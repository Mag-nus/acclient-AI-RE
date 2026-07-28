/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : WinInetImplementation
   Object     : PORTAL\http_wininet_async_client\WinInetImplementation.obj
   Functions  : 9
   Addresses  : 00714610 - 007146D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00714610) --------------------------------------------------------  // acclient.c:807226
int sub_714610()
{
  return atexit(nullsub_1875);
}

//----- (00714620) --------------------------------------------------------  // acclient.c:807232
int _E4_26()
{
  return atexit(_E5_26);
}

//----- (00714630) --------------------------------------------------------  // acclient.c:807238
int _E7_26()
{
  Outside_CellID_26.id = Invalid_CellID_26.id + 1;
  return atexit(_E8_26);
}

//----- (00714650) --------------------------------------------------------  // acclient.c:807245
int _E10_25()
{
  In_Limbo_CellID_25.id = Outside_CellID_26.id + 1;
  return atexit(_E11_25);
}

//----- (00714670) --------------------------------------------------------  // acclient.c:807252
int _E13_25()
{
  First_Interior_CellID_25.id = In_Limbo_CellID_25.id + 1;
  return atexit(_E14_25);
}

//----- (00714690) --------------------------------------------------------  // acclient.c:807259
int _E16_25()
{
  Last_Interior_CellID_25.id = Invalid_CellID_26.id - 1;
  return atexit(_E17_25);
}

//----- (007146B0) --------------------------------------------------------  // acclient.c:807266
int _E21_27()
{
  return atexit(_E22_27);
}

//----- (007146C0) --------------------------------------------------------  // acclient.c:807272
int _E40_27()
{
  return atexit(_E41_27);
}

//----- (007146D0) --------------------------------------------------------  // acclient.c:807278
int _E43_30()
{
  return atexit(_E44_30);
}

