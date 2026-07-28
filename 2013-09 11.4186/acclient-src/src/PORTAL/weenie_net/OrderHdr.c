/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : OrderHdr
   Object     : PORTAL\weenie_net\OrderHdr.obj
   Functions  : 2
   Addresses  : 006B30D0 - 006B3100 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B30D0) --------------------------------------------------------  // acclient.c:716784
signed int __thiscall OrderHdr::Pack(OrderHdr *this, void **addr, unsigned int size)
{
  char *v3; // edx@2

  if ( size >= 8 )
  {
    *(_DWORD *)*addr = 63409;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = this->stamp_;
    *addr = (char *)*addr + 4;
  }
  return 8;
}

//----- (006B3100) --------------------------------------------------------  // acclient.c:716800
int __thiscall OrderHdr::UnPack(OrderHdr *this, void **addr, unsigned int size)
{
  void *v3; // edx@1
  bool v4; // zf@2

  v3 = *addr;
  if ( size < 4 )
    return 0;
  v4 = *(_DWORD *)v3 == 63409;
  *addr = (char *)v3 + 4;
  if ( !v4 )
  {
    *addr = v3;
    return 0;
  }
  this->stamp_ = *((_DWORD *)v3 + 1);
  *addr = (char *)*addr + 4;
  return 1;
}

