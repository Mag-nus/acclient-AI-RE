/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Allegiance
   Object     : GAME\game_cevents\CM_Allegiance.obj
   Functions  : 49
   Addresses  : 006A6920 - 00722080 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006A6920) --------------------------------------------------------  // acclient.c:703621
unsigned int __cdecl CM_Allegiance::DispatchUI_AllegianceLoginNotificationEvent(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pAllegianceSystem && *(_DWORD *)buf == 634 )
    result = ClientAllegianceSystem::Handle_Allegiance__AllegianceLoginNotificationEvent(
               *((_DWORD *)buf + 1),
               *((_DWORD *)buf + 2));
  else
    result = 0;
  return result;
}

//----- (006A6950) --------------------------------------------------------  // acclient.c:703635
unsigned int __cdecl CM_Allegiance::DispatchUI_AllegianceUpdateAborted(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pAllegianceSystem && *(_DWORD *)buf == 3 )
    result = ClientAllegianceSystem::Handle_Allegiance__AllegianceUpdateAborted(*((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006A6980) --------------------------------------------------------  // acclient.c:703647
bool __cdecl CM_Allegiance::Event_BreakAllegiance(unsigned int i_target)
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
  *(_DWORD *)buf = 30;
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

//----- (006A6A50) --------------------------------------------------------  // acclient.c:703697
bool __cdecl CM_Allegiance::Event_ClearAllegianceName()
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
  *(_DWORD *)buf = 49;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A6AE0) --------------------------------------------------------  // acclient.c:703722
bool __cdecl CM_Allegiance::Event_ClearAllegianceOfficerTitles()
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
  *(_DWORD *)buf = 62;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A6B70) --------------------------------------------------------  // acclient.c:703747
bool __cdecl CM_Allegiance::Event_ClearAllegianceOfficers()
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
  *(_DWORD *)buf = 679;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A6C00) --------------------------------------------------------  // acclient.c:703772
bool __cdecl CM_Allegiance::Event_ClearMotd()
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
  *(_DWORD *)buf = 598;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A6C90) --------------------------------------------------------  // acclient.c:703797
bool __cdecl CM_Allegiance::Event_DoAllegianceHouseAction(unsigned int i_iAction)
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
  *(_DWORD *)buf = 66;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_iAction;
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

//----- (006A6D60) --------------------------------------------------------  // acclient.c:703847
bool __cdecl CM_Allegiance::Event_DoAllegianceLockAction(unsigned int i_iAction)
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
  *(_DWORD *)buf = 63;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_iAction;
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

//----- (006A6E30) --------------------------------------------------------  // acclient.c:703897
bool __cdecl CM_Allegiance::Event_ListAllegianceBans()
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
  *(_DWORD *)buf = 675;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A6EC0) --------------------------------------------------------  // acclient.c:703922
bool __cdecl CM_Allegiance::Event_ListAllegianceOfficerTitles()
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
  *(_DWORD *)buf = 61;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A6F50) --------------------------------------------------------  // acclient.c:703947
bool __cdecl CM_Allegiance::Event_ListAllegianceOfficers()
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
  *(_DWORD *)buf = 678;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A6FE0) --------------------------------------------------------  // acclient.c:703972
bool __cdecl CM_Allegiance::Event_QueryAllegianceName()
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
  *(_DWORD *)buf = 48;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A7070) --------------------------------------------------------  // acclient.c:703997
bool __cdecl CM_Allegiance::Event_QueryMotd()
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
  *(_DWORD *)buf = 597;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A7100) --------------------------------------------------------  // acclient.c:704022
bool __cdecl CM_Allegiance::Event_RecallAllegianceHometown()
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
  *(_DWORD *)buf = 683;
  buf = (char *)buf + 4;
  v2 = Proto_UI::SendToWeenie(v1, v0);
  if ( !v2 )
    Proto_UI::UICounterFailedSend();
  return v2;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A7190) --------------------------------------------------------  // acclient.c:704047
bool __cdecl CM_Allegiance::Event_SwearAllegiance(unsigned int i_target)
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
  *(_DWORD *)buf = 29;
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

//----- (006A7260) --------------------------------------------------------  // acclient.c:704097
bool __cdecl CM_Allegiance::Event_UpdateRequest(int i_on)
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
  *(_DWORD *)buf = 31;
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

//----- (006A7330) --------------------------------------------------------  // acclient.c:704147
char __cdecl CM_Allegiance::SendNotice_AllegianceLogin(unsigned int i_iidMember, int i_bNowLoggedIn)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)&loc_4DD205);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, int))(*(_DWORD *)v5 + 100))(v5, i_iidMember, i_bNowLoggedIn);
    }
  }
  return 1;
}

//----- (006A7380) --------------------------------------------------------  // acclient.c:704173
char __cdecl CM_Allegiance::SendNotice_AllegianceUpdate(CAllegianceProfile *i_prof, unsigned int i_rank)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD205 + 1));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, CAllegianceProfile *, unsigned int))(*(_DWORD *)v5 + 104))(v5, i_prof, i_rank);
    }
  }
  return 1;
}

//----- (006A73D0) --------------------------------------------------------  // acclient.c:704199
char __cdecl CM_Allegiance::SendNotice_AllegianceUpdateAborted(unsigned int i_etype)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD207);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 108))(v4, i_etype);
    }
  }
  return 1;
}

//----- (006A7420) --------------------------------------------------------  // acclient.c:704225
char __cdecl CM_Allegiance::SendNotice_SwearAllegianceRequest(AC1Legacy::PStringBase<char> *i_strRequestor, unsigned int i_uiContextID)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD207 + 1));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, AC1Legacy::PStringBase<char> *, unsigned int))(*(_DWORD *)v5 + 112))(
          v5,
          i_strRequestor,
          i_uiContextID);
    }
  }
  return 1;
}

//----- (006A7470) --------------------------------------------------------  // acclient.c:704254
unsigned int __cdecl CM_Allegiance::DispatchUI_AllegianceInfoResponseEvent(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  int v4; // ecx@4
  void *v5; // esi@4
  char *v6; // eax@4
  unsigned int v7; // edi@6
  unsigned int v8; // esi@6
  CAllegianceProfile prof; // [sp+4h] [bp-118h]@6

  if ( ui && ui->m_pAllegianceSystem )
  {
    v4 = *(_DWORD *)buf;
    v5 = buf;
    v6 = (char *)buf + 4;
    buf = (char *)buf + 4;
    if ( v4 == 636 )
    {
      v7 = *(_DWORD *)v6;
      buf = v6 + 4;
      CAllegianceProfile::CAllegianceProfile(&prof);
      AllegianceProfile::UnPack((AllegianceProfile *)&prof.vfptr, &buf, size + (_BYTE *)v5 - (_BYTE *)buf);
      v8 = ClientAllegianceSystem::Handle_Allegiance__AllegianceInfoResponseEvent(ui->m_pAllegianceSystem, v7, &prof);
      AllegianceHierarchy::~AllegianceHierarchy(&prof._allegiance);
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

//----- (006A7520) --------------------------------------------------------  // acclient.c:704293
bool __cdecl CM_Allegiance::Event_AddAllegianceBan(AC1Legacy::PStringBase<char> *i_char_name)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_char_name, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 673;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_char_name, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A75E0) --------------------------------------------------------  // acclient.c:704323
bool __cdecl CM_Allegiance::Event_AllegianceChatBoot(AC1Legacy::PStringBase<char> *i_char_name, AC1Legacy::PStringBase<char> *i_reason)
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
  v2 = AC1Legacy::PStringBase<char>::Pack(i_char_name, &buf, 0);
  v3 = AC1Legacy::PStringBase<char>::Pack(i_reason, &buf, 0) + v2;
  v4 = v3 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v4);
  v5 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v4);
  *(_DWORD *)buf = 672;
  v6 = v4 + v5 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_char_name, &buf, v6);
  AC1Legacy::PStringBase<char>::Pack(i_reason, &buf, v4 + v5 - (_BYTE *)buf);
  v7 = Proto_UI::SendToWeenie(v5, v4);
  if ( !v7 )
    Proto_UI::UICounterFailedSend();
  return v7;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A76C0) --------------------------------------------------------  // acclient.c:704356
bool __cdecl CM_Allegiance::Event_AllegianceChatGag(AC1Legacy::PStringBase<char> *i_char_name, int i_bOn)
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
  v2 = AC1Legacy::PStringBase<char>::Pack(i_char_name, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v4 = operator new[](v3);
  buf = v4;
  v5 = (char *)v4;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 65;
  v6 = v3 + v5 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_char_name, &buf, v6);
  *(_DWORD *)buf = i_bOn;
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

//----- (006A77C0) --------------------------------------------------------  // acclient.c:704407
bool __cdecl CM_Allegiance::Event_AllegianceInfoRequest(AC1Legacy::PStringBase<char> *i_target_name)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_target_name, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 635;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_target_name, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A7880) --------------------------------------------------------  // acclient.c:704437
bool __cdecl CM_Allegiance::Event_BreakAllegianceBoot(AC1Legacy::PStringBase<char> *i_bootee_name, int i_account_boot)
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
  v2 = AC1Legacy::PStringBase<char>::Pack(i_bootee_name, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v4 = operator new[](v3);
  buf = v4;
  v5 = (char *)v4;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 631;
  v6 = v3 + v5 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_bootee_name, &buf, v6);
  *(_DWORD *)buf = i_account_boot;
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

//----- (006A7980) --------------------------------------------------------  // acclient.c:704488
bool __cdecl CM_Allegiance::Event_RemoveAllegianceBan(AC1Legacy::PStringBase<char> *i_char_name)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_char_name, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 674;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_char_name, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A7A40) --------------------------------------------------------  // acclient.c:704518
bool __cdecl CM_Allegiance::Event_RemoveAllegianceOfficer(AC1Legacy::PStringBase<char> *i_char_name)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_char_name, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 677;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_char_name, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A7B00) --------------------------------------------------------  // acclient.c:704548
bool __cdecl CM_Allegiance::Event_SetAllegianceApprovedVassal(AC1Legacy::PStringBase<char> *i_char_name)
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
  v1 = AC1Legacy::PStringBase<char>::Pack(i_char_name, &buf, 0);
  v2 = v1 + OrderHdr::Pack(&hdr, &buf, 0) + 4;
  buf = operator new[](v2);
  v3 = (char *)buf;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 64;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_char_name, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A7BC0) --------------------------------------------------------  // acclient.c:704578
bool __cdecl CM_Allegiance::Event_SetAllegianceName(AC1Legacy::PStringBase<char> *i_msg)
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
  *(_DWORD *)buf = 51;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_msg, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A7C80) --------------------------------------------------------  // acclient.c:704608
bool __cdecl CM_Allegiance::Event_SetAllegianceOfficer(AC1Legacy::PStringBase<char> *i_char_name, unsigned int i_level)
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
  v2 = AC1Legacy::PStringBase<char>::Pack(i_char_name, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v4 = operator new[](v3);
  buf = v4;
  v5 = (char *)v4;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 59;
  v6 = v3 + v5 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_char_name, &buf, v6);
  *(_DWORD *)buf = i_level;
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

//----- (006A7D80) --------------------------------------------------------  // acclient.c:704659
bool __cdecl CM_Allegiance::Event_SetAllegianceOfficerTitle(unsigned int i_level, AC1Legacy::PStringBase<char> *i_title)
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
  v2 = AC1Legacy::PStringBase<char>::Pack(i_title, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v4 = operator new[](v3);
  buf = v4;
  v5 = (char *)v4;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 60;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_level;
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
  AC1Legacy::PStringBase<char>::Pack(i_title, &buf, v3 + v5 - v7);
  v11 = Proto_UI::SendToWeenie(v5, v3);
  if ( !v11 )
    Proto_UI::UICounterFailedSend();
  return v11;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A7E70) --------------------------------------------------------  // acclient.c:704720
bool __cdecl CM_Allegiance::Event_SetMotd(AC1Legacy::PStringBase<char> *i_msg)
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
  *(_DWORD *)buf = 596;
  v4 = v2 + v3 - ((_BYTE *)buf + 4);
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack(i_msg, &buf, v4);
  v5 = Proto_UI::SendToWeenie(v3, v2);
  if ( !v5 )
    Proto_UI::UICounterFailedSend();
  return v5;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (00721F40) --------------------------------------------------------  // acclient.c:819725
void sub_721F40()
{
  flt_8FA004 = 1000.0 + 1.0;
}

//----- (00721F60) --------------------------------------------------------  // acclient.c:819731
void sub_721F60()
{
  flt_8FA008 = 24.0 * 8.0;
}

//----- (00721F80) --------------------------------------------------------  // acclient.c:819737
void sub_721F80()
{
  flt_8FA00C = 24.0 * 0.5;
}

//----- (00721FA0) --------------------------------------------------------  // acclient.c:819743
int sub_721FA0()
{
  return atexit(nullsub_374);
}

//----- (00721FB0) --------------------------------------------------------  // acclient.c:819749
int sub_721FB0()
{
  return atexit(nullsub_375);
}

//----- (00721FC0) --------------------------------------------------------  // acclient.c:819755
int sub_721FC0()
{
  return atexit(nullsub_376);
}

//----- (00721FD0) --------------------------------------------------------  // acclient.c:819761
void sub_721FD0()
{
  flt_8FA014 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00721FF0) --------------------------------------------------------  // acclient.c:819767
void sub_721FF0()
{
  dbl_8FA018 = 1.0 / 30.0;
}

//----- (00722010) --------------------------------------------------------  // acclient.c:819773
void _E110_88()
{
  dbl_8FA020 = 1.0 / 5.0;
}

//----- (00722030) --------------------------------------------------------  // acclient.c:819779
void sub_722030()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FA028, PFID_A8R8G8B8);
}

//----- (00722040) --------------------------------------------------------  // acclient.c:819785
void sub_722040()
{
  dword_8FA060 = 1024;
}

//----- (00722050) --------------------------------------------------------  // acclient.c:819791
void _E117_95()
{
  dword_8FA064 = 0x7FFF;
}

//----- (00722060) --------------------------------------------------------  // acclient.c:819797
int _E119_40()
{
  const int result; // eax@1

  result = dword_8FA060;
  dword_8FA068 = dword_8FA060;
  return result;
}

//----- (00722070) --------------------------------------------------------  // acclient.c:819807
int sub_722070()
{
  return atexit(nullsub_372);
}

//----- (00722080) --------------------------------------------------------  // acclient.c:819813
int sub_722080()
{
  return atexit(nullsub_373);
}

