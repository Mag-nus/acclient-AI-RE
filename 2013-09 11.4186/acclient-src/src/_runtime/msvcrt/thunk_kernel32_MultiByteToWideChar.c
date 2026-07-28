/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_kernel32_MultiByteToWideChar
   Object     : _runtime\msvcrt\thunk_kernel32_MultiByteToWideChar.obj
   Functions  : 1
   Addresses  : 00405260 - 00405260 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00405260) --------------------------------------------------------  // acclient.c:64077
void __stdcall kernel32_MultiByteToWideChar_Thunk()
{
  ResolveThunk(
    "kernel32.dll",
    "MultiByteToWideChar",
    (int (__stdcall **)())MultiByteToWideChar,
    Unicows_MultiByteToWideChar,
    (int (__stdcall *)())GodotFailMultiByteToWideChar);
  JUMPOUT(__CS__, *(_DWORD *)MultiByteToWideChar);
}

