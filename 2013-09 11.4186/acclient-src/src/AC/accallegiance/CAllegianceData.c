/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CAllegianceData
   Object     : AC\accallegiance\CAllegianceData.obj
   Functions  : 2
   Addresses  : 005990A0 - 005990C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005990A0) --------------------------------------------------------  // acclient.c:451296
void __thiscall CAllegianceData::CAllegianceData(CAllegianceData *this)
{
  CAllegianceData *v1; // esi@1

  v1 = this;
  AllegianceData::AllegianceData((AllegianceData *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&CAllegianceData::vftable;
}
// 7E4EB4: using guessed type int (__thiscall *CAllegianceData::vftable)(void *, char);

//----- (005990C0) --------------------------------------------------------  // acclient.c:451307
CAllegianceData *__thiscall CAllegianceData::scalar_deleting_destructor(CAllegianceData *this, unsigned int a2)
{
  CAllegianceData *v2; // esi@1

  v2 = this;
  AllegianceData::~AllegianceData((AllegianceData *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

