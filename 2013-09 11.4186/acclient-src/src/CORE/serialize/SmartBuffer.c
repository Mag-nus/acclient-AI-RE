/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SmartBuffer
   Object     : CORE\serialize\SmartBuffer.obj
   Functions  : 23
   Addresses  : 00406A60 - 00725C40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00406A60) --------------------------------------------------------  // acclient.c:65918
void __thiscall SmartBuffer::SmartBuffer(SmartBuffer *this)
{
  this->m_startOffset = 0;
  this->m_size = 0;
  this->m_masterBuffer = 0;
}

//----- (00406A70) --------------------------------------------------------  // acclient.c:65926
char __thiscall SmartBuffer::CanGrow(SmartBuffer *this)
{
  GrowBuffer *v1; // eax@1
  char result; // al@2

  v1 = this->m_masterBuffer;
  if ( v1 )
    result = v1->m_bCanResize;
  else
    result = 1;
  return result;
}

//----- (00406A80) --------------------------------------------------------  // acclient.c:65940
unsigned int __thiscall SmartBuffer::GetBuffer(SmartBuffer *this)
{
  GrowBuffer *v1; // eax@1
  unsigned int result; // eax@2

  v1 = this->m_masterBuffer;
  if ( v1 )
    result = (unsigned int)&v1->m_data[this->m_startOffset];
  else
    result = 0;
  return result;
}

//----- (00406A90) --------------------------------------------------------  // acclient.c:65954
char *__thiscall SmartBuffer::Orphan(SmartBuffer *this)
{
  GrowBuffer *v1; // eax@1
  char *result; // eax@2

  v1 = this->m_masterBuffer;
  if ( v1 )
  {
    v1->m_ownsBuffer = 0;
    v1->m_bCanResize = 0;
    result = v1->m_data;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00406AB0) --------------------------------------------------------  // acclient.c:65974
unsigned int __thiscall SmartBuffer::GetSize(SmartBuffer *this)
{
  return this->m_size;
}

//----- (00406AC0) --------------------------------------------------------  // acclient.c:65980
unsigned int __thiscall SmartBuffer::GetShareCount(SmartBuffer *this)
{
  GrowBuffer *v1; // eax@1
  unsigned int result; // eax@2

  v1 = this->m_masterBuffer;
  if ( v1 )
    result = v1->m_cRef;
  else
    result = 0;
  return result;
}

//----- (00406AD0) --------------------------------------------------------  // acclient.c:65994
void __thiscall CSpinLock<1048576,0>::Enter(CSpinLock<1048576,0> *this)
{
  volatile LONG *v1; // edi@1
  unsigned int v2; // esi@1

  v1 = (volatile LONG *)this;
  v2 = 0;
  while ( InterlockedExchange(v1, 1) )
  {
    while ( *v1 )
    {
      ++v2;
      if ( v2 >= 0x100000 )
      {
        Sleep(0);
        v2 = 0;
      }
    }
  }
}

//----- (00406B20) --------------------------------------------------------  // acclient.c:66016
unsigned int __stdcall GrowBuffer::GetGoodSize(unsigned int i_sizeNeeded)
{
  unsigned int result; // eax@2
  signed int v8; // edx@5

  if ( i_sizeNeeded <= 0x40000 )
  {
    if ( i_sizeNeeded >= 0x10 )
    {
      __asm { bsr     eax, [esp+4+i_sizeNeeded] }
      v8 = 1 << _EAX;
      result = 1 << _EAX;
      if ( result > 0x1800 )
        result = v8 + 3072;
      if ( result < i_sizeNeeded )
        result += v8;
    }
    else
    {
      result = 16;
    }
  }
  else
  {
    result = i_sizeNeeded + 0x3FFFF - ((i_sizeNeeded + 0x3FFFF) & 0x3FFFF);
  }
  return result;
}

//----- (00406B80) --------------------------------------------------------  // acclient.c:66046
void __thiscall GrowBuffer::FreeBuffer(GrowBuffer *this)
{
  GrowBuffer *v1; // esi@1
  unsigned int v2; // eax@3
  signed int v3; // edi@3
  signed int v4; // ebp@6
  unsigned __int32 v5; // ebx@6
  int v6; // edx@8
  unsigned int v7; // eax@8
  int v8; // ecx@9
  struct GrowBuffer::FreeGrowBuffer *v9; // eax@15

  v1 = this;
  if ( this->m_ownsBuffer )
  {
    if ( this->m_bAllocateFromFreelist )
    {
      v2 = this->m_size;
      v3 = 0;
      if ( v2 )
      {
        if ( v2 < 0x200000 && GrowBuffer::m_pFreeListLock )
        {
          v4 = -1;
          CSpinLock<1048576,0>::Enter(GrowBuffer::m_pFreeListLock);
          v5 = GrowBuffer::m_nFreeListEntries;
          if ( GrowBuffer::m_nFreeListEntries >= 8 )
          {
            v6 = dword_83675C[0];
            v7 = GrowBuffer::m_nFreeListEntries;
            while ( v7 > 1 )
            {
              v8 = dword_836754[2 * v7--];
              if ( v6 > (unsigned int)v8 )
              {
                v6 = v8;
                v3 = v7;
              }
            }
            if ( v6 < v1->m_size )
              v4 = v3;
          }
          else
          {
            v4 = GrowBuffer::m_nFreeListEntries;
            v5 = GrowBuffer::m_nFreeListEntries + 1;
            (&GrowBuffer::m_FreeList)[GrowBuffer::m_nFreeListEntries] = 0;
            GrowBuffer::m_nFreeListEntries = v5;
          }
          if ( v4 < v5 )
          {
            v9 = (struct GrowBuffer::FreeGrowBuffer *)v1->m_data;
            v1->m_data = (char *)&(&GrowBuffer::m_FreeList)[v4]->pData;
            (&GrowBuffer::m_FreeList)[v4] = v9;
            dword_83675C[2 * v4] = v1->m_size;
          }
          InterlockedExchange(&GrowBuffer::m_pFreeListLock->m_Lock, 0);
        }
      }
    }
    operator delete[](v1->m_data);
  }
  v1->m_data = 0;
  v1->m_size = 0;
}
// 836754: using guessed type int dword_836754[];
// 836758: using guessed type struct GrowBuffer::FreeGrowBuffer *GrowBuffer::m_FreeList;
// 83675C: using guessed type int dword_83675C[];
// 83679C: using guessed type unsigned __int32 GrowBuffer::m_nFreeListEntries;

//----- (00406C60) --------------------------------------------------------  // acclient.c:66117
void __thiscall SmartBuffer::SmartBuffer(SmartBuffer *this, SmartBuffer *i_rhs)
{
  GrowBuffer *v2; // eax@1

  this->m_startOffset = i_rhs->m_startOffset;
  this->m_size = i_rhs->m_size;
  v2 = i_rhs->m_masterBuffer;
  this->m_masterBuffer = v2;
  if ( v2 )
    InterlockedIncrement((volatile LONG *)&v2->m_cRef);
}

//----- (00406C90) --------------------------------------------------------  // acclient.c:66130
void __thiscall SmartBuffer::ReleaseMasterBuffer(SmartBuffer *this)
{
  SmartBuffer *v1; // esi@1
  GrowBuffer *v2; // edi@1

  v1 = this;
  v2 = this->m_masterBuffer;
  if ( v2 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
      v2->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, 1u);
    v1->m_masterBuffer = 0;
  }
  v1->m_startOffset = 0;
  v1->m_size = 0;
}

//----- (00406CD0) --------------------------------------------------------  // acclient.c:66148
GrowBuffer *__thiscall GrowBuffer::scalar_deleting_destructor(GrowBuffer *this, unsigned int a2)
{
  GrowBuffer *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&GrowBuffer::vftable;
  GrowBuffer::FreeBuffer(this);
  v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 7942F8: using guessed type int (__thiscall *GrowBuffer::vftable)(void *, char);

//----- (00406D00) --------------------------------------------------------  // acclient.c:66164
void GrowBuffer::GrowExact::_2::FreeListLockAllocator::~FreeListLockAllocator()
{
  unsigned __int32 v1; // esi@3
  void *v2; // eax@4

  if ( GrowBuffer::m_pFreeListLock )
    operator delete(GrowBuffer::m_pFreeListLock);
  v1 = GrowBuffer::m_nFreeListEntries;
  GrowBuffer::m_pFreeListLock = 0;
  while ( v1 )
  {
    v2 = *(&PStringBase<unsigned short>::whitespace_string + 2 * v1--);
    operator delete[](v2);
  }
  GrowBuffer::m_nFreeListEntries = 0;
}
// 83679C: using guessed type unsigned __int32 GrowBuffer::m_nFreeListEntries;

//----- (00406D60) --------------------------------------------------------  // acclient.c:66183
void __thiscall SmartBuffer::SmartBuffer(SmartBuffer *this, void *i_addr, unsigned int i_size)
{
  SmartBuffer *v3; // edi@1
  void *v4; // eax@1
  void *v5; // esi@2

  v3 = this;
  this->m_startOffset = 0;
  this->m_size = i_size;
  v4 = operator new(0x14u);
  if ( v4 )
  {
    *((_DWORD *)v4 + 1) = 1;
    *(_DWORD *)v4 = &GrowBuffer::vftable;
    *((_DWORD *)v4 + 2) = 0;
    *((_DWORD *)v4 + 3) = 0;
    *((_BYTE *)v4 + 16) = 1;
    *((_BYTE *)v4 + 17) = 1;
    *((_BYTE *)v4 + 18) = 0;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v3->m_masterBuffer = (GrowBuffer *)v5;
  GrowBuffer::FreeBuffer((GrowBuffer *)v5);
  *((_DWORD *)v5 + 2) = i_addr;
  *((_DWORD *)v5 + 3) = i_size;
  *((_BYTE *)v5 + 16) = 0;
  *((_BYTE *)v5 + 17) = 0;
}
// 7942F8: using guessed type int (__thiscall *GrowBuffer::vftable)(void *, char);

//----- (00406DD0) --------------------------------------------------------  // acclient.c:66218
int __thiscall SmartBuffer::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // edi@2
  int v4; // eax@7

  v2 = this;
  if ( a2 != this )
  {
    v3 = *(_DWORD *)(this + 8);
    if ( v3 )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      *(_DWORD *)(v2 + 8) = 0;
    }
    *(_DWORD *)v2 = 0;
    *(_DWORD *)(v2 + 4) = 0;
    v4 = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(v2 + 8) = v4;
    if ( v4 )
      InterlockedIncrement((volatile LONG *)(v4 + 4));
    *(_DWORD *)v2 = *(_DWORD *)a2;
    *(_DWORD *)(v2 + 4) = *(_DWORD *)(a2 + 4);
  }
  return v2;
}

//----- (00406E40) --------------------------------------------------------  // acclient.c:66247
SmartBuffer *__thiscall SmartBuffer::MakeWindow(SmartBuffer *this, SmartBuffer *result, unsigned int i_start, unsigned int i_size)
{
  SmartBuffer *v4; // edi@1
  void *v5; // eax@2
  GrowBuffer *v6; // esi@6

  v4 = this;
  if ( !this->m_masterBuffer )
  {
    v5 = operator new(0x14u);
    if ( v5 )
    {
      *((_DWORD *)v5 + 1) = 1;
      *(_DWORD *)v5 = &GrowBuffer::vftable;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      *((_BYTE *)v5 + 16) = 1;
      *((_BYTE *)v5 + 17) = 1;
      *((_BYTE *)v5 + 18) = 0;
    }
    else
    {
      v5 = 0;
    }
    v4->m_masterBuffer = (GrowBuffer *)v5;
  }
  v6 = v4->m_masterBuffer;
  if ( v6 )
    InterlockedIncrement((volatile LONG *)&v6->m_cRef);
  result->m_startOffset = i_start + v4->m_startOffset;
  result->m_size = i_size;
  result->m_masterBuffer = v6;
  if ( v6 )
  {
    InterlockedIncrement((volatile LONG *)&v6->m_cRef);
    if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 1u);
  }
  return result;
}
// 7942F8: using guessed type int (__thiscall *GrowBuffer::vftable)(void *, char);

//----- (00406EE0) --------------------------------------------------------  // acclient.c:66290
void __thiscall SmartBuffer::CreateNewMasterBuffer(SmartBuffer *this)
{
  SmartBuffer *v1; // esi@1
  GrowBuffer *v2; // edi@1
  void *v3; // eax@6

  v1 = this;
  v2 = this->m_masterBuffer;
  if ( v2 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
      v2->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, 1u);
    v1->m_masterBuffer = 0;
  }
  v1->m_startOffset = 0;
  v1->m_size = 0;
  v3 = operator new(0x14u);
  if ( v3 )
  {
    *((_DWORD *)v3 + 2) = 0;
    *((_DWORD *)v3 + 3) = 0;
    *((_BYTE *)v3 + 18) = 0;
    *((_DWORD *)v3 + 1) = 1;
    *(_DWORD *)v3 = &GrowBuffer::vftable;
    *((_BYTE *)v3 + 16) = 1;
    *((_BYTE *)v3 + 17) = 1;
    v1->m_masterBuffer = (GrowBuffer *)v3;
  }
  else
  {
    v1->m_masterBuffer = 0;
  }
}
// 7942F8: using guessed type int (__thiscall *GrowBuffer::vftable)(void *, char);

//----- (00406F50) --------------------------------------------------------  // acclient.c:66326
void __thiscall GrowBuffer::GrowExact(GrowBuffer *this, unsigned int i_exactSize)
{
  GrowBuffer *v2; // esi@1
  void *v3; // eax@2
  int v4; // ebx@5
  void *v5; // ebp@6
  unsigned __int32 v6; // eax@10
  struct GrowBuffer::FreeGrowBuffer **v7; // ecx@14
  struct GrowBuffer::FreeGrowBuffer *v8; // eax@14
  unsigned __int32 v9; // edx@14
  unsigned int v10; // ecx@17
  GrowBuffer *v11; // [sp+0h] [bp-4h]@1

  v2 = this;
  v11 = this;
  if ( !(GrowBuffer::GrowExact::_3::local_static_guard & 1) )
  {
    GrowBuffer::GrowExact::_3::local_static_guard |= 1u;
    v3 = operator new(0xCu);
    if ( v3 )
    {
      *(_DWORD *)v3 = 0;
      *((_DWORD *)v3 + 1) = 0;
      *((_DWORD *)v3 + 2) = 0;
      GrowBuffer::m_pFreeListLock = (CSpinLock<1048576,0> *)v3;
      atexit(GrowBuffer::GrowExact::_3::s_FreeListHelper);
    }
    else
    {
      GrowBuffer::m_pFreeListLock = 0;
      atexit(GrowBuffer::GrowExact::_3::s_FreeListHelper);
    }
  }
  v4 = i_exactSize;
  if ( v2->m_size < i_exactSize )
  {
    v5 = 0;
    if ( !v2->m_bAllocateFromFreelist || !GrowBuffer::m_nFreeListEntries || !GrowBuffer::m_pFreeListLock )
      goto LABEL_22;
    CSpinLock<1048576,0>::Enter(GrowBuffer::m_pFreeListLock);
    if ( GrowBuffer::m_nFreeListEntries )
    {
      v6 = GrowBuffer::m_nFreeListEntries;
      if ( GrowBuffer::m_nFreeListEntries > 0 )
      {
        while ( 1 )
        {
          --v6;
          if ( dword_83675C[2 * v6] >= i_exactSize )
            break;
          if ( v6 <= 0 )
            goto LABEL_15;
        }
        v4 = dword_83675C[2 * v6];
        v5 = (&GrowBuffer::m_FreeList)[v6];
        v7 = &(&GrowBuffer::m_FreeList)[v6];
        v8 = (struct GrowBuffer::FreeGrowBuffer *)*(&PStringBase<unsigned short>::whitespace_string
                                                  + 2 * GrowBuffer::m_nFreeListEntries--);
        v9 = GrowBuffer::m_nFreeListEntries;
        *v7 = v8;
        v7[1] = (struct GrowBuffer::FreeGrowBuffer *)dword_83675C[2 * v9];
      }
    }
LABEL_15:
    InterlockedExchange(&GrowBuffer::m_pFreeListLock->m_Lock, 0);
    if ( !v5 )
LABEL_22:
      v5 = operator new[](v4);
    v10 = v2->m_size;
    if ( v10 > 0 )
    {
      qmemcpy(v5, v2->m_data, v10);
      GrowBuffer::FreeBuffer(v11);
      v2 = v11;
    }
    v2->m_data = (char *)v5;
    v2->m_size = v4;
  }
}
// 836758: using guessed type struct GrowBuffer::FreeGrowBuffer *GrowBuffer::m_FreeList;
// 83675C: using guessed type int dword_83675C[];
// 83679C: using guessed type unsigned __int32 GrowBuffer::m_nFreeListEntries;
// 8367A0: using guessed type int GrowBuffer::GrowExact::_3::local_static_guard;

//----- (00407090) --------------------------------------------------------  // acclient.c:66411
SmartBuffer *__thiscall SmartBuffer::MakeWindow(SmartBuffer *this, SmartBuffer *result, unsigned int i_start)
{
  SmartBuffer::MakeWindow(this, result, i_start, this->m_size - i_start);
  return result;
}

//----- (004070B0) --------------------------------------------------------  // acclient.c:66418
void __thiscall SmartBuffer::Borrow(SmartBuffer *this, char *i_addr, unsigned int i_size)
{
  SmartBuffer *v3; // edi@1
  GrowBuffer *v4; // esi@1

  v3 = this;
  SmartBuffer::CreateNewMasterBuffer(this);
  v4 = v3->m_masterBuffer;
  GrowBuffer::FreeBuffer(v3->m_masterBuffer);
  v4->m_data = i_addr;
  v4->m_size = i_size;
  v4->m_ownsBuffer = 0;
  v4->m_bCanResize = 0;
  v3->m_size = i_size;
}

//----- (004070F0) --------------------------------------------------------  // acclient.c:66435
SmartBuffer *__thiscall SmartBuffer::Clone(SmartBuffer *this, SmartBuffer *result)
{
  SmartBuffer *v2; // ebx@1
  void *v3; // edi@1
  unsigned int v4; // eax@1
  void *v5; // ebp@1
  void *v6; // eax@2
  GrowBuffer *v7; // eax@5
  const void *v8; // esi@6

  v2 = this;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  if ( this->m_masterBuffer )
  {
    v6 = operator new(0x14u);
    if ( v6 )
    {
      *((_DWORD *)v6 + 1) = 1;
      *(_DWORD *)v6 = &GrowBuffer::vftable;
      *((_DWORD *)v6 + 2) = 0;
      *((_DWORD *)v6 + 3) = 0;
      *((_BYTE *)v6 + 16) = 1;
      *((_BYTE *)v6 + 17) = 1;
      *((_BYTE *)v6 + 18) = 0;
      v5 = v6;
    }
    else
    {
      v5 = 0;
    }
    GrowBuffer::GrowExact((GrowBuffer *)v5, v2->m_size);
    v7 = v2->m_masterBuffer;
    if ( v7 )
      v8 = &v7->m_data[v2->m_startOffset];
    else
      v8 = 0;
    if ( v5 )
      v3 = (void *)*((_DWORD *)v5 + 2);
    qmemcpy(v3, v8, v2->m_size);
    v4 = v2->m_size;
  }
  result->m_startOffset = 0;
  result->m_size = v4;
  result->m_masterBuffer = (GrowBuffer *)v5;
  if ( v5 )
  {
    InterlockedIncrement((volatile LONG *)v5 + 1);
    if ( !InterlockedDecrement((volatile LONG *)v5 + 1) )
      (**(void (__thiscall ***)(void *, signed int))v5)(v5, 1);
  }
  return result;
}
// 7942F8: using guessed type int (__thiscall *GrowBuffer::vftable)(void *, char);

//----- (004071B0) --------------------------------------------------------  // acclient.c:66492
void __thiscall SmartBuffer::ReconfigureAllocation(SmartBuffer *this, unsigned int i_sizeNeeded, unsigned int i_dwBehaviorBits)
{
  char v3; // al@1
  SmartBuffer *v4; // esi@1
  void *v5; // eax@5
  GrowBuffer *v6; // edi@10
  unsigned int v7; // ST00_4@10

  v3 = i_dwBehaviorBits;
  v4 = this;
  if ( i_dwBehaviorBits & 8 )
    this->m_masterBuffer->m_bAllocateFromFreelist = 1;
  if ( this->m_size < i_sizeNeeded )
  {
    if ( !this->m_masterBuffer )
    {
      v5 = operator new(0x14u);
      if ( v5 )
      {
        *((_DWORD *)v5 + 1) = 1;
        *(_DWORD *)v5 = &GrowBuffer::vftable;
        *((_DWORD *)v5 + 2) = 0;
        *((_DWORD *)v5 + 3) = 0;
        *((_BYTE *)v5 + 16) = 1;
        *((_BYTE *)v5 + 17) = 1;
        *((_BYTE *)v5 + 18) = 0;
      }
      else
      {
        v5 = 0;
      }
      v4->m_masterBuffer = (GrowBuffer *)v5;
      v3 = i_dwBehaviorBits;
    }
    if ( v3 & 1 )
    {
      v6 = v4->m_masterBuffer;
      v7 = GrowBuffer::GetGoodSize(i_sizeNeeded + v4->m_startOffset);
      GrowBuffer::GrowExact(v6, v7);
    }
    else
    {
      GrowBuffer::GrowExact(v4->m_masterBuffer, i_sizeNeeded + v4->m_startOffset);
    }
    v3 = i_dwBehaviorBits;
    v4->m_size = i_sizeNeeded;
  }
  if ( v3 & 4 )
    v4->m_masterBuffer->m_bCanResize = 0;
  if ( v3 & 2 )
    v4->m_size = i_sizeNeeded;
}
// 7942F8: using guessed type int (__thiscall *GrowBuffer::vftable)(void *, char);

//----- (00725C40) --------------------------------------------------------  // acclient.c:823579
void __cdecl GrowBuffer::GrowExact::_3::s_FreeListHelper()
{
  GrowBuffer::GrowExact::_2::FreeListLockAllocator::~FreeListLockAllocator();
}

