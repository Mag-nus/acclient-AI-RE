/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_House
   Object     : GAME\game_cevents\CM_House.obj
   Functions  : 51
   Addresses  : 006AA320 - 00722810 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006AA320) --------------------------------------------------------  // acclient.c:707288
unsigned int __cdecl CM_House::DispatchUI_Recv_HouseStatus(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pHousingSystem && *(_DWORD *)buf == 550 )
    result = ClientHousingSystem::Handle_House__Recv_HouseTransaction(*((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006AA350) --------------------------------------------------------  // acclient.c:707300
unsigned int __cdecl CM_House::DispatchUI_Recv_HouseTransaction(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pHousingSystem && *(_DWORD *)buf == 601 )
    result = ClientHousingSystem::Handle_House__Recv_HouseTransaction(*((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006AA380) --------------------------------------------------------  // acclient.c:707312
unsigned int __cdecl CM_House::DispatchUI_Recv_UpdateHAR(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  int v4; // ecx@4
  void *v5; // esi@4
  unsigned int v6; // esi@6
  HAR har; // [sp+4h] [bp-34h]@6

  if ( ui && ui->m_pHousingSystem )
  {
    v4 = *(_DWORD *)buf;
    v5 = buf;
    buf = (char *)buf + 4;
    if ( v4 == 599 )
    {
      HAR::HAR(&har);
      HAR::UnPack(&har, &buf, size + (_BYTE *)v5 - (_BYTE *)buf);
      v6 = ClientHousingSystem::Handle_House__Recv_UpdateHAR(ui->m_pHousingSystem, &har);
      HAR::~HAR(&har);
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

//----- (006AA400) --------------------------------------------------------  // acclient.c:707346
unsigned int __cdecl CM_House::DispatchUI_Recv_UpdateRentTime(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pHousingSystem && *(_DWORD *)buf == 551 )
    result = ClientHousingSystem::Handle_House__Recv_UpdateRentTime(*((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006AA430) --------------------------------------------------------  // acclient.c:707358
unsigned int __cdecl CM_House::DispatchUI_Recv_UpdateRestrictions(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  int v4; // ecx@4
  void *v5; // esi@4
  char *v6; // eax@4
  char v7; // cl@6
  unsigned int v8; // edi@6
  char wts; // ST18_1@6
  ClientHousingSystem *v10; // ecx@6
  unsigned int v11; // esi@6
  RestrictionDB db; // [sp+8h] [bp-84h]@6

  if ( ui && ui->m_pHousingSystem )
  {
    v4 = *(_DWORD *)buf;
    v5 = buf;
    v6 = (char *)buf + 4;
    buf = (char *)buf + 4;
    if ( v4 == 584 )
    {
      v7 = *v6;
      buf = v6 + 1;
      v8 = *(_DWORD *)(v6 + 1);
      wts = v7;
      buf = v6 + 5;
      RestrictionDB::RestrictionDB(&db);
      RestrictionDB::UnPack(&db, &buf, size + (_BYTE *)v5 - (_BYTE *)buf);
      v10 = ui->m_pHousingSystem;
      v11 = ClientHousingSystem::Handle_House__Recv_UpdateRestrictions(wts, v8, &db);
      RestrictionDB::~RestrictionDB(&db);
      result = v11;
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

//----- (006AA4F0) --------------------------------------------------------  // acclient.c:707404
bool __cdecl CM_House::Event_AbandonHouse()
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
  *(_DWORD *)buf = 543;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AA580) --------------------------------------------------------  // acclient.c:707429
bool __cdecl CM_House::Event_AddAllStoragePermission()
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
  *(_DWORD *)buf = 604;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AA610) --------------------------------------------------------  // acclient.c:707454
bool __cdecl CM_House::Event_BootEveryone_Event()
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
  *(_DWORD *)buf = 607;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AA6A0) --------------------------------------------------------  // acclient.c:707479
bool __cdecl CM_House::Event_BuyHouse(unsigned int i_slumlord, PackableList<unsigned long> *i_stuff)
{
  PackObjVtbl *v2; // eax@1
  int v3; // esi@1
  int v4; // esi@1
  void *v5; // eax@1
  char *v6; // ebx@1
  char *v7; // eax@1
  char *v8; // eax@1
  bool v9; // zf@1
  unsigned int v10; // ecx@1
  int v11; // edx@4
  bool v12; // bl@6
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  v2 = i_stuff->vfptr;
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v3 = ((int (__thiscall *)(PackableList<unsigned long> *, void **, _DWORD))v2->Pack)(i_stuff, &buf, 0);
  v4 = v3 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v5 = operator new[](v4);
  buf = v5;
  v6 = (char *)v5;
  OrderHdr::Pack(&hdr, &buf, v4);
  *(_DWORD *)buf = 540;
  v7 = (char *)buf + 4;
  buf = v7;
  *(_DWORD *)v7 = i_slumlord;
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
  ((void (__thiscall *)(PackableList<unsigned long> *, void **, int))i_stuff->vfptr->Pack)(i_stuff, &buf, v4 + v6 - v8);
  v12 = Proto_UI::SendToWeenie(v6, v4);
  if ( !v12 )
    Proto_UI::UICounterFailedSend();
  return v12;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AA790) --------------------------------------------------------  // acclient.c:707542
bool __cdecl CM_House::Event_ListAvailableHouses(unsigned int i_houseType)
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
  *(_DWORD *)buf = 624;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_houseType;
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

//----- (006AA860) --------------------------------------------------------  // acclient.c:707592
bool __cdecl CM_House::Event_ModifyAllegianceGuestPermission(int i_add)
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
  *(_DWORD *)buf = 615;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_add;
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

//----- (006AA930) --------------------------------------------------------  // acclient.c:707642
bool __cdecl CM_House::Event_ModifyAllegianceStoragePermission(int i_add)
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
  *(_DWORD *)buf = 616;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_add;
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

//----- (006AAA00) --------------------------------------------------------  // acclient.c:707692
bool __cdecl CM_House::Event_QueryHouse()
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
  *(_DWORD *)buf = 542;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AAA90) --------------------------------------------------------  // acclient.c:707717
bool __cdecl CM_House::Event_QueryLord(unsigned int i_lord)
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
  *(_DWORD *)buf = 600;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_lord;
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

//----- (006AAB60) --------------------------------------------------------  // acclient.c:707767
bool __cdecl CM_House::Event_RemoveAllPermanentGuests_Event()
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
  *(_DWORD *)buf = 606;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AABF0) --------------------------------------------------------  // acclient.c:707792
bool __cdecl CM_House::Event_RemoveAllStoragePermission()
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
  *(_DWORD *)buf = 588;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AAC80) --------------------------------------------------------  // acclient.c:707817
bool __cdecl CM_House::Event_RentHouse(unsigned int i_slumlord, PackableList<unsigned long> *i_stuff)
{
  PackObjVtbl *v2; // eax@1
  int v3; // esi@1
  int v4; // esi@1
  void *v5; // eax@1
  char *v6; // ebx@1
  char *v7; // eax@1
  char *v8; // eax@1
  bool v9; // zf@1
  unsigned int v10; // ecx@1
  int v11; // edx@4
  bool v12; // bl@6
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  v2 = i_stuff->vfptr;
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v3 = ((int (__thiscall *)(PackableList<unsigned long> *, void **, _DWORD))v2->Pack)(i_stuff, &buf, 0);
  v4 = v3 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v5 = operator new[](v4);
  buf = v5;
  v6 = (char *)v5;
  OrderHdr::Pack(&hdr, &buf, v4);
  *(_DWORD *)buf = 545;
  v7 = (char *)buf + 4;
  buf = v7;
  *(_DWORD *)v7 = i_slumlord;
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
  ((void (__thiscall *)(PackableList<unsigned long> *, void **, int))i_stuff->vfptr->Pack)(i_stuff, &buf, v4 + v6 - v8);
  v12 = Proto_UI::SendToWeenie(v6, v4);
  if ( !v12 )
    Proto_UI::UICounterFailedSend();
  return v12;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AAD70) --------------------------------------------------------  // acclient.c:707880
bool __cdecl CM_House::Event_RequestFullGuestList_Event()
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
  *(_DWORD *)buf = 589;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AAE00) --------------------------------------------------------  // acclient.c:707905
bool __cdecl CM_House::Event_SetHooksVisibility(int i_bVisible)
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
  *(_DWORD *)buf = 614;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_bVisible;
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

//----- (006AAED0) --------------------------------------------------------  // acclient.c:707955
bool __cdecl CM_House::Event_SetOpenHouseStatus_Event(int i_open_house)
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
  *(_DWORD *)buf = 583;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_open_house;
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

//----- (006AAFA0) --------------------------------------------------------  // acclient.c:708005
bool __cdecl CM_House::Event_TeleToHouse_Event()
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
  *(_DWORD *)buf = 610;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AB030) --------------------------------------------------------  // acclient.c:708030
bool __cdecl CM_House::Event_TeleToMansion_Event()
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
  *(_DWORD *)buf = 632;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AB0C0) --------------------------------------------------------  // acclient.c:708055
char __cdecl CM_House::SendNotice_FailedHouseTransaction(unsigned int i_eType)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&byte_4DD226);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 292))(v4, i_eType);
    }
  }
  return 1;
}
// 4DD226: using guessed type char byte_4DD226;

//----- (006AB110) --------------------------------------------------------  // acclient.c:708082
char __cdecl CM_House::SendNotice_UpdateHouseData(HouseData *i_houseData)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&byte_4DD225);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, HouseData *))(*(_DWORD *)v4 + 296))(v4, i_houseData);
    }
  }
  return 1;
}
// 4DD225: using guessed type char byte_4DD225;

//----- (006AB160) --------------------------------------------------------  // acclient.c:708109
char __cdecl CM_House::SendNotice_UpdateHouseProfile(unsigned int i_iidOwner, HouseProfile *i_prof)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)byte_4DD229);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, HouseProfile *))(*(_DWORD *)v5 + 300))(v5, i_iidOwner, i_prof);
    }
  }
  return 1;
}

//----- (006AB1C0) --------------------------------------------------------  // acclient.c:708135
char __cdecl CM_House::SendNotice_UpdateRentPayment(HousePaymentList *i_rent)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&byte_4DD228);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, HousePaymentList *))(*(_DWORD *)v4 + 304))(v4, i_rent);
    }
  }
  return 1;
}
// 4DD228: using guessed type char byte_4DD228;

//----- (006AB210) --------------------------------------------------------  // acclient.c:708162
char __cdecl CM_House::SendNotice_UpdateRentTime(int i_rentTime)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&byte_4DD227);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 308))(v4, i_rentTime);
    }
  }
  return 1;
}
// 4DD227: using guessed type char byte_4DD227;

//----- (006AB260) --------------------------------------------------------  // acclient.c:708189
bool __cdecl CM_House::Event_AddPermanentGuest_Event(AC1Legacy::PStringBase<char> *i_guest_name)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_guest_name, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 581;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_guest_name, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AB320) --------------------------------------------------------  // acclient.c:708219
bool __cdecl CM_House::Event_BootSpecificHouseGuest_Event(AC1Legacy::PStringBase<char> *i_guest_name)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_guest_name, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 586;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_guest_name, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AB3E0) --------------------------------------------------------  // acclient.c:708249
bool __cdecl CM_House::Event_ChangeStoragePermission_Event(AC1Legacy::PStringBase<char> *i_guest_name, int i_has_permission)
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
  v2 = AC1Legacy::PStringBase<char>::Pack(i_guest_name, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v4 = operator new[](v3);
  buf = v4;
  v5 = (char *)v4;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 585;
  v6 = v3 + v5 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_guest_name, &buf, v6);
  *(_DWORD *)buf = i_has_permission;
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

//----- (006AB4E0) --------------------------------------------------------  // acclient.c:708300
bool __cdecl CM_House::Event_RemovePermanentGuest_Event(AC1Legacy::PStringBase<char> *i_guest_name)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_guest_name, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 582;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_guest_name, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AB5A0) --------------------------------------------------------  // acclient.c:708330
unsigned int __cdecl CM_House::DispatchUI_Recv_AvailableHouses(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  unsigned int v4; // esi@6
  unsigned int v5; // esi@6
  PackableList<unsigned long> houses; // [sp+4h] [bp-10h]@6

  if ( ui && ui->m_pHousingSystem )
  {
    if ( *(_DWORD *)buf == 625 )
    {
      v4 = *((_DWORD *)buf + 1);
      buf = (char *)buf + 8;
      houses.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
      houses.head = 0;
      houses.tail = 0;
      houses.curNum = 0;
      PackableList<unsigned long>::UnPack(&houses, &buf, size - 8);
      v5 = ClientHousingSystem::Handle_House__Recv_AvailableHouses(ui->m_pHousingSystem, v4, &houses, *(_DWORD *)buf);
      houses.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
      PackableList<unsigned long>::Flush(&houses);
      result = v5;
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
// 7A3E80: using guessed type int (__thiscall *PackableList<unsigned long>::vftable)(void *, char);

//----- (006AB640) --------------------------------------------------------  // acclient.c:708367
void __thiscall HouseData::~HouseData(HouseData *this)
{
  HouseData *v1; // esi@1
  char *v2; // edi@1

  v1 = this;
  v2 = (char *)&this->m_rent;
  this->m_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->m_rent.vfptr = (PackObjVtbl *)&HousePaymentList::vftable;
  PackableList<HousePayment>::Flush((PackableList<HousePayment> *)&this->m_rent.vfptr);
  *(_DWORD *)v2 = &PackObj::vftable;
  v1->m_buy.vfptr = (PackObjVtbl *)&HousePaymentList::vftable;
  PackableList<HousePayment>::Flush((PackableList<HousePayment> *)&v1->m_buy.vfptr);
  v1->m_buy.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E72E4: using guessed type int (__thiscall *HousePaymentList::vftable)(void *, char);

//----- (006AB680) --------------------------------------------------------  // acclient.c:708387
unsigned int __cdecl CM_House::DispatchUI_Recv_HouseProfile(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  int v4; // ecx@4
  void *v5; // esi@4
  char *v6; // eax@4
  unsigned int v7; // edi@6
  ClientHousingSystem *v8; // ecx@6
  unsigned int v9; // esi@6
  HouseProfile prof; // [sp+4h] [bp-4Ch]@6

  if ( ui && ui->m_pHousingSystem )
  {
    v4 = *(_DWORD *)buf;
    v5 = buf;
    v6 = (char *)buf + 4;
    buf = (char *)buf + 4;
    if ( v4 == 541 )
    {
      v7 = *(_DWORD *)v6;
      buf = v6 + 4;
      HouseProfile::HouseProfile(&prof);
      HouseProfile::UnPack(&prof, &buf, size + (_BYTE *)v5 - (_BYTE *)buf);
      v8 = ui->m_pHousingSystem;
      v9 = ClientHousingSystem::Handle_House__Recv_HouseProfile(v7, &prof);
      HouseProfile::~HouseProfile(&prof);
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

//----- (006AB710) --------------------------------------------------------  // acclient.c:708428
unsigned int __cdecl CM_House::DispatchUI_Recv_UpdateRentPayment(UIQueueManager *ui, void *buf, unsigned int size)
{
  void *v3; // eax@3
  char *v4; // ecx@3
  bool v5; // zf@3
  unsigned int result; // eax@4
  ClientHousingSystem *v7; // ecx@5
  unsigned int v8; // esi@5
  HousePaymentList list; // [sp+4h] [bp-10h]@5

  if ( ui
    && ui->m_pHousingSystem
    && (v3 = buf, v4 = (char *)buf + 4, v5 = *(_DWORD *)buf == 552, buf = (char *)buf + 4, v5) )
  {
    list.head = 0;
    list.tail = 0;
    list.curNum = 0;
    list.vfptr = (PackObjVtbl *)&HousePaymentList::vftable;
    PackableList<HousePayment>::UnPack((PackableList<HousePayment> *)&list.vfptr, &buf, size + (_BYTE *)v3 - v4);
    v7 = ui->m_pHousingSystem;
    v8 = ClientHousingSystem::Handle_House__Recv_UpdateRentPayment(&list);
    list.vfptr = (PackObjVtbl *)&HousePaymentList::vftable;
    PackableList<HousePayment>::Flush((PackableList<HousePayment> *)&list.vfptr);
    result = v8;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7E72E4: using guessed type int (__thiscall *HousePaymentList::vftable)(void *, char);

//----- (006AB7A0) --------------------------------------------------------  // acclient.c:708462
unsigned int __cdecl CM_House::DispatchUI_Recv_HouseData(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  int v4; // ecx@4
  void *v5; // esi@4
  ClientHousingSystem *v6; // ecx@6
  unsigned int v7; // esi@6
  HouseData data; // [sp+4h] [bp-7Ch]@6

  if ( ui && ui->m_pHousingSystem )
  {
    v4 = *(_DWORD *)buf;
    v5 = buf;
    buf = (char *)buf + 4;
    if ( v4 == 549 )
    {
      HouseData::HouseData(&data);
      HouseData::UnPack(&data, &buf, size + (_BYTE *)v5 - (_BYTE *)buf);
      v6 = ui->m_pHousingSystem;
      v7 = ClientHousingSystem::Handle_House__Recv_HouseData(&data);
      HouseData::~HouseData(&data);
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

//----- (007226D0) --------------------------------------------------------  // acclient.c:820251
void sub_7226D0()
{
  flt_8FA2BC = 1000.0 + 1.0;
}

//----- (007226F0) --------------------------------------------------------  // acclient.c:820257
void sub_7226F0()
{
  flt_8FA2C0 = 24.0 * 8.0;
}

//----- (00722710) --------------------------------------------------------  // acclient.c:820263
void sub_722710()
{
  flt_8FA2C4 = 24.0 * 0.5;
}

//----- (00722730) --------------------------------------------------------  // acclient.c:820269
int sub_722730()
{
  return atexit(nullsub_412);
}

//----- (00722740) --------------------------------------------------------  // acclient.c:820275
int sub_722740()
{
  return atexit(nullsub_413);
}

//----- (00722750) --------------------------------------------------------  // acclient.c:820281
int sub_722750()
{
  return atexit(nullsub_414);
}

//----- (00722760) --------------------------------------------------------  // acclient.c:820287
void sub_722760()
{
  flt_8FA2CC = 0.00019999999 * 3.0 + 0.1;
}

//----- (00722780) --------------------------------------------------------  // acclient.c:820293
void sub_722780()
{
  dbl_8FA2D0 = 1.0 / 30.0;
}

//----- (007227A0) --------------------------------------------------------  // acclient.c:820299
void _E110_92()
{
  dbl_8FA2D8 = 1.0 / 5.0;
}

//----- (007227C0) --------------------------------------------------------  // acclient.c:820305
void sub_7227C0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FA2E0, PFID_A8R8G8B8);
}

//----- (007227D0) --------------------------------------------------------  // acclient.c:820311
void sub_7227D0()
{
  dword_8FA318 = 1024;
}

//----- (007227E0) --------------------------------------------------------  // acclient.c:820317
void sub_7227E0()
{
  dword_8FA31C = 0x7FFF;
}

//----- (007227F0) --------------------------------------------------------  // acclient.c:820323
int _E119_44()
{
  const int result; // eax@1

  result = dword_8FA318;
  dword_8FA320 = dword_8FA318;
  return result;
}

//----- (00722800) --------------------------------------------------------  // acclient.c:820333
int sub_722800()
{
  return atexit(nullsub_410);
}

//----- (00722810) --------------------------------------------------------  // acclient.c:820339
int sub_722810()
{
  return atexit(nullsub_411);
}

