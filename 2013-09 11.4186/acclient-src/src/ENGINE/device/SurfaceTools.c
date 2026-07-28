/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SurfaceTools
   Object     : ENGINE\device\SurfaceTools.obj
   Functions  : 6
   Addresses  : 0043BDB0 - 006C6A80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0043BDB0) --------------------------------------------------------  // acclient.c:120659
HBITMAP__ *__cdecl CreateScreenCompatibleBitmapFromRGBA(unsigned int BmpWidth, unsigned int BmpHeight, SourceImageData *sid)
{
  SourceImageData *v3; // esi@1
  int v4; // ecx@1
  unsigned int v5; // eax@2
  void *v6; // edx@2
  unsigned int i; // ebx@2
  unsigned int *v8; // edi@3
  unsigned int j; // ecx@3
  HDC__ *v10; // eax@9
  HDC__ *v11; // ebx@9
  HDC v12; // edi@9
  HDC v13; // ebp@9
  HBITMAP v14; // eax@9
  HBITMAP__ *result; // eax@21
  void *pDIBits; // [sp+Ch] [bp-40h]@1
  HBITMAP__ *hbmDIB; // [sp+10h] [bp-3Ch]@1
  HBITMAP__ *hOldDestBitmap; // [sp+14h] [bp-38h]@12
  HBITMAP__ *hOldSrcBitmap; // [sp+18h] [bp-34h]@12
  HDC__ *hScreenDC; // [sp+1Ch] [bp-30h]@9
  tagBITMAPINFO Info; // [sp+20h] [bp-2Ch]@1
  void *sida; // [sp+58h] [bp+Ch]@9

  v3 = sid;
  v4 = sid->cxImage;
  Info.bmiHeader.biHeight = sid->cyImage;
  Info.bmiHeader.biSizeImage = 4 * v4 * Info.bmiHeader.biHeight;
  Info.bmiHeader.biWidth = v4;
  Info.bmiHeader.biSize = 40;
  Info.bmiHeader.biPlanes = 1;
  Info.bmiHeader.biBitCount = 32;
  Info.bmiHeader.biCompression = 0;
  Info.bmiHeader.biXPelsPerMeter = 0;
  Info.bmiHeader.biYPelsPerMeter = 0;
  Info.bmiHeader.biClrUsed = 0;
  Info.bmiHeader.biClrImportant = 0;
  pDIBits = 0;
  hbmDIB = CreateDIBSection(0, &Info, 0, &pDIBits, 0, 0);
  if ( hbmDIB )
  {
    v5 = sid->cyImage;
    v6 = pDIBits;
    for ( i = 0; i < v5; ++i )
    {
      v8 = &sid->pData[sid->pitch * (v5 - i - 1) >> 2];
      for ( j = 0; j < sid->cxImage; ++j )
      {
        if ( (v8[j] & 0xFF000000) >= 0x40000000 )
          *(_DWORD *)v6 = v8[j];
        else
          *(_DWORD *)v6 = 0;
        v6 = (char *)v6 + 4;
      }
      v5 = sid->cyImage;
    }
    v10 = GetDC(0);
    v11 = v10;
    hScreenDC = v10;
    v12 = CreateCompatibleDC(v10);
    v13 = CreateCompatibleDC(v11);
    v14 = CreateCompatibleBitmap(v11, BmpWidth, BmpHeight);
    sida = v14;
    if ( v12 && v13 )
    {
      if ( v14 )
      {
        hOldSrcBitmap = (HBITMAP__ *)SelectObject(v13, hbmDIB);
        hOldDestBitmap = (HBITMAP__ *)SelectObject(v12, sida);
        PatBlt(v12, 0, 0, BmpWidth, BmpHeight, 0x42u);
        BitBlt(v12, 0, 0, v3->cxImage, v3->cyImage, v13, 0, 0, 0xCC0020u);
        SelectObject(v12, hOldDestBitmap);
        SelectObject(v13, hOldSrcBitmap);
        v11 = hScreenDC;
      }
    }
    else if ( v14 )
    {
      DeleteObject(v14);
      sida = 0;
    }
    if ( v11 )
      ReleaseDC(0, v11);
    if ( v13 )
      DeleteDC(v13);
    if ( v12 )
      DeleteDC(v12);
    DeleteObject(hbmDIB);
    result = (HBITMAP__ *)sida;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0043BF80) --------------------------------------------------------  // acclient.c:120756
HBITMAP__ *__cdecl CreateMonoBitmapFromRGBA(unsigned int BmpWidth, unsigned int BmpHeight, SourceImageData *sid, const bool _MonoOnly)
{
  signed int v4; // esi@3
  char v5; // bl@3
  SourceImageData *v6; // ebp@5
  unsigned int v7; // ecx@5
  char *v8; // edi@9
  int v9; // eax@9
  unsigned int v10; // ebp@10
  signed int v11; // esi@10
  unsigned int v12; // eax@10
  int v13; // eax@15
  int v14; // edx@22
  int v15; // eax@22
  signed int v16; // edi@25
  unsigned int v17; // edx@25
  unsigned int v18; // ebp@25
  unsigned int v19; // ecx@28
  char v20; // bl@28
  unsigned int v21; // esi@29
  unsigned int v22; // edx@29
  unsigned int v23; // ecx@29
  char v24; // cl@34
  int v25; // ecx@38
  HBITMAP v26; // esi@43
  HBITMAP__ *result; // eax@43
  unsigned int xDim; // [sp+0h] [bp-14h]@5
  char *pMonoData; // [sp+4h] [bp-10h]@5
  int AdjBmpHeight; // [sp+8h] [bp-Ch]@1
  unsigned int y; // [sp+Ch] [bp-8h]@9
  unsigned int *pSrc; // [sp+10h] [bp-4h]@25
  unsigned int _MonoOnlya; // [sp+24h] [bp+10h]@22

  AdjBmpHeight = BmpHeight;
  if ( _MonoOnly )
    AdjBmpHeight = 2 * BmpHeight;
  v4 = AdjBmpHeight * (BmpWidth >> 3);
  v5 = -1;
  if ( !v4 || BmpWidth & 7 )
  {
    result = 0;
  }
  else
  {
    v6 = sid;
    pMonoData = (char *)operator new[](AdjBmpHeight * (BmpWidth >> 3));
    memset(pMonoData, 0xFFu, v4);
    v7 = BmpWidth;
    xDim = BmpWidth;
    if ( sid->cxImage < BmpWidth )
    {
      xDim = sid->cxImage;
      v7 = sid->cxImage;
    }
    if ( sid->cyImage < BmpHeight )
      BmpHeight = sid->cyImage;
    v8 = pMonoData;
    v9 = 0;
    y = 0;
    if ( BmpHeight )
    {
      do
      {
        v10 = (unsigned int)&v6->pData[v9 * v6->pitch >> 2];
        v11 = 0;
        v12 = 0;
        if ( !v7 )
          goto LABEL_47;
        do
        {
          if ( v11 == 8 )
          {
            *v8++ = v5;
            v5 = -1;
            v11 = 0;
          }
          ++v11;
          v5 = ((*(_DWORD *)(v10 + 4 * v12++) & 0xFF000000) < 0x40000000) | 2 * v5;
        }
        while ( v12 < v7 );
        if ( v11 < 8 )
        {
LABEL_47:
          v13 = 8 - v11;
          do
          {
            v5 = 2 * v5 | 1;
            --v13;
          }
          while ( v13 );
        }
        *v8++ = v5;
        if ( BmpWidth > v7 )
          v8 += (BmpWidth - v7) >> 3;
        v6 = sid;
        v9 = y++ + 1;
      }
      while ( y < BmpHeight );
      v4 = AdjBmpHeight * (BmpWidth >> 3);
    }
    if ( _MonoOnly )
    {
      v14 = 0;
      v15 = (int)&pMonoData[v4 / 2];
      _MonoOnlya = 0;
      if ( BmpHeight )
      {
        while ( 1 )
        {
          v16 = 0;
          v17 = (unsigned int)&v6->pData[v14 * v6->pitch >> 2];
          v18 = 0;
          pSrc = (unsigned int *)v17;
          if ( !v7 )
            goto LABEL_48;
          do
          {
            if ( v16 == 8 )
            {
              *(_BYTE *)v15++ = v5;
              v5 = -1;
              v16 = 0;
            }
            v19 = pSrc[v18];
            ++v16;
            v20 = 2 * v5;
            if ( (pSrc[v18] & 0xFF000000) < 0x40000000 )
              goto LABEL_49;
            v21 = BYTE1(v19);
            v22 = (unsigned __int8)(v19 >> 16);
            v23 = (unsigned __int8)v19;
            if ( v22 <= v21 )
              v22 = v21;
            if ( v22 <= v23 )
              v22 = v23;
            if ( v22 <= 0x40 )
LABEL_49:
              v24 = 0;
            else
              v24 = 1;
            v5 = v24 | v20;
            ++v18;
          }
          while ( v18 < xDim );
          if ( v16 < 8 )
          {
LABEL_48:
            v25 = 8 - v16;
            do
            {
              v5 = 2 * v5 | 1;
              --v25;
            }
            while ( v25 );
          }
          *(_BYTE *)v15++ = v5;
          if ( BmpWidth > xDim )
            v15 += (BmpWidth - xDim) >> 3;
          v14 = _MonoOnlya++ + 1;
          if ( _MonoOnlya >= BmpHeight )
            break;
          v7 = xDim;
          v6 = sid;
        }
      }
    }
    v26 = CreateBitmap(BmpWidth, AdjBmpHeight, 1u, 1u, pMonoData);
    operator delete[](pMonoData);
    result = v26;
  }
  return result;
}

//----- (0043C1E0) --------------------------------------------------------  // acclient.c:120930
HICON__ *__cdecl CreateIconFromRGBA(SourceImageData *sid, int xHotspot, int yHotspot, const bool _MonoOnly)
{
  HICON v4; // ebp@1
  HBITMAP__ *v5; // edi@1
  HBITMAP__ *v6; // esi@3
  _ICONINFO IconInfo; // [sp+10h] [bp-14h]@4

  v4 = 0;
  v5 = 0;
  if ( !_MonoOnly )
    v5 = CreateScreenCompatibleBitmapFromRGBA(0x20u, 0x20u, sid);
  v6 = CreateMonoBitmapFromRGBA(0x20u, 0x20u, sid, _MonoOnly);
  if ( v6 )
  {
    IconInfo.fIcon = 0;
    IconInfo.hbmColor = v5;
    IconInfo.hbmMask = v6;
    IconInfo.xHotspot = xHotspot;
    IconInfo.yHotspot = yHotspot;
    v4 = CreateIconIndirect(&IconInfo);
  }
  DeleteObject(v5);
  DeleteObject(v6);
  return v4;
}

//----- (0043C260) --------------------------------------------------------  // acclient.c:120957
char __cdecl CreateIconFromRenderSurface(unsigned int i_xHotSpot, unsigned int i_yHotSpot, RenderSurface *i_image, HICON__ **o_icon)
{
  HICON__ **v4; // ebp@1
  RenderSurface *v5; // edi@1
  char v6; // bl@1
  int v7; // esi@4
  int v8; // edx@5
  int v9; // edx@5
  unsigned int v10; // edx@6
  unsigned int v11; // eax@6
  HWND__ *v12; // ecx@6
  char result; // al@8
  tagRECT rect; // [sp+24h] [bp-4Ch]@5
  SourceImageData sid; // [sp+34h] [bp-3Ch]@6
  SurfaceWindow destWindow; // [sp+44h] [bp-2Ch]@5

  v4 = o_icon;
  v5 = i_image;
  *o_icon = 0;
  v6 = 0;
  if ( v5->width > 0x20 || v5->height > 0x20 || v5->m_pSurfaceBits )
  {
    result = 0;
  }
  else
  {
    v7 = ((int (*)(void))RenderDevice::render_device->vfptr->CreateSurface)();
    if ( (unsigned __int8)(*(int (__thiscall **)(int, signed int, signed int, signed int, signed int))(*(_DWORD *)v7 + 88))(
                            v7,
                            32,
                            32,
                            21,
                            1) )
    {
      SurfaceWindow::Fill((SurfaceWindow *)(v7 + 172), &RGBAColor_Null_1);
      SurfaceWindow::SurfaceWindow(&destWindow, (RenderSurface *)v7, 0, 0, v5->width - 1, v5->height - 1);
      SurfaceWindow::Blit(&destWindow, &v5->window);
      v8 = *(_DWORD *)(v7 + 160);
      rect.bottom = *(_DWORD *)(v7 + 164);
      rect.right = v8;
      v9 = *(_DWORD *)v7;
      rect.top = 0;
      rect.left = 0;
      if ( (unsigned __int8)(*(int (__thiscall **)(int, tagRECT *, signed int, RenderSurface **, HICON__ ***))(v9 + 96))(
                              v7,
                              &rect,
                              2,
                              &i_image,
                              &o_icon) )
      {
        v10 = *(_DWORD *)(v7 + 160);
        v11 = *(_DWORD *)(v7 + 164);
        sid.pData = (unsigned int *)o_icon;
        sid.cxImage = v10;
        sid.pitch = (unsigned int)i_image;
        v12 = RenderDevice::render_device[1].m_config.hFocusWindow;
        sid.cyImage = v11;
        *v4 = CreateIconFromRGBA(&sid, i_xHotSpot, i_yHotSpot, v12 == 0);
        (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 100))(v7);
        v6 = 1;
      }
      destWindow.vfptr = (SurfaceWindowVtbl *)SurfaceWindow::vftable;
      SurfaceWindow::End(&destWindow);
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 20))(v7);
    result = v6;
  }
  return result;
}
// 798D14: using guessed type int (__thiscall *SurfaceWindow::vftable[2])(void *, char);

//----- (006C6A70) --------------------------------------------------------  // acclient.c:734822
void _E73_30()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_5, PFID_A8R8G8B8);
}

//----- (006C6A80) --------------------------------------------------------  // acclient.c:734828
int _E1_28()
{
  return atexit(_E2_28);
}

