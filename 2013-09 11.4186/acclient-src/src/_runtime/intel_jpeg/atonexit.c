/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : atonexit
   Object     : _runtime\intel_jpeg\atonexit.obj
   Functions  : 2
   Addresses  : 005DDFF0 - 005DE016 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DDFF0) --------------------------------------------------------  // acclient.c:521052
int (__cdecl *__cdecl _onexit(int (__cdecl *func)()))()
{
  int (__cdecl *result)(); // eax@2

  if ( __onexitbegin == -1 )
    result = __onexit(func);
  else
    result = (int (__cdecl *)())__dllonexit(func, &__onexitbegin, &__onexitend);
  return result;
}
// 5DE5EE: using guessed type int __cdecl __dllonexit(_DWORD, _DWORD, _DWORD);
// 9057CC: using guessed type int __onexitend;
// 9057D0: using guessed type int __onexitbegin;

//----- (005DE016) --------------------------------------------------------  // acclient.c:521067
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != 0) - 1;
}

