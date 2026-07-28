/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AnimChgs
   Object     : PORTAL\objdesc\AnimChgs.obj
   Functions  : 10
   Addresses  : 005AD830 - 0070E1F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005AD830) --------------------------------------------------------  // acclient.c:471614
BOOL __thiscall Subpalette::replaces(Subpalette *this, Subpalette *change)
{
  unsigned int v2; // eax@1

  v2 = this->offset;
  return v2 == change->offset && this->numcolors == change->numcolors || !v2 && this->numcolors == 2048;
}

//----- (005AD870) --------------------------------------------------------  // acclient.c:471623
BOOL __thiscall Subpalette::supercedes(Subpalette *this, Subpalette *change)
{
  return !this->offset && this->numcolors == 2048 && (change->offset || change->numcolors != 2048);
}

//----- (005AD8A0) --------------------------------------------------------  // acclient.c:471629
unsigned int __thiscall TextureMapChange::Pack(TextureMapChange *this, void **addr, unsigned int size)
{
  TextureMapChange *v3; // ebx@1
  signed int v4; // esi@1
  unsigned int v5; // esi@1
  unsigned int v6; // esi@2

  v3 = this;
  v4 = Pack_AsDataIDOfKnownType(0x5000000u, this->new_tex_id, addr, 0);
  v5 = v4 + Pack_AsDataIDOfKnownType(0x5000000u, v3->old_tex_id, addr, 0) + 1;
  if ( size >= v5 )
  {
    *(_BYTE *)*addr = LOBYTE(v3->part_index);
    *addr = (char *)*addr + 1;
    v6 = v5 - 1 - Pack_AsDataIDOfKnownType(0x5000000u, v3->old_tex_id, addr, v5 - 1);
    v5 = v6 - Pack_AsDataIDOfKnownType(0x5000000u, v3->new_tex_id, addr, v6);
  }
  return v5;
}

//----- (005AD920) --------------------------------------------------------  // acclient.c:471650
int __thiscall TextureMapChange::UnPack(TextureMapChange *this, void **addr, unsigned int size)
{
  TextureMapChange *v3; // edi@1
  int result; // eax@2
  unsigned __int8 v5; // cl@3

  v3 = this;
  if ( size >= 5 )
  {
    v5 = *(_BYTE *)*addr;
    *addr = (char *)*addr + 1;
    v3->part_index = v5;
    if ( Unpack_AsDataIDOfKnownType(0x5000000u, &v3->old_tex_id, addr) )
      result = Unpack_AsDataIDOfKnownType(0x5000000u, &v3->new_tex_id, addr) != 0;
    else
      result = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005AD980) --------------------------------------------------------  // acclient.c:471675
BOOL __thiscall TextureMapChange::replaces(TextureMapChange *this, TextureMapChange *change)
{
  return this->part_index == change->part_index && this->old_tex_id.id == change->old_tex_id.id;
}

//----- (005AD9B0) --------------------------------------------------------  // acclient.c:471681
unsigned int __thiscall AnimPartChange::Pack(AnimPartChange *this, void **addr, unsigned int size)
{
  AnimPartChange *v3; // ebx@1
  unsigned int v4; // esi@1

  v3 = this;
  v4 = Pack_AsDataIDOfKnownType(0x1000000u, this->part_id, addr, 0) + 1;
  if ( size >= v4 )
  {
    *(_BYTE *)*addr = LOBYTE(v3->part_index);
    *addr = (char *)*addr + 1;
    v4 = v4 - 1 - Pack_AsDataIDOfKnownType(0x1000000u, v3->part_id, addr, v4 - 1);
  }
  return v4;
}

//----- (005ADA10) --------------------------------------------------------  // acclient.c:471698
int __thiscall AnimPartChange::UnPack(AnimPartChange *this, void **addr, unsigned int size)
{
  AnimPartChange *v3; // esi@1
  int result; // eax@2
  unsigned int v5; // ecx@3

  v3 = this;
  if ( size >= 3 )
  {
    v5 = *(_BYTE *)*addr;
    *addr = (char *)*addr + 1;
    v3->part_index = v5;
    result = Unpack_AsDataIDOfKnownType(0x1000000u, &v3->part_id, addr) != 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005ADA50) --------------------------------------------------------  // acclient.c:471720
unsigned int __thiscall Subpalette::Pack(Subpalette *this, void **addr, unsigned int size)
{
  Subpalette *v3; // edi@1
  unsigned int v4; // ebx@1
  unsigned int v5; // eax@2
  char *v6; // ecx@2

  v3 = this;
  v4 = Pack_AsDataIDOfKnownType(0x4000000u, this->subID, addr, 0) + 2;
  if ( size >= v4 )
  {
    Pack_AsDataIDOfKnownType(0x4000000u, v3->subID, addr, size);
    v5 = v3->numcolors;
    *(_BYTE *)*addr = v3->offset >> 3;
    v6 = (char *)*addr + 1;
    *addr = v6;
    *v6 = v5 >> 3;
    *addr = (char *)*addr + 1;
  }
  return v4;
}

//----- (005ADAB0) --------------------------------------------------------  // acclient.c:471743
int __thiscall Subpalette::UnPack(Subpalette *this, void **addr, unsigned int size)
{
  void *v3; // ebx@1
  Subpalette *v4; // edi@1
  void *v5; // eax@3
  int result; // eax@4
  unsigned __int8 v7; // cl@5
  unsigned __int8 v8; // cl@5

  v3 = *addr;
  v4 = this;
  if ( size >= 4
    && Unpack_AsDataIDOfKnownType(0x4000000u, &this->subID, addr)
    && (v5 = *addr, (char *)*addr + 2 <= (char *)v3 + size) )
  {
    v7 = *(_BYTE *)v5;
    *addr = (char *)v5 + 1;
    v4->offset = 8 * v7;
    v8 = *(_BYTE *)*addr;
    *addr = (char *)*addr + 1;
    v4->numcolors = v8;
    if ( !v8 )
      v4->numcolors = 256;
    v4->numcolors *= 8;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0070E1F0) --------------------------------------------------------  // acclient.c:801105
int sub_70E1F0()
{
  return atexit(nullsub_1540);
}

