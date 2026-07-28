/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ECM_Item
   Object     : ENGINE\engine_cevents\ECM_Item.obj
   Functions  : 4
   Addresses  : 006928C0 - 006929C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006928C0) --------------------------------------------------------  // acclient.c:682178
char __cdecl ECM_Item::SendNotice_ItemAttributesChanged(unsigned int i_target, unsigned int i_attrib)
{
  GlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // esi@2
  int v5; // ecx@3
  bool v6; // zf@3

  v2 = GlobalEventHandler::GetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, 100011u);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 )
        (*(void (__stdcall **)(unsigned int, unsigned int))(*(_DWORD *)v5 + 16))(i_target, i_attrib);
    }
  }
  return 1;
}

//----- (00692910) --------------------------------------------------------  // acclient.c:682204
char __cdecl ECM_Item::SendNotice_ServerSaysAttemptFailed(unsigned int i_itemID)
{
  GlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // ecx@3
  bool v5; // zf@3

  v1 = GlobalEventHandler::GetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, 100009u);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 )
        (*(void (__stdcall **)(unsigned int))(*(_DWORD *)v4 + 20))(i_itemID);
    }
  }
  return 1;
}

//----- (00692950) --------------------------------------------------------  // acclient.c:682230
char __cdecl ECM_Item::SendNotice_ServerSaysMoveItem(unsigned int i_itemID, unsigned int i_oldContainer, unsigned int i_oldWielder, unsigned int i_oldLocation, unsigned int i_newContainer, int i_place, unsigned int i_newWielder, unsigned int i_newLocation)
{
  GlobalEventHandler *v8; // eax@1
  int v9; // eax@1
  int v10; // esi@2
  int v11; // ecx@3
  bool v12; // zf@3

  v8 = GlobalEventHandler::GetGlobalEventHandler();
  v9 = (int)v8->vfptr->GetNoticeHandlers((NoticeRegistrar *)v8, 100008u);
  if ( v9 )
  {
    v10 = *(_DWORD *)(v9 + 4);
    while ( v10 )
    {
      v11 = *(_DWORD *)v10;
      v12 = *(_DWORD *)v10 == 0;
      v10 = *(_DWORD *)(v10 + 4);
      if ( !v12 )
        (*(void (__stdcall **)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, int, unsigned int, unsigned int))(*(_DWORD *)v11 + 24))(
          i_itemID,
          i_oldContainer,
          i_oldWielder,
          i_oldLocation,
          i_newContainer,
          i_place,
          i_newWielder,
          i_newLocation);
    }
  }
  return 1;
}

//----- (006929C0) --------------------------------------------------------  // acclient.c:682264
char __cdecl ECM_Item::SendNotice_SetSelectedItem(unsigned int i_oldSelectedID, unsigned int i_selectedID)
{
  GlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // esi@2
  int v5; // ecx@3
  bool v6; // zf@3

  v2 = GlobalEventHandler::GetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, 100010u);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 )
        (*(void (__stdcall **)(unsigned int, unsigned int))(*(_DWORD *)v5 + 28))(i_oldSelectedID, i_selectedID);
    }
  }
  return 1;
}

