/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SpellIDEnumMap
   Object     : AC\acmagic\SpellIDEnumMap.obj
   Functions  : 10
   Addresses  : 00508960 - 0070EDB0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00508960) --------------------------------------------------------  // acclient.c:310180
unsigned int __cdecl UIObject::DynamicCast_UIViewportObject()
{
  return 0;
}

//----- (0070ECF0) --------------------------------------------------------  // acclient.c:801829
int sub_70ECF0()
{
  return atexit(nullsub_1599);
}

//----- (0070ED00) --------------------------------------------------------  // acclient.c:801835
int _E4_10()
{
  return atexit(_E5_10);
}

//----- (0070ED10) --------------------------------------------------------  // acclient.c:801841
int _E7_10()
{
  Outside_CellID_10.id = Invalid_CellID_10.id + 1;
  return atexit(_E8_10);
}

//----- (0070ED30) --------------------------------------------------------  // acclient.c:801848
int _E10_9()
{
  In_Limbo_CellID_9.id = Outside_CellID_10.id + 1;
  return atexit(_E11_9);
}

//----- (0070ED50) --------------------------------------------------------  // acclient.c:801855
int _E13_9()
{
  First_Interior_CellID_9.id = In_Limbo_CellID_9.id + 1;
  return atexit(_E14_9);
}

//----- (0070ED70) --------------------------------------------------------  // acclient.c:801862
int _E16_9()
{
  Last_Interior_CellID_9.id = Invalid_CellID_10.id - 1;
  return atexit(_E17_9);
}

//----- (0070ED90) --------------------------------------------------------  // acclient.c:801869
int _E21_11()
{
  return atexit(_E22_11);
}

//----- (0070EDA0) --------------------------------------------------------  // acclient.c:801875
int _E40_11()
{
  return atexit(_E41_11);
}

//----- (0070EDB0) --------------------------------------------------------  // acclient.c:801881
int _E43_14()
{
  return atexit(_E44_14);
}

