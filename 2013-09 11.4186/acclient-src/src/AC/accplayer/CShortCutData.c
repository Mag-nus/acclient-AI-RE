/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CShortCutData
   Object     : AC\accplayer\CShortCutData.obj
   Functions  : 1
   Addresses  : 0059A5B0 - 0059A5B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0059A5B0) --------------------------------------------------------  // acclient.c:452733
void __thiscall CShortCutData::CShortCutData(CShortCutData *this, int index, unsigned int objectID, unsigned int spellID)
{
  CShortCutData *v4; // esi@1

  v4 = this;
  ShortCutData::ShortCutData((ShortCutData *)&this->vfptr, index, objectID, spellID);
  v4->vfptr = (PackObjVtbl *)&CShortCutData::vftable;
}
// 7E8A7C: using guessed type int (__thiscall *CShortCutData::vftable)(void *, char);

