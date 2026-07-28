/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_kernel32_GetTempFileNameW
   Object     : _runtime\msvcrt\thunk_kernel32_GetTempFileNameW.obj
   Functions  : 1
   Addresses  : 006B7EC4 - 006B7EC4 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B7EC4) --------------------------------------------------------  // acclient.c:721661
int __stdcall kernel32_GetTempFileNameW_Thunk()
{
  ResolveThunk(
    "kernel32.dll",
    "GetTempFileNameW",
    &kernel32_GetTempFileNameW_Ptr,
    Unicows_GetTempFileNameW,
    (int (__stdcall *)())GodotFailVerQueryValueW);
  return kernel32_GetTempFileNameW_Ptr();
}

