/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Fellowship
   Object     : GAME\game_cevents\CM_Fellowship.obj
   Functions  : 37
   Addresses  : 006A5E80 - 00721F30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006A5E80) --------------------------------------------------------  // acclient.c:702911
unsigned int __cdecl CM_Fellowship::DispatchUI_Disband(UIQueueManager *ui, void *buf)
{
  ClientFellowshipSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pFellowshipSystem) != 0 && *(_DWORD *)buf == 703 )
    result = ClientFellowshipSystem::Handle_Fellowship__Disband(v2);
  else
    result = 0;
  return result;
}

//----- (006A5EB0) --------------------------------------------------------  // acclient.c:702924
unsigned int __cdecl CM_Fellowship::DispatchUI_Dismiss(UIQueueManager *ui, void *buf)
{
  ClientFellowshipSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pFellowshipSystem) != 0 && *(_DWORD *)buf == 164 )
    result = ClientFellowshipSystem::Handle_Fellowship__Dismiss(v2, *((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006A5EE0) --------------------------------------------------------  // acclient.c:702937
int __cdecl CM_Fellowship::DispatchUI_FellowStatsDone(UIQueueManager *ui, void *buf)
{
  int result; // eax@4

  if ( ui && ui->m_pFellowshipSystem && *(_DWORD *)buf == 458 )
    result = InfoRegion::GetVitaeModifier(*((Enchantment **)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006A5F10) --------------------------------------------------------  // acclient.c:702949
int __cdecl CM_Fellowship::DispatchUI_FellowUpdateDone(UIQueueManager *ui, void *buf)
{
  int result; // eax@4

  if ( ui && ui->m_pFellowshipSystem && *(_DWORD *)buf == 457 )
    result = InfoRegion::GetVitaeModifier(*((Enchantment **)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006A5F40) --------------------------------------------------------  // acclient.c:702961
unsigned int __cdecl CM_Fellowship::DispatchUI_Quit(UIQueueManager *ui, void *buf)
{
  ClientFellowshipSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pFellowshipSystem) != 0 && *(_DWORD *)buf == 163 )
    result = ClientFellowshipSystem::Handle_Fellowship__Quit(v2, *((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006A5F70) --------------------------------------------------------  // acclient.c:702974
bool __cdecl CM_Fellowship::Event_AssignNewLeader(unsigned int i_target)
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
  *(_DWORD *)buf = 656;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_target;
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

//----- (006A6040) --------------------------------------------------------  // acclient.c:703024
bool __cdecl CM_Fellowship::Event_ChangeFellowOpeness(int i_open)
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
  *(_DWORD *)buf = 657;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_open;
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

//----- (006A6110) --------------------------------------------------------  // acclient.c:703074
bool __cdecl CM_Fellowship::Event_Dismiss(unsigned int i_target)
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
  *(_DWORD *)buf = 164;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_target;
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

//----- (006A61E0) --------------------------------------------------------  // acclient.c:703124
bool __cdecl CM_Fellowship::Event_Quit(int i_disband)
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
  *(_DWORD *)buf = 163;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_disband;
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

//----- (006A62B0) --------------------------------------------------------  // acclient.c:703174
bool __cdecl CM_Fellowship::Event_Recruit(unsigned int i_target)
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
  *(_DWORD *)buf = 165;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_target;
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

//----- (006A6380) --------------------------------------------------------  // acclient.c:703224
bool __cdecl CM_Fellowship::Event_UpdateRequest(int i_on)
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
  *(_DWORD *)buf = 166;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_on;
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

//----- (006A6450) --------------------------------------------------------  // acclient.c:703274
char __cdecl CM_Fellowship::SendNotice_FellowAdded(unsigned int i_iidPlayer)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD245 + 1));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 224))(v4, i_iidPlayer);
    }
  }
  return 1;
}

//----- (006A64A0) --------------------------------------------------------  // acclient.c:703300
char __cdecl CM_Fellowship::SendNotice_FellowDismissed(unsigned int i_iidPlayer)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD213);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 228))(v4, i_iidPlayer);
    }
  }
  return 1;
}

//----- (006A64F0) --------------------------------------------------------  // acclient.c:703326
char __cdecl CM_Fellowship::SendNotice_FellowQuit(unsigned int i_iidPlayer)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD211 + 1));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 232))(v4, i_iidPlayer);
    }
  }
  return 1;
}

//----- (006A6540) --------------------------------------------------------  // acclient.c:703352
char __cdecl CM_Fellowship::SendNotice_FellowUpdated(unsigned int i_iidPlayer, Fellow *i_fellow, unsigned int i_uiUpdateType)
{
  gmGlobalEventHandler *v3; // eax@1
  int v4; // eax@1
  int v5; // edi@2
  int v6; // esi@3
  bool v7; // zf@3

  v3 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v4 = (int)v3->vfptr->GetNoticeHandlers((NoticeRegistrar *)v3, (unsigned int)((char *)&loc_4DD213 + 1));
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    while ( v5 )
    {
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 == 0;
      v5 = *(_DWORD *)(v5 + 4);
      if ( !v7 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v6)(v6) )
        (*(void (__thiscall **)(int, unsigned int, Fellow *, unsigned int))(*(_DWORD *)v6 + 236))(
          v6,
          i_iidPlayer,
          i_fellow,
          i_uiUpdateType);
    }
  }
  return 1;
}

//----- (006A65A0) --------------------------------------------------------  // acclient.c:703382
char __cdecl CM_Fellowship::SendNotice_FellowshipDisbanded()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)&loc_4DD211);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 240))(v3);
    }
  }
  return 1;
}

//----- (006A65F0) --------------------------------------------------------  // acclient.c:703408
char __cdecl CM_Fellowship::SendNotice_FellowshipLeaderChanged(unsigned int i_iidNewLeader, unsigned int i_iidOldLeader)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD245 + 2));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, unsigned int))(*(_DWORD *)v5 + 244))(
          v5,
          i_iidNewLeader,
          i_iidOldLeader);
    }
  }
  return 1;
}

//----- (006A6650) --------------------------------------------------------  // acclient.c:703437
char __cdecl CM_Fellowship::SendNotice_FellowshipRequest(AC1Legacy::PStringBase<char> *i_strRequestor, unsigned int i_uiContextID)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)&loc_4DD20F);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, AC1Legacy::PStringBase<char> *, unsigned int))(*(_DWORD *)v5 + 248))(
          v5,
          i_strRequestor,
          i_uiContextID);
    }
  }
  return 1;
}

//----- (006A66B0) --------------------------------------------------------  // acclient.c:703466
char __cdecl CM_Fellowship::SendNotice_FellowshipUpdate(CFellowship *i_fellowship)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD20F + 1));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, CFellowship *))(*(_DWORD *)v4 + 252))(v4, i_fellowship);
    }
  }
  return 1;
}

//----- (006A6700) --------------------------------------------------------  // acclient.c:703492
unsigned int __cdecl CM_Fellowship::DispatchUI_UpdateFellow(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  unsigned int v4; // ecx@4
  void *v5; // esi@4
  char *v6; // eax@4
  unsigned int v7; // edi@6
  unsigned int v8; // ST08_4@6
  ClientFellowshipSystem *v9; // ecx@6
  unsigned int v10; // esi@6
  Fellow fellow; // [sp+4h] [bp-30h]@6

  if ( ui && ui->m_pFellowshipSystem )
  {
    v4 = *(_DWORD *)buf;
    v5 = buf;
    v6 = (char *)buf + 4;
    buf = (char *)buf + 4;
    if ( v4 == 704 )
    {
      v7 = *(_DWORD *)v6;
      buf = v6 + 4;
      Fellow::Fellow(&fellow);
      Fellow::UnPack(&fellow, &buf, size + (_BYTE *)v5 - (_BYTE *)buf);
      v8 = *(_DWORD *)buf;
      v9 = ui->m_pFellowshipSystem;
      buf = (char *)buf + 4;
      v10 = ClientFellowshipSystem::Handle_Fellowship__UpdateFellow(v9, v7, &fellow, v8);
      Fellow::~Fellow(&fellow);
      result = v10;
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

//----- (006A67A0) --------------------------------------------------------  // acclient.c:703536
bool __cdecl CM_Fellowship::Event_Create(AC1Legacy::PStringBase<char> *i_name, int i_share_xp)
{
  int v2; // esi@1
  int v3; // esi@1
  void *v4; // eax@1
  char *v5; // ebx@1
  unsigned int v6; // ST04_4@1
  int v7; // eax@1
  int v8; // ecx@2
  bool v9; // bl@4
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = AC1Legacy::PStringBase<char>::Pack(i_name, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v4 = operator new[](v3);
  buf = v4;
  v5 = (char *)v4;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 162;
  v6 = v3 + v5 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_name, &buf, v6);
  *(_DWORD *)buf = i_share_xp;
  buf = (char *)buf + 4;
  v7 = (signed int)buf % 4;
  if ( (signed int)buf % 4 )
  {
    v8 = 4 - v7;
    if ( 4 != v7 )
    {
      do
      {
        *(_BYTE *)buf = 0;
        --v8;
        buf = (char *)buf + 1;
      }
      while ( v8 );
    }
  }
  v9 = Proto_UI::SendToWeenie(v5, v3);
  if ( !v9 )
    Proto_UI::UICounterFailedSend();
  return v9;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A68A0) --------------------------------------------------------  // acclient.c:703587
unsigned int __cdecl CM_Fellowship::DispatchUI_FullUpdate(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  int v4; // ecx@4
  void *v5; // esi@4
  unsigned int v6; // esi@6
  CFellowship fellows; // [sp+4h] [bp-44h]@6

  if ( ui && ui->m_pFellowshipSystem )
  {
    v4 = *(_DWORD *)buf;
    v5 = buf;
    buf = (char *)buf + 4;
    if ( v4 == 702 )
    {
      CFellowship::CFellowship(&fellows);
      Fellowship::UnPack((Fellowship *)&fellows.vfptr, &buf, size + (_BYTE *)v5 - (_BYTE *)buf);
      v6 = ClientFellowshipSystem::Handle_Fellowship__FullUpdate(ui->m_pFellowshipSystem, &fellows);
      Fellowship::~Fellowship((Fellowship *)&fellows.vfptr);
      result = v6;
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

//----- (00721DF0) --------------------------------------------------------  // acclient.c:819631
void sub_721DF0()
{
  flt_8F9F80 = 1000.0 + 1.0;
}

//----- (00721E10) --------------------------------------------------------  // acclient.c:819637
void sub_721E10()
{
  flt_8F9F84 = 24.0 * 8.0;
}

//----- (00721E30) --------------------------------------------------------  // acclient.c:819643
void sub_721E30()
{
  flt_8F9F88 = 24.0 * 0.5;
}

//----- (00721E50) --------------------------------------------------------  // acclient.c:819649
int sub_721E50()
{
  return atexit(nullsub_402);
}

//----- (00721E60) --------------------------------------------------------  // acclient.c:819655
int sub_721E60()
{
  return atexit(nullsub_403);
}

//----- (00721E70) --------------------------------------------------------  // acclient.c:819661
int sub_721E70()
{
  return atexit(nullsub_404);
}

//----- (00721E80) --------------------------------------------------------  // acclient.c:819667
void sub_721E80()
{
  flt_8F9F8C = 0.00019999999 * 3.0 + 0.1;
}

//----- (00721EA0) --------------------------------------------------------  // acclient.c:819673
void sub_721EA0()
{
  dbl_8F9F90 = 1.0 / 30.0;
}

//----- (00721EC0) --------------------------------------------------------  // acclient.c:819679
void _E110_87()
{
  dbl_8F9F98 = 1.0 / 5.0;
}

//----- (00721EE0) --------------------------------------------------------  // acclient.c:819685
void sub_721EE0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F9FA0, PFID_A8R8G8B8);
}

//----- (00721EF0) --------------------------------------------------------  // acclient.c:819691
void sub_721EF0()
{
  dword_8F9FD8 = 1024;
}

//----- (00721F00) --------------------------------------------------------  // acclient.c:819697
void _E117_94()
{
  dword_8F9FDC = 0x7FFF;
}

//----- (00721F10) --------------------------------------------------------  // acclient.c:819703
int _E119_39()
{
  const int result; // eax@1

  result = dword_8F9FD8;
  dword_8F9FE0 = dword_8F9FD8;
  return result;
}

//----- (00721F20) --------------------------------------------------------  // acclient.c:819713
int sub_721F20()
{
  return atexit(nullsub_400);
}

//----- (00721F30) --------------------------------------------------------  // acclient.c:819719
int sub_721F30()
{
  return atexit(nullsub_401);
}

