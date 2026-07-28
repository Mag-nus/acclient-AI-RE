/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CAllegianceProfile
   Object     : AC\accallegiance\CAllegianceProfile.obj
   Functions  : 6
   Addresses  : 005990E0 - 0070AEA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005990E0) --------------------------------------------------------  // acclient.c:451319
void __thiscall CAllegianceProfile::CAllegianceProfile(CAllegianceProfile *this)
{
  CAllegianceProfile *v1; // esi@1

  v1 = this;
  AllegianceProfile::AllegianceProfile((AllegianceProfile *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&CAllegianceProfile::vftable;
}
// 7E4F00: using guessed type int (__thiscall *CAllegianceProfile::vftable)(void *, char);

//----- (00599100) --------------------------------------------------------  // acclient.c:451330
CAllegianceProfile *__thiscall CAllegianceProfile::vector_deleting_destructor(CAllegianceProfile *this, unsigned int a2)
{
  CAllegianceProfile *v2; // esi@1

  v2 = this;
  AllegianceProfile::~AllegianceProfile((AllegianceProfile *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0070AE40) --------------------------------------------------------  // acclient.c:798092
void sub_70AE40()
{
  flt_8710DC = 1000.0 + 1.0;
}

//----- (0070AE60) --------------------------------------------------------  // acclient.c:798098
void sub_70AE60()
{
  flt_8710E0 = 24.0 * 8.0;
}

//----- (0070AE80) --------------------------------------------------------  // acclient.c:798104
void sub_70AE80()
{
  flt_8710E4 = 24.0 * 0.5;
}

//----- (0070AEA0) --------------------------------------------------------  // acclient.c:798110
int sub_70AEA0()
{
  return atexit(nullsub_1429);
}

