/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MagicSystem
   Object     : AC\acmagic\MagicSystem.obj
   Functions  : 11
   Addresses  : 005BD240 - 0070EF50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005BD240) --------------------------------------------------------  // acclient.c:488432
signed int __cdecl MagicSystem::DeterminePowerLevelOfComponent(const unsigned int scid)
{
  signed int result; // eax@1

  result = 0;
  switch ( scid )
  {
    case 1u:
      result = 1;
      break;
    case 2u:
      result = 2;
      break;
    case 3u:
      result = 3;
      break;
    case 4u:
      result = 4;
      break;
    case 5u:
      result = 5;
      break;
    case 6u:
      result = 6;
      break;
    case 0x6Eu:
      result = 7;
      break;
    case 0x70u:
      result = 8;
      break;
    case 0xC0u:
      result = 9;
      break;
    case 0xC1u:
      result = 10;
      break;
    default:
      return result;
  }
  return result;
}

//----- (005BD390) --------------------------------------------------------  // acclient.c:488476
signed int __cdecl MagicSystem::GetLowestTaperID()
{
  return 63;
}

//----- (0070EE90) --------------------------------------------------------  // acclient.c:801945
int sub_70EE90()
{
  return atexit(nullsub_1563);
}

//----- (0070EEA0) --------------------------------------------------------  // acclient.c:801951
int _E4_12()
{
  return atexit(_E5_12);
}

//----- (0070EEB0) --------------------------------------------------------  // acclient.c:801957
int _E7_12()
{
  Outside_CellID_12.id = Invalid_CellID_12.id + 1;
  return atexit(_E8_12);
}

//----- (0070EED0) --------------------------------------------------------  // acclient.c:801964
int _E10_11()
{
  In_Limbo_CellID_11.id = Outside_CellID_12.id + 1;
  return atexit(_E11_11);
}

//----- (0070EEF0) --------------------------------------------------------  // acclient.c:801971
int _E13_11()
{
  First_Interior_CellID_11.id = In_Limbo_CellID_11.id + 1;
  return atexit(_E14_11);
}

//----- (0070EF10) --------------------------------------------------------  // acclient.c:801978
int _E16_11()
{
  Last_Interior_CellID_11.id = Invalid_CellID_12.id - 1;
  return atexit(_E17_11);
}

//----- (0070EF30) --------------------------------------------------------  // acclient.c:801985
int _E21_13()
{
  return atexit(_E22_13);
}

//----- (0070EF40) --------------------------------------------------------  // acclient.c:801991
int _E40_13()
{
  return atexit(_E41_13);
}

//----- (0070EF50) --------------------------------------------------------  // acclient.c:801997
int _E43_16()
{
  return atexit(_E44_16);
}

