# Audio

Target: acclient.exe 11.4186 (September 2013). Line references are into
`../acclient.c` and `../acclient.h` unless noted.

> This subsystem was mapped from scratch in the second pass; no first-pass
> report covered it.

> **Revision note.** Mapped in the second pass, then adversarially verified in a
> third. The third pass corrected the attenuation operation order (§3), the
> variant-selection consequence (§4), the weight-formula attribution (§5), and —
> most importantly — found that the "no streaming audio of any kind" claim was
> **false**: there is a live DirectShow player (§6).

**Headline:** `SoundManager` is far simpler than its data structures suggest.
Despite full DirectSound 3D support being compiled in, **every game sound is a 2D
buffer with software-computed pan and attenuation**. No 3D listener update, no
doppler, no MIDI music. Streaming audio does exist, but outside `SoundManager`
entirely — see §6.

---

## 1. Backend: legacy DirectSound, no fallback, no enumeration

The client uses **DX3-era `DirectSoundCreate`** exclusively. There is no Miles
(`AIL_*`), no XAudio, no FMOD or OpenAL, and no `LoadLibrary` of any audio DLL —
the sole *DirectSound* import is `DirectSoundCreate` (acclient.c:11409, called at
acclient.c:387122). Note the client also statically imports winmm
(`midiStreamOpen`, `midiOutShortMsg`, `mmio*`) and msacm32, and reaches
DirectShow via COM — so this is not the only audio code in the binary.

There is **no device enumeration**: `CDirSound::CDirSound` (acclient.c:387104)
passes a NULL GUID, so it always uses the default device.

Init sequence: `SetCooperativeLevel(hwnd, DSSCL_PRIORITY)`; create a **primary
buffer** with `DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRL3D`; query
`IID_IDirectSound3DListener`; set listener rolloff to 0.01f and orientation
front = (−1,0,0), top = (0,1,0); `CommitDeferredSettings`; force the primary
format to **11025 Hz, 16-bit, stereo**; then `Play(..., DSBPLAY_LOOPING)` on the
primary. `CDirSound` is at acclient.h:46357.

Secondary decode uses **MSACM** (`acmStreamOpen` / `Convert` / `Size`) to convert
any non-PCM DAT wave — `wFormatTag != 1`, i.e. ADPCM — to 11025 Hz, 16-bit,
**mono** PCM at buffer-fill time (`SoundBuf::Create`, acclient.c:385849;
`SoundBuf::CopyWaveToBuffer`, acclient.c:385680).

The only fallback is degradation. `SoundManager::Init` (acclient.c:383412) calls `SoundSetup` (386201) and, if
`SoundOK()` is false, sets `effect_sounds_enabled = 0` (383418–383427). Note it
clears **only** that flag — `ambient_sounds_enabled` and
`interface_sounds_enabled` stay true, so the ambient scheduler and UI sound paths
keep running every frame; they are silent only because buffer creation fails.

---

## 2. `SoundManager`

`SoundManager` is a namespace of statics, not an instantiated class.

Init is called from **`Client::InitUI`** (acclient.c:77544), before
`SmartBox::Init`. `SoundManager::ShutDown` (acclient.c:383205) exists but is
**never called** from anywhere in either decompilation — teardown happens only at
process exit.

There is likewise **no per-frame `SoundManager::UseTime`**. The only periodic
audio work in the client is `Ambient::UseTime`, driven from `SmartBox::UseTime`
(acclient.c:146291).

### Voice pool and stealing

`SoundManager::playing_sounds_` is a fixed array of **16** `SoundPlayingData`
(acclient.h:46404 — `{SoundBuf* buffer; float priority; double start_time}`).

`SoundManager::PlaySoundInternal(SoundBufRef*, pan, attenuation)`
(acclient.c:383004) round-robins from `curr_playing_buffer_`, taking the first
slot that is empty, has priority 0, or whose `IDirectSoundBuffer::GetStatus` no
longer reports `DSBSTATUS_PLAYING`.

If all 16 are live it makes a second pass for a slot whose stored priority is
**lower than the new sound's**, stops and deletes that voice, and reuses the
slot. If no slot loses the comparison, **the new sound is dropped**.

It also early-outs entirely when
`s_bPlaySoundOnlyWhenActive && !Device::m_bIsActiveApp`.

Each voice is a `DuplicateSoundBuffer` of a cached master buffer
(`SoundBuf::SoundBuf(SoundBuf*)`, acclient.c:385808). The voice limit is
therefore 16 DirectSound duplicate buffers.

### Buffer cache — eager, not lazy

`SoundManager::sound_hash_` maps wave DID to `SoundBufRef` (acclient.h:46395 —
refcount `links_`, `SoundData data_`, `SoundBuf *sound_buf_`). `CreateSound`
(acclient.c:383707) refcounts up or creates; `DestroySound` (acclient.c:383747)
refcounts down and releases.

An earlier draft said the call sites were "inlined away" and visible only in the
alternate decompilation. That is false — they are plainly present in
`acclient.c`. The complete set is `CreateSound` at **343075**
(`SoundHook::UnPack`), **343140** (`SoundTweakedHook::UnPack`), and **385488**
(`SoundTableData::UnPack`, function at 385399); `DestroySound` at **343058**,
**343088**, and **385383** (`SoundTableData::Destroy`, function at 385365).
`UnPack` also recurses into child nodes (385536), so the whole tree is decoded.
The finding is therefore *stronger* than that draft claimed, not weaker.

**Every wave referenced by a loaded STable is eagerly decoded into a DirectSound
static buffer at table-load time.** There is no lazy load.

A practical consequence worth recording: the `m_stype == 0` branch of
`MediaMachine::Update_Sound` calls `PlaySoundFromCenter(gid, 1.0)` (383591),
which is a **pure `sound_hash_` lookup with no `CreateSound` fallback**. If that
wave DID was never referenced by a loaded STable or animation hook, the call
silently does nothing.

---

## 3. "3D" audio: panning only

This is the most important negative finding.

`SoundBuf` supports 3D — `m_p3DBuf`, `IID_IDirectSound3DBuffer`
(acclient.h:46367) — and `SoundBuf::Create` will request `DSBCAPS_CTRL3D` when
`m_3D` is set. But **`SoundBufRef::SoundBufRef` always constructs its buffer with
`use_3D = 0`** (acclient.c:383127). Every game sound is a plain 2D buffer.
Consequently:

- **The `IDirectSound3DListener` position is never updated.** No `SetPosition` or
  `SetVelocity` call exists anywhere; the listener is configured once in the
  constructor and left alone.
- **No doppler.** `SetDopplerFactor` is never called.
- **No DirectSound distance rolloff** on emitters — rolloff is computed in
  software.

### Software positioning

`SoundManager::PlaySoundInternal(SoundBufRef*, Position*, volume, is_ambient)`
(acclient.c:383152) takes `Position::distance` and `Position::heading` relative to
`SoundManager::player_position_`, computes `sin(angleDelta) * −15` as a **pan
index in [−15, 15]** — scaled ×100 into DirectSound pan units by `SoundBuf::Play`
(acclient.c:386102) — and skips panning entirely when distance is under 5.0 or
when the user preference `s_SoundFeatures == 1` ("Mono").

`SoundManager::GetAttenuation` (acclient.c:383079) is inverse-square beyond 5 m.
**The operation order matters and an earlier draft had it wrong** — the slider
multiplies *inside* the log argument, not after it:

```c
gain = (d >= 5.0) ? 25.0 * volume / (d*d) : volume;
gain = min(gain, 1.0);
gain *= is_ambient ? ambient_sound_volume : effect_sound_volume;
dB    = ceil(log2(gain) * 6.0206);      /* whole dB: 6.0206 = 20*log10(2) */
```

Since log is not linear, applying the slider to a dB result would give a
completely different curve. The value here is **whole dB**; the ×100 to
hundredths-dB happens later, in `SoundBuf::Play` (386140,
`SetVolume(100 * v6)`). `VOL_MIN = −50` (acclient.c:45626), and the function
returns false only when *strictly below* it.

**The listener is the camera, not the player.**
`SoundManager::SetPlayerPosition` (acclient.c:383277) is called from
`SmartBox::set_viewer` with the *viewer* position (acclient.c:144034), and is
temporarily overridden to the creature-view frame during `CreatureMode::Render`
(acclient.c:143931, 143934) so paperdoll and preview sounds are centred.

**Attachment to a `CPhysicsObj` is by value at play time**, not a persistent
emitter: `SoundManager::PlaySoundA(SoundType, CPhysicsObj*)` reads
`physobj->sound_table` and `physobj->m_position` once (acclient.c:383681). A
moving object does **not** update the pan or volume of an already-playing sound.

---

## 4. `CSoundTable` and `DBWave`

`CSoundTable : SerializeUsingPackDBObj` (acclient.h:30809) has
`GetDBOType() == 34` (`0x22`, acclient.c:385565). The type→DID-prefix mapping
(`0x22` ↔ `0x20xxxxxx`, and type 15 ↔ `0x0Axxxxxx` for `DBWave`) is **inferred**
from `07-dat-resources.md`; nothing in the audio subsystem establishes it.

It contains one `SoundTableData` (acclient.h:30801), which is a **recursive
node**: an `IntrusiveHashTable<ulong, SoundTableData*>` keyed by `SoundType`,
plus `num_stdatas_` and `SoundData data_[]`. `SoundData` (acclient.h:31197) is
`{DID sound_id_, float priority_, float probability_, float volume_}`.

**Selection** (`SoundManager::GetSound`, acclient.c:383433): look up the
`SoundType` in the table hash (`CSoundTable::Lookup` → `SoundTableData::Lookup`,
acclient.c:385195, 385164); if the node has N variants, pick one with
`Random::RollDice(0,1)` scaled to `N−1`. That is the randomized-variant
mechanism. The chosen entry's `probability_` is then rolled against
`SoundManager::PlayProbability` (`rand() * 2^-15 < p`, acclient.c:383121), so a
sound can legitimately not play at all.

This is worth stating more strongly than "bias". `Random::RollDice` (105532) is
`rand() * (hi − lo) + lo`, and `Random::rand()` (105458) is an L'Ecuyer combined
LCG returning **[0, 1)** — so `(N−1) * roll` can never reach `N−1`. **The last
variant in every multi-variant node is dead data**; indices 0..N−2 are uniform.
Also note `GetSound` does not roll `probability_` itself — its callers do
(383670, 383696, 383579, and inline `rand()` forms at 383533 and 383557).

`DBWave : SerializeUsingPackDBObj, WaveFile` (acclient.h:57172) is DBO type 15
(`0x0Axxxxxx`, acclient.c:385798). Its record format (`DBWave::UnPack`,
acclient.c:384721) is trivial:

```
u32 formatSize; u32 dataSize; WAVEFORMATEX[formatSize]; bytes[dataSize];
```

A file-based fallback exists (`WaveFile::Open` / `Load` via `mmio*`,
acclient.c:386974, 386849) but `SoundBuf::useDatabase = 1`, so only the DAT path
runs.

A `CPhysicsObj` gets its table from `CSetup::default_stable_id` in
`CPhysicsObj::InitDefaults` (acclient.c:320871), or from `PhysicsDesc::stable_id`
in `CPhysicsObj::set_description` (acclient.c:322310), both via
`DBObj::Get(did, 0x22)`.

### The SoundType enum

Enumerated at **acclient.h:4569**, values 0–`0xCC`
(`NUM_SOUND_TYPES = 0xCD`, 205 values). Notable runs:

| Range | Contents |
|---|---|
| `0x01`–`0x02` | Speak1, Random |
| `0x03`–`0x08` | Attack1–3, SpecialAttack1–3 |
| `0x09`–`0x11` | Damage1–3, Wound1–3, Death1–3 |
| `0x12`–`0x1D` | Grunt / Oh / Heave / Knockdown family |
| `0x1E`–`0x20` | Swoosh1–3 |
| `0x21`–`0x2D` | Thump, Smash, Scratch, Spear, Sling, Dagger, ArrowWhiz1–2, Crossbow/Bow pull and release, ThrownWeaponRelease1 |
| `0x2E`–`0x2F` | ArrowLand, Collision |
| `0x30`–`0x36` | HitFlesh / Leather / Chain / Plate, HitMissile1–3 |
| `0x37`–`0x39` | **Footstep1, Footstep2, Walk1** |
| `0x3A`–`0x41` | Dance1–3, Hidden1–3, Eat1, Drink1 |
| `0x42`–`0x45` | Open, Close, OpenSlam, CloseSlam |
| `0x46`–`0x4E` | **Ambient1–Ambient8, Waterfall** |
| `0x4F`–`0x51` | LogOut, LogIn, LifestoneOn |
| `0x52`–`0x5D` | Attrib/Skill/Health/Shield/Enchant/Vision Up and Down |
| `0x5E`–`0x60` | Fizzle, Launch, Explode |
| `0x61`–`0x66` | TransUp/Down, BreatheFlaem/Acid/Frost/Lightning |
| `0x67`–`0x69` | Create, Destroy, Lockpicking |
| `0x6A`–`0x8A` | **the UI block** — portal in/out, GeneralQuery, GeneralError, TransientMessage, IconPickUp, SuccessfulDrop, Invalid_Drop, ButtonPress, GrabSlider, ReleaseSlider, NewTargetSelected, Roar, Bell, Chant1–2, DarkWhispers1–2, DarkLaugh, DarkWind, DarkSpeech, Drums, GhostSpeak, Breathing, Howl, LostSouls, Squeal, Thunder1–6 |
| `0x8B`–`0x97` | RaiseTrait, Wield/UnwieldObject, Receive/PickUp/DropItem, ResistSpell, PicklockFail, LockSuccess, OpenFailDueToLock, TriggerActivated, SpellExpire, ItemManaDepleted |
| `0x98`–`0xC9` | **TriggerActivated1–50** |
| `0xCA`–`0xCC` | HealthDownVoid, RegenDownVoid, SkillDownVoid |

---

## 5. Ambient sound beds

`Ambient` (acclient.h:35318) holds the listener `Position`, a
`DArray<AmbientSound*>`, a total weight, and a **priority queue of scheduled play
times**.

Two `AmbientSound` subclasses (acclient.h:35430, vtable at 35472):
`IntermitSound` (acclient.h:52830) for randomized one-shots, with per-direction
min/max distance arrays across 8 directions; and `ConstantSound`
(acclient.h:52856) for a continuous drone with a running volume.

**Selection is per landcell, by terrain type plus scene type** — not per
landblock. `CLandBlock::add_ambient_sounds` (acclient.c:352444) walks every cell,
extracts `terrain_id = (t >> 2) & 0x1F` and `scene_type_id = t >> 11` from the
terrain word, resolves `CRegionDesc::GetSTBDesc` → `CTerrainDesc::GetSTBDesc` →
`CSceneType::sound_table_desc` (acclient.c:299022, 303290), lazily loads the
STable via `AmbientSTBDesc::InitSoundTable` (acclient.c:299000), and calls
`Ambient::AddSound` with the cell's world position. `LScape::add_ambient_sounds`
(acclient.c:307180) drives that over loaded blocks.

The weight formula lives in **`Ambient::CalcWeight` (acclient.c:383857)**, not in
`AddSound` as an earlier draft said — `AddSound` (384362) merely calls it at
384377. It returns 0 past `max_dist_sq = 14400` (120 m), 1.0 inside
`min_dist_sq = 400` (20 m), and `min_dist_sq / d²` between.

`Ambient::CalcDir` (acclient.c:383880) returns 1–8 for the compass octants **and
0** when the offset is inside `min_dist_sq * 0.5`. `IntermitSound::AddTo`
(384260) treats direction 0 by registering the sound in **all eight** direction
slots (384281–384289) with a fixed [4.0, 10.0] range — an undocumented
omnidirectional close-range mode.

Weights accumulate into `total_sound_count`, and `UpdateSound` normalises:
intermittent sounds get `play_chance = base_chance * weight / total_weight`,
constant sounds get `current_volume = desc.volume * weight / total_weight`
(acclient.c:384200, 384295). **This normalised weighting is the entire crossfade
mechanism** — there is no fade envelope and no timed crossfade; volumes simply
re-derive whenever the player changes cell.

The set is rebuilt on cell change in `CellManager::ChangePosition`
(acclient.c:146646): `InitSounds` → `add_ambient_sounds` → `UpdatePlayQueue` →
`ReleaseSoundTables`, the last dropping STables whose `play_count == 0`
(acclient.c:146461).

`Ambient::UseTime` (acclient.c:384507) pops the queue whenever
`key < Timer::cur_time` and calls `Ambient::Play` (acclient.c:384452), which asks
`CanHear` / `PlayNow`, synthesises a random emitter position via
`IntermitSound::GetSoundPos` (random octant, random distance within that octant's
range, acclient.c:384212), plays through `SoundManager::PlayAmbientSound`, then
re-queues at `now + GetPlayInterval` — a `RollDice(min_rate, max_rate)` for
intermittent sounds, or just `min_rate` for constant ones.

`AmbientSoundDesc` (acclient.h:35498) is
`{SoundType stype; int is_continuous; float volume, base_chance, min_rate,
max_rate}`, where `is_continuous` is derived in `AmbientSTBDesc::UnPack`
(acclient.c:384535) as `base_chance == 0`.

---

## 6. Music: compiled in, dead in practice

There **is** a complete winmm **MIDI stream player** in the binary —
`midiSetup`, `midiPlay(filename, loop, stopprev, tempo)`, `midiPlayNext`,
`midiStop`, `midiCleanup`, `StreamBufferSetup`, `MidiProc`, `SetChannelVolume`,
with six 84-byte `MIDIHDR` stream buffers, a tempo multiplier, a per-channel
volume cache, and note-on/off callbacks (acclient.c:386258–386730).
`SoundManager::Init` calls `midiSetup()` and `ShutDown` calls `midiCleanup()`.

**However `midiPlay` is called from nowhere except `midiPlayNext`, which is
called only from `MidiProc`'s buffer-done handler.** There is no game-side entry
point, and it plays from a **file path**, not the DAT.

So there is **no MIDI music** in the shipped client.

**But an earlier draft went further and was wrong.** It claimed "no streaming
audio of any kind, and no MP3, OGG, or WMA decode." The client contains a live
**DirectShow** player: `MovieTheatre::Init` (acclient.c:724263) does
`CoCreateInstance(CLSID_FilterGraph)` (724294), adds a custom `CTextureRenderer`
(724326), calls `IGraphBuilder::AddSourceFilter(wFileName, L"SOURCE")` (724346),
finds pin `L"Output"` (724362), and then calls **`IGraphBuilder::Render(pin)`**
(724371) — which auto-renders *all* downstream streams, audio included, through
whatever DirectShow codecs and audio renderer are installed. `IMediaControl::Run`
follows at 724380.

It is reachable: `MovieTheatre::CreateTheatreForMovie` (724399) is called from
`MD_Data_Movie::Update` (693286), and `MediaMachine::Update_Movie` (162103) sits
beside `Update_Sound` (162243) in the same media-descriptor dispatch documented
in §7.

So the client *does* stream audio, from a file path, decoded by arbitrary system
codecs, entirely outside `SoundManager` and unaffected by any of the eight sound
preferences. What holds is the narrower claim: no soundtrack or MIDI music is
ever played, and `SoundManager` itself handles only DAT-embedded PCM and
ACM-decodable non-PCM WAV.

---

## 7. How sounds get triggered

### From the network — `0xF750` SoundEvent

Dispatch hits `case 0xF750` → `CM_Physics::DispatchSB_SoundEvent`
(acclient.c:392803 → 709642). The blob layout is
`u32 opcode | u32 object_id | u32 sound (SoundType) | float volume`.

It forwards to `SmartBox::HandleSoundEvent` (acclient.c:143333), which resolves
the object via `CObjectMaint::GetObjectA`. If the object isn't known yet the blob
is **queued on the object** (return code 4 = defer) and replayed on creation.
Otherwise `CPhysicsObj::play_sound(type, volume)` (acclient.c:316424) calls
`SoundManager::PlaySoundA`.

**The server only ever sends an abstract `SoundType` plus a volume** — the wave
choice is entirely client-side, from the object's own STable.

### From animation hooks — where footsteps actually come from

The other server-driven route is animation hooks embedded in motion data:
`SoundHook` (absolute wave DID, acclient.c:342188), `SoundTweakedHook` (DID plus
priority/probability/volume overrides, defaults 0.9 / 1.0 / 1.0,
acclient.c:342207), and `SoundTableHook` (a `SoundType` resolved against the
object's own table, acclient.c:342219).

**This is how footsteps and weapon swings fire.** `Sound_Footstep1/2`,
`Sound_Swoosh*` and friends are never referenced by name in code; they are
emitted by `SoundTableHook`s authored into animation frames.

**There is no surface-type-dependent footstep logic.** No landblock surface query
feeds sound selection; variation comes only from the STable's random variant list
for that `SoundType`.

### Collisions produce no direct audio

`CPhysicsObj::report_environment_collision` (acclient.c:320194) and
`report_object_collision` (acclient.c:320228) build collision profiles and hand
them to `CWeenieObject` virtuals — **they play no sound directly**.
`Sound_Collision (0x2F)` is never referenced in client code; collision sounds
arrive only as server-sent `0xF750` events.

### UI sounds

Two routes, both through `PlaySoundFromCenter` (pan 0, distance 0):

1. **`MD_Data_Sound` media descriptors** (acclient.h:34146 —
   `{DID m_file; SoundType m_stype}`) executed by `MediaMachine::Update_Sound`
   (acclient.c:162243). If `m_stype != 0`, `m_file` is an STable DID
   (`DBObj::Get(..., 0x22)`) and the type is looked up in it; if `m_stype == 0`,
   `m_file` is a direct wave DID played at volume 1.0. The
   `Sound_UI_ButtonPress`, `IconPickUp`, `GeneralError` constants appear **only**
   in the enum and never in code — they are authored into DAT UI media scripts.
2. **Hard-coded calls** using `ClientUISystem::GetUISoundTable`
   (acclient.c:401286, `DBObj::GetByEnum(0x10000003, 7, 0x22)`): teleport in/out
   in `gmSmartBoxUI::BeginTeleportAnimation` and `UseTime` (acclient.c:261845,
   262562), and the admin `/environs` sound bank in
   `CPlayerSystem::Handle_Admin__Environs` (function 396298, calls spanning
   **396439–396539**) — a bank of 22 sounds including Roar, Bell, Chant,
   DarkWhispers, Drums, and Thunder.

---

## 8. Options and gains

`SoundManager::InitPrefs` (acclient.c:383284) registers eight `UserPreferences`
entries: `Sound.SoundVolume` → `effect_sound_volume`,
`Sound.AmbientSoundVolume` → `ambient_sound_volume`,
`Sound.InterfaceSoundVolume` → `interface_sound_volume`,
`Sound.SoundFeatures` (an enum with choices "Stereo" and "Mono",
acclient.c:**793517–793518**), `Sound.SoundDisabled`, `Sound.AmbientSoundDisabled`,
`Sound.InterfaceSoundDisabled`, and `Sound.PlaySoundOnlyWhenActive`.

Two negative findings worth recording:

**`interface_sound_volume` is registered but never read.** `GetAttenuation` only
consumes `ambient_sound_volume` on the ambient path and `effect_sound_volume`
everywhere else — so UI sounds are scaled by the *effects* slider and the
Interface volume slider is a no-op. Only its matching
`interface_sounds_enabled` boolean has any effect.

**The three "Disabled" booleans gate whole categories rather than muting.** They
are checked at the entry points (`PlaySoundA`, `PlayAmbientSound*`,
`PlaySoundFromCenter`), so a disabled category never reaches the mixer at all.

Constants: `SoundManager::VOL_MIN = −50` dB (acclient.c:45626),
`VOL_MIN_DIST_SQ = 25.0` (acclient.c:793567),
`Ambient::ambient_sound_min_dist = 20`, `min_dist_sq = 400`,
`max_dist_sq = 14400`, `min_vol = 0.03` (acclient.c:45647–45650).
