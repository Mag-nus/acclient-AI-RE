/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ConnectionCache
   Object     : PORTAL\http_wininet_async_client\ConnectionCache.obj
   Functions  : 9
   Addresses  : 007146E0 - 007147A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (007146E0) --------------------------------------------------------  // acclient.c:807284
int sub_7146E0()
{
  return atexit(nullsub_1884);
}

//----- (007146F0) --------------------------------------------------------  // acclient.c:807290
int _E4_27()
{
  return atexit(_E5_27);
}

//----- (00714700) --------------------------------------------------------  // acclient.c:807296
int _E7_27()
{
  Outside_CellID_27.id = Invalid_CellID_27.id + 1;
  return atexit(_E8_27);
}

//----- (00714720) --------------------------------------------------------  // acclient.c:807303
int _E10_26()
{
  In_Limbo_CellID_26.id = Outside_CellID_27.id + 1;
  return atexit(_E11_26);
}

//----- (00714740) --------------------------------------------------------  // acclient.c:807310
int _E13_26()
{
  First_Interior_CellID_26.id = In_Limbo_CellID_26.id + 1;
  return atexit(_E14_26);
}

//----- (00714760) --------------------------------------------------------  // acclient.c:807317
int _E16_26()
{
  Last_Interior_CellID_26.id = Invalid_CellID_27.id - 1;
  return atexit(_E17_26);
}

//----- (00714780) --------------------------------------------------------  // acclient.c:807324
int _E21_28()
{
  return atexit(_E22_28);
}

//----- (00714790) --------------------------------------------------------  // acclient.c:807330
int _E40_28()
{
  return atexit(_E41_28);
}

//----- (007147A0) --------------------------------------------------------  // acclient.c:807336
int _E43_31()
{
  return atexit(_E44_31);
}

