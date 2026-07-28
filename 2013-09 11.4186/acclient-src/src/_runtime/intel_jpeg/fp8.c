/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : fp8
   Object     : _runtime\intel_jpeg\fp8.obj
   Functions  : 1
   Addresses  : 005DE68E - 005DE68E */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE68E) --------------------------------------------------------  // acclient.c:521253
unsigned int _setdefaultprecision()
{
  return _controlfp(0x10000u, 0x30000u);
}

