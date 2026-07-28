/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_kernel32_CreateDirectoryW
   Object     : _runtime\msvcrt\thunk_kernel32_CreateDirectoryW.obj
   Functions  : 1
   Addresses  : 005DE825 - 005DE825 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE825) --------------------------------------------------------  // acclient.c:521339
void __stdcall kernel32_CreateDirectoryW_Thunk()
{
  ResolveThunk(
    "kernel32.dll",
    "CreateDirectoryW",
    (int (__stdcall **)())CreateDirectoryW,
    Unicows_CreateDirectoryW,
    (int (__stdcall *)())GodotFailGetCurrentDirectoryW);
  JUMPOUT(__CS__, *(_DWORD *)CreateDirectoryW);
}

