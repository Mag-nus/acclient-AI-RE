/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmFloatyMainChatUI
   Object     : GAME\game_ui_misc\gmFloatyMainChatUI.obj
   Functions  : 24
   Addresses  : 004D22B0 - 006F4340 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004D22B0) --------------------------------------------------------  // acclient.c:258492
void __thiscall gmFloatyMainChatUI::gmFloatyMainChatUI(gmFloatyMainChatUI *this, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFloatyMainChatUI *v3; // esi@1

  v3 = this;
  gmMainChatUI::gmMainChatUI((gmMainChatUI *)&this->vfptr, _layout, _full_desc);
  v3->m_pTopBorder = 0;
  v3->m_pLeftBorder = 0;
  v3->m_pBottomBorder = 0;
  v3->m_pRightBorder = 0;
  v3->m_pTopLeftCorner = 0;
  v3->m_pTopRightCorner = 0;
  v3->m_pBottomLeftCorner = 0;
  v3->m_pBottomRightCorner = 0;
  v3->m_pTopBorder_Locked = 0;
  v3->m_pLeftBorder_Locked = 0;
  v3->m_pBottomBorder_Locked = 0;
  v3->m_pRightBorder_Locked = 0;
  v3->m_pTopLeftCorner_Locked = 0;
  v3->m_pTopRightCorner_Locked = 0;
  v3->m_pBottomLeftCorner_Locked = 0;
  v3->m_pBottomRightCorner_Locked = 0;
  v3->vfptr = (NoticeHandlerVtbl *)&gmFloatyMainChatUI::vftable;
  v3->vfptr = (IInputActionCallbackVtbl *)&gmFloatyMainChatUI::vftable;
}
// 7BB520: using guessed type int (__stdcall *gmFloatyMainChatUI::vftable)(char);
// 7BB658: using guessed type bool (__thiscall *gmFloatyMainChatUI::vftable)(DBCache *this);

//----- (004D2340) --------------------------------------------------------  // acclient.c:258521
signed int __thiscall gmFloatyMainChatUI::DynamicCast(gmFloatyMainChatUI *this, unsigned int i_eType)
{
  signed int result; // eax@2

  if ( i_eType == 268435536 || i_eType == 268435521 )
    result = this != (gmFloatyMainChatUI *)4 ? (unsigned int)this : 0;
  else
    result = i_eType != 3 ? 0 : (unsigned int)this;
  return result;
}

//----- (004D2370) --------------------------------------------------------  // acclient.c:258533
signed int gmFloatyMainChatUI::GetUIElementType()
{
  return 268435536;
}

//----- (004D2380) --------------------------------------------------------  // acclient.c:258539
UIElement *__cdecl gmFloatyMainChatUI::Create(LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFloatyMainChatUI *v2; // eax@1
  int v3; // eax@2
  UIElement *result; // eax@3

  v2 = (gmFloatyMainChatUI *)operator new(0x698u);
  if ( v2 && (gmFloatyMainChatUI::gmFloatyMainChatUI(v2, _layout, _full_desc), v3) )
    result = (UIElement *)(v3 + 4);
  else
    result = 0;
  return result;
}

//----- (004D23D0) --------------------------------------------------------  // acclient.c:258554
void __thiscall gmFloatyMainChatUI::UpdateLockedStatus(gmFloatyMainChatUI *this)
{
  gmFloatyMainChatUI *v1; // esi@1
  CPlayerSystem *v2; // eax@2

  v1 = this;
  if ( CPlayerSystem::GetPlayerSystem()
    && (v2 = CPlayerSystem::GetPlayerSystem(),
        (unsigned __int8)PlayerModule::LockUI((PlayerModule *)&v2->playerModule.vfptr)) )
  {
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

//----- (004D2620) --------------------------------------------------------  // acclient.c:258639
void *__thiscall gmFloatyMainChatUI::scalar_deleting_destructor(gmMainChatUI *this, char a2)
{
  void *v2; // esi@1

  v2 = &this[-1].m_OldHeight;
  this[-1].m_OldHeight = (int)&gmFloatyMainChatUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmFloatyMainChatUI::vftable;
  gmMainChatUI::~gmMainChatUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7BB520: using guessed type int (__stdcall *gmFloatyMainChatUI::vftable)(char);
// 7BB658: using guessed type bool (__thiscall *gmFloatyMainChatUI::vftable)(DBCache *this);

//----- (004D2650) --------------------------------------------------------  // acclient.c:258655
void __cdecl gmFloatyMainChatUI::Register()
{
  UIElement::RegisterElementClass(0x10000050u, gmFloatyMainChatUI::Create);
}

//----- (004D2670) --------------------------------------------------------  // acclient.c:258661
void __thiscall gmFloatyMainChatUI::PostInit(gmFloatyMainChatUI *this)
{
  gmFloatyMainChatUI *v1; // esi@1
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
  v2 = UIElement::GetChildRecursive((UIElement *)this, 0x1000069Cu);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)2);
  else
    v3 = 0;
  v1->m_OldHeight = v3;
  v4 = UIElement::GetChildRecursive((UIElement *)v1, 0x1000069Eu);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)9);
  else
    v5 = 0;
  v1->m_pTopBorder = (UIElement *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)v1, 0x100006A0u);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)9);
  else
    v7 = 0;
  v1->m_pLeftBorder = (UIElement *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)v1, 0x100006A2u);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)9);
  else
    v9 = 0;
  v1->m_pBottomBorder = (UIElement *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)v1, 0x1000069Bu);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)9);
  else
    v11 = 0;
  v1->m_pRightBorder = (UIElement *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)v1, 0x1000069Du);
  if ( v12 )
    v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)9);
  else
    v13 = 0;
  v1->m_pTopLeftCorner = (UIElement *)v13;
  v14 = UIElement::GetChildRecursive((UIElement *)v1, 0x1000069Fu);
  if ( v14 )
    v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)9);
  else
    v15 = 0;
  v1->m_pTopRightCorner = (UIElement *)v15;
  v16 = UIElement::GetChildRecursive((UIElement *)v1, 0x100006A1u);
  if ( v16 )
    v17 = v16->vfptr[12].OnAction((IInputActionCallback *)v16, (InputEvent *)9);
  else
    v17 = 0;
  v1->m_pBottomLeftCorner = (UIElement *)v17;
  v18 = UIElement::GetChildRecursive((UIElement *)v1, 0x10000694u);
  if ( v18 )
    v19 = v18->vfptr[12].OnAction((IInputActionCallback *)v18, (InputEvent *)3);
  else
    v19 = 0;
  v1->m_pBottomRightCorner = (UIElement *)v19;
  v20 = UIElement::GetChildRecursive((UIElement *)v1, 0x10000696u);
  if ( v20 )
    v21 = v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)3);
  else
    v21 = 0;
  v1->m_pTopBorder_Locked = (UIElement *)v21;
  v22 = UIElement::GetChildRecursive((UIElement *)v1, 0x10000698u);
  if ( v22 )
    v23 = v22->vfptr[12].OnAction((IInputActionCallback *)v22, (InputEvent *)3);
  else
    v23 = 0;
  v1->m_pLeftBorder_Locked = (UIElement *)v23;
  v24 = UIElement::GetChildRecursive((UIElement *)v1, 0x1000069Au);
  if ( v24 )
    v25 = v24->vfptr[12].OnAction((IInputActionCallback *)v24, (InputEvent *)3);
  else
    v25 = 0;
  v1->m_pBottomBorder_Locked = (UIElement *)v25;
  v26 = UIElement::GetChildRecursive((UIElement *)v1, 0x10000693u);
  if ( v26 )
    v27 = v26->vfptr[12].OnAction((IInputActionCallback *)v26, (InputEvent *)3);
  else
    v27 = 0;
  v1->m_pRightBorder_Locked = (UIElement *)v27;
  v28 = UIElement::GetChildRecursive((UIElement *)v1, 0x10000695u);
  if ( v28 )
    v29 = v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)3);
  else
    v29 = 0;
  v1->m_pTopLeftCorner_Locked = (UIElement *)v29;
  v30 = UIElement::GetChildRecursive((UIElement *)v1, 0x10000697u);
  if ( v30 )
    v31 = v30->vfptr[12].OnAction((IInputActionCallback *)v30, (InputEvent *)3);
  else
    v31 = 0;
  v1->m_pTopRightCorner_Locked = (UIElement *)v31;
  v32 = UIElement::GetChildRecursive((UIElement *)v1, 0x10000699u);
  if ( v32 )
    v33 = v32->vfptr[12].OnAction((IInputActionCallback *)v32, (InputEvent *)3);
  else
    v33 = 0;
  v1->m_pBottomLeftCorner_Locked = (UIElement *)v33;
  gmMainChatUI::PostInit((gmMainChatUI *)&v1->vfptr);
  v34 = GlobalEventHandler::GetGlobalEventHandler();
  v35 = v34;
  if ( v34 )
  {
    v34->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v34,
      100022u,
      (NoticeHandler *)&v1[-1].m_pBottomRightCorner_Locked);
    v35->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v35,
      5100114u,
      (NoticeHandler *)&v1[-1].m_pBottomRightCorner_Locked);
    v35->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v35,
      5100135u,
      (NoticeHandler *)&v1[-1].m_pBottomRightCorner_Locked);
    v35->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v35,
      5100142u,
      (NoticeHandler *)&v1[-1].m_pBottomRightCorner_Locked);
    v35->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v35,
      (unsigned int)&loc_4DD1F0,
      (NoticeHandler *)&v1[-1].m_pBottomRightCorner_Locked);
  }
  UIListener::RegisterForGlobalMessage((UIListener *)v1, 1u);
  UIListener::RegisterForGlobalMessage((UIListener *)v1, 0xDu);
}

//----- (004D2940) --------------------------------------------------------  // acclient.c:258827
void __thiscall gmFloatyMainChatUI::ListenToGlobalMessage(gmFloatyMainChatUI *this, unsigned int i_messageID, int i_data_int)
{
  gmMainChatUI *v3; // esi@1

  v3 = (gmMainChatUI *)this;
  if ( i_messageID == 13 )
    gmFloatyMainChatUI::UpdateLockedStatus((gmFloatyMainChatUI *)((char *)this - 4));
  gmMainChatUI::ListenToGlobalMessage(v3, i_messageID, i_data_int);
}

//----- (004D2970) --------------------------------------------------------  // acclient.c:258838
void __thiscall gmFloatyMainChatUI::UpdateFromPlayerModule(gmFloatyMainChatUI *this)
{
  gmFloatyMainChatUI *v1; // esi@1
  PlayerModule *v2; // edi@1
  unsigned int v3; // ST14_4@12
  unsigned int v4; // ST14_4@19
  BasePropertyDesc *v5; // ecx@32
  unsigned int v6; // edx@32
  BasePropertyValue *v7; // ecx@36
  unsigned int v8; // edx@36
  int w; // [sp+2Ch] [bp-30h]@3
  unsigned int bVis; // [sp+30h] [bp-2Ch]@15
  BaseProperty prop; // [sp+34h] [bp-28h]@1
  BaseProperty propH; // [sp+3Ch] [bp-20h]@19
  BaseProperty propW; // [sp+44h] [bp-18h]@19
  BaseProperty propY; // [sp+4Ch] [bp-10h]@12
  BaseProperty propX; // [sp+54h] [bp-8h]@12

  v1 = this;
  v2 = (PlayerModule *)&CPlayerSystem::GetPlayerSystem()->playerModule.vfptr;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( PlayerModule::InqOption(v2, 0x10000080u, &prop)
    && prop.m_pcPropertyValue
    && (unsigned __int8)((int (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[34].__vecDelDtor)(&w) )
    ChatInterface::SetDefaultOpacity((ChatInterface *)&v1->vfptr, *(float *)&w);
  if ( PlayerModule::InqOption(v2, 0x10000081u, &prop)
    && prop.m_pcPropertyValue
    && (unsigned __int8)((int (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[34].__vecDelDtor)(&w) )
    ChatInterface::SetActiveOpacity((ChatInterface *)&v1->vfptr, *(float *)&w);
  if ( v1->m_eWindowID && CPlayerSystem::GetPlayerSystem() )
  {
    if ( !CPlayerSystem::GetPlayerSystem()->m_layoutFromFile )
    {
      v3 = v1->m_eWindowID;
      propX.m_pcPropertyDesc = 0;
      propX.m_pcPropertyValue = 0;
      propY.m_pcPropertyDesc = 0;
      propY.m_pcPropertyValue = 0;
      if ( PlayerModule::InqChatWindowOption(v2, v3, 0x10000086u, &propX)
        && PlayerModule::InqChatWindowOption(v2, v1->m_eWindowID, 0x10000087u, &propY)
        && propX.m_pcPropertyValue
        && (unsigned __int8)((int (__stdcall *)(_DWORD))propX.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&bVis)
        && propY.m_pcPropertyValue
        && (unsigned __int8)((int (__stdcall *)(_DWORD))propY.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&w) )
        ((void (__thiscall *)(int, int, int))v1->vfptr[3].OnLoseFocus)(&v1->vfptr, bVis, w);
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
        && (unsigned __int8)((int (__stdcall *)(_DWORD))propH.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&bVis) )
        ((void (__thiscall *)(int, int, int))v1->vfptr[4].__vecDelDtor)(&v1->vfptr, w, bVis);
      BaseProperty::~BaseProperty(&propH);
      BaseProperty::~BaseProperty(&propW);
      BaseProperty::~BaseProperty(&propY);
      BaseProperty::~BaseProperty(&propX);
    }
    if ( PlayerModule::InqChatWindowOption(v2, v1->m_eWindowID, 0x1000008Au, &prop)
      && prop.m_pcPropertyValue
      && (unsigned __int8)((int (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[28].__vecDelDtor)(&bVis) )
      v1->vfptr[2].__vecDelDtor((IInputActionCallback *)&v1->vfptr, bVis);
  }
  ChatInterface::UpdateFromPlayerModule((ChatInterface *)&v1->vfptr);
  gmFloatyMainChatUI::UpdateLockedStatus(v1);
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

//----- (004D2C00) --------------------------------------------------------  // acclient.c:258928
void __userpurge gmFloatyMainChatUI::ResizeTo(gmFloatyMainChatUI *this@<ecx>, int a2@<edi>, const int i_width, const int i_height)
{
  gmFloatyMainChatUI *v4; // esi@1
  char *v5; // edi@4
  int v6; // ebp@4
  PlayerModule *v7; // edi@6
  int v8; // ebp@6
  BaseProperty propH; // [sp+8h] [bp-10h]@6
  BaseProperty propW; // [sp+10h] [bp-8h]@4

  v4 = this;
  gmMainChatUI::ResizeTo((gmMainChatUI *)&this->vfptr, a2, i_width, i_height);
  if ( !LOBYTE(v4->m_pChatTargetButtonText) && v4->m_oldState && CPlayerSystem::GetPlayerSystem() )
  {
    v5 = (char *)&CPlayerSystem::GetPlayerSystem()->playerModule;
    propW.m_pcPropertyDesc = 0;
    propW.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propW, 0x10000088u);
    v6 = UIRegion::GetWidth((UIRegion *)v4);
    if ( propW.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propW);
      ((void (__stdcall *)(_DWORD))propW.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v6);
    }
    v7 = (PlayerModule *)(v5 + 4);
    PlayerModule::SetChatWindowOption(v7, v4->m_oldState, &propW);
    propH.m_pcPropertyDesc = 0;
    propH.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propH, 0x10000089u);
    v8 = UIRegion::GetHeight((UIRegion *)v4);
    if ( propH.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propH);
      ((void (__stdcall *)(_DWORD))propH.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v8);
    }
    PlayerModule::SetChatWindowOption(v7, v4->m_oldState, &propH);
    BaseProperty::~BaseProperty(&propH);
    BaseProperty::~BaseProperty(&propW);
  }
}

//----- (004D2D10) --------------------------------------------------------  // acclient.c:258970
void __thiscall gmFloatyMainChatUI::MoveTo(gmFloatyMainChatUI *this, const int i_x, const int i_y)
{
  int v3; // ebp@1
  gmFloatyMainChatUI *v4; // esi@1
  int v5; // edi@1
  char v6; // bl@1
  UIRegion *v7; // eax@2
  int v8; // ebx@2
  UIRegion *v9; // eax@3
  int v10; // ebp@3
  UIRegion *v11; // eax@6
  int v12; // ebx@6
  UIRegion *v13; // eax@7
  int v14; // edi@7
  char *v15; // edi@13
  unsigned int v16; // ebp@13
  PlayerModule *v17; // edi@15
  int v18; // ebp@15
  BaseProperty propY; // [sp+10h] [bp-10h]@15
  BaseProperty propX; // [sp+18h] [bp-8h]@13

  v3 = i_x;
  v4 = this;
  v5 = i_y;
  v6 = 0;
  if ( ((int (*)(void))this->vfptr[1].RecvNotice_DisplayWeenieError)() )
  {
    v7 = (UIRegion *)((int (__thiscall *)(gmFloatyMainChatUI *))v4->vfptr[1].RecvNotice_DisplayWeenieError)(v4);
    v8 = UIRegion::GetWidth(v7);
    if ( i_x > v8 - UIRegion::GetWidth((UIRegion *)v4) )
    {
      v9 = (UIRegion *)((int (__thiscall *)(gmFloatyMainChatUI *))v4->vfptr[1].RecvNotice_DisplayWeenieError)(v4);
      v10 = UIRegion::GetWidth(v9);
      v3 = v10 - UIRegion::GetWidth((UIRegion *)v4);
    }
    if ( v3 < 0 )
      v3 = 0;
    v11 = (UIRegion *)((int (__thiscall *)(gmFloatyMainChatUI *))v4->vfptr[1].RecvNotice_DisplayWeenieError)(v4);
    v12 = UIRegion::GetHeight(v11);
    if ( i_y > v12 - UIRegion::GetHeight((UIRegion *)v4) )
    {
      v13 = (UIRegion *)((int (__thiscall *)(_DWORD))v4->vfptr[1].RecvNotice_DisplayWeenieError)(v4);
      v14 = UIRegion::GetHeight(v13);
      v5 = v14 - UIRegion::GetHeight((UIRegion *)v4);
    }
    v6 = 0;
    if ( v5 < 0 )
      v5 = 0;
  }
  gmMainChatUI::MoveTo((gmMainChatUI *)&v4->vfptr, v3, v5);
  if ( LOBYTE(v4->m_pChatTargetButtonText) == v6 && v4->m_oldState && CPlayerSystem::GetPlayerSystem() )
  {
    v15 = (char *)&CPlayerSystem::GetPlayerSystem()->playerModule;
    propX.m_pcPropertyDesc = 0;
    propX.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propX, 0x10000086u);
    v16 = v4->m_tsSerialNumberLastListenedTo.m_timestamp;
    if ( propX.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propX);
      ((void (__stdcall *)(unsigned int))propX.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v16);
    }
    v17 = (PlayerModule *)(v15 + 4);
    PlayerModule::SetChatWindowOption(v17, v4->m_oldState, &propX);
    propY.m_pcPropertyDesc = 0;
    propY.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propY, 0x10000087u);
    v18 = v4->m_box.m_x0;
    if ( propY.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propY);
      ((void (__stdcall *)(int))propY.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v18);
    }
    PlayerModule::SetChatWindowOption(v17, v4->m_oldState, &propY);
    BaseProperty::~BaseProperty(&propY);
    BaseProperty::~BaseProperty(&propX);
  }
}

//----- (006F4230) --------------------------------------------------------  // acclient.c:776762
void sub_6F4230()
{
  outside_val_94 = 1000.0 + 1.0;
}

//----- (006F4250) --------------------------------------------------------  // acclient.c:776768
void _E93_78()
{
  block_length_94 = 24.0 * 8.0;
}

//----- (006F4270) --------------------------------------------------------  // acclient.c:776774
void _E95_78()
{
  half_square_length_94 = 24.0 * 0.5;
}

//----- (006F4290) --------------------------------------------------------  // acclient.c:776780
int sub_6F4290()
{
  return atexit(nullsub_676);
}

//----- (006F42A0) --------------------------------------------------------  // acclient.c:776786
int _E100_96()
{
  return atexit(nullsub_677);
}

//----- (006F42B0) --------------------------------------------------------  // acclient.c:776792
int _E103_88()
{
  return atexit(nullsub_678);
}

//----- (006F42C0) --------------------------------------------------------  // acclient.c:776798
void _E106_61()
{
  DEFAULT_VIEW_RADIUS_63 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F42E0) --------------------------------------------------------  // acclient.c:776804
void _E108_48()
{
  MIN_QUANTUM_63 = 1.0 / 30.0;
}

//----- (006F4300) --------------------------------------------------------  // acclient.c:776810
void _E110_39()
{
  MAX_QUANTUM_63 = 1.0 / 5.0;
}

//----- (006F4320) --------------------------------------------------------  // acclient.c:776816
void _E112_55()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_98, PFID_A8R8G8B8);
}

//----- (006F4330) --------------------------------------------------------  // acclient.c:776822
int _E117_40()
{
  return atexit(nullsub_674);
}

//----- (006F4340) --------------------------------------------------------  // acclient.c:776828
int sub_6F4340()
{
  return atexit(nullsub_675);
}

