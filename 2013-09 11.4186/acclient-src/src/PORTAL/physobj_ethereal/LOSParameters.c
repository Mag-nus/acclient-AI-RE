/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : LOSParameters
   Object     : PORTAL\physobj_ethereal\LOSParameters.obj
   Functions  : 4
   Addresses  : 00723EF0 - 00723F50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00723EF0) --------------------------------------------------------  // acclient.c:821706
void sub_723EF0()
{
  flt_8FAA20 = 1000.0 + 1.0;
}

//----- (00723F10) --------------------------------------------------------  // acclient.c:821712
void sub_723F10()
{
  flt_8FAA24 = 24.0 * 8.0;
}

//----- (00723F30) --------------------------------------------------------  // acclient.c:821718
void sub_723F30()
{
  flt_8FAA28 = 24.0 * 0.5;
}

//----- (00723F50) --------------------------------------------------------  // acclient.c:821724
int sub_723F50()
{
  return atexit(nullsub_1113);
}

