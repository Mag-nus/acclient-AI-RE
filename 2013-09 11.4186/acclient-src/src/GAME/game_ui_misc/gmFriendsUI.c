/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmFriendsUI
   Object     : GAME\game_ui_misc\gmFriendsUI.obj
   Functions  : 46
   Addresses  : 0048D060 - 0075F790 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0048D060) --------------------------------------------------------  // acclient.c:200630
char __thiscall gmFriendsUI::RemoveFriendDisplay(gmFriendsUI *this, unsigned int _friendID)
{
  gmFriendsUI *v2; // ebx@1
  UIElement_ListBox *v3; // ecx@1
  unsigned int v4; // edi@1
  unsigned int v5; // ebp@2
  UIElement *v6; // esi@3
  char result; // al@6

  v2 = this;
  UIElement_ListBox::SetSelectedItem(this->m_pFriendsListBox, 0, 1);
  v3 = v2->m_pFriendsListBox;
  v4 = 0;
  if ( (signed int)v3->m_listItems.m_num <= 0 )
  {
LABEL_6:
    result = 0;
  }
  else
  {
    v5 = _friendID;
    while ( 1 )
    {
      v6 = UIElement_ListBox::GetItem(v3, v4);
      if ( v6 )
      {
        _friendID = 0;
        UIElement::GetAttribute_InstanceID(v6, 0x10000085u, &_friendID);
        if ( v5 == _friendID )
          break;
      }
      v3 = v2->m_pFriendsListBox;
      ++v4;
      if ( (signed int)v4 >= (signed int)v3->m_listItems.m_num )
        goto LABEL_6;
    }
    UIElement_ListBox::DeleteItem(v2->m_pFriendsListBox, v6);
    result = 1;
  }
  return result;
}

//----- (0048D0F0) --------------------------------------------------------  // acclient.c:200673
void __thiscall gmFriendsUI::PostInit(gmFriendsUI *this)
{
  gmFriendsUI *v1; // esi@1
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
  UIOption_Checkbox *v14; // ecx@18
  GlobalEventHandler *v15; // eax@20
  GlobalEventHandler *v16; // edi@20
  int v17; // esi@21

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000514u);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)1);
  else
    v3 = 0;
  v1->m_pAddButton = (UIElement_Button *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000515u);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)1);
  else
    v5 = 0;
  v1->m_pRemoveButton = (UIElement_Button *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000516u);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)1);
  else
    v7 = 0;
  v1->m_pTellButton = (UIElement_Button *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000517u);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)5);
  else
    v9 = 0;
  v1->m_pFriendsListBox = (UIElement_ListBox *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000051Bu);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)12);
  else
    v11 = 0;
  v1->m_pFriendNameEditBox = (UIElement_Text *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000052Cu);
  if ( v12 && (v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)268435509)) != 0 )
    v14 = (UIOption_Checkbox *)(v13 - 32);
  else
    v14 = 0;
  UIOption_Checkbox::SetPlayerOption(v14, AppearOffline_PlayerOption);
  v15 = GlobalEventHandler::GetGlobalEventHandler();
  v16 = v15;
  if ( v15 )
  {
    v17 = (int)&v1->vfptr;
    v15->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v15, 5100143u, (NoticeHandler *)v17);
    v16->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v16, 5100146u, (NoticeHandler *)v17);
    v16->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v16, (unsigned int)&loc_4DD273, (NoticeHandler *)v17);
    v16->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v16, 5100148u, (NoticeHandler *)v17);
    v16->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v16, (unsigned int)&loc_4DD275, (NoticeHandler *)v17);
  }
}

//----- (0048D240) --------------------------------------------------------  // acclient.c:200745
char __thiscall gmFriendsUI::Request_AddFriend(gmFriendsUI *this, PStringBase<char> *i_friend_name)
{
  char result; // al@2
  AC1Legacy::PStringBase<char> *v3; // eax@3
  PStringBase<char> *v4; // esi@3

  if ( this->m_friendsList._num_elements < 0x32 )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(
      (AC1Legacy::PStringBase<char> *)&i_friend_name,
      i_friend_name->m_charbuffer->m_data);
    CM_Social::Event_AddFriend(v3);
    v4 = i_friend_name;
    if ( !InterlockedDecrement((volatile LONG *)&i_friend_name[1]) )
    {
      if ( v4 )
        (*(void (__thiscall **)(PStringBase<char> *, signed int))&v4->m_charbuffer->m_data[0])(v4, 1);
    }
    result = 1;
  }
  else
  {
    ECM_UI::SendNotice_DisplayWeenieError(0x561u, &AC1Legacy::PStringBase<char>::null_string);
    result = 0;
  }
  return result;
}

//----- (0048D2A0) --------------------------------------------------------  // acclient.c:200774
void __thiscall gmFriendsUI::UpdateButtons(gmFriendsUI *this)
{
  gmFriendsUI *v1; // esi@1
  UIElement_ListBox *v2; // ecx@1
  unsigned int v3; // edi@1
  unsigned int v4; // eax@1
  UIElement **v5; // edx@2
  UIElement *v6; // eax@6
  UIElement *v7; // edi@6
  bool v8; // zf@6
  IInputActionCallbackVtbl *v9; // eax@6
  UIElement *v10; // eax@7
  int v11; // eax@8
  UIElement_Button *v12; // ecx@13

  v1 = this;
  v2 = this->m_pFriendsListBox;
  v3 = v2->m_listItems.m_num;
  v4 = 0;
  if ( v3 )
  {
    v5 = v2->m_listItems.m_data;
    while ( *v5 != v2->m_pSelectedItem )
    {
      ++v4;
      ++v5;
      if ( v4 >= v3 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v4 = -1;
  }
  v6 = UIElement_ListBox::GetItem(v2, v4);
  v7 = v6;
  v8 = v6 == 0;
  v9 = v1->m_pRemoveButton->vfptr;
  if ( v8 )
  {
    ((void (__stdcall *)(signed int))v9[13].__vecDelDtor)(13);
  }
  else
  {
    ((void (__stdcall *)(signed int))v9[13].__vecDelDtor)(1);
    v10 = UIElement::GetChildRecursive(v7, 0x1000051Au);
    if ( v10 )
    {
      v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)12);
      if ( v11 )
      {
        if ( *(_DWORD *)(v11 + 1024) == 268435540 )
        {
          ((void (__stdcall *)(signed int))v1->m_pTellButton->vfptr[13].__vecDelDtor)(1);
          goto LABEL_13;
        }
      }
    }
  }
  ((void (__stdcall *)(signed int))v1->m_pTellButton->vfptr[13].__vecDelDtor)(13);
LABEL_13:
  v12 = v1->m_pAddButton;
  if ( v1->m_friendsList._num_elements >= 0x32 )
    ((void (__stdcall *)(signed int))v12->vfptr[13].__vecDelDtor)(13);
  else
    ((void (__stdcall *)(signed int))v12->vfptr[13].__vecDelDtor)(1);
}

//----- (0048D370) --------------------------------------------------------  // acclient.c:200844
UIElement *__thiscall gmFriendsUI::FindSortedInsertPosition(gmFriendsUI *this, PStringBase<unsigned short> *_name, bool _online)
{
  gmFriendsUI *v3; // ebx@1
  UIElement_ListBox *v4; // ecx@1
  unsigned int v5; // esi@1
  const wchar_t **v6; // ebp@2
  UIElement *v7; // eax@3
  UIElement *v8; // edi@3
  UIElement *v9; // eax@4
  int v10; // eax@5
  int v11; // ecx@7
  const wchar_t **v13; // eax@11
  bool v14; // bl@11
  PStringBase<unsigned short> *v15; // esi@11
  int i; // [sp+10h] [bp-8h]@1
  gmFriendsUI *v17; // [sp+14h] [bp-4h]@1

  v3 = this;
  v4 = this->m_pFriendsListBox;
  v5 = 0;
  v17 = v3;
  i = 0;
  if ( (signed int)v4->m_listItems.m_num > 0 )
  {
    v6 = (const wchar_t **)_name;
    do
    {
      v7 = UIElement_ListBox::GetItem(v4, v5);
      v8 = v7;
      if ( v7 )
      {
        v9 = UIElement::GetChildRecursive(v7, 0x1000051Au);
        if ( v9 )
          v10 = v9->vfptr[12].OnAction((IInputActionCallback *)v9, (InputEvent *)12);
        else
          v10 = 0;
        v11 = *(_DWORD *)(v10 + 1024);
        if ( _online )
        {
          if ( v11 == 268435541 )
            return v8;
        }
        else if ( v11 == 268435540 )
        {
          goto LABEL_16;
        }
        v13 = (const wchar_t **)UIElement_Text::GetText((UIElement_Text *)v10, (PStringBase<unsigned short> *)&_name);
        v14 = _wcscmp(*v6, *v13) < 0;
        v15 = _name - 5;
        if ( !InterlockedDecrement((volatile LONG *)&_name[-4]) )
        {
          if ( v15 )
            (*(void (__thiscall **)(PStringBase<unsigned short> *, signed int))&v15->m_charbuffer->m_data[0])(v15, 1);
        }
        if ( v14 )
          return v8;
        v5 = i;
        v3 = v17;
      }
LABEL_16:
      v4 = v3->m_pFriendsListBox;
      ++v5;
      i = v5;
    }
    while ( (signed int)v5 < (signed int)v4->m_listItems.m_num );
  }
  return 0;
}

//----- (0048D470) --------------------------------------------------------  // acclient.c:200914
void __thiscall gmFriendsUI::RecvNotice_ChatCommand_AddFriend(gmFriendsUI *this, PStringBase<char> *i_friend_name)
{
  gmFriendsUI::Request_AddFriend((gmFriendsUI *)((char *)this - 1528), i_friend_name);
}

//----- (0048D480) --------------------------------------------------------  // acclient.c:200920
char __thiscall gmFriendsUI::AddFriendDisplay(gmFriendsUI *this, PStringBase<unsigned short> *_name, unsigned int _friendID, bool _online)
{
  gmFriendsUI *v4; // esi@1
  UIElement *v5; // eax@1
  int v6; // eax@1
  UIElement *v7; // esi@1
  UIElement *v8; // eax@1
  UIElement_Text *v9; // eax@2
  UIElement_Text *v10; // edi@2
  char result; // al@4

  v4 = this;
  v5 = gmFriendsUI::FindSortedInsertPosition(this, _name, _online);
  v6 = UIElement_ListBox::AddItemFromTemplateList(v4->m_pFriendsListBox, 0, v5);
  v7 = (UIElement *)v6;
  v8 = UIElement::GetChildRecursive((UIElement *)v6, 0x1000051Au);
  if ( v8
    && (v9 = (UIElement_Text *)v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12), (v10 = v9) != 0) )
  {
    UIElement_Text::SetText(v9, _name);
    UIElement::SetAttribute_InstanceID(v7, 0x10000085u, _friendID);
    if ( _online )
    {
      v10->vfptr[13].__vecDelDtor((IInputActionCallback *)v10, 268435540u);
      result = 1;
    }
    else
    {
      v10->vfptr[13].__vecDelDtor((IInputActionCallback *)v10, 268435541u);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0048D520) --------------------------------------------------------  // acclient.c:200960
int __thiscall gmFriendsUI::ListenToElementMessage(gmFriendsUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // ebp@1
  gmFriendsUI *v3; // esi@1
  int v4; // eax@2
  bool v5; // bl@4
  char *v6; // edi@4
  UIElement_Button *v7; // ecx@7
  UIElement_ListBox *v8; // edi@13
  unsigned int v9; // eax@13
  UIElement *v10; // eax@13
  int v11; // eax@14
  PStringBase<unsigned short> *v12; // eax@15
  UIElement_ListBox *v13; // edi@16
  unsigned int v14; // eax@16
  UIElement *v15; // eax@16
  PStringBase<unsigned short> *v16; // eax@18
  PStringBase<unsigned short> result; // [sp+8h] [bp-Ch]@4
  PStringBase<unsigned short> v18; // [sp+Ch] [bp-8h]@15
  PStringBase<unsigned short> v19; // [sp+10h] [bp-4h]@18

  v2 = i_rMsg;
  v3 = this;
  switch ( i_rMsg->idMessage )
  {
    case 4u:
    case 0x43u:
      gmFriendsUI::UpdateButtons(this);
      v4 = UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
      break;
    case 0x12u:
    case 0x44u:
      if ( this->m_friendsList._num_elements >= 0x32 )
        goto LABEL_19;
      v5 = *(_DWORD *)&UIElement_Text::GetText(this->m_pFriendNameEditBox, &result)->m_charbuffer[-1].m_data[14] == 1;
      v6 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) )
      {
        if ( v6 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      }
      v7 = v3->m_pAddButton;
      if ( !v5 )
      {
        ((void (__stdcall *)(signed int))v7->vfptr[13].__vecDelDtor)(1);
        goto LABEL_19;
      }
      ((void (__stdcall *)(signed int))v7->vfptr[13].__vecDelDtor)(13);
      v4 = UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
      break;
    case 1u:
      if ( i_rMsg->idElement == 268436756 )
      {
        v16 = UIElement_Text::GetText(this->m_pFriendNameEditBox, &v19);
        PStringBase<unsigned short>::to_spstring(v16, (PStringBase<char> *)&i_rMsg, 0);
        gmFriendsUI::Request_AddFriend(v3, (PStringBase<char> *)&i_rMsg);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_rMsg);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v19);
        UIElement_Text::ClearAllText(v3->m_pFriendNameEditBox);
        ((void (__stdcall *)(signed int))v3->m_pAddButton->vfptr[13].__vecDelDtor)(13);
        goto LABEL_19;
      }
      if ( i_rMsg->idElement == 268436757 )
      {
        v13 = this->m_pFriendsListBox;
        v14 = UIElement_ListBox::GetSelectedIndex(this->m_pFriendsListBox);
        v15 = UIElement_ListBox::GetItem(v13, v14);
        if ( !v15 )
          goto LABEL_19;
        i_rMsg = 0;
        UIElement::GetAttribute_InstanceID(v15, 0x10000085u, (unsigned int *)&i_rMsg);
        CM_Social::Event_RemoveFriend((unsigned int)i_rMsg);
        v4 = UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
      }
      else
      {
        if ( i_rMsg->idElement != 268436758 )
          goto LABEL_19;
        v8 = this->m_pFriendsListBox;
        v9 = UIElement_ListBox::GetSelectedIndex(this->m_pFriendsListBox);
        v10 = UIElement_ListBox::GetItem(v8, v9);
        if ( !v10 )
          goto LABEL_19;
        v11 = UIElement::GetChildRecursiveTemplate<UIElement_Text>(v10, 0x1000051Au);
        if ( !v11 )
          goto LABEL_19;
        v12 = UIElement_Text::GetText((UIElement_Text *)v11, &v18);
        CM_UI::SendNotice_StartTell(v12);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v18);
        v4 = UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
      }
      break;
    default:
LABEL_19:
      v4 = UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
      break;
  }
  return v4;
}

//----- (0048D760) --------------------------------------------------------  // acclient.c:201061
void __thiscall gmFriendsUI::RecvNotice_ChatCommand_DisplayFriends(gmFriendsUI *this, bool i_onlineOnly)
{
  gmFriendsUI *v2; // ebx@1
  HashSetData<UIElement *> *v3; // eax@1
  ClientSystem *v4; // esi@2
  int v5; // esi@2
  int v6; // ebp@5
  ClientSystem *v7; // esi@5
  char *v8; // esi@5
  HashSetData<UIElement *> *v9; // ecx@8
  UIElement *v10; // edx@8
  unsigned int v11; // eax@8
  UIElement *v12; // eax@9
  UIElement *v13; // eax@10
  int v14; // esi@11
  PStringBase<unsigned short> *v15; // esi@14
  unsigned int v16; // eax@14
  char *v17; // esi@14
  char *v18; // esi@17
  char *v19; // esi@20
  char *v20; // esi@23
  ClientSystem *v21; // eax@26
  PSRefBufferCharData<unsigned short> *v22; // esi@26
  PStringBase<unsigned short> *v23; // eax@28
  PStringBase<unsigned short> *v24; // eax@28
  char *v25; // esi@28
  char *v26; // esi@31
  char *v27; // esi@34
  ClientSystem *v28; // eax@37
  int v29; // esi@38
  int v30; // edx@41
  ClientSystem *v31; // esi@43
  int v32; // esi@43
  PStringBase<unsigned short> i_text; // [sp+8h] [bp-2Ch]@5
  PStringBase<unsigned short> v34; // [sp+Ch] [bp-28h]@14
  PStringBase<unsigned short> rhs; // [sp+10h] [bp-24h]@14
  PStringBase<unsigned short> msg; // [sp+14h] [bp-20h]@17
  PStringBase<unsigned short> v37; // [sp+18h] [bp-1Ch]@28
  PStringBase<unsigned short> v38; // [sp+1Ch] [bp-18h]@28
  int i; // [sp+20h] [bp-14h]@8
  PStringBase<unsigned short> result; // [sp+24h] [bp-10h]@14
  PStringBase<unsigned short> v41; // [sp+28h] [bp-Ch]@28
  PStringBase<unsigned short> v42; // [sp+2Ch] [bp-8h]@28
  gmFriendsUI *v43; // [sp+30h] [bp-4h]@1

  v2 = this;
  v3 = this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6];
  v43 = this;
  if ( !v3 )
  {
    v4 = (ClientSystem *)ClientUISystem::GetUISystem();
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&i_onlineOnly,
      0,
      "Your friends list is empty!\n");
    ClientSystem::AddTextToScroll(v4, (PStringBase<unsigned short> *)&i_onlineOnly, 0, 1, 0);
    v5 = i_onlineOnly - 20;
    if ( !InterlockedDecrement((volatile LONG *)(i_onlineOnly - 20 + 4)) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    return;
  }
  v6 = 0;
  v7 = (ClientSystem *)ClientUISystem::GetUISystem();
  PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, 0, "Your friends:\n");
  ClientSystem::AddTextToScroll(v7, &i_text, 0, 1, 0);
  v8 = (char *)&i_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v8 )
    (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
  v9 = v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1];
  v10 = v9[194].m_hashKey;
  v11 = 0;
  i = 0;
  if ( (signed int)v10 <= 0 )
  {
LABEL_43:
    v31 = (ClientSystem *)ClientUISystem::GetUISystem();
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&i_onlineOnly,
      0,
      "  You have no friends that are online.\n");
    ClientSystem::AddTextToScroll(v31, (PStringBase<unsigned short> *)&i_onlineOnly, 0, 1, 0);
    v32 = i_onlineOnly - 20;
    if ( !InterlockedDecrement((volatile LONG *)(i_onlineOnly - 20 + 4)) && v32 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v32)(v32, 1);
    return;
  }
  do
  {
    v12 = UIElement_ListBox::GetItem((UIElement_ListBox *)v9, v11);
    if ( !v12 )
      goto LABEL_41;
    v13 = UIElement::GetChildRecursive(v12, 0x1000051Au);
    if ( v13 )
      v14 = v13->vfptr[12].OnAction((IInputActionCallback *)v13, (InputEvent *)12);
    else
      v14 = 0;
    if ( *(_DWORD *)(v14 + 1024) == 268435540 )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(&rhs, L" (Online)\n");
      v15 = UIElement_Text::GetText((UIElement_Text *)v14, &result);
      v16 = _wcslen(L"  ");
      PStringBase<unsigned short>::allocate_ref_buffer(&i_text, v16);
      _wcscpy(i_text.m_charbuffer->m_data, L"  ");
      PStringBase<unsigned short>::operator+(&i_text, &v34, v15);
      v17 = (char *)&i_text.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v17 )
        (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
      PStringBase<unsigned short>::operator+(&v34, &msg, &rhs);
      v18 = (char *)&v34.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v34.m_charbuffer[-1].m_data[8]) && v18 )
        (**(void (__thiscall ***)(char *, signed int))v18)(v18, 1);
      v19 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v19 )
        (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
      v20 = (char *)&rhs.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1].m_data[8]) && v20 )
        (**(void (__thiscall ***)(char *, signed int))v20)(v20, 1);
      v21 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v21, &msg, 0, 1, 0);
      v22 = msg.m_charbuffer;
    }
    else
    {
      if ( i_onlineOnly )
        goto LABEL_41;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v37, L"\n");
      v23 = UIElement_Text::GetText((UIElement_Text *)v14, &v42);
      v24 = operator+(&v41, L"  ", v23);
      PStringBase<unsigned short>::operator+(v24, &v38, &v37);
      v25 = (char *)&v41.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v41.m_charbuffer[-1].m_data[8]) && v25 )
        (**(void (__thiscall ***)(char *, signed int))v25)(v25, 1);
      v26 = (char *)&v42.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v42.m_charbuffer[-1].m_data[8]) && v26 )
        (**(void (__thiscall ***)(char *, signed int))v26)(v26, 1);
      v27 = (char *)&v37.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v37.m_charbuffer[-1].m_data[8]) && v27 )
        (**(void (__thiscall ***)(char *, signed int))v27)(v27, 1);
      v28 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v28, &v38, 0, 1, 0);
      v22 = v38.m_charbuffer;
    }
    v29 = (int)&v22[-1].m_data[6];
    ++v6;
    if ( !InterlockedDecrement((volatile LONG *)(v29 + 4)) && v29 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v29)(v29, 1);
LABEL_41:
    v9 = v43->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1];
    v30 = (int)v9[194].m_hashKey;
    v11 = i++ + 1;
  }
  while ( i < v30 );
  if ( !v6 )
    goto LABEL_43;
}

//----- (0048DAC0) --------------------------------------------------------  // acclient.c:201221
void __thiscall gmFriendsUI::RecvNotice_ChatCommand_RemoveFriend(gmFriendsUI *this, PStringBase<char> *i_friend_name)
{
  AC1Legacy::ListNode<FriendData> *v2; // ecx@1
  PSRefBufferCharData<char> *v3; // ecx@3
  void *v4; // eax@3
  int v5; // eax@4
  int v6; // eax@5
  char *v7; // esi@5
  bool v8; // bl@5
  char *v9; // esi@9
  char *v10; // esi@13
  PStringBase<char> v11; // [sp-4h] [bp-68h]@3
  PStringBase<char> iter_name; // [sp+10h] [bp-54h]@3
  PStringBase<char> v13; // [sp+14h] [bp-50h]@5
  gmFriendsUI *v14; // [sp+18h] [bp-4Ch]@1
  AC1Legacy::ListIterator<FriendData> iter; // [sp+1Ch] [bp-48h]@1
  FriendData friendData; // [sp+28h] [bp-3Ch]@3

  v14 = this;
  v2 = (AC1Legacy::ListNode<FriendData> *)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4];
  for ( iter._current = v2; ; iter._current = iter._current->next )
  {
    if ( !v2 )
    {
      ECM_UI::SendNotice_DisplayWeenieError(0x563u, &AC1Legacy::PStringBase<char>::null_string);
      return;
    }
    FriendData::FriendData(&friendData, &v2->data);
    PStringBase<char>::PStringBase<char>(&iter_name, friendData.m_name.m_buffer->m_data);
    v11.m_charbuffer = v3;
    v4 = operator new[](0x24u);
    if ( v4 )
    {
      *((_DWORD *)v4 + 1) = 1;
      *(_DWORD *)v4 = AC1Legacy::PSRefBuffer<char>::vftable;
      *((_DWORD *)v4 + 4) = 1;
      *((_DWORD *)v4 + 2) = 1;
      *((_DWORD *)v4 + 3) = -1;
      v5 = (int)((char *)v4 + 20);
      *(_BYTE *)v5 = 0;
      v11.m_charbuffer = (PSRefBufferCharData<char> *)v5;
      *(_DWORD *)(v5 - 4) = 2;
      *(_DWORD *)(v5 - 12) = 16;
    }
    v11.m_charbuffer->m_data[0] = 43;
    v11.m_charbuffer->m_data[1] = 0;
    PStringBase<char>::trim(&iter_name, 1, 0, v11);
    PStringBase<char>::PStringBase<char>(&v13, iter_name.m_charbuffer->m_data);
    v6 = __stricmp(i_friend_name->m_charbuffer->m_data, v13.m_charbuffer->m_data);
    v7 = &v13.m_charbuffer[-2].m_data[12];
    v8 = v6 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v13.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    if ( v8 )
      break;
    v9 = &iter_name.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&iter_name.m_charbuffer[-1]) )
    {
      if ( v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    }
    FriendData::~FriendData(&friendData);
    v2 = iter._current->next;
  }
  CM_Social::Event_RemoveFriend(friendData.m_id);
  v10 = &iter_name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&iter_name.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  FriendData::~FriendData(&friendData);
}
// 7CA074: using guessed type int (__thiscall *AC1Legacy::PSRefBuffer<char>::vftable[2])(void *, char);

//----- (0048DC40) --------------------------------------------------------  // acclient.c:201294
char __thiscall gmFriendsUI::RefreshFriendsDisplay(gmFriendsUI *this)
{
  gmFriendsUI *v1; // ebx@1
  AC1Legacy::ListNode<FriendData> *i; // esi@1
  bool v3; // ST0C_1@3
  unsigned int v4; // ST08_4@3
  PStringBase<unsigned short> *v5; // eax@3
  char *v6; // edi@3
  PStringBase<unsigned short> v8; // [sp+10h] [bp-4h]@3

  v1 = this;
  UIElement_ListBox::Flush(this->m_pFriendsListBox);
  UIElement_ListBox::SetSelectedItem(v1->m_pFriendsListBox, 0, 1);
  for ( i = v1->m_friendsList._head; i; i = i->next )
  {
    v3 = i->data.m_online != 0;
    v4 = i->data.m_id;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v8, 0, i->data.m_name.m_buffer->m_data);
    gmFriendsUI::AddFriendDisplay(v1, v5, v4, v3);
    v6 = (char *)&v8.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v8.m_charbuffer[-1].m_data[8]) )
    {
      if ( v6 )
        (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
    }
  }
  gmFriendsUI::UpdateButtons(v1);
  return 1;
}

//----- (0048DCD0) --------------------------------------------------------  // acclient.c:201325
char __thiscall gmFriendsUI::ServerSays_UpdateFriend(gmFriendsUI *this, FriendDataList *i_friendDataList)
{
  gmFriendsUI *v2; // esi@1
  UIElement *v3; // ebx@2
  bool v4; // ST0C_1@2
  unsigned int v5; // ST08_4@2
  PStringBase<unsigned short> *v6; // eax@2
  FriendDataList *v7; // edi@2
  char result; // al@5
  FriendData myFriend; // [sp+4h] [bp-3Ch]@1

  v2 = this;
  FriendData::FriendData(&myFriend);
  if ( i_friendDataList->_head )
  {
    FriendData::operator=((int)&myFriend, (int)i_friendDataList->_head);
    v3 = v2->m_pFriendsListBox->m_pSelectedItem;
    gmFriendsUI::RemoveFriendDisplay(v2, myFriend.m_id);
    v4 = myFriend.m_online != 0;
    v5 = myFriend.m_id;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&i_friendDataList,
      0,
      myFriend.m_name.m_buffer->m_data);
    gmFriendsUI::AddFriendDisplay(v2, v6, v5, v4);
    v7 = i_friendDataList - 1;
    if ( !InterlockedDecrement((volatile LONG *)&i_friendDataList[-1]._head) )
    {
      if ( v7 )
        v7->vfptr->__vecDelDtor((AC1Legacy::List<FriendData> *)v7, 1u);
    }
    UIElement_ListBox::SetSelectedItem(v2->m_pFriendsListBox, v3, 1);
    FriendData::~FriendData(&myFriend);
    result = 1;
  }
  else
  {
    FriendData::~FriendData(&myFriend);
    result = 0;
  }
  return result;
}

//----- (0048DDA0) --------------------------------------------------------  // acclient.c:201369
int __thiscall AC1Legacy::List<FriendData>::insert(AC1Legacy::List<FriendData> *this, AC1Legacy::ListNode<FriendData> *node, FriendData *val)
{
  AC1Legacy::List<FriendData> *v3; // edi@1
  void *v4; // esi@1
  int v5; // eax@3
  int result; // eax@3
  AC1Legacy::ListNode<FriendData> *v7; // ecx@5

  v3 = this;
  v4 = operator new(0x44u);
  if ( v4 )
  {
    FriendData::FriendData((FriendData *)v4, val);
    *((_DWORD *)v4 + 15) = 0;
    *((_DWORD *)v4 + 16) = 0;
    if ( v3->_head )
    {
      *((_DWORD *)v4 + 15) = node;
      *((_DWORD *)v4 + 16) = node->prev;
      v7 = node->prev;
      if ( v7 )
      {
        v7->next = (AC1Legacy::ListNode<FriendData> *)v4;
        node->prev = (AC1Legacy::ListNode<FriendData> *)v4;
        ++v3->_num_elements;
        result = 1;
      }
      else
      {
        v3->_head = (AC1Legacy::ListNode<FriendData> *)v4;
        node->prev = (AC1Legacy::ListNode<FriendData> *)v4;
        ++v3->_num_elements;
        result = 1;
      }
    }
    else
    {
      v5 = v3->_num_elements + 1;
      v3->_head = (AC1Legacy::ListNode<FriendData> *)v4;
      v3->_tail = (AC1Legacy::ListNode<FriendData> *)v4;
      v3->_num_elements = v5;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0048DE30) --------------------------------------------------------  // acclient.c:201421
int __thiscall AC1Legacy::List<FriendData>::remove(AC1Legacy::List<FriendData> *this, AC1Legacy::ListNode<FriendData> *node)
{
  AC1Legacy::List<FriendData> *v2; // edi@1
  AC1Legacy::ListNode<FriendData> *v3; // ecx@1
  AC1Legacy::ListNode<FriendData> *v4; // eax@2
  AC1Legacy::ListNode<FriendData> *v6; // eax@5

  v2 = this;
  v3 = 0;
  if ( !node )
    return 0;
  v4 = v2->_head;
  if ( !v4 )
    return 0;
  if ( node != v4 )
  {
    node->prev->next = node->next;
    v6 = node->next;
    if ( !v6 )
    {
      v2->_tail = node->prev;
      goto LABEL_11;
    }
    v3 = node->prev;
    goto LABEL_9;
  }
  v6 = node->next;
  v2->_head = v6;
  if ( v6 )
  {
LABEL_9:
    v6->prev = v3;
    goto LABEL_11;
  }
  v2->_tail = 0;
LABEL_11:
  FriendData::~FriendData(&node->data);
  operator delete(node);
  --v2->_num_elements;
  return 1;
}

//----- (0048DEA0) --------------------------------------------------------  // acclient.c:201464
int __thiscall AC1Legacy::List<FriendData>::remove(AC1Legacy::List<FriendData> *this, FriendData *val)
{
  AC1Legacy::List<FriendData> *v2; // ebx@1
  AC1Legacy::ListNode<FriendData> *v3; // esi@1
  int v4; // edi@1
  int result; // eax@7

  v2 = this;
  v3 = this->_head;
  v4 = 0;
  if ( !v3 )
    goto LABEL_11;
  do
  {
    if ( FriendData::operator==(&v3->data, val) )
      v4 = (int)v3;
    if ( !v3 )
      break;
    v3 = v3->next;
  }
  while ( v3 );
  if ( v4 )
  {
    FriendData::operator=((int)val, v4);
    result = AC1Legacy::List<FriendData>::remove(v2, (AC1Legacy::ListNode<FriendData> *)v4);
  }
  else
  {
LABEL_11:
    result = 0;
  }
  return result;
}

//----- (0048DEF0) --------------------------------------------------------  // acclient.c:201499
char __thiscall gmFriendsUI::ServerSays_AddFriend(gmFriendsUI *this, FriendDataList *i_friendDataList)
{
  gmFriendsUI *v2; // edi@1
  bool v3; // ST0C_1@2
  unsigned int v4; // ST08_4@2
  PStringBase<unsigned short> *v5; // eax@2
  FriendDataList *v6; // esi@2
  char result; // al@5
  FriendData myFriend; // [sp+4h] [bp-3Ch]@1

  v2 = this;
  FriendData::FriendData(&myFriend);
  if ( i_friendDataList->_head )
  {
    FriendData::operator=((int)&myFriend, (int)i_friendDataList->_head);
    AC1Legacy::List<FriendData>::insert(
      (AC1Legacy::List<FriendData> *)&v2->m_friendsList.vfptr,
      v2->m_friendsList._head,
      &myFriend);
    v3 = myFriend.m_online != 0;
    v4 = myFriend.m_id;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&i_friendDataList,
      0,
      myFriend.m_name.m_buffer->m_data);
    gmFriendsUI::AddFriendDisplay(v2, v5, v4, v3);
    v6 = i_friendDataList - 1;
    if ( !InterlockedDecrement((volatile LONG *)&i_friendDataList[-1]._head) )
    {
      if ( v6 )
        v6->vfptr->__vecDelDtor((AC1Legacy::List<FriendData> *)v6, 1u);
    }
    gmFriendsUI::UpdateButtons(v2);
    FriendData::~FriendData(&myFriend);
    result = 1;
  }
  else
  {
    FriendData::~FriendData(&myFriend);
    result = 0;
  }
  return result;
}

//----- (0048DFB0) --------------------------------------------------------  // acclient.c:201544
char __thiscall gmFriendsUI::ServerSays_RemoveFriend(gmFriendsUI *this, FriendDataList *i_friendDataList, bool i_bSilent)
{
  gmFriendsUI *v3; // esi@1
  char result; // al@2
  FriendData myFriend; // [sp+4h] [bp-3Ch]@1

  v3 = this;
  FriendData::FriendData(&myFriend);
  if ( i_friendDataList->_head )
  {
    FriendData::operator=((int)&myFriend, (int)i_friendDataList->_head);
    AC1Legacy::List<FriendData>::remove((AC1Legacy::List<FriendData> *)&v3->m_friendsList.vfptr, &myFriend);
    gmFriendsUI::RemoveFriendDisplay(v3, myFriend.m_id);
    gmFriendsUI::UpdateButtons(v3);
    FriendData::~FriendData(&myFriend);
    result = 1;
  }
  else
  {
    FriendData::~FriendData(&myFriend);
    result = 0;
  }
  return result;
}

//----- (0048E020) --------------------------------------------------------  // acclient.c:201570
void __thiscall gmFriendsUI::RecvNotice_ChatCommand_RemoveAllFriends(gmFriendsUI *this)
{
  gmFriendsUI *v1; // esi@1
  ClientSystem *v2; // esi@1
  char *v3; // esi@1
  PStringBase<unsigned short> i_text; // [sp+0h] [bp-4h]@1

  i_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v1 = this;
  CM_Social::Event_ClearFriends();
  AC1Legacy::List<FriendData>::flush((AC1Legacy::List<FriendData> *)&v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3]);
  UIElement_ListBox::Flush((UIElement_ListBox *)v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1]);
  UIElement_ListBox::SetSelectedItem(
    (UIElement_ListBox *)v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1],
    0,
    1);
  v2 = (ClientSystem *)ClientUISystem::GetUISystem();
  PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, 0, "Your friends list has been cleared.\n");
  ClientSystem::AddTextToScroll(v2, &i_text, 0, 1, 0);
  v3 = (char *)&i_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}

//----- (0048E0A0) --------------------------------------------------------  // acclient.c:201598
void __userpurge gmFriendsUI::gmFriendsUI(gmFriendsUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFriendsUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_pAddButton = 0;
  v4->m_pRemoveButton = 0;
  v4->m_pTellButton = 0;
  v4->m_pFriendsListBox = 0;
  v4->m_pFriendNameEditBox = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmFriendsUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmFriendsUI::vftable;
  v4->m_friendsList._head = 0;
  v4->m_friendsList._tail = 0;
  v4->m_friendsList._num_elements = 0;
  v4->m_friendsList.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v4->m_friendsList.vfptr = (AC1Legacy::List<FriendData>Vtbl *)&FriendDataList::vftable;
  v4->m_friendsList.vfptr = (PackObjVtbl *)&PList<FriendData>::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A413C: using guessed type void *PList<FriendData>::vftable;
// 7A4150: using guessed type int (__thiscall *FriendDataList::vftable)(void *, char);
// 7A47B8: using guessed type bool (__thiscall *gmFriendsUI::vftable)(DBCache *this);
// 7A4A60: using guessed type int (__thiscall *gmFriendsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0048E130) --------------------------------------------------------  // acclient.c:201627
gmFriendsUI *__thiscall gmFriendsUI::DynamicCast(gmFriendsUI *this, unsigned int i_eType)
{
  gmFriendsUI *result; // eax@1

  result = this;
  if ( i_eType != 268435525 )
    result = (gmFriendsUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (0048E150) --------------------------------------------------------  // acclient.c:201638
signed int gmFriendsUI::GetUIElementType()
{
  return 268435525;
}

//----- (0048E160) --------------------------------------------------------  // acclient.c:201644
void __thiscall gmFriendsUI::~gmFriendsUI(gmFriendsUI *this)
{
  gmFriendsUI *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1
  int v4; // ecx@3

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmFriendsUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmFriendsUI::vftable;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v4 = (int)&v1->m_friendsList;
  *(_DWORD *)(v4 + 16) = &PList<FriendData>::vftable;
  *(_DWORD *)(v4 + 16) = &PackObj::vftable;
  *(_DWORD *)v4 = AC1Legacy::List<FriendData>::vftable;
  AC1Legacy::List<FriendData>::flush((AC1Legacy::List<FriendData> *)&v1->m_friendsList.vfptr);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A410C: using guessed type int (__thiscall *AC1Legacy::List<FriendData>::vftable[2])(void *, char);
// 7A413C: using guessed type void *PList<FriendData>::vftable;
// 7A47B8: using guessed type bool (__thiscall *gmFriendsUI::vftable)(DBCache *this);
// 7A4A60: using guessed type int (__thiscall *gmFriendsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0048E1C0) --------------------------------------------------------  // acclient.c:201675
void __usercall gmFriendsUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFriendsUI *v3; // eax@1

  v3 = (gmFriendsUI *)operator new(0x624u);
  if ( v3 )
    gmFriendsUI::gmFriendsUI(v3, a1, _layout, _full_desc);
}

//----- (0048E1F0) --------------------------------------------------------  // acclient.c:201685
gmFriendsUI *__thiscall gmFriendsUI::vector_deleting_destructor(gmFriendsUI *this, unsigned int a2)
{
  gmFriendsUI *v2; // esi@1

  v2 = this;
  gmFriendsUI::~gmFriendsUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0048E210) --------------------------------------------------------  // acclient.c:201697
void __cdecl gmFriendsUI::Register()
{
  UIElement::RegisterElementClass(0x10000045u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmFriendsUI::Create);
}

//----- (0048E230) --------------------------------------------------------  // acclient.c:201703
AC1Legacy::List<FriendData> *__thiscall FriendDataList::operator=(AC1Legacy::List<FriendData> *this, int a2)
{
  AC1Legacy::List<FriendData> *v2; // edi@1
  int i; // esi@2

  v2 = this;
  if ( this != (AC1Legacy::List<FriendData> *)a2 )
  {
    AC1Legacy::List<FriendData>::flush(this);
    for ( i = *(_DWORD *)(a2 + 4); i; i = *(_DWORD *)(i + 60) )
    {
      AC1Legacy::List<FriendData>::push_back(v2, (FriendData *)i);
      if ( !i )
        break;
    }
  }
  return v2;
}

//----- (0048E270) --------------------------------------------------------  // acclient.c:201723
void __thiscall gmFriendsUI::RecvNotice_UpdateFriendsList(gmFriendsUI *this, FriendDataList *i_friendDataList, int i_updateType)
{
  gmFriendsUI *v3; // esi@1

  v3 = this;
  switch ( i_updateType )
  {
    case 0:
      FriendDataList::operator=(
        (AC1Legacy::List<FriendData> *)&this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3],
        (int)i_friendDataList);
      gmFriendsUI::RefreshFriendsDisplay((gmFriendsUI *)((char *)v3 - 1528));
      break;
    case 1:
      gmFriendsUI::ServerSays_AddFriend((gmFriendsUI *)((char *)this - 1528), i_friendDataList);
      break;
    case 2:
      gmFriendsUI::ServerSays_RemoveFriend((gmFriendsUI *)((char *)this - 1528), i_friendDataList, 0);
      break;
    case 3:
      gmFriendsUI::ServerSays_RemoveFriend((gmFriendsUI *)((char *)this - 1528), i_friendDataList, 1);
      break;
    case 4:
      gmFriendsUI::ServerSays_UpdateFriend((gmFriendsUI *)((char *)this - 1528), i_friendDataList);
      break;
    default:
      return;
  }
}

//----- (006EDFA0) --------------------------------------------------------  // acclient.c:769943
void _E91_54()
{
  outside_val_46 = 1000.0 + 1.0;
}

//----- (006EDFC0) --------------------------------------------------------  // acclient.c:769949
void _E93_30()
{
  block_length_46 = 24.0 * 8.0;
}

//----- (006EDFE0) --------------------------------------------------------  // acclient.c:769955
void _E95_30()
{
  half_square_length_46 = 24.0 * 0.5;
}

//----- (006EE000) --------------------------------------------------------  // acclient.c:769961
int _E97_55()
{
  return atexit(_E98_67);
}

//----- (006EE010) --------------------------------------------------------  // acclient.c:769967
int _E100_48()
{
  return atexit(_E101_85);
}

//----- (006EE020) --------------------------------------------------------  // acclient.c:769973
int _E103_40()
{
  return atexit(_E104_55);
}

//----- (006EE030) --------------------------------------------------------  // acclient.c:769979
void _E106_30()
{
  DEFAULT_VIEW_RADIUS_24 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EE050) --------------------------------------------------------  // acclient.c:769985
void _E108_21()
{
  MIN_QUANTUM_24 = 1.0 / 30.0;
}

//----- (006EE070) --------------------------------------------------------  // acclient.c:769991
void _E110_12()
{
  MAX_QUANTUM_24 = 1.0 / 5.0;
}

//----- (006EE090) --------------------------------------------------------  // acclient.c:769997
void _E112_26()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_59, PFID_A8R8G8B8);
}

//----- (006EE0A0) --------------------------------------------------------  // acclient.c:770003
void _E115_19()
{
  LOWEST_DATA_RATE_67 = 1024;
}

//----- (006EE0B0) --------------------------------------------------------  // acclient.c:770009
void _E117_16()
{
  HIGHEST_DATA_RATE_67 = 0x7FFF;
}

//----- (006EE0C0) --------------------------------------------------------  // acclient.c:770015
int _E119_5()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_67;
  INITIAL_MAX_DATA_RATE_15 = LOWEST_DATA_RATE_67;
  return result;
}

//----- (006EE0D0) --------------------------------------------------------  // acclient.c:770025
int _E121_26()
{
  return atexit(_E122_63);
}

//----- (006EE0E0) --------------------------------------------------------  // acclient.c:770031
int _E124_24()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_18, "Misc.TooltipEnable");
  return atexit(_E125_34);
}

//----- (006EE100) --------------------------------------------------------  // acclient.c:770038
int _E127_20()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_18, "Misc.TooltipDelay");
  return atexit(_E128_35);
}

//----- (006EE120) --------------------------------------------------------  // acclient.c:770045
int sub_6EE120()
{
  return atexit(nullsub_905);
}

//----- (0075F760) --------------------------------------------------------  // acclient.c:887315
void __cdecl _E125_34()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075F790) --------------------------------------------------------  // acclient.c:887328
void __cdecl _E128_35()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

