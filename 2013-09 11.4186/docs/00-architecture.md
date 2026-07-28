# Architecture Overview

Target: acclient.exe 11.4186 (September 2013).

This document ties together the eleven subsystem reports. Read it first; each
detailed claim below is sourced in the linked report.

> **Status.** Every subsystem has been through three passes: an initial survey,
> an adversarial verification pass, and a third pass that treated the second
> pass's own corrections as suspect. Each pass found real errors in the one
> before it. Corrections are folded into the individual reports and named there.
> §9 collects the decompiler traps that caused most of them.

---

## 1. The shape of the program

The client is a **single-threaded game loop** with exactly one long-lived worker
thread (the DAT loader). Networking, physics, UI, and rendering all run
sequentially on the main thread.

```
WinMain
 └─ Client::Init      network, DATs, device, UI
 └─ Client::Run  ──►  while (Client::UseTime())
                        Timer::update_time
                        Device::DoEventLoop            Win32 pump; returns true to quit
                        ClientNet::UseTime             socket recv, ack, flow control
                        Client::ProcessLogonEventQueue queue 4 + Turbine Chat
                        PacketController::UseTime      fragment reassembly
                        CLCache::UseTime               DDD pump + async-cache drain
                          └─ ThreadedCache::UseTime → DBCache::UseTime
                        UIElementManager::UseTime      UI tick + dirty-rect paint
                        SmartBox::UseTime              the world tick:
                               CellManager, CObjectMaint, CPhysics,
                               LScape, Ambient, SceneTool::Think,
                               NetBlob dispatch, Render::CalcDegLevel
                        SceneTool::PrepareGraphicsDevice
                        SceneTool::StartFrame
                        SmartBox::Draw                 3D scene
                        SceneTool::EndFrame            UI overlay, EndScene, Flip
                        Device::DoFrameSleep           throttle only when inactive
```

**This ordering is now observed, not inferred.** `Client::UseTime` and
`Client::KeepUIAlive` are the only two functions in the 11.4186 binary that
Hex-Rays failed to decompile — but the sibling 2015 client folder contains a
decompilation by an *older* Hex-Rays (6.6) that handled the offending indirect
call and emitted both bodies in full. The third pass corroborated this with a second,
name-stripped decompilation of the same build and three further arguments — a
rigid +0x360 block rebase, a two-sided orphan-closure test, and an identical
dual-decompiler failure signature — making the transfer to 11.4186 as strong as
static evidence allows. See `08-client-core.md` §2.

One correction this forced: earlier drafts put `UIFlow::Update` in the frame
pump. It is **not** there, and it has no visible caller in any of the four
decompilations. `UIFlow` derives from `Interface`, whose vtable holds only the
six COM-ish slots, and `Client::m_ui` is only ever stored and cleared — so the
whole class is reached through the `Turbine_GUID` registry. Identifying the
caller would need the binary's `.rdata`.

Two timing rules are observable. There is **no frame cap when the window is
active**; `Device::DoFrameSleep` throttles to roughly 10 fps when inactive.
Physics is separately clamped, in two places: `CPhysics::UseTime` returns
immediately unless 1/30 s has elapsed (the real limiter), and within an object's
update `MIN_QUANTUM` = 1/30 s gates the remainder after `MAX_QUANTUM` = 1/5 s
slices.

---

## 2. The central abstraction: every object is two objects

This is the most important structural fact about the codebase.

| Half | Class | Owns |
|---|---|---|
| Physical | `CPhysicsObj` | position, cell, velocity, geometry, animation, collision |
| Logical | `ACCWeenieObject` | name, icon, stats, inventory, container, UI state |

They cross-link by pointer and are registered in **parallel hash tables** in
`CObjectMaint` — `object_table` and `weenie_object_table`, each with a `null_`
twin for objects whose cell isn't loaded yet.

"Weenie" is Turbine's own term for the game-data entity as opposed to the
physical one. A third layer sits under the weenie:
`PlayerDesc : CACQualities : CBaseQualities` holds the sparse property tables.

`SmartBox` is the world-session hub that owns the object registry, physics,
landscape, camera, and player pointer. Effectively every 3D-world network event
enters through `SmartBox::DispatchSmartBoxEvent`.

Details: `03-object-model.md`, `01-physics.md`.

---

## 3. Data flow, end to end

```
UDP datagram
  └─ ProtoHeader (20 bytes) + optional headers + fragments
       └─ BlobFrag (448-byte payload chunks)
            └─ Indicator: dedup, supersede, reassemble
                 └─ queueID routes:  2 control · 4 logon (+ chat) · 5 DAT/DDD
                                     9 UI events · 10 SmartBox
                      ├─ queue 10 ─► ACSmartBox::DispatchSmartBoxEvent
                      │                0xF745 CreateObject, 0xF748 Position, …
                      │                  └─ CPhysicsObj + ACCWeenieObject
                      └─ queue  9 ─► UIQueueManager::ProcessNetBlobData
                                       0xF7B0 weenie-ordered envelope
                                       0xF7B1 plain-ordered envelope
                                         └─ CACQualities property writes
                                              └─ QualityRegistrar notices
                                                   └─ gm*UI windows repaint
```

The UI never reads the network directly and the network never touches widgets.
The seam is the **notice system** — a publish-subscribe bus of 157
`SendNotice_*` symbols and 152 defined `RecvNotice_*` handlers. A stat update writes into
`CACQualities`, fires a notice, and any window registered for it re-queries and
marks itself dirty.

One structural surprise: **every `CWeenieObject` is itself a `NoticeRegistrar`**,
so notices are not purely global — objects carry their own subscriber lists.

Details: `02-networking.md`, `03-object-model.md`, `05-ui.md`.

---

## 4. Three independent ordering layers

A point that spans two reports, and a common source of confusion: the protocol
enforces ordering at **three** separate levels, solving different problems.

1. **Packet sequence** — `ProtoHeader.seqID_`, with NAK lists, retransmission
   from `SentPacketStore`, and a `0x7FFF` look-ahead limit. Recovers lost
   datagrams. The AVL of NAKed seqIDs stores each packet's **crypto key**
   alongside it, so retransmits decrypt with the original key and the ISAAC
   streams stay synchronized across loss.
2. **Blob ordering** — the 64-bit `blobID` encodes an ordering *type* (bits
   56–60) and a 16-bit stamp (bits 32–47), plus the `0xF7B0` / `0xF7B1`
   envelopes. The `Indicator` uses this to discard stale ephemeral fragments
   *before reassembly even begins*, and to replace a half-assembled blob when
   stamps differ — though the direction of that comparison is **not** what
   intuition suggests; see `02-networking.md` §3.
3. **Per-object and per-property versions** — `PhysicsDesc` carries
   `u16 timestamps[9]`; `ACWTimeStamper` keeps a per-property sequence byte keyed
   by `stype | (StatType << 16)`. A stale update is silently dropped.

So a late-arriving movement packet can be discarded at layer 3 even though layers
1 and 2 delivered it correctly. That is deliberate reorder tolerance.

---

## 5. Almost everything is data-driven from the DAT files

The executable is largely an interpreter for `client_portal.dat`,
`client_cell_*.dat`, `client_local_*.dat`, and `client_highres.dat`.

| What | DB_TYPE | DID range |
|---|---|---|
| Meshes (`GfxObj`) | 6 | `0x01000000`–`0x0100FFFF` |
| Object archetypes (`Setup`) | 7 | `0x02000000`–`0x0200FFFF` |
| Animations | 8 | `0x03……` |
| Palettes | 10 | `0x04……` |
| Textures | 11, 12 | `0x05……`, `0x06`–`0x07……` |
| Motion tables | 14 | `0x09……` |
| Clothing / appearance | 25 | `0x10……` |
| Sound tables | 34 | `0x20……` |
| UI layouts (`LayoutDesc`) | 35 | `0x21……` |
| String tables | 37 | `0x23000000`–`0x24FFFFFF` |
| Keymaps (`CMasterInputMap`) | 29 | `0x14……` |
| Landblocks, cells | 1, 2, 3 | `0xLLLLFFFF`, `0xLLLLFFFE`, `0xLLLL0100`+ |

And **almost nothing hardcodes a DID**. `master_map_id_m` in the DAT header roots
a two-level enum-to-DID indirection (`DBCache::GetDIDFromEnum`), so code asks for
"font 23, group 9" and the mapping lives in data.

The consequence is that whole systems are configuration rather than code. UI
windows are `LayoutDesc` trees whose per-state art, sounds, and animations come
from `MediaDesc` playlists executed by a small **bytecode interpreter** with
Pause, Jump, Message, and State opcodes. Skill values are a `SkillFormula`
record. Experience is a lookup table. Movement speed is the authored velocity
baked into animation `MotionData`. Key bindings merge a user INI over two DAT
defaults. Even the gameplay-options list is read from DBObj enum 21 rather than
compiled in.

Details: `07-dat-resources.md`, `05-ui.md`, `04-combat-magic.md`.

---

## 6. The standout engineering: the async cache

For a 1999-era engine the resource pipeline is startlingly well-built:

- one dedicated I/O thread with **1024-slot lock-free ring queues** (SPSC, with a
  mutex-guarded overflow list) and event wakeup
- **no object construction off-thread** — the worker only reads bytes and
  decompresses (zlib). It does also perform *saves* and purges, which matters for
  DDD patching.
- main-thread completion **time-boxed to 25 ms per frame**, so a burst of loads
  degrades smoothly instead of hitching
- **automatic dependency-graph loading** — a `Setup` completes only once its
  child `GfxObj`s and palettes arrive, tracked by `nGetsRemaining` and
  `RequestsWaitingForMe`
- duplicate concurrent requests are deduplicated
- the on-disk B-tree is **transactional**, with a 64-byte write-ahead record at
  file offset 256 replayed on open, because live server-push patching (DDD)
  writes into the same files
- DDD writes carry a **staleness guard**: an on-disk entry with a newer iteration
  number silently wins, so replayed patch messages cannot downgrade a record

Details: `07-dat-resources.md`, `02-networking.md` §9.

---

## 7. Where authority lives

**Client is authoritative for its own movement.** It runs full local physics —
including a real restitution impulse solver, `v += −(v·n)(1+elasticity)·n` — and
pushes position packs upstream. The server corrects rather than simulates.

**Server is authoritative for everything else.** Combat is the clearest case: the
client sends only `(targetID, attackHeight, power)` and waits. Every hit roll,
damage figure, fizzle, and resist is computed server-side and returned as a
discrete event. The client never learns an enemy's absolute health — only a
fraction, via message `0x1C0`.

The verification pass strengthened this considerably. Structures that *look* like
client-side game logic turn out to be parsed and then **never read**: the combat
maneuver table's contents, `SpellBookPage::_casting_likelihood`,
`CSpellBase::_category` and `_power`, spell sets, the `DamageOverTime` flag, the
whole `Body` / body-part armor model, `CEmoteTable`, and `CreationProfile`. There
is no client-side chance-to-cast math and no client-side hit-location logic at
all.

**There is no *local* anti-cheat**: no debugger detection, no integrity checks,
no version self-validation, no code-section checksum. The only client-side
enforcement is a voluntary speedhack self-report. **But "anti-cheat absent" is
too strong** — the client ships a server-driven plugin audit
(`ClientAdminSystem::Handle_Admin__Recv_QueryPluginList`), which answers server
queries with the loaded plugin's name, author, e-mail, and webpage.

This build also **never installs a `SetUnhandledExceptionFilter` handler** — the
Turbine filter, the 100 MB emergency pool, and Watson reporting are all present
but gated behind a debug bit that `Turbine::Debug::Init` clears at startup.
(The CRT's own `__try/__except` frame around `WinMain` still exists, so "no crash
handling of any kind" would overstate it.)

That is coherent with the sanctioned-plugin culture: `APIManager` deliberately
loads a third-party DLL named in the registry and hands it a 52-method COM
interface. Decal was a supported extension point, not a hack. (Though 16 of those
52 methods are `E_FAIL` stubs — the trade and salvage automation surface was
declared and never finished.)

Details: `02-networking.md`, `04-combat-magic.md`, `08-client-core.md`.

---

## 8. Reading the codebase: recurring idioms

**Ref-counted copy-on-write strings.** `PStringBase<T>` is a bare pointer to
character data with metadata at *negative* offsets in a shared `PSRefBuffer`
(vfptr, refcount, capacity, cached hash, length, then data at +20). Every string
destructor inlines as an `InterlockedDecrement` on `buffer[-1]` followed by a
virtual call at `buffer[-2]`. This appears thousands of times and accounts for
much of the visual noise.

**The COM lookalike.** `Turbine_GUID` is layout-identical to `_GUID`, and the
root `Interface` vtable has six slots: three real `__stdcall` IUnknown entries
followed by three `__thiscall` Turbine-convention ones. Objects are
binary-compatible with COM without using its registry or marshaling — which is
what makes the plugin API possible.

**`PackObj` serialization.** Everything on the wire derives from `PackObj` with
virtual `GetPackSize` / `Pack` / `UnPack`. Strings are `u16` length, bytes, then
4-byte alignment. `PackableHashTable` packs bucket count in the high 16 bits and
element count in the low 16 of one dword.

**Bitfield-gated optional fields.** `PublicWeenieDesc` uses two 32-bit presence
masks; `PhysicsDesc` one; `CACQualities::UnPack` two; the packet `header_` word
doubles as a bitmask of which optional headers follow. When you see an unpacker
testing bit after bit against a header dword, that is the idiom. **Note the gate
bits are not field order** — `CBaseQualities` gates int with `0x01` but int64
with `0x80`, despite int64 being the second field.

**Generated notice boilerplate.** Each `SendNotice_X` fetches a handler list for
a compile-time constant ID and calls a **fixed vtable slot**. There is no dynamic
dispatch table; both the notice ID and the offset are baked in.

---

## 9. Decompiler traps

These caused most of the first-pass errors. Watch for all of them.

**Hex-Rays substitutes string literals for large immediates.** The immediate
`0x800000` renders throughout as
`(unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)"`.
It is `SLEDDING_PS` in physics contexts, `Vitae_EnchantmentType` in the
enchantment registry, and `MISSILE_AMMO_LOC` in inventory code. The first pass
misread it as `0x8000000` in the combat report. **When a string constant appears
in a bitwise test, look up the numeric value.**

**Not every strange constant is an artifact.** `PhysicsGlobals::floor_z` is
initialized as `cos(3437.746770784939)`, which looks like decompiler damage but
is not: `3437.7467…` is exactly `60 × (180/π)`, a genuine
degrees-for-radians bug in Turbine's source. The `cos` really runs at load time,
so the walkable slope limit really is **≈48.38°, not 60°**.

**Duplicate static constants across translation units.** `MIN_QUANTUM` has 100
identical initializers; the plain `MIN_QUANTUM` global is `0.0` in the static
image but initialized to 1/30 at load, and it is never read — only the
`_93` and `_97` copies are live. Check that the address you cite is the one being
read.

**Type tags look like DIDs.** `0x10000004`, `0x10000009` and friends are DB_TYPE
constants passed to `GetByEnum`, not data IDs. The real DIDs are in
`07-dat-resources.md` §4.

**IDA mislabels struct fields.** Several branches inside `CACQualities::UnPack`
carry the wrong `CBaseQualities` field names, and the `Client` struct's
command-line member names are offset-shifted and simply wrong. Trust
`SetPackHeader` and `operator new` sizes over decompiled field names.

**Trampolines abound.** `MasterDBMap::Init`, `DiskController::LoadData`, and
others are thin forwarders; the real body is elsewhere. Check function length
before concluding you have found the implementation.

**`__usercall` register arguments signal a failed caller.** Prototypes like
`SceneTool::EndFrame(a1@<ebx>, a2@<ebp>, …)` mean IDA could not type the *caller*
and leaked its register state into the callee. Those functions are called from
the two undecompilable frame pumps.

**Prefer header enums to inferred bits.** `EnchantmentTypeEnum`, `SpellIndex`,
`StatType`, `COMBAT_MODE`, `RadarBlipShape`, and the component type and category
enums are all fully named in `acclient.h`. Reconstructing them from usage is how
the first pass got several values wrong.

**Notice IDs are address-encoded.** The 5100xxx notice constants decompile as
`(char *)&loc_XXXXXX + n`, not as decimals — grepping for the number finds
nothing. Misreading IDA's decimal autoname counter (`nullsub_1891`) as hex is
what produced two phantom "out-of-band" notice IDs in an earlier draft.

**Absence of evidence is not evidence of absence.** Every strong negative in
these documents was reached by grep over *one decompilation*. Two such claims
turned out to be false (§10). Where a negative survived a targeted hunt it is
stated as "no such path was found", not "there is none".

---

## 10. Archaeology: what this build is

11.4186 is a late-life client, fourteen years into a game that shipped in 1999,
and the layering shows.

**The 1999 core is intact.** Sphere-swept collision against BSP polygon soups.
Terrain textures composited in software offline ("texture merge") rather than
blended at runtime. CPU-lit landscape vertices rebuilt per frame. Painter's-
algorithm translucency — and in fact the alpha *list* is not sorted at all;
ordering happens coarsely per-part beforehand. Portal-clipped visibility. Pure
fixed-function transform and lighting. Audio is 2D DirectSound with
software-computed pan; the 3D listener is configured once and never updated.

**Modernization arrived as a second engine, not a rewrite.** The binary contains
**two complete rendering stacks**. The AC1 stack draws the world in fixed-function
D3D9. A much newer Turbine material stack — `RenderMaterial`, `MaterialLayer`,
`LayerStage`, with a `RenderPassType` enum reaching `RenderPass_ShaderGlow` and
`RenderPass_LandscapeShadowMap` — is fully implemented and live, but drives only
2D UI surfaces, atlas fonts, and debug primitives. Its `SetVertexShader` call
exists and always passes `NULL`. So the shader plumbing is not vestigial: it
belongs to a different engine that shares the process.

**Several expected features do not exist.** No shadows of any kind. No
nameplates, speech bubbles, or damage numbers — the hover name is a mouse-anchored
tooltip. No MIDI music (a complete player is compiled in with no game-side
caller). No weather engine — "weather" is a cell of UV-scrolling objects pinned
under the player.

Two claims in earlier drafts of this document were wrong and are worth flagging
as cautionary: **billboarding does exist** (`CPhysicsPart::calc_draw_frame`, four
DAT-driven modes), and **streaming audio does exist** (a live DirectShow filter
graph, outside `SoundManager`). Both errors came from searching one plausible
location, finding nothing, and generalising to the whole binary.

**Gameplay accreted visibly.** The "floaty" UI windows are a parallel set of
movable skins alongside the original fixed panels. `PlayerModule` carries two
generations of options storage at once. Late-era systems — augmentations,
luminance, enlightenment, aetheria — appear only as bare property literals with
named enums existing solely on the server.

**Developer tooling shipped in retail.** `DebugConsole`, `ProfilerUI`, a debug
HUD, a `dxdiag` report generator, and the `loc`, `render`, and `framerate`
commands are all in the production build. No GM-only commands ship.

**The build itself is recoverable.** The PDB gives 16,232 function symbols and
1,091 module records with original paths under `d:\ac1_sep13\output\obj\…\WIN32\
retail\`, confirming that the `Portal*` / `AC*` / `GAME*` / `ENGINE*` prefixes
are a genuine four-layer static-library split rather than a naming convention.

---

## 11. Cross-references

| Report | Subsystem |
|---|---|
| `01-physics.md` | Physics, collision, movement, world geometry |
| `02-networking.md` | UDP transport, wire protocol, dispatch, DDD, login |
| `03-object-model.md` | Game objects, properties, inventory, social systems |
| `04-combat-magic.md` | Attacks, stances, enchantments, spells, skills |
| `05-ui.md` | UI framework, windows, input, camera, radar |
| `06-rendering.md` | Graphics pipeline, terrain, sky, textures |
| `07-dat-resources.md` | DAT container format, BTree, async cache |
| `08-client-core.md` | Startup, main loop, commands, plugin API, infrastructure |
| `09-audio.md` | DirectSound backend, sound tables, ambient beds |
| `10-crypto-obfuscation.md` | Every crypto, obfuscation, hash, PRNG and encoding, with formulas |
| `11-memory-leak-investigation.md` | Confirmed memory leaks in object teardown and icon lifetime |

Navigation aids: `INDEX.md` (1,011 classes with body line ranges),
`func_index.tsv` (all 36,601 function bodies), `struct_index.txt` (all types in
`acclient.h`).
