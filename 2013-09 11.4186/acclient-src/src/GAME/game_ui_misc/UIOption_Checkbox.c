/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIOption_Checkbox
   Object     : GAME\game_ui_misc\UIOption_Checkbox.obj
   Functions  : 30
   Addresses  : 004868A0 - 006ED750 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004868A0) --------------------------------------------------------  // acclient.c:194206
void __thiscall UIOption_Checkbox::Refresh(UIOption_Checkbox *this)
{
  UIElement::SetAttribute_Bool((UIElement *)&this->vfptr, 0xEu, this->m_current);
}

//----- (004868C0) --------------------------------------------------------  // acclient.c:194212
bool __thiscall UIOption_Checkbox::Changed(UIOption_Checkbox *this)
{
  return this->m_saved != this->m_current;
}

//----- (004868E0) --------------------------------------------------------  // acclient.c:194218
char __thiscall UIOption_Checkbox::SaveCurrentValue(UIOption_Checkbox *this)
{
  UIOption_Checkbox *v1; // esi@1
  char v2; // al@1

  v1 = this;
  v2 = ((int (*)(void))this->vfptr[7].RecvNotice_DisplayWeenieError)();
  v1->m_current = v2;
  v1->m_saved = v2;
  return 1;
}

//----- (00486900) --------------------------------------------------------  // acclient.c:194231
char __thiscall UIOption_Checkbox::RestoreSavedValue(UIOption_Checkbox *this)
{
  UIOption_Checkbox *v1; // esi@1
  NoticeHandlerVtbl *v2; // edx@1

  v1 = this;
  v2 = this->vfptr;
  this->m_current = this->m_saved;
  ((void (__stdcall *)(_DWORD))v2[7].RecvNotice_CloseDialog)(0);
  ((void (__thiscall *)(UIOption_Checkbox *))v1->vfptr[7].RecvNotice_ServerSaysMoveItem)(v1);
  return 1;
}

//----- (00486930) --------------------------------------------------------  // acclient.c:194245
char __thiscall UIOption_Checkbox::RestoreDefaultValue(UIOption_Checkbox *this)
{
  UIOption_Checkbox *v1; // esi@1
  NoticeHandlerVtbl *v2; // edx@1

  v1 = this;
  v2 = this->vfptr;
  this->m_current = this->m_default;
  ((void (__stdcall *)(_DWORD))v2[7].RecvNotice_CloseDialog)(0);
  ((void (__thiscall *)(UIOption_Checkbox *))v1->vfptr[7].RecvNotice_ServerSaysMoveItem)(v1);
  return 1;
}

//----- (00486960) --------------------------------------------------------  // acclient.c:194259
void __thiscall UIOption_Checkbox::SetDefaultValue(UIOption_Checkbox *this, bool _default)
{
  this->m_default = _default;
}

//----- (00486970) --------------------------------------------------------  // acclient.c:194265
void __thiscall UIOption_Checkbox::SetCurrentValue(UIOption_Checkbox *this, int _current)
{
  UIOption_Checkbox *v2; // esi@1

  v2 = this;
  this->m_current = _current;
  UIElement::SetAttribute_Bool((UIElement *)&this->vfptr, 0xEu, _current);
  ((void (__thiscall *)(UIOption_Checkbox *, signed int))v2->vfptr[7].RecvNotice_CloseDialog)(v2, 1);
}

//----- (004869A0) --------------------------------------------------------  // acclient.c:194276
int __thiscall UIOption_Checkbox::ListenToElementMessage(UIOption_Checkbox *this, UIElementMessageInfo *i_rMsg)
{
  UIElement_Button *v2; // esi@1

  v2 = (UIElement_Button *)this;
  if ( i_rMsg->idMessage == 1 )
  {
    if ( LODWORD(this[-1].nextHotClickTime) )
    {
      (*(void (__thiscall **)(bool *))(*(_DWORD *)&this[-1].mousePressedOnButton + 696))(&this[-1].mousePressedOnButton);
      return UIElement_Button::ListenToElementMessage(v2, i_rMsg);
    }
    UIElement::GetAttribute_Bool((UIElement *)this, 0xEu, (bool *)&this->m_downloadQueue.m_data + 2);
    (*((void (__thiscall **)(int, signed int))v2[-1].m_downloadQueue.m_data + 181))(&v2[-1].m_downloadQueue, 1);
  }
  return UIElement_Button::ListenToElementMessage(v2, i_rMsg);
}

//----- (00486A10) --------------------------------------------------------  // acclient.c:194301
void __thiscall UIOption_Checkbox::RecvNotice_RefreshOptionsPanel(UIOption_Checkbox *this)
{
  UIOption_Checkbox *v1; // esi@1
  char v2; // al@1
  NoticeHandlerVtbl *v3; // edx@1

  v1 = this;
  v2 = ((int (*)(void))this->vfptr[7].RecvNotice_DisplayWeenieError)();
  v3 = v1->vfptr;
  v1->m_current = v2;
  ((void (__thiscall *)(UIOption_Checkbox *))v3[7].RecvNotice_ServerSaysMoveItem)(v1);
}

//----- (00486A30) --------------------------------------------------------  // acclient.c:194315
void __thiscall UIOption_Checkbox::RecvNotice_PlayerOptionChanged(UIOption_Checkbox *this, PlayerOption i_po)
{
  if ( i_po == this->m_playerOption )
    (*(void (**)(void))&this->vfptr[6].gap4[4])();
}

//----- (00486A50) --------------------------------------------------------  // acclient.c:194322
void __thiscall UIOption_Checkbox::UIOption_Checkbox(UIOption_Checkbox *this, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIOption_Checkbox *v3; // esi@1
  volatile LONG *v4; // ST04_4@1

  v3 = this;
  UIOption::UIOption((UIOption *)&this->vfptr);
  UIElement_Button::UIElement_Button((UIElement_Button *)&v3->vfptr, (int)&v3->vfptr, _layout, _full_desc);
  v3->vfptr = (NoticeHandlerVtbl *)&UIOption_Checkbox::vftable;
  v3->vfptr = (IInputActionCallbackVtbl *)&UIOption_Checkbox::vftable;
  v3->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  v3->m_default = 0;
  v3->m_saved = 0;
  v3->m_current = 0;
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v3->m_prefName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
  v3->m_propName = 0;
  v3->m_playerOption = -1;
}
// 7A25E0: using guessed type void *UIOption_Checkbox::vftable;
// 7A2720: using guessed type bool (__thiscall *UIOption_Checkbox::vftable)(DBCache *this);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00486AD0) --------------------------------------------------------  // acclient.c:194347
signed int UIOption_Checkbox::GetUIElementType()
{
  return 268435509;
}

//----- (00486AE0) --------------------------------------------------------  // acclient.c:194353
UIOption_Checkbox *__thiscall UIOption_Checkbox::vector_deleting_destructor(UIOption_Checkbox *this, unsigned int a2)
{
  return UIOption_Checkbox::scalar_deleting_destructor((UIOption_Checkbox *)((char *)this - 32), a2);
}

//----- (00486AF0) --------------------------------------------------------  // acclient.c:194359
signed int __thiscall UIOption_Checkbox::DynamicCast(UIOption_Checkbox *this, unsigned int a2)
{
  return UIOption_Checkbox::DynamicCast((UIOption_Checkbox *)((char *)this - 32), a2);
}

//----- (00486B00) --------------------------------------------------------  // acclient.c:194365
void __thiscall UIOption_Checkbox::~UIOption_Checkbox(UIOption_Checkbox *this)
{
  UIOption *v1; // esi@1
  char *v2; // edi@1
  UIElement_Button *v3; // ebx@1

  v1 = (UIOption *)this;
  v2 = &this->m_prefName.m_charbuffer[-2].m_data[12];
  v3 = (UIElement_Button *)&this->vfptr;
  this->vfptr = (NoticeHandlerVtbl *)&UIOption_Checkbox::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&UIOption_Checkbox::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  UIElement_Button::~UIElement_Button(v3);
  UIOption::~UIOption(v1);
}
// 7A25E0: using guessed type void *UIOption_Checkbox::vftable;
// 7A2720: using guessed type bool (__thiscall *UIOption_Checkbox::vftable)(DBCache *this);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00486B60) --------------------------------------------------------  // acclient.c:194387
UIElement *__cdecl UIOption_Checkbox::Create(LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIOption_Checkbox *v2; // eax@1
  int v3; // eax@2
  UIElement *result; // eax@3

  v2 = (UIOption_Checkbox *)operator new(0x750u);
  if ( v2 && (UIOption_Checkbox::UIOption_Checkbox(v2, _layout, _full_desc), v3) )
    result = (UIElement *)(v3 + 32);
  else
    result = 0;
  return result;
}

//----- (00486B90) --------------------------------------------------------  // acclient.c:194402
void __thiscall UIOption_Checkbox::SetUIPreference(UIOption_Checkbox *this, PStringBase<char> *_prefName)
{
  UIOption *v2; // esi@1
  PStringBase<char> *v3; // edi@3
  unsigned int labelID; // [sp+4h] [bp-8h]@3
  unsigned int tooltipID; // [sp+8h] [bp-4h]@3

  v2 = (UIOption *)this;
  if ( !this->m_propName && this->m_playerOption == -1 )
  {
    v3 = _prefName;
    PStringBase<unsigned short>::operator=(
      (PStringBase<unsigned short> *)&this->m_prefName,
      (const unsigned __int16 *)_prefName);
    _prefName = 0;
    labelID = 0;
    tooltipID = 0;
    if ( UIPreferences::InqPreference(v3, (unsigned int *)&_prefName, &labelID, &tooltipID) )
    {
      UIOption::SetLabel(v2, labelID, (unsigned int)_prefName);
      UIOption::SetTooltip(v2, tooltipID, (unsigned int)_prefName);
    }
  }
}

//----- (00486C20) --------------------------------------------------------  // acclient.c:194428
UIOption_Checkbox *__thiscall UIOption_Checkbox::scalar_deleting_destructor(UIOption_Checkbox *this, unsigned int a2)
{
  UIOption_Checkbox *v2; // esi@1

  v2 = this;
  UIOption_Checkbox::~UIOption_Checkbox(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00486C40) --------------------------------------------------------  // acclient.c:194440
void __cdecl UIOption_Checkbox::Register()
{
  UIElement::RegisterElementClass(0x10000035u, UIOption_Checkbox::Create);
}

//----- (00486C60) --------------------------------------------------------  // acclient.c:194446
char __thiscall UIOption_Checkbox::Apply(UIOption_Checkbox *this, int _userRequested)
{
  UIOption_Checkbox *v2; // ebp@1
  InterfaceSystem *v3; // eax@2
  Interface *v4; // edi@2
  int v5; // ebx@4
  CPlayerModule *v6; // edi@6
  const unsigned int v7; // ST08_4@8
  BasePropertyDesc *v8; // ecx@11
  unsigned int v9; // ebx@11
  BasePropertyValue *v10; // ecx@15
  unsigned int v11; // edx@15
  InterfaceSystem *v12; // eax@19
  Interface *v13; // edi@19
  int v14; // ebx@21
  CPlayerModule *v15; // edi@23
  int v17; // [sp-8h] [bp-30h]@2
  int v18; // [sp-8h] [bp-30h]@19
  Interface *_rpInterface; // [sp+10h] [bp-18h]@2
  TResult result; // [sp+14h] [bp-14h]@2
  BaseProperty prop; // [sp+18h] [bp-10h]@4
  InterfacePtr<CPlayerModule> spPM; // [sp+20h] [bp-8h]@2

  v2 = this;
  if ( this->m_propName )
  {
    _rpInterface = 0;
    v3 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v3, &result, &CPlayerModule_ClassType_2, &_rpInterface);
    v4 = _rpInterface;
    v17 = (int)_rpInterface;
    spPM.m_pInterface = 0;
    spPM.m_trStatus.m_val = 0;
    if ( _rpInterface )
      _rpInterface->vfptr->AddRef(_rpInterface);
    v5 = *(_DWORD *)InterfacePtr<CPlayerModule>::_QueryInterface(&spPM, (int)&prop, v17, 0);
    if ( v4 )
      v4->vfptr->Release(v4);
    v6 = spPM.m_pInterface;
    if ( (_DWORD)spPM.m_pInterface )
    {
      if ( v5 >= 0 )
      {
        v7 = v2->m_propName;
        prop.m_pcPropertyDesc = 0;
        prop.m_pcPropertyValue = 0;
        BaseProperty::SetPropertyName(&prop, v7);
        LOBYTE(_rpInterface) = v2->m_current;
        if ( prop.m_pcPropertyValue )
        {
          BaseProperty::CheckCopyOnWrite(&prop);
          ((void (__stdcall *)(Interface *))prop.m_pcPropertyValue->vfptr[29].__vecDelDtor)(_rpInterface);
        }
        PlayerModule::SetOption((PlayerModule *)&v6->vfptr, &prop);
        if ( (_DWORD)prop.m_pcPropertyDesc )
        {
          v8 = prop.m_pcPropertyDesc;
          v9 = prop.m_pcPropertyDesc->m_cRef - 1;
          prop.m_pcPropertyDesc->m_cRef = v9;
          if ( !v9 )
            ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
          prop.m_pcPropertyDesc = 0;
        }
        if ( prop.m_pcPropertyValue )
        {
          v10 = prop.m_pcPropertyValue;
          v11 = prop.m_pcPropertyValue->m_cRef - 1;
          prop.m_pcPropertyValue->m_cRef = v11;
          if ( !v11 )
            ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
        }
      }
      v6->vfptr->Release((Interface *)v6);
    }
LABEL_30:
    v2->vfptr[7].RecvNotice_CreateObject((NoticeHandler *)v2, _userRequested);
    return 1;
  }
  if ( this->m_playerOption != -1 )
  {
    _rpInterface = 0;
    v12 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v12, (TResult *)&prop, &CPlayerModule_ClassType_2, &_rpInterface);
    v13 = _rpInterface;
    v18 = (int)_rpInterface;
    spPM.m_pInterface = 0;
    spPM.m_trStatus.m_val = 0;
    if ( _rpInterface )
      _rpInterface->vfptr->AddRef(_rpInterface);
    v14 = *(_DWORD *)InterfacePtr<CPlayerModule>::_QueryInterface(&spPM, (int)&result, v18, 0);
    if ( v13 )
      v13->vfptr->Release(v13);
    v15 = spPM.m_pInterface;
    if ( (_DWORD)spPM.m_pInterface )
    {
      if ( v14 >= 0 )
        PlayerModule::SetOption((PlayerModule *)&spPM.m_pInterface->vfptr, v2->m_playerOption, v2->m_current);
      v15->vfptr->Release((Interface *)v15);
    }
    goto LABEL_30;
  }
  if ( *(_DWORD *)&this->m_prefName.m_charbuffer[-1].m_data[12] != 1 )
  {
    if ( UIPreferences::ModifyPreference(&this->m_prefName, this->m_current) )
      CM_UI::SendNotice_UserPreferenceChanged(&v2->m_prefName);
    goto LABEL_30;
  }
  return 0;
}

//----- (00486E80) --------------------------------------------------------  // acclient.c:194557
void __thiscall UIOption_Checkbox::SetPlayerOption(UIOption_Checkbox *this, PlayerOption _propName)
{
  UIOption_Checkbox *v2; // edi@1
  InterfaceSystem *v3; // eax@3
  PlayerOption v4; // esi@3
  int v5; // ebp@5
  CPlayerModule *v6; // esi@7
  GlobalEventHandler *v7; // eax@10
  int v8; // [sp-8h] [bp-28h]@3
  TResult result; // [sp+10h] [bp-10h]@3
  char v10; // [sp+14h] [bp-Ch]@5
  InterfacePtr<CPlayerModule> spPM; // [sp+18h] [bp-8h]@3

  v2 = this;
  if ( !this->m_propName && *(_DWORD *)&this->m_prefName.m_charbuffer[-1].m_data[12] == 1 )
  {
    this->m_playerOption = _propName;
    _propName = 0;
    v3 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v3, &result, &CPlayerModule_ClassType_2, (Interface **)&_propName);
    v8 = _propName;
    v4 = _propName;
    spPM.m_pInterface = 0;
    spPM.m_trStatus.m_val = 0;
    if ( _propName )
      (*(void (__thiscall **)(PlayerOption))(*(_DWORD *)_propName + 16))(_propName);
    v5 = *(_DWORD *)InterfacePtr<CPlayerModule>::_QueryInterface(&spPM, (int)&v10, v8, 0);
    if ( v4 )
      (*(void (__thiscall **)(PlayerOption))(*(_DWORD *)v4 + 20))(v4);
    v6 = spPM.m_pInterface;
    if ( (_DWORD)spPM.m_pInterface && v5 >= 0 )
      v2->m_default = PlayerModule::GetDefaultOptionValue(v2->m_playerOption);
    v7 = GlobalEventHandler::GetGlobalEventHandler();
    if ( v7 )
      v7->vfptr->RegisterNoticeHandler(
        (NoticeRegistrar *)v7,
        (unsigned int)((char *)&loc_4DD21E + 1),
        (NoticeHandler *)v2);
    if ( v6 )
      v6->vfptr->Release((Interface *)v6);
  }
}

//----- (00486F60) --------------------------------------------------------  // acclient.c:194601
bool __thiscall UIOption_Checkbox::GetValue(UIOption_Checkbox *this)
{
  UIOption_Checkbox *v1; // ebp@1
  PlayerOption v2; // ecx@1
  bool v3; // al@1
  InterfaceSystem *v4; // eax@2
  Interface *v5; // esi@2
  int v6; // edi@4
  CPlayerModule *v7; // esi@6
  int v8; // [sp-8h] [bp-30h]@2
  bool val; // [sp+13h] [bp-15h]@1
  Interface *_rpInterface; // [sp+14h] [bp-14h]@2
  TResult result; // [sp+18h] [bp-10h]@2
  char v12; // [sp+1Ch] [bp-Ch]@4
  InterfacePtr<CPlayerModule> spPM; // [sp+20h] [bp-8h]@2

  v1 = this;
  v2 = this->m_playerOption;
  v3 = 0;
  val = 0;
  if ( v2 == -1 )
  {
    if ( *(_DWORD *)&v1->m_prefName.m_charbuffer[-1].m_data[12] == 1 )
      return v3;
    UIPreferences::InqPreferenceValue(&v1->m_prefName, &val);
    return val;
  }
  _rpInterface = 0;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v4, &result, &CPlayerModule_ClassType_2, &_rpInterface);
  v5 = _rpInterface;
  v8 = (int)_rpInterface;
  spPM.m_pInterface = 0;
  spPM.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v6 = *(_DWORD *)InterfacePtr<CPlayerModule>::_QueryInterface(&spPM, (int)&v12, v8, 0);
  if ( v5 )
    v5->vfptr->Release(v5);
  v7 = spPM.m_pInterface;
  if ( !(_DWORD)spPM.m_pInterface )
    return val;
  if ( v6 >= 0 )
    val = PlayerModule::GetOption((PlayerModule *)&spPM.m_pInterface->vfptr, v1->m_playerOption);
  v7->vfptr->Release((Interface *)v7);
  return val;
}

//----- (00487040) --------------------------------------------------------  // acclient.c:194650
void __thiscall UIOption_Checkbox::SetLabel(UIOption_Checkbox *this, StringInfo *i_siLabel)
{
  UIElement_Text::SetStringInfo((UIElement_Text *)&this->vfptr, i_siLabel);
}

//----- (006ED6C0) --------------------------------------------------------  // acclient.c:769297
void _E91_49()
{
  outside_val_41 = 1000.0 + 1.0;
}

//----- (006ED6E0) --------------------------------------------------------  // acclient.c:769303
void _E93_25()
{
  block_length_41 = 24.0 * 8.0;
}

//----- (006ED700) --------------------------------------------------------  // acclient.c:769309
void _E95_25()
{
  half_square_length_41 = 24.0 * 0.5;
}

//----- (006ED720) --------------------------------------------------------  // acclient.c:769315
int _E97_50()
{
  return atexit(_E98_62);
}

//----- (006ED730) --------------------------------------------------------  // acclient.c:769321
int _E100_43()
{
  return atexit(_E101_80);
}

//----- (006ED740) --------------------------------------------------------  // acclient.c:769327
int _E103_35()
{
  return atexit(_E104_50);
}

//----- (006ED750) --------------------------------------------------------  // acclient.c:769333
int sub_6ED750()
{
  return atexit(nullsub_1001);
}

