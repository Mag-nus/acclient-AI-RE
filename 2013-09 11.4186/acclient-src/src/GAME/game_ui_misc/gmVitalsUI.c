/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmVitalsUI
   Object     : GAME\game_ui_misc\gmVitalsUI.obj
   Functions  : 21
   Addresses  : 004BFB20 - 006F27C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004BFB20) --------------------------------------------------------  // acclient.c:242172
void __thiscall gmVitalsUI::~gmVitalsUI(gmVitalsUI *this)
{
  UIElement_Field *v1; // ebx@1
  NoticeHandler *v2; // edi@1
  char *v3; // esi@1
  GlobalEventHandler *v4; // eax@1

  v1 = (UIElement_Field *)this;
  v2 = (NoticeHandler *)&this->vfptr;
  v3 = (char *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmVitalsUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmVitalsUI::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)gmFloatyVitalsUI::vftable;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v2);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    9,
    2,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    9,
    1,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    9,
    4,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    9,
    3,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    9,
    6,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    9,
    5,
    v3);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field(v1);
}
// 7B4984: using guessed type void (__thiscall *gmFloatyVitalsUI::vftable[2])(gmVitalsUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7B4990: using guessed type bool (__thiscall *gmVitalsUI::vftable)(DBCache *this);
// 7B4C38: using guessed type int (__thiscall *gmVitalsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004BFBD0) --------------------------------------------------------  // acclient.c:242222
gmVitalsUI *__thiscall gmVitalsUI::DynamicCast(gmVitalsUI *this, unsigned int i_eType)
{
  gmVitalsUI *result; // eax@1

  result = this;
  if ( i_eType != 268435465 )
    result = (gmVitalsUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004BFC00) --------------------------------------------------------  // acclient.c:242239
int __thiscall gmVitalsUI::ListenToElementMessage(gmVitalsUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElement *v2; // esi@1
  unsigned int v3; // eax@2

  v2 = (UIElement *)this;
  if ( i_rMsg->idMessage == 28 )
  {
    v3 = i_rMsg->dwParam1;
    if ( v3 == 7 || v3 == 10 )
      this->vfptr[13].__vecDelDtor((IInputActionCallback *)this, (this->m_state == 268435462) + 268435462);
  }
  return UIElement::ListenToElementMessage(v2, i_rMsg);
}

//----- (004BFC50) --------------------------------------------------------  // acclient.c:242255
void __userpurge gmVitalsUI::gmVitalsUI(gmVitalsUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmVitalsUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)QualityChangeHandler::vftable;
  v4->m_pHealthMeter = 0;
  v4->m_pStaminaMeter = 0;
  v4->m_pManaMeter = 0;
  v4->m_pHealthLabel = 0;
  v4->m_pStaminaLabel = 0;
  v4->m_pManaLabel = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmVitalsUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmVitalsUI::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)gmFloatyVitalsUI::vftable;
}
// 7A5AA4: using guessed type void (__thiscall *QualityChangeHandler::vftable[2])(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int);
// 7B4984: using guessed type void (__thiscall *gmFloatyVitalsUI::vftable[2])(gmVitalsUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7B4990: using guessed type bool (__thiscall *gmVitalsUI::vftable)(DBCache *this);
// 7B4C38: using guessed type int (__thiscall *gmVitalsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004BFCC0) --------------------------------------------------------  // acclient.c:242280
gmVitalsUI *__thiscall gmVitalsUI::scalar_deleting_destructor(gmVitalsUI *this, unsigned int a2)
{
  gmVitalsUI *v2; // esi@1

  v2 = this;
  gmVitalsUI::~gmVitalsUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004BFCE0) --------------------------------------------------------  // acclient.c:242292
void __thiscall gmVitalsUI::PostInit(gmVitalsUI *this)
{
  gmVitalsUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // eax@7
  int v7; // eax@8
  UIElement *v8; // eax@10
  int v9; // eax@11
  UIElement *v10; // eax@13
  int v11; // eax@14
  UIElement *v12; // eax@16

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100000E6u);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)7);
  else
    v3 = 0;
  v1->m_pHealthMeter = (UIElement_Meter *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100000ECu);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)7);
  else
    v5 = 0;
  v1->m_pStaminaMeter = (UIElement_Meter *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100000EEu);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)7);
  else
    v7 = 0;
  v1->m_pManaMeter = (UIElement_Meter *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100000EBu);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12);
  else
    v9 = 0;
  v1->m_pHealthLabel = (UIElement_Text *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100000EDu);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)12);
  else
    v11 = 0;
  v1->m_pStaminaLabel = (UIElement_Text *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100000EFu);
  if ( v12 )
    v1->m_pManaLabel = (UIElement_Text *)v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)12);
  else
    v1->m_pManaLabel = 0;
}

//----- (004BFDE0) --------------------------------------------------------  // acclient.c:242347
void __usercall gmVitalsUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmVitalsUI *v3; // eax@1

  v3 = (gmVitalsUI *)operator new(0x618u);
  if ( v3 )
    gmVitalsUI::gmVitalsUI(v3, a1, _layout, _full_desc);
}

//----- (004BFE10) --------------------------------------------------------  // acclient.c:242357
void __cdecl gmVitalsUI::Register()
{
  UIElement::RegisterElementClass(0x10000009u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmVitalsUI::Create);
}

//----- (004BFE30) --------------------------------------------------------  // acclient.c:242363
void __thiscall gmVitalsUI::Update(gmVitalsUI *this)
{
  gmVitalsUI *v1; // esi@1
  InterfaceSystem *v2; // eax@1
  unsigned int v3; // ebx@1
  CACQualities *v4; // ebp@5
  float _val; // ST08_4@9
  PStringBase<unsigned short> *v6; // eax@10
  unsigned int v7; // ebx@10
  float v8; // ST08_4@15
  PStringBase<unsigned short> *v9; // eax@16
  unsigned int v10; // ebx@16
  float v11; // ST08_4@21
  PStringBase<unsigned short> *v12; // eax@22
  unsigned int v13; // esi@22
  int v14; // [sp+4h] [bp-BCh]@1
  unsigned int uiCurMana; // [sp+1Ch] [bp-A4h]@1
  TResult result; // [sp+20h] [bp-A0h]@1
  unsigned int uiMaxMana; // [sp+24h] [bp-9Ch]@3
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+28h] [bp-98h]@1
  StringInfo v19; // [sp+30h] [bp-90h]@10

  v1 = this;
  uiCurMana = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_12, (Interface **)&uiCurMana);
  v14 = uiCurMana;
  v3 = uiCurMana;
  spPlayerDesc.m_pInterface = 0;
  spPlayerDesc.m_trStatus.m_val = 0;
  if ( uiCurMana )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)uiCurMana + 16))(uiCurMana);
  uiCurMana = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&uiMaxMana, v14, 0);
  if ( v3 )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v3 + 20))(v3);
  v4 = (CACQualities *)spPlayerDesc.m_pInterface;
  if ( (_DWORD)spPlayerDesc.m_pInterface )
  {
    if ( (uiCurMana & 0x80000000) == 0 )
    {
      if ( v1->m_pHealthMeter )
      {
        uiMaxMana = 0;
        uiCurMana = 0;
        CACQualities::InqAttribute2nd((CACQualities *)&spPlayerDesc.m_pInterface->vfptr, 2u, &uiMaxMana, 0);
        CACQualities::InqAttribute2nd(v4, 1u, &uiCurMana, 0);
        _val = (double)uiMaxMana / (double)uiCurMana;
        UIElement::SetAttribute_Float((UIElement *)&v1->m_pHealthMeter->vfptr, 0x69u, _val);
        if ( v1->m_pHealthLabel )
        {
          StringInfo::StringInfo(&v19);
          StringInfo::SetStringIDandTableEnum(&v19, ID_Vitals_VitalBarLabel, 268435457);
          StringInfo::AddVariable_Int(&v19, ID_Cur_0, uiMaxMana);
          StringInfo::AddVariable_Int(&v19, ID_Max_0, uiCurMana);
          v6 = StringInfo::GetString(&v19, (PStringBase<unsigned short> *)&result, 0);
          UIElement_Text::SetText(v1->m_pHealthLabel, v6);
          v7 = result.m_val - 20;
          if ( !InterlockedDecrement((volatile LONG *)(result.m_val - 20 + 4)) && v7 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
          StringInfo::~StringInfo(&v19);
        }
      }
      if ( v1->m_pStaminaMeter )
      {
        uiCurMana = 0;
        uiMaxMana = 0;
        CACQualities::InqAttribute2nd(v4, 4u, &uiCurMana, 0);
        CACQualities::InqAttribute2nd(v4, 3u, &uiMaxMana, 0);
        v8 = (double)uiCurMana / (double)uiMaxMana;
        UIElement::SetAttribute_Float((UIElement *)&v1->m_pStaminaMeter->vfptr, 0x69u, v8);
        if ( v1->m_pStaminaLabel )
        {
          StringInfo::StringInfo(&v19);
          StringInfo::SetStringIDandTableEnum(&v19, ID_Vitals_VitalBarLabel, 268435457);
          StringInfo::AddVariable_Int(&v19, ID_Cur_0, uiCurMana);
          StringInfo::AddVariable_Int(&v19, ID_Max_0, uiMaxMana);
          v9 = StringInfo::GetString(&v19, (PStringBase<unsigned short> *)&result, 0);
          UIElement_Text::SetText(v1->m_pStaminaLabel, v9);
          v10 = result.m_val - 20;
          if ( !InterlockedDecrement((volatile LONG *)(result.m_val - 20 + 4)) && v10 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
          StringInfo::~StringInfo(&v19);
        }
      }
      if ( v1->m_pManaMeter )
      {
        uiCurMana = 0;
        uiMaxMana = 0;
        CACQualities::InqAttribute2nd(v4, 6u, &uiCurMana, 0);
        CACQualities::InqAttribute2nd(v4, 5u, &uiMaxMana, 0);
        v11 = (double)uiCurMana / (double)uiMaxMana;
        UIElement::SetAttribute_Float((UIElement *)&v1->m_pManaMeter->vfptr, 0x69u, v11);
        if ( v1->m_pManaLabel )
        {
          StringInfo::StringInfo(&v19);
          StringInfo::SetStringIDandTableEnum(&v19, ID_Vitals_VitalBarLabel, 268435457);
          StringInfo::AddVariable_Int(&v19, ID_Cur_0, uiCurMana);
          StringInfo::AddVariable_Int(&v19, ID_Max_0, uiMaxMana);
          v12 = StringInfo::GetString(&v19, (PStringBase<unsigned short> *)&result, 0);
          UIElement_Text::SetText(v1->m_pManaLabel, v12);
          v13 = result.m_val - 20;
          if ( !InterlockedDecrement((volatile LONG *)(result.m_val - 20 + 4)) )
          {
            if ( v13 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
          }
          StringInfo::~StringInfo(&v19);
        }
      }
      v4->vfptr->Release((Interface *)v4);
    }
    else
    {
      spPlayerDesc.m_pInterface->vfptr->Release((Interface *)spPlayerDesc.m_pInterface);
    }
  }
}

//----- (004C01F0) --------------------------------------------------------  // acclient.c:242482
void __thiscall gmVitalsUI::OnQualityChanged(gmVitalsUI *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  gmVitalsUI::Update((gmVitalsUI *)((char *)this - 1532));
}

//----- (004C0200) --------------------------------------------------------  // acclient.c:242488
void __thiscall gmVitalsUI::RecvNotice_PlayerDescReceived(gmVitalsUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmVitalsUI::Update((gmVitalsUI *)((char *)this - 1528));
}

//----- (006F26D0) --------------------------------------------------------  // acclient.c:774863
void _E91_85()
{
  outside_val_77 = 1000.0 + 1.0;
}

//----- (006F26F0) --------------------------------------------------------  // acclient.c:774869
void _E93_61()
{
  block_length_77 = 24.0 * 8.0;
}

//----- (006F2710) --------------------------------------------------------  // acclient.c:774875
void _E95_61()
{
  half_square_length_77 = 24.0 * 0.5;
}

//----- (006F2730) --------------------------------------------------------  // acclient.c:774881
int _E97_86()
{
  return atexit(_E98_98);
}

//----- (006F2740) --------------------------------------------------------  // acclient.c:774887
int _E100_79()
{
  return atexit(nullsub_766);
}

//----- (006F2750) --------------------------------------------------------  // acclient.c:774893
int _E103_71()
{
  return atexit(_E104_86);
}

//----- (006F2760) --------------------------------------------------------  // acclient.c:774899
unsigned int _E106_51()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Vitals_VitalBarLabel");
  ID_Vitals_VitalBarLabel = result;
  return result;
}

//----- (006F2780) --------------------------------------------------------  // acclient.c:774909
unsigned int _E108_38()
{
  unsigned int result; // eax@1

  result = compute_str_hash("CUR");
  ID_Cur_0 = result;
  return result;
}

//----- (006F27A0) --------------------------------------------------------  // acclient.c:774919
unsigned int _E110_29()
{
  unsigned int result; // eax@1

  result = compute_str_hash("MAX");
  ID_Max_0 = result;
  return result;
}

//----- (006F27C0) --------------------------------------------------------  // acclient.c:774929
int sub_6F27C0()
{
  return atexit(nullsub_764);
}

