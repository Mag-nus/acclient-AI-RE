/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ShadePackage
   Object     : PORTAL\clothing\ShadePackage.obj
   Functions  : 2
   Addresses  : 005A8290 - 005A82C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005A8290) --------------------------------------------------------  // acclient.c:465510
void __thiscall ShadePackage::ShadePackage(ShadePackage *this, const long double val)
{
  this->_val[0] = val;
  qmemcpy(&this->_val[1], this, 0x18u);
}

//----- (005A82C0) --------------------------------------------------------  // acclient.c:465517
long double __thiscall ShadePackage::GetVal(ShadePackage *this, const int index)
{
  long double result; // st7@2

  if ( index >= 4 )
    result = this->_val[3];
  else
    result = this->_val[index];
  return result;
}

