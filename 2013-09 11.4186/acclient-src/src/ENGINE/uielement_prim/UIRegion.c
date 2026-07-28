/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIRegion
   Object     : ENGINE\uielement_prim\UIRegion.obj
   Functions  : 83
   Addresses  : 0069ED50 - 0078FED0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0069ED50) --------------------------------------------------------  // acclient.c:695139
void __thiscall UIRegion::ClearAlphaImage(UIRegion *this)
{
  UIRegion *v1; // esi@1
  Graphic *v2; // ecx@1

  v1 = this;
  v2 = this->m_alphaImage;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v1->m_alphaImage = 0;
}

//----- (0069ED70) --------------------------------------------------------  // acclient.c:695152
void __stdcall UIRegion::EraseBackground(Box2D *i_boxObject, UISurface *i_pSurface)
{
  int v3; // ebx@1
  int v4; // ebp@1
  int v5; // esi@1
  int v6; // edi@1
  SurfaceWindow win; // [sp+10h] [bp-2Ch]@1

  v3 = i_boxObject->m_y0;
  v4 = i_boxObject->m_x0;
  v5 = i_boxObject->m_y1;
  v6 = i_boxObject->m_x1;
  UISurface::PrepareSurface(i_pSurface);
  SurfaceWindow::SurfaceWindow(&win, i_pSurface->m_pLocalSurface, v4, v3, v6, v5);
  SurfaceWindow::Fill(&win, &RGBAColor_Null_40);
  win.vfptr = (SurfaceWindowVtbl *)SurfaceWindow::vftable;
  SurfaceWindow::End(&win);
}
// 798D14: using guessed type int (__thiscall *SurfaceWindow::vftable[2])(void *, char);

//----- (0069EDD0) --------------------------------------------------------  // acclient.c:695173
void __thiscall UIRegion::SetShouldBlockClicks(UIRegion *this, bool i_bBlockClicks)
{
  *((_DWORD *)this + 41) ^= ((unsigned __int8)*((_DWORD *)this + 41) ^ (unsigned __int8)(i_bBlockClicks << 6)) & 0x40;
}

//----- (0069EDF0) --------------------------------------------------------  // acclient.c:695179
void __thiscall UIRegion::SetClampGameViewEdge(UIRegion *this, unsigned int i_eEdge)
{
  UIObject *v2; // eax@1
  UIRegion *v3; // ecx@2

  v2 = this->m_object;
  if ( v2 )
  {
    v2->m_eClampGameView = i_eEdge;
    RenderUI::RecalculateClampedPosition();
  }
  else
  {
    v3 = this->m_parent;
    if ( v3 )
      ((void (__stdcall *)(unsigned int))v3->vfptr[3].__vecDelDtor)(i_eEdge);
  }
}

//----- (0069EE20) --------------------------------------------------------  // acclient.c:695199
void __thiscall UIRegion::BringToFront(UIRegion *this)
{
  UIRegion *v1; // eax@1

  v1 = this->m_parent;
  if ( v1 )
    v1->vfptr[6].__vecDelDtor((IInputActionCallback *)v1, (unsigned int)this);
}

//----- (0069EE40) --------------------------------------------------------  // acclient.c:695209
bool __thiscall UIRegion::PointIsOverRegion(UIRegion *this, int i_xParent, int i_yParent)
{
  UIRegion *v3; // eax@1
  Graphic *v4; // ecx@5
  bool result; // al@7

  v3 = this;
  result = 0;
  if ( i_xParent >= this->m_box.m_x0
    && i_xParent <= this->m_box.m_x1
    && i_yParent >= this->m_box.m_y0
    && i_yParent <= this->m_box.m_y1 )
  {
    v4 = this->m_alphaImage;
    if ( !v4 || !Graphic::PointTest(v4, i_xParent - v3->m_box.m_x0, i_yParent - v3->m_box.m_y0) )
      result = 1;
  }
  return result;
}

//----- (0069EEA0) --------------------------------------------------------  // acclient.c:695230
void __thiscall UIRegion::NotifyMouseMove(UIRegion *this, int _xWindow, int _yWindow)
{
  ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr[6].OnAction)(_xWindow, _yWindow);
}

//----- (0069EEB0) --------------------------------------------------------  // acclient.c:695236
void __thiscall UIRegion::NotifyMouseTap(UIRegion *this, unsigned int _x, unsigned int _y, unsigned int _button)
{
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->vfptr[12].__vecDelDtor)(_x, _y, _button);
}

//----- (0069EEC0) --------------------------------------------------------  // acclient.c:695242
int __thiscall UIRegion::GetObjectX0(UIRegion *this)
{
  UIRegion *v1; // esi@1
  UIRegion *v2; // ecx@2
  int result; // eax@3

  v1 = this;
  if ( this->m_object || (v2 = this->m_parent) == 0 )
    result = 0;
  else
    result = v1->m_box.m_x0 + UIRegion::GetObjectX0(v2);
  return result;
}

//----- (0069EEF0) --------------------------------------------------------  // acclient.c:695257
int __thiscall UIRegion::GetObjectY0(UIRegion *this)
{
  UIRegion *v1; // esi@1
  UIRegion *v2; // ecx@2
  int result; // eax@3

  v1 = this;
  if ( this->m_object || (v2 = this->m_parent) == 0 )
    result = 0;
  else
    result = v1->m_box.m_y0 + UIRegion::GetObjectY0(v2);
  return result;
}

//----- (0069EF20) --------------------------------------------------------  // acclient.c:695272
Box2D *__thiscall UIRegion::GetSurfaceBox(UIRegion *this, Box2D *result)
{
  UIObject *v2; // ecx@1
  int v3; // eax@2
  Box2D *v4; // eax@4
  int v5; // edx@4
  int v6; // ecx@4
  int nSurfX1; // [sp+8h] [bp-8h]@1
  int nSurfY1; // [sp+Ch] [bp-4h]@1

  v2 = this->m_object;
  nSurfX1 = 0;
  nSurfY1 = 0;
  if ( v2 )
  {
    v3 = ((int (*)(void))v2->vfptr[7].__vecDelDtor)();
    if ( v3 )
      (*(void (__thiscall **)(int, int *, int *))(*(_DWORD *)v3 + 20))(v3, &nSurfX1, &nSurfY1);
  }
  v4 = result;
  v5 = nSurfX1 - 1;
  v6 = nSurfY1 - 1;
  result->m_x0 = 0;
  result->m_y0 = 0;
  result->m_x1 = v5;
  result->m_y1 = v6;
  return v4;
}

//----- (0069EF80) --------------------------------------------------------  // acclient.c:695302
unsigned int __thiscall UIRegion::GetScreenX0(UIRegion *this)
{
  UIRegion *v1; // esi@1
  UIObject *v2; // eax@1
  unsigned int result; // eax@2
  UIRegion *v4; // ecx@3

  v1 = this;
  v2 = this->m_object;
  if ( v2 )
  {
    result = v2->m_nVirtualX;
  }
  else
  {
    v4 = this->m_parent;
    if ( v4 )
      result = v1->m_box.m_x0 + UIRegion::GetScreenX0(v4);
    else
      result = 0;
  }
  return result;
}

//----- (0069EFB0) --------------------------------------------------------  // acclient.c:695327
unsigned int __thiscall UIRegion::GetScreenY0(UIRegion *this)
{
  UIRegion *v1; // esi@1
  UIObject *v2; // eax@1
  unsigned int result; // eax@2
  UIRegion *v4; // ecx@3

  v1 = this;
  v2 = this->m_object;
  if ( v2 )
  {
    result = v2->m_nVirtualY;
  }
  else
  {
    v4 = this->m_parent;
    if ( v4 )
      result = v1->m_box.m_y0 + UIRegion::GetScreenY0(v4);
    else
      result = 0;
  }
  return result;
}

//----- (0069EFE0) --------------------------------------------------------  // acclient.c:695352
int __thiscall UIRegion::GetWidth(UIRegion *this)
{
  return this->m_box.m_x1 - this->m_box.m_x0 + 1;
}

//----- (0069EFF0) --------------------------------------------------------  // acclient.c:695358
int __thiscall UIRegion::GetHeight(UIRegion *this)
{
  return this->m_box.m_y1 - this->m_box.m_y0 + 1;
}

//----- (0069F000) --------------------------------------------------------  // acclient.c:695364
int __thiscall UIRegion::CompareZLevel(UIRegion *this, UIRegion *i_pRegion)
{
  int v2; // eax@1
  int v3; // ecx@1
  int result; // eax@2

  v2 = this->m_zlevel;
  v3 = i_pRegion->m_zlevel;
  if ( v2 >= v3 )
    result = v2 != v3;
  else
    result = -1;
  return result;
}

//----- (0069F030) --------------------------------------------------------  // acclient.c:695380
void __thiscall UIRegion::SetAlphaImageByDID(UIRegion *this, IDClass<_tagDataID,32,0> _alphaImageDID)
{
  UIRegion *v2; // esi@1
  Graphic *v3; // ecx@1
  Graphic *v4; // eax@3
  Graphic *v5; // eax@4

  v2 = this;
  v3 = this->m_alphaImage;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v2->m_alphaImage = 0;
  v4 = (Graphic *)operator new(0xCu);
  if ( v4 )
  {
    Graphic::Graphic(v4, _alphaImageDID);
    v2->m_alphaImage = v5;
  }
  else
  {
    v2->m_alphaImage = 0;
  }
}

//----- (0069F080) --------------------------------------------------------  // acclient.c:695405
void __thiscall UIRegion::AddDirtyRect(UIRegion *this, Box2D *_rect)
{
  UIRegion *v2; // esi@1
  UIObject *v3; // ecx@2
  UIRegion *v4; // ecx@4
  UIRegion *v5; // ecx@5
  Box2D clippedRect; // [sp+8h] [bp-40h]@1
  Box2D surfaceBox; // [sp+18h] [bp-30h]@1
  Box2D newRect; // [sp+28h] [bp-20h]@1
  Box2D parentSurfBox; // [sp+38h] [bp-10h]@5

  v2 = this;
  ((void (__stdcall *)(_DWORD))this->vfptr[4].OnAction)(&surfaceBox);
  newRect.m_y0 = surfaceBox.m_y0;
  newRect.m_x1 = surfaceBox.m_x1;
  newRect.m_x0 = surfaceBox.m_x0;
  newRect.m_y1 = surfaceBox.m_y1;
  clippedRect.m_x0 = 0;
  clippedRect.m_y0 = 0;
  clippedRect.m_x1 = 0;
  clippedRect.m_y1 = 0;
  if ( (unsigned __int8)Box2D::Intersection(&newRect, _rect, &clippedRect) )
  {
    v3 = v2->m_object;
    if ( v3 )
    {
      UIObject::AddDirtyRect(v3, &clippedRect);
    }
    else
    {
      v4 = v2->m_parent;
      if ( v4 )
      {
        ((void (__stdcall *)(Box2D *))v4->vfptr[4].OnAction)(&parentSurfBox);
        newRect.m_x0 = clippedRect.m_x0 + parentSurfBox.m_x0;
        newRect.m_y1 = clippedRect.m_y0 + parentSurfBox.m_y0 + clippedRect.m_y1 - clippedRect.m_y0;
        v5 = v2->m_parent;
        newRect.m_y0 = clippedRect.m_y0 + parentSurfBox.m_y0;
        newRect.m_x1 = clippedRect.m_x0 + parentSurfBox.m_x0 + clippedRect.m_x1 - clippedRect.m_x0;
        UIRegion::AddDirtyRect(v5, &newRect);
      }
    }
  }
}

//----- (0069F160) --------------------------------------------------------  // acclient.c:695451
void __thiscall UIRegion::EraseSelf(UIRegion *this, Box2D *i_rectObjectSelf, Box2D *i_rectObjectClip, SmartArray<Box2D,1> *i_aObjectBoxes, UISurface *i_pSurface)
{
  unsigned int v5; // ebx@1
  UIRegion *v6; // edi@1
  unsigned int v7; // esi@2

  v5 = i_aObjectBoxes->m_num;
  v6 = this;
  if ( v5 )
  {
    v7 = v5;
    do
    {
      --v7;
      ((void (__thiscall *)(UIRegion *, Box2D *, UISurface *))v6->vfptr[10].__vecDelDtor)(
        v6,
        &i_aObjectBoxes->m_data[v7],
        i_pSurface);
      --v5;
    }
    while ( v5 );
  }
}

//----- (0069F1A0) --------------------------------------------------------  // acclient.c:695476
void __thiscall UIRegion::DrawSelf(UIRegion *this, Box2D *i_rectObjectSelf, Box2D *i_rectObjectClip, SmartArray<Box2D,1> *i_aObjectBoxes, UISurface *i_pSurface)
{
  Box2D *v5; // edx@1
  int v6; // ebx@1
  UIRegion *v7; // esi@1
  int v8; // edi@1
  unsigned int v9; // eax@2
  unsigned int v10; // ebp@3
  Box2D *v11; // eax@5
  unsigned int v12; // [sp+Ch] [bp-14h]@3
  Box2D elementclipped; // [sp+10h] [bp-10h]@5

  v5 = i_rectObjectSelf;
  v6 = i_rectObjectSelf->m_y0;
  v7 = this;
  v8 = i_rectObjectSelf->m_x0;
  if ( this->m_image )
  {
    v9 = i_aObjectBoxes->m_num;
    if ( v9 )
    {
      v10 = v9;
      v12 = i_aObjectBoxes->m_num;
      while ( 1 )
      {
        --v10;
        v11 = &i_aObjectBoxes->m_data[v10];
        if ( &elementclipped != v11 )
        {
          elementclipped.m_x0 = v11->m_x0;
          elementclipped.m_x1 = v11->m_x1;
          elementclipped.m_y0 = v11->m_y0;
          elementclipped.m_y1 = v11->m_y1;
        }
        elementclipped.m_x0 = v11->m_x0 - v8;
        elementclipped.m_y0 = v11->m_y0 - v6;
        elementclipped.m_x1 = v11->m_x1 - v8;
        elementclipped.m_y1 = v11->m_y1 - v6;
        Graphic::Draw(
          v7->m_image,
          v7->m_eBlitMode,
          v7->m_alphaBlendMod,
          v5,
          v11,
          &elementclipped,
          &v7->m_ptTilingOffset,
          i_pSurface);
        --v12;
        if ( !v12 )
          break;
        v5 = i_rectObjectSelf;
      }
    }
  }
}

//----- (0069F280) --------------------------------------------------------  // acclient.c:695533
Box2D *__thiscall UIRegion::GetObjectBox(UIRegion *this, Box2D *result)
{
  UIRegion *v2; // edx@1
  UIObject *v3; // ebx@1
  int v4; // ebp@1
  int v5; // esi@1
  UIRegion *v6; // ecx@2
  int v7; // edi@3
  UIRegion *v8; // ecx@6
  int v9; // eax@7
  int v10; // edx@7
  int v11; // eax@7
  int v13; // [sp+10h] [bp-8h]@1
  int v14; // [sp+14h] [bp-4h]@1

  v2 = this;
  v3 = this->m_object;
  v4 = this->m_box.m_y0;
  v5 = this->m_box.m_y1;
  v14 = this->m_box.m_x1;
  v13 = this->m_box.m_x0;
  if ( v3 || (v6 = this->m_parent) == 0 )
    v7 = 0;
  else
    v7 = v4 + UIRegion::GetObjectY0(v6);
  if ( v3 || (v8 = v2->m_parent) == 0 )
  {
    v11 = 0;
  }
  else
  {
    v9 = UIRegion::GetObjectX0(v8);
    v11 = *(_DWORD *)(v10 + 124) + v9;
  }
  result->m_x0 = v11;
  result->m_y0 = v7;
  result->m_y1 = v7 + v5 - v4;
  result->m_x1 = v14 + v11 - v13;
  return result;
}

//----- (0069F310) --------------------------------------------------------  // acclient.c:695575
unsigned int __thiscall UIRegion::GetScreenX1(UIRegion *this)
{
  UIRegion *v1; // edx@1
  UIObject *v2; // eax@1
  unsigned int result; // eax@2
  UIRegion *v4; // ecx@3
  unsigned int v5; // eax@4
  int v6; // edx@4

  v1 = this;
  v2 = this->m_object;
  if ( v2 )
  {
    result = v2->m_nVirtualX + this->m_box.m_x1 - this->m_box.m_x0;
  }
  else
  {
    v4 = this->m_parent;
    if ( v4 )
    {
      v5 = UIRegion::GetScreenX0(v4);
      result = *(_DWORD *)(v6 + 124) + v5 + *(_DWORD *)(v6 + 132) - *(_DWORD *)(v6 + 124);
    }
    else
    {
      result = v1->m_box.m_x1 - v1->m_box.m_x0;
    }
  }
  return result;
}

//----- (0069F360) --------------------------------------------------------  // acclient.c:695607
unsigned int __thiscall UIRegion::GetScreenY1(UIRegion *this)
{
  UIRegion *v1; // edx@1
  UIObject *v2; // eax@1
  unsigned int result; // eax@2
  UIRegion *v4; // ecx@3
  unsigned int v5; // eax@4
  int v6; // edx@4

  v1 = this;
  v2 = this->m_object;
  if ( v2 )
  {
    result = v2->m_nVirtualY + this->m_box.m_y1 - this->m_box.m_y0;
  }
  else
  {
    v4 = this->m_parent;
    if ( v4 )
    {
      v5 = UIRegion::GetScreenY0(v4);
      result = *(_DWORD *)(v6 + 128) + v5 + *(_DWORD *)(v6 + 136) - *(_DWORD *)(v6 + 128);
    }
    else
    {
      result = v1->m_box.m_y1 - v1->m_box.m_y0;
    }
  }
  return result;
}

//----- (0069F3C0) --------------------------------------------------------  // acclient.c:695639
Box2D *__thiscall UIRegion::GetClipBox(UIRegion *this, Box2D *result)
{
  UIRegion *v2; // edi@1
  UIObject *v3; // ecx@1
  unsigned int v4; // eax@2
  int v5; // ecx@2
  UIRegion *v6; // ecx@3
  Box2D *v7; // eax@4
  int v8; // ecx@5
  int v9; // edx@5
  int v10; // eax@5
  Box2D *v11; // eax@6
  bool v12; // zf@6
  Box2D *v13; // eax@6
  int v14; // edx@10
  int v15; // ecx@10
  int v16; // edx@10
  Box2D parent; // [sp+Ch] [bp-30h]@1
  Box2D ret; // [sp+1Ch] [bp-20h]@4
  Box2D empty; // [sp+2Ch] [bp-10h]@6

  v2 = this;
  v3 = this->m_object;
  parent.m_x0 = 0;
  parent.m_x1 = -1;
  parent.m_y0 = 0;
  parent.m_y1 = -1;
  if ( v3 )
  {
    v4 = v3->m_nVirtualWidth;
    v5 = v3->m_nVirtualHeight - 1;
    parent.m_x0 = 0;
    parent.m_x1 = v4 - 1;
    parent.m_y0 = 0;
    parent.m_y1 = v5;
  }
  else
  {
    v6 = v2->m_parent;
    if ( v6 )
    {
      v7 = UIRegion::GetClipBox(v6, &ret);
      if ( &parent != v7 )
      {
        v8 = v7->m_x1;
        parent.m_x0 = v7->m_x0;
        v9 = v7->m_y0;
        v10 = v7->m_y1;
        parent.m_x1 = v8;
        parent.m_y0 = v9;
        parent.m_y1 = v10;
      }
    }
  }
  ret.m_x0 = 0;
  ret.m_y0 = 0;
  ret.m_x1 = 0;
  ret.m_y1 = 0;
  v11 = UIRegion::GetObjectBox(v2, &empty);
  v12 = (unsigned __int8)Box2D::Intersection(&parent, v11, &ret) == 0;
  v13 = result;
  if ( v12 )
  {
    if ( result != &empty )
    {
      result->m_x0 = 0;
      result->m_y0 = 0;
      result->m_x1 = -1;
      result->m_y1 = -1;
    }
  }
  else if ( result != &ret )
  {
    v14 = ret.m_x1;
    result->m_x0 = ret.m_x0;
    v15 = ret.m_y0;
    result->m_x1 = v14;
    v16 = ret.m_y1;
    result->m_y0 = v15;
    result->m_y1 = v16;
  }
  return v13;
}

//----- (0069F4C0) --------------------------------------------------------  // acclient.c:695724
Box2D *__thiscall UIRegion::GetScreenClipBox(UIRegion *this, Box2D *result)
{
  UIRegion *v2; // esi@1
  UIObject *v3; // edi@1
  unsigned int v4; // edx@2
  UIRegion *v5; // ecx@3
  unsigned int v6; // eax@7
  UIRegion *v7; // ecx@8
  int v8; // esi@11
  int v9; // ecx@11
  int v10; // edx@11
  Box2D *v11; // eax@11
  int v12; // ebx@11
  int v13; // ecx@11
  Box2D clip; // [sp+Ch] [bp-20h]@1
  Box2D object; // [sp+1Ch] [bp-10h]@1

  v2 = this;
  UIRegion::GetClipBox(this, &clip);
  UIRegion::GetObjectBox(v2, &object);
  v3 = v2->m_object;
  if ( v3 )
  {
    v4 = v3->m_nVirtualY;
  }
  else
  {
    v5 = v2->m_parent;
    if ( v5 )
      v4 = v2->m_box.m_y0 + UIRegion::GetScreenY0(v5);
    else
      v4 = 0;
  }
  if ( v3 )
  {
    v6 = v3->m_nVirtualX;
  }
  else
  {
    v7 = v2->m_parent;
    if ( v7 )
      v6 = v2->m_box.m_x0 + UIRegion::GetScreenX0(v7);
    else
      v6 = 0;
  }
  v8 = clip.m_y0;
  v9 = v4 + clip.m_y0 - object.m_y0;
  v10 = clip.m_x0 + v6 - object.m_x0;
  v11 = result;
  v12 = v10 + clip.m_x1 - clip.m_x0;
  result->m_y0 = v9;
  result->m_x0 = v10;
  v13 = clip.m_y1 + v9 - v8;
  result->m_x1 = v12;
  result->m_y1 = v13;
  return v11;
}

//----- (0069F570) --------------------------------------------------------  // acclient.c:695783
IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *__thiscall IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::vector_deleting_destructor(IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *v2; // esi@1
  HashList<UIRegion *,UIRegion *,1>::HashListData **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::vftable;
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
// 801714: using guessed type int (__thiscall *IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::vftable[2])(void *, char);

//----- (0069F5B0) --------------------------------------------------------  // acclient.c:695804
void __thiscall UIRegion::MakeRootDirtyHere(UIRegion *this)
{
  UIRegion *v1; // esi@1
  Box2D surfaceBox; // [sp+4h] [bp-10h]@1

  v1 = this;
  ((void (__stdcall *)(_DWORD))this->vfptr[4].OnAction)(&surfaceBox);
  UIRegion::AddDirtyRect(v1, &surfaceBox);
}

//----- (0069F5E0) --------------------------------------------------------  // acclient.c:695815
void __thiscall UIRegion::SetAlphaBlendMod(UIRegion *this, float _mod)
{
  UIRegion *v2; // esi@1
  double v3; // st7@2
  double v4; // st6@6
  Box2D _rect; // [sp+4h] [bp-10h]@8

  v2 = this;
  if ( _mod >= 0.0 )
  {
    if ( _mod <= 1.0 )
      v3 = _mod;
    else
      v3 = 1.0;
  }
  else
  {
    v3 = 0.0;
  }
  v4 = this->m_alphaBlendMod;
  this->m_alphaBlendMod = v3;
  if ( v3 != v4 )
  {
    if ( this->m_eBlitMode )
    {
      ((void (__stdcall *)(Box2D *))this->vfptr[4].OnAction)(&_rect);
      UIRegion::AddDirtyRect(v2, &_rect);
    }
  }
}

//----- (0069F660) --------------------------------------------------------  // acclient.c:695847
void __thiscall UIRegion::SetParent(UIRegion *this, UIRegion *_parent)
{
  UIRegion *v2; // esi@1
  UIRegion *v3; // ecx@2
  IInputActionCallbackVtbl *v4; // edx@4
  unsigned int v5; // ST04_4@4
  UIRegion *v6; // ecx@4
  Box2D _rect; // [sp+10h] [bp-10h]@2

  v2 = this;
  if ( this->m_parent != _parent )
  {
    ((void (__stdcall *)(_DWORD))this->vfptr[4].OnAction)(&_rect);
    UIRegion::AddDirtyRect(v2, &_rect);
    v3 = v2->m_parent;
    if ( v3 )
      ((void (__stdcall *)(UIRegion *))v3->vfptr[9].OnAction)(v2);
    v4 = v2->vfptr;
    v5 = (*((_DWORD *)v2 + 41) >> 1) & 0xFFFFFF01;
    v2->m_parent = _parent;
    v4[2].__vecDelDtor((IInputActionCallback *)v2, v5);
    v2->vfptr[4].OnAction((IInputActionCallback *)v2, (InputEvent *)&_rect);
    UIRegion::AddDirtyRect(v2, &_rect);
    v6 = v2->m_parent;
    if ( v6 )
      ((void (__stdcall *)(UIRegion *))v6->vfptr[9].__vecDelDtor)(v2);
  }
}

//----- (0069F6F0) --------------------------------------------------------  // acclient.c:695877
void __thiscall UIRegion::SetBlitMode(UIRegion *this, BlitMode i_eBlitMode)
{
  UIRegion *v2; // esi@1
  Box2D _rect; // [sp+4h] [bp-10h]@2

  v2 = this;
  if ( this->m_eBlitMode != i_eBlitMode )
  {
    this->m_eBlitMode = i_eBlitMode;
    ((void (__stdcall *)(_DWORD))this->vfptr[4].OnAction)(&_rect);
    UIRegion::AddDirtyRect(v2, &_rect);
  }
}

//----- (0069F730) --------------------------------------------------------  // acclient.c:695892
void __thiscall UIRegion::SetTilingOffset(UIRegion *this, tagPOINT *i_pt)
{
  UIRegion *v2; // esi@1
  Box2D _rect; // [sp+4h] [bp-10h]@3

  v2 = this;
  if ( this->m_ptTilingOffset.x != i_pt->x || this->m_ptTilingOffset.y != i_pt->y )
  {
    this->m_ptTilingOffset = *i_pt;
    this->vfptr[4].OnAction((IInputActionCallback *)this, (InputEvent *)&_rect);
    UIRegion::AddDirtyRect(v2, &_rect);
  }
}

//----- (0069F790) --------------------------------------------------------  // acclient.c:695907
void __thiscall UIRegion::SetImage(UIRegion *this, Graphic *_image)
{
  UIRegion *v2; // esi@1
  Graphic *v3; // ecx@1
  Box2D _rect; // [sp+8h] [bp-10h]@4

  v2 = this;
  v3 = this->m_image;
  v2->m_image = _image;
  if ( v3 != _image )
  {
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v2->vfptr[4].OnAction((IInputActionCallback *)v2, (InputEvent *)&_rect);
    UIRegion::AddDirtyRect(v2, &_rect);
  }
}

//----- (0069F7E0) --------------------------------------------------------  // acclient.c:695926
void __thiscall UIRegion::ClearImage(UIRegion *this)
{
  UIRegion *v1; // esi@1
  Graphic *v2; // edi@1
  Box2D _rect; // [sp+8h] [bp-10h]@4

  v1 = this;
  v2 = this->m_image;
  if ( v2 )
    v2->vfptr->__vecDelDtor(v2, 1u);
  v1->m_image = 0;
  if ( v2 )
  {
    v1->vfptr[4].OnAction((IInputActionCallback *)v1, (InputEvent *)&_rect);
    UIRegion::AddDirtyRect(v1, &_rect);
  }
}

//----- (0069F830) --------------------------------------------------------  // acclient.c:695945
void __thiscall UIRegion::MoveTo(UIRegion *this, const int _x, const int _y)
{
  UIRegion *v3; // esi@1
  int v4; // eax@3
  int v5; // ecx@3
  int v6; // edx@3
  int v7; // edi@3
  Box2D _rect; // [sp+Ch] [bp-10h]@3

  v3 = this;
  if ( _x != this->m_box.m_x0 || _y != this->m_box.m_y0 )
  {
    ((void (__stdcall *)(_DWORD))this->vfptr[4].OnAction)(&_rect);
    UIRegion::AddDirtyRect(v3, &_rect);
    v4 = v3->m_box.m_x1;
    v5 = v3->m_box.m_x0;
    v6 = v3->m_box.m_y1;
    v7 = v3->m_box.m_y0;
    v3->m_box.m_x0 = _x;
    v3->m_box.m_y0 = _y;
    v3->m_box.m_x1 = v4 + _x - v5;
    v3->m_box.m_y1 = v6 + v3->m_box.m_y0 - v7;
    v3->vfptr[4].OnAction((IInputActionCallback *)v3, (InputEvent *)&_rect);
    UIRegion::AddDirtyRect(v3, &_rect);
  }
}

//----- (0069F8C0) --------------------------------------------------------  // acclient.c:695973
void __thiscall UIRegion::ResizeTo(UIRegion *this, const int _width, const int _height)
{
  UIRegion *v3; // esi@1
  int v4; // eax@1
  const int v5; // ecx@1
  bool v6; // sf@1
  unsigned __int8 v7; // of@1
  Box2D _rect; // [sp+Ch] [bp-10h]@6

  v3 = this;
  v4 = this->m_box.m_x1 - this->m_box.m_x0 + 1;
  v5 = this->m_box.m_y1 - this->m_box.m_y0 + 1;
  v7 = __OFSUB__(_width, v4);
  v6 = _width - v4 < 0;
  if ( _width == v4 )
  {
    if ( _height == v5 )
      return;
    v7 = __OFSUB__(_width, v4);
    v6 = _width - v4 < 0;
  }
  if ( v6 ^ v7 || _height < v5 )
  {
    v3->vfptr[4].OnAction((IInputActionCallback *)v3, (InputEvent *)&_rect);
    UIRegion::AddDirtyRect(v3, &_rect);
  }
  v3->m_box.m_x1 = v3->m_box.m_x0 + _width - 1;
  v3->m_box.m_y1 = v3->m_box.m_y0 + _height - 1;
  v3->vfptr[4].OnAction((IInputActionCallback *)v3, (InputEvent *)&_rect);
  UIRegion::AddDirtyRect(v3, &_rect);
}

//----- (0069F960) --------------------------------------------------------  // acclient.c:696006
void __thiscall UIRegion::SetImageByDID(UIRegion *this, IDClass<_tagDataID,32,0> _imageDID, unsigned int _drawMode)
{
  UIRegion *v3; // esi@1
  Graphic *v4; // edi@1
  Graphic *v5; // eax@10
  Graphic *v6; // eax@11
  Graphic *v7; // ecx@13
  Box2D _rect; // [sp+10h] [bp-10h]@4

  v3 = this;
  v4 = this->m_image;
  if ( v4 )
    v4->vfptr->__vecDelDtor(v4, 1u);
  v3->m_image = 0;
  if ( v4 )
  {
    v3->vfptr[4].OnAction((IInputActionCallback *)v3, (InputEvent *)&_rect);
    UIRegion::AddDirtyRect(v3, &_rect);
  }
  if ( _drawMode == 2 )
  {
    v3->m_eBlitMode = 1;
  }
  else if ( _drawMode == 3 )
  {
    v3->m_eBlitMode = 2;
  }
  else
  {
    v3->m_eBlitMode = 0;
  }
  v5 = (Graphic *)operator new(0xCu);
  if ( v5 )
    Graphic::Graphic(v5, _imageDID);
  else
    v6 = 0;
  v7 = v3->m_image;
  v3->m_image = v6;
  if ( v7 != v6 )
  {
    if ( v7 )
      ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
    v3->vfptr[4].OnAction((IInputActionCallback *)v3, (InputEvent *)&_rect);
    UIRegion::AddDirtyRect(v3, &_rect);
  }
}

//----- (0069FA30) --------------------------------------------------------  // acclient.c:696054
void __thiscall UIRegion::DrawHere(UIRegion *this, Box2D *_surfaceBox, Box2D *_clipBox, SmartArray<Box2D,1> *_boxes, UISurface *_surface)
{
  UIRegion *v5; // edi@1
  int v6; // ebx@4
  int v7; // ebp@5
  int v8; // esi@5
  unsigned int v9; // eax@7
  int v10; // ebp@7
  int v11; // ebx@7
  int v12; // esi@7
  bool v13; // zf@7
  int v14; // eax@20
  int v15; // ecx@20
  int v16; // edx@20
  int v17; // [sp+48h] [bp-34h]@8
  int index; // [sp+4Ch] [bp-30h]@4
  unsigned int indexa; // [sp+4Ch] [bp-30h]@7
  SmartArray<Box2D,1> hitArray; // [sp+50h] [bp-2Ch]@7
  Box2D rectTotalDirty; // [sp+5Ch] [bp-20h]@7
  Box2D elementdirty; // [sp+6Ch] [bp-10h]@9

  v5 = this;
  if ( _boxes->m_num )
  {
    if ( _surface )
    {
      if ( (*((_DWORD *)this + 41) >> 1) & 1 )
      {
        v6 = _surfaceBox->m_x1;
        index = _surfaceBox->m_x0;
        if ( _surfaceBox->m_x1 - _surfaceBox->m_x0 + 1 > 0 )
        {
          v7 = _surfaceBox->m_y1;
          v8 = _surfaceBox->m_y0;
          if ( _surfaceBox->m_y1 - v8 + 1 > 0 )
          {
            if ( (unsigned __int8)Box2D::IsValid(_clipBox) )
            {
              v9 = 0;
              rectTotalDirty.m_x0 = v6 + 1;
              v10 = v7 + 1;
              v11 = index - 1;
              v12 = v8 - 1;
              v13 = _boxes->m_num == 0;
              hitArray.m_data = 0;
              hitArray.m_sizeAndDeallocate = 0;
              hitArray.m_num = 0;
              rectTotalDirty.m_y0 = v10;
              rectTotalDirty.m_x1 = index - 1;
              rectTotalDirty.m_y1 = v12;
              indexa = 0;
              if ( !v13 )
              {
                v17 = 0;
                do
                {
                  elementdirty.m_x0 = 0;
                  elementdirty.m_y0 = 0;
                  elementdirty.m_x1 = 0;
                  elementdirty.m_y1 = 0;
                  if ( (unsigned __int8)Box2D::Intersection(_clipBox, &_boxes->m_data[v17], &elementdirty) )
                  {
                    SmartArray<Box2D,1>::AddToEnd(&hitArray, &elementdirty);
                    if ( elementdirty.m_x0 < rectTotalDirty.m_x0 )
                      rectTotalDirty.m_x0 = elementdirty.m_x0;
                    v10 = rectTotalDirty.m_y0;
                    if ( elementdirty.m_y0 < rectTotalDirty.m_y0 )
                    {
                      v10 = elementdirty.m_y0;
                      rectTotalDirty.m_y0 = elementdirty.m_y0;
                    }
                    v11 = rectTotalDirty.m_x1;
                    if ( elementdirty.m_x1 > rectTotalDirty.m_x1 )
                    {
                      v11 = elementdirty.m_x1;
                      rectTotalDirty.m_x1 = elementdirty.m_x1;
                    }
                    v12 = rectTotalDirty.m_y1;
                    if ( elementdirty.m_y1 > rectTotalDirty.m_y1 )
                    {
                      v12 = elementdirty.m_y1;
                      rectTotalDirty.m_y1 = elementdirty.m_y1;
                    }
                  }
                  ++v17;
                  ++indexa;
                }
                while ( indexa < _boxes->m_num );
                if ( hitArray.m_num )
                {
                  v14 = _surfaceBox->m_x0;
                  v15 = _surfaceBox->m_y0;
                  elementdirty.m_x0 = rectTotalDirty.m_x0 - _surfaceBox->m_x0;
                  v16 = *((_DWORD *)v5 + 41) >> 3;
                  elementdirty.m_x1 = v11 - v14;
                  elementdirty.m_y1 = v12 - v15;
                  elementdirty.m_y0 = v10 - v15;
                  if ( v16 & 1 )
                    ((void (__thiscall *)(UIRegion *, Box2D *, Box2D *, SmartArray<Box2D,1> *, UISurface *))v5->vfptr[5].OnAction)(
                      v5,
                      _surfaceBox,
                      &rectTotalDirty,
                      &hitArray,
                      _surface);
                  if ( (*((_DWORD *)v5 + 41) >> 7) & 1 )
                    ((void (__thiscall *)(UIRegion *, Box2D *, Box2D *, SmartArray<Box2D,1> *, UISurface *))v5->vfptr[11].OnAction)(
                      v5,
                      _surfaceBox,
                      &rectTotalDirty,
                      &hitArray,
                      _surface);
                  ((void (__thiscall *)(UIRegion *))v5->vfptr[9].OnLoseFocus)(v5);
                  ((void (__thiscall *)(UIRegion *, Box2D *, UISurface *))v5->vfptr[10].OnAction)(
                    v5,
                    &elementdirty,
                    _surface);
                  ((void (__thiscall *)(UIRegion *, Box2D *, Box2D *, SmartArray<Box2D,1> *, UISurface *))v5->vfptr[10].OnLoseFocus)(
                    v5,
                    _surfaceBox,
                    &rectTotalDirty,
                    &hitArray,
                    _surface);
                  ((void (__thiscall *)(UIRegion *, Box2D *, UISurface *))v5->vfptr[11].__vecDelDtor)(
                    v5,
                    &elementdirty,
                    _surface);
                  if ( !((*((_DWORD *)v5 + 41) >> 7) & 1) )
                    ((void (__thiscall *)(UIRegion *, Box2D *, Box2D *, SmartArray<Box2D,1> *, UISurface *))v5->vfptr[11].OnAction)(
                      v5,
                      _surfaceBox,
                      &rectTotalDirty,
                      &hitArray,
                      _surface);
                  ((void (__thiscall *)(UIRegion *))v5->vfptr[11].OnLoseFocus)(v5);
                }
                v9 = hitArray.m_sizeAndDeallocate;
              }
              if ( (v9 & 0x80000000) == 0x80000000 )
                operator delete[](hitArray.m_data);
            }
          }
        }
      }
    }
  }
}

//----- (0069FCA0) --------------------------------------------------------  // acclient.c:696202
void __thiscall UIRegion::DrawChildren(UIRegion *this, Box2D *i_rectObjectSelf, Box2D *i_rectObjectClip, SmartArray<Box2D,1> *i_aObjectBoxes, UISurface *i_pSurface)
{
  unsigned int v5; // edx@1
  char *v6; // ecx@1
  int v7; // eax@1
  int v8; // eax@2
  int v9; // esi@6
  int v10; // eax@7
  int v11; // ecx@7
  int v12; // eax@10
  int iter; // [sp+14h] [bp-38h]@5
  Box2D childClipBox; // [sp+1Ch] [bp-30h]@7
  Box2D childSurfaceBox; // [sp+2Ch] [bp-20h]@7
  Box2D surfaceBox; // [sp+3Ch] [bp-10h]@7

  v5 = this->m_children.m_ihlIntrusive.m_hash.m_numElements;
  v6 = (char *)&this->m_children;
  v7 = 0;
  if ( v5 )
  {
    v8 = *((_DWORD *)v6 + 28);
    if ( v8 )
      v7 = v8 - 8;
    else
      v7 = 0;
  }
  for ( iter = v7; v7; iter = v7 )
  {
    v9 = *(_DWORD *)(v7 + 16);
    if ( !*(_DWORD *)(v9 + 176) )
    {
      (*(void (__thiscall **)(int, Box2D *))(*(_DWORD *)v9 + 52))(v9, &surfaceBox);
      v10 = i_rectObjectSelf->m_y0;
      v11 = surfaceBox.m_x0 + i_rectObjectSelf->m_x0;
      childSurfaceBox.m_y0 = surfaceBox.m_y0 + v10;
      childSurfaceBox.m_x1 = v11 + surfaceBox.m_x1 - surfaceBox.m_x0;
      childSurfaceBox.m_y1 = surfaceBox.m_y1 + v10;
      childSurfaceBox.m_x0 = v11;
      childClipBox.m_x0 = 0;
      childClipBox.m_y0 = 0;
      childClipBox.m_x1 = 0;
      childClipBox.m_y1 = 0;
      if ( (unsigned __int8)Box2D::Intersection(i_rectObjectClip, &childSurfaceBox, &childClipBox) )
        (*(void (__thiscall **)(int, Box2D *, Box2D *, SmartArray<Box2D,1> *, UISurface *))(*(_DWORD *)v9 + 60))(
          v9,
          &childSurfaceBox,
          &childClipBox,
          i_aObjectBoxes,
          i_pSurface);
      v7 = iter;
    }
    v12 = *(_DWORD *)(v7 + 8);
    if ( !v12 )
      break;
    v7 = v12 - 8;
  }
}

//----- (0069FD90) --------------------------------------------------------  // acclient.c:696261
void __thiscall UIRegion::ForceUpdate(UIRegion *this, unsigned int i_updateFlags)
{
  UIRegion *v2; // edi@1
  UIObject *v3; // ecx@2
  int v4; // esi@7
  DLListData *v5; // ecx@8
  int v6; // esi@12
  HashListIterator<HashList<UIRegion *,UIRegion *,1> > iter; // [sp+8h] [bp-10h]@5

  v2 = this;
  if ( i_updateFlags & 2 )
  {
    v3 = this->m_object;
    if ( v3 )
      ((void (*)(void))v3->vfptr[2].__vecDelDtor)();
  }
  if ( i_updateFlags & 1 )
  {
    v2->vfptr[4].OnAction((IInputActionCallback *)v2, (InputEvent *)&iter);
    UIRegion::AddDirtyRect(v2, (Box2D *)&iter);
  }
  if ( i_updateFlags & 4 )
  {
    v4 = 0;
    if ( v2->m_children.m_ihlIntrusive.m_hash.m_numElements )
    {
      v5 = v2->m_children.m_ihlIntrusive.m_list.head_;
      if ( v5 )
        v4 = (int)&v5[-1];
      else
        v4 = 0;
    }
    for ( iter.m_iter.m_pHashList = &v2->m_children.m_ihlIntrusive; v4; v4 = v6 - 8 )
    {
      UIRegion::ForceUpdate(*(UIRegion **)v4, i_updateFlags);
      v6 = *(_DWORD *)(v4 + 8);
      if ( !v6 )
        break;
    }
  }
}

//----- (0069FE20) --------------------------------------------------------  // acclient.c:696304
void __thiscall UIRegion::NotifyMouseDown(UIRegion *this, unsigned int _xWindow, unsigned int _yWindow, unsigned int _button)
{
  UIRegion *v4; // esi@1

  v4 = this;
  if ( _button != 5 && _button != 6 && UIRegion::IsMouseDown(this, _button) )
  {
    if ( !(*((_BYTE *)v4 + 164) & 1) )
      ((void (__thiscall *)(UIRegion *, unsigned int, unsigned int, unsigned int))v4->vfptr[8].OnAction)(
        v4,
        _xWindow,
        _yWindow,
        _button);
  }
  else if ( *((_BYTE *)v4 + 164) & 1 )
  {
    ((void (__thiscall *)(UIRegion *, unsigned int, unsigned int, unsigned int))v4->vfptr[8].__vecDelDtor)(
      v4,
      _xWindow,
      _yWindow,
      _button);
  }
}

//----- (0069FE80) --------------------------------------------------------  // acclient.c:696329
void __thiscall UIRegion::NotifyMouseUp(UIRegion *this, unsigned int _xWindow, unsigned int _yWindow, unsigned int _button)
{
  HashSetData<unsigned long> *v4; // eax@1

  v4 = this->m_mouseDownTable.m_intrusiveTable.m_buckets[_button % this->m_mouseDownTable.m_intrusiveTable.m_numBuckets];
  if ( v4 )
  {
    while ( v4->m_hashKey != _button )
    {
      v4 = v4->m_hashNext;
      if ( !v4 )
        return;
    }
    if ( v4 )
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->vfptr[8].OnAction)(_xWindow, _yWindow, _button);
  }
}

//----- (0069FED0) --------------------------------------------------------  // acclient.c:696348
void __thiscall UIRegion::SetVisible(UIRegion *this, bool _visible)
{
  UIRegion *v2; // edi@1
  unsigned int v3; // eax@1
  bool v4; // bl@1
  int v5; // esi@1
  DLListData *v6; // ecx@2
  int v7; // esi@6
  UIObject *v8; // eax@9
  HashListIterator<HashList<UIRegion *,UIRegion *,1> > iter; // [sp+Ch] [bp-10h]@5

  v2 = this;
  v3 = *((_DWORD *)this + 41);
  v4 = ((v3 >> 1) & 1) != _visible;
  *((_DWORD *)this + 41) = v3 ^ ((unsigned __int8)v3 ^ (unsigned __int8)(2 * _visible)) & 2;
  v5 = 0;
  if ( this->m_children.m_ihlIntrusive.m_hash.m_numElements )
  {
    v6 = this->m_children.m_ihlIntrusive.m_list.head_;
    if ( v6 )
      v5 = (int)&v6[-1];
    else
      v5 = 0;
  }
  for ( iter.m_iter.m_pHashList = &v2->m_children.m_ihlIntrusive; v5; v5 = v7 - 8 )
  {
    (*(void (__stdcall **)(unsigned int))(**(_DWORD **)v5 + 24))((*(_DWORD *)(*(_DWORD *)v5 + 164) >> 1) & 0xFFFFFF01);
    v7 = *(_DWORD *)(v5 + 8);
    if ( !v7 )
      break;
  }
  if ( v4 )
  {
    v8 = v2->m_object;
    if ( v8 )
    {
      v8->m_bVisible = _visible;
      if ( v8->m_eClampGameView )
        RenderUI::RecalculateClampedPosition();
    }
    v2->vfptr[4].OnAction((IInputActionCallback *)v2, (InputEvent *)&iter);
    UIRegion::AddDirtyRect(v2, (Box2D *)&iter);
  }
}

//----- (0069FF90) --------------------------------------------------------  // acclient.c:696394
void __thiscall IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>(IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashList<UIRegion *,UIRegion *,1>::HashListData **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashList<UIRegion *,UIRegion *,1>::HashListData **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 801714: using guessed type int (__thiscall *IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::vftable[2])(void *, char);

//----- (006A0080) --------------------------------------------------------  // acclient.c:696472
void __thiscall UIRegion::MouseDown(UIRegion *this, unsigned int _xWindow, unsigned int _yWindow, unsigned int _button)
{
  HashSet<unsigned long>::add(&this->m_mouseDownTable, &_button);
}

//----- (006A00A0) --------------------------------------------------------  // acclient.c:696478
void __thiscall UIRegion::MouseUp(UIRegion *this, unsigned int _xWindow, unsigned int _yWindow, unsigned int _button)
{
  HashSetData<IDClass<_tagDataID,32,0> > *v4; // eax@1

  v4 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->m_mouseDownTable.m_intrusiveTable,
         (IDClass<_tagDataID,32,0> *)&_button);
  if ( v4 )
    operator delete(v4);
}

//----- (006A00C0) --------------------------------------------------------  // acclient.c:696490
char __thiscall IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::place_at_head(IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this, HashList<UIRegion *,UIRegion *,1>::HashListData *pMoving)
{
  IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *v2; // esi@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *v3; // eax@1
  char *v4; // eax@5
  DLListData *v5; // ecx@5
  char result; // al@6

  v2 = this;
  v3 = v2->m_hash.m_buckets[(((unsigned int)pMoving->m_hashKey >> 8) | (unsigned __int64)((unsigned int)pMoving->m_hashKey << 24))
                          % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != pMoving->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
    DLListBase::Remove(&this->m_list, (DLListData *)&pMoving->dllist_next);
  else
LABEL_4:
    IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::add(&this->m_hash, pMoving);
  v4 = (char *)&pMoving->dllist_next;
  pMoving->dllist_next = v2->m_list.head_;
  v5 = v2->m_list.head_;
  if ( v5 )
  {
    v5->dllist_prev = (DLListData *)v4;
    v2->m_list.head_ = (DLListData *)v4;
    pMoving->dllist_prev = 0;
    result = 1;
  }
  else
  {
    v2->m_list.tail_ = (DLListData *)v4;
    v2->m_list.head_ = (DLListData *)v4;
    pMoving->dllist_prev = 0;
    result = 1;
  }
  return result;
}

//----- (006A0150) --------------------------------------------------------  // acclient.c:696535
void __thiscall UIRegion::UIRegion(UIRegion *this, UIRegion *_parent, int _x, int _y, int _width, int _height)
{
  UIRegion *v6; // esi@1

  v6 = this;
  UIListener::UIListener((UIListener *)&this->vfptr);
  v6->vfptr = (IInputActionCallbackVtbl *)&UIRegion::vftable;
  v6->m_box.m_x0 = _x;
  v6->m_box.m_y0 = _y;
  v6->m_box.m_x1 = _x + _width - 1;
  v6->m_box.m_y1 = _y + _height - 1;
  *((_DWORD *)v6 + 41) = *((_DWORD *)v6 + 41) & 0xFFFFFF06 | 2;
  v6->m_zlevel = 0;
  v6->m_image = 0;
  v6->m_alphaImage = 0;
  LODWORD(v6->m_alphaBlendMod) = 1065353216;
  v6->m_eBlitMode = 0;
  v6->m_parent = 0;
  v6->m_object = 0;
  IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>(
    &v6->m_children.m_ihlIntrusive.m_hash,
    0);
  v6->m_children.m_ihlIntrusive.m_list.head_ = 0;
  v6->m_children.m_ihlIntrusive.m_list.tail_ = 0;
  v6->m_mouseDownTable.vfptr = (HashSet<unsigned long>Vtbl *)HashSet<unsigned long>::vftable;
  IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>(
    &v6->m_mouseDownTable.m_intrusiveTable,
    4u);
  v6->m_ptTilingOffset.x = 0;
  v6->m_ptTilingOffset.y = 0;
}
// 79BD74: using guessed type int (__thiscall *HashSet<unsigned long>::vftable[3])(void *, char);
// 801718: using guessed type int (__thiscall *UIRegion::vftable)(void *, char);

//----- (006A0250) --------------------------------------------------------  // acclient.c:696582
void __thiscall UIRegion::~UIRegion(UIRegion *this)
{
  UIRegion *v1; // esi@1
  Graphic *v2; // ecx@1
  Graphic *v3; // ecx@3
  UIObject *v4; // ecx@5
  bool v5; // zf@6
  void *v6; // eax@9
  void *v7; // eax@11

  v1 = this;
  v2 = this->m_image;
  v1->vfptr = (IInputActionCallbackVtbl *)&UIRegion::vftable;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v3 = v1->m_alphaImage;
  v1->m_image = 0;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v1->m_alphaImage = 0;
  HashList<UIRegion *,UIRegion *,1>::flush(&v1->m_children);
  v4 = v1->m_object;
  if ( v4 )
  {
    v5 = v4->m_cRef-- == 1;
    if ( v5 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v1->m_object = 0;
  }
  v1->m_parent = 0;
  v1->m_mouseDownTable.vfptr = (HashSet<unsigned long>Vtbl *)HashSet<unsigned long>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_mouseDownTable.m_intrusiveTable);
  v6 = v1->m_mouseDownTable.m_intrusiveTable.m_buckets;
  v1->m_mouseDownTable.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable;
  if ( v6 != v1->m_mouseDownTable.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v6);
  v1->m_mouseDownTable.m_intrusiveTable.m_buckets = 0;
  v1->m_mouseDownTable.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_mouseDownTable.m_intrusiveTable.m_numBuckets = 0;
  v1->m_mouseDownTable.m_intrusiveTable.m_numElements = 0;
  IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents((IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *)&v1->m_children);
  v7 = v1->m_children.m_ihlIntrusive.m_hash.m_buckets;
  v1->m_children.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::vftable;
  if ( v7 != v1->m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
    operator delete[](v7);
  v1->m_children.m_ihlIntrusive.m_hash.m_buckets = 0;
  v1->m_children.m_ihlIntrusive.m_hash.m_firstInterestingBucket = 0;
  v1->m_children.m_ihlIntrusive.m_hash.m_numBuckets = 0;
  v1->m_children.m_ihlIntrusive.m_hash.m_numElements = 0;
  UIListener::~UIListener((UIListener *)&v1->vfptr);
}
// 79BD6C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable[5])(void *, char);
// 79BD74: using guessed type int (__thiscall *HashSet<unsigned long>::vftable[3])(void *, char);
// 801714: using guessed type int (__thiscall *IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::vftable[2])(void *, char);
// 801718: using guessed type int (__thiscall *UIRegion::vftable)(void *, char);

//----- (006A0330) --------------------------------------------------------  // acclient.c:696639
void __thiscall UIRegion::RemoveChild(UIRegion *this, UIRegion *_child)
{
  HashList<UIRegion *,UIRegion *,1>::HashListData *v2; // eax@1

  v2 = IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::remove(
         &this->m_children.m_ihlIntrusive,
         &_child);
  if ( v2 )
    operator delete(v2);
}

//----- (006A0350) --------------------------------------------------------  // acclient.c:696651
char __thiscall HashList<UIRegion *,UIRegion *,1>::move_to_head(HashList<UIRegion *,UIRegion *,1> *this, UIRegion *const *keyToMove)
{
  HashList<UIRegion *,UIRegion *,1>::HashListData *v2; // eax@1
  char result; // al@4

  v2 = this->m_ihlIntrusive.m_hash.m_buckets[(((unsigned int)*keyToMove >> 8) | (unsigned __int64)((unsigned int)*keyToMove << 24))
                                           % this->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v2 )
    goto LABEL_10;
  while ( v2->m_hashKey != (UIRegion *)*keyToMove )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      return 0;
  }
  if ( v2 )
    result = IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::place_at_head(
               &this->m_ihlIntrusive,
               v2);
  else
LABEL_10:
    result = 0;
  return result;
}

//----- (006A03A0) --------------------------------------------------------  // acclient.c:696677
char __thiscall IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::push_head(IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this, HashList<UIRegion *,UIRegion *,1>::HashListData *val)
{
  IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *v2; // esi@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *v3; // eax@1
  char *v4; // eax@4
  DLListData *v5; // ecx@4
  char result; // al@5

  v2 = this;
  v3 = v2->m_hash.m_buckets[(((unsigned int)val->m_hashKey >> 8) | (unsigned __int64)((unsigned int)val->m_hashKey << 24))
                          % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != val->m_hashKey )
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
    IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::add(&this->m_hash, val);
    v4 = (char *)&val->dllist_next;
    val->dllist_next = v2->m_list.head_;
    v5 = v2->m_list.head_;
    if ( v5 )
    {
      v5->dllist_prev = (DLListData *)v4;
      v2->m_list.head_ = (DLListData *)v4;
      val->dllist_prev = 0;
      result = 1;
    }
    else
    {
      v2->m_list.tail_ = (DLListData *)v4;
      v2->m_list.head_ = (DLListData *)v4;
      val->dllist_prev = 0;
      result = 1;
    }
  }
  return result;
}

//----- (006A0420) --------------------------------------------------------  // acclient.c:696726
char __thiscall IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::insert_after(IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this, HashList<UIRegion *,UIRegion *,1>::HashListData *pExisting, HashList<UIRegion *,UIRegion *,1>::HashListData *pNew)
{
  IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *v3; // edi@1
  char result; // al@2

  v3 = this;
  if ( pExisting )
  {
    if ( IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::contains(
           this,
           &pNew->m_hashKey) )
    {
      result = 0;
    }
    else
    {
      IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::add(&v3->m_hash, pNew);
      if ( pNew )
      {
        DLListBase::InsertAfter(&v3->m_list, (DLListData *)&pNew->dllist_next, (DLListData *)&pExisting->dllist_next);
        result = 1;
      }
      else
      {
        DLListBase::InsertAfter(&v3->m_list, 0, (DLListData *)&pExisting->dllist_next);
        result = 1;
      }
    }
  }
  else
  {
    result = IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::push_head(this, pNew);
  }
  return result;
}

//----- (006A0490) --------------------------------------------------------  // acclient.c:696763
char __thiscall IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::place_after(IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this, HashList<UIRegion *,UIRegion *,1>::HashListData *pExisting, HashList<UIRegion *,UIRegion *,1>::HashListData *pMoving)
{
  IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *v3; // edi@1
  char result; // al@2

  v3 = this;
  if ( pExisting )
  {
    if ( IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::contains(
           this,
           &pMoving->m_hashKey) )
    {
      if ( pMoving )
        DLListBase::Remove(&v3->m_list, (DLListData *)&pMoving->dllist_next);
      else
        DLListBase::Remove(&v3->m_list, 0);
    }
    else
    {
      IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::add(&v3->m_hash, pMoving);
    }
    if ( pMoving )
    {
      DLListBase::InsertAfter(&v3->m_list, (DLListData *)&pMoving->dllist_next, (DLListData *)&pExisting->dllist_next);
      result = 1;
    }
    else
    {
      DLListBase::InsertAfter(&v3->m_list, 0, (DLListData *)&pExisting->dllist_next);
      result = 1;
    }
  }
  else
  {
    result = IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::place_at_head(
               this,
               pMoving);
  }
  return result;
}

//----- (006A0520) --------------------------------------------------------  // acclient.c:696805
UIRegion *__thiscall UIRegion::vector_deleting_destructor(UIRegion *this, unsigned int a2)
{
  UIRegion *v2; // esi@1

  v2 = this;
  UIRegion::~UIRegion(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006A0540) --------------------------------------------------------  // acclient.c:696817
char __thiscall HashList<UIRegion *,UIRegion *,1>::push_head(HashList<UIRegion *,UIRegion *,1> *this, UIRegion *const *key, UIRegion *const *val)
{
  HashList<UIRegion *,UIRegion *,1> *v3; // edi@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *v4; // edx@1
  void *v5; // eax@4
  HashList<UIRegion *,UIRegion *,1>::HashListData *v6; // esi@5
  char result; // al@7
  char v8; // bl@9

  v3 = this;
  v4 = v3->m_ihlIntrusive.m_hash.m_buckets[(((unsigned int)*key >> 8) | (unsigned __int64)((unsigned int)*key << 24))
                                         % v3->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != (UIRegion *)*key )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = HashList<UIRegion *,UIRegion *,1>::move_to_head(this, key);
  }
  else
  {
LABEL_4:
    v5 = operator new(0x14u);
    if ( v5 )
    {
      *(_DWORD *)v5 = *key;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 4) = *val;
      v6 = (HashList<UIRegion *,UIRegion *,1>::HashListData *)v5;
    }
    else
    {
      v6 = 0;
    }
    v8 = IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::push_head(
           &v3->m_ihlIntrusive,
           v6);
    if ( !v8 )
    {
      if ( v6 )
        operator delete(v6);
    }
    result = v8;
  }
  return result;
}

//----- (006A05E0) --------------------------------------------------------  // acclient.c:696872
char __thiscall HashList<UIRegion *,UIRegion *,1>::move_to_middle(HashList<UIRegion *,UIRegion *,1> *this, UIRegion *const *keyInsertAfter, UIRegion *const *keyToMove)
{
  unsigned int v3; // ebx@1
  HashList<UIRegion *,UIRegion *,1>::HashListData **v4; // ebp@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *i; // esi@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *j; // eax@4
  char result; // al@9

  v3 = this->m_ihlIntrusive.m_hash.m_numBuckets;
  v4 = this->m_ihlIntrusive.m_hash.m_buckets;
  for ( i = v4[(((unsigned int)*keyInsertAfter >> 8) | (unsigned __int64)((unsigned int)*keyInsertAfter << 24)) % v3];
        i;
        i = i->m_hashNext )
  {
    if ( i->m_hashKey == (UIRegion *)*keyInsertAfter )
      break;
  }
  for ( j = v4[(((unsigned int)*keyToMove >> 8) | (unsigned __int64)((unsigned int)*keyToMove << 24)) % v3];
        j;
        j = j->m_hashNext )
  {
    if ( j->m_hashKey == (UIRegion *)*keyToMove )
      break;
  }
  if ( i && j )
    result = IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::place_after(
               &this->m_ihlIntrusive,
               i,
               j);
  else
    result = 0;
  return result;
}

//----- (006A0670) --------------------------------------------------------  // acclient.c:696907
char __thiscall HashList<UIRegion *,UIRegion *,1>::insert_after(HashList<UIRegion *,UIRegion *,1> *this, UIRegion *const *keyInsertAfter, UIRegion *const *keyNew, UIRegion *const *valNew)
{
  HashList<UIRegion *,UIRegion *,1> *v4; // esi@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *v5; // edx@1
  char result; // al@4
  void *v7; // eax@9
  void *v8; // edi@10
  HashList<UIRegion *,UIRegion *,1>::HashListData *v9; // edx@12

  v4 = this;
  v5 = v4->m_ihlIntrusive.m_hash.m_buckets[(((unsigned int)*keyInsertAfter >> 8) | (unsigned __int64)((unsigned int)*keyInsertAfter << 24))
                                         % v4->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v5 )
    goto LABEL_23;
  while ( v5->m_hashKey != (UIRegion *)*keyInsertAfter )
  {
    v5 = v5->m_hashNext;
    if ( !v5 )
      return 0;
  }
  if ( v5 )
  {
    if ( IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::contains(
           &this->m_ihlIntrusive,
           keyNew) )
    {
      result = HashList<UIRegion *,UIRegion *,1>::move_to_middle(v4, keyInsertAfter, keyNew);
    }
    else
    {
      v7 = operator new(0x14u);
      if ( v7 )
      {
        *(_DWORD *)v7 = *keyNew;
        *((_DWORD *)v7 + 1) = 0;
        *((_DWORD *)v7 + 2) = 0;
        *((_DWORD *)v7 + 3) = 0;
        *((_DWORD *)v7 + 4) = *valNew;
        v8 = v7;
      }
      else
      {
        v8 = 0;
      }
      v9 = v4->m_ihlIntrusive.m_hash.m_buckets[(((unsigned int)*keyInsertAfter >> 8) | (unsigned __int64)((unsigned int)*keyInsertAfter << 24))
                                             % v4->m_ihlIntrusive.m_hash.m_numBuckets];
      if ( !v9 )
        goto LABEL_15;
      while ( v9->m_hashKey != (UIRegion *)*keyInsertAfter )
      {
        v9 = v9->m_hashNext;
        if ( !v9 )
          goto LABEL_15;
      }
      if ( v9
        && IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::insert_after(
             &v4->m_ihlIntrusive,
             v9,
             (HashList<UIRegion *,UIRegion *,1>::HashListData *)v8) )
      {
        result = 1;
      }
      else
      {
LABEL_15:
        if ( v8 )
          operator delete(v8);
        result = 0;
      }
    }
  }
  else
  {
LABEL_23:
    result = 0;
  }
  return result;
}

//----- (006A0760) --------------------------------------------------------  // acclient.c:696987
void __thiscall UIRegion::AddChild(UIRegion *this, UIRegion *_child)
{
  UIRegion *v2; // ebx@1
  HashList<UIRegion *,UIRegion *,1> *v3; // edi@2
  int v4; // esi@2
  DLListData *v5; // eax@3
  int v6; // eax@7
  int v7; // esi@8
  UIRegion *pPrev; // [sp+4h] [bp-8h]@7
  HashList<UIRegion *,UIRegion *,1> *v9; // [sp+8h] [bp-4h]@6

  v2 = _child;
  if ( _child )
  {
    v3 = &this->m_children;
    v4 = 0;
    if ( this->m_children.m_ihlIntrusive.m_hash.m_numElements )
    {
      v5 = this->m_children.m_ihlIntrusive.m_list.tail_;
      if ( v5 )
        v4 = (int)&v5[-1];
      else
        v4 = 0;
    }
    v9 = &this->m_children;
    if ( v4 )
    {
      while ( 1 )
      {
        v6 = **(_DWORD **)(v4 + 16);
        pPrev = *(UIRegion **)(v4 + 16);
        if ( (*(int (__stdcall **)(UIRegion *))(v6 + 56))(v2) >= 0 )
          break;
        v7 = *(_DWORD *)(v4 + 12);
        if ( v7 )
        {
          v4 = v7 - 8;
          if ( v4 )
            continue;
        }
        goto LABEL_10;
      }
      HashList<UIRegion *,UIRegion *,1>::insert_after(v3, &pPrev, &_child, &_child);
    }
    else
    {
LABEL_10:
      HashList<UIRegion *,UIRegion *,1>::push_head(v3, &_child, &_child);
    }
  }
}

//----- (006A07F0) --------------------------------------------------------  // acclient.c:697040
void __thiscall UIRegion::BringToFront(UIRegion *this, UIRegion *_child)
{
  UIRegion *v2; // ebx@1
  char *v3; // edi@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *i; // edx@1
  DLListData *v5; // edx@5
  int v6; // esi@6
  HashList<UIRegion *,UIRegion *,1>::HashListData *v7; // eax@8
  int v8; // eax@11
  int v9; // eax@12
  int v10; // ebx@15
  int j; // eax@16
  int v12; // esi@18
  HashList<UIRegion *,UIRegion *,1>::HashListData *iter; // [sp+8h] [bp-10h]@4

  v2 = _child;
  v3 = (char *)&this->m_children;
  for ( i = this->m_children.m_ihlIntrusive.m_hash.m_buckets[(((unsigned int)_child >> 8) | (unsigned __int64)((_DWORD)_child << 24))
                                                           % this->m_children.m_ihlIntrusive.m_hash.m_numBuckets];
        i;
        i = i->m_hashNext )
  {
    if ( i->m_hashKey == _child )
      break;
  }
  iter = i;
  if ( i )
  {
    v5 = i->dllist_next;
    if ( v5 )
    {
      v6 = (int)&v5[-1];
      if ( v5 != (DLListData *)8 && *(_DWORD *)(*(_DWORD *)(v6 + 16) + 148) != _child->m_zlevel )
        return;
    }
    else
    {
      v6 = 0;
    }
    v7 = IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::remove(
           (IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *)v3,
           &_child);
    if ( v7 )
      operator delete(v7);
    if ( *((_DWORD *)v3 + 27)
      && ((v8 = *((_DWORD *)v3 + 29)) == 0 ? (v9 = 0) : (v9 = v8 - 8),
          v10 = v2->m_zlevel,
          *(_DWORD *)(*(_DWORD *)(v9 + 16) + 148) < v10) )
    {
      for ( j = (int)iter; v6; v6 = v12 - 8 )
      {
        if ( *(_DWORD *)(*(_DWORD *)(v6 + 16) + 148) < v10 )
          break;
        j = v6;
        v12 = *(_DWORD *)(v6 + 8);
        if ( !v12 )
          break;
      }
      HashList<UIRegion *,UIRegion *,1>::insert_after(
        (HashList<UIRegion *,UIRegion *,1> *)v3,
        (UIRegion *const *)(j + 16),
        &_child,
        &_child);
    }
    else
    {
      HashList<UIRegion *,UIRegion *,1>::push_tail((HashList<UIRegion *,UIRegion *,1> *)v3, &_child, &_child);
    }
  }
}

//----- (00721480) --------------------------------------------------------  // acclient.c:819009
void sub_721480()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F9BE0, PFID_A8R8G8B8);
}

//----- (00721490) --------------------------------------------------------  // acclient.c:819015
int sub_721490()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_84, "None");
  return atexit(_E92_68);
}

//----- (007214B0) --------------------------------------------------------  // acclient.c:819022
int _E94_59()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_84, "Speed");
  return atexit(sub_78FD20);
}

//----- (007214D0) --------------------------------------------------------  // acclient.c:819029
int sub_7214D0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_84, "Noise");
  return atexit(sub_78FD50);
}

//----- (007214F0) --------------------------------------------------------  // acclient.c:819036
int sub_7214F0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_84, "Sine");
  return atexit(sub_78FD80);
}

//----- (00721510) --------------------------------------------------------  // acclient.c:819043
int sub_721510()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_84, "Square");
  return atexit(sub_78FDB0);
}

//----- (00721530) --------------------------------------------------------  // acclient.c:819050
int sub_721530()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_84, "Bounce");
  return atexit(sub_78FDE0);
}

//----- (00721550) --------------------------------------------------------  // acclient.c:819057
int sub_721550()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_84, "Perlin");
  return atexit(sub_78FE10);
}

//----- (00721570) --------------------------------------------------------  // acclient.c:819064
int sub_721570()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_84, "Fractal");
  return atexit(_E113_92);
}

//----- (00721590) --------------------------------------------------------  // acclient.c:819071
int sub_721590()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_84, "FrameLoop");
  return atexit(_E116_84);
}

//----- (007215B0) --------------------------------------------------------  // acclient.c:819078
int sub_7215B0()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_49, "Misc.TooltipEnable");
  return atexit(sub_78FEA0);
}

//----- (007215D0) --------------------------------------------------------  // acclient.c:819085
int _E121_93()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_49, "Misc.TooltipDelay");
  return atexit(sub_78FED0);
}

//----- (007215F0) --------------------------------------------------------  // acclient.c:819092
int sub_7215F0()
{
  return atexit(nullsub_317);
}

//----- (0078FCF0) --------------------------------------------------------  // acclient.c:936308
void __cdecl _E92_68()
{
  char *v0; // esi@1

  v0 = &waveform_None_84.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_84.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FD20) --------------------------------------------------------  // acclient.c:936321
void __cdecl sub_78FD20()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_84.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_84.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FD50) --------------------------------------------------------  // acclient.c:936334
void __cdecl sub_78FD50()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_84.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_84.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FD80) --------------------------------------------------------  // acclient.c:936347
void __cdecl sub_78FD80()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_84.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_84.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FDB0) --------------------------------------------------------  // acclient.c:936360
void __cdecl sub_78FDB0()
{
  char *v0; // esi@1

  v0 = &waveform_Square_84.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_84.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FDE0) --------------------------------------------------------  // acclient.c:936373
void __cdecl sub_78FDE0()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_84.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_84.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FE10) --------------------------------------------------------  // acclient.c:936386
void __cdecl sub_78FE10()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_84.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_84.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FE40) --------------------------------------------------------  // acclient.c:936399
void __cdecl _E113_92()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_84.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_84.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FE70) --------------------------------------------------------  // acclient.c:936412
void __cdecl _E116_84()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_84.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_84.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FEA0) --------------------------------------------------------  // acclient.c:936425
void __cdecl sub_78FEA0()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FED0) --------------------------------------------------------  // acclient.c:936438
void __cdecl sub_78FED0()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

