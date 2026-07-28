/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Social
   Object     : GAME\game_cevents\CM_Social.obj
   Functions  : 36
   Addresses  : 006A54C0 - 00721DE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006A54C0) --------------------------------------------------------  // acclient.c:702239
unsigned int __cdecl CM_Social::DispatchUI_AddOrSetCharacterTitle(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pUISystem && *(_DWORD *)buf == 43 )
    result = ClientUISystem::Handle_Social__AddOrSetCharacterTitle(*((_DWORD *)buf + 1), *((_DWORD *)buf + 2));
  else
    result = 0;
  return result;
}

//----- (006A54F0) --------------------------------------------------------  // acclient.c:702251
bool __cdecl CM_Social::Event_AbandonContract(unsigned int i_contract_id)
{
  signed int v1; // eax@1
  int v2; // esi@1
  void *v3; // eax@1
  char *v4; // edi@1
  char *v5; // eax@1
  int v6; // eax@1
  int v7; // ecx@2
  bool v8; // bl@4
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v1 = OrderHdr::Pack(&hdr, &buf, 0);
  v2 = v1 + 8;
  v3 = operator new[](v1 + 8);
  buf = v3;
  v4 = (char *)v3;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 790;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_contract_id;
  buf = (char *)buf + 4;
  v6 = (signed int)buf % 4;
  if ( (signed int)buf % 4 )
  {
    v7 = 4 - v6;
    if ( 4 != v6 )
    {
      do
      {
        *(_BYTE *)buf = 0;
        --v7;
        buf = (char *)buf + 1;
      }
      while ( v7 );
    }
  }
  v8 = Proto_UI::SendToWeenie(v4, v2);
  if ( !v8 )
    Proto_UI::UICounterFailedSend();
  return v8;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A55C0) --------------------------------------------------------  // acclient.c:702301
bool __cdecl CM_Social::Event_ClearFriends()
{
  int v0; // esi@1
  char *v1; // edi@1
  bool v2; // bl@1
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v0 = OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v0);
  v1 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v0);
  *(_DWORD *)buf = 37;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A5650) --------------------------------------------------------  // acclient.c:702326
bool __cdecl CM_Social::Event_RemoveFriend(unsigned int i_friendID)
{
  signed int v1; // eax@1
  int v2; // esi@1
  void *v3; // eax@1
  char *v4; // edi@1
  char *v5; // eax@1
  int v6; // eax@1
  int v7; // ecx@2
  bool v8; // bl@4
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v1 = OrderHdr::Pack(&hdr, &buf, 0);
  v2 = v1 + 8;
  v3 = operator new[](v1 + 8);
  buf = v3;
  v4 = (char *)v3;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 23;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_friendID;
  buf = (char *)buf + 4;
  v6 = (signed int)buf % 4;
  if ( (signed int)buf % 4 )
  {
    v7 = 4 - v6;
    if ( 4 != v6 )
    {
      do
      {
        *(_BYTE *)buf = 0;
        --v7;
        buf = (char *)buf + 1;
      }
      while ( v7 );
    }
  }
  v8 = Proto_UI::SendToWeenie(v4, v2);
  if ( !v8 )
    Proto_UI::UICounterFailedSend();
  return v8;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A5720) --------------------------------------------------------  // acclient.c:702376
bool __cdecl CM_Social::Event_SetDisplayCharacterTitle(unsigned int i_i_title)
{
  signed int v1; // eax@1
  int v2; // esi@1
  void *v3; // eax@1
  char *v4; // edi@1
  char *v5; // eax@1
  int v6; // eax@1
  int v7; // ecx@2
  bool v8; // bl@4
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v1 = OrderHdr::Pack(&hdr, &buf, 0);
  v2 = v1 + 8;
  v3 = operator new[](v1 + 8);
  buf = v3;
  v4 = (char *)v3;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 44;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_i_title;
  buf = (char *)buf + 4;
  v6 = (signed int)buf % 4;
  if ( (signed int)buf % 4 )
  {
    v7 = 4 - v6;
    if ( 4 != v6 )
    {
      do
      {
        *(_BYTE *)buf = 0;
        --v7;
        buf = (char *)buf + 1;
      }
      while ( v7 );
    }
  }
  v8 = Proto_UI::SendToWeenie(v4, v2);
  if ( !v8 )
    Proto_UI::UICounterFailedSend();
  return v8;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A57F0) --------------------------------------------------------  // acclient.c:702426
unsigned int __cdecl CM_Social::DispatchUI_SendClientContractTracker(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  int v4; // ecx@4
  void *v5; // esi@4
  int v6; // ecx@6
  char *v7; // eax@6
  int v8; // ST08_4@6
  int v9; // ST04_4@6
  ClientUISystem *v10; // ecx@6
  CContractTracker contractTracker; // [sp+4h] [bp-28h]@6

  if ( ui && ui->m_pUISystem )
  {
    v4 = *(_DWORD *)buf;
    v5 = buf;
    buf = (char *)buf + 4;
    if ( v4 == 789 )
    {
      CContractTracker::CContractTracker(&contractTracker);
      CContractTracker::UnPack(&contractTracker, &buf, size + (_BYTE *)v5 - (_BYTE *)buf);
      v6 = *(_DWORD *)buf;
      v7 = (char *)buf + 4;
      buf = v7;
      v8 = *(_DWORD *)v7;
      v9 = v6;
      v10 = ui->m_pUISystem;
      buf = v7 + 4;
      result = ClientUISystem::Handle_Social__SendClientContractTracker(&contractTracker, v9, v8);
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006A5880) --------------------------------------------------------  // acclient.c:702469
char __cdecl CM_Social::SendNotice_AddCharacterTitle(unsigned int i_i_title)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD279);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 440))(v4, i_i_title);
    }
  }
  return 1;
}

//----- (006A58D0) --------------------------------------------------------  // acclient.c:702495
char __cdecl CM_Social::SendNotice_ChatCommand_AddFriend(PStringBase<char> *i_friend_name)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD26D + 5));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, PStringBase<char> *))(*(_DWORD *)v4 + 444))(v4, i_friend_name);
    }
  }
  return 1;
}

//----- (006A5920) --------------------------------------------------------  // acclient.c:702521
char __cdecl CM_Social::SendNotice_ChatCommand_DisplayFriends(int i_onlineOnly)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD273);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 448))(v4, i_onlineOnly);
    }
  }
  return 1;
}

//----- (006A5970) --------------------------------------------------------  // acclient.c:702547
char __cdecl CM_Social::SendNotice_ChatCommand_RemoveAllFriends()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)&loc_4DD275);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 452))(v3);
    }
  }
  return 1;
}

//----- (006A59C0) --------------------------------------------------------  // acclient.c:702573
char __cdecl CM_Social::SendNotice_ChatCommand_RemoveFriend(PStringBase<char> *i_friend_name)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD273 + 1));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, PStringBase<char> *))(*(_DWORD *)v4 + 456))(v4, i_friend_name);
    }
  }
  return 1;
}

//----- (006A5A10) --------------------------------------------------------  // acclient.c:702599
char __cdecl CM_Social::SendNotice_SetDisplayCharacterTitle(unsigned int i_i_title)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD277 + 1));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 460))(v4, i_i_title);
    }
  }
  return 1;
}

//----- (006A5A60) --------------------------------------------------------  // acclient.c:702625
char __cdecl CM_Social::SendNotice_SetDisplayContractTracker(CContractTracker *i_contractTracker)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD27F);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, CContractTracker *))(*(_DWORD *)v4 + 464))(v4, i_contractTracker);
    }
  }
  return 1;
}

//----- (006A5AB0) --------------------------------------------------------  // acclient.c:702651
char __cdecl CM_Social::SendNotice_UpdateCharacterTitleTable(CharacterTitleTable *i_i_titleTable)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD277);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, CharacterTitleTable *))(*(_DWORD *)v4 + 468))(v4, i_i_titleTable);
    }
  }
  return 1;
}

//----- (006A5B00) --------------------------------------------------------  // acclient.c:702677
char __cdecl CM_Social::SendNotice_UpdateContractTracker(CContractTracker *i_contractTracker, int i_bDeleteContract)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD27F + 3));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, CContractTracker *, int))(*(_DWORD *)v5 + 472))(
          v5,
          i_contractTracker,
          i_bDeleteContract);
    }
  }
  return 1;
}

//----- (006A5B60) --------------------------------------------------------  // acclient.c:702706
char __cdecl CM_Social::SendNotice_UpdateContractTrackerTable(CContractTrackerTable *i_contractTrackerTable)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD27F + 2));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, CContractTrackerTable *))(*(_DWORD *)v4 + 476))(v4, i_contractTrackerTable);
    }
  }
  return 1;
}

//----- (006A5BB0) --------------------------------------------------------  // acclient.c:702732
char __cdecl CM_Social::SendNotice_UpdateFriendsList(FriendDataList *i_friendDataList, int i_updateType)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD26D + 2));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, FriendDataList *, int))(*(_DWORD *)v5 + 480))(v5, i_friendDataList, i_updateType);
    }
  }
  return 1;
}

//----- (006A5C10) --------------------------------------------------------  // acclient.c:702758
bool __cdecl CM_Social::Event_AddFriend(AC1Legacy::PStringBase<char> *i_friend_name)
{
  int v1; // esi@1
  int v2; // esi@1
  char *v3; // edi@1
  unsigned int v4; // ST04_4@1
  bool v5; // bl@1
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v1 = AC1Legacy::PStringBase<char>::Pack(i_friend_name, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 24;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_friend_name, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A5CD0) --------------------------------------------------------  // acclient.c:702788
unsigned int __cdecl CM_Social::DispatchUI_SendClientContractTrackerTable(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  int v4; // ecx@4
  void *v5; // esi@4
  ClientUISystem *v6; // ecx@6
  unsigned int v7; // esi@6
  CContractTrackerTable contractTrackerTable; // [sp+4h] [bp-18h]@6

  if ( ui && ui->m_pUISystem )
  {
    v4 = *(_DWORD *)buf;
    v5 = buf;
    buf = (char *)buf + 4;
    if ( v4 == 788 )
    {
      CContractTrackerTable::CContractTrackerTable(&contractTrackerTable);
      Body::UnPack((Body *)&contractTrackerTable, &buf, size + (_BYTE *)v5 - (_BYTE *)buf);
      v6 = ui->m_pUISystem;
      v7 = ClientUISystem::Handle_Social__SendClientContractTrackerTable(&contractTrackerTable);
      CContractTrackerTable::~CContractTrackerTable(&contractTrackerTable);
      result = v7;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006A5D50) --------------------------------------------------------  // acclient.c:702824
unsigned int __cdecl CM_Social::DispatchUI_CharacterTitleTable(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  int v4; // ecx@4
  void *v5; // esi@4
  ClientUISystem *v6; // ecx@6
  unsigned int v7; // esi@6
  CharacterTitleTable titleTable; // [sp+4h] [bp-1Ch]@6

  if ( ui && ui->m_pUISystem )
  {
    v4 = *(_DWORD *)buf;
    v5 = buf;
    buf = (char *)buf + 4;
    if ( v4 == 41 )
    {
      CharacterTitleTable::CharacterTitleTable(&titleTable);
      CharacterTitleTable::UnPack(&titleTable, &buf, size + (_BYTE *)v5 - (_BYTE *)buf);
      v6 = ui->m_pUISystem;
      v7 = ClientUISystem::Handle_Social__CharacterTitleTable(&titleTable);
      CharacterTitleTable::~CharacterTitleTable(&titleTable);
      result = v7;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006A5DD0) --------------------------------------------------------  // acclient.c:702860
unsigned int __cdecl CM_Social::DispatchUI_FriendsUpdate(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  void *v4; // eax@4
  char *v5; // ecx@4
  bool v6; // zf@4
  int v7; // ST04_4@6
  ClientUISystem *v8; // ecx@6
  unsigned int v9; // esi@6
  FriendDataList friendDataList; // [sp+4h] [bp-14h]@6

  if ( ui && ui->m_pUISystem )
  {
    v4 = buf;
    v5 = (char *)buf + 4;
    v6 = *(_DWORD *)buf == 33;
    buf = (char *)buf + 4;
    if ( v6 )
    {
      friendDataList._head = 0;
      friendDataList._tail = 0;
      friendDataList._num_elements = 0;
      friendDataList.vfptr = (AC1Legacy::List<FriendData>Vtbl *)&FriendDataList::vftable;
      friendDataList.vfptr = (PackObjVtbl *)&PList<FriendData>::vftable;
      PList<FriendData>::UnPack((PList<FriendData> *)&friendDataList.vfptr, &buf, size + (_BYTE *)v4 - v5);
      v7 = *(_DWORD *)buf;
      v8 = ui->m_pUISystem;
      buf = (char *)buf + 4;
      v9 = ClientUISystem::Handle_Social__FriendsUpdate(&friendDataList, v7);
      friendDataList.vfptr = (PackObjVtbl *)&PackObj::vftable;
      friendDataList.vfptr = (AC1Legacy::List<FriendData>Vtbl *)AC1Legacy::List<FriendData>::vftable;
      AC1Legacy::List<FriendData>::flush((AC1Legacy::List<FriendData> *)&friendDataList.vfptr);
      result = v9;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A410C: using guessed type int (__thiscall *AC1Legacy::List<FriendData>::vftable[2])(void *, char);
// 7A413C: using guessed type void *PList<FriendData>::vftable;
// 7A4150: using guessed type int (__thiscall *FriendDataList::vftable)(void *, char);

//----- (00721CA0) --------------------------------------------------------  // acclient.c:819537
void sub_721CA0()
{
  flt_8F9EF8 = 1000.0 + 1.0;
}

//----- (00721CC0) --------------------------------------------------------  // acclient.c:819543
void sub_721CC0()
{
  flt_8F9EFC = 24.0 * 8.0;
}

//----- (00721CE0) --------------------------------------------------------  // acclient.c:819549
void sub_721CE0()
{
  flt_8F9F00 = 24.0 * 0.5;
}

//----- (00721D00) --------------------------------------------------------  // acclient.c:819555
int sub_721D00()
{
  return atexit(nullsub_449);
}

//----- (00721D10) --------------------------------------------------------  // acclient.c:819561
int sub_721D10()
{
  return atexit(nullsub_450);
}

//----- (00721D20) --------------------------------------------------------  // acclient.c:819567
int sub_721D20()
{
  return atexit(nullsub_451);
}

//----- (00721D30) --------------------------------------------------------  // acclient.c:819573
void sub_721D30()
{
  flt_8F9F04 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00721D50) --------------------------------------------------------  // acclient.c:819579
void sub_721D50()
{
  dbl_8F9F08 = 1.0 / 30.0;
}

//----- (00721D70) --------------------------------------------------------  // acclient.c:819585
void _E110_86()
{
  dbl_8F9F10 = 1.0 / 5.0;
}

//----- (00721D90) --------------------------------------------------------  // acclient.c:819591
void sub_721D90()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F9F18, PFID_A8R8G8B8);
}

//----- (00721DA0) --------------------------------------------------------  // acclient.c:819597
void sub_721DA0()
{
  dword_8F9F50 = 1024;
}

//----- (00721DB0) --------------------------------------------------------  // acclient.c:819603
void _E117_93()
{
  dword_8F9F54 = 0x7FFF;
}

//----- (00721DC0) --------------------------------------------------------  // acclient.c:819609
int _E119_38()
{
  const int result; // eax@1

  result = dword_8F9F50;
  dword_8F9F58 = dword_8F9F50;
  return result;
}

//----- (00721DD0) --------------------------------------------------------  // acclient.c:819619
int _E121_98()
{
  return atexit(nullsub_447);
}

//----- (00721DE0) --------------------------------------------------------  // acclient.c:819625
int sub_721DE0()
{
  return atexit(nullsub_448);
}

