/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : NetPacket
   Object     : PORTAL\clinet\NetPacket.obj
   Functions  : 11
   Addresses  : 005492B0 - 007056D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005492B0) --------------------------------------------------------  // acclient.c:376683
void __thiscall NetPacket::ComputeChecksum(NetPacket *this)
{
  NetPacket *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  unsigned int v4; // edi@1
  int v5; // ebx@2
  unsigned int v6; // ebx@4
  int v7; // ebp@5
  int v8; // edi@6

  v1 = this;
  v2 = this->numSpecialFrags_;
  v3 = this->flags_ & 0xFFFFFFFE;
  v4 = 0;
  v1->checksum_ = 0;
  v1->flags_ = v3;
  if ( v2 )
  {
    v5 = (int)v1->specialFragList_;
    do
    {
      v1->checksum_ += PortalChecksum::CalcChecksum32(
                         *(const char **)(*(_DWORD *)v5 + 16),
                         *(_DWORD *)(*(_DWORD *)v5 + 20));
      ++v4;
      v5 += 4;
    }
    while ( v4 < v1->numSpecialFrags_ );
  }
  v6 = 0;
  if ( v1->numFrags_ )
  {
    v7 = (int)v1->fragList_;
    do
    {
      v8 = *(_DWORD *)v7;
      v1->checksum_ += PortalChecksum::CalcChecksum32(*(const char **)(*(_DWORD *)v7 + 16), 0x10u);
      v1->checksum_ += PortalChecksum::CalcChecksum32(
                         *(const char **)(v8 + 40),
                         *(_WORD *)(*(_DWORD *)(v8 + 16) + 10) - 16);
      ++v6;
      v7 += 4;
    }
    while ( v6 < v1->numFrags_ );
  }
}

//----- (00549370) --------------------------------------------------------  // acclient.c:376732
unsigned int __thiscall NetPacket::ApplySpecialFrags(NetPacket *this, ProtoHeader *pHeader)
{
  unsigned int v2; // edx@1
  unsigned int result; // eax@1
  char *v4; // ecx@2

  v2 = this->numSpecialFrags_;
  result = 0;
  if ( v2 )
  {
    v4 = (char *)this->specialFragList_;
    do
    {
      result |= *(_DWORD *)(*(_DWORD *)v4 + 8);
      v4 += 4;
      --v2;
    }
    while ( v2 );
  }
  if ( pHeader )
    pHeader->header_ |= result;
  return result;
}

//----- (005493A0) --------------------------------------------------------  // acclient.c:376757
void __thiscall NetPacket::AddToTail(NetPacket *this, NetPacket **head, NetPacket **tail)
{
  if ( *head )
  {
    (*tail)->next_ = this;
    *tail = this;
  }
  else
  {
    *head = this;
    *tail = this;
  }
}

//----- (005493D0) --------------------------------------------------------  // acclient.c:376772
void __thiscall NetPacket::AddToHead(NetPacket *this, NetPacket **head, NetPacket **tail)
{
  NetPacket *v3; // edx@1

  v3 = *head;
  if ( *head )
  {
    if ( v3->flags_ & 1 )
    {
      this->next_ = v3->next_;
      (*head)->next_ = this;
      if ( *tail == *head )
        *tail = this;
    }
    else
    {
      this->next_ = v3;
      *head = this;
    }
  }
  else
  {
    *tail = this;
    *head = this;
    this->next_ = 0;
  }
}

//----- (00549420) --------------------------------------------------------  // acclient.c:376801
void __thiscall NetPacket::Remove(NetPacket *this, NetPacket *prev, NetPacket **head, NetPacket **tail)
{
  if ( prev )
  {
    prev->next_ = this->next_;
    if ( *tail == this )
      *tail = prev;
  }
  else
  {
    *head = this->next_;
    if ( *tail == this )
      *tail = 0;
  }
}

//----- (00549460) --------------------------------------------------------  // acclient.c:376818
void __thiscall NetPacket::AddOptionalHeader(NetPacket *this, COptionalHeader *frag)
{
  NetPacket *v2; // esi@1
  unsigned int v3; // eax@1
  int v4; // ecx@2
  unsigned int v5; // ebx@5

  v2 = this;
  InterlockedIncrement((volatile LONG *)&frag->m_cRef);
  v3 = v2->numSpecialFrags_;
  if ( (signed int)v3 > 0 )
  {
    v4 = (int)(&v2->next_ + v3);
    do
    {
      if ( *(_DWORD *)(*(_DWORD *)v4 + 8) <= frag->m_dwMask )
        break;
      *(_DWORD *)(v4 + 4) = *(_DWORD *)v4;
      --v3;
      v4 -= 4;
    }
    while ( (signed int)v3 > 0 );
  }
  v2->specialFragList_[v3] = frag;
  v5 = v2->size_;
  ++v2->numSpecialFrags_;
  v2->size_ = frag->m_cbData + v5;
  v2->checksum_ += PortalChecksum::CalcChecksum32(frag->m_pData, frag->m_cbData);
  if ( frag->m_Flags & 8 )
    v2->flags_ |= 2u;
  if ( !(frag->m_Flags & 1) )
    v2->flags_ |= 4u;
  if ( frag->m_Flags & 0x20 )
    v2->flags_ |= 8u;
}

//----- (00549510) --------------------------------------------------------  // acclient.c:376855
bool __thiscall NetPacket::RemoveDisposableOptionalHeaders(NetPacket *this)
{
  NetPacket *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebp@1
  char *v4; // ebx@2
  int v5; // esi@3
  unsigned int v6; // ecx@9
  char *v8; // [sp+8h] [bp-8h]@2
  unsigned int iDest; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = 0;
  v3 = 0;
  iDest = 0;
  if ( this->numSpecialFrags_ )
  {
    v4 = (char *)this->specialFragList_;
    v8 = (char *)this->specialFragList_;
    do
    {
      v5 = *(_DWORD *)v8;
      if ( *(_BYTE *)(*(_DWORD *)v8 + 12) & 1 )
      {
        v1->size_ -= *(_DWORD *)(v5 + 20);
        if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      }
      else
      {
        *(_DWORD *)v4 = v5;
        ++iDest;
        v4 += 4;
      }
      ++v3;
      v8 += 4;
    }
    while ( v3 < v1->numSpecialFrags_ );
    v2 = iDest;
    if ( v3 != iDest )
    {
      v6 = v1->flags_ & 0xFFFFFFFE;
      v1->numSpecialFrags_ += iDest - v3;
      v1->checksum_ = 0;
      v1->flags_ = v6;
    }
  }
  return v3 != v2;
}

//----- (005495D0) --------------------------------------------------------  // acclient.c:376906
char __thiscall NetPacket::UpdateTimeSensitiveHeaders(NetPacket *this)
{
  NetPacket *v1; // esi@1
  char v2; // al@2
  unsigned int v3; // edi@2
  char *v4; // ebp@3

  v1 = this;
  if ( this->flags_ & 2 )
  {
    v2 = 0;
    v3 = 0;
    if ( this->numSpecialFrags_ )
    {
      v4 = (char *)this->specialFragList_;
      do
      {
        if ( *(_BYTE *)(*(_DWORD *)v4 + 12) & 8 )
        {
          (*(void (**)(void))(**(_DWORD **)v4 + 4))();
          v2 = 1;
        }
        ++v3;
        v4 += 4;
      }
      while ( v3 < v1->numSpecialFrags_ );
      if ( v2 )
      {
        v1->flags_ &= 0xFFFFFFFE;
        v1->checksum_ = 0;
        return 1;
      }
    }
    v1->flags_ &= 0xFFFFFFFD;
  }
  return 1;
}

//----- (00549640) --------------------------------------------------------  // acclient.c:376945
void __thiscall NetPacket::AddFrag(NetPacket *this, BlobFrag *frag, unsigned __int16 recip, unsigned int priority)
{
  NetPacket *v4; // esi@1
  int v5; // ecx@5
  int v6; // eax@5

  v4 = this;
  if ( !this->recipient_ )
    this->recipient_ = recip;
  if ( priority > this->realPriority_ )
    this->realPriority_ = priority;
  InterlockedIncrement((volatile LONG *)&frag->m_cRef);
  v4->fragList_[v4->numFrags_++] = frag;
  v4->size_ += frag->hdrRead_->blobFragSize;
  v4->checksum_ += PortalChecksum::CalcChecksum32((const char *)frag->hdrRead_, 0x10u);
  v5 = PortalChecksum::CalcChecksum32(frag->dat_, frag->hdrRead_->blobFragSize - 16) + v4->checksum_;
  v6 = v4->flags_ | 4;
  v4->checksum_ = v5;
  v4->flags_ = v6;
}

//----- (007056C0) --------------------------------------------------------  // acclient.c:792722
int _E77_14()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_31;
  dword_845F80 = LOWEST_DATA_RATE_31;
  return result;
}

//----- (007056D0) --------------------------------------------------------  // acclient.c:792732
int sub_7056D0()
{
  return atexit(nullsub_1206);
}

