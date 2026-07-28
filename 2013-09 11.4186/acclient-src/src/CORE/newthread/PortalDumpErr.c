/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PortalDumpErr
   Object     : CORE\newthread\PortalDumpErr.obj
   Functions  : 1
   Addresses  : 006601F0 - 006601F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006601F0) --------------------------------------------------------  // acclient.c:630603
void __thiscall PortalThreadErrorDump::DumpLastError(char *ecx0)
{
  DWORD v1; // eax@1
  char *buf; // [sp+0h] [bp-4h]@1

  buf = ecx0;
  v1 = GetLastError();
  FormatMessageA(0x1100u, 0, v1, 0x400u, (LPSTR)&buf, 0, 0);
  LocalFree(buf);
}

