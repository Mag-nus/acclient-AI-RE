# Memory Leak Investigation — Icons, Looting, and Object Lifetime

Target: acclient.exe 11.4186 (September 2013). Line references are into
`../acclient.c` and `../acclient.h` unless noted.

**Hypothesis under test:** the client leaks memory the longer it runs; the leak
is icon files not being freed; looting makes it worse.

---

## 0. Verdict

**The hypothesis is half right, and the half that is right has a different cause
than stated.**

| Claim | Finding |
|---|---|
| "The client leaks memory over time" | **Confirmed** — four independent leaks, plus a structural amplifier |
| "Icon files are not being freed" | **Not supported as stated.** All 17 icon-DID acquisitions are correctly refcounted and released. But icon *pixel* memory does leak, through a different object (`IconData`) on a different trigger — and **item-appearance memory leaks badly through `Palette`, see §0b** |
| "Looting makes it worse" | **Confirmed.** Two separate mechanisms: server messages about objects the client has not yet materialized (§2), and a leaked 8 KB palette for every item appearance loaded (§0b) |

Four defects are known. Ranked by size, the palette leak in **§0b dominates the
three below combined** — read it first. The original three, ranked by how well
each matches the reported symptom:

1. **`null_weenie_object_table` is never reaped** (§2) — a genuine asymmetry bug.
   Unbounded, monotonic, **correlates with looting**. This is the best match for
   "leaks the longer it runs, worse when looting."
2. **`IconData` is stranded on bulk teardown** (§3) — every icon's composited
   pixels leak on **relog**, not on looting. Roughly 8 KB × every object the
   client knew about, per logout-to-character-select cycle.
3. **System-RAM texture memory is structurally unreclaimable** (§4) — not a leak
   in itself, but it means nothing the client does can ever give memory back, so
   every other defect is permanent rather than transient.

---

## 0b. Correction — a fourth leak, larger than all three above

**Added after the original investigation, and it changes the ranking.**

`Palette::makeModifiedPalette` — both overloads, `0x0053E280` and `0x0053E3C0` —
increment the reference count of an object that `DBObj::DBObj` (`0x004151C0`)
has already initialised to 1:

```asm
4151dd: mov  ecx,0x1
4151e8: mov  DWORD PTR [eax+0x24],ecx     ; m_numLinks = 1
...
53e295: call 53e100                       ; Palette::Palette(0x800)
53e29e: inc  DWORD PTR [eax+0x24]         ; refcount becomes 2
```

`Palette::releasePalette` (`0x0053DFB0`) decrements once and frees only at zero,
so every manufactured palette settles at 1 and is never destroyed. All three
creation sites — `CPartArray::SetPalette`, `PalShift::MakeNewSurface` and
`ClientCharGenState::ClientCharGenState` — pair with exactly one release each,
and nothing calls `copyRef` on a fresh palette, so the increment is genuinely
unpaired.

Each leaked palette strands **8,192 bytes** of colour data plus a 72-byte object,
and `CPartArray::SetPalette` runs on essentially every object appearance load.

**⚠ Do not fix only the increment.** `Palette::releasePalette` calls the scalar
deleting destructor **twice** on the same object (`0x0053E00C` and `0x0053E015`),
where `DBObj::Release` (`0x00415160`) — the house idiom — calls it once. The two
bugs currently cancel: because the refcount never reaches zero, the double free
is never reached. Removing the increment alone makes it reachable on the
dominant path.

**Fix — three sites, 15 bytes:**

| File offset | VA | Original | Patched |
|---|---|---|---|
| `0x0013E29E` | `0x0053E29E` | `FF 40 24` | `90 90 90` |
| `0x0013E43C` | `0x0053E43C` | `FF 46 24` | `90 90 90` |
| `0x0013E015` | `0x0053E015` | `8B 16 6A 01 8B CE FF 52 18` | `90` ×9 |

**⚠ This fix does not cover a second double-delete site.** The NOP above kills
the double-delete only in `releasePalette`'s **object-cache branch**. Its **first
branch — the global-palette path (`ds:0x845748`)** — has the same defect, and by
the same mechanism:

```
53dfb9:  mov  ecx, ds:0x845748      ; the global palette
53dfbf:  cmp  esi, ecx              ; is the argument THE global palette?
53dfc1:  jne  0x53e000              ;   no  -> object-cache branch
53dfc3:  mov  esi,[ecx+0x24]        ;   yes -> refcount
53dfc9:  dec  esi
53dfd0:  jne  0x53dffe              ; not zero -> return
53dfd2:  mov  eax,[ecx]             ; FIRST delete of the global palette
53dfd6:  call DWORD PTR [eax+0x18]
53dfd9:  mov  ecx, ds:0x845748      ; reload -- STILL the same, now-freed pointer
53dfe1:  je   0x53dfea              ; non-null, so falls through
53dfe3:  mov  edx,[ecx]             ; SECOND delete: vtable read from freed memory
53dfe7:  call DWORD PTR [edx+0x18]
53dfea:  mov  DWORD PTR ds:0x845748, 0   ; only cleared AFTER both deletes
```

The branch is entered only when the argument *is* the global palette, so both
calls land on the same object; the global is nulled at `0x0053DFEA`, one
instruction too late to stop the second call. Whether this site is reachable
depends on whether the global palette's refcount ever reaches zero, which is
untested here. If it can, this branch needs the same treatment as the
object-cache branch.

> **Why §1 below did not catch it.** That section argues that in this cache
> design "a Get without a Release pins a DID, it does not allocate", so refcount
> leaks are bounded by the number of distinct DIDs. That is correct for cached
> `DBObj`s fetched by DataID, and it is why the icon audit legitimately came back
> clean. It does **not** hold for a factory method that calls `operator new` on
> every invocation, which is what `makeModifiedPalette` is. `Palette` was never
> examined, and the structural argument would not have flagged it if it had been.
>
> It also means the original hypothesis was **closer than §0 gives it credit
> for**: item-appearance data really does leak, and really is worsened by
> looting, because looting brings new items into view and each one triggers
> `SetPalette`. The specific claim about `IconData` refcounting was still wrong,
> and that finding stands.

Credit: the defect was reported at
`github.com/eriknihlen/ac-eor-palette-leak-fix` against the 2015 build. It is
verified here independently, and it is present in **this** build too — both
overloads are instruction-identical (differing only in relocated operands — 11
operand bytes of absolute data addresses / call displacements) between 11.4186
and 11.6096. See
`../../2015-10 11.6096/docs/12-memory-leak-2015.md` §0b for the full analysis.

---

## 1. How item icons actually work

Worth correcting the mental model first, because "icon files not freed" points
at the wrong layer.

An item icon is **not** simply a DAT resource held by a widget. It is composited
at runtime:

```
PublicWeenieDesc._iconID / _iconOverlayID / _iconUnderlayID   (DAT, type 12)
        │
        ▼  ACCWeenieObject::GetIconData (acclient.c:438653)
   IconData  ──── lives in the global ACCWeenieObject::iconDataTable
        │         (LongHash, 200 buckets, buckets at dword_8206C8)
        ▼  IconData::RenderIcons (acclient.c:437901)
   Gets 5 DAT surfaces (background, effect, underlay, icon, overlay)
   Composites them into TWO fresh 32×32 RenderSurfaces
   Releases all 5 DAT refs           ← this is why the DAT side stays clean
        │
        ▼
   m_pIcon, m_pDragIcon  (Graphic*, owning a RenderSurface each)
        │
        ▼  UIElement_UIItem::UIItem_SetIcon (acclient.c:272186)
   copy-constructed Graphic (AddRef) → UIRegion::SetImage
```

Two consequences:

- **The DAT icon resources are held only transiently**, for the duration of one
  composite. They churn through the type-12 freelist and are correctly released
  at acclient.c:438044–438052.
- **The persistent memory is the composited pair**, roughly 8 KB of pixels per
  object, owned by an `IconData` whose lifetime is tied to the
  `ACCWeenieObject` — *if* the correct teardown path runs.

### The DAT-side freelist is properly bounded

`DB_TYPE_RENDERSURFACE` (type 12, DIDs `0x06000000`–`0x07FFFFFF`) is registered
at acclient.c:92336–92391 with `m_nIdealSize = 100`, `m_nMaxSize = 400`,
`m_bRecycle = 0`, `m_bShrink = 1`. That is the largest budget of any type but is
finite, and identical to SurfaceTexture.

Icons are also precisely the RenderSurfaces that *are* freelisted:
`RenderSurface::Serialize` (acclient.c:128500–128502) sets
`m_AllowedInFreeList = (m_dataCategory == 6 || m_dataCategory == 10)`, and
category 6 is the UI/icon category (`SelectSurfaceFormat`,
acclient.c:127916–127919). 3D textures are *not* freelisted and are destroyed
immediately on last release.

`FreelistAdd` hard-caps at `m_nMaxSize` (acclient.c:83181–83208); `UseTime`
trims toward ideal for objects idle over 30 s (83131–83148); `DestroyObj`
removes from `m_ObjTable` before deleting (83309–83330) so the hash does not
accumulate corpses; and `DBCache::UseTime` (80049–80070) services every cache
each tick.

**Conclusion: the DAT icon cache is sound.** A complete audit of every type-12
acquisition found 17 sites, all with matching releases on all exit paths.

### The property that reframes everything below

A separate audit of the cache protocol established a fact that changes how any
refcount bug in this client should be read:

> **A Get-without-Release pins a DID; it does not allocate.**

Repeated `Get`s of the same DID return the *same* cached object with
`++m_numLinks`. So the memory lost to a refcount leak is bounded by the number
of **distinct DIDs** leaked times the object size — *not* by how often the
leaking path executes. A missing release on a per-frame path costs the same as
one on a once-per-session path, provided both touch the same DID.

This is why §5's six confirmed Get/Release asymmetries — including one that runs
every frame — together account for well under 60 objects, and why none of them
is a candidate for the reported symptom.

### Allocation cannot outpace eviction

The freelist cap is enforced **synchronously at insertion**, not by the periodic
trim (`FreelistAdd`, acclient.c:83194–83200):

```c
v5 = m_nFree + 1;  m_nFree = v5;
if ( v5 > m_freelistDef.m_nMaxSize ) { v6 = FreelistRemoveOldest(); DestroyObj(v6); }
```

So the freelist can never exceed `m_nMaxSize` however fast objects are released.
`DBOCache::UseTime`'s one-object-per-tick eviction is only the *idle shrink* from
max down to ideal — the 30-second gate delays shrinking but can never permit
growth. Across all 50 registered types in the base `MasterDBMap` the worst case is
Σ`m_nMaxSize` = **3731** payload-freed shells, on the order of hundreds of KB (a
further 15 types in `gmMasterDBMap` bring the totals to 65 types / 3956). `DBCache::UseTime`
(80049–80071) services **every** cache each tick, not a subset.

Freelisted objects are also emptied shells: `FreeObject` (83049) calls the
object's virtual `Destroy()` — which frees the payload (e.g. `RenderSurface` at
128351 frees `sourceBits` and `m_pSurfaceBits`) — *before* freelisting.

And objects that are **not** freelist-eligible are deleted immediately rather
than floating: `FreeObject`'s `else` branch goes straight to `DestroyObj`
(83049–83067). The only site in the entire binary that clears
`m_AllowedInFreeList` is the `RenderSurface::Serialize` line quoted above, so
world textures are freed eagerly — the opposite of what the hypothesis predicts.

---

## 2. Primary leak — `null_weenie_object_table` is unreapable

**This is a real bug, verified by direct read.**

`CObjectMaint::DeleteObject(unsigned int)` (acclient.c:309939) handles the two
halves of an object asymmetrically.

**The physics half** (309949–309985) searches `object_table`, and **falls back**
to `null_object_table` at 309966. Either way it deletes.

**The weenie half** (309986–310007) searches `weenie_object_table` **only**. On a
miss it jumps to `LABEL_16` and returns 0:

```c
v4 = weenie_object_table.buckets[ ... ];
if ( !v4 ) goto LABEL_16;              // 309987 — no fallback to null table
while ( object_id != v4->id ) { v4 = v4->hash_next; if (!v4) goto LABEL_16; }
if ( v4 ) {
    v4->vfptr[1].__vecDelDtor(v4);                        // ObjectBeingDeleted
    HashBase::remove(&weenie_object_table, v4->id);
    HashBase::remove(&null_weenie_object_table, v4->id);  // 309999 — INSIDE the
    v4->vfptr->__vecDelDtor(v4, 1u);                      //   success branch
}
```

The `null_weenie_object_table` removal at 309999 sits inside `if (v4)`, so it
only ever runs for objects that were found in `weenie_object_table`.

**A weenie that exists only in `null_weenie_object_table` can never be found,
never destroyed, never unlinked.** It is a copy-paste asymmetry between the two
halves of one function.

### What populates it

`CObjectMaint::GetNullWeenieObject` (acclient.c:310720), inserting at
310754–310756. Reached from `QueueBlobForWeenieObject` (310864, 310876), which is
called from:

- `UIQueueManager::ProcessEphemeralNetBlob` (acclient.c:395421)
- `UIQueueManager::HandleOrderingForBlob` (acclient.c:395530)

Both are the **defer path**: a server game-event arrives naming an object the
client does not yet have, so a placeholder weenie is parked and the message
queued against it. Every inventory opcode qualifies — `0x22`/`0x23`/`0x24`
move/wield/remove, `0x196` ContentProfile, `0x197` UpdateStackSize, `0x19A`
ServerSaysMoveItem.

**Looting is precisely the workload that generates these in bulk.**

### Why nothing collects it

Every reference to `null_weenie_object_table` in the binary:

| Line | What it does |
|---|---|
| 309999 | remove — **unreachable for null-only entries** (inside the success branch) |
| 310330 | read, in the `UseTime` re-request loop |
| 310597, 310645 | bulk iterate / `destroy_contents` — world teardown only |
| 310730, 310754–310756 | `GetNullWeenieObject` lookup and insert |
| 310809–310812 | destructor |
| 391926 | remove — the **promotion** path when `0xF745` CreateObject finally arrives |

So there are only two escapes: the object's `CreateObject` eventually arrives
(`ACCObjectMaint::CreateObject`, acclient.c:391922–391927), or the world is torn
down. **Anything whose `0xF745` never comes survives for the rest of the world
session.**

`GetNullWeenieObject` does call `AddObjectToBeDestroyed` (310757), but when the
25-second timer fires, `DeleteObject` does nothing *and* the
`destruction_object_table` entry is consumed at 310271 — it never retries.

**Secondary cost:** `CObjectMaint::UseTime` re-sends `Proto_UI::SendForceObjdesc`
for each stranded id every 20 seconds, forever (acclient.c:310318–310328,
310355–310365). So each leaked entry also buys permanent, growing network
chatter — which is independently observable and makes a good confirmation test
(§6).

**Cost per entry:** ~336 B for the weenie, plus its parked `NetBlob` references,
plus its `ACWTimeStamper` (128 B), plus an `IconData` (~8 KB) if an icon was ever
drawn for it.

---

## 3. Secondary leak — `IconData` stranded on bulk teardown

**Also verified by direct read**, and found independently by two separate audits.

`IconData` is removed from `iconDataTable` in exactly one place:
`ACCWeenieObject::ObjectBeingDeleted` (acclient.c:438948), unlink loop at
438999–439026. **`~ACCWeenieObject` (437260) never touches it** — confirmed by
inspection of the destructor body.

`ObjectBeingDeleted` is vtable slot 1. Compare the two teardown paths:

```c
// CObjectMaint::DeleteObject — CORRECT (309997-310000)
v4->vfptr[1].__vecDelDtor(v4);        // slot 1: ObjectBeingDeleted -> frees IconData
...removes from both tables...
v4->vfptr->__vecDelDtor(v4, 1u);      // slot 0: destructor

// CObjectMaint::DestroyObjects — BROKEN (LABEL_61, ~310619)
v20->vfptr->__vecDelDtor(v20, 1u);    // slot 0 ONLY — no slot 1
```

`DestroyObjects` (acclient.c:310383) is the bulk table flush. It unlinks the
weenie from the hash inline (310596–310618) and then calls **only the
destructor**. Every live `IconData` — two `Graphic`s and two 32×32
`RenderSurface`s, roughly 8 KB of pixels plus a D3D texture each — is stranded
permanently in `iconDataTable`. The object's `ACWTimeStamper` (freed only at
439029) leaks with it.

### Trigger

`CPlayerSystem::LogOnCharacter` (acclient.c:397920) →
`SmartBox::Reset(clear_objects = 1)` (144968) → `DestroyObjects` (310383).

Also reached from `SmartBox::~SmartBox` (145621),
`gmSmartBoxUI::~gmSmartBoxUI` (261778), `~CObjectMaint` (310781).

**In practice: log out to character select and log back in without quitting the
client.** Every object known at that moment — inventory, corpses, ground items,
NPCs, other players — leaks its icon pixels. Several MB per relog cycle on a busy
scene.

It does **not** fire on portalling, zoning, or looting. Nothing purges the table
at process exit either; the `atexit` handler (908214–908220) frees only the
bucket array.

**Possible second-order symptom worth testing:** object IDs are the hash key, and
`GetIconData` (438676–438690) only inserts when no entry is found. A stranded
entry whose ID collides with a new object after relogging would return a **stale
icon**. If players report wrong item icons after relogging, this is the cause.

---

## 4. Structural amplifier — system RAM is never reclaimable

Not a leak, but it converts every other defect from transient to permanent, and
it is worth knowing independently.

`ImgTex::CreateD3DTexture` (acclient.c:366008) creates two textures per image:

- `m_pSystemMemTexture` — `D3DPOOL_SYSTEMMEM`, holding the **full mip chain in
  system RAM**, explicitly marked `SetResourceIsThrashable(…, 0)` at
  acclient.c:366145 with `m_AllowManagement = 0`.
- `m_pRenderTexture` — `D3DPOOL_DEFAULT` (VRAM), marked thrashable at 365482.

`UISurface::CreateSurface` (124892) does the same, with a permanent system-RAM
texture per UI surface (call at 124970–124976).

**Every eviction path keys on `m_bIsThrashable`,** which defaults to 0 in the
`GraphicsResource` constructor (131482) and is set to 1 at only four sites — all
`D3DPOOL_DEFAULT` VRAM objects (136532, 365482, 687250, 687549). Both purge paths
require the flag (131206, 131609).

**Therefore `PurgeOldGraphicsResources` cannot free a single byte of system
RAM.** It is a VRAM-only mechanism. Additionally, `PurgeResource` never destroys
anything or removes it from `s_Resources` (131211–131214) — it releases the
D3D-side handle and sets `m_bIsLost`. The C++ object and its system-memory copy
survive.

And on a modern machine it never runs at all.
`SceneTool::PurgeOldGraphicsResources` (123095) calls
`PurgeOldResources(120.0)` only when `IsAvailableVideoMemoryLow` (457974)
returns true:

```c
avail = GetAvailableTextureMem();
if (m_TotalVideoMemoryInBytes >= 0xC00000 && avail >= 0x1800000)
        return avail < (m_TotalVideoMemoryInBytes >> 2);
else    return true;
```

`m_TotalVideoMemoryInBytes` is `GetAvailableTextureMem()` sampled once at device
creation (460019). On a card with plenty of VRAM, current-available stays above a
quarter of startup-available, so this returns **false** and the purge never
executes.

System-RAM texture footprint is released only by destroying the owning `ImgTex` /
`UISurface` / `CSurface` — i.e. only by refcount reaching zero. Which is exactly
what §3 prevents.

---

## 5. Minor and conditional findings

**`object_inventory_table` — conditional orphan.** One add
(`ViewObjectContents`, acclient.c:391986–392002), one remove
(`StopViewingObjectContents`, 392031). Neither `DeleteObject` variant nor
`ObjectBeingDeleted` touches it. If a corpse you had open is deleted by `0xF747`
without a preceding `0x52`, its `CObjectInventory` (76 B plus two `IDList`s and
`PackableList` nodes) is orphaned. In normal play
`Event_NoLongerViewingContents` (401668) elicits the `0x52`, so this is an
edge case rather than steady state. Whether the live server always sends `0x52`
before deleting is a protocol question the client cannot answer.

**Recycled UI widgets pin the last icon.** `ItemList_DeleteItem`
(acclient.c:274174) pushes a `UIElement_UIItem` into `m_listUIItemCache` via
`ListBox::RemoveItem` **without** calling `Clear_UIItem` or
`UIRegion::ClearImage`; `ItemList_Flush` (273978) clears the tooltip but not the
image. So a cached slot keeps the previous item's ~4 KB composited surface
resident until reassigned. **Bounded by grid slot count, not by items looted** —
it raises the floor, it does not grow.

**`ImgTex::temp_buffer_table`** (acclient.c:45328) — a (pixel format → W×H →
`ImgTex`) cache with **no removal code anywhere**; entries are pinned at
refcount 1 forever. Bounded in practice by the number of distinct dimension
tuples the client requests, so a fixed high-water cost rather than a runtime leak
— but it is genuinely never evicted.

**`lost_cell_table`** — `GetLostCell` allocates a `CLostCell` (309712); the only
removal is `InitObjCell` (309759–309785), which fires only when that specific
cell actually loads. `RemoveFromLostCell` (309546) empties a cell but never
deletes it. Small, session-lifetime accumulation.

### Confirmed Get/Release asymmetries — all bounded, none symptom-relevant

Six exist. Per the pin-not-allocate property (§1) each costs a fixed handful of
objects regardless of execution frequency.

| # | Site | Leaks | Runs |
|---|---|---|---|
| 1 | `~VividTargetIndicator` (acclient.c:289719) frees the array at 289735 but never releases the 12 surfaces Got at 290051 | 12 UI RenderSurfaces | per `gmSmartBoxUI` lifecycle |
| 2 | `gmCGAppearancePage::SetSelection` (186939) — 8 Gets (187056–187210), tail at 187291–187293 releases none | PalSets | every char-gen body-part click |
| 3 | `gmBarberUI::SetSelection` (269647) — same code clone, Gets at 269739–269804 | PalSets (same pool) | every barber selection |
| 4 | `MediaMachine::Update_Sound` (162256) — Gets, plays, returns without release; `PlaySoundFromCenter` (383569) does not take ownership | CSoundTable | cutscene/media only |
| 5 | `CharGenState` ctor (498002/498004) — `attribute2ndTable` never released; the dtor releases `skillTable` (496471) and `charGenData` (496507) but not this | 1 table | once per char-gen |
| 6 | `ClientCombatSystem::PlayerInReadyPosition` (408485) — missing release at 408540–408545; correct release exists at 408546 on the other branch | CombatManeuverTable | **per frame while charging an attack** |

Callers hitting #6 with `true`: `AttemptStartBuildingAttack` (408606),
`ExecuteAttack` (408642), `UseTime` (409033). It is the highest-frequency leak in
the binary and still bounded to one table per weapon type wielded.

### A further candidate: `m_PendingGets` under sustained prefetch

This one is plausible and **could not be settled statically.**

`m_PendingGets` (the async duplicate-request dedupe hash) does not self-retire.
Entries are inserted by `HashAndEnqueue` (86743) and removed **only** by
`UnhashPendingGet` (86797), which is reached only from `ReleaseContext` (86841).
Entries survive both completion and failure. The `ReadyToUnhash` predicate
(`m_cRef == 2`, 84818) occupies request-vtable slot 2 and is **never called
anywhere in the binary** — good evidence a self-retiring path was removed.

Each outstanding get therefore holds a hash node, a ~100-byte request, and **one
pinned `DBObj` link** until its context is released. `DBCachePrefetchCallback`
funnels *all* prefetches into a single shared context (`PreFetch`, 80989),
released in `OnContextFinished` (80979) only when the whole context completes.

So during sustained landblock streaming — running across the world continuously —
that shared context may never reach zero, and `m_PendingGets` accumulates one
request plus one pinned DBObj per distinct prefetched DID. It should self-clear
at the first lull. Whether it actually drains in practice is a runtime-timing
question. (The related in-flight filter `m_hashRequestedIDs` *is* correctly
erased per request in `OnTopLevelRequestFinished` (81036), so that set is fine.)

There is also no timeout on net-sourced gets — no Cancel/Abort/Timeout API exists
in the `AsyncCache` family, and `OnAsyncGetFromOtherSourcesFailed` (85466) is
dead code. A dropped DDD reply hangs that get and its context indefinitely.

**One-shot leaks, not symptom-relevant:** `gmCGAppearancePage` char-gen drops
creation refs after `Graphic` AddRefs them (186490–186492, 186608–186613,
186633–186638); `VividTargetIndicator`'s constructor drops up to 12 Gets
(290051).

---

## 6. What is *not* leaking

Recorded because ruling these out is what makes the findings above credible.

| Container / path | Status |
|---|---|
| Type-12 DAT icon cache | **Sound** — 100/400 freelist, hard-capped at insertion |
| DBObj refcount protocol overall | **Sound** — single decrement choke point (`Release` 83517 → `FreeObject` 83049, one caller); no double-decrement; `DBObjGrabber` RAII correct |
| Network message handlers | **Clean** — no `Handle_*`/`Recv*` calls the Get family except `RecvNotice_FontSettingsChanged` (288145), which releases both |
| Per-frame render paths | **Clean** — `UpdateTexVelocity` (311272) releases at 311287; `gmCG3DView::Update` is 6 Gets / 6 releases |
| Object-creation paths | **Clean** — `set_description`, `LoadGfxObjArray`, `SetInfo`, `AddScript`, `SetSetupID`, `SetMotionTableID` all pair |
| All 17 icon-DID acquisitions | **Balanced** — matching release on every exit path |
| `ImgTex::texture_table` | **Sound** — a weak/intern cache; stores bare pointers, each `ImgTex` removes its own entry in `~ImgTex` (367462–367470) |
| `PublicWeenieDesc` strings | **Freed** — `~ACCWeenieObject` (437273) calls `~PublicWeenieDesc` (470774) |
| `IconData` on the *normal* delete path | **Freed** — `ObjectBeingDeleted` (438999–439026) |
| `UIElement_UIItem` cache | **Free-list, not a leak list** — 5 push sites, 1 pop, fully drained in `~UIElement_ItemList` (273896) |
| UI surfaces on window open/close | **Balanced** — full chain from `~UIElement` → `SetUIObject(0)` → `~UISurfaceObject` → `DestroySurface` (124760) |
| `Graphic` objects | **Owned outright, never shared**; `m_image` refcount balanced |
| `visible_object_table` | Rebuilt every second (309858, 309883) |
| `object_destruction_queue` | Self-draining; stale nodes discarded by the timestamp guard (310270) |
| `m_openedCorpses` | `SetCorpseOpened` (439059) matched by `SetCorpseDeleted` (439081) |
| Notice handlers | `~NoticeRegistrar` (121264) reached from `~ACCWeenieObject` (437267) |
| Drag clones | Temporary-flagged and delete-queued on both stop paths |
| Shortcut bar | Fixed 18-slot array; stale IDs, zero growth |
| `GraphicsResource::s_Resources` | Self-register / self-unregister, balanced |

---

## 7. How to confirm at runtime

Static analysis can prove these paths exist; it cannot measure how often they
fire. Three cheap experiments, in order of value:

**1. Test the null-weenie leak without looting.** Its signature is *network*, not
just memory: each stranded entry re-sends `SendForceObjdesc` every 20 seconds
forever. Sit in a busy area and watch outbound packet volume over an hour. A
slow, monotonic rise in a *steady* scene is close to conclusive — nothing else in
the client behaves that way. Compare a quiet area against a crowded one.

**2. Separate looting from relogging.** These are different defects with
different triggers, and conflating them will send a fix in the wrong direction.
- Loot heavily for an hour without relogging → tests §2.
- Relog repeatedly in a busy area without looting → tests §3.

If memory climbs in the second test, the icon leak is real but has nothing to do
with looting.

**3. Look for stale icons after relogging.** If §3 is occurring, an object ID
collision will surface the previous occupant's icon. This is a zero-cost
observation that would confirm the mechanism outright.

---

## 8. If you intend to patch

Ranked by benefit-to-risk.

**Fix 1 — `CObjectMaint::DeleteObject`, acclient.c:309986.** Give the weenie half
the same `null_weenie_object_table` fallback the physics half already has at
309966. This is a two-line symmetry restoration and is the highest-value change.

**Fix 2 — `CObjectMaint::DestroyObjects`, ~acclient.c:310619.** Call vtable slot 1
(`ObjectBeingDeleted`) before slot 0, matching `DeleteObject` at 309997. Frees
both the stranded `IconData` and the `ACWTimeStamper`.

**Fix 3 — `ItemList_DeleteItem` (274174) and `ItemList_Flush` (273978).** Call
`UIRegion::ClearImage` when returning a widget to the cache. Recovers up to
(grid slots × 4 KB) of resident pixels; low risk, small benefit.

**Not recommended without care:** making `ImgTex`'s system-memory texture
thrashable (§4). It is marked non-thrashable *deliberately* — it is the restore
source after device loss. Changing it risks black textures on
alt-tab/resolution-change rather than fixing anything.

---

## 8b. Delivering the fixes against a shipped binary

**Everything in this section was verified against the actual `acclient.exe`**
(4,837,376 bytes, MD5 `2e30cd620b26f9787b4e6a6257a9e581`, linked 2013-09-06,
PDB GUID `9E847E2F-777C-4BD9-886C22256BB87F32` age 1, matching
`d:\ac1_sep13\output\bin\GAME\WIN32\retail\acclient.pdb`). Byte-level
disassembly, not inference.

### PE facts that matter for patching

| Property | Value | Consequence |
|---|---|---|
| ImageBase | `0x00400000` | as assumed |
| **DYNAMICBASE** | **clear** | **no ASLR — absolute addresses in patch code are safe, no reloc entries needed** |
| NX_COMPAT | clear | DEP not requested |
| RELOCS_STRIPPED | clear | `.reloc` present but unused for ASLR |
| CheckSum | `0x0049D162` | non-zero; Windows only enforces it for drivers/services, but recompute for tidiness |
| Section mapping | **file offset == RVA for `.text`, `.rdata`, `.data`** | `.text` RVA 0x1000 → raw 0x1000, `.rdata` 0x392000 → 0x392000, `.data` 0x40A000 → 0x40A000. **For those three, file offset = VA − 0x400000**, so locating a patch site is trivial arithmetic. It does **not** hold beyond them: `.data` has a large BSS tail (raw size 0x2D000 against virtual size 0xFB7D4), so `.data1`, `.rsrc` and `.reloc` are shifted by −847,872 (−0xCF000) relative to their RVAs — use the section table for those. Every patch site in this document is in `.text`. |

### The vtable question is resolved — and the naive answer is wrong

`ACCWeenieObject` has **two** vtables, and slot 1 means completely different
things in each:

Ground truth is `~ACCWeenieObject` (`0x0058C930`), which writes both vptrs
explicitly:

```asm
58c93c: lea  edi,[esi+0xC]
58c93f: mov  DWORD PTR [esi],0x7E3EA0     ; vptr at object+0
58c945: mov  DWORD PTR [edi],0x7E3E88     ; vptr at object+0xC
```

| Sub-object | Vtable | Slot 0 | Slot 1 |
|---|---|---|---|
| **`ACCWeenieObject` at `object+0`** | `0x007E3EA0` | `'scalar deleting destructor'` (0x0058CC20) | **`ACCWeenieObject::ObjectBeingDeleted`** (0x0058E4D0) |
| `NoticeRegistrar` at `object+0xC` | `0x007E3E88` | `'vector deleting destructor'` (0x0058C8F0) | **`NoticeRegistrar::RegisterNoticeHandler`** (0x0043C870) |

The hash tables store the **complete-object pointer** (`object+0`), so
`CObjectMaint::DeleteObject`'s `call [edx+4]` correctly reaches
`ObjectBeingDeleted`. **A patch author who looks up "ACCWeenieObject's vtable",
lands on the `NoticeRegistrar` table at 0x7E3E88, and calls slot 1 would invoke
`RegisterNoticeHandler` on every object during teardown.**

> An earlier draft of this table labelled `0x007E3E88` "primary" and
> `0x007E3EA0` "secondary". That is inverted — `0x007E3EA0` is the vptr at
> offset 0. The warning above is unaffected. Independent confirmation: a search
> of the whole image finds the address `0x0058E4D0` exactly **once**, at
> `0x007E3EA4`, which pins both the vtable and the slot index.

Call `0x0058E4D0` directly and the ambiguity disappears.

### The bug, at instruction level

`CObjectMaint::DeleteObject(unsigned int)` @ `0x005084D0`, weenie half:

```asm
508578: mov  esi,[eax+edx*4]      ; weenie_object_table bucket
50857b: test esi,esi
50857d: je   50858c               ; <-- MISS goes straight to the exit
508580: cmp  ebx,[esi+8]          ; chain walk on id
508583: je   508596
508585: mov  esi,[esi+4]
508588: test esi,esi
50858a: jne  508580
50858c: pop edi / pop esi / pop ebp
50858f: xor  eax,eax              ; <-- return 0. NO null-table fallback.
508591: pop ebx / pop ecx
508593: ret  4

508596: test esi,esi
508598: je   50858c
50859a: mov  edx,[esi]
50859c: mov  ecx,esi
50859e: call [edx+4]              ; slot 1 = ObjectBeingDeleted
5085a1: mov  eax,[esi+8]
5085a5: mov  ecx,ebp
5085a7: call 507AC0               ; HashBase::remove  (weenie_object_table)
5085ac: mov  ecx,[esi+8]
5085b0: lea  ecx,[edi+0xCC]       ; null_weenie_object_table
5085b6: call 507AC0               ; HashBase::remove
5085bb: mov  edx,[esi]
5085bd: push 1
5085c1: call [edx]                ; slot 0 = scalar deleting destructor
```

The `je 50858c` at `0x0050857D` is the defect: a weenie present only in the null
table can never be reached.

**Concrete data a patch needs**, read from the binary:

| Item | Value |
|---|---|
| `null_weenie_object_table` | `CObjectMaint + 0xCC` |
| `object_table` | `CObjectMaint + 0x84` (mask +0x88, key_shift +0x8C, buckets +0x90) |
| Other tables (from `DestroyObjects` epilogue) | `+0x9C`, `+0xCC`, `+0x1CC` |
| `HashBase<unsigned long>::remove` | `0x00507AC0` |
| `LongNIValHash::destroy_contents` | `0x00507F10` |
| `ACCWeenieObject::ObjectBeingDeleted` | `0x0058E4D0` |

### Fix 2's premise also verified

`CObjectMaint::DestroyObjects` @ `0x00508C30` (829 B) contains exactly **two**
indirect vtable calls — `call [edx]` at `0x00508DE9` and `call [eax]` at
`0x00508EE2`. Both are slot 0. **There is no `call [reg+4]` anywhere in the
function**, confirming at byte level that `ObjectBeingDeleted` is never invoked
during the bulk sweep.

### Code caves — corrected

An xref scan across `.text`, `.rdata`, `.data` and `.data1` changes the earlier
recommendation. "Dead" is not the same as "unreferenced":

| Candidate | VA | Size | Refs | Safe as cave? |
|---|---|---|---|---|
| **`DwExceptionFilter`** | **0x006B5820** | **1292 B** | 1 `.text` absolute (a function pointer that is never registered), 0 calls | **YES — best choice** |
| `SetRegistryKeysForWatson` | 0x006B56E0 | 189 B | 1 direct call, from Watson code that never runs | probably, but reachable-in-principle |
| `TurbineDwExceptionFilter::TurnOnDwExceptionHandler::BuildListOfFilesToUpload` | 0x006B57B0 | 107 B | 1 direct call, same | probably |
| `AddDllToDumpCapture` | 0x006B5680 | 86 B | 1 direct call, from `TurbineDwExceptionFilter::AddDllToDumpCapture` (`0x006B57A0`) — which is itself reached from live code, see next row | **NO — transitively live** |
| `AddDllToDumpCapture` | 0x006B57A0 | 16 B | 1 direct call, from **`AC1ClientChatManager::Init` (0x00556A51) — LIVE startup code** | **NO — called from live chat-init, do not overwrite** |
| `TurnOnDwExceptionHandler` | 0x006B5DB0 | 144 B | 1 direct call **that executes at startup** | **NO — do not touch** |
| `QTIsaac::srand` | 0x0065F720 | 176 B | **1 `.rdata` ref** — it is a live vtable slot | **NO** |
| `ReadyToUnhash` | 0x00417E90 | 12 B | **5 `.rdata` refs** — vtable slots | **NO** |
| `OnAsyncGetFromOtherSourcesFailed` | 0x00418770 | 57 B | **4 `.rdata` refs** — vtable slots | **NO** |

> **Both `AddDllToDumpCapture` functions are live, despite the
> `TurbineDwExceptionFilter` namespace.** `0x006B57A0` is a 16-byte thunk
> (`mov eax,[esp+4]; push eax; mov ecx,0x8FAA38; call 0x006B5680; ret`) called
> from `AC1ClientChatManager::Init`, so the 86-byte body at `0x006B5680` is
> reachable from client startup too. An earlier draft listed both as
> probably-dead Watson code; that is wrong, and overwriting either would corrupt
> chat initialisation. Neither is a usable cave.

An earlier draft of this section suggested the whole ~2 KB Watson block was fair
game. That was wrong: `TurnOnDwExceptionHandler` really does run at startup — it
is the constructor call that passes `fInstallNow = 0`. **Use
`DwExceptionFilter` (0x006B5820, 1292 bytes, verified real code with no `0xCC`
padding).** That is ample for all three detours.

### Recommended delivery: a DLL, not a modified EXE

The client already loads arbitrary third-party code by design.
`APIManager::Init` (acclient.c:393464) reads
`HKLM\SOFTWARE\Microsoft\Microsoft Games\Asheron's Call\1.00\ACPlugin`,
`LoadLibrary`s it, and calls the exported `CreateACPlugin` — the Decal injection
point.

A DLL installing runtime detours beats editing the EXE on every axis: no PE
surgery, no checksum, no cave needed at all, trivially reversible by clearing one
registry value, and iterable without redistributing a client. Since
DYNAMICBASE is clear, addresses are stable, so the DLL can hardcode them — though
computing from the module base costs nothing and is more robust.

### Implement all three as *additive* hooks

None needs the original logic restructured:

**Fix 1** — detour `0x005084D0`. Call the original; **if it returns 0**, do the
`null_weenie_object_table` (`this+0xCC`) lookup yourself, call `0x0058E4D0`, then
`HashBase::remove` (`0x00507AC0`) and the slot-0 destructor.

**Fix 2** — detour `0x00508C30`. **Before** the original, walk
`weenie_object_table` and call `0x0058E4D0` on each entry. The original's
slot-0-only sweep then does no harm.

**Fix 3** — detour `ItemList_DeleteItem` (`0x004E3FE0`) / `ItemList_Flush`
(`0x004E3D60`) and call `UIRegion::ClearImage` (`0x0069F7E0`) on the widget
before delegating.

### One honest caveat about visibility

The client answers server `QueryPluginList` / `QueryPlugin` admin messages with
the loaded plugin's name, author, e-mail and webpage (`ClientAdminSystem`,
acclient.c:719765/719792). A DLL registered as an `ACPlugin` is visible to the
server by design. Not an obstacle for a client you operate; worth knowing before
deploying against a server you do not.

---

## 9. Provenance

**Verified personally by direct read**, not accepted from a single source:

- The `DeleteObject` asymmetry at acclient.c:309986–310007, including that the
  `null_weenie_object_table` removal at 309999 is inside the success branch.
- That the only removals from `null_weenie_object_table` are 309999 (unreachable
  for null-only entries), 391926 (promotion), and 310645 (world teardown) —
  established by enumerating every reference to the symbol.
- That `GetNullWeenieObject` is fed by `QueueBlobForWeenieObject` from the two
  ordering-defer sites at 395421 and 395530.
- The `DestroyObjects` slot-0-only call at LABEL_61 versus `DeleteObject`'s
  slot-1-then-slot-0 at 309997–310000.
- That `~ACCWeenieObject` (437260–437300) contains no reference to icon or
  stamper state.
- `m_bIsThrashable` defaults to 0 (131482), is set at only four sites, and is
  required by both purge paths (131206, 131609).

**Corroborated independently by two separate audits:** the `DestroyObjects`
slot-1 omission.

**Reported but not personally re-read:** the type-12 freelist values at
92336–92391; the 17-site icon acquisition/release table; the `texture_table`
weak-cache mechanics; the UI surface teardown chain.

**Previously inferred, now RESOLVED against the binary:** that vtable slot 1 is
`ObjectBeingDeleted`. Dumping both `ACCWeenieObject` vtables from
`acclient.exe` confirms it — but only for the vtable at **object+0**
(`0x007E3EA0`), which is the complete-object pointer the hash tables store. The
`NoticeRegistrar` sub-object table at **object+0xC** (`0x007E3E88`) has
`NoticeRegistrar::RegisterNoticeHandler` in slot 1. The inference was correct;
the reasoning behind it was incomplete, and the distinction is patch-critical.
See §8b.

**A separate lead, not a leak — possible over-release.** `CObjCell::Get`
(acclient.c:346730) returns an AddRef'd `CEnvCell` for `cell_id >= 0x100`, but
delegates to `CLandCell::Get` (354916) → `LScape::get_landcell` (307512), which
returns a **borrowed interior pointer** into a `CLandBlock`'s array that was never
AddRef'd. The sole caller (`CellManager`, 146696) unconditionally releases
`curr_cell` at 146683. If a `CLandCell` reaches `DBObj::Release` with
`m_pMaintainer == 0` (81441) it decrements a count it never incremented. That is a
crash/corruption risk rather than a leak, and it deserves its own targeted check.

**Open questions requiring runtime data or the server:**

- How often the server references an object whose `0xF745` never arrives. This
  determines the *rate* of the primary leak; the analysis can only show it is
  unreapable.
- Whether the server always emits `0x52` before deleting a corpse being viewed
  (determines whether §5's `object_inventory_table` orphan occurs in practice).
- What `GetAvailableTextureMem()` returns on modern drivers, which decides
  whether `IsAvailableVideoMemoryLow` is merely rare or literally never true.
- Whether `m_dataCategory == 6` universally holds for item-icon DIDs. This is a
  property of the DAT records, not the binary.
- Whether the shared prefetch context drains during sustained exploration (§5).
  This is the one place worth instrumenting a live client.
