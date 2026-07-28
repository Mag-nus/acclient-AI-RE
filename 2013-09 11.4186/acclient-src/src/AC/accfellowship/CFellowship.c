/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CFellowship
   Object     : AC\accfellowship\CFellowship.obj
   Functions  : 2
   Addresses  : 0059A570 - 0059A590 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0059A570) --------------------------------------------------------  // acclient.c:452710
void __thiscall CFellowship::CFellowship(CFellowship *this)
{
  CFellowship *v1; // esi@1

  v1 = this;
  Fellowship::Fellowship((Fellowship *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&CFellowship::vftable;
}
// 7CEC6C: using guessed type int (__thiscall *CFellowship::vftable)(void *, char);

//----- (0059A590) --------------------------------------------------------  // acclient.c:452721
CFellowship *__thiscall CFellowship::vector_deleting_destructor(CFellowship *this, unsigned int a2)
{
  CFellowship *v2; // esi@1

  v2 = this;
  Fellowship::~Fellowship((Fellowship *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

