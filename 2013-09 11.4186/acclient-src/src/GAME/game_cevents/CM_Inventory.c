/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Inventory
   Object     : GAME\game_cevents\CM_Inventory.obj
   Functions  : 30
   Addresses  : 006AB830 - 00722960 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006AB830) --------------------------------------------------------  // acclient.c:708498
bool __cdecl CM_Inventory::Event_CreateTinkeringTool(unsigned int i_toolID, PackableList<unsigned long> *i_gems)
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
  v2 = i_gems->vfptr;
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v3 = ((int (__thiscall *)(PackableList<unsigned long> *, void **, _DWORD))v2->Pack)(i_gems, &buf, 0);
  v4 = v3 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v5 = operator new[](v4);
  buf = v5;
  v6 = (char *)v5;
  OrderHdr::Pack(&hdr, &buf, v4);
  *(_DWORD *)buf = 637;
  v7 = (char *)buf + 4;
  buf = v7;
  *(_DWORD *)v7 = i_toolID;
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
  ((void (__thiscall *)(PackableList<unsigned long> *, void **, int))i_gems->vfptr->Pack)(i_gems, &buf, v4 + v6 - v8);
  v12 = Proto_UI::SendToWeenie(v6, v4);
  if ( !v12 )
    Proto_UI::UICounterFailedSend();
  return v12;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AB920) --------------------------------------------------------  // acclient.c:708561
bool __cdecl CM_Inventory::Event_DropItem(unsigned int i_item)
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
  *(_DWORD *)buf = 27;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_item;
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

//----- (006AB9F0) --------------------------------------------------------  // acclient.c:708611
bool __cdecl CM_Inventory::Event_GetAndWieldItem(unsigned int i_item, unsigned int i_loc)
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
  *(_DWORD *)buf = 26;
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

//----- (006ABB00) --------------------------------------------------------  // acclient.c:708690
bool __cdecl CM_Inventory::Event_GiveObjectRequest(unsigned int i_targetID, unsigned int i_objectID, unsigned int i_amount)
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
  *(_DWORD *)buf = 205;
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
  *(_DWORD *)v8 = i_objectID;
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
  *(_DWORD *)v12 = i_amount;
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

//----- (006ABC50) --------------------------------------------------------  // acclient.c:708798
bool __cdecl CM_Inventory::Event_NoLongerViewingContents(unsigned int i_container)
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
  *(_DWORD *)buf = 405;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_container;
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

//----- (006ABD20) --------------------------------------------------------  // acclient.c:708848
bool __cdecl CM_Inventory::Event_PutItemInContainer(unsigned int i_item, unsigned int i_container, unsigned int i_loc)
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
  *(_DWORD *)buf = 25;
  v7 = (char *)buf + 4;
  buf = v7;
  *(_DWORD *)v7 = i_item;
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
  *(_DWORD *)v8 = i_container;
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
  *(_DWORD *)v12 = i_loc;
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

//----- (006ABE70) --------------------------------------------------------  // acclient.c:708956
bool __cdecl CM_Inventory::Event_StackableMerge(unsigned int i_mergeFromID, unsigned int i_mergeToID, int i_amount)
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
  *(_DWORD *)buf = 84;
  v7 = (char *)buf + 4;
  buf = v7;
  *(_DWORD *)v7 = i_mergeFromID;
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
  *(_DWORD *)v8 = i_mergeToID;
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
  *(_DWORD *)v12 = i_amount;
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

//----- (006ABFC0) --------------------------------------------------------  // acclient.c:709064
bool __cdecl CM_Inventory::Event_StackableSplitTo3D(unsigned int i_stackID, int i_amount)
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
  *(_DWORD *)buf = 86;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_stackID;
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

//----- (006AC0D0) --------------------------------------------------------  // acclient.c:709143
bool __cdecl CM_Inventory::Event_StackableSplitToContainer(unsigned int i_stackID, unsigned int i_containerID, int i_place, int i_amount)
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
  *(_DWORD *)buf = 85;
  v8 = (char *)buf + 4;
  buf = v8;
  *(_DWORD *)v8 = i_stackID;
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
  *(_DWORD *)v9 = i_containerID;
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
  *(_DWORD *)v13 = i_place;
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
  *(_DWORD *)v17 = i_amount;
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

//----- (006AC260) --------------------------------------------------------  // acclient.c:709280
bool __cdecl CM_Inventory::Event_StackableSplitToWield(unsigned int i_stackID, unsigned int i_loc, int i_amount)
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
  *(_DWORD *)buf = 411;
  v7 = (char *)buf + 4;
  buf = v7;
  *(_DWORD *)v7 = i_stackID;
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
  *(_DWORD *)v8 = i_loc;
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
  *(_DWORD *)v12 = i_amount;
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

//----- (006AC3B0) --------------------------------------------------------  // acclient.c:709388
bool __cdecl CM_Inventory::Event_UseEvent(unsigned int i_object)
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
  *(_DWORD *)buf = 54;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_object;
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

//----- (006AC480) --------------------------------------------------------  // acclient.c:709438
bool __cdecl CM_Inventory::Event_UseWithTargetEvent(unsigned int i_object, unsigned int i_target)
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
  *(_DWORD *)buf = 53;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_object;
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
  *(_DWORD *)v7 = i_target;
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

//----- (006AC590) --------------------------------------------------------  // acclient.c:709517
char __cdecl CM_Inventory::SendNotice_OpenSalvagePanel(unsigned int i_toolID)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)nullsub_1891 + 1));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 316))(v4, i_toolID);
    }
  }
  return 1;
}
// 4DD221: using guessed type int __stdcall nullsub_1891(int);

//----- (006AC5E0) --------------------------------------------------------  // acclient.c:709544
void __thiscall SalvageOperationsResultData::~SalvageOperationsResultData(SalvageOperationsResultData *this)
{
  SalvageOperationsResultData *v1; // esi@1
  char *v2; // edi@1

  v1 = this;
  v2 = (char *)&this->m_salvageResults;
  this->m_salvageResults.vfptr = (PackObjVtbl *)&PackableList<SalvageResult>::vftable;
  PackableList<SalvageResult>::Flush(&this->m_salvageResults);
  *(_DWORD *)v2 = &PackObj::vftable;
  v1->m_notSalvagable.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
  PackableList<unsigned long>::Flush(&v1->m_notSalvagable);
  v1->m_notSalvagable.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A3E80: using guessed type int (__thiscall *PackableList<unsigned long>::vftable)(void *, char);
// 7E7F1C: using guessed type int (__thiscall *PackableList<SalvageResult>::vftable)(void *, char);

//----- (006AC620) --------------------------------------------------------  // acclient.c:709564
unsigned int __cdecl CM_Inventory::DispatchUI_Recv_SalvageOperationsResultData(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  int v4; // ecx@4
  void *v5; // esi@4
  unsigned int v6; // esi@6
  SalvageOperationsResultData operationsResultData; // [sp+4h] [bp-38h]@6

  if ( ui && ui->m_pUISystem )
  {
    v4 = *(_DWORD *)buf;
    v5 = buf;
    buf = (char *)buf + 4;
    if ( v4 == 692 )
    {
      SalvageOperationsResultData::SalvageOperationsResultData(&operationsResultData);
      SalvageOperationsResultData::UnPack(&operationsResultData, &buf, size + (_BYTE *)v5 - (_BYTE *)buf);
      v6 = ClientUISystem::Handle_Inventory__Recv_SalvageOperationsResultData(ui->m_pUISystem, &operationsResultData);
      SalvageOperationsResultData::~SalvageOperationsResultData(&operationsResultData);
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

//----- (00722820) --------------------------------------------------------  // acclient.c:820345
void sub_722820()
{
  flt_8FA348 = 1000.0 + 1.0;
}

//----- (00722840) --------------------------------------------------------  // acclient.c:820351
void sub_722840()
{
  flt_8FA34C = 24.0 * 8.0;
}

//----- (00722860) --------------------------------------------------------  // acclient.c:820357
void sub_722860()
{
  flt_8FA350 = 24.0 * 0.5;
}

//----- (00722880) --------------------------------------------------------  // acclient.c:820363
int sub_722880()
{
  return atexit(nullsub_417);
}

//----- (00722890) --------------------------------------------------------  // acclient.c:820369
int sub_722890()
{
  return atexit(nullsub_418);
}

//----- (007228A0) --------------------------------------------------------  // acclient.c:820375
int sub_7228A0()
{
  return atexit(nullsub_419);
}

//----- (007228B0) --------------------------------------------------------  // acclient.c:820381
void sub_7228B0()
{
  flt_8FA354 = 0.00019999999 * 3.0 + 0.1;
}

//----- (007228D0) --------------------------------------------------------  // acclient.c:820387
void sub_7228D0()
{
  dbl_8FA358 = 1.0 / 30.0;
}

//----- (007228F0) --------------------------------------------------------  // acclient.c:820393
void _E110_93()
{
  dbl_8FA360 = 1.0 / 5.0;
}

//----- (00722910) --------------------------------------------------------  // acclient.c:820399
void sub_722910()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FA368, PFID_A8R8G8B8);
}

//----- (00722920) --------------------------------------------------------  // acclient.c:820405
void sub_722920()
{
  dword_8FA3A0 = 1024;
}

//----- (00722930) --------------------------------------------------------  // acclient.c:820411
void sub_722930()
{
  dword_8FA3A4 = 0x7FFF;
}

//----- (00722940) --------------------------------------------------------  // acclient.c:820417
int _E119_45()
{
  const int result; // eax@1

  result = dword_8FA3A0;
  dword_8FA3A8 = dword_8FA3A0;
  return result;
}

//----- (00722950) --------------------------------------------------------  // acclient.c:820427
int sub_722950()
{
  return atexit(nullsub_415);
}

//----- (00722960) --------------------------------------------------------  // acclient.c:820433
int sub_722960()
{
  return atexit(nullsub_416);
}

