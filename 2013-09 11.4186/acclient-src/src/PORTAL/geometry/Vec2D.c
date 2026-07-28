/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Vec2D
   Object     : PORTAL\geometry\Vec2D.obj
   Functions  : 3
   Addresses  : 0051F6D0 - 005A9E00 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051F6D0) --------------------------------------------------------  // acclient.c:333696
signed int TextureVelocityHook::pack_size()
{
  return 8;
}

//----- (005A9DD0) --------------------------------------------------------  // acclient.c:467526
signed int __thiscall Vec2D::Pack(Vec2D *this, void **addr, unsigned int size)
{
  char *v3; // edx@2

  if ( size >= 8 )
  {
    *(_DWORD *)*addr = LODWORD(this->x);
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(float *)v3 = this->y;
    *addr = (char *)*addr + 4;
  }
  return 8;
}

//----- (005A9E00) --------------------------------------------------------  // acclient.c:467542
int __thiscall Vec2D::UnPack(Vec2D *this, void **addr, unsigned int size)
{
  char *v3; // edx@1

  LODWORD(this->x) = *(_DWORD *)*addr;
  v3 = (char *)*addr + 4;
  *addr = v3;
  LODWORD(this->y) = *(_DWORD *)v3;
  *addr = (char *)*addr + 4;
  return 1;
}

