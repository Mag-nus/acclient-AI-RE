/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmFloatySideVitalsUI
   Object     : GAME\game_ui_misc\gmFloatySideVitalsUI.obj
   Functions  : 20
   Addresses  : 004D0170 - 006F3FE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004D0170) --------------------------------------------------------  // acclient.c:256841
void __userpurge gmFloatySideVitalsUI::gmFloatySideVitalsUI(gmFloatySideVitalsUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFloatySideVitalsUI *v4; // esi@1

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
  v4->vfptr = (IInputActionCallbackVtbl *)&gmFloatySideVitalsUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmFloatySideVitalsUI::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)gmFloatyVitalsUI::vftable;
}
// 7B4984: using guessed type void (__thiscall *gmFloatyVitalsUI::vftable[2])(gmVitalsUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7BA688: using guessed type bool (__thiscall *gmFloatySideVitalsUI::vftable)(DBCache *this);
// 7BA930: using guessed type int (__thiscall *gmFloatySideVitalsUI::vftable)(void *, char);

//----- (004D0210) --------------------------------------------------------  // acclient.c:256873
gmFloatySideVitalsUI *__thiscall gmFloatySideVitalsUI::DynamicCast(gmFloatySideVitalsUI *this, unsigned int i_eType)
{
  gmFloatySideVitalsUI *result; // eax@1

  result = this;
  if ( i_eType != 268435542 && i_eType != 268435465 )
    result = (gmFloatySideVitalsUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004D0240) --------------------------------------------------------  // acclient.c:256884
signed int gmFloatySideVitalsUI::GetUIElementType()
{
  return 268435542;
}

//----- (004D0250) --------------------------------------------------------  // acclient.c:256890
void __usercall gmFloatySideVitalsUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFloatySideVitalsUI *v3; // eax@1

  v3 = (gmFloatySideVitalsUI *)operator new(0x65Cu);
  if ( v3 )
    gmFloatySideVitalsUI::gmFloatySideVitalsUI(v3, a1, _layout, _full_desc);
}

//----- (004D0450) --------------------------------------------------------  // acclient.c:256954
gmFloatySideVitalsUI *__thiscall gmFloatySideVitalsUI::vector_deleting_destructor(gmFloatySideVitalsUI *this, unsigned int a2)
{
  gmFloatySideVitalsUI *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&gmFloatySideVitalsUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmFloatySideVitalsUI::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)gmFloatyVitalsUI::vftable;
  gmVitalsUI::~gmVitalsUI((gmVitalsUI *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7B4984: using guessed type void (__thiscall *gmFloatyVitalsUI::vftable[2])(gmVitalsUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7BA688: using guessed type bool (__thiscall *gmFloatySideVitalsUI::vftable)(DBCache *this);
// 7BA930: using guessed type int (__thiscall *gmFloatySideVitalsUI::vftable)(void *, char);

//----- (004D0490) --------------------------------------------------------  // acclient.c:256972
void __cdecl gmFloatySideVitalsUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000056u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmFloatySideVitalsUI::Create);
}

//----- (004D04B0) --------------------------------------------------------  // acclient.c:256980
void __thiscall gmFloatySideVitalsUI::PostInit(gmFloatySideVitalsUI *this)
{
  gmFloatySideVitalsUI *v1; // esi@1
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
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006DFu);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)2);
  else
    v9 = 0;
  v1->m_pTopBorder = (UIElement *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006E1u);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)9);
  else
    v11 = 0;
  v1->m_pLeftBorder = (UIElement *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006E3u);
  if ( v12 )
    v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)2);
  else
    v13 = 0;
  v1->m_pBottomBorder = (UIElement *)v13;
  v14 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006E5u);
  if ( v14 )
    v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)9);
  else
    v15 = 0;
  v1->m_pRightBorder = (UIElement *)v15;
  v16 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006DEu);
  if ( v16 )
    v17 = v16->vfptr[12].OnAction((IInputActionCallback *)v16, (InputEvent *)9);
  else
    v17 = 0;
  v1->m_pTopLeftCorner = (UIElement *)v17;
  v18 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006E0u);
  if ( v18 )
    v19 = v18->vfptr[12].OnAction((IInputActionCallback *)v18, (InputEvent *)9);
  else
    v19 = 0;
  v1->m_pTopRightCorner = (UIElement *)v19;
  v20 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006E2u);
  if ( v20 )
    v21 = v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)9);
  else
    v21 = 0;
  v1->m_pBottomLeftCorner = (UIElement *)v21;
  v22 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006E4u);
  if ( v22 )
    v23 = v22->vfptr[12].OnAction((IInputActionCallback *)v22, (InputEvent *)9);
  else
    v23 = 0;
  v1->m_pBottomRightCorner = (UIElement *)v23;
  v24 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006D7u);
  if ( v24 )
    v25 = v24->vfptr[12].OnAction((IInputActionCallback *)v24, (InputEvent *)3);
  else
    v25 = 0;
  v1->m_pTopBorder_Locked = (UIElement *)v25;
  v26 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006D9u);
  if ( v26 )
    v27 = v26->vfptr[12].OnAction((IInputActionCallback *)v26, (InputEvent *)3);
  else
    v27 = 0;
  v1->m_pLeftBorder_Locked = (UIElement *)v27;
  v28 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006DBu);
  if ( v28 )
    v29 = v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)3);
  else
    v29 = 0;
  v1->m_pBottomBorder_Locked = (UIElement *)v29;
  v30 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006DDu);
  if ( v30 )
    v31 = v30->vfptr[12].OnAction((IInputActionCallback *)v30, (InputEvent *)3);
  else
    v31 = 0;
  v1->m_pRightBorder_Locked = (UIElement *)v31;
  v32 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006D6u);
  if ( v32 )
    v33 = v32->vfptr[12].OnAction((IInputActionCallback *)v32, (InputEvent *)3);
  else
    v33 = 0;
  v1->m_pTopLeftCorner_Locked = (UIElement *)v33;
  v34 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006D8u);
  if ( v34 )
    v35 = v34->vfptr[12].OnAction((IInputActionCallback *)v34, (InputEvent *)3);
  else
    v35 = 0;
  v1->m_pTopRightCorner_Locked = (UIElement *)v35;
  v36 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006DAu);
  if ( v36 )
    v37 = v36->vfptr[12].OnAction((IInputActionCallback *)v36, (InputEvent *)3);
  else
    v37 = 0;
  v1->m_pBottomLeftCorner_Locked = (UIElement *)v37;
  v38 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006DCu);
  if ( v38 )
    v39 = v38->vfptr[12].OnAction((IInputActionCallback *)v38, (InputEvent *)3);
  else
    v39 = 0;
  v1->m_pBottomRightCorner_Locked = (UIElement *)v39;
  v40 = GlobalEventHandler::GetGlobalEventHandler();
  v40->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v40, (unsigned int)&loc_4DD1F0, (NoticeHandler *)&v1->vfptr);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 0xDu);
  ((void (__thiscall *)(gmFloatySideVitalsUI *))v1->vfptr[26].__vecDelDtor)(v1);
}

//----- (004D0810) --------------------------------------------------------  // acclient.c:257177
void __thiscall gmFloatySideVitalsUI::UpdateFromPlayerModule(gmFloatySideVitalsUI *this)
{
  gmFloatySideVitalsUI *v1; // esi@1
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
    v1->vfptr[2].__vecDelDtor((IInputActionCallback *)v1, 1u);
  else
    v1->vfptr[2].__vecDelDtor((IInputActionCallback *)v1, 0);
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
      ((void (__thiscall *)(gmFloatySideVitalsUI *, int, int))v1->vfptr[3].OnLoseFocus)(v1, h, w);
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
      ((void (__thiscall *)(gmFloatySideVitalsUI *, int, int))v1->vfptr[4].__vecDelDtor)(v1, w, h);
    BaseProperty::~BaseProperty(&propH);
    BaseProperty::~BaseProperty(&propW);
    BaseProperty::~BaseProperty(&propY);
    BaseProperty::~BaseProperty(&propX);
  }
  gmFloatyVitalsUI::UpdateLockedStatus((gmFloatyVitalsUI *)v1);
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

//----- (006F3ED0) --------------------------------------------------------  // acclient.c:776546
void sub_6F3ED0()
{
  outside_val_91 = 1000.0 + 1.0;
}

//----- (006F3EF0) --------------------------------------------------------  // acclient.c:776552
void _E93_75()
{
  block_length_91 = 24.0 * 8.0;
}

//----- (006F3F10) --------------------------------------------------------  // acclient.c:776558
void _E95_75()
{
  half_square_length_91 = 24.0 * 0.5;
}

//----- (006F3F30) --------------------------------------------------------  // acclient.c:776564
int sub_6F3F30()
{
  return atexit(nullsub_691);
}

//----- (006F3F40) --------------------------------------------------------  // acclient.c:776570
int _E100_93()
{
  return atexit(nullsub_692);
}

//----- (006F3F50) --------------------------------------------------------  // acclient.c:776576
int _E103_85()
{
  return atexit(nullsub_693);
}

//----- (006F3F60) --------------------------------------------------------  // acclient.c:776582
void _E106_58()
{
  DEFAULT_VIEW_RADIUS_60 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F3F80) --------------------------------------------------------  // acclient.c:776588
void _E108_45()
{
  MIN_QUANTUM_60 = 1.0 / 30.0;
}

//----- (006F3FA0) --------------------------------------------------------  // acclient.c:776594
void _E110_36()
{
  MAX_QUANTUM_60 = 1.0 / 5.0;
}

//----- (006F3FC0) --------------------------------------------------------  // acclient.c:776600
void _E112_52()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_95, PFID_A8R8G8B8);
}

//----- (006F3FD0) --------------------------------------------------------  // acclient.c:776606
int _E117_37()
{
  return atexit(nullsub_689);
}

//----- (006F3FE0) --------------------------------------------------------  // acclient.c:776612
int sub_6F3FE0()
{
  return atexit(nullsub_690);
}

