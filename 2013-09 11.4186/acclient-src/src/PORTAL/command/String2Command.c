/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : String2Command
   Object     : PORTAL\command\String2Command.obj
   Functions  : 1
   Addresses  : 006B4C20 - 006B4C20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B4C20) --------------------------------------------------------  // acclient.c:718577
unsigned int __cdecl string2command(const char *s)
{
  unsigned int v1; // kr00_4@1
  unsigned int v2; // esi@1

  v1 = strlen(s);
  v2 = 0;
  while ( __strnicmp(s, command_strings[v2], v1 + 1) )
  {
    ++v2;
    if ( v2 >= 0x198 )
      return 0;
  }
  return command_ids_1[v2];
}

