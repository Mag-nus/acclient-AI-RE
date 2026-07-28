/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_advapi32_RegCreateKeyExW
   Object     : _runtime\msvcrt\thunk_advapi32_RegCreateKeyExW.obj
   Functions  : 1
   Addresses  : 006B7FEC - 006B7FEC */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B7FEC) --------------------------------------------------------  // acclient.c:721757
void __stdcall advapi32_RegCreateKeyExW_Thunk()
{
  ResolveThunk(
    "advapi32.dll",
    "RegCreateKeyExW",
    (int (__stdcall **)())RegCreateKeyExW,
    Unicows_RegCreateKeyExW,
    (int (__stdcall *)())GodotFailRegCreateKeyExW);
  JUMPOUT(__CS__, *(_DWORD *)RegCreateKeyExW);
}

