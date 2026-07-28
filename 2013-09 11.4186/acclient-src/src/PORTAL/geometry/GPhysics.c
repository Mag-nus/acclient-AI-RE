/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GPhysics
   Object     : PORTAL\geometry\GPhysics.obj
   Functions  : 2
   Addresses  : 0070D920 - 0070D930 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0070D920) --------------------------------------------------------  // acclient.c:800527
void sub_70D920()
{
  PhysicsGlobals::floor_z = cos(3437.746770784939);
}
// 8EDE5C: using guessed type float PhysicsGlobals::floor_z;

//----- (0070D930) --------------------------------------------------------  // acclient.c:800534
int _E75()
{
  int result; // eax@1

  result = 0;
  *(_QWORD *)&PhysicsTimer::curr_time = -4616189618054758400i64;
  return result;
}

