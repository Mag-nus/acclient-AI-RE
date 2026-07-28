/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DBObjPackVersion
   Object     : ENGINE\engine_database\DBObjPackVersion.obj
   Functions  : 9
   Addresses  : 0041A2B0 - 00726FE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0041A2B0) --------------------------------------------------------  // acclient.c:87420
int __cdecl GetCoreSDKPackVersionFromDBObjPackVersion(unsigned int i_iDBObjVersion)
{
  return 2 - (i_iDBObjVersion < 2);
}

//----- (0041A2C0) --------------------------------------------------------  // acclient.c:87426
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0> *v2; // esi@1
  HashTableData<unsigned long,ArchiveVersionRow> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::vftable;
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
// 79545C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::vftable[6])(void *, char);

//----- (0041A300) --------------------------------------------------------  // acclient.c:87447
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,ArchiveVersionRow> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,ArchiveVersionRow> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79545C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::vftable[6])(void *, char);

//----- (0041A390) --------------------------------------------------------  // acclient.c:87480
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned long,ArchiveVersionRow> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,ArchiveVersionRow> **v5; // edx@5
  HashTableData<unsigned long,ArchiveVersionRow> *v6; // edi@5
  HashTableData<unsigned long,ArchiveVersionRow> *v7; // eax@7
  HashTableData<unsigned long,ArchiveVersionRow> *v8; // ecx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,ArchiveVersionRow> **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,ArchiveVersionRow> **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_19;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_19:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      if ( (v6->m_data.m_aVersions.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        operator delete[](v6->m_data.m_aVersions.m_data);
      operator delete(v6);
    }
  }
}

//----- (0041A430) --------------------------------------------------------  // acclient.c:87541
char __thiscall HashTable<unsigned long,ArchiveVersionRow,0>::add(HashTable<unsigned long,ArchiveVersionRow,0> *this, const unsigned int *_key, ArchiveVersionRow *_data)
{
  HashTable<unsigned long,ArchiveVersionRow,0> *v3; // ebx@1
  void *v4; // esi@1
  int v5; // ecx@2
  char result; // al@9

  v3 = this;
  v4 = operator new(0x58u);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    v5 = (int)((char *)v4 + 12);
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = &ArchiveVersionRow::vftable;
    *(_DWORD *)v5 = (char *)v4 + 24;
    *(_DWORD *)(v5 + 4) = 8;
    *(_DWORD *)(v5 + 8) = 0;
    SmartArray<ArchiveVersionRow::VersionEntry,1>::operator=(
      (SmartArray<ArchiveVersionRow::VersionEntry,1> *)v4 + 1,
      (int)&_data->m_aVersions);
  }
  else
  {
    v4 = 0;
  }
  if ( IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v3->m_intrusiveTable,
         (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v4) )
  {
    result = 1;
  }
  else
  {
    if ( v4 )
    {
      if ( (*((_DWORD *)v4 + 4) & 0x80000000) == 0x80000000 )
        operator delete[](*((void **)v4 + 3));
      operator delete(v4);
    }
    result = 0;
  }
  return result;
}
// 794430: using guessed type unsigned __int32 (__thiscall *ArchiveVersionRow::vftable)(ArchiveVersionRow *this, unsigned __int32);

//----- (0041A4D0) --------------------------------------------------------  // acclient.c:87588
ArchiveVersionRow *__cdecl GetVersionRowForDBObjPackVersion(unsigned int i_iDBObjVersion)
{
  unsigned int v1; // edi@1
  ArchiveVersionRow *v2; // esi@1
  HashTableData<unsigned long,ArchiveVersionRow> *v3; // eax@1
  ArchiveVersionRow *result; // eax@6
  HashTableData<unsigned long,ArchiveVersionRow> *v5; // eax@9
  ArchiveVersionRow _data; // [sp+8h] [bp-50h]@7

  v1 = i_iDBObjVersion;
  v2 = 0;
  v3 = stru_817734.m_buckets[i_iDBObjVersion % stru_817734.m_numBuckets];
  if ( !v3 )
    goto LABEL_7;
  while ( v3->m_hashKey != i_iDBObjVersion )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_7;
  }
  if ( !v3 || (result = &v3->m_data) == 0 )
  {
LABEL_7:
    _data.m_aVersions.m_data = (ArchiveVersionRow::VersionEntry *)_data.m_aVersions.m_aPrimitiveInplaceMemory;
    _data.vfptr = (ArchiveVersionRowVtbl *)&ArchiveVersionRow::vftable;
    _data.m_aVersions.m_sizeAndDeallocate = 8;
    _data.m_aVersions.m_num = 0;
    HashTable<unsigned long,ArchiveVersionRow,0>::add(&s_CachedVersionRows, &i_iDBObjVersion, &_data);
    if ( (_data.m_aVersions.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](_data.m_aVersions.m_data);
    v5 = stru_817734.m_buckets[v1 % stru_817734.m_numBuckets];
    if ( v5 )
    {
      while ( v5->m_hashKey != v1 )
      {
        v5 = v5->m_hashNext;
        if ( !v5 )
          goto LABEL_15;
      }
      if ( v5 )
        v2 = &v5->m_data;
    }
LABEL_15:
    ArchiveVersionRow::SetVersion(v2, 0x436F7265u, 2 - (v1 < 2));
    ArchiveVersionRow::SetVersion(v2, 0x444F626Au, v1);
    ArchiveVersionRow::SetVersion(v2, 0x55494C20u, v1 >= 3);
    result = v2;
  }
  return result;
}
// 794430: using guessed type unsigned __int32 (__thiscall *ArchiveVersionRow::vftable)(ArchiveVersionRow *this, unsigned __int32);

//----- (0041A5D0) --------------------------------------------------------  // acclient.c:87641
HashTable<unsigned long,ArchiveVersionRow,0> *__thiscall HashTable<unsigned long,ArchiveVersionRow,0>::scalar_deleting_destructor(HashTable<unsigned long,ArchiveVersionRow,0> *this, unsigned int a2)
{
  HashTable<unsigned long,ArchiveVersionRow,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,ArchiveVersionRow,0>Vtbl *)HashTable<unsigned long,ArchiveVersionRow,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::vftable;
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
// 79545C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::vftable[6])(void *, char);
// 795460: using guessed type int (__thiscall *HashTable<unsigned long,ArchiveVersionRow,0>::vftable[5])(void *, char);

//----- (006C4A20) --------------------------------------------------------  // acclient.c:732981
int _E73_15()
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>(
    &stru_817734,
    0x17u);
  return atexit(_E74_18);
}

//----- (00726FE0) --------------------------------------------------------  // acclient.c:824826
void __cdecl _E74_18()
{
  s_CachedVersionRows.vfptr = (HashTable<unsigned long,ArchiveVersionRow,0>Vtbl *)HashTable<unsigned long,ArchiveVersionRow,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::delete_contents(&stru_817734);
  stru_817734.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::vftable;
  if ( (HashTableData<unsigned long,ArchiveVersionRow> **)stru_817734.m_buckets != stru_817734.m_aInplaceBuckets )
    operator delete[](stru_817734.m_buckets);
  stru_817734.m_buckets = 0;
  stru_817734.m_firstInterestingBucket = 0;
  stru_817734.m_numBuckets = 0;
  stru_817734.m_numElements = 0;
}
// 79545C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::vftable[6])(void *, char);
// 795460: using guessed type int (__thiscall *HashTable<unsigned long,ArchiveVersionRow,0>::vftable[5])(void *, char);

