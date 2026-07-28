/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_Button
   Object     : ENGINE\uielement_types\UIElement_Button.obj
   Functions  : 22
   Addresses  : 00471B50 - 0075E8C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00471B50) --------------------------------------------------------  // acclient.c:174408
void __userpurge UIElement_Button::UIElement_Button(UIElement_Button *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_Button *v4; // esi@1

  v4 = this;
  UIElement_Text::UIElement_Text((UIElement_Text *)&this->vfptr, a2, _layout, _full_desc);
  v4->mousePressedOnButton = 0;
  v4->hotClickingInProgress = 0;
  LODWORD(v4->nextHotClickTime) = 0;
  HIDWORD(v4->nextHotClickTime) = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement_Button::vftable;
  v4->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
}
// 79D228: using guessed type int (__thiscall *UIElement_Button::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00471BA0) --------------------------------------------------------  // acclient.c:174425
UIElement_Button *__thiscall UIElement_Button::DynamicCast(UIElement_Button *this, unsigned int i_eType)
{
  UIElement_Button *result; // eax@1

  result = this;
  if ( i_eType != 1 && i_eType != 12 )
    result = (UIElement_Button *)(i_eType != 10 ? 0 : (unsigned int)this);
  return result;
}

//----- (00471BC0) --------------------------------------------------------  // acclient.c:174436
void __thiscall UIElement_Button::~UIElement_Button(UIElement_Button *this)
{
  UIElement_Text *v1; // esi@1
  bool v2; // al@1

  v1 = (UIElement_Text *)this;
  v2 = this->hotClickingInProgress;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_Button::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  if ( v2 )
  {
    this->hotClickingInProgress = 0;
    UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
  }
  UIElement_Text::~UIElement_Text(v1);
}
// 79D228: using guessed type int (__thiscall *UIElement_Button::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00471C00) --------------------------------------------------------  // acclient.c:174456
UIElement *__usercall UIElement_Button::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x720u);
  if ( v3 )
  {
    UIElement_Text::UIElement_Text((UIElement_Text *)v3, a1, _layout, _full_desc);
    *((_BYTE *)v3 + 1808) = 0;
    *((_BYTE *)v3 + 1809) = 0;
    *((_DWORD *)v3 + 454) = 0;
    *((_DWORD *)v3 + 455) = 0;
    *(_DWORD *)v3 = &UIElement_Button::vftable;
    *((_DWORD *)v3 + 386) = &UIOption_Menu::vftable;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79D228: using guessed type int (__thiscall *UIElement_Button::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00471C60) --------------------------------------------------------  // acclient.c:174483
void __thiscall UIElement_Button::ListenToGlobalMessage(UIElement_Button *this, unsigned int _messageID, int _data_int)
{
  UIElement_Button *v3; // esi@1
  long double v4; // st7@3
  char v5; // cl@3

  v3 = this;
  UIElement_Text::ListenToGlobalMessage((UIElement_Text *)&this->vfptr, _messageID, _data_int);
  if ( _messageID == 3 && v3->hotClickingInProgress )
  {
    v4 = *(double *)&Timer::cur_time;
    v5 = *((_BYTE *)&v3->0 + 164) & 1;
    if ( !v5 && COERCE_DOUBLE(Timer::cur_time.Cmd) > v3->nextHotClickTime )
      v3->nextHotClickTime = *(double *)&Timer::cur_time;
    if ( v5 )
    {
      if ( v4 >= v3->nextHotClickTime )
      {
        UIElement::BroadcastElementMessage((UIElement *)&v3->vfptr, 2u, 0, 0);
        UIElement::GetAttribute_Float((UIElement *)&v3->vfptr, 0x11u, (float *)&_data_int);
        v3->nextHotClickTime = *(float *)&_data_int + v3->nextHotClickTime;
      }
    }
  }
}

//----- (00471CF0) --------------------------------------------------------  // acclient.c:174510
void __thiscall UIElement_Button::UpdateState_(UIElement_Button *this)
{
  UIElement_Button *v1; // esi@1
  unsigned int v2; // edi@2
  bool v3; // cl@3
  UIElement_Button *v4; // [sp+0h] [bp-4h]@1

  v4 = this;
  v1 = this;
  UIElement::GetAttribute_Bool((UIElement *)&this->vfptr, 0xDu, (bool *)&v4 + 1);
  if ( BYTE1(v4) )
  {
    v2 = 13;
  }
  else
  {
    UIElement::GetAttribute_Bool((UIElement *)&v1->vfptr, 0xEu, (bool *)&v4 + 2);
    UIElement::GetAttribute_Bool((UIElement *)&v1->vfptr, 0x13u, (bool *)&v4 + 3);
    v2 = BYTE2(v4) != 0 ? 6 : 1;
    v3 = v1->mousePressedOnButton;
    if ( v3 || BYTE3(v4) && *((_BYTE *)&v1->0 + 164) & 1 )
      v2 = BYTE2(v4) != 0 ? 7 : 2;
    if ( v3 && *((_BYTE *)&v1->0 + 164) & 1 )
      v2 = BYTE2(v4) != 0 ? 8 : 3;
  }
  if ( ElementDesc::AccessStateDesc(&v1->m_desc, v2) )
    v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, v2);
}

//----- (00471DA0) --------------------------------------------------------  // acclient.c:174540
char __thiscall UIElement_Button::SetState(UIElement_Button *this, unsigned int _state)
{
  UIElement *v2; // esi@1
  bool v3; // al@1
  unsigned int v4; // edi@1
  char result; // al@4
  UIElement_Button *v6; // [sp-2h] [bp-4h]@1

  v6 = this;
  v2 = (UIElement *)this;
  v3 = UIElement::GetAttribute_Bool((UIElement *)&this->vfptr, 0xBu, (bool *)&v6 + 3);
  v4 = _state;
  if ( v3 )
  {
    UIElement::GetAttribute_Bool(v2, 0xEu, (bool *)&_state);
    if ( v4 == 6 )
    {
      if ( !(_BYTE)_state )
      {
        UIElement::SetAttribute_Bool(v2, 0xEu, 1);
        return 1;
      }
    }
    else if ( v4 == 1 && (_BYTE)_state )
    {
      UIElement::SetAttribute_Bool(v2, 0xEu, 0);
      return 1;
    }
  }
  LOBYTE(_state) = v4 == 13;
  BYTE2(v6) = 0;
  UIElement::GetAttribute_Bool(v2, 0xDu, (bool *)&v6 + 2);
  if ( (v4 == 13) == BYTE2(v6) )
  {
    result = UIElement::SetState(v2, v4);
  }
  else
  {
    UIElement::SetAttribute_Bool(v2, 0xDu, _state);
    result = 1;
  }
  return result;
}

//----- (00471E50) --------------------------------------------------------  // acclient.c:174585
char __thiscall UIElement_Button::HandleButtonClick(UIElement_Button *this, UIElementMessageInfo *i_rMsg)
{
  char v2; // bl@1
  UIElementManager *v3; // esi@5
  unsigned int eInputAction; // [sp+8h] [bp-4Ch]@1
  InputEvent inputEvent; // [sp+Ch] [bp-48h]@6

  v2 = 0;
  if ( !UIElement::GetAttribute_Enum((UIElement *)&this->vfptr, 0x12u, &eInputAction) )
    return v2;
  v2 = 1;
  if ( eInputAction != 1 )
  {
    if ( ICIDM::s_cidm )
    {
      if ( ((int (*)(void))ICIDM::s_cidm->vfptr->GetActionMap)() )
      {
        v3 = UIElementManager::s_pInstance;
        if ( UIElementManager::s_pInstance )
        {
          InputEvent::InputEvent(&inputEvent);
          inputEvent.m_InputAction = eInputAction;
          inputEvent.m_ToggleType = 3;
          inputEvent.m_fStart = 1;
          v3->vfptr->ActionHandler((CInputHandler *)v3, &inputEvent);
          return v2;
        }
      }
    }
  }
  return 0;
}

//----- (00471ED0) --------------------------------------------------------  // acclient.c:174619
UIElement_Text *__thiscall UIElement_Button::scalar_deleting_destructor(UIElement_Button *this, unsigned int a2)
{
  UIElement_Text *v2; // esi@1
  bool v3; // al@1

  v2 = (UIElement_Text *)this;
  v3 = this->hotClickingInProgress;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_Button::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  if ( v3 )
  {
    this->hotClickingInProgress = 0;
    UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
  }
  UIElement_Text::~UIElement_Text(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79D228: using guessed type int (__thiscall *UIElement_Button::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00471F20) --------------------------------------------------------  // acclient.c:174642
void __cdecl UIElement_Button::Register()
{
  UIElement::RegisterElementClass(1u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_Button::Create);
}

//----- (00471F30) --------------------------------------------------------  // acclient.c:174648
void __thiscall UIElement_Button::PostInit(UIElement_Button *this)
{
  UIElement_Button *v1; // esi@1

  v1 = this;
  UIElement_Scrollable::PostInit((UIElement_Scrollable *)&this->vfptr);
  UIElement_Button::UpdateState_(v1);
}

//----- (00471F40) --------------------------------------------------------  // acclient.c:174658
void __userpurge UIElement_Button::OnSetAttribute(UIElement_Button *this@<ecx>, int a2@<ebx>, BaseProperty *_attribute)
{
  BaseProperty *v3; // edi@1
  UIElement_Button *v4; // esi@1
  IInputActionCallbackVtbl *v5; // edi@2
  int v6; // eax@2
  BasePropertyValue *v7; // ecx@4

  v3 = _attribute;
  v4 = this;
  UIElement_Text::OnSetAttribute((UIElement_Text *)&this->vfptr, a2, _attribute);
  switch ( BaseProperty::GetPropertyName(v3) )
  {
    case 0xDu:
      UIElement_Button::UpdateState_(v4);
      v5 = v4->vfptr;
      v6 = ((int (__thiscall *)(UIElement_Button *))v4->vfptr[24].OnAction)(v4);
      ((void (__thiscall *)(UIElement_Button *, int))v5[22].OnLoseFocus)(v4, v6);
      break;
    case 0xEu:
    case 0x13u:
      UIElement_Button::UpdateState_(v4);
      break;
    case 0xFu:
      v7 = v3->m_pcPropertyValue;
      LOBYTE(_attribute) = 0;
      if ( v7 )
        ((void (__stdcall *)(BaseProperty **))v7->vfptr[28].__vecDelDtor)(&_attribute);
      if ( v4->hotClickingInProgress )
      {
        if ( !(_BYTE)_attribute )
        {
          v4->hotClickingInProgress = 0;
          UIListener::UnRegisterForGlobalMessage((UIListener *)&v4->vfptr, 3u);
        }
      }
      break;
    default:
      return;
  }
}

//----- (00471FF0) --------------------------------------------------------  // acclient.c:174701
void __thiscall UIElement_Button::MouseDown(UIElement_Button *this, unsigned int _xWindow, unsigned int _yWindow, unsigned int _button)
{
  unsigned int v4; // edi@1
  UIElement_Button *v5; // esi@1
  unsigned int v6; // eax@1
  float hot_click_first_interval; // [sp+0h] [bp-4h]@1

  hot_click_first_interval = *(float *)&this;
  v4 = _button;
  v5 = this;
  UIElement_Text::MouseDown((UIElement_Text *)&this->vfptr, _xWindow, _yWindow, _button);
  v6 = v5->m_nFlags;
  if ( (!((v5->m_nFlags >> 23) & 1) && v4 == 10 || v4 == 7) && !((v6 >> 19) & 1) && !((v6 >> 18) & 1) )
  {
    v5->mousePressedOnButton = 1;
    UIElement_Button::UpdateState_(v5);
    UIElement::GetAttribute_Bool((UIElement *)&v5->vfptr, 0xDu, (bool *)&_button);
    UIElement::GetAttribute_Bool((UIElement *)&v5->vfptr, 0xCu, (bool *)&_yWindow);
    if ( !(_BYTE)_button || (_BYTE)_yWindow )
    {
      UIElement::GetAttribute_Bool((UIElement *)&v5->vfptr, 0xFu, (bool *)&_xWindow);
      if ( (_BYTE)_xWindow )
      {
        UIElement::BroadcastElementMessage((UIElement *)&v5->vfptr, 2u, v4, 0);
        v5->hotClickingInProgress = 1;
        UIListener::RegisterForGlobalMessage((UIListener *)&v5->vfptr, 3u);
        UIElement::GetAttribute_Float((UIElement *)&v5->vfptr, 0x10u, &hot_click_first_interval);
        v5->nextHotClickTime = hot_click_first_interval + COERCE_DOUBLE(Timer::cur_time.Cmd);
      }
    }
  }
}

//----- (004720E0) --------------------------------------------------------  // acclient.c:174735
void __thiscall UIElement_Button::MouseUp(UIElement_Button *this, unsigned int _xElement, unsigned int _yElement, unsigned int _button)
{
  unsigned int v4; // edi@1
  UIElement_Button *v5; // esi@1
  bool v6; // bl@1
  int v7; // eax@7
  bool v8; // al@13
  UIElement_Button *v9; // [sp-2h] [bp-4h]@1

  v9 = this;
  v4 = _button;
  v5 = this;
  UIElement_Text::MouseUp((UIElement_Text *)&this->vfptr, _xElement, _yElement, _button);
  UIElement::GetAttribute_Bool((UIElement *)&v5->vfptr, 0xDu, (bool *)&_yElement);
  UIElement::GetAttribute_Bool((UIElement *)&v5->vfptr, 0xCu, (bool *)&v9 + 3);
  v6 = 0;
  if ( v5->mousePressedOnButton && (v4 == 7 || v4 == 10) )
  {
    if ( *((_BYTE *)&v5->0 + 164) & 1 && !(_BYTE)_yElement )
    {
      LOBYTE(_button) = 0;
      UIElement::GetAttribute_Bool((UIElement *)&v5->vfptr, 0xBu, (bool *)&_button);
      if ( (_BYTE)_button )
      {
        UIElement::GetAttribute_Bool((UIElement *)&v5->vfptr, 0xEu, (bool *)&_xElement);
        LOBYTE(v7) = (_BYTE)_xElement == 0;
        UIElement::SetAttribute_Bool((UIElement *)&v5->vfptr, 0xEu, v7);
      }
      v6 = (!(_BYTE)_yElement || BYTE3(v9)) && !v5->hotClickingInProgress;
    }
    v8 = v5->hotClickingInProgress;
    v5->mousePressedOnButton = 0;
    if ( v8 )
    {
      v5->hotClickingInProgress = 0;
      UIListener::UnRegisterForGlobalMessage((UIListener *)&v5->vfptr, 3u);
    }
    UIElement_Button::UpdateState_(v5);
    if ( v6 )
      UIElement::BroadcastElementMessage((UIElement *)&v5->vfptr, 1u, 7u, 0);
  }
}

//----- (004721F0) --------------------------------------------------------  // acclient.c:174779
void __thiscall UIElement_Button::MouseOverTop(UIElement_Button *this, bool _overTop)
{
  UIElement_Button *v2; // esi@1

  v2 = this;
  UIElement::MouseOverTop((UIElement *)&this->vfptr, _overTop);
  UIElement_Button::UpdateState_(v2);
}

//----- (00472210) --------------------------------------------------------  // acclient.c:174789
int __thiscall UIElement_Button::ListenToElementMessage(UIElement_Button *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // edi@1
  UIElement_Text *v3; // esi@1
  int result; // eax@5

  v2 = i_rMsg;
  v3 = (UIElement_Text *)this;
  if ( (UIElement_Button *)i_rMsg->pElement == this
    && i_rMsg->idMessage == 1
    && ((UIElement::GetAttribute_Bool((UIElement *)&this->vfptr, 0xDu, (bool *)&i_rMsg), (_BYTE)i_rMsg)
     || UIElement_Button::HandleButtonClick((UIElement_Button *)v3, v2)) )
    result = 2;
  else
    result = UIElement_Text::ListenToElementMessage(v3, v2);
  return result;
}

//----- (00472260) --------------------------------------------------------  // acclient.c:174808
char __thiscall UIElement_Button::InqAvailableProperties(UIElement_Button *this, AvailablePropertySet *_set)
{
  AvailablePropertySet *v2; // edi@1
  char v3; // bl@1
  AvailablePropertySet *v4; // esi@3
  char result; // al@4

  v2 = _set;
  v3 = 1;
  if ( !UIElement_Text::InqAvailableProperties((UIElement_Text *)&this->vfptr, _set) )
    v3 = 0;
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&_set);
  v4 = _set;
  if ( _set )
  {
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)_set, 1u, v2) )
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

//----- (006EC080) --------------------------------------------------------  // acclient.c:767845
int _E73_73()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_12, "Misc.TooltipEnable");
  return atexit(_E74_55);
}

//----- (006EC0A0) --------------------------------------------------------  // acclient.c:767852
int _E76_41()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_12, "Misc.TooltipDelay");
  return atexit(_E77_69);
}

//----- (006EC0C0) --------------------------------------------------------  // acclient.c:767859
int _E1_68()
{
  return atexit(_E2_68);
}

//----- (0075E890) --------------------------------------------------------  // acclient.c:886800
void __cdecl _E74_55()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E8C0) --------------------------------------------------------  // acclient.c:886813
void __cdecl _E77_69()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

