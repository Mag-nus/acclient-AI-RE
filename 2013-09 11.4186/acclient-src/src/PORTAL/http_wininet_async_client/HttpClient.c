/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : HttpClient
   Object     : PORTAL\http_wininet_async_client\HttpClient.obj
   Functions  : 9
   Addresses  : 00714540 - 00714600 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00714540) --------------------------------------------------------  // acclient.c:807168
int sub_714540()
{
  return atexit(nullsub_1857);
}

//----- (00714550) --------------------------------------------------------  // acclient.c:807174
int _E4_25()
{
  return atexit(_E5_25);
}

//----- (00714560) --------------------------------------------------------  // acclient.c:807180
int _E7_25()
{
  Outside_CellID_25.id = Invalid_CellID_25.id + 1;
  return atexit(_E8_25);
}

//----- (00714580) --------------------------------------------------------  // acclient.c:807187
int _E10_24()
{
  In_Limbo_CellID_24.id = Outside_CellID_25.id + 1;
  return atexit(_E11_24);
}

//----- (007145A0) --------------------------------------------------------  // acclient.c:807194
int _E13_24()
{
  First_Interior_CellID_24.id = In_Limbo_CellID_24.id + 1;
  return atexit(_E14_24);
}

//----- (007145C0) --------------------------------------------------------  // acclient.c:807201
int _E16_24()
{
  Last_Interior_CellID_24.id = Invalid_CellID_25.id - 1;
  return atexit(_E17_24);
}

//----- (007145E0) --------------------------------------------------------  // acclient.c:807208
int _E21_26()
{
  return atexit(_E22_26);
}

//----- (007145F0) --------------------------------------------------------  // acclient.c:807214
int _E40_26()
{
  return atexit(_E41_26);
}

//----- (00714600) --------------------------------------------------------  // acclient.c:807220
int _E43_29()
{
  return atexit(_E44_29);
}

