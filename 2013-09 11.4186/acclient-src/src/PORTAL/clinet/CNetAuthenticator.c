/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CNetAuthenticator
   Object     : PORTAL\clinet\CNetAuthenticator.obj
   Functions  : 14
   Addresses  : 00540590 - 00540A10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00540590) --------------------------------------------------------  // acclient.c:367792
BOOL __thiscall NetAuthenticator::CGrowBuffer::Grow(NetAuthenticator::CGrowBuffer *this, unsigned int new_size)
{
  NetAuthenticator::CGrowBuffer *v2; // esi@1
  char *v3; // ecx@3

  v2 = this;
  if ( new_size > this->m_cbAllocatedSize )
  {
    operator delete[](this->m_pBuf);
    v2->m_cbAllocatedSize = new_size;
    v2->m_pBuf = (char *)operator new[](new_size);
  }
  v3 = v2->m_pBuf;
  v2->m_cbCurSize = new_size;
  return v3 != 0;
}

//----- (005405D0) --------------------------------------------------------  // acclient.c:367810
int __cdecl STREAMPACK_BYTES(STREAMTYPE op, char *data, unsigned int numBytes, void **addr, unsigned int *size)
{
  if ( numBytes )
  {
    if ( op == STREAM_GETPACKSIZE )
    {
LABEL_6:
      *size -= numBytes;
      return 1;
    }
    if ( op == 1 )
    {
      qmemcpy(*addr, data, numBytes);
      *addr = (char *)*addr + numBytes;
      *size -= numBytes;
      return 1;
    }
    if ( op == 2 )
    {
      qmemcpy(data, *addr, numBytes);
      *addr = (char *)*addr + numBytes;
      goto LABEL_6;
    }
  }
  return 0;
}

//----- (00540660) --------------------------------------------------------  // acclient.c:367838
unsigned int __thiscall NetAuthenticator::GetPackSize(NetAuthenticator *this)
{
  PackObjVtbl *v1; // edx@1
  unsigned int size; // [sp+Ch] [bp-8h]@1
  void *addr; // [sp+10h] [bp-4h]@1

  v1 = this->vfptr;
  addr = 0;
  size = 0;
  ((void (__stdcall *)(_DWORD, void **, unsigned int *))v1[1].__vecDelDtor)(0, &addr, &size);
  return -size;
}

//----- (00540690) --------------------------------------------------------  // acclient.c:367852
unsigned int __thiscall StreamPackObj::Pack(StreamPackObj *this, void **addr, unsigned int size)
{
  unsigned int result; // eax@2
  unsigned int v4; // esi@3

  if ( *addr )
  {
    v4 = size;
    ((void (__stdcall *)(signed int, void **, unsigned int *))this->vfptr[1].__vecDelDtor)(1, addr, &size);
    result = v4 - size;
  }
  else
  {
    result = ((int (*)(void))this->vfptr->GetPackSize)();
  }
  return result;
}

//----- (005406D0) --------------------------------------------------------  // acclient.c:367871
int __thiscall StreamPackObj::UnPack(StreamPackObj *this, void **addr, unsigned int size)
{
  return ((int (__stdcall *)(signed int, void **, unsigned int *))this->vfptr[1].__vecDelDtor)(2, addr, &size);
}

//----- (005406F0) --------------------------------------------------------  // acclient.c:367877
int __cdecl STREAMPACK(STREAMTYPE op, unsigned int *obj, void **addr, unsigned int *size)
{
  int result; // eax@4
  unsigned int *v5; // ecx@5

  if ( op )
  {
    if ( op == 1 )
    {
      if ( *size >= 4 )
      {
        *(_DWORD *)*addr = *obj;
        *addr = (char *)*addr + 4;
      }
      *size -= 4;
      result = 1;
    }
    else if ( op == 2 )
    {
      v5 = (unsigned int *)*addr;
      if ( *size >= 4 )
      {
        *obj = *v5;
        *addr = (char *)*addr + 4;
        *size += (char *)v5 - (_BYTE *)*addr;
        result = 1;
      }
      else
      {
        result = 0;
        *size = *size;
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    *size -= 4;
    result = 1;
  }
  return result;
}

//----- (00540780) --------------------------------------------------------  // acclient.c:367924
int __thiscall NetAuthenticator::CGrowBuffer::StreamPack(NetAuthenticator::CGrowBuffer *this, STREAMTYPE op, void **addr, unsigned int *size)
{
  NetAuthenticator::CGrowBuffer *v4; // esi@1
  unsigned int *v5; // edi@1
  unsigned int v6; // edi@5

  v4 = this;
  v5 = &this->m_cbCurSize;
  if ( !STREAMPACK(op, &this->m_cbCurSize, addr, size) )
    return 0;
  if ( op == 2 )
  {
    if ( *v5 > *size )
      return 0;
    NetAuthenticator::CGrowBuffer::Grow(v4, *v5);
  }
  v6 = *v5;
  if ( !v6 || STREAMPACK_BYTES(op, v4->m_pBuf, v6, addr, size) )
    return 1;
  return 0;
}

//----- (005407F0) --------------------------------------------------------  // acclient.c:367947
void __thiscall NetAuthenticator::NetAuthenticator(NetAuthenticator *this)
{
  NetAuthenticator *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&NetAuthenticator::vftable;
  this->m_dwAuthType = 0;
  this->m_dwAuthFlags = 0;
  this->m_dwConnectionSequenceNumber = 0;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->m_Account.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v1->m_Account.fIsDarkMajestyExpansion_ = 0;
  v1->m_Account.m_fIsThroneOfDestinyExpansion = 0;
  v1->m_Account.m_fPreOrderedThroneOfDestinyExpansion = 0;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->m_AccountToLogonAs.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v1->m_AccountToLogonAs.fIsDarkMajestyExpansion_ = 0;
  v1->m_AccountToLogonAs.m_fIsThroneOfDestinyExpansion = 0;
  v1->m_AccountToLogonAs.m_fPreOrderedThroneOfDestinyExpansion = 0;
  v1->m_CryptoData.m_pBuf = 0;
  v1->m_CryptoData.m_cbAllocatedSize = 0;
  v1->m_CryptoData.m_cbCurSize = 0;
  v1->m_ExtraData.m_pBuf = 0;
  v1->m_ExtraData.m_cbAllocatedSize = 0;
  v1->m_ExtraData.m_cbCurSize = 0;
}
// 7C9DD8: using guessed type int (__thiscall *NetAuthenticator::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00540860) --------------------------------------------------------  // acclient.c:367981
unsigned int __thiscall NetAuthenticator::Pack(NetAuthenticator *this, void **addr, unsigned int size)
{
  unsigned int v3; // esi@1
  unsigned int result; // eax@2

  v3 = size;
  if ( *addr )
  {
    ((void (__stdcall *)(signed int, void **, unsigned int *))this->vfptr[1].__vecDelDtor)(1, addr, &size);
    result = v3 - size;
  }
  else
  {
    result = ((int (*)(void))this->vfptr->GetPackSize)();
  }
  return result;
}

//----- (005408A0) --------------------------------------------------------  // acclient.c:368000
int __cdecl STREAMPACK_STREAMPACKOBJ(STREAMTYPE op, NetAuthenticator::CGrowBuffer *obj, void **addr, unsigned int *size)
{
  return NetAuthenticator::CGrowBuffer::StreamPack(obj, op, addr, size);
}

//----- (005408C0) --------------------------------------------------------  // acclient.c:368006
NetAuthenticator *__thiscall NetAuthenticator::scalar_deleting_destructor(NetAuthenticator *this, unsigned int a2)
{
  NetAuthenticator *v2; // esi@1

  v2 = this;
  NetAuthenticator::~NetAuthenticator(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005408E0) --------------------------------------------------------  // acclient.c:368018
int __cdecl STREAMPACK(STREAMTYPE op, accountID *obj, void **addr, unsigned int *size)
{
  int result; // eax@4
  void *v5; // esi@5
  unsigned int v6; // eax@7
  signed int v7; // ecx@7
  int v8; // edx@9
  int v9; // eax@9

  if ( op )
  {
    if ( op == 1 )
    {
      *size -= AC1Legacy::PStringBase<char>::Pack((AC1Legacy::PStringBase<char> *)&obj->m_buffer, addr, *size);
      result = 1;
    }
    else if ( op == 2 )
    {
      v5 = *addr;
      result = AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&obj->m_buffer, addr, *size);
      *size += (_BYTE *)v5 - (_BYTE *)*addr;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    v6 = obj->m_buffer->m_len - 1;
    v7 = 0;
    if ( v6 >= 0xFFFF )
      v7 = 4;
    v8 = v7 + v6 + 2;
    v9 = ((_BYTE)v7 + (_BYTE)v6 + 2) & 3;
    if ( v9 )
    {
      *size -= v8 + 4 - v9;
      result = 1;
    }
    else
    {
      *size -= v8;
      result = 1;
    }
  }
  return result;
}

//----- (00540990) --------------------------------------------------------  // acclient.c:368068
char __thiscall NetAuthenticator::SetToAuthType(NetAuthenticator *this, unsigned int dwAuthType, accountID *Account, unsigned int dwBinaryLen, const char *pData)
{
  NetAuthenticator *v5; // edi@1
  char *v6; // esi@1

  v5 = this;
  this->m_dwAuthType = dwAuthType;
  v6 = (char *)&this->m_Account;
  AC1Legacy::PStringBase<char>::set(
    (AC1Legacy::PStringBase<char> *)&this->m_Account.m_buffer,
    Account->m_buffer->m_data);
  *((_DWORD *)v6 + 1) = Account->fIsDarkMajestyExpansion_;
  *((_DWORD *)v6 + 2) = Account->m_fIsThroneOfDestinyExpansion;
  *((_DWORD *)v6 + 3) = Account->m_fPreOrderedThroneOfDestinyExpansion;
  if ( pData )
  {
    if ( dwBinaryLen > v5->m_ExtraData.m_cbAllocatedSize )
    {
      operator delete[](v5->m_ExtraData.m_pBuf);
      v5->m_ExtraData.m_cbAllocatedSize = dwBinaryLen;
      v5->m_ExtraData.m_pBuf = (char *)operator new[](dwBinaryLen);
    }
    v5->m_ExtraData.m_cbCurSize = dwBinaryLen;
    qmemcpy(v5->m_ExtraData.m_pBuf, pData, dwBinaryLen);
  }
  return 1;
}

//----- (00540A10) --------------------------------------------------------  // acclient.c:368097
int __thiscall NetAuthenticator::StreamPack(NetAuthenticator *this, STREAMTYPE op, void **addr, unsigned int *size)
{
  NetAuthenticator *v4; // esi@1
  int result; // eax@8

  v4 = this;
  if ( STREAMPACK(op, &this->m_dwAuthType, addr, size)
    && STREAMPACK(op, &v4->m_dwAuthFlags, addr, size)
    && STREAMPACK(op, &v4->m_dwConnectionSequenceNumber, addr, size)
    && STREAMPACK(op, &v4->m_Account, addr, size)
    && (!(v4->m_dwAuthFlags & 2) || STREAMPACK(op, &v4->m_AccountToLogonAs, addr, size))
    && NetAuthenticator::CGrowBuffer::StreamPack(&v4->m_CryptoData, op, addr, size) )
    result = STREAMPACK_STREAMPACKOBJ(op, &v4->m_ExtraData, addr, size) != 0;
  else
    result = 0;
  return result;
}

