/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmFloatyIndicatorsUI
   Object     : GAME\game_ui_misc\gmFloatyIndicatorsUI.obj
   Functions  : 26
   Addresses  : 004D2EB0 - 006F4460 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004D2EB0) --------------------------------------------------------  // acclient.c:259050
void __userpurge gmFloatyIndicatorsUI::gmFloatyIndicatorsUI(gmFloatyIndicatorsUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFloatyIndicatorsUI *v4; // esi@1

  v4 = this;
  gmIndicatorsUI::gmIndicatorsUI((gmIndicatorsUI *)&this->vfptr, a2, _layout, _full_desc);
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
  v4->vfptr = (IInputActionCallbackVtbl *)&gmFloatyIndicatorsUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmFloatyIndicatorsUI::vftable;
}
// 7BB9F8: using guessed type bool (__thiscall *gmFloatyIndicatorsUI::vftable)(DBCache *this);
// 7BBCA0: using guessed type int (__thiscall *gmFloatyIndicatorsUI::vftable)(void *, char);

//----- (004D2F50) --------------------------------------------------------  // acclient.c:259080
gmFloatyIndicatorsUI *__thiscall gmFloatyIndicatorsUI::DynamicCast(gmFloatyIndicatorsUI *this, unsigned int i_eType)
{
  gmFloatyIndicatorsUI *result; // eax@1

  result = this;
  if ( i_eType != 268435538 && i_eType != 268435466 )
    result = (gmFloatyIndicatorsUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004D2F80) --------------------------------------------------------  // acclient.c:259091
signed int gmFloatyIndicatorsUI::GetUIElementType()
{
  return 268435538;
}

//----- (004D2F90) --------------------------------------------------------  // acclient.c:259097
void __usercall gmFloatyIndicatorsUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFloatyIndicatorsUI *v3; // eax@1

  v3 = (gmFloatyIndicatorsUI *)operator new(0x640u);
  if ( v3 )
    gmFloatyIndicatorsUI::gmFloatyIndicatorsUI(v3, a1, _layout, _full_desc);
}

//----- (004D2FC0) --------------------------------------------------------  // acclient.c:259107
int __thiscall gmFloatyIndicatorsUI::ListenToElementMessage(gmFloatyIndicatorsUI *this, UIElementMessageInfo *i_rMsg)
{
  gmIndicatorsUI *v2; // edi@1

  v2 = (gmIndicatorsUI *)this;
  if ( i_rMsg->idMessage == 1 && i_rMsg->idElement == 268435706 )
    CM_UI::SendNotice_EndCharacterSession(1);
  return gmIndicatorsUI::ListenToElementMessage(v2, i_rMsg);
}

//----- (004D2FF0) --------------------------------------------------------  // acclient.c:259118
void __thiscall gmFloatyIndicatorsUI::UpdateLockedStatus(gmFloatyIndicatorsUI *this)
{
  gmFloatyIndicatorsUI *v1; // esi@1
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

//----- (004D31C0) --------------------------------------------------------  // acclient.c:259172
gmFloatyIndicatorsUI *__thiscall gmFloatyIndicatorsUI::vector_deleting_destructor(gmFloatyIndicatorsUI *this, unsigned int a2)
{
  gmFloatyIndicatorsUI *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&gmFloatyIndicatorsUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmFloatyIndicatorsUI::vftable;
  gmIndicatorsUI::~gmIndicatorsUI((gmIndicatorsUI *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7BB9F8: using guessed type bool (__thiscall *gmFloatyIndicatorsUI::vftable)(DBCache *this);
// 7BBCA0: using guessed type int (__thiscall *gmFloatyIndicatorsUI::vftable)(void *, char);

//----- (004D31F0) --------------------------------------------------------  // acclient.c:259188
void __cdecl gmFloatyIndicatorsUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000052u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmFloatyIndicatorsUI::Create);
}

//----- (004D3210) --------------------------------------------------------  // acclient.c:259196
void __thiscall gmFloatyIndicatorsUI::PostInit(gmFloatyIndicatorsUI *this)
{
  gmFloatyIndicatorsUI *v1; // esi@1
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

  v1 = this;
  gmGameplayOptionsUI::PostInit((gmGameplayOptionsUI *)this);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000064Cu);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)2);
  else
    v3 = 0;
  v1->m_pTopBorder = (UIElement *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000064Eu);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)2);
  else
    v5 = 0;
  v1->m_pLeftBorder = (UIElement *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000650u);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)2);
  else
    v7 = 0;
  v1->m_pBottomBorder = (UIElement *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000652u);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)2);
  else
    v9 = 0;
  v1->m_pRightBorder = (UIElement *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000064Bu);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)2);
  else
    v11 = 0;
  v1->m_pTopLeftCorner = (UIElement *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000064Du);
  if ( v12 )
    v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)2);
  else
    v13 = 0;
  v1->m_pTopRightCorner = (UIElement *)v13;
  v14 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000064Fu);
  if ( v14 )
    v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)2);
  else
    v15 = 0;
  v1->m_pBottomLeftCorner = (UIElement *)v15;
  v16 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000651u);
  if ( v16 )
    v17 = v16->vfptr[12].OnAction((IInputActionCallback *)v16, (InputEvent *)2);
  else
    v17 = 0;
  v1->m_pBottomRightCorner = (UIElement *)v17;
  v18 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000644u);
  if ( v18 )
    v19 = v18->vfptr[12].OnAction((IInputActionCallback *)v18, (InputEvent *)3);
  else
    v19 = 0;
  v1->m_pTopBorder_Locked = (UIElement *)v19;
  v20 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000646u);
  if ( v20 )
    v21 = v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)3);
  else
    v21 = 0;
  v1->m_pLeftBorder_Locked = (UIElement *)v21;
  v22 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000648u);
  if ( v22 )
    v23 = v22->vfptr[12].OnAction((IInputActionCallback *)v22, (InputEvent *)3);
  else
    v23 = 0;
  v1->m_pBottomBorder_Locked = (UIElement *)v23;
  v24 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000064Au);
  if ( v24 )
    v25 = v24->vfptr[12].OnAction((IInputActionCallback *)v24, (InputEvent *)3);
  else
    v25 = 0;
  v1->m_pRightBorder_Locked = (UIElement *)v25;
  v26 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000643u);
  if ( v26 )
    v27 = v26->vfptr[12].OnAction((IInputActionCallback *)v26, (InputEvent *)3);
  else
    v27 = 0;
  v1->m_pTopLeftCorner_Locked = (UIElement *)v27;
  v28 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000645u);
  if ( v28 )
    v29 = v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)3);
  else
    v29 = 0;
  v1->m_pTopRightCorner_Locked = (UIElement *)v29;
  v30 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000647u);
  if ( v30 )
    v31 = v30->vfptr[12].OnAction((IInputActionCallback *)v30, (InputEvent *)3);
  else
    v31 = 0;
  v1->m_pBottomLeftCorner_Locked = (UIElement *)v31;
  v32 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000649u);
  if ( v32 )
    v33 = v32->vfptr[12].OnAction((IInputActionCallback *)v32, (InputEvent *)3);
  else
    v33 = 0;
  v1->m_pBottomRightCorner_Locked = (UIElement *)v33;
  UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x1000007Eu, &v1->m_eWindowID);
  v34 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v34 )
    v34->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v34, (unsigned int)&loc_4DD1F0, (NoticeHandler *)&v1->vfptr);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 0xDu);
  ((void (__thiscall *)(gmFloatyIndicatorsUI *))v1->vfptr[26].__vecDelDtor)(v1);
}

//----- (004D34C0) --------------------------------------------------------  // acclient.c:259340
void __thiscall gmFloatyIndicatorsUI::ListenToGlobalMessage(gmFloatyIndicatorsUI *this, unsigned int i_messageID, int i_data_int)
{
  PlayerModule *v3; // esi@1

  v3 = (PlayerModule *)this;
  if ( i_messageID == 13 )
    gmFloatyIndicatorsUI::UpdateLockedStatus(this);
  gmPanelUI::ListenToGlobalMessage(v3, (BaseProperty *)i_messageID, i_data_int);
}

//----- (004D34F0) --------------------------------------------------------  // acclient.c:259351
void __thiscall gmFloatyIndicatorsUI::UpdateFromPlayerModule(gmFloatyIndicatorsUI *this)
{
  gmFloatyIndicatorsUI *v1; // esi@1
  PlayerModule *v2; // edi@1
  unsigned int v3; // ST14_4@10
  unsigned int v4; // ST14_4@17
  BasePropertyDesc *v5; // ecx@30
  unsigned int v6; // edx@30
  BasePropertyValue *v7; // ecx@34
  unsigned int v8; // edx@34
  int w; // [sp+2Ch] [bp-30h]@15
  unsigned int bVis; // [sp+30h] [bp-2Ch]@3
  BaseProperty prop; // [sp+34h] [bp-28h]@1
  BaseProperty propH; // [sp+3Ch] [bp-20h]@17
  BaseProperty propW; // [sp+44h] [bp-18h]@17
  BaseProperty propY; // [sp+4Ch] [bp-10h]@10
  BaseProperty propX; // [sp+54h] [bp-8h]@10

  v1 = this;
  v2 = (PlayerModule *)&CPlayerSystem::GetPlayerSystem()->playerModule.vfptr;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( PlayerModule::InqOption(v2, 0x10000080u, &prop) && prop.m_pcPropertyValue )
    ((void (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[34].__vecDelDtor)(&bVis);
  if ( PlayerModule::InqOption(v2, 0x10000081u, &prop) && prop.m_pcPropertyValue )
    ((void (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[34].__vecDelDtor)(&bVis);
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
        ((void (__thiscall *)(gmFloatyIndicatorsUI *, int, int))v1->vfptr[3].OnLoseFocus)(v1, bVis, w);
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
        ((void (__thiscall *)(gmFloatyIndicatorsUI *, int, int))v1->vfptr[4].__vecDelDtor)(v1, w, bVis);
      BaseProperty::~BaseProperty(&propH);
      BaseProperty::~BaseProperty(&propW);
      BaseProperty::~BaseProperty(&propY);
      BaseProperty::~BaseProperty(&propX);
    }
    if ( PlayerModule::InqChatWindowOption(v2, v1->m_eWindowID, 0x1000008Au, &prop)
      && prop.m_pcPropertyValue
      && (unsigned __int8)((int (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[28].__vecDelDtor)(&bVis) )
      v1->vfptr[2].__vecDelDtor((IInputActionCallback *)v1, bVis);
  }
  gmFloatyIndicatorsUI::UpdateLockedStatus(v1);
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

//----- (004D3750) --------------------------------------------------------  // acclient.c:259436
void __userpurge gmFloatyIndicatorsUI::ResizeTo(gmFloatyIndicatorsUI *this@<ecx>, int a2@<edi>, const int i_width, const int i_height)
{
  gmFloatyIndicatorsUI *v4; // esi@1
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

//----- (004D38C0) --------------------------------------------------------  // acclient.c:259519
void __thiscall gmFloatyIndicatorsUI::MoveTo(gmFloatyIndicatorsUI *this, const int i_x, const int i_y)
{
  int v3; // ebx@1
  gmFloatyIndicatorsUI *v4; // esi@1
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
    v6 = (UIRegion *)((int (__thiscall *)(gmFloatyIndicatorsUI *))v4->vfptr[13].OnAction)(v4);
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

//----- (004D3AC0) --------------------------------------------------------  // acclient.c:259637
void __thiscall gmFloatyIndicatorsUI::SetVisible(gmFloatyIndicatorsUI *this, int i_fVisible)
{
  gmFloatyIndicatorsUI *v2; // edi@1
  char *v3; // esi@3
  BasePropertyDesc *v4; // ecx@6
  unsigned int v5; // edx@6
  BasePropertyValue *v6; // ecx@10
  unsigned int v7; // edx@10
  BaseProperty prop; // [sp+8h] [bp-8h]@3

  v2 = this;
  UIElement::SetVisible((UIElement *)&this->vfptr, i_fVisible);
  if ( v2->m_eWindowID && CPlayerSystem::GetPlayerSystem() )
  {
    v3 = (char *)&CPlayerSystem::GetPlayerSystem()->playerModule;
    prop.m_pcPropertyDesc = 0;
    prop.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&prop, 0x1000008Au);
    LOBYTE(i_fVisible) = (*((_DWORD *)&v2->0 + 41) >> 1) & 1;
    if ( prop.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&prop);
      ((void (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[29].__vecDelDtor)(i_fVisible);
    }
    PlayerModule::SetChatWindowOption((PlayerModule *)(v3 + 4), v2->m_eWindowID, &prop);
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

//----- (006F4350) --------------------------------------------------------  // acclient.c:776834
void sub_6F4350()
{
  outside_val_95 = 1000.0 + 1.0;
}

//----- (006F4370) --------------------------------------------------------  // acclient.c:776840
void _E93_79()
{
  block_length_95 = 24.0 * 8.0;
}

//----- (006F4390) --------------------------------------------------------  // acclient.c:776846
void _E95_79()
{
  half_square_length_95 = 24.0 * 0.5;
}

//----- (006F43B0) --------------------------------------------------------  // acclient.c:776852
int sub_6F43B0()
{
  return atexit(nullsub_671);
}

//----- (006F43C0) --------------------------------------------------------  // acclient.c:776858
int _E100_97()
{
  return atexit(nullsub_672);
}

//----- (006F43D0) --------------------------------------------------------  // acclient.c:776864
int _E103_89()
{
  return atexit(nullsub_673);
}

//----- (006F43E0) --------------------------------------------------------  // acclient.c:776870
void _E106_62()
{
  DEFAULT_VIEW_RADIUS_64 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F4400) --------------------------------------------------------  // acclient.c:776876
void _E108_49()
{
  MIN_QUANTUM_64 = 1.0 / 30.0;
}

//----- (006F4420) --------------------------------------------------------  // acclient.c:776882
void _E110_40()
{
  MAX_QUANTUM_64 = 1.0 / 5.0;
}

//----- (006F4440) --------------------------------------------------------  // acclient.c:776888
void _E112_56()
{
  PixelFormatDesc::PixelFormatDesc(&stru_83FEE8, PFID_A8R8G8B8);
}

//----- (006F4450) --------------------------------------------------------  // acclient.c:776894
int _E117_41()
{
  return atexit(nullsub_669);
}

//----- (006F4460) --------------------------------------------------------  // acclient.c:776900
int sub_6F4460()
{
  return atexit(nullsub_670);
}

