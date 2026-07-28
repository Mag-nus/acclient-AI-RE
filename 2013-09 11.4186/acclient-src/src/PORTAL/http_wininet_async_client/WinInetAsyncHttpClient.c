/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : WinInetAsyncHttpClient
   Object     : PORTAL\http_wininet_async_client\WinInetAsyncHttpClient.obj
   Functions  : 9
   Addresses  : 00714470 - 00714530 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00714470) --------------------------------------------------------  // acclient.c:807110
int sub_714470()
{
  return atexit(nullsub_1866);
}

//----- (00714480) --------------------------------------------------------  // acclient.c:807116
int _E4_24()
{
  return atexit(_E5_24);
}

//----- (00714490) --------------------------------------------------------  // acclient.c:807122
int _E7_24()
{
  Outside_CellID_24.id = Invalid_CellID_24.id + 1;
  return atexit(_E8_24);
}

//----- (007144B0) --------------------------------------------------------  // acclient.c:807129
int _E10_23()
{
  In_Limbo_CellID_23.id = Outside_CellID_24.id + 1;
  return atexit(_E11_23);
}

//----- (007144D0) --------------------------------------------------------  // acclient.c:807136
int _E13_23()
{
  First_Interior_CellID_23.id = In_Limbo_CellID_23.id + 1;
  return atexit(_E14_23);
}

//----- (007144F0) --------------------------------------------------------  // acclient.c:807143
int _E16_23()
{
  Last_Interior_CellID_23.id = Invalid_CellID_24.id - 1;
  return atexit(_E17_23);
}

//----- (00714510) --------------------------------------------------------  // acclient.c:807150
int _E21_25()
{
  return atexit(_E22_25);
}

//----- (00714520) --------------------------------------------------------  // acclient.c:807156
int _E40_25()
{
  return atexit(_E41_25);
}

//----- (00714530) --------------------------------------------------------  // acclient.c:807162
int _E43_28()
{
  return atexit(_E44_28);
}

