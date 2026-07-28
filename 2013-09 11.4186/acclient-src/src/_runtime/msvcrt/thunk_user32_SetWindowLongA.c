/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_user32_SetWindowLongA
   Object     : _runtime\msvcrt\thunk_user32_SetWindowLongA.obj
   Functions  : 1
   Addresses  : 005DE928 - 005DE928 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE928) --------------------------------------------------------  // acclient.c:521423
void __stdcall user32_SetWindowLongA_Thunk()
{
  ResolveThunk(
    "user32.dll",
    "SetWindowLongA",
    (int (__stdcall **)())SetWindowLongA,
    Unicows_SetWindowLongA,
    (int (__stdcall *)())GodotFailSetWindowLongA);
  JUMPOUT(__CS__, *(_DWORD *)SetWindowLongA);
}

