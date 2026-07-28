# The DAT Container Format, Resource Loading, and Caching

Target: acclient.exe 11.4186 (September 2013). Line references are into
`../acclient.c` and `../acclient.h` unless noted.

> **Revision note.** Written in a first pass, then verified line-by-line in a
> second pass with arithmetic checks on every struct size. The binary format
> claims all held up. Corrections were needed on several DID range upper bounds,
> the queue type (SPSC not MPSC), the dead recycle path, and the fact that the
> client actually uses `gmMasterDBMap` rather than `MasterDBMap`. See §12.

---

## 1. On-disk container format

A DAT file starts with `DiskHeaderBlock_t` (acclient.h:28252–28257):
`acVersionStr_[256]` at 0, `acTransactionRecord[64]` at `0x100`, and
`DiskFileInfo_t` at **`0x140`**. Total `256 + 64 + 80 = 400 = 0x190`, read and
written whole at file offset 0 in `DiskDev::Open_File` (acclient.c:653512,
653524).

`CLBlockAllocator::OpenDataFile` (acclient.c:651004) reads the 0x50-byte
`DiskFileInfo_t` from offset 320 (`0x140`) and rejects the file unless
`magic_ == 21570` (`0x5442`, "BT" little-endian), returning **−102**
(acclient.c:651035–651038).

`DiskFileInfo_t` (acclient.h:28231–28249), all offsets verified individually:

| Offset | Field | Notes |
|---|---|---|
| +0x00 | `magic_` | `0x5442` |
| +0x04 | `iBlockSize_` | includes the 4-byte link |
| +0x08 | `fileSize_` | |
| +0x0C | `data_set_lm` | `DATFILE_TYPE` (acclient.h:3116): 1 PORTAL, 2 CELL, 3 LOCAL |
| +0x10 | `data_subset_lm` | region or language ID |
| +0x14 / +0x18 / +0x1C | `firstFree_`, `finalFree_`, `iFreeBlocks_` | |
| +0x20 | `btreeRoot_` | |
| +0x24 / +0x28 | `young_lru_lm`, `old_lru_lm` | |
| +0x2C | `use_lru_fm` | a `bool` plus 3 pad |
| +0x30 | `master_map_id_m` | root of the enum→DID indirection (§4) |
| +0x34 / +0x38 | `eng_pack_vnum`, `game_pack_vnum` | |
| +0x3C | `id_vnum` | `DatIDStamp` = GUID(16) + uint(4) = 20 B |

The arithmetic closes exactly: `0x3C + 0x14 = 0x50`.

### Block chain

Every block's first dword is the offset of the next; payload is
`iBlockSize_ − 4` bytes. `CLBlockAllocator::Load_Data`
(acclient.c:650711–650776) walks the chain, saving and restoring the 4 clobbered
bytes at each hop (650745, 650755).

A next-pointer with **bit 31 set** marks a free block, and hitting one mid-read
aborts the read (acclient.c:650759–650763). `CreateDataFile`
(acclient.c:650903) pre-tags free blocks with `| 0x80000000`
(acclient.c:650985).

The data area starts at file offset **1024**, not 400 —
`firstFree_ = 1024`, `iFreeBlocks_ = (fileSize_ − 1024) / iBlockSize_`
(acclient.c:650945–650952).

`acVersionStr_` is decorative: `DiskDev::Open_File` writes
`"\nFile Header Structure Default Constructor v1.3\n"` plus
`acVersionStr_[255] = 0x1A` — a DOS EOF byte so `type` stops there — and nothing
ever reads it back (acclient.c:653484–653489).

### The transaction journal

`SaveTransaction` (acclient.c:650815) serializes a `DiskTransactInfo`, refuses if
it exceeds `0x40` bytes, and writes at file offset **256**. `ReadTransaction`
(650860) reads `0x40` from 256; `ClearTransaction` (650849) writes a `NO_TRANS`
record.

Journaled operations: `SplitNodeTrans` (649602), `InsertEntryTrans` (649627),
`MergeNodesTrans` (649780), `RotateEntryTrans` (649849). Recovery is
`BTree::RecoverTransaction` (649449) and is **redo-forward** — it re-executes the
journaled `*Exec` and then clears the record. Note types 8 and 9
(`LRU_EXPAND_TRANS`, `LRU_DELETE_TRANS`) fall through to `default` and return
−103.

---

## 2. The BTree directory

```c
struct BTEntry {                      // 24 bytes
  uint32 comp_:1, resv_:15, ver_:16;
  IDClass GID_;  int Offset_;  uint size_;  int date_;  int iter_;
};
struct BTNode {                       // 1716 bytes
  int NextNode_[62]; int NumEntries_; BTEntry Entry_[61];
};
```

Sizes check out: `62×4 + 4 + 61×24 = 248 + 4 + 1464 = 1716` (acclient.h:28579–
28584). The bitfield layout is independently corroborated by
`WorkerExecuteSaveRequest`, which does
`v4 = pSaveReq->Buf.m_iVersion << 16; entry = (BTEntry)v4;`
(acclient.c:654068–654074) — `ver_` really is bits 16–31 and `comp_` is bit 0.

This is an order-62 B-tree: 61 sorted entries and 62 children per node, with
`NextNode_[0] == 0` marking a leaf (`BTree::Search`, acclient.c:649569–649588).
The key is the raw 32-bit DID.

In memory the root is pinned plus a **100-slot node cache**. `BTMemNode` is a
20-byte header plus the node = **1736** bytes (acclient.h:28587–28595).
`LoadTree` (acclient.c:648665–648715) allocates `0x2A624` = 173,604 =
`4 (operator new[] count cookie) + 100 × 1736` (at 648684), writes the count 100
at **648687**, strides by 1736 at **648698**, and reads the root as `0x6B8` =
1720 = `4 (offset_m) + 1716` (at 648714).

`BTree::HasEntry` (648415) binary-searches within a node; `Search` (649569) and
`Lookup` (649939) descend via `FindNode`. Insertion is preemptive-split — the
body of `DescendToAdd` is at **acclient.c:649679** (13012 is only the
prototype). Deletion uses merge and rotate.

`ver_` becomes `Cache_Pack_t::m_iVersion` (`LoadDataEx`, acclient.c:647444).
`iter_` is the patch-iteration number, and the dat's whole iteration set is
stored in-band under the reserved DID **`0xFFFF0001`** (the constant
`stru_8333B8 = { 4294901761u }` at acclient.c:46578, referenced only by
`LoadIterationList` at 647540/647555 and `SaveIterationList` at 647622). That
record's version must be exactly 1.

### Compression

If `comp_` is set, the decompress call happens inside
**`DiskController::LoadDataEx`** (body at acclient.c:647426, dispatch at
647461–647468) — `DiskController::LoadData` (647412) is only a 10-line vtable
forwarder.

`DiskController::Decompress` (acclient.c:647367) is plain zlib `uncompress`
(called at 647393) with a 4-byte uncompressed-size prefix. The guard at
**647382** is `v4 >= 0x10` where `v4 = GetSize − 4` is the *record* length, so
the payload handed to zlib is `v4 − 4` bytes — i.e. record ≥ 0x10, payload ≥
0x0C. The write side, `AttemptToCompress` (acclient.c:647114), calls `compress2` with
level 9 at **647154** and stores the prefix at **647164**. Its guard is
`> 0x10` (strict), against the read side's `>= 0x10`.

**There is no encryption in the DAT *container* path.** `DiskDev::SyncRead`
(653420–653439) and `SyncWrite` (653442–653459) are raw `SetFilePointer` plus
`ReadFile`/`WriteFile`; `Load_Data`/`Store_Data` touch only the 4-byte link;
`Decompress`/`AttemptToCompress` are pure zlib. The binary's only cipher — ISAAC
keystream XOR, `CryptoSystem::EncryptData` at 630381 — is provably network-only.

**But obfuscation exists one layer up, on record *content*.**
`SpellFormula::Decrypt` (487851) subtractively de-obfuscates spell component IDs
with a key from name and description hashes (applied at 448932), and spell name,
description, and component-name strings are stored **nibble-swapped** (448856,
448899, 448912, 487046) — see `04-combat-magic.md` §3. Earlier drafts said "no
encryption anywhere," which the container-path search does not support.

---

## 3. The DID namespace

`CLCache::Init` (acclient.c:293386) opens `client_portal.dat` and grows a
four-slot array (acclient.c:293450): 0 portal, 1 local, 2 cell, 3 highres.
`SetRegion` builds `client_cell_<rid>.dat` (292059), `SetLanguageInternal` builds
`client_local_<lang>.dat` (292277–292285), and `LoadHighResDat` (293657) opens
`client_highres.dat`. `CLCache::GetDiskController` (292490) routes by slot.

`CThreadsafeDiskController` is `operator new(0x788)` = 1928 bytes, with the
`SharedCriticalSection` at **+1872 = 0x750** and a `CMostlyConsecutiveIntSet` at
+1908 (acclient.c:293522–293529) — so the `DiskController` really is 0x750 bytes.

The mapping lives in `MasterDBMap::DivineType_Internal` (acclient.c:89735), with
DB_TYPE constants at 39276–39325. The registration table is built by
**`MasterDBMap::InitDBTypeDef_Internal`** (89317 → 91986, first `add` at 92069) —
`MasterDBMap::Init` (89317) is only a 12-line trampoline.

| DID range | DB_TYPE | Name |
|---|---|---|
| `0x01000000`–`0x0100FFFF` | 6 | GfxObj |
| `0x02000000`–`0x0200FFFF` | 7 | Setup |
| `0x03000000`–`0x0300FFFF` | 8 | Animation |
| `0x04000000`–`0x0400FFFF` | 10 | Palette |
| `0x05000000`–`0x05FFFFFF` | 11 | SurfaceTexture |
| `0x06000000`–`0x07FFFFFF` | 12 | RenderSurface / ImgTex |
| `0x08000000`–`0x0800FFFF` | 13 | Surface |
| `0x09000000`–`0x0900FFFF` | 14 | MotionTable |
| `0x0A000000`–`0x0A00FFFF` | 15 | Wave |
| `0x0D000000`–`0x0D00FFFF` | 16 | Environment |
| `0x0F000000`–`0x0F00FFFF` | 24 | PalSet |
| `0x10000000`–`0x1000FFFF` | 25 | ClothingTable |
| `0x11000000`–`0x1100FFFF` | 26 | GfxObjDegradeInfo |
| `0x12000000`–`0x1200FFFF` | 27 | Scene |
| `0x13000000`–`0x1300FFFF` | 28 | Region |
| `0x14000000`–`0x1400FFFF` | 29 | Keymap (`CMasterInputMap`) |
| `0x19000000`–`0x19FFFFFF` | 67 | RenderMesh |
| `0x20000000`–`0x2000FFFF` | 34 | SoundTable |
| `0x21000000`–`0x21FFFFFF` | 35 | UILayout (`LayoutDesc`) |
| **`0x23000000`–`0x24FFFFFF`** | 37 | StringTable — **owns the 0x24 high byte too** |
| `0x26000000`–`0x2600FFFF` | 39 | ActionMap |
| `0x27000000`–`0x27FFFFFF` | 40 | DualDIDMapper |
| `0x31000000`–`0x3100FFFF` | 41 | String |
| `0x32000000`–`0x3200FFFF` | 42 | ParticleEmitter |
| `0x33000000`–`0x3300FFFF` | 43 | PhysicsScript |
| `0x34000000`–`0x3400FFFF` | 44 | PhysicsScriptTable |
| `0x39000000`–`0x39FFFFFF` | 45 | MasterProperty |
| `0x40000000`–`0x40000FFF` | 46 | Font |
| `0x40001000`–`0x40FFFFFF` | 47 | FontLocal |
| `0x41000000`–`0x41FFFFFF` | 48 | StringState |
| `0x78000000`–`0x7FFFFFFF` | 49 | DBProperties |
| `0x0E020000`–`0x0E02FFFF` | 23 | MonitoredProperties (registered `m_bIsClientType = 0` — server-only) |

Note the many `…00FFFF` upper bounds: the first pass listed several of these as
`…FFFFFF`, which is wrong.

**The table above is not exhaustive.** Six further client-visible ranges are
registered and were omitted by earlier drafts: `0x15……` → 30 RenderTexture,
`0x16……` → 31 RenderMaterial, `0x17……` → 32 MaterialModifier, `0x18……` → 33
MaterialInstance, **`0x22000000`–`0x22FFFFFF` → 36 EnumMapper**, and
**`0x25000000`–`0x25FFFFFF` → 38 DIDMapper**. The last two matter because §4's
entire indirection story runs through type 38.

Singletons: `0x0E000007` ChatPoseTable (17), `0x0E00000D` ObjectHierarchy (18),
`0x0E00001A` BadData (19), `0x0E00001E` TabooTable (20), `0x0E00001F`
File2IDTable (21), `0x0E000020` NameFilterTable (22).

Cell-dat forms are built, not parsed:
`(((y>>3) | 32*(x & ~7)) << 16) | 0xFFFF` for the LandBlock
(acclient.c:306919); `m_DID.id & 0xFFFFFFFE | 0xFFFE` for LandBlockInfo (348069,
352411); and `v17 = m_DID.id & 0xFFFF0100 | 0x100` plus an index for EnvCell
(348083–348088), with `QualifiedDataID` types 1, 2, and 3 respectively. Note that
`MasterDBMap::IsCellType` (acclient.c:89488) takes a **dbtype** and returns
`DBTypeDef::m_bIsCellType` — it has nothing to do with DID form.

---

## 4. The game layer: `gmMasterDBMap` and enum indirection

**The client actually installs `gmMasterDBMap`, not `MasterDBMap`.**
`gmCLCache::Init` (acclient.c:435258) swaps in `gmMasterDBMap::vftable` before
calling `CLCache::Init`.

`gmMasterDBMap::DivineType_Internal` (acclient.c:514291) resolves a *game* layer
of DB types numbered from `0x10000000` and only then tail-calls the engine
version (514365). Constants at acclient.c:42117–42131:

| DID | DB_TYPE | Name |
|---|---|---|
| `0x00000001`–`0x0000FFFF` | `0x10000001` | WEENIE_DEF |
| `0x0E000002` | `0x10000002` | CHAR_GEN |
| `0x0E000003` | `0x10000003` | ATTRIBUTE_2ND_TABLE |
| `0x0E000004` | `0x10000004` | SKILL_TABLE |
| `0x0E00000E` | `0x10000005` | SPELL_TABLE |
| `0x0E00000F` | `0x10000006` | SPELLCOMPONENT_TABLE |
| `0x0E000011` | `0x10000007` | W_TREASURE_SYSTEM |
| `0x0E000018` | `0x10000009` | XP_TABLE |
| `0x0E000019` | `0x10000008` | W_CRAFT_TABLE |
| `0x0E00001B` | `0x1000000A` | QUEST_DEF_DB |
| `0x0E00001C` | `0x1000000B` | GAME_EVENT_DB |
| `0x0E00001D` | `0x10000010` | CONTRACT_TABLE |
| `0x0E010000`–`0x0E01FFFF` | `0x1000000C` | QUALITY_FILTER |
| `0x30000000`–`0x3000FFFF` | `0x1000000D` | COMBAT_TABLE |
| `0x38000000`–`0x3800FFFF` | `0x1000000E` | MUTATE_FILTER |

`gmMasterDBMap` also has its **own** `InitDBTypeDef_Internal` at
acclient.c:514905, registering the 15 game types at 514938–515316. Earlier
drafts documented only `DivineType_Internal`, which would leave a reader
thinking game types have no `DBTypeDef` — no freelist budget, no
`m_bIsClientType`, no extension.

One ordering subtlety: `DBCache::Init` (79982) contains a *second*
`MasterDBMap::Init` site that would install a plain `MasterDBMap`. It is
harmless only because `CLCache::Init` reaches it at 293437, *after*
`gmCLCache::Init` has already set `sm_mmap`, so the `||` short-circuits.

### The two-level enum→DID indirection

`master_map_id_m` (+0x30 in the header) is the root. `CLCache::Init` reads it and
installs it with `DBCache::SetMasterMapDID` (acclient.c:293563, sink at 79532).

`DBCache::GetDIDFromEnum` (acclient.c:79580) then does: load `m_MasterMapID` as
type `0x26` (DID_MAPPER) → `EnumIDMap::EnumToDID(enum_group)` → load *that* DID as
`0x26` → `EnumIDMap::EnumToDID(enum_id)` → the real resource DID.

**This is why almost nothing in the client hardcodes DIDs.** Fonts are
`GetDIDByEnum(23, 9)` (acclient.c:155800), cursors `(1, 6)`, `MasterProperty`
`(15, 2)`, StringTables group 4, `StringState` `(1, 4)`.

`EnumMapper` (acclient.h:28129) maps enum value to case-insensitive name; only
`m_id_to_string_map` is on disk and the reverse map is rebuilt at load.
`m_base_emp_did` chains to a parent mapper that every lookup falls through to
(`GetString` 88051, `GetEnum` 88640).

`EnumIDMap` (acclient.h:47389, `Serialize` 82982) serializes four hash tables in
order — `m_EnumToID`, `m_EnumToName`, `m_EnumToIDInternal`,
`m_EnumToNameInternal` — the "Internal" pair being a second tier consulted on
miss. `DualEnumIDMap` adds no serialized state; `InitLoad` (82466) inverts
`m_EnumToID` into `m_IDToEnum` and reports
`"DataID 0x%08X used multiple times."` on collision. The reverse direction is
used by `HouseSystem::IsTradeNote` (486161) and
`SpellComponentTable::WCIDtoSCID` (487281).

`EnumeratedBitfield` (acclient.c:653537) maps **bit positions**, not masks.

---

## 5. Schema and index singletons

`DBFile2IDTable` (acclient.h:48027, `Serialize` 658197) is a bidirectional
filename ↔ DID registry bucketed per DB type. `TDBTypeEntry` holds the type name,
game and engine root paths, `HighestDIDAssigned`, and a `DID → TFileEntry` map;
`TFileEntry` carries path, filename, DID, dbtype, and `m_tFileWriteTime`. This is
**the asset-build index, shipped inside the dat.**

`MasterProperty` (acclient.h:45249, `Serialize` 101199) is the **global property
schema**: an embedded `EnumMapper` plus `HashTable<enum, BasePropertyDesc*>`.
`BasePropertyDesc` (acclient.h:30462) is a rich record — type, group, provider,
default/min/max, inheritance, propagation, caching type, `m_ePatchFlags`,
element-count bounds, help text, prediction timeout. It is fetched as a singleton
by `MasterPropertyGrabber` (97523) via `GetByEnum(15, 2, 45)`.

`DBPropertyCollection` (acclient.h:48289, `Serialize` 664553) is a serialized
property bag; the `.pmat` extension shows it is the material-property container.

---

## 6. Class factories and serialization

Each `DBOCache` (acclient.h:27724) is constructed with a `DBObj *(__cdecl *)()`
allocator and a dbtype, registered in a global hash keyed by dbtype
(`DBCache::GetDBOCache`, acclient.c:80241). Factories are trivial
`X::Allocator()` functions (acclient.c:290161–290522, 435118+).

Unpacking is the virtual `DBObj::Serialize(Archive&)`, invoked by
`AsyncCache::SerializeFromCachePack` (acclient.c:84377) over a plain **`Archive`**
(`&Archive::vftable` at 84388) wrapping a `SmartBuffer::MakeWindow(…, 4u)`.
`TransientArchive` is used by `Load`/`SaveIterationList` and `ReadTransaction`,
not here.

`Archive` (acclient.h:7952) is `{vfptr, m_flags, m_hrError, m_buffer,
m_currOffset, m_pcUserDataHash, m_pVersionStack}`; `TransientArchive`
(acclient.h:24459) adds nothing. Flag bit 0 means packing (`InitForPacking`
70505 sets it; `InitForUnpacking` 70528 clears bits 0 and 2), bit 2 means error —
every caller tests success as `~(m_flags >> 2) & 1`.

**Version tolerance is token-based, not field-count-based.**
`SerializeFromCachePack` calls `GetVersionRowForDBObjPackVersion(m_iVersion)`
(acclient.c:87589), which populates an `ArchiveVersionRow` with three FOURCC
tokens — `'Core'` = `2 − (v < 2)`, `'DObj'` = the record version straight from
`BTEntry::ver_`, and `'UIL '` = `(v >= 3)` — pushed onto an
`InArchiveVersionStack` (acclient.h:43846, 232 bytes, a hash-list of rows keyed
by `VersionHandle`).

A `Serialize` body then asks `Archive::GetVersionByToken` (acclient.c:69987)
which fields exist — for instance RenderMaterial gates on `'RMVT'`
(acclient.c:129851) and UI code on `'UIL '` (691996, 692624).
`SerializeFromCachePack` refuses outright if `m_iVersion == 0`.

---

## 7. The async pipeline

The chain is `AsyncCache` → `DBCache` → `ThreadedCache : DBCache, PortalThread` →
`CLCache` (acclient.h:28318, 28888, 29537, 29649).

`ThreadedCache` owns **two 1024-slot ring queues** (`numBuckets_ = 1024` at
acclient.c:654389 and 654399) plus a Win32 auto-reset event. The worker is a real
thread — `PortalThread::PortalThread` calls `CreateThread`
(acclient.c:627455, call at 627467).

**Correction:** `LFQueue<T>` (acclient.h:29525) is **single-producer /
single-consumer**, not MPSC. It uses plain `m_dwProducerBucketIndex` and
`m_dwConsumerBucketIndex` comparisons with **no CAS anywhere**
(acclient.c:654092–654272); overflow spills to a `List` under a
`SharedCriticalSection`.

**Issue.** `ThreadedCache::AsyncGetInternal` (acclient.c:654330) first tries
`GetIfInMemory`. On a miss, if the type can load from disk and the ID
`IsOnDisk`, the request is pushed to the job queue and the event signaled
(`PutOnWorkerThreadJobQueue`, 654291). Otherwise it falls back to the DDD network
fetch (`AsyncGetFromOtherSources`) or fails.

**Worker.** `ThreadedCache::Startup` (acclient.c:654256) loops: drain, execute,
push to the reply queue, `WaitForSignal(INFINITE)`.

`WorkerExecuteRequest` (acclient.c:653985) dispatches **three** ops, not one.
It makes three *virtual* calls — `Op==0 → vfptr[3].Release`, `Op==1 →
vfptr[4].AddRef`, `Op==2 → vfptr[4].QueryInterface` — so the mapping to
get / purge / save is an **inference from vtable-slot order**, consistent with
the function ordering `WorkerExecuteGetRequest` 654034,
`WorkerExecutePurgeRequest` **654047**, `WorkerExecuteSaveRequest` 654057, and
with CLCache's op-3 override. And
`CLCache::WorkerExecuteRequest` (290564) adds op 3, BeginDDD (290913). So while
object *construction* never happens off-thread, **saving does** — the first pass
understated this.

For gets, `WorkerExecuteGetRequest` (654034) only does `LoadData` into
`pReq->Buf`.

**Main-thread completion.** `ThreadedCache::UseTime` (acclient.c:654302) drains
the reply queue under `while (GetTickCount() - v2 < 0x19)` — a **25 ms budget**
(loop at **654312**). `AsyncCache::CallPendingCallbacks` (acclient.c:84428) has the
identical guard (loop at **84441**).

`AsyncCache::OnGetRequestFinished` (acclient.c:86237) allocates via `GetFreeObj`
or the factory, deserializes, and — if the object isn't fully loaded — asks for
its **sub-DataIDs** (`GetSubDataIDs`, `FilterSubDataIDs`) and issues child gets.
`nGetsRemaining` and `RequestsWaitingForMe` implement dependency fan-in, so a
Setup completes only after its GfxObjs and palettes arrive.

There is no priority field — ordering is FIFO. `AsyncGetImmediate` and
`BlockingGet` exist for synchronous needs (acclient.c:765, 788).

`CAsyncStateMachine` (acclient.h:35031) is a companion per-context state machine
used to script multi-step flows such as login
(`CClientsideLoginStateHandler`, acclient.h:35114).

---

## 8. Caching and eviction

`DBObj` (acclient.h:27570) carries `m_numLinks`, freelist links, `m_timeStamp`,
and `m_pMaintainer`. `GetIfUsing` returns only when `m_numLinks > 1`
(acclient.c:83485–83503).

`DBOCache::Release` (body at acclient.c:**83517**) decrements. `FreelistAdd`
(83171) gates on `object_p->m_AllowedInFreeList && this->m_fKeepFreeObjs`
(**83181**) — not on the link count, as the first pass implied.

`DBOCache::UseTime` (83131) destroys the oldest free object once the list exceeds
ideal size **and** `m_timeStamp + 30.0 < Timer::cur_time` — the 30-second idle
rule.

Freelist budgets, all verified:

| Type | Ideal / Max | At |
|---|---|---|
| GfxObj | 100 / 200 | acclient.c:92196–92197 |
| Setup | 25 / 100 | 92223–92224 |
| Animation | 20 / 80 | 92250–92251 |
| Palette | 60 / 100 | 92304–92305 |

**The recycle path is dead code in this build.** `GetFreeObj` (83108) has a
**three-way** condition at 83115–83117: `m_bRecycle`, `m_nFree > m_nIdealSize`,
and `FreelistRemoveOldest() != 0`. `m_bRecycle` is assigned **0 at all 65
registration sites** — 50 in `MasterDBMap::InitDBTypeDef_Internal`
(92064–93422) and **15 in `gmMasterDBMap::InitDBTypeDef_Internal`
(514938–515316)** — plus two constructor sites and two bulk copies, with **zero**
nonzero assignments anywhere. The alternate decompilation agrees. Corroborating:
the sibling `m_bShrink` is set to 1 at 63 sites, so the 0 is deliberate.

There is no global byte budget — limits are per-type object counts.

Writable cell dats additionally keep an **on-disk LRU**: `LRU_List`
(acclient.h:28702) and `LRUB_Mem_t` (acclient.h:**28788**), with
`BTree::Restamp_Entry` (648508) called from `LoadDataEx` (647459) and
`Try_Delete_Oldest` called from `CheckRoom` (**647197**).

---

## 9. DDD writes into the dats

`CAsyncSaveRequest` (acclient.h:28526) is built in two places:
`AsyncCache::AsyncSave` (86677, flags 1 = raw) and
`CLCache::AsyncSaveDDDMessage` (291679), which sets
`dwDiskControllerSaveFlags = m_bCompressed ? 12 : 1` — 4 is `dcsfUncompress`, 8
is `dcsfModifyCachePack` (enum at acclient.h:5606) — and stamps `idIteration`
from the server.

`DiskController::SaveDataEx` (647687) switches on `dwFlags & 7` (test at 647718,
switch at 647726) and applies a **staleness guard** at acclient.c:**647775**
(`v12 = v4->iter_` at 647774). An earlier draft cited 647760, which is
`if (dwFlags & 8)`:

```c
if (v12 && v11->iter_ > v12) { v5 = 1; goto LABEL_27; }
```

An on-disk entry with a *newer* iteration silently wins, so replayed or
out-of-order `DDD_DataMessage`s cannot downgrade a record.

Space is made by `DiskController::CheckRoom` (body **647183**): needed blocks
plus **51 slack** (`size_l / (iBlockSize_ − 4) + 51` at 647189), then either
`ExpandFile(0x100000)` — 1 MiB at a time, 647195 — if expandable, or
`BTree::Try_Delete_Oldest` (647197) if not.

`CLBlockAllocator::Store_Data` (650531) consumes the free chain and only commits
`firstFree_` / `iFreeBlocks_` (plus a 0x50-byte header rewrite at offset 320)
once it reaches the last block. `DeleteBlocks` (650406) re-tags each freed link
with bit 31 and splices the run onto `finalFree_`.

A failed DDD write is fatal: `CLCache::OnSaveRequestFinished` (296099) calls
`Turbine::Debug::Abort()`.

### The iteration handshake

`CMostlyConsecutiveIntSet` (acclient.h:28732) is a sorted, deduped int array
(`Sort` 646607) with run-length `Serialize` (646696).

At `DDD_InterrogationMessage` the client loads each dat's set from `0xFFFF0001`
into a `CAllIterationList` (654732) and ships it up. **The server computes the
delta** and returns `DDD_BeginDDDMessage` with per-dat `MissingIteration`
records; the client never diffs anything itself.

An iteration number is `Add`ed and `SaveIterationList`ed only after the last byte
of that iteration has landed (294042–294044, 294303–294312), so a crash
mid-patch simply re-requests the whole set.

The protocol side of DDD is documented in `02-networking.md` §9.

---

## 10. Startup validation is three-layered and mostly permissive

**(1) Pack version.** `DiskController::InitFile` (body acclient.c:**647891**)
compares
`eng_pack_vnum` / `game_pack_vnum` against `DBCache::s_EngDataPackVer` /
`s_GameDataPackVer`; mismatch returns −6, and with `open_flags & 0x10` the dat is
**recreated empty** (647970–647994). The statics default to `0xFFFFFFFF` (acclient.c:44367–44371), and a negative
expected version short-circuits the test — **but the conclusion an earlier draft
drew from that is inverted.** `gmCLCache::Init` sets `s_GameDataPackVer = 0`
(acclient.c:**435273–435275**) *before* calling `CLCache::Init`, and 0 is not
negative, so **the game half of the check is live** in the shipping client: it
requires either `eng_only` (passed as 0) or `dat.game_pack_vnum == 0`. Only the
**engine** half is short-circuited, `s_EngDataPackVer` remaining −1.

Also note cell dats use a *different* pair of statics, `s_EngCellPackVer` /
`s_GameCellPackVer` (acclient.c:292102–292103).

Whether the shipped `client_portal.dat` actually carries `game_pack_vnum == 0` —
and therefore whether this gate passes in practice — cannot be answered from the
decompilation; it needs a real dat file.

**(2) Journal replay.** `BTree::RecoverTransaction` — see §1.

**(3) Per-record versioning** is the strongest gate. `CRegionDesc::UnPack`
requires `version == 3` exactly, and otherwise raises one of two `PopupError`
dialogs — "The data files have a more recent verion than the executable…" (sic)
or its inverse — and refuses to load (acclient.c:299874–299885).

---

## 11. Resource formats

**`DBWave`** (acclient.h:57172) is **not** a RIFF file: `UnPack`
(acclient.c:384721) reads `u32 headerSize`, `u32 dataSize`, then a bare
`WAVEFORMATEX` blob and raw codec bytes. See `09-audio.md`.

**`CSoundTable`** (acclient.h:30809) is a *recursive* `SoundTableData` tree keyed
by `SoundType`; each node holds N × 16-byte `SoundData{sound_id, priority,
probability, volume}` and N children (`Pack` 384970).

**`GfxObjDegradeInfo`** (acclient.h:31705) is `u32 count` plus count × 20-byte
`GfxObjInfo{gfxobj_id, degrade_mode, min_dist, ideal_dist, max_dist}`.

**`ClothingTable`** (acclient.h:56734) is two `PackableHashTable`s — setup DID →
`ClothingBase` (part and texture substitutions), and palette-template key →
`CloPaletteTemplate` (icon plus `CloSubpalEffect`s). `CloSubpalEffect` is
`u32 numRanges`, then `numRanges × {start, length}`, **then** `palSet` last
(acclient.c:466319). `BuildObjDesc` (464867) turns a shade in [0,1] into one
palette DID via `PalSet::GetPaletteID` (470484:
`palette_IDs[(u64)((num_pals − 0.000001) * shade)]`), and
`CPartArray::SetPalette` (326448) → `Palette::makeModifiedPalette` (365273)
copies the 2048-entry base palette and overwrites only the named ranges.

**LandBlock** records are **exactly 248 bytes**: `u32 DID` plus
`CLandBlockStruct::pack_size() == 244` (acclient.c:351510, 353336) = 81 × u16
terrain (162 B) + 81 × u8 height (81 B) + 1 pad.

**`LandDefs`** (acclient.h:35885) is an empty namespace class; `get_vars`
(467309) hardcodes height and width 255, cell size 24.0, 8 cells per block, max
object height 200.0, sky 1000.0, road 5.0. The only real datum is the 256-float
`Land_Height_Table` loaded from the region (`set_height_table` 467322, clamped to
[0, 800]).

**`CRegionDesc`** (acclient.h:53237, `UnPack` 299776) carries a `parts_mask`
(`0x01` sound, `0x02` scene, `0x04` terrain, `0x10` sky, `0x200` misc), the height
table, `GameTime`, a `SkyDesc`, an `AmbientSTBDesc`, scene and terrain type
tables, and `LandSurf` — whose `UnPack` (303985) reads one selector word choosing
the legacy `PalShift` path or the modern `TexMerge` path. `CEncounterDesc` has
only a `Destroy` in the client: **encounters are server-side.**

**`CLandBlockInfo`** (acclient.h:31893, `Pack` 350963) serializes
`num_objects × {DID, Frame(28 B)}`, then
`(num_buildings & 0xFFFF) | (has_restriction << 16)`, each `BuildInfo` with its
`CBldPortal` list, and optionally the restriction hash. **`num_cells` *is* stored.** `pack_size` (350892) returns `32*num_objects + 12`
— three fixed dwords, not the two an earlier draft accounted for — and `Pack`
writes that leading dword before `num_objects` (350984), with `UnPack` reading it
back first (351086). What is genuinely *not* serialized is `cells` / `cell_ids`:
the `CEnvCell` records themselves, fetched by DID `0xLLLL0100+i`.

**`CEnvCell`** (acclient.h:32072, `Pack` 348524) writes a flag word (bit 0
seen-outside, bit 1 has statics, bit 3 has restriction obj), the cell id,
`u8 num_surfaces`, `u8 num_portals`, `u16 num_visible_cells`, the surface IDs as
16-bit indices promoted with `| 0x08000000`, the environment as `| 0x0D000000`, a
cell-struct index, a 28-byte `Frame`, the portals, the visible-cell list (each
`block_mask | u16`), and the static-object list.

---

## 12. Traps for the unwary

**`PFileNode` / `PFileParser` are believed unrelated to DATs** (acclient.h:8153,
acclient.c:721844) despite the naming. They are a refcounted tree of named nodes
with line, column, and comment information — Turbine's loose-file text property
format, used for RenderMaterial, UI `StateDesc`, keymaps, and dev data. The exhaustive "no BTree, DID, or `Cache_Pack_t` anywhere in that subsystem"
sweep was **not completed** in the third pass, and there is at least one
adjacency: `EnumeratedBitfield::FromFileNode` (653554) takes a `PFileNode*` and
sits directly below `InitByDataID`, which *does* use `QualifiedDataID` and DIDs.
Treat the separation as likely but unproven.

**Type tags look like DIDs.** `0x10000004` and friends are DB_TYPE constants
passed to `GetByEnum`, not data IDs — see §4.

**`QualifiedDataIDArray` is not an array.** It is
`IntrusiveHashTable<QualifiedDataID, DBObjSaveInfo*>` (acclient.h:28073).

**`DiskConBase::GetDatFileID`** (291609) returns a 64-bit value with
`data_set_lm` in the high dword and `data_subset_lm` in the low dword.

**Trampolines and forwarders abound.** `MasterDBMap::Init`,
`DiskController::LoadData`, and others are thin wrappers; the real body is
elsewhere. Check the function length before concluding you have found the
implementation.
