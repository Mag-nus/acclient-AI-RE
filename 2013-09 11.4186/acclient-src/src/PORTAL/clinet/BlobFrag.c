/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : BlobFrag
   Object     : PORTAL\clinet\BlobFrag.obj
   Functions  : 7
   Addresses  : 005496F0 - 007056F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005496F0) --------------------------------------------------------  // acclient.c:376967
void __thiscall BlobFrag::BlobFrag(BlobFrag *this, NetBlob *myBlob, unsigned int blobNum, unsigned int cTotalBlobs, char *dat, unsigned int size)
{
  BlobFrag *v6; // esi@1
  BlobFragHeader_t *v7; // eax@1

  v6 = this;
  this->blobNextFrag_ = 0;
  this->myBlob_ = 0;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)BlobFrag::vftable;
  this->dat_ = dat;
  v6->hdrWrite_ = &v6->memberHeader_;
  v6->hdrRead_ = &v6->memberHeader_;
  InterlockedIncrement((volatile LONG *)&myBlob->m_cRef);
  v7 = v6->hdrWrite_;
  v6->myBlob_ = myBlob;
  v7->blobID = myBlob->id;
  v6->hdrWrite_->queueID = v6->myBlob_->queueID_;
  v6->hdrWrite_->blobFragSize = size + 16;
  v6->hdrWrite_->numFrags = cTotalBlobs;
  v6->hdrWrite_->blobNum = blobNum;
}
// 7CA714: using guessed type int (__thiscall *BlobFrag::vftable[2])(void *, char);

//----- (00549780) --------------------------------------------------------  // acclient.c:376992
BlobFrag *__thiscall BlobFrag::vector_deleting_destructor(BlobFrag *this, unsigned int a2)
{
  BlobFrag *v2; // esi@1
  ReferenceCountTemplate<1048576,0> *v3; // ecx@1

  v2 = this;
  v3 = (ReferenceCountTemplate<1048576,0> *)&this->myBlob_->vfptr;
  v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)BlobFrag::vftable;
  if ( v3 )
    ReferenceCountTemplate<1048576,0>::Release(v3);
  v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 7CA714: using guessed type int (__thiscall *BlobFrag::vftable[2])(void *, char);

//----- (005497C0) --------------------------------------------------------  // acclient.c:377011
void __thiscall BlobFrag::BlobFrag(BlobFrag *this, const char *pbData, unsigned int cbSize, unsigned int *cbUsed)
{
  BlobFrag *v4; // eax@1
  BlobFragHeader_t *v5; // ecx@1
  unsigned __int16 v6; // dx@1

  v4 = this;
  this->blobNextFrag_ = 0;
  this->dat_ = 0;
  this->myBlob_ = 0;
  this->hdrWrite_ = 0;
  this->hdrRead_ = (BlobFragHeader_t *)pbData;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)BlobFrag::vftable;
  *cbUsed = 0;
  v5 = this->hdrRead_;
  v6 = v5->blobFragSize;
  if ( v6 >= 0x10u && v6 <= 0x1D0u && v6 <= cbSize )
  {
    v4->dat_ = pbData + 16;
    *cbUsed = v5->blobFragSize;
  }
}
// 7CA714: using guessed type int (__thiscall *BlobFrag::vftable[2])(void *, char);

//----- (00549820) --------------------------------------------------------  // acclient.c:377037
void __cdecl BlobFrag::CreateForSend(NetBlob *myBlob, unsigned int blobNum, unsigned int cTotalBlobs, char *dat, unsigned int size)
{
  BlobFrag *v5; // eax@1

  v5 = (BlobFrag *)operator new(0x30u);
  if ( v5 )
    BlobFrag::BlobFrag(v5, myBlob, blobNum, cTotalBlobs, dat, size);
}

//----- (00549860) --------------------------------------------------------  // acclient.c:377047
BlobFrag *__cdecl BlobFrag::CreateForRecv(CBufferIterator *Buf)
{
  BlobFrag *v1; // eax@1
  unsigned int v2; // edx@2
  unsigned int v3; // edi@2
  unsigned int v4; // edx@3
  BlobFrag *result; // eax@5
  BlobFrag *v6; // edi@5
  unsigned int cbUsed; // [sp+0h] [bp-4h]@1

  cbUsed = 0;
  v1 = (BlobFrag *)operator new(0x30u);
  if ( v1 )
  {
    v2 = Buf->m_cbBufSize;
    v3 = Buf->m_dwCurOfs;
    if ( v3 >= v2 )
      v4 = 0;
    else
      v4 = v2 - v3;
    BlobFrag::BlobFrag(v1, &Buf->m_pBuf[v3], v4, &cbUsed);
    v6 = result;
    if ( cbUsed )
    {
      Buf->m_dwCurOfs += cbUsed;
    }
    else if ( result )
    {
      if ( !InterlockedDecrement((volatile LONG *)&result->m_cRef) )
        v6->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 1u);
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (007056E0) --------------------------------------------------------  // acclient.c:792738
int _E77_15()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_32;
  dword_845F8C = LOWEST_DATA_RATE_32;
  return result;
}

//----- (007056F0) --------------------------------------------------------  // acclient.c:792748
int sub_7056F0()
{
  return atexit(nullsub_1207);
}

