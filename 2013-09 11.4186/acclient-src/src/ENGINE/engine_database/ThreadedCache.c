/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ThreadedCache
   Object     : ENGINE\engine_database\ThreadedCache.obj
   Functions  : 21
   Addresses  : 00677550 - 00714F50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00677550) --------------------------------------------------------  // acclient.c:653984
void __thiscall ThreadedCache::WorkerExecuteRequest(ThreadedCache *this, AsyncCache::CAsyncRequest *pReq)
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
        ((void (__stdcall *)(_DWORD))this->vfptr[4].IUnknown_QueryInterface)(pReq);
    }
    else
    {
      this->vfptr[4].IUnknown_AddRef((Interface *)pReq);
    }
  }
  else
  {
    ((void (__stdcall *)(_DWORD))this->vfptr[3].Release)(pReq);
  }
}

//----- (00677580) --------------------------------------------------------  // acclient.c:654010
BOOL __thiscall ThreadedCache::SetShutdown(ThreadedCache *this, bool shut_f)
{
  ((void (*)(void))this->vfptr[3].QueryInterface)();
  return DBCache::KeepFreeObjects(shut_f == 0, 0) == 0;
}

//----- (006775B0) --------------------------------------------------------  // acclient.c:654017
void __thiscall ThreadedCache::StopThread(ThreadedCache *this)
{
  PortalThread *v1; // esi@1

  v1 = (PortalThread *)&this->vfptr;
  this->vfptr->SetShouldExit((PortalThread *)&this->vfptr, 1);
  PortalThread::Join(v1);
}

//----- (006775D0) --------------------------------------------------------  // acclient.c:654027
void __thiscall ThreadedCache::WakeForTheReaper(ThreadedCache *this)
{
  PortalEvent::Signal((PortalEvent *)this->m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets);
}

//----- (006775E0) --------------------------------------------------------  // acclient.c:654033
void __thiscall ThreadedCache::WorkerExecuteGetRequest(ThreadedCache *this, CAsyncGetRequest *pGetReq)
{
  pGetReq->Result = 2
                  * ((unsigned __int8)((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->vfptr->LoadData)(
                                        &this->vfptr,
                                        &pGetReq->qdid,
                                        &pGetReq->Buf,
                                        0,
                                        0) == 0)
                  + 1;
}

//----- (00677610) --------------------------------------------------------  // acclient.c:654046
void __thiscall ThreadedCache::WorkerExecutePurgeRequest(ThreadedCache *this, CAsyncPurgeRequest *pPurgeReq)
{
  pPurgeReq->Result = (unsigned __int8)((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->vfptr->PurgeData)(
                                         &this->vfptr,
                                         &pPurgeReq->qdid,
                                         0,
                                         0) != 0 ? 1 : 3;
}

//----- (00677640) --------------------------------------------------------  // acclient.c:654056
void __thiscall ThreadedCache::WorkerExecuteSaveRequest(ThreadedCache *this, CAsyncSaveRequest *pSaveReq)
{
  DiskController *v2; // eax@1
  int v3; // edx@3
  unsigned int v4; // ecx@3
  BTEntry entry; // [sp+Ch] [bp-18h]@3

  v2 = pSaveReq->pDisk;
  pSaveReq->Result = 3;
  if ( !v2 )
    v2 = (DiskController *)((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->vfptr->GetDiskController)(
                             &this->vfptr,
                             &pSaveReq->qdid,
                             LODWORD(pSaveReq->idTargetDatFile),
                             HIDWORD(pSaveReq->idTargetDatFile));
  v3 = pSaveReq->idIteration;
  entry.GID_.id = pSaveReq->qdid.ID.id;
  v4 = pSaveReq->Buf.m_iVersion << 16;
  entry.Offset_ = 0;
  entry.size_ = 0;
  entry.date_ = 0;
  entry.iter_ = v3;
  entry = (BTEntry)v4;
  if ( v2 )
  {
    if ( (unsigned __int8)((int (__thiscall *)(DiskController *, BTEntry *, Cache_Pack_t *, unsigned int))v2->vfptr[1].HowmuchFreeSpace)(
                            v2,
                            &entry,
                            &pSaveReq->Buf,
                            pSaveReq->dwDiskControllerSaveFlags) )
      pSaveReq->Result = 1;
  }
}

//----- (006776D0) --------------------------------------------------------  // acclient.c:654091
void __thiscall LFQueue<AsyncCache::CAsyncRequest *>::Produce(LFQueue<AsyncCache::CAsyncRequest *> *this, AsyncCache::CAsyncRequest *toAdd)
{
  LFQueue<AsyncCache::CAsyncRequest *> *v2; // esi@1
  volatile int v3; // eax@1
  int v4; // eax@2
  bool v5; // bl@4
  ListNode<AsyncCache::CAsyncRequest *> *v6; // eax@6
  ListNode<AsyncCache::CAsyncRequest *> *v7; // ecx@7
  AsyncCache::CAsyncRequest *v8; // ebp@10
  AsyncCache::CAsyncRequest **v9; // ecx@10
  volatile int v10; // eax@10
  int v11; // eax@11
  volatile int v12; // eax@13
  void *v13; // eax@18
  volatile int v14; // eax@22
  ListNode<AsyncCache::CAsyncRequest *> *v15; // ecx@25

  v2 = this;
  v3 = this->m_dwProducerBucketIndex;
  if ( v3 == this->numBuckets_ - 1 )
    v4 = 0;
  else
    v4 = v3 + 1;
  v5 = v4 != this->m_dwConsumerBucketIndex;
  if ( v4 == this->m_dwConsumerBucketIndex )
    goto LABEL_18;
  while ( v2->m_backupList._head )
  {
    v2->m_backupListCritSec.vfptr->EnterCriticalSection(&v2->m_backupListCritSec);
    v6 = v2->m_backupList._head;
    if ( v6 )
    {
      v7 = v6->next;
      v2->m_backupList._head = v7;
      if ( v7 )
        v7->prev = 0;
      else
        v2->m_backupList._tail = 0;
      v8 = v6->data;
      operator delete(v6);
      --v2->m_backupList._num_elements;
      v9 = v2->buckets_;
      --v2->m_dwBackupListLen;
      v9[v2->m_dwProducerBucketIndex] = v8;
      v10 = v2->m_dwProducerBucketIndex;
      if ( v10 == v2->numBuckets_ - 1 )
        v11 = 0;
      else
        v11 = v10 + 1;
      v2->m_dwProducerBucketIndex = v11;
      SharedCriticalSection::LeaveCriticalSection(&v2->m_backupListCritSec);
      v12 = v2->m_dwProducerBucketIndex;
      if ( v12 == v2->numBuckets_ - 1 )
        v5 = v2->m_dwConsumerBucketIndex != 0;
      else
        v5 = v12 + 1 != v2->m_dwConsumerBucketIndex;
    }
    else
    {
      SharedCriticalSection::LeaveCriticalSection(&v2->m_backupListCritSec);
    }
    if ( !v5 )
      goto LABEL_18;
  }
  if ( v5 )
  {
    v2->buckets_[v2->m_dwProducerBucketIndex] = toAdd;
    v14 = v2->m_dwProducerBucketIndex;
    if ( v14 == v2->numBuckets_ - 1 )
      v2->m_dwProducerBucketIndex = 0;
    else
      v2->m_dwProducerBucketIndex = v14 + 1;
  }
  else
  {
LABEL_18:
    v2->m_backupListCritSec.vfptr->EnterCriticalSection(&v2->m_backupListCritSec);
    v13 = operator new(0xCu);
    if ( v13 )
    {
      *(_DWORD *)v13 = toAdd;
      *((_DWORD *)v13 + 1) = 0;
      *((_DWORD *)v13 + 2) = 0;
      if ( v2->m_backupList._head )
      {
        v15 = v2->m_backupList._tail;
        v15->next = (ListNode<AsyncCache::CAsyncRequest *> *)v13;
        *((_DWORD *)v13 + 2) = v15;
      }
      else
      {
        v2->m_backupList._head = (ListNode<AsyncCache::CAsyncRequest *> *)v13;
      }
      v2->m_backupList._tail = (ListNode<AsyncCache::CAsyncRequest *> *)v13;
      ++v2->m_backupList._num_elements;
    }
    ++v2->m_dwBackupListLen;
    SharedCriticalSection::LeaveCriticalSection(&v2->m_backupListCritSec);
  }
}

//----- (00677830) --------------------------------------------------------  // acclient.c:654193
char __thiscall LFQueue<AsyncCache::CAsyncRequest *>::Consume(LFQueue<AsyncCache::CAsyncRequest *> *this, AsyncCache::CAsyncRequest **retVal)
{
  LFQueue<AsyncCache::CAsyncRequest *> *v2; // esi@1
  volatile int v3; // eax@2
  char result; // al@3
  volatile int v5; // eax@10

  v2 = this;
  if ( this->m_dwProducerBucketIndex == this->m_dwConsumerBucketIndex )
  {
    if ( this->m_backupList._head )
    {
      this->m_backupListCritSec.vfptr->EnterCriticalSection(&this->m_backupListCritSec);
      if ( v2->m_dwProducerBucketIndex == v2->m_dwConsumerBucketIndex
        && List<NoticeHandler *>::pop_front((List<NoticeHandler *> *)&v2->m_backupList, (NoticeHandler **)retVal) )
      {
        --v2->m_dwBackupListLen;
        SharedCriticalSection::LeaveCriticalSection(&v2->m_backupListCritSec);
        result = 1;
      }
      else
      {
        *retVal = v2->buckets_[v2->m_dwConsumerBucketIndex];
        v5 = v2->m_dwConsumerBucketIndex;
        if ( v5 == v2->numBuckets_ - 1 )
        {
          v2->m_dwConsumerBucketIndex = 0;
          SharedCriticalSection::LeaveCriticalSection(&v2->m_backupListCritSec);
          result = 1;
        }
        else
        {
          v2->m_dwConsumerBucketIndex = v5 + 1;
          SharedCriticalSection::LeaveCriticalSection(&v2->m_backupListCritSec);
          result = 1;
        }
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    *retVal = this->buckets_[this->m_dwConsumerBucketIndex];
    v3 = this->m_dwConsumerBucketIndex;
    if ( v3 == this->numBuckets_ - 1 )
    {
      this->m_dwConsumerBucketIndex = 0;
      result = 1;
    }
    else
    {
      this->m_dwConsumerBucketIndex = v3 + 1;
      result = 1;
    }
  }
  return result;
}

//----- (00677900) --------------------------------------------------------  // acclient.c:654255
int __thiscall ThreadedCache::Startup(ThreadedCache *this)
{
  ThreadedCache *v1; // esi@1
  char i; // al@1
  AsyncCache::CAsyncRequest *v3; // edi@4
  AsyncCache::CAsyncRequest *pReq; // [sp+0h] [bp-4h]@1

  pReq = (AsyncCache::CAsyncRequest *)this;
  v1 = this;
  for ( i = BYTE1(this->m_PendingCallbacks.A); !i; i = BYTE1(v1->m_PendingCallbacks.A) )
  {
    pReq = 0;
    if ( !i )
    {
      do
      {
        if ( !LFQueue<AsyncCache::CAsyncRequest *>::Consume(
                (LFQueue<AsyncCache::CAsyncRequest *> *)&v1->m_PendingCallbacks.first,
                &pReq) )
          break;
        v3 = pReq;
        pReq->Result = 3;
        ((void (__stdcall *)(AsyncCache::CAsyncRequest *))v1[-1].m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets[1][7].m_hashNext)(v3);
        LFQueue<AsyncCache::CAsyncRequest *>::Produce(
          (LFQueue<AsyncCache::CAsyncRequest *> *)&v1->m_PendingGets.m_intrusiveTable.m_aInplaceBuckets[11],
          v3);
      }
      while ( !BYTE1(v1->m_PendingCallbacks.A) );
    }
    PortalEvent::WaitForSignal((PortalEvent *)v1->m_BusyCallbacks.m_intrusiveTable.m_aInplaceBuckets, 0xFFFFFFFF);
  }
  return 0;
}

//----- (00677980) --------------------------------------------------------  // acclient.c:654290
void __thiscall ThreadedCache::PutOnWorkerThreadJobQueue(ThreadedCache *this, AsyncCache::CAsyncRequest *pReq)
{
  ThreadedCache *v2; // esi@1

  v2 = this;
  InterlockedIncrement((volatile LONG *)&pReq->m_cRef);
  LFQueue<AsyncCache::CAsyncRequest *>::Produce(&v2->m_WorkerThreadJobQueue, pReq);
  PortalEvent::Signal(&v2->m_evtWorkerHasJobs);
}

//----- (006779B0) --------------------------------------------------------  // acclient.c:654301
void __thiscall ThreadedCache::UseTime(ThreadedCache *this)
{
  DBCache *v1; // edi@1
  DWORD v2; // ebp@1
  AsyncCache::CAsyncRequest *v3; // esi@3
  AsyncCache::CAsyncRequest *pReq; // [sp+Ch] [bp-4h]@1

  v1 = (DBCache *)this;
  v2 = GetTickCount();
  pReq = 0;
  while ( GetTickCount() - v2 < 0x19 )
  {
    if ( !LFQueue<AsyncCache::CAsyncRequest *>::Consume(
            (LFQueue<AsyncCache::CAsyncRequest *> *)&v1[1].m_PendingGets.m_intrusiveTable.m_aInplaceBuckets[10],
            &pReq) )
      break;
    v3 = pReq;
    ((void (__thiscall *)(DBCache *, AsyncCache::CAsyncRequest *))v1->vfptr[3].Release)(v1, pReq);
    if ( v3 )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
        v3->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 1u);
      pReq = 0;
    }
  }
  DBCache::UseTime(v1);
}

//----- (00677A30) --------------------------------------------------------  // acclient.c:654330
void __thiscall ThreadedCache::AsyncGetInternal(ThreadedCache *this, CAsyncGetRequest *pReq)
{
  ThreadedCache *v2; // ebp@1
  char *v3; // edi@1
  char *v4; // ebx@1
  DBObj *v5; // eax@1
  unsigned int v6; // edx@1

  v2 = this;
  v3 = (char *)&this->vfptr;
  v4 = (char *)&pReq->qdid;
  v5 = this->vfptr->GetIfInMemory((AsyncCache *)&this->vfptr, &pReq->qdid, pReq->pObjCache);
  v6 = pReq->m_dwGetRequestFlags;
  if ( v5 )
  {
    pReq->m_dwGetRequestFlags = v6 | 4;
    AsyncCache::CAsyncRequest::AdoptDBObj((AsyncCache::CAsyncRequest *)&pReq->vfptr, v5);
    pReq->Result = 1;
    (*(void (__thiscall **)(char *, CAsyncGetRequest *))(*(_DWORD *)v3 + 96))(v3, pReq);
  }
  else
  {
    pReq->m_dwGetRequestFlags = v6 & 0xFFFFFFFB;
    if ( (unsigned __int8)((int (*)(void))pReq->pObjCache->vfptr->CanLoadFromDisk)()
      && (unsigned __int8)(*(int (__thiscall **)(char *, char *))(*(_DWORD *)v3 + 60))(v3, v4) )
    {
      ThreadedCache::PutOnWorkerThreadJobQueue(v2, (AsyncCache::CAsyncRequest *)&pReq->vfptr);
    }
    else if ( (unsigned __int8)((int (*)(void))pReq->pObjCache->vfptr->CanRequestFromNet)()
           && (unsigned __int8)(*(int (__thiscall **)(char *, char *, DBOCache *))(*(_DWORD *)v3 + 140))(
                                 v3,
                                 v4,
                                 pReq->pObjCache) )
    {
      pReq->m_dwGetRequestFlags &= 0xFFFFFFFD;
    }
    else
    {
      pReq->Result = 3;
      (*(void (__thiscall **)(char *, CAsyncGetRequest *))(*(_DWORD *)v3 + 92))(v3, pReq);
    }
  }
}

//----- (00677AF0) --------------------------------------------------------  // acclient.c:654375
void __thiscall ThreadedCache::ThreadedCache(ThreadedCache *this)
{
  ThreadedCache *v1; // esi@1

  v1 = this;
  DBCache::DBCache((DBCache *)&this->vfptr);
  PortalThread::PortalThread((PortalThread *)&v1->vfptr, 0);
  v1->vfptr = (PortalThreadVtbl *)&ThreadedCache::vftable;
  v1->vfptr = (InterfaceVtbl *)&ThreadedCache::vftable;
  v1->vfptr = (AsyncCacheVtbl *)&ThreadedCache::vftable;
  v1->m_WorkerThreadJobQueue.m_dwProducerBucketIndex = 0;
  v1->m_WorkerThreadJobQueue.m_dwConsumerBucketIndex = 0;
  v1->m_WorkerThreadJobQueue.buckets_ = 0;
  v1->m_WorkerThreadJobQueue.numBuckets_ = 1024;
  v1->m_WorkerThreadJobQueue.m_backupList.vfptr = (List<AsyncCache::CAsyncRequest *>Vtbl *)&List<AsyncCache::CAsyncRequest *>::vftable;
  v1->m_WorkerThreadJobQueue.m_backupList._head = 0;
  v1->m_WorkerThreadJobQueue.m_backupList._tail = 0;
  v1->m_WorkerThreadJobQueue.m_backupList._num_elements = 0;
  v1->m_WorkerThreadJobQueue.m_dwBackupListLen = 0;
  SharedCriticalSection::SharedCriticalSection(&v1->m_WorkerThreadJobQueue.m_backupListCritSec);
  v1->m_WorkerThreadJobQueue.buckets_ = (AsyncCache::CAsyncRequest **)operator new[](4 * v1->m_WorkerThreadJobQueue.numBuckets_);
  v1->m_WorkerThreadReplyQueue.m_dwProducerBucketIndex = 0;
  v1->m_WorkerThreadReplyQueue.buckets_ = 0;
  v1->m_WorkerThreadReplyQueue.numBuckets_ = 1024;
  v1->m_WorkerThreadReplyQueue.m_dwConsumerBucketIndex = 0;
  v1->m_WorkerThreadReplyQueue.m_backupList.vfptr = (List<AsyncCache::CAsyncRequest *>Vtbl *)&List<AsyncCache::CAsyncRequest *>::vftable;
  v1->m_WorkerThreadReplyQueue.m_backupList._head = 0;
  v1->m_WorkerThreadReplyQueue.m_backupList._tail = 0;
  v1->m_WorkerThreadReplyQueue.m_backupList._num_elements = 0;
  v1->m_WorkerThreadReplyQueue.m_dwBackupListLen = 0;
  SharedCriticalSection::SharedCriticalSection(&v1->m_WorkerThreadReplyQueue.m_backupListCritSec);
  v1->m_WorkerThreadReplyQueue.buckets_ = (AsyncCache::CAsyncRequest **)operator new[](4 * v1->m_WorkerThreadReplyQueue.numBuckets_);
  PortalEvent::PortalEvent(&v1->m_evtWorkerHasJobs);
}
// 7C5AD8: using guessed type int (__thiscall *List<AsyncCache::CAsyncRequest *>::vftable)(void *, char);
// 7FE008: using guessed type struct DBObj *(__thiscall *ThreadedCache::vftable)(AsyncCache *this, unsigned __int32 type, const struct QualifiedDataID *);
// 7FE0B0: using guessed type __int32 (__stdcall *ThreadedCache::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7FE118: using guessed type void *ThreadedCache::vftable;

//----- (00677BF0) --------------------------------------------------------  // acclient.c:654415
ThreadedCache *__thiscall ThreadedCache::vector_deleting_destructor(ThreadedCache *this, unsigned int a2)
{
  return ThreadedCache::vector_deleting_destructor((ThreadedCache *)((char *)this - 304), a2);
}

//----- (00677C00) --------------------------------------------------------  // acclient.c:654421
void __thiscall ThreadedCache::EnqueueAsyncRequest(ThreadedCache *this, AsyncCache::CAsyncRequest *pReq)
{
  ThreadedCache *v2; // esi@1

  v2 = this;
  if ( pReq->Op )
  {
    InterlockedIncrement((volatile LONG *)&pReq->m_cRef);
    LFQueue<AsyncCache::CAsyncRequest *>::Produce((LFQueue<AsyncCache::CAsyncRequest *> *)&v2->m_fThreadRunning, pReq);
    PortalEvent::Signal((PortalEvent *)&v2->m_WorkerThreadReplyQueue.m_backupListCritSec.lockCount_);
  }
  else
  {
    ThreadedCache::AsyncGetInternal((ThreadedCache *)((char *)this - 4), (CAsyncGetRequest *)pReq);
  }
}

//----- (00677C50) --------------------------------------------------------  // acclient.c:654439
ThreadedCache *__thiscall ThreadedCache::vector_deleting_destructor(ThreadedCache *this, unsigned int a2)
{
  ThreadedCache *v2; // esi@1

  v2 = this;
  ThreadedCache::~ThreadedCache(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00714F20) --------------------------------------------------------  // acclient.c:807853
int sub_714F20()
{
  return atexit(nullsub_114);
}

//----- (00714F30) --------------------------------------------------------  // acclient.c:807859
int _E76_92()
{
  return atexit(nullsub_115);
}

//----- (00714F40) --------------------------------------------------------  // acclient.c:807865
int _E79_87()
{
  return atexit(_E80_84);
}

//----- (00714F50) --------------------------------------------------------  // acclient.c:807871
int sub_714F50()
{
  return atexit(nullsub_113);
}

