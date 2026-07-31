# Memory Leak Investigation — 2015 Client (11.6096)

**Companion to `../../2013-09 11.4186/docs/11-memory-leak-investigation.md`.**
That document contains the full derivation: how icons are allocated, why the
refcounting is *not* the problem, what populates the null-weenie table, and the
evidence for each finding. This document does not repeat it. It answers one
question — **does 11.6096 have the same defects, and where are they** — and then
gives patch instructions for this build.

---

## 0. Verdict

**All three defects are present in 11.6096, and every function on the leak path
is byte-for-byte identical to its 11.4186 counterpart.**

> **Read §0b first.** A fourth defect — an unbalanced reference count in
> `Palette::makeModifiedPalette` — was identified after this document was
> written, and it is larger than all three below combined. It also affects both
> builds. The three defects here are real and worth fixing, but they are not the
> main event.

### All known defects, ranked

Every row is byte-level verified in **both** builds. "Bounded" means the leak
saturates: it pins an already-cached object rather than allocating a new one, so
it stops growing once the distinct set has been seen.

| # | Defect | Per event | Trigger | Bounded | Est. cost |
|---|---|---|---|---|---|
| 1 | **`Palette::makeModifiedPalette` over-references** (§0b) | **8,264 B** — 72 B object + 8,192 B ARGB buffer | Every *modified* palette manufactured: one per subpalette entry per object created, via `ACCObjectMaint::CreateObject` → `CPartArray::SetPalette` | **No** — `operator new` per call, never cache-registered | **~19 MB/hr** at the measured 40/min; the dominant leak by an order of magnitude |
| 2 | `null_weenie_object_table` never reaped (§2) | ~336 B weenie + 128 B `ACWTimeStamper` + ~8 KB `IconData` if an icon was drawn | Server message naming an object the client has not yet materialized — inventory opcodes, so loot-correlated | No | Low MB/hr; also costs a `SendForceObjdesc` every 20 s per entry, forever |
| 3 | `IconData` stranded by `DestroyObjects` (§3) | ~8 KB per object known — two `Graphic`s + two 32×32 `RenderSurface`s — plus 128 B | **Relog only**: logout to character select and back without quitting | No, accumulates per cycle | Several MB per relog on a busy scene; zero otherwise |
| 4 | `GenerateSurfaceFromFrontBuffer` abandons a surface | ~8.3 MB at 1920×1080 (full front buffer, `D3DPOOL_SYSTEMMEM`) + 0x130 B wrapper | Screenshot taken while the device is lost (alt-tab, resolution change) | No, but needs a rare trigger | ~0 in normal play; hundreds of MB if provoked |
| 5 | `CPartArray::MorphToExistingObject` drops a `CSetup` ref | one `CSetup`, ~1–4 KB | 3D creature-examine panel; paper-doll redress | **Yes** — per distinct setup DataID | A few hundred KB, then flat |
| 6 | `ItemList` widgets keep their surfaces (§1, fix 3) | ~4 KB | Widget returned to the cache without `ClearImage` | **Yes** — grid slot count | Tens of KB |
| 7 | `LScape::GenerateDetailSurface` drops an `ImgTex` ref | one `ImgTex` | Region change; detail-texture option toggled | **Yes** — max 4 ever | Negligible |
| 8 | `RenderTextureD3D::CreateD3DTexture` failure path | one D3D surface ref | Only if `operator new[]` returns null | — | Effectively unreachable |

Two entries that are **not** leaks but belong on the same page:

| Item | Why it matters |
|---|---|
| **`Palette::releasePalette` double-frees** (§0b) | Calls the deleting destructor twice where `DBObj::Release` calls it once. Unreachable on the dominant object-teardown path (which frees through `DBObj::Release`, once) but latent on the appearance-reset and character-generation paths. **Patch all three sites** to close the hazard |
| System RAM is structurally unreclaimable (§4) | `m_bIsThrashable` defaults false and both purge paths require it, so nothing the client does returns system memory. Converts every leak above from transient to permanent |

Latent, no reachable trigger today: `RenderSurface::Create`,
`RenderSurfaceD3D::CreateD3DSurface`, `RenderTextureD3D::CreateD3DTexture`,
`UISurface::CreateSurface` and `TextureBasedFont::InitFromFont` all overwrite a
buffer or COM pointer without releasing the previous value. Every current caller
guards. Worth knowing before adding one.

That is not an inference from matching decompiler output. It is a direct
byte-level comparison of the two shipped executables, with call/jump
displacements and relocated absolute operands normalised so that a function which
merely moved still compares equal. On that basis:

| Function | 11.4186 | 11.6096 | Bytes | Verdict |
|---|---|---|---|---|
| `CObjectMaint::DeleteObject(unsigned int)` | `0x005084D0` | `0x00508FA0` | 255 | **identical** |
| `CObjectMaint::DestroyObjects` | `0x00508C30` | `0x00509700` | 829 | **identical** |
| `CObjectMaint::GetNullWeenieObject` | `0x00509090` | `0x00509B60` | 163 | **identical** |
| `CObjectMaint::UseTime` | `0x005089B0` | `0x00509480` | 635 | **identical** |
| `CObjectMaint::AddObjectToBeDestroyed` | `0x00508F70` | `0x00509A40` | 111 | **identical** |
| `CObjectMaint::QueueBlobForWeenieObject` | `0x00509310` | `0x00509DE0` | 46 | **identical** |
| `CObjectMaint::~CObjectMaint` | `0x00509140` | `0x00509C10` | 400 | **identical** |
| `ACCObjectMaint::CreateObject` | `0x00558870` | `0x005594B0` | 497 | **identical** |
| `ACCObjectMaint::DeleteObject` | `0x005576F0` | `0x00558330` | 51 | **identical** |
| `ACCWeenieObject::ObjectBeingDeleted` | `0x0058E4D0` | `0x0058F300` | 374 | **identical** |
| `ACCWeenieObject::~ACCWeenieObject` | `0x0058C930` | `0x0058D760` | 106 | **identical** |
| `ACCWeenieObject::GetIconData` | `0x0058DE30` | `0x0058EC60` | 133 | **identical** |
| `UIElement_ItemList::ItemList_DeleteItem` | `0x004E3FE0` | `0x004E4C70` | 184 | **identical** |
| `UIElement_ItemList::ItemList_Flush` | `0x004E3D60` | `0x004E49F0` | 156 | **identical** |
| `UIRegion::ClearImage` | `0x0069F7E0` | `0x006A0660` | 69 | **identical** |
| `HashBase<unsigned long>::remove` | `0x00507AC0` | `0x005085F0` | 92 | **identical** |
| `SmartBox::Reset` | `0x00453BF0` | `0x00453C90` | 131 | **identical** |
| `CPlayerSystem::LogOnCharacter` | `0x0055F890` | `0x00560600` | 263 | **identical** |
| `UIQueueManager::ProcessEphemeralNetBlob` | `0x0055D0C0` | `0x0055DDE0` | 250 | **identical** |
| `UIQueueManager::HandleOrderingForBlob` | `0x0055D1C0` | `0x0055DEE0` | 361 | **identical** |
| `SceneTool::PurgeOldGraphicsResources` | `0x0043E5C0` | `0x0043E760` | 98 | **identical** |
| `RenderDeviceD3D::IsAvailableVideoMemoryLow` | `0x005A0460` | `0x005A1570` | 55 | **identical** |
| `DBOCache::FreelistAdd` | `0x004168B0` | `0x00416B50` | 113 | **identical** |

Exactly **one** function anywhere near this path changed between builds:
`UIQueueManager::ProcessNetBlobData` (`0x0055B000`, 8,280 bytes). That is the
top-level blob dispatcher upstream of the defer path, not part of the leak
mechanism. It is discussed in §5.

**Consequence: every finding, every cost estimate, and every runtime confirmation
test in the 11.4186 report applies unchanged to 11.6096.** Only the addresses
differ.

---

## 0b. Addendum — a fourth leak, and it is almost certainly the dominant one

**This section postdates the original investigation and corrects its emphasis.**
The defect was reported publicly at
`github.com/eriknihlen/ac-eor-palette-leak-fix`. Everything below has been
re-verified independently against both binaries; where the published account and
the binary disagree, the binary is followed and the difference is noted.

### The defect

`Palette::makeModifiedPalette` has two overloads, and **both increment the
reference count of an object that is already born with a count of 1.**

`DBObj::DBObj` (`0x00415460` in 11.6096, `0x004151C0` in 11.4186) ends with:

```asm
4151dd: mov  ecx,0x1
4151e2: mov  DWORD PTR [eax],0x7951E0     ; vtable
4151e8: mov  DWORD PTR [eax+0x24],ecx     ; <-- m_numLinks = 1
```

Both factory overloads then do this immediately after construction:

```asm
; overload A, 11.4186 0x0053E280 / 11.6096 0x0053EFE0
53e28e: push 0x800
53e293: mov  ecx,eax
53e295: call 53e100                ; Palette::Palette(0x800)
53e29e: inc  DWORD PTR [eax+0x24]  ; <-- refcount becomes 2
53e2a1: ret

; overload B, 11.4186 0x0053E3C0 / 11.6096 0x0053F120
53e43c: inc  DWORD PTR [esi+0x24]  ; <-- refcount becomes 2
```

`Palette::releasePalette` (`0x0053ED10` in 11.6096) decrements **once** and frees
only at zero:

```asm
53e007: dec  DWORD PTR [esi+0x24]
53e00a: jne  53dffe                ; refcount still 1 -> return, no free
53e00c: ... scalar deleting destructor ...
```

So a palette born at 2 is released to 1 and **never destroyed**.

### Why the release is genuinely unpaired

The critical question is whether some caller releases twice, in which case
removing the increment would cause a premature free. It does not. There are
exactly three creation sites in the image, and each pairs with exactly one
release:

| Creates | Releases |
|---|---|
| `CPartArray::SetPalette` → overload B, stores one pointer in `m_pals[i]` | `CPartArray::DestroyPals` → one `releasePalette` per slot, then nulls it |
| `ClientCharGenState::ClientCharGenState` → overload A | `~ClientCharGenState` → one `releasePalette` |

The `ClientCharGenState` row is the airtight case: one create, one release, so
the constructor leaves the count at 2 and the destructor drops it to 1 —
removing the increment restores an exact 1:1 balance and the palette is freed.
`CPartArray::SetPalette` behaves the same on its teardown path.

Two paths *do* take a second reference through `Palette::copyRef` — the earlier
draft's claim that "no site calls `copyRef` on a freshly manufactured palette"
is wrong. `CPartArray::SetPalette` hands `m_pals[i]` to
`CPhysicsPart::UsePalette` (`copyRef` at `0x0050DF4B`), and
`PalShift::MakeNewSurface` hands its palette to `CSurface::UsePalette` →
`CSurface::SetPalette` (`copyRef` at `0x00535EBF`). On the `CPartArray` path each
`copyRef` is balanced by a `releasePalette` in the same function, so the count
still nets out. The `PalShift` path does **not** balance: `MakeNewSurface`
creates the palette into `edi`, lets `CSurface::UsePalette` take its own
`copyRef`, and then discards `edi` at `0x0050038B` without releasing it;
`PalShift::CleanupSurface` later releases only the `copyRef`'d reference
(`surf+0x70`), never the factory one. **That palette leaks with or without the
increment patch** — a separate, unfixed asymmetry, distinct from the
over-reference this section is about.

### Cost, and why it dwarfs the other three

`Palette::Palette` allocates a colour buffer of `numColors * 4` bytes, and both
factories pass `0x800`, so each leaked palette strands **8,192 bytes of ARGB data
plus a 72-byte object**. Unlike the defects in §1, this is a **factory, not a
cache lookup** — every call runs `operator new`. The published measurements
(18–60 leaked palettes per minute unpatched, dropping to equilibrium when
patched; 56,664 instances and ~446 MB after 27 hours) are consistent with that
arithmetic: 40/min × 8 KB ≈ 19 MB/hour.

`CPartArray::SetPalette` runs whenever a part array's palette is established —
that is, on essentially every object appearance load or change. **This is the
leak that fills a 32-bit address space in a long session.**

> **This corrects the emphasis of the original report.** Its §1 argues that in
> this cache design "a Get without a Release pins a DID, it does not allocate",
> so refcount leaks are bounded by the number of distinct DIDs. That reasoning is
> correct *for cached `DBObj`s fetched by DataID* — and it is exactly why the
> icon audit came back clean. It does **not** apply to a factory method that
> constructs a new object on every call, and `makeModifiedPalette` is one. The
> original investigation never examined `Palette`, and the structural argument it
> relied on would not have caught this class of defect.
>
> It also means the original hypothesis — item-appearance data leaking, worsened
> by looting — was **directionally right**, just aimed at the wrong resource.
> Looting brings new items into view, each triggering `SetPalette`. The audit
> that cleared `IconData` was correct about `IconData`.

### ⚠ The obvious fix is not safe on its own — `releasePalette` double-frees

**`Palette::releasePalette` calls the scalar deleting destructor twice.** At
`0x0053ED6C` in 11.6096 (`0x0053E00C` in 11.4186):

```asm
53ed67: dec  DWORD PTR [esi+0x24]
53ed6a: jne  53ed5e                ; refcount not zero -> return
53ed6c: mov  eax,[esi]
53ed6e: push 1
53ed70: mov  ecx,esi
53ed72: call [eax+0x18]            ; scalar deleting destructor -> operator delete(this)
53ed75: mov  edx,[esi]             ; <-- reads freed memory
53ed77: push 1
53ed79: mov  ecx,esi
53ed7b: call [edx+0x18]            ; <-- frees it AGAIN
```

Vtable slot `+0x18` is `Palette::'scalar deleting destructor'` (`0x0053E370` in
11.4186), which ends in `operator delete(this)` when the flag bit is set — and
both calls pass 1. `DBObj::~DBObj` rewrites the vptr to the `DBObj` table on the
way out, so the second call lands in `DBObj::'scalar deleting destructor'`, which
frees the same pointer a second time.

That this is a defect rather than an idiom is settled by comparing it with
`DBObj::Release` (`0x00415160`), which is the house pattern and does it
correctly:

```asm
415173: mov  eax,[ecx+0x24]
415176: dec  eax
415177: mov  [ecx+0x24],eax
41517a: jne  415185
41517c: mov  edx,[ecx]
41517e: push 1
415180: call [edx+0x18]            ; exactly ONE call
```

The failure path inside `makeModifiedPalette` itself also calls it exactly once.

**On the dominant path the two bugs do not interact.** A manufactured palette has
two distinct release routes, and only one of them double-frees.
`Palette::releasePalette` (`0x0053ED10`) is the one shown above, with the doubled
`call [reg+0x18]`. The other is `DBObj::Release` (vtable slot `+0x14`,
`0x00415400`), which deletes exactly once; `~CPhysicsPart` (`0x0050E270`:
`call [eax+0x14]`) releases through it.

On the object-teardown path — the hot one — the ordering keeps the double-free
out of reach. `CPartArray::Destroy` (`0x005192A0`) calls `DestroyPals` **first**
(→ `releasePalette`, refcount 2→1, returns at the `0x0053ED6A` `jne` without
freeing) and `DestroyParts` **second** (→ `~CPhysicsPart` → `DBObj::Release`,
1→0, a **single** delete). `CPartArray::SetSetupID` has the same ordering. So
even under the published 6-byte patch — which removes the two `inc`s and leaves
the doubled free in place — the hot path releases each palette to 1 through
`releasePalette` and then frees it exactly once through `DBObj::Release`. That is
why the 6-byte version is reported stable across 15 clients: the double-free is
simply not on the path it exercises.

The double-free **is** reachable, but only on cold paths where the ordering
inverts and `releasePalette` is the route that takes the count to zero:
`CPartArray::DoObjDescChangesFromDefault` (`0x00519480`), which calls
`RestorePalette` on every part first and only then `DestroyPals`, and
`~ClientCharGenState`, which holds the sole reference at `this+0x25C` and releases
it with a single `releasePalette` at `0x0056397B`. On those appearance-reset and
character-generation paths a palette taken to zero by `releasePalette` is freed
twice. The honest summary is therefore **stable in practice, latent hazard**: the
6-byte patch is safe on the path that runs constantly and unsafe on paths that
run rarely.

### The fix — patch both, not just the increment

| Build | VA | File offset | Original | Patched | What |
|---|---|---|---|---|---|
| **11.6096** | `0x0053EFFE` | `0x0013EFFE` | `FF 40 24` | `90 90 90` | overload A `inc` |
| **11.6096** | `0x0053F19C` | `0x0013F19C` | `FF 46 24` | `90 90 90` | overload B `inc` |
| **11.6096** | `0x0053ED75` | `0x0013ED75` | `8B 16 6A 01 8B CE FF 52 18` | `90` ×9 | **second free** |
| 11.4186 | `0x0053E29E` | `0x0013E29E` | `FF 40 24` | `90 90 90` | overload A `inc` |
| 11.4186 | `0x0053E43C` | `0x0013E43C` | `FF 46 24` | `90 90 90` | overload B `inc` |
| 11.4186 | `0x0053E015` | `0x0013E015` | `8B 16 6A 01 8B CE FF 52 18` | `90` ×9 | **second free** |

Fifteen bytes at three sites, not six at two. Removing the *second* call (rather
than the first) is the right choice: the first still runs with a live vptr, and
each call is stack-balanced by the callee's `ret 4`, so nine `0x90` bytes are
stack-neutral.

> **Why the 6-byte patch is reported stable — resolved.** The published patch
> changes only the two `inc` sites and is reported to run stably across 15
> clients with allocation reaching equilibrium. By the release-route analysis
> above that is exactly what should happen, not a mystery: on the object-teardown
> path the palette is released to 1 through `releasePalette` and then freed once
> through `DBObj::Release`, so the doubled free is never the call that reaches
> zero. The double-free is a **latent hazard** confined to the appearance-reset
> and character-generation paths, not a hot-path certainty. The second call is
> still unambiguously present, still not the pattern used anywhere else in this
> codebase, and NOPing it costs nothing and closes the hazard. **Apply all three
> sites** — now for the right reason: eliminating a latent double-free, not
> preventing a certain one.

**The defect is present in the 2013 client too.** Both overloads compare
byte-identical between the builds under relocation-exact normalisation, so this
is not a regression introduced in 2015 — it shipped in both.

The 11.6096 binary this applies to is confirmed by SHA-256
`bca95bbebed4b9ed1ff09d0da83144e2fc4208f63ad7ada5cb47c3ca207ccba9`, which matches
the file in this folder exactly.

> **One correction to the published account.** It gives the second overload's
> address as `0x0053F19C`. That is the *patch site*, not the function entry —
> overload B begins at **`0x0053F120`**, and the `inc` sits `0x7C` bytes into it
> (matching `0x0053E3C0` + `0x7C` in the 2013 build). The patch offset itself is
> correct; only the function label is off. This matters if you are locating the
> function by signature rather than by hardcoded offset.

Being NOP fill, this needs no code cave and no detour — though it can equally be
applied at runtime from the same DLL that carries the other fixes (§4.4), which is
the better option if you would rather not modify the shipped executable.

### Two further asymmetries in the same subsystem — both real, both small

Found while auditing the surrounding code, verified by direct disassembly, and
recorded for completeness rather than urgency. Both are **pins, not
allocations** — they hold a cached object alive rather than creating a new one,
so they are bounded by the number of distinct DataIDs involved.

**`CPartArray::MorphToExistingObject`** (`0x00518D40` in 11.4186, `0x00519870` in
11.6096) overwrites `this->setup` without releasing the previous value:

```asm
518d45: call 518920            ; DestroyParts -- does not touch `setup`
518d4e: mov  ecx,[ebx+0x54]    ; template->setup
518d53: mov  [esi+0x54],ecx    ; this->setup = ...   <-- old reference dropped
```

`CPartArray::Destroy` and `CPartArray::SetMeshID` both release `setup` correctly;
this path is the only one that does not. It runs from
`CPhysicsObj::MorphToExistingObject`, reached by the 3D creature-examine panel and
the paper-doll redress, so it permanently pins one `CSetup` per distinct creature
model examined — on the order of a few hundred KB over a long session, and it
stops growing once the common models have been seen.

**`LScape::GenerateDetailSurface`** (`0x00506230` in 11.4186, `0x00506C90` in
11.6096) never releases the reference `DBObj::Get` returns:

```asm
506288: call 415190            ; DBObj::Get -> ImgTex, +1 ref
506299: call 536350            ; CSurface::UseTextureMap  (takes its own ref)
5062a5: mov  eax,esi
5062ab: ret  4                 ; <-- Get's reference never released
```

Its two sibling functions, `TexMerge::RestoreSurface` and
`TexMerge::MakeNewSurface`, both release the texture immediately after
`UseTextureMap`, which is what makes this an unambiguous asymmetry rather than a
design choice. The error path at `0x005062AE` releases the *surface* rather than
the texture, so the reference is lost there too. Impact is negligible — at most
four detail textures ever exist, and the path runs only on region change or when
the detail-texture option is toggled.

### How much memory the client can actually use

Worth stating precisely, because the ceiling is what turns a leak into a crash
and the commonly quoted figure is wrong for this binary.

**Both builds set `IMAGE_FILE_LARGE_ADDRESS_AWARE`.** PE Characteristics are
`0x012E` in each, and bit `0x0020` is set. The consequence:

| Host | User-mode address space |
|---|---|
| 64-bit Windows (WOW64) | **4 GB** |
| 32-bit Windows, `/3GB` boot switch | 3 GB |
| 32-bit Windows, default | 2 GB |

So on any modern 64-bit system this is a 4 GB process, not a 2 GB one. In
practice allocation starts failing somewhere around 3–3.5 GB because a 32-bit
address space fragments — and note that the leaked palettes are 8 KB each, above
the CRT's small-block threshold, so they come from the general heap and fragment
it as they accumulate.

**There is no internal budget or cap.** The client never adapts to available
memory: `GlobalMemoryStatus` is imported but called from exactly one place,
`ProfilerUI::Render`, purely for display. There is no fixed-size pool allocator —
allocation goes through `operator new` (`0x005DDFC5`) to MSVCR70.dll's allocator,
which is **dynamically linked** — `operator delete` at `0x005DE02E` jumps through
the IAT slot at `0x0079227C` to `MSVCR70.dll!??3@YAXPAX@Z`, and both `MSVCR70.dll`
and `MSVCP70.dll` are in the import table. Any behavior around a double-free —
whether it is silently absorbed or faults immediately — is therefore determined
by MSVCR70's allocator specifically, not by a statically linked CRT. The PE heap
reserve is the linker default of 1 MB, which is the initial process heap only and
not a limit.

**The `usemem` command-line flag is vestigial — it does nothing.** Its help text
("Enables the use of the memory manager") makes it look like a memory knob, so
it is worth recording why it is not:

1. `Client::BuildCommandLineArgs` (`0x004120C0`) registers it with
   `AddCmd(0x11, …, this+0x68, …)`. `ebp` is loaded once with `ecx` at
   `0x004120C7` and modified exactly once, by `add ebp,0x68` at `0x00412491`, so
   the destination is unambiguously `Client+0x68`.
2. The only consumer is `Client::InitUI` (`0x00411660`), which reads it at
   `0x00411670`, converts it to a boolean with `test ecx,ecx; setne cl`, and
   passes it as **argument 1** of `Device::Init`.
3. `Device::Init` (`0x0043B820`) **overwrites that argument slot before ever
   reading it.** Every access to `[esp+0x10C]` in the function is:

   | Address | Access |
   |---|---|
   | `0x0043B93A` | **write** `0` |
   | `0x0043B944` | **write** `1` |
   | `0x0043B9B9`, `0x0043B9EA`, `0x0043BBA5`, `0x0043BBCB` | reads, all after |

   The value written is computed from `ds:0x00817B02` — which
   `Device::AllowFullScreenMode` sets — and a field of the
   `RenderDevicePresentation` filled in by `Device::LoadDisplayPreferences`. In
   other words the slot now carries a **windowed/full-screen determination**, and
   has nothing to do with memory.

The parameter was evidently repurposed and the caller never updated. Both
`Client::InitUI` and `Device::Init` are byte-identical in 11.4186 and 11.6096, so
this holds for both builds. Scope of the claim: `Client+0x68` was checked against
every `Client::`, `gmClient::`, `ClientMain` and `WinMain` function; `InitUI` is
the only reader among them.

> **This corrects the published palette report**, which describes the client as
> "approaching its 2 GB virtual memory ceiling." With `LARGE_ADDRESS_AWARE` set
> the headroom on 64-bit Windows is roughly double that, which is consistent with
> the observed symptom of crashes after *multi-day* sessions rather than daily
> ones: at the measured ~17–19 MB/hour the palette leak alone needs on the order
> of a hundred-plus hours to exhaust a 4 GB space from a typical baseline.
> Anyone diagnosing against a 2 GB expectation will misread how far along a
> session is.

### How far the search for a second instance went

The obvious question is whether the same defect exists elsewhere. It does not,
and the search that establishes this was exhaustive rather than sampled.

**The refcount field is only ever touched in a handful of places.** Scanning all
3.7 MB of `.text` for every encoding of a reference-count bump on `[reg+0x24]`
(`inc dword [reg+0x24]`, `add dword [reg+0x24],1`, and direct stores of a value
greater than 1) finds **exactly three increment sites in each build**: the two
`makeModifiedPalette` overloads, and `DBOCache::AddObj`, where the cache
legitimately takes a reference. Every direct store of a value above 1 lands on an
unrelated `+0x24` field in a non-`DBObj` class. Every *decrement* site — four of
them — destroys at exactly zero, with no early return before the decrement.

**The set of classes that could have the bug is closed and was enumerated.**
`DBObj::DBObj` is never inlined, so every `DBObj`-derived object is built through
a literal `call`. That constructor has **exactly 58 direct callers in both
builds**, which is the complete set of `DBObj`-derived constructors, and there are
**67 `DBObj`-family vtables in both builds** (identified by `DBObj::QueryInterface`
in slot `+0x0C`). Of the 58, **41 are reachable only from their own `Allocator`**,
which is invoked solely through `DBOCache::GetFreeObj` — so at most one live
instance exists per DataID and a missing release merely pins. That covers
`RenderMesh`, `CMotionTable`, `CSoundTable`, `ClothingTable`, `CAnimation`,
`CEnvCell`, `CGfxObj`, `PalSet`, `CLandBlockInfo` and the rest of the DAT
resource classes.

That leaves **17 factories that call `operator new` per invocation** — the only
place the defect could recur. Sixteen of them pair their allocation with a
release: both `CSetup::makeSimpleSetup`/`makeParticleSetup`, both
`CSurface::makeCustomSurface` overloads, `ImgTex::CreateCombinedTexture` /
`CreateLScapeTexture` / `AllocateTempBuffer`, `RenderDevice::CreateLocalSurface`,
`RenderDeviceD3D::CreateSurface`/`CreateTexture`,
`UISurfaceObject::GenerateMaterial`, `RenderMaterial::GetSubObjects`, and four
one-shot startup allocations. **`Palette::makeModifiedPalette` is the only one
that returns an over-referenced object.**

The cache core is clean too — `AddObj`, `RemoveObj`, `DestroyObj`, `FreeObject`,
`FreelistAdd`/`Remove`/`RemoveOldest`, `GetFreeObj`, `Release`, `GetIfInMemory`,
`GetIfUsing` and both `AsyncCache` blocking-get paths all balance, and no eviction
path drops an object without decrementing.

One apparent anomaly is worth recording so nobody "fixes" it: **`CLandCell`
overrides `Release` with a no-op stub** (`mov eax,1; ret`), the only one of the 67
vtables that does not use `DBObj::Release`. That is correct by design —
`CLandCell`s are array elements inside a landblock, built by
`CLandBlockStruct::InitPVArrays` with `operator new[]` and destroyed with it, and
`CLandCell::Get` correspondingly does not AddRef. Refcounting an array element
would be a double free.

### The Direct3D layer is clean — and there is no "D3DXMesh leak"

The published palette report states that "a secondary `D3DXMesh` leak remains."
**That does not hold up.** A complete enumeration of the D3D9 COM surface — built
by locating the device pointer at `RenderDeviceD3D+0x468` and resolving the
method behind all 233 loads of that field, identically in both builds — finds
these creation sites and no others:

| Created | Released by |
|---|---|
| `D3DXCreateMeshFVF` (one call site, in `ConstructMesh`) | `D3DPolyRender::DestroyMesh` + every in-function failure path |
| `GetRenderTarget`, `GetDepthStencilSurface`, `GetSwapChain`, 1×1 `CreateTexture` | `RenderSurfaceD3D::Destroy`, `ReleaseD3DResources` |
| `CreateTexture`/`CreateCubeTexture`/`GetSurfaceLevel` | `ReleaseD3DTexture`, `ReleaseD3DSurfaces` |
| `CreateOffscreenPlainSurface` | `PurgeResource` / `Destroy` / destructor |
| `CreateVertexBuffer`, `CreateIndexBuffer` | `RenderVertexStreamD3D::Shutdown` |

`D3DPolyRender::ConstructMesh` contains **11 COM `Release` sites**, covering
every one of its failure exits; the single success exit stores the mesh into
`MeshBuffer`. `DestroyMesh` then releases the mesh (COM `Release`), releases the
associated `DBObj` (slot `+0x14`), `operator delete[]`s the batch array and
`operator delete`s itself. A `D3DXMesh` can therefore only leak if its owning
`CGfxObj`/`CEnvCell` leaks, and those are cache-managed with no imbalance.

The classic D3D leak sources are simply **absent from this client**: no
`CreateStateBlock`, `CreateRenderTarget`, `CreateDepthStencilSurface`,
`GetTexture`, `GetStreamSource`, `GetIndices`, `GetBackBuffer`, no shader or
declaration creation, and no `CloneMesh`. The per-frame render path
(`SetSurface`, `RenderMeshSubset`, `DrawMesh`, `DrawMeshInternal`) creates no COM
objects at all.

Two D3D-side defects do exist, neither material:

- **`RenderDeviceD3D::GenerateSurfaceFromFrontBuffer`** (`0x005A0210`) abandons a
  freshly created `RenderSurfaceD3D` on two exits — when `Create` fails, and when
  `GetFrontBufferData` returns `D3DERR_DEVICELOST`. That strands a full
  front-buffer `D3DPOOL_SYSTEMMEM` surface, ~8 MB at 1920×1080. Its only caller is
  the screenshot key, so it costs nothing in normal play, but taking screenshots
  during a device-lost window (alt-tab, resolution change) burns memory fast.
- **`RenderTextureD3D::CreateD3DTexture`** (`0x00695550`) leaks a
  `GetSurfaceLevel` reference on one of three failure exits, reachable only if
  `operator new[]` returns null. Not worth patching.

Also worth knowing: **`RenderMesh::*` is dead code in the retail client.**
`MeshBuffer::pRenderMesh` is read in eight places and never assigned anywhere in
the binary, so `RenderMesh::Destroy`, `ReleaseFragments`, `ReleaseSubObjects`,
`CreateLODBatch` and `RenderMeshBatch::InitRenderBatch` never execute.

### One latent hazard, no reachable trigger

`RenderSurface::Create` (`0x00443FF0`) `operator new[]`s the surface bits into
`this+0x64` **without freeing any previous allocation**, where
`RenderSurface::Destroy` and `~RenderSurface` both free it. A second `Create` on
a live surface would therefore strand the first buffer. Its only two direct
callers are `RenderSurfaceD3D::Create` and
`RenderSurfaceD3D::CreateFromD3DSurface`, and the purge/restore LRU cycle nulls
the pointer before recreating, so no current path triggers it. The same shape
appears in `RenderSurfaceD3D::CreateD3DSurface`, `RenderTextureD3D::CreateD3DTexture`,
`UISurface::CreateSurface` and `TextureBasedFont::InitFromFont` — all guarded
today. Worth remembering before adding a caller.

---

## 0c. Two externally-reported leaks — one confirmed, one not

Both were reported against 11.6096 and checked against both images; the full
derivation is in the 11.4186 report **§4b**. Summarised here because the reported
addresses are this build's.

**Leak 5 — `RenderSurface` / `RenderTexture` inherit a do-nothing
`PurgeResource`: NOT CONFIRMED.** Every component is real. The base
implementation at `0x004154A0` is `mov al,1; ret`; it occupies vtable slot 2
(`+0x08`), which `GraphicsResource::PurgeOldResources` (`0x00446DC0`) dispatches
with `call [edx+0x8]`; on a success return the loop sets the flag at `[esi+0x8]`
and its own head then skips that resource forever; and the base vtables
`0x0079A67C` / `0x0079C198` do carry the stub while six sibling classes override.
But neither named class reaches that path. `RenderTexture`'s constructor has a
single caller — `RenderTextureD3D`'s — which overwrites the `GraphicsResource`
sub-object vtable at `+0x30` with the overriding one, so **no leaf
`RenderTexture` is ever built**. And `m_bIsThrashable`, which the loop tests
*before* the dispatch, is zero from the constructor and is never set on a leaf
`RenderSurface`. **Do not repoint these vtable slots on the strength of this
report** — see §4b for the full argument and for what the reported +250/hr growth
might otherwise be.

**Leak 6 — the inventory icon pool is trimmed only while its panel is visible.**
`UIElement_ItemList::ItemList_Flush` (`0x004E49F0`) clears each
`UIElement_UIItem` (1,736 bytes, vtable `0x007C0498`) and sets it to the WAITING
state `0x1000001C`, but never calls `InternalDeleteItem` (`0x004E41C0`) — by
design, the array is a recycle pool. The only trim,
`UIElement_ItemList::UpdateEmptySlots` (`0x004E4390`), returns immediately unless
`UIElement::IsVisible` (`0x004603A0`) is true, so a closed panel never drains and
each container opened grows the pool. Two-site patch: six `90`s at `0x004E439D`
and six at `0x004E43C0`.

The original report adds a third site, `75 0D` → `75 08`, described as making the
trim loop skip past non-WAITING items. That branch is at `0x004E4496` (not
`0x004E4497`), and the change does not do what is claimed: both delete loops
re-fetch `[esi+0x610]-1` — always the *last* item — so they trim trailing slack
and correctly stop at the first non-WAITING entry. Patched, the loop re-tests the
same item and spins until its counter expires, deleting nothing extra. See the
11.4186 report §4b for the disassembly.

---

## 1. The three defects, restated

Short form only — see the 11.4186 report §2–§4 for the derivation.

**Defect 1 — `null_weenie_object_table` is unreapable (primary, loot-correlated).**
`CObjectMaint::DeleteObject(unsigned int)` handles its two halves
asymmetrically. The physics half falls back to `null_object_table` on a miss; the
weenie half does not. A weenie that exists only in `null_weenie_object_table` can
never be found, destroyed, or unlinked. The defer path that creates those
placeholders is driven by inventory opcodes, which is why looting amplifies it.
Each stranded entry also buys a permanent `SendForceObjdesc` re-request every
20 seconds.

**Defect 2 — `IconData` stranded on bulk teardown (relog-correlated).**
`CObjectMaint::DestroyObjects` unlinks each weenie inline and then calls **vtable
slot 0 only**. `ObjectBeingDeleted` (slot 1) is the sole place `IconData` is
removed from `iconDataTable`, so every live icon — two `Graphic`s and two 32×32
`RenderSurface`s, roughly 8 KB plus a D3D texture — is stranded, along with the
object's `ACWTimeStamper`. Trigger: log out to character select and back in
without quitting.

**Defect 3 — `ItemList` widgets keep their surfaces (minor, bounded).**
Neither `ItemList_DeleteItem` nor `ItemList_Flush` calls `UIRegion::ClearImage`
when returning a widget to the cache.

### Byte-level confirmation in *this* binary

**Defect 1** — `CObjectMaint::DeleteObject(unsigned int)` @ `0x00508FA0`, weenie
half. The `je` at `0x0050904D` is the defect:

```asm
; weenie_object_table is at this+0xB4  (mask +0xB8, key_shift +0xBC, buckets +0xC0)
50902b: mov  ecx,[edi+0xBC]        ; key_shift
509031: mov  eax,[edi+0xC0]        ; buckets
509037: lea  ebp,[edi+0xB4]        ; &weenie_object_table
50903d: mov  edx,ebx
50903f: shr  edx,cl
509041: mov  ecx,[ebp+0x4]         ; mask
509044: xor  edx,ebx
509046: and  edx,ecx
509048: mov  esi,[eax+edx*4]       ; bucket head
50904b: test esi,esi
50904d: je   50905c                ; <-- MISS goes straight to the exit
50904f: nop
509050: cmp  ebx,[esi+0x8]         ; chain walk on id
509053: je   509066
509055: mov  esi,[esi+0x4]
509058: test esi,esi
50905a: jne  509050
50905c: pop  edi / pop esi / pop ebp
50905f: xor  eax,eax               ; <-- return 0.  NO null-table fallback.
509061: pop  ebx / pop ecx
509063: ret  0x4

509066: test esi,esi
509068: je   50905c
50906a: mov  edx,[esi]
50906c: mov  ecx,esi
50906e: call [edx+0x4]             ; slot 1 = ObjectBeingDeleted
509071: mov  eax,[esi+0x8]
509074: push eax
509075: mov  ecx,ebp
509077: call 5085f0                ; HashBase::remove (weenie_object_table)
50907c: mov  ecx,[esi+0x8]
50907f: push ecx
509080: lea  ecx,[edi+0xCC]        ; &null_weenie_object_table
509086: call 5085f0                ; HashBase::remove  -- INSIDE the hit branch
50908b: mov  edx,[esi]
50908d: push 0x1
50908f: mov  ecx,esi
509091: call [edx]                 ; slot 0 = scalar deleting destructor
```

The `null_weenie_object_table` removal at `0x00509080` sits inside the hit
branch, so it only ever runs for objects already found in
`weenie_object_table`.

**Defect 2** — `CObjectMaint::DestroyObjects` @ `0x00509700` (829 bytes)
contains exactly **two** indirect vtable calls: `call [edx]` at `0x005098B9`
and `call [eax]` at `0x005099B2`. Both are slot 0. **There is no `call [reg+4]`
anywhere in the function.** `ObjectBeingDeleted` is never invoked during the
bulk sweep.

**Defect 3** — `ItemList_DeleteItem` @ `0x004E4C70` and `ItemList_Flush` @
`0x004E49F0` contain no reference to `UIRegion::ClearImage` (`0x006A0660`),
confirmed both by disassembly and by reading the decompiled bodies
(`../acclient.c` `sub_4E4C70`, `sub_4E49F0`).

---

## 2. `CObjectMaint` table layout

Read directly from the 2015 disassembly above and from the `DestroyObjects`
epilogue. **These offsets are identical in both builds** — that follows from the
functions comparing byte-equal, since structure displacements are literal
operands and are not relocated.

| Offset | Table | Fields |
|---|---|---|
| `this+0x84` | `object_table` (physics) | mask `+0x88`, key_shift `+0x8C`, buckets `+0x90` |
| `this+0x9C` | `null_object_table` (physics) | mask `+0xA0`, key_shift `+0xA4`, buckets `+0xA8` |
| `this+0xB4` | **`weenie_object_table`** | mask `+0xB8`, key_shift `+0xBC`, buckets `+0xC0` |
| `this+0xCC` | **`null_weenie_object_table`** | mask `+0xD0`, key_shift `+0xD4`, buckets `+0xD8` |
| `this+0x1CC` | `destruction_object_table` | — |

Each `HashBase` is 0x18 bytes, and the four tables sit at a uniform 0x18 stride
from `0x84`. The 11.4186 report listed `+0x84`, `+0x9C`, `+0xCC` and `+0x1CC`
without identifying `+0xB4`; that gap is now closed.

Bucket-node layout, from the chain walk: `+0x00` = object pointer target of the
vtable calls, `+0x04` = `hash_next`, `+0x08` = object id.

---

## 3. The vtable question — and a correction to the 11.4186 report

`ACCWeenieObject` has **two** vtables and slot 1 means completely different
things in each. Getting this wrong turns a fix into a crash.

Ground truth is `~ACCWeenieObject`, which writes both vptrs explicitly. In
11.6096 at `0x0058D760`:

```asm
58d76c: lea  edi,[esi+0xC]
58d76f: mov  DWORD PTR [esi],0x7E4F70     ; vptr at object+0
58d775: mov  DWORD PTR [edi],0x7E4F58     ; vptr at object+0xC
```

| Sub-object | 11.4186 vtable | 11.6096 vtable | Slot 0 | Slot 1 |
|---|---|---|---|---|
| **`ACCWeenieObject` at `object+0`** | `0x007E3EA0` | **`0x007E4F70`** | scalar deleting destructor | **`ObjectBeingDeleted`** |
| `NoticeRegistrar` at `object+0xC` | `0x007E3E88` | `0x007E4F58` | vector deleting destructor | `NoticeRegistrar::RegisterNoticeHandler` |

2015 slot values at `0x007E4F70`: `0058DA50`, **`0058F300`**, `00509FD0`,
`0058CC40`, `0058D6C0`, `0058D200`.
2015 slot values at `0x007E4F58`: `0058D720`, `0043CA10`, `0043C860`,
`0043C8A0`, `0043C930`, `00000000`.

The hash tables store the **complete-object pointer** (`object+0`), so
`DeleteObject`'s `call [edx+0x4]` correctly reaches `ObjectBeingDeleted`.

> **Correction.** The 11.4186 report labels `0x007E3E88` "primary" and
> `0x007E3EA0` "secondary", and describes the hash tables as storing "the
> secondary sub-object pointer". The labels are inverted: `0x007E3EA0` is the
> vptr written at `object+0` and `0x007E3E88` is the `NoticeRegistrar` base
> sub-object vptr at `object+0xC`. The *practical* conclusion in that report is
> unaffected and its warning still stands — a patch author who looks up
> "ACCWeenieObject's vtable", lands on the `NoticeRegistrar` table, and calls
> slot 1 will invoke `RegisterNoticeHandler` on every object during teardown.
>
> **Avoid the ambiguity entirely: call `0x0058F300` directly.**

---

## 4. Patch instructions for 11.6096

### 4.1 Binary identity

Verify you have the right file before patching anything.

| Property | Value |
|---|---|
| Size | 4,841,472 bytes (`0x49E000`) |
| MD5 | `116d9a66a70b6af449dc3a28d82f2f6d` |
| Linker timestamp | 2015-06-12 08:16 UTC |
| `FileVersion` | `00.00.11.6096` |
| PDB GUID / age | `08E25C14-E2A1-46D5-B05692B2E43A7234` age 1 |
| PDB path | `d:\ac1_acxp\output\bin\GAME\WIN32\retail\acclient.pdb` |
| ImageBase | `0x00400000` |
| **DllCharacteristics** | **`0x0000`** |

`DYNAMICBASE` is clear, so **there is no ASLR and absolute addresses in patch
code are safe** — the same as 11.4186. `NX_COMPAT` is also clear.
`CheckSum` is `0x004A60C3`; Windows enforces it only for drivers and
services, but recompute it if you modify the file.

**No PDB ships for this build.** Every 11.6096 address in this document was
derived by matching normalised function bodies from the 11.4186 binary (which
does have symbols) against the 11.6096 `.text`, then confirmed against the
decompilation in `../acclient.c`, where all of them appear as real function
entry points (`sub_508FA0`, `sub_509700`, `sub_58F300`, `sub_58D760`,
`sub_4E4C70`, `sub_6A0660`, `sub_5085F0`).

### 4.2 File offsets

`file offset == RVA` holds for `.text`, `.rdata` and `.data`, so for every patch
site in this document:

```
file offset = VA - 0x400000
```

> **Correction to the 11.4186 report**, which claims this identity holds for
> *every* section. It does not, in either build. `.data` has a large BSS tail
> (raw size `0x2D000` against a virtual size of `0xFB7D4`), so `.data1`, `.rsrc`
> and `.reloc` are all shifted by −847,872 bytes (−`0xCF000`) relative to their
> RVAs. All patch sites here are in `.text`, so the simple rule is safe *for
> this purpose* — but do not apply it to resources or relocations.

### 4.3 Address table

| Item | 11.6096 VA | File offset | Size |
|---|---|---|---|
| `CObjectMaint::DeleteObject(unsigned int)` | `0x00508FA0` | `0x00108FA0` | 255 |
| `CObjectMaint::DeleteObject(CPhysicsObj*)` | `0x00508F30` | `0x00108F30` | 108 |
| `CObjectMaint::DestroyObjects` | `0x00509700` | `0x00109700` | 829 |
| `CObjectMaint::GetNullWeenieObject` | `0x00509B60` | `0x00109B60` | 163 |
| `CObjectMaint::UseTime` | `0x00509480` | `0x00109480` | 635 |
| `ACCWeenieObject::ObjectBeingDeleted` | **`0x0058F300`** | `0x0018F300` | 374 |
| `ACCWeenieObject::GetIconData` | `0x0058EC60` | `0x0018EC60` | 133 |
| `ItemList_DeleteItem` | `0x004E4C70` | `0x000E4C70` | 184 |
| `ItemList_Flush` | `0x004E49F0` | `0x000E49F0` | 156 |
| `UIRegion::ClearImage` | **`0x006A0660`** | `0x002A0660` | 69 |
| `HashBase<unsigned long>::remove` | **`0x005085F0`** | `0x001085F0` | 92 |
| `ACCObjectMaint::CreateObject` | `0x005594B0` | `0x001594B0` | 497 |
| `SmartBox::Reset` | `0x00453C90` | `0x00053C90` | 131 |
| `CPlayerSystem::LogOnCharacter` | `0x00560600` | `0x00160600` | 263 |
| `APIManager::Init` | `0x0055AF00` | `0x0015AF00` | — |
| vtable, `object+0` | `0x007E4F70` | `0x003E4F70` | — |
| vtable, `object+0xC` | `0x007E4F58` | `0x003E4F58` | — |
| **Code cave — `DwExceptionFilter`** | **`0x006B6760`** | `0x002B6760` | **1292** |

### 4.4 Recommended delivery: a DLL, not a modified EXE

**The plugin loader survives intact in 11.6096.** `APIManager::Init` at
`0x0055AF00` still reads
`HKLM\SOFTWARE\Microsoft\Microsoft Games\Asheron's Call\1.00\ACPlugin`,
`LoadLibrary`s the named DLL, and calls its exported `CreateACPlugin` — the
Decal injection point. Verified by string cross-reference in this binary: the
`ACPlugin` value name at `0x007CD1F8` is referenced from `0x0055AF1A`, and
`CreateACPlugin` at `0x007CD1E8` from `0x0055AFB5`, both inside that function.

A DLL installing runtime detours beats editing the EXE on every axis: no PE
surgery, no checksum, no code cave needed at all, reversible by clearing one
registry value, and iterable without redistributing a client. Since
`DYNAMICBASE` is clear the addresses above are stable and can be hardcoded,
though computing them from the module base costs nothing and is more robust.

Note that `APIManager::Init` is **byte-identical** between the two builds: the
11.4186 body at `0x0055A2C0` (361 bytes) normalises equal to the 11.6096 body at
`0x0055AF00`. It is one of the 11,081 unchanged functions (see
`13-client-differences-2013-vs-2015.md`), so the registry path, the export name,
the load mechanism, and the surrounding code are all the same, and a byte patch
of this function ports across builds without adjustment.

### 4.5 Implement all three as *additive* hooks

None of the three needs the original logic restructured.

**Fix 1** — detour `0x00508FA0`. Call the original; **if it returns 0**, perform
the `null_weenie_object_table` (`this+0xCC`) lookup yourself, call `0x0058F300`
on the node's object pointer, then `HashBase::remove` (`0x005085F0`) and the
slot-0 destructor. Highest value of the three; this is the loot-correlated leak.

**Fix 2** — detour `0x00509700`. **Before** calling the original, walk
`weenie_object_table` (`this+0xB4`) and call `0x0058F300` on each entry. The
original's slot-0-only sweep then does no harm. Frees both the stranded
`IconData` and the `ACWTimeStamper`.

**Fix 3** — detour `ItemList_DeleteItem` (`0x004E4C70`) and `ItemList_Flush`
(`0x004E49F0`); call `UIRegion::ClearImage` (`0x006A0660`) on the widget before
delegating. Low risk, small bounded benefit.

**Not recommended:** making `ImgTex`'s system-memory texture thrashable. It is
marked non-thrashable deliberately — it is the restore source after device loss.
Changing it risks black textures on alt-tab or resolution change rather than
fixing anything. This is unchanged in 11.6096
(`SceneTool::PurgeOldGraphicsResources` and
`RenderDeviceD3D::IsAvailableVideoMemoryLow` are both byte-identical).

### 4.6 Code cave, if you insist on in-place patching

`DwExceptionFilter` at **`0x006B6760`** (1292 bytes, file offset `0x002B6760`)
is the best choice, exactly as in 11.4186. An xref scan across the whole image
finds:

| Candidate | VA | Size | References | Safe? |
|---|---|---|---|---|
| **`DwExceptionFilter`** | **`0x006B6760`** | **1292** | 1 absolute at `0x006B6D41`; **0 calls** | **YES — best** |
| `SetRegistryKeysForWatson` | `0x006B6620` | 189 | 1 call, from `0x006B6AC0` (Watson code that never runs) | probably |
| `BuildListOfExtraFiles` | `0x006B66F0` | 107 | 1 call, from `0x006B696C` (same) | probably |
| `AddDllToDumpCapture` | `0x006B65C0` | 86 | 1 call, from `0x006B66EA` (same) | probably |
| `AddDllToDumpCapture` | `0x006B66E0` | 16 | 1 call from **`0x00557691` — live game code** | **NO** |
| `TurnOnDwExceptionHandler` | `0x006B6CF0` | 144 | 1 call from `0x00724E7C` **that executes at startup** | **NO** |

The single reference to `DwExceptionFilter` is the `push 0x6b6760` at
`0x006B6D40`, feeding `SetUnhandledExceptionFilter` through the IAT at
`0x007931A4`. That push is inside a branch that never executes:

```asm
; caller, 0x00724E70
724e70: push 0x8076ac
724e75: push 0x0                  ; <-- fInstallNow = 0
724e77: mov  ecx,0x8fba38
724e7c: call 6b6cf0               ; TurnOnDwExceptionHandler

; callee, 0x006B6CF0
6b6d32: cmp  DWORD PTR [esp+0x14],ebx   ; arg1 (fInstallNow) vs 0
6b6d36: je   6b6d5b                     ; taken -> skips the install
6b6d40: push 0x6b6760
6b6d45: call DWORD PTR ds:0x7931a4      ; SetUnhandledExceptionFilter
```

**The filter is never registered, so its body is genuinely dead.** 1292 bytes of
real code with no `0xCC` padding — ample for all three detours.

`TurnOnDwExceptionHandler` itself really does run at startup; do not overwrite
it. The 16-byte `AddDllToDumpCapture` at `0x006B66E0` is called from
`0x00557691`, which is live application code, not the Watson block — it is *not*
a safe cave despite sitting in the same address range.

---

## 5. The one nearby function that changed

`UIQueueManager::ProcessNetBlobData` (`0x0055B000` in 11.4186, 8,280 bytes) is
the only changed function anywhere near this path. It is the top-level dispatcher
for incoming net blobs, upstream of `ProcessEphemeralNetBlob` and
`HandleOrderingForBlob` — both of which are byte-identical.

What changed in it is now known precisely: 11.6096 dispatches **two additional
server→client message IDs, `0x317` and `0x318`**, and nothing was removed. The
top-level pivot moves from `cmp edx,0x276` to `cmp edx,0x27A`. Each new opcode
carries a single string payload and is routed by a new 160-byte dispatcher
(`0x006A56F0` and `0x006A5790`) into the pre-existing transient-string and
pop-up-string handlers, both of which are themselves byte-identical to 11.4186.

Neither new opcode is an inventory message, so neither reaches the defer path.
Since the two functions that actually park a blob against a placeholder weenie
are unchanged, and `GetNullWeenieObject` is unchanged, **the mechanism that feeds
the primary leak is unchanged, and so is the set of opcodes that drives it.**

---

## 6. Confirming at runtime

The tests in the 11.4186 report §7 apply verbatim. The cheapest one needs no
debugger:

**Defect 1** leaves a network signature. Each stranded weenie causes
`CObjectMaint::UseTime` to re-send `Proto_UI::SendForceObjdesc` for that id every
20 seconds, forever. Capture client→server UDP over a long session with heavy
looting and count distinct object ids in recurring `ForceObjdesc` requests. **A
monotonically growing set is the leak, directly observed.** It also means the
defect costs bandwidth continuously, not just memory.

**Defect 2** is confirmed by watching the process working set across
log-out-to-character-select and log-back-in cycles without quitting the client.
A staircase that never descends, proportional to how busy the scene was at
logout, is this defect. A possible second-order symptom worth watching for:
`GetIconData` keys `iconDataTable` by object id and only inserts when no entry
is found, so a stranded entry whose id collides with a new object after relogging
returns a **stale icon**. Players reporting wrong item icons after a relog would
be independent confirmation.

---

## 7. Provenance

Every 11.6096 address here was produced by one of three methods, and each was
confirmed by at least two:

1. **Relocation-exact body matching** — the definitive method. The PE `.reloc`
   section names precisely which dwords in each image are absolute addresses;
   those are zeroed, and `call`/`jmp`/`jcc` rel32 displacements are masked using
   instruction boundaries taken from a real disassembly of the function rather
   than guessed. The resulting signature is searched across the whole 11.6096
   `.text`. A unique hit is a rename-free identification that cannot be confused
   by code motion.
2. **Disassembly of the 11.6096 bytes** at the resulting address, checked
   against the expected instruction sequence (shown in §1 and §3).
3. **Cross-check against `../acclient.c`**, the name-stripped decompilation of
   this exact binary, where the derived addresses appear as `sub_XXXXXX` function
   entry points.

The vtable addresses came from a fourth, independent route: searching the whole
image for a dword equal to the resolved `ObjectBeingDeleted` address. In both
builds it occurs **exactly once** — `0x007E3EA4` in 11.4186, `0x007E4F74` in
11.6096 — which pins the vtable and the slot index without ambiguity.

**Two methodological warnings, since both bit this analysis.** Anyone repeating
this work will hit them.

*Guessing where the operands are does not work.* A first pass normalised each
function independently by scanning for `E8`/`E9` opcodes and in-range dwords. That
scan is phase-sensitive — masking a 4-byte operand can swallow the opcode byte
that follows, after which the walk is desynchronised — so two identical functions
can normalise differently and compare unequal. It produced hundreds of false
differences, including `~ACCWeenieObject`, which disassembly then showed to be
instruction-for-instruction identical.

*Comparing two functions in lockstep does not fix it either.* A second pass
walked both bodies at the same offset and tolerated a difference only where both
sides held an in-image address. That fails whenever the low byte of an address
happens to be equal in both builds — the first *differing* byte is then at
operand offset 1, 2 or 3, the dword read at that position is garbage, and the
comparison rejects a function that is actually identical. `ObjectBeingDeleted`
failed this test despite being byte-identical.

**Only the relocation table is authoritative about which bytes are addresses.**
Use it, take instruction boundaries from a disassembler rather than a byte
scanner, and the ambiguity disappears. Across the two images that method finds
**only 46 functions changed, over 99.5% identical**; four successive heuristics
reported 2.7%, 3.5%, 40.2% and 0.84% of functions changed, and every one of them
was wrong. See `13-client-differences-2013-vs-2015.md` for the full comparison.
