/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmFloatyVitalsUI
   Object     : GAME\game_ui_misc\gmFloatyVitalsUI.obj
   Functions  : 26
   Addresses  : 004CEBB0 - 006F3DA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004CEBB0) --------------------------------------------------------  // acclient.c:255765
void __userpurge gmFloatyVitalsUI::gmFloatyVitalsUI(gmFloatyVitalsUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFloatyVitalsUI *v4; // esi@1

  v4 = this;
  gmVitalsUI::gmVitalsUI((gmVitalsUI *)&this->vfptr, a2, _layout, _full_desc);
  v4->m_eWindowID = 0;
  v4->m_pTopBorder = 0;
  v4->m_pLeftBorder = 0;
  v4->m_pBottomBorder = 0;
  v4->m_pRightBorder = 0;
  v4->m_pTopLeftCorner = 0;
  v4->m_pTopRightCorner = 0;
  v4->m_pBottomLeftCorner = 0;
  v4->m_pBottomRightCorner = 0;
  v4->m_pTopBorder_Locked = 0;
  v4->m_pLeftBorder_Locked = 0;
  v4->m_pBottomBorder_Locked = 0;
  v4->m_pRightBorder_Locked = 0;
  v4->m_pTopLeftCorner_Locked = 0;
  v4->m_pTopRightCorner_Locked = 0;
  v4->m_pBottomLeftCorner_Locked = 0;
  v4->m_pBottomRightCorner_Locked = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmFloatyVitalsUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmFloatySideVitalsUI::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)gmFloatyVitalsUI::vftable;
}
// 7B4984: using guessed type void (__thiscall *gmFloatyVitalsUI::vftable[2])(gmVitalsUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7B9F80: using guessed type int (__thiscall *gmFloatyVitalsUI::vftable)(void *, char);
// 7BA688: using guessed type bool (__thiscall *gmFloatySideVitalsUI::vftable)(DBCache *this);

//----- (004CEC50) --------------------------------------------------------  // acclient.c:255797
gmFloatyVitalsUI *__thiscall gmFloatyVitalsUI::DynamicCast(gmFloatyVitalsUI *this, unsigned int i_eType)
{
  gmFloatyVitalsUI *result; // eax@1

  result = this;
  if ( i_eType != 268435533 && i_eType != 268435465 )
    result = (gmFloatyVitalsUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004CEC80) --------------------------------------------------------  // acclient.c:255808
signed int gmFloatyVitalsUI::GetUIElementType()
{
  return 268435533;
}

//----- (004CEC90) --------------------------------------------------------  // acclient.c:255814
void __usercall gmFloatyVitalsUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFloatyVitalsUI *v3; // eax@1

  v3 = (gmFloatyVitalsUI *)operator new(0x65Cu);
  if ( v3 )
    gmFloatyVitalsUI::gmFloatyVitalsUI(v3, a1, _layout, _full_desc);
}

//----- (004CECE0) --------------------------------------------------------  // acclient.c:255824
void __stdcall gmFloatyPanelUI::RecvNotice_GameplayOptionChanged(BaseProperty *i_prop, unsigned int i_dwUserData)
{
  BaseProperty *v3; // esi@1
  char *v4; // eax@1
  BasePropertyValue *v5; // ecx@3

  v3 = i_prop;
  v4 = (char *)&BaseProperty::GetPropertyName(i_prop)[-1315861].m_availableProperties.m_reqHash.m_intrusiveTable.m_aInplaceBuckets[2];
  if ( !v4 || v4 == (char *)1 )
  {
    v5 = v3->m_pcPropertyValue;
    if ( v5 )
      ((void (__stdcall *)(BaseProperty **))v5->vfptr[34].__vecDelDtor)(&i_prop);
  }
}

//----- (004CED20) --------------------------------------------------------  // acclient.c:255841
void __thiscall gmFloatyVitalsUI::RecvNotice_PlayerDescReceived(gmFloatyVitalsUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmVitalsUI *v3; // esi@1

  v3 = (gmVitalsUI *)this;
  ((void (__thiscall *)(_DWORD))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[22][39].m_hashKey)(&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[22]);
  gmVitalsUI::RecvNotice_PlayerDescReceived(v3, i_playerDesc, i_playerModule);
}

//----- (004CED50) --------------------------------------------------------  // acclient.c:255851
gmFloatyVitalsUI *__thiscall gmFloatyVitalsUI::vector_deleting_destructor(gmFloatyVitalsUI *this, unsigned int a2)
{
  gmFloatyVitalsUI *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&gmFloatyVitalsUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmFloatySideVitalsUI::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)gmFloatyVitalsUI::vftable;
  gmVitalsUI::~gmVitalsUI((gmVitalsUI *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7B4984: using guessed type void (__thiscall *gmFloatyVitalsUI::vftable[2])(gmVitalsUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7B9F80: using guessed type int (__thiscall *gmFloatyVitalsUI::vftable)(void *, char);
// 7BA688: using guessed type bool (__thiscall *gmFloatySideVitalsUI::vftable)(DBCache *this);

//----- (004CED90) --------------------------------------------------------  // acclient.c:255869
void __cdecl gmFloatyVitalsUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000004Du,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmFloatyVitalsUI::Create);
}

//----- (004CEDB0) --------------------------------------------------------  // acclient.c:255877
void __thiscall gmFloatyVitalsUI::PostInit(gmFloatyVitalsUI *this)
{
  gmFloatyVitalsUI *v1; // esi@1
  int v2; // eax@2
  int v3; // eax@5
  int v4; // eax@8
  int v5; // eax@11
  int v6; // eax@14
  int v7; // eax@17
  UIElement *v8; // eax@19
  int v9; // eax@20
  UIElement *v10; // eax@22
  int v11; // eax@23
  UIElement *v12; // eax@25
  int v13; // eax@26
  UIElement *v14; // eax@28
  int v15; // eax@29
  UIElement *v16; // eax@31
  int v17; // eax@32
  UIElement *v18; // eax@34
  int v19; // eax@35
  UIElement *v20; // eax@37
  int v21; // eax@38
  UIElement *v22; // eax@40
  int v23; // eax@41
  UIElement *v24; // eax@43
  int v25; // eax@44
  UIElement *v26; // eax@46
  int v27; // eax@47
  UIElement *v28; // eax@49
  int v29; // eax@50
  UIElement *v30; // eax@52
  int v31; // eax@53
  UIElement *v32; // eax@55
  int v33; // eax@56
  UIElement *v34; // eax@58
  int v35; // eax@59
  UIElement *v36; // eax@61
  int v37; // eax@62
  UIElement *v38; // eax@64
  int v39; // eax@65
  GlobalEventHandler *v40; // eax@67

  v1 = this;
  gmVitalsUI::PostInit((gmVitalsUI *)&this->vfptr);
  UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x1000007Eu, &v1->m_eWindowID);
  if ( v1 )
    v2 = (int)&v1->vfptr;
  else
    v2 = 0;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    9,
    2,
    v2);
  if ( v1 )
    v3 = (int)&v1->vfptr;
  else
    v3 = 0;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    9,
    1,
    v3);
  if ( v1 )
    v4 = (int)&v1->vfptr;
  else
    v4 = 0;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    9,
    4,
    v4);
  if ( v1 )
    v5 = (int)&v1->vfptr;
  else
    v5 = 0;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    9,
    3,
    v5);
  if ( v1 )
    v6 = (int)&v1->vfptr;
  else
    v6 = 0;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    9,
    6,
    v6);
  if ( v1 )
    v7 = (int)&v1->vfptr;
  else
    v7 = 0;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    9,
    5,
    v7);
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000063Cu);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)2);
  else
    v9 = 0;
  v1->m_pTopBorder = (UIElement *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000063Eu);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)9);
  else
    v11 = 0;
  v1->m_pLeftBorder = (UIElement *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000640u);
  if ( v12 )
    v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)2);
  else
    v13 = 0;
  v1->m_pBottomBorder = (UIElement *)v13;
  v14 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000642u);
  if ( v14 )
    v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)9);
  else
    v15 = 0;
  v1->m_pRightBorder = (UIElement *)v15;
  v16 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000063Bu);
  if ( v16 )
    v17 = v16->vfptr[12].OnAction((IInputActionCallback *)v16, (InputEvent *)9);
  else
    v17 = 0;
  v1->m_pTopLeftCorner = (UIElement *)v17;
  v18 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000063Du);
  if ( v18 )
    v19 = v18->vfptr[12].OnAction((IInputActionCallback *)v18, (InputEvent *)9);
  else
    v19 = 0;
  v1->m_pTopRightCorner = (UIElement *)v19;
  v20 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000063Fu);
  if ( v20 )
    v21 = v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)9);
  else
    v21 = 0;
  v1->m_pBottomLeftCorner = (UIElement *)v21;
  v22 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000641u);
  if ( v22 )
    v23 = v22->vfptr[12].OnAction((IInputActionCallback *)v22, (InputEvent *)9);
  else
    v23 = 0;
  v1->m_pBottomRightCorner = (UIElement *)v23;
  v24 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000634u);
  if ( v24 )
    v25 = v24->vfptr[12].OnAction((IInputActionCallback *)v24, (InputEvent *)3);
  else
    v25 = 0;
  v1->m_pTopBorder_Locked = (UIElement *)v25;
  v26 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000636u);
  if ( v26 )
    v27 = v26->vfptr[12].OnAction((IInputActionCallback *)v26, (InputEvent *)3);
  else
    v27 = 0;
  v1->m_pLeftBorder_Locked = (UIElement *)v27;
  v28 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000638u);
  if ( v28 )
    v29 = v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)3);
  else
    v29 = 0;
  v1->m_pBottomBorder_Locked = (UIElement *)v29;
  v30 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000063Au);
  if ( v30 )
    v31 = v30->vfptr[12].OnAction((IInputActionCallback *)v30, (InputEvent *)3);
  else
    v31 = 0;
  v1->m_pRightBorder_Locked = (UIElement *)v31;
  v32 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000633u);
  if ( v32 )
    v33 = v32->vfptr[12].OnAction((IInputActionCallback *)v32, (InputEvent *)3);
  else
    v33 = 0;
  v1->m_pTopLeftCorner_Locked = (UIElement *)v33;
  v34 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000635u);
  if ( v34 )
    v35 = v34->vfptr[12].OnAction((IInputActionCallback *)v34, (InputEvent *)3);
  else
    v35 = 0;
  v1->m_pTopRightCorner_Locked = (UIElement *)v35;
  v36 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000637u);
  if ( v36 )
    v37 = v36->vfptr[12].OnAction((IInputActionCallback *)v36, (InputEvent *)3);
  else
    v37 = 0;
  v1->m_pBottomLeftCorner_Locked = (UIElement *)v37;
  v38 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000639u);
  if ( v38 )
    v39 = v38->vfptr[12].OnAction((IInputActionCallback *)v38, (InputEvent *)3);
  else
    v39 = 0;
  v1->m_pBottomRightCorner_Locked = (UIElement *)v39;
  v40 = GlobalEventHandler::GetGlobalEventHandler();
  v40->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v40, (unsigned int)&loc_4DD1F0, (NoticeHandler *)&v1->vfptr);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 0xDu);
  ((void (__thiscall *)(gmFloatyVitalsUI *))v1->vfptr[26].__vecDelDtor)(v1);
}

//----- (004CF110) --------------------------------------------------------  // acclient.c:256074
void __thiscall gmFloatyVitalsUI::ListenToGlobalMessage(gmFloatyVitalsUI *this, unsigned int i_messageID, int i_data_int)
{
  PlayerModule *v3; // esi@1

  v3 = (PlayerModule *)this;
  if ( i_messageID == 13 )
    gmFloatyVitalsUI::UpdateLockedStatus(this);
  gmPanelUI::ListenToGlobalMessage(v3, (BaseProperty *)i_messageID, i_data_int);
}

//----- (004CF140) --------------------------------------------------------  // acclient.c:256085
void __thiscall gmFloatyVitalsUI::UpdateFromPlayerModule(gmFloatyVitalsUI *this)
{
  gmFloatyVitalsUI *v1; // esi@1
  PlayerModule *v2; // edi@1
  unsigned int v3; // ST10_4@13
  unsigned int v4; // ST10_4@20
  BasePropertyDesc *v5; // ecx@29
  unsigned int v6; // edx@29
  BasePropertyValue *v7; // ecx@33
  unsigned int v8; // edx@33
  int w; // [sp+28h] [bp-30h]@18
  int h; // [sp+2Ch] [bp-2Ch]@6
  BaseProperty prop; // [sp+30h] [bp-28h]@4
  BaseProperty propH; // [sp+38h] [bp-20h]@20
  BaseProperty propW; // [sp+40h] [bp-18h]@20
  BaseProperty propY; // [sp+48h] [bp-10h]@13
  BaseProperty propX; // [sp+50h] [bp-8h]@13

  v1 = this;
  v2 = (PlayerModule *)&CPlayerSystem::GetPlayerSystem()->playerModule.vfptr;
  if ( (unsigned __int8)PlayerModule::SideBySideVitals(v2) )
    v1->vfptr[2].__vecDelDtor((IInputActionCallback *)v1, 0);
  else
    v1->vfptr[2].__vecDelDtor((IInputActionCallback *)v1, 1u);
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( PlayerModule::InqOption(v2, 0x10000080u, &prop) && prop.m_pcPropertyValue )
    ((void (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[34].__vecDelDtor)(&h);
  if ( PlayerModule::InqOption(v2, 0x10000081u, &prop) && prop.m_pcPropertyValue )
    ((void (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[34].__vecDelDtor)(&h);
  if ( v1->m_eWindowID && CPlayerSystem::GetPlayerSystem() && !CPlayerSystem::GetPlayerSystem()->m_layoutFromFile )
  {
    v3 = v1->m_eWindowID;
    propX.m_pcPropertyDesc = 0;
    propX.m_pcPropertyValue = 0;
    propY.m_pcPropertyDesc = 0;
    propY.m_pcPropertyValue = 0;
    if ( PlayerModule::InqChatWindowOption(v2, v3, 0x10000086u, &propX)
      && PlayerModule::InqChatWindowOption(v2, v1->m_eWindowID, 0x10000087u, &propY)
      && propX.m_pcPropertyValue
      && (unsigned __int8)((int (__stdcall *)(_DWORD))propX.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&h)
      && propY.m_pcPropertyValue
      && (unsigned __int8)((int (__stdcall *)(_DWORD))propY.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&w) )
      ((void (__thiscall *)(gmFloatyVitalsUI *, int, int))v1->vfptr[3].OnLoseFocus)(v1, h, w);
    v4 = v1->m_eWindowID;
    propW.m_pcPropertyDesc = 0;
    propW.m_pcPropertyValue = 0;
    propH.m_pcPropertyDesc = 0;
    propH.m_pcPropertyValue = 0;
    if ( PlayerModule::InqChatWindowOption(v2, v4, 0x10000088u, &propW)
      && PlayerModule::InqChatWindowOption(v2, v1->m_eWindowID, 0x10000089u, &propH)
      && propW.m_pcPropertyValue
      && (unsigned __int8)((int (__stdcall *)(_DWORD))propW.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&w)
      && propH.m_pcPropertyValue
      && (unsigned __int8)((int (__stdcall *)(_DWORD))propH.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&h) )
      ((void (__thiscall *)(gmFloatyVitalsUI *, int, int))v1->vfptr[4].__vecDelDtor)(v1, w, h);
    BaseProperty::~BaseProperty(&propH);
    BaseProperty::~BaseProperty(&propW);
    BaseProperty::~BaseProperty(&propY);
    BaseProperty::~BaseProperty(&propX);
  }
  gmFloatyVitalsUI::UpdateLockedStatus(v1);
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v5 = prop.m_pcPropertyDesc;
    v6 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v6;
    if ( !v6 )
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    prop.m_pcPropertyDesc = 0;
  }
  if ( prop.m_pcPropertyValue )
  {
    v7 = prop.m_pcPropertyValue;
    v8 = prop.m_pcPropertyValue->m_cRef - 1;
    prop.m_pcPropertyValue->m_cRef = v8;
    if ( !v8 )
      ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
  }
}

//----- (004D0280) --------------------------------------------------------  // acclient.c:256900
void __thiscall gmFloatyVitalsUI::UpdateLockedStatus(gmFloatyVitalsUI *this)
{
  gmFloatyVitalsUI *v1; // esi@1
  CPlayerSystem *v2; // eax@1
  char v3; // al@1
  UIElement *v4; // ecx@1

  v1 = this;
  v2 = CPlayerSystem::GetPlayerSystem();
  v3 = PlayerModule::LockUI((PlayerModule *)&v2->playerModule.vfptr);
  v4 = v1->m_pTopBorder;
  if ( v3 )
  {
    ((void (__stdcall *)(_DWORD))v4->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pTopBorder->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pLeftBorder->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pBottomBorder->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pRightBorder->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pTopLeftCorner->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pTopRightCorner->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pBottomLeftCorner->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pBottomRightCorner->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(signed int))v1->m_pTopBorder_Locked->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pLeftBorder_Locked->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pBottomBorder_Locked->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pRightBorder_Locked->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pTopLeftCorner_Locked->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pTopRightCorner_Locked->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pBottomLeftCorner_Locked->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pBottomRightCorner_Locked->vfptr[2].__vecDelDtor)(1);
  }
  else
  {
    ((void (__stdcall *)(signed int))v4->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pTopBorder->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pLeftBorder->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pBottomBorder->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pRightBorder->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pTopLeftCorner->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pTopRightCorner->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pBottomLeftCorner->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pBottomRightCorner->vfptr[2].__vecDelDtor)(1);
    ((void (__stdcall *)(_DWORD))v1->m_pTopBorder_Locked->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pLeftBorder_Locked->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pBottomBorder_Locked->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pRightBorder_Locked->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pTopLeftCorner_Locked->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pTopRightCorner_Locked->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pBottomLeftCorner_Locked->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pBottomRightCorner_Locked->vfptr[2].__vecDelDtor)(0);
  }
}

//----- (004D0A50) --------------------------------------------------------  // acclient.c:257259
void __userpurge gmFloatySideVitalsUI::ResizeTo(gmFloatyVitalsUI *this@<ecx>, int a2@<edi>, const int i_width, const int i_height)
{
  gmFloatyVitalsUI *v4; // esi@1
  char *v5; // edi@3
  int v6; // ebx@3
  PlayerModule *v7; // edi@5
  int v8; // ebx@5
  BasePropertyDesc *v9; // ecx@8
  unsigned int v10; // edx@8
  BasePropertyValue *v11; // ecx@12
  unsigned int v12; // edx@12
  BasePropertyDesc *v13; // ecx@16
  unsigned int v14; // edx@16
  BasePropertyValue *v15; // ecx@20
  unsigned int v16; // edx@20
  BaseProperty propH; // [sp+Ch] [bp-10h]@5
  BaseProperty propW; // [sp+14h] [bp-8h]@3

  v4 = this;
  UIElement::ResizeTo((UIElement *)&this->vfptr, a2, i_width, i_height);
  if ( v4->m_eWindowID && CPlayerSystem::GetPlayerSystem() )
  {
    v5 = (char *)&CPlayerSystem::GetPlayerSystem()->playerModule;
    propW.m_pcPropertyDesc = 0;
    propW.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propW, 0x10000088u);
    v6 = UIRegion::GetWidth((UIRegion *)&v4->vfptr);
    if ( propW.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propW);
      ((void (__stdcall *)(_DWORD))propW.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v6);
    }
    v7 = (PlayerModule *)(v5 + 4);
    PlayerModule::SetChatWindowOption(v7, v4->m_eWindowID, &propW);
    propH.m_pcPropertyDesc = 0;
    propH.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propH, 0x10000089u);
    v8 = UIRegion::GetHeight((UIRegion *)&v4->vfptr);
    if ( propH.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propH);
      ((void (__stdcall *)(_DWORD))propH.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v8);
    }
    PlayerModule::SetChatWindowOption(v7, v4->m_eWindowID, &propH);
    if ( (_DWORD)propH.m_pcPropertyDesc )
    {
      v9 = propH.m_pcPropertyDesc;
      v10 = propH.m_pcPropertyDesc->m_cRef - 1;
      propH.m_pcPropertyDesc->m_cRef = v10;
      if ( !v10 )
        ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
      propH.m_pcPropertyDesc = 0;
    }
    if ( propH.m_pcPropertyValue )
    {
      v11 = propH.m_pcPropertyValue;
      v12 = propH.m_pcPropertyValue->m_cRef - 1;
      propH.m_pcPropertyValue->m_cRef = v12;
      if ( !v12 )
        ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(1);
      propH.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)propW.m_pcPropertyDesc )
    {
      v13 = propW.m_pcPropertyDesc;
      v14 = propW.m_pcPropertyDesc->m_cRef - 1;
      propW.m_pcPropertyDesc->m_cRef = v14;
      if ( !v14 )
        ((void (__stdcall *)(_DWORD))v13->vfptr->__vecDelDtor)(1);
      propW.m_pcPropertyDesc = 0;
    }
    if ( propW.m_pcPropertyValue )
    {
      v15 = propW.m_pcPropertyValue;
      v16 = propW.m_pcPropertyValue->m_cRef - 1;
      propW.m_pcPropertyValue->m_cRef = v16;
      if ( !v16 )
        ((void (__stdcall *)(_DWORD))v15->vfptr->__vecDelDtor)(1);
    }
  }
}

//----- (004D20B0) --------------------------------------------------------  // acclient.c:258374
void __thiscall gmFloatySideVitalsUI::MoveTo(gmFloatyVitalsUI *this, const int i_x, const int i_y)
{
  int v3; // ebx@1
  gmFloatyVitalsUI *v4; // esi@1
  int v5; // edi@1
  UIRegion *v6; // eax@2
  int v7; // ebp@2
  UIRegion *v8; // eax@3
  int v9; // ebx@3
  UIRegion *v10; // eax@6
  int v11; // ebp@6
  UIRegion *v12; // eax@7
  int v13; // edi@7
  char *v14; // edi@12
  int v15; // ebx@12
  PlayerModule *v16; // edi@14
  int v17; // ebx@14
  BasePropertyDesc *v18; // ecx@17
  unsigned int v19; // edx@17
  BasePropertyValue *v20; // ecx@21
  unsigned int v21; // edx@21
  BasePropertyDesc *v22; // ecx@25
  unsigned int v23; // edx@25
  BasePropertyValue *v24; // ecx@29
  unsigned int v25; // edx@29
  BaseProperty propY; // [sp+10h] [bp-10h]@14
  BaseProperty propX; // [sp+18h] [bp-8h]@12

  v3 = i_x;
  v4 = this;
  v5 = i_y;
  if ( ((int (*)(void))this->vfptr[13].OnAction)() )
  {
    v6 = (UIRegion *)((int (__thiscall *)(gmFloatyVitalsUI *))v4->vfptr[13].OnAction)(v4);
    v7 = UIRegion::GetWidth(v6);
    if ( i_x > v7 - UIRegion::GetWidth((UIRegion *)&v4->vfptr) )
    {
      v8 = (UIRegion *)((int (__thiscall *)(_DWORD))v4->vfptr[13].OnAction)(v4);
      v9 = UIRegion::GetWidth(v8);
      v3 = v9 - UIRegion::GetWidth((UIRegion *)&v4->vfptr);
    }
    if ( v3 < 0 )
      v3 = 0;
    v10 = (UIRegion *)((int (__thiscall *)(_DWORD))v4->vfptr[13].OnAction)(v4);
    v11 = UIRegion::GetHeight(v10);
    if ( i_y > v11 - UIRegion::GetHeight((UIRegion *)&v4->vfptr) )
    {
      v12 = (UIRegion *)((int (__thiscall *)(_DWORD))v4->vfptr[13].OnAction)(v4);
      v13 = UIRegion::GetHeight(v12);
      v5 = v13 - UIRegion::GetHeight((UIRegion *)&v4->vfptr);
    }
    if ( v5 < 0 )
      v5 = 0;
  }
  UIElement::MoveTo((UIElement *)&v4->vfptr, v3, v5);
  if ( v4->m_eWindowID && CPlayerSystem::GetPlayerSystem() )
  {
    v14 = (char *)&CPlayerSystem::GetPlayerSystem()->playerModule;
    propX.m_pcPropertyDesc = 0;
    propX.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propX, 0x10000086u);
    v15 = v4->m_box.m_x0;
    if ( propX.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propX);
      ((void (__stdcall *)(_DWORD))propX.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v15);
    }
    v16 = (PlayerModule *)(v14 + 4);
    PlayerModule::SetChatWindowOption(v16, v4->m_eWindowID, &propX);
    propY.m_pcPropertyDesc = 0;
    propY.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propY, 0x10000087u);
    v17 = v4->m_box.m_y0;
    if ( propY.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propY);
      ((void (__stdcall *)(_DWORD))propY.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v17);
    }
    PlayerModule::SetChatWindowOption(v16, v4->m_eWindowID, &propY);
    if ( (_DWORD)propY.m_pcPropertyDesc )
    {
      v18 = propY.m_pcPropertyDesc;
      v19 = propY.m_pcPropertyDesc->m_cRef - 1;
      propY.m_pcPropertyDesc->m_cRef = v19;
      if ( !v19 )
        ((void (__stdcall *)(_DWORD))v18->vfptr->__vecDelDtor)(1);
      propY.m_pcPropertyDesc = 0;
    }
    if ( propY.m_pcPropertyValue )
    {
      v20 = propY.m_pcPropertyValue;
      v21 = propY.m_pcPropertyValue->m_cRef - 1;
      propY.m_pcPropertyValue->m_cRef = v21;
      if ( !v21 )
        ((void (__stdcall *)(_DWORD))v20->vfptr->__vecDelDtor)(1);
      propY.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)propX.m_pcPropertyDesc )
    {
      v22 = propX.m_pcPropertyDesc;
      v23 = propX.m_pcPropertyDesc->m_cRef - 1;
      propX.m_pcPropertyDesc->m_cRef = v23;
      if ( !v23 )
        ((void (__stdcall *)(_DWORD))v22->vfptr->__vecDelDtor)(1);
      propX.m_pcPropertyDesc = 0;
    }
    if ( propX.m_pcPropertyValue )
    {
      v24 = propX.m_pcPropertyValue;
      v25 = propX.m_pcPropertyValue->m_cRef - 1;
      propX.m_pcPropertyValue->m_cRef = v25;
      if ( !v25 )
        ((void (__stdcall *)(_DWORD))v24->vfptr->__vecDelDtor)(1);
    }
  }
}

//----- (006F3C90) --------------------------------------------------------  // acclient.c:776402
void _E91_97()
{
  outside_val_89 = 1000.0 + 1.0;
}

//----- (006F3CB0) --------------------------------------------------------  // acclient.c:776408
void _E93_73()
{
  block_length_89 = 24.0 * 8.0;
}

//----- (006F3CD0) --------------------------------------------------------  // acclient.c:776414
void _E95_73()
{
  half_square_length_89 = 24.0 * 0.5;
}

//----- (006F3CF0) --------------------------------------------------------  // acclient.c:776420
int _E97_98()
{
  return atexit(nullsub_701);
}

//----- (006F3D00) --------------------------------------------------------  // acclient.c:776426
int _E100_91()
{
  return atexit(nullsub_702);
}

//----- (006F3D10) --------------------------------------------------------  // acclient.c:776432
int _E103_83()
{
  return atexit(_E104_98);
}

//----- (006F3D20) --------------------------------------------------------  // acclient.c:776438
void _E106_56()
{
  DEFAULT_VIEW_RADIUS_58 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F3D40) --------------------------------------------------------  // acclient.c:776444
void _E108_43()
{
  MIN_QUANTUM_58 = 1.0 / 30.0;
}

//----- (006F3D60) --------------------------------------------------------  // acclient.c:776450
void _E110_34()
{
  MAX_QUANTUM_58 = 1.0 / 5.0;
}

//----- (006F3D80) --------------------------------------------------------  // acclient.c:776456
void _E112_50()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_93, PFID_A8R8G8B8);
}

//----- (006F3D90) --------------------------------------------------------  // acclient.c:776462
int _E117_35()
{
  return atexit(nullsub_699);
}

//----- (006F3DA0) --------------------------------------------------------  // acclient.c:776468
int sub_6F3DA0()
{
  return atexit(nullsub_700);
}

