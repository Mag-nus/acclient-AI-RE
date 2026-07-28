/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmFloatyChatUI
   Object     : GAME\game_ui_misc\gmFloatyChatUI.obj
   Functions  : 26
   Addresses  : 004CE280 - 006F3C80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004CE280) --------------------------------------------------------  // acclient.c:255293
signed int __thiscall gmFloatyChatUI::DynamicCast(gmFloatyChatUI *this, unsigned int i_eType)
{
  signed int result; // eax@2

  if ( i_eType == 268435520 )
    result = this != (gmFloatyChatUI *)4 ? (unsigned int)this : 0;
  else
    result = i_eType != 3 ? 0 : (unsigned int)this;
  return result;
}

//----- (004CE2B0) --------------------------------------------------------  // acclient.c:255305
signed int gmFloatyChatUI::GetUIElementType()
{
  return 268435520;
}

//----- (004CE2C0) --------------------------------------------------------  // acclient.c:255311
UIElement *__cdecl gmFloatyChatUI::Create(LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v2; // esi@1
  UIElement *result; // eax@2

  v2 = operator new(0x638u);
  if ( v2 )
  {
    ChatInterface::ChatInterface((ChatInterface *)v2, _layout, _full_desc);
    result = (UIElement *)((char *)v2 + 4);
    *(_DWORD *)v2 = &gmFloatyChatUI::vftable;
    *((_DWORD *)v2 + 1) = &gmFloatyChatUI::vftable;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7B9AA8: using guessed type int (__thiscall *gmFloatyChatUI::vftable)(ChatInterface *this, char);
// 7B9BE0: using guessed type bool (__thiscall *gmFloatyChatUI::vftable)(DBCache *this);

//----- (004CE300) --------------------------------------------------------  // acclient.c:255334
void __thiscall gmFloatyChatUI::PostInit(gmFloatyChatUI *this)
{
  ChatInterface *v1; // esi@1
  GlobalEventHandler *v2; // eax@1

  v1 = (ChatInterface *)this;
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 5100144u, (NoticeHandler *)&v1[-1].m_pCCS);
  ChatInterface::PostInit(v1);
}

//----- (004CE330) --------------------------------------------------------  // acclient.c:255347
UIElementMessageListenResult __thiscall gmFloatyChatUI::ListenToElementMessage(gmFloatyChatUI *this, UIElementMessageInfo *i_rMsg)
{
  ChatInterface *v2; // esi@1

  v2 = (ChatInterface *)this;
  if ( i_rMsg->idMessage == 1 && i_rMsg->idElement == 268436778 )
    ((void (__stdcall *)(_DWORD))this->vfptr->RecvNotice_ServerSaysMoveItem)(0);
  return ChatInterface::ListenToElementMessage(v2, i_rMsg);
}

//----- (004CE360) --------------------------------------------------------  // acclient.c:255358
void __thiscall gmFloatyChatUI::RecvNotice_SetChatWindowTitle(gmFloatyChatUI *this, unsigned int i_idWindow, StringInfo *i_siTitle)
{
  if ( i_idWindow == this->m_eWindowID )
    ((void (__stdcall *)(_DWORD))this->vfptr[7].RecvNotice_RuntimeDDDStatus)(i_siTitle);
}

//----- (004CE380) --------------------------------------------------------  // acclient.c:255365
char *__thiscall gmFloatyChatUI::vector_deleting_destructor(ChatInterface *this, char a2)
{
  ChatInterface *v2; // edi@1
  char *v3; // esi@1
  GlobalEventHandler *v4; // eax@1

  v2 = this;
  v3 = (char *)&this[-1].m_pCCS;
  this[-1].m_pCCS = (ClientCommunicationSystem *)&gmFloatyChatUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmFloatyChatUI::vftable;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, (NoticeHandler *)v3);
  ChatInterface::~ChatInterface(v2);
  if ( a2 & 1 )
    operator delete(v3);
  return v3;
}
// 7B9AA8: using guessed type int (__thiscall *gmFloatyChatUI::vftable)(ChatInterface *this, char);
// 7B9BE0: using guessed type bool (__thiscall *gmFloatyChatUI::vftable)(DBCache *this);

//----- (004CE3D0) --------------------------------------------------------  // acclient.c:255387
void __cdecl gmFloatyChatUI::Register()
{
  UIElement::RegisterElementClass(0x10000040u, gmFloatyChatUI::Create);
}

//----- (004CE3F0) --------------------------------------------------------  // acclient.c:255393
void __thiscall gmFloatyChatUI::UpdateFromPlayerModule(gmFloatyChatUI *this)
{
  gmFloatyChatUI *v1; // esi@1
  PlayerModule *v2; // edi@1
  unsigned int v3; // ST20_4@12
  unsigned int v4; // ST20_4@19
  BasePropertyDesc *v5; // ecx@37
  unsigned int v6; // edx@37
  BasePropertyValue *v7; // ecx@41
  unsigned int v8; // edx@41
  int w; // [sp+38h] [bp-C0h]@3
  BaseProperty prop; // [sp+3Ch] [bp-BCh]@1
  unsigned int bVis; // [sp+44h] [bp-B4h]@15
  BaseProperty propH; // [sp+48h] [bp-B0h]@19
  BaseProperty propY; // [sp+50h] [bp-A8h]@12
  BaseProperty propX; // [sp+58h] [bp-A0h]@12
  BaseProperty propW; // [sp+60h] [bp-98h]@19
  StringInfo siTitle; // [sp+68h] [bp-90h]@32

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
    if ( PlayerModule::InqChatWindowOption(v2, v1->m_eWindowID, 0x1000008Du, &prop) )
    {
      StringInfo::StringInfo(&siTitle);
      if ( prop.m_pcPropertyValue
        && (unsigned __int8)((int (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[48].__vecDelDtor)(&siTitle) )
        ((void (__thiscall *)(gmFloatyChatUI *, StringInfo *))v1->vfptr[7].RecvNotice_RuntimeDDDStatus)(v1, &siTitle);
      StringInfo::~StringInfo(&siTitle);
    }
  }
  ChatInterface::UpdateFromPlayerModule((ChatInterface *)&v1->vfptr);
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

//----- (004CE6D0) --------------------------------------------------------  // acclient.c:255491
void __userpurge gmFloatyChatUI::ResizeTo(gmFloatyChatUI *this@<ecx>, int a2@<edi>, const int i_width, const int i_height)
{
  gmFloatyChatUI *v4; // esi@1
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
  ChatInterface::ResizeTo((ChatInterface *)&this->vfptr, a2, i_width, i_height);
  if ( v4->m_oldState && CPlayerSystem::GetPlayerSystem() )
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

//----- (004CE840) --------------------------------------------------------  // acclient.c:255574
void __thiscall gmFloatyChatUI::MoveTo(gmFloatyChatUI *this, const int i_x, const int i_y)
{
  gmFloatyChatUI *v3; // esi@1
  char *v4; // edi@3
  unsigned int v5; // ebx@3
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
  BaseProperty propY; // [sp+Ch] [bp-10h]@5
  BaseProperty propX; // [sp+14h] [bp-8h]@3

  v3 = this;
  UIElement::MoveTo((UIElement *)this, i_x, i_y);
  if ( v3->m_oldState && CPlayerSystem::GetPlayerSystem() )
  {
    v4 = (char *)&CPlayerSystem::GetPlayerSystem()->playerModule;
    propX.m_pcPropertyDesc = 0;
    propX.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propX, 0x10000086u);
    v5 = v3->m_tsSerialNumberLastListenedTo.m_timestamp;
    if ( propX.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propX);
      ((void (__stdcall *)(_DWORD))propX.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v5);
    }
    v6 = (PlayerModule *)(v4 + 4);
    PlayerModule::SetChatWindowOption(v6, v3->m_oldState, &propX);
    propY.m_pcPropertyDesc = 0;
    propY.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propY, 0x10000087u);
    v7 = v3->m_box.m_x0;
    if ( propY.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&propY);
      ((void (__stdcall *)(_DWORD))propY.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v7);
    }
    PlayerModule::SetChatWindowOption(v6, v3->m_oldState, &propY);
    if ( (_DWORD)propY.m_pcPropertyDesc )
    {
      v8 = propY.m_pcPropertyDesc;
      v9 = propY.m_pcPropertyDesc->m_cRef - 1;
      propY.m_pcPropertyDesc->m_cRef = v9;
      if ( !v9 )
        ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
      propY.m_pcPropertyDesc = 0;
    }
    if ( propY.m_pcPropertyValue )
    {
      v10 = propY.m_pcPropertyValue;
      v11 = propY.m_pcPropertyValue->m_cRef - 1;
      propY.m_pcPropertyValue->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
      propY.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)propX.m_pcPropertyDesc )
    {
      v12 = propX.m_pcPropertyDesc;
      v13 = propX.m_pcPropertyDesc->m_cRef - 1;
      propX.m_pcPropertyDesc->m_cRef = v13;
      if ( !v13 )
        ((void (__stdcall *)(_DWORD))v12->vfptr->__vecDelDtor)(1);
      propX.m_pcPropertyDesc = 0;
    }
    if ( propX.m_pcPropertyValue )
    {
      v14 = propX.m_pcPropertyValue;
      v15 = propX.m_pcPropertyValue->m_cRef - 1;
      propX.m_pcPropertyValue->m_cRef = v15;
      if ( !v15 )
        ((void (__stdcall *)(_DWORD))v14->vfptr->__vecDelDtor)(1);
    }
  }
}

//----- (004CE9B0) --------------------------------------------------------  // acclient.c:255657
void __thiscall gmFloatyChatUI::SetVisible(gmFloatyChatUI *this, int i_fVisible)
{
  gmFloatyChatUI *v2; // edi@1
  char *v3; // esi@3
  BasePropertyDesc *v4; // ecx@6
  unsigned int v5; // edx@6
  BasePropertyValue *v6; // ecx@10
  unsigned int v7; // edx@10
  BaseProperty prop; // [sp+8h] [bp-8h]@3

  v2 = this;
  UIElement::SetVisible((UIElement *)this, i_fVisible);
  if ( v2->m_oldState && CPlayerSystem::GetPlayerSystem() )
  {
    v3 = (char *)&CPlayerSystem::GetPlayerSystem()->playerModule;
    prop.m_pcPropertyDesc = 0;
    prop.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&prop, 0x1000008Au);
    LOBYTE(i_fVisible) = (LODWORD(v2->m_alphaBlendMod) >> 1) & 1;
    if ( prop.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&prop);
      ((void (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[29].__vecDelDtor)(i_fVisible);
    }
    PlayerModule::SetChatWindowOption((PlayerModule *)(v3 + 4), v2->m_oldState, &prop);
    if ( (_DWORD)prop.m_pcPropertyDesc )
    {
      v4 = prop.m_pcPropertyDesc;
      v5 = prop.m_pcPropertyDesc->m_cRef - 1;
      prop.m_pcPropertyDesc->m_cRef = v5;
      if ( !v5 )
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      prop.m_pcPropertyDesc = 0;
    }
    if ( prop.m_pcPropertyValue )
    {
      v6 = prop.m_pcPropertyValue;
      v7 = prop.m_pcPropertyValue->m_cRef - 1;
      prop.m_pcPropertyValue->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
    }
  }
}

//----- (004CEAA0) --------------------------------------------------------  // acclient.c:255703
BOOL __thiscall gmFloatyChatUI::SetWindowTitle(gmFloatyChatUI *this, StringInfo *i_siTitle)
{
  gmFloatyChatUI *v2; // edi@1
  UIElement *v3; // eax@1
  StringInfo *v4; // ebx@1
  UIElement_Text *v5; // eax@2
  char *v6; // esi@6
  BasePropertyDesc *v7; // ecx@9
  unsigned int v8; // edx@9
  BasePropertyValue *v9; // ecx@13
  unsigned int v10; // edx@13
  BaseProperty prop; // [sp+Ch] [bp-8h]@6
  StringInfo *i_siTitlea; // [sp+18h] [bp+4h]@2

  v2 = this;
  v3 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x100004D9u);
  v4 = i_siTitle;
  if ( v3 )
  {
    v5 = (UIElement_Text *)v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
    i_siTitlea = (StringInfo *)v5;
    if ( v5 )
      UIElement_Text::SetStringInfo(v5, v4);
  }
  else
  {
    i_siTitlea = 0;
  }
  if ( v2->m_eWindowID && CPlayerSystem::GetPlayerSystem() )
  {
    v6 = (char *)&CPlayerSystem::GetPlayerSystem()->playerModule;
    prop.m_pcPropertyDesc = 0;
    prop.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&prop, 0x1000008Du);
    if ( prop.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&prop);
      ((void (__stdcall *)(StringInfo *))prop.m_pcPropertyValue->vfptr[49].__vecDelDtor)(v4);
    }
    PlayerModule::SetChatWindowOption((PlayerModule *)(v6 + 4), v2->m_eWindowID, &prop);
    if ( (_DWORD)prop.m_pcPropertyDesc )
    {
      v7 = prop.m_pcPropertyDesc;
      v8 = prop.m_pcPropertyDesc->m_cRef - 1;
      prop.m_pcPropertyDesc->m_cRef = v8;
      if ( !v8 )
        ((void (__stdcall *)(signed int))v7->vfptr->__vecDelDtor)(1);
      prop.m_pcPropertyDesc = 0;
    }
    if ( prop.m_pcPropertyValue )
    {
      v9 = prop.m_pcPropertyValue;
      v10 = prop.m_pcPropertyValue->m_cRef - 1;
      prop.m_pcPropertyValue->m_cRef = v10;
      if ( !v10 )
        ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
    }
  }
  return i_siTitlea != 0;
}

//----- (004D25A0) --------------------------------------------------------  // acclient.c:258603
void __thiscall gmFloatyChatUI::RecvNotice_GameplayOptionChanged(gmFloatyChatUI *this, BaseProperty *i_prop, unsigned int i_dwUserData)
{
  BaseProperty *v3; // esi@1
  ChatInterface *v4; // edi@1
  char *v5; // eax@1
  BasePropertyValue *v6; // ecx@4
  BasePropertyValue *v7; // ecx@7

  v3 = i_prop;
  v4 = (ChatInterface *)this;
  v5 = (char *)&BaseProperty::GetPropertyName(i_prop)[-1315861].m_availableProperties.m_reqHash.m_intrusiveTable.m_aInplaceBuckets[2];
  if ( v5 )
  {
    if ( v5 == (char *)1 )
    {
      v6 = v3->m_pcPropertyValue;
      if ( v6 )
      {
        if ( (unsigned __int8)((int (__stdcall *)(BaseProperty **))v6->vfptr[34].__vecDelDtor)(&i_prop) )
          ChatInterface::SetActiveOpacity(v4, *(float *)&i_prop);
      }
    }
    else
    {
      ChatInterface::RecvNotice_GameplayOptionChanged(v4, v3, i_dwUserData);
    }
  }
  else
  {
    v7 = v3->m_pcPropertyValue;
    if ( v7 && (unsigned __int8)((int (__stdcall *)(BaseProperty **))v7->vfptr[34].__vecDelDtor)(&i_prop) )
      ChatInterface::SetDefaultOpacity(v4, *(float *)&i_prop);
  }
}

//----- (006F3B70) --------------------------------------------------------  // acclient.c:776330
void _E91_96()
{
  outside_val_88 = 1000.0 + 1.0;
}

//----- (006F3B90) --------------------------------------------------------  // acclient.c:776336
void _E93_72()
{
  block_length_88 = 24.0 * 8.0;
}

//----- (006F3BB0) --------------------------------------------------------  // acclient.c:776342
void _E95_72()
{
  half_square_length_88 = 24.0 * 0.5;
}

//----- (006F3BD0) --------------------------------------------------------  // acclient.c:776348
int _E97_97()
{
  return atexit(nullsub_716);
}

//----- (006F3BE0) --------------------------------------------------------  // acclient.c:776354
int _E100_90()
{
  return atexit(nullsub_717);
}

//----- (006F3BF0) --------------------------------------------------------  // acclient.c:776360
int _E103_82()
{
  return atexit(_E104_97);
}

//----- (006F3C00) --------------------------------------------------------  // acclient.c:776366
void _E106_55()
{
  DEFAULT_VIEW_RADIUS_57 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F3C20) --------------------------------------------------------  // acclient.c:776372
void _E108_42()
{
  MIN_QUANTUM_57 = 1.0 / 30.0;
}

//----- (006F3C40) --------------------------------------------------------  // acclient.c:776378
void _E110_33()
{
  MAX_QUANTUM_57 = 1.0 / 5.0;
}

//----- (006F3C60) --------------------------------------------------------  // acclient.c:776384
void _E112_49()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_92, PFID_A8R8G8B8);
}

//----- (006F3C70) --------------------------------------------------------  // acclient.c:776390
int _E114_30()
{
  return atexit(nullsub_714);
}

//----- (006F3C80) --------------------------------------------------------  // acclient.c:776396
int sub_6F3C80()
{
  return atexit(nullsub_715);
}

