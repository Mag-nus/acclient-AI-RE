/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ehvecdtr
   Object     : _runtime\intel_jpeg\ehvecdtr.obj
   Functions  : 2
   Addresses  : 005DE4B0 - 005DE50E */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE4B0) --------------------------------------------------------  // acclient.c:521202
void __stdcall __ArrayUnwind(void *ptr, unsigned int size, int count, void (__thiscall *pDtor)(void *))
{
  while ( 1 )
  {
    --count;
    if ( count < 0 )
      break;
    ptr = (char *)ptr - size;
    ((void (*)(void))pDtor)();
  }
}

//----- (005DE50E) --------------------------------------------------------  // acclient.c:521215
void __stdcall eh_vector_destructor_iterator(void *ptr, unsigned int size, int count, void (__thiscall *pDtor)(void *))
{
  char *ptra; // [sp+30h] [bp+8h]@1

  for ( ptra = (char *)ptr + count * size; ; pDtor(ptra) )
  {
    --count;
    if ( count < 0 )
      break;
    ptra -= size;
  }
}

