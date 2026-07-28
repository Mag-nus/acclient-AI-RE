/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : NameFilterTable
   Object     : ENGINE\namefilter\NameFilterTable.obj
   Functions  : 11
   Addresses  : 0067F2F0 - 00715440 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0067F2F0) --------------------------------------------------------  // acclient.c:662260
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0> *v2; // esi@1
  HashTableData<unsigned long,NameFilterLanguageData> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::vftable;
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
// 7FE690: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::vftable[2])(void *, char);

//----- (0067F330) --------------------------------------------------------  // acclient.c:662281
void __thiscall NameFilterLanguageData::Serialize(NameFilterLanguageData *this, Archive *_rArchive)
{
  NameFilterLanguageData *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5
  unsigned int v5; // eax@9
  unsigned int v6; // eax@13

  v2 = this;
  Archive::CheckAlignment(_rArchive, 4u);
  v3 = Archive::GetBytes(_rArchive, 4u);
  if ( v3 )
  {
    if ( _rArchive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_MaximumSameCharactersInARow;
    else
      v2->m_MaximumSameCharactersInARow = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(_rArchive, 4u);
  v4 = Archive::GetBytes(_rArchive, 4u);
  if ( v4 )
  {
    if ( _rArchive->m_flags & 1 )
      *(_DWORD *)v4 = v2->m_MaximumVowelsInARow;
    else
      v2->m_MaximumVowelsInARow = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(_rArchive, 4u);
  v5 = Archive::GetBytes(_rArchive, 4u);
  if ( v5 )
  {
    if ( _rArchive->m_flags & 1 )
      *(_DWORD *)v5 = v2->m_FirstNCharactersMustHaveAVowel;
    else
      v2->m_FirstNCharactersMustHaveAVowel = *(_DWORD *)v5;
  }
  Archive::CheckAlignment(_rArchive, 4u);
  v6 = Archive::GetBytes(_rArchive, 4u);
  if ( v6 )
  {
    if ( _rArchive->m_flags & 1 )
      *(_DWORD *)v6 = v2->m_VowelContainingSubstringLength;
    else
      v2->m_VowelContainingSubstringLength = *(_DWORD *)v6;
  }
  PStringBase<unsigned short>::Serialize(&v2->m_ExtraAllowedCharacters, _rArchive);
  SmartArray<PStringBase<unsigned short>,1>::Serialize(&v2->m_CompoundLetterGroups, _rArchive);
}

//----- (0067F3F0) --------------------------------------------------------  // acclient.c:662331
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,NameFilterLanguageData> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,NameFilterLanguageData> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FE690: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::vftable[2])(void *, char);

//----- (0067F480) --------------------------------------------------------  // acclient.c:662364
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0> *v1; // ebp@1
  int v2; // ecx@2
  HashTableData<unsigned long,NameFilterLanguageData> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,NameFilterLanguageData> **v5; // edx@5
  HashTableData<unsigned long,NameFilterLanguageData> *v6; // ebx@5
  HashTableData<unsigned long,NameFilterLanguageData> *v7; // eax@7
  HashTableData<unsigned long,NameFilterLanguageData> *v8; // ecx@8
  PStringBase<unsigned short> *v9; // ecx@14
  PSRefBufferCharData<unsigned short> *v10; // eax@15
  void *v11; // edx@15
  int v12; // edi@15
  int v13; // eax@15
  int v14; // esi@17
  int v15; // esi@17
  int v16; // esi@23
  int v17; // [sp+4h] [bp-8h]@16
  int v18; // [sp+8h] [bp-4h]@15

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,NameFilterLanguageData> **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,NameFilterLanguageData> **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_30;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_30:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      if ( (v6->m_data.m_CompoundLetterGroups.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      {
        v9 = v6->m_data.m_CompoundLetterGroups.m_data;
        if ( v9 )
        {
          v10 = v9[-1].m_charbuffer;
          v11 = &v9[-1];
          v12 = (int)&v9[(_DWORD)v10];
          v13 = (int)((char *)&v10[-1].m_data[15] + 1);
          v18 = (int)&v9[-1];
          if ( v13 >= 0 )
          {
            v17 = v13 + 1;
            do
            {
              v14 = *(_DWORD *)(v12 - 4);
              v12 -= 4;
              v15 = v14 - 20;
              if ( !InterlockedDecrement((volatile LONG *)(v15 + 4)) && v15 )
                (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
              --v17;
            }
            while ( v17 );
            v11 = (void *)v18;
          }
          operator delete[](v11);
        }
      }
      v16 = (int)&v6->m_data.m_ExtraAllowedCharacters.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)(v16 + 4)) )
      {
        if ( v16 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
      }
      operator delete(v6);
    }
  }
}

//----- (0067F5A0) --------------------------------------------------------  // acclient.c:662467
void __thiscall HashTable<unsigned long,NameFilterLanguageData,0>::~HashTable<unsigned long,NameFilterLanguageData,0>(HashTable<unsigned long,NameFilterLanguageData,0> *this)
{
  char *v1; // esi@1
  void *v2; // eax@1

  v1 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,NameFilterLanguageData,0>Vtbl *)&HashTable<unsigned long,NameFilterLanguageData,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::delete_contents(&this->m_intrusiveTable);
  v2 = (void *)*((_DWORD *)v1 + 24);
  *(_DWORD *)v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::vftable;
  if ( v2 != v1 + 4 )
    operator delete[](v2);
  *((_DWORD *)v1 + 24) = 0;
  *((_DWORD *)v1 + 25) = 0;
  *((_DWORD *)v1 + 26) = 0;
  *((_DWORD *)v1 + 27) = 0;
}
// 7FE690: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::vftable[2])(void *, char);
// 7FE694: using guessed type int (__thiscall *HashTable<unsigned long,NameFilterLanguageData,0>::vftable)(void *, char);

//----- (0067F5E0) --------------------------------------------------------  // acclient.c:662488
HashTable<unsigned long,NameFilterLanguageData,0> *__thiscall HashTable<unsigned long,NameFilterLanguageData,0>::scalar_deleting_destructor(HashTable<unsigned long,NameFilterLanguageData,0> *this, unsigned int a2)
{
  HashTable<unsigned long,NameFilterLanguageData,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,NameFilterLanguageData,0>Vtbl *)&HashTable<unsigned long,NameFilterLanguageData,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::vftable;
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
// 7FE690: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::vftable[2])(void *, char);
// 7FE694: using guessed type int (__thiscall *HashTable<unsigned long,NameFilterLanguageData,0>::vftable)(void *, char);

//----- (0067F640) --------------------------------------------------------  // acclient.c:662514
void __thiscall NameFilterTable::NameFilterTable(NameFilterTable *this)
{
  NameFilterTable *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_8F79AC);
  v1->vfptr = (InterfaceVtbl *)&NameFilterTable::vftable;
  v1->m_LanguageData.vfptr = (HashTable<unsigned long,NameFilterLanguageData,0>Vtbl *)&HashTable<unsigned long,NameFilterLanguageData,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>(
    &v1->m_LanguageData.m_intrusiveTable,
    0x17u);
}
// 7FE694: using guessed type int (__thiscall *HashTable<unsigned long,NameFilterLanguageData,0>::vftable)(void *, char);
// 7FE698: using guessed type __int32 (__stdcall *NameFilterTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0067F690) --------------------------------------------------------  // acclient.c:662536
DBObj *__thiscall NameFilterTable::scalar_deleting_destructor(NameFilterTable *this, unsigned int a2)
{
  DBObj *v2; // esi@1

  v2 = (DBObj *)this;
  HashTable<unsigned long,NameFilterLanguageData,0>::~HashTable<unsigned long,NameFilterLanguageData,0>(&this->m_LanguageData);
  DBObj::~DBObj(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0067F6C0) --------------------------------------------------------  // acclient.c:662549
void __cdecl SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>,HashTableData<unsigned long,NameFilterLanguageData> *,SB_Default>(const int *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0> *io_object, Archive *io_archive)
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
  void *v16; // eax@32
  void *v17; // esi@32
  volatile LONG *v18; // ST10_4@33
  unsigned int v19; // eax@35
  bool v20; // cf@41
  unsigned int i; // [sp+10h] [bp-10h]@31
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+14h] [bp-Ch]@19

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
        NameFilterLanguageData::Serialize((NameFilterLanguageData *)&v11->m_data, v3);
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
      i = 0;
      if ( (unsigned int)io_archive > 0 )
      {
        do
        {
          v16 = operator new(0x28u);
          v17 = v16;
          if ( v16 )
          {
            *((_DWORD *)v16 + 1) = 0;
            *((_DWORD *)v16 + 2) = 0;
            *((_DWORD *)v16 + 3) = 0;
            *((_DWORD *)v16 + 4) = 0;
            *((_DWORD *)v16 + 5) = 0;
            v18 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
            *((_DWORD *)v16 + 6) = PStringBase<unsigned short>::s_NullBuffer;
            InterlockedIncrement(v18);
            *((_DWORD *)v17 + 7) = 0;
            *((_DWORD *)v17 + 8) = 0;
            *((_DWORD *)v17 + 9) = 0;
          }
          else
          {
            v17 = 0;
          }
          Archive::CheckAlignment(v3, 4u);
          v19 = Archive::GetBytes(v3, 4u);
          if ( v19 )
          {
            if ( v3->m_flags & 1 )
              *(_DWORD *)v19 = *(_DWORD *)v17;
            else
              *(_DWORD *)v17 = *(_DWORD *)v19;
          }
          NameFilterLanguageData::Serialize((NameFilterLanguageData *)((char *)v17 + 8), v3);
          if ( (v3->m_flags >> 2) & 1 )
            break;
          if ( !IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
                  (HashTableData<unsigned long,Sex_CG> *)v17,
                  v15) )
            goto LABEL_43;
          v20 = i + 1 < (unsigned int)io_archive;
          v15 = (HashTableData<unsigned long,Sex_CG> *)v17;
          ++i;
        }
        while ( v20 );
      }
    }
  }
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;

//----- (0067F900) --------------------------------------------------------  // acclient.c:662714
void __thiscall NameFilterTable::Serialize(NameFilterTable *this, Archive *_rArchive)
{
  Archive *v2; // edi@1
  NameFilterTable *v3; // esi@1

  v2 = _rArchive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, _rArchive);
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::delete_contents(&v3->m_LanguageData.m_intrusiveTable);
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>,HashTableData<unsigned long,NameFilterLanguageData> *,SB_Default>(
    (const int *)&_rArchive,
    &v3->m_LanguageData.m_intrusiveTable,
    v2);
}

//----- (00715440) --------------------------------------------------------  // acclient.c:808233
int sub_715440()
{
  return atexit(nullsub_176);
}

