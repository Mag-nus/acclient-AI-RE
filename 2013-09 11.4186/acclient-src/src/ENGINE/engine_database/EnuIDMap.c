/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : EnuIDMap
   Object     : ENGINE\engine_database\EnuIDMap.obj
   Functions  : 27
   Addresses  : 00415590 - 006C4980 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00415590) --------------------------------------------------------  // acclient.c:81754
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char> > *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char> > *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char> > *,0> *v2; // esi@1
  HashTableData<unsigned long,PStringBase<char> > **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char> > *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::vftable;
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
// 795294: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::vftable[4])(void *, char);

//----- (004155D0) --------------------------------------------------------  // acclient.c:81775
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *,0> *v2; // esi@1
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vftable;
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
// 795298: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vftable[3])(void *, char);

//----- (00415610) --------------------------------------------------------  // acclient.c:81796
void __thiscall SmartArray<IDClass<_tagDataID,32,0>,1>::Reset(SmartArray<IDClass<_tagDataID,32,0>,1> *this)
{
  SmartArray<IDClass<_tagDataID,32,0>,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int i; // eax@6
  SmartArray<IDClass<_tagDataID,32,0>,1> *v5; // [sp+0h] [bp-4h]@1

  v5 = this;
  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      operator delete[](&v1->m_data[-1]);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    for ( i = (v2 & 0x7FFFFFFF) - 1; i >= 0; v1->m_data[i + 1].id = (unsigned int)v5 )
      --i;
  }
}

//----- (00415670) --------------------------------------------------------  // acclient.c:81824
char __thiscall SmartArray<IDClass<_tagDataID,32,0>,1>::grow(SmartArray<IDClass<_tagDataID,32,0>,1> *this, unsigned int i_nSize)
{
  SmartArray<IDClass<_tagDataID,32,0>,1> *v2; // esi@1
  void *v4; // eax@5
  int v5; // ebx@6
  int i; // eax@8

  v2 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<IDClass<_tagDataID,32,0>,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](4 * i_nSize + 4);
    if ( v4 )
    {
      v5 = (int)((char *)v4 + 4);
      *(_DWORD *)v4 = i_nSize;
      vector_constructor_iterator(
        (char *)v4 + 4,
        4u,
        i_nSize,
        (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
      if ( v5 )
      {
        if ( v2->m_data )
        {
          for ( i = v2->m_num - 1; i >= 0; *(_DWORD *)(v5 + 4 * i + 4) = v2->m_data[i + 1].id )
            --i;
          if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v2->m_data )
              operator delete[](&v2->m_data[-1]);
          }
        }
        v2->m_data = (IDClass<_tagDataID,32,0> *)v5;
        v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (00415730) --------------------------------------------------------  // acclient.c:81873
char __thiscall EnumIDMap::NameToEnum(EnumIDMap *this, PStringBase<char> *_Name, unsigned int *o_iEnum)
{
  EnumIDMap *v3; // ebx@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v6; // ebp@1
  HashTableData<unsigned long,HeritageGroup_CG> **v7; // edi@1
  int v8; // ecx@7
  HashTableData<unsigned long,PStringBase<char> > **v9; // eax@8
  int v10; // eax@9
  HashTableData<unsigned long,PStringBase<char> > **v11; // eax@10
  HashTableData<unsigned long,PStringBase<char> > *v12; // esi@10
  HashTableData<unsigned long,PStringBase<char> > **v14; // edi@13
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@1

  v3 = this;
  v4 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_EnumToName.m_intrusiveTable,
         &result);
  v5 = v4->m_currElement;
  v6 = v4->m_currHashTable;
  v7 = v4->m_currBucket;
  if ( v5 )
  {
    do
    {
LABEL_2:
      if ( !__stricmp(_Name->m_charbuffer->m_data, (const char *)v5->m_data.vfptr) )
      {
        *o_iEnum = v5->m_hashKey;
        return 1;
      }
      v5 = v5->m_hashNext;
    }
    while ( v5 );
    while ( 1 )
    {
      ++v7;
      if ( v7 == &v6->m_buckets[v6->m_numBuckets] )
        break;
      if ( *v7 )
      {
        v5 = *v7;
        if ( *v7 )
          goto LABEL_2;
        break;
      }
    }
  }
  v8 = (int)&v3->m_EnumToNameInternal.m_intrusiveTable.m_buckets[v3->m_EnumToNameInternal.m_intrusiveTable.m_numBuckets];
  if ( v3->m_EnumToNameInternal.m_intrusiveTable.m_firstInterestingBucket == (HashTableData<unsigned long,PStringBase<char> > **)v8 )
  {
LABEL_10:
    v11 = 0;
    v12 = 0;
  }
  else
  {
    while ( 1 )
    {
      v9 = v3->m_EnumToNameInternal.m_intrusiveTable.m_firstInterestingBucket;
      if ( *v9 )
        break;
      v10 = (int)(v9 + 1);
      v3->m_EnumToNameInternal.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<unsigned long,PStringBase<char> > **)v10;
      if ( v10 == v8 )
        goto LABEL_10;
    }
    v11 = v3->m_EnumToNameInternal.m_intrusiveTable.m_firstInterestingBucket;
    v12 = *v11;
  }
  v14 = v11;
  if ( v12 )
  {
    do
    {
LABEL_14:
      if ( !__stricmp(_Name->m_charbuffer->m_data, v12->m_data.m_charbuffer->m_data) )
      {
        *o_iEnum = v12->m_hashKey;
        return 1;
      }
      v12 = v12->m_hashNext;
    }
    while ( v12 );
    while ( 1 )
    {
      ++v14;
      if ( v14 == &v3->m_EnumToNameInternal.m_intrusiveTable.m_buckets[v3->m_EnumToNameInternal.m_intrusiveTable.m_numBuckets] )
        break;
      if ( *v14 )
      {
        v12 = *v14;
        if ( *v14 )
          goto LABEL_14;
        return 0;
      }
    }
  }
  return 0;
}

//----- (00415860) --------------------------------------------------------  // acclient.c:81976
void __thiscall EnumIDMap::GetSubDataIDs(EnumIDMap *this, QualifiedDataIDArray *IDs)
{
  EnumIDMap *v2; // ebx@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v4; // esi@1
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edi@1
  QualifiedDataID *v6; // eax@2
  int v7; // ecx@6
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **v8; // eax@7
  int v9; // eax@8
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **v10; // eax@9
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *v11; // esi@9
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **v12; // edi@11
  QualifiedDataID *v13; // eax@12
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-18h]@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v15; // [sp+1Ch] [bp-Ch]@1

  v2 = this;
  v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_EnumToID.m_intrusiveTable,
         &result);
  v4 = v3->m_currElement;
  v5 = v3->m_currBucket;
  v15 = v3->m_currHashTable;
  if ( v4 )
  {
    do
    {
LABEL_2:
      QualifiedDataID::QualifiedDataID((QualifiedDataID *)&result, (IDClass<_tagDataID,32,0>)v4->m_data.vfptr, 0);
      QualifiedDataIDArray::AddQDID(IDs, v6, 0);
      v4 = v4->m_hashNext;
    }
    while ( v4 );
    while ( 1 )
    {
      ++v5;
      if ( v5 == &v15->m_buckets[v15->m_numBuckets] )
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
  v7 = (int)&v2->m_EnumToIDInternal.m_intrusiveTable.m_buckets[v2->m_EnumToIDInternal.m_intrusiveTable.m_numBuckets];
  if ( v2->m_EnumToIDInternal.m_intrusiveTable.m_firstInterestingBucket == (HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **)v7 )
  {
LABEL_9:
    v10 = 0;
    v11 = 0;
  }
  else
  {
    while ( 1 )
    {
      v8 = v2->m_EnumToIDInternal.m_intrusiveTable.m_firstInterestingBucket;
      if ( *v8 )
        break;
      v9 = (int)(v8 + 1);
      v2->m_EnumToIDInternal.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **)v9;
      if ( v9 == v7 )
        goto LABEL_9;
    }
    v10 = v2->m_EnumToIDInternal.m_intrusiveTable.m_firstInterestingBucket;
    v11 = *v10;
  }
  v12 = v10;
  if ( v11 )
  {
    do
    {
LABEL_12:
      QualifiedDataID::QualifiedDataID((QualifiedDataID *)&result, v11->m_data, 0);
      QualifiedDataIDArray::AddQDID(IDs, v13, 2u);
      v11 = v11->m_hashNext;
    }
    while ( v11 );
    while ( 1 )
    {
      ++v12;
      if ( v12 == &v2->m_EnumToIDInternal.m_intrusiveTable.m_buckets[v2->m_EnumToIDInternal.m_intrusiveTable.m_numBuckets] )
        break;
      if ( *v12 )
      {
        v11 = *v12;
        if ( *v12 )
          goto LABEL_12;
        return;
      }
    }
  }
}

//----- (00415970) --------------------------------------------------------  // acclient.c:82074
signed int __thiscall EnumIDMap::EnumToDID(EnumIDMap *this, const unsigned int i_iEnum, IDClass<_tagDataID,32,0> *o_cDataID)
{
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *v3; // eax@1

  v3 = this->m_EnumToID.m_intrusiveTable.m_buckets[i_iEnum % this->m_EnumToID.m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_6;
  while ( v3->m_hashKey != i_iEnum )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_6;
  }
  if ( !v3 )
  {
LABEL_6:
    v3 = this->m_EnumToIDInternal.m_intrusiveTable.m_buckets[i_iEnum
                                                           % this->m_EnumToIDInternal.m_intrusiveTable.m_numBuckets];
    if ( !v3 )
      return 0;
    while ( v3->m_hashKey != i_iEnum )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        return 0;
    }
    if ( !v3 )
      return 0;
  }
  o_cDataID->id = v3->m_data.id;
  return 1;
}

//----- (004159F0) --------------------------------------------------------  // acclient.c:82108
BOOL __thiscall EnumIDMap::GetName(EnumIDMap *this, const unsigned int i_iEnum, PStringBase<char> *o_rcName)
{
  PStringBase<char> *v3; // edi@1
  EnumIDMap *v4; // esi@1

  v3 = o_rcName;
  v4 = this;
  return HashTable<unsigned long,PStringBase<unsigned short>,0>::find(
           (HashTable<unsigned long,PStringBase<unsigned short>,0> *)&this->m_EnumToName,
           &i_iEnum,
           (PStringBase<unsigned short> *)o_rcName)
      || HashTable<unsigned long,PStringBase<unsigned short>,0>::find(
           (HashTable<unsigned long,PStringBase<unsigned short>,0> *)&v4->m_EnumToNameInternal,
           &i_iEnum,
           (PStringBase<unsigned short> *)v3);
}

//----- (00415A40) --------------------------------------------------------  // acclient.c:82126
char __thiscall DualEnumIDMap::DIDToEnum(DualEnumIDMap *this, IDClass<_tagDataID,32,0> _ID, unsigned int *o_iEnum)
{
  HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *v3; // eax@1
  char result; // al@4

  v3 = this->m_IDToEnum.m_intrusiveTable.m_buckets[_ID.id % this->m_IDToEnum.m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.id != _ID.id )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    *o_iEnum = v3->m_data;
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00415A90) --------------------------------------------------------  // acclient.c:82154
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char> > *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char> > *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char> > *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,PStringBase<char> > **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,PStringBase<char> > **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 795294: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::vftable[4])(void *, char);

//----- (00415B20) --------------------------------------------------------  // acclient.c:82187
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 795298: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vftable[3])(void *, char);

//----- (00415C60) --------------------------------------------------------  // acclient.c:82286
void __cdecl SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,SB_Default>(const int *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *,0> *io_object, Archive *io_archive)
{
  Archive *v3; // esi@1
  unsigned int *v4; // edi@4
  unsigned int *v5; // ebp@4
  const unsigned int *v6; // eax@4
  int v7; // ebx@6
  unsigned int v8; // eax@8
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // eax@19
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // ebx@19
  HashTableData<unsigned long,HeritageGroup_CG> *v11; // edi@19
  HashTableData<unsigned long,HeritageGroup_CG> **v12; // ebp@19
  unsigned int v13; // eax@21
  unsigned int v14; // eax@25
  unsigned int v15; // eax@34
  HashTableData<unsigned long,Sex_CG> *v16; // ebx@35
  unsigned int v17; // ebp@35
  void *v18; // eax@36
  void *v19; // edi@36
  unsigned int v20; // eax@38
  unsigned int v21; // eax@42
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@19

  v3 = io_archive;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::clear((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object);
  if ( (v3->m_flags & 5) == 1 )
  {
    v4 = g_bucketSizesEnd;
    v5 = g_bucketSizesBegin;
    io_archive = (Archive *)io_object->m_numBuckets;
    v6 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, (const unsigned int *)&io_archive);
    if ( v6 == v4 )
      --v6;
    v7 = v6 - v5;
  }
  else
  {
    LOBYTE(v7) = (_BYTE)io_archive;
  }
  Archive::CheckAlignment(v3, 1u);
  v8 = Archive::GetBytes(v3, 1u);
  if ( v8 )
  {
    if ( v3->m_flags & 1 )
      *(_BYTE *)v8 = v7;
    else
      LOBYTE(v7) = *(_BYTE *)v8;
  }
  if ( !(v3->m_flags & 5) )
  {
    if ( (unsigned __int8)v7 < g_numBucketSizes )
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::resize(
        (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
        g_bucketSizesBegin[(unsigned __int8)v7]);
    else
      Archive::RaiseError(v3);
  }
  if ( (v3->m_flags & 5) == 1 )
    io_archive = (Archive *)io_object->m_numElements;
  SB_As32Bit_Compressed::Serialize((const int *)&io_archive, (unsigned int *)&io_archive, v3);
  if ( (v3->m_flags & 5) == 1 )
  {
    v9 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)io_object,
           &result);
    v10 = v9->m_currHashTable;
    v11 = v9->m_currElement;
    v12 = v9->m_currBucket;
LABEL_20:
    while ( v11 )
    {
      do
      {
        Archive::CheckAlignment(v3, 4u);
        v13 = Archive::GetBytes(v3, 4u);
        if ( v13 )
        {
          if ( v3->m_flags & 1 )
            *(_DWORD *)v13 = v11->m_hashKey;
          else
            v11->m_hashKey = *(_DWORD *)v13;
        }
        Archive::CheckAlignment(v3, 4u);
        v14 = Archive::GetBytes(v3, 4u);
        if ( v14 )
        {
          if ( v3->m_flags & 1 )
            *(_DWORD *)v14 = v11->m_data.vfptr;
          else
            v11->m_data.vfptr = *(HeritageGroup_CGVtbl **)v14;
        }
        v11 = v11->m_hashNext;
      }
      while ( v11 );
      while ( 1 )
      {
        ++v12;
        if ( v12 == &v10->m_buckets[v10->m_numBuckets] )
          break;
        if ( *v12 )
        {
          v11 = *v12;
          goto LABEL_20;
        }
      }
    }
  }
  if ( !(v3->m_flags & 5) )
  {
    v15 = Archive::GetSizeLeft(v3);
    if ( (unsigned int)io_archive > v15 )
    {
LABEL_50:
      Archive::RaiseError(v3);
    }
    else
    {
      v16 = 0;
      v17 = 0;
      if ( io_archive )
      {
        do
        {
          v18 = operator new(0xCu);
          v19 = 0;
          if ( v18 )
          {
            *((_DWORD *)v18 + 1) = 0;
            v19 = v18;
          }
          Archive::CheckAlignment(v3, 4u);
          v20 = Archive::GetBytes(v3, 4u);
          if ( v20 )
          {
            if ( v3->m_flags & 1 )
              *(_DWORD *)v20 = *(_DWORD *)v19;
            else
              *(_DWORD *)v19 = *(_DWORD *)v20;
          }
          Archive::CheckAlignment(v3, 4u);
          v21 = Archive::GetBytes(v3, 4u);
          if ( v21 )
          {
            if ( v3->m_flags & 1 )
              *(_DWORD *)v21 = *((_DWORD *)v19 + 2);
            else
              *((_DWORD *)v19 + 2) = *(_DWORD *)v21;
          }
          if ( (v3->m_flags >> 2) & 1 )
            break;
          if ( !IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
                  (HashTableData<unsigned long,Sex_CG> *)v19,
                  v16) )
            goto LABEL_50;
          ++v17;
          v16 = (HashTableData<unsigned long,Sex_CG> *)v19;
        }
        while ( v17 < (unsigned int)io_archive );
      }
    }
  }
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;

//----- (00415EB0) --------------------------------------------------------  // acclient.c:82453
void __thiscall EnumIDMap::Destroy(EnumIDMap *this)
{
  EnumIDMap *v1; // esi@1

  v1 = this;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_EnumToID.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *)&v1->m_EnumToName.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_EnumToIDInternal.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *)&v1->m_EnumToNameInternal.m_intrusiveTable);
}

//----- (00415EE0) --------------------------------------------------------  // acclient.c:82465
char __thiscall DualEnumIDMap::InitLoad(DualEnumIDMap *this)
{
  DualEnumIDMap *v1; // esi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  void *v3; // edi@1
  void *v4; // eax@2
  void *v5; // ebp@2
  int v6; // edx@3
  int v7; // ecx@4
  int v8; // eax@4
  char v9; // bl@11
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **v10; // ecx@14
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **v11; // eax@15
  int v12; // ecx@18
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **v13; // eax@19
  int v14; // eax@20
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **v15; // eax@21
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *v16; // edi@21
  void *v17; // eax@24
  void *v18; // ebp@24
  unsigned int v19; // ecx@25
  int v20; // ecx@26
  int v21; // eax@26
  char v22; // bl@33
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **v23; // ecx@36
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **v24; // eax@37
  char fEverythingWorked; // [sp+13h] [bp-19h]@1
  HashIterator<unsigned long,IDClass<_tagDataID,32,0>,0> iterator; // [sp+14h] [bp-18h]@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v28; // [sp+20h] [bp-Ch]@1

  v1 = this;
  fEverythingWorked = 1;
  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_EnumToID.m_intrusiveTable,
         (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&iterator);
  v3 = v2->m_currElement;
  v28 = v2->m_currHashTable;
  iterator.m_iter.m_currBucket = (HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **)v2->m_currBucket;
  if ( v3 )
  {
    do
    {
LABEL_2:
      v4 = operator new(0xCu);
      v5 = 0;
      if ( v4 )
      {
        v6 = *((_DWORD *)v3 + 2);
        *((_DWORD *)v4 + 1) = 0;
        *(_DWORD *)v4 = v6;
        *((_DWORD *)v4 + 2) = *(_DWORD *)v3;
        v5 = v4;
      }
      v7 = (int)&v1->m_IDToEnum.m_intrusiveTable.m_buckets[*(_DWORD *)v5 % v1->m_IDToEnum.m_intrusiveTable.m_numBuckets];
      v8 = *(_DWORD *)v7;
      if ( !*(_DWORD *)v7 )
        goto LABEL_9;
      while ( *(_DWORD *)v8 != *(_DWORD *)v5 )
      {
        v8 = *(_DWORD *)(v8 + 4);
        if ( !v8 )
          goto LABEL_9;
      }
      if ( v8 )
      {
        operator delete(v5);
        v9 = 0;
        IError::ReportDataErrorFrom(v1->m_DID, "DataID 0x%08X used multiple times.", *((_DWORD *)v3 + 2));
      }
      else
      {
LABEL_9:
        *((_DWORD *)v5 + 1) = *(_DWORD *)v7;
        *(_DWORD *)v7 = v5;
        if ( (HashTableData<IDClass<_tagDataID,32,0>,unsigned long> **)v7 < v1->m_IDToEnum.m_intrusiveTable.m_firstInterestingBucket )
          v1->m_IDToEnum.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,unsigned long> **)v7;
        ++v1->m_IDToEnum.m_intrusiveTable.m_numElements;
        v9 = 1;
      }
      v3 = (void *)*((_DWORD *)v3 + 1);
      fEverythingWorked &= v9;
    }
    while ( v3 );
    v10 = (HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **)&v28->m_buckets[v28->m_numBuckets];
    while ( 1 )
    {
      v11 = iterator.m_iter.m_currBucket + 1;
      ++iterator.m_iter.m_currBucket;
      if ( iterator.m_iter.m_currBucket == v10 )
        break;
      if ( *v11 )
      {
        v3 = *v11;
        if ( *v11 )
          goto LABEL_2;
        break;
      }
    }
  }
  v12 = (int)&v1->m_EnumToIDInternal.m_intrusiveTable.m_buckets[v1->m_EnumToIDInternal.m_intrusiveTable.m_numBuckets];
  if ( v1->m_EnumToIDInternal.m_intrusiveTable.m_firstInterestingBucket == (HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **)v12 )
  {
LABEL_21:
    v15 = 0;
    v16 = 0;
  }
  else
  {
    while ( 1 )
    {
      v13 = v1->m_EnumToIDInternal.m_intrusiveTable.m_firstInterestingBucket;
      if ( *v13 )
        break;
      v14 = (int)(v13 + 1);
      v1->m_EnumToIDInternal.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<unsigned long,IDClass<_tagDataID,32,0> > **)v14;
      if ( v14 == v12 )
        goto LABEL_21;
    }
    v15 = v1->m_EnumToIDInternal.m_intrusiveTable.m_firstInterestingBucket;
    v16 = *v15;
  }
  iterator.m_iter.m_currBucket = v15;
  if ( v16 )
  {
    do
    {
LABEL_24:
      v17 = operator new(0xCu);
      v18 = 0;
      if ( v17 )
      {
        v19 = v16->m_data.id;
        *((_DWORD *)v17 + 1) = 0;
        *(_DWORD *)v17 = v19;
        *((_DWORD *)v17 + 2) = v16->m_hashKey;
        v18 = v17;
      }
      v20 = (int)&v1->m_IDToEnum.m_intrusiveTable.m_buckets[*(_DWORD *)v18
                                                          % v1->m_IDToEnum.m_intrusiveTable.m_numBuckets];
      v21 = *(_DWORD *)v20;
      if ( !*(_DWORD *)v20 )
        goto LABEL_31;
      while ( *(_DWORD *)v21 != *(_DWORD *)v18 )
      {
        v21 = *(_DWORD *)(v21 + 4);
        if ( !v21 )
          goto LABEL_31;
      }
      if ( v21 )
      {
        operator delete(v18);
        v22 = 0;
        IError::ReportDataErrorFrom(v1->m_DID, "DataID 0x%08X used multiple times.", v16->m_data.id);
      }
      else
      {
LABEL_31:
        *((_DWORD *)v18 + 1) = *(_DWORD *)v20;
        *(_DWORD *)v20 = v18;
        if ( (HashTableData<IDClass<_tagDataID,32,0>,unsigned long> **)v20 < v1->m_IDToEnum.m_intrusiveTable.m_firstInterestingBucket )
          v1->m_IDToEnum.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,unsigned long> **)v20;
        ++v1->m_IDToEnum.m_intrusiveTable.m_numElements;
        v22 = 1;
      }
      v16 = v16->m_hashNext;
      fEverythingWorked &= v22;
    }
    while ( v16 );
    v23 = &v1->m_EnumToIDInternal.m_intrusiveTable.m_buckets[v1->m_EnumToIDInternal.m_intrusiveTable.m_numBuckets];
    while ( 1 )
    {
      v24 = iterator.m_iter.m_currBucket + 1;
      ++iterator.m_iter.m_currBucket;
      if ( iterator.m_iter.m_currBucket == v23 )
        break;
      if ( *v24 )
      {
        v16 = *v24;
        if ( *v24 )
          goto LABEL_24;
        return fEverythingWorked;
      }
    }
  }
  return fEverythingWorked;
}

//----- (00416110) --------------------------------------------------------  // acclient.c:82653
HashTable<unsigned long,PStringBase<char>,0> *__thiscall HashTable<unsigned long,PStringBase<char>,0>::vector_deleting_destructor(HashTable<unsigned long,PStringBase<char>,0> *this, unsigned int a2)
{
  HashTable<unsigned long,PStringBase<char>,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,PStringBase<char>,0>Vtbl *)HashTable<unsigned long,PStringBase<char>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::vftable;
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
// 795294: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::vftable[4])(void *, char);
// 79529C: using guessed type int (__thiscall *HashTable<unsigned long,PStringBase<char>,0>::vftable[2])(void *, char);

//----- (00416170) --------------------------------------------------------  // acclient.c:82679
HashTable<unsigned long,IDClass<_tagDataID,32,0>,0> *__thiscall HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::scalar_deleting_destructor(HashTable<unsigned long,IDClass<_tagDataID,32,0>,0> *this, unsigned int a2)
{
  HashTable<unsigned long,IDClass<_tagDataID,32,0>,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>Vtbl *)&HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vftable;
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
// 795298: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vftable[3])(void *, char);
// 7952A0: using guessed type int (__thiscall *HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::vftable)(void *, char);

//----- (004161D0) --------------------------------------------------------  // acclient.c:82705
void __cdecl SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>,HashTableData<unsigned long,PStringBase<char>> *,SB_Default>(const int *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char> > *,0> *io_object, Archive *io_archive)
{
  Archive *v3; // edi@1
  unsigned int *v4; // esi@4
  unsigned int *v5; // ebp@4
  const unsigned int *v6; // eax@4
  int v7; // ebx@6
  unsigned int v8; // eax@8
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // eax@19
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // ebx@19
  HashTableData<unsigned long,HeritageGroup_CG> *v11; // esi@19
  HashTableData<unsigned long,HeritageGroup_CG> **v12; // ebp@19
  unsigned int v13; // eax@21
  unsigned int v14; // eax@30
  HashTableData<unsigned long,Sex_CG> *v15; // ebx@31
  unsigned int v16; // ebp@31
  void *v17; // eax@32
  void *v18; // esi@32
  volatile LONG *v19; // ST10_4@33
  unsigned int v20; // eax@35
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@19

  v3 = io_archive;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::clear((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object);
  if ( (v3->m_flags & 5) == 1 )
  {
    v4 = g_bucketSizesEnd;
    v5 = g_bucketSizesBegin;
    io_archive = (Archive *)io_object->m_numBuckets;
    v6 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, (const unsigned int *)&io_archive);
    if ( v6 == v4 )
      --v6;
    v7 = v6 - v5;
  }
  else
  {
    LOBYTE(v7) = (_BYTE)io_archive;
  }
  Archive::CheckAlignment(v3, 1u);
  v8 = Archive::GetBytes(v3, 1u);
  if ( v8 )
  {
    if ( v3->m_flags & 1 )
      *(_BYTE *)v8 = v7;
    else
      LOBYTE(v7) = *(_BYTE *)v8;
  }
  if ( !(v3->m_flags & 5) )
  {
    if ( (unsigned __int8)v7 < g_numBucketSizes )
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::resize(
        (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
        g_bucketSizesBegin[(unsigned __int8)v7]);
    else
      Archive::RaiseError(v3);
  }
  if ( (v3->m_flags & 5) == 1 )
    io_archive = (Archive *)io_object->m_numElements;
  SB_As32Bit_Compressed::Serialize((const int *)&io_archive, (unsigned int *)&io_archive, v3);
  if ( (v3->m_flags & 5) == 1 )
  {
    v9 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)io_object,
           &result);
    v10 = v9->m_currHashTable;
    v11 = v9->m_currElement;
    v12 = v9->m_currBucket;
LABEL_20:
    while ( v11 )
    {
      do
      {
        Archive::CheckAlignment(v3, 4u);
        v13 = Archive::GetBytes(v3, 4u);
        if ( v13 )
        {
          if ( v3->m_flags & 1 )
            *(_DWORD *)v13 = v11->m_hashKey;
          else
            v11->m_hashKey = *(_DWORD *)v13;
        }
        PStringBase<char>::Serialize((PStringBase<char> *)&v11->m_data, v3);
        v11 = v11->m_hashNext;
      }
      while ( v11 );
      while ( 1 )
      {
        ++v12;
        if ( v12 == &v10->m_buckets[v10->m_numBuckets] )
          break;
        if ( *v12 )
        {
          v11 = *v12;
          goto LABEL_20;
        }
      }
    }
  }
  if ( !(v3->m_flags & 5) )
  {
    v14 = Archive::GetSizeLeft(v3);
    if ( (unsigned int)io_archive > v14 )
    {
LABEL_43:
      Archive::RaiseError(v3);
    }
    else
    {
      v15 = 0;
      v16 = 0;
      if ( io_archive )
      {
        do
        {
          v17 = operator new(0xCu);
          v18 = v17;
          if ( v17 )
          {
            *((_DWORD *)v17 + 1) = 0;
            v19 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
            *((_DWORD *)v17 + 2) = PStringBase<char>::s_NullBuffer.m_charbuffer;
            InterlockedIncrement(v19);
          }
          else
          {
            v18 = 0;
          }
          Archive::CheckAlignment(v3, 4u);
          v20 = Archive::GetBytes(v3, 4u);
          if ( v20 )
          {
            if ( v3->m_flags & 1 )
              *(_DWORD *)v20 = *(_DWORD *)v18;
            else
              *(_DWORD *)v18 = *(_DWORD *)v20;
          }
          PStringBase<char>::Serialize((PStringBase<char> *)v18 + 2, v3);
          if ( (v3->m_flags >> 2) & 1 )
            break;
          if ( !IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
                  (HashTableData<unsigned long,Sex_CG> *)v18,
                  v15) )
            goto LABEL_43;
          ++v16;
          v15 = (HashTableData<unsigned long,Sex_CG> *)v18;
        }
        while ( v16 < (unsigned int)io_archive );
      }
    }
  }
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;

//----- (004163F0) --------------------------------------------------------  // acclient.c:82861
void __thiscall EnumIDMap::EnumIDMap(EnumIDMap *this)
{
  EnumIDMap *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, INVALID_DID_7);
  v1->vfptr = (InterfaceVtbl *)&EnumIDMap::vftable;
  v1->m_EnumToID.vfptr = (HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>Vtbl *)&HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>(
    &v1->m_EnumToID.m_intrusiveTable,
    0x10u);
  v1->m_EnumToIDInternal.vfptr = (HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>Vtbl *)&HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>(
    &v1->m_EnumToIDInternal.m_intrusiveTable,
    0x10u);
  v1->m_EnumToName.vfptr = (HashTable<unsigned long,PStringBase<char>,0>Vtbl *)HashTable<unsigned long,PStringBase<char>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>(
    &v1->m_EnumToName.m_intrusiveTable,
    0x10u);
  v1->m_EnumToNameInternal.vfptr = (HashTable<unsigned long,PStringBase<char>,0>Vtbl *)HashTable<unsigned long,PStringBase<char>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>(
    &v1->m_EnumToNameInternal.m_intrusiveTable,
    0x10u);
}
// 79529C: using guessed type int (__thiscall *HashTable<unsigned long,PStringBase<char>,0>::vftable[2])(void *, char);
// 7952A0: using guessed type int (__thiscall *HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::vftable)(void *, char);
// 7952C8: using guessed type __int32 (__stdcall *EnumIDMap::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00416460) --------------------------------------------------------  // acclient.c:82890
signed int EnumIDMap::GetDBOType()
{
  return 38;
}

//----- (00416470) --------------------------------------------------------  // acclient.c:82896
void __thiscall EnumIDMap::~EnumIDMap(EnumIDMap *this)
{
  EnumIDMap *v1; // esi@1
  void *v2; // eax@1
  void *v3; // eax@3
  void *v4; // eax@5
  void *v5; // eax@7

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&EnumIDMap::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_EnumToID.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *)&v1->m_EnumToName.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_EnumToIDInternal.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *)&v1->m_EnumToNameInternal.m_intrusiveTable);
  v1->m_EnumToNameInternal.vfptr = (HashTable<unsigned long,PStringBase<char>,0>Vtbl *)HashTable<unsigned long,PStringBase<char>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *)&v1->m_EnumToNameInternal.m_intrusiveTable);
  v2 = v1->m_EnumToNameInternal.m_intrusiveTable.m_buckets;
  v1->m_EnumToNameInternal.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char> > *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::vftable;
  if ( v2 != v1->m_EnumToNameInternal.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v2);
  v1->m_EnumToNameInternal.m_intrusiveTable.m_buckets = 0;
  v1->m_EnumToNameInternal.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_EnumToNameInternal.m_intrusiveTable.m_numBuckets = 0;
  v1->m_EnumToNameInternal.m_intrusiveTable.m_numElements = 0;
  v1->m_EnumToName.vfptr = (HashTable<unsigned long,PStringBase<char>,0>Vtbl *)HashTable<unsigned long,PStringBase<char>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *)&v1->m_EnumToName.m_intrusiveTable);
  v3 = v1->m_EnumToName.m_intrusiveTable.m_buckets;
  v1->m_EnumToName.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char> > *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::vftable;
  if ( v3 != v1->m_EnumToName.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v3);
  v1->m_EnumToName.m_intrusiveTable.m_buckets = 0;
  v1->m_EnumToName.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_EnumToName.m_intrusiveTable.m_numBuckets = 0;
  v1->m_EnumToName.m_intrusiveTable.m_numElements = 0;
  v1->m_EnumToIDInternal.vfptr = (HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>Vtbl *)&HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_EnumToIDInternal.m_intrusiveTable);
  v4 = v1->m_EnumToIDInternal.m_intrusiveTable.m_buckets;
  v1->m_EnumToIDInternal.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vftable;
  if ( v4 != v1->m_EnumToIDInternal.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v4);
  v1->m_EnumToIDInternal.m_intrusiveTable.m_buckets = 0;
  v1->m_EnumToIDInternal.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_EnumToIDInternal.m_intrusiveTable.m_numBuckets = 0;
  v1->m_EnumToIDInternal.m_intrusiveTable.m_numElements = 0;
  v1->m_EnumToID.vfptr = (HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>Vtbl *)&HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_EnumToID.m_intrusiveTable);
  v5 = v1->m_EnumToID.m_intrusiveTable.m_buckets;
  v1->m_EnumToID.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vftable;
  if ( v5 != v1->m_EnumToID.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v5);
  v1->m_EnumToID.m_intrusiveTable.m_buckets = 0;
  v1->m_EnumToID.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_EnumToID.m_intrusiveTable.m_numBuckets = 0;
  v1->m_EnumToID.m_intrusiveTable.m_numElements = 0;
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 795294: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::vftable[4])(void *, char);
// 795298: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vftable[3])(void *, char);
// 79529C: using guessed type int (__thiscall *HashTable<unsigned long,PStringBase<char>,0>::vftable[2])(void *, char);
// 7952A0: using guessed type int (__thiscall *HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::vftable)(void *, char);
// 7952C8: using guessed type __int32 (__stdcall *EnumIDMap::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (004165B0) --------------------------------------------------------  // acclient.c:82959
void __cdecl EnumIDMap::Allocator()
{
  EnumIDMap *v0; // eax@1

  v0 = (EnumIDMap *)operator new(0x200u);
  if ( v0 )
    EnumIDMap::EnumIDMap(v0);
}

//----- (004165D0) --------------------------------------------------------  // acclient.c:82969
EnumIDMap *__thiscall EnumIDMap::scalar_deleting_destructor(EnumIDMap *this, unsigned int a2)
{
  EnumIDMap *v2; // esi@1

  v2 = this;
  EnumIDMap::~EnumIDMap(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004165F0) --------------------------------------------------------  // acclient.c:82981
void __thiscall EnumIDMap::Serialize(EnumIDMap *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  EnumIDMap *v3; // edi@1

  v2 = io_archive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v3->m_EnumToID.m_intrusiveTable);
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,SB_Default>(
    (const int *)&io_archive,
    &v3->m_EnumToID.m_intrusiveTable,
    v2);
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *)&v3->m_EnumToName.m_intrusiveTable);
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>,HashTableData<unsigned long,PStringBase<char>> *,SB_Default>(
    (const int *)&io_archive,
    &v3->m_EnumToName.m_intrusiveTable,
    v2);
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v3->m_EnumToIDInternal.m_intrusiveTable);
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,SB_Default>(
    (const int *)&io_archive,
    &v3->m_EnumToIDInternal.m_intrusiveTable,
    v2);
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *)&v3->m_EnumToNameInternal.m_intrusiveTable);
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>,HashTableData<unsigned long,PStringBase<char>> *,SB_Default>(
    (const int *)&io_archive,
    &v3->m_EnumToNameInternal.m_intrusiveTable,
    v2);
}

//----- (006C4950) --------------------------------------------------------  // acclient.c:732903
int _E73_12()
{
  return atexit(_E74_15);
}

//----- (006C4960) --------------------------------------------------------  // acclient.c:732909
int _E76_7()
{
  return atexit(_E77_35);
}

//----- (006C4970) --------------------------------------------------------  // acclient.c:732915
int _E79_7()
{
  return atexit(_E80_9);
}

//----- (006C4980) --------------------------------------------------------  // acclient.c:732921
int _E1_7()
{
  return atexit(_E2_7);
}

