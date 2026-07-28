/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : seccinit
   Object     : _runtime\intel_jpeg\seccinit.obj
   Functions  : 1
   Addresses  : 006B7DCC - 006B7DCC */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B7DCC) --------------------------------------------------------  // acclient.c:721589
unsigned int __security_init_cookie()
{
  unsigned int v0; // esi@1
  DWORD v1; // esi@1
  DWORD v2; // esi@1
  DWORD v3; // esi@1
  unsigned int result; // eax@1
  _LARGE_INTEGER perfctr; // [sp+4h] [bp-10h]@1
  FT systime; // [sp+Ch] [bp-8h]@1

  GetSystemTimeAsFileTime((LPFILETIME)&systime);
  v0 = systime.ft_struct.dwLowDateTime ^ systime.ft_struct.dwHighDateTime;
  v1 = GetCurrentProcessId() ^ v0;
  v2 = GetCurrentThreadId() ^ v1;
  v3 = GetTickCount() ^ v2;
  QueryPerformanceCounter(&perfctr);
  result = perfctr.LowPart ^ perfctr.HighPart;
  __security_cookie = perfctr.LowPart ^ perfctr.HighPart ^ v3;
  if ( !__security_cookie )
    __security_cookie = -1153374642;
  return result;
}

