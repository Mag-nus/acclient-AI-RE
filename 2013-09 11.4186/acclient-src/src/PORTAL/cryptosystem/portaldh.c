/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : portaldh
   Object     : PORTAL\cryptosystem\portaldh.obj
   Functions  : 1
   Addresses  : 005B0250 - 005B0250 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B0250) --------------------------------------------------------  // acclient.c:474886
int __thiscall PortalDH::Init(PortalDH *this, AC1Legacy::vlong *shared_base, AC1Legacy::vlong *shared_prime)
{
  PortalDH *v3; // esi@1

  v3 = this;
  AC1Legacy::vlong::operator=(&this->shared_base_, shared_base);
  AC1Legacy::vlong::operator=(&v3->shared_prime_, shared_prime);
  return 1;
}

