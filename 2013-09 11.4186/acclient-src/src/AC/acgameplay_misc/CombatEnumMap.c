/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CombatEnumMap
   Object     : AC\acgameplay_misc\CombatEnumMap.obj
   Functions  : 10
   Addresses  : 005C9B80 - 0070FBE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005C9B80) --------------------------------------------------------  // acclient.c:500917
AC1Legacy::PStringBase<char> *__cdecl CombatEnumMapper::CombatModeToString(AC1Legacy::PStringBase<char> *result, COMBAT_MODE combatMode)
{
  AC1Legacy::PStringBase<char> *v2; // eax@2

  switch ( combatMode )
  {
    case 1:
      AC1Legacy::PStringBase<char>::PStringBase<char>(result, "peace");
      v2 = result;
      break;
    case 2:
      AC1Legacy::PStringBase<char>::PStringBase<char>(result, "melee");
      v2 = result;
      break;
    case 4:
      AC1Legacy::PStringBase<char>::PStringBase<char>(result, "missile");
      v2 = result;
      break;
    case 8:
      AC1Legacy::PStringBase<char>::PStringBase<char>(result, "magic");
      v2 = result;
      break;
    default:
      AC1Legacy::PStringBase<char>::PStringBase<char>(result, "unknown");
      v2 = result;
      break;
  }
  return v2;
}

//----- (0070FB20) --------------------------------------------------------  // acclient.c:802927
int sub_70FB20()
{
  return atexit(nullsub_1721);
}

//----- (0070FB30) --------------------------------------------------------  // acclient.c:802933
int _E4_19()
{
  return atexit(_E5_19);
}

//----- (0070FB40) --------------------------------------------------------  // acclient.c:802939
int _E7_19()
{
  Outside_CellID_19.id = Invalid_CellID_19.id + 1;
  return atexit(_E8_19);
}

//----- (0070FB60) --------------------------------------------------------  // acclient.c:802946
int _E10_18()
{
  In_Limbo_CellID_18.id = Outside_CellID_19.id + 1;
  return atexit(_E11_18);
}

//----- (0070FB80) --------------------------------------------------------  // acclient.c:802953
int _E13_18()
{
  First_Interior_CellID_18.id = In_Limbo_CellID_18.id + 1;
  return atexit(_E14_18);
}

//----- (0070FBA0) --------------------------------------------------------  // acclient.c:802960
int _E16_18()
{
  Last_Interior_CellID_18.id = Invalid_CellID_19.id - 1;
  return atexit(_E17_18);
}

//----- (0070FBC0) --------------------------------------------------------  // acclient.c:802967
int _E21_20()
{
  return atexit(_E22_20);
}

//----- (0070FBD0) --------------------------------------------------------  // acclient.c:802973
int _E40_20()
{
  return atexit(_E41_20);
}

//----- (0070FBE0) --------------------------------------------------------  // acclient.c:802979
int _E43_23()
{
  return atexit(_E44_23);
}

