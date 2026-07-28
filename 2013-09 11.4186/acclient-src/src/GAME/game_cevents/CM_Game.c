/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Game
   Object     : GAME\game_cevents\CM_Game.obj
   Functions  : 35
   Addresses  : 006A88F0 - 00722430 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006A88F0) --------------------------------------------------------  // acclient.c:705428
unsigned int __cdecl CM_Game::DispatchUI_Recv_GameOver(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pMiniGameSystem && *(_DWORD *)buf == 652 )
    result = ClientMiniGameSystem::Handle_Game__Recv_GameOver(*((_DWORD *)buf + 1), *((_DWORD *)buf + 2));
  else
    result = 0;
  return result;
}

//----- (006A8920) --------------------------------------------------------  // acclient.c:705440
unsigned int __cdecl CM_Game::DispatchUI_Recv_JoinGameResponse(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pMiniGameSystem && *(_DWORD *)buf == 641 )
    result = ClientMiniGameSystem::Handle_Game__Recv_JoinGameResponse(*((_DWORD *)buf + 1), *((_DWORD *)buf + 2));
  else
    result = 0;
  return result;
}

//----- (006A8950) --------------------------------------------------------  // acclient.c:705452
unsigned int __cdecl CM_Game::DispatchUI_Recv_MoveResponse(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pMiniGameSystem && *(_DWORD *)buf == 643 )
    result = ClientMiniGameSystem::Handle_Game__Recv_MoveResponse(*((_DWORD *)buf + 1), *((_DWORD *)buf + 2));
  else
    result = 0;
  return result;
}

//----- (006A8980) --------------------------------------------------------  // acclient.c:705464
unsigned int __cdecl CM_Game::DispatchUI_Recv_OppenentStalemateState(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pMiniGameSystem && *(_DWORD *)buf == 645 )
    result = ClientMiniGameSystem::Handle_Game__Recv_OppenentStalemateState(
               *((_DWORD *)buf + 1),
               *((_DWORD *)buf + 2),
               *((_DWORD *)buf + 3));
  else
    result = 0;
  return result;
}

//----- (006A89C0) --------------------------------------------------------  // acclient.c:705479
unsigned int __cdecl CM_Game::DispatchUI_Recv_StartGame(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pMiniGameSystem && *(_DWORD *)buf == 642 )
    result = ClientMiniGameSystem::Handle_Game__Recv_StartGame(*((_DWORD *)buf + 1), *((_DWORD *)buf + 2));
  else
    result = 0;
  return result;
}

//----- (006A89F0) --------------------------------------------------------  // acclient.c:705491
bool __cdecl CM_Game::Event_Join(unsigned int i_idGame, unsigned int i_iWhichTeam)
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
  *(_DWORD *)buf = 617;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_idGame;
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
  *(_DWORD *)v7 = i_iWhichTeam;
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

//----- (006A8B00) --------------------------------------------------------  // acclient.c:705570
bool __cdecl CM_Game::Event_Move(int i_xFrom, int i_yFrom, int i_xTo, int i_yTo)
{
  signed int v4; // eax@1
  int v5; // esi@1
  void *v6; // eax@1
  char *v7; // edi@1
  char *v8; // eax@1
  char *v9; // eax@1
  bool v10; // zf@1
  unsigned int v11; // ecx@1
  int v12; // edx@4
  char *v13; // eax@6
  bool v14; // zf@6
  unsigned int v15; // ecx@6
  int v16; // edx@9
  char *v17; // eax@11
  bool v18; // zf@11
  unsigned int v19; // ecx@11
  int v20; // edx@14
  int v21; // eax@16
  int v22; // ecx@17
  bool v23; // bl@19
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v4 = OrderHdr::Pack(&hdr, &buf, 0);
  v5 = v4 + 20;
  v6 = operator new[](v4 + 20);
  buf = v6;
  v7 = (char *)v6;
  OrderHdr::Pack(&hdr, &buf, v5);
  *(_DWORD *)buf = 619;
  v8 = (char *)buf + 4;
  buf = v8;
  *(_DWORD *)v8 = i_xFrom;
  v9 = (char *)buf + 4;
  v11 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v10 = v11 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v11 = (((_BYTE)v11 - 1) | 0xFFFFFFFC) + 1;
    v10 = v11 == 0;
  }
  if ( !v10 )
  {
    v12 = 4 - v11;
    if ( 4 != v11 )
    {
      do
      {
        *v9 = 0;
        v9 = (char *)buf + 1;
        --v12;
        buf = (char *)buf + 1;
      }
      while ( v12 );
    }
  }
  *(_DWORD *)v9 = i_yFrom;
  v13 = (char *)buf + 4;
  v15 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v14 = v15 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v15 = (((_BYTE)v15 - 1) | 0xFFFFFFFC) + 1;
    v14 = v15 == 0;
  }
  if ( !v14 )
  {
    v16 = 4 - v15;
    if ( 4 != v15 )
    {
      do
      {
        *v13 = 0;
        v13 = (char *)buf + 1;
        --v16;
        buf = (char *)buf + 1;
      }
      while ( v16 );
    }
  }
  *(_DWORD *)v13 = i_xTo;
  v17 = (char *)buf + 4;
  v19 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v18 = v19 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v19 = (((_BYTE)v19 - 1) | 0xFFFFFFFC) + 1;
    v18 = v19 == 0;
  }
  if ( !v18 )
  {
    v20 = 4 - v19;
    if ( 4 != v19 )
    {
      do
      {
        *v17 = 0;
        v17 = (char *)buf + 1;
        --v20;
        buf = (char *)buf + 1;
      }
      while ( v20 );
    }
  }
  *(_DWORD *)v17 = i_yTo;
  buf = (char *)buf + 4;
  v21 = (signed int)buf % 4;
  if ( (signed int)buf % 4 )
  {
    v22 = 4 - v21;
    if ( 4 != v21 )
    {
      do
      {
        *(_BYTE *)buf = 0;
        --v22;
        buf = (char *)buf + 1;
      }
      while ( v22 );
    }
  }
  v23 = Proto_UI::SendToWeenie(v7, v5);
  if ( !v23 )
    Proto_UI::UICounterFailedSend();
  return v23;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A8C90) --------------------------------------------------------  // acclient.c:705707
bool __cdecl CM_Game::Event_MovePass()
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
  *(_DWORD *)buf = 621;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A8D20) --------------------------------------------------------  // acclient.c:705732
bool __cdecl CM_Game::Event_Quit()
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
  *(_DWORD *)buf = 618;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A8DB0) --------------------------------------------------------  // acclient.c:705757
bool __cdecl CM_Game::Event_Stalemate(int i_fOn)
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
  *(_DWORD *)buf = 622;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_fOn;
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

//----- (006A8E80) --------------------------------------------------------  // acclient.c:705807
unsigned int __cdecl CM_Game::DispatchUI_Recv_OpponentTurn(UIQueueManager *ui, void *buf, unsigned int size)
{
  void *v3; // ecx@3
  char *v4; // eax@3
  bool v5; // zf@3
  unsigned int result; // eax@4
  unsigned int v7; // esi@5
  int v8; // edi@5
  ClientMiniGameSystem *v9; // ecx@5
  GameMoveData move; // [sp+4h] [bp-1Ch]@5

  if ( ui
    && ui->m_pMiniGameSystem
    && (v3 = buf, v4 = (char *)buf + 4, v5 = *(_DWORD *)buf == 644, buf = (char *)buf + 4, v5) )
  {
    v7 = *(_DWORD *)v4;
    buf = v4 + 4;
    v8 = *((_DWORD *)v4 + 1);
    buf = v4 + 8;
    move.vfptr = (PackObjVtbl *)&GameMoveData::vftable;
    move.m_type = 0;
    GameMoveData::UnPack(&move, &buf, size + (_BYTE *)v3 - (v4 + 8));
    v9 = ui->m_pMiniGameSystem;
    result = ClientMiniGameSystem::Handle_Game__Recv_OpponentTurn(v7, v8, &move);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 802894: using guessed type int (__thiscall *GameMoveData::vftable)(void *, char);

//----- (006A8F00) --------------------------------------------------------  // acclient.c:705841
char __cdecl CM_Game::SendNotice_BeginGame(unsigned int i_iidGame)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD218 + 1));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 256))(v4, i_iidGame);
    }
  }
  return 1;
}

//----- (006A8F50) --------------------------------------------------------  // acclient.c:705867
char __cdecl CM_Game::SendNotice_EndGame()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)&loc_4DD21A);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 260))(v3);
    }
  }
  return 1;
}

//----- (006A8FA0) --------------------------------------------------------  // acclient.c:705893
char __cdecl CM_Game::SendNotice_GameOver(unsigned int i_idGame, int i_iTeamWinner)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD23C + 4));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, int))(*(_DWORD *)v5 + 264))(v5, i_idGame, i_iTeamWinner);
    }
  }
  return 1;
}

//----- (006A9000) --------------------------------------------------------  // acclient.c:705919
char __cdecl CM_Game::SendNotice_JoinGameResponse(unsigned int i_idGame, int i_iTeam)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD23A + 1));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, int))(*(_DWORD *)v5 + 268))(v5, i_idGame, i_iTeam);
    }
  }
  return 1;
}

//----- (006A9060) --------------------------------------------------------  // acclient.c:705945
char __cdecl CM_Game::SendNotice_MoveResponse(unsigned int i_idGame, int i_iMoveResult)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD23C + 1));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, int))(*(_DWORD *)v5 + 272))(v5, i_idGame, i_iMoveResult);
    }
  }
  return 1;
}

//----- (006A90C0) --------------------------------------------------------  // acclient.c:705971
char __cdecl CM_Game::SendNotice_OpponentOffersStalemate(unsigned int i_idGame, int i_iTeam, int i_fOn)
{
  gmGlobalEventHandler *v3; // eax@1
  int v4; // eax@1
  int v5; // edi@2
  int v6; // esi@3
  bool v7; // zf@3

  v3 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v4 = (int)v3->vfptr->GetNoticeHandlers((NoticeRegistrar *)v3, (unsigned int)((char *)&loc_4DD23C + 3));
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    while ( v5 )
    {
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 == 0;
      v5 = *(_DWORD *)(v5 + 4);
      if ( !v7 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v6)(v6) )
        (*(void (__thiscall **)(int, unsigned int, int, int))(*(_DWORD *)v6 + 276))(v6, i_idGame, i_iTeam, i_fOn);
    }
  }
  return 1;
}

//----- (006A9120) --------------------------------------------------------  // acclient.c:705997
char __cdecl CM_Game::SendNotice_OpponentTurn(unsigned int i_idGame, int i_iTeam, GameMoveData *i_move)
{
  gmGlobalEventHandler *v3; // eax@1
  int v4; // eax@1
  int v5; // edi@2
  int v6; // esi@3
  bool v7; // zf@3

  v3 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v4 = (int)v3->vfptr->GetNoticeHandlers((NoticeRegistrar *)v3, (unsigned int)((char *)&loc_4DD23C + 2));
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    while ( v5 )
    {
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 == 0;
      v5 = *(_DWORD *)(v5 + 4);
      if ( !v7 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v6)(v6) )
        (*(void (__thiscall **)(int, unsigned int, int, GameMoveData *))(*(_DWORD *)v6 + 280))(
          v6,
          i_idGame,
          i_iTeam,
          i_move);
    }
  }
  return 1;
}

//----- (006A9180) --------------------------------------------------------  // acclient.c:706027
char __cdecl CM_Game::SendNotice_StartGame(unsigned int i_idGame, int i_iTeam)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)&loc_4DD23C);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, int))(*(_DWORD *)v5 + 284))(v5, i_idGame, i_iTeam);
    }
  }
  return 1;
}

//----- (006A91E0) --------------------------------------------------------  // acclient.c:706053
char __cdecl CM_Game::SendNotice_TryToQuitGame(int i_bQuitting)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD250);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 288))(v4, i_bQuitting);
    }
  }
  return 1;
}

//----- (007222F0) --------------------------------------------------------  // acclient.c:819979
void sub_7222F0()
{
  flt_8FA160 = 1000.0 + 1.0;
}

//----- (00722310) --------------------------------------------------------  // acclient.c:819985
void sub_722310()
{
  flt_8FA164 = 24.0 * 8.0;
}

//----- (00722330) --------------------------------------------------------  // acclient.c:819991
void sub_722330()
{
  flt_8FA168 = 24.0 * 0.5;
}

//----- (00722350) --------------------------------------------------------  // acclient.c:819997
int sub_722350()
{
  return atexit(nullsub_407);
}

//----- (00722360) --------------------------------------------------------  // acclient.c:820003
int sub_722360()
{
  return atexit(nullsub_408);
}

//----- (00722370) --------------------------------------------------------  // acclient.c:820009
int sub_722370()
{
  return atexit(nullsub_409);
}

//----- (00722380) --------------------------------------------------------  // acclient.c:820015
void sub_722380()
{
  flt_8FA16C = 0.00019999999 * 3.0 + 0.1;
}

//----- (007223A0) --------------------------------------------------------  // acclient.c:820021
void sub_7223A0()
{
  dbl_8FA170 = 1.0 / 30.0;
}

//----- (007223C0) --------------------------------------------------------  // acclient.c:820027
void _E110_90()
{
  dbl_8FA178 = 1.0 / 5.0;
}

//----- (007223E0) --------------------------------------------------------  // acclient.c:820033
void sub_7223E0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FA180, PFID_A8R8G8B8);
}

//----- (007223F0) --------------------------------------------------------  // acclient.c:820039
void sub_7223F0()
{
  dword_8FA1B8 = 1024;
}

//----- (00722400) --------------------------------------------------------  // acclient.c:820045
void _E117_97()
{
  dword_8FA1BC = 0x7FFF;
}

//----- (00722410) --------------------------------------------------------  // acclient.c:820051
int _E119_42()
{
  const int result; // eax@1

  result = dword_8FA1B8;
  dword_8FA1C0 = dword_8FA1B8;
  return result;
}

//----- (00722420) --------------------------------------------------------  // acclient.c:820061
int sub_722420()
{
  return atexit(nullsub_405);
}

//----- (00722430) --------------------------------------------------------  // acclient.c:820067
int sub_722430()
{
  return atexit(nullsub_406);
}

