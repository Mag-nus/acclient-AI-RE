# Asheron's Call Client — Reverse Engineering Notes

Target: **acclient.exe, September 2013, version 11.4186**

Decompiled by Hex-Rays with the original Turbine PDB present, so class and
function names throughout are the real internal names, not invented ones.

All findings have been through **three passes**: an initial survey, an
adversarial verification pass, and a third pass that treated the second pass's
own corrections as suspect and re-checked them independently. Each pass found
real errors in the one before it, including two fabricated identifiers and two
false universal negatives. Where a draft was wrong, the reports say so
explicitly and name the error.

## Source material

| File | Size | What it is |
|---|---|---|
| `../acclient.c` | 938,010 lines | Primary Hex-Rays decompilation |
| `../acclient 6.95.16808.c` | 928,590 lines | Alternate decompilation, newer Hex-Rays (2016). Useful for cross-checking garbled bodies. |
| `../acclient.h` | 70,719 lines | Type definitions: 6,936 structs, 410 enums |
| `../acclient.pdb` | 29.6 MB | Original debug symbols — a first-class artifact, see below. **Not included in the repository**; user-provided. |

The binary itself (`../acclient.exe`, 4,837,376 bytes, MD5
`2e30cd620b26f9787b4e6a6257a9e581`) and the PDB are **not distributed with this
repository** — they are excluded via `.gitignore` and must be supplied by the
user at those paths for any work that reads the bytes directly.

### Layout of `acclient.c`

| Lines | Contents |
|---|---|
| 1–14 | Preamble and includes |
| 15–38,953 | Function prototypes |
| 38,955–60,792 | Globals, vtables, string literals |
| 60,793–938,010 | Function bodies (36,601 of them) |

Functions are **not** grouped by class — the linker's COMDAT ordering scattered
them. `CPhysicsObj`'s 230 bodies span lines 143,003–343,373. Use the index files
below rather than trying to read any region contiguously.

### The PDB

`acclient.pdb` yields 16,232 global function symbols (plus 23,716 static ones)
with exact virtual address, byte length, and owning `.obj`, and 1,091 module
records with original build paths (`d:\ac1_sep13\output\obj\…\WIN32\retail\`).
It has no call-graph records, so it cannot resolve call ordering — but it
settles "is this really function X" and "how big is it" instantly, and it reveals
the original four-layer library split (`PORTAL` / `ENGINE` / `GAME` / `AC`).

**It also carries full line information** — roughly 1.83 MB of C11 records and
730 distinct source paths — which earlier drafts wrongly said it lacked. VA to
`file:line` resolution is available and has not yet been exploited here.

## Navigation index

**If `acclient.c` is unwieldy, use [`../acclient-src/`](../acclient-src/)** — the
same decompilation split into 795 files along Turbine's original
`LAYER/library/module.obj` tree, reconstructed from the PDB's module records.
Bodies are identical to the monolith apart from one documented textual
substitution — Hex-Rays' backtick/apostrophe compiler names (`` `vftable' ``,
`` `scalar deleting destructor' ``) are rewritten to plain identifiers, 14,122 of
them; see [`../acclient-src/README.md`](../acclient-src/README.md). Every
function keeps its original `acclient.c` line number, so the citations in these
reports resolve in either copy. Start at
[`../acclient-src/INDEX.md`](../acclient-src/INDEX.md).

Index files, all in this folder:

- **`INDEX.md`** — all 1,011 classes with function counts and body line ranges
- **`class_index.tsv`** — same, machine-readable: `count \t class \t first-last`
- **`func_index.tsv`** — every function body that has a signature: `line \t full
  signature`. That is 36,601 of the 36,603 — the two Hex-Rays failed to
  decompile (`Client::UseTime`, `Client::KeepUIAlive`) carry an `#error`
  directive in place of a signature
- **`struct_index.txt`** — every struct/union/enum in `acclient.h` with its line

Not to be confused with [`../acclient-src/INDEX.md`](../acclient-src/INDEX.md),
which indexes the split tree instead: all 795 files, grouped by layer and
library, each with its function count and address range.

## Reports

**Start with [`00-architecture.md`](00-architecture.md)** — it ties the eleven
subsystem reports together: the shape of the main loop, the two-object model,
end-to-end data flow, the three ordering layers, where authority lives between
client and server, the recurring code idioms, and the decompiler traps.

| Document | Subsystem | Principal classes |
|---|---|---|
| `01-physics.md` | Physics, collision, movement, animation, world geometry | `CPhysicsObj`, `CTransition`, `CSequence`, `CMotionTable`, `CObjCell` |
| `02-networking.md` | UDP transport, protocol, dispatch, DDD patching, login, chat | `SharedNet`, `Indicator`, `NetBlob`, `PacketController` |
| `03-object-model.md` | Objects, properties, inventory, appearance, social systems | `ACCWeenieObject`, `CACQualities`, `PlayerModule`, `SmartBox` |
| `04-combat-magic.md` | Attacks, stances, enchantments, spells, skills | `ClientCombatSystem`, `CEnchantmentRegistry`, `CSpellBase` |
| `05-ui.md` | UI framework, windows, input, keybinding, camera, radar | `UIElement`, `UIElementManager`, `MediaMachine`, `gm*UI` |
| `06-rendering.md` | Graphics pipeline, terrain, portals, sky, textures | `RenderDeviceD3D`, `D3DPolyRender`, `PView`, `ImgTex` |
| `07-dat-resources.md` | DAT container format, BTree, async cache, resource formats | `BTree`, `DiskController`, `ThreadedCache`, `CLCache` |
| `08-client-core.md` | Startup, main loop, commands, plugin API, infrastructure | `Client`, `APIManager`, `AC1Legacy`, `InterfaceSystem` |
| `09-audio.md` | DirectSound backend, sound tables, ambient beds | `SoundManager`, `CSoundTable`, `Ambient` |
| `10-crypto-obfuscation.md` | **Cross-cutting:** every encryption, obfuscation, hash, PRNG, checksum and encoding, with reproducible formulas | `CryptoSystem`, `QTIsaac`, `SpellFormula`, `PortalChecksum` |
| `11-memory-leak-investigation.md` | **Defect report:** three confirmed memory leaks in object teardown and icon lifetime, with fixes | `CObjectMaint`, `ACCWeenieObject`, `IconData` |

## These notes also describe the 2015 client

Both `acclient.exe` binaries (user-provided — neither ships with this
repository) have been compared byte for byte, masking only the operands that necessarily differ between builds (using the
PE relocation table and real instruction boundaries, not a heuristic scan).

**Over 99.5% of functions are byte-for-byte identical between 11.4186 and
11.6096. Only 46 changed.** Cryptography, the DAT container and cache
layer, rendering, the UI framework, object maintenance, audio and the plugin API
have **zero** changed functions between the two builds; physics has three (all
about when a jump is permitted) and networking two.

So every report here describes the 2015 client too, with three exceptions noted
in [`../../2015-10 11.6096/docs/13-client-differences-2013-vs-2015.md`](../../2015-10%2011.6096/docs/13-client-differences-2013-vs-2015.md) §6.
That document lists all 46 changed functions and explains how to translate
addresses between the builds.

Two errors in `11-memory-leak-investigation.md` were found during that comparison
and have been **corrected in place**: the `ACCWeenieObject` vtable labels were
inverted (§8b), and the claim that file offset equals RVA "for every section" is
false beyond `.data` (§8b). Both corrections are marked where they appear.

## Caveats

Findings are cited as `file:line` so they can be re-checked. Three things limit
confidence in specific places:

**The main loop was recovered from a different build.** `Client::UseTime` and
`Client::KeepUIAlive` are the only two functions in the 11.4186 binary that
Hex-Rays failed to decompile. Both bodies were recovered in full from the 2015
client, where an older Hex-Rays handled the indirect call the newer ones choke
on, and independently corroborated by a second, name-stripped decompilation of
that same build. Four lines of evidence — a rigid +0x360 block rebase, a
two-sided orphan-closure test, the third decompilation, and an identical
dual-decompiler failure signature — make the transfer to 11.4186 as strong as
static evidence allows. No binary is present, so byte-level identity remains
formally unproven. See `08-client-core.md` §2.

**Hex-Rays substitutes string literals for large immediates.** The immediate
`0x800000` renders as a long format-string pointer throughout, and means
different things in different subsystems (`SLEDDING_PS`, `Vitae_EnchantmentType`,
`MISSILE_AMMO_LOC`). This caused a first-pass error in the combat report. When a
string constant appears in a bitwise test, look up the numeric value.

**Not every strange constant is decompiler damage.**
`PhysicsGlobals::floor_z = cos(3437.746770784939)` looks like an artifact but is
a genuine degrees-for-radians bug in Turbine's source, giving a real walkable
slope limit of ≈48.38° rather than the intended 60°.

The full list of traps is in `00-architecture.md` §9.
