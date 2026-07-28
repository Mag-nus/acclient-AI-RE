/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SurfaceWindow
   Object     : ENGINE\render_base\SurfaceWindow.obj
   Functions  : 41
   Addresses  : 00440DA0 - 0072A7C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00440DA0) --------------------------------------------------------  // acclient.c:125147
bool __thiscall SurfaceWindow::End(SurfaceWindow *this)
{
  return this->lockCount == 0;
}

//----- (00440DB0) --------------------------------------------------------  // acclient.c:125153
void __thiscall SurfaceWindow::Attach(SurfaceWindow *this, RenderSurface *_surface, tagRECT *_rect)
{
  char *v3; // edx@1
  int v4; // eax@5
  int v5; // eax@7
  int v6; // eax@13
  int v7; // eax@15

  this->surface = _surface;
  this->parent = 0;
  v3 = (char *)&this->rect;
  this->rect = *_rect;
  if ( this->rect.left < 0 )
    *(_DWORD *)v3 = 0;
  if ( this->rect.top < 0 )
    this->rect.top = 0;
  v4 = _surface->width;
  if ( this->rect.right > v4 )
    this->rect.right = v4;
  v5 = _surface->height;
  if ( this->rect.bottom > v5 )
    this->rect.bottom = v5;
  if ( this->rect.right < 1 )
    this->rect.right = 1;
  if ( this->rect.bottom < 1 )
    this->rect.bottom = 1;
  v6 = this->rect.right;
  if ( *(_DWORD *)v3 >= v6 )
    *(_DWORD *)v3 = v6 - 1;
  v7 = this->rect.bottom;
  if ( this->rect.top >= v7 )
    this->rect.top = v7 - 1;
}

//----- (00440E40) --------------------------------------------------------  // acclient.c:125188
void __thiscall SurfaceWindow::Attach(SurfaceWindow *this, RenderSurface *_surface, const unsigned int x0, const unsigned int y0, const unsigned int x1, const unsigned int y1)
{
  tagRECT r; // [sp+0h] [bp-10h]@1

  r.left = x0;
  r.top = y0;
  r.right = x1 + 1;
  r.bottom = y1 + 1;
  SurfaceWindow::Attach(this, _surface, &r);
}

//----- (00440E80) --------------------------------------------------------  // acclient.c:125200
void __thiscall SurfaceWindow::Attach(SurfaceWindow *this, SurfaceWindow *_window, tagRECT *rect)
{
  int v3; // ebx@1
  int v4; // edx@1
  int v5; // edi@1
  int v6; // ebx@1
  RenderSurface *v7; // ST00_4@1
  int v8; // ecx@1
  tagRECT r; // [sp+Ch] [bp-10h]@1

  v3 = rect->top;
  v4 = _window->rect.left;
  r.left = v4 + rect->left;
  v5 = _window->rect.top;
  r.top = v5 + v3;
  v6 = v4 + rect->right;
  r.bottom = v5 + rect->bottom;
  v7 = _window->surface;
  r.right = v6;
  SurfaceWindow::Attach(this, v7, &r);
  *(_DWORD *)(v8 + 8) = _window;
}

//----- (00440EE0) --------------------------------------------------------  // acclient.c:125224
void __thiscall SurfaceWindow::WindowToClip(SurfaceWindow *this, const int x, const int y, float *clipX, float *clipY)
{
  RenderDeviceD3D::TransformPixelToClipPoint(
    x + this->rect.left,
    y + this->rect.top,
    this->surface->width,
    this->surface->height,
    clipX,
    clipY);
}

//----- (00440F20) --------------------------------------------------------  // acclient.c:125236
char __thiscall SurfaceWindow::Lock(SurfaceWindow *this, const bool readOnly)
{
  SurfaceWindow *v2; // esi@1
  RenderSurface *v3; // ecx@1
  unsigned int v4; // eax@2
  SurfaceWindow *v6; // eax@5
  int v7; // ecx@6
  SurfaceWindow *v8; // eax@6
  int v9; // ecx@6
  int v10; // edi@6
  bool v11; // zf@6

  v2 = this;
  v3 = this->surface;
  if ( v3 )
  {
    v4 = v2->lockCount;
    if ( v4 )
    {
      if ( (readOnly == 0) == v2->writable )
      {
        v2->lockCount = v4 + 1;
        return 1;
      }
      return 0;
    }
    v6 = v2->parent;
    if ( v6 )
    {
      SurfaceWindow::Lock(v6, readOnly);
      v7 = v2->lockCount + 1;
      v2->writable = readOnly == 0;
      v8 = v2->parent;
      v2->lockCount = v7;
      v9 = v2->rect.left - v8->rect.left;
      v10 = v2->rect.top - v8->rect.top;
      v11 = v2->rect.left == v8->rect.left;
      v2->data = v8->data;
      v2->pitch = v8->pitch;
      if ( !v11 )
        v2->data = (char *)v2->data + v9 * v2->surface->pfDesc.bitsPerPixel / 8;
      if ( v10 )
      {
        v2->data = (char *)v2->data + v10 * v2->pitch;
        return 1;
      }
      return 1;
    }
    if ( !v3->locked
      && (unsigned __int8)((int (__stdcall *)(int, int, int, int))v3->vfptr[4].IUnknown_QueryInterface)(
                            &v2->rect,
                            readOnly != 0 ? 2 : 0,
                            &v2->pitch,
                            &v2->data) )
    {
      ++v2->lockCount;
      v2->writable = readOnly == 0;
      return 1;
    }
  }
  return 0;
}

//----- (00441030) --------------------------------------------------------  // acclient.c:125300
char __thiscall SurfaceWindow::Unlock(SurfaceWindow *this)
{
  SurfaceWindow *v1; // esi@1
  RenderSurface *v2; // edx@1
  unsigned int v3; // eax@2
  SurfaceWindow *v4; // ecx@4
  int v5; // eax@5
  bool v6; // zf@9
  char result; // al@13

  v1 = this;
  v2 = this->surface;
  if ( v2 && (v3 = this->lockCount) != 0 && v2->locked )
  {
    v4 = this->parent;
    if ( v4 )
    {
      v5 = v3 - 1;
      v1->lockCount = v5;
      if ( !v5 )
        SurfaceWindow::Unlock(v4);
    }
    else
    {
      if ( v1->writable )
        v2->m_IsDirty = 1;
      v6 = v1->lockCount-- == 1;
      if ( v6 )
        ((void (*)(void))v1->surface->vfptr[4].IUnknown_AddRef)();
    }
    if ( !v1->lockCount )
    {
      v1->pitch = 0;
      v1->data = 0;
      v1->writable = 0;
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004410A0) --------------------------------------------------------  // acclient.c:125346
char __thiscall SurfaceWindowLocker::Lock(SurfaceWindowLocker *this, bool i_bReadOnly)
{
  SurfaceWindowLocker *v2; // esi@1
  char result; // al@2
  SurfaceWindow *v4; // ecx@3

  v2 = this;
  if ( this->m_bLocked )
  {
    result = 1;
  }
  else
  {
    v4 = this->m_pSurface;
    if ( v2->m_pSurface && SurfaceWindow::Lock(v4, i_bReadOnly) )
    {
      result = 1;
      v2->m_bLocked = 1;
    }
    else
    {
      result = 0;
      v2->m_bLocked = 0;
    }
  }
  return result;
}

//----- (004410E0) --------------------------------------------------------  // acclient.c:125375
char __thiscall SurfaceWindow::CopyAlpha(SurfaceWindow *this, SurfaceWindow *i_swSource)
{
  SurfaceWindow *v2; // esi@1
  RenderSurface *v3; // eax@5
  PixelFormatID v4; // eax@6
  BlitDataFormat v5; // ecx@8
  char *v6; // edx@11
  RenderSurface *v7; // eax@11
  PixelFormatID v8; // eax@12
  BlitDataFormat v9; // eax@14
  char *v10; // edx@17
  int v11; // edx@19
  unsigned int v12; // ecx@19
  unsigned int v13; // eax@19
  AlphaConvertArgs cCvtArgs; // [sp+8h] [bp-20h]@11

  v2 = this;
  if ( !this || !SurfaceWindow::Lock(this, 0) )
    return 0;
  if ( !i_swSource || !SurfaceWindow::Lock(i_swSource, 1) )
  {
LABEL_25:
    SurfaceWindow::Unlock(v2);
    return 0;
  }
  v3 = v2->surface;
  if ( !v3 )
    goto LABEL_29;
  v4 = v3->pfDesc.format;
  if ( v4 == 21 )
  {
    v5 = 2;
    goto LABEL_11;
  }
  if ( v4 != 28 )
  {
LABEL_29:
    v5 = -1;
    goto LABEL_11;
  }
  v5 = 1;
LABEL_11:
  v6 = (char *)v2->data;
  cCvtArgs.cDstArgs.iStride = v2->pitch;
  v7 = i_swSource->surface;
  cCvtArgs.cDstArgs.eBlitFormat = v5;
  cCvtArgs.cDstArgs.pDstBuf = v6;
  if ( !v7 )
    goto LABEL_30;
  v8 = v7->pfDesc.format;
  if ( v8 == 21 )
  {
    v9 = 2;
    goto LABEL_17;
  }
  if ( v8 != 28 )
  {
LABEL_30:
    v9 = -1;
    goto LABEL_17;
  }
  v9 = 1;
LABEL_17:
  cCvtArgs.cSrcArgs.iStride = i_swSource->pitch;
  v10 = (char *)i_swSource->data;
  cCvtArgs.cSrcArgs.eBlitFormat = v9;
  cCvtArgs.cSrcArgs.pDstBuf = v10;
  if ( v5 == -1 || v9 == -1 )
  {
    SurfaceWindow::Unlock(i_swSource);
    goto LABEL_25;
  }
  v11 = i_swSource->rect.right - i_swSource->rect.left;
  v12 = i_swSource->rect.bottom - i_swSource->rect.top;
  v13 = v2->rect.bottom - v2->rect.top;
  cCvtArgs.nWidth = i_swSource->rect.right - i_swSource->rect.left;
  cCvtArgs.nHeight = v12;
  if ( v12 > v13 )
    cCvtArgs.nHeight = v13;
  if ( v11 > (unsigned int)(v2->rect.right - v2->rect.left) )
    cCvtArgs.nWidth = v2->rect.right - v2->rect.left;
  AlphaConvert(&cCvtArgs);
  SurfaceWindow::Unlock(i_swSource);
  SurfaceWindow::Unlock(v2);
  return 1;
}

//----- (00441210) --------------------------------------------------------  // acclient.c:125463
char __thiscall SurfaceWindow::DrawLine(SurfaceWindow *this, RGBAColor *color, const int aX, const int aY, const int bX, const int bY)
{
  const int v6; // ebp@1
  const int v7; // eax@1
  const int v8; // edx@1
  char result; // al@10
  int v10; // eax@11
  int v11; // ecx@14
  int v12; // edx@15
  int v13; // esi@17
  int v14; // edi@23
  int v15; // ecx@23
  const int v16; // eax@23
  bool v17; // zf@31
  SurfaceWindow *v18; // [sp+10h] [bp-14h]@1
  int nRectWidth; // [sp+14h] [bp-10h]@1
  int nRectHeight; // [sp+18h] [bp-Ch]@1
  char *pixels; // [sp+1Ch] [bp-8h]@11
  unsigned int fillColor; // [sp+20h] [bp-4h]@9
  int colora; // [sp+28h] [bp+4h]@21
  unsigned __int8 sUnitY; // [sp+2Ch] [bp+8h]@9
  int BPP; // [sp+30h] [bp+Ch]@24
  int BPPa; // [sp+30h] [bp+Ch]@34
  int i; // [sp+34h] [bp+10h]@12
  const int bYa; // [sp+38h] [bp+14h]@18

  v6 = aX;
  v7 = this->rect.right - this->rect.left;
  v8 = this->rect.bottom - this->rect.top;
  v18 = this;
  nRectWidth = this->rect.right - this->rect.left;
  nRectHeight = this->rect.bottom - this->rect.top;
  if ( (aX <= v7 || bX <= v7)
    && (aX >= 0 || bX >= 0)
    && (aY <= v8 || bY <= v8)
    && (aY >= 0 || bY >= 0)
    && (fillColor = RGBAColor::GetColor32(color),
        sUnitY = (unsigned __int8)v18->surface->pfDesc.bitsPerPixel >> 3,
        SurfaceWindow::Lock(v18, 0)) )
  {
    v10 = bX - v6;
    pixels = (char *)v18->data;
    if ( bX - v6 < 0 )
      i = v6 - bX;
    else
      i = bX - v6;
    v11 = bY - aY;
    if ( bY - aY < 0 )
      v12 = aY - bY;
    else
      v12 = bY - aY;
    v13 = i - v12;
    if ( v10 <= 0 )
      bYa = -(v10 < 0);
    else
      bYa = 1;
    if ( v11 <= 0 )
      colora = -(v11 < 0);
    else
      colora = 1;
    v14 = i;
    v15 = v6;
    v16 = aY;
    if ( i >= v12 )
    {
      BPP = i;
      while ( 1 )
      {
        do
        {
          if ( v15 >= 0 && v16 >= 0 && v15 < nRectWidth && v16 < nRectHeight )
          {
            *(_DWORD *)(&pixels[v15 * sUnitY] + v16 * v18->pitch) = fillColor;
            v14 = i;
          }
          if ( v13 < 0 )
            break;
          v17 = BPP-- == 0;
          if ( v17 )
            goto LABEL_44;
          v15 += bYa;
          v13 -= v12;
        }
        while ( v13 >= 0 );
        v16 += colora;
        v13 += v14;
      }
    }
    BPPa = v12;
    while ( 1 )
    {
      do
      {
        if ( v15 >= 0 && v16 >= 0 && v15 < nRectWidth && v16 < nRectHeight )
        {
          *(_DWORD *)(&pixels[v15 * sUnitY] + v16 * v18->pitch) = fillColor;
          v14 = i;
        }
        if ( v13 < 0 )
          break;
        v15 += bYa;
        v13 -= v12;
      }
      while ( v13 >= 0 );
      v17 = BPPa-- == 0;
      if ( v17 )
        break;
      v16 += colora;
      v13 += v14;
    }
LABEL_44:
    SurfaceWindow::Unlock(v18);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004413F0) --------------------------------------------------------  // acclient.c:125585
bool __thiscall SurfaceWindow::DrawBox(SurfaceWindow *this, RGBAColor *color, const int tlX, const int tlY, const int brX, const int brY)
{
  SurfaceWindow *v6; // esi@1
  bool result; // al@1

  v6 = this;
  result = SurfaceWindow::DrawLine(this, color, tlX, tlY, brX, tlY);
  if ( result )
  {
    if ( SurfaceWindow::DrawLine(v6, color, tlX, brY, brX, brY)
      && SurfaceWindow::DrawLine(v6, color, tlX, tlY, tlX, brY) )
      result = SurfaceWindow::DrawLine(v6, color, brX, tlY, brX, brY) != 0;
    else
      result = 0;
  }
  return result;
}

//----- (00441480) --------------------------------------------------------  // acclient.c:125604
void __usercall CreateCharRectPair(int yd@<edx>, int xp@<ecx>, int a3@<ebx>, int xs, int ys, int ws, int hs, int xd, int wd, int hd, int yp, tagRECT *o_rs, tagRECT *o_rd)
{
  int v13; // edx@3
  int v14; // esi@5
  int v15; // esi@7

  o_rs->left = xs - yd;
  o_rs->top = ys - yp;
  o_rs->right = yd + ws + xs;
  o_rs->bottom = yp + hs + ys;
  o_rd->top = a3 - yp;
  o_rd->right = yd + xd + ws;
  o_rd->left = xd - yd;
  o_rd->bottom = yd + a3 + hs;
  if ( xd - yd < 0 )
  {
    o_rs->left -= xd - yd;
    o_rd->left = 0;
  }
  v13 = o_rd->top;
  if ( v13 < 0 )
  {
    o_rs->top -= v13;
    o_rd->top = 0;
  }
  v14 = o_rd->right;
  if ( v14 > wd )
  {
    o_rs->right += wd - v14;
    o_rd->right = wd;
  }
  v15 = o_rd->bottom;
  if ( v15 > hd )
  {
    o_rs->bottom += hd - v15;
    o_rd->bottom = hd;
  }
}

//----- (00441530) --------------------------------------------------------  // acclient.c:125644
char __thiscall SurfaceWindow::ReplaceColor(SurfaceWindow *this, RGBAColor *i_oldColor, RGBAColor *i_newColor)
{
  SurfaceWindow *v3; // esi@1
  char result; // al@1
  int v5; // ebx@2
  unsigned int v6; // eax@2
  int v7; // edi@2
  void *v8; // eax@2
  int v9; // ebx@3
  int v10; // edx@4
  int i; // ecx@4
  RGBAColor *i_oldColora; // [sp+8h] [bp+4h]@2
  unsigned int oldColor; // [sp+Ch] [bp+8h]@2

  v3 = this;
  result = SurfaceWindow::Lock(this, 0);
  if ( result )
  {
    v5 = v3->rect.right - v3->rect.left;
    i_oldColora = (RGBAColor *)RGBAColor::GetColor32(i_oldColor);
    v6 = RGBAColor::GetColor32(i_newColor);
    v7 = v3->rect.bottom - v3->rect.top - 1;
    oldColor = v6;
    v8 = v3->data;
    if ( v7 >= 0 )
    {
      v9 = v5 - 1;
      do
      {
        v10 = v9;
        for ( i = (int)((char *)v8 + v7 * v3->pitch); v10 >= 0; --v10 )
        {
          if ( *(RGBAColor **)(i + 4 * v10) == i_oldColora )
            *(_DWORD *)(i + 4 * v10) = oldColor;
        }
        --v7;
      }
      while ( v7 >= 0 );
    }
    SurfaceWindow::Unlock(v3);
    result = 1;
  }
  return result;
}

//----- (004415B0) --------------------------------------------------------  // acclient.c:125690
char __thiscall SurfaceWindow::ReplaceColor(SurfaceWindow *this, RGBAColor *i_oldColor, SurfaceWindow *i_newData)
{
  SurfaceWindow *v3; // ebp@1
  SurfaceWindow *v4; // ebx@1
  int v6; // edi@7
  unsigned int v7; // eax@7
  int v8; // esi@7
  int v9; // eax@8
  int v10; // ecx@9
  int v11; // edi@10
  int v12; // edx@10
  int v13; // ecx@10
  char *srcData; // [sp+10h] [bp-8h]@7
  unsigned int maskColor; // [sp+14h] [bp-4h]@7
  RGBAColor *i_oldColora; // [sp+1Ch] [bp+4h]@7

  v3 = i_newData;
  v4 = this;
  if ( i_newData->rect.right - i_newData->rect.left < (unsigned int)(this->rect.right - this->rect.left)
    || i_newData->rect.bottom - i_newData->rect.top < (unsigned int)(this->rect.bottom - this->rect.top)
    || !SurfaceWindow::Lock(this, 0) )
    return 0;
  if ( !SurfaceWindow::Lock(i_newData, 1) )
  {
    SurfaceWindow::Unlock(v4);
    return 0;
  }
  v6 = v4->rect.right - v4->rect.left;
  v7 = RGBAColor::GetColor32(i_oldColor);
  i_oldColora = (RGBAColor *)v4->data;
  v8 = v4->rect.bottom - v4->rect.top - 1;
  maskColor = v7;
  srcData = (char *)i_newData->data;
  if ( v8 >= 0 )
  {
    v9 = v6 - 1;
    do
    {
      v10 = (int)((char *)i_oldColora + v8 * v4->pitch);
      if ( v9 >= 0 )
      {
        v11 = v10 + 4 * v9;
        v12 = (int)(&srcData[v8 * v3->pitch] - v10);
        v13 = v9 + 1;
        do
        {
          if ( *(_DWORD *)v11 == maskColor )
            *(_DWORD *)v11 = *(_DWORD *)(v12 + v11);
          v11 -= 4;
          --v13;
        }
        while ( v13 );
        v3 = i_newData;
      }
      --v8;
    }
    while ( v8 >= 0 );
  }
  SurfaceWindow::Unlock(v4);
  SurfaceWindow::Unlock(v3);
  return 1;
}

//----- (004416A0) --------------------------------------------------------  // acclient.c:125754
bool __thiscall SurfaceWindow::PointTestOverlay(SurfaceWindow *this, const int x, const int y)
{
  SurfaceWindow *v3; // esi@1
  RenderSurface *v4; // eax@6
  int v5; // edi@6
  bool result; // al@8

  v3 = this;
  if ( x >= 0
    && y >= 0
    && x < this->rect.right - this->rect.left
    && y < this->rect.bottom - this->rect.top
    && SurfaceWindow::Lock(this, 1) )
  {
    v4 = v3->surface;
    v5 = *(_DWORD *)((char *)v3->data + y * v3->pitch + x * ((unsigned int)v4->pfDesc.bitsPerPixel >> 3));
    if ( v4->pfDesc.flags & 2 )
      v5 &= ~v4->pfDesc.alphaBitMask;
    SurfaceWindow::Unlock(v3);
    result = v5 != 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00441730) --------------------------------------------------------  // acclient.c:125783
char __thiscall SurfaceWindow::GetColorFromPoint(SurfaceWindow *this, RGBAColor *_cColor, const int x, const int y)
{
  SurfaceWindow *v4; // esi@1
  const unsigned int v5; // edi@6
  char result; // al@6

  v4 = this;
  if ( x >= 0
    && y >= 0
    && x < this->rect.right - this->rect.left
    && y < this->rect.bottom - this->rect.top
    && SurfaceWindow::Lock(this, 1) )
  {
    v5 = *(_DWORD *)((char *)v4->data + y * v4->pitch + x * ((unsigned int)v4->surface->pfDesc.bitsPerPixel >> 3));
    SurfaceWindow::Unlock(v4);
    RGBAColor::SetColor32(_cColor, v5);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004417B0) --------------------------------------------------------  // acclient.c:125809
char __thiscall SurfaceWindow::SearchForColor(SurfaceWindow *this, int *o_x, int *o_y, RGBAColor *i_cColor, bool bReturnClosest)
{
  SurfaceWindow *v5; // edi@1
  char result; // al@1
  float v7; // edx@2
  int v8; // esi@2
  int v9; // eax@2
  int v10; // edx@2
  int v11; // ebx@2
  int v12; // ebp@4
  int v13; // ecx@5
  int v14; // eax@5
  float diffColor_8; // ST3C_4@7
  float diffColor; // ST34_4@7
  float v17; // ST3C_4@7
  RGBAColor *v18; // esi@7
  bool bFound; // [sp+7h] [bp-3Dh]@1
  unsigned int cColor32; // [sp+8h] [bp-3Ch]@2
  int nHeight; // [sp+Ch] [bp-38h]@2
  int nWidth; // [sp+10h] [bp-34h]@2
  float cColor; // [sp+14h] [bp-30h]@2
  float cColor_4; // [sp+18h] [bp-2Ch]@2
  float cColor_8; // [sp+1Ch] [bp-28h]@2
  RGBAColor testColor; // [sp+34h] [bp-10h]@7
  RGBAColor *i_cColora; // [sp+50h] [bp+Ch]@2

  v5 = this;
  bFound = 0;
  result = SurfaceWindow::Lock(this, 1);
  if ( result )
  {
    cColor = i_cColor->r;
    cColor_4 = i_cColor->g;
    v7 = i_cColor->a;
    cColor_8 = i_cColor->b;
    v8 = (unsigned __int64)(cColor_8 * 255.0) | (((unsigned int)(unsigned __int64)(cColor_4 * 255.0) | ((unsigned int)(unsigned __int64)(i_cColor->r * 255.0) << 8)) << 8);
    v9 = v5->rect.bottom - v5->rect.top;
    v10 = v5->rect.right - v5->rect.left;
    v11 = 0;
    cColor32 = (unsigned __int64)(cColor_8 * 255.0) | (((unsigned int)(unsigned __int64)(cColor_4 * 255.0) | ((unsigned int)(unsigned __int64)(i_cColor->r * 255.0) << 8)) << 8);
    nWidth = v5->rect.right - v5->rect.left;
    nHeight = v5->rect.bottom - v5->rect.top;
    for ( i_cColora = (RGBAColor *)-1; v11 < v9; ++v11 )
    {
      if ( bFound )
        break;
      v12 = 0;
      if ( v10 > 0 )
      {
        while ( 1 )
        {
          v13 = *(_DWORD *)((char *)v5->data
                          + v11 * v5->pitch
                          + v12 * ((unsigned int)v5->surface->pfDesc.bitsPerPixel >> 3));
          v14 = v13 | ((v13 | (*(_DWORD *)((char *)v5->data
                                         + v11 * v5->pitch
                                         + v12 * ((unsigned int)v5->surface->pfDesc.bitsPerPixel >> 3)) << 8)) << 8);
          if ( v14 == v8 )
            break;
          if ( bReturnClosest )
          {
            RGBAColor::SetColor32(&testColor, v14);
            diffColor_8 = cColor_8 - testColor.b;
            diffColor = fabs(cColor - testColor.r);
            v17 = fabs(diffColor_8);
            v18 = (RGBAColor *)((unsigned __int64)(v17 * 255.0) | (((unsigned int)(unsigned __int64)(fabs(cColor_4 - testColor.g) * 255.0) | ((unsigned int)(unsigned __int64)(diffColor * 255.0) << 8)) << 8));
            if ( v18 < i_cColora )
            {
              *o_x = v12;
              i_cColora = v18;
              *o_y = v11;
            }
            v8 = cColor32;
          }
          v10 = nWidth;
          ++v12;
          if ( v12 >= nWidth )
            goto LABEL_13;
        }
        *o_x = v12;
        *o_y = v11;
        bFound = 1;
LABEL_13:
        v9 = nHeight;
      }
    }
    SurfaceWindow::Unlock(v5);
    result = 1;
    if ( !bReturnClosest )
      result = bFound;
  }
  return result;
}

//----- (004419C0) --------------------------------------------------------  // acclient.c:125904
char __cdecl PixelOp<unsigned long>::ConvertPixel(PixelFormatDesc *sourcePFD, const unsigned int source, PixelFormatDesc *destPFD, unsigned int *dest)
{
  PixelFormatDesc *v4; // esi@1
  unsigned int *v6; // eax@5
  const unsigned int v7; // edx@7
  const unsigned int v8; // ebx@7
  const unsigned int v9; // edi@7
  char v10; // cl@7
  char v11; // cl@10
  char v12; // cl@13
  unsigned int v13; // edx@16
  unsigned int v14; // ebx@16
  const unsigned int v15; // edx@19
  char v16; // cl@19
  const unsigned int sourcePFDa; // [sp+Ch] [bp+4h]@7

  v4 = sourcePFD;
  if ( sourcePFD->format == destPFD->format )
  {
    *dest = source;
    return 1;
  }
  if ( destPFD->flags & 4 || sourcePFD->flags & 4 )
    return 0;
  v6 = dest;
  *dest = 0;
  if ( sourcePFD->flags & 1 && destPFD->flags & 1 )
  {
    v7 = (source & sourcePFD->redBitMask) >> sourcePFD->redBitOffset;
    v8 = (source & sourcePFD->greenBitMask) >> sourcePFD->greenBitOffset;
    v9 = (source & sourcePFD->blueBitMask) >> sourcePFD->blueBitOffset;
    v10 = sourcePFD->redBitCount;
    sourcePFDa = (source & sourcePFD->redBitMask) >> sourcePFD->redBitOffset;
    if ( v10 && v10 != destPFD->redBitCount )
    {
      sourcePFDa = v7 * destPFD->redMax / v4->redMax;
      v6 = dest;
      v7 = v7 * destPFD->redMax / v4->redMax;
    }
    v11 = v4->greenBitCount;
    if ( v11 && v11 != destPFD->greenBitCount )
    {
      v7 = sourcePFDa;
      v8 = v8 * destPFD->greenMax / v4->greenMax;
      v6 = dest;
    }
    v12 = v4->blueBitCount;
    if ( v12 && v12 != destPFD->blueBitCount )
    {
      v7 = sourcePFDa;
      v9 = v9 * destPFD->blueMax / v4->blueMax;
      v6 = dest;
    }
    v13 = destPFD->redBitMask & (v7 << destPFD->redBitOffset);
    *v6 = v13;
    v14 = v13 | destPFD->greenBitMask & (v8 << destPFD->greenBitOffset);
    *v6 = v14;
    *v6 = v14 | destPFD->blueBitMask & (v9 << destPFD->blueBitOffset);
  }
  if ( !(destPFD->flags & 2) )
    return 1;
  if ( !(v4->flags & 2) )
  {
    *v6 |= destPFD->alphaBitMask;
    return 1;
  }
  v15 = (source & v4->alphaBitMask) >> v4->alphaBitOffset;
  v16 = v4->alphaBitCount;
  if ( v16 )
  {
    if ( v16 != destPFD->alphaBitCount )
    {
      v15 = v15 * destPFD->alphaMax / v4->alphaMax;
      v6 = dest;
    }
  }
  *v6 |= destPFD->alphaBitMask & (v15 << destPFD->alphaBitOffset);
  return 1;
}

//----- (00441B30) --------------------------------------------------------  // acclient.c:125985
void __thiscall SurfaceWindow::SurfaceWindow(SurfaceWindow *this)
{
  this->vfptr = (SurfaceWindowVtbl *)SurfaceWindow::vftable;
  this->surface = 0;
  this->rect.bottom = 0;
  this->rect.right = 0;
  this->rect.top = 0;
  this->rect.left = 0;
  this->lockCount = 0;
  this->writable = 0;
  this->pitch = 0;
  this->data = 0;
  this->parent = 0;
}
// 798D14: using guessed type int (__thiscall *SurfaceWindow::vftable[2])(void *, char);

//----- (00441B60) --------------------------------------------------------  // acclient.c:126002
void __thiscall SurfaceWindow::SurfaceWindow(SurfaceWindow *this, RenderSurface *_surface, tagRECT *_rect)
{
  this->surface = 0;
  this->rect.bottom = 0;
  this->rect.right = 0;
  this->rect.top = 0;
  this->rect.left = 0;
  this->lockCount = 0;
  this->writable = 0;
  this->pitch = 0;
  this->data = 0;
  this->parent = 0;
  this->vfptr = (SurfaceWindowVtbl *)SurfaceWindow::vftable;
  SurfaceWindow::Attach(this, _surface, _rect);
}
// 798D14: using guessed type int (__thiscall *SurfaceWindow::vftable[2])(void *, char);

//----- (00441BA0) --------------------------------------------------------  // acclient.c:126020
void __thiscall SurfaceWindow::SurfaceWindow(SurfaceWindow *this, RenderSurface *_surface, const unsigned int x0, const unsigned int y0, const unsigned int x1, const unsigned int y1)
{
  tagRECT _rect; // [sp+0h] [bp-10h]@1

  this->surface = 0;
  this->rect.bottom = 0;
  this->rect.right = 0;
  this->rect.top = 0;
  this->rect.left = 0;
  this->lockCount = 0;
  this->writable = 0;
  this->pitch = 0;
  this->data = 0;
  this->parent = 0;
  _rect.left = x0;
  _rect.top = y0;
  _rect.right = x1 + 1;
  _rect.bottom = y1 + 1;
  this->vfptr = (SurfaceWindowVtbl *)SurfaceWindow::vftable;
  SurfaceWindow::Attach(this, _surface, &_rect);
}
// 798D14: using guessed type int (__thiscall *SurfaceWindow::vftable[2])(void *, char);

//----- (00441C10) --------------------------------------------------------  // acclient.c:126044
void __thiscall SurfaceWindow::SurfaceWindow(SurfaceWindow *this, SurfaceWindow *_window, tagRECT *_rect)
{
  this->surface = 0;
  this->rect.bottom = 0;
  this->rect.right = 0;
  this->rect.top = 0;
  this->rect.left = 0;
  this->lockCount = 0;
  this->writable = 0;
  this->pitch = 0;
  this->data = 0;
  this->parent = 0;
  this->vfptr = (SurfaceWindowVtbl *)SurfaceWindow::vftable;
  SurfaceWindow::Attach(this, _window, _rect);
}
// 798D14: using guessed type int (__thiscall *SurfaceWindow::vftable[2])(void *, char);

//----- (00441C50) --------------------------------------------------------  // acclient.c:126062
char __thiscall SurfaceWindow::LegacyBlit(SurfaceWindow *this, SurfaceWindow *source, const unsigned int flags, const float _AlphaBlendOpacity, RGBAColor *_pDyeColor, SurfaceWindow *_pDyeMask)
{
  SurfaceWindow *v6; // ebp@1
  RenderSurface *v7; // ebx@1
  int v8; // eax@1
  int v9; // edx@1
  int v10; // ecx@1
  PixelFormatID v11; // edx@1
  char *v12; // edi@1
  int v13; // ebx@1
  int v14; // ecx@1
  bool v15; // zf@8
  bool v16; // al@19
  PixelFormatID v17; // eax@29
  char *v19; // ecx@37
  char *v20; // eax@37
  char v21; // bl@37
  RenderSurface *v22; // ecx@43
  int v23; // edi@52
  RenderSurface *v24; // ecx@52
  RenderSurface *v25; // eax@54
  int v26; // ecx@54
  int v27; // edx@55
  int v28; // ecx@63
  signed int v29; // esi@63
  int v30; // ebp@64
  char *v31; // ebx@64
  char *v32; // eax@64
  int v33; // edi@64
  signed int v34; // ecx@65
  int v35; // esi@65
  int v36; // eax@67
  const unsigned int *v37; // ecx@69
  char v38; // al@78
  unsigned int v39; // ecx@81
  unsigned int v40; // eax@83
  unsigned int v41; // ebp@83
  unsigned int v42; // edx@85
  int v43; // edx@90
  int v44; // ebx@90
  int v45; // ecx@90
  signed int v46; // ecx@91
  int v47; // esi@91
  int v48; // edi@91
  int v49; // ebx@91
  char *v50; // eax@94
  int v51; // ebp@95
  int v52; // ebp@97
  __int64 v53; // rax@97
  __int64 v54; // rax@97
  __int64 v55; // rax@97
  int v56; // ecx@100
  int v57; // ecx@100
  int v58; // ebx@103
  char *v59; // eax@104
  int v60; // ebp@105
  int v61; // ebp@107
  __int64 v62; // rax@107
  unsigned int v63; // esi@107
  __int64 v64; // rax@107
  unsigned int v65; // edi@107
  __int64 v66; // rax@107
  unsigned int v67; // ebx@107
  int v68; // eax@109
  unsigned int v69; // ecx@109
  int v70; // ecx@109
  int v71; // ecx@117
  int v72; // ebp@118
  char *v73; // edx@119
  char *v74; // ecx@120
  int v75; // esi@120
  int v76; // eax@120
  int v77; // edx@120
  bool bNeedDye; // [sp+13h] [bp-89h]@28
  char bMatchingFormats; // [sp+14h] [bp-88h]@1
  bool bNeedDyeMap; // [sp+15h] [bp-87h]@31
  char srcBytesPP; // [sp+16h] [bp-86h]@37
  bool bNeedAlphaBlendAlpha; // [sp+17h] [bp-85h]@23
  bool bNeedsX2AConversion; // [sp+18h] [bp-84h]@1
  bool bNeedScale; // [sp+19h] [bp-83h]@11
  bool bNeedConvert; // [sp+1Ah] [bp-82h]@14
  bool bNeedAlphaBlend; // [sp+1Bh] [bp-81h]@21
  unsigned int pixelColor; // [sp+1Ch] [bp-80h]@74
  bool bFourCCFormat; // [sp+20h] [bp-7Ch]@8
  char dstBytesPP; // [sp+21h] [bp-7Bh]@37
  char DyeBytesPerPixel; // [sp+22h] [bp-7Ah]@43
  bool bIs8BitDyeMap; // [sp+23h] [bp-79h]@43
  int y; // [sp+24h] [bp-78h]@38
  char *dstData; // [sp+28h] [bp-74h]@37
  int destSizeY; // [sp+2Ch] [bp-70h]@1
  unsigned int DyeRed; // [sp+30h] [bp-6Ch]@38
  char *srcData; // [sp+34h] [bp-68h]@37
  int v97; // [sp+38h] [bp-64h]@65
  int sourceSizeX; // [sp+3Ch] [bp-60h]@1
  unsigned int DyeBlue; // [sp+40h] [bp-5Ch]@38
  unsigned int DyeGreen; // [sp+44h] [bp-58h]@38
  int v101; // [sp+48h] [bp-54h]@65
  int v102; // [sp+4Ch] [bp-50h]@62
  int destSizeX; // [sp+50h] [bp-4Ch]@1
  char *pDyeSourceData; // [sp+54h] [bp-48h]@37
  int sourceSizeY; // [sp+58h] [bp-44h]@1
  unsigned int AlphaBlendOpacityInt; // [sp+5Ch] [bp-40h]@37
  SurfaceWindow *v107; // [sp+60h] [bp-3Ch]@1
  int x; // [sp+64h] [bp-38h]@64
  int srcY; // [sp+68h] [bp-34h]@64
  int srcX; // [sp+6Ch] [bp-30h]@67
  char *pSourceRow; // [sp+70h] [bp-2Ch]@64
  int v112; // [sp+74h] [bp-28h]@65
  int sourceGreen; // [sp+78h] [bp-24h]@90
  int sourceBlue; // [sp+7Ch] [bp-20h]@90
  PixelFormatDesc *srcPFDesc; // [sp+80h] [bp-1Ch]@1
  unsigned int dest32; // [sp+84h] [bp-18h]@83
  int v117; // [sp+88h] [bp-14h]@65
  int v118; // [sp+8Ch] [bp-10h]@65
  int v119; // [sp+90h] [bp-Ch]@65
  PixelFormatDesc *dstPFDesc; // [sp+94h] [bp-8h]@1
  int v121; // [sp+98h] [bp-4h]@63

  v6 = this;
  v7 = this->surface;
  v8 = this->rect.right - this->rect.left;
  destSizeY = this->rect.bottom - this->rect.top;
  v9 = source->rect.top;
  sourceSizeX = source->rect.right - source->rect.left;
  v10 = source->rect.bottom - v9;
  v11 = v7->pfDesc.format;
  v12 = (char *)&source->surface->pfDesc;
  v13 = (int)&v7->pfDesc;
  sourceSizeY = v10;
  v14 = *(_DWORD *)v12;
  bMatchingFormats = *(_DWORD *)v12 == v11;
  v107 = v6;
  srcPFDesc = (PixelFormatDesc *)v12;
  dstPFDesc = (PixelFormatDesc *)v13;
  destSizeX = v8;
  bNeedsX2AConversion = 0;
  if ( v14 == 22 && v11 == 21 || v14 == 21 && *(_DWORD *)v13 == 22 )
  {
    bMatchingFormats = 1;
    if ( *(_DWORD *)v13 == 21 )
      bNeedsX2AConversion = 1;
  }
  if ( v12[4] & 4 || (v15 = (*(_BYTE *)(v13 + 4) & 4) == 0, bFourCCFormat = 0, !v15) )
    bFourCCFormat = 1;
  if ( sourceSizeX != v8 || (bNeedScale = 0, sourceSizeY != destSizeY) )
    bNeedScale = 1;
  if ( !(flags & 4) || (bNeedConvert = 1, bMatchingFormats) )
    bNeedConvert = 0;
  v16 = flags & 0x10 && v14 == 21 && bMatchingFormats;
  bNeedAlphaBlend = v16;
  if ( (flags & 0x50) != 80 || !v16 || (bNeedAlphaBlendAlpha = 1, *(_DWORD *)v13 != 21) )
    bNeedAlphaBlendAlpha = 0;
  if ( !(flags & 0x20) || !bMatchingFormats || !_pDyeColor )
  {
    bNeedDye = 0;
LABEL_33:
    bNeedDyeMap = 0;
    goto LABEL_34;
  }
  bNeedDye = 1;
  if ( !_pDyeMask )
    goto LABEL_33;
  v17 = _pDyeMask->surface->pfDesc.format;
  if ( v17 != 21 && v17 != 28 )
    goto LABEL_33;
  bNeedDyeMap = 1;
LABEL_34:
  if ( !SurfaceWindow::Lock(source, 1) )
    return 0;
  if ( !SurfaceWindow::Lock(v6, 0) )
  {
    SurfaceWindow::Unlock(source);
    return 0;
  }
  v19 = (char *)v6->data;
  srcBytesPP = (unsigned __int8)v12[12] >> 3;
  v20 = (char *)source->data;
  v21 = *(_BYTE *)(v13 + 12) >> 3;
  dstBytesPP = v21;
  srcData = v20;
  dstData = v19;
  AlphaBlendOpacityInt = (unsigned __int64)(_AlphaBlendOpacity * 256.0);
  pDyeSourceData = 0;
  if ( bNeedDye )
  {
    y = RGBAColor::GetColor32(_pDyeColor);
    DyeRed = ((unsigned __int8)((unsigned int)y >> 16) != 0) + (unsigned __int8)((unsigned int)y >> 16);
    DyeGreen = (BYTE1(y) != 0) + BYTE1(y);
    DyeBlue = ((unsigned __int8)y != 0) + (unsigned __int8)y;
  }
  if ( bNeedDyeMap )
  {
    if ( !SurfaceWindow::Lock(_pDyeMask, 1) )
    {
      SurfaceWindow::Unlock(source);
      SurfaceWindow::Unlock(v6);
      return 0;
    }
    v22 = _pDyeMask->surface;
    pDyeSourceData = (char *)_pDyeMask->data;
    DyeBytesPerPixel = (unsigned __int8)v22->pfDesc.bitsPerPixel >> 3;
    bIs8BitDyeMap = v22->pfDesc.format == 28;
  }
  if ( bFourCCFormat )
  {
    qmemcpy(dstData, srcData, v6->surface->size);
    goto LABEL_124;
  }
  if ( bMatchingFormats )
  {
    if ( !bNeedsX2AConversion && !bNeedScale && !bNeedConvert && !bNeedAlphaBlend && !bNeedDye )
    {
      v23 = v6->rect.right - v6->rect.left;
      v24 = v6->surface;
      if ( v23 == v24->width && v6->rect.bottom - v6->rect.top == v24->height )
      {
        v25 = source->surface;
        v26 = v24->size;
        v15 = v26 == v25->size;
        y = v26;
        if ( v15 )
        {
          v27 = source->rect.right - source->rect.left;
          if ( v27 == v25->width
            && source->rect.bottom - source->rect.top == v25->height
            && v6->pitch == v23 * (unsigned __int8)v21
            && source->pitch == v27 * (unsigned __int8)srcBytesPP )
          {
            qmemcpy(dstData, srcData, y);
            goto LABEL_124;
          }
        }
      }
    }
  }
  if ( (unsigned __int8)srcBytesPP < 3u || (unsigned __int8)v21 < 3u )
  {
    v71 = destSizeY - 1;
    y = destSizeY - 1;
    if ( destSizeY - 1 >= 0 )
    {
      v72 = destSizeX - 1;
      do
      {
        v73 = &srcData[v71 * source->pitch];
        if ( v72 >= 0 )
        {
          v74 = &dstData[v71 * v107->pitch] + (unsigned __int8)dstBytesPP * v72;
          v101 = (unsigned __int8)srcBytesPP;
          v75 = -(unsigned __int8)dstBytesPP;
          v76 = (int)&v73[(unsigned __int8)srcBytesPP * v72];
          v77 = v72 + 1;
          do
          {
            *v74 = *(_BYTE *)v76;
            v76 -= (unsigned __int8)srcBytesPP;
            v74 += v75;
            --v77;
          }
          while ( v77 );
          v71 = y;
        }
        --v71;
        y = v71;
      }
      while ( v71 >= 0 );
    }
    goto LABEL_124;
  }
  v102 = destSizeY - 1;
  if ( destSizeY - 1 < 0 )
    goto LABEL_124;
  v28 = destSizeY - 1;
  v29 = sourceSizeY * (destSizeY - 1);
  y = sourceSizeY * (destSizeY - 1);
  v121 = -sourceSizeY;
  do
  {
    v30 = v29 / destSizeY;
    v31 = &srcData[v29 / destSizeY * source->pitch];
    v32 = &dstData[v28 * v107->pitch];
    v33 = destSizeX - 1;
    srcY = v29 / destSizeY;
    pSourceRow = v31;
    x = destSizeX - 1;
    if ( destSizeX - 1 < 0 )
      goto LABEL_115;
    v119 = -(unsigned __int8)dstBytesPP;
    v117 = -sourceSizeX;
    v101 = (unsigned __int8)srcBytesPP;
    v34 = sourceSizeX * v33;
    v35 = (int)&v32[(unsigned __int8)dstBytesPP * v33];
    v112 = sourceSizeX * v33;
    v118 = (unsigned __int8)dstBytesPP;
    v97 = (int)&v32[(unsigned __int8)dstBytesPP * v33];
    while ( 1 )
    {
      v36 = v33;
      srcX = v33;
      if ( bNeedScale )
      {
        v36 = v34 / destSizeX;
        srcX = v34 / destSizeX;
      }
      v37 = (const unsigned int *)&v31[v101 * v36];
      if ( v36 >= 0 && v36 < sourceSizeX || v30 >= 0 && v30 < sourceSizeY )
      {
        if ( bNeedConvert )
        {
          PixelOp<unsigned long>::ConvertPixel(srcPFDesc, *v37, dstPFDesc, &pixelColor);
          switch ( v118 )
          {
            case 2:
              *(_WORD *)v35 = pixelColor;
              break;
            case 3:
              v38 = BYTE2(pixelColor);
              *(_WORD *)v35 = pixelColor;
              *(_BYTE *)(v35 + 2) = v38;
              break;
            case 4:
              *(_DWORD *)v35 = pixelColor;
              break;
          }
        }
        else if ( bNeedAlphaBlend )
        {
          v39 = *v37;
          pixelColor = v39;
          if ( v39 >> 24 && AlphaBlendOpacityInt )
          {
            v40 = *(_DWORD *)v35;
            v41 = (v39 >> 24) + 1;
            dest32 = *(_DWORD *)v35;
            if ( bNeedDye || v41 != 256 )
            {
              v42 = AlphaBlendOpacityInt;
              if ( AlphaBlendOpacityInt != 256 )
                goto LABEL_89;
            }
            else
            {
              v42 = AlphaBlendOpacityInt;
              if ( AlphaBlendOpacityInt == 256 )
              {
                if ( !bNeedAlphaBlendAlpha )
                {
                  pixelColor = v40 ^ (v39 ^ v40) & 0xFFFFFF;
                  *(_DWORD *)v35 = pixelColor;
                  goto LABEL_113;
                }
                goto LABEL_101;
              }
LABEL_89:
              v41 = v42 * v41 >> 8;
            }
            v43 = BYTE1(v39);
            sourceBlue = (unsigned __int8)v39;
            v44 = (unsigned __int8)v40;
            v45 = v40 >> 24;
            sourceGreen = v43;
            if ( bNeedAlphaBlendAlpha )
            {
              v46 = v41 - (signed int)(v41 * ((v45 != 0) + v45)) / 256 + (v45 != 0) + v45;
              v47 = BYTE2(dest32) - (signed int)(v41 * (BYTE2(dest32) - BYTE2(pixelColor))) / v46;
              v48 = BYTE1(v40) - (signed int)(v41 * (BYTE1(v40) - sourceGreen)) / v46;
              v49 = v44 - (signed int)(v41 * (v44 - sourceBlue)) / v46;
              v45 = v46 - (v46 != 0);
            }
            else
            {
              v47 = (signed int)(v41 * (BYTE2(dest32) - BYTE2(pixelColor))) / -256 + BYTE2(dest32);
              v48 = (signed int)(v41 * (BYTE1(v40) - sourceGreen)) / -256 + BYTE1(v40);
              v49 = (signed int)(v41 * (v44 - sourceBlue)) / -256 + v44;
            }
            if ( bNeedDyeMap )
            {
              v50 = &pDyeSourceData[srcX * (unsigned __int8)DyeBytesPerPixel] + srcY * _pDyeMask->pitch;
              if ( bIs8BitDyeMap )
                v51 = (unsigned __int8)*v50;
              else
                v51 = (unsigned __int8)v50[3];
              v52 = (v51 != 0) + v51;
              v53 = (signed int)(v52 * (v47 - (DyeRed * v47 >> 8)));
              v47 -= (BYTE4(v53) + (signed int)v53) >> 8;
              v54 = (signed int)(v52 * (v48 - (DyeGreen * v48 >> 8)));
              v48 -= (BYTE4(v54) + (signed int)v54) >> 8;
              v55 = (signed int)(v52 * (v49 - (DyeBlue * v49 >> 8)));
              v49 -= (BYTE4(v55) + (signed int)v55) >> 8;
            }
            else if ( bNeedDye )
            {
              v47 = DyeRed * v47 >> 8;
              v48 = DyeGreen * v48 >> 8;
              v49 = DyeBlue * v49 >> 8;
            }
            v56 = v47 | (v45 << 8);
            v35 = v97;
            v57 = v48 | (v56 << 8);
            v33 = x;
            v39 = v49 | (v57 << 8);
            v31 = pSourceRow;
            pixelColor = v39;
LABEL_101:
            *(_DWORD *)v35 = v39;
            goto LABEL_113;
          }
        }
        else if ( bNeedDye )
        {
          pixelColor = *v37;
          v58 = (unsigned __int8)pixelColor;
          if ( bNeedDyeMap )
          {
            v59 = &pDyeSourceData[v36 * (unsigned __int8)DyeBytesPerPixel] + srcY * _pDyeMask->pitch;
            if ( bIs8BitDyeMap )
              v60 = (unsigned __int8)*v59;
            else
              v60 = (unsigned __int8)v59[3];
            v61 = (v60 != 0) + v60;
            v62 = (signed int)(v61 * (BYTE2(pixelColor) - (DyeRed * BYTE2(pixelColor) >> 8)));
            v63 = BYTE2(pixelColor) - ((BYTE4(v62) + (signed int)v62) >> 8);
            v64 = (signed int)(v61 * (BYTE1(pixelColor) - (DyeGreen * BYTE1(pixelColor) >> 8)));
            v65 = BYTE1(pixelColor) - ((BYTE4(v64) + (signed int)v64) >> 8);
            v66 = (signed int)(v61 * (v58 - (DyeBlue * v58 >> 8)));
            v67 = v58 - ((BYTE4(v66) + (signed int)v66) >> 8);
          }
          else
          {
            v63 = DyeRed * BYTE2(pixelColor) >> 8;
            v65 = DyeGreen * BYTE1(pixelColor) >> 8;
            v67 = DyeBlue * v58 >> 8;
          }
          v68 = v97;
          v69 = v65 | ((v63 | (pixelColor >> 24 << 8)) << 8);
          v33 = x;
          v70 = v67 | (v69 << 8);
          v31 = pSourceRow;
          pixelColor = v70;
          *(_DWORD *)v97 = v70;
          v35 = v68;
        }
        else if ( bNeedsX2AConversion )
        {
          *(_DWORD *)v35 = *v37 | 0xFF000000;
        }
        else
        {
          *(_DWORD *)v35 = *v37;
        }
      }
LABEL_113:
      --v33;
      v34 = v117 + v112;
      v35 += v119;
      x = v33;
      v112 += v117;
      v97 = v35;
      if ( v33 < 0 )
        break;
      v30 = srcY;
    }
    v28 = v102;
    v29 = y;
LABEL_115:
    --v28;
    v29 += v121;
    v102 = v28;
    y = v29;
  }
  while ( v28 >= 0 );
LABEL_124:
  SurfaceWindow::Unlock(v107);
  SurfaceWindow::Unlock(source);
  if ( bNeedDyeMap )
    SurfaceWindow::Unlock(_pDyeMask);
  return 1;
}

//----- (004425E0) --------------------------------------------------------  // acclient.c:126542
char __thiscall SurfaceWindow::NotColorBits(SurfaceWindow *this, const int x0, const int y0, const int x1, const int y1)
{
  SurfaceWindow *v5; // edi@1
  void *v6; // eax@1
  int v7; // edx@3
  int *v8; // eax@3
  const int *v9; // eax@5
  const int v10; // ebp@7
  const int *v11; // eax@7
  int v12; // ebx@9
  RenderSurface *v13; // eax@9
  int v14; // esi@9
  bool v15; // zf@9
  char result; // al@11
  unsigned __int8 v17; // al@12
  int v18; // ecx@12
  int v19; // ebx@13
  const int v20; // edx@13
  int v21; // eax@14
  int v22; // edx@15
  int realx1; // [sp+10h] [bp-8h]@1
  int realy1; // [sp+14h] [bp-4h]@9

  v5 = this;
  realx1 = 0;
  v6 = &realx1;
  if ( x0 >= 0 )
    v6 = (void *)&x0;
  v7 = this->rect.right;
  x0 = *(_DWORD *)v6;
  v8 = &this->rect.right;
  if ( v7 >= x1 )
    v8 = (int *)&x1;
  realx1 = *v8;
  x1 = 0;
  v9 = &x1;
  if ( y0 >= 0 )
    v9 = &y0;
  v10 = *v9;
  v11 = &this->rect.bottom;
  if ( this->rect.bottom >= y1 )
    v11 = &y1;
  v12 = *v11;
  v13 = this->surface;
  v14 = v13->pfDesc.redBitMask | v13->pfDesc.greenBitMask | v13->pfDesc.blueBitMask;
  y0 = v13->pfDesc.alphaBitMask;
  v15 = (v13->pfDesc.flags & 4) == 0;
  realy1 = v12;
  if ( v15 && SurfaceWindow::Lock(this, 0) )
  {
    v17 = (unsigned __int8)v5->surface->pfDesc.bitsPerPixel >> 3;
    v18 = v10;
    x1 = v10;
    if ( v10 < v12 )
    {
      v19 = v17;
      v20 = x0 * v17;
      y1 = x0 * v17;
      do
      {
        v21 = (int)((char *)v5->data + v18 * v5->pitch + v20);
        if ( x0 < realx1 )
        {
          v22 = realx1 - x0;
          do
          {
            *(_DWORD *)v21 = y0 & *(_DWORD *)v21 | v14 & ~*(_DWORD *)v21;
            v21 += v19;
            --v22;
          }
          while ( v22 );
          v18 = x1;
          v20 = y1;
        }
        ++v18;
        x1 = v18;
      }
      while ( v18 < realy1 );
    }
    SurfaceWindow::Unlock(v5);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00442750) --------------------------------------------------------  // acclient.c:126649
char __thiscall SurfaceWindow::BlitAndColor(SurfaceWindow *this, SurfaceWindow *i_pswSource, BlitMode i_eBlitMode, float i_fBlitModeMultiplier, SurfaceWindow *i_pswAlpha, BlitMode i_eColorMode, const unsigned int i_dwARGB)
{
  SurfaceWindow *v7; // esi@1
  SurfaceWindow *v8; // edi@1
  RenderSurface *v10; // eax@4
  int v11; // eax@5
  int v12; // eax@6
  BlitDataFormat v13; // eax@8
  unsigned int v14; // ecx@12
  char *v15; // edx@12
  RenderSurface *v16; // eax@15
  int v17; // eax@16
  int v18; // eax@17
  unsigned int v19; // ecx@23
  int v20; // ebp@23
  int v21; // ebx@23
  char *v22; // edx@23
  int v23; // eax@23
  int v24; // ebp@23
  int v25; // ebx@23
  int v26; // edx@23
  const unsigned int v27; // ebx@29
  char v28; // bl@35
  RenderSurface *v29; // eax@47
  PixelFormatID v30; // eax@48
  BlitDataFormat v31; // eax@50
  int v32; // ecx@53
  int v33; // ebx@53
  int v34; // edx@56
  SurfaceWindowLocker cSrcLock; // [sp+8h] [bp-5Ch]@1
  RGBAColor rgba; // [sp+10h] [bp-54h]@1
  ColorArgs cColorArgs; // [sp+20h] [bp-44h]@39
  BlitArgs cBlitArgs; // [sp+3Ch] [bp-28h]@12
  BlitDataFormat i_pswSourcea; // [sp+68h] [bp+4h]@19

  v7 = i_pswSource;
  v8 = this;
  cSrcLock.m_pSurface = i_pswSource;
  cSrcLock.m_bLocked = 0;
  LODWORD(rgba.r) = i_pswAlpha;
  LOBYTE(rgba.g) = 0;
  if ( !this || !SurfaceWindow::Lock(this, 0) )
    return 0;
  v10 = v8->surface;
  if ( !v10 )
    goto LABEL_67;
  v11 = v10->pfDesc.format - 20;
  if ( !v11 )
  {
    v13 = 2;
    goto LABEL_12;
  }
  v12 = v11 - 1;
  if ( !v12 )
  {
    v13 = 0;
    goto LABEL_12;
  }
  if ( v12 != 1 )
  {
LABEL_67:
    v13 = -1;
    goto LABEL_12;
  }
  v13 = 1;
LABEL_12:
  v14 = v8->pitch;
  v15 = (char *)v8->data;
  cBlitArgs.cDstArgs.eBlitFormat = v13;
  cBlitArgs.cDstArgs.iStride = v14;
  cBlitArgs.cDstArgs.pDstBuf = v15;
  cBlitArgs.eMode = 7;
  if ( !i_pswSource || i_eBlitMode == 7 || !SurfaceWindowLocker::Lock(&cSrcLock, 1) )
  {
    v25 = cBlitArgs.nHeight;
    v24 = cBlitArgs.nWidth;
    goto LABEL_39;
  }
  v16 = i_pswSource->surface;
  cBlitArgs.eMode = i_eBlitMode;
  if ( v16 )
  {
    v17 = v16->pfDesc.format - 20;
    if ( !v17 )
    {
      i_pswSourcea = 2;
      goto LABEL_23;
    }
    v18 = v17 - 1;
    if ( !v18 )
    {
      i_pswSourcea = 0;
      goto LABEL_23;
    }
    if ( v18 == 1 )
    {
      i_pswSourcea = 1;
      goto LABEL_23;
    }
  }
  i_pswSourcea = -1;
LABEL_23:
  v19 = v7->pitch;
  v20 = v7->rect.right;
  v21 = v7->rect.bottom;
  v22 = (char *)v7->data;
  cBlitArgs.cSrcArgs.eBlitFormat = i_pswSourcea;
  v23 = v7->rect.top;
  cBlitArgs.cSrcArgs.iStride = v19;
  v24 = v20 - v7->rect.left;
  v25 = v21 - v23;
  cBlitArgs.cSrcArgs.pDstBuf = v22;
  cBlitArgs.nWidth = v24;
  cBlitArgs.nHeight = v25;
  v26 = v8->rect.left;
  cBlitArgs.i8AlphaModifier = (unsigned __int64)(i_fBlitModeMultiplier * 255.0);
  if ( v24 > (unsigned int)(v8->rect.right - v26) )
  {
    v24 = v8->rect.right - v26;
    cBlitArgs.nWidth = v8->rect.right - v26;
  }
  if ( v25 > (unsigned int)(v8->rect.bottom - v8->rect.top) )
  {
    v25 = v8->rect.bottom - v8->rect.top;
    cBlitArgs.nHeight = v8->rect.bottom - v8->rect.top;
  }
  if ( cBlitArgs.cDstArgs.eBlitFormat == -1 || i_pswSourcea == -1 )
  {
    v27 = 4;
    if ( i_eBlitMode == 1 )
    {
      v27 = 20;
    }
    else if ( i_eBlitMode == 2 )
    {
      v27 = 84;
    }
    if ( i_eColorMode != 7 )
      v27 |= 0x20u;
    RGBAColor::SetColor32(&rgba, i_dwARGB);
    v28 = SurfaceWindow::LegacyBlit(v8, v7, v27, i_fBlitModeMultiplier, &rgba, i_pswAlpha);
    if ( cSrcLock.m_bLocked )
      SurfaceWindow::Unlock(cSrcLock.m_pSurface);
    SurfaceWindow::Unlock(v8);
    return v28;
  }
LABEL_39:
  cColorArgs.eMode = i_eColorMode;
  if ( i_eColorMode != 7 )
  {
    if ( !i_pswAlpha )
    {
      cColorArgs.cMaskArgs.eBlitFormat = 0;
      cColorArgs.nWidth = v24;
      cColorArgs.nHeight = v25;
LABEL_56:
      v34 = v8->rect.left;
      cColorArgs.dwARGB = i_dwARGB;
      if ( v24 > (unsigned int)(v8->rect.right - v34) )
        cColorArgs.nWidth = v8->rect.right - v34;
      if ( v25 > (unsigned int)(v8->rect.bottom - v8->rect.top) )
        cColorArgs.nHeight = v8->rect.bottom - v8->rect.top;
      goto LABEL_60;
    }
    if ( !SurfaceWindowLocker::Lock((SurfaceWindowLocker *)&rgba, 1) )
    {
LABEL_42:
      if ( LOBYTE(rgba.g) )
        SurfaceWindow::Unlock((SurfaceWindow *)rgba.r);
      if ( cSrcLock.m_bLocked )
        SurfaceWindow::Unlock(cSrcLock.m_pSurface);
      SurfaceWindow::Unlock(v8);
      return 0;
    }
    v29 = i_pswAlpha->surface;
    if ( v29 )
    {
      v30 = v29->pfDesc.format;
      if ( v30 == 21 )
      {
        v31 = 2;
        goto LABEL_53;
      }
      if ( v30 == 28 )
      {
        v31 = 1;
        goto LABEL_53;
      }
    }
    v31 = -1;
LABEL_53:
    v32 = i_pswAlpha->pitch;
    v24 = i_pswAlpha->rect.right - i_pswAlpha->rect.left;
    v33 = i_pswAlpha->rect.bottom;
    cColorArgs.cMaskArgs.pDstBuf = (char *)i_pswAlpha->data;
    v25 = v33 - i_pswAlpha->rect.top;
    cColorArgs.cMaskArgs.eBlitFormat = v31;
    cColorArgs.cMaskArgs.iStride = v32;
    cColorArgs.nWidth = v24;
    cColorArgs.nHeight = v25;
    if ( v31 == -1 )
      goto LABEL_42;
    goto LABEL_56;
  }
LABEL_60:
  SoftwareBlitAndColor(&cBlitArgs, &cColorArgs);
  if ( LOBYTE(rgba.g) )
    SurfaceWindow::Unlock((SurfaceWindow *)rgba.r);
  if ( cSrcLock.m_bLocked )
    SurfaceWindow::Unlock(cSrcLock.m_pSurface);
  SurfaceWindow::Unlock(v8);
  return 1;
}

//----- (00442A80) --------------------------------------------------------  // acclient.c:126864
char __thiscall SmartArray<unsigned char,0>::grow(SmartArray<unsigned char,0> *this, unsigned int i_nSize)
{
  SmartArray<unsigned char,0> *v2; // esi@1
  void *v4; // ebx@5
  int i; // eax@7

  v2 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<unsigned char,0>::Reset((SmartArray<_D3DXATTRIBUTERANGE,0> *)this);
      return 1;
    }
    v4 = operator new[](i_nSize);
    if ( v4 )
    {
      if ( v2->m_data )
      {
        for ( i = v2->m_num - 1; i >= 0; *((_BYTE *)v4 + i + 1) = v2->m_data[i + 1] )
          --i;
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = (char *)v4;
      v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (00442B10) --------------------------------------------------------  // acclient.c:126899
char __thiscall SurfaceWindow::Blit(SurfaceWindow *this, SurfaceWindow *i_swSource, BlitMode i_eBlitMode, float i_fBlitModeMultiplier)
{
  return SurfaceWindow::BlitAndColor(this, i_swSource, i_eBlitMode, i_fBlitModeMultiplier, 0, Blit_NOP, 0xFF000000);
}

//----- (00442B30) --------------------------------------------------------  // acclient.c:126905
char __thiscall SurfaceWindow::Color(SurfaceWindow *this, SurfaceWindow *i_pswAlpha, BlitMode i_eColorMode, RGBAColor *i_rgbaColor)
{
  return SurfaceWindow::BlitAndColor(
           this,
           0,
           Blit_NOP,
           1.0,
           i_pswAlpha,
           i_eColorMode,
           (unsigned __int64)(i_rgbaColor->b * 255.0) | (((unsigned int)(unsigned __int64)(i_rgbaColor->g * 255.0) | (((unsigned int)(unsigned __int64)(i_rgbaColor->r * 255.0) | ((unsigned int)(unsigned __int64)(i_rgbaColor->a * 255.0) << 8)) << 8)) << 8));
}

//----- (00442BB0) --------------------------------------------------------  // acclient.c:126918
char __thiscall SurfaceWindow::Color(SurfaceWindow *this, SurfaceWindow *i_pswAlpha, BlitMode i_eColorMode, unsigned int i_dwARGB)
{
  return SurfaceWindow::BlitAndColor(this, 0, Blit_NOP, 1.0, i_pswAlpha, i_eColorMode, i_dwARGB);
}

//----- (00442BD0) --------------------------------------------------------  // acclient.c:126924
unsigned int __thiscall SurfaceWindow::DrawCharacter(SurfaceWindow *this, const int x, const int y, Font *font, const unsigned __int16 ch, unsigned int pfColor, const unsigned int flags, unsigned int pfBkColor)
{
  SurfaceWindow *v8; // ebp@1
  int v9; // eax@3
  int v10; // edx@4
  int v11; // ebx@9
  int v12; // esi@11
  int v13; // edi@11
  RenderSurface *v14; // eax@22
  unsigned int result; // eax@24
  char DrawToAlphaChannelOnly; // [sp+13h] [bp-B1h]@11
  unsigned int HOffsetDist; // [sp+14h] [bp-B0h]@5
  int ActualX; // [sp+18h] [bp-ACh]@9
  int charHeight; // [sp+1Ch] [bp-A8h]@4
  int ws; // [sp+20h] [bp-A4h]@4
  int xs; // [sp+24h] [bp-A0h]@11
  int ys; // [sp+28h] [bp-9Ch]@11
  tagRECT rectDst; // [sp+2Ch] [bp-98h]@11
  SurfaceWindow swSource; // [sp+3Ch] [bp-88h]@15
  SurfaceWindow swDest; // [sp+68h] [bp-5Ch]@15
  tagRECT rectBkDst; // [sp+94h] [bp-30h]@15
  tagRECT rectBkSrc; // [sp+A4h] [bp-20h]@15
  tagRECT rectSrc; // [sp+B4h] [bp-10h]@11

  v8 = this;
  if ( font && this->lockCount && (v9 = Font::GetCharDesc(font, ch)) != 0 )
  {
    charHeight = *(_BYTE *)(v9 + 7);
    v10 = 0;
    ws = *(_BYTE *)(v9 + 6);
    if ( flags & 1 )
    {
      HOffsetDist = font->maxCharWidth + 1;
    }
    else if ( BYTE1(flags) & 0x10 )
    {
      HOffsetDist = *(_BYTE *)(v9 + 6) + *(_BYTE *)(v9 + 8) + *(_BYTE *)(v9 + 9);
      v10 = *(_BYTE *)(v9 + 8);
    }
    else
    {
      HOffsetDist = *(_BYTE *)(v9 + 6);
    }
    v11 = y + *(_BYTE *)(v9 + 10);
    ActualX = x + v10;
    if ( flags & 2 )
      v11 -= font->m_BaselineOffset;
    v12 = v8->rect.right - v8->rect.left;
    DrawToAlphaChannelOnly = BYTE1(flags) & 1;
    v13 = v8->rect.bottom - v8->rect.top;
    ys = *(_WORD *)(v9 + 4);
    xs = *(_WORD *)(v9 + 2);
    CreateCharRectPair(0, ys, v11, xs, ys, ws, charHeight, ActualX, v12, v13, 0, &rectSrc, &rectDst);
    if ( rectDst.left < rectDst.right && rectDst.top < rectDst.bottom )
    {
      if ( font->m_pBackgroundSurface && BYTE1(flags) & 0x40 )
      {
        CreateCharRectPair(
          font->m_NumHorizontalBorderPixels,
          (int)font,
          v11,
          xs,
          ys,
          ws,
          charHeight,
          ActualX,
          v12,
          v13,
          font->m_NumVerticalBorderPixels,
          &rectBkSrc,
          &rectBkDst);
        SurfaceWindow::SurfaceWindow(&swSource, &font->m_pBackgroundSurface->window, &rectBkSrc);
        SurfaceWindow::SurfaceWindow(&swDest, v8, &rectBkDst);
        if ( DrawToAlphaChannelOnly )
        {
          SurfaceWindow::CopyAlpha(&swDest, &swSource);
        }
        else if ( swSource.surface->pfDesc.format == 28 || SBYTE1(flags) < 0 )
        {
          SurfaceWindow::Color(&swDest, &swSource, Blit_4Alpha, pfBkColor);
        }
        else
        {
          SurfaceWindow::BlitAndColor(&swDest, &swSource, Blit_4Alpha, 1.0, 0, Blit_NOP, 0xFF000000);
        }
      }
      if ( !(BYTE1(flags) & 0x20) )
      {
        v14 = font->m_pForegroundSurface;
        if ( v14 )
        {
          SurfaceWindow::SurfaceWindow(&swSource, &v14->window, &rectSrc);
          SurfaceWindow::SurfaceWindow(&swDest, v8, &rectDst);
          if ( DrawToAlphaChannelOnly )
          {
            SurfaceWindow::CopyAlpha(&swDest, &swSource);
            return HOffsetDist;
          }
          if ( swSource.surface->pfDesc.format != 28 && SBYTE1(flags) >= 0 )
          {
            SurfaceWindow::BlitAndColor(&swDest, &swSource, Blit_4Alpha, 1.0, 0, Blit_NOP, 0xFF000000);
            return HOffsetDist;
          }
          SurfaceWindow::Color(&swDest, &swSource, Blit_4Alpha, pfColor);
        }
      }
    }
    result = HOffsetDist;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00442EE0) --------------------------------------------------------  // acclient.c:127041
char __thiscall SurfaceWindow::Fill(SurfaceWindow *this, RGBAColor *color)
{
  SurfaceWindow *v2; // ebp@1
  RenderSurface *v3; // ebx@1
  char v4; // al@1
  int v5; // ebx@1
  int v7; // edi@5
  unsigned int v8; // eax@5
  int v9; // esi@5
  unsigned int v10; // ebx@5
  unsigned int v11; // edx@5
  char v12; // al@9
  char *v13; // eax@11
  int v14; // esi@11
  int v15; // ecx@12
  void *v16; // eax@14
  int v17; // edi@14
  void *v18; // ebx@18
  int v19; // edi@18
  int v20; // esi@19
  int v21; // edi@19
  void *v22; // eax@20
  int v23; // ecx@21
  unsigned int BytesPP; // [sp+8h] [bp-4h]@5
  RGBAColor *colora; // [sp+10h] [bp+4h]@5
  RGBAColor *colorb; // [sp+10h] [bp+4h]@15

  v2 = this;
  v3 = this->surface;
  v4 = LOBYTE(v3->pfDesc.flags);
  v5 = (int)&v3->pfDesc;
  if ( v4 & 4 || *(_BYTE *)(v5 + 12) != 32 || !SurfaceWindow::Lock(this, 0) )
    return 0;
  v7 = v2->rect.bottom - v2->rect.top;
  v8 = *(_BYTE *)(v5 + 12);
  v9 = v2->rect.right - v2->rect.left;
  v10 = v9 * v8 >> 3;
  BytesPP = v8 >> 3;
  v11 = RGBAColor::GetColor32(color);
  colora = (RGBAColor *)v11;
  if ( (unsigned int)v9 <= 0x100 )
  {
    v18 = v2->data;
    v19 = v7 - 1;
    if ( v19 >= 0 )
    {
      v20 = v9 - 1;
      v21 = v19 + 1;
      do
      {
        v22 = v18;
        if ( v20 >= 0 )
        {
          v23 = v20 + 1;
          do
          {
            *(_DWORD *)v22 = v11;
            v22 = (char *)v22 + BytesPP;
            --v23;
          }
          while ( v23 );
        }
        v18 = (char *)v18 + v2->pitch;
        --v21;
      }
      while ( v21 );
    }
    goto LABEL_24;
  }
  if ( !(dword_837E14 & 1) )
  {
    dword_837E14 |= 1u;
    refRow.m_data = 0;
    refRow.m_sizeAndDeallocate = 0;
    refRow.m_num = 0;
    atexit(sub_72A7C0);
    v11 = (unsigned int)colora;
  }
  if ( (refRow.m_sizeAndDeallocate & 0x7FFFFFFF) >= v10
    || (v12 = SmartArray<unsigned char,0>::grow((SmartArray<unsigned char,0> *)&refRow.m_data, v10),
        v11 = (unsigned int)colora,
        v12) )
    refRow.m_num = v10;
  v13 = refRow.m_data;
  v14 = v9 - 1;
  if ( v14 >= 0 )
  {
    v15 = v14 + 1;
    do
    {
      *(_DWORD *)v13 = v11;
      v13 += BytesPP;
      --v15;
    }
    while ( v15 );
  }
  v16 = v2->data;
  v17 = v7 - 1;
  if ( v17 < 0 )
  {
LABEL_24:
    SurfaceWindow::Unlock(v2);
    return 1;
  }
  colorb = (RGBAColor *)(v17 + 1);
  do
  {
    qmemcpy(v16, refRow.m_data, v10);
    v16 = (char *)v16 + v2->pitch;
    colorb = (RGBAColor *)((char *)colorb - 1);
  }
  while ( colorb );
  SurfaceWindow::Unlock(v2);
  return 1;
}

//----- (00443050) --------------------------------------------------------  // acclient.c:127158
char __thiscall SurfaceWindow::FillArea(SurfaceWindow *this, RGBAColor *color, tagRECT *area)
{
  SurfaceWindow *v3; // esi@1
  int v4; // ecx@1
  int v5; // edi@1
  int v6; // edx@1
  int v7; // edi@1
  int v8; // eax@1
  RenderSurface *v9; // ST00_4@1
  tagRECT _rect; // [sp+8h] [bp-3Ch]@1
  SurfaceWindow targetWindow; // [sp+18h] [bp-2Ch]@1

  v3 = this;
  v4 = this->rect.left;
  targetWindow.surface = 0;
  targetWindow.rect.bottom = 0;
  targetWindow.rect.right = 0;
  targetWindow.rect.top = 0;
  targetWindow.rect.left = 0;
  targetWindow.lockCount = 0;
  targetWindow.writable = 0;
  targetWindow.pitch = 0;
  targetWindow.data = 0;
  targetWindow.parent = 0;
  v5 = area->top;
  _rect.left = v4 + area->left;
  v6 = v3->rect.top;
  _rect.top = v6 + v5;
  v7 = v4 + area->right;
  v8 = v6 + area->bottom;
  v9 = v3->surface;
  targetWindow.vfptr = (SurfaceWindowVtbl *)SurfaceWindow::vftable;
  _rect.right = v7;
  _rect.bottom = v8;
  SurfaceWindow::Attach(&targetWindow, v9, &_rect);
  targetWindow.parent = v3;
  return SurfaceWindow::Fill(&targetWindow, color);
}
// 798D14: using guessed type int (__thiscall *SurfaceWindow::vftable[2])(void *, char);

//----- (004430F0) --------------------------------------------------------  // acclient.c:127199
char __thiscall SurfaceWindow::FillArea(SurfaceWindow *this, RGBAColor *color, const int x0, const int y0, const int x1, const int y1)
{
  tagRECT r; // [sp+0h] [bp-10h]@1

  r.left = x0;
  r.top = y0;
  r.right = x1 + 1;
  r.bottom = y1 + 1;
  return SurfaceWindow::FillArea(this, color, &r);
}

//----- (00443130) --------------------------------------------------------  // acclient.c:127211
char __thiscall SurfaceWindow::Blit(SurfaceWindow *this, SurfaceWindow *i_swSource)
{
  SurfaceWindow *v2; // ebp@1
  SurfaceWindow *v3; // ebx@3
  RenderSurface *v4; // esi@5
  RenderSurface *v5; // eax@5
  bool v6; // cl@8
  int v7; // edx@14
  int v8; // ecx@15
  PixelFormatID v10; // edx@19
  char v11; // al@21
  SurfaceWindow *v12; // eax@24
  int v13; // ecx@24
  int v14; // edx@24
  int v15; // esi@24
  bool v16; // cf@24
  SurfaceWindow **v17; // ecx@24
  int *v18; // eax@26
  int v19; // [sp+10h] [bp-Ch]@24
  int v20; // [sp+14h] [bp-8h]@24
  int v21; // [sp+18h] [bp-4h]@24

  v2 = this;
  if ( this && SurfaceWindow::Lock(this, 0) )
  {
    v3 = i_swSource;
    if ( i_swSource && SurfaceWindow::Lock(i_swSource, 1) )
    {
      v4 = v3->surface;
      v5 = v2->surface;
      v6 = v4->pfDesc.flags & 4 && v5->size == v4->size || v2->pitch == v3->pitch;
      if ( v4->pfDesc.format == v5->pfDesc.format && v6 && !v2->rect.left && !v2->rect.top )
      {
        v7 = v2->rect.right;
        if ( v3->rect.right == v7 )
        {
          v8 = v2->rect.bottom;
          if ( v3->rect.bottom == v8 && v7 == v5->width && v8 == v5->height )
          {
            qmemcpy(v2->data, v3->data, v5->size);
            SurfaceWindow::Unlock(v3);
            SurfaceWindow::Unlock(v2);
            return 1;
          }
        }
      }
      v10 = v5->pfDesc.format;
      if ( v4->pfDesc.format == 28 )
      {
        if ( v10 != 28 )
        {
          v12 = (SurfaceWindow *)(v3->rect.bottom - v3->rect.top);
          v13 = v2->rect.bottom - v2->rect.top;
          v14 = v3->rect.right - v3->rect.left;
          v15 = v2->rect.right - v2->rect.left;
          v19 = v13;
          v16 = (unsigned int)v12 < v13;
          i_swSource = v12;
          v20 = v14;
          v21 = v15;
          v17 = &i_swSource;
          if ( !v16 )
            v17 = (SurfaceWindow **)&v19;
          v18 = &v20;
          if ( v14 >= (unsigned int)v15 )
            v18 = &v21;
          SurfaceWindow::FillArea(v2, &RGBAColor_Black_11, 0, 0, *v18 - 1, (const int)((char *)&(*v17)[-1].pitch + 3));
        }
      }
      else if ( v10 != 28 )
      {
        v11 = SurfaceWindow::BlitAndColor(v2, v3, 0, 1.0, 0, Blit_NOP, 0xFF000000);
LABEL_22:
        LOBYTE(i_swSource) = v11;
        SurfaceWindow::Unlock(v3);
        SurfaceWindow::Unlock(v2);
        return (char)i_swSource;
      }
      v11 = SurfaceWindow::CopyAlpha(v2, v3);
      goto LABEL_22;
    }
    SurfaceWindow::Unlock(v2);
  }
  return 0;
}

//----- (006C76E0) --------------------------------------------------------  // acclient.c:735430
void _E73_34()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_9, PFID_A8R8G8B8);
}

//----- (006C76F0) --------------------------------------------------------  // acclient.c:735436
void _E91_12()
{
  LODWORD(dword_837E64) = 1053364187;
}

//----- (006C7700) --------------------------------------------------------  // acclient.c:735442
void _E93_3()
{
  outside_val_8 = 1000.0 + 1.0;
}

//----- (006C7720) --------------------------------------------------------  // acclient.c:735448
void _E95_3()
{
  block_length_8 = 24.0 * 8.0;
}

//----- (006C7740) --------------------------------------------------------  // acclient.c:735454
void _E97_12()
{
  half_square_length_8 = 24.0 * 0.5;
}

//----- (006C7760) --------------------------------------------------------  // acclient.c:735460
int _E1_31()
{
  return atexit(_E2_31);
}

//----- (0072A7C0) --------------------------------------------------------  // acclient.c:828687
void __cdecl sub_72A7C0()
{
  if ( (refRow.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](refRow.m_data);
}

