/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SkillBase
   Object     : AC\acqualities\SkillBase.obj
   Functions  : 3
   Addresses  : 005CB190 - 0070FFE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005CB190) --------------------------------------------------------  // acclient.c:502726
int __thiscall SkillBase::Pack(SkillBase *this, void **addr, unsigned int size)
{
  SkillBase *v3; // edi@1
  char *v4; // ebp@1
  int v5; // ebx@1
  int v6; // ebx@1
  int result; // eax@1
  void **v8; // esi@2
  char *v9; // eax@2
  char *v10; // edx@2
  char *v11; // ecx@2
  char *v12; // eax@2
  char *v13; // edx@2
  char *v14; // edx@2
  char *v15; // ecx@2
  unsigned int retVal; // [sp+10h] [bp-4h]@1

  v3 = this;
  retVal = 0;
  v4 = (char *)&this->_formula;
  v5 = AC1Legacy::PStringBase<char>::Pack(&this->_description, (void **)&retVal, 0);
  v6 = AC1Legacy::PStringBase<char>::Pack(&v3->_name, (void **)&retVal, 0) + v5;
  result = v6
         + (*(int (__thiscall **)(int, unsigned int *, _DWORD))(*(_DWORD *)v4 + 12))(&v3->_formula, &retVal, 0)
         + 48;
  retVal = result;
  if ( size >= result )
  {
    v8 = addr;
    AC1Legacy::PStringBase<char>::Pack(&v3->_description, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->_name, addr, size);
    *(_DWORD *)*addr = v3->_iconID.id;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = v3->_trained_cost;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(_DWORD *)v10 = v3->_specialized_cost;
    v11 = (char *)*addr + 4;
    *addr = v11;
    *(_DWORD *)v11 = v3->_category;
    v12 = (char *)*addr + 4;
    *addr = v12;
    *(_DWORD *)v12 = v3->_chargen_use;
    v13 = (char *)*addr + 4;
    *addr = v13;
    *(_DWORD *)v13 = v3->_min_level;
    *v8 = (char *)*v8 + 4;
    (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)v4 + 12))(&v3->_formula, addr, size);
    *(double *)*addr = v3->_upper_bound;
    v14 = (char *)*addr + 8;
    *addr = v14;
    *(double *)v14 = v3->_lower_bound;
    v15 = (char *)*addr + 8;
    *addr = v15;
    *(double *)v15 = v3->_learn_mod;
    *v8 = (char *)*v8 + 8;
    result = retVal;
  }
  return result;
}

//----- (005CB290) --------------------------------------------------------  // acclient.c:502789
int __thiscall SkillBase::UnPack(SkillBase *this, void **addr, unsigned int size)
{
  void **v3; // esi@1
  SkillBase *v4; // edi@1
  char *v5; // ebp@1
  int v6; // ST18_4@1
  int v7; // ST18_4@1
  int v8; // eax@1
  unsigned int v9; // ebx@1
  unsigned int v10; // ecx@2
  int v11; // eax@2
  int v12; // edx@2
  int v13; // ecx@2
  int v14; // eax@2
  void *v15; // eax@2
  int v16; // ecx@2
  int v17; // eax@2
  int v18; // eax@2
  void *start; // [sp+14h] [bp-4h]@1

  v3 = addr;
  v4 = this;
  start = *addr;
  addr = 0;
  v5 = (char *)&this->_formula;
  v6 = AC1Legacy::PStringBase<char>::Pack(&this->_description, (void **)&addr, 0);
  v7 = AC1Legacy::PStringBase<char>::Pack(&v4->_name, (void **)&addr, 0) + v6;
  v8 = (*(int (__thiscall **)(int, void ***, _DWORD))(*(_DWORD *)v5 + 12))(&v4->_formula, &addr, 0);
  v9 = size;
  if ( size < v7 + v8 + 48 )
    return 0;
  AC1Legacy::PStringBase<char>::UnPack(&v4->_description, v3, size);
  AC1Legacy::PStringBase<char>::UnPack(&v4->_name, v3, v9);
  v10 = *(_DWORD *)*v3;
  *v3 = (char *)*v3 + 4;
  v4->_iconID.id = v10;
  v4->_trained_cost = *(_DWORD *)*v3;
  v11 = (int)((char *)*v3 + 4);
  *v3 = (void *)v11;
  v4->_specialized_cost = *(_DWORD *)v11;
  v12 = (int)((char *)*v3 + 4);
  *v3 = (void *)v12;
  v4->_category = *(_DWORD *)v12;
  v13 = (int)((char *)*v3 + 4);
  *v3 = (void *)v13;
  v4->_chargen_use = *(_DWORD *)v13;
  v14 = (int)((char *)*v3 + 4);
  *v3 = (void *)v14;
  v4->_min_level = *(_DWORD *)v14;
  *v3 = (char *)*v3 + 4;
  (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)v5 + 16))(&v4->_formula, v3, v9);
  v15 = *v3;
  LODWORD(v4->_upper_bound) = *(_DWORD *)*v3;
  HIDWORD(v4->_upper_bound) = *((_DWORD *)v15 + 1);
  v16 = (int)((char *)*v3 + 8);
  *v3 = (void *)v16;
  LODWORD(v4->_lower_bound) = *(_DWORD *)v16;
  HIDWORD(v4->_lower_bound) = *(_DWORD *)(v16 + 4);
  v17 = (int)((char *)*v3 + 8);
  *v3 = (void *)v17;
  LODWORD(v4->_learn_mod) = *(_DWORD *)v17;
  HIDWORD(v4->_learn_mod) = *(_DWORD *)(v17 + 4);
  v18 = (_BYTE *)*v3 + 8 - (_BYTE *)start;
  *v3 = (char *)*v3 + 8;
  if ( v9 < v18 )
  {
    *v3 = start;
    return 0;
  }
  return 1;
}

//----- (0070FFE0) --------------------------------------------------------  // acclient.c:803265
int sub_70FFE0()
{
  return atexit(nullsub_1831);
}

