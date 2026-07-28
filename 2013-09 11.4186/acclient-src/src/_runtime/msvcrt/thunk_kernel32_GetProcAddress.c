/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_kernel32_GetProcAddress
   Object     : _runtime\msvcrt\thunk_kernel32_GetProcAddress.obj
   Functions  : 1
   Addresses  : 005DE8DE - 005DE8DE */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE8DE) --------------------------------------------------------  // acclient.c:521399
void __stdcall kernel32_GetProcAddress_Thunk()
{
  ResolveThunk(
    "kernel32.dll",
    "GetProcAddress",
    (int (__stdcall **)())GetProcAddress,
    Unicows_GetProcAddress,
    (int (__stdcall *)())GodotFailGetProcAddress);
  JUMPOUT(__CS__, *(_DWORD *)GetProcAddress);
}

