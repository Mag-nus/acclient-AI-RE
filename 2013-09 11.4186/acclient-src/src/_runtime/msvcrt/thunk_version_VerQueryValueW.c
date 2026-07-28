/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_version_VerQueryValueW
   Object     : _runtime\msvcrt\thunk_version_VerQueryValueW.obj
   Functions  : 1
   Addresses  : 005DE903 - 005DE903 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE903) --------------------------------------------------------  // acclient.c:521411
int __stdcall version_VerQueryValueW_Thunk()
{
  ResolveThunk(
    "version.dll",
    "VerQueryValueW",
    &version_VerQueryValueW_Ptr,
    Unicows_VerQueryValueW,
    (int (__stdcall *)())GodotFailVerQueryValueW);
  return version_VerQueryValueW_Ptr();
}

