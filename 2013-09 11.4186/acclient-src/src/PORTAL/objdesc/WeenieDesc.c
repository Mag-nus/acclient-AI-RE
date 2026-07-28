/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : WeenieDesc
   Object     : PORTAL\objdesc\WeenieDesc.obj
   Functions  : 2
   Addresses  : 005ADB30 - 005ADB40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005ADB30) --------------------------------------------------------  // acclient.c:471777
void __thiscall WeenieDesc::WeenieDesc(WeenieDesc *this)
{
  this->vfptr = (PackObjVtbl *)&VisualDesc::vftable;
}
// 7E60D0: using guessed type int (__thiscall *VisualDesc::vftable)(void *, char);

//----- (005ADB40) --------------------------------------------------------  // acclient.c:471784
void __thiscall WeenieDesc::~WeenieDesc(WeenieDesc *this)
{
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

