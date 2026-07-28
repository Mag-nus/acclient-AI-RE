# Combat, Magic, Enchantments, and Skills

Target: acclient.exe 11.4186 (September 2013). Line references are into
`../acclient.c` and `../acclient.h` unless noted.

> **Revision note.** Three passes. The third pass found that the enchantment
> **duel tie-break was stated backwards** (§2) and that the spell-level collision
> claim was wrong (§3), plus roughly twenty citation drifts. Both are corrected.
> Universal negatives are now phrased as "no such path was found" rather than
> "there is none", because grep over one decompilation cannot prove absence.

**Client/server split:** the client owns stances, the power-bar timer, target
selection, animation readiness, and message formatting. Every roll is
server-side. Several client structures that look like game logic are parsed and
never read — see §8.

---

## 1. Attack flow — `ClientCombatSystem`

`ClientCombatSystem` (acclient.h:40640) holds the attack state machine.

### Input

`OnAction` (acclient.c:410072) routes toggle-combat (action `0x1000005A`,
literal 268435546) to `SetCombatMode`, melee/missile to `HandleCombatAction`
(409997), magic to `HandleMagicAction` (407451).

`ATTACK_HEIGHT` (acclient.h:4371): `UNDEF 0`, HIGH 1, MEDIUM 2, LOW 3,
`NUM_ATTACK_HEIGHTS 4`.

Power stepping (acclient.c:410017–410023) clamps **after** the multiply:

```c
clamp((trunc((p + 0.083333336) * 6) ± 1) * 0.16666667, 0.0, 1.0)
```

`+1` for `0x1000005C` / `0x100000F0`, `−1` for `0x1000005B` / `0x100000EF`.
Key release calls `EndAttackRequest(height, -1.0)` (410059).

### The power bar

`GetPowerBarLevel` (body at acclient.c:**407919**) is
`(cur_time − buildStartTime) / T` clamped to [0,1].

`T` is **0.8 s when the interpreted motion style is `0x80000046`**, otherwise
1.0 s (acclient.c:407935 — the comparison is against `-2147483578`, which
unsigned is `0x80000046`; offset `+4` in the interpreted motion state is the
style word).

**`0x80000046` is `DualWieldCombat`, not a bow stance.** See §6. The fast power
bar is the dual-wield bonus.

`UseTime` (409015) auto-fires `ExecuteAttack` at `requestedAttackPower` in
classic UI mode (409034–409045).

### Dispatch

`ExecuteAttack` (acclient.c:408626) checks `ObjectIsAttackable` (407410 — flag
`0x10`, plus a PK `0x200000` test), confirms readiness, then branches on
`combatMode == 2` or `4` (408643–408652). It takes only `(ATTACK_HEIGHT, bool)`
— there is **no power parameter**; it reads `this->requestedAttackPower`.

| Opcode | Action | Function | Opcode written at |
|---|---|---|---|
| `0x08` | `Event_TargetedMeleeAttack` | 706741 | 706771 |
| `0x0A` | `Event_TargetedMissileAttack` | 706849 | 706879 |
| `0x53` | `Event_ChangeCombatMode` | 706641 | 706663 |
| `0x1BF` | `Event_QueryHealth` | 706691 | 706713 |

The missile parameter is named `i_accuracy_level` but receives the same
`requestedAttackPower`.

`Handle_Combat__QueryHealthResponse` (407379) forwards only a health *fraction*.

### The combat maneuver table is inert

`PlayerInReadyPosition` (acclient.c:408485) reads the weapon's `AttackType` int
(stat `0x2F`, default 25 = `Unarmed_AttackType`, acclient.h:3825) at
408525–408527 and loads the table via `CombatManeuverTable::Get` (407721).

An exhaustive grep shows `_cmt`, `min_skill_level`, `attack_type`,
`attack_height`, `style`, and `motion` appear **only** in constructor, destructor,
`Init`, `Pack`, and `UnPack` (acclient.c:501762–502004). The `AttackType` read is
dead. No path derives a motion from `(style, height, attack_type)` — the swing
animation arrives from the server.

Two nuances the earlier drafts missed. There *is* a virtual call on the returned
table at acclient.c:408548, `(*(...)(*(_DWORD *)v9 + 20))(v9)`; vtable offset +20
matches `DBObj::Release` by pattern (same shape at 79615, 445942, 446054,
446109, 404166), so it is a refcount drop rather than a data read — **an
inference from the vtable slot, not a read symbol**. And the
`_considerAttackingReady == true` path (408540–408545) returns *without*
releasing, a genuine reference leak.

### Combat modes

`COMBAT_MODE` (acclient.h:3730): NonCombat 1, Melee 2, Missile 4, Magic 8,
`VALID 0xF`, `COMBAT 0xE`. `CombatEnumMapper::CombatModeToString`
(acclient.c:500918) gives peace / melee / missile / magic.

`SetCombatMode` (408787) validates via `CompatibleCombatMode` (407386) against
the inventory mask — bit 22 missile, bit 24 caster, bits 20/25 melee, plus an
additional `inventoryMask & 0x3500000` guard at 407402 — blocks changes in portal
space, defers via `pendingCombatMode`, sends `0x53`, and runs `AutoTarget`
(408690), which reselects your last attacker if attacked within 15 seconds.

`GetDefaultCombatMode` (408230): location mask `0x2500000` → melee,
`0x1000000` held caster → magic.

Missile readiness hardcodes styles `0x8000003F`, `0x80000041`, `0x80000043`,
`0x80000047`, `0x80000138` (Atlatl), `0x80000139` (ThrownShield) at
acclient.c:**408576–408577**, against ready-state `0x41000003` (acclient.c:40408 /
43458).

---

## 2. The enchantment registry

`Enchantment` (acclient.h:37406) is `{_id, m_SpellSetID, _spell_category,
_power_level, _start_time, _duration, _caster, _degrade_modifier, _degrade_limit,
_last_time_degraded, StatMod _smod}`; `StatMod` is `{type, key, val}`
(acclient.h:**37398**).

`CEnchantmentRegistry` (acclient.h:37438) keeps `_mult_list`, `_add_list`,
`_cooldown_list`, `_vitae`, and helpful/harmful counters. `Pack`
(acclient.c:445042) writes a presence mask `1 mult | 2 add | 4 vitae |
8 cooldown` (445056–445065).

### EnchantmentTypeEnum — read the header, not the immediates

acclient.h:3163–3187:

| Value | Name | Value | Name |
|---|---|---|---|
| `0x1` | Attribute | `0x2000` | MultipleStat |
| `0x2` | SecondAtt | `0x4000` | Multiplicative |
| `0x4` | Int | `0x8000` | Additive |
| `0x8` | Float | `0x10000` | AttackSkills |
| `0x10` | Skill | `0x20000` | DefenseSkills |
| `0x20` | BodyDamageValue | `0x100000` | Multiplicative_Degrade |
| `0x40` | BodyDamageVariance | `0x200000` | Additive_Degrade |
| `0x80` | BodyArmorValue | **`0x800000`** | **Vitae** |
| `0xFF` | StatTypes (mask) | `0x1000000` | Cooldown |
| `0x1000` | SingleStat | `0x2000000` | Beneficial |

**The vitae bit is `0x800000`.** An early draft had `0x8000000`, fooled by
Hex-Rays substituting a string literal for the immediate. The runtime test is at
**acclient.c:445367**; 445372 and 445377 are the mult/add tests and 445369/445382
are the cooldown tests.

The same substituted literal appears at acclient.c:221881 tested against
`_location` in a block setting `ammoReadySlot`, between `_location & 0x200000`
(shield) and `& 0x40` — and `MISSILE_AMMO_LOC = 0x800000` (acclient.h:3219).
`SLEDDING_PS = 0x800000` (acclient.h:2840) is the same immediate again.

`Beneficial_EnchantmentType` drives `PurgeBadEnchantmentList`
(acclient.c:446299), which skips `type & 0x2000000` or `_duration == −1.0`.

### Storage and stacking

`UpdateEnchantment` (445354) routes by `_smod.type`.
`AttemptToReplaceSpellInList` (body 445244; the `0xFFFF` test at 445253)
overwrites any entry sharing the low 16 bits of the spell ID with a positive
duration, and is invoked from inside `AddEnchantmentToList` (445324, call at
445338).

`UpdateSpellTotals` (445193) classifies from `CSpellBase::_bitfield & 4`
(445214); IDs ≥ `0x8000` skip totals (445202). Nothing in the binary names that
range, so the "layered/set spells" reading is unverified.

### Category dueling — the tie-break runs the other way

`CullEnchantmentsFromList` (acclient.c:445810) selects by stat class. Pairing the
classes to their call sites explicitly, because class order and line order differ:

| Class | Call site |
|---|---|
| 1 attribute | 445888 |
| 2 vital | 445955 |
| `0x10` skill | **446007** |
| 4 int | **446063** |
| 8 float | 446118 |

Plus MultipleStat `0x2000` (445826), AttackSkills `0x10000` (502471), and
DefenseSkills `0x20000` (502503). `AffectsAttackSkills` (502475–502483) lists
33, 34, 41, 43, 44, 45, 46, 47, 49; `AffectsDefenseSkills` (502507–502510) lists
6, 7, 15, 48.

Within a `_spell_category` (445688), `Enchantment::Duel` (body
acclient.c:**502375**) decides. Its return at 502382 is:

```c
return v2 > v3 || v2 == v3 && challenger->_start_time < this->_start_time;
```

`this` is the incumbent. It survives a power tie when the *challenger started
earlier* — so **on equal power the enchantment with the LATER `_start_time`
wins**, not the earlier. An earlier draft of this document stated the reverse.
Confirmed identically in the 6.95 decompilation (496498) and the 2015 build
(499960). `CEnchantmentRegistry::Duel` (445690) drops the challenger only when
this returns true, so re-casting at equal power does displace the incumbent —
consistent with the observed "recast refreshes" behaviour.

### Application

`Enchantment::Enchant` (502386) adds or multiplies.

- `EnchantAttribute` (445904–445912) floors at 10, or 1 if base < 10, and applies
  **no** vitae
- `EnchantAttribute2nd` (445960–445968) applies vitae first (445946–445949), then
  floors at 5 — or at 1 when the value is under 5
- `EnchantSkill` applies vitae first, floors at 0 via `if (tmp <= 0.5) tmp = 0.0`
  (446023)

`EnchantedQualityDetails` (502413) splits increasing from decreasing factors for
UI colouring. Vitae is spell ID **666** (445426; 405118 appends " penalty").
`OnCooldown` (445770–445775) self-prunes.

---

## 3. Magic

`CSpellBase` (acclient.h:39434) carries `_school`, `_category`, `_bitfield`,
`_base_mana`, `_mana_mod`, `_power`, `_spell_economy_mod`, `_formula_version`,
`_component_loss`, a `SpellFormula` of `_comps[8]`, PScripts, and recovery
fields. `_category` and `_power` are dead — init, pack, and unpack only.

### `_bitfield` is `enum SpellIndex`

acclient.h:3568–3589: `Resistable 0x1`, `PKSensitive 0x2`, `Beneficial 0x4`,
`SelfTargeted 0x8`, `Reversed 0x10`, `NotIndoor 0x20`, `NotOutdoor 0x40`,
`NotResearchable 0x80`, `Projectile 0x100`, `CreatureSpell 0x200`,
`ExcludedFromItemDescriptions 0x400`, `IgnoresManaConversion 0x800`,
`NonTrackingProjectile 0x1000`, `FellowshipSpell 0x2000`, `FastCast 0x4000`,
`IndoorLongRange 0x8000`, `DamageOverTime 0x10000`.

A grep of every `CSpellBase::_bitfield` site finds readers for only four: `0x4`
(235475, 445214), `0x8` (248523, 404169, 404732), `0x10` (404152), and `0x2000`
(404158, as `BYTE1 & 0x20`). **`DamageOverTime` has no reader** — no client-side
damage-over-time machinery was found. `CSpellBase::IsUntargeted` (449226) is
formula-based, not bitfield-based.

### School

No `MAGIC_SCHOOL` enum exists; `SchoolOfMagic` is a typedef (acclient.h:61688).
`SchoolEnumToName` (449184): 1 War, 2 Life, 3 Item Enchantment, 4 Creature
Enchantment, 5 Void. `InqSkillForSpell` (448600) maps 1→34, 2→33, 3→32, 4→31,
5→43.

`Enchantment::_spell_category` is a 16-bit field: `Pack` writes
`_spell_category & 0xFFFF | 0x10000` (502596) and `UnPack` reads the low word
(502652), using the high word as an "`m_SpellSetID` present" flag (502680–502684).

### Spell level comes from the scarab

`InqSpellLevelByRoughHeuristic` (acclient.c:449068) at 449074–449080:

```c
if (v2 >= 7) { if (v2 >= 9) v2 -= 2; else --v2; }
```

So 7→6, 8→7, 9→7, 10→8. **The colliding pairs are {6,7}→6 and {8,9}→7** — an
earlier draft said "7 and 9 both map to 7", which is wrong. The range is 1..8.

A useful corollary: because this never returns 9, the `case 9:` arm of
`gmSpellbookUI::IsFilteredOut` (449553 region, function at **198486**) is **dead
code**. That is the real reason the level-9 filter bit is inert — stronger than
"no UI button".

Component power levels are hardcoded in `DeterminePowerLevelOfComponent`
(488433): scarabs 1–6 → 1–6; `0x6E`→7, `0x70`→8, `0xC0`→9, `0xC1`→10. `0x6F` is
omitted here but accepted by `InqScarabOnlyFormula` (448999).

### Formula obfuscation

**(a) At-rest.** `CSpellBase::InqSpellFormula` (body acclient.c:**448869**)
nibble-swaps name and description at 448899 and 448912, covering
`m_len − 1` bytes (`buffer+20` through `buffer+m_len+19`):

```c
c = (c << 4) | (c >> 4);
```

The decrypt key is `hash(name) % 0x12107680 + hash(desc) % 0xBEADCF45` (448932);
`SpellFormula::Decrypt` subtracts it from each nonzero component (487863–487884).

**(b) Per-account.** `GetAppropriateSpellFormula` (404513) checks the per-school
augmentation — **school 1→297, 2→296, 3→295, 4→294, 5→328**
(acclient.c:404557–404575, note the reversed ordering), reads it at 404577, and
takes `InqScarabOnlyFormula` when positive, else checks `MagicPackIsOwned`, else
`InqCustomizedSpellFormula` (448947) → `RandomizeForName`.

- **V1** (487980) seeds `hash % 0x13D573` (488033), rewriting `_comps[1]`, `[3]`,
  `[6]`.
- **V2** (488125–488126) rewrites `[3]` and `[6]`; the `[3]` expression expands
  exactly to `(3*c0 + c1 + c2 + 2*c4*c5 + c7) % 12 + GetLowestTaperID()`.
- **V3** (488138) uses six moduli — `0x13D573` (488189), `0x4AEFD` (488198),
  `0x96A7F` (488207), `0x100A03` (488216), `0xEB2EF` (488225), `0x121E7D`
  (488234) — **plus a seventh, `0x65039`, used raw** in the slot-6 mix as
  `v25 % 0x65039 % 0xC` (488258).

`MagicSystem::GetLowestTaperID()` (function 488477) is literally `return 63;`
at 488479.

### Components

`SpellComponentBase` (acclient.h:40960). `_type` is the word-slot role
(acclient.h:4523): Power 1, Action 2, ConceptPrefix 3, ConceptSuffix 4, Target 5,
Accent 6, Pea 7. `_category` is the item class (acclient.h:3540): Scarab 0,
Herb 1, PowderedGem 2, AlchemicalSubstance 3, Talisman 4, Taper 5, Pea 6,
Undef 8.

**`_gesture` and `_CDM` have no readers** — Pack (486949/486955), ctor
(486971/486974), UnPack (487011/487017), copy-ctor (487309/487314).

`SCIDtoWCID` / `WCIDtoSCID` (487319 / 487279) are `DualEnumIDMap` DAT lookups.
`SpellComponentBase::InqName` (body **487029**, swap at 487046) applies the same
nibble-swap transform as spell names — written inline in both places, not a
shared routine.

### ComponentTracker

`ComponentTracker` (acclient.h:41211) holds seven `DLList<ComponentData>`
(`componentLists[7]`, acclient.h:41212) plus an objectID→wcid hash and an
owned-wcid set.

Burn-on-cast is server-driven: `CastSpell` only reads `ComponentIsOwned`
(404710); mutations arrive via `CPlayerSystem::UpdateSpellComponent` (397044).

**Latent bug**: `DetermineComponentCategory` returns `8` on lookup failure
(430925), and that value indexes the 7-element array unguarded at
acclient.c:**431555, 431701, 431762**.

Auto-restock is `PlayerModule::desired_comps_` (function 513140, clamp 0..5000 at
513152–513153) and `gmVendorUI::FillComponentList` (function **246299**), where
category `8` means "all" (test at **246371**).

### Casting economy

`ClientMagicSystem::CastSpell` (404671) checks only component ownership and a
valid target; self-target spells (`_bitfield & 8`, 404732) bypass targeting. It
sends `Event_CastUntargetedSpell` (`0x48`, function 699875, opcode at 699897) or
`Event_CastTargetedSpell` (`0x4A`, function 699796, opcode at 699822).

Everything else is server-side, returned as WERROR codes rendered at
acclient.c:415977–416015. The casting-related codes, **including `0x3FF` which
earlier drafts dropped**:

| Code | Message | Line |
|---|---|---|
| `0x3FE` | "You don't know that spell!" | 415978 |
| **`0x3FF`** | **"Incorrect target type"** | between 415978 and 415990 |
| `0x400` | "You don't have all the components for this spell." | 415990 |
| `0x401` | "You don't have enough Mana to cast this spell." | 415997 |
| `0x402` | "Your spell fizzled." | 416002 |
| `0x403` | "Your spell's target is missing!" | 416007 |
| `0x404` | "Your projectile spell mislaunched!" | 416012 |

Nearby in the same switch: `0x3F8`, `0x3F9`, and `0x3FA` ("You've attempted an
impossible spell path!").

### Spellbook

`SpellBookPage` (acclient.h:37368) is a vfptr plus one float. `_casting_likelihood`
has no display reader — only zero-init (439830, 439847, 447401), hashtable insert
(447203) and remove-copy (447238), Pack `+2.0` (503930), UnPack (503951, legacy
`< 2.0` test at 503948). **No client-side difficulty or chance-to-cast
calculation was found anywhere.**

`spell_filters_` is a 16-bit mask: `0x1` Creature, `0x2` Item, `0x4` Life,
`0x8` War, `0x2000` Void, `0x10`–`0x800` levels 1–8, `0x1000` level 9, default
`0x3FFF` (513743). UI buttons stop at `m_btnLevel_8` = 2048 (198912), and the
level-9 arm is unreachable anyway (see above).

Rows sort ascending by `_display_order` via linear scan (comparison at 198772).

**Spell sets are parsed and never queried.** `m_SpellSetHash` appears only in
`CSpellTable` ctor/dtor/Pack/UnPack (449259–450448); `m_SpellSetID` only in
Pack/UnPack (502620, 502682), ctors (502536, 502561), and a struct copy in
`PackableList<Enchantment>::Flush` (235697).

Equipment-set names come from a separate path:
`ItemExamineUI::Appraisal_ShowSet` (function 229498) reads int property `0x109`
at 229516, then a hardcoded switch of **113** set-name strings, cases 4 through
130, at 229524–229867.

---

## 4. Skills

`SkillFormula::Calculate` (body acclient.c:**442789**), guarded on `_z != 0`:

```c
level = floor((w + attr1*x + attr2*y) / z + 0.5);
```

`InqSkill` (443603–443693) adds, **unconditionally**: `_init_level +
_level_from_pp` (443631); enlightenment int `0x16D` (443634); and **+10** per
mastery augmentation (443637–443665) — int 300 for skills
`{0x29, 0x2C, 0x2D, 0x2E, 0x31}`, 301 for `{0x2F}`, 302 for
`{0x1F, 0x20, 0x21, 0x22, 0x2B}`.

The `if (!raw)` block opens at **443666** and gates only: `EnchantSkill` (443670),
**+5** for aug `0x146` (443671), and **+2 × aug `0x158`** when `_sac == 3`
(443673).

So "base" values shown in the UI still include enlightenment and mastery.

Char-gen shows +5 trained / +10 specialized (496309–496322), gated on
`sac >= _min_level`.

---

## 5. Damage, death, and vitae

`HandleAttackerNotificationEvent` (408294) and
`HandleDefenderNotificationEvent` (409442 — it also carries a `part` index) both
feed `CombatSystem::InqCombatHitAdjectives` (500139), which returns 0 for
`php < 0.0` (500164) and keys on strict thresholds `> 0.1`, `> 0.25`, `> 0.5`.

Attack-condition bits, tested at acclient.c:408414 / 408416 / 408426: `0x1`
target's Critical Protection, `0x2` Recklessness, `0x4` Sneak Attack.

| Type | Value | Adjectives |
|---|---|---|
| Nether | `0x400` (1024) | scar / twist / wither / eradicate |
| **Health** | **`0x80` (128)** | drain / exhaust / siphon / deplete (500200) |
| Electric | 64 | **spark / shock / jolt / blast** — four tiers (500234–500266) |
| Mana | `0x200` (512) | **no case**; `> 128 && != 1024` falls to "hit"/"hits" |

`AppraisalSystem::DamageTypeToString` (479074) handles bits 1, 2, 4, 8, `0x10`,
`0x20`, `0x40`, `0x400`, `0x10000000`. Health, stamina, and mana yield an empty
string, so those hits read "…points of damage!" with no type word.

Death is thin: `HandleVictimNotificationEvent` (409151) just adds a
pre-formatted string; `HandlePlayerDeathEvent` (409097) suppresses the message if
the local player is victim or killer.

Vitae display is `gmVitaeUI::Update` (222962) using
`VitaeCPPoolThreshold = (level^2.5 * 2.5 + 20) * vitae^5` (500126). Client-side
vitae modifies only skills and secondary attributes —
`InfoRegion::GetVitaeModifier` returns 0 (285130), with overrides only in
`SkillInfoRegion` (285192) and `Attribute2ndInfoRegion` (285287); there is no
`AttributeInfoRegion` override.

---

## 6. Motion styles

Recovered by aligning `command_strings[408]` (element 0 at acclient.c:43455) with
`command_ids_1[408]` (element 0 at 43866). Two independent anchors confirm the
alignment: `"HandCombat"` at index 60 → `2147483708` = `0x8000003C`, and
`"Ready"` at index 3 → `0x41000003`. The 6.95 decompilation reproduces the same
pairing.

| ID | Style | ID | Style |
|---|---|---|---|
| `0x8000003C` | HandCombat | `0x80000044` | 2HandedSwordCombat |
| `0x8000003D` | NonCombat | `0x80000045` | 2HandedStaffCombat |
| `0x8000003E` | SwordCombat | **`0x80000046`** | **DualWieldCombat** |
| **`0x8000003F`** | **BowCombat** | `0x80000047` | ThrownWeaponCombat |
| `0x80000040` | SwordShieldCombat | `0x80000048` | Graze |
| `0x80000041` | CrossbowCombat | `0x80000049` | **Magi** |
| `0x80000042` | UnusedCombat | `0x800000E8` | BowNoAmmo |
| `0x80000043` | SlingCombat | `0x800000E9` | CrossBowNoAmmo |
| `0x80000138` | AtlatlCombat | `0x80000139` | ThrownShieldCombat |

(The string at 43528 is `"Magi"`, not "Magic".)

---

## 7. Message opcodes

Server to client — magic (395140, 395293–395314): `0x2C1` UpdateSpell, `0x2C2`
UpdateEnchantment, `0x2C3` RemoveEnchantment, `0x2C4`
UpdateMultipleEnchantments, `0x2C5` RemoveMultipleEnchantments, `0x2C6`
PurgeEnchantments, `0x2C7` DispelEnchantment, `0x2C8`
DispelMultipleEnchantments, `0x312` PurgeBadEnchantments.

Server to client — combat (394686, 394708–394803): `0x19E` PlayerDeath, `0x1A7`
AttackDone, `0x1AC`/`0x1AD` VictimNotification, `0x1B1` AttackerNotification,
`0x1B2` DefenderNotification, `0x1B3`/`0x1B4` Evasion, `0x1B8` CommenceAttack,
`0x1C0` QueryHealthResponse.

Client to server, beyond §1: `Event_RemoveSpell` `0x1A8` (699947),
`Event_SpellbookFilterEvent` `0x286` (698260), `Event_AddSpellFavorite` `0x1E3`
(697583), `Event_RemoveSpellFavorite` `0x1E4` (698163),
`Event_CharacterOptionsEvent` `0x1A1` = 417 (function 697664, opcode at 697689 —
agrees with `03-object-model.md`).

---

## 8. Traps for the unwary

**Hex-Rays substitutes string literals for large immediates.** `0x800000`
renders as a long format string and means Vitae here, `SLEDDING_PS` in physics,
and `MISSILE_AMMO_LOC` in inventory. Look up the numeric value; do not trust the
rendering. The 2015 decompilation renders it the same way, so a second opinion
does not settle it — the *header enum* does.

**Prefer header enums to inferred bits.** `EnchantmentTypeEnum`
(acclient.h:3163), `SpellIndex` (3568), the component enums (4523, 3540),
`COMBAT_MODE` (3730), and `ATTACK_HEIGHT` (4371) are all named.

**Motion style IDs come from two parallel arrays.** Recover them by aligning
acclient.c:43455 and 43866 against a known anchor, not by guessing from context.

**Much of what looks like game logic is dead.** The maneuver table's contents,
`_casting_likelihood`, `_category`, `_power`, `_gesture`, `_CDM`, spell sets, and
`DamageOverTime` are all parsed and never read. Before concluding the client
implements a mechanic, check that something reads the field.

**Two caveats on method.** The field-level negatives above were established by
exhaustive grep and are solid. But statements like "the swing animation always
arrives from the server" are universal negatives over a 938k-line decompilation —
they are consistent with everything read here, but the correct phrasing is "no
such path was found", not "there is none". Separately, the `DBObj::Release`
identification in §1 rests on a vtable offset pattern; resolving `7E8060+20` in
IDA would settle it.
