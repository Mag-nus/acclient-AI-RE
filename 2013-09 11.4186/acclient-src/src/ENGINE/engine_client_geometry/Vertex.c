/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Vertex
   Object     : ENGINE\engine_client_geometry\Vertex.obj
   Functions  : 1
   Addresses  : 005D8670 - 005D8670 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005D8670) --------------------------------------------------------  // acclient.c:516498
void __thiscall VertexFormatInfo::GenerateOffsets(VertexFormatInfo *this)
{
  unsigned int v1; // ebx@1
  unsigned int v2; // esi@1
  unsigned int v3; // eax@1
  int v4; // edx@11
  unsigned int v5; // edx@27
  unsigned int v6; // eax@31
  unsigned int v7; // eax@31
  unsigned int v8; // edx@39
  char *v9; // esi@40
  unsigned int v10; // esi@42
  bool v11; // zf@42
  unsigned int v12; // edx@46
  unsigned int v13; // eax@46
  unsigned int v14; // eax@46

  v1 = this->format;
  v2 = 0;
  v3 = this->format & 0xE;
  this->bFVFCompatible = 1;
  this->numWeights = 0;
  if ( v3 == 6 )
    this->numWeights = 1;
  if ( v3 == 8 )
    this->numWeights = 2;
  if ( v3 == 10 )
    this->numWeights = 3;
  if ( v3 == 12 )
    this->numWeights = 4;
  if ( v3 == 14 )
    this->numWeights = 5;
  v4 = v1 & 0xF00;
  this->numTCPairs = 0;
  if ( v4 == 256 )
    this->numTCPairs = 1;
  if ( v4 == 512 )
    this->numTCPairs = 2;
  if ( v4 == 768 )
    this->numTCPairs = 3;
  if ( v4 == 1024 )
    this->numTCPairs = 4;
  if ( v4 == 1280 )
    this->numTCPairs = 5;
  if ( v4 == 1536 )
    this->numTCPairs = 6;
  if ( v4 == 1792 )
    this->numTCPairs = 7;
  if ( v4 == 2048 )
    this->numTCPairs = 8;
  v5 = BYTE2(this->format);
  this->numMatrices = v5;
  if ( v5 )
    this->bFVFCompatible = 0;
  this->offsetOrigin = 0;
  if ( v3 )
    v2 = 12;
  this->offsetWeight1 = v2 + 4;
  this->offsetWeight3 = v2 + 12;
  v6 = this->numWeights;
  this->offsetWeight2 = v2 + 8;
  v7 = v2 + 4 * v6;
  this->offsetWeight0 = v2;
  this->offsetWeight4 = v2 + 16;
  this->offsetNormal = v7;
  if ( v1 & 0x10 )
    v7 += 12;
  this->offsetPointSize = v7;
  if ( v1 & 0x20 )
    v7 += 4;
  this->offsetDiffuse = v7;
  if ( v1 & 0x40 )
    v7 += 4;
  this->offsetSpecular = v7;
  if ( (v1 & 0x80u) != 0 )
    v7 += 4;
  v8 = 0;
  if ( this->numTCPairs )
  {
    v9 = (char *)this->offsetTCPair;
    do
    {
      *(_DWORD *)v9 = v7;
      v7 += 8;
      ++v8;
      v9 += 4;
    }
    while ( v8 < this->numTCPairs );
  }
  v10 = this->format;
  v11 = (this->format & 0x10000000) == 0;
  this->offsetVectorS = v7;
  if ( !v11 )
  {
    v7 += 12;
    this->bFVFCompatible = 0;
  }
  this->offsetVectorT = v7;
  if ( v10 & 0x20000000 )
  {
    v7 += 12;
    this->bFVFCompatible = 0;
  }
  v12 = this->numMatrices;
  this->offsetMatrices = v7;
  v13 = v12 + v7;
  this->offsetMWeights = v13;
  v14 = v13 + 4 * v12;
  this->size = v14;
  if ( v10 & 0x1000000 )
  {
    if ( v14 < 0x20 )
    {
      this->formatFVF = v10 & 0xCE00FFFF;
      this->size = 32;
      return;
    }
    if ( v14 < 0x40 )
    {
      this->formatFVF = v10 & 0xCE00FFFF;
      this->size = 64;
      return;
    }
    if ( v14 < 0x60 )
    {
      this->formatFVF = v10 & 0xCE00FFFF;
      this->size = 96;
      return;
    }
    if ( v14 < 0x80 )
    {
      this->formatFVF = v10 & 0xCE00FFFF;
      this->size = 128;
      return;
    }
    if ( v14 < 0xA0 )
    {
      this->formatFVF = v10 & 0xCE00FFFF;
      this->size = 160;
      return;
    }
    if ( v14 < 0xC0 )
    {
      this->formatFVF = v10 & 0xCE00FFFF;
      this->size = 192;
      return;
    }
    if ( v14 < 0xE0 )
    {
      this->formatFVF = v10 & 0xCE00FFFF;
      this->size = 224;
      return;
    }
    if ( v14 < 0x100 )
      this->size = 256;
  }
  this->formatFVF = v10 & 0xCE00FFFF;
}

