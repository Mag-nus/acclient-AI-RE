/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_kernel32_FindResourceW
   Object     : _runtime\msvcrt\thunk_kernel32_FindResourceW.obj
   Functions  : 1
   Addresses  : 006B7E55 - 006B7E55 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B7E55) --------------------------------------------------------  // acclient.c:721625
int __stdcall kernel32_FindResourceW_Thunk()
{
  ResolveThunk(
    "kernel32.dll",
    "FindResourceW",
    &kernel32_FindResourceW_Ptr,
    Unicows_FindResourceW,
    (int (__stdcall *)())GodotFailFindResourceW);
  return kernel32_FindResourceW_Ptr();
}

