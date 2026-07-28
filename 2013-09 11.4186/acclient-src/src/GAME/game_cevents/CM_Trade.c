/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Trade
   Object     : GAME\game_cevents\CM_Trade.obj
   Functions  : 42
   Addresses  : 006ACDF0 - 00722BA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006ACDF0) --------------------------------------------------------  // acclient.c:710049
unsigned int __cdecl CM_Trade::DispatchUI_Recv_AcceptTrade(UIQueueManager *ui, void *buf)
{
  ClientTradeSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pTradeSystem) != 0 && *(_DWORD *)buf == 514 )
    result = ClientTradeSystem::Handle_Trade__Recv_AcceptTrade(v2, *((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006ACE20) --------------------------------------------------------  // acclient.c:710062
unsigned int __cdecl CM_Trade::DispatchUI_Recv_AddToTrade(UIQueueManager *ui, void *buf)
{
  ClientTradeSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pTradeSystem) != 0 && *(_DWORD *)buf == 512 )
    result = ClientTradeSystem::Handle_Trade__Recv_AddToTrade(
               v2,
               *((_DWORD *)buf + 1),
               *((_DWORD *)buf + 2),
               *((_DWORD *)buf + 3));
  else
    result = 0;
  return result;
}

//----- (006ACE60) --------------------------------------------------------  // acclient.c:710079
unsigned int __cdecl CM_Trade::DispatchUI_Recv_ClearTradeAcceptance(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pTradeSystem && *(_DWORD *)buf == 520 )
    result = ClientTradeSystem::Handle_Trade__Recv_ClearTradeAcceptance();
  else
    result = 0;
  return result;
}

//----- (006ACE90) --------------------------------------------------------  // acclient.c:710091
unsigned int __cdecl CM_Trade::DispatchUI_Recv_CloseTrade(UIQueueManager *ui, void *buf)
{
  ClientTradeSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pTradeSystem) != 0 && *(_DWORD *)buf == 511 )
    result = ClientTradeSystem::Handle_Trade__Recv_CloseTrade(v2, *((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006ACEC0) --------------------------------------------------------  // acclient.c:710104
unsigned int __cdecl CM_Trade::DispatchUI_Recv_DeclineTrade(UIQueueManager *ui, void *buf)
{
  ClientTradeSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pTradeSystem) != 0 && *(_DWORD *)buf == 515 )
    result = ClientTradeSystem::Handle_Trade__Recv_DeclineTrade(v2, *((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006ACEF0) --------------------------------------------------------  // acclient.c:710117
unsigned int __cdecl CM_Trade::DispatchUI_Recv_OpenTrade(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pTradeSystem && *(_DWORD *)buf == 510 )
    result = ClientTradeSystem::Handle_Trade__Recv_OpenTrade(*((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006ACF20) --------------------------------------------------------  // acclient.c:710129
unsigned int __cdecl CM_Trade::DispatchUI_Recv_RegisterTrade(UIQueueManager *ui, void *buf)
{
  ClientTradeSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pTradeSystem) != 0 && *(_DWORD *)buf == 509 )
    result = ClientTradeSystem::Handle_Trade__Recv_RegisterTrade(
               v2,
               *((_DWORD *)buf + 1),
               *((_DWORD *)buf + 2),
               *(long double *)((char *)buf + 12));
  else
    result = 0;
  return result;
}

//----- (006ACF80) --------------------------------------------------------  // acclient.c:710146
unsigned int __cdecl CM_Trade::DispatchUI_Recv_RemoveFromTrade(UIQueueManager *ui, void *buf)
{
  ClientTradeSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pTradeSystem) != 0 && *(_DWORD *)buf == 513 )
    result = ClientTradeSystem::Handle_Trade__Recv_RemoveFromTrade(v2, *((_DWORD *)buf + 1), *((_DWORD *)buf + 2));
  else
    result = 0;
  return result;
}

//----- (006ACFB0) --------------------------------------------------------  // acclient.c:710159
unsigned int __cdecl CM_Trade::DispatchUI_Recv_ResetTrade(UIQueueManager *ui, void *buf)
{
  ClientTradeSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pTradeSystem) != 0 && *(_DWORD *)buf == 517 )
    result = ClientTradeSystem::Handle_Trade__Recv_ResetTrade(v2, *((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006ACFE0) --------------------------------------------------------  // acclient.c:710172
unsigned int __cdecl CM_Trade::DispatchUI_Recv_TradeFailure(UIQueueManager *ui, void *buf)
{
  ClientTradeSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pTradeSystem) != 0 && *(_DWORD *)buf == 519 )
    result = ClientTradeSystem::Handle_Trade__Recv_TradeFailure(v2, *((_DWORD *)buf + 1), *((_DWORD *)buf + 2));
  else
    result = 0;
  return result;
}

//----- (006AD010) --------------------------------------------------------  // acclient.c:710185
bool __cdecl CM_Trade::Event_AcceptTrade(Trade *i_stuff)
{
  PackObjVtbl *v1; // eax@1
  int v2; // esi@1
  int v3; // esi@1
  char *v4; // ebx@1
  PackObjVtbl *v5; // edx@1
  int v6; // ecx@1
  bool v7; // bl@1
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  v1 = i_stuff->vfptr;
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = ((int (__thiscall *)(Trade *, void **, _DWORD))v1->Pack)(i_stuff, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v3);
  v4 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 506;
  v5 = i_stuff->vfptr;
  v6 = v4 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  ((void (__thiscall *)(Trade *, void **, int))v5->Pack)(i_stuff, &buf, v3 + v6);
  v7 = Proto_UI::SendToWeenie(v4, v3);
  if ( !v7 )
    Proto_UI::UICounterFailedSend();
  return v7;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AD0D0) --------------------------------------------------------  // acclient.c:710219
bool __cdecl CM_Trade::Event_AddToTrade(unsigned int i_item, unsigned int i_loc)
{
  signed int v2; // eax@1
  int v3; // esi@1
  void *v4; // eax@1
  char *v5; // edi@1
  char *v6; // eax@1
  char *v7; // eax@1
  bool v8; // zf@1
  unsigned int v9; // ecx@1
  int v10; // edx@4
  int v11; // eax@6
  int v12; // ecx@7
  bool v13; // bl@9
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = OrderHdr::Pack(&hdr, &buf, 0);
  v3 = v2 + 12;
  v4 = operator new[](v2 + 12);
  buf = v4;
  v5 = (char *)v4;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 504;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_item;
  v7 = (char *)buf + 4;
  v9 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v8 = v9 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v9 = (((_BYTE)v9 - 1) | 0xFFFFFFFC) + 1;
    v8 = v9 == 0;
  }
  if ( !v8 )
  {
    v10 = 4 - v9;
    if ( 4 != v9 )
    {
      do
      {
        *v7 = 0;
        v7 = (char *)buf + 1;
        --v10;
        buf = (char *)buf + 1;
      }
      while ( v10 );
    }
  }
  *(_DWORD *)v7 = i_loc;
  buf = (char *)buf + 4;
  v11 = (signed int)buf % 4;
  if ( (signed int)buf % 4 )
  {
    v12 = 4 - v11;
    if ( 4 != v11 )
    {
      do
      {
        *(_BYTE *)buf = 0;
        --v12;
        buf = (char *)buf + 1;
      }
      while ( v12 );
    }
  }
  v13 = Proto_UI::SendToWeenie(v5, v3);
  if ( !v13 )
    Proto_UI::UICounterFailedSend();
  return v13;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AD1E0) --------------------------------------------------------  // acclient.c:710298
bool __cdecl CM_Trade::Event_CloseTradeNegotiations()
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
  *(_DWORD *)buf = 503;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AD270) --------------------------------------------------------  // acclient.c:710323
bool __cdecl CM_Trade::Event_DeclineTrade()
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
  *(_DWORD *)buf = 507;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AD300) --------------------------------------------------------  // acclient.c:710348
bool __cdecl CM_Trade::Event_OpenTradeNegotiations(unsigned int i_other)
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
  *(_DWORD *)buf = 502;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_other;
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

//----- (006AD3D0) --------------------------------------------------------  // acclient.c:710398
bool __cdecl CM_Trade::Event_ResetTrade()
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
  *(_DWORD *)buf = 516;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AD460) --------------------------------------------------------  // acclient.c:710423
char __cdecl CM_Trade::SendNotice_AcceptTrade(unsigned int i_source)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD232 + 3));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 484))(v4, i_source);
    }
  }
  return 1;
}

//----- (006AD4B0) --------------------------------------------------------  // acclient.c:710449
char __cdecl CM_Trade::SendNotice_AddItemToTrade(unsigned int i_item, unsigned int i_id, unsigned int i_loc)
{
  gmGlobalEventHandler *v3; // eax@1
  int v4; // eax@1
  int v5; // edi@2
  int v6; // esi@3
  bool v7; // zf@3

  v3 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v4 = (int)v3->vfptr->GetNoticeHandlers((NoticeRegistrar *)v3, (unsigned int)((char *)&loc_4DD232 + 1));
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    while ( v5 )
    {
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 == 0;
      v5 = *(_DWORD *)(v5 + 4);
      if ( !v7 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v6)(v6) )
        (*(void (__thiscall **)(int, unsigned int, unsigned int, unsigned int))(*(_DWORD *)v6 + 488))(
          v6,
          i_item,
          i_id,
          i_loc);
    }
  }
  return 1;
}

//----- (006AD510) --------------------------------------------------------  // acclient.c:710479
char __cdecl CM_Trade::SendNotice_ClearTradeAcceptance()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)&loc_4DD239);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 492))(v3);
    }
  }
  return 1;
}

//----- (006AD560) --------------------------------------------------------  // acclient.c:710505
char __cdecl CM_Trade::SendNotice_CloseTrade(unsigned int i_etype)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD232);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 496))(v4, i_etype);
    }
  }
  return 1;
}

//----- (006AD5B0) --------------------------------------------------------  // acclient.c:710531
char __cdecl CM_Trade::SendNotice_DeclineTrade(unsigned int i_source)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD236);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 500))(v4, i_source);
    }
  }
  return 1;
}

//----- (006AD600) --------------------------------------------------------  // acclient.c:710557
char __cdecl CM_Trade::SendNotice_OpenTrade(unsigned int i_source)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD231);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 504))(v4, i_source);
    }
  }
  return 1;
}

//----- (006AD650) --------------------------------------------------------  // acclient.c:710583
char __cdecl CM_Trade::SendNotice_RegisterTrade(unsigned int i_initiator, unsigned int i_partner, long double i_stamp)
{
  gmGlobalEventHandler *v3; // eax@1
  int v4; // eax@1
  int v5; // edi@2
  int v6; // esi@3
  bool v7; // zf@3

  v3 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v4 = (int)v3->vfptr->GetNoticeHandlers((NoticeRegistrar *)v3, (unsigned int)gmKeyboardUI::ListenToElementMessage);
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    while ( v5 )
    {
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 == 0;
      v5 = *(_DWORD *)(v5 + 4);
      if ( !v7 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v6)(v6) )
        (*(void (__thiscall **)(int, unsigned int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)v6 + 508))(
          v6,
          i_initiator,
          i_partner,
          LODWORD(i_stamp),
          HIDWORD(i_stamp));
    }
  }
  return 1;
}

//----- (006AD6B0) --------------------------------------------------------  // acclient.c:710614
char __cdecl CM_Trade::SendNotice_RemoveItemFromTrade(unsigned int i_item, unsigned int i_id)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD232 + 2));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, unsigned int))(*(_DWORD *)v5 + 512))(v5, i_item, i_id);
    }
  }
  return 1;
}

//----- (006AD710) --------------------------------------------------------  // acclient.c:710640
char __cdecl CM_Trade::SendNotice_ResetTrade(unsigned int i_source)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD236 + 1));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 516))(v4, i_source);
    }
  }
  return 1;
}

//----- (006AD760) --------------------------------------------------------  // acclient.c:710666
char __cdecl CM_Trade::SendNotice_TradeAnItemForDummies(unsigned int i_iidObject)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD23A);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 520))(v4, i_iidObject);
    }
  }
  return 1;
}

//----- (006AD7B0) --------------------------------------------------------  // acclient.c:710692
char __cdecl CM_Trade::SendNotice_TradeFailure(unsigned int i_item, unsigned int i_etype)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD236 + 2));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, unsigned int))(*(_DWORD *)v5 + 524))(v5, i_item, i_etype);
    }
  }
  return 1;
}

//----- (00722A60) --------------------------------------------------------  // acclient.c:820497
void sub_722A60()
{
  flt_8FA448 = 1000.0 + 1.0;
}

//----- (00722A80) --------------------------------------------------------  // acclient.c:820503
void sub_722A80()
{
  flt_8FA44C = 24.0 * 8.0;
}

//----- (00722AA0) --------------------------------------------------------  // acclient.c:820509
void sub_722AA0()
{
  flt_8FA450 = 24.0 * 0.5;
}

//----- (00722AC0) --------------------------------------------------------  // acclient.c:820515
int sub_722AC0()
{
  return atexit(nullsub_454);
}

//----- (00722AD0) --------------------------------------------------------  // acclient.c:820521
int sub_722AD0()
{
  return atexit(nullsub_455);
}

//----- (00722AE0) --------------------------------------------------------  // acclient.c:820527
int sub_722AE0()
{
  return atexit(nullsub_456);
}

//----- (00722AF0) --------------------------------------------------------  // acclient.c:820533
void sub_722AF0()
{
  flt_8FA454 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00722B10) --------------------------------------------------------  // acclient.c:820539
void sub_722B10()
{
  dbl_8FA458 = 1.0 / 30.0;
}

//----- (00722B30) --------------------------------------------------------  // acclient.c:820545
void _E110_94()
{
  dbl_8FA460 = 1.0 / 5.0;
}

//----- (00722B50) --------------------------------------------------------  // acclient.c:820551
void sub_722B50()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FA468, PFID_A8R8G8B8);
}

//----- (00722B60) --------------------------------------------------------  // acclient.c:820557
void sub_722B60()
{
  dword_8FA4A0 = 1024;
}

//----- (00722B70) --------------------------------------------------------  // acclient.c:820563
void sub_722B70()
{
  dword_8FA4A4 = 0x7FFF;
}

//----- (00722B80) --------------------------------------------------------  // acclient.c:820569
int _E119_46()
{
  const int result; // eax@1

  result = dword_8FA4A0;
  dword_8FA4A8 = dword_8FA4A0;
  return result;
}

//----- (00722B90) --------------------------------------------------------  // acclient.c:820579
int sub_722B90()
{
  return atexit(nullsub_452);
}

//----- (00722BA0) --------------------------------------------------------  // acclient.c:820585
int sub_722BA0()
{
  return atexit(nullsub_453);
}

