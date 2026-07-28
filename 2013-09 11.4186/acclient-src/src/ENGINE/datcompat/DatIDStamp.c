/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DatIDStamp
   Object     : ENGINE\datcompat\DatIDStamp.obj
   Functions  : 3
   Addresses  : 004136B0 - 00413700 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004136B0) --------------------------------------------------------  // acclient.c:79355
void __thiscall DatIDStamp::DatIDStamp(DatIDStamp *this, DatIDStamp *rhs)
{
  *this = *rhs;
}

//----- (004136E0) --------------------------------------------------------  // acclient.c:79361
void __thiscall DatIDStamp::Clear(DatIDStamp *this)
{
  this->_maj_vnum.Data1 = 0;
  *(_DWORD *)&this->_maj_vnum.Data2 = 0;
  *(_DWORD *)&this->_maj_vnum.Data4[0] = 0;
  *(_DWORD *)&this->_maj_vnum.Data4[4] = 0;
  this->_min_vnum = 0;
}

//----- (00413700) --------------------------------------------------------  // acclient.c:79371
void __thiscall DatIDStamp::DatIDStamp(DatIDStamp *this)
{
  this->_maj_vnum.Data1 = 0;
  *(_DWORD *)&this->_maj_vnum.Data2 = 0;
  *(_DWORD *)&this->_maj_vnum.Data4[0] = 0;
  *(_DWORD *)&this->_maj_vnum.Data4[4] = 0;
  this->_min_vnum = 0;
}

