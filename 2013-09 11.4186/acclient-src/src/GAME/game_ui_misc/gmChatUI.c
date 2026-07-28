/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmChatUI
   Object     : GAME\game_ui_misc\gmChatUI.obj
   Functions  : 90
   Addresses  : 004CCCC0 - 00761980 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004CCCC0) --------------------------------------------------------  // acclient.c:254156
void __thiscall gmMainChatUI::MoveTo(gmMainChatUI *this, const int _x, const int _y)
{
  UIRegion *v3; // esi@1
  unsigned int v4; // edi@1
  unsigned int v5; // ebp@1
  unsigned int v6; // ebx@1
  const int v7; // eax@3
  const int v8; // eax@8
  unsigned int _xa; // [sp+14h] [bp+4h]@1

  v3 = (UIRegion *)this;
  v4 = UIRegion::GetScreenX0((UIRegion *)this);
  v5 = UIRegion::GetScreenY0(v3);
  UIElement::MoveTo((UIElement *)v3, _x, _y);
  v6 = UIRegion::GetScreenX0(v3);
  _xa = UIRegion::GetScreenY0(v3);
  if ( v4 != v6 )
  {
    _y = 0;
    if ( UIElement::GetAttribute_Int((UIElement *)v3, 0x54u, (int *)&_y) )
    {
      v7 = _y;
    }
    else
    {
      v7 = 0;
      _y = 0;
    }
    UIElement::SetAttribute_Int((UIElement *)v3, 0x54u, v6 + v7 - v4);
  }
  if ( v5 != _xa )
  {
    _y = 0;
    if ( UIElement::GetAttribute_Int((UIElement *)v3, 0x55u, (int *)&_y) )
    {
      v8 = _y;
    }
    else
    {
      v8 = 0;
      _y = 0;
    }
    UIElement::SetAttribute_Int((UIElement *)v3, 0x55u, _xa + v8 - v5);
  }
}

//----- (004CCD80) --------------------------------------------------------  // acclient.c:254203
void __thiscall gmMainChatUI::RecvNotice_SetPanelVisibility(gmMainChatUI *this, unsigned int i_ePanelID, bool i_bVisible)
{
  unsigned int v3; // eax@2
  UIElement *v4; // ecx@6

  switch ( i_ePanelID )
  {
    case 0x10000505u:
      v3 = 268436770;
      goto LABEL_6;
    case 0x1000050Eu:
      v3 = 268436771;
      goto LABEL_6;
    case 0x1000050Fu:
      v3 = 268436772;
      goto LABEL_6;
    case 0x10000510u:
      v3 = 268436773;
LABEL_6:
      v4 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, v3);
      if ( v4 )
      {
        if ( i_bVisible )
          ((void (__stdcall *)(signed int))v4->vfptr[13].__vecDelDtor)(6);
        else
          ((void (__stdcall *)(signed int))v4->vfptr[13].__vecDelDtor)(1);
      }
      break;
    default:
      return;
  }
}

//----- (004CCE10) --------------------------------------------------------  // acclient.c:254237
void __thiscall gmMainChatUI::RecvNotice_TextTag_IIDStringClick(gmMainChatUI *this, unsigned int i_eType, unsigned int i_iid, PStringBase<unsigned short> *i_strValue)
{
  ChatInterface *v4; // esi@1

  v4 = (ChatInterface *)this;
  if ( i_eType == 268435457 && !ChatInterface::IsTextEntryFocused((ChatInterface *)&this->vfptr) )
    ChatInterface::StartTell(v4, i_strValue);
}

//----- (004CCE50) --------------------------------------------------------  // acclient.c:254247
void __usercall gmMainChatUI::HandleMaximizeButton(gmMainChatUI *this@<ecx>, InputEvent *a2@<ebp>)
{
  gmMainChatUI *v2; // edi@1
  UIRegion *v3; // esi@1
  UIRegion *v4; // eax@4
  int v5; // ebx@4
  int v6; // eax@4
  int v7; // ebp@4
  UIRegion *v8; // eax@4
  int v9; // eax@4
  bool v10; // sf@4
  unsigned __int8 v11; // of@4
  IInputActionCallbackVtbl *v12; // eax@4
  UIRegion *v13; // eax@4
  int v14; // ebp@4
  int v15; // eax@4
  int v16; // eax@6
  int v17; // ebp@6
  UIRegion *v18; // eax@15
  int v19; // eax@15
  UIRegion *v20; // eax@16
  int v21; // eax@16
  int v22; // ecx@17
  IInputActionCallbackVtbl *v23; // ebx@17
  int v24; // ST04_4@17
  int v25; // eax@17
  int v26; // eax@18
  int v27; // ecx@18
  UIRegion *v28; // eax@20
  int v29; // eax@20
  UIRegion *v30; // eax@21
  IInputActionCallbackVtbl *v31; // ebx@22
  int v32; // eax@22
  int nMinHeight; // [sp+Ch] [bp-18h]@1
  int expandedHeight; // [sp+10h] [bp-14h]@9
  int nMaxHeight; // [sp+14h] [bp-10h]@1
  UIElement *pMaximizeButton; // [sp+18h] [bp-Ch]@1
  int v37; // [sp+1Ch] [bp-8h]@17
  int expandDown; // [sp+20h] [bp-4h]@4
  void *retaddr; // [sp+24h] [bp+0h]@4

  v2 = this;
  v3 = (UIRegion *)&this->vfptr;
  nMaxHeight = 0;
  nMinHeight = 0;
  pMaximizeButton = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x1000046Fu);
  if ( pMaximizeButton
    && UIElement::GetAttribute_Int((UIElement *)v3, 0x3Cu, &nMaxHeight)
    && UIElement::GetAttribute_Int((UIElement *)v3, 0x3Eu, &nMinHeight) )
  {
    v4 = (UIRegion *)v3->vfptr[13].OnAction((IInputActionCallback *)v3, a2);
    v5 = UIRegion::GetHeight(v4) / 2;
    v6 = UIRegion::GetHeight(v3);
    v7 = v2->m_box.m_y0;
    nMaxHeight = v5 + v6;
    v8 = (UIRegion *)((int (__thiscall *)(UIRegion *))v3->vfptr[13].OnAction)(v3);
    v9 = UIRegion::GetHeight(v8) / 2;
    v11 = __OFSUB__(v7, v9);
    v10 = v7 - v9 < 0;
    v12 = v3->vfptr;
    expandDown = v2->m_box.m_y0;
    retaddr = (void *)(unsigned __int8)(v10 ^ v11);
    v13 = (UIRegion *)((int (__thiscall *)(UIRegion *))v12[13].OnAction)(v3);
    v14 = UIRegion::GetHeight(v13);
    v15 = UIRegion::GetHeight(v3);
    if ( expandDown + v15 < v14 && retaddr )
    {
      v16 = v2->m_box.m_y0;
      v17 = v2->m_box.m_y0;
    }
    else
    {
      v16 = v2->m_box.m_y0;
      v17 = v2->m_box.m_y0 - v5;
    }
    if ( v2->m_Maximized )
    {
      if ( v2->m_OldHeight < expandedHeight )
        v2->m_OldHeight = expandedHeight;
      if ( v2->m_OldHeight > (signed int)pMaximizeButton )
        v2->m_OldHeight = (int)pMaximizeButton;
      if ( v2->m_OldY < 0 )
        v2->m_OldY = 0;
      v18 = (UIRegion *)((int (__thiscall *)(UIRegion *))v3->vfptr[13].OnAction)(v3);
      v19 = UIRegion::GetHeight(v18);
      if ( v2->m_OldY > v19 - expandedHeight )
      {
        v20 = (UIRegion *)((int (__thiscall *)(UIRegion *))v3->vfptr[13].OnAction)(v3);
        v21 = UIRegion::GetHeight(v20);
        v2->m_OldY = v21 - expandedHeight;
      }
      v22 = v37;
      v2->m_Maximized = 0;
      (*(void (__cdecl **)(signed int))(*(_DWORD *)v22 + 156))(268435528);
      v23 = v3->vfptr;
      v24 = v2->m_OldHeight;
      v25 = UIRegion::GetWidth(v3);
      ((void (__thiscall *)(UIRegion *, int, int))v23[4].__vecDelDtor)(v3, v25, v24);
      ((void (__thiscall *)(UIRegion *, int, int))v3->vfptr[3].OnLoseFocus)(v3, v2->m_box.m_x0, v2->m_OldY);
    }
    else
    {
      v2->m_OldY = v16;
      v26 = UIRegion::GetHeight(v3);
      v27 = v37;
      v2->m_OldHeight = v26;
      v2->m_Maximized = 1;
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v27 + 156))(268435527);
      if ( v17 < 0 )
        v17 = 0;
      v28 = (UIRegion *)((int (__thiscall *)(_DWORD))v3->vfptr[13].OnAction)(v3);
      v29 = UIRegion::GetHeight(v28);
      if ( v17 + nMaxHeight > v29 )
      {
        v30 = (UIRegion *)((int (__thiscall *)(_DWORD))v3->vfptr[13].OnAction)(v3);
        nMaxHeight = UIRegion::GetHeight(v30) - v17;
      }
      v31 = v3->vfptr;
      v32 = UIRegion::GetWidth(v3);
      v31[4].__vecDelDtor((IInputActionCallback *)v3, v32);
      ((void (__thiscall *)(UIRegion *, int, int))v3->vfptr[3].OnLoseFocus)(v3, v2->m_box.m_x0, v17);
    }
  }
}

//----- (004CD0A0) --------------------------------------------------------  // acclient.c:254373
void __userpurge gmMainChatUI::ResizeTo(gmMainChatUI *this@<ecx>, int a2@<edi>, const int i_cWidth, const int i_cHeight)
{
  gmMainChatUI *v4; // esi@1
  UIElement_Text *v5; // ecx@1
  bool v6; // bl@1

  v4 = this;
  v5 = this->m_chatEntry;
  v6 = 0;
  if ( v5 )
    v6 = UIElement_Text::IsAtVerticalEnd(v5);
  ChatInterface::ResizeTo((ChatInterface *)&v4->vfptr, a2, i_cWidth, i_cHeight);
  if ( v6 )
    UIElement_Text::ScrollToPosition(v4->m_chatEntry, v4->m_chatEntry->m_glyphList.m_glyphList._num_elements);
}

//----- (004CD0F0) --------------------------------------------------------  // acclient.c:254390
void __thiscall gmMainChatUI::gmMainChatUI(gmMainChatUI *this, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmMainChatUI *v3; // esi@1

  v3 = this;
  ChatInterface::ChatInterface((ChatInterface *)&this->vfptr, _layout, _full_desc);
  v3->m_pSquelchToggleButton = 0;
  v3->vfptr = (NoticeHandlerVtbl *)&gmMainChatUI::vftable;
  v3->vfptr = (IInputActionCallbackVtbl *)&gmMainChatUI::vftable;
  v3->m_aTalkFocusButtons.m_data = 0;
  v3->m_aTalkFocusButtons.m_sizeAndDeallocate = 0;
  v3->m_aTalkFocusButtons.m_num = 0;
  v3->m_pChatTargetButtonText = 0;
  v3->m_Maximized = 0;
  v3->m_OldY = 0;
  v3->m_OldHeight = 0;
  LODWORD(v3->m_fDefaultOpacity) = 1065353216;
  LODWORD(v3->m_fCurrentOpacity) = 1065353216;
}
// 7B9280: using guessed type int (__stdcall *gmMainChatUI::vftable)(char);
// 7B93B8: using guessed type bool (__thiscall *gmMainChatUI::vftable)(DBCache *this);

//----- (004CD160) --------------------------------------------------------  // acclient.c:254413
signed int __thiscall gmMainChatUI::DynamicCast(gmMainChatUI *this, unsigned int i_eType)
{
  signed int result; // eax@2

  if ( i_eType == 268435521 )
    result = this != (gmMainChatUI *)4 ? (unsigned int)this : 0;
  else
    result = i_eType != 3 ? 0 : (unsigned int)this;
  return result;
}

//----- (004CD190) --------------------------------------------------------  // acclient.c:254425
signed int gmMainChatUI::GetUIElementType()
{
  return 268435521;
}

//----- (004CD1A0) --------------------------------------------------------  // acclient.c:254431
void __thiscall gmMainChatUI::~gmMainChatUI(gmMainChatUI *this)
{
  gmMainChatUI *v1; // esi@1
  char *v2; // edi@1
  GlobalEventHandler *v3; // eax@1

  v1 = this;
  v2 = (char *)&this[-1].m_OldHeight;
  this[-1].m_OldHeight = (int)&gmMainChatUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmMainChatUI::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)this, 3u);
  UIListener::UnRegisterForGlobalMessage((UIListener *)v1, 0xBu);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, (NoticeHandler *)v2);
  if ( ((unsigned int)v1->m_aTalkFocusButtons.m_data & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_pSquelchToggleButton);
  ChatInterface::~ChatInterface((ChatInterface *)&v1->vfptr);
}
// 7B9280: using guessed type int (__stdcall *gmMainChatUI::vftable)(char);
// 7B93B8: using guessed type bool (__thiscall *gmMainChatUI::vftable)(DBCache *this);

//----- (004CD200) --------------------------------------------------------  // acclient.c:254454
UIElement *__cdecl gmMainChatUI::Create(LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmMainChatUI *v2; // eax@1
  int v3; // eax@2
  UIElement *result; // eax@3

  v2 = (gmMainChatUI *)operator new(0x658u);
  if ( v2 && (gmMainChatUI::gmMainChatUI(v2, _layout, _full_desc), v3) )
    result = (UIElement *)(v3 + 4);
  else
    result = 0;
  return result;
}

//----- (004CD230) --------------------------------------------------------  // acclient.c:254469
void __thiscall gmMainChatUI::ToggleSquelchOnCurrentSpeakableTarget(gmMainChatUI *this)
{
  unsigned int v1; // eax@1
  const unsigned int v2; // esi@1
  HashBaseData<unsigned long> *v3; // eax@2
  int v4; // ebx@3
  AC1Legacy::PSRefBuffer<char> *v5; // edi@3
  AC1Legacy::PSRefBuffer<char> *v6; // esi@9
  int v7; // [sp-18h] [bp-2Ch]@7
  unsigned int v8; // [sp-14h] [bp-28h]@7
  AC1Legacy::PStringBase<char> *v9; // [sp-10h] [bp-24h]@7
  AC1Legacy::PStringBase<char> name; // [sp+8h] [bp-Ch]@3
  AC1Legacy::PStringBase<char> account_name; // [sp+Ch] [bp-8h]@3
  gmMainChatUI *v12; // [sp+10h] [bp-4h]@1

  v12 = this;
  v1 = gmCCommunicationSystem::GetLastSpeakableTarget();
  v2 = v1;
  if ( v1 )
  {
    v3 = ClientObjMaintSystem::GetWeenieObject(v1);
    if ( v3 )
    {
      name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)v3[13].vfptr;
      InterlockedIncrement((volatile LONG *)&name.m_buffer->m_cRef);
      AC1Legacy::PStringBase<char>::PStringBase<char>(&account_name, &::name);
      v4 = gmCCommunicationSystem::IsSquelched(v2, &account_name, 1u);
      v5 = account_name.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&account_name.m_buffer->m_cRef) && v5 )
        v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
      if ( v4 )
      {
        ((void (__stdcall *)(signed int))v12->m_pSquelchToggleButton->vfptr[13].__vecDelDtor)(1);
        v9 = &name;
        v8 = v2;
        v7 = 0;
      }
      else
      {
        ((void (__stdcall *)(signed int))v12->m_pSquelchToggleButton->vfptr[13].__vecDelDtor)(268435457);
        v9 = &name;
        v8 = v2;
        v7 = 1;
      }
      CM_Communication::Event_ModifyCharacterSquelch(v7, v8, v9, 1u);
      v6 = name.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&name.m_buffer->m_cRef) )
      {
        if ( v6 )
          v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
      }
    }
  }
}

//----- (004CD320) --------------------------------------------------------  // acclient.c:254525
int __thiscall gmMainChatUI::vector_deleting_destructor(gmMainChatUI *this, char a2)
{
  gmMainChatUI *v2; // esi@1
  int result; // eax@1

  v2 = this;
  gmMainChatUI::~gmMainChatUI(this);
  result = (int)&v2[-1].m_OldHeight;
  if ( a2 & 1 )
  {
    operator delete(&v2[-1].m_OldHeight);
    result = (int)&v2[-1].m_OldHeight;
  }
  return result;
}

//----- (004CD350) --------------------------------------------------------  // acclient.c:254542
void __cdecl gmMainChatUI::Register()
{
  UIElement::RegisterElementClass(0x10000041u, gmMainChatUI::Create);
}

//----- (004CD370) --------------------------------------------------------  // acclient.c:254548
UIElement *__thiscall gmMainChatUI::GetTalkFocusMenuItem(gmMainChatUI *this, unsigned int i_eFocus)
{
  gmMainChatUI *v2; // ebx@1
  unsigned int v3; // edi@1
  unsigned int v4; // ebp@2
  UIElement *v5; // esi@3
  UIElement *result; // eax@6

  v2 = this;
  v3 = 0;
  if ( this->m_aTalkFocusButtons.m_num )
  {
    v4 = i_eFocus;
    while ( 1 )
    {
      v5 = (UIElement *)&v2->m_aTalkFocusButtons.m_data[v3]->vfptr;
      if ( v5 )
      {
        UIElement::GetAttribute_Enum(v5, 0x1000000Bu, &i_eFocus);
        if ( i_eFocus == v4 )
          break;
      }
      ++v3;
      if ( v3 >= v2->m_aTalkFocusButtons.m_num )
        goto LABEL_6;
    }
    result = v5;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (004CD3E0) --------------------------------------------------------  // acclient.c:254585
int __cdecl IsOlthoi()
{
  InterfaceSystem *v0; // eax@1
  Interface *v1; // edi@1
  int v2; // ebx@3
  PlayerDesc *v3; // edi@5
  int v5; // [sp-8h] [bp-2Ch]@1
  Interface *_rpInterface; // [sp+Ch] [bp-18h]@1
  unsigned int heritage; // [sp+10h] [bp-14h]@1
  TResult result; // [sp+14h] [bp-10h]@1
  char v9; // [sp+18h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> spPD; // [sp+1Ch] [bp-8h]@1

  heritage = 0;
  _rpInterface = 0;
  v0 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v0, &result, &PlayerDesc_ClassType_16, &_rpInterface);
  v1 = _rpInterface;
  v5 = (int)_rpInterface;
  spPD.m_pInterface = 0;
  spPD.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v2 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPD, (int)&v9, v5, 0);
  if ( v1 )
    v1->vfptr->Release(v1);
  v3 = spPD.m_pInterface;
  if ( (_DWORD)spPD.m_pInterface )
  {
    if ( v2 >= 0 )
    {
      CBaseQualities::InqInt((CBaseQualities *)&spPD.m_pInterface->vfptr, 0xBCu, (int *)&heritage, 0, 0);
      if ( heritage == 12 || heritage == 13 )
      {
        v3->vfptr->Release((Interface *)v3);
        return 1;
      }
    }
    v3->vfptr->Release((Interface *)v3);
  }
  return 0;
}

//----- (004CD4A0) --------------------------------------------------------  // acclient.c:254629
void __thiscall gmMainChatUI::ResetAllTalkFocusMenuButtons(gmMainChatUI *this)
{
  gmMainChatUI *v1; // ebx@1
  unsigned int v2; // edi@1
  UIElement *v3; // esi@2
  signed int v4; // ST04_4@9
  unsigned int v5; // eax@11
  unsigned int eFocus; // [sp+0h] [bp-4h]@1

  eFocus = (unsigned int)this;
  v1 = this;
  v2 = 0;
  if ( this->m_aTalkFocusButtons.m_num )
  {
    do
    {
      v3 = (UIElement *)&v1->m_aTalkFocusButtons.m_data[v2]->vfptr;
      if ( v3 )
      {
        UIElement::GetAttribute_Enum(v3, 0x1000000Bu, &eFocus);
        if ( eFocus )
        {
          if ( IsOlthoi() )
          {
            if ( eFocus == 13 || eFocus == 1 )
              v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 1u);
            else
              v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 13u);
          }
          else
          {
            v4 = gmCCommunicationSystem::IsTalkFocusEnabled(eFocus) != 0 ? 1 : 13;
            v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, v4);
          }
        }
      }
      ++v2;
    }
    while ( v2 < v1->m_aTalkFocusButtons.m_num );
  }
  v5 = gmCCommunicationSystem::GetLastSpeakableTarget();
  gmMainChatUI::SetSelected(v1, v5);
}

//----- (004CD540) --------------------------------------------------------  // acclient.c:254674
void __thiscall gmMainChatUI::HandleSelection(gmMainChatUI *this, unsigned int i_eFocus)
{
  gmMainChatUI *v2; // edi@1
  UIElement *v3; // eax@1
  UIElement *v4; // esi@1
  unsigned int v5; // eax@4
  StringInfo _info; // [sp+Ch] [bp-90h]@3

  v2 = this;
  v3 = gmMainChatUI::GetTalkFocusMenuItem(this, i_eFocus);
  v4 = v3;
  if ( v3 && v3->m_state != 13 )
  {
    StringInfo::StringInfo(&_info);
    StringInfo::SetTableEnum(&_info, 268435457);
    switch ( i_eFocus )
    {
      case 2u:
        gmCCommunicationSystem::SetTalkFocus(2u);
        v5 = ID_Chat_ChatTargetMenuSelected;
        goto LABEL_17;
      case 1u:
        gmCCommunicationSystem::SetTalkFocus(1u);
        _info.m_stringID = ID_Chat_ChatTargetMenu;
        goto LABEL_18;
      case 3u:
        gmCCommunicationSystem::SetTalkFocus(3u);
        _info.m_stringID = ID_Chat_ChatTargetMenuFellows;
        goto LABEL_18;
      case 4u:
        gmCCommunicationSystem::SetTalkFocus(4u);
        v5 = ID_Chat_ChatTargetMenuPatron;
        goto LABEL_17;
      case 5u:
        gmCCommunicationSystem::SetTalkFocus(5u);
        _info.m_stringID = ID_Chat_ChatTargetMenuMonarch;
        goto LABEL_18;
      case 6u:
        gmCCommunicationSystem::SetTalkFocus(6u);
        _info.m_stringID = ID_Chat_ChatTargetMenuVassals;
        goto LABEL_18;
      case 7u:
        gmCCommunicationSystem::SetWantsToBeInAllegChat(1);
        gmCCommunicationSystem::SetTalkFocus(7u);
        _info.m_stringID = ID_Chat_ChatTargetMenuAllegiance;
        goto LABEL_18;
      case 8u:
        gmCCommunicationSystem::SetTalkFocus(8u);
        _info.m_stringID = ID_Chat_ChatTargetMenuGeneral;
        goto LABEL_18;
      case 9u:
        gmCCommunicationSystem::SetTalkFocus(9u);
        _info.m_stringID = ID_Chat_ChatTargetMenuTrade;
        goto LABEL_18;
      case 0xAu:
        gmCCommunicationSystem::SetTalkFocus(0xAu);
        v5 = ID_Chat_ChatTargetMenuLFG;
        goto LABEL_17;
      case 0xBu:
        gmCCommunicationSystem::SetTalkFocus(0xBu);
        _info.m_stringID = ID_Chat_ChatTargetMenuRoleplay;
        goto LABEL_18;
      case 0xDu:
        gmCCommunicationSystem::SetTalkFocus(0xDu);
        _info.m_stringID = ID_Chat_ChatTargetMenuOlthoi;
        goto LABEL_18;
      case 0xCu:
        gmCCommunicationSystem::SetTalkFocus(0xCu);
        v5 = ID_Chat_ChatTargetMenuSociety;
LABEL_17:
        _info.m_stringID = v5;
LABEL_18:
        if ( v2->m_pChatTargetButtonText )
        {
          if ( StringInfo::IsValid(&_info, 1) )
            UIElement_Text::SetStringInfo(v2->m_pChatTargetButtonText, &_info);
        }
        gmMainChatUI::ResetAllTalkFocusMenuButtons(v2);
        v4->vfptr[13].__vecDelDtor((IInputActionCallback *)v4, 268435457u);
        break;
      default:
        break;
    }
    StringInfo::~StringInfo(&_info);
  }
}

//----- (004CD730) --------------------------------------------------------  // acclient.c:254762
void __thiscall gmMainChatUI::SetSelected(gmMainChatUI *this, unsigned int i_iidTarget)
{
  gmMainChatUI *v2; // ebx@1
  UIElement *v3; // eax@1
  PStringBase<unsigned short> v4; // esi@1
  volatile LONG *v5; // edi@1
  HashBaseData<unsigned long> *v6; // eax@1
  PStringBase<unsigned short> *v7; // eax@2
  bool v8; // zf@2
  int v9; // esi@3
  UIElement_Text *v10; // eax@10
  unsigned int v11; // edi@17
  int v12; // esi@18
  HashBaseData<unsigned long> *v13; // eax@27
  ITEM_TYPE v14; // eax@28
  int v15; // ebp@29
  UIElement_Text *pTellSelected; // [sp+10h] [bp-9Ch]@1
  unsigned __int16 *v17; // [sp+14h] [bp-98h]@2
  PStringBase<unsigned short> result; // [sp+18h] [bp-94h]@2
  StringInfo _info; // [sp+1Ch] [bp-90h]@12

  v2 = this;
  v3 = gmMainChatUI::GetTalkFocusMenuItem(this, 2u);
  v4.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v5 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  pTellSelected = (UIElement_Text *)v3;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v6 = ClientObjMaintSystem::GetWeenieObject(i_iidTarget);
  if ( v6 )
  {
    v7 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v6, &result, 0, 0);
    v8 = v4.m_charbuffer == v7->m_charbuffer;
    v17 = (unsigned __int16 *)v7;
    if ( !v8 )
    {
      v9 = (int)&v4.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      v4.m_charbuffer = *(PSRefBufferCharData<unsigned short> **)v17;
      v5 = (volatile LONG *)(*(_DWORD *)v17 - 16);
      InterlockedIncrement(v5);
    }
    v17 = &result.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v17 )
      (**(void (__stdcall ***)(_DWORD))v17)(1);
  }
  v10 = v2->m_pSquelchToggleButton;
  if ( *(_DWORD *)&v4.m_charbuffer[-1].m_data[14] == 1 )
  {
    if ( v10 )
    {
      StringInfo::StringInfo(&_info);
      StringInfo::SetStringIDandTableEnum(&_info, ID_Chat_SquelchSelected, 268435457);
      InterlockedIncrement(v5);
      StringInfo::AddVariable_String(&_info, VALUE_4, v4);
      UIElement_Text::SetStringInfo(v2->m_pSquelchToggleButton, &_info);
      ((void (__stdcall *)(signed int))v2->m_pSquelchToggleButton->vfptr[13].__vecDelDtor)(13);
      StringInfo::~StringInfo(&_info);
    }
    if ( pTellSelected )
    {
      StringInfo::StringInfo(&_info);
      StringInfo::SetStringIDandTableEnum(&_info, ID_Chat_TellToSelectedNoSelection, 268435457);
      UIElement_Text::SetStringInfo(pTellSelected, &_info);
      pTellSelected->vfptr[13].__vecDelDtor((IInputActionCallback *)pTellSelected, 13u);
      StringInfo::~StringInfo(&_info);
    }
    gmCCommunicationSystem::SetTalkFocusEnabled(2u, 0);
    if ( gmCCommunicationSystem::GetTalkFocus() == 2 )
      gmMainChatUI::HandleSelection(v2, 1u);
    v11 = i_iidTarget;
  }
  else
  {
    if ( v10 )
    {
      StringInfo::StringInfo(&_info);
      StringInfo::SetStringIDandTableEnum(&_info, ID_Chat_SquelchSelected, 268435457);
      InterlockedIncrement(v5);
      StringInfo::AddVariable_String(&_info, VALUE_4, v4);
      UIElement_Text::SetStringInfo(v2->m_pSquelchToggleButton, &_info);
      ((void (__stdcall *)(signed int))v2->m_pSquelchToggleButton->vfptr[13].__vecDelDtor)(1);
      StringInfo::~StringInfo(&_info);
    }
    if ( pTellSelected )
    {
      StringInfo::StringInfo(&_info);
      StringInfo::SetStringIDandTableEnum(&_info, ID_Chat_TellToSelected, 268435457);
      InterlockedIncrement(v5);
      StringInfo::AddVariable_String(&_info, VALUE_4, v4);
      UIElement_Text::SetStringInfo(pTellSelected, &_info);
      pTellSelected->vfptr[13].__vecDelDtor((IInputActionCallback *)pTellSelected, 1u);
      StringInfo::~StringInfo(&_info);
    }
    gmCCommunicationSystem::SetTalkFocusEnabled(2u, 1);
    v11 = i_iidTarget;
    if ( i_iidTarget )
    {
      v13 = ClientObjMaintSystem::GetWeenieObject(i_iidTarget);
      if ( v13 )
      {
        v14 = ((int (__thiscall *)(HashBaseData<unsigned long> *))v13->vfptr[6].__vecDelDtor)(v13);
        if ( PublicWeenieDesc::IsTalkable(v14) )
        {
          AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&pTellSelected, &name);
          v15 = gmCCommunicationSystem::IsSquelched(i_iidTarget, (AC1Legacy::PStringBase<char> *)&pTellSelected, 1u);
          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&pTellSelected);
          if ( v15 )
            v2->m_pSquelchToggleButton->vfptr[13].__vecDelDtor(
              (IInputActionCallback *)v2->m_pSquelchToggleButton,
              268435457u);
        }
      }
    }
  }
  gmCCommunicationSystem::SetLastSpeakableTarget(v11);
  v12 = (int)&v4.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v12 + 4)) )
  {
    if ( v12 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  }
}

//----- (004CDA40) --------------------------------------------------------  // acclient.c:254887
void __thiscall SmartArray<UIElement_Text *,1>::push_back(SmartArray<UIElement_Text *,1> *this, UIElement_Text *const *_v)
{
  SmartArray<UIElement_Text *,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v2, v4)) )
    v2->m_data[v2->m_num++] = *_v;
}

//----- (004CDA80) --------------------------------------------------------  // acclient.c:254902
UIElementMessageListenResult __userpurge gmMainChatUI::ListenToElementMessage@<eax>(gmMainChatUI *this@<ecx>, InputEvent *a2@<ebp>, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v3; // esi@1
  gmMainChatUI *v4; // edi@1
  UIElement_Menu *v5; // eax@3
  UIElement *v6; // ecx@5

  v3 = i_rMsg;
  v4 = this;
  if ( i_rMsg->idMessage == 1 )
  {
    if ( i_rMsg->idElement == 268436591 )
      gmMainChatUI::HandleMaximizeButton((gmMainChatUI *)((char *)this - 4), a2);
  }
  else if ( i_rMsg->idMessage == 7 )
  {
    v5 = (UIElement_Menu *)((int (__stdcall *)(signed int))i_rMsg->pElement->vfptr[12].OnAction)(6);
    if ( v5 )
      UIElement_Menu::SetSelectedItem(v5, 0, 0);
    v6 = (UIElement *)v3->dwParam2;
    if ( v6 )
    {
      if ( (ClientCommunicationSystem *)v6 == v4->m_pCCS )
      {
        gmMainChatUI::ToggleSquelchOnCurrentSpeakableTarget((gmMainChatUI *)((char *)v4 - 4));
        return ChatInterface::ListenToElementMessage((ChatInterface *)&v4->vfptr, v3);
      }
      if ( UIElement::GetAttribute_Enum(v6, 0x1000000Bu, (unsigned int *)&i_rMsg) )
      {
        gmMainChatUI::HandleSelection((gmMainChatUI *)((char *)v4 - 4), (unsigned int)i_rMsg);
        return ChatInterface::ListenToElementMessage((ChatInterface *)&v4->vfptr, v3);
      }
    }
  }
  return ChatInterface::ListenToElementMessage((ChatInterface *)&v4->vfptr, v3);
}

//----- (004CDB20) --------------------------------------------------------  // acclient.c:254940
void __thiscall gmMainChatUI::UseTime(gmMainChatUI *this)
{
  gmMainChatUI *v1; // ebx@1
  unsigned int v2; // edi@2
  unsigned int v3; // esi@3
  HashBaseData<unsigned long> *v4; // eax@3
  unsigned int v5; // edx@5
  ITEM_TYPE v6; // eax@8
  double _range; // ST08_8@9
  unsigned int v8; // eax@9
  HashBaseData<unsigned long> *v9; // eax@12
  HashBaseData<unsigned long> *v10; // esi@12
  unsigned int v11; // esi@14
  unsigned int v12; // esi@17
  double v13; // st7@19
  double curTime; // [sp+1Ch] [bp-8h]@1

  curTime = *(double *)&Timer::cur_time;
  v1 = this;
  if ( COERCE_DOUBLE(Timer::cur_time.Cmd) >= nextCheckChatSelectedTime )
  {
    v2 = gmCCommunicationSystem::GetLastSpeakableTarget();
    if ( !gmCCommunicationSystem::IsTalkFocusEnabled(2u) )
    {
      v3 = ACCWeenieObject::selectedID;
      v4 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
      if ( v4 )
      {
        if ( SmartBox::smartbox )
          v5 = SmartBox::smartbox->player_id;
        else
          v5 = 0;
        if ( v3 != v5 )
        {
          v6 = ((int (__thiscall *)(HashBaseData<unsigned long> *))v4->vfptr[6].__vecDelDtor)(v4);
          if ( PublicWeenieDesc::IsTalkable(v6) )
          {
            CPlayerSystem::GetPlayerSystem();
            _range = CPlayerSystem::GetRadarRadius();
            v8 = GetPlayerID();
            if ( ACCWeenieObject::ObjectsInRange(v3, v8, _range, 1, 0) )
              gmMainChatUI::SetSelected(v1, v3);
          }
        }
      }
      goto LABEL_21;
    }
    if ( v2 )
    {
      v9 = ClientObjMaintSystem::GetWeenieObject(v2);
      v10 = v9;
      if ( !v9 )
      {
LABEL_16:
        if ( SmartBox::smartbox )
          v12 = SmartBox::smartbox->player_id;
        else
          v12 = 0;
        CPlayerSystem::GetPlayerSystem();
        v13 = CPlayerSystem::GetRadarRadius();
        if ( !ACCWeenieObject::ObjectsInRange(v2, v12, v13, 1, 0) )
          gmMainChatUI::SetSelected(v1, 0);
        goto LABEL_21;
      }
      if ( !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v9) )
      {
        v11 = (unsigned int)v10[15].vfptr;
        if ( v11 )
          v2 = v11;
        goto LABEL_16;
      }
    }
LABEL_21:
    nextCheckChatSelectedTime = curTime + 1.0;
  }
}

//----- (004CDC50) --------------------------------------------------------  // acclient.c:255018
void __thiscall gmMainChatUI::InitTalkFocusMenu(gmMainChatUI *this)
{
  gmMainChatUI *v1; // ebx@1
  UIElement *v2; // eax@1
  UIElement_Menu *v3; // esi@2
  UIElement_Text *v4; // eax@3
  unsigned int v5; // ST00_4@3
  UIElement_Text *v6; // eax@3
  UIElement_Text *v7; // eax@5
  UIElement_Text *v8; // eax@7
  UIElement_Text *v9; // eax@9
  UIElement_Text *v10; // eax@11
  UIElement_Text *v11; // eax@13
  UIElement_Text *v12; // eax@15
  UIElement_Text *v13; // eax@17
  UIElement_Text *v14; // eax@19
  UIElement_Text *v15; // eax@21
  UIElement_Text *v16; // eax@23
  UIElement_Text *v17; // eax@25
  UIElement_Text *v18; // eax@27
  UIElement_Text *pItem; // [sp+4h] [bp-94h]@3
  StringInfo _text; // [sp+8h] [bp-90h]@3

  v1 = this;
  v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000014u);
  if ( v2 )
  {
    v3 = (UIElement_Menu *)v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)6);
    if ( v3 )
    {
      SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&v1->m_aTalkFocusButtons);
      UIElement_Menu::Flush(v3);
      StringInfo::StringInfo(&_text);
      StringInfo::SetStringIDandTableEnum(&_text, ID_Chat_SquelchSelectedNoSelection, 268435457);
      v4 = UIElement_Menu::AddTextItem(v3, &_text);
      v5 = ID_Chat_TellToMonarch;
      v1->m_pSquelchToggleButton = v4;
      StringInfo::SetStringIDandTableEnum(&_text, v5, 268435457);
      v6 = UIElement_Menu::AddTextItem(v3, &_text);
      pItem = v6;
      if ( v6 )
      {
        UIElement::SetAttribute_Enum((UIElement *)&v6->vfptr, 0x1000000Bu, 5u);
        SmartArray<UIElement_Text *,1>::push_back(&v1->m_aTalkFocusButtons, &pItem);
      }
      StringInfo::SetStringIDandTableEnum(&_text, ID_Chat_TellToSelectedNoSelection, 268435457);
      v7 = UIElement_Menu::AddTextItem(v3, &_text);
      pItem = v7;
      if ( v7 )
      {
        UIElement::SetAttribute_Enum((UIElement *)&v7->vfptr, 0x1000000Bu, 2u);
        SmartArray<UIElement_Text *,1>::push_back(&v1->m_aTalkFocusButtons, &pItem);
      }
      StringInfo::SetStringIDandTableEnum(&_text, ID_Chat_TellToPatron, 268435457);
      v8 = UIElement_Menu::AddTextItem(v3, &_text);
      pItem = v8;
      if ( v8 )
      {
        UIElement::SetAttribute_Enum((UIElement *)&v8->vfptr, 0x1000000Bu, 4u);
        SmartArray<UIElement_Text *,1>::push_back(&v1->m_aTalkFocusButtons, &pItem);
      }
      StringInfo::SetStringIDandTableEnum(&_text, ID_Chat_TellToAll, 268435457);
      v9 = UIElement_Menu::AddTextItem(v3, &_text);
      pItem = v9;
      if ( v9 )
      {
        UIElement::SetAttribute_Enum((UIElement *)&v9->vfptr, 0x1000000Bu, 1u);
        SmartArray<UIElement_Text *,1>::push_back(&v1->m_aTalkFocusButtons, &pItem);
      }
      StringInfo::SetStringIDandTableEnum(&_text, ID_Chat_TellToVassals, 268435457);
      v10 = UIElement_Menu::AddTextItem(v3, &_text);
      pItem = v10;
      if ( v10 )
      {
        UIElement::SetAttribute_Enum((UIElement *)&v10->vfptr, 0x1000000Bu, 6u);
        SmartArray<UIElement_Text *,1>::push_back(&v1->m_aTalkFocusButtons, &pItem);
      }
      StringInfo::SetStringIDandTableEnum(&_text, ID_Chat_TellToFellows, 268435457);
      v11 = UIElement_Menu::AddTextItem(v3, &_text);
      pItem = v11;
      if ( v11 )
      {
        UIElement::SetAttribute_Enum((UIElement *)&v11->vfptr, 0x1000000Bu, 3u);
        SmartArray<UIElement_Text *,1>::push_back(&v1->m_aTalkFocusButtons, &pItem);
      }
      StringInfo::SetStringIDandTableEnum(&_text, ID_Chat_TellToAllegiance, 268435457);
      v12 = UIElement_Menu::AddTextItem(v3, &_text);
      pItem = v12;
      if ( v12 )
      {
        UIElement::SetAttribute_Enum((UIElement *)&v12->vfptr, 0x1000000Bu, 7u);
        SmartArray<UIElement_Text *,1>::push_back(&v1->m_aTalkFocusButtons, &pItem);
      }
      StringInfo::SetStringIDandTableEnum(&_text, ID_Chat_TellToGeneral, 268435457);
      v13 = UIElement_Menu::AddTextItem(v3, &_text);
      pItem = v13;
      if ( v13 )
      {
        UIElement::SetAttribute_Enum((UIElement *)&v13->vfptr, 0x1000000Bu, 8u);
        SmartArray<UIElement_Text *,1>::push_back(&v1->m_aTalkFocusButtons, &pItem);
      }
      StringInfo::SetStringIDandTableEnum(&_text, ID_Chat_TellToTrade, 268435457);
      v14 = UIElement_Menu::AddTextItem(v3, &_text);
      pItem = v14;
      if ( v14 )
      {
        UIElement::SetAttribute_Enum((UIElement *)&v14->vfptr, 0x1000000Bu, 9u);
        SmartArray<UIElement_Text *,1>::push_back(&v1->m_aTalkFocusButtons, &pItem);
      }
      StringInfo::SetStringIDandTableEnum(&_text, ID_Chat_TellToLFG, 268435457);
      v15 = UIElement_Menu::AddTextItem(v3, &_text);
      pItem = v15;
      if ( v15 )
      {
        UIElement::SetAttribute_Enum((UIElement *)&v15->vfptr, 0x1000000Bu, 0xAu);
        SmartArray<UIElement_Text *,1>::push_back(&v1->m_aTalkFocusButtons, &pItem);
      }
      StringInfo::SetStringIDandTableEnum(&_text, ID_Chat_TellToRoleplay, 268435457);
      v16 = UIElement_Menu::AddTextItem(v3, &_text);
      pItem = v16;
      if ( v16 )
      {
        UIElement::SetAttribute_Enum((UIElement *)&v16->vfptr, 0x1000000Bu, 0xBu);
        SmartArray<UIElement_Text *,1>::push_back(&v1->m_aTalkFocusButtons, &pItem);
      }
      StringInfo::SetStringIDandTableEnum(&_text, ID_Chat_TellToSociety, 268435457);
      v17 = UIElement_Menu::AddTextItem(v3, &_text);
      pItem = v17;
      if ( v17 )
      {
        UIElement::SetAttribute_Enum((UIElement *)&v17->vfptr, 0x1000000Bu, 0xCu);
        SmartArray<UIElement_Text *,1>::push_back(&v1->m_aTalkFocusButtons, &pItem);
      }
      StringInfo::SetStringIDandTableEnum(&_text, ID_Chat_TellToOlthoi, 268435457);
      v18 = UIElement_Menu::AddTextItem(v3, &_text);
      pItem = v18;
      if ( v18 )
      {
        UIElement::SetAttribute_Enum((UIElement *)&v18->vfptr, 0x1000000Bu, 0xDu);
        SmartArray<UIElement_Text *,1>::push_back(&v1->m_aTalkFocusButtons, &pItem);
      }
      StringInfo::~StringInfo(&_text);
    }
  }
}

//----- (004CE050) --------------------------------------------------------  // acclient.c:255165
void __thiscall gmMainChatUI::RecvNotice_SelectionChanged(gmMainChatUI *this)
{
  unsigned int v1; // esi@1
  gmMainChatUI *v2; // edi@1
  HashBaseData<unsigned long> *v3; // eax@1
  ITEM_TYPE v4; // eax@2
  unsigned int v5; // eax@4

  v1 = ACCWeenieObject::selectedID;
  v2 = this;
  v3 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
  if ( v3 )
  {
    v4 = ((int (__thiscall *)(HashBaseData<unsigned long> *))v3->vfptr[6].__vecDelDtor)(v3);
    if ( PublicWeenieDesc::IsTalkable(v4) )
    {
      if ( SmartBox::smartbox )
        v5 = SmartBox::smartbox->player_id;
      else
        v5 = 0;
      if ( v1 != v5 )
        gmMainChatUI::SetSelected(v2, v1);
    }
  }
}

//----- (004CE0A0) --------------------------------------------------------  // acclient.c:255192
void __thiscall gmMainChatUI::EnableSelection(gmMainChatUI *this, unsigned int i_eFocus, bool i_bEnabled)
{
  gmMainChatUI *v3; // ebp@1
  UIElement *v4; // esi@1

  v3 = this;
  v4 = gmMainChatUI::GetTalkFocusMenuItem(this, i_eFocus);
  if ( v4 )
  {
    if ( IsOlthoi() && i_eFocus != 13 && i_eFocus != 1 && i_eFocus != 2 )
    {
      v4->vfptr[13].__vecDelDtor((IInputActionCallback *)v4, 13u);
    }
    else if ( i_bEnabled == (v4->m_state == 13) )
    {
      v4->vfptr[13].__vecDelDtor((IInputActionCallback *)v4, i_bEnabled != 0 ? 1 : 13);
      if ( !i_bEnabled && gmCCommunicationSystem::GetTalkFocus() == i_eFocus )
        gmMainChatUI::HandleSelection(v3, 1u);
    }
  }
}

//----- (004CE130) --------------------------------------------------------  // acclient.c:255215
void __thiscall gmMainChatUI::PostInit(gmMainChatUI *this)
{
  gmMainChatUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  CInputManager *v4; // edi@4
  gmMainChatUI *v5; // esi@4
  IInputActionCallback *v6; // eax@6
  int v7; // eax@9
  GlobalEventHandler *v8; // eax@12
  GlobalEventHandler *v9; // edi@12

  v1 = this;
  ChatInterface::PostInit((ChatInterface *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)v1, 0x10000015u);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)12);
  else
    v3 = 0;
  v1->m_aTalkFocusButtons.m_num = v3;
  UIListener::RegisterForGlobalMessage((UIListener *)v1, 3u);
  UIListener::RegisterForGlobalMessage((UIListener *)v1, 0xBu);
  v4 = ICIDM::s_cidm;
  v5 = (gmMainChatUI *)((char *)v1 - 4);
  if ( ICIDM::s_cidm )
  {
    if ( v5 )
      v6 = (IInputActionCallback *)&v5->vfptr;
    else
      v6 = 0;
    ICIDM::s_cidm->vfptr->RegisterInputMap((ICIDM *)ICIDM::s_cidm, 268435469u, v6, 3010);
    if ( v5 )
      v7 = (int)&v5->vfptr;
    else
      v7 = 0;
    v4->vfptr->RegisterInputMap((ICIDM *)v4, 268435466u, (IInputActionCallback *)v7, 1000);
  }
  v8 = GlobalEventHandler::GetGlobalEventHandler();
  v9 = v8;
  if ( v8 )
  {
    v8->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v8,
      (unsigned int)((char *)&loc_4DD1EE + 1),
      (NoticeHandler *)v5);
    v9->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v9, 5100113u, (NoticeHandler *)v5);
    v9->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v9,
      (unsigned int)((char *)&loc_4DD1F7 + 1),
      (NoticeHandler *)v5);
    v9->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v9, 100018u, (NoticeHandler *)v5);
    v9->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v9, 5100145u, (NoticeHandler *)v5);
  }
  gmMainChatUI::InitTalkFocusMenu(v5);
  gmMainChatUI::SetSelected(v5, 0);
  gmMainChatUI::HandleSelection(v5, 1u);
}

//----- (004CE220) --------------------------------------------------------  // acclient.c:255274
void __thiscall gmMainChatUI::ListenToGlobalMessage(gmMainChatUI *this, unsigned int i_messageID, int i_data_int)
{
  ChatInterface *v3; // esi@1

  v3 = (ChatInterface *)this;
  if ( i_messageID == 3 )
  {
    gmMainChatUI::UseTime((gmMainChatUI *)((char *)this - 4));
  }
  else if ( i_messageID != 11 )
  {
    ChatInterface::ListenToGlobalMessage((ChatInterface *)&this->vfptr, i_messageID, i_data_int);
    return;
  }
  gmMainChatUI::ResetAllTalkFocusMenuButtons((gmMainChatUI *)&v3[-1].m_pCCS);
  ChatInterface::ListenToGlobalMessage(v3, i_messageID, i_data_int);
}

//----- (006F3460) --------------------------------------------------------  // acclient.c:775829
void _E91_95()
{
  outside_val_87 = 1000.0 + 1.0;
}

//----- (006F3480) --------------------------------------------------------  // acclient.c:775835
void _E93_71()
{
  block_length_87 = 24.0 * 8.0;
}

//----- (006F34A0) --------------------------------------------------------  // acclient.c:775841
void _E95_71()
{
  half_square_length_87 = 24.0 * 0.5;
}

//----- (006F34C0) --------------------------------------------------------  // acclient.c:775847
int _E97_96()
{
  return atexit(nullsub_706);
}

//----- (006F34D0) --------------------------------------------------------  // acclient.c:775853
int _E100_89()
{
  return atexit(nullsub_707);
}

//----- (006F34E0) --------------------------------------------------------  // acclient.c:775859
int _E103_81()
{
  return atexit(_E104_96);
}

//----- (006F34F0) --------------------------------------------------------  // acclient.c:775865
void _E106_54()
{
  DEFAULT_VIEW_RADIUS_56 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F3510) --------------------------------------------------------  // acclient.c:775871
void _E108_41()
{
  MIN_QUANTUM_56 = 1.0 / 30.0;
}

//----- (006F3530) --------------------------------------------------------  // acclient.c:775877
void _E110_32()
{
  MAX_QUANTUM_56 = 1.0 / 5.0;
}

//----- (006F3550) --------------------------------------------------------  // acclient.c:775883
void _E112_48()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_91, PFID_A8R8G8B8);
}

//----- (006F3560) --------------------------------------------------------  // acclient.c:775889
int _E114_29()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_34, "Misc.TooltipEnable");
  return atexit(sub_761850);
}

//----- (006F3580) --------------------------------------------------------  // acclient.c:775896
int _E117_34()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_34, "Misc.TooltipDelay");
  return atexit(sub_761880);
}

//----- (006F35A0) --------------------------------------------------------  // acclient.c:775903
void _E121_45()
{
  LOWEST_DATA_RATE_93 = 1024;
}

//----- (006F35B0) --------------------------------------------------------  // acclient.c:775909
void _E123_18()
{
  HIGHEST_DATA_RATE_93 = 0x7FFF;
}

//----- (006F35C0) --------------------------------------------------------  // acclient.c:775915
int _E125_5()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_93;
  INITIAL_MAX_DATA_RATE_41 = LOWEST_DATA_RATE_93;
  return result;
}

//----- (006F35D0) --------------------------------------------------------  // acclient.c:775925
int _E127_37()
{
  return atexit(_E128_47);
}

//----- (006F35E0) --------------------------------------------------------  // acclient.c:775931
int _E133_24()
{
  PStringBase<char>::PStringBase<char>(&Input_KeymapFile_1, "Input.KeymapFile");
  return atexit(_E134_29);
}

//----- (006F3600) --------------------------------------------------------  // acclient.c:775938
int _E136_19()
{
  PStringBase<char>::PStringBase<char>(&UI_ChatFontFace_1, "UI.ChatFontFace");
  return atexit(_E137_28);
}

//----- (006F3620) --------------------------------------------------------  // acclient.c:775945
int _E139_19()
{
  PStringBase<char>::PStringBase<char>(&UI_ChatFontSize_1, "UI.ChatFontSize");
  return atexit(_E140_23);
}

//----- (006F3640) --------------------------------------------------------  // acclient.c:775952
int _E142_17()
{
  PStringBase<char>::PStringBase<char>(UI_ChatFontFace_Choices_1, "Arial");
  PStringBase<char>::PStringBase<char>(&stru_83FAAC, "CourierNew");
  PStringBase<char>::PStringBase<char>(&stru_83FAB0, "PalatinoLinotype");
  PStringBase<char>::PStringBase<char>(&stru_83FAB4, "Tahoma");
  PStringBase<char>::PStringBase<char>(&stru_83FAB8, "TimesNewRoman");
  return atexit(_E143_24);
}

//----- (006F36A0) --------------------------------------------------------  // acclient.c:775963
int _E145_18()
{
  PStringBase<char>::PStringBase<char>(UI_ChatFontSize_Choices_1, "Tiny");
  PStringBase<char>::PStringBase<char>(&stru_83FAC0, "Small");
  PStringBase<char>::PStringBase<char>(&stru_83FAC4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83FAC8, "Large");
  PStringBase<char>::PStringBase<char>(&stru_83FACC, "XL");
  return atexit(_E146_24);
}

//----- (006F3700) --------------------------------------------------------  // acclient.c:775974
unsigned int _E148_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CmdPrefix");
  ID_CmdPrefix = result;
  return result;
}

//----- (006F3720) --------------------------------------------------------  // acclient.c:775984
unsigned int _E150_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_AliasPrefix");
  ID_AliasPrefix = result;
  return result;
}

//----- (006F3740) --------------------------------------------------------  // acclient.c:775994
unsigned int _E152_2()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_AssistedTell");
  ID_AssistedTell = result;
  return result;
}

//----- (006F3760) --------------------------------------------------------  // acclient.c:776004
unsigned int _E154_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_ChatTargetMenu");
  ID_Chat_ChatTargetMenu = result;
  return result;
}

//----- (006F3780) --------------------------------------------------------  // acclient.c:776014
unsigned int _E156_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_ChatTargetMenuAllegiance");
  ID_Chat_ChatTargetMenuAllegiance = result;
  return result;
}

//----- (006F37A0) --------------------------------------------------------  // acclient.c:776024
unsigned int _E158_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_ChatTargetMenuFellows");
  ID_Chat_ChatTargetMenuFellows = result;
  return result;
}

//----- (006F37C0) --------------------------------------------------------  // acclient.c:776034
unsigned int _E160_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_ChatTargetMenuMonarch");
  ID_Chat_ChatTargetMenuMonarch = result;
  return result;
}

//----- (006F37E0) --------------------------------------------------------  // acclient.c:776044
unsigned int _E162_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_ChatTargetMenuPatron");
  ID_Chat_ChatTargetMenuPatron = result;
  return result;
}

//----- (006F3800) --------------------------------------------------------  // acclient.c:776054
unsigned int _E164_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_ChatTargetMenuSelected");
  ID_Chat_ChatTargetMenuSelected = result;
  return result;
}

//----- (006F3820) --------------------------------------------------------  // acclient.c:776064
unsigned int _E166_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_ChatTargetMenuVassals");
  ID_Chat_ChatTargetMenuVassals = result;
  return result;
}

//----- (006F3840) --------------------------------------------------------  // acclient.c:776074
unsigned int _E168_16()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_SquelchSelected");
  ID_Chat_SquelchSelected = result;
  return result;
}

//----- (006F3860) --------------------------------------------------------  // acclient.c:776084
unsigned int _E170_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_SquelchSelectedNoSelection");
  ID_Chat_SquelchSelectedNoSelection = result;
  return result;
}

//----- (006F3880) --------------------------------------------------------  // acclient.c:776094
unsigned int _E172_13()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_TellToAll");
  ID_Chat_TellToAll = result;
  return result;
}

//----- (006F38A0) --------------------------------------------------------  // acclient.c:776104
unsigned int _E174_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_TellToAllegiance");
  ID_Chat_TellToAllegiance = result;
  return result;
}

//----- (006F38C0) --------------------------------------------------------  // acclient.c:776114
unsigned int _E176_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_TellToFellows");
  ID_Chat_TellToFellows = result;
  return result;
}

//----- (006F38E0) --------------------------------------------------------  // acclient.c:776124
unsigned int _E178_11()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_TellToMonarch");
  ID_Chat_TellToMonarch = result;
  return result;
}

//----- (006F3900) --------------------------------------------------------  // acclient.c:776134
unsigned int _E180_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_TellToPatron");
  ID_Chat_TellToPatron = result;
  return result;
}

//----- (006F3920) --------------------------------------------------------  // acclient.c:776144
unsigned int _E182_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_TellToSelected");
  ID_Chat_TellToSelected = result;
  return result;
}

//----- (006F3940) --------------------------------------------------------  // acclient.c:776154
unsigned int _E184_9()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_TellToSelectedNoSelection");
  ID_Chat_TellToSelectedNoSelection = result;
  return result;
}

//----- (006F3960) --------------------------------------------------------  // acclient.c:776164
unsigned int _E186_13()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_TellToVassals");
  ID_Chat_TellToVassals = result;
  return result;
}

//----- (006F3980) --------------------------------------------------------  // acclient.c:776174
unsigned int _E188_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_ChatTargetMenuGeneral");
  ID_Chat_ChatTargetMenuGeneral = result;
  return result;
}

//----- (006F39A0) --------------------------------------------------------  // acclient.c:776184
unsigned int _E190_9()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_ChatTargetMenuTrade");
  ID_Chat_ChatTargetMenuTrade = result;
  return result;
}

//----- (006F39C0) --------------------------------------------------------  // acclient.c:776194
unsigned int _E192_11()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_ChatTargetMenuLFG");
  ID_Chat_ChatTargetMenuLFG = result;
  return result;
}

//----- (006F39E0) --------------------------------------------------------  // acclient.c:776204
unsigned int _E194_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_ChatTargetMenuRoleplay");
  ID_Chat_ChatTargetMenuRoleplay = result;
  return result;
}

//----- (006F3A00) --------------------------------------------------------  // acclient.c:776214
unsigned int _E196_11()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_ChatTargetMenuSociety");
  ID_Chat_ChatTargetMenuSociety = result;
  return result;
}

//----- (006F3A20) --------------------------------------------------------  // acclient.c:776224
unsigned int _E198_9()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_ChatTargetMenuOlthoi");
  ID_Chat_ChatTargetMenuOlthoi = result;
  return result;
}

//----- (006F3A40) --------------------------------------------------------  // acclient.c:776234
unsigned int _E200()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_TellToGeneral");
  ID_Chat_TellToGeneral = result;
  return result;
}

//----- (006F3A60) --------------------------------------------------------  // acclient.c:776244
unsigned int _E202_9()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_TellToTrade");
  ID_Chat_TellToTrade = result;
  return result;
}

//----- (006F3A80) --------------------------------------------------------  // acclient.c:776254
unsigned int _E204_6()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_TellToLFG");
  ID_Chat_TellToLFG = result;
  return result;
}

//----- (006F3AA0) --------------------------------------------------------  // acclient.c:776264
unsigned int _E206_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_TellToRoleplay");
  ID_Chat_TellToRoleplay = result;
  return result;
}

//----- (006F3AC0) --------------------------------------------------------  // acclient.c:776274
unsigned int _E208_12()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_TellToSociety");
  ID_Chat_TellToSociety = result;
  return result;
}

//----- (006F3AE0) --------------------------------------------------------  // acclient.c:776284
unsigned int _E210_6()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Chat_TellToOlthoi");
  ID_Chat_TellToOlthoi = result;
  return result;
}

//----- (006F3B00) --------------------------------------------------------  // acclient.c:776294
unsigned int _E212_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("prefix");
  PREFIX = result;
  return result;
}

//----- (006F3B20) --------------------------------------------------------  // acclient.c:776304
unsigned int _E214_12()
{
  unsigned int result; // eax@1

  result = compute_str_hash("target");
  TARGET = result;
  return result;
}

//----- (006F3B40) --------------------------------------------------------  // acclient.c:776314
unsigned int _E216_6()
{
  unsigned int result; // eax@1

  result = compute_str_hash("VALUE");
  VALUE_4 = result;
  return result;
}

//----- (006F3B60) --------------------------------------------------------  // acclient.c:776324
int sub_6F3B60()
{
  return atexit(nullsub_705);
}

//----- (00761850) --------------------------------------------------------  // acclient.c:888803
void __cdecl sub_761850()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00761880) --------------------------------------------------------  // acclient.c:888816
void __cdecl sub_761880()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007618B0) --------------------------------------------------------  // acclient.c:888829
void __cdecl _E134_29()
{
  char *v0; // esi@1

  v0 = &Input_KeymapFile_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_KeymapFile_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007618E0) --------------------------------------------------------  // acclient.c:888842
void __cdecl _E137_28()
{
  char *v0; // esi@1

  v0 = &UI_ChatFontFace_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UI_ChatFontFace_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00761910) --------------------------------------------------------  // acclient.c:888855
void __cdecl _E140_23()
{
  char *v0; // esi@1

  v0 = &UI_ChatFontSize_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UI_ChatFontSize_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00761940) --------------------------------------------------------  // acclient.c:888868
void __cdecl _E143_24()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)UI_ChatFontSize_Choices_1;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00761980) --------------------------------------------------------  // acclient.c:888893
void __cdecl _E146_24()
{
  const unsigned int *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &ID_CmdPrefix;
  v1 = 5;
  do
  {
    v2 = *(v0 - 1);
    --v0;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

