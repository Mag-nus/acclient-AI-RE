# Working context

Notes for whoever — human or model — picks this up next. The user-facing
overview is in `README.md`; this file is the operational side: what is
established, what to distrust, and what is still open.

---

## Ground rules that were established during the work

These came out of real mistakes. Follow them.

**The binary is the authority.** Above the decompilations, above the PDB names,
above any community reference. Two decompilations of the 2015 client exist and
they disagree; one has BinDiff-ported names that are demonstrably wrong in
several places (`PlayerModule::DisplayDateOfBirth` is actually the new
HearPKDeaths getter; `CM_Magic::DispatchUI_PurgeBadEnchantments` is a string
dispatcher). Verify with `objdump` before asserting.

**Do not assert a type you cannot evidence.** `_UNKNOWN` is left undefined in
`2013-09 11.4186/acclient-src/include/defs.h` on purpose — typedef'ing it to `int` would assert a
size that is not known and propagate the guess. When a type is needed, recover it
from the binary: spacing between adjacent symbols gives array extents, the bytes
give scalar values.

**Count code uses, not text matches.** Three declarations survived an earlier
audit only because they appear inside string literals (`"Not an int64."`). Strip
comments and string/char literals before counting.

**A rigorous negative is a result.** "The D3D layer is clean, here is the
complete enumeration that shows it" is worth as much as a finding, and was asked
for explicitly. Do not pad reports with speculation.

**Say what was not checked.** Coverage limits are stated in the documents on
purpose; keep doing that.

---

## The binaries

**Not in the repository.** The `.exe`s and the PDB are excluded via
`.gitignore`; the user provides them locally at
`2013-09 11.4186/acclient.exe`, `2013-09 11.4186/acclient.pdb` and
`2015-10 11.6096/acclient.exe`. Verify against the hashes below before trusting
any byte-level work, and do not assume they are present in a fresh checkout.

| | 11.4186 | 11.6096 |
|---|---|---|
| Size | 4,837,376 | 4,841,472 |
| MD5 | `2e30cd620b26f9787b4e6a6257a9e581` | `116d9a66a70b6af449dc3a28d82f2f6d` |
| SHA-256 (2015) | — | `bca95bbebed4b9ed1ff09d0da83144e2fc4208f63ad7ada5cb47c3ca207ccba9` |
| Linked | 2013-09-06 | 2015-06-12 |
| PDB | **yes**, 29.6 MB | **none** |
| Build root | `d:\ac1_sep13\` | `d:\ac1_acxp\` |
| ImageBase | `0x00400000`, **no ASLR** (`DllCharacteristics` = 0) | same |
| LARGE_ADDRESS_AWARE | **set** — 4 GB on 64-bit Windows, not 2 GB | set |

`file offset == RVA` for `.text`, `.rdata` and `.data` **only**. `.data1`,
`.rsrc` and `.reloc` are shifted by −0xCF000 because `.data` has a large BSS
tail. An early draft got this wrong.

---

## Binary diffing — use the tool, not intuition

`tools/binary_diff.py`. Its header documents four methods that gave wrong
answers (80.7%, 2.7%, 40.2%, 0.84% "changed") before the correct one (0.41%).
The failure mode in every case was guessing which bytes are operands.

**Correct method:** parse `.reloc` for `IMAGE_REL_BASED_HIGHLOW` entries — that
is authoritative about which dwords are addresses — and take instruction
boundaries from `objdump`, not a byte walker, to mask `call`/`jmp`/`jcc` rel32.

Answer: **46 functions changed; over 99.5% identical**, all 46
enumerated in `2015-10 11.6096/docs/13-client-differences-2013-vs-2015.md` §5.

Durable assets: `tools/relnorm.py`, `tools/binary_diff.py`,
`tools/pdb_symbols_11.4186.pkl` (39,948 function symbols with address, length
and owning `.obj`). Everything else from the original session lived in a
`/tmp` scratchpad and is gone.

---

## Known-good anchor addresses

Useful for re-orienting quickly.

| Symbol | 11.4186 | 11.6096 |
|---|---|---|
| `CObjectMaint::DeleteObject(uint)` | `0x005084D0` | `0x00508FA0` |
| `CObjectMaint::DestroyObjects` | `0x00508C30` | `0x00509700` |
| `ACCWeenieObject::ObjectBeingDeleted` | `0x0058E4D0` | `0x0058F300` |
| `Palette::makeModifiedPalette` (A / B) | `0x0053E280` / `0x0053E3C0` | `0x0053EFE0` / `0x0053F120` |
| `Palette::releasePalette` | `0x0053DFB0` | `0x0053ED10` |
| `DBObj::DBObj` (sets refcount = 1 at +0x24) | `0x004151C0` | `0x00415460` |
| `APIManager::Init` (ACPlugin loader) | `0x0055A2C0` | `0x0055AF00` |
| `Device::Init` | `0x0043B820` | `0x0043BA60` |
| `D3DPolyRender::Startup` | `0x0059E9F0` | `0x0059FB00` |
| Code cave (`DwExceptionFilter`, dead) | `0x006B5820`, 1292 B | `0x006B6760` |

`ACCWeenieObject` vtables: the one at `object+0` is `0x007E3EA0` (2013) /
`0x007E4F70` (2015) and its **slot 1 is `ObjectBeingDeleted`**. The table at
`object+0xC` is the `NoticeRegistrar` sub-object; calling its slot 1 invokes
`RegisterNoticeHandler` and will not do what you want. An early draft had these
labels inverted.

---

## Open threads

**Untested at runtime.** Nothing here has been executed. Two patches are
designed but unverified:

- The 15-byte palette fix (two `inc` sites plus the second `delete` in
  `releasePalette`). There is an unresolved tension documented in
  `12-memory-leak-2015.md` §0b: the published six-byte version is reported to run
  stably across 15 clients, but by static analysis it should double-free on
  nearly every palette release. That contradiction is not explained.
- The borderless-fullscreen patch at `0x0043B9C7` / `0x0043BC07`. The window is
  centred and `GetSystemMetrics` adjustments may still apply under `WS_POPUP`,
  so sizing needs checking.

**Decoded (2026-07-28).** The jump tables in
`ClientCommunicationSystem::HandleFailureEvent` (`0x00571990`) and
`UIQueueManager::ProcessNetBlobData` (`0x0055B000`) are now fully decoded, so the
`WeenieError` and S2C-opcode comparisons against ACProtocol are **exhaustive**.
Results are in `2013-09 11.4186/acclient-src/reference/`:
`failure_events_11.4186.tsv` (344 rows) and `s2c_dispatch_11.4186.tsv` (168 rows).

Neither function has *one* table — MSVC compiled each sparse switch into a
binary-search chain of range tables plus discrete `je` cases:

| | ranges | discrete `je` | total cases | default target |
|---|---|---|---|---|
| `HandleFailureEvent` | 6 (3 byte-indexed) | 5 | **344** (339 from tables) | `0x0057544A` |
| `ProcessNetBlobData` | 7 (all byte-indexed) | 6 | **168** (162 from tables) | `0x0055CA5C` |

Correcting two figures this file previously carried: the 339 was the
table-only count and missed the 5 discrete cases; and `ProcessNetBlobData`
dispatches **168** message IDs, not 164.

What the comparison shows:

- **Every one of the 344 failure codes and all 168 opcodes maps to a named
  ACProtocol entry — zero undocumented.**
- Failure codes: 233 are `WeenieError`, 111 are `WeenieErrorWithString`. The
  client handles **all 113** `WeenieErrorWithString` values and 233 of 369
  `WeenieError`; the 136 unhandled are server-internal codes (`NoMem`,
  `BadParam`, `SegV`, …), 55 of them below `0x100`. Client span is
  `0x17`–`0x593`; ACProtocol's `0x594 ContractError` sits one past the last
  table entry.
- Opcodes: 99 `GameEvent` + 69 `S2CMessage`. **Only one `GameEvent` is never
  dispatched — `0x1C8 Allegiance_AllegianceUpdateDone`.**
- `0x46A` and `0x528` appear in *both* error enums under different names
  (`TradeAiDoesntWant`/`DoesntKnowWhatToDoWithThat`,
  `FellowshipIsLocked`/`YouCannotOpenLockedFellowship`) — an ACProtocol
  ambiguity, not a client one.

Corroboration: for the 339 codes carrying both a name and a literal message,
**94% share a word between the ACProtocol name and the client's own message
string** (`YouAreTooTiredToDoThat` ↔ "You are too tired to do that!"), which is
independent agreement between the community reference and the binary. Decoding
was validated against six handlers documented elsewhere in these reports
(`0xEA60`→`DispatchUI_Environs`, `0x2EB`, `0x147`, `0x312`, `0x2C7`, `0x13`);
all six resolve correctly.

Three failure cases (`0x24`, `0x48`, `0x49`) display runtime-initialised
`.data` string objects rather than literals, and two (`0x4DE`, `0x4DF`) build
their text from the event payload — so those five have no fixed message.

**Done as a table, deliberately not as a source tree (2026-07-28).** 11.6096 has
no PDB, so its decompilation is entirely `sub_XXXXXX` with no module information.
The name-and-module transplant now exists as
`2015-10 11.6096/docs/symbol_transplant_11.6096.tsv` — one row per 11.6096
function, 36,087 rows:

| | |
|---|---|
| named from the 11.4186 PDB | **34,562** (95.8%) |
| unmapped (no 11.4186 counterpart) | 1,525 |
| ambiguous, COMDAT-folded | 76 (`alt_names` lists the rival names) |

Confidence is recorded per row, not assumed:

- `exact` (9,520) — the relocation-normalised body occurs exactly once in
  11.6096 `.text`; unambiguous, and these fix the address map
- `verified` (23,783) — placed by that map, then the normalised bodies compared
  equal at the predicted address
- `predicted` (1,259) — placed by the map onto a real 11.6096 function entry but
  the bodies do not compare equal: mostly tiny relocation-dense CRT thunks where
  masking is imprecise, plus the 46 genuinely changed functions

So **33,303 of the 34,562 names are byte-confirmed**, not inferred from position
alone. Two guards worth keeping if this is ever regenerated: every placement had
to land on a real function entry in the 11.6096 decompilation (that list comes
from Hex-Rays, so it is an independent check), and 226 `exact` matches that
landed somewhere that is *not* a function entry were dropped rather than snapped
to the nearest one. All 11 known 11.6096 anchors above resolve to the correct
name and owning `.obj`.

A full 11.6096 source tree was generated from this and then **discarded on
request** — the table is wanted, the mirrored tree is not. Do not regenerate the
tree; if it is ever needed, the mapping table plus the 2013
`split_acclient.py` is all that is required.

**Partially done.** 25 named globals in `acclient_data.h` are typed `_UNKNOWN`;
about a third were recovered by reading bytes and measuring symbol spacing. The
rest are unresolved.

---

## User context

The user runs **roughly 15 clients concurrently** and cares about memory
footprint (observed 550–650 MB each) more than visuals or frame rate. That
framing matters for prioritisation: the palette leak (~19 MB/hr/client) and draw
distance and DAT freelist caps are the levers that matter; Direct3D 11 migration
is not, and was assessed and advised against for their purposes.

They push back on unsupported claims and asked explicitly for type assumptions to
be removed rather than papered over. Match that standard.

---

## Environment notes

`python3` and `objdump` are available. **No `capstone`, no `pip`.** Disassemble
with:

```
objdump -D -b binary -m i386 -M intel --adjust-vma=0xVA slice.bin
```

Beware `objdump` output formatting when pattern-matching: `call   0x5de034` has
multiple spaces, so `t.startswith('call 0x')` silently fails. This produced a
false "this function makes no calls" conclusion once. Normalise whitespace first.

Paths contain spaces — quote them.
