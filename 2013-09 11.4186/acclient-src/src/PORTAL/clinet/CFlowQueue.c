/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CFlowQueue
   Object     : PORTAL\clinet\CFlowQueue.obj
   Functions  : 51
   Addresses  : 004537C0 - 00705670 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004537C0) --------------------------------------------------------  // acclient.c:144644
void __thiscall NIList<NetBlob *>::AddToTail(NIList<unsigned long> *this, unsigned int inData)
{
  NIList<unsigned long> *v2; // esi@1
  void *v3; // eax@1
  NIListElement<unsigned long> *v4; // ecx@4

  v2 = this;
  v3 = operator new(8u);
  if ( v3 )
  {
    *(_DWORD *)v3 = inData;
    *((_DWORD *)v3 + 1) = 0;
  }
  else
  {
    v3 = 0;
  }
  v4 = v2->tail_;
  if ( v4 )
  {
    v4->next_ = (NIListElement<unsigned long> *)v3;
    v2->tail_ = v2->tail_->next_;
  }
  else
  {
    v2->head_ = (NIListElement<unsigned long> *)v3;
    v2->tail_ = (NIListElement<unsigned long> *)v3;
  }
}

//----- (00547070) --------------------------------------------------------  // acclient.c:374430
NetPacket *__thiscall FlowQueue::DequeuePacket(FlowQueue *this, NetPacket **head, NetPacket **tail)
{
  NetPacket *v3; // esi@1

  v3 = *head;
  if ( *head )
  {
    ((void (__stdcall *)(unsigned int))this->vfptr->RecordBytesDequeued)(v3->size_);
    *head = (*head)->next_;
    NetPacket::Remove(v3, 0, head, tail);
  }
  return v3;
}

//----- (005470B0) --------------------------------------------------------  // acclient.c:374445
void __thiscall FlowQueue::EncryptChecksum(FlowQueue *this, NetPacket *packet, unsigned int seqnum, unsigned int *pKey)
{
  ReceiverData *v4; // ecx@1
  NetPacket *v5; // esi@1
  unsigned int v6; // eax@1

  v4 = this->myReceiverData_;
  v5 = packet;
  packet = (NetPacket *)packet->checksum_;
  v6 = ReceiverData::Encrypt(v4, seqnum, (char *)&packet, 4u, pKey);
  v5->checksum_ = (unsigned int)packet;
  v5->flags_ |= 1u;
  v5->cryptoKey_ = v6;
}

//----- (00547100) --------------------------------------------------------  // acclient.c:374461
void __thiscall FlowQueue::IncrementLocalInterval(FlowQueue *this, unsigned int cIntervals)
{
  this->CurLocalInterval_.intervalID_ += cIntervals;
}

//----- (00547110) --------------------------------------------------------  // acclient.c:374467
void __thiscall ClientFlowQueue::RecordBytesSent(ClientFlowQueue *this, int dataAmount)
{
  this->CurLocalInterval_.nBytes_ += dataAmount;
}

//----- (00547130) --------------------------------------------------------  // acclient.c:374473
void __thiscall NIListIter<unsigned long>::RemoveCur(NIListIter<unsigned long> *this)
{
  NIListIter<unsigned long> *v1; // esi@1
  NIListElement<unsigned long> *v2; // eax@1
  NIList<unsigned long> *v3; // esi@2
  NIListElement<unsigned long> *v4; // ecx@2
  NIListElement<unsigned long> *v5; // eax@3
  NIListElement<unsigned long> *v6; // eax@6

  v1 = this;
  v2 = this->prev_;
  if ( v2 )
  {
    v2->next_ = this->cur_->next_;
    v6 = this->prev_;
    if ( !v6->next_ )
      this->list_->tail_ = v6;
    operator delete(this->cur_);
    v1->cur_ = v1->prev_->next_;
  }
  else
  {
    this->cur_ = this->cur_->next_;
    v3 = this->list_;
    v4 = v3->head_;
    if ( v3->head_ )
    {
      v5 = v4->next_;
      v3->head_ = v5;
      if ( !v5 )
        v3->tail_ = 0;
      operator delete(v4);
    }
  }
}

//----- (005471A0) --------------------------------------------------------  // acclient.c:374510
PQueueArray<unsigned long,void *> *__thiscall PQueueArray<unsigned long,void *>::scalar_deleting_destructor(PQueueArray<unsigned long,void *> *this, unsigned int a2)
{
  PQueueArray<unsigned long,void *> *v2; // esi@1
  PQueueArray<unsigned long,void *>::PQueueNode *v3; // ST00_4@1

  v2 = this;
  v3 = this->A;
  this->vfptr = (PQueueArray<unsigned long,void *>Vtbl *)PQueueArray<unsigned long,void *>::vftable;
  operator delete[](v3);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7CA4E8: using guessed type int (__thiscall *PQueueArray<unsigned long,void *>::vftable[2])(void *, char);

//----- (005471D0) --------------------------------------------------------  // acclient.c:374526
void __thiscall PQueueArray<unsigned long,void *>::_ExpandNodes(PQueueArray<unsigned long,void *> *this)
{
  PQueueArray<unsigned long,void *> *v1; // ebx@1
  void *v2; // ebp@1
  void *v3; // ST00_4@1

  v1 = this;
  v2 = operator new[](16 * this->allocatedNodes);
  qmemcpy(v2, v1->A, 8 * v1->allocatedNodes);
  v3 = v1->A;
  v1->allocatedNodes *= 2;
  operator delete[](v3);
  v1->A = (PQueueArray<unsigned long,void *>::PQueueNode *)v2;
}

//----- (00547220) --------------------------------------------------------  // acclient.c:374542
void __thiscall PQueueArray<unsigned long,void *>::_Heapify(PQueueArray<unsigned long,void *> *this, int root)
{
  int v2; // edx@1
  PQueueArray<unsigned long,void *>::PQueueNode *v3; // eax@1
  int v4; // ebx@2
  int v5; // esi@2
  int v6; // edi@2
  unsigned int v7; // edi@9
  void *v8; // ebx@9

  v2 = root;
  v3 = this->A - 1;
  while ( 1 )
  {
    v4 = this->curNumNodes;
    v5 = 2 * v2;
    v6 = 2 * v2 + 1;
    if ( 2 * v2 > v4 || v3[2 * v2].key >= v3[v2].key )
      v5 = v2;
    if ( v6 <= v4 && v3[v6].key < v3[v5].key )
      v5 = 2 * v2 + 1;
    if ( v5 == v2 )
      break;
    v7 = v3[v2].key;
    v8 = v3[v2].data;
    v3[v2].key = v3[v5].key;
    v3[v2].data = v3[v5].data;
    v3[v5].key = v7;
    v3[v5].data = v8;
    v2 = v5;
  }
}

//----- (00547290) --------------------------------------------------------  // acclient.c:374576
void __thiscall CTimeSyncHeader::UpdateTimeSensitivePayload(CTimeSyncHeader *this)
{
  this->m_time = Timer::compute_time();
}

//----- (005472A0) --------------------------------------------------------  // acclient.c:374582
void __thiscall CEchoRequestHeader::UpdateTimeSensitivePayload(CEchoRequestHeader *this)
{
  this->m_LocalTime = Timer::local_time;
}

//----- (005472B0) --------------------------------------------------------  // acclient.c:374588
void __cdecl FlowQueue::SharedStaticCleanup()
{
  PerfMonCounter<unsigned __int64> *v0; // esi@1

  v0 = FlowQueue::m_pBlobsDequeuedCounter;
  if ( FlowQueue::m_pBlobsDequeuedCounter )
  {
    if ( !InterlockedDecrement((volatile LONG *)&FlowQueue::m_pBlobsDequeuedCounter->m_cRef) )
    {
      if ( v0 )
        v0->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v0, 1u);
    }
    FlowQueue::m_pBlobsDequeuedCounter = 0;
  }
}

//----- (005472F0) --------------------------------------------------------  // acclient.c:374605
NetPacket *__thiscall FlowQueue::DequeueAck(FlowQueue *this)
{
  FlowQueue *v1; // esi@1
  NIListElement<unsigned long> *v2; // eax@1
  unsigned int v3; // ebx@3
  NetPacket *v4; // eax@5
  NetPacket *v5; // edi@5
  int v6; // eax@5
  NIListElement<unsigned long> *v8; // ecx@14
  NIListElement<unsigned long> *v9; // eax@15
  unsigned int key; // [sp+4h] [bp-4h]@1

  key = (unsigned int)this;
  v1 = this;
  v2 = this->m_ackList.head_;
  if ( !v2 )
    return 0;
  if ( v2 )
    v3 = v2->data_;
  else
    v3 = 0;
  v4 = SentPacketStore::GenerateAck(&this->m_sentPacketStore, v3);
  v5 = v4;
  v6 = v4->size_;
  if ( v6 )
  {
    if ( !v1->vfptr->WireRoomLeft(v1, v6) )
    {
      ReferenceCountTemplate<1048576,0>::Release((ReferenceCountTemplate<1048576,0> *)&v5->vfptr);
      return 0;
    }
    NetPacket::UpdateTimeSensitiveHeaders(v5);
    if ( !v5->checksum_ )
      NetPacket::ComputeChecksum(v5);
    if ( !(v5->flags_ & 1) && (v5->flags_ >> 2) & 1 )
    {
      key = v5->cryptoKey_;
      FlowQueue::EncryptChecksum(v1, v5, v3, &key);
    }
  }
  v8 = v1->m_ackList.head_;
  if ( v8 )
  {
    v9 = v8->next_;
    v1->m_ackList.head_ = v9;
    if ( !v9 )
      v1->m_ackList.tail_ = 0;
    operator delete(v8);
  }
  return v5;
}

//----- (005473B0) --------------------------------------------------------  // acclient.c:374658
void __thiscall FlowQueue::EnqueuePacket(FlowQueue *this, NetPacket *packet, NetPacket **head, NetPacket **tail)
{
  FlowQueue *v4; // edi@1

  v4 = this;
  if ( packet )
  {
    InterlockedIncrement((volatile LONG *)&packet->m_cRef);
    if ( packet->numSpecialFrags_ )
    {
      NetPacket::AddToHead(packet, head, tail);
      v4->vfptr->RecordBytesQueued(v4, packet->size_);
    }
    else
    {
      NetPacket::AddToTail(packet, head, tail);
      v4->vfptr->RecordBytesQueued(v4, packet->size_);
    }
  }
}

//----- (00547420) --------------------------------------------------------  // acclient.c:374680
void __thiscall PQueueArray<unsigned long,void *>::Insert(PQueueArray<unsigned long,void *> *this, unsigned int key, void *data)
{
  PQueueArray<unsigned long,void *> *v3; // esi@1
  int v4; // eax@3
  signed int v5; // ecx@3
  bool v6; // sf@3
  signed int v7; // edx@4
  unsigned int v8; // edi@4

  v3 = this;
  if ( this->curNumNodes == this->allocatedNodes )
    PQueueArray<unsigned long,void *>::_ExpandNodes(this);
  v4 = (int)&v3->A[-1];
  v5 = v3->curNumNodes + 1;
  v6 = v3->curNumNodes < 0;
  v3->curNumNodes = v5;
  if ( !((unsigned __int8)(v6 ^ __OFSUB__(v5, 1)) | (v5 == 1)) )
  {
    do
    {
      v7 = v5 >> 1;
      v8 = *(_DWORD *)(v4 + 8 * (v5 >> 1));
      if ( v8 <= key )
        break;
      *(_DWORD *)(v4 + 8 * v5) = v8;
      *(_DWORD *)(v4 + 8 * v5 + 4) = *(_DWORD *)(v4 + 8 * v7 + 4);
      v5 >>= 1;
    }
    while ( v7 > 1 );
  }
  *(_DWORD *)(v4 + 8 * v5) = key;
  *(_DWORD *)(v4 + 8 * v5 + 4) = data;
}

//----- (00547480) --------------------------------------------------------  // acclient.c:374715
char __thiscall PQueueArray<unsigned long,void *>::RemoveMin(PQueueArray<unsigned long,void *> *this, unsigned int *key, void **data)
{
  unsigned int *v3; // eax@2
  int v4; // eax@3
  int v5; // edx@4
  PQueueArray<unsigned long,void *>::PQueueNode *v6; // eax@4
  char result; // al@4

  if ( this->curNumNodes > 0 && (v3 = &this->A->key) != 0 )
  {
    *key = *v3;
    *data = this->A->data;
    v4 = this->curNumNodes;
    if ( v4 <= 1 )
    {
      this->curNumNodes = 0;
      PQueueArray<unsigned long,void *>::_Heapify(this, 1);
      result = 1;
    }
    else
    {
      v5 = v4 - 1;
      v6 = this->A;
      this->curNumNodes = v5;
      v6->key = v6[v5].key;
      v6->data = v6[v5].data;
      PQueueArray<unsigned long,void *>::_Heapify(this, 1);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005474F0) --------------------------------------------------------  // acclient.c:374753
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0> *v2; // esi@1
  HashTableData<unsigned long,int> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>::vftable;
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
// 7CA4FC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>::vftable[2])(void *, char);

//----- (00547530) --------------------------------------------------------  // acclient.c:374774
CPackObjHeader<NetError,2097152,2> *__thiscall CPackObjHeader<NetError,2097152,2>::scalar_deleting_destructor(CPackObjHeader<NetError,2097152,2> *this, unsigned int a2)
{
  CPackObjHeader<NetError,2097152,2> *v2; // esi@1
  char *v3; // ST00_4@1

  v2 = this;
  v3 = this->m_pAdoptedData;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CPackObjHeader<NetError,2097152,2>::vftable;
  operator delete(v3);
  v2->m_pAdoptedData = 0;
  v2->m_Obj.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 7CA500: using guessed type int (__thiscall *CPackObjHeader<NetError,2097152,2>::vftable)(void *, char);

//----- (00547570) --------------------------------------------------------  // acclient.c:374795
void __thiscall CSeqIDListHeader<8192,33>::CSeqIDListHeader<8192,33>(CSeqIDListHeader<8192,33> *this, unsigned int *IDs, unsigned int nIDs)
{
  this->m_IDs[0] = nIDs;
  this->m_pData = (char *)this->m_IDs;
  this->m_cbData = 4 * nIDs + 4;
  this->m_cRef = 1;
  this->m_dwMask = 0x2000;
  this->m_Flags = 33;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
  qmemcpy(&this->m_IDs[1], IDs, 4 * (4 * nIDs >> 2));
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005475D0) --------------------------------------------------------  // acclient.c:374809
COptionalHeader *__cdecl CTimeSyncHeader::CreateFromData(long double time)
{
  COptionalHeader *result; // eax@1
  COptionalHeader *v2; // ecx@2

  result = (COptionalHeader *)operator new(0x20u);
  if ( result )
  {
    v2 = result + 1;
    v2->m_cRef = HIDWORD(time);
    result->m_cRef = 1;
    result->m_dwMask = 0x1000000;
    result->m_Flags = 24;
    result->m_pData = (char *)&result[1];
    result->m_cbData = 8;
    result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CTimeSyncHeader::vftable;
    v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)LODWORD(time);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7CA4EC: using guessed type int (__thiscall *CTimeSyncHeader::vftable)(void *, char);

//----- (00547620) --------------------------------------------------------  // acclient.c:374836
COptionalHeader *__cdecl CEchoRequestHeader::CreateFromData()
{
  COptionalHeader *result; // eax@1

  result = (COptionalHeader *)operator new(0x1Cu);
  if ( result )
  {
    *(float *)&result[1].vfptr = Timer::local_time;
    result->m_cRef = 1;
    result->m_dwMask = 0x2000000;
    result->m_Flags = 24;
    result->m_pData = (char *)&result[1];
    result->m_cbData = 4;
    result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CEchoRequestHeader::vftable;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7CA4F4: using guessed type int (__thiscall *CEchoRequestHeader::vftable)(void *, char);

//----- (00547670) --------------------------------------------------------  // acclient.c:374860
void __thiscall FlowQueue::EnqueueOptionalHeader(FlowQueue *this, COptionalHeader *newFrag)
{
  FlowQueue *v2; // edi@1
  RecipientData *v3; // ST04_4@1
  PacketController *v4; // eax@1

  v2 = this;
  InterlockedIncrement((volatile LONG *)&newFrag->m_cRef);
  PQueueArray<unsigned long,void *>::Insert(&v2->pqueueSpecial_, newFrag->m_dwMask, newFrag);
  v3 = v2->myRecip_;
  v4 = PacketController::Instance();
  PacketController::EnqueueRecip(v4, v3);
  if ( newFrag->m_Flags & 0x40 )
    RecipientData::TouchConnection(v2->myRecip_);
}

//----- (005476C0) --------------------------------------------------------  // acclient.c:374877
void __thiscall FlowQueue::FlushSentPackets(FlowQueue *this, unsigned int id, int fEverything)
{
  FlowQueue *v3; // esi@1
  NIListElement<unsigned long> *v4; // eax@3
  unsigned int v5; // ecx@4
  unsigned int v6; // eax@7
  int v7; // edx@7
  NIListElement<unsigned long> *v8; // ecx@12
  NIListElement<unsigned long> *v9; // eax@13

  v3 = this;
  while ( v3->m_ackList.head_ )
  {
    if ( !fEverything )
    {
      v4 = v3->m_ackList.head_;
      v5 = v4 ? v4->data_ : 0;
      if ( v5 == id )
        break;
      v6 = v5 - id;
      v7 = 1;
      if ( v5 < id )
      {
        v6 = id - v5;
        v7 = -1;
      }
      if ( v6 > 0x7FFFFFFF )
        v7 = -v7;
      if ( v7 >= 0 )
        break;
    }
    v8 = v3->m_ackList.head_;
    if ( v8 )
    {
      v9 = v8->next_;
      v3->m_ackList.head_ = v9;
      if ( !v9 )
        v3->m_ackList.tail_ = 0;
      operator delete(v8);
    }
  }
  SentPacketStore::Flush(&v3->m_sentPacketStore, id, fEverything);
}

//----- (00547740) --------------------------------------------------------  // acclient.c:374922
void __thiscall FlowQueue::CoalesceData(FlowQueue *this)
{
  FlowQueue *v1; // esi@1
  NetBlob *v2; // ebx@1
  BlobFrag *v3; // edi@2
  bool v4; // zf@3
  NetPacket *v5; // ebp@4
  unsigned int v6; // eax@6
  unsigned int v7; // ebx@6
  NetPacket *v8; // ebp@18
  LONG (__stdcall *v9)(volatile LONG *); // ebp@21
  bool v10; // bl@21
  signed int v11; // ecx@24
  PQueueArray<unsigned long,void *>::PQueueNode *v12; // eax@25
  int v13; // ecx@27
  BlobFrag *v14; // eax@36
  NetPacket *i; // ecx@37
  NetPacket *v16; // edi@45
  BlobFrag *v17; // edi@48
  volatile LONG *v18; // ST08_4@48
  BlobFrag *curFrag; // [sp+1Ch] [bp-Ch]@1
  NetBlob *curBlob; // [sp+20h] [bp-8h]@1
  unsigned int key; // [sp+24h] [bp-4h]@1

  v1 = this;
  v2 = (NetBlob *)((int (__stdcall *)(_DWORD))this->vfptr->Dequeue)(0);
  curBlob = v2;
  curFrag = 0;
  if ( PQueueArray<unsigned long,void *>::RemoveMin(&v1->pqueueSpecial_, &key, (void **)&curFrag) && (v3 = curFrag) != 0 )
  {
    while ( 1 )
    {
      v4 = ((unsigned int)v3->hdrWrite_ & 2) == 0;
      curFrag = 0;
      if ( !v4 )
        goto LABEL_58;
      v5 = v1->waitingPacketsHead_;
      while ( v5 )
      {
        v6 = NetPacket::ApplySpecialFrags(v5, 0);
        v7 = v6;
        if ( v5->flags_ & 1
          || *((_DWORD *)&v3->hdrRead_ + 1) + v5->size_ > 0x1D0
          || v6 & (unsigned int)v3->blobNextFrag_
          || v5->numSpecialFrags_ == 1 && v5->specialFragList_[0]->m_Flags & 2 )
        {
          v5 = v5->next_;
        }
        else
        {
          NetPacket::AddOptionalHeader(v5, (COptionalHeader *)v3);
          v1->vfptr->RecordBytesQueued(v1, *((_DWORD *)&v3->hdrRead_ + 1));
          curFrag = (BlobFrag *)1;
        }
        if ( !v7 || (unsigned int)v3->hdrWrite_ & 0x20 )
          break;
        if ( curFrag )
          goto LABEL_21;
      }
      if ( !curFrag )
      {
LABEL_58:
        v8 = NetPacket::CreateForSend(v1->myRecip_->recID_);
        NetPacket::AddOptionalHeader(v8, (COptionalHeader *)v3);
        v1->vfptr->EnqueuePacket(v1, v8, &v1->waitingPacketsHead_, &v1->waitingPacketsTail_);
        if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) && v8 )
          v8->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v8, 1u);
      }
LABEL_21:
      v9 = InterlockedDecrement;
      v10 = ((unsigned int)v3->hdrWrite_ & 0x20) == 32;
      if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
        v3->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 1u);
      if ( v10 )
        break;
      v11 = v1->pqueueSpecial_.curNumNodes;
      if ( v11 <= 0 )
        break;
      v12 = v1->pqueueSpecial_.A;
      if ( !v12 )
        break;
      v3 = (BlobFrag *)v12->data;
      if ( v11 <= 1 )
      {
        v1->pqueueSpecial_.curNumNodes = 0;
      }
      else
      {
        v13 = v11 - 1;
        v1->pqueueSpecial_.curNumNodes = v13;
        v12->key = v12[v13].key;
        v12->data = v12[v13].data;
      }
      PQueueArray<unsigned long,void *>::_Heapify(&v1->pqueueSpecial_, 1);
      if ( !v3 )
      {
        v9 = InterlockedDecrement;
        break;
      }
    }
    v2 = curBlob;
  }
  else
  {
    v9 = InterlockedDecrement;
  }
  if ( v2 )
  {
    while ( 1 )
    {
      ((void (*)(void))FlowQueue::m_pBlobsDequeuedCounter->vfptr[3].__vecDelDtor)();
      NetBlob::Fragmentize(v2, &curFrag);
      v14 = curFrag;
      if ( curFrag )
      {
        do
        {
          for ( i = v1->waitingPacketsHead_; i; i = i->next_ )
          {
            if ( !(i->flags_ & 1)
              && i->size_ + v14->hdrRead_->blobFragSize <= 0x1D0
              && (i->numSpecialFrags_ != 1 || !(i->specialFragList_[0]->m_Flags & 2)) )
            {
              NetPacket::AddFrag(i, v14, v1->myRecip_->recID_, v14->myBlob_->priority_);
              v1->vfptr->RecordBytesQueued(v1, curFrag->hdrRead_->blobFragSize);
              goto LABEL_48;
            }
          }
          v16 = NetPacket::CreateForSend(v1->myRecip_->recID_);
          NetPacket::AddFrag(v16, curFrag, v1->myRecip_->recID_, curFrag->myBlob_->priority_);
          v1->vfptr->EnqueuePacket(v1, v16, &v1->waitingPacketsHead_, &v1->waitingPacketsTail_);
          if ( !v9((volatile LONG *)&v16->m_cRef) && v16 )
            v16->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v16, 1u);
LABEL_48:
          v17 = curFrag;
          v18 = (volatile LONG *)&curFrag->m_cRef;
          curFrag = curFrag->blobNextFrag_;
          if ( !v9(v18) )
            v17->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v17, 1u);
          v14 = curFrag;
        }
        while ( curFrag );
        v2 = curBlob;
      }
      if ( !v9((volatile LONG *)&v2->m_cRef) )
      {
        if ( v2 )
          v2->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, 1u);
      }
      curBlob = v1->vfptr->Dequeue(v1, 0);
      if ( !curBlob )
        break;
      v2 = curBlob;
    }
  }
}

//----- (00547A60) --------------------------------------------------------  // acclient.c:375080
char __thiscall FlowQueue::TransmitNewPackets(FlowQueue *this)
{
  FlowQueue *v1; // edi@1
  unsigned __int16 v2; // ax@1
  unsigned __int16 v3; // cx@1
  unsigned __int16 v4; // dx@1
  NetPacket *v5; // esi@2
  char v6; // bl@3
  RecipientData *v7; // ecx@6
  unsigned int *v8; // ecx@13
  bool v9; // zf@16
  unsigned int *v10; // ST0C_4@19
  ReceiverData *v11; // ecx@19
  unsigned int v12; // ST00_4@19
  unsigned int v13; // eax@19
  int v14; // ecx@19
  PacketController *v15; // eax@22
  int v16; // ebp@25
  char v18; // [sp+15h] [bp-1Dh]@1
  char mem[4]; // [sp+16h] [bp-1Ch]@19
  unsigned int key; // [sp+1Ah] [bp-18h]@13
  ProtoHeader newHeader; // [sp+1Eh] [bp-14h]@1

  v1 = this;
  v18 = 0;
  FlowQueue::CoalesceData(this);
  v2 = v1->myReceiverData_->iteration_;
  v3 = v1->netID_;
  v4 = v1->CurLocalInterval_.intervalID_;
  newHeader.seqID_ = 0;
  newHeader.header_ = 0;
  newHeader.checksum_ = 0;
  newHeader.recID_ = v3;
  newHeader.interval_ = v4;
  newHeader.datalen_ = 0;
  newHeader.iteration_ = v2;
  while ( 1 )
  {
    v5 = v1->waitingPacketsHead_;
    if ( !v5 )
      break;
    v6 = v5->flags_ & 1;
    if ( !v1->vfptr->WireRoomLeft(v1, v5->size_) && !((v5->flags_ >> 3) & 1) )
      break;
    newHeader.header_ = 0;
    if ( v5->numFrags_ )
    {
      v7 = v1->myRecip_;
      newHeader.header_ = 4;
      RecipientData::TouchConnection(v7);
    }
    NetPacket::ApplySpecialFrags(v5, &newHeader);
    if ( !(newHeader.header_ & 0xFFFFFF) && !v5->next_ )
      break;
    NetPacket::UpdateTimeSensitiveHeaders(v5);
    if ( !v5->checksum_ )
      NetPacket::ComputeChecksum(v5);
    if ( (v5->flags_ >> 2) & 1 )
    {
      if ( !(v5->flags_ & 1) )
      {
        key = v5->cryptoKey_;
        v8 = 0;
        if ( v5->seqNum_ && v6 )
        {
          v8 = &key;
        }
        else
        {
          v9 = v1->highestIDSent_++ == -1;
          if ( v9 )
            v1->highestIDSent_ = 1;
          v5->seqNum_ = v1->highestIDSent_;
        }
        v10 = v8;
        v11 = v1->myReceiverData_;
        v12 = v5->seqNum_;
        *(_DWORD *)mem = v5->checksum_;
        v13 = ReceiverData::Encrypt(v11, v12, mem, 4u, v10);
        v14 = v5->flags_ | 1;
        v5->checksum_ = *(_DWORD *)mem;
        v5->flags_ = v14;
        v5->cryptoKey_ = v13;
      }
      newHeader.header_ |= 2u;
    }
    else
    {
      v5->seqNum_ = v1->highestIDSent_;
    }
    newHeader.seqID_ = v5->seqNum_;
    newHeader.checksum_ = v5->checksum_;
    newHeader.datalen_ = LOWORD(v5->size_);
    v15 = PacketController::Instance();
    if ( !SharedNet::SendPacket((SharedNet *)&v15->net_->vfptr, v5, &newHeader, &v1->addr_) )
      break;
    v1->vfptr->RecordBytesSent(v1, v5->size_ + 20);
    v9 = (newHeader.header_ & 0x200000) == 0;
    ++v1->m_cPacketsSent;
    if ( !v9 )
      v1->myRecip_->m_ConnectionState = 7;
    v16 = (int)v1->vfptr->DequeuePacket(v1, &v1->waitingPacketsHead_, &v1->waitingPacketsTail_);
    if ( (v5->flags_ >> 2) & 1 )
      SentPacketStore::AddSentPacket(&v1->m_sentPacketStore, v5);
    if ( !InterlockedDecrement((volatile LONG *)(v16 + 4)) )
    {
      if ( v16 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
    }
    v18 = 1;
  }
  return v18;
}

//----- (00547CD0) --------------------------------------------------------  // acclient.c:375195
void __thiscall ClientFlowQueue::Enqueue(ClientFlowQueue *this, NetBlob *newBlob)
{
  ClientFlowQueue *v2; // edi@1
  RecipientData *v3; // ST04_4@2
  PacketController *v4; // eax@2

  v2 = this;
  if ( this->myRecip_->m_ConnectionState <= 5 )
  {
    InterlockedIncrement((volatile LONG *)&newBlob->m_cRef);
    PQueueArray<unsigned long,void *>::Insert(&v2->pqueue_, newBlob->priority_, newBlob);
    v3 = v2->myRecip_;
    v4 = PacketController::Instance();
    PacketController::EnqueueRecip(v4, v3);
  }
}

//----- (00547D20) --------------------------------------------------------  // acclient.c:375213
unsigned int __thiscall ClientFlowQueue::Dequeue(ClientFlowQueue *this, int __formal)
{
  char v2; // al@1
  void *hook; // [sp+0h] [bp-8h]@1
  unsigned int key; // [sp+4h] [bp-4h]@1

  hook = 0;
  v2 = PQueueArray<unsigned long,void *>::RemoveMin(&this->pqueue_, &key, &hook);
  return v2 != 0 ? (unsigned int)hook : 0;
}

//----- (00547D50) --------------------------------------------------------  // acclient.c:375225
void __thiscall NIListIter<unsigned long>::AddBeforeCur(NIListIter<unsigned long> *this, unsigned int inData)
{
  NIListIter<unsigned long> *v2; // esi@1
  NIList<unsigned long> *v3; // edi@2
  void *v4; // eax@2
  NIListElement<unsigned long> *v5; // ecx@3
  NIListElement<unsigned long> *v6; // ecx@5
  void *v7; // eax@10
  NIListElement<unsigned long> *v8; // ecx@11

  v2 = this;
  if ( this->prev_ )
  {
    if ( this->cur_ )
    {
      v7 = operator new(8u);
      if ( v7 )
      {
        v8 = v2->cur_;
        *(_DWORD *)v7 = inData;
        *((_DWORD *)v7 + 1) = v8;
        v2->prev_->next_ = (NIListElement<unsigned long> *)v7;
        v2->prev_ = (NIListElement<unsigned long> *)v7;
      }
      else
      {
        v2->prev_->next_ = 0;
        v2->prev_ = 0;
      }
    }
    else
    {
      NIList<NetBlob *>::AddToTail(this->list_, inData);
      v2->prev_ = v2->list_->tail_;
    }
  }
  else
  {
    v3 = this->list_;
    v4 = operator new(8u);
    if ( v4 )
    {
      v5 = v3->head_;
      *(_DWORD *)v4 = inData;
      *((_DWORD *)v4 + 1) = v5;
    }
    else
    {
      v4 = 0;
    }
    v6 = v3->tail_;
    v3->head_ = (NIListElement<unsigned long> *)v4;
    if ( !v6 )
      v3->tail_ = (NIListElement<unsigned long> *)v4;
    v2->prev_ = v2->list_->head_;
  }
}

//----- (00547DF0) --------------------------------------------------------  // acclient.c:375284
COptionalHeader *__cdecl CPackObjHeader<NetError,2097152,2>::CreateFromData(NetError *ConstObj)
{
  NetError *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // esi@1
  NetError *v4; // eax@1
  PackObjVtbl *v5; // edx@1
  void *v6; // edi@1
  COptionalHeader *result; // eax@3

  v1 = ConstObj;
  v2 = ((int (__thiscall *)(NetError *))ConstObj->vfptr->GetPackSize)(ConstObj);
  v3 = v2;
  v4 = (NetError *)operator new[](v2);
  v5 = v1->vfptr;
  v6 = v4;
  ConstObj = v4;
  if ( ((int (__thiscall *)(NetError *, NetError **, unsigned int))v5->Pack)(v1, &ConstObj, v3) != v3 )
  {
    operator delete(v6);
    return 0;
  }
  result = (COptionalHeader *)operator new(0x30u);
  if ( !result )
    return 0;
  result->m_pData = (char *)v6;
  result[1].vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)v6;
  result->m_cbData = v3;
  result[1].m_cRef = v3;
  result->m_cRef = 1;
  result->m_dwMask = 0x200000;
  result->m_Flags = 2;
  result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CPackObjHeader<NetError,2097152,2>::vftable;
  result[1].m_dwMask = (unsigned int)&NetError::vftable;
  return result;
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 7CA500: using guessed type int (__thiscall *CPackObjHeader<NetError,2097152,2>::vftable)(void *, char);

//----- (00547E70) --------------------------------------------------------  // acclient.c:375324
COptionalHeader *__cdecl COnePrimHeader<4194304,7,CICMDCommandStruct>::CreateFromData(CICMDCommandStruct Prim)
{
  COptionalHeader *result; // eax@1

  result = (COptionalHeader *)operator new(0x20u);
  if ( result )
  {
    result[1].0 = (ReferenceCountTemplate<1048576,0>)Prim;
    result->m_cRef = 1;
    result->m_dwMask = 0x400000;
    result->m_Flags = 7;
    result->m_pData = (char *)&result[1];
    result->m_cbData = 8;
    result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (00547EC0) --------------------------------------------------------  // acclient.c:375348
int __thiscall ClientFlowQueue::OnLocalIntervalAck(ClientFlowQueue *this, IntervalData *IntervalBeingAcked)
{
  unsigned __int16 v2; // dx@1
  unsigned __int16 v3; // ax@1
  unsigned __int16 v4; // si@2
  int v5; // edi@2
  int result; // eax@7

  v2 = IntervalBeingAcked->intervalID_;
  v3 = this->lastIntervalAcked_;
  if ( IntervalBeingAcked->intervalID_ == v3 )
    goto LABEL_11;
  v4 = v2 - v3;
  v5 = 1;
  if ( v2 < v3 )
  {
    v4 = v3 - v2;
    v5 = -1;
  }
  if ( v4 > 0x7FFFu )
    v5 = -v5;
  if ( v5 <= 0 )
  {
LABEL_11:
    result = 0;
  }
  else
  {
    this->lastIntervalAcked_ = v2;
    result = 1;
  }
  return result;
}

//----- (00547F10) --------------------------------------------------------  // acclient.c:375383
void __thiscall ClientFlowQueue::IncrementLocalInterval(ClientFlowQueue *this, unsigned int cIntervals)
{
  ClientFlowQueue *v2; // esi@1
  int v3; // edi@1
  unsigned int v4; // ecx@1
  COptionalHeader *v5; // edi@5
  COptionalHeader *v6; // edi@8
  unsigned int v7; // ecx@11
  COptionalHeader *v8; // edi@15
  unsigned int v9; // ecx@15
  int v10; // eax@15
  int v11; // ecx@15
  u_short v12; // ax@15
  sockaddr_in addrServerWrite; // [sp+10h] [bp-10h]@5

  v2 = this;
  v3 = this->CurLocalInterval_.intervalID_;
  v4 = (v3 + cIntervals) % 6;
  if ( v4 == 1 || cIntervals >= 6 || (signed int)v4 > 0 && (signed int)v4 < (signed int)(v3 % 6u) )
  {
    *(_QWORD *)&addrServerWrite.sin_family = Timer::cur_time;
    v5 = CTimeSyncHeader::CreateFromData(*(long double *)&Timer::cur_time);
    FlowQueue::EnqueueOptionalHeader((FlowQueue *)&v2->vfptr, v5);
    if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
      v5->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 1u);
    v6 = CEchoRequestHeader::CreateFromData();
    FlowQueue::EnqueueOptionalHeader((FlowQueue *)&v2->vfptr, v6);
    if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 1u);
  }
  v7 = (v2->CurLocalInterval_.intervalID_ + cIntervals) % 0xDC;
  if ( v7 == 1
    || cIntervals >= 0xDC
    || (signed int)v7 > 0 && (signed int)v7 < (signed int)(v2->CurLocalInterval_.intervalID_ % 0xDCu) )
  {
    v8 = COnePrimHeader<4194304,7,CICMDCommandStruct>::CreateFromData((CICMDCommandStruct)1i64);
    v9 = v2->addr_.sin_addr.S_un.S_addr;
    *(_DWORD *)&addrServerWrite.sin_family = *(_DWORD *)&v2->addr_.sin_family;
    v10 = *(_DWORD *)&v2->addr_.sin_zero[0];
    addrServerWrite.sin_addr.S_un.S_addr = v9;
    v11 = *(_DWORD *)&v2->addr_.sin_zero[4];
    *(_DWORD *)&addrServerWrite.sin_zero[0] = v10;
    *(_DWORD *)&addrServerWrite.sin_zero[4] = v11;
    v12 = ntohs(addrServerWrite.sin_port);
    addrServerWrite.sin_port = htons(v12 + 1);
    SharedNet::SendOptionalHeader(SharedNet::s_pNet, v8, &addrServerWrite, 0);
    if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) && v8 )
      v8->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v8, 1u);
  }
  v2->CurLocalInterval_.intervalID_ += cIntervals;
}

//----- (00548090) --------------------------------------------------------  // acclient.c:375436
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,int> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,int> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7CA4FC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>::vftable[2])(void *, char);

//----- (00548180) --------------------------------------------------------  // acclient.c:375503
HashTable<unsigned long,int,0> *__thiscall HashTable<unsigned long,int,0>::vector_deleting_destructor(HashTable<unsigned long,int,0> *this, unsigned int a2)
{
  HashTable<unsigned long,int,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,int,0>Vtbl *)HashTable<unsigned long,int,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>::vftable;
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
// 7CA4FC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>::vftable[2])(void *, char);
// 7CA510: using guessed type int (__thiscall *HashTable<unsigned long,int,0>::vftable[2])(void *, char);

//----- (005481E0) --------------------------------------------------------  // acclient.c:375529
void __thiscall FlowQueue::FlowQueue(FlowQueue *this, sockaddr_in addr, unsigned __int16 recID, float lineNoise)
{
  FlowQueue *v4; // esi@1
  ClientNet *v5; // eax@1
  int v6; // eax@2
  long double v7; // kr00_8@4

  v4 = this;
  this->vfptr = (FlowQueueVtbl *)&FlowQueue::vftable;
  this->waitingPacketsHead_ = 0;
  this->waitingPacketsTail_ = 0;
  this->m_ackList.head_ = 0;
  this->m_ackList.tail_ = 0;
  SentPacketStore::SentPacketStore(&this->m_sentPacketStore);
  v4->m_emptyAckList.head_ = 0;
  v4->m_emptyAckList.tail_ = 0;
  v4->empties_.vfptr = (HashTable<unsigned long,int,0>Vtbl *)HashTable<unsigned long,int,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>(
    &v4->empties_.m_intrusiveTable,
    0x20u);
  v4->addr_ = addr;
  v4->emptyNum_ = 0;
  v4->m_cPacketsSent = 0;
  v4->m_cPacketsAcked = 0;
  v4->highestIDSent_ = 1;
  v4->myRecip_ = 0;
  v5 = PacketController::Instance()->net_;
  if ( recID >= 0x100u )
    v6 = 0;
  else
    v6 = (int)&v5->receivers_[136 * recID];
  v4->myReceiverData_ = (ReceiverData *)v6;
  v4->netID_ = recID;
  v4->pqueueSpecial_.vfptr = (PQueueArray<unsigned long,void *>Vtbl *)PQueueArray<unsigned long,void *>::vftable;
  v4->pqueueSpecial_.curNumNodes = 0;
  v4->pqueueSpecial_.A = (PQueueArray<unsigned long,void *>::PQueueNode *)operator new[](0x200u);
  v4->pqueueSpecial_.minAllocatedNodes = 64;
  v4->pqueueSpecial_.allocatedNodes = 64;
  v7 = Timer::local_time;
  v4->lastIntervalAcked_ = 0;
  v4->intervalTime_ = v7;
}
// 7CA4E8: using guessed type int (__thiscall *PQueueArray<unsigned long,void *>::vftable[2])(void *, char);
// 7CA510: using guessed type int (__thiscall *HashTable<unsigned long,int,0>::vftable[2])(void *, char);
// 7CA514: using guessed type int (__thiscall *FlowQueue::vftable)(void *, char);

//----- (00548300) --------------------------------------------------------  // acclient.c:375576
void __thiscall FlowQueue::~FlowQueue(FlowQueue *this)
{
  FlowQueue *v1; // esi@1
  PQueueArray<unsigned long,void *>::PQueueNode *v2; // ST00_4@1
  void *v3; // eax@1

  v1 = this;
  this->vfptr = (FlowQueueVtbl *)&FlowQueue::vftable;
  v2 = this->pqueueSpecial_.A;
  this->pqueueSpecial_.vfptr = (PQueueArray<unsigned long,void *>Vtbl *)PQueueArray<unsigned long,void *>::vftable;
  operator delete[](v2);
  v1->empties_.vfptr = (HashTable<unsigned long,int,0>Vtbl *)HashTable<unsigned long,int,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->empties_.m_intrusiveTable);
  v3 = v1->empties_.m_intrusiveTable.m_buckets;
  v1->empties_.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>::vftable;
  if ( v3 != v1->empties_.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v3);
  v1->empties_.m_intrusiveTable.m_buckets = 0;
  v1->empties_.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->empties_.m_intrusiveTable.m_numBuckets = 0;
  v1->empties_.m_intrusiveTable.m_numElements = 0;
  NIList<unsigned long>::DeleteContents((NIList<NetPacket *> *)&v1->m_emptyAckList);
  SentPacketStore::~SentPacketStore(&v1->m_sentPacketStore);
  NIList<unsigned long>::DeleteContents((NIList<NetPacket *> *)&v1->m_ackList);
}
// 7CA4E8: using guessed type int (__thiscall *PQueueArray<unsigned long,void *>::vftable[2])(void *, char);
// 7CA4FC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>::vftable[2])(void *, char);
// 7CA510: using guessed type int (__thiscall *HashTable<unsigned long,int,0>::vftable[2])(void *, char);
// 7CA514: using guessed type int (__thiscall *FlowQueue::vftable)(void *, char);

//----- (00548380) --------------------------------------------------------  // acclient.c:375607
void __thiscall FlowQueue::EnqueueEmptyAck(FlowQueue *this, unsigned int id)
{
  unsigned int v2; // edi@1
  FlowQueue *v3; // esi@1
  HashTableData<unsigned long,int> *v4; // eax@1
  void *v5; // eax@7
  NIListElement<unsigned long> *v6; // ecx@10
  RenderVertexStreamD3D *_data; // [sp+0h] [bp-4h]@1

  _data = (RenderVertexStreamD3D *)this;
  v2 = id;
  v3 = this;
  v4 = this->empties_.m_intrusiveTable.m_buckets[id % this->empties_.m_intrusiveTable.m_numBuckets];
  if ( !v4 )
    goto LABEL_7;
  while ( v4->m_hashKey != id )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_7;
  }
  if ( !v4 || v4 == (HashTableData<unsigned long,int> *)-8 )
  {
LABEL_7:
    ++this->emptyNum_;
    v5 = operator new(8u);
    if ( v5 )
    {
      *(_DWORD *)v5 = v2;
      *((_DWORD *)v5 + 1) = 0;
    }
    else
    {
      v5 = 0;
    }
    v6 = v3->m_emptyAckList.tail_;
    if ( v6 )
    {
      v6->next_ = (NIListElement<unsigned long> *)v5;
      v3->m_emptyAckList.tail_ = v3->m_emptyAckList.tail_->next_;
    }
    else
    {
      v3->m_emptyAckList.head_ = (NIListElement<unsigned long> *)v5;
      v3->m_emptyAckList.tail_ = (NIListElement<unsigned long> *)v5;
    }
    ++v3->m_cPacketsAcked;
    _data = 0;
    HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
      (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&v3->empties_,
      &id,
      &_data);
  }
}

//----- (00548440) --------------------------------------------------------  // acclient.c:375663
int __thiscall FlowQueue::DequeueEmptyAck(FlowQueue *this, unsigned int *seqID)
{
  FlowQueue *v2; // esi@1
  NIListElement<unsigned long> *v3; // eax@1
  unsigned int v4; // edi@3
  NIListElement<unsigned long> *v5; // ecx@4
  HashSetData<IDClass<_tagDataID,32,0> > *v6; // eax@7
  int result; // eax@9

  v2 = this;
  v3 = this->m_emptyAckList.head_;
  if ( v3 )
  {
    --this->emptyNum_;
    if ( v3 )
    {
      v5 = v3->next_;
      v2->m_emptyAckList.head_ = v5;
      if ( !v5 )
        v2->m_emptyAckList.tail_ = 0;
      v4 = v3->data_;
      operator delete(v3);
    }
    else
    {
      v4 = 0;
    }
    *seqID = v4;
    v6 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
           (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&v2->empties_.m_intrusiveTable,
           (IDClass<_tagDataID,32,0> *)seqID);
    if ( v6 )
      operator delete(v6);
    result = 1;
  }
  else
  {
    *seqID = 0;
    result = 0;
  }
  return result;
}

//----- (005484C0) --------------------------------------------------------  // acclient.c:375707
void __thiscall FlowQueue::CompileEmptyAcks(FlowQueue *this)
{
  FlowQueue *v1; // ebp@1
  int v2; // esi@1
  signed int v3; // edi@5
  char *v4; // ebx@6
  unsigned int curr; // [sp+10h] [bp-4h]@7

  v1 = this;
  v2 = this->emptyNum_;
  if ( !v2 || this->emptyAcks_[0] )
  {
    this->emptyAcks_[0] = 0;
  }
  else
  {
    if ( (unsigned int)v2 > 0x72 )
      v2 = 114;
    v3 = 1;
    this->emptyAcks_[0] = v2;
    if ( v2 >= 1 )
    {
      v4 = (char *)&this->emptyAcks_[1];
      do
      {
        if ( !FlowQueue::DequeueEmptyAck(v1, &curr) )
          break;
        *(_DWORD *)v4 = curr;
        ++v3;
        v4 += 4;
      }
      while ( v3 <= v2 );
    }
  }
}

//----- (00548540) --------------------------------------------------------  // acclient.c:375744
char __thiscall FlowQueue::TransmitNaks(FlowQueue *this)
{
  FlowQueue *v1; // edi@1
  unsigned int v2; // esi@1
  CSeqIDListHeader<8192,33> *v3; // eax@2
  int v4; // eax@3
  int v5; // esi@3
  char result; // al@8

  v1 = this;
  FlowQueue::CompileEmptyAcks(this);
  v2 = v1->emptyAcks_[0];
  if ( v2 )
  {
    v3 = (CSeqIDListHeader<8192,33> *)operator new(0x1E4u);
    if ( v3 )
    {
      CSeqIDListHeader<8192,33>::CSeqIDListHeader<8192,33>(v3, &v1->emptyAcks_[1], v2);
      v5 = v4;
    }
    else
    {
      v5 = 0;
    }
    FlowQueue::EnqueueOptionalHeader(v1, (COptionalHeader *)v5);
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005485B0) --------------------------------------------------------  // acclient.c:375784
bool __thiscall FlowQueue::TransmitAcks(FlowQueue *this)
{
  FlowQueue *v1; // edi@1
  unsigned __int16 v2; // ax@1
  unsigned __int16 v3; // dx@1
  int v4; // ebp@1
  NetPacket *v5; // esi@1
  PacketController *v6; // eax@7
  PacketController *v7; // eax@14
  ProtoHeader ackHeader; // [sp+Ch] [bp-14h]@1

  v1 = this;
  v2 = this->myReceiverData_->iteration_;
  v3 = this->CurLocalInterval_.intervalID_;
  ackHeader.recID_ = this->netID_;
  ackHeader.seqID_ = 0;
  ackHeader.header_ = 3;
  ackHeader.checksum_ = 0;
  ackHeader.interval_ = v3;
  ackHeader.datalen_ = 0;
  ackHeader.iteration_ = v2;
  v4 = 0;
  v5 = FlowQueue::DequeueAck(this);
  if ( v5 )
  {
    do
    {
      if ( v5->numFrags_ || v5->numSpecialFrags_ )
      {
        ackHeader.header_ = 3;
        if ( v5->numFrags_ )
          ackHeader.header_ = 7;
        NetPacket::ApplySpecialFrags(v5, &ackHeader);
        ackHeader.seqID_ = v5->seqNum_;
        ackHeader.checksum_ = v5->checksum_;
        ackHeader.datalen_ = LOWORD(v5->size_);
        v6 = PacketController::Instance();
        if ( SharedNet::SendPacket((SharedNet *)&v6->net_->vfptr, v5, &ackHeader, &v1->addr_) )
        {
          v1->vfptr->RecordBytesSent(v1, v5->size_ + 20);
          ++v1->m_cPacketsSent;
        }
        ++v4;
      }
      else
      {
        FlowQueue::EnqueueEmptyAck(v1, v5->seqNum_);
      }
      if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) )
        v5->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 1u);
      v5 = FlowQueue::DequeueAck(v1);
    }
    while ( v5 );
    if ( v4 )
    {
      v7 = PacketController::Instance();
      v7->net_->vfptr->AddToPerfCounter((SharedNet *)v7->net_, RetransmitsSentCounter, v4);
    }
  }
  return v4 > 0;
}

//----- (00548700) --------------------------------------------------------  // acclient.c:375847
void __thiscall ClientFlowQueue::ClientFlowQueue(ClientFlowQueue *this, sockaddr_in addr, unsigned __int16 recID, float lineNoise)
{
  ClientFlowQueue *v4; // esi@1
  sockaddr_in v5; // ST00_16@1

  v4 = this;
  *(_QWORD *)&v5.sin_family = *(_QWORD *)&addr;
  *(_QWORD *)&v5.sin_zero[0] = *(_QWORD *)&addr.sin_zero[0];
  FlowQueue::FlowQueue((FlowQueue *)&this->vfptr, v5, recID, lineNoise);
  v4->vfptr = (FlowQueueVtbl *)&ClientFlowQueue::vftable;
  v4->pqueue_.vfptr = (PQueueArray<unsigned long,void *>Vtbl *)PQueueArray<unsigned long,void *>::vftable;
  v4->pqueue_.curNumNodes = 0;
  v4->pqueue_.A = (PQueueArray<unsigned long,void *>::PQueueNode *)operator new[](0x200u);
  v4->pqueue_.minAllocatedNodes = 64;
  v4->pqueue_.allocatedNodes = 64;
  v4->netID_ = *(_WORD *)&SharedNet::s_pNet->receivers_[136 * recID + 44];
  v4->CurLocalInterval_.nBytes_ = 0;
  v4->CurLocalInterval_.FlowLevel_ = 10;
  v4->CurLocalInterval_.intervalID_ = 1;
  v4->CurLocalInterval_.nPkts_ = 0;
}
// 7CA4E8: using guessed type int (__thiscall *PQueueArray<unsigned long,void *>::vftable[2])(void *, char);
// 7CA540: using guessed type int (__thiscall *ClientFlowQueue::vftable)(void *, char);

//----- (005487C0) --------------------------------------------------------  // acclient.c:375872
FlowQueue *__thiscall FlowQueue::vector_deleting_destructor(FlowQueue *this, unsigned int a2)
{
  FlowQueue *v2; // esi@1

  v2 = this;
  FlowQueue::~FlowQueue(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005487E0) --------------------------------------------------------  // acclient.c:375884
void __thiscall FlowQueue::Destroy(FlowQueue *this)
{
  FlowQueue *v1; // esi@1
  int i; // edi@1
  int v3; // edi@8
  int v4; // esi@12
  signed int v5; // ecx@13
  int v6; // eax@14
  int v7; // edi@15
  int v8; // ecx@16
  unsigned int seqID; // [sp+10h] [bp-4h]@6

  v1 = this;
  for ( i = ((int (__stdcall *)(signed int))this->vfptr->Dequeue)(1); i; i = (int)v1->vfptr->Dequeue(v1, 1) )
  {
    if ( !InterlockedDecrement((volatile LONG *)(i + 4)) && i )
      (**(void (__thiscall ***)(_DWORD, _DWORD))i)(i, 1);
  }
  while ( FlowQueue::DequeueEmptyAck(v1, &seqID) )
    ;
  NIList<unsigned long>::DeleteContents((NIList<NetPacket *> *)&v1->m_ackList);
  while ( v1->waitingPacketsHead_ )
  {
    v3 = (int)v1->vfptr->DequeuePacket(v1, &v1->waitingPacketsHead_, &v1->waitingPacketsTail_);
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
  v4 = (int)&v1->pqueueSpecial_;
  while ( 1 )
  {
    v5 = *(_DWORD *)(v4 + 8);
    if ( v5 <= 0 )
      break;
    v6 = *(_DWORD *)(v4 + 4);
    if ( !v6 )
      break;
    v7 = *(_DWORD *)(v6 + 4);
    if ( v5 <= 1 )
    {
      *(_DWORD *)(v4 + 8) = 0;
    }
    else
    {
      v8 = v5 - 1;
      *(_DWORD *)(v4 + 8) = v8;
      *(_DWORD *)v6 = *(_DWORD *)(v6 + 8 * v8);
      *(_DWORD *)(v6 + 4) = *(_DWORD *)(v6 + 8 * v8 + 4);
    }
    PQueueArray<unsigned long,void *>::_Heapify((PQueueArray<unsigned long,void *> *)v4, 1);
    if ( !v7 )
      break;
    if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  }
}

//----- (005488E0) --------------------------------------------------------  // acclient.c:375941
void __thiscall FlowQueue::EnqueueAcks(FlowQueue *this, const unsigned int *id, int nIDs)
{
  NIListElement<unsigned long> *v3; // ebp@1
  int v4; // edi@1
  int v5; // eax@1
  unsigned int v6; // eax@3
  const unsigned int v7; // ecx@3
  int v8; // edx@4
  int v9; // esi@4
  int v10; // edx@13
  int v11; // esi@13
  FlowQueue *v12; // [sp+8h] [bp-10h]@1
  NIListIter<unsigned long> iterAckList; // [sp+Ch] [bp-Ch]@1

  v12 = this;
  v3 = this->m_ackList.head_;
  v4 = 0;
  iterAckList.list_ = &this->m_ackList;
  v5 = nIDs;
  iterAckList.cur_ = v3;
  iterAckList.prev_ = 0;
  if ( nIDs <= 0 )
    return;
  while ( v3 )
  {
    v6 = v3->data_;
    v7 = id[v4];
    if ( v7 == v3->data_ )
      goto LABEL_19;
    v8 = v7 - v6;
    v9 = 1;
    if ( v7 < v6 )
    {
      v8 = v6 - v7;
      v9 = -1;
    }
    if ( (unsigned int)v8 > 0x7FFFFFFF )
      v9 = -v9;
    if ( v9 < 0 )
    {
      if ( SentPacketStore::Contains(&v12->m_sentPacketStore, id[v4]) )
      {
        NIListIter<unsigned long>::AddBeforeCur(&iterAckList, id[v4]);
        v3 = iterAckList.cur_;
      }
      else
      {
        FlowQueue::EnqueueEmptyAck(v12, id[v4]);
      }
      goto LABEL_20;
    }
    if ( v7 == v6 )
      goto LABEL_19;
    v10 = v7 - v6;
    v11 = 1;
    if ( v7 < v6 )
    {
      v10 = v6 - v7;
      v11 = -1;
    }
    if ( (unsigned int)v10 > 0x7FFFFFFF )
      v11 = -v11;
    if ( v11 <= 0 )
    {
LABEL_19:
      iterAckList.prev_ = v3;
      v3 = v3->next_;
      iterAckList.cur_ = v3;
LABEL_20:
      ++v4;
      goto LABEL_21;
    }
    NIListIter<unsigned long>::RemoveCur(&iterAckList);
    v3 = iterAckList.cur_;
LABEL_21:
    v5 = nIDs;
    if ( v4 >= nIDs )
      return;
  }
  if ( v4 < v5 )
  {
    do
    {
      if ( SentPacketStore::Contains(&v12->m_sentPacketStore, id[v4]) )
        NIListIter<unsigned long>::AddBeforeCur(&iterAckList, id[v4]);
      else
        FlowQueue::EnqueueEmptyAck(v12, id[v4]);
      ++v4;
    }
    while ( v4 < nIDs );
  }
}

//----- (00548A20) --------------------------------------------------------  // acclient.c:376035
void __thiscall FlowQueue::Empty(FlowQueue *this)
{
  FlowQueue *v1; // esi@1
  COptionalHeader *v2; // edi@6
  unsigned int v3; // ecx@7
  double v4; // st6@8

  v1 = this;
  if ( this->addr_.sin_addr.S_un.S_addr && this->myReceiverData_ )
  {
    FlowQueue::TransmitNaks(this);
    FlowQueue::TransmitAcks(v1);
    FlowQueue::TransmitNewPackets(v1);
    if ( v1->myRecip_->m_ConnectionState == 6
      && (!v1->waitingPacketsHead_ || ReceiverData::GetConnectionStateDuration(v1->myReceiverData_) > 10.0) )
    {
      v2 = CPackObjHeader<NetError,2097152,2>::CreateFromData(&ID_NetError_None);
      FlowQueue::EnqueueOptionalHeader(v1, v2);
      ReferenceCountTemplate<1048576,0>::Release((ReferenceCountTemplate<1048576,0> *)&v2->vfptr);
    }
    v3 = 0;
    if ( Timer::local_time > v1->intervalTime_ )
    {
      v4 = v1->intervalTime_;
      do
      {
        v4 = v4 + 0.5;
        ++v3;
      }
      while ( Timer::local_time > v4 );
      v1->intervalTime_ = v4;
      if ( v3 )
        v1->vfptr->IncrementLocalInterval(v1, v3);
    }
  }
}

//----- (00548AF0) --------------------------------------------------------  // acclient.c:376073
void __thiscall ClientFlowQueue::~ClientFlowQueue(ClientFlowQueue *this)
{
  ClientFlowQueue *v1; // esi@1
  void *v2; // ST00_4@1

  v1 = this;
  this->vfptr = (FlowQueueVtbl *)&ClientFlowQueue::vftable;
  FlowQueue::Destroy((FlowQueue *)&this->vfptr);
  v2 = v1->pqueue_.A;
  v1->pqueue_.vfptr = (PQueueArray<unsigned long,void *>Vtbl *)PQueueArray<unsigned long,void *>::vftable;
  operator delete[](v2);
  FlowQueue::~FlowQueue((FlowQueue *)&v1->vfptr);
}
// 7CA4E8: using guessed type int (__thiscall *PQueueArray<unsigned long,void *>::vftable[2])(void *, char);
// 7CA540: using guessed type int (__thiscall *ClientFlowQueue::vftable)(void *, char);

//----- (00548B20) --------------------------------------------------------  // acclient.c:376090
ClientFlowQueue *__thiscall ClientFlowQueue::scalar_deleting_destructor(ClientFlowQueue *this, unsigned int a2)
{
  ClientFlowQueue *v2; // esi@1
  void *v3; // ST00_4@1

  v2 = this;
  this->vfptr = (FlowQueueVtbl *)&ClientFlowQueue::vftable;
  FlowQueue::Destroy((FlowQueue *)&this->vfptr);
  v3 = v2->pqueue_.A;
  v2->pqueue_.vfptr = (PQueueArray<unsigned long,void *>Vtbl *)PQueueArray<unsigned long,void *>::vftable;
  operator delete[](v3);
  FlowQueue::~FlowQueue((FlowQueue *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7CA4E8: using guessed type int (__thiscall *PQueueArray<unsigned long,void *>::vftable[2])(void *, char);
// 7CA540: using guessed type int (__thiscall *ClientFlowQueue::vftable)(void *, char);

//----- (00548B70) --------------------------------------------------------  // acclient.c:376110
void __cdecl FlowQueue::SharedStaticInit()
{
  unsigned int v0; // eax@1
  unsigned int v1; // eax@1
  PerfMonCounterInfo *v2; // eax@1
  char *v3; // esi@4
  char *v4; // esi@7
  PStringBase<unsigned short> name; // [sp+8h] [bp-8h]@1
  PStringBase<unsigned short> help; // [sp+Ch] [bp-4h]@1

  v0 = _wcslen(L"The rate of NetBlobs released from all FlowQueues and given to the lower level net code.");
  PStringBase<unsigned short>::allocate_ref_buffer(&help, v0);
  _wcscpy(
    help.m_charbuffer->m_data,
    L"The rate of NetBlobs released from all FlowQueues and given to the lower level net code.");
  v1 = _wcslen(L"Net - NetBlobs FlowQueue dequeued/sec");
  PStringBase<unsigned short>::allocate_ref_buffer(&name, v1);
  _wcscpy(name.m_charbuffer->m_data, L"Net - NetBlobs FlowQueue dequeued/sec");
  v2 = PerfMonCounterInfo::LookupExistingCounterByName(&name, 9);
  if ( v2 )
    FlowQueue::m_pBlobsDequeuedCounter = (PerfMonCounter<unsigned __int64> *)v2;
  else
    PerfMonCounterFactory::CreateNewCounter(&FlowQueue::m_pBlobsDequeuedCounter, PER_SEC, &name, &help, 9u);
  v3 = (char *)&name.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&name.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = (char *)&help.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&help.m_charbuffer[-1].m_data[8]) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
}

//----- (00705660) --------------------------------------------------------  // acclient.c:792674
int _E77_11()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_28;
  dword_845F58 = LOWEST_DATA_RATE_28;
  return result;
}

//----- (00705670) --------------------------------------------------------  // acclient.c:792684
int sub_705670()
{
  return atexit(nullsub_1213);
}

