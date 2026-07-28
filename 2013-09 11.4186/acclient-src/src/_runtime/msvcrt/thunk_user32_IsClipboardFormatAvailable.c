/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : thunk_user32_IsClipboardFormatAvailable
   Object     : _runtime\msvcrt\thunk_user32_IsClipboardFormatAvailable.obj
   Functions  : 1
   Addresses  : 005DE972 - 005DE972 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE972) --------------------------------------------------------  // acclient.c:521447
void __stdcall user32_IsClipboardFormatAvailable_Thunk()
{
  ResolveThunk(
    "user32.dll",
    "IsClipboardFormatAvailable",
    (int (__stdcall **)())IsClipboardFormatAvailable,
    Unicows_IsClipboardFormatAvailable,
    (int (__stdcall *)())GodotFailIsClipboardFormatAvailable);
  JUMPOUT(__CS__, *(_DWORD *)IsClipboardFormatAvailable);
}

