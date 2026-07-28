/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : NoticeHandler
   Object     : ENGINE\engine_cevents\NoticeHandler.obj
   Functions  : 1
   Addresses  : 0043C3D0 - 0043C3D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0043C3D0) --------------------------------------------------------  // acclient.c:121029
void __thiscall NoticeHandler::~NoticeHandler(NoticeHandler *this)
{
  NoticeHandler *v1; // esi@1
  GlobalEventHandler *v2; // eax@1

  v1 = this;
  this->vfptr = (NoticeHandlerVtbl *)&CObjectMaint::vftable;
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
    v2->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v2, v1);
  if ( CObjectMaint::s_pcInstance )
    CObjectMaint::UnRegisterAllNoticeHandlers(CObjectMaint::s_pcInstance, v1);
}
// 7CBD20: using guessed type bool (__thiscall *CObjectMaint::vftable)(DBObj *this);

