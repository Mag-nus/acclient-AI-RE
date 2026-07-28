/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SquelchPackage
   Object     : PORTAL\squelch\SquelchPackage.obj
   Functions  : 35
   Addresses  : 006B0C20 - 006B1D50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B0C20) --------------------------------------------------------  // acclient.c:713962
int __thiscall SquelchInfo::IsEmpty(SquelchInfo *this)
{
  unsigned int v1; // esi@1
  AC1Legacy::vlong *v2; // edi@1

  v1 = 0;
  v2 = &this->_squelch_msgs;
  while ( !AC1Legacy::vlong::bit(v2, v1) )
  {
    ++v1;
    if ( v1 >= 0x80 )
      return 1;
  }
  return 0;
}

//----- (006B0C50) --------------------------------------------------------  // acclient.c:713979
int __thiscall SquelchInfo::IsSquelched(SquelchInfo *this, unsigned int msg_type)
{
  int result; // eax@2
  unsigned int v3; // esi@3
  AC1Legacy::vlong *v4; // edi@3

  if ( msg_type == 1 )
  {
    v3 = 0;
    v4 = &this->_squelch_msgs;
    while ( AC1Legacy::vlong::bit(v4, v3) )
    {
      ++v3;
      if ( v3 >= 0x80 )
        return 1;
    }
    result = 0;
  }
  else
  {
    result = AC1Legacy::vlong::bit(&this->_squelch_msgs, msg_type) != 0;
  }
  return result;
}

//----- (006B0CA0) --------------------------------------------------------  // acclient.c:714005
unsigned int __thiscall SquelchDB::Pack(SquelchDB *this, void **addr, unsigned int size)
{
  PackObjVtbl *v3; // eax@1
  char *v4; // ebx@1
  char *v5; // edi@1
  char *v6; // ebp@1
  int v7; // esi@1
  int v8; // esi@1
  unsigned int v9; // esi@1
  int v11; // [sp+1Ch] [bp-4h]@1

  v3 = this->_character_hash.vfptr;
  v4 = (char *)&this->_character_hash;
  v5 = (char *)&this->_global_squelch_info;
  v6 = (char *)&this->_account_hash;
  v11 = 0;
  v7 = ((int (__thiscall *)(PackableHashTable<unsigned long,SquelchInfo> *, int *, _DWORD))v3->Pack)(
         &this->_character_hash,
         &v11,
         0);
  v8 = (*(int (__thiscall **)(char *, int *, _DWORD))(*(_DWORD *)v6 + 12))(v6, &v11, 0) + v7;
  v9 = (*(int (__thiscall **)(char *, int *, _DWORD))(*(_DWORD *)v5 + 12))(v5, &v11, 0) + v8;
  if ( size >= v9 )
  {
    (*(void (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v6 + 12))(v6, addr, size);
    (*(void (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v4 + 12))(v4, addr, size);
    (*(void (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v5 + 12))(v5, addr, size);
  }
  return v9;
}

//----- (006B0D30) --------------------------------------------------------  // acclient.c:714037
int __thiscall SquelchDB::IsPlayerSquelched(SquelchDB *this, unsigned int player_iid, unsigned int msg_type)
{
  unsigned int v3; // esi@1
  PackableHashData<unsigned long,SquelchInfo> **v4; // ecx@2
  PackableHashData<unsigned long,SquelchInfo> *v5; // edx@3
  int result; // eax@6

  v3 = this->_character_hash._table_size;
  if ( !v3 )
    goto LABEL_12;
  v4 = this->_character_hash._buckets;
  if ( !v4 )
    goto LABEL_12;
  v5 = v4[player_iid % v3];
  if ( !v5 )
    goto LABEL_12;
  while ( player_iid != v5->_key )
  {
    v5 = v5->_next;
    if ( !v5 )
      return 0;
  }
  if ( v5 != (PackableHashData<unsigned long,SquelchInfo> *)-4 )
    result = SquelchInfo::IsSquelched(&v5->_data, msg_type);
  else
LABEL_12:
    result = 0;
  return result;
}

//----- (006B0D80) --------------------------------------------------------  // acclient.c:714068
signed int __thiscall PackableHashTable<unsigned long,SquelchInfo>::Pack(PackableHashTable<unsigned long,SquelchInfo> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,SquelchInfo> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<unsigned long,SquelchInfo> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<unsigned long,SquelchInfo>::pack_size(this);
  v5 = size;
  retVal = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    *addr = (char *)*addr + 4;
    v6 = 0;
    sizea = 0;
    if ( v3->_table_size )
    {
      do
      {
        v7 = v3->_buckets[v6];
        if ( v7 )
        {
          do
          {
            if ( v5 >= 4 )
            {
              *(_DWORD *)*addr = v7->_key;
              *addr = (char *)*addr + 4;
            }
            ((void (__thiscall *)(int, void **, unsigned int))v7->_data.vfptr->Pack)(&v7->_data, addr, v5);
            v7 = v7->_next;
          }
          while ( v7 );
          result = retVal;
          v6 = sizea;
        }
        ++v6;
        sizea = v6;
      }
      while ( v6 < v3->_table_size );
    }
  }
  return result;
}

//----- (006B0E10) --------------------------------------------------------  // acclient.c:714119
signed int __thiscall PackableHashTable<unsigned long,SquelchInfo>::pack_size(PackableHashTable<unsigned long,SquelchInfo> *this)
{
  PackableHashTable<unsigned long,SquelchInfo> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<unsigned long,SquelchInfo> *i; // esi@2
  int v6; // eax@3
  void *addr; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = this->_table_size;
  v3 = 0;
  v4 = 4;
  addr = 0;
  if ( v2 )
  {
    do
    {
      for ( i = v1->_buckets[v3]; i; v4 += v6 + 4 )
      {
        v6 = ((int (__thiscall *)(int, void **, _DWORD))i->_data.vfptr->Pack)(&i->_data, &addr, 0);
        i = i->_next;
      }
      ++v3;
    }
    while ( v3 < v1->_table_size );
  }
  return v4;
}

//----- (006B0E70) --------------------------------------------------------  // acclient.c:714151
int __thiscall SquelchInfo::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebx@2
  int v4; // edi@6

  v2 = this;
  if ( a2 != this )
  {
    AC1Legacy::vlong::operator=((AC1Legacy::vlong *)(this + 4), (AC1Legacy::vlong *)(a2 + 4));
    *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
    v3 = *(_DWORD *)(v2 + 20);
    if ( v3 != *(_DWORD *)(a2 + 20) )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      v4 = *(_DWORD *)(a2 + 20);
      *(_DWORD *)(v2 + 20) = v4;
      InterlockedIncrement((volatile LONG *)(v4 + 4));
    }
  }
  return v2;
}

//----- (006B0ED0) --------------------------------------------------------  // acclient.c:714176
void __thiscall SquelchInfo::Clear(SquelchInfo *this)
{
  SquelchInfo *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // edi@1
  volatile LONG *v3; // ST00_4@5
  AC1Legacy::vlong x; // [sp+8h] [bp-Ch]@1

  v1 = this;
  AC1Legacy::vlong::vlong(&x, 0);
  AC1Legacy::vlong::operator=(&v1->_squelch_msgs, &x);
  AC1Legacy::vlong::~vlong(&x);
  v2 = v1->_name.m_buffer;
  if ( v2 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
      v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
    v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
    v1->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement(v3);
  }
  v1->_is_zone_squelch = 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006B0F40) --------------------------------------------------------  // acclient.c:714201
unsigned int *__thiscall PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::lookup(PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *this, AC1Legacy::PStringBase<char> *key)
{
  PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *v2; // edi@1
  unsigned int v3; // ebp@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@3
  unsigned int v5; // eax@3
  PackableHashData<AC1Legacy::PStringBase<char>,unsigned long> *v6; // edi@5
  unsigned int *result; // eax@8

  v2 = this;
  v3 = this->_table_size;
  if ( !v3 || !this->_buckets )
    goto LABEL_8;
  v4 = key->m_buffer;
  v5 = key->m_buffer->m_hash;
  if ( v5 == -1 )
  {
    v5 = AC1Legacy::PStringBase<char>::compute_hash(key);
    v4->m_hash = v5;
  }
  v6 = v2->_buckets[v5 % v3];
  if ( v6 )
  {
    while ( strcmp(key->m_buffer->m_data, v6->_key.m_buffer->m_data) )
    {
      v6 = v6->_next;
      if ( !v6 )
        goto LABEL_8;
    }
    result = &v6->_data;
  }
  else
  {
LABEL_8:
    result = 0;
  }
  return result;
}

//----- (006B0FE0) --------------------------------------------------------  // acclient.c:714241
void __thiscall PackableHashData<AC1Legacy::PStringBase<char>,unsigned long>::PackableHashData<AC1Legacy::PStringBase<char>,unsigned long>(PackableHashData<AC1Legacy::PStringBase<char>,unsigned long> *this, AC1Legacy::PStringBase<char> *key, const unsigned int *data, int highbound)
{
  AC1Legacy::PSRefBuffer<char> *v4; // eax@1
  PackableHashData<AC1Legacy::PStringBase<char>,unsigned long> *v5; // esi@1
  AC1Legacy::PSRefBuffer<char> *v6; // ebx@1
  unsigned int v7; // eax@1

  v4 = key->m_buffer;
  v5 = this;
  this->_key.m_buffer = key->m_buffer;
  InterlockedIncrement((volatile LONG *)&v4->m_cRef);
  v5->_data = *data;
  v5->_next = 0;
  v6 = key->m_buffer;
  v7 = key->m_buffer->m_hash;
  if ( v7 == -1 )
  {
    v7 = AC1Legacy::PStringBase<char>::compute_hash(key);
    v6->m_hash = v7;
  }
  v5->_hashVal = v7 % highbound;
}

//----- (006B1030) --------------------------------------------------------  // acclient.c:714265
void __thiscall SquelchInfo::SquelchInfo(SquelchInfo *this)
{
  SquelchInfo *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&SquelchInfo::vftable;
  AC1Legacy::vlong::vlong(&this->_squelch_msgs, 0);
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  SquelchInfo::Clear(v1);
}
// 7E2ED8: using guessed type int (__thiscall *SquelchInfo::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006B1070) --------------------------------------------------------  // acclient.c:714282
void __thiscall SquelchInfo::SquelchInfo(SquelchInfo *this, AC1Legacy::PStringBase<char> *name, unsigned int msg_type)
{
  SquelchInfo *v3; // esi@1
  AC1Legacy::vlong *v4; // ebx@1
  volatile LONG *v5; // ST00_4@1
  AC1Legacy::PSRefBuffer<char> *v6; // edi@1
  AC1Legacy::PSRefBuffer<char> *v7; // eax@5
  unsigned int v8; // edi@8

  v3 = this;
  v4 = &this->_squelch_msgs;
  this->vfptr = (PackObjVtbl *)&SquelchInfo::vftable;
  AC1Legacy::vlong::vlong(&this->_squelch_msgs, 0);
  v5 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v3->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v5);
  SquelchInfo::Clear(v3);
  v6 = v3->_name.m_buffer;
  if ( v6 != name->m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    v7 = name->m_buffer;
    v3->_name.m_buffer = name->m_buffer;
    InterlockedIncrement((volatile LONG *)&v7->m_cRef);
  }
  if ( msg_type == 1 )
  {
    v8 = 0;
    do
      AC1Legacy::vlong::setbit(v4, v8++);
    while ( v8 < 0x80 );
  }
  else
  {
    AC1Legacy::vlong::setbit(v4, msg_type);
  }
}
// 7E2ED8: using guessed type int (__thiscall *SquelchInfo::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006B1110) --------------------------------------------------------  // acclient.c:714324
void __thiscall SquelchInfo::~SquelchInfo(SquelchInfo *this)
{
  SquelchInfo *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // edi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&SquelchInfo::vftable;
  SquelchInfo::Clear(this);
  v2 = v1->_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  AC1Legacy::vlong::~vlong(&v1->_squelch_msgs);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E2ED8: using guessed type int (__thiscall *SquelchInfo::vftable)(void *, char);

//----- (006B1150) --------------------------------------------------------  // acclient.c:714342
unsigned int __thiscall SquelchInfo::Pack(SquelchInfo *this, void **addr, unsigned int size)
{
  SquelchInfo *v3; // ebx@1
  char *v4; // edi@1
  int v5; // esi@1
  unsigned int v6; // ebp@1
  void *v8; // [sp+10h] [bp-4h]@1

  v3 = this;
  v8 = 0;
  v4 = (char *)&this->_squelch_msgs;
  v5 = AC1Legacy::PStringBase<char>::Pack(&this->_name, &v8, 0);
  v6 = v5 + (*(int (__thiscall **)(int, void **, _DWORD))(*(_DWORD *)v4 + 12))(&v3->_squelch_msgs, &v8, 0) + 4;
  if ( size >= v6 )
  {
    (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)v4 + 12))(&v3->_squelch_msgs, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->_name, addr, size);
    *(_DWORD *)*addr = v3->_is_zone_squelch;
    *addr = (char *)*addr + 4;
  }
  return v6;
}

//----- (006B11C0) --------------------------------------------------------  // acclient.c:714366
int __thiscall SquelchInfo::UnPack(SquelchInfo *this, void **addr, unsigned int size)
{
  SquelchInfo *v3; // edi@1
  int v4; // esi@1
  int result; // eax@2
  void *v6; // [sp+10h] [bp-4h]@1

  v3 = this;
  SquelchInfo::Clear(this);
  v6 = 0;
  v4 = AC1Legacy::PStringBase<char>::Pack(&v3->_name, &v6, 0);
  if ( size >= v4
             + ((int (__thiscall *)(int, void **, _DWORD))v3->_squelch_msgs.vfptr->Pack)(&v3->_squelch_msgs, &v6, 0)
             + 4 )
  {
    ((void (__thiscall *)(int, void **, unsigned int))v3->_squelch_msgs.vfptr->UnPack)(&v3->_squelch_msgs, addr, size);
    AC1Legacy::PStringBase<char>::UnPack(&v3->_name, addr, size);
    v3->_is_zone_squelch = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006B1250) --------------------------------------------------------  // acclient.c:714395
void __thiscall PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::EmptyContents(PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *this)
{
  PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *v1; // ebp@1
  unsigned int v2; // eax@2
  void *v3; // esi@3
  int v4; // edi@4
  void *v5; // ebx@4
  unsigned int i; // [sp+4h] [bp-4h]@2

  v1 = this;
  if ( this->_buckets )
  {
    v2 = 0;
    i = 0;
    if ( this->_table_size )
    {
      do
      {
        v3 = v1->_buckets[v2];
        if ( v3 )
        {
          do
          {
            v4 = *(_DWORD *)v3;
            v5 = (void *)*((_DWORD *)v3 + 2);
            if ( !InterlockedDecrement((volatile LONG *)(*(_DWORD *)v3 + 4)) && v4 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
            operator delete(v3);
            v3 = v5;
          }
          while ( v5 );
          v2 = i;
        }
        v1->_buckets[v2++] = 0;
        i = v2;
      }
      while ( v2 < v1->_table_size );
    }
  }
  v1->_currNum = 0;
}

//----- (006B12E0) --------------------------------------------------------  // acclient.c:714438
int __thiscall PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::add(PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *this, AC1Legacy::PStringBase<char> *key, const unsigned int *data)
{
  PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *v3; // esi@1
  PackableHashData<AC1Legacy::PStringBase<char>,unsigned long> *v4; // eax@2
  int v5; // eax@3
  int result; // eax@4
  int v7; // ecx@5

  v3 = this;
  if ( !PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::lookup(this, key)
    && (v4 = (PackableHashData<AC1Legacy::PStringBase<char>,unsigned long> *)operator new(0x10u)) != 0
    && (PackableHashData<AC1Legacy::PStringBase<char>,unsigned long>::PackableHashData<AC1Legacy::PStringBase<char>,unsigned long>(
          v4,
          key,
          data,
          v3->_table_size),
        v5) )
  {
    v7 = *(_DWORD *)(v5 + 12);
    *(_DWORD *)(v5 + 8) = v3->_buckets[v7];
    v3->_buckets[v7] = (PackableHashData<AC1Legacy::PStringBase<char>,unsigned long> *)v5;
    ++v3->_currNum;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006B1340) --------------------------------------------------------  // acclient.c:714470
signed int __thiscall PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::Pack(PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *this, void **addr, unsigned int size)
{
  PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<AC1Legacy::PStringBase<char>,unsigned long> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::pack_size(this);
  v5 = size;
  retVal = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    *addr = (char *)*addr + 4;
    v6 = 0;
    sizea = 0;
    if ( v3->_table_size )
    {
      do
      {
        v7 = v3->_buckets[v6];
        if ( v7 )
        {
          do
          {
            AC1Legacy::PStringBase<char>::Pack(&v7->_key, addr, v5);
            if ( v5 >= 4 )
            {
              *(_DWORD *)*addr = v7->_data;
              *addr = (char *)*addr + 4;
            }
            v7 = v7->_next;
          }
          while ( v7 );
          result = retVal;
          v6 = sizea;
        }
        ++v6;
        sizea = v6;
      }
      while ( v6 < v3->_table_size );
    }
  }
  return result;
}

//----- (006B13D0) --------------------------------------------------------  // acclient.c:714521
signed int __thiscall PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::pack_size(PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *this)
{
  PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<AC1Legacy::PStringBase<char>,unsigned long> *i; // esi@2
  int v6; // eax@3
  void *addr; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = this->_table_size;
  v3 = 0;
  v4 = 4;
  addr = 0;
  if ( v2 )
  {
    do
    {
      for ( i = v1->_buckets[v3]; i; v4 += v6 + 4 )
      {
        v6 = AC1Legacy::PStringBase<char>::Pack(&i->_key, &addr, 0);
        i = i->_next;
      }
      ++v3;
    }
    while ( v3 < v1->_table_size );
  }
  return v4;
}

//----- (006B1430) --------------------------------------------------------  // acclient.c:714553
void __thiscall PackableHashData<unsigned long,SquelchInfo>::PackableHashData<unsigned long,SquelchInfo>(PackableHashData<unsigned long,SquelchInfo> *this, const unsigned int *key, SquelchInfo *data, int highbound)
{
  PackableHashData<unsigned long,SquelchInfo> *v4; // esi@1
  AC1Legacy::PSRefBuffer<char> *v5; // edi@1

  v4 = this;
  this->_key = *key;
  this->_data.vfptr = (PackObjVtbl *)&SquelchInfo::vftable;
  AC1Legacy::vlong::vlong(&this->_data._squelch_msgs, &data->_squelch_msgs);
  v4->_data._is_zone_squelch = data->_is_zone_squelch;
  v5 = data->_name.m_buffer;
  v4->_data._name.m_buffer = v5;
  InterlockedIncrement((volatile LONG *)&v5->m_cRef);
  v4->_next = 0;
  v4->_hashVal = *key % highbound;
}
// 7E2ED8: using guessed type int (__thiscall *SquelchInfo::vftable)(void *, char);

//----- (006B1490) --------------------------------------------------------  // acclient.c:714572
int __thiscall SquelchDB::IsSquelched(SquelchDB *this, unsigned int player_iid, AC1Legacy::PStringBase<char> *account_name, unsigned int msg_type)
{
  SquelchDB *v4; // esi@1
  int result; // eax@2

  v4 = this;
  if ( SquelchInfo::IsSquelched(&this->_global_squelch_info, msg_type) )
    return 1;
  if ( msg_type == 17 )
  {
    result = 0;
  }
  else
  {
    if ( PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::lookup(&v4->_account_hash, account_name) )
      return 1;
    result = SquelchDB::IsPlayerSquelched(v4, player_iid, msg_type) != 0;
  }
  return result;
}

//----- (006B14F0) --------------------------------------------------------  // acclient.c:714594
int __thiscall PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::UnPack(PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  unsigned int v10; // ebx@5
  unsigned int v11; // ebp@5
  int v12; // eax@12
  unsigned int *v13; // ecx@12
  unsigned int size_r; // [sp+8h] [bp-10h]@12
  unsigned int tempData; // [sp+Ch] [bp-Ch]@12
  void *start_addr; // [sp+10h] [bp-8h]@3
  unsigned int blob_size; // [sp+14h] [bp-4h]@3
  void **addra; // [sp+1Ch] [bp+4h]@10

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::EmptyContents(this);
  if ( v4->_buckets )
  {
    operator delete[](v4->_buckets);
    v4->_buckets = 0;
  }
  v4->_table_size = 0;
  v7 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  v8 = v7 >> 16;
  v9 = (unsigned __int16)v7;
  v10 = v3 - 4;
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 <= 0x10000
    && v9 <= 0x10000
    && PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&size);
    addra = 0;
    if ( v11 )
    {
      while ( AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&size, v6, v10) )
      {
        size_r = v10;
        v12 = PackObj::UNPACK_TYPE((int *)&tempData, v6, &size_r);
        v13 = &size;
        if ( !v12 )
          goto LABEL_19;
        if ( !PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::add(
                v4,
                (AC1Legacy::PStringBase<char> *)&size,
                &tempData)
          && !v4->m_fThrowawayDuplicateKeysOnUnPack )
          break;
        addra = (void **)((char *)addra + 1);
        if ( (unsigned int)addra >= v11 )
          goto LABEL_16;
      }
      v13 = &size;
    }
    else
    {
LABEL_16:
      v13 = &size;
      if ( blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr )
      {
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&size);
        return 1;
      }
    }
LABEL_19:
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)v13);
  }
  return 0;
}

//----- (006B1640) --------------------------------------------------------  // acclient.c:714679
int __thiscall PackableHashTable<unsigned long,SquelchInfo>::add(PackableHashTable<unsigned long,SquelchInfo> *this, const unsigned int *key, SquelchInfo *data)
{
  PackableHashTable<unsigned long,SquelchInfo> *v3; // esi@1
  unsigned int v4; // edi@1
  PackableHashData<unsigned long,SquelchInfo> **v5; // ebx@2
  PackableHashData<unsigned long,SquelchInfo> *v6; // edx@3
  PackableHashData<unsigned long,SquelchInfo> *v7; // eax@8
  int v8; // eax@9
  int v10; // ecx@11

  v3 = this;
  v4 = this->_table_size;
  if ( v4 )
  {
    v5 = this->_buckets;
    if ( v5 )
    {
      v6 = v5[*key % v4];
      if ( v6 )
      {
        while ( *key != v6->_key )
        {
          v6 = v6->_next;
          if ( !v6 )
            goto LABEL_8;
        }
        if ( v6 != (PackableHashData<unsigned long,SquelchInfo> *)-4 )
          return 0;
      }
    }
  }
LABEL_8:
  v7 = (PackableHashData<unsigned long,SquelchInfo> *)operator new(0x24u);
  if ( !v7 )
    return 0;
  PackableHashData<unsigned long,SquelchInfo>::PackableHashData<unsigned long,SquelchInfo>(
    v7,
    key,
    data,
    v3->_table_size);
  if ( !v8 )
    return 0;
  v10 = *(_DWORD *)(v8 + 32);
  *(_DWORD *)(v8 + 28) = v3->_buckets[v10];
  v3->_buckets[v10] = (PackableHashData<unsigned long,SquelchInfo> *)v8;
  ++v3->_currNum;
  return 1;
}

//----- (006B16D0) --------------------------------------------------------  // acclient.c:714729
PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *__thiscall PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::operator=(PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *this, int a2)
{
  int v2; // esi@1
  PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *v3; // ebx@1
  unsigned int v4; // eax@4
  AC1Legacy::PStringBase<char> *v5; // edi@5
  AC1Legacy::PSRefBuffer<char> *v6; // ebp@6
  void *v7; // esi@7
  AC1Legacy::PSRefBuffer<char> *v8; // eax@8
  unsigned int v9; // edx@8
  AC1Legacy::PSRefBuffer<char> *v10; // ebp@8
  unsigned int v11; // eax@8
  unsigned int v13; // [sp+8h] [bp-Ch]@4
  unsigned int v14; // [sp+Ch] [bp-8h]@8
  AC1Legacy::PSRefBuffer<char> *v15; // [sp+10h] [bp-4h]@6

  v2 = a2;
  v3 = this;
  if ( this != (PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *)a2 )
  {
    PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::EmptyContents(this);
    if ( v3->_buckets )
    {
      operator delete[](v3->_buckets);
      v3->_buckets = 0;
    }
    v3->_table_size = 0;
    v3->_table_size = *(_DWORD *)(a2 + 12);
    PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3);
    v4 = 0;
    v13 = 0;
    if ( *(_DWORD *)(a2 + 12) > 0u )
    {
      do
      {
        v5 = *(AC1Legacy::PStringBase<char> **)(*(_DWORD *)(v2 + 8) + 4 * v4);
        if ( v5 )
        {
          do
          {
            v6 = v5[2].m_buffer;
            v15 = v5[2].m_buffer;
            if ( !PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::lookup(v3, v5) )
            {
              v7 = operator new(0x10u);
              if ( v7 )
              {
                v8 = v5->m_buffer;
                v9 = v3->_table_size;
                *(_DWORD *)v7 = v5->m_buffer;
                v14 = v9;
                InterlockedIncrement((volatile LONG *)&v8->m_cRef);
                *((_DWORD *)v7 + 1) = v5[1].m_buffer;
                *((_DWORD *)v7 + 2) = 0;
                v10 = v5->m_buffer;
                v11 = v5->m_buffer->m_hash;
                if ( v11 == -1 )
                {
                  v11 = AC1Legacy::PStringBase<char>::compute_hash(v5);
                  v10->m_hash = v11;
                }
                v6 = v15;
                *((_DWORD *)v7 + 3) = v11 % v14;
                *((_DWORD *)v7 + 2) = v3->_buckets[v11 % v14];
                v3->_buckets[v11 % v14] = (PackableHashData<AC1Legacy::PStringBase<char>,unsigned long> *)v7;
                ++v3->_currNum;
              }
            }
            v5 = (AC1Legacy::PStringBase<char> *)v6;
          }
          while ( v6 );
          v2 = a2;
          v4 = v13;
        }
        ++v4;
        v13 = v4;
      }
      while ( v4 < *(_DWORD *)(v2 + 12) );
    }
  }
  return v3;
}

//----- (006B17E0) --------------------------------------------------------  // acclient.c:714813
void __thiscall PackableHashTable<unsigned long,SquelchInfo>::EmptyContents(PackableHashTable<unsigned long,SquelchInfo> *this)
{
  unsigned int v1; // eax@2
  PackableHashData<unsigned long,SquelchInfo> *v2; // edi@3
  PackableHashData<unsigned long,SquelchInfo> *v3; // ebp@4
  AC1Legacy::PSRefBuffer<char> *v4; // ebx@4
  unsigned int i; // [sp+4h] [bp-8h]@2
  PackableHashTable<unsigned long,SquelchInfo> *v6; // [sp+8h] [bp-4h]@1

  v6 = this;
  if ( this->_buckets )
  {
    v1 = 0;
    i = 0;
    if ( this->_table_size )
    {
      do
      {
        v2 = this->_buckets[v1];
        if ( v2 )
        {
          do
          {
            v3 = v2->_next;
            v2->_data.vfptr = (PackObjVtbl *)&SquelchInfo::vftable;
            SquelchInfo::Clear(&v2->_data);
            v4 = v2->_data._name.m_buffer;
            if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
              v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
            AC1Legacy::vlong::~vlong(&v2->_data._squelch_msgs);
            v2->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
            operator delete(v2);
            v2 = v3;
          }
          while ( v3 );
          v1 = i;
          this = v6;
        }
        this->_buckets[v1++] = 0;
        i = v1;
      }
      while ( v1 < this->_table_size );
    }
  }
  this->_currNum = 0;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E2ED8: using guessed type int (__thiscall *SquelchInfo::vftable)(void *, char);

//----- (006B1890) --------------------------------------------------------  // acclient.c:714863
PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *__thiscall PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::vector_deleting_destructor(PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *this, unsigned int a2)
{
  PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::vftable;
  PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::EmptyContents(this);
  if ( v2->_buckets )
  {
    operator delete[](v2->_buckets);
    v2->_buckets = 0;
  }
  v2->_table_size = 0;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 803BA0: using guessed type int (__thiscall *PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::vftable)(void *, char);

//----- (006B18E0) --------------------------------------------------------  // acclient.c:714885
void __thiscall SquelchDB::Clear(SquelchDB *this)
{
  SquelchDB *v1; // esi@1

  v1 = this;
  PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::EmptyContents(&this->_account_hash);
  PackableHashTable<unsigned long,SquelchInfo>::EmptyContents(&v1->_character_hash);
  SquelchInfo::Clear(&v1->_global_squelch_info);
}

//----- (006B1900) --------------------------------------------------------  // acclient.c:714896
int __thiscall SquelchDB::UnPack(SquelchDB *this, void **addr, unsigned int size)
{
  SquelchDB *v3; // esi@1
  int result; // eax@2
  char *v5; // edi@3
  int v6; // ebx@3
  int v7; // edx@3
  int v8; // eax@5
  int oldValAcct; // [sp+8h] [bp-4h]@3

  v3 = this;
  if ( size >= 0x10 )
  {
    v5 = (char *)&this->_account_hash;
    PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::EmptyContents(&this->_account_hash);
    v6 = (int)&v3->_character_hash;
    PackableHashTable<unsigned long,SquelchInfo>::EmptyContents(&v3->_character_hash);
    SquelchInfo::Clear(&v3->_global_squelch_info);
    v7 = *(_DWORD *)v5;
    oldValAcct = v3->_account_hash.m_fThrowawayDuplicateKeysOnUnPack;
    v3->_account_hash.m_fThrowawayDuplicateKeysOnUnPack = 1;
    if ( (*(int (__thiscall **)(int, void **, unsigned int))(v7 + 16))(&v3->_account_hash, addr, size)
      && (v8 = *(_DWORD *)v6,
          v3->_account_hash.m_fThrowawayDuplicateKeysOnUnPack = oldValAcct,
          (*(int (__thiscall **)(int, void **, unsigned int))(v8 + 16))(v6, addr, size)) )
      result = ((int (__thiscall *)(int, void **, unsigned int))v3->_global_squelch_info.vfptr->UnPack)(
                 &v3->_global_squelch_info,
                 addr,
                 size) != 0;
    else
      result = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006B19A0) --------------------------------------------------------  // acclient.c:714936
PackableHashTable<unsigned long,SquelchInfo> *__thiscall PackableHashTable<unsigned long,SquelchInfo>::operator=(PackableHashTable<unsigned long,SquelchInfo> *this, int a2)
{
  PackableHashTable<unsigned long,SquelchInfo> *v2; // edi@1
  unsigned int v3; // ebx@2
  int v4; // eax@5
  int v5; // esi@6

  v2 = this;
  if ( this != (PackableHashTable<unsigned long,SquelchInfo> *)a2 )
  {
    PackableHashTable<unsigned long,SquelchInfo>::EmptyContents(this);
    v3 = 0;
    if ( v2->_buckets )
    {
      operator delete[](v2->_buckets);
      v2->_buckets = 0;
    }
    v2->_table_size = 0;
    v2->_table_size = *(_DWORD *)(a2 + 12);
    PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
    if ( *(_DWORD *)(a2 + 12) > 0u )
    {
      do
      {
        v4 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4 * v3);
        if ( v4 )
        {
          do
          {
            v5 = *(_DWORD *)(v4 + 28);
            PackableHashTable<unsigned long,SquelchInfo>::add(v2, (const unsigned int *)v4, (SquelchInfo *)(v4 + 4));
            v4 = v5;
          }
          while ( v5 );
        }
        ++v3;
      }
      while ( v3 < *(_DWORD *)(a2 + 12) );
    }
  }
  return v2;
}

//----- (006B1A20) --------------------------------------------------------  // acclient.c:714980
int __thiscall PackableHashTable<unsigned long,SquelchInfo>::UnPack(PackableHashTable<unsigned long,SquelchInfo> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<unsigned long,SquelchInfo> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  void **v10; // ebx@5
  unsigned int v11; // ebp@5
  SquelchInfo *v12; // ecx@16
  unsigned int tempKey; // [sp+8h] [bp-24h]@11
  void *start_addr; // [sp+Ch] [bp-20h]@3
  unsigned int blob_size; // [sp+10h] [bp-1Ch]@3
  SquelchInfo tempData; // [sp+14h] [bp-18h]@10

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,SquelchInfo>::EmptyContents(this);
  if ( v4->_buckets )
  {
    operator delete[](v4->_buckets);
    v4->_buckets = 0;
  }
  v4->_table_size = 0;
  v7 = *(_DWORD *)*v6;
  *v6 = (char *)*v6 + 4;
  v8 = v7 >> 16;
  v9 = (unsigned __int16)v7;
  v10 = (void **)(v3 - 4);
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 <= 0x10000
    && v9 <= 0x10000
    && PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
  {
    SquelchInfo::SquelchInfo(&tempData);
    size = 0;
    if ( v11 )
    {
      while ( 1 )
      {
        addr = v10;
        if ( !PackObj::UNPACK_TYPE((int *)&tempKey, v6, (unsigned int *)&addr)
          || !((int (__thiscall *)(SquelchInfo *, void **, void **))tempData.vfptr->UnPack)(&tempData, v6, v10)
          || !PackableHashTable<unsigned long,SquelchInfo>::add(v4, &tempKey, &tempData)
          && !v4->m_fThrowawayDuplicateKeysOnUnPack )
          break;
        ++size;
        if ( size >= v11 )
          goto LABEL_16;
      }
      v12 = &tempData;
    }
    else
    {
LABEL_16:
      v12 = &tempData;
      if ( blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr )
      {
        SquelchInfo::~SquelchInfo(&tempData);
        return 1;
      }
    }
    SquelchInfo::~SquelchInfo(v12);
  }
  return 0;
}

//----- (006B1B70) --------------------------------------------------------  // acclient.c:715057
PackableHashTable<unsigned long,SquelchInfo> *__thiscall PackableHashTable<unsigned long,SquelchInfo>::scalar_deleting_destructor(PackableHashTable<unsigned long,SquelchInfo> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,SquelchInfo> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,SquelchInfo>::vftable;
  PackableHashTable<unsigned long,SquelchInfo>::EmptyContents(this);
  if ( v2->_buckets )
  {
    operator delete[](v2->_buckets);
    v2->_buckets = 0;
  }
  v2->_table_size = 0;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 803BB4: using guessed type int (__thiscall *PackableHashTable<unsigned long,SquelchInfo>::vftable)(void *, char);

//----- (006B1BC0) --------------------------------------------------------  // acclient.c:715079
void __thiscall SquelchDB::SquelchDB(SquelchDB *this)
{
  SquelchDB *v1; // edi@1
  char *v2; // ecx@1
  int v3; // ecx@1
  volatile LONG *v4; // ST00_4@1

  v1 = this;
  v2 = (char *)&this->_account_hash;
  v1->vfptr = (PackObjVtbl *)&SquelchDB::vftable;
  *(_DWORD *)v2 = &PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::vftable;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 128;
  *((_DWORD *)v2 + 4) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
  v3 = (int)&v1->_character_hash;
  *(_DWORD *)v3 = &PackableHashTable<unsigned long,SquelchInfo>::vftable;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 128;
  *(_DWORD *)(v3 + 16) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&v1->_character_hash);
  v1->_global_squelch_info.vfptr = (PackObjVtbl *)&SquelchInfo::vftable;
  AC1Legacy::vlong::vlong(&v1->_global_squelch_info._squelch_msgs, 0);
  v4 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_global_squelch_info._name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v4);
  SquelchInfo::Clear(&v1->_global_squelch_info);
  SquelchInfo::Clear(&v1->_global_squelch_info);
}
// 7E2ED8: using guessed type int (__thiscall *SquelchInfo::vftable)(void *, char);
// 803BA0: using guessed type int (__thiscall *PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::vftable)(void *, char);
// 803BB4: using guessed type int (__thiscall *PackableHashTable<unsigned long,SquelchInfo>::vftable)(void *, char);
// 803BC8: using guessed type int (__thiscall *SquelchDB::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006B1C40) --------------------------------------------------------  // acclient.c:715117
void __thiscall SquelchDB::~SquelchDB(SquelchDB *this)
{
  SquelchDB *v1; // ebp@1
  char *v2; // ebx@1
  int v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = (char *)&this->_account_hash;
  this->vfptr = (PackObjVtbl *)&SquelchDB::vftable;
  PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::EmptyContents(&this->_account_hash);
  v3 = (int)&v1->_character_hash;
  PackableHashTable<unsigned long,SquelchInfo>::EmptyContents(&v1->_character_hash);
  SquelchInfo::Clear(&v1->_global_squelch_info);
  v1->_global_squelch_info.vfptr = (PackObjVtbl *)&SquelchInfo::vftable;
  SquelchInfo::Clear(&v1->_global_squelch_info);
  v4 = v1->_global_squelch_info._name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
  AC1Legacy::vlong::~vlong(&v1->_global_squelch_info._squelch_msgs);
  v1->_global_squelch_info.vfptr = (PackObjVtbl *)&PackObj::vftable;
  *(_DWORD *)v3 = &PackableHashTable<unsigned long,SquelchInfo>::vftable;
  PackableHashTable<unsigned long,SquelchInfo>::EmptyContents(&v1->_character_hash);
  if ( v1->_character_hash._buckets )
  {
    operator delete[](v1->_character_hash._buckets);
    v1->_character_hash._buckets = 0;
  }
  v1->_character_hash._table_size = 0;
  *(_DWORD *)v3 = &PackObj::vftable;
  *(_DWORD *)v2 = &PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::vftable;
  PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::EmptyContents((PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *)v2);
  if ( *((_DWORD *)v2 + 2) )
  {
    operator delete[](*((void **)v2 + 2));
    *((_DWORD *)v2 + 2) = 0;
  }
  *((_DWORD *)v2 + 3) = 0;
  *(_DWORD *)v2 = &PackObj::vftable;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E2ED8: using guessed type int (__thiscall *SquelchInfo::vftable)(void *, char);
// 803BA0: using guessed type int (__thiscall *PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::vftable)(void *, char);
// 803BB4: using guessed type int (__thiscall *PackableHashTable<unsigned long,SquelchInfo>::vftable)(void *, char);
// 803BC8: using guessed type int (__thiscall *SquelchDB::vftable)(void *, char);

//----- (006B1D10) --------------------------------------------------------  // acclient.c:715165
int __thiscall SquelchDB::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  if ( a2 != this )
  {
    PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::operator=(
      (PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long> *)(this + 4),
      a2 + 4);
    PackableHashTable<unsigned long,SquelchInfo>::operator=(
      (PackableHashTable<unsigned long,SquelchInfo> *)(v2 + 24),
      a2 + 24);
    SquelchInfo::operator=(v2 + 44, a2 + 44);
  }
  return v2;
}

//----- (006B1D50) --------------------------------------------------------  // acclient.c:715184
SquelchDB *__thiscall SquelchDB::scalar_deleting_destructor(SquelchDB *this, unsigned int a2)
{
  SquelchDB *v2; // esi@1

  v2 = this;
  SquelchDB::~SquelchDB(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

