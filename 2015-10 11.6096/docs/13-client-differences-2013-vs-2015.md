# What Changed Between the 2013 and 2015 Clients

**11.4186 (September 2013) vs 11.6096 (2015).**

Both `acclient.exe` binaries are present, so this is a byte-level comparison of
shipped code, not a comparison of decompiler output. That distinction turns out
to matter enormously: the two decompilations *look* very different, and almost
all of that difference is an artifact.

---

## 0. Verdict

**Only 46 functions changed between the two builds — over 99.5% of the code is
byte-for-byte identical.** (The exact percentage depends on how COMDAT-folded
bodies are counted, 99.55%–99.77%; see §7. The 46-function set itself is exact
and independently reproduced.)

Everything else follows from that number. The 2015 client is not a new client. It
is the 2013 client with a small patch applied, and the patch is small enough to
enumerate function by function. All 46 changed functions are listed in §5, and
every one of them is accounted for.

Two themes cover all 46. The first is **content**: a new character-progression
stat (**Enlightenment**, property `0x186`), two new combat ratings (**PK Damage**
and **Overpower**), a "Hear PK Deaths" chat filter, two new network opcodes, six
new emote types, four new motion commands, and the UI, appraisal and
serialisation changes needed to carry all of it. The second is **raised capacity
limits**: friend and squelch lists 50 → 100, house guest table 64 → 128 buckets,
a 256-character cap on outgoing chat, and an allegiance node count widened from
signed 16-bit to unsigned 32-bit with a new 40,000-member ceiling.

Three of the 46 carry no behavioural change at all — two are instruction
scheduling and one is enum renumbering. They differ at byte level and nowhere
else.

That only 46 functions changed across two years is itself the finding: late-era
development was overwhelmingly data-driven, through the server and the DAT files,
and touched the client only where a new enum value, property ID, opcode or
hard-coded limit forced a recompile.

**Practical consequence for the reverse-engineering notes in
`../../2013-09 11.4186/docs/`: they transfer to 11.6096 essentially wholesale.**
Where a document describes an algorithm, a structure layout, a protocol or a file
format, it is describing code that is byte-identical in both builds. Only
addresses need translating (§4), and §6 lists the specific places where a 2013
claim needs a footnote.

---

## 1. Why the naive comparisons are all wrong

This is worth stating up front because four different methods gave four different
answers here, and three of them were badly wrong.

| # | Method | Reported changed | Verdict |
|---|---|---|---|
| 1 | Raw byte comparison of function bodies | 80.7% | Useless — every relocated address differs |
| 2 | Independent normalisation, matched on a 24-byte prefix | 2.7% | Wrong twice over — phase-sensitive, and a prefix match misses interior changes |
| 3 | Lockstep pairwise, full body, seeded with candidate shifts | 3.5% | Wrong — inherits pass 2's false "identical" verdicts |
| 4 | Lockstep pairwise applied to every function | 40.2% | Wrong — fails whenever an address's low byte matches |
| 5 | Relocation table, but rel32 masking still by byte scan | 0.84% | Close, but a missed `call` makes identical functions differ |
| 6 | **Relocation table + instruction boundaries from a disassembler** | **0.41%** | **Correct** |

Passes 2 and 3 were *too permissive* and passes 1, 4 and 5 *too strict*, which is
why the answer bounced around by two orders of magnitude before settling.

The trap in the middle two rows is subtle enough to be worth spelling out.

*Scanning for operands does not work.* If you walk a function looking for `E8`
opcodes and dwords that fall in the image range, then zero them, the walk
desynchronises: masking a 4-byte operand can swallow the opcode byte that
follows. Two identical functions then normalise differently and compare unequal.
This produced hundreds of false differences, including
`ACCWeenieObject::~ACCWeenieObject`, which disassembly shows to be
instruction-for-instruction identical.

*Comparing two candidates in lockstep does not fix it.* Walk both bodies at the
same offset and tolerate a difference only where both sides hold an in-image
address, and you fail whenever the low byte of an address happens to match. The
first *differing* byte is then at operand offset 1, 2 or 3, the dword read there
is garbage, and an identical function is rejected. `ObjectBeingDeleted` failed
this test despite being byte-identical.

**Only the PE relocation table is authoritative about which bytes are
addresses.** `.reloc` names every absolute-address dword exactly. Combine that
with instruction boundaries taken from an actual disassembler — not a byte
scanner — to mask `call`/`jmp`/`jcc` rel32 displacements, and the ambiguity
disappears. That is the method behind every number in this document.

Two independent analyses converged on the same answer using this approach,
which is the main reason to trust it.

---

## 2. The two binaries

| Property | 11.4186 | 11.6096 |
|---|---|---|
| File size | 4,837,376 (`0x49D000`) | 4,841,472 (`0x49E000`) |
| MD5 | `2e30cd620b26f9787b4e6a6257a9e581` | `116d9a66a70b6af449dc3a28d82f2f6d` |
| Linker timestamp | 2013-09-06 00:17 UTC | 2015-06-12 08:16 UTC |
| `FileVersion` | `00.00.11.4186` | `00.00.11.6096` |
| ImageBase | `0x00400000` | `0x00400000` |
| `DllCharacteristics` | `0x0000` (no ASLR, no DEP) | `0x0000` (no ASLR, no DEP) |
| `CheckSum` | `0x0049D162` | `0x004A60C3` |
| PDB GUID / age | `9E847E2F-777C-4BD9-886C22256BB87F32` / 1 | `08E25C14-E2A1-46D5-B05692B2E43A7234` / 1 |
| **PDB build root** | **`d:\ac1_sep13\`** | **`d:\ac1_acxp\`** |
| PDB shipped? | **yes** (29.6 MB, full symbols + line info) | **no** |
| Base relocations | 142,836 | 142,909 (+73) |

The build-root change from `ac1_sep13` to **`ac1_acxp`** is the clearest
provenance signal in either file: a dated branch replaced by a named one.

### Sections

| Section | 11.4186 vsize | 11.6096 vsize | Δ |
|---|---|---|---|
| `.text` | 3,739,088 | 3,742,944 | **+3,856 (+0.10%)** |
| `.rdata` | 488,358 | 488,798 | +440 |
| `.data` | 1,030,100 | 1,030,100 | **0** |
| `.data1` | 7,072 | 7,072 | **0** |
| `.rsrc` | 47,880 | 47,880 | **0** |
| `.reloc` | 357,206 | 357,376 | +170 |

`.text` grew by under four kilobytes across two years. `.rsrc` is the same size
and **differs in only 37 of 49,152 bytes** — that is the version string
`11.4186` → `11.6096` and nothing else. No icons, dialogs, manifests or menus
changed.

### Imports

**The import tables are identical**: 18 DLLs, 372 imported functions, same names
in the same order in both builds. No new OS API is used, no dependency was added
or dropped, and nothing was migrated to a different library.

### Strings — the whole change set in one table

An independent check that needs no function matching at all: extract every
word-like string from `.rdata` and `.data` in both images and diff the sets.
Out of 4,545 ASCII strings, **16 were added and 3 removed.**

| | String |
|---|---|
| **added** | `ENLIGHTENMENT` |
| **added** | `ID_CharacterInfo_Enlightenment_Tiers` |
| **added** | `Overpower! ` |
| **added** | `Overpower% %d` |
| **added** | `Overpower Reduction% %d` |
| **added** | `PK Dam %d` |
| **added** | `PK Dam Resist %d` |
| **added** | `ID_PlayerOption_HearPKDeaths` |
| **added** | `ID_PlayerOption_HearPKDeaths_Help` |
| **added** | `[PKDe]` |
| **added** | `AI_TelegraphCast` |
| **added** | `CombatDrink` |
| **added** | `CombatEat` |
| **added** | `SkillHealOther` |
| **added** | `StretchUI` |
| **added** | `d:\ac1_acxp\output\bin\GAME\WIN32\retail\acclient.pdb` |
| **removed** | `SideBySideVitals` |
| **removed** | `d:\ac1_sep13\output\bin\GAME\WIN32\retail\acclient.pdb` |

The wide-character set tells the same story: 860 strings, three real additions —
`Enlightenment:`, `Overpower %`, `PK Dmg/Res` — and no real removals.

Sixteen strings is the entire user-visible surface of two years of change. Four
of the additions are motion or emote names — `AI_TelegraphCast`, `CombatDrink`,
`CombatEat`, `SkillHealOther` — and they are what the `Emote` and `EmoteSet`
serialisation changes carry.

`SideBySideVitals` → `StretchUI` deserves a note, because it is **an option slot
being repurposed, not renamed.** The internal option key in the preference name
table at `0x00804EF4` (2013) / `0x00806080` (2015) changed, but the localisation
string IDs `ID_PlayerOption_SideBySideVitals` and
`ID_PlayerOption_SideBySideVitals_Help` are still present in 11.6096 and were
*not* renamed to match. Anyone reading the string IDs alone would conclude the
option was unchanged.

### A correction that matters for patching

The 11.4186 notes state that file offset equals RVA "for every section". **That
is false in both builds.** It holds for `.text`, `.rdata` and `.data`, but
`.data` has a large BSS tail (raw size `0x2D000` against a virtual size of
`0xFB7D4`), so `.data1`, `.rsrc` and `.reloc` are shifted by −847,872 bytes
(−`0xCF000`) relative to their RVAs. Use the section table for those three. For
code and read-only data — which is where patch sites live — `file offset = VA −
0x400000` is correct in both builds.

---

## 3. What did *not* change

Stating this precisely is more useful than listing the changes, because it is
what licenses reusing the 2013 analysis.

| Area | Functions | Changed |
|---|---|---|
| **Crypto, hashes, checksums, PRNGs** | 27 | **0** |
| DAT container, BTree, disk controller, async cache, `MasterDBMap` | 292 | **0** |
| Rendering core (`RenderDeviceD3D`, `D3DPolyRender`, `ImgTex`, `PView`, `SurfaceWindow`) | 265 | **0** |
| UI framework (`UIElement*`, `UIRegion`, `UIElementManager`, `MediaMachine`) | 710 | **0** |
| Object maintenance (`CObjectMaint`, `ACCObjectMaint`, `ACCWeenieObject`) | 116 | **0** |
| Audio (`SoundManager`, `CSoundTable`, `Ambient`) | 47 | **0** |
| Physics (`CPhysicsObj`, `CTransition`, `CSphere`, `CObjCell`, `CMotionTable`, …) | 354 | 3 — all three in `CMotionInterp`, on jump gating |
| Network (`SharedNet`, `NetPacket`, `NetBlob`, `FlowQueue`, `Indicator`, dispatch) | 199 | 2 — `ClientFlowQueue` ctor and the message dispatcher |

Specific results worth calling out, each verified individually:

- **Every algorithm in `10-crypto-obfuscation.md` is byte-identical.** ISAAC-32,
  the PJW/ELF hash, `CalcChecksum32`, the L'Ecuyer `ran2` PRNG, the packet
  checksum and the spell-formula obfuscation are unchanged. That document
  transfers verbatim.
- `NetPacket::ComputeChecksum` and `NetPacket::AddFrag` are identical — the
  packet-level integrity scheme did not change.
- `ClientNet::HandleTimeSynch` and `SharedNet::SharedNet` are identical — no
  transport or time-sync change.
- **The plugin loader is intact.** `APIManager::Init` is byte-identical and still
  reads `HKLM\SOFTWARE\Microsoft\Microsoft Games\Asheron's Call\1.00\ACPlugin`,
  `LoadLibrary`s it and calls the exported `CreateACPlugin`. The `IAsheronsCall`
  vtable has the same 52 slots in the same order.
- **The DAT type system is unchanged.** `MasterDBMap::InitDBTypeDef_Internal`
  registers the same 50 `DB_TYPE_*` entries with identical directory names, pack
  versions, freelist sizes and flags, and the same 56 file-extension strings.
- **The command line is unchanged.** Both builds register the same nine
  `Client` arguments (`account, debug, host, language, outport, port, prefs,
  rodat, usemem`) and the same seven `gmClient` arguments (`user, create,
  zoneticket, glsticketdirect, glsticket, migrationurl, vgpassword`).
- **The preference system is unchanged** — the same 103-entry UI preference
  table, the same registration calls.
- `CLCache::SetRegion` and `SetLanguageInternal` are identical; the supported
  region and language sets live in the DAT files, not the executable.
- All 24 `gmStatManagementUI` functions are identical, displaced by exactly
  `+0xC90`.

---

## 4. Translating addresses between the builds

There is **no single constant offset.** The shift grows monotonically through
`.text` as the inserted code accumulates — from about `+0x360` at the start to
`+0x1000` at the end — across 471 distinct step values. Measured on the 7,540
functions that match at a unique site, 98.4% of consecutive steps are
non-decreasing.

| 2013 VA range | Dominant delta |
|---|---|
| `0x00401220`–`0x00424AF0` | `+0x0360` |
| `0x00424B70`–`0x00447270` | `+0x01A0` |
| `0x00447330`–`0x00466DB0` | `+0x00E0` |
| `0x00466E60`–`0x00489BF0` | `+0x03C0` |
| `0x00489C40`–`0x004B6000` | `+0x02E0` |
| `0x004B60C0`–`0x004E4B60` | `+0x0BF0` |
| `0x004E4C20`–`0x00509820` | `+0x0C90` |
| `0x00509950`–`0x00527D50` | `+0x0AD0` |
| `0x00527E40`–`0x00546810` | `+0x0D40` |
| `0x00546880`–`0x0056A8F0` | `+0x0C20` |
| `0x0056A950`–`0x0059A890` | `+0x0E30` |
| `0x0059A8E0`–`0x005BB9A0` | `+0x10B0` |
| `0x005BBA40`–`0x00611140` | `+0x0FE0` |
| `0x00611C77`–`0x00687D70` | `+0x1000` |
| `0x00687F40`–`0x006A6650` | `+0x0E20` |
| `0x006A66B0`–`0x006C2750` | `+0x0ED0` |

**Treat this table as a sanity check, not a translation function.** Within any
range the delta varies, and COMDAT reordering relocates individual functions
arbitrarily — `APIManager::IAsheronsCallImpl::GetVendorID` moved from after
`GetPlayerID` to before `MoveItemExternal` with a byte-identical body, and
`PackableList<ContentProfile>::Pack` jumped from `0x6ADA10` to `0x55B4A0`.

**The reliable method is to match the function's bytes.** Take the 11.4186
function, mask its relocated dwords and rel32 displacements using the relocation
table and real instruction boundaries, and search the 11.6096 `.text` for the
result. 87% of functions match at exactly one site; the rest are small bodies
that the linker folded (`__insertion_sort`, thunks, one-line accessors), where
several sites are genuinely interchangeable.

An important side effect of code folding: two functions with different names can
share one address. `DArray<portal_info>::grow` and `DArray<ObjectInfo>::grow`
both resolve to `0x0051ABB0` in 11.6096.

---

## 5. The 46 changed functions

Grouped by what they do rather than by module.

### Enlightenment — a new character-progression stat

Property ID **`0x186` (390)**, absent from 11.4186 entirely (`grep` finds no
occurrence of "Enlightenment" in the 2013 decompilation).

| Function | Change |
|---|---|
| `CACQualities::InqSkill` | Adds Enlightenment to **every** skill, if the skill is at least Trained (`_sac != 1`). Sits *outside* the `if (!raw)` guard, so it is included even in raw skill queries — unlike the pre-existing +5 and specialisation bonuses |
| `CACQualities::InqRunRate` | Adds Enlightenment to the Run skill before `EnchantSkill`, so it is inside the enchantment pipeline rather than bolted on after |
| `CACQualities::InqJumpVelocity` | Same insertion on the Jump skill |
| `CACQualities::InqAttribute2nd` | Adds `2 × Enlightenment` to **Max Health only**; Stamina and Mana are untouched |
| `gmCharacterInfoUI::UpdatePlayerBirthAgeDeaths` | New "Enlightenment tiers" line, gated on `InqInt(0x186) > 0`. New string IDs `ID_CharacterInfo_Enlightenment_Tiers` and `ENLIGHTENMENT` |
| `CharExamineUI::SetAppraiseInfo` | New `Enlightenment:` line on the character appraisal panel |

The underlying movement formulas are *not* changed — `MovementSystem::GetRunRate`
and `GetJumpHeight` are byte-identical. What changed is the skill value fed into
them.

### Two new combat ratings

Following the existing convention of a character-side and a gear-side property
per rating:

| Rating | Character-side | Gear-side |
|---|---|---|
| PK Damage / PK Damage Resist | `0x17D` `PKDamageRating` / `0x17E` `PKDamageResistRating` | `0x17F` `GearPKDamageRating` / `0x180` `GearPKDamageResistRating` |
| Overpower / Overpower Reduction | `0x182` `Overpower` / `0x183` `OverpowerResist` | `0x184` `GearOverpower` / `0x185` `GearOverpowerResist` |

and Enlightenment is `0x186` `Enlightenment`. The ten pre-existing gear ratings
are `0x172`–`0x17B`: `GearDamage`, `GearDamageResist`, `GearCrit`,
`GearCritResist`, `GearCritDamage`, `GearCritDamageResist`, `GearHealingBoost`,
`GearNetherResist`, `GearLifeResist`, `GearMaxHealth`.

Those names come from the community protocol reference at
`github.com/ACClientLib/ACProtocol`, and they corroborate this analysis
independently: **all 19 IDs extracted from the binary map one-to-one onto named
`PropertyInt` entries**, and the naming confirms the character-side / gear-side
split inferred here — the bare names are character properties and the `Gear*`
forms are the item-side equivalents.

> **Notation trap in that reference.** Its `Property*` enums write values with an
> `0x` prefix but **decimal digits**: `value="0x390"` means property **390**,
> which is `0x186`. Across 390 `PropertyInt` entries not one contains a hex digit
> `A`–`F`, which would be impossible if they were genuinely hex. Other enums in
> the same file — `Command`, `GameEvent`, `S2CMessage`, `WeenieError` — *are*
> real hex. Read naively the two conventions appear to contradict the binary;
> read correctly they agree exactly.

| Function | Change |
|---|---|
| `ItemExamineUI::Appraisal_ShowRatings` | Ten gear ratings become fourteen. New lines `"PK Dam %d"`, `"PK Dam Resist %d"`, `"Overpower% %d"`, `"Overpower Reduction% %d"`, inserted between Crit Dam Resist and Heal Boost |
| `CreatureExamineUI::SetAppraiseInfo` | Nine properties become thirteen; new `Overpower %` and `PK Dmg/Res` lines |
| `CharExamineUI::SetAppraiseInfo` | Same four ratings on the character panel |
| `ClientCombatSystem::HandleAttackerNotificationEvent` | New `attack_conditions & 8` → `"Overpower! "`, joining the existing `& 4` "Sneak Attack!" and `& 2` "Recklessness!" |
| `ClientCombatSystem::HandleDefenderNotificationEvent` | Same |
| `ItemExamineUI::Appraisal_ShowSpecialProperties` | **Not a behavioural change** — same size, same 1,024 instructions, two adjacent `mov`s reordered by the scheduler. It is listed here only because it is one of the 46 that differ at byte level |

The existing ratings (damage, damage reduction, crit, crit damage, crit resist,
crit damage resist, healing boost, nether resist, life resist, Vitality) are
unchanged in ID, order and format string.

**All of these IDs are confirmed directly in the binaries**, not inferred from
decompiler output — which matters, because IDA typed the property-ID parameter of
`AppraisalProfile::Inq*` as `char` in the 2015 database and therefore prints only
the low byte of every ID. Disassembling the two builds and extracting the
property-ID immediates gives:

```
ItemExamineUI::Appraisal_ShowRatings
  2013:  172 173 174 175 176 177 178 179 17A 17B
  2015:  172 173 174 175 176 177 178 179 17A 17B  +17F +180 +184 +185
CreatureExamineUI::SetAppraiseInfo
  2013:  133 134 139 13A 13B 13C 143 15E 15F
  2015:  133 134 139 13A 13B 13C 143 15E 15F      +17D +17E +182 +183
CACQualities::InqRunRate
  2013:  146 158 16D
  2015:  146 158 16D                              +186
```

Nothing was removed in any of them.

### Two new network opcodes

| Function | Change |
|---|---|
| `UIQueueManager::ProcessNetBlobData` | Dispatches **164** server→client message IDs, up from 162. Added `0x317` and `0x318`; nothing removed. The top-level pivot moves from `cmp edx,0x276` to `cmp edx,0x27A` |

Each new opcode carries a single string payload and is routed by a new 160-byte
dispatcher — `0x006A56F0` → `Handle_Communication__TransientString`, and
`0x006A5790` → `Handle_Communication__PopUpString`. Both target handlers are
themselves byte-identical to 11.4186, so this is new plumbing into existing
display paths, not a new message format.

Confirmed directly in the binaries: the instruction `cmp eax,0x317` occurs
**exactly once** in 11.6096 and **zero times** in 11.4186, and likewise for
`0x318`. The two dispatchers are also the only functions in this comparison known
to exist in 11.6096 with no 11.4186 counterpart at all.

**Neither opcode appears in the community protocol reference.** Its `GameEvent`
enum tops out at `0x315` (`Social_SendClientContractTracker`), with `0x312`
`Magic_PurgeBadEnchantments` and `0x314` `Social_SendClientContractTrackerTable`
just below. So `0x317` and `0x318` are beyond everything that reference
documents — consistent with their being genuinely new in this build.

That also explains a mislabel noted earlier: BinDiff named the 2015 `0x318`
dispatcher `CM_Magic::DispatchUI_PurgeBadEnchantments`, which is the handler for
`GameEvent 0x312`. It matched the new function to its nearest documented
neighbour. The name is wrong; the function is a string dispatcher.

### Constructor signature change

| Function | Change |
|---|---|
| `Client::Client` | Ends `ret 4` instead of `ret`. The preceding 491 bytes are byte-identical |
| `gmClient::gmClient` | Gained a `push 0` before the call |

The argument is never read. This is the signature of MSVC's hidden
most-derived-object flag appearing on a constructor — a change in the `Client`
class hierarchy, or simply a different compiler version. **Behaviourally inert as
compiled.** Note that neither 2015 decompilation handled `Client::Client`; IDA
left it as `_UNKNOWN loc_412E50`, so it is invisible if you only read the `.c`
files.

### Chat, filtering and social lists

| Function | Change |
|---|---|
| `ClientCommunicationSystem::IsMessageSafe` | **New length gate as the first statement:** `if (len > 0x100) return 0`. Any outgoing chat message of 256 characters or more is now classified unsafe and silently dropped. The existing `<tell:` and newline injection checks are unchanged, and callers are unchanged — the check was genuinely added to the callee |
| `ClientCommunicationSystem::Handle_Communication__TextboxString` | **New `[PKDe]` PK-death filter.** The handler now searches the incoming string for the literal `[PKDe]`. If present and the new "Hear PK Deaths" option is **off**, the message is dropped entirely; if on, the tag is stripped and the message falls through to the unchanged squelch/display path |
| `gmFriendsUI::Request_AddFriend`, `gmFriendsUI::UpdateButtons`, `gmFriendsUI::ListenToElementMessage`, `gmSquelchUI::UpdateButtons`, `gmSquelchUI::ListenToElementMessage` | **Friend and squelch list cap raised from 50 to 100** — the constant `0x32` becomes `0x64` at all five sites and nowhere else in either binary. The Add-Friend and Squelch buttons stay enabled to 100 entries; the refusal error (`0x561`) and its text are unchanged |

The "Hear PK Deaths" option is **option index `0x34` (52)** — 11.4186 has 52
options (`0x00`–`0x33`, contiguous), 11.6096 has 53. It lives in
`PlayerModule::options2_` (`this+0x90`, *not* `options_` at `this+0x8C`) at
**bit 25**, mask `0x02000000`, with a new accessor pair at `0x005D4740` (get) and
`0x005D4750` (set). It is registered as
`PlayerOptionPage::AddToggleOption(…, 0x34)` immediately after `HearSocietyChat`
(`0x2E`), which is where 11.4186's list ends — so it is a chat-channel filter.
This is the same option visible as the jump-table bound moving from
`cmp eax,0x33` to `cmp eax,0x34` in `CPlayerModule::IsAutoSaveOption`, and it is
why `PlayerModule::GetOption`, `SetOption`, `UnPack` and
`gmCharacterSettingsUI::InitOptions` all changed.

**It defaults to on.** Both `PlayerModule::PlayerModule` and
`PlayerModule::UnPack` initialise `options2_` to `0x00948700` in 11.4186 and
`0x02948700` in 11.6096 — that single bit is the only difference in either
function. The constant `0x00948700` occurs exactly twice in the 2013 image and
zero times in the 2015 image, and `0x02948700` exactly the reverse.

Worth recording explicitly, because it is the most likely thing to be assumed
wrongly: **the slash-command table did not change.**
`ClientCommunicationSystem::InitializeCommands` registers exactly the same 116
commands in the same order bound to the same handler and help pairs in both
builds, and `StartupTurbineChatSystem` registers the same 15 Turbine-chat
commands. `HandleFailureEvent` has exactly the same 339 case labels with the
same message strings and the same output routing. All three byte-differ only
because they are almost entirely string and function-pointer immediates, every
one of which moved.

### Remaining changed functions

Confirmed changed at byte level, and consistent with the string additions in §2:
`Emote::IsValid`, `Emote::Pack`, `Emote::UnPack`, `Emote::pack_size`,
`EmoteSet::Pack`, `EmoteSet::UnPack`, `EmoteSet::pack_size` carry the four new
motion or emote names (`AI_TelegraphCast`, `CombatDrink`, `CombatEat`,
`SkillHealOther`).

`CMotionInterp::motion_allows_jump`, `CMotionInterp::jump_charge_is_allowed` and
`CMotionInterp::charge_jump` change which motion states permit a jump. The
comparison sets, read directly out of both binaries:

| Allowed motion IDs | 11.4186 | 11.6096 |
|---|---|---|
| exact | `0x40000008` | `0x40000008` |
| range | `0x40000016`–`0x40000018` | same |
| range | `0x4000001E`–`0x40000039` | same |
| range | `0x41000012`–`0x41000014` | same |
| range | `0x1000006F`–`0x10000078` | same |
| range | `0x10000128`–`0x10000131` | **`0x1000012B`–`0x10000134`** |
| exact | — | **`0x10000057` (new)** |
| exact | — | **`0x1000019B` (new)** |

**That shifted range is the most informative single fact in the comparison.** The
window did not widen or narrow — it moved by exactly three, which is what happens
when three entries are inserted earlier in the same command enum.

The root cause is visible directly in `string2command`, whose table bound goes
from `0x198` (408) to `0x19C` (412). Dumping both name/ID tables
(`0x00803DF0`/`0x00804450` in 2013, `0x00804F48`/`0x008055B8` in 2015) gives the
whole story:

| | Command | ID |
|---|---|---|
| **added** | `SkillHealOther` | `0x1000010F` |
| **added** | `CombatEat` | `0x10000110` |
| **added** | `CombatDrink` | `0x10000111` |
| **added** | `AI_TelegraphCast` | `0x1000019B` |
| **added** | `StretchUI` | `0x09000161` |
| **removed** | `SideBySideVitals` | `0x0900015E` |

Three commands inserted at ordinal `0x10F` pushed everything after them along.
Of the 407 commands present in both builds, **271 kept their ID and 136 shifted
by exactly +3** — nothing shifted by any other amount. The boundary is ordinal
`0x10F`, and it spans *both* namespaces: the lowest shifted command is
`NextMonster` at `0x0900010F`, not something in the `0x10xxxxxx` motion range.

`StretchUI` at `0x09000161` is precisely `SideBySideVitals`'s old `0x0900015E`
plus the same +3, confirming that the slot was repurposed rather than a new one
appended.

**Independently corroborated.** The `Command` enum in the community protocol
reference (`github.com/ACClientLib/ACProtocol`) lists `NextMonster` = `0x10F` and
`SideBySideVitals` = `0x15E` — exactly the ordinals recovered here, minus the
`0x09000000` namespace prefix the client carries. That reference contains none of
the four commands added in 2015 (`SkillHealOther`, `CombatEat`, `CombatDrink`,
`AI_TelegraphCast`) and still lists `SideBySideVitals`, so it describes the
pre-shift command set — which is precisely why a tool built against it will be
wrong by three on the 2015 client.

> **This is the one constant in the whole comparison that silently changed
> meaning rather than simply being added.** Any tool that hardcodes a command ID
> with ordinal `0x10F` or higher — in either the `0x09xxxxxx` action namespace or
> the `0x10xxxxxx` motion namespace — will be wrong by three against the 2015
> client.

`CMotionInterp` was recompiled against the new values, which accounts for the
shifted range above. Its two *semantic* additions are that jumping is now also
blocked during `Sanctuary` (`0x10000057`) and `AI_TelegraphCast` (`0x1000019B`),
and that `jump_charge_is_allowed` and `charge_jump` each gained `Sanctuary` as
well.

`ClientCombatSystem::PlayerInReadyPosition` is in the changed list for the same
reason and **has no behavioural change at all** — its accepted motion set is
identical, with `AtlatlCombat` and `ThrownShieldCombat` merely renumbered from
`0x80000138`/`0x80000139` to `0x8000013B`/`0x8000013C`.

### Raised capacity limits — a secondary theme

Separate from the content patch, several hard-coded limits were raised.

| Function | Change |
|---|---|
| `gmFriendsUI` ×3, `gmSquelchUI` ×2 | Friend and squelch caps 50 → 100 (§ above) |
| `ClientCommunicationSystem::IsMessageSafe` | New 256-character outgoing message cap (§ above) |
| `HAR::HAR` | House access-rights guest hash table initial bucket count **64 → 128**. The only change in the function |
| `AllegianceHierarchy::UnPack` | The packed node count is the low 16 bits of the header dword. The loop that consumes it changed from **signed 16-bit** (`cmp WORD PTR [esp+0x14],bp` / `jle`) to **unsigned 32-bit** (`test eax,eax` / `jbe`). Previously a hierarchy with 32,768–65,535 nodes was read as a negative count and silently unpacked as **zero** nodes; it now unpacks correctly |
| `AllegianceHierarchy::Add` | The validity chain was factored into a new helper that adds one condition: `m_total <= 40000` (`0x9C40`). Adding beyond **40,000 members** now fails. This is why the count needed to become unsigned |
| `ClientFlowQueue::ClientFlowQueue` | `CurLocalInterval_.FlowLevel_` initialised **10 → 1**; everything else in the constructor is unchanged |

### The rest

| Function | Change |
|---|---|
| `PlayerModule::GetOption` / `SetOption` / `UnPack` / ctor, `CPlayerModule::IsAutoSaveOption`, `gmCharacterSettingsUI::InitOptions` | The new "Hear PK Deaths" option — 52 options become 53. See above |
| `CPlayerSystem::OnAction` | Jump-table bound `0x114` → `0x115`; exactly one new case, action `0x1000013F`, which toggles the new option. All 75 pre-existing cases unchanged |
| `Emote::IsValid` / `Pack` / `UnPack` / `pack_size` | Emote type enum grows from **1–0x79 (121)** to **1–0x7F (127)** — six new types, `0x7A`–`0x7F`. The `Emote` struct layout is unchanged; the new types reuse existing payload shapes (string-only, string plus two dwords, or header-only) |
| `EmoteSet::Pack` / `UnPack` / `pack_size` | Category enum maximum **0x26 (38) → 0x27 (39)**. The new category packs the existing `style`/`substyle` dword pair — no new field |
| `gmSpewBoxUI::Update` | Each spew line now gets an extra call setting an `RGBAColor` master property to `{1.0, 1.0, 0.0, 1.0}` — **spew-box text is forced to opaque yellow** |
| `string2command` | Table bound `0x198` → `0x19C`; the command table changes above |
| `CPlayerSystem::Handle_PlayerDescription` | **No semantic change.** 179 instructions in both builds; the only differences are two swapped operand loads and `lea esi,[eax+ecx]` versus `lea esi,[ecx+eax]`. No new field is unpacked |

Three of the 46 therefore carry **no behavioural change whatsoever** —
`Handle_PlayerDescription` and `Appraisal_ShowSpecialProperties` are pure
instruction scheduling, and `PlayerInReadyPosition` is pure enum renumbering.
They differ at byte level and nowhere else.

---

## 6. Where the 2013 notes need a footnote

Only three items in `../../2013-09 11.4186/docs/` need qualifying, and two of them
are corrections to the 2013 document itself rather than 2013-vs-2015 differences.

**`11-memory-leak-investigation.md` §8b — the vtable labels are inverted.**
`0x007E3EA0` is the vptr written at `object+0` (the `ACCWeenieObject` vtable,
slot 1 = `ObjectBeingDeleted`); `0x007E3E88` is the `NoticeRegistrar` base
sub-object vptr at `object+0xC` (slot 1 = `RegisterNoticeHandler`). The report
calls the first "secondary" and the second "primary". The practical warning it
gives is still correct and still important. Details and the 11.6096 equivalents
are in `12-memory-leak-2015.md` §3.

**`11-memory-leak-investigation.md` §8b — "file offset == RVA for every
section" is false.** It holds for `.text`, `.rdata` and `.data` only. See §2
above.

**`04-combat-magic.md` and `03-object-model.md`** describe the rating and
property sets as of 2013. Four rating properties and one progression stat were
added in 2015 (§5). No existing property changed ID or meaning.

**`01-physics.md` and `05-ui.md` — command IDs at ordinal `0x10F` or above
shifted by +3.** Three commands were inserted at that ordinal, so **136 of the
407 shared command IDs name a different command in 11.6096**, across both the
`0x09xxxxxx` action namespace and the `0x10xxxxxx` motion namespace. The lowest
affected is `NextMonster` (`0x0900010F` → `0x09000112`). This is the only
constant in the whole comparison that silently changed meaning rather than being
added; check it against any tool or keybinding table that hardcodes command IDs.

Everything else in `01-physics.md` describes byte-identical code — `CPhysicsObj`,
`CTransition`, `CSequence`, `CObjCell`, `CMotionTable` and the collision
primitives all have zero changed functions.

Everything else — physics, rendering, audio, DAT resources, networking,
cryptography, the client core and the UI framework — describes byte-identical
code and needs no qualification at all.

---

## 7. Provenance

Function inventory comes from the 11.4186 PDB: 16,232 global and 23,716 static
function symbols with exact virtual address, byte length and owning `.obj`.
Functions shorter than 32 bytes were excluded because they fold too aggressively
to identify reliably; they account for roughly 3.5 KB of `.text` between them.

> **The 46 changed functions are verified; the denominator they are quoted
> against is not.** A later re-derivation reproduced the changed set exactly —
> same 46 functions, function for function, via an independent address map and
> relocation-exact masking — and `tools/binary_diff.py` now prints that set. But
> the population figure of **11,127** could not be reproduced under any counting
> rule tried against the PDB:
>
> | Counting rule | Count |
> |---|---|
> | distinct `(VA, length)` procs ≥ 32 bytes | 20,271 |
> | distinct `(VA, length, name)` procs ≥ 32 bytes | 21,287 |
> | distinct bodies after COMDAT folding (relocation-normalised) | 10,183 |
> | distinct names ≥ 32 bytes | 12,798 |
>
> So "11,081 of 11,127 (99.59%)" should be read as **46 changed out of a
> population between roughly 10.2k and 20.3k depending on how folded bodies are
> counted** — 99.55% to 99.77% unchanged. The headline conclusion (only 46
> functions changed in two years) is unaffected; only the percentage's precision
> is. `binary_diff.py` reports 20,271 because that is the population it actually
> enumerates.

There is **no PDB for 11.6096**, so every 11.6096 address in this document was
derived by matching normalised bytes and then confirmed against
`../acclient.c`, the name-stripped decompilation of this exact binary, where the
derived addresses appear as `sub_XXXXXX` entry points.

Two limits on what "identical" means here, stated plainly:

**Call targets are masked.** A function whose only change was calling a different
function would be counted identical. To bound this, every resolvable call edge in
the matched set was checked against the function mapping: of 30,566 edges, 96.9%
land exactly where the mapping predicts. The residual 3.1% is dominated by the
13% of functions whose bodies occur at several sites after code folding, where
the mapping is ambiguous by construction — so 3.1% is an upper bound on genuine
callee changes, not a measurement of them.

**Only 2013-side functions were enumerated.** A function that exists only in
11.6096 cannot appear in this comparison. Two such functions are known from the
opcode analysis (`0x006A56F0` and `0x006A5790`, 160 bytes each). Together with
the growth in the 46 changed functions these account for a few hundred bytes of
the 3,856-byte `.text` increase; the remainder is unattributed and could include
further new functions that no 11.4186 code path calls.
