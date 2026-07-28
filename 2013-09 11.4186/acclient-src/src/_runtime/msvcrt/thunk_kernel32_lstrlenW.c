/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_kernel32_lstrlenW
   Object     : _runtime\msvcrt\thunk_kernel32_lstrlenW.obj
   Functions  : 1
   Addresses  : 005DE9BC - 005DE9BC */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE9BC) --------------------------------------------------------  // acclient.c:521471
int __stdcall kernel32_lstrlenW_Thunk()
{
  ResolveThunk(
    "kernel32.dll",
    "lstrlenW",
    &kernel32_lstrlenW_Ptr,
    Unicows_lstrlenW,
    (int (__stdcall *)())GodotFaillstrlenW);
  return kernel32_lstrlenW_Ptr();
}

