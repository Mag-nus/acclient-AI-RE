/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Writing
   Object     : GAME\game_cevents\CM_Writing.obj
   Functions  : 17
   Addresses  : 006A9230 - 007224D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006A9230) --------------------------------------------------------  // acclient.c:706079
bool __cdecl CM_Writing::Event_BookAddPage(unsigned int i_objectID)
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
  *(_DWORD *)buf = 172;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_objectID;
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

//----- (006A9300) --------------------------------------------------------  // acclient.c:706129
bool __cdecl CM_Writing::Event_BookData(unsigned int i_objectID)
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
  *(_DWORD *)buf = 170;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_objectID;
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

//----- (006A93D0) --------------------------------------------------------  // acclient.c:706179
bool __cdecl CM_Writing::Event_BookDeletePage(unsigned int i_objectID, int i_pageNum)
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
  *(_DWORD *)buf = 173;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_objectID;
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
  *(_DWORD *)v7 = i_pageNum;
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

//----- (006A94E0) --------------------------------------------------------  // acclient.c:706258
bool __cdecl CM_Writing::Event_BookPageData(unsigned int i_objectID, int i_pageNum)
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
  *(_DWORD *)buf = 174;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_objectID;
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
  *(_DWORD *)v7 = i_pageNum;
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

//----- (006A95F0) --------------------------------------------------------  // acclient.c:706337
char __cdecl CM_Writing::SendNotice_BookAddPageResponse(unsigned int i_bookID, int i_pageNum, int i_success)
{
  gmGlobalEventHandler *v3; // eax@1
  int v4; // eax@1
  int v5; // edi@2
  int v6; // esi@3
  bool v7; // zf@3

  v3 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v4 = (int)v3->vfptr->GetNoticeHandlers((NoticeRegistrar *)v3, (unsigned int)((char *)&loc_4DD1E9 + 1));
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    while ( v5 )
    {
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 == 0;
      v5 = *(_DWORD *)(v5 + 4);
      if ( !v7 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v6)(v6) )
        (*(void (__thiscall **)(int, unsigned int, int, int))(*(_DWORD *)v6 + 664))(v6, i_bookID, i_pageNum, i_success);
    }
  }
  return 1;
}

//----- (006A9650) --------------------------------------------------------  // acclient.c:706363
char __cdecl CM_Writing::SendNotice_BookDeletePageResponse(unsigned int i_bookID, int i_pageNum, int i_success)
{
  gmGlobalEventHandler *v3; // eax@1
  int v4; // eax@1
  int v5; // edi@2
  int v6; // esi@3
  bool v7; // zf@3

  v3 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v4 = (int)v3->vfptr->GetNoticeHandlers((NoticeRegistrar *)v3, (unsigned int)((char *)&loc_4DD1E9 + 2));
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    while ( v5 )
    {
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 == 0;
      v5 = *(_DWORD *)(v5 + 4);
      if ( !v7 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v6)(v6) )
        (*(void (__thiscall **)(int, unsigned int, int, int))(*(_DWORD *)v6 + 668))(v6, i_bookID, i_pageNum, i_success);
    }
  }
  return 1;
}

//----- (006A96B0) --------------------------------------------------------  // acclient.c:706389
char __cdecl CM_Writing::SendNotice_BookPageDataResponse(unsigned int i_bookID, int i_pageNum, PageData *i_pageData)
{
  gmGlobalEventHandler *v3; // eax@1
  int v4; // eax@1
  int v5; // edi@2
  int v6; // esi@3
  bool v7; // zf@3

  v3 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v4 = (int)v3->vfptr->GetNoticeHandlers((NoticeRegistrar *)v3, (unsigned int)&loc_4DD1EC);
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    while ( v5 )
    {
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 == 0;
      v5 = *(_DWORD *)(v5 + 4);
      if ( !v7 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v6)(v6) )
        (*(void (__thiscall **)(int, unsigned int, int, PageData *))(*(_DWORD *)v6 + 672))(
          v6,
          i_bookID,
          i_pageNum,
          i_pageData);
    }
  }
  return 1;
}

//----- (006A9710) --------------------------------------------------------  // acclient.c:706419
char __cdecl CM_Writing::SendNotice_OpenBook(unsigned int i_bookID, int i_maxNumPages, PageDataList *i_pageDataList, AC1Legacy::PStringBase<char> *i_inscription, unsigned int i_scribeID, AC1Legacy::PStringBase<char> *i_scribeName)
{
  gmGlobalEventHandler *v6; // eax@1
  int v7; // eax@1
  int v8; // edi@2
  int v9; // esi@3
  bool v10; // zf@3

  v6 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v7 = (int)v6->vfptr->GetNoticeHandlers((NoticeRegistrar *)v6, (unsigned int)&loc_4DD1E9);
  if ( v7 )
  {
    v8 = *(_DWORD *)(v7 + 4);
    while ( v8 )
    {
      v9 = *(_DWORD *)v8;
      v10 = *(_DWORD *)v8 == 0;
      v8 = *(_DWORD *)(v8 + 4);
      if ( !v10 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v9)(v9) )
        (*(void (__thiscall **)(int, unsigned int, int, PageDataList *, AC1Legacy::PStringBase<char> *, unsigned int, AC1Legacy::PStringBase<char> *))(*(_DWORD *)v9 + 676))(
          v9,
          i_bookID,
          i_maxNumPages,
          i_pageDataList,
          i_inscription,
          i_scribeID,
          i_scribeName);
    }
  }
  return 1;
}

//----- (006A9780) --------------------------------------------------------  // acclient.c:706452
bool __cdecl CM_Writing::Event_BookModifyPage(unsigned int i_objectID, int i_pageNum, AC1Legacy::PStringBase<char> *i_pageText)
{
  int v3; // esi@1
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
  bool v16; // bl@11
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v3 = AC1Legacy::PStringBase<char>::Pack(i_pageText, &buf, 0);
  v4 = v3 + OrderHdr::Pack(&hdr, &buf, 0) + 12;
  v5 = operator new[](v4);
  buf = v5;
  v6 = (char *)v5;
  OrderHdr::Pack(&hdr, &buf, v4);
  *(_DWORD *)buf = 171;
  v7 = (char *)buf + 4;
  buf = v7;
  *(_DWORD *)v7 = i_objectID;
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
  *(_DWORD *)v8 = i_pageNum;
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
  AC1Legacy::PStringBase<char>::Pack(i_pageText, &buf, v4 + v6 - v12);
  v16 = Proto_UI::SendToWeenie(v6, v4);
  if ( !v16 )
    Proto_UI::UICounterFailedSend();
  return v16;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A98B0) --------------------------------------------------------  // acclient.c:706542
bool __cdecl CM_Writing::Event_SetInscription(unsigned int i_objectID, AC1Legacy::PStringBase<char> *i_inscription)
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
  v2 = AC1Legacy::PStringBase<char>::Pack(i_inscription, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v4 = operator new[](v3);
  buf = v4;
  v5 = (char *)v4;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 191;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_objectID;
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
  AC1Legacy::PStringBase<char>::Pack(i_inscription, &buf, v3 + v5 - v7);
  v11 = Proto_UI::SendToWeenie(v5, v3);
  if ( !v11 )
    Proto_UI::UICounterFailedSend();
  return v11;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (00722440) --------------------------------------------------------  // acclient.c:820073
void sub_722440()
{
  flt_8FA1E4 = 1000.0 + 1.0;
}

//----- (00722460) --------------------------------------------------------  // acclient.c:820079
void sub_722460()
{
  flt_8FA1E8 = 24.0 * 8.0;
}

//----- (00722480) --------------------------------------------------------  // acclient.c:820085
void sub_722480()
{
  flt_8FA1EC = 24.0 * 0.5;
}

//----- (007224A0) --------------------------------------------------------  // acclient.c:820091
int sub_7224A0()
{
  return atexit(nullsub_470);
}

//----- (007224B0) --------------------------------------------------------  // acclient.c:820097
int sub_7224B0()
{
  return atexit(nullsub_471);
}

//----- (007224C0) --------------------------------------------------------  // acclient.c:820103
int sub_7224C0()
{
  return atexit(nullsub_472);
}

//----- (007224D0) --------------------------------------------------------  // acclient.c:820109
int sub_7224D0()
{
  return atexit(nullsub_469);
}

