/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Vendor
   Object     : GAME\game_cevents\CM_Vendor.obj
   Functions  : 12
   Addresses  : 006AA000 - 007226C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006AA000) --------------------------------------------------------  // acclient.c:707060
bool __cdecl CM_Vendor::Event_Sell(unsigned int i_vendorID, PackableList<ItemProfile> *i_stuff)
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
  v3 = ((int (__thiscall *)(PackableList<ItemProfile> *, void **, _DWORD))v2->Pack)(i_stuff, &buf, 0);
  v4 = v3 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v5 = operator new[](v4);
  buf = v5;
  v6 = (char *)v5;
  OrderHdr::Pack(&hdr, &buf, v4);
  *(_DWORD *)buf = 96;
  v7 = (char *)buf + 4;
  buf = v7;
  *(_DWORD *)v7 = i_vendorID;
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
  ((void (__thiscall *)(PackableList<ItemProfile> *, void **, int))i_stuff->vfptr->Pack)(i_stuff, &buf, v4 + v6 - v8);
  v12 = Proto_UI::SendToWeenie(v6, v4);
  if ( !v12 )
    Proto_UI::UICounterFailedSend();
  return v12;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AA0F0) --------------------------------------------------------  // acclient.c:707123
bool __cdecl CM_Vendor::Event_Buy(unsigned int i_vendorID, PackableList<ItemProfile> *i_stuff, IDClass<_tagDataID,32,0> i_alternateCurrencyID)
{
  PackObjVtbl *v3; // eax@1
  int v4; // esi@1
  int v5; // esi@1
  void *v6; // eax@1
  char *v7; // ebx@1
  char *v8; // eax@1
  char *v9; // eax@1
  bool v10; // zf@1
  unsigned int v11; // ecx@1
  int v12; // edx@4
  int v13; // eax@6
  int v14; // ecx@7
  bool v15; // bl@9
  void *buf; // [sp+10h] [bp-Ch]@1
  OrderHdr hdr; // [sp+14h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  v3 = i_stuff->vfptr;
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v4 = ((int (__thiscall *)(PackableList<ItemProfile> *, void **, _DWORD))v3->Pack)(i_stuff, &buf, 0);
  v5 = v4 + OrderHdr::Pack(&hdr, &buf, 0) + 12;
  v6 = operator new[](v5);
  buf = v6;
  v7 = (char *)v6;
  OrderHdr::Pack(&hdr, &buf, v5);
  *(_DWORD *)buf = 95;
  v8 = (char *)buf + 4;
  buf = v8;
  *(_DWORD *)v8 = i_vendorID;
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
  ((void (__thiscall *)(PackableList<ItemProfile> *, void **, int))i_stuff->vfptr->Pack)(i_stuff, &buf, v5 + v7 - v9);
  *(_DWORD *)buf = i_alternateCurrencyID.id;
  buf = (char *)buf + 4;
  v13 = (signed int)buf % 4;
  if ( (signed int)buf % 4 )
  {
    v14 = 4 - v13;
    if ( 4 != v13 )
    {
      do
      {
        *(_BYTE *)buf = 0;
        --v14;
        buf = (char *)buf + 1;
      }
      while ( v14 );
    }
  }
  v15 = Proto_UI::SendToWeenie(v7, v5);
  if ( !v15 )
    Proto_UI::UICounterFailedSend();
  return v15;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006AA220) --------------------------------------------------------  // acclient.c:707205
char __cdecl CM_Vendor::SendNotice_AddItemToSell(unsigned int i_itemID)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD218);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 652))(v4, i_itemID);
    }
  }
  return 1;
}

//----- (006AA270) --------------------------------------------------------  // acclient.c:707231
char __cdecl CM_Vendor::SendNotice_CloseVendor(int i_bUpdating)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD250 + 3));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 656))(v4, i_bUpdating);
    }
  }
  return 1;
}

//----- (006AA2C0) --------------------------------------------------------  // acclient.c:707257
char __cdecl CM_Vendor::SendNotice_OpenVendor(unsigned int i_vendorID, VendorProfile *i_vendorProfile, PackableList<ItemProfile> *i_itemProfileList, ShopMode i_startMode)
{
  gmGlobalEventHandler *v4; // eax@1
  int v5; // eax@1
  int v6; // edi@2
  int v7; // esi@3
  bool v8; // zf@3

  v4 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v5 = (int)v4->vfptr->GetNoticeHandlers((NoticeRegistrar *)v4, (unsigned int)((char *)&loc_4DD20C + 2));
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 + 4);
    while ( v6 )
    {
      v7 = *(_DWORD *)v6;
      v8 = *(_DWORD *)v6 == 0;
      v6 = *(_DWORD *)(v6 + 4);
      if ( !v8 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v7)(v7) )
        (*(void (__thiscall **)(int, unsigned int, VendorProfile *, PackableList<ItemProfile> *, ShopMode))(*(_DWORD *)v7 + 660))(
          v7,
          i_vendorID,
          i_vendorProfile,
          i_itemProfileList,
          i_startMode);
    }
  }
  return 1;
}

//----- (00722630) --------------------------------------------------------  // acclient.c:820209
void sub_722630()
{
  flt_8FA294 = 1000.0 + 1.0;
}

//----- (00722650) --------------------------------------------------------  // acclient.c:820215
void sub_722650()
{
  flt_8FA298 = 24.0 * 8.0;
}

//----- (00722670) --------------------------------------------------------  // acclient.c:820221
void sub_722670()
{
  flt_8FA29C = 24.0 * 0.5;
}

//----- (00722690) --------------------------------------------------------  // acclient.c:820227
int sub_722690()
{
  return atexit(nullsub_466);
}

//----- (007226A0) --------------------------------------------------------  // acclient.c:820233
int sub_7226A0()
{
  return atexit(nullsub_467);
}

//----- (007226B0) --------------------------------------------------------  // acclient.c:820239
int sub_7226B0()
{
  return atexit(nullsub_468);
}

//----- (007226C0) --------------------------------------------------------  // acclient.c:820245
int sub_7226C0()
{
  return atexit(nullsub_465);
}

