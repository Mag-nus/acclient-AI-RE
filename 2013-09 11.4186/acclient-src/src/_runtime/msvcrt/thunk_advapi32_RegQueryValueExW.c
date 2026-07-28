/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_advapi32_RegQueryValueExW
   Object     : _runtime\msvcrt\thunk_advapi32_RegQueryValueExW.obj
   Functions  : 1
   Addresses  : 005DE894 - 005DE894 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE894) --------------------------------------------------------  // acclient.c:521375
int __stdcall advapi32_RegQueryValueExW_Thunk()
{
  ResolveThunk(
    "advapi32.dll",
    "RegQueryValueExW",
    &advapi32_RegQueryValueExW_Ptr,
    Unicows_RegQueryValueExW,
    (int (__stdcall *)())GodotFailRegQueryValueExW);
  return advapi32_RegQueryValueExW_Ptr();
}

