/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Character
   Object     : GAME\game_cevents\CM_Character.obj
   Functions  : 63
   Addresses  : 006A0E20 - 007219F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006A0E20) --------------------------------------------------------  // acclient.c:697484
unsigned int __cdecl CM_Character::DispatchUI_ConfirmationDone(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pUISystem && *(_DWORD *)buf == 630 )
    result = ClientUISystem::Handle_Character__ConfirmationDone(*((_DWORD *)buf + 1), *((_DWORD *)buf + 2));
  else
    result = 0;
  return result;
}

//----- (006A0E50) --------------------------------------------------------  // acclient.c:697496
unsigned int __cdecl CM_Character::DispatchUI_EnterGame_ServerReady(UIQueueManager *ui, void *buf)
{
  CPlayerSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pPlayerSystem) != 0 && *(_DWORD *)buf == 63455 )
    result = CPlayerSystem::Handle_Character__EnterGame_ServerReady(v2);
  else
    result = 0;
  return result;
}

//----- (006A0E80) --------------------------------------------------------  // acclient.c:697509
unsigned int __cdecl CM_Character::DispatchUI_ReturnPing(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pUISystem && *(_DWORD *)buf == 490 )
    result = ClientUISystem::Handle_Character__ReturnPing();
  else
    result = 0;
  return result;
}

//----- (006A0EB0) --------------------------------------------------------  // acclient.c:697521
bool __cdecl CM_Character::Event_AddShortCut(CShortCutData *i_scData)
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
  v1 = i_scData->vfptr;
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = ((int (__thiscall *)(CShortCutData *, void **, _DWORD))v1->Pack)(i_scData, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v3);
  v4 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 412;
  v5 = i_scData->vfptr;
  v6 = v4 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  ((void (__thiscall *)(CShortCutData *, void **, int))v5->Pack)(i_scData, &buf, v3 + v6);
  v7 = Proto_UI::SendToWeenie(v4, v3);
  if ( !v7 )
    Proto_UI::UICounterFailedSend();
  return v7;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A0F70) --------------------------------------------------------  // acclient.c:697555
bool __cdecl CM_Character::Event_AddSpellFavorite(unsigned int i_spid, int i_index, int i_list)
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
  *(_DWORD *)buf = 483;
  v7 = (char *)buf + 4;
  buf = v7;
  *(_DWORD *)v7 = i_spid;
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
  *(_DWORD *)v8 = i_index;
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
  *(_DWORD *)v12 = i_list;
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

//----- (006A10C0) --------------------------------------------------------  // acclient.c:697663
bool __cdecl CM_Character::Event_CharacterOptionsEvent(PlayerModule *i_pMod)
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
  v1 = i_pMod->vfptr;
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = ((int (__thiscall *)(PlayerModule *, void **, _DWORD))v1->Pack)(i_pMod, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v3);
  v4 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 417;
  v5 = i_pMod->vfptr;
  v6 = v4 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  ((void (__thiscall *)(PlayerModule *, void **, int))v5->Pack)(i_pMod, &buf, v3 + v6);
  v7 = Proto_UI::SendToWeenie(v4, v3);
  if ( !v7 )
    Proto_UI::UICounterFailedSend();
  return v7;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A1180) --------------------------------------------------------  // acclient.c:697697
bool __cdecl CM_Character::Event_ClearPlayerConsentList()
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
  *(_DWORD *)buf = 534;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A1210) --------------------------------------------------------  // acclient.c:697722
bool __cdecl CM_Character::Event_ConfirmationResponse(int i_confirmType, unsigned int i_context, int i_bAccepted)
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
  *(_DWORD *)buf = 629;
  v7 = (char *)buf + 4;
  buf = v7;
  *(_DWORD *)v7 = i_confirmType;
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
  *(_DWORD *)v8 = i_context;
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
  *(_DWORD *)v12 = i_bAccepted;
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

//----- (006A1360) --------------------------------------------------------  // acclient.c:697830
bool __cdecl CM_Character::Event_DisplayPlayerConsentList()
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
  *(_DWORD *)buf = 535;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A13F0) --------------------------------------------------------  // acclient.c:697855
bool __cdecl CM_Character::Event_EnterPKLite()
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
  *(_DWORD *)buf = 655;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A1480) --------------------------------------------------------  // acclient.c:697880
bool __cdecl CM_Character::Event_LoginCompleteNotification()
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
  *(_DWORD *)buf = 161;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A1510) --------------------------------------------------------  // acclient.c:697905
bool __cdecl CM_Character::Event_PlayerOptionChangedEvent(PlayerOption i_po, int i_value)
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
  *(_DWORD *)buf = 5;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_po;
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
  *(_DWORD *)v7 = i_value;
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

//----- (006A1620) --------------------------------------------------------  // acclient.c:697984
bool __cdecl CM_Character::Event_QueryAge(unsigned int i_target)
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
  *(_DWORD *)buf = 450;
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

//----- (006A16F0) --------------------------------------------------------  // acclient.c:698034
bool __cdecl CM_Character::Event_QueryBirth(unsigned int i_target)
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
  *(_DWORD *)buf = 452;
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

//----- (006A17C0) --------------------------------------------------------  // acclient.c:698084
bool __cdecl CM_Character::Event_RemoveShortCut(int i_index)
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
  *(_DWORD *)buf = 413;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_index;
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

//----- (006A1890) --------------------------------------------------------  // acclient.c:698134
bool __cdecl CM_Character::Event_RemoveSpellFavorite(unsigned int i_spid, int i_list)
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
  *(_DWORD *)buf = 484;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_spid;
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
  *(_DWORD *)v7 = i_list;
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

//----- (006A19A0) --------------------------------------------------------  // acclient.c:698213
bool __cdecl CM_Character::Event_RequestPing()
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
  *(_DWORD *)buf = 489;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A1A30) --------------------------------------------------------  // acclient.c:698238
bool __cdecl CM_Character::Event_SpellbookFilterEvent(unsigned int i_options)
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
  *(_DWORD *)buf = 646;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_options;
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

//----- (006A1B00) --------------------------------------------------------  // acclient.c:698288
bool __cdecl CM_Character::Event_Suicide()
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
  *(_DWORD *)buf = 633;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A1B90) --------------------------------------------------------  // acclient.c:698313
bool __cdecl CM_Character::Event_TeleToLifestone()
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
  *(_DWORD *)buf = 99;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A1C20) --------------------------------------------------------  // acclient.c:698338
bool __cdecl CM_Character::Event_TeleToMarketplace()
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
  *(_DWORD *)buf = 653;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A1CB0) --------------------------------------------------------  // acclient.c:698363
bool __cdecl CM_Character::Event_TeleToPKArena()
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
  *(_DWORD *)buf = 39;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A1D40) --------------------------------------------------------  // acclient.c:698388
bool __cdecl CM_Character::Event_TeleToPKLArena()
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
  *(_DWORD *)buf = 38;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A1DD0) --------------------------------------------------------  // acclient.c:698413
unsigned int __cdecl CM_Character::DispatchUI_StartBarber(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pUISystem && *(_DWORD *)buf == 117 )
    result = ClientUISystem::Handle_Character__StartBarber(
               *((IDClass<_tagDataID,32,0> *)buf + 1),
               *((IDClass<_tagDataID,32,0> *)buf + 2),
               *((IDClass<_tagDataID,32,0> *)buf + 3),
               *((IDClass<_tagDataID,32,0> *)buf + 4),
               *((IDClass<_tagDataID,32,0> *)buf + 5),
               *((IDClass<_tagDataID,32,0> *)buf + 6),
               *((IDClass<_tagDataID,32,0> *)buf + 7),
               *((IDClass<_tagDataID,32,0> *)buf + 8),
               *((IDClass<_tagDataID,32,0> *)buf + 9),
               *((IDClass<_tagDataID,32,0> *)buf + 10),
               *((IDClass<_tagDataID,32,0> *)buf + 11),
               *((IDClass<_tagDataID,32,0> *)buf + 12),
               *((IDClass<_tagDataID,32,0> *)buf + 13),
               *((IDClass<_tagDataID,32,0> *)buf + 14),
               *((_DWORD *)buf + 15),
               *((_DWORD *)buf + 16));
  else
    result = 0;
  return result;
}

//----- (006A1EC0) --------------------------------------------------------  // acclient.c:698441
bool __cdecl CM_Character::Event_FinishBarber(IDClass<_tagDataID,32,0> i_base_palette, IDClass<_tagDataID,32,0> i_head_object, IDClass<_tagDataID,32,0> i_head_texture, IDClass<_tagDataID,32,0> i_default_head_texture, IDClass<_tagDataID,32,0> i_eyes_texture, IDClass<_tagDataID,32,0> i_default_eyes_texture, IDClass<_tagDataID,32,0> i_nose_texture, IDClass<_tagDataID,32,0> i_default_nose_texture, IDClass<_tagDataID,32,0> i_mouth_texture, IDClass<_tagDataID,32,0> i_default_mouth_texture, IDClass<_tagDataID,32,0> i_skin_palette, IDClass<_tagDataID,32,0> i_hair_palette, IDClass<_tagDataID,32,0> i_eyes_palette, IDClass<_tagDataID,32,0> i_setup_id, int i_option1, int i_option2)
{
  signed int v16; // eax@1
  int v17; // esi@1
  void *v18; // eax@1
  char *v19; // edi@1
  char *v20; // eax@1
  char *v21; // eax@1
  bool v22; // zf@1
  unsigned int v23; // ecx@1
  int v24; // edx@4
  char *v25; // eax@6
  bool v26; // zf@6
  unsigned int v27; // ecx@6
  int v28; // edx@9
  char *v29; // eax@11
  bool v30; // zf@11
  unsigned int v31; // ecx@11
  int v32; // edx@14
  char *v33; // eax@16
  bool v34; // zf@16
  unsigned int v35; // ecx@16
  int v36; // edx@19
  char *v37; // eax@21
  bool v38; // zf@21
  unsigned int v39; // ecx@21
  int v40; // edx@24
  char *v41; // eax@26
  bool v42; // zf@26
  unsigned int v43; // ecx@26
  int v44; // edx@29
  char *v45; // eax@31
  bool v46; // zf@31
  unsigned int v47; // ecx@31
  int v48; // edx@34
  char *v49; // eax@36
  bool v50; // zf@36
  unsigned int v51; // ecx@36
  int v52; // edx@39
  char *v53; // eax@41
  bool v54; // zf@41
  unsigned int v55; // ecx@41
  int v56; // edx@44
  char *v57; // eax@46
  bool v58; // zf@46
  unsigned int v59; // ecx@46
  int v60; // edx@49
  char *v61; // eax@51
  bool v62; // zf@51
  unsigned int v63; // ecx@51
  int v64; // edx@54
  char *v65; // eax@56
  bool v66; // zf@56
  unsigned int v67; // ecx@56
  int v68; // edx@59
  char *v69; // eax@61
  bool v70; // zf@61
  unsigned int v71; // ecx@61
  int v72; // edx@64
  char *v73; // eax@66
  bool v74; // zf@66
  unsigned int v75; // ecx@66
  int v76; // edx@69
  char *v77; // eax@71
  bool v78; // zf@71
  unsigned int v79; // ecx@71
  int v80; // edx@74
  int v81; // eax@76
  int v82; // ecx@77
  bool v83; // bl@79
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v16 = OrderHdr::Pack(&hdr, &buf, 0);
  v17 = v16 + 68;
  v18 = operator new[](v16 + 68);
  buf = v18;
  v19 = (char *)v18;
  OrderHdr::Pack(&hdr, &buf, v17);
  *(_DWORD *)buf = 785;
  v20 = (char *)buf + 4;
  buf = v20;
  *(_DWORD *)v20 = i_base_palette.id;
  v21 = (char *)buf + 4;
  v23 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v22 = v23 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v23 = (((_BYTE)v23 - 1) | 0xFFFFFFFC) + 1;
    v22 = v23 == 0;
  }
  if ( !v22 )
  {
    v24 = 4 - v23;
    if ( 4 != v23 )
    {
      do
      {
        *v21 = 0;
        v21 = (char *)buf + 1;
        --v24;
        buf = (char *)buf + 1;
      }
      while ( v24 );
    }
  }
  *(_DWORD *)v21 = i_head_object.id;
  v25 = (char *)buf + 4;
  v27 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v26 = v27 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v27 = (((_BYTE)v27 - 1) | 0xFFFFFFFC) + 1;
    v26 = v27 == 0;
  }
  if ( !v26 )
  {
    v28 = 4 - v27;
    if ( 4 != v27 )
    {
      do
      {
        *v25 = 0;
        v25 = (char *)buf + 1;
        --v28;
        buf = (char *)buf + 1;
      }
      while ( v28 );
    }
  }
  *(_DWORD *)v25 = i_head_texture.id;
  v29 = (char *)buf + 4;
  v31 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v30 = v31 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v31 = (((_BYTE)v31 - 1) | 0xFFFFFFFC) + 1;
    v30 = v31 == 0;
  }
  if ( !v30 )
  {
    v32 = 4 - v31;
    if ( 4 != v31 )
    {
      do
      {
        *v29 = 0;
        v29 = (char *)buf + 1;
        --v32;
        buf = (char *)buf + 1;
      }
      while ( v32 );
    }
  }
  *(_DWORD *)v29 = i_default_head_texture.id;
  v33 = (char *)buf + 4;
  v35 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v34 = v35 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v35 = (((_BYTE)v35 - 1) | 0xFFFFFFFC) + 1;
    v34 = v35 == 0;
  }
  if ( !v34 )
  {
    v36 = 4 - v35;
    if ( 4 != v35 )
    {
      do
      {
        *v33 = 0;
        v33 = (char *)buf + 1;
        --v36;
        buf = (char *)buf + 1;
      }
      while ( v36 );
    }
  }
  *(_DWORD *)v33 = i_eyes_texture.id;
  v37 = (char *)buf + 4;
  v39 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v38 = v39 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v39 = (((_BYTE)v39 - 1) | 0xFFFFFFFC) + 1;
    v38 = v39 == 0;
  }
  if ( !v38 )
  {
    v40 = 4 - v39;
    if ( 4 != v39 )
    {
      do
      {
        *v37 = 0;
        v37 = (char *)buf + 1;
        --v40;
        buf = (char *)buf + 1;
      }
      while ( v40 );
    }
  }
  *(_DWORD *)v37 = i_default_eyes_texture.id;
  v41 = (char *)buf + 4;
  v43 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v42 = v43 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v43 = (((_BYTE)v43 - 1) | 0xFFFFFFFC) + 1;
    v42 = v43 == 0;
  }
  if ( !v42 )
  {
    v44 = 4 - v43;
    if ( 4 != v43 )
    {
      do
      {
        *v41 = 0;
        v41 = (char *)buf + 1;
        --v44;
        buf = (char *)buf + 1;
      }
      while ( v44 );
    }
  }
  *(_DWORD *)v41 = i_nose_texture.id;
  v45 = (char *)buf + 4;
  v47 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v46 = v47 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v47 = (((_BYTE)v47 - 1) | 0xFFFFFFFC) + 1;
    v46 = v47 == 0;
  }
  if ( !v46 )
  {
    v48 = 4 - v47;
    if ( 4 != v47 )
    {
      do
      {
        *v45 = 0;
        v45 = (char *)buf + 1;
        --v48;
        buf = (char *)buf + 1;
      }
      while ( v48 );
    }
  }
  *(_DWORD *)v45 = i_default_nose_texture.id;
  v49 = (char *)buf + 4;
  v51 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v50 = v51 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v51 = (((_BYTE)v51 - 1) | 0xFFFFFFFC) + 1;
    v50 = v51 == 0;
  }
  if ( !v50 )
  {
    v52 = 4 - v51;
    if ( 4 != v51 )
    {
      do
      {
        *v49 = 0;
        v49 = (char *)buf + 1;
        --v52;
        buf = (char *)buf + 1;
      }
      while ( v52 );
    }
  }
  *(_DWORD *)v49 = i_mouth_texture.id;
  v53 = (char *)buf + 4;
  v55 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v54 = v55 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v55 = (((_BYTE)v55 - 1) | 0xFFFFFFFC) + 1;
    v54 = v55 == 0;
  }
  if ( !v54 )
  {
    v56 = 4 - v55;
    if ( 4 != v55 )
    {
      do
      {
        *v53 = 0;
        v53 = (char *)buf + 1;
        --v56;
        buf = (char *)buf + 1;
      }
      while ( v56 );
    }
  }
  *(_DWORD *)v53 = i_default_mouth_texture.id;
  v57 = (char *)buf + 4;
  v59 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v58 = v59 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v59 = (((_BYTE)v59 - 1) | 0xFFFFFFFC) + 1;
    v58 = v59 == 0;
  }
  if ( !v58 )
  {
    v60 = 4 - v59;
    if ( 4 != v59 )
    {
      do
      {
        *v57 = 0;
        v57 = (char *)buf + 1;
        --v60;
        buf = (char *)buf + 1;
      }
      while ( v60 );
    }
  }
  *(_DWORD *)v57 = i_skin_palette.id;
  v61 = (char *)buf + 4;
  v63 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v62 = v63 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v63 = (((_BYTE)v63 - 1) | 0xFFFFFFFC) + 1;
    v62 = v63 == 0;
  }
  if ( !v62 )
  {
    v64 = 4 - v63;
    if ( 4 != v63 )
    {
      do
      {
        *v61 = 0;
        v61 = (char *)buf + 1;
        --v64;
        buf = (char *)buf + 1;
      }
      while ( v64 );
    }
  }
  *(_DWORD *)v61 = i_hair_palette.id;
  v65 = (char *)buf + 4;
  v67 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v66 = v67 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v67 = (((_BYTE)v67 - 1) | 0xFFFFFFFC) + 1;
    v66 = v67 == 0;
  }
  if ( !v66 )
  {
    v68 = 4 - v67;
    if ( 4 != v67 )
    {
      do
      {
        *v65 = 0;
        v65 = (char *)buf + 1;
        --v68;
        buf = (char *)buf + 1;
      }
      while ( v68 );
    }
  }
  *(_DWORD *)v65 = i_eyes_palette.id;
  v69 = (char *)buf + 4;
  v71 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v70 = v71 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v71 = (((_BYTE)v71 - 1) | 0xFFFFFFFC) + 1;
    v70 = v71 == 0;
  }
  if ( !v70 )
  {
    v72 = 4 - v71;
    if ( 4 != v71 )
    {
      do
      {
        *v69 = 0;
        v69 = (char *)buf + 1;
        --v72;
        buf = (char *)buf + 1;
      }
      while ( v72 );
    }
  }
  *(_DWORD *)v69 = i_setup_id.id;
  v73 = (char *)buf + 4;
  v75 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v74 = v75 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v75 = (((_BYTE)v75 - 1) | 0xFFFFFFFC) + 1;
    v74 = v75 == 0;
  }
  if ( !v74 )
  {
    v76 = 4 - v75;
    if ( 4 != v75 )
    {
      do
      {
        *v73 = 0;
        v73 = (char *)buf + 1;
        --v76;
        buf = (char *)buf + 1;
      }
      while ( v76 );
    }
  }
  *(_DWORD *)v73 = i_option1;
  v77 = (char *)buf + 4;
  v79 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v78 = v79 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v79 = (((_BYTE)v79 - 1) | 0xFFFFFFFC) + 1;
    v78 = v79 == 0;
  }
  if ( !v78 )
  {
    v80 = 4 - v79;
    if ( 4 != v79 )
    {
      do
      {
        *v77 = 0;
        v77 = (char *)buf + 1;
        --v80;
        buf = (char *)buf + 1;
      }
      while ( v80 );
    }
  }
  *(_DWORD *)v77 = i_option2;
  buf = (char *)buf + 4;
  v81 = (signed int)buf % 4;
  if ( (signed int)buf % 4 )
  {
    v82 = 4 - v81;
    if ( 4 != v81 )
    {
      do
      {
        *(_BYTE *)buf = 0;
        --v82;
        buf = (char *)buf + 1;
      }
      while ( v82 );
    }
  }
  v83 = Proto_UI::SendToWeenie(v19, v17);
  if ( !v83 )
    Proto_UI::UICounterFailedSend();
  return v83;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A2350) --------------------------------------------------------  // acclient.c:698926
bool __cdecl CM_Character::Event_SetDesiredComponentLevel(IDClass<_tagDataID,32,0> i_wcid, int i_amount)
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
  *(_DWORD *)buf = 548;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_wcid.id;
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
  *(_DWORD *)v7 = i_amount;
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

//----- (006A2460) --------------------------------------------------------  // acclient.c:699005
char __cdecl CM_Character::SendNotice_AbortConfirmationRequest(int i_confirmationType, unsigned int i_uiContextID)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD20C + 1));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, int, unsigned int))(*(_DWORD *)v5 + 120))(v5, i_confirmationType, i_uiContextID);
    }
  }
  return 1;
}

//----- (006A24B0) --------------------------------------------------------  // acclient.c:699031
char __cdecl CM_Character::SendNotice_AbuseReportResponse(unsigned int i_error)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)nullsub_1891);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 124))(v4, i_error);
    }
  }
  return 1;
}
// 4DD221: using guessed type int __stdcall nullsub_1891(int);

//----- (006A2500) --------------------------------------------------------  // acclient.c:699058
char __cdecl CM_Character::SendNotice_AlterAttribute_ConfirmationRequest(AC1Legacy::PStringBase<char> *i_userData, unsigned int i_uiContextID)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD207 + 3));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, AC1Legacy::PStringBase<char> *, unsigned int))(*(_DWORD *)v5 + 132))(
          v5,
          i_userData,
          i_uiContextID);
    }
  }
  return 1;
}

//----- (006A2560) --------------------------------------------------------  // acclient.c:699087
char __cdecl CM_Character::SendNotice_AlterSkill_ConfirmationRequest(AC1Legacy::PStringBase<char> *i_userData, unsigned int i_uiContextID)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD207 + 2));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, AC1Legacy::PStringBase<char> *, unsigned int))(*(_DWORD *)v5 + 136))(
          v5,
          i_userData,
          i_uiContextID);
    }
  }
  return 1;
}

//----- (006A25C0) --------------------------------------------------------  // acclient.c:699116
char __cdecl CM_Character::SendNotice_Augmentation_ConfirmationRequest(AC1Legacy::PStringBase<char> *i_userData, unsigned int i_uiContextID)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD207 + 4));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, AC1Legacy::PStringBase<char> *, unsigned int))(*(_DWORD *)v5 + 140))(
          v5,
          i_userData,
          i_uiContextID);
    }
  }
  return 1;
}

//----- (006A2620) --------------------------------------------------------  // acclient.c:699145
char __cdecl CM_Character::SendNotice_BeginPowerbar(PowerBarMode i_pbm)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD1FD);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, PowerBarMode))(*(_DWORD *)v4 + 144))(v4, i_pbm);
    }
  }
  return 1;
}

//----- (006A2670) --------------------------------------------------------  // acclient.c:699171
char __cdecl CM_Character::SendNotice_ChangeRadarLook(CWeenieObject *obj)
{
  List<NoticeHandler *> *v1; // eax@1
  ListNode<NoticeHandler *> *v2; // esi@2
  NoticeHandler *v3; // edi@3
  bool v4; // zf@3

  v1 = obj->vfptr->GetNoticeHandlers((NoticeRegistrar *)&obj->vfptr, (unsigned int)&loc_4DD245);
  if ( v1 )
  {
    v2 = v1->_head;
    while ( v2 )
    {
      v3 = v2->data;
      v4 = v2->data == 0;
      v2 = v2->next;
      if ( !v4 && !v3->vfptr->IsEngine(v3) )
        ((void (__thiscall *)(NoticeHandler *, CWeenieObject *))v3->vfptr[1].RecvNotice_CloseDialog)(v3, obj);
    }
  }
  return 1;
}

//----- (006A26C0) --------------------------------------------------------  // acclient.c:699195
char __cdecl CM_Character::SendNotice_CraftInteraction_ConfirmationRequest(AC1Legacy::PStringBase<char> *i_userData, unsigned int i_uiContextID)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)&loc_4DD20C);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, AC1Legacy::PStringBase<char> *, unsigned int))(*(_DWORD *)v5 + 152))(
          v5,
          i_userData,
          i_uiContextID);
    }
  }
  return 1;
}

//----- (006A2720) --------------------------------------------------------  // acclient.c:699224
char __cdecl CM_Character::SendNotice_FinishPowerbar(PowerBarMode i_pbm)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD1FD + 1));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, PowerBarMode))(*(_DWORD *)v4 + 156))(v4, i_pbm);
    }
  }
  return 1;
}

//----- (006A2770) --------------------------------------------------------  // acclient.c:699250
char __cdecl CM_Character::SendNotice_LoadChanged(float i_fNewLoad)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD21E + 2));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 160))(v4, LODWORD(i_fNewLoad));
    }
  }
  return 1;
}

//----- (006A27C0) --------------------------------------------------------  // acclient.c:699276
char __cdecl CM_Character::SendNotice_Ping()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)&loc_4DD21D);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 164))(v3);
    }
  }
  return 1;
}

//----- (006A2810) --------------------------------------------------------  // acclient.c:699302
char __cdecl CM_Character::SendNotice_RefreshActionKeyMapping(QualifiedControl *i_qcMapped)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD242);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, QualifiedControl *))(*(_DWORD *)v4 + 168))(v4, i_qcMapped);
    }
  }
  return 1;
}

//----- (006A2860) --------------------------------------------------------  // acclient.c:699328
char __cdecl CM_Character::SendNotice_ReloadOptions()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)&loc_4DD216);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 172))(v3);
    }
  }
  return 1;
}

//----- (006A28B0) --------------------------------------------------------  // acclient.c:699354
char __cdecl CM_Character::SendNotice_SetPowerbarLevel(PowerBarMode i_pbm, float i_fLevel)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD1E5 + 1));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, PowerBarMode, _DWORD))(*(_DWORD *)v5 + 180))(v5, i_pbm, LODWORD(i_fLevel));
    }
  }
  return 1;
}

//----- (006A2910) --------------------------------------------------------  // acclient.c:699380
char __cdecl CM_Character::SendNotice_StartBarberNotice(IDClass<_tagDataID,32,0> i_base_palette, IDClass<_tagDataID,32,0> i_head_object, IDClass<_tagDataID,32,0> i_head_texture, IDClass<_tagDataID,32,0> i_default_head_texture, IDClass<_tagDataID,32,0> i_eyes_texture, IDClass<_tagDataID,32,0> i_default_eyes_texture, IDClass<_tagDataID,32,0> i_nose_texture, IDClass<_tagDataID,32,0> i_default_nose_texture, IDClass<_tagDataID,32,0> i_mouth_texture, IDClass<_tagDataID,32,0> i_default_mouth_texture, IDClass<_tagDataID,32,0> i_skin_palette, IDClass<_tagDataID,32,0> i_hair_palette, IDClass<_tagDataID,32,0> i_eyes_palette, IDClass<_tagDataID,32,0> i_setup_id, int i_option1, int i_option2)
{
  gmGlobalEventHandler *v16; // eax@1
  int v17; // eax@1
  int v18; // eax@2
  int v19; // esi@5
  int iter_4; // [sp+44h] [bp-8h]@5

  v16 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v17 = (int)v16->vfptr->GetNoticeHandlers((NoticeRegistrar *)v16, (unsigned int)((char *)&loc_4DD279 + 5));
  if ( v17 )
  {
    v18 = *(_DWORD *)(v17 + 4);
    if ( v18 )
    {
      while ( 1 )
      {
        v19 = *(_DWORD *)v18;
        iter_4 = *(_DWORD *)(v18 + 4);
        if ( *(_DWORD *)v18 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v19)(v19) )
          (*(void (__thiscall **)(int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, int, int))(*(_DWORD *)v19 + 184))(
            v19,
            i_base_palette.id,
            i_head_object.id,
            i_head_texture.id,
            i_default_head_texture.id,
            i_eyes_texture.id,
            i_default_eyes_texture.id,
            i_nose_texture.id,
            i_default_nose_texture.id,
            i_mouth_texture.id,
            i_default_mouth_texture.id,
            i_skin_palette.id,
            i_hair_palette.id,
            i_eyes_palette.id,
            i_setup_id.id,
            i_option1,
            i_option2);
        if ( !iter_4 )
          break;
        v18 = iter_4;
      }
    }
  }
  return 1;
}

//----- (006A29D0) --------------------------------------------------------  // acclient.c:699428
char __cdecl CM_Character::SendNotice_YesNo_ConfirmationRequest(AC1Legacy::PStringBase<char> *i_userData, unsigned int i_uiContextID)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD279 + 1));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, AC1Legacy::PStringBase<char> *, unsigned int))(*(_DWORD *)v5 + 192))(
          v5,
          i_userData,
          i_uiContextID);
    }
  }
  return 1;
}

//----- (006A2A30) --------------------------------------------------------  // acclient.c:699457
bool __cdecl CM_Character::Event_AbuseLogRequest(AC1Legacy::PStringBase<char> *i_target, int i_status, AC1Legacy::PStringBase<char> *i_complaint)
{
  int v3; // esi@1
  int v4; // esi@1
  int v5; // esi@1
  void *v6; // eax@1
  char *v7; // edi@1
  unsigned int v8; // edx@1
  char *v9; // eax@1
  bool v10; // zf@1
  unsigned int v11; // ecx@1
  int v12; // edx@4
  bool v13; // bl@6
  void *buf; // [sp+10h] [bp-Ch]@1
  OrderHdr hdr; // [sp+14h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v3 = AC1Legacy::PStringBase<char>::Pack(i_target, &buf, 0);
  v4 = AC1Legacy::PStringBase<char>::Pack(i_complaint, &buf, 0) + v3;
  v5 = v4 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v6 = operator new[](v5);
  buf = v6;
  v7 = (char *)v6;
  OrderHdr::Pack(&hdr, &buf, v5);
  *(_DWORD *)buf = 320;
  v8 = v5 + v7 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_target, &buf, v8);
  *(_DWORD *)buf = i_status;
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
  AC1Legacy::PStringBase<char>::Pack(i_complaint, &buf, v5 + v7 - v9);
  v13 = Proto_UI::SendToWeenie(v7, v5);
  if ( !v13 )
    Proto_UI::UICounterFailedSend();
  return v13;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A2B50) --------------------------------------------------------  // acclient.c:699521
bool __cdecl CM_Character::Event_AddPlayerPermission(AC1Legacy::PStringBase<char> *i_targetName)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_targetName, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 537;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_targetName, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A2C10) --------------------------------------------------------  // acclient.c:699551
bool __cdecl CM_Character::Event_RemoveFromPlayerConsentList(AC1Legacy::PStringBase<char> *i_targetName)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_targetName, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 536;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_targetName, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A2CD0) --------------------------------------------------------  // acclient.c:699581
bool __cdecl CM_Character::Event_RemovePlayerPermission(AC1Legacy::PStringBase<char> *i_targetName)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_targetName, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 538;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_targetName, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A2D90) --------------------------------------------------------  // acclient.c:699611
unsigned int __cdecl CM_Character::DispatchUI_ConfirmationRequest(UIQueueManager *ui, void *buf, unsigned int size)
{
  AC1Legacy::PSRefBuffer<char> *v3; // ecx@0
  unsigned int result; // eax@3
  void *v5; // edi@4
  int v6; // ebx@6
  unsigned int v7; // ebp@6
  void *v8; // esi@6
  ClientUISystem *v9; // ecx@6
  unsigned int v10; // edi@6
  AC1Legacy::PSRefBuffer<char> *v11; // esi@6
  AC1Legacy::PStringBase<char> userData; // [sp+0h] [bp-4h]@1

  userData.m_buffer = v3;
  if ( ui && ui->m_pUISystem )
  {
    v5 = buf;
    if ( *(_DWORD *)buf == 628 )
    {
      v6 = *((_DWORD *)buf + 1);
      v7 = *((_DWORD *)buf + 2);
      userData.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      buf = (char *)buf + 12;
      v8 = buf;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack(&userData, &buf, size + (_BYTE *)v5 - (_BYTE *)v8);
      v9 = ui->m_pUISystem;
      v10 = ClientUISystem::Handle_Character__ConfirmationRequest(v6, v7, &userData);
      v11 = userData.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&userData.m_buffer->m_cRef) )
      {
        if ( v11 )
          v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
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

//----- (006A2E40) --------------------------------------------------------  // acclient.c:699661
unsigned int __cdecl CM_Character::DispatchUI_QueryAgeResponse(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebp@1
  unsigned int result; // eax@3
  int v5; // eax@4
  void *v6; // esi@4
  char *v7; // ebx@4
  int v8; // eax@6
  unsigned int v9; // ebx@6
  unsigned int v10; // ebx@6
  UIQueueManager *v11; // esi@6
  AC1Legacy::PSRefBuffer<char> *v12; // esi@9
  AC1Legacy::PStringBase<char> targetName; // [sp+4h] [bp-4h]@6

  v3 = ui;
  if ( ui && ui->m_pCommunicationSystem )
  {
    v5 = *(_DWORD *)buf;
    v6 = buf;
    v7 = (char *)buf + 4;
    buf = (char *)buf + 4;
    if ( v5 == 451 )
    {
      targetName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      v8 = (_BYTE *)v6 - v7;
      v9 = size;
      AC1Legacy::PStringBase<char>::UnPack(&targetName, &buf, size + v8);
      ui = (UIQueueManager *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&ui, &buf, v9 + (_BYTE *)v6 - (_BYTE *)buf);
      v10 = ClientCommunicationSystem::Handle_Character__QueryAgeResponse(
              v3->m_pCommunicationSystem,
              &targetName,
              (AC1Legacy::PStringBase<char> *)&ui);
      v11 = ui;
      if ( !InterlockedDecrement((volatile LONG *)&ui->m_cTurbineRefCount) && v11 )
        ((void (__thiscall *)(UIQueueManager *, signed int))v11->vfptr->IUnknown_QueryInterface)(v11, 1);
      v12 = targetName.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&targetName.m_buffer->m_cRef) )
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

//----- (007218B0) --------------------------------------------------------  // acclient.c:819255
void sub_7218B0()
{
  flt_8F9D60 = 1000.0 + 1.0;
}

//----- (007218D0) --------------------------------------------------------  // acclient.c:819261
void sub_7218D0()
{
  flt_8F9D64 = 24.0 * 8.0;
}

//----- (007218F0) --------------------------------------------------------  // acclient.c:819267
void sub_7218F0()
{
  flt_8F9D68 = 24.0 * 0.5;
}

//----- (00721910) --------------------------------------------------------  // acclient.c:819273
int sub_721910()
{
  return atexit(nullsub_383);
}

//----- (00721920) --------------------------------------------------------  // acclient.c:819279
int sub_721920()
{
  return atexit(nullsub_384);
}

//----- (00721930) --------------------------------------------------------  // acclient.c:819285
int sub_721930()
{
  return atexit(nullsub_385);
}

//----- (00721940) --------------------------------------------------------  // acclient.c:819291
void sub_721940()
{
  flt_8F9D6C = 0.00019999999 * 3.0 + 0.1;
}

//----- (00721960) --------------------------------------------------------  // acclient.c:819297
void sub_721960()
{
  dbl_8F9D70 = 1.0 / 30.0;
}

//----- (00721980) --------------------------------------------------------  // acclient.c:819303
void _E110_83()
{
  dbl_8F9D78 = 1.0 / 5.0;
}

//----- (007219A0) --------------------------------------------------------  // acclient.c:819309
void sub_7219A0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F9D80, PFID_A8R8G8B8);
}

//----- (007219B0) --------------------------------------------------------  // acclient.c:819315
void sub_7219B0()
{
  dword_8F9DB8 = 1024;
}

//----- (007219C0) --------------------------------------------------------  // acclient.c:819321
void _E117_90()
{
  dword_8F9DBC = 0x7FFF;
}

//----- (007219D0) --------------------------------------------------------  // acclient.c:819327
int _E119_35()
{
  const int result; // eax@1

  result = dword_8F9DB8;
  dword_8F9DC0 = dword_8F9DB8;
  return result;
}

//----- (007219E0) --------------------------------------------------------  // acclient.c:819337
int _E121_95()
{
  return atexit(nullsub_381);
}

//----- (007219F0) --------------------------------------------------------  // acclient.c:819343
int sub_7219F0()
{
  return atexit(nullsub_382);
}

