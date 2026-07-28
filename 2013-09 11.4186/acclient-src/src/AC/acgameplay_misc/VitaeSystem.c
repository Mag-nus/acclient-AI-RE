/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : VitaeSystem
   Object     : AC\acgameplay_misc\VitaeSystem.obj
   Functions  : 10
   Addresses  : 005C8FD0 - 0070F8A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005C8FD0) --------------------------------------------------------  // acclient.c:500125
unsigned __int64 __cdecl VitaeSystem::VitaeCPPoolThreshold(float cur_vitae, unsigned int level)
{
  return (unsigned __int64)((pow((double)level, 2.5) * 2.5 + 20.0) * pow(cur_vitae, 5.0) + 0.5);
}

//----- (0070F7E0) --------------------------------------------------------  // acclient.c:802695
int sub_70F7E0()
{
  return atexit(nullsub_1802);
}

//----- (0070F7F0) --------------------------------------------------------  // acclient.c:802701
int _E4_15()
{
  return atexit(_E5_15);
}

//----- (0070F800) --------------------------------------------------------  // acclient.c:802707
int _E7_15()
{
  Outside_CellID_15.id = Invalid_CellID_15.id + 1;
  return atexit(_E8_15);
}

//----- (0070F820) --------------------------------------------------------  // acclient.c:802714
int _E10_14()
{
  In_Limbo_CellID_14.id = Outside_CellID_15.id + 1;
  return atexit(_E11_14);
}

//----- (0070F840) --------------------------------------------------------  // acclient.c:802721
int _E13_14()
{
  First_Interior_CellID_14.id = In_Limbo_CellID_14.id + 1;
  return atexit(_E14_14);
}

//----- (0070F860) --------------------------------------------------------  // acclient.c:802728
int _E16_14()
{
  Last_Interior_CellID_14.id = Invalid_CellID_15.id - 1;
  return atexit(_E17_14);
}

//----- (0070F880) --------------------------------------------------------  // acclient.c:802735
int _E21_16()
{
  return atexit(_E22_16);
}

//----- (0070F890) --------------------------------------------------------  // acclient.c:802741
int _E40_16()
{
  return atexit(_E41_16);
}

//----- (0070F8A0) --------------------------------------------------------  // acclient.c:802747
int _E43_19()
{
  return atexit(_E44_19);
}

