/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : WeenieOrderHdr
   Object     : PORTAL\gameplay_net\WeenieOrderHdr.obj
   Functions  : 2
   Addresses  : 006B0AA0 - 006B0AE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B0AA0) --------------------------------------------------------  // acclient.c:713847
signed int __thiscall WOrderHdr::Pack(WOrderHdr *this, void **addr, unsigned int size)
{
  char *v3; // esi@2
  char *v4; // edx@2

  if ( size >= 0xC )
  {
    *(_DWORD *)*addr = 63408;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = this->iid_;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_DWORD *)v4 = this->stamp_;
    *addr = (char *)*addr + 4;
  }
  return 12;
}

//----- (006B0AE0) --------------------------------------------------------  // acclient.c:713867
int __thiscall WOrderHdr::UnPack(WOrderHdr *this, void **addr, unsigned int size)
{
  void *v3; // edx@1
  int v4; // edi@1
  char *v5; // esi@1
  int result; // eax@2
  char *v7; // edx@3

  v3 = *addr;
  v4 = *(_DWORD *)*addr;
  v5 = (char *)*addr + 4;
  *addr = v5;
  if ( v4 == 63408 )
  {
    this->iid_ = *(_DWORD *)v5;
    v7 = (char *)*addr + 4;
    *addr = v7;
    this->stamp_ = *(_DWORD *)v7;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    this->isFromWeenie_ = 0;
    *addr = v3;
    result = 0;
  }
  return result;
}

