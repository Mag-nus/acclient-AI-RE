/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : InterfaceSystem
   Object     : CORE\tcom_interface\InterfaceSystem.obj
   Functions  : 25
   Addresses  : 00406090 - 00725B50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00406090) --------------------------------------------------------  // acclient.c:65116
BOOL __stdcall _STL::__less_2<unsigned long,unsigned long>::operator()(const unsigned int *__x, const unsigned int __y)
{
  return *__x < __y;
}

//----- (004060B0) --------------------------------------------------------  // acclient.c:65122
IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *__thiscall IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::vector_deleting_destructor(IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *v2; // esi@1
  HashTableData<Turbine_GUID,Interface *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>Vtbl *)IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7942DC: using guessed type int (__thiscall *IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::vftable[2])(void *, char);

//----- (004060F0) --------------------------------------------------------  // acclient.c:65143
IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *__thiscall IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::begin(IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *this, IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *result)
{
  HashTableData<Turbine_GUID,Interface *> **v2; // edx@1
  HashTableData<Turbine_GUID,Interface *> **v3; // eax@2
  HashTableData<Turbine_GUID,Interface *> **v4; // eax@3
  IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *v5; // eax@4
  HashTableData<Turbine_GUID,Interface *> **v6; // edx@5

  v2 = &this->m_buckets[this->m_numBuckets];
  if ( this->m_firstInterestingBucket == v2 )
  {
LABEL_4:
    v5 = result;
    result->m_currBucket = 0;
    result->m_currElement = 0;
    result->m_currHashTable = this;
  }
  else
  {
    while ( 1 )
    {
      v3 = this->m_firstInterestingBucket;
      if ( *v3 )
        break;
      v4 = v3 + 1;
      this->m_firstInterestingBucket = v4;
      if ( v4 == v2 )
        goto LABEL_4;
    }
    v6 = this->m_firstInterestingBucket;
    v5 = result;
    result->m_currElement = *v6;
    result->m_currBucket = v6;
    result->m_currHashTable = this;
  }
  return v5;
}

//----- (00406140) --------------------------------------------------------  // acclient.c:65182
IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *__thiscall IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::find_internal(IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *this, IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *result, Turbine_GUID *_key)
{
  HashTableData<Turbine_GUID,Interface *> **v3; // ebx@1
  HashTableData<Turbine_GUID,Interface *> *i; // edx@1
  IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *v5; // eax@7

  v3 = &this->m_buckets[_key->m_data1 % this->m_numBuckets];
  for ( i = *v3; i; i = i->m_hashNext )
  {
    if ( i->m_hashKey.m_data1 == _key->m_data1
      && *(_DWORD *)&i->m_hashKey.m_data2 == *(_DWORD *)&_key->m_data2
      && *(_DWORD *)&i->m_hashKey.m_data4[0] == *(_DWORD *)&_key->m_data4[0]
      && *(_DWORD *)&i->m_hashKey.m_data4[4] == *(_DWORD *)&_key->m_data4[4] )
      break;
  }
  v5 = result;
  result->m_currBucket = v3;
  result->m_currHashTable = this;
  result->m_currElement = i;
  return v5;
}

//----- (004061A0) --------------------------------------------------------  // acclient.c:65205
const unsigned int *__cdecl _STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(const unsigned int *__first, const unsigned int *__last, const unsigned int *__val)
{
  const unsigned int *result; // eax@1
  signed int v4; // edx@1
  signed int v5; // ecx@2

  result = __first;
  v4 = __last - __first;
  while ( v4 > 0 )
  {
    v5 = v4 >> 1;
    if ( result[v4 >> 1] >= *__val )
    {
      v4 >>= 1;
    }
    else
    {
      result += v5 + 1;
      v4 += -1 - v5;
    }
  }
  return result;
}

//----- (004061E0) --------------------------------------------------------  // acclient.c:65230
void __thiscall PStringBase<char>::append_string(PStringBase<char> *this, PStringBase<char> *str)
{
  int v2; // edx@1

  v2 = *(_DWORD *)&str->m_charbuffer[-1].m_data[12];
  if ( v2 != 1 )
    PStringBase<char>::append_n_chars(this, str->m_charbuffer->m_data, v2 - 1);
}

//----- (00406200) --------------------------------------------------------  // acclient.c:65240
int PStringBase<char>::sprintf_append(PStringBase<char> *this, const char *fmt, ...)
{
  int v2; // eax@1
  PSRefBufferCharData<char> *v3; // esi@1
  int v4; // edi@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> new_str; // [sp+0h] [bp-4h]@1
  va_list va; // [sp+10h] [bp+Ch]@1

  va_start(va, fmt);
  new_str.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v2 = PStringBase<char>::vsprintf(&new_str, fmt, va);
  v3 = new_str.m_charbuffer;
  v4 = v2;
  v5 = *(_DWORD *)&new_str.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
    PStringBase<char>::append_n_chars(this, new_str.m_charbuffer->m_data, v5 - 1);
  v6 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return v4;
}

//----- (00406270) --------------------------------------------------------  // acclient.c:65266
TResult *__thiscall InterfaceSystem::GetClass(InterfaceSystem *this, TResult *result, Turbine_GUID *_rClassType, Interface **_rpInterface)
{
  TResult *v4; // eax@4
  IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> v5; // [sp+0h] [bp-Ch]@1

  *_rpInterface = 0;
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::find_internal(
    &this->m_classTable.m_intrusiveTable,
    &v5,
    _rClassType);
  if ( v5.m_currElement )
    *_rpInterface = v5.m_currElement->m_data;
  if ( *_rpInterface )
  {
    ((void (*)(void))(*_rpInterface)->vfptr->AddRef)();
    v4 = result;
    result->m_val = 0;
  }
  else
  {
    v4 = result;
    result->m_val = -2147221164;
  }
  return v4;
}

//----- (004062D0) --------------------------------------------------------  // acclient.c:65293
TResult *__thiscall InterfaceSystem::GetClass(InterfaceSystem *this, TResult *result, Turbine_GUID *_rClassType, Turbine_GUID *_rInterfaceType, void **_ppOutInterface)
{
  Interface *v5; // ecx@2
  InterfaceVtbl *v6; // eax@3
  TResult *v7; // eax@4
  IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> v8; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::find_internal(
    &this->m_classTable.m_intrusiveTable,
    &v8,
    _rClassType);
  if ( v8.m_currElement && (v5 = v8.m_currElement->m_data) != 0 )
  {
    v6 = v5->vfptr;
    _rClassType = 0;
    if ( *(_DWORD *)((int (__stdcall *)(Turbine_GUID **, Turbine_GUID *, Turbine_GUID **))v6->QueryInterface)(
                      &_rInterfaceType,
                      _rInterfaceType,
                      &_rClassType) < 0 )
    {
      v7 = result;
      result->m_val = -2147467262;
    }
    else
    {
      *_ppOutInterface = _rClassType;
      v7 = result;
      result->m_val = 0;
    }
  }
  else
  {
    v7 = result;
    result->m_val = -2147221164;
  }
  return v7;
}

//----- (00406350) --------------------------------------------------------  // acclient.c:65332
TResult *__thiscall InterfaceSystem::CreateInstance(InterfaceSystem *this, TResult *result, Turbine_GUID *_rClassType, Turbine_GUID *_rInterfaceType, Interface *_pOuterInterface, void **_ppNewInstance)
{
  void **v6; // ebp@1
  Turbine_GUID *v7; // ST0C_4@1
  TResult *v8; // eax@2
  void **v9; // esi@3
  unsigned int v10; // edi@3
  TResult tr; // [sp+8h] [bp-4h]@1

  v6 = _ppNewInstance;
  v7 = _rClassType;
  *_ppNewInstance = 0;
  _ppNewInstance = 0;
  InterfaceSystem::GetClass(this, &tr, v7, &IObjectFactory_InterfaceType_1, (void **)&_ppNewInstance);
  if ( (tr.m_val & 0x80000000) == 0 )
  {
    v9 = _ppNewInstance;
    _rClassType = 0;
    v10 = *(_DWORD *)(*(int (__thiscall **)(void **, void ***, Interface *, Turbine_GUID *, Turbine_GUID **))((int (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))*_ppNewInstance + 6))(
                       _ppNewInstance,
                       &_ppNewInstance,
                       _pOuterInterface,
                       _rInterfaceType,
                       &_rClassType);
    if ( (v10 & 0x80000000) == 0 )
      *v6 = _rClassType;
    (*((void (__thiscall **)(void **))*v9 + 5))(v9);
    v8 = result;
    result->m_val = v10;
  }
  else
  {
    v8 = result;
    result->m_val = tr.m_val;
  }
  return v8;
}

//----- (004063E0) --------------------------------------------------------  // acclient.c:65371
void __thiscall IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>(IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6
  unsigned int __val; // [sp+0h] [bp-4h]@1

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>Vtbl *)IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  __val = _numBuckets;
  v4 = _STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(
         g_bucketSizesBegin,
         g_bucketSizesEnd,
         &__val);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<Turbine_GUID,Interface *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<Turbine_GUID,Interface *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7942DC: using guessed type int (__thiscall *IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::vftable[2])(void *, char);

//----- (00406480) --------------------------------------------------------  // acclient.c:65409
char __thiscall IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::grow(IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+Ch] [bp-4h]@1

  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(
                         g_bucketSizesBegin,
                         g_bucketSizesEnd,
                         &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::resize_internal(v2, *v3);
}

//----- (004064E0) --------------------------------------------------------  // acclient.c:65429
char __thiscall IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::resize_internal(IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *v2; // esi@1
  char result; // al@2
  HashTableData<Turbine_GUID,Interface *> *v4; // ebp@3
  int v5; // ecx@4
  HashTableData<Turbine_GUID,Interface *> **v6; // eax@5
  int v7; // eax@6
  HashTableData<Turbine_GUID,Interface *> **v8; // ecx@7
  HashTableData<Turbine_GUID,Interface *> *v9; // edi@7
  _BYTE v10[12]; // ST00_12@9
  HashTableData<Turbine_GUID,Interface *> *v11; // edi@12
  HashTableData<Turbine_GUID,Interface *> *v12; // ebp@13
  int v13; // edx@15
  HashTableData<Turbine_GUID,Interface *> **v14; // eax@15
  int v15; // eax@15

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (HashTableData<Turbine_GUID,Interface *> **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (HashTableData<Turbine_GUID,Interface *> **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        *(_QWORD *)&v10[4] = __PAIR__((unsigned int)v9, (unsigned int)v8);
        *(_DWORD *)v10 = v2;
        IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::remove(
          v2,
          *(IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *)v10);
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashTableData<Turbine_GUID,Interface *> **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<int,CAsyncStateHandler *,1>::init(
      (IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *)v2,
      _numBuckets);
    v11 = v4;
    if ( v4 )
    {
      do
      {
        v12 = v11->m_hashNext;
        if ( (signed int)(2 * v2->m_numBuckets) < (signed int)(v2->m_numElements + 1) )
          IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::grow(v2);
        v13 = v11->m_hashKey.m_data1 % v2->m_numBuckets;
        v14 = v2->m_buckets;
        v11->m_hashNext = v14[v13];
        v14[v13] = v11;
        v15 = (int)&v14[v13];
        if ( (HashTableData<Turbine_GUID,Interface *> **)v15 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (HashTableData<Turbine_GUID,Interface *> **)v15;
        ++v2->m_numElements;
        v11 = v12;
      }
      while ( v12 );
    }
    result = 1;
  }
  return result;
}

//----- (004065D0) --------------------------------------------------------  // acclient.c:65525
char __thiscall IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::add(IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *this, HashTableData<Turbine_GUID,Interface *> *data)
{
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *v2; // esi@1
  char v3; // al@2
  unsigned int v4; // edx@5
  HashTableData<Turbine_GUID,Interface *> **v5; // eax@5
  int v6; // eax@5
  IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> result; // [sp+8h] [bp-Ch]@1

  v2 = this;
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::find_internal(
    this,
    &result,
    &data->m_hashKey);
  if ( result.m_currElement )
  {
    v3 = 0;
  }
  else
  {
    if ( (signed int)(2 * v2->m_numBuckets) < (signed int)(v2->m_numElements + 1) )
      IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::grow(v2);
    v4 = data->m_hashKey.m_data1 % v2->m_numBuckets;
    v5 = v2->m_buckets;
    data->m_hashNext = v5[v4];
    v5[v4] = data;
    v6 = (int)&v5[v4];
    if ( (HashTableData<Turbine_GUID,Interface *> **)v6 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashTableData<Turbine_GUID,Interface *> **)v6;
    ++v2->m_numElements;
    v3 = 1;
  }
  return v3;
}

//----- (00406640) --------------------------------------------------------  // acclient.c:65561
char __thiscall HashTable<Turbine_GUID,Interface *,1>::set(HashTable<Turbine_GUID,Interface *,1> *this, Turbine_GUID *_key, Interface *const *_data)
{
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *v3; // edi@1
  char v4; // al@2
  void *v5; // eax@3
  IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> result; // [sp+8h] [bp-Ch]@1

  v3 = &this->m_intrusiveTable;
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::find_internal(
    &this->m_intrusiveTable,
    &result,
    _key);
  if ( result.m_currElement )
  {
    result.m_currElement->m_data = *_data;
    v4 = 1;
  }
  else
  {
    v5 = operator new(0x18u);
    if ( v5 )
    {
      *(_OWORD *)v5 = *_key;
      *((_DWORD *)v5 + 4) = 0;
      *((_DWORD *)v5 + 5) = *_data;
      IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::add(
        v3,
        (HashTableData<Turbine_GUID,Interface *> *)v5);
      v4 = 1;
    }
    else
    {
      IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::add(v3, 0);
      v4 = 1;
    }
  }
  return v4;
}

//----- (004066D0) --------------------------------------------------------  // acclient.c:65601
void __thiscall IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::remove(IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *this, IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> iter)
{
  HashTableData<Turbine_GUID,Interface *> *v2; // eax@1
  HashTableData<Turbine_GUID,Interface *> *v3; // edx@2

  v2 = *iter.m_currBucket;
  if ( *iter.m_currBucket == iter.m_currElement )
    goto LABEL_8;
  do
  {
    v3 = v2;
    v2 = v2->m_hashNext;
  }
  while ( v2 != iter.m_currElement );
  if ( v3 )
  {
    v3->m_hashNext = v2->m_hashNext;
    --this->m_numElements;
  }
  else
  {
LABEL_8:
    *iter.m_currBucket = v2->m_hashNext;
    --this->m_numElements;
  }
}

//----- (00406710) --------------------------------------------------------  // acclient.c:65629
void __thiscall IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::delete_contents(IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *this)
{
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<Turbine_GUID,Interface *> **v3; // eax@3
  int v4; // eax@4
  HashTableData<Turbine_GUID,Interface *> **v5; // edi@5
  void *v6; // ecx@5
  void *v7; // eax@7
  void *v8; // edx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<Turbine_GUID,Interface *> **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_firstInterestingBucket = (HashTableData<Turbine_GUID,Interface *> **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_17;
    do
    {
      v8 = v7;
      v7 = (void *)*((_DWORD *)v7 + 4);
    }
    while ( v7 != v6 );
    if ( v8 )
      *((_DWORD *)v8 + 4) = *((_DWORD *)v7 + 4);
    else
LABEL_17:
      *v5 = (HashTableData<Turbine_GUID,Interface *> *)*((_DWORD *)v7 + 4);
    --v1->m_numElements;
    if ( v6 )
      operator delete(v6);
  }
}

//----- (00406790) --------------------------------------------------------  // acclient.c:65686
TResult *__thiscall InterfaceSystem::RegisterClassA(InterfaceSystem *this, TResult *result, Turbine_GUID *_rClassType, Interface *_pClassObject, Interface **_ppOldClassObject)
{
  Interface *v5; // ebp@1
  HashTable<Turbine_GUID,Interface *,1> *v6; // edi@1
  Interface *v7; // esi@2
  Interface **v8; // ebx@4
  TResult *v9; // eax@12
  IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> v10; // [sp+8h] [bp-Ch]@2

  v5 = _pClassObject;
  v6 = (HashTable<Turbine_GUID,Interface *,1> *)this;
  if ( _pClassObject )
  {
    v7 = 0;
    IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::find_internal(
      &this->m_classTable.m_intrusiveTable,
      &v10,
      _rClassType);
    if ( v10.m_currElement )
      v7 = v10.m_currElement->m_data;
    v8 = _ppOldClassObject;
    if ( _ppOldClassObject )
    {
      if ( v7 )
        v7->vfptr->AddRef(v7);
      *v8 = v7;
    }
    if ( v7 != v5 )
    {
      if ( v7 )
        v7->vfptr->Release(v7);
      v5->vfptr->AddRef(v5);
      HashTable<Turbine_GUID,Interface *,1>::set(v6, _rClassType, &_pClassObject);
    }
    v9 = result;
    result->m_val = 0;
  }
  else
  {
    v9 = result;
    result->m_val = -2147467259;
  }
  return v9;
}

//----- (00406830) --------------------------------------------------------  // acclient.c:65732
HashTableData<Turbine_GUID,Interface *> *__thiscall IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::remove(IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *this, Turbine_GUID *key)
{
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *v2; // esi@1
  HashTableData<Turbine_GUID,Interface *> *v3; // edi@1
  _BYTE v4[12]; // ST00_12@2
  HashTableData<Turbine_GUID,Interface *> *result; // eax@2
  IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> iter; // [sp+Ch] [bp-Ch]@1

  v2 = this;
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::find_internal(this, &iter, key);
  v3 = iter.m_currElement;
  if ( iter.m_currElement )
  {
    *(_QWORD *)&v4[4] = *(_QWORD *)&iter.m_currBucket;
    *(_DWORD *)v4 = iter.m_currHashTable;
    IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::remove(
      v2,
      *(IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *)v4);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00406890) --------------------------------------------------------  // acclient.c:65760
void __thiscall InterfaceSystem::~InterfaceSystem(InterfaceSystem *this)
{
  InterfaceSystem *v1; // ebp@1
  char *v2; // ebx@1
  IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *v3; // eax@1
  HashTableData<Turbine_GUID,Interface *> *v4; // esi@1
  HashTableData<Turbine_GUID,Interface *> **v5; // edi@1
  void *v6; // eax@6
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *i; // [sp+10h] [bp-18h]@1
  IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> result; // [sp+1Ch] [bp-Ch]@1

  v1 = this;
  v2 = (char *)&this->m_classTable.m_intrusiveTable;
  v3 = IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::begin(
         &this->m_classTable.m_intrusiveTable,
         &result);
  v4 = v3->m_currElement;
  v5 = v3->m_currBucket;
  i = v3->m_currHashTable;
  if ( v4 )
  {
    do
    {
LABEL_2:
      ((void (*)(void))v4->m_data->vfptr->Release)();
      v4 = v4->m_hashNext;
    }
    while ( v4 );
    while ( 1 )
    {
      ++v5;
      if ( v5 == &i->m_buckets[i->m_numBuckets] )
        break;
      if ( *v5 )
      {
        v4 = *v5;
        if ( *v5 )
          goto LABEL_2;
        break;
      }
    }
  }
  v1->m_classTable.vfptr = (HashTable<Turbine_GUID,Interface *,1>Vtbl *)&HashTable<Turbine_GUID,Interface *,1>::vftable;
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::delete_contents((IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *)v2);
  v6 = (void *)*((_DWORD *)v2 + 24);
  *(_DWORD *)v2 = IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::vftable;
  if ( v6 != v2 + 4 )
    operator delete[](v6);
  *((_DWORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 25) = 0;
  *((_DWORD *)v2 + 26) = 0;
  *((_DWORD *)v2 + 27) = 0;
}
// 7942DC: using guessed type int (__thiscall *IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::vftable[2])(void *, char);
// 7942E0: using guessed type int (__thiscall *HashTable<Turbine_GUID,Interface *,1>::vftable)(void *, char);

//----- (00406930) --------------------------------------------------------  // acclient.c:65817
TResult *__thiscall InterfaceSystem::UnregisterClassA(InterfaceSystem *this, TResult *result, Turbine_GUID *_rClassType, Interface *_pCurClassObject, Interface **_ppOldClassObject)
{
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *v5; // edi@1
  Interface *v6; // esi@1
  HashTableData<Turbine_GUID,Interface *> *v7; // eax@7
  TResult *v8; // eax@11
  IntrusiveHashIterator<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> v9; // [sp+Ch] [bp-Ch]@1

  v5 = &this->m_classTable.m_intrusiveTable;
  v6 = 0;
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::find_internal(
    &this->m_classTable.m_intrusiveTable,
    &v9,
    _rClassType);
  if ( v9.m_currElement )
    v6 = v9.m_currElement->m_data;
  if ( _ppOldClassObject )
  {
    *_ppOldClassObject = v6;
    v6->vfptr->AddRef(v6);
  }
  if ( !_pCurClassObject || v6 == _pCurClassObject )
  {
    v7 = IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::remove(v5, _rClassType);
    if ( v7 )
      operator delete(v7);
    if ( v6 )
      v6->vfptr->Release(v6);
  }
  v8 = result;
  result->m_val = 0;
  return v8;
}

//----- (004069B0) --------------------------------------------------------  // acclient.c:65852
AutoGrowHashTable<Turbine_GUID,Interface *> *__thiscall AutoGrowHashTable<Turbine_GUID,Interface *>::vector_deleting_destructor(AutoGrowHashTable<Turbine_GUID,Interface *> *this, unsigned int a2)
{
  AutoGrowHashTable<Turbine_GUID,Interface *> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<Turbine_GUID,Interface *,1>Vtbl *)&HashTable<Turbine_GUID,Interface *,1>::vftable;
  IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::vftable;
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
// 7942DC: using guessed type int (__thiscall *IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::vftable[2])(void *, char);
// 7942E0: using guessed type int (__thiscall *HashTable<Turbine_GUID,Interface *,1>::vftable)(void *, char);

//----- (00406A10) --------------------------------------------------------  // acclient.c:65878
InterfaceSystem *__cdecl InterfaceSystem::GetInstance()
{
  InterfaceSystem *result; // eax@2
  void *v1; // eax@4
  InterfaceSystem *v2; // esi@4

  if ( InterfaceSystem::s_bInterfaceSystemDestroyed )
  {
    result = 0;
  }
  else
  {
    result = InterfaceSystem::s_pInterfaceSystem;
    if ( !InterfaceSystem::s_pInterfaceSystem )
    {
      v1 = operator new(0x74u);
      v2 = (InterfaceSystem *)v1;
      if ( v1 )
      {
        *(_DWORD *)v1 = &HashTable<Turbine_GUID,Interface *,1>::vftable;
        IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>(
          (IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1> *)((char *)v1 + 4),
          0);
        result = v2;
        v2->m_classTable.vfptr = (HashTable<Turbine_GUID,Interface *,1>Vtbl *)&HashTable<Turbine_GUID,Interface *,1>::vftable;
        InterfaceSystem::s_pInterfaceSystem = v2;
      }
      else
      {
        result = 0;
        InterfaceSystem::s_pInterfaceSystem = 0;
      }
    }
  }
  return result;
}
// 7942E0: using guessed type int (__thiscall *HashTable<Turbine_GUID,Interface *,1>::vftable)(void *, char);
// 836744: using guessed type bool InterfaceSystem::s_bInterfaceSystemDestroyed;

//----- (006C3950) --------------------------------------------------------  // acclient.c:731992
int _E73_2()
{
  return atexit(_E74_4);
}

//----- (00725B50) --------------------------------------------------------  // acclient.c:823511
void __cdecl _E74_4()
{
  InterfaceSystem *v0; // esi@2

  if ( InterfaceSystem::s_pInterfaceSystem )
  {
    v0 = InterfaceSystem::s_pInterfaceSystem;
    InterfaceSystem::~InterfaceSystem(InterfaceSystem::s_pInterfaceSystem);
    operator delete(v0);
    InterfaceSystem::s_pInterfaceSystem = 0;
    InterfaceSystem::s_bInterfaceSystemDestroyed = 1;
  }
}
// 836744: using guessed type bool InterfaceSystem::s_bInterfaceSystemDestroyed;

