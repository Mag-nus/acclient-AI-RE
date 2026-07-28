/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : OptionalHeader
   Object     : PORTAL\newnet\OptionalHeader.obj
   Functions  : 52
   Addresses  : 00542B80 - 0070E1B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00542B80) --------------------------------------------------------  // acclient.c:370376
COnePrimHeader<512,7,sockaddr_in> *__thiscall COnePrimHeader<524288,536870919,unsigned __int64>::scalar_deleting_destructor(COnePrimHeader<512,7,sockaddr_in> *this, unsigned int a2)
{
  COnePrimHeader<512,7,sockaddr_in> *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);

//----- (005AA770) --------------------------------------------------------  // acclient.c:468083
void __cdecl COptionalHeaderFactory::RegisterOptionalHeaderType(unsigned int dwMask, COptionalHeader *(__cdecl *pAllocatorFunc)(CBufferIterator *))
{
  int v2; // ecx@1
  CPluginManager **v3; // eax@2
  int v4; // eax@5

  v2 = COptionalHeaderFactory::s_nPlugins;
  if ( COptionalHeaderFactory::s_nPlugins > 0 )
  {
    v3 = &NetInitializer::S_sockerCleaner.m_pManager + 2 * COptionalHeaderFactory::s_nPlugins;
    do
    {
      if ( (unsigned int)*v3 <= dwMask )
        break;
      v3[2] = *v3;
      v3[3] = v3[1];
      --v2;
      v3 -= 2;
    }
    while ( v2 > 0 );
  }
  dword_8EDFCC[2 * v2] = (int)pAllocatorFunc;
  v4 = COptionalHeaderFactory::s_nPlugins + 1;
  (&COptionalHeaderFactory::s_FactoryPlugins)[v2] = (struct COptionalHeaderFactory::CPlugin *)dwMask;
  COptionalHeaderFactory::s_nPlugins = v4;
}
// 8EDFC8: using guessed type struct COptionalHeaderFactory::CPlugin *COptionalHeaderFactory::s_FactoryPlugins;
// 8EDFCC: using guessed type int dword_8EDFCC[];
// 8EE0CC: using guessed type int COptionalHeaderFactory::s_nPlugins;

//----- (005AA7C0) --------------------------------------------------------  // acclient.c:468114
char __thiscall CBufferIterator::ReadPrimArray(CBufferIterator *this, unsigned __int32 *a2, int a3)
{
  unsigned int v3; // edi@1
  unsigned int v4; // edx@1
  char result; // al@2

  v3 = this->m_dwCurOfs;
  v4 = 4 * a3;
  if ( v3 + 4 * a3 > this->m_cbBufSize )
  {
    result = 0;
  }
  else
  {
    qmemcpy(a2, &this->m_pBuf[v3], v4);
    this->m_dwCurOfs += v4;
    result = 1;
  }
  return result;
}

//----- (005AA810) --------------------------------------------------------  // acclient.c:468136
bool __cdecl COptionalHeaderFactory::AddOptionalHeadersToPacket(unsigned int dwMask, NetPacket *pPacket, CBufferIterator *Buf)
{
  unsigned int v3; // ebx@1
  int v4; // edi@1
  struct COptionalHeaderFactory::CPlugin *v5; // eax@3
  COptionalHeader *v6; // eax@4
  COptionalHeader *v7; // esi@4

  v3 = dwMask;
  v4 = 0;
  if ( dwMask )
  {
    while ( v4 < COptionalHeaderFactory::s_nPlugins )
    {
      v5 = (&COptionalHeaderFactory::s_FactoryPlugins)[v4];
      if ( (unsigned int)v5 & v3 )
      {
        v3 &= ~(unsigned int)v5;
        v6 = (COptionalHeader *)((int (__cdecl *)(CBufferIterator *))dword_8EDFCC[2 * v4])(Buf);
        v7 = v6;
        if ( !v6 )
          return 0;
        NetPacket::AddOptionalHeader(pPacket, v6);
        if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) )
          v7->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v7, 1u);
      }
      ++v4;
      if ( !v3 )
        return (v3 & 0xFFFFFF00) == 0;
    }
  }
  return (v3 & 0xFFFFFF00) == 0;
}
// 8EDFC8: using guessed type struct COptionalHeaderFactory::CPlugin *COptionalHeaderFactory::s_FactoryPlugins;
// 8EDFCC: using guessed type int dword_8EDFCC[];
// 8EE0CC: using guessed type int COptionalHeaderFactory::s_nPlugins;

//----- (005AA890) --------------------------------------------------------  // acclient.c:468174
void __thiscall CPackObjHeader<NetError,1048576,7>::CPackObjHeader<NetError,1048576,7>(CPackObjHeader<NetError,1048576,7> *this, CBufferIterator *Buf)
{
  CBufferIterator *v2; // ebp@1
  CPackObjHeader<NetError,1048576,7> *v3; // esi@1
  char *v4; // edi@1
  unsigned int v5; // eax@1
  PackObjVtbl *v6; // edx@1
  int v7; // ebx@1
  int v8; // ST04_4@1
  char v9; // al@2
  int v10; // edx@4

  v2 = Buf;
  v3 = this;
  this->m_pData = 0;
  this->m_cbData = 0;
  this->m_pAdoptedData = 0;
  this->m_cbAdoptedData = 0;
  this->m_cRef = 1;
  this->m_dwMask = 0x100000;
  this->m_Flags = 7;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CPackObjHeader<NetError,1048576,7>::vftable;
  v4 = (char *)&this->m_Obj;
  this->m_Obj.vfptr = (PackObjVtbl *)&NetError::vftable;
  v5 = v2->m_dwCurOfs;
  v6 = this->m_Obj.vfptr;
  v7 = (int)&v2->m_pBuf[v5];
  v8 = v2->m_cbBufSize - v5;
  Buf = (CBufferIterator *)&v2->m_pBuf[v5];
  if ( ((int (__thiscall *)(NetError *, CBufferIterator **, int))v6->UnPack)(&this->m_Obj, &Buf, v8) )
  {
    v2->m_dwCurOfs = (char *)Buf - v2->m_pBuf;
    v9 = 1;
  }
  else
  {
    v9 = 0;
  }
  v10 = *(_DWORD *)v4;
  v3->m_bObjValid = v9;
  v3->m_cbData = (*(int (__thiscall **)(char *))(v10 + 8))(v4);
  v3->m_pData = (char *)v7;
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 7CA084: using guessed type int (__thiscall *CPackObjHeader<NetError,1048576,7>::vftable)(void *, char);

//----- (005AA920) --------------------------------------------------------  // acclient.c:468221
void __thiscall COnePrimHeader<512,7,sockaddr_in>::COnePrimHeader<512,7,sockaddr_in>(COnePrimHeader<512,7,sockaddr_in> *this, sockaddr_in Prim)
{
  COnePrimHeader<512,7,sockaddr_in> *v2; // eax@1
  char *v3; // ecx@1

  v2 = this;
  v3 = (char *)&this->m_Prim;
  *(_OWORD *)v3 = Prim;
  v2->m_cRef = 1;
  v2->m_dwMask = 512;
  v2->m_Flags = 7;
  v2->m_pData = v3;
  v2->m_cbData = 16;
  v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005AA970) --------------------------------------------------------  // acclient.c:468239
void __thiscall CPackObjHeader<NetError,2097152,2>::CPackObjHeader<NetError,2097152,2>(CPackObjHeader<NetError,2097152,2> *this, CBufferIterator *Buf)
{
  CBufferIterator *v2; // ebp@1
  CPackObjHeader<NetError,2097152,2> *v3; // esi@1
  char *v4; // edi@1
  unsigned int v5; // eax@1
  PackObjVtbl *v6; // edx@1
  int v7; // ebx@1
  int v8; // ST04_4@1
  char v9; // al@2
  int v10; // edx@4

  v2 = Buf;
  v3 = this;
  this->m_pData = 0;
  this->m_cbData = 0;
  this->m_pAdoptedData = 0;
  this->m_cbAdoptedData = 0;
  this->m_cRef = 1;
  this->m_dwMask = 0x200000;
  this->m_Flags = 2;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CPackObjHeader<NetError,2097152,2>::vftable;
  v4 = (char *)&this->m_Obj;
  this->m_Obj.vfptr = (PackObjVtbl *)&NetError::vftable;
  v5 = v2->m_dwCurOfs;
  v6 = this->m_Obj.vfptr;
  v7 = (int)&v2->m_pBuf[v5];
  v8 = v2->m_cbBufSize - v5;
  Buf = (CBufferIterator *)&v2->m_pBuf[v5];
  if ( ((int (__thiscall *)(NetError *, CBufferIterator **, int))v6->UnPack)(&this->m_Obj, &Buf, v8) )
  {
    v2->m_dwCurOfs = (char *)Buf - v2->m_pBuf;
    v9 = 1;
  }
  else
  {
    v9 = 0;
  }
  v10 = *(_DWORD *)v4;
  v3->m_bObjValid = v9;
  v3->m_cbData = (*(int (__thiscall **)(char *))(v10 + 8))(v4);
  v3->m_pData = (char *)v7;
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 7CA500: using guessed type int (__thiscall *CPackObjHeader<NetError,2097152,2>::vftable)(void *, char);

//----- (005AAA00) --------------------------------------------------------  // acclient.c:468286
COptionalHeader *__cdecl CTimeSyncHeader::CreateFromStream(CBufferIterator *Buf)
{
  unsigned int v1; // ecx@1
  COptionalHeader *result; // eax@2
  COptionalHeader *v3; // ecx@3
  ReferenceCountTemplate<1048576,0>Vtbl *time; // [sp+4h] [bp-8h]@2
  unsigned int time_4; // [sp+8h] [bp-4h]@2

  v1 = Buf->m_dwCurOfs;
  if ( v1 + 8 <= Buf->m_cbBufSize
    && (time = *(ReferenceCountTemplate<1048576,0>Vtbl **)&Buf->m_pBuf[v1],
        time_4 = *(_DWORD *)&Buf->m_pBuf[v1 + 4],
        Buf->m_dwCurOfs = v1 + 8,
        (result = (COptionalHeader *)operator new(0x20u)) != 0) )
  {
    v3 = result + 1;
    v3->m_cRef = time_4;
    result->m_cRef = 1;
    result->m_dwMask = 0x1000000;
    result->m_Flags = 24;
    result->m_pData = (char *)&result[1];
    result->m_cbData = 8;
    result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CTimeSyncHeader::vftable;
    v3->vfptr = time;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7CA4EC: using guessed type int (__thiscall *CTimeSyncHeader::vftable)(void *, char);

//----- (005AAA80) --------------------------------------------------------  // acclient.c:468320
void __thiscall CLogonHeader::HandshakeWireData::~HandshakeWireData(CLogonHeader::HandshakeWireData *this)
{
  AC1Legacy::PSRefBuffer<char> *v1; // esi@1

  v1 = this->ClientVersion.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&this->ClientVersion.m_buffer->m_cRef) )
  {
    if ( v1 )
      v1->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v1, 1u);
  }
}

//----- (005AAAA0) --------------------------------------------------------  // acclient.c:468333
COptionalHeader *__cdecl CEchoRequestHeader::CreateFromStream(CBufferIterator *Buf)
{
  CBufferIterator *v1; // eax@1
  unsigned int v2; // ecx@1
  COptionalHeader *result; // eax@2
  float Bufa; // [sp+8h] [bp+4h]@2

  v1 = Buf;
  v2 = Buf->m_dwCurOfs;
  if ( v2 + 4 <= Buf->m_cbBufSize
    && (Bufa = *(float *)&Buf->m_pBuf[v2],
        v1->m_dwCurOfs = v2 + 4,
        (result = (COptionalHeader *)operator new(0x1Cu)) != 0) )
  {
    *(float *)&result[1].vfptr = Bufa;
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

//----- (005AAB00) --------------------------------------------------------  // acclient.c:468364
COptionalHeader *__cdecl CEchoResponseHeader::CreateFromStream(CBufferIterator *Buf)
{
  void *v1; // esi@1
  unsigned int v2; // edx@2
  const char *v3; // edi@3

  v1 = operator new(0x28u);
  if ( v1 )
  {
    *((_DWORD *)v1 + 1) = 1;
    *((_DWORD *)v1 + 2) = 0x4000000;
    *((_DWORD *)v1 + 3) = 24;
    *((_DWORD *)v1 + 4) = (char *)v1 + 24;
    *((_DWORD *)v1 + 5) = 8;
    *(_DWORD *)v1 = &CEchoResponseHeader::vftable;
    v2 = Buf->m_dwCurOfs;
    if ( v2 + 8 <= Buf->m_cbBufSize )
    {
      v3 = Buf->m_pBuf;
      *((_DWORD *)v1 + 6) = *(_DWORD *)&Buf->m_pBuf[v2];
      *((_DWORD *)v1 + 7) = *(_DWORD *)&v3[v2 + 4];
      Buf->m_dwCurOfs += 8;
      return (COptionalHeader *)v1;
    }
    if ( !InterlockedDecrement((volatile LONG *)v1 + 1) )
      (**(void (__thiscall ***)(void *, signed int))v1)(v1, 1);
  }
  return 0;
}
// 7CA078: using guessed type int (__thiscall *CEchoResponseHeader::vftable)(void *, char);

//----- (005AAB90) --------------------------------------------------------  // acclient.c:468396
COptionalHeader *__cdecl CConnectHeader::CreateFromStream(CBufferIterator *Buf)
{
  COptionalHeader *result; // eax@1
  unsigned int v2; // ecx@2

  result = (COptionalHeader *)operator new(0x38u);
  if ( result )
  {
    result->m_cRef = 1;
    result->m_dwMask = 0x40000;
    result->m_Flags = 536870919;
    result->m_pData = (char *)&result[1];
    result->m_cbData = 32;
    result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
    v2 = Buf->m_dwCurOfs;
    if ( v2 + 32 > Buf->m_cbBufSize )
    {
      ReferenceCountTemplate<1048576,0>::Release((ReferenceCountTemplate<1048576,0> *)&result->vfptr);
      result = 0;
    }
    else
    {
      qmemcpy(&result[1], &Buf->m_pBuf[v2], 0x20u);
      Buf->m_dwCurOfs += 32;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005AAC10) --------------------------------------------------------  // acclient.c:468431
COptionalHeader *__cdecl COnePrimHeader<134217728,16,CFlowStruct>::CreateFromStream(CBufferIterator *Buf)
{
  unsigned int v1; // ecx@1
  unsigned int v2; // edx@1
  const char *v3; // ecx@2
  ReferenceCountTemplate<1048576,0>Vtbl *v4; // esi@2
  __int16 v5; // di@2
  COptionalHeader *result; // eax@2
  COptionalHeader *v7; // ecx@3

  v1 = Buf->m_dwCurOfs;
  v2 = v1 + 6;
  if ( v1 + 6 > Buf->m_cbBufSize )
  {
    result = 0;
  }
  else
  {
    v3 = &Buf->m_pBuf[v1];
    v4 = *(ReferenceCountTemplate<1048576,0>Vtbl **)v3;
    v5 = *((_WORD *)v3 + 2);
    Buf->m_dwCurOfs = v2;
    result = (COptionalHeader *)operator new(0x20u);
    if ( result )
    {
      v7 = result + 1;
      v7->vfptr = v4;
      LOWORD(v7->m_cRef) = v5;
      result->m_cRef = 1;
      result->m_dwMask = 0x8000000;
      result->m_Flags = 16;
      result->m_pData = (char *)&result[1];
      result->m_cbData = 6;
      result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005AAC80) --------------------------------------------------------  // acclient.c:468476
void __cdecl CPackObjHeader<NetError,1048576,7>::CreateFromStream(CBufferIterator *Buf)
{
  CPackObjHeader<NetError,1048576,7> *v1; // eax@1
  int v2; // eax@2

  v1 = (CPackObjHeader<NetError,1048576,7> *)operator new(0x30u);
  if ( v1 )
    CPackObjHeader<NetError,1048576,7>::CPackObjHeader<NetError,1048576,7>(v1, Buf);
  else
    v2 = 0;
  if ( !*(_BYTE *)(v2 + 44) )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
}

//----- (005AACB0) --------------------------------------------------------  // acclient.c:468491
COptionalHeader *__cdecl CSeqIDListHeader<4096,33>::CreateFromStream(CBufferIterator *Buf)
{
  void *v1; // eax@1
  void *v2; // edi@2
  unsigned int v3; // eax@4
  unsigned int v4; // ecx@4
  int v5; // ebp@5
  char v6; // al@9
  unsigned int v7; // eax@13
  unsigned int v8; // esi@13
  COptionalHeader *result; // eax@14

  v1 = operator new(0x1E4u);
  if ( v1 )
  {
    *((_DWORD *)v1 + 1) = 1;
    *((_DWORD *)v1 + 2) = 4096;
    *((_DWORD *)v1 + 3) = 33;
    *((_DWORD *)v1 + 4) = (char *)v1 + 24;
    *((_DWORD *)v1 + 5) = 460;
    *(_DWORD *)v1 = &COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
    v2 = v1;
  }
  else
  {
    v2 = 0;
  }
  v3 = Buf->m_dwCurOfs;
  v4 = Buf->m_cbBufSize;
  if ( v3 >= v4 )
    v5 = 0;
  else
    v5 = v4 - v3;
  if ( v2 != 0
    && (v3 + 4 > v4 ? (v6 = 0) : (*((_DWORD *)v2 + 6) = *(_DWORD *)&Buf->m_pBuf[v3], Buf->m_dwCurOfs += 4, v6 = 1),
        (*((_DWORD *)v2 + 6) <= 0x72u) & (unsigned __int8)v6
     && CBufferIterator::ReadPrimArray(Buf, (unsigned __int32 *)v2 + 7, *((_DWORD *)v2 + 6))) )
  {
    v7 = Buf->m_dwCurOfs;
    v8 = Buf->m_cbBufSize;
    if ( v7 >= v8 )
    {
      *((_DWORD *)v2 + 5) = v5;
      result = (COptionalHeader *)v2;
    }
    else
    {
      *((_DWORD *)v2 + 5) = v5 - (v8 - v7);
      result = (COptionalHeader *)v2;
    }
  }
  else
  {
    if ( v2 && !InterlockedDecrement((volatile LONG *)v2 + 1) )
      (**(void (__thiscall ***)(void *, signed int))v2)(v2, 1);
    result = 0;
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005AAD90) --------------------------------------------------------  // acclient.c:468553
COptionalHeader *__cdecl COnePrimHeader<16384,1,unsigned long>::CreateFromStream(CBufferIterator *Buf)
{
  unsigned int v1; // ecx@1
  ReferenceCountTemplate<1048576,0>Vtbl *v2; // esi@2
  COptionalHeader *result; // eax@2

  v1 = Buf->m_dwCurOfs;
  if ( v1 + 4 <= Buf->m_cbBufSize
    && (v2 = *(ReferenceCountTemplate<1048576,0>Vtbl **)&Buf->m_pBuf[v1],
        Buf->m_dwCurOfs = v1 + 4,
        (result = (COptionalHeader *)operator new(0x1Cu)) != 0) )
  {
    result->m_cRef = 1;
    result->m_Flags = 1;
    result[1].vfptr = v2;
    result->m_dwMask = 0x4000;
    result->m_pData = (char *)&result[1];
    result->m_cbData = 4;
    result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005AADF0) --------------------------------------------------------  // acclient.c:468582
COptionalHeader *__cdecl CSeqIDListHeader<8192,33>::CreateFromStream(CBufferIterator *Buf)
{
  void *v1; // eax@1
  void *v2; // edi@2
  unsigned int v3; // eax@4
  unsigned int v4; // ecx@4
  int v5; // ebp@5
  char v6; // al@9
  unsigned int v7; // eax@13
  unsigned int v8; // esi@13
  COptionalHeader *result; // eax@14

  v1 = operator new(0x1E4u);
  if ( v1 )
  {
    *((_DWORD *)v1 + 1) = 1;
    *((_DWORD *)v1 + 2) = 0x2000;
    *((_DWORD *)v1 + 3) = 33;
    *((_DWORD *)v1 + 4) = (char *)v1 + 24;
    *((_DWORD *)v1 + 5) = 460;
    *(_DWORD *)v1 = &COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
    v2 = v1;
  }
  else
  {
    v2 = 0;
  }
  v3 = Buf->m_dwCurOfs;
  v4 = Buf->m_cbBufSize;
  if ( v3 >= v4 )
    v5 = 0;
  else
    v5 = v4 - v3;
  if ( v2 != 0
    && (v3 + 4 > v4 ? (v6 = 0) : (*((_DWORD *)v2 + 6) = *(_DWORD *)&Buf->m_pBuf[v3], Buf->m_dwCurOfs += 4, v6 = 1),
        (*((_DWORD *)v2 + 6) <= 0x72u) & (unsigned __int8)v6
     && CBufferIterator::ReadPrimArray(Buf, (unsigned __int32 *)v2 + 7, *((_DWORD *)v2 + 6))) )
  {
    v7 = Buf->m_dwCurOfs;
    v8 = Buf->m_cbBufSize;
    if ( v7 >= v8 )
    {
      *((_DWORD *)v2 + 5) = v5;
      result = (COptionalHeader *)v2;
    }
    else
    {
      *((_DWORD *)v2 + 5) = v5 - (v8 - v7);
      result = (COptionalHeader *)v2;
    }
  }
  else
  {
    if ( v2 && !InterlockedDecrement((volatile LONG *)v2 + 1) )
      (**(void (__thiscall ***)(void *, signed int))v2)(v2, 1);
    result = 0;
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005AAED0) --------------------------------------------------------  // acclient.c:468644
COptionalHeader *__cdecl COnePrimHeader<131072,7,unsigned __int64>::CreateFromStream(CBufferIterator *Buf)
{
  unsigned int v1; // ecx@1
  ReferenceCountTemplate<1048576,0>Vtbl *v2; // esi@2
  unsigned int v3; // edi@2
  COptionalHeader *result; // eax@2
  COptionalHeader *v5; // ecx@3

  v1 = Buf->m_dwCurOfs;
  if ( v1 + 8 > Buf->m_cbBufSize )
  {
    result = 0;
  }
  else
  {
    v2 = *(ReferenceCountTemplate<1048576,0>Vtbl **)&Buf->m_pBuf[v1];
    v3 = *(_DWORD *)&Buf->m_pBuf[v1 + 4];
    Buf->m_dwCurOfs = v1 + 8;
    result = (COptionalHeader *)operator new(0x20u);
    if ( result )
    {
      v5 = result + 1;
      v5->m_cRef = v3;
      v5->vfptr = v2;
      result->m_cRef = 1;
      result->m_dwMask = 0x20000;
      result->m_Flags = 7;
      result->m_pData = (char *)&result[1];
      result->m_cbData = 8;
      result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005AAF40) --------------------------------------------------------  // acclient.c:468685
COptionalHeader *__cdecl CEmptyHeader<32768,3>::CreateFromStream()
{
  COptionalHeader *result; // eax@1

  result = (COptionalHeader *)operator new(0x1Cu);
  if ( result )
  {
    result->m_cRef = 1;
    result->m_dwMask = 0x8000;
    result->m_Flags = 3;
    result->m_pData = (char *)&result[1];
    result->m_cbData = 0;
    result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
    result[1].vfptr = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005AAF80) --------------------------------------------------------  // acclient.c:468709
COptionalHeader *__cdecl CEmptyHeader<1024,7>::CreateFromStream()
{
  COptionalHeader *result; // eax@1

  result = (COptionalHeader *)operator new(0x1Cu);
  if ( result )
  {
    result->m_cRef = 1;
    result->m_dwMask = 1024;
    result->m_Flags = 7;
    result->m_pData = (char *)&result[1];
    result->m_cbData = 0;
    result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
    result[1].vfptr = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005AAFC0) --------------------------------------------------------  // acclient.c:468733
COptionalHeader *__cdecl COnePrimHeader<524288,536870919,unsigned __int64>::CreateFromStream(CBufferIterator *Buf)
{
  unsigned int v1; // ecx@1
  ReferenceCountTemplate<1048576,0>Vtbl *v2; // esi@2
  unsigned int v3; // edi@2
  COptionalHeader *result; // eax@2
  COptionalHeader *v5; // ecx@3

  v1 = Buf->m_dwCurOfs;
  if ( v1 + 8 > Buf->m_cbBufSize )
  {
    result = 0;
  }
  else
  {
    v2 = *(ReferenceCountTemplate<1048576,0>Vtbl **)&Buf->m_pBuf[v1];
    v3 = *(_DWORD *)&Buf->m_pBuf[v1 + 4];
    Buf->m_dwCurOfs = v1 + 8;
    result = (COptionalHeader *)operator new(0x20u);
    if ( result )
    {
      v5 = result + 1;
      v5->m_cRef = v3;
      v5->vfptr = v2;
      result->m_cRef = 1;
      result->m_dwMask = 0x80000;
      result->m_Flags = 536870919;
      result->m_pData = (char *)&result[1];
      result->m_cbData = 8;
      result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005AB030) --------------------------------------------------------  // acclient.c:468774
COptionalHeader *__cdecl COnePrimHeader<256,96,CServerSwitchStruct>::CreateFromStream(CBufferIterator *Buf)
{
  unsigned int v1; // ecx@1
  ReferenceCountTemplate<1048576,0>Vtbl *v2; // esi@2
  unsigned int v3; // edi@2
  COptionalHeader *result; // eax@2
  COptionalHeader *v5; // ecx@3

  v1 = Buf->m_dwCurOfs;
  if ( v1 + 8 > Buf->m_cbBufSize )
  {
    result = 0;
  }
  else
  {
    v2 = *(ReferenceCountTemplate<1048576,0>Vtbl **)&Buf->m_pBuf[v1];
    v3 = *(_DWORD *)&Buf->m_pBuf[v1 + 4];
    Buf->m_dwCurOfs = v1 + 8;
    result = (COptionalHeader *)operator new(0x20u);
    if ( result )
    {
      v5 = result + 1;
      result->m_cRef = 1;
      result->m_dwMask = 256;
      result->m_Flags = 96;
      result->m_pData = (char *)&result[1];
      result->m_cbData = 8;
      result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
      v5->m_cRef = v3;
      v5->vfptr = v2;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005AB0A0) --------------------------------------------------------  // acclient.c:468815
void __cdecl COnePrimHeader<512,7,sockaddr_in>::CreateFromStream(CBufferIterator *Buf)
{
  unsigned int v1; // ecx@1
  unsigned int v2; // edx@1
  const char *v3; // ecx@2
  unsigned int v4; // esi@2
  unsigned int v5; // edi@2
  unsigned int v6; // ebx@2
  unsigned int v7; // ebp@2
  COnePrimHeader<512,7,sockaddr_in> *v8; // eax@2
  sockaddr_in v9; // ST00_16@3

  v1 = Buf->m_dwCurOfs;
  v2 = v1 + 16;
  if ( v1 + 16 <= Buf->m_cbBufSize )
  {
    v3 = &Buf->m_pBuf[v1];
    v4 = *(_DWORD *)v3;
    v5 = *((_DWORD *)v3 + 1);
    v6 = *((_DWORD *)v3 + 2);
    v7 = *((_DWORD *)v3 + 3);
    Buf->m_dwCurOfs = v2;
    v8 = (COnePrimHeader<512,7,sockaddr_in> *)operator new(0x28u);
    if ( v8 )
    {
      *(_QWORD *)&v9.sin_family = __PAIR__(v5, v4);
      *(_QWORD *)&v9.sin_zero[0] = __PAIR__(v7, v6);
      COnePrimHeader<512,7,sockaddr_in>::COnePrimHeader<512,7,sockaddr_in>(v8, v9);
    }
  }
}

//----- (005AB100) --------------------------------------------------------  // acclient.c:468848
COptionalHeader *__cdecl COnePrimHeader<2048,1073741922,CReferralStruct>::CreateFromStream(CBufferIterator *Buf)
{
  unsigned int v1; // ecx@1
  COptionalHeader *result; // eax@2
  CReferralStruct Prim; // [sp+4h] [bp-20h]@2

  v1 = Buf->m_dwCurOfs;
  if ( v1 + 32 > Buf->m_cbBufSize )
  {
    result = 0;
  }
  else
  {
    qmemcpy(&Prim, &Buf->m_pBuf[v1], sizeof(Prim));
    Buf->m_dwCurOfs = v1 + 32;
    result = (COptionalHeader *)operator new(0x38u);
    if ( result )
    {
      result->m_pData = (char *)&result[1];
      qmemcpy(&result[1], &Prim, 0x20u);
      result->m_cRef = 1;
      result->m_dwMask = 2048;
      result->m_Flags = 1073741922;
      result->m_cbData = 32;
      result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005AB180) --------------------------------------------------------  // acclient.c:468884
COptionalHeader *__cdecl COnePrimHeader<4194304,7,CICMDCommandStruct>::CreateFromStream(CBufferIterator *Buf)
{
  unsigned int v1; // ecx@1
  ReferenceCountTemplate<1048576,0>Vtbl *v2; // esi@2
  unsigned int v3; // edi@2
  COptionalHeader *result; // eax@2
  COptionalHeader *v5; // ecx@3

  v1 = Buf->m_dwCurOfs;
  if ( v1 + 8 > Buf->m_cbBufSize )
  {
    result = 0;
  }
  else
  {
    v2 = *(ReferenceCountTemplate<1048576,0>Vtbl **)&Buf->m_pBuf[v1];
    v3 = *(_DWORD *)&Buf->m_pBuf[v1 + 4];
    Buf->m_dwCurOfs = v1 + 8;
    result = (COptionalHeader *)operator new(0x20u);
    if ( result )
    {
      v5 = result + 1;
      v5->m_cRef = v3;
      v5->vfptr = v2;
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
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005AB1F0) --------------------------------------------------------  // acclient.c:468925
void __cdecl CPackObjHeader<NetError,2097152,2>::CreateFromStream(CBufferIterator *Buf)
{
  CPackObjHeader<NetError,2097152,2> *v1; // eax@1
  int v2; // eax@2

  v1 = (CPackObjHeader<NetError,2097152,2> *)operator new(0x30u);
  if ( v1 )
    CPackObjHeader<NetError,2097152,2>::CPackObjHeader<NetError,2097152,2>(v1, Buf);
  else
    v2 = 0;
  if ( !*(_BYTE *)(v2 + 44) )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
}

//----- (005AB220) --------------------------------------------------------  // acclient.c:468940
void __thiscall CLogonHeader::CLogonHeader(CLogonHeader *this, unsigned int cbPackedData)
{
  volatile LONG *v2; // ST00_4@1

  this->m_pData = this->m_PackedData;
  this->m_cRef = 1;
  this->m_dwMask = 0x10000;
  this->m_Flags = 7;
  this->m_cbData = cbPackedData;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CLogonHeader::vftable;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->m_UnpackedData.ClientVersion.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
}
// 7E6020: using guessed type int (__thiscall *CLogonHeader::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005AB270) --------------------------------------------------------  // acclient.c:468958
void __thiscall CLogonHeader::CLogonHeader(CLogonHeader *this, const char *pRecvBuf, unsigned int cbRecvBuf)
{
  volatile LONG *v3; // ST00_4@1

  this->m_pData = (char *)pRecvBuf;
  this->m_cRef = 1;
  this->m_dwMask = 0x10000;
  this->m_Flags = 7;
  this->m_cbData = cbRecvBuf;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CLogonHeader::vftable;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->m_UnpackedData.ClientVersion.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
}
// 7E6020: using guessed type int (__thiscall *CLogonHeader::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005AB2C0) --------------------------------------------------------  // acclient.c:468976
CLogonHeader *__thiscall CLogonHeader::scalar_deleting_destructor(CLogonHeader *this, unsigned int a2)
{
  CLogonHeader *v2; // esi@1

  v2 = this;
  CLogonHeader::HandshakeWireData::~HandshakeWireData(&this->m_UnpackedData);
  v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);

//----- (005AB2F0) --------------------------------------------------------  // acclient.c:468990
COptionalHeader *__cdecl CLogonHeader::CreateFromData(AC1Legacy::PStringBase<char> *ClientVersion, NetAuthenticator *pNetAuth)
{
  NetAuthenticator *v2; // ebp@1
  PackObjVtbl *v3; // ebx@1
  unsigned int v4; // eax@1
  signed int v5; // ecx@1
  int v6; // edx@3
  int v7; // ecx@3
  int v8; // eax@4
  unsigned int v9; // esi@6
  CLogonHeader *v10; // eax@6
  int v11; // eax@7
  int v12; // edi@7
  int v13; // esi@9
  COptionalHeader *result; // eax@12

  v2 = pNetAuth;
  v3 = (PackObjVtbl *)(*(int (__thiscall **)(NetAuthenticator *))&pNetAuth->vfptr->gap4[0])(pNetAuth);
  v4 = ClientVersion->m_buffer->m_len - 1;
  v5 = 0;
  if ( v4 >= 0xFFFF )
    v5 = 4;
  v6 = v5 + v4 + 2;
  v7 = ((_BYTE)v5 + (_BYTE)v4 + 2) & 3;
  if ( v7 )
    v8 = 4 - v7;
  else
    v8 = 0;
  v9 = (unsigned int)(&v3->gap4[v6] + v8);
  v10 = (CLogonHeader *)operator new(0x10000u);
  if ( v10 )
  {
    CLogonHeader::CLogonHeader(v10, v9);
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  pNetAuth = (NetAuthenticator *)(v12 + 32);
  v13 = v9 - AC1Legacy::PStringBase<char>::Pack(ClientVersion, (void **)&pNetAuth, v9);
  if ( (unsigned int)v13 >= 4 )
  {
    pNetAuth->vfptr = v3;
    pNetAuth = (NetAuthenticator *)((char *)pNetAuth + 4);
    v13 -= 4;
  }
  ClientVersion = (AC1Legacy::PStringBase<char> *)v13;
  if ( pNetAuth )
  {
    ((void (__thiscall *)(NetAuthenticator *, signed int, NetAuthenticator **, AC1Legacy::PStringBase<char> **))v2->vfptr[1].__vecDelDtor)(
      v2,
      1,
      &pNetAuth,
      &ClientVersion);
    result = (COptionalHeader *)v12;
  }
  else
  {
    ((void (__thiscall *)(NetAuthenticator *))v2->vfptr->GetPackSize)(v2);
    result = (COptionalHeader *)v12;
  }
  return result;
}

//----- (005AB3C0) --------------------------------------------------------  // acclient.c:469056
int __cdecl CLogonHeader::CreateFromStream(CBufferIterator *Buf)
{
  CBufferIterator *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  const char *v4; // esi@4
  int v5; // ebp@4
  unsigned int v6; // ST04_4@4
  const char *v7; // edi@5
  unsigned int v8; // ecx@5
  char *v9; // edx@5
  int v10; // eax@5
  unsigned int v11; // edi@6
  signed int v12; // edx@7
  int v13; // ebp@12
  CLogonHeader *v14; // eax@14
  int v15; // eax@15
  int v16; // esi@17
  CBufferIterator *v17; // edi@17
  unsigned int v18; // eax@22
  unsigned int v19; // edx@22
  void *addr; // [sp+10h] [bp-8h]@4
  unsigned int StartSize; // [sp+14h] [bp-4h]@2

  v1 = Buf;
  v2 = Buf->m_dwCurOfs;
  v3 = Buf->m_cbBufSize;
  if ( v2 >= v3 )
    StartSize = 0;
  else
    StartSize = v3 - v2;
  v4 = &Buf->m_pBuf[v2];
  Buf = (CBufferIterator *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v5 = 0;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v6 = v1->m_cbBufSize - v1->m_dwCurOfs;
  addr = (void *)&v1->m_pBuf[v1->m_dwCurOfs];
  if ( !AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&Buf, &addr, v6) )
    goto LABEL_24;
  v7 = v1->m_pBuf;
  v8 = v1->m_cbBufSize;
  v9 = (char *)((_BYTE *)addr - v1->m_pBuf);
  v10 = (int)(v9 + 4);
  v1->m_dwCurOfs = (unsigned int)v9;
  if ( (unsigned int)(v9 + 4) > v8 )
    goto LABEL_24;
  v11 = *(_DWORD *)&v7[(_DWORD)v9];
  v1->m_dwCurOfs = v10;
  v12 = (unsigned int)(v9 + 4) >= v8 ? 0 : v8 - v10;
  if ( v11 > v12 || v11 > 0xFFE0 )
    goto LABEL_24;
  if ( v10 >= v8 )
    v13 = 0;
  else
    v13 = v8 - v10;
  v14 = (CLogonHeader *)operator new(0x10000u);
  if ( v14 )
  {
    CLogonHeader::CLogonHeader(v14, v4, StartSize + v11 - v13);
    v5 = v15;
  }
  else
  {
    v5 = 0;
  }
  *(_DWORD *)(v5 + 28) = v11;
  v16 = *(_DWORD *)(v5 + 24);
  v17 = Buf;
  if ( (CBufferIterator *)v16 != Buf )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v16 + 4)) && v16 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
    *(_DWORD *)(v5 + 24) = v17;
    InterlockedIncrement((volatile LONG *)&v17->m_dwCurOfs);
  }
  v18 = *(_DWORD *)(v5 + 28);
  v19 = v1->m_dwCurOfs;
  if ( v19 + v18 <= v1->m_cbBufSize )
  {
    qmemcpy((void *)(v5 + 32), &v1->m_pBuf[v19], v18);
    v1->m_dwCurOfs += v18;
LABEL_24:
    v17 = Buf;
    goto LABEL_25;
  }
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v5 = 0;
LABEL_25:
  if ( !InterlockedDecrement((volatile LONG *)&v17->m_dwCurOfs) && v17 )
    (*(void (__thiscall **)(CBufferIterator *, signed int))v17->m_pBuf)(v17, 1);
  return v5;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0070DF40) --------------------------------------------------------  // acclient.c:800933
int _E77_24()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_46;
  dword_8EE0D0 = LOWEST_DATA_RATE_46;
  return result;
}

//----- (0070DF50) --------------------------------------------------------  // acclient.c:800943
void _E79_70()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(
    0x8000000u,
    COnePrimHeader<134217728,16,CFlowStruct>::CreateFromStream);
}

//----- (0070DF70) --------------------------------------------------------  // acclient.c:800951
void _E81()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(0x1000000u, CTimeSyncHeader::CreateFromStream);
}

//----- (0070DF90) --------------------------------------------------------  // acclient.c:800957
void _E83()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(
    0x100000u,
    (COptionalHeader *(__cdecl *)(CBufferIterator *))CPackObjHeader<NetError,1048576,7>::CreateFromStream);
}

//----- (0070DFB0) --------------------------------------------------------  // acclient.c:800965
void _E85_32()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(0x1000u, CSeqIDListHeader<4096,33>::CreateFromStream);
}

//----- (0070DFD0) --------------------------------------------------------  // acclient.c:800971
void _E87_0()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(0x4000u, COnePrimHeader<16384,1,unsigned long>::CreateFromStream);
}

//----- (0070DFF0) --------------------------------------------------------  // acclient.c:800977
void _E89_10()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(0x2000u, CSeqIDListHeader<8192,33>::CreateFromStream);
}

//----- (0070E010) --------------------------------------------------------  // acclient.c:800983
void sub_70E010()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(0x2000000u, CEchoRequestHeader::CreateFromStream);
}

//----- (0070E030) --------------------------------------------------------  // acclient.c:800989
void sub_70E030()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(0x4000000u, CEchoResponseHeader::CreateFromStream);
}

//----- (0070E050) --------------------------------------------------------  // acclient.c:800995
void sub_70E050()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(
    0x20000u,
    COnePrimHeader<131072,7,unsigned __int64>::CreateFromStream);
}

//----- (0070E070) --------------------------------------------------------  // acclient.c:801003
void sub_70E070()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(
    0x10000u,
    (COptionalHeader *(__cdecl *)(CBufferIterator *))CLogonHeader::CreateFromStream);
}

//----- (0070E090) --------------------------------------------------------  // acclient.c:801011
void _E99_41()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(
    0x8000u,
    (COptionalHeader *(__cdecl *)(CBufferIterator *))CEmptyHeader<32768,3>::CreateFromStream);
}

//----- (0070E0B0) --------------------------------------------------------  // acclient.c:801019
void _E101_41()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(
    0x400u,
    (COptionalHeader *(__cdecl *)(CBufferIterator *))CEmptyHeader<1024,7>::CreateFromStream);
}

//----- (0070E0D0) --------------------------------------------------------  // acclient.c:801027
void sub_70E0D0()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(0x40000u, CConnectHeader::CreateFromStream);
}

//----- (0070E0F0) --------------------------------------------------------  // acclient.c:801033
void _E105_55()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(
    0x80000u,
    COnePrimHeader<524288,536870919,unsigned __int64>::CreateFromStream);
}

//----- (0070E110) --------------------------------------------------------  // acclient.c:801041
void _E107_45()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(
    0x100u,
    COnePrimHeader<256,96,CServerSwitchStruct>::CreateFromStream);
}

//----- (0070E130) --------------------------------------------------------  // acclient.c:801049
void _E109_83()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(
    0x200u,
    (COptionalHeader *(__cdecl *)(CBufferIterator *))COnePrimHeader<512,7,sockaddr_in>::CreateFromStream);
}

//----- (0070E150) --------------------------------------------------------  // acclient.c:801057
void _E111_58()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(
    0x800u,
    COnePrimHeader<2048,1073741922,CReferralStruct>::CreateFromStream);
}

//----- (0070E170) --------------------------------------------------------  // acclient.c:801065
void _E113_32()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(
    0x400000u,
    COnePrimHeader<4194304,7,CICMDCommandStruct>::CreateFromStream);
}

//----- (0070E190) --------------------------------------------------------  // acclient.c:801073
void _E115_89()
{
  COptionalHeaderFactory::RegisterOptionalHeaderType(
    0x200000u,
    (COptionalHeader *(__cdecl *)(CBufferIterator *))CPackObjHeader<NetError,2097152,2>::CreateFromStream);
}

//----- (0070E1B0) --------------------------------------------------------  // acclient.c:801081
int sub_70E1B0()
{
  return atexit(nullsub_1534);
}

