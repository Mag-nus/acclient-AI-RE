/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIOption_Menu
   Object     : GAME\game_ui_misc\UIOption_Menu.obj
   Functions  : 53
   Addresses  : 00483C60 - 0075F3A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00483C60) --------------------------------------------------------  // acclient.c:191462
void __thiscall UIOption_Menu::Refresh(UIOption_Menu *this)
{
  UIOption_Menu *v1; // ebp@1
  UIElement_Menu *v2; // edi@1
  int v3; // ebx@1
  UIElement *v4; // esi@2
  UIElement *v5; // eax@5
  int value; // [sp+10h] [bp-4h]@3

  v1 = this;
  v2 = (UIElement_Menu *)&this->vfptr;
  v3 = 0;
  if ( (signed int)UIElement_Menu::GetNumItems((UIElement_Menu *)&this->vfptr) <= 0 )
  {
LABEL_5:
    v5 = UIElement_Menu::GetItem(v2, 0);
    if ( v5 )
      UIElement_Menu::SetSelectedItem(v2, v5, 0);
  }
  else
  {
    while ( 1 )
    {
      v4 = UIElement_Menu::GetItem(v2, v3);
      if ( v4 )
      {
        value = 0;
        UIElement::GetAttribute_Int(v4, 0x10000025u, &value);
        if ( v1->m_current == value )
          break;
      }
      ++v3;
      if ( v3 >= (signed int)UIElement_Menu::GetNumItems(v2) )
        goto LABEL_5;
    }
    UIElement_Menu::SetSelectedItem(v2, v4, 0);
  }
}

//----- (00483CF0) --------------------------------------------------------  // acclient.c:191502
bool __thiscall UIOption_Menu::Changed(UIOption_Menu *this)
{
  return this->m_saved != this->m_current;
}

//----- (00483D10) --------------------------------------------------------  // acclient.c:191508
char __thiscall UIOption_Menu::SaveCurrentValue(UIOption_Menu *this)
{
  UIOption_Menu *v1; // esi@1
  int v2; // eax@1

  v1 = this;
  v2 = ((int (*)(void))this->vfptr[7].RecvNotice_OpenDialog)();
  v1->m_current = v2;
  v1->m_saved = v2;
  return 1;
}

//----- (00483D30) --------------------------------------------------------  // acclient.c:191521
char __thiscall UIOption_Menu::RestoreSavedValue(UIOption_Menu *this)
{
  UIOption_Menu *v1; // esi@1
  NoticeHandlerVtbl *v2; // edx@1

  v1 = this;
  v2 = this->vfptr;
  this->m_current = this->m_saved;
  ((void (__stdcall *)(_DWORD))v2[7].RecvNotice_CloseDialog)(0);
  ((void (__thiscall *)(UIOption_Menu *))v1->vfptr[7].RecvNotice_ServerSaysMoveItem)(v1);
  return 1;
}

//----- (00483D60) --------------------------------------------------------  // acclient.c:191535
char __thiscall UIOption_Menu::RestoreDefaultValue(UIOption_Menu *this)
{
  UIOption_Menu *v1; // esi@1
  NoticeHandlerVtbl *v2; // edx@1

  v1 = this;
  v2 = this->vfptr;
  this->m_current = this->m_default;
  ((void (__stdcall *)(_DWORD))v2[7].RecvNotice_CloseDialog)(0);
  ((void (__thiscall *)(UIOption_Menu *))v1->vfptr[7].RecvNotice_ServerSaysMoveItem)(v1);
  return 1;
}

//----- (00483D90) --------------------------------------------------------  // acclient.c:191549
void __thiscall UIOption_Menu::SetDefaultValue(UIOption_Menu *this, const unsigned int _default)
{
  this->m_default = _default;
}

//----- (00483DA0) --------------------------------------------------------  // acclient.c:191555
int __thiscall UIOption_Menu::ListenToElementMessage(UIOption_Menu *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // edi@1
  UIOption_Menu *v3; // esi@1
  UIElement *v5; // eax@4
  int v6; // eax@5

  v2 = i_rMsg;
  v3 = this;
  if ( i_rMsg->idMessage == 7 )
  {
    if ( this[-1].m_uiListBoxYBorder )
    {
      (*(void (__thiscall **)(bool *))(*(_DWORD *)&this[-1].m_open + 696))(&this[-1].m_open);
      return UIElement_Menu::ListenToElementMessage((UIElement_Menu *)v3, v2);
    }
    i_rMsg = 0;
    v5 = UIElement_Menu::GetSelectedItem((UIElement_Menu *)this);
    if ( v5 )
    {
      UIElement::GetAttribute_Int(v5, 0x10000025u, (int *)&i_rMsg);
      v6 = *(_DWORD *)&v3[-1].m_open;
      v3->m_popup = (UIElement *)i_rMsg;
      (*(void (__thiscall **)(int, signed int))(v6 + 724))(&v3[-1].m_open, 1);
    }
  }
  return UIElement_Menu::ListenToElementMessage((UIElement_Menu *)v3, v2);
}

//----- (00483E20) --------------------------------------------------------  // acclient.c:191585
void __thiscall UIOption_Menu::RecvNotice_RefreshOptionsPanel(UIOption_Menu *this)
{
  UIOption_Menu *v1; // esi@1
  int v2; // eax@1
  NoticeHandlerVtbl *v3; // edx@1

  v1 = this;
  v2 = ((int (*)(void))this->vfptr[7].RecvNotice_OpenDialog)();
  v3 = v1->vfptr;
  v1->m_current = v2;
  ((void (__thiscall *)(UIOption_Menu *))v3[7].RecvNotice_ServerSaysMoveItem)(v1);
}

//----- (00483E40) --------------------------------------------------------  // acclient.c:191599
unsigned int __thiscall UIOption_Menu::GetValue(UIOption_Menu *this)
{
  PSRefBufferCharData<char> *v1; // edx@1
  PStringBase<char> *v2; // ecx@1
  unsigned int result; // eax@1
  unsigned int val; // [sp+0h] [bp-4h]@1

  val = (unsigned int)this;
  v1 = this->m_prefName.m_charbuffer;
  v2 = &this->m_prefName;
  result = 0;
  val = 0;
  if ( *(_DWORD *)&v1[-1].m_data[12] != 1 )
  {
    UIPreferences::InqPreferenceValue(v2, &val);
    result = val;
  }
  return result;
}

//----- (00483E70) --------------------------------------------------------  // acclient.c:191620
void __thiscall UIOption_Menu::HandleDialogAndNotices(UIOption_Menu *this, bool _userRequested)
{
  UIOption_Menu *v2; // esi@1
  bool v3; // bl@1

  v2 = this;
  v3 = this->m_confirmChange;
  if ( _userRequested && v3 && this->m_bDelayConfirmation )
  {
    UIListener::RegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
    v2->m_confirmChange = 0;
  }
  UIOption::HandleDialogAndNotices((UIOption *)&v2->vfptr, _userRequested);
  v2->m_confirmChange = v3;
}

//----- (00483EB0) --------------------------------------------------------  // acclient.c:191637
void __thiscall UIOption_Menu::ListenToGlobalMessage(UIOption_Menu *this, unsigned int i_messageID, int i_data_int)
{
  UIListener *v3; // esi@1
  bool v4; // zf@2
  bool v5; // sf@2
  unsigned __int8 v6; // of@2

  v3 = (UIListener *)this;
  if ( i_messageID == 3 )
  {
    v6 = __OFSUB__(cUseTimes + 1, 1);
    v4 = cUseTimes == 0;
    v5 = cUseTimes++ < 0;
    if ( !((unsigned __int8)(v5 ^ v6) | v4) )
    {
      UIOption::HandleDialog((UIOption *)&this[-1].m_open);
      UIListener::UnRegisterForGlobalMessage(v3, i_messageID);
      cUseTimes = 0;
    }
  }
  UIElement_Button::ListenToGlobalMessage((UIElement_Button *)v3, i_messageID, i_data_int);
}

//----- (00483F00) --------------------------------------------------------  // acclient.c:191661
void __thiscall UIOption_Menu::~UIOption_Menu(UIOption_Menu *this)
{
  UIOption *v1; // esi@1
  char *v2; // edi@1
  UIElement_Menu *v3; // ebx@1

  v1 = (UIOption *)this;
  v2 = &this->m_prefName.m_charbuffer[-2].m_data[12];
  v3 = (UIElement_Menu *)&this->vfptr;
  this->vfptr = (NoticeHandlerVtbl *)&UIOption_Menu::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&UIOption_Menu::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  UIElement_Menu::~UIElement_Menu(v3);
  UIOption::~UIOption(v1);
}
// 7A0F20: using guessed type void *UIOption_Menu::vftable;
// 7A1060: using guessed type bool (__thiscall *UIOption_Menu::vftable)(DBCache *this);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00483F60) --------------------------------------------------------  // acclient.c:191683
signed int __thiscall UIOption_Menu::DynamicCast(UIOption_Menu *this, unsigned int i_eType)
{
  signed int result; // eax@3

  if ( i_eType == 268435512 )
  {
    if ( this )
      result = (signed int)&this->vfptr;
    else
      result = 0;
  }
  else
  {
    result = (signed int)&this->vfptr;
    if ( i_eType != 6 && i_eType != 1 && i_eType != 12 )
      result = i_eType != 10 ? 0 : result;
  }
  return result;
}

//----- (00483FA0) --------------------------------------------------------  // acclient.c:191704
signed int UIOption_Menu::GetUIElementType()
{
  return 268435512;
}

//----- (00483FB0) --------------------------------------------------------  // acclient.c:191710
UIOption_Menu *__thiscall UIOption_Menu::vector_deleting_destructor(UIOption_Menu *this, unsigned int a2)
{
  return UIOption_Menu::scalar_deleting_destructor((UIOption_Menu *)((char *)this - 32), a2);
}

//----- (00483FC0) --------------------------------------------------------  // acclient.c:191716
signed int __thiscall UIOption_Menu::DynamicCast(UIOption_Menu *this, unsigned int a2)
{
  return UIOption_Menu::DynamicCast((UIOption_Menu *)((char *)this - 32), a2);
}

//----- (00483FD0) --------------------------------------------------------  // acclient.c:191722
void __thiscall UIOption_Menu::SetLabel(UIOption_Menu *this, StringInfo *i_siLabel)
{
  UIElement *v2; // eax@1
  UIElement *v3; // eax@2
  UIElement_Text *v4; // eax@3

  v2 = (UIElement *)((int (__thiscall *)(_DWORD))this->vfptr[13].OnAction)(&this->vfptr);
  if ( v2 )
  {
    v3 = UIElement::GetChildRecursive(v2, 0x10000223u);
    if ( v3 )
    {
      v4 = (UIElement_Text *)v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
      if ( v4 )
        UIElement_Text::SetStringInfo(v4, i_siLabel);
    }
  }
}

//----- (00484010) --------------------------------------------------------  // acclient.c:191742
void __thiscall UIOption_Menu::SetEntries(UIOption_Menu *this, SmartArray<unsigned long,1> *_tokenArray, SmartArray<unsigned long,1> *_valueArray, unsigned int _tableID)
{
  int v4; // esi@1
  UIElement_Menu *v5; // ebx@2
  UIElement *v6; // eax@3
  StringInfo _text; // [sp+8h] [bp-90h]@3

  v4 = 0;
  if ( _tokenArray->m_num )
  {
    v5 = (UIElement_Menu *)&this->vfptr;
    do
    {
      StringInfo::StringInfo(&_text);
      StringInfo::SetStringIDandTableEnum(&_text, _tokenArray->m_data[v4], _tableID);
      v6 = (UIElement *)UIElement_Menu::InsertTextItem(v5, &_text, v4);
      if ( v6 )
        UIElement::SetAttribute_Int(v6, 0x10000025u, _valueArray->m_data[v4]);
      StringInfo::~StringInfo(&_text);
      ++v4;
    }
    while ( v4 < _tokenArray->m_num );
  }
}

//----- (004840A0) --------------------------------------------------------  // acclient.c:191768
UIOption_Menu *__thiscall UIOption_Menu::scalar_deleting_destructor(UIOption_Menu *this, unsigned int a2)
{
  UIOption_Menu *v2; // esi@1

  v2 = this;
  UIOption_Menu::~UIOption_Menu(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004840C0) --------------------------------------------------------  // acclient.c:191780
void __thiscall UIOption_Menu::UIOption_Menu(UIOption_Menu *this, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIOption_Menu *v3; // esi@1

  v3 = this;
  UIOption::UIOption((UIOption *)&this->vfptr);
  UIElement_Menu::UIElement_Menu((UIElement_Menu *)&v3->vfptr, (int)&v3->vfptr, _layout, _full_desc);
  v3->vfptr = (NoticeHandlerVtbl *)&UIOption_Menu::vftable;
  v3->vfptr = (IInputActionCallbackVtbl *)&UIOption_Menu::vftable;
  v3->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  v3->m_default = 0;
  v3->m_saved = 0;
  v3->m_current = 0;
  PStringBase<char>::PStringBase<char>(&v3->m_prefName, &name);
}
// 7A0F20: using guessed type void *UIOption_Menu::vftable;
// 7A1060: using guessed type bool (__thiscall *UIOption_Menu::vftable)(DBCache *this);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00484120) --------------------------------------------------------  // acclient.c:191800
UIElement *__cdecl UIOption_Menu::Create(LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIOption_Menu *v2; // eax@1
  int v3; // eax@2
  UIElement *result; // eax@3

  v2 = (UIOption_Menu *)operator new(0x768u);
  if ( v2 && (UIOption_Menu::UIOption_Menu(v2, _layout, _full_desc), v3) )
    result = (UIElement *)(v3 + 32);
  else
    result = 0;
  return result;
}

//----- (00484150) --------------------------------------------------------  // acclient.c:191815
char __thiscall UIOption_Menu::Apply(UIOption_Menu *this, int _userRequested)
{
  UIOption_Menu *v2; // esi@1
  bool v3; // bl@1
  char *v4; // ebp@1
  unsigned int v5; // ebx@5
  char result; // al@7
  PStringBase<char> v7; // [sp+10h] [bp-4h]@1

  v2 = this;
  PStringBase<char>::PStringBase<char>(&v7, &name);
  v3 = __stricmp(v2->m_prefName.m_charbuffer->m_data, v7.m_charbuffer->m_data) != 0;
  v4 = &v7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v7.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  if ( v3 )
  {
    v5 = v2->m_saved;
    if ( UIPreferences::ModifyPreference(&v2->m_prefName, v2->m_current) )
    {
      CM_UI::SendNotice_UserPreferenceChanged(&v2->m_prefName);
      CM_UI::SendNotice_UserPreferenceChanged_Menu(&v2->m_prefName, v5, v2->m_current);
    }
    v2->vfptr[7].RecvNotice_CreateObject((NoticeHandler *)v2, _userRequested);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00484200) --------------------------------------------------------  // acclient.c:191849
void __thiscall UIOption_Menu::SetUserPreference(UIOption_Menu *this, PStringBase<char> *_prefName)
{
  PStringBase<char> *v2; // edi@1
  UIOption_Menu *v3; // esi@1
  PSRefBufferCharData<char> *v4; // eax@1
  int v5; // ebx@2
  PStringBase<char> v6; // eax@5
  unsigned int labelID; // [sp+Ch] [bp-20h]@6
  unsigned int tooltipID; // [sp+10h] [bp-1Ch]@6
  SmartArray<unsigned long,1> valArray; // [sp+14h] [bp-18h]@7
  SmartArray<PStringBase<char>,1> strArray; // [sp+20h] [bp-Ch]@10

  v2 = _prefName;
  v3 = this;
  v4 = this->m_prefName.m_charbuffer;
  if ( v4 != _prefName->m_charbuffer )
  {
    v5 = (int)&v4[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6.m_charbuffer = v2->m_charbuffer;
    v3->m_prefName.m_charbuffer = v2->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v6.m_charbuffer[-1]);
  }
  _prefName = 0;
  labelID = 0;
  tooltipID = 0;
  if ( UIPreferences::InqPreference(v2, (unsigned int *)&_prefName, &labelID, &tooltipID) )
  {
    UIOption::SetLabel((UIOption *)&v3->vfptr, labelID, (unsigned int)_prefName);
    UIOption::SetTooltip((UIOption *)&v3->vfptr, tooltipID, (unsigned int)_prefName);
    valArray.m_data = 0;
    valArray.m_sizeAndDeallocate = 0;
    valArray.m_num = 0;
    if ( UserPreferences::InqChoiceValues(v2, &valArray) )
    {
      strArray.m_data = 0;
      strArray.m_sizeAndDeallocate = 0;
      strArray.m_num = 0;
      if ( UserPreferences::InqChoiceStrings(v2, &strArray) )
        v3->vfptr[7].RecvNotice_DisplayWeenieError(
          (NoticeHandler *)v3,
          (unsigned int)&strArray,
          (AC1Legacy::PStringBase<char> *)&valArray);
      if ( (strArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)strArray.m_data )
        PStringBase<unsigned short>::vector_deleting_destructor(strArray.m_data, 3u);
      if ( (valArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        operator delete[](valArray.m_data);
    }
    else if ( (valArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    {
      operator delete[](valArray.m_data);
    }
  }
}

//----- (00484360) --------------------------------------------------------  // acclient.c:191906
void __cdecl UIOption_Menu::Register()
{
  UIElement::RegisterElementClass(0x10000038u, UIOption_Menu::Create);
}

//----- (00484380) --------------------------------------------------------  // acclient.c:191912
void __thiscall UIOption_Menu::SetUIPreference(UIOption_Menu *this, PStringBase<char> *_prefName)
{
  PStringBase<char> *v2; // esi@1
  UIOption_Menu *v3; // ebp@1
  PSRefBufferCharData<char> *v4; // eax@1
  int v5; // ebx@2
  PStringBase<char> v6; // eax@5
  unsigned int i; // esi@10
  unsigned int v8; // eax@12
  unsigned int labelID; // [sp+Ch] [bp-20h]@6
  unsigned int tooltipID; // [sp+10h] [bp-1Ch]@6
  SmartArray<unsigned long,1> valArray; // [sp+14h] [bp-18h]@8
  SmartArray<unsigned long,1> tokenArray; // [sp+20h] [bp-Ch]@7

  v2 = _prefName;
  v3 = this;
  v4 = this->m_prefName.m_charbuffer;
  if ( v4 != _prefName->m_charbuffer )
  {
    v5 = (int)&v4[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6.m_charbuffer = v2->m_charbuffer;
    v3->m_prefName.m_charbuffer = v2->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v6.m_charbuffer[-1]);
  }
  _prefName = 0;
  labelID = 0;
  tooltipID = 0;
  if ( UIPreferences::InqPreference(v2, (unsigned int *)&_prefName, &labelID, &tooltipID) )
  {
    UIOption::SetLabel((UIOption *)&v3->vfptr, labelID, (unsigned int)_prefName);
    UIOption::SetTooltip((UIOption *)&v3->vfptr, tooltipID, (unsigned int)_prefName);
    tokenArray.m_data = 0;
    tokenArray.m_sizeAndDeallocate = 0;
    tokenArray.m_num = 0;
    if ( UIPreferences::InqEnumChoices(v2, &tokenArray) )
    {
      valArray.m_data = 0;
      valArray.m_sizeAndDeallocate = 0;
      valArray.m_num = 0;
      if ( !UserPreferences::InqChoiceValues(v2, &valArray) || !valArray.m_num )
      {
        for ( i = 0; i < tokenArray.m_num; ++i )
        {
          if ( valArray.m_num >= (valArray.m_sizeAndDeallocate & 0x7FFFFFFF) )
          {
            v8 = SmartArray<UIChildFramework *,1>::get_new_size((valArray.m_sizeAndDeallocate & 0x7FFFFFFF) + 1);
            if ( !SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&valArray, v8) )
              continue;
          }
          valArray.m_data[valArray.m_num++] = i;
        }
      }
      ((void (__thiscall *)(UIOption_Menu *, SmartArray<unsigned long,1> *, SmartArray<unsigned long,1> *, PStringBase<char> *))v3->vfptr[7].RecvNotice_DisplayStringInfo)(
        v3,
        &tokenArray,
        &valArray,
        _prefName);
      if ( (valArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        operator delete[](valArray.m_data);
      if ( (tokenArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        operator delete[](tokenArray.m_data);
    }
    else if ( (tokenArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    {
      operator delete[](tokenArray.m_data);
    }
  }
}

//----- (00484540) --------------------------------------------------------  // acclient.c:191984
void __thiscall UIOption_Menu::SetLiteralEntries(UIOption_Menu *this, SmartArray<PStringBase<char>,1> *_stringArray, SmartArray<unsigned long,1> *_valueArray)
{
  int v3; // ebx@1
  PStringBase<unsigned short> *v4; // eax@3
  char *v5; // esi@3
  UIElement *v6; // eax@6
  UIElement_Menu *v7; // [sp+8h] [bp-98h]@2
  PStringBase<unsigned short> result; // [sp+Ch] [bp-94h]@3
  StringInfo _text; // [sp+10h] [bp-90h]@3

  v3 = 0;
  if ( _stringArray->m_num )
  {
    v7 = (UIElement_Menu *)&this->vfptr;
    do
    {
      StringInfo::StringInfo(&_text);
      v4 = PStringBase<char>::to_wpstring(&_stringArray->m_data[v3], &result, 0);
      StringInfo::SetLiteralValue(&_text, v4, 1);
      v5 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      v6 = (UIElement *)UIElement_Menu::InsertTextItem(v7, &_text, v3);
      if ( v6 )
        UIElement::SetAttribute_Int(v6, 0x10000025u, _valueArray->m_data[v3]);
      StringInfo::~StringInfo(&_text);
      ++v3;
    }
    while ( v3 < _stringArray->m_num );
  }
}

//----- (00486A00) --------------------------------------------------------  // acclient.c:194295
void __thiscall UIOption_Menu::RecvNotice_ReloadOptions(UIOption_Menu *this)
{
  (*(void (**)(void))&this->vfptr[6].gap4[4])();
}

//----- (00487050) --------------------------------------------------------  // acclient.c:194656
void __thiscall UIOption_Slider::SetTooltip(UIOption_Menu *this, StringInfo *i_siTooltip)
{
  UIElement::SetTooltip((UIElement *)&this->vfptr, i_siTooltip);
}

//----- (006ED280) --------------------------------------------------------  // acclient.c:769024
void _E91_44()
{
  outside_val_36 = 1000.0 + 1.0;
}

//----- (006ED2A0) --------------------------------------------------------  // acclient.c:769030
void _E93_20()
{
  block_length_36 = 24.0 * 8.0;
}

//----- (006ED2C0) --------------------------------------------------------  // acclient.c:769036
void _E95_20()
{
  half_square_length_36 = 24.0 * 0.5;
}

//----- (006ED2E0) --------------------------------------------------------  // acclient.c:769042
int _E97_45()
{
  return atexit(_E98_57);
}

//----- (006ED2F0) --------------------------------------------------------  // acclient.c:769048
int _E100_38()
{
  return atexit(_E101_75);
}

//----- (006ED300) --------------------------------------------------------  // acclient.c:769054
int _E103_30()
{
  return atexit(_E104_45);
}

//----- (006ED310) --------------------------------------------------------  // acclient.c:769060
int _E106_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_34, "None");
  return atexit(_E107_70);
}

//----- (006ED330) --------------------------------------------------------  // acclient.c:769067
int _E109_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_34, "Speed");
  return atexit(sub_75F250);
}

//----- (006ED350) --------------------------------------------------------  // acclient.c:769074
int _E112_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_34, "Noise");
  return atexit(_E113_48);
}

//----- (006ED370) --------------------------------------------------------  // acclient.c:769081
int _E115_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_34, "Sine");
  return atexit(_E116_40);
}

//----- (006ED390) --------------------------------------------------------  // acclient.c:769088
int _E118_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_34, "Square");
  return atexit(_E119_72);
}

//----- (006ED3B0) --------------------------------------------------------  // acclient.c:769095
int _E121_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_34, "Bounce");
  return atexit(_E122_59);
}

//----- (006ED3D0) --------------------------------------------------------  // acclient.c:769102
int _E124_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_34, "Perlin");
  return atexit(_E125_31);
}

//----- (006ED3F0) --------------------------------------------------------  // acclient.c:769109
int _E127_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_34, "Fractal");
  return atexit(_E128_32);
}

//----- (006ED410) --------------------------------------------------------  // acclient.c:769116
int _E130_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_34, "FrameLoop");
  return atexit(_E131_28);
}

//----- (006ED430) --------------------------------------------------------  // acclient.c:769123
int _E1_96()
{
  return atexit(_E2_96);
}

//----- (0075F220) --------------------------------------------------------  // acclient.c:887146
void __cdecl _E107_70()
{
  char *v0; // esi@1

  v0 = &waveform_None_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075F250) --------------------------------------------------------  // acclient.c:887159
void __cdecl sub_75F250()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075F280) --------------------------------------------------------  // acclient.c:887172
void __cdecl _E113_48()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075F2B0) --------------------------------------------------------  // acclient.c:887185
void __cdecl _E116_40()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075F2E0) --------------------------------------------------------  // acclient.c:887198
void __cdecl _E119_72()
{
  char *v0; // esi@1

  v0 = &waveform_Square_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075F310) --------------------------------------------------------  // acclient.c:887211
void __cdecl _E122_59()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075F340) --------------------------------------------------------  // acclient.c:887224
void __cdecl _E125_31()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075F370) --------------------------------------------------------  // acclient.c:887237
void __cdecl _E128_32()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075F3A0) --------------------------------------------------------  // acclient.c:887250
void __cdecl _E131_28()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

