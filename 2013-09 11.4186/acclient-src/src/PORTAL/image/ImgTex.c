/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ImgTex
   Object     : PORTAL\image\ImgTex.obj
   Functions  : 929
   Addresses  : 00415200 - 00771040 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00415200) --------------------------------------------------------  // acclient.c:81480
char __cdecl DBObj::InitLoad()
{
  return 1;
}

//----- (00526880) --------------------------------------------------------  // acclient.c:342059
signed int UIElement_Scrollbar::GetUIElementType()
{
  return 11;
}

//----- (0053E490) --------------------------------------------------------  // acclient.c:365309
unsigned int __thiscall ImgTex::get_width(ImgTex *this)
{
  RenderSurface *v1; // eax@1
  unsigned int result; // eax@2

  v1 = this->m_pImageData;
  if ( v1 )
    result = v1->width;
  else
    result = 0;
  return result;
}

//----- (0053E4B0) --------------------------------------------------------  // acclient.c:365323
unsigned int __thiscall ImgTex::get_height(ImgTex *this)
{
  RenderSurface *v1; // eax@1
  unsigned int result; // eax@2

  v1 = this->m_pImageData;
  if ( v1 )
    result = v1->height;
  else
    result = 0;
  return result;
}

//----- (0053E4D0) --------------------------------------------------------  // acclient.c:365337
char __stdcall ImgTex::CSI2TGA(char *csi_data, int csi_width, int csi_height, char *tga_data, int tga_width, int tga_height, int tga_pitch)
{
  char result; // al@3

  if ( csi_width != tga_width || csi_height != tga_height )
  {
    result = 0;
  }
  else
  {
    qmemcpy(tga_data, csi_data, 4 * ((unsigned int)(4 * tga_height * tga_width) >> 2));
    result = 1;
  }
  return result;
}

//----- (0053E510) --------------------------------------------------------  // acclient.c:365354
char *__thiscall ImgTex::GetData(ImgTex *this)
{
  ImgTex *v1; // esi@1
  RenderSurface *v2; // ecx@1
  char *result; // eax@3
  void *pData; // [sp+10h] [bp-4h]@1

  pData = this;
  v1 = this;
  v2 = this->m_pImageData;
  if ( v2
    && (unsigned __int8)((int (__stdcall *)(int, _DWORD, int, void **))v2->vfptr[4].IUnknown_QueryInterface)(
                          &v2->window.rect,
                          0,
                          &v1->m_cPitch,
                          &pData) )
  {
    result = (char *)pData;
    v1->m_IsLocked = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0053E550) --------------------------------------------------------  // acclient.c:365382
char __thiscall ImgTex::PurgeResource(ImgTex *this)
{
  ImgTex *v1; // esi@1
  char result; // al@1
  int v3; // eax@2
  unsigned int v4; // eax@5
  int v5; // ecx@7

  v1 = this;
  result = DBObj::InitLoad();
  if ( result )
  {
    v3 = *((_DWORD *)&v1->vfptr + 1);
    if ( v3 && (unsigned __int8)(*(int (**)(void))(*(_DWORD *)(v3 + 48) + 8))() )
      GraphicsResource::MarkResourceAsLost((GraphicsResource *)(*((_DWORD *)&v1->vfptr + 1) + 48));
    v4 = v1->m_FrameUsed;
    if ( v4 )
    {
      (*(void (__stdcall **)(unsigned int))(*(_DWORD *)v4 + 8))(v1->m_FrameUsed);
      v1->m_FrameUsed = 0;
    }
    v5 = *(_DWORD *)&v1->m_bIsThrashable;
    if ( v5 )
    {
      (*(void (**)(void))(*(_DWORD *)v5 + 20))();
      *(_DWORD *)&v1->m_bIsThrashable = 0;
    }
    result = 1;
  }
  return result;
}

//----- (0053E5B0) --------------------------------------------------------  // acclient.c:365415
IDirect3DTexture9 *__thiscall ImgTex::GetD3DTexture(ImgTex *this)
{
  ImgTex *v1; // esi@1
  IDirect3DTexture9 *result; // eax@3
  int v3; // edx@4
  RenderTexture *v4; // eax@6
  RenderTexture *v5; // ecx@8
  int v6; // eax@16
  RenderTexture *v7; // edx@16
  IDirect3DTexture9 *v8; // eax@18
  RenderTexture *v9; // ecx@20
  RenderTexture *v10; // ecx@22
  RenderTextureD3D *v11; // esi@24
  unsigned int TexFlags; // [sp+8h] [bp-3Ch]@12
  PixelFormatDesc PFDesc; // [sp+Ch] [bp-38h]@12

  v1 = this;
  if ( this->m_bIsLost && !this->vfptr->RestoreResource((GraphicsResource *)&this->vfptr) )
    return 0;
  v3 = HIDWORD(Timer::local_time);
  LODWORD(v1->m_TimeUsed) = LODWORD(Timer::local_time);
  HIDWORD(v1->m_TimeUsed) = v3;
  if ( RenderDevice::render_device )
    v1->m_FrameUsed = RenderDevice::render_device->m_nFrameStamp;
  v4 = v1->m_pSystemMemTexture;
  if ( !v4 || v4->m_bIsLost )
  {
LABEL_20:
    v9 = v1->m_pRenderTexture;
    if ( v9 )
    {
      ((void (*)(void))v9->vfptr->Release)();
      v1->m_pRenderTexture = 0;
    }
    v10 = v1->m_pSystemMemTexture;
    if ( v10 )
    {
      ((void (*)(void))v10->vfptr->Release)();
      v1->m_pSystemMemTexture = 0;
    }
    goto LABEL_24;
  }
  v5 = v1->m_pRenderTexture;
  if ( !v5 )
  {
LABEL_12:
    ClipPlane::ClipPlane((ClipPlane *)&PFDesc);
    PixelFormatDesc::SetFormat(&PFDesc, v1->m_pSystemMemTexture->m_PixelFormat);
    TexFlags = 0;
    if ( !((PFDesc.flags >> 2) & 1)
      && v1->m_pSystemMemTexture->m_nNumLevels == 1
      && RenderDevice::render_device[1].m_presentation.FSRefreshRate & 0x40000000 )
      TexFlags = 4;
    v6 = ((int (*)(void))RenderDevice::render_device->vfptr->CreateTexture)();
    v7 = v1->m_pSystemMemTexture;
    v1->m_pRenderTexture = (RenderTexture *)v6;
    if ( (unsigned __int8)(*(int (__thiscall **)(int, unsigned int, unsigned int, unsigned int, PixelFormatID, unsigned int))(*(_DWORD *)v6 + 88))(
                            v6,
                            v7->m_nWidth,
                            v7->m_nHeight,
                            v7->m_nNumLevels,
                            v7->m_PixelFormat,
                            TexFlags) )
    {
      if ( RenderTextureD3D::Get2DTextureD3D((RenderTextureD3D *)v1->m_pRenderTexture) )
      {
        GraphicsResource::SetResourceIsThrashable((GraphicsResource *)&v1->m_pRenderTexture->vfptr, 1);
        v1->m_pRenderTexture->m_AllowManagement = 0;
        v8 = RenderTextureD3D::Get2DTextureD3D((RenderTextureD3D *)v1->m_pSystemMemTexture);
        if ( v8 )
        {
          ((void (__stdcall *)(IDirect3DTexture9 *, _DWORD))v8->vfptr[7].QueryInterface)(v8, 0);
          if ( (unsigned __int8)((int (__stdcall *)(RenderTexture *))v1->m_pRenderTexture->vfptr[4].IUnknown_QueryInterface)(v1->m_pSystemMemTexture) )
            goto LABEL_24;
        }
      }
    }
    goto LABEL_20;
  }
  if ( v5->m_bIsLost )
  {
    if ( v5 )
    {
      ((void (*)(void))v5->vfptr->Release)();
      v1->m_pRenderTexture = 0;
    }
    goto LABEL_12;
  }
LABEL_24:
  v11 = (RenderTextureD3D *)v1->m_pRenderTexture;
  result = 0;
  if ( v11 )
    result = RenderTextureD3D::Get2DTextureD3D(v11);
  return result;
}

//----- (0053E740) --------------------------------------------------------  // acclient.c:365512
void __cdecl ImgTex::TileCSI(char *data, unsigned int dest_height, unsigned int dest_width, ImgTex *csi_tex, unsigned int tiling)
{
  ImgTex *v5; // esi@1
  RenderSurface *v6; // ecx@1
  unsigned int v7; // ebx@2
  int v8; // ecx@9
  unsigned int v9; // ecx@11
  unsigned int v10; // edx@12
  int v11; // eax@12
  char *v12; // ecx@15
  char *v13; // esi@16
  unsigned int v14; // edi@16
  unsigned int v15; // edx@17
  char *v16; // eax@17
  bool v17; // zf@22
  RenderSurface *v18; // ecx@24
  char *src; // [sp+10h] [bp-24h]@9
  int v20; // [sp+14h] [bp-20h]@14
  unsigned int src_width; // [sp+18h] [bp-1Ch]@5
  unsigned int src_height; // [sp+1Ch] [bp-18h]@4
  unsigned int v23; // [sp+20h] [bp-14h]@14
  int v24; // [sp+24h] [bp-10h]@12
  unsigned int v25; // [sp+28h] [bp-Ch]@12
  int v26; // [sp+2Ch] [bp-8h]@8
  unsigned int v27; // [sp+30h] [bp-4h]@12

  v5 = csi_tex;
  v6 = csi_tex->m_pImageData;
  if ( v6 )
    v7 = v6->height;
  else
    v7 = 0;
  src_height = v7;
  if ( v6 )
    src_width = v6->width;
  else
    src_width = 0;
  if ( v6
    && (unsigned __int8)((int (__stdcall *)(int, _DWORD, int *, int *))v6->vfptr[4].IUnknown_QueryInterface)(
                          &v6->window.rect,
                          0,
                          &csi_tex->m_cPitch,
                          &v26) )
  {
    v8 = v26;
    csi_tex->m_IsLocked = 1;
    src = (char *)v8;
  }
  else
  {
    src = 0;
  }
  v9 = tiling;
  if ( tiling > 0 )
  {
    v10 = dest_width * v7;
    v11 = 0;
    v27 = dest_width * v7;
    v24 = 0;
    v25 = tiling;
    while ( 1 )
    {
      v20 = 0;
      v23 = v9;
      do
      {
        v12 = src;
        if ( v7 > 0 )
        {
          v13 = &data[4 * (v20 + v11)];
          v14 = v7;
          do
          {
            v15 = src_width;
            v16 = v13;
            if ( src_width )
            {
              do
              {
                *(_DWORD *)v16 = *(_DWORD *)v12;
                v16 += 4;
                v12 += 4;
                --v15;
              }
              while ( v15 );
              v7 = src_height;
            }
            v13 += 4 * dest_width;
            --v14;
          }
          while ( v14 );
          v5 = csi_tex;
          v11 = v24;
          v10 = v27;
        }
        v17 = v23 == 1;
        v20 += v10;
        --v23;
      }
      while ( !v17 );
      v11 += src_width;
      v17 = v25 == 1;
      v24 = v11;
      --v25;
      if ( v17 )
        break;
      v9 = tiling;
    }
  }
  v18 = v5->m_pImageData;
  if ( v18 )
  {
    v5->m_cPitch = 0;
    ((void (*)(void))v18->vfptr[4].IUnknown_AddRef)();
    v5->m_IsLocked = 0;
  }
}

//----- (0053E870) --------------------------------------------------------  // acclient.c:365631
void __cdecl ImgTex::MergeTexture(char *data, unsigned int dest_height, unsigned int dest_width, ImgTex *csi_merge_tex, unsigned int tiling, ImgTex *alpha_map, LandDefs::Rotation rot)
{
  RenderSurface *v7; // ecx@1
  unsigned int v8; // ebx@5
  RenderSurface *v9; // eax@7
  unsigned int v10; // edi@8
  int v11; // ecx@12
  RenderSurface *v12; // ecx@14
  int v13; // ecx@16
  unsigned int v14; // ebp@19
  unsigned int v15; // eax@22
  int v16; // edx@25
  char *v17; // ecx@31
  unsigned int v18; // esi@33
  int v19; // edi@34
  int v20; // ebp@36
  unsigned int v21; // eax@37
  unsigned int v22; // edx@38
  __int16 v23; // bx@42
  bool v24; // zf@45
  int v25; // ebp@47
  unsigned int v26; // esi@49
  unsigned int v27; // eax@50
  int v28; // edi@50
  int v29; // ebx@53
  int v30; // edx@53
  RenderSurface *v31; // ecx@63
  RenderSurface *v32; // ecx@65
  char *src; // [sp+10h] [bp-34h]@12
  unsigned int src_height; // [sp+14h] [bp-30h]@2
  unsigned int src_y; // [sp+18h] [bp-2Ch]@10
  signed int scale_up_alpha; // [sp+1Ch] [bp-28h]@19
  unsigned int scale_up_alphaa; // [sp+1Ch] [bp-28h]@34
  unsigned int skip_y; // [sp+20h] [bp-24h]@34
  unsigned int skip_ya; // [sp+20h] [bp-24h]@47
  unsigned int src_width; // [sp+24h] [bp-20h]@7
  unsigned int dest_x; // [sp+28h] [bp-1Ch]@49
  char *src_line; // [sp+2Ch] [bp-18h]@47
  int v43; // [sp+30h] [bp-14h]@48
  int v44; // [sp+34h] [bp-10h]@34
  int v45; // [sp+34h] [bp-10h]@48
  int v46; // [sp+38h] [bp-Ch]@34
  unsigned int v47; // [sp+38h] [bp-Ch]@48
  int v48; // [sp+3Ch] [bp-8h]@11
  int v49; // [sp+40h] [bp-4h]@15
  char *dataa; // [sp+48h] [bp+4h]@34
  char *datab; // [sp+48h] [bp+4h]@47
  unsigned int dest_widtha; // [sp+50h] [bp+Ch]@25
  unsigned int dest_widthb; // [sp+50h] [bp+Ch]@33
  LandDefs::Rotation rota; // [sp+60h] [bp+1Ch]@25
  LandDefs::Rotation rotb; // [sp+60h] [bp+1Ch]@36

  v7 = csi_merge_tex->m_pImageData;
  if ( v7 )
    src_height = v7->height;
  else
    src_height = 0;
  if ( v7 )
    v8 = v7->width;
  else
    v8 = 0;
  v9 = alpha_map->m_pImageData;
  src_width = v8;
  if ( v9 )
    v10 = v9->width;
  else
    v10 = 0;
  src_y = 0;
  if ( v7
    && (unsigned __int8)((int (__stdcall *)(int, _DWORD, int *, int *))v7->vfptr[4].IUnknown_QueryInterface)(
                          &v7->window.rect,
                          0,
                          &csi_merge_tex->m_cPitch,
                          &v48) )
  {
    v11 = v48;
    csi_merge_tex->m_IsLocked = 1;
    src = (char *)v11;
  }
  else
  {
    src = 0;
  }
  v12 = alpha_map->m_pImageData;
  if ( v12
    && (unsigned __int8)((int (__stdcall *)(int, _DWORD, int *, int *))v12->vfptr[4].IUnknown_QueryInterface)(
                          &v12->window.rect,
                          0,
                          &alpha_map->m_cPitch,
                          &v49) )
  {
    v13 = v49;
    alpha_map->m_IsLocked = 1;
  }
  else
  {
    v13 = 0;
  }
  if ( dest_width <= v10 )
  {
    scale_up_alpha = 1;
    v14 = 1;
  }
  else
  {
    v14 = dest_width / v10;
    scale_up_alpha = dest_width / v10;
  }
  if ( dest_width >= v10 )
    v15 = 1;
  else
    v15 = v10 / dest_width;
  switch ( rot )
  {
    case 1:
      v16 = v13 + v8 - 1;
      dest_widtha = v8;
      rota = -1;
      break;
    case 2:
      v16 = src_height * v8 + v13 - 1;
      dest_widtha = -1;
      rota = -v8;
      break;
    case 3:
      v16 = v13 + v8 * (src_height - 1);
      dest_widtha = -v8;
      rota = 1;
      break;
    default:
      v16 = v13;
      dest_widtha = 1;
      rota = v8;
      break;
  }
  v17 = data;
  if ( v15 < 1 || v14 > 1 )
  {
    src_line = src;
    datab = (char *)v14;
    skip_ya = v14;
    v25 = v16;
    if ( dest_height )
    {
      v45 = v16;
      v43 = v16;
      v47 = dest_height;
      do
      {
        v26 = 0;
        dest_x = 0;
        do
        {
          v27 = *(_BYTE *)v25;
          v28 = (int)&src_line[4 * (v26 & (v8 - 1))];
          if ( v27 < 0xFF )
          {
            if ( v27 > 0x80 )
              ++v27;
            v29 = v27 * (unsigned __int8)v17[1];
            *v17 = (unsigned __int16)(v27 * (unsigned __int8)*v17 + (256 - v27) * *(_BYTE *)v28) >> 8;
            v30 = v29 + (256 - v27) * *(_BYTE *)(v28 + 1);
            v8 = src_width;
            v17[1] = BYTE1(v30);
            v26 = dest_x;
            v17[2] = (unsigned __int16)(v27 * (unsigned __int8)v17[2] + (256 - v27) * *(_BYTE *)(v28 + 2)) >> 8;
          }
          v17 += 4;
          --datab;
          if ( !datab )
          {
            v25 += dest_widtha;
            datab = (char *)scale_up_alpha;
          }
          ++v26;
          dest_x = v26;
        }
        while ( v26 < dest_height );
        ++src_y;
        if ( src_y >= src_height )
          src_y = 0;
        v16 = (int)&src[4 * v8 * src_y];
        v24 = skip_ya == 1;
        src_line = &src[4 * v8 * src_y];
        --skip_ya;
        if ( v24 )
        {
          v25 = rota + v43;
          v43 = v25;
          v45 = v25;
          skip_ya = scale_up_alpha;
        }
        else
        {
          v25 = v45;
        }
        --v47;
      }
      while ( v47 );
    }
    goto LABEL_63;
  }
  dest_widthb = v15 * dest_widtha;
  v18 = dest_height;
  if ( !dest_height )
    goto LABEL_63;
  v44 = v15 * rota;
  v19 = (int)src;
  skip_y = v16;
  v46 = 4 * v8;
  dataa = src;
  scale_up_alphaa = dest_height;
  while ( 2 )
  {
    v20 = v16;
    rotb = v18;
    do
    {
      v21 = *(_BYTE *)v20;
      if ( v21 >= 1 )
      {
        if ( v21 >= 0xFF )
          goto LABEL_44;
        if ( v21 > 0x80 )
          ++v21;
        v23 = v21 * (unsigned __int8)v17[1];
        *v17 = (unsigned __int16)(v21 * (unsigned __int8)*v17 + (256 - v21) * *(_BYTE *)v19) >> 8;
        v17[1] = (unsigned __int16)(v23 + (256 - v21) * *(_BYTE *)(v19 + 1)) >> 8;
        v22 = (v21 * (unsigned __int8)v17[2] + (256 - v21) * *(_BYTE *)(v19 + 2)) >> 8;
      }
      else
      {
        *v17 = *(_BYTE *)v19;
        v17[1] = *(_BYTE *)(v19 + 1);
        LOBYTE(v22) = *(_BYTE *)(v19 + 2);
      }
      v17[2] = v22;
LABEL_44:
      v17 += 4;
      v19 += 4;
      v20 += dest_widthb;
      --rotb;
    }
    while ( rotb );
    v19 = (int)&dataa[v46];
    v16 = v44 + skip_y;
    v24 = scale_up_alphaa == 1;
    dataa += v46;
    skip_y += v44;
    --scale_up_alphaa;
    if ( !v24 )
    {
      v18 = dest_height;
      continue;
    }
    break;
  }
LABEL_63:
  v31 = csi_merge_tex->m_pImageData;
  if ( v31 )
  {
    csi_merge_tex->m_cPitch = 0;
    ((void (*)(void))v31->vfptr[4].IUnknown_AddRef)();
    csi_merge_tex->m_IsLocked = 0;
  }
  v32 = alpha_map->m_pImageData;
  if ( v32 )
  {
    alpha_map->m_cPitch = 0;
    ((void (__fastcall *)(RenderSurface *, int))v32->vfptr[4].IUnknown_AddRef)(v32, v16);
    alpha_map->m_IsLocked = 0;
  }
}

//----- (0053EC60) --------------------------------------------------------  // acclient.c:365906
char __cdecl ImgTex::CopyIntoData(char *dst_data, int dst_pitch, ImgTex *texture, Palette *palette, bool clipmap)
{
  ImgTex *v5; // ebx@1
  RenderSurface *v6; // ecx@1
  int v7; // eax@3
  char *v8; // edi@5
  int i; // ebp@5
  RenderSurface *v10; // eax@6
  unsigned int v11; // esi@8
  RenderSurface *v12; // eax@9
  unsigned __int16 v13; // ax@11
  RenderSurface *v14; // eax@15
  RenderSurface *v15; // ecx@22
  char *v17; // [sp+Ch] [bp-Ch]@6
  int v18; // [sp+10h] [bp-8h]@2
  int src_pitch; // [sp+14h] [bp-4h]@5
  ImgTex *texturea; // [sp+24h] [bp+Ch]@5

  v5 = texture;
  v6 = texture->m_pImageData;
  if ( v6
    && (unsigned __int8)((int (__stdcall *)(int, _DWORD, int *, int *))v6->vfptr[4].IUnknown_QueryInterface)(
                          &v6->window.rect,
                          0,
                          &texture->m_cPitch,
                          &v18) )
  {
    v7 = v18;
    texture->m_IsLocked = 1;
  }
  else
  {
    v7 = 0;
  }
  v8 = dst_data;
  src_pitch = texture->m_cPitch;
  texturea = 0;
  for ( i = v7; ; i += src_pitch )
  {
    v10 = v5->m_pImageData;
    v17 = v8;
    if ( !v10 || (unsigned int)texturea >= v10->height )
      break;
    v11 = 0;
    if ( v10->pfDesc.format == 101 )
    {
      while ( 1 )
      {
        v12 = v5->m_pImageData;
        if ( !v12 || v11 >= v12->width )
          break;
        v13 = *(_WORD *)(i + 2 * v11);
        if ( clipmap && v13 < 8u )
        {
          *(_DWORD *)v8 = 0;
          v8 += 4;
          ++v11;
        }
        else
        {
          *(_DWORD *)v8 = Palette::get_color32(palette, v13);
          v8 += 4;
          ++v11;
        }
      }
    }
    else
    {
      while ( 1 )
      {
        v14 = v5->m_pImageData;
        if ( !v14 || v11 >= v14->width )
          break;
        if ( clipmap && (unsigned __int16)*(_BYTE *)(v11 + i) < 8u )
        {
          *(_DWORD *)v8 = 0;
          v8 += 4;
          ++v11;
        }
        else
        {
          *(_DWORD *)v8 = Palette::get_color32(palette, *(_BYTE *)(v11 + i));
          v8 += 4;
          ++v11;
        }
      }
    }
    v8 = &v17[dst_pitch];
    texturea = (ImgTex *)((char *)texturea + 1);
  }
  v15 = v5->m_pImageData;
  if ( v15 )
  {
    v5->m_cPitch = 0;
    ((void (*)(void))v15->vfptr[4].IUnknown_AddRef)();
    v5->m_IsLocked = 0;
  }
  return 1;
}

//----- (0053EDB0) --------------------------------------------------------  // acclient.c:366007
bool __usercall ImgTex::CreateD3DTexture@<al>(ImgTex *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>)
{
  ImgTex *v4; // esi@1
  bool result; // al@1
  RenderSurface *v6; // eax@2
  IDirect3DTexture9 *v7; // eax@4
  RenderTexture *v8; // ecx@6
  RenderTexture *v9; // ecx@8
  RenderSurface *v10; // edx@10
  unsigned int v11; // eax@11
  unsigned __int32 v12; // ebx@13
  unsigned int v13; // eax@14
  unsigned int v14; // ebp@16
  unsigned int v15; // edi@17
  signed int v16; // edi@25
  unsigned int v17; // eax@25
  char v18; // bl@31
  int v19; // eax@31
  RenderSurface *v20; // ecx@31
  PixelFormatID v21; // ecx@32
  char v22; // al@33
  RenderTexture *v23; // ecx@33
  struct IDirect3DSurface9 *v24; // ebx@34
  void **v25; // edi@39
  int v26; // edi@41
  PixelFormatID v27; // eax@43
  unsigned int v28; // edx@43
  unsigned int v29; // eax@43
  const unsigned int i; // ecx@43
  RenderTexture *v31; // ecx@47
  IDirect3DTexture9 *v32; // eax@49
  int v33; // [sp+16h] [bp-58h]@2
  int v34; // [sp+1Ah] [bp-54h]@2
  int v35; // [sp+1Eh] [bp-50h]@2
  bool fResult; // [sp+29h] [bp-45h]@39
  unsigned int width; // [sp+2Ah] [bp-44h]@13
  unsigned int NumMipLevels; // [sp+2Eh] [bp-40h]@10
  unsigned int NumMipLevelsa; // [sp+2Eh] [bp-40h]@25
  IDirect3DSurface9 *surfaceDest; // [sp+32h] [bp-3Ch]@40
  PixelFormatDesc PFDesc; // [sp+36h] [bp-38h]@33

  v4 = this;
  result = DBCache::IsRunTime();
  if ( result )
  {
    v6 = v4->m_pImageData;
    v35 = a2;
    v34 = a3;
    v33 = a4;
    if ( !v6 || v6->m_pSurfaceBits )
      return 0;
    v7 = v4->m_pD3DTexture;
    if ( v7 )
    {
      v7->vfptr->Release((IUnknown *)v4->m_pD3DTexture);
      v4->m_pD3DTexture = 0;
    }
    v8 = v4->m_pRenderTexture;
    if ( v8 )
    {
      ((void (*)(void))v8->vfptr->Release)();
      v4->m_pRenderTexture = 0;
    }
    v9 = v4->m_pSystemMemTexture;
    if ( v9 )
    {
      ((void (*)(void))v9->vfptr->Release)();
      v4->m_pSystemMemTexture = 0;
    }
    GraphicsResource::SetResourceSize((GraphicsResource *)&v4->vfptr, 0);
    v10 = v4->m_pImageData;
    NumMipLevels = (unsigned int)v4->m_pImageData;
    if ( v10 )
      v11 = v10->width;
    else
      v11 = 0;
    v12 = v11 >> ImgTex::fCurrentTextureScale;
    width = v11 >> ImgTex::fCurrentTextureScale;
    if ( v10 )
      v13 = v10->height;
    else
      v13 = 0;
    v14 = v13 >> ImgTex::fCurrentTextureScale;
    if ( ImgTex::fCurrentTextureScale )
    {
      v15 = ImgTex::min_tex_size;
      if ( v12 < ImgTex::min_tex_size )
      {
        width = ImgTex::min_tex_size;
        if ( v15 > ImgTex::get_width(v4) )
          width = ImgTex::get_width(v4);
        v12 = width;
        v10 = (RenderSurface *)NumMipLevels;
      }
      if ( v14 < v15 )
      {
        v14 = v15;
        if ( v15 > ImgTex::get_height(v4) )
          v14 = ImgTex::get_height(v4);
        v10 = (RenderSurface *)NumMipLevels;
      }
    }
    v16 = 1;
    NumMipLevelsa = 1;
    v17 = v12;
    if ( v12 <= v14 )
      v17 = v14;
    if ( v17 > 1 )
    {
      do
      {
        v17 >>= 1;
        ++v16;
      }
      while ( v17 > 1 );
      NumMipLevelsa = v16;
      if ( (unsigned int)v16 > 4 )
        NumMipLevelsa = 4;
    }
    v18 = (v10->pfDesc.flags >> 2) & 1;
    v19 = ((int (__stdcall *)(int, int, int))RenderDevice::render_device->vfptr->CreateTexture)(v33, v34, v35);
    v4->m_pSystemMemTexture = (RenderTexture *)v19;
    v20 = v4->m_pImageData;
    if ( v20 )
      v21 = v20->pfDesc.format;
    v22 = (*(int (__thiscall **)(int, PixelFormatID, unsigned int))(*(_DWORD *)v19 + 88))(v19, PFDesc.format, v14);
    v23 = v4->m_pSystemMemTexture;
    if ( !v22 )
    {
LABEL_36:
      if ( v23 )
      {
        ((void (*)(void))v23->vfptr->Release)();
        v4->m_pSystemMemTexture = 0;
      }
      return 0;
    }
    GraphicsResource::SetResourceIsThrashable((GraphicsResource *)&v23->vfptr, 0);
    v4->m_pSystemMemTexture->m_AllowManagement = 0;
    v24 = (struct IDirect3DSurface9 *)RenderTextureD3D::Get2DTextureD3D((RenderTextureD3D *)v4->m_pSystemMemTexture);
    if ( !v24 )
    {
      v23 = v4->m_pSystemMemTexture;
      goto LABEL_36;
    }
    fResult = 0;
    v25 = (void **)RenderSurfaceD3D::GetDirect3DSurface((RenderSurfaceD3D *)v4->m_pImageData);
    if ( v25
      && v24->vfptr[6].QueryInterface((IUnknown *)v24, 0, (void **)&surfaceDest) >= 0
      && (v26 = D3DXLoadSurfaceFromSurface(v25, surfaceDest, 0, 0, (struct IDirect3DSurface9 *)v25, 0, 0, 0x70005u, 0),
          surfaceDest->vfptr->Release((IUnknown *)surfaceDest),
          v26 >= 0)
      && (D3DXFilterTexture(v24, 0, -1, 0x70005u) & 0x80000000) == 0 )
    {
      fResult = 1;
      v27 = ImgTex::get_image_type(v4);
      PixelFormatDesc::PixelFormatDesc(&PFDesc, v27);
      v28 = NumMipLevelsa;
      v29 = width * v14 * (unsigned __int8)PFDesc.bitsPerPixel >> 3;
      for ( i = 0; v28; --v28 )
      {
        i += v29;
        v29 >>= 2;
      }
      GraphicsResource::SetResourceSize((GraphicsResource *)&v4->vfptr, i);
      if ( v4->m_pImageData->vfptr->PurgeResource((GraphicsResource *)&v4->m_pImageData->vfptr) )
      {
        GraphicsResource::MarkResourceAsLost((GraphicsResource *)&v4->m_pImageData->vfptr);
        return 1;
      }
    }
    else
    {
      v31 = v4->m_pSystemMemTexture;
      if ( v31 )
      {
        ((void (*)(void))v31->vfptr->Release)();
        v4->m_pSystemMemTexture = 0;
      }
      v32 = v4->m_pD3DTexture;
      if ( v32 )
      {
        v32->vfptr->Release((IUnknown *)v4->m_pD3DTexture);
        v4->m_pD3DTexture = 0;
      }
    }
    result = fResult;
  }
  return result;
}
// 53EDB0: could not find valid save-restore pair for ebx
// 53EDB0: could not find valid save-restore pair for ebp
// 53EDB0: could not find valid save-restore pair for edi
// 81E918: using guessed type unsigned __int32 ImgTex::min_tex_size;
// 845774: using guessed type enum ImageScaleType ImgTex::fCurrentTextureScale;

//----- (0053F080) --------------------------------------------------------  // acclient.c:366204
char __usercall ImgTex::RestoreResource@<al>(ImgTex *this@<ecx>, int a2@<ebp>, int a3@<edi>)
{
  ImgTex *v3; // esi@1
  int v4; // eax@2
  char result; // al@3
  char v6; // bl@4

  v3 = this;
  if ( GraphicsResource::RestoreResource((GraphicsResource *)this) && (v4 = *((_DWORD *)&v3->vfptr + 1)) != 0 )
  {
    v6 = 1;
    if ( *(_BYTE *)(v4 + 56) )
      v6 = (*(int (**)(void))(*(_DWORD *)(v4 + 48) + 12))() & 1;
    if ( !*(_DWORD *)(*((_DWORD *)&v3->vfptr + 1) + 276) )
      v6 &= ImgTex::CreateD3DTexture((ImgTex *)((char *)v3 - 48), v6, a2, a3);
    if ( v6 )
      GraphicsResource::MarkResourceAsNotLost((GraphicsResource *)v3);
    result = v6;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0053F0E0) --------------------------------------------------------  // acclient.c:366231
IDClass<_tagDataID,32,0> *__thiscall ImgTex::GetSurfaceDID(ImgTex *this, IDClass<_tagDataID,32,0> *result)
{
  ImgTex *v2; // esi@1
  IDClass<_tagDataID,32,0> *v3; // eax@3

  v2 = this;
  if ( this->m_SourceLevels.m_num == 1 )
    goto LABEL_9;
  if ( this->m_SourceLevels.m_num != 2 )
  {
    IError::ReportDataErrorFrom(this->m_DID, "Cannot get surface DID, no source levels are listed!");
    v3 = result;
    result->id = stru_8457D8.id;
    return v3;
  }
  if ( (unsigned __int8)Render::ShouldDropHighDetail() )
  {
    v3 = result;
    result->id = v2->m_SourceLevels.m_data[1].id;
  }
  else
  {
LABEL_9:
    v3 = result;
    result->id = v2->m_SourceLevels.m_data->id;
  }
  return v3;
}

//----- (0053F140) --------------------------------------------------------  // acclient.c:366261
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::~IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0> *v1; // esi@1
  HashTableData<unsigned long,ImgTex *> **v2; // eax@1

  v1 = this;
  v2 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::vftable;
  if ( v2 != this->m_aInplaceBuckets )
    operator delete[](v2);
  v1->m_buckets = 0;
  v1->m_firstInterestingBucket = 0;
  v1->m_numBuckets = 0;
  v1->m_numElements = 0;
}
// 7C9D40: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::vftable)(void *, char);

//----- (0053F170) --------------------------------------------------------  // acclient.c:366279
IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1> *__thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::scalar_deleting_destructor(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1> *v2; // esi@1
  HashTableData<unsigned __int64,ImgTex *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>Vtbl *)IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9D34: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::vftable[4])(void *, char);

//----- (0053F1B0) --------------------------------------------------------  // acclient.c:366300
IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1> *__thiscall IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::scalar_deleting_destructor(IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1> *v2; // esi@1
  HashSetData<ImgTex *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>Vtbl *)IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9D38: using guessed type int (__thiscall *IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::vftable[3])(void *, char);

//----- (0053F1F0) --------------------------------------------------------  // acclient.c:366321
IntrusiveHashTable<enum PixelFormatID,HashTableData<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0> *__thiscall IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::scalar_deleting_destructor(IntrusiveHashTable<enum PixelFormatID,HashTableData<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<enum PixelFormatID,HashTableData<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0> *v2; // esi@1
  HashTableData<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<enum PixelFormatID,HashTableData<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>Vtbl *)IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9D3C: using guessed type int (__thiscall *IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::vftable[2])(void *, char);

//----- (0053F230) --------------------------------------------------------  // acclient.c:366342
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0> *v2; // esi@1
  HashTableData<unsigned long,ImgTex *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9D40: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::vftable)(void *, char);

//----- (0053F270) --------------------------------------------------------  // acclient.c:366363
void __userpurge ImgTex::CreateFromRenderSurface_Internal(ImgTex *this@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, RenderSurface *i_pRS)
{
  ImgTex *v5; // esi@1
  RenderSurface *v6; // eax@2
  IDClass<_tagDataID,32,0> v7; // ecx@2
  QualifiedDataID *v8; // eax@3
  QualifiedDataID v9; // [sp+4h] [bp-8h]@3

  v5 = this;
  this->m_pImageData = i_pRS;
  if ( i_pRS )
  {
    ((void (*)(void))i_pRS->vfptr->AddRef)();
    v6 = v5->m_pImageData;
    v7.id = v6->m_didPalatte.id;
    if ( stru_8457D8.id == v7.id )
    {
      if ( !v6->m_pSurfaceBits )
        ImgTex::CreateD3DTexture(v5, a2, a3, a4);
    }
    else
    {
      QualifiedDataID::QualifiedDataID(&v9, v7, 0xAu);
      v5->m_pPalette = (Palette *)DBObj::Get(v8);
    }
  }
}

//----- (0053F2D0) --------------------------------------------------------  // acclient.c:366392
void __cdecl ImgTex::CopyCSI(char *data, unsigned int height, unsigned int width, ImgTex *csi_tex, unsigned int tiling)
{
  if ( csi_tex )
  {
    ImgTex::TileCSI(data, height, width, csi_tex, tiling);
  }
  else if ( width * height )
  {
    memset32(data, 65280, width * height);
  }
}

//----- (0053F300) --------------------------------------------------------  // acclient.c:366405
char __userpurge ImgTex::Load@<al>(ImgTex *this@<ecx>, int a2@<ebx>, int a3@<ebp>, ImgTex *texture)
{
  ImgTex *v4; // edi@1
  RenderSurface *v5; // ecx@1
  PixelFormatID v6; // esi@2
  RenderSurface *v7; // edx@4
  PixelFormatID v8; // eax@5
  unsigned int v9; // esi@9
  unsigned int v10; // eax@12
  unsigned int v11; // esi@16
  unsigned int v12; // eax@19
  char result; // al@25

  v4 = this;
  v5 = this->m_pImageData;
  if ( v5 )
    v6 = v5->pfDesc.format;
  else
    v6 = 0;
  v7 = texture->m_pImageData;
  if ( v7 )
    v8 = v7->pfDesc.format;
  else
    v8 = 0;
  if ( v6 == v8
    && (!v5 ? (v9 = 0) : (v9 = v5->width),
        !v7 ? (v10 = 0) : (v10 = v7->width),
        v9 == v10
     && (!v5 ? (v11 = 0) : (v11 = v5->height),
         !v7 ? (v12 = 0) : (v12 = v7->height),
         v11 == v12 && v5 && v7 && (unsigned __int8)v5->vfptr[4].IUnknown_Release((Interface *)texture->m_pImageData))) )
  {
    ImgTex::CreateD3DTexture(v4, a2, a3, (int)v4);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0053F3A0) --------------------------------------------------------  // acclient.c:366448
void __thiscall ImgTex::GetSubDataIDs(ImgTex *this, QualifiedDataIDArray *id_array)
{
  ImgTex *v2; // edi@1
  unsigned int v3; // eax@1
  bool v4; // bl@1
  unsigned int v5; // esi@1
  signed int v6; // ecx@2
  unsigned int v7; // ST08_4@5
  QualifiedDataID *v8; // eax@5
  QualifiedDataID v9; // [sp+Ch] [bp-8h]@5

  v2 = this;
  v3 = this->m_SourceLevels.m_num;
  v4 = v3 > 1;
  v5 = 0;
  if ( v3 )
  {
    do
    {
      v6 = 8;
      if ( v4 && !v5 )
        v6 = 12;
      v7 = v6;
      QualifiedDataID::QualifiedDataID(&v9, v2->m_SourceLevels.m_data[v5], 0);
      QualifiedDataIDArray::AddQDID(id_array, v8, v7);
      ++v5;
    }
    while ( v5 < v2->m_SourceLevels.m_num );
  }
}

//----- (0053F450) --------------------------------------------------------  // acclient.c:366502
char __thiscall SmartArray<IDClass<_tagDataID,32,0>,1>::SetNElements(SmartArray<IDClass<_tagDataID,32,0>,1> *this, const unsigned int i_nSize, int i_bGrowExactly)
{
  SmartArray<IDClass<_tagDataID,32,0>,1> *v3; // esi@1
  unsigned int v4; // eax@3
  char result; // al@5
  unsigned int i; // eax@7

  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    for ( i = i_nSize; i < this->m_num; ++i )
      this->m_data[i].id = i_bGrowExactly;
    goto LABEL_9;
  }
  if ( (_BYTE)i_bGrowExactly )
    v4 = i_nSize;
  else
    v4 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<IDClass<_tagDataID,32,0>,1>::grow(v3, v4);
  if ( result )
  {
LABEL_9:
    v3->m_num = i_nSize;
    result = 1;
  }
  return result;
}

//----- (0053F4B0) --------------------------------------------------------  // acclient.c:366531
void __userpurge ImgTex::ImgTex(ImgTex *this@<ecx>, int a2@<ebx>, int a3@<ebp>, RenderSurface *i_pRS)
{
  ImgTex *v4; // esi@1

  v4 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_8457D8);
  GraphicsResource::GraphicsResource((GraphicsResource *)&v4->vfptr);
  v4->vfptr = (InterfaceVtbl *)&ImgTex::vftable;
  v4->vfptr = (GraphicsResourceVtbl *)&ImgTex::vftable;
  v4->m_SourceLevels.m_data = 0;
  v4->m_SourceLevels.m_sizeAndDeallocate = 0;
  v4->m_SourceLevels.m_num = 0;
  v4->m_pImageData = 0;
  v4->m_pPalette = 0;
  v4->m_cPitch = 0;
  LODWORD(v4->m_TextureCode) = 0;
  HIDWORD(v4->m_TextureCode) = 0;
  v4->m_pD3DTexture = 0;
  v4->m_pRenderTexture = 0;
  v4->m_pSystemMemTexture = 0;
  v4->m_IsLocked = 0;
  ImgTex::CreateFromRenderSurface_Internal(v4, a2, a3, (int)&v4->vfptr, i_pRS);
}
// 7C9D44: using guessed type void *ImgTex::vftable;
// 7C9D58: using guessed type __int32 (__stdcall *ImgTex::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0053F520) --------------------------------------------------------  // acclient.c:366558
ImgTex *__thiscall ImgTex::vector_deleting_destructor(ImgTex *this, unsigned int a2)
{
  return ImgTex::scalar_deleting_destructor((ImgTex *)((char *)this - 48), a2);
}

//----- (0053F530) --------------------------------------------------------  // acclient.c:366564
char __usercall ImgTex::InitLoad@<al>(ImgTex *this@<ecx>, int a2@<ebx>, int a3@<ebp>)
{
  ImgTex *v3; // edi@1
  IDClass<_tagDataID,32,0> *v4; // eax@2
  QualifiedDataID *v5; // eax@2
  int v6; // eax@2
  int v7; // esi@2
  IDClass<_tagDataID,32,0> result; // [sp+4h] [bp-Ch]@2
  QualifiedDataID v10; // [sp+8h] [bp-8h]@2

  v3 = this;
  if ( DBCache::IsRunTime() )
  {
    v4 = ImgTex::GetSurfaceDID(v3, &result);
    QualifiedDataID::QualifiedDataID(&v10, (IDClass<_tagDataID,32,0>)v4->id, 0xCu);
    v6 = DBObj::Get(v5);
    v7 = v6;
    if ( v6 )
    {
      ImgTex::CreateFromRenderSurface_Internal(v3, a2, a3, (int)v3, (RenderSurface *)v6);
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 20))(v7);
    }
  }
  return 1;
}

//----- (0053F580) --------------------------------------------------------  // acclient.c:366591
void __thiscall ImgTex::Serialize(ImgTex *this, Archive *io_archive)
{
  ImgTex *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // ebx@4
  unsigned int v5; // eax@4
  unsigned int v6; // ecx@9
  int v7; // edi@9
  unsigned int i; // eax@12
  unsigned int v9; // ebp@15
  int v10; // edi@16
  unsigned int v11; // eax@16
  ImgTex *v12; // [sp+10h] [bp-4h]@1

  v2 = this;
  v12 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  Archive::CheckAlignment(io_archive, 1u);
  v3 = Archive::GetBytes(io_archive, 1u);
  if ( v3 && io_archive->m_flags & 1 )
    *(_BYTE *)v3 = 2;
  v4 = v2->m_SourceLevels.m_num;
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v5 = v4;
    else
      v4 = *(_DWORD *)v5;
  }
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
  {
    v6 = v2->m_SourceLevels.m_sizeAndDeallocate;
    v7 = (int)&v2->m_SourceLevels;
    if ( (v6 & 0x7FFFFFFF) >= v4 )
    {
      for ( i = v4; i < *(_DWORD *)(v7 + 8); ++i )
        *(_DWORD *)(*(_DWORD *)v7 + 4 * i) = io_archive;
    }
    else if ( !SmartArray<IDClass<_tagDataID,32,0>,1>::grow((SmartArray<IDClass<_tagDataID,32,0>,1> *)v7, v4) )
    {
      goto LABEL_15;
    }
    *(_DWORD *)(v7 + 8) = v4;
  }
LABEL_15:
  v9 = 0;
  if ( v4 )
  {
    do
    {
      v10 = (int)&v12->m_SourceLevels.m_data[v9];
      Archive::CheckAlignment(io_archive, 4u);
      v11 = Archive::GetBytes(io_archive, 4u);
      if ( v11 )
      {
        if ( io_archive->m_flags & 1 )
          *(_DWORD *)v11 = *(_DWORD *)v10;
        else
          *(_DWORD *)v10 = *(_DWORD *)v11;
      }
      ++v9;
    }
    while ( v9 < v4 );
  }
}

//----- (0053F680) --------------------------------------------------------  // acclient.c:366660
char __thiscall IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::grow(IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::resize_internal(v2, *v3);
}

//----- (0053F6D0) --------------------------------------------------------  // acclient.c:366678
void __thiscall IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>(IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>Vtbl *)IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashSetData<ImgTex *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashSetData<ImgTex *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7C9D38: using guessed type int (__thiscall *IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::vftable[3])(void *, char);

//----- (0053F760) --------------------------------------------------------  // acclient.c:366711
void __thiscall IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>(IntrusiveHashTable<enum PixelFormatID,HashTableData<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<enum PixelFormatID,HashTableData<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<enum PixelFormatID,HashTableData<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>Vtbl *)IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7C9D3C: using guessed type int (__thiscall *IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::vftable[2])(void *, char);

//----- (0053F7F0) --------------------------------------------------------  // acclient.c:366744
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,ImgTex *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,ImgTex *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7C9D40: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::vftable)(void *, char);

//----- (0053F880) --------------------------------------------------------  // acclient.c:366777
void __thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>Vtbl *)IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned __int64,ImgTex *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned __int64,ImgTex *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7C9D34: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::vftable[4])(void *, char);

//----- (0053F910) --------------------------------------------------------  // acclient.c:366810
char __thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::grow(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::resize_internal(v2, *v3);
}

//----- (0053F960) --------------------------------------------------------  // acclient.c:366828
char __thiscall IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::resize_internal(IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1> *v3; // esi@1
  char result; // al@2
  HashSetData<ImgTex *> *v5; // edi@3
  int v6; // ecx@4
  HashSetData<ImgTex *> **v7; // eax@5
  int v8; // eax@6
  HashSetData<ImgTex *> **v9; // ebx@7
  HashSetData<ImgTex *> *v10; // ecx@7
  HashSetData<ImgTex *> *v11; // eax@9
  HashSetData<ImgTex *> *v12; // edx@10
  HashSetData<ImgTex *> *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  HashSetData<ImgTex *> **v17; // eax@23
  int v18; // eax@23

  v2 = _numBuckets;
  v3 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v6 = (int)&v3->m_buckets[v3->m_numBuckets];
        if ( v3->m_firstInterestingBucket == (HashSetData<ImgTex *> **)v6 )
        {
LABEL_7:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v3->m_firstInterestingBucket;
            if ( *v7 )
              break;
            v8 = (int)(v7 + 1);
            v3->m_firstInterestingBucket = (HashSetData<ImgTex *> **)v8;
            if ( v8 == v6 )
              goto LABEL_7;
          }
          v10 = *v3->m_firstInterestingBucket;
          v9 = v3->m_firstInterestingBucket;
        }
        v11 = *v9;
        if ( *v9 == v10 )
          goto LABEL_29;
        do
        {
          v12 = v11;
          v11 = v11->m_hashNext;
        }
        while ( v11 != v10 );
        if ( v12 )
          v12->m_hashNext = v11->m_hashNext;
        else
LABEL_29:
          *v9 = v11->m_hashNext;
        --v3->m_numElements;
        v10->m_hashNext = v5;
        v5 = v10;
      }
      while ( v3->m_numElements );
    }
    if ( (HashSetData<ImgTex *> **)v3->m_buckets != v3->m_aInplaceBuckets )
      operator delete[](v3->m_buckets);
    v3->m_buckets = 0;
    v3->m_firstInterestingBucket = 0;
    v3->m_numBuckets = 0;
    v3->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v3,
      v2);
    if ( v5 )
    {
      do
      {
        v13 = v5->m_hashNext;
        if ( (signed int)(2 * v3->m_numBuckets) < (signed int)(v3->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v3->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::resize_internal(v3, *v15);
        }
        v16 = (unsigned int)v5->m_hashKey % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashSetData<ImgTex *> **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashSetData<ImgTex *> **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (0053FAA0) --------------------------------------------------------  // acclient.c:366944
char __thiscall IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::add(IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1> *this, HashSetData<ImgTex *> *data)
{
  IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashSetData<ImgTex *> *v4; // eax@1
  unsigned int v5; // edx@6
  HashSetData<ImgTex *> **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[(unsigned int)data->m_hashKey % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != data->m_hashKey )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::grow(this);
    v5 = (unsigned int)data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashSetData<ImgTex *> **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashSetData<ImgTex *> **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (0053FB60) --------------------------------------------------------  // acclient.c:367016
void __thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::add_internal(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1> *this, HashTableData<unsigned __int64,ImgTex *> *data)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1> *v2; // esi@1
  unsigned __int64 v3; // rax@3
  HashTableData<unsigned __int64,ImgTex *> *v4; // ecx@3
  HashTableData<unsigned __int64,ImgTex *> **v5; // eax@3

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::grow(this);
  v3 = data->m_hashKey % v2->m_numBuckets;
  HIDWORD(v3) = v2->m_buckets;
  v4 = *(HashTableData<unsigned __int64,ImgTex *> **)(HIDWORD(v3) + 4 * v3);
  v5 = (HashTableData<unsigned __int64,ImgTex *> **)(HIDWORD(v3) + 4 * v3);
  data->m_hashNext = v4;
  *v5 = data;
  if ( v5 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = v5;
  ++v2->m_numElements;
}

//----- (0053FBB0) --------------------------------------------------------  // acclient.c:367038
char __thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::resize_internal(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1> *v3; // esi@1
  char result; // al@2
  HashTableData<unsigned __int64,ImgTex *> *v5; // edi@3
  int v6; // ecx@4
  HashTableData<unsigned __int64,ImgTex *> **v7; // eax@5
  int v8; // eax@6
  HashTableData<unsigned __int64,ImgTex *> **v9; // ebx@7
  HashTableData<unsigned __int64,ImgTex *> *v10; // ecx@7
  HashTableData<unsigned __int64,ImgTex *> *v11; // eax@9
  HashTableData<unsigned __int64,ImgTex *> *v12; // edx@10
  HashTableData<unsigned __int64,ImgTex *> *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  unsigned __int64 v16; // rax@23
  HashTableData<unsigned __int64,ImgTex *> **v17; // ecx@23
  HashTableData<unsigned __int64,ImgTex *> **v18; // eax@23

  v2 = _numBuckets;
  v3 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v6 = (int)&v3->m_buckets[v3->m_numBuckets];
        if ( v3->m_firstInterestingBucket == (HashTableData<unsigned __int64,ImgTex *> **)v6 )
        {
LABEL_7:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v3->m_firstInterestingBucket;
            if ( *v7 )
              break;
            v8 = (int)(v7 + 1);
            v3->m_firstInterestingBucket = (HashTableData<unsigned __int64,ImgTex *> **)v8;
            if ( v8 == v6 )
              goto LABEL_7;
          }
          v10 = *v3->m_firstInterestingBucket;
          v9 = v3->m_firstInterestingBucket;
        }
        v11 = *v9;
        if ( *v9 == v10 )
          goto LABEL_29;
        do
        {
          v12 = v11;
          v11 = v11->m_hashNext;
        }
        while ( v11 != v10 );
        if ( v12 )
          v12->m_hashNext = v11->m_hashNext;
        else
LABEL_29:
          *v9 = v11->m_hashNext;
        --v3->m_numElements;
        v10->m_hashNext = v5;
        v5 = v10;
      }
      while ( v3->m_numElements );
    }
    if ( (HashTableData<unsigned __int64,ImgTex *> **)v3->m_buckets != v3->m_aInplaceBuckets )
      operator delete[](v3->m_buckets);
    v3->m_buckets = 0;
    v3->m_firstInterestingBucket = 0;
    v3->m_numBuckets = 0;
    v3->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v3,
      v2);
    if ( v5 )
    {
      do
      {
        v13 = v5->m_hashNext;
        if ( (signed int)(2 * v3->m_numBuckets) < (signed int)(v3->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v3->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::resize_internal(v3, *v15);
        }
        v16 = v5->m_hashKey % v3->m_numBuckets;
        v17 = v3->m_buckets;
        HIDWORD(v16) = v17[(_DWORD)v16];
        v18 = &v17[v16];
        v5->m_hashNext = (HashTableData<unsigned __int64,ImgTex *> *)HIDWORD(v16);
        *v18 = v5;
        if ( v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (0053FD00) --------------------------------------------------------  // acclient.c:367155
char __thiscall HashSet<ImgTex *>::add(HashSet<ImgTex *> *this, ImgTex *const *_key)
{
  IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1> *v2; // esi@1
  HashSetData<ImgTex *> *v3; // eax@1
  void *v4; // eax@4
  char result; // al@5

  v2 = &this->m_intrusiveTable;
  v3 = this->m_intrusiveTable.m_buckets[(unsigned int)*_key % this->m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != (ImgTex *)*_key )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    v4 = operator new(8u);
    if ( v4 )
    {
      *(_DWORD *)v4 = *_key;
      *((_DWORD *)v4 + 1) = 0;
      IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::add(v2, (HashSetData<ImgTex *> *)v4);
      result = 1;
    }
    else
    {
      IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::add(v2, 0);
      result = 1;
    }
  }
  return result;
}

//----- (0053FD70) --------------------------------------------------------  // acclient.c:367197
HashSet<ImgTex *> *__thiscall HashSet<ImgTex *>::scalar_deleting_destructor(HashSet<ImgTex *> *this, unsigned int a2)
{
  HashSet<ImgTex *> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashSet<ImgTex *>Vtbl *)HashSet<ImgTex *>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9D38: using guessed type int (__thiscall *IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::vftable[3])(void *, char);
// 7C9DB0: using guessed type int (__thiscall *HashSet<ImgTex *>::vftable[5])(void *, char);

//----- (0053FDD0) --------------------------------------------------------  // acclient.c:367223
HashTable<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0> *__thiscall HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::vector_deleting_destructor(HashTable<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0> *this, unsigned int a2)
{
  HashTable<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>Vtbl *)HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9D3C: using guessed type int (__thiscall *IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::vftable[2])(void *, char);
// 7C9DB4: using guessed type int (__thiscall *HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::vftable[4])(void *, char);

//----- (0053FE30) --------------------------------------------------------  // acclient.c:367249
HashTable<unsigned long,ImgTex *,0> *__thiscall HashTable<unsigned long,ImgTex *,0>::vector_deleting_destructor(HashTable<unsigned long,ImgTex *,0> *this, unsigned int a2)
{
  HashTable<unsigned long,ImgTex *,0> *v2; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0> *v3; // edi@1

  v2 = this;
  v3 = &this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,ImgTex *,0>Vtbl *)HashTable<unsigned long,ImgTex *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::~IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>(v3);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9DB8: using guessed type int (__thiscall *HashTable<unsigned long,ImgTex *,0>::vftable[3])(void *, char);

//----- (0053FED0) --------------------------------------------------------  // acclient.c:367297
ImgTex *__usercall ImgTex::AllocateTempBuffer@<eax>(ImgTex *a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int _width, int _height, PixelFormatID _image_type)
{
  ImgTex *v6; // eax@1
  ImgTex *v7; // eax@2
  ImgTex *v8; // esi@2
  int v9; // eax@5
  ImgTex *_key; // [sp+0h] [bp-4h]@1

  _key = a1;
  v6 = (ImgTex *)operator new(0x88u);
  if ( v6 )
  {
    ImgTex::ImgTex(v6, a2, a3, 0);
    v8 = v7;
    _key = v7;
    if ( !v7 )
      return v8;
    HashSet<ImgTex *>::add(&ImgTex::custom_texture_table, &_key);
  }
  else
  {
    v8 = 0;
  }
  if ( v8 )
  {
    v9 = (*(int (**)(void))&RenderDevice::render_device->vfptr->gap4[8])();
    v8->m_pImageData = (RenderSurface *)v9;
    if ( !v9
      || !(unsigned __int8)(*(int (__thiscall **)(int, int, int, PixelFormatID, signed int))(*(_DWORD *)v9 + 88))(
                             v9,
                             _width,
                             _height,
                             _image_type,
                             1) )
    {
      v8->vfptr->Release((Interface *)v8);
      return 0;
    }
  }
  return v8;
}

//----- (0053FF50) --------------------------------------------------------  // acclient.c:367340
char __thiscall HashTable<unsigned __int64,ImgTex *,1>::add(HashTable<unsigned __int64,ImgTex *,1> *this, const unsigned __int64 *_key, ImgTex *const *_data)
{
  HashTable<unsigned __int64,ImgTex *,1> *v3; // edi@1
  void *v4; // eax@1
  const unsigned __int64 *v5; // esi@2
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *v6; // edi@4
  char v7; // al@5
  IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> result; // [sp+8h] [bp-Ch]@4

  v3 = this;
  v4 = operator new(0x18u);
  if ( v4 )
  {
    *(_QWORD *)v4 = *_key;
    *((_DWORD *)v4 + 2) = 0;
    *((_DWORD *)v4 + 4) = *_data;
    v5 = (const unsigned __int64 *)v4;
  }
  else
  {
    v5 = 0;
  }
  v6 = (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&v3->m_intrusiveTable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::find_internal(
    v6,
    &result,
    v5);
  if ( result.m_currElement )
  {
    if ( v5 )
      operator delete((void *)v5);
    v7 = 0;
  }
  else
  {
    IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::add_internal(
      (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1> *)v6,
      (HashTableData<unsigned __int64,ImgTex *> *)v5);
    v7 = 1;
  }
  return v7;
}

//----- (0053FFD0) --------------------------------------------------------  // acclient.c:367384
AutoGrowHashTable<unsigned __int64,ImgTex *> *__thiscall HashTable<unsigned __int64,ImgTex *,1>::vector_deleting_destructor(AutoGrowHashTable<unsigned __int64,ImgTex *> *this, unsigned int a2)
{
  AutoGrowHashTable<unsigned __int64,ImgTex *> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned __int64,ImgTex *,1>Vtbl *)AutoGrowHashTable<unsigned __int64,ImgTex *>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9D34: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::vftable[4])(void *, char);
// 7C9DBC: using guessed type int (__thiscall *AutoGrowHashTable<unsigned __int64,ImgTex *>::vftable[2])(void *, char);

//----- (00540030) --------------------------------------------------------  // acclient.c:367410
void __thiscall ImgTex::~ImgTex(ImgTex *this)
{
  unsigned int v1; // esi@1
  RenderSurface *v2; // ecx@1
  int v3; // ecx@3
  int v4; // eax@5
  int v5; // ecx@7
  int v6; // ecx@9
  void *v7; // eax@12
  int v8; // eax@17
  IDClass<_tagDataID,32,0> key; // [sp+4h] [bp-4h]@1

  key.id = (unsigned int)this;
  v1 = (unsigned int)this;
  v2 = this->m_pImageData;
  *(_DWORD *)v1 = &ImgTex::vftable;
  *(_DWORD *)(v1 + 48) = &ImgTex::vftable;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    *(_DWORD *)(v1 + 100) = 0;
  }
  v3 = *(_DWORD *)(v1 + 104);
  if ( v3 )
  {
    (*(void (**)(void))(*(_DWORD *)v3 + 20))();
    *(_DWORD *)(v1 + 104) = 0;
  }
  v4 = *(_DWORD *)(v1 + 120);
  if ( v4 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 8))(*(_DWORD *)(v1 + 120));
    *(_DWORD *)(v1 + 120) = 0;
  }
  v5 = *(_DWORD *)(v1 + 124);
  if ( v5 )
  {
    (*(void (**)(void))(*(_DWORD *)v5 + 20))();
    *(_DWORD *)(v1 + 124) = 0;
  }
  v6 = *(_DWORD *)(v1 + 128);
  if ( v6 )
  {
    (*(void (**)(void))(*(_DWORD *)v6 + 20))();
    *(_DWORD *)(v1 + 128) = 0;
  }
  if ( *(_QWORD *)(v1 + 112) )
  {
    v7 = IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::remove(
           (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&ImgTex::texture_table.m_intrusiveTable,
           (const unsigned __int64 *)(v1 + 112));
  }
  else
  {
    key.id = v1;
    v7 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
           &stru_81EA74,
           &key);
  }
  if ( v7 )
    operator delete(v7);
  if ( (*(_DWORD *)(v1 + 92) & 0x80000000) == 0x80000000 )
  {
    v8 = *(_DWORD *)(v1 + 88);
    if ( v8 )
      operator delete[]((void *)(v8 - 4));
  }
  GraphicsResource::~GraphicsResource((GraphicsResource *)(v1 + 48));
  DBObj::~DBObj((DBObj *)v1);
}
// 7C9D44: using guessed type void *ImgTex::vftable;
// 7C9D58: using guessed type __int32 (__stdcall *ImgTex::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00540110) --------------------------------------------------------  // acclient.c:367484
ImgTex *__cdecl ImgTex::GetTempBuffer(int _width, int _height, PixelFormatID _image_type)
{
  int v3; // ebp@1
  HashTableData<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *v4; // eax@1
  void *v5; // eax@4
  unsigned int v6; // edi@4
  int v7; // ecx@6
  int v8; // edx@6
  int v9; // eax@6
  int v10; // eax@6
  ImgTex *v11; // esi@9
  ImgTex *result; // eax@11
  unsigned int hash_val; // [sp+8h] [bp-4h]@5

  v3 = _image_type;
  v4 = stru_81E984.m_buckets[_image_type % stru_81E984.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != _image_type )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    v6 = (unsigned int)v4->m_data;
  }
  else
  {
LABEL_4:
    v5 = operator new(0x74u);
    v6 = (unsigned int)v5;
    if ( !v5 )
      return 0;
    *(_DWORD *)v5 = HashTable<unsigned long,ImgTex *,0>::vftable;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0> *)((char *)v5 + 4),
      8u);
    hash_val = v6;
    HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
      &ImgTex::temp_buffer_table,
      (const unsigned int *)&_image_type,
      (RenderVertexStreamD3D *const *)&hash_val);
  }
  v7 = (unsigned __int16)_height | (_width << 16);
  v8 = ((unsigned __int16)_height | (unsigned __int64)(unsigned int)(_width << 16)) % *(_DWORD *)(v6 + 108);
  v9 = *(_DWORD *)(v6 + 100);
  hash_val = (unsigned __int16)_height | (_width << 16);
  v10 = *(_DWORD *)(v9 + 4 * v8);
  if ( !v10 )
    goto LABEL_9;
  while ( *(_DWORD *)v10 != v7 )
  {
    v10 = *(_DWORD *)(v10 + 4);
    if ( !v10 )
      goto LABEL_9;
  }
  if ( v10 )
  {
    result = *(ImgTex **)(v10 + 8);
  }
  else
  {
LABEL_9:
    v11 = ImgTex::AllocateTempBuffer((ImgTex *)v7, _height, v3, _width, _height, (PixelFormatID)v3);
    _image_type = (PixelFormatID)v11;
    if ( v11 )
      HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
        (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)v6,
        &hash_val,
        (RenderVertexStreamD3D *const *)&_image_type);
    result = v11;
  }
  return result;
}
// 7C9DB8: using guessed type int (__thiscall *HashTable<unsigned long,ImgTex *,0>::vftable[3])(void *, char);

//----- (00540210) --------------------------------------------------------  // acclient.c:367563
ImgTex *__thiscall ImgTex::scalar_deleting_destructor(ImgTex *this, unsigned int a2)
{
  ImgTex *v2; // esi@1

  v2 = this;
  ImgTex::~ImgTex(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00540230) --------------------------------------------------------  // acclient.c:367575
char __thiscall ImgTex::Combine(ImgTex *this, ImgTex *texture, Palette *palette, int clipmap)
{
  RenderSurface *v4; // eax@1
  PixelFormatID v5; // ecx@2
  char result; // al@5
  unsigned int v7; // esi@6
  unsigned int v8; // edi@6
  int v9; // ebp@6
  int v10; // eax@6
  RenderSurface *v11; // eax@8
  int v12; // ecx@9
  int v13; // eax@12
  ImgTex *v14; // eax@14
  ImgTex *v15; // esi@14
  char *v16; // eax@15
  RenderSurface *v17; // ecx@16
  bool v18; // zf@18
  ImgTex *v19; // [sp+10h] [bp-4h]@1

  v4 = texture->m_pImageData;
  v19 = this;
  if ( v4 && ((v5 = v4->pfDesc.format, v5 == 41) || v4 && v5 == 101) )
  {
    v7 = v4->height;
    v8 = v4->width;
    v9 = 22 - ((_BYTE)clipmap != 0);
    v10 = ((int (*)(void))RenderDevice::render_device->vfptr->CreateSurface)();
    v19->m_pImageData = (RenderSurface *)v10;
    if ( !v10
      || !(unsigned __int8)(*(int (__thiscall **)(int, unsigned int, unsigned int, int, signed int))(*(_DWORD *)v10 + 88))(
                             v10,
                             v8,
                             v7,
                             v9,
                             1) )
      goto LABEL_22;
    v11 = texture->m_pImageData;
    v12 = v11 ? v11->height : 0;
    v13 = v11 ? v11->width : 0;
    v14 = ImgTex::GetTempBuffer(v13, v12, (PixelFormatID)v9);
    v15 = v14;
    if ( !v14 )
      goto LABEL_22;
    v16 = ImgTex::GetData(v14);
    if ( !v16 )
      goto LABEL_22;
    ImgTex::CopyIntoData(v16, v15->m_cPitch, texture, palette, clipmap);
    v17 = v15->m_pImageData;
    if ( v17 )
    {
      v15->m_cPitch = 0;
      ((void (*)(void))v17->vfptr[4].IUnknown_AddRef)();
      v15->m_IsLocked = 0;
    }
    v18 = ImgTex::Load(v19, clipmap, v9, v15) == 0;
    result = 1;
    if ( v18 )
LABEL_22:
      result = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00540340) --------------------------------------------------------  // acclient.c:367643
char __thiscall ImgTex::LoadCSI(ImgTex *this, char *csi_data, unsigned int csi_width, unsigned int csi_height)
{
  ImgTex *v4; // esi@1
  int v5; // eax@1
  ImgTex *v6; // eax@3
  ImgTex *v7; // esi@3
  char *v8; // ebx@4
  RenderSurface *v9; // ecx@5
  int v10; // edx@6
  int v11; // ecx@9
  RenderSurface *v12; // ecx@11
  char result; // al@14
  ImgTex *v14; // [sp+10h] [bp-4h]@1

  v4 = this;
  v14 = this;
  v5 = ((int (*)(void))RenderDevice::render_device->vfptr->CreateSurface)();
  v4->m_pImageData = (RenderSurface *)v5;
  if ( v5
    && (unsigned __int8)(*(int (__thiscall **)(int, unsigned int, unsigned int, signed int, signed int))(*(_DWORD *)v5 + 88))(
                          v5,
                          csi_width,
                          csi_height,
                          22,
                          1)
    && (v6 = ImgTex::GetTempBuffer(csi_width, csi_height, PFID_X8R8G8B8), (v7 = v6) != 0) )
  {
    v8 = ImgTex::GetData(v6);
    if ( !v8 )
      goto LABEL_19;
    v9 = v7->m_pImageData;
    v10 = v9 ? v9->height : 0;
    v11 = v9 ? v9->width : 0;
    ImgTex::CSI2TGA(csi_data, csi_width, csi_height, v8, v11, v10, v7->m_cPitch);
    v12 = v7->m_pImageData;
    if ( v12 )
    {
      v7->m_cPitch = 0;
      ((void (*)(void))v12->vfptr[4].IUnknown_AddRef)();
      v7->m_IsLocked = 0;
    }
    if ( ImgTex::Load(v14, (int)v8, csi_width, v7) )
      result = 1;
    else
LABEL_19:
      result = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00540420) --------------------------------------------------------  // acclient.c:367698
Palette *__cdecl ImgTex::CreateCombinedTexture(ImgTex *i_pIndexedImage, Palette *i_pPalette, bool fHasClipmap)
{
  Palette *v3; // ebp@1
  unsigned int v4; // esi@1
  int v5; // ebx@1
  Palette *v6; // edi@3
  ImgTex *v7; // eax@6
  Palette *v8; // eax@7
  unsigned __int64 _key; // [sp+10h] [bp-1Ch]@3
  unsigned __int64 texCode; // [sp+18h] [bp-14h]@3
  IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> result; // [sp+20h] [bp-Ch]@3

  v3 = i_pPalette;
  v4 = 0;
  v5 = 0;
  if ( i_pPalette->m_pMaintainer )
  {
    v4 = i_pPalette->m_DID.id;
    v5 = i_pIndexedImage->m_DID.id;
  }
  texCode = __PAIR__(v5, v4);
  _key = __PAIR__(v5, v4);
  v6 = 0;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::find_internal(
    (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&ImgTex::texture_table.m_intrusiveTable,
    &result,
    &_key);
  if ( result.m_currElement )
  {
    v6 = (Palette *)LODWORD(result.m_currElement->m_data);
    v6->vfptr->AddRef(LODWORD(result.m_currElement->m_data));
  }
  if ( v6 )
    return v6;
  v7 = (ImgTex *)operator new(0x88u);
  if ( !v7 )
    return 0;
  ImgTex::ImgTex(v7, v5, (int)v3, 0);
  v6 = v8;
  i_pPalette = v8;
  if ( !v8 )
    return v6;
  if ( !ImgTex::Combine((ImgTex *)v8, i_pIndexedImage, v3, fHasClipmap) )
  {
    v6->vfptr->Release((Interface *)v6);
    return 0;
  }
  if ( v5 | v4 )
  {
    v6[1].m_DID.id = v4;
    *(_DWORD *)&v6[1].m_AllowedInFreeList = v5;
    HashTable<unsigned __int64,ImgTex *,1>::add(&ImgTex::texture_table, &texCode, (ImgTex *const *)&i_pPalette);
    return v6;
  }
  HashSet<ImgTex *>::add(&ImgTex::custom_texture_table, (ImgTex *const *)&i_pPalette);
  return v6;
}

//----- (00540520) --------------------------------------------------------  // acclient.c:367757
ImgTex *__usercall ImgTex::CreateLScapeTexture@<eax>(ImgTex *a1@<ecx>, int a2@<ebx>, int a3@<ebp>, char *i_pRawData, unsigned int i_width, unsigned int i_height)
{
  ImgTex *v6; // eax@1
  ImgTex *v7; // eax@2
  ImgTex *v8; // esi@2
  ImgTex *result; // eax@5
  ImgTex *retval; // [sp+0h] [bp-4h]@1

  retval = a1;
  v6 = (ImgTex *)operator new(0x88u);
  if ( v6 )
  {
    ImgTex::ImgTex(v6, a2, a3, 0);
    v8 = v7;
    retval = v7;
    if ( !v7 )
      return v8;
    ImgTex::fCurrentTextureScale = 0;
    if ( ImgTex::LoadCSI(v7, i_pRawData, i_width, i_height) )
    {
      HashSet<ImgTex *>::add(&ImgTex::custom_texture_table, &retval);
      return v8;
    }
    v8->vfptr->Release((Interface *)v8);
    result = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 845774: using guessed type enum ImageScaleType ImgTex::fCurrentTextureScale;

//----- (00701D10) --------------------------------------------------------  // acclient.c:789445
void _E73_97()
{
  PixelFormatDesc::PixelFormatDesc(&stru_845790, PFID_A8R8G8B8);
}

//----- (00701D20) --------------------------------------------------------  // acclient.c:789451
void sub_701D20()
{
  LODWORD(dword_8457C8) = 1053364187;
}

//----- (00701D30) --------------------------------------------------------  // acclient.c:789457
void sub_701D30()
{
  flt_8457CC = 1000.0 + 1.0;
}

//----- (00701D50) --------------------------------------------------------  // acclient.c:789463
void sub_701D50()
{
  flt_8457D0 = 24.0 * 8.0;
}

//----- (00701D70) --------------------------------------------------------  // acclient.c:789469
void sub_701D70()
{
  flt_8457D4 = 24.0 * 0.5;
}

//----- (00701D90) --------------------------------------------------------  // acclient.c:789475
int _E99_37()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_33, "Render.TextureFiltering");
  return atexit(sub_770970);
}

//----- (00701DB0) --------------------------------------------------------  // acclient.c:789482
int _E102_26()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_33, "Render.LandscapeDetailTextures");
  return atexit(sub_7709A0);
}

//----- (00701DD0) --------------------------------------------------------  // acclient.c:789489
int _E105_42()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_33, "Render.BuildingDetailTextures");
  return atexit(sub_7709D0);
}

//----- (00701DF0) --------------------------------------------------------  // acclient.c:789496
int _E108_81()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_33, "Render.FieldOfView");
  return atexit(sub_770A00);
}

//----- (00701E10) --------------------------------------------------------  // acclient.c:789503
int _E111_45()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_33, "Render.LandscapeTextureDetail");
  return atexit(sub_770A30);
}

//----- (00701E30) --------------------------------------------------------  // acclient.c:789510
int _E114_55()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_33, "Render.EnvironmentTextureDetail");
  return atexit(sub_770A60);
}

//----- (00701E50) --------------------------------------------------------  // acclient.c:789517
int _E117_63()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_33, "Render.SceneryDrawDistance");
  return atexit(sub_770A90);
}

//----- (00701E70) --------------------------------------------------------  // acclient.c:789524
int _E120_61()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_33, "Render.LandscapeDrawDistance");
  return atexit(sub_770AC0);
}

//----- (00701E90) --------------------------------------------------------  // acclient.c:789531
int _E123_39()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_33, "Render.ScreenBrightness");
  return atexit(sub_770AF0);
}

//----- (00701EB0) --------------------------------------------------------  // acclient.c:789538
int _E126_45()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_33, "Render.AspectRatio");
  return atexit(sub_770B20);
}

//----- (00701ED0) --------------------------------------------------------  // acclient.c:789545
int _E129_37()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_33, "Render.DisplayAdapter");
  return atexit(sub_770B50);
}

//----- (00701EF0) --------------------------------------------------------  // acclient.c:789552
int _E132_40()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_33, "Render.MaxHardwareClass");
  return atexit(sub_770B80);
}

//----- (00701F10) --------------------------------------------------------  // acclient.c:789559
int _E135_43()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_33, "Render.AutomaticDegrades");
  return atexit(_E136_82);
}

//----- (00701F30) --------------------------------------------------------  // acclient.c:789566
int _E138_35()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_33, "Render.GraphicsPerformance");
  return atexit(_E139_82);
}

//----- (00701F50) --------------------------------------------------------  // acclient.c:789573
int _E141_35()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_33, "Render.DegradeDistance");
  return atexit(_E142_77);
}

//----- (00701F70) --------------------------------------------------------  // acclient.c:789580
int _E144_34()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_33, "Render.MultiPassAlpha");
  return atexit(_E145_79);
}

//----- (00701F90) --------------------------------------------------------  // acclient.c:789587
int _E147_32()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_33, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_845820, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_845824, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_845828, "Anisotropic");
  return atexit(_E148_75);
}

//----- (00701FE0) --------------------------------------------------------  // acclient.c:789597
int _E150_32()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_33, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_845830, "Low");
  PStringBase<char>::PStringBase<char>(&stru_845834, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_845838, "High");
  PStringBase<char>::PStringBase<char>(&stru_84583C, "VeryHigh");
  return atexit(_E151_73);
}

//----- (00702040) --------------------------------------------------------  // acclient.c:789608
int _E153_30()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_33, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_845844, "Low");
  PStringBase<char>::PStringBase<char>(&stru_845848, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_84584C, "High");
  PStringBase<char>::PStringBase<char>(&stru_845850, "VeryHigh");
  return atexit(_E154_74);
}

//----- (007020A0) --------------------------------------------------------  // acclient.c:789619
int _E156_32()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_33, "Low");
  PStringBase<char>::PStringBase<char>(&stru_845858, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_84585C, "High");
  return atexit(_E157_70);
}

//----- (007020E0) --------------------------------------------------------  // acclient.c:789628
int _E159_30()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_33, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_845864, "Low");
  PStringBase<char>::PStringBase<char>(&stru_845868, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_84586C, "High");
  PStringBase<char>::PStringBase<char>(&stru_845870, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_845874, "Extreme");
  return atexit(_E160_73);
}

//----- (00702150) --------------------------------------------------------  // acclient.c:789640
int _E162_32()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_33, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_84587C, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_845880, "Wide");
  return atexit(_E163_66);
}

//----- (00702190) --------------------------------------------------------  // acclient.c:789649
int _E165_28()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_57, "None");
  return atexit(_E166_68);
}

//----- (007021B0) --------------------------------------------------------  // acclient.c:789656
int _E168_29()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_57, "Speed");
  return atexit(_E169_67);
}

//----- (007021D0) --------------------------------------------------------  // acclient.c:789663
int _E171_28()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_57, "Noise");
  return atexit(_E172_65);
}

//----- (007021F0) --------------------------------------------------------  // acclient.c:789670
int _E174_29()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_57, "Sine");
  return atexit(_E175_62);
}

//----- (00702210) --------------------------------------------------------  // acclient.c:789677
int _E177_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_57, "Square");
  return atexit(_E178_62);
}

//----- (00702230) --------------------------------------------------------  // acclient.c:789684
int _E180_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_57, "Bounce");
  return atexit(_E181_62);
}

//----- (00702250) --------------------------------------------------------  // acclient.c:789691
int _E183_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_57, "Perlin");
  return atexit(_E184_59);
}

//----- (00702270) --------------------------------------------------------  // acclient.c:789698
int _E186_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_57, "Fractal");
  return atexit(_E187_58);
}

//----- (00702290) --------------------------------------------------------  // acclient.c:789705
int _E189_25()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_57, "FrameLoop");
  return atexit(_E190_59);
}

//----- (007022B0) --------------------------------------------------------  // acclient.c:789712
int _E192_21()
{
  return atexit(_E193_47);
}

//----- (007022C0) --------------------------------------------------------  // acclient.c:789718
int _E195_13()
{
  return atexit(_E196_54);
}

//----- (007022D0) --------------------------------------------------------  // acclient.c:789724
int _E198_19()
{
  return atexit(_E199_46);
}

//----- (007022E0) --------------------------------------------------------  // acclient.c:789730
int _E201_13()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_26, "Display.Resolution");
  return atexit(_E202_47);
}

//----- (00702300) --------------------------------------------------------  // acclient.c:789737
int _E204_12()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_26, "Display.FullScreen");
  return atexit(_E205_42);
}

//----- (00702320) --------------------------------------------------------  // acclient.c:789744
int _E207_9()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_26, "Display.RefreshRate");
  return atexit(_E208_46);
}

//----- (00702340) --------------------------------------------------------  // acclient.c:789751
int _E210_12()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_26, "Display.SyncToRefresh");
  return atexit(_E211_42);
}

//----- (00702360) --------------------------------------------------------  // acclient.c:789758
int _E213_8()
{
  PStringBase<char>::PStringBase<char>(&PHeader_10, "PREPROC_HEADER");
  return atexit(_E214_44);
}

//----- (00702380) --------------------------------------------------------  // acclient.c:789765
int _E216_10()
{
  PStringBase<char>::PStringBase<char>(&VertexArray_8, "VertexArray");
  return atexit(_E217_40);
}

//----- (007023A0) --------------------------------------------------------  // acclient.c:789772
int _E219_7()
{
  PStringBase<char>::PStringBase<char>(&BinaryVertexArray_8, "BinaryVertexArray");
  return atexit(_E220_39);
}

//----- (007023C0) --------------------------------------------------------  // acclient.c:789779
int _E222_6()
{
  PStringBase<char>::PStringBase<char>(&VertexType_9, "VertexType");
  return atexit(_E223_39);
}

//----- (007023E0) --------------------------------------------------------  // acclient.c:789786
int _E225_6()
{
  PStringBase<char>::PStringBase<char>(&VertexData_8, "VertexData");
  return atexit(_E226_25);
}

//----- (00702400) --------------------------------------------------------  // acclient.c:789793
int _E228_6()
{
  PStringBase<char>::PStringBase<char>(&Vertex_8, "Vertex");
  return atexit(_E229_25);
}

//----- (00702420) --------------------------------------------------------  // acclient.c:789800
int _E231_6()
{
  PStringBase<char>::PStringBase<char>(&Index_17, "Index");
  return atexit(_E232_24);
}

//----- (00702440) --------------------------------------------------------  // acclient.c:789807
int _E234_5()
{
  PStringBase<char>::PStringBase<char>(&Origin_17, "P");
  return atexit(_E235_24);
}

//----- (00702460) --------------------------------------------------------  // acclient.c:789814
int _E237_5()
{
  PStringBase<char>::PStringBase<char>(&Normal_8, "N");
  return atexit(_E238_22);
}

//----- (00702480) --------------------------------------------------------  // acclient.c:789821
int _E240_5()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_17, "Diffuse");
  return atexit(_E241_22);
}

//----- (007024A0) --------------------------------------------------------  // acclient.c:789828
int _E243_5()
{
  PStringBase<char>::PStringBase<char>(&Specular_17, "Specular");
  return atexit(_E244_22);
}

//----- (007024C0) --------------------------------------------------------  // acclient.c:789835
int _E246_5()
{
  PStringBase<char>::PStringBase<char>(&UVS_8, "UVS");
  return atexit(_E247_21);
}

//----- (007024E0) --------------------------------------------------------  // acclient.c:789842
int _E249_5()
{
  PStringBase<char>::PStringBase<char>(&VectorS_8, "VectorS");
  return atexit(_E250_22);
}

//----- (00702500) --------------------------------------------------------  // acclient.c:789849
int _E252_5()
{
  PStringBase<char>::PStringBase<char>(&VectorT_8, "VectorT");
  return atexit(_E253_19);
}

//----- (00702520) --------------------------------------------------------  // acclient.c:789856
int _E255_3()
{
  PStringBase<char>::PStringBase<char>(&VectorSxT_8, "VectorSxT");
  return atexit(_E256_19);
}

//----- (00702540) --------------------------------------------------------  // acclient.c:789863
int _E258_4()
{
  PStringBase<char>::PStringBase<char>(&Weights_8, "Weights");
  return atexit(_E259_20);
}

//----- (00702560) --------------------------------------------------------  // acclient.c:789870
int _E261_4()
{
  PStringBase<char>::PStringBase<char>(&Importance_8, "Importance");
  return atexit(_E262_20);
}

//----- (00702580) --------------------------------------------------------  // acclient.c:789877
int _E264_3()
{
  PStringBase<char>::PStringBase<char>(&PhysMtl_8, "PhysMtl");
  return atexit(_E265_20);
}

//----- (007025A0) --------------------------------------------------------  // acclient.c:789884
int _E267_3()
{
  PStringBase<char>::PStringBase<char>(&Material_38, "Material");
  return atexit(_E268_19);
}

//----- (007025C0) --------------------------------------------------------  // acclient.c:789891
int _E270_3()
{
  PStringBase<char>::PStringBase<char>(&ID_20, "ID");
  return atexit(_E271_18);
}

//----- (007025E0) --------------------------------------------------------  // acclient.c:789898
int _E273_3()
{
  PStringBase<char>::PStringBase<char>(&FileName_8, "FileName");
  return atexit(_E274_18);
}

//----- (00702600) --------------------------------------------------------  // acclient.c:789905
int _E276_3()
{
  PStringBase<char>::PStringBase<char>(&Polygon_17, "Polygon");
  return atexit(_E277_18);
}

//----- (00702620) --------------------------------------------------------  // acclient.c:789912
int _E279_3()
{
  PStringBase<char>::PStringBase<char>(&ID_21, "ID");
  return atexit(_E280_17);
}

//----- (00702640) --------------------------------------------------------  // acclient.c:789919
int _E282_3()
{
  PStringBase<char>::PStringBase<char>(&Indices_14, "INDICES");
  return atexit(_E283_17);
}

//----- (00702660) --------------------------------------------------------  // acclient.c:789926
int _E285_4()
{
  PStringBase<char>::PStringBase<char>(&MaterialID_8, "MaterialID");
  return atexit(_E286_16);
}

//----- (00702680) --------------------------------------------------------  // acclient.c:789933
int _E288_3()
{
  PStringBase<char>::PStringBase<char>(&PhysMaterialID_8, "PhysMaterialID");
  return atexit(_E289_15);
}

//----- (007026A0) --------------------------------------------------------  // acclient.c:789940
int _E291_3()
{
  PStringBase<char>::PStringBase<char>(&Markings_8, "Markings");
  return atexit(_E292_16);
}

//----- (007026C0) --------------------------------------------------------  // acclient.c:789947
int _E294_4()
{
  PStringBase<char>::PStringBase<char>(&Material_39, "Material");
  return atexit(_E295_15);
}

//----- (007026E0) --------------------------------------------------------  // acclient.c:789954
int _E297_3()
{
  PStringBase<char>::PStringBase<char>(&Index_18, "Index");
  return atexit(_E298_16);
}

//----- (00702700) --------------------------------------------------------  // acclient.c:789961
int _E300_4()
{
  PStringBase<char>::PStringBase<char>(&Filename_8, "Filename");
  return atexit(_E301_14);
}

//----- (00702720) --------------------------------------------------------  // acclient.c:789968
int _E303_3()
{
  PStringBase<char>::PStringBase<char>(&Surface_8, "Surface");
  return atexit(_E304_15);
}

//----- (00702740) --------------------------------------------------------  // acclient.c:789975
int _E306_4()
{
  PStringBase<char>::PStringBase<char>(&CellPoly_8, "CellPoly");
  return atexit(_E307_14);
}

//----- (00702760) --------------------------------------------------------  // acclient.c:789982
int _E309_3()
{
  PStringBase<char>::PStringBase<char>(&Sphere_11, "Sphere");
  return atexit(_E310_15);
}

//----- (00702780) --------------------------------------------------------  // acclient.c:789989
int _E312_4()
{
  PStringBase<char>::PStringBase<char>(&Side_8, "Side");
  return atexit(_E313_14);
}

//----- (007027A0) --------------------------------------------------------  // acclient.c:789996
int _E315_3()
{
  PStringBase<char>::PStringBase<char>(&Positive_8, "Positive");
  return atexit(_E316_15);
}

//----- (007027C0) --------------------------------------------------------  // acclient.c:790003
int _E318_4()
{
  PStringBase<char>::PStringBase<char>(&Negative_8, "Negative");
  return atexit(_E319_14);
}

//----- (007027E0) --------------------------------------------------------  // acclient.c:790010
int _E321_3()
{
  PStringBase<char>::PStringBase<char>(&Polygon_18, "PolygonIndex");
  return atexit(_E322_14);
}

//----- (00702800) --------------------------------------------------------  // acclient.c:790017
int _E324_4()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_17, "OtherCellMeshIndex");
  return atexit(_E325_13);
}

//----- (00702820) --------------------------------------------------------  // acclient.c:790024
int _E327_3()
{
  PStringBase<char>::PStringBase<char>(&CellPortal_8, "CellPortal");
  return atexit(_E328_14);
}

//----- (00702840) --------------------------------------------------------  // acclient.c:790031
int _E330_4()
{
  PStringBase<char>::PStringBase<char>(&Portal_11, "PortalIndex");
  return atexit(_E331_13);
}

//----- (00702860) --------------------------------------------------------  // acclient.c:790038
int _E333_3()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_18, "OtherCellID");
  return atexit(_E334_13);
}

//----- (00702880) --------------------------------------------------------  // acclient.c:790045
int _E336_3()
{
  PStringBase<char>::PStringBase<char>(&OtherPortal_8, "OtherPortalIndex");
  return atexit(_E337_13);
}

//----- (007028A0) --------------------------------------------------------  // acclient.c:790052
int _E339_3()
{
  PStringBase<char>::PStringBase<char>(&ExactMatch_8, "ExactMatch");
  return atexit(_E340_13);
}

//----- (007028C0) --------------------------------------------------------  // acclient.c:790059
int _E342_3()
{
  PStringBase<char>::PStringBase<char>(&StabList_8, "StabList");
  return atexit(_E343_10);
}

//----- (007028E0) --------------------------------------------------------  // acclient.c:790066
int _E345_3()
{
  PStringBase<char>::PStringBase<char>(&Period_8, "Period");
  return atexit(_E346_10);
}

//----- (00702900) --------------------------------------------------------  // acclient.c:790073
int _E348_3()
{
  PStringBase<char>::PStringBase<char>(&GrannyAnimation_8, "GrannyAnimation");
  return atexit(_E349_10);
}

//----- (00702920) --------------------------------------------------------  // acclient.c:790080
int _E351_3()
{
  PStringBase<char>::PStringBase<char>(&Transform_8, "Transform");
  return atexit(_E352_10);
}

//----- (00702940) --------------------------------------------------------  // acclient.c:790087
int _E354_3()
{
  PStringBase<char>::PStringBase<char>(&Scale_26, "Scale");
  return atexit(_E355_10);
}

//----- (00702960) --------------------------------------------------------  // acclient.c:790094
int _E357_3()
{
  PStringBase<char>::PStringBase<char>(&Weight_8, "Weight");
  return atexit(_E358_10);
}

//----- (00702980) --------------------------------------------------------  // acclient.c:790101
int _E360_3()
{
  PStringBase<char>::PStringBase<char>(&Offset_8, "Offset");
  return atexit(_E361_10);
}

//----- (007029A0) --------------------------------------------------------  // acclient.c:790108
int _E363_3()
{
  PStringBase<char>::PStringBase<char>(&Quaternion_9, "Quaternion");
  return atexit(_E364_10);
}

//----- (007029C0) --------------------------------------------------------  // acclient.c:790115
int _E366_3()
{
  PStringBase<char>::PStringBase<char>(&Rotation_17, "Rotation");
  return atexit(_E367_10);
}

//----- (007029E0) --------------------------------------------------------  // acclient.c:790122
int _E369_3()
{
  PStringBase<char>::PStringBase<char>(&STime_8, "STime");
  return atexit(_E370_10);
}

//----- (00702A00) --------------------------------------------------------  // acclient.c:790129
int _E372_3()
{
  PStringBase<char>::PStringBase<char>(&PhysicsSplines_8, "PhysicsSplines");
  return atexit(_E373_10);
}

//----- (00702A20) --------------------------------------------------------  // acclient.c:790136
int _E375_3()
{
  PStringBase<char>::PStringBase<char>(&BoneOpacities_8, "BoneOpacities");
  return atexit(_E376_10);
}

//----- (00702A40) --------------------------------------------------------  // acclient.c:790143
int _E378_3()
{
  PStringBase<char>::PStringBase<char>(&LowPt_8, "LowPoint");
  return atexit(_E379_10);
}

//----- (00702A60) --------------------------------------------------------  // acclient.c:790150
int _E381_3()
{
  PStringBase<char>::PStringBase<char>(&Radius_8, "Radius");
  return atexit(_E382_10);
}

//----- (00702A80) --------------------------------------------------------  // acclient.c:790157
int _E384_3()
{
  PStringBase<char>::PStringBase<char>(&Height_8, "Height");
  return atexit(_E385_10);
}

//----- (00702AA0) --------------------------------------------------------  // acclient.c:790164
int _E387_3()
{
  PStringBase<char>::PStringBase<char>(&Texture2D_8, "Texture2D");
  return atexit(_E388_10);
}

//----- (00702AC0) --------------------------------------------------------  // acclient.c:790171
int _E390_3()
{
  PStringBase<char>::PStringBase<char>(&Texture3D_8, "Texture3D");
  return atexit(_E391_10);
}

//----- (00702AE0) --------------------------------------------------------  // acclient.c:790178
int _E393_3()
{
  PStringBase<char>::PStringBase<char>(&TextureCube_8, "TextureCube");
  return atexit(_E394_10);
}

//----- (00702B00) --------------------------------------------------------  // acclient.c:790185
int _E396_3()
{
  PStringBase<char>::PStringBase<char>(&TextureMovie2D_8, "TextureMovie2D");
  return atexit(_E397_10);
}

//----- (00702B20) --------------------------------------------------------  // acclient.c:790192
int _E399_3()
{
  PStringBase<char>::PStringBase<char>(&MovieFileName_8, "MovieFile");
  return atexit(_E400_10);
}

//----- (00702B40) --------------------------------------------------------  // acclient.c:790199
int _E402_3()
{
  PStringBase<char>::PStringBase<char>(&MovieFramesPerSecond_8, "MovieFPS");
  return atexit(_E403_10);
}

//----- (00702B60) --------------------------------------------------------  // acclient.c:790206
int _E405_3()
{
  PStringBase<char>::PStringBase<char>(&Levels_8, "Levels");
  return atexit(_E406_10);
}

//----- (00702B80) --------------------------------------------------------  // acclient.c:790213
int _E408_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_89, "Instance");
  return atexit(_E409_10);
}

//----- (00702BA0) --------------------------------------------------------  // acclient.c:790220
int _E411_3()
{
  PStringBase<char>::PStringBase<char>(&Material_40, "Material");
  return atexit(_E412_10);
}

//----- (00702BC0) --------------------------------------------------------  // acclient.c:790227
int _E414_3()
{
  PStringBase<char>::PStringBase<char>(&MaterialType_8, "MaterialType");
  return atexit(_E415_10);
}

//----- (00702BE0) --------------------------------------------------------  // acclient.c:790234
int _E417_3()
{
  PStringBase<char>::PStringBase<char>(&Modifier_8, "Modifier");
  return atexit(_E418_10);
}

//----- (00702C00) --------------------------------------------------------  // acclient.c:790241
int _E420_3()
{
  PStringBase<char>::PStringBase<char>(&AllowStencilShadows_8, "AllowStencilShadows");
  return atexit(_E421_10);
}

//----- (00702C20) --------------------------------------------------------  // acclient.c:790248
int _E423_3()
{
  PStringBase<char>::PStringBase<char>(&DiscardGeometry_8, "DiscardGeometry");
  return atexit(_E424_10);
}

//----- (00702C40) --------------------------------------------------------  // acclient.c:790255
int _E426_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_90, "Material");
  return atexit(_E427_10);
}

//----- (00702C60) --------------------------------------------------------  // acclient.c:790262
int _E429_3()
{
  PStringBase<char>::PStringBase<char>(&SortMode_8, "SortMode");
  return atexit(_E430_10);
}

//----- (00702C80) --------------------------------------------------------  // acclient.c:790269
int _E432_3()
{
  PStringBase<char>::PStringBase<char>(&SortMode_None_8, "None");
  return atexit(_E433_10);
}

//----- (00702CA0) --------------------------------------------------------  // acclient.c:790276
int _E435_3()
{
  PStringBase<char>::PStringBase<char>(&SortMode_Triangle_8, "Triangle");
  return atexit(_E436_10);
}

//----- (00702CC0) --------------------------------------------------------  // acclient.c:790283
int _E438_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_91, "Modifier");
  return atexit(_E439_10);
}

//----- (00702CE0) --------------------------------------------------------  // acclient.c:790290
int _E441_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_92, "Property");
  return atexit(_E442_10);
}

//----- (00702D00) --------------------------------------------------------  // acclient.c:790297
int _E444_3()
{
  PStringBase<char>::PStringBase<char>(&DataType_DATA_8, "Data");
  return atexit(_E445_10);
}

//----- (00702D20) --------------------------------------------------------  // acclient.c:790304
int _E447_3()
{
  PStringBase<char>::PStringBase<char>(&DataType_WAVEFORM_8, "Waveform");
  return atexit(_E448_10);
}

//----- (00702D40) --------------------------------------------------------  // acclient.c:790311
int _E450_3()
{
  PStringBase<char>::PStringBase<char>(&DataType_COLOR_8, "Color");
  return atexit(_E451_10);
}

//----- (00702D60) --------------------------------------------------------  // acclient.c:790318
int _E453_3()
{
  PStringBase<char>::PStringBase<char>(&DataType_TEXTURE_8, "Texture");
  return atexit(_E454_10);
}

//----- (00702D80) --------------------------------------------------------  // acclient.c:790325
int _E456_3()
{
  PStringBase<char>::PStringBase<char>(&DataType_BOOL_8, "Bool");
  return atexit(_E457_10);
}

//----- (00702DA0) --------------------------------------------------------  // acclient.c:790332
int _E459_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_93, "Layer");
  return atexit(_E460_10);
}

//----- (00702DC0) --------------------------------------------------------  // acclient.c:790339
int _E462_3()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTranslate_8, "UVTranslate");
  return atexit(_E463_10);
}

//----- (00702DE0) --------------------------------------------------------  // acclient.c:790346
int _E465_3()
{
  PStringBase<char>::PStringBase<char>(&modType_UVRotate_8, "UVRotate");
  return atexit(_E466_10);
}

//----- (00702E00) --------------------------------------------------------  // acclient.c:790353
int _E468_3()
{
  PStringBase<char>::PStringBase<char>(&modType_UVScale_8, "UVScale");
  return atexit(_E469_10);
}

//----- (00702E20) --------------------------------------------------------  // acclient.c:790360
int _E471_3()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTransform_8, "UVTransform");
  return atexit(_E472_10);
}

//----- (00702E40) --------------------------------------------------------  // acclient.c:790367
int _E474_3()
{
  PStringBase<char>::PStringBase<char>(&TrueFlags_8, "TrueFlags");
  return atexit(_E475_10);
}

//----- (00702E60) --------------------------------------------------------  // acclient.c:790374
int _E477_3()
{
  PStringBase<char>::PStringBase<char>(&FalseFlags_8, "FalseFlags");
  return atexit(_E478_10);
}

//----- (00702E80) --------------------------------------------------------  // acclient.c:790381
int _E480_3()
{
  PStringBase<char>::PStringBase<char>(&RenderPass_8, "RenderPass");
  return atexit(_E481_10);
}

//----- (00702EA0) --------------------------------------------------------  // acclient.c:790388
int _E483_3()
{
  PStringBase<char>::PStringBase<char>(&Blend_8, "Blend");
  return atexit(_E484_10);
}

//----- (00702EC0) --------------------------------------------------------  // acclient.c:790395
int _E486_3()
{
  PStringBase<char>::PStringBase<char>(&DepthTest_8, "DepthTest");
  return atexit(_E487_10);
}

//----- (00702EE0) --------------------------------------------------------  // acclient.c:790402
int _E489_3()
{
  PStringBase<char>::PStringBase<char>(&DepthWrite_8, "DepthWrite");
  return atexit(_E490_10);
}

//----- (00702F00) --------------------------------------------------------  // acclient.c:790409
int _E492_3()
{
  PStringBase<char>::PStringBase<char>(&CullMode_8, "CullMode");
  return atexit(_E493_10);
}

//----- (00702F20) --------------------------------------------------------  // acclient.c:790416
int _E495_3()
{
  PStringBase<char>::PStringBase<char>(&DepthFog_8, "DepthFog");
  return atexit(_E496_10);
}

//----- (00702F40) --------------------------------------------------------  // acclient.c:790423
int _E498_3()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestMode_8, "AlphaTestMode");
  return atexit(_E499_10);
}

//----- (00702F60) --------------------------------------------------------  // acclient.c:790430
int _E501_3()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestRef_8, "AlphaTestRef");
  return atexit(_E502_10);
}

//----- (00702F80) --------------------------------------------------------  // acclient.c:790437
int _E504_3()
{
  PStringBase<char>::PStringBase<char>(&FFUseLighting_8, "FFUseLighting");
  return atexit(_E505_10);
}

//----- (00702FA0) --------------------------------------------------------  // acclient.c:790444
int _E507_3()
{
  PStringBase<char>::PStringBase<char>(&FFUseDyeColorInTFactor_8, "FFUseDyeColorInTFactor");
  return atexit(_E508_10);
}

//----- (00702FC0) --------------------------------------------------------  // acclient.c:790451
int _E510_3()
{
  PStringBase<char>::PStringBase<char>(&FFUseSpecularLighting_8, "FFUseSpecularLighting");
  return atexit(_E511_10);
}

//----- (00702FE0) --------------------------------------------------------  // acclient.c:790458
int _E513_3()
{
  PStringBase<char>::PStringBase<char>(&FFUseDistanceFog_8, "FFUseDistanceFog");
  return atexit(_E514_10);
}

//----- (00703000) --------------------------------------------------------  // acclient.c:790465
int _E516_3()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexDiffuse_8, "FFUseVertexDiffuse");
  return atexit(_E517_10);
}

//----- (00703020) --------------------------------------------------------  // acclient.c:790472
int _E519_3()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexSpecular_8, "FFUseVertexSpecular");
  return atexit(_E520_10);
}

//----- (00703040) --------------------------------------------------------  // acclient.c:790479
int _E522_3()
{
  PStringBase<char>::PStringBase<char>(&ShaderSupportsDynamicLights_8, "ShaderSupportsDynamicLights");
  return atexit(_E523_10);
}

//----- (00703060) --------------------------------------------------------  // acclient.c:790486
int _E525_3()
{
  PStringBase<char>::PStringBase<char>(&UsesTransparency_8, "UsesTransparency");
  return atexit(_E526_10);
}

//----- (00703080) --------------------------------------------------------  // acclient.c:790493
int _E528_3()
{
  PStringBase<char>::PStringBase<char>(&Ambient_8, "Ambient");
  return atexit(_E529_10);
}

//----- (007030A0) --------------------------------------------------------  // acclient.c:790500
int _E531_3()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_18, "Diffuse");
  return atexit(_E532_10);
}

//----- (007030C0) --------------------------------------------------------  // acclient.c:790507
int _E534_3()
{
  PStringBase<char>::PStringBase<char>(&Specular_18, "Specular");
  return atexit(_E535_10);
}

//----- (007030E0) --------------------------------------------------------  // acclient.c:790514
int _E537_3()
{
  PStringBase<char>::PStringBase<char>(&SpecularPower_8, "SpecularPower");
  return atexit(_E538_10);
}

//----- (00703100) --------------------------------------------------------  // acclient.c:790521
int _E540_3()
{
  PStringBase<char>::PStringBase<char>(&Dye_8, "Dye");
  return atexit(_E541_10);
}

//----- (00703120) --------------------------------------------------------  // acclient.c:790528
int _E543_3()
{
  PStringBase<char>::PStringBase<char>(&Emissive_8, "Emissive");
  return atexit(_E544_10);
}

//----- (00703140) --------------------------------------------------------  // acclient.c:790535
int _E546_3()
{
  PStringBase<char>::PStringBase<char>(&VertexFormat_8, "VertexFormat");
  return atexit(_E547_10);
}

//----- (00703160) --------------------------------------------------------  // acclient.c:790542
int _E549_3()
{
  PStringBase<char>::PStringBase<char>(&VertexShader_8, "VertexShader");
  return atexit(_E550_10);
}

//----- (00703180) --------------------------------------------------------  // acclient.c:790549
int _E552_3()
{
  PStringBase<char>::PStringBase<char>(&PixelShader_8, "PixelShader");
  return atexit(_E553_10);
}

//----- (007031A0) --------------------------------------------------------  // acclient.c:790556
int _E555_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_NONE_8, "None");
  return atexit(_E556_10);
}

//----- (007031C0) --------------------------------------------------------  // acclient.c:790563
int _E558_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_REFLECTIONS_8, "Reflections");
  return atexit(_E559_10);
}

//----- (007031E0) --------------------------------------------------------  // acclient.c:790570
int _E561_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_VIDEOPOST_8, "VideoPost");
  return atexit(_E562_10);
}

//----- (00703200) --------------------------------------------------------  // acclient.c:790577
int _E564_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_HIGHDETAIL_8, "HighDetail");
  return atexit(_E565_10);
}

//----- (00703220) --------------------------------------------------------  // acclient.c:790584
int _E567_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_SPECULAR_8, "Specular");
  return atexit(_E568_10);
}

//----- (00703240) --------------------------------------------------------  // acclient.c:790591
int _E570_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS1_8, "Class1");
  return atexit(_E571_10);
}

//----- (00703260) --------------------------------------------------------  // acclient.c:790598
int _E573_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS2_8, "Class2");
  return atexit(_E574_10);
}

//----- (00703280) --------------------------------------------------------  // acclient.c:790605
int _E576_3()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS3_8, "Class3");
  return atexit(_E577_10);
}

//----- (007032A0) --------------------------------------------------------  // acclient.c:790612
int _E579_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_Default_8, "Default");
  return atexit(_E580_10);
}

//----- (007032C0) --------------------------------------------------------  // acclient.c:790619
int _E582_3()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_DirectionalLightDiffuseAndSpecular_8,
    "DirectionalLightDiffuseAndSpecular");
  return atexit(_E583_10);
}

//----- (007032E0) --------------------------------------------------------  // acclient.c:790628
int _E585_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_PointLightDiffuseAndSpecular_8, "PointLightDiffuseAndSpecular");
  return atexit(_E586_10);
}

//----- (00703300) --------------------------------------------------------  // acclient.c:790635
int _E588_3()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_PointLightDiffuseAndSpecularProjector_8,
    "PointLightDiffuseAndSpecularProjector");
  return atexit(_E589_10);
}

//----- (00703320) --------------------------------------------------------  // acclient.c:790644
int _E591_3()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_8,
    "AmbientLight_DirectionalLightDiffuseAndSpecular");
  return atexit(_E592_10);
}

//----- (00703340) --------------------------------------------------------  // acclient.c:790653
int _E594_3()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_8,
    "AmbientLight_PointLightDiffuseAndSpecular");
  return atexit(_E595_10);
}

//----- (00703360) --------------------------------------------------------  // acclient.c:790662
int _E597_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_DistanceFog_8, "DistanceFog");
  return atexit(_E598_10);
}

//----- (00703380) --------------------------------------------------------  // acclient.c:790669
int _E600_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_FixedFunctionGlow_8, "FFGlow");
  return atexit(_E601_10);
}

//----- (007033A0) --------------------------------------------------------  // acclient.c:790676
int _E603_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_ShaderGlow_8, "ShaderGlow");
  return atexit(_E604_10);
}

//----- (007033C0) --------------------------------------------------------  // acclient.c:790683
int _E606_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_LandscapeShadowMap_8, "LandscapeShadowMap");
  return atexit(_E607_10);
}

//----- (007033E0) --------------------------------------------------------  // acclient.c:790690
int _E609_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AlphaBlend_8, "AlphaBlend");
  return atexit(_E610_10);
}

//----- (00703400) --------------------------------------------------------  // acclient.c:790697
int _E612_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_8, "AL_0DL_0PL");
  return atexit(_E613_10);
}

//----- (00703420) --------------------------------------------------------  // acclient.c:790704
int _E615_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_8, "AL_0DL_1PL");
  return atexit(_E616_10);
}

//----- (00703440) --------------------------------------------------------  // acclient.c:790711
int _E618_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_8, "AL_0DL_2PL");
  return atexit(_E619_10);
}

//----- (00703460) --------------------------------------------------------  // acclient.c:790718
int _E621_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_8, "AL_0DL_3PL");
  return atexit(_E622_10);
}

//----- (00703480) --------------------------------------------------------  // acclient.c:790725
int _E624_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_8, "AL_0DL_4PL");
  return atexit(_E625_10);
}

//----- (007034A0) --------------------------------------------------------  // acclient.c:790732
int _E627_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_8, "AL_0DL_5PL");
  return atexit(_E628_10);
}

//----- (007034C0) --------------------------------------------------------  // acclient.c:790739
int _E630_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_8, "AL_0DL_6PL");
  return atexit(_E631_10);
}

//----- (007034E0) --------------------------------------------------------  // acclient.c:790746
int _E633_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_8, "AL_0DL_7PL");
  return atexit(_E634_10);
}

//----- (00703500) --------------------------------------------------------  // acclient.c:790753
int _E636_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_8, "AL_0DL_8PL");
  return atexit(_E637_10);
}

//----- (00703520) --------------------------------------------------------  // acclient.c:790760
int _E639_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_8, "AL_1DL_0PL");
  return atexit(_E640_10);
}

//----- (00703540) --------------------------------------------------------  // acclient.c:790767
int _E642_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_8, "AL_1DL_1PL");
  return atexit(_E643_10);
}

//----- (00703560) --------------------------------------------------------  // acclient.c:790774
int _E645_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_8, "AL_1DL_2PL");
  return atexit(_E646_10);
}

//----- (00703580) --------------------------------------------------------  // acclient.c:790781
int _E648_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_8, "AL_1DL_3PL");
  return atexit(_E649_10);
}

//----- (007035A0) --------------------------------------------------------  // acclient.c:790788
int _E651_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_8, "AL_1DL_4PL");
  return atexit(_E652_10);
}

//----- (007035C0) --------------------------------------------------------  // acclient.c:790795
int _E654_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_8, "AL_1DL_5PL");
  return atexit(_E655_10);
}

//----- (007035E0) --------------------------------------------------------  // acclient.c:790802
int _E657_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_8, "AL_1DL_6PL");
  return atexit(_E658_10);
}

//----- (00703600) --------------------------------------------------------  // acclient.c:790809
int _E660_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_8, "AL_1DL_7PL");
  return atexit(_E661_10);
}

//----- (00703620) --------------------------------------------------------  // acclient.c:790816
int _E663_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_Fog_8, "AL_0DL_0PL_Fog");
  return atexit(_E664_10);
}

//----- (00703640) --------------------------------------------------------  // acclient.c:790823
int _E666_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_Fog_8, "AL_0DL_1PL_Fog");
  return atexit(_E667_10);
}

//----- (00703660) --------------------------------------------------------  // acclient.c:790830
int _E669_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_Fog_8, "AL_0DL_2PL_Fog");
  return atexit(_E670_10);
}

//----- (00703680) --------------------------------------------------------  // acclient.c:790837
int _E672_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_Fog_8, "AL_0DL_3PL_Fog");
  return atexit(_E673_10);
}

//----- (007036A0) --------------------------------------------------------  // acclient.c:790844
int _E675_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_Fog_8, "AL_0DL_4PL_Fog");
  return atexit(_E676_10);
}

//----- (007036C0) --------------------------------------------------------  // acclient.c:790851
int _E678_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_Fog_8, "AL_0DL_5PL_Fog");
  return atexit(_E679_10);
}

//----- (007036E0) --------------------------------------------------------  // acclient.c:790858
int _E681_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_Fog_8, "AL_0DL_6PL_Fog");
  return atexit(_E682_10);
}

//----- (00703700) --------------------------------------------------------  // acclient.c:790865
int _E684_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_Fog_8, "AL_0DL_7PL_Fog");
  return atexit(_E685_10);
}

//----- (00703720) --------------------------------------------------------  // acclient.c:790872
int _E687_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_Fog_8, "AL_0DL_8PL_Fog");
  return atexit(_E688_10);
}

//----- (00703740) --------------------------------------------------------  // acclient.c:790879
int _E690_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_Fog_8, "AL_1DL_0PL_Fog");
  return atexit(_E691_10);
}

//----- (00703760) --------------------------------------------------------  // acclient.c:790886
int _E693_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_Fog_8, "AL_1DL_1PL_Fog");
  return atexit(_E694_10);
}

//----- (00703780) --------------------------------------------------------  // acclient.c:790893
int _E696_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_Fog_8, "AL_1DL_2PL_Fog");
  return atexit(_E697_10);
}

//----- (007037A0) --------------------------------------------------------  // acclient.c:790900
int _E699_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_Fog_8, "AL_1DL_3PL_Fog");
  return atexit(_E700_10);
}

//----- (007037C0) --------------------------------------------------------  // acclient.c:790907
int _E702_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_Fog_8, "AL_1DL_4PL_Fog");
  return atexit(_E703_10);
}

//----- (007037E0) --------------------------------------------------------  // acclient.c:790914
int _E705_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_Fog_8, "AL_1DL_5PL_Fog");
  return atexit(_E706_10);
}

//----- (00703800) --------------------------------------------------------  // acclient.c:790921
int _E708_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_Fog_8, "AL_1DL_6PL_Fog");
  return atexit(_E709_10);
}

//----- (00703820) --------------------------------------------------------  // acclient.c:790928
int _E711_3()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_Fog_8, "AL_1DL_7PL_Fog");
  return atexit(_E712_10);
}

//----- (00703840) --------------------------------------------------------  // acclient.c:790935
int _E714_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ZERO_8, "Zero");
  return atexit(_E715_10);
}

//----- (00703860) --------------------------------------------------------  // acclient.c:790942
int _E717_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ONE_8, "One");
  return atexit(_E718_10);
}

//----- (00703880) --------------------------------------------------------  // acclient.c:790949
int _E720_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCCOLOR_8, "SrcColor");
  return atexit(_E721_10);
}

//----- (007038A0) --------------------------------------------------------  // acclient.c:790956
int _E723_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCCOLOR_8, "InvSrcColor");
  return atexit(_E724_10);
}

//----- (007038C0) --------------------------------------------------------  // acclient.c:790963
int _E726_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHA_8, "SrcAlpha");
  return atexit(_E727_10);
}

//----- (007038E0) --------------------------------------------------------  // acclient.c:790970
int _E729_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCALPHA_8, "InvSrcAlpha");
  return atexit(_E730_10);
}

//----- (00703900) --------------------------------------------------------  // acclient.c:790977
int _E732_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTALPHA_8, "DstAlpha");
  return atexit(_E733_10);
}

//----- (00703920) --------------------------------------------------------  // acclient.c:790984
int _E735_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTALPHA_8, "InvDstAlpha");
  return atexit(_E736_10);
}

//----- (00703940) --------------------------------------------------------  // acclient.c:790991
int _E738_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTCOLOR_8, "DstColor");
  return atexit(_E739_10);
}

//----- (00703960) --------------------------------------------------------  // acclient.c:790998
int _E741_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTCOLOR_8, "InvDstColor");
  return atexit(_E742_10);
}

//----- (00703980) --------------------------------------------------------  // acclient.c:791005
int _E744_3()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHASAT_8, "SrcAlphaSat");
  return atexit(_E745_10);
}

//----- (007039A0) --------------------------------------------------------  // acclient.c:791012
int _E747_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESS_8, "Less");
  return atexit(_E748_10);
}

//----- (007039C0) --------------------------------------------------------  // acclient.c:791019
int _E750_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_EQUAL_8, "Equal");
  return atexit(_E751_10);
}

//----- (007039E0) --------------------------------------------------------  // acclient.c:791026
int _E753_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESSEQUAL_8, "LessEqual");
  return atexit(_E754_10);
}

//----- (00703A00) --------------------------------------------------------  // acclient.c:791033
int _E756_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATER_8, "Greater");
  return atexit(_E757_10);
}

//----- (00703A20) --------------------------------------------------------  // acclient.c:791040
int _E759_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_NOTEQUAL_8, "NotEqual");
  return atexit(_E760_10);
}

//----- (00703A40) --------------------------------------------------------  // acclient.c:791047
int _E762_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATEREQUAL_8, "GreaterEqual");
  return atexit(_E763_10);
}

//----- (00703A60) --------------------------------------------------------  // acclient.c:791054
int _E765_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_ALWAYS_8, "Always");
  return atexit(_E766_10);
}

//----- (00703A80) --------------------------------------------------------  // acclient.c:791061
int _E768_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_ON_8, "On");
  return atexit(_E769_10);
}

//----- (00703AA0) --------------------------------------------------------  // acclient.c:791068
int _E771_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_OFF_8, "Off");
  return atexit(_E772_10);
}

//----- (00703AC0) --------------------------------------------------------  // acclient.c:791075
int _E774_3()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERDIFFUSE_8, "LayerDiffuse");
  return atexit(_E775_10);
}

//----- (00703AE0) --------------------------------------------------------  // acclient.c:791082
int _E777_3()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERSPECULAR_8, "LayerSpecular");
  return atexit(_E778_10);
}

//----- (00703B00) --------------------------------------------------------  // acclient.c:791089
int _E780_3()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXDIFFUSE_8, "VertexDiffuse");
  return atexit(_E781_10);
}

//----- (00703B20) --------------------------------------------------------  // acclient.c:791096
int _E783_3()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXSPECULAR_8, "VertexSpecular");
  return atexit(_E784_10);
}

//----- (00703B40) --------------------------------------------------------  // acclient.c:791103
int _E786_3()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_NONE_8, "None");
  return atexit(_E787_10);
}

//----- (00703B60) --------------------------------------------------------  // acclient.c:791110
int _E789_3()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CW_8, "CW");
  return atexit(_E790_10);
}

//----- (00703B80) --------------------------------------------------------  // acclient.c:791117
int _E792_3()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CCW_8, "CCW");
  return atexit(_E793_10);
}

//----- (00703BA0) --------------------------------------------------------  // acclient.c:791124
int _E795_3()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_NONE_8, "None");
  return atexit(_E796_10);
}

//----- (00703BC0) --------------------------------------------------------  // acclient.c:791131
int _E798_3()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SIMPLE_8, "Simple");
  return atexit(_E799_10);
}

//----- (00703BE0) --------------------------------------------------------  // acclient.c:791138
int _E801_3()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_DIFFUSE_8, "Diffuse");
  return atexit(_E802_10);
}

//----- (00703C00) --------------------------------------------------------  // acclient.c:791145
int _E804_3()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SPECULAR_8, "Specular");
  return atexit(_E805_10);
}

//----- (00703C20) --------------------------------------------------------  // acclient.c:791152
int _E807_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_OFF_8, "Off");
  return atexit(_E808_10);
}

//----- (00703C40) --------------------------------------------------------  // acclient.c:791159
int _E810_3()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_ON_8, "On");
  return atexit(_E811_10);
}

//----- (00703C60) --------------------------------------------------------  // acclient.c:791166
int _E813_3()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_OFF_8, "Off");
  return atexit(_E814_10);
}

//----- (00703C80) --------------------------------------------------------  // acclient.c:791173
int _E816_3()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_ON_8, "On");
  return atexit(_E817_10);
}

//----- (00703CA0) --------------------------------------------------------  // acclient.c:791180
int _E819_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_ORIGIN_8, "Origin");
  return atexit(_E820_10);
}

//----- (00703CC0) --------------------------------------------------------  // acclient.c:791187
int _E822_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_NORMAL_8, "Normal");
  return atexit(_E823_10);
}

//----- (00703CE0) --------------------------------------------------------  // acclient.c:791194
int _E825_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_POINTSIZE_8, "PointSize");
  return atexit(_E826_10);
}

//----- (00703D00) --------------------------------------------------------  // acclient.c:791201
int _E828_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_DIFFUSE_8, "Diffuse");
  return atexit(_E829_10);
}

//----- (00703D20) --------------------------------------------------------  // acclient.c:791208
int _E831_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_SPECULAR_8, "Specular");
  return atexit(_E832_10);
}

//----- (00703D40) --------------------------------------------------------  // acclient.c:791215
int _E834_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx1_8, "TCPairX1");
  return atexit(_E835_10);
}

//----- (00703D60) --------------------------------------------------------  // acclient.c:791222
int _E837_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx2_8, "TCPairX2");
  return atexit(_E838_10);
}

//----- (00703D80) --------------------------------------------------------  // acclient.c:791229
int _E840_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx3_8, "TCPairX3");
  return atexit(_E841_10);
}

//----- (00703DA0) --------------------------------------------------------  // acclient.c:791236
int _E843_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx4_8, "TCPairX4");
  return atexit(_E844_10);
}

//----- (00703DC0) --------------------------------------------------------  // acclient.c:791243
int _E846_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx5_8, "TCPairX5");
  return atexit(_E847_10);
}

//----- (00703DE0) --------------------------------------------------------  // acclient.c:791250
int _E849_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx6_8, "TCPairX6");
  return atexit(_E850_10);
}

//----- (00703E00) --------------------------------------------------------  // acclient.c:791257
int _E852_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx7_8, "TCPairX7");
  return atexit(_E853_10);
}

//----- (00703E20) --------------------------------------------------------  // acclient.c:791264
int _E855_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx8_8, "TCPairX8");
  return atexit(_E856_10);
}

//----- (00703E40) --------------------------------------------------------  // acclient.c:791271
int _E858_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_S_8, "VectorS");
  return atexit(_E859_10);
}

//----- (00703E60) --------------------------------------------------------  // acclient.c:791278
int _E861_3()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_T_8, "VectorT");
  return atexit(_E862_10);
}

//----- (00703E80) --------------------------------------------------------  // acclient.c:791285
int _E864_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_94, "Stage");
  return atexit(_E865_10);
}

//----- (00703EA0) --------------------------------------------------------  // acclient.c:791292
int _E867_3()
{
  PStringBase<char>::PStringBase<char>(&SamplerNodeName_8, "Sampler");
  return atexit(_E868_10);
}

//----- (00703EC0) --------------------------------------------------------  // acclient.c:791299
int _E870_3()
{
  PStringBase<char>::PStringBase<char>(&SamplerName_8, "SamplerName");
  return atexit(_E871_10);
}

//----- (00703EE0) --------------------------------------------------------  // acclient.c:791306
int _E873_3()
{
  PStringBase<char>::PStringBase<char>(&Texture_8, "Texture");
  return atexit(_E874_10);
}

//----- (00703F00) --------------------------------------------------------  // acclient.c:791313
int _E876_3()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_FrameBuffer_8, "!FrameBuffer");
  return atexit(_E877_10);
}

//----- (00703F20) --------------------------------------------------------  // acclient.c:791320
int _E879_3()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Distortion_8, "!Distortion");
  return atexit(_E880_10);
}

//----- (00703F40) --------------------------------------------------------  // acclient.c:791327
int _E882_3()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Reflection_8, "!Reflection");
  return atexit(_E883_10);
}

//----- (00703F60) --------------------------------------------------------  // acclient.c:791334
int _E885_3()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_NormalizeCube_8, "!NormalizeCube");
  return atexit(_E886_10);
}

//----- (00703F80) --------------------------------------------------------  // acclient.c:791341
int _E888_3()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LightProjectorCube_8, "!LightProjectorCube");
  return atexit(_E889_10);
}

//----- (00703FA0) --------------------------------------------------------  // acclient.c:791348
int _E891_3()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_EnvironmentCube_8, "!EnvironmentCube");
  return atexit(_E892_10);
}

//----- (00703FC0) --------------------------------------------------------  // acclient.c:791355
int _E894_3()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LandscapeShadows_8, "!LandscapeShadows");
  return atexit(_E895_10);
}

//----- (00703FE0) --------------------------------------------------------  // acclient.c:791362
int _E897_3()
{
  PStringBase<char>::PStringBase<char>(&AddressMode_8, "AddressMode");
  return atexit(_E898_10);
}

//----- (00704000) --------------------------------------------------------  // acclient.c:791369
int _E900_3()
{
  PStringBase<char>::PStringBase<char>(&TexFilter_8, "FilterMode");
  return atexit(_E901_10);
}

//----- (00704020) --------------------------------------------------------  // acclient.c:791376
int _E903_3()
{
  PStringBase<char>::PStringBase<char>(&ColorOp_8, "FFColorOp");
  return atexit(_E904_10);
}

//----- (00704040) --------------------------------------------------------  // acclient.c:791383
int _E906_3()
{
  PStringBase<char>::PStringBase<char>(&ColorArg1_8, "FFColorArg1");
  return atexit(_E907_10);
}

//----- (00704060) --------------------------------------------------------  // acclient.c:791390
int _E909_3()
{
  PStringBase<char>::PStringBase<char>(&ColorArg2_8, "FFColorArg2");
  return atexit(_E910_10);
}

//----- (00704080) --------------------------------------------------------  // acclient.c:791397
int _E912_3()
{
  PStringBase<char>::PStringBase<char>(&AlphaOp_8, "FFAlphaOp");
  return atexit(_E913_10);
}

//----- (007040A0) --------------------------------------------------------  // acclient.c:791404
int _E915_3()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg1_8, "FFAlphaArg1");
  return atexit(_E916_10);
}

//----- (007040C0) --------------------------------------------------------  // acclient.c:791411
int _E918_3()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg2_8, "FFAlphaArg2");
  return atexit(_E919_10);
}

//----- (007040E0) --------------------------------------------------------  // acclient.c:791418
int _E921_3()
{
  PStringBase<char>::PStringBase<char>(&TexCoord_8, "FFTexCoordIndex");
  return atexit(_E922_10);
}

//----- (00704100) --------------------------------------------------------  // acclient.c:791425
int _E924_3()
{
  PStringBase<char>::PStringBase<char>(&UseProjection_8, "FFUseProjection");
  return atexit(_E925_10);
}

//----- (00704120) --------------------------------------------------------  // acclient.c:791432
int _E927_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG1_8, "SelectArg1");
  return atexit(_E928_10);
}

//----- (00704140) --------------------------------------------------------  // acclient.c:791439
int _E930_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG2_8, "SelectArg2");
  return atexit(_E931_10);
}

//----- (00704160) --------------------------------------------------------  // acclient.c:791446
int _E933_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE_8, "Modulate");
  return atexit(_E934_10);
}

//----- (00704180) --------------------------------------------------------  // acclient.c:791453
int _E936_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE2X_8, "Modulate2X");
  return atexit(_E937_10);
}

//----- (007041A0) --------------------------------------------------------  // acclient.c:791460
int _E939_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE4X_8, "Modulate4X");
  return atexit(_E940_10);
}

//----- (007041C0) --------------------------------------------------------  // acclient.c:791467
int _E942_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADD_8, "Add");
  return atexit(_E943_10);
}

//----- (007041E0) --------------------------------------------------------  // acclient.c:791474
int _E945_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED_8, "AddSigned");
  return atexit(_E946_10);
}

//----- (00704200) --------------------------------------------------------  // acclient.c:791481
int _E948_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED2X_8, "AddSigned2X");
  return atexit(_E949_10);
}

//----- (00704220) --------------------------------------------------------  // acclient.c:791488
int _E951_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SUBTRACT_8, "Subtract");
  return atexit(_E952_10);
}

//----- (00704240) --------------------------------------------------------  // acclient.c:791495
int _E954_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSMOOTH_8, "AddSmooth");
  return atexit(_E955_10);
}

//----- (00704260) --------------------------------------------------------  // acclient.c:791502
int _E957_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDDIFFUSEALPHA_8, "BlendDiffuseAlpha");
  return atexit(_E958_10);
}

//----- (00704280) --------------------------------------------------------  // acclient.c:791509
int _E960_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHA_8, "BlendTextureAlpha");
  return atexit(_E961_10);
}

//----- (007042A0) --------------------------------------------------------  // acclient.c:791516
int _E963_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDFACTORALPHA_8, "BlendFactorAlpha");
  return atexit(_E964_10);
}

//----- (007042C0) --------------------------------------------------------  // acclient.c:791523
int _E966_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHAPM_8, "BlendTextureAlphaPM");
  return atexit(_E967_10);
}

//----- (007042E0) --------------------------------------------------------  // acclient.c:791530
int _E969_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDCURRENTALPHA_8, "BlendCurrentAlpha");
  return atexit(_E970_10);
}

//----- (00704300) --------------------------------------------------------  // acclient.c:791537
int _E972_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_PREMODULATE_8, "Premodulate");
  return atexit(_E973_10);
}

//----- (00704320) --------------------------------------------------------  // acclient.c:791544
int _E975_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEALPHA_ADDCOLOR_8, "ModulateAlphaAddColor");
  return atexit(_E976_10);
}

//----- (00704340) --------------------------------------------------------  // acclient.c:791551
int _E978_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATECOLOR_ADDALPHA_8, "ModulateColorAddAlpha");
  return atexit(_E979_10);
}

//----- (00704360) --------------------------------------------------------  // acclient.c:791558
int _E981_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_8, "ModulateInvAlphaAddColor");
  return atexit(_E982_10);
}

//----- (00704380) --------------------------------------------------------  // acclient.c:791565
int _E984_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_8, "ModulateInvColorAddAlpha");
  return atexit(_E985_10);
}

//----- (007043A0) --------------------------------------------------------  // acclient.c:791572
int _E987_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAP_8, "BumpEnvMap");
  return atexit(_E988_10);
}

//----- (007043C0) --------------------------------------------------------  // acclient.c:791579
int _E990_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAPLUMINANCE_8, "BumpEnvMapLuminance");
  return atexit(_E991_10);
}

//----- (007043E0) --------------------------------------------------------  // acclient.c:791586
int _E993_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_DOTPRODUCT3_8, "DotProduct3");
  return atexit(_E994_10);
}

//----- (00704400) --------------------------------------------------------  // acclient.c:791593
int _E996_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MULTIPLYADD_8, "MultiplyAdd");
  return atexit(_E997_10);
}

//----- (00704420) --------------------------------------------------------  // acclient.c:791600
int _E999_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_LERP_8, "Lerp");
  return atexit(_E1000_10);
}

//----- (00704440) --------------------------------------------------------  // acclient.c:791607
int _E1002_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_DIFFUSE_8, "Diffuse");
  return atexit(_E1003_10);
}

//----- (00704460) --------------------------------------------------------  // acclient.c:791614
int _E1005_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_SPECULAR_8, "Specular");
  return atexit(_E1006_10);
}

//----- (00704480) --------------------------------------------------------  // acclient.c:791621
int _E1008_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_CURRENT_8, "Current");
  return atexit(_E1009_10);
}

//----- (007044A0) --------------------------------------------------------  // acclient.c:791628
int _E1011_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TEXTURE_8, "Texture");
  return atexit(_E1012_10);
}

//----- (007044C0) --------------------------------------------------------  // acclient.c:791635
int _E1014_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TFACTOR_8, "TFactor");
  return atexit(_E1015_10);
}

//----- (007044E0) --------------------------------------------------------  // acclient.c:791642
int _E1017_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_WRAP_8, "Wrap");
  return atexit(_E1018_10);
}

//----- (00704500) --------------------------------------------------------  // acclient.c:791649
int _E1020_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_MIRROR_8, "Mirror");
  return atexit(_E1021_10);
}

//----- (00704520) --------------------------------------------------------  // acclient.c:791656
int _E1023_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_CLAMP_8, "Clamp");
  return atexit(_E1024_10);
}

//----- (00704540) --------------------------------------------------------  // acclient.c:791663
int _E1026_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_BORDER_8, "Border");
  return atexit(_E1027_10);
}

//----- (00704560) --------------------------------------------------------  // acclient.c:791670
int _E1029_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_NONE_8, "None");
  return atexit(_E1030_10);
}

//----- (00704580) --------------------------------------------------------  // acclient.c:791677
int _E1032_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_POINT_8, "Point");
  return atexit(_E1033_10);
}

//----- (007045A0) --------------------------------------------------------  // acclient.c:791684
int _E1035_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_LINEAR_8, "Linear");
  return atexit(_E1036_10);
}

//----- (007045C0) --------------------------------------------------------  // acclient.c:791691
int _E1038_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_ANISOTROPIC_8, "Anisotropic");
  return atexit(_E1039_10);
}

//----- (007045E0) --------------------------------------------------------  // acclient.c:791698
int _E1041_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ReflectionVector_8, "ReflectionVector");
  return atexit(_E1042_10);
}

//----- (00704600) --------------------------------------------------------  // acclient.c:791705
int _E1044_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewNormal_8, "ViewNormal");
  return atexit(_E1045_10);
}

//----- (00704620) --------------------------------------------------------  // acclient.c:791712
int _E1047_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewOrigin_8, "ViewOrigin");
  return atexit(_E1048_10);
}

//----- (00704640) --------------------------------------------------------  // acclient.c:791719
int _E1050_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_SphereMap_8, "SphereMap");
  return atexit(_E1051_10);
}

//----- (00704660) --------------------------------------------------------  // acclient.c:791726
int _E1053_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapReflection_8, "CubeMapReflection");
  return atexit(_E1054_10);
}

//----- (00704680) --------------------------------------------------------  // acclient.c:791733
int _E1056_3()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapFakeLight_8, "CubeMapFakeLight");
  return atexit(_E1057_10);
}

//----- (007046A0) --------------------------------------------------------  // acclient.c:791740
int _E1059_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_95, "FFModifier");
  return atexit(_E1060_10);
}

//----- (007046C0) --------------------------------------------------------  // acclient.c:791747
int _E1062_3()
{
  PStringBase<char>::PStringBase<char>(&ModType_Origin_8, "Origin");
  return atexit(_E1063_10);
}

//----- (007046E0) --------------------------------------------------------  // acclient.c:791754
int _E1065_3()
{
  PStringBase<char>::PStringBase<char>(&ModType_Normal_8, "Normal");
  return atexit(_E1066_10);
}

//----- (00704700) --------------------------------------------------------  // acclient.c:791761
int _E1068_3()
{
  PStringBase<char>::PStringBase<char>(&ModType_Diffuse_8, "Diffuse");
  return atexit(_E1069_10);
}

//----- (00704720) --------------------------------------------------------  // acclient.c:791768
int _E1071_3()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTranslate_8, "UVTranslate");
  return atexit(_E1072_10);
}

//----- (00704740) --------------------------------------------------------  // acclient.c:791775
int _E1074_3()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVRotate_8, "UVRotate");
  return atexit(_E1075_10);
}

//----- (00704760) --------------------------------------------------------  // acclient.c:791782
int _E1077_3()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVScale_8, "UVScale");
  return atexit(_E1078_10);
}

//----- (00704780) --------------------------------------------------------  // acclient.c:791789
int _E1080_3()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTransform_8, "UVTransform");
  return atexit(_E1081_10);
}

//----- (007047A0) --------------------------------------------------------  // acclient.c:791796
int _E1083_3()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_texCoordIndex_8, "TexCoordIndex");
  return atexit(_E1084_10);
}

//----- (007047C0) --------------------------------------------------------  // acclient.c:791803
int _E1086_3()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_translate_8, "Translate");
  return atexit(_E1087_10);
}

//----- (007047E0) --------------------------------------------------------  // acclient.c:791810
int _E1089_3()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_texCoordIndex_8, "TexCoordIndex");
  return atexit(_E1090_10);
}

//----- (00704800) --------------------------------------------------------  // acclient.c:791817
int _E1092_3()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_rotate_8, "Rotate");
  return atexit(_E1093_10);
}

//----- (00704820) --------------------------------------------------------  // acclient.c:791824
int _E1095_3()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_texCoordIndex_8, "TexCoordIndex");
  return atexit(_E1096_10);
}

//----- (00704840) --------------------------------------------------------  // acclient.c:791831
int _E1098_3()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_scale_8, "Scale");
  return atexit(_E1099_10);
}

//----- (00704860) --------------------------------------------------------  // acclient.c:791838
int _E1101_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_96, "PSDesc");
  return atexit(_E1102_10);
}

//----- (00704880) --------------------------------------------------------  // acclient.c:791845
int _E1104_3()
{
  PStringBase<char>::PStringBase<char>(&PhysicsTimeStep_8, "PhysicsTimeStep");
  return atexit(_E1105_10);
}

//----- (007048A0) --------------------------------------------------------  // acclient.c:791852
int _E1107_3()
{
  PStringBase<char>::PStringBase<char>(&FastForwardTime_8, "FastForwardTime");
  return atexit(_E1108_10);
}

//----- (007048C0) --------------------------------------------------------  // acclient.c:791859
int _E1110_3()
{
  PStringBase<char>::PStringBase<char>(&StartFadeDistance_8, "StartFadeDistance");
  return atexit(_E1111_10);
}

//----- (007048E0) --------------------------------------------------------  // acclient.c:791866
int _E1113_3()
{
  PStringBase<char>::PStringBase<char>(&StopFadeDistance_8, "StopFadeDistance");
  return atexit(_E1114_10);
}

//----- (00704900) --------------------------------------------------------  // acclient.c:791873
int _E1116_3()
{
  PStringBase<char>::PStringBase<char>(&PhysicsDuration_8, "PhysicsDuration");
  return atexit(_E1117_10);
}

//----- (00704920) --------------------------------------------------------  // acclient.c:791880
int _E1119_3()
{
  PStringBase<char>::PStringBase<char>(&ScaleType_8, "ScaleType");
  return atexit(_E1120_10);
}

//----- (00704940) --------------------------------------------------------  // acclient.c:791887
int _E1122_3()
{
  PStringBase<char>::PStringBase<char>(&WorldSpace_8, "WorldSpace");
  return atexit(_E1123_10);
}

//----- (00704960) --------------------------------------------------------  // acclient.c:791894
int _E1125_3()
{
  PStringBase<char>::PStringBase<char>(&ForceDraw_8, "ForceDraw");
  return atexit(_E1126_10);
}

//----- (00704980) --------------------------------------------------------  // acclient.c:791901
int _E1128_3()
{
  PStringBase<char>::PStringBase<char>(&NumEmitters_8, "NumEmitters");
  return atexit(_E1129_10);
}

//----- (007049A0) --------------------------------------------------------  // acclient.c:791908
int _E1131_3()
{
  PStringBase<char>::PStringBase<char>(&Material_41, "Material");
  return atexit(_E1132_10);
}

//----- (007049C0) --------------------------------------------------------  // acclient.c:791915
int _E1134_3()
{
  PStringBase<char>::PStringBase<char>(&Version_8, "Version");
  return atexit(_E1135_10);
}

//----- (007049E0) --------------------------------------------------------  // acclient.c:791922
int _E1137_3()
{
  PStringBase<char>::PStringBase<char>(&MaxParticles_8, "MaxParticles");
  return atexit(_E1138_10);
}

//----- (00704A00) --------------------------------------------------------  // acclient.c:791929
int _E1140_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_97, "Emitter");
  return atexit(_E1141_10);
}

//----- (00704A20) --------------------------------------------------------  // acclient.c:791936
int _E1143_3()
{
  PStringBase<char>::PStringBase<char>(&Origin_18, "Origin");
  return atexit(_E1144_10);
}

//----- (00704A40) --------------------------------------------------------  // acclient.c:791943
int _E1146_3()
{
  PStringBase<char>::PStringBase<char>(&Shape_8, "Shape");
  return atexit(_E1147_10);
}

//----- (00704A60) --------------------------------------------------------  // acclient.c:791950
int _E1149_3()
{
  PStringBase<char>::PStringBase<char>(&Shape_Point_8, "Point");
  return atexit(_E1150_10);
}

//----- (00704A80) --------------------------------------------------------  // acclient.c:791957
int _E1152_3()
{
  PStringBase<char>::PStringBase<char>(&Shape_Line_8, "Line");
  return atexit(_E1153_10);
}

//----- (00704AA0) --------------------------------------------------------  // acclient.c:791964
int _E1155_3()
{
  PStringBase<char>::PStringBase<char>(&Shape_Quad_8, "Quad");
  return atexit(_E1156_10);
}

//----- (00704AC0) --------------------------------------------------------  // acclient.c:791971
int _E1158_3()
{
  PStringBase<char>::PStringBase<char>(&Shape_Disc_8, "Disc");
  return atexit(_E1159_10);
}

//----- (00704AE0) --------------------------------------------------------  // acclient.c:791978
int _E1161_3()
{
  PStringBase<char>::PStringBase<char>(&Shape_Sphere_8, "Sphere");
  return atexit(_E1162_10);
}

//----- (00704B00) --------------------------------------------------------  // acclient.c:791985
int _E1164_3()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_8, "ParticleShape");
  return atexit(_E1165_10);
}

//----- (00704B20) --------------------------------------------------------  // acclient.c:791992
int _E1167_3()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Triangle_8, "Triangle");
  return atexit(_E1168_10);
}

//----- (00704B40) --------------------------------------------------------  // acclient.c:791999
int _E1170_3()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Quad_8, "Quad");
  return atexit(_E1171_10);
}

//----- (00704B60) --------------------------------------------------------  // acclient.c:792006
int _E1173_3()
{
  PStringBase<char>::PStringBase<char>(&Streak_8, "Streak");
  return atexit(_E1174_10);
}

//----- (00704B80) --------------------------------------------------------  // acclient.c:792013
int _E1176_3()
{
  PStringBase<char>::PStringBase<char>(&Rotation_18, "Rotation");
  return atexit(_E1177_10);
}

//----- (00704BA0) --------------------------------------------------------  // acclient.c:792020
int _E1179_3()
{
  PStringBase<char>::PStringBase<char>(&WorldRotation_8, "WorldRotation");
  return atexit(_E1180_10);
}

//----- (00704BC0) --------------------------------------------------------  // acclient.c:792027
int _E1182_3()
{
  PStringBase<char>::PStringBase<char>(&RotateVelocity_8, "RotateVelocity");
  return atexit(_E1183_10);
}

//----- (00704BE0) --------------------------------------------------------  // acclient.c:792034
int _E1185_3()
{
  PStringBase<char>::PStringBase<char>(&ParticleScale_8, "ParticleScale");
  return atexit(_E1186_10);
}

//----- (00704C00) --------------------------------------------------------  // acclient.c:792041
int _E1188_3()
{
  PStringBase<char>::PStringBase<char>(&Scale_27, "Scale");
  return atexit(_E1189_10);
}

//----- (00704C20) --------------------------------------------------------  // acclient.c:792048
int _E1191_3()
{
  PStringBase<char>::PStringBase<char>(&ExplodingDir_8, "ExplodingDir");
  return atexit(_E1192_10);
}

//----- (00704C40) --------------------------------------------------------  // acclient.c:792055
int _E1194_3()
{
  PStringBase<char>::PStringBase<char>(&BirthRate_8, "BirthRate");
  return atexit(_E1195_10);
}

//----- (00704C60) --------------------------------------------------------  // acclient.c:792062
int _E1197_3()
{
  PStringBase<char>::PStringBase<char>(&Lifespan_8, "Lifespan");
  return atexit(_E1198_10);
}

//----- (00704C80) --------------------------------------------------------  // acclient.c:792069
int _E1200_3()
{
  PStringBase<char>::PStringBase<char>(&Velocity_8, "Velocity");
  return atexit(_E1201_10);
}

//----- (00704CA0) --------------------------------------------------------  // acclient.c:792076
int _E1203_3()
{
  PStringBase<char>::PStringBase<char>(&Direction_8, "Direction");
  return atexit(_E1204_10);
}

//----- (00704CC0) --------------------------------------------------------  // acclient.c:792083
int _E1206_3()
{
  PStringBase<char>::PStringBase<char>(&MinSpread_8, "MinSpread");
  return atexit(_E1207_10);
}

//----- (00704CE0) --------------------------------------------------------  // acclient.c:792090
int _E1209_3()
{
  PStringBase<char>::PStringBase<char>(&MaxSpread_8, "MaxSpread");
  return atexit(_E1210_10);
}

//----- (00704D00) --------------------------------------------------------  // acclient.c:792097
int _E1212_3()
{
  PStringBase<char>::PStringBase<char>(&EmissionLimit_8, "EmissionLimit");
  return atexit(_E1213_10);
}

//----- (00704D20) --------------------------------------------------------  // acclient.c:792104
int _E1215_3()
{
  PStringBase<char>::PStringBase<char>(&BlastCount_8, "BlastCount");
  return atexit(_E1216_10);
}

//----- (00704D40) --------------------------------------------------------  // acclient.c:792111
int _E1218_3()
{
  PStringBase<char>::PStringBase<char>(&StartTime_8, "StartTime");
  return atexit(_E1219_10);
}

//----- (00704D60) --------------------------------------------------------  // acclient.c:792118
int _E1221_3()
{
  PStringBase<char>::PStringBase<char>(&TimeLimit_8, "TimeLimit");
  return atexit(_E1222_10);
}

//----- (00704D80) --------------------------------------------------------  // acclient.c:792125
int _E1224_3()
{
  PStringBase<char>::PStringBase<char>(&EmissionDistance_8, "EmissionDistance");
  return atexit(_E1225_10);
}

//----- (00704DA0) --------------------------------------------------------  // acclient.c:792132
int _E1227_3()
{
  PStringBase<char>::PStringBase<char>(&ParticleSnap_8, "ParticleSnap");
  return atexit(_E1228_10);
}

//----- (00704DC0) --------------------------------------------------------  // acclient.c:792139
int _E1230_3()
{
  PStringBase<char>::PStringBase<char>(&InclusiveShape_8, "InclusiveShape");
  return atexit(_E1231_10);
}

//----- (00704DE0) --------------------------------------------------------  // acclient.c:792146
int _E1233_3()
{
  PStringBase<char>::PStringBase<char>(&NumKeyframes_8, "NumKeyframes");
  return atexit(_E1234_10);
}

//----- (00704E00) --------------------------------------------------------  // acclient.c:792153
int _E1236_3()
{
  PStringBase<char>::PStringBase<char>(&IsActive_8, "IsActive");
  return atexit(_E1237_10);
}

//----- (00704E20) --------------------------------------------------------  // acclient.c:792160
int _E1239_3()
{
  PStringBase<char>::PStringBase<char>(&FadeIn_8, "FadeIn");
  return atexit(_E1240_10);
}

//----- (00704E40) --------------------------------------------------------  // acclient.c:792167
int _E1242_3()
{
  PStringBase<char>::PStringBase<char>(&FadeOut_8, "FadeOut");
  return atexit(_E1243_10);
}

//----- (00704E60) --------------------------------------------------------  // acclient.c:792174
int _E1245_3()
{
  PStringBase<char>::PStringBase<char>(&ConstrainX_8, "ConstrainX");
  return atexit(_E1246_10);
}

//----- (00704E80) --------------------------------------------------------  // acclient.c:792181
int _E1248_3()
{
  PStringBase<char>::PStringBase<char>(&ConstrainY_8, "ConstrainY");
  return atexit(_E1249_10);
}

//----- (00704EA0) --------------------------------------------------------  // acclient.c:792188
int _E1251_3()
{
  PStringBase<char>::PStringBase<char>(&ConstrainZ_8, "ConstrainZ");
  return atexit(_E1252_10);
}

//----- (00704EC0) --------------------------------------------------------  // acclient.c:792195
int _E1254_3()
{
  PStringBase<char>::PStringBase<char>(&NodeName_98, "Keyframe");
  return atexit(_E1255_10);
}

//----- (00704EE0) --------------------------------------------------------  // acclient.c:792202
int _E1257_3()
{
  PStringBase<char>::PStringBase<char>(&Time_8, "Time");
  return atexit(_E1258_9);
}

//----- (00704F00) --------------------------------------------------------  // acclient.c:792209
int _E1260_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_8, "Flags");
  return atexit(_E1261_8);
}

//----- (00704F20) --------------------------------------------------------  // acclient.c:792216
int _E1263_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_None_8, "None");
  return atexit(_E1264_8);
}

//----- (00704F40) --------------------------------------------------------  // acclient.c:792223
int _E1266_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendScale_8, "BlendScale");
  return atexit(_E1267_8);
}

//----- (00704F60) --------------------------------------------------------  // acclient.c:792230
int _E1269_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendColor_8, "BlendColor");
  return atexit(_E1270_8);
}

//----- (00704F80) --------------------------------------------------------  // acclient.c:792237
int _E1272_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendMass_8, "BlendMass");
  return atexit(_E1273_8);
}

//----- (00704FA0) --------------------------------------------------------  // acclient.c:792244
int _E1275_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetScale_8, "SetScale");
  return atexit(_E1276_9);
}

//----- (00704FC0) --------------------------------------------------------  // acclient.c:792251
int _E1278_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetColor_8, "SetColor");
  return atexit(_E1279_8);
}

//----- (00704FE0) --------------------------------------------------------  // acclient.c:792258
int _E1281_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetMass_8, "SetMass");
  return atexit(_E1282_9);
}

//----- (00705000) --------------------------------------------------------  // acclient.c:792265
int _E1284_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPFlags_8, "SetParticleFlags");
  return atexit(_E1285_8);
}

//----- (00705020) --------------------------------------------------------  // acclient.c:792272
int _E1287_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPCType_8, "SetControllerType");
  return atexit(_E1288_8);
}

//----- (00705040) --------------------------------------------------------  // acclient.c:792279
int _E1290_4()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPhysFlags_8, "SetPhysicsFlags");
  return atexit(_E1291_7);
}

//----- (00705060) --------------------------------------------------------  // acclient.c:792286
int _E1293_3()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetParams_8, "SetParams");
  return atexit(_E1294_8);
}

//----- (00705080) --------------------------------------------------------  // acclient.c:792293
int _E1296_4()
{
  PStringBase<char>::PStringBase<char>(&Scale_28, "Scale");
  return atexit(_E1297_8);
}

//----- (007050A0) --------------------------------------------------------  // acclient.c:792300
int _E1299_4()
{
  PStringBase<char>::PStringBase<char>(&ScaleX_8, "ScaleX");
  return atexit(_E1300_8);
}

//----- (007050C0) --------------------------------------------------------  // acclient.c:792307
int _E1302_4()
{
  PStringBase<char>::PStringBase<char>(&ScaleY_8, "ScaleY");
  return atexit(_E1303_7);
}

//----- (007050E0) --------------------------------------------------------  // acclient.c:792314
int _E1305_4()
{
  PStringBase<char>::PStringBase<char>(&Color_8, "Color");
  return atexit(_E1306_6);
}

//----- (00705100) --------------------------------------------------------  // acclient.c:792321
int _E1308_4()
{
  PStringBase<char>::PStringBase<char>(&Mass_8, "Mass");
  return atexit(_E1309_6);
}

//----- (00705120) --------------------------------------------------------  // acclient.c:792328
int _E1311_4()
{
  PStringBase<char>::PStringBase<char>(&PFlags_8, "ParticleFlags");
  return atexit(_E1312_6);
}

//----- (00705140) --------------------------------------------------------  // acclient.c:792335
int _E1314_4()
{
  PStringBase<char>::PStringBase<char>(&PFlags_None_8, "None");
  return atexit(_E1315_4);
}

//----- (00705160) --------------------------------------------------------  // acclient.c:792342
int _E1317_4()
{
  PStringBase<char>::PStringBase<char>(&PCType_8, "ControllerType");
  return atexit(_E1318_4);
}

//----- (00705180) --------------------------------------------------------  // acclient.c:792349
int _E1320_4()
{
  PStringBase<char>::PStringBase<char>(&PCType_None_8, "None");
  return atexit(_E1321_4);
}

//----- (007051A0) --------------------------------------------------------  // acclient.c:792356
int _E1323_4()
{
  PStringBase<char>::PStringBase<char>(&PCType_Physics_8, "Physics");
  return atexit(_E1324_4);
}

//----- (007051C0) --------------------------------------------------------  // acclient.c:792363
int _E1326_4()
{
  PStringBase<char>::PStringBase<char>(&PCType_Parametric_8, "Parametric");
  return atexit(_E1327_4);
}

//----- (007051E0) --------------------------------------------------------  // acclient.c:792370
int _E1329_4()
{
  PStringBase<char>::PStringBase<char>(&PCType_AttractRepulse_8, "AttractRepulse");
  return atexit(_E1330_4);
}

//----- (00705200) --------------------------------------------------------  // acclient.c:792377
int _E1332_4()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFile_8, "PointFile");
  return atexit(_E1333_4);
}

//----- (00705220) --------------------------------------------------------  // acclient.c:792384
int _E1335_4()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFileLerp_8, "PointFileLerp");
  return atexit(_E1336_4);
}

//----- (00705240) --------------------------------------------------------  // acclient.c:792391
int _E1338_4()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_8, "PhysicsFlags");
  return atexit(_E1339_4);
}

//----- (00705260) --------------------------------------------------------  // acclient.c:792398
int _E1341_4()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_None_8, "None");
  return atexit(_E1342_4);
}

//----- (00705280) --------------------------------------------------------  // acclient.c:792405
int _E1344_4()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Gravity_8, "Gravity");
  return atexit(_E1345_4);
}

//----- (007052A0) --------------------------------------------------------  // acclient.c:792412
int _E1347_4()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Wind_8, "Wind");
  return atexit(_E1348_4);
}

//----- (007052C0) --------------------------------------------------------  // acclient.c:792419
int _E1350_4()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Momentum_8, "Momentum");
  return atexit(_E1351_4);
}

//----- (007052E0) --------------------------------------------------------  // acclient.c:792426
int _E1353_4()
{
  PStringBase<char>::PStringBase<char>(&PointfileFlags_RandomPoint_8, "RandomPoint");
  return atexit(_E1354_4);
}

//----- (00705300) --------------------------------------------------------  // acclient.c:792433
int _E1356_4()
{
  PStringBase<char>::PStringBase<char>(&Position_9, "Position");
  return atexit(_E1357_4);
}

//----- (00705320) --------------------------------------------------------  // acclient.c:792440
int _E1359_4()
{
  PStringBase<char>::PStringBase<char>(&PointList_8, "PointList");
  return atexit(_E1360_4);
}

//----- (00705340) --------------------------------------------------------  // acclient.c:792447
int _E1362_4()
{
  PStringBase<char>::PStringBase<char>(&Point_18, "pt");
  return atexit(_E1363_4);
}

//----- (00705360) --------------------------------------------------------  // acclient.c:792454
int _E1365_4()
{
  PStringBase<char>::PStringBase<char>(&DetailLevels_8, "DetailLevels");
  return atexit(_E1366_4);
}

//----- (00705380) --------------------------------------------------------  // acclient.c:792461
int _E1368_4()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Low_8, "Low");
  return atexit(_E1369_4);
}

//----- (007053A0) --------------------------------------------------------  // acclient.c:792468
int _E1371_4()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Medium_8, "Medium");
  return atexit(_E1372_4);
}

//----- (007053C0) --------------------------------------------------------  // acclient.c:792475
int _E1374_4()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_High_8, "High");
  return atexit(_E1375_4);
}

//----- (007053E0) --------------------------------------------------------  // acclient.c:792482
int _E1377_4()
{
  PStringBase<char>::PStringBase<char>(&FadeSpeed_8, "FadeSpeed");
  return atexit(_E1378_4);
}

//----- (00705400) --------------------------------------------------------  // acclient.c:792489
int _E1380_3()
{
  PStringBase<char>::PStringBase<char>(&MaxOpacity_8, "MaxOpacity");
  return atexit(_E1381_3);
}

//----- (00705420) --------------------------------------------------------  // acclient.c:792496
int _E1383_3()
{
  PStringBase<char>::PStringBase<char>(&Point_19, "Point");
  return atexit(_E1384_3);
}

//----- (00705440) --------------------------------------------------------  // acclient.c:792503
int _E1386_2()
{
  PStringBase<char>::PStringBase<char>(&PointAxisPos_8, "AxisPos");
  return atexit(_E1387_2);
}

//----- (00705460) --------------------------------------------------------  // acclient.c:792510
int _E1389_1()
{
  PStringBase<char>::PStringBase<char>(&PointTexture_8, "Texture");
  return atexit(_E1390_1);
}

//----- (00705480) --------------------------------------------------------  // acclient.c:792517
int _E1392_1()
{
  PStringBase<char>::PStringBase<char>(&PointSize_8, "Size");
  return atexit(_E1393_1);
}

//----- (007054A0) --------------------------------------------------------  // acclient.c:792524
int _E1395_1()
{
  PStringBase<char>::PStringBase<char>(&UseOcclusion_8, "UseOcclusion");
  return atexit(_E1396_1);
}

//----- (007054C0) --------------------------------------------------------  // acclient.c:792531
int _E1398_1()
{
  PStringBase<char>::PStringBase<char>(PHEADER_STRINGS_6, "COMPATABILITY_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_845EE8, "TOOL_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_845EEC, "SOURCE_FILE_NAME");
  PStringBase<char>::PStringBase<char>(&stru_845EF0, "PREPROC_OPTIONS");
  return atexit(_E1399_1);
}

//----- (00705510) --------------------------------------------------------  // acclient.c:792541
int _E1401_1()
{
  IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>(
    &stru_81E984,
    0x17u);
  return atexit(_E1402_1);
}

//----- (00705530) --------------------------------------------------------  // acclient.c:792550
int _E1404_1()
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>(
    &ImgTex::texture_table.m_intrusiveTable,
    0x80u);
  ImgTex::texture_table.vfptr = (HashTable<unsigned __int64,ImgTex *,1>Vtbl *)AutoGrowHashTable<unsigned __int64,ImgTex *>::vftable;
  return atexit(_E1405_1);
}
// 7C9DBC: using guessed type int (__thiscall *AutoGrowHashTable<unsigned __int64,ImgTex *>::vftable[2])(void *, char);

//----- (00705560) --------------------------------------------------------  // acclient.c:792561
int _E1407_1()
{
  IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>(
    (IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1> *)&stru_81EA74,
    0x80u);
  return atexit(_E1408_1);
}

//----- (00705580) --------------------------------------------------------  // acclient.c:792570
int sub_705580()
{
  return atexit(nullsub_1198);
}

//----- (0076BE60) --------------------------------------------------------  // acclient.c:899226
void __cdecl _E202_47()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BE90) --------------------------------------------------------  // acclient.c:899239
void __cdecl _E205_42()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BEC0) --------------------------------------------------------  // acclient.c:899252
void __cdecl _E208_46()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BEF0) --------------------------------------------------------  // acclient.c:899265
void __cdecl _E211_42()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BF20) --------------------------------------------------------  // acclient.c:899278
void __cdecl _E214_44()
{
  char *v0; // esi@1

  v0 = &PHeader_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BF50) --------------------------------------------------------  // acclient.c:899291
void __cdecl _E217_40()
{
  char *v0; // esi@1

  v0 = &VertexArray_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexArray_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BF80) --------------------------------------------------------  // acclient.c:899304
void __cdecl _E220_39()
{
  char *v0; // esi@1

  v0 = &BinaryVertexArray_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryVertexArray_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BFB0) --------------------------------------------------------  // acclient.c:899317
void __cdecl _E223_39()
{
  char *v0; // esi@1

  v0 = &VertexType_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexType_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BFE0) --------------------------------------------------------  // acclient.c:899330
void __cdecl _E226_25()
{
  char *v0; // esi@1

  v0 = &VertexData_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexData_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C010) --------------------------------------------------------  // acclient.c:899343
void __cdecl _E229_25()
{
  char *v0; // esi@1

  v0 = &Vertex_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertex_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C040) --------------------------------------------------------  // acclient.c:899356
void __cdecl _E232_24()
{
  char *v0; // esi@1

  v0 = &Index_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C070) --------------------------------------------------------  // acclient.c:899369
void __cdecl _E235_24()
{
  char *v0; // esi@1

  v0 = &Origin_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C0A0) --------------------------------------------------------  // acclient.c:899382
void __cdecl _E238_22()
{
  char *v0; // esi@1

  v0 = &Normal_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Normal_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C0D0) --------------------------------------------------------  // acclient.c:899395
void __cdecl _E241_22()
{
  char *v0; // esi@1

  v0 = &Diffuse_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C100) --------------------------------------------------------  // acclient.c:899408
void __cdecl _E244_22()
{
  char *v0; // esi@1

  v0 = &Specular_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C130) --------------------------------------------------------  // acclient.c:899421
void __cdecl _E247_21()
{
  char *v0; // esi@1

  v0 = &UVS_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVS_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C160) --------------------------------------------------------  // acclient.c:899434
void __cdecl _E250_22()
{
  char *v0; // esi@1

  v0 = &VectorS_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorS_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C190) --------------------------------------------------------  // acclient.c:899447
void __cdecl _E253_19()
{
  char *v0; // esi@1

  v0 = &VectorT_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorT_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C1C0) --------------------------------------------------------  // acclient.c:899460
void __cdecl _E256_19()
{
  char *v0; // esi@1

  v0 = &VectorSxT_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorSxT_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C1F0) --------------------------------------------------------  // acclient.c:899473
void __cdecl _E259_20()
{
  char *v0; // esi@1

  v0 = &Weights_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weights_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C220) --------------------------------------------------------  // acclient.c:899486
void __cdecl _E262_20()
{
  char *v0; // esi@1

  v0 = &Importance_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Importance_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C250) --------------------------------------------------------  // acclient.c:899499
void __cdecl _E265_20()
{
  char *v0; // esi@1

  v0 = &PhysMtl_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMtl_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C280) --------------------------------------------------------  // acclient.c:899512
void __cdecl _E268_19()
{
  char *v0; // esi@1

  v0 = &Material_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C2B0) --------------------------------------------------------  // acclient.c:899525
void __cdecl _E271_18()
{
  char *v0; // esi@1

  v0 = &ID_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C2E0) --------------------------------------------------------  // acclient.c:899538
void __cdecl _E274_18()
{
  char *v0; // esi@1

  v0 = &FileName_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C310) --------------------------------------------------------  // acclient.c:899551
void __cdecl _E277_18()
{
  char *v0; // esi@1

  v0 = &Polygon_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C340) --------------------------------------------------------  // acclient.c:899564
void __cdecl _E280_17()
{
  char *v0; // esi@1

  v0 = &ID_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C370) --------------------------------------------------------  // acclient.c:899577
void __cdecl _E283_17()
{
  char *v0; // esi@1

  v0 = &Indices_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C3A0) --------------------------------------------------------  // acclient.c:899590
void __cdecl _E286_16()
{
  char *v0; // esi@1

  v0 = &MaterialID_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialID_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C3D0) --------------------------------------------------------  // acclient.c:899603
void __cdecl _E289_15()
{
  char *v0; // esi@1

  v0 = &PhysMaterialID_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMaterialID_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C400) --------------------------------------------------------  // acclient.c:899616
void __cdecl _E292_16()
{
  char *v0; // esi@1

  v0 = &Markings_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Markings_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C430) --------------------------------------------------------  // acclient.c:899629
void __cdecl _E295_15()
{
  char *v0; // esi@1

  v0 = &Material_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C460) --------------------------------------------------------  // acclient.c:899642
void __cdecl _E298_16()
{
  char *v0; // esi@1

  v0 = &Index_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C490) --------------------------------------------------------  // acclient.c:899655
void __cdecl _E301_14()
{
  char *v0; // esi@1

  v0 = &Filename_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Filename_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C4C0) --------------------------------------------------------  // acclient.c:899668
void __cdecl _E304_15()
{
  char *v0; // esi@1

  v0 = &Surface_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Surface_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C4F0) --------------------------------------------------------  // acclient.c:899681
void __cdecl _E307_14()
{
  char *v0; // esi@1

  v0 = &CellPoly_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPoly_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C520) --------------------------------------------------------  // acclient.c:899694
void __cdecl _E310_15()
{
  char *v0; // esi@1

  v0 = &Sphere_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C550) --------------------------------------------------------  // acclient.c:899707
void __cdecl _E313_14()
{
  char *v0; // esi@1

  v0 = &Side_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Side_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C580) --------------------------------------------------------  // acclient.c:899720
void __cdecl _E316_15()
{
  char *v0; // esi@1

  v0 = &Positive_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Positive_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C5B0) --------------------------------------------------------  // acclient.c:899733
void __cdecl _E319_14()
{
  char *v0; // esi@1

  v0 = &Negative_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Negative_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C5E0) --------------------------------------------------------  // acclient.c:899746
void __cdecl _E322_14()
{
  char *v0; // esi@1

  v0 = &Polygon_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C610) --------------------------------------------------------  // acclient.c:899759
void __cdecl _E325_13()
{
  char *v0; // esi@1

  v0 = &OtherCell_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C640) --------------------------------------------------------  // acclient.c:899772
void __cdecl _E328_14()
{
  char *v0; // esi@1

  v0 = &CellPortal_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPortal_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C670) --------------------------------------------------------  // acclient.c:899785
void __cdecl _E331_13()
{
  char *v0; // esi@1

  v0 = &Portal_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C6A0) --------------------------------------------------------  // acclient.c:899798
void __cdecl _E334_13()
{
  char *v0; // esi@1

  v0 = &OtherCell_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C6D0) --------------------------------------------------------  // acclient.c:899811
void __cdecl _E337_13()
{
  char *v0; // esi@1

  v0 = &OtherPortal_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherPortal_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C700) --------------------------------------------------------  // acclient.c:899824
void __cdecl _E340_13()
{
  char *v0; // esi@1

  v0 = &ExactMatch_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExactMatch_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C730) --------------------------------------------------------  // acclient.c:899837
void __cdecl _E343_10()
{
  char *v0; // esi@1

  v0 = &StabList_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StabList_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C760) --------------------------------------------------------  // acclient.c:899850
void __cdecl _E346_10()
{
  char *v0; // esi@1

  v0 = &Period_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Period_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C790) --------------------------------------------------------  // acclient.c:899863
void __cdecl _E349_10()
{
  char *v0; // esi@1

  v0 = &GrannyAnimation_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&GrannyAnimation_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C7C0) --------------------------------------------------------  // acclient.c:899876
void __cdecl _E352_10()
{
  char *v0; // esi@1

  v0 = &Transform_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Transform_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C7F0) --------------------------------------------------------  // acclient.c:899889
void __cdecl _E355_10()
{
  char *v0; // esi@1

  v0 = &Scale_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C820) --------------------------------------------------------  // acclient.c:899902
void __cdecl _E358_10()
{
  char *v0; // esi@1

  v0 = &Weight_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weight_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C850) --------------------------------------------------------  // acclient.c:899915
void __cdecl _E361_10()
{
  char *v0; // esi@1

  v0 = &Offset_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Offset_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C880) --------------------------------------------------------  // acclient.c:899928
void __cdecl _E364_10()
{
  char *v0; // esi@1

  v0 = &Quaternion_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Quaternion_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C8B0) --------------------------------------------------------  // acclient.c:899941
void __cdecl _E367_10()
{
  char *v0; // esi@1

  v0 = &Rotation_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C8E0) --------------------------------------------------------  // acclient.c:899954
void __cdecl _E370_10()
{
  char *v0; // esi@1

  v0 = &STime_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&STime_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C910) --------------------------------------------------------  // acclient.c:899967
void __cdecl _E373_10()
{
  char *v0; // esi@1

  v0 = &PhysicsSplines_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsSplines_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C940) --------------------------------------------------------  // acclient.c:899980
void __cdecl _E376_10()
{
  char *v0; // esi@1

  v0 = &BoneOpacities_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BoneOpacities_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C970) --------------------------------------------------------  // acclient.c:899993
void __cdecl _E379_10()
{
  char *v0; // esi@1

  v0 = &LowPt_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LowPt_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C9A0) --------------------------------------------------------  // acclient.c:900006
void __cdecl _E382_10()
{
  char *v0; // esi@1

  v0 = &Radius_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Radius_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076C9D0) --------------------------------------------------------  // acclient.c:900019
void __cdecl _E385_10()
{
  char *v0; // esi@1

  v0 = &Height_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Height_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CA00) --------------------------------------------------------  // acclient.c:900032
void __cdecl _E388_10()
{
  char *v0; // esi@1

  v0 = &Texture2D_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture2D_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CA30) --------------------------------------------------------  // acclient.c:900045
void __cdecl _E391_10()
{
  char *v0; // esi@1

  v0 = &Texture3D_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture3D_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CA60) --------------------------------------------------------  // acclient.c:900058
void __cdecl _E394_10()
{
  char *v0; // esi@1

  v0 = &TextureCube_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureCube_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CA90) --------------------------------------------------------  // acclient.c:900071
void __cdecl _E397_10()
{
  char *v0; // esi@1

  v0 = &TextureMovie2D_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureMovie2D_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CAC0) --------------------------------------------------------  // acclient.c:900084
void __cdecl _E400_10()
{
  char *v0; // esi@1

  v0 = &MovieFileName_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFileName_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CAF0) --------------------------------------------------------  // acclient.c:900097
void __cdecl _E403_10()
{
  char *v0; // esi@1

  v0 = &MovieFramesPerSecond_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFramesPerSecond_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CB20) --------------------------------------------------------  // acclient.c:900110
void __cdecl _E406_10()
{
  char *v0; // esi@1

  v0 = &Levels_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Levels_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CB50) --------------------------------------------------------  // acclient.c:900123
void __cdecl _E409_10()
{
  char *v0; // esi@1

  v0 = &NodeName_89.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_89.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CB80) --------------------------------------------------------  // acclient.c:900136
void __cdecl _E412_10()
{
  char *v0; // esi@1

  v0 = &Material_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CBB0) --------------------------------------------------------  // acclient.c:900149
void __cdecl _E415_10()
{
  char *v0; // esi@1

  v0 = &MaterialType_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialType_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CBE0) --------------------------------------------------------  // acclient.c:900162
void __cdecl _E418_10()
{
  char *v0; // esi@1

  v0 = &Modifier_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Modifier_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CC10) --------------------------------------------------------  // acclient.c:900175
void __cdecl _E421_10()
{
  char *v0; // esi@1

  v0 = &AllowStencilShadows_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AllowStencilShadows_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CC40) --------------------------------------------------------  // acclient.c:900188
void __cdecl _E424_10()
{
  char *v0; // esi@1

  v0 = &DiscardGeometry_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DiscardGeometry_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CC70) --------------------------------------------------------  // acclient.c:900201
void __cdecl _E427_10()
{
  char *v0; // esi@1

  v0 = &NodeName_90.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_90.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CCA0) --------------------------------------------------------  // acclient.c:900214
void __cdecl _E430_10()
{
  char *v0; // esi@1

  v0 = &SortMode_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CCD0) --------------------------------------------------------  // acclient.c:900227
void __cdecl _E433_10()
{
  char *v0; // esi@1

  v0 = &SortMode_None_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_None_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CD00) --------------------------------------------------------  // acclient.c:900240
void __cdecl _E436_10()
{
  char *v0; // esi@1

  v0 = &SortMode_Triangle_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_Triangle_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CD30) --------------------------------------------------------  // acclient.c:900253
void __cdecl _E439_10()
{
  char *v0; // esi@1

  v0 = &NodeName_91.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_91.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CD60) --------------------------------------------------------  // acclient.c:900266
void __cdecl _E442_10()
{
  char *v0; // esi@1

  v0 = &NodeName_92.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_92.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CD90) --------------------------------------------------------  // acclient.c:900279
void __cdecl _E445_10()
{
  char *v0; // esi@1

  v0 = &DataType_DATA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_DATA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CDC0) --------------------------------------------------------  // acclient.c:900292
void __cdecl _E448_10()
{
  char *v0; // esi@1

  v0 = &DataType_WAVEFORM_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_WAVEFORM_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CDF0) --------------------------------------------------------  // acclient.c:900305
void __cdecl _E451_10()
{
  char *v0; // esi@1

  v0 = &DataType_COLOR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_COLOR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CE20) --------------------------------------------------------  // acclient.c:900318
void __cdecl _E454_10()
{
  char *v0; // esi@1

  v0 = &DataType_TEXTURE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_TEXTURE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CE50) --------------------------------------------------------  // acclient.c:900331
void __cdecl _E457_10()
{
  char *v0; // esi@1

  v0 = &DataType_BOOL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_BOOL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CE80) --------------------------------------------------------  // acclient.c:900344
void __cdecl _E460_10()
{
  char *v0; // esi@1

  v0 = &NodeName_93.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_93.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CEB0) --------------------------------------------------------  // acclient.c:900357
void __cdecl _E463_10()
{
  char *v0; // esi@1

  v0 = &modType_UVTranslate_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTranslate_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CEE0) --------------------------------------------------------  // acclient.c:900370
void __cdecl _E466_10()
{
  char *v0; // esi@1

  v0 = &modType_UVRotate_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVRotate_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CF10) --------------------------------------------------------  // acclient.c:900383
void __cdecl _E469_10()
{
  char *v0; // esi@1

  v0 = &modType_UVScale_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVScale_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CF40) --------------------------------------------------------  // acclient.c:900396
void __cdecl _E472_10()
{
  char *v0; // esi@1

  v0 = &modType_UVTransform_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTransform_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CF70) --------------------------------------------------------  // acclient.c:900409
void __cdecl _E475_10()
{
  char *v0; // esi@1

  v0 = &TrueFlags_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TrueFlags_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CFA0) --------------------------------------------------------  // acclient.c:900422
void __cdecl _E478_10()
{
  char *v0; // esi@1

  v0 = &FalseFlags_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FalseFlags_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076CFD0) --------------------------------------------------------  // acclient.c:900435
void __cdecl _E481_10()
{
  char *v0; // esi@1

  v0 = &RenderPass_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderPass_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D000) --------------------------------------------------------  // acclient.c:900448
void __cdecl _E484_10()
{
  char *v0; // esi@1

  v0 = &Blend_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Blend_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D030) --------------------------------------------------------  // acclient.c:900461
void __cdecl _E487_10()
{
  char *v0; // esi@1

  v0 = &DepthTest_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthTest_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D060) --------------------------------------------------------  // acclient.c:900474
void __cdecl _E490_10()
{
  char *v0; // esi@1

  v0 = &DepthWrite_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthWrite_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D090) --------------------------------------------------------  // acclient.c:900487
void __cdecl _E493_10()
{
  char *v0; // esi@1

  v0 = &CullMode_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CullMode_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D0C0) --------------------------------------------------------  // acclient.c:900500
void __cdecl _E496_10()
{
  char *v0; // esi@1

  v0 = &DepthFog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthFog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D0F0) --------------------------------------------------------  // acclient.c:900513
void __cdecl _E499_10()
{
  char *v0; // esi@1

  v0 = &AlphaTestMode_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestMode_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D120) --------------------------------------------------------  // acclient.c:900526
void __cdecl _E502_10()
{
  char *v0; // esi@1

  v0 = &AlphaTestRef_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestRef_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D150) --------------------------------------------------------  // acclient.c:900539
void __cdecl _E505_10()
{
  char *v0; // esi@1

  v0 = &FFUseLighting_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseLighting_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D180) --------------------------------------------------------  // acclient.c:900552
void __cdecl _E508_10()
{
  char *v0; // esi@1

  v0 = &FFUseDyeColorInTFactor_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDyeColorInTFactor_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D1B0) --------------------------------------------------------  // acclient.c:900565
void __cdecl _E511_10()
{
  char *v0; // esi@1

  v0 = &FFUseSpecularLighting_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseSpecularLighting_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D1E0) --------------------------------------------------------  // acclient.c:900578
void __cdecl _E514_10()
{
  char *v0; // esi@1

  v0 = &FFUseDistanceFog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDistanceFog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D210) --------------------------------------------------------  // acclient.c:900591
void __cdecl _E517_10()
{
  char *v0; // esi@1

  v0 = &FFUseVertexDiffuse_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexDiffuse_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D240) --------------------------------------------------------  // acclient.c:900604
void __cdecl _E520_10()
{
  char *v0; // esi@1

  v0 = &FFUseVertexSpecular_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexSpecular_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D270) --------------------------------------------------------  // acclient.c:900617
void __cdecl _E523_10()
{
  char *v0; // esi@1

  v0 = &ShaderSupportsDynamicLights_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ShaderSupportsDynamicLights_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D2A0) --------------------------------------------------------  // acclient.c:900630
void __cdecl _E526_10()
{
  char *v0; // esi@1

  v0 = &UsesTransparency_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UsesTransparency_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D2D0) --------------------------------------------------------  // acclient.c:900643
void __cdecl _E529_10()
{
  char *v0; // esi@1

  v0 = &Ambient_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Ambient_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D300) --------------------------------------------------------  // acclient.c:900656
void __cdecl _E532_10()
{
  char *v0; // esi@1

  v0 = &Diffuse_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D330) --------------------------------------------------------  // acclient.c:900669
void __cdecl _E535_10()
{
  char *v0; // esi@1

  v0 = &Specular_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D360) --------------------------------------------------------  // acclient.c:900682
void __cdecl _E538_10()
{
  char *v0; // esi@1

  v0 = &SpecularPower_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecularPower_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D390) --------------------------------------------------------  // acclient.c:900695
void __cdecl _E541_10()
{
  char *v0; // esi@1

  v0 = &Dye_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Dye_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D3C0) --------------------------------------------------------  // acclient.c:900708
void __cdecl _E544_10()
{
  char *v0; // esi@1

  v0 = &Emissive_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Emissive_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D3F0) --------------------------------------------------------  // acclient.c:900721
void __cdecl _E547_10()
{
  char *v0; // esi@1

  v0 = &VertexFormat_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexFormat_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D420) --------------------------------------------------------  // acclient.c:900734
void __cdecl _E550_10()
{
  char *v0; // esi@1

  v0 = &VertexShader_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexShader_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D450) --------------------------------------------------------  // acclient.c:900747
void __cdecl _E553_10()
{
  char *v0; // esi@1

  v0 = &PixelShader_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PixelShader_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D480) --------------------------------------------------------  // acclient.c:900760
void __cdecl _E556_10()
{
  char *v0; // esi@1

  v0 = &param_MLF_NONE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_NONE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D4B0) --------------------------------------------------------  // acclient.c:900773
void __cdecl _E559_10()
{
  char *v0; // esi@1

  v0 = &param_MLF_REFLECTIONS_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_REFLECTIONS_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D4E0) --------------------------------------------------------  // acclient.c:900786
void __cdecl _E562_10()
{
  char *v0; // esi@1

  v0 = &param_MLF_VIDEOPOST_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_VIDEOPOST_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D510) --------------------------------------------------------  // acclient.c:900799
void __cdecl _E565_10()
{
  char *v0; // esi@1

  v0 = &param_MLF_HIGHDETAIL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_HIGHDETAIL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D540) --------------------------------------------------------  // acclient.c:900812
void __cdecl _E568_10()
{
  char *v0; // esi@1

  v0 = &param_MLF_SPECULAR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_SPECULAR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D570) --------------------------------------------------------  // acclient.c:900825
void __cdecl _E571_10()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS1_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS1_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D5A0) --------------------------------------------------------  // acclient.c:900838
void __cdecl _E574_10()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS2_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS2_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D5D0) --------------------------------------------------------  // acclient.c:900851
void __cdecl _E577_10()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS3_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS3_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D600) --------------------------------------------------------  // acclient.c:900864
void __cdecl _E580_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_Default_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_Default_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D630) --------------------------------------------------------  // acclient.c:900877
void __cdecl _E583_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DirectionalLightDiffuseAndSpecular_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DirectionalLightDiffuseAndSpecular_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D660) --------------------------------------------------------  // acclient.c:900890
void __cdecl _E586_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecular_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecular_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D690) --------------------------------------------------------  // acclient.c:900903
void __cdecl _E589_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecularProjector_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecularProjector_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D6C0) --------------------------------------------------------  // acclient.c:900916
void __cdecl _E592_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D6F0) --------------------------------------------------------  // acclient.c:900929
void __cdecl _E595_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D720) --------------------------------------------------------  // acclient.c:900942
void __cdecl _E598_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DistanceFog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DistanceFog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D750) --------------------------------------------------------  // acclient.c:900955
void __cdecl _E601_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_FixedFunctionGlow_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_FixedFunctionGlow_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D780) --------------------------------------------------------  // acclient.c:900968
void __cdecl _E604_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_ShaderGlow_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_ShaderGlow_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D7B0) --------------------------------------------------------  // acclient.c:900981
void __cdecl _E607_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_LandscapeShadowMap_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_LandscapeShadowMap_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D7E0) --------------------------------------------------------  // acclient.c:900994
void __cdecl _E610_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AlphaBlend_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AlphaBlend_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D810) --------------------------------------------------------  // acclient.c:901007
void __cdecl _E613_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D840) --------------------------------------------------------  // acclient.c:901020
void __cdecl _E616_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D870) --------------------------------------------------------  // acclient.c:901033
void __cdecl _E619_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D8A0) --------------------------------------------------------  // acclient.c:901046
void __cdecl _E622_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D8D0) --------------------------------------------------------  // acclient.c:901059
void __cdecl _E625_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D900) --------------------------------------------------------  // acclient.c:901072
void __cdecl _E628_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D930) --------------------------------------------------------  // acclient.c:901085
void __cdecl _E631_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D960) --------------------------------------------------------  // acclient.c:901098
void __cdecl _E634_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D990) --------------------------------------------------------  // acclient.c:901111
void __cdecl _E637_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D9C0) --------------------------------------------------------  // acclient.c:901124
void __cdecl _E640_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076D9F0) --------------------------------------------------------  // acclient.c:901137
void __cdecl _E643_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DA20) --------------------------------------------------------  // acclient.c:901150
void __cdecl _E646_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DA50) --------------------------------------------------------  // acclient.c:901163
void __cdecl _E649_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DA80) --------------------------------------------------------  // acclient.c:901176
void __cdecl _E652_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DAB0) --------------------------------------------------------  // acclient.c:901189
void __cdecl _E655_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DAE0) --------------------------------------------------------  // acclient.c:901202
void __cdecl _E658_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DB10) --------------------------------------------------------  // acclient.c:901215
void __cdecl _E661_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DB40) --------------------------------------------------------  // acclient.c:901228
void __cdecl _E664_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DB70) --------------------------------------------------------  // acclient.c:901241
void __cdecl _E667_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DBA0) --------------------------------------------------------  // acclient.c:901254
void __cdecl _E670_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DBD0) --------------------------------------------------------  // acclient.c:901267
void __cdecl _E673_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DC00) --------------------------------------------------------  // acclient.c:901280
void __cdecl _E676_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DC30) --------------------------------------------------------  // acclient.c:901293
void __cdecl _E679_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DC60) --------------------------------------------------------  // acclient.c:901306
void __cdecl _E682_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DC90) --------------------------------------------------------  // acclient.c:901319
void __cdecl _E685_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DCC0) --------------------------------------------------------  // acclient.c:901332
void __cdecl _E688_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DCF0) --------------------------------------------------------  // acclient.c:901345
void __cdecl _E691_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DD20) --------------------------------------------------------  // acclient.c:901358
void __cdecl _E694_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DD50) --------------------------------------------------------  // acclient.c:901371
void __cdecl _E697_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DD80) --------------------------------------------------------  // acclient.c:901384
void __cdecl _E700_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DDB0) --------------------------------------------------------  // acclient.c:901397
void __cdecl _E703_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DDE0) --------------------------------------------------------  // acclient.c:901410
void __cdecl _E706_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DE10) --------------------------------------------------------  // acclient.c:901423
void __cdecl _E709_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DE40) --------------------------------------------------------  // acclient.c:901436
void __cdecl _E712_10()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_Fog_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_Fog_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DE70) --------------------------------------------------------  // acclient.c:901449
void __cdecl _E715_10()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ZERO_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ZERO_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DEA0) --------------------------------------------------------  // acclient.c:901462
void __cdecl _E718_10()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ONE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ONE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DED0) --------------------------------------------------------  // acclient.c:901475
void __cdecl _E721_10()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCCOLOR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCCOLOR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DF00) --------------------------------------------------------  // acclient.c:901488
void __cdecl _E724_10()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCCOLOR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCCOLOR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DF30) --------------------------------------------------------  // acclient.c:901501
void __cdecl _E727_10()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DF60) --------------------------------------------------------  // acclient.c:901514
void __cdecl _E730_10()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCALPHA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCALPHA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DF90) --------------------------------------------------------  // acclient.c:901527
void __cdecl _E733_10()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTALPHA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTALPHA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DFC0) --------------------------------------------------------  // acclient.c:901540
void __cdecl _E736_10()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTALPHA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTALPHA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076DFF0) --------------------------------------------------------  // acclient.c:901553
void __cdecl _E739_10()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTCOLOR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTCOLOR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E020) --------------------------------------------------------  // acclient.c:901566
void __cdecl _E742_10()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTCOLOR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTCOLOR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E050) --------------------------------------------------------  // acclient.c:901579
void __cdecl _E745_10()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHASAT_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHASAT_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E080) --------------------------------------------------------  // acclient.c:901592
void __cdecl _E748_10()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESS_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESS_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E0B0) --------------------------------------------------------  // acclient.c:901605
void __cdecl _E751_10()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_EQUAL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_EQUAL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E0E0) --------------------------------------------------------  // acclient.c:901618
void __cdecl _E754_10()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESSEQUAL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESSEQUAL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E110) --------------------------------------------------------  // acclient.c:901631
void __cdecl _E757_10()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATER_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATER_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E140) --------------------------------------------------------  // acclient.c:901644
void __cdecl _E760_10()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_NOTEQUAL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_NOTEQUAL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E170) --------------------------------------------------------  // acclient.c:901657
void __cdecl _E763_10()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATEREQUAL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATEREQUAL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E1A0) --------------------------------------------------------  // acclient.c:901670
void __cdecl _E766_10()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_ALWAYS_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_ALWAYS_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E1D0) --------------------------------------------------------  // acclient.c:901683
void __cdecl _E769_10()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_ON_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_ON_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E200) --------------------------------------------------------  // acclient.c:901696
void __cdecl _E772_10()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_OFF_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_OFF_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E230) --------------------------------------------------------  // acclient.c:901709
void __cdecl _E775_10()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERDIFFUSE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERDIFFUSE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E260) --------------------------------------------------------  // acclient.c:901722
void __cdecl _E778_10()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERSPECULAR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERSPECULAR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E290) --------------------------------------------------------  // acclient.c:901735
void __cdecl _E781_10()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXDIFFUSE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXDIFFUSE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E2C0) --------------------------------------------------------  // acclient.c:901748
void __cdecl _E784_10()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXSPECULAR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXSPECULAR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E2F0) --------------------------------------------------------  // acclient.c:901761
void __cdecl _E787_10()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_NONE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_NONE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E320) --------------------------------------------------------  // acclient.c:901774
void __cdecl _E790_10()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CW_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CW_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E350) --------------------------------------------------------  // acclient.c:901787
void __cdecl _E793_10()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CCW_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CCW_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E380) --------------------------------------------------------  // acclient.c:901800
void __cdecl _E796_10()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_NONE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_NONE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E3B0) --------------------------------------------------------  // acclient.c:901813
void __cdecl _E799_10()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SIMPLE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SIMPLE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E3E0) --------------------------------------------------------  // acclient.c:901826
void __cdecl _E802_10()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_DIFFUSE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_DIFFUSE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E410) --------------------------------------------------------  // acclient.c:901839
void __cdecl _E805_10()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SPECULAR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SPECULAR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E440) --------------------------------------------------------  // acclient.c:901852
void __cdecl _E808_10()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_OFF_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_OFF_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E470) --------------------------------------------------------  // acclient.c:901865
void __cdecl _E811_10()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_ON_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_ON_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E4A0) --------------------------------------------------------  // acclient.c:901878
void __cdecl _E814_10()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_OFF_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_OFF_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E4D0) --------------------------------------------------------  // acclient.c:901891
void __cdecl _E817_10()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_ON_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_ON_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E500) --------------------------------------------------------  // acclient.c:901904
void __cdecl _E820_10()
{
  char *v0; // esi@1

  v0 = &param_VF_ORIGIN_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_ORIGIN_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E530) --------------------------------------------------------  // acclient.c:901917
void __cdecl _E823_10()
{
  char *v0; // esi@1

  v0 = &param_VF_NORMAL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_NORMAL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E560) --------------------------------------------------------  // acclient.c:901930
void __cdecl _E826_10()
{
  char *v0; // esi@1

  v0 = &param_VF_POINTSIZE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_POINTSIZE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E590) --------------------------------------------------------  // acclient.c:901943
void __cdecl _E829_10()
{
  char *v0; // esi@1

  v0 = &param_VF_DIFFUSE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_DIFFUSE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E5C0) --------------------------------------------------------  // acclient.c:901956
void __cdecl _E832_10()
{
  char *v0; // esi@1

  v0 = &param_VF_SPECULAR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_SPECULAR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E5F0) --------------------------------------------------------  // acclient.c:901969
void __cdecl _E835_10()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx1_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx1_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E620) --------------------------------------------------------  // acclient.c:901982
void __cdecl _E838_10()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx2_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx2_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E650) --------------------------------------------------------  // acclient.c:901995
void __cdecl _E841_10()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx3_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx3_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E680) --------------------------------------------------------  // acclient.c:902008
void __cdecl _E844_10()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx4_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx4_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E6B0) --------------------------------------------------------  // acclient.c:902021
void __cdecl _E847_10()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx5_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx5_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E6E0) --------------------------------------------------------  // acclient.c:902034
void __cdecl _E850_10()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx6_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx6_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E710) --------------------------------------------------------  // acclient.c:902047
void __cdecl _E853_10()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx7_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx7_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E740) --------------------------------------------------------  // acclient.c:902060
void __cdecl _E856_10()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx8_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx8_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E770) --------------------------------------------------------  // acclient.c:902073
void __cdecl _E859_10()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_S_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_S_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E7A0) --------------------------------------------------------  // acclient.c:902086
void __cdecl _E862_10()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_T_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_T_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E7D0) --------------------------------------------------------  // acclient.c:902099
void __cdecl _E865_10()
{
  char *v0; // esi@1

  v0 = &NodeName_94.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_94.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E800) --------------------------------------------------------  // acclient.c:902112
void __cdecl _E868_10()
{
  char *v0; // esi@1

  v0 = &SamplerNodeName_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerNodeName_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E830) --------------------------------------------------------  // acclient.c:902125
void __cdecl _E871_10()
{
  char *v0; // esi@1

  v0 = &SamplerName_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerName_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E860) --------------------------------------------------------  // acclient.c:902138
void __cdecl _E874_10()
{
  char *v0; // esi@1

  v0 = &Texture_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E890) --------------------------------------------------------  // acclient.c:902151
void __cdecl _E877_10()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_FrameBuffer_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_FrameBuffer_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E8C0) --------------------------------------------------------  // acclient.c:902164
void __cdecl _E880_10()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Distortion_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Distortion_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E8F0) --------------------------------------------------------  // acclient.c:902177
void __cdecl _E883_10()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Reflection_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Reflection_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E920) --------------------------------------------------------  // acclient.c:902190
void __cdecl _E886_10()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_NormalizeCube_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_NormalizeCube_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E950) --------------------------------------------------------  // acclient.c:902203
void __cdecl _E889_10()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LightProjectorCube_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LightProjectorCube_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E980) --------------------------------------------------------  // acclient.c:902216
void __cdecl _E892_10()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_EnvironmentCube_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_EnvironmentCube_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E9B0) --------------------------------------------------------  // acclient.c:902229
void __cdecl _E895_10()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LandscapeShadows_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LandscapeShadows_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076E9E0) --------------------------------------------------------  // acclient.c:902242
void __cdecl _E898_10()
{
  char *v0; // esi@1

  v0 = &AddressMode_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AddressMode_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EA10) --------------------------------------------------------  // acclient.c:902255
void __cdecl _E901_10()
{
  char *v0; // esi@1

  v0 = &TexFilter_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexFilter_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EA40) --------------------------------------------------------  // acclient.c:902268
void __cdecl _E904_10()
{
  char *v0; // esi@1

  v0 = &ColorOp_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorOp_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EA70) --------------------------------------------------------  // acclient.c:902281
void __cdecl _E907_10()
{
  char *v0; // esi@1

  v0 = &ColorArg1_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg1_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EAA0) --------------------------------------------------------  // acclient.c:902294
void __cdecl _E910_10()
{
  char *v0; // esi@1

  v0 = &ColorArg2_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg2_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EAD0) --------------------------------------------------------  // acclient.c:902307
void __cdecl _E913_10()
{
  char *v0; // esi@1

  v0 = &AlphaOp_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaOp_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EB00) --------------------------------------------------------  // acclient.c:902320
void __cdecl _E916_10()
{
  char *v0; // esi@1

  v0 = &AlphaArg1_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg1_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EB30) --------------------------------------------------------  // acclient.c:902333
void __cdecl _E919_10()
{
  char *v0; // esi@1

  v0 = &AlphaArg2_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg2_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EB60) --------------------------------------------------------  // acclient.c:902346
void __cdecl _E922_10()
{
  char *v0; // esi@1

  v0 = &TexCoord_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexCoord_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EB90) --------------------------------------------------------  // acclient.c:902359
void __cdecl _E925_10()
{
  char *v0; // esi@1

  v0 = &UseProjection_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseProjection_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EBC0) --------------------------------------------------------  // acclient.c:902372
void __cdecl _E928_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG1_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG1_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EBF0) --------------------------------------------------------  // acclient.c:902385
void __cdecl _E931_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG2_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG2_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EC20) --------------------------------------------------------  // acclient.c:902398
void __cdecl _E934_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EC50) --------------------------------------------------------  // acclient.c:902411
void __cdecl _E937_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE2X_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE2X_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EC80) --------------------------------------------------------  // acclient.c:902424
void __cdecl _E940_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE4X_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE4X_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076ECB0) --------------------------------------------------------  // acclient.c:902437
void __cdecl _E943_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADD_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADD_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076ECE0) --------------------------------------------------------  // acclient.c:902450
void __cdecl _E946_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076ED10) --------------------------------------------------------  // acclient.c:902463
void __cdecl _E949_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED2X_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED2X_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076ED40) --------------------------------------------------------  // acclient.c:902476
void __cdecl _E952_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SUBTRACT_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SUBTRACT_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076ED70) --------------------------------------------------------  // acclient.c:902489
void __cdecl _E955_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSMOOTH_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSMOOTH_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EDA0) --------------------------------------------------------  // acclient.c:902502
void __cdecl _E958_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDDIFFUSEALPHA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDDIFFUSEALPHA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EDD0) --------------------------------------------------------  // acclient.c:902515
void __cdecl _E961_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EE00) --------------------------------------------------------  // acclient.c:902528
void __cdecl _E964_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDFACTORALPHA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDFACTORALPHA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EE30) --------------------------------------------------------  // acclient.c:902541
void __cdecl _E967_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHAPM_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHAPM_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EE60) --------------------------------------------------------  // acclient.c:902554
void __cdecl _E970_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDCURRENTALPHA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDCURRENTALPHA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EE90) --------------------------------------------------------  // acclient.c:902567
void __cdecl _E973_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_PREMODULATE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_PREMODULATE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EEC0) --------------------------------------------------------  // acclient.c:902580
void __cdecl _E976_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEALPHA_ADDCOLOR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEALPHA_ADDCOLOR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EEF0) --------------------------------------------------------  // acclient.c:902593
void __cdecl _E979_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATECOLOR_ADDALPHA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATECOLOR_ADDALPHA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EF20) --------------------------------------------------------  // acclient.c:902606
void __cdecl _E982_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVALPHA_ADDCOLOR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EF50) --------------------------------------------------------  // acclient.c:902619
void __cdecl _E985_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVCOLOR_ADDALPHA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EF80) --------------------------------------------------------  // acclient.c:902632
void __cdecl _E988_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAP_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAP_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EFB0) --------------------------------------------------------  // acclient.c:902645
void __cdecl _E991_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAPLUMINANCE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAPLUMINANCE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076EFE0) --------------------------------------------------------  // acclient.c:902658
void __cdecl _E994_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_DOTPRODUCT3_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_DOTPRODUCT3_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F010) --------------------------------------------------------  // acclient.c:902671
void __cdecl _E997_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MULTIPLYADD_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MULTIPLYADD_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F040) --------------------------------------------------------  // acclient.c:902684
void __cdecl _E1000_10()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_LERP_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_LERP_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F070) --------------------------------------------------------  // acclient.c:902697
void __cdecl _E1003_10()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_DIFFUSE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_DIFFUSE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F0A0) --------------------------------------------------------  // acclient.c:902710
void __cdecl _E1006_10()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_SPECULAR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_SPECULAR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F0D0) --------------------------------------------------------  // acclient.c:902723
void __cdecl _E1009_10()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_CURRENT_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_CURRENT_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F100) --------------------------------------------------------  // acclient.c:902736
void __cdecl _E1012_10()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TEXTURE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TEXTURE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F130) --------------------------------------------------------  // acclient.c:902749
void __cdecl _E1015_10()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TFACTOR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TFACTOR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F160) --------------------------------------------------------  // acclient.c:902762
void __cdecl _E1018_10()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_WRAP_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_WRAP_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F190) --------------------------------------------------------  // acclient.c:902775
void __cdecl _E1021_10()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_MIRROR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_MIRROR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F1C0) --------------------------------------------------------  // acclient.c:902788
void __cdecl _E1024_10()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_CLAMP_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_CLAMP_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F1F0) --------------------------------------------------------  // acclient.c:902801
void __cdecl _E1027_10()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_BORDER_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_BORDER_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F220) --------------------------------------------------------  // acclient.c:902814
void __cdecl _E1030_10()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_NONE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_NONE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F250) --------------------------------------------------------  // acclient.c:902827
void __cdecl _E1033_10()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_POINT_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_POINT_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F280) --------------------------------------------------------  // acclient.c:902840
void __cdecl _E1036_10()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_LINEAR_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_LINEAR_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F2B0) --------------------------------------------------------  // acclient.c:902853
void __cdecl _E1039_10()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_ANISOTROPIC_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_ANISOTROPIC_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F2E0) --------------------------------------------------------  // acclient.c:902866
void __cdecl _E1042_10()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ReflectionVector_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ReflectionVector_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F310) --------------------------------------------------------  // acclient.c:902879
void __cdecl _E1045_10()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewNormal_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewNormal_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F340) --------------------------------------------------------  // acclient.c:902892
void __cdecl _E1048_10()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewOrigin_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewOrigin_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F370) --------------------------------------------------------  // acclient.c:902905
void __cdecl _E1051_10()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_SphereMap_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_SphereMap_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F3A0) --------------------------------------------------------  // acclient.c:902918
void __cdecl _E1054_10()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapReflection_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapReflection_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F3D0) --------------------------------------------------------  // acclient.c:902931
void __cdecl _E1057_10()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapFakeLight_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapFakeLight_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F400) --------------------------------------------------------  // acclient.c:902944
void __cdecl _E1060_10()
{
  char *v0; // esi@1

  v0 = &NodeName_95.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_95.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F430) --------------------------------------------------------  // acclient.c:902957
void __cdecl _E1063_10()
{
  char *v0; // esi@1

  v0 = &ModType_Origin_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Origin_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F460) --------------------------------------------------------  // acclient.c:902970
void __cdecl _E1066_10()
{
  char *v0; // esi@1

  v0 = &ModType_Normal_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Normal_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F490) --------------------------------------------------------  // acclient.c:902983
void __cdecl _E1069_10()
{
  char *v0; // esi@1

  v0 = &ModType_Diffuse_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Diffuse_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F4C0) --------------------------------------------------------  // acclient.c:902996
void __cdecl _E1072_10()
{
  char *v0; // esi@1

  v0 = &ModType_UVTranslate_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTranslate_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F4F0) --------------------------------------------------------  // acclient.c:903009
void __cdecl _E1075_10()
{
  char *v0; // esi@1

  v0 = &ModType_UVRotate_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVRotate_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F520) --------------------------------------------------------  // acclient.c:903022
void __cdecl _E1078_10()
{
  char *v0; // esi@1

  v0 = &ModType_UVScale_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVScale_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F550) --------------------------------------------------------  // acclient.c:903035
void __cdecl _E1081_10()
{
  char *v0; // esi@1

  v0 = &ModType_UVTransform_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTransform_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F580) --------------------------------------------------------  // acclient.c:903048
void __cdecl _E1084_10()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_texCoordIndex_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_texCoordIndex_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F5B0) --------------------------------------------------------  // acclient.c:903061
void __cdecl _E1087_10()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_translate_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_translate_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F5E0) --------------------------------------------------------  // acclient.c:903074
void __cdecl _E1090_10()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_texCoordIndex_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_texCoordIndex_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F610) --------------------------------------------------------  // acclient.c:903087
void __cdecl _E1093_10()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_rotate_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_rotate_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F640) --------------------------------------------------------  // acclient.c:903100
void __cdecl _E1096_10()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_texCoordIndex_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_texCoordIndex_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F670) --------------------------------------------------------  // acclient.c:903113
void __cdecl _E1099_10()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_scale_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_scale_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F6A0) --------------------------------------------------------  // acclient.c:903126
void __cdecl _E1102_10()
{
  char *v0; // esi@1

  v0 = &NodeName_96.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_96.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F6D0) --------------------------------------------------------  // acclient.c:903139
void __cdecl _E1105_10()
{
  char *v0; // esi@1

  v0 = &PhysicsTimeStep_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsTimeStep_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F700) --------------------------------------------------------  // acclient.c:903152
void __cdecl _E1108_10()
{
  char *v0; // esi@1

  v0 = &FastForwardTime_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FastForwardTime_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F730) --------------------------------------------------------  // acclient.c:903165
void __cdecl _E1111_10()
{
  char *v0; // esi@1

  v0 = &StartFadeDistance_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartFadeDistance_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F760) --------------------------------------------------------  // acclient.c:903178
void __cdecl _E1114_10()
{
  char *v0; // esi@1

  v0 = &StopFadeDistance_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StopFadeDistance_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F790) --------------------------------------------------------  // acclient.c:903191
void __cdecl _E1117_10()
{
  char *v0; // esi@1

  v0 = &PhysicsDuration_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsDuration_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F7C0) --------------------------------------------------------  // acclient.c:903204
void __cdecl _E1120_10()
{
  char *v0; // esi@1

  v0 = &ScaleType_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleType_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F7F0) --------------------------------------------------------  // acclient.c:903217
void __cdecl _E1123_10()
{
  char *v0; // esi@1

  v0 = &WorldSpace_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldSpace_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F820) --------------------------------------------------------  // acclient.c:903230
void __cdecl _E1126_10()
{
  char *v0; // esi@1

  v0 = &ForceDraw_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ForceDraw_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F850) --------------------------------------------------------  // acclient.c:903243
void __cdecl _E1129_10()
{
  char *v0; // esi@1

  v0 = &NumEmitters_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumEmitters_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F880) --------------------------------------------------------  // acclient.c:903256
void __cdecl _E1132_10()
{
  char *v0; // esi@1

  v0 = &Material_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F8B0) --------------------------------------------------------  // acclient.c:903269
void __cdecl _E1135_10()
{
  char *v0; // esi@1

  v0 = &Version_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Version_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F8E0) --------------------------------------------------------  // acclient.c:903282
void __cdecl _E1138_10()
{
  char *v0; // esi@1

  v0 = &MaxParticles_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxParticles_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F910) --------------------------------------------------------  // acclient.c:903295
void __cdecl _E1141_10()
{
  char *v0; // esi@1

  v0 = &NodeName_97.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_97.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F940) --------------------------------------------------------  // acclient.c:903308
void __cdecl _E1144_10()
{
  char *v0; // esi@1

  v0 = &Origin_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F970) --------------------------------------------------------  // acclient.c:903321
void __cdecl _E1147_10()
{
  char *v0; // esi@1

  v0 = &Shape_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F9A0) --------------------------------------------------------  // acclient.c:903334
void __cdecl _E1150_10()
{
  char *v0; // esi@1

  v0 = &Shape_Point_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Point_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076F9D0) --------------------------------------------------------  // acclient.c:903347
void __cdecl _E1153_10()
{
  char *v0; // esi@1

  v0 = &Shape_Line_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Line_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FA00) --------------------------------------------------------  // acclient.c:903360
void __cdecl _E1156_10()
{
  char *v0; // esi@1

  v0 = &Shape_Quad_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Quad_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FA30) --------------------------------------------------------  // acclient.c:903373
void __cdecl _E1159_10()
{
  char *v0; // esi@1

  v0 = &Shape_Disc_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Disc_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FA60) --------------------------------------------------------  // acclient.c:903386
void __cdecl _E1162_10()
{
  char *v0; // esi@1

  v0 = &Shape_Sphere_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Sphere_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FA90) --------------------------------------------------------  // acclient.c:903399
void __cdecl _E1165_10()
{
  char *v0; // esi@1

  v0 = &ParticleShape_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FAC0) --------------------------------------------------------  // acclient.c:903412
void __cdecl _E1168_10()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Triangle_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Triangle_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FAF0) --------------------------------------------------------  // acclient.c:903425
void __cdecl _E1171_10()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Quad_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Quad_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FB20) --------------------------------------------------------  // acclient.c:903438
void __cdecl _E1174_10()
{
  char *v0; // esi@1

  v0 = &Streak_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Streak_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FB50) --------------------------------------------------------  // acclient.c:903451
void __cdecl _E1177_10()
{
  char *v0; // esi@1

  v0 = &Rotation_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FB80) --------------------------------------------------------  // acclient.c:903464
void __cdecl _E1180_10()
{
  char *v0; // esi@1

  v0 = &WorldRotation_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldRotation_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FBB0) --------------------------------------------------------  // acclient.c:903477
void __cdecl _E1183_10()
{
  char *v0; // esi@1

  v0 = &RotateVelocity_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RotateVelocity_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FBE0) --------------------------------------------------------  // acclient.c:903490
void __cdecl _E1186_10()
{
  char *v0; // esi@1

  v0 = &ParticleScale_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleScale_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FC10) --------------------------------------------------------  // acclient.c:903503
void __cdecl _E1189_10()
{
  char *v0; // esi@1

  v0 = &Scale_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FC40) --------------------------------------------------------  // acclient.c:903516
void __cdecl _E1192_10()
{
  char *v0; // esi@1

  v0 = &ExplodingDir_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExplodingDir_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FC70) --------------------------------------------------------  // acclient.c:903529
void __cdecl _E1195_10()
{
  char *v0; // esi@1

  v0 = &BirthRate_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BirthRate_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FCA0) --------------------------------------------------------  // acclient.c:903542
void __cdecl _E1198_10()
{
  char *v0; // esi@1

  v0 = &Lifespan_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Lifespan_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FCD0) --------------------------------------------------------  // acclient.c:903555
void __cdecl _E1201_10()
{
  char *v0; // esi@1

  v0 = &Velocity_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Velocity_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FD00) --------------------------------------------------------  // acclient.c:903568
void __cdecl _E1204_10()
{
  char *v0; // esi@1

  v0 = &Direction_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Direction_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FD30) --------------------------------------------------------  // acclient.c:903581
void __cdecl _E1207_10()
{
  char *v0; // esi@1

  v0 = &MinSpread_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MinSpread_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FD60) --------------------------------------------------------  // acclient.c:903594
void __cdecl _E1210_10()
{
  char *v0; // esi@1

  v0 = &MaxSpread_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxSpread_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FD90) --------------------------------------------------------  // acclient.c:903607
void __cdecl _E1213_10()
{
  char *v0; // esi@1

  v0 = &EmissionLimit_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionLimit_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FDC0) --------------------------------------------------------  // acclient.c:903620
void __cdecl _E1216_10()
{
  char *v0; // esi@1

  v0 = &BlastCount_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BlastCount_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FDF0) --------------------------------------------------------  // acclient.c:903633
void __cdecl _E1219_10()
{
  char *v0; // esi@1

  v0 = &StartTime_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartTime_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FE20) --------------------------------------------------------  // acclient.c:903646
void __cdecl _E1222_10()
{
  char *v0; // esi@1

  v0 = &TimeLimit_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TimeLimit_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FE50) --------------------------------------------------------  // acclient.c:903659
void __cdecl _E1225_10()
{
  char *v0; // esi@1

  v0 = &EmissionDistance_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionDistance_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FE80) --------------------------------------------------------  // acclient.c:903672
void __cdecl _E1228_10()
{
  char *v0; // esi@1

  v0 = &ParticleSnap_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleSnap_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FEB0) --------------------------------------------------------  // acclient.c:903685
void __cdecl _E1231_10()
{
  char *v0; // esi@1

  v0 = &InclusiveShape_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&InclusiveShape_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FEE0) --------------------------------------------------------  // acclient.c:903698
void __cdecl _E1234_10()
{
  char *v0; // esi@1

  v0 = &NumKeyframes_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumKeyframes_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FF10) --------------------------------------------------------  // acclient.c:903711
void __cdecl _E1237_10()
{
  char *v0; // esi@1

  v0 = &IsActive_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&IsActive_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FF40) --------------------------------------------------------  // acclient.c:903724
void __cdecl _E1240_10()
{
  char *v0; // esi@1

  v0 = &FadeIn_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeIn_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FF70) --------------------------------------------------------  // acclient.c:903737
void __cdecl _E1243_10()
{
  char *v0; // esi@1

  v0 = &FadeOut_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeOut_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FFA0) --------------------------------------------------------  // acclient.c:903750
void __cdecl _E1246_10()
{
  char *v0; // esi@1

  v0 = &ConstrainX_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainX_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076FFD0) --------------------------------------------------------  // acclient.c:903763
void __cdecl _E1249_10()
{
  char *v0; // esi@1

  v0 = &ConstrainY_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainY_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770000) --------------------------------------------------------  // acclient.c:903776
void __cdecl _E1252_10()
{
  char *v0; // esi@1

  v0 = &ConstrainZ_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainZ_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770030) --------------------------------------------------------  // acclient.c:903789
void __cdecl _E1255_10()
{
  char *v0; // esi@1

  v0 = &NodeName_98.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_98.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770060) --------------------------------------------------------  // acclient.c:903802
void __cdecl _E1258_9()
{
  char *v0; // esi@1

  v0 = &Time_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Time_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770090) --------------------------------------------------------  // acclient.c:903815
void __cdecl _E1261_8()
{
  char *v0; // esi@1

  v0 = &Flags_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007700C0) --------------------------------------------------------  // acclient.c:903828
void __cdecl _E1264_8()
{
  char *v0; // esi@1

  v0 = &Flags_None_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_None_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007700F0) --------------------------------------------------------  // acclient.c:903841
void __cdecl _E1267_8()
{
  char *v0; // esi@1

  v0 = &Flags_BlendScale_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendScale_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770120) --------------------------------------------------------  // acclient.c:903854
void __cdecl _E1270_8()
{
  char *v0; // esi@1

  v0 = &Flags_BlendColor_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendColor_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770150) --------------------------------------------------------  // acclient.c:903867
void __cdecl _E1273_8()
{
  char *v0; // esi@1

  v0 = &Flags_BlendMass_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendMass_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770180) --------------------------------------------------------  // acclient.c:903880
void __cdecl _E1276_9()
{
  char *v0; // esi@1

  v0 = &Flags_SetScale_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetScale_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007701B0) --------------------------------------------------------  // acclient.c:903893
void __cdecl _E1279_8()
{
  char *v0; // esi@1

  v0 = &Flags_SetColor_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetColor_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007701E0) --------------------------------------------------------  // acclient.c:903906
void __cdecl _E1282_9()
{
  char *v0; // esi@1

  v0 = &Flags_SetMass_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetMass_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770210) --------------------------------------------------------  // acclient.c:903919
void __cdecl _E1285_8()
{
  char *v0; // esi@1

  v0 = &Flags_SetPFlags_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPFlags_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770240) --------------------------------------------------------  // acclient.c:903932
void __cdecl _E1288_8()
{
  char *v0; // esi@1

  v0 = &Flags_SetPCType_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPCType_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770270) --------------------------------------------------------  // acclient.c:903945
void __cdecl _E1291_7()
{
  char *v0; // esi@1

  v0 = &Flags_SetPhysFlags_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPhysFlags_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007702A0) --------------------------------------------------------  // acclient.c:903958
void __cdecl _E1294_8()
{
  char *v0; // esi@1

  v0 = &Flags_SetParams_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetParams_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007702D0) --------------------------------------------------------  // acclient.c:903971
void __cdecl _E1297_8()
{
  char *v0; // esi@1

  v0 = &Scale_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770300) --------------------------------------------------------  // acclient.c:903984
void __cdecl _E1300_8()
{
  char *v0; // esi@1

  v0 = &ScaleX_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleX_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770330) --------------------------------------------------------  // acclient.c:903997
void __cdecl _E1303_7()
{
  char *v0; // esi@1

  v0 = &ScaleY_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleY_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770360) --------------------------------------------------------  // acclient.c:904010
void __cdecl _E1306_6()
{
  char *v0; // esi@1

  v0 = &Color_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Color_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770390) --------------------------------------------------------  // acclient.c:904023
void __cdecl _E1309_6()
{
  char *v0; // esi@1

  v0 = &Mass_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mass_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007703C0) --------------------------------------------------------  // acclient.c:904036
void __cdecl _E1312_6()
{
  char *v0; // esi@1

  v0 = &PFlags_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007703F0) --------------------------------------------------------  // acclient.c:904049
void __cdecl _E1315_4()
{
  char *v0; // esi@1

  v0 = &PFlags_None_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_None_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770420) --------------------------------------------------------  // acclient.c:904062
void __cdecl _E1318_4()
{
  char *v0; // esi@1

  v0 = &PCType_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770450) --------------------------------------------------------  // acclient.c:904075
void __cdecl _E1321_4()
{
  char *v0; // esi@1

  v0 = &PCType_None_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_None_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770480) --------------------------------------------------------  // acclient.c:904088
void __cdecl _E1324_4()
{
  char *v0; // esi@1

  v0 = &PCType_Physics_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Physics_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007704B0) --------------------------------------------------------  // acclient.c:904101
void __cdecl _E1327_4()
{
  char *v0; // esi@1

  v0 = &PCType_Parametric_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Parametric_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007704E0) --------------------------------------------------------  // acclient.c:904114
void __cdecl _E1330_4()
{
  char *v0; // esi@1

  v0 = &PCType_AttractRepulse_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_AttractRepulse_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770510) --------------------------------------------------------  // acclient.c:904127
void __cdecl _E1333_4()
{
  char *v0; // esi@1

  v0 = &PCType_PointFile_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFile_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770540) --------------------------------------------------------  // acclient.c:904140
void __cdecl _E1336_4()
{
  char *v0; // esi@1

  v0 = &PCType_PointFileLerp_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFileLerp_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770570) --------------------------------------------------------  // acclient.c:904153
void __cdecl _E1339_4()
{
  char *v0; // esi@1

  v0 = &PhysFlags_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007705A0) --------------------------------------------------------  // acclient.c:904166
void __cdecl _E1342_4()
{
  char *v0; // esi@1

  v0 = &PhysFlags_None_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_None_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007705D0) --------------------------------------------------------  // acclient.c:904179
void __cdecl _E1345_4()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Gravity_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Gravity_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770600) --------------------------------------------------------  // acclient.c:904192
void __cdecl _E1348_4()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Wind_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Wind_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770630) --------------------------------------------------------  // acclient.c:904205
void __cdecl _E1351_4()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Momentum_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Momentum_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770660) --------------------------------------------------------  // acclient.c:904218
void __cdecl _E1354_4()
{
  char *v0; // esi@1

  v0 = &PointfileFlags_RandomPoint_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointfileFlags_RandomPoint_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770690) --------------------------------------------------------  // acclient.c:904231
void __cdecl _E1357_4()
{
  char *v0; // esi@1

  v0 = &Position_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Position_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007706C0) --------------------------------------------------------  // acclient.c:904244
void __cdecl _E1360_4()
{
  char *v0; // esi@1

  v0 = &PointList_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointList_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007706F0) --------------------------------------------------------  // acclient.c:904257
void __cdecl _E1363_4()
{
  char *v0; // esi@1

  v0 = &Point_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770720) --------------------------------------------------------  // acclient.c:904270
void __cdecl _E1366_4()
{
  char *v0; // esi@1

  v0 = &DetailLevels_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevels_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770750) --------------------------------------------------------  // acclient.c:904283
void __cdecl _E1369_4()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Low_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Low_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770780) --------------------------------------------------------  // acclient.c:904296
void __cdecl _E1372_4()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Medium_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Medium_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007707B0) --------------------------------------------------------  // acclient.c:904309
void __cdecl _E1375_4()
{
  char *v0; // esi@1

  v0 = &DetailLevel_High_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_High_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007707E0) --------------------------------------------------------  // acclient.c:904322
void __cdecl _E1378_4()
{
  char *v0; // esi@1

  v0 = &FadeSpeed_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeSpeed_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770810) --------------------------------------------------------  // acclient.c:904335
void __cdecl _E1381_3()
{
  char *v0; // esi@1

  v0 = &MaxOpacity_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxOpacity_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770840) --------------------------------------------------------  // acclient.c:904348
void __cdecl _E1384_3()
{
  char *v0; // esi@1

  v0 = &Point_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770870) --------------------------------------------------------  // acclient.c:904361
void __cdecl _E1387_2()
{
  char *v0; // esi@1

  v0 = &PointAxisPos_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointAxisPos_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007708A0) --------------------------------------------------------  // acclient.c:904374
void __cdecl _E1390_1()
{
  char *v0; // esi@1

  v0 = &PointTexture_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointTexture_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007708D0) --------------------------------------------------------  // acclient.c:904387
void __cdecl _E1393_1()
{
  char *v0; // esi@1

  v0 = &PointSize_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointSize_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770900) --------------------------------------------------------  // acclient.c:904400
void __cdecl _E1396_1()
{
  char *v0; // esi@1

  v0 = &UseOcclusion_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseOcclusion_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770930) --------------------------------------------------------  // acclient.c:904413
void __cdecl _E1399_1()
{
  char *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (char *)&unk_845EF4;
  v1 = 4;
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

//----- (00770970) --------------------------------------------------------  // acclient.c:904438
void __cdecl sub_770970()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007709A0) --------------------------------------------------------  // acclient.c:904451
void __cdecl sub_7709A0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007709D0) --------------------------------------------------------  // acclient.c:904464
void __cdecl sub_7709D0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770A00) --------------------------------------------------------  // acclient.c:904477
void __cdecl sub_770A00()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770A30) --------------------------------------------------------  // acclient.c:904490
void __cdecl sub_770A30()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770A60) --------------------------------------------------------  // acclient.c:904503
void __cdecl sub_770A60()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770A90) --------------------------------------------------------  // acclient.c:904516
void __cdecl sub_770A90()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770AC0) --------------------------------------------------------  // acclient.c:904529
void __cdecl sub_770AC0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770AF0) --------------------------------------------------------  // acclient.c:904542
void __cdecl sub_770AF0()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770B20) --------------------------------------------------------  // acclient.c:904555
void __cdecl sub_770B20()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770B50) --------------------------------------------------------  // acclient.c:904568
void __cdecl sub_770B50()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770B80) --------------------------------------------------------  // acclient.c:904581
void __cdecl sub_770B80()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770BB0) --------------------------------------------------------  // acclient.c:904594
void __cdecl _E136_82()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770BE0) --------------------------------------------------------  // acclient.c:904607
void __cdecl _E139_82()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770C10) --------------------------------------------------------  // acclient.c:904620
void __cdecl _E142_77()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770C40) --------------------------------------------------------  // acclient.c:904633
void __cdecl _E145_79()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770C70) --------------------------------------------------------  // acclient.c:904646
void __cdecl _E148_75()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_33;
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

//----- (00770CB0) --------------------------------------------------------  // acclient.c:904671
void __cdecl _E151_73()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_33;
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

//----- (00770CF0) --------------------------------------------------------  // acclient.c:904696
void __cdecl _E154_74()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_33;
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

//----- (00770D30) --------------------------------------------------------  // acclient.c:904721
void __cdecl _E157_70()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_33;
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

//----- (00770D70) --------------------------------------------------------  // acclient.c:904746
void __cdecl _E160_73()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_33;
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

//----- (00770DB0) --------------------------------------------------------  // acclient.c:904771
void __cdecl _E163_66()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_57;
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

//----- (00770DF0) --------------------------------------------------------  // acclient.c:904796
void __cdecl _E166_68()
{
  char *v0; // esi@1

  v0 = &waveform_None_57.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_57.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770E20) --------------------------------------------------------  // acclient.c:904809
void __cdecl _E169_67()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_57.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_57.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770E50) --------------------------------------------------------  // acclient.c:904822
void __cdecl _E172_65()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_57.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_57.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770E80) --------------------------------------------------------  // acclient.c:904835
void __cdecl _E175_62()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_57.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_57.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770EB0) --------------------------------------------------------  // acclient.c:904848
void __cdecl _E178_62()
{
  char *v0; // esi@1

  v0 = &waveform_Square_57.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_57.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770EE0) --------------------------------------------------------  // acclient.c:904861
void __cdecl _E181_62()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_57.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_57.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770F10) --------------------------------------------------------  // acclient.c:904874
void __cdecl _E184_59()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_57.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_57.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770F40) --------------------------------------------------------  // acclient.c:904887
void __cdecl _E187_58()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_57.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_57.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770F70) --------------------------------------------------------  // acclient.c:904900
void __cdecl _E190_59()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_57.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_57.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00770FA0) --------------------------------------------------------  // acclient.c:904913
void __cdecl _E1402_1()
{
  ImgTex::temp_buffer_table.vfptr = (HashTable<unsigned long,RenderVertexStreamD3D *,0>Vtbl *)HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81E984);
  stru_81E984.vfptr = (IntrusiveHashTable<enum PixelFormatID,HashTableData<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>Vtbl *)IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::vftable;
  if ( (HashTableData<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> **)stru_81E984.m_buckets != stru_81E984.m_aInplaceBuckets )
    operator delete[](stru_81E984.m_buckets);
  stru_81E984.m_buckets = 0;
  stru_81E984.m_firstInterestingBucket = 0;
  stru_81E984.m_numBuckets = 0;
  stru_81E984.m_numElements = 0;
}
// 7C9D3C: using guessed type int (__thiscall *IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::vftable[2])(void *, char);
// 7C9DB4: using guessed type int (__thiscall *HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::vftable[4])(void *, char);

//----- (00770FF0) --------------------------------------------------------  // acclient.c:904929
void __cdecl _E1408_1()
{
  ImgTex::custom_texture_table.vfptr = (HashSet<ImgTex *>Vtbl *)HashSet<ImgTex *>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81EA74);
  stru_81EA74.vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1>Vtbl *)IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::vftable;
  if ( (HashSetData<IDClass<_tagDataID,32,0> > **)stru_81EA74.m_buckets != stru_81EA74.m_aInplaceBuckets )
    operator delete[](stru_81EA74.m_buckets);
  stru_81EA74.m_buckets = 0;
  stru_81EA74.m_firstInterestingBucket = 0;
  stru_81EA74.m_numBuckets = 0;
  stru_81EA74.m_numElements = 0;
}
// 7C9D38: using guessed type int (__thiscall *IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::vftable[3])(void *, char);
// 7C9DB0: using guessed type int (__thiscall *HashSet<ImgTex *>::vftable[5])(void *, char);

//----- (00771040) --------------------------------------------------------  // acclient.c:904945
void __cdecl _E1405_1()
{
  ImgTex::texture_table.vfptr = (HashTable<unsigned __int64,ImgTex *,1>Vtbl *)AutoGrowHashTable<unsigned __int64,ImgTex *>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&ImgTex::texture_table.m_intrusiveTable);
  ImgTex::texture_table.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>Vtbl *)IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::vftable;
  if ( (HashTableData<unsigned __int64,ImgTex *> **)ImgTex::texture_table.m_intrusiveTable.m_buckets != ImgTex::texture_table.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](ImgTex::texture_table.m_intrusiveTable.m_buckets);
  ImgTex::texture_table.m_intrusiveTable.m_buckets = 0;
  ImgTex::texture_table.m_intrusiveTable.m_firstInterestingBucket = 0;
  ImgTex::texture_table.m_intrusiveTable.m_numBuckets = 0;
  ImgTex::texture_table.m_intrusiveTable.m_numElements = 0;
}
// 7C9D34: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::vftable[4])(void *, char);
// 7C9DBC: using guessed type int (__thiscall *AutoGrowHashTable<unsigned __int64,ImgTex *>::vftable[2])(void *, char);

