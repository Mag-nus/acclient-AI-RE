/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ECM_Login
   Object     : ENGINE\engine_cevents\ECM_Login.obj
   Functions  : 3
   Addresses  : 00692A90 - 00692B10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00692A90) --------------------------------------------------------  // acclient.c:682340
char __cdecl ECM_Login::SendNotice_CharacterError(charError i_error)
{
  GlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // ecx@3
  bool v5; // zf@3

  v1 = GlobalEventHandler::GetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, 100001u);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 )
        (*(void (__stdcall **)(charError))(*(_DWORD *)v4 + 32))(i_error);
    }
  }
  return 1;
}

//----- (00692AD0) --------------------------------------------------------  // acclient.c:682366
char __cdecl ECM_Login::SendNotice_ServerDied()
{
  GlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // ecx@3
  bool v4; // zf@3

  v0 = GlobalEventHandler::GetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, 100000u);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 )
        (*(void (**)(void))(*(_DWORD *)v3 + 36))();
    }
  }
  return 1;
}

//----- (00692B10) --------------------------------------------------------  // acclient.c:682392
char __cdecl ECM_Login::SendNotice_WorldName(AC1Legacy::PStringBase<char> *i_strName)
{
  GlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // ecx@3
  bool v5; // zf@3

  v1 = GlobalEventHandler::GetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, 100002u);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 )
        (*(void (__stdcall **)(AC1Legacy::PStringBase<char> *))(*(_DWORD *)v4 + 40))(i_strName);
    }
  }
  return 1;
}

