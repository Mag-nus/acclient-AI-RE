/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_Scrollable
   Object     : ENGINE\uielement_types\UIElement_Scrollable.obj
   Functions  : 19
   Addresses  : 00473D90 - 006EC140 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00473D90) --------------------------------------------------------  // acclient.c:176931
void __userpurge UIElement_Scrollable::UIElement_Scrollable(UIElement_Scrollable *this@<ecx>, int a2@<edi>, LayoutDesc *i_rcLayout, ElementDesc *i_rcFullDesc)
{
  UIElement_Scrollable *v4; // esi@1

  v4 = this;
  UIElement::UIElement((UIElement *)&this->vfptr, a2, i_rcLayout, i_rcFullDesc);
  v4->m_eHorizonalScrollbarID = 0;
  v4->m_eVerticalScrollbarID = 0;
  v4->m_iScrollableX = 0;
  v4->m_iScrollableY = 0;
  v4->m_iScrollableWidth = 0;
  v4->m_iScrollableHeight = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement_Scrollable::vftable;
}
// 79D4C0: using guessed type int (__thiscall *UIElement_Scrollable::vftable)(void *, char);

//----- (00473DE0) --------------------------------------------------------  // acclient.c:176948
signed int __thiscall UIElement_Scrollable::DynamicCast(UIElement_Scrollable *this, unsigned int i_eType)
{
  return i_eType != 10 ? 0 : (unsigned int)this;
}

//----- (00473E00) --------------------------------------------------------  // acclient.c:176954
void __thiscall UIElement_Scrollable::MouseDown(UIElement_Scrollable *this, unsigned int i_xWindow, unsigned int i_yWindow, unsigned int i_eButton)
{
  UIElement *v4; // edi@1
  UIElement *v5; // esi@1

  v4 = (UIElement *)this;
  UIElement::MouseDown((UIElement *)&this->vfptr, i_xWindow, i_yWindow, i_eButton);
  v5 = UIElement::GetRootElement(v4);
  if ( v5 )
  {
    if ( (unsigned __int8)((int (__thiscall *)(UIElement *))v5->vfptr[22].OnAction)(v5) )
    {
      ((void (__thiscall *)(UIElement *))v5->vfptr[21].__vecDelDtor)(v5);
      ((void (__thiscall *)(UIElement *))v4->vfptr[21].OnLoseFocus)(v4);
    }
  }
}

//----- (00473E50) --------------------------------------------------------  // acclient.c:176973
bool __thiscall UIElement_Scrollable::RegisterInputMaps(UIElement_Scrollable *this, int i_nPriority)
{
  UIElement_Scrollable *v2; // esi@1
  bool result; // al@2
  bool v4; // bl@3

  v2 = this;
  if ( ICIDM::s_cidm )
  {
    v4 = UIElement::RegisterInputMaps((UIElement *)&this->vfptr, i_nPriority);
    result = v4 | ((int (__stdcall *)(signed int, UIElement_Scrollable *, int))ICIDM::s_cidm->vfptr->RegisterInputMap)(
                    10,
                    v2,
                    i_nPriority);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00473E90) --------------------------------------------------------  // acclient.c:176996
bool __thiscall UIElement_Scrollable::UnregisterInputMaps(UIElement_Scrollable *this)
{
  UIElement_Scrollable *v1; // esi@1
  bool result; // al@2
  bool v3; // bl@3

  v1 = this;
  if ( ICIDM::s_cidm )
  {
    v3 = UIElement::UnregisterInputMaps((UIElement *)&this->vfptr);
    result = v3 | ((int (__stdcall *)(signed int, UIElement_Scrollable *))ICIDM::s_cidm->vfptr->UnregisterInputMap)(
                    10,
                    v1);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00473EC0) --------------------------------------------------------  // acclient.c:177018
UIElement_Scrollbar *__thiscall UIElement_Scrollable::GetScrollbarPointer_(UIElement_Scrollable *this, bool i_bHorizontal)
{
  UIElement_Scrollable *v2; // esi@1
  UIElement_Scrollbar *result; // eax@1
  unsigned int v4; // ecx@2
  UIElement *v5; // eax@5
  UIElement_Scrollbar *v6; // edi@6

  v2 = this;
  result = 0;
  if ( i_bHorizontal )
    v4 = this->m_eHorizonalScrollbarID;
  else
    v4 = this->m_eVerticalScrollbarID;
  if ( v4 )
  {
    v5 = UIElement::FindRelative((UIElement *)&v2->vfptr, v4);
    if ( v5
      && (v6 = (UIElement_Scrollbar *)v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)11)) != 0
      && (UIElement_Scrollable *)UIElement::FindRelative((UIElement *)&v6->vfptr, v2->m_desc.m_elementID) == v2 )
      result = v6;
    else
      result = 0;
  }
  return result;
}

//----- (00473F20) --------------------------------------------------------  // acclient.c:177046
void __thiscall UIElement_Scrollable::UpdateScrollbarPosition_(UIElement_Scrollable *this, int i_bHorizontal)
{
  int v2; // ebx@1
  UIElement_Scrollable *v3; // edi@1
  UIElement *v4; // esi@1
  int v5; // ebp@3
  long double v6; // st7@3
  int v7; // ebp@4
  BasePropertyDesc *v8; // ecx@11
  unsigned int v9; // edx@11
  BasePropertyValue *v10; // ecx@15
  unsigned int v11; // edx@15
  BaseProperty cPositionProperty; // [sp+10h] [bp-8h]@8
  float i_bHorizontala; // [sp+1Ch] [bp+4h]@3
  float i_bHorizontalb; // [sp+1Ch] [bp+4h]@6

  v2 = i_bHorizontal;
  v3 = this;
  v4 = (UIElement *)UIElement_Scrollable::GetScrollbarPointer_(this, i_bHorizontal);
  if ( v4 )
  {
    if ( (_BYTE)i_bHorizontal )
    {
      v5 = v3->m_iScrollableWidth;
      i_bHorizontala = (double)v3->m_iScrollableX;
      v6 = (double)(v5 - UIRegion::GetWidth((UIRegion *)&v3->vfptr));
    }
    else
    {
      v7 = v3->m_iScrollableHeight;
      i_bHorizontala = (double)v3->m_iScrollableY;
      v6 = (double)(v7 - UIRegion::GetHeight((UIRegion *)&v3->vfptr));
    }
    if ( fabs(v6) > 0.00019999999 )
      i_bHorizontalb = i_bHorizontala / v6;
    else
      i_bHorizontalb = 0.0;
    UIElement::SetAttribute_Bool(v4, 0x75u, 1);
    cPositionProperty.m_pcPropertyDesc = 0;
    cPositionProperty.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&cPositionProperty, 0x86u);
    if ( cPositionProperty.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&cPositionProperty);
      ((void (__stdcall *)(_DWORD))cPositionProperty.m_pcPropertyValue->vfptr[35].__vecDelDtor)(LODWORD(i_bHorizontalb));
    }
    UIElement::SetAttribute_Bool(v4, 0x7Bu, v2);
    ((void (__thiscall *)(UIElement *, BaseProperty *))v4->vfptr[17].OnLoseFocus)(v4, &cPositionProperty);
    UIElement::SetAttribute_Bool(v4, 0x75u, 0);
    UIElement_Scrollbar::UpdateLayout((UIElement_Scrollbar *)v4);
    if ( (_DWORD)cPositionProperty.m_pcPropertyDesc )
    {
      v8 = cPositionProperty.m_pcPropertyDesc;
      v9 = cPositionProperty.m_pcPropertyDesc->m_cRef - 1;
      cPositionProperty.m_pcPropertyDesc->m_cRef = v9;
      if ( !v9 )
        ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
      cPositionProperty.m_pcPropertyDesc = 0;
    }
    if ( cPositionProperty.m_pcPropertyValue )
    {
      v10 = cPositionProperty.m_pcPropertyValue;
      v11 = cPositionProperty.m_pcPropertyValue->m_cRef - 1;
      cPositionProperty.m_pcPropertyValue->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
    }
  }
}

//----- (00474070) --------------------------------------------------------  // acclient.c:177117
char __thiscall UIElement_Scrollable::InqAvailableProperties(UIElement_Scrollable *this, AvailablePropertySet *o_rcSet)
{
  AvailablePropertySet *v2; // edi@1
  char v3; // bl@1
  AvailablePropertySet *v4; // esi@3
  char result; // al@4

  v2 = o_rcSet;
  v3 = 1;
  if ( !UIElement::InqAvailableProperties((UIElement *)&this->vfptr, o_rcSet) )
    v3 = 0;
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&o_rcSet);
  v4 = o_rcSet;
  if ( o_rcSet )
  {
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)o_rcSet, 0x11u, v2) )
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

//----- (004740C0) --------------------------------------------------------  // acclient.c:177145
void __thiscall UIElement_Scrollable::SetScrollableXY(UIElement_Scrollable *this, int i_iX, int i_iY, bool i_bForce)
{
  UIElement_Scrollable *v4; // esi@1
  int v5; // edi@3
  int *v6; // eax@3
  int v7; // ebp@7
  int v8; // edi@7
  void *v9; // eax@7
  int v10; // eax@11
  int v11; // [sp+8h] [bp-8h]@3
  int v12; // [sp+Ch] [bp-4h]@3

  v4 = this;
  if ( i_bForce || (i_bForce = 1, UIElement::GetAttribute_Bool((UIElement *)&this->vfptr, 0x73u, &i_bForce), !i_bForce) )
  {
    v10 = i_iY;
    v7 = i_iX;
  }
  else
  {
    v5 = v4->m_iScrollableWidth;
    v11 = v5 - UIRegion::GetWidth((UIRegion *)&v4->vfptr);
    v12 = 0;
    v6 = &i_iX;
    if ( i_iX >= v11 )
      v6 = &v11;
    if ( *v6 <= 0 )
      v6 = &v12;
    v7 = *v6;
    v8 = v4->m_iScrollableHeight;
    *(_DWORD *)&i_bForce = v8 - UIRegion::GetHeight((UIRegion *)&v4->vfptr);
    i_iX = 0;
    v9 = &i_iY;
    if ( i_iY >= i_bForce )
      v9 = &i_bForce;
    if ( *(_DWORD *)v9 <= 0 )
      v9 = &i_iX;
    v10 = *(_DWORD *)v9;
  }
  if ( v7 != v4->m_iScrollableX || v10 != v4->m_iScrollableY )
  {
    v4->m_iScrollableX = v7;
    v4->m_iScrollableY = v10;
    UIElement_Scrollable::UpdateScrollbarPosition_(v4, 1);
    UIElement_Scrollable::UpdateScrollbarPosition_(v4, 0);
    ((void (__thiscall *)(UIElement_Scrollable *))v4->vfptr[26].__vecDelDtor)(v4);
  }
}

//----- (004741A0) --------------------------------------------------------  // acclient.c:177195
void __thiscall UIElement_Scrollable::UpdateScrollbarSize_(UIElement_Scrollable *this, int i_bHorizontal)
{
  UIElement_Scrollable *v2; // edi@1
  UIElement *v3; // esi@1
  float v4; // ebp@3
  float v5; // eax@6
  int v6; // ecx@6
  char v7; // bl@8
  double v8; // st7@14
  double v9; // st7@14
  float *v10; // eax@14
  int v11; // esi@21
  double v12; // st7@21
  int v13; // esi@22
  unsigned __int64 v14; // rax@23
  bool bAnchorPercentage; // [sp+Fh] [bp-11h]@19
  float fPosition; // [sp+10h] [bp-10h]@17
  int nViewableSize; // [sp+14h] [bp-Ch]@6
  float fWidgetSize; // [sp+18h] [bp-8h]@5
  int bDisable; // [sp+1Ch] [bp-4h]@8

  v2 = this;
  v3 = (UIElement *)UIElement_Scrollable::GetScrollbarPointer_(this, i_bHorizontal);
  if ( v3 )
  {
    if ( (_BYTE)i_bHorizontal )
      v4 = *(float *)&v2->m_iScrollableWidth;
    else
      v4 = *(float *)&v2->m_iScrollableHeight;
    fWidgetSize = v4;
    if ( (_BYTE)i_bHorizontal )
    {
      v5 = COERCE_FLOAT(UIRegion::GetWidth((UIRegion *)&v2->vfptr));
      nViewableSize = LODWORD(v5);
      v6 = (int)&v2->m_iScrollableX;
    }
    else
    {
      v5 = COERCE_FLOAT(UIRegion::GetHeight((UIRegion *)&v2->vfptr));
      nViewableSize = LODWORD(v5);
      v6 = (int)&v2->m_iScrollableY;
    }
    v7 = 0;
    LOBYTE(bDisable) = 0;
    if ( SLODWORD(v4) <= SLODWORD(v5) )
    {
      v4 = v5;
      v7 = 1;
      *(_DWORD *)v6 = 0;
      fWidgetSize = v5;
      LOBYTE(bDisable) = 1;
    }
    if ( *(_DWORD *)v6 > SLODWORD(v4) )
      *(float *)v6 = v4;
    if ( v4 == 0.0 )
    {
      fWidgetSize = 1.0;
    }
    else
    {
      v8 = (double)nViewableSize;
      nViewableSize = 1065353216;
      v9 = v8 / (double)SLODWORD(fWidgetSize);
      fWidgetSize = v9;
      v10 = &fWidgetSize;
      if ( v9 >= 1.0 )
        v10 = (float *)&nViewableSize;
      fWidgetSize = *v10;
    }
    fPosition = 0.0;
    UIElement::GetAttribute_Float(v3, 0x86u, &fPosition);
    if ( v7 )
      fPosition = 0.0;
    UIElement::SetAttribute_Bool(v3, 0x75u, 1);
    UIElement::SetAttribute_Bool(v3, 0x7Bu, i_bHorizontal);
    UIElement::SetAttribute_Bool(v3, 0x76u, bDisable);
    UIElement::SetAttribute_Float(v3, 0x88u, fWidgetSize);
    UIElement::SetAttribute_Bool(v3, 0x75u, 0);
    bAnchorPercentage = 0;
    UIElement::GetAttribute_Bool(v3, 0x74u, &bAnchorPercentage);
    if ( bAnchorPercentage )
    {
      UIElement::SetAttribute_Float(v3, 0x86u, fPosition);
      if ( (_BYTE)i_bHorizontal )
      {
        v11 = v2->m_iScrollableWidth;
        v12 = (double)(v11 - UIRegion::GetWidth((UIRegion *)&v2->vfptr));
      }
      else
      {
        v13 = v2->m_iScrollableHeight;
        v12 = (double)(v13 - UIRegion::GetHeight((UIRegion *)&v2->vfptr));
      }
      v14 = (unsigned __int64)(v12 * fPosition);
      v2->m_iScrollableX = (_BYTE)i_bHorizontal != 0 ? v14 : 0;
      HIDWORD(v14) = (_BYTE)i_bHorizontal != 0 ? 0 : v14;
      LODWORD(v14) = v2->vfptr;
      v2->m_iScrollableY = HIDWORD(v14);
      (*(void (__thiscall **)(UIElement_Scrollable *))(v14 + 312))(v2);
    }
    else
    {
      UIElement_Scrollable::UpdateScrollbarPosition_(v2, i_bHorizontal);
    }
  }
}

//----- (00474370) --------------------------------------------------------  // acclient.c:177303
void __thiscall UIElement_Scrollable::HandleScrollbarMessage_(UIElement_Scrollable *this, int i_bHorizontal, const unsigned int i_eMessageID, UIElement_Scrollbar *i_pcScrollbar)
{
  UIElement_Scrollable *v4; // esi@1
  UIElement *v5; // ecx@1
  const unsigned int v6; // eax@2
  int v7; // eax@13
  int v8; // edi@15
  double v9; // st7@15
  int v10; // edi@16
  unsigned __int64 v11; // rax@17

  v4 = this;
  v5 = (UIElement *)i_pcScrollbar;
  if ( *(float *)&i_pcScrollbar != 0.0 )
  {
    v6 = i_eMessageID;
    if ( i_eMessageID == 10 )
    {
      *(float *)&i_pcScrollbar = 0.0;
      UIElement::GetAttribute_Float(v5, 0x86u, (float *)&i_pcScrollbar);
      if ( (_BYTE)i_bHorizontal )
      {
        v8 = v4->m_iScrollableWidth;
        v9 = (double)(v8 - UIRegion::GetWidth((UIRegion *)&v4->vfptr));
      }
      else
      {
        v10 = v4->m_iScrollableHeight;
        v9 = (double)(v10 - UIRegion::GetHeight((UIRegion *)&v4->vfptr));
      }
      v11 = (unsigned __int64)(v9 * *(float *)&i_pcScrollbar);
      v4->m_iScrollableX = (_BYTE)i_bHorizontal != 0 ? v11 : 0;
      HIDWORD(v11) = (_BYTE)i_bHorizontal != 0 ? 0 : v11;
      LODWORD(v11) = v4->vfptr;
      v4->m_iScrollableY = HIDWORD(v11);
      (*(void (__thiscall **)(UIElement_Scrollable *))(v11 + 312))(v4);
    }
    else if ( i_eMessageID > 0xC && i_eMessageID <= 0x10 )
    {
      LOBYTE(v5) = i_eMessageID == 15 || i_eMessageID == 16;
      if ( i_eMessageID == 13 || i_eMessageID == 15 )
        v6 = 1;
      else
        LOBYTE(v6) = 0;
      v7 = ((int (__thiscall *)(UIElement_Scrollable *, int, const unsigned int, UIElement *))v4->vfptr[26].OnAction)(
             v4,
             i_bHorizontal,
             v6,
             v5);
      UIElement_Scrollable::SetScrollableXY(
        v4,
        v4->m_iScrollableX + ((_BYTE)i_bHorizontal != 0 ? v7 : 0),
        v4->m_iScrollableY + ((_BYTE)i_bHorizontal != 0 ? 0 : v7),
        0);
    }
  }
}

//----- (00474490) --------------------------------------------------------  // acclient.c:177362
void __thiscall UIElement_Scrollable::~UIElement_Scrollable(UIElement_Scrollable *this)
{
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_Scrollable::vftable;
  this->m_eHorizonalScrollbarID = 0;
  this->m_eVerticalScrollbarID = 0;
  UIElement::~UIElement((UIElement *)&this->vfptr);
}
// 79D4C0: using guessed type int (__thiscall *UIElement_Scrollable::vftable)(void *, char);

//----- (004744B0) --------------------------------------------------------  // acclient.c:177372
void __thiscall UIElement_Scrollable::PostInit(UIElement_Scrollable *this)
{
  UIElement_Scrollable *v1; // esi@1
  UIElement *v2; // eax@2
  UIElement *v3; // edi@3
  UIElement *v4; // eax@7
  UIElement *v5; // edi@8

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  if ( v1->m_eHorizonalScrollbarID )
  {
    v2 = UIElement::FindRelative((UIElement *)&v1->vfptr, v1->m_eHorizonalScrollbarID);
    if ( v2 )
    {
      v3 = (UIElement *)v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)11);
      if ( v3 )
      {
        if ( (UIElement_Scrollable *)UIElement::FindRelative(v3, v1->m_desc.m_elementID) == v1 )
          UIElement::RegisterForElementMessages(v3, (UIListener *)&v1->vfptr);
      }
    }
  }
  if ( v1->m_eVerticalScrollbarID )
  {
    v4 = UIElement::FindRelative((UIElement *)&v1->vfptr, v1->m_eVerticalScrollbarID);
    if ( v4 )
    {
      v5 = (UIElement *)v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)11);
      if ( v5 )
      {
        if ( (UIElement_Scrollable *)UIElement::FindRelative(v5, v1->m_desc.m_elementID) == v1 )
          UIElement::RegisterForElementMessages(v5, (UIListener *)&v1->vfptr);
      }
    }
  }
  UIElement_Scrollable::UpdateScrollbarSize_(v1, 1);
  UIElement_Scrollable::UpdateScrollbarSize_(v1, 0);
}

//----- (00474560) --------------------------------------------------------  // acclient.c:177413
int __thiscall UIElement_Scrollable::ListenToElementMessage(UIElement_Scrollable *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // ebx@1
  unsigned int v3; // eax@1
  UIElement_Scrollable *v4; // esi@1
  unsigned int v5; // ecx@1
  bool v6; // zf@1
  UIElement_Scrollbar *v7; // eax@4
  int result; // eax@5
  unsigned int v9; // ebp@6
  UIElement *v10; // eax@10
  int v11; // edi@11

  v2 = i_rMsg;
  v3 = i_rMsg->idElement;
  v4 = this;
  v5 = this->m_eHorizonalScrollbarID;
  v6 = i_rMsg->idElement == v5;
  if ( i_rMsg->idElement != v5 )
  {
    if ( v3 != v4->m_eVerticalScrollbarID )
      goto LABEL_6;
    v6 = v3 == v5;
  }
  LOBYTE(i_rMsg) = v6;
  v7 = UIElement_Scrollable::GetScrollbarPointer_(v4, v6);
  if ( (UIElement *)v7 == v2->pElement )
  {
    UIElement_Scrollable::HandleScrollbarMessage_(v4, (int)i_rMsg, v2->idMessage, v7);
    return 2;
  }
LABEL_6:
  v9 = v2->dwParam1;
  if ( v2->idMessage == 28
    && (v9 == 5 || v9 == 6)
    && v4->m_eVerticalScrollbarID
    && (v10 = UIElement::FindRelative((UIElement *)&v4->vfptr, v4->m_eVerticalScrollbarID)) != 0
    && (v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)11)) != 0
    && (UIElement_Scrollable *)UIElement::FindRelative((UIElement *)v11, v4->m_desc.m_elementID) == v4
    && !((*(_DWORD *)(v11 + 164) >> 4) & 1) )
  {
    UIElement_Scrollbar::HandleMouseWheel((UIElement_Scrollbar *)v11, v9);
    result = 2;
  }
  else
  {
    result = UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
  }
  return result;
}

//----- (00474630) --------------------------------------------------------  // acclient.c:177465
void __userpurge UIElement_Scrollable::OnSetAttribute(UIElement_Scrollable *this@<ecx>, int a2@<ebx>, BaseProperty *i_rcProperty)
{
  BaseProperty *v3; // esi@1
  UIElement_Scrollable *v4; // edi@1
  char *v5; // eax@1
  BasePropertyValue *v6; // ecx@3
  BaseProperty *v7; // esi@5
  BasePropertyValue *v8; // ecx@8
  BaseProperty *v9; // esi@10

  v3 = i_rcProperty;
  v4 = this;
  UIElement::OnSetAttribute((UIElement *)&this->vfptr, a2, i_rcProperty);
  v5 = (char *)&BaseProperty::GetPropertyName(v3)[-1].m_availableProperties.m_reqHash.m_intrusiveTable.m_aInplaceBuckets[9]
     + 3;
  if ( v5 )
  {
    if ( v5 == (char *)1 )
    {
      v6 = v3->m_pcPropertyValue;
      if ( v6 )
        ((void (__stdcall *)(BaseProperty **))v6->vfptr[42].__vecDelDtor)(&i_rcProperty);
      v7 = i_rcProperty;
      if ( i_rcProperty )
        UIElement_Scrollable::UpdateScrollbarSize_(v4, 0);
      v4->m_eVerticalScrollbarID = (unsigned int)v7;
    }
  }
  else
  {
    v8 = v3->m_pcPropertyValue;
    if ( v8 )
      ((void (__stdcall *)(BaseProperty **))v8->vfptr[42].__vecDelDtor)(&i_rcProperty);
    v9 = i_rcProperty;
    if ( i_rcProperty )
      UIElement_Scrollable::UpdateScrollbarSize_(v4, 1);
    v4->m_eHorizonalScrollbarID = (unsigned int)v9;
  }
}

//----- (004746C0) --------------------------------------------------------  // acclient.c:177506
void __thiscall UIElement_Scrollable::ResizeTo(UIElement_Scrollable *this, const int i_iWidth, const int i_iHeight)
{
  UIElement_Scrollable *v3; // esi@1
  int v4; // edi@1
  int v5; // ebx@1

  v3 = this;
  v4 = UIRegion::GetWidth((UIRegion *)&this->vfptr);
  v5 = UIRegion::GetHeight((UIRegion *)&v3->vfptr);
  UIElement::ResizeTo((UIElement *)&v3->vfptr, v4, i_iWidth, i_iHeight);
  if ( v4 != UIRegion::GetWidth((UIRegion *)&v3->vfptr) || v5 != UIRegion::GetHeight((UIRegion *)&v3->vfptr) )
  {
    UIElement_Scrollable::UpdateScrollbarSize_(v3, 1);
    UIElement_Scrollable::UpdateScrollbarSize_(v3, 0);
    UIElement_Scrollable::SetScrollableXY(v3, v3->m_iScrollableX, v3->m_iScrollableY, 0);
  }
}

//----- (00474730) --------------------------------------------------------  // acclient.c:177525
void __thiscall UIElement_Scrollable::ResizeScrollableArea(UIElement_Scrollable *this, int i_iWidth, int i_iHeight)
{
  UIElement_Scrollable *v3; // esi@1
  int v4; // edi@1
  int v5; // ebx@3

  v3 = this;
  v4 = this->m_iScrollableWidth;
  if ( v4 != i_iWidth || this->m_iScrollableHeight != i_iHeight )
  {
    v5 = this->m_iScrollableHeight;
    this->m_iScrollableHeight = i_iHeight;
    this->m_iScrollableWidth = i_iWidth;
    UIElement_Scrollable::UpdateScrollbarSize_(this, 1);
    UIElement_Scrollable::UpdateScrollbarSize_(v3, 0);
    UIElement::BroadcastElementMessage((UIElement *)&v3->vfptr, 0x32u, v4, v5);
  }
}

//----- (00474790) --------------------------------------------------------  // acclient.c:177545
UIElement_Scrollable *__thiscall UIElement_Scrollable::vector_deleting_destructor(UIElement_Scrollable *this, unsigned int a2)
{
  UIElement_Scrollable *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_Scrollable::vftable;
  this->m_eHorizonalScrollbarID = 0;
  this->m_eVerticalScrollbarID = 0;
  UIElement::~UIElement((UIElement *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79D4C0: using guessed type int (__thiscall *UIElement_Scrollable::vftable)(void *, char);

//----- (006EC140) --------------------------------------------------------  // acclient.c:767897
int _E1_71()
{
  return atexit(_E2_71);
}

