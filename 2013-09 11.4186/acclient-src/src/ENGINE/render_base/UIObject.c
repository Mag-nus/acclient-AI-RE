/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIObject
   Object     : ENGINE\render_base\UIObject.obj
   Functions  : 9
   Addresses  : 006992F0 - 0071B430 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006992F0) --------------------------------------------------------  // acclient.c:689070
int __thiscall Box2D::Includes(Box2D *this, Box2D *_rhs)
{
  Box2D *v2; // esi@1
  int v3; // eax@1
  int v4; // edx@1
  int v5; // edi@1
  int v6; // ebp@2
  int v7; // ecx@4
  int v8; // ebx@5
  int v9; // esi@9
  int result; // eax@17
  int v11; // [sp+10h] [bp-4h]@2
  int _rhsa; // [sp+18h] [bp+4h]@3

  v2 = _rhs;
  v3 = _rhs->m_x0;
  v4 = _rhs->m_y0;
  v5 = this->m_x0;
  result = 0;
  if ( _rhs->m_x0 >= this->m_x0 )
  {
    v6 = this->m_x1;
    v11 = this->m_x1;
    if ( v3 <= v6 )
    {
      _rhsa = this->m_y0;
      if ( v4 >= this->m_y0 )
      {
        v7 = this->m_y1;
        if ( v4 <= v7 )
        {
          v8 = v2->m_x1;
          if ( v8 >= v5 && v8 <= v6 && v4 >= _rhsa && v4 <= v7 )
          {
            v9 = v2->m_y1;
            if ( v3 >= v5 && v3 <= v11 && v9 >= _rhsa && v9 <= v7 && v8 >= v5 && v8 <= v11 && v9 >= _rhsa && v9 <= v7 )
              result = 1;
          }
        }
      }
    }
  }
  return result;
}

//----- (00699380) --------------------------------------------------------  // acclient.c:689116
bool __thiscall Box2D::Collide(Box2D *this, Box2D *_rhs)
{
  bool result; // al@1
  int v3; // ebp@4
  int v4; // edx@4
  int v5; // [sp+8h] [bp-8h]@2
  int v6; // [sp+Ch] [bp-4h]@2

  result = 0;
  if ( this->m_x1 - this->m_x0 + 1 > 0 )
  {
    v6 = this->m_y1;
    v5 = this->m_y0;
    if ( v6 - v5 + 1 > 0 && _rhs->m_x1 - _rhs->m_x0 + 1 > 0 )
    {
      v3 = _rhs->m_y1;
      v4 = _rhs->m_y0;
      result = v3 - v4 + 1 > 0 && this->m_x0 <= _rhs->m_x1 && this->m_x1 >= _rhs->m_x0 && v5 <= v3 && v6 >= v4;
    }
  }
  return result;
}

//----- (00699400) --------------------------------------------------------  // acclient.c:689140
void __thiscall UIObject::SetVirtualScreenPosition(UIObject *this, const unsigned int i_x, const unsigned int i_y, const unsigned int i_width, const unsigned int i_height)
{
  this->m_nVirtualX = i_x;
  this->m_nVirtualY = i_y;
  this->m_nVirtualWidth = i_width;
  this->m_nVirtualHeight = i_height;
  RenderUI::RecalculateClampedPosition();
}

//----- (00699430) --------------------------------------------------------  // acclient.c:689150
char __thiscall SmartArray<Box2D,1>::RemoveUnOrderedByIndex(SmartArray<Box2D,1> *this, unsigned int index)
{
  unsigned int v2; // eax@1
  unsigned int v3; // eax@2
  Box2D *v4; // eax@3
  Box2D *v5; // edx@3
  Box2D *v6; // eax@5
  char result; // al@7
  char v8; // [sp+0h] [bp-10h]@5

  v2 = this->m_num;
  if ( index >= v2 )
  {
    result = 0;
  }
  else
  {
    v3 = v2 - 1;
    this->m_num = v3;
    if ( index != v3 )
    {
      v4 = &this->m_data[v3];
      v5 = &this->m_data[index];
      if ( v5 != v4 )
      {
        v5->m_x0 = v4->m_x0;
        v5->m_x1 = v4->m_x1;
        v5->m_y0 = v4->m_y0;
        v5->m_y1 = v4->m_y1;
      }
      v6 = &this->m_data[this->m_num];
      if ( (char *)v6 != &v8 )
      {
        v6->m_x0 = 0;
        v6->m_x1 = 0;
        v6->m_y0 = 0;
        v6->m_y1 = 0;
      }
    }
    result = 1;
  }
  return result;
}

//----- (006994A0) --------------------------------------------------------  // acclient.c:689195
void __thiscall UIObject::UIObject(UIObject *this)
{
  LODWORD(this->m_tTouchTime) = 0;
  this->m_cRef = 1;
  this->m_bVisible = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&UIObject::vftable;
  this->m_bTemporary = 0;
  this->m_eClampGameView = 0;
  this->m_nDepth = 0;
  this->m_nVirtualX = 0;
  this->m_nVirtualY = 0;
  this->m_nVirtualWidth = 0;
  this->m_nVirtualHeight = 0;
  HIDWORD(this->m_tTouchTime) = -1074790400;
  LODWORD(this->m_vScale.x) = 1065353216;
  LODWORD(this->m_vScale.y) = 1065353216;
  LODWORD(this->m_vScale.z) = 1065353216;
  this->m_pOwner = 0;
  this->m_dirtyRects.m_data = 0;
  this->m_dirtyRects.m_sizeAndDeallocate = 0;
  this->m_dirtyRects.m_num = 0;
}
// 800678: using guessed type int (__thiscall *UIObject::vftable)(void *, char);

//----- (00699500) --------------------------------------------------------  // acclient.c:689220
char __thiscall SmartArray<Box2D,1>::AddToEnd(SmartArray<Box2D,1> *this, Box2D *i_rData)
{
  SmartArray<Box2D,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2
  Box2D *v6; // eax@3

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1), (result = SmartArray<Box2D,1>::grow(v2, v4)) != 0) )
  {
    v6 = &v2->m_data[v2->m_num];
    if ( v6 != i_rData )
      *v6 = *i_rData;
    ++v2->m_num;
    result = 1;
  }
  return result;
}

//----- (00699560) --------------------------------------------------------  // acclient.c:689243
bool __thiscall Box2D::Subtract(Box2D *this, Box2D *_rhs, SmartArray<Box2D,1> *_result)
{
  Box2D *v3; // esi@1
  bool result; // al@1
  int v5; // edi@3
  int v6; // ebx@3
  int v7; // ebp@3
  int v8; // eax@5
  int v9; // eax@7
  int v10; // eax@9
  int v11; // eax@11
  Box2D current; // [sp+4h] [bp-20h]@2
  Box2D add; // [sp+14h] [bp-10h]@6

  v3 = this;
  result = Box2D::Collide(this, _rhs);
  if ( result )
  {
    if ( &current == v3 )
    {
      v7 = current.m_y0;
      v6 = current.m_x1;
      v5 = current.m_x0;
    }
    else
    {
      v5 = v3->m_x0;
      v6 = v3->m_x1;
      v7 = v3->m_y0;
      current.m_y1 = v3->m_y1;
    }
    v8 = _rhs->m_x0;
    if ( v5 <= _rhs->m_x0 )
    {
      add.m_x0 = v5;
      v5 = v8;
      add.m_y1 = current.m_y1;
      add.m_y0 = v7;
      add.m_x1 = v8 - 1;
      SmartArray<Box2D,1>::AddToEnd(_result, &add);
    }
    v9 = _rhs->m_x1;
    if ( v6 >= v9 )
    {
      add.m_y1 = current.m_y1;
      add.m_x0 = v9 + 1;
      add.m_x1 = v6;
      add.m_y0 = v7;
      v6 = v9;
      SmartArray<Box2D,1>::AddToEnd(_result, &add);
    }
    v10 = _rhs->m_y0;
    if ( v7 <= v10 )
    {
      add.m_x0 = v5;
      add.m_x1 = v6;
      add.m_y0 = v7;
      add.m_y1 = v10 - 1;
      SmartArray<Box2D,1>::AddToEnd(_result, &add);
    }
    v11 = _rhs->m_y1;
    if ( current.m_y1 >= v11 )
    {
      add.m_y0 = v11 + 1;
      add.m_y1 = current.m_y1;
      add.m_x0 = v5;
      add.m_x1 = v6;
      SmartArray<Box2D,1>::AddToEnd(_result, &add);
    }
    result = _result->m_num != 0;
  }
  return result;
}

//----- (00699670) --------------------------------------------------------  // acclient.c:689318
void __thiscall UIObject::AddDirtyRect(UIObject *this, Box2D *_rect)
{
  unsigned int v2; // edi@3
  int v3; // ebx@4
  Box2D *v4; // esi@5
  char *v5; // esi@12
  unsigned int v6; // eax@12
  unsigned int v7; // eax@13
  Box2D *v8; // eax@14
  unsigned int v9; // edi@18
  int v10; // esi@19
  UIObject *v11; // [sp+8h] [bp-10h]@1
  SmartArray<Box2D,1> pieces; // [sp+Ch] [bp-Ch]@8

  v11 = this;
  if ( _rect->m_x1 - _rect->m_x0 + 1 > 0 && _rect->m_y1 - _rect->m_y0 + 1 > 0 )
  {
    v2 = 0;
    if ( this->m_dirtyRects.m_num )
    {
      v3 = 0;
      while ( 1 )
      {
        v4 = &this->m_dirtyRects.m_data[v3];
        if ( (unsigned __int8)Box2D::Includes(&this->m_dirtyRects.m_data[v3], _rect) )
          break;
        if ( (unsigned __int8)Box2D::Includes(_rect, v4) )
        {
          SmartArray<Box2D,1>::RemoveUnOrderedByIndex(&v11->m_dirtyRects, v2--);
          --v3;
        }
        else
        {
          pieces.m_data = 0;
          pieces.m_sizeAndDeallocate = 0;
          pieces.m_num = 0;
          if ( Box2D::Subtract(_rect, v4, &pieces) )
          {
            v9 = 0;
            if ( pieces.m_num )
            {
              v10 = 0;
              do
              {
                UIObject::AddDirtyRect(v11, &pieces.m_data[v10]);
                ++v9;
                ++v10;
              }
              while ( v9 < pieces.m_num );
            }
            if ( (pieces.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
              operator delete[](pieces.m_data);
            return;
          }
          if ( (pieces.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
            operator delete[](pieces.m_data);
        }
        ++v2;
        ++v3;
        this = v11;
        if ( v2 >= v11->m_dirtyRects.m_num )
          goto LABEL_12;
      }
    }
    else
    {
LABEL_12:
      v5 = (char *)&this->m_dirtyRects;
      v6 = this->m_dirtyRects.m_sizeAndDeallocate & 0x7FFFFFFF;
      if ( this->m_dirtyRects.m_num < v6
        || (v7 = SmartArray<UIChildFramework *,1>::get_new_size(v6 + 1),
            SmartArray<Box2D,1>::grow((SmartArray<Box2D,1> *)v5, v7)) )
      {
        v8 = (Box2D *)(*(_DWORD *)v5 + 16 * *((_DWORD *)v5 + 2));
        if ( v8 != _rect )
          *v8 = *_rect;
        ++*((_DWORD *)v5 + 2);
      }
    }
  }
}

//----- (0071B430) --------------------------------------------------------  // acclient.c:813576
void sub_71B430()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F8F04, PFID_A8R8G8B8);
}

