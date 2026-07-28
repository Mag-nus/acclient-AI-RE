/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : QDIDArray
   Object     : ENGINE\engine_database\QDIDArray.obj
   Functions  : 7
   Addresses  : 00419FE0 - 006C4A10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00419FE0) --------------------------------------------------------  // acclient.c:87196
void __thiscall QualifiedDataIDArray::ExpensiveUpdateIterator(QualifiedDataIDArray *this, unsigned int idx)
{
  QualifiedDataIDArray *v2; // esi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@1
  DBObjSaveInfo *v4; // edx@1
  unsigned int v5; // edi@2
  DBObjSaveInfo *v6; // eax@4
  int v7; // ecx@5
  int v8; // eax@6
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+4h] [bp-Ch]@1

  v2 = this;
  v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)this,
         &result);
  v2->m_CurBracketIterator.m_currHashTable = (IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *)v3->m_currHashTable;
  v4 = (DBObjSaveInfo *)v3->m_currElement;
  v2->m_CurBracketIterator.m_currElement = v4;
  v2->m_CurBracketIterator.m_currBucket = (DBObjSaveInfo **)v3->m_currBucket;
  if ( v4 )
  {
    v5 = idx;
    do
    {
      if ( !v5 )
        break;
      v6 = v2->m_CurBracketIterator.m_currElement->m_hashNext;
      v2->m_CurBracketIterator.m_currElement = v6;
      if ( !v6 )
      {
        v7 = (int)&v2->m_CurBracketIterator.m_currHashTable->m_buckets[v2->m_CurBracketIterator.m_currHashTable->m_numBuckets];
        while ( 1 )
        {
          v8 = (int)(v2->m_CurBracketIterator.m_currBucket + 1);
          v2->m_CurBracketIterator.m_currBucket = (DBObjSaveInfo **)v8;
          if ( v8 == v7 )
            break;
          if ( *(_DWORD *)v8 )
          {
            v2->m_CurBracketIterator.m_currElement = *(DBObjSaveInfo **)v8;
            break;
          }
        }
      }
      --v5;
    }
    while ( v2->m_CurBracketIterator.m_currElement );
  }
}

//----- (0041A060) --------------------------------------------------------  // acclient.c:87247
char __thiscall IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::add(IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *this, DBObjSaveInfo *data)
{
  IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *v2; // esi@1
  char v3; // al@2
  unsigned int v4; // edx@5
  DBObjSaveInfo **v5; // eax@5
  int v6; // eax@5
  IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> result; // [sp+8h] [bp-Ch]@1

  v2 = this;
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::find_internal(
    (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *)this,
    &result,
    &data->m_hashKey);
  if ( result.m_currElement )
  {
    v3 = 0;
  }
  else
  {
    if ( (signed int)(2 * v2->m_numBuckets) < (signed int)(v2->m_numElements + 1) )
      IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::grow(v2);
    v4 = (data->m_hashKey.Type + data->m_hashKey.ID.id) % v2->m_numBuckets;
    v5 = v2->m_buckets;
    data->m_hashNext = v5[v4];
    v5[v4] = data;
    v6 = (int)&v5[v4];
    if ( (DBObjSaveInfo **)v6 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (DBObjSaveInfo **)v6;
    ++v2->m_numElements;
    v3 = 1;
  }
  return v3;
}

//----- (0041A0D0) --------------------------------------------------------  // acclient.c:87283
void __thiscall QualifiedDataIDArray::~QualifiedDataIDArray(QualifiedDataIDArray *this)
{
  QualifiedDataIDArray *v1; // esi@1
  void *v2; // eax@1

  v1 = this;
  this->vfptr = (IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>Vtbl *)QualifiedDataIDArray::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)this);
  v2 = v1->m_buckets;
  v1->vfptr = (IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>Vtbl *)IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::vftable;
  if ( v2 != v1->m_aInplaceBuckets )
    operator delete[](v2);
  v1->m_buckets = 0;
  v1->m_firstInterestingBucket = 0;
  v1->m_numBuckets = 0;
  v1->m_numElements = 0;
}
// 794F84: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::vftable[8])(void *, char);
// 794F98: using guessed type int (__thiscall *QualifiedDataIDArray::vftable[3])(void *, char);

//----- (0041A110) --------------------------------------------------------  // acclient.c:87304
char __thiscall QualifiedDataIDArray::AdoptDBObjSaveInfo(QualifiedDataIDArray *this, DBObjSaveInfo *i_pHashData)
{
  QualifiedDataIDArray *v2; // edi@1
  char v3; // bl@1
  MissingIteration *v4; // ecx@4
  unsigned int v5; // eax@4
  IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> result; // [sp+Ch] [bp-Ch]@3

  v2 = this;
  v3 = 0;
  if ( i_pHashData->m_hashKey.ID.id != INVALID_DID_10.id )
  {
    v3 = IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::add(
           (IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *)&this->vfptr,
           i_pHashData);
    if ( v3 )
      goto LABEL_10;
  }
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::find_internal(
    (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *)v2,
    &result,
    &i_pHashData->m_hashKey);
  if ( result.m_currElement )
  {
    v4 = result.m_currElement->m_data;
    v5 = i_pHashData->m_dwSubDataIDFlags & (unsigned int)result.m_currElement->m_data | s_dwDominantDBObjSubDataIDFlags & (i_pHashData->m_dwSubDataIDFlags | (unsigned int)result.m_currElement->m_data);
    result.m_currElement->m_data = (MissingIteration *)v5;
    v3 = v5 != (_DWORD)v4;
  }
  operator delete(i_pHashData);
  if ( v3 )
  {
LABEL_10:
    v2->m_CurBracketIterator.m_currHashTable = (IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *)v2;
    v2->m_CurBracketIterator.m_currElement = 0;
    v2->m_CurBracketIterator.m_currBucket = 0;
  }
  return v3;
}

//----- (0041A1A0) --------------------------------------------------------  // acclient.c:87345
bool __thiscall QualifiedDataIDArray::AddQDID(QualifiedDataIDArray *this, QualifiedDataID *i_data, unsigned int i_dwSubDataIDFlags)
{
  QualifiedDataIDArray *v3; // edi@1
  bool v4; // al@2
  MissingIteration *v5; // ecx@4
  unsigned int v6; // eax@4
  void *v7; // eax@5
  unsigned int v8; // edx@6
  IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> result; // [sp+8h] [bp-Ch]@3

  v3 = this;
  if ( i_data->ID.id == INVALID_DID_10.id )
  {
    v4 = 0;
  }
  else
  {
    IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::find_internal(
      (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *)this,
      &result,
      i_data);
    if ( result.m_currElement )
    {
      v5 = result.m_currElement->m_data;
      v6 = i_dwSubDataIDFlags & (unsigned int)result.m_currElement->m_data | s_dwDominantDBObjSubDataIDFlags & (i_dwSubDataIDFlags | (unsigned int)result.m_currElement->m_data);
      result.m_currElement->m_data = (MissingIteration *)v6;
      v4 = v6 != (_DWORD)v5;
    }
    else
    {
      v7 = operator new(0x10u);
      if ( v7 )
      {
        *(_DWORD *)v7 = i_data->Type;
        v8 = i_data->ID.id;
        *((_DWORD *)v7 + 3) = i_dwSubDataIDFlags;
        *((_DWORD *)v7 + 1) = v8;
        *((_DWORD *)v7 + 2) = 0;
        v4 = QualifiedDataIDArray::AdoptDBObjSaveInfo(v3, (DBObjSaveInfo *)v7);
      }
      else
      {
        v4 = QualifiedDataIDArray::AdoptDBObjSaveInfo(v3, 0);
      }
    }
  }
  return v4;
}

//----- (0041A250) --------------------------------------------------------  // acclient.c:87395
char __thiscall QualifiedDataIDArray::CopyDIDs(QualifiedDataIDArray *this, SmartArray<IDClass<_tagDataID,32,0>,1> *i_rhs, unsigned int i_dwSubDataIDFlags)
{
  char v3; // bl@1
  unsigned int v4; // esi@1
  QualifiedDataIDArray *v5; // ebp@1
  QualifiedDataID *v6; // eax@2
  QualifiedDataID v8; // [sp+10h] [bp-8h]@2

  v3 = 0;
  v4 = 0;
  v5 = this;
  if ( i_rhs->m_num )
  {
    do
    {
      QualifiedDataID::QualifiedDataID(&v8, i_rhs->m_data[v4], 0);
      v3 |= QualifiedDataIDArray::AddQDID(v5, v6, i_dwSubDataIDFlags);
      ++v4;
    }
    while ( v4 < i_rhs->m_num );
  }
  return v3;
}

//----- (006C4A10) --------------------------------------------------------  // acclient.c:732975
int _E1_10()
{
  return atexit(_E2_10);
}

