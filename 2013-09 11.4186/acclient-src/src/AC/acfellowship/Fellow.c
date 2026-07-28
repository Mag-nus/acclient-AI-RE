/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Fellow
   Object     : AC\acfellowship\Fellow.obj
   Functions  : 10
   Addresses  : 005B98A0 - 0070E830 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B98A0) --------------------------------------------------------  // acclient.c:484389
void __thiscall Fellow::Fellow(Fellow *this)
{
  Fellow *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&Fellow::vftable;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v1->_level = 0;
  v1->_cp_cache = 0;
  v1->_lum_cache = 0;
  v1->_share_loot = 0;
  v1->_max_health = 0;
  v1->_max_stamina = 0;
  v1->_max_mana = 0;
  v1->_current_health = 0;
  v1->_current_stamina = 0;
  v1->_current_mana = 0;
}
// 7A515C: using guessed type int (__thiscall *Fellow::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005B98F0) --------------------------------------------------------  // acclient.c:484414
void __thiscall Fellow::Fellow(Fellow *this, Fellow *rhs)
{
  Fellow *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // eax@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&Fellow::vftable;
  v3 = rhs->_name.m_buffer;
  this->_name.m_buffer = v3;
  InterlockedIncrement((volatile LONG *)&v3->m_cRef);
  v2->_level = rhs->_level;
  v2->_cp_cache = rhs->_cp_cache;
  v2->_lum_cache = rhs->_lum_cache;
  v2->_share_loot = rhs->_share_loot;
  v2->_max_health = rhs->_max_health;
  v2->_max_stamina = rhs->_max_stamina;
  v2->_max_mana = rhs->_max_mana;
  v2->_current_health = rhs->_current_health;
  v2->_current_stamina = rhs->_current_stamina;
  v2->_current_mana = rhs->_current_mana;
}
// 7A515C: using guessed type int (__thiscall *Fellow::vftable)(void *, char);

//----- (005B9960) --------------------------------------------------------  // acclient.c:484438
int __thiscall Fellow::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebx@2
  int v4; // eax@6

  v2 = this;
  if ( this != a2 )
  {
    v3 = *(_DWORD *)(this + 4);
    if ( v3 != *(_DWORD *)(a2 + 4) )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      v4 = *(_DWORD *)(a2 + 4);
      *(_DWORD *)(v2 + 4) = v4;
      InterlockedIncrement((volatile LONG *)(v4 + 4));
    }
    *(_DWORD *)(v2 + 8) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(v2 + 12) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(v2 + 20) = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(v2 + 24) = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(v2 + 28) = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(v2 + 32) = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(v2 + 36) = *(_DWORD *)(a2 + 36);
    *(_DWORD *)(v2 + 40) = *(_DWORD *)(a2 + 40);
    *(_DWORD *)(v2 + 44) = *(_DWORD *)(a2 + 44);
  }
  return v2;
}

//----- (005B99F0) --------------------------------------------------------  // acclient.c:484471
int __thiscall Fellow::GetPackSize(Fellow *this)
{
  void *dummy; // [sp+0h] [bp-4h]@1

  dummy = 0;
  return AC1Legacy::PStringBase<char>::Pack(&this->_name, &dummy, 0) + 40;
}

//----- (005B9A10) --------------------------------------------------------  // acclient.c:484480
unsigned int __thiscall Fellow::Pack(Fellow *this, void **addr, unsigned int size)
{
  Fellow *v3; // esi@1
  unsigned int v4; // edi@1
  char *v5; // ebx@2
  char *v6; // ecx@2
  char *v7; // ebx@2
  char *v8; // ecx@2
  char *v9; // ebx@2
  char *v10; // ecx@2
  char *v11; // ebx@2
  char *v12; // ecx@2
  char *v13; // ebx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->_cp_cache;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->_lum_cache;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->_level;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->_max_health;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = v3->_max_stamina;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = v3->_max_mana;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(_DWORD *)v10 = v3->_current_health;
    v11 = (char *)*addr + 4;
    *addr = v11;
    *(_DWORD *)v11 = v3->_current_stamina;
    v12 = (char *)*addr + 4;
    *addr = v12;
    *(_DWORD *)v12 = v3->_current_mana;
    v13 = (char *)*addr + 4;
    *addr = v13;
    *(_DWORD *)v13 = v3->_share_loot;
    *addr = (char *)*addr + 4;
    AC1Legacy::PStringBase<char>::Pack(&v3->_name, addr, size);
  }
  return v4;
}

//----- (005B9AD0) --------------------------------------------------------  // acclient.c:484533
int __thiscall Fellow::UnPack(Fellow *this, void **addr, unsigned int size)
{
  int result; // eax@2
  void **v4; // eax@3
  unsigned int v5; // esi@3
  unsigned int v6; // esi@3
  unsigned int v7; // esi@3
  char *v8; // edx@3
  char *v9; // esi@3
  char *v10; // edx@3
  char *v11; // esi@3
  char *v12; // edx@3
  char *v13; // esi@3

  if ( size >= 0x28 )
  {
    v4 = addr;
    v5 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    this->_cp_cache = v5;
    v6 = *(_DWORD *)*addr;
    *v4 = (char *)*v4 + 4;
    this->_lum_cache = v6;
    v7 = *(_DWORD *)*addr;
    *v4 = (char *)*v4 + 4;
    this->_level = v7;
    this->_max_health = *(_DWORD *)*addr;
    v8 = (char *)*addr + 4;
    *addr = v8;
    this->_max_stamina = *(_DWORD *)v8;
    v9 = (char *)*addr + 4;
    *addr = v9;
    this->_max_mana = *(_DWORD *)v9;
    v10 = (char *)*addr + 4;
    *addr = v10;
    this->_current_health = *(_DWORD *)v10;
    v11 = (char *)*addr + 4;
    *addr = v11;
    this->_current_stamina = *(_DWORD *)v11;
    v12 = (char *)*addr + 4;
    *addr = v12;
    this->_current_mana = *(_DWORD *)v12;
    v13 = (char *)*addr + 4;
    *addr = v13;
    this->_share_loot = *(_DWORD *)v13;
    *addr = (char *)*addr + 4;
    result = AC1Legacy::PStringBase<char>::UnPack(&this->_name, addr, size);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0070E7D0) --------------------------------------------------------  // acclient.c:801489
void sub_70E7D0()
{
  flt_8EF454 = 1000.0 + 1.0;
}

//----- (0070E7F0) --------------------------------------------------------  // acclient.c:801495
void sub_70E7F0()
{
  flt_8EF458 = 24.0 * 8.0;
}

//----- (0070E810) --------------------------------------------------------  // acclient.c:801501
void sub_70E810()
{
  flt_8EF45C = 24.0 * 0.5;
}

//----- (0070E830) --------------------------------------------------------  // acclient.c:801507
int sub_70E830()
{
  return atexit(nullsub_1555);
}

