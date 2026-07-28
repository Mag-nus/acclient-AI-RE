/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_kernel32_DeleteFileW
   Object     : _runtime\msvcrt\thunk_kernel32_DeleteFileW.obj
   Functions  : 1
   Addresses  : 006B7E7A - 006B7E7A */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B7E7A) --------------------------------------------------------  // acclient.c:721637
void __stdcall kernel32_DeleteFileW_Thunk()
{
  ResolveThunk(
    "kernel32.dll",
    "DeleteFileW",
    (int (__stdcall **)())DeleteFileW,
    Unicows_DeleteFileW,
    (int (__stdcall *)())GodotFailCreateFontIndirectW);
  JUMPOUT(__CS__, *(_DWORD *)DeleteFileW);
}

