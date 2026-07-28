/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIOption_Slider
   Object     : GAME\game_ui_misc\UIOption_Slider.obj
   Functions  : 34
   Addresses  : 00484A50 - 006ED570 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00484A50) --------------------------------------------------------  // acclient.c:192323
void __thiscall UIOption_Slider::Refresh(UIOption_Slider *this)
{
  double v1; // st7@5
  char *v2; // ecx@5
  float _val; // ST04_4@5

  if ( this->m_current < (double)this->m_lowerValue )
    this->m_current = this->m_lowerValue;
  if ( this->m_current > (double)this->m_upperValue )
    this->m_current = this->m_upperValue;
  v1 = this->m_current - this->m_lowerValue;
  v2 = (char *)&this->vfptr;
  _val = v1 / (*((float *)v2 + 486) - *((float *)v2 + 485));
  UIElement::SetAttribute_Float((UIElement *)v2, 0x86u, _val);
}

//----- (00484AC0) --------------------------------------------------------  // acclient.c:192340
BOOL __thiscall UIOption_Slider::Changed(UIOption_Slider *this)
{
  return this->m_saved != this->m_current;
}

//----- (00484AE0) --------------------------------------------------------  // acclient.c:192346
char __thiscall UIOption_Slider::RestoreSavedValue(UIOption_Slider *this)
{
  UIOption_Slider *v1; // esi@1
  NoticeHandlerVtbl *v2; // edx@1

  v1 = this;
  v2 = this->vfptr;
  this->m_current = this->m_saved;
  ((void (__stdcall *)(_DWORD))v2[7].RecvNotice_CloseDialog)(0);
  ((void (__thiscall *)(UIOption_Slider *))v1->vfptr[7].RecvNotice_ServerSaysMoveItem)(v1);
  return 1;
}

//----- (00484B10) --------------------------------------------------------  // acclient.c:192360
char __thiscall UIOption_Slider::RestoreDefaultValue(UIOption_Slider *this)
{
  UIOption_Slider *v1; // esi@1
  NoticeHandlerVtbl *v2; // edx@1

  v1 = this;
  v2 = this->vfptr;
  this->m_current = this->m_default;
  ((void (__stdcall *)(_DWORD))v2[7].RecvNotice_CloseDialog)(0);
  ((void (__thiscall *)(UIOption_Slider *))v1->vfptr[7].RecvNotice_ServerSaysMoveItem)(v1);
  return 1;
}

//----- (00484B40) --------------------------------------------------------  // acclient.c:192374
void __thiscall UIOption_Slider::SetDefaultValue(UIOption_Slider *this, float _default)
{
  this->m_default = _default;
}

//----- (00484B50) --------------------------------------------------------  // acclient.c:192380
int __thiscall UIOption_Slider::ListenToElementMessage(UIOption_Slider *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // edi@1
  UIOption_Slider *v3; // esi@1
  float v4; // edx@3

  v2 = i_rMsg;
  v3 = this;
  if ( i_rMsg->idMessage == 10
    && i_rMsg->pElement == (UIElement *)(this != (UIOption_Slider *)32 ? (unsigned int)this : 0) )
  {
    *(float *)&i_rMsg = 0.0;
    UIElement::GetAttribute_Float((UIElement *)this, 0x86u, (float *)&i_rMsg);
    v4 = v3[-1].m_current;
    *(float *)&v3->m_rectScrollingArea.right = (*(float *)&v3->m_bitField - *(float *)&v3->m_eDecrementButtonID)
                                             * *(float *)&i_rMsg
                                             + *(float *)&v3->m_eDecrementButtonID;
    (*(void (__thiscall **)(int, signed int))(LODWORD(v4) + 724))(&v3[-1].m_current, 1);
  }
  return UIElement_Scrollbar::ListenToElementMessage((UIElement_Scrollbar *)v3, v2);
}

//----- (00484BC0) --------------------------------------------------------  // acclient.c:192403
double __thiscall UIOption_Slider::GetCurrentValue(UIOption_Slider *this)
{
  return this->m_current;
}

//----- (00484BD0) --------------------------------------------------------  // acclient.c:192409
void __thiscall UIOption_Slider::SetCurrentValue(UIOption_Slider *this, float i_fNewValue)
{
  UIOption_Slider *v2; // esi@1
  NoticeHandlerVtbl *v3; // edx@1

  v2 = this;
  v3 = this->vfptr;
  this->m_current = i_fNewValue;
  ((void (*)(void))v3[7].RecvNotice_ServerSaysMoveItem)();
  ((void (__thiscall *)(UIOption_Slider *, _DWORD))v2->vfptr[7].RecvNotice_CloseDialog)(v2, 0);
}

//----- (00484C00) --------------------------------------------------------  // acclient.c:192422
void __thiscall UIOption_Slider::~UIOption_Slider(UIOption_Slider *this)
{
  UIOption *v1; // esi@1
  char *v2; // edi@1
  UIElement_Scrollbar *v3; // ebx@1

  v1 = (UIOption *)this;
  v2 = &this->m_prefName.m_charbuffer[-2].m_data[12];
  v3 = (UIElement_Scrollbar *)&this->vfptr;
  this->vfptr = (NoticeHandlerVtbl *)&UIOption_Slider::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&UIOption_Slider::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  UIElement_Scrollbar::~UIElement_Scrollbar(v3);
  UIOption::~UIOption(v1);
}
// 7A1818: using guessed type void *UIOption_Slider::vftable;
// 7A1958: using guessed type bool (__thiscall *UIOption_Slider::vftable)(DBCache *this);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00484C60) --------------------------------------------------------  // acclient.c:192444
signed int __thiscall UIOption_Slider::DynamicCast(UIOption_Slider *this, unsigned int i_eType)
{
  signed int result; // eax@3

  if ( i_eType == 268435511 )
  {
    if ( this )
      result = (signed int)&this->vfptr;
    else
      result = 0;
  }
  else
  {
    result = (signed int)&this->vfptr;
    if ( i_eType != 11 && i_eType != 1 && i_eType != 12 )
      result = i_eType != 10 ? 0 : result;
  }
  return result;
}

//----- (00484CA0) --------------------------------------------------------  // acclient.c:192465
signed int UIOption_Slider::GetUIElementType()
{
  return 268435511;
}

//----- (00484CB0) --------------------------------------------------------  // acclient.c:192471
UIOption_Slider *__thiscall UIOption_Slider::vector_deleting_destructor(UIOption_Slider *this, unsigned int a2)
{
  return UIOption_Slider::vector_deleting_destructor((UIOption_Slider *)((char *)this - 32), a2);
}

//----- (00484CC0) --------------------------------------------------------  // acclient.c:192477
signed int __thiscall UIOption_Slider::DynamicCast(UIOption_Slider *this, unsigned int a2)
{
  return UIOption_Slider::DynamicCast((UIOption_Slider *)((char *)this - 32), a2);
}

//----- (00484CD0) --------------------------------------------------------  // acclient.c:192483
void __thiscall UIOption_Slider::SetUIPreference(UIOption_Slider *this, PStringBase<char> *_prefName)
{
  UIOption_Slider *v2; // esi@1
  PSRefBufferCharData<char> *v3; // eax@2
  PStringBase<char> *v4; // ebp@2
  int v5; // edi@3
  PStringBase<char> v6; // eax@6
  int v7; // eax@12
  unsigned int labelID; // [sp+8h] [bp-10h]@7
  unsigned int tooltipID; // [sp+Ch] [bp-Ch]@7
  int minRange; // [sp+10h] [bp-8h]@9
  int maxRange; // [sp+14h] [bp-4h]@9

  v2 = this;
  if ( !this->m_propName )
  {
    v3 = this->m_prefName.m_charbuffer;
    v4 = _prefName;
    if ( v3 != _prefName->m_charbuffer )
    {
      v5 = (int)&v3[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      v6.m_charbuffer = v4->m_charbuffer;
      v2->m_prefName.m_charbuffer = v4->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v6.m_charbuffer[-1]);
    }
    _prefName = 0;
    labelID = 0;
    tooltipID = 0;
    if ( UIPreferences::InqPreference(v4, (unsigned int *)&_prefName, &labelID, &tooltipID) )
    {
      UIOption::SetLabel((UIOption *)&v2->vfptr, labelID, (unsigned int)_prefName);
      UIOption::SetTooltip((UIOption *)&v2->vfptr, tooltipID, (unsigned int)_prefName);
      if ( v2->m_setAsInt )
      {
        minRange = 0;
        maxRange = 0;
        if ( UIPreferences::InqPreferenceRange(v4, &minRange, &maxRange) )
        {
          v2->m_lowerValue = (double)minRange;
          v2->m_upperValue = (double)maxRange;
        }
      }
      else
      {
        maxRange = 0;
        minRange = 0;
        if ( UIPreferences::InqPreferenceRange(v4, (float *)&maxRange, (float *)&minRange) )
        {
          v7 = minRange;
          LODWORD(v2->m_lowerValue) = maxRange;
          LODWORD(v2->m_upperValue) = v7;
        }
      }
    }
  }
}

//----- (00484E00) --------------------------------------------------------  // acclient.c:192543
void __thiscall UIOption_Slider::SetLabel(UIOption_Slider *this, StringInfo *i_siLabel)
{
  UIElement *v2; // eax@1
  UIElement *v3; // eax@2
  UIElement_Text *v4; // eax@3

  v2 = (UIElement *)((int (__thiscall *)(_DWORD))this->vfptr[13].OnAction)(&this->vfptr);
  if ( v2 )
  {
    v3 = UIElement::GetChildRecursive(v2, 0x1000021Bu);
    if ( v3 )
    {
      v4 = (UIElement_Text *)v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
      if ( v4 )
        UIElement_Text::SetStringInfo(v4, i_siLabel);
    }
  }
}

//----- (00484E40) --------------------------------------------------------  // acclient.c:192563
InterfacePtr<Interface> *__cdecl GetClassObject(InterfacePtr<Interface> *result, Turbine_GUID *i_rcClassType)
{
  InterfaceSystem *v2; // eax@1
  InterfacePtr<Interface> *v3; // eax@1
  Interface *pcInterface; // [sp+0h] [bp-8h]@1
  TResult v5; // [sp+4h] [bp-4h]@1

  pcInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &v5, i_rcClassType, &pcInterface);
  v3 = result;
  result->m_pInterface = pcInterface;
  result->m_trStatus.m_val = 0;
  return v3;
}

//----- (00484E80) --------------------------------------------------------  // acclient.c:192580
UIOption_Slider *__thiscall UIOption_Slider::vector_deleting_destructor(UIOption_Slider *this, unsigned int a2)
{
  UIOption_Slider *v2; // esi@1

  v2 = this;
  UIOption_Slider::~UIOption_Slider(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00484EA0) --------------------------------------------------------  // acclient.c:192592
int __thiscall InterfacePtr<CPlayerModule>::_QueryInterface(void *this, int a2, int a3, int a4)
{
  int v4; // edi@1
  void *v5; // esi@1
  int v6; // eax@2
  signed int v7; // ebx@2
  int v8; // ecx@2
  int v10; // ebp@6
  int v11; // ecx@9
  char v12; // [sp+10h] [bp-4h]@2

  v4 = a3;
  v5 = this;
  if ( a3 )
  {
    v6 = *(_DWORD *)a3;
    a3 = 0;
    v7 = *(_DWORD *)(*(int (__thiscall **)(int, char *, Turbine_GUID *, int *))(v6 + 12))(
                      v4,
                      &v12,
                      &CPlayerModule_InterfaceType_8,
                      &a3);
    v8 = *(_DWORD *)v5;
    if ( v7 < 0 )
    {
      if ( v8 )
        (*(void (**)(void))(*(_DWORD *)v8 + 20))();
      *(_DWORD *)v5 = 0;
      *((_DWORD *)v5 + 1) = 0;
      *(_DWORD *)a2 = v7;
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
      return a2;
    }
    v10 = a3;
    if ( v8 )
      (*(void (**)(void))(*(_DWORD *)v8 + 20))();
    *(_DWORD *)v5 = v10;
    *((_DWORD *)v5 + 1) = 0;
  }
  else
  {
    v11 = *(_DWORD *)this;
    if ( *(_DWORD *)v5 )
    {
      *(_DWORD *)v5 = 0;
      (*(void (**)(void))(*(_DWORD *)v11 + 20))();
      *((_DWORD *)v5 + 1) = 0;
    }
    v7 = -2147467262;
  }
  *(_DWORD *)a2 = v7;
  if ( v4 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
  return a2;
}

//----- (00484F50) --------------------------------------------------------  // acclient.c:192649
void __thiscall UIOption_Slider::UIOption_Slider(UIOption_Slider *this, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIOption_Slider *v3; // esi@1
  GlobalEventHandler *v4; // eax@1

  v3 = this;
  UIOption::UIOption((UIOption *)&this->vfptr);
  UIElement_Scrollbar::UIElement_Scrollbar((UIElement_Scrollbar *)&v3->vfptr, (int)&v3->vfptr, _layout, _full_desc);
  v3->vfptr = (NoticeHandlerVtbl *)&UIOption_Slider::vftable;
  v3->vfptr = (IInputActionCallbackVtbl *)&UIOption_Slider::vftable;
  v3->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  LODWORD(v3->m_default) = 0;
  LODWORD(v3->m_saved) = 0;
  LODWORD(v3->m_current) = 0;
  PStringBase<char>::PStringBase<char>(&v3->m_prefName, &name);
  v3->m_propName = 0;
  LODWORD(v3->m_lowerValue) = 0;
  LODWORD(v3->m_upperValue) = 1065353216;
  v3->m_numStops = 10;
  v3->m_precision = 1;
  v3->m_setAsInt = 0;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v4, 100004u, (NoticeHandler *)v3);
}
// 7A1818: using guessed type void *UIOption_Slider::vftable;
// 7A1958: using guessed type bool (__thiscall *UIOption_Slider::vftable)(DBCache *this);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00485000) --------------------------------------------------------  // acclient.c:192679
UIElement *__cdecl UIOption_Slider::Create(LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIOption_Slider *v2; // eax@1
  int v3; // eax@2
  UIElement *result; // eax@3

  v2 = (UIOption_Slider *)operator new(0x7C8u);
  if ( v2 && (UIOption_Slider::UIOption_Slider(v2, _layout, _full_desc), v3) )
    result = (UIElement *)(v3 + 32);
  else
    result = 0;
  return result;
}

//----- (00485030) --------------------------------------------------------  // acclient.c:192694
void __thiscall UIOption_Slider::SetGameplayOptionProperty(UIOption_Slider *this, unsigned int _propName)
{
  UIOption_Slider *v2; // esi@1
  int v3; // eax@1
  int v4; // edi@1
  bool v5; // bl@1
  unsigned int v6; // ST0C_4@6
  float v7; // ST10_4@10
  BasePropertyDesc *v8; // ecx@15
  unsigned int v9; // esi@15
  BasePropertyValue *v10; // ecx@19
  unsigned int v11; // edx@19
  float defaultVal; // [sp+24h] [bp-12Ch]@1
  BaseProperty defaultProp; // [sp+28h] [bp-128h]@6
  StringInfo siTooltip; // [sp+30h] [bp-120h]@5
  StringInfo siName; // [sp+C0h] [bp-90h]@5

  v2 = this;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&defaultVal, &name);
  v3 = __stricmp(v2->m_prefName.m_charbuffer->m_data, LODWORD(defaultVal));
  v4 = LODWORD(defaultVal) - 20;
  v5 = v3 == 0;
  if ( !InterlockedDecrement((volatile LONG *)(LODWORD(defaultVal) - 20 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  if ( v5 )
  {
    v2->m_propName = _propName;
    StringInfo::StringInfo(&siName);
    StringInfo::StringInfo(&siTooltip);
    if ( UIOption::InqGameplayOptionNameAndTooltip(_propName, &siName, &siTooltip) )
    {
      ((void (__thiscall *)(UIOption_Slider *, StringInfo *))v2->vfptr[7].RecvNotice_ItemAttributesChanged)(v2, &siName);
      v2->vfptr[7].RecvNotice_ServerSaysAttemptFailed((NoticeHandler *)v2, (unsigned int)&siTooltip);
      v6 = v2->m_propName;
      defaultProp.m_pcPropertyDesc = 0;
      defaultProp.m_pcPropertyValue = 0;
      if ( UIOption::InqDefaultGameplayOptionProperty(v6, &defaultProp) )
      {
        if ( v2->m_setAsInt )
        {
          defaultVal = 0.0;
          if ( defaultProp.m_pcPropertyValue )
            ((void (__stdcall *)(float *))defaultProp.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&defaultVal);
          v7 = (double)SLODWORD(defaultVal);
          ((void (__thiscall *)(UIOption_Slider *, _DWORD))v2->vfptr[7].RecvNotice_DisplayFinalStringInfo)(
            v2,
            LODWORD(v7));
        }
        else
        {
          defaultVal = 0.0;
          if ( defaultProp.m_pcPropertyValue )
            ((void (__stdcall *)(float *))defaultProp.m_pcPropertyValue->vfptr[34].__vecDelDtor)(&defaultVal);
          ((void (__thiscall *)(UIOption_Slider *, _DWORD))v2->vfptr[7].RecvNotice_DisplayFinalStringInfo)(
            v2,
            LODWORD(defaultVal));
        }
      }
      if ( (_DWORD)defaultProp.m_pcPropertyDesc )
      {
        v8 = defaultProp.m_pcPropertyDesc;
        v9 = defaultProp.m_pcPropertyDesc->m_cRef - 1;
        defaultProp.m_pcPropertyDesc->m_cRef = v9;
        if ( !v9 )
          ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
        defaultProp.m_pcPropertyDesc = 0;
      }
      if ( defaultProp.m_pcPropertyValue )
      {
        v10 = defaultProp.m_pcPropertyValue;
        v11 = defaultProp.m_pcPropertyValue->m_cRef - 1;
        defaultProp.m_pcPropertyValue->m_cRef = v11;
        if ( !v11 )
          ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
        defaultProp.m_pcPropertyValue = 0;
      }
    }
    StringInfo::~StringInfo(&siTooltip);
    StringInfo::~StringInfo(&siName);
  }
}

//----- (004851E0) --------------------------------------------------------  // acclient.c:192777
void __thiscall InterfacePtr<CPlayerModule>::InterfacePtr<CPlayerModule>(InterfacePtr<CPlayerModule> *this, InterfacePtr<Interface> *_ptr)
{
  InterfacePtr<Interface> *v2; // edx@1
  InterfacePtr<CPlayerModule> *v3; // esi@1
  int v4; // [sp-8h] [bp-Ch]@1

  v2 = _ptr;
  v3 = this;
  this->m_pInterface = 0;
  this->m_trStatus.m_val = 0;
  v4 = (int)v2->m_pInterface;
  if ( v2->m_pInterface )
    v2->m_pInterface->vfptr->AddRef(v2->m_pInterface);
  v3->m_trStatus.m_val = *(_DWORD *)InterfacePtr<CPlayerModule>::_QueryInterface(v3, (int)&_ptr, v4, 0);
}

//----- (00485220) --------------------------------------------------------  // acclient.c:192794
void __cdecl UIOption_Slider::Register()
{
  UIElement::RegisterElementClass(0x10000037u, UIOption_Slider::Create);
}

//----- (00485240) --------------------------------------------------------  // acclient.c:192800
char __thiscall UIOption_Slider::Apply(UIOption_Slider *this, int _userRequested)
{
  UIOption_Slider *v2; // edi@1
  InterfaceSystem *v3; // eax@2
  Interface *v4; // esi@2
  int v5; // ebp@4
  CPlayerModule *v6; // esi@6
  const unsigned int v7; // ST08_4@8
  int v8; // esi@9
  BasePropertyDesc *v9; // ecx@13
  unsigned int v10; // ebp@13
  BasePropertyValue *v11; // ecx@17
  unsigned int v12; // edx@17
  char v13; // al@24
  int v15; // [sp-8h] [bp-30h]@2
  Interface *_rpInterface; // [sp+10h] [bp-18h]@2
  TResult result; // [sp+14h] [bp-14h]@2
  BaseProperty prop; // [sp+18h] [bp-10h]@4
  InterfacePtr<CPlayerModule> spPM; // [sp+20h] [bp-8h]@2

  v2 = this;
  if ( this->m_propName )
  {
    _rpInterface = 0;
    v3 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v3, &result, &CPlayerModule_ClassType, &_rpInterface);
    v4 = _rpInterface;
    v15 = (int)_rpInterface;
    spPM.m_pInterface = 0;
    spPM.m_trStatus.m_val = 0;
    if ( _rpInterface )
      _rpInterface->vfptr->AddRef(_rpInterface);
    v5 = *(_DWORD *)InterfacePtr<CPlayerModule>::_QueryInterface(&spPM, (int)&prop, v15, 0);
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
        if ( v2->m_setAsInt )
        {
          v8 = (unsigned __int64)v2->m_current;
          if ( prop.m_pcPropertyValue )
          {
            BaseProperty::CheckCopyOnWrite(&prop);
            ((void (__stdcall *)(int))prop.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v8);
          }
          v6 = spPM.m_pInterface;
        }
        else
        {
          _rpInterface = (Interface *)LODWORD(v2->m_current);
          if ( prop.m_pcPropertyValue )
          {
            BaseProperty::CheckCopyOnWrite(&prop);
            ((void (__stdcall *)(Interface *))prop.m_pcPropertyValue->vfptr[35].__vecDelDtor)(_rpInterface);
          }
        }
        PlayerModule::SetOption((PlayerModule *)&v6->vfptr, &prop);
        if ( (_DWORD)prop.m_pcPropertyDesc )
        {
          v9 = prop.m_pcPropertyDesc;
          v10 = prop.m_pcPropertyDesc->m_cRef - 1;
          prop.m_pcPropertyDesc->m_cRef = v10;
          if ( !v10 )
            ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
          prop.m_pcPropertyDesc = 0;
        }
        if ( prop.m_pcPropertyValue )
        {
          v11 = prop.m_pcPropertyValue;
          v12 = prop.m_pcPropertyValue->m_cRef - 1;
          prop.m_pcPropertyValue->m_cRef = v12;
          if ( !v12 )
            ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
        }
      }
      v6->vfptr->Release((Interface *)v6);
    }
LABEL_28:
    v2->vfptr[7].RecvNotice_CreateObject((NoticeHandler *)v2, _userRequested);
    return 1;
  }
  if ( *(_DWORD *)&this->m_prefName.m_charbuffer[-1].m_data[12] != 1 )
  {
    if ( this->m_setAsInt )
      v13 = UIPreferences::ModifyPreference(&this->m_prefName, (unsigned __int64)this->m_current);
    else
      v13 = UIPreferences::ModifyPreference(&this->m_prefName, this->m_current);
    if ( v13 )
      CM_UI::SendNotice_UserPreferenceChanged(&v2->m_prefName);
    goto LABEL_28;
  }
  return 0;
}

//----- (00485420) --------------------------------------------------------  // acclient.c:192902
double __thiscall UIOption_Slider::GetValue(UIOption_Slider *this)
{
  UIOption_Slider *v1; // esi@1
  unsigned int v2; // eax@1
  InterfaceSystem *v3; // eax@2
  int v4; // edi@2
  int v5; // ebp@4
  CPlayerModule *v6; // edi@6
  const unsigned int v7; // ST08_4@8
  BasePropertyValue *v8; // ecx@10
  int v9; // edi@10
  BasePropertyDesc *v10; // ecx@22
  unsigned int v11; // esi@22
  int v12; // edx@26
  int v14; // [sp-8h] [bp-34h]@2
  float val; // [sp+10h] [bp-1Ch]@1
  int tmpVal; // [sp+14h] [bp-18h]@2
  TResult result; // [sp+18h] [bp-14h]@2
  BaseProperty baseProp; // [sp+1Ch] [bp-10h]@4
  InterfacePtr<CPlayerModule> spPM; // [sp+24h] [bp-8h]@2

  v1 = this;
  v2 = this->m_propName;
  val = 0.0;
  if ( v2 )
  {
    tmpVal = 0;
    v3 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v3, &result, &CPlayerModule_ClassType, (Interface **)&tmpVal);
    v4 = tmpVal;
    v14 = tmpVal;
    spPM.m_pInterface = 0;
    spPM.m_trStatus.m_val = 0;
    if ( tmpVal )
      (*(void (__thiscall **)(int))(*(_DWORD *)tmpVal + 16))(tmpVal);
    v5 = *(_DWORD *)InterfacePtr<CPlayerModule>::_QueryInterface(&spPM, (int)&baseProp, v14, 0);
    if ( v4 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
    v6 = spPM.m_pInterface;
    if ( (_DWORD)spPM.m_pInterface )
    {
      if ( v5 < 0 )
      {
LABEL_28:
        v6->vfptr->Release((Interface *)v6);
        return val;
      }
      v7 = v1->m_propName;
      baseProp.m_pcPropertyDesc = 0;
      baseProp.m_pcPropertyValue = 0;
      BaseProperty::SetPropertyName(&baseProp, v7);
      if ( !PlayerModule::InqOption((PlayerModule *)&v6->vfptr, v1->m_propName, &baseProp) )
      {
        if ( v1->m_setAsInt )
        {
          v8 = baseProp.m_pcPropertyValue;
          v9 = (unsigned __int64)v1->m_default;
          if ( baseProp.m_pcPropertyValue )
          {
            BaseProperty::CheckCopyOnWrite(&baseProp);
            ((void (__stdcall *)(int))baseProp.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v9);
            v8 = baseProp.m_pcPropertyValue;
          }
          v6 = spPM.m_pInterface;
          goto LABEL_13;
        }
        BaseProperty::SetFloat(&baseProp, v1->m_default);
      }
      v8 = baseProp.m_pcPropertyValue;
LABEL_13:
      if ( v1->m_setAsInt )
      {
        tmpVal = 0;
        if ( v8 )
        {
          ((void (__stdcall *)(int *))v8->vfptr[30].__vecDelDtor)(&tmpVal);
          v8 = baseProp.m_pcPropertyValue;
        }
        val = (double)tmpVal;
      }
      else if ( v8 )
      {
        ((void (__stdcall *)(float *))v8->vfptr[34].__vecDelDtor)(&val);
        v8 = baseProp.m_pcPropertyValue;
      }
      if ( (_DWORD)baseProp.m_pcPropertyDesc )
      {
        v10 = baseProp.m_pcPropertyDesc;
        v11 = baseProp.m_pcPropertyDesc->m_cRef - 1;
        baseProp.m_pcPropertyDesc->m_cRef = v11;
        if ( !v11 )
          ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
        v8 = baseProp.m_pcPropertyValue;
        baseProp.m_pcPropertyDesc = 0;
      }
      if ( v8 )
      {
        v12 = v8->m_cRef - 1;
        v8->m_cRef = v12;
        if ( !v12 )
          ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
      }
      goto LABEL_28;
    }
  }
  else if ( *(_DWORD *)&this->m_prefName.m_charbuffer[-1].m_data[12] != 1 )
  {
    if ( this->m_setAsInt )
    {
      tmpVal = 0;
      UIPreferences::InqPreferenceValue(&this->m_prefName, &tmpVal);
      return (double)tmpVal;
    }
    UIPreferences::InqPreferenceValue(&this->m_prefName, &val);
  }
  return val;
}

//----- (00485620) --------------------------------------------------------  // acclient.c:193021
char __thiscall UIOption_Slider::SaveCurrentValue(UIOption_Slider *this)
{
  UIOption_Slider *v1; // esi@1
  double v2; // st7@1

  v1 = this;
  v2 = UIOption_Slider::GetValue(this);
  v1->m_current = v2;
  v1->m_saved = v2;
  return 1;
}

//----- (00485640) --------------------------------------------------------  // acclient.c:193034
void __thiscall UIOption_Slider::RecvNotice_RefreshOptionsPanel(UIOption_Slider *this)
{
  UIOption_Slider *v1; // esi@1
  double v2; // st7@1
  NoticeHandlerVtbl *v3; // eax@1

  v1 = this;
  v2 = UIOption_Slider::GetValue(this);
  v3 = v1->vfptr;
  v1->m_current = v2;
  ((void (__thiscall *)(UIOption_Slider *))v3[7].RecvNotice_ServerSaysMoveItem)(v1);
}

//----- (006ED4E0) --------------------------------------------------------  // acclient.c:769171
void _E91_46()
{
  outside_val_38 = 1000.0 + 1.0;
}

//----- (006ED500) --------------------------------------------------------  // acclient.c:769177
void _E93_22()
{
  block_length_38 = 24.0 * 8.0;
}

//----- (006ED520) --------------------------------------------------------  // acclient.c:769183
void _E95_22()
{
  half_square_length_38 = 24.0 * 0.5;
}

//----- (006ED540) --------------------------------------------------------  // acclient.c:769189
int _E97_47()
{
  return atexit(_E98_59);
}

//----- (006ED550) --------------------------------------------------------  // acclient.c:769195
int _E100_40()
{
  return atexit(_E101_77);
}

//----- (006ED560) --------------------------------------------------------  // acclient.c:769201
int _E103_32()
{
  return atexit(_E104_47);
}

//----- (006ED570) --------------------------------------------------------  // acclient.c:769207
int _E1_98()
{
  return atexit(_E2_98);
}

