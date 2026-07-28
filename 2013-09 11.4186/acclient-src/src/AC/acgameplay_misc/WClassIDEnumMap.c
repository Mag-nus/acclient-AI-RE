/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : WClassIDEnumMap
   Object     : AC\acgameplay_misc\WClassIDEnumMap.obj
   Functions  : 9
   Addresses  : 00724870 - 00724930 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00724870) --------------------------------------------------------  // acclient.c:822237
int sub_724870()
{
  return atexit(nullsub_1784);
}

//----- (00724880) --------------------------------------------------------  // acclient.c:822243
int _E4_36()
{
  return atexit(_E5_36);
}

//----- (00724890) --------------------------------------------------------  // acclient.c:822249
int _E7_36()
{
  Outside_CellID_36.id = Invalid_CellID_36.id + 1;
  return atexit(_E8_36);
}

//----- (007248B0) --------------------------------------------------------  // acclient.c:822256
int _E10_35()
{
  In_Limbo_CellID_35.id = Outside_CellID_36.id + 1;
  return atexit(_E11_35);
}

//----- (007248D0) --------------------------------------------------------  // acclient.c:822263
int _E13_35()
{
  First_Interior_CellID_35.id = In_Limbo_CellID_35.id + 1;
  return atexit(_E14_35);
}

//----- (007248F0) --------------------------------------------------------  // acclient.c:822270
int _E16_35()
{
  Last_Interior_CellID_35.id = Invalid_CellID_36.id - 1;
  return atexit(_E17_35);
}

//----- (00724910) --------------------------------------------------------  // acclient.c:822277
int _E21_38()
{
  return atexit(_E22_38);
}

//----- (00724920) --------------------------------------------------------  // acclient.c:822283
int _E40_37()
{
  return atexit(_E41_37);
}

//----- (00724930) --------------------------------------------------------  // acclient.c:822289
int _E43_40()
{
  return atexit(_E44_40);
}

