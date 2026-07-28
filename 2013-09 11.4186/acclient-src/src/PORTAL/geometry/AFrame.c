/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AFrame
   Object     : PORTAL\geometry\AFrame.obj
   Functions  : 3
   Addresses  : 005A9E30 - 005A9FB0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005A9E30) --------------------------------------------------------  // acclient.c:467555
int __thiscall AFrame::IsValid(AFrame *this)
{
  AFrame *v1; // esi@1
  signed int v2; // ebx@1
  int result; // eax@11
  float norm; // [sp+14h] [bp-4h]@9

  v1 = this;
  v2 = 1;
  if ( __isnan(this->m_fOrigin.x)
    || __isnan(v1->m_fOrigin.y)
    || __isnan(v1->m_fOrigin.z)
    || __isnan(v1->qw)
    || __isnan(v1->qx)
    || __isnan(v1->qy)
    || __isnan(v1->qz) )
    v2 = 0;
  norm = v1->qz * v1->qz + v1->qy * v1->qy + v1->qx * v1->qx + v1->qw * v1->qw;
  if ( __isnan(norm) || 0.00019999999 * 5.0 < fabs(norm - 1.0) )
    result = 0;
  else
    result = v2;
  return result;
}

//----- (005A9F40) --------------------------------------------------------  // acclient.c:467581
signed int __thiscall AFrame::Pack(AFrame *this, void **addr, unsigned int size)
{
  char *v3; // edx@3
  char *v4; // esi@3
  char *v5; // edx@4
  char *v6; // esi@4
  char *v7; // edx@4

  if ( size >= 0x1C )
  {
    if ( size >= 0xC )
    {
      *(_DWORD *)*addr = LODWORD(this->m_fOrigin.x);
      v3 = (char *)*addr + 4;
      *addr = v3;
      *(float *)v3 = this->m_fOrigin.y;
      v4 = (char *)*addr + 4;
      *addr = v4;
      *(float *)v4 = this->m_fOrigin.z;
      *addr = (char *)*addr + 4;
    }
    *(float *)*addr = this->qw;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = this->qx;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(float *)v6 = this->qy;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(float *)v7 = this->qz;
    *addr = (char *)*addr + 4;
  }
  return 28;
}

//----- (005A9FB0) --------------------------------------------------------  // acclient.c:467618
BOOL __thiscall AFrame::UnPack(AFrame *this, void **addr, unsigned int size)
{
  char *v3; // edx@2
  char *v4; // edx@2
  char *v5; // edx@3
  char *v6; // edx@3
  char *v7; // edx@3

  if ( size >= 0xC )
  {
    LODWORD(this->m_fOrigin.x) = *(_DWORD *)*addr;
    v3 = (char *)*addr + 4;
    *addr = v3;
    LODWORD(this->m_fOrigin.y) = *(_DWORD *)v3;
    v4 = (char *)*addr + 4;
    *addr = v4;
    LODWORD(this->m_fOrigin.z) = *(_DWORD *)v4;
    *addr = (char *)*addr + 4;
  }
  LODWORD(this->qw) = *(_DWORD *)*addr;
  v5 = (char *)*addr + 4;
  *addr = v5;
  LODWORD(this->qx) = *(_DWORD *)v5;
  v6 = (char *)*addr + 4;
  *addr = v6;
  LODWORD(this->qy) = *(_DWORD *)v6;
  v7 = (char *)*addr + 4;
  *addr = v7;
  LODWORD(this->qz) = *(_DWORD *)v7;
  *addr = (char *)*addr + 4;
  return AFrame::IsValid(this) != 0;
}

