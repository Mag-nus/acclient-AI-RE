/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TSRecv
   Object     : PORTAL\timestamper\TSRecv.obj
   Functions  : 7
   Addresses  : 005AFE50 - 005B0220 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005AFE50) --------------------------------------------------------  // acclient.c:474588
void __thiscall TSRecv::TSRecv(TSRecv *this, TSRecvMode mode, unsigned int TSOverflowLimit)
{
  this->mode_ = mode;
  this->receivedFirstEntry_ = 0;
  this->overflowLimit_ = TSOverflowLimit;
  this->highestStamp_ = 0;
  this->head_.m_pNext = 0;
  this->head_.m_stamp = 0;
  this->head_.m_pObj = 0;
  this->numBlockedStamps_ = 0;
  *(_QWORD *)&this->blockedSince_ = 0i64;
}

//----- (005AFE80) --------------------------------------------------------  // acclient.c:474602
int __thiscall TSRecv::GetNextReadyEntry(TSRecv *this, unsigned int *pstampOut, ReferenceCountTemplate<1048576,0> **ppObjOut)
{
  TSRecv *v3; // edi@1
  TSBlockedEntry *v4; // esi@1
  unsigned int v5; // eax@2
  unsigned int v6; // ecx@2
  unsigned int v7; // edx@5
  TSBlockedEntry *v9; // edx@7
  ReferenceCountTemplate<1048576,0> *v10; // ebx@7
  int v11; // eax@11
  int v12; // eax@12

  v3 = this;
  *pstampOut = this->highestStamp_;
  *ppObjOut = 0;
  v4 = this->head_.m_pNext;
  if ( !v4 )
    return 0;
  v5 = v4->m_stamp;
  v6 = this->highestStamp_;
  if ( v5 != v6 && v5 != v6 + 1 )
  {
    if ( v3->numBlockedStamps_ )
    {
      v7 = Timer::cur_time.Param;
      LODWORD(v3->blockedSince_) = Timer::cur_time.Cmd;
      HIDWORD(v3->blockedSince_) = v7;
    }
    return 0;
  }
  *pstampOut = v4->m_stamp;
  *ppObjOut = v4->m_pObj;
  v9 = v4->m_pNext;
  v4->m_pObj = 0;
  v3->head_.m_pNext = v9;
  v3->highestStamp_ = v4->m_stamp;
  v10 = v4->m_pObj;
  if ( v10 && !InterlockedDecrement((volatile LONG *)&v10->m_cRef) && v10 )
    v10->vfptr->__vecDelDtor(v10, 1u);
  operator delete(v4);
  v11 = v3->numBlockedStamps_;
  if ( v11 )
  {
    v12 = v11 - 1;
    v3->numBlockedStamps_ = v12;
    if ( v12 < 0 )
      v3->numBlockedStamps_ = 0;
  }
  if ( !v3->numBlockedStamps_ )
  {
    LODWORD(v3->blockedSince_) = 0;
    HIDWORD(v3->blockedSince_) = 0;
  }
  return 1;
}

//----- (005AFF40) --------------------------------------------------------  // acclient.c:474659
void __thiscall TSRecv::~TSRecv(TSRecv *this)
{
  TSRecv *v1; // edi@1
  TSBlockedEntry *v2; // ebx@2
  ReferenceCountTemplate<1048576,0> *v3; // esi@2
  ReferenceCountTemplate<1048576,0> *v4; // edi@7

  v1 = this;
  while ( v1->head_.m_pNext )
  {
    v2 = v1->head_.m_pNext;
    v1->head_.m_pNext = v2->m_pNext;
    v3 = v2->m_pObj;
    if ( v3 && !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
      v3->vfptr->__vecDelDtor(v3, 1u);
    operator delete(v2);
  }
  v4 = v1->head_.m_pObj;
  if ( v4 && !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
  {
    if ( v4 )
      v4->vfptr->__vecDelDtor(v4, 1u);
  }
}

//----- (005AFFB0) --------------------------------------------------------  // acclient.c:474685
int __thiscall TSRecv::AddEntryLatest(TSRecv *this, unsigned int stampIn, ReferenceCountTemplate<1048576,0> *pObjIn, unsigned int *pstampOut, ReferenceCountTemplate<1048576,0> **ppObjOut)
{
  unsigned int v5; // eax@1
  unsigned int v6; // eax@1
  unsigned int v7; // esi@2
  int v8; // edi@2
  int result; // eax@7

  v5 = this->highestStamp_;
  this->receivedFirstEntry_ = 1;
  *pstampOut = v5;
  *ppObjOut = 0;
  v6 = this->highestStamp_;
  if ( stampIn == v6 )
    goto LABEL_11;
  v7 = stampIn - v6;
  v8 = 1;
  if ( stampIn < v6 )
  {
    v7 = v6 - stampIn;
    v8 = -1;
  }
  if ( v7 >= 0x7FFFFFFF )
    v8 = -v8;
  if ( v8 <= 0 )
  {
LABEL_11:
    result = 3;
  }
  else
  {
    this->highestStamp_ = stampIn;
    *pstampOut = stampIn;
    InterlockedIncrement((volatile LONG *)&pObjIn->m_cRef);
    *ppObjOut = pObjIn;
    result = 1;
  }
  return result;
}

//----- (005B0030) --------------------------------------------------------  // acclient.c:474726
void __thiscall TSRecv::AddEntry(TSRecv *this, unsigned int stampIn, ReferenceCountTemplate<1048576,0> *pObjIn, int *fRejected)
{
  TSRecv *v4; // ebp@1
  void *v5; // eax@1
  unsigned int v6; // esi@1
  int v7; // ebx@6
  int v8; // edi@6
  unsigned int v9; // esi@7
  unsigned int v10; // eax@8
  int v11; // ecx@9
  int v12; // edx@9
  unsigned int stampIna; // [sp+Ch] [bp+4h]@4

  v4 = this;
  v5 = operator new(0xCu);
  v6 = (unsigned int)v5;
  if ( v5 )
  {
    *((_DWORD *)v5 + 1) = stampIn;
    *(_DWORD *)v5 = 0;
    *((_DWORD *)v5 + 2) = pObjIn;
    if ( pObjIn )
      InterlockedIncrement((volatile LONG *)&pObjIn->m_cRef);
    stampIna = v6;
  }
  else
  {
    stampIna = 0;
  }
  v7 = (int)&v4->head_;
  v8 = (int)v4->head_.m_pNext;
  if ( v8 )
  {
    v9 = *(_DWORD *)(stampIna + 4);
    do
    {
      v10 = *(_DWORD *)(v8 + 4);
      if ( v9 == v10 )
        break;
      v11 = v9 - v10;
      v12 = 1;
      if ( v9 < v10 )
      {
        v11 = v10 - v9;
        v12 = -1;
      }
      if ( (unsigned int)v11 >= 0x7FFFFFFF )
        v12 = -v12;
      if ( v12 <= 0 )
        break;
      v7 = v8;
      v8 = *(_DWORD *)v8;
    }
    while ( v8 );
  }
  *(_DWORD *)stampIna = v8;
  *(_DWORD *)v7 = stampIna;
  if ( v4->numBlockedStamps_ < 0 )
    v4->numBlockedStamps_ = 0;
  ++v4->numBlockedStamps_;
}

//----- (005B00F0) --------------------------------------------------------  // acclient.c:474789
int __thiscall TSRecv::AddEntryBlocking(TSRecv *this, unsigned int stampIn, ReferenceCountTemplate<1048576,0> *pObjIn, unsigned int *pstampOut, ReferenceCountTemplate<1048576,0> **ppObjOut)
{
  ReferenceCountTemplate<1048576,0> **v5; // ebp@1
  TSRecv *v6; // esi@1
  unsigned int *v7; // edi@1
  int result; // eax@3
  unsigned int v9; // ecx@5
  ReferenceCountTemplate<1048576,0> *v10; // edx@7
  int v11; // ebx@7
  unsigned int v12; // edx@10
  unsigned int v13; // eax@14
  ReferenceCountTemplate<1048576,0> *v14; // esi@16
  bool v15; // zf@16

  v5 = ppObjOut;
  v6 = this;
  v7 = pstampOut;
  *pstampOut = this->highestStamp_;
  *v5 = 0;
  if ( this->receivedFirstEntry_ )
  {
    if ( stampIn <= this->highestStamp_ )
      return 3;
  }
  else
  {
    this->receivedFirstEntry_ = 1;
  }
  v9 = this->highestStamp_;
  if ( stampIn == v9 || stampIn == v9 + 1 )
  {
    v6->highestStamp_ = stampIn;
    v14 = pObjIn;
    v15 = pObjIn == 0;
    *v7 = stampIn;
    if ( !v15 )
      InterlockedIncrement((volatile LONG *)&v14->m_cRef);
    *v5 = v14;
    result = 1;
  }
  else
  {
    v10 = pObjIn;
    *v7 = v9;
    *v5 = 0;
    v11 = v6->numBlockedStamps_;
    pstampOut = 0;
    TSRecv::AddEntry(v6, stampIn, v10, (int *)&pstampOut);
    if ( pstampOut )
      return 3;
    if ( !v11 && v6->numBlockedStamps_ == 1 )
    {
      v12 = Timer::cur_time.Param;
      LODWORD(v6->blockedSince_) = Timer::cur_time.Cmd;
      HIDWORD(v6->blockedSince_) = v12;
    }
    if ( v6->numBlockedStamps_ < 20
      || v6->blockedSince_ == 0.0
      || COERCE_DOUBLE(Timer::cur_time.Cmd) - v6->blockedSince_ <= 300.0 )
    {
      result = 2;
    }
    else
    {
      v13 = v6->highestStamp_ + 1;
      pstampOut = 0;
      pObjIn = 0;
      TSRecv::AddEntryBlocking(v6, v13, 0, (unsigned int *)&pstampOut, &pObjIn);
      result = 2 - (TSRecv::GetNextReadyEntry(v6, v7, v5) != 0);
    }
  }
  return result;
}

//----- (005B0220) --------------------------------------------------------  // acclient.c:474864
int __thiscall TSRecv::AddAndCheck(TSRecv *this, unsigned int stampIn, ReferenceCountTemplate<1048576,0> *pObjIn, unsigned int *pstampOut, ReferenceCountTemplate<1048576,0> **ppObjOut)
{
  TSRecvMode v5; // eax@1
  int result; // eax@3

  *ppObjOut = 0;
  v5 = this->mode_;
  if ( v5 )
  {
    if ( v5 == 1 )
      result = TSRecv::AddEntryLatest(this, stampIn, pObjIn, pstampOut, ppObjOut);
    else
      result = 0;
  }
  else
  {
    result = TSRecv::AddEntryBlocking(this, stampIn, pObjIn, pstampOut, ppObjOut);
  }
  return result;
}

