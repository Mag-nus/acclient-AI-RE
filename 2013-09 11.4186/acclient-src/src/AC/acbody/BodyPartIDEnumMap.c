/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : BodyPartIDEnumMap
   Object     : AC\acbody\BodyPartIDEnumMap.obj
   Functions  : 1
   Addresses  : 005D0EC0 - 005D0EC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005D0EC0) --------------------------------------------------------  // acclient.c:508932
unsigned int __cdecl BodyPartEnumMapper::BodyPartToString(const int bp, char *buf, const unsigned int size)
{
  const char *v3; // ecx@2
  const unsigned int result; // eax@30
  const char *v5; // eax@31
  char *v6; // edx@31
  char v7; // cl@32

  switch ( bp + 1 )
  {
    case 0:
      v3 = "UNDEFINED";
      break;
    case 1:
      v3 = "HEAD";
      break;
    case 2:
      v3 = "CHEST";
      break;
    case 3:
      v3 = "ABDOMEN";
      break;
    case 4:
      v3 = "UPPER_ARM";
      break;
    case 5:
      v3 = "LOWER_ARM";
      break;
    case 6:
      v3 = "HAND";
      break;
    case 7:
      v3 = "UPPER_LEG";
      break;
    case 8:
      v3 = "LOWER_LEG";
      break;
    case 9:
      v3 = "FOOT";
      break;
    case 10:
      v3 = "HORN";
      break;
    case 11:
      v3 = "FRONT_LEG";
      break;
    case 13:
      v3 = "FRONT_FOOT";
      break;
    case 14:
      v3 = "REAR_LEG";
      break;
    case 16:
      v3 = "REAR_FOOT";
      break;
    case 17:
      v3 = "TORSO";
      break;
    case 18:
      v3 = "TAIL";
      break;
    case 19:
      v3 = "ARM";
      break;
    case 20:
      v3 = "LEG";
      break;
    case 21:
      v3 = "CLAW";
      break;
    case 22:
      v3 = "WINGS";
      break;
    case 23:
      v3 = "BREATH";
      break;
    case 24:
      v3 = "TENTACLE";
      break;
    case 25:
      v3 = "UPPER_TENTACLE";
      break;
    case 26:
      v3 = "LOWER_TENTACLE";
      break;
    case 27:
      v3 = "CLOAK";
      break;
    case 28:
      v3 = "NUM";
      break;
    default:
      v3 = "Unknown";
      break;
  }
  result = strlen(v3) + 1;
  if ( size >= result )
  {
    v5 = v3;
    v6 = (char *)(buf - v3);
    do
    {
      v7 = *v5;
      v5[(_DWORD)v6] = *v5;
      ++v5;
    }
    while ( v7 );
    result = 0;
  }
  return result;
}

