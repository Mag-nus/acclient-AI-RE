# `reference/` — third-party enum names

`protocol_enums.tsv` maps numeric constants you meet while reading the
decompilation onto human names: property IDs, message opcodes, command IDs,
skills, spells, weenie errors, and 118 other enumerations.

**5,065 values across 124 enums.**

```
enum          value_dec  value_hex  name                    base
PropertyInt   390        0x186      Enlightenment           dec
GameEvent     4          0x4        Communication_PopUpString  hex
Command       271        0x10F      NextMonster             hex
WeenieError   1377       0x561      MaxFriendsExceeded      hex
```

## Provenance, and how far to trust it

This is **not** derived from the binary. It is a normalised copy of the community
protocol definition at `github.com/ACClientLib/ACProtocol` (itself based on
zegeger's `messages.xml` and ACE enum work). It is a useful naming aid and
nothing more — where it disagrees with the binary, **the binary wins**.

That said, the overlap that *has* been checked against `acclient.exe` came out
exact:

- **19 of 19** `PropertyInt` IDs recovered by disassembling the appraisal code
  matched named entries — the ten 2013 gear ratings `0x172`–`0x17B`
  (`GearDamage` … `GearMaxHealth`), the four PK-damage and four Overpower
  properties added in 2015, and `Enlightenment` at `0x186`.
- **9 of 9** message opcodes matched, including `0xF7DE` appearing in *both* the
  client-to-server and server-to-client enums, which independently confirms that
  Turbine Chat is tunnelled over the game link rather than using a separate
  service.
- `Command` values matched the client's ordinals exactly once the `0x09000000`
  namespace prefix is removed — `NextMonster` `0x10F`, `SideBySideVitals`
  `0x15E`.

Everything else — roughly 5,030 values — is **unverified** against this binary.

## The notation trap, and what was done about it

The source file writes some enums with an `0x` prefix but **decimal digits**.
`value="0x390"` in `PropertyInt` means property **390**, which is `0x186`. Across
its 390 `PropertyInt` entries not one contains a hex digit `A`–`F`, which is
impossible if they were genuinely hex. Other enums — `Command`, `GameEvent`,
`S2CMessage`, `WeenieError` — really are hex.

Read naively, the file appears to contradict the binary. Read correctly, it
agrees exactly.

`protocol_enums.tsv` resolves this once, so both columns are true numbers. The
`base` column records how each enum was classified:

| `base` | Enums | Basis |
|---|---|---|
| `hex` | 75 | contains `A`–`F`, or both readings coincide |
| `hex (mask attr)` | 22 | marked `mask="true"` in the source |
| `dec` | 13 | ≥20 values, none containing `A`–`F` — statistically conclusive |
| `hex (power-of-two)` | 6 | every value a power of two, i.e. a bitmask |
| `dec (unverified)` | 8 | too small to decide; **treat with suspicion** |

The eight undecidable ones are `ArmorType`, `EnchantmentMask`, `EndTradeReason`,
`FragmentGroup`, `NetAuthType`, `RadarColor`, `WeaponType` and
`WieldRequirement`. For those, check the value against the binary before relying
on it.

## Where it disagrees with the 2015 binary

Checked wherever the client carries something extractable — a complete name→ID
table, or a switch bound. **Every disagreement found points the same way: the
client-side enums describe the 2013 client, not the 2015 one.**

### `Command` — 136 IDs wrong, 4 missing, 1 stale

The client carries a full name→ID table (`string2command`, 408 entries in 2013,
412 in 2015), so this comparison is complete rather than sampled. Against the
XML's 408 `Command` values, on the 404 names present in both:

| | |
|---|---|
| IDs agree | 268 |
| **IDs disagree** | **136 — every one by exactly +3** |
| In XML, not in 2015 client | `SideBySideVitals` (replaced by `StretchUI`) |
| In 2015 client, not in XML | `SkillHealOther`, `CombatEat`, `CombatDrink`, `AI_TelegraphCast` |

The +3 is the enum shift caused by inserting those three motion commands at
ordinal `0x10F`; the XML predates it. `NextMonster` is `0x10F` in the XML and
`0x112` in the 2015 client.

Three further differences are cosmetic, not semantic: the XML spells `Magic` as
`Magi`, and `2HandedStaffCombat`/`2HandedSwordCombat` as
`TwoHandedStaffCombat`/`TwoHandedSwordCombat`.

### `EmoteType` — 6 values short

The XML is complete and contiguous, `0x00`–`0x79`, no gaps. `Emote::IsValid`
bounds-checks `cmp eax,0x79` in the 2013 client — an exact match — and
**`cmp eax,0x7F` in 2015**. Types `0x7A`–`0x7F` are undocumented. (`Emote::pack_size`
switches on `type-1` and moves `0x78` → `0x7E`, consistent.)

### `EmoteCategory` — 1 value short

XML tops out at `0x26`. `EmoteSet::pack_size` bounds `cmp eax,0x25` in 2013 and
**`0x26` in 2015**, i.e. a category `0x27` the XML does not list.

### `GameEvent` — 2 opcodes short

XML tops out at `0x315`. The 2015 client dispatches **`0x317` and `0x318`**, each
routed by a new 160-byte handler into the existing transient-string and pop-up-string
paths.

### `PropertyInt` — no disagreement found

Notably, this one *is* current: it carries `PKDamageRating` (381),
`GearPKDamageRating` (383), `Overpower` (386), `GearOverpower` (388) and
`Enlightenment` (390) — all of them 2015 additions, all matching the binary.

### Why the split

The reference is assembled from several sources, including ACE (a server
emulator). A server needs current *property* IDs but has no use for the client's
keybinding command table, emote type enum or UI event opcodes. So the
server-facing enums are up to date and the client-facing ones are frozen at the
2013 client. Treat `Command`, `EmoteType`, `EmoteCategory` and `GameEvent` as
**pre-2015** unless you have checked the value yourself.

### Coverage limits

This comparison is only as complete as what the binary makes extractable.
`Command` is exhaustive because of the static table; `EmoteType`, `EmoteCategory`
and `GameEvent` are bounds and spot checks. `WeenieError`, `GameAction`,
`S2CMessage` and the rest of `PropertyInt` would require decoding jump tables in
`HandleFailureEvent` and `ProcessNetBlobData`, which has not been done — absence
of a reported disagreement there is **not** evidence of agreement.

## Regenerating

Fetch `protocol.xml` from the repository above and re-run the normaliser
described in this file's history; the classification rules are the table above.
Nothing in `src/` or `include/` depends on this directory — it is a lookup aid,
deliberately kept out of the include chain so that unverified third-party data
can never leak into the extracted code.
