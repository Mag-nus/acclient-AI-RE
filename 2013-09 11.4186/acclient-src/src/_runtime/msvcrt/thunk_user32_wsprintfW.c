/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_user32_wsprintfW
   Object     : _runtime\msvcrt\thunk_user32_wsprintfW.obj
   Functions  : 1
   Addresses  : 006C2AA0 - 006C2AA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006C2AA0) --------------------------------------------------------  // acclient.c:731134
int __stdcall user32_wsprintfW_Thunk()
{
  ResolveThunk("user32.dll", "wsprintfW", &user32_wsprintfW_Ptr, Unicows_wsprintfW, GodotFailwsprintfW);
  return user32_wsprintfW_Ptr();
}

