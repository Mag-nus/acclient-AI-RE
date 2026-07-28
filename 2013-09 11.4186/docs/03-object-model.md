# The Game Object Model and Qualities System

Target: acclient.exe 11.4186 (September 2013). Line references are into
`../acclient.c` and `../acclient.h` unless noted.

> **Revision note.** Three passes. The third pass found a semantic error in the
> DID table (§5), a missing opcode pair (§6), a false "fires only in" claim
> (§6), a wrong pack-header bit (§11), and roughly thirty citation drifts. It
> also established that the second pass's characteristic failure was citing
> *function headers* instead of the line that proves the claim. Citations below
> point at the proving line.
>
> **On property names**: the client has no property-ID enum. Names like
> "enlightenment" or "vitality" are inferences from call context and outside
> knowledge, not from the binary. Only `0x18` and `0x1E` have in-binary
> corroboration. They are marked below.

---

## 1. Object model layering

Every world object is two objects:

- **`CPhysicsObj`** — physics and render entity (see `01-physics.md`).
- **`CWeenieObject`** (acclient.h:30252) — game-logic side; nearly empty on the
  client: `update_time`, a `netblob_list`, and a `TSRecv blobOrdering`.
- **`ACCWeenieObject`** (acclient.h:40386) — the concrete client weenie:
  `CObjectInventory *objInventory`; lifecycle flags; `PositionState current_state`
  (acclient.h:6802); UI state; a back-pointer `_phys_obj`; an embedded
  **`PublicWeenieDesc pwd`**; an `ACWTimeStamper *_stamper`; and
  `PlayerDesc *m_pQualities`.

`PublicWeenieDesc` (acclient.h:37163) is the broadcast stat block, with a
`_bitfield` of `BitfieldIndex` flags (acclient.h:6431) and a cut-down
`RestrictionDB _db` for housing. Its wire format is delta-encoded through two
presence masks (acclient.h:7634, 7673).

`PlayerDesc : CACQualities : CBaseQualities` (acclient.h:39400, 37736, 37238) is
allocated for every weenie in `ResetPlayerDesc` (acclient.c:436359) but stays
mostly empty for non-players.

`CObjectMaint` (acclient.h:33078) holds the registries. They are **not** all the
same container type: `object_table` / `null_object_table` /
`weenie_object_table` / `null_weenie_object_table` are `LongHash`,
`visible_object_table` is a `HashSet`, `destruction_object_table` is a
`HashTable<ulong,double,0>`, plus `object_inventory_table`, `lost_cell_table`,
and `object_destruction_queue`.

Creation: `SmartBox::HandleCreateObject` (acclient.c:145881) →
`ACCObjectMaint::CreateObject` (391856), which recycles or builds both halves,
applies the WeenieDesc via `SetWeenieDesc` (391179), cross-links them, and for
the player runs `init_player` and `enter_world`.

---

## 2. SmartBox

`SmartBox` (acclient.h:35189), static instance at acclient.c:52134, owns the
viewer Position, `CameraManager`, `CellManager`, `CPhysics`, `CObjectMaint`,
`LScape`, `Ambient`, the `CommandInterpreter`, and `player_id`/`player`. Its
three-entry vtable (acclient.h:35230–35235) is essentially
`DispatchSmartBoxEvent` (acclient.c:143041).

---

## 3. Property storage

`CBaseQualities` (acclient.h:37238) holds eight per-type `PackableHashTable`s.
**Struct order** is `_weenie_type`, int, int64, bool, float, string, DID, IID,
Position (acclient.h:37238–37249).

**Wire gate bits are a different order** (`SetPackHeader`,
acclient.c:447580–447597): int `0x1`, bool `0x2`, float `0x4`, DID `0x8`,
string `0x10`, Position `0x20`, IID `0x40`, int64 `0x80`.

`CBaseQualities::UnPack` (447729) reads the header at 447771, `_weenie_type` at
447777, and dispatches the gated tables from **447780**.

### Property-ID literals

Verified in context, each at the line that proves it:

| Literal | Meaning | Proving line | Name source |
|---|---|---|---|
| `0x18` | available skill credits | 212882 | **in-binary** (`ID_SkillCredits`, 212884) |
| `0x1E` | buffed allegiance rank | **204568** | **in-binary** (`ID_Allegiance_RankBuffed`) |
| `0x6A` | Spellcraft | **232644** | string "Spellcraft: %d." |
| `0x6B` / `0x6C` | item mana / max mana | **232654 / 232655** | "Mana: %d / %d." (IDA names the second out-param `iManaCost`, misleadingly) |
| `0x75` | mana cost | **232671** | "Mana Cost: %d." |
| `0xBC` | heritage | 220476 | inferred |
| `0xC7` | last landscape-house purchase time | **219452** | inferred (feeds `HasPurchaseWaitPeriodExpired`) |
| `0x142` | aetheria bitfield | 220467 | inferred |
| `0x146` | "+5 all skills" aug | 443671 | inferred |
| `0x158` | luminance specialized-skill aug | 443673 | inferred |
| `0x16D` | enlightenment | 443634 | inferred |
| `0x17B` | vitality | 443247 | inferred |

### StatType

acclient.h:2879–2899: `Undef 0`, Int 1, Float 2, Position 3, Skill 4, String 5,
DID 6, IID 7, Attribute 8, Attribute2nd 9, **BodyDamageValue `0xA`,
BodyDamageVariance `0xB`, BodyArmorValue `0xC`** (the third is armor),
Bool `0xD`, Int64 `0xE`, `Num_StatTypes 0xF`.

Corroborated by the `WTimeStamper` key masks, which are exactly `StatType << 16`:
Int `0x10000`, Float `0x20000`, Position `0x30000`, Skill `0x40000`,
String `0x50000`, DID `0x60000`, IID `0x70000`, Attribute `0x80000`,
Attribute2nd `0x90000`, Bool `0xD0000`, Int64 `0xE0000`.

### CACQualities sub-objects

`SetPackHeader` (acclient.c:444090): `0x1` attribCache, `0x2` skills, `0x4` body,
`0x8` event filter, `0x10` emote table, `0x20` create list, `0x40` page data,
`0x80` generator table, `0x100` spell book, `0x200` enchantment registry,
`0x400` generator registry, `0x800` generator queue.

---

## 4. Attributes, skills, vitals, XP

`Attribute`, `SecondaryAttribute`, `AttributeCache` (acclient.h:37287–**37312**),
`Skill` (37315). `SKILL_ADVANCEMENT_CLASS` has `SPECIALIZED = 0x3` at
acclient.h:2956.

`SkillFormula::Calculate` (body acclient.c:**442789**), guarded on `_z != 0`:

```c
level = floor((_w + attr2*_y + attr1*_x) / _z + 0.5);
```

Declaration order is `{_w, _x, _y, _z, _attr1, _attr2}` (acclient.h:40199).

`InqSkillBaseLevel` (443298) resolves the skill table with
**`DBObj::GetByEnum(4, 2, 0x10000004u)` at acclient.c:443316** — not
`GetDIDFromEnumStatic` as an earlier draft said.

`InqSkill` (443603–443693) adds **unconditionally**: `_init_level +
_level_from_pp` (443631), enlightenment `0x16D` (443634), and **+10** mastery
(switch opens 443637, cases to 443665) — int 300 for skills
`{0x29,0x2C,0x2D,0x2E,0x31}`, 301 for `{0x2F}`, 302 for
`{0x1F,0x20,0x21,0x22,0x2B}`.

The `if (!raw)` block opens at **443666** and gates only `EnchantSkill` (443670),
+5 for `0x146` (443671), and +2 × `0x158` when `_sac == 3` (443673). So UI "base"
values still include enlightenment and mastery.

**Vitals**: `InqAttribute2nd` (443223) adds `0x17B` only when `stype == 1`
(guard at 443244, read at 443247). `BoundsCheck` is at
**acclient.c:443268–443295** — an earlier draft cited 441267, off by 2,000 lines
— clamping even stypes to `InqAttribute2nd(stype − 1)`.

**XP** is table-driven. `ExperienceSystem` (from 499328) loads via
`DBObj::GetByEnum(3, 2, 0x10000009)` at 499332 — `0x10000009` is a **type tag**,
the DID is `0x0E000018` (§5). `ExperienceTable` (acclient.h:59315–59328) holds
`_level_table`, `_attribute_table`, `_attribute2nd_table`,
`_trained_skill_table`, `_specialized_skill_table`, and `_credit_table`
(`Credit_ExperienceType = 6`, acclient.h:7581). `GetExperienceForLevel` (501001)
is a bounds-checked index.

---

## 5. The DID to DB_TYPE map

`gmMasterDBMap::DivineType_Internal` (acclient.c:**514291**) is authoritative.
Constants at acclient.c:**42117–42132**.

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
| **`0x30000000`–`0x3000FFFF`** | `0x1000000D` | COMBAT_TABLE |
| `0x38000000`–`0x3800FFFF` | `0x1000000E` | MUTATE_FILTER |

**The COMBAT_TABLE row is bounded, not open-ended.** An earlier draft wrote
"≥ `0x30000000`", which would swallow the MUTATE_FILTER range and everything
above it. The `else` arm at acclient.c:514297 tests `did.id > 0x3000FFFF` and
excludes it. Confirmed identically in the 2015 build
(`acclient 6.6.14.605 Diffed.c:511785–511793`).

Lookups go through `DBObj::GetByEnum` (81695) and `DBCache::GetDIDFromEnum`
(79580) — see `07-dat-resources.md` §4.

---

## 6. Quality updates from the server

The ordinals live in the `UIQueueManager` dispatch switch at roughly
**acclient.c:394597–395400** — *not* at 711673–712260, which holds the
`CM_Qualities::DispatchUI_*` bodies and contains no ordinals at all.

| Operation | Private / Public |
|---|---|
| RemoveInt … RemovePosition | 465/466, 467/468, 469/470, 471/472, 473/474, 475/476, 477/478 |
| RemoveInt64 | 696 / 697 (out of band) |
| UpdateInt | 717 / 718 |
| UpdateInt64 | 719 / 720 |
| UpdateBool | 721 / 722 |
| UpdateFloat | 723 / 724 |
| **UpdateString** | **725 / 726** (`0x2D5` / `0x2D6`) |
| UpdateDID | 727 / 728 |
| UpdateIID | 729 / 730 |
| UpdatePosition | 731 / 732 |
| UpdateSkill | 733 / 734 |
| UpdateSkillLevel | 735 / 736 |
| UpdateSkillAC | 737 / 738 |
| UpdateAttribute | 739 / 740 |
| UpdateAttributeLevel | 741 / 742 |
| UpdateAttribute2nd | 743 / 744 |
| UpdateAttribute2ndLevel | 745 / 746 |

**UpdateString was missing from earlier drafts.** The gap between UpdateFloat 724
and UpdateDID 727 should have been the tell. Its handlers are
`Handle_Qualities__UpdateString` (392178) and `__PrivateUpdateString` (392354),
and unlike the rest of the `0x2CD`–`0x2EA` block it routes through
`UIQueueManager::HandleStringUpdateEvents`, not `CM_Qualities`.

These are separate per-type instantiations, not one template:

| Type | Body | Timestamp mask |
|---|---|---|
| Skill | 391428 / 391450 / 391473 | `|0x40000` at 391438/391460/391483 |
| Int | 391495 | `|0x10000` at 391505 |
| Int64 | **391518** | `|0xE0000` at **391528** |
| Bool | **391540** | `|0xD0000` at **391550** |
| Float | **391563** | — |

**`OnStatUpdated` fires in seven instantiations, not two** — 391375
(AttributeLevel), 391420 (Attribute2ndLevel), 391465 (SkillLevel), 391510 (Int),
391555 (Bool), 391627 (DataID), 391650 (InstanceID). An earlier draft bolded the
false claim.

`WTimeStamper` (acclient.h:40374) / `ACWTimeStamper` (40381) hold a
`PHashTable<ulong,uchar>` plus `char _house_ts`; the derived class adds nothing.

---

## 7. Inventory

`CObjectInventory` (acclient.h:33202) = `IDList _itemsList`,
`IDList _containersList`, `PackableList<InventoryPlacement>` (33178).

Driven by `ViewObjectContents` (391974) and `UpdateObjectInventory` (392652), or
by WeenieDesc rewrites and `ServerSaysContainID` (436395).

`INVENTORY_LOC` composites (acclient.h:3193), all verified:
`CLOTHING_LOC 0x080001FF`, `ARMOR_LOC 0x00007E00`,
**`JEWELRY_LOC 0x7C0F8000`** (decomposing to `0x8000|0x30000|0xC0000|0x4000000|
0x8000000|0x70000000` — trinket, cloak, and sigils included),
`WEAPON_LOC 0x02500000`, `READY_SLOT_LOC 0x03F00000`,
`WEAPON_READY_SLOT_LOC 0x03500000`, `SIGIL_LOC 0x70000000`,
`ALL_LOC 0x7FFFFFFF`.

`InventoryRequest` (acclient.h:6812) runs `IR_NONE` … `IR_SHOP_EVENT (0xA)`.

Wield requirements (`GetAppraisalStringFromRequirements`, 227877): types **1, 2,
and 8** all resolve as skill names; 3/4 attribute; 5/6 vital; 7 level; 9/10 int
property; 11 creature type; 12 heritage. The `"base "` prefix applies to 2, 4, 6.
Int properties 287/288/289 map to Celestial Hand / Eldrytch Web / Radiant Blood
at 227925–227932.

---

## 8. Appearance and appraisal

`ObjDesc : VisualDesc` (acclient.h:39630) is a base palette plus `Subpalette`,
`TextureMapChange`, and `AnimPartChange` lists. `ClothingTable::BuildObjDesc`
feeds char-gen preview (call at 283284 inside `gmCG3DView::Update`, 283108) and
the barber; in world the server sends complete ObjDescs
(`HandleObjDescEvent`, 144356).

### AppraisalProfile

acclient.h:36603 — **six** stat tables (int, int64, bool, float, string, DID;
**no IID, no Position**), optional Creature/Hook/Weapon/Armor profiles, a
`PSmartArray<ulong> *_spellBook`, three highlight bitfields, and **nine
`base_armor_*` ints** in order head, chest, groin, bicep, wrist, hand, thigh,
shin, foot.

**Spell IDs carry a bit-31 tag.** `Appraisal_ShowMagicInfo` (232515) masks
`id & 0x80000000` at **232581** and `id & 0x7FFFFFFF` at **232582**, routing to
"Enchantments:" when set and "Spell Descriptions:" when clear (232607).
`Appraisal_ShowShortMagicInfo` (232412) skips high-bit entries at **232447**.

Names resolve via `GetSpellName` / `GetSpellDescription` (403960, 403976) into
`CSpellTable::InqSpellBase` (403913). The player's own `CSpellBook`
(acclient.h:**37392**) is never consulted here.

The highlight bitfields use low bit = modified/lowered, same bit `<<16` = raised.
**The decode lives in `AppraisalProfile::InqIntEnchantmentMod` (477439) and
`InqFloatEnchantmentMod` (477474)**, not in `Appraisal_ShowArmorMods` (231786),
which merely selects between the `mod_high_font` and `mod_low_font` member
handles.

`ArmorEnchantment_BFIndex` (acclient.h:4237) covers level plus eight damage
types. `WeaponEnchantment_BFIndex` (4261) covers offense, defense, time, damage,
variance, mod. `ResistanceEnchantment_BFIndex` (4279) has **15 low bits, of which
13 are resistances** — slash, pierce, bludgeon, fire, cold, acid, electric,
health boost, stamina drain, stamina boost, mana drain, mana boost, nether — plus
`BF_MANA_CON_MOD 0x1000` and `BF_ELE_DAMAGE_MOD 0x2000`.

---

## 9. Social and world systems

### Allegiance

`AllegianceData` (acclient.h:35815, 13 fields), `AllegianceNode` (36253),
`AllegianceHierarchy` (36275), `AllegianceProfile` (36297).

Rank is server-supplied; `_loyalty` and `_leadership` are unpacked (481196–481197,
481329/481332, 481429/481433) and never used — note they are wire-packed as
16-bit despite being declared `unsigned int`.

Titles come from **17** hardcoded switch functions spanning
acclient.c:**482727–483643**, dispatched by `AllegianceSystem::GetTitle`
(483645). The extra two beyond a naive male/female pairing are the male-only
Gearknight/Tumerok/Lugian set. Aluvian male ranks 1–10: Yeoman, Baronet, Baron,
Reeve, Thane, Ealdor, Duke, Aetheling, King, High King.

`AllegianceIndex` (acclient.h:7714), `AllegianceVersion` 1..11 (2979),
`eAllegianceOfficerLevel` (3888). `AllegianceHierarchy::UnPack` (482324) gates
every field on version.

`gmAllegianceUI::UpdatePlayerData` (204451) reads int `0x1E` at **204568**,
switching to `ID_Allegiance_RankBuffed` when it differs from base and is not −1.
`UpdateVassalsData` (205238) renders `_cp_tithed` at 205345.

`ChannelSystem::GetChannelID` (507159) has ~18 entries; the six cited are
allegiance `0x2000000`, co-vassals `0x1000000`, monarch `0x4000`, patron
`0x2000`, vassals `0x1000`, fellowship `0x800`.

### Fellowship

`Fellow` (acclient.h:36647). `Fellowship` (36731) — note `_fellowship_table` is
the **first** member. Cap is 9 (`IsFull`, 483775).

`GetEvenSplitXPPctg` (484596) is a literal table: 1.0, 0.75, 0.60000002,
0.55000001, 0.5, 0.44999999, 0.40000001, 0.34999999, 0.31111109, 0.28, default
0.0.

`RecalculateEvenXPSplitting` (484008) is gated on `_share_xp`, sets
`_even_xp_split = 1`, and then — **only if the lowest member is under level 50**
— applies **two independent** kills, both measured against the **leader's**
level: `if (max > leader + 5) → 0` and `if (min + 5 < leader) → 0`. Earlier
drafts described a single group-spread test.

Opcodes: inbound 702/703/704; outbound 162, 163, 164, 165, 166, 656, 657.

### Housing

`HouseProfile` (37806), `HouseData` (37794), `HousePayment` (37763), `House`
(38029), `HAR` (37988), `GuestInfo` (37963 — storage permission is per-guest),
`HARBitmask` (2846), `HouseBitmask` (3652), `RestrictionDB` (37155) with
`IsAllowedIn` (473082).

House types 1 cottage / 2 villa / 3 mansion / 4 apartment (412637, 430788). Rent
is 7776000.0 s (90 days) for apartments, 2592000.0 (30 days) otherwise
(`GetRentPeriod`, 486149); the purchase cooldown literal 2592000 is at 486145
inside `HasPurchaseWaitPeriodExpired` (486143).

Exactly **21** `CM_House::Event_*` opcodes span acclient.c:**707405–708327**,
including BuyHouse 540, AbandonHouse 543, RentHouse 545, SetOpenHouseStatus 583,
ChangeStoragePermission 585, TeleToHouse 610, SetHooksVisibility 614,
ListAvailableHouses 624.

### Contracts, titles, books

`CContract` (acclient.h:40422) stores quest flags as **strings**.
`CContractTable` (40476) is fetched with `DBObj::GetByEnum(23, 2, 0x10000010)` at
**acclient.c:210995, 211211, 211296, and 211674** — an earlier draft cited
451670, which is unrelated quest-def code.

`CContractTracker` (37823). `gmContractsUI::FillProgressString` (210728) decodes
`_contract_stage`: 1 Available, 2 In Progress, **3 has three outcomes** — "Done"
with no repeat time, `"Done (<delta> to Repeat)"` with a pending timer, and
"Available" once expired — and anything ≥ 4 is a progress counter rendered as
`stage − 4`.

`QuestTable` / `QuestProfile` (36725, 36681) have **zero occurrences anywhere in
`acclient.c`**, prototypes included. The `questflag` hits at 210750/211147 are
`CContract` string members.

`CharacterTitleTable` (37862) is `{unsigned mDisplayTitle; PList<ulong>
mTitleList}` — a list, not a bitfield. `Pack` (498059) writes literal 1, the
display title, then the packed list. Names resolve through
`EnumMapper::GetString(0x10000006, …)` at 498120 into string table `0x10000007`
at 498138.

`PageData` / `PageDataList` (37608, 37621); `PackNoText` (510634); `UnPack`
(510580) with the version escape at 510599–510618. Books arrive on `0xB4` using a
stack-local `PageDataList` (394966).

---

## 10. Body, emotes, creation profiles

**`Body` has zero readers.** `Body` (acclient.h:**37362**; 37364 is its member
line) is `PackableHashTable<long, BodyPart>`; there is no `BodyPartTable` type. A
grep for `PackableHashTable<long,BodyPart>::lookup` returns **nothing** — the
table only ever has `add` called, from its own `UnPack`. Across 109 references,
every one is ctor, dtor, Pack, pack_size, UnPack, or a null check.

Earlier drafts said the part index's only consumer is combat text. That
understates it: the `part` argument at 409674 arrives **straight off the wire**
in the `0x1B2` handler (`case 0x1B2u` at 394742 →
`HandleDefenderNotificationEvent` 409442), so `Body`, `BodyPart`, `ArmorCache`
(35753), and `BodyPartSelectionData` (35780, twelve floats HLF…LRB) are read by
nothing at all.

`BodyPartEnumMapper::BodyPartToString` (508933) switches on `bp + 1`; the full
map includes `−1 UNDEFINED`, 0–23 as listed elsewhere, **24 UPPER_TENTACLE**,
**25 LOWER_TENTACLE**, 26 CLOAK, and **27 NUM**. The gaps at 11 and 14 are
genuine.

`CEmoteTable` (37586) is store-only: allocated and unpacked at
acclient.c:444716–444735, freed in `Clear` (444042/444046), null-checked in
`SetPackHeader` (444104), serialized — never looked up or iterated. The only
content inspection is `Emote::IsValid`, called from inside `Emote::UnPack`.

`EmoteSet::UnPack` (448305) category semantics: 1 and 6 carry a `classID`; 5
style plus substyle; 2 `vendorType`; `0xC`, `0xD`, `0x16`, `0x17`, and the
contiguous run `0x1B`–`0x26` a quest string; `0xF` min/max health floats.
`Emote::UnPack` (506750) switches on **114** distinct case labels, not "roughly
80".

`CreationProfile` (37478): `UnPack` (504048) fixes the wire layout at 24 bytes —
`wcid, palette, shade (float), destination, stack_size, try_to_bond`. Note the
**C++ layout differs**: `try_to_bond` sits at offset +8 but serializes last.

`_create_list` is store-only, but **`Emote::cprof` is read** — `Emote::IsValid`
(505773) reads `cprof.wcid.id` and `cprof.stack_size` at 505874 (`case 3`),
505878 (`0x4A`), 505887 (`0x4C`), and `Emote::UnPack` reads it for size
computation at 506941/506949/506954. Validate-and-serialize only, never for
display — but "never read" is too strong.

---

## 11. PlayerModule

`PlayerModule` (acclient.h:36507): `shortCuts_[18]` (36494) of
`ShortCutData{index_, objectID_, spellID_}` (36484); `favorite_spells_[8]`
(36510); desired comps; `options_`; `options2_`; `spell_filters_`;
`m_pPlayerOptionsData` (a `GenericQualitiesData*`, acclient.h:**36498**);
`m_colGameplayOptions`; `m_TimeStampFormat`.

`Default_CharacterOption = 0x50C4A54A` (acclient.h:**3434**; enum head 3404, top
member `UseCraftSuccessDialog 0x80000000` at 3433, also
`AutoAcceptFellowRequest 0x20000000`). `Default_CharacterOptions2 = 0x948700`
(acclient.h:**3479**; enum head 3451). The constructor assigns 1355064650 and
9733888 at acclient.c:**513741** and **513742** (513743 is
`spell_filters_ = 0x3FFF`).

`PlayerOption` (acclient.h:4162–4217) covers `0x00`–`0x33` with
`TotalNumberOfPlayerOptions = 0x34`. `AddShortCut` is at acclient.c:11067 and
`SetToggleRun` at 11093.

**`GetDefaultOptionValue` is not the decomposition of the two masks.** The masks
set **19** bits (12 + 7), but `GetDefaultOptionValue` (510998) returns 1 for only
**16**: `{0, 2, 6, 8, 0xA, 0xD, 0xE, 0xF, 0x14, 0x15, 0x19, 0x1B, 0x23, 0x24,
0x25, 0x2A}`. The three defaulted-on options it returns **0** for are
`ConfirmVolatileRareUse` (`0x2D` / opt2 `0x40000`), `ShowHelm` (`0x2F` /
`0x100000`), and `ShowCloak` (`0x32` / `0x800000`).

### GenericQualitiesData

Four optional tables with a 4-bit header — int 1, bool 2, float 4, string 8
(`Pack` at acclient.c:721265, bits at 721283–721290; the
`CEnchantmentRegistry::pack_size` call there is an IDA mislabel). **Exactly one
key is used client-side**: string key `1`, the timestamp format, written at
513085 and read at 513371.

### m_colGameplayOptions

A `PackObjPropertyCollection` with 23 in-place buckets. Note acclient.h:30260 is
an **`IntrusiveHashTable`**; the bucket count is right but earlier drafts named
the type wrongly.

The option set is DAT-driven: `UIOption::InqGameplayOptionProperty` (283650)
reads DBObj enum 21 and hash key 210; defaults come from
`InqDefaultGameplayOptionProperty` (283953) on enum 22. Known property names in
the `0x1000xxxx` space: `0x1000007F` chat text-type filter,
`0x10000080`/`0x81` opacity, `0x10000086`–`0x89` window geometry, `0x1000008C`
the chat-option struct array (`GetChatOptionStructure`, 513787).

### Wire evolution

`SetPackHeader` (512804), decoded against `UnPack` (513178):

| Bit | Meaning |
|---|---|
| `0x1` | shortcuts |
| `0x4` | 5 favorite-spell lists |
| `0x8` | desired comps |
| `0x10` | 7 favorite-spell lists |
| `0x20` | spell filters (absent ⇒ `0x3FFF`) |
| `0x40` | options2 (absent ⇒ 9733888) |
| **`0x80`** | **timestamp format** — read-only legacy; `SetPackHeader` never sets it |
| `0x100` | GenericQualitiesData |
| `0x200` | gameplay options |
| **`0x400`** | **8 favorite-spell lists** |

Earlier drafts put the 8-list case on `0x100` and the timestamp on `0x400`. Both
were wrong, and `0x100` was simultaneously documented as GenericQualitiesData —
an internal contradiction that should have been caught.

The module ships via `Event_CharacterOptionsEvent`, opcode **417** (function
697664, opcode written at 697682 — agrees with `04-combat-magic.md`'s `0x1A1`),
on a 480-second dirty flush (`CPlayerModule::UseTime`, 452827).

`CPlayerModule::OnChanged` (452957) has **six** switch arms plus a tail, not
four: option 5 → `LScape::SetDay`, 4 → `SmartBox::EnableWeather(v4 == 0)`,
`0x30` → `LScape::m_fFogEnabled`, 7 → `ClientCombatSystem::TrackTarget`, 2
(IgnoreFellowshipRequests clears auto-accept), `0x12` (auto-accept clears
ignore), plus an `IsAutoSaveOption` path that fires
`Event_PlayerOptionChangedEvent` immediately instead of dirtying.

---

## 12. Traps for the unwary

**IDA mislabels fields inside `CACQualities::UnPack`** (444513): the emote table
is allocated at 444718 under the name `_boolStatsTable`, and the create list at
**444742** under `_floatStatsTable` (assigned at 444754). Trust `SetPackHeader`
and the `operator new` sizes.

**Type tags look like DIDs.** `0x10000004`, `0x10000009` and friends are DB_TYPE
constants passed to `GetByEnum`. Real DIDs are in §5.

**Pack-header bit order is not field order** (§3), and `PlayerModule`'s bits are
not in numeric feature order (§11).

**Not everything unpacked is used.** `Body`, `CEmoteTable`, `_create_list`, and
`QuestTable` are parsed and never read for display.

**Property names are inferred.** The client has no property-ID enum; only `0x18`
and `0x1E` have in-binary name corroboration.

### Not re-verified in the third pass

For honesty about coverage: the `0x1000xxxx` gameplay-property names beyond their
constants, the `InqGameplayOptionProperty` sub-property numbers 212/213/214,
`GetObjectName`'s pluralization and "Backpack" substitution, the
`EnchantInt`/`EnchantFloat` virtual family, and
`CFactory::MakeCWeenieObject` / `ServerSaysMoveItem` were located but not read
line-by-line.
