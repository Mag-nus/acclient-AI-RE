# Physics, Collision, Movement, and World Geometry

Target: acclient.exe 11.4186 (September 2013). Line references are into
`../acclient.c` and `../acclient.h` unless noted.

> **Revision note.** Three passes. The third pass found that §4's claim about
> smooth in-between motion was **structurally backwards**, that the
> TurnLeft/TurnRight command IDs were **swapped**, and that the document omitted
> the single most important timing fact in the subsystem — the 30 Hz outer gate
> (§2). All corrected below.

---

## 1. Class hierarchy and data layout

**`CPhysicsObj`** (acclient.h:30689) derives from `LongHashData`, keyed by object
IID: 230 bodies across 218 distinct method names.

Notable members: `part_array`; `player_vector` / `player_distance`;
`parent` / `children`; `m_position`; `cell`; `shadow_objects`; `state` /
`transient_state`; `elasticity` / `friction` / `massinv`; `movement_manager` /
`position_manager`; `m_velocityVector` / `m_accelerationVector` /
`m_omegaVector`; `detection_manager` / `attack_manager` / `target_manager` /
`particle_manager`; `weenie_obj`; `contact_plane` / `sliding_normal` /
`cached_velocity`; `collision_table`.

**`PhysicsState`** (acclient.h:2815): `STATIC_PS 0x1`, `ETHEREAL_PS 0x4`,
`REPORT_COLLISIONS_PS 0x8`, `MISSILE_PS 0x40`, `ALIGNPATH_PS 0x100`,
`GRAVITY_PS 0x400`, `HIDDEN_PS 0x4000`, `HAS_PHYSICS_BSP_PS 0x10000`,
`INELASTIC_PS 0x20000`, `REPORT_COLLISIONS_AS_ENVIRONMENT_PS 0x200000`,
`EDGE_SLIDE_PS 0x400000`, **`SLEDDING_PS 0x800000`** (value at acclient.h:2839),
`FROZEN_PS 0x1000000`.

**`TransientState`** (acclient.h:3688): `CONTACT_TS 0x1`, `ON_WALKABLE_TS 0x2`,
`SLIDING_TS 0x4`, `WATER_CONTACT_TS 0x8`, `STATIONARY_FALL/STOP/STUCK_TS
0x10/0x20/0x40`, `ACTIVE_TS 0x80`, `CHECK_ETHEREAL_TS 0x100`.

### Position and Frame

`Frame` (acclient.h:30647) holds a quaternion plus a cached 3×3 matrix
`m_fl2gv[9]` and `m_fOrigin`. `Position : PackObj` (acclient.h:30658) is
`{objcell_id, Frame}`.

### Geometry

`CPartArray` (acclient.h:30762) owns a `CSequence`, `MotionTableManager`,
`CSetup`, and `CPhysicsPart** parts`.

`CSetup` (acclient.h:31119) is the archetype: part DIDs, `parent_index`,
`CSphere`s and `CCylSphere`s (`{low_pt, height, radius}`, acclient.h:31672),
`has_physics_bsp`, `step_down_height` and `step_up_height` (declared in that
order), sorting and selection spheres, placement frames, default IDs.

`BSPNODE` (acclient.h:32157) has virtual `sphere_intersects_solid`
(acclient.c:363574), `hits_walkable` (363615), and `find_walkable` (**363663**).

### Cells

`CObjCell` (acclient.h:30915) extends `CPartCell`. `CSortCell` adds `building`;
`CLandCell` (acclient.h:31886) adds terrain `polygons`; `CEnvCell`
(acclient.h:32072) carries `structure`, `portals`, static objects, and a
`light_array` of pre-lit vertex colors.

`CLandBlock` (acclient.h:31337) holds a `CLandBlockInfo *lbi`. **There is no
declared 8×8 array** — the grid is inherited from `CLandBlockStruct`
(acclient.h:31310) as a flat `CLandCell *lcell` (31325) plus a runtime
`side_cell_count` (31316), indexed over `side_cell_count²`
(acclient.c:306799–306808) and asserted equal to 8 (307495, 308183). The 8×8 is a
runtime fact, not a type fact.

Cell-ID encoding, `CLandCell::add_outside_cell` (acclient.c:354975, expression at
354983/354986):

```c
(((y >> 3) | 32*(x & 0xFFFFFFF8)) << 16) | ((y & 7) + 8*(x & 7) + 1)
```

`LandDefs::gid_to_lcoord` (209521) treats a low word below `0x100` as outdoor
(209529). `get_block_offset` (123110): same block gives zero, otherwise
Δblock × 24.0 with z = 0 — which is why dungeon coordinates are block-local.

### Object bookkeeping

`CObjectMaint` (acclient.h:33078): `object_table`, `null_object_table`,
`weenie_object_table` / `null_weenie_object_table`, `visible_object_table`,
`lost_cell_table` (33082), `destruction_object_table` (33088),
`object_inventory_table` (33089), and `object_destruction_queue` (33090).

---

## 2. Per-frame control flow

### The 30 Hz outer gate

**`CPhysics::UseTime` (acclient.c:311335) does nothing at all unless
`Timer::cur_time − last_update >= MIN_QUANTUM_93` (1/30 s), tested at
acclient.c:311352.** This is the real physics frame-rate limiter, and it matters
for understanding §4 — physics ticks and animation frames both run at ~30 Hz.

When it does run, it iterates the maintenance hash calling
`CPhysicsObj::update_object`, then `SmartBox::PlayerPhysicsUpdatedCallback` for
the player, then animates static objects (and calls `UpdateTexVelocity`).

### Activity culling

`update_object` (acclient.c:323081) skips `parent`, cell-less, and `FROZEN_PS`
objects (323099). At 323114 it tests `v4 > 96.0 && CPhysicsObj::obj_maint->is_active`
and clears `ACTIVE_TS` at 323115.

Note on the co-condition: `is_active` is set to 1 in the `CObjectMaint`
constructor (310043) and cleared in exactly one place — `if (testMode != 0)` at
146213. **In shipped play the 96-unit cull is always on.** An earlier draft
implied a gameplay-visible mode; there isn't one.

`ACTIVE_TS` matters more broadly than the cull: `UpdateObjectInternal` runs its
entire body only for active objects (gate at 322758), and
`UpdatePhysicsInternal` self-deactivates a stationary object with no
`movement_manager` (317731–317735).

### Time quantization

At acclient.c:323123–323144: dt must exceed 0.00019999999 or it is a resync; dt
above 2.0 is discarded; then `if (v6 <= MAX_QUANTUM_97) goto LABEL_21` — **a dt
smaller than `MAX_QUANTUM` is stepped whole, with no `MIN_QUANTUM` test at all.**
The `MIN_QUANTUM_97` test at 323138 gates only the remainder after the
full-quantum loop.

The live initializers are at acclient.c:784229 (`MIN_QUANTUM_97 = 1.0/30.0`) and
784235 (`MAX_QUANTUM_97 = 1.0/5.0`).

A correction on the duplicates: there are 100 copies of each constant
(`MIN_QUANTUM` plus `MIN_QUANTUM_0`…`_98`), and **all of them are set to 1/30 and
1/5 by static-init thunks** — `MIN_QUANTUM` itself at acclient.c:731343. The
`= 0.0` at acclient.c:46730–46731 is IDA's BSS placeholder, not a runtime value.
An earlier draft called them "0.0 decoys"; the correct statement is simply that
only the `_93` and `_97` copies are ever read. The complete set of read sites is
311352 (`_93`), 321170 and 321678 (`_97`), and 323127–323138 (`_97`).

### The update chain

`UpdateObjectInternal` (322719) builds an identity `new_pos` (322765–322774) and
calls **`UpdatePositionInternal`** (319989), which:

1. Calls `CPartArray::Update` → `CSequence::update` (325140/325142), scaling root
   motion by `m_scale` when `ON_WALKABLE_TS` and by 0.0 otherwise
   (320014–320026). **Skipped entirely when `HIDDEN_PS` is set** (320009).
2. Calls `PositionManager::adjust_offset` (320030).
3. Calls **`UpdatePhysicsInternal`** (317701) — also skipped under `HIDDEN_PS`
   (320033) — then `process_hooks` (320035).

`UpdatePhysicsInternal` clamps velocity at 50 u/s (317740–317747, comparing
`velocity_mag2` against `50.0*50.0`), applies `calc_friction` (317749), zeroes
velocities under 0.25 u/s (317750), then integrates
`x += v*dt + 0.5*a*dt*dt` and `v += a*dt` (317756–317780) plus `Frame::grotate`
(317783).

`calc_acceleration` (317787) zeroes both acceleration and omega when
`CONTACT_TS && ON_WALKABLE_TS && !SLEDDING_PS` (317797–317808); otherwise applies
`PhysicsGlobals::gravity = -9.8000002` (acclient.c:45824) when `GRAVITY_PS` is
set (317814–317819).

**Heading alignment is an either/or, not two independent behaviours.** At
acclient.c:322800, `ALIGNPATH_PS` aligns heading to the **position delta**
(`new_pos.origin − m_position.origin`) via `set_vector_heading` (322802–322804) —
not to velocity. Only in the `else if` branch (322806) do `SLEDDING_PS` objects
with nonzero velocity yaw-align to velocity (322806–322810).

On success `cached_velocity = offset / quantum` (322816–322828) and
`SetPositionInternal` commits; on failure the position is restored and
`cached_velocity` zeroed (322833–322845). The frame then ticks DetectionManager,
TargetManager, `MovementManager::UseTime`, `CPartArray::HandleMovement`,
`PositionManager::UseTime`, particles, and scripts (322871–322890).

### The impulse solver

Collision response is **not** merely slide/step/stop. `handle_all_collisions`
(acclient.c:321808) applies a genuine restitution impulse at 321876–321886:

```c
v13 = v·n;  v14 = -(v13 * (elasticity + 1.0));  v += v14 * n;
```

Four guards, three of which earlier drafts omitted:

- the whole block requires `frames_stationary_fall <= 1` (321863); above that,
  velocity is zeroed unconditionally (321891–321894) regardless of elasticity
- requires `collisions->collision_normal_valid` (321865)
- the impulse applies only when `v·n < 0.0` (321879), i.e. approaching
- `INELASTIC_PS` (`0x20000`) zeroes velocity instead of bouncing (321867–321872)

Bounce is suppressed when the object was and remains on walkable ground unless
`SLEDDING_PS` (321829–321832) — which is what makes sledding a distinct mode.

### Committing

`SetPositionInternal` (322504) fires `LeaveGround` (322610–322612), copies
`sliding_normal` into `SLIDING_TS` (322616–322625), and calls
`handle_all_collisions` (322626).

Cell residency splits two ways: `calc_cross_cells` (body 322447) runs **only when
`state & 0x10000`** (`HAS_PHYSICS_BSP_PS`), gated at **322629** with the call at
322631. Everything else diffs the transition's own `cell_array` via
`remove_shadows_from_cells` / `add_shadows_to_cells` at **322636–322637**.

---

## 3. The `CTransition` collision machine

`CTransition` (acclient.h:52329) = `OBJECTINFO` (init acclient.c:314118),
`SPHEREPATH` (acclient.h:32625), `COLLISIONINFO` (acclient.h:52306), and a
`CELLARRAY`.

Transitions come from a **static pool of 10**: `makeTransition` (body
acclient.c:**312543**) constructs ten at 312553–312561 and returns 0 once
`transition_level >= 10` (**312564**). `cleanupTransition` (311589) decrements.

`CPhysicsObj::transition` (320061) seeds `frames_stationary_fall` from the
`STATIONARY_*` bits at 320104–320116 (`&0x40`→3, `&0x20`→2, `&0x10`→1) and calls
`find_valid_position` (313419), which dispatches on `sphere_path.insert_type`
(313423).

### The walkable slope constant

`PhysicsGlobals::floor_z` is initialized at acclient.c:800530 inside static-init
thunk `sub_70D920`:

```c
PhysicsGlobals::floor_z = cos(3437.746770784939);
```

The alternate 6.95 decompilation (791206) is byte-identical, and the **2015
client 11.6096 decompiled by Hex-Rays 6.6** carries the same line at
`acclient 6.6.14.605 Diffed.c:793086`. Two binaries, two decompilers, one
literal — this is not an artifact.

`3437.7467707849396` is exactly `60 × 180/π`, so the source contained a
degrees-for-radians inversion. The `cos` runs at load time:

```
cos(3437.7467707849) = 0.6641741461866  →  float32 0.66417414  →  acos ≈ 48.381°
```

Every read of `floor_z` in the binary: `is_valid_walkable` (316502,
`normal->z >= floor_z`), the getter `get_walkable_z` (316509), and
`SetPositionInternal` (322600, `if (contact_plane.N.z < floor_z) set_on_walkable(0)`).
There is **no `set_floor_z` and no other writer** — the only write anywhere is
800530. The same holds in the 2015 build.

So the maximum walkable slope really is ≈48.38°, not the intended 60°.

`z_for_landing = 0.0871557` (sin 5°, acclient.c:40376) is the non-walking
allowance, used at 313381, 359132, and 362028, and as `step_down`'s `z_val` at
313393, 313398, and 313405.

### Sub-stepping

`find_transitional_position` (313171) divides displacement using `calc_num_steps`
(311764): `floor(dist/radius)+1` when `object_info.state & 4`, otherwise
`ceil(dist/radius)` (311796–311835). Bit `0x4` is `IS_VIEWER_OI`
(`ObjectInfoEnum`, acclient.h:6182), which makes this "the viewer gets one extra
step" — an odd reading, stated here without interpretation.

Rotation is slerped per step (`Frame::interpolate_rotation`, 313279), and each
step calls `transitional_insert` (312834) then `validate_transition` (313308).

`transitional_insert`'s retry count is a **caller-supplied parameter**, not a
fixed N: 3 from `find_transitional_position` (313290/313307), 5 from `step_down`
(312662), 1 from the confirmation re-insert (312673); the limit check is at
313002–313004.

On collision it does one of:

- **Slide** — `CSphere::slide_sphere` (358899) primarily projects onto
  `cross(collision_normal, contact_plane.N)`, the intersection line of the two
  planes (358954–358980). Projecting onto the plane perpendicular to the
  collision normal is only the degenerate fallback (358982–358998).
- **Step up** (312794) — sets `step_up_normal` (312806), calls
  `step_down(step_up_height, walkable_z)` (312812/312818), falls back to
  `step_up_slide` (312955–312957).
- **Step down** (312629) — accepts only if `contact_plane.N.z >= z_val` (312666).
  The halving lives in the *caller*: `transitional_insert` sets
  `step_down_ht = radius * 0.5` when `num_sphere < 2 && 2*radius < step_down_ht`
  (312975–312980), then applies a **single** `* 0.5` at 312991 and calls
  `step_down` **twice with that same value** (312993). One halving, two attempts.
- **Edge slide** (312685) → `cliff_slide` (312714) / `precipice_slide` (312725,
  312762). The gate at 312707 requires `ON_WALKABLE_OI | EDGE_SLIDE_OI` — the
  `EDGE_SLIDE_OI` bit is set from `state & 0x400000` in `get_object_info`
  (319085–319086), so "EDGE_SLIDE_PS objects" is right, but the additional
  on-walkable requirement matters. `cliff_slide` (312005) crosses the current and
  last contact normals (312028–312033), zeroes z (312037), and clamps
  (312053–312076).

### The stationary-fall failsafe

`validate_transition` (312194) fabricates a plane `N = (0,0,1)`,
`d = radius − center.z` at 312294–312300, and flags an environment collision at
312306 — reached only on the third consecutive frame **and** only when
`(object_info.state & 1) == 0`, i.e. not already in contact (312301–312307).

The counter is broader than "OK_TS with unchanged position." The controlling
`redoa` flag (312217–312221) is 0 in two cases: `ts == OK_TS(1)` with unchanged
cell and frame, **or** `ts` in {2,3,4} (collision/adjusted/slid) whenever the
last-known-contact-plane re-establish at 312235–312242 did not fire. The whole
mechanism is gated on not-ethereal and `GRAVITY_PS` (312272–312275). Reset at
312279; increments at 312312 (0→1), 312288 (1→2), 312293 (2→3).

### Per-cell dispatch

`CEnvCell::find_env_collisions` (347823) runs the physics BSP through
`BSPTREE::find_collisions` (361296).

**`CLandCell::find_collisions` (354887) does not test terrain polygons** — it
dispatches to `find_env_collisions`, `CSortCell::find_collisions`, and
`find_obj_collisions`. The two-polygon loop lives in
`CLandCell::find_terrain_poly` (**354859**, loop at 354873). `CSortCell` reaches
`CBuildingObj::find_building_collisions` (356107/356114).

Object-vs-object: `find_obj_collisions` (347142) → `CSphere::intersects_sphere`
(359157). The primitive is `CPolygon::polygon_hits_sphere` (359916), with
`polygon_hits_sphere_slow_but_sure` at **360007**.

### Cell residency and portals

`CObjCell::find_cell_list` has four overloads (346961, 347316, 347322, 347337).
The cylsphere overload **silently clamps to 10** at **347351–347358**, copying
into a file-static scratch array with no diagnostic.

The core overload branches on `(u16)cell_id >= 0x100` → `CEnvCell::GetVisible`
plus `hits_interior_cell` (346994–347003), else `CLandCell::Get` and
`add_all_outside_cells` (346996/347007), then virtual-dispatches
`find_transit_cells` over the array (347012–347026).

`CEnvCell::find_transit_cells` (348250) adds an epsilon of `0.00019999999` to the
radius (348315) and accepts on `> -ia && < ia` (348321); portal ID −1 opens to
the outdoors (348301).

---

## 4. Animation is frame-quantized in *both* root motion and velocity

`CSequence::update` (340951) calls `update_internal` (340659) then `apricot`
(339893).

`update_internal` advances `frame_number += framerate * quantum` (340690/340695),
then loops over each integer boundary crossed (340713), calling
`Frame::combine(retval, retval, get_pos_frame(n))` (340719–340720). Reverse
playback uses `Frame::subtract1` (340753) walking backwards (340746–340759).
**There is no keyframe interpolation anywhere.**

**The correction.** An earlier draft claimed that between frames the authored
velocity provides smooth motion. It does not. `CSequence::apply_physics` (339860)
is called *inside* the per-frame loop, once per boundary crossed, with
`dt = 1.0/framerate` (340723 forward, 340756 reverse) — one frame's worth of
velocity applied in a lump at the boundary. It receives the true `quantum` only
when `framerate * quantum == 0` (340778–340779) or when `anim_list` is empty
(`CSequence::update`, 340963).

The consequence is the opposite of what that draft said: with a nonzero framerate
and **no** boundary crossed in a quantum, the loop body never runs and
`update_internal` **returns at 340762–340763 having contributed nothing** — no
root motion and no velocity. Authored velocity is quantized to animation frames
exactly like root motion.

In practice this is invisible because `CPhysics::UseTime` is itself gated to
1/30 s (§2) and animations run at roughly 30 fps, so a boundary is crossed nearly
every tick. That coincidence — not interpolation — is why the game does not look
steppy.

### Hooks

`execute_hooks` (339683) pushes each `AnimFrame` hook onto the object, filtering
`if (!direction_ || dir == direction_)`.

`process_hooks` (318641) first drains the `PhysicsObjHook` list, deleting hooks
whose `Execute` returns true (318655–318675) — these are the interpolating
`FPHook` / `VectorHook` tweens (acclient.h:57589, 57596) — then fires and clears
the one-shot `anim_hooks` array (318677–318688).

There are 26 direct `CAnimHook` subclasses at acclient.h:57405–57583, with bodies
from acclient.c:342188 (`SoundHook::Execute`) to 342590 (`SetLightHook::Execute`):
`NOOPHook`; `SoundHook` / `SoundTableHook` / `SoundTweakedHook`;
`ReplaceObjectHook`; `AttackHook`; `EtherealHook`; `NoDrawHook`;
`DefaultScriptHook` / `DefaultScriptPartHook`; `TransparentHook` /
`TransparentPartHook`; `LuminousHook` / `LuminousPartHook`; `DiffuseHook` /
`DiffusePartHook`; `ScaleHook`; `CreateParticleHook` (with
`CreateBlockingParticleHook` derived from it); `DestroyParticleHook`;
`StopParticleHook`; `CallPESHook`; `AnimDoneHook`; `SetOmegaHook`;
`TextureVelocityHook` / `TextureVelocityPartHook`; `SetLightHook`.

`apricot` (339893) deletes finished non-cyclic nodes from the head of
`anim_list`, stopping at `curr_anim` or `first_cyclic`.

---

## 5. Motion: commands to animation chains

`MovementManager::PerformMovement` (339175) fans types 1–5 to `CMotionInterp` and
6–9 to `MoveToManager`.

### The command ID tables

Command IDs are recovered by index-aligning `command_strings[408]`
(acclient.c:43453) with `command_ids_1[408]` (acclient.c:43864):

| Index | String | ID |
|---|---|---|
| 3 | `Ready` | `0x41000003` |
| 13 | **`TurnRight`** | **`0x6500000D`** |
| 14 | **`TurnLeft`** | **`0x6500000E`** |
| 15 | `SideStepRight` | `0x6500000F` |
| 16 | `SideStepLeft` | `0x65000010` |
| 60 | `HandCombat` | `0x8000003C` |

**Earlier drafts had TurnLeft and TurnRight swapped.** Anyone reimplementing
input handling from those drafts would have turned the wrong way.

### The motion table

`CMotionTable` (acclient.h:31654) is four hash tables: `style_defaults`,
`cycles`, `modifiers`, `links`.

`MotionData` (acclient.h:31763) carries the authored `velocity`, which
`add_motion` (337431) installs as
`CSequence::set_velocity(speed_mod * data->velocity)` (337445–337451) before
appending each `AnimData` scaled by `speed_mod`.

`GetObjectSequence` (337641) decodes bit `0x80000000` as a style change (337699)
and `0x40000000` as a cycle (337763); the cycle key is
`motion & 0xFFFFFF | (style << 16)` with a `default_style` fallback
(337765/337768). `get_link` (337585) keys `(style << 16) | (substate & 0xFFFFFF)`
and reverses the lookup when either speed is negative. `re_modify` (337286),
`change_cycle_speed` (337269), `subtract_motion` (337506), and `combine_motion`
(337477) retune a running sequence rather than restarting it.

`MotionTableManager` queues an `AnimNode` per command (`add_to_queue`, 330149)
and counts `AnimDoneHook` firings. `AnimationDone` (329873) pops
`MotionState::action_head` when `motion & 0x10000000` — note this happens
*before* `MotionDone`, not after. `HandleExitWorld` (329940) force-completes with
`success = 0`.

### Input canonicalization and speeds

`CMotionInterp::adjust_motion` (343746) canonicalizes input. It turns
**`TurnLeft (0x6500000E)` into `TurnRight (0x6500000D)`** with negated speed
(343764–343767); `WalkBackwards (0x45000006)` into `WalkForward` at −0.65×;
`SideStepLeft (0x65000010)` into `SideStepRight` negated; and multiplies sidestep
speed by `3.1199999 / 1.25 * 0.5` = 1.24799996 at **acclient.c:343786**.

`get_state_velocity` (343539) then applies sidestep 1.25 (343553), walk 3.1199999
(343561), run 4.0 (343565), with magnitude capped at `run_rate * 4.0`
(343586–343592).

The composition is verifiable end to end: at 344278
`interpreted_state.sidestep_speed = raw_state.sidestep_speed`, then
`adjust_motion` is called on that same field (344286–344290), so the 1.248 is
written into what `get_state_velocity` later reads. **Effective sidestep is
1.25 × 1.248 ≈ 1.56.**

`apply_run_to_command` (343439) runs at the *end* of `adjust_motion` (343802) —
after the 1.248 — upgrading walk to run, scaling turn by 1.5 (343469), and
clamping speed to ±3.0 (343474–343480). So maximum sidestep is 1.25 × 3.0 = 3.75.
`get_max_speed` is `run_rate * 4.0` (343486).

### Jumping

`charge_jump` (343845) sets `standing_longjump` only when `CONTACT_TS` **and**
`ON_WALKABLE_TS` **and** `forward_command == 0x41000003` (Ready) **and** no
sidestep **and** no turn (343866–343871) — dead standing still. There is an
earlier early-out at 343858 for forward commands `0x40000008` and
`0x41000012`–`0x41000014`.

`get_jump_v_z` (343343) defaults to 10 u/s. `get_leave_ground_velocity` (343806)
sets `v = state_velocity` and `v.z = jump_v_z` in **local** space
(343814–343819); the `m_fl2gv` rotation (343824–343838) is a fallback used only
when all three components are near zero.

### MoveToManager

`UseTime` (body **346018**) services the head node only while `CONTACT_TS`
(**346027**).

`HandleMoveToPosition` (345577) corrects heading first: above **20°** error
(345636) it issues `TurnRight` / `TurnLeft` as `aux_command` (345646–345652).

`GetCurrentDistance` (344856) uses `cylinder_distance` when the `use_spheres` bit
is set (344880), else `distance` (344884).

`CheckProgressMade` (344833): after 1.0 s (344843), a closing rate under 0.25 u/s
either since the last sample (344847) or since the start (344849) means progress
is lost. Exceeding `fail_distance` cancels with `0x3D` (345691–345692); loss of
visibility gives `0x37` (346086) or `0x38` (346108).

`fail_progress_count` is incremented in **two** places (345659, 345769), zeroed in
four, and **never read** — dead code.

On arrival with the sticky bit, `BeginNextNode` (345521) calls
`PositionManager::StickTo` (345565).

### PositionManager sub-managers

`adjust_offset` (388287) combines three:

**InterpolationManager** (389178) moves at `min(2 × max speed,
MAX_INTERPOLATED_VELOCITY = 7.5)` (multiply 389237; constant at
acclient.c:41536), completing within 0.050000001 (389217/389258). Every 5 frames
(389244) it audits: under 30% of theoretical closing rate (389248) fails the node
via `node_fail_counter` and `NodeCompleted(0)` (389272–389273), unless within 0.2
units, which is `NodeCompleted(1)` (389270). Sticky objects bypass the audit.

**StickyManager** (388519) holds a 0.30000001 standoff (388559), moves at
`get_max_speed * 5.0` (388572) with a 15.0 fallback (388578–388579), and re-aims
heading (388593–388600). `UseTime` (388605) drops the stick on timeout.

**ConstraintManager** (389478) scales the offset by `(max − offset)/(max − start)`
(389493–389495), hard-zeroes past the max (389500–389503), and accumulates the
*post-scale* magnitude (389506–389509).

---

## 6. Physics scripts and particles

`PhysicsScript` (acclient.h:31801) holds `PhysicsScriptData {start_time,
CAnimHook*}` (acclient.h:31992) — **scripts reuse the animation hook
vocabulary**.

`ScriptManager` (acclient.h:30815); `UpdateScripts` (329189) fires due hooks and
chains `next_data`, so scripts can overlap.

`CPhysicsObj::play_script` (320326) → `PhysicsScriptTable::GetScript` (336931),
which hashes `type % m_numBuckets` and picks a variant by intensity.
`PS_Invalid 0` (acclient.h:2628), `PS_Launch 4` (2632), `PS_Explode 5` (2633).

`ParticleEmitterInfo` (acclient.h:52409): `emitter_type`
(`BirthratePerSec_ET 1` / `BirthratePerMeter_ET 2`, acclient.h:7228–7229),
`particle_type` (`Unknown_PT 0` through `GlobalVelocity_PT 0xC`,
`NumParticleType = 0xD` — so 12 real types), `birthrate`, `max_particles`,
`total_particles`, `total_seconds`, `lifespan` and `lifespan_rand`, `offset_dir`
with min/max, three motion vectors with randomization, start/final scale and
translucency, plus `is_parent_local`, `gfxobj_id`, `hw_gfxobj_id`,
`initial_particles`, `sorting_sphere`, `scale_rand`, `trans_rand`.

`Particle::Update` (330313) is genuinely closed-form: position is written
directly as `parent + offset [+ a·t] [+ 0.5·b·t²] [+ c-term]`, with only
`lifetime` accumulating. Scale and translucency are closed-form lerps on
`lifetime / lifespan`.

`ShouldEmitParticle` (330613) uses a distance delta from `last_emit_offset` for
per-metre emitters.

`CPhysicsObj::ShouldDrawParticles` (body **317184**, distance test 317192) gates
degradation. The degraded branch does **not** keep advancing lifetimes: finite
emitters compute lifetime once, then `KillParticle` and stop (331138–331182);
infinite emitters **reset every particle's birthtime to now** (331175), freezing
lifetime near zero. `Particle::Update` is skipped either way.

---

## 7. Detection, targeting, and streaming

`DetectionManager` runs at 1 Hz — the gate is at acclient.c:**327688** — over a
`LongNIHash<DetectionCylsphere>`. The test at 327037 is
`if (object_radius + detcyl->radius <= distance)` → *out of range*, so in-range is
strict `<`. Returns `NoChangeDetection 0`, `EnteredDetection 1`,
`LeftDetection 2`.

`TargetManager` (acclient.h:31024) is interpolation-based:
`GetInterpolatedPosition` (328131) is `pos + velocity * quantum`, with a
`voyeur_table` for subscribers. `MoveToManager` calls
`set_target_quantum(distance / speed)` on more than 1 s of drift
(**345703–345704**).

**Landblock streaming**: `CellManager::PreFetchCells` (146528) →
`LScape::PreFetchCells` (307068) walks `(2 × mid_radius + 1)²` blocks
(`SetMidRadius` 306429/306440) and prefetches DID `blockid | 0xFFFF` as type 1
(307124) — the landblock terrain and heightmap file, consumed as `CLandBlock` at
307149 — falling back to `(id & 0xFFFFFFFE) | 0xFFFE` as type 2
(307141–307142) for LandBlockInfo. Individual cells arrive later via
`CLandBlock::PreFetchCells`.

`LScape::update_loadpoint` (308283) rebuilds only on a real block shift
(308340), and `CellManager::UpdateLoadPoint` (146439) gates on
`(u16)objcell_id < 0x100`, so **dungeons never stream landblocks**.

Progress reaches the UI through `ECM_DDD::SendNotice_RuntimeDDDStatus` — despite
the DDD name its only four call sites are in `CellManager` (146573, 146589,
146594, 146638), consumed by `gmPowerbarUI::RecvNotice_RuntimeDDDStatus`
(265135).

---

## 8. Networking hand-off

The client is authoritative for its own motion.
`CommandInterpreter::SendMovementEvent` (718142) builds a **`MoveToStatePack`**
(718161/718187), *not* an `AutonomousPositionPack`; the latter is built by
`CommandInterpreter::SendPositionEvent` (718202, construction 718239) and by
`ACCmdInterp::SendAutonomousPositionEvent` (435905). The
`AutonomousPositionPack` constructor is at 323904 and carries position, contact
flag, and instance/server-control/teleport/force-position timestamps.

Inbound state arrives as a `PhysicsDesc` applied by
`CPhysicsObj::unpack_movement` (319254); `MovementManager::unpack_movement` is at
339492. `last_move_was_autonomous` (acclient.h:30717) distinguishes echoes.

Collisions reach game logic through `report_environment_collision` (320194, gated
on `state & 8` at 320207) and `report_object_collision` (320228), carrying
`EnvCollisionProfile` (acclient.h:33094) and `ObjCollisionProfile`
(acclient.h:33101). `REPORT_COLLISIONS_AS_ENVIRONMENT_PS` re-routes at
320249–320251.

**The `collision_table` dedup is not in either reporter.** It lives in
`CPhysicsObj::track_object_collision` (321217), which lazily allocates the table
(321234–321241) and calls `report_object_collision` only when
`LongNIValHash::clobber` reports the id was absent (321249–321252).

---

## 9. Decompiler traps

**Hex-Rays substitutes string literals for large immediates.** `0x800000` renders
as `(unsigned int)"activation type (%s) with '%s' because of its toggle type
(%s)"`. Proof: acclient.c:173725 tests it and 173726 clears it with
`& 0xFF7FFFFF`. In physics it is `SLEDDING_PS`; in the enchantment registry it is
`Vitae_EnchantmentType`; in inventory it is `MISSILE_AMMO_LOC`. The 2015
decompilation renders the same immediate as `&aActivationType` — a second opinion
does not settle it, only the header enum does.

**Not every strange constant is damage.** `floor_z`'s `cos(3437.7467…)` is a real
units bug in Turbine's source, reproduced identically across two binaries and two
decompiler versions. See §3.

**IDA's `= 0.0` on a global may be a BSS placeholder.** The 100 `MIN_QUANTUM`
copies all get real values from static-init thunks; only the referenced ones
matter.

**Two IDA misnamings in the animation code.** `MD_Data_Fade::GetDuration`
(694302) actually returns `framerate`, and `PhysicsDesc::get_animframe_id`
returns offset +20, which in `AnimSequenceNode` (acclient.h:31063) is
`low_frame`. `get_starting_frame` / `get_ending_frame` are at **341016** and
**341028**, flipping on negative framerate and biasing by −0.00019999999.

**Some Hex-Rays output is reconstructed from FPU flags.** `apply_physics`'s sign
handling (`v5 = fabs(quantum); if (v6) v5 = -v5;` with `v6` unassigned) and
`update_object`'s `while (!(v11 | v12))` are both flag artifacts. The semantics
are clear from context but were not literally read.
