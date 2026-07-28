/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GlobalEventHandler
   Object     : ENGINE\engine_cmessage\GlobalEventHandler.obj
   Functions  : 4
   Addresses  : 0043C400 - 0043C450 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0043C400) --------------------------------------------------------  // acclient.c:121045
void __thiscall GlobalEventHandler::GlobalEventHandler(GlobalEventHandler *this)
{
  struct GlobalEventHandler *v1; // esi@1

  v1 = this;
  NoticeRegistrar::NoticeRegistrar((NoticeRegistrar *)&this->vfptr);
  v1->vfptr = (NoticeRegistrarVtbl *)&GlobalEventHandler::vftable;
  GlobalEventHandler::geh = v1;
}
// 798FC4: using guessed type int (__thiscall *GlobalEventHandler::vftable)(void *, char);
// 837374: using guessed type struct GlobalEventHandler *GlobalEventHandler::geh;

//----- (0043C420) --------------------------------------------------------  // acclient.c:121058
void __thiscall GlobalEventHandler::~GlobalEventHandler(GlobalEventHandler *this)
{
  this->vfptr = (NoticeRegistrarVtbl *)&GlobalEventHandler::vftable;
  GlobalEventHandler::geh = 0;
  NoticeRegistrar::~NoticeRegistrar((NoticeRegistrar *)&this->vfptr);
}
// 798FC4: using guessed type int (__thiscall *GlobalEventHandler::vftable)(void *, char);
// 837374: using guessed type struct GlobalEventHandler *GlobalEventHandler::geh;

//----- (0043C440) --------------------------------------------------------  // acclient.c:121068
GlobalEventHandler *__cdecl GlobalEventHandler::GetGlobalEventHandler()
{
  return GlobalEventHandler::geh;
}
// 837374: using guessed type struct GlobalEventHandler *GlobalEventHandler::geh;

//----- (0043C450) --------------------------------------------------------  // acclient.c:121075
GlobalEventHandler *__thiscall GlobalEventHandler::scalar_deleting_destructor(GlobalEventHandler *this, unsigned int a2)
{
  GlobalEventHandler *v2; // esi@1

  v2 = this;
  this->vfptr = (NoticeRegistrarVtbl *)&GlobalEventHandler::vftable;
  GlobalEventHandler::geh = 0;
  NoticeRegistrar::~NoticeRegistrar((NoticeRegistrar *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 798FC4: using guessed type int (__thiscall *GlobalEventHandler::vftable)(void *, char);
// 837374: using guessed type struct GlobalEventHandler *GlobalEventHandler::geh;

