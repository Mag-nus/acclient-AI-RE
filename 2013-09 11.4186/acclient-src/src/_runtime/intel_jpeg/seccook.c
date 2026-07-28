/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : seccook
   Object     : _runtime\intel_jpeg\seccook.obj
   Functions  : 1
   Addresses  : 006B7CC2 - 006B7CC2 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B7CC2) --------------------------------------------------------  // acclient.c:721581
void __noreturn report_failure()
{
  __security_error_handler(1, 0);
  ExitProcess(3u);
}
// 6B7E22: using guessed type int __cdecl __security_error_handler(_DWORD, _DWORD);

