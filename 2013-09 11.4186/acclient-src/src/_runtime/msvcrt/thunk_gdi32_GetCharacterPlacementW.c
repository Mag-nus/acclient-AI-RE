/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_gdi32_GetCharacterPlacementW
   Object     : _runtime\msvcrt\thunk_gdi32_GetCharacterPlacementW.obj
   Functions  : 1
   Addresses  : 006B7F0E - 006B7F0E */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B7F0E) --------------------------------------------------------  // acclient.c:721685
void __stdcall gdi32_GetCharacterPlacementW_Thunk()
{
  ResolveThunk(
    "gdi32.dll",
    "GetCharacterPlacementW",
    (int (__stdcall **)())GetCharacterPlacementW,
    Unicows_GetCharacterPlacementW,
    (int (__stdcall *)())GodotFailGetCharacterPlacementW);
  JUMPOUT(__CS__, *(_DWORD *)GetCharacterPlacementW);
}

