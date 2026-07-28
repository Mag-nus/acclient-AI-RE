/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ECM_UI
   Object     : ENGINE\engine_cevents\ECM_UI.obj
   Functions  : 11
   Addresses  : 00692500 - 00692810 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00692500) --------------------------------------------------------  // acclient.c:681852
char __cdecl ECM_UI::SendNotice_CloseDialog(unsigned int i_context, PropertyCollection *i_data)
{
  GlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // esi@2
  int v5; // ecx@3
  bool v6; // zf@3

  v2 = GlobalEventHandler::GetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, 100004u);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 )
        (*(void (__stdcall **)(unsigned int, PropertyCollection *))(*(_DWORD *)v5 + 52))(i_context, i_data);
    }
  }
  return 1;
}

//----- (00692550) --------------------------------------------------------  // acclient.c:681878
char __cdecl ECM_UI::SendNotice_DisplayFinalStringInfo(unsigned int i_lt, StringInfo *i_siMessage, StringInfo *i_siPrefix, unsigned int i_idDestinationOverride)
{
  GlobalEventHandler *v4; // eax@1
  int v5; // eax@1
  int v6; // esi@2
  int v7; // ecx@3
  bool v8; // zf@3

  v4 = GlobalEventHandler::GetGlobalEventHandler();
  v5 = (int)v4->vfptr->GetNoticeHandlers((NoticeRegistrar *)v4, 100022u);
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 + 4);
    while ( v6 )
    {
      v7 = *(_DWORD *)v6;
      v8 = *(_DWORD *)v6 == 0;
      v6 = *(_DWORD *)(v6 + 4);
      if ( !v8 )
        (*(void (__stdcall **)(unsigned int, StringInfo *, StringInfo *, unsigned int))(*(_DWORD *)v7 + 56))(
          i_lt,
          i_siMessage,
          i_siPrefix,
          i_idDestinationOverride);
    }
  }
  return 1;
}

//----- (006925B0) --------------------------------------------------------  // acclient.c:681908
char __cdecl ECM_UI::SendNotice_DisplayStringInfo(unsigned int i_lt, StringInfo *i_si)
{
  GlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // esi@2
  int v5; // ecx@3
  bool v6; // zf@3

  v2 = GlobalEventHandler::GetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, 100005u);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 )
        (*(void (__stdcall **)(unsigned int, StringInfo *))(*(_DWORD *)v5 + 60))(i_lt, i_si);
    }
  }
  return 1;
}

//----- (00692600) --------------------------------------------------------  // acclient.c:681934
char __cdecl ECM_UI::SendNotice_DisplayWeenieError(unsigned int i_etype, AC1Legacy::PStringBase<char> *i_user_data)
{
  GlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // esi@2
  int v5; // ecx@3
  bool v6; // zf@3

  v2 = GlobalEventHandler::GetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, 100023u);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 )
        (*(void (__stdcall **)(unsigned int, AC1Legacy::PStringBase<char> *))(*(_DWORD *)v5 + 64))(i_etype, i_user_data);
    }
  }
  return 1;
}

//----- (00692650) --------------------------------------------------------  // acclient.c:681960
char __cdecl ECM_UI::SendNotice_OpenDialog(unsigned int i_context)
{
  GlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // ecx@3
  bool v5; // zf@3

  v1 = GlobalEventHandler::GetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, 100003u);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 )
        (*(void (__stdcall **)(unsigned int))(*(_DWORD *)v4 + 68))(i_context);
    }
  }
  return 1;
}

//----- (00692690) --------------------------------------------------------  // acclient.c:681986
char __cdecl ECM_UI::SendNotice_SmartBoxObjectFound(unsigned int i_iidObject)
{
  GlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // ecx@3
  bool v5; // zf@3

  v1 = GlobalEventHandler::GetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, 100007u);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 )
        (*(void (__stdcall **)(unsigned int))(*(_DWORD *)v4 + 72))(i_iidObject);
    }
  }
  return 1;
}

//----- (006926D0) --------------------------------------------------------  // acclient.c:682012
char __cdecl ECM_UI::SendNotice_TextTag_DIDClick(unsigned int i_eType, IDClass<_tagDataID,32,0> i_did)
{
  GlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // esi@2
  int v5; // ecx@3
  bool v6; // zf@3

  v2 = GlobalEventHandler::GetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, 100019u);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 )
        (*(void (__stdcall **)(unsigned int, unsigned int))(*(_DWORD *)v5 + 76))(i_eType, i_did.id);
    }
  }
  return 1;
}

//----- (00692720) --------------------------------------------------------  // acclient.c:682038
char __cdecl ECM_UI::SendNotice_TextTag_IIDClick(unsigned int i_eType, unsigned int i_iid)
{
  GlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // esi@2
  int v5; // ecx@3
  bool v6; // zf@3

  v2 = GlobalEventHandler::GetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, 100021u);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 )
        (*(void (__stdcall **)(unsigned int, unsigned int))(*(_DWORD *)v5 + 80))(i_eType, i_iid);
    }
  }
  return 1;
}

//----- (00692770) --------------------------------------------------------  // acclient.c:682064
char __cdecl ECM_UI::SendNotice_TextTag_IIDEnumClick(unsigned int i_eType, unsigned int i_iid, unsigned int i_eValue)
{
  GlobalEventHandler *v3; // eax@1
  int v4; // eax@1
  int v5; // esi@2
  int v6; // ecx@3
  bool v7; // zf@3

  v3 = GlobalEventHandler::GetGlobalEventHandler();
  v4 = (int)v3->vfptr->GetNoticeHandlers((NoticeRegistrar *)v3, 100020u);
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    while ( v5 )
    {
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 == 0;
      v5 = *(_DWORD *)(v5 + 4);
      if ( !v7 )
        (*(void (__stdcall **)(unsigned int, unsigned int, unsigned int))(*(_DWORD *)v6 + 84))(i_eType, i_iid, i_eValue);
    }
  }
  return 1;
}

//----- (006927C0) --------------------------------------------------------  // acclient.c:682090
char __cdecl ECM_UI::SendNotice_TextTag_IIDStringClick(unsigned int i_eType, unsigned int i_iid, PStringBase<unsigned short> *i_strValue)
{
  GlobalEventHandler *v3; // eax@1
  int v4; // eax@1
  int v5; // esi@2
  int v6; // ecx@3
  bool v7; // zf@3

  v3 = GlobalEventHandler::GetGlobalEventHandler();
  v4 = (int)v3->vfptr->GetNoticeHandlers((NoticeRegistrar *)v3, 100018u);
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    while ( v5 )
    {
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 == 0;
      v5 = *(_DWORD *)(v5 + 4);
      if ( !v7 )
        (*(void (__stdcall **)(unsigned int, unsigned int, PStringBase<unsigned short> *))(*(_DWORD *)v6 + 88))(
          i_eType,
          i_iid,
          i_strValue);
    }
  }
  return 1;
}

//----- (00692810) --------------------------------------------------------  // acclient.c:682119
char __cdecl ECM_UI::SendNotice_UpdateGameView(unsigned int i_x, unsigned int i_y, unsigned int i_width, unsigned int i_height)
{
  GlobalEventHandler *v4; // eax@1
  int v5; // eax@1
  int v6; // esi@2
  int v7; // ecx@3
  bool v8; // zf@3

  v4 = GlobalEventHandler::GetGlobalEventHandler();
  v5 = (int)v4->vfptr->GetNoticeHandlers((NoticeRegistrar *)v4, 100013u);
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 + 4);
    while ( v6 )
    {
      v7 = *(_DWORD *)v6;
      v8 = *(_DWORD *)v6 == 0;
      v6 = *(_DWORD *)(v6 + 4);
      if ( !v8 )
        (*(void (__stdcall **)(unsigned int, unsigned int, unsigned int, unsigned int))(*(_DWORD *)v7 + 92))(
          i_x,
          i_y,
          i_width,
          i_height);
    }
  }
  return 1;
}

