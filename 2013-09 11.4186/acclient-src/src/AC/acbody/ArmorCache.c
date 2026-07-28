/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ArmorCache
   Object     : AC\acbody\ArmorCache.obj
   Functions  : 2
   Addresses  : 005D14B0 - 005D1540 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005D14B0) --------------------------------------------------------  // acclient.c:509361
signed int __thiscall ArmorCache::Pack(ArmorCache *this, void **addr, unsigned int size)
{
  char *v3; // esi@2
  char *v4; // edx@2
  char *v5; // esi@2
  char *v6; // edx@2
  char *v7; // esi@2
  char *v8; // edx@2
  char *v9; // esi@2
  char *v10; // edx@2

  if ( size >= 0x24 )
  {
    *(_DWORD *)*addr = this->_base_armor;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = this->_armor_vs_slash;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_DWORD *)v4 = this->_armor_vs_pierce;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = this->_armor_vs_bludgeon;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = this->_armor_vs_cold;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = this->_armor_vs_fire;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = this->_armor_vs_acid;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = this->_armor_vs_electric;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(_DWORD *)v10 = this->_armor_vs_nether;
    *addr = (char *)*addr + 4;
  }
  return 36;
}

//----- (005D1540) --------------------------------------------------------  // acclient.c:509405
int __thiscall ArmorCache::UnPack(ArmorCache *this, void **addr, unsigned int size)
{
  int *v3; // edx@1
  char *v4; // esi@2
  char *v5; // esi@2
  char *v6; // esi@2
  char *v7; // esi@2
  char *v8; // esi@2
  char *v9; // esi@2
  char *v10; // esi@2
  char *v11; // esi@2
  char *v12; // ecx@2

  v3 = (int *)*addr;
  if ( size < 0x24 )
    return 0;
  this->_base_armor = *v3;
  v4 = (char *)*addr + 4;
  *addr = v4;
  this->_armor_vs_slash = *(_DWORD *)v4;
  v5 = (char *)*addr + 4;
  *addr = v5;
  this->_armor_vs_pierce = *(_DWORD *)v5;
  v6 = (char *)*addr + 4;
  *addr = v6;
  this->_armor_vs_bludgeon = *(_DWORD *)v6;
  v7 = (char *)*addr + 4;
  *addr = v7;
  this->_armor_vs_cold = *(_DWORD *)v7;
  v8 = (char *)*addr + 4;
  *addr = v8;
  this->_armor_vs_fire = *(_DWORD *)v8;
  v9 = (char *)*addr + 4;
  *addr = v9;
  this->_armor_vs_acid = *(_DWORD *)v9;
  v10 = (char *)*addr + 4;
  *addr = v10;
  this->_armor_vs_electric = *(_DWORD *)v10;
  v11 = (char *)*addr + 4;
  *addr = v11;
  this->_armor_vs_nether = *(_DWORD *)v11;
  v12 = (char *)*addr + 4;
  *addr = v12;
  if ( size < v12 - (char *)v3 )
  {
    *addr = v3;
    return 0;
  }
  return 1;
}

