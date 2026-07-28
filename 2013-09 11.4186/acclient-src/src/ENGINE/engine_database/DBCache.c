/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DBCache
   Object     : ENGINE\engine_database\DBCache.obj
   Functions  : 132
   Addresses  : 00413720 - 00726E40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00413720) --------------------------------------------------------  // acclient.c:79381
void __thiscall DBCache::ResetCache(DBCache *this)
{
  DBCache *v1; // esi@1

  v1 = this;
  if ( DBCache::s_pCache )
    ((void (__stdcall *)(_DWORD))DBCache::s_pCache->vfptr->ReleaseContext)(unk_817684);
  unk_817684 = INVALID_ASYNCCONTEXT_1.m_id;
  ((void (*)(void))v1->vfptr->FlushPendingRequests)();
}

//----- (00413750) --------------------------------------------------------  // acclient.c:79393
int __cdecl DBCache::GetFromEnumStatic(int enum_id, int enum_group, unsigned int cache_index)
{
  int result; // eax@2

  if ( DBCache::s_pCache )
    result = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))DBCache::s_pCache->vfptr[1].QueryInterface)(
               enum_id,
               enum_group,
               cache_index);
  else
    result = 0;
  return result;
}

//----- (00413780) --------------------------------------------------------  // acclient.c:79408
int __cdecl DBCache::PreFetchStatic(QualifiedDataID *qdid)
{
  int result; // eax@2

  if ( DBCache::s_pCache )
    result = ((int (__stdcall *)(_DWORD))DBCache::s_pCache->vfptr[1].Release)(qdid);
  else
    result = 0;
  return result;
}

//----- (004137A0) --------------------------------------------------------  // acclient.c:79420
char __cdecl DBCache::GetCurrentRegion(unsigned int *region_num)
{
  char result; // al@2

  if ( DBCache::s_pCache )
  {
    *region_num = DBCache::s_pCache->m_CurrentRegion;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004137C0) --------------------------------------------------------  // acclient.c:79437
bool __cdecl DBCache::IsRunTime()
{
  bool result; // al@2

  if ( DBCache::s_pCache )
    result = DBCache::s_pCache->m_bRuntime;
  else
    result = 0;
  return result;
}

//----- (004137E0) --------------------------------------------------------  // acclient.c:79449
bool __cdecl DBCache::IsClient()
{
  bool result; // al@2

  if ( DBCache::s_pCache )
    result = DBCache::s_pCache->m_bIsClient;
  else
    result = 0;
  return result;
}

//----- (00413800) --------------------------------------------------------  // acclient.c:79461
bool __cdecl DBCache::IsServer()
{
  bool result; // al@2

  if ( DBCache::s_pCache )
    result = DBCache::s_pCache->m_bIsServer;
  else
    result = 0;
  return result;
}

//----- (00413820) --------------------------------------------------------  // acclient.c:79473
char __thiscall DBCache::SetRegion(DBCache *this, unsigned int rid)
{
  this->m_CurrentRegion = rid;
  return 1;
}

//----- (00413830) --------------------------------------------------------  // acclient.c:79480
bool __cdecl DBCache::SetLocalLanguage(unsigned int language_l, int engine_only)
{
  bool result; // al@2

  if ( DBCache::s_pCache )
    result = ((int (__stdcall *)(unsigned int, int))DBCache::s_pCache->vfptr[3].IUnknown_AddRef)(
               language_l,
               engine_only);
  else
    result = 0;
  return result;
}

//----- (00413850) --------------------------------------------------------  // acclient.c:79494
unsigned int __cdecl DBCache::GetLocalLanguage()
{
  unsigned int result; // eax@2

  if ( DBCache::s_pCache )
    result = DBCache::s_pCache->m_LocalLanguage;
  else
    result = 0;
  return result;
}

//----- (00413870) --------------------------------------------------------  // acclient.c:79506
void __thiscall TDynamicCircularArray<AsyncCache::CCallbackHandler *>::Clear(TDynamicCircularArray<AsyncCache::CCallbackHandler *> *this)
{
  this->count = 0;
  this->next = 0;
  this->first = 0;
}

//----- (00413880) --------------------------------------------------------  // acclient.c:79514
TDynamicCircularArray<AsyncCache::CCallbackHandler *> *__thiscall TDynamicCircularArray<AsyncCache::CCallbackHandler *>::scalar_deleting_destructor(TDynamicCircularArray<AsyncCache::CCallbackHandler *> *this, unsigned int a2)
{
  TDynamicCircularArray<AsyncCache::CCallbackHandler *> *v2; // esi@1
  AsyncCache::CCallbackHandler **v3; // eax@1

  v2 = this;
  v3 = this->A;
  this->vfptr = (TDynamicCircularArray<AsyncCache::CCallbackHandler *>Vtbl *)&TDynamicCircularArray<AsyncCache::CCallbackHandler *>::vftable;
  if ( v3 )
    operator delete[](v3);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 794F70: using guessed type int (__thiscall *TDynamicCircularArray<AsyncCache::CCallbackHandler *>::vftable)(void *, char);

//----- (004138B0) --------------------------------------------------------  // acclient.c:79531
IDClass<_tagDataID,32,0> *__thiscall DBCache::SetMasterMapDID(DBCache *this, IDClass<_tagDataID,32,0> *result, IDClass<_tagDataID,32,0> master_id)
{
  unsigned int v3; // edx@1
  IDClass<_tagDataID,32,0> *v4; // eax@1

  v3 = this->m_MasterMapID.id;
  this->m_MasterMapID.id = master_id.id;
  v4 = result;
  result->id = v3;
  return v4;
}

//----- (004138D0) --------------------------------------------------------  // acclient.c:79544
int __cdecl DBCache::Get(IDClass<_tagDataID,32,0> did, unsigned int dbtype)
{
  AsyncCacheVtbl *v2; // edi@1
  char *v3; // esi@1
  QualifiedDataID *v4; // eax@1
  QualifiedDataID v6; // [sp+8h] [bp-8h]@1

  v2 = DBCache::s_pCache->vfptr;
  v3 = (char *)&DBCache::s_pCache->vfptr;
  QualifiedDataID::QualifiedDataID(&v6, did, dbtype);
  return v2->BlockingGet(v3, 2, v4);
}

//----- (00413910) --------------------------------------------------------  // acclient.c:79558
IDClass<_tagDataID,32,0> *__cdecl DBCache::GetDIDFromEnumStatic(IDClass<_tagDataID,32,0> *result, int enum_id, int enum_group)
{
  IDClass<_tagDataID,32,0> *v3; // eax@2

  if ( DBCache::s_pCache )
  {
    ((void (__stdcall *)(IDClass<_tagDataID,32,0> *, int, int))DBCache::s_pCache->vfptr[1].AddRef)(
      result,
      enum_id,
      enum_group);
    v3 = result;
  }
  else
  {
    v3 = result;
    result->id = INVALID_DID_5.id;
  }
  return v3;
}

//----- (00413940) --------------------------------------------------------  // acclient.c:79579
IDClass<_tagDataID,32,0> *__thiscall DBCache::GetDIDFromEnum(DBCache *this, IDClass<_tagDataID,32,0> *result, int enum_id, int enum_group)
{
  unsigned int v4; // eax@1
  unsigned int v5; // ecx@1
  QualifiedDataID *v6; // eax@2
  int v7; // esi@2
  IDClass<_tagDataID,32,0> *v8; // eax@3
  QualifiedDataID *v9; // eax@4
  int v10; // edi@4
  IDClass<_tagDataID,32,0> result_id; // [sp+0h] [bp-18h]@2
  IDClass<_tagDataID,32,0> group_id; // [sp+4h] [bp-14h]@4
  QualifiedDataID v13; // [sp+8h] [bp-10h]@2
  QualifiedDataID v14; // [sp+10h] [bp-8h]@4

  v4 = this->m_MasterMapID.id;
  v5 = INVALID_DID_5.id;
  if ( v4 )
  {
    result_id.id = INVALID_DID_5.id;
    QualifiedDataID::QualifiedDataID(&v13, (IDClass<_tagDataID,32,0>)v4, 0x26u);
    v7 = DBObj::Get(v6);
    if ( !v7 )
    {
      v8 = result;
      result->id = INVALID_DID_5.id;
      return v8;
    }
    group_id.id = INVALID_DID_5.id;
    EnumIDMap::EnumToDID((EnumIDMap *)v7, enum_group, &group_id);
    QualifiedDataID::QualifiedDataID(&v14, group_id, 0x26u);
    v10 = DBObj::Get(v9);
    if ( v10 )
    {
      result_id.id = INVALID_DID_5.id;
      EnumIDMap::EnumToDID((EnumIDMap *)v10, enum_id, &result_id);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 20))(v10);
    }
    else
    {
      result_id.id = INVALID_DID_5.id;
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 20))(v7);
    v5 = result_id.id;
  }
  v8 = result;
  result->id = v5;
  return v8;
}

//----- (00413A10) --------------------------------------------------------  // acclient.c:79629
int __thiscall DBCache::GetFromEnum(DBCache *this, int enum_id, int enum_group, unsigned int dbtype)
{
  int result; // eax@2
  AsyncCacheVtbl *v5; // edi@3
  char *v6; // esi@3
  QualifiedDataID *v7; // eax@3
  QualifiedDataID v8; // [sp+Ch] [bp-8h]@3

  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->vfptr[1].AddRef)(&enum_group, enum_id, enum_group);
  if ( enum_group == INVALID_DID_5.id )
  {
    result = 0;
  }
  else
  {
    v5 = DBCache::s_pCache->vfptr;
    v6 = (char *)&DBCache::s_pCache->vfptr;
    QualifiedDataID::QualifiedDataID(&v8, (IDClass<_tagDataID,32,0>)enum_group, dbtype);
    result = v5->BlockingGet(v6, 2, v7);
  }
  return result;
}

//----- (00413A70) --------------------------------------------------------  // acclient.c:79653
char __thiscall DBCache::ReloadObject(DBCache *this, IDClass<_tagDataID,32,0> did, unsigned int dbtype)
{
  DBCache *v3; // edi@1
  char v4; // bl@1
  AsyncCacheVtbl *v5; // edx@1
  int v6; // edi@1
  int v7; // eax@1
  int v8; // ebp@1
  int v9; // eax@2
  int v10; // esi@2
  QualifiedDataID qdid; // [sp+10h] [bp-8h]@1
  char dbtypea; // [sp+20h] [bp+8h]@3

  v3 = this;
  v4 = 0;
  QualifiedDataID::QualifiedDataID(&qdid, did, dbtype);
  v5 = v3->vfptr;
  v6 = (int)&v3->vfptr;
  v7 = (int)v5->GetDBOCache((AsyncCache *)v6, &qdid);
  v8 = v7;
  if ( v7 )
  {
    v9 = (*(int (__thiscall **)(int, QualifiedDataID *, int))(*(_DWORD *)v6 + 132))(v6, &qdid, v7);
    v10 = v9;
    if ( v9 )
    {
      dbtypea = *(_BYTE *)(v9 + 8);
      if ( *(_BYTE *)(v9 + 8) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 44))(v9);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 60))(v10);
      v4 = (*(int (__thiscall **)(int, int, QualifiedDataID *, int))(*(_DWORD *)v6 + 124))(v6, v10, &qdid, v8);
      if ( !v4 )
        goto LABEL_15;
      v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 36))(v10);
      if ( !v4 )
        goto LABEL_15;
      if ( dbtypea )
        v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 40))(v10);
      if ( !v4 )
LABEL_15:
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v8 + 28))(v8, did.id);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 20))(v10);
    }
  }
  return v4;
}

//----- (00413B30) --------------------------------------------------------  // acclient.c:79701
void __cdecl DBCache::AddToDataGraph(DBObj *obj)
{
  const unsigned int v1; // eax@4

  if ( DBCache::s_pCache )
  {
    if ( obj->m_DID.id != INVALID_DID_5.id )
    {
      if ( DBCache::s_pCache->m_pDataGraph )
      {
        v1 = ((int (__thiscall *)(_DWORD))obj->vfptr[3].IUnknown_QueryInterface)(obj);
        if ( !MasterDBMap::IsCellType(v1) )
        {
          switch ( ((int (__thiscall *)(_DWORD))obj->vfptr[3].IUnknown_QueryInterface)(obj) )
          {
            default:
              ((void (__thiscall *)(_DWORD, _DWORD))obj->vfptr[2].AddRef)(obj, DBCache::s_pCache->m_pDataGraph);
              break;
            case 21:
            case 28:
            case 36:
            case 38:
            case 40:
            case 45:
              return;
          }
        }
      }
    }
  }
}

//----- (00413BC0) --------------------------------------------------------  // acclient.c:79734
IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *__thiscall IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::vector_deleting_destructor(IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *v2; // esi@1
  DBObjSaveInfo **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>Vtbl *)IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::vftable;
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
// 794F84: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::vftable[8])(void *, char);

//----- (00413C00) --------------------------------------------------------  // acclient.c:79755
IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1> *__thiscall IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::vector_deleting_destructor(IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1> *v2; // esi@1
  HashTableData<QualifiedDataID,CAsyncGetRequest *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>Vtbl *)IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::vftable;
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
// 794F88: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::vftable[7])(void *, char);

//----- (00413C40) --------------------------------------------------------  // acclient.c:79776
IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1> *__thiscall IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::scalar_deleting_destructor(IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1> *v2; // esi@1
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>Vtbl *)IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::vftable;
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
// 794F8C: using guessed type int (__thiscall *IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::vftable[6])(void *, char);

//----- (00413C80) --------------------------------------------------------  // acclient.c:79797
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0> *v2; // esi@1
  HashTableData<unsigned long,DBOCache *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::vftable;
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
// 794F90: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::vftable[5])(void *, char);

//----- (00413CC0) --------------------------------------------------------  // acclient.c:79818
IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> *__thiscall IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vector_deleting_destructor(IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> *v2; // esi@1
  HashSetData<QualifiedDataID> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>Vtbl *)IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vftable;
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
// 794F94: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vftable[4])(void *, char);

//----- (00413D00) --------------------------------------------------------  // acclient.c:79839
int __thiscall TDynamicCircularArray<AsyncCache::CCallbackHandler *>::Add(TDynamicCircularArray<AsyncCache::CCallbackHandler *> *this, AsyncCache::CCallbackHandler *const *T)
{
  TDynamicCircularArray<AsyncCache::CCallbackHandler *> *v2; // esi@1
  unsigned int v3; // eax@1
  void *v4; // edi@2
  unsigned int v5; // edx@3
  unsigned int v6; // ecx@3
  unsigned int v7; // ecx@6
  unsigned int v8; // eax@6
  unsigned int v9; // edx@6
  int v10; // eax@7

  v2 = this;
  v3 = this->max;
  if ( this->count == v3 )
  {
    v4 = operator new[](4 * (v3 + this->growsize));
    if ( v2->A )
    {
      v5 = v2->first;
      v6 = 0;
      if ( v2->count )
      {
        do
        {
          *((_DWORD *)v4 + v6) = v2->A[v5];
          v5 = (v5 + 1) % v2->max;
          ++v6;
        }
        while ( v6 < v2->count );
      }
      operator delete[](v2->A);
    }
    v7 = v2->max;
    v8 = v2->growsize;
    v9 = v2->count;
    v2->A = (AsyncCache::CCallbackHandler **)v4;
    v2->first = 0;
    v2->next = v9;
    v2->max = v8 + v7;
  }
  v2->A[v2->next] = *T;
  v2->next = (v2->next + 1) % v2->max;
  v10 = v2->count + 1;
  v2->count = v10;
  return v10 - 1;
}

//----- (00413DA0) --------------------------------------------------------  // acclient.c:79888
void __thiscall TDynamicCircularArray<AsyncCache::CCallbackHandler *>::Remove(TDynamicCircularArray<AsyncCache::CCallbackHandler *> *this, unsigned int Index)
{
  TDynamicCircularArray<AsyncCache::CCallbackHandler *> *v2; // esi@1
  unsigned int v3; // ecx@1
  unsigned int v4; // ecx@4
  unsigned int v5; // edi@4
  unsigned int v6; // edx@4
  int v7; // edi@6

  v2 = this;
  --this->count;
  v3 = this->max;
  if ( Index )
  {
    v2->next = (v3 + v2->next - 1) % v3;
    if ( Index != v2->count )
    {
      v4 = v2->first;
      v5 = v2->max;
      v6 = (v4 + Index) % v5;
      if ( v2->next < v4 && v6 > v4 )
      {
        v7 = v5 - 1;
        TDynamicCircularArray<AsyncCache::CCallbackHandler *>::Move(v2, v6, v6 + 1, v7 - v6);
        v2->A[v7] = *v2->A;
        v6 = 0;
      }
      TDynamicCircularArray<AsyncCache::CCallbackHandler *>::Move(v2, v6, v6 + 1, v2->next - v6);
    }
  }
  else
  {
    v2->first = (v2->first + 1) % v3;
  }
}

//----- (00413E30) --------------------------------------------------------  // acclient.c:79925
void __thiscall TDynamicCircularArray<AsyncCache::CCallbackHandler *>::Move(TDynamicCircularArray<AsyncCache::CCallbackHandler *> *this, unsigned int To, unsigned int From, unsigned int N)
{
  unsigned int v4; // esi@1
  unsigned int v5; // edi@4
  unsigned int v6; // edx@4
  unsigned int v7; // edx@8
  unsigned int v8; // eax@8
  unsigned int v9; // edi@8

  v4 = N;
  if ( N )
  {
    if ( To >= From )
    {
      if ( N )
      {
        v7 = To - 1 + N;
        v8 = From - 1 + N;
        v9 = N;
        do
        {
          this->A[v7] = this->A[v8];
          --v8;
          --v7;
          --v9;
        }
        while ( v9 );
      }
    }
    else if ( N )
    {
      v5 = To;
      v6 = From;
      do
      {
        this->A[v5] = this->A[v6];
        ++v6;
        ++v5;
        --v4;
      }
      while ( v4 );
    }
  }
}

//----- (00413EB0) --------------------------------------------------------  // acclient.c:79971
AsyncCache::CCallbackHandler *__thiscall TDynamicCircularArray<AsyncCache::CCallbackHandler *>::RemoveAndReturn(TDynamicCircularArray<AsyncCache::CCallbackHandler *> *this, unsigned int Index)
{
  AsyncCache::CCallbackHandler *v2; // edi@1

  v2 = this->A[(Index + this->first) % this->max];
  ((void (__stdcall *)(unsigned int))this->vfptr->Remove)(Index);
  return v2;
}

//----- (00413EE0) --------------------------------------------------------  // acclient.c:79981
bool __stdcall DBCache::Init(bool _bRequireProjectSettings, PStringBase<char> *i_strSearchPath)
{
  MasterDBMap *v3; // eax@2
  bool v4; // al@5
  PStringBase<char> *v5; // eax@6
  char *v6; // esi@6
  char *v7; // esi@9
  PStringBase<char> *v8; // eax@12
  PSRefBufferCharData<char> **v9; // ebx@12
  char *v10; // esi@13
  char *v11; // esi@17
  char *v12; // esi@20
  char *v13; // esi@23
  char *v14; // esi@26
  PStringBase<char> strPath; // [sp+18h] [bp-10h]@6
  PStringBase<char> rhs; // [sp+1Ch] [bp-Ch]@6
  PStringBase<char> result; // [sp+20h] [bp-8h]@6
  PStringBase<char> v18; // [sp+24h] [bp-4h]@12

  if ( MasterDBMap::sm_mmap
    || ((v3 = (MasterDBMap *)operator new(4u)) == 0 ? (v3 = 0) : (v3->vfptr = (MasterDBMapVtbl *)&MasterDBMap::vftable),
        (v4 = MasterDBMap::Init(v3)) != 0) )
  {
    PStringBase<char>::PStringBase<char>(&rhs, "/");
    v5 = ProjectSettings::CompleteProjectPath(&result, &DATA_GAME_PATH);
    PStringBase<char>::operator+(v5, &strPath, &rhs);
    v6 = &result.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v6 )
      (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
    v7 = &rhs.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    MasterDBMap::SetGameDataDir(&strPath);
    PStringBase<char>::PStringBase<char>(&rhs, "/");
    v8 = ProjectSettings::CompleteProjectPath(&v18, &DATA_ENGINE_PATH);
    v9 = (PSRefBufferCharData<char> **)PStringBase<char>::operator+(v8, &result, &rhs);
    if ( strPath.m_charbuffer != *v9 )
    {
      v10 = &strPath.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&strPath.m_charbuffer[-1]) && v10 )
        (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
      strPath.m_charbuffer = *v9;
      InterlockedIncrement((volatile LONG *)&strPath.m_charbuffer[-1]);
    }
    v11 = &result.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v11 )
      (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
    v12 = &v18.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v18.m_charbuffer[-1]) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    v13 = &rhs.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v13 )
      (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
    MasterDBMap::SetEngineDataDir(&strPath);
    v14 = &strPath.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strPath.m_charbuffer[-1]) )
    {
      if ( v14 )
        (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
    }
    v4 = 1;
  }
  return v4;
}
// 794F5C: using guessed type bool (__thiscall *MasterDBMap::vftable)(MasterDBMap *__hidden this);

//----- (00414090) --------------------------------------------------------  // acclient.c:80048
void __thiscall DBCache::UseTime(DBCache *this)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v1; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v2; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // edi@1
  DBOCache *v5; // ecx@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@1

  AsyncCache::UseTime((AsyncCache *)this);
  v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(&stru_81760C, &result);
  v2 = v1->m_currElement;
  v3 = v1->m_currHashTable;
  v4 = v1->m_currBucket;
  if ( v2 )
  {
    do
    {
LABEL_2:
      v5 = (DBOCache *)v2->m_data.vfptr;
      if ( v5 )
        DBOCache::UseTime(v5);
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    while ( 1 )
    {
      ++v4;
      if ( v4 == &v3->m_buckets[v3->m_numBuckets] )
        break;
      if ( *v4 )
      {
        v2 = *v4;
        if ( *v4 )
          goto LABEL_2;
        return;
      }
    }
  }
}

//----- (004140F0) --------------------------------------------------------  // acclient.c:80090
bool DBCache::UnloadCellData()
{
  bool v1; // bl@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // esi@1
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // edi@1
  HeritageGroup_CGVtbl *v5; // ebp@2
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *iter; // [sp+10h] [bp-18h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+1Ch] [bp-Ch]@1

  v1 = 1;
  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(&stru_81760C, &result);
  v3 = v2->m_currElement;
  v4 = v2->m_currBucket;
  iter = v2->m_currHashTable;
  if ( v3 )
  {
    do
    {
LABEL_2:
      v5 = v3->m_data.vfptr;
      if ( MasterDBMap::IsCellType((const unsigned int)v5[30].Serialize) )
      {
        (*((void (__thiscall **)(HeritageGroup_CGVtbl *))v5->Serialize + 10))(v5);
        v1 = v1 && !v5[67].Serialize;
      }
      v3 = v3->m_hashNext;
    }
    while ( v3 );
    while ( 1 )
    {
      ++v4;
      if ( v4 == &iter->m_buckets[iter->m_numBuckets] )
        break;
      if ( *v4 )
      {
        v3 = *v4;
        if ( *v4 )
          goto LABEL_2;
        return v1;
      }
    }
  }
  return v1;
}

//----- (00414180) --------------------------------------------------------  // acclient.c:80137
void DBCache::AskForLastWords()
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v1; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v2; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // edi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@1

  v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(&stru_81760C, &result);
  v2 = v1->m_currElement;
  v3 = v1->m_currHashTable;
  v4 = v1->m_currBucket;
  if ( v2 )
  {
    do
    {
LABEL_2:
      (*((void (**)(void))v2->m_data.vfptr->Serialize + 13))();
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    while ( 1 )
    {
      ++v4;
      if ( v4 == &v3->m_buckets[v3->m_numBuckets] )
        break;
      if ( *v4 )
      {
        v2 = *v4;
        if ( *v4 )
          goto LABEL_2;
        return;
      }
    }
  }
}

//----- (004141E0) --------------------------------------------------------  // acclient.c:80175
void __stdcall DBCache::FlushFreeObjects(unsigned int db_type)
{
  HashTableData<unsigned long,HeritageGroup_CG> *v2; // eax@2
  int v3; // eax@7
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // eax@9
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // esi@9
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v6; // ebx@9
  HashTableData<unsigned long,HeritageGroup_CG> **v7; // edi@9
  HeritageGroup_CGVtbl *v8; // ecx@10
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+0h] [bp-Ch]@9

  if ( db_type )
  {
    v2 = stru_81760C.m_buckets[db_type % stru_81760C.m_numBuckets];
    if ( v2 )
    {
      while ( v2->m_hashKey != db_type )
      {
        v2 = v2->m_hashNext;
        if ( !v2 )
          return;
      }
      if ( v2 )
      {
        v3 = (int)&v2->m_data;
        if ( v3 )
          (*(void (**)(void))(**(_DWORD **)v3 + 40))();
      }
    }
  }
  else
  {
    v4 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(&stru_81760C, &result);
    v5 = v4->m_currElement;
    v6 = v4->m_currHashTable;
    v7 = v4->m_currBucket;
    if ( v5 )
    {
      do
      {
LABEL_10:
        v8 = v5->m_data.vfptr;
        if ( v8 )
          (*((void (**)(void))v8->Serialize + 10))();
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
            goto LABEL_10;
          return;
        }
      }
    }
  }
}

//----- (00414290) --------------------------------------------------------  // acclient.c:80240
HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *__cdecl DBCache::GetDBOCache(unsigned int dbtype)
{
  HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *result; // eax@1
  char *v2; // eax@6

  result = (HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *)stru_81760C.m_buckets[dbtype % stru_81760C.m_numBuckets];
  if ( !result )
    goto LABEL_11;
  while ( result->__vecDelDtor != (void *(__thiscall *)(HashTable<IDClass<_tagDataID,32,0>,DBObj *,1> *, unsigned int))dbtype )
  {
    result = (HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *)result[1].__vecDelDtor;
    if ( !result )
      return result;
  }
  if ( result && (v2 = (char *)&result[2]) != 0 )
    result = *(HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl **)v2;
  else
LABEL_11:
    result = 0;
  return result;
}

//----- (004142D0) --------------------------------------------------------  // acclient.c:80263
char __thiscall IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::grow(IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::resize_internal(v2, *v3);
}

//----- (00414320) --------------------------------------------------------  // acclient.c:80281
char __stdcall DBCache::KeepFreeObjects(bool keep_f, unsigned int db_type)
{
  DBOCache *v3; // eax@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // eax@4
  HashTableData<unsigned long,HeritageGroup_CG> *v6; // esi@4
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // ebx@4
  HashTableData<unsigned long,HeritageGroup_CG> **v8; // edi@4
  DBOCache *v9; // ecx@5
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@4

  if ( db_type )
  {
    v3 = (DBOCache *)DBCache::GetDBOCache(db_type);
    if ( v3 )
    {
      DBOCache::KeepFreeObjects(v3, keep_f);
      return 1;
    }
  }
  else
  {
    v5 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(&stru_81760C, &result);
    v6 = v5->m_currElement;
    v7 = v5->m_currHashTable;
    v8 = v5->m_currBucket;
    if ( v6 )
    {
      do
      {
LABEL_5:
        v9 = (DBOCache *)v6->m_data.vfptr;
        if ( v9 )
          DBOCache::KeepFreeObjects(v9, keep_f);
        v6 = v6->m_hashNext;
      }
      while ( v6 );
      while ( 1 )
      {
        ++v8;
        if ( v8 == &v7->m_buckets[v7->m_numBuckets] )
          break;
        if ( *v8 )
        {
          v6 = *v8;
          if ( *v8 )
            goto LABEL_5;
          return 1;
        }
      }
    }
  }
  return 1;
}

//----- (004143B0) --------------------------------------------------------  // acclient.c:80336
HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *__stdcall DBCache::GetDBOCache(QualifiedDataID *qdida)
{
  HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *result; // eax@1
  char *v3; // eax@6

  result = (HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *)stru_81760C.m_buckets[qdida->Type
                                                                                    % stru_81760C.m_numBuckets];
  if ( !result )
    goto LABEL_11;
  while ( result->__vecDelDtor != (void *(__thiscall *)(HashTable<IDClass<_tagDataID,32,0>,DBObj *,1> *, unsigned int))qdida->Type )
  {
    result = (HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *)result[1].__vecDelDtor;
    if ( !result )
      return result;
  }
  if ( result && (v3 = (char *)&result[2]) != 0 )
    result = *(HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl **)v3;
  else
LABEL_11:
    result = 0;
  return result;
}

//----- (00414400) --------------------------------------------------------  // acclient.c:80360
void __thiscall IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>(IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>Vtbl *)IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (DBObjSaveInfo **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (DBObjSaveInfo **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 794F84: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::vftable[8])(void *, char);

//----- (00414490) --------------------------------------------------------  // acclient.c:80393
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,DBOCache *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,DBOCache *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 794F90: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::vftable[5])(void *, char);

//----- (00414520) --------------------------------------------------------  // acclient.c:80426
void __thiscall IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>(IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>Vtbl *)IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashSetData<QualifiedDataID> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashSetData<QualifiedDataID> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 794F94: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vftable[4])(void *, char);

//----- (004145B0) --------------------------------------------------------  // acclient.c:80459
char __thiscall IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::resize_internal(IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> *v3; // esi@1
  char result; // al@2
  HashSetData<QualifiedDataID> *v5; // edi@3
  int v6; // ecx@4
  HashSetData<QualifiedDataID> **v7; // eax@5
  int v8; // eax@6
  HashSetData<QualifiedDataID> **v9; // ebx@7
  HashSetData<QualifiedDataID> *v10; // ecx@7
  HashSetData<QualifiedDataID> *v11; // eax@9
  HashSetData<QualifiedDataID> *v12; // edx@10
  HashSetData<QualifiedDataID> *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  unsigned int v16; // edx@23
  HashSetData<QualifiedDataID> **v17; // eax@23
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
        if ( v3->m_firstInterestingBucket == (HashSetData<QualifiedDataID> **)v6 )
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
            v3->m_firstInterestingBucket = (HashSetData<QualifiedDataID> **)v8;
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
    if ( (HashSetData<QualifiedDataID> **)v3->m_buckets != v3->m_aInplaceBuckets )
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
          IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::resize_internal(v3, *v15);
        }
        v16 = (v5->m_hashKey.Type + v5->m_hashKey.ID.id) % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashSetData<QualifiedDataID> **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashSetData<QualifiedDataID> **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (004146F0) --------------------------------------------------------  // acclient.c:80575
void __thiscall QualifiedDataIDArray::QualifiedDataIDArray(QualifiedDataIDArray *this, int nRequestStartSize)
{
  QualifiedDataIDArray *v2; // esi@1

  v2 = this;
  IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>(
    (IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *)&this->vfptr,
    nRequestStartSize);
  v2->vfptr = (IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>Vtbl *)QualifiedDataIDArray::vftable;
  v2->m_CurBracketIterator.m_currHashTable = 0;
  v2->m_CurBracketIterator.m_currBucket = 0;
  v2->m_CurBracketIterator.m_currElement = 0;
  v2->m_LastBracketIndex = -1;
  v2->m_CurBracketIterator.m_currElement = 0;
  v2->m_CurBracketIterator.m_currBucket = 0;
  v2->m_CurBracketIterator.m_currHashTable = (IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *)v2;
}
// 794F98: using guessed type int (__thiscall *QualifiedDataIDArray::vftable[3])(void *, char);

//----- (00414730) --------------------------------------------------------  // acclient.c:80595
QualifiedDataIDArray *__thiscall QualifiedDataIDArray::vector_deleting_destructor(QualifiedDataIDArray *this, unsigned int a2)
{
  QualifiedDataIDArray *v2; // esi@1

  v2 = this;
  QualifiedDataIDArray::~QualifiedDataIDArray(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00414750) --------------------------------------------------------  // acclient.c:80607
char __thiscall IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::add(IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> *this, HashSetData<QualifiedDataID> *data)
{
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> *v2; // esi@1
  char v3; // al@2
  unsigned int v4; // edx@5
  HashSetData<QualifiedDataID> **v5; // eax@5
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
      IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::grow(v2);
    v4 = (data->m_hashKey.Type + data->m_hashKey.ID.id) % v2->m_numBuckets;
    v5 = v2->m_buckets;
    data->m_hashNext = v5[v4];
    v5[v4] = data;
    v6 = (int)&v5[v4];
    if ( (HashSetData<QualifiedDataID> **)v6 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashSetData<QualifiedDataID> **)v6;
    ++v2->m_numElements;
    v3 = 1;
  }
  return v3;
}

//----- (004147C0) --------------------------------------------------------  // acclient.c:80643
char __thiscall IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::resize_internal(IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1> *v2; // esi@1
  char result; // al@2
  HashTableData<QualifiedDataID,CAsyncGetRequest *> *v4; // edi@3
  int v5; // ecx@4
  HashTableData<QualifiedDataID,CAsyncGetRequest *> **v6; // eax@5
  int v7; // eax@6
  HashTableData<QualifiedDataID,CAsyncGetRequest *> **v8; // ebx@7
  HashTableData<QualifiedDataID,CAsyncGetRequest *> *v9; // ecx@7
  HashTableData<QualifiedDataID,CAsyncGetRequest *> *v10; // eax@9
  HashTableData<QualifiedDataID,CAsyncGetRequest *> *v11; // edx@10
  unsigned int v12; // eax@18
  HashTableData<QualifiedDataID,CAsyncGetRequest *> *v13; // ebx@18
  unsigned int v14; // eax@19
  unsigned int v15; // edx@20
  HashTableData<QualifiedDataID,CAsyncGetRequest *> **v16; // eax@20
  int v17; // eax@20

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
        if ( v2->m_firstInterestingBucket == (HashTableData<QualifiedDataID,CAsyncGetRequest *> **)v5 )
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
            v2->m_firstInterestingBucket = (HashTableData<QualifiedDataID,CAsyncGetRequest *> **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_26;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_26:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashTableData<QualifiedDataID,CAsyncGetRequest *> **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v2,
      _numBuckets);
    if ( v4 )
    {
      do
      {
        v12 = v2->m_numBuckets;
        v13 = v4->m_hashNext;
        if ( (signed int)(2 * v12) < (signed int)(v2->m_numElements + 1) )
        {
          v14 = IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::next_largest_num_buckets(v12);
          IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::resize_internal(
            v2,
            v14);
        }
        v15 = (v4->m_hashKey.Type + v4->m_hashKey.ID.id) % v2->m_numBuckets;
        v16 = v2->m_buckets;
        v4->m_hashNext = v16[v15];
        v16[v15] = v4;
        v17 = (int)&v16[v15];
        if ( (HashTableData<QualifiedDataID,CAsyncGetRequest *> **)v17 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (HashTableData<QualifiedDataID,CAsyncGetRequest *> **)v17;
        ++v2->m_numElements;
        v4 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (004148D0) --------------------------------------------------------  // acclient.c:80756
char __thiscall IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::resize_internal(IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1> *v2; // esi@1
  char result; // al@2
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *v4; // edi@3
  int v5; // ecx@4
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> **v6; // eax@5
  int v7; // eax@6
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> **v8; // ebx@7
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *v9; // ecx@7
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *v10; // eax@9
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *v11; // edx@10
  unsigned int v12; // eax@18
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *v13; // ebx@18
  unsigned int v14; // eax@19
  int v15; // edx@20
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> **v16; // eax@20
  int v17; // eax@20

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
        if ( v2->m_firstInterestingBucket == (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> **)v5 )
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
            v2->m_firstInterestingBucket = (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_26;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_26:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v2,
      _numBuckets);
    if ( v4 )
    {
      do
      {
        v12 = v2->m_numBuckets;
        v13 = v4->m_hashNext;
        if ( (signed int)(2 * v12) < (signed int)(v2->m_numElements + 1) )
        {
          v14 = IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::next_largest_num_buckets(v12);
          IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::resize_internal(
            v2,
            v14);
        }
        v15 = v4->m_hashKey.m_id % v2->m_numBuckets;
        v16 = v2->m_buckets;
        v4->m_hashNext = v16[v15];
        v16[v15] = v4;
        v17 = (int)&v16[v15];
        if ( (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> **)v17 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> **)v17;
        ++v2->m_numElements;
        v4 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (004149E0) --------------------------------------------------------  // acclient.c:80869
char __thiscall IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::grow(IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::resize_internal(
           v2,
           *v3);
}

//----- (00414A30) --------------------------------------------------------  // acclient.c:80889
char __thiscall IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::grow(IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::resize_internal(
           v2,
           *v3);
}

//----- (00414A80) --------------------------------------------------------  // acclient.c:80909
char __thiscall HashSet<QualifiedDataID>::add(HashSet<QualifiedDataID> *this, QualifiedDataID *_key)
{
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> *v2; // edi@1
  char v3; // al@2
  void *v4; // eax@3
  IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> result; // [sp+8h] [bp-Ch]@1

  v2 = &this->m_intrusiveTable;
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::find_internal(
    (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *)&this->m_intrusiveTable,
    &result,
    _key);
  if ( result.m_currElement )
  {
    v3 = 0;
  }
  else
  {
    v4 = operator new(0xCu);
    if ( v4 )
    {
      *(_QWORD *)v4 = *_key;
      *((_DWORD *)v4 + 2) = 0;
      IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::add(v2, (HashSetData<QualifiedDataID> *)v4);
      v3 = 1;
    }
    else
    {
      IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::add(v2, 0);
      v3 = 1;
    }
  }
  return v3;
}

//----- (00414AF0) --------------------------------------------------------  // acclient.c:80945
HashSet<QualifiedDataID> *__thiscall HashSet<QualifiedDataID>::scalar_deleting_destructor(HashSet<QualifiedDataID> *this, unsigned int a2)
{
  HashSet<QualifiedDataID> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashSet<QualifiedDataID>Vtbl *)&HashSet<QualifiedDataID>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vftable;
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
// 794F94: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vftable[4])(void *, char);
// 794FA0: using guessed type int (__thiscall *HashSet<QualifiedDataID>::vftable)(void *, char);

//----- (00414B50) --------------------------------------------------------  // acclient.c:80971
void __thiscall DBCachePrefetchCallback::OnContextFinished(DBCachePrefetchCallback *this, AsyncContext hContext, AsyncResult Result, unsigned int dwUser1)
{
  DBCachePrefetchCallback *v4; // esi@1

  v4 = this;
  if ( DBCache::s_pCache )
  {
    ((void (__stdcall *)(_DWORD))DBCache::s_pCache->vfptr->ReleaseContext)(this->m_PreFetchContext.m_id);
    v4->m_PreFetchContext.m_id = INVALID_ASYNCCONTEXT_1.m_id;
  }
  else
  {
    this->m_PreFetchContext.m_id = INVALID_ASYNCCONTEXT_1.m_id;
  }
}

//----- (00414B90) --------------------------------------------------------  // acclient.c:80988
void __thiscall DBCachePrefetchCallback::PreFetch(DBCachePrefetchCallback *this, QualifiedDataID *qdid)
{
  DBCachePrefetchCallback *v2; // esi@1
  DBCache *v3; // ebx@2
  char v4; // [sp+8h] [bp-90h]@4
  IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> result; // [sp+Ch] [bp-8Ch]@1
  QualifiedDataIDArray idarray; // [sp+18h] [bp-80h]@5

  v2 = this;
  if ( !IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::find_internal(
          (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *)&this->m_hashRequestedIDs.m_intrusiveTable,
          &result,
          qdid)->m_currElement )
  {
    v3 = DBCache::s_pCache;
    if ( DBCache::s_pCache )
    {
      if ( INVALID_ASYNCCONTEXT_1.m_id == v2->m_PreFetchContext.m_id )
      {
        v2->m_PreFetchContext.m_id = *(_DWORD *)DBCache::s_pCache->vfptr->AsyncGet(
                                                  (AsyncCache *)&DBCache::s_pCache->vfptr,
                                                  (AsyncContext *)&v4,
                                                  3u,
                                                  qdid,
                                                  (AsyncCacheCallback *)v2,
                                                  0);
      }
      else
      {
        QualifiedDataIDArray::QualifiedDataIDArray(&idarray, 32);
        QualifiedDataIDArray::AddQDID(&idarray, qdid, 0);
        v3->vfptr->AddToAsyncGet(
          (AsyncCache *)&v3->vfptr,
          v2->m_PreFetchContext.m_id,
          (QualifiedDataIDArray *)3,
          &idarray);
        QualifiedDataIDArray::~QualifiedDataIDArray(&idarray);
      }
      HashSet<QualifiedDataID>::add(&v2->m_hashRequestedIDs, qdid);
    }
  }
}

//----- (00414C30) --------------------------------------------------------  // acclient.c:81032
void __thiscall DBCachePrefetchCallback::OnTopLevelRequestFinished(DBCachePrefetchCallback *this, AsyncContext hContext, QualifiedDataID qdid, AsyncResult Result, unsigned int dwUser1, int nTimesFinished, void *hInternal)
{
  if ( nTimesFinished == 1 )
    HashSet<QualifiedDataID>::erase(&this->m_hashRequestedIDs, &qdid);
}

//----- (00414C50) --------------------------------------------------------  // acclient.c:81039
char __thiscall HashSet<QualifiedDataID>::erase(HashSet<QualifiedDataID> *this, QualifiedDataID *_key)
{
  HashSetData<QualifiedDataID> *v2; // eax@1
  char result; // al@2

  v2 = IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::remove(&this->m_intrusiveTable, _key);
  if ( v2 )
  {
    operator delete(v2);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00414C80) --------------------------------------------------------  // acclient.c:81058
signed int __thiscall DBCache::PreFetch(DBCache *this, QualifiedDataID *qdid)
{
  char *v2; // esi@1
  DBOCache *v3; // eax@1
  int v4; // eax@2
  signed int result; // eax@3

  v2 = (char *)&this->vfptr;
  v3 = this->vfptr->GetDBOCache((AsyncCache *)&this->vfptr, qdid);
  if ( v3
    && (v4 = (*(int (__thiscall **)(char *, QualifiedDataID *, DBOCache *))(*(_DWORD *)v2 + 132))(v2, qdid, v3)) != 0 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
    result = 2;
  }
  else if ( (unsigned __int8)(*(int (__thiscall **)(char *, QualifiedDataID *))(*(_DWORD *)v2 + 60))(v2, qdid) )
  {
    result = 1;
  }
  else
  {
    DBCachePrefetchCallback::PreFetch(&s_PrefetchCallback, qdid);
    result = -1;
  }
  return result;
}

//----- (00414CE0) --------------------------------------------------------  // acclient.c:81086
void __thiscall DBCache::DestroyObjectCaches(DBCache *this)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v1; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v2; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // edi@1
  HeritageGroup_CGVtbl *v5; // ecx@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@1

  this->vfptr[2].IUnknown_Release((Interface *)1);
  v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(&stru_81760C, &result);
  v2 = v1->m_currElement;
  v3 = v1->m_currHashTable;
  v4 = v1->m_currBucket;
  if ( v2 )
  {
    do
    {
LABEL_2:
      v5 = v2->m_data.vfptr;
      if ( v5 )
        (*(void (__stdcall **)(_DWORD))v5->Serialize)(1);
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    while ( 1 )
    {
      ++v4;
      if ( v4 == &v3->m_buckets[v3->m_numBuckets] )
        break;
      if ( *v4 )
      {
        v2 = *v4;
        if ( *v4 )
          goto LABEL_2;
        break;
      }
    }
  }
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C);
}

//----- (00414D50) --------------------------------------------------------  // acclient.c:81129
HashTable<unsigned long,DBOCache *,0> *__thiscall HashTable<unsigned long,DBOCache *,0>::vector_deleting_destructor(HashTable<unsigned long,DBOCache *,0> *this, unsigned int a2)
{
  HashTable<unsigned long,DBOCache *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,DBOCache *,0>Vtbl *)HashTable<unsigned long,DBOCache *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::vftable;
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
// 794F90: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::vftable[5])(void *, char);
// 794F9C: using guessed type int (__thiscall *HashTable<unsigned long,DBOCache *,0>::vftable[2])(void *, char);

//----- (00414DB0) --------------------------------------------------------  // acclient.c:81155
HashTable<QualifiedDataID,CAsyncGetRequest *,1> *__thiscall AutoGrowHashTable<QualifiedDataID,CAsyncGetRequest *>::scalar_deleting_destructor(HashTable<QualifiedDataID,CAsyncGetRequest *,1> *this, unsigned int a2)
{
  HashTable<QualifiedDataID,CAsyncGetRequest *,1> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<QualifiedDataID,CAsyncGetRequest *,1>Vtbl *)&HashTable<QualifiedDataID,CAsyncGetRequest *,1>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::vftable;
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
// 794F88: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::vftable[7])(void *, char);
// 7953A8: using guessed type int (__thiscall *HashTable<QualifiedDataID,CAsyncGetRequest *,1>::vftable)(void *, char);

//----- (00414E10) --------------------------------------------------------  // acclient.c:81181
HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1> *__thiscall AutoGrowHashTable<AsyncContext,AsyncCache::CCallbackHandler *>::scalar_deleting_destructor(HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1> *this, unsigned int a2)
{
  HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1>Vtbl *)HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::vftable;
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
// 794F8C: using guessed type int (__thiscall *IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::vftable[6])(void *, char);
// 7953A4: using guessed type int (__thiscall *HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1>::vftable[2])(void *, char);

//----- (00414E70) --------------------------------------------------------  // acclient.c:81207
void __thiscall AsyncCache::~AsyncCache(AsyncCache *this)
{
  AsyncCache *v1; // edi@1
  char *v2; // esi@1
  void *v3; // eax@1
  void *v4; // eax@3
  void *v5; // edi@5

  v1 = this;
  v2 = (char *)&this->m_BusyCallbacks.m_intrusiveTable;
  this->m_BusyCallbacks.vfptr = (HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1>Vtbl *)HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_BusyCallbacks.m_intrusiveTable);
  v3 = (void *)*((_DWORD *)v2 + 24);
  *(_DWORD *)v2 = IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::vftable;
  if ( v3 != v2 + 4 )
    operator delete[](v3);
  *((_DWORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 25) = 0;
  *((_DWORD *)v2 + 26) = 0;
  *((_DWORD *)v2 + 27) = 0;
  v1->m_PendingGets.vfptr = (HashTable<QualifiedDataID,CAsyncGetRequest *,1>Vtbl *)&HashTable<QualifiedDataID,CAsyncGetRequest *,1>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&v1->m_PendingGets.m_intrusiveTable);
  v4 = v1->m_PendingGets.m_intrusiveTable.m_buckets;
  v1->m_PendingGets.m_intrusiveTable.vfptr = (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>Vtbl *)IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::vftable;
  if ( v4 != v1->m_PendingGets.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v4);
  v1->m_PendingGets.m_intrusiveTable.m_buckets = 0;
  v1->m_PendingGets.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_PendingGets.m_intrusiveTable.m_numBuckets = 0;
  v1->m_PendingGets.m_intrusiveTable.m_numElements = 0;
  v1->m_PendingCallbacks.vfptr = (TDynamicCircularArray<AsyncCache::CCallbackHandler *>Vtbl *)&TDynamicCircularArray<AsyncCache::CCallbackHandler *>::vftable;
  v5 = v1->m_PendingCallbacks.A;
  if ( v5 )
    operator delete[](v5);
}
// 794F70: using guessed type int (__thiscall *TDynamicCircularArray<AsyncCache::CCallbackHandler *>::vftable)(void *, char);
// 794F88: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::vftable[7])(void *, char);
// 794F8C: using guessed type int (__thiscall *IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::vftable[6])(void *, char);
// 7953A4: using guessed type int (__thiscall *HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1>::vftable[2])(void *, char);
// 7953A8: using guessed type int (__thiscall *HashTable<QualifiedDataID,CAsyncGetRequest *,1>::vftable)(void *, char);

//----- (00414F10) --------------------------------------------------------  // acclient.c:81249
void __thiscall DBCache::~DBCache(DBCache *this)
{
  DBCache *v1; // esi@1
  AsyncCache *v2; // edi@1

  v1 = this;
  v2 = (AsyncCache *)&this->vfptr;
  this->vfptr = (InterfaceVtbl *)&DBCache::vftable;
  this->vfptr = (AsyncCacheVtbl *)&DBCache::vftable;
  MasterDBMap::Cleanup();
  if ( DBCache::s_pCache )
    ((void (__stdcall *)(_DWORD))DBCache::s_pCache->vfptr->ReleaseContext)(unk_817684);
  unk_817684 = INVALID_ASYNCCONTEXT_1.m_id;
  DBCache::s_pCache = 0;
  DBCache::s_bCacheInitialized = 0;
  v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  AsyncCache::~AsyncCache(v2);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 794FB0: using guessed type struct DBObj *(__thiscall *DBCache::vftable)(AsyncCache *this, unsigned __int32 type, const struct QualifiedDataID *);
// 795058: using guessed type __int32 (__stdcall *DBCache::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 836BA8: using guessed type bool DBCache::s_bCacheInitialized;

//----- (00414F70) --------------------------------------------------------  // acclient.c:81273
TResult *__thiscall DBCache::QueryInterface(DBCache *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppObject)
{
  TResult *v4; // eax@6

  if ( i_rcInterface->m_data1 == -559038737
    && *(_DWORD *)&i_rcInterface->m_data2 == *(_DWORD *)&Interface_InterfaceType_6.m_data2
    && *(_DWORD *)&i_rcInterface->m_data4[0] == *(_DWORD *)&Interface_InterfaceType_6.m_data4[0]
    && *(_DWORD *)&i_rcInterface->m_data4[4] == *(_DWORD *)&Interface_InterfaceType_6.m_data4[4]
    && this )
  {
    *o_ppObject = this;
    ((void (*)(void))this->vfptr->AddRef)();
    v4 = result;
    result->m_val = 0;
  }
  else
  {
    v4 = result;
    result->m_val = -2147467262;
  }
  return v4;
}

//----- (00414FD0) --------------------------------------------------------  // acclient.c:81297
LONG __thiscall DBCache::AddRef(DBCache *this)
{
  return InterlockedIncrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef);
}

//----- (00414FE0) --------------------------------------------------------  // acclient.c:81303
unsigned int __thiscall DBCache::Release(DBCache *this)
{
  DBCache *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
    ((void (__thiscall *)(DBCache *, signed int))v1->vfptr[1].IUnknown_QueryInterface)(v1, 1);
  return v2;
}

//----- (00415010) --------------------------------------------------------  // acclient.c:81316
bool __stdcall DBCache::SetShutdown(bool shut_f)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edi@1
  DBOCache *v6; // ecx@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@1
  bool shut_fa; // [sp+20h] [bp+4h]@1

  shut_fa = shut_f == 0;
  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(&stru_81760C, &result);
  v3 = v2->m_currElement;
  v4 = v2->m_currHashTable;
  v5 = v2->m_currBucket;
  if ( v3 )
  {
    do
    {
LABEL_2:
      v6 = (DBOCache *)v3->m_data.vfptr;
      if ( v6 )
        DBOCache::KeepFreeObjects(v6, shut_fa);
      v3 = v3->m_hashNext;
    }
    while ( v3 );
    while ( 1 )
    {
      ++v5;
      if ( v5 == &v4->m_buckets[v4->m_numBuckets] )
        break;
      if ( *v5 )
      {
        v3 = *v5;
        if ( *v5 )
          goto LABEL_2;
        return 0;
      }
    }
  }
  return 0;
}

//----- (00415080) --------------------------------------------------------  // acclient.c:81360
void __thiscall DBCache::DBCache(DBCache *this)
{
  DBCache *v1; // esi@1
  char *v2; // edi@1

  v1 = this;
  v2 = (char *)&this->vfptr;
  AsyncCache::AsyncCache((AsyncCache *)&this->vfptr);
  v1->vfptr = (InterfaceVtbl *)&DBCache::vftable;
  *(_DWORD *)v2 = &DBCache::vftable;
  v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  v1->m_cTurbineRefCount.m_cRef = 1;
  v1->m_MasterMapID.id = INVALID_DID_5.id;
  v1->m_CurrentRegion = 0;
  v1->m_LocalLanguage = 0;
  v1->m_bRuntime = 1;
  v1->m_bIsClient = 0;
  v1->m_bIsServer = 0;
  v1->m_pDataGraph = 0;
  if ( DBCache::s_pCache )
    ((void (__stdcall *)(_DWORD))DBCache::s_pCache->vfptr[1].IUnknown_QueryInterface)(1);
  DBCache::s_pCache = v1;
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 794FB0: using guessed type struct DBObj *(__thiscall *DBCache::vftable)(AsyncCache *this, unsigned __int32 type, const struct QualifiedDataID *);
// 795058: using guessed type __int32 (__stdcall *DBCache::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00415100) --------------------------------------------------------  // acclient.c:81388
DBCache *__thiscall DBCache::vector_deleting_destructor(DBCache *this, unsigned int a2)
{
  DBCache *v2; // esi@1

  v2 = this;
  DBCache::~DBCache(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00417490) --------------------------------------------------------  // acclient.c:84121
int __stdcall AsyncCache::GetIfInMemory(DBOCache *pObjCache, DBOCache *pObjCachea)
{
  int result; // eax@2

  if ( pObjCachea )
    result = (*(int (__stdcall **)(HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *, _DWORD))&pObjCachea->vfptr->gap4[0])(
               pObjCache->m_ObjTable.vfptr,
               0);
  else
    result = 0;
  return result;
}

//----- (00418270) --------------------------------------------------------  // acclient.c:85085
unsigned int __cdecl IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::next_largest_num_buckets(unsigned int _n)
{
  unsigned int *v1; // esi@1
  const unsigned int *v2; // eax@1
  bool v3; // zf@1
  const unsigned int result; // eax@4

  v1 = g_bucketSizesEnd;
  v2 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_n);
  v3 = v2 == v1;
  if ( v2 == v1 )
  {
    --v2;
    v3 = v2 == v1;
  }
  if ( v3 )
    result = *v2;
  else
    result = v2[1];
  return result;
}

//----- (00419050) --------------------------------------------------------  // acclient.c:86161
HashSetData<QualifiedDataID> *__thiscall IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::remove(IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> *this, QualifiedDataID *key)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *v2; // esi@1
  HashSetData<QualifiedDataID> *v3; // edi@1
  _BYTE v4[12]; // ST00_12@2
  HashSetData<QualifiedDataID> *result; // eax@2
  IntrusiveHashIterator<QualifiedDataID,HashSetData<QualifiedDataID> *,1> iter; // [sp+Ch] [bp-Ch]@1

  v2 = (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)this;
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::find_internal(
    (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *)this,
    (IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *)&iter,
    key);
  v3 = iter.m_currElement;
  if ( iter.m_currElement )
  {
    *(_QWORD *)&v4[4] = *(_QWORD *)&iter.m_currBucket;
    *(_DWORD *)v4 = iter.m_currHashTable;
    IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::remove(
      v2,
      *(IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)v4);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006C44B0) --------------------------------------------------------  // acclient.c:732633
int _E73_10()
{
  return atexit(_E74_13);
}

//----- (006C44C0) --------------------------------------------------------  // acclient.c:732639
int _E76_5()
{
  return atexit(_E77_33);
}

//----- (006C44D0) --------------------------------------------------------  // acclient.c:732645
int _E79_5()
{
  return atexit(_E80_7);
}

//----- (006C44E0) --------------------------------------------------------  // acclient.c:732651
int _E82_1()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"ProjectSetting");
  PStringBase<unsigned short>::allocate_ref_buffer(&PROJECTSETTING, v0);
  _wcscpy(PROJECTSETTING.m_charbuffer->m_data, L"ProjectSetting");
  return atexit(_E83_1);
}

//----- (006C4520) --------------------------------------------------------  // acclient.c:732662
int _E85()
{
  PStringBase<char>::PStringBase<char>(&NAME, "name");
  return atexit(_E86_1);
}

//----- (006C4540) --------------------------------------------------------  // acclient.c:732669
int _E88()
{
  PStringBase<char>::PStringBase<char>(&VALUE, "value");
  return atexit(_E89_12);
}

//----- (006C4560) --------------------------------------------------------  // acclient.c:732676
int _E91()
{
  PStringBase<char>::PStringBase<char>(&BRANCH, "branch");
  return atexit(_E92_9);
}

//----- (006C4580) --------------------------------------------------------  // acclient.c:732683
int _E94()
{
  PStringBase<char>::PStringBase<char>(&BRANCHBASEDIR, "branchbasedir");
  return atexit(sub_726990);
}

//----- (006C45A0) --------------------------------------------------------  // acclient.c:732690
int _E97()
{
  PStringBase<char>::PStringBase<char>(&PROJECTNAME, "projectname");
  return atexit(_E98_22);
}

//----- (006C45C0) --------------------------------------------------------  // acclient.c:732697
int _E100_2()
{
  PStringBase<char>::PStringBase<char>(&LONGNAME, "longname");
  return atexit(_E101_52);
}

//----- (006C45E0) --------------------------------------------------------  // acclient.c:732704
int _E103()
{
  PStringBase<char>::PStringBase<char>(&ENUMDB, "enumdb");
  return atexit(_E104_22);
}

//----- (006C4600) --------------------------------------------------------  // acclient.c:732711
int _E106_1()
{
  PStringBase<char>::PStringBase<char>(&DIDNAME, "didname");
  return atexit(_E107_54);
}

//----- (006C4620) --------------------------------------------------------  // acclient.c:732718
int _E109()
{
  PStringBase<char>::PStringBase<char>(&RCS, "rcs");
  return atexit(sub_726A80);
}

//----- (006C4640) --------------------------------------------------------  // acclient.c:732725
int _E112_1()
{
  PStringBase<char>::PStringBase<char>(&PREPROC_KEYS_BASE_PATH, "SOFTWARE\\Turbine\\Preproc");
  return atexit(_E113_35);
}

//----- (006C4660) --------------------------------------------------------  // acclient.c:732732
int _E115()
{
  PStringBase<char>::PStringBase<char>(&CURRENT_PROJECT, "CURRENT_PROJECT");
  return atexit(_E116_27);
}

//----- (006C4680) --------------------------------------------------------  // acclient.c:732739
int _E118_1()
{
  PStringBase<char>::PStringBase<char>(&DATA_GAME_PATH, "data/game");
  return atexit(_E119_53);
}

//----- (006C46A0) --------------------------------------------------------  // acclient.c:732746
int _E121_1()
{
  PStringBase<char>::PStringBase<char>(&DATA_ENGINE_PATH, "data/engine");
  return atexit(_E122_40);
}

//----- (006C46C0) --------------------------------------------------------  // acclient.c:732753
int _E124_1()
{
  PStringBase<char>::PStringBase<char>(&SOURCE_GAME_PATH, "src/game");
  return atexit(_E125_16);
}

//----- (006C46E0) --------------------------------------------------------  // acclient.c:732760
int _E127_1()
{
  PStringBase<char>::PStringBase<char>(&SOURCE_ENGINE_PATH, "src/engine");
  return atexit(_E128_17);
}

//----- (006C4700) --------------------------------------------------------  // acclient.c:732767
int _E130_1()
{
  PStringBase<char>::PStringBase<char>(&TOOLS_BIN_PATH, "tools/bin");
  return atexit(_E131_13);
}

//----- (006C4720) --------------------------------------------------------  // acclient.c:732774
int _E133_1()
{
  PStringBase<char>::PStringBase<char>(&CONFIG_TOOLS_PATH, "config/tools");
  return atexit(_E134_12);
}

//----- (006C4740) --------------------------------------------------------  // acclient.c:732781
int _E136_0()
{
  PStringBase<char>::PStringBase<char>(&OUTPUT_INI_PATH, "output/ini");
  return atexit(_E137_13);
}

//----- (006C4760) --------------------------------------------------------  // acclient.c:732788
int _E139_0()
{
  PStringBase<char>::PStringBase<char>(&DATA_PATH, "data");
  return atexit(_E140_8);
}

//----- (006C4780) --------------------------------------------------------  // acclient.c:732795
int _E142_0()
{
  PStringBase<char>::PStringBase<char>(&DOC_PATH, "doc");
  return atexit(_E143_10);
}

//----- (006C47A0) --------------------------------------------------------  // acclient.c:732802
int _E145_0()
{
  PStringBase<char>::PStringBase<char>(&EXPORT_PATH, "export");
  return atexit(_E146_9);
}

//----- (006C47C0) --------------------------------------------------------  // acclient.c:732809
int _E148_0()
{
  PStringBase<char>::PStringBase<char>(&SDK_PATH, "sdk");
  return atexit(_E149_9);
}

//----- (006C47E0) --------------------------------------------------------  // acclient.c:732816
int _E151_0()
{
  PStringBase<char>::PStringBase<char>(&SOURCE_PATH, "src");
  return atexit(_E152_8);
}

//----- (006C4800) --------------------------------------------------------  // acclient.c:732823
int _E154_1()
{
  PStringBase<char>::PStringBase<char>(&TOOLS_PATH, "tools");
  return atexit(_E155_6);
}

//----- (006C4820) --------------------------------------------------------  // acclient.c:732830
int _E157_0()
{
  PStringBase<char>::PStringBase<char>(&PORTAL_PATH, "portal");
  return atexit(_E158_9);
}

//----- (006C4840) --------------------------------------------------------  // acclient.c:732837
int _E160_1()
{
  PStringBase<char>::PStringBase<char>(&AC_PATH, "ac");
  return atexit(_E161_6);
}

//----- (006C4860) --------------------------------------------------------  // acclient.c:732844
int _E163_0()
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0> *)&stru_81760C,
    0x80u);
  return atexit(_E164_10);
}

//----- (006C4880) --------------------------------------------------------  // acclient.c:732853
int _E166_1()
{
  unk_817684 = INVALID_ASYNCCONTEXT_1.m_id;
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>(
    &stru_81768C,
    0x17u);
  return atexit(_E167_6);
}

//----- (006C48B0) --------------------------------------------------------  // acclient.c:732863
int _E1_5()
{
  return atexit(_E2_5);
}

//----- (007268D0) --------------------------------------------------------  // acclient.c:824414
void __cdecl _E83_1()
{
  char *v0; // esi@1

  v0 = (char *)&PROJECTSETTING.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&PROJECTSETTING.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726900) --------------------------------------------------------  // acclient.c:824427
void __cdecl _E86_1()
{
  char *v0; // esi@1

  v0 = &NAME.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NAME.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726930) --------------------------------------------------------  // acclient.c:824440
void __cdecl _E89_12()
{
  char *v0; // esi@1

  v0 = &VALUE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VALUE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726960) --------------------------------------------------------  // acclient.c:824453
void __cdecl _E92_9()
{
  char *v0; // esi@1

  v0 = &BRANCH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BRANCH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726990) --------------------------------------------------------  // acclient.c:824466
void __cdecl sub_726990()
{
  char *v0; // esi@1

  v0 = &BRANCHBASEDIR.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BRANCHBASEDIR.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007269C0) --------------------------------------------------------  // acclient.c:824479
void __cdecl _E98_22()
{
  char *v0; // esi@1

  v0 = &PROJECTNAME.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PROJECTNAME.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007269F0) --------------------------------------------------------  // acclient.c:824492
void __cdecl _E101_52()
{
  char *v0; // esi@1

  v0 = &LONGNAME.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LONGNAME.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726A20) --------------------------------------------------------  // acclient.c:824505
void __cdecl _E104_22()
{
  char *v0; // esi@1

  v0 = &ENUMDB.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ENUMDB.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726A50) --------------------------------------------------------  // acclient.c:824518
void __cdecl _E107_54()
{
  char *v0; // esi@1

  v0 = &DIDNAME.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DIDNAME.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726A80) --------------------------------------------------------  // acclient.c:824531
void __cdecl sub_726A80()
{
  char *v0; // esi@1

  v0 = &RCS.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RCS.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726AB0) --------------------------------------------------------  // acclient.c:824544
void __cdecl _E113_35()
{
  char *v0; // esi@1

  v0 = &PREPROC_KEYS_BASE_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PREPROC_KEYS_BASE_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726AE0) --------------------------------------------------------  // acclient.c:824557
void __cdecl _E116_27()
{
  char *v0; // esi@1

  v0 = &CURRENT_PROJECT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CURRENT_PROJECT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726B10) --------------------------------------------------------  // acclient.c:824570
void __cdecl _E119_53()
{
  char *v0; // esi@1

  v0 = &DATA_GAME_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DATA_GAME_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726B40) --------------------------------------------------------  // acclient.c:824583
void __cdecl _E122_40()
{
  char *v0; // esi@1

  v0 = &DATA_ENGINE_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DATA_ENGINE_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726B70) --------------------------------------------------------  // acclient.c:824596
void __cdecl _E125_16()
{
  char *v0; // esi@1

  v0 = &SOURCE_GAME_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SOURCE_GAME_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726BA0) --------------------------------------------------------  // acclient.c:824609
void __cdecl _E128_17()
{
  char *v0; // esi@1

  v0 = &SOURCE_ENGINE_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SOURCE_ENGINE_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726BD0) --------------------------------------------------------  // acclient.c:824622
void __cdecl _E131_13()
{
  char *v0; // esi@1

  v0 = &TOOLS_BIN_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TOOLS_BIN_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726C00) --------------------------------------------------------  // acclient.c:824635
void __cdecl _E134_12()
{
  char *v0; // esi@1

  v0 = &CONFIG_TOOLS_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CONFIG_TOOLS_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726C30) --------------------------------------------------------  // acclient.c:824648
void __cdecl _E137_13()
{
  char *v0; // esi@1

  v0 = &OUTPUT_INI_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OUTPUT_INI_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726C60) --------------------------------------------------------  // acclient.c:824661
void __cdecl _E140_8()
{
  char *v0; // esi@1

  v0 = &DATA_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DATA_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726C90) --------------------------------------------------------  // acclient.c:824674
void __cdecl _E143_10()
{
  char *v0; // esi@1

  v0 = &DOC_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DOC_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726CC0) --------------------------------------------------------  // acclient.c:824687
void __cdecl _E146_9()
{
  char *v0; // esi@1

  v0 = &EXPORT_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EXPORT_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726CF0) --------------------------------------------------------  // acclient.c:824700
void __cdecl _E149_9()
{
  char *v0; // esi@1

  v0 = &SDK_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SDK_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726D20) --------------------------------------------------------  // acclient.c:824713
void __cdecl _E152_8()
{
  char *v0; // esi@1

  v0 = &SOURCE_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SOURCE_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726D50) --------------------------------------------------------  // acclient.c:824726
void __cdecl _E155_6()
{
  char *v0; // esi@1

  v0 = &TOOLS_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TOOLS_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726D80) --------------------------------------------------------  // acclient.c:824739
void __cdecl _E158_9()
{
  char *v0; // esi@1

  v0 = &PORTAL_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PORTAL_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726DB0) --------------------------------------------------------  // acclient.c:824752
void __cdecl _E161_6()
{
  char *v0; // esi@1

  v0 = &AC_PATH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AC_PATH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00726DE0) --------------------------------------------------------  // acclient.c:824765
void __cdecl _E167_6()
{
  s_PrefetchCallback.vfptr = (AsyncCacheCallbackVtbl *)&DBCachePrefetchCallback::vftable;
  off_817688 = &HashSet<QualifiedDataID>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&stru_81768C);
  stru_81768C.vfptr = (IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>Vtbl *)IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vftable;
  if ( (HashSetData<QualifiedDataID> **)stru_81768C.m_buckets != stru_81768C.m_aInplaceBuckets )
    operator delete[](stru_81768C.m_buckets);
  stru_81768C.m_buckets = 0;
  stru_81768C.m_firstInterestingBucket = 0;
  stru_81768C.m_numBuckets = 0;
  stru_81768C.m_numElements = 0;
}
// 794F94: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vftable[4])(void *, char);
// 794FA0: using guessed type int (__thiscall *HashSet<QualifiedDataID>::vftable)(void *, char);
// 794FA4: using guessed type void (__thiscall *DBCachePrefetchCallback::vftable)(DBCachePrefetchCallback *this, AsyncContext hContext, AsyncResult Result, unsigned __int32);
// 817688: using guessed type int (__thiscall **)(void *, char);

//----- (00726E40) --------------------------------------------------------  // acclient.c:824784
void __cdecl _E164_10()
{
  DBCache::s_ObjCache = (int (__thiscall *(*)[2])(void *, char))HashTable<unsigned long,DBOCache *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81760C);
  stru_81760C.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::vftable;
  if ( (HashTableData<unsigned long,HeritageGroup_CG> **)stru_81760C.m_buckets != stru_81760C.m_aInplaceBuckets )
    operator delete[](stru_81760C.m_buckets);
  stru_81760C.m_buckets = 0;
  stru_81760C.m_firstInterestingBucket = 0;
  stru_81760C.m_numBuckets = 0;
  stru_81760C.m_numElements = 0;
}
// 794F90: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::vftable[5])(void *, char);
// 794F9C: using guessed type int (__thiscall *HashTable<unsigned long,DBOCache *,0>::vftable[2])(void *, char);
// 817608: using guessed type int (__thiscall *(*DBCache::s_ObjCache)[2])(void *, char);

