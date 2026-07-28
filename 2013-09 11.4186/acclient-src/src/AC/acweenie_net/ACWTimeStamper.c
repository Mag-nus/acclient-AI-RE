/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ACWTimeStamper
   Object     : AC\acweenie_net\ACWTimeStamper.obj
   Functions  : 2
   Addresses  : 005BD3A0 - 005BD3C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005BD3A0) --------------------------------------------------------  // acclient.c:488482
void __thiscall ACWTimeStamper::ACWTimeStamper(ACWTimeStamper *this)
{
  ACWTimeStamper *v1; // esi@1

  v1 = this;
  WTimeStamper::WTimeStamper((WTimeStamper *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&ACWTimeStamper::vftable;
}
// 7E75E8: using guessed type int (__thiscall *ACWTimeStamper::vftable)(void *, char);

//----- (005BD3C0) --------------------------------------------------------  // acclient.c:488493
ACWTimeStamper *__thiscall ACWTimeStamper::scalar_deleting_destructor(ACWTimeStamper *this, unsigned int a2)
{
  ACWTimeStamper *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&ACWTimeStamper::vftable;
  WTimeStamper::~WTimeStamper((WTimeStamper *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E75E8: using guessed type int (__thiscall *ACWTimeStamper::vftable)(void *, char);

