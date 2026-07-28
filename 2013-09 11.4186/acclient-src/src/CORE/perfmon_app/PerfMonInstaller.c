/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PerfMonInstaller
   Object     : CORE\perfmon_app\PerfMonInstaller.obj
   Functions  : 9
   Addresses  : 007156E0 - 007157A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (007156E0) --------------------------------------------------------  // acclient.c:808424
int sub_7156E0()
{
  return atexit(nullsub_204);
}

//----- (007156F0) --------------------------------------------------------  // acclient.c:808430
int _E4_35()
{
  return atexit(_E5_35);
}

//----- (00715700) --------------------------------------------------------  // acclient.c:808436
int _E7_35()
{
  Outside_CellID_35.id = Invalid_CellID_35.id + 1;
  return atexit(_E8_35);
}

//----- (00715720) --------------------------------------------------------  // acclient.c:808443
int _E10_34()
{
  In_Limbo_CellID_34.id = Outside_CellID_35.id + 1;
  return atexit(_E11_34);
}

//----- (00715740) --------------------------------------------------------  // acclient.c:808450
int _E13_34()
{
  First_Interior_CellID_34.id = In_Limbo_CellID_34.id + 1;
  return atexit(_E14_34);
}

//----- (00715760) --------------------------------------------------------  // acclient.c:808457
int _E16_34()
{
  Last_Interior_CellID_34.id = Invalid_CellID_35.id - 1;
  return atexit(_E17_34);
}

//----- (00715780) --------------------------------------------------------  // acclient.c:808464
int _E21_37()
{
  return atexit(_E22_37);
}

//----- (00715790) --------------------------------------------------------  // acclient.c:808470
int _E40_36()
{
  return atexit(_E41_36);
}

//----- (007157A0) --------------------------------------------------------  // acclient.c:808476
int _E43_39()
{
  return atexit(_E44_39);
}

