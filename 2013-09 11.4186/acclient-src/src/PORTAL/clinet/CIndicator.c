/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CIndicator
   Object     : PORTAL\clinet\CIndicator.obj
   Functions  : 19
   Addresses  : 00549FA0 - 00705730 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00549FA0) --------------------------------------------------------  // acclient.c:377557
void __thiscall HashBaseIter<unsigned __int64>::DeleteCurrent(HashBaseIter<unsigned __int64> *this)
{
  HashBaseIter<unsigned __int64> *v1; // esi@1
  HashBaseData<unsigned __int64> *v2; // eax@2
  HashBaseData<unsigned __int64> *v3; // ecx@2
  HashBaseData<unsigned __int64> *v4; // edi@3
  HashBaseData<unsigned __int64> *v5; // ecx@5
  HashBase<unsigned __int64> *v6; // ecx@8
  int v7; // edi@9

  v1 = this;
  if ( !this->fEnd_ )
  {
    v2 = this->lastThisChain_;
    v3 = this->curPtr_;
    if ( v2 )
    {
      v2->hash_next = v3->hash_next;
      v4 = v1->lastThisChain_->hash_next;
    }
    else
    {
      v1->myHash_->buckets[v1->curBucket_] = v3->hash_next;
      v4 = v1->myHash_->buckets[v1->curBucket_];
    }
    v5 = v1->curPtr_;
    if ( v5 )
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    if ( v4 )
    {
LABEL_11:
      v1->curPtr_ = v4;
    }
    else
    {
      v6 = v1->myHash_;
      while ( 1 )
      {
        v7 = v1->curBucket_ + 1;
        v1->lastThisChain_ = 0;
        v1->curBucket_ = v7;
        if ( v7 >= v6->table_size )
          break;
        v4 = v6->buckets[v7];
        if ( v4 )
          goto LABEL_11;
      }
      v1->fEnd_ = 1;
      v1->curPtr_ = 0;
    }
  }
}

//----- (0054A030) --------------------------------------------------------  // acclient.c:377611
void __thiscall HashBaseIter<unsigned __int64>::Next(HashBaseIter<unsigned __int64> *this)
{
  HashBaseData<unsigned __int64> *v1; // eax@1
  HashBase<unsigned __int64> *v2; // edx@4
  unsigned int v3; // eax@5
  HashBaseData<unsigned __int64> *v4; // eax@6

  v1 = this->curPtr_;
  if ( v1 )
  {
    this->lastThisChain_ = v1;
    this->curPtr_ = v1->hash_next;
  }
  if ( !this->curPtr_ )
  {
    v2 = this->myHash_;
    while ( 1 )
    {
      v3 = this->curBucket_ + 1;
      this->lastThisChain_ = 0;
      this->curBucket_ = v3;
      if ( v3 >= v2->table_size )
        break;
      v4 = v2->buckets[v3];
      this->curPtr_ = v4;
      if ( v4 )
        return;
    }
    this->fEnd_ = 1;
  }
}

//----- (0054A080) --------------------------------------------------------  // acclient.c:377644
HashBaseData<unsigned __int64> *__thiscall HashBase<unsigned __int64>::remove(HashBase<unsigned __int64> *this, unsigned __int64 key)
{
  unsigned int v2; // ebx@1
  HashBase<unsigned __int64> *v3; // esi@1
  unsigned __int64 v4; // rax@1
  HashBaseData<unsigned __int64> **v5; // ecx@1
  HashBaseData<unsigned __int64> *result; // eax@1
  HashBaseData<unsigned __int64> *v7; // ecx@5
  HashBaseData<unsigned __int64> *v8; // ecx@8
  int bucketNum_4; // [sp+14h] [bp+8h]@1

  v2 = HIDWORD(key);
  v3 = this;
  v4 = key >> this->key_shift;
  v5 = &v3->buckets[LODWORD(v3->table_mask) & (key ^ v4)];
  result = *v5;
  bucketNum_4 = HIDWORD(v3->table_mask) & (HIDWORD(key) ^ HIDWORD(v4));
  if ( !*v5 )
    goto LABEL_7;
  if ( result->id == __PAIR__(v2, (unsigned int)key) )
  {
    *v5 = result->hash_next;
    return result;
  }
  if ( result->hash_next )
  {
    while ( 1 )
    {
      v7 = result->hash_next;
      if ( v7->id == __PAIR__(v2, (unsigned int)key) )
        break;
      result = result->hash_next;
      if ( !v7->hash_next )
        goto LABEL_7;
    }
    v8 = result->hash_next;
    result->hash_next = v8->hash_next;
    result = v8;
  }
  else
  {
LABEL_7:
    result = 0;
  }
  return result;
}

//----- (0054A110) --------------------------------------------------------  // acclient.c:377692
HashBaseData<unsigned __int64> *__thiscall HashBase<unsigned __int64>::lookup(HashBase<unsigned __int64> *this, unsigned __int64 key)
{
  HashBaseData<unsigned __int64> *result; // eax@1

  result = this->buckets[LODWORD(this->table_mask) & (key ^ (key >> this->key_shift))];
  if ( result )
  {
    while ( key != result->id )
    {
      result = result->hash_next;
      if ( !result )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (0054A160) --------------------------------------------------------  // acclient.c:377715
void __thiscall UI64Hash<NetBlob>::add(UI64Hash<NetBlob> *this, NetBlob *data)
{
  char *v2; // edi@2
  __int64 v3; // rax@4
  int v4; // ST14_4@4

  if ( data )
    v2 = (char *)&data->vfptr;
  else
    v2 = 0;
  v3 = *((_QWORD *)v2 + 2) >> this->key_shift;
  LODWORD(v3) = LODWORD(this->table_mask) & (*((_DWORD *)v2 + 4) ^ v3);
  v4 = HIDWORD(this->table_mask) & (*((_DWORD *)v2 + 5) ^ HIDWORD(v3));
  *((_DWORD *)v2 + 2) = this->buckets[v3];
  this->buckets[v3] = (HashBaseData<unsigned __int64> *)v2;
}

//----- (0054A1C0) --------------------------------------------------------  // acclient.c:377733
UI64Hash<ArrivedEphInfo> *__thiscall UI64Hash<NetBlob>::vector_deleting_destructor(UI64Hash<ArrivedEphInfo> *this, unsigned int a2)
{
  UI64Hash<ArrivedEphInfo> *v2; // esi@1
  int v3; // eax@1

  v2 = this;
  v3 = this->fPlacementNew_;
  this->vfptr = (HashBase<unsigned __int64>Vtbl *)UI64Hash<NetBlob>::vftable;
  if ( !v3 )
    operator delete[](this->buckets);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7CA79C: using guessed type int (__thiscall *UI64Hash<NetBlob>::vftable[2])(void *, char);

//----- (0054A200) --------------------------------------------------------  // acclient.c:377750
void __thiscall Indicator::SendBlobToQueue(Indicator *this, NetBlob *toSend)
{
  PacketController *v2; // eax@1

  HashBase<unsigned __int64>::remove((HashBase<unsigned __int64> *)&this->waitingBlobs_.vfptr, toSend->id);
  toSend->id = toSend->savedNetBlobID_;
  NetBlob::ReceiveBlobReady(toSend);
  v2 = PacketController::Instance();
  PacketController::AddReceivedBlobToQueue(v2, toSend);
  if ( !InterlockedDecrement((volatile LONG *)&toSend->m_cRef) )
    toSend->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)toSend, 1u);
}

//----- (0054A250) --------------------------------------------------------  // acclient.c:377764
void __thiscall Indicator::Indicator(Indicator *this)
{
  Indicator *v1; // esi@1
  signed int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // edi@2
  int v5; // edx@2
  int v6; // edi@2
  unsigned int v7; // eax@4
  signed int v8; // eax@6
  unsigned int v9; // ecx@6
  int v10; // edi@7
  int v11; // edx@7
  int v12; // edi@7
  unsigned int v13; // eax@9

  v1 = this;
  this->vfptr = (IndicatorVtbl *)&Indicator::vftable;
  this->waitingBlobs_.vfptr = (HashBase<unsigned __int64>Vtbl *)UI64Hash<NetBlob>::vftable;
  this->waitingBlobs_.fPlacementNew_ = 0;
  this->waitingBlobs_.buckets = (HashBaseData<unsigned __int64> **)operator new[](0x200u);
  v1->waitingBlobs_.table_size = 128;
  v1->waitingBlobs_.key_shift = 16;
  LODWORD(v1->waitingBlobs_.table_mask) = 0;
  HIDWORD(v1->waitingBlobs_.table_mask) = 0;
  v2 = 1;
  v3 = 0;
  do
  {
    v4 = v2 | LODWORD(v1->waitingBlobs_.table_mask);
    v5 = v3 | HIDWORD(v1->waitingBlobs_.table_mask);
    v3 = __PAIR__(v3, v2) >> 31;
    v2 *= 2;
    HIDWORD(v1->waitingBlobs_.table_mask) = v5;
    LODWORD(v1->waitingBlobs_.table_mask) = v4;
    v6 = v2 | v4;
  }
  while ( (v3 | v5) <= 0 && v6 < v1->waitingBlobs_.table_size );
  v7 = 0;
  do
    v1->waitingBlobs_.buckets[v7++] = 0;
  while ( v7 < v1->waitingBlobs_.table_size );
  v1->waitingBlobs_.vfptr = (HashBase<unsigned __int64>Vtbl *)UI64Hash<NetBlob>::vftable;
  v1->arrivedEphBlobs_.vfptr = (HashBase<unsigned __int64>Vtbl *)UI64Hash<NetBlob>::vftable;
  v1->arrivedEphBlobs_.fPlacementNew_ = 0;
  v1->arrivedEphBlobs_.buckets = (HashBaseData<unsigned __int64> **)operator new[](0x80u);
  v1->arrivedEphBlobs_.table_size = 32;
  v1->arrivedEphBlobs_.key_shift = 16;
  LODWORD(v1->arrivedEphBlobs_.table_mask) = 0;
  HIDWORD(v1->arrivedEphBlobs_.table_mask) = 0;
  v8 = 1;
  v9 = 0;
  do
  {
    v10 = v8 | LODWORD(v1->arrivedEphBlobs_.table_mask);
    v11 = v9 | HIDWORD(v1->arrivedEphBlobs_.table_mask);
    v9 = __PAIR__(v9, v8) >> 31;
    v8 *= 2;
    HIDWORD(v1->arrivedEphBlobs_.table_mask) = v11;
    LODWORD(v1->arrivedEphBlobs_.table_mask) = v10;
    v12 = v8 | v10;
  }
  while ( (v9 | v11) <= 0 && v12 < v1->arrivedEphBlobs_.table_size );
  v13 = 0;
  do
    v1->arrivedEphBlobs_.buckets[v13++] = 0;
  while ( v13 < v1->arrivedEphBlobs_.table_size );
  v1->arrivedEphBlobs_.vfptr = (HashBase<unsigned __int64>Vtbl *)UI64Hash<NetBlob>::vftable;
  v1->firstInfo_ = 0;
  LODWORD(v1->flushStamp_) = 0;
  HIDWORD(v1->flushStamp_) = 0;
}
// 7CA79C: using guessed type int (__thiscall *UI64Hash<NetBlob>::vftable[2])(void *, char);
// 7CA7A0: using guessed type int (__thiscall *Indicator::vftable)(void *, char);

//----- (0054A370) --------------------------------------------------------  // acclient.c:377840
void __thiscall Indicator::AddArrivedEphInfo(Indicator *this, ArrivedEphInfo *info)
{
  unsigned __int64 v2; // rax@1
  int v3; // ST14_4@1
  ArrivedEphInfo *v4; // eax@1

  v2 = info->id >> this->arrivedEphBlobs_.key_shift;
  LODWORD(v2) = LODWORD(this->arrivedEphBlobs_.table_mask) & (LODWORD(info->id) ^ v2);
  v3 = HIDWORD(this->arrivedEphBlobs_.table_mask) & (HIDWORD(info->id) ^ HIDWORD(v2));
  info->hash_next = this->arrivedEphBlobs_.buckets[v2];
  this->arrivedEphBlobs_.buckets[v2] = (HashBaseData<unsigned __int64> *)info;
  v4 = this->firstInfo_;
  if ( v4 )
    info->m_next = v4;
  this->firstInfo_ = info;
}

//----- (0054A3D0) --------------------------------------------------------  // acclient.c:377858
void __thiscall Indicator::FlushTimedOutEphInfo(Indicator *this)
{
  Indicator *v1; // ebx@1
  unsigned int v2; // ecx@2
  ArrivedEphInfo *v3; // edi@2
  ArrivedEphInfo *v4; // ebp@2
  ArrivedEphInfo *v5; // esi@3

  v1 = this;
  if ( COERCE_DOUBLE(Timer::cur_time.Cmd) - this->flushStamp_ >= 5.0 )
  {
    v2 = Timer::cur_time.Param;
    v3 = v1->firstInfo_;
    v4 = 0;
    LODWORD(v1->flushStamp_) = Timer::cur_time.Cmd;
    HIDWORD(v1->flushStamp_) = v2;
    while ( v3 )
    {
      v5 = v3;
      v3 = v3->m_next;
      if ( (unsigned __int8)ArrivedEphInfo::fTimedOut(v5) )
      {
        if ( v4 )
          v4->m_next = v3;
        else
          v1->firstInfo_ = v3;
        HashBase<unsigned __int64>::remove((HashBase<unsigned __int64> *)&v1->arrivedEphBlobs_.vfptr, v5->id);
        v5->vfptr->__vecDelDtor((HashBaseData<unsigned __int64> *)v5, 1u);
      }
      else
      {
        v4 = v5;
      }
    }
  }
}

//----- (0054A450) --------------------------------------------------------  // acclient.c:377896
int __thiscall Indicator::FragIsObsoleteEmphemeral(Indicator *this, unsigned __int64 _netBlobID)
{
  Indicator *v2; // ebx@1
  int result; // eax@2
  unsigned __int64 v4; // rax@3
  unsigned __int64 v5; // kr08_8@3
  HashBaseData<unsigned __int64> *v6; // eax@3
  HashBaseData<unsigned __int64> *v7; // ebx@3
  ArrivedEphInfo *v8; // eax@4
  ArrivedEphInfo *v9; // eax@5
  HashBaseData<unsigned __int64> *v10; // eax@7
  unsigned int v11; // ecx@7
  Indicator *v12; // [sp+0h] [bp-4h]@1

  v2 = this;
  v12 = this;
  if ( !(unsigned __int8)NetBlobIDUtils::IsEphemeralFlagSet(_netBlobID) )
    return 0;
  v4 = NetBlobIDUtils::GetSequenceID(_netBlobID);
  v5 = v4;
  v6 = HashBase<unsigned __int64>::lookup((HashBase<unsigned __int64> *)&v2->arrivedEphBlobs_.vfptr, v4);
  v7 = v6;
  if ( v6 )
  {
    v10 = v6[1].hash_next;
    v11 = *((_DWORD *)&v7[1].hash_next + 1);
    if ( _netBlobID != __PAIR__(v11, (unsigned int)v10) )
    {
      if ( NetBlobIDUtils::LHSNewerOrderingStamp(__PAIR__(v11, (unsigned int)v10), _netBlobID) )
        return 1;
      ArrivedEphInfo::UpdateNetBlobID((ArrivedEphInfo *)v7, _netBlobID);
    }
    result = 0;
  }
  else
  {
    v8 = (ArrivedEphInfo *)operator new(0x30u);
    if ( v8 )
    {
      ArrivedEphInfo::ArrivedEphInfo(v8, v5, _netBlobID);
      Indicator::AddArrivedEphInfo(v12, v9);
      result = 0;
    }
    else
    {
      Indicator::AddArrivedEphInfo(v12, 0);
      result = 0;
    }
  }
  return result;
}

//----- (0054A520) --------------------------------------------------------  // acclient.c:377949
void __thiscall UI64Hash<ArrivedEphInfo>::destroy_contents(UI64Hash<ArrivedEphInfo> *this)
{
  HashBaseData<unsigned __int64> *v1; // eax@2
  UI64HashIter<ArrivedEphInfo> iter; // [sp+0h] [bp-14h]@1

  iter.myHash_ = (HashBase<unsigned __int64> *)this;
  iter.lastThisChain_ = 0;
  iter.curBucket_ = 0;
  if ( this )
  {
    v1 = *this->buckets;
    iter.fEnd_ = 0;
    iter.curPtr_ = v1;
    if ( v1 || (HashBaseIter<unsigned __int64>::Next((HashBaseIter<unsigned __int64> *)&iter.myHash_), !iter.fEnd_) )
    {
      do
        HashBaseIter<unsigned __int64>::DeleteCurrent((HashBaseIter<unsigned __int64> *)&iter.myHash_);
      while ( !iter.fEnd_ );
    }
  }
}

//----- (0054A580) --------------------------------------------------------  // acclient.c:377972
void __thiscall Indicator::CleanupWaitingBlobs(Indicator *this)
{
  char *v1; // edi@1
  HashBaseData<unsigned __int64> *i; // eax@2
  int v3; // esi@8
  UI64HashIter<NetBlob> iter; // [sp+8h] [bp-14h]@1

  v1 = (char *)&this->waitingBlobs_;
  iter.myHash_ = (HashBase<unsigned __int64> *)&this->waitingBlobs_.vfptr;
  iter.lastThisChain_ = 0;
  iter.curBucket_ = 0;
  if ( this != (Indicator *)-8 )
  {
    i = *this->waitingBlobs_.buckets;
    iter.fEnd_ = 0;
    iter.curPtr_ = i;
    if ( i )
      goto LABEL_7;
    HashBaseIter<unsigned __int64>::Next((HashBaseIter<unsigned __int64> *)&iter.myHash_);
    if ( !iter.fEnd_ )
    {
LABEL_7:
      for ( i = iter.curPtr_; !i; i = iter.curPtr_ )
      {
        v3 = 0;
LABEL_10:
        HashBase<unsigned __int64>::remove((HashBase<unsigned __int64> *)v1, *(_QWORD *)(v3 + 32));
        if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
        iter.myHash_ = (HashBase<unsigned __int64> *)v1;
        iter.lastThisChain_ = 0;
        iter.curBucket_ = 0;
        if ( !v1 )
          return;
        i = (HashBaseData<unsigned __int64> *)**((_DWORD **)v1 + 5);
        iter.fEnd_ = 0;
        iter.curPtr_ = i;
        if ( i )
          break;
        HashBaseIter<unsigned __int64>::Next((HashBaseIter<unsigned __int64> *)&iter.myHash_);
        if ( iter.fEnd_ )
          return;
      }
      v3 = (int)&i[-1].hash_next;
      goto LABEL_10;
    }
  }
}

//----- (0054A640) --------------------------------------------------------  // acclient.c:378022
void __thiscall Indicator::AcceptFrag(Indicator *this, BlobFrag *newFrag, unsigned __int16 sender)
{
  BlobFrag *v3; // edi@1
  BlobFragHeader_t *v4; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ebp@1
  Indicator *v7; // esi@1
  unsigned __int64 v8; // kr00_8@2
  HashBaseData<unsigned __int64> *v9; // eax@3
  int v10; // esi@4
  unsigned __int64 v11; // rax@5
  unsigned int v12; // ecx@5
  unsigned int v13; // edi@5
  volatile LONG *v14; // edi@6
  NetBlob *v15; // eax@11
  int v16; // eax@12
  BlobFragHeader_t *v17; // ecx@14
  bool v18; // zf@15
  Indicator *v19; // [sp+10h] [bp-4h]@1

  v3 = newFrag;
  v4 = newFrag->hdrRead_;
  v5 = LODWORD(v4->blobID);
  v6 = HIDWORD(v4->blobID);
  v7 = this;
  v19 = this;
  if ( (unsigned __int8)NetBlobIDUtils::IsEphemeralFlagSet(v4->blobID) )
  {
    v8 = NetBlobIDUtils::GetSequenceID(__PAIR__(v6, v5));
    v6 = HIDWORD(v8);
    v5 = v8;
  }
  v9 = HashBase<unsigned __int64>::lookup((HashBase<unsigned __int64> *)&v7->waitingBlobs_.vfptr, __PAIR__(v6, v5));
  if ( v9 )
  {
    v10 = (int)&v9[-1].hash_next;
    if ( v9 != (HashBaseData<unsigned __int64> *)16 )
    {
      v11 = newFrag->hdrRead_->blobID;
      v12 = *(_DWORD *)(v10 + 72);
      v13 = *(_DWORD *)(v10 + 76);
      if ( __PAIR__(v13, v12) == v11 )
      {
        v14 = (volatile LONG *)(v10 + 4);
        InterlockedIncrement((volatile LONG *)(v10 + 4));
        goto LABEL_15;
      }
      if ( !NetBlobIDUtils::LHSNewerOrderingStamp(__PAIR__(v13, v12), v11) )
        return;
      HashBase<unsigned __int64>::remove((HashBase<unsigned __int64> *)&v19->waitingBlobs_.vfptr, __PAIR__(v6, v5));
      if ( !InterlockedDecrement((volatile LONG *)(v10 + 4)) )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      v3 = newFrag;
    }
  }
  v15 = (NetBlob *)operator new(0x50u);
  if ( v15 )
  {
    NetBlob::NetBlob(v15);
    v10 = v16;
  }
  else
  {
    v10 = 0;
  }
  *(_WORD *)(v10 + 60) = sender;
  *(_WORD *)(v10 + 62) = v3->hdrRead_->queueID;
  v17 = v3->hdrRead_;
  *(_DWORD *)(v10 + 72) = LODWORD(v17->blobID);
  v14 = (volatile LONG *)(v10 + 4);
  *(_DWORD *)(v10 + 76) = HIDWORD(v17->blobID);
  *(_DWORD *)(v10 + 32) = v5;
  *(_DWORD *)(v10 + 36) = v6;
  InterlockedIncrement((volatile LONG *)(v10 + 4));
  UI64Hash<NetBlob>::add(&v19->waitingBlobs_, (NetBlob *)v10);
LABEL_15:
  NetBlob::ReceiveAddFragment((NetBlob *)v10, newFrag);
  v18 = *(_DWORD *)(v10 + 56) == *(_DWORD *)(v10 + 52);
  *(_DWORD *)(v10 + 32) = v5;
  *(_DWORD *)(v10 + 36) = v6;
  if ( v18 )
    Indicator::SendBlobToQueue(v19, (NetBlob *)v10);
  if ( !InterlockedDecrement(v14) )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
}

//----- (0054A790) --------------------------------------------------------  // acclient.c:378109
void __thiscall Indicator::~Indicator(Indicator *this)
{
  Indicator *v1; // esi@1
  int v2; // eax@1
  int v3; // eax@3

  v1 = this;
  this->vfptr = (IndicatorVtbl *)&Indicator::vftable;
  Indicator::CleanupWaitingBlobs(this);
  UI64Hash<ArrivedEphInfo>::destroy_contents(&v1->arrivedEphBlobs_);
  v2 = v1->arrivedEphBlobs_.fPlacementNew_;
  v1->arrivedEphBlobs_.vfptr = (HashBase<unsigned __int64>Vtbl *)UI64Hash<NetBlob>::vftable;
  if ( !v2 )
    operator delete[](v1->arrivedEphBlobs_.buckets);
  v3 = v1->waitingBlobs_.fPlacementNew_;
  v1->waitingBlobs_.vfptr = (HashBase<unsigned __int64>Vtbl *)UI64Hash<NetBlob>::vftable;
  if ( !v3 )
    operator delete[](v1->waitingBlobs_.buckets);
}
// 7CA79C: using guessed type int (__thiscall *UI64Hash<NetBlob>::vftable[2])(void *, char);
// 7CA7A0: using guessed type int (__thiscall *Indicator::vftable)(void *, char);

//----- (0054A7E0) --------------------------------------------------------  // acclient.c:378132
void __thiscall Indicator::CheckInPacket(Indicator *this, NetPacket *packet, unsigned __int16 sender)
{
  Indicator *v3; // ebx@1
  char *v4; // edi@2
  unsigned int v5; // ebp@2
  BlobFrag *v6; // esi@3

  v3 = this;
  if ( (signed int)packet->numFrags_ > 0 )
  {
    v4 = (char *)packet->fragList_;
    v5 = packet->numFrags_;
    do
    {
      v6 = *(BlobFrag **)v4;
      if ( !Indicator::FragIsObsoleteEmphemeral(v3, *(_QWORD *)*(_DWORD *)(*(_DWORD *)v4 + 16)) )
        Indicator::AcceptFrag(v3, v6, sender);
      v4 += 4;
      --v5;
    }
    while ( v5 );
  }
}

//----- (0054A840) --------------------------------------------------------  // acclient.c:378157
Indicator *__thiscall Indicator::vector_deleting_destructor(Indicator *this, unsigned int a2)
{
  Indicator *v2; // esi@1

  v2 = this;
  Indicator::~Indicator(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00705720) --------------------------------------------------------  // acclient.c:792770
int _E77_17()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_34;
  dword_845FA4 = LOWEST_DATA_RATE_34;
  return result;
}

//----- (00705730) --------------------------------------------------------  // acclient.c:792780
int sub_705730()
{
  return atexit(nullsub_1212);
}

