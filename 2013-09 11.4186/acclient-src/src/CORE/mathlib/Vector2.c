/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Vector2
   Object     : CORE\mathlib\Vector2.obj
   Functions  : 1
   Addresses  : 0065D890 - 0065D890 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0065D890) --------------------------------------------------------  // acclient.c:627298
void __thiscall Vector2::Vector2(Vector2 *this, float _x, float _y)
{
  this->x = _x;
  this->y = _y;
}

