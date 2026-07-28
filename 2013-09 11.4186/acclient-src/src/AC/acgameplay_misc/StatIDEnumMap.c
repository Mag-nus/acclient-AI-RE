/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : StatIDEnumMap
   Object     : AC\acgameplay_misc\StatIDEnumMap.obj
   Functions  : 9
   Addresses  : 0070FD90 - 0070FE50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0070FD90) --------------------------------------------------------  // acclient.c:803101
int sub_70FD90()
{
  return atexit(nullsub_1775);
}

//----- (0070FDA0) --------------------------------------------------------  // acclient.c:803107
int _E4_22()
{
  return atexit(_E5_22);
}

//----- (0070FDB0) --------------------------------------------------------  // acclient.c:803113
int _E7_22()
{
  Outside_CellID_22.id = Invalid_CellID_22.id + 1;
  return atexit(_E8_22);
}

//----- (0070FDD0) --------------------------------------------------------  // acclient.c:803120
int _E10_21()
{
  In_Limbo_CellID_21.id = Outside_CellID_22.id + 1;
  return atexit(_E11_21);
}

//----- (0070FDF0) --------------------------------------------------------  // acclient.c:803127
int _E13_21()
{
  First_Interior_CellID_21.id = In_Limbo_CellID_21.id + 1;
  return atexit(_E14_21);
}

//----- (0070FE10) --------------------------------------------------------  // acclient.c:803134
int _E16_21()
{
  Last_Interior_CellID_21.id = Invalid_CellID_22.id - 1;
  return atexit(_E17_21);
}

//----- (0070FE30) --------------------------------------------------------  // acclient.c:803141
int _E21_23()
{
  return atexit(_E22_23);
}

//----- (0070FE40) --------------------------------------------------------  // acclient.c:803147
int _E40_23()
{
  return atexit(_E41_23);
}

//----- (0070FE50) --------------------------------------------------------  // acclient.c:803153
int _E43_26()
{
  return atexit(_E44_26);
}

