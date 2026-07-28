/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RestrictionDB
   Object     : PORTAL\engine_house\RestrictionDB.obj
   Functions  : 32
   Addresses  : 005AE250 - 005AEFB0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005AE250) --------------------------------------------------------  // acclient.c:472473
OldHashData<unsigned long,unsigned long> *__thiscall OldHashIterator<unsigned long,unsigned long>::get_next_bucket_data(OldHashIterator<unsigned long,unsigned long> *this)
{
  OldHashIterator<unsigned long,unsigned long> *v1; // esi@1
  OldHashTable<unsigned long,unsigned long> *v2; // ecx@1
  OldHashData<unsigned long,unsigned long> *result; // eax@2
  int v4; // eax@3
  OldHashTable<unsigned long,unsigned long> *v5; // esi@3
  unsigned int v6; // edx@3
  int v7; // eax@3
  OldHashData<unsigned long,unsigned long> **v8; // esi@4
  int v9; // ecx@4

  v1 = this;
  v2 = this->_table;
  if ( v2 )
  {
    v4 = ((int (__stdcall *)(OldHashData<unsigned long,unsigned long> *))v2->vfptr->hash)(v1->_current);
    v5 = v1->_table;
    v6 = v5->_num_buckets;
    v7 = v4 + 1;
    if ( v7 >= v6 )
    {
LABEL_7:
      result = 0;
    }
    else
    {
      v8 = v5->_buckets;
      v9 = (int)&v8[v7];
      while ( !*(_DWORD *)v9 )
      {
        ++v7;
        v9 += 4;
        if ( v7 >= v6 )
          goto LABEL_7;
      }
      result = v8[v7];
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005AE290) --------------------------------------------------------  // acclient.c:472520
unsigned int *__thiscall OldHashTable<unsigned long,unsigned long>::find(OldHashTable<unsigned long,unsigned long> *this, const unsigned int *key)
{
  OldHashTable<unsigned long,unsigned long> *v2; // esi@1
  OldHashData<unsigned long,unsigned long> *v3; // edi@3
  unsigned int *result; // eax@6

  v2 = this;
  if ( this->_num_buckets
    && this->_buckets
    && (v3 = this->_buckets[((int (__stdcall *)(const unsigned int *))this->vfptr->hash)(key)]) != 0 )
  {
    while ( !v2->vfptr->is_keys_equiv(v2, key, (const unsigned int *)v3) )
    {
      v3 = v3->_next;
      if ( !v3 )
        goto LABEL_6;
    }
    result = &v3->_data;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (005AE2E0) --------------------------------------------------------  // acclient.c:472548
int __thiscall OldHashTable<unsigned long,unsigned long>::verify_num_buckets(OldHashTable<unsigned long,unsigned long> *this)
{
  unsigned int v1; // edx@1
  unsigned int v2; // eax@2

  v1 = this->_num_buckets;
  if ( !v1 )
    return 1;
  v2 = 2147483648;
  if ( v1 <= 0x80000000 )
  {
    if ( !(v1 & 0x80000000) )
    {
      do
        v2 >>= 1;
      while ( !(v1 & v2) );
    }
    if ( v2 == v1 )
      return 1;
    v2 *= 2;
  }
  this->_num_buckets = v2;
  return 0;
}

//----- (005AE310) --------------------------------------------------------  // acclient.c:472574
void __thiscall RestrictionDB::SetOpenHouse(RestrictionDB *this, int open)
{
  unsigned int v2; // eax@1

  v2 = this->_bitmask;
  if ( open )
    this->_bitmask = v2 | 1;
  else
    this->_bitmask = v2 & 0xFFFFFFFE;
}

//----- (005AE330) --------------------------------------------------------  // acclient.c:472586
unsigned int __thiscall RestrictionDB::Pack(RestrictionDB *this, void **addr, unsigned int size)
{
  RestrictionDB *v3; // ebx@1
  PackObjVtbl *v4; // eax@1
  char *v5; // esi@1
  unsigned int v6; // edi@1
  char *v7; // ecx@2
  char *v8; // ebp@2
  RestrictionDB *v10; // [sp+0h] [bp-4h]@1

  v10 = this;
  v3 = this;
  v4 = this->_table.vfptr;
  v5 = (char *)&this->_table.vfptr;
  v10 = 0;
  v6 = ((int (__thiscall *)(PackObjVtbl **, int *, _DWORD))v4->Pack)(&this->_table.vfptr, &v10, 0) + 12;
  if ( size >= v6 )
  {
    *(_DWORD *)*addr = 268435458;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->_bitmask;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = v3->_monarch_iid;
    *addr = (char *)*addr + 4;
    (*(void (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v5 + 12))(v5, addr, size);
  }
  return v6;
}

//----- (005AE3A0) --------------------------------------------------------  // acclient.c:472618
OldHashIterator<unsigned long,unsigned long> *__thiscall OldHashTable<unsigned long,unsigned long>::begin(OldHashTable<unsigned long,unsigned long> *this, OldHashIterator<unsigned long,unsigned long> *result)
{
  OldHashData<unsigned long,unsigned long> **v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // esi@2
  OldHashData<unsigned long,unsigned long> **v5; // edx@3
  OldHashIterator<unsigned long,unsigned long> *v6; // eax@6

  v2 = this->_buckets;
  v3 = 0;
  if ( v2 && (v4 = this->_num_buckets) != 0 )
  {
    v5 = this->_buckets;
    while ( !*v5 )
    {
      ++v3;
      ++v5;
      if ( v3 >= v4 )
        goto LABEL_6;
    }
    result->_current = v2[v3];
    result->_table = this;
    v6 = result;
  }
  else
  {
LABEL_6:
    result->_current = 0;
    result->_table = this;
    v6 = result;
  }
  return v6;
}

//----- (005AE3F0) --------------------------------------------------------  // acclient.c:472653
int __thiscall OldHashTable<unsigned long,unsigned long>::init(OldHashTable<unsigned long,unsigned long> *this)
{
  OldHashTable<unsigned long,unsigned long> *v1; // esi@1
  void *v2; // eax@3
  unsigned int v4; // eax@5

  v1 = this;
  if ( this->_buckets )
    return 0;
  if ( this->_num_buckets )
  {
    OldHashTable<unsigned long,unsigned long>::verify_num_buckets(this);
    v2 = operator new[](4 * v1->_num_buckets);
    v1->_buckets = (OldHashData<unsigned long,unsigned long> **)v2;
    if ( !v2 )
      return 0;
    v4 = 0;
    if ( v1->_num_buckets )
    {
      do
        v1->_buckets[v4++] = 0;
      while ( v4 < v1->_num_buckets );
    }
  }
  return 1;
}

//----- (005AE450) --------------------------------------------------------  // acclient.c:472681
int __thiscall OldHashTable<unsigned long,unsigned long>::add(OldHashTable<unsigned long,unsigned long> *this, const unsigned int *key, const unsigned int *data)
{
  OldHashTable<unsigned long,unsigned long> *v3; // esi@1
  int result; // eax@2
  void *v5; // eax@5
  void *v6; // edi@5
  int v7; // eax@6

  v3 = this;
  if ( this->_num_elements < 0xFFFFFF )
  {
    if ( OldHashTable<unsigned long,unsigned long>::find(this, key) || (v5 = operator new(0xCu), (v6 = v5) == 0) )
    {
      result = 0;
    }
    else
    {
      *(_DWORD *)v5 = *key;
      *((_DWORD *)v5 + 1) = *data;
      *((_DWORD *)v5 + 2) = 0;
      v7 = v3->vfptr->hash(v3, key);
      *((_DWORD *)v6 + 2) = v3->_buckets[v7];
      v3->_buckets[v7] = (OldHashData<unsigned long,unsigned long> *)v6;
      ++v3->_num_elements;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005AE4D0) --------------------------------------------------------  // acclient.c:472716
void __thiscall OldHashTable<unsigned long,unsigned long>::flush(OldHashTable<unsigned long,unsigned long> *this)
{
  OldHashTable<unsigned long,unsigned long> *v1; // edi@1
  unsigned int v2; // ebx@2
  OldHashData<unsigned long,unsigned long> *v3; // eax@3
  OldHashData<unsigned long,unsigned long> *v4; // esi@4

  v1 = this;
  if ( this->_buckets )
  {
    v2 = 0;
    if ( this->_num_buckets )
    {
      do
      {
        v3 = v1->_buckets[v2];
        if ( v3 )
        {
          do
          {
            v4 = v3->_next;
            operator delete(v3);
            v3 = v4;
          }
          while ( v4 );
        }
        v1->_buckets[v2++] = 0;
      }
      while ( v2 < v1->_num_buckets );
    }
  }
  v1->_num_elements = 0;
}

//----- (005AE520) --------------------------------------------------------  // acclient.c:472751
unsigned int __thiscall OldHashTable<unsigned long,unsigned long>::hash(OldHashTable<unsigned long,unsigned long> *this, const unsigned int *key)
{
  return *key % this->_num_buckets;
}

//----- (005AE530) --------------------------------------------------------  // acclient.c:472757
BOOL __stdcall OldHashTable<unsigned long,unsigned long>::is_keys_equiv(const unsigned int *lhs, const unsigned int *rhs)
{
  return *lhs == *rhs;
}

//----- (005AE550) --------------------------------------------------------  // acclient.c:472763
void __thiscall OldPHashTable<unsigned long,unsigned long>::OldPHashTable<unsigned long,unsigned long>(OldPHashTable<unsigned long,unsigned long> *this)
{
  OldPHashTable<unsigned long,unsigned long> *v1; // esi@1

  v1 = this;
  this->vfptr = (OldHashTable<unsigned long,unsigned long>Vtbl *)&OldHashTable<unsigned long,unsigned long>::vftable;
  this->_buckets = 0;
  this->_num_buckets = 32;
  this->_num_elements = 0;
  OldHashTable<unsigned long,unsigned long>::init((OldHashTable<unsigned long,unsigned long> *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (OldHashTable<unsigned long,unsigned long>Vtbl *)&OldPHashTable<unsigned long,unsigned long>::vftable;
  v1->vfptr = (PackObjVtbl *)&OldPHashTable<unsigned long,unsigned long>::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E6168: using guessed type int (__thiscall *OldHashTable<unsigned long,unsigned long>::vftable)(void *, char);
// 7E6174: using guessed type void *OldPHashTable<unsigned long,unsigned long>::vftable;
// 7E6188: using guessed type int (__thiscall *OldPHashTable<unsigned long,unsigned long>::vftable)(void *, char);

//----- (005AE590) --------------------------------------------------------  // acclient.c:472783
OldPHashTable<unsigned long,unsigned long> *__thiscall OldPHashTable<unsigned long,unsigned long>::vector_deleting_destructor(OldPHashTable<unsigned long,unsigned long> *this, unsigned int a2)
{
  return OldPHashTable<unsigned long,unsigned long>::scalar_deleting_destructor(
           (OldPHashTable<unsigned long,unsigned long> *)((char *)this - 16),
           a2);
}

//----- (005AE5A0) --------------------------------------------------------  // acclient.c:472791
signed int __thiscall OldPHashTable<unsigned long,unsigned long>::Pack(OldPHashTable<unsigned long,unsigned long> *this, void **addr, unsigned int size)
{
  OldPHashTable<unsigned long,unsigned long> *v3; // esi@1
  char *v4; // ebx@1
  signed int v5; // ebp@1
  unsigned int v6; // ecx@2
  int i; // eax@2
  int v8; // edi@4
  unsigned int v9; // eax@4
  unsigned int v10; // edx@5
  int v11; // ecx@6
  char *v12; // edx@12
  int v13; // eax@17
  unsigned int v14; // edx@17
  int v15; // eax@17
  int v16; // edi@18
  int v17; // ecx@18

  v3 = this;
  v4 = (char *)&this[-1]._buckets;
  v5 = OldPHashTable<unsigned long,unsigned long>::pack_size((OldPHashTable<unsigned long,unsigned long> *)((char *)this - 16));
  if ( size >= v5 )
  {
    v6 = v3[-1]._num_elements;
    for ( i = 0; v6; ++i )
      v6 >>= 1;
    *(_DWORD *)*addr = (unsigned int)v3[-1].vfptr | (i << 24);
    *addr = (char *)*addr + 4;
    v8 = *((_DWORD *)v4 + 1);
    v9 = 0;
    if ( v8 )
    {
      v10 = *((_DWORD *)v4 + 2);
      if ( v10 )
      {
        v11 = *((_DWORD *)v4 + 1);
        while ( !*(_DWORD *)v11 )
        {
          ++v9;
          v11 += 4;
          if ( v9 >= v10 )
            goto LABEL_9;
        }
        v9 = *(_DWORD *)(v8 + 4 * v9);
      }
      else
      {
LABEL_9:
        v9 = 0;
      }
    }
    while ( v9 )
    {
      if ( size >= 4 )
      {
        *(_DWORD *)*addr = *(_DWORD *)v9;
        v12 = (char *)*addr + 4;
        *addr = v12;
        *(_DWORD *)v12 = *(_DWORD *)(v9 + 4);
        *addr = (char *)*addr + 4;
      }
      if ( !v9 )
        break;
      if ( *(_DWORD *)(v9 + 8) )
      {
        v9 = *(_DWORD *)(v9 + 8);
      }
      else
      {
        v13 = (*(int (__thiscall **)(char *, unsigned int))(*(_DWORD *)v4 + 4))(v4, v9);
        v14 = *((_DWORD *)v4 + 2);
        v15 = v13 + 1;
        if ( v15 >= v14 )
        {
LABEL_21:
          v9 = 0;
        }
        else
        {
          v16 = *((_DWORD *)v4 + 1);
          v17 = v16 + 4 * v15;
          while ( !*(_DWORD *)v17 )
          {
            ++v15;
            v17 += 4;
            if ( v15 >= v14 )
              goto LABEL_21;
          }
          v9 = *(_DWORD *)(v16 + 4 * v15);
        }
      }
    }
  }
  return v5;
}

//----- (005AE680) --------------------------------------------------------  // acclient.c:472888
signed int __thiscall OldPHashTable<unsigned long,unsigned long>::pack_size(OldPHashTable<unsigned long,unsigned long> *this)
{
  signed int v1; // ebx@1
  OldHashData<unsigned long,unsigned long> *v2; // eax@1
  OldHashTable<unsigned long,unsigned long> *v3; // edi@2
  int v4; // eax@7
  unsigned int v5; // edx@7
  int v6; // eax@7
  OldHashData<unsigned long,unsigned long> **v7; // esi@8
  int v8; // ecx@8
  OldHashIterator<unsigned long,unsigned long> iter; // [sp+Ch] [bp-8h]@1

  v1 = 4;
  OldHashTable<unsigned long,unsigned long>::begin((OldHashTable<unsigned long,unsigned long> *)&this->vfptr, &iter);
  v2 = iter._current;
  if ( (_DWORD)iter._current )
  {
    v3 = iter._table;
    do
    {
      v1 += 8;
      if ( !v2 )
        break;
      if ( v2->_next )
      {
        v2 = v2->_next;
      }
      else if ( v3 && (v4 = v3->vfptr->hash(v3, (const unsigned int *)v2), v5 = v3->_num_buckets, v6 = v4 + 1, v6 < v5) )
      {
        v7 = v3->_buckets;
        v8 = (int)&v7[v6];
        while ( !*(_DWORD *)v8 )
        {
          ++v6;
          v8 += 4;
          if ( v6 >= v5 )
            goto LABEL_11;
        }
        v2 = v7[v6];
      }
      else
      {
LABEL_11:
        v2 = 0;
      }
    }
    while ( v2 );
  }
  return v1;
}

//----- (005AE700) --------------------------------------------------------  // acclient.c:472940
signed int __thiscall OldPHashTable<unsigned long,unsigned long>::GetPackSize(OldPHashTable<unsigned long,unsigned long> *this)
{
  return OldPHashTable<unsigned long,unsigned long>::pack_size((OldPHashTable<unsigned long,unsigned long> *)((char *)this - 16));
}

//----- (005AE710) --------------------------------------------------------  // acclient.c:472946
void __thiscall OldPHashTable<unsigned long,unsigned long>::~OldPHashTable<unsigned long,unsigned long>(OldPHashTable<unsigned long,unsigned long> *this)
{
  OldPHashTable<unsigned long,unsigned long> *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&OldPHashTable<unsigned long,unsigned long>::vftable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (OldHashTable<unsigned long,unsigned long>Vtbl *)&OldHashTable<unsigned long,unsigned long>::vftable;
  OldHashTable<unsigned long,unsigned long>::flush((OldHashTable<unsigned long,unsigned long> *)&this->vfptr);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_num_buckets = 0;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E6168: using guessed type int (__thiscall *OldHashTable<unsigned long,unsigned long>::vftable)(void *, char);
// 7E6174: using guessed type void *OldPHashTable<unsigned long,unsigned long>::vftable;

//----- (005AE750) --------------------------------------------------------  // acclient.c:472967
int __thiscall OldPHashTable<unsigned long,unsigned long>::UnPack(OldPHashTable<unsigned long,unsigned long> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebp@1
  OldPHashTable<unsigned long,unsigned long> *v4; // ebx@1
  char *v6; // edi@3
  void **v7; // esi@5
  unsigned int v8; // edx@5
  int v9; // edx@10
  int v10; // ebp@10
  unsigned int v11; // ebx@13
  unsigned int v12; // ecx@15
  int v13; // eax@15
  void **v14; // edx@15
  unsigned int tmp_key; // [sp+8h] [bp-4h]@15

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = (char *)&this[-1]._buckets;
  OldHashTable<unsigned long,unsigned long>::flush((OldHashTable<unsigned long,unsigned long> *)&this[-1]._buckets);
  if ( *((_DWORD *)v6 + 1) )
  {
    operator delete[](*((void **)v6 + 1));
    *((_DWORD *)v6 + 1) = 0;
  }
  *((_DWORD *)v6 + 2) = 0;
  v7 = addr;
  v8 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  size = v3 - 4;
  if ( v8 >> 24 > 0x20 )
    return 0;
  if ( v8 >> 24 )
    v4[-1]._num_elements = 1 << (BYTE3(v8) - 1);
  else
    v4[-1]._num_elements = 0;
  v9 = v8 & 0xFFFFFF;
  v10 = v9;
  if ( !v4[-1]._num_elements )
    return v9 == 0;
  if ( !OldHashTable<unsigned long,unsigned long>::init((OldHashTable<unsigned long,unsigned long> *)&v4[-1]._buckets) )
    return 0;
  v11 = 0;
  if ( v10 )
  {
    while ( size >= 4 )
    {
      v12 = *(_DWORD *)*v7;
      v13 = (int)((char *)*v7 + 4);
      *v7 = (void *)v13;
      tmp_key = v12;
      v14 = *(void ***)v13;
      *v7 = (void *)(v13 + 4);
      addr = v14;
      if ( !OldHashTable<unsigned long,unsigned long>::add(
              (OldHashTable<unsigned long,unsigned long> *)v6,
              &tmp_key,
              (const unsigned int *)&addr) )
        break;
      ++v11;
      if ( v11 >= v10 )
        return 1;
    }
    return 0;
  }
  return 1;
}

//----- (005AE850) --------------------------------------------------------  // acclient.c:473037
OldHashTable<unsigned long,unsigned long> *__thiscall OldHashTable<unsigned long,unsigned long>::vector_deleting_destructor(OldHashTable<unsigned long,unsigned long> *this, unsigned int a2)
{
  OldHashTable<unsigned long,unsigned long> *v2; // esi@1

  v2 = this;
  this->vfptr = (OldHashTable<unsigned long,unsigned long>Vtbl *)&OldHashTable<unsigned long,unsigned long>::vftable;
  OldHashTable<unsigned long,unsigned long>::flush(this);
  if ( v2->_buckets )
  {
    operator delete[](v2->_buckets);
    v2->_buckets = 0;
  }
  v2->_num_buckets = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E6168: using guessed type int (__thiscall *OldHashTable<unsigned long,unsigned long>::vftable)(void *, char);

//----- (005AE8A0) --------------------------------------------------------  // acclient.c:473057
OldPHashTable<unsigned long,unsigned long> *__thiscall OldPHashTable<unsigned long,unsigned long>::scalar_deleting_destructor(OldPHashTable<unsigned long,unsigned long> *this, unsigned int a2)
{
  OldPHashTable<unsigned long,unsigned long> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&OldPHashTable<unsigned long,unsigned long>::vftable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (OldHashTable<unsigned long,unsigned long>Vtbl *)&OldHashTable<unsigned long,unsigned long>::vftable;
  OldHashTable<unsigned long,unsigned long>::flush((OldHashTable<unsigned long,unsigned long> *)&this->vfptr);
  if ( v2->_buckets )
  {
    operator delete[](v2->_buckets);
    v2->_buckets = 0;
  }
  v2->_num_buckets = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E6168: using guessed type int (__thiscall *OldHashTable<unsigned long,unsigned long>::vftable)(void *, char);
// 7E6174: using guessed type void *OldPHashTable<unsigned long,unsigned long>::vftable;

//----- (005AE8F0) --------------------------------------------------------  // acclient.c:473081
int __thiscall RestrictionDB::IsAllowedIn(RestrictionDB *this, unsigned int guest, unsigned int monarch)
{
  unsigned int v3; // eax@2
  int result; // eax@6

  result = 1;
  if ( !(this->_bitmask & 1) )
  {
    v3 = this->_monarch_iid;
    if ( !v3 || monarch != v3 )
    {
      monarch = guest;
      if ( !guest
        || HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
             (HashTable<unsigned long,unsigned long,0> *)&this->_table.vfptr,
             &monarch) == 0 )
        result = 0;
    }
  }
  return result;
}

//----- (005AE940) --------------------------------------------------------  // acclient.c:473104
char __thiscall HashTable<unsigned long,unsigned long,0>::resize(HashTable<unsigned long,unsigned long,0> *this, unsigned int _numBuckets)
{
  unsigned int *v2; // esi@1
  HashTable<unsigned long,unsigned long,0> *v3; // edi@1
  unsigned int *v4; // eax@1

  v2 = g_bucketSizesEnd;
  v3 = this;
  v4 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v2 )
    --v4;
  return IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::resize_internal(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v3->m_intrusiveTable,
           *v4);
}

//----- (005AE990) --------------------------------------------------------  // acclient.c:473121
int __thiscall RestrictionDB::UnPack(RestrictionDB *this, void **addr, unsigned int size)
{
  unsigned int v3; // edi@1
  RestrictionDB *v4; // ebx@1
  void **v6; // esi@3
  void *v7; // ebp@3
  char *v8; // eax@3
  signed int v9; // ecx@4
  int v10; // eax@11
  unsigned int v11; // edi@12
  int v12; // ecx@17
  int v13; // eax@17
  int v14; // eax@17
  OldHashData<unsigned long,unsigned long> *v15; // esi@19
  HashTable<unsigned long,RenderVertexStreamD3D *,0> *v16; // ebx@20
  int v17; // ecx@28
  int v18; // eax@28
  int v19; // eax@28
  int v20; // edi@29
  OldHashIterator<unsigned long,unsigned long> iter; // [sp+8h] [bp-1Ch]@19
  OldPHashTable<unsigned long,unsigned long> old_style_table; // [sp+10h] [bp-14h]@10
  int addra; // [sp+28h] [bp+4h]@3
  unsigned int dummy; // [sp+2Ch] [bp+8h]@4

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  v7 = *addr;
  v8 = (char *)*addr + 4;
  addra = *(_DWORD *)*addr;
  *v6 = v8;
  if ( addra & 0xFFFF0000 )
  {
    dummy = addra;
    if ( addra )
      v9 = 12;
    else
      v9 = 4;
  }
  else
  {
    dummy = 0;
    v9 = 4;
  }
  if ( v3 < v9 )
    return 0;
  if ( dummy >= 0x10000002 )
  {
    v4->_bitmask = *(_DWORD *)v8;
    v17 = (int)((char *)*v6 + 4);
    *v6 = (void *)v17;
    v4->_monarch_iid = *(_DWORD *)v17;
    v18 = (int)((char *)*v6 + 4);
    *v6 = (void *)v18;
    v19 = v18 - (_DWORD)v7;
    if ( v3 <= v19 )
      v20 = 0;
    else
      v20 = v3 - v19;
    return ((int (__thiscall *)(int, void **, int))v4->_table.vfptr->UnPack)(&v4->_table.vfptr, v6, v20) != 0;
  }
  OldPHashTable<unsigned long,unsigned long>::OldPHashTable<unsigned long,unsigned long>(&old_style_table);
  if ( dummy )
  {
    v4->_bitmask = *(_DWORD *)*v6;
    v12 = (int)((char *)*v6 + 4);
    *v6 = (void *)v12;
    v4->_monarch_iid = *(_DWORD *)v12;
    v13 = (int)((char *)*v6 + 4);
    *v6 = (void *)v13;
    v14 = v13 - (_DWORD)v7;
    if ( v3 > v14 )
    {
      v11 = v3 - v14;
      goto LABEL_14;
    }
    goto LABEL_13;
  }
  RestrictionDB::SetOpenHouse(v4, addra);
  v10 = (_BYTE *)*v6 - (_BYTE *)v7;
  if ( v3 <= v10 )
  {
LABEL_13:
    v11 = 0;
    goto LABEL_14;
  }
  v11 = v3 - v10;
LABEL_14:
  if ( !OldPHashTable<unsigned long,unsigned long>::UnPack(
          (OldPHashTable<unsigned long,unsigned long> *)((char *)&old_style_table + 16),
          v6,
          v11) )
  {
    OldPHashTable<unsigned long,unsigned long>::~OldPHashTable<unsigned long,unsigned long>(&old_style_table);
    return 0;
  }
  OldHashTable<unsigned long,unsigned long>::begin(
    (OldHashTable<unsigned long,unsigned long> *)&old_style_table.vfptr,
    &iter);
  v15 = iter._current;
  if ( (_DWORD)iter._current )
  {
    v16 = (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&v4->_table;
    do
    {
      HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
        v16,
        &v15->_key,
        (RenderVertexStreamD3D *const *)&v15->_data);
      if ( !v15 )
        break;
      v15 = v15->_next;
      if ( !v15 )
        v15 = OldHashIterator<unsigned long,unsigned long>::get_next_bucket_data(&iter);
      iter._current = v15;
    }
    while ( v15 );
  }
  old_style_table.vfptr = (PackObjVtbl *)&PackObj::vftable;
  old_style_table.vfptr = (OldHashTable<unsigned long,unsigned long>Vtbl *)&OldHashTable<unsigned long,unsigned long>::vftable;
  OldHashTable<unsigned long,unsigned long>::flush((OldHashTable<unsigned long,unsigned long> *)&old_style_table.vfptr);
  if ( old_style_table._buckets )
    operator delete[](old_style_table._buckets);
  return 1;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E6168: using guessed type int (__thiscall *OldHashTable<unsigned long,unsigned long>::vftable)(void *, char);

//----- (005AEB40) --------------------------------------------------------  // acclient.c:473252
int __thiscall HashTable<unsigned long,unsigned long,0>::operator=(int this, unsigned int __val)
{
  unsigned int v2; // edi@1
  int v3; // ebx@1
  unsigned int *v4; // ebp@2
  unsigned int *v5; // eax@2
  void *v6; // ebp@4
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // eax@4
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // esi@4
  void *v9; // eax@7
  void *v10; // ecx@7
  unsigned int v11; // edx@8
  unsigned int v12; // ebx@9
  int v13; // edi@9
  int v14; // edx@10
  int v15; // eax@13
  HashTableData<unsigned long,HeritageGroup_CG> **v16; // ecx@17
  HashTableData<unsigned long,HeritageGroup_CG> **v17; // eax@18
  int v19; // [sp+8h] [bp-1Ch]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-18h]@4
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v21; // [sp+18h] [bp-Ch]@4

  v2 = __val;
  v3 = this;
  v19 = this;
  if ( this == __val )
    return v3;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)(this + 4));
  v4 = g_bucketSizesEnd;
  __val = *(_DWORD *)(v2 + 108);
  v5 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v5 == v4 )
    --v5;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::resize_internal(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)(v3 + 4),
    *v5);
  v6 = 0;
  v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)(v2 + 4),
         &result);
  v8 = v7->m_currElement;
  v21 = v7->m_currHashTable;
  result.m_currBucket = v7->m_currBucket;
  if ( !v8 )
    return v3;
  while ( 1 )
  {
    v9 = operator new(0xCu);
    v10 = 0;
    if ( v9 )
    {
      v11 = v8->m_hashKey;
      *((_DWORD *)v9 + 1) = 0;
      *(_DWORD *)v9 = v11;
      *((_DWORD *)v9 + 2) = v8->m_data.vfptr;
      v10 = v9;
    }
    v12 = *(_DWORD *)(v3 + 108);
    v13 = *(_DWORD *)v10 % v12;
    if ( !v6 )
      goto LABEL_13;
    v14 = *(_DWORD *)v6 % v12;
    if ( v13 != v14 )
    {
      if ( v13 <= (unsigned int)v14 )
        goto LABEL_16;
LABEL_13:
      v15 = *(_DWORD *)(v19 + 100) + 4 * v13;
      *(_DWORD *)v15 = v10;
      if ( !v6 )
        *(_DWORD *)(v19 + 104) = v15;
      goto LABEL_15;
    }
    *((_DWORD *)v6 + 1) = v10;
LABEL_15:
    ++*(_DWORD *)(v19 + 112);
LABEL_16:
    v8 = v8->m_hashNext;
    v6 = v10;
    if ( !v8 )
      break;
LABEL_6:
    v3 = v19;
  }
  v16 = &v21->m_buckets[v21->m_numBuckets];
  while ( 1 )
  {
    v17 = result.m_currBucket + 1;
    ++result.m_currBucket;
    if ( result.m_currBucket == v16 )
      return v19;
    if ( *v17 )
    {
      v8 = *v17;
      if ( *v17 )
        goto LABEL_6;
      return v19;
    }
  }
}

//----- (005AEC80) --------------------------------------------------------  // acclient.c:473354
PHashTable<unsigned long,unsigned long> *__thiscall PHashTable<unsigned long,unsigned long>::vector_deleting_destructor(PHashTable<unsigned long,unsigned long> *this, unsigned int a2)
{
  return PHashTable<unsigned long,unsigned long>::scalar_deleting_destructor(
           (PHashTable<unsigned long,unsigned long> *)((char *)this - 116),
           a2);
}

//----- (005AEC90) --------------------------------------------------------  // acclient.c:473362
int __thiscall PHashTable<unsigned long,unsigned long>::StreamPack(PHashTable<unsigned long,unsigned long> *this, STREAMTYPE op, void **addr, unsigned int *size)
{
  STREAMTYPE v4; // edi@1
  PHashTable<unsigned long,unsigned long> *v5; // esi@1
  STREAMTYPE v6; // ebx@2
  const unsigned int *v7; // eax@3
  void **v8; // ebp@3
  unsigned int *v9; // ebx@3
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // eax@4
  HashTableData<unsigned long,unsigned long> **v11; // edx@4
  HashTableData<unsigned long,unsigned long> *v12; // esi@4
  unsigned int v14; // eax@10
  __int32 v15; // edi@12
  HashTableData<unsigned long,Sex_CG> *v16; // ebx@12
  unsigned int v17; // ebp@12
  void *v18; // eax@13
  void *v19; // esi@13
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *v20; // [sp+10h] [bp-10h]@9
  HashIterator<unsigned long,unsigned long,0> iter; // [sp+14h] [bp-Ch]@4

  v4 = op;
  v5 = this;
  if ( op == 2 )
  {
    v20 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)this[-1].m_intrusiveTable.m_aInplaceBuckets;
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)this[-1].m_intrusiveTable.m_aInplaceBuckets);
    if ( STREAMPACK(STREAM_UNPACK, (unsigned int *)&op, addr, size) )
    {
      v14 = (unsigned int)op >> 24;
      if ( (unsigned int)op >> 24 >= g_numBucketSizes )
        v14 = g_numBucketSizes - 1;
      HashTable<unsigned long,unsigned long,0>::resize(
        (HashTable<unsigned long,unsigned long,0> *)&v5[-1].m_intrusiveTable,
        g_bucketSizesBegin[v14]);
      v15 = op & 0xFFFFFF;
      v16 = 0;
      v17 = 0;
      if ( op & 0xFFFFFF )
      {
        while ( 1 )
        {
          v18 = operator new(0xCu);
          v19 = 0;
          if ( v18 )
          {
            *((_DWORD *)v18 + 1) = 0;
            v19 = v18;
          }
          if ( !STREAMPACK(STREAM_UNPACK, (unsigned int *)v19, addr, size)
            || !STREAMPACK(STREAM_UNPACK, (unsigned int *)v19 + 2, addr, size) )
            break;
          IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
            v20,
            (HashTableData<unsigned long,Sex_CG> *)v19,
            v16);
          ++v17;
          v16 = (HashTableData<unsigned long,Sex_CG> *)v19;
          if ( v17 >= v15 )
            return 1;
        }
        return 0;
      }
      return 1;
    }
  }
  else
  {
    op = (STREAMTYPE)this[-1].vfptr;
    v6 = op;
    if ( (unsigned int)op <= 0xFFFFFF )
    {
      v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::get_bucket_size_pointer(this[-1].m_intrusiveTable.m_numElements);
      v8 = addr;
      op = ((v7 - g_bucketSizesBegin) << 24) | v6;
      v9 = size;
      if ( STREAMPACK(v4, (unsigned int *)&op, addr, size) )
      {
        v10 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
                (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v5[-1].m_intrusiveTable.m_aInplaceBuckets,
                (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&iter);
        v11 = (HashTableData<unsigned long,unsigned long> **)v10->m_currBucket;
        v12 = (HashTableData<unsigned long,unsigned long> *)v10->m_currElement;
        iter.m_iter.m_currHashTable = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0> *)v10->m_currHashTable;
        iter.m_iter.m_currElement = v12;
        iter.m_iter.m_currBucket = v11;
        if ( v12 )
        {
          while ( STREAMPACK(v4, &v12->m_hashKey, v8, v9) && STREAMPACK(v4, &v12->m_data, v8, v9) )
          {
            HashSetIterator<UIListener *>::operator++(&iter);
            v12 = iter.m_iter.m_currElement;
            if ( !iter.m_iter.m_currElement )
              return 1;
          }
          return 0;
        }
        return 1;
      }
    }
  }
  return 0;
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;

//----- (005AEE50) --------------------------------------------------------  // acclient.c:473467
PHashTable<unsigned long,unsigned long> *__thiscall PHashTable<unsigned long,unsigned long>::scalar_deleting_destructor(PHashTable<unsigned long,unsigned long> *this, unsigned int a2)
{
  PHashTable<unsigned long,unsigned long> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PHashTable<unsigned long,unsigned long>::vftable;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 79C9A8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable[3])(void *, char);
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);
// 7E6194: using guessed type void *PHashTable<unsigned long,unsigned long>::vftable;

//----- (005AEEB0) --------------------------------------------------------  // acclient.c:473497
void __thiscall RestrictionDB::RestrictionDB(RestrictionDB *this)
{
  RestrictionDB *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&RestrictionDB::vftable;
  this->_bitmask = 0;
  this->_monarch_iid = 0;
  this->_table.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>(
    &this->_table.m_intrusiveTable,
    0x40u);
  v1->_table.vfptr = (PackObjVtbl *)&StreamPackObj::vftable;
  v1->_table.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)PHashTable<unsigned long,unsigned long>::vftable;
  v1->_table.vfptr = (PackObjVtbl *)&PHashTable<unsigned long,unsigned long>::vftable;
}
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);
// 7C9DC0: using guessed type int (__thiscall *StreamPackObj::vftable)(void *, char);
// 7E6194: using guessed type void *PHashTable<unsigned long,unsigned long>::vftable;
// 7E61AC: using guessed type int (__thiscall *PHashTable<unsigned long,unsigned long>::vftable[2])(void *, char);
// 7E61B0: using guessed type int (__thiscall *RestrictionDB::vftable)(void *, char);

//----- (005AEF00) --------------------------------------------------------  // acclient.c:473520
int __thiscall RestrictionDB::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  if ( this != a2 )
  {
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
    HashTable<unsigned long,unsigned long,0>::operator=(this + 12, a2 + 12);
  }
  return v2;
}

//----- (005AEF30) --------------------------------------------------------  // acclient.c:473535
void __thiscall RestrictionDB::~RestrictionDB(RestrictionDB *this)
{
  RestrictionDB *v1; // edi@1
  char *v2; // esi@1
  void *v3; // eax@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&RestrictionDB::vftable;
  this->_table.vfptr = (PackObjVtbl *)&PHashTable<unsigned long,unsigned long>::vftable;
  v2 = (char *)&this->_table.m_intrusiveTable;
  this->_table.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->_table.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->_table.m_intrusiveTable);
  v3 = (void *)*((_DWORD *)v2 + 24);
  *(_DWORD *)v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable;
  if ( v3 != v2 + 4 )
    operator delete[](v3);
  *((_DWORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 25) = 0;
  *((_DWORD *)v2 + 26) = 0;
  *((_DWORD *)v2 + 27) = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 79C9A8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable[3])(void *, char);
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);
// 7E6194: using guessed type void *PHashTable<unsigned long,unsigned long>::vftable;
// 7E61B0: using guessed type int (__thiscall *RestrictionDB::vftable)(void *, char);

//----- (005AEF90) --------------------------------------------------------  // acclient.c:473565
RestrictionDB *__thiscall RestrictionDB::scalar_deleting_destructor(RestrictionDB *this, unsigned int a2)
{
  RestrictionDB *v2; // esi@1

  v2 = this;
  RestrictionDB::~RestrictionDB(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005AEFB0) --------------------------------------------------------  // acclient.c:473577
void __thiscall RestrictionDB::RestrictionDB(RestrictionDB *this, RestrictionDB *rhs)
{
  RestrictionDB *v2; // esi@1
  int v3; // edi@1

  v2 = this;
  v3 = (int)&this->_table;
  this->vfptr = (PackObjVtbl *)&RestrictionDB::vftable;
  this->_table.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>(
    &this->_table.m_intrusiveTable,
    0x17u);
  *(_DWORD *)(v3 + 116) = &StreamPackObj::vftable;
  *(_DWORD *)v3 = PHashTable<unsigned long,unsigned long>::vftable;
  *(_DWORD *)(v3 + 116) = &PHashTable<unsigned long,unsigned long>::vftable;
  if ( v2 != rhs )
  {
    v2->_bitmask = rhs->_bitmask;
    v2->_monarch_iid = rhs->_monarch_iid;
    HashTable<unsigned long,unsigned long,0>::operator=(v3, (unsigned int)&rhs->_table);
  }
}
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);
// 7C9DC0: using guessed type int (__thiscall *StreamPackObj::vftable)(void *, char);
// 7E6194: using guessed type void *PHashTable<unsigned long,unsigned long>::vftable;
// 7E61AC: using guessed type int (__thiscall *PHashTable<unsigned long,unsigned long>::vftable[2])(void *, char);
// 7E61B0: using guessed type int (__thiscall *RestrictionDB::vftable)(void *, char);

