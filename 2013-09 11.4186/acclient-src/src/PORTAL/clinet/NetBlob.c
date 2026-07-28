/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : NetBlob
   Object     : PORTAL\clinet\NetBlob.obj
   Functions  : 15
   Addresses  : 00549A20 - 00705710 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00549A20) --------------------------------------------------------  // acclient.c:377184
void __thiscall NetBlob::ReceiveAddFragment(NetBlob *this, BlobFrag *frag)
{
  NetBlob *v2; // ebx@1
  BlobFragHeader_t *v3; // ecx@2
  int v4; // eax@2
  BlobFragHeader_t *v5; // ecx@5
  BlobFragHeader_t *v6; // eax@6
  char *v7; // ecx@6
  unsigned int v8; // esi@6
  unsigned int v9; // edx@6
  void *v10; // edi@6
  unsigned int v11; // eax@11
  unsigned int v12; // [sp+10h] [bp-4h]@6

  v2 = this;
  if ( !this->numFragments_ )
  {
    v3 = frag->hdrRead_;
    v4 = v3->numFrags;
    if ( v3->blobNum + 1 == v4 )
      v2->bufSize_ = 448 * (v4 - 1) + v3->blobFragSize - 16;
    else
      v2->bufSize_ = 448 * v4;
    v2->buf_ = (char *)operator new[](v2->bufSize_);
    v5 = frag->hdrRead_;
    LODWORD(v2->id) = LODWORD(v5->blobID);
    HIDWORD(v2->id) = HIDWORD(v5->blobID);
    v2->cMaxFragments_ = frag->hdrRead_->numFrags;
    v2->queueID_ = frag->hdrRead_->queueID;
  }
  v6 = frag->hdrRead_;
  v7 = v2->buf_;
  v8 = v2->cMaxFragments_;
  v12 = v6->blobNum;
  v9 = v6->blobFragSize - 16;
  v10 = &v7[448 * v12];
  if ( v6->numFrags == v8
    && v6->queueID == v2->queueID_
    && v12 < v8
    && v9 <= 0x1C0
    && (char *)v10 + v9 <= &v7[v2->bufSize_] )
  {
    qmemcpy(v10, frag->dat_, v9);
    v11 = v2->cMaxFragments_;
    ++v2->numFragments_;
    if ( v11 > 1 && v11 == frag->hdrRead_->blobNum + 1 )
      v2->bufSize_ = v9 + 448 * (v11 - 1);
  }
}

//----- (00549B30) --------------------------------------------------------  // acclient.c:377235
void __thiscall NetBlob::ReceiveBlobReady(NetBlob *this)
{
  this->state_ = 3;
}

//----- (00549B40) --------------------------------------------------------  // acclient.c:377241
char __thiscall NetBlob::Send(NetBlob *this, unsigned __int16 recip, unsigned int priority)
{
  char result; // al@2
  signed int v4; // eax@3
  NetBlob *v5; // ST00_4@5
  PacketController *v6; // eax@5

  if ( *(_WORD *)&SharedNet::s_pNet[1].receivers_[454] )
  {
    v4 = priority;
    if ( priority == -842150451 )
      v4 = 1;
    v5 = this;
    this->state_ = 1;
    this->priority_ = v4;
    v6 = PacketController::Instance();
    result = PacketController::SendBlob(v6, v5, recip);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00549B90) --------------------------------------------------------  // acclient.c:377267
void __thiscall NetBlob::NetBlob(NetBlob *this, char *buf, unsigned int bufSize, __int16 queue)
{
  unsigned int v4; // eax@1

  this->m_cRef = 1;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->hash_next = 0;
  this->id = 0i64;
  this->vfptr = (HashBaseData<unsigned __int64>Vtbl *)&HashBaseData<unsigned __int64>::vftable;
  this->buf_ = buf;
  this->queueID_ = queue;
  this->bufSize_ = bufSize;
  v4 = bufSize / 0x1C0;
  this->state_ = 0;
  this->numFragments_ = 0;
  this->sender_ = 0;
  this->priority_ = 0;
  this->waitNext_ = 0;
  this->savedNetBlobID_ = 0i64;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&NetBlob::vftable;
  this->vfptr = (PackObjVtbl *)&NetBlob::vftable;
  this->vfptr = (HashBaseData<unsigned __int64>Vtbl *)&NetBlob::vftable;
  if ( bufSize % 0x1C0 )
    ++v4;
  this->cMaxFragments_ = v4;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CA754: using guessed type int (__thiscall *HashBaseData<unsigned __int64>::vftable)(void *, char);
// 7CA758: using guessed type void *NetBlob::vftable;
// 7CA75C: using guessed type void *NetBlob::vftable;
// 7CA770: using guessed type int (__thiscall *NetBlob::vftable)(void *, char);

//----- (00549C10) --------------------------------------------------------  // acclient.c:377300
NetBlob *__thiscall NetBlob::vector_deleting_destructor(NetBlob *this, unsigned int a2)
{
  return NetBlob::vector_deleting_destructor((NetBlob *)((char *)this - 8), a2);
}

//----- (00549C20) --------------------------------------------------------  // acclient.c:377306
NetBlob *__thiscall NetBlob::vector_deleting_destructor(NetBlob *this, unsigned int a2)
{
  return NetBlob::vector_deleting_destructor((NetBlob *)((char *)this - 16), a2);
}

//----- (00549C30) --------------------------------------------------------  // acclient.c:377312
__int32 __thiscall NetBlob::GetPackSize(NetBlob *this)
{
  return this->state_ + 40;
}

//----- (00549C40) --------------------------------------------------------  // acclient.c:377318
void __thiscall NetBlob::NetBlob(NetBlob *this)
{
  this->m_cRef = 1;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->hash_next = 0;
  this->id = 0i64;
  this->vfptr = (HashBaseData<unsigned __int64>Vtbl *)&HashBaseData<unsigned __int64>::vftable;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&NetBlob::vftable;
  this->vfptr = (PackObjVtbl *)&NetBlob::vftable;
  this->vfptr = (HashBaseData<unsigned __int64>Vtbl *)&NetBlob::vftable;
  this->state_ = 2;
  this->buf_ = 0;
  this->bufSize_ = 0;
  this->cMaxFragments_ = 0;
  this->numFragments_ = 0;
  this->sender_ = 0;
  this->queueID_ = 0;
  this->priority_ = 0;
  this->waitNext_ = 0;
  this->savedNetBlobID_ = 0i64;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CA754: using guessed type int (__thiscall *HashBaseData<unsigned __int64>::vftable)(void *, char);
// 7CA758: using guessed type void *NetBlob::vftable;
// 7CA75C: using guessed type void *NetBlob::vftable;
// 7CA770: using guessed type int (__thiscall *NetBlob::vftable)(void *, char);

//----- (00549CA0) --------------------------------------------------------  // acclient.c:377346
void __thiscall NetBlob::~NetBlob(NetBlob *this)
{
  NetBlob *v1; // esi@1
  char *v2; // ST00_4@1

  v1 = this;
  v2 = this->buf_;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&NetBlob::vftable;
  this->vfptr = (PackObjVtbl *)&NetBlob::vftable;
  this->vfptr = (HashBaseData<unsigned __int64>Vtbl *)&NetBlob::vftable;
  operator delete[](v2);
  v1->vfptr = (HashBaseData<unsigned __int64>Vtbl *)&HashBaseData<unsigned __int64>::vftable;
  v1->hash_next = 0;
  LODWORD(v1->id) = 0;
  HIDWORD(v1->id) = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 7CA754: using guessed type int (__thiscall *HashBaseData<unsigned __int64>::vftable)(void *, char);
// 7CA758: using guessed type void *NetBlob::vftable;
// 7CA75C: using guessed type void *NetBlob::vftable;
// 7CA770: using guessed type int (__thiscall *NetBlob::vftable)(void *, char);

//----- (00549CF0) --------------------------------------------------------  // acclient.c:377372
unsigned int __thiscall NetBlob::Fragmentize(NetBlob *this, BlobFrag **ppCurFragment)
{
  NetBlob *v2; // edi@1
  unsigned int v3; // ebx@1
  unsigned int v4; // eax@1
  unsigned int v5; // ett@1
  BlobFrag *v6; // ecx@1
  unsigned int v7; // ebp@3
  unsigned int v8; // esi@4
  BlobFrag *v9; // eax@6
  int cTotalBlobs; // [sp+10h] [bp-Ch]@1
  char *curBufPtr; // [sp+14h] [bp-8h]@3
  BlobFrag *lastFragment; // [sp+18h] [bp-4h]@4

  *ppCurFragment = 0;
  v2 = this;
  v3 = this->bufSize_;
  v5 = this->bufSize_;
  v4 = this->bufSize_ / 0x1C0;
  v6 = 0;
  v2->state_ = 4;
  cTotalBlobs = v5 / 0x1C0;
  if ( v5 % 0x1C0 )
    cTotalBlobs = v4 + 1;
  v7 = 0;
  for ( curBufPtr = v2->buf_; v3; curBufPtr += v8 )
  {
    lastFragment = v6;
    v8 = 448;
    if ( v3 <= 0x1C0 )
      v8 = v3;
    BlobFrag::CreateForSend(v2, v7, cTotalBlobs, curBufPtr, v8);
    v6 = v9;
    ++v7;
    if ( !*ppCurFragment )
      *ppCurFragment = v9;
    if ( lastFragment )
      lastFragment->blobNextFrag_ = v9;
    v3 -= v8;
  }
  return v7;
}

//----- (00549DA0) --------------------------------------------------------  // acclient.c:377416
unsigned int __thiscall NetBlob::Pack(NetBlob *this, void **addr, unsigned int size)
{
  NetBlob *v3; // ebx@1
  unsigned int result; // eax@1
  void *v5; // ecx@2
  char *v6; // ecx@2
  char *v7; // ebp@2
  char *v8; // edi@2
  char *v9; // esi@2
  char *v10; // ecx@2
  char *v11; // ebp@2
  char *v12; // edi@2
  char *v13; // esi@2
  char *v14; // ecx@2

  v3 = this;
  result = this->state_ + 40;
  if ( size >= result )
  {
    v5 = *addr;
    *(_DWORD *)v5 = v3->hash_next;
    *((_DWORD *)v5 + 1) = *((_DWORD *)&v3->hash_next + 1);
    v6 = (char *)*addr + 8;
    *addr = v6;
    *(_DWORD *)v6 = LODWORD(v3->id);
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->state_;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_WORD *)v8 = LOWORD(v3->cMaxFragments_);
    v9 = (char *)*addr + 2;
    *addr = v9;
    *(_WORD *)v9 = HIWORD(v3->cMaxFragments_);
    v10 = (char *)*addr + 2;
    *addr = v10;
    *(_DWORD *)v10 = v3->numFragments_;
    v11 = (char *)*addr + 4;
    *addr = v11;
    *(_DWORD *)v11 = v3->bufSize_;
    v12 = (char *)*addr + 4;
    *addr = v12;
    *(_DWORD *)v12 = v3->buf_;
    v13 = (char *)*addr + 4;
    *addr = v13;
    *(_DWORD *)v13 = v3->priority_;
    *((_DWORD *)v13 + 1) = v3->waitNext_;
    v14 = (char *)*addr + 8;
    *addr = v14;
    qmemcpy(v14, HIDWORD(v3->id), v3->state_);
    *addr = (char *)*addr + v3->state_;
  }
  return result;
}

//----- (00549E70) --------------------------------------------------------  // acclient.c:377472
int __thiscall NetBlob::UnPack(NetBlob *this, void **addr, unsigned int size)
{
  void **v3; // ebx@1
  void *v4; // eax@1
  NetBlob *v5; // ebp@1
  char *v6; // eax@1
  int v7; // ecx@1
  char *v8; // edi@1
  char *v9; // esi@1
  char *v10; // edx@1
  char *v11; // ecx@1
  char *v12; // eax@1
  char *v13; // edi@1
  void *v14; // eax@1
  unsigned int v15; // edx@1

  v3 = addr;
  v4 = *addr;
  v5 = this;
  this->hash_next = *(HashBaseData<unsigned __int64> **)*addr;
  *((_DWORD *)&this->hash_next + 1) = *((_DWORD *)v4 + 1);
  v6 = (char *)*addr + 8;
  *addr = v6;
  v7 = *(_DWORD *)v6;
  *addr = v6 + 4;
  LODWORD(v5->id) = v7;
  v5->state_ = *(_DWORD *)*addr;
  v8 = (char *)*addr + 4;
  *addr = v8;
  LOWORD(v5->cMaxFragments_) = *(_WORD *)v8;
  v9 = (char *)*addr + 2;
  *addr = v9;
  HIWORD(v5->cMaxFragments_) = *(_WORD *)v9;
  v10 = (char *)*addr + 2;
  *addr = v10;
  v5->numFragments_ = *(_DWORD *)v10;
  v11 = (char *)*addr + 4;
  *addr = v11;
  v5->bufSize_ = *(_DWORD *)v11;
  v12 = (char *)*addr + 4;
  *addr = v12;
  v5->buf_ = *(char **)v12;
  v13 = (char *)*addr + 4;
  *addr = v13;
  v5->priority_ = *(_DWORD *)v13;
  v5->waitNext_ = (NetBlob *)*((_DWORD *)v13 + 1);
  *v3 = (char *)*v3 + 8;
  v14 = operator new[](v5->state_);
  v15 = v5->state_;
  HIDWORD(v5->id) = v14;
  qmemcpy(v14, *addr, v15);
  *v3 = (char *)*v3 + v5->state_;
  return 1;
}

//----- (00549F40) --------------------------------------------------------  // acclient.c:377528
NetBlob *__thiscall NetBlob::vector_deleting_destructor(NetBlob *this, unsigned int a2)
{
  NetBlob *v2; // esi@1
  char *v3; // ST00_4@1

  v2 = this;
  v3 = this->buf_;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&NetBlob::vftable;
  this->vfptr = (PackObjVtbl *)&NetBlob::vftable;
  this->vfptr = (HashBaseData<unsigned __int64>Vtbl *)&NetBlob::vftable;
  operator delete[](v3);
  v2->hash_next = 0;
  LODWORD(v2->id) = 0;
  HIDWORD(v2->id) = 0;
  v2->vfptr = (HashBaseData<unsigned __int64>Vtbl *)&HashBaseData<unsigned __int64>::vftable;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 7CA754: using guessed type int (__thiscall *HashBaseData<unsigned __int64>::vftable)(void *, char);
// 7CA758: using guessed type void *NetBlob::vftable;
// 7CA75C: using guessed type void *NetBlob::vftable;
// 7CA770: using guessed type int (__thiscall *NetBlob::vftable)(void *, char);

//----- (00705700) --------------------------------------------------------  // acclient.c:792754
int _E77_16()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_33;
  dword_845F98 = LOWEST_DATA_RATE_33;
  return result;
}

//----- (00705710) --------------------------------------------------------  // acclient.c:792764
int sub_705710()
{
  return atexit(nullsub_1205);
}

