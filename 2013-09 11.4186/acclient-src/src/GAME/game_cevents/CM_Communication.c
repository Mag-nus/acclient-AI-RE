/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Communication
   Object     : GAME\game_cevents\CM_Communication.obj
   Functions  : 52
   Addresses  : 006A3A20 - 00721C90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006A3A20) --------------------------------------------------------  // acclient.c:700548
unsigned int __cdecl CM_Communication::DispatchUI_SetSquelchDB(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  int v4; // ecx@4
  void *v5; // esi@4
  ClientCommunicationSystem *v6; // ecx@6
  unsigned int v7; // esi@6
  SquelchDB db; // [sp+4h] [bp-44h]@6

  if ( ui && ui->m_pCommunicationSystem )
  {
    v4 = *(_DWORD *)buf;
    v5 = buf;
    buf = (char *)buf + 4;
    if ( v4 == 500 )
    {
      SquelchDB::SquelchDB(&db);
      SquelchDB::UnPack(&db, &buf, size + (_BYTE *)v5 - (_BYTE *)buf);
      v6 = ui->m_pCommunicationSystem;
      v7 = ClientCommunicationSystem::Handle_Communication__SetSquelchDB(&db);
      SquelchDB::~SquelchDB(&db);
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

//----- (006A3AA0) --------------------------------------------------------  // acclient.c:700584
unsigned int __cdecl CM_Communication::DispatchUI_WeenieError(UIQueueManager *ui, void *buf)
{
  ClientCommunicationSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pCommunicationSystem) != 0 && *(_DWORD *)buf == 650 )
    result = ClientCommunicationSystem::Handle_Communication__WeenieError(v2, *((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006A3AD0) --------------------------------------------------------  // acclient.c:700597
bool __cdecl CM_Communication::Event_AddToChannel(unsigned int i_chan)
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
  *(_DWORD *)buf = 325;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_chan;
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

//----- (006A3BA0) --------------------------------------------------------  // acclient.c:700647
bool __cdecl CM_Communication::Event_ChannelIndex()
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
  *(_DWORD *)buf = 329;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A3C30) --------------------------------------------------------  // acclient.c:700672
bool __cdecl CM_Communication::Event_ChannelList(unsigned int i_chan)
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
  *(_DWORD *)buf = 328;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_chan;
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

//----- (006A3D00) --------------------------------------------------------  // acclient.c:700722
bool __cdecl CM_Communication::Event_ModifyGlobalSquelch(int i_add, unsigned int i_msg_type)
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
  *(_DWORD *)buf = 91;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_add;
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
  *(_DWORD *)v7 = i_msg_type;
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

//----- (006A3E10) --------------------------------------------------------  // acclient.c:700801
bool __cdecl CM_Communication::Event_RemoveFromChannel(unsigned int i_chan)
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
  *(_DWORD *)buf = 326;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_chan;
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

//----- (006A3EE0) --------------------------------------------------------  // acclient.c:700851
bool __cdecl CM_Communication::Event_SetAFKMode(int i_bAFK)
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
  *(_DWORD *)buf = 15;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_bAFK;
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

//----- (006A3FB0) --------------------------------------------------------  // acclient.c:700901
unsigned int __cdecl CM_Communication::DispatchUI_Recv_ChatRoomTracker(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  int v4; // ecx@4
  void *v5; // esi@4
  ClientCommunicationSystem *v6; // ecx@6
  ChatRoomTracker chatRoomTracker; // [sp+4h] [bp-2Ch]@6

  if ( ui && ui->m_pCommunicationSystem )
  {
    v4 = *(_DWORD *)buf;
    v5 = buf;
    buf = (char *)buf + 4;
    if ( v4 == 661 )
    {
      ChatRoomTracker::ChatRoomTracker(&chatRoomTracker);
      ChatRoomTracker::UnPack(&chatRoomTracker, &buf, size + (_BYTE *)v5 - (_BYTE *)buf);
      v6 = ui->m_pCommunicationSystem;
      result = ClientCommunicationSystem::Handle_Communication__Recv_ChatRoomTracker(&chatRoomTracker);
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

//----- (006A4030) --------------------------------------------------------  // acclient.c:700934
bool __cdecl CM_Communication::Event_ChannelBroadcast(unsigned int i_chan, AC1Legacy::PStringBase<char> *i_msg)
{
  int v2; // esi@1
  int v3; // esi@1
  void *v4; // eax@1
  char *v5; // edi@1
  char *v6; // eax@1
  char *v7; // eax@1
  bool v8; // zf@1
  unsigned int v9; // ecx@1
  int v10; // edx@4
  bool v11; // bl@6
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = AC1Legacy::PStringBase<char>::Pack(i_msg, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v4 = operator new[](v3);
  buf = v4;
  v5 = (char *)v4;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 327;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_chan;
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
  AC1Legacy::PStringBase<char>::Pack(i_msg, &buf, v3 + v5 - v7);
  v11 = Proto_UI::SendToWeenie(v5, v3);
  if ( !v11 )
    Proto_UI::UICounterFailedSend();
  return v11;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A4120) --------------------------------------------------------  // acclient.c:700995
bool __cdecl CM_Communication::Event_Emote(AC1Legacy::PStringBase<char> *i_msg)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_msg, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 479;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_msg, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A41E0) --------------------------------------------------------  // acclient.c:701025
bool __cdecl CM_Communication::Event_ModifyAccountSquelch(int i_add, AC1Legacy::PStringBase<char> *i_character_name)
{
  int v2; // esi@1
  int v3; // esi@1
  void *v4; // eax@1
  char *v5; // edi@1
  char *v6; // eax@1
  char *v7; // eax@1
  bool v8; // zf@1
  unsigned int v9; // ecx@1
  int v10; // edx@4
  bool v11; // bl@6
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = AC1Legacy::PStringBase<char>::Pack(i_character_name, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v4 = operator new[](v3);
  buf = v4;
  v5 = (char *)v4;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 89;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_add;
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
  AC1Legacy::PStringBase<char>::Pack(i_character_name, &buf, v3 + v5 - v7);
  v11 = Proto_UI::SendToWeenie(v5, v3);
  if ( !v11 )
    Proto_UI::UICounterFailedSend();
  return v11;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A42D0) --------------------------------------------------------  // acclient.c:701086
bool __cdecl CM_Communication::Event_ModifyCharacterSquelch(int i_add, unsigned int i_character_id, AC1Legacy::PStringBase<char> *i_character_name, unsigned int i_msg_type)
{
  int v4; // esi@1
  int v5; // esi@1
  void *v6; // eax@1
  char *v7; // ebx@1
  char *v8; // eax@1
  char *v9; // eax@1
  bool v10; // zf@1
  unsigned int v11; // ecx@1
  int v12; // edx@4
  char *v13; // eax@6
  bool v14; // zf@6
  unsigned int v15; // ecx@6
  int v16; // edx@9
  int v17; // eax@11
  int v18; // ecx@12
  bool v19; // bl@14
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v4 = AC1Legacy::PStringBase<char>::Pack(i_character_name, &buf, 0);
  v5 = v4 + OrderHdr::Pack(&hdr, &buf, 0) + 16;
  v6 = operator new[](v5);
  buf = v6;
  v7 = (char *)v6;
  OrderHdr::Pack(&hdr, &buf, v5);
  *(_DWORD *)buf = 88;
  v8 = (char *)buf + 4;
  buf = v8;
  *(_DWORD *)v8 = i_add;
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
  *(_DWORD *)v9 = i_character_id;
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
  AC1Legacy::PStringBase<char>::Pack(i_character_name, &buf, v5 + v7 - v13);
  *(_DWORD *)buf = i_msg_type;
  buf = (char *)buf + 4;
  v17 = (signed int)buf % 4;
  if ( (signed int)buf % 4 )
  {
    v18 = 4 - v17;
    if ( 4 != v17 )
    {
      do
      {
        *(_BYTE *)buf = 0;
        --v18;
        buf = (char *)buf + 1;
      }
      while ( v18 );
    }
  }
  v19 = Proto_UI::SendToWeenie(v7, v5);
  if ( !v19 )
    Proto_UI::UICounterFailedSend();
  return v19;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A4440) --------------------------------------------------------  // acclient.c:701195
bool __cdecl CM_Communication::Event_SetAFKMessage(AC1Legacy::PStringBase<char> *i_strMessage)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_strMessage, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 16;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_strMessage, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A4500) --------------------------------------------------------  // acclient.c:701225
bool __cdecl CM_Communication::Event_SoulEmote(AC1Legacy::PStringBase<char> *i_msg)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_msg, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 481;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_msg, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A45C0) --------------------------------------------------------  // acclient.c:701255
bool __cdecl CM_Communication::Event_Talk(AC1Legacy::PStringBase<char> *i_msg)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_msg, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 21;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_msg, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A4680) --------------------------------------------------------  // acclient.c:701285
bool __cdecl CM_Communication::Event_TalkDirect(AC1Legacy::PStringBase<char> *i_msg, unsigned int i_target_id)
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
  v2 = AC1Legacy::PStringBase<char>::Pack(i_msg, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v4 = operator new[](v3);
  buf = v4;
  v5 = (char *)v4;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 50;
  v6 = v3 + v5 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_msg, &buf, v6);
  *(_DWORD *)buf = i_target_id;
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

//----- (006A4780) --------------------------------------------------------  // acclient.c:701336
bool __cdecl CM_Communication::Event_TalkDirectByName(AC1Legacy::PStringBase<char> *i_msg, AC1Legacy::PStringBase<char> *i_target_name)
{
  int v2; // esi@1
  int v3; // esi@1
  int v4; // esi@1
  char *v5; // edi@1
  unsigned int v6; // edx@1
  bool v7; // bl@1
  void *buf; // [sp+10h] [bp-Ch]@1
  OrderHdr hdr; // [sp+14h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = AC1Legacy::PStringBase<char>::Pack(i_msg, &buf, 0);
  v3 = AC1Legacy::PStringBase<char>::Pack(i_target_name, &buf, 0) + v2;
  v4 = v3 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v4);
  v5 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v4);
  *(_DWORD *)buf = 93;
  v6 = v4 + v5 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_msg, &buf, v6);
  AC1Legacy::PStringBase<char>::Pack(i_target_name, &buf, v4 + v5 - (_BYTE *)buf);
  v7 = Proto_UI::SendToWeenie(v5, v4);
  if ( !v7 )
    Proto_UI::UICounterFailedSend();
  return v7;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A4860) --------------------------------------------------------  // acclient.c:701369
int __thiscall PackableList<AC1Legacy::PStringBase<char>>::InsertTail(PackableList<AC1Legacy::PStringBase<char> > *this, AC1Legacy::PStringBase<char> *val)
{
  PackableList<AC1Legacy::PStringBase<char> > *v2; // edi@1
  void *v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // eax@2
  int result; // eax@5
  PackableLLNode<AC1Legacy::PStringBase<char> > *v6; // eax@6

  v2 = this;
  v3 = operator new(0xCu);
  if ( v3 )
  {
    v4 = val->m_buffer;
    *(_DWORD *)v3 = val->m_buffer;
    InterlockedIncrement((volatile LONG *)&v4->m_cRef);
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
  }
  else
  {
    v3 = 0;
  }
  if ( v2->head )
  {
    v6 = v2->tail;
    v6->next = (PackableLLNode<AC1Legacy::PStringBase<char> > *)v3;
    *((_DWORD *)v3 + 2) = v6;
    result = v2->curNum + 1;
    v2->tail = (PackableLLNode<AC1Legacy::PStringBase<char> > *)v3;
    v2->curNum = result;
  }
  else
  {
    result = v2->curNum + 1;
    v2->head = (PackableLLNode<AC1Legacy::PStringBase<char> > *)v3;
    v2->tail = (PackableLLNode<AC1Legacy::PStringBase<char> > *)v3;
    v2->curNum = result;
  }
  return result;
}

//----- (006A48D0) --------------------------------------------------------  // acclient.c:701411
unsigned int __cdecl CM_Communication::DispatchUI_ChannelBroadcast(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  void *v4; // esi@4
  unsigned int v5; // ebx@6
  void *v6; // edi@6
  int v7; // eax@6
  unsigned int v8; // edi@6
  unsigned int v9; // ebx@6
  AC1Legacy::PSRefBuffer<char> *v10; // esi@6
  AC1Legacy::PSRefBuffer<char> *v11; // esi@9
  AC1Legacy::PStringBase<char> msg; // [sp+0h] [bp-8h]@6
  AC1Legacy::PStringBase<char> senderName; // [sp+4h] [bp-4h]@6

  if ( ui && ui->m_pCommunicationSystem )
  {
    v4 = buf;
    if ( *(_DWORD *)buf == 327 )
    {
      v5 = *((_DWORD *)buf + 1);
      senderName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      buf = (char *)buf + 8;
      v6 = buf;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      v7 = (_BYTE *)v4 - (_BYTE *)v6;
      v8 = size;
      AC1Legacy::PStringBase<char>::UnPack(&senderName, &buf, size + v7);
      msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack(&msg, &buf, v8 + (_BYTE *)v4 - (_BYTE *)buf);
      v9 = ClientCommunicationSystem::Handle_Communication__ChannelBroadcast(
             ui->m_pCommunicationSystem,
             v5,
             &senderName,
             &msg);
      v10 = msg.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer->m_cRef) && v10 )
        v10->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v10, 1u);
      v11 = senderName.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&senderName.m_buffer->m_cRef) )
      {
        if ( v11 )
          v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
      }
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
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006A49C0) --------------------------------------------------------  // acclient.c:701471
unsigned int __cdecl CM_Communication::DispatchUI_HearDirectSpeech(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebp@1
  unsigned int result; // eax@3
  unsigned int v5; // eax@4
  void *v6; // esi@4
  char *v7; // ebx@4
  int v8; // eax@6
  unsigned int v9; // ebx@6
  unsigned int v10; // ebx@6
  UIQueueManager *v11; // esi@6
  AC1Legacy::PSRefBuffer<char> *v12; // esi@9
  AC1Legacy::PStringBase<char> msg; // [sp+4h] [bp-4h]@6

  v3 = ui;
  if ( ui && ui->m_pCommunicationSystem )
  {
    v5 = *(_DWORD *)buf;
    v6 = buf;
    v7 = (char *)buf + 4;
    buf = (char *)buf + 4;
    if ( v5 == 701 )
    {
      msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      v8 = (_BYTE *)v6 - v7;
      v9 = size;
      AC1Legacy::PStringBase<char>::UnPack(&msg, &buf, size + v8);
      ui = (UIQueueManager *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&ui, &buf, v9 + (_BYTE *)v6 - (_BYTE *)buf);
      v10 = ClientCommunicationSystem::Handle_Communication__HearDirectSpeech(
              v3->m_pCommunicationSystem,
              &msg,
              (AC1Legacy::PStringBase<char> *)&ui,
              *(_DWORD *)buf,
              *((_DWORD *)buf + 1),
              *((_DWORD *)buf + 2),
              *((_DWORD *)buf + 3));
      v11 = ui;
      if ( !InterlockedDecrement((volatile LONG *)&ui->m_cTurbineRefCount) && v11 )
        ((void (__thiscall *)(UIQueueManager *, signed int))v11->vfptr->IUnknown_QueryInterface)(v11, 1);
      v12 = msg.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer->m_cRef) )
      {
        if ( v12 )
          v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
      }
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
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006A4AC0) --------------------------------------------------------  // acclient.c:701535
unsigned int __cdecl CM_Communication::DispatchUI_HearEmote(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  void *v4; // esi@4
  unsigned int v5; // ebx@6
  void *v6; // edi@6
  int v7; // eax@6
  unsigned int v8; // edi@6
  unsigned int v9; // ebx@6
  AC1Legacy::PSRefBuffer<char> *v10; // esi@6
  AC1Legacy::PSRefBuffer<char> *v11; // esi@9
  AC1Legacy::PStringBase<char> msg; // [sp+0h] [bp-8h]@6
  AC1Legacy::PStringBase<char> name; // [sp+4h] [bp-4h]@6

  if ( ui && ui->m_pCommunicationSystem )
  {
    v4 = buf;
    if ( *(_DWORD *)buf == 480 )
    {
      v5 = *((_DWORD *)buf + 1);
      name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      buf = (char *)buf + 8;
      v6 = buf;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      v7 = (_BYTE *)v4 - (_BYTE *)v6;
      v8 = size;
      AC1Legacy::PStringBase<char>::UnPack(&name, &buf, size + v7);
      msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack(&msg, &buf, v8 + (_BYTE *)v4 - (_BYTE *)buf);
      v9 = ClientCommunicationSystem::Handle_Communication__HearEmote(ui->m_pCommunicationSystem, v5, &name, &msg);
      v10 = msg.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer->m_cRef) && v10 )
        v10->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v10, 1u);
      v11 = name.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&name.m_buffer->m_cRef) )
      {
        if ( v11 )
          v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
      }
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
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006A4BB0) --------------------------------------------------------  // acclient.c:701591
unsigned int __cdecl CM_Communication::DispatchUI_HearRangedSpeech(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebp@1
  unsigned int result; // eax@3
  unsigned int v5; // eax@4
  void *v6; // esi@4
  char *v7; // ebx@4
  int v8; // eax@6
  unsigned int v9; // ebx@6
  unsigned int v10; // ST10_4@6
  unsigned int v11; // ST08_4@6
  ClientCommunicationSystem *v12; // ecx@6
  unsigned int v13; // ebx@6
  UIQueueManager *v14; // esi@6
  AC1Legacy::PSRefBuffer<char> *v15; // esi@9
  AC1Legacy::PStringBase<char> msg; // [sp+4h] [bp-8h]@6
  float range; // [sp+8h] [bp-4h]@6

  v3 = ui;
  if ( ui && ui->m_pCommunicationSystem )
  {
    v5 = *(_DWORD *)buf;
    v6 = buf;
    v7 = (char *)buf + 4;
    buf = (char *)buf + 4;
    if ( v5 == 700 )
    {
      msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      v8 = (_BYTE *)v6 - v7;
      v9 = size;
      AC1Legacy::PStringBase<char>::UnPack(&msg, &buf, size + v8);
      ui = (UIQueueManager *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&ui, &buf, v9 + (_BYTE *)v6 - (_BYTE *)buf);
      v10 = *((_DWORD *)buf + 2);
      v11 = *(_DWORD *)buf;
      range = *((float *)buf + 1);
      v12 = v3->m_pCommunicationSystem;
      v13 = ClientCommunicationSystem::Handle_Communication__HearRangedSpeech(
              &msg,
              (AC1Legacy::PStringBase<char> *)&ui,
              v11,
              range,
              v10);
      v14 = ui;
      if ( !InterlockedDecrement((volatile LONG *)&ui->m_cTurbineRefCount) && v14 )
        ((void (__thiscall *)(UIQueueManager *, signed int))v14->vfptr->IUnknown_QueryInterface)(v14, 1);
      v15 = msg.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer->m_cRef) )
      {
        if ( v15 )
          v15->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v15, 1u);
      }
      result = v13;
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
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006A4CC0) --------------------------------------------------------  // acclient.c:701661
unsigned int __cdecl CM_Communication::DispatchUI_HearSoulEmote(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  void *v4; // esi@4
  unsigned int v5; // ebx@6
  void *v6; // edi@6
  int v7; // eax@6
  unsigned int v8; // edi@6
  unsigned int v9; // ebx@6
  AC1Legacy::PSRefBuffer<char> *v10; // esi@6
  AC1Legacy::PSRefBuffer<char> *v11; // esi@9
  AC1Legacy::PStringBase<char> msg; // [sp+0h] [bp-8h]@6
  AC1Legacy::PStringBase<char> name; // [sp+4h] [bp-4h]@6

  if ( ui && ui->m_pCommunicationSystem )
  {
    v4 = buf;
    if ( *(_DWORD *)buf == 482 )
    {
      v5 = *((_DWORD *)buf + 1);
      name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      buf = (char *)buf + 8;
      v6 = buf;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      v7 = (_BYTE *)v4 - (_BYTE *)v6;
      v8 = size;
      AC1Legacy::PStringBase<char>::UnPack(&name, &buf, size + v7);
      msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack(&msg, &buf, v8 + (_BYTE *)v4 - (_BYTE *)buf);
      v9 = ClientCommunicationSystem::Handle_Communication__HearSoulEmote(ui->m_pCommunicationSystem, v5, &name, &msg);
      v10 = msg.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer->m_cRef) && v10 )
        v10->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v10, 1u);
      v11 = name.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&name.m_buffer->m_cRef) )
      {
        if ( v11 )
          v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
      }
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
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006A4DB0) --------------------------------------------------------  // acclient.c:701717
unsigned int __cdecl CM_Communication::DispatchUI_HearSpeech(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebp@1
  unsigned int result; // eax@3
  unsigned int v5; // eax@4
  void *v6; // esi@4
  char *v7; // ebx@4
  int v8; // eax@6
  unsigned int v9; // ebx@6
  unsigned int v10; // ebx@6
  UIQueueManager *v11; // esi@6
  AC1Legacy::PSRefBuffer<char> *v12; // esi@9
  AC1Legacy::PStringBase<char> msg; // [sp+4h] [bp-4h]@6

  v3 = ui;
  if ( ui && ui->m_pCommunicationSystem )
  {
    v5 = *(_DWORD *)buf;
    v6 = buf;
    v7 = (char *)buf + 4;
    buf = (char *)buf + 4;
    if ( v5 == 699 )
    {
      msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      v8 = (_BYTE *)v6 - v7;
      v9 = size;
      AC1Legacy::PStringBase<char>::UnPack(&msg, &buf, size + v8);
      ui = (UIQueueManager *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&ui, &buf, v9 + (_BYTE *)v6 - (_BYTE *)buf);
      v10 = ClientCommunicationSystem::Handle_Communication__HearSpeech(
              v3->m_pCommunicationSystem,
              &msg,
              (AC1Legacy::PStringBase<char> *)&ui,
              *(_DWORD *)buf,
              *((_DWORD *)buf + 1));
      v11 = ui;
      if ( !InterlockedDecrement((volatile LONG *)&ui->m_cTurbineRefCount) && v11 )
        ((void (__thiscall *)(UIQueueManager *, signed int))v11->vfptr->IUnknown_QueryInterface)(v11, 1);
      v12 = msg.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer->m_cRef) )
      {
        if ( v12 )
          v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
      }
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
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006A4EA0) --------------------------------------------------------  // acclient.c:701779
unsigned int __cdecl CM_Communication::DispatchUI_PopUpString(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebx@1
  unsigned int result; // eax@3
  void *v5; // esi@4
  char *v6; // edi@4
  bool v7; // zf@4
  ClientCommunicationSystem *v8; // ecx@6
  unsigned int v9; // edi@6
  UIQueueManager *v10; // esi@6

  v3 = ui;
  if ( ui && ui->m_pCommunicationSystem )
  {
    v5 = buf;
    v6 = (char *)buf + 4;
    v7 = *(_DWORD *)buf == 4;
    buf = (char *)buf + 4;
    if ( v7 )
    {
      ui = (UIQueueManager *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&ui, &buf, size + (_BYTE *)v5 - v6);
      v8 = v3->m_pCommunicationSystem;
      v9 = ClientCommunicationSystem::Handle_Communication__PopUpString((AC1Legacy::PStringBase<char> *)&ui);
      v10 = ui;
      if ( !InterlockedDecrement((volatile LONG *)&ui->m_cTurbineRefCount) )
      {
        if ( v10 )
          ((void (__thiscall *)(UIQueueManager *, signed int))v10->vfptr->IUnknown_QueryInterface)(v10, 1);
      }
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
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006A4F30) --------------------------------------------------------  // acclient.c:701826
unsigned int __cdecl CM_Communication::DispatchUI_TextboxString(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebx@1
  unsigned int result; // eax@3
  void *v5; // esi@4
  char *v6; // edi@4
  bool v7; // zf@4
  unsigned int v8; // edi@6
  UIQueueManager *v9; // esi@6

  v3 = ui;
  if ( ui && ui->m_pCommunicationSystem )
  {
    v5 = buf;
    v6 = (char *)buf + 4;
    v7 = *(_DWORD *)buf == 63456;
    buf = (char *)buf + 4;
    if ( v7 )
    {
      ui = (UIQueueManager *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&ui, &buf, size + (_BYTE *)v5 - v6);
      v8 = ClientCommunicationSystem::Handle_Communication__TextboxString(
             v3->m_pCommunicationSystem,
             (AC1Legacy::PStringBase<char> *)&ui,
             *(_DWORD *)buf);
      v9 = ui;
      if ( !InterlockedDecrement((volatile LONG *)&ui->m_cTurbineRefCount) )
      {
        if ( v9 )
          ((void (__thiscall *)(UIQueueManager *, signed int))v9->vfptr->IUnknown_QueryInterface)(v9, 1);
      }
      result = v8;
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
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006A4FD0) --------------------------------------------------------  // acclient.c:701874
unsigned int __cdecl CM_Communication::DispatchUI_TransientString(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebx@1
  unsigned int result; // eax@3
  void *v5; // esi@4
  char *v6; // edi@4
  bool v7; // zf@4
  unsigned int v8; // edi@6
  UIQueueManager *v9; // esi@6

  v3 = ui;
  if ( ui && ui->m_pCommunicationSystem )
  {
    v5 = buf;
    v6 = (char *)buf + 4;
    v7 = *(_DWORD *)buf == 747;
    buf = (char *)buf + 4;
    if ( v7 )
    {
      ui = (UIQueueManager *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&ui, &buf, size + (_BYTE *)v5 - v6);
      v8 = ClientCommunicationSystem::Handle_Communication__TransientString(
             v3->m_pCommunicationSystem,
             (AC1Legacy::PStringBase<char> *)&ui);
      v9 = ui;
      if ( !InterlockedDecrement((volatile LONG *)&ui->m_cTurbineRefCount) )
      {
        if ( v9 )
          ((void (__thiscall *)(UIQueueManager *, signed int))v9->vfptr->IUnknown_QueryInterface)(v9, 1);
      }
      result = v8;
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
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006A5070) --------------------------------------------------------  // acclient.c:701921
unsigned int __cdecl CM_Communication::DispatchUI_WeenieErrorWithString(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebp@1
  unsigned int result; // eax@3
  void *v5; // esi@4
  unsigned int v6; // ebx@6
  void *v7; // edi@6
  unsigned int v8; // edi@6
  UIQueueManager *v9; // esi@6

  v3 = ui;
  if ( ui && ui->m_pCommunicationSystem )
  {
    v5 = buf;
    if ( *(_DWORD *)buf == 651 )
    {
      v6 = *((_DWORD *)buf + 1);
      ui = (UIQueueManager *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      buf = (char *)buf + 8;
      v7 = buf;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&ui, &buf, size + (_BYTE *)v5 - (_BYTE *)v7);
      v8 = ClientCommunicationSystem::Handle_Communication__WeenieErrorWithString(
             v3->m_pCommunicationSystem,
             v6,
             (AC1Legacy::PStringBase<char> *)&ui);
      v9 = ui;
      if ( !InterlockedDecrement((volatile LONG *)&ui->m_cTurbineRefCount) )
      {
        if ( v9 )
          ((void (__thiscall *)(UIQueueManager *, signed int))v9->vfptr->IUnknown_QueryInterface)(v9, 1);
      }
      result = v8;
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
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006A5110) --------------------------------------------------------  // acclient.c:701969
signed int __thiscall PackableList<AC1Legacy::PStringBase<char>>::Pack(PackableList<AC1Legacy::PStringBase<char> > *this, void **addr, unsigned int size)
{
  PackableList<AC1Legacy::PStringBase<char> > *v3; // esi@1
  signed int v4; // ebp@1
  PackableLLNode<AC1Legacy::PStringBase<char> > *i; // esi@4

  v3 = this;
  v4 = PackableList<AC1Legacy::PStringBase<char>>::pack_size(this);
  if ( size >= v4 )
  {
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v3->curNum;
      *addr = (char *)*addr + 4;
    }
    for ( i = v3->head; i; i = i->next )
      AC1Legacy::PStringBase<char>::Pack(&i->data, addr, size);
  }
  return v4;
}

//----- (006A5160) --------------------------------------------------------  // acclient.c:701991
signed int __thiscall PackableList<AC1Legacy::PStringBase<char>>::pack_size(PackableList<AC1Legacy::PStringBase<char> > *this)
{
  PackableLLNode<AC1Legacy::PStringBase<char> > *v1; // esi@1
  signed int v2; // edi@1
  int v3; // eax@2
  void *addr; // [sp+0h] [bp-4h]@1

  addr = this;
  v1 = this->head;
  v2 = 4;
  for ( addr = 0; v1; v2 += v3 )
  {
    v3 = AC1Legacy::PStringBase<char>::Pack(&v1->data, &addr, 0);
    v1 = v1->next;
  }
  return v2;
}

//----- (006A51A0) --------------------------------------------------------  // acclient.c:702010
int __thiscall PackableList<AC1Legacy::PStringBase<char>>::RemoveHead(PackableList<AC1Legacy::PStringBase<char> > *this, AC1Legacy::PStringBase<char> *retVal)
{
  PackableList<AC1Legacy::PStringBase<char> > *v2; // ebx@1
  PackableLLNode<AC1Legacy::PStringBase<char> > *v3; // edi@1
  int result; // eax@2
  PackableLLNode<AC1Legacy::PStringBase<char> > *v5; // eax@3
  AC1Legacy::PSRefBuffer<char> *v6; // esi@6
  AC1Legacy::PSRefBuffer<char> *v7; // eax@10
  AC1Legacy::PSRefBuffer<char> *v8; // esi@11

  v2 = this;
  v3 = this->head;
  if ( v3 )
  {
    v5 = v3->next;
    this->head = v5;
    if ( v5 )
      v5->prev = 0;
    else
      this->tail = 0;
    v6 = retVal->m_buffer;
    if ( retVal->m_buffer != v3->data.m_buffer )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
        v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
      v7 = v3->data.m_buffer;
      retVal->m_buffer = v3->data.m_buffer;
      InterlockedIncrement((volatile LONG *)&v7->m_cRef);
    }
    v8 = v3->data.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v3->data.m_buffer->m_cRef) )
    {
      if ( v8 )
        v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
    }
    operator delete(v3);
    --v2->curNum;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006A5240) --------------------------------------------------------  // acclient.c:702057
void __thiscall PackableList<AC1Legacy::PStringBase<char>>::Flush(PackableList<AC1Legacy::PStringBase<char> > *this)
{
  AC1Legacy::PSRefBuffer<char> *v1; // edi@1
  PackableList<AC1Legacy::PStringBase<char> > *v2; // esi@1
  AC1Legacy::PStringBase<char> dummyData; // [sp+0h] [bp-4h]@1

  v1 = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v2 = this;
  dummyData.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  if ( v2->head )
  {
    do
      PackableList<AC1Legacy::PStringBase<char>>::RemoveHead(v2, &dummyData);
    while ( v2->head );
    v1 = dummyData.m_buffer;
  }
  if ( !InterlockedDecrement((volatile LONG *)&v1->m_cRef) )
  {
    if ( v1 )
      v1->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v1, 1u);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006A52A0) --------------------------------------------------------  // acclient.c:702083
int __thiscall PackableList<AC1Legacy::PStringBase<char>>::UnPack(PackableList<AC1Legacy::PStringBase<char> > *this, void **addr, unsigned int size)
{
  void **v3; // ebp@2
  int v4; // ebx@2
  void **v5; // esi@2
  int v6; // edi@2
  int result; // eax@9
  void **v8; // esi@11
  PackableList<AC1Legacy::PStringBase<char> > *v9; // [sp+0h] [bp-4h]@1

  v9 = this;
  PackableList<AC1Legacy::PStringBase<char>>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v3 = addr;
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    v5 = (void **)AC1Legacy::PStringBase<char>::s_NullBuffer;
    addr = (void **)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    v6 = 0;
    if ( v4 <= 0 )
    {
LABEL_6:
      if ( !InterlockedDecrement((volatile LONG *)v5 + 1) )
      {
        if ( v5 )
          (*(void (__thiscall **)(void **, signed int))*v5)(v5, 1);
      }
      result = 1;
    }
    else
    {
      while ( AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&addr, v3, size) )
      {
        PackableList<AC1Legacy::PStringBase<char>>::InsertTail(v9, (AC1Legacy::PStringBase<char> *)&addr);
        ++v6;
        if ( v6 >= v4 )
        {
          v5 = addr;
          goto LABEL_6;
        }
      }
      v8 = addr;
      if ( !InterlockedDecrement((volatile LONG *)addr + 1) && v8 )
        (*(void (__thiscall **)(void **, signed int))*v8)(v8, 1);
      result = 0;
    }
  }
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006A5370) --------------------------------------------------------  // acclient.c:702141
PackableList<AC1Legacy::PStringBase<char> > *__thiscall PackableList<AC1Legacy::PStringBase<char>>::scalar_deleting_destructor(PackableList<AC1Legacy::PStringBase<char> > *this, unsigned int a2)
{
  PackableList<AC1Legacy::PStringBase<char> > *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<AC1Legacy::PStringBase<char>>::vftable;
  PackableList<AC1Legacy::PStringBase<char>>::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 801EA4: using guessed type int (__thiscall *PackableList<AC1Legacy::PStringBase<char>>::vftable)(void *, char);

//----- (006A53A0) --------------------------------------------------------  // acclient.c:702157
unsigned int __cdecl CM_Communication::DispatchUI_ChannelIndex(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  void *v4; // eax@4
  char *v5; // ecx@4
  bool v6; // zf@4
  unsigned int v7; // esi@6
  PackableList<AC1Legacy::PStringBase<char> > index; // [sp+4h] [bp-10h]@6

  if ( ui && ui->m_pCommunicationSystem )
  {
    v4 = buf;
    v5 = (char *)buf + 4;
    v6 = *(_DWORD *)buf == 329;
    buf = (char *)buf + 4;
    if ( v6 )
    {
      index.vfptr = (PackObjVtbl *)&PackableList<AC1Legacy::PStringBase<char>>::vftable;
      index.head = 0;
      index.tail = 0;
      index.curNum = 0;
      PackableList<AC1Legacy::PStringBase<char>>::UnPack(&index, &buf, size + (_BYTE *)v4 - v5);
      v7 = ClientCommunicationSystem::Handle_Communication__ChannelIndex(ui->m_pCommunicationSystem, &index);
      index.vfptr = (PackObjVtbl *)&PackableList<AC1Legacy::PStringBase<char>>::vftable;
      PackableList<AC1Legacy::PStringBase<char>>::Flush(&index);
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
// 801EA4: using guessed type int (__thiscall *PackableList<AC1Legacy::PStringBase<char>>::vftable)(void *, char);

//----- (006A5430) --------------------------------------------------------  // acclient.c:702198
unsigned int __cdecl CM_Communication::DispatchUI_ChannelList(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  void *v4; // eax@4
  char *v5; // ecx@4
  bool v6; // zf@4
  unsigned int v7; // esi@6
  PackableList<AC1Legacy::PStringBase<char> > list; // [sp+4h] [bp-10h]@6

  if ( ui && ui->m_pCommunicationSystem )
  {
    v4 = buf;
    v5 = (char *)buf + 4;
    v6 = *(_DWORD *)buf == 328;
    buf = (char *)buf + 4;
    if ( v6 )
    {
      list.vfptr = (PackObjVtbl *)&PackableList<AC1Legacy::PStringBase<char>>::vftable;
      list.head = 0;
      list.tail = 0;
      list.curNum = 0;
      PackableList<AC1Legacy::PStringBase<char>>::UnPack(&list, &buf, size + (_BYTE *)v4 - v5);
      v7 = ClientCommunicationSystem::Handle_Communication__ChannelList(ui->m_pCommunicationSystem, &list);
      list.vfptr = (PackObjVtbl *)&PackableList<AC1Legacy::PStringBase<char>>::vftable;
      PackableList<AC1Legacy::PStringBase<char>>::Flush(&list);
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
// 801EA4: using guessed type int (__thiscall *PackableList<AC1Legacy::PStringBase<char>>::vftable)(void *, char);

//----- (00721B50) --------------------------------------------------------  // acclient.c:819443
void sub_721B50()
{
  flt_8F9E70 = 1000.0 + 1.0;
}

//----- (00721B70) --------------------------------------------------------  // acclient.c:819449
void sub_721B70()
{
  flt_8F9E74 = 24.0 * 8.0;
}

//----- (00721B90) --------------------------------------------------------  // acclient.c:819455
void sub_721B90()
{
  flt_8F9E78 = 24.0 * 0.5;
}

//----- (00721BB0) --------------------------------------------------------  // acclient.c:819461
int sub_721BB0()
{
  return atexit(nullsub_393);
}

//----- (00721BC0) --------------------------------------------------------  // acclient.c:819467
int sub_721BC0()
{
  return atexit(nullsub_394);
}

//----- (00721BD0) --------------------------------------------------------  // acclient.c:819473
int sub_721BD0()
{
  return atexit(nullsub_395);
}

//----- (00721BE0) --------------------------------------------------------  // acclient.c:819479
void sub_721BE0()
{
  flt_8F9E7C = 0.00019999999 * 3.0 + 0.1;
}

//----- (00721C00) --------------------------------------------------------  // acclient.c:819485
void sub_721C00()
{
  dbl_8F9E80 = 1.0 / 30.0;
}

//----- (00721C20) --------------------------------------------------------  // acclient.c:819491
void _E110_85()
{
  dbl_8F9E88 = 1.0 / 5.0;
}

//----- (00721C40) --------------------------------------------------------  // acclient.c:819497
void sub_721C40()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F9E90, PFID_A8R8G8B8);
}

//----- (00721C50) --------------------------------------------------------  // acclient.c:819503
void sub_721C50()
{
  dword_8F9EC8 = 1024;
}

//----- (00721C60) --------------------------------------------------------  // acclient.c:819509
void _E117_92()
{
  dword_8F9ECC = 0x7FFF;
}

//----- (00721C70) --------------------------------------------------------  // acclient.c:819515
int _E119_37()
{
  const int result; // eax@1

  result = dword_8F9EC8;
  dword_8F9ED0 = dword_8F9EC8;
  return result;
}

//----- (00721C80) --------------------------------------------------------  // acclient.c:819525
int _E121_97()
{
  return atexit(nullsub_391);
}

//----- (00721C90) --------------------------------------------------------  // acclient.c:819531
int sub_721C90()
{
  return atexit(nullsub_392);
}

