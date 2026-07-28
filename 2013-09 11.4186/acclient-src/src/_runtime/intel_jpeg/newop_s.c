/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : newop_s
   Object     : _runtime\intel_jpeg\newop_s.obj
   Functions  : 1
   Addresses  : 005DDFC5 - 005DDFC5 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DDFC5) --------------------------------------------------------  // acclient.c:521034
void *__cdecl operator new(unsigned int size)
{
  void *result; // eax@4

  while ( 1 )
  {
    result = malloc(size);
    if ( result )
      break;
    if ( !_callnewh(size) )
      std::_Nomemory();
  }
  return result;
}
// 5DE5E8: using guessed type int __cdecl _callnewh(_DWORD);
// 79222C: using guessed type void __cdecl std::_Nomemory();

