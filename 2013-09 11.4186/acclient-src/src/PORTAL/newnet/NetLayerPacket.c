/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : NetLayerPacket
   Object     : PORTAL\newnet\NetLayerPacket.obj
   Functions  : 6
   Addresses  : 00542C20 - 0070DF10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00542C20) --------------------------------------------------------  // acclient.c:370420
CNetLayerPacket *__thiscall CNetLayerPacket::scalar_deleting_destructor(CNetLayerPacket *this, unsigned int a2)
{
  CNetLayerPacket *v2; // esi@1

  v2 = this;
  NetPacket::~NetPacket((NetPacket *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005AA540) --------------------------------------------------------  // acclient.c:467938
void __thiscall CNetLayerPacket::CNetLayerPacket(CNetLayerPacket *this)
{
  this->m_cRef = 1;
  this->next_ = 0;
  this->numSpecialFrags_ = 0;
  this->numFrags_ = 0;
  this->recipient_ = 0;
  this->realPriority_ = 0;
  this->size_ = 0;
  this->seqNum_ = 0;
  this->cryptoKey_ = 0;
  this->checksum_ = 0;
  this->flags_ = 0;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)NetPacket::vftable;
  this->m_Hdr.seqID_ = 0;
  this->m_Hdr.header_ = 0;
  this->m_Hdr.checksum_ = 0;
  this->m_Hdr.recID_ = 0;
  this->m_Hdr.interval_ = 0;
  this->m_Hdr.datalen_ = 0;
  this->m_Hdr.iteration_ = 0;
  this->m_Iter.m_dwCurOfs = 0;
  this->m_Iter.m_cbBufSize = 65484;
  this->m_Iter.m_pBuf = this->m_Data;
  this->m_bValid = 0;
  this->m_pRecv = 0;
  this->m_pRecip = 0;
  this->m_CryptoKey = 0;
}
// 7CA080: using guessed type int (__thiscall *NetPacket::vftable[2])(void *, char);

//----- (005AA5F0) --------------------------------------------------------  // acclient.c:467970
void __cdecl CNetLayerPacket::Create()
{
  CNetLayerPacket *v0; // eax@1

  v0 = (CNetLayerPacket *)operator new(0x10130u);
  if ( v0 )
    CNetLayerPacket::CNetLayerPacket(v0);
}

//----- (005AA610) --------------------------------------------------------  // acclient.c:467980
void __thiscall CNetLayerPacket::Clear(CNetLayerPacket *this)
{
  CNetLayerPacket *v1; // esi@1
  unsigned int v2; // ecx@1
  unsigned int v3; // ebx@1
  int v4; // ebp@2
  int v5; // edi@3
  unsigned int v6; // ecx@9
  unsigned int v7; // ebx@9
  int v8; // ebp@10
  int v9; // edi@11

  v1 = this;
  v2 = this->numSpecialFrags_;
  v3 = 0;
  v1->m_bValid = 0;
  if ( v2 )
  {
    v4 = (int)v1->specialFragList_;
    do
    {
      v5 = *(_DWORD *)v4;
      if ( *(_DWORD *)v4 )
      {
        if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
        *(_DWORD *)v4 = 0;
      }
      ++v3;
      v4 += 4;
    }
    while ( v3 < v1->numSpecialFrags_ );
  }
  v6 = v1->numFrags_;
  v7 = 0;
  v1->numSpecialFrags_ = 0;
  if ( v6 > 0 )
  {
    v8 = (int)v1->fragList_;
    do
    {
      v9 = *(_DWORD *)v8;
      if ( *(_DWORD *)v8 )
      {
        if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
        *(_DWORD *)v8 = 0;
      }
      ++v7;
      v8 += 4;
    }
    while ( v7 < v1->numFrags_ );
  }
  v1->numFrags_ = 0;
  v1->seqNum_ = 0;
  v1->size_ = 0;
  v1->flags_ = 0;
  v1->checksum_ = 0;
  v1->m_pRecv = 0;
  v1->m_pRecip = 0;
  v1->m_CryptoKey = 0;
}

//----- (0070DF00) --------------------------------------------------------  // acclient.c:800908
int _E77_23()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_45;
  dword_8EDFB0 = LOWEST_DATA_RATE_45;
  return result;
}

//----- (0070DF10) --------------------------------------------------------  // acclient.c:800918
int sub_70DF10()
{
  return atexit(nullsub_1535);
}

