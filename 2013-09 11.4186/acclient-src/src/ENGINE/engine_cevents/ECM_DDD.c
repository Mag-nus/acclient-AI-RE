/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ECM_DDD
   Object     : ENGINE\engine_cevents\ECM_DDD.obj
   Functions  : 1
   Addresses  : 00692870 - 00692870 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00692870) --------------------------------------------------------  // acclient.c:682149
char __cdecl ECM_DDD::SendNotice_RuntimeDDDStatus(int i_fCurrentlyDownloading, unsigned int i_cItemsDownloaded, unsigned int i_cTotalItems)
{
  GlobalEventHandler *v3; // eax@1
  int v4; // eax@1
  int v5; // esi@2
  int v6; // ecx@3
  bool v7; // zf@3

  v3 = GlobalEventHandler::GetGlobalEventHandler();
  v4 = (int)v3->vfptr->GetNoticeHandlers((NoticeRegistrar *)v3, 100017u);
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    while ( v5 )
    {
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 == 0;
      v5 = *(_DWORD *)(v5 + 4);
      if ( !v7 )
        (*(void (__stdcall **)(int, unsigned int, unsigned int))(*(_DWORD *)v6 + 12))(
          i_fCurrentlyDownloading,
          i_cItemsDownloaded,
          i_cTotalItems);
    }
  }
  return 1;
}

