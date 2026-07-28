# Client Core, Application Lifecycle, and Shared Infrastructure

Target: acclient.exe 11.4186 (September 2013). Line references are into
`../acclient.c` and `../acclient.h` unless noted.

> **Revision note.** Written in a first pass, then verified in a second pass that
> also parsed `../acclient.pdb` directly. Three first-pass claims were
> substantively wrong and all point the same way: **this build installs no crash
> handling of any kind** (§9). The main-loop story also changed — there are *two*
> undecompilable frame pumps, not one (§2).

---

## 1. Startup sequence

`WinMainCRTStartup` (acclient.c:521074) calls `WinMain` (acclient.c:61064),
which does:

1. `Turbine::Debug::Init("ac", …, 0xE08)` — called at acclient.c:61077 (65089 is
   the definition). See §9 for what this does *not* do.
2. `ConvertCommandLineToArgList` into a `SmartBuffer` / `SmartArray<char*>`.
3. `ClientMain::ConfigureFPU` (acclient.c:60885–60891) —
   `Turbine::Debug::SetFloatingPointException(0, 0x80017)` followed by three
   `__control87` calls.
4. `ProgramTypeSystem::s_eProgramType = 0x40000001` (acclient.c:61093).
5. `IError::AddDataErrorHandlers(0, null_string)` (acclient.c:61094) — missed by
   the first pass; it runs here, after `ConfigureFPU` and `s_eProgramType`, not
   immediately after `Debug::Init`.
6. `APIManager::Init`.
7. `AC1Legacy::Version::Init` (acclient.c:388055) — builds version strings from
   the EXE's `VS_VERSIONINFO`. Display only; no integrity check.
8. `ACCFactory::Init` (acclient.c:390841).
9. `ConstructClassObjectEx<Client, Interface>(&Client_ClassType)`
   (acclient.c:60894) creates the singleton `gmClient`.

Then virtual `ParseCommandLine`, `Init("Asheron's Call", lang=1, region=1)`,
`Run`, and `ClientMain::ClientCleanUp` (acclient.c:60873).

### Command-line switches

`Client::BuildCommandLineArgs` (acclient.c:78160) registers exactly nine:
`account` (-a), `debug`, `host` (-h), `language`, `outport` (-q), `port` (-p),
`prefs`, `rodat`, `usemem`.

**`-logfile` is not registered.** It is only string-compared in
`Client::EvaluateCommandLineArg` (acclient.c:78361), and that branch body is
empty.

`gmClient::BuildCommandLineArgs` (acclient.c:62232) adds: `user` (-u),
`create` (-r), `zoneticket` (-z), `glsticketdirect`, `glsticket`,
`migrationurl`, `vgpassword` (-v).

`-glsticket` reads
`HKCU\Software\Turbine\ac1\GLSTicket` (acclient.c:62382–62390) and then reopens
the key to `RegEdit::DeleteValue` it (acclient.c:62401).

**`-debug <n>` is a replace, not an OR.** `EvaluateCommandLineArg` does
`SetDebugFlags(n, 1); SetDebugFlags(~n, 0);` (acclient.c:78355–78356), so
`DebugFlags` becomes exactly `n`. Recovered bit meanings, with two corrections to earlier drafts:
**`0x200`** installs the unhandled-exception filter and the emergency pool;
**`0x400`** adjusts the FPU exception mask (65047) — and is *also* cleared by
`~0xE08`, so that path is dead too; **`0x800`** does **not** suppress
`Logger::Initialize`, which always runs (65102) — the bit only selects its bool
argument, `Logger::Initialize((v3 & 0x800) != 2048)`, which given the clear is
**true**; `0x2000` is the self-clearing "Init not yet done" gate (65098–65101);
`0x4000` is the `ReportException` re-entrancy guard, saved/cleared/restored at
64847/64848/64853/64855 (the separate clear at 64851 masks bits `0x8` and `0x40`,
not `0x4000`). **`0x100`'s meaning is unknown** — `InitDebug` clears it (65060),
`Client::Client` sets it (78717), and nothing reads it. Because
parsing happens *after* `Turbine::Debug::Init`, **`-debug 0x200` cannot
retroactively install the crash handler.**

### Init order

`gmClient::Init` (acclient.c:63384) forces a minimum resolution of 800×600, then
`Client::Init` (acclient.c:78000):

- `_set_new_handler(portal_new_handler)` — pops "OUT OF MEMORY" and calls
  `DebugBreak` (acclient.c:77270)
- single-instance check: `CreateSemaphoreA(0, 0, 1, "Empyrean Client")`
  (acclient.c:78079), duplicate detected via `GetLastError() == 183`
- Win9x check loading `unicows.dll`
- `Timer::Init`, `Random::Seed`
- factory-made `GlobalEventHandler` and `QualityRegistrar`
- `Client::InitPreferences` (acclient.c:78100) — see §7
- `Client::InitNet` (acclient.c:77815) — `ClientNet`, `PacketController`, and the
  12-slot NetBlob queue array
- `Client::InitDatabase` (acclient.c:78750) — DAT mounting via `CLCache`
- `CLanguageInfoInterface::Startup`
- `Client::InitUI` (acclient.c:77531) — `CoInitialize`, `KeyStone::Init`,
  `Device::Init(…, 800, 600, …)` (acclient.c:120403, `CreateWindowExA` at
  120562), `SoundManager::Init` (77544), `SmartBox::Init`, `UIElementManager`,
  and `ConstructClassObjectEx<UIFlow, …>`

---

## 2. The main loop, and what can actually be known about it

`Client::Run` (acclient.c:77592–77604) calls the virtual `Connect`, then spins
`while (UseTime());` gated on `NetError::None`.

**Two functions in this binary defeat Hex-Rays, and they are the two frame
pumps.** The file's own summary line (acclient.c:938010) reads "2 decompilation
failure(s) on 36603 function(s)":

| Function | VA | Size | Failure |
|---|---|---|---|
| `Client::UseTime` | 0x411C40 | 126 bytes | `#error "411CAD: call analysis failed (funcsize=34)"` at acclient.c:77890 |
| `Client::KeepUIAlive` | 0x4112D0 | 107 bytes | acclient.c:77316 |

The first pass mentioned only the first. `Client::KeepUIAlive` is a cut-down pump
run from `Client::Connect`'s login spin —
`while (v2->m_eLinkState < 3) Client::KeepUIAlive(v2);` (acclient.c:78899).

Both fail at nearly the same relative offset (0x5D and 0x6D), consistent with a
shared indirect-call idiom. The alternate decompilation fails at the *identical*
address (`acclient 6.95.16808.c:79056`), so it offers nothing extra.

### RESOLVED — recovered from the 2015 client

**The loop is no longer inference.** The sibling folder
`../../2015-10 11.6096/` contains a decompilation of client 11.6096 produced by
an *older* Hex-Rays (6.6, build 14.605 — the filename is the decompiler version,
not the client version). Hex-Rays 6.6 handled the indirect call that 6.95 and the
2014-era build both choked on, and emitted complete bodies for **both** functions.

`Client::UseTime` (2015 file, line 77146; VA 0x411FA0):

```c
Timer::update_time();
if ( Device::DoEventLoop() ) return 0;          // quit requested
ClientNet::UseTime(client->m_pClientNet);       // socket recv, ack, flow control
Client::ProcessLogonEventQueue(client);         // logon queue 4 + Turbine Chat
PacketController::UseTime(client->m_pPacketCtl);// fragment reassembly
(*(CLCache vtable slot 18))();                  // -> CLCache::UseTime  (see below)
UIElementManager::UseTime(s_pInstance, …);      // UI tick + dirty-rect paint
SmartBox::UseTime(client->m_pSmartBox, …);      // the whole world tick
SceneTool::PrepareGraphicsDevice();
SceneTool::StartFrame();
SmartBox::Draw(client->m_pSmartBox, …);         // 3D scene
SceneTool::EndFrame(…);                         // UI overlay, EndScene, Flip
Device::DoFrameSleep();
return 1;
```

`Client::KeepUIAlive` (2015 file, line 76532; VA 0x411630) is the same loop with
networking reduced and no frame-quit path:

```c
Timer::update_time();
if ( Device::DoEventLoop() ) {                  // quit during handshake
    if (net->state != INVALID_ASYNCCONTEXT)
        ClientNet::EndState(net, &ID_NetError_AbortedHandshake);
} else {
    ClientNet::UseTime(net);
    (*(CLCache vtable slot 18))();
    UIElementManager::UseTime(s_pInstance, …);
    SmartBox::UseTime(…);
    SceneTool::PrepareGraphicsDevice();
    SceneTool::StartFrame();
    SmartBox::Draw(…);
    SceneTool::EndFrame(…);
    Device::DoFrameSleep();
}
```

Note it omits `ProcessLogonEventQueue` and `PacketController::UseTime` — during
the login spin the logon queue is drained by `Client::Connect` itself — but it
**does** run the full world tick and render. That is why the 3D scene keeps
animating behind the connecting screen.

### The indirect call

`(*(void (**)(void))(*(_DWORD *)(*((_DWORD *)v4 + 43) + 4) + 72))()` resolves as
follows. `Client + 43 dwords` (offset 172) is the **CLCache** — proved in both
builds by `Client::InitDatabase` calling
`CLCache::SetNetQueue(v4->m_pDBCache, …)` (acclient.c:78802), with
`Client::m_pDBCache` typed `CLCache*` (acclient.h:35581); the name-stripped 2015
decompilation writes the offset literally as `*(_DWORD *)(v4 + 172)`.

The expression loads a secondary vtable at `CLCache + 4` and calls slot
72/4 = **18**.

**That secondary vtable is the `AsyncCache` sub-object, not `PortalThread`** — an
earlier draft got this wrong. `DBCache : Interface, AsyncCache`
(acclient.h:28888), and `Interface` is a single vptr (acclient.h:8009), so
`AsyncCache`'s vptr lands at +4. (`PortalThreadVtbl` has only four slots, so slot
18 could not exist there.)

Slot 18 is `UseTime`, and the arithmetic is exact. Walking `AsyncCacheVtbl`
(acclient.h:28344) byte by byte: `BlockingGet` 0; `gap4[16]` 4–19; `AsyncGet` 20;
`AsyncGetImmediate` 24; `___u3` is `__declspec(align(8))` so it pads to 32;
`AsyncSave` 36; `gap28[8]` 40–47; `___u5` 48; `ReleaseContext` 52; `GetDBOCache`
56; `IsOnDisk` 60; `AreOnDisk` 64; and **`UseTime` is also `align(8)`, padding
from 68 to 72**. IDA's two `align(8)` declspecs are precisely the holes that make
offset 72 land on `UseTime`.

The target is `CLCache::UseTime` — `sub_4FCBE0` in the 2015 file (marker at line
294866), statement-for-statement identical to the 2013 `CLCache::UseTime`
(acclient.c:295961, VA 0x4FC040). Both call `ThreadedCache::UseTime` and then
drain the list at offset 764 — the field `CLCache::SetNetQueue` writes
(acclient.c:290558) — through a `TransientArchive`.

So the per-frame chain is **`Client::UseTime` → `CLCache::UseTime` →
`ThreadedCache::UseTime` → `DBCache::UseTime`**, which is where the 25 ms
reply-queue drain documented in `07-dat-resources.md` §7 gets its tick
(`while (GetTickCount() - v2 < 0x19)` in `ThreadedCache::UseTime`,
acclient.c:654301).

### Why this transfers to 11.4186

The recovered bodies are from **11.6096**. Four independent lines of evidence,
well beyond the slot-size argument an earlier draft relied on:

**1. A rigid +0x360 rebase across the whole `Client.obj` block.** Testing every
PDB function in 0x411200–0x413000 for whether `VA + 0x360` is a function marker
in the 2015 file gives 45 hits and 5 misses. The misses are one contiguous run
where the 2015 IDB merged functions; the sequence **re-synchronises exactly** at
`Client::InitDatabase` (0x412D10 → 0x413070) and `Client::Connect`
(0x412E20 → 0x413180), so accumulated drift is zero. Both pumps sit mid-block,
and their five nearest neighbours decompile token-for-token identically.

**2. A two-sided orphan-closure test.** Enumerating all PDB functions with no
visible caller in the 2013 file and asking which gain references in 2015: exactly
11 land inside the recovered bodies, and they are precisely the pumps' callees
(`SceneTool::StartFrame`, `PrepareGraphicsDevice`, `EndFrame`,
`Device::DoEventLoop`, `DoFrameSleep`, `SmartBox::UseTime`,
`UIElementManager::UseTime`, `ClientNet::UseTime`,
`Client::ProcessLogonEventQueue`, `PacketController::UseTime`,
`Client::KeepUIAlive`). Every function 11.4186 orphaned is explained, and every
callee that could have been orphaned was. The set closes from both directions.

**3. A genuinely independent third decompilation.**
`../../2015-10 11.6096/acclient.c` is a separate, **name-stripped** IDB — every
symbol is `sub_XXXXXX`, with a different failure set at a different address. It
decompiles both pumps cleanly and emits the **identical sequence with identical
target addresses**. This rules out the Diffed file's BinDiff-ported names having
fabricated anything.

**4. Both 2013 decompilers fail identically** — Hex-Rays ~2014 and 6.95 emit the
same two errors at the same two addresses with the same `funcsize` values (27 and
34). The failing call sits 17 bytes from the end of `UseTime`, matching the
`call EndFrame; call DoFrameSleep; ret` tail — corroborated by `EndFrame` being
the one callee whose prototype is garbage in 2013 and clean in 2015.

| | 11.4186 | 11.6096 |
|---|---|---|
| `Client::UseTime` VA → next | 0x411C40 → 0x411CC0 | 0x411FA0 → 0x412020 |
| slot / true length | 0x80 / **126 B** | 0x80 |
| `Client::KeepUIAlive` VA → next | 0x4112D0 → 0x411340 | 0x411630 → 0x4116A0 |
| slot / true length | 0x70 / **107 B** | 0x70 |

**Verdict: proven for 11.6096, and directly verifiable for 11.4186.**
`acclient.exe` is in fact present in both folders (the 2013 one matches the
documented MD5), so the pump bodies verify directly against the binary rather
than resting on static inference alone — and any residual risk is confined to
whether an argument expression or branch predicate differs by a few bytes, not to
which functions are called or in what order.

### Corrections to earlier inferences

The first-pass claim that `SceneTool::BeginScene` and `DBCache::PreFetchStatic`
are called from these functions is **false** — neither appears in either body.
The "no xrefs implies called from the failed functions" argument was unsound.

**`SceneTool::StartFrame` is a 5-byte tail-call thunk.** The PDB gives it a
length of 5 bytes at VA 0x43E500 — exactly one `jmp rel32`. That is why no
decompiler ever emits a body: IDA absorbs those 5 bytes into the preceding
function's extent in all four IDBs. Its callers are exactly the two pumps and
nothing else, confirmed in the stripped 2015 file.

**`SceneTool::BeginScene` is almost certainly what `StartFrame` jumps to.** It
has zero call sites in all four decompilations, and after the pumps are accounted
for it is the *only* `SceneTool` function left with no caller anywhere — whereas
`PrepareGraphicsDevice` and `EndFrame` were orphaned in 2013 for exactly the pump
reason and gained callers in 2015. Its body is unmistakably a frame-start
(`if (!m_bOpenScene) { ++sceneTimestamp; Clear(7, …); BeginScene(); }`), and
`StartFrame` is called at precisely the point a scene must open. Not formally
provable without the binary, but no competing candidate exists.

**`DBCache::PreFetchStatic` is unreferenced code.** Zero call sites in all four
decompilations; the name appears nowhere in `acclient.h`, so it is not in any
vtable or function-pointer struct, and being `__cdecl` it is a free static. Its
sibling forwarders `GetFromEnumStatic` and `GetDIDFromEnumStatic` have eight call
sites each, so the pattern is normally used. Most likely retained because the
linker keeps the whole `DBCache.obj` COMDAT set.

**`UIFlow::Update` is dispatched through the COM-like component vtable and its
caller cannot be identified from these artifacts.** It has zero call sites in all
four decompilations. There is no `UIFlowVtbl` in the header — `UIFlow` derives
from `Interface` (acclient.h:34333), whose vtable has only the six COM-ish slots
— and `Client::m_ui` is only ever stored and cleared, never dereferenced for a
tick. Every other `UIFlow` method shows the same two-occurrence pattern, so the
whole class is reached through the `Turbine_GUID`-keyed registry. Resolving the
caller would need the binary's `.rdata`.

One refinement on the `__usercall` argument: it holds for `SceneTool::EndFrame`,
whose 2013 prototype is a garbage nine-argument form versus the clean 2015
`(char a1@<bl>)`. But `UIElementManager::UseTime` has the **identical** prototype
in both builds, so its register arguments reflect a genuine calling convention,
not a recovery artifact.

### What is observable

`Device::DoFrameSleep` (acclient.c:118017–118030) always calls `Sleep(0)` as an
unconditional yield, and applies a ~99 ms budget via `timeGetTime()` when
`Device::m_bIsActiveApp` is false — roughly 10 fps when inactive. There is no
frame cap when active.

The world tick is `SmartBox::UseTime` (acclient.c:146256), invoked from gameplay
mode: cell prefetch and `CellManager::ChangePosition` → `CObjectMaint::UseTime`
→ `CPhysics::UseTime` → `GameTime::UseTime` and `LScape::UseTime` →
`Ambient::UseTime` → `SceneTool::Think` → queued NetBlob dispatch →
`CommandInterpreter` tick → `Render::CalcDegLevel`.

**A note on `MIN_QUANTUM`.** The physics and core reports cited different lines
for the same constant; both are correct and both are inert. There are **100
identical `MIN_QUANTUM* = 1.0/30.0` static initializers**, one per translation
unit. acclient.c:731343 initializes copy #0 and acclient.c:784229 initializes
`MIN_QUANTUM_97`. The **live** constant for physics is `MIN_QUANTUM_93`,
initialized at acclient.c:783717 and tested in `CPhysics::UseTime` at
acclient.c:311352. `MIN_QUANTUM_97` is used by the animation paths
(acclient.c:321170, 321678, 323138).

---

## 3. The COM-like component system

A deliberate COM lookalike with a real-COM shim.

`Turbine_GUID` (acclient.h:8072–8079) is layout-identical to `_GUID`. The root
`Interface` vtable (acclient.h:8056–8064) has **six** slots: three genuine
`__stdcall` IUnknown slots followed by three `__thiscall` Turbine-convention
slots.

`InterfaceSystem` is the class registry: an
`IntrusiveHashTable<Turbine_GUID, Interface*>` (acclient.c:65372) mapping class
GUIDs to factory objects registered via `InterfaceSystem::RegisterClassA`
(acclient.c:65687). `CreateInstance` (acclient.c:65333) looks up the class
object, QueryInterfaces it for `IObjectFactory`, and calls that factory — e.g.
`ClassFactoryForceClient_ClassType::CreateInstance` (acclient.c:62778) returns
real COM HRESULTs (`0x80040110` CLASS_E_NOAGGREGATION, `0x80004003` E_POINTER).

So: not registry-based COM, no `CoCreateInstance` for game classes, no marshaling
— but binary-compatible IUnknown heads, which is precisely what makes the plugin
API possible.

`TResult` is an HRESULT-alike (sign bit means failure). Ref counting is via
`ReferenceCountTemplate<N, M>` (acclient.h:8168).

---

## 4. Client state machine

A UI-mode state machine owned by `UIFlow` / `gmUIFlow`. `gmUIFlow::gmUIFlow`
(acclient.c:183742) registers mode-ID to framework-factory pairs at
acclient.c:183760–183767:

| Mode ID | Framework |
|---|---|
| `0x10000001` | `gmIntroUI` |
| `0x10000002` | `gmDisconnectedUI` |
| `0x10000003` | `gmDataPatchUI` — **initial mode** |
| `0x10000005` | `gmCreditsUI` |
| `0x10000008` | `gmGamePlayUI` |
| `0x10000009` | `gmEpilogueUI` |
| `0x1000000A` | `gmCharacterManagementUI` |
| `0x1000000B` | `gmCharGenMainUI` |

**Only eight are registered.** `0x10000004`, `0x10000006`, and `0x10000007` are
not UI modes at all — the first pass implied they were gaps. Those values belong
to unrelated reuses of the `0x1000000x` well-known-ID space: input-map IDs
(`ID_InputMap_MissileCombat`, `ID_InputMap_Emotes`,
`ID_InputMap_ItemSelectionCommands` — acclient.c:265355–265362), DAT enum IDs
(213131, 435396), element-class IDs (240519), and string-table IDs (63055).

Transitions are `UIFramework::QueueUIMode` calls consumed on the next
`UIFlow::Update`. `CharGenState` (acclient.h:40074) is the char-gen model,
submitted via `Proto_UI::SendCharGenResult` (acclient.c:278661) with the server
verdict returned through `RecvNotice_CharGenVerificationResponse`
(acclient.c:278557).

---

## 5. Slash commands

Two distinct things are called a "CommandInterpreter." The class literally named
`CommandInterpreter` (acclient.c:717732) is the **movement and keyboard**
interpreter — autorun, hold-run, turn-to-heading, autonomy level.

Chat and slash commands live in `ClientCommunicationSystem::OnChatCommand`
(acclient.c:426126) → `DoCommand`, dispatching through a case-insensitive
`IntrusiveHashTable<PString, CmdHashData*>` built in `InitializeCommands`
(acclient.c:426432–430247). **116 command tokens** are registered — counted
mechanically as 116 `operator new(0x18u)` registration sites with 116 distinct
`PStringBase` literals.

The retail set, with aliases:

`?` / `help` / `commands` / `clist`, `afk`, `age`, `allegiance` / `allegiances` /
`a` / `ab` / `alh` / `ah`, `birth`, `chat` / `c` / `chatting`, `channels`,
`clear`, `consent`, `corpse` / `cor`, `covassal(s)`, `day`, `death` / `die`,
`emote` / `emotes` / `e` / `em` / `me`, `endurance`, `framerate`,
`fellow(ship)` / `f`, `fillcomps`, `filter` / `unfilter`,
`friends(_add/_remove)`, `house` / `hoa` / `hom` / `hor` / `hou` / `hslist` /
`hr`, `index`, `join` / `leave`, `lifestone` / `lif` / `ls`, `loadfile` /
`loadui` / `loadautoui` / `saveui` / `saveautoui` / `lockui`, `loc`, `log`,
`marketplace` / `mar` / `mp`, `messagetypes` / `message_types` / `msgtypes` /
`msg_types`, `monarch` / `m`, `motd`, `mr`, `notell` / `retell` / `reply` / `r` /
`rt`, `off` / `on`, `party` / `p` / `group` / `g`, `patron`, `permit`, `pklite` /
`pkl` / `pkarena` / `pka` / `pklarena` / `pla`, `pr`, `render`, `rp`, `say` / `s`,
`send`, `speaker`, `squelch` / `unsquelch`, `status`, `tell` / `t` / `whisper` /
`w`, `text`, `title`, `vassal(s)` / `v`, `version`.

**`bug` does not exist** — the first pass listed it, but there is no `"bug"`
literal anywhere in the file. The prose list above enumerates 113 tokens; the
three it still omits are **`all`**, **`co-vassals`**, and **`fellows`**.

Nothing GM-only ships. The developer leftovers are `loc`, `render`, `framerate`,
plus the retail `DebugConsole` and `ProfilerUI`.

A separate `GlobalRegistry::RegisterCommand` console-command registry exists
alongside the slash commands, exposing `LoadPreferences` / `SavePreferences`
(acclient.c:117882–117897).

---

## 6. APIManager — the plugin surface

`APIManager::Init` (acclient.c:393464) reads the registry value **`ACPlugin`**
under **HKLM** `SOFTWARE\Microsoft\Microsoft Games\Asheron's Call\1.00`
(`g_strClientRegKeyBasePath` at acclient.c:821086; read at
`ClientRegKey::GetClientOptions`, acclient.c:713261), then `LoadLibraryA` and
`GetProcAddress(..., "CreateACPlugin")` (acclient.c:393498, 393509), passing an
`IAsheronsCall` COM object and receiving an `IACPlugin`. This is the sanctioned
Decal injection point.

**The real interface has 52 methods**, not the ~25 the first pass listed or the
56 a later draft claimed. The vtable at 0x7CC0F8 runs to the next `.rdata`
symbol at 0x7CC1C8 — 0xD0 bytes = 52 slots — and the PDB yields exactly 52
method publics (3 IUnknown + 49). Beyond
those already documented, it includes `WriteToChat`, `GetCombatMode`,
`GetIsOutdoors`, `GetChatState`, `GetSelectedStackCount` / `SetSelectedStackCount`,
`GetBusyCount` / `IncrementBusyCount` / `DecrementBusyCount`, the
`TradeWindow_*` family (`IsOpen`, `GetPartnerID`, `AddItem`, `Accept`, `Close`),
and the whole `SalvagePanel_*` family. Also note the getter is
`GetSelectedItemID` (0x559C00), not `GetSelectedObjectID`, and there are
`SetPreviousSelectedItemID` / `GetPreviousSelectedItemID`.

**16 of those 52 are `return E_FAIL` stubs**, COMDAT-folded to 0x559E40 (nine
methods) and 0x559E50 (seven), both returning `0x80004005`; the split is just
`ret 8` versus `ret 4`. They are: `GetBusyCount`, `IncrementBusyCount`,
`DecrementBusyCount`, `SetSelectedStackCount`, `GetChatState`, five of the six
`TradeWindow_*`, and all six `SalvagePanel_*`.

`TradeWindow_Clear` (0x55A0C0, acclient.c:393313) is **real** — it calls
`CM_Trade::Event_ResetTrade()`.

Worse than the stubs: `GetCombatMode` and `GetVendorID` are COMDAT-folded into
one body at 0x55A050 that returns `S_OK` **without writing the out-parameter**,
and `GetSelectedStackCount` (0x6B3DC0) is a 5-byte `return 0` folded with 16
unrelated functions. Callers cannot detect these —
`IAsheronsCallImpl::CastSpell` (0x559DC0, acclient.c:393120–393124) depends on
`GetCombatMode` writing a value and therefore always takes its failure path.

---

## 7. Preferences are an INI file, not the registry

`UserPreferences::FindDefaultFile` (0x437CE0) builds **`UserPreferences.ini`**
next to the executable (`PSUtils::get_process_name` → `get_directory` →
`sprintf("%s%s")`, acclient.c:117095–117120). Persistence is the plain Win32
profile API — `WritePrivateProfileStringA` in `UserPreferences::Save`
(acclient.c:117423), section `"Default"`. `-prefs` overrides the path via
`Client::m_preferencesFile` (acclient.c:78114).

Preferences **are** saved on exit: `Client::CleanupPreferences` calls
`UserPreferences::Save()` then `Cleanup()` (acclient.c:77286–77287).

Registration is two-tier. `UserPreferences::RegisterPreference` (44 sites) binds a
C++ storage address to a name. `UIPreferences::AttachPreference(name, dataType,
stringTableID, displayToken, tooltipToken)` (36 sites) additionally exposes it in
the options UI, with `SetPreferenceRange` for floats (dataType 3 = float,
4 = bool).

Recovered groups: `Net_*` (BindInterface, ComputeUniquePort, UserSpecifiedPort);
`Render_*` (16 keys — see `06-rendering.md` §11); `Sound_*` (8 keys — see
`09-audio.md` §8); `Input_*` (InvertMouseLookYAxis, MouseLookSensitivity,
MouseLookSmoothingAmount, UseMouseTurning); `Display_*` (FullScreen, Resolution,
SyncToRefresh, **RefreshRate**); `Camera_*` (AdjustmentSpeed, AlignToSlope, Stiffness);
`Misc_Tooltip{Delay,Enable}`; `UI_ChatFont{Face,Size}`;
`International_UseIME`.

### Complete registry inventory

Turbine-owned access is remarkably small:

1. **Read** HKLM `SOFTWARE\Microsoft\Microsoft Games\Asheron's Call\1.00` →
   `ACPlugin` (acclient.c:713261).
2. **Read then delete** HKCU `Software\Turbine\ac1` → `GLSTicket`
   (acclient.c:62385, 62401).
3. **Write** HKLM
   `SYSTEM\CurrentControlSet\Services\EventLog\Application\<AppName>` →
   `EventMessageFile` and `TypesSupported`, in `SetRegistryKeysForWatson`
   (acclient.c:719362–719375). Requires admin, and is only reachable from the
   never-installed crash path (§9).

Third-party reads: HKLM `SOFTWARE\Microsoft\Windows\CurrentVersion` →
`CommonFilesDir` for the unicows MSLU loader (acclient.c:64340, value at 64347);
HKLM `Software\Microsoft\Direct3D` at **both** acclient.c:553036 and 553063
(the second is `isMMXprocessor` reading `DisableMMX`); and
`Software\Intel Corporation\PLSuite\IJLib` → `USECPU` at
**acclient.c:571184–571185** (globals `ijlkey` / `usecpu` at 46101/46102).

One more Turbine-code read site exists that earlier drafts missed:
`LookFile::LookForFile` (0x671960) calls `RegEdit::QueryWStrValue(…, HKLM)` at
**acclient.c:648303**, using `LookFile::_key_path` / `_key` as key and value and
treating the result as a DAT search path. Every construction found initialises
those members to the null string, so the branch appears dead — but the
"complete inventory" claim should not have omitted it.

`RegEdit` exposes only `QueryStrValue` (ANSI and Unicode, two overloads each) and
`DeleteValue` — **there is no `RegEdit::SetValue`**.

---

## 8. Timing

`TimeSource_QueryPerformanceCounter` is the sole clock. `Init`
(acclient.c:77059) caches `m_rPerfsPerSecond`, `m_qwPerfsPerMS = freq/1000`, and
`m_qwPerfCountTolerance = freq/2`, and snapshots a paired reference
`(qwReferenceQPC, dwReferenceTGT = timeGetTime())` under a `CSpinLock<512,0>`.

`ComputeElapsedTime` (acclient.c:77098+) cross-checks the two clocks: if
`qpcDelta >= tolerance + perfsPerMs * tgtDelta` — QPC has run more than half a
second ahead of `timeGetTime` — it permanently latches flag `0x2` and falls back
to `timeGetTime * 0.001` **forever**, logging once via `bComplainedAlready`. This
is the classic AMD dual-core / SpeedStep QPC-jump workaround.

It also **rebases** `tReference` / `dwReferenceTGT` / `qwReferenceQPC` every 10
seconds (`v5 >= 0x2710`), and clamps monotonically.

`Timer::update_time` (acclient.c:75413) adds a second monotonic guard and
publishes `Timer::local_time` (raw elapsed) and `Timer::cur_time`
(= elapsed + `m_rExternalOffset`, the server-time sync offset) — both doubles in
seconds since `Timer::Init`. `Timer::cur_time` has 337 references.

---

## 9. There is no crash handling in this build

Three separate mechanisms exist in the source and **none of them is installed**.

**The 100 MB emergency pool is never allocated.** The call is
`VirtualAlloc(0, 0x6400000u, 0x2000u, 4u)` — exactly 104,857,600 bytes,
MEM_RESERVE only — at acclient.c:65104, gated on `BYTE1(DebugFlags) & 2`, i.e.
bit `0x200`. `DebugFlags` defaults to `0xFFFFFFFF` (acclient.c:44355), and
`Turbine::Debug::Init` does `DebugFlags &= ~0xE08` (acclient.c:61077, 65094),
which **clears** `0x200`. `0xE08` decomposes to `0x8 | 0x200 | 0x400 | 0x800`, so
the post-Init value is **`0xFFFFF1F7`** — bit `0x200` clear.

**`TurbineExceptionFilter` is never installed.** `Turbine::Debug::InitCommon`
gates the `SetUnhandledExceptionFilter` call on the same cleared bit
(acclient.c:65045).

**Watson is never installed either.** The machinery is all present —
`"%s\\watson\\dw15.exe"` (acclient.c:719536), `" -x -s %u"` (719537),
`"watson.microsoft.com"` (821736), and a payload embedding
`HKLM\Software\Microsoft\Internet Explorer\Registration\DigitalProductID`
(719510) plus `GetUserDefaultLCID()`. But the only construction passes
`fInstallNow = 0` (acclient.c:821733–821736), and
`TurnOnDwExceptionHandler::TurnOnDwExceptionHandler` calls
`SetUnhandledExceptionFilter` only when that flag is set
(acclient.c:719702–719705). Nothing else sets `m_fInstalled`.

**Net result: acclient.exe 11.4186 never installs a `SetUnhandledExceptionFilter`
handler.** All four call sites were enumerated: 64877 (the `~Debug` restore),
65046 (dead, gate clear), 719704 (dead, `fInstallNow == 0`), and 937256 (an
atexit teardown guarded by `m_fInstalled == 0`). There is no other mechanism —
zero `AddVectoredExceptionHandler`, `_set_se_translator`, `set_terminate`,
`_set_purecall_handler`, `signal()`, or `SetErrorMode`.

**Scope matters here.** "No top-level exception filter" is exact; "no crash
handling of any kind" would be too strong. `WinMainCRTStartup` still carries the
standard MSVC CRT `__try/__except(_XcptFilter)` frame around `WinMain` (the
`CPPEH_RECORD ms_exc` that Hex-Rays elided), `IError::AddDataErrorHandlers`
(61094) is installed, and `CrashCleaners::CallCrashCleaners` exists as
registered machinery whose reachability was not examined.

`Logger` / `LogController` (acclient.c:74089 onward) still work — a per-category
handler table fanning out to `ConsoleOutputHandler`,
`OutputDebugStringOutputHandler` (which only writes when `IsDebuggerPresent()`,
acclient.c:74161), `TextFileOutputHandler`, and
`TimestamppedTextFileOutputHandler`. The `g_strEmailAssertions` global exists and is assigned at acclient.c:65096 —
but the value `WinMain` passes is `&name`, and acclient.c:39028 declares
`char name = '\0';`. **The assert-email string is empty in this build.**

### Anti-cheat: no *local* integrity code — but there is a server-driven audit

No decompiled reference exists to `CheckRemoteDebuggerPresent`,
`NtQueryInformationProcess`, `BeingDebugged`, `NtGlobalFlag`,
`CreateToolhelp32`, `Process32`, `OpenProcess`, `ReadProcessMemory`,
`WriteProcessMemory`, `VirtualProtect`, `GetThreadContext`, `FindWindow`,
`EnumWindows`, or `IsBadReadPtr`.

There is exactly one `IsDebuggerPresent()` (acclient.c:74161), inside a logging
handler, and one `DebugBreak()` (acclient.c:77273) in the out-of-memory handler.
All 13 `GetTickCount` sites are frame budgets, spin-waits, or `__security_cookie`
seeding (721604) — none is a timing check. The `rdtsc` references sit in a
third-party math library's CPU dispatch (`__g_rdtsc` at 571216/571218, selecting
`ownRDTSCh` at 0x640650), not an integrity check. There is no code-section
checksum and no self-modifying code.

**But "anti-cheat absent" is too strong, and earlier drafts said it.** The client
ships a cooperative, server-driven third-party-software audit.
`ClientAdminSystem::Handle_Admin__Recv_QueryPluginList` (0x6B5EE0,
acclient.c:719765) and `Handle_Admin__Recv_QueryPlugin` (0x6B5F80, 719792)
respond to server Admin messages by interrogating the loaded `IACPlugin` and
reporting the plugin list — and per plugin, its name, author, e-mail, and webpage
— back via `CM_Admin::Event_QueryPluginListResponse`. With no plugin loaded the
client answers `L"3rd party API not in use."`. These are dispatched from live
handlers at acclient.c:710813 and 711104.

So the accurate claim is: **no local anti-debug, anti-tamper, or memory-integrity
code, but a server-queryable plugin manifest.**

A methodological caveat on all of the above: these are searches of a *Hex-Rays
decompilation*, not of the binary. An API resolved dynamically through
`GetProcAddress` can appear only as an unreferenced string literal — the unicows
loader at 64332 is exactly that pattern, and the `ijlkey` / `usecpu` globals are
literals IDA marked `// weak` that are nonetheless referenced at 571184. Read
these as "no decompiled reference to", not "provably absent".

---

## 10. AC1Legacy and PSUtils idioms

`PStringBase<T>` (acclient.h:8127) is a single pointer to character data with all
metadata at *negative* offsets in a shared `PSRefBuffer`. From
`allocate_ref_buffer` (acclient.c:60989–61035) the layout is:

| Offset | Field |
|---|---|
| +0 | vfptr |
| +4 | refcount |
| +8 | **capacity** |
| +12 | **cached string hash** (initialized to −1) |
| +16 | **length** |
| +20 | data |

The first pass had capacity and length transposed; a later draft called +12
"flags". It is the **cached hash**: `PStringBase<char>::hash` (79021) reads
base+12 and, when it equals −1, computes `compute_str_hash` and caches it there
(79028–79032); `set()` invalidates it back to −1 at 63824. IDA's own
`PSRefBufferStatistics<char>` type gives the order `{m_size, m_hash, m_len}`,
matching — while its *other* type, `AC1Legacy::PSRefBuffer<char>`
(acclient.h:25338), lists `m_len, m_size, m_hash` and is **wrong**. Growth is powers of two
via `bsr` up to `0x10000`, then 64 KB granularity; minimum block `0x24` bytes.

Strings are ref-counted copy-on-write: assignment bumps the count, mutators call
`break_reference` first (`SetAtIndex`, acclient.c:67702). The inlined destructor
pattern — `InterlockedDecrement` at `buffer[-1]`, virtual delete at `buffer[-2]`
— accounts for a large share of the decompiled noise.

Other containers: `SmartArray<T>` (acclient.h:8139) is
`{data, sizeAndDeallocate (top bit means owns), num}`. `IntrusiveHashTable` keeps
23 in-place buckets with prime-table sizing. `NIList` is a non-intrusive singly
linked queue used for NetBlob queues.

`_STL` is **STLport**: `_STL::__node_alloc<1,0>::_S_chunk_alloc`
(acclient.c:63479) uses 8-byte size classes up to `0x80` (16 free lists), taking
chunks from `operator new`.

`PSUtils` is a path and parsing toolbox: `get_directory`, `change_extension`,
`create_directory`, `explode`, `widify` / `narrowify`, `is_int32` / `is_double`,
`linewrap_string`.

---

## 11. Threading is thinner than it looks

**The process creates one thread.**

`PortalThread::PortalThread` (acclient.c:627455) is the generic base —
`CreateThread(..., CREATE_SUSPENDED, ...)` with an explicit stack size, resumed by
`PortalThread::Resume`. Its only subclass in this build is `ThreadedCache`, the
async DAT loader, so there is exactly one long-lived worker.

`CreateAndRunDebugWorkerThread` (acclient.c:64782) would be a second, transient
thread — create, wait 1 second on a ready event, join — but its only caller is
`RunInBackupStack` (64940), reachable only from `TurbineExceptionFilter`
(65024), which §9 proves is never installed. **It can never run.**

A nuance on the worker: `PortalThread`'s constructor takes a stack size, but its
only caller (`ThreadedCache::ThreadedCache`, 654382) passes **0**, i.e. the
default. And `acclient.h:27053` declares a second subclass,
`WinInetAsyncHttpClient`, whose object file was linked but contributes only
orphan EH funclets with no method symbols — it was dead-stripped. The conclusion
holds; the stated reason ("only subclass") did not.

Locks: `SharedCriticalSection` (acclient.c:627306, recursive-aware with
`lockHolder_` / `lockCount_`), a `CSpinLock<512,0>` in the time source, and four
raw `InitializeCriticalSection` calls, all in linked-in DirectShow code — three
in `CBaseRenderer::CBaseRenderer` (`render_base\renbase.obj`) and one in
`CRendererPosPassThru::CRendererPosPassThru` (**`render_base\ctlutil.obj`**).
There is also a second spinlock instantiation, `CSpinLock<1048576,0>`, guarding
`GrowBuffer::m_pFreeListLock` (66071, 66366).

---

## 12. `KeyStone` is a third-party UI runtime

`KeyStone::Init` (acclient.c:390175) checks for MSXML4, then
`LoadLibraryA("keystone.dll")` and resolves `KeystoneCreate`, whose signature
takes an `HWND`, an `IDirect3DDevice9*`, and callbacks for texture creation and
vertex-buffer allocation.

It then loads **`plugins\ACHelpPlugin.dll`** and
**`plugins\ACPluginManager.dll`**, resolving `ExecutePlugin` / `TerminatePlugin`
for each.

Keystone is Turbine's AC2-derived XML/HTML UI runtime, rendered into the same D3D
scene. In this client it hosts the in-game **Help** browser and the **Plugin
Manager** window (`OpenHelp` 0x557010, `OpenPluginManager` 0x556ED0,
`IsPluginManagerOpen` 0x557140). It also owns `TranslateAcceleratorA` and
`DispatchMessageA` hooks (0x556E50, 0x556DB0) so it can steal keyboard focus,
plus a dummy accelerator table created when Keystone is unavailable.

It is **not** a windowing shim and **not** the game UI, as the first pass
described it.

---

## 13. Shutdown, localization, and miscellany

`ClientMain::ClientCleanUp` (acclient.c:60873) calls the virtual `Cleanup`, then
`Release`, then `CFactory::CleanUp()` and `AC1Legacy::Version::Cleanup()`.

`Client::Cleanup` (acclient.c:77471) runs, in order: `Disconnect` →
`CCommunicationSystem::Cleanup` → `CleanupNet` →
`CLanguageInfoInterface::Shutdown` → `CleanupUI` → `CleanupPreferences`
(which saves the INI) → delete `QualityRegistrar` → delete `GlobalEventHandler` →
destroy `InterfaceSystem` (setting `s_bInterfaceSystemDestroyed`) →
`CleanupDatabase` → `SoundManager::Cleanup`.

`CLanguageInfoInterface` is **grammar and formatting, not string tables**:
`GetNumerals`, `GetDecimalSeperator`, `GetGroupingSeperator`, `GetGroupingSize`,
`GetNegNumFormat`, `GetLeadingZero`, `GetBase`, `IsNumberSingular`, and —
notably — `GetMaleMetaLetters`, `GetFemaleMetaLetters`,
`GetTreasureMetaLetters` (0x422230–0x4222D0), which drive AC's procedural
item-name metalanguage. Language selection flows through `EnumMapper` table `0xC`
(acclient.c:77523, 292257) into `Client::InitDatabase` (acclient.c:78750) and
`CLCache::SetLanguageInternal` / `SetRegion`.

`ProgramTypeSystem::s_eProgramType = 0x40000001` is a build-role tag. It is
compared elsewhere only against `0x80000001` and `0x80000002`
(acclient.c:104577, 105219, 107238, 664266) — a different high-bit family,
presumably server and tool roles — so those branches are dead in the client. They
gate string-table and property-grabber behaviour in code shared with offline
tools.

---

## 14. The PDB is a first-class artifact

`acclient.pdb` (29.6 MB, MSF 7.00) is a full Microsoft DBI PDB sitting next to
the decompilations. It yields **16,232 function symbols** with exact VA, byte
length, and owning `.obj`, plus **1,091 module records** with original build
paths. It has no call-graph records, so it cannot resolve call ordering — but it settles
every "is this really function X" and "how big is it" question instantly.

**Correction to an earlier draft: the PDB *does* carry line information** —
roughly 1.83 MB of C11 line records across the module streams, plus **730
distinct `.cpp` source paths** under `d:\ac1_sep13\src\…`, `d:\core\core_dev\src\…`,
and `d:\ac2_sdk\…`. VA→`file:line` resolution is therefore available, which is a
materially more capable artifact than earlier drafts assumed.

Also note the 16,232 figure is the `S_GPROC32` (global) count; there are a
further **23,716 `S_LPROC32`** static-function records, for 39,948 proc records
over 37,531 distinct VAs.

**Build identity:** `d:\ac1_sep13\output\obj\…\WIN32\retail\`, multithreaded CRT,
precompiled header `PCH_PortalPrecomp.obj`. Section layout: `.text` 0x401000
(0x390DD0), `.rdata` 0x792000, `.data` 0x80A000, `.data1` 0x906000, `.rsrc`
0x908000, `.reloc` 0x914000.

**Source-tree architecture**, recoverable for the first time. Modules group by
static library:

- `AC/*` — AC1 gameplay: `acqualities`, `accspells`, `acgameplay_misc`,
  `accui_misc`
- `GAME/*` — `game_ui_misc` (103 objs, the largest single group), `game_cevents`
- `ENGINE/*` — `render_base`, `uielement_types`, `uielement_desc`, `property`,
  `diskcon`, `engine_database`, `engine_cevents`
- `PORTAL/*` — `cphysobj`, `cgeometry`, `clinet`, `canim`, `cregion`, `ccell`,
  `sound`, `newnet`, `objdesc`

Third-party: `turbinecore.lib` (50 objs), `d3dx9.lib` (162), `unicoWS.lib` (60),
`ijl15l.lib` (33 — Intel JPEG Library), `MSVCRT.lib` (29), plus the DirectShow
`renbase.obj`.

**This confirms the `Portal*` / `AC*` / `gm*` naming is a genuine four-layer
library split, not merely a prefix convention.**

---

## 15. Traps for the unwary

**IDA's field names on the `Client` struct are offset-shifted and unreliable.**
`-account` writes to the field IDA calls `m_fReadOnlyDatFiles`
(acclient.c:78336, then `__strlwr` on it); `-rodat` writes
`m_fUseMemoryManager` (78384); and `-usemem`'s `AddCmd` storage target is
`&m_fWindowed` with default 1 (78286). The switches are real; the member names
attached to them are not. Consequently the first pass's "`-usemem` is effectively
vestigial" claim is **unverifiable** — the flag does write a bool member, but
which one cannot be determined without the binary.

**Duplicate static constants across translation units.** `MIN_QUANTUM` has 100
copies; only the `_93` and `_97` variants are live. Before citing a constant's
address, check whether the value at that address is actually the one being read.

**Two functions are undecompilable, and they are the frame pumps.** Do not treat
any published main-loop ordering — including the one in these documents — as
observed fact.
