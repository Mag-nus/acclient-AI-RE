/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : initsect
   Object     : _runtime\intel_jpeg\initsect.obj
   Functions  : 2
   Addresses  : 005DE600 - 005DE644 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE600) --------------------------------------------------------  // acclient.c:521229
void _RTC_Initialize()
{
  void (__cdecl *const *f)(); // [sp+Ch] [bp-1Ch]@1

  for ( f = (void (__cdecl *const *)())&__rtc_izz; (unsigned int)f < (unsigned int)&__rtc_izz; ++f )
  {
    if ( *f )
      (*(void (**)(void))f)();
  }
}

//----- (005DE644) --------------------------------------------------------  // acclient.c:521241
void __cdecl _RTC_Terminate()
{
  void (__cdecl *const *f)(); // [sp+Ch] [bp-1Ch]@1

  for ( f = (void (__cdecl *const *)())&__rtc_tzz; (unsigned int)f < (unsigned int)&__rtc_tzz; ++f )
  {
    if ( *f )
      (*(void (**)(void))f)();
  }
}

