/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AllegianceData
   Object     : AC\acallegiance\AllegianceData.obj
   Functions  : 12
   Addresses  : 005B6530 - 005B6950 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B6530) --------------------------------------------------------  // acclient.c:481153
int __thiscall AllegianceData::GetTitle(AllegianceData *this, AC1Legacy::PStringBase<char> *title)
{
  return AllegianceSystem::GetTitle(this->_rank, this->_hg, this->_gender, title);
}

//----- (005B6550) --------------------------------------------------------  // acclient.c:481159
unsigned int __thiscall AllegianceData::IsLoggedIn(AllegianceData *this)
{
  return this->_bitfield & 1;
}

//----- (005B6560) --------------------------------------------------------  // acclient.c:481165
void __thiscall AllegianceData::SetMayPassupExperience(AllegianceData *this, int bMayPassupExperience)
{
  unsigned int v2; // eax@1

  v2 = this->_bitfield;
  if ( bMayPassupExperience )
    this->_bitfield = v2 | 0x10;
  else
    this->_bitfield = v2 & 0xFFFFFFEF;
}

//----- (005B6580) --------------------------------------------------------  // acclient.c:481177
void __thiscall AllegianceData::AllegianceData(AllegianceData *this)
{
  AllegianceData *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&AllegianceData::vftable;
  this->_id = 0;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v1->_gender = 0;
  v1->_hg = 0;
  v1->_rank = 0;
  v1->_level = 0;
  v1->_bitfield = 0;
  v1->_cp_tithed = 0;
  v1->_cp_cached = 0;
  v1->_loyalty = 0;
  v1->_leadership = 0;
  v1->_time_online = 0;
  v1->_allegiance_age = 0;
}
// 7E6CF0: using guessed type int (__thiscall *AllegianceData::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005B65D0) --------------------------------------------------------  // acclient.c:481204
void __thiscall AllegianceData::~AllegianceData(AllegianceData *this)
{
  AllegianceData *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // edi@1

  v1 = this;
  v2 = this->_name.m_buffer;
  this->vfptr = (PackObjVtbl *)&AllegianceData::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E6CF0: using guessed type int (__thiscall *AllegianceData::vftable)(void *, char);

//----- (005B6600) --------------------------------------------------------  // acclient.c:481220
AllegianceData *__thiscall AllegianceData::vector_deleting_destructor(AllegianceData *this, unsigned int a2)
{
  AllegianceData *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1

  v2 = this;
  v3 = this->_name.m_buffer;
  this->vfptr = (PackObjVtbl *)&AllegianceData::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E6CF0: using guessed type int (__thiscall *AllegianceData::vftable)(void *, char);

//----- (005B6650) --------------------------------------------------------  // acclient.c:481239
int __thiscall AllegianceData::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebx@2
  int v4; // eax@6

  v2 = this;
  if ( this != a2 )
  {
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
    v3 = *(_DWORD *)(this + 8);
    if ( v3 != *(_DWORD *)(a2 + 8) )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      v4 = *(_DWORD *)(a2 + 8);
      *(_DWORD *)(v2 + 8) = v4;
      InterlockedIncrement((volatile LONG *)(v4 + 4));
    }
    *(_DWORD *)(v2 + 36) = *(_DWORD *)(a2 + 36);
    *(_DWORD *)(v2 + 32) = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(v2 + 12) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(v2 + 20) = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(v2 + 24) = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(v2 + 28) = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(v2 + 40) = *(_DWORD *)(a2 + 40);
    *(_DWORD *)(v2 + 44) = *(_DWORD *)(a2 + 44);
    *(_DWORD *)(v2 + 48) = *(_DWORD *)(a2 + 48);
    *(_DWORD *)(v2 + 52) = *(_DWORD *)(a2 + 52);
  }
  return v2;
}

//----- (005B66F0) --------------------------------------------------------  // acclient.c:481274
int __thiscall AllegianceData::GetPackSize(AllegianceData *this)
{
  void *dummy; // [sp+0h] [bp-4h]@1

  dummy = 0;
  return AC1Legacy::PStringBase<char>::Pack(&this->_name, &dummy, 0) + 36;
}

//----- (005B6710) --------------------------------------------------------  // acclient.c:481283
unsigned int __thiscall AllegianceData::Pack(AllegianceData *this, void **addr, unsigned int size)
{
  AllegianceData *v3; // esi@1
  unsigned int v4; // edi@1
  char *v5; // edx@2
  char *v6; // ecx@2
  char *v7; // edx@2
  char *v8; // ecx@2
  char *v9; // edx@2
  char *v10; // ecx@2
  char *v11; // edx@2
  char *v12; // ecx@2
  char *v13; // edx@2
  char *v14; // ecx@2
  char *v15; // edx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  v3->_bitfield |= 0xCu;
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->_id;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->_cp_cached;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->_cp_tithed;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->_bitfield;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *v8 = LOBYTE(v3->_gender);
    v9 = (char *)*addr + 1;
    *addr = v9;
    *v9 = LOBYTE(v3->_hg);
    v10 = (char *)*addr + 1;
    *addr = v10;
    *(_WORD *)v10 = LOWORD(v3->_rank);
    v11 = (char *)*addr + 2;
    *addr = v11;
    *(_DWORD *)v11 = v3->_level;
    v12 = (char *)*addr + 4;
    *addr = v12;
    *(_WORD *)v12 = LOWORD(v3->_loyalty);
    v13 = (char *)*addr + 2;
    *addr = v13;
    *(_WORD *)v13 = LOWORD(v3->_leadership);
    v14 = (char *)*addr + 2;
    *addr = v14;
    *(_DWORD *)v14 = v3->_time_online;
    v15 = (char *)*addr + 4;
    *addr = v15;
    *(_DWORD *)v15 = v3->_allegiance_age;
    *addr = (char *)*addr + 4;
    AC1Legacy::PStringBase<char>::Pack(&v3->_name, addr, size);
  }
  return v4;
}

//----- (005B67F0) --------------------------------------------------------  // acclient.c:481345
void __thiscall AllegianceData::AllegianceData(AllegianceData *this, AllegianceData *rhs)
{
  int v2; // esi@1
  volatile LONG *v3; // ST00_4@1

  v2 = (int)this;
  this->vfptr = (PackObjVtbl *)&AllegianceData::vftable;
  this->_id = 0;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  *(_DWORD *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 16) = 0;
  *(_DWORD *)(v2 + 20) = 0;
  *(_DWORD *)(v2 + 24) = 0;
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 32) = 0;
  *(_DWORD *)(v2 + 36) = 0;
  *(_DWORD *)(v2 + 40) = 0;
  *(_DWORD *)(v2 + 44) = 0;
  *(_DWORD *)(v2 + 48) = 0;
  *(_DWORD *)(v2 + 52) = 0;
  AllegianceData::operator=(v2, (int)rhs);
}
// 7E6CF0: using guessed type int (__thiscall *AllegianceData::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005B6850) --------------------------------------------------------  // acclient.c:481373
int __thiscall AllegianceData::UnPack(AllegianceData *this, void **addr, unsigned int size)
{
  AllegianceData *v3; // edi@1
  int result; // eax@2
  void **v5; // esi@3
  char *v6; // edx@3
  char *v7; // ecx@3
  char *v8; // eax@3
  char *v9; // edx@3
  unsigned int v10; // eax@3
  unsigned __int16 v11; // cx@6
  unsigned __int16 v12; // cx@6
  char v13; // al@6
  bool v14; // zf@6
  void *v15; // eax@6
  double v16; // st7@7
  char *v17; // ecx@8

  v3 = this;
  if ( size >= 0x20 )
  {
    v5 = addr;
    this->_id = *(_DWORD *)*addr;
    v6 = (char *)*addr + 4;
    *addr = v6;
    this->_cp_cached = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    v3->_cp_tithed = *(_DWORD *)v7;
    v8 = (char *)*addr + 4;
    *addr = v8;
    v3->_bitfield = *(_DWORD *)v8;
    v9 = (char *)*addr + 4;
    *addr = v9;
    LOBYTE(v7) = *v9;
    *addr = v9 + 1;
    v3->_gender = (unsigned __int8)v7;
    LOBYTE(v7) = *(_BYTE *)*addr;
    *v5 = (char *)*v5 + 1;
    v3->_hg = (unsigned __int8)v7;
    LOWORD(v7) = *(_WORD *)*addr;
    *v5 = (char *)*v5 + 2;
    v10 = v3->_bitfield;
    v3->_rank = (unsigned __int16)v7;
    if ( v10 & 8 )
    {
      v3->_level = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
    }
    else
    {
      v3->_bitfield = v10 | 0x10;
    }
    v11 = *(_WORD *)*addr;
    *addr = (char *)*addr + 2;
    v3->_loyalty = v11;
    v12 = *(_WORD *)*addr;
    *addr = (char *)*addr + 2;
    v13 = LOBYTE(v3->_bitfield);
    v3->_leadership = v12;
    v14 = (v13 & 4) == 0;
    v15 = *addr;
    if ( v14 )
    {
      v16 = *(double *)v15;
      *addr = (char *)v15 + 8;
      *(_QWORD *)&v3->_time_online = (unsigned int)(unsigned __int64)v16;
    }
    else
    {
      v3->_time_online = *(_DWORD *)v15;
      v17 = (char *)*addr + 4;
      *addr = v17;
      v3->_allegiance_age = *(_DWORD *)v17;
      *addr = (char *)*addr + 4;
    }
    AC1Legacy::PStringBase<char>::UnPack(&v3->_name, addr, size);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B6950) --------------------------------------------------------  // acclient.c:481460
int __thiscall AllegianceData::GetFullName(AllegianceData *this, AC1Legacy::PStringBase<char> *name)
{
  AC1Legacy::PStringBase<char> *v2; // ebx@1
  AllegianceData *v3; // edi@1
  AC1Legacy::PStringBase<char> v4; // esi@2
  AC1Legacy::PSRefBuffer<char> *v5; // edi@6
  int result; // eax@7
  AC1Legacy::PStringBase<char> *v7; // esi@8
  AC1Legacy::PSRefBuffer<char> *v8; // eax@8
  AC1Legacy::PSRefBuffer<char> *v9; // eax@13
  unsigned int v10; // ecx@13

  v2 = name;
  v3 = this;
  if ( AllegianceSystem::GetTitle(this->_rank, this->_hg, this->_gender, name) )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, " ");
    v7 = name;
    v8 = name[2].m_buffer;
    if ( v8 != (AC1Legacy::PSRefBuffer<char> *)1
      && name != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v2, (const char *)&name[5], (unsigned int)&v8[-1].m_data[3]);
    if ( !InterlockedDecrement((volatile LONG *)&v7[1]) )
      ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v7->m_buffer->vfptr)(v7, 1);
    v9 = v3->_name.m_buffer;
    v10 = v9->m_len;
    if ( v10 != 1 && v9 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v2, v9->m_data, v10 - 1);
    result = 1;
  }
  else
  {
    v4.m_buffer = v2->m_buffer;
    if ( v2->m_buffer != v3->_name.m_buffer )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v4.m_buffer->m_cRef) )
      {
        if ( v4.m_buffer )
          v4.m_buffer->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4.m_buffer, 1u);
      }
      v5 = v3->_name.m_buffer;
      v2->m_buffer = v5;
      InterlockedIncrement((volatile LONG *)&v5->m_cRef);
    }
    result = 0;
  }
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

