/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SkillFormula
   Object     : AC\acqualities\SkillFormula.obj
   Functions  : 2
   Addresses  : 005CA870 - 005CA8D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005CA870) --------------------------------------------------------  // acclient.c:502021
signed int __thiscall SkillFormula::Pack(SkillFormula *this, void **addr, unsigned int size)
{
  char *v3; // edx@2
  char *v4; // esi@2
  char *v5; // edx@2
  char *v6; // esi@2
  char *v7; // edx@2

  if ( size >= 0x18 )
  {
    *(_DWORD *)*addr = this->_w;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = this->_x;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_DWORD *)v4 = this->_y;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = this->_z;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = this->_attr1;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = this->_attr2;
    *addr = (char *)*addr + 4;
  }
  return 24;
}

//----- (005CA8D0) --------------------------------------------------------  // acclient.c:502053
int __thiscall SkillFormula::UnPack(SkillFormula *this, void **addr, unsigned int size)
{
  unsigned int *v3; // edx@1
  int result; // eax@2
  char *v5; // esi@3
  char *v6; // esi@3
  char *v7; // esi@3
  char *v8; // esi@3
  char *v9; // esi@3
  char *v10; // esi@3

  v3 = (unsigned int *)*addr;
  if ( size >= 0x18 )
  {
    this->_w = *v3;
    v5 = (char *)*addr + 4;
    *addr = v5;
    this->_x = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    this->_y = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    this->_z = *(_DWORD *)v7;
    v8 = (char *)*addr + 4;
    *addr = v8;
    this->_attr1 = *(_DWORD *)v8;
    v9 = (char *)*addr + 4;
    *addr = v9;
    this->_attr2 = *(_DWORD *)v9;
    v10 = (char *)*addr + 4;
    *addr = v10;
    result = v10 - (char *)v3 == 24;
  }
  else
  {
    result = 0;
  }
  return result;
}

