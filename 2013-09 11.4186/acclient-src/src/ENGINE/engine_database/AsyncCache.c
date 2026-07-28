/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AsyncCache
   Object     : ENGINE\engine_database\AsyncCache.obj
   Functions  : 81
   Addresses  : 00417350 - 006C4A00 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00417350) --------------------------------------------------------  // acclient.c:84002
void __thiscall Cache_Pack_t::Cache_Pack_t(Cache_Pack_t *this)
{
  this->m_dwOffset = 0;
  this->m_iVersion = 0;
  SmartBuffer::SmartBuffer(&this->m_buff);
}

//----- (00417370) --------------------------------------------------------  // acclient.c:84010
unsigned int __thiscall Cache_Pack_t::GetPackBufferPtr(Cache_Pack_t *this)
{
  SmartBuffer *v1; // esi@1

  v1 = &this->m_buff;
  SmartBuffer::ReconfigureAllocation(&this->m_buff, 4u, 1u);
  return SmartBuffer::GetBuffer(v1) + 4;
}

//----- (00417390) --------------------------------------------------------  // acclient.c:84020
unsigned int __thiscall Cache_Pack_t::GetDataSize(Cache_Pack_t *this)
{
  SmartBuffer *v1; // esi@1
  unsigned int result; // eax@2

  v1 = &this->m_buff;
  if ( SmartBuffer::GetSize(&this->m_buff) <= 4 )
    result = 0;
  else
    result = SmartBuffer::GetSize(v1) - 4;
  return result;
}

//----- (004173B0) --------------------------------------------------------  // acclient.c:84034
void __thiscall AsyncCache::CAsyncRequest::AdoptDBObj(AsyncCache::CAsyncRequest *this, DBObj *pObj)
{
  AsyncCache::CAsyncRequest *v2; // esi@1

  v2 = this;
  ((void (*)(void))this->vfptr[3].__vecDelDtor)();
  v2->m_pObj = pObj;
}

//----- (004173D0) --------------------------------------------------------  // acclient.c:84044
void __thiscall AsyncCache::CAsyncRequest::ReleaseDBObj(AsyncCache::CAsyncRequest *this)
{
  AsyncCache::CAsyncRequest *v1; // esi@1
  DBObj *v2; // ecx@1

  v1 = this;
  v2 = this->m_pObj;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_pObj = 0;
  }
}

//----- (004173F0) --------------------------------------------------------  // acclient.c:84059
int __thiscall Cache_Pack_t::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  *(_DWORD *)this = *(_DWORD *)a2;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  SmartBuffer::operator=(this + 8, a2 + 8);
  return v2;
}

//----- (00417420) --------------------------------------------------------  // acclient.c:84071
void __thiscall AsyncCache::OnRequestFinished(AsyncCache *this, AsyncCache::CAsyncRequest *pReq)
{
  unsigned int v2; // eax@1
  int v3; // eax@2

  v2 = pReq->Op;
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
        ((void (__stdcall *)(_DWORD))this->vfptr->OnSaveRequestFinished)(pReq);
    }
    else
    {
      ((void (__stdcall *)(_DWORD))this->vfptr->OnPurgeRequestFinished)(pReq);
    }
  }
  else
  {
    ((void (__stdcall *)(_DWORD))this->vfptr->OnGetRequestFinished)(pReq);
  }
}

//----- (00417450) --------------------------------------------------------  // acclient.c:84097
void __thiscall AsyncCache::OnPurgeRequestFinished(AsyncCache *this, CAsyncPurgeRequest *pPurgeReq)
{
  ((void (__stdcall *)(_DWORD))this->vfptr->NotifyCallback)(pPurgeReq);
}

//----- (00417460) --------------------------------------------------------  // acclient.c:84103
void __thiscall AsyncCache::UseTime(AsyncCache *this)
{
  ((void (*)(void))this->vfptr->CallPendingCallbacks)();
}

//----- (00417470) --------------------------------------------------------  // acclient.c:84109
bool __stdcall AsyncCache::AddObjToDBOCache(DBObj *pObj, DBOCache *pObjCache)
{
  bool result; // al@2

  if ( pObjCache )
    result = ((int (__stdcall *)(DBObj *))pObjCache->vfptr->AddObj)(pObj);
  else
    result = 0;
  return result;
}

//----- (004174C0) --------------------------------------------------------  // acclient.c:84135
DBObj *__stdcall AsyncCache::GetFreeObj(QualifiedDataID *qdid, DBOCache *pObjCache)
{
  DBObj *result; // eax@1
  DBObj *v4; // esi@2

  result = 0;
  if ( pObjCache )
  {
    v4 = (DBObj *)(*(int (**)(void))&pObjCache->vfptr->gap4[4])();
    if ( v4 )
      ((void (__thiscall *)(DBObj *, unsigned int))v4->vfptr[2].Release)(v4, qdid->ID.id);
    result = v4;
  }
  return result;
}

//----- (004174F0) --------------------------------------------------------  // acclient.c:84152
bool __thiscall AsyncCache::LoadData(AsyncCache *this, QualifiedDataID *qdid, Cache_Pack_t *Buf, unsigned __int64 idDatFile)
{
  int v4; // eax@1
  bool result; // al@2

  v4 = ((int (__stdcall *)(QualifiedDataID *, _DWORD, _DWORD))this->vfptr->GetDiskController)(
         qdid,
         idDatFile,
         HIDWORD(idDatFile));
  if ( v4 )
    result = (*(int (__thiscall **)(int, unsigned int, Cache_Pack_t *))(*(_DWORD *)v4 + 12))(v4, qdid->ID.id, Buf);
  else
    result = 0;
  return result;
}

//----- (00417530) --------------------------------------------------------  // acclient.c:84169
bool __thiscall AsyncCache::PurgeData(AsyncCache *this, QualifiedDataID *qdid, unsigned __int64 idDatFile)
{
  int v3; // eax@1
  bool result; // al@2

  v3 = ((int (__stdcall *)(QualifiedDataID *, _DWORD, _DWORD))this->vfptr->GetDiskController)(
         qdid,
         idDatFile,
         HIDWORD(idDatFile));
  if ( v3 )
    result = (*(int (__thiscall **)(int, unsigned int, _DWORD))(*(_DWORD *)v3 + 20))(v3, qdid->ID.id, 0);
  else
    result = 0;
  return result;
}

//----- (00417570) --------------------------------------------------------  // acclient.c:84186
bool __thiscall AsyncCache::SaveData(AsyncCache *this, QualifiedDataID *qdid, Cache_Pack_t *Buf, unsigned __int64 idDatFile)
{
  int v4; // eax@1
  bool result; // al@2

  v4 = ((int (__stdcall *)(QualifiedDataID *, _DWORD, _DWORD))this->vfptr->GetDiskController)(
         qdid,
         idDatFile,
         HIDWORD(idDatFile));
  if ( v4 )
    result = (*(int (__thiscall **)(int, unsigned int, Cache_Pack_t *, _DWORD))(*(_DWORD *)v4 + 16))(
               v4,
               qdid->ID.id,
               Buf,
               0);
  else
    result = 0;
  return result;
}

//----- (004175B0) --------------------------------------------------------  // acclient.c:84207
int __thiscall AsyncCache::BlockingPurge(AsyncCache *this, QualifiedDataID *qdid)
{
  return ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))this->vfptr->PurgeData)(qdid, 0, 0);
}

//----- (004175D0) --------------------------------------------------------  // acclient.c:84213
int __thiscall AsyncCache::BlockingSave(AsyncCache *this, QualifiedDataID *qdid, Cache_Pack_t *pack_buf)
{
  return ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->vfptr->SaveData)(qdid, pack_buf, 0, 0);
}

//----- (004175F0) --------------------------------------------------------  // acclient.c:84219
void __thiscall Cache_Pack_t::~Cache_Pack_t(Cache_Pack_t *this)
{
  SmartBuffer *v1; // esi@1

  v1 = &this->m_buff;
  SmartBuffer::ReleaseMasterBuffer(&this->m_buff);
  SmartBuffer::ReleaseMasterBuffer(v1);
}

//----- (00417610) --------------------------------------------------------  // acclient.c:84229
char __thiscall AsyncCache::CAsyncRequest::RemoveAllCallbacks(AsyncCache::CAsyncRequest *this)
{
  AsyncCache::CAsyncRequest *v1; // edi@1
  unsigned int v2; // ebx@1
  AsyncCache::CCallbackHandler *v3; // esi@2
  char result; // al@6

  v1 = this;
  v2 = 0;
  if ( this->m_pCallbacks.m_num )
  {
    do
    {
      v3 = v1->m_pCallbacks.m_data[v2].pCallbackHandler;
      if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
      {
        if ( v3 )
          v3->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 1u);
      }
      ++v2;
    }
    while ( v2 < v1->m_pCallbacks.m_num );
    v1->m_pCallbacks.m_num = 0;
    result = 1;
  }
  else
  {
    this->m_pCallbacks.m_num = 0;
    result = 1;
  }
  return result;
}

//----- (00417660) --------------------------------------------------------  // acclient.c:84263
void __thiscall CAsyncGetRequest::ReleaseDBObj(CAsyncGetRequest *this)
{
  CAsyncGetRequest *v1; // esi@1
  DBObj *v2; // ecx@1
  unsigned int v3; // eax@4
  HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *v4; // eax@4
  DBObj *v5; // ecx@6

  v1 = this;
  v2 = this->m_pObj;
  if ( v2 && (v1->m_dwGetRequestFlags & 4 || (unsigned __int8)((int (*)(void))v2->vfptr[1].QueryInterface)()) )
  {
    v3 = ((int (*)(void))v1->m_pObj->vfptr[3].IUnknown_QueryInterface)();
    v4 = DBCache::GetDBOCache(v3);
    if ( v4 )
      (*((void (__thiscall **)(HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *, _DWORD))v4->__vecDelDtor + 6))(
        v4,
        v1->m_pObj);
  }
  v5 = v1->m_pObj;
  if ( v5 )
  {
    ((void (*)(void))v5->vfptr->Release)();
    v1->m_pObj = 0;
  }
}

//----- (004176B0) --------------------------------------------------------  // acclient.c:84291
void __thiscall AsyncCache::EnqueueAsyncRequest(AsyncCache *this, AsyncCache::CAsyncRequest *pReq)
{
  AsyncCache *v2; // edi@1
  unsigned int v3; // eax@2
  int v4; // eax@3
  DBObj *v5; // ebx@7

  v2 = this;
  if ( pReq->qdid.ID.id == INVALID_DID_9.id )
  {
    pReq->Result = 3;
  }
  else
  {
    v3 = pReq->Op;
    if ( v3 )
    {
      v4 = v3 - 1;
      if ( !v4 )
      {
        pReq->Result = (unsigned __int8)(*(int (__stdcall **)(QualifiedDataID *))&this->vfptr->gap4[0])(&pReq->qdid) != 0 ? 1 : 3;
        v2->vfptr->OnRequestFinished(v2, pReq);
        return;
      }
      if ( v4 == 1 )
      {
        pReq->Result = (unsigned __int8)(*(int (__stdcall **)(QualifiedDataID *, AsyncCache::CAsyncRequest *))&this->vfptr->gap4[4])(
                                          &pReq->qdid,
                                          &pReq[1]) != 0 ? 1 : 3;
        v2->vfptr->OnRequestFinished(v2, pReq);
        return;
      }
    }
    else
    {
      v5 = this->vfptr->BlockingGet(this, (unsigned int)pReq[1].vfptr, &pReq->qdid);
      ((void (__thiscall *)(_DWORD))pReq->vfptr[3].__vecDelDtor)(pReq);
      pReq->m_pObj = v5;
      pReq->Result = 3;
      if ( v5 )
      {
        pReq->Result = 1;
        pReq[2].qdid.Type |= 4u;
        v2->vfptr->OnRequestFinished(v2, pReq);
        return;
      }
    }
  }
  v2->vfptr->OnRequestFinished(v2, pReq);
}

//----- (00417780) --------------------------------------------------------  // acclient.c:84343
void __thiscall AsyncCache::OnAsyncGetFinished(AsyncCache *this, CAsyncGetRequest *pGetReq)
{
  AsyncCache *v2; // ebp@1
  unsigned int v3; // ebx@4
  CAsyncGetRequest *v4; // esi@5
  int v5; // edx@5

  v2 = this;
  if ( pGetReq->Result == 1 && !pGetReq->m_pObj )
    pGetReq->Result = 3;
  v3 = 0;
  if ( pGetReq->RequestsWaitingForMe.m_num )
  {
    do
    {
      v4 = pGetReq->RequestsWaitingForMe.m_data[v3];
      v5 = v4->nGetsRemaining - 1;
      v4->nGetsRemaining = v5;
      if ( pGetReq->Result == 3 )
        v4->Result = 2;
      if ( !v5 )
        v2->vfptr->OnAsyncGetFinished(v2, v4);
      if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
        v4->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 1u);
      ++v3;
    }
    while ( v3 < pGetReq->RequestsWaitingForMe.m_num );
  }
  pGetReq->RequestsWaitingForMe.m_num = 0;
  v2->vfptr->NotifyCallback(v2, (AsyncCache::CAsyncRequest *)pGetReq);
}

//----- (00417810) --------------------------------------------------------  // acclient.c:84376
char __stdcall AsyncCache::SerializeFromCachePack(DBObj *io_pObj, Cache_Pack_t *i_cpData)
{
  unsigned int v3; // esi@1
  unsigned int v4; // ST04_4@1
  int v5; // eax@1
  InterfaceVtbl *v6; // eax@3
  char v7; // bl@3
  char result; // al@3
  ArchiveInitializer i_rInitializer; // [sp+Ch] [bp-38h]@3
  ArchiveVersionRow *v10; // [sp+10h] [bp-34h]@3
  SmartBuffer cBuffer; // [sp+14h] [bp-30h]@1
  Archive cArchive; // [sp+20h] [bp-24h]@1

  SmartBuffer::ReconfigureAllocation(&i_cpData->m_buff, 4u, 1u);
  SmartBuffer::MakeWindow(&i_cpData->m_buff, &cBuffer, 4u);
  cArchive.vfptr = (ArchiveVtbl *)&Archive::vftable;
  cArchive.m_flags = 0;
  cArchive.m_hrError.m_val = 0;
  SmartBuffer::SmartBuffer(&cArchive.m_buffer);
  v3 = i_cpData->m_iVersion;
  v4 = i_cpData->m_iVersion;
  cArchive.m_currOffset = 0;
  cArchive.m_pcUserDataHash = 0;
  cArchive.m_pVersionStack = 0;
  cArchive.m_flags |= 0x400u;
  v5 = GetCoreSDKPackVersionFromDBObjPackVersion(v4);
  if ( v3 && v5 )
  {
    i_rInitializer.vfptr = (ArchiveInitializerVtbl *)&Archive::SetVersionRow::vftable;
    v10 = GetVersionRowForDBObjPackVersion(v3);
    Archive::InitForUnpacking(&cArchive, &i_rInitializer, &cBuffer);
    v6 = io_pObj->vfptr;
    cArchive.m_flags |= 0x2000u;
    v6[1].IUnknown_AddRef((Interface *)&cArchive);
    v7 = ~(unsigned __int8)(cArchive.m_flags >> 2) & 1;
    Archive::~Archive(&cArchive);
    SmartBuffer::ReleaseMasterBuffer(&cBuffer);
    result = v7;
  }
  else
  {
    Archive::~Archive(&cArchive);
    SmartBuffer::ReleaseMasterBuffer(&cBuffer);
    result = 0;
  }
  return result;
}
// 792B3C: using guessed type void (__thiscall *Archive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);
// 79535C: using guessed type bool (__thiscall *Archive::SetVersionRow::vftable)(Archive::SetVersionRow *this, struct Archive *);

//----- (00417910) --------------------------------------------------------  // acclient.c:84427
void __thiscall AsyncCache::CallPendingCallbacks(AsyncCache *this)
{
  AsyncCache *v1; // edi@1
  DWORD v2; // ebp@2
  int v3; // eax@4
  int v4; // esi@4
  int v5; // ecx@4

  v1 = this;
  if ( !this->m_bCallingPendingCallbacks )
  {
    this->m_bCallingPendingCallbacks = 1;
    v2 = GetTickCount();
    while ( GetTickCount() - v2 < 0x19 )
    {
      if ( !v1->m_PendingCallbacks.count )
        break;
      v3 = (int)v1->m_PendingCallbacks.vfptr->RemoveAndReturn(&v1->m_PendingCallbacks, 0);
      v4 = v3;
      v5 = *(_DWORD *)(v3 + 12);
      if ( v5 && *(_DWORD *)(v3 + 36) != INVALID_ASYNCCONTEXT_2.m_id )
        (**(void (__stdcall ***)(_DWORD, _DWORD, _DWORD))v5)(
          *(_DWORD *)(v3 + 36),
          *(_DWORD *)(v3 + 16),
          *(_DWORD *)(v3 + 20));
      if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    v1->m_bCallingPendingCallbacks = 0;
  }
}

//----- (004179B0) --------------------------------------------------------  // acclient.c:84460
char __thiscall AsyncCache::BlockingLoadInto(AsyncCache *this, DBObj *pObj, QualifiedDataID *qdid, DBOCache *pObjCache)
{
  AsyncCache *v4; // esi@1
  char v5; // bl@1
  Cache_Pack_t Buf; // [sp+10h] [bp-14h]@1

  v4 = this;
  v5 = qdid->ID.id != INVALID_DID_9.id;
  Buf.m_dwOffset = 0;
  Buf.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&Buf.m_buff);
  if ( v5 )
  {
    v5 = ((int (__thiscall *)(AsyncCache *, QualifiedDataID *, Cache_Pack_t *, _DWORD, _DWORD))v4->vfptr->LoadData)(
           v4,
           qdid,
           &Buf,
           0,
           0);
    if ( v5 )
    {
      v5 = v4->vfptr->SerializeFromCachePack(v4, pObj, &Buf);
      if ( v5 )
      {
        if ( pObj->m_DID.id != qdid->ID.id )
          v5 = 0;
      }
    }
  }
  SmartBuffer::ReleaseMasterBuffer(&Buf.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&Buf.m_buff);
  return v5;
}

//----- (00417A40) --------------------------------------------------------  // acclient.c:84495
DBObj *__thiscall AsyncCache::BlockingGetFromDisk(AsyncCache *this, QualifiedDataID *qdid, DBOCache *pObjCache)
{
  AsyncCache *v3; // edi@1
  DBObj *v4; // esi@1

  v3 = this;
  v4 = 0;
  if ( qdid->ID.id != INVALID_DID_9.id )
    v4 = this->vfptr->GetFreeObj(this, qdid, pObjCache);
  if ( v3->vfptr->BlockingLoadInto(v3, v4, qdid, pObjCache)
    && (unsigned __int8)((int (__thiscall *)(DBObj *))v4->vfptr[1].QueryInterface)(v4) )
  {
    v3->vfptr->AddObjToDBOCache(v3, v4, pObjCache);
    return v4;
  }
  if ( !v4 )
    return v4;
  v4->vfptr->Release((Interface *)v4);
  return 0;
}

//----- (00417AB0) --------------------------------------------------------  // acclient.c:84517
void __thiscall SmartArray<AsyncCache::CAsyncRequest::CCallbackWrapper,1>::Reset(SmartArray<AsyncCache::CAsyncRequest::CCallbackWrapper,1> *this)
{
  SmartArray<AsyncCache::CAsyncRequest::CCallbackWrapper,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int i; // eax@4
  void *v5; // edi@5

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    for ( i = (v2 & 0x7FFFFFFF) - 1; i >= 0; *((_DWORD *)v5 + 2 * i + 3) = 0 )
    {
      --i;
      v5 = v1->m_data;
      *((_DWORD *)v5 + 2 * i + 2) = 0;
    }
  }
}

//----- (00417B00) --------------------------------------------------------  // acclient.c:84547
char __thiscall AsyncCache::CAsyncRequest::RemoveCallback(AsyncCache::CAsyncRequest *this, AsyncCache::CCallbackHandler *pCallback)
{
  unsigned int v2; // esi@1
  unsigned int v3; // eax@1
  AsyncCache::CAsyncRequest::CCallbackWrapper *v4; // edx@2
  char result; // al@5
  unsigned int v6; // edx@6
  int v7; // esi@7
  AsyncCache::CAsyncRequest::CCallbackWrapper *v8; // edx@8
  unsigned int v9; // esi@8
  AsyncCache::CAsyncRequest::CCallbackWrapper *v10; // ecx@8

  v2 = this->m_pCallbacks.m_num;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->m_pCallbacks.m_data;
    while ( v4->pCallbackHandler != pCallback )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
    v6 = this->m_pCallbacks.m_num;
    if ( v3 < v6 )
    {
      v7 = v6 - 1;
      this->m_pCallbacks.m_num = v6 - 1;
      if ( v3 != v6 - 1 )
      {
        v8 = this->m_pCallbacks.m_data;
        v8[v3].pCallbackHandler = v8[v7].pCallbackHandler;
        v8[v3].dwTimesFinished = v8[v7].dwTimesFinished;
        v9 = this->m_pCallbacks.m_num;
        v10 = this->m_pCallbacks.m_data;
        v10[v9].pCallbackHandler = 0;
        v10[v9].dwTimesFinished = 0;
      }
    }
    if ( !InterlockedDecrement((volatile LONG *)&pCallback->m_cRef) )
    {
      if ( pCallback )
        pCallback->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)pCallback, 1u);
    }
    result = 1;
  }
  else
  {
LABEL_5:
    result = 0;
  }
  return result;
}

//----- (00417B80) --------------------------------------------------------  // acclient.c:84603
void __thiscall AsyncCache::CCallbackHandler::OnContextReleased(AsyncCache::CCallbackHandler *this)
{
  AsyncCache::CCallbackHandler *v1; // esi@1
  unsigned int v2; // ebx@1
  AsyncCache::CAsyncRequest *v3; // edi@2

  v1 = this;
  v2 = 0;
  if ( this->m_TopLevelReqs.m_num )
  {
    do
    {
      AsyncCache::CAsyncRequest::RemoveCallback(v1->m_TopLevelReqs.m_data[v2], v1);
      v3 = v1->m_TopLevelReqs.m_data[v2];
      if ( v3 )
      {
        if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
          v3->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 1u);
        v1->m_TopLevelReqs.m_data[v2] = 0;
      }
      ++v2;
    }
    while ( v2 < v1->m_TopLevelReqs.m_num );
  }
  v1->m_TopLevelReqs.m_num = 0;
  v1->m_pCallbackPlugin = 0;
  v1->m_hContext.m_id = INVALID_ASYNCCONTEXT_2.m_id;
}

//----- (00417BF0) --------------------------------------------------------  // acclient.c:84633
void __thiscall AsyncCache::AsyncGetImmediate(AsyncCache *this, AsyncContext *o_context, unsigned int type, QualifiedDataIDArray *qdids, AsyncCacheCallback *pCallbackPlugin, unsigned int dwUser1)
{
  AsyncCache *v6; // esi@1
  unsigned int v7; // ebp@1
  unsigned int *v8; // eax@1
  unsigned int v9; // ebx@1
  unsigned int v10; // edi@2
  unsigned int v11; // ebp@3
  int v12; // ecx@3
  unsigned int v13; // esi@3
  int v14; // eax@7
  int v15; // esi@7
  int v16; // ecx@7
  unsigned int idxCurCallbacks; // [sp+14h] [bp-4h]@1

  v6 = this;
  v7 = this->m_PendingCallbacks.count;
  idxCurCallbacks = this->m_PendingCallbacks.count;
  v8 = (unsigned int *)(*(int (__stdcall **)(unsigned int *, unsigned int, QualifiedDataIDArray *, AsyncCacheCallback *, unsigned int))&this->vfptr->gap4[12])(
                         &dwUser1,
                         type,
                         qdids,
                         pCallbackPlugin,
                         dwUser1);
  v9 = *v8;
  o_context->m_id = *v8;
  if ( !v6->m_bCallingPendingCallbacks )
  {
    v10 = v6->m_PendingCallbacks.count;
    if ( v10 > v7 )
    {
      v11 = v6->m_PendingCallbacks.max;
      v12 = (int)&v6->m_PendingCallbacks;
      v13 = v6->m_PendingCallbacks.first;
      while ( 1 )
      {
        --v10;
        if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v12 + 4) + 4 * ((v13 + v10) % v11)) + 36) == v9 )
          break;
        if ( v10 <= idxCurCallbacks )
          return;
      }
      v14 = (*(int (__stdcall **)(unsigned int))(*(_DWORD *)v12 + 12))(v10);
      v15 = v14;
      v16 = *(_DWORD *)(v14 + 12);
      if ( v16 && *(_DWORD *)(v14 + 36) != INVALID_ASYNCCONTEXT_2.m_id )
        (**(void (__stdcall ***)(_DWORD, _DWORD, _DWORD))v16)(
          *(_DWORD *)(v14 + 36),
          *(_DWORD *)(v14 + 16),
          *(_DWORD *)(v14 + 20));
      if ( !InterlockedDecrement((volatile LONG *)(v15 + 4)) )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    }
  }
}

//----- (00417CB0) --------------------------------------------------------  // acclient.c:84690
char __thiscall AsyncCache::AreOnDisk(AsyncCache *this, QualifiedDataIDArray *qdids)
{
  AsyncCache *v2; // ebp@1
  DBObjSaveInfo *v3; // edi@1
  IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *v4; // ebx@2
  DBObjSaveInfo **v5; // esi@2
  char result; // al@8
  IntrusiveHashIterator<QualifiedDataID,DBObjSaveInfo *,1> iter; // [sp+Ch] [bp-Ch]@1

  v2 = this;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)qdids,
    (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&iter);
  v3 = iter.m_currElement;
  if ( iter.m_currElement )
  {
    v4 = iter.m_currHashTable;
    v5 = iter.m_currBucket;
    do
    {
LABEL_3:
      if ( !v2->vfptr->IsOnDisk(v2, (QualifiedDataID *)v3) )
        return 0;
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
          goto LABEL_3;
        break;
      }
    }
    result = 1;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (00417D40) --------------------------------------------------------  // acclient.c:84739
char __thiscall SmartArray<AsyncCache::CAsyncRequest::CCallbackWrapper,1>::grow(SmartArray<AsyncCache::CAsyncRequest::CCallbackWrapper,1> *this, unsigned int i_nSize)
{
  SmartArray<AsyncCache::CAsyncRequest::CCallbackWrapper,1> *v2; // esi@1
  void *v4; // eax@5
  AsyncCache::CAsyncRequest::CCallbackWrapper *v5; // edi@5
  int i; // eax@7
  void *v7; // edx@8

  v2 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<AsyncCache::CAsyncRequest::CCallbackWrapper,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](8 * i_nSize);
    v5 = (AsyncCache::CAsyncRequest::CCallbackWrapper *)v4;
    if ( v4 )
    {
      vector_constructor_iterator(v4, 8u, i_nSize, (void *(__thiscall *)(void *))BaseProperty::BaseProperty);
      if ( v2->m_data )
      {
        for ( i = v2->m_num - 1; i >= 0; v5[i + 1].dwTimesFinished = *((_DWORD *)v7 + 2 * i + 3) )
        {
          --i;
          v7 = v2->m_data;
          v5[i + 1].pCallbackHandler = v2->m_data[i + 1].pCallbackHandler;
        }
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = v5;
      v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (00417E90) --------------------------------------------------------  // acclient.c:84817
BOOL __thiscall AsyncCache::CAsyncRequest::ReadyToUnhash(AsyncCache::CAsyncRequest *this)
{
  return this->m_cRef == 2;
}

//----- (00417EA0) --------------------------------------------------------  // acclient.c:84823
void __thiscall AsyncCache::CAsyncRequest::~CAsyncRequest(AsyncCache::CAsyncRequest *this)
{
  AsyncCache::CAsyncRequest *v1; // esi@1
  DBObj *v2; // ecx@1

  v1 = this;
  v2 = this->m_pObj;
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&AsyncCache::CAsyncRequest::vftable;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_pObj = 0;
  }
  if ( (v1->m_pCallbacks.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_pCallbacks.m_data);
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 795360: using guessed type int (__thiscall *AsyncCache::CAsyncRequest::vftable)(void *, char);

//----- (00417EF0) --------------------------------------------------------  // acclient.c:84844
void __thiscall CAsyncGetRequest::~CAsyncGetRequest(CAsyncGetRequest *this)
{
  CAsyncGetRequest *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebp@1
  CAsyncGetRequest *v4; // edi@2
  unsigned int v5; // ebp@6
  CAsyncGetRequest *v6; // edi@7
  DBObj *v7; // ecx@11
  unsigned int v8; // eax@14
  HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *v9; // eax@14
  DBObj *v10; // ecx@16
  DBObj *v11; // ecx@22

  v1 = this;
  v2 = this->RequestsImWaitingFor.m_num;
  v3 = 0;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CAsyncGetRequest::vftable;
  if ( v2 )
  {
    do
    {
      v4 = v1->RequestsImWaitingFor.m_data[v3];
      if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
        v4->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 1u);
      ++v3;
    }
    while ( v3 < v1->RequestsImWaitingFor.m_num );
  }
  v5 = 0;
  if ( v1->RequestsWaitingForMe.m_num )
  {
    do
    {
      v6 = v1->RequestsWaitingForMe.m_data[v5];
      if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
        v6->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 1u);
      ++v5;
    }
    while ( v5 < v1->RequestsWaitingForMe.m_num );
  }
  v7 = v1->m_pObj;
  if ( v7 && (v1->m_dwGetRequestFlags & 4 || (unsigned __int8)((int (*)(void))v7->vfptr[1].QueryInterface)()) )
  {
    v8 = ((int (*)(void))v1->m_pObj->vfptr[3].IUnknown_QueryInterface)();
    v9 = DBCache::GetDBOCache(v8);
    if ( v9 )
      (*((void (__thiscall **)(HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *, _DWORD))v9->__vecDelDtor + 6))(
        v9,
        v1->m_pObj);
  }
  v10 = v1->m_pObj;
  if ( v10 )
  {
    ((void (*)(void))v10->vfptr->Release)();
    v1->m_pObj = 0;
  }
  SmartBuffer::ReleaseMasterBuffer(&v1->Buf.m_buff);
  SmartBuffer::ReleaseMasterBuffer(&v1->Buf.m_buff);
  if ( (v1->RequestsImWaitingFor.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->RequestsImWaitingFor.m_data);
  if ( (v1->RequestsWaitingForMe.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->RequestsWaitingForMe.m_data);
  v11 = v1->m_pObj;
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&AsyncCache::CAsyncRequest::vftable;
  if ( v11 )
  {
    ((void (*)(void))v11->vfptr->Release)();
    v1->m_pObj = 0;
  }
  if ( (v1->m_pCallbacks.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_pCallbacks.m_data);
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 795360: using guessed type int (__thiscall *AsyncCache::CAsyncRequest::vftable)(void *, char);
// 795374: using guessed type int (__thiscall *CAsyncGetRequest::vftable)(void *, char);

//----- (00418040) --------------------------------------------------------  // acclient.c:84923
BOOL __thiscall CAsyncGetRequest::bAllDependanciesDone(CAsyncGetRequest *this)
{
  return this->nGetsRemaining == 0;
}

//----- (00418050) --------------------------------------------------------  // acclient.c:84929
void __thiscall AsyncCache::CCallbackHandler::~CCallbackHandler(AsyncCache::CCallbackHandler *this)
{
  AsyncCache::CCallbackHandler *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  AsyncCache::CAsyncRequest *v4; // edi@2

  v1 = this;
  v2 = this->m_TopLevelReqs.m_num;
  v3 = 0;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)AsyncCache::CCallbackHandler::vftable;
  if ( v2 )
  {
    do
    {
      AsyncCache::CAsyncRequest::RemoveCallback(v1->m_TopLevelReqs.m_data[v3], v1);
      v4 = v1->m_TopLevelReqs.m_data[v3];
      if ( v4 )
      {
        if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
          v4->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 1u);
        v1->m_TopLevelReqs.m_data[v3] = 0;
      }
      ++v3;
    }
    while ( v3 < v1->m_TopLevelReqs.m_num );
  }
  if ( (v1->m_TopLevelReqs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_TopLevelReqs.m_data);
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 795370: using guessed type int (__thiscall *AsyncCache::CCallbackHandler::vftable[2])(void *, char);

//----- (00418130) --------------------------------------------------------  // acclient.c:84986
AsyncCache::CAsyncRequest *__thiscall AsyncCache::CAsyncRequest::scalar_deleting_destructor(AsyncCache::CAsyncRequest *this, unsigned int a2)
{
  AsyncCache::CAsyncRequest *v2; // esi@1
  DBObj *v3; // ecx@1

  v2 = this;
  v3 = this->m_pObj;
  v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&AsyncCache::CAsyncRequest::vftable;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v2->m_pObj = 0;
  }
  if ( (v2->m_pCallbacks.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v2->m_pCallbacks.m_data);
  v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 795360: using guessed type int (__thiscall *AsyncCache::CAsyncRequest::vftable)(void *, char);

//----- (00418190) --------------------------------------------------------  // acclient.c:85010
AsyncCache::CCallbackHandler *__thiscall AsyncCache::CCallbackHandler::vector_deleting_destructor(AsyncCache::CCallbackHandler *this, unsigned int a2)
{
  AsyncCache::CCallbackHandler *v2; // esi@1

  v2 = this;
  AsyncCache::CCallbackHandler::~CCallbackHandler(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004181B0) --------------------------------------------------------  // acclient.c:85022
void __thiscall CAsyncGetRequest::CAsyncGetRequest(CAsyncGetRequest *this)
{
  CAsyncGetRequest *v1; // esi@1

  v1 = this;
  this->m_cRef = 1;
  this->Result = 0;
  this->m_pCallbacks.m_data = 0;
  this->m_pCallbacks.m_sizeAndDeallocate = 0;
  this->m_pCallbacks.m_num = 0;
  this->m_pObj = 0;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CAsyncGetRequest::vftable;
  this->RequestsWaitingForMe.m_data = 0;
  this->RequestsWaitingForMe.m_sizeAndDeallocate = 0;
  this->RequestsWaitingForMe.m_num = 0;
  this->RequestsImWaitingFor.m_data = 0;
  this->RequestsImWaitingFor.m_sizeAndDeallocate = 0;
  this->RequestsImWaitingFor.m_num = 0;
  this->Buf.m_dwOffset = 0;
  this->Buf.m_iVersion = 0;
  SmartBuffer::SmartBuffer(&this->Buf.m_buff);
  v1->m_dwGetRequestFlags = 0;
}
// 795374: using guessed type int (__thiscall *CAsyncGetRequest::vftable)(void *, char);

//----- (00418200) --------------------------------------------------------  // acclient.c:85048
CAsyncGetRequest *__thiscall CAsyncGetRequest::scalar_deleting_destructor(CAsyncGetRequest *this, unsigned int a2)
{
  CAsyncGetRequest *v2; // esi@1

  v2 = this;
  CAsyncGetRequest::~CAsyncGetRequest(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00418220) --------------------------------------------------------  // acclient.c:85060
CAsyncPurgeRequest *__thiscall CAsyncPurgeRequest::scalar_deleting_destructor(CAsyncPurgeRequest *this, unsigned int a2)
{
  CAsyncPurgeRequest *v2; // esi@1

  v2 = this;
  AsyncCache::CAsyncRequest::~CAsyncRequest((AsyncCache::CAsyncRequest *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00418240) --------------------------------------------------------  // acclient.c:85072
AsyncCache::CAsyncRequest *__thiscall CAsyncSaveRequest::vector_deleting_destructor(CAsyncSaveRequest *this, unsigned int a2)
{
  AsyncCache::CAsyncRequest *v2; // esi@1

  v2 = (AsyncCache::CAsyncRequest *)this;
  Cache_Pack_t::~Cache_Pack_t(&this->Buf);
  AsyncCache::CAsyncRequest::~CAsyncRequest(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004182B0) --------------------------------------------------------  // acclient.c:85108
void __thiscall AsyncCache::NotifyCallback(AsyncCache *this, AsyncCache::CAsyncRequest *pReq)
{
  AsyncCache::CAsyncRequest *v2; // esi@1
  AsyncCache *v3; // ebp@1
  unsigned int v4; // edi@2
  int v5; // ecx@3
  int v6; // eax@3
  int v7; // ecx@5
  unsigned int v8; // ebx@9
  AsyncCache::CAsyncRequest *v9; // eax@10
  unsigned int v10; // ecx@11
  unsigned int v11; // ecx@12
  unsigned int v12; // edx@16
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *v13; // eax@22

  v2 = pReq;
  v3 = this;
  if ( !pReq->Op )
  {
    v4 = 0;
    if ( pReq->m_pCallbacks.m_num )
    {
      do
      {
        v5 = (int)&v2->m_pCallbacks.m_data[v4];
        v6 = *(_DWORD *)v5;
        if ( *(_DWORD *)v5 )
        {
          if ( !*(_BYTE *)(v6 + 40) )
          {
            ++*(_DWORD *)(v5 + 4);
            v7 = *(_DWORD *)(v6 + 12);
            if ( v7 )
              (*(void (__stdcall **)(_DWORD, unsigned int, unsigned int, AsyncResult, _DWORD, unsigned int, AsyncCache::CAsyncRequest *))(*(_DWORD *)v7 + 4))(
                *(_DWORD *)(v6 + 36),
                v2->qdid.Type,
                v2->qdid.ID.id,
                v2->Result,
                *(_DWORD *)(v6 + 20),
                v2->m_pCallbacks.m_data[v4].dwTimesFinished,
                v2);
          }
        }
        ++v4;
      }
      while ( v4 < v2->m_pCallbacks.m_num );
    }
  }
  if ( (unsigned __int8)((int (__thiscall *)(AsyncCache::CAsyncRequest *))v2->vfptr[1].__vecDelDtor)(v2) )
  {
    v8 = 0;
    if ( v2->m_pCallbacks.m_num )
    {
      do
      {
        pReq = (AsyncCache::CAsyncRequest *)v2->m_pCallbacks.m_data[v8].pCallbackHandler;
        v9 = pReq;
        if ( pReq )
        {
          --pReq->Result;
          v10 = v2->Result;
          if ( v10 == 1 )
          {
            v11 = v9->qdid.Type;
            if ( v11 == 3 )
            {
              v9->qdid.Type = 2;
            }
            else if ( !v11 )
            {
              v9->qdid.Type = 1;
            }
          }
          else
          {
            v12 = v9->qdid.Type;
            if ( v12 == 1 )
            {
              v9->qdid.Type = 2;
            }
            else if ( !v12 )
            {
              v9->qdid.Type = v10;
            }
          }
          if ( pReq->Result == AsyncResult_Unknown && !LOBYTE(pReq[1].vfptr) )
          {
            v13 = v3->m_BusyCallbacks.m_intrusiveTable.m_buckets[(unsigned int)pReq->m_pObj
                                                               % v3->m_BusyCallbacks.m_intrusiveTable.m_numBuckets];
            if ( v13 )
            {
              while ( (DBObj *)v13->m_hashKey.m_id != pReq->m_pObj )
              {
                v13 = v13->m_hashNext;
                if ( !v13 )
                  goto LABEL_28;
              }
              if ( v13 )
              {
                InterlockedIncrement((volatile LONG *)&pReq->m_cRef);
                LOBYTE(pReq[1].vfptr) = 1;
                v3->m_PendingCallbacks.vfptr->Add(&v3->m_PendingCallbacks, (AsyncCache::CCallbackHandler *const *)&pReq);
              }
            }
          }
        }
LABEL_28:
        ++v8;
      }
      while ( v8 < v2->m_pCallbacks.m_num );
    }
    AsyncCache::CAsyncRequest::RemoveAllCallbacks(v2);
  }
}

//----- (00418400) --------------------------------------------------------  // acclient.c:85224
char __thiscall HashTable<QualifiedDataID,CAsyncGetRequest *,1>::find(HashTable<QualifiedDataID,CAsyncGetRequest *,1> *this, QualifiedDataID *_key, CAsyncGetRequest **_retval)
{
  char v3; // al@2
  IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::find_internal(
    (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *)&this->m_intrusiveTable,
    &result,
    _key);
  if ( result.m_currElement )
  {
    *_retval = (CAsyncGetRequest *)result.m_currElement->m_data;
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  return v3;
}

//----- (00418440) --------------------------------------------------------  // acclient.c:85246
void __thiscall AsyncCache::CAsyncRequest::AddCallback(AsyncCache::CAsyncRequest *this, AsyncCache::CCallbackHandler *pCallback)
{
  AsyncCache::CAsyncRequest *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // ecx@1
  int v5; // esi@1
  int v6; // eax@1
  unsigned int v7; // eax@2
  int v8; // ecx@3
  int v9; // edx@3

  v2 = this;
  InterlockedIncrement((volatile LONG *)&pCallback->m_cRef);
  v3 = v2->m_pCallbacks.m_sizeAndDeallocate;
  v4 = v2->m_pCallbacks.m_num;
  v5 = (int)&v2->m_pCallbacks;
  v6 = v3 & 0x7FFFFFFF;
  if ( v4 < v6
    || (v7 = SmartArray<UIChildFramework *,1>::get_new_size(v6 + 1),
        SmartArray<AsyncCache::CAsyncRequest::CCallbackWrapper,1>::grow(
          (SmartArray<AsyncCache::CAsyncRequest::CCallbackWrapper,1> *)v5,
          v7)) )
  {
    v8 = *(_DWORD *)(v5 + 8);
    v9 = *(_DWORD *)v5;
    *(_DWORD *)(v9 + 8 * v8) = pCallback;
    *(_DWORD *)(v9 + 8 * v8 + 4) = 0;
    ++*(_DWORD *)(v5 + 8);
  }
}

//----- (004184A0) --------------------------------------------------------  // acclient.c:85278
MissingIteration *__thiscall AsyncCache::FormGetRequest(AsyncCache *this, CAsyncGetRequest *pParentReq, unsigned int type, QualifiedDataID *qdid)
{
  AsyncCache *v4; // edi@1
  MissingIteration *v5; // esi@2
  MissingIteration *v6; // eax@2
  CAsyncGetRequest *v7; // eax@3
  int v8; // eax@4
  int v9; // esi@4
  IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> result; // [sp+Ch] [bp-Ch]@1

  v4 = this;
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::find_internal(
    (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *)&this->m_PendingGets.m_intrusiveTable,
    &result,
    qdid);
  if ( result.m_currElement )
  {
    v5 = result.m_currElement->m_data;
    InterlockedIncrement((volatile LONG *)&(&v5->vfptr)[1]);
    v6 = v5;
  }
  else
  {
    v7 = (CAsyncGetRequest *)operator new(0x64u);
    if ( v7 )
    {
      CAsyncGetRequest::CAsyncGetRequest(v7);
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    *(_DWORD *)(v9 + 92) = v4->vfptr->GetDBOCache(v4, qdid);
    *(_DWORD *)(v9 + 40) = type;
    *(_DWORD *)(v9 + 12) = 0;
    *(_QWORD *)(v9 + 16) = *qdid;
    *(_DWORD *)(v9 + 88) = 1;
    *(_DWORD *)(v9 + 8) = 0;
    v6 = (MissingIteration *)v9;
  }
  return v6;
}

//----- (00418540) --------------------------------------------------------  // acclient.c:85323
void __thiscall AsyncCache::OnSaveRequestFinished(AsyncCache *this, CAsyncSaveRequest *pSaveReq)
{
  CAsyncSaveRequest *v2; // edi@1
  AsyncCache *v3; // esi@1
  MissingIteration *v4; // ebx@2
  int v5; // edi@4
  IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> result; // [sp+Ch] [bp-Ch]@1

  v2 = pSaveReq;
  v3 = this;
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::find_internal(
    (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *)&this->m_PendingGets.m_intrusiveTable,
    &result,
    &pSaveReq->qdid);
  if ( result.m_currElement )
  {
    v4 = result.m_currElement->m_data;
    if ( !LODWORD(v4->idDatFile) && !((unsigned int)v4[2].vfptr & 2) )
    {
      LODWORD(v4->idDatFile) = pSaveReq->Result;
      v5 = (int)&pSaveReq->Buf.m_dwOffset;
      if ( pSaveReq->Result == 1 )
      {
        if ( !Cache_Pack_t::GetPackBufferPtr((Cache_Pack_t *)v5) || !Cache_Pack_t::GetDataSize((Cache_Pack_t *)v5) )
          ((void (__thiscall *)(AsyncCache *, QualifiedDataID *, int, _DWORD, _DWORD))v3->vfptr->LoadData)(
            v3,
            &pSaveReq->qdid,
            v5,
            0,
            0);
        Cache_Pack_t::operator=((int)&v4[1].IDsToDownload, v5);
      }
      v3->vfptr->OnGetRequestFinished(v3, (CAsyncGetRequest *)v4);
      v2 = pSaveReq;
    }
  }
  v3->vfptr->NotifyCallback(v3, (AsyncCache::CAsyncRequest *)v2);
}

//----- (004185E0) --------------------------------------------------------  // acclient.c:85363
char __thiscall AsyncCache::IsOnDisk(AsyncCache *this, QualifiedDataID *qdid)
{
  AsyncCache *v2; // esi@1
  DBOCache *v3; // eax@1
  MissingIteration *v4; // eax@4
  int v5; // eax@5
  char v6; // al@7
  int v7; // eax@8
  IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> result; // [sp+8h] [bp-Ch]@3

  v2 = this;
  v3 = (DBOCache *)((int (__stdcall *)(QualifiedDataID *))this->vfptr->GetDBOCache)(qdid);
  if ( v3 && DBOCache::IsInMemory(v3, qdid->ID)
    || (IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::find_internal(
          (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *)&v2->m_PendingGets.m_intrusiveTable,
          &result,
          qdid),
        result.m_currElement)
    && (v4 = result.m_currElement->m_data, !((unsigned int)v4[2].vfptr & 2))
    && (v5 = LODWORD(v4->idDatFile), v5 != 3)
    && v5 )
  {
    v6 = 1;
  }
  else
  {
    v7 = ((int (__thiscall *)(AsyncCache *, QualifiedDataID *, _DWORD, _DWORD))v2->vfptr->GetDiskController)(
           v2,
           qdid,
           0,
           0);
    if ( v7 )
      v6 = (*(int (__thiscall **)(int, unsigned int, _DWORD))(*(_DWORD *)v7 + 28))(v7, qdid->ID.id, 0);
    else
      v6 = 0;
  }
  return v6;
}

//----- (00418670) --------------------------------------------------------  // acclient.c:85403
unsigned int __thiscall AsyncCache::BlockingGet(AsyncCache *this, unsigned int type, QualifiedDataID *qdid)
{
  QualifiedDataID *v3; // ebx@1
  AsyncCache *v4; // edi@1
  int v6; // ebp@3
  unsigned int v7; // esi@5
  bool v8; // zf@5
  QualifiedDataID *v9; // eax@7

  v3 = qdid;
  v4 = this;
  if ( qdid->ID.id == INVALID_DID_9.id )
    return 0;
  v6 = ((int (__stdcall *)(_DWORD))this->vfptr->GetDBOCache)(qdid);
  if ( !v6 )
    return 0;
  v7 = (int)v4->vfptr->GetIfInMemory(v4, v3, (DBOCache *)v6);
  v8 = v7 == 0;
  if ( !v7 )
  {
    qdid = 0;
    if ( HashTable<QualifiedDataID,CAsyncGetRequest *,1>::find(
           (HashTable<QualifiedDataID,CAsyncGetRequest *,1> *)&v4->m_PendingGets.vfptr,
           v3,
           (CAsyncGetRequest **)&qdid)
      && (v9 = qdid, (v7 = qdid[4].ID.id) != 0) )
    {
      if ( !(qdid[12].Type & 4) )
      {
        if ( !(unsigned __int8)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)v7 + 36))(qdid[4].ID.id) )
          return 0;
        v9 = qdid;
      }
      v9[12].Type |= 4u;
      v4->vfptr->AddObjToDBOCache(v4, (DBObj *)v7, (DBOCache *)v6);
      (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v7 + 16))(v7);
    }
    else if ( (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 32))(v6) )
    {
      v7 = (int)v4->vfptr->BlockingGetFromDisk(v4, v3, (DBOCache *)v6);
    }
    v8 = v7 == 0;
  }
  if ( !v8 )
  {
    if ( *(_BYTE *)(v7 + 8) || type == 1 )
      return v7;
    if ( (unsigned __int8)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)v7 + 40))(v7) )
    {
      *(_BYTE *)(v7 + 8) = 1;
      return v7;
    }
  }
  if ( v7 )
  {
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v7 + 20))(v7);
    v7 = 0;
  }
  return v7;
}

//----- (00418770) --------------------------------------------------------  // acclient.c:85465
void __thiscall AsyncCache::OnAsyncGetFromOtherSourcesFailed(AsyncCache *this, QualifiedDataID *qdid)
{
  AsyncCache *v2; // esi@1
  MissingIteration *v3; // eax@2
  IntrusiveHashIterator<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> result; // [sp+4h] [bp-Ch]@1

  v2 = this;
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::find_internal(
    (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1> *)&this->m_PendingGets.m_intrusiveTable,
    &result,
    qdid);
  if ( result.m_currElement )
  {
    v3 = result.m_currElement->m_data;
    LODWORD(v3->idDatFile) = 3;
    v2->vfptr->OnGetRequestFinished(v2, (CAsyncGetRequest *)v3);
  }
}

//----- (004187B0) --------------------------------------------------------  // acclient.c:85485
void __thiscall IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>(IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>Vtbl *)IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<QualifiedDataID,CAsyncGetRequest *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<QualifiedDataID,CAsyncGetRequest *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 794F88: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::vftable[7])(void *, char);

//----- (00418840) --------------------------------------------------------  // acclient.c:85518
void __thiscall IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>(IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>Vtbl *)IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 794F8C: using guessed type int (__thiscall *IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::vftable[6])(void *, char);

//----- (004188D0) --------------------------------------------------------  // acclient.c:85551
char __thiscall IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::resize_internal(IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *v2; // esi@1
  char result; // al@2
  DBObjSaveInfo *v4; // edi@3
  int v5; // ecx@4
  DBObjSaveInfo **v6; // eax@5
  int v7; // eax@6
  DBObjSaveInfo **v8; // ebx@7
  DBObjSaveInfo *v9; // ecx@7
  DBObjSaveInfo *v10; // eax@9
  DBObjSaveInfo *v11; // edx@10
  unsigned int v12; // eax@18
  DBObjSaveInfo *v13; // ebx@18
  unsigned int v14; // eax@19
  unsigned int v15; // edx@20
  DBObjSaveInfo **v16; // eax@20
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
        if ( v2->m_firstInterestingBucket == (DBObjSaveInfo **)v5 )
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
            v2->m_firstInterestingBucket = (DBObjSaveInfo **)v7;
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
    if ( (DBObjSaveInfo **)v2->m_buckets != v2->m_aInplaceBuckets )
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
          IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::resize_internal(v2, v14);
        }
        v15 = (v4->m_hashKey.Type + v4->m_hashKey.ID.id) % v2->m_numBuckets;
        v16 = v2->m_buckets;
        v4->m_hashNext = v16[v15];
        v16[v15] = v4;
        v17 = (int)&v16[v15];
        if ( (DBObjSaveInfo **)v17 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (DBObjSaveInfo **)v17;
        ++v2->m_numElements;
        v4 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (004189E0) --------------------------------------------------------  // acclient.c:85662
char __thiscall IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::grow(IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::resize_internal(v2, *v3);
}

//----- (00418A30) --------------------------------------------------------  // acclient.c:85680
void __thiscall AsyncCache::CCallbackHandler::AddTopLevelRequest(AsyncCache::CCallbackHandler *this, AsyncCache::CAsyncRequest *pReq)
{
  AsyncCache::CCallbackHandler *v2; // edi@1
  int v3; // eax@1
  unsigned int v4; // eax@2

  v2 = this;
  InterlockedIncrement((volatile LONG *)&pReq->m_cRef);
  v3 = v2->m_TopLevelReqs.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v2->m_TopLevelReqs.m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v2->m_TopLevelReqs, v4)) )
    v2->m_TopLevelReqs.m_data[v2->m_TopLevelReqs.m_num++] = pReq;
  AsyncCache::CAsyncRequest::AddCallback(pReq, v2);
}

//----- (00418A90) --------------------------------------------------------  // acclient.c:85697
bool __thiscall AsyncCache::AddToAsyncGet(AsyncCache *this, AsyncContext context, unsigned int type, QualifiedDataIDArray *qdids)
{
  AsyncCache *v4; // esi@1
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *v5; // eax@1
  bool result; // al@4
  AsyncCache::CCallbackHandler *v7; // ebp@6
  MissingIteration *v8; // eax@9
  MissingIteration *v9; // edi@9
  volatile LONG *v10; // ebx@9
  int v11; // eax@9
  unsigned int v12; // eax@10
  int v13; // eax@12
  unsigned int v14; // eax@13
  QualifiedDataID *v15; // ecx@14
  unsigned int v16; // edx@14
  AsyncCache *v17; // esi@16
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *v18; // eax@22
  DBObjSaveInfo **v19; // ecx@28
  DBObjSaveInfo **v20; // eax@29
  DBObjSaveInfo *v21; // edx@30
  AsyncCache *v22; // [sp+4h] [bp-10h]@1
  IntrusiveHashIterator<QualifiedDataID,DBObjSaveInfo *,1> iter; // [sp+8h] [bp-Ch]@6

  v4 = this;
  v22 = this;
  v5 = this->m_BusyCallbacks.m_intrusiveTable.m_buckets[context.m_id
                                                      % this->m_BusyCallbacks.m_intrusiveTable.m_numBuckets];
  if ( !v5 )
    goto LABEL_4;
  while ( v5->m_hashKey.m_id != context.m_id )
  {
    v5 = v5->m_hashNext;
    if ( !v5 )
      goto LABEL_4;
  }
  if ( v5 )
  {
    v7 = v5->m_data;
    v7->m_nRequestsPending += qdids->m_numElements;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)qdids,
      (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&iter);
    if ( iter.m_currElement )
    {
      while ( 2 )
      {
        v8 = AsyncCache::FormGetRequest(v4, 0, type, &iter.m_currElement->m_hashKey);
        v9 = v8;
        v10 = (volatile LONG *)&(&v8->vfptr)[1];
        InterlockedIncrement((volatile LONG *)&(&v8->vfptr)[1]);
        v11 = v7->m_TopLevelReqs.m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( v7->m_TopLevelReqs.m_num < v11
          || (v12 = SmartArray<UIChildFramework *,1>::get_new_size(v11 + 1),
              SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v7->m_TopLevelReqs, v12)) )
          v7->m_TopLevelReqs.m_data[v7->m_TopLevelReqs.m_num++] = (AsyncCache::CAsyncRequest *)v9;
        InterlockedIncrement((volatile LONG *)&v7->m_cRef);
        v13 = v9->IDsToDownload.m_num & 0x7FFFFFFF;
        if ( v9->IDsToPurge.m_data < (QualifiedDataID *)v13
          || (v14 = SmartArray<UIChildFramework *,1>::get_new_size(v13 + 1),
              SmartArray<AsyncCache::CAsyncRequest::CCallbackWrapper,1>::grow(
                (SmartArray<AsyncCache::CAsyncRequest::CCallbackWrapper,1> *)&v9->IDsToDownload.m_sizeAndDeallocate,
                v14)) )
        {
          v15 = v9->IDsToPurge.m_data;
          v16 = v9->IDsToDownload.m_sizeAndDeallocate;
          *(_DWORD *)(v16 + 8 * (_DWORD)v15) = v7;
          *(_DWORD *)(v16 + 8 * (_DWORD)v15 + 4) = 0;
          ++v9->IDsToPurge.m_data;
        }
        if ( (unsigned __int8)((int (__thiscall *)(MissingIteration *))v9->vfptr[1].Serialize)(v9) )
        {
          v17 = v22;
          v22->vfptr->NotifyCallback(v22, (AsyncCache::CAsyncRequest *)v9);
        }
        else
        {
          if ( !((unsigned int)v9[2].vfptr & 1) )
            ((void (__stdcall *)(MissingIteration *))v22->vfptr->HashAndEnqueue)(v9);
          v17 = v22;
        }
        if ( !InterlockedDecrement(v10) )
          v9->vfptr->Serialize(v9, (Archive *)1);
        v18 = v17->m_BusyCallbacks.m_intrusiveTable.m_buckets[context.m_id
                                                            % v17->m_BusyCallbacks.m_intrusiveTable.m_numBuckets];
        if ( v18 )
        {
          while ( v18->m_hashKey.m_id != context.m_id )
          {
            v18 = v18->m_hashNext;
            if ( !v18 )
              return 1;
          }
          if ( v18 )
          {
            v7 = v18->m_data;
            iter.m_currElement = iter.m_currElement->m_hashNext;
            if ( iter.m_currElement )
            {
LABEL_8:
              v4 = v22;
              continue;
            }
            v19 = &iter.m_currHashTable->m_buckets[iter.m_currHashTable->m_numBuckets];
            while ( 1 )
            {
              v20 = iter.m_currBucket + 1;
              ++iter.m_currBucket;
              if ( iter.m_currBucket == v19 )
                break;
              v21 = *v20;
              if ( *v20 )
              {
                iter.m_currElement = *v20;
                if ( v21 )
                  goto LABEL_8;
                goto LABEL_32;
              }
            }
          }
        }
        break;
      }
    }
LABEL_32:
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00418C60) --------------------------------------------------------  // acclient.c:85832
char __thiscall AsyncCache::AddToAsyncGet(AsyncCache *this, AsyncContext context, SmartArray<_STL::pair<unsigned long,QualifiedDataIDArray>,1> *qdids)
{
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *v3; // eax@1
  char result; // al@4
  AsyncCache::CCallbackHandler *v5; // ebx@6
  unsigned int v6; // edx@6
  int v7; // ecx@6
  char *v8; // eax@7
  SmartArray<_STL::pair<unsigned long,QualifiedDataIDArray>,1> *v9; // eax@9
  int v10; // edx@10
  _STL::pair<unsigned long,QualifiedDataIDArray> *v11; // ecx@12
  unsigned int v12; // eax@12
  int v13; // edx@12
  int v14; // ecx@12
  int v15; // eax@13
  int v16; // eax@14
  int v17; // ebx@17
  MissingIteration *v18; // ebp@18
  int v19; // eax@18
  unsigned int v20; // edx@19
  int v21; // ST30_4@24
  int v27; // eax@28
  unsigned int v28; // edx@29
  int v29; // ST30_4@34
  QualifiedDataID *v31; // edx@37
  unsigned int v32; // ecx@37
  int v33; // ecx@45
  AsyncCache *v34; // [sp+4h] [bp-28h]@1
  AsyncCache::CCallbackHandler *pCallback; // [sp+8h] [bp-24h]@6
  unsigned int iArray; // [sp+Ch] [bp-20h]@9
  int v37; // [sp+10h] [bp-1Ch]@10
  unsigned int eType; // [sp+14h] [bp-18h]@12
  int v39; // [sp+1Ch] [bp-10h]@12
  int iter_4; // [sp+24h] [bp-8h]@16
  int iter_8; // [sp+28h] [bp-4h]@16

  v34 = this;
  v3 = this->m_BusyCallbacks.m_intrusiveTable.m_buckets[context.m_id
                                                      % this->m_BusyCallbacks.m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.m_id != context.m_id )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    v5 = v3->m_data;
    v6 = qdids->m_num;
    v7 = 0;
    pCallback = v3->m_data;
    if ( v6 )
    {
      v8 = (char *)&qdids->m_data->second.m_numElements;
      do
      {
        v7 += *(_DWORD *)v8;
        v8 += 132;
        --v6;
      }
      while ( v6 );
    }
    v5->m_nRequestsPending += v7;
    v9 = qdids;
    iArray = 0;
    if ( qdids->m_num )
    {
      v10 = 0;
      v37 = 0;
      while ( 1 )
      {
        v11 = v9->m_data;
        v12 = *(unsigned int *)((char *)&v9->m_data->first + v10);
        v13 = (int)((char *)v11 + v10);
        eType = v12;
        v14 = *(_DWORD *)(v13 + 100) + 4 * *(_DWORD *)(v13 + 108);
        v39 = v13;
        if ( *(_DWORD *)(v13 + 104) != v14 )
        {
          while ( 1 )
          {
            v15 = *(_DWORD *)(v13 + 104);
            if ( *(_DWORD *)v15 )
              break;
            v16 = v15 + 4;
            *(_DWORD *)(v13 + 104) = v16;
            if ( v16 == v14 )
              goto LABEL_48;
          }
          iter_4 = *(_DWORD *)(v13 + 104);
          iter_8 = **(_DWORD **)(v13 + 104);
          if ( **(_DWORD **)(v13 + 104) )
          {
            v17 = (int)&v5->m_TopLevelReqs;
            do
            {
LABEL_18:
              v18 = AsyncCache::FormGetRequest(v34, 0, eType, (QualifiedDataID *)iter_8);
              InterlockedIncrement((volatile LONG *)&(&v18->vfptr)[1]);
              v19 = *(_DWORD *)(v17 + 4) & 0x7FFFFFFF;
              if ( *(_DWORD *)(v17 + 8) < (unsigned int)v19 )
                goto LABEL_52;
              v20 = v19 + 1;
              if ( (unsigned int)(v19 + 1) > 8 )
              {
                if ( v20 <= 0x4000 )
                {
                  v21 = v19 + 1;
                  __asm { bsr     this, [esp+38h+var_14] }
                  if ( v20 > 1 << _EAX )
                    v20 = 2 * (1 << _EAX);
                }
                else if ( v20 & 0x3FFF )
                {
                  v20 += 0x4000 - (v20 & 0x3FFF);
                }
              }
              else
              {
                v20 = 8;
              }
              if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v17, v20) )
LABEL_52:
                *(_DWORD *)(*(_DWORD *)v17 + 4 * (*(_DWORD *)(v17 + 8))++) = v18;
              InterlockedIncrement((volatile LONG *)&pCallback->m_cRef);
              v27 = v18->IDsToDownload.m_num & 0x7FFFFFFF;
              if ( v18->IDsToPurge.m_data < (QualifiedDataID *)v27 )
                goto LABEL_53;
              v28 = v27 + 1;
              if ( (unsigned int)(v27 + 1) > 8 )
              {
                if ( v28 <= 0x4000 )
                {
                  v29 = v27 + 1;
                  __asm { bsr     this, [esp+38h+var_14] }
                  if ( v28 > 1 << _EAX )
                    v28 = 2 * (1 << _EAX);
                }
                else if ( v28 & 0x3FFF )
                {
                  v28 += 0x4000 - (v28 & 0x3FFF);
                }
              }
              else
              {
                v28 = 8;
              }
              if ( SmartArray<AsyncCache::CAsyncRequest::CCallbackWrapper,1>::grow(
                     (SmartArray<AsyncCache::CAsyncRequest::CCallbackWrapper,1> *)&v18->IDsToDownload.m_sizeAndDeallocate,
                     v28) )
              {
LABEL_53:
                v31 = v18->IDsToPurge.m_data;
                v32 = v18->IDsToDownload.m_sizeAndDeallocate;
                *(_DWORD *)(v32 + 8 * (_DWORD)v31) = pCallback;
                *(_DWORD *)(v32 + 8 * (_DWORD)v31 + 4) = 0;
                ++v18->IDsToPurge.m_data;
              }
              if ( (unsigned __int8)((int (__thiscall *)(MissingIteration *))v18->vfptr[1].Serialize)(v18) )
              {
                ((void (__stdcall *)(MissingIteration *))v34->vfptr->NotifyCallback)(v18);
              }
              else if ( !((unsigned int)v18[2].vfptr & 1) )
              {
                ((void (__stdcall *)(MissingIteration *))v34->vfptr->HashAndEnqueue)(v18);
              }
              if ( !InterlockedDecrement((volatile LONG *)&(&v18->vfptr)[1]) )
                v18->vfptr->Serialize(v18, (Archive *)1);
              iter_8 = *(_DWORD *)(iter_8 + 8);
            }
            while ( iter_8 );
            while ( 1 )
            {
              v33 = iter_4 + 4;
              iter_4 += 4;
              if ( iter_4 == *(_DWORD *)(v39 + 100) + 4 * *(_DWORD *)(v39 + 108) )
                break;
              if ( *(_DWORD *)v33 )
              {
                iter_8 = *(_DWORD *)v33;
                if ( *(_DWORD *)v33 )
                  goto LABEL_18;
                break;
              }
            }
          }
        }
LABEL_48:
        v9 = qdids;
        v10 = v37 + 132;
        _CF = iArray++ + 1 < qdids->m_num;
        v37 += 132;
        if ( !_CF )
          break;
        v5 = pCallback;
      }
    }
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00418F10) --------------------------------------------------------  // acclient.c:86042
void __stdcall AsyncCache::FilterSubDataIDs(QualifiedDataIDArray *io_qdids, unsigned int i_type)
{
  DBObjSaveInfo *v3; // ecx@1
  IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *v4; // ebp@2
  DBObjSaveInfo **v5; // esi@2
  DBObjSaveInfo *v6; // ebx@7
  DBObjSaveInfo **v7; // edx@7
  DBObjSaveInfo *v8; // eax@11
  DBObjSaveInfo *v9; // edi@12
  IntrusiveHashIterator<QualifiedDataID,DBObjSaveInfo *,1> iter; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)io_qdids,
    (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&iter);
  v3 = iter.m_currElement;
  if ( iter.m_currElement )
  {
    v4 = iter.m_currHashTable;
    v5 = iter.m_currBucket;
    do
    {
      while ( i_type == 1 || i_type != 2 && (i_type != 3 || !(~(unsigned __int8)(v3->m_dwSubDataIDFlags >> 3) & 1)) )
      {
        v6 = v3->m_hashNext;
        v7 = v5;
        if ( !v6 )
        {
          while ( 1 )
          {
            ++v7;
            if ( v7 == &v4->m_buckets[v4->m_numBuckets] )
              break;
            if ( *v7 )
            {
              v6 = *v7;
              break;
            }
          }
        }
        v8 = *v5;
        if ( *v5 == v3 )
          goto LABEL_22;
        do
        {
          v9 = v8;
          v8 = v8->m_hashNext;
        }
        while ( v8 != v3 );
        if ( v9 )
        {
          v9->m_hashNext = v8->m_hashNext;
          --v4->m_numElements;
          v3 = v6;
          v5 = v7;
        }
        else
        {
LABEL_22:
          *v5 = v8->m_hashNext;
          --v4->m_numElements;
          v3 = v6;
          v5 = v7;
        }
LABEL_19:
        if ( !v3 )
          return;
      }
      v3 = v3->m_hashNext;
    }
    while ( v3 );
    while ( 1 )
    {
      ++v5;
      if ( v5 == &v4->m_buckets[v4->m_numBuckets] )
        break;
      v3 = *v5;
      if ( *v5 )
        goto LABEL_19;
    }
  }
}

//----- (00418FE0) --------------------------------------------------------  // acclient.c:86125
char __thiscall IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::add(IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1> *this, HashTableData<QualifiedDataID,CAsyncGetRequest *> *data)
{
  IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1> *v2; // esi@1
  char v3; // al@2
  unsigned int v4; // edx@5
  HashTableData<QualifiedDataID,CAsyncGetRequest *> **v5; // eax@5
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
      IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::grow(v2);
    v4 = (data->m_hashKey.Type + data->m_hashKey.ID.id) % v2->m_numBuckets;
    v5 = v2->m_buckets;
    data->m_hashNext = v5[v4];
    v5[v4] = data;
    v6 = (int)&v5[v4];
    if ( (HashTableData<QualifiedDataID,CAsyncGetRequest *> **)v6 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashTableData<QualifiedDataID,CAsyncGetRequest *> **)v6;
    ++v2->m_numElements;
    v3 = 1;
  }
  return v3;
}

//----- (004190B0) --------------------------------------------------------  // acclient.c:86192
char __thiscall IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::add(IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1> *this, HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *data)
{
  IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *v4; // eax@1
  unsigned int v5; // edx@6
  HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey.m_id % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.m_id != data->m_hashKey.m_id )
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
      IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::grow(this);
    v5 = data->m_hashKey.m_id % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (00419130) --------------------------------------------------------  // acclient.c:86236
void __thiscall AsyncCache::OnGetRequestFinished(AsyncCache *this, CAsyncGetRequest *pGetReq)
{
  AsyncCache *v2; // edi@1
  bool v3; // zf@1
  DBObj *v4; // ebx@5
  DBObj *v5; // ebp@13
  DBObj *v6; // eax@13
  bool v7; // bl@14
  QualifiedDataIDArray qdids; // [sp+18h] [bp-80h]@9

  v2 = this;
  v3 = (pGetReq->m_dwGetRequestFlags & 1) == 0;
  pGetReq->m_dwGetRequestFlags &= 0xFFFFFFFD;
  if ( !v3 || pGetReq->m_pCallbacks.m_num || pGetReq->RequestsWaitingForMe.m_num )
  {
    if ( pGetReq->Result == 1 )
    {
      v4 = this->vfptr->GetIfInMemory(this, &pGetReq->qdid, pGetReq->pObjCache);
      if ( v4 )
      {
        ((void (__thiscall *)(_DWORD))pGetReq->vfptr[3].__vecDelDtor)(pGetReq);
        pGetReq->m_pObj = v4;
        pGetReq->m_dwGetRequestFlags |= 4u;
      }
      else
      {
        v5 = v2->vfptr->GetFreeObj(v2, &pGetReq->qdid, pGetReq->pObjCache);
        ((void (__thiscall *)(_DWORD))pGetReq->vfptr[3].__vecDelDtor)(pGetReq);
        pGetReq->m_pObj = v5;
        pGetReq->m_dwGetRequestFlags &= 0xFFFFFFFB;
        v6 = pGetReq->m_pObj;
        if ( !v6
          || (v7 = v2->vfptr->SerializeFromCachePack(v2, v6, &pGetReq->Buf),
              SmartBuffer::ReleaseMasterBuffer(&pGetReq->Buf.m_buff),
              !v7) )
        {
          if ( pGetReq->m_pObj )
          {
            ((void (__thiscall *)(_DWORD))pGetReq->vfptr[3].__vecDelDtor)(pGetReq);
            pGetReq->m_pObj = 0;
          }
          pGetReq->Result = 3;
          goto LABEL_10;
        }
      }
      if ( pGetReq->GSDIType != 1 && !pGetReq->m_pObj->m_bLoaded )
      {
        QualifiedDataIDArray::QualifiedDataIDArray(&qdids, 32);
        pGetReq->m_pObj->vfptr[1].IUnknown_Release((Interface *)&qdids);
        AsyncCache::FilterSubDataIDs(&qdids, pGetReq->GSDIType);
        (*(void (__thiscall **)(AsyncCache *, unsigned int, QualifiedDataIDArray *, CAsyncGetRequest *))&v2->vfptr->gap28[0])(
          v2,
          pGetReq->GSDIType,
          &qdids,
          pGetReq);
        QualifiedDataIDArray::~QualifiedDataIDArray(&qdids);
      }
    }
LABEL_10:
    v3 = pGetReq->nGetsRemaining-- == 1;
    if ( v3 )
      v2->vfptr->OnAsyncGetFinished(v2, pGetReq);
  }
}

//----- (00419270) --------------------------------------------------------  // acclient.c:86302
char __thiscall HashTable<QualifiedDataID,CAsyncGetRequest *,1>::add(HashTable<QualifiedDataID,CAsyncGetRequest *,1> *this, QualifiedDataID *_key, CAsyncGetRequest *const *_data)
{
  HashTable<QualifiedDataID,CAsyncGetRequest *,1> *v3; // edi@1
  void *v4; // eax@1
  void *v5; // esi@2
  char result; // al@7

  v3 = this;
  v4 = operator new(0x10u);
  if ( v4 )
  {
    *(_QWORD *)v4 = *_key;
    *((_DWORD *)v4 + 2) = 0;
    *((_DWORD *)v4 + 3) = *_data;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::add(
         &v3->m_intrusiveTable,
         (HashTableData<QualifiedDataID,CAsyncGetRequest *> *)v5) )
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

//----- (004192D0) --------------------------------------------------------  // acclient.c:86338
char __thiscall HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1>::add(HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1> *this, AsyncContext *_key, AsyncCache::CCallbackHandler *const *_data)
{
  HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1> *v3; // edi@1
  void *v4; // eax@1
  void *v5; // esi@2
  char result; // al@7

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *(_DWORD *)v4 = _key->m_id;
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = *_data;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::add(
         &v3->m_intrusiveTable,
         (HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *)v5) )
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

//----- (00419330) --------------------------------------------------------  // acclient.c:86374
AsyncCache::CCallbackHandler *__thiscall AsyncCache::AllocateCallback(AsyncCache *this, AsyncCacheCallback *pCallbackPlugin, unsigned int dwUser1, unsigned int nRequests)
{
  AsyncCacheCallback *v4; // ebp@1
  AsyncCache *v5; // edi@1
  unsigned int v6; // esi@4
  void *v7; // eax@4
  unsigned int v8; // ecx@5
  void *v9; // esi@5
  AsyncCache::CCallbackHandler *result; // eax@7

  v4 = pCallbackPlugin;
  v5 = this;
  if ( pCallbackPlugin )
  {
    if ( !this->dwNextCallbackHandle )
      this->dwNextCallbackHandle = 1;
    v6 = this->dwNextCallbackHandle;
    this->dwNextCallbackHandle = v6 + 1;
    v7 = operator new(0x2Cu);
    if ( v7 )
    {
      v8 = dwUser1;
      *((_DWORD *)v7 + 1) = 1;
      *(_DWORD *)v7 = AsyncCache::CCallbackHandler::vftable;
      *((_DWORD *)v7 + 2) = 0;
      *((_DWORD *)v7 + 3) = v4;
      *((_DWORD *)v7 + 4) = 0;
      *((_DWORD *)v7 + 5) = v8;
      *((_DWORD *)v7 + 6) = 0;
      *((_DWORD *)v7 + 7) = 0;
      *((_DWORD *)v7 + 8) = 0;
      *((_DWORD *)v7 + 9) = v6;
      *((_BYTE *)v7 + 40) = 0;
      v9 = v7;
    }
    else
    {
      v9 = 0;
    }
    *((_DWORD *)v9 + 2) += nRequests;
    pCallbackPlugin = (AsyncCacheCallback *)v9;
    InterlockedIncrement((volatile LONG *)v9 + 1);
    dwUser1 = *((_DWORD *)v9 + 9);
    HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1>::add(
      (HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1> *)&v5->m_BusyCallbacks.vfptr,
      (AsyncContext *)&dwUser1,
      (AsyncCache::CCallbackHandler *const *)&pCallbackPlugin);
    result = (AsyncCache::CCallbackHandler *)v9;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 795370: using guessed type int (__thiscall *AsyncCache::CCallbackHandler::vftable[2])(void *, char);

//----- (004193F0) --------------------------------------------------------  // acclient.c:86432
AsyncContext *__thiscall AsyncCache::CreateContext(AsyncCache *this, AsyncContext *result, AsyncCacheCallback *i_pcCallbackPlugin, unsigned int i_dwUser)
{
  AsyncCache::CCallbackHandler *v4; // esi@2
  AsyncContext *v5; // eax@4

  if ( i_pcCallbackPlugin )
  {
    v4 = AsyncCache::AllocateCallback(this, i_pcCallbackPlugin, i_dwUser, 0);
    result->m_id = v4->m_hContext.m_id;
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 1u);
    v5 = result;
  }
  else
  {
    v5 = result;
    result->m_id = INVALID_ASYNCCONTEXT_2.m_id;
  }
  return v5;
}

//----- (00419440) --------------------------------------------------------  // acclient.c:86454
AsyncContext *__thiscall AsyncCache::AsyncGet(AsyncCache *this, AsyncContext *result, unsigned int type, QualifiedDataID *qdid, AsyncCacheCallback *pCallbackPlugin, unsigned int dwUser1)
{
  AsyncCache *v6; // ebx@1
  MissingIteration *v7; // eax@1
  unsigned int v8; // ebp@1
  MissingIteration *v9; // edi@1
  AsyncCache::CCallbackHandler *v10; // esi@1
  AsyncContext *v11; // eax@12

  v6 = this;
  v7 = AsyncCache::FormGetRequest(this, 0, type, qdid);
  v8 = INVALID_ASYNCCONTEXT_2.m_id;
  v9 = v7;
  v10 = 0;
  if ( pCallbackPlugin )
  {
    v10 = AsyncCache::AllocateCallback(v6, pCallbackPlugin, dwUser1, 1u);
    AsyncCache::CCallbackHandler::AddTopLevelRequest(v10, (AsyncCache::CAsyncRequest *)v9);
    v8 = v10->m_hContext.m_id;
  }
  if ( (unsigned __int8)((int (__thiscall *)(MissingIteration *))v9->vfptr[1].Serialize)(v9) )
  {
    v6->vfptr->NotifyCallback(v6, (AsyncCache::CAsyncRequest *)v9);
  }
  else if ( !((unsigned int)v9[2].vfptr & 1) )
  {
    v6->vfptr->HashAndEnqueue(v6, (CAsyncGetRequest *)v9);
  }
  if ( v10 && !InterlockedDecrement((volatile LONG *)&v10->m_cRef) )
    v10->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v10, 1u);
  if ( !InterlockedDecrement((volatile LONG *)&(&v9->vfptr)[1]) )
    v9->vfptr->Serialize(v9, (Archive *)1);
  v11 = result;
  result->m_id = v8;
  return v11;
}

//----- (004194F0) --------------------------------------------------------  // acclient.c:86492
AsyncContext *__thiscall AsyncCache::AsyncGet(AsyncCache *this, AsyncContext *result, unsigned int type, QualifiedDataIDArray *qdids, AsyncCacheCallback *pCallbackPlugin, unsigned int dwUser1)
{
  QualifiedDataIDArray *v6; // esi@1
  unsigned int v7; // eax@1
  AsyncContext *v8; // eax@2
  AsyncCache::CCallbackHandler *v9; // eax@3
  AsyncCache::CCallbackHandler *v10; // ebx@3
  QualifiedDataIDArray **v11; // eax@4
  DBObjSaveInfo *v12; // edi@6
  DBObjSaveInfo **v13; // ebp@7
  AsyncCache::CAsyncRequest *v14; // eax@14
  AsyncCache::CAsyncRequest *v15; // esi@14
  AsyncCache *v16; // [sp+4h] [bp-10h]@1
  IntrusiveHashIterator<QualifiedDataID,DBObjSaveInfo *,1> iter; // [sp+8h] [bp-Ch]@6

  v6 = qdids;
  v7 = qdids->m_numElements;
  v16 = this;
  if ( v7 )
  {
    v9 = AsyncCache::AllocateCallback(this, pCallbackPlugin, dwUser1, v7);
    v10 = v9;
    if ( v9 )
    {
      qdids = (QualifiedDataIDArray *)v9->m_hContext.m_id;
      v11 = &qdids;
    }
    else
    {
      v11 = (QualifiedDataIDArray **)&INVALID_ASYNCCONTEXT_2;
    }
    qdids = *v11;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v6,
      (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&iter);
    v12 = iter.m_currElement;
    if ( iter.m_currElement )
    {
      v13 = iter.m_currBucket;
      do
      {
LABEL_8:
        if ( type != 1 && (type == 2 || type == 3 && ~(unsigned __int8)(v12->m_dwSubDataIDFlags >> 3) & 1) )
        {
          v14 = (AsyncCache::CAsyncRequest *)AsyncCache::FormGetRequest(v16, 0, type, &v12->m_hashKey);
          v15 = v14;
          if ( v10 )
            AsyncCache::CCallbackHandler::AddTopLevelRequest(v10, v14);
          if ( (unsigned __int8)((int (__thiscall *)(AsyncCache::CAsyncRequest *))v15->vfptr[1].__vecDelDtor)(v15) )
          {
            ((void (__stdcall *)(AsyncCache::CAsyncRequest *))v16->vfptr->NotifyCallback)(v15);
          }
          else if ( !(v15[2].qdid.Type & 1) )
          {
            ((void (__stdcall *)(AsyncCache::CAsyncRequest *))v16->vfptr->HashAndEnqueue)(v15);
          }
          if ( !InterlockedDecrement((volatile LONG *)&v15->m_cRef) )
            v15->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v15, 1u);
        }
        else if ( v10 )
        {
          --v10->m_nRequestsPending;
        }
        v12 = v12->m_hashNext;
      }
      while ( v12 );
      while ( 1 )
      {
        ++v13;
        if ( v13 == &iter.m_currHashTable->m_buckets[iter.m_currHashTable->m_numBuckets] )
          break;
        if ( *v13 )
        {
          v12 = *v13;
          if ( *v13 )
            goto LABEL_8;
          break;
        }
      }
    }
    if ( v10 )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v10->m_cRef) )
        v10->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v10, 1u);
    }
    v8 = result;
    result->m_id = (unsigned int)qdids;
  }
  else
  {
    v8 = result;
    result->m_id = INVALID_ASYNCCONTEXT_2.m_id;
  }
  return v8;
}

//----- (00419650) --------------------------------------------------------  // acclient.c:86589
AsyncContext *__thiscall AsyncCache::AsyncPurge(AsyncCache *this, AsyncContext *result, QualifiedDataID *qdid, AsyncCacheCallback *pCallbackPlugin, unsigned int dwUser1)
{
  AsyncCache *v5; // ebx@1
  void *v6; // eax@1
  void *v7; // esi@2
  AsyncCache::CCallbackHandler *v8; // edi@7
  AsyncContext *v9; // eax@10
  AsyncContext hContext; // [sp+10h] [bp-4h]@1

  v5 = this;
  hContext.m_id = INVALID_ASYNCCONTEXT_2.m_id;
  v6 = operator new(0x28u);
  if ( v6 )
  {
    *((_DWORD *)v6 + 1) = 1;
    *((_DWORD *)v6 + 2) = 0;
    *((_DWORD *)v6 + 6) = 0;
    *((_DWORD *)v6 + 7) = 0;
    *((_DWORD *)v6 + 8) = 0;
    *((_DWORD *)v6 + 9) = 0;
    *(_DWORD *)v6 = &CAsyncPurgeRequest::vftable;
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  *((_DWORD *)v7 + 3) = 1;
  *((_QWORD *)v7 + 2) = *qdid;
  if ( *((_DWORD *)v7 + 9) )
  {
    (*(void (__thiscall **)(void *))(*(_DWORD *)v7 + 12))(v7);
    *((_DWORD *)v7 + 9) = 0;
  }
  if ( pCallbackPlugin )
  {
    v8 = AsyncCache::AllocateCallback(v5, pCallbackPlugin, dwUser1, 1u);
    AsyncCache::CCallbackHandler::AddTopLevelRequest(v8, (AsyncCache::CAsyncRequest *)v7);
    hContext.m_id = v8->m_hContext.m_id;
    if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) )
      v8->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v8, 1u);
  }
  v5->vfptr->EnqueueAsyncRequest(v5, (AsyncCache::CAsyncRequest *)v7);
  if ( InterlockedDecrement((volatile LONG *)v7 + 1) )
  {
    v9 = result;
    result->m_id = hContext.m_id;
  }
  else
  {
    (**(void (__thiscall ***)(void *, signed int))v7)(v7, 1);
    v9 = result;
    result->m_id = hContext.m_id;
  }
  return v9;
}
// 795384: using guessed type int (__thiscall *CAsyncPurgeRequest::vftable)(void *, char);

//----- (00419740) --------------------------------------------------------  // acclient.c:86648
AsyncContext *__thiscall AsyncCache::AsyncPurge(AsyncCache *this, AsyncContext *result, QualifiedDataIDArray *qdids, AsyncCacheCallback *pCallbackPlugin, unsigned int dwUser1)
{
  AsyncCache::CCallbackHandler *v5; // eax@1
  AsyncCache::CCallbackHandler *v6; // esi@1
  QualifiedDataIDArray **v7; // eax@2
  unsigned int v8; // edi@4
  AsyncContext *v9; // eax@7

  v5 = AsyncCache::AllocateCallback(this, pCallbackPlugin, dwUser1, qdids->m_numElements);
  v6 = v5;
  if ( v5 )
  {
    qdids = (QualifiedDataIDArray *)v5->m_hContext.m_id;
    v7 = &qdids;
  }
  else
  {
    v7 = (QualifiedDataIDArray **)&INVALID_ASYNCCONTEXT_2;
  }
  v8 = (unsigned int)*v7;
  if ( v6 && !InterlockedDecrement((volatile LONG *)&v6->m_cRef) )
    v6->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 1u);
  v9 = result;
  result->m_id = v8;
  return v9;
}

//----- (004197A0) --------------------------------------------------------  // acclient.c:86676
AsyncContext *__thiscall AsyncCache::AsyncSave(AsyncCache *this, AsyncContext *result, QualifiedDataID *qdid, Cache_Pack_t *pack_buf, unsigned __int64 idDestination, AsyncCacheCallback *pCallbackPlugin, unsigned int dwUser1)
{
  unsigned int v7; // ebp@1
  AsyncCache *v8; // ebx@1
  void *v9; // eax@1
  void *v10; // esi@1
  AsyncCache::CCallbackHandler *v11; // edi@5
  AsyncContext *v12; // eax@9

  v7 = INVALID_ASYNCCONTEXT_2.m_id;
  v8 = this;
  v9 = operator new(0x58u);
  v10 = v9;
  if ( v9 )
  {
    *((_DWORD *)v9 + 1) = 1;
    *((_DWORD *)v9 + 2) = 0;
    *((_DWORD *)v9 + 6) = 0;
    *((_DWORD *)v9 + 7) = 0;
    *((_DWORD *)v9 + 8) = 0;
    *((_DWORD *)v9 + 9) = 0;
    *(_DWORD *)v9 = &CAsyncSaveRequest::vftable;
    *((_DWORD *)v9 + 10) = 0;
    *((_DWORD *)v9 + 11) = 0;
    SmartBuffer::SmartBuffer((SmartBuffer *)v9 + 4);
  }
  else
  {
    v10 = 0;
  }
  *((_DWORD *)v10 + 3) = 2;
  *((_QWORD *)v10 + 2) = *qdid;
  *((_DWORD *)v10 + 10) = pack_buf->m_dwOffset;
  *((_DWORD *)v10 + 11) = pack_buf->m_iVersion;
  SmartBuffer::operator=((int)((char *)v10 + 48), (int)&pack_buf->m_buff);
  *((_DWORD *)v10 + 16) = idDestination;
  *((_DWORD *)v10 + 19) = 0;
  *((_DWORD *)v10 + 17) = HIDWORD(idDestination);
  *((_DWORD *)v10 + 18) = 1;
  *((_DWORD *)v10 + 20) = 0;
  if ( pCallbackPlugin )
  {
    v11 = AsyncCache::AllocateCallback(v8, pCallbackPlugin, dwUser1, 1u);
    AsyncCache::CCallbackHandler::AddTopLevelRequest(v11, (AsyncCache::CAsyncRequest *)v10);
    v7 = v11->m_hContext.m_id;
    if ( !InterlockedDecrement((volatile LONG *)&v11->m_cRef) )
      v11->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v11, 1u);
  }
  v8->vfptr->EnqueueAsyncRequest(v8, (AsyncCache::CAsyncRequest *)v10);
  if ( !InterlockedDecrement((volatile LONG *)v10 + 1) )
    (**(void (__thiscall ***)(void *, signed int))v10)(v10, 1);
  v12 = result;
  result->m_id = v7;
  return v12;
}
// 795394: using guessed type int (__thiscall *CAsyncSaveRequest::vftable)(void *, char);

//----- (004198A0) --------------------------------------------------------  // acclient.c:86734
void __thiscall AsyncCache::HashAndEnqueue(AsyncCache *this, CAsyncGetRequest *pGetReq)
{
  CAsyncGetRequest *v2; // esi@1
  AsyncCache *v3; // edi@1
  int v4; // eax@2

  v2 = pGetReq;
  v3 = this;
  if ( HashTable<QualifiedDataID,CAsyncGetRequest *,1>::add(
         (HashTable<QualifiedDataID,CAsyncGetRequest *,1> *)&this->m_PendingGets.vfptr,
         &pGetReq->qdid,
         &pGetReq) )
  {
    InterlockedIncrement((volatile LONG *)&v2->m_cRef);
    v4 = v2->m_dwGetRequestFlags | 1;
    v2->m_dwGetRequestFlags = v4;
    v2->m_dwGetRequestFlags = v4 | 2;
    v3->vfptr->EnqueueAsyncRequest(v3, (AsyncCache::CAsyncRequest *)v2);
  }
}

//----- (004198F0) --------------------------------------------------------  // acclient.c:86756
void __thiscall AsyncCache::UnhashPendingGet(AsyncCache *this, CAsyncGetRequest *pGetReq, CAsyncGetRequest *pParentReq)
{
  unsigned int v3; // edx@1
  unsigned int v4; // eax@1
  AsyncCache *v5; // ebx@1
  CAsyncGetRequest **v6; // edi@2
  CAsyncGetRequest **v7; // ecx@2
  HashSetData<QualifiedDataID> *v8; // eax@12
  unsigned int v9; // edi@13

  v3 = pGetReq->RequestsWaitingForMe.m_num;
  v4 = 0;
  v5 = this;
  if ( v3 )
  {
    v6 = pGetReq->RequestsWaitingForMe.m_data;
    v7 = pGetReq->RequestsWaitingForMe.m_data;
    while ( *v7 != pParentReq )
    {
      ++v4;
      ++v7;
      if ( v4 >= pGetReq->RequestsWaitingForMe.m_num )
        goto LABEL_9;
    }
    if ( v4 < v3 )
    {
      pGetReq->RequestsWaitingForMe.m_num = v3 - 1;
      if ( v4 != v3 - 1 )
      {
        v6[v4] = v6[v3 - 1];
        pGetReq->RequestsWaitingForMe.m_data[pGetReq->RequestsWaitingForMe.m_num] = 0;
      }
    }
  }
LABEL_9:
  if ( pGetReq->m_dwGetRequestFlags & 1 )
  {
    if ( !pGetReq->RequestsWaitingForMe.m_num && !pGetReq->m_pCallbacks.m_num )
    {
      pGetReq->m_dwGetRequestFlags &= 0xFFFFFFFE;
      v8 = IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::remove(
             (IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> *)&v5->m_PendingGets.m_intrusiveTable,
             &pGetReq->qdid);
      if ( v8 )
      {
        operator delete(v8);
        v9 = 0;
        if ( pGetReq->RequestsImWaitingFor.m_num )
        {
          do
            v5->vfptr->UnhashPendingGet(v5, pGetReq->RequestsImWaitingFor.m_data[v9++], pGetReq);
          while ( v9 < pGetReq->RequestsImWaitingFor.m_num );
        }
        if ( !InterlockedDecrement((volatile LONG *)&pGetReq->m_cRef) )
          pGetReq->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)pGetReq, 1u);
      }
    }
  }
}

//----- (004199C0) --------------------------------------------------------  // acclient.c:86817
void __thiscall AsyncCache::ReleaseContext(AsyncCache *this, AsyncContext hContext)
{
  AsyncCache *v2; // ebx@1
  HashSetData<IDClass<_tagDataID,32,0> > *v3; // eax@1
  unsigned int v4; // esi@2
  unsigned int v5; // edi@2
  int v6; // eax@3

  v2 = this;
  v3 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->m_BusyCallbacks.m_intrusiveTable,
         (IDClass<_tagDataID,32,0> *)&hContext);
  if ( v3 )
  {
    v4 = v3[1].m_hashKey.id;
    operator delete(v3);
    v5 = 0;
    if ( *(_DWORD *)(v4 + 32) )
    {
      do
      {
        v6 = *(_DWORD *)(*(_DWORD *)(v4 + 24) + 4 * v5);
        if ( !*(_DWORD *)(v6 + 12) )
          v2->vfptr->UnhashPendingGet(v2, (CAsyncGetRequest *)v6, 0);
        ++v5;
      }
      while ( v5 < *(_DWORD *)(v4 + 32) );
    }
    AsyncCache::CCallbackHandler::OnContextReleased((AsyncCache::CCallbackHandler *)v4);
    if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
}

//----- (00419A40) --------------------------------------------------------  // acclient.c:86852
void __thiscall AsyncCache::FlushPendingRequests(AsyncCache *this)
{
  AsyncCache *v1; // ebx@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // ebp@1
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // esi@1
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v6; // edi@2
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // ebx@7
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v8; // eax@7
  HashTableData<unsigned long,HeritageGroup_CG> *v9; // esi@7
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // ebp@7
  HashTableData<unsigned long,HeritageGroup_CG> **v11; // edi@7
  PSRefBufferCharData<char> *v12; // ebx@8
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v13; // [sp+10h] [bp-10h]@7
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+14h] [bp-Ch]@1

  v1 = this;
  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_BusyCallbacks.m_intrusiveTable,
         &result);
  v3 = v2->m_currHashTable;
  v4 = v2->m_currBucket;
  v5 = v2->m_currElement;
  if ( v5 )
  {
    do
    {
      v6 = v5->m_hashNext;
      if ( !v6 )
      {
        while ( 1 )
        {
          ++v4;
          if ( v4 == &v3->m_buckets[v3->m_numBuckets] )
            break;
          if ( *v4 )
          {
            v6 = *v4;
            break;
          }
        }
      }
      ((void (__thiscall *)(AsyncCache *, _DWORD))v1->vfptr->ReleaseContext)(v1, v5->m_data.vfptr[9].Serialize);
      v5 = v6;
    }
    while ( v6 );
  }
  v7 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v1->m_PendingGets.m_intrusiveTable;
  v13 = v7;
  v8 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(v7, &result);
  v9 = v8->m_currElement;
  v10 = v8->m_currHashTable;
  v11 = v8->m_currBucket;
  if ( v9 )
  {
    do
    {
LABEL_8:
      v12 = v9->m_data.name.m_charbuffer;
      if ( !InterlockedDecrement((volatile LONG *)&v12->m_data[4]) && v12 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))&v12->m_data[0])(v12, 1);
      v9 = (HashTableData<unsigned long,HeritageGroup_CG> *)v9->m_data.vfptr;
    }
    while ( v9 );
    while ( 1 )
    {
      ++v11;
      if ( v11 == &v10->m_buckets[v10->m_numBuckets] )
        break;
      if ( *v11 )
      {
        v9 = *v11;
        if ( *v11 )
          goto LABEL_8;
        break;
      }
    }
    v7 = v13;
  }
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)v7);
}

//----- (00419B10) --------------------------------------------------------  // acclient.c:86936
char __stdcall AsyncCache::IsWaitingFor(CAsyncGetRequest *pGetFrom, CAsyncGetRequest *pGetTo)
{
  unsigned int v3; // ebp@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@3
  CAsyncGetRequest *v6; // ebx@4
  CAsyncGetRequest *v7; // edi@5
  int v8; // eax@6
  int v9; // eax@6
  int v10; // ecx@9
  int v11; // esi@9
  HashSetData<QualifiedDataID> *v12; // eax@9
  unsigned int v13; // eax@15
  unsigned int v14; // edx@16
  char result; // al@32
  SmartArray<CAsyncGetRequest *,1> Queue; // [sp+10h] [bp-88h]@1
  int v22; // [sp+1Ch] [bp-7Ch]@6
  unsigned int v23; // [sp+20h] [bp-78h]@21
  HashSet<QualifiedDataID> Used; // [sp+24h] [bp-74h]@1

  Used.vfptr = (HashSet<QualifiedDataID>Vtbl *)&HashSet<QualifiedDataID>::vftable;
  IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>(
    &Used.m_intrusiveTable,
    0x17u);
  v3 = 0;
  Queue.m_data = 0;
  Queue.m_sizeAndDeallocate = 0;
  Queue.m_num = 0;
  v4 = SmartArray<UIChildFramework *,1>::get_new_size(1u);
  if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&Queue, v4) )
    Queue.m_data[Queue.m_num++] = pGetFrom;
  HashSet<QualifiedDataID>::add(&Used, &pGetFrom->qdid);
  v5 = Queue.m_num;
  if ( Queue.m_num )
  {
    while ( 1 )
    {
      Queue.m_num = v5 - 1;
      v6 = Queue.m_data[v5 - 1];
      Queue.m_data[Queue.m_num] = 0;
      if ( v6->RequestsImWaitingFor.m_num > 0 )
        break;
LABEL_27:
      v5 = Queue.m_num;
      v3 = 0;
      if ( !Queue.m_num )
        goto LABEL_28;
    }
    v7 = pGetTo;
    while ( 1 )
    {
      v8 = (int)&v6->RequestsImWaitingFor.m_data[v3];
      v22 = v8;
      v9 = *(_DWORD *)v8;
      if ( (CAsyncGetRequest *)v9 == v7
        || v7->qdid.Type == *(_DWORD *)(v9 + 16) && v7->qdid.ID.id == *(_DWORD *)(v9 + 20) )
        break;
      v10 = *(_DWORD *)(v9 + 20);
      v11 = *(_DWORD *)(v9 + 16);
      v12 = Used.m_intrusiveTable.m_buckets[(v11 + v10) % Used.m_intrusiveTable.m_numBuckets];
      if ( !v12 )
        goto LABEL_15;
      while ( v12->m_hashKey.Type != v11 || v12->m_hashKey.ID.id != v10 )
      {
        v12 = v12->m_hashNext;
        if ( !v12 )
          goto LABEL_15;
      }
      if ( !v12 )
      {
LABEL_15:
        v13 = Queue.m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( Queue.m_num < (Queue.m_sizeAndDeallocate & 0x7FFFFFFF) )
          goto LABEL_40;
        v14 = v13 + 1;
        if ( v13 + 1 > 8 )
        {
          if ( v14 <= 0x4000 )
          {
            v23 = v13 + 1;
            __asm { bsr     this, [esp+98h+var_78] }
            if ( v14 > 1 << _EAX )
              v14 = 2 * (1 << _EAX);
          }
          else if ( v14 & 0x3FFF )
          {
            v14 += 0x4000 - (v14 & 0x3FFF);
          }
        }
        else
        {
          v14 = 8;
        }
        if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&Queue, v14) )
LABEL_40:
          Queue.m_data[Queue.m_num++] = *(CAsyncGetRequest **)v22;
        HashSet<QualifiedDataID>::add(&Used, &v6->RequestsImWaitingFor.m_data[v3]->qdid);
        v7 = pGetTo;
      }
      ++v3;
      if ( v3 >= v6->RequestsImWaitingFor.m_num )
        goto LABEL_27;
    }
    if ( (Queue.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](Queue.m_data);
    Used.vfptr = (HashSet<QualifiedDataID>Vtbl *)&HashSet<QualifiedDataID>::vftable;
    IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&Used.m_intrusiveTable);
    Used.m_intrusiveTable.vfptr = (IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>Vtbl *)IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vftable;
    if ( (HashSetData<QualifiedDataID> **)Used.m_intrusiveTable.m_buckets != Used.m_intrusiveTable.m_aInplaceBuckets )
      operator delete[](Used.m_intrusiveTable.m_buckets);
    result = 1;
  }
  else
  {
LABEL_28:
    if ( (Queue.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](Queue.m_data);
    Used.vfptr = (HashSet<QualifiedDataID>Vtbl *)&HashSet<QualifiedDataID>::vftable;
    IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&Used.m_intrusiveTable);
    Used.m_intrusiveTable.vfptr = (IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>Vtbl *)IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vftable;
    if ( (HashSetData<QualifiedDataID> **)Used.m_intrusiveTable.m_buckets != Used.m_intrusiveTable.m_aInplaceBuckets )
      operator delete[](Used.m_intrusiveTable.m_buckets);
    result = 0;
  }
  return result;
}
// 794F94: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vftable[4])(void *, char);
// 794FA0: using guessed type int (__thiscall *HashSet<QualifiedDataID>::vftable)(void *, char);

//----- (00419D90) --------------------------------------------------------  // acclient.c:87066
char __thiscall AsyncCache::AddToAsyncGet(AsyncCache *this, unsigned int type, QualifiedDataIDArray *qdids, void *hInternal)
{
  AsyncCache *v4; // edi@1
  DBObjSaveInfo *v6; // ebx@3
  MissingIteration *v7; // eax@8
  MissingIteration *v8; // esi@8
  int v9; // eax@18
  unsigned int v10; // eax@19
  int v11; // eax@22
  unsigned int v12; // eax@23
  DBObjSaveInfo **v13; // eax@31
  DBObjSaveInfo **v14; // ecx@32
  AsyncCache *v15; // [sp+8h] [bp-10h]@1
  IntrusiveHashIterator<QualifiedDataID,DBObjSaveInfo *,1> iter; // [sp+Ch] [bp-Ch]@3

  v4 = this;
  v15 = this;
  if ( *((_DWORD *)hInternal + 3) )
    return 0;
  *((_DWORD *)hInternal + 22) += qdids->m_numElements;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)qdids,
    (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&iter);
  v6 = iter.m_currElement;
  if ( !iter.m_currElement )
    goto LABEL_36;
  while ( 1 )
  {
    if ( v6->m_hashKey.Type == *((_DWORD *)hInternal + 4) && v6->m_hashKey.ID.id == *((_DWORD *)hInternal + 5) )
      goto LABEL_29;
    v7 = AsyncCache::FormGetRequest(v4, (CAsyncGetRequest *)hInternal, type, &v6->m_hashKey);
    v8 = v7;
    if ( v7 == hInternal && v7 )
    {
      if ( !InterlockedDecrement((volatile LONG *)&(&v7->vfptr)[1]) )
        v8->vfptr->Serialize(v8, (Archive *)1);
      v8 = 0;
    }
    if ( AsyncCache::IsWaitingFor((CAsyncGetRequest *)v8, (CAsyncGetRequest *)hInternal) )
    {
      if ( v8 && !InterlockedDecrement((volatile LONG *)&(&v8->vfptr)[1]) )
        v8->vfptr->Serialize(v8, (Archive *)1);
LABEL_29:
      --*((_DWORD *)hInternal + 22);
      goto LABEL_30;
    }
    if ( !v8 )
      goto LABEL_29;
    v9 = *((_DWORD *)hInternal + 15) & 0x7FFFFFFF;
    if ( *((_DWORD *)hInternal + 16) < (unsigned int)v9
      || (v10 = SmartArray<UIChildFramework *,1>::get_new_size(v9 + 1),
          SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)((char *)hInternal + 56), v10)) )
      *(_DWORD *)(*((_DWORD *)hInternal + 14) + 4 * (*((_DWORD *)hInternal + 16))++) = v8;
    if ( (unsigned __int8)((int (__thiscall *)(MissingIteration *))v8->vfptr[1].Serialize)(v8) )
    {
      if ( LODWORD(v8->idDatFile) != 1 )
        *((_DWORD *)hInternal + 2) = 2;
      goto LABEL_29;
    }
    InterlockedIncrement((volatile LONG *)hInternal + 1);
    v11 = (unsigned int)v8[1].vfptr & 0x7FFFFFFF;
    if ( (&v8[1].vfptr)[1] < (MissingIterationVtbl *)v11
      || (v12 = SmartArray<UIChildFramework *,1>::get_new_size(v11 + 1),
          SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v8->IDsToPurge + 1, v12)) )
      *(_DWORD *)(*((_DWORD *)&v8->IDsToPurge + 3) + 4 * (unsigned int)(&v8[1].vfptr)[1]++) = hInternal;
    if ( !((unsigned int)v8[2].vfptr & 1) )
      ((void (__stdcall *)(_DWORD))v15->vfptr->HashAndEnqueue)(v8);
LABEL_30:
    v6 = v6->m_hashNext;
    if ( !v6 )
      break;
LABEL_5:
    v4 = v15;
  }
  v13 = &iter.m_currHashTable->m_buckets[iter.m_currHashTable->m_numBuckets];
  while ( 1 )
  {
    v14 = iter.m_currBucket + 1;
    ++iter.m_currBucket;
    if ( iter.m_currBucket == v13 )
      break;
    if ( *v14 )
    {
      v6 = *v14;
      if ( *v14 )
        goto LABEL_5;
      break;
    }
  }
  v4 = v15;
LABEL_36:
  if ( !*((_DWORD *)hInternal + 22) )
    v4->vfptr->OnAsyncGetFinished(v4, (CAsyncGetRequest *)hInternal);
  return 1;
}

//----- (00419F50) --------------------------------------------------------  // acclient.c:87163
void __thiscall AsyncCache::AsyncCache(AsyncCache *this)
{
  AsyncCache *v1; // esi@1

  v1 = this;
  this->vfptr = (AsyncCacheVtbl *)&AsyncCache::vftable;
  this->m_PendingCallbacks.vfptr = (TDynamicCircularArray<AsyncCache::CCallbackHandler *>Vtbl *)&TDynamicCircularArray<AsyncCache::CCallbackHandler *>::vftable;
  this->m_PendingCallbacks.first = 0;
  this->m_PendingCallbacks.next = 0;
  this->m_PendingCallbacks.count = 0;
  this->m_PendingCallbacks.max = 0;
  this->m_PendingCallbacks.growsize = 256;
  this->m_PendingCallbacks.A = (AsyncCache::CCallbackHandler **)operator new[](0x4000u);
  v1->m_PendingCallbacks.max = 4096;
  v1->m_PendingGets.vfptr = (HashTable<QualifiedDataID,CAsyncGetRequest *,1>Vtbl *)&HashTable<QualifiedDataID,CAsyncGetRequest *,1>::vftable;
  IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>(
    &v1->m_PendingGets.m_intrusiveTable,
    0);
  v1->m_PendingGets.vfptr = (HashTable<QualifiedDataID,CAsyncGetRequest *,1>Vtbl *)&HashTable<QualifiedDataID,CAsyncGetRequest *,1>::vftable;
  v1->m_BusyCallbacks.vfptr = (HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1>Vtbl *)HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1>::vftable;
  IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>(
    &v1->m_BusyCallbacks.m_intrusiveTable,
    0);
  v1->m_BusyCallbacks.vfptr = (HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1>Vtbl *)HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1>::vftable;
  v1->m_bCallingPendingCallbacks = 0;
  v1->dwNextCallbackHandle = 1;
}
// 794F70: using guessed type int (__thiscall *TDynamicCircularArray<AsyncCache::CCallbackHandler *>::vftable)(void *, char);
// 7953A4: using guessed type int (__thiscall *HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1>::vftable[2])(void *, char);
// 7953A8: using guessed type int (__thiscall *HashTable<QualifiedDataID,CAsyncGetRequest *,1>::vftable)(void *, char);
// 7953B0: using guessed type struct DBObj *(__thiscall *AsyncCache::vftable)(AsyncCache *this, unsigned __int32 type, const struct QualifiedDataID *);

//----- (006C49D0) --------------------------------------------------------  // acclient.c:732951
int _E73_14()
{
  return atexit(_E74_17);
}

//----- (006C49E0) --------------------------------------------------------  // acclient.c:732957
int _E76_9()
{
  return atexit(_E77_37);
}

//----- (006C49F0) --------------------------------------------------------  // acclient.c:732963
int _E79_9()
{
  return atexit(_E80_11);
}

//----- (006C4A00) --------------------------------------------------------  // acclient.c:732969
int _E1_9()
{
  return atexit(_E2_9);
}

