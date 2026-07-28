/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Graphic
   Object     : ENGINE\imagelib\Graphic.obj
   Functions  : 15
   Addresses  : 006939D0 - 00719190 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006939D0) --------------------------------------------------------  // acclient.c:683570
unsigned int __thiscall Graphic::GetWidth(Graphic *this)
{
  RenderSurface *v1; // eax@1
  unsigned int result; // eax@2

  v1 = this->m_image;
  if ( v1 )
    result = v1->width;
  else
    result = 0;
  return result;
}

//----- (006939F0) --------------------------------------------------------  // acclient.c:683584
unsigned int __thiscall Graphic::GetHeight(Graphic *this)
{
  RenderSurface *v1; // eax@1
  unsigned int result; // eax@2

  v1 = this->m_image;
  if ( v1 )
    result = v1->height;
  else
    result = 0;
  return result;
}

//----- (00693A10) --------------------------------------------------------  // acclient.c:683598
bool __thiscall Graphic::PointTest(Graphic *this, int _x, int _y)
{
  RenderSurface *v3; // eax@1
  bool result; // al@2

  v3 = this->m_image;
  if ( v3 )
    result = SurfaceWindow::PointTestOverlay(&v3->window, _x, _y);
  else
    result = 0;
  return result;
}

//----- (00693A30) --------------------------------------------------------  // acclient.c:683612
void __thiscall Graphic::PutImage(Graphic *this, BlitMode _eMode, float _alphablendmod, Box2D *_src, Box2D *_dst, UISurface *_surface)
{
  RenderSurface *v6; // ecx@1
  UISurface *v7; // esi@2
  int v8; // edi@3
  int v9; // ebx@3
  int v10; // ebp@3
  SurfaceWindow dest; // [sp+0h] [bp-58h]@3
  SurfaceWindow src; // [sp+2Ch] [bp-2Ch]@3
  int _surfacea; // [sp+6Ch] [bp+14h]@3

  v6 = this->m_image;
  if ( v6 )
  {
    v7 = _surface;
    if ( _surface )
    {
      SurfaceWindow::SurfaceWindow(&src, v6, _src->m_x0, _src->m_y0, _src->m_x1, _src->m_y1);
      v8 = _dst->m_y1;
      v9 = _dst->m_x1;
      v10 = _dst->m_y0;
      _surfacea = _dst->m_x0;
      UISurface::PrepareSurface(v7);
      SurfaceWindow::SurfaceWindow(&dest, v7->m_pLocalSurface, _surfacea, v10, v9, v8);
      SurfaceWindow::Blit(&dest, &src, _eMode, _alphablendmod);
      dest.vfptr = (SurfaceWindowVtbl *)SurfaceWindow::vftable;
      SurfaceWindow::End(&dest);
      src.vfptr = (SurfaceWindowVtbl *)SurfaceWindow::vftable;
      SurfaceWindow::End(&src);
    }
  }
}
// 798D14: using guessed type int (__thiscall *SurfaceWindow::vftable[2])(void *, char);

//----- (00693AE0) --------------------------------------------------------  // acclient.c:683647
void __thiscall Graphic::Graphic(Graphic *this, Graphic *_rhs)
{
  Graphic *v2; // esi@1
  RenderSurface *v3; // ecx@2

  v2 = this;
  this->vfptr = (GraphicVtbl *)&Graphic::vftable;
  this->m_id.id = stru_8F8608.id;
  this->m_image = 0;
  if ( this != _rhs )
  {
    this->m_id.id = _rhs->m_id.id;
    v3 = _rhs->m_image;
    if ( v3 )
    {
      v2->m_image = v3;
      ((void (*)(void))v3->vfptr->AddRef)();
    }
  }
}
// 800638: using guessed type int (__thiscall *Graphic::vftable)(void *, char);

//----- (00693B20) --------------------------------------------------------  // acclient.c:683670
void __thiscall Graphic::Draw(Graphic *this, BlitMode i_eBlitFlags, float _alphablendmod, Box2D *_bounds, Box2D *_objectdirty, Box2D *_elementdirty, tagPOINT *i_ptTilingOffset, UISurface *_surface)
{
  int v8; // ebx@1
  Box2D *v9; // ebp@3
  RenderSurface *v10; // eax@7
  int v11; // esi@11
  signed int v12; // edi@16
  Graphic *v13; // ecx@16
  signed int v14; // ebx@16
  Box2D *v15; // edx@16
  int v16; // esi@17
  bool v17; // zf@17
  signed int v18; // esi@17
  int v19; // ecx@20
  int v20; // edx@20
  int v21; // esi@23
  int v22; // ebp@24
  int v23; // ebx@26
  int v24; // edi@28
  int v25; // eax@28
  int v26; // esi@30
  int v27; // [sp+4h] [bp-3Ch]@1
  int v28; // [sp+8h] [bp-38h]@2
  Graphic *v29; // [sp+Ch] [bp-34h]@1
  Box2D rectDirty; // [sp+10h] [bp-30h]@16
  Box2D rectDest; // [sp+20h] [bp-20h]@29
  Box2D rectImage; // [sp+30h] [bp-10h]@29
  int _boundsa; // [sp+4Ch] [bp+Ch]@2
  Box2D *_boundsb; // [sp+4Ch] [bp+Ch]@16
  int hMe; // [sp+50h] [bp+10h]@16
  int wMe; // [sp+54h] [bp+14h]@17
  int xofs; // [sp+58h] [bp+18h]@23

  v8 = _bounds->m_x1 - _bounds->m_x0 + 1;
  v29 = this;
  v27 = _bounds->m_x0;
  if ( v8 > 0 )
  {
    v28 = _bounds->m_y0;
    _boundsa = _bounds->m_y1 - _bounds->m_y0 + 1;
    if ( _boundsa > 0 )
    {
      v9 = _objectdirty;
      if ( _objectdirty->m_x1 - _objectdirty->m_x0 + 1 > 0
        && _objectdirty->m_y1 - _objectdirty->m_y0 + 1 > 0
        && _elementdirty->m_x1 - _elementdirty->m_x0 + 1 > 0
        && _elementdirty->m_y1 - _elementdirty->m_y0 + 1 > 0 )
      {
        v10 = this->m_image;
        if ( v10 )
        {
          if ( v10->width && v10->height && _surface )
          {
            v11 = i_ptTilingOffset->x;
            if ( i_ptTilingOffset->x
              || i_ptTilingOffset->y
              || v8 > (signed int)Graphic::GetWidth(this)
              || _boundsa > (signed int)Graphic::GetHeight(this) )
            {
              v12 = Graphic::GetWidth(this);
              hMe = v12;
              v14 = Graphic::GetHeight(v13);
              rectDirty.m_x0 = 0;
              rectDirty.m_y0 = 0;
              rectDirty.m_x1 = 0;
              rectDirty.m_y1 = 0;
              _boundsb = (Box2D *)v14;
              if ( (unsigned __int8)Box2D::Intersection(v9, v15, &rectDirty) )
              {
                v16 = v11 - v27;
                v17 = rectDirty.m_x0 + v16 == 0;
                v18 = rectDirty.m_x0 + v16;
                wMe = v18;
                if ( !v17 )
                {
                  wMe = v18 % v12;
                  if ( v18 % v12 < 0 )
                    wMe = v12 + v18 % v12;
                }
                v19 = rectDirty.m_y0;
                v20 = rectDirty.m_y0 + i_ptTilingOffset->y - v28;
                if ( v20 )
                {
                  v20 %= v14;
                  if ( v20 < 0 )
                    v20 += v14;
                }
                v21 = rectDirty.m_y1;
                xofs = rectDirty.m_y0;
                if ( rectDirty.m_y0 <= rectDirty.m_y1 )
                {
                  v22 = rectDirty.m_x1;
                  while ( 1 )
                  {
                    v23 = v14 - v20;
                    if ( v23 + v19 > v21 + 1 )
                      v23 = v21 - v19 + 1;
                    v24 = rectDirty.m_x0;
                    v25 = wMe;
                    if ( rectDirty.m_x0 <= v22 )
                    {
                      rectDest.m_y0 = v19;
                      rectImage.m_y0 = v20;
                      rectDest.m_y1 = v23 + v19 - 1;
                      rectImage.m_y1 = v23 + v20 - 1;
                      do
                      {
                        v26 = hMe - v25;
                        if ( hMe - v25 + v24 > v22 + 1 )
                          v26 = v22 - v24 + 1;
                        rectImage.m_x0 = v25;
                        rectDest.m_x1 = v26 + v24 - 1;
                        rectImage.m_x1 = v26 + v25 - 1;
                        rectDest.m_x0 = v24;
                        Graphic::PutImage(v29, i_eBlitFlags, _alphablendmod, &rectImage, &rectDest, _surface);
                        v24 += v26;
                        v25 = 0;
                      }
                      while ( v24 <= v22 );
                      v19 = xofs;
                      v21 = rectDirty.m_y1;
                    }
                    v19 += v23;
                    v20 = 0;
                    xofs = v19;
                    if ( v19 > v21 )
                      break;
                    v14 = (signed int)_boundsb;
                  }
                }
              }
            }
            else
            {
              Graphic::PutImage(this, i_eBlitFlags, _alphablendmod, _elementdirty, _objectdirty, _surface);
            }
          }
        }
      }
    }
  }
}

//----- (00693D70) --------------------------------------------------------  // acclient.c:683814
void __thiscall Graphic::SetToDefaultGraphic(Graphic *this)
{
  Graphic *v1; // esi@1
  int v2; // eax@1
  int v3; // ebx@1
  PixelFormatID v4; // eax@1
  RenderSurface *v5; // ecx@2
  RenderSurface *v6; // eax@4
  SurfaceWindow *v7; // ecx@5
  RGBAColor color; // [sp+10h] [bp-30h]@5
  tagRECT r1; // [sp+20h] [bp-20h]@5
  tagRECT r2; // [sp+30h] [bp-10h]@5

  v1 = this;
  v2 = (*(int (**)(void))&RenderDevice::render_device->vfptr->gap4[8])();
  v1->m_image = (RenderSurface *)v2;
  v3 = *(_DWORD *)v2;
  v4 = RenderDevice::GetUISurfaceFormat(RenderDevice::render_device);
  if ( (unsigned __int8)(*(int (__thiscall **)(RenderSurface *, signed int, signed int, PixelFormatID, signed int))(v3 + 88))(
                          v1->m_image,
                          32,
                          32,
                          v4,
                          1) )
  {
    v6 = v1->m_image;
    if ( v6 )
    {
      LODWORD(color.r) = 1050253722;
      LODWORD(color.g) = 1050253722;
      LODWORD(color.b) = 1053609165;
      LODWORD(color.a) = 1065353216;
      SurfaceWindow::Fill(&v6->window, &color);
      v7 = &v1->m_image->window;
      r1.left = 29;
      r2.top = 29;
      r1.top = 0;
      r2.left = 0;
      r1.right = 32;
      r2.bottom = 32;
      r1.bottom = 32;
      r2.right = 32;
      SurfaceWindow::FillArea(v7, &::color, &r1);
      SurfaceWindow::FillArea(&v1->m_image->window, &::color, &r2);
    }
  }
  else
  {
    v5 = v1->m_image;
    if ( v5 )
    {
      ((void (*)(void))v5->vfptr->Release)();
      v1->m_image = 0;
    }
  }
}

//----- (00693E60) --------------------------------------------------------  // acclient.c:683872
void __thiscall Graphic::Graphic(Graphic *this, RenderSurface *i_pSurface)
{
  Graphic *v2; // esi@1

  v2 = this;
  this->vfptr = (GraphicVtbl *)&Graphic::vftable;
  this->m_id.id = stru_8F8608.id;
  this->m_image = i_pSurface;
  if ( i_pSurface )
  {
    i_pSurface->vfptr->AddRef((Interface *)i_pSurface);
    v2->m_id.id = i_pSurface->m_DID.id;
  }
  else
  {
    Graphic::SetToDefaultGraphic(this);
  }
}
// 800638: using guessed type int (__thiscall *Graphic::vftable)(void *, char);

//----- (00693EA0) --------------------------------------------------------  // acclient.c:683893
Graphic *__thiscall Graphic::vector_deleting_destructor(Graphic *this, unsigned int a2)
{
  Graphic *v2; // esi@1
  RenderSurface *v3; // ecx@1

  v2 = this;
  v3 = this->m_image;
  v2->vfptr = (GraphicVtbl *)&Graphic::vftable;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v2->m_image = 0;
  }
  v2->m_id.id = stru_8F8608.id;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 800638: using guessed type int (__thiscall *Graphic::vftable)(void *, char);

//----- (00693EE0) --------------------------------------------------------  // acclient.c:683914
void __thiscall Graphic::Graphic(Graphic *this, IDClass<_tagDataID,32,0> _id)
{
  Graphic *v2; // esi@1
  QualifiedDataID *v3; // eax@1
  int v4; // eax@1
  QualifiedDataID v5; // [sp+4h] [bp-8h]@1

  v2 = this;
  this->vfptr = (GraphicVtbl *)&Graphic::vftable;
  this->m_id.id = _id.id;
  this->m_image = 0;
  QualifiedDataID::QualifiedDataID(&v5, _id, 0xCu);
  v4 = DBObj::Get(v3);
  v2->m_image = (RenderSurface *)v4;
  if ( !v4 )
    Graphic::SetToDefaultGraphic(v2);
}
// 800638: using guessed type int (__thiscall *Graphic::vftable)(void *, char);

//----- (00719150) --------------------------------------------------------  // acclient.c:811796
int sub_719150()
{
  return atexit(nullsub_244);
}

//----- (00719160) --------------------------------------------------------  // acclient.c:811802
int sub_719160()
{
  return atexit(nullsub_245);
}

//----- (00719170) --------------------------------------------------------  // acclient.c:811808
int _E79_93()
{
  return atexit(_E80_90);
}

//----- (00719180) --------------------------------------------------------  // acclient.c:811814
void _E82_58()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F860C, PFID_A8R8G8B8);
}

//----- (00719190) --------------------------------------------------------  // acclient.c:811820
int sub_719190()
{
  return atexit(nullsub_243);
}

