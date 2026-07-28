/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PrimD3DRender
   Object     : PORTAL\primd3drender\PrimD3DRender.obj
   Functions  : 89
   Addresses  : 0059AA40 - 00775390 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0059AA40) --------------------------------------------------------  // acclient.c:453014
void __cdecl PrimD3DRender::ScreenToViewTransform(AC1Legacy::Vector3 *dirToPoint, float xPoint, float yPoint)
{
  unsigned int v3; // ebx@1
  unsigned int v4; // ebp@1
  double v5; // st7@1
  double v6; // st6@1
  Matrix4 vmInv; // [sp+14h] [bp-C0h]@1
  Matrix4 pm; // [sp+54h] [bp-80h]@1
  Matrix4 vm; // [sp+94h] [bp-40h]@1

  v3 = RenderDevice::render_device->m_viewportWidth;
  v4 = RenderDevice::render_device->m_viewportHeight;
  qmemcpy(&pm, &RenderDevice::render_device->m_GState.ViewToClipMatrix, sizeof(pm));
  qmemcpy(&vm, &RenderDevice::render_device->m_GState.WorldToViewMatrix, sizeof(vm));
  D3DXMatrixInverse(&vmInv, 0, &vm);
  v5 = ((xPoint + xPoint) / (double)v3 - 1.0) / pm._11;
  v6 = ((yPoint + yPoint) / (double)v4 - 1.0) * (-1.0 / pm._22);
  dirToPoint->x = vmInv._21 * v6 + vmInv._11 * v5 + vmInv._31;
  dirToPoint->z = vmInv._22 * v6 + vmInv._12 * v5 + vmInv._32;
  dirToPoint->y = vmInv._23 * v6 + vmInv._13 * v5 + vmInv._33;
}
// 5E05A2: using guessed type _DWORD __stdcall D3DXMatrixInverse(_DWORD, _DWORD, _DWORD);

//----- (0059AB40) --------------------------------------------------------  // acclient.c:453038
void __stdcall PrimD3DRender::SetFOVInternal(float _radians)
{
  Matrix4 pm; // [sp+10h] [bp-40h]@1

  Render::SetFOVInternal(_radians);
  D3DXMatrixPerspectiveFovLH(
    (int)&pm,
    _radians,
    RenderDevice::render_device->m_ViewportAspectRatio,
    Render::znear,
    Render::zfar);
  RenderDeviceD3D::SetViewToClipMatrix((RenderDeviceD3D *)RenderDevice::render_device, &pm);
}

//----- (0059AB90) --------------------------------------------------------  // acclient.c:453053
AC1Legacy::Vector3 *__thiscall LIGHTINFO::GetDirection(LIGHTINFO *this, AC1Legacy::Vector3 *result)
{
  AC1Legacy::Vector3 *v2; // eax@3

  if ( this->type == 1 || this->type == 2 )
  {
    Frame::get_vector_heading(&this->offset, result);
    v2 = result;
  }
  else
  {
    v2 = result;
    LODWORD(result->x) = 0;
    LODWORD(result->y) = 0;
    LODWORD(result->z) = 0;
  }
  return v2;
}

//----- (0059ABD0) --------------------------------------------------------  // acclient.c:453073
void PrimD3DRender::CleanupInternal()
{
  if ( PrimD3DRender::pD3DSunlight )
  {
    operator delete(PrimD3DRender::pD3DSunlight);
    PrimD3DRender::pD3DSunlight = 0;
  }
}

//----- (0059ABF0) --------------------------------------------------------  // acclient.c:453083
HRESULT __cdecl PrimD3DRender::InitializeLights()
{
  LODWORD(Render::world_lights.ambient_color.r) = 0;
  LODWORD(Render::world_lights.ambient_color.g) = 0;
  LODWORD(Render::world_lights.ambient_color.b) = 0;
  LODWORD(Render::world_lights.sunlight.x) = 0;
  LODWORD(Render::world_lights.sunlight.y) = 0;
  LODWORD(Render::world_lights.sunlight.z) = -1082130432;
  LODWORD(Render::world_lights.sunlight_color.r) = 1065353216;
  Render::world_lights.m_Sunlight.d3dLight.Type = 3;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Ambient.r) = 0;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Ambient.g) = 0;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Ambient.b) = 0;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Ambient.a) = 1065353216;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Diffuse.r) = 1065353216;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Diffuse.g) = 1065353216;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Diffuse.b) = 1065353216;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Diffuse.a) = 1065353216;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Specular.r) = 1065353216;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Specular.g) = 1065353216;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Specular.b) = 1065353216;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Specular.a) = 1065353216;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Direction.x) = 0;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Direction.y) = -1082130432;
  LODWORD(Render::world_lights.m_Sunlight.d3dLight.Direction.z) = 0;
  Render::world_lights.m_Sunlight.d3dLightIndex = 0;
  LODWORD(Render::world_lights.sunlight_color.g) = 1065353216;
  LODWORD(Render::world_lights.sunlight_color.b) = 1065353216;
  Render::world_lights.m_bSunlightValid = 0;
  Render::reset_active_lights_state();
  Render::reset_active_lights_state();
  return 0;
}

//----- (0059AD30) --------------------------------------------------------  // acclient.c:453118
int __cdecl PrimD3DRender::config_hardware_light(int light_index, _D3DLIGHT9 *o_pHardwareLight, unsigned int cellID, LIGHTINFO *i_pLightInfo)
{
  double v4; // st7@2
  char *v5; // ecx@2
  double v6; // st7@2
  double v7; // st7@2
  double v8; // st7@2
  double v9; // st7@2
  char *v10; // ecx@2
  AC1Legacy::Vector3 result; // [sp+4h] [bp-4Ch]@5
  AC1Legacy::Vector3 v13; // [sp+10h] [bp-40h]@5
  AC1Legacy::Vector3 v14; // [sp+1Ch] [bp-34h]@5
  AC1Legacy::Vector3 v15; // [sp+28h] [bp-28h]@6
  AC1Legacy::Vector3 v16; // [sp+34h] [bp-1Ch]@6
  AC1Legacy::Vector3 v17; // [sp+40h] [bp-10h]@2
  int v18; // [sp+4Ch] [bp-4h]@2

  if ( LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24) )
  {
    v4 = i_pLightInfo->color.r * i_pLightInfo->intensity;
    v5 = (char *)&o_pHardwareLight->Specular;
    LODWORD(v17.x) = 0;
    o_pHardwareLight->Diffuse.r = v4;
    LODWORD(v17.y) = 0;
    v6 = i_pLightInfo->color.g;
    LODWORD(v17.z) = 0;
    v7 = v6 * i_pLightInfo->intensity;
    v18 = 0;
    LODWORD(v17.x) = 0;
    LODWORD(v17.y) = 0;
    o_pHardwareLight->Diffuse.g = v7;
    LODWORD(v17.z) = 0;
    v8 = i_pLightInfo->color.b;
    v18 = 0;
    v9 = v8 * i_pLightInfo->intensity;
    *(_DWORD *)v5 = 0;
    *((_DWORD *)v5 + 1) = 0;
    *((_DWORD *)v5 + 2) = 0;
    *((_DWORD *)v5 + 3) = 0;
    o_pHardwareLight->Diffuse.b = v9;
    v10 = (char *)&o_pHardwareLight->Ambient;
    *(_DWORD *)v10 = 0;
    *((_DWORD *)v10 + 1) = 0;
    *((_DWORD *)v10 + 2) = 0;
    *((_DWORD *)v10 + 3) = 0;
    if ( i_pLightInfo->type )
    {
      if ( i_pLightInfo->type == 1 )
      {
        o_pHardwareLight->Type = 3;
        o_pHardwareLight->Direction.x = LIGHTINFO::GetDirection(i_pLightInfo, &v15)->x;
        o_pHardwareLight->Direction.y = LIGHTINFO::GetDirection(i_pLightInfo, &v16)->z;
        o_pHardwareLight->Direction.z = LIGHTINFO::GetDirection(i_pLightInfo, &v17)->y;
        return 1;
      }
      if ( i_pLightInfo->type != 2 )
        return 1;
      o_pHardwareLight->Type = 2;
      LODWORD(o_pHardwareLight->Falloff) = 1065353216;
      o_pHardwareLight->Range = i_pLightInfo->falloff * rangeAdjust;
      o_pHardwareLight->Theta = i_pLightInfo->cone_angle;
      o_pHardwareLight->Phi = i_pLightInfo->cone_angle;
      o_pHardwareLight->Position.x = i_pLightInfo->offset.m_fOrigin.x;
      o_pHardwareLight->Position.y = i_pLightInfo->offset.m_fOrigin.z;
      o_pHardwareLight->Position.z = i_pLightInfo->offset.m_fOrigin.y;
      o_pHardwareLight->Direction.x = LIGHTINFO::GetDirection(i_pLightInfo, &result)->x;
      o_pHardwareLight->Direction.y = LIGHTINFO::GetDirection(i_pLightInfo, &v13)->z;
      o_pHardwareLight->Direction.z = LIGHTINFO::GetDirection(i_pLightInfo, &v14)->y;
    }
    else
    {
      o_pHardwareLight->Type = 1;
      LODWORD(o_pHardwareLight->Falloff) = 1065353216;
      o_pHardwareLight->Range = i_pLightInfo->falloff * rangeAdjust;
      o_pHardwareLight->Position.x = i_pLightInfo->offset.m_fOrigin.x;
      o_pHardwareLight->Position.y = i_pLightInfo->offset.m_fOrigin.z;
      o_pHardwareLight->Position.z = i_pLightInfo->offset.m_fOrigin.y;
    }
    LODWORD(o_pHardwareLight->Attenuation0) = 0;
    LODWORD(o_pHardwareLight->Attenuation1) = 1065353216;
    LODWORD(o_pHardwareLight->Attenuation2) = 0;
    return 1;
  }
  return 0;
}

//----- (0059AED0) --------------------------------------------------------  // acclient.c:453205
void PrimD3DRender::UpdateLightsInternal()
{
  char v1; // si@2
  signed int v2; // edi@7
  unsigned __int64 v3; // rax@12
  unsigned int v4; // esi@16
  signed int v5; // ebx@17
  signed int v6; // edi@22
  signed int v7; // esi@27
  unsigned __int64 v8; // rax@32
  int v9; // edi@36
  RenderLight *v10; // esi@38
  float v11; // edx@38
  float v12; // eax@38
  float v13; // ecx@38
  float v14; // edx@38
  float v15; // eax@38
  float v16; // ecx@38
  float v17; // edx@38
  float v18; // eax@38
  float v19; // ecx@38
  float v20; // edx@38
  float v21; // eax@38
  float v22; // ecx@38
  float v23; // edx@38
  float v24; // eax@38
  float v25; // ecx@38
  AC1Legacy::Vector3 *v26; // eax@38
  RenderLight *v27; // eax@38
  double v28; // st6@38
  double v29; // st7@38
  int v30; // ecx@38
  bool v31; // sf@38
  unsigned __int8 v32; // of@38
  int v33; // edi@39
  RenderLight *v34; // esi@41
  float v35; // edx@41
  float v36; // eax@41
  float v37; // ecx@41
  float v38; // edx@41
  float v39; // eax@41
  float v40; // ecx@41
  float v41; // edx@41
  float v42; // eax@41
  float v43; // ecx@41
  float v44; // edx@41
  float v45; // eax@41
  float v46; // ecx@41
  float v47; // edx@41
  float v48; // eax@41
  float v49; // ecx@41
  AC1Legacy::Vector3 *v50; // eax@41
  RenderLight *v51; // eax@41
  double v52; // st6@41
  double v53; // st7@41
  int v54; // ecx@41
  long double v55; // st7@46
  AC1Legacy::Vector3 v; // [sp+10h] [bp-64h]@37
  AC1Legacy::Vector3 result; // [sp+1Ch] [bp-58h]@1
  float v58; // [sp+28h] [bp-4Ch]@16
  Position pos_i; // [sp+2Ch] [bp-48h]@38

  result.x = Render::world_lights.ambient_color.r * ambientBoostFactor;
  result.y = Render::world_lights.ambient_color.g * ambientBoostFactor;
  result.z = ambientBoostFactor * Render::world_lights.ambient_color.b;
  if ( result.x < 1.0 )
  {
    if ( result.x > 0.0 )
      v1 = (unsigned __int64)(result.x * 255.0 + 0.5);
    else
      v1 = 0;
  }
  else
  {
    v1 = -1;
  }
  if ( result.y < 1.0 )
  {
    if ( result.y > 0.0 )
      v2 = (unsigned __int64)(result.y * 255.0 + 0.5);
    else
      v2 = 0;
  }
  else
  {
    v2 = 255;
  }
  if ( result.z < 1.0 )
  {
    if ( result.z > 0.0 )
      v3 = (unsigned __int64)(result.z * 255.0 + 0.5);
    else
      LODWORD(v3) = 0;
  }
  else
  {
    LODWORD(v3) = 255;
  }
  v4 = v3 | ((v2 | ((*(_DWORD *)&v1 | 0xFFFFFF00) << 8)) << 8);
  result.x = (double)(unsigned __int8)(v4 >> 16) * 0.0039215689;
  result.y = (double)BYTE1(v4) * 0.0039215689;
  result.z = (double)(unsigned __int8)v4 * 0.0039215689;
  v58 = (double)(v4 >> 24) * 0.0039215689;
  if ( result.x < 1.0 )
  {
    if ( result.x > 0.0 )
      v5 = (unsigned __int64)(result.x * 255.0 + 0.5);
    else
      v5 = 0;
  }
  else
  {
    v5 = 255;
  }
  if ( result.y < 1.0 )
  {
    if ( result.y > 0.0 )
      v6 = (unsigned __int64)(result.y * 255.0 + 0.5);
    else
      v6 = 0;
  }
  else
  {
    v6 = 255;
  }
  if ( result.z < 1.0 )
  {
    if ( result.z > 0.0 )
      v7 = (unsigned __int64)(result.z * 255.0 + 0.5);
    else
      v7 = 0;
  }
  else
  {
    v7 = 255;
  }
  if ( v58 < 1.0 )
  {
    if ( v58 > 0.0 )
      v8 = (unsigned __int64)(v58 * 255.0 + 0.5);
    else
      LODWORD(v8) = 0;
  }
  else
  {
    LODWORD(v8) = 255;
  }
  RenderDeviceD3D::SetFFAmbientColor32(
    (RenderDeviceD3D *)RenderDevice::render_device,
    v7 | ((v6 | ((v5 | ((_DWORD)v8 << 8)) << 8)) << 8));
  v9 = 0;
  if ( Render::world_lights.num_static_lights > 0 )
  {
    LODWORD(v.x) = 0;
    LODWORD(v.y) = 0;
    LODWORD(v.z) = 0;
    do
    {
      v10 = Render::world_lights.sorted_static_lights[v9];
      pos_i.objcell_id = v10->cellID;
      v11 = v10->info.offset.m_fOrigin.y;
      v12 = v10->info.offset.m_fOrigin.z;
      pos_i.frame.m_fOrigin.x = v10->info.offset.m_fOrigin.x;
      v13 = v10->info.offset.qw;
      pos_i.frame.m_fOrigin.y = v11;
      v14 = v10->info.offset.qx;
      pos_i.frame.m_fOrigin.z = v12;
      v15 = v10->info.offset.qy;
      pos_i.frame.qw = v13;
      v16 = v10->info.offset.qz;
      pos_i.frame.qx = v14;
      v17 = v10->info.offset.m_fl2gv[0];
      pos_i.frame.qy = v15;
      v18 = v10->info.offset.m_fl2gv[1];
      pos_i.frame.qz = v16;
      v19 = v10->info.offset.m_fl2gv[2];
      pos_i.frame.m_fl2gv[0] = v17;
      v20 = v10->info.offset.m_fl2gv[3];
      pos_i.frame.m_fl2gv[1] = v18;
      v21 = v10->info.offset.m_fl2gv[4];
      pos_i.frame.m_fl2gv[2] = v19;
      v22 = v10->info.offset.m_fl2gv[5];
      pos_i.frame.m_fl2gv[3] = v20;
      v23 = v10->info.offset.m_fl2gv[6];
      pos_i.frame.m_fl2gv[4] = v21;
      v24 = v10->info.offset.m_fl2gv[7];
      pos_i.frame.m_fl2gv[5] = v22;
      v25 = v10->info.offset.m_fl2gv[8];
      pos_i.frame.m_fl2gv[6] = v23;
      pos_i.frame.m_fl2gv[7] = v24;
      pos_i.frame.m_fl2gv[8] = v25;
      pos_i.vfptr = (PackObjVtbl *)&Position::vftable;
      v26 = Position::localtolocal(&Render::viewer_pos, &result, &pos_i, &v);
      v10 = (RenderLight *)((char *)v10 + 180);
      v10->d3dLight.Type = LODWORD(v26->x);
      v10->d3dLight.Diffuse.r = v26->y;
      v10->d3dLight.Diffuse.g = v26->z;
      v27 = Render::world_lights.sorted_static_lights[v9];
      v28 = stru_81EF08.m_fl2gv[4] * v27->info.viewerspace_location.y
          + stru_81EF08.m_fl2gv[7] * v27->info.viewerspace_location.z
          + stru_81EF08.m_fl2gv[1] * v27->info.viewerspace_location.x
          + stru_81EF08.m_fOrigin.y;
      v29 = stru_81EF08.m_fl2gv[5] * v27->info.viewerspace_location.y
          + stru_81EF08.m_fl2gv[2] * v27->info.viewerspace_location.x
          + stru_81EF08.m_fl2gv[8] * v27->info.viewerspace_location.z
          + stru_81EF08.m_fOrigin.z;
      ++v9;
      v27->d3dLight.Position.x = stru_81EF08.m_fl2gv[6] * v27->info.viewerspace_location.z
                               + stru_81EF08.m_fl2gv[0] * v27->info.viewerspace_location.x
                               + stru_81EF08.m_fl2gv[3] * v27->info.viewerspace_location.y
                               + stru_81EF08.m_fOrigin.x;
      *(float *)(*((_DWORD *)&Render::world_lights.static_lights[59].distancesq + v9) + 56) = v29;
      v30 = *((_DWORD *)&Render::world_lights.static_lights[59].distancesq + v9);
      pos_i.vfptr = (PackObjVtbl *)&PackObj::vftable;
      *(float *)(v30 + 60) = v28;
      v32 = __OFSUB__(v9, Render::world_lights.num_static_lights);
      v31 = v9 - Render::world_lights.num_static_lights < 0;
      dword_8460C4[v9] = 1;
    }
    while ( v31 ^ v32 );
  }
  v33 = 0;
  if ( Render::world_lights.num_dynamic_lights > 0 )
  {
    LODWORD(v.x) = 0;
    LODWORD(v.y) = 0;
    LODWORD(v.z) = 0;
    do
    {
      v34 = Render::world_lights.sorted_dynamic_lights[v33];
      pos_i.objcell_id = v34->cellID;
      v35 = v34->info.offset.m_fOrigin.y;
      v36 = v34->info.offset.m_fOrigin.z;
      pos_i.frame.m_fOrigin.x = v34->info.offset.m_fOrigin.x;
      v37 = v34->info.offset.qw;
      pos_i.frame.m_fOrigin.y = v35;
      v38 = v34->info.offset.qx;
      pos_i.frame.m_fOrigin.z = v36;
      v39 = v34->info.offset.qy;
      pos_i.frame.qw = v37;
      v40 = v34->info.offset.qz;
      pos_i.frame.qx = v38;
      v41 = v34->info.offset.m_fl2gv[0];
      pos_i.frame.qy = v39;
      v42 = v34->info.offset.m_fl2gv[1];
      pos_i.frame.qz = v40;
      v43 = v34->info.offset.m_fl2gv[2];
      pos_i.frame.m_fl2gv[0] = v41;
      v44 = v34->info.offset.m_fl2gv[3];
      pos_i.frame.m_fl2gv[1] = v42;
      v45 = v34->info.offset.m_fl2gv[4];
      pos_i.frame.m_fl2gv[2] = v43;
      v46 = v34->info.offset.m_fl2gv[5];
      pos_i.frame.m_fl2gv[3] = v44;
      v47 = v34->info.offset.m_fl2gv[6];
      pos_i.frame.m_fl2gv[4] = v45;
      v48 = v34->info.offset.m_fl2gv[7];
      pos_i.frame.m_fl2gv[5] = v46;
      v49 = v34->info.offset.m_fl2gv[8];
      pos_i.frame.m_fl2gv[6] = v47;
      pos_i.frame.m_fl2gv[7] = v48;
      pos_i.frame.m_fl2gv[8] = v49;
      pos_i.vfptr = (PackObjVtbl *)&Position::vftable;
      v50 = Position::localtolocal(&Render::viewer_pos, &result, &pos_i, &v);
      v34 = (RenderLight *)((char *)v34 + 180);
      v34->d3dLight.Type = LODWORD(v50->x);
      v34->d3dLight.Diffuse.r = v50->y;
      v34->d3dLight.Diffuse.g = v50->z;
      v51 = Render::world_lights.sorted_dynamic_lights[v33];
      v52 = stru_81EF08.m_fl2gv[4] * v51->info.viewerspace_location.y
          + stru_81EF08.m_fl2gv[1] * v51->info.viewerspace_location.x
          + stru_81EF08.m_fl2gv[7] * v51->info.viewerspace_location.z
          + stru_81EF08.m_fOrigin.y;
      v53 = stru_81EF08.m_fl2gv[5] * v51->info.viewerspace_location.y
          + stru_81EF08.m_fl2gv[2] * v51->info.viewerspace_location.x
          + stru_81EF08.m_fl2gv[8] * v51->info.viewerspace_location.z
          + stru_81EF08.m_fOrigin.z;
      ++v33;
      v51->d3dLight.Position.x = stru_81EF08.m_fl2gv[3] * v51->info.viewerspace_location.y
                               + stru_81EF08.m_fl2gv[0] * v51->info.viewerspace_location.x
                               + stru_81EF08.m_fl2gv[6] * v51->info.viewerspace_location.z
                               + stru_81EF08.m_fOrigin.x;
      *(float *)(*((_DWORD *)&Render::world_lights.dynamic_lights[9].distancesq + v33) + 56) = v53;
      v54 = *((_DWORD *)&Render::world_lights.dynamic_lights[9].distancesq + v33);
      pos_i.vfptr = (PackObjVtbl *)&PackObj::vftable;
      *(float *)(v54 + 60) = v52;
      v32 = __OFSUB__(v33, Render::world_lights.num_dynamic_lights);
      v31 = v33 - Render::world_lights.num_dynamic_lights < 0;
      dword_866234[v33] = 1;
    }
    while ( v31 ^ v32 );
  }
  if ( !Render::world_lights.m_bSunlightValid
    && (fabs(Render::world_lights.sunlight.x) >= 0.00019999999
     || fabs(Render::world_lights.sunlight.y) >= 0.00019999999
     || fabs(Render::world_lights.sunlight.z) >= 0.00019999999) )
  {
    LODWORD(Render::world_lights.m_Sunlight.d3dLight.Diffuse.a) = 1065353216;
    Render::world_lights.m_bSunlightValid = 1;
    v55 = sqrt(Render::world_lights.sunlight.y * Render::world_lights.sunlight.y
             + Render::world_lights.sunlight.z * Render::world_lights.sunlight.z + Render::world_lights.sunlight.x
                                                                                 * Render::world_lights.sunlight.x);
    Render::world_lights.m_Sunlight.d3dLight.Diffuse.r = Render::world_lights.sunlight_color.r * v55;
    Render::world_lights.m_Sunlight.d3dLight.Diffuse.g = Render::world_lights.sunlight_color.g * v55;
    Render::world_lights.m_Sunlight.d3dLight.Diffuse.b = Render::world_lights.sunlight_color.b * v55;
    Render::world_lights.m_Sunlight.d3dLight.Direction.x = -Render::world_lights.sunlight.x;
    Render::world_lights.m_Sunlight.d3dLight.Direction.y = -Render::world_lights.sunlight.z;
    Render::world_lights.m_Sunlight.d3dLight.Direction.z = -Render::world_lights.sunlight.y;
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 8460C4: using guessed type int dword_8460C4[];
// 866234: using guessed type int dword_866234[];

//----- (0059B5E0) --------------------------------------------------------  // acclient.c:453521
void __stdcall PrimD3DRender::positionPushInternal(const int op, Position *position)
{
  bool v3; // zf@2
  AC1Legacy::Vector3 *v4; // eax@4
  AC1Legacy::Vector3 *v5; // eax@6
  AC1Legacy::Vector3 *v6; // edx@6
  AC1Legacy::Vector3 *v7; // eax@6
  AC1Legacy::Vector3 *v8; // esi@6
  double v9; // st7@6
  double v10; // st6@6
  float v11; // ecx@6
  AC1Legacy::Vector3 v; // [sp+4h] [bp-18h]@6
  AC1Legacy::Vector3 result; // [sp+10h] [bp-Ch]@6

  if ( op & 1 )
  {
    v3 = Render::FramePushCount++ == 0;
    if ( v3 )
    {
      Render::FrameCurrent = (AC1Legacy::Vector3 *)&Render::FrameStack;
      dword_866480 = position->objcell_id;
      Frame::operator=((int)&unk_866484, (int)&position->frame);
    }
    else
    {
      v4 = Render::FrameCurrent + 30;
      Render::FrameCurrent = v4;
      v4 = (AC1Legacy::Vector3 *)((char *)v4 + 28);
      LODWORD(v4->y) = position->objcell_id;
      Frame::operator=((int)&v4->z, (int)&position->frame);
    }
  }
  if ( op & 2 )
  {
    LODWORD(v.x) = 0;
    LODWORD(v.y) = 0;
    LODWORD(v.z) = 0;
    v5 = Position::localtolocal((Position *)&Render::FrameCurrent[2].y, &result, &Render::viewer_pos, &v);
    v6 = Render::FrameCurrent;
    Render::FrameCurrent->x = v5->x;
    v6->y = v5->y;
    v6->z = v5->z;
    v7 = Render::FrameCurrent;
    Render::FrameCurrent->x = Render::FrameCurrent->x / Render::object_scale_vec.x;
    v7->y = v7->y / *(float *)&dword_81EEB4;
    v7->z = v7->z / *(float *)&dword_81EEB8;
    *(AC1Legacy::Vector3 *)((char *)Render::FrameCurrent + 116) = (AC1Legacy::Vector3)Render::object_scale_vec;
    Render::FrameCurrent[9].y = Render::object_scale;
    v8 = Render::FrameCurrent;
    LandDefs::get_block_offset(&v, dword_81EF04, LODWORD(Render::FrameCurrent[2].z));
    v9 = v.x + v8[7].y;
    v8 = (AC1Legacy::Vector3 *)((char *)v8 + 100);
    v10 = v.y + v8[-1].y;
    result.z = v.z + v8[-1].z;
    v11 = result.z;
    v.x = v9;
    LODWORD(v8->x) = (_DWORD)v.x;
    v.y = v10;
    v8->y = v.y;
    v8->z = v11;
    Render::FrameEra = Render::FrameEraNext;
    LODWORD(Render::FrameCurrent[29].y) = Render::FrameEraNext++;
  }
}
// 81EC74: using guessed type float Render::object_scale;
// 81EC8C: using guessed type int Render::FrameEraNext;
// 81EEB0: using guessed type struct Vector3 Render::object_scale_vec;
// 81EEB4: using guessed type int dword_81EEB4;
// 81EEB8: using guessed type int dword_81EEB8;
// 866328: using guessed type int Render::FramePushCount;
// 866330: using guessed type int Render::FrameEra;
// 866480: using guessed type int dword_866480;

//----- (0059B780) --------------------------------------------------------  // acclient.c:453595
int PrimD3DRender::positionPopInternal()
{
  AC1Legacy::Vector3 *v1; // eax@2
  float v2; // edx@2
  int result; // eax@2

  --Render::FramePushCount;
  if ( Render::FramePushCount )
  {
    v1 = Render::FrameCurrent - 30;
    Render::FrameCurrent = v1;
    Render::FrameEra = LODWORD(v1[29].y);
    v2 = v1[9].y;
    v1 = (AC1Legacy::Vector3 *)((char *)v1 + 116);
    Render::object_scale = v2;
    Render::object_scale_vec.x = v1->x;
    dword_81EEB4 = LODWORD(v1->y);
    dword_81EEB8 = LODWORD(v1->z);
    result = 1;
  }
  else
  {
    Render::FrameCurrent = 0;
    Render::FrameEra = 0;
    dword_81EEB8 = 1065353216;
    LODWORD(Render::object_scale) = 1065353216;
    LODWORD(Render::object_scale_vec.x) = 1065353216;
    dword_81EEB4 = 1065353216;
    result = 0;
  }
  return result;
}
// 81EC74: using guessed type float Render::object_scale;
// 81EEB0: using guessed type struct Vector3 Render::object_scale_vec;
// 81EEB4: using guessed type int dword_81EEB4;
// 81EEB8: using guessed type int dword_81EEB8;
// 866328: using guessed type int Render::FramePushCount;
// 866330: using guessed type int Render::FrameEra;

//----- (0059B830) --------------------------------------------------------  // acclient.c:453635
void PrimD3DRender::CalcObjectMatrixInternal()
{
  double v1; // st7@3
  float OXaxis_8; // ST2C_4@3
  float OXaxis; // ST24_4@3
  float OYaxis_4; // ST10_4@3
  float OYaxis; // ST0C_4@3
  float OYaxis_8; // ST14_4@3
  float OZaxis; // ST18_4@3
  float OZaxis_4; // ST1C_4@3
  float ObjScaleY; // ST04_4@3
  float OZaxis_8; // ST20_4@3
  double v11; // st6@3
  float ObjScaleZ; // ST08_4@3
  double v13; // st5@3
  double v14; // st4@3
  double v15; // st3@3
  Matrix4 om; // [sp+2Ch] [bp-40h]@3

  if ( Render::FrameCurrent )
  {
    if ( Render::CachedMatrixFrameEra != LODWORD(Render::FrameCurrent[29].y) )
    {
      v1 = Render::FrameCurrent[4].z;
      OXaxis_8 = Render::FrameCurrent[5].x;
      OXaxis = Render::FrameCurrent[4].y;
      OYaxis_4 = Render::FrameCurrent[5].z;
      OYaxis = Render::FrameCurrent[5].y;
      OYaxis_8 = Render::FrameCurrent[6].x;
      OZaxis = Render::FrameCurrent[6].y;
      OZaxis_4 = Render::FrameCurrent[6].z;
      ObjScaleY = Render::FrameCurrent[10].x;
      OZaxis_8 = Render::FrameCurrent[7].x;
      v11 = Render::FrameCurrent[8].y;
      ObjScaleZ = Render::FrameCurrent[10].y;
      v13 = Render::FrameCurrent[8].z;
      v14 = Render::FrameCurrent[9].x;
      v15 = Render::FrameCurrent[9].z;
      LODWORD(om._14) = 0;
      LODWORD(om._24) = 0;
      LODWORD(om._34) = 0;
      om._11 = OXaxis * v15;
      LODWORD(om._44) = 1065353216;
      om._21 = OYaxis * ObjScaleY;
      om._31 = OZaxis * ObjScaleZ;
      om._41 = v11;
      om._12 = OXaxis_8 * v15;
      om._22 = OYaxis_8 * ObjScaleY;
      om._32 = OZaxis_8 * ObjScaleZ;
      om._42 = v14;
      om._13 = v1 * v15;
      om._23 = OYaxis_4 * ObjScaleY;
      om._33 = OZaxis_4 * ObjScaleZ;
      om._43 = v13;
      RenderDeviceD3D::SetModelToWorldMatrix((RenderDeviceD3D *)RenderDevice::render_device, &om);
      Render::CachedMatrixFrameEra = LODWORD(Render::FrameCurrent[29].y);
    }
  }
  else
  {
    Render::CachedMatrixFrameEra = -1;
    RenderDeviceD3D::SetModelToWorldMatrix((RenderDeviceD3D *)RenderDevice::render_device, &Matrix4_IdentityMatrix___5);
  }
}
// 81EC90: using guessed type int Render::CachedMatrixFrameEra;

//----- (0059B980) --------------------------------------------------------  // acclient.c:453702
int PrimD3DRender::InitInternal()
{
  PrimD3DRender::InitializeLights();
  return 1;
}

//----- (0059B990) --------------------------------------------------------  // acclient.c:453709
Vec2Dscreen *__cdecl PrimD3DRender::xformStart(AC1Legacy::Vector3 *worldVertex, int doprojection)
{
  RenderDevice *v2; // esi@3
  int v3; // eax@3
  Matrix4 *v4; // eax@3
  Vec2Dscreen *result; // eax@5
  double v6; // st7@8
  float v7; // edx@9
  float v8; // edx@10
  D3DXVECTOR4 out2; // [sp+0h] [bp-90h]@5
  Matrix4 tm1; // [sp+10h] [bp-80h]@3
  Matrix4 tm2; // [sp+50h] [bp-40h]@3

  if ( !(_S204_34 & 1) )
    _S204_34 |= 1u;
  v2 = RenderDevice::render_device;
  v3 = Render::GetObjectMatrix();
  D3DXMatrixMultiply(&tm1, v3, &v2->m_GState.WorldToViewMatrix);
  D3DXMatrixMultiply(&tm2, &tm1, &v2->m_GState.ViewToClipMatrix);
  v4 = &tm2;
  if ( !doprojection )
    v4 = &tm1;
  D3DXVec3Transform(&out2, worldVertex, v4);
  result = &tmpScreenBuffer[pt_to_use++];
  if ( pt_to_use == 100 )
    pt_to_use = 0;
  if ( doprojection )
  {
    v6 = out2.w;
    result->xw = Render::bw * out2.w * 0.5 + out2.x * Render::bw * 0.5;
    result->yw = v6 * Render::bh * 0.5 - out2.y * Render::bh * 0.5;
  }
  else
  {
    v7 = out2.y;
    LODWORD(result->xw) = (_DWORD)out2.x;
    result->yw = v7;
  }
  v8 = out2.w;
  result->zw = out2.z;
  result->w = v8;
  return result;
}
// 5DF85C: using guessed type _DWORD __stdcall D3DXVec3Transform(_DWORD, _DWORD, _DWORD);
// 5E007C: using guessed type _DWORD __stdcall D3DXMatrixMultiply(_DWORD, _DWORD, _DWORD);
// 8662D0: using guessed type double Render::bh;
// 8662E8: using guessed type double Render::bw;

//----- (0059BAA0) --------------------------------------------------------  // acclient.c:453758
BoundingType __stdcall PrimD3DRender::xformPointInternal(AC1Legacy::Vector3 *i_vec, Vec2D *o_pt)
{
  Vec2Dscreen *v3; // esi@1
  double v4; // st7@1

  v3 = PrimD3DRender::xformStart(i_vec, 1);
  v4 = 1.0 / v3->w;
  o_pt->x = (double)(signed int)(unsigned __int64)(v3->xw * 128.0 * v4) * 0.0078125;
  o_pt->y = (double)(signed int)(unsigned __int64)(v3->yw * 128.0 * v4) * 0.0078125;
  return v3->w >= 0.00019999999;
}

//----- (0070B1D0) --------------------------------------------------------  // acclient.c:798312
int sub_70B1D0()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_34, "Display.Resolution");
  return atexit(_E74_85);
}

//----- (0070B1F0) --------------------------------------------------------  // acclient.c:798319
int _E76_69()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_34, "Display.FullScreen");
  return atexit(_E77_97);
}

//----- (0070B210) --------------------------------------------------------  // acclient.c:798326
int _E79_63()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_34, "Display.RefreshRate");
  return atexit(_E80_62);
}

//----- (0070B230) --------------------------------------------------------  // acclient.c:798333
int _E82_41()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_34, "Display.SyncToRefresh");
  return atexit(_E83_39);
}

//----- (0070B250) --------------------------------------------------------  // acclient.c:798340
void _E85_29()
{
  PixelFormatDesc::PixelFormatDesc(&stru_871248, PFID_A8R8G8B8);
}

//----- (0070B260) --------------------------------------------------------  // acclient.c:798346
void sub_70B260()
{
  LODWORD(dword_871284) = 1053364187;
}

//----- (0070B270) --------------------------------------------------------  // acclient.c:798352
void _E105_50()
{
  flt_871288 = 1000.0 + 1.0;
}

//----- (0070B290) --------------------------------------------------------  // acclient.c:798358
void _E107_41()
{
  flt_87128C = 24.0 * 8.0;
}

//----- (0070B2B0) --------------------------------------------------------  // acclient.c:798364
void _E109_77()
{
  flt_871290 = 24.0 * 0.5;
}

//----- (0070B2D0) --------------------------------------------------------  // acclient.c:798370
int _E111_53()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_37, "Render.TextureFiltering");
  return atexit(sub_774D90);
}

//----- (0070B2F0) --------------------------------------------------------  // acclient.c:798377
int _E114_63()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_37, "Render.LandscapeDetailTextures");
  return atexit(sub_774DC0);
}

//----- (0070B310) --------------------------------------------------------  // acclient.c:798384
int _E117_78()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_37, "Render.BuildingDetailTextures");
  return atexit(sub_774DF0);
}

//----- (0070B330) --------------------------------------------------------  // acclient.c:798391
int _E120_72()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_37, "Render.FieldOfView");
  return atexit(sub_774E20);
}

//----- (0070B350) --------------------------------------------------------  // acclient.c:798398
int _E123_43()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_37, "Render.LandscapeTextureDetail");
  return atexit(sub_774E50);
}

//----- (0070B370) --------------------------------------------------------  // acclient.c:798405
int _E126_50()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_37, "Render.EnvironmentTextureDetail");
  return atexit(sub_774E80);
}

//----- (0070B390) --------------------------------------------------------  // acclient.c:798412
int _E129_44()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_37, "Render.SceneryDrawDistance");
  return atexit(sub_774EB0);
}

//----- (0070B3B0) --------------------------------------------------------  // acclient.c:798419
int _E132_44()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_37, "Render.LandscapeDrawDistance");
  return atexit(sub_774EE0);
}

//----- (0070B3D0) --------------------------------------------------------  // acclient.c:798426
int _E135_51()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_37, "Render.ScreenBrightness");
  return atexit(_E136_86);
}

//----- (0070B3F0) --------------------------------------------------------  // acclient.c:798433
int _E138_39()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_37, "Render.AspectRatio");
  return atexit(_E139_86);
}

//----- (0070B410) --------------------------------------------------------  // acclient.c:798440
int _E141_41()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_37, "Render.DisplayAdapter");
  return atexit(_E142_81);
}

//----- (0070B430) --------------------------------------------------------  // acclient.c:798447
int _E144_38()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_37, "Render.MaxHardwareClass");
  return atexit(_E145_83);
}

//----- (0070B450) --------------------------------------------------------  // acclient.c:798454
int _E147_37()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_37, "Render.AutomaticDegrades");
  return atexit(_E148_79);
}

//----- (0070B470) --------------------------------------------------------  // acclient.c:798461
int _E150_36()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_37, "Render.GraphicsPerformance");
  return atexit(_E151_77);
}

//----- (0070B490) --------------------------------------------------------  // acclient.c:798468
int _E153_34()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_37, "Render.DegradeDistance");
  return atexit(_E154_78);
}

//----- (0070B4B0) --------------------------------------------------------  // acclient.c:798475
int _E156_36()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_37, "Render.MultiPassAlpha");
  return atexit(_E157_74);
}

//----- (0070B4D0) --------------------------------------------------------  // acclient.c:798482
int _E159_34()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_37, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8712D8, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8712DC, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8712E0, "Anisotropic");
  return atexit(_E160_77);
}

//----- (0070B520) --------------------------------------------------------  // acclient.c:798492
int _E162_37()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_37, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8712E8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8712EC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8712F0, "High");
  PStringBase<char>::PStringBase<char>(&stru_8712F4, "VeryHigh");
  return atexit(_E163_70);
}

//----- (0070B580) --------------------------------------------------------  // acclient.c:798503
int _E165_32()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_37, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8712FC, "Low");
  PStringBase<char>::PStringBase<char>(&stru_871300, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_871304, "High");
  PStringBase<char>::PStringBase<char>(&stru_871308, "VeryHigh");
  return atexit(_E166_72);
}

//----- (0070B5E0) --------------------------------------------------------  // acclient.c:798514
int _E168_33()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_37, "Low");
  PStringBase<char>::PStringBase<char>(&stru_871310, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_871314, "High");
  return atexit(_E169_71);
}

//----- (0070B620) --------------------------------------------------------  // acclient.c:798523
int _E171_32()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_37, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_87131C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_871320, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_871324, "High");
  PStringBase<char>::PStringBase<char>(&stru_871328, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_87132C, "Extreme");
  return atexit(_E172_69);
}

//----- (0070B690) --------------------------------------------------------  // acclient.c:798535
int _E174_34()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_37, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_871334, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_871338, "Wide");
  return atexit(_E175_66);
}

//----- (0070B6D0) --------------------------------------------------------  // acclient.c:798544
int _E177_31()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_64, "None");
  return atexit(_E178_66);
}

//----- (0070B6F0) --------------------------------------------------------  // acclient.c:798551
int _E180_31()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_64, "Speed");
  return atexit(_E181_66);
}

//----- (0070B710) --------------------------------------------------------  // acclient.c:798558
int _E183_30()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_64, "Noise");
  return atexit(_E184_63);
}

//----- (0070B730) --------------------------------------------------------  // acclient.c:798565
int _E186_30()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_64, "Sine");
  return atexit(_E187_62);
}

//----- (0070B750) --------------------------------------------------------  // acclient.c:798572
int _E189_29()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_64, "Square");
  return atexit(_E190_63);
}

//----- (0070B770) --------------------------------------------------------  // acclient.c:798579
int _E192_24()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_64, "Bounce");
  return atexit(_E193_50);
}

//----- (0070B790) --------------------------------------------------------  // acclient.c:798586
int _E195_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_64, "Perlin");
  return atexit(_E196_57);
}

//----- (0070B7B0) --------------------------------------------------------  // acclient.c:798593
int _E198_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_64, "Fractal");
  return atexit(_E199_49);
}

//----- (0070B7D0) --------------------------------------------------------  // acclient.c:798600
int _E201_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_64, "FrameLoop");
  return atexit(_E202_50);
}

//----- (0070B7F0) --------------------------------------------------------  // acclient.c:798607
int sub_70B7F0()
{
  return atexit(nullsub_1442);
}

//----- (00774CD0) --------------------------------------------------------  // acclient.c:908294
void __cdecl _E74_85()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774D00) --------------------------------------------------------  // acclient.c:908307
void __cdecl _E77_97()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774D30) --------------------------------------------------------  // acclient.c:908320
void __cdecl _E80_62()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774D60) --------------------------------------------------------  // acclient.c:908333
void __cdecl _E83_39()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774D90) --------------------------------------------------------  // acclient.c:908346
void __cdecl sub_774D90()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774DC0) --------------------------------------------------------  // acclient.c:908359
void __cdecl sub_774DC0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774DF0) --------------------------------------------------------  // acclient.c:908372
void __cdecl sub_774DF0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774E20) --------------------------------------------------------  // acclient.c:908385
void __cdecl sub_774E20()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774E50) --------------------------------------------------------  // acclient.c:908398
void __cdecl sub_774E50()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774E80) --------------------------------------------------------  // acclient.c:908411
void __cdecl sub_774E80()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774EB0) --------------------------------------------------------  // acclient.c:908424
void __cdecl sub_774EB0()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774EE0) --------------------------------------------------------  // acclient.c:908437
void __cdecl sub_774EE0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774F10) --------------------------------------------------------  // acclient.c:908450
void __cdecl _E136_86()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774F40) --------------------------------------------------------  // acclient.c:908463
void __cdecl _E139_86()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774F70) --------------------------------------------------------  // acclient.c:908476
void __cdecl _E142_81()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774FA0) --------------------------------------------------------  // acclient.c:908489
void __cdecl _E145_83()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774FD0) --------------------------------------------------------  // acclient.c:908502
void __cdecl _E148_79()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775000) --------------------------------------------------------  // acclient.c:908515
void __cdecl _E151_77()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775030) --------------------------------------------------------  // acclient.c:908528
void __cdecl _E154_78()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775060) --------------------------------------------------------  // acclient.c:908541
void __cdecl _E157_74()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775090) --------------------------------------------------------  // acclient.c:908554
void __cdecl _E160_77()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_37;
  v1 = 4;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (007750D0) --------------------------------------------------------  // acclient.c:908579
void __cdecl _E163_70()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_37;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00775110) --------------------------------------------------------  // acclient.c:908604
void __cdecl _E166_72()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_37;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00775150) --------------------------------------------------------  // acclient.c:908629
void __cdecl _E169_71()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_37;
  v1 = 3;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00775190) --------------------------------------------------------  // acclient.c:908654
void __cdecl _E172_69()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_37;
  v1 = 6;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (007751D0) --------------------------------------------------------  // acclient.c:908679
void __cdecl _E175_66()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_64;
  v1 = 3;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00775210) --------------------------------------------------------  // acclient.c:908704
void __cdecl _E178_66()
{
  char *v0; // esi@1

  v0 = &waveform_None_64.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_64.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775240) --------------------------------------------------------  // acclient.c:908717
void __cdecl _E181_66()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_64.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_64.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775270) --------------------------------------------------------  // acclient.c:908730
void __cdecl _E184_63()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_64.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_64.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007752A0) --------------------------------------------------------  // acclient.c:908743
void __cdecl _E187_62()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_64.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_64.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007752D0) --------------------------------------------------------  // acclient.c:908756
void __cdecl _E190_63()
{
  char *v0; // esi@1

  v0 = &waveform_Square_64.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_64.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775300) --------------------------------------------------------  // acclient.c:908769
void __cdecl _E193_50()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_64.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_64.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775330) --------------------------------------------------------  // acclient.c:908782
void __cdecl _E196_57()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_64.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_64.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775360) --------------------------------------------------------  // acclient.c:908795
void __cdecl _E199_49()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_64.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_64.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00775390) --------------------------------------------------------  // acclient.c:908808
void __cdecl _E202_50()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_64.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_64.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

