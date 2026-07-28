/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Chess
   Object     : AC\acgameplay_misc\Chess.obj
   Functions  : 9
   Addresses  : 0070F8B0 - 0070F970 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0070F8B0) --------------------------------------------------------  // acclient.c:802753
int sub_70F8B0()
{
  return atexit(nullsub_1820);
}

//----- (0070F8C0) --------------------------------------------------------  // acclient.c:802759
int _E4_16()
{
  return atexit(_E5_16);
}

//----- (0070F8D0) --------------------------------------------------------  // acclient.c:802765
int _E7_16()
{
  Outside_CellID_16.id = Invalid_CellID_16.id + 1;
  return atexit(_E8_16);
}

//----- (0070F8F0) --------------------------------------------------------  // acclient.c:802772
int _E10_15()
{
  In_Limbo_CellID_15.id = Outside_CellID_16.id + 1;
  return atexit(_E11_15);
}

//----- (0070F910) --------------------------------------------------------  // acclient.c:802779
int _E13_15()
{
  First_Interior_CellID_15.id = In_Limbo_CellID_15.id + 1;
  return atexit(_E14_15);
}

//----- (0070F930) --------------------------------------------------------  // acclient.c:802786
int _E16_15()
{
  Last_Interior_CellID_15.id = Invalid_CellID_16.id - 1;
  return atexit(_E17_15);
}

//----- (0070F950) --------------------------------------------------------  // acclient.c:802793
int _E21_17()
{
  return atexit(_E22_17);
}

//----- (0070F960) --------------------------------------------------------  // acclient.c:802799
int _E40_17()
{
  return atexit(_E41_17);
}

//----- (0070F970) --------------------------------------------------------  // acclient.c:802805
int _E43_20()
{
  return atexit(_E44_20);
}

