/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_kernel32_WideCharToMultiByte
   Object     : _runtime\msvcrt\thunk_kernel32_WideCharToMultiByte.obj
   Functions  : 1
   Addresses  : 005DE800 - 005DE800 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE800) --------------------------------------------------------  // acclient.c:521327
void __stdcall kernel32_WideCharToMultiByte_Thunk()
{
  ResolveThunk(
    "kernel32.dll",
    "WideCharToMultiByte",
    (int (__stdcall **)())WideCharToMultiByte,
    Unicows_WideCharToMultiByte,
    (int (__stdcall *)())GodotFailWideCharToMultiByte);
  JUMPOUT(__CS__, *(_DWORD *)WideCharToMultiByte);
}

