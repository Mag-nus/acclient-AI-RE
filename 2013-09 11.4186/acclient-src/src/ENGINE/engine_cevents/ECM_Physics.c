/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ECM_Physics
   Object     : ENGINE\engine_cevents\ECM_Physics.obj
   Functions  : 2
   Addresses  : 00692A10 - 00692A50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00692A10) --------------------------------------------------------  // acclient.c:682290
char __cdecl ECM_Physics::SendNotice_BeingDeleted(CWeenieObject *obj)
{
  List<NoticeHandler *> *v1; // eax@1
  ListNode<NoticeHandler *> *v2; // esi@2
  NoticeHandler *v3; // ecx@3
  bool v4; // zf@3

  v1 = obj->vfptr->GetNoticeHandlers((NoticeRegistrar *)&obj->vfptr, 100015u);
  if ( v1 )
  {
    v2 = v1->_head;
    while ( v2 )
    {
      v3 = v2->data;
      v4 = v2->data == 0;
      v2 = v2->next;
      if ( !v4 )
        ((void (__stdcall *)(CWeenieObject *))v3->vfptr->RecvNotice_BeingDeleted)(obj);
    }
  }
  return 1;
}

//----- (00692A50) --------------------------------------------------------  // acclient.c:682314
char __cdecl ECM_Physics::SendNotice_CreateObject(unsigned int i_iidObject)
{
  GlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // ecx@3
  bool v5; // zf@3

  v1 = GlobalEventHandler::GetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, 100014u);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 )
        (*(void (__stdcall **)(unsigned int))(*(_DWORD *)v4 + 48))(i_iidObject);
    }
  }
  return 1;
}

