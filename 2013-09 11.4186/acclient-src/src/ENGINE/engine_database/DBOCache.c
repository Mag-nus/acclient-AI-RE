/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DBOCache
   Object     : ENGINE\engine_database\DBOCache.obj
   Functions  : 34
   Addresses  : 004166B0 - 006C49C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004166B0) --------------------------------------------------------  // acclient.c:83016
char __thiscall DBOCache::AddObj(DBOCache *this, DBObj *obj_p)
{
  char result; // al@2

  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))this->vfptr->AddObj_Internal)(obj_p) )
  {
    ++obj_p->m_numLinks;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004166D0) --------------------------------------------------------  // acclient.c:83033
bool __thiscall DBOCache::KeepFreeObjects(DBOCache *this, bool keep_f)
{
  bool v2; // bl@1

  v2 = this->m_fKeepFreeObjs;
  if ( this->m_fCanKeepFreeObjs )
  {
    this->m_fKeepFreeObjs = keep_f;
    if ( v2 && !keep_f )
      ((void (*)(void))this->vfptr->FlushFreeObjects)();
  }
  return v2;
}

//----- (00416700) --------------------------------------------------------  // acclient.c:83048
void __thiscall DBOCache::FreeObject(DBOCache *this, DBObj *object_p)
{
  DBOCache *v2; // edi@1

  v2 = this;
  if ( object_p )
  {
    object_p->vfptr[1].Release((Interface *)object_p);
    object_p->m_bLoaded = 0;
    if ( v2->m_fKeepFreeObjs && object_p->m_AllowedInFreeList )
    {
      if ( v2->m_bFreelistActive )
        v2->vfptr->FreelistAdd(v2, object_p);
    }
    else
    {
      v2->vfptr->DestroyObj(v2, object_p);
    }
  }
}

//----- (00416750) --------------------------------------------------------  // acclient.c:83070
void __thiscall DBOCache::FreelistRemove(DBOCache *this, DBObj *object_p)
{
  DBObj *v2; // edx@1
  DBObj *v3; // esi@3
  DBObj *v4; // edx@6

  v2 = object_p->m_pLast;
  if ( v2 || this->m_pOldestFree == object_p )
  {
    v3 = object_p->m_pNext;
    if ( v3 )
      v3->m_pLast = v2;
    else
      this->m_pYoungestFree = v2;
    v4 = object_p->m_pLast;
    if ( v4 )
      v4->m_pNext = object_p->m_pNext;
    else
      this->m_pOldestFree = object_p->m_pNext;
    object_p->m_pLast = 0;
    object_p->m_pNext = 0;
    --this->m_nFree;
  }
}

//----- (004167B0) --------------------------------------------------------  // acclient.c:83096
DBObj *__thiscall DBOCache::FreelistRemoveOldest(DBOCache *this)
{
  DBObj *v1; // esi@1

  v1 = this->m_pOldestFree;
  if ( v1 )
    ((void (__stdcall *)(DBObj *))this->vfptr->FreelistRemove)(this->m_pOldestFree);
  return v1;
}

//----- (004167D0) --------------------------------------------------------  // acclient.c:83107
int __thiscall DBOCache::GetFreeObj(DBOCache *this)
{
  DBOCache *v1; // esi@1
  DBObj *v2; // edi@3
  int result; // eax@4

  v1 = this;
  if ( this->m_freelistDef.m_bRecycle
    && this->m_nFree > this->m_freelistDef.m_nIdealSize
    && (v2 = (DBObj *)((int (*)(void))this->vfptr->FreelistRemoveOldest)()) != 0 )
  {
    v1->vfptr->RemoveObj_Internal(v1, v2);
    ((void (__thiscall *)(DBObj *))v2->vfptr[2].QueryInterface)(v2);
    result = (int)v2;
  }
  else
  {
    result = (int)v1->m_pfnAllocator();
  }
  return result;
}

//----- (00416820) --------------------------------------------------------  // acclient.c:83130
void __thiscall DBOCache::UseTime(DBOCache *this)
{
  DBOCache *v1; // esi@1
  DBObj *v2; // edi@2

  v1 = this;
  if ( this->m_nFree > this->m_freelistDef.m_nIdealSize )
  {
    v2 = this->m_pOldestFree;
    if ( v2 )
    {
      if ( v2->m_timeStamp + 30.0 < COERCE_DOUBLE(Timer::cur_time.Cmd) )
      {
        ((void (__stdcall *)(_DWORD))this->vfptr->FreelistRemove)(this->m_pOldestFree);
        v1->vfptr->DestroyObj(v1, v2);
      }
    }
  }
}

//----- (00416870) --------------------------------------------------------  // acclient.c:83151
void __thiscall DBOCache::FlushFreeObjects(DBOCache *this)
{
  DBOCache *i; // esi@1
  int v2; // eax@3

  for ( i = this; i->m_nFree; i->vfptr->DestroyObj(i, (DBObj *)v2) )
    v2 = (int)i->vfptr->FreelistRemoveOldest(i);
}

//----- (00416890) --------------------------------------------------------  // acclient.c:83161
int __thiscall DBOCache::ReloadObject(DBOCache *this, IDClass<_tagDataID,32,0> id)
{
  return ((int (__thiscall *)(_DWORD, _DWORD, _DWORD))DBCache::s_pCache->vfptr[2].IUnknown_AddRef)(
           DBCache::s_pCache,
           id.id,
           this->m_dbtype);
}

//----- (004168B0) --------------------------------------------------------  // acclient.c:83170
void __thiscall DBOCache::FreelistAdd(DBOCache *this, DBObj *object_p)
{
  DBOCache *v2; // esi@1
  DBObj *v3; // ecx@3
  unsigned int v4; // ecx@6
  int v5; // edx@6
  int v6; // eax@7

  object_p->m_timeStamp = *(double *)&Timer::cur_time;
  v2 = this;
  if ( object_p->m_AllowedInFreeList && this->m_fKeepFreeObjs )
  {
    v3 = this->m_pYoungestFree;
    if ( v3 )
    {
      v3->m_pNext = object_p;
      object_p->m_pLast = v2->m_pYoungestFree;
    }
    else
    {
      v2->m_pOldestFree = object_p;
    }
    v4 = v2->m_freelistDef.m_nMaxSize;
    v5 = v2->m_nFree + 1;
    v2->m_pYoungestFree = object_p;
    v2->m_nFree = v5;
    if ( v5 > v4 )
    {
      v6 = (int)v2->vfptr->FreelistRemoveOldest(v2);
      v2->vfptr->DestroyObj(v2, (DBObj *)v6);
    }
  }
}

//----- (00416930) --------------------------------------------------------  // acclient.c:83205
IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1> *__thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::vector_deleting_destructor(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1> *v2; // esi@1
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::vftable;
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
// 795338: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::vftable[3])(void *, char);

//----- (00416970) --------------------------------------------------------  // acclient.c:83226
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0> *v2; // esi@1
  HashTableData<unsigned long,float> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>::vftable;
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
// 79533C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>::vftable[2])(void *, char);

//----- (00416A00) --------------------------------------------------------  // acclient.c:83286
bool __thiscall DBOCache::IsInMemory(DBOCache *this, IDClass<_tagDataID,32,0> did)
{
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *v2; // eax@1
  bool v3; // zf@1

  v2 = this->m_ObjTable.m_intrusiveTable.m_buckets[did.id % this->m_ObjTable.m_intrusiveTable.m_numBuckets];
  v3 = v2 == 0;
  if ( v2 )
  {
    do
    {
      if ( v2->m_hashKey.id == did.id )
        break;
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    v3 = v2 == 0;
  }
  return !v3;
}

//----- (00416A30) --------------------------------------------------------  // acclient.c:83308
void __thiscall DBOCache::DestroyObj(DBOCache *this, DBObj *object_p)
{
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *v2; // eax@1
  bool v3; // zf@7

  v2 = this->m_ObjTable.m_intrusiveTable.m_buckets[object_p->m_DID.id % this->m_ObjTable.m_intrusiveTable.m_numBuckets];
  if ( v2 )
  {
    while ( v2->m_hashKey.id != object_p->m_DID.id )
    {
      v2 = v2->m_hashNext;
      if ( !v2 )
        goto LABEL_7;
    }
    if ( v2 )
      ((void (__stdcall *)(_DWORD))this->vfptr->RemoveObj_Internal)(object_p);
  }
LABEL_7:
  v3 = object_p->m_numLinks-- == 1;
  if ( v3 )
    ((void (__thiscall *)(_DWORD, _DWORD))object_p->vfptr[1].IUnknown_QueryInterface)(object_p, 1);
}

//----- (00416A80) --------------------------------------------------------  // acclient.c:83332
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,float> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,float> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79533C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>::vftable[2])(void *, char);

//----- (00416B10) --------------------------------------------------------  // acclient.c:83365
void __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<IDClass<_tagDataID,32,0>,DBObj *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,DBObj *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 795338: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::vftable[3])(void *, char);

//----- (00416BA0) --------------------------------------------------------  // acclient.c:83398
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::grow(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::resize_internal(
           v2,
           *v3);
}

//----- (00416BF0) --------------------------------------------------------  // acclient.c:83418
bool __thiscall DBOCache::RemoveObj(DBOCache *this, IDClass<_tagDataID,32,0> did)
{
  DBOCache *v2; // esi@1
  DBObj *v3; // edi@1
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *v4; // eax@1
  bool v6; // zf@6

  v2 = this;
  v3 = 0;
  v4 = this->m_ObjTable.m_intrusiveTable.m_buckets[did.id % this->m_ObjTable.m_intrusiveTable.m_numBuckets];
  if ( v4 )
  {
    while ( v4->m_hashKey.id != did.id )
    {
      v4 = v4->m_hashNext;
      if ( !v4 )
        return 0;
    }
    if ( v4 )
    {
      v3 = v4->m_data;
      this->vfptr->FreelistRemove(this, v4->m_data);
      v2->vfptr->RemoveObj_Internal(v2, v3);
      v6 = v3->m_numLinks-- == 1;
      if ( v6 )
        ((void (__thiscall *)(DBObj *, signed int))v3->vfptr[1].IUnknown_QueryInterface)(v3, 1);
    }
  }
  return v3 != 0;
}

//----- (00416C60) --------------------------------------------------------  // acclient.c:83450
int __thiscall DBOCache::GetIfInMemory(void *this, unsigned int a2, char a3)
{
  int v3; // eax@1
  int v5; // esi@6
  char v6; // al@9

  v3 = *(_DWORD *)(*((_DWORD *)this + 26) + 4 * (a2 % *((_DWORD *)this + 28)));
  if ( !v3 )
    return 0;
  while ( *(_DWORD *)v3 != a2 )
  {
    v3 = *(_DWORD *)(v3 + 4);
    if ( !v3 )
      return 0;
  }
  if ( !v3 )
    return 0;
  v5 = *(_DWORD *)(v3 + 8);
  if ( !v5 || *(_DWORD *)(v5 + 36) <= 1 )
    (*(void (__stdcall **)(int))(*(_DWORD *)this + 76))(v5);
  v6 = *(_BYTE *)(v5 + 8);
  ++*(_DWORD *)(v5 + 36);
  if ( v6 || !a3 )
    return v5;
  if ( (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 40))(v5) )
  {
    *(_BYTE *)(v5 + 8) = 1;
    return v5;
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
  return 0;
}

//----- (00416CF0) --------------------------------------------------------  // acclient.c:83484
DBObj *__thiscall DBOCache::GetIfUsing(DBOCache *this, IDClass<_tagDataID,32,0> id)
{
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *v2; // eax@1
  DBObj *result; // eax@4
  int v4; // ecx@7

  v2 = this->m_ObjTable.m_intrusiveTable.m_buckets[id.id % this->m_ObjTable.m_intrusiveTable.m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey.id != id.id )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 )
  {
    result = v2->m_data;
    if ( result && (v4 = result->m_numLinks, v4 > 1) )
      result->m_numLinks = v4 + 1;
    else
      result = 0;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00416D50) --------------------------------------------------------  // acclient.c:83516
unsigned int __thiscall DBOCache::Release(DBOCache *this, IDClass<_tagDataID,32,0> id)
{
  DBOCache *v2; // ebx@1
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *v3; // eax@1
  unsigned int result; // eax@4
  DBObj *v5; // esi@6
  unsigned int v6; // edi@6
  signed int v7; // eax@7
  int v8; // eax@8

  v2 = this;
  v3 = this->m_ObjTable.m_intrusiveTable.m_buckets[id.id % this->m_ObjTable.m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.id != id.id )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    v5 = v3->m_data;
    v6 = 0;
    if ( v5 )
    {
      v7 = v5->m_numLinks;
      if ( v7 > 1 )
      {
        v8 = v7 - 1;
        v5->m_numLinks = v8;
        if ( !v8 )
        {
          ((void (__thiscall *)(DBObj *, signed int))v5->vfptr[1].IUnknown_QueryInterface)(v5, 1);
          v8 = 0;
        }
        v6 = v8;
        if ( v5->m_numLinks <= 1 )
          v2->vfptr->FreeObject(v2, v5);
      }
    }
    result = v6;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00416DD0) --------------------------------------------------------  // acclient.c:83568
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::resize_internal(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1> *v3; // esi@1
  char result; // al@2
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *v5; // edi@3
  int v6; // ecx@4
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> **v7; // eax@5
  int v8; // eax@6
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> **v9; // ebx@7
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *v10; // ecx@7
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *v11; // eax@9
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *v12; // edx@10
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> **v17; // eax@23
  int v18; // eax@23

  v2 = _numBuckets;
  v3 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v6 = (int)&v3->m_buckets[v3->m_numBuckets];
        if ( v3->m_firstInterestingBucket == (HashTableData<IDClass<_tagDataID,32,0>,DBObj *> **)v6 )
        {
LABEL_7:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v3->m_firstInterestingBucket;
            if ( *v7 )
              break;
            v8 = (int)(v7 + 1);
            v3->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,DBObj *> **)v8;
            if ( v8 == v6 )
              goto LABEL_7;
          }
          v10 = *v3->m_firstInterestingBucket;
          v9 = v3->m_firstInterestingBucket;
        }
        v11 = *v9;
        if ( *v9 == v10 )
          goto LABEL_29;
        do
        {
          v12 = v11;
          v11 = v11->m_hashNext;
        }
        while ( v11 != v10 );
        if ( v12 )
          v12->m_hashNext = v11->m_hashNext;
        else
LABEL_29:
          *v9 = v11->m_hashNext;
        --v3->m_numElements;
        v10->m_hashNext = v5;
        v5 = v10;
      }
      while ( v3->m_numElements );
    }
    if ( (HashTableData<IDClass<_tagDataID,32,0>,DBObj *> **)v3->m_buckets != v3->m_aInplaceBuckets )
      operator delete[](v3->m_buckets);
    v3->m_buckets = 0;
    v3->m_firstInterestingBucket = 0;
    v3->m_numBuckets = 0;
    v3->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v3,
      v2);
    if ( v5 )
    {
      do
      {
        v13 = v5->m_hashNext;
        if ( (signed int)(2 * v3->m_numBuckets) < (signed int)(v3->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v3->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::resize_internal(
            v3,
            *v15);
        }
        v16 = v5->m_hashKey.id % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashTableData<IDClass<_tagDataID,32,0>,DBObj *> **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,DBObj *> **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (00416F10) --------------------------------------------------------  // acclient.c:83686
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::add(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1> *this, HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *data)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *v4; // eax@1
  unsigned int v5; // edx@6
  HashTableData<IDClass<_tagDataID,32,0>,DBObj *> **v6; // eax@6
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
      IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::grow(this);
    v5 = data->m_hashKey.id % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashTableData<IDClass<_tagDataID,32,0>,DBObj *> **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,DBObj *> **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (00416F90) --------------------------------------------------------  // acclient.c:83730
char __thiscall HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>::add(HashTable<IDClass<_tagDataID,32,0>,DBObj *,1> *this, IDClass<_tagDataID,32,0> *_key, DBObj *const *_data)
{
  HashTable<IDClass<_tagDataID,32,0>,DBObj *,1> *v3; // edi@1
  void *v4; // eax@1
  void *v5; // esi@2
  char result; // al@7

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *(_DWORD *)v4 = _key->id;
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = *_data;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::add(
         &v3->m_intrusiveTable,
         (HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *)v5) )
  {
    result = 1;
  }
  else
  {
    if ( v5 )
      operator delete(v5);
    result = 0;
  }
  return result;
}

//----- (00416FF0) --------------------------------------------------------  // acclient.c:83766
HashTable<unsigned long,float,0> *__thiscall HashTable<unsigned long,float,0>::vector_deleting_destructor(HashTable<unsigned long,float,0> *this, unsigned int a2)
{
  HashTable<unsigned long,float,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,float,0>Vtbl *)&HashTable<unsigned long,float,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>::vftable;
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
// 79533C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>::vftable[2])(void *, char);
// 795340: using guessed type int (__thiscall *HashTable<unsigned long,float,0>::vftable)(void *, char);

//----- (00417050) --------------------------------------------------------  // acclient.c:83792
void __thiscall DBOCache::~DBOCache(DBOCache *this)
{
  DBOCache *v1; // edi@1
  char *v2; // esi@1
  IDClass<_tagDataID,32,0> *v3; // eax@1
  int v4; // ecx@2
  int v5; // eax@3
  int v6; // eax@4
  void *v7; // eax@8
  void *v8; // eax@10
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@1

  v1 = this;
  v2 = (char *)&this->m_ObjTable.m_intrusiveTable;
  this->vfptr = (DBOCacheVtbl *)&CLOCache::vftable;
  v3 = (IDClass<_tagDataID,32,0> *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
                                     (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_ObjTable.m_intrusiveTable,
                                     &result)->m_currElement;
  while ( v3 )
  {
    DBOCache::RemoveObj(v1, (IDClass<_tagDataID,32,0>)v3->id);
    v4 = *((_DWORD *)v2 + 24) + 4 * *((_DWORD *)v2 + 26);
    if ( *((_DWORD *)v2 + 25) == v4 )
    {
LABEL_5:
      v3 = 0;
    }
    else
    {
      while ( 1 )
      {
        v5 = *((_DWORD *)v2 + 25);
        if ( *(_DWORD *)v5 )
          break;
        v6 = v5 + 4;
        *((_DWORD *)v2 + 25) = v6;
        if ( v6 == v4 )
          goto LABEL_5;
      }
      v3 = (IDClass<_tagDataID,32,0> *)**((_DWORD **)v2 + 25);
    }
  }
  v1->m_fidelityTable.vfptr = (HashTable<unsigned long,float,0>Vtbl *)&HashTable<unsigned long,float,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_fidelityTable.m_intrusiveTable);
  v7 = v1->m_fidelityTable.m_intrusiveTable.m_buckets;
  v1->m_fidelityTable.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>::vftable;
  if ( v7 != v1->m_fidelityTable.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v7);
  v1->m_fidelityTable.m_intrusiveTable.m_buckets = 0;
  v1->m_fidelityTable.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_fidelityTable.m_intrusiveTable.m_numBuckets = 0;
  v1->m_fidelityTable.m_intrusiveTable.m_numElements = 0;
  v1->m_ObjTable.vfptr = (HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *)&HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_ObjTable.m_intrusiveTable);
  v8 = v1->m_ObjTable.m_intrusiveTable.m_buckets;
  v1->m_ObjTable.m_intrusiveTable.vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::vftable;
  if ( v8 != v1->m_ObjTable.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v8);
  v1->m_ObjTable.m_intrusiveTable.m_buckets = 0;
  v1->m_ObjTable.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_ObjTable.m_intrusiveTable.m_numBuckets = 0;
  v1->m_ObjTable.m_intrusiveTable.m_numElements = 0;
}
// 795338: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::vftable[3])(void *, char);
// 79533C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>::vftable[2])(void *, char);
// 795340: using guessed type int (__thiscall *HashTable<unsigned long,float,0>::vftable)(void *, char);
// 795348: using guessed type int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>::vftable)(void *, char);
// 7C5CF8: using guessed type int (__thiscall *CLOCache::vftable)(void *, char);

//----- (00417130) --------------------------------------------------------  // acclient.c:83862
char __thiscall DBOCache::AddObj_Internal(DBOCache *this, DBObj *object_p)
{
  DBObj *v2; // edi@1
  DBOCache *v3; // esi@1
  char result; // al@4
  unsigned int _key; // [sp+0h] [bp-4h]@1

  _key = (unsigned int)this;
  v2 = object_p;
  v3 = this;
  if ( !object_p
    || object_p->m_DID.id == INVALID_DID_8.id
    || (_key = object_p->m_DID.id,
        HashSet<unsigned long>::contains((HashTable<unsigned long,unsigned long,0> *)&this->m_ObjTable, &_key)) )
  {
    result = 0;
  }
  else
  {
    v2->m_pMaintainer = v3;
    DBObj::AddToDataGraph(v2);
    _key = v2->m_DID.id;
    HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>::add(
      (HashTable<IDClass<_tagDataID,32,0>,DBObj *,1> *)&v3->m_ObjTable.vfptr,
      (IDClass<_tagDataID,32,0> *)&_key,
      &object_p);
    ++v3->m_nTotalCount;
    result = 1;
  }
  return result;
}

//----- (004171B0) --------------------------------------------------------  // acclient.c:83895
void __thiscall DBOCache::RemoveObj_Internal(DBOCache *this, DBObj *object_p)
{
  DBObj *v2; // edi@1
  DBOCache *v3; // esi@1
  HashSetData<IDClass<_tagDataID,32,0> > *v4; // eax@1

  v2 = object_p;
  v3 = this;
  object_p = (DBObj *)object_p->m_DID.id;
  v4 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->m_ObjTable.m_intrusiveTable,
         (IDClass<_tagDataID,32,0> *)&object_p);
  if ( v4 )
  {
    operator delete(v4);
    --v3->m_nTotalCount;
  }
  v2->m_pMaintainer = 0;
}

//----- (00417200) --------------------------------------------------------  // acclient.c:83916
AutoGrowHashTable<IDClass<_tagDataID,32,0>,DBObj *> *__thiscall HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>::scalar_deleting_destructor(AutoGrowHashTable<IDClass<_tagDataID,32,0>,DBObj *> *this, unsigned int a2)
{
  AutoGrowHashTable<IDClass<_tagDataID,32,0>,DBObj *> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *)&HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::vftable;
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
// 795338: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::vftable[3])(void *, char);
// 795348: using guessed type int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>::vftable)(void *, char);

//----- (00417260) --------------------------------------------------------  // acclient.c:83942
void __thiscall DBOCache::DBOCache(DBOCache *this, DBObj *(__cdecl *_allocator)(), unsigned int _dbtype)
{
  DBOCache *v3; // esi@1
  const unsigned int v4; // ST00_4@1
  FreelistDef *v5; // eax@1

  v3 = this;
  this->vfptr = (DBOCacheVtbl *)&CLOCache::vftable;
  this->m_ObjTable.vfptr = (HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *)&HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>::vftable;
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>(
    &this->m_ObjTable.m_intrusiveTable,
    0x80u);
  v3->m_ObjTable.vfptr = (HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *)&HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>::vftable;
  v3->m_dbtype = _dbtype;
  v3->m_fidelityTable.vfptr = (HashTable<unsigned long,float,0>Vtbl *)&HashTable<unsigned long,float,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>(
    &v3->m_fidelityTable.m_intrusiveTable,
    0x17u);
  v3->m_fCanKeepFreeObjs = 1;
  v3->m_fKeepFreeObjs = 1;
  v3->m_bFreelistActive = 1;
  v3->m_freelistDef.m_bRecycle = 0;
  v3->m_freelistDef.m_bShrink = 0;
  v3->m_freelistDef.m_nIdealSize = 16;
  v3->m_freelistDef.m_nMaxSize = 16;
  v4 = v3->m_dbtype;
  v3->m_pOldestFree = 0;
  v3->m_pYoungestFree = 0;
  v3->m_nFree = 0;
  v3->m_nTotalCount = 0;
  v3->m_pfnAllocator = _allocator;
  v5 = MasterDBMap::GetFreelistDef(v4);
  *(_DWORD *)&v3->m_freelistDef.m_bRecycle = *(_DWORD *)&v5->m_bRecycle;
  v3->m_freelistDef.m_nIdealSize = v5->m_nIdealSize;
  v3->m_freelistDef.m_nMaxSize = v5->m_nMaxSize;
}
// 795340: using guessed type int (__thiscall *HashTable<unsigned long,float,0>::vftable)(void *, char);
// 795348: using guessed type int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>::vftable)(void *, char);
// 7C5CF8: using guessed type int (__thiscall *CLOCache::vftable)(void *, char);

//----- (006C4990) --------------------------------------------------------  // acclient.c:732927
int _E73_13()
{
  return atexit(_E74_16);
}

//----- (006C49A0) --------------------------------------------------------  // acclient.c:732933
int _E76_8()
{
  return atexit(_E77_36);
}

//----- (006C49B0) --------------------------------------------------------  // acclient.c:732939
int _E79_8()
{
  return atexit(_E80_10);
}

//----- (006C49C0) --------------------------------------------------------  // acclient.c:732945
int _E1_8()
{
  return atexit(_E2_8);
}

