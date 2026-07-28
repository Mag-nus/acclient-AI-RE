/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Checksum
   Object     : CORE\core_utils\Checksum.obj
   Functions  : 1
   Addresses  : 0065F6A0 - 0065F6A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0065F6A0) --------------------------------------------------------  // acclient.c:629838
int __cdecl PortalChecksum::CalcChecksum32(const char *data, unsigned int size)
{
  int result; // eax@2
  unsigned int v3; // edx@3
  unsigned int v4; // edi@3
  const char *i; // eax@3
  int v6; // ebx@5
  signed int j; // edx@5
  int v8; // ebp@6

  if ( data )
  {
    v3 = (unsigned int)&data[4 * (size >> 2)];
    v4 = size << 16;
    for ( i = data; (unsigned int)i < v3; i += 4 )
      v4 += *(_DWORD *)i;
    v6 = 0;
    for ( j = 3; i < &data[size]; v6 += v8 )
      v8 = *i++ << 8 * j--;
    result = v6 + v4;
  }
  else
  {
    result = 0;
  }
  return result;
}

