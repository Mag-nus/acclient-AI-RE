/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_ListBox
   Object     : ENGINE\uielement_types\UIElement_ListBox.obj
   Functions  : 69
   Addresses  : 00401200 - 0075E770 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00401200) --------------------------------------------------------  // acclient.c:60932
void __thiscall SmartArray<char *,1>::~SmartArray<char *,1>(SmartArray<long,1> *this)
{
  if ( (this->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](this->m_data);
}

//----- (0046D510) --------------------------------------------------------  // acclient.c:170025
char __thiscall UIElement_ListBox::SetState(UIElement_ListBox *this, unsigned int _state)
{
  UIElement_ListBox *v2; // esi@1
  char v3; // al@1
  IInputActionCallbackVtbl *v4; // edi@1
  char v5; // bl@1
  int v6; // eax@1

  v2 = this;
  v3 = UIElement::SetState((UIElement *)&this->vfptr, _state);
  v4 = v2->vfptr;
  v5 = v3;
  v6 = ((int (__thiscall *)(UIElement_ListBox *))v2->vfptr[24].OnAction)(v2);
  ((void (__thiscall *)(UIElement_ListBox *, int))v4[22].OnLoseFocus)(v2, v6);
  return v5;
}

//----- (0046D540) --------------------------------------------------------  // acclient.c:170043
void __thiscall UIElement_ListBox::DrawStart(UIElement_ListBox *this)
{
  ((void (*)(void))this->vfptr[29].OnAction)();
}

//----- (0046D550) --------------------------------------------------------  // acclient.c:170049
void __thiscall UIElement_ListBox::ScrollToY(UIElement_ListBox *this, int i_iY)
{
  UIElement_Scrollable::SetScrollableXY((UIElement_Scrollable *)&this->vfptr, this->m_iScrollableX, i_iY, 0);
}

//----- (0046D570) --------------------------------------------------------  // acclient.c:170055
void __thiscall UIElement_ListBox::ScrollToX(UIElement_ListBox *this, int i_iX)
{
  UIElement_Scrollable::SetScrollableXY((UIElement_Scrollable *)&this->vfptr, i_iX, this->m_iScrollableY, 0);
}

//----- (0046D5B0) --------------------------------------------------------  // acclient.c:170070
void __thiscall UIElement_ListBox::SetHorizontal(UIElement_ListBox *this, const bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 1;
  else
    this->m_bitField = v2 & 0xFFFFFFFE;
}

//----- (0046D5E0) --------------------------------------------------------  // acclient.c:170082
void __thiscall UIElement_ListBox::SetClickSelect(UIElement_ListBox *this, const bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 2;
  else
    this->m_bitField = v2 & 0xFFFFFFFD;
}

//----- (0046D610) --------------------------------------------------------  // acclient.c:170094
void __thiscall UIElement_ListBox::SetDragSelect(UIElement_ListBox *this, const bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 4;
  else
    this->m_bitField = v2 & 0xFFFFFFFB;
}

//----- (0046D640) --------------------------------------------------------  // acclient.c:170106
void __thiscall UIElement_ListBox::SetDragRollover(UIElement_ListBox *this, const bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 8;
  else
    this->m_bitField = v2 & 0xFFFFFFF7;
}

//----- (0046D670) --------------------------------------------------------  // acclient.c:170118
void __thiscall UIElement_ListBox::SetSelectedItemStateChange(UIElement_ListBox *this, const bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 0x20;
  else
    this->m_bitField = v2 & 0xFFFFFFDF;
}

//----- (0046D6A0) --------------------------------------------------------  // acclient.c:170130
void __userpurge UIElement_ListBox::OnSetAttribute(UIElement_ListBox *this@<ecx>, int a2@<ebx>, BaseProperty *_attribute)
{
  BaseProperty *v3; // esi@1
  UIElement_ListBox *v4; // edi@1
  BasePropertyValue *v5; // ecx@2
  BasePropertyValue *v6; // ecx@6
  BasePropertyValue *v7; // ecx@9
  BasePropertyValue *v8; // ecx@12
  BasePropertyValue *v9; // ecx@15

  v3 = _attribute;
  v4 = this;
  UIElement_Scrollable::OnSetAttribute((UIElement_Scrollable *)&this->vfptr, a2, _attribute);
  switch ( BaseProperty::GetPropertyName(v3) )
  {
    case 0x5Cu:
      v5 = v3->m_pcPropertyValue;
      if ( v5 )
        ((void (__stdcall *)(BaseProperty **))v5->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement_ListBox::SetHorizontal(v4, (const bool)_attribute);
      goto $L100910;
    case 0x5Fu:
$L100910:
      v4->m_bitField |= 0x200u;
      UIRegion::MakeRootDirtyHere((UIRegion *)&v4->vfptr);
      break;
    default:
      return;
    case 0x59u:
      v6 = v3->m_pcPropertyValue;
      if ( v6 )
        ((void (__stdcall *)(BaseProperty **))v6->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement_ListBox::SetClickSelect(v4, (const bool)_attribute);
      break;
    case 0x5Bu:
      v7 = v3->m_pcPropertyValue;
      if ( v7 )
        ((void (__stdcall *)(BaseProperty **))v7->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement_ListBox::SetDragSelect(v4, (const bool)_attribute);
      break;
    case 0x5Au:
      v8 = v3->m_pcPropertyValue;
      if ( v8 )
        ((void (__stdcall *)(BaseProperty **))v8->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement_ListBox::SetDragRollover(v4, (const bool)_attribute);
      break;
    case 0x61u:
      v9 = v3->m_pcPropertyValue;
      if ( v9 )
        ((void (__stdcall *)(BaseProperty **))v9->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement_ListBox::SetSelectedItemStateChange(v4, (const bool)_attribute);
      break;
  }
}

//----- (0046D7B0) --------------------------------------------------------  // acclient.c:170186
void __thiscall UIElement_ListBox::ResizeTo(UIElement_ListBox *this, const int _width, const int _height)
{
  UIElement_ListBox *v3; // esi@1
  int v4; // edi@1
  int v5; // ebx@1

  v3 = this;
  v4 = UIRegion::GetWidth((UIRegion *)&this->vfptr);
  v5 = UIRegion::GetHeight((UIRegion *)&v3->vfptr);
  UIElement_Scrollable::ResizeTo((UIElement_Scrollable *)&v3->vfptr, _width, _height);
  if ( v4 != UIRegion::GetWidth((UIRegion *)&v3->vfptr) || v5 != UIRegion::GetHeight((UIRegion *)&v3->vfptr) )
  {
    v3->m_bitField |= 0x200u;
    UIRegion::MakeRootDirtyHere((UIRegion *)&v3->vfptr);
  }
}

//----- (0046D810) --------------------------------------------------------  // acclient.c:170204
void __thiscall UIElement_ListBox::UpdateForChildSizeChange(UIElement_ListBox *this, UIElement *i_pcChild)
{
  this->m_bitField |= 0x200u;
  UIRegion::MakeRootDirtyHere((UIRegion *)&this->vfptr);
}

//----- (0046D830) --------------------------------------------------------  // acclient.c:170211
int __thiscall UIElement_ListBox::CalculatePaperSize(UIElement_ListBox *this, bool i_bWidth, int i_iMax)
{
  UIElement_ListBox *v3; // esi@1
  unsigned int v4; // eax@1
  int v5; // edx@3
  int v6; // ecx@6
  int result; // eax@8
  int v8; // ecx@9

  v3 = this;
  v4 = this->m_bitField;
  if ( BYTE1(v4) & 2 )
    ((void (*)(void))this->vfptr[29].OnAction)();
  v5 = i_iMax;
  if ( i_iMax != -1 )
  {
LABEL_6:
    v6 = (int)&v3->m_nItemWidths;
    if ( i_bWidth )
      goto LABEL_8;
    goto LABEL_7;
  }
  if ( i_bWidth )
  {
    v5 = v3->m_nCols;
    goto LABEL_6;
  }
  v5 = v3->m_nRows;
LABEL_7:
  v6 = (int)&v3->m_nItemHeights;
LABEL_8:
  result = 0;
  if ( v5 > 0 )
  {
    v8 = *(_DWORD *)v6;
    do
    {
      result += *(_DWORD *)v8;
      v8 += 4;
      --v5;
    }
    while ( v5 );
  }
  return result;
}

//----- (0046D890) --------------------------------------------------------  // acclient.c:170258
UIElement *__thiscall UIElement_ListBox::GetItem(UIElement_ListBox *this, unsigned int _index)
{
  UIElement *result; // eax@2

  if ( _index >= this->m_listItems.m_num )
    result = 0;
  else
    result = this->m_listItems.m_data[_index];
  return result;
}

//----- (0046D8B0) --------------------------------------------------------  // acclient.c:170270
void __thiscall UIElement_ListBox::SetSelectedItem(UIElement_ListBox *this, UIElement *_pNewSelected, bool _bBroadcast)
{
  UIElement_ListBox *v3; // esi@1
  UIElement *v4; // edi@1
  unsigned int v5; // ecx@4
  unsigned int v6; // eax@4
  UIElement **v7; // edx@5
  unsigned int v8; // ebp@8

  v3 = this;
  v4 = this->m_pSelectedItem;
  if ( v4 == _pNewSelected )
  {
    if ( _bBroadcast )
      UIElement::BroadcastElementMessage((UIElement *)&this->vfptr, 0x43u, (unsigned int)v4, 0);
    return;
  }
  v5 = this->m_listItems.m_num;
  v6 = 0;
  if ( v5 )
  {
    v7 = v3->m_listItems.m_data;
    while ( *v7 != _pNewSelected )
    {
      ++v6;
      ++v7;
      if ( v6 >= v5 )
        goto LABEL_8;
    }
    v8 = v6;
    if ( v6 != -1 )
    {
      v3->m_pSelectedItem = _pNewSelected;
      goto LABEL_10;
    }
  }
  else
  {
LABEL_8:
    v8 = -1;
  }
  v3->m_pSelectedItem = 0;
LABEL_10:
  if ( v3->m_bitField & 0x20 )
  {
    if ( v4 )
    {
      UIElement::GetAttribute_Enum((UIElement *)&v3->vfptr, 0x5Du, (unsigned int *)&_pNewSelected);
      v4->vfptr[13].__vecDelDtor((IInputActionCallback *)v4, (unsigned int)_pNewSelected);
    }
    if ( v3->m_pSelectedItem )
    {
      UIElement::GetAttribute_Enum((UIElement *)&v3->vfptr, 0x5Eu, (unsigned int *)&_pNewSelected);
      ((void (__stdcall *)(UIElement *))v3->m_pSelectedItem->vfptr[13].__vecDelDtor)(_pNewSelected);
    }
  }
  if ( _bBroadcast )
    UIElement::BroadcastElementMessage((UIElement *)&v3->vfptr, 4u, v8, (unsigned int)v3->m_pSelectedItem);
}

//----- (0046D9A0) --------------------------------------------------------  // acclient.c:170331
char __thiscall UIElement_ListBox::InqItemIndexAtPoint(UIElement_ListBox *this, int i_iX, int i_iY, unsigned int *o_iIndex)
{
  UIElement_ListBox *v4; // esi@1
  int v5; // edi@6
  unsigned int v6; // ecx@6
  int v7; // ebx@6
  int v8; // edx@6
  int v9; // eax@6
  int *v10; // ebp@7
  unsigned int v11; // edi@12
  int v12; // ecx@12
  int v13; // eax@12
  int *v14; // edx@13
  int v15; // eax@19
  int v16; // ecx@19
  unsigned int v17; // eax@21
  char result; // al@22
  int i_iXa; // [sp+14h] [bp+4h]@6
  int iColumn; // [sp+18h] [bp+8h]@6

  v4 = this;
  if ( this->m_listItems.m_num && i_iX >= 0 && i_iX < UIRegion::GetWidth((UIRegion *)&this->vfptr) )
  {
    if ( i_iY < 0 || i_iY >= UIRegion::GetHeight((UIRegion *)&v4->vfptr) )
      goto LABEL_27;
    ((void (__thiscall *)(UIElement_ListBox *))v4->vfptr[29].OnAction)(v4);
    v5 = v4->m_iScrollableX + i_iX;
    v6 = v4->m_nItemWidths.m_num;
    v7 = v4->m_iScrollableY + i_iY;
    v8 = 0;
    v9 = 0;
    i_iXa = 0;
    iColumn = 0;
    if ( v6 > 0 )
    {
      v10 = v4->m_nItemWidths.m_data;
      while ( 1 )
      {
        v8 += *v10;
        if ( v5 <= v8 )
          break;
        ++v9;
        ++v10;
        if ( v9 >= v6 )
          goto LABEL_12;
      }
      i_iXa = v9;
    }
LABEL_12:
    v11 = v4->m_nItemHeights.m_num;
    v12 = 0;
    v13 = 0;
    if ( v11 )
    {
      v14 = v4->m_nItemHeights.m_data;
      while ( 1 )
      {
        v12 += *v14;
        if ( v7 <= v12 )
          break;
        ++v13;
        ++v14;
        if ( v13 >= v11 )
          goto LABEL_18;
      }
      iColumn = v13;
    }
LABEL_18:
    if ( v4->m_bitField & 1 )
    {
      v15 = iColumn * v4->m_nCols;
      v16 = i_iXa;
    }
    else
    {
      v15 = i_iXa * v4->m_nRows;
      v16 = iColumn;
    }
    v17 = v16 + v15;
    if ( v17 >= v4->m_listItems.m_num )
    {
LABEL_27:
      result = 0;
    }
    else
    {
      *o_iIndex = v17;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046DAC0) --------------------------------------------------------  // acclient.c:170429
UIElement *__thiscall UIElement_ListBox::RemoveItem(UIElement_ListBox *this, unsigned int _itemIndex)
{
  UIElement_ListBox *v2; // esi@1
  UIElement *v3; // edi@2
  SmartArray<UIElement *,1> *v4; // ecx@2
  UIElement *result; // eax@9

  v2 = this;
  if ( _itemIndex < this->m_listItems.m_num && (v3 = this->m_listItems.m_data[_itemIndex], v4 = &this->m_listItems, v3) )
  {
    SmartArray<UIElement *,1>::RemoveOrderedByIndex(v4, _itemIndex);
    v2->m_bitField |= 0x200u;
    UIRegion::MakeRootDirtyHere((UIRegion *)&v2->vfptr);
    ((void (__thiscall *)(UIElement *, _DWORD))v3->vfptr[5].OnLoseFocus)(v3, 0);
    if ( v3 == v2->m_pSelectedItem )
      v2->m_pSelectedItem = 0;
    if ( v3 == v2->m_dragLastOver )
      v2->m_dragLastOver = 0;
    if ( v3 == v2->m_itemDragged )
      v2->m_itemDragged = 0;
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046DB50) --------------------------------------------------------  // acclient.c:170459
void __thiscall UIElement_ListBox::StartDragSelect(UIElement_ListBox *this)
{
  UIElement_ListBox *v1; // esi@1

  v1 = this;
  if ( !(this->m_bitField & 0x40) && ICIDM::s_cidm && CInputManager::IsActionInProgress(ICIDM::s_cidm, 7u) )
  {
    UIElementManager::SetMouseCapture(UIElementManager::s_pInstance, (UIElement *)&v1->vfptr);
    v1->m_bitField |= 0x40u;
  }
}

//----- (0046DB90) --------------------------------------------------------  // acclient.c:170472
void __thiscall UIElement_ListBox::StartRollover(UIElement_ListBox *this)
{
  unsigned int v1; // eax@1

  v1 = this->m_bitField;
  if ( v1 & 8 )
  {
    if ( !(BYTE1(v1) & 1) )
      this->m_bitField = v1 | 0x100;
  }
}

//----- (0046DBB0) --------------------------------------------------------  // acclient.c:170485
void __thiscall UIElement_ListBox::EndRollover(UIElement_ListBox *this)
{
  UIElement_ListBox *v1; // esi@1
  unsigned int v2; // eax@1
  UIElement *v3; // ecx@2

  v1 = this;
  v2 = this->m_bitField;
  if ( BYTE1(v2) & 1 )
  {
    this->m_bitField = v2 & 0xFFFFFEFF;
    v3 = this->m_dragLastOver;
    if ( v3 )
    {
      ((void (__stdcall *)(_DWORD))v3->vfptr[13].__vecDelDtor)(v1->m_lastDragOverState);
      v1->m_dragLastOver = 0;
    }
  }
}

//----- (0046DC00) --------------------------------------------------------  // acclient.c:170506
void __thiscall UIElement_ListBox::AdjustToScrollableXYChange(UIElement_ListBox *this)
{
  this->m_bitField |= 0x200u;
  UIRegion::MakeRootDirtyHere((UIRegion *)&this->vfptr);
}

//----- (0046DC10) --------------------------------------------------------  // acclient.c:170513
int __thiscall UIElement_ListBox::InqScrollDelta(UIElement_ListBox *this, bool i_bHorizontal, bool i_bIncrement, bool i_bPage)
{
  int result; // eax@1
  int v5; // edx@5
  int v6; // esi@6
  int v7; // eax@10
  int v8; // esi@10
  int v9; // esi@12
  int v10; // eax@13
  bool v11; // sf@15
  unsigned __int8 v12; // of@15
  bool *v13; // eax@15

  result = 0;
  if ( i_bPage )
  {
    if ( i_bHorizontal )
      result = UIRegion::GetWidth((UIRegion *)&this->vfptr);
    else
      result = UIRegion::GetHeight((UIRegion *)&this->vfptr);
  }
  else
  {
    v5 = 0;
    if ( i_bHorizontal )
      v6 = this->m_nCols;
    else
      v6 = this->m_nRows;
    LOBYTE(v5) = v6 != 0;
    if ( v5 )
    {
      if ( i_bHorizontal )
      {
        v7 = this->m_iScrollableWidth;
        v8 = this->m_nCols;
      }
      else
      {
        v7 = this->m_iScrollableHeight;
        v8 = this->m_nRows;
      }
      v9 = v7 / v8;
      *(_DWORD *)&i_bPage = v9;
      if ( i_bHorizontal )
        v10 = UIRegion::GetWidth((UIRegion *)&this->vfptr);
      else
        v10 = UIRegion::GetHeight((UIRegion *)&this->vfptr);
      *(_DWORD *)&i_bHorizontal = v10;
      v12 = __OFSUB__(v9, v10);
      v11 = v9 - v10 < 0;
      v13 = &i_bPage;
      if ( !(v11 ^ v12) )
        v13 = &i_bHorizontal;
      result = *(_DWORD *)v13;
    }
  }
  if ( i_bIncrement )
    result = -result;
  return result;
}

//----- (0046DCB0) --------------------------------------------------------  // acclient.c:170575
void __userpurge UIElement_ListBox::UIElement_ListBox(UIElement_ListBox *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_ListBox *v4; // esi@1

  v4 = this;
  UIElement_Scrollable::UIElement_Scrollable((UIElement_Scrollable *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement_ListBox::vftable;
  v4->m_listItems.m_data = 0;
  v4->m_listItems.m_sizeAndDeallocate = 0;
  v4->m_listItems.m_num = 0;
  v4->m_pSelectedItem = 0;
  v4->m_dragLastOver = 0;
  v4->m_lastDragOverState = 0;
  v4->m_nCols = 0;
  v4->m_nRows = 0;
  v4->m_nItemHeights.m_data = 0;
  v4->m_nItemHeights.m_sizeAndDeallocate = 0;
  v4->m_nItemHeights.m_num = 0;
  v4->m_nItemWidths.m_data = 0;
  v4->m_nItemWidths.m_sizeAndDeallocate = 0;
  v4->m_nItemWidths.m_num = 0;
  LODWORD(v4->m_nAnimStartTime) = 0;
  HIDWORD(v4->m_nAnimStartTime) = 0;
  LODWORD(v4->m_nAnimEndTime) = 0;
  HIDWORD(v4->m_nAnimEndTime) = 0;
  v4->m_nAnimStartX = 0;
  v4->m_nAnimStartY = 0;
  v4->m_nAnimEndX = 0;
  v4->m_nAnimEndY = 0;
  v4->m_bitField = 656;
}
// 79CD68: using guessed type int (__thiscall *UIElement_ListBox::vftable)(void *, char);

//----- (0046DD60) --------------------------------------------------------  // acclient.c:170609
UIElement_ListBox *__thiscall UIElement_ListBox::DynamicCast(UIElement_ListBox *this, unsigned int i_eType)
{
  UIElement_ListBox *result; // eax@1

  result = this;
  if ( i_eType != 5 )
    result = (UIElement_ListBox *)(i_eType != 10 ? 0 : (unsigned int)this);
  return result;
}

//----- (0046DD80) --------------------------------------------------------  // acclient.c:170620
void __thiscall UIElement_ListBox::~UIElement_ListBox(UIElement_ListBox *this)
{
  UIElement_ListBox *v1; // esi@1
  bool v2; // zf@1
  unsigned int v3; // eax@3
  UIElement *v4; // ecx@4

  v1 = this;
  v2 = (this->m_bitField & 0x40) == 0;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_ListBox::vftable;
  if ( !v2 )
    this->m_bitField &= 0xFFFFFFBF;
  v3 = this->m_bitField;
  if ( BYTE1(v3) & 1 )
  {
    this->m_bitField = v3 & 0xFFFFFEFF;
    v4 = this->m_dragLastOver;
    if ( v4 )
    {
      ((void (__stdcall *)(_DWORD))v4->vfptr[13].__vecDelDtor)(v1->m_lastDragOverState);
      v1->m_dragLastOver = 0;
    }
  }
  if ( (v1->m_nItemWidths.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_nItemWidths.m_data);
  if ( (v1->m_nItemHeights.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_nItemHeights.m_data);
  if ( (v1->m_listItems.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_listItems.m_data);
  UIElement_Scrollable::~UIElement_Scrollable((UIElement_Scrollable *)&v1->vfptr);
}
// 79CD68: using guessed type int (__thiscall *UIElement_ListBox::vftable)(void *, char);

//----- (0046DE50) --------------------------------------------------------  // acclient.c:170654
void __usercall UIElement_ListBox::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_ListBox *v3; // eax@1

  v3 = (UIElement_ListBox *)operator new(0x668u);
  if ( v3 )
    UIElement_ListBox::UIElement_ListBox(v3, a1, _layout, _full_desc);
}

//----- (0046DE80) --------------------------------------------------------  // acclient.c:170664
char __thiscall UIElement_ListBox::InqAvailableProperties(UIElement_ListBox *this, AvailablePropertySet *_set)
{
  AvailablePropertySet *v2; // edi@1
  char v3; // bl@1
  AvailablePropertySet *v4; // esi@3
  char result; // al@4

  v2 = _set;
  v3 = 1;
  if ( !UIElement_Scrollable::InqAvailableProperties((UIElement_Scrollable *)&this->vfptr, _set) )
    v3 = 0;
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&_set);
  v4 = _set;
  if ( _set )
  {
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)_set, 0xCu, v2) )
      v3 = 0;
    ((void (__thiscall *)(AvailablePropertySet *))v4->m_reqHash.vfptr[5].__vecDelDtor)(v4);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046DED0) --------------------------------------------------------  // acclient.c:170692
void __thiscall UIElement_ListBox::MouseOverTop(UIElement_ListBox *this, bool _bOverTop)
{
  bool v2; // bl@1
  UIElement_ListBox *v3; // esi@1
  unsigned int v4; // eax@2

  v2 = _bOverTop;
  v3 = this;
  UIElement::MouseOverTop((UIElement *)&this->vfptr, _bOverTop);
  if ( v2 )
  {
    v4 = v3->m_bitField;
    if ( !(BYTE1(v4) & 1) && UIElementManager::s_pInstance && UIElementManager::s_pInstance->m_dragElement )
    {
      UIElement::GetAttribute_Bool((UIElement *)&v3->vfptr, 0x36u, &_bOverTop);
      if ( _bOverTop )
        UIElement_ListBox::StartRollover(v3);
    }
  }
}

//----- (0046DF30) --------------------------------------------------------  // acclient.c:170714
void __thiscall UIElement_ListBox::MouseUp(UIElement_ListBox *this, unsigned int _xWindow, unsigned int _yWindow, unsigned int _button)
{
  UIElement_ListBox *v4; // esi@1
  unsigned int v5; // eax@3
  UIElement *v6; // ecx@4

  v4 = this;
  UIElement::MouseUp((UIElement *)&this->vfptr, _xWindow, _yWindow, _button);
  if ( v4->m_bitField & 0x40 )
    v4->m_bitField &= 0xFFFFFFBF;
  v5 = v4->m_bitField;
  if ( BYTE1(v5) & 1 )
  {
    v4->m_bitField = v5 & 0xFFFFFEFF;
    v6 = v4->m_dragLastOver;
    if ( v6 )
    {
      ((void (__stdcall *)(unsigned int))v6->vfptr[13].__vecDelDtor)(v4->m_lastDragOverState);
      v4->m_dragLastOver = 0;
    }
  }
}

//----- (0046DFA0) --------------------------------------------------------  // acclient.c:170738
UIElement *__thiscall UIElement_ListBox::GetItemAtPoint(UIElement_ListBox *this, int _scrX, int _scrY)
{
  UIElement_ListBox *v3; // esi@1
  UIElement *result; // eax@2

  v3 = this;
  if ( UIElement_ListBox::InqItemIndexAtPoint(this, _scrX, _scrY, (unsigned int *)&_scrY) )
    result = v3->m_listItems.m_data[_scrY];
  else
    result = 0;
  return result;
}

//----- (0046DFE0) --------------------------------------------------------  // acclient.c:170752
unsigned int __thiscall UIElement_ListBox::RemoveItem(UIElement_ListBox *this, UIElement *_item)
{
  unsigned int result; // eax@1
  unsigned int v3; // esi@2
  UIElement **v4; // edx@3

  result = 0;
  if ( _item )
  {
    v3 = this->m_listItems.m_num;
    if ( v3 )
    {
      v4 = this->m_listItems.m_data;
      while ( *v4 != _item )
      {
        ++result;
        ++v4;
        if ( result >= v3 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      result = -1;
    }
    result = (unsigned int)UIElement_ListBox::RemoveItem(this, result);
  }
  return result;
}

//----- (0046E020) --------------------------------------------------------  // acclient.c:170784
char __thiscall UIElement_ListBox::DeleteItem(UIElement_ListBox *this, UIElement *_pItem)
{
  unsigned int v2; // esi@2
  unsigned int v3; // eax@2
  UIElement **v4; // edx@3
  UIElement *v5; // eax@7
  char result; // al@8

  if ( !_pItem )
    goto LABEL_12;
  v2 = this->m_listItems.m_num;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->m_listItems.m_data;
    while ( *v4 != _pItem )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v3 = -1;
  }
  v5 = UIElement_ListBox::RemoveItem(this, v3);
  if ( v5 )
  {
    UIElement::AddToDeleteQueue(v5);
    result = 1;
  }
  else
  {
LABEL_12:
    result = 0;
  }
  return result;
}

//----- (0046E070) --------------------------------------------------------  // acclient.c:170827
char __thiscall UIElement_ListBox::DeleteItem(UIElement_ListBox *this, int _itemIndex)
{
  UIElement *v2; // eax@2
  char result; // al@3

  if ( _itemIndex < this->m_listItems.m_num && (v2 = this->m_listItems.m_data[_itemIndex]) != 0 )
    result = UIElement_ListBox::DeleteItem(this, v2);
  else
    result = 0;
  return result;
}

//----- (0046E0A0) --------------------------------------------------------  // acclient.c:170840
void __thiscall UIElement_ListBox::Flush(UIElement_ListBox *this)
{
  UIElement_ListBox *v1; // esi@1
  unsigned int v2; // edi@1
  UIElement *v3; // ecx@2
  unsigned int v4; // eax@5
  unsigned int v5; // ecx@5
  int i; // eax@8

  v1 = this;
  v2 = 0;
  if ( this->m_listItems.m_num )
  {
    do
    {
      v3 = v1->m_listItems.m_data[v2];
      if ( v3 )
        UIElement::AddToDeleteQueue(v3);
      ++v2;
    }
    while ( v2 < v1->m_listItems.m_num );
  }
  v4 = v1->m_listItems.m_sizeAndDeallocate;
  v5 = v1->m_listItems.m_sizeAndDeallocate & 0x80000000;
  v1->m_listItems.m_num = 0;
  if ( v5 == 0x80000000 )
  {
    operator delete[](v1->m_listItems.m_data);
    v1->m_listItems.m_data = 0;
    v1->m_listItems.m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_listItems.m_data )
  {
    for ( i = (v4 & 0x7FFFFFFF) - 1; i >= 0; v1->m_listItems.m_data[i + 1] = 0 )
      --i;
  }
  v1->m_pSelectedItem = 0;
  v1->m_dragLastOver = 0;
  v1->m_bitField |= 0x200u;
  UIRegion::MakeRootDirtyHere((UIRegion *)&v1->vfptr);
}

//----- (0046E160) --------------------------------------------------------  // acclient.c:170883
UIElement_ListBox *__thiscall UIElement_ListBox::vector_deleting_destructor(UIElement_ListBox *this, unsigned int a2)
{
  UIElement_ListBox *v2; // esi@1

  v2 = this;
  UIElement_ListBox::~UIElement_ListBox(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0046E180) --------------------------------------------------------  // acclient.c:170895
void __cdecl UIElement_ListBox::Register()
{
  UIElement::RegisterElementClass(5u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_ListBox::Create);
}

//----- (0046E190) --------------------------------------------------------  // acclient.c:170901
void __thiscall UIElement_ListBox::InitializeWidthHeightArray(UIElement_ListBox *this, bool i_bWidth)
{
  int v2; // edi@2
  char *v3; // esi@2
  int i; // eax@7
  int j; // eax@10

  if ( i_bWidth )
  {
    v2 = this->m_nCols;
    v3 = (char *)&this->m_nItemWidths;
  }
  else
  {
    v2 = this->m_nRows;
    v3 = (char *)&this->m_nItemHeights;
  }
  if ( (*((_DWORD *)v3 + 1) & 0x7FFFFFFFu) >= v2 )
  {
    for ( i = v2; (unsigned int)i < *((_DWORD *)v3 + 2); ++i )
      *(_DWORD *)(*(_DWORD *)v3 + 4 * i) = 0;
  }
  else if ( !SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v3, v2) )
  {
    goto LABEL_10;
  }
  *((_DWORD *)v3 + 2) = v2;
LABEL_10:
  for ( j = 0; j < v2; ++j )
    *(_DWORD *)(*(_DWORD *)v3 + 4 * j) = 0;
}

//----- (0046E220) --------------------------------------------------------  // acclient.c:170934
UIElement *__thiscall UIElement_ListBox::GetItemUnderMouse(UIElement_ListBox *this)
{
  UIElement_ListBox *v1; // esi@1
  UIElement *result; // eax@1
  int v3; // edi@2
  int v4; // edi@2
  int v5; // ebx@2
  unsigned int v6; // eax@2
  UIElement *v7; // ebp@2
  unsigned int o_iIndex; // [sp+0h] [bp-4h]@1

  o_iIndex = (unsigned int)this;
  v1 = this;
  result = 0;
  if ( (*((_DWORD *)&this->0 + 41) >> 4) & 1 )
  {
    v3 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseX)();
    v4 = v3 - UIRegion::GetScreenX0((UIRegion *)&v1->vfptr);
    v5 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseY)();
    v6 = UIRegion::GetScreenY0((UIRegion *)&v1->vfptr);
    v7 = 0;
    if ( UIElement_ListBox::InqItemIndexAtPoint(v1, v4, v5 - v6, &o_iIndex) )
      v7 = v1->m_listItems.m_data[o_iIndex];
    result = v7;
  }
  return result;
}

//----- (0046E290) --------------------------------------------------------  // acclient.c:170963
void __thiscall UIElement_ListBox::Rollover(UIElement_ListBox *this)
{
  UIElement_ListBox *v1; // esi@1
  UIElement *v2; // edi@2
  signed int v3; // ebp@5
  UIElement *v4; // eax@7
  UIElement *v5; // ecx@7
  UIElement *v6; // edi@7
  unsigned int v7; // eax@11
  UIElement_ListBox *v8; // [sp-2h] [bp-4h]@1

  v8 = this;
  v1 = this;
  if ( UIElementManager::s_pInstance )
  {
    v2 = UIElementManager::s_pInstance->m_dragElement;
    if ( v2 )
    {
      BYTE3(v8) = 0;
      UIElement::GetAttribute_Bool((UIElement *)&this->vfptr, 0x38u, (bool *)&v8 + 3);
      if ( !v1->m_dragDropCallback(v2, (UIElement *)v1) || (v3 = 9, BYTE3(v8)) )
        v3 = 10;
      v4 = UIElement_ListBox::GetItemUnderMouse(v1);
      v5 = v1->m_dragLastOver;
      v6 = v4;
      if ( v5 != v4 )
      {
        if ( v5 )
        {
          ((void (__stdcall *)(unsigned int))v5->vfptr[13].__vecDelDtor)(v1->m_lastDragOverState);
          v1->m_dragLastOver = 0;
        }
        if ( v6 )
        {
          v7 = v6->m_state;
          if ( v3 != v7 )
          {
            v1->m_lastDragOverState = v7;
            v1->m_dragLastOver = v6;
            v6->vfptr[13].__vecDelDtor((IInputActionCallback *)v6, v3);
          }
        }
      }
    }
    else
    {
      UIElement_ListBox::EndRollover(this);
    }
  }
}

//----- (0046E350) --------------------------------------------------------  // acclient.c:171015
int __thiscall UIElement_ListBox::ListenToElementMessage(UIElement_ListBox *this, UIElementMessageInfo *i_rMsg)
{
  UIElement_ListBox *v2; // esi@1
  UIElement *v3; // eax@4

  v2 = this;
  if ( i_rMsg->idMessage == 28 && i_rMsg->dwParam1 == 7 )
  {
    if ( this->m_bitField & 2 )
    {
      v3 = UIElement_ListBox::GetItemUnderMouse(this);
      if ( v3 )
      {
        UIElement_ListBox::SetSelectedItem(v2, v3, 1);
        if ( v2->m_bitField & 4 )
          UIElement_ListBox::StartDragSelect(v2);
      }
    }
  }
  return UIElement_Scrollable::ListenToElementMessage((UIElement_Scrollable *)&v2->vfptr, i_rMsg);
}

//----- (0046E3A0) --------------------------------------------------------  // acclient.c:171038
void __thiscall UIElement_ListBox::MouseDown(UIElement_ListBox *this, unsigned int _x, unsigned int _y, unsigned int _button)
{
  UIElement_ListBox *v4; // esi@1
  UIElement *v5; // eax@6

  v4 = this;
  UIElement_Scrollable::MouseDown((UIElement_Scrollable *)&this->vfptr, _x, _y, _button);
  if ( !((v4->m_nFlags >> 19) & 1) && !((v4->m_nFlags >> 18) & 1) && (_button == 7 || _button == 10) )
  {
    if ( v4->m_bitField & 2 )
    {
      v5 = UIElement_ListBox::GetItemUnderMouse(v4);
      if ( v5 )
      {
        UIElement_ListBox::SetSelectedItem(v4, v5, 1);
        if ( v4->m_bitField & 4 )
          UIElement_ListBox::StartDragSelect(v4);
      }
    }
  }
}

//----- (0046E410) --------------------------------------------------------  // acclient.c:171061
void __userpurge UIElement_ListBox::MouseMove(UIElement_ListBox *this@<ecx>, int a2@<edi>, int i_xWindow, int i_yWindow)
{
  UIElement_ListBox *v4; // esi@1
  UIElement *v5; // eax@2
  unsigned int v6; // eax@5

  v4 = this;
  UIElement::MouseMove((UIElement *)&this->vfptr, a2, i_xWindow, i_yWindow);
  if ( v4->m_bitField & 0x40 )
  {
    v5 = UIElement_ListBox::GetItemUnderMouse(v4);
    if ( v5 )
    {
      if ( v5 != v4->m_pSelectedItem )
        UIElement_ListBox::SetSelectedItem(v4, v5, 1);
    }
  }
  v6 = v4->m_bitField;
  if ( BYTE1(v6) & 1 )
    UIElement_ListBox::Rollover(v4);
}

//----- (0046E460) --------------------------------------------------------  // acclient.c:171084
void __thiscall UIElement_ListBox::UpdateLayout(UIElement_ListBox *this)
{
  UIElement_ListBox *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // edi@2
  int v4; // ebp@2
  void *v5; // eax@4
  int v6; // eax@6
  bool v7; // sf@6
  unsigned __int8 v8; // of@6
  void *v9; // eax@6
  unsigned int v10; // eax@8
  unsigned __int64 v11; // rax@9
  unsigned int v12; // eax@12
  int v13; // ebx@12
  UIElement **v14; // edx@13
  UIRegion *v15; // edi@13
  int v16; // eax@14
  int *v17; // ecx@14
  int v18; // edx@14
  int v19; // ecx@14
  int *v20; // eax@14
  int v21; // eax@16
  int *v22; // ecx@16
  int v23; // edx@16
  int v24; // ecx@16
  int *v25; // eax@16
  unsigned int v26; // eax@23
  int v27; // ebp@23
  int v28; // ebx@27
  int v29; // edi@27
  int *v30; // eax@28
  unsigned int v31; // eax@30
  int v32; // ebp@30
  int v33; // eax@34
  int *v34; // ecx@35
  unsigned int v35; // eax@37
  int v36; // ebp@37
  int v37; // edi@37
  int nMaxColumns; // [sp+18h] [bp-14h]@2
  int nCurrentColumn; // [sp+1Ch] [bp-10h]@14
  unsigned int nIndex; // [sp+20h] [bp-Ch]@4
  unsigned int nNum; // [sp+24h] [bp-8h]@2
  UIElement *curItem; // [sp+28h] [bp-4h]@10

  v1 = this;
  v2 = this->m_bitField;
  if ( BYTE1(v2) & 2 )
  {
    this->m_bitField = v2 & 0xFFFFFDFF;
    UIRegion::MakeRootDirtyHere((UIRegion *)&this->vfptr);
    v3 = v1->m_listItems.m_num;
    v4 = 0;
    nNum = v1->m_listItems.m_num;
    nMaxColumns = 0;
    UIElement::GetAttribute_Int((UIElement *)&v1->vfptr, 0x5Fu, &nMaxColumns);
    if ( nMaxColumns >= 0 )
    {
      nIndex = 1;
      v5 = &nIndex;
      if ( nMaxColumns >= 1 )
        v5 = &nMaxColumns;
      v6 = *(_DWORD *)v5;
      nMaxColumns = v6;
      v8 = __OFSUB__(v6, v3);
      v7 = ((v6 - v3) & 0x80000000) != 0;
      nIndex = v3;
      v9 = &nMaxColumns;
      if ( !(v7 ^ v8) )
        v9 = &nIndex;
      v10 = *(_DWORD *)v9;
      nIndex = v10;
      v1->m_nCols = v10;
      if ( v10 )
      {
        curItem = (UIElement *)v3;
        v11 = (unsigned __int64)_ceil((double)v3 / (double)(signed int)nIndex);
      }
      else
      {
        LODWORD(v11) = 0;
      }
      v1->m_nRows = v11;
    }
    else
    {
      v1->m_nCols = v3;
      v1->m_nRows = v3 != 0;
    }
    UIElement_ListBox::InitializeWidthHeightArray(v1, 1);
    UIElement_ListBox::InitializeWidthHeightArray(v1, 0);
    v12 = 0;
    v13 = 0;
    nIndex = 0;
    if ( v3 > 0 )
    {
      do
      {
        v14 = v1->m_listItems.m_data;
        v15 = (UIRegion *)&v14[v12]->vfptr;
        if ( v15 )
        {
          v16 = UIRegion::GetWidth((UIRegion *)&v14[v12]->vfptr);
          v17 = v1->m_nItemWidths.m_data;
          v18 = v17[v13];
          v19 = (int)&v17[v13];
          nCurrentColumn = v16;
          v8 = __OFSUB__(v18, v16);
          v7 = v18 - v16 < 0;
          v20 = &nCurrentColumn;
          if ( !(v7 ^ v8) )
            v20 = (int *)v19;
          *(_DWORD *)v19 = *v20;
          v21 = UIRegion::GetHeight(v15);
          v22 = v1->m_nItemHeights.m_data;
          v23 = v22[v4];
          v24 = (int)&v22[v4];
          nCurrentColumn = v21;
          v8 = __OFSUB__(v23, v21);
          v7 = v23 - v21 < 0;
          v25 = &nCurrentColumn;
          if ( !(v7 ^ v8) )
            v25 = (int *)v24;
          *(_DWORD *)v24 = *v25;
          if ( v1->m_bitField & 1 )
          {
            if ( v13 != v1->m_nCols - 1 )
              goto LABEL_48;
            v13 = 0;
          }
          else if ( v4 == v1->m_nRows - 1 )
          {
            v4 = 0;
LABEL_48:
            ++v13;
            goto LABEL_22;
          }
          ++v4;
        }
LABEL_22:
        v12 = nIndex++ + 1;
      }
      while ( nIndex < nNum );
    }
    v26 = v1->m_bitField;
    v27 = v1->m_nCols;
    if ( BYTE1(v26) & 2 )
      ((void (__thiscall *)(UIElement_ListBox *))v1->vfptr[29].OnAction)(v1);
    if ( v27 == -1 )
      v27 = v1->m_nCols;
    v28 = 0;
    v29 = 0;
    if ( v27 > 0 )
    {
      v30 = v1->m_nItemWidths.m_data;
      do
      {
        v29 += *v30;
        ++v30;
        --v27;
      }
      while ( v27 );
    }
    v31 = v1->m_bitField;
    v32 = v1->m_nRows;
    if ( BYTE1(v31) & 2 )
      ((void (__thiscall *)(UIElement_ListBox *))v1->vfptr[29].OnAction)(v1);
    if ( v32 == -1 )
      v32 = v1->m_nRows;
    v33 = 0;
    if ( v32 > 0 )
    {
      v34 = v1->m_nItemHeights.m_data;
      do
      {
        v33 += *v34;
        ++v34;
        --v32;
      }
      while ( v32 );
    }
    UIElement_Scrollable::ResizeScrollableArea((UIElement_Scrollable *)&v1->vfptr, v29, v33);
    v35 = 0;
    v36 = -v1->m_iScrollableX;
    v37 = -v1->m_iScrollableY;
    nCurrentColumn = 0;
    nIndex = 0;
    if ( nNum )
    {
      do
      {
        curItem = v1->m_listItems.m_data[v35];
        if ( !curItem || (UIElement_ListBox *)((int (*)(void))curItem->vfptr[13].OnAction)() != v1 )
          goto LABEL_44;
        ((void (__stdcall *)(int, int))curItem->vfptr[3].OnLoseFocus)(v36, v37);
        if ( v1->m_bitField & 1 )
        {
          if ( nCurrentColumn != v1->m_nCols - 1 )
          {
            v36 += v1->m_nItemWidths.m_data[nCurrentColumn++];
            goto LABEL_44;
          }
          v36 = -v1->m_iScrollableX;
          nCurrentColumn = 0;
        }
        else if ( v28 == v1->m_nRows - 1 )
        {
          v37 = -v1->m_iScrollableY;
          v36 += v1->m_nItemWidths.m_data[nCurrentColumn];
          v28 = 0;
          ++nCurrentColumn;
          goto LABEL_44;
        }
        v37 += v1->m_nItemHeights.m_data[v28++];
LABEL_44:
        v35 = nIndex++ + 1;
      }
      while ( nIndex < nNum );
    }
  }
}

//----- (0046E760) --------------------------------------------------------  // acclient.c:171307
char __thiscall UIElement_ListBox::InsertItem(UIElement_ListBox *this, UIElement *_insertThis, int _here)
{
  UIElement *v3; // edi@1
  UIElement_ListBox *v4; // ebx@1
  unsigned int v5; // edx@2
  SmartArray<EffectInfoRegion *,1> *v6; // ecx@2
  unsigned int v7; // eax@2
  EffectInfoRegion **v8; // esi@3
  char result; // al@9

  v3 = _insertThis;
  v4 = this;
  if ( _insertThis )
  {
    ((void (__thiscall *)(_DWORD, _DWORD))_insertThis->vfptr[5].OnLoseFocus)(_insertThis, this);
    v5 = v4->m_listItems.m_num;
    v6 = (SmartArray<EffectInfoRegion *,1> *)&v4->m_listItems;
    v7 = 0;
    if ( !v5 )
      goto LABEL_8;
    v8 = v6->m_data;
    while ( (UIElement *)*v8 != v3 )
    {
      ++v7;
      ++v8;
      if ( v7 >= v5 )
        goto LABEL_8;
    }
    if ( v7 == -1 )
    {
LABEL_8:
      SmartArray<LayerStage *,1>::InsertOrderedByIndex(v6, (EffectInfoRegion *const *)&_insertThis, _here);
      v4->m_bitField |= 0x200u;
      UIRegion::MakeRootDirtyHere((UIRegion *)&v4->vfptr);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046E7E0) --------------------------------------------------------  // acclient.c:171352
int __thiscall UIElement_ListBox::CalculateColumn(UIElement_ListBox *this, int _itemIndex)
{
  UIElement_ListBox *v2; // esi@1
  int v3; // edi@1
  int v4; // ecx@2
  int result; // eax@6
  int v6; // esi@8

  v2 = this;
  v3 = this->m_nRows;
  if ( v3 <= 0 || (v4 = this->m_nCols, v4 <= 0) )
  {
    _itemIndex = (int)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::sprintf(
      (PStringBase<char> *)&_itemIndex,
      "The number of calculated rows [%d] and/or columns [%d] do not reflect the number of items [%d] in the list box. UpateLayout needs to be called to re-calculate the number of rows and columns.",
      v2->m_nRows,
      v2->m_nCols,
      v2->m_listItems.m_num);
    v6 = _itemIndex - 20;
    if ( !InterlockedDecrement((volatile LONG *)(_itemIndex - 20 + 4)) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    return -1;
  }
  if ( _itemIndex < 0 || _itemIndex >= (signed int)v2->m_listItems.m_num )
    return -1;
  if ( v2->m_bitField & 1 )
    result = _itemIndex % v4;
  else
    result = _itemIndex / v3;
  return result;
}

//----- (0046E890) --------------------------------------------------------  // acclient.c:171387
int __thiscall UIElement_ListBox::CalculateRow(UIElement_ListBox *this, int _itemIndex)
{
  UIElement_ListBox *v2; // esi@1
  int v3; // edi@1
  int v4; // ecx@2
  int result; // eax@6
  int v6; // esi@8

  v2 = this;
  v3 = this->m_nRows;
  if ( v3 <= 0 || (v4 = this->m_nCols, v4 <= 0) )
  {
    _itemIndex = (int)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::sprintf(
      (PStringBase<char> *)&_itemIndex,
      "The number of calculated rows [%d] and/or columns [%d] do not reflect the number of items [%d] in the list box. UpateLayout needs to be called to re-calculate the number of rows and columns.",
      v2->m_nRows,
      v2->m_nCols,
      v2->m_listItems.m_num);
    v6 = _itemIndex - 20;
    if ( !InterlockedDecrement((volatile LONG *)(_itemIndex - 20 + 4)) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    return -1;
  }
  if ( _itemIndex < 0 || _itemIndex >= (signed int)v2->m_listItems.m_num )
    return -1;
  if ( v2->m_bitField & 1 )
    result = _itemIndex / v4;
  else
    result = _itemIndex % v3;
  return result;
}

//----- (0046E940) --------------------------------------------------------  // acclient.c:171422
void __thiscall UIElement_ListBox::ScrollToShow(UIElement_ListBox *this, int i_iItemNum)
{
  UIElement_ListBox *v2; // esi@1
  int v3; // edi@3
  int v4; // eax@3
  int v5; // ebp@3
  unsigned int v6; // eax@5
  int v7; // ebx@7
  int *v8; // eax@8
  unsigned int v9; // eax@10
  int v10; // eax@12
  int *v11; // ecx@13
  int v12; // edx@13

  v2 = this;
  if ( i_iItemNum >= 0 && i_iItemNum < (signed int)this->m_listItems.m_num )
  {
    ((void (*)(void))this->vfptr[29].OnAction)();
    v3 = UIElement_ListBox::CalculateColumn(v2, i_iItemNum);
    v4 = UIElement_ListBox::CalculateRow(v2, i_iItemNum);
    v5 = v4;
    if ( v3 != -1 && v4 != -1 )
    {
      v6 = v2->m_bitField;
      if ( BYTE1(v6) & 2 )
        ((void (__thiscall *)(UIElement_ListBox *))v2->vfptr[29].OnAction)(v2);
      v7 = 0;
      if ( v3 > 0 )
      {
        v8 = v2->m_nItemWidths.m_data;
        do
        {
          v7 += *v8;
          ++v8;
          --v3;
        }
        while ( v3 );
      }
      v9 = v2->m_bitField;
      if ( BYTE1(v9) & 2 )
        ((void (__thiscall *)(_DWORD))v2->vfptr[29].OnAction)(v2);
      v10 = 0;
      if ( v5 > 0 )
      {
        v11 = v2->m_nItemHeights.m_data;
        v12 = v5;
        do
        {
          v10 += *v11;
          ++v11;
          --v12;
        }
        while ( v12 );
      }
      UIElement_Scrollable::SetScrollableXY((UIElement_Scrollable *)&v2->vfptr, v7, v10, 0);
    }
  }
}

//----- (0046E9F0) --------------------------------------------------------  // acclient.c:171482
void __thiscall UIElement_ListBox::ScrollToView(UIElement_ListBox *this, int i_iItemNum)
{
  UIElement_ListBox *v2; // esi@1
  int v3; // edi@3
  int v4; // eax@3
  int v5; // ebp@3
  unsigned int v6; // eax@5
  int v7; // ebx@7
  int *v8; // eax@8
  unsigned int v9; // eax@10
  int v10; // edi@12
  int *v11; // eax@13
  int v12; // ecx@13
  int v13; // ebp@15
  int v14; // eax@15
  UIRegion *v15; // eax@15
  int v16; // edx@15
  UIRegion *v17; // ebp@15
  int v18; // eax@16
  int iCurrViewY0; // [sp+8h] [bp-20h]@15
  int iItemW; // [sp+Ch] [bp-1Ch]@15
  int iCurrViewW; // [sp+10h] [bp-18h]@15
  int iCurrViewH; // [sp+14h] [bp-14h]@15
  int iCurrViewX0; // [sp+1Ch] [bp-Ch]@15
  int iCurrViewX1; // [sp+20h] [bp-8h]@15
  int iCurrViewY1; // [sp+24h] [bp-4h]@15

  v2 = this;
  if ( i_iItemNum >= 0 && i_iItemNum < (signed int)this->m_listItems.m_num )
  {
    ((void (*)(void))this->vfptr[29].OnAction)();
    v3 = UIElement_ListBox::CalculateColumn(v2, i_iItemNum);
    v4 = UIElement_ListBox::CalculateRow(v2, i_iItemNum);
    v5 = v4;
    if ( v3 != -1 && v4 != -1 )
    {
      v6 = v2->m_bitField;
      if ( BYTE1(v6) & 2 )
        ((void (__thiscall *)(UIElement_ListBox *))v2->vfptr[29].OnAction)(v2);
      v7 = 0;
      if ( v3 > 0 )
      {
        v8 = v2->m_nItemWidths.m_data;
        do
        {
          v7 += *v8;
          ++v8;
          --v3;
        }
        while ( v3 );
      }
      v9 = v2->m_bitField;
      if ( BYTE1(v9) & 2 )
        ((void (__thiscall *)(_DWORD))v2->vfptr[29].OnAction)(v2);
      v10 = 0;
      if ( v5 > 0 )
      {
        v11 = v2->m_nItemHeights.m_data;
        v12 = v5;
        do
        {
          v10 += *v11;
          ++v11;
          --v12;
        }
        while ( v12 );
      }
      v13 = v2->m_iScrollableX;
      iCurrViewY0 = v2->m_iScrollableY;
      iCurrViewX0 = v2->m_iScrollableX;
      iCurrViewW = UIRegion::GetWidth((UIRegion *)&v2->vfptr);
      v14 = UIRegion::GetHeight((UIRegion *)&v2->vfptr);
      iCurrViewX1 = v13 + iCurrViewW;
      iCurrViewY1 = v14 + iCurrViewY0;
      iCurrViewH = v14;
      iItemW = 0;
      v15 = (UIRegion *)UIElement_ListBox::GetItem(v2, i_iItemNum);
      v17 = v15;
      if ( v15 )
      {
        iItemW = UIRegion::GetWidth(v15);
        v18 = UIRegion::GetHeight(v17);
        v16 = iCurrViewH;
      }
      else
      {
        v18 = 0;
      }
      if ( v7 >= iCurrViewX0 && v10 >= iCurrViewY0 )
      {
        if ( v7 <= iCurrViewX1 - iItemW )
        {
          if ( v10 <= iCurrViewY1 - v18 )
            return;
          v10 = v18 + v10 - v16;
        }
        else
        {
          v7 = iItemW + v7 - iCurrViewW;
        }
      }
      UIElement_Scrollable::SetScrollableXY((UIElement_Scrollable *)&v2->vfptr, v7, v10, 0);
    }
  }
}

//----- (0046EB60) --------------------------------------------------------  // acclient.c:171589
void __thiscall UIElement_ListBox::ScrollToShow(UIElement_ListBox *this, UIElement *i_pcItem)
{
  unsigned int v2; // esi@2
  int v3; // eax@2
  UIElement **v4; // edx@3

  if ( this->m_listItems.m_num )
  {
    v2 = this->m_listItems.m_num;
    v3 = 0;
    if ( v2 )
    {
      v4 = this->m_listItems.m_data;
      while ( *v4 != i_pcItem )
      {
        ++v3;
        ++v4;
        if ( v3 >= v2 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      v3 = -1;
    }
    UIElement_ListBox::ScrollToShow(this, v3);
  }
}

//----- (0046EBA0) --------------------------------------------------------  // acclient.c:171620
void __thiscall UIElement_ListBox::SetSelectedIndex(UIElement_ListBox *this, unsigned int _selectedIndex, bool _bBroadcast)
{
  UIElement_ListBox *v3; // esi@1

  v3 = this;
  if ( _selectedIndex >= this->m_listItems.m_num )
  {
    UIElement_ListBox::SetSelectedItem(this, 0, _bBroadcast);
  }
  else
  {
    UIElement_ListBox::SetSelectedItem(this, this->m_listItems.m_data[_selectedIndex], _bBroadcast);
    UIElement_ListBox::ScrollToShow(v3, v3->m_listItems.m_data[_selectedIndex]);
  }
}

//----- (0046EC00) --------------------------------------------------------  // acclient.c:171637
char __thiscall UIElement_ListBox::InsertItem(UIElement_ListBox *this, UIElement *_insertThis, UIElement *_here)
{
  unsigned int v3; // esi@3
  int v4; // eax@3
  UIElement **v5; // edx@4
  char result; // al@8

  if ( _insertThis && _here )
  {
    v3 = this->m_listItems.m_num;
    v4 = 0;
    if ( v3 )
    {
      v5 = this->m_listItems.m_data;
      while ( *v5 != _here )
      {
        ++v4;
        ++v5;
        if ( v4 >= v3 )
          goto LABEL_7;
      }
    }
    else
    {
LABEL_7:
      v4 = -1;
    }
    result = UIElement_ListBox::InsertItem(this, _insertThis, v4);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046EC50) --------------------------------------------------------  // acclient.c:171674
char __thiscall UIElement_ListBox::StartActive(UIElement_ListBox *this, const int *_nDelta)
{
  UIElement_ListBox *v2; // edi@1
  unsigned int v3; // edx@1
  signed int v4; // eax@1
  UIElement *v5; // esi@2
  UIElement **v6; // ecx@2
  int v7; // esi@6
  int v8; // eax@8
  bool v9; // cf@8
  char result; // al@11

  v2 = this;
  v3 = this->m_listItems.m_num;
  v4 = 0;
  if ( v3 )
  {
    v5 = this->m_pSelectedItem;
    v6 = this->m_listItems.m_data;
    while ( *v6 != v5 )
    {
      ++v4;
      ++v6;
      if ( v4 >= v3 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v4 = -1;
  }
  v7 = v4 + *_nDelta;
  if ( v7 < 0 )
    v7 = v2->m_listItems.m_num - 1;
  v8 = v2->m_listItems.m_num;
  v9 = v7 < (unsigned int)v8;
  if ( v7 >= v8 )
  {
    v7 = 0;
    v9 = (unsigned int)v8 > 0;
  }
  if ( v9 )
  {
    UIElement_ListBox::SetSelectedItem(v2, v2->m_listItems.m_data[v7], 1);
    UIElement_ListBox::ScrollToShow(v2, v2->m_listItems.m_data[v7]);
    result = 1;
  }
  else
  {
    UIElement_ListBox::SetSelectedItem(v2, 0, 1);
    result = 1;
  }
  return result;
}

//----- (0046ECE0) --------------------------------------------------------  // acclient.c:171731
void __thiscall UIElement_ListBox::SetSelectedItemByID(UIElement_ListBox *this, unsigned int _itemID, bool _bBroadcast)
{
  UIElement_ListBox *v3; // edi@1
  unsigned int v4; // ecx@1
  unsigned int v5; // esi@1
  UIElement **v6; // eax@2

  v3 = this;
  v4 = this->m_listItems.m_num;
  v5 = 0;
  if ( v4 )
  {
    v6 = v3->m_listItems.m_data;
    while ( (*v6)->m_desc.m_elementID != _itemID )
    {
      ++v5;
      ++v6;
      if ( v5 >= v4 )
        goto LABEL_5;
    }
    if ( v5 >= v4 )
    {
      UIElement_ListBox::SetSelectedItem(v3, 0, _bBroadcast);
    }
    else
    {
      UIElement_ListBox::SetSelectedItem(v3, v3->m_listItems.m_data[v5], _bBroadcast);
      UIElement_ListBox::ScrollToShow(v3, v3->m_listItems.m_data[v5]);
    }
  }
  else
  {
LABEL_5:
    UIElement_ListBox::SetSelectedItem(v3, 0, _bBroadcast);
  }
}

//----- (0046ED70) --------------------------------------------------------  // acclient.c:171769
char __thiscall UIElement_ListBox::AddItem(UIElement_ListBox *this, UIElement *_item)
{
  UIElement_ListBox *v2; // esi@1
  char result; // al@4

  v2 = this;
  if ( _item )
  {
    ((void (__stdcall *)(_DWORD))_item->vfptr[5].OnLoseFocus)(this);
    if ( SmartArray<QualityChangeHandler *,1>::add_unique(&v2->m_listItems, &_item) )
    {
      v2->m_bitField |= 0x200u;
      UIRegion::MakeRootDirtyHere((UIRegion *)&v2->vfptr);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046EDC0) --------------------------------------------------------  // acclient.c:171793
int __thiscall UIElement_ListBox::AddItem(UIElement_ListBox *this, IDClass<_tagDataID,32,0> didLayout, unsigned int idElement, UIElement *i_pInsertBefore)
{
  UIElementManager *v4; // ebx@1
  int result; // eax@1
  UIElement_ListBox *v6; // edi@1
  int v7; // esi@2
  char v8; // al@4

  v4 = UIElementManager::s_pInstance;
  result = 0;
  v6 = this;
  if ( UIElementManager::s_pInstance )
  {
    v7 = UIElementManager::CreateChildElementByDid(
           UIElementManager::s_pInstance,
           (UIElement *)&this->vfptr,
           didLayout,
           idElement);
    if ( !v7
      || (!i_pInsertBefore ? (v8 = UIElement_ListBox::AddItem(v6, (UIElement *)v7)) : (v8 = UIElement_ListBox::InsertItem(
                                                                                              v6,
                                                                                              (UIElement *)v7,
                                                                                              i_pInsertBefore)),
          v8) )
    {
      result = v7;
    }
    else
    {
      UIElementManager::AddElementToDeleteQueue(v4, (UIElement *)v7);
      result = 0;
    }
  }
  return result;
}

//----- (0046EE20) --------------------------------------------------------  // acclient.c:171830
char __thiscall UIElement_ListBox::StartUpActive(UIElement_ListBox *this)
{
  char result; // al@2
  int _nDelta; // [sp+0h] [bp-4h]@1

  _nDelta = (int)this;
  if ( this->m_bitField & 1 )
  {
    _nDelta = -this->m_nCols;
    result = UIElement_ListBox::StartActive(this, &_nDelta);
  }
  else
  {
    _nDelta = -1;
    result = UIElement_ListBox::StartActive(this, &_nDelta);
  }
  return result;
}

//----- (0046EE60) --------------------------------------------------------  // acclient.c:171850
char __thiscall UIElement_ListBox::StartDownActive(UIElement_ListBox *this)
{
  signed int v1; // eax@1
  int _nDelta; // [sp+0h] [bp-4h]@1

  _nDelta = (int)this;
  v1 = 1;
  if ( this->m_bitField & 1 )
    v1 = this->m_nCols;
  _nDelta = v1;
  return UIElement_ListBox::StartActive(this, &_nDelta);
}

//----- (0046EE90) --------------------------------------------------------  // acclient.c:171864
char __thiscall UIElement_ListBox::StartLeftActive(UIElement_ListBox *this)
{
  char result; // al@2
  int _nDelta; // [sp+0h] [bp-4h]@1

  _nDelta = (int)this;
  if ( this->m_bitField & 1 )
  {
    _nDelta = -1;
    result = UIElement_ListBox::StartActive(this, &_nDelta);
  }
  else
  {
    _nDelta = -this->m_nRows;
    result = UIElement_ListBox::StartActive(this, &_nDelta);
  }
  return result;
}

//----- (0046EED0) --------------------------------------------------------  // acclient.c:171884
char __thiscall UIElement_ListBox::StartRightActive(UIElement_ListBox *this)
{
  signed int v1; // eax@1
  int _nDelta; // [sp+0h] [bp-4h]@1

  _nDelta = (int)this;
  v1 = 1;
  if ( !(this->m_bitField & 1) )
    v1 = this->m_nRows;
  _nDelta = v1;
  return UIElement_ListBox::StartActive(this, &_nDelta);
}

//----- (0046EF00) --------------------------------------------------------  // acclient.c:171898
int __thiscall UIElement_ListBox::AddItemFromTemplateListByID(UIElement_ListBox *this, unsigned int i_item, UIElement *i_pInsertBefore)
{
  UIElement_ListBox *v3; // edi@1
  IInputActionCallbackVtbl *v4; // eax@1
  char v5; // al@1
  BasePropertyValue *v6; // ecx@1
  unsigned int i; // esi@4
  BasePropertyDesc *v8; // ecx@17
  unsigned int v9; // edx@17
  BasePropertyValue *v10; // ecx@21
  unsigned int v11; // edx@21
  BasePropertyDesc *v12; // ecx@25
  unsigned int v13; // edx@25
  BasePropertyValue *v14; // ecx@29
  unsigned int v15; // edx@29
  BasePropertyDesc *v16; // ecx@33
  unsigned int v17; // edx@33
  BasePropertyValue *v18; // ecx@37
  unsigned int v19; // edx@37
  BasePropertyDesc *v20; // ecx@45
  unsigned int v21; // edx@45
  int v22; // edx@49
  int pResult; // [sp+40h] [bp-30h]@1
  unsigned int cElements; // [sp+44h] [bp-2Ch]@2
  unsigned int idElement; // [sp+48h] [bp-28h]@14
  IDClass<_tagDataID,32,0> didLayout; // [sp+4Ch] [bp-24h]@12
  BaseProperty propArray; // [sp+50h] [bp-20h]@1
  BaseProperty propCurItem; // [sp+58h] [bp-18h]@5
  BaseProperty propElement; // [sp+60h] [bp-10h]@7
  BaseProperty propLayout; // [sp+68h] [bp-8h]@7

  v3 = this;
  v4 = this->vfptr;
  pResult = 0;
  propArray.m_pcPropertyDesc = 0;
  propArray.m_pcPropertyValue = 0;
  v5 = ((int (__stdcall *)(signed int, BaseProperty *))v4[17].OnAction)(100, &propArray);
  v6 = propArray.m_pcPropertyValue;
  if ( v5 )
  {
    cElements = 0;
    if ( propArray.m_pcPropertyValue )
    {
      ((void (__stdcall *)(unsigned int *))propArray.m_pcPropertyValue->vfptr[60].__vecDelDtor)(&cElements);
      v6 = propArray.m_pcPropertyValue;
    }
    for ( i = 0; i < cElements; ++i )
    {
      propCurItem.m_pcPropertyDesc = 0;
      propCurItem.m_pcPropertyValue = 0;
      if ( v6 )
      {
        if ( (unsigned __int8)((int (__stdcall *)(unsigned int, BaseProperty *))v6->vfptr[61].__vecDelDtor)(
                                i,
                                &propCurItem) )
        {
          propLayout.m_pcPropertyDesc = 0;
          propLayout.m_pcPropertyValue = 0;
          propElement.m_pcPropertyDesc = 0;
          propElement.m_pcPropertyValue = 0;
          if ( propCurItem.m_pcPropertyValue )
          {
            if ( (unsigned __int8)((int (__stdcall *)(signed int, BaseProperty *))propCurItem.m_pcPropertyValue->vfptr[70].__vecDelDtor)(
                                    99,
                                    &propLayout)
              && propCurItem.m_pcPropertyValue
              && (unsigned __int8)((int (__stdcall *)(signed int, BaseProperty *))propCurItem.m_pcPropertyValue->vfptr[70].__vecDelDtor)(
                                    98,
                                    &propElement)
              && propLayout.m_pcPropertyValue
              && (unsigned __int8)((int (__stdcall *)(IDClass<_tagDataID,32,0> *))propLayout.m_pcPropertyValue->vfptr[44].__vecDelDtor)(&didLayout)
              && propElement.m_pcPropertyValue
              && (unsigned __int8)((int (__stdcall *)(unsigned int *))propElement.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&idElement)
              && idElement == i_item )
            {
              pResult = UIElement_ListBox::AddItem(v3, didLayout, idElement, i_pInsertBefore);
              BaseProperty::~BaseProperty(&propElement);
              BaseProperty::~BaseProperty(&propLayout);
              BaseProperty::~BaseProperty(&propCurItem);
              v6 = propArray.m_pcPropertyValue;
              break;
            }
            if ( (_DWORD)propElement.m_pcPropertyDesc )
            {
              v8 = propElement.m_pcPropertyDesc;
              v9 = propElement.m_pcPropertyDesc->m_cRef - 1;
              propElement.m_pcPropertyDesc->m_cRef = v9;
              if ( !v9 )
                ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
              propElement.m_pcPropertyDesc = 0;
            }
            if ( propElement.m_pcPropertyValue )
            {
              v10 = propElement.m_pcPropertyValue;
              v11 = propElement.m_pcPropertyValue->m_cRef - 1;
              propElement.m_pcPropertyValue->m_cRef = v11;
              if ( !v11 )
                ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
              propElement.m_pcPropertyValue = 0;
            }
            if ( (_DWORD)propLayout.m_pcPropertyDesc )
            {
              v12 = propLayout.m_pcPropertyDesc;
              v13 = propLayout.m_pcPropertyDesc->m_cRef - 1;
              propLayout.m_pcPropertyDesc->m_cRef = v13;
              if ( !v13 )
                ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
              propLayout.m_pcPropertyDesc = 0;
            }
            if ( propLayout.m_pcPropertyValue )
            {
              v14 = propLayout.m_pcPropertyValue;
              v15 = propLayout.m_pcPropertyValue->m_cRef - 1;
              propLayout.m_pcPropertyValue->m_cRef = v15;
              if ( !v15 )
                ((void (__stdcall *)(signed int))v14->vfptr->__vecDelDtor)(1);
              propLayout.m_pcPropertyValue = 0;
            }
          }
        }
        if ( (_DWORD)propCurItem.m_pcPropertyDesc )
        {
          v16 = propCurItem.m_pcPropertyDesc;
          v17 = propCurItem.m_pcPropertyDesc->m_cRef - 1;
          propCurItem.m_pcPropertyDesc->m_cRef = v17;
          if ( !v17 )
            ((void (__stdcall *)(signed int))v16->vfptr->__vecDelDtor)(1);
          propCurItem.m_pcPropertyDesc = 0;
        }
        if ( propCurItem.m_pcPropertyValue )
        {
          v18 = propCurItem.m_pcPropertyValue;
          v19 = propCurItem.m_pcPropertyValue->m_cRef - 1;
          propCurItem.m_pcPropertyValue->m_cRef = v19;
          if ( !v19 )
            ((void (__stdcall *)(signed int))v18->vfptr->__vecDelDtor)(1);
          propCurItem.m_pcPropertyValue = 0;
        }
        v6 = propArray.m_pcPropertyValue;
      }
    }
  }
  if ( (_DWORD)propArray.m_pcPropertyDesc )
  {
    v20 = propArray.m_pcPropertyDesc;
    v21 = propArray.m_pcPropertyDesc->m_cRef - 1;
    propArray.m_pcPropertyDesc->m_cRef = v21;
    if ( !v21 )
      ((void (__stdcall *)(signed int))v20->vfptr->__vecDelDtor)(1);
    v6 = propArray.m_pcPropertyValue;
    propArray.m_pcPropertyDesc = 0;
  }
  if ( v6 )
  {
    v22 = v6->m_cRef - 1;
    v6->m_cRef = v22;
    if ( !v22 )
      ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
  }
  return pResult;
}

//----- (0046F170) --------------------------------------------------------  // acclient.c:172061
int __thiscall UIElement_ListBox::AddItem(UIElement_ListBox *this, BaseProperty *propEntryStruct, UIElement *i_pInsertBefore)
{
  BaseProperty *v3; // esi@1
  UIElement_ListBox *v4; // edi@1
  BasePropertyValue *v5; // ecx@1
  int v6; // ebp@1
  BasePropertyValue *v7; // ecx@3
  BasePropertyValue *v8; // ecx@7
  BasePropertyDesc *v9; // ecx@12
  unsigned int v10; // edx@12
  int v11; // edx@16
  BasePropertyDesc *v12; // ecx@20
  unsigned int v13; // edx@20
  BasePropertyValue *v14; // ecx@24
  unsigned int v15; // edx@24
  IDClass<_tagDataID,32,0> didLayout; // [sp+18h] [bp-14h]@6
  BaseProperty propElement; // [sp+1Ch] [bp-10h]@1
  BaseProperty propLayout; // [sp+24h] [bp-8h]@1

  v3 = propEntryStruct;
  v4 = this;
  v5 = propEntryStruct->m_pcPropertyValue;
  v6 = 0;
  propLayout.m_pcPropertyDesc = 0;
  propLayout.m_pcPropertyValue = 0;
  propElement.m_pcPropertyDesc = 0;
  propElement.m_pcPropertyValue = 0;
  if ( !v5 )
    return v6;
  if ( !(unsigned __int8)((int (__stdcall *)(signed int, BaseProperty *))v5->vfptr[70].__vecDelDtor)(99, &propLayout) )
    goto LABEL_10;
  v7 = v3->m_pcPropertyValue;
  if ( !v7
    || !(unsigned __int8)((int (__stdcall *)(signed int, BaseProperty *))v7->vfptr[70].__vecDelDtor)(98, &propElement)
    || !propLayout.m_pcPropertyValue
    || !(unsigned __int8)((int (__stdcall *)(_DWORD))propLayout.m_pcPropertyValue->vfptr[44].__vecDelDtor)(&didLayout) )
    goto LABEL_10;
  v8 = propElement.m_pcPropertyValue;
  if ( propElement.m_pcPropertyValue )
  {
    if ( (unsigned __int8)((int (__stdcall *)(_DWORD))propElement.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&propEntryStruct) )
      v6 = UIElement_ListBox::AddItem(v4, didLayout, (unsigned int)propEntryStruct, i_pInsertBefore);
LABEL_10:
    v8 = propElement.m_pcPropertyValue;
  }
  if ( (_DWORD)propElement.m_pcPropertyDesc )
  {
    v9 = propElement.m_pcPropertyDesc;
    v10 = propElement.m_pcPropertyDesc->m_cRef - 1;
    propElement.m_pcPropertyDesc->m_cRef = v10;
    if ( !v10 )
      ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
    v8 = propElement.m_pcPropertyValue;
    propElement.m_pcPropertyDesc = 0;
  }
  if ( v8 )
  {
    v11 = v8->m_cRef - 1;
    v8->m_cRef = v11;
    if ( !v11 )
      ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
    propElement.m_pcPropertyValue = 0;
  }
  if ( (_DWORD)propLayout.m_pcPropertyDesc )
  {
    v12 = propLayout.m_pcPropertyDesc;
    v13 = propLayout.m_pcPropertyDesc->m_cRef - 1;
    propLayout.m_pcPropertyDesc->m_cRef = v13;
    if ( !v13 )
      ((void (__stdcall *)(_DWORD))v12->vfptr->__vecDelDtor)(1);
    propLayout.m_pcPropertyDesc = 0;
  }
  if ( propLayout.m_pcPropertyValue )
  {
    v14 = propLayout.m_pcPropertyValue;
    v15 = propLayout.m_pcPropertyValue->m_cRef - 1;
    propLayout.m_pcPropertyValue->m_cRef = v15;
    if ( !v15 )
      ((void (__stdcall *)(_DWORD))v14->vfptr->__vecDelDtor)(1);
  }
  return v6;
}

//----- (0046F2B0) --------------------------------------------------------  // acclient.c:172145
int __thiscall UIElement_ListBox::AddItemFromTemplateList(UIElement_ListBox *this, unsigned int i_itemIndex, UIElement *i_pInsertBefore)
{
  UIElement_ListBox *v3; // esi@1
  IInputActionCallbackVtbl *v4; // eax@1
  int v5; // edi@1
  BasePropertyValue *v6; // ecx@2
  BasePropertyDesc *v7; // ecx@6
  unsigned int v8; // edx@6
  BasePropertyValue *v9; // ecx@9
  unsigned int v10; // edx@10
  BasePropertyDesc *v11; // ecx@14
  unsigned int v12; // edx@14
  int v13; // edx@18
  BaseProperty propArray; // [sp+1Ch] [bp-10h]@1
  BaseProperty propCurItem; // [sp+24h] [bp-8h]@2

  v3 = this;
  v4 = this->vfptr;
  v5 = 0;
  propArray.m_pcPropertyDesc = 0;
  propArray.m_pcPropertyValue = 0;
  if ( (unsigned __int8)((int (__stdcall *)(signed int, BaseProperty *))v4[17].OnAction)(100, &propArray) )
  {
    v6 = propArray.m_pcPropertyValue;
    propCurItem.m_pcPropertyDesc = 0;
    propCurItem.m_pcPropertyValue = 0;
    if ( !propArray.m_pcPropertyValue )
      goto LABEL_13;
    if ( (unsigned __int8)((int (__stdcall *)(_DWORD, _DWORD))propArray.m_pcPropertyValue->vfptr[61].__vecDelDtor)(
                            i_itemIndex,
                            &propCurItem) )
      v5 = UIElement_ListBox::AddItem(v3, &propCurItem, i_pInsertBefore);
    if ( (_DWORD)propCurItem.m_pcPropertyDesc )
    {
      v7 = propCurItem.m_pcPropertyDesc;
      v8 = propCurItem.m_pcPropertyDesc->m_cRef - 1;
      propCurItem.m_pcPropertyDesc->m_cRef = v8;
      if ( !v8 )
        ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
      propCurItem.m_pcPropertyDesc = 0;
    }
    v9 = propCurItem.m_pcPropertyValue;
    if ( propCurItem.m_pcPropertyValue )
    {
      v10 = propCurItem.m_pcPropertyValue->m_cRef - 1;
      propCurItem.m_pcPropertyValue->m_cRef = v10;
      if ( !v10 )
        ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
    }
  }
  v6 = propArray.m_pcPropertyValue;
LABEL_13:
  if ( (_DWORD)propArray.m_pcPropertyDesc )
  {
    v11 = propArray.m_pcPropertyDesc;
    v12 = propArray.m_pcPropertyDesc->m_cRef - 1;
    propArray.m_pcPropertyDesc->m_cRef = v12;
    if ( !v12 )
      ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(1);
    v6 = propArray.m_pcPropertyValue;
    propArray.m_pcPropertyDesc = 0;
  }
  if ( v6 )
  {
    v13 = v6->m_cRef - 1;
    v6->m_cRef = v13;
    if ( !v13 )
      ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
  }
  return v5;
}

//----- (0046F3B0) --------------------------------------------------------  // acclient.c:172218
int __thiscall UIElement_ListBox::AddItemFromTemplateList(UIElement_ListBox *this, unsigned int i_itemIndex, int _here)
{
  UIElement_ListBox *v3; // esi@1
  IInputActionCallbackVtbl *v4; // eax@1
  int v5; // edi@1
  BasePropertyValue *v6; // ecx@2
  UIElement *v7; // eax@5
  BasePropertyDesc *v8; // ecx@9
  unsigned int v9; // edx@9
  BasePropertyValue *v10; // ecx@12
  unsigned int v11; // edx@13
  BasePropertyDesc *v12; // ecx@17
  unsigned int v13; // edx@17
  int v14; // edx@21
  BaseProperty propArray; // [sp+1Ch] [bp-10h]@1
  BaseProperty propCurItem; // [sp+24h] [bp-8h]@2

  v3 = this;
  v4 = this->vfptr;
  v5 = 0;
  propArray.m_pcPropertyDesc = 0;
  propArray.m_pcPropertyValue = 0;
  if ( (unsigned __int8)((int (__stdcall *)(signed int, BaseProperty *))v4[17].OnAction)(100, &propArray) )
  {
    v6 = propArray.m_pcPropertyValue;
    propCurItem.m_pcPropertyDesc = 0;
    propCurItem.m_pcPropertyValue = 0;
    if ( !propArray.m_pcPropertyValue )
      goto LABEL_16;
    if ( (unsigned __int8)((int (__stdcall *)(_DWORD, _DWORD))propArray.m_pcPropertyValue->vfptr[61].__vecDelDtor)(
                            i_itemIndex,
                            &propCurItem) )
    {
      if ( _here >= v3->m_listItems.m_num )
        v7 = 0;
      else
        v7 = v3->m_listItems.m_data[_here];
      v5 = UIElement_ListBox::AddItem(v3, &propCurItem, v7);
    }
    if ( (_DWORD)propCurItem.m_pcPropertyDesc )
    {
      v8 = propCurItem.m_pcPropertyDesc;
      v9 = propCurItem.m_pcPropertyDesc->m_cRef - 1;
      propCurItem.m_pcPropertyDesc->m_cRef = v9;
      if ( !v9 )
        ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
      propCurItem.m_pcPropertyDesc = 0;
    }
    v10 = propCurItem.m_pcPropertyValue;
    if ( propCurItem.m_pcPropertyValue )
    {
      v11 = propCurItem.m_pcPropertyValue->m_cRef - 1;
      propCurItem.m_pcPropertyValue->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
    }
  }
  v6 = propArray.m_pcPropertyValue;
LABEL_16:
  if ( (_DWORD)propArray.m_pcPropertyDesc )
  {
    v12 = propArray.m_pcPropertyDesc;
    v13 = propArray.m_pcPropertyDesc->m_cRef - 1;
    propArray.m_pcPropertyDesc->m_cRef = v13;
    if ( !v13 )
      ((void (__stdcall *)(_DWORD))v12->vfptr->__vecDelDtor)(1);
    v6 = propArray.m_pcPropertyValue;
    propArray.m_pcPropertyDesc = 0;
  }
  if ( v6 )
  {
    v14 = v6->m_cRef - 1;
    v6->m_cRef = v14;
    if ( !v14 )
      ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
  }
  return v5;
}

//----- (006EBF90) --------------------------------------------------------  // acclient.c:767785
int _E73_70()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_9, "Misc.TooltipEnable");
  return atexit(_E74_52);
}

//----- (006EBFB0) --------------------------------------------------------  // acclient.c:767792
int _E76_38()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_9, "Misc.TooltipDelay");
  return atexit(_E77_66);
}

//----- (006EBFD0) --------------------------------------------------------  // acclient.c:767799
int _E1_65()
{
  return atexit(_E2_65);
}

//----- (0075E740) --------------------------------------------------------  // acclient.c:886722
void __cdecl _E74_52()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E770) --------------------------------------------------------  // acclient.c:886735
void __cdecl _E77_66()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

