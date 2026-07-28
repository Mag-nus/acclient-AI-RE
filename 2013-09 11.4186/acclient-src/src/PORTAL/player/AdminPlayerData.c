/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AdminPlayerData
   Object     : PORTAL\player\AdminPlayerData.obj
   Functions  : 1
   Addresses  : 006B0B80 - 006B0B80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B0B80) --------------------------------------------------------  // acclient.c:713919
void __thiscall AdminPlayerData::AdminPlayerData(AdminPlayerData *this)
{
  AdminPlayerData *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&AdminPlayerData::vftable;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&this->name, &name);
  v1->bookieID = 0;
}
// 803548: using guessed type int (__thiscall *AdminPlayerData::vftable)(void *, char);

