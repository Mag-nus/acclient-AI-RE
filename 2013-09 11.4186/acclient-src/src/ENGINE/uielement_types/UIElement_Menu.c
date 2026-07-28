/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_Menu
   Object     : ENGINE\uielement_types\UIElement_Menu.obj
   Functions  : 52
   Addresses  : 0046C990 - 0075E700 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0046C990) --------------------------------------------------------  // acclient.c:169226
void __userpurge UIElement_Menu::UIElement_Menu(UIElement_Menu *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_Menu *v4; // esi@1

  v4 = this;
  UIElement_Button::UIElement_Button((UIElement_Button *)&this->vfptr, a2, _layout, _full_desc);
  v4->m_popup = 0;
  v4->m_listBox = 0;
  v4->m_open = 0;
  v4->m_uiListBoxXBorder = 0;
  v4->m_uiListBoxYBorder = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement_Menu::vftable;
  v4->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
}
// 79CC28: using guessed type int (__thiscall *UIElement_Menu::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (0046C9E0) --------------------------------------------------------  // acclient.c:169244
UIElement_Menu *__thiscall UIElement_Menu::DynamicCast(UIElement_Menu *this, unsigned int i_eType)
{
  UIElement_Menu *result; // eax@1

  result = this;
  if ( i_eType != 6 && i_eType != 1 && i_eType != 12 )
    result = (UIElement_Menu *)(i_eType != 10 ? 0 : (unsigned int)this);
  return result;
}

//----- (0046CA10) --------------------------------------------------------  // acclient.c:169255
void __usercall UIElement_Menu::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_Menu *v3; // eax@1

  v3 = (UIElement_Menu *)operator new(0x738u);
  if ( v3 )
    UIElement_Menu::UIElement_Menu(v3, a1, _layout, _full_desc);
}

//----- (0046CA40) --------------------------------------------------------  // acclient.c:169265
void __thiscall UIElement_Menu::Flush(UIElement_Menu *this)
{
  UIElement_ListBox *v1; // ecx@1

  v1 = this->m_listBox;
  if ( v1 )
    UIElement_ListBox::Flush(v1);
}

//----- (0046CA50) --------------------------------------------------------  // acclient.c:169275
UIElement *__thiscall UIElement_Menu::GetItem(UIElement_Menu *this, int _index)
{
  UIElement_ListBox *v2; // ecx@1
  UIElement *result; // eax@2

  v2 = this->m_listBox;
  if ( v2 )
    result = UIElement_ListBox::GetItem(v2, _index);
  else
    result = 0;
  return result;
}

//----- (0046CA70) --------------------------------------------------------  // acclient.c:169289
UIElement *__thiscall UIElement_Menu::GetSelectedItem(UIElement_Menu *this)
{
  UIElement_ListBox *v1; // eax@1
  UIElement *result; // eax@2

  v1 = this->m_listBox;
  if ( v1 )
    result = v1->m_pSelectedItem;
  else
    result = 0;
  return result;
}

//----- (0046CA90) --------------------------------------------------------  // acclient.c:169303
char __thiscall UIElement_Menu::InsertItem(UIElement_Menu *this, UIElement *_insertThis, int _here)
{
  UIElement_Menu *v3; // edi@1
  char result; // al@2

  v3 = this;
  if ( this->m_listBox )
  {
    ((void (__thiscall *)(_DWORD, _DWORD))_insertThis->vfptr[22].OnLoseFocus)(_insertThis, 1);
    result = UIElement_ListBox::InsertItem(v3->m_listBox, _insertThis, _here);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046CAD0) --------------------------------------------------------  // acclient.c:169322
void __thiscall UIElement_Menu::UpdateState(UIElement_Menu *this)
{
  UIElement::SetAttribute_Bool((UIElement *)&this->vfptr, 0xEu, this->m_open);
}

//----- (0046CAF0) --------------------------------------------------------  // acclient.c:169328
void __thiscall UIElement_Menu::RecalculatePopupSize(UIElement_Menu *this)
{
  UIElement_Menu *v1; // esi@1
  UIRegion *v2; // ecx@2
  int v3; // edi@3
  int v4; // eax@3
  UIElement_ListBox *v5; // ecx@3

  v1 = this;
  if ( this->m_listBox )
  {
    v2 = (UIRegion *)&this->m_popup->vfptr;
    if ( v2 )
    {
      v3 = UIRegion::GetWidth(v2);
      v4 = UIRegion::GetHeight((UIRegion *)&v1->m_popup->vfptr);
      v5 = v1->m_listBox;
      if ( v5->m_desc.m_leftEdge == 1 && v5->m_desc.m_rightEdge == 1 )
        v3 = v1->m_uiListBoxXBorder + v5->m_iScrollableWidth;
      if ( v5->m_desc.m_topEdge == 1 && v5->m_desc.m_bottomEdge == 1 )
        v4 = v1->m_uiListBoxYBorder + v5->m_iScrollableHeight;
      ((void (__stdcall *)(int, int))v1->m_popup->vfptr[4].__vecDelDtor)(v3, v4);
    }
  }
}

//----- (0046CB80) --------------------------------------------------------  // acclient.c:169355
unsigned int __thiscall UIElement_ListBox::GetSelectedIndex(UIElement_ListBox *this)
{
  unsigned int v1; // edx@1
  unsigned int result; // eax@1
  UIElement *v3; // esi@2
  UIElement **v4; // ecx@2

  v1 = this->m_listItems.m_num;
  result = 0;
  if ( v1 )
  {
    v3 = this->m_pSelectedItem;
    v4 = this->m_listItems.m_data;
    while ( *v4 != v3 )
    {
      ++result;
      ++v4;
      if ( result >= v1 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    result = -1;
  }
  return result;
}

//----- (0046CBC0) --------------------------------------------------------  // acclient.c:169385
void __cdecl UIElement_Menu::Register()
{
  UIElement::RegisterElementClass(6u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_Menu::Create);
}

//----- (0046CBD0) --------------------------------------------------------  // acclient.c:169391
unsigned int __thiscall UIElement_Menu::GetNumItems(UIElement_Menu *this)
{
  UIElement_ListBox *v1; // eax@1
  unsigned int result; // eax@2

  v1 = this->m_listBox;
  if ( v1 )
    result = v1->m_listItems.m_num;
  else
    result = 0;
  return result;
}

//----- (0046CBF0) --------------------------------------------------------  // acclient.c:169405
unsigned int __thiscall UIElement_Menu::GetSelectedIndex(UIElement_Menu *this)
{
  UIElement_ListBox *v1; // ecx@1
  unsigned int v2; // edx@2
  unsigned int result; // eax@2
  UIElement *v4; // esi@3
  UIElement **v5; // ecx@3

  v1 = this->m_listBox;
  if ( v1 )
  {
    v2 = v1->m_listItems.m_num;
    result = 0;
    if ( v2 )
    {
      v4 = v1->m_pSelectedItem;
      v5 = v1->m_listItems.m_data;
      while ( *v5 != v4 )
      {
        ++result;
        ++v5;
        if ( result >= v2 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      result = -1;
    }
  }
  else
  {
    result = -1;
  }
  return result;
}

//----- (0046CC30) --------------------------------------------------------  // acclient.c:169444
void __thiscall UIElement_Menu::Open(UIElement_Menu *this)
{
  UIElement_Menu *v1; // esi@1
  UIElement_ListBox *v2; // eax@2
  unsigned int v3; // ebx@5
  int v4; // edi@6
  unsigned int v5; // edi@8
  unsigned int v6; // edi@8
  UIElement_Menu *v7; // [sp-2h] [bp-4h]@1

  v7 = this;
  v1 = this;
  if ( !this->m_open )
  {
    v2 = this->m_listBox;
    if ( v2 )
    {
      if ( v2->m_listItems.m_num && this->m_popup )
      {
        UIElement::GetAttribute_Bool((UIElement *)&this->vfptr, 5u, (bool *)&v7 + 3);
        UIElement::GetAttribute_Bool((UIElement *)&v1->vfptr, 3u, (bool *)&v7 + 2);
        v3 = UIRegion::GetScreenX0((UIRegion *)&v1->vfptr);
        if ( BYTE2(v7) )
        {
          v4 = UIRegion::GetWidth((UIRegion *)&v1->vfptr);
          v3 += (UIRegion::GetWidth((UIRegion *)&v1->m_popup->vfptr) - v4) / -2;
        }
        if ( BYTE3(v7) )
        {
          v5 = UIRegion::GetScreenY0((UIRegion *)&v1->vfptr);
          v6 = v5 - UIRegion::GetHeight((UIRegion *)&v1->m_popup->vfptr);
        }
        else
        {
          v6 = UIRegion::GetScreenY1((UIRegion *)&v1->vfptr);
        }
        ((void (__stdcall *)(unsigned int, unsigned int))v1->m_popup->vfptr[3].OnLoseFocus)(v3, v6);
        ((void (__stdcall *)(signed int))v1->m_popup->vfptr[2].__vecDelDtor)(1);
        v1->m_open = 1;
        UIElement::SetAttribute_Bool((UIElement *)&v1->vfptr, 0xEu, 1);
        UIElement::BroadcastElementMessage((UIElement *)&v1->vfptr, 8u, 0, 0);
      }
    }
  }
}

//----- (0046CD20) --------------------------------------------------------  // acclient.c:169491
void __thiscall UIElement_Menu::Close(UIElement_Menu *this)
{
  UIElement_Menu *v1; // esi@1
  UIElement *v2; // ecx@2

  v1 = this;
  if ( this->m_open )
  {
    v2 = this->m_popup;
    if ( v2 )
    {
      ((void (__stdcall *)(_DWORD))v2->vfptr[2].__vecDelDtor)(0);
      v1->m_open = 0;
      UIElement::SetAttribute_Bool((UIElement *)&v1->vfptr, 0xEu, 0);
      UIElement::BroadcastElementMessage((UIElement *)&v1->vfptr, 9u, 0, 0);
    }
  }
}

//----- (0046CD60) --------------------------------------------------------  // acclient.c:169511
void __thiscall UIElement_Menu::NewSelection(UIElement_Menu *this, bool _broadcast)
{
  UIElement_Menu *v2; // esi@1
  UIElement *v3; // eax@3
  UIElement_Text *v4; // edi@4
  UIElement_ListBox *v5; // eax@5
  UIElement *v6; // ecx@6
  UIElement_Text *v7; // eax@7
  PStringBase<unsigned short> *v8; // eax@8
  UIElement_ListBox *v9; // eax@11
  unsigned int v10; // eax@12
  unsigned int selection_display_ID; // [sp+4h] [bp-8h]@2
  PStringBase<unsigned short> result; // [sp+8h] [bp-4h]@8

  v2 = this;
  if ( this->m_listBox )
  {
    UIElement::GetAttribute_Enum((UIElement *)&this->vfptr, 8u, &selection_display_ID);
    if ( selection_display_ID )
    {
      v3 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, selection_display_ID);
      if ( v3 )
      {
        v4 = (UIElement_Text *)v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
        if ( v4 )
        {
          v5 = v2->m_listBox;
          if ( v5 && (v6 = v5->m_pSelectedItem) != 0 )
          {
            v7 = (UIElement_Text *)((int (__stdcall *)(signed int))v6->vfptr[12].OnAction)(12);
            if ( v7 )
            {
              v8 = UIElement_Text::GetPreParsedText(v7, &result);
              UIElement_Text::SetText(v4, v8);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
            }
          }
          else
          {
            UIElement_Text::ClearAllText(v4);
          }
        }
      }
    }
    if ( _broadcast )
    {
      v9 = v2->m_listBox;
      if ( v9 )
      {
        v10 = (unsigned int)v9->m_pSelectedItem;
        if ( v10 )
        {
          UIElement::BroadcastElementMessage((UIElement *)&v2->vfptr, 7u, *(_DWORD *)(v10 + 740), v10);
          return;
        }
      }
      else
      {
        v10 = 0;
      }
      UIElement::BroadcastElementMessage((UIElement *)&v2->vfptr, 7u, 0, v10);
    }
  }
}

//----- (0046CE40) --------------------------------------------------------  // acclient.c:169577
void __thiscall UIElement_Menu::~UIElement_Menu(UIElement_Menu *this)
{
  UIElement_Menu *v1; // esi@1
  UIElement *v2; // ecx@1
  UIElement *v3; // ecx@4
  UIElement *v4; // ecx@6

  v1 = this;
  v2 = this->m_popup;
  v1->vfptr = (IInputActionCallbackVtbl *)&UIElement_Menu::vftable;
  v1->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  if ( v2 )
    UIElement::UnregisterForElementMessages(v2, (UIListener *)&v1->vfptr);
  if ( v1->m_open )
  {
    v3 = v1->m_popup;
    if ( v3 )
    {
      ((void (__stdcall *)(_DWORD))v3->vfptr[2].__vecDelDtor)(0);
      v1->m_open = 0;
      UIElement::SetAttribute_Bool((UIElement *)&v1->vfptr, 0xEu, 0);
      UIElement::BroadcastElementMessage((UIElement *)&v1->vfptr, 9u, 0, 0);
    }
  }
  v4 = v1->m_popup;
  if ( v4 )
  {
    UIElement::AddToDeleteQueue(v4);
    v1->m_popup = 0;
  }
  UIElement_Button::~UIElement_Button((UIElement_Button *)&v1->vfptr);
}
// 79CC28: using guessed type int (__thiscall *UIElement_Menu::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (0046CEC0) --------------------------------------------------------  // acclient.c:169613
char __thiscall UIElement_Menu::InqAvailableProperties(UIElement_Menu *this, AvailablePropertySet *_set)
{
  AvailablePropertySet *v2; // edi@1
  char v3; // bl@1
  AvailablePropertySet *v4; // esi@3
  char result; // al@4

  v2 = _set;
  v3 = 1;
  if ( !UIElement::InqAvailableProperties((UIElement *)&this->vfptr, _set) )
    v3 = 0;
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&_set);
  v4 = _set;
  if ( _set )
  {
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)_set, 0xDu, v2) )
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

//----- (0046CF10) --------------------------------------------------------  // acclient.c:169641
UIElement_Text *__thiscall UIElement_Menu::InsertTextItem(UIElement_Menu *this, StringInfo *_text, int _here)
{
  UIElement_Menu *v3; // ebp@1
  UIElementManager *v4; // esi@1
  LayoutDesc *v5; // edi@3
  LayoutDesc *v6; // eax@4
  ElementDesc *v7; // eax@6
  ElementDesc *v8; // esi@6
  UIElement_Text *result; // eax@9
  UIElement_Text *v10; // eax@10
  UIElement_Text *v11; // ebx@10
  DBObjGrabber<LayoutDesc> layout; // [sp+10h] [bp-Ch]@2
  IDClass<_tagDataID,32,0> layoutID; // [sp+14h] [bp-8h]@2
  unsigned int textItemID; // [sp+18h] [bp-4h]@1

  v3 = this;
  UIElement::GetAttribute_Enum((UIElement *)&this->vfptr, 9u, &textItemID);
  v4 = UIElementManager::s_pInstance;
  if ( !UIElementManager::s_pInstance )
    return 0;
  layoutID.id = INVALID_DID_64.id;
  layout.m_object = 0;
  if ( !UIElement::GetAttribute_DataID((UIElement *)&v3->vfptr, 0xAu, &layoutID)
    || (DBObjGrabber<LayoutDesc>::set(&layout, layoutID), (v5 = layout.m_object) == 0) )
  {
    v6 = v3->m_layout;
    if ( !v6 )
      return 0;
    DBObjGrabber<LayoutDesc>::set(&layout, v6->m_DID);
    v5 = layout.m_object;
    if ( !layout.m_object )
      return 0;
  }
  v7 = UIElementManager::CreateChildElement(v4, 0, v5, textItemID);
  v8 = v7;
  if ( !v7 )
  {
    if ( v5 )
      v5->vfptr->Release((Interface *)v5);
    return 0;
  }
  v10 = (UIElement_Text *)(*(int (__thiscall **)(ElementDesc *, signed int))&v7->vfptr[4].gap4[0])(v7, 12);
  v11 = v10;
  if ( v10 )
  {
    UIElement_Text::SetStringInfo(v10, _text);
    if ( UIElement_Menu::InsertItem(v3, (UIElement *)&v11->vfptr, _here) )
    {
      DBObjGrabber<StringTable>::~DBObjGrabber<StringTable>((DBObjGrabber<ACCharGenData> *)&layout);
      result = v11;
    }
    else
    {
      v8->vfptr->__vecDelDtor((StateDesc *)v8, 1u);
      DBObjGrabber<StringTable>::~DBObjGrabber<StringTable>((DBObjGrabber<ACCharGenData> *)&layout);
      result = 0;
    }
  }
  else
  {
    v8->vfptr->__vecDelDtor((StateDesc *)v8, 1u);
    if ( !v5 )
      return 0;
    v5->vfptr->Release((Interface *)v5);
    result = 0;
  }
  return result;
}

//----- (0046D040) --------------------------------------------------------  // acclient.c:169711
UIElement *__thiscall UIElement_Menu::ReplaceTextItem(UIElement_Menu *this, StringInfo *_text, int _here)
{
  UIElement_Menu *v3; // ebp@1
  UIElement_ListBox *v4; // ecx@1
  char v5; // bl@1
  unsigned int v6; // esi@2
  signed int v7; // eax@2
  UIElement **v8; // edx@3
  UIElement *v9; // eax@13
  UIElement *v10; // esi@13

  v3 = this;
  v4 = this->m_listBox;
  v5 = 0;
  if ( v4 )
  {
    v6 = v4->m_listItems.m_num;
    v7 = 0;
    if ( v6 )
    {
      v8 = v4->m_listItems.m_data;
      while ( *v8 != v4->m_pSelectedItem )
      {
        ++v7;
        ++v8;
        if ( v7 >= v6 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      v7 = -1;
    }
  }
  else
  {
    v7 = -1;
  }
  if ( v7 == _here )
    v5 = 1;
  if ( (signed int)v4->m_listItems.m_num > _here )
    UIElement_ListBox::DeleteItem(v4, _here);
  v9 = (UIElement *)UIElement_Menu::InsertTextItem(v3, _text, _here);
  v10 = v9;
  if ( v5 )
    UIElement_ListBox::SetSelectedItem(v3->m_listBox, v9, 1);
  return v10;
}

//----- (0046D0D0) --------------------------------------------------------  // acclient.c:169762
void __thiscall UIElement_Menu::SetSelectedItem(UIElement_Menu *this, UIElement *_select, bool _broadcast)
{
  UIElement_Menu *v3; // esi@1
  UIElement_ListBox *v4; // ecx@1

  v3 = this;
  v4 = this->m_listBox;
  if ( v4 )
  {
    UIElement_ListBox::SetSelectedItem(v4, _select, _broadcast);
    UIElement_Menu::NewSelection(v3, _broadcast);
  }
}

//----- (0046D100) --------------------------------------------------------  // acclient.c:169777
void __thiscall UIElement_Menu::SetVisible(UIElement_Menu *this, int _visible)
{
  UIElement_Menu *v2; // esi@1

  v2 = this;
  UIElement::SetVisible((UIElement *)&this->vfptr, _visible);
  if ( !UIElement::IsVisible((UIElement *)&v2->vfptr) )
  {
    if ( v2->m_open )
      UIElement_Menu::Close(v2);
  }
}

//----- (0046D130) --------------------------------------------------------  // acclient.c:169791
char __thiscall UIElement_Menu::Deactivate(UIElement_Menu *this)
{
  UIElement_Menu *v1; // esi@1
  char v2; // bl@1
  UIElement *v3; // ecx@3

  v1 = this;
  v2 = UIElement::Deactivate((UIElement *)&this->vfptr);
  if ( v2 )
  {
    if ( v1->m_open )
    {
      v3 = v1->m_popup;
      if ( v3 )
      {
        ((void (__stdcall *)(_DWORD))v3->vfptr[2].__vecDelDtor)(0);
        v1->m_open = 0;
        UIElement::SetAttribute_Bool((UIElement *)&v1->vfptr, 0xEu, 0);
        UIElement::BroadcastElementMessage((UIElement *)&v1->vfptr, 9u, 0, 0);
      }
    }
  }
  return v2;
}

//----- (0046D180) --------------------------------------------------------  // acclient.c:169817
int __thiscall UIElement_Menu::ListenToElementMessage(UIElement_Menu *this, UIElementMessageInfo *i_rMsg)
{
  UIElement_Menu *v2; // edi@1
  UIElement *v3; // ecx@1
  int result; // eax@5
  unsigned int v5; // esi@7
  UIElement *v6; // ecx@17
  signed int v7; // eax@17

  v2 = this;
  v3 = i_rMsg->pElement;
  if ( v3 == v2->m_popup )
  {
    if ( i_rMsg->idMessage == 42 && v2->m_open && !(*((_BYTE *)&v2->0 + 164) & 1) )
    {
      UIElement_Menu::Close(v2);
      return 2;
    }
    return 2;
  }
  if ( (UIElement_ListBox *)v3 == v2->m_listBox )
  {
    v5 = i_rMsg->idMessage;
    if ( v5 == 4 )
    {
      UIElement_Menu::NewSelection(v2, 1);
    }
    else
    {
      if ( v5 == 50 )
      {
        UIElement_Menu::RecalculatePopupSize(v2);
        return 2;
      }
      if ( v5 != 67 )
        return 2;
    }
    UIElement_Menu::Close(v2);
    return 2;
  }
  if ( (UIElement_ListBox *)((int (*)(void))v3->vfptr[13].OnAction)() != v2->m_listBox )
  {
    if ( (UIElement_Menu *)i_rMsg->pElement == v2 )
    {
      if ( i_rMsg->idMessage == 1 )
      {
        if ( v2->m_open )
        {
          UIElement_Menu::Close(v2);
          result = 2;
        }
        else
        {
          UIElement_Menu::Open(v2);
          result = 2;
        }
        return result;
      }
      if ( i_rMsg->idMessage == 27 )
      {
        UIElement_Menu::UpdateState(v2);
        return 2;
      }
    }
    return UIElement_Button::ListenToElementMessage((UIElement_Button *)&v2->vfptr, i_rMsg);
  }
  if ( i_rMsg->idMessage == 27 )
  {
    v6 = i_rMsg->pElement;
    v7 = v6->m_state;
    if ( !v7 )
      v7 = 1;
    switch ( v7 )
    {
      case 2:
        if ( !i_rMsg->dwParam1 )
          v7 = 1;
        break;
      case 1:
        if ( i_rMsg->dwParam1 )
          v7 = 2;
        break;
      case 7:
        if ( !i_rMsg->dwParam1 )
          v7 = 6;
        break;
      case 6:
        if ( i_rMsg->dwParam1 )
          v7 = 7;
        break;
      default:
        break;
    }
    if ( v7 != v6->m_state )
      ((void (__stdcall *)(signed int))v6->vfptr[13].__vecDelDtor)(v7);
  }
  return 2;
}

//----- (0046D310) --------------------------------------------------------  // acclient.c:169917
void __thiscall UIElement_Menu::MakePopup(UIElement_Menu *this)
{
  UIElement_Menu *v1; // edi@1
  UIElement *v2; // ecx@1
  UIElementManager *v3; // esi@3
  LayoutDesc *v4; // ebx@5
  LayoutDesc *v5; // eax@6
  ElementDesc *v6; // eax@8
  UIElement *v7; // esi@8
  DBObjGrabber<LayoutDesc> layout; // [sp+8h] [bp-8h]@4
  IDClass<_tagDataID,32,0> layoutID; // [sp+Ch] [bp-4h]@4

  v1 = this;
  v2 = this->m_popup;
  if ( v2 )
  {
    UIElement::AddToDeleteQueue(v2);
    v1->m_popup = 0;
  }
  v3 = UIElementManager::s_pInstance;
  if ( UIElementManager::s_pInstance )
  {
    if ( (layout.m_object = 0,
          layoutID.id = INVALID_DID_64.id,
          UIElement::GetAttribute_DataID((UIElement *)&v1->vfptr, 7u, &layoutID))
      && (DBObjGrabber<LayoutDesc>::set(&layout, layoutID), (v4 = layout.m_object) != 0)
      || (v5 = v1->m_layout) != 0 && (DBObjGrabber<LayoutDesc>::set(&layout, v5->m_DID), (v4 = layout.m_object) != 0) )
    {
      UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 6u, (unsigned int *)&layout);
      v6 = UIElementManager::CreateRootElement(v3, v4, (unsigned int)layout.m_object);
      v7 = (UIElement *)v6;
      if ( v6 )
      {
        ((void (__thiscall *)(ElementDesc *, _DWORD))v6->vfptr->HandleNode)(v6, 0);
        UIElement::SetAttribute_Bool(v7, 0x33u, 1);
        UIElement::SetAttribute_Bool(v7, 0x34u, 1);
        v1->m_popup = v7;
        UIElement::RegisterForElementMessages(v7, (UIListener *)&v1->vfptr);
      }
      if ( v4 )
        v4->vfptr->Release((Interface *)v4);
    }
  }
}

//----- (0046D400) --------------------------------------------------------  // acclient.c:169963
UIElement_Menu *__thiscall UIElement_Menu::scalar_deleting_destructor(UIElement_Menu *this, unsigned int a2)
{
  UIElement_Menu *v2; // esi@1

  v2 = this;
  UIElement_Menu::~UIElement_Menu(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0046D420) --------------------------------------------------------  // acclient.c:169975
UIElement_Text *__thiscall UIElement_Menu::AddTextItem(UIElement_Menu *this, StringInfo *_text)
{
  return UIElement_Menu::InsertTextItem(this, _text, this->m_listBox->m_listItems.m_num);
}

//----- (0046D440) --------------------------------------------------------  // acclient.c:169981
void __thiscall UIElement_Menu::Initialize(UIElement_Menu *this)
{
  UIElement_Menu *v1; // esi@1
  UIElement *v2; // eax@2
  UIRegion *v3; // ecx@8
  int v4; // edi@9
  int v5; // eax@9
  UIRegion *v6; // ecx@9
  int v7; // edi@9
  unsigned int default_sel_item; // [sp+4h] [bp-4h]@1

  default_sel_item = (unsigned int)this;
  v1 = this;
  UIElement_Menu::MakePopup(this);
  if ( v1->m_popup )
  {
    UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 2u, &default_sel_item);
    v2 = UIElement::GetChildRecursive(v1->m_popup, default_sel_item);
    if ( v2 )
      v1->m_listBox = (UIElement_ListBox *)v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)5);
    if ( v1->m_listBox )
    {
      UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 1u, &default_sel_item);
      if ( default_sel_item )
        UIElement_ListBox::SetSelectedItemByID(v1->m_listBox, default_sel_item, 1);
    }
  }
  UIElement::Initialize((UIElement *)&v1->vfptr);
  if ( v1->m_popup )
  {
    v3 = (UIRegion *)&v1->m_listBox->vfptr;
    if ( v3 )
    {
      v4 = UIRegion::GetWidth(v3);
      v5 = UIRegion::GetWidth((UIRegion *)&v1->m_popup->vfptr);
      v6 = (UIRegion *)&v1->m_popup->vfptr;
      v1->m_uiListBoxXBorder = v5 - v4;
      v7 = UIRegion::GetHeight(v6);
      v1->m_uiListBoxYBorder = v7 - UIRegion::GetHeight((UIRegion *)&v1->m_listBox->vfptr);
    }
  }
}

//----- (006EBE10) --------------------------------------------------------  // acclient.c:767696
int _E73_69()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_32, "None");
  return atexit(_E74_51);
}

//----- (006EBE30) --------------------------------------------------------  // acclient.c:767703
int _E76_37()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_32, "Speed");
  return atexit(_E77_65);
}

//----- (006EBE50) --------------------------------------------------------  // acclient.c:767710
int _E79_35()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_32, "Noise");
  return atexit(_E80_36);
}

//----- (006EBE70) --------------------------------------------------------  // acclient.c:767717
int _E82_25()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_32, "Sine");
  return atexit(_E83_25);
}

//----- (006EBE90) --------------------------------------------------------  // acclient.c:767724
int _E85_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_32, "Square");
  return atexit(_E86_17);
}

//----- (006EBEB0) --------------------------------------------------------  // acclient.c:767731
int _E88_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_32, "Bounce");
  return atexit(_E89_28);
}

//----- (006EBED0) --------------------------------------------------------  // acclient.c:767738
int _E91_35()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_32, "Perlin");
  return atexit(_E92_32);
}

//----- (006EBEF0) --------------------------------------------------------  // acclient.c:767745
int _E94_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_32, "Fractal");
  return atexit(sub_75E670);
}

//----- (006EBF10) --------------------------------------------------------  // acclient.c:767752
int _E97_35()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_32, "FrameLoop");
  return atexit(_E98_47);
}

//----- (006EBF30) --------------------------------------------------------  // acclient.c:767759
void _E100_27()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_44, PFID_A8R8G8B8);
}

//----- (006EBF40) --------------------------------------------------------  // acclient.c:767765
int _E118_21()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_8, "Misc.TooltipEnable");
  return atexit(_E119_70);
}

//----- (006EBF60) --------------------------------------------------------  // acclient.c:767772
int _E121_19()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_8, "Misc.TooltipDelay");
  return atexit(_E122_57);
}

//----- (006EBF80) --------------------------------------------------------  // acclient.c:767779
int _E1_64()
{
  return atexit(_E2_64);
}

//----- (0075E520) --------------------------------------------------------  // acclient.c:886579
void __cdecl _E74_51()
{
  char *v0; // esi@1

  v0 = &waveform_None_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E550) --------------------------------------------------------  // acclient.c:886592
void __cdecl _E77_65()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E580) --------------------------------------------------------  // acclient.c:886605
void __cdecl _E80_36()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E5B0) --------------------------------------------------------  // acclient.c:886618
void __cdecl _E83_25()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E5E0) --------------------------------------------------------  // acclient.c:886631
void __cdecl _E86_17()
{
  char *v0; // esi@1

  v0 = &waveform_Square_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E610) --------------------------------------------------------  // acclient.c:886644
void __cdecl _E89_28()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E640) --------------------------------------------------------  // acclient.c:886657
void __cdecl _E92_32()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E670) --------------------------------------------------------  // acclient.c:886670
void __cdecl sub_75E670()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E6A0) --------------------------------------------------------  // acclient.c:886683
void __cdecl _E98_47()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E6D0) --------------------------------------------------------  // acclient.c:886696
void __cdecl _E119_70()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E700) --------------------------------------------------------  // acclient.c:886709
void __cdecl _E122_57()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

