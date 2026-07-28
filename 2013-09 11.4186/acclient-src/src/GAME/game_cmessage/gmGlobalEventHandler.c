/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmGlobalEventHandler
   Object     : GAME\game_cmessage\gmGlobalEventHandler.obj
   Functions  : 2
   Addresses  : 0047A3F0 - 0047A420 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0047A3F0) --------------------------------------------------------  // acclient.c:183628
void __thiscall gmGlobalEventHandler::gmGlobalEventHandler(gmGlobalEventHandler *this)
{
  gmGlobalEventHandler *v1; // esi@1

  v1 = this;
  GlobalEventHandler::GlobalEventHandler((GlobalEventHandler *)&this->vfptr);
  v1->vfptr = (NoticeRegistrarVtbl *)&gmGlobalEventHandler::vftable;
}
// 79E314: using guessed type int (__thiscall *gmGlobalEventHandler::vftable)(void *, char);

//----- (0047A420) --------------------------------------------------------  // acclient.c:183639
gmGlobalEventHandler *__thiscall gmGlobalEventHandler::scalar_deleting_destructor(gmGlobalEventHandler *this, unsigned int a2)
{
  gmGlobalEventHandler *v2; // esi@1

  v2 = this;
  this->vfptr = (NoticeRegistrarVtbl *)&gmGlobalEventHandler::vftable;
  GlobalEventHandler::~GlobalEventHandler((GlobalEventHandler *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79E314: using guessed type int (__thiscall *gmGlobalEventHandler::vftable)(void *, char);

