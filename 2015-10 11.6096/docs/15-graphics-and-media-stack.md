# Graphics and Media Stack

What `acclient.exe` actually renders and plays with, derived from the binaries.
**Identical in 11.4186 and 11.6096** — the import tables are content-identical (18
DLLs, 372 functions) and the rendering core has zero changed functions between
the builds.

---

## 0. Summary

| Purpose | Library | Linkage |
|---|---|---|
| **3D rendering** | **Direct3D 9** | **dynamic** — `LoadLibrary("d3d9.dll")` |
| 3D math, mesh helpers | **D3DX9** | **static** (`d3dx9.lib`) — no `d3dx9_XX.dll` dependency |
| Audio output | **DirectSound** | static import, `DSOUND.dll` |
| MIDI, RIFF/WAV parsing, timers | **WINMM** | static import, 25 functions |
| Compressed audio decode | **MSACM32** (ACM) | static import, 6 functions |
| Video playback | **DirectShow** | COM, via `ole32` |
| 2D surfaces, font rasterisation | **GDI32** | static import, 12 functions |
| JPEG decode | **Intel JPEG Library 1.5** | **static** (`ijl15l.lib`, v1.51.12) |
| Deflate | **zlib** | `zlib1.dll` |
| C/C++ runtime | **MSVCR70 / MSVCP70** (Visual C++ 7.0) | static import |

The rendering path uses the **fixed-function pipeline**. There are no shaders
anywhere in the client.

---

## 1. Direct3D 9

### It is loaded at runtime, not imported

`d3d9.dll` does not appear in the import table. `D3DPolyRender::Startup`
(`0x0059E9F0`) loads it explicitly:

```asm
59e9f8: call 54e9b0                  ; Render::Startup
59ea01: push 0x7e5588                ; "d3d9.dll"
59ea06: call DWORD PTR ds:0x7921d4   ; LoadLibraryA
59ea0e: mov  [esi+0x18],eax          ; cache the module handle
59ea11: je   59ea2e                  ; failed -> error path
59ea13: push 0x7e5578                ; "Direct3DCreate9"
59ea18: push eax
59ea19: call DWORD PTR ds:0x836388   ; GetProcAddress
59ea21: je   59ea2e
59ea23: push 0x20                    ; D3D_SDK_VERSION = 32
59ea25: call eax                     ; Direct3DCreate9(32)
59ea29: mov  [esi+0x1c],eax          ; cache IDirect3D9*
59ea2c: jne  59ea67
59ea57: push 0x69                    ; else: DisplayString(0x69) -- fatal error
...
59ea70: call 59bfc0                  ; D3DPolyRender::SelectBestAdapter
59ea7b: call 59de90                  ; D3DPolyRender::DetectDisplayModes
```

`push 0x20` is `D3D_SDK_VERSION` (32), confirming the Direct3D 9 SDK. The debug
runtime `d3d9d.dll` is referenced separately at `0x007EC3F4`.

Loading dynamically is why the client can start on a machine without D3D9 and
report a clean error rather than failing at load time.

### No other 3D API is present

Zero occurrences in either build, checked as raw byte counts:

`d3d8`, `D3D8`, `Direct3DCreate8`, `ddraw`, `DirectDrawCreate`, `opengl32`,
`OpenGL` — **all zero**. There is no fallback renderer and no software
rasteriser path.

### Fixed-function pipeline, no shaders

| Token | Occurrences (both builds) |
|---|---|
| `CreateVertexShader` | 0 |
| `CreatePixelShader` | 0 |
| `D3DXCompileShader` | 0 |
| `HLSL` | 0 |

A full enumeration of the D3D9 COM surface — built by locating the device
pointer at `RenderDeviceD3D+0x468` and resolving the method behind all 231 loads
of that field — found no shader creation, no vertex-declaration creation and no
state blocks on any path. The presence of `RenderDeviceD3D::SetFFFogProperties`
("FF" = fixed function) is the corroborating name.

Rendering is therefore fixed-function transform and lighting with multitexturing.
The `vs_1_1`, `vs_2_0` and `ps_2_0` strings each occur exactly once — those live
in the statically linked D3DX shader-profile tables and are not referenced by
client code.

### D3DX is statically linked

There is no `d3dx9_XX.dll` dependency to satisfy, because D3DX is linked in. The
evidence is that its AMD-optimised math routines are **local functions** with
their own addresses:

```
00607000  AMDSSE_D3DXPlaneTransformArray
00608000  AMDSSE_D3DXVec4TransformArray
00609000  AMDSSE_D3DXVec2TransformArray
0060A0A0  AMDSSE_D3DXVec3TransformCoordArray
00611000  AMDX3D_D3DXFloat16To32Array
00611140  AMDX3D_D3DXFloat32To16Array
```

plus `_D3DXATTRIBUTERANGE` appearing as a local type in
`SmartArray<_D3DXATTRIBUTERANGE,0>`. `D3DXCreateMeshFVF` is reached by a direct
local call from `D3DPolyRender::ConstructMesh` and has no import-name string,
which is why searching for `D3DXCreateMesh` as text returns nothing.

---

## 2. Audio

**DirectSound** is the output backend. `DSOUND.dll` contributes exactly **one**
import, and it is **by ordinal `#1`** — that is `DirectSoundCreate`. Everything
else is done through the returned interfaces.

**WINMM** (25 imports) covers three separate jobs:

- MIDI streaming — `midiStreamOpen`, `midiStreamOut`, `midiStreamProperty`,
  `midiOutShortMsg`, `midiOutPrepareHeader`, `midiStreamRestart/Stop/Close`
- RIFF/WAV container parsing — `mmioOpenA`, `mmioDescend`, `mmioAscend`,
  `mmioRead`, `mmioSeek`, `mmioAdvance`, `mmioGetInfo`, `mmioSetInfo`
- Timing — `timeGetTime`, `timeSetEvent`, `timeKillEvent`, `timeBeginPeriod`,
  `timeEndPeriod`

**MSACM32** (6 imports) is the Audio Compression Manager, used to decode
compressed audio: `acmStreamOpen`, `acmStreamConvert`, `acmStreamSize`,
`acmStreamPrepareHeader`, `acmStreamUnprepareHeader`, `acmStreamClose`.

---

## 3. Video

Movie playback goes through **DirectShow**, constructed as COM objects via
`ole32`, from `MovieTheatre::Init` (`0x006BC660`) which builds an `IGraphBuilder`
and calls `Render` on it. There is no bundled codec — playback depends on
whatever DirectShow filters are installed on the machine.

---

## 3b. Input — DirectInput, statically linked

Easy to miss, because `DINPUT8.DLL` does **not** appear in the import table. It
is loaded dynamically instead: the string appears twice — ANSI `DINPUT8.DLL` at
`0x007FEF94` and UTF-16 at `0x007FEF7C` (2013), right after `DirectInput8Create`
at `0x007FEF68` — and only the lowercase spelling `dinput8.dll` is absent. But
DirectInput is used, and the proof is both a data structure and a dynamic load:

`c_dfDIMouse2` — the standard DirectInput mouse data format — sits at
`0x0080691C` in `.rdata`, and its fields check out exactly against the
documented `DIDATAFORMAT` layout:

| Field | Value | Expected |
|---|---|---|
| `dwSize` | 24 | `sizeof(DIDATAFORMAT)` |
| `dwObjSize` | 16 | `sizeof(DIOBJECTDATAFORMAT)` |
| `dwFlags` | `0x2` | `DIDF_RELAXIS` |
| `dwDataSize` | 20 | `sizeof(DIMOUSESTATE2)` |
| `dwNumObjs` | 11 | 3 axes + 8 buttons |
| `rgodf` | `0x006B8020` | object-format array |

It is referenced from **`CInputManager_WIN32::AddDevice`** (`0x006873A7`), so it
is live, not dead library data. The string `DirectInput8Create` occurs exactly
once. The API entry point is reached by the same dynamic-load pattern as d3d9:
`CInputManager_WIN32::OnStartup` (`0x00687D70`) does `push 0x7fef94; call
[LoadLibraryA]` to load `DINPUT8.DLL`, then `push 0x7fef68; call [GetProcAddress]`
to resolve `DirectInput8Create`. DirectInput is therefore used via dynamic load,
not a static import.

## 4. 2D and images

**GDI32** (12 imports) handles offscreen 2D work and font rasterisation:
`CreateDIBSection`, `CreateCompatibleDC`, `CreateCompatibleBitmap`,
`CreateBitmap`, `SelectObject`, `BitBlt`, `PatBlt`, `GetDeviceCaps`,
`CreateICA`, `GetStockObject`, `DeleteDC`, `DeleteObject`.

**JPEG decoding uses the Intel JPEG Library**, statically linked. Version
evidence in the binary:

```
0x00907180  "ijl15l.lib"  "1.51.12"
0x00906680  "Software\Intel Corporation\PLSuite\IJLib"   ... "USECPU"
```

So IJL 1.5, with a registry key that lets the library's CPU dispatch be
overridden.

**zlib** is the only compression dependency shipped as a DLL — `zlib1.dll`,
importing just `uncompress` and `compress2`.

---

## 5. Runtime and other DLLs

The CRT is **MSVCR70.dll** (112 imports) and **MSVCP70.dll** — the Visual C++
7.0 / Visual Studio .NET 2002 runtime, still in use in a 2015 build.
`MSVCI70.dll` is referenced by name as well.

Other DLL names referenced as strings, i.e. candidates for dynamic load rather
than static imports: `unicows.dll` (the Microsoft Layer for Unicode, for Win9x),
`keystone.dll`, `chatclient.dll`, `corestrings.dll`, `acpl.dll`,
`plugins\ACPluginManager.dll`, `plugins\ACHelpPlugin.dll`, `Trowser.dll`
(`0x0079C50C`), `msxml4.dll` (`0x007CB7C0`), `WININET.dll`, `msvfw32.dll`,
`avicap32.dll`, `sensapi.dll`,
`rasapi32.dll`, `secur32.dll`.

Full static import list, in descending order of size:

```
MSVCR70.dll 112   KERNEL32.dll 103   USER32.dll  55   WINMM.dll  25
WSOCK32.dll  18   RPCRT4.dll   12    GDI32.dll   12   ole32.dll   7
ADVAPI32.dll  6   MSACM32.dll   6    IMM32.dll    3   OLEAUT32.dll 3
VERSION.dll   3   SHELL32.dll   2    zlib1.dll    2   COMCTL32.dll 1
MSVCP70.dll   1   DSOUND.dll    1
```

---

## 6. Address reference

| Symbol / string | 11.4186 | 11.6096 |
|---|---|---|
| `D3DPolyRender::Startup` | `0x0059E9F0` | `0x0059FB00` |
| `Render::StartupRenderingSystem` | `0x0054C4B0` | `0x0054D0C0` |
| `D3DPolyRender::SelectBestAdapter` | `0x0059BFC0` | — |
| `D3DPolyRender::DetectDisplayModes` | `0x0059DE90` | — |
| `D3DPolyRender::ConstructMesh` | `0x0059DFA0` | `0x0059F0B0` |
| `RenderDeviceD3D::DetectDisplayFormats` | `0x005A1BE0` | `0x005A2CF0` |
| `SoundManager::Init` | `0x00550640` | `0x00551250` |
| `MovieTheatre::Init` | `0x006BC660` | `0x006BD530` |
| `"d3d9.dll"` | `0x007E5588` | `0x007E6670` |
| `"Direct3DCreate9"` | `0x007E5578` | `0x007E6660` |
| `"d3d9d.dll"` | `0x007EC3F4` | `0x007ED4CC` |
| `"ijl15l.lib"` | `0x00907180` | `0x00908180` |
| D3D device pointer | `RenderDeviceD3D+0x468` | same |

---

## 7. Provenance and caveats

The import tables were parsed directly from the PE import directory in both
files, not read from a decompilation. Negative results (`d3d8`, `opengl32`,
`CreateVertexShader`, …) are raw byte-count searches over the entire image in
both builds, so they are strong: those tokens do not exist anywhere, in code or
data.

**One methodological caveat.** The 11.6096 addresses above were resolved by
matching relocation-normalised function bodies. That method uses a heuristic
byte scan to mask `call`/`jmp` displacements, which occasionally fails to match
a function that is in fact identical. `RenderDeviceD3D::Clear` and
`RenderDeviceD3D::SetFFFogProperties` did not resolve by this route, but both
were confirmed **unchanged** by the more rigorous disassembly-based comparison
in `13-client-differences-2013-vs-2015.md` — their 11.6096 addresses are simply
not listed here rather than being unknown-because-changed. See §1 of that
document for why the byte-scan method is unreliable in this direction.
