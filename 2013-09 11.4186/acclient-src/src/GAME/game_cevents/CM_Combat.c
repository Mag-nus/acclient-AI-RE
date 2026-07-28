/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Combat
   Object     : GAME\game_cevents\CM_Combat.obj
   Functions  : 25
   Addresses  : 006A99A0 - 00722620 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006A99A0) --------------------------------------------------------  // acclient.c:706603
unsigned int __cdecl CM_Combat::DispatchUI_QueryHealthResponse(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pCombatSystem && *(_DWORD *)buf == 448 )
    result = ClientCombatSystem::Handle_Combat__QueryHealthResponse(*((_DWORD *)buf + 1), *((float *)buf + 2));
  else
    result = 0;
  return result;
}

//----- (006A99E0) --------------------------------------------------------  // acclient.c:706615
bool __cdecl CM_Combat::Event_CancelAttack()
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
  *(_DWORD *)buf = 439;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A9A70) --------------------------------------------------------  // acclient.c:706640
bool __cdecl CM_Combat::Event_ChangeCombatMode(COMBAT_MODE i_mode)
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
  *(_DWORD *)buf = 83;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_mode;
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

//----- (006A9B40) --------------------------------------------------------  // acclient.c:706690
bool __cdecl CM_Combat::Event_QueryHealth(unsigned int i_target)
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
  *(_DWORD *)buf = 447;
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

//----- (006A9C10) --------------------------------------------------------  // acclient.c:706740
bool __cdecl CM_Combat::Event_TargetedMeleeAttack(unsigned int i_targetID, ATTACK_HEIGHT i_ah, float i_power_level)
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
  *(_DWORD *)buf = 8;
  v7 = (char *)buf + 4;
  buf = v7;
  *(_DWORD *)v7 = i_targetID;
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
  *(_DWORD *)v8 = i_ah;
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
  *(float *)v12 = i_power_level;
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

//----- (006A9D60) --------------------------------------------------------  // acclient.c:706848
bool __cdecl CM_Combat::Event_TargetedMissileAttack(unsigned int i_targetID, ATTACK_HEIGHT i_ah, float i_accuracy_level)
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
  *(_DWORD *)buf = 10;
  v7 = (char *)buf + 4;
  buf = v7;
  *(_DWORD *)v7 = i_targetID;
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
  *(_DWORD *)v8 = i_ah;
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
  *(float *)v12 = i_accuracy_level;
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

//----- (006A9EB0) --------------------------------------------------------  // acclient.c:706956
char __cdecl CM_Combat::SendNotice_AttackHeightChanged(ATTACK_HEIGHT i_i_height)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD1F9 + 3));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, ATTACK_HEIGHT))(*(_DWORD *)v4 + 196))(v4, i_i_height);
    }
  }
  return 1;
}

//----- (006A9F00) --------------------------------------------------------  // acclient.c:706982
char __cdecl CM_Combat::SendNotice_DesiredAttackPowerChanged(float i_i_fLevel)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD245 + 4));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 200))(v4, LODWORD(i_i_fLevel));
    }
  }
  return 1;
}

//----- (006A9F50) --------------------------------------------------------  // acclient.c:707008
char __cdecl CM_Combat::SendNotice_SetCombatMode(COMBAT_MODE i_eCombatMode)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD1F9 + 2));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, COMBAT_MODE))(*(_DWORD *)v4 + 204))(v4, i_eCombatMode);
    }
  }
  return 1;
}

//----- (006A9FA0) --------------------------------------------------------  // acclient.c:707034
char __cdecl CM_Combat::SendNotice_UpdateObjectHealth(unsigned int i_target, float i_health)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD1F3 + 1));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, _DWORD))(*(_DWORD *)v5 + 208))(v5, i_target, LODWORD(i_health));
    }
  }
  return 1;
}

//----- (007224E0) --------------------------------------------------------  // acclient.c:820115
void sub_7224E0()
{
  flt_8FA210 = 1000.0 + 1.0;
}

//----- (00722500) --------------------------------------------------------  // acclient.c:820121
void sub_722500()
{
  flt_8FA214 = 24.0 * 8.0;
}

//----- (00722520) --------------------------------------------------------  // acclient.c:820127
void sub_722520()
{
  flt_8FA218 = 24.0 * 0.5;
}

//----- (00722540) --------------------------------------------------------  // acclient.c:820133
int sub_722540()
{
  return atexit(nullsub_388);
}

//----- (00722550) --------------------------------------------------------  // acclient.c:820139
int sub_722550()
{
  return atexit(nullsub_389);
}

//----- (00722560) --------------------------------------------------------  // acclient.c:820145
int sub_722560()
{
  return atexit(nullsub_390);
}

//----- (00722570) --------------------------------------------------------  // acclient.c:820151
void sub_722570()
{
  flt_8FA21C = 0.00019999999 * 3.0 + 0.1;
}

//----- (00722590) --------------------------------------------------------  // acclient.c:820157
void sub_722590()
{
  dbl_8FA220 = 1.0 / 30.0;
}

//----- (007225B0) --------------------------------------------------------  // acclient.c:820163
void _E110_91()
{
  dbl_8FA228 = 1.0 / 5.0;
}

//----- (007225D0) --------------------------------------------------------  // acclient.c:820169
void sub_7225D0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FA230, PFID_A8R8G8B8);
}

//----- (007225E0) --------------------------------------------------------  // acclient.c:820175
void sub_7225E0()
{
  dword_8FA268 = 1024;
}

//----- (007225F0) --------------------------------------------------------  // acclient.c:820181
void _E117_98()
{
  dword_8FA26C = 0x7FFF;
}

//----- (00722600) --------------------------------------------------------  // acclient.c:820187
int _E119_43()
{
  const int result; // eax@1

  result = dword_8FA268;
  dword_8FA270 = dword_8FA268;
  return result;
}

//----- (00722610) --------------------------------------------------------  // acclient.c:820197
int sub_722610()
{
  return atexit(nullsub_386);
}

//----- (00722620) --------------------------------------------------------  // acclient.c:820203
int sub_722620()
{
  return atexit(nullsub_387);
}

