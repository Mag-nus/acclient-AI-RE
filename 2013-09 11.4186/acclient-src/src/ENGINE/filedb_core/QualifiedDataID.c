/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : QualifiedDataID
   Object     : ENGINE\filedb_core\QualifiedDataID.obj
   Functions  : 3
   Addresses  : 00421C90 - 006C4AE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00421C90) --------------------------------------------------------  // acclient.c:93437
void __thiscall QualifiedDataID::QualifiedDataID(QualifiedDataID *this, IDClass<_tagDataID,32,0> AnID, unsigned int AType)
{
  this->Type = AType;
  this->ID.id = AnID.id;
  if ( AnID.id != INVALID_DID_14.id && !AType )
    this->Type = MasterDBMap::DivineType(AnID);
}

//----- (006C4AD0) --------------------------------------------------------  // acclient.c:733031
int _E73_17()
{
  return atexit(_E74_20);
}

//----- (006C4AE0) --------------------------------------------------------  // acclient.c:733037
int _E1_14()
{
  return atexit(_E2_14);
}

