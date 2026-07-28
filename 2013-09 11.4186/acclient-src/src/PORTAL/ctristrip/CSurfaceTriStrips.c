/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSurfaceTriStrips
   Object     : PORTAL\ctristrip\CSurfaceTriStrips.obj
   Functions  : 1
   Addresses  : 00534CF0 - 00534CF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00534CF0) --------------------------------------------------------  // acclient.c:356912
void __thiscall CSurfaceTriStrips::~CSurfaceTriStrips(CSurfaceTriStrips *this)
{
  CTriangleStrip *v1; // ecx@1
  unsigned __int16 *v2; // eax@2
  void *v3; // ebx@2
  CTriangleStrip *v4; // esi@2
  int v5; // eax@2
  int v6; // edi@3

  v1 = this->strips;
  if ( v1 )
  {
    v2 = v1[-1].indices;
    v3 = &v1[-1].indices;
    v4 = &v1[(_DWORD)v2];
    v5 = (int)((char *)v2 - 1);
    if ( v5 >= 0 )
    {
      v6 = v5 + 1;
      do
      {
        --v4;
        CTriangleStrip::~CTriangleStrip(v4);
        --v6;
      }
      while ( v6 );
    }
    operator delete[](v3);
  }
}

