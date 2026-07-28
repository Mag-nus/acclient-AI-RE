/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : cstable
   Object     : PORTAL\sound\cstable.obj
   Functions  : 50
   Addresses  : 00551CB0 - 007724D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00551CB0) --------------------------------------------------------  // acclient.c:384779
void __thiscall SoundData::SoundData(SoundData *this)
{
  this->sound_id_.id = 0;
  LODWORD(this->priority_) = 0;
  LODWORD(this->probability_) = 1065353216;
  LODWORD(this->volume_) = 1065353216;
}

//----- (00551CD0) --------------------------------------------------------  // acclient.c:384788
int __thiscall CSoundTable::UnPack(CSoundTable *this, void **addr, unsigned int size)
{
  CSoundTable *v3; // esi@1
  int v4; // eax@1
  int v5; // ecx@2

  v3 = this;
  ((void (__thiscall *)(SoundTableData **))this[-1].sound_data_.sound_hash_.m_aInplaceBuckets[18]->sound_hash_.m_aInplaceBuckets[11])(&this[-1].sound_data_.sound_hash_.m_aInplaceBuckets[18]);
  (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)&v3->m_bLoaded + 16))(&v3->m_bLoaded, addr, size);
  v4 = (signed int)*addr % 4;
  if ( v4 )
  {
    v5 = 4 - v4;
    if ( 4 != v4 )
    {
      do
      {
        *(_BYTE *)*addr = 0;
        --v5;
        *addr = (char *)*addr + 1;
      }
      while ( v5 );
    }
  }
  return 1;
}

//----- (00551D20) --------------------------------------------------------  // acclient.c:384816
IntrusiveHashTable<unsigned long,SoundTableData *,0> *__thiscall IntrusiveHashTable<unsigned long,SoundTableData *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,SoundTableData *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,SoundTableData *,0> *v2; // esi@1
  SoundTableData **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,SoundTableData *,0>Vtbl *)IntrusiveHashTable<unsigned long,SoundTableData *,0>::vftable;
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
// 7CB1CC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,SoundTableData *,0>::vftable[2])(void *, char);

//----- (00551D60) --------------------------------------------------------  // acclient.c:384837
void __thiscall SoundTableData::GetSubDataIDs(SoundTableData *this, QualifiedDataIDArray *id_array)
{
  SoundTableData *v2; // esi@1
  unsigned int v3; // edi@1
  int v4; // ebx@2
  QualifiedDataID *v5; // eax@3
  int v6; // ecx@4
  SoundTableData **v7; // eax@5
  int v8; // eax@6
  SoundTableData **v9; // ebx@8
  SoundTableData *v10; // edi@8
  QualifiedDataID v11; // [sp+10h] [bp-8h]@3

  v2 = this;
  v3 = 0;
  if ( this->num_stdatas_ )
  {
    v4 = 0;
    do
    {
      QualifiedDataID::QualifiedDataID(&v11, v2->data_[v4].sound_id_, 0);
      QualifiedDataIDArray::AddQDID(id_array, v5, 8u);
      ++v3;
      ++v4;
    }
    while ( v3 < v2->num_stdatas_ );
  }
  v6 = (int)&v2->sound_hash_.m_buckets[v2->sound_hash_.m_numBuckets];
  if ( v2->sound_hash_.m_firstInterestingBucket != (SoundTableData **)v6 )
  {
    while ( 1 )
    {
      v7 = v2->sound_hash_.m_firstInterestingBucket;
      if ( *v7 )
        break;
      v8 = (int)(v7 + 1);
      v2->sound_hash_.m_firstInterestingBucket = (SoundTableData **)v8;
      if ( v8 == v6 )
        return;
    }
    v9 = v2->sound_hash_.m_firstInterestingBucket;
    v10 = *v9;
    if ( *v9 )
    {
      do
      {
LABEL_9:
        SoundTableData::GetSubDataIDs(v10, id_array);
        v10 = v10->m_hashNext;
      }
      while ( v10 );
      while ( 1 )
      {
        ++v9;
        if ( v9 == &v2->sound_hash_.m_buckets[v2->sound_hash_.m_numBuckets] )
          break;
        if ( *v9 )
        {
          v10 = *v9;
          if ( *v9 )
            goto LABEL_9;
          return;
        }
      }
    }
  }
}

//----- (00551E20) --------------------------------------------------------  // acclient.c:384906
int __thiscall SoundTableData::pack_size(SoundTableData *this)
{
  SoundTableData *v1; // ebx@1
  unsigned int v2; // eax@1
  int v3; // ebp@1
  SoundTableData **v4; // ecx@3
  int v5; // ebp@3
  SoundTableData **v6; // eax@4
  int v7; // eax@5
  SoundTableData **v9; // edi@7
  SoundTableData *v10; // esi@7
  unsigned int v11; // eax@8

  v1 = this;
  v2 = this->num_stdatas_;
  v3 = 8;
  if ( v2 )
    v3 = 16 * v2 + 8;
  v4 = &this->sound_hash_.m_buckets[this->sound_hash_.m_numBuckets];
  v5 = v3 + 4;
  if ( v1->sound_hash_.m_firstInterestingBucket != v4 )
  {
    while ( 1 )
    {
      v6 = v1->sound_hash_.m_firstInterestingBucket;
      if ( *v6 )
        break;
      v7 = (int)(v6 + 1);
      v1->sound_hash_.m_firstInterestingBucket = (SoundTableData **)v7;
      if ( (SoundTableData **)v7 == v4 )
        return v5;
    }
    v9 = v1->sound_hash_.m_firstInterestingBucket;
    v10 = *v9;
    if ( *v9 )
    {
      do
      {
LABEL_8:
        v11 = SoundTableData::pack_size(v10);
        v10 = v10->m_hashNext;
        v5 += v11;
      }
      while ( v10 );
      while ( 1 )
      {
        ++v9;
        if ( v9 == &v1->sound_hash_.m_buckets[v1->sound_hash_.m_numBuckets] )
          break;
        if ( *v9 )
        {
          v10 = *v9;
          if ( *v9 )
            goto LABEL_8;
          return v5;
        }
      }
    }
  }
  return v5;
}

//----- (00551EB0) --------------------------------------------------------  // acclient.c:384969
int __thiscall SoundTableData::Pack(SoundTableData *this, void **addr, unsigned int size)
{
  SoundTableData *v3; // edi@1
  int result; // eax@1
  char *v5; // edx@2
  char *v6; // ecx@2
  unsigned int v7; // ebp@2
  int v8; // ebx@3
  int v9; // eax@4
  char *v10; // ecx@5
  char *v11; // edx@5
  char *v12; // ecx@5
  char *v13; // eax@5
  int v14; // ecx@7
  int v15; // ebp@7
  SoundTableData **v16; // eax@8
  int v17; // eax@9
  SoundTableData **v18; // eax@11
  SoundTableData *i; // ecx@11
  int v20; // ecx@17
  SoundTableData **v21; // eax@18
  int v22; // eax@19
  SoundTableData **v23; // eax@20
  SoundTableData *v24; // ebx@20
  SoundTableData **v25; // ebp@22
  int v26; // ecx@27
  int v27; // eax@28
  unsigned int retval; // [sp+8h] [bp-4h]@1

  v3 = this;
  result = SoundTableData::pack_size(this);
  retval = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->m_hashKey;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->num_stdatas_;
    v6 = (char *)*addr + 4;
    *addr = v6;
    v7 = 0;
    if ( v3->num_stdatas_ )
    {
      v8 = 0;
      do
      {
        v9 = (int)&v3->data_[v8];
        if ( size >= 0x10 )
        {
          *(_DWORD *)v6 = *(_DWORD *)v9;
          v10 = (char *)*addr + 4;
          *addr = v10;
          *(float *)v10 = *(float *)(v9 + 4);
          v11 = (char *)*addr + 4;
          *addr = v11;
          *(float *)v11 = *(float *)(v9 + 8);
          v12 = (char *)*addr + 4;
          *addr = v12;
          *(float *)v12 = *(float *)(v9 + 12);
          v13 = (char *)*addr + 4;
          *addr = v13;
          v6 = v13;
        }
        ++v7;
        ++v8;
      }
      while ( v7 < v3->num_stdatas_ );
    }
    v14 = (int)&v3->sound_hash_.m_buckets[v3->sound_hash_.m_numBuckets];
    v15 = 0;
    if ( v3->sound_hash_.m_firstInterestingBucket != (SoundTableData **)v14 )
    {
      while ( 1 )
      {
        v16 = v3->sound_hash_.m_firstInterestingBucket;
        if ( *v16 )
          break;
        v17 = (int)(v16 + 1);
        v3->sound_hash_.m_firstInterestingBucket = (SoundTableData **)v17;
        if ( v17 == v14 )
          goto LABEL_17;
      }
      v18 = v3->sound_hash_.m_firstInterestingBucket;
      for ( i = *v18; i; ++v15 )
      {
        i = i->m_hashNext;
        if ( !i )
        {
          while ( 1 )
          {
            ++v18;
            if ( v18 == &v3->sound_hash_.m_buckets[v3->sound_hash_.m_numBuckets] )
              break;
            if ( *v18 )
            {
              i = *v18;
              break;
            }
          }
        }
      }
    }
LABEL_17:
    *(_DWORD *)*addr = v15;
    *addr = (char *)*addr + 4;
    v20 = (int)&v3->sound_hash_.m_buckets[v3->sound_hash_.m_numBuckets];
    if ( v3->sound_hash_.m_firstInterestingBucket == (SoundTableData **)v20 )
    {
LABEL_20:
      v23 = 0;
      v24 = 0;
    }
    else
    {
      while ( 1 )
      {
        v21 = v3->sound_hash_.m_firstInterestingBucket;
        if ( *v21 )
          break;
        v22 = (int)(v21 + 1);
        v3->sound_hash_.m_firstInterestingBucket = (SoundTableData **)v22;
        if ( v22 == v20 )
          goto LABEL_20;
      }
      v23 = v3->sound_hash_.m_firstInterestingBucket;
      v24 = *v23;
    }
    v25 = v23;
    if ( v24 )
    {
      do
      {
LABEL_23:
        ((void (__thiscall *)(SoundTableData *, void **, unsigned int))v24->vfptr->Pack)(v24, addr, size);
        v24 = v24->m_hashNext;
      }
      while ( v24 );
      while ( 1 )
      {
        ++v25;
        if ( v25 == &v3->sound_hash_.m_buckets[v3->sound_hash_.m_numBuckets] )
          break;
        if ( *v25 )
        {
          v24 = *v25;
          if ( *v25 )
            goto LABEL_23;
          break;
        }
      }
    }
    v26 = (signed int)*addr % 4;
    if ( v26 )
    {
      v27 = 4 - v26;
      if ( 4 != v26 )
      {
        do
        {
          *(_BYTE *)*addr = 0;
          --v27;
          *addr = (char *)*addr + 1;
        }
        while ( v27 );
      }
    }
    result = retval;
  }
  return result;
}

//----- (00552050) --------------------------------------------------------  // acclient.c:385141
void __thiscall CSoundTable::GetSubDataIDs(CSoundTable *this, QualifiedDataIDArray *id_array)
{
  SoundTableData::GetSubDataIDs(&this->sound_data_, id_array);
}

//----- (00552060) --------------------------------------------------------  // acclient.c:385147
int __thiscall CSoundTable::Pack(CSoundTable *this, void **addr, unsigned int size)
{
  char *v3; // esi@1
  int v4; // edi@1

  v3 = (char *)&this->m_bLoaded;
  v4 = SoundTableData::pack_size((SoundTableData *)&this->m_bLoaded);
  if ( size >= v4 )
  {
    (*(void (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v3 + 12))(v3, addr, size);
    PackObj::ALIGN_PTR(addr);
  }
  return v4;
}

//----- (005520A0) --------------------------------------------------------  // acclient.c:385163
int __thiscall SoundTableData::Lookup(SoundTableData *this, SoundType stype, SoundTableData **lookup_stdata)
{
  int result; // eax@1

  result = (int)this->sound_hash_.m_buckets[stype % this->sound_hash_.m_numBuckets];
  if ( !result )
    goto LABEL_10;
  while ( *(_DWORD *)(result + 4) != stype )
  {
    result = *(_DWORD *)(result + 8);
    if ( !result )
    {
      *lookup_stdata = 0;
      return result;
    }
  }
  if ( result )
  {
    *lookup_stdata = (SoundTableData *)result;
    result = 1;
  }
  else
  {
LABEL_10:
    *lookup_stdata = 0;
    result = 0;
  }
  return result;
}

//----- (00552100) --------------------------------------------------------  // acclient.c:385194
int __thiscall CSoundTable::Lookup(CSoundTable *this, SoundType stype, SoundTableData **lookup_stdata)
{
  return SoundTableData::Lookup(&this->sound_data_, stype, lookup_stdata);
}

//----- (00552110) --------------------------------------------------------  // acclient.c:385200
void __thiscall IntrusiveHashTable<unsigned long,SoundTableData *,0>::IntrusiveHashTable<unsigned long,SoundTableData *,0>(IntrusiveHashTable<unsigned long,SoundTableData *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,SoundTableData *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,SoundTableData *,0>Vtbl *)IntrusiveHashTable<unsigned long,SoundTableData *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (SoundTableData **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (SoundTableData **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7CB1CC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,SoundTableData *,0>::vftable[2])(void *, char);

//----- (005521A0) --------------------------------------------------------  // acclient.c:385233
void __thiscall SoundTableData::SoundTableData(SoundTableData *this)
{
  SoundTableData *v1; // esi@1
  void *v2; // eax@1
  int v3; // eax@2

  v1 = this;
  this->m_hashNext = 0;
  this->vfptr = (PackObjVtbl *)&SoundTableData::vftable;
  IntrusiveHashTable<unsigned long,SoundTableData *,0>::IntrusiveHashTable<unsigned long,SoundTableData *,0>(
    &this->sound_hash_,
    4u);
  v1->num_stdatas_ = 0;
  v1->data_ = 0;
  v1->m_hashKey = 0;
  v2 = operator new[](0x14u);
  if ( v2 )
  {
    *(_DWORD *)v2 = 1;
    v3 = (int)((char *)v2 + 4);
    *(_DWORD *)v3 = 0;
    *(_DWORD *)(v3 + 4) = 0;
    *(_DWORD *)(v3 + 8) = 1065353216;
    *(_DWORD *)(v3 + 12) = 1065353216;
    v1->data_ = (SoundData *)v3;
    ++v1->num_stdatas_;
  }
  else
  {
    v1->data_ = 0;
    ++v1->num_stdatas_;
  }
}
// 7CB1D0: using guessed type int (__thiscall *SoundTableData::vftable)(void *, char);

//----- (00552210) --------------------------------------------------------  // acclient.c:385269
char __thiscall IntrusiveHashTable<unsigned long,SoundTableData *,0>::add(IntrusiveHashTable<unsigned long,SoundTableData *,0> *this, SoundTableData *data)
{
  unsigned int v2; // ebx@1
  SoundTableData **v3; // ebp@1
  SoundTableData *v4; // eax@1
  SoundTableData **v5; // eax@4
  char result; // al@6

  v2 = this->m_numBuckets;
  v3 = this->m_buckets;
  v4 = v3[data->m_hashKey % v2];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != data->m_hashKey )
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
    v5 = &v3[data->m_hashKey % v2];
    data->m_hashNext = *v5;
    *v5 = data;
    if ( v5 < this->m_firstInterestingBucket )
      this->m_firstInterestingBucket = v5;
    ++this->m_numElements;
    result = 1;
  }
  return result;
}

//----- (00552280) --------------------------------------------------------  // acclient.c:385307
void __thiscall IntrusiveHashTable<unsigned long,SoundTableData *,0>::delete_contents(IntrusiveHashTable<unsigned long,SoundTableData *,0> *this)
{
  IntrusiveHashTable<unsigned long,SoundTableData *,0> *v1; // esi@1
  int v2; // ecx@2
  SoundTableData **v3; // eax@3
  int v4; // eax@4
  SoundTableData **v5; // edi@5
  SoundTableData *v6; // ecx@5
  SoundTableData *v7; // eax@7
  SoundTableData *v8; // edx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (SoundTableData **)v2 )
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
        v1->m_firstInterestingBucket = (SoundTableData **)v4;
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
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_17:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
      ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
  }
}

//----- (00552300) --------------------------------------------------------  // acclient.c:385364
void __thiscall SoundTableData::Destroy(SoundTableData *this)
{
  SoundTableData *v1; // esi@1
  unsigned int v2; // ebx@1
  int v3; // edi@2
  IDClass<_tagDataID,32,0> v4; // ecx@3
  SoundData *v5; // eax@6

  v1 = this;
  IntrusiveHashTable<unsigned long,SoundTableData *,0>::delete_contents(&this->sound_hash_);
  v2 = 0;
  if ( v1->num_stdatas_ )
  {
    v3 = 0;
    do
    {
      v4.id = v1->data_[v3].sound_id_.id;
      if ( v4.id )
        SoundManager::DestroySound(v4);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->num_stdatas_ );
  }
  v5 = v1->data_;
  v1->num_stdatas_ = 0;
  if ( v5 )
  {
    operator delete[](&v5[-1].volume_);
    v1->data_ = 0;
  }
}

//----- (00552370) --------------------------------------------------------  // acclient.c:385398
int __thiscall SoundTableData::UnPack(SoundTableData *this, void **addr, unsigned int size)
{
  SoundTableData *v3; // edi@1
  void **v4; // esi@1
  unsigned int v5; // ecx@1
  SoundData *v6; // eax@1
  unsigned int v7; // ebx@3
  void *v8; // eax@3
  int v9; // edx@4
  int v10; // eax@4
  unsigned int v11; // ecx@5
  int v12; // eax@7
  int v13; // ebx@10
  int v14; // eax@11
  int v15; // edx@12
  int v16; // edx@12
  int v17; // ecx@12
  IDClass<_tagDataID,32,0> v18; // ecx@13
  unsigned int v19; // ecx@16
  unsigned int v20; // ebx@17
  void *v21; // eax@18
  SoundTableData *v22; // edi@18
  void *v23; // eax@19
  int v24; // eax@20
  void **addra; // [sp+14h] [bp+4h]@9
  void **addrb; // [sp+14h] [bp+4h]@17

  v3 = this;
  SoundTableData::Destroy(this);
  v4 = addr;
  v5 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  v3->m_hashKey = v5;
  v3->num_stdatas_ = *(_DWORD *)*addr;
  *v4 = (char *)*v4 + 4;
  v6 = v3->data_;
  if ( v6 )
    operator delete[](&v6[-1].volume_);
  v7 = v3->num_stdatas_;
  v8 = operator new[](16 * v3->num_stdatas_ + 4);
  if ( v8 )
  {
    v9 = (int)((char *)v8 + 4);
    *(_DWORD *)v8 = v7;
    v10 = (int)((char *)v8 + 4);
    if ( ((v7 - 1) & 0x80000000) == 0 )
    {
      v11 = v7;
      do
      {
        *(_DWORD *)v10 = 0;
        *(_DWORD *)(v10 + 4) = 0;
        *(_DWORD *)(v10 + 8) = 1065353216;
        *(_DWORD *)(v10 + 12) = 1065353216;
        v10 += 16;
        --v11;
      }
      while ( v11 );
    }
    v12 = v9;
  }
  else
  {
    v12 = 0;
  }
  v3->data_ = (SoundData *)v12;
  addra = 0;
  if ( v3->num_stdatas_ )
  {
    v13 = 0;
    do
    {
      v14 = (int)&v3->data_[v13];
      if ( size >= 0x10 )
      {
        v15 = *(_DWORD *)*v4;
        *v4 = (char *)*v4 + 4;
        *(_DWORD *)v14 = v15;
        *(_DWORD *)(v14 + 4) = *(_DWORD *)*v4;
        v16 = (int)((char *)*v4 + 4);
        *v4 = (void *)v16;
        *(_DWORD *)(v14 + 8) = *(_DWORD *)v16;
        v17 = (int)((char *)*v4 + 4);
        *v4 = (void *)v17;
        *(_DWORD *)(v14 + 12) = *(_DWORD *)v17;
        *v4 = (char *)*v4 + 4;
      }
      v18.id = v3->data_[v13].sound_id_.id;
      if ( v18.id )
        SoundManager::CreateSound(v18);
      ++v13;
      addra = (void **)((char *)addra + 1);
    }
    while ( (unsigned int)addra < v3->num_stdatas_ );
  }
  v19 = *(_DWORD *)*v4;
  *v4 = (char *)*v4 + 4;
  if ( v19 > 0 )
  {
    addrb = (void **)&v3->sound_hash_.vfptr;
    v20 = v19;
    do
    {
      v21 = operator new(0x84u);
      v22 = (SoundTableData *)v21;
      if ( v21 )
      {
        *((_DWORD *)v21 + 2) = 0;
        *(_DWORD *)v21 = &SoundTableData::vftable;
        IntrusiveHashTable<unsigned long,SoundTableData *,0>::IntrusiveHashTable<unsigned long,SoundTableData *,0>(
          (IntrusiveHashTable<unsigned long,SoundTableData *,0> *)((char *)v21 + 12),
          4u);
        v22->num_stdatas_ = 0;
        v22->data_ = 0;
        v22->m_hashKey = 0;
        v23 = operator new[](0x14u);
        if ( v23 )
        {
          *(_DWORD *)v23 = 1;
          v24 = (int)((char *)v23 + 4);
          *(_DWORD *)v24 = 0;
          *(_DWORD *)(v24 + 4) = 0;
          *(_DWORD *)(v24 + 8) = 1065353216;
          *(_DWORD *)(v24 + 12) = 1065353216;
          v22->data_ = (SoundData *)v24;
          ++v22->num_stdatas_;
        }
        else
        {
          v22->data_ = 0;
          ++v22->num_stdatas_;
        }
      }
      else
      {
        v22 = 0;
      }
      ((void (__thiscall *)(SoundTableData *, void **, unsigned int))v22->vfptr->UnPack)(v22, v4, size);
      IntrusiveHashTable<unsigned long,SoundTableData *,0>::add(
        (IntrusiveHashTable<unsigned long,SoundTableData *,0> *)addrb,
        v22);
      --v20;
    }
    while ( v20 );
  }
  return 1;
}
// 7CB1D0: using guessed type int (__thiscall *SoundTableData::vftable)(void *, char);

//----- (00552530) --------------------------------------------------------  // acclient.c:385548
void __thiscall CSoundTable::CSoundTable(CSoundTable *this, IDClass<_tagDataID,32,0> gid)
{
  CSoundTable *v2; // esi@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, gid);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (InterfaceVtbl *)&CSoundTable::vftable;
  v2->vfptr = (PackObjVtbl *)&CSoundTable::vftable;
  SoundTableData::SoundTableData(&v2->sound_data_);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CB1E4: using guessed type void *CSoundTable::vftable;
// 7CB1F8: using guessed type __int32 (__stdcall *CSoundTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00552560) --------------------------------------------------------  // acclient.c:385564
signed int CSoundTable::GetDBOType()
{
  return 34;
}

//----- (00552570) --------------------------------------------------------  // acclient.c:385570
CSoundTable *__thiscall CSoundTable::vector_deleting_destructor(CSoundTable *this, unsigned int a2)
{
  return CSoundTable::scalar_deleting_destructor((CSoundTable *)((char *)this - 48), a2);
}

//----- (00552580) --------------------------------------------------------  // acclient.c:385576
void __thiscall CSoundTable::~CSoundTable(CSoundTable *this)
{
  CSoundTable *v1; // edi@1
  char *v2; // esi@1
  void *v3; // eax@1

  v1 = this;
  v2 = (char *)&this->sound_data_;
  this->vfptr = (InterfaceVtbl *)&CSoundTable::vftable;
  this->vfptr = (PackObjVtbl *)&CSoundTable::vftable;
  this->sound_data_.vfptr = (PackObjVtbl *)&SoundTableData::vftable;
  SoundTableData::Destroy(&this->sound_data_);
  v3 = (void *)*((_DWORD *)v2 + 27);
  *((_DWORD *)v2 + 3) = IntrusiveHashTable<unsigned long,SoundTableData *,0>::vftable;
  if ( v3 != v2 + 16 )
    operator delete[](v3);
  *((_DWORD *)v2 + 27) = 0;
  *((_DWORD *)v2 + 28) = 0;
  *((_DWORD *)v2 + 29) = 0;
  *((_DWORD *)v2 + 30) = 0;
  *(_DWORD *)v2 = &PackObj::vftable;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CB1CC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,SoundTableData *,0>::vftable[2])(void *, char);
// 7CB1D0: using guessed type int (__thiscall *SoundTableData::vftable)(void *, char);
// 7CB1E4: using guessed type void *CSoundTable::vftable;
// 7CB1F8: using guessed type __int32 (__stdcall *CSoundTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005525F0) --------------------------------------------------------  // acclient.c:385607
SoundTableData *__thiscall SoundTableData::scalar_deleting_destructor(SoundTableData *this, unsigned int a2)
{
  SoundTableData *v2; // esi@1
  void *v3; // eax@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&SoundTableData::vftable;
  SoundTableData::Destroy(this);
  v3 = v2->sound_hash_.m_buckets;
  v2->sound_hash_.vfptr = (IntrusiveHashTable<unsigned long,SoundTableData *,0>Vtbl *)IntrusiveHashTable<unsigned long,SoundTableData *,0>::vftable;
  if ( v3 != v2->sound_hash_.m_aInplaceBuckets )
    operator delete[](v3);
  v2->sound_hash_.m_buckets = 0;
  v2->sound_hash_.m_firstInterestingBucket = 0;
  v2->sound_hash_.m_numBuckets = 0;
  v2->sound_hash_.m_numElements = 0;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CB1CC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,SoundTableData *,0>::vftable[2])(void *, char);
// 7CB1D0: using guessed type int (__thiscall *SoundTableData::vftable)(void *, char);

//----- (00552650) --------------------------------------------------------  // acclient.c:385633
CSoundTable *__thiscall CSoundTable::scalar_deleting_destructor(CSoundTable *this, unsigned int a2)
{
  CSoundTable *v2; // esi@1

  v2 = this;
  CSoundTable::~CSoundTable(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00706A10) --------------------------------------------------------  // acclient.c:793899
int sub_706A10()
{
  return atexit(_E74_75);
}

//----- (00706A20) --------------------------------------------------------  // acclient.c:793905
int _E76_61()
{
  return atexit(_E77_89);
}

//----- (00706A30) --------------------------------------------------------  // acclient.c:793911
int _E79_55()
{
  return atexit(_E80_54);
}

//----- (00706A40) --------------------------------------------------------  // acclient.c:793917
int _E82_36()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_18, "Sound.SoundDisabled");
  return atexit(_E83_34);
}

//----- (00706A60) --------------------------------------------------------  // acclient.c:793924
int _E85_25()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_18, "Sound.SoundVolume");
  return atexit(_E86_22);
}

//----- (00706A80) --------------------------------------------------------  // acclient.c:793931
int _E88_19()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_18, "Sound.AmbientSoundDisabled");
  return atexit(_E89_32);
}

//----- (00706AA0) --------------------------------------------------------  // acclient.c:793938
int sub_706AA0()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_18, "Sound.AmbientSoundVolume");
  return atexit(_E92_37);
}

//----- (00706AC0) --------------------------------------------------------  // acclient.c:793945
int _E94_25()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_18, "Sound.InterfaceSoundDisabled");
  return atexit(sub_772410);
}

//----- (00706AE0) --------------------------------------------------------  // acclient.c:793952
int sub_706AE0()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_18, "Sound.InterfaceSoundVolume");
  return atexit(sub_772440);
}

//----- (00706B00) --------------------------------------------------------  // acclient.c:793959
int sub_706B00()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_18, "Sound.SoundFeatures");
  return atexit(sub_772470);
}

//----- (00706B20) --------------------------------------------------------  // acclient.c:793966
int sub_706B20()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_18, "Sound.PlaySoundOnlyWhenActive");
  return atexit(sub_7724A0);
}

//----- (00706B40) --------------------------------------------------------  // acclient.c:793973
int sub_706B40()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_18, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_86F6C8, "Mono");
  return atexit(_E107_91);
}

//----- (00706B70) --------------------------------------------------------  // acclient.c:793981
void _E125_9()
{
  LODWORD(dword_86F6CC) = 1053364187;
}

//----- (00706B80) --------------------------------------------------------  // acclient.c:793987
void _E127_51()
{
  flt_86F6D0 = 1000.0 + 1.0;
}

//----- (00706BA0) --------------------------------------------------------  // acclient.c:793993
void _E129_40()
{
  flt_86F6D4 = 24.0 * 8.0;
}

//----- (00706BC0) --------------------------------------------------------  // acclient.c:793999
void _E131_6()
{
  flt_86F6D8 = 24.0 * 0.5;
}

//----- (00706BE0) --------------------------------------------------------  // acclient.c:794005
void _E133_39()
{
  VOL_MIN_DIST_SQ_15 = 5.0 * 5.0;
}

//----- (00706C00) --------------------------------------------------------  // acclient.c:794011
void _E135_47()
{
  INV_LOG_OF_2_15 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (00706C20) --------------------------------------------------------  // acclient.c:794017
int sub_706C20()
{
  return atexit(nullsub_1254);
}

//----- (00772350) --------------------------------------------------------  // acclient.c:906109
void __cdecl _E83_34()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772380) --------------------------------------------------------  // acclient.c:906122
void __cdecl _E86_22()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007723B0) --------------------------------------------------------  // acclient.c:906135
void __cdecl _E89_32()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007723E0) --------------------------------------------------------  // acclient.c:906148
void __cdecl _E92_37()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772410) --------------------------------------------------------  // acclient.c:906161
void __cdecl sub_772410()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772440) --------------------------------------------------------  // acclient.c:906174
void __cdecl sub_772440()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772470) --------------------------------------------------------  // acclient.c:906187
void __cdecl sub_772470()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007724A0) --------------------------------------------------------  // acclient.c:906200
void __cdecl sub_7724A0()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007724D0) --------------------------------------------------------  // acclient.c:906213
void __cdecl _E107_91()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &dword_86F6CC;
  v1 = 2;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
    --v0;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

