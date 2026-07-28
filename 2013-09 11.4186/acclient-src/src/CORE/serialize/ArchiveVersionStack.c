/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ArchiveVersionStack
   Object     : CORE\serialize\ArchiveVersionStack.obj
   Functions  : 19
   Addresses  : 00410560 - 006C3B60 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00410560) --------------------------------------------------------  // acclient.c:76276
void __thiscall DLListBase::InsertAfter(DLListBase *this, DLListData *to_add, DLListData *where)
{
  if ( where )
  {
    to_add->dllist_next = where->dllist_next;
    if ( where->dllist_next )
    {
      where->dllist_next->dllist_prev = to_add;
      where->dllist_next = to_add;
      to_add->dllist_prev = where;
    }
    else
    {
      this->tail_ = to_add;
      where->dllist_next = to_add;
      to_add->dllist_prev = where;
    }
  }
  else
  {
    to_add->dllist_next = this->head_;
    if ( this->head_ )
    {
      this->head_->dllist_prev = to_add;
      this->head_ = to_add;
      to_add->dllist_prev = where;
    }
    else
    {
      this->tail_ = to_add;
      this->head_ = to_add;
      to_add->dllist_prev = where;
    }
  }
}

//----- (004105C0) --------------------------------------------------------  // acclient.c:76313
void __thiscall DLListBase::Remove(DLListBase *this, DLListData *to_remove)
{
  DLListData *v2; // edx@1
  DLListData *v3; // edx@3
  DLListData *v4; // edx@7

  v2 = to_remove->dllist_prev;
  if ( v2 )
  {
    v2->dllist_next = to_remove->dllist_next;
  }
  else
  {
    v3 = this->head_->dllist_next;
    this->head_ = v3;
    if ( v3 )
      v3->dllist_prev = 0;
  }
  if ( to_remove->dllist_next )
  {
    to_remove->dllist_next->dllist_prev = to_remove->dllist_prev;
    to_remove->dllist_next = 0;
    to_remove->dllist_prev = 0;
  }
  else
  {
    v4 = this->tail_->dllist_prev;
    this->tail_ = v4;
    if ( v4 )
      v4->dllist_next = 0;
    to_remove->dllist_next = 0;
    to_remove->dllist_prev = 0;
  }
}

//----- (00410610) --------------------------------------------------------  // acclient.c:76349
TResult *__thiscall InArchiveVersionStack::QueryInterface(InArchiveVersionStack *this, TResult *result, Turbine_GUID *i_rInterfaceType, void **o_pOutInterface)
{
  Turbine_GUID *v4; // eax@1
  unsigned int v5; // edi@1
  QIOffset *v6; // edx@1
  TResult *v7; // eax@7
  int v8; // esi@9
  int v9; // edx@9
  char *v10; // esi@9
  QIOffset aOffsets[3]; // [sp+10h] [bp-18h]@1

  v4 = &InArchiveVersionStack_InterfaceType_0;
  v5 = i_rInterfaceType->m_data1;
  aOffsets[0].key = (_GUID *)&InArchiveVersionStack_InterfaceType_0;
  aOffsets[0].ofs = 0;
  aOffsets[1].key = (_GUID *)&Interface_InterfaceType_3;
  aOffsets[1].ofs = 0;
  aOffsets[2].key = 0;
  aOffsets[2].ofs = 0;
  v6 = aOffsets;
  while ( v4->m_data1 != v5
       || *(_DWORD *)&v4->m_data2 != *(_DWORD *)&i_rInterfaceType->m_data2
       || *(_DWORD *)&v4->m_data4[0] != *(_DWORD *)&i_rInterfaceType->m_data4[0]
       || *(_DWORD *)&v4->m_data4[4] != *(_DWORD *)&i_rInterfaceType->m_data4[4] )
  {
    v4 = (Turbine_GUID *)v6[1].key;
    ++v6;
    if ( !v4 )
    {
      v7 = result;
      result->m_val = -2147467262;
      return v7;
    }
  }
  if ( o_pOutInterface )
  {
    v8 = v6->ofs;
    v9 = *(int *)((char *)&this->vfptr + v8);
    v10 = (char *)this + v8;
    (*(void (__thiscall **)(char *))(v9 + 16))(v10);
    *o_pOutInterface = v10;
  }
  v7 = result;
  result->m_val = 0;
  return v7;
}

//----- (004106B0) --------------------------------------------------------  // acclient.c:76397
int __thiscall InArchiveVersionStack::GetVersionByToken(InArchiveVersionStack *this, unsigned int i_tokVersion)
{
  int result; // eax@1
  DLListData *v3; // ecx@2
  int v4; // ecx@3

  result = 0;
  if ( this->m_hlVersions.m_hash.m_numElements )
  {
    v3 = this->m_hlVersions.m_list.tail_;
    if ( v3 )
    {
      v4 = (int)&v3[-1];
      if ( v4 )
        result = (**(int (__stdcall ***)(_DWORD))(v4 + 16))(i_tokVersion);
    }
  }
  return result;
}

//----- (004106E0) --------------------------------------------------------  // acclient.c:76418
bool __thiscall InArchiveVersionStack::SetVersion(InArchiveVersionStack *this, unsigned int i_tokVersion, unsigned int i_iVersion)
{
  bool result; // al@1
  DLListData *v4; // ecx@2
  int v5; // ecx@3

  result = 0;
  if ( this->m_hlVersions.m_hash.m_numElements )
  {
    v4 = this->m_hlVersions.m_list.tail_;
    if ( v4 )
    {
      v5 = (int)&v4[-1];
      if ( v5 )
        result = ArchiveVersionRow::SetVersion((ArchiveVersionRow *)(v5 + 16), i_tokVersion, i_iVersion);
    }
  }
  return result;
}

//----- (00410710) --------------------------------------------------------  // acclient.c:76439
IDClass<_tagVersionHandle,32,0> *__thiscall InArchiveVersionStack::GetCurrentVersionHandle(InArchiveVersionStack *this, IDClass<_tagVersionHandle,32,0> *result)
{
  DLListData *v2; // eax@2
  int v3; // eax@3
  unsigned int v4; // ecx@4
  IDClass<_tagVersionHandle,32,0> *v5; // eax@4

  if ( this->m_hlVersions.m_hash.m_numElements
    && (v2 = this->m_hlVersions.m_list.tail_) != 0
    && (v3 = (int)&v2[-1]) != 0 )
  {
    v4 = *(_DWORD *)v3;
    v5 = result;
    result->id = v4;
  }
  else
  {
    v5 = result;
    result->id = INVALID_VERSIONHANDLE_2.id;
  }
  return v5;
}

//----- (00410740) --------------------------------------------------------  // acclient.c:76463
SmartArray<ArchiveVersionRow::VersionEntry,1> *__thiscall SmartArray<ArchiveVersionRow::VersionEntry,1>::operator=(SmartArray<ArchiveVersionRow::VersionEntry,1> *this, int a2)
{
  SmartArray<ArchiveVersionRow::VersionEntry,1> *v2; // esi@1
  unsigned int v3; // eax@3
  int v4; // edx@3
  ArchiveVersionRow::VersionEntry *v5; // ecx@3
  unsigned int i; // eax@5
  ArchiveVersionRow::VersionEntry *v7; // edx@6

  v2 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<ArchiveVersionRow::VersionEntry,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v3 = *(_DWORD *)a2;
    v4 = *(_DWORD *)a2 + 8 * *(_DWORD *)(a2 + 8);
    v5 = v2->m_data;
    if ( *(_DWORD *)a2 < (unsigned int)v4 )
    {
      do
      {
        v5->tokVersion = *(_DWORD *)v3;
        v5->iVersion = *(_DWORD *)(v3 + 4);
        v3 += 8;
        ++v5;
      }
      while ( v3 < v4 );
    }
    for ( i = *(_DWORD *)(a2 + 8); i < v2->m_num; ++i )
    {
      v7 = v2->m_data;
      v7[i].tokVersion = 0;
      v7[i].iVersion = 0;
    }
    v2->m_num = *(_DWORD *)(a2 + 8);
  }
  return v2;
}

//----- (004107D0) --------------------------------------------------------  // acclient.c:76502
char __thiscall IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::grow(IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *v2; // edi@1
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
  return IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::resize_internal(
           v2,
           *v3);
}

//----- (00410830) --------------------------------------------------------  // acclient.c:76524
char __thiscall InArchiveVersionStack::GetRowByHandle(InArchiveVersionStack *this, IDClass<_tagVersionHandle,32,0> i_hVersion, ArchiveVersionRow **o_pVersionRow)
{
  InArchiveVersionStack::VersionRowHolder *v3; // edx@1
  char result; // al@4

  v3 = this->m_hlVersions.m_hash.m_buckets[i_hVersion.id % this->m_hlVersions.m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.id != i_hVersion.id )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    *o_pVersionRow = &v3->m_VersionRow;
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00410870) --------------------------------------------------------  // acclient.c:76552
char __thiscall IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::resize_internal(IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *v2; // esi@1
  char result; // al@2
  InArchiveVersionStack::VersionRowHolder *v4; // ebp@3
  int v5; // ecx@4
  InArchiveVersionStack::VersionRowHolder **v6; // eax@5
  int v7; // eax@6
  InArchiveVersionStack::VersionRowHolder **v8; // ecx@7
  InArchiveVersionStack::VersionRowHolder *v9; // edi@7
  _BYTE v10[12]; // ST00_12@9
  InArchiveVersionStack::VersionRowHolder *v11; // edi@12
  InArchiveVersionStack::VersionRowHolder *v12; // ebp@13
  int v13; // edx@15
  InArchiveVersionStack::VersionRowHolder **v14; // eax@15
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
        if ( v2->m_firstInterestingBucket == (InArchiveVersionStack::VersionRowHolder **)v5 )
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
            v2->m_firstInterestingBucket = (InArchiveVersionStack::VersionRowHolder **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        *(_QWORD *)&v10[4] = __PAIR__((unsigned int)v9, (unsigned int)v8);
        *(_DWORD *)v10 = v2;
        IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::remove(
          (IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0> *)v2,
          *(IntrusiveHashIterator<unsigned long,LogController::CategoryHandler *,0> *)v10);
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (InArchiveVersionStack::VersionRowHolder **)v2->m_buckets != v2->m_aInplaceBuckets )
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
          IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::grow(v2);
        v13 = v11->m_hashKey.id % v2->m_numBuckets;
        v14 = v2->m_buckets;
        v11->m_hashNext = v14[v13];
        v14[v13] = v11;
        v15 = (int)&v14[v13];
        if ( (InArchiveVersionStack::VersionRowHolder **)v15 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (InArchiveVersionStack::VersionRowHolder **)v15;
        ++v2->m_numElements;
        v11 = v12;
      }
      while ( v12 );
    }
    result = 1;
  }
  return result;
}

//----- (00410960) --------------------------------------------------------  // acclient.c:76648
char __thiscall IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::add(IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *this, InArchiveVersionStack::VersionRowHolder *data)
{
  IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  InArchiveVersionStack::VersionRowHolder *v4; // edx@1
  unsigned int v5; // edx@6
  InArchiveVersionStack::VersionRowHolder **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey.id % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.id != data->m_hashKey.id )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::grow(this);
    v5 = data->m_hashKey.id % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (InArchiveVersionStack::VersionRowHolder **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (InArchiveVersionStack::VersionRowHolder **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (004109E0) --------------------------------------------------------  // acclient.c:76692
char __thiscall IntrusiveHashList<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::push_tail(IntrusiveHashList<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *this, InArchiveVersionStack::VersionRowHolder *val)
{
  IntrusiveHashList<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *v2; // esi@1
  InArchiveVersionStack::VersionRowHolder *v3; // edx@1
  char result; // al@4

  v2 = this;
  v3 = v2->m_hash.m_buckets[val->m_hashKey.id % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.id != val->m_hashKey.id )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::add(
      &this->m_hash,
      val);
    DLListBase::InsertAfter(&v2->m_list, (DLListData *)&val->dllist_next, v2->m_list.tail_);
    result = 1;
  }
  return result;
}

//----- (00410A40) --------------------------------------------------------  // acclient.c:76725
IDClass<_tagVersionHandle,32,0> *__thiscall InArchiveVersionStack::PushVersionRow(InArchiveVersionStack *this, IDClass<_tagVersionHandle,32,0> *result)
{
  InArchiveVersionStack *v2; // esi@1
  unsigned int v3; // edi@1
  IDClass<_tagVersionHandle,32,0> *v4; // eax@2
  void *v5; // eax@3

  v2 = this;
  v2->m_iLastSerialNumber += 2;
  v3 = this->m_iLastSerialNumber;
  if ( this->m_hlVersions.m_hash.m_numElements )
  {
    v5 = operator new(0x60u);
    if ( v5 )
    {
      *(_DWORD *)v5 = v3;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 4) = &ArchiveVersionRow::vftable;
      *((_DWORD *)v5 + 5) = (char *)v5 + 32;
      *((_DWORD *)v5 + 6) = 8;
      *((_DWORD *)v5 + 7) = 0;
      IntrusiveHashList<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::push_tail(
        &v2->m_hlVersions,
        (InArchiveVersionStack::VersionRowHolder *)v5);
      v4 = result;
      result->id = v3;
    }
    else
    {
      IntrusiveHashList<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::push_tail(
        &v2->m_hlVersions,
        0);
      v4 = result;
      result->id = v3;
    }
  }
  else
  {
    this->m_vrDefaultRow.m_hashKey.id = v3;
    IntrusiveHashList<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::push_tail(
      &this->m_hlVersions,
      &this->m_vrDefaultRow);
    v4 = result;
    result->id = v3;
  }
  return v4;
}
// 794430: using guessed type unsigned __int32 (__thiscall *ArchiveVersionRow::vftable)(ArchiveVersionRow *this, unsigned __int32);

//----- (00410AE0) --------------------------------------------------------  // acclient.c:76777
IDClass<_tagVersionHandle,32,0> *__thiscall InArchiveVersionStack::PushVersionRow(InArchiveVersionStack *this, IDClass<_tagVersionHandle,32,0> *result, ArchiveVersionRow *i_rInitialData)
{
  InArchiveVersionStack *v3; // esi@1
  char *v4; // ebx@1
  unsigned int v5; // edi@1
  void *v6; // eax@3
  IDClass<_tagVersionHandle,32,0> *v7; // eax@6

  v3 = this;
  v3->m_iLastSerialNumber += 2;
  v4 = 0;
  v5 = this->m_iLastSerialNumber;
  if ( this->m_hlVersions.m_hash.m_numElements )
  {
    v6 = operator new(0x60u);
    if ( v6 )
    {
      *((_DWORD *)v6 + 1) = 0;
      *(_DWORD *)v6 = v5;
      *((_DWORD *)v6 + 2) = 0;
      *((_DWORD *)v6 + 3) = 0;
      *((_DWORD *)v6 + 4) = &ArchiveVersionRow::vftable;
      *((_DWORD *)v6 + 7) = 0;
      *((_DWORD *)v6 + 5) = (char *)v6 + 32;
      *((_DWORD *)v6 + 6) = 8;
      v4 = (char *)v6;
    }
    SmartArray<ArchiveVersionRow::VersionEntry,1>::operator=(
      (SmartArray<ArchiveVersionRow::VersionEntry,1> *)(v4 + 20),
      (int)&i_rInitialData->m_aVersions);
  }
  else
  {
    v4 = (char *)&this->m_vrDefaultRow;
    this->m_vrDefaultRow.m_hashKey.id = v5;
    SmartArray<ArchiveVersionRow::VersionEntry,1>::operator=(
      (SmartArray<ArchiveVersionRow::VersionEntry,1> *)&this->m_vrDefaultRow.m_VersionRow.m_aVersions.m_data,
      (int)&i_rInitialData->m_aVersions);
  }
  IntrusiveHashList<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::push_tail(
    &v3->m_hlVersions,
    (InArchiveVersionStack::VersionRowHolder *)v4);
  v7 = result;
  result->id = v5;
  return v7;
}
// 794430: using guessed type unsigned __int32 (__thiscall *ArchiveVersionRow::vftable)(ArchiveVersionRow *this, unsigned __int32);

//----- (00410B70) --------------------------------------------------------  // acclient.c:76826
InArchiveVersionStack::VersionRowHolder *__thiscall IntrusiveHashList<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::remove(IntrusiveHashList<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *this, IDClass<_tagVersionHandle,32,0> *val)
{
  IntrusiveHashList<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1> *v2; // edi@1
  InArchiveVersionStack::VersionRowHolder *v3; // esi@1

  v2 = this;
  v3 = v2->m_hash.m_buckets[val->id % v2->m_hash.m_numBuckets];
  if ( v3 )
  {
    while ( v3->m_hashKey.id != val->id )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        return 0;
    }
    if ( v3 )
    {
      DLListBase::Remove(&this->m_list, (DLListData *)&v3->dllist_next);
      IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::remove(
        (IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0> *)v2,
        &val->id);
    }
  }
  return v3;
}

//----- (00410BD0) --------------------------------------------------------  // acclient.c:76853
char __thiscall InArchiveVersionStack::PopVersionRow(InArchiveVersionStack *this, IDClass<_tagVersionHandle,32,0> i_hVersion)
{
  InArchiveVersionStack *v2; // edi@1
  InArchiveVersionStack::VersionRowHolder *v3; // eax@1
  void *v4; // esi@1
  char result; // al@6

  v2 = this;
  v3 = IntrusiveHashList<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::remove(
         &this->m_hlVersions,
         &i_hVersion);
  v4 = v3;
  if ( v3 )
  {
    if ( v3 != &v2->m_vrDefaultRow )
    {
      if ( (v3->m_VersionRow.m_aVersions.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        operator delete[](v3->m_VersionRow.m_aVersions.m_data);
      operator delete(v4);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00410C30) --------------------------------------------------------  // acclient.c:76883
void __thiscall InArchiveVersionStack::Reset(InArchiveVersionStack *this)
{
  InArchiveVersionStack *v1; // ebx@1
  DLListData *v2; // eax@2
  int v3; // eax@3
  int v4; // ecx@6
  int v5; // ebp@6
  int v6; // eax@6
  int v7; // ecx@9
  DLListData *v8; // ecx@11
  DLListData *v9; // ecx@15
  int v10; // edx@17
  InArchiveVersionStack::VersionRowHolder **v11; // eax@17
  InArchiveVersionStack::VersionRowHolder *v12; // ecx@17
  int v13; // edi@17
  InArchiveVersionStack::VersionRowHolder *v14; // eax@17
  InArchiveVersionStack::VersionRowHolder *v15; // edx@23
  int iter; // [sp+4h] [bp-8h]@7

  v1 = this;
  if ( this->m_hlVersions.m_hash.m_numElements )
  {
    v2 = this->m_hlVersions.m_list.head_;
    if ( v2 )
    {
      v3 = (int)&v2[-1];
      if ( v3 )
      {
        while ( 1 )
        {
          v4 = *(_DWORD *)(v3 + 8);
          v5 = v3;
          v6 = v3 + 8;
          if ( v4 )
            iter = v4 - 8;
          else
            iter = 0;
          v7 = *(_DWORD *)(v6 + 4);
          if ( v7 )
          {
            *(_DWORD *)v7 = *(_DWORD *)v6;
          }
          else
          {
            v8 = v1->m_hlVersions.m_list.head_->dllist_next;
            v1->m_hlVersions.m_list.head_ = v8;
            if ( v8 )
              v8->dllist_prev = 0;
          }
          if ( *(_DWORD *)v6 )
          {
            *(_DWORD *)(*(_DWORD *)v6 + 4) = *(_DWORD *)(v6 + 4);
          }
          else
          {
            v9 = v1->m_hlVersions.m_list.tail_->dllist_prev;
            v1->m_hlVersions.m_list.tail_ = v9;
            if ( v9 )
              v9->dllist_next = 0;
          }
          *(_DWORD *)v6 = 0;
          *(_DWORD *)(v6 + 4) = 0;
          v10 = *(_DWORD *)v5 % v1->m_hlVersions.m_hash.m_numBuckets;
          v11 = v1->m_hlVersions.m_hash.m_buckets;
          v12 = v11[v10];
          v13 = (int)&v11[v10];
          v14 = v11[v10];
          if ( v14 )
          {
            while ( v14->m_hashKey.id != *(_DWORD *)v5 )
            {
              v14 = v14->m_hashNext;
              if ( !v14 )
                goto LABEL_28;
            }
            if ( v14 )
            {
              if ( v12 == v14 )
                goto LABEL_35;
              do
              {
                v15 = v12;
                v12 = v12->m_hashNext;
              }
              while ( v12 != v14 );
              if ( v15 )
                v15->m_hashNext = v12->m_hashNext;
              else
LABEL_35:
                *(_DWORD *)v13 = v12->m_hashNext;
              --v1->m_hlVersions.m_hash.m_numElements;
            }
          }
LABEL_28:
          if ( (InArchiveVersionStack::VersionRowHolder *)v5 != &v1->m_vrDefaultRow )
          {
            if ( (*(_DWORD *)(v5 + 24) & 0x80000000) == 0x80000000 )
              operator delete[](*(void **)(v5 + 20));
            operator delete((void *)v5);
          }
          if ( !iter )
            break;
          v3 = iter;
        }
      }
    }
  }
}

//----- (00410D60) --------------------------------------------------------  // acclient.c:76993
void __thiscall InArchiveVersionStack::~InArchiveVersionStack(InArchiveVersionStack *this)
{
  InArchiveVersionStack *v1; // esi@1
  void *v2; // eax@3

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&InArchiveVersionStack::vftable;
  InArchiveVersionStack::Reset(this);
  if ( (v1->m_vrDefaultRow.m_VersionRow.m_aVersions.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_vrDefaultRow.m_VersionRow.m_aVersions.m_data);
  v2 = v1->m_hlVersions.m_hash.m_buckets;
  v1->m_hlVersions.m_hash.vfptr = (IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>Vtbl *)&IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::vftable;
  if ( v2 != v1->m_hlVersions.m_hash.m_aInplaceBuckets )
    operator delete[](v2);
  v1->m_hlVersions.m_hash.m_buckets = 0;
  v1->m_hlVersions.m_hash.m_firstInterestingBucket = 0;
  v1->m_hlVersions.m_hash.m_numBuckets = 0;
  v1->m_hlVersions.m_hash.m_numElements = 0;
  v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 79442C: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::vftable)(void *, char);
// 794434: using guessed type __int32 (__stdcall *InArchiveVersionStack::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006C3B60) --------------------------------------------------------  // acclient.c:732133
int _E21_2()
{
  return atexit(_E22_2);
}

