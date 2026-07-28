/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Movement
   Object     : GAME\game_cevents\CM_Movement.obj
   Functions  : 12
   Addresses  : 006AF790 - 007232A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006AF790) --------------------------------------------------------  // acclient.c:712831
bool __cdecl CM_Movement::Event_AutonomousPosition(AutonomousPositionPack *i_app)
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
  v1 = i_app->vfptr;
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = ((int (__thiscall *)(AutonomousPositionPack *, void **, _DWORD))v1->Pack)(i_app, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v3);
  v4 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 63315;
  v5 = i_app->vfptr;
  v6 = v4 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  ((void (__thiscall *)(AutonomousPositionPack *, void **, int))v5->Pack)(i_app, &buf, v3 + v6);
  v7 = Proto_UI::SendToWeenie(v4, v3);
  if ( !v7 )
    Proto_UI::UICounterFailedSend();
  return v7;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AF850) --------------------------------------------------------  // acclient.c:712865
bool __cdecl CM_Movement::Event_AutonomyLevel(unsigned int i_autonomy_level)
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
  *(_DWORD *)buf = 63314;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_autonomy_level;
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

//----- (006AF920) --------------------------------------------------------  // acclient.c:712915
bool __cdecl CM_Movement::Event_DoMovementCommand(unsigned int i_motion, float i_speed, HoldKey i_hold_key)
{
  signed int v3; // eax@1
  int v4; // esi@1
  void *v5; // eax@1
  char *v6; // edi@1
  char *v7; // eax@1
  char *v8; // eax@1
  bool v9; // zf@1
  unsigned int v10; // ecx@1
  int v11; // edx@4
  char *v12; // eax@6
  bool v13; // zf@6
  unsigned int v14; // ecx@6
  int v15; // edx@9
  int v16; // eax@11
  int v17; // ecx@12
  bool v18; // bl@14
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v3 = OrderHdr::Pack(&hdr, &buf, 0);
  v4 = v3 + 16;
  v5 = operator new[](v3 + 16);
  buf = v5;
  v6 = (char *)v5;
  OrderHdr::Pack(&hdr, &buf, v4);
  *(_DWORD *)buf = 63006;
  v7 = (char *)buf + 4;
  buf = v7;
  *(_DWORD *)v7 = i_motion;
  v8 = (char *)buf + 4;
  v10 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v9 = v10 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v10 = (((_BYTE)v10 - 1) | 0xFFFFFFFC) + 1;
    v9 = v10 == 0;
  }
  if ( !v9 )
  {
    v11 = 4 - v10;
    if ( 4 != v10 )
    {
      do
      {
        *v8 = 0;
        v8 = (char *)buf + 1;
        --v11;
        buf = (char *)buf + 1;
      }
      while ( v11 );
    }
  }
  *(float *)v8 = i_speed;
  v12 = (char *)buf + 4;
  v14 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v13 = v14 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v14 = (((_BYTE)v14 - 1) | 0xFFFFFFFC) + 1;
    v13 = v14 == 0;
  }
  if ( !v13 )
  {
    v15 = 4 - v14;
    if ( 4 != v14 )
    {
      do
      {
        *v12 = 0;
        v12 = (char *)buf + 1;
        --v15;
        buf = (char *)buf + 1;
      }
      while ( v15 );
    }
  }
  *(_DWORD *)v12 = i_hold_key;
  buf = (char *)buf + 4;
  v16 = (signed int)buf % 4;
  if ( (signed int)buf % 4 )
  {
    v17 = 4 - v16;
    if ( 4 != v16 )
    {
      do
      {
        *(_BYTE *)buf = 0;
        --v17;
        buf = (char *)buf + 1;
      }
      while ( v17 );
    }
  }
  v18 = Proto_UI::SendToWeenie(v6, v4);
  if ( !v18 )
    Proto_UI::UICounterFailedSend();
  return v18;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AFA70) --------------------------------------------------------  // acclient.c:713023
bool __cdecl CM_Movement::Event_Jump(JumpPack *i_jp)
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
  v1 = i_jp->vfptr;
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = ((int (__thiscall *)(JumpPack *, void **, _DWORD))v1->Pack)(i_jp, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v3);
  v4 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 63003;
  v5 = i_jp->vfptr;
  v6 = v4 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  ((void (__thiscall *)(JumpPack *, void **, int))v5->Pack)(i_jp, &buf, v3 + v6);
  v7 = Proto_UI::SendToWeenie(v4, v3);
  if ( !v7 )
    Proto_UI::UICounterFailedSend();
  return v7;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AFB30) --------------------------------------------------------  // acclient.c:713057
bool __cdecl CM_Movement::Event_Jump_NonAutonomous(float i_extent)
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
  *(_DWORD *)buf = 63433;
  v5 = (char *)buf + 4;
  buf = v5;
  *(float *)v5 = i_extent;
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

//----- (006AFC00) --------------------------------------------------------  // acclient.c:713107
bool __cdecl CM_Movement::Event_MoveToState(MoveToStatePack *i_mtsp)
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
  v1 = i_mtsp->vfptr;
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = ((int (__thiscall *)(MoveToStatePack *, void **, _DWORD))v1->Pack)(i_mtsp, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v3);
  v4 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 63004;
  v5 = i_mtsp->vfptr;
  v6 = v4 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  ((void (__thiscall *)(MoveToStatePack *, void **, int))v5->Pack)(i_mtsp, &buf, v3 + v6);
  v7 = Proto_UI::SendToWeenie(v4, v3);
  if ( !v7 )
    Proto_UI::UICounterFailedSend();
  return v7;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AFCC0) --------------------------------------------------------  // acclient.c:713141
bool __cdecl CM_Movement::Event_StopMovementCommand(unsigned int i_motion, HoldKey i_hold_key)
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
  *(_DWORD *)buf = 63073;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_motion;
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
  *(_DWORD *)v7 = i_hold_key;
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

//----- (006AFDD0) --------------------------------------------------------  // acclient.c:713220
bool __cdecl CM_Movement::Event_TurnToEvent(TurnToEventPack *i_ttep)
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
  v1 = i_ttep->vfptr;
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = ((int (__thiscall *)(TurnToEventPack *, void **, _DWORD))v1->Pack)(i_ttep, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v3);
  v4 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 63049;
  v5 = i_ttep->vfptr;
  v6 = v4 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  ((void (__thiscall *)(TurnToEventPack *, void **, int))v5->Pack)(i_ttep, &buf, v3 + v6);
  v7 = Proto_UI::SendToWeenie(v4, v3);
  if ( !v7 )
    Proto_UI::UICounterFailedSend();
  return v7;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (00723240) --------------------------------------------------------  // acclient.c:821057
void sub_723240()
{
  flt_8FA738 = 1000.0 + 1.0;
}

//----- (00723260) --------------------------------------------------------  // acclient.c:821063
void sub_723260()
{
  flt_8FA73C = 24.0 * 8.0;
}

//----- (00723280) --------------------------------------------------------  // acclient.c:821069
void sub_723280()
{
  flt_8FA740 = 24.0 * 0.5;
}

//----- (007232A0) --------------------------------------------------------  // acclient.c:821075
int sub_7232A0()
{
  return atexit(nullsub_440);
}

