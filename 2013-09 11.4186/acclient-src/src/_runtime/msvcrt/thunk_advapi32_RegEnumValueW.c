/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_advapi32_RegEnumValueW
   Object     : _runtime\msvcrt\thunk_advapi32_RegEnumValueW.obj
   Functions  : 1
   Addresses  : 006B7FC7 - 006B7FC7 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B7FC7) --------------------------------------------------------  // acclient.c:721745
int __stdcall advapi32_RegEnumValueW_Thunk()
{
  ResolveThunk(
    "advapi32.dll",
    "RegEnumValueW",
    &advapi32_RegEnumValueW_Ptr,
    Unicows_RegEnumValueW,
    (int (__stdcall *)())GodotFailRegEnumValueW);
  return advapi32_RegEnumValueW_Ptr();
}

