/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SentPacket
   Object     : PORTAL\clinet\SentPacket.obj
   Functions  : 19
   Addresses  : 004C59B0 - 00705750 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004C59B0) --------------------------------------------------------  // acclient.c:247389
void __thiscall NIList<unsigned long>::DeleteContents(NIList<NetPacket *> *this)
{
  NIList<NetPacket *> *v1; // edi@1
  NIListElement<NetPacket *> *v2; // esi@1
  void *v3; // eax@2

  v1 = this;
  v2 = this->head_;
  if ( this->head_ )
  {
    do
    {
      v3 = v2;
      v2 = v2->next_;
      operator delete(v3);
    }
    while ( v2 );
  }
  v1->head_ = 0;
  v1->tail_ = 0;
}

//----- (0053F400) --------------------------------------------------------  // acclient.c:366480
IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *__thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::find_internal(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *this, IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *result, const unsigned __int64 *_key)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *v3; // esi@1
  HashTableData<unsigned __int64,unsigned __int64> **v4; // edx@1
  HashTableData<unsigned __int64,unsigned __int64> *i; // ecx@1
  IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *v6; // eax@5

  v3 = this;
  v4 = &this->m_buckets[*_key % this->m_numBuckets];
  for ( i = *v4; i; i = i->m_hashNext )
  {
    if ( LODWORD(i->m_hashKey) == *(_DWORD *)_key && HIDWORD(i->m_hashKey) == *((_DWORD *)_key + 1) )
      break;
  }
  v6 = result;
  result->m_currHashTable = v3;
  result->m_currBucket = v4;
  result->m_currElement = i;
  return v6;
}

//----- (0053FB20) --------------------------------------------------------  // acclient.c:366988
void __thiscall IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::remove(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *this, IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> iter)
{
  HashTableData<unsigned __int64,unsigned __int64> *v2; // eax@1
  HashTableData<unsigned __int64,unsigned __int64> *v3; // edx@2

  v2 = *iter.m_currBucket;
  if ( *iter.m_currBucket == iter.m_currElement )
    goto LABEL_8;
  do
  {
    v3 = v2;
    v2 = v2->m_hashNext;
  }
  while ( v2 != iter.m_currElement );
  if ( v3 )
  {
    v3->m_hashNext = v2->m_hashNext;
    --this->m_numElements;
  }
  else
  {
LABEL_8:
    *iter.m_currBucket = v2->m_hashNext;
    --this->m_numElements;
  }
}

//----- (0053FE70) --------------------------------------------------------  // acclient.c:367266
HashTableData<unsigned __int64,unsigned __int64> *__thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::remove(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *this, const unsigned __int64 *key)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *v2; // esi@1
  HashTableData<unsigned __int64,unsigned __int64> *v3; // edi@1
  _BYTE v4[12]; // ST00_12@2
  HashTableData<unsigned __int64,unsigned __int64> *result; // eax@2
  IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> iter; // [sp+Ch] [bp-Ch]@1

  v2 = this;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::find_internal(
    this,
    &iter,
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

//----- (0054A860) --------------------------------------------------------  // acclient.c:378169
IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *__thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *v2; // esi@1
  HashTableData<unsigned __int64,unsigned __int64> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>Vtbl *)IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::vftable;
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
// 7CA7CC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::vftable[2])(void *, char);

//----- (0054A8A0) --------------------------------------------------------  // acclient.c:378190
int __thiscall SentPacketStore::Contains(SentPacketStore *this, unsigned int seqID)
{
  NIListElement<NetPacket *> *i; // eax@1

  for ( i = this->m_sentPacketList.head_; i; i = i->next_ )
  {
    if ( i->data_->seqNum_ == seqID )
      return 1;
  }
  return 0;
}

//----- (0054A8D0) --------------------------------------------------------  // acclient.c:378203
NetPacket *__thiscall SentPacketStore::GenerateAck(SentPacketStore *this, unsigned int seqID)
{
  NIListElement<NetPacket *> *i; // eax@1
  NetPacket *v3; // esi@3

  for ( i = this->m_sentPacketList.head_; i; i = i->next_ )
  {
    v3 = i->data_;
    if ( i->data_->seqNum_ == seqID )
    {
      InterlockedIncrement((volatile LONG *)&v3->m_cRef);
      return v3;
    }
  }
  return 0;
}

//----- (0054A900) --------------------------------------------------------  // acclient.c:378221
void __thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>Vtbl *)IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned __int64,unsigned __int64> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned __int64,unsigned __int64> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7CA7CC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::vftable[2])(void *, char);

//----- (0054A990) --------------------------------------------------------  // acclient.c:378254
char __thiscall HashTable<unsigned __int64,unsigned __int64,0>::set(HashTable<unsigned __int64,unsigned __int64,0> *this, const unsigned __int64 *_key, const unsigned __int64 *_data)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *v3; // edi@1
  HashTableData<unsigned __int64,unsigned __int64> *v4; // eax@1
  char v5; // al@2
  void *v6; // eax@3
  IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> result; // [sp+8h] [bp-Ch]@1

  v3 = &this->m_intrusiveTable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::find_internal(
    &this->m_intrusiveTable,
    &result,
    _key);
  v4 = result.m_currElement;
  if ( result.m_currElement )
  {
    LODWORD(result.m_currElement->m_data) = *(_DWORD *)_data;
    HIDWORD(v4->m_data) = *((_DWORD *)_data + 1);
    v5 = 1;
  }
  else
  {
    v6 = operator new(0x18u);
    if ( v6 )
    {
      *(_QWORD *)v6 = *_key;
      *((_DWORD *)v6 + 2) = 0;
      *((_QWORD *)v6 + 2) = *_data;
      IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::add(
        v3,
        (HashTableData<unsigned __int64,unsigned __int64> *)v6);
      v5 = 1;
    }
    else
    {
      IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::add(
        v3,
        0);
      v5 = 1;
    }
  }
  return v5;
}

//----- (0054AA20) --------------------------------------------------------  // acclient.c:378299
HashTable<unsigned __int64,unsigned __int64,0> *__thiscall HashTable<unsigned __int64,unsigned __int64,0>::vector_deleting_destructor(HashTable<unsigned __int64,unsigned __int64,0> *this, unsigned int a2)
{
  HashTable<unsigned __int64,unsigned __int64,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned __int64,unsigned __int64,0>Vtbl *)&HashTable<unsigned __int64,unsigned __int64,0>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::vftable;
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
// 7CA7CC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::vftable[2])(void *, char);
// 7CA7D0: using guessed type int (__thiscall *HashTable<unsigned __int64,unsigned __int64,0>::vftable)(void *, char);

//----- (0054AA80) --------------------------------------------------------  // acclient.c:378325
void __thiscall SentPacketStore::SentPacketStore(SentPacketStore *this)
{
  this->m_sentPacketList.head_ = 0;
  this->m_sentPacketList.tail_ = 0;
  this->m_sentNetBlobIDInfo.vfptr = (HashTable<unsigned __int64,unsigned __int64,0>Vtbl *)&HashTable<unsigned __int64,unsigned __int64,0>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>(
    &this->m_sentNetBlobIDInfo.m_intrusiveTable,
    0x40u);
}
// 7CA7D0: using guessed type int (__thiscall *HashTable<unsigned __int64,unsigned __int64,0>::vftable)(void *, char);

//----- (0054AAB0) --------------------------------------------------------  // acclient.c:378337
void __thiscall SentPacketStore::~SentPacketStore(SentPacketStore *this)
{
  NIList<NetPacket *> *v1; // edi@1
  char *v2; // esi@1
  void *v3; // eax@1

  v1 = (NIList<NetPacket *> *)this;
  v2 = (char *)&this->m_sentNetBlobIDInfo.m_intrusiveTable;
  this->m_sentNetBlobIDInfo.vfptr = (HashTable<unsigned __int64,unsigned __int64,0>Vtbl *)&HashTable<unsigned __int64,unsigned __int64,0>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents(&this->m_sentNetBlobIDInfo.m_intrusiveTable);
  v3 = (void *)*((_DWORD *)v2 + 24);
  *(_DWORD *)v2 = IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::vftable;
  if ( v3 != v2 + 4 )
    operator delete[](v3);
  *((_DWORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 25) = 0;
  *((_DWORD *)v2 + 26) = 0;
  *((_DWORD *)v2 + 27) = 0;
  NIList<unsigned long>::DeleteContents(v1);
}
// 7CA7CC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::vftable[2])(void *, char);
// 7CA7D0: using guessed type int (__thiscall *HashTable<unsigned __int64,unsigned __int64,0>::vftable)(void *, char);

//----- (0054AB00) --------------------------------------------------------  // acclient.c:378361
int __thiscall SentPacketStore::AddSentPacket(SentPacketStore *this, NetPacket *packet)
{
  NetPacket *v2; // edi@1
  SentPacketStore *v3; // esi@1
  void *v4; // eax@1
  NIListElement<NetPacket *> *v5; // ecx@4
  int v6; // eax@9
  unsigned int v7; // ebx@9
  unsigned int v8; // ebp@9
  unsigned __int64 v9; // ST08_8@9
  unsigned __int64 v10; // ST08_8@10
  int v11; // esi@10
  unsigned __int64 v12; // rax@10
  bool v13; // cf@19
  SentPacketStore *v15; // [sp+Ch] [bp-1Ch]@1
  char *v16; // [sp+10h] [bp-18h]@8
  unsigned int i; // [sp+14h] [bp-14h]@7
  unsigned __int64 id; // [sp+18h] [bp-10h]@9
  unsigned __int64 seq; // [sp+20h] [bp-8h]@10

  v2 = packet;
  v3 = this;
  v15 = this;
  InterlockedIncrement((volatile LONG *)&packet->m_cRef);
  v4 = operator new(8u);
  if ( v4 )
  {
    *(_DWORD *)v4 = packet;
    *((_DWORD *)v4 + 1) = 0;
  }
  else
  {
    v4 = 0;
  }
  v5 = v3->m_sentPacketList.tail_;
  if ( v5 )
  {
    v5->next_ = (NIListElement<NetPacket *> *)v4;
    v3->m_sentPacketList.tail_ = v3->m_sentPacketList.tail_->next_;
  }
  else
  {
    v3->m_sentPacketList.head_ = (NIListElement<NetPacket *> *)v4;
    v3->m_sentPacketList.tail_ = (NIListElement<NetPacket *> *)v4;
  }
  NetPacket::RemoveDisposableOptionalHeaders(packet);
  i = 0;
  if ( packet->numFrags_ )
  {
    v16 = (char *)packet->fragList_;
    do
    {
      v6 = *(_DWORD *)(*(_DWORD *)v16 + 16);
      v7 = *(_DWORD *)v6;
      v8 = *(_DWORD *)(v6 + 4);
      v9 = *(_QWORD *)v6;
      LODWORD(id) = *(_DWORD *)v6;
      HIDWORD(id) = v8;
      if ( (unsigned __int8)NetBlobIDUtils::IsEphemeralFlagSet(v9) )
      {
        v12 = NetBlobIDUtils::GetSequenceID(__PAIR__(v8, v7));
        v10 = v15->m_sentNetBlobIDInfo.m_intrusiveTable.m_numBuckets;
        v11 = v12;
        seq = v12;
        LODWORD(v12) = v15->m_sentNetBlobIDInfo.m_intrusiveTable.m_buckets[v12 % v10];
        if ( !(_DWORD)v12 )
          goto LABEL_17;
        while ( *(_DWORD *)v12 != v11 || *(_DWORD *)(v12 + 4) != HIDWORD(v12) )
        {
          LODWORD(v12) = *(_DWORD *)(v12 + 8);
          if ( !(_DWORD)v12 )
            goto LABEL_17;
        }
        if ( !(_DWORD)v12 || NetBlobIDUtils::LHSNewerOrderingStamp(__PAIR__(v8, v7), *(_QWORD *)(v12 + 16)) )
LABEL_17:
          HashTable<unsigned __int64,unsigned __int64,0>::set(&v15->m_sentNetBlobIDInfo, &seq, &id);
        v2 = packet;
      }
      v13 = i++ + 1 < v2->numFrags_;
      v16 += 4;
    }
    while ( v13 );
  }
  return 1;
}

//----- (0054AC50) --------------------------------------------------------  // acclient.c:378448
void __thiscall SentPacketStore::EraseNetBlobID(SentPacketStore *this, unsigned __int64 _id)
{
  unsigned int v2; // ebx@1
  unsigned int v3; // esi@1
  SentPacketStore *v4; // edi@1
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *v5; // edi@2
  HashTableData<unsigned __int64,unsigned __int64> *v6; // eax@5
  IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> result; // [sp+Ch] [bp-Ch]@2

  v2 = HIDWORD(_id);
  v3 = _id;
  v4 = this;
  if ( (unsigned __int8)NetBlobIDUtils::IsEphemeralFlagSet(_id) )
  {
    _id = NetBlobIDUtils::GetSequenceID(__PAIR__(v2, v3));
    v5 = &v4->m_sentNetBlobIDInfo.m_intrusiveTable;
    IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::find_internal(
      v5,
      &result,
      &_id);
    if ( result.m_currElement )
    {
      if ( v3 == LODWORD(result.m_currElement->m_data) && v2 == HIDWORD(result.m_currElement->m_data) )
      {
        v6 = IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::remove(v5, &_id);
        if ( v6 )
          operator delete(v6);
      }
    }
  }
}

//----- (0054ACD0) --------------------------------------------------------  // acclient.c:378481
int __thiscall SentPacketStore::Flush(SentPacketStore *this, unsigned int highest, int everything)
{
  SentPacketStore *v3; // ebp@1
  NIListElement<NetPacket *> *i; // edi@1
  NetPacket *v5; // ebx@4
  unsigned int v6; // ecx@5
  unsigned int v7; // eax@6
  int v8; // edx@6
  NIListElement<NetPacket *> *v9; // ecx@11
  NIListElement<NetPacket *> *v10; // eax@12
  unsigned int v11; // esi@15
  int v12; // edi@16
  NIListElement<NetPacket *> *iter_4; // [sp+14h] [bp-8h]@11

  v3 = this;
  for ( i = this->m_sentPacketList.head_; i; i = iter_4 )
  {
    v5 = i->data_;
    if ( !everything )
    {
      v6 = v5->seqNum_;
      if ( v6 == highest )
        break;
      v7 = v6 - highest;
      v8 = 1;
      if ( v6 < highest )
      {
        v7 = highest - v6;
        v8 = -1;
      }
      if ( v7 > 0x7FFFFFFF )
        v8 = -v8;
      if ( v8 >= 0 )
        break;
    }
    v9 = v3->m_sentPacketList.head_;
    iter_4 = i->next_;
    if ( v3->m_sentPacketList.head_ )
    {
      v10 = v9->next_;
      v3->m_sentPacketList.head_ = v10;
      if ( !v10 )
        v3->m_sentPacketList.tail_ = 0;
      operator delete(v9);
    }
    v11 = 0;
    if ( v5->numFrags_ )
    {
      v12 = (int)v5->fragList_;
      do
      {
        SentPacketStore::EraseNetBlobID(v3, *(_QWORD *)*(_DWORD *)(*(_DWORD *)v12 + 16));
        ++v11;
        v12 += 4;
      }
      while ( v11 < v5->numFrags_ );
    }
    if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) )
      v5->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 1u);
  }
  return 1;
}

//----- (00693470) --------------------------------------------------------  // acclient.c:683122
char __thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::add(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *this, HashTableData<unsigned __int64,unsigned __int64> *data)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *v2; // esi@1
  char v3; // al@2
  unsigned __int64 v4; // rax@3
  HashTableData<unsigned __int64,unsigned __int64> **v5; // ecx@3
  HashTableData<unsigned __int64,unsigned __int64> **v6; // eax@3
  IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> result; // [sp+8h] [bp-Ch]@1

  v2 = this;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::find_internal(
    this,
    &result,
    &data->m_hashKey);
  if ( result.m_currElement )
  {
    v3 = 0;
  }
  else
  {
    v4 = data->m_hashKey % v2->m_numBuckets;
    v5 = v2->m_buckets;
    HIDWORD(v4) = v5[(_DWORD)v4];
    v6 = &v5[v4];
    data->m_hashNext = (HashTableData<unsigned __int64,unsigned __int64> *)HIDWORD(v4);
    *v6 = data;
    if ( v6 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = v6;
    ++v2->m_numElements;
    v3 = 1;
  }
  return v3;
}

//----- (006934D0) --------------------------------------------------------  // acclient.c:683157
void __thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *this)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned __int64,unsigned __int64> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned __int64,unsigned __int64> **v5; // edi@5
  void *v6; // ecx@5
  void *v7; // eax@7
  void *v8; // edx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned __int64,unsigned __int64> **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<unsigned __int64,unsigned __int64> **)v4;
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
      v7 = (void *)*((_DWORD *)v7 + 2);
    }
    while ( v7 != v6 );
    if ( v8 )
      *((_DWORD *)v8 + 2) = *((_DWORD *)v7 + 2);
    else
LABEL_17:
      *v5 = (HashTableData<unsigned __int64,unsigned __int64> *)*((_DWORD *)v7 + 2);
    --v1->m_numElements;
    if ( v6 )
      operator delete(v6);
  }
}

//----- (00705740) --------------------------------------------------------  // acclient.c:792786
int _E77_18()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_35;
  dword_845FB0 = LOWEST_DATA_RATE_35;
  return result;
}

//----- (00705750) --------------------------------------------------------  // acclient.c:792796
int sub_705750()
{
  return atexit(nullsub_1216);
}

