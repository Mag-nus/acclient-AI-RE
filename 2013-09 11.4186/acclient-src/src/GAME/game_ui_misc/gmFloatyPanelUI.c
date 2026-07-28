/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmFloatyPanelUI
   Object     : GAME\game_ui_misc\gmFloatyPanelUI.obj
   Functions  : 21
   Addresses  : 004D18C0 - 006F4220 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004D18C0) --------------------------------------------------------  // acclient.c:257974
void __userpurge gmFloatyPanelUI::gmFloatyPanelUI(gmFloatyPanelUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFloatyPanelUI *v4; // esi@1

  v4 = this;
  gmPanelUI::gmPanelUI((gmPanelUI *)&this->vfptr, a2, _layout, _full_desc);
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
  v4->vfptr = (IInputActionCallbackVtbl *)&gmFloatyPanelUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmFloatyPanelUI::vftable;
}
// 7BB038: using guessed type bool (__thiscall *gmFloatyPanelUI::vftable)(DBCache *this);
// 7BB2E0: using guessed type int (__thiscall *gmFloatyPanelUI::vftable)(void *, char);

//----- (004D1960) --------------------------------------------------------  // acclient.c:258004
gmFloatyPanelUI *__thiscall gmFloatyPanelUI::DynamicCast(gmFloatyPanelUI *this, unsigned int i_eType)
{
  gmFloatyPanelUI *result; // eax@1

  result = this;
  if ( i_eType != 268435535 && i_eType != 268435464 )
    result = (gmFloatyPanelUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004D1990) --------------------------------------------------------  // acclient.c:258015
signed int gmFloatyPanelUI::GetUIElementType()
{
  return 268435535;
}

//----- (004D19A0) --------------------------------------------------------  // acclient.c:258021
void __usercall gmFloatyPanelUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFloatyPanelUI *v3; // eax@1

  v3 = (gmFloatyPanelUI *)operator new(0x65Cu);
  if ( v3 )
    gmFloatyPanelUI::gmFloatyPanelUI(v3, a1, _layout, _full_desc);
}

//----- (004D19E0) --------------------------------------------------------  // acclient.c:258031
gmFloatyPanelUI *__thiscall gmFloatyPanelUI::vector_deleting_destructor(gmFloatyPanelUI *this, unsigned int a2)
{
  gmFloatyPanelUI *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&gmFloatyPanelUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmFloatyPanelUI::vftable;
  gmPanelUI::~gmPanelUI((gmPanelUI *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7BB038: using guessed type bool (__thiscall *gmFloatyPanelUI::vftable)(DBCache *this);
// 7BB2E0: using guessed type int (__thiscall *gmFloatyPanelUI::vftable)(void *, char);

//----- (004D1A10) --------------------------------------------------------  // acclient.c:258047
void __cdecl gmFloatyPanelUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000004Fu,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmFloatyPanelUI::Create);
}

//----- (004D1A30) --------------------------------------------------------  // acclient.c:258055
void __thiscall gmFloatyPanelUI::PostInit(gmFloatyPanelUI *this)
{
  gmFloatyPanelUI *v1; // esi@1
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
  int v13; // eax@17
  UIElement *v14; // eax@19
  int v15; // eax@20
  UIElement *v16; // eax@22
  int v17; // eax@23
  UIElement *v18; // eax@25
  int v19; // eax@26
  UIElement *v20; // eax@28
  int v21; // eax@29
  UIElement *v22; // eax@31
  int v23; // eax@32
  UIElement *v24; // eax@34
  int v25; // eax@35
  UIElement *v26; // eax@37
  int v27; // eax@38
  UIElement *v28; // eax@40
  int v29; // eax@41
  UIElement *v30; // eax@43
  int v31; // eax@44
  UIElement *v32; // eax@46
  int v33; // eax@47
  GlobalEventHandler *v34; // eax@49
  GlobalEventHandler *v35; // edi@49

  v1 = this;
  gmPanelUI::PostInit((gmPanelUI *)&this->vfptr);
  UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x1000007Eu, &v1->m_eWindowID);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000065Cu);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)2);
  else
    v3 = 0;
  v1->m_pTopBorder = (UIElement *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000065Eu);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)2);
  else
    v5 = 0;
  v1->m_pLeftBorder = (UIElement *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000660u);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)9);
  else
    v7 = 0;
  v1->m_pBottomBorder = (UIElement *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000662u);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)2);
  else
    v9 = 0;
  v1->m_pRightBorder = (UIElement *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000065Bu);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)9);
  else
    v11 = 0;
  v1->m_pTopLeftCorner = (UIElement *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000065Du);
  if ( v12 )
    v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)9);
  else
    v13 = 0;
  v1->m_pTopRightCorner = (UIElement *)v13;
  v14 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000065Fu);
  if ( v14 )
    v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)9);
  else
    v15 = 0;
  v1->m_pBottomLeftCorner = (UIElement *)v15;
  v16 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000661u);
  if ( v16 )
    v17 = v16->vfptr[12].OnAction((IInputActionCallback *)v16, (InputEvent *)9);
  else
    v17 = 0;
  v1->m_pBottomRightCorner = (UIElement *)v17;
  v18 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000654u);
  if ( v18 )
    v19 = v18->vfptr[12].OnAction((IInputActionCallback *)v18, (InputEvent *)3);
  else
    v19 = 0;
  v1->m_pTopBorder_Locked = (UIElement *)v19;
  v20 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000656u);
  if ( v20 )
    v21 = v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)3);
  else
    v21 = 0;
  v1->m_pLeftBorder_Locked = (UIElement *)v21;
  v22 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000658u);
  if ( v22 )
    v23 = v22->vfptr[12].OnAction((IInputActionCallback *)v22, (InputEvent *)3);
  else
    v23 = 0;
  v1->m_pBottomBorder_Locked = (UIElement *)v23;
  v24 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000065Au);
  if ( v24 )
    v25 = v24->vfptr[12].OnAction((IInputActionCallback *)v24, (InputEvent *)3);
  else
    v25 = 0;
  v1->m_pRightBorder_Locked = (UIElement *)v25;
  v26 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000653u);
  if ( v26 )
    v27 = v26->vfptr[12].OnAction((IInputActionCallback *)v26, (InputEvent *)3);
  else
    v27 = 0;
  v1->m_pTopLeftCorner_Locked = (UIElement *)v27;
  v28 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000655u);
  if ( v28 )
    v29 = v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)3);
  else
    v29 = 0;
  v1->m_pTopRightCorner_Locked = (UIElement *)v29;
  v30 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000657u);
  if ( v30 )
    v31 = v30->vfptr[12].OnAction((IInputActionCallback *)v30, (InputEvent *)3);
  else
    v31 = 0;
  v1->m_pBottomLeftCorner_Locked = (UIElement *)v31;
  v32 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000659u);
  if ( v32 )
    v33 = v32->vfptr[12].OnAction((IInputActionCallback *)v32, (InputEvent *)3);
  else
    v33 = 0;
  v1->m_pBottomRightCorner_Locked = (UIElement *)v33;
  v34 = GlobalEventHandler::GetGlobalEventHandler();
  v35 = v34;
  if ( v34 )
  {
    v34->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v34,
      (unsigned int)((char *)&loc_4DD1F7 + 1),
      (NoticeHandler *)&v1->vfptr);
    v35->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v35, (unsigned int)&loc_4DD1F0, (NoticeHandler *)&v1->vfptr);
    v35->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v35,
      (unsigned int)((char *)&loc_4DD21E + 1),
      (NoticeHandler *)&v1->vfptr);
    v35->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v35, 5100124u, (NoticeHandler *)&v1->vfptr);
  }
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 1u);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 0xDu);
  ((void (__thiscall *)(gmFloatyPanelUI *))v1->vfptr[26].__vecDelDtor)(v1);
}

//----- (004D1D20) --------------------------------------------------------  // acclient.c:258213
void __thiscall gmFloatyPanelUI::UpdateFromPlayerModule(gmFloatyPanelUI *this)
{
  gmFloatyPanelUI *v1; // esi@1
  PlayerModule *v2; // edi@1
  unsigned int v3; // ST0C_4@10
  unsigned int v4; // ST0C_4@17
  BasePropertyDesc *v5; // ecx@26
  unsigned int v6; // edx@26
  BasePropertyValue *v7; // ecx@30
  unsigned int v8; // edx@30
  int w; // [sp+24h] [bp-30h]@15
  int h; // [sp+28h] [bp-2Ch]@3
  BaseProperty prop; // [sp+2Ch] [bp-28h]@1
  BaseProperty propH; // [sp+34h] [bp-20h]@17
  BaseProperty propW; // [sp+3Ch] [bp-18h]@17
  BaseProperty propY; // [sp+44h] [bp-10h]@10
  BaseProperty propX; // [sp+4Ch] [bp-8h]@10

  v1 = this;
  v2 = (PlayerModule *)&CPlayerSystem::GetPlayerSystem()->playerModule.vfptr;
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
      ((void (__thiscall *)(gmFloatyPanelUI *, int, int))v1->vfptr[3].OnLoseFocus)(v1, h, w);
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
      ((void (__thiscall *)(gmFloatyPanelUI *, int, int))v1->vfptr[4].__vecDelDtor)(v1, w, h);
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

//----- (004D1F40) --------------------------------------------------------  // acclient.c:258291
void __thiscall gmFloatyPanelUI::ResizeTo(gmFloatyPanelUI *this, const int i_width, const int i_height)
{
  gmFloatyPanelUI *v3; // esi@1
  char *v4; // edi@3
  int v5; // ebx@3
  PlayerModule *v6; // edi@5
  int v7; // ebx@5
  BasePropertyDesc *v8; // ecx@8
  unsigned int v9; // edx@8
  BasePropertyValue *v10; // ecx@12
  unsigned int v11; // edx@12
  BasePropertyDesc *v12; // ecx@16
  unsigned int v13; // edx@16
  BasePropertyValue *v14; // ecx@20
  unsigned int v15; // edx@20
  BaseProperty propH; // [sp+Ch] [bp-10h]@5
  BaseProperty propW; // [sp+14h] [bp-8h]@3

  v3 = this;
  gmPanelUI::ResizeTo((gmPanelUI *)&this->vfptr, i_width, i_height);
  if ( v3->m_eWindowID && CPlayerSystem::GetPlayerSystem() )
  {
    v4 = (char *)&CPlayerSystem::GetPlayerSystem()->playerModule;
    propW.m_pcPropertyDesc = 0;
    propW.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propW, 0x10000088u);
    v5 = UIRegion::GetWidth((UIRegion *)&v3->vfptr);
    if ( propW.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propW);
      ((void (__stdcall *)(_DWORD))propW.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v5);
    }
    v6 = (PlayerModule *)(v4 + 4);
    PlayerModule::SetChatWindowOption(v6, v3->m_eWindowID, &propW);
    propH.m_pcPropertyDesc = 0;
    propH.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propH, 0x10000089u);
    v7 = UIRegion::GetHeight((UIRegion *)&v3->vfptr);
    if ( propH.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propH);
      ((void (__stdcall *)(_DWORD))propH.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v7);
    }
    PlayerModule::SetChatWindowOption(v6, v3->m_eWindowID, &propH);
    if ( (_DWORD)propH.m_pcPropertyDesc )
    {
      v8 = propH.m_pcPropertyDesc;
      v9 = propH.m_pcPropertyDesc->m_cRef - 1;
      propH.m_pcPropertyDesc->m_cRef = v9;
      if ( !v9 )
        ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
      propH.m_pcPropertyDesc = 0;
    }
    if ( propH.m_pcPropertyValue )
    {
      v10 = propH.m_pcPropertyValue;
      v11 = propH.m_pcPropertyValue->m_cRef - 1;
      propH.m_pcPropertyValue->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
      propH.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)propW.m_pcPropertyDesc )
    {
      v12 = propW.m_pcPropertyDesc;
      v13 = propW.m_pcPropertyDesc->m_cRef - 1;
      propW.m_pcPropertyDesc->m_cRef = v13;
      if ( !v13 )
        ((void (__stdcall *)(_DWORD))v12->vfptr->__vecDelDtor)(1);
      propW.m_pcPropertyDesc = 0;
    }
    if ( propW.m_pcPropertyValue )
    {
      v14 = propW.m_pcPropertyValue;
      v15 = propW.m_pcPropertyValue->m_cRef - 1;
      propW.m_pcPropertyValue->m_cRef = v15;
      if ( !v15 )
        ((void (__stdcall *)(_DWORD))v14->vfptr->__vecDelDtor)(1);
    }
  }
}

//----- (006F4110) --------------------------------------------------------  // acclient.c:776690
void sub_6F4110()
{
  outside_val_93 = 1000.0 + 1.0;
}

//----- (006F4130) --------------------------------------------------------  // acclient.c:776696
void _E93_77()
{
  block_length_93 = 24.0 * 8.0;
}

//----- (006F4150) --------------------------------------------------------  // acclient.c:776702
void _E95_77()
{
  half_square_length_93 = 24.0 * 0.5;
}

//----- (006F4170) --------------------------------------------------------  // acclient.c:776708
int sub_6F4170()
{
  return atexit(nullsub_681);
}

//----- (006F4180) --------------------------------------------------------  // acclient.c:776714
int _E100_95()
{
  return atexit(nullsub_682);
}

//----- (006F4190) --------------------------------------------------------  // acclient.c:776720
int _E103_87()
{
  return atexit(nullsub_683);
}

//----- (006F41A0) --------------------------------------------------------  // acclient.c:776726
void _E106_60()
{
  DEFAULT_VIEW_RADIUS_62 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F41C0) --------------------------------------------------------  // acclient.c:776732
void _E108_47()
{
  MIN_QUANTUM_62 = 1.0 / 30.0;
}

//----- (006F41E0) --------------------------------------------------------  // acclient.c:776738
void _E110_38()
{
  MAX_QUANTUM_62 = 1.0 / 5.0;
}

//----- (006F4200) --------------------------------------------------------  // acclient.c:776744
void _E112_54()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_97, PFID_A8R8G8B8);
}

//----- (006F4210) --------------------------------------------------------  // acclient.c:776750
int _E117_39()
{
  return atexit(nullsub_679);
}

//----- (006F4220) --------------------------------------------------------  // acclient.c:776756
int sub_6F4220()
{
  return atexit(nullsub_680);
}

