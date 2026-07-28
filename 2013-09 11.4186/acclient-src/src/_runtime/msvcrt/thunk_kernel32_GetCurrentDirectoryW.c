/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_kernel32_GetCurrentDirectoryW
   Object     : _runtime\msvcrt\thunk_kernel32_GetCurrentDirectoryW.obj
   Functions  : 1
   Addresses  : 005DE86F - 005DE86F */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE86F) --------------------------------------------------------  // acclient.c:521363
int __stdcall kernel32_GetCurrentDirectoryW_Thunk()
{
  ResolveThunk(
    "kernel32.dll",
    "GetCurrentDirectoryW",
    &kernel32_GetCurrentDirectoryW_Ptr,
    Unicows_GetCurrentDirectoryW,
    (int (__stdcall *)())GodotFailGetCurrentDirectoryW);
  return kernel32_GetCurrentDirectoryW_Ptr();
}

