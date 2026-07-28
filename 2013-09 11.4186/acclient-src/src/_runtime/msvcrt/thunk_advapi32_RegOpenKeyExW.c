/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_advapi32_RegOpenKeyExW
   Object     : _runtime\msvcrt\thunk_advapi32_RegOpenKeyExW.obj
   Functions  : 1
   Addresses  : 005DE8B9 - 005DE8B9 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE8B9) --------------------------------------------------------  // acclient.c:521387
void __stdcall advapi32_RegOpenKeyExW_Thunk()
{
  ResolveThunk(
    "advapi32.dll",
    "RegOpenKeyExW",
    (int (__stdcall **)())RegOpenKeyExW,
    Unicows_RegOpenKeyExW,
    (int (__stdcall *)())GodotFailRegOpenKeyExW);
  JUMPOUT(__CS__, *(_DWORD *)RegOpenKeyExW);
}

