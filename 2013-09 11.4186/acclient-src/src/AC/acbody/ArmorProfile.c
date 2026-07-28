/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ArmorProfile
   Object     : AC\acbody\ArmorProfile.obj
   Functions  : 2
   Addresses  : 005D0DC0 - 005D0E40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005D0DC0) --------------------------------------------------------  // acclient.c:508846
signed int __thiscall ArmorProfile::Pack(ArmorProfile *this, void **addr, unsigned int size)
{
  char *v3; // edx@2
  char *v4; // edx@2
  char *v5; // edx@2
  char *v6; // edx@2
  char *v7; // edx@2
  char *v8; // edx@2
  char *v9; // edx@2

  if ( size >= 0x20 )
  {
    *(float *)*addr = this->mod_vs_slash;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(float *)v3 = this->mod_vs_pierce;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(float *)v4 = this->mod_vs_bludgeon;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = this->mod_vs_cold;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(float *)v6 = this->mod_vs_fire;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(float *)v7 = this->mod_vs_acid;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(float *)v8 = this->mod_vs_nether;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(float *)v9 = this->mod_vs_electric;
    *addr = (char *)*addr + 4;
  }
  return 32;
}

//----- (005D0E40) --------------------------------------------------------  // acclient.c:508886
int __thiscall ArmorProfile::UnPack(ArmorProfile *this, void **addr, unsigned int size)
{
  int result; // eax@2
  char *v4; // edx@3
  char *v5; // edx@3
  char *v6; // edx@3
  char *v7; // edx@3
  char *v8; // edx@3
  char *v9; // edx@3
  char *v10; // edx@3

  if ( size >= 0x20 )
  {
    LODWORD(this->mod_vs_slash) = *(_DWORD *)*addr;
    v4 = (char *)*addr + 4;
    *addr = v4;
    LODWORD(this->mod_vs_pierce) = *(_DWORD *)v4;
    v5 = (char *)*addr + 4;
    *addr = v5;
    LODWORD(this->mod_vs_bludgeon) = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    LODWORD(this->mod_vs_cold) = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    LODWORD(this->mod_vs_fire) = *(_DWORD *)v7;
    v8 = (char *)*addr + 4;
    *addr = v8;
    LODWORD(this->mod_vs_acid) = *(_DWORD *)v8;
    v9 = (char *)*addr + 4;
    *addr = v9;
    LODWORD(this->mod_vs_nether) = *(_DWORD *)v9;
    v10 = (char *)*addr + 4;
    *addr = v10;
    LODWORD(this->mod_vs_electric) = *(_DWORD *)v10;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

