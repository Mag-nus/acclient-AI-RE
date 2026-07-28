# The Renderer and Graphics Pipeline

Target: acclient.exe 11.4186 (September 2013). Line references are into
`../acclient.c` and `../acclient.h` unless noted.

> **Revision note.** Written in a first pass, then verified line-by-line in a
> second pass. Several first-pass claims were wrong: alpha-list sorting,
> stippling, `DrawPrimitiveUP` being a fallback, and the nature of
> `CShadowObj`/`CShadowPart`. The second pass also found something the first
> missed entirely — this binary contains **two independent rendering stacks**
> (§2). See §12 for traps.

---

## 1. API layer: Direct3D 9, loaded dynamically

The client uses **Direct3D 9**, not 8. `LoadLibraryA("d3d9.dll")` plus
`GetProcAddress(..., "Direct3DCreate9")` with SDK version 32 is at
acclient.c:456464–456468 — inside **`D3DPolyRender::Startup`**
(acclient.c:456447), not `RenderDeviceD3D` as the first pass said.
`RenderDeviceD3D::Startup` (acclient.c:459894) only creates the device.

There is **no D3D8 path**: zero hits for `d3d8`, `Direct3DCreate8`, or
`IDirect3D8` anywhere in the source or header. The only other `d3d9.dll`
reference is inside statically-linked D3DX (acclient.c:538342).

`RenderDeviceD3D` holds `IDirect3DDevice9 *m_pDirect3DDevice`,
`IDirect3DSwapChain9 *m_pPrimarySwapChain`, and a `_D3DCAPS9`
(acclient.h:45947).

The abstract base `RenderDevice` (acclient.h:38988) exposes a virtual interface
(`RenderDeviceVtbl`, acclient.h:39019) that is strikingly game-specific:
alongside `BeginScene` / `EndScene` / `Flip` / `Clear` / `SetViewport` /
`CreateTexture` it has `DrawInside`, `DrawBlock`, `DrawLandCell`,
`DrawSortCell`, `DrawEnvCell`, `DrawObjCell`, `DrawBuilding`, and `DrawMesh`.
This abstraction was never meant to host a second backend seriously.

### Device creation

`RenderDeviceD3D::Startup` clamps windowed size to `GetSystemMetrics`, then walks
a fallback ladder: `0x50` pure device plus hardware vertex processing
(acclient.c:**459976** — also requires both `bHardwareVertexProcessing` and
`m_config.bUsePureDevice`), then `0x40` hardware (459961), then `0x20` software
(**459965**), each OR'd with `0x106`
(`D3DCREATE_MULTITHREADED | FPU_PRESERVE | DISABLE_DRIVER_MANAGEMENT`, **459978**).

The outer loop is `while (ia < 2)` (**460009**), with `Sleep(0xC8)` (460002) on
`D3DERR_DEVICELOST` (−2005530520, compared at 459998) inside an inner `while(1)`
bounded by a 10-second timeout — not a fixed retry count. On success,
`if (v14 & 0x20) m_caps.bHardwareVertexProcessing = 0` (**460020**).

`OnDeviceDisplayModeChange` (acclient.c:459096) re-applies default states,
recalculates the UI clamp and aspect ratio, calls `SetDialogBoxMode(TRUE)` in
fullscreen (459113) before `SetGamma`, then clears and flips three frames
(459120–459130).

`RenderDevicePresentation` (acclient.h:38869) covers fullscreen refresh, bit
depth, triple buffering, vsync, and antialiasing. `RenderDeviceCaps`
(acclient.h:38892) records `bCanDoSinglePassDetailing`, point sprites, DXT
support, and occlusion queries.

---

## 2. There are two renderers in this binary

This is the single biggest thing the first pass missed, and it reframes the
"vestigial shader fields" story entirely.

**The AC1 stack** — `Render`, `D3DPolyRender`, `PrimD3DRender`, `ACRender`,
`CSurface`, `CMaterial`, `MeshBuffer` — draws the world. It is pure
fixed-function.

**A second, much newer Turbine material stack** — `RenderMaterial`,
`MaterialLayer`, `LayerStage`, `LayerModifier`, `RenderVertexBuffer`,
`RenderIndexBuffer`, `RenderTexture` — also exists, is fully implemented, and
**is live**. But it only drives 2D UI surfaces (`UISurfaceObject::Render`,
acclient.c:684176), texture-atlas fonts (`TextureBasedFont::EndRenderingText`,
acclient.c:686275), and `SceneTool` debug primitives (acclient.c:123275,
123315).

Its entry point `RenderDeviceD3D::SetupState` (acclient.c:458456) is what calls
`SetVertexShader`, evaluates
`Waveform::GetValue(m_wSpecularPower, Timer::local_time)` for animated material
parameters, and drives eight texture stages from `MaterialLayer::m_Stages`.

`SetupState` has exactly three callers —
`RenderVertexBuffer::RenderIndexedUsingMaterial` (132098),
`RenderVertexBuffer::RenderUsingMaterial` (132166), and
`RenderDeviceD3D::RenderDynamicPrimitivesUsingMaterial` (458873) — and those
three have exactly four call sites in the entire binary:
`UISurfaceObject::Render` (684176), `SceneTool::DrawLine` (123275),
`SceneTool::DrawTexturedTriangle` (123315), and
`TextureBasedFont::EndRenderingText` (686275). **No AC1 world-geometry path
reaches any of them.**

Its `RenderPassType` enum (acclient.h:**5374–5423**) tops out at
`RenderPass_AL_1DL_7PL_Fog = 0x2C`, then `RenderPass_MaxPasses = 0x2D` and
`RenderPass_Invalid = 0x2E`. It includes `RenderPass_ShaderGlow`,
`RenderPass_LandscapeShadowMap`, and the `AL_*DL_*PL[_Fog]` family — for example
`RenderPass_AL_0DL_8PL` (0x13) — which is the pass vocabulary of a shader engine
from the LOTRO/DDO lineage. (An earlier draft cited `RenderPass_AL_8DL_8PL`; no
such identifier exists.)

**There is one code bridge from AC1 geometry into the new stack, and it is
dead.** `MeshBuffer` (acclient.h:31949) carries a `RenderMesh *pRenderMesh`, and
`D3DPolyRender::RenderMeshSubset` falls back to `RenderMesh::DrawSubset` when
`pMesh` is null (acclient.c:454788, 454819). But `pRenderMesh` is assigned
**only `0`**, at every one of its seven assignment sites (454214, 456097, 456115,
456139, 456162, 456320, 456397). That is a stronger argument for the separation
than mere absence of call sites.

So the correct statement is not "dormant shader plumbing" but "a whole second
renderer, wired up to the HUD."

A caveat on how "live" was established: `UISurfaceObject::Render` has no direct
call site. The object is created by `UIElement::MakeUIObject` (158158) and
`RenderUI::RenderObjects` (132950) dispatches through vtable slot 1. The
inference is sound but indirect.

### Shaders, precisely

There are **zero** calls to `CreateVertexShader`, `CreatePixelShader`,
`SetPixelShader`, `SetVertexShaderConstant*`, or `D3DXCompileShader`.

`SetVertexShader` **is** called — exactly once, at acclient.c:458543 in
`SetupState`, always with argument `0`, i.e. explicitly clearing to
fixed-function. (Verified by vtable offset: 356 is `SetFVF`, 368 is
`SetVertexShader`; apparent hits at offsets 364/424/428 are `__thiscall` on
unrelated UI objects.)

`ShaderResourceType` fields (acclient.h:32902) are only constructed, copied, and
serialized (acclient.c:135020–135330). `ShaderVersionType` (acclient.h:5554) and
`IDirect3DVertexShader9` / `IDirect3DPixelShader9` (acclient.h:38775, 38780) are
declared but never instantiated.

---

## 3. Fixed-function state and vertex formats

`RenderStateCacheType` (acclient.h:45869) is a full fixed-function mirror: alpha
test and blend, cull, depth bias, fog (`FFFog*`), `FFLightEnable[8]`,
`FFTextureFactor32`, 16 samplers, and 8 texture stages with `FFColorOp` /
`FFAlphaOp`. Setters compare against the cache unless `m_bForceStates` is set.

Vertex formats are plain FVFs via `SetFVF` (`ApplyVertexFormat`,
acclient.c:457079). The full live set:

| FVF | Hex | Use |
|---|---|---|
| 594 | `0x252` | object meshes — XYZ \| NORMAL \| DIFFUSE \| TEX2 |
| 578 | `0x242` | landscape — XYZ \| DIFFUSE \| TEX2 |
| 338 | `0x152` | non-detail object polys (acclient.c:455408) |
| 322 | `0x142` | single-texture landscape pass (720100, 720316) |
| 324 | `0x144` | screen-space — XYZRHW \| DIFFUSE \| TEX1 (453958) |

---

## 4. Frame loop

Per tick, `SmartBox::UseTime` (acclient.c:146256) runs physics and cell logic,
then `SceneTool::Think` and `Render::CalcDegLevel`. Drawing is
`SmartBox::Draw` → `DrawNoBlit` (acclient.c:146329, 145853):

1. **Open scene** — `SceneTool::BeginScene` (acclient.c:122402):
   `Clear(target | Z | stencil)` then `BeginScene`.
2. **3D scene** — `SmartBox::RenderNormalMode` (acclient.c:144867). If the
   viewer cell is outdoors (`objcell_id & 0xFFFF < 0x100`) it calls
   `LScape::draw`; otherwise `RenderDevice::DrawInside`.
3. **Sky** — inside `LScape::draw` (acclient.c:307754), `GameSky::Draw(pre)`
   (acclient.c:308475), then landblocks, then `GameSky::Draw(after)` for the
   weather cell.
4. **Alpha flush** — `D3DPolyRender::FlushAlphaList` (acclient.c:455064).
5. **Selection** — the mouse-pick result is read back from the traversal (§7).
6. **UI overlay and present** — `SceneTool::EndFrame` (acclient.c:124036):
   viewport reset, `RenderUI::RenderObjects` and `KeyStone::Update`, then
   profiler, debug console, debug HUD, `EndScene`, `Flip`, FPS counter.

---

## 5. Landscape

`LScape::draw` walks a sliding `mid_width × mid_width` grid of `CLandBlock`s
far to near and calls the vtable `DrawBlock` (acclient.c:458990–459066). Per
8×8-cell block it updates object cells and sorts their shadow parts, then per
`CLandCell` calls `DrawLandCell` and `DrawSortCell`.

**Terrain geometry.** `CLandBlockStruct` (acclient.h:31310) holds a 9×9 height
array, per-cell terrain codes, and a `CVertexArray`. `ConstructPolygons`
(acclient.c:354001) makes two triangles per cell, choosing the diagonal with the
`SWtoNEcut` hash at acclient.c:**354046** (comparison at 354050):

```c
v8 = y*(214614067*x + 1813693831) - 1109124029*x - 1369149221;
cut = ((double)(unsigned)v8 * 2.3283064e-10) >= 0.5;   /* scale = 1/2^32 */
```

The first pass elided the trailing constant `1369149221` and the `1/2³²` scale.

**Vertex assembly is on the CPU.** `landPolysDraw` (acclient.c:720640)
backface-culls the two triangles with camera-side plane tests, then
`landPolyDraw` (acclient.c:719994) builds vertices per frame: per-vertex terrain
lighting from `curLandBlockVertexLighting`, plus a detail-texture alpha fading
between 10 and 50 units (acclient.c:720141–720150; slope constant
`MY_MAX_MINUS_MIN_OO` = 1/40; depth is view-space `zw` from
`PrimD3DRender::xformStart`). The object equivalent is
`ACRender::get_alpha_for_z` (acclient.c:719936–719950).

**Landscape detail texturing is hard-disabled in this build.**
`UpdateFromPreferences` unconditionally forces it off and calls
`SmartBox::SetDetailTexturing(smartbox, /*landscape=*/0, environment)`
(acclient.c:381020–381026); all five quality presets set the preference byte to
0 (acclient.c:378749–378795). Only *environment* detail texturing remains
reachable.

**Texture splatting is offline software work.** `LandSurf::SelectTerrain`
(acclient.c:304328) and `TexMerge::Merge` (304839) composite base terrain
textures, transition alpha maps, and road alpha maps (`FindTerrainAlpha`,
304756) into per-combination merged textures via `ImgTex::MergeTexture`
(365632). This is the classic AC "texture merge," not runtime blending.

Scenery (`Scene` DAT objects) is instantiated as static `CPhysicsObj`s per
landblock and drawn as ordinary objects.

---

## 6. Indoor and portal rendering

Indoors, `DrawInside` delegates to a `PView` (acclient.h:45934;
`PView::DrawCells` at acclient.c:461450), which implements classic portal
visibility: starting from the viewer's `CEnvCell` it clips portal polygons in
screen space (`ClipPortals`, `GetClip`), building per-cell view cones,
breadth-first through `cell_todo_list`, producing a back-to-front
`cell_draw_list`.

`DrawCells` draws the landscape through outdoor portals if visible, flushes
alpha, partially clears Z, draws portal polygons into the depth buffer, draws
each `CEnvCell` (`DrawEnvCell`, acclient.c:456878), and finally each cell's
dynamic objects via `DrawObjCellForDummies` (acclient.c:458143).

Per-object culling is a sphere-versus-viewcone test per portal view in
`RenderDeviceD3D::DrawMesh` (acclient.c:458209), with `m_nFrameStamp` and
`DrawnThisFrame` preventing duplicates across views.

`DrawEnvCell` also sets the environment detail surface with
**`src = BLEND_DSTCOLOR (9)`**. The SRCALPHA/INVSRCALPHA (5/6) pair belongs to
the *landscape* detail blend in `DrawBlock`; an earlier draft cross-contaminated
the two.

---

## 7. Object rendering, LOD, and picking

A `CPhysicsObj` owns a `CPartArray` of rigid `CPhysicsPart`s. There is no
skinning — animation poses each part's `Frame` (see `01-physics.md`).

`CPhysicsPart::Draw` (acclient.c:314587) picks `gfxobj[deg_level]`, sets the
part's `CMaterial`, surface array, and scale, then goes through `DrawMesh` →
`DrawMeshInternal` (acclient.c:456960) → `D3DPolyRender::DrawMesh`
(acclient.c:455154).

CGfxObjs are compiled once into a `MeshBuffer` (acclient.h:31949) by
`D3DPolyRender::ConstructMesh` (acclient.c:455780), which calls
`D3DXCreateMeshFVF` (acclient.c:456079) to build a real **`ID3DXMesh`** with
per-surface attribute ranges, optional baked static lighting, and an
`isStippledOrAlphaedMask`. `RenderMeshSubset` (acclient.c:454633) draws through
`ID3DXMesh::DrawSubset`.

So the pipeline is a **hybrid**: indexed D3DX meshes for objects and env cells,
`DrawPrimitiveUP` for terrain and portal polygons, and pooled dynamic streams for
the newer material path.

### The auto-degrade fuzzy controller

`Render::CalcDegLevel` (acclient.c:380231) is a genuine Mamdani fuzzy
controller over `SceneTool::m_FramesPerSecond`, with `min_framerate = 8`,
`ideal_framerate = 10`, `max_framerate = 20` (acclient.c:45517–45519):

| Set | Support | Consequent Δ |
|---|---|---|
| low | shoulder below 6, up to 9 | −0.15 |
| medlow | [8, 9.5] | −0.02 |
| plateau | [9, 15] | 0.0 |
| medhigh | [12.5, 20] | +0.01 |
| high | [15, 25], shoulder above | +0.10 |

Defuzzification is a weighted average (`rulesum / Σμ`, acclient.c:380310), added
to `Render::deg_mul` and clamped to **[−1, +1]**. A 29-entry history ring
suppresses the update unless the new value differs from *every* recent value by
at least 0.01 (acclient.c:380325–380333) — deliberate anti-oscillation
hysteresis. The asymmetric consequents (−0.15 down, +0.10 up) make degradation
fast and recovery slow.

`Render::SetDegradeLevelInternal` (acclient.c:379786) maps `deg_mul` linearly to
four live budgets:

| Budget | Worst → default → best |
|---|---|
| object cull distance | 8 → 25 → 50 (stored squared) |
| particle cull distance | 8 → 16 → 25 |
| `max_static_lights` | 20 → 40 → 60 |
| `max_dynamic_lights` | 5 → 7 → 10 |

So the "60 static / 10 dynamic" figure is the **best case** of this controller,
not a constant. The 60/10 in `LightParms` (acclient.h:46630–46635) are array
capacities; the defaults are 40 and 7. There are exactly two `LightParms`
instances: `Render::world_lights` (acclient.c:56201) and
`Render::viewer_lights` (56255).

Per-object LOD is separate. `GfxObjDegradeInfo` is
`{num_degrades, GfxObjInfo *degrades}` (acclient.h:31705), and `GfxObjInfo` is
`{gfxobj_id, degrade_mode, min_dist, ideal_dist, max_dist}` (acclient.h:31932).

`get_degrade` (acclient.c:332356) subtracts a user bias
`Render::s_rDegradeDistance` (default **50.0**) from the distance, **clamps the
result to ≥ 0**, then compares against
`ideal_dist − (ideal_dist − max_dist)·scale` when `scale ≥ 0`, or
`ideal_dist + (ideal_dist − min_dist)·scale` when negative. (An earlier draft had
`ideal` and `max` transposed in the positive branch.) `scale` is
`Render::deg_mul` only when `auto_update_deg_mul` is set; otherwise it is
`Render::s_rUserSuppliedDegradeBias`.

Globals `degrades_disabled` and `Render::force_level` (default −1) override it;
the creature preview sets `degrades_disabled = 1` for its own render
(acclient.c:143914).

`degrade_mode` is also what selects the billboard modes described in §10.

### Mouse picking is a CPU ray cast

Not a render-to-texture ID pass, not a depth readback.
`Render::set_selection_cursor(x, y, fPolyAccurate)` (acclient.c:379094) arms the
test; `Render::pick_ray` (acclient.c:379035) unprojects the cursor once per frame
in `Render::update_viewpoint` (acclient.c:380396–380402).

Then **during the normal draw traversal**, `RenderDeviceD3D::DrawMesh` calls
`Render::GfxObjUnderSelectionRay` (acclient.c:379997) at acclient.c:458247 and
458282. That transforms the ray into part-local space, normalises by
`gfxobj_scale`, tests `CSphere::sphere_intersects_ray` against
`mesh->drawing_sphere`, and — if `check_curr_object_polys` — loops
`CPolygon::polygon_hits_ray`. Two nearest-hit records are kept (sphere and
polygon); `GetMouseSelectionObjectID` (acclient.c:380089) returns the cached best
and prefers the polygon result.

Static scenery is excluded: `Render::check_curr_object` is only set for parts
whose physobj has an ID or is in `creature_mode` (acclient.c:314614).

---

## 8. There are no shadows, and no world-space text

Two definitive negative findings.

**No shadows at all.** `CShadowObj` is `{physobj, cell_id, cell}`
(acclient.h:30935), held in `CObjCell::shadow_object_list`; `CShadowPart` is
`{num_planes, planes, frame, part}` (acclient.h:31254) — portal clip planes plus
a draw-sort handle. Both are **purely spatial cell-membership structures**. There
is no blob texture, no projected shadow, and no stencil pass anywhere. The
material-system strings `AllowStencilShadows`,
`RenderPass_LandscapeShadowMap`, `SpecialTexture_LandscapeShadows`, and
`FragmentType_ShadowLODModel` are inert parser vocabulary belonging to the second
renderer.

**No nameplates, speech bubbles, or damage numbers.** The hover name is a
`UIElement` tooltip anchored to the *mouse*, not to a projected object point —
`UIElement::SetTooltip` plus `StartTooltipAtMouse` inside
`UIElement_SmartBoxWrapper::RecvNotice_SmartBoxObjectFound` (acclient.c:275631,
tooltip block 275763–275805), gated on `PlayerModule::ShowTooltips`. Zero hits
for nameplate, billboard-text, speech-bubble, or damage-number strings.

`xformPointInternal` (453759) is consumed only inside
`SmartBox::GetObjectBoundingBox` (acclient.c:144083, at 144140 and 144146), which
projects the selection sphere's viewer-space AABB into a `tagRECT` for
`SmartBox::target_callback`. `VividTargetIndicator::OnDraw` (acclient.c:289744)
then moves four corner-bracket widgets to that rect, or shows an edge arrow from
a compass heading when off-screen.

An earlier draft called this "the only 3D-to-2D projection consumer in the whole
binary," which is too strong: `PrimD3DRender::xformStart(v, doprojection=1)` also
projects to screen at 453929 (`DrawPortalPolyInternal`) and 461071 (`PView`
portal clipping), and with `doprojection=0` supplies view-space `zw` at 720060,
720139, 720277, and 720413. The defensible statement is that it is the only
projection consumer *outside* the renderer's own portal-clipping and detail-fade
paths.

Selection "glow" is not an outline pass: `CPhysicsObj::SetLighting(0.99, 1.0)`
copies the part's `CMaterial` and raises luminosity and diffuse
(acclient.c:275686 → 318929 → 315325 → `CMaterial::SetLuminositySimple`), with a
four-flip 0.2 s blink on confirm (acclient.c:275388–275415).

The `TextureBasedFont` atlas renderer (acclient.c:685993–687161) exists but is
used *only* by the debug HUD, profiler, and debug console.

---

## 9. Sky, day/night, and weather

**There is no weather engine.** `GameSky` (acclient.h:35420) holds two
`CEnvCell`s — `before_sky_cell`, drawn before landblocks, and `after_sky_cell`,
the "weather cell," drawn after and gated on `LScape::weather_enabled`.

Celestial bodies are real `CPhysicsObj`s (`GameSky::MakeObject`,
acclient.c:308427). Clouds and precipitation "move" via
`CPhysicsObj::SetTextureVelocity` UV scroll — there is no wind vector and no
particle path (`CelestialPosition::pes_id` is parsed and never consumed).
`GameSky::Draw` (acclient.c:308475) sets a global sky-mode byte, forces
`DEPTHTEST_ALWAYS` with depth writes off, and multiplies `zfar` by 4. Weather
objects are pinned to the player's XY and forced to **z = −120.0** unless a
property bit says otherwise (acclient.c:**308415**).

One nuance: `before_sky_cell` is never passed to a draw call. `GameSky::Draw(0)`
iterates `sky_obj` calling `CPhysicsObj::DrawRecursive`; only `after_sky_cell`
goes through `DrawObjCellForDummies` (308502).

**Day/night comes from the region DAT.** No message handler in this binary
writes game time — it is DAT-constructed at 299972–299985 and
`GameTime.TimeZeroDelta` is a local registry offset — so client and server agree
without traffic:
`SkyDesc → DayGroup → SkyTimeOfDay`, with the day group chosen by an LCG hash of
the calendar day (`SkyDesc::CalcPresentDayGroup`, acclient.c:301664) so client
and server agree independently. `SkyDesc::GetLighting` (acclient.c:301485) lerps
ambient brightness and colour plus sun heading and pitch; `LScape::UseTime`
(acclient.c:307222) re-lights on a `light_tick_size` cadence, writes
`Render::world_lights.sunlight[_color]`, and re-runs
`CLandBlockStruct::calc_lighting` on every loaded block.

Fog is **linear range fog only** — `SetFFFogProperties` (acclient.c:460308)
writes `D3DRS_FOGCOLOR`, `FOGSTART`, and `FOGEND`, with no density — behind four
independent disable flags (`FFFogSystemDisabled`, `FFFogUserDisabled`,
`FFFogAlphaDisabled`, plus the enable).

`PlayerModule::PersistentAtDay` (acclient.c:511150) → `LScape::SetDay`
(acclient.c:306897) sets `m_fAlwaysDaylight`, which makes
`set_landscape_lighting` discard the real time and re-query `GetLighting(0.5)`.
Note the consequence: **terrain and object lighting pin to noon, but the sky
objects keep moving.**

Server "environs" overrides arrive as message 60000 → `Handle_Admin__Environs`
(acclient.c:396298) and blend at +0.04 per tick — the portal-storm ambience hook.

---

## 10. Alpha, translucency, and particles

`AddMeshToAlphaList` (acclient.c:454225) writes 84-byte entries into two fixed
**3000-entry** arrays — a clip list and an alpha list. **Overflow silently drops
geometry.** Each entry is `{MeshBuffer*, surfaceNum, CSurface*, CMaterial*,
Matrix4, bFirstInGroup, overrideClip}`.

**`FlushAlphaList` performs no sorting whatsoever.** Read in full
(acclient.c:455064–455148) it is two straight `++`-indexed loops with no
comparison. It fires only when a list is `t × 3000` full; every in-scene call
passes 0.0 except the per-landcell one. It saves and restores only the
model-to-world matrix.

Depth ordering happens earlier and coarser, per-part, in
`CShadowPart::insertion_sort` (acclient.c:719001) keyed on
`CPhysicsPart::CYpt`.

Deferral is decided by `MeshBuffer::isStippledOrAlphaedMask` against
`s_AlphaDelayMask = 14`: bit 1 = surface has ALPHA/INVALPHA/ADDITIVE, bit 2 =
TRANSLUCENT, bit 3 = BASE1_CLIPMAP.

**There is no stipple or screen-door path in the D3D build.** The `stippled`
flag selects texture WRAP versus CLAMP and additionally sets
`Render::curr_surface_type |= 0x40000000` on the same line (acclient.c:454437). The real cutout
mechanism is alpha test, with `ALPHAREF` 100 for palettized and 200 for DXT
(acclient.c:45764–45765), versus alpha blend.

Blend modes come purely from `CSurface::type` bits in `SetSurface`
(acclient.c:454471–454497): ADDITIVE alone gives ONE/ONE; ALPHA+ADDITIVE gives
SRCALPHA/ONE; ALPHA gives SRCALPHA/INVSRCALPHA. **Nothing in `ParticleEmitter`
chooses a blend mode** — a fire particle is additive because its DAT surface says
so.

`PhysicsDesc::translucency` (acclient.h:33141, bitfield `0x40000`) flows into
`CPhysicsPart::SetTranslucency` (acclient.c:315488), which **copy-on-writes the
part's `CMaterial`** and calls `CMaterial::SetTranslucencySimple`
(acclient.c:360594), setting all four material alphas to `1 − t`. A translucency
of exactly 1.0 sets `draw_state |= 1` and the part is skipped entirely. A
`has_alpha` material forces the subset onto the alpha list and, at flush, into
SRCALPHA/INVSRCALPHA **with z-writes off** (acclient.c:454525–454546).

Particles are ordinary `CPhysicsPart`s in a synthetic `CPhysicsObj`
(`makeParticleObject`, acclient.c:319617, state
`STATIC_PS | PARTICLE_EMITTER_PS`, acclient.h:2817/2829) using
`ParticleEmitterInfo::hw_gfxobj_id`.

`Particle::Update` (acclient.c:330313) itself writes only origin, scale, and
translucency, with a parent-frame-derived rotation in the parabolic branch
(330470–330498) — it contains no camera or viewer reference.

**But billboarding does exist, and an earlier draft of this document wrongly
denied it.** `CPhysicsPart::calc_draw_frame` (acclient.c:**315066**) copies
`pos.frame` into `draw_pos.frame` and then switches on `deg_mode`:

- `case 2` → `Frame::set_vector_heading(&draw_pos.frame, &viewer_heading)`
  (315080) — a full camera-facing billboard
- `case 3` / `4` / `5` → `Frame::rotate_around_axis_to_vector(&draw_pos.frame,
  0|1|2, &viewer_heading)` (315083 / 315086 / 315089) — axis-locked billboards

`viewer_heading` is the normalized viewer-to-object vector, from
`Position::get_offset(&Render::viewer_pos, …)` (317935–317951). `deg_mode` comes
from the DAT via `GfxObjDegradeInfo::get_degrade` reading
`GfxObjInfo::degrade_mode`. `calc_draw_frame` is called from both
`CPhysicsPart::UpdateViewerDistance` overloads (315168, 315199), and
`CPhysicsPart::Draw` passes `&draw_pos` to `DrawMesh` (314620).

This is live, DAT-driven, four-mode billboarding. The earlier claim came from
searching `Particle::Update` and the string "billboard" (which does not appear)
and then generalising — a textbook absence-of-evidence error.

---

## 11. Textures, lighting, and settings

`ImgTex` (acclient.h:31978) is the DAT-to-texture object. `CreateD3DTexture`
(acclient.c:366008) applies the user texture-scale shift with a minimum size of 8
(`ImgTex::min_tex_size`, acclient.c:45327) and uses
`D3DXFilterTexture(v24, 0, -1, 0x70005)` for mips (acclient.c:366160).

The clothing and appearance palette system runs through `ImgTex::Combine` /
`CreateCombinedTexture` (acclient.c:367576): an 8-bit indexed source plus a
`Palette`, possibly shifted per `CPhysicsPart::shiftPal`, is software-expanded to
ARGB, producing a distinct cached texture keyed by the 64-bit `m_TextureCode` in
`ImgTex::texture_table` (acclient.c:45397).

Eviction: `SceneTool::PurgeOldGraphicsResources` (acclient.c:123099–123103)
purges `GraphicsResource`s older than 120 s, every 5 s, when
`IsAvailableVideoMemoryLow` (acclient.c:457974) — which returns true unless total
VRAM ≥ `0xC00000` **and** free ≥ `0x1800000` **and** free < total/4.

**`DrawPrimitiveUP` is the primary path, not a fallback.**
`s_bAllowDrawPrimitiveUP` **defaults to true** (acclient.c:45784) and
`DrawPrimitiveUP` serves terrain (`landPolyDraw`, acclient.c:720129, 720163) and
per-polygon/portal draws (454031, 455401). The registry key
`"RenderDeviceD3D.AllowDrawPrimUP"` is a **debug kill-switch**, the opposite of
what the first pass implied.

`RenderPrimitivesInHardware` (acclient.c:457860) is the pooled dynamic-stream
path — `SetStreamSource` (400), `SetFVF` (356), `DrawPrimitive` (324) — with an
`m_nStreamFrameID` check at 457866 to detect stale fills.

**Interior lighting is CPU-baked per vertex.**
`D3DPolyRender::SetStaticLightingVertexColors` (acclient.c:454918) locks the
`ID3DXMesh` vertex buffer and evaluates every
`Render::world_lights.static_lights[]` per vertex via
`LIGHTINFO::convert_to_local`, caching into `MeshBuffer::burnedInStaticLights`.
`Render::minimize_envcell_lighting` (acclient.c:379652) then enables only the
dynamic lights as hardware FF lights. Cell lights enter through
`CObjCell::add_static_to_global_lights` and `add_dynamic_to_global_lights`
(acclient.c:346859, 346881).

The hardware light cap is 8 for **objects**, enforced twice: a caps clamp at
acclient.c:457137 and a hard `v0 >= 8` cutoff in
`Render::minimize_object_lighting` (acclient.c:**380678**). Note
`Render::minimize_envcell_lighting` (379652) enables **every**
`num_dynamic_lights` with no cap, and the degrade controller can push that to 10
— so env-cell lighting can request more than eight. Sunlight is `d3dLight.Type = 3` (D3DLIGHT_DIRECTIONAL) in
`PrimD3DRender::InitializeLights` (acclient.c:453084).

### Graphics settings

Five presets in `Render::SetOverallGraphicsQuality` (acclient.c:378743),
reversed by `DetermineOverallGraphicsQuality` (acclient.c:378810):

| Setting | Preset values (low → high) |
|---|---|
| `TextureFiltering` | 0 / 0 / 0 / 1 / 1 |
| `LandscapeDetailTextures` | always 0 |
| `BuildingDetailTextures`, `MultiPassAlpha` | 0 / 0 / 0 / 1 / 1 |
| `LandscapeTextureDetail` | 4 / 3 / 2 / 2 / 0 |
| `EnvironmentTextureDetail` | 4 / 3 / 2 / 1 / 1 |
| `SceneryDrawDistance` | 0 / 1 / 1 / 2 / 2 |
| `LandscapeDrawDistance` (`mid_radius`) | 3 / 5 / 8 / 11 / 15 |

`UpdateFromPreferences` (acclient.c:380924) converts texture-detail levels into
`ImgTex::fLandTextureScale` / `fClipmapTextureScale` / `fRGBATextureScale` /
`fIndexedTextureScale` mip shifts, then triggers `FlushGraphicsResources`,
gamma, aspect ratio, or `Device::ChangePresentation` as needed.

Registry and preference keys:
`Render.{AspectRatio, AutomaticDegrades, BuildingDetailTextures,
DegradeDistance, DisplayAdapter, EnvironmentTextureDetail, FieldOfView,
GraphicsPerformance, LandscapeDetailTextures, LandscapeDrawDistance,
LandscapeTextureDetail, MaxHardwareClass, MultiPassAlpha, SceneryDrawDistance,
ScreenBrightness, TextureFiltering}`,
`Display.{FullScreen, RefreshRate, Resolution, SyncToRefresh}`,
`SceneTool.{RenderUIObjects, ScreenShot*}`, `GameTime.TimeZeroDelta`,
`RenderDeviceD3D.AllowDrawPrimUP`.

Console commands: `@render radius <5-25>` and `@render fov <10-160>`
(`GraphicsOptions::HandleRenderOption`, acclient.c:146792).

---

## 12. Traps for the unwary

**`KeyStone` is not part of the renderer.** It is an external third-party
toolkit, `keystone.dll`, loaded only if `CheckForMSXML4()` passes
(acclient.c:390176), with entry point
`KeystoneCreate(HWND, IDirect3DDevice9*, cwd, texture-create cb, VB-create cb,
malloc, free)`. It hosts `plugins\ACHelpPlugin.dll` and
`plugins\ACPluginManager.dll` — AC2-heritage in-game help browser and plugin
manager. It renders into the same D3D9 device via callbacks and receives raw
`WM_*` messages, IME context, and accelerators (acclient.c:390179–390300). It is
**not** the game UI.

**`CBaseRenderer` / `CBaseVideoRenderer` are DirectShow**, deriving from
`CBaseInputPin` (acclient.c:14785–14792). Nothing to do with the 3D pipeline.

**`D3DXTex` / `D3DXMesh` / `D3DXCore` really are Microsoft D3DX9**, statically
linked — not Turbine wrappers. Symbols include `D3DXMesh::CD3DXCrackDecl`,
`D3DXMesh::GXTri3Mesh<unsigned short,1,65535>::OptimizeInplace`, and
`D3DXFVFFromDeclaratorEx` (acclient.c:11593–11601), with real bodies at
acclient.c:535171, 537033, and 538154.

**`ParticleEmitter` at acclient.c:329361 is the destructor.** The live logic is
at 330313 (`Particle::Update`), 330909 (`SetInfo`), 331003 (`EmitParticle`), and
331097 (`UpdateParticles`).

**The alpha-flush threshold is recoverable after all.** An earlier draft said it
could not be. The float `FlushAlphaList` receives inside `DrawBlock` is the
global `float flush = 0.75;` at **acclient.c:45787**, plainly visible in the
globals section — so the per-landcell flush fires at 2250 of 3000 entries. (With
`t = 0.0`, as every in-scene call passes, the guard `count >= t*3000` is
trivially true and those calls always flush.)

What *is* genuinely unrecoverable is a **different** value: the dropped `st0`
argument `a2` that `DrawBlock` forwards to
`RenderDeviceD3D::UpdateObjCell(v4, a2, …)` at acclient.c:459010. That one is
dropped in the alternate decompilation too.
