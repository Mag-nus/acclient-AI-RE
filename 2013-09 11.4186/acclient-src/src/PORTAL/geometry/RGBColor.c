/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RGBColor
   Object     : PORTAL\geometry\RGBColor.obj
   Functions  : 3
   Addresses  : 00524810 - 005AA080 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00524810) --------------------------------------------------------  // acclient.c:339670
signed int __cdecl EtherealHook::pack_size()
{
  return 4;
}

//----- (005AA020) --------------------------------------------------------  // acclient.c:467652
signed int __thiscall RGBColor::Pack(RGBColor *this, void **addr, unsigned int size)
{
  *(_DWORD *)*addr = (unsigned __int64)(this->b * 255.0) | (((unsigned int)(unsigned __int64)(this->g * 255.0) | (((unsigned __int8)(unsigned __int64)(this->r * 255.0) | 0xFFFFFF00) << 8)) << 8);
  *addr = (char *)*addr + 4;
  return 4;
}

//----- (005AA080) --------------------------------------------------------  // acclient.c:467660
int __thiscall RGBColor::UnPack(RGBColor *this, void **addr, unsigned int size)
{
  const unsigned int v3; // ST00_4@1

  v3 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  RGBColor::SetColor32(this, v3);
  return 1;
}

