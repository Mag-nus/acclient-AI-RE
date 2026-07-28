/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Render
   Object     : PORTAL\render\Render.obj
   Functions  : 195
   Addresses  : 00439340 - 00771A40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00439340) --------------------------------------------------------  // acclient.c:118238
void __thiscall SmartArray<RenderDisplayModeType,1>::Reset(SmartArray<RenderDisplayModeType,1> *this)
{
  SmartArray<RenderDisplayModeType,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@4
  int v5; // ecx@4
  int v6; // eax@5
  int v7; // ecx@5
  int v8; // ebx@6
  int v9; // [sp+8h] [bp-10h]@0
  int v10; // [sp+Ch] [bp-Ch]@0
  int v11; // [sp+10h] [bp-8h]@0
  int v12; // [sp+14h] [bp-4h]@0

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    v5 = v4;
    if ( v4 >= 0 )
    {
      v6 = v4;
      v7 = v5 + 1;
      do
      {
        v8 = (int)&v1->m_data[v6];
        *(_DWORD *)v8 = v9;
        *(_DWORD *)(v8 + 4) = v10;
        *(_DWORD *)(v8 + 8) = v11;
        --v6;
        --v7;
        *(_DWORD *)(v8 + 12) = v12;
      }
      while ( v7 );
    }
  }
}

//----- (0054B020) --------------------------------------------------------  // acclient.c:378742
void __cdecl Render::SetOverallGraphicsQuality(unsigned int _Level)
{
  switch ( _Level )
  {
    case 1u:
      Render::m_RenderPrefs.TextureFiltering = 0;
      byte_81EF95 = 0;
      byte_81EF96 = 0;
      dword_81EF98 = 4;
      dword_81EFA0 = 0;
      mid_radius = 3;
      byte_81EF94 = 0;
      dword_81EF9C = 4;
      break;
    case 2u:
      Render::m_RenderPrefs.TextureFiltering = 0;
      byte_81EF94 = 0;
      byte_81EF95 = 0;
      byte_81EF96 = 0;
      dword_81EF98 = 3;
      dword_81EF9C = 3;
      dword_81EFA0 = 1;
      mid_radius = 5;
      break;
    case 3u:
      Render::m_RenderPrefs.TextureFiltering = 0;
      byte_81EF94 = 0;
      byte_81EF95 = 0;
      byte_81EF96 = 0;
      dword_81EF98 = 2;
      dword_81EF9C = 2;
      dword_81EFA0 = 1;
      mid_radius = 8;
      break;
    case 4u:
      Render::m_RenderPrefs.TextureFiltering = 1;
      byte_81EF94 = 0;
      byte_81EF95 = 1;
      byte_81EF96 = 1;
      dword_81EF98 = 2;
      dword_81EFA0 = 2;
      mid_radius = 11;
      dword_81EF9C = 1;
      break;
    case 5u:
      Render::m_RenderPrefs.TextureFiltering = 1;
      byte_81EF95 = 1;
      byte_81EF96 = 1;
      dword_81EF98 = 0;
      dword_81EFA0 = 2;
      mid_radius = 15;
      byte_81EF94 = 0;
      dword_81EF9C = 1;
      break;
    default:
      return;
  }
}
// 81EF90: using guessed type struct RenderPrefs Render::m_RenderPrefs;
// 81EF94: using guessed type char byte_81EF94;
// 81EF95: using guessed type char byte_81EF95;
// 81EF96: using guessed type char byte_81EF96;
// 81EF98: using guessed type int dword_81EF98;
// 81EF9C: using guessed type int dword_81EF9C;
// 81EFA0: using guessed type int dword_81EFA0;

//----- (0054B170) --------------------------------------------------------  // acclient.c:378809
signed int __cdecl Render::DetermineOverallGraphicsQuality()
{
  signed int result; // eax@1
  int v1; // ecx@1
  bool v2; // zf@9

  result = 1;
  v1 = 0;
  while ( 2 )
  {
    switch ( v1 )
    {
      case 0:
        if ( Render::m_RenderPrefs.TextureFiltering
          || byte_81EF95
          || byte_81EF96
          || dword_81EF98 != 4
          || dword_81EF9C != 4
          || dword_81EFA0 )
          goto $L133242;
        v2 = mid_radius == 3;
        goto LABEL_17;
      case 1:
        if ( Render::m_RenderPrefs.TextureFiltering
          || byte_81EF95
          || byte_81EF96
          || dword_81EF98 != 3
          || dword_81EF9C != 3
          || dword_81EFA0 != 1 )
          goto $L133242;
        v2 = mid_radius == 5;
LABEL_17:
        if ( !v2 )
          goto $L133242;
        return result;
      case 2:
      case 3:
      case 4:
$L133242:
        ++result;
        ++v1;
        if ( (unsigned int)result <= 5 )
          continue;
        result = 0;
        break;
      default:
        return result;
    }
    return result;
  }
}
// 81EF90: using guessed type struct RenderPrefs Render::m_RenderPrefs;
// 81EF95: using guessed type char byte_81EF95;
// 81EF96: using guessed type char byte_81EF96;
// 81EF98: using guessed type int dword_81EF98;
// 81EF9C: using guessed type int dword_81EF9C;
// 81EFA0: using guessed type int dword_81EFA0;

//----- (0054B220) --------------------------------------------------------  // acclient.c:378868
int __cdecl Render::Set3DView(int _x, int _y, int _width, int _height)
{
  return ((int (__stdcall *)(int, int, int, int))Render::m_pRenderer->vfptr->Set3DViewInternal)(_x, _y, _width, _height);
}

//----- (0054B240) --------------------------------------------------------  // acclient.c:378874
void __cdecl Render::set_vdst(float _vdst)
{
  long double v1; // st7@1
  long double v2; // st7@1
  float v3; // ST00_4@8

  v1 = atan2(_vdst, 1.0);
  v2 = v1 + v1;
  if ( _vdst >= 0.40000001 )
    LODWORD(Render::znear) = 1036831949;
  else
    Render::znear = _vdst * 0.25;
  if ( v2 >= 0.001 )
  {
    if ( v2 > 3.141592653589793 )
      v2 = 3.141592653589793;
    v3 = v2;
    ((void (__stdcall *)(_DWORD))Render::m_pRenderer->vfptr->SetFOVInternal)(LODWORD(v3));
  }
  else
  {
    ((void (__stdcall *)(_DWORD))Render::m_pRenderer->vfptr->SetFOVInternal)(0.001);
  }
}

//----- (0054B2D0) --------------------------------------------------------  // acclient.c:378900
int __cdecl Render::SetFOVRad(float _radians)
{
  int result; // eax@3

  if ( _radians <= 0.0 || _radians >= 3.141592653589793 )
  {
    result = 0;
  }
  else
  {
    LODWORD(Render::znear) = 1036831949;
    ((void (__stdcall *)(_DWORD))Render::m_pRenderer->vfptr->SetFOVInternal)(LODWORD(_radians));
    result = 1;
  }
  return result;
}

//----- (0054B320) --------------------------------------------------------  // acclient.c:378918
void __cdecl Render::set_zfar(float _zfar)
{
  Render::zfar = _zfar;
  ((void (__stdcall *)(_DWORD))Render::m_pRenderer->vfptr->SetFOVInternal)(LODWORD(Render::fov));
}
// 81EC78: using guessed type float Render::fov;

//----- (0054B340) --------------------------------------------------------  // acclient.c:378926
void __stdcall Render::SetFOVInternal(float _radians)
{
  Render::bw = (double)RenderDevice::render_device->m_viewportWidth;
  Render::bh = (double)RenderDevice::render_device->m_viewportHeight;
  Render::fov = _radians;
  Render::xinvscale = 1.0 / Render::scale;
  Render::yinvscale = Render::xinvscale;
  Render::tx = (Render::bw - 1.0) * 0.5 * Render::xinvscale;
  Render::ty = (Render::bh - 1.0) * 0.5 * Render::xinvscale;
  Render::vdst = Render::ty / tan(_radians * 0.5);
}
// 81EC78: using guessed type float Render::fov;
// 81EC7C: using guessed type float Render::scale;
// 81EC80: using guessed type float Render::vdst;
// 846048: using guessed type double Render::tx;
// 8662C8: using guessed type double Render::xinvscale;
// 8662D0: using guessed type double Render::bh;
// 8662E0: using guessed type double Render::yinvscale;
// 8662E8: using guessed type double Render::bw;
// 866300: using guessed type double Render::ty;

//----- (0054B400) --------------------------------------------------------  // acclient.c:378948
void __cdecl Render::GetViewerBBox(CSphere *sphere, AC1Legacy::Vector3 *top_left, AC1Legacy::Vector3 *bottom_right)
{
  double v3; // st7@1
  double v4; // st6@1
  float local_xaxis_8; // ST38_4@1
  double v6; // st5@1
  double v7; // st4@1
  float local_zaxis_8; // ST2C_4@1
  double v9; // st3@1
  float v10; // ST10_4@1
  float v11; // ST14_4@1
  double v12; // st1@1
  float v13; // ST00_4@1
  float v14; // ST04_4@1
  float v15; // ST08_4@1
  float v16; // ST1C_4@1
  float v17; // ST20_4@1
  float v18; // ST20_4@1
  float v19; // ST00_4@1
  float v20; // ST04_4@1
  float v21; // edx@1
  float v22; // ST00_4@1
  float v23; // ST04_4@1
  float v24; // ST08_4@1
  float local_zaxis; // ST24_4@1
  float v26; // ST18_4@1
  float v27; // ST1C_4@1
  float v28; // ST38_4@1
  float v29; // ST00_4@1
  float v30; // ST04_4@1

  v3 = flt_86B1C4 * Render::FrameCurrent[4].z
     + flt_86B1C8 * Render::FrameCurrent[5].x
     + Render::Xaxis.x * Render::FrameCurrent[4].y;
  v4 = flt_86B1C4 * Render::FrameCurrent[5].z
     + flt_86B1C8 * Render::FrameCurrent[6].x
     + Render::Xaxis.x * Render::FrameCurrent[5].y;
  local_xaxis_8 = flt_86B1C4 * Render::FrameCurrent[6].z
                + flt_86B1C8 * Render::FrameCurrent[7].x
                + Render::Xaxis.x * Render::FrameCurrent[6].y;
  v6 = flt_86642C * Render::FrameCurrent[4].z
     + flt_866430 * Render::FrameCurrent[5].x
     + Render::Zaxis.x * Render::FrameCurrent[4].y;
  v7 = flt_86642C * Render::FrameCurrent[5].z
     + flt_866430 * Render::FrameCurrent[6].x
     + Render::Zaxis.x * Render::FrameCurrent[5].y;
  local_zaxis_8 = flt_86642C * Render::FrameCurrent[6].z
                + flt_866430 * Render::FrameCurrent[7].x
                + Render::Zaxis.x * Render::FrameCurrent[6].y;
  v9 = sphere->radius;
  v10 = v4 * v9;
  v11 = local_xaxis_8 * v9;
  v12 = sphere->radius;
  v13 = v6 * v12;
  v14 = v7 * v12;
  v15 = local_zaxis_8 * v12;
  v16 = sphere->center.y - v10;
  v17 = sphere->center.z - v11;
  v18 = v17 + v15;
  v19 = sphere->center.x - v3 * v9 + v13;
  top_left->x = v19;
  v20 = v16 + v14;
  top_left->y = v20;
  top_left->z = v18;
  v21 = sphere->radius;
  v22 = v21 * v6;
  v23 = v7 * v21;
  v24 = local_zaxis_8 * v21;
  local_zaxis = v21 * v3;
  v26 = local_zaxis + sphere->center.x;
  v27 = v4 * v21 + sphere->center.y;
  v28 = local_xaxis_8 * v21 + sphere->center.z - v24;
  v29 = v26 - v22;
  bottom_right->x = v29;
  v30 = v27 - v23;
  bottom_right->y = v30;
  bottom_right->z = v28;
}
// 866428: using guessed type struct Vector3 Render::Zaxis;
// 86642C: using guessed type float flt_86642C;
// 866430: using guessed type float flt_866430;
// 86B1C0: using guessed type struct Vector3 Render::Xaxis;
// 86B1C4: using guessed type float flt_86B1C4;
// 86B1C8: using guessed type float flt_86B1C8;

//----- (0054B610) --------------------------------------------------------  // acclient.c:379034
AC1Legacy::Vector3 *__cdecl Render::pick_ray(AC1Legacy::Vector3 *result, int x, int y)
{
  double v3; // st7@1
  float v4; // ST1C_4@1
  float v5; // ST20_4@1
  float v6; // ST2C_4@1
  double v7; // st3@1
  float f_4; // ST10_4@1
  float f_8; // ST14_4@1
  float v10; // ST00_4@1
  float v11; // ST04_4@1
  float v12; // ST08_4@1
  double v13; // st7@1
  double v14; // st6@1
  double v15; // st5@1
  float v16; // ST04_4@1
  float v17; // ST08_4@1
  long double v18; // st4@1
  AC1Legacy::Vector3 *v19; // eax@1
  int ya; // [sp+3Ch] [bp+Ch]@1

  v3 = (double)y * Render::yinvscale - Render::ty;
  v4 = flt_86642C * v3;
  v5 = flt_866430 * v3;
  v6 = flt_86B184 * Render::vdst;
  v7 = (double)x * Render::xinvscale - Render::tx;
  f_4 = flt_86B1C4 * v7;
  f_8 = flt_86B1C8 * v7;
  v10 = Render::Xaxis.x * v7 + Render::Yaxis.x * Render::vdst;
  v11 = f_4 + flt_86B180 * Render::vdst;
  v12 = f_8 + v6;
  v13 = v10 - Render::Zaxis.x * v3;
  v14 = v11 - v4;
  v15 = v12 - v5;
  v16 = v14;
  v17 = v15;
  v18 = sqrt(v15 * v15 + v14 * v14 + v13 * v13);
  *(float *)&ya = 1.0 / v18;
  v19 = result;
  result->x = v13 * (1.0 / v18);
  result->y = v16 * *(float *)&ya;
  result->z = v17 * *(float *)&ya;
  return v19;
}
// 81EC80: using guessed type float Render::vdst;
// 846048: using guessed type double Render::tx;
// 8662C8: using guessed type double Render::xinvscale;
// 8662E0: using guessed type double Render::yinvscale;
// 866300: using guessed type double Render::ty;
// 866428: using guessed type struct Vector3 Render::Zaxis;
// 86642C: using guessed type float flt_86642C;
// 866430: using guessed type float flt_866430;
// 86B17C: using guessed type struct Vector3 Render::Yaxis;
// 86B180: using guessed type float flt_86B180;
// 86B184: using guessed type float flt_86B184;
// 86B1C0: using guessed type struct Vector3 Render::Xaxis;
// 86B1C4: using guessed type float flt_86B1C4;
// 86B1C8: using guessed type float flt_86B1C8;

//----- (0054B750) --------------------------------------------------------  // acclient.c:379094
void __cdecl Render::set_selection_cursor(int x, int y, bool fPolyAccurate)
{
  Render::selection_x = x;
  Render::selection_y = y;
  Render::check_selection = 1;
  Render::check_curr_object_polys = fPolyAccurate;
  Render::m_MouseSelectData.bFoundPolygon = 0;
  byte_86B1A8 = 0;
}
// 866339: using guessed type bool Render::check_curr_object_polys;
// 86633A: using guessed type bool Render::check_selection;
// 86B190: using guessed type struct Render::MouseSelectData Render::m_MouseSelectData;
// 86B1A8: using guessed type char byte_86B1A8;

//----- (0054B790) --------------------------------------------------------  // acclient.c:379109
void __cdecl Render::clear_selection_cursor()
{
  Render::check_selection = 0;
  Render::check_curr_object_polys = 0;
  Render::m_MouseSelectData.bFoundPolygon = 0;
  byte_86B1A8 = 0;
}
// 866339: using guessed type bool Render::check_curr_object_polys;
// 86633A: using guessed type bool Render::check_selection;
// 86B190: using guessed type struct Render::MouseSelectData Render::m_MouseSelectData;
// 86B1A8: using guessed type char byte_86B1A8;

//----- (0054B7B0) --------------------------------------------------------  // acclient.c:379122
void __cdecl Render::SetSurfaceArray(CSurface **surf_array)
{
  Render::curr_surfaces = surf_array;
}

//----- (0054B7C0) --------------------------------------------------------  // acclient.c:379128
void __cdecl Render::SetLandscapeDetailSurface(CSurface *s)
{
  Render::landscape_detail_surface = s;
}
// 866354: using guessed type struct CSurface *Render::landscape_detail_surface;

//----- (0054B7D0) --------------------------------------------------------  // acclient.c:379135
void __cdecl Render::SetBuildingDetailSurface(CSurface *s)
{
  Render::building_detail_surface = s;
}
// 866358: using guessed type struct CSurface *Render::building_detail_surface;

//----- (0054B7E0) --------------------------------------------------------  // acclient.c:379142
void __cdecl Render::SetEnvironmentDetailSurface(CSurface *s)
{
  Render::environment_detail_surface = s;
}
// 86635C: using guessed type struct CSurface *Render::environment_detail_surface;

//----- (0054B7F0) --------------------------------------------------------  // acclient.c:379149
void __cdecl Render::SetObjectDetailSurface(CSurface *s)
{
  Render::object_detail_surface = s;
}
// 866360: using guessed type struct CSurface *Render::object_detail_surface;

//----- (0054B800) --------------------------------------------------------  // acclient.c:379156
void __cdecl Render::SetLandscapeDetailTiling(float tiling)
{
  Render::landscape_detail_tiling = tiling;
}
// 81ECA8: using guessed type float Render::landscape_detail_tiling;

//----- (0054B810) --------------------------------------------------------  // acclient.c:379163
void __cdecl Render::SetEnvironmentDetailTiling(float tiling)
{
  Render::environment_detail_tiling = tiling;
}
// 81ECAC: using guessed type float Render::environment_detail_tiling;

//----- (0054B820) --------------------------------------------------------  // acclient.c:379170
void __cdecl Render::SetBuildingDetailTiling(float tiling)
{
  Render::building_detail_tiling = tiling;
}
// 81ECB0: using guessed type float Render::building_detail_tiling;

//----- (0054B830) --------------------------------------------------------  // acclient.c:379177
void __cdecl Render::SetObjectDetailTiling(float tiling)
{
  Render::object_detail_tiling = tiling;
}
// 81ECB4: using guessed type float Render::object_detail_tiling;

//----- (0054B840) --------------------------------------------------------  // acclient.c:379184
double __cdecl Render::get_pt_limit(float x, float y, Plane *plane)
{
  double v3; // st7@2
  double result; // st7@4
  AC1Legacy::Vector3 vec; // [sp+0h] [bp-Ch]@10
  float planea; // [sp+18h] [bp+Ch]@2

  if ( plane->N.z > 0.00019999999 )
  {
    v3 = -((y * plane->N.y + x * plane->N.x + plane->d) / plane->N.z);
    planea = v3;
    if ( v3 < 1000.0 )
    {
      if ( planea > 0.0 )
        return -planea;
      return 0.0;
    }
    return flt_86B120;
  }
  if ( -0.00019999999 <= plane->N.z )
  {
    vec.x = x;
    vec.y = y;
    LODWORD(vec.z) = 0;
    if ( Plane::which_side(plane, &vec, 0.00019999999) != 1 )
      return 0.0;
    return flt_86B120;
  }
  result = -((y * plane->N.y + x * plane->N.x + plane->d) / plane->N.z);
  if ( result <= 0.0 )
    return flt_86B120;
  if ( result >= 1000.0 )
    result = 0.0;
  return result;
}

//----- (0054B930) --------------------------------------------------------  // acclient.c:379221
signed int __cdecl Render::corner_plane_check(float corner, float min, float max)
{
  double v4; // st7@3
  unsigned __int8 v5; // c0@3
  unsigned __int8 v6; // c3@3
  double v8; // st7@7

  if ( corner == flt_86B120 )
    return 0;
  if ( corner == 0.0 )
    return 2;
  v4 = corner;
  if ( !(v5 | v6) )
  {
    if ( v4 < max )
    {
      if ( corner <= (double)min )
        return 0;
      return 1;
    }
    return 2;
  }
  v8 = -v4;
  if ( v8 <= min )
    return 2;
  if ( v8 >= max )
    return 0;
  return 1;
}

//----- (0054B9B0) --------------------------------------------------------  // acclient.c:379252
void __cdecl Render::obj_view_set()
{
  AC1Legacy::Vector3 *v0; // eax@1
  int v1; // edi@1
  unsigned int v2; // esi@1
  _UNKNOWN *v3; // edx@2
  char *v4; // ecx@2
  int v5; // ebx@3
  float v6; // ST14_4@3
  float v7; // ST18_4@3
  float v8; // ST1C_4@3
  double v9; // st6@3
  float v10; // ST14_4@3
  float v11; // ST18_4@3
  int v12; // ebx@3
  float v13; // ST1C_4@3
  double v14; // st6@3
  int v15; // ebx@3
  float v16; // ST14_4@3
  float v17; // ST18_4@3
  float v18; // ST1C_4@3
  double v19; // st6@3
  int v20; // ebx@3
  double v21; // st4@3
  double v22; // st3@3
  float v23; // ST14_4@3
  float v24; // ST18_4@3
  float v25; // ST1C_4@3
  double v26; // st6@3
  char *v27; // edx@5
  char *v28; // ecx@5
  int v29; // edi@5
  char *v30; // esi@6
  float v31; // ST14_4@6
  float v32; // ST18_4@6
  float v33; // ST1C_4@6
  double v34; // st6@6
  int v35; // edx@7
  float v36; // ST14_4@7
  float v37; // ST18_4@7
  float v38; // ST1C_4@7
  double v39; // st6@7
  signed int v40; // [sp+Ch] [bp-10h]@2

  v0 = Render::FrameCurrent;
  v1 = Render::portal_npnts;
  v2 = 0;
  if ( Render::portal_npnts >= 4 )
  {
    v40 = 3;
    v3 = &unk_86F094;
    v4 = (char *)&Render::portal_vertex->plane.N.y;
    do
    {
      v5 = (int)((char *)v3 - 28);
      v6 = *(float *)v4 * v0[4].z + *((float *)v4 - 1) * v0[4].y + *((float *)v4 + 1) * v0[5].x;
      v7 = *((float *)v4 + 1) * v0[6].x + *(float *)v4 * v0[5].z + *((float *)v4 - 1) * v0[5].y;
      v8 = *((float *)v4 - 1) * v0[6].y + v0[7].x * *((float *)v4 + 1) + v0[6].z * *(float *)v4;
      v9 = v0[8].z * *(float *)v4 + v0[8].y * *((float *)v4 - 1) + v0[9].x * *((float *)v4 + 1) + *((float *)v4 + 2);
      *(float *)v5 = v6;
      *(float *)(v5 + 4) = v7;
      *((float *)v3 - 4) = v9;
      *(float *)(v5 + 8) = v8;
      v10 = *((float *)v4 + 6) * v0[4].z + *((float *)v4 + 5) * v0[4].y + *((float *)v4 + 7) * v0[5].x;
      v11 = *((float *)v4 + 7) * v0[6].x + *((float *)v4 + 6) * v0[5].z + *((float *)v4 + 5) * v0[5].y;
      v12 = (int)((char *)v3 - 12);
      v13 = *((float *)v4 + 5) * v0[6].y + v0[7].x * *((float *)v4 + 7) + v0[6].z * *((float *)v4 + 6);
      v14 = v0[8].z * *((float *)v4 + 6)
          + v0[8].y * *((float *)v4 + 5)
          + v0[9].x * *((float *)v4 + 7)
          + *((float *)v4 + 8);
      *(float *)v12 = v10;
      *(float *)(v12 + 4) = v11;
      *(float *)v3 = v14;
      *(float *)(v12 + 8) = v13;
      v15 = (int)((char *)v3 + 4);
      v16 = *((float *)v4 + 12) * v0[4].z + *((float *)v4 + 11) * v0[4].y + *((float *)v4 + 13) * v0[5].x;
      v17 = *((float *)v4 + 13) * v0[6].x + *((float *)v4 + 12) * v0[5].z + *((float *)v4 + 11) * v0[5].y;
      v18 = *((float *)v4 + 11) * v0[6].y + v0[7].x * *((float *)v4 + 13) + v0[6].z * *((float *)v4 + 12);
      v19 = v0[8].z * *((float *)v4 + 12)
          + v0[8].y * *((float *)v4 + 11)
          + v0[9].x * *((float *)v4 + 13)
          + *((float *)v4 + 14);
      *(float *)v15 = v16;
      *(float *)(v15 + 4) = v17;
      *((float *)v3 + 4) = v19;
      *(float *)(v15 + 8) = v18;
      v20 = (int)((char *)v3 + 20);
      v21 = *((float *)v4 + 18) * v0[4].z;
      v2 += 4;
      v22 = *((float *)v4 + 17);
      v4 += 96;
      v3 = (char *)v3 + 64;
      v23 = v21 + v22 * v0[4].y + *((float *)v4 - 5) * v0[5].x;
      v24 = *((float *)v4 - 5) * v0[6].x + *((float *)v4 - 6) * v0[5].z + *((float *)v4 - 7) * v0[5].y;
      v25 = *((float *)v4 - 7) * v0[6].y + v0[7].x * *((float *)v4 - 5) + v0[6].z * *((float *)v4 - 6);
      v26 = v0[8].z * *((float *)v4 - 6)
          + v0[8].y * *((float *)v4 - 7)
          + v0[9].x * *((float *)v4 - 5)
          + *((float *)v4 - 4);
      *(float *)v20 = v23;
      *(float *)(v20 + 4) = v24;
      *((float *)v3 - 8) = v26;
      *(float *)(v20 + 8) = v25;
      v40 += 4;
    }
    while ( v40 < (unsigned int)v1 );
  }
  if ( v2 < v1 )
  {
    v27 = (char *)&Render::portal_obj_plane + 16 * v2;
    v28 = (char *)&Render::portal_vertex[v2].plane.N.y;
    v29 = v1 - v2;
    do
    {
      v30 = v27;
      v28 += 24;
      v27 += 16;
      --v29;
      v31 = *((float *)v28 - 5) * v0[5].x + v0[4].y * *((float *)v28 - 7) + *((float *)v28 - 6) * v0[4].z;
      v32 = v0[5].y * *((float *)v28 - 7) + *((float *)v28 - 5) * v0[6].x + v0[5].z * *((float *)v28 - 6);
      v33 = v0[6].z * *((float *)v28 - 6) + *((float *)v28 - 7) * v0[6].y + v0[7].x * *((float *)v28 - 5);
      v34 = v0[9].x * *((float *)v28 - 5)
          + v0[8].y * *((float *)v28 - 7)
          + v0[8].z * *((float *)v28 - 6)
          + *((float *)v28 - 4);
      *(float *)v30 = v31;
      *((float *)v30 + 1) = v32;
      *((float *)v27 - 1) = v34;
      *((float *)v30 + 2) = v33;
    }
    while ( v29 );
  }
  v35 = (int)&v0[1];
  v36 = plane.N.y * v0[4].z + plane.N.z * v0[5].x + plane.N.x * v0[4].y;
  v37 = plane.N.y * v0[5].z + plane.N.z * v0[6].x + plane.N.x * v0[5].y;
  v38 = plane.N.y * v0[6].z + plane.N.z * v0[7].x + plane.N.x * v0[6].y;
  v39 = v0[8].z * plane.N.y + v0[9].x * plane.N.z + plane.N.x * v0[8].y + plane.d;
  *(float *)v35 = v36;
  *(float *)(v35 + 4) = v37;
  *(float *)(v35 + 12) = v39;
  *(float *)(v35 + 8) = v38;
}
// 846040: using guessed type struct view_vertex *Render::portal_vertex;
// 846050: using guessed type int Render::portal_npnts;

//----- (0054BDB0) --------------------------------------------------------  // acclient.c:379399
void __cdecl Render::positionPush(const int op, Position *position)
{
  ((void (__stdcall *)(_DWORD, _DWORD))Render::m_pRenderer->vfptr->positionPushInternal)(op, position);
}

//----- (0054BDD0) --------------------------------------------------------  // acclient.c:379405
int __cdecl Render::framePop()
{
  return ((int (*)(void))Render::m_pRenderer->vfptr->positionPopInternal)();
}

//----- (0054BDE0) --------------------------------------------------------  // acclient.c:379411
void __cdecl Render::CalcObjectMatrix()
{
  ((void (*)(void))Render::m_pRenderer->vfptr->CalcObjectMatrixInternal)();
}

//----- (0054BDF0) --------------------------------------------------------  // acclient.c:379417
int __cdecl Render::GetObjectMatrix()
{
  return ((int (*)(void))Render::m_pRenderer->vfptr->GetObjectMatrixInternal)();
}

//----- (0054BE00) --------------------------------------------------------  // acclient.c:379423
void __cdecl Render::reset_active_lights_state()
{
  dword_866270 = dword_846060[0];
  dword_866274 = dword_846064;
  dword_866278 = dword_846068;
  dword_86627C = dword_84606C;
  dword_866280 = dword_846070;
  dword_866284 = dword_846074;
  dword_866288 = dword_846078;
  dword_86628C = dword_84607C;
  dword_866290 = dword_846080;
  dword_866294 = dword_846084;
  dword_866298 = dword_846088;
  dword_86629C = dword_84608C;
  dword_8662A0 = dword_846090;
  dword_8662A4 = dword_846094;
  dword_8662A8 = dword_846098;
  dword_8662AC = dword_84609C;
  dword_8662B0 = dword_8460A0;
  dword_8662B4 = dword_8460A4;
  dword_8662B8 = dword_8460A8;
  dword_8662BC = dword_8460AC;
  Render::prevLightUsage = Render::curLightUsage;
  dword_86626C = dword_84605C[0];
  dword_8662C0 = dword_8460B0;
  LOBYTE(Render::curLightUsage) = 0;
  dword_84605C[0] = -1;
  dword_846060[0] = -1;
  LOBYTE(dword_846064) = 0;
  dword_846068 = -1;
  dword_84606C = -1;
  LOBYTE(dword_846070) = 0;
  dword_846074 = -1;
  dword_846078 = -1;
  LOBYTE(dword_84607C) = 0;
  dword_846080 = -1;
  dword_846084 = -1;
  LOBYTE(dword_846088) = 0;
  dword_84608C = -1;
  dword_846090 = -1;
  LOBYTE(dword_846094) = 0;
  dword_846098 = -1;
  dword_84609C = -1;
  LOBYTE(dword_8460A0) = 0;
  dword_8460A4 = -1;
  dword_8460A8 = -1;
  dword_8662C4 = dword_8460B4;
  LOBYTE(dword_8460AC) = 0;
  dword_8460B0 = -1;
  dword_8460B4 = -1;
}
// 846058: using guessed type struct HWLightUsage *Render::curLightUsage;
// 84605C: using guessed type int dword_84605C[];
// 846060: using guessed type int dword_846060[];
// 846064: using guessed type int dword_846064;
// 846068: using guessed type int dword_846068;
// 84606C: using guessed type int dword_84606C;
// 846070: using guessed type int dword_846070;
// 846074: using guessed type int dword_846074;
// 846078: using guessed type int dword_846078;
// 84607C: using guessed type int dword_84607C;
// 846080: using guessed type int dword_846080;
// 846084: using guessed type int dword_846084;
// 846088: using guessed type int dword_846088;
// 84608C: using guessed type int dword_84608C;
// 846090: using guessed type int dword_846090;
// 846094: using guessed type int dword_846094;
// 846098: using guessed type int dword_846098;
// 84609C: using guessed type int dword_84609C;
// 8460A0: using guessed type int dword_8460A0;
// 8460A4: using guessed type int dword_8460A4;
// 8460A8: using guessed type int dword_8460A8;
// 8460AC: using guessed type int dword_8460AC;
// 8460B0: using guessed type int dword_8460B0;
// 8460B4: using guessed type int dword_8460B4;
// 866268: using guessed type struct HWLightUsage *Render::prevLightUsage;
// 86626C: using guessed type int dword_86626C;
// 866270: using guessed type int dword_866270;
// 866274: using guessed type int dword_866274;
// 866278: using guessed type int dword_866278;
// 86627C: using guessed type int dword_86627C;
// 866280: using guessed type int dword_866280;
// 866284: using guessed type int dword_866284;
// 866288: using guessed type int dword_866288;
// 86628C: using guessed type int dword_86628C;
// 866290: using guessed type int dword_866290;
// 866294: using guessed type int dword_866294;
// 866298: using guessed type int dword_866298;
// 86629C: using guessed type int dword_86629C;
// 8662A0: using guessed type int dword_8662A0;
// 8662A4: using guessed type int dword_8662A4;
// 8662A8: using guessed type int dword_8662A8;
// 8662AC: using guessed type int dword_8662AC;
// 8662B0: using guessed type int dword_8662B0;
// 8662B4: using guessed type int dword_8662B4;
// 8662B8: using guessed type int dword_8662B8;
// 8662BC: using guessed type int dword_8662BC;
// 8662C0: using guessed type int dword_8662C0;
// 8662C4: using guessed type int dword_8662C4;

//----- (0054BFB0) --------------------------------------------------------  // acclient.c:379524
void __cdecl Render::add_active_light(int index, int lightClass)
{
  int v2; // ecx@1
  signed int v3; // eax@1
  int v4; // ecx@5
  signed int v5; // eax@5
  unsigned int v6; // ecx@9
  int v7; // esi@9
  int v8; // edx@10
  signed int v9; // eax@10
  unsigned int v10; // eax@14
  unsigned int v11; // eax@16

  v2 = 0;
  v3 = (signed int)&dword_866270;
  while ( *(_DWORD *)(v3 - 4) != lightClass || *(_DWORD *)v3 != index )
  {
    v3 += 12;
    ++v2;
    if ( v3 >= (signed int)&Render::bh )
    {
      v4 = 0;
      v5 = (signed int)dword_846060;
      while ( *(_DWORD *)v5 != -1 )
      {
        v5 += 12;
        ++v4;
        if ( v5 >= (signed int)&Render::xmax )
          return;
      }
      v11 = 12 * v4;
      dword_84605C[v11 / 4] = lightClass;
      dword_846060[v11 / 4] = index;
      LOBYTE((&Render::curLightUsage)[v11 / 0xC]) = 0;
      return;
    }
  }
  v6 = 12 * v2;
  v7 = dword_84605C[v6 / 4];
  if ( v7 != -1 )
  {
    v8 = 0;
    v9 = (signed int)dword_84605C;
    while ( *(_DWORD *)v9 != -1 )
    {
      v9 += 12;
      ++v8;
      if ( v9 >= (signed int)&Render::ymin )
        goto LABEL_15;
    }
    v10 = 12 * v8;
    dword_84605C[v10 / 4] = v7;
    LOBYTE((&Render::curLightUsage)[v10 / 0xC]) = 0;
    dword_846060[v10 / 4] = dword_846060[v6 / 4];
  }
LABEL_15:
  dword_84605C[v6 / 4] = lightClass;
  dword_846060[v6 / 4] = index;
  LOBYTE((&Render::curLightUsage)[v6 / 0xC]) = 1;
}
// 846058: using guessed type struct HWLightUsage *Render::curLightUsage;
// 84605C: using guessed type int dword_84605C[];
// 846060: using guessed type int dword_846060[];
// 8460BC: using guessed type float Render::ymin;
// 8460C0: using guessed type float Render::xmax;
// 866270: using guessed type int dword_866270;
// 8662D0: using guessed type double Render::bh;

//----- (0054C080) --------------------------------------------------------  // acclient.c:379593
void __cdecl Render::enable_active_lights()
{
  const unsigned int v0; // esi@1
  signed int v1; // edi@1
  int v2; // eax@2

  v0 = 0;
  v1 = (signed int)dword_84605C;
  do
  {
    v2 = *(_DWORD *)v1;
    if ( *(_DWORD *)v1 == -1 )
    {
      RenderDeviceD3D::SetFFLightEnable((RenderDeviceD3D *)RenderDevice::render_device, v0, 0);
    }
    else if ( lightCacheing && *(_BYTE *)(v1 - 4) )
    {
      RenderDeviceD3D::SetFFLightEnable((RenderDeviceD3D *)RenderDevice::render_device, v0, 1);
    }
    else if ( doDynamic && v2 == 2 )
    {
      (*(void (__stdcall **)(_DWORD, const unsigned int, RenderLight *))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                                       + 204))(
        LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
        v0,
        Render::world_lights.sorted_dynamic_lights[*(_DWORD *)(v1 + 4)]);
      RenderDeviceD3D::SetFFLightEnable((RenderDeviceD3D *)RenderDevice::render_device, v0, 1);
    }
    else if ( doStatic && v2 == 1 )
    {
      (*(void (__stdcall **)(_DWORD, const unsigned int, RenderLight *))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                                       + 204))(
        LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
        v0,
        Render::world_lights.sorted_static_lights[*(_DWORD *)(v1 + 4)]);
      RenderDeviceD3D::SetFFLightEnable((RenderDeviceD3D *)RenderDevice::render_device, v0, 1);
    }
    else if ( doSun )
    {
      if ( !v2 )
      {
        (*(void (__stdcall **)(_DWORD, const unsigned int, RenderLight *))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                                                         + 204))(
          LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
          v0,
          &Render::world_lights.m_Sunlight);
        RenderDeviceD3D::SetFFLightEnable((RenderDeviceD3D *)RenderDevice::render_device, v0, 1);
      }
    }
    v1 += 12;
    ++v0;
  }
  while ( v1 < (signed int)&Render::ymin );
}
// 84605C: using guessed type int dword_84605C[];
// 8460BC: using guessed type float Render::ymin;

//----- (0054C170) --------------------------------------------------------  // acclient.c:379651
void __cdecl Render::minimize_envcell_lighting()
{
  int v0; // ebx@1
  int v1; // esi@1

  Render::reset_active_lights_state();
  v0 = Render::world_lights.num_dynamic_lights;
  v1 = 0;
  if ( Render::world_lights.num_dynamic_lights > 0 )
  {
    memset32(&Render::dynamic_light_used, 1, Render::world_lights.num_dynamic_lights);
    do
      Render::add_active_light(v1++, 2);
    while ( v1 < v0 );
  }
  Render::enable_active_lights();
}
// 866238: using guessed type int *Render::dynamic_light_used;

//----- (0054C1B0) --------------------------------------------------------  // acclient.c:379671
int __cdecl Render::remove_object_light(LIGHTINFO *light_info)
{
  int result; // eax@2
  double v2; // st7@3
  double v3; // st6@3
  double v4; // st5@3
  double v5; // st4@3
  unsigned __int8 v7; // c0@3
  unsigned __int8 v8; // c2@3

  result = 0;
  if ( !light_info->type )
  {
    v2 = light_info->viewerspace_location.x - Render::local_object_center.x;
    v3 = light_info->viewerspace_location.y - flt_86B118;
    v4 = light_info->viewerspace_location.z - flt_86B11C;
    v5 = light_info->falloff + Render::local_object_radius;
    if ( !(v7 | v8) )
      result = 1;
  }
  return result;
}
// 866260: using guessed type float Render::local_object_radius;
// 86B114: using guessed type struct Vector3 Render::local_object_center;
// 86B118: using guessed type float flt_86B118;
// 86B11C: using guessed type float flt_86B11C;

//----- (0054C220) --------------------------------------------------------  // acclient.c:379699
void __cdecl Render::restore_all_lighting()
{
  if ( Render::world_lights.num_static_lights > 0 )
    memset32(&Render::static_light_used, 1, Render::world_lights.num_static_lights);
  if ( Render::world_lights.num_dynamic_lights > 0 )
    memset32(&Render::dynamic_light_used, 1, Render::world_lights.num_dynamic_lights);
}
// 8460C8: using guessed type int *Render::static_light_used;
// 866238: using guessed type int *Render::dynamic_light_used;

//----- (0054C250) --------------------------------------------------------  // acclient.c:379710
int __cdecl Render::viewconeCheck(CSphere *sphere)
{
  double v1; // st7@1
  double v2; // st6@1
  double v3; // st7@1
  double v4; // st7@1
  int result; // eax@2
  signed int v6; // esi@3
  int v7; // edx@3
  char *v8; // ecx@4
  double v9; // st7@5
  float neg_radius; // [sp+4h] [bp-1Ch]@1
  AC1Legacy::Vector3 global_center; // [sp+8h] [bp-18h]@1
  AC1Legacy::Vector3 v; // [sp+14h] [bp-Ch]@1
  float spherea; // [sp+24h] [bp+4h]@1

  v1 = Render::object_scale * sphere->center.x;
  v2 = Render::object_scale * sphere->center.y;
  global_center.z = Render::object_scale * sphere->center.z;
  v.z = global_center.z;
  v.x = v1;
  v.y = v2;
  Position::localtoglobal(&Render::viewer_pos, &global_center, (Position *)&Render::FrameCurrent[2].y, &v);
  v3 = Render::object_scale * sphere->radius;
  spherea = v3;
  neg_radius = -v3;
  Frame::globaltolocal(&stru_81EF08, &v, &global_center);
  Render::local_object_center = v.0;
  Render::local_object_radius = spherea;
  v4 = global_center.z * plane.N.z + global_center.y * plane.N.y + plane.N.x * global_center.x + plane.d;
  if ( v4 >= neg_radius )
  {
    v6 = v4 <= spherea;
    v7 = 0;
    if ( Render::portal_npnts <= 0 )
    {
LABEL_10:
      result = (v6 == 0) + 1;
    }
    else
    {
      v8 = (char *)&Render::portal_vertex->plane.N.y;
      while ( 1 )
      {
        v9 = global_center.z * *((float *)v8 + 1)
           + global_center.x * *((float *)v8 - 1)
           + global_center.y * *(float *)v8
           + *((float *)v8 + 2);
        if ( v9 < neg_radius )
          break;
        if ( v6 || v9 <= spherea )
          v6 = 1;
        ++v7;
        v8 += 24;
        if ( v7 >= Render::portal_npnts )
          goto LABEL_10;
      }
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 81EC74: using guessed type float Render::object_scale;
// 846040: using guessed type struct view_vertex *Render::portal_vertex;
// 846050: using guessed type int Render::portal_npnts;
// 866260: using guessed type float Render::local_object_radius;
// 86B114: using guessed type struct Vector3 Render::local_object_center;
// 86B118: using guessed type float flt_86B118;
// 86B11C: using guessed type float flt_86B11C;

//----- (0054C3C0) --------------------------------------------------------  // acclient.c:379785
int __cdecl Render::SetDegradeLevelInternal(float new_deg_mul)
{
  unsigned __int8 v2; // c0@1
  unsigned __int8 v3; // c2@1
  double v4; // st7@2
  double v5; // st6@2
  unsigned __int64 v6; // rax@2
  double v7; // st5@2
  int result; // eax@4

  Render::deg_mul = new_deg_mul;
  if ( v2 | v3 )
  {
    v4 = (25.0 - 8.0) * new_deg_mul + 25.0;
    v5 = (16.0 - 8.0) * new_deg_mul + 16.0;
    v6 = (unsigned __int64)(new_deg_mul * 20.0 + 40.0);
    v7 = new_deg_mul + new_deg_mul + 7.0;
  }
  else
  {
    v4 = 25.0 - (25.0 - 50.0) * new_deg_mul;
    v5 = 16.0 - (16.0 - 25.0) * new_deg_mul;
    v6 = (unsigned __int64)(40.0 - new_deg_mul * -20.0);
    v7 = 7.0 - new_deg_mul * -3.0;
  }
  Render::max_static_lights = v6;
  Render::max_dynamic_lights = (unsigned __int64)v7;
  result = 1;
  Render::object_distance_2dsq = v4 * v4;
  Render::particle_distance_2dsq = v5 * v5;
  return result;
}
// 86630C: using guessed type float Render::deg_mul;
// 866404: using guessed type float Render::object_distance_2dsq;
// 86B1F8: using guessed type float Render::particle_distance_2dsq;

//----- (0054C4B0) --------------------------------------------------------  // acclient.c:379822
char __cdecl Render::StartupRenderingSystem(RenderConfig *_config)
{
  D3DPolyRender *v1; // eax@3

  if ( Render::m_pRenderer )
    return 0;
  if ( _config->m_GraphicsDriver != 1 )
    return 0;
  v1 = (D3DPolyRender *)RenderAllocator::AllocateRender();
  Render::m_pRenderer = v1;
  if ( !v1 )
    return 0;
  if ( !(unsigned __int8)(*(int (__thiscall **)(D3DPolyRender *, RenderConfig *))&v1->vfptr->gap4[0])(v1, _config) )
  {
    if ( Render::m_pRenderer )
      ((void (__stdcall *)(_DWORD))Render::m_pRenderer->vfptr->__vecDelDtor)(1);
    Render::m_pRenderer = 0;
    return 0;
  }
  return 1;
}

//----- (0054C500) --------------------------------------------------------  // acclient.c:379845
char __cdecl Render::StartupDevice(const unsigned int _nDisplayAdapter, RenderDevicePresentation *_presentation, RenderDeviceConfig *_deviceConfig)
{
  RenderDevice *v3; // eax@1

  v3 = (RenderDevice *)((int (*)(void))Render::m_pRenderer->vfptr->CreateRenderDevice)();
  RenderDevice::render_device = v3;
  if ( !v3 )
    return 0;
  if ( !(unsigned __int8)(*(int (__thiscall **)(RenderDevice *, const unsigned int, RenderDevicePresentation *, RenderDeviceConfig *))&v3->vfptr->gap4[0])(
                           v3,
                           _nDisplayAdapter,
                           _presentation,
                           _deviceConfig) )
  {
    if ( RenderDevice::render_device )
      ((void (__stdcall *)(_DWORD))RenderDevice::render_device->vfptr->__vecDelDtor)(1);
    RenderDevice::render_device = 0;
    return 0;
  }
  return 1;
}

//----- (0054C550) --------------------------------------------------------  // acclient.c:379868
void __cdecl Render::ShutdownDevice()
{
  GraphicsResource::PurgeResources();
  if ( RenderDevice::render_device )
  {
    (*(void (**)(void))&RenderDevice::render_device->vfptr->gap4[4])();
    if ( RenderDevice::render_device )
      ((void (__stdcall *)(_DWORD))RenderDevice::render_device->vfptr->__vecDelDtor)(1);
  }
  RenderDevice::render_device = 0;
}

//----- (0054C580) --------------------------------------------------------  // acclient.c:379881
void __cdecl Render::ShutdownRenderingSystem()
{
  RenderUI::Shutdown();
  KeyStone::Release();
  GraphicsResource::PurgeResources();
  if ( RenderDevice::render_device )
  {
    (*(void (**)(void))&RenderDevice::render_device->vfptr->gap4[4])();
    if ( RenderDevice::render_device )
      ((void (__stdcall *)(_DWORD))RenderDevice::render_device->vfptr->__vecDelDtor)(1);
  }
  RenderDevice::render_device = 0;
  FontMapper::Shutdown();
  GraphicsResource::ShutdownResourceManager();
  (*(void (**)(void))&Render::m_pRenderer->vfptr->gap4[4])();
  if ( Render::m_pRenderer )
    ((void (__stdcall *)(_DWORD))Render::m_pRenderer->vfptr->__vecDelDtor)(1);
  Render::m_pRenderer = 0;
}

//----- (0054C5F0) --------------------------------------------------------  // acclient.c:379902
char __cdecl Render::RestartDevice(const unsigned int _nDisplayAdapter, RenderDevicePresentation *_presentation, RenderDeviceConfig *_deviceConfig)
{
  HWND__ *v3; // ebp@1
  int OldDeviceConfig_4; // [sp+14h] [bp-20h]@1
  RenderDevicePresentation OldDevicePresentation; // [sp+18h] [bp-1Ch]@1

  v3 = _deviceConfig->hFocusWindow;
  OldDeviceConfig_4 = *(_DWORD *)&_deviceConfig->bUseStencilBuffer;
  qmemcpy(&OldDevicePresentation, _presentation, sizeof(OldDevicePresentation));
  if ( RenderDevice::render_device )
  {
    qmemcpy(&OldDevicePresentation, &RenderDevice::render_device->m_presentation, sizeof(OldDevicePresentation));
    v3 = RenderDevice::render_device->m_config.hFocusWindow;
    OldDeviceConfig_4 = *(_DWORD *)&RenderDevice::render_device->m_config.bUseStencilBuffer;
  }
  if ( RenderDevice::render_device->vfptr->ResetDevice(RenderDevice::render_device, _presentation) )
    return 1;
  if ( (unsigned __int8)((int (__stdcall *)(RenderDevicePresentation *))RenderDevice::render_device->vfptr->ResetDevice)(&OldDevicePresentation) )
  {
    qmemcpy(_presentation, &OldDevicePresentation, 0x1Cu);
    _deviceConfig->hFocusWindow = v3;
    *(_DWORD *)&_deviceConfig->bUseStencilBuffer = OldDeviceConfig_4;
    return 1;
  }
  return 0;
}

//----- (0054C690) --------------------------------------------------------  // acclient.c:379930
int __cdecl Render::CreateIndexBuffer()
{
  int result; // eax@2
  RenderIndexBuffer *v1; // eax@3
  RenderIndexBuffer *v2; // esi@3

  if ( Render::m_pRenderer )
  {
    result = ((int (*)(void))RenderDevice::render_device->vfptr->CreateIndexBuffer)();
  }
  else
  {
    v1 = (RenderIndexBuffer *)operator new(0x28u);
    v2 = v1;
    if ( v1 )
    {
      v1->vfptr = (RenderIndexBufferVtbl *)&RenderIndexBuffer::vftable;
      RenderIndexBuffer::Begin(v1);
      result = (int)v2;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
// 79B26C: using guessed type int (__thiscall *RenderIndexBuffer::vftable)(void *, char);

//----- (0054C6D0) --------------------------------------------------------  // acclient.c:379960
void __cdecl Render::SafelyStopUsingAndReleaseTexture(RenderTexture **io_pTexture)
{
  if ( *io_pTexture )
  {
    ((void (*)(void))(*io_pTexture)->vfptr->Release)();
    *io_pTexture = 0;
  }
}

//----- (0054C6F0) --------------------------------------------------------  // acclient.c:379970
void __cdecl Render::GRPCallback_OnRenderPreferenceChanged()
{
  Render::m_CacheOverallGraphicsQuality = Render::DetermineOverallGraphicsQuality();
}
// 866340: using guessed type unsigned __int32 Render::m_CacheOverallGraphicsQuality;

//----- (0054C700) --------------------------------------------------------  // acclient.c:379977
BOOL __cdecl Render::ShouldDropHighDetail()
{
  return !(unsigned __int8)(*(int (__thiscall **)(AsyncCacheVtbl **, signed int, signed int))((int (__thiscall **)(_DWORD, _DWORD, _DWORD))&DBCache::s_pCache->vfptr->AreOnDisk
                                                                                            + 1))(
                             &DBCache::s_pCache->vfptr,
                             1766222152,
                             1)
      || dword_81EF9C;
}
// 81EF9C: using guessed type int dword_81EF9C;

//----- (0054C730) --------------------------------------------------------  // acclient.c:379989
double __cdecl Render::GetFramerate()
{
  return SceneTool::m_FramesPerSecond;
}
// 837418: using guessed type float SceneTool::m_FramesPerSecond;

//----- (0054C740) --------------------------------------------------------  // acclient.c:379996
bool __cdecl Render::GfxObjUnderSelectionRay(CGfxObj *mesh)
{
  CPhysicsPart *v1; // edi@3
  AC1Legacy::Vector3 *v2; // esi@4
  double v3; // st7@4
  double v4; // st6@4
  double v5; // st5@4
  long double v6; // st7@4
  CSphere *v7; // ecx@4
  unsigned int v8; // ebx@11
  int v9; // edi@12
  bool result; // al@15
  CPhysicsPart *pCurrentPart; // [sp+Ch] [bp-3Ch]@3
  long double fSphereCollisionDepth; // [sp+10h] [bp-38h]@4
  long double fPolygonCollisionDepth; // [sp+18h] [bp-30h]@4
  float v14; // [sp+20h] [bp-28h]@4
  Ray local_ray; // [sp+2Ch] [bp-1Ch]@4

  if ( Render::check_selection
    && Render::check_curr_object
    && (v1 = RenderDeviceD3D::s_current_physics_part, (pCurrentPart = RenderDeviceD3D::s_current_physics_part) != 0)
    && (v2 = Render::FrameCurrent,
        Frame::globaltolocalvec(
          (Frame *)&Render::FrameCurrent[3],
          (AC1Legacy::Vector3 *)&fPolygonCollisionDepth,
          &Render::selection_ray),
        v3 = v1->gfxobj_scale.z,
        v4 = v1->gfxobj_scale.y,
        v5 = v1->gfxobj_scale.x,
        local_ray.pt.x = v2->x,
        local_ray.pt.y = v2->y,
        local_ray.pt.z = v2->z,
        LODWORD(local_ray.length) = 1176256512,
        v6 = 1.0 / sqrt(v5 * v5 + v4 * v4 + v3 * v3),
        v14 = v14 * v6,
        local_ray.dir.z = v14,
        v7 = mesh->drawing_sphere,
        local_ray.dir.x = (float)fPolygonCollisionDepth * v6,
        local_ray.dir.y = *((float *)&fPolygonCollisionDepth + 1) * v6,
        CSphere::sphere_intersects_ray(v7, &local_ray, &fSphereCollisionDepth))
    && (!Render::m_MouseSelectData.bFoundPolygon || fSphereCollisionDepth <= dbl_86B198) )
  {
    if ( !byte_86B1A8 || fSphereCollisionDepth < dbl_86B1B0 )
    {
      byte_86B1A8 = 1;
      dbl_86B1B0 = fSphereCollisionDepth;
      dword_86B1B8 = CPhysicsPart::get_physobj_id(v1);
      dword_86B1BC = v1->physobj_index;
    }
    if ( Render::check_curr_object_polys )
    {
      v8 = 0;
      if ( mesh->num_polygons )
      {
        v9 = 0;
        while ( !CPolygon::polygon_hits_ray(&mesh->polygons[v9], &local_ray, &fPolygonCollisionDepth) )
        {
          ++v8;
          ++v9;
          if ( v8 >= mesh->num_polygons )
            return 1;
        }
        if ( !Render::m_MouseSelectData.bFoundPolygon || fPolygonCollisionDepth < dbl_86B198 )
        {
          Render::m_MouseSelectData.bFoundPolygon = 1;
          dbl_86B198 = fPolygonCollisionDepth;
          dword_86B1A0 = CPhysicsPart::get_physobj_id(pCurrentPart);
          dword_86B1A4 = pCurrentPart->physobj_index;
        }
      }
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 866338: using guessed type bool Render::check_curr_object;
// 866339: using guessed type bool Render::check_curr_object_polys;
// 86633A: using guessed type bool Render::check_selection;
// 86B190: using guessed type struct Render::MouseSelectData Render::m_MouseSelectData;
// 86B198: using guessed type double dbl_86B198;
// 86B1A0: using guessed type int dword_86B1A0;
// 86B1A4: using guessed type int dword_86B1A4;
// 86B1A8: using guessed type char byte_86B1A8;
// 86B1B0: using guessed type double dbl_86B1B0;
// 86B1B8: using guessed type int dword_86B1B8;
// 86B1BC: using guessed type int dword_86B1BC;

//----- (0054C950) --------------------------------------------------------  // acclient.c:380088
int __cdecl Render::GetMouseSelectionObjectID()
{
  int result; // eax@2

  if ( Render::m_MouseSelectData.bFoundPolygon )
    result = dword_86B1A0;
  else
    result = byte_86B1A8 != 0 ? dword_86B1B8 : 0;
  return result;
}
// 86B190: using guessed type struct Render::MouseSelectData Render::m_MouseSelectData;
// 86B1A0: using guessed type int dword_86B1A0;
// 86B1A8: using guessed type char byte_86B1A8;
// 86B1B8: using guessed type int dword_86B1B8;

//----- (0054C980) --------------------------------------------------------  // acclient.c:380104
int __cdecl Render::GetMouseSelectionPartIndex()
{
  int result; // eax@2

  if ( Render::m_MouseSelectData.bFoundPolygon )
    result = dword_86B1A4;
  else
    result = byte_86B1A8 != 0 ? dword_86B1BC : 0;
  return result;
}
// 86B190: using guessed type struct Render::MouseSelectData Render::m_MouseSelectData;
// 86B1A4: using guessed type int dword_86B1A4;
// 86B1A8: using guessed type char byte_86B1A8;
// 86B1BC: using guessed type int dword_86B1BC;

//----- (0054C9B0) --------------------------------------------------------  // acclient.c:380120
void __thiscall DArray<view_poly>::grow(DArray<view_poly> *this, unsigned int size)
{
  DArray<view_poly> *v2; // ebx@1
  unsigned int v3; // esi@1
  void *v4; // ebp@3
  unsigned int v5; // edx@3
  int v6; // eax@4

  v2 = this;
  v3 = size;
  if ( size > this->sizeOf )
  {
    v4 = operator new[](24 * size);
    v5 = 0;
    if ( v2->sizeOf )
    {
      v6 = 0;
      do
      {
        qmemcpy((char *)v4 + v6 * 24, &v2->data[v6], 0x18u);
        ++v5;
        ++v6;
      }
      while ( v5 < v2->sizeOf );
      v3 = size;
    }
    operator delete[](v2->data);
    v2->data = (view_poly *)v4;
    v2->sizeOf = v3;
  }
  else
  {
    DArray<view_poly>::shrink(this, size);
  }
}

//----- (0054CA20) --------------------------------------------------------  // acclient.c:380157
void view_vertex::view_vertex()
{
  DeleteLeafTransactInfo::DynamicCast_DeleteLeaf();
}

//----- (0054CA30) --------------------------------------------------------  // acclient.c:380163
void __thiscall DArray<view_poly>::shrink(DArray<view_poly> *this, unsigned int size)
{
  DArray<view_poly> *v2; // ebx@1
  unsigned int v3; // ebp@1
  view_poly *v4; // ST04_4@4
  void *v5; // eax@5
  unsigned int v6; // edx@5
  int v7; // eax@6
  unsigned int sizea; // [sp+Ch] [bp+4h]@5

  v2 = this;
  v3 = size;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v5 = operator new[](24 * size);
      v6 = 0;
      sizea = (unsigned int)v5;
      v2->sizeOf = v3;
      if ( v3 )
      {
        v7 = 0;
        do
        {
          qmemcpy((void *)(v7 * 24 + sizea), &v2->data[v7], 0x18u);
          ++v6;
          ++v7;
        }
        while ( v6 < v2->sizeOf );
      }
      operator delete[](v2->data);
      v2->data = (view_poly *)sizea;
    }
    else
    {
      v4 = this->data;
      this->sizeOf = 0;
      operator delete[](v4);
      v2->data = 0;
    }
    if ( v2->next_available > v3 )
      v2->next_available = v3;
  }
  else
  {
    DArray<view_poly>::grow(this, size);
  }
}

//----- (0054CAC0) --------------------------------------------------------  // acclient.c:380214
void __thiscall RenderLight::RenderLight(RenderLight *this)
{
  char *v1; // ecx@1

  v1 = (char *)&this->info.offset;
  *(_DWORD *)v1 = 1065353216;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = 0;
  *((_DWORD *)v1 + 13) = 0;
  *((_DWORD *)v1 + 14) = 0;
  *((_DWORD *)v1 + 15) = 0;
  Frame::cache((Frame *)v1);
}

//----- (0054CAF0) --------------------------------------------------------  // acclient.c:380230
void __cdecl Render::CalcDegLevel()
{
  double v0; // st7@3
  float v1; // ST14_4@3
  double v2; // st6@3
  double v3; // st5@3
  float v4; // ST10_4@5
  float plat_low; // ST24_4@9
  double v6; // st6@3
  long double v7; // st7@4
  float v8; // ST08_4@9
  long double v9; // st6@7
  long double v10; // st7@9
  long double v11; // st6@9
  long double v12; // st7@11
  long double v13; // st6@11
  long double v14; // st7@13
  long double v15; // st6@14
  long double v16; // st6@17
  signed int v17; // ecx@22
  float rulesum; // [sp+8h] [bp-2Ch]@9
  float rulesuma; // [sp+8h] [bp-2Ch]@11
  float rulesumb; // [sp+8h] [bp-2Ch]@13
  float new_deg_mul; // [sp+Ch] [bp-28h]@18
  float v22; // [sp+10h] [bp-24h]@7
  float high_high; // [sp+14h] [bp-20h]@3
  float medlow_high; // [sp+18h] [bp-1Ch]@3
  float plat_high; // [sp+20h] [bp-14h]@3
  float medhigh_low; // [sp+2Ch] [bp-8h]@3
  float high_low; // [sp+30h] [bp-4h]@3

  qmemcpy(&degmulhist, &unk_8661C4, 0x74u);
  if ( Render::auto_update_deg_mul )
  {
    v0 = Render::min_framerate * 0.75;
    v1 = Render::ideal_framerate * 0.75;
    medlow_high = Render::min_framerate * 0.25 + v1;
    v2 = Render::ideal_framerate * 0.5;
    v3 = Render::min_framerate * 0.5 + v2;
    v6 = v2 + Render::max_framerate * 0.5;
    plat_high = v6;
    medhigh_low = Render::max_framerate * 0.25 + v1;
    high_low = v6;
    high_high = Render::max_framerate * 1.25;
    if ( SceneTool::m_FramesPerSecond >= v0 )
    {
      v4 = v3;
      v7 = 1.0 - fabs(SceneTool::m_FramesPerSecond - v0) / (v4 - v0);
      if ( v7 < 0.0 )
        v7 = 0.0;
    }
    else
    {
      v7 = 1.0;
    }
    v22 = SceneTool::m_FramesPerSecond + SceneTool::m_FramesPerSecond;
    v9 = 1.0 - fabs(v22 - (medlow_high + Render::min_framerate)) / (medlow_high - Render::min_framerate);
    if ( v9 < 0.0 )
      v9 = 0.0;
    v8 = -0.15000001 * v7;
    rulesum = v8 - 0.02 * v9;
    v10 = v7 + v9;
    plat_low = v3;
    v11 = 1.0 - fabs(v22 - (plat_high + plat_low)) / (plat_high - plat_low);
    if ( v11 < 0.0 )
      v11 = 0.0;
    rulesuma = 0.0 * v11 + rulesum;
    v12 = v10 + v11;
    v13 = 1.0 - fabs(v22 - (Render::max_framerate + medhigh_low)) / (Render::max_framerate - medhigh_low);
    if ( v13 < 0.0 )
      v13 = 0.0;
    rulesumb = 0.0099999998 * v13 + rulesuma;
    v14 = v12 + v13;
    if ( SceneTool::m_FramesPerSecond <= (double)high_high )
    {
      v15 = 1.0 - fabs(SceneTool::m_FramesPerSecond - high_high) / (high_high - high_low);
      if ( v15 < 0.0 )
        v15 = 0.0;
    }
    else
    {
      v15 = 1.0;
    }
    v16 = (0.1 * v15 + rulesumb) / (v15 + v14) + Render::deg_mul;
    if ( v16 <= 1.0 )
    {
      if ( v16 >= -1.0 )
        new_deg_mul = v16;
      else
        new_deg_mul = -1.0;
    }
    else
    {
      new_deg_mul = 1.0;
    }
    v17 = (signed int)&degmulhist;
    while ( fabs(*(float *)v17 - new_deg_mul) >= 0.01 )
    {
      v17 += 4;
      if ( v17 >= (signed int)dword_866234 )
      {
        Render::SetDegradeLevelInternal(new_deg_mul);
        break;
      }
    }
    dword_866234[0] = LODWORD(Render::deg_mul);
  }
  else
  {
    dword_866234[0] = LODWORD(Render::deg_mul);
  }
}
// 81EC5C: using guessed type float Render::max_framerate;
// 81EC60: using guessed type float Render::min_framerate;
// 81EC64: using guessed type float Render::ideal_framerate;
// 81EC68: using guessed type bool Render::auto_update_deg_mul;
// 837418: using guessed type float SceneTool::m_FramesPerSecond;
// 866234: using guessed type int dword_866234[];
// 86630C: using guessed type float Render::deg_mul;

//----- (0054CDD0) --------------------------------------------------------  // acclient.c:380351
void __cdecl Render::update_viewpoint(Position *_viewer_pos)
{
  AC1Legacy::Vector3 *v1; // eax@2
  AC1Legacy::Vector3 in; // [sp+0h] [bp-58h]@1
  AC1Legacy::Vector3 p; // [sp+Ch] [bp-4Ch]@1
  Matrix4 vm; // [sp+18h] [bp-40h]@1

  dword_81EF04 = _viewer_pos->objcell_id;
  Frame::operator=((int)&stru_81EF08, (int)&_viewer_pos->frame);
  Render::Xaxis = *(struct Vector3 *)&stru_81EF08.m_fl2gv[0];
  Render::Yaxis = *(struct Vector3 *)&stru_81EF08.m_fl2gv[3];
  Render::Zaxis = *(struct Vector3 *)&stru_81EF08.m_fl2gv[6];
  plane.d = -(stru_81EF08.m_fOrigin.z * stru_81EF08.m_fl2gv[5]
            + stru_81EF08.m_fOrigin.y * stru_81EF08.m_fl2gv[4]
            + stru_81EF08.m_fOrigin.x * stru_81EF08.m_fl2gv[3])
          - Render::znear;
  Render::viewer_world_space.viewpoint.x = stru_81EF08.m_fOrigin.x;
  dword_866410 = LODWORD(stru_81EF08.m_fOrigin.y);
  dword_866414 = LODWORD(stru_81EF08.m_fOrigin.z);
  plane.N.x = stru_81EF08.m_fl2gv[3];
  plane.N.y = stru_81EF08.m_fl2gv[4];
  plane.N.z = stru_81EF08.m_fl2gv[5];
  LODWORD(in.x) = 0;
  LODWORD(in.y) = 0;
  LODWORD(in.z) = 0;
  Frame::globaltolocal(&stru_81EF08, &p, &in);
  LODWORD(vm._11) = (_DWORD)Render::Xaxis.x;
  vm._21 = flt_86B1C8;
  vm._31 = flt_86B1C4;
  LODWORD(vm._41) = (_DWORD)p.x;
  LODWORD(vm._12) = (_DWORD)Render::Zaxis.x;
  vm._22 = flt_866430;
  vm._32 = flt_86642C;
  vm._42 = p.z;
  LODWORD(vm._13) = (_DWORD)Render::Yaxis.x;
  vm._23 = flt_86B184;
  vm._33 = flt_86B180;
  vm._43 = p.y;
  LODWORD(vm._14) = 0;
  LODWORD(vm._24) = 0;
  LODWORD(vm._34) = 0;
  LODWORD(vm._44) = 1065353216;
  RenderDeviceD3D::SetWorldToViewMatrix((RenderDeviceD3D *)RenderDevice::render_device, &vm);
  ((void (*)(void))Render::m_pRenderer->vfptr->UpdateLightsInternal)();
  if ( Render::check_selection )
  {
    v1 = Render::pick_ray(&p, Render::selection_x, Render::selection_y);
    Render::selection_ray.x = v1->x;
    Render::selection_ray.y = v1->y;
    Render::selection_ray.z = v1->z;
  }
}
// 86633A: using guessed type bool Render::check_selection;
// 86640C: using guessed type struct DrawParms Render::viewer_world_space;
// 866410: using guessed type int dword_866410;
// 866414: using guessed type int dword_866414;
// 866428: using guessed type struct Vector3 Render::Zaxis;
// 86642C: using guessed type float flt_86642C;
// 866430: using guessed type float flt_866430;
// 86B17C: using guessed type struct Vector3 Render::Yaxis;
// 86B180: using guessed type float flt_86B180;
// 86B184: using guessed type float flt_86B184;
// 86B1C0: using guessed type struct Vector3 Render::Xaxis;
// 86B1C4: using guessed type float flt_86B1C4;
// 86B1C8: using guessed type float flt_86B1C8;

//----- (0054CFF0) --------------------------------------------------------  // acclient.c:380418
void __cdecl Render::get_clip_height(float x, float y, ViewIntervalType *vint)
{
  signed int v3; // esi@1
  signed int v4; // edi@2

  vint->bound[0] = Render::get_pt_limit(x, y, &plane);
  v3 = 1;
  if ( Render::portal_npnts >= 1 )
  {
    v4 = 1;
    do
    {
      vint->bound[v3++] = Render::get_pt_limit(x, y, (Plane *)&Render::portal_vertex[v4] - 1);
      ++v4;
    }
    while ( v3 <= Render::portal_npnts );
  }
}
// 846040: using guessed type struct view_vertex *Render::portal_vertex;
// 846050: using guessed type int Render::portal_npnts;

//----- (0054D060) --------------------------------------------------------  // acclient.c:380440
signed int __cdecl Render::block_plane_check(float corner1, float corner2, float corner3, float corner4, float min, float max)
{
  signed int v6; // esi@1
  float v7; // edx@1
  float v8; // ecx@1
  signed int v9; // edi@1
  float v10; // edx@1
  float v11; // ecx@1
  signed int v12; // ebx@1
  float v13; // edx@1
  float v14; // ecx@1
  signed int result; // eax@1
  bool v16; // zf@9

  v6 = Render::corner_plane_check(corner1, min, max);
  v9 = Render::corner_plane_check(corner2, v7, v8);
  v12 = Render::corner_plane_check(corner3, v10, v11);
  result = Render::corner_plane_check(corner4, v13, v14);
  if ( !v6 )
  {
    if ( !v9 && !v12 && !result )
      return result;
    return 1;
  }
  if ( v6 != 2 )
    return 1;
  if ( v9 != 2 )
    return 1;
  if ( v12 != 2 )
    return 1;
  v16 = result == 2;
  result = 2;
  if ( !v16 )
    return 1;
  return result;
}

//----- (0054D0E0) --------------------------------------------------------  // acclient.c:380478
void __cdecl Render::set_view(view_type *view, int view_num)
{
  view_poly *v2; // eax@1

  Render::portal_view_num = view_num;
  Render::portal_view = view;
  v2 = &view->poly.data[view_num];
  Render::portal_npnts = v2->vertex_count;
  Render::portal_inmask = (1 << (Render::portal_npnts + 1)) - 1;
  Render::portal_vertex = &view->vertex.data[v2->vertex_index];
  Render::xmin = v2->xmin;
  Render::xmax = v2->xmax;
  Render::ymin = v2->ymin;
  Render::ymax = v2->ymax;
}
// 846040: using guessed type struct view_vertex *Render::portal_vertex;
// 846044: using guessed type struct view_type *Render::portal_view;
// 846050: using guessed type int Render::portal_npnts;
// 8460BC: using guessed type float Render::ymin;
// 8460C0: using guessed type float Render::xmax;
// 8661B8: using guessed type int Render::portal_inmask;
// 8662DC: using guessed type int Render::portal_view_num;
// 8662F0: using guessed type float Render::ymax;
// 8662F4: using guessed type float Render::xmin;

//----- (0054D150) --------------------------------------------------------  // acclient.c:380504
void __cdecl Render::framePush(const int op, Frame *frame)
{
  Position p; // [sp+0h] [bp-48h]@2

  if ( frame )
  {
    p.vfptr = (PackObjVtbl *)&Position::vftable;
    p.objcell_id = 0;
    Frame::operator=((int)&p.frame, (int)frame);
    ((void (__stdcall *)(_DWORD, _DWORD))Render::m_pRenderer->vfptr->positionPushInternal)(op, &p);
  }
  else
  {
    ((void (__stdcall *)(_DWORD, _DWORD))Render::m_pRenderer->vfptr->positionPushInternal)(op, 0);
  }
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (0054D1B0) --------------------------------------------------------  // acclient.c:380523
void __cdecl Render::insert_light(int max_lights, int *num_lights, RenderLight *lights, RenderLight **sorted_lights, LIGHTINFO *light_info, const unsigned int cell_id, Frame *frame, int offset)
{
  Frame *v8; // edi@1
  double v9; // st7@2
  double v10; // st6@2
  int v11; // ebp@3
  int v12; // edx@4
  RenderLight *v13; // ebp@11
  int v14; // eax@11
  RenderLight *v15; // edi@12
  RenderLight *v16; // esi@15
  unsigned int v17; // edi@15
  double v18; // st7@15
  int v19; // edx@15
  float distancesq; // [sp+10h] [bp-1Ch]@1
  AC1Legacy::Vector3 result; // [sp+14h] [bp-18h]@2
  float v22; // [sp+28h] [bp-4h]@2

  v8 = frame;
  distancesq = 0.0;
  if ( !light_info->type )
  {
    LandDefs::get_block_offset(&result, cell_from, cell_id);
    v9 = result.x + frame->m_fOrigin.x;
    v10 = result.y + frame->m_fOrigin.y;
    v22 = result.z + frame->m_fOrigin.z;
    result.x = v9 - stru_81EF50.m_fOrigin.x;
    distancesq = (v22 - stru_81EF50.m_fOrigin.z) * (v22 - stru_81EF50.m_fOrigin.z)
               + (v10 - stru_81EF50.m_fOrigin.y) * (v10 - stru_81EF50.m_fOrigin.y)
               + result.x * result.x;
  }
  v11 = *num_lights;
  if ( *num_lights )
  {
    v12 = 0;
    if ( v11 > 0 )
    {
      do
      {
        if ( distancesq < (double)sorted_lights[v12]->distancesq )
          break;
        ++v12;
      }
      while ( v12 < *num_lights );
    }
    if ( v11 == max_lights )
    {
      if ( v12 == v11 )
        return;
    }
    else
    {
      *num_lights = v11 + 1;
    }
    v13 = sorted_lights[v12];
    sorted_lights[v12] = sorted_lights[*num_lights - 1];
    v14 = v12 + 1;
    if ( v12 + 1 < *num_lights )
    {
      do
      {
        v15 = sorted_lights[v14];
        sorted_lights[v14] = v13;
        v13 = v15;
        ++v14;
      }
      while ( v14 < *num_lights );
      v8 = frame;
    }
  }
  else
  {
    v12 = 0;
    *num_lights = 1;
  }
  v16 = sorted_lights[v12];
  v16->info.type = light_info->type;
  Frame::combine(&v16->info.offset, v8, &light_info->offset);
  v17 = (unsigned __int64)(light_info->color.b * 255.0) | (((unsigned int)(unsigned __int64)(light_info->color.g * 255.0) | (((unsigned __int8)(unsigned __int64)(light_info->color.r * 255.0) | 0xFFFFFF00) << 8)) << 8);
  v16->info.color.r = (double)((v17 >> 16) & 0xFF) * 0.0039215689;
  v16->info.color.g = (double)((unsigned __int16)v17 >> 8) * 0.0039215689;
  v16->info.color.b = (double)(unsigned __int8)v17 * 0.0039215689;
  v16->info.intensity = light_info->intensity;
  v16->info.falloff = light_info->falloff;
  v18 = light_info->cone_angle;
  v16->distancesq = distancesq;
  v19 = offset + v16 - lights;
  v16->info.cone_angle = v18;
  v16->cellID = cell_id;
  v16->d3dLightIndex = v19;
  PrimD3DRender::config_hardware_light(v19, &v16->d3dLight, cell_id, &v16->info);
}

//----- (0054D3E0) --------------------------------------------------------  // acclient.c:380617
void __cdecl Render::add_static_light(LIGHTINFO *light_info, const unsigned int cell_id, Frame *frame)
{
  Render::insert_light(
    Render::max_static_lights,
    &Render::world_lights.num_static_lights,
    Render::world_lights.static_lights,
    Render::world_lights.sorted_static_lights,
    light_info,
    cell_id,
    frame,
    Render::max_dynamic_lights + 1);
}

//----- (0054D420) --------------------------------------------------------  // acclient.c:380631
void __cdecl Render::add_dynamic_light(LIGHTINFO *light_info, const unsigned int cell_id, Frame *frame)
{
  Render::insert_light(
    Render::max_dynamic_lights,
    &Render::world_lights.num_dynamic_lights,
    Render::world_lights.dynamic_lights,
    Render::world_lights.sorted_dynamic_lights,
    light_info,
    cell_id,
    frame,
    1);
}

//----- (0054D450) --------------------------------------------------------  // acclient.c:380645
void __cdecl Render::useSunlightSet(int use_sunlight)
{
  Render::useSunlight = use_sunlight;
  Render::reset_active_lights_state();
  if ( use_sunlight )
  {
    Render::add_active_light(-1, 0);
    Render::enable_active_lights();
  }
}
// 866334: using guessed type int Render::useSunlight;

//----- (0054D480) --------------------------------------------------------  // acclient.c:380658
void __cdecl Render::minimize_object_lighting()
{
  signed int v0; // edi@1
  int v1; // ebx@1
  int i; // esi@1
  int v3; // ebx@7
  int j; // esi@7
  double v5; // st7@10
  double v6; // st6@10
  double v7; // st5@10
  double v8; // st4@10
  unsigned __int8 v10; // c0@10
  unsigned __int8 v11; // c2@10

  v0 = 0;
  Render::reset_active_lights_state();
  v1 = Render::world_lights.num_dynamic_lights;
  for ( i = 0; i < v1; ++i )
  {
    if ( v0 >= 8 || Render::remove_object_light(&Render::world_lights.sorted_dynamic_lights[i]->info) )
    {
      (&Render::dynamic_light_used)[i] = 0;
    }
    else
    {
      (&Render::dynamic_light_used)[i] = (int *)1;
      Render::add_active_light(i, 2);
      ++v0;
    }
  }
  v3 = Render::world_lights.num_static_lights;
  for ( j = 0; j < v3; ++j )
  {
    if ( v0 < 8
      && (Render::world_lights.sorted_static_lights[j]->info.type
       || (v5 = Render::world_lights.sorted_static_lights[j]->info.viewerspace_location.x
              - Render::local_object_center.x,
           v6 = Render::world_lights.sorted_static_lights[j]->info.viewerspace_location.y - flt_86B118,
           v7 = Render::world_lights.sorted_static_lights[j]->info.viewerspace_location.z - flt_86B11C,
           v8 = Render::world_lights.sorted_static_lights[j]->info.falloff + Render::local_object_radius,
           v10 | v11)) )
    {
      (&Render::static_light_used)[j] = (int *)1;
      Render::add_active_light(j, 1);
      ++v0;
    }
    else
    {
      (&Render::static_light_used)[j] = 0;
    }
  }
  Render::enable_active_lights();
}
// 8460C8: using guessed type int *Render::static_light_used;
// 866238: using guessed type int *Render::dynamic_light_used;
// 866260: using guessed type float Render::local_object_radius;
// 86B114: using guessed type struct Vector3 Render::local_object_center;
// 86B118: using guessed type float flt_86B118;
// 86B11C: using guessed type float flt_86B11C;

//----- (0054D590) --------------------------------------------------------  // acclient.c:380719
char __cdecl Render::StartupRenderingDevice(RenderDevicePresentation *_presentation, RenderDeviceConfig *_deviceConfig)
{
  if ( !DBObj::InitLoad() )
    return 0;
  if ( !FontMapper::Startup() )
  {
    GraphicsResource::PurgeResources();
    if ( RenderDevice::render_device )
    {
      (*(void (**)(void))&RenderDevice::render_device->vfptr->gap4[4])();
      if ( RenderDevice::render_device )
        ((void (__stdcall *)(_DWORD))RenderDevice::render_device->vfptr->__vecDelDtor)(1);
    }
    RenderDevice::render_device = 0;
    goto LABEL_10;
  }
  if ( !Render::StartupDevice(Render::m_pRenderer->m_nDisplayAdapter, _presentation, _deviceConfig) )
  {
LABEL_10:
    if ( Render::m_pRenderer )
    {
      (*(void (**)(void))&Render::m_pRenderer->vfptr->gap4[4])();
      if ( Render::m_pRenderer )
        ((void (__stdcall *)(_DWORD))Render::m_pRenderer->vfptr->__vecDelDtor)(1);
      Render::m_pRenderer = 0;
    }
    return 0;
  }
  KeyStone::Create();
  if ( !RenderUI::Startup() )
  {
    KeyStone::Release();
    FontMapper::Shutdown();
    Render::ShutdownDevice();
    goto LABEL_10;
  }
  return 1;
}

//----- (0054D650) --------------------------------------------------------  // acclient.c:380759
char __cdecl Render::FlushGraphicsResources()
{
  unsigned int v0; // esi@2
  unsigned int v1; // esi@4
  void (*v2)(void); // eax@5
  char result; // al@8

  if ( Render::m_pRenderer )
  {
    v0 = 0;
    do
      RenderDeviceD3D::SetStageTexture((RenderDeviceD3D *)RenderDevice::render_device, v0++, 0);
    while ( v0 < 8 );
    GraphicsResource::PurgeResources();
    GraphicsResource::RestoreLostResources();
    v1 = 0;
    if ( Render::m_RGRCallbacks.m_num )
    {
      do
      {
        v2 = (void (*)(void))Render::m_RGRCallbacks.m_data[v1];
        if ( v2 )
          v2();
        ++v1;
      }
      while ( v1 < Render::m_RGRCallbacks.m_num );
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0054D6B0) --------------------------------------------------------  // acclient.c:380796
char __cdecl Render::RestartRenderingSystem(RenderDevicePresentation *_presentation, RenderDeviceConfig *_config)
{
  unsigned int v2; // esi@3
  void (*v3)(void); // eax@4
  char result; // al@7

  if ( Render::m_pRenderer && Render::RestartDevice(Render::m_pRenderer->m_nDisplayAdapter, _presentation, _config) )
  {
    GraphicsResource::RestoreLostResources();
    v2 = 0;
    if ( Render::m_RGRCallbacks.m_num )
    {
      do
      {
        v3 = (void (*)(void))Render::m_RGRCallbacks.m_data[v2];
        if ( v3 )
          v3();
        ++v2;
      }
      while ( v2 < Render::m_RGRCallbacks.m_num );
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0054D710) --------------------------------------------------------  // acclient.c:380827
char __cdecl Render::RestartRenderingSystem()
{
  int v0; // edx@2
  char result; // al@2
  RenderDeviceConfig config; // [sp+0h] [bp-24h]@2
  RenderDevicePresentation presentation; // [sp+8h] [bp-1Ch]@2

  if ( Render::m_pRenderer )
  {
    qmemcpy(&presentation, &RenderDevice::render_device->m_presentation, sizeof(presentation));
    v0 = *(_DWORD *)&RenderDevice::render_device->m_config.bUseStencilBuffer;
    config.hFocusWindow = RenderDevice::render_device->m_config.hFocusWindow;
    *(_DWORD *)&config.bUseStencilBuffer = v0;
    result = Render::RestartRenderingSystem(&presentation, &config);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0054D760) --------------------------------------------------------  // acclient.c:380850
void __cdecl Render::UnlinkRGRCallback(bool (__cdecl *_RGRCallback)())
{
  unsigned int v1; // eax@1

  v1 = 0;
  if ( Render::m_RGRCallbacks.m_num )
  {
    while ( Render::m_RGRCallbacks.m_data[v1] != _RGRCallback )
    {
      ++v1;
      if ( v1 >= Render::m_RGRCallbacks.m_num )
        return;
    }
    if ( v1 != -1 )
      SmartArray<UIElement *,1>::RemoveUnOrdered(&Render::m_RGRCallbacks, &_RGRCallback);
  }
}

//----- (0054D7A0) --------------------------------------------------------  // acclient.c:380869
void __thiscall LightParms::LightParms(LightParms *this)
{
  LightParms *v1; // ebp@1
  char *v2; // ecx@1
  int v3; // esi@1
  signed int v4; // ebx@1
  int v5; // esi@3
  signed int v6; // ebx@3

  v1 = this;
  v2 = (char *)&this->m_Sunlight.info.offset;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  v3 = (int)&v1->static_lights[0].info.offset.m_fOrigin.z;
  v4 = 60;
  do
  {
    *(_DWORD *)(v3 - 60) = 1065353216;
    *(_DWORD *)(v3 - 56) = 0;
    *(_DWORD *)(v3 - 52) = 0;
    *(_DWORD *)(v3 - 48) = 0;
    *(_DWORD *)(v3 - 8) = 0;
    *(_DWORD *)(v3 - 4) = 0;
    *(_DWORD *)v3 = 0;
    Frame::cache((Frame *)(v3 - 60));
    v3 += 220;
    --v4;
  }
  while ( v4 );
  v5 = (int)&v1->dynamic_lights[0].info.offset.m_fOrigin.z;
  v6 = 10;
  do
  {
    *(_DWORD *)(v5 - 60) = 1065353216;
    *(_DWORD *)(v5 - 56) = 0;
    *(_DWORD *)(v5 - 52) = 0;
    *(_DWORD *)(v5 - 48) = 0;
    *(_DWORD *)(v5 - 8) = 0;
    *(_DWORD *)(v5 - 4) = 0;
    *(_DWORD *)v5 = 0;
    Frame::cache((Frame *)(v5 - 60));
    v5 += 220;
    --v6;
  }
  while ( v6 );
}

//----- (0054D850) --------------------------------------------------------  // acclient.c:380923
void __cdecl Render::UpdateFromPreferences()
{
  char v0; // bl@2
  int v1; // eax@15
  int v2; // eax@20
  double v3; // st7@27
  bool bNeedReloadTextures; // [sp+3h] [bp-5h]@2
  bool bNeedRefreshDetailTextures; // [sp+4h] [bp-4h]@2
  bool bNeedGammaChange; // [sp+5h] [bp-3h]@2
  bool bNeedRefreshLandscape; // [sp+6h] [bp-2h]@2
  bool bNeedNewAspectRatio; // [sp+7h] [bp-1h]@2

  if ( !RenderDevice::render_device )
    return;
  v0 = 0;
  bNeedReloadTextures = 0;
  bNeedGammaChange = 0;
  bNeedRefreshLandscape = 0;
  bNeedRefreshDetailTextures = 0;
  bNeedNewAspectRatio = 0;
  if ( Device::m_bIsInitialized )
  {
    if ( Current_Display_Resolution != Device::m_DisplayPrefs.Resolution )
    {
      v0 = 1;
      Current_Display_Resolution = Device::m_DisplayPrefs.Resolution;
    }
    if ( Current_Display_FullScreen != byte_817B68 )
    {
      v0 = 1;
      Current_Display_FullScreen = byte_817B68;
    }
    if ( Current_Display_RefreshRate != dword_817B6C )
    {
      v0 = 1;
      Current_Display_RefreshRate = dword_817B6C;
    }
    if ( Current_Display_SyncToRefresh != byte_817B71 )
    {
      v0 = 1;
      Current_Display_SyncToRefresh = byte_817B71;
    }
    if ( Current_Display_Antialiasing != byte_817B72 )
    {
      v0 = 1;
      Current_Display_Antialiasing = byte_817B72;
    }
  }
  if ( Current_Render_LandscapeTextureDetail != dword_81EF98 )
  {
    bNeedReloadTextures = 1;
    Current_Render_LandscapeTextureDetail = dword_81EF98;
    if ( dword_81EF98 )
      v1 = dword_81EF98 - 1;
    else
      v1 = 0;
    ImgTex::fLandTextureScale = v1;
  }
  if ( Current_Render_EnvironmentTextureDetail != dword_81EF9C )
  {
    bNeedReloadTextures = 1;
    Current_Render_EnvironmentTextureDetail = dword_81EF9C;
    if ( dword_81EF9C )
      v2 = dword_81EF9C - 1;
    else
      v2 = 0;
    ImgTex::fClipmapTextureScale = v2;
    ImgTex::fRGBATextureScale = v2;
    ImgTex::fIndexedTextureScale = v2;
  }
  if ( Current_Render_ScreenBrightness != fBrightness )
  {
    bNeedGammaChange = 1;
    Current_Render_ScreenBrightness = fBrightness;
  }
  if ( Current_Render_AspectRatio != dword_81EFA8 )
  {
    bNeedNewAspectRatio = 1;
    Current_Render_AspectRatio = dword_81EFA8;
  }
  v3 = Current_Render_FieldOfView;
  if ( Current_Render_FieldOfView != degrees )
  {
    Current_Render_FieldOfView = degrees;
    SmartBox::SetDefaultFov(SmartBox::smartbox, degrees);
  }
  if ( SmartBox::smartbox )
  {
    if ( Current_Render_LandscapeDrawDistance != mid_radius )
    {
      bNeedRefreshLandscape = 1;
      Current_Render_LandscapeDrawDistance = mid_radius;
    }
    if ( Current_Render_LandscapeDetailTextures )
    {
      bNeedRefreshDetailTextures = 1;
      Current_Render_LandscapeDetailTextures = 0;
    }
    if ( Current_Render_EnvironmentDetailTextures != byte_81EF95 )
    {
      Current_Render_EnvironmentDetailTextures = byte_81EF95;
LABEL_37:
      SmartBox::SetDetailTexturing(SmartBox::smartbox, 0, byte_81EF95);
      goto LABEL_38;
    }
    if ( bNeedRefreshDetailTextures )
      goto LABEL_37;
  }
LABEL_38:
  if ( bNeedGammaChange )
    RenderDeviceD3D::SetGamma((RenderDeviceD3D *)RenderDevice::render_device, fBrightness, 0);
  if ( !IsFirstTime )
  {
    if ( Device::m_bIsInitialized && v0 )
      Device::ChangePresentation();
    if ( bNeedRefreshLandscape )
      SmartBox::set_mid_radius(SmartBox::smartbox, v3, mid_radius);
    if ( bNeedReloadTextures && (!Device::m_bIsInitialized || !v0) )
      Render::FlushGraphicsResources();
    if ( bNeedNewAspectRatio )
      RenderDeviceD3D::SetupDisplayAspectRatio((RenderDeviceD3D *)RenderDevice::render_device);
  }
  IsFirstTime = 0;
}
// 817B64: using guessed type struct DisplayPrefs Device::m_DisplayPrefs;
// 817B68: using guessed type char byte_817B68;
// 817B6C: using guessed type int dword_817B6C;
// 817B71: using guessed type char byte_817B71;
// 817B72: using guessed type char byte_817B72;
// 81EF95: using guessed type char byte_81EF95;
// 81EF98: using guessed type int dword_81EF98;
// 81EF9C: using guessed type int dword_81EF9C;
// 81EFA8: using guessed type int dword_81EFA8;
// 837196: using guessed type bool Device::m_bIsInitialized;
// 845764: using guessed type enum ImageScaleType ImgTex::fLandTextureScale;
// 845768: using guessed type enum ImageScaleType ImgTex::fClipmapTextureScale;
// 84576C: using guessed type enum ImageScaleType ImgTex::fRGBATextureScale;
// 845770: using guessed type enum ImageScaleType ImgTex::fIndexedTextureScale;

//----- (0054DA90) --------------------------------------------------------  // acclient.c:381063
int __cdecl Render::Init()
{
  int result; // eax@2
  signed int v1; // eax@3
  int v2; // ecx@3
  signed int v3; // eax@5

  if ( ((int (*)(void))Render::m_pRenderer->vfptr->InitInternal)() )
  {
    v1 = 0;
    v2 = 0;
    do
    {
      Render::world_lights.sorted_static_lights[v2] = &Render::world_lights.static_lights[v1];
      Render::viewer_lights.sorted_static_lights[v2] = &Render::viewer_lights.static_lights[v1];
      ++v1;
      ++v2;
    }
    while ( v1 < 60 );
    Render::world_lights.sorted_dynamic_lights[0] = Render::world_lights.dynamic_lights;
    Render::viewer_lights.sorted_dynamic_lights[0] = Render::viewer_lights.dynamic_lights;
    Render::world_lights.sorted_dynamic_lights[1] = &Render::world_lights.dynamic_lights[1];
    Render::viewer_lights.sorted_dynamic_lights[1] = &Render::viewer_lights.dynamic_lights[1];
    Render::world_lights.sorted_dynamic_lights[2] = &Render::world_lights.dynamic_lights[2];
    Render::viewer_lights.sorted_dynamic_lights[2] = &Render::viewer_lights.dynamic_lights[2];
    Render::world_lights.sorted_dynamic_lights[3] = &Render::world_lights.dynamic_lights[3];
    Render::viewer_lights.sorted_dynamic_lights[3] = &Render::viewer_lights.dynamic_lights[3];
    Render::world_lights.sorted_dynamic_lights[4] = &Render::world_lights.dynamic_lights[4];
    Render::viewer_lights.sorted_dynamic_lights[4] = &Render::viewer_lights.dynamic_lights[4];
    Render::world_lights.sorted_dynamic_lights[5] = &Render::world_lights.dynamic_lights[5];
    Render::viewer_lights.sorted_dynamic_lights[5] = &Render::viewer_lights.dynamic_lights[5];
    Render::world_lights.sorted_dynamic_lights[6] = &Render::world_lights.dynamic_lights[6];
    Render::viewer_lights.sorted_dynamic_lights[6] = &Render::viewer_lights.dynamic_lights[6];
    Render::world_lights.sorted_dynamic_lights[7] = &Render::world_lights.dynamic_lights[7];
    Render::viewer_lights.sorted_dynamic_lights[7] = &Render::viewer_lights.dynamic_lights[7];
    Render::world_lights.sorted_dynamic_lights[8] = &Render::world_lights.dynamic_lights[8];
    Render::viewer_lights.sorted_dynamic_lights[8] = &Render::viewer_lights.dynamic_lights[8];
    Render::world_lights.sorted_dynamic_lights[9] = &Render::world_lights.dynamic_lights[9];
    Render::viewer_lights.sorted_dynamic_lights[9] = &Render::viewer_lights.dynamic_lights[9];
    Render::PolyNext = (struct polyListEntry *)&Render::PolyList;
    v3 = (signed int)&unk_867268;
    do
    {
      *(_DWORD *)v3 = 0;
      v3 -= 360;
    }
    while ( v3 >= (signed int)&unk_8665C0 );
    simple_clip_plane_list.cplane_num = 1;
    DArray<ClipPlane>::grow(&simple_clip_plane_list.cplane_list, 1u);
    simple_clip_plane_list.cplane_list.data->plane = 0;
    simple_clip_plane_list.cplane_list.data->side = 0;
    Render::world_lights.num_static_lights = 0;
    Render::world_lights.num_dynamic_lights = 0;
    DBObj::InitLoad();
    InitState = 1;
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}
// 8662D8: using guessed type struct polyListEntry *Render::PolyNext;

//----- (0054DC20) --------------------------------------------------------  // acclient.c:381129
void __cdecl Render::update_viewpoint(Frame *_viewer_frame)
{
  Position p; // [sp+0h] [bp-48h]@1

  p.vfptr = (PackObjVtbl *)&Position::vftable;
  p.objcell_id = 0;
  Frame::operator=((int)&p.frame, (int)_viewer_frame);
  Render::update_viewpoint(&p);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (0054DC50) --------------------------------------------------------  // acclient.c:381141
signed int __cdecl Render::block_check(ViewIntervalType *corner1, ViewIntervalType *corner2, ViewIntervalType *corner3, ViewIntervalType *corner4, float max_height, float min_height)
{
  signed int result; // eax@1
  signed int v7; // eax@3
  float *v8; // esi@3
  signed int v9; // eax@5
  int iq; // [sp+Ch] [bp-Ch]@2
  BoundingType bnd; // [sp+10h] [bp-8h]@1

  result = Render::block_plane_check(
             corner1->bound[0],
             corner2->bound[0],
             corner3->bound[0],
             corner4->bound[0],
             min_height,
             max_height);
  bnd = result;
  if ( result )
  {
    iq = 1;
    if ( Render::portal_npnts >= 1 )
    {
      v7 = (char *)corner1 - (char *)corner3;
      v8 = &corner3->bound[1];
      while ( 1 )
      {
        v9 = Render::block_plane_check(
               *(float *)((char *)v8 + v7),
               *(float *)((char *)v8 + (char *)corner2 - (char *)corner3),
               *v8,
               *(float *)((char *)v8 + (char *)corner4 - (char *)corner3),
               min_height,
               max_height);
        if ( !v9 )
          break;
        if ( v9 == 1 )
          bnd = 1;
        ++v8;
        ++iq;
        if ( iq > Render::portal_npnts )
          return bnd;
        v7 = (char *)corner1 - (char *)corner3;
      }
      result = 0;
    }
  }
  return result;
}
// 846050: using guessed type int Render::portal_npnts;

//----- (0054DD20) --------------------------------------------------------  // acclient.c:381192
void __thiscall DArray<view_vertex>::grow(DArray<view_vertex> *this, unsigned int size)
{
  unsigned int v2; // ebx@1
  DArray<view_vertex> *v3; // esi@1
  void *v4; // eax@3
  int v5; // edi@4
  unsigned int v6; // edx@6
  int v7; // ecx@7
  int v8; // eax@7
  int v9; // ecx@9
  int v10; // edi@9
  int v11; // ecx@9
  view_vertex *v12; // ecx@11
  float v13; // eax@12
  void *v14; // edx@12
  int v15; // edi@12
  int v16; // eax@12
  DiskSpace *v17; // edi@12
  int v18; // ebp@13
  view_vertex *new_data; // [sp+8h] [bp-8h]@4
  unsigned int sizea; // [sp+14h] [bp+4h]@12

  v2 = size;
  v3 = this;
  if ( size > this->sizeOf )
  {
    v4 = operator new[](24 * size + 4);
    if ( v4 )
    {
      v5 = (int)((char *)v4 + 4);
      *(_DWORD *)v4 = size;
      vector_constructor_iterator((char *)v4 + 4, 0x18u, size, (void *(__thiscall *)(void *))view_vertex::view_vertex);
      new_data = (view_vertex *)v5;
    }
    else
    {
      new_data = 0;
    }
    v6 = 0;
    if ( v3->sizeOf )
    {
      v7 = -8 - (_DWORD)new_data;
      v8 = (int)&new_data->plane;
      while ( 1 )
      {
        v9 = v8 + v7;
        v10 = *(_DWORD *)((char *)&v3->data->pt.x + v9);
        v11 = (int)((char *)v3->data + v9);
        *(_DWORD *)(v8 - 8) = v10;
        *(_DWORD *)(v8 - 4) = *(_DWORD *)(v11 + 4);
        v11 += 8;
        *(_DWORD *)v8 = *(_DWORD *)v11;
        *(_DWORD *)(v8 + 4) = *(_DWORD *)(v11 + 4);
        *(_DWORD *)(v8 + 8) = *(_DWORD *)(v11 + 8);
        *(_DWORD *)(v8 + 12) = *(_DWORD *)(v11 + 12);
        ++v6;
        v8 += 24;
        if ( v6 >= v3->sizeOf )
          break;
        v7 = -8 - (_DWORD)new_data;
      }
      v2 = size;
    }
    v12 = v3->data;
    if ( v3->data )
    {
      v13 = v12[-1].plane.d;
      v14 = &v12[-1].plane.d;
      v15 = 3 * LODWORD(v13);
      v16 = LODWORD(v13) - 1;
      sizea = (unsigned int)&v12[-1].plane.d;
      v17 = (DiskSpace *)&v12[8 * v15 / 0x18u];
      if ( v16 >= 0 )
      {
        v18 = v16 + 1;
        do
        {
          v17 -= 24;
          gmNoticeHandler::RecvNotice_PrevSpellSelection(v17);
          --v18;
        }
        while ( v18 );
        v14 = (void *)sizea;
      }
      operator delete[](v14);
    }
    v3->sizeOf = v2;
    v3->data = new_data;
  }
  else
  {
    DArray<view_vertex>::shrink(this, size);
  }
}

//----- (0054DE30) --------------------------------------------------------  // acclient.c:381288
void __thiscall DArray<view_vertex>::shrink(DArray<view_vertex> *this, unsigned int size)
{
  DArray<view_vertex> *v2; // esi@1
  unsigned int v3; // edi@1
  view_vertex *v4; // ecx@4
  bool v5; // zf@4
  float v6; // eax@5
  void *v7; // edx@5
  int v8; // ebx@5
  int v9; // eax@5
  DiskSpace *v10; // ebx@5
  int v11; // ebp@6
  void *v12; // eax@11
  int v13; // ebx@12
  unsigned int v14; // edx@14
  int v15; // ecx@15
  int v16; // eax@15
  int v17; // ecx@17
  int v18; // edi@17
  int v19; // ecx@17
  view_vertex *v20; // ecx@19
  float v21; // eax@20
  void *v22; // edx@20
  int v23; // ebx@20
  int v24; // eax@20
  DiskSpace *v25; // ebx@20
  int v26; // ebp@21
  view_vertex *new_data; // [sp+8h] [bp-8h]@12
  unsigned int sizea; // [sp+14h] [bp+4h]@5
  unsigned int sizeb; // [sp+14h] [bp+4h]@20

  v2 = this;
  v3 = size;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v12 = operator new[](24 * size + 4);
      if ( v12 )
      {
        v13 = (int)((char *)v12 + 4);
        *(_DWORD *)v12 = size;
        vector_constructor_iterator(
          (char *)v12 + 4,
          0x18u,
          size,
          (void *(__thiscall *)(void *))view_vertex::view_vertex);
        new_data = (view_vertex *)v13;
      }
      else
      {
        new_data = 0;
      }
      v14 = 0;
      v2->sizeOf = size;
      if ( size > 0 )
      {
        v15 = -8 - (_DWORD)new_data;
        v16 = (int)&new_data->plane;
        while ( 1 )
        {
          v17 = v16 + v15;
          v18 = *(_DWORD *)((char *)&v2->data->pt.x + v17);
          v19 = (int)((char *)v2->data + v17);
          *(_DWORD *)(v16 - 8) = v18;
          *(_DWORD *)(v16 - 4) = *(_DWORD *)(v19 + 4);
          v19 += 8;
          *(_DWORD *)v16 = *(_DWORD *)v19;
          *(_DWORD *)(v16 + 4) = *(_DWORD *)(v19 + 4);
          *(_DWORD *)(v16 + 8) = *(_DWORD *)(v19 + 8);
          *(_DWORD *)(v16 + 12) = *(_DWORD *)(v19 + 12);
          ++v14;
          v16 += 24;
          if ( v14 >= v2->sizeOf )
            break;
          v15 = -8 - (_DWORD)new_data;
        }
        v3 = size;
      }
      v20 = v2->data;
      if ( v2->data )
      {
        v21 = v20[-1].plane.d;
        v22 = &v20[-1].plane.d;
        v23 = 3 * LODWORD(v21);
        v24 = LODWORD(v21) - 1;
        sizeb = (unsigned int)&v20[-1].plane.d;
        v25 = (DiskSpace *)&v20[8 * v23 / 0x18u];
        if ( v24 >= 0 )
        {
          v26 = v24 + 1;
          do
          {
            v25 -= 24;
            gmNoticeHandler::RecvNotice_PrevSpellSelection(v25);
            --v26;
          }
          while ( v26 );
          v22 = (void *)sizeb;
        }
        operator delete[](v22);
      }
      v2->data = new_data;
    }
    else
    {
      v4 = this->data;
      v5 = v2->data == 0;
      v2->sizeOf = 0;
      if ( !v5 )
      {
        v6 = v4[-1].plane.d;
        v7 = &v4[-1].plane.d;
        v8 = 3 * LODWORD(v6);
        v9 = LODWORD(v6) - 1;
        sizea = (unsigned int)&v4[-1].plane.d;
        v10 = (DiskSpace *)&v4[8 * v8 / 0x18u];
        if ( v9 >= 0 )
        {
          v11 = v9 + 1;
          do
          {
            v10 -= 24;
            gmNoticeHandler::RecvNotice_PrevSpellSelection(v10);
            --v11;
          }
          while ( v11 );
          v7 = (void *)sizea;
        }
        operator delete[](v7);
      }
      v2->data = 0;
    }
    if ( v2->next_available > v3 )
      v2->next_available = v3;
  }
  else
  {
    DArray<view_vertex>::grow(this, size);
  }
}

//----- (0054DFA0) --------------------------------------------------------  // acclient.c:381431
void __thiscall Render::Begin(Render *this)
{
  this->m_nDisplayAdapter = 0;
  SmartArray<RenderDisplayModeType,1>::Reset(&this->m_DisplayModes);
}

//----- (0054DFB0) --------------------------------------------------------  // acclient.c:381438
void __thiscall Render::End(Render *this)
{
  SmartArray<RenderDisplayModeType,1>::Reset(&this->m_DisplayModes);
}

//----- (0054DFC0) --------------------------------------------------------  // acclient.c:381444
int __cdecl Render::copy_view(portal_view_type *portal_view, Vec2Dscreen **clip_view, unsigned int num_pts)
{
  portal_view_type *v3; // edi@1
  unsigned int v4; // ebx@1
  int v5; // esi@2
  unsigned int v6; // ecx@7
  signed int v7; // ebp@7
  unsigned int v8; // ecx@9
  int v9; // esi@9
  signed int v10; // ecx@10
  float v11; // ebx@10
  Vec2Dscreen *v12; // edx@12
  Vec2Dscreen *v13; // edx@15
  Vec2Dscreen *v14; // esi@15
  bool v15; // al@17
  Vec2Dscreen *v16; // edi@21
  long double v17; // st7@21
  Vec2Dscreen *v18; // ecx@32
  Vec2Dscreen *v19; // edx@32
  bool v20; // al@34
  Vec2Dscreen *v21; // edx@37
  long double v22; // st7@37
  Vec2Dscreen *v23; // eax@39
  Vec2Dscreen *v24; // edx@43
  Vec2Dscreen *v25; // ebx@43
  long double v26; // st7@43
  signed int v27; // eax@47
  unsigned int v29; // ecx@52
  int v30; // eax@52
  int v31; // edx@54
  signed int v32; // eax@54
  int v33; // edx@55
  int v34; // eax@60
  int v35; // edx@61
  double v36; // st7@61
  double v37; // st6@62
  int v38; // edi@71
  AC1Legacy::Vector3 *v39; // ebx@73
  int v40; // ebp@73
  double v41; // st7@77
  int v42; // eax@77
  double v43; // st6@77
  AC1Legacy::Vector3 *v44; // ecx@77
  int v45; // edx@77
  double v46; // st5@77
  double v47; // st4@78
  double v48; // st4@78
  float v49; // ST48_4@78
  float v50; // ST4C_4@78
  double v51; // st3@78
  float v52; // ST58_4@78
  float v53; // ST5C_4@78
  float v54; // ST64_4@78
  float v55; // ST68_4@78
  float v56; // ST74_4@78
  float v57; // ST28_4@78
  AC1Legacy::Vector3 *v58; // ebx@78
  float v59; // ST2C_4@78
  AC1Legacy::Vector3 *v60; // ecx@79
  int v61; // edx@80
  float *v62; // ecx@80
  int v63; // edi@80
  long double v64; // st6@84
  int v65; // eax@85
  double v66; // st6@85
  double v67; // st5@85
  int num_out; // [sp+10h] [bp-228h]@7
  float dy; // [sp+14h] [bp-224h]@21
  float dya; // [sp+14h] [bp-224h]@37
  float dyb; // [sp+14h] [bp-224h]@43
  float dyc; // [sp+14h] [bp-224h]@62
  float ymin; // [sp+18h] [bp-220h]@10
  float ymina; // [sp+18h] [bp-220h]@61
  float tmpVector; // [sp+1Ch] [bp-21Ch]@81
  float tmpVector_4; // [sp+20h] [bp-218h]@81
  float tmpVector_8; // [sp+24h] [bp-214h]@81
  float xmax; // [sp+28h] [bp-210h]@10
  float xmaxa; // [sp+28h] [bp-210h]@61
  int vf; // [sp+2Ch] [bp-20Ch]@4
  float vfa; // [sp+2Ch] [bp-20Ch]@61
  int vc; // [sp+30h] [bp-208h]@1
  float v83; // [sp+34h] [bp-204h]@11
  int v84; // [sp+34h] [bp-204h]@73
  char keep[64]; // [sp+6Ch] [bp-1CCh]@10
  AC1Legacy::Vector3 v[33]; // [sp+ACh] [bp-18Ch]@73

  v3 = portal_view;
  v4 = portal_view->view_count;
  vc = portal_view->view_count;
  if ( v4 )
    v5 = portal_view->view.vertex_count_total;
  else
    v5 = 0;
  vf = v5;
  if ( (signed int)v4 >= (signed int)portal_view->view.poly.sizeOf )
    DArray<view_poly>::grow(&portal_view->view.poly, v4 + 16);
  if ( !clip_view )
  {
    v6 = portal_view->view.vertex.sizeOf;
    v7 = 4;
    num_out = 4;
    portal_view->view.vertex_count_total = v5 + 5;
    if ( v5 + 5 >= v6 )
      DArray<view_vertex>::grow(&portal_view->view.vertex, v5 + 21);
    v8 = v4;
    portal_view->view.poly.data[v8].vertex_count = 4;
    portal_view->view.poly.data[v8].vertex_index = v5;
    v9 = (int)&portal_view->view.vertex.data[v5];
    *(_DWORD *)v9 = 0;
    *(float *)(v9 + 4) = (double)RenderDevice::render_device->m_viewportHeight;
    *(float *)(v9 + 24) = (double)RenderDevice::render_device->m_viewportWidth;
    *(float *)(v9 + 28) = (double)RenderDevice::render_device->m_viewportHeight;
    *(float *)(v9 + 48) = (double)RenderDevice::render_device->m_viewportWidth;
    *(_DWORD *)(v9 + 52) = 0;
    *(_DWORD *)(v9 + 72) = 0;
    *(_DWORD *)(v9 + 76) = 0;
    *(_DWORD *)(v9 + 96) = 0;
    *(float *)(v9 + 100) = (double)RenderDevice::render_device->m_viewportHeight;
    goto LABEL_61;
  }
  *(float *)&v10 = 0.0;
  v11 = 0.0;
  num_out = 1;
  xmax = 0.0;
  ymin = 0.0;
  keep[0] = 1;
  if ( (signed int)num_pts > 0 )
  {
    v83 = 0.0;
    while ( 1 )
    {
      v12 = clip_view[v10];
      if ( v12->w != 1.0 )
      {
        v12->xw = v12->xw / v12->w;
        clip_view[v10]->yw = clip_view[v10]->yw / clip_view[v10]->w;
        LODWORD(clip_view[v10]->w) = 1065353216;
      }
      if ( v10 <= 0 )
        goto LABEL_31;
      v13 = clip_view[v10];
      v14 = clip_view[LODWORD(v11)];
      v15 = fabs(v13->xw - v14->xw) > 1.0 || fabs(v13->yw - v14->yw) > 1.0;
      keep[v10] = v15;
      if ( v15 )
        break;
LABEL_30:
      v5 = vf;
      v3 = portal_view;
LABEL_31:
      ++v10;
      if ( v10 >= (signed int)num_pts )
        goto LABEL_32;
    }
    if ( SLODWORD(v11) > 0 )
    {
      v16 = *(Vec2Dscreen **)((char *)clip_view + LODWORD(v83));
      v17 = fabs(v16->xw - v13->xw);
      dy = fabs(v16->yw - v13->yw);
      if ( v17 < dy )
        v17 = dy;
      if ( fabs((v14->yw - v13->yw) * (v16->xw - v14->xw) - (v14->xw - v13->xw) * (v16->yw - v14->yw)) >= v17 )
      {
        ++num_out;
        xmax = v11;
        LODWORD(v83) = 4 * LODWORD(v11);
      }
      else
      {
        keep[LODWORD(v11)] = 0;
        if ( LODWORD(ymin) == LODWORD(v11) )
          goto LABEL_28;
      }
LABEL_29:
      v11 = *(float *)&v10;
      goto LABEL_30;
    }
    ++num_out;
LABEL_28:
    ymin = *(float *)&v10;
    goto LABEL_29;
  }
LABEL_32:
  v18 = *clip_view;
  v19 = clip_view[LODWORD(v11)];
  v20 = fabs((*clip_view)->xw - v19->xw) > 1.0 || fabs(v18->yw - v19->yw) > 1.0;
  keep[LODWORD(v11)] = v20;
  if ( v20 )
  {
    v21 = clip_view[LODWORD(xmax)];
    v22 = fabs(v21->xw - v18->xw);
    dya = fabs(v21->yw - v18->yw);
    if ( v22 < dya )
      v22 = dya;
    v23 = clip_view[LODWORD(v11)];
    if ( v22 <= fabs((v23->yw - v18->yw) * (v21->xw - v23->xw) - (v21->yw - v23->yw) * (v23->xw - v18->xw)) )
    {
      xmax = v11;
      goto LABEL_42;
    }
    keep[LODWORD(v11)] = 0;
  }
  --num_out;
LABEL_42:
  if ( SLODWORD(ymin) > 0 )
  {
    v24 = clip_view[LODWORD(xmax)];
    v25 = clip_view[LODWORD(ymin)];
    v26 = fabs(v24->xw - v25->xw);
    dyb = fabs(v24->yw - v25->yw);
    if ( v26 < dyb )
      v26 = dyb;
    if ( v26 > fabs((v24->xw - v18->xw) * (v18->yw - v25->yw) - (v24->yw - v18->yw) * (v18->xw - v25->xw)) )
    {
      keep[0] = 0;
      --num_out;
    }
  }
  v27 = num_out;
  if ( num_out < 3 )
    return 0;
  if ( num_out > 31 )
  {
    v27 = 31;
    num_out = 31;
  }
  v29 = v3->view.vertex.sizeOf;
  v30 = v27 + v5 + 1;
  v3->view.vertex_count_total = v30;
  if ( v30 >= v29 )
    DArray<view_vertex>::grow(&v3->view.vertex, v30 + 16);
  v31 = num_out;
  v8 = vc;
  v3->view.poly.data[v8].vertex_count = num_out;
  v3->view.poly.data[v8].vertex_index = v5;
  v9 = (int)&v3->view.vertex.data[v5];
  v32 = 0;
  if ( (signed int)num_pts > 0 )
  {
    v33 = v9;
    do
    {
      if ( keep[v32] )
      {
        v33 += 24;
        *(float *)(v33 - 24) = fabs(clip_view[v32]->xw);
        *(float *)(v33 - 20) = fabs(clip_view[v32]->vertex_w.y);
      }
      ++v32;
    }
    while ( v32 < (signed int)num_pts );
    v31 = num_out;
  }
  v7 = num_out;
  v34 = v9 + 24 * v31;
  *(_DWORD *)v34 = *(_DWORD *)v9;
  *(_DWORD *)(v34 + 4) = *(_DWORD *)(v9 + 4);
LABEL_61:
  xmaxa = *(float *)(v9 + 24 * v7 - 24);
  v35 = v9 + 24 * v7 - 48;
  vfa = xmaxa;
  v36 = *(float *)(v35 + 28);
  for ( ymina = *(float *)(v35 + 28); v35 >= (unsigned int)v9; v35 -= 24 )
  {
    v37 = *(float *)v35;
    dyc = *(float *)(v35 + 4);
    if ( v37 >= vfa )
    {
      if ( v37 > xmaxa )
        xmaxa = *(float *)v35;
    }
    else
    {
      vfa = *(float *)v35;
    }
    if ( dyc >= (double)ymina )
    {
      if ( dyc > v36 )
        v36 = dyc;
    }
    else
    {
      ymina = *(float *)(v35 + 4);
    }
  }
  v3->view.poly.data[v8].xmin = vfa;
  v3->view.poly.data[v8].xmax = xmaxa;
  v3->view.poly.data[v8].ymin = ymina;
  v3->view.poly.data[v8].ymax = v36;
  v38 = num_out - 1;
  if ( newmethod == 1 )
  {
    if ( v38 >= 0 )
    {
      v39 = &v[v38];
      v40 = v9 + 24 * v38;
      v84 = num_out;
      do
      {
        PrimD3DRender::ScreenToViewTransform(v39, *(float *)v40, *(float *)(v40 + 4));
        v40 -= 24;
        --v39;
        --v84;
      }
      while ( v84 );
    }
  }
  else if ( v38 >= 0 )
  {
    v41 = Render::Yaxis.x * Render::vdst;
    v42 = v9 + 24 * v38;
    v43 = flt_86B180 * Render::vdst;
    v44 = &v[v38];
    v45 = num_out;
    v46 = flt_86B184 * Render::vdst;
    do
    {
      v47 = *(float *)(v42 + 4);
      v42 -= 24;
      v48 = v47 * Render::yinvscale - Render::ty;
      v49 = Render::Zaxis.x * v48;
      v50 = flt_86642C * v48;
      v51 = *(float *)(v42 + 24) * Render::xinvscale - Render::tx;
      v52 = v51 * flt_86B1C4;
      v53 = flt_86B1C8 * v51;
      v54 = v52 + v43;
      v55 = v53 + v46;
      v56 = v55 - v48 * flt_866430;
      v57 = Render::Xaxis.x * v51 + v41 - v49;
      v58 = v44;
      v44->x = v57;
      v59 = v54 - v50;
      v44->y = v59;
      --v44;
      --v45;
      v58->z = v56;
    }
    while ( v45 );
  }
  v60 = &v[num_out];
  v60->x = v[0].x;
  v60->y = v[0].y;
  v60->z = v[0].z;
  if ( v38 >= 0 )
  {
    v61 = v9 + 24 * v38 + 8;
    v62 = &v[0].z + 3 * v38;
    v63 = num_out;
    do
    {
      tmpVector = *v62 * v62[2] - *(v62 - 1) * v62[3];
      tmpVector_4 = v62[3] * *(v62 - 2) - *v62 * v62[1];
      tmpVector_8 = *(v62 - 1) * v62[1] - v62[2] * *(v62 - 2);
      if ( fabs(tmpVector) >= 0.00019999999 || fabs(tmpVector_4) >= 0.00019999999 || fabs(tmpVector_8) >= 0.00019999999 )
      {
        v64 = 1.0 / sqrt(tmpVector_8 * tmpVector_8 + tmpVector_4 * tmpVector_4 + tmpVector * tmpVector);
        tmpVector = tmpVector * v64;
        tmpVector_4 = tmpVector_4 * v64;
        tmpVector_8 = tmpVector_8 * v64;
      }
      v65 = v61;
      v62 -= 3;
      v61 -= 24;
      --v63;
      v66 = *(float *)&dword_866414 * tmpVector_8 + *(float *)&dword_866410 * tmpVector_4;
      v67 = tmpVector * Render::viewer_world_space.viewpoint.x;
      *(float *)v65 = tmpVector;
      *(float *)(v65 + 4) = tmpVector_4;
      *(float *)(v65 + 8) = tmpVector_8;
      *(float *)(v61 + 36) = -(v66 + v67);
    }
    while ( v63 );
  }
  ++portal_view->view_count;
  return 1;
}
// 81EC80: using guessed type float Render::vdst;
// 846048: using guessed type double Render::tx;
// 8662C8: using guessed type double Render::xinvscale;
// 8662E0: using guessed type double Render::yinvscale;
// 866300: using guessed type double Render::ty;
// 86640C: using guessed type struct DrawParms Render::viewer_world_space;
// 866410: using guessed type int dword_866410;
// 866414: using guessed type int dword_866414;
// 866428: using guessed type struct Vector3 Render::Zaxis;
// 86642C: using guessed type float flt_86642C;
// 866430: using guessed type float flt_866430;
// 86B17C: using guessed type struct Vector3 Render::Yaxis;
// 86B180: using guessed type float flt_86B180;
// 86B184: using guessed type float flt_86B184;
// 86B1C0: using guessed type struct Vector3 Render::Xaxis;
// 86B1C4: using guessed type float flt_86B1C4;
// 86B1C8: using guessed type float flt_86B1C8;

//----- (0054E7A0) --------------------------------------------------------  // acclient.c:381839
void __thiscall Render::Shutdown(Render *this)
{
  Render *v1; // edi@1
  char *v2; // esi@1
  PStringBase<char> _Name; // [sp+0h] [bp-4h]@1

  _Name.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v1 = this;
  UserPreferences::UnregisterPreference(&Render_TextureFiltering_34);
  UserPreferences::UnregisterPreference(&Render_LandscapeDetailTextures_34);
  UserPreferences::UnregisterPreference(&Render_BuildingDetailTextures_34);
  UserPreferences::UnregisterPreference(&Render_MultiPassAlpha_34);
  UserPreferences::UnregisterPreference(&Render_LandscapeTextureDetail_34);
  UserPreferences::UnregisterPreference(&Render_EnvironmentTextureDetail_34);
  UserPreferences::UnregisterPreference(&Render_SceneryDrawDistance_34);
  UserPreferences::UnregisterPreference(&Render_LandscapeDrawDistance_34);
  UserPreferences::UnregisterPreference(&Render_ScreenBrightness_34);
  UserPreferences::UnregisterPreference(&Render_AspectRatio_34);
  UserPreferences::UnregisterPreference(&Render_FieldOfView_34);
  UserPreferences::UnregisterPreference(&Render_AutomaticDegrades_34);
  UserPreferences::UnregisterPreference(&Render_GraphicsPerformance_34);
  UserPreferences::UnregisterPreference(&Render_DegradeDistance_34);
  PStringBase<char>::PStringBase<char>(&_Name, "SetGraphicsQuality");
  GlobalRegistry::UnregisterCommand(&_Name);
  v2 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  SmartArray<RenderDisplayModeType,1>::Reset(&v1->m_DisplayModes);
  v1->m_nDisplayAdapter = 0;
  SmartArray<RenderDisplayModeType,1>::Reset(&v1->m_DisplayModes);
}

//----- (0054E890) --------------------------------------------------------  // acclient.c:381872
void __cdecl Render::CheckForLostDevice()
{
  PSRefBufferCharData<unsigned short> *v0; // ecx@4
  PSRefBufferCharData<unsigned short> *v1; // ecx@5
  PSRefBufferCharData<unsigned short> *v2; // ecx@5
  PStringBase<unsigned short> v3; // [sp-10h] [bp-10h]@5
  PStringBase<unsigned short> v4; // [sp-Ch] [bp-Ch]@5
  PStringBase<unsigned short> v5; // [sp-8h] [bp-8h]@5
  PlatformString::DisplayStringMode v6; // [sp-4h] [bp-4h]@5

  if ( RenderDevice::render_device
    && RenderDevice::render_device->m_bDeviceLost
    && (unsigned __int8)((int (*)(void))RenderDevice::render_device->vfptr->IsResetPossible)()
    && !Render::RestartRenderingSystem() )
  {
    v6 = 0;
    v5.m_charbuffer = v0;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v5, &word_794320);
    v4.m_charbuffer = v1;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v4, &word_794320);
    v3.m_charbuffer = v2;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v3, &word_794320);
    PlatformString::DisplayString(0x80u, v3, v4, v5, v6);
    _exit(1);
  }
}

//----- (0054E900) --------------------------------------------------------  // acclient.c:381900
char __cdecl Render::CC_SetGraphicsQuality(PStringBaseArray<char> *_Args)
{
  PSRefBufferCharData<char> *v1; // esi@2
  unsigned __int32 v2; // eax@2
  char result; // al@4
  signed int v4; // esi@6
  char *v5; // esi@6

  if ( _Args->m_num )
  {
    v1 = _Args->m_data->m_charbuffer;
    *__errno() = 0;
    v2 = _strtoul(v1->m_data, 0, 0);
    if ( v2 < 1 || v2 > 5 )
    {
      result = 0;
    }
    else
    {
      Render::SetOverallGraphicsQuality(v2);
      result = 1;
    }
  }
  else
  {
    v4 = Render::DetermineOverallGraphicsQuality();
    _Args = (PStringBaseArray<char> *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::sprintf((PStringBase<char> *)&_Args, "Current graphics quality level: %i\n", v4);
    GlobalRegistry::OutputText((PStringBase<char> *)&_Args);
    v5 = (char *)&_Args[-2].m_sizeAndDeallocate;
    if ( !InterlockedDecrement((volatile LONG *)&_Args[-2].m_sizeAndDeallocate + 1) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    result = 1;
  }
  return result;
}

//----- (0054E9B0) --------------------------------------------------------  // acclient.c:381939
char __thiscall Render::Startup(Render *this, RenderConfig *_config)
{
  RenderConfig *v2; // edi@1
  char *v3; // edi@4
  char *v4; // edi@7
  RenderConfig *v5; // edi@10
  RenderConfig *v6; // edi@13
  RenderConfig *v7; // edi@16
  RenderConfig *v8; // edi@19
  RenderConfig *v9; // edi@22
  RenderConfig *v10; // edi@25
  RenderConfig *v11; // edi@28
  RenderConfig *v12; // edi@31
  RenderConfig *v13; // edi@34
  RenderConfig *v14; // edi@37
  RenderConfig *v15; // edi@40
  RenderConfig *v16; // edi@43
  RenderConfig *v17; // edi@46
  RenderConfig *v18; // edi@49
  RenderConfig *v19; // edi@52
  PStringBase<char> _Description; // [sp+38h] [bp-8h]@1
  PStringBase<char> _Usage; // [sp+3Ch] [bp-4h]@1

  this->m_Config.m_GraphicsDriver = _config->m_GraphicsDriver;
  this->m_nDisplayAdapter = 0;
  SmartArray<RenderDisplayModeType,1>::Reset(&this->m_DisplayModes);
  Render::m_CacheOverallGraphicsQuality = 3;
  Render::SetOverallGraphicsQuality(3u);
  PStringBase<char>::PStringBase<char>(&_Usage, "SetGraphicsQuality <1-5>");
  PStringBase<char>::PStringBase<char>(
    &_Description,
    "Sets rendering options to the preset configuration for the specified quality level");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_config, "SetGraphicsQuality");
  GlobalRegistry::RegisterCommand(
    (bool (__cdecl *)(PStringBaseArray<char> *))Render::CC_SetGraphicsQuality,
    (PStringBase<char> *)&_config,
    &_Description,
    &_Usage);
  v2 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v2 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v2->m_GraphicsDriver)(v2, 1);
  v3 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = &_Usage.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Usage.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  PStringBase<char>::PStringBase<char>(
    (PStringBase<char> *)&_config,
    "Texture filtering quality.  Bilinear is fastest.  Anisoptric is highest quality.");
  UserPreferences::RegisterPreference(
    (unsigned int *)&_config,
    &Render::m_RenderPrefs,
    &Render_TextureFiltering_34,
    (PStringBase<char> *)&_config,
    (void (__cdecl *)(PStringBase<char> *))Render::GRPCallback_OnRenderPreferenceChanged,
    4u,
    Render_TextureFiltering_Choices_34,
    0);
  v5 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v5 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v5->m_GraphicsDriver)(v5, 1);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_config, "Landscape Detail Textures");
  UserPreferences::RegisterPreference(
    (bool *)&_config,
    &byte_81EF94,
    &Render_LandscapeDetailTextures_34,
    (PStringBase<char> *)&_config,
    (void (__cdecl *)(PStringBase<char> *))Render::GRPCallback_OnRenderPreferenceChanged,
    0,
    0,
    0);
  v6 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v6 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v6->m_GraphicsDriver)(v6, 1);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_config, "Environment Detail Textures");
  UserPreferences::RegisterPreference(
    (bool *)&_config,
    &byte_81EF95,
    &Render_BuildingDetailTextures_34,
    (PStringBase<char> *)&_config,
    (void (__cdecl *)(PStringBase<char> *))Render::GRPCallback_OnRenderPreferenceChanged,
    0,
    0,
    0);
  v7 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v7 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v7->m_GraphicsDriver)(v7, 1);
  PStringBase<char>::PStringBase<char>(
    (PStringBase<char> *)&_config,
    "Multiple pass alpha renders all clipmapped textures twice for softer edges.");
  UserPreferences::RegisterPreference(
    (bool *)&_config,
    &byte_81EF96,
    &Render_MultiPassAlpha_34,
    (PStringBase<char> *)&_config,
    (void (__cdecl *)(PStringBase<char> *))Render::GRPCallback_OnRenderPreferenceChanged,
    0,
    0,
    0);
  v8 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v8 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v8->m_GraphicsDriver)(v8, 1);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_config, "Landscape texture detail level");
  UserPreferences::RegisterPreference(
    (unsigned int *)&_config,
    &dword_81EF98,
    &Render_LandscapeTextureDetail_34,
    (PStringBase<char> *)&_config,
    (void (__cdecl *)(PStringBase<char> *))Render::GRPCallback_OnRenderPreferenceChanged,
    5u,
    Render_LandscapeTextureDetail_Choices_34,
    Render_LandscapeTextureDetail_Values);
  v9 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v9 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v9->m_GraphicsDriver)(v9, 1);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_config, "Environment texture detail level");
  UserPreferences::RegisterPreference(
    (unsigned int *)&_config,
    &dword_81EF9C,
    &Render_EnvironmentTextureDetail_34,
    (PStringBase<char> *)&_config,
    (void (__cdecl *)(PStringBase<char> *))Render::GRPCallback_OnRenderPreferenceChanged,
    5u,
    Render_EnvironmentTextureDetail_Choices_34,
    Render_EnvironmentTextureDetail_Values);
  v10 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v10 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v10->m_GraphicsDriver)(v10, 1);
  PStringBase<char>::PStringBase<char>(
    (PStringBase<char> *)&_config,
    "Distance to draw characters, scenery and other objects");
  UserPreferences::RegisterPreference(
    (unsigned int *)&_config,
    &dword_81EFA0,
    &Render_SceneryDrawDistance_34,
    (PStringBase<char> *)&_config,
    (void (__cdecl *)(PStringBase<char> *))Render::GRPCallback_OnRenderPreferenceChanged,
    3u,
    Render_SceneryDrawDistance_Choices_34,
    0);
  v11 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v11 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v11->m_GraphicsDriver)(v11, 1);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_config, "How far out to generate landscape topology");
  UserPreferences::RegisterPreference(
    (unsigned int *)&_config,
    &mid_radius,
    &Render_LandscapeDrawDistance_34,
    (PStringBase<char> *)&_config,
    (void (__cdecl *)(PStringBase<char> *))Render::GRPCallback_OnRenderPreferenceChanged,
    6u,
    Render_LandscapeDrawDistance_Choices_34,
    Render_LandscapeDrawDistance_Values);
  v12 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v12 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v12->m_GraphicsDriver)(v12, 1);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_config, "Screen brightness adjustment");
  UserPreferences::RegisterPreference(
    (float *)&_config,
    &fBrightness,
    &Render_ScreenBrightness_34,
    (PStringBase<char> *)&_config,
    (void (__cdecl *)(PStringBase<char> *))Render::GRPCallback_OnRenderPreferenceChanged,
    0,
    0,
    0);
  v13 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v13 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v13->m_GraphicsDriver)(v13, 1);
  PStringBase<char>::PStringBase<char>(
    (PStringBase<char> *)&_config,
    "Display aspect ratio; use 'Normal' for square 4:3 displays or 'Wide' for 16:9 widescreen displays");
  UserPreferences::RegisterPreference(
    (unsigned int *)&_config,
    &dword_81EFA8,
    &Render_AspectRatio_34,
    (PStringBase<char> *)&_config,
    (void (__cdecl *)(PStringBase<char> *))Render::GRPCallback_OnRenderPreferenceChanged,
    3u,
    Render_AspectRatio_Choices_34,
    0);
  v14 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v14 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v14->m_GraphicsDriver)(v14, 1);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_config, "Feild of View");
  UserPreferences::RegisterPreference(
    (float *)&_config,
    &degrees,
    &Render_FieldOfView_34,
    (PStringBase<char> *)&_config,
    (void (__cdecl *)(PStringBase<char> *))Render::GRPCallback_OnRenderPreferenceChanged,
    0,
    0,
    0);
  v15 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v15 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v15->m_GraphicsDriver)(v15, 1);
  PStringBase<char>::PStringBase<char>(
    (PStringBase<char> *)&_config,
    "Automatic degrades; adjustes the adaptive degrade bias based on framerate.");
  UserPreferences::RegisterPreference(
    (bool *)&_config,
    &Render::auto_update_deg_mul,
    &Render_AutomaticDegrades_34,
    (PStringBase<char> *)&_config,
    (void (__cdecl *)(PStringBase<char> *))Render::GRPCallback_OnRenderPreferenceChanged,
    0,
    0,
    0);
  v16 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v16 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v16->m_GraphicsDriver)(v16, 1);
  PStringBase<char>::PStringBase<char>(
    (PStringBase<char> *)&_config,
    "Adaptive Degrade Bias; manually sets the degrade biad, overwritten by Automatic Degrades.");
  UserPreferences::RegisterPreference(
    (float *)&_config,
    &Render::s_rUserSuppliedDegradeBias,
    &Render_GraphicsPerformance_34,
    (PStringBase<char> *)&_config,
    (void (__cdecl *)(PStringBase<char> *))Render::GRPCallback_OnRenderPreferenceChanged,
    0,
    0,
    0);
  v17 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v17 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v17->m_GraphicsDriver)(v17, 1);
  PStringBase<char>::PStringBase<char>(
    (PStringBase<char> *)&_config,
    "Degrade Distance; scales the distance at which degrades occure.");
  UserPreferences::RegisterPreference(
    (float *)&_config,
    &Render::s_rDegradeDistance,
    &Render_DegradeDistance_34,
    (PStringBase<char> *)&_config,
    (void (__cdecl *)(PStringBase<char> *))Render::GRPCallback_OnRenderPreferenceChanged,
    0,
    0,
    0);
  v18 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v18 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v18->m_GraphicsDriver)(v18, 1);
  PStringBase<char>::PStringBase<char>(
    (PStringBase<char> *)&_config,
    "Prefer a specific display adapter index (0 = automatic selection.)");
  UserPreferences::RegisterPreference(
    (unsigned int *)&_config,
    &dword_81EFAC,
    &Render_DisplayAdapter_34,
    (PStringBase<char> *)&_config,
    0,
    0,
    0,
    0);
  v19 = _config - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_config[-4]) && v19 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v19->m_GraphicsDriver)(v19, 1);
  if ( Render::sm_WantSafeRenderSettings )
  {
    dword_81EF98 = 2;
    dword_81EF9C = 2;
    Render::m_RenderPrefs.TextureFiltering = 0;
    byte_81EF94 = 0;
    byte_81EF95 = 0;
    byte_81EF96 = 0;
    dword_81EFA0 = 1;
    mid_radius = 8;
    LODWORD(fBrightness) = 0;
    dword_81EFAC = 0;
    dword_81EFA8 = 1;
    Render::sm_WantSafeRenderSettings = 0;
  }
  UserPreferences::UnregisterPreference(&Render_DisplayAdapter_34);
  return 1;
}
// 81EC58: using guessed type float Render::s_rDegradeDistance;
// 81EC68: using guessed type bool Render::auto_update_deg_mul;
// 81EF90: using guessed type struct RenderPrefs Render::m_RenderPrefs;
// 81EF94: using guessed type char byte_81EF94;
// 81EF95: using guessed type char byte_81EF95;
// 81EF96: using guessed type char byte_81EF96;
// 81EF98: using guessed type int dword_81EF98;
// 81EF9C: using guessed type int dword_81EF9C;
// 81EFA0: using guessed type int dword_81EFA0;
// 81EFA8: using guessed type int dword_81EFA8;
// 81EFAC: using guessed type int dword_81EFAC;
// 866308: using guessed type float Render::s_rUserSuppliedDegradeBias;
// 866340: using guessed type unsigned __int32 Render::m_CacheOverallGraphicsQuality;
// 866344: using guessed type bool Render::sm_WantSafeRenderSettings;

//----- (0054EF50) --------------------------------------------------------  // acclient.c:382231
void __cdecl Render::set_default_view()
{
  if ( !(_S273_14 & 1) )
  {
    _S273_14 |= 1u;
    window.portal.data = 0;
    unk_86F2EC = 0;
    unk_86F2E8 = 0;
    unk_86F2E4 = 128;
    dword_86F2F4 = 0;
    unk_86F300 = 0;
    unk_86F2FC = 0;
    unk_86F2F8 = 128;
    stru_86F304.data = 0;
    stru_86F304.sizeOf = 0;
    stru_86F304.next_available = 0;
    stru_86F304.blocksize = 128;
    unk_86F320 = 0;
    atexit(_E274_19);
  }
  unk_86F318 = 0;
  unk_86F2F0.vertex_count_total = 0;
  Render::copy_view(&window, 0, 0);
  Render::PortalList = &window;
  Render::set_view(&unk_86F2F0, 0);
}
// 866320: using guessed type struct portal_view_type *Render::PortalList;

//----- (0054F000) --------------------------------------------------------  // acclient.c:382260
char __cdecl Render::LinkRGRCallback(bool (__cdecl *_RGRCallback)())
{
  unsigned int v1; // ecx@1
  bool (__cdecl **v2)(); // edx@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@7

  v1 = Render::m_RGRCallbacks.m_num;
  v2 = Render::m_RGRCallbacks.m_data;
  v3 = 0;
  if ( !Render::m_RGRCallbacks.m_num )
    goto LABEL_6;
  while ( Render::m_RGRCallbacks.m_data[v3] != _RGRCallback )
  {
    ++v3;
    if ( v3 >= Render::m_RGRCallbacks.m_num )
      goto LABEL_6;
  }
  if ( v3 == -1 )
  {
LABEL_6:
    if ( Render::m_RGRCallbacks.m_num < (Render::m_RGRCallbacks.m_sizeAndDeallocate & 0x7FFFFFFF) )
    {
LABEL_9:
      v2[v1] = _RGRCallback;
      ++Render::m_RGRCallbacks.m_num;
      return 1;
    }
    v4 = SmartArray<UIChildFramework *,1>::get_new_size((Render::m_RGRCallbacks.m_sizeAndDeallocate & 0x7FFFFFFF) + 1);
    if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&Render::m_RGRCallbacks, v4) )
    {
      v1 = Render::m_RGRCallbacks.m_num;
      v2 = Render::m_RGRCallbacks.m_data;
      goto LABEL_9;
    }
  }
  return 1;
}

//----- (0054F070) --------------------------------------------------------  // acclient.c:382300
int __stdcall Render::Set3DViewInternal(int _x, int _y, int _width, int _height)
{
  ((void (__stdcall *)(_DWORD))Render::m_pRenderer->vfptr->SetFOVInternal)(LODWORD(Render::fov));
  Render::check_selection = 0;
  Render::check_curr_object_polys = 0;
  Render::m_MouseSelectData.bFoundPolygon = 0;
  byte_86B1A8 = 0;
  Render::set_default_view();
  return 1;
}
// 81EC78: using guessed type float Render::fov;
// 866339: using guessed type bool Render::check_curr_object_polys;
// 86633A: using guessed type bool Render::check_selection;
// 86B190: using guessed type struct Render::MouseSelectData Render::m_MouseSelectData;
// 86B1A8: using guessed type char byte_86B1A8;

//----- (00692BD0) --------------------------------------------------------  // acclient.c:682470
char __thiscall SmartArray<UIElement *,1>::RemoveUnOrdered(SmartArray<bool (__cdecl*)(void),1> *this, bool (__cdecl *const *i_rData)())
{
  unsigned int v2; // edx@1
  bool (__cdecl **v3)(); // esi@1
  bool (__cdecl **v4)(); // eax@1
  char result; // al@4
  unsigned int v6; // edx@5

  v2 = this->m_num;
  v3 = this->m_data;
  v4 = this->m_data;
  if ( this->m_data >= &this->m_data[v2] )
  {
LABEL_4:
    result = 0;
  }
  else
  {
    while ( *v4 != *i_rData )
    {
      ++v4;
      if ( v4 >= &this->m_data[this->m_num] )
        goto LABEL_4;
    }
    v6 = v2 - 1;
    this->m_num = v6;
    *v4 = v3[v6];
    this->m_data[this->m_num] = 0;
    result = 1;
  }
  return result;
}

//----- (00705890) --------------------------------------------------------  // acclient.c:792884
int sub_705890()
{
  return atexit(nullsub_1228);
}

//----- (007058A0) --------------------------------------------------------  // acclient.c:792890
int _E4_2()
{
  return atexit(_E5_2);
}

//----- (007058B0) --------------------------------------------------------  // acclient.c:792896
int _E7_2()
{
  Outside_CellID_2.id = Invalid_CellID_2.id + 1;
  return atexit(_E8_2);
}

//----- (007058D0) --------------------------------------------------------  // acclient.c:792903
int _E10_1()
{
  In_Limbo_CellID_1.id = Outside_CellID_2.id + 1;
  return atexit(_E11_1);
}

//----- (007058F0) --------------------------------------------------------  // acclient.c:792910
int _E13_1()
{
  First_Interior_CellID_1.id = In_Limbo_CellID_1.id + 1;
  return atexit(_E14_1);
}

//----- (00705910) --------------------------------------------------------  // acclient.c:792917
int _E16_1()
{
  Last_Interior_CellID_1.id = Invalid_CellID_2.id - 1;
  return atexit(_E17_1);
}

//----- (00705930) --------------------------------------------------------  // acclient.c:792924
int _E21_3()
{
  return atexit(_E22_3);
}

//----- (00705940) --------------------------------------------------------  // acclient.c:792930
int _E40_1()
{
  return atexit(_E41_1);
}

//----- (00705950) --------------------------------------------------------  // acclient.c:792936
int _E43_2()
{
  return atexit(_E44_2);
}

//----- (00705960) --------------------------------------------------------  // acclient.c:792942
int _E73_98()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_27, "Display.Resolution");
  return atexit(_E74_73);
}

//----- (00705980) --------------------------------------------------------  // acclient.c:792949
int _E76_59()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_27, "Display.FullScreen");
  return atexit(_E77_87);
}

//----- (007059A0) --------------------------------------------------------  // acclient.c:792956
int _E79_53()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_27, "Display.RefreshRate");
  return atexit(_E80_52);
}

//----- (007059C0) --------------------------------------------------------  // acclient.c:792963
int _E82_34()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_27, "Display.SyncToRefresh");
  return atexit(_E83_32);
}

//----- (007059E0) --------------------------------------------------------  // acclient.c:792970
void _E101_33()
{
  LODWORD(dword_86B188) = 1053364187;
}

//----- (007059F0) --------------------------------------------------------  // acclient.c:792976
void sub_7059F0()
{
  flt_86B120 = 1000.0 + 1.0;
}

//----- (00705A10) --------------------------------------------------------  // acclient.c:792982
void _E105_43()
{
  flt_86B174 = 24.0 * 8.0;
}

//----- (00705A30) --------------------------------------------------------  // acclient.c:792988
void _E107_32()
{
  flt_86B100 = 24.0 * 0.5;
}

//----- (00705A50) --------------------------------------------------------  // acclient.c:792994
void _E109_68()
{
  PixelFormatDesc::PixelFormatDesc(&stru_86B124, PFID_A8R8G8B8);
}

//----- (00705A60) --------------------------------------------------------  // acclient.c:793000
int _E111_46()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_34, "Render.TextureFiltering");
  return atexit(sub_7713B0);
}

//----- (00705A80) --------------------------------------------------------  // acclient.c:793007
int _E114_56()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_34, "Render.LandscapeDetailTextures");
  return atexit(sub_7713E0);
}

//----- (00705AA0) --------------------------------------------------------  // acclient.c:793014
int _E117_64()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_34, "Render.BuildingDetailTextures");
  return atexit(sub_771410);
}

//----- (00705AC0) --------------------------------------------------------  // acclient.c:793021
int _E120_62()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_34, "Render.FieldOfView");
  return atexit(sub_771440);
}

//----- (00705AE0) --------------------------------------------------------  // acclient.c:793028
int _E123_40()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_34, "Render.LandscapeTextureDetail");
  return atexit(sub_771470);
}

//----- (00705B00) --------------------------------------------------------  // acclient.c:793035
int _E126_46()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_34, "Render.EnvironmentTextureDetail");
  return atexit(sub_7714A0);
}

//----- (00705B20) --------------------------------------------------------  // acclient.c:793042
int _E129_38()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_34, "Render.SceneryDrawDistance");
  return atexit(sub_7714D0);
}

//----- (00705B40) --------------------------------------------------------  // acclient.c:793049
int _E132_41()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_34, "Render.LandscapeDrawDistance");
  return atexit(sub_771500);
}

//----- (00705B60) --------------------------------------------------------  // acclient.c:793056
int _E135_44()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_34, "Render.ScreenBrightness");
  return atexit(_E136_83);
}

//----- (00705B80) --------------------------------------------------------  // acclient.c:793063
int _E138_36()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_34, "Render.AspectRatio");
  return atexit(_E139_83);
}

//----- (00705BA0) --------------------------------------------------------  // acclient.c:793070
int _E141_36()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_34, "Render.DisplayAdapter");
  return atexit(_E142_78);
}

//----- (00705BC0) --------------------------------------------------------  // acclient.c:793077
int _E144_35()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_34, "Render.MaxHardwareClass");
  return atexit(_E145_80);
}

//----- (00705BE0) --------------------------------------------------------  // acclient.c:793084
int _E147_33()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_34, "Render.AutomaticDegrades");
  return atexit(_E148_76);
}

//----- (00705C00) --------------------------------------------------------  // acclient.c:793091
int _E150_33()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_34, "Render.GraphicsPerformance");
  return atexit(_E151_74);
}

//----- (00705C20) --------------------------------------------------------  // acclient.c:793098
int _E153_31()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_34, "Render.DegradeDistance");
  return atexit(_E154_75);
}

//----- (00705C40) --------------------------------------------------------  // acclient.c:793105
int _E156_33()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_34, "Render.MultiPassAlpha");
  return atexit(_E157_71);
}

//----- (00705C60) --------------------------------------------------------  // acclient.c:793112
int _E159_31()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_34, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_86F298, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_86F29C, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_86F2A0, "Anisotropic");
  return atexit(_E160_74);
}

//----- (00705CB0) --------------------------------------------------------  // acclient.c:793122
int _E162_33()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_34, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_86B214, "Low");
  PStringBase<char>::PStringBase<char>(&stru_86B218, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_86B21C, "High");
  PStringBase<char>::PStringBase<char>(&stru_86B220, "VeryHigh");
  return atexit(_E163_67);
}

//----- (00705D10) --------------------------------------------------------  // acclient.c:793133
int _E165_29()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_34, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_867274, "Low");
  PStringBase<char>::PStringBase<char>(&stru_867278, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_86727C, "High");
  PStringBase<char>::PStringBase<char>(&stru_867280, "VeryHigh");
  return atexit(_E166_69);
}

//----- (00705D70) --------------------------------------------------------  // acclient.c:793144
int _E168_30()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_34, "Low");
  PStringBase<char>::PStringBase<char>(&stru_86B10C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_86B110, "High");
  return atexit(_E169_68);
}

//----- (00705DB0) --------------------------------------------------------  // acclient.c:793153
int _E171_29()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_34, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_86F2A8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_86F2AC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_86F2B0, "High");
  PStringBase<char>::PStringBase<char>(&stru_86F2B4, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_86F2B8, "Extreme");
  return atexit(_E172_66);
}

//----- (00705E20) --------------------------------------------------------  // acclient.c:793165
int _E174_30()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_34, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_86B168, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_86B16C, "Wide");
  return atexit(_E175_63);
}

//----- (00705E60) --------------------------------------------------------  // acclient.c:793174
int _E177_28()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_58, "None");
  return atexit(_E178_63);
}

//----- (00705E80) --------------------------------------------------------  // acclient.c:793181
int _E180_28()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_58, "Speed");
  return atexit(_E181_63);
}

//----- (00705EA0) --------------------------------------------------------  // acclient.c:793188
int _E183_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_58, "Noise");
  return atexit(_E184_60);
}

//----- (00705EC0) --------------------------------------------------------  // acclient.c:793195
int _E186_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_58, "Sine");
  return atexit(_E187_59);
}

//----- (00705EE0) --------------------------------------------------------  // acclient.c:793202
int _E189_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_58, "Square");
  return atexit(_E190_60);
}

//----- (00705F00) --------------------------------------------------------  // acclient.c:793209
int _E192_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_58, "Bounce");
  return atexit(_E193_48);
}

//----- (00705F20) --------------------------------------------------------  // acclient.c:793216
int _E195_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_58, "Perlin");
  return atexit(_E196_55);
}

//----- (00705F40) --------------------------------------------------------  // acclient.c:793223
int _E198_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_58, "Fractal");
  return atexit(_E199_47);
}

//----- (00705F60) --------------------------------------------------------  // acclient.c:793230
int _E201_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_58, "FrameLoop");
  return atexit(_E202_48);
}

//----- (00705F80) --------------------------------------------------------  // acclient.c:793237
void _E204_13()
{
  flt_866454 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00705FA0) --------------------------------------------------------  // acclient.c:793243
void _E206_5()
{
  dbl_86B1E0 = 1.0 / 30.0;
}

//----- (00705FC0) --------------------------------------------------------  // acclient.c:793249
void _E208_18()
{
  dbl_86B0F0 = 1.0 / 5.0;
}

//----- (00705FE0) --------------------------------------------------------  // acclient.c:793255
int _E210_13()
{
  return atexit(_E211_43);
}

//----- (00705FF0) --------------------------------------------------------  // acclient.c:793261
int _E213_9()
{
  return atexit(_E214_45);
}

//----- (00706000) --------------------------------------------------------  // acclient.c:793267
int _E216_11()
{
  return atexit(_E217_41);
}

//----- (00706010) --------------------------------------------------------  // acclient.c:793273
int _E219_8()
{
  _UNKNOWN *v0; // esi@1
  signed int v1; // ebx@1

  v0 = &unk_8664C0;
  v1 = 10;
  do
  {
    *((_DWORD *)v0 - 17) = &Position::vftable;
    *((_DWORD *)v0 - 16) = 0;
    *((_DWORD *)v0 - 15) = 1065353216;
    *((_DWORD *)v0 - 14) = 0;
    *((_DWORD *)v0 - 13) = 0;
    *((_DWORD *)v0 - 12) = 0;
    *((_DWORD *)v0 - 2) = 0;
    *((_DWORD *)v0 - 1) = 0;
    *(_DWORD *)v0 = 0;
    Frame::cache((Frame *)((char *)v0 - 60));
    v0 = (char *)v0 + 360;
    --v1;
  }
  while ( v1 );
  return atexit(_E220_40);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00706070) --------------------------------------------------------  // acclient.c:793301
int _E222_7()
{
  return atexit(_E223_40);
}

//----- (00706080) --------------------------------------------------------  // acclient.c:793307
int _E229_13()
{
  ClipPlaneList::ClipPlaneList(&simple_clip_plane_list);
  return atexit(_E230_16);
}

//----- (007060A0) --------------------------------------------------------  // acclient.c:793314
int _E232_13()
{
  Frame::cache(&simple_clip_plane_list_frame);
  return atexit(_E233_15);
}

//----- (007060C0) --------------------------------------------------------  // acclient.c:793321
float _E235_13()
{
  const float result; // eax@1

  result = IDEAL_OBJECT_SORT_DISTANCE;
  Render::object_distance_2dsq = IDEAL_OBJECT_SORT_DISTANCE;
  return result;
}
// 866404: using guessed type float Render::object_distance_2dsq;

//----- (007060D0) --------------------------------------------------------  // acclient.c:793332
float _E237_6()
{
  const float result; // eax@1

  result = IDEAL_PARTICLE_SORT_DISTANCE;
  Render::particle_distance_2dsq = IDEAL_PARTICLE_SORT_DISTANCE;
  return result;
}
// 86B1F8: using guessed type float Render::particle_distance_2dsq;

//----- (007060E0) --------------------------------------------------------  // acclient.c:793343
int _E239_0()
{
  LightParms::LightParms(&Render::world_lights);
  return atexit(_E240_7);
}

//----- (00706100) --------------------------------------------------------  // acclient.c:793350
int _E242_0()
{
  LightParms::LightParms(&Render::viewer_lights);
  return atexit(_E243_7);
}

//----- (00706120) --------------------------------------------------------  // acclient.c:793357
int _E245_0()
{
  Frame::cache(&stru_81EF08);
  return atexit(_E246_7);
}

//----- (00706140) --------------------------------------------------------  // acclient.c:793364
int _E248_0()
{
  return atexit(_E249_7);
}

//----- (00706150) --------------------------------------------------------  // acclient.c:793370
int _E251_0()
{
  Frame::cache(&stru_81EF50);
  return atexit(_E252_7);
}

//----- (00706170) --------------------------------------------------------  // acclient.c:793377
int _E260_0()
{
  return atexit(_E261_5);
}

//----- (00771200) --------------------------------------------------------  // acclient.c:904961
void __cdecl _E230_16()
{
  ClipPlaneList::~ClipPlaneList(&simple_clip_plane_list);
}

//----- (00771220) --------------------------------------------------------  // acclient.c:904967
void __cdecl _E246_7()
{
  Render::viewer_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00771240) --------------------------------------------------------  // acclient.c:904974
void __cdecl _E252_7()
{
  Render::player_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 81EF48: using guessed type struct Position Render::player_pos;

//----- (007712F0) --------------------------------------------------------  // acclient.c:904982
void __cdecl _E74_73()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771320) --------------------------------------------------------  // acclient.c:904995
void __cdecl _E77_87()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771350) --------------------------------------------------------  // acclient.c:905008
void __cdecl _E80_52()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771380) --------------------------------------------------------  // acclient.c:905021
void __cdecl _E83_32()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007713B0) --------------------------------------------------------  // acclient.c:905034
void __cdecl sub_7713B0()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007713E0) --------------------------------------------------------  // acclient.c:905047
void __cdecl sub_7713E0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771410) --------------------------------------------------------  // acclient.c:905060
void __cdecl sub_771410()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771440) --------------------------------------------------------  // acclient.c:905073
void __cdecl sub_771440()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771470) --------------------------------------------------------  // acclient.c:905086
void __cdecl sub_771470()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007714A0) --------------------------------------------------------  // acclient.c:905099
void __cdecl sub_7714A0()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007714D0) --------------------------------------------------------  // acclient.c:905112
void __cdecl sub_7714D0()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771500) --------------------------------------------------------  // acclient.c:905125
void __cdecl sub_771500()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771530) --------------------------------------------------------  // acclient.c:905138
void __cdecl _E136_83()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771560) --------------------------------------------------------  // acclient.c:905151
void __cdecl _E139_83()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771590) --------------------------------------------------------  // acclient.c:905164
void __cdecl _E142_78()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007715C0) --------------------------------------------------------  // acclient.c:905177
void __cdecl _E145_80()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007715F0) --------------------------------------------------------  // acclient.c:905190
void __cdecl _E148_76()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771620) --------------------------------------------------------  // acclient.c:905203
void __cdecl _E151_74()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771650) --------------------------------------------------------  // acclient.c:905216
void __cdecl _E154_75()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771680) --------------------------------------------------------  // acclient.c:905229
void __cdecl _E157_71()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007716B0) --------------------------------------------------------  // acclient.c:905242
void __cdecl _E160_74()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_34;
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

//----- (007716F0) --------------------------------------------------------  // acclient.c:905267
void __cdecl _E163_67()
{
  char *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (char *)&unk_86B224;
  v1 = 5;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
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

//----- (00771730) --------------------------------------------------------  // acclient.c:905292
void __cdecl _E166_69()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &Render_EnvironmentTextureDetail_34;
  v1 = 5;
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

//----- (00771770) --------------------------------------------------------  // acclient.c:905317
void __cdecl _E169_68()
{
  struct Vector3 *v0; // edi@1
  signed int v1; // ebp@1
  float v2; // esi@2
  int v3; // esi@2

  v0 = &Render::local_object_center;
  v1 = 3;
  do
  {
    v2 = v0[-1].z;
    v0 = (struct Vector3 *)((char *)v0 - 4);
    v3 = LODWORD(v2) - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}
// 86B114: using guessed type struct Vector3 Render::local_object_center;

//----- (007717B0) --------------------------------------------------------  // acclient.c:905343
void __cdecl _E172_66()
{
  bool *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &Current_Render_EnvironmentDetailTextures;
  v1 = 6;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
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

//----- (007717F0) --------------------------------------------------------  // acclient.c:905368
void __cdecl _E175_63()
{
  IDClass<_tagCellID,16,65535> *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &Outside_CellID_2;
  v1 = 3;
  do
  {
    v2 = *(_DWORD *)&v0[-2].id;
    v0 -= 2;
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

//----- (00771830) --------------------------------------------------------  // acclient.c:905393
void __cdecl _E178_63()
{
  char *v0; // esi@1

  v0 = &waveform_None_58.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_58.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771860) --------------------------------------------------------  // acclient.c:905406
void __cdecl _E181_63()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_58.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_58.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771890) --------------------------------------------------------  // acclient.c:905419
void __cdecl _E184_60()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_58.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_58.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007718C0) --------------------------------------------------------  // acclient.c:905432
void __cdecl _E187_59()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_58.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_58.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007718F0) --------------------------------------------------------  // acclient.c:905445
void __cdecl _E190_60()
{
  char *v0; // esi@1

  v0 = &waveform_Square_58.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_58.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771920) --------------------------------------------------------  // acclient.c:905458
void __cdecl _E193_48()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_58.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_58.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771950) --------------------------------------------------------  // acclient.c:905471
void __cdecl _E196_55()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_58.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_58.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771980) --------------------------------------------------------  // acclient.c:905484
void __cdecl _E199_47()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_58.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_58.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007719B0) --------------------------------------------------------  // acclient.c:905497
void __cdecl _E202_48()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_58.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_58.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007719E0) --------------------------------------------------------  // acclient.c:905510
void __cdecl _E220_40()
{
  PStringBase<char> *v0; // eax@1
  signed int v1; // ecx@1

  v0 = &waveform_Sine_58;
  v1 = 10;
  do
  {
    v0 -= 90;
    --v1;
    v0->m_charbuffer = (PSRefBufferCharData<char> *)&PackObj::vftable;
  }
  while ( v1 );
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00771A20) --------------------------------------------------------  // acclient.c:905528
void __cdecl _E261_5()
{
  if ( (Render::m_RGRCallbacks.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](Render::m_RGRCallbacks.m_data);
}

//----- (00771A40) --------------------------------------------------------  // acclient.c:905535
void __cdecl _E274_19()
{
  DArray<view_vertex>::~DArray<view_vertex>(&stru_86F304);
  operator delete[](dword_86F2F4);
  dword_86F2F4 = 0;
  operator delete[](window.portal.data);
  window.portal.data = 0;
}

