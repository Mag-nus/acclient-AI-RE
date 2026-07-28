/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_kernel32_CreateFileW
   Object     : _runtime\msvcrt\thunk_kernel32_CreateFileW.obj
   Functions  : 1
   Addresses  : 006B7E30 - 006B7E30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B7E30) --------------------------------------------------------  // acclient.c:721613
void __stdcall kernel32_CreateFileW_Thunk()
{
  ResolveThunk(
    "kernel32.dll",
    "CreateFileW",
    (int (__stdcall **)())CreateFileW,
    Unicows_CreateFileW,
    (int (__stdcall *)())GodotFailCreateFileW);
  JUMPOUT(__CS__, *(_DWORD *)CreateFileW);
}

