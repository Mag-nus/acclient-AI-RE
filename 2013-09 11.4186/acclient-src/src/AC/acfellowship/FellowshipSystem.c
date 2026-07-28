/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : FellowshipSystem
   Object     : AC\acfellowship\FellowshipSystem.obj
   Functions  : 6
   Addresses  : 005B9B80 - 0070E8A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B9B80) --------------------------------------------------------  // acclient.c:484589
signed __int64 __cdecl FellowshipSystem::GetExperienceProportion(unsigned int level)
{
  return ExperienceSystem::ExperienceToRaiseLevel(level, level + 1);
}

//----- (005B9BA0) --------------------------------------------------------  // acclient.c:484595
double __cdecl FellowshipSystem::GetEvenSplitXPPctg(unsigned int uiNumFellows)
{
  double result; // st7@2

  switch ( uiNumFellows )
  {
    case 1u:
      result = 1.0;
      break;
    case 2u:
      result = 0.75;
      break;
    case 3u:
      result = 0.60000002;
      break;
    case 4u:
      result = 0.55000001;
      break;
    case 5u:
      result = 0.5;
      break;
    case 6u:
      result = 0.44999999;
      break;
    case 7u:
      result = 0.40000001;
      break;
    case 8u:
      result = 0.34999999;
      break;
    case 9u:
      result = 0.31111109;
      break;
    case 0xAu:
      result = 0.28;
      break;
    default:
      result = 0.0;
      break;
  }
  return result;
}

//----- (0070E840) --------------------------------------------------------  // acclient.c:801513
void sub_70E840()
{
  flt_8EF474 = 1000.0 + 1.0;
}

//----- (0070E860) --------------------------------------------------------  // acclient.c:801519
void sub_70E860()
{
  flt_8EF478 = 24.0 * 8.0;
}

//----- (0070E880) --------------------------------------------------------  // acclient.c:801525
void sub_70E880()
{
  flt_8EF47C = 24.0 * 0.5;
}

//----- (0070E8A0) --------------------------------------------------------  // acclient.c:801531
int sub_70E8A0()
{
  return atexit(nullsub_1556);
}

