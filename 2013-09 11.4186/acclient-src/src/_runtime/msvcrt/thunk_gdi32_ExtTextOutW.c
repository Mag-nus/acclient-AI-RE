/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_gdi32_ExtTextOutW
   Object     : _runtime\msvcrt\thunk_gdi32_ExtTextOutW.obj
   Functions  : 1
   Addresses  : 006B7F7D - 006B7F7D */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B7F7D) --------------------------------------------------------  // acclient.c:721721
int __stdcall gdi32_ExtTextOutW_Thunk()
{
  ResolveThunk(
    "gdi32.dll",
    "ExtTextOutW",
    &gdi32_ExtTextOutW_Ptr,
    Unicows_ExtTextOutW,
    (int (__stdcall *)())GodotFailExtTextOutW);
  return gdi32_ExtTextOutW_Ptr();
}

