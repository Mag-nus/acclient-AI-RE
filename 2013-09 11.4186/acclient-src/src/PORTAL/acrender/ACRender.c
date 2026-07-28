/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ACRender
   Object     : PORTAL\acrender\ACRender.obj
   Functions  : 96
   Addresses  : 006B61E0 - 00791910 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B61E0) --------------------------------------------------------  // acclient.c:719915
signed int __thiscall Plane::which_side2(Plane *this, AC1Legacy::Vector3 *v, float bias, float epsilon)
{
  double v4; // st7@1
  signed int result; // eax@2

  v4 = v->z * this->N.z + v->y * this->N.y + v->x * this->N.x + this->d + bias;
  if ( v4 <= epsilon )
  {
    result = 1;
    if ( v4 >= -epsilon )
      result = 2;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006B6230) --------------------------------------------------------  // acclient.c:719935
char __cdecl ACRender::get_alpha_for_z(const float zdist)
{
  unsigned __int64 v1; // rax@3

  if ( zdist < 10.0 )
  {
    LOBYTE(v1) = -1;
  }
  else if ( zdist <= 50.0 )
  {
    v1 = (unsigned __int64)((1.0 - (zdist - 10.0) * MY_MAX_MINUS_MIN_OO) * 255.0);
  }
  else
  {
    LOBYTE(v1) = 0;
  }
  return v1;
}

//----- (006B6280) --------------------------------------------------------  // acclient.c:719955
void __cdecl ACRender::SetDetailSurfaceInternal(int detail_stage)
{
  ImgTex *v1; // eax@1
  ImgTex *v2; // ecx@1
  IDirect3DTexture9 *v3; // eax@1

  v1 = CSurface::GetTextureMap(Render::curr_detail_surface);
  v2 = v1;
  Render::curr_texture_is_set = v1 != 0;
  v3 = 0;
  if ( v2 )
    v3 = ImgTex::GetD3DTexture(v2);
  RenderDeviceD3D::SetStageTexture((RenderDeviceD3D *)RenderDevice::render_device, detail_stage, v3);
  RenderDeviceD3D::SetSamplerAddressMode(
    (RenderDeviceD3D *)RenderDevice::render_device,
    detail_stage,
    TEXADDRESS_WRAP,
    TEXADDRESS_WRAP);
  RenderDeviceD3D::SetSamplerFilterMode(
    (RenderDeviceD3D *)RenderDevice::render_device,
    detail_stage,
    TEXFILTER_LINEAR,
    TEXFILTER_LINEAR,
    TEXFILTER_LINEAR);
  if ( !detail_stage )
  {
    RenderDeviceD3D::SetBlendFunction(
      (RenderDeviceD3D *)RenderDevice::render_device,
      Render::curr_detail_src_blend,
      Render::curr_detail_dst_blend,
      BLENDOP_ADD);
    RenderDeviceD3D::SetAlphaBlendEnable((RenderDeviceD3D *)RenderDevice::render_device, 1);
    RenderDeviceD3D::SetDepthBufferMode((RenderDeviceD3D *)RenderDevice::render_device, DEPTHTEST_LESSEQUAL, 1);
  }
}
// 866378: using guessed type int Render::curr_texture_is_set;

//----- (006B6320) --------------------------------------------------------  // acclient.c:719993
void __cdecl ACRender::landPolyDraw(CPolygon *p)
{
  int v1; // edi@2
  int v2; // esi@8
  CPolygon *v3; // ebx@10
  char *v4; // edi@12
  CVertex *v5; // esi@13
  struct RGBColor *v6; // ecx@13
  int v7; // ebp@13
  unsigned __int64 v8; // rax@15
  unsigned __int16 v9; // cx@20
  bool v10; // zf@20
  int v11; // eax@20
  char *v12; // ecx@21
  int v13; // eax@24
  char *v14; // edi@25
  CVertex *v15; // esi@26
  struct RGBColor *v16; // ebp@26
  char *v17; // ecx@27
  signed int v18; // edi@32
  char *v19; // esi@33
  unsigned __int64 v20; // rax@36
  char green; // [sp+12h] [bp-Eh]@13
  char blue; // [sp+13h] [bp-Dh]@13
  int iq; // [sp+14h] [bp-Ch]@4
  int iqa; // [sp+14h] [bp-Ch]@11
  float v25; // [sp+18h] [bp-8h]@13
  int v26; // [sp+18h] [bp-8h]@24
  char pa; // [sp+24h] [bp+4h]@13
  float pb; // [sp+24h] [bp+4h]@34

  Render::CalcObjectMatrix();
  if ( ignore_clipmap )
    v1 = 1;
  else
    v1 = ~(unsigned __int8)(Render::curr_surface->type >> 2) & 1;
  iq = v1;
  v2 = trysinglepass_0
    && RenderDevice::render_device->m_caps.bCanDoSinglePassDetailing
    && Render::curr_detail_surface
    && v1;
  v3 = p;
  D3DPolyRender::SetSurface(p, 0, v2);
  RenderDeviceD3D::SetFFLighting((RenderDeviceD3D *)RenderDevice::render_device, 0);
  if ( v2 )
  {
    ACRender::SetDetailSurfaceInternal(1);
    (*(void (__stdcall **)(_DWORD, signed int))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                              + 356))(
      LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
      578);
    iqa = 0;
    if ( p->num_pts )
    {
      v4 = (char *)&v_3[0].y;
      do
      {
        v5 = v3->vertices[iqa];
        *((_DWORD *)v4 - 1) = LODWORD(v5->x);
        v6 = ACRender::curLandBlockVertexLighting;
        *(_DWORD *)v4 = LODWORD(v5->y);
        *((float *)v4 + 1) = v5->z - zFightTerrainAdjust;
        v7 = (int)&v6[LOWORD(v5->reserve4)];
        pa = (unsigned __int64)(*(float *)v7 * 255.0);
        green = (unsigned __int64)(*(float *)(v7 + 4) * 255.0);
        blue = (unsigned __int64)(*(float *)(v7 + 8) * 255.0);
        v25 = PrimD3DRender::xformStart((AC1Legacy::Vector3 *)v5, 0)->zw;
        if ( v25 < 10.0 )
        {
          LOBYTE(v8) = -1;
        }
        else if ( v25 <= 50.0 )
        {
          v8 = (unsigned __int64)((1.0 - (v25 - 10.0) * MY_MAX_MINUS_MIN_OO) * 255.0);
        }
        else
        {
          LOBYTE(v8) = 0;
        }
        if ( overrideColor )
          v8 = (unsigned __int64)((double)(unsigned __int8)v8 * 0.8500000000000001);
        HIBYTE(v9) = v8;
        LOBYTE(v9) = pa;
        v10 = Render::curr_texture_is_set == 0;
        v11 = iqa;
        *((_DWORD *)v4 + 2) = (unsigned __int8)blue | (((unsigned __int8)green | (v9 << 8)) << 8);
        if ( !v10 )
        {
          v12 = Render::UVIndexTbl;
          *((float *)v4 + 3) = Render::TextureUSize * *(float *)(v5->reserve5 + 8 * Render::UVIndexTbl[iqa]);
          *((float *)v4 + 4) = Render::TextureVSize * *(float *)(v5->reserve5 + 8 * v12[iqa] + 4);
          *((float *)v4 + 5) = Render::curr_detail_tiling * *((float *)v4 + 3);
          *((float *)v4 + 6) = Render::curr_detail_tiling * *((float *)v4 + 4);
        }
        v4 += 32;
        ++iqa;
      }
      while ( v11 + 1 < v3->num_pts );
    }
    RenderDeviceD3D::DrawPrimitiveUP(D3DPT_TRIANGLELIST, 1u, v_3, 0x20u);
  }
  else
  {
    (*(void (__stdcall **)(_DWORD, signed int))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                              + 356))(
      LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
      322);
    v13 = 0;
    v26 = 0;
    if ( p->num_pts )
    {
      v14 = (char *)&v_2[0].y;
      do
      {
        v15 = v3->vertices[v13];
        *((_DWORD *)v14 - 1) = LODWORD(v15->x);
        *(_DWORD *)v14 = LODWORD(v15->y);
        *((float *)v14 + 1) = v15->z - zFightTerrainAdjust;
        v16 = &ACRender::curLandBlockVertexLighting[LOWORD(v15->reserve4)];
        v10 = Render::curr_texture_is_set == 0;
        *((_DWORD *)v14 + 2) = (unsigned __int8)(unsigned __int64)(v16->b * 255.0) | (((unsigned __int8)(unsigned __int64)(v16->g * 255.0) | (((unsigned __int8)(unsigned __int64)(v16->r * 255.0) | 0xFFFFFF00) << 8)) << 8);
        if ( !v10 )
        {
          v17 = Render::UVIndexTbl;
          *((float *)v14 + 3) = Render::TextureUSize * *(float *)(v15->reserve5 + 8 * Render::UVIndexTbl[v26]);
          *((float *)v14 + 4) = Render::TextureVSize * *(float *)(v15->reserve5 + 8 * v17[v26] + 4);
        }
        v3 = p;
        v13 = v26 + 1;
        v14 += 24;
        v26 = v13;
      }
      while ( v13 < p->num_pts );
      v1 = iq;
    }
    RenderDeviceD3D::DrawPrimitiveUP(D3DPT_TRIANGLELIST, 1u, v_2, 0x18u);
    if ( Render::curr_detail_surface && v1 )
    {
      ACRender::SetDetailSurfaceInternal(0);
      v18 = 0;
      if ( v3->num_pts )
      {
        v19 = (char *)&v_2[0].tu;
        do
        {
          pb = PrimD3DRender::xformStart((AC1Legacy::Vector3 *)v3->vertices[v18], 0)->zw;
          if ( pb < 10.0 )
          {
            LOBYTE(v20) = -1;
          }
          else if ( pb <= 50.0 )
          {
            v20 = (unsigned __int64)((1.0 - (pb - 10.0) * MY_MAX_MINUS_MIN_OO) * 255.0);
          }
          else
          {
            LOBYTE(v20) = 0;
          }
          v10 = Render::curr_texture_is_set == 0;
          *((_DWORD *)v19 - 1) = *((_DWORD *)v19 - 1) & 0xFFFFFF | ((unsigned __int8)v20 << 24);
          if ( !v10 )
          {
            *(float *)v19 = Render::curr_detail_tiling * *(float *)v19;
            *((float *)v19 + 1) = Render::curr_detail_tiling * *((float *)v19 + 1);
          }
          ++v18;
          v19 += 24;
        }
        while ( v18 < v3->num_pts );
      }
      RenderDeviceD3D::DrawPrimitiveUP(D3DPT_TRIANGLELIST, 1u, v_2, 0x18u);
    }
  }
}
// 81ECBC: using guessed type float Render::TextureUSize;
// 81ECC0: using guessed type float Render::TextureVSize;
// 866370: using guessed type struct CSurface *Render::curr_surface;
// 866378: using guessed type int Render::curr_texture_is_set;
// 86637C: using guessed type char *Render::UVIndexTbl;
// 8FB624: using guessed type struct RGBColor *ACRender::curLandBlockVertexLighting;

//----- (006B6760) --------------------------------------------------------  // acclient.c:720175
void __cdecl ACRender::landPolyDraw(CPolygon *p1, CPolygon *p2)
{
  int v2; // eax@2
  int v3; // esi@8
  CPolygon *v4; // edi@10
  CPolygon *v5; // ebx@11
  int v6; // esi@11
  CVertex *v7; // edi@21
  unsigned int v8; // esi@21
  struct RGBColor *v9; // ecx@21
  int v10; // ebp@21
  unsigned __int64 v11; // rax@23
  unsigned __int16 v12; // cx@28
  bool v13; // zf@28
  bool v14; // sf@30
  unsigned __int8 v15; // of@30
  CPolygon *v16; // ebx@32
  signed int v17; // ebp@32
  int v18; // esi@32
  CVertex *v19; // edi@43
  unsigned int v20; // esi@43
  struct RGBColor *v21; // ebp@43
  unsigned int v22; // ST34_4@43
  unsigned __int64 v23; // rax@43
  signed int v24; // esi@48
  unsigned __int64 v25; // rax@59
  int v26; // ecx@62
  char red; // [sp+11h] [bp-17h]@21
  char green; // [sp+12h] [bp-16h]@21
  char blue; // [sp+13h] [bp-15h]@21
  int iq2; // [sp+14h] [bp-14h]@0
  int should_draw_detail; // [sp+18h] [bp-10h]@4
  int should_draw_detaila; // [sp+18h] [bp-10h]@21
  int iq; // [sp+1Ch] [bp-Ch]@11
  int iqa; // [sp+1Ch] [bp-Ch]@32
  int iqb; // [sp+1Ch] [bp-Ch]@57
  CPolygon *p; // [sp+20h] [bp-8h]@0

  Render::CalcObjectMatrix();
  if ( ignore_clipmap_0 )
    v2 = 1;
  else
    v2 = ~(unsigned __int8)(Render::curr_surface->type >> 2) & 1;
  should_draw_detail = v2;
  v3 = trysinglepass_1
    && RenderDevice::render_device->m_caps.bCanDoSinglePassDetailing
    && Render::curr_detail_surface
    && v2;
  v4 = p1;
  D3DPolyRender::SetSurface(p1, 0, v3);
  RenderDeviceD3D::SetFFLighting((RenderDeviceD3D *)RenderDevice::render_device, 0);
  if ( v3 )
  {
    ACRender::SetDetailSurfaceInternal(1);
    (*(void (__stdcall **)(_DWORD, signed int))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                              + 356))(
      LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
      578);
    v5 = p;
    v6 = 0;
    for ( iq = 0; ; v6 = iq )
    {
      switch ( v6 )
      {
        case 0:
          v5 = v4;
          iq2 = 0;
          break;
        case 1:
          v5 = v4;
          iq2 = 1;
          break;
        case 2:
          v5 = v4;
          goto LABEL_20;
        case 3:
          v5 = p2;
          iq2 = 0;
          break;
        case 4:
          v5 = p2;
          iq2 = 1;
          break;
        case 5:
          v5 = p2;
LABEL_20:
          iq2 = 2;
          break;
        default:
          break;
      }
      v7 = v5->vertices[iq2];
      v8 = 8 * v6;
      v_5[v8 / 8].x = v7->x;
      v9 = ACRender::curLandBlockVertexLighting;
      dword_902114[v8] = LODWORD(v7->vertex.y);
      flt_902118[v8] = v7->z - zFightTerrainAdjust;
      v10 = (int)&v9[LOWORD(v7->reserve4)];
      red = (unsigned __int64)(*(float *)v10 * 255.0);
      green = (unsigned __int64)(*(float *)(v10 + 4) * 255.0);
      blue = (unsigned __int64)(*(float *)(v10 + 8) * 255.0);
      *(float *)&should_draw_detaila = PrimD3DRender::xformStart((AC1Legacy::Vector3 *)v7, 0)->zw;
      if ( *(float *)&should_draw_detaila < 10.0 )
      {
        LOBYTE(v11) = -1;
      }
      else if ( *(float *)&should_draw_detaila <= 50.0 )
      {
        v11 = (unsigned __int64)((1.0 - (*(float *)&should_draw_detaila - 10.0) * MY_MAX_MINUS_MIN_OO) * 255.0);
      }
      else
      {
        LOBYTE(v11) = 0;
      }
      if ( overrideColor_0 )
        v11 = (unsigned __int64)((double)(unsigned __int8)v11 * 0.8500000000000001);
      HIBYTE(v12) = v11;
      LOBYTE(v12) = red;
      v13 = Render::curr_texture_is_set == 0;
      dword_90211C[v8] = (unsigned __int8)blue | (((unsigned __int8)green | (v12 << 8)) << 8);
      if ( !v13 )
      {
        flt_902120[v8] = Render::TextureUSize * *(float *)(v7->reserve5 + 8 * v5->pos_uv_indices[iq2]);
        flt_902124[v8] = Render::TextureVSize * *(float *)(v7->reserve5 + 8 * v5->pos_uv_indices[iq2] + 4);
        flt_902128[v8] = Render::curr_detail_tiling * flt_902120[v8];
        flt_90212C[v8] = Render::curr_detail_tiling * flt_902124[v8];
      }
      v15 = __OFSUB__(iq + 1, 6);
      v14 = iq++ - 5 < 0;
      if ( !(v14 ^ v15) )
        break;
      v4 = p1;
    }
    RenderDeviceD3D::DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2u, v_5, 0x20u);
  }
  else
  {
    (*(void (__stdcall **)(_DWORD, signed int))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                              + 356))(
      LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
      322);
    v16 = p;
    v17 = iq2;
    v18 = 0;
    iqa = 0;
    while ( 1 )
    {
      switch ( v18 )
      {
        case 0:
          v16 = v4;
          v17 = 0;
          goto LABEL_42;
        case 1:
          v16 = v4;
          v17 = 1;
          goto LABEL_42;
        case 2:
          v16 = v4;
          goto LABEL_41;
        case 3:
          v16 = p2;
          v17 = 0;
          goto LABEL_42;
        case 4:
          v16 = p2;
          v17 = 1;
          goto LABEL_42;
        case 5:
          v16 = p2;
LABEL_41:
          v17 = 2;
LABEL_42:
          iq2 = v17;
          break;
        default:
          break;
      }
      v19 = v16->vertices[v17];
      v20 = 6 * v18;
      v_4[v20 / 6].x = v19->x;
      dword_902084[v20] = LODWORD(v19->vertex.y);
      flt_902088[v20] = v19->z - zFightTerrainAdjust;
      v21 = &ACRender::curLandBlockVertexLighting[LOWORD(v19->reserve4)];
      v22 = ((unsigned __int8)(unsigned __int64)(v21->g * 255.0) | (((unsigned int)(unsigned __int64)(v21->r * 255.0) | 0xFFFFFF00) << 8)) << 8;
      v23 = (unsigned __int64)(v21->b * 255.0);
      v17 = iq2;
      v13 = Render::curr_texture_is_set == 0;
      dword_90208C[v20] = (unsigned __int8)v23 | v22;
      if ( !v13 )
      {
        flt_902090[v20] = Render::TextureUSize * *(float *)(v19->reserve5 + 8 * v16->pos_uv_indices[iq2]);
        flt_902094[v20] = Render::TextureVSize * *(float *)(v19->reserve5 + 8 * v16->pos_uv_indices[iq2] + 4);
      }
      v18 = iqa + 1;
      v15 = __OFSUB__(iqa + 1, 6);
      v14 = iqa++ - 5 < 0;
      if ( !(v14 ^ v15) )
        break;
      v4 = p1;
    }
    RenderDeviceD3D::DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2u, v_4, 0x18u);
    if ( Render::curr_detail_surface && should_draw_detail )
    {
      ACRender::SetDetailSurfaceInternal(0);
      v24 = 0;
      do
      {
        switch ( v24 )
        {
          case 0:
            v16 = p1;
            v17 = 0;
            break;
          case 1:
            v16 = p1;
            v17 = 1;
            break;
          case 2:
            v16 = p1;
            goto LABEL_56;
          case 3:
            v16 = p2;
            v17 = 0;
            break;
          case 4:
            v16 = p2;
            v17 = 1;
            break;
          case 5:
            v16 = p2;
LABEL_56:
            v17 = 2;
            break;
          default:
            break;
        }
        *(float *)&iqb = PrimD3DRender::xformStart((AC1Legacy::Vector3 *)v16->vertices[v17], 0)->zw;
        if ( *(float *)&iqb < 10.0 )
        {
          LOBYTE(v25) = -1;
        }
        else if ( *(float *)&iqb <= 50.0 )
        {
          v25 = (unsigned __int64)((1.0 - (*(float *)&iqb - 10.0) * MY_MAX_MINUS_MIN_OO) * 255.0);
        }
        else
        {
          LOBYTE(v25) = 0;
        }
        v26 = 6 * v24;
        dword_90208C[6 * v24] = dword_90208C[6 * v24] & 0xFFFFFF | ((unsigned __int8)v25 << 24);
        if ( Render::curr_texture_is_set )
        {
          flt_902090[v26] = Render::curr_detail_tiling * flt_902090[v26];
          flt_902094[v26] = Render::curr_detail_tiling * flt_902094[v26];
        }
        ++v24;
      }
      while ( v24 < 6 );
      RenderDeviceD3D::DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2u, v_4, 0x18u);
    }
  }
}
// 81ECBC: using guessed type float Render::TextureUSize;
// 81ECC0: using guessed type float Render::TextureVSize;
// 866370: using guessed type struct CSurface *Render::curr_surface;
// 866378: using guessed type int Render::curr_texture_is_set;
// 8FB624: using guessed type struct RGBColor *ACRender::curLandBlockVertexLighting;
// 902084: using guessed type int dword_902084[];
// 902088: using guessed type float flt_902088[];
// 90208C: using guessed type int dword_90208C[];
// 902090: using guessed type float flt_902090[];
// 902094: using guessed type float flt_902094[];
// 902114: using guessed type int dword_902114[];
// 902118: using guessed type float flt_902118[];
// 90211C: using guessed type int dword_90211C[];
// 902120: using guessed type float flt_902120[];
// 902124: using guessed type float flt_902124[];
// 902128: using guessed type float flt_902128[];
// 90212C: using guessed type float flt_90212C[];

//----- (006B6D00) --------------------------------------------------------  // acclient.c:720458
void __cdecl ACRender::polyClipFinish(Vec2Dscreen **ptsIn, int ptCount, Vec2Dscreen **ptsOut, int *ptsOutCount, int viewPtChkMask)
{
  signed int v5; // edx@3
  int v6; // ecx@3
  Vec2Dscreen **v7; // edi@3
  signed int v8; // ebp@3
  int v9; // esi@3
  view_vertex *v10; // eax@7
  view_vertex *i; // ebx@7
  Vec2Dscreen *v12; // ecx@9
  int v13; // ebp@9
  double v14; // st7@9
  int v15; // eax@9
  Vec2Dscreen *v16; // edx@10
  double v17; // st7@10
  int v18; // eax@10
  int j; // ebp@10
  Vec2Dscreen *v20; // ecx@11
  int v21; // ebx@11
  double v22; // st6@12
  int v23; // ebp@18
  Vec2Dscreen *v24; // edx@19
  int v25; // ebx@19
  double v26; // st6@23
  Vec2Dscreen *v27; // edx@33
  view_vertex *vPoly; // [sp+0h] [bp-2Ch]@3
  float vx0; // [sp+4h] [bp-28h]@9
  float vy0; // [sp+8h] [bp-24h]@9
  float ic0; // [sp+Ch] [bp-20h]@9
  int polyToggle; // [sp+10h] [bp-1Ch]@9
  Vec2Dscreen **cDstPoly; // [sp+14h] [bp-18h]@0
  float vyd; // [sp+18h] [bp-14h]@9
  float vxd; // [sp+1Ch] [bp-10h]@9
  view_vertex *vi1; // [sp+20h] [bp-Ch]@3
  view_vertex *vi1a; // [sp+20h] [bp-Ch]@7
  Vec2Dscreen **polyBuf[2]; // [sp+24h] [bp-8h]@3
  int ptCounta; // [sp+34h] [bp+8h]@11
  int ptCountb; // [sp+34h] [bp+8h]@19
  int viewPtChkMaska; // [sp+40h] [bp+14h]@3

  if ( !(_S235_1 & 1) )
    _S235_1 |= 1u;
  polyBuf[0] = ptsOut;
  vPoly = Render::portal_vertex;
  viewPtChkMaska = viewPtChkMask << (30 - Render::portal_npnts);
  v5 = ptCount;
  v6 = ptCount - 1;
  v7 = tempPtPBuf;
  v8 = 0;
  vi1 = (view_vertex *)Render::portal_npnts;
  polyBuf[1] = tempPtPBuf;
  v9 = (int)tempPtBuf;
  if ( ptCount - 1 < 0 )
  {
LABEL_6:
    v7 = (Vec2Dscreen **)viewPtChkMaska;
LABEL_7:
    v10 = vPoly;
    vi1a = &vPoly[(signed int)vi1 - 1];
    for ( i = vi1a; i >= vPoly; vi1a = i )
    {
      viewPtChkMaska *= 2;
      if ( viewPtChkMaska >= 0 )
      {
        v12 = *ptsIn;
        v13 = v8 ^ 1;
        v7 = polyBuf[v13];
        polyToggle = v13;
        vx0 = v10->pt.x;
        vy0 = v10->pt.y;
        cDstPoly = polyBuf[v13];
        vxd = i->pt.x - v10->pt.x;
        vyd = i->pt.y - vy0;
        v14 = (v12->xw - v10->pt.x * v12->w) * vyd - (v12->yw - vy0 * v12->w) * vxd;
        ic0 = v14;
        v15 = ic0 <= 0.0;
        v23 = v5 - 1;
        if ( v5 - 1 >= 0 )
        {
          do
          {
            *(float *)&ptCountb = v14;
            v24 = v12;
            v12 = ptsIn[v23];
            v25 = v15;
            if ( v23 )
              v14 = (v12->xw - vx0 * v12->w) * vyd - (v12->yw - vy0 * v12->w) * vxd;
            else
              v14 = ic0;
            v15 = v14 <= 0.0;
            if ( v15 ^ v25 )
            {
              ++v7;
              v26 = *(float *)&ptCountb / (*(float *)&ptCountb - v14);
              *(float *)v9 = (v12->xw - v24->xw) * v26 + v24->xw;
              *(float *)(v9 + 4) = (v12->yw - v24->yw) * v26 + v24->yw;
              *(float *)(v9 + 8) = (v12->zw - v24->zw) * v26 + v24->zw;
              *(float *)(v9 + 12) = (v12->w - v24->w) * v26 + v24->w;
              *(v7 - 1) = (Vec2Dscreen *)v9;
              v9 += 16;
            }
            if ( v14 <= 0.0 )
            {
              *v7 = v12;
              ++v7;
            }
            --v23;
          }
          while ( v23 >= 0 );
          i = vi1a;
        }
        v5 = v7 - cDstPoly;
        if ( v5 < 3 )
          return;
        v8 = polyToggle;
        ptsIn = cDstPoly;
      }
      v10 = i;
      --i;
    }
    *ptsOutCount = v5;
    if ( v8 && v7 > cDstPoly )
    {
      do
      {
        v27 = *(v7 - 1);
        --v7;
        *ptsOut = v27;
        ++ptsOut;
      }
      while ( v7 > cDstPoly );
    }
    return;
  }
  while ( ptsIn[v6]->w >= (double)cdstW )
  {
    --v6;
    if ( v6 < 0 )
      goto LABEL_6;
  }
  v16 = *ptsIn;
  v17 = (*ptsIn)->w - cdstW;
  cDstPoly = tempPtPBuf;
  v18 = v17 >= 0.0;
  for ( j = ptCount - 1; j >= 0; --j )
  {
    v20 = v16;
    *(float *)&ptCounta = v17;
    v16 = ptsIn[j];
    v21 = v18;
    v17 = v16->w - cdstW;
    v18 = v17 >= 0.0;
    if ( v18 ^ v21 )
    {
      ++v7;
      v22 = *(float *)&ptCounta / (*(float *)&ptCounta - v17);
      *(float *)v9 = (v16->xw - v20->xw) * v22 + v20->xw;
      *(float *)(v9 + 4) = (v16->yw - v20->yw) * v22 + v20->yw;
      *(float *)(v9 + 8) = (v16->zw - v20->zw) * v22 + v20->zw;
      *(float *)(v9 + 12) = (v16->w - v20->w) * v22 + v20->w;
      *(v7 - 1) = (Vec2Dscreen *)v9;
      v9 += 16;
    }
    if ( v17 >= 0.0 )
    {
      *v7 = v16;
      ++v7;
    }
  }
  v5 = v7 - tempPtPBuf;
  if ( v5 >= 3 )
  {
    v8 = 1;
    ptsIn = tempPtPBuf;
    goto LABEL_7;
  }
}
// 846040: using guessed type struct view_vertex *Render::portal_vertex;
// 846050: using guessed type int Render::portal_npnts;

//----- (006B7040) --------------------------------------------------------  // acclient.c:720639
void __cdecl ACRender::landPolysDraw(CPolygon **polys, int num_polys)
{
  float v2; // ebp@2
  CPolygon *v3; // esi@2
  signed int v4; // eax@2
  CPolygon *v5; // edi@2
  signed int v6; // eax@2
  int num_polysa; // [sp+8h] [bp+8h]@2

  if ( num_polys == 2 )
  {
    v2 = zFightTerrainAdjust;
    v3 = *polys;
    v4 = Plane::which_side2(&(*polys)->plane, Render::FrameCurrent, zFightTerrainAdjust, 0.00019999999);
    v5 = polys[1];
    num_polysa = v4;
    v6 = Plane::which_side2(&v5->plane, Render::FrameCurrent, v2, 0.00019999999);
    if ( num_polysa )
    {
      if ( !v6 )
        ACRender::landPolyDraw(v5);
    }
    else if ( v6 )
    {
      ACRender::landPolyDraw(v3);
    }
    else
    {
      ACRender::landPolyDraw(v3, v5);
    }
  }
}

//----- (00724120) --------------------------------------------------------  // acclient.c:821854
int sub_724120()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_40, "Display.Resolution");
  return atexit(sub_791880);
}

//----- (00724140) --------------------------------------------------------  // acclient.c:821861
int sub_724140()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_40, "Display.FullScreen");
  return atexit(sub_7918B0);
}

//----- (00724160) --------------------------------------------------------  // acclient.c:821868
int sub_724160()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_40, "Display.RefreshRate");
  return atexit(sub_7918E0);
}

//----- (00724180) --------------------------------------------------------  // acclient.c:821875
int _E82_74()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_40, "Display.SyncToRefresh");
  return atexit(_E83_70);
}

//----- (007241A0) --------------------------------------------------------  // acclient.c:821882
void _E101_51()
{
  LODWORD(dword_8FB650) = 1053364187;
}

//----- (007241B0) --------------------------------------------------------  // acclient.c:821888
void sub_7241B0()
{
  flt_8FB654 = 1000.0 + 1.0;
}

//----- (007241D0) --------------------------------------------------------  // acclient.c:821894
void _E105_65()
{
  flt_8FB658 = 24.0 * 8.0;
}

//----- (007241F0) --------------------------------------------------------  // acclient.c:821900
void _E107_53()
{
  flt_8FB65C = 24.0 * 0.5;
}

//----- (00724210) --------------------------------------------------------  // acclient.c:821906
void sub_724210()
{
  flt_8FB664 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00724230) --------------------------------------------------------  // acclient.c:821912
void _E111_68()
{
  dbl_8FB668 = 1.0 / 30.0;
}

//----- (00724250) --------------------------------------------------------  // acclient.c:821918
void _E113_34()
{
  dbl_8FB670 = 1.0 / 5.0;
}

//----- (00724270) --------------------------------------------------------  // acclient.c:821924
void sub_724270()
{
  dword_8FB678 = 1024;
}

//----- (00724280) --------------------------------------------------------  // acclient.c:821930
void sub_724280()
{
  dword_8FB67C = 0x7FFF;
}

//----- (00724290) --------------------------------------------------------  // acclient.c:821936
int _E119_52()
{
  const int result; // eax@1

  result = dword_8FB678;
  dword_8FB680 = dword_8FB678;
  return result;
}

//----- (007242A0) --------------------------------------------------------  // acclient.c:821946
void sub_7242A0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FB684, PFID_A8R8G8B8);
}

//----- (007242B0) --------------------------------------------------------  // acclient.c:821952
int _E123_56()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_50, "Render.TextureFiltering");
  return atexit(sub_791250);
}

//----- (007242D0) --------------------------------------------------------  // acclient.c:821959
int _E126_64()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_50, "Render.LandscapeDetailTextures");
  return atexit(sub_791280);
}

//----- (007242F0) --------------------------------------------------------  // acclient.c:821966
int _E129_58()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_50, "Render.BuildingDetailTextures");
  return atexit(sub_7912B0);
}

//----- (00724310) --------------------------------------------------------  // acclient.c:821973
int _E132_58()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_50, "Render.FieldOfView");
  return atexit(sub_7912E0);
}

//----- (00724330) --------------------------------------------------------  // acclient.c:821980
int _E135_66()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_50, "Render.LandscapeTextureDetail");
  return atexit(sub_791310);
}

//----- (00724350) --------------------------------------------------------  // acclient.c:821987
int _E138_52()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_50, "Render.EnvironmentTextureDetail");
  return atexit(sub_791340);
}

//----- (00724370) --------------------------------------------------------  // acclient.c:821994
int _E141_54()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_50, "Render.SceneryDrawDistance");
  return atexit(_E142_94);
}

//----- (00724390) --------------------------------------------------------  // acclient.c:822001
int _E144_50()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_50, "Render.LandscapeDrawDistance");
  return atexit(_E145_95);
}

//----- (007243B0) --------------------------------------------------------  // acclient.c:822008
int _E147_49()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_50, "Render.ScreenBrightness");
  return atexit(_E148_91);
}

//----- (007243D0) --------------------------------------------------------  // acclient.c:822015
int _E150_48()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_50, "Render.AspectRatio");
  return atexit(_E151_89);
}

//----- (007243F0) --------------------------------------------------------  // acclient.c:822022
int _E153_46()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_50, "Render.DisplayAdapter");
  return atexit(_E154_90);
}

//----- (00724410) --------------------------------------------------------  // acclient.c:822029
int _E156_48()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_50, "Render.MaxHardwareClass");
  return atexit(_E157_86);
}

//----- (00724430) --------------------------------------------------------  // acclient.c:822036
int _E159_46()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_50, "Render.AutomaticDegrades");
  return atexit(_E160_89);
}

//----- (00724450) --------------------------------------------------------  // acclient.c:822043
int _E162_49()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_50, "Render.GraphicsPerformance");
  return atexit(_E163_82);
}

//----- (00724470) --------------------------------------------------------  // acclient.c:822050
int _E165_44()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_50, "Render.DegradeDistance");
  return atexit(_E166_84);
}

//----- (00724490) --------------------------------------------------------  // acclient.c:822057
int _E168_45()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_50, "Render.MultiPassAlpha");
  return atexit(_E169_83);
}

//----- (007244B0) --------------------------------------------------------  // acclient.c:822064
int _E171_44()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_50, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8FB700, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8FB704, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8FB708, "Anisotropic");
  return atexit(_E172_81);
}

//----- (00724500) --------------------------------------------------------  // acclient.c:822074
int _E174_46()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_50, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8FB710, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8FB714, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8FB718, "High");
  PStringBase<char>::PStringBase<char>(&stru_8FB71C, "VeryHigh");
  return atexit(_E175_78);
}

//----- (00724560) --------------------------------------------------------  // acclient.c:822085
int _E177_43()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_50, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8FB724, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8FB728, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8FB72C, "High");
  PStringBase<char>::PStringBase<char>(&stru_8FB730, "VeryHigh");
  return atexit(_E178_78);
}

//----- (007245C0) --------------------------------------------------------  // acclient.c:822096
int _E180_43()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_50, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8FB738, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8FB73C, "High");
  return atexit(_E181_78);
}

//----- (00724600) --------------------------------------------------------  // acclient.c:822105
int _E183_42()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_50, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8FB744, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8FB748, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8FB74C, "High");
  PStringBase<char>::PStringBase<char>(&stru_8FB750, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8FB754, "Extreme");
  return atexit(_E184_75);
}

//----- (00724670) --------------------------------------------------------  // acclient.c:822117
int _E186_42()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_50, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8FB75C, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8FB760, "Wide");
  return atexit(_E187_74);
}

//----- (007246B0) --------------------------------------------------------  // acclient.c:822126
int _E189_41()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_87, "None");
  return atexit(_E190_75);
}

//----- (007246D0) --------------------------------------------------------  // acclient.c:822133
int _E192_32()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_87, "Speed");
  return atexit(_E193_57);
}

//----- (007246F0) --------------------------------------------------------  // acclient.c:822140
int _E195_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_87, "Noise");
  return atexit(_E196_64);
}

//----- (00724710) --------------------------------------------------------  // acclient.c:822147
int _E198_29()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_87, "Sine");
  return atexit(_E199_56);
}

//----- (00724730) --------------------------------------------------------  // acclient.c:822154
int _E201_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_87, "Square");
  return atexit(_E202_55);
}

//----- (00724750) --------------------------------------------------------  // acclient.c:822161
int _E204_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_87, "Bounce");
  return atexit(_E205_46);
}

//----- (00724770) --------------------------------------------------------  // acclient.c:822168
int _E207_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_87, "Perlin");
  return atexit(_E208_50);
}

//----- (00724790) --------------------------------------------------------  // acclient.c:822175
int _E210_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_87, "Fractal");
  return atexit(_E211_46);
}

//----- (007247B0) --------------------------------------------------------  // acclient.c:822182
int _E213_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_87, "FrameLoop");
  return atexit(_E214_48);
}

//----- (007247D0) --------------------------------------------------------  // acclient.c:822189
signed int _E218_1()
{
  signed int result; // eax@1

  result = 961656599;
  LODWORD(cdstW) = 961656599;
  return result;
}

//----- (007247E0) --------------------------------------------------------  // acclient.c:822199
void _E220_31()
{
  MY_MAX_MINUS_MIN_OO = 1.0 / (50.0 - 10.0);
}

//----- (00724800) --------------------------------------------------------  // acclient.c:822205
int _E224_1()
{
  CPolygon::CPolygon(&PolyOut);
  return atexit(_E225_9);
}

//----- (00724820) --------------------------------------------------------  // acclient.c:822212
int _E227_1()
{
  ClipPlaneList::ClipPlaneList(&ClipPlaneListObj);
  return atexit(_E228_9);
}

//----- (00724840) --------------------------------------------------------  // acclient.c:822219
int _E230_1()
{
  return atexit(_E231_9);
}

//----- (00724850) --------------------------------------------------------  // acclient.c:822225
int sub_724850()
{
  return atexit(nullsub_1441);
}

//----- (00791210) --------------------------------------------------------  // acclient.c:937289
void __cdecl _E225_9()
{
  CPolygon::Destroy(&PolyOut);
}

//----- (00791220) --------------------------------------------------------  // acclient.c:937295
void __cdecl _E228_9()
{
  ClipPlaneList::~ClipPlaneList(&ClipPlaneListObj);
}

//----- (00791250) --------------------------------------------------------  // acclient.c:937301
void __cdecl sub_791250()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791280) --------------------------------------------------------  // acclient.c:937314
void __cdecl sub_791280()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007912B0) --------------------------------------------------------  // acclient.c:937327
void __cdecl sub_7912B0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007912E0) --------------------------------------------------------  // acclient.c:937340
void __cdecl sub_7912E0()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791310) --------------------------------------------------------  // acclient.c:937353
void __cdecl sub_791310()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791340) --------------------------------------------------------  // acclient.c:937366
void __cdecl sub_791340()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791370) --------------------------------------------------------  // acclient.c:937379
void __cdecl _E142_94()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007913A0) --------------------------------------------------------  // acclient.c:937392
void __cdecl _E145_95()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007913D0) --------------------------------------------------------  // acclient.c:937405
void __cdecl _E148_91()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791400) --------------------------------------------------------  // acclient.c:937418
void __cdecl _E151_89()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791430) --------------------------------------------------------  // acclient.c:937431
void __cdecl _E154_90()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791460) --------------------------------------------------------  // acclient.c:937444
void __cdecl _E157_86()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791490) --------------------------------------------------------  // acclient.c:937457
void __cdecl _E160_89()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007914C0) --------------------------------------------------------  // acclient.c:937470
void __cdecl _E163_82()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007914F0) --------------------------------------------------------  // acclient.c:937483
void __cdecl _E166_84()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791520) --------------------------------------------------------  // acclient.c:937496
void __cdecl _E169_83()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791550) --------------------------------------------------------  // acclient.c:937509
void __cdecl _E172_81()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_50;
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

//----- (00791590) --------------------------------------------------------  // acclient.c:937534
void __cdecl _E175_78()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_50;
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

//----- (007915D0) --------------------------------------------------------  // acclient.c:937559
void __cdecl _E178_78()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_50;
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

//----- (00791610) --------------------------------------------------------  // acclient.c:937584
void __cdecl _E181_78()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_50;
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

//----- (00791650) --------------------------------------------------------  // acclient.c:937609
void __cdecl _E184_75()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_50;
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

//----- (00791690) --------------------------------------------------------  // acclient.c:937634
void __cdecl _E187_74()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_87;
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

//----- (007916D0) --------------------------------------------------------  // acclient.c:937659
void __cdecl _E190_75()
{
  char *v0; // esi@1

  v0 = &waveform_None_87.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_87.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791700) --------------------------------------------------------  // acclient.c:937672
void __cdecl _E193_57()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_87.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_87.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791730) --------------------------------------------------------  // acclient.c:937685
void __cdecl _E196_64()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_87.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_87.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791760) --------------------------------------------------------  // acclient.c:937698
void __cdecl _E199_56()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_87.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_87.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791790) --------------------------------------------------------  // acclient.c:937711
void __cdecl _E202_55()
{
  char *v0; // esi@1

  v0 = &waveform_Square_87.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_87.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007917C0) --------------------------------------------------------  // acclient.c:937724
void __cdecl _E205_46()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_87.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_87.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007917F0) --------------------------------------------------------  // acclient.c:937737
void __cdecl _E208_50()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_87.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_87.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791820) --------------------------------------------------------  // acclient.c:937750
void __cdecl _E211_46()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_87.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_87.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791850) --------------------------------------------------------  // acclient.c:937763
void __cdecl _E214_48()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_87.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_87.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791880) --------------------------------------------------------  // acclient.c:937776
void __cdecl sub_791880()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007918B0) --------------------------------------------------------  // acclient.c:937789
void __cdecl sub_7918B0()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007918E0) --------------------------------------------------------  // acclient.c:937802
void __cdecl sub_7918E0()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791910) --------------------------------------------------------  // acclient.c:937815
void __cdecl _E83_70()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

