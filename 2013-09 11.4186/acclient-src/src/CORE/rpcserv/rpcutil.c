/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : rpcutil
   Object     : CORE\rpcserv\rpcutil.obj
   Functions  : 2
   Addresses  : 006B9BF0 - 006B9C10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B9BF0) --------------------------------------------------------  // acclient.c:721825
void *__stdcall MIDL_user_allocate(unsigned int size)
{
  HANDLE v1; // eax@1

  v1 = GetProcessHeap();
  return HeapAlloc(v1, 0, size);
}

//----- (006B9C10) --------------------------------------------------------  // acclient.c:721834
void __stdcall MIDL_user_free(void *pvBlob)
{
  HANDLE v1; // eax@1

  v1 = GetProcessHeap();
  HeapFree(v1, 0, pvBlob);
}

