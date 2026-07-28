/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AsyncState
   Object     : CORE\statemachine\AsyncState.obj
   Functions  : 56
   Addresses  : 0065DB50 - 0065F660 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0065DB50) --------------------------------------------------------  // acclient.c:627515
int __thiscall CAsyncStateHandler::EndStateOK(CAsyncStateHandler *this, AsyncContext hContext, int NextStateNumber)
{
  return ((int (__stdcall *)(_DWORD, _DWORD))this->m_pMachine->vfptr->OnHandlerDoneOK)(hContext.m_id, NextStateNumber);
}

//----- (0065DB60) --------------------------------------------------------  // acclient.c:627521
void __thiscall CAsyncStateHandler::EndStateFailed(CAsyncStateHandler *this, AsyncContext hContext)
{
  ((void (__stdcall *)(_DWORD))this->m_pMachine->vfptr->OnHandlerFailed)(hContext.m_id);
}

//----- (0065DB70) --------------------------------------------------------  // acclient.c:627527
void __thiscall CAsyncStateMachine::SetTimerInstance(CAsyncStateMachine *this, PreciseTimerInstance *i_pTimer)
{
  CAsyncStateMachine *v2; // edi@1
  PreciseTimerInstance *v3; // esi@1

  v2 = this;
  v3 = this->m_pTimer;
  if ( v3 != i_pTimer )
  {
    if ( v3 )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
      {
        if ( v3 )
          v3->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 1u);
      }
      v2->m_pTimer = 0;
    }
    v2->m_pTimer = i_pTimer;
    InterlockedIncrement((volatile LONG *)&i_pTimer->m_cRef);
  }
}

//----- (0065DBD0) --------------------------------------------------------  // acclient.c:627551
IntrusiveHashTable<int,CAsyncStateHandler *,1> *__thiscall IntrusiveHashTable<int,CAsyncStateHandler *,1>::scalar_deleting_destructor(IntrusiveHashTable<int,CAsyncStateHandler *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<int,CAsyncStateHandler *,1> *v2; // esi@1
  CAsyncStateHandler **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<int,CAsyncStateHandler *,1>Vtbl *)IntrusiveHashTable<int,CAsyncStateHandler *,1>::vftable;
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
// 7FDA64: using guessed type int (__thiscall *IntrusiveHashTable<int,CAsyncStateHandler *,1>::vftable[4])(void *, char);

//----- (0065DC10) --------------------------------------------------------  // acclient.c:627572
IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *__thiscall IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::vector_deleting_destructor(IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *v2; // esi@1
  CAsyncStateMachine::CAsyncStateData **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>Vtbl *)IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::vftable;
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
// 7FDA68: using guessed type int (__thiscall *IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::vftable[3])(void *, char);

//----- (0065DC50) --------------------------------------------------------  // acclient.c:627593
IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *__thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::vector_deleting_destructor(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *v2; // esi@1
  HashTableData<PStringBase<char>,unsigned long> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>Vtbl *)IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::vftable;
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
// 7FDA6C: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::vftable[2])(void *, char);

//----- (0065DC90) --------------------------------------------------------  // acclient.c:627614
void __thiscall CAsyncStateHandler::CAsyncStateHandler(CAsyncStateHandler *this, int StateNumber)
{
  this->m_hashKey = StateNumber;
  this->m_hashNext = 0;
  this->dllist_next = 0;
  this->dllist_prev = 0;
  this->vfptr = (CAsyncStateHandlerVtbl *)&CAsyncStateHandler::vftable;
  this->m_pMachine = 0;
}
// 7FDA70: using guessed type int (__thiscall *CAsyncStateHandler::vftable)(void *, char);

//----- (0065DCB0) --------------------------------------------------------  // acclient.c:627626
void __thiscall CAsyncStateMachine::CAsyncStateData::CAsyncStateData(CAsyncStateMachine::CAsyncStateData *this, AsyncContext i_hKey)
{
  this->m_hashKey.m_id = i_hKey.m_id;
  this->m_hashNext = 0;
  this->dllist_next = 0;
  this->dllist_prev = 0;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)CAsyncStateMachine::CAsyncStateData::vftable;
  this->Data.m_data = 0;
  this->Data.m_sizeAndDeallocate = 0;
  this->Data.m_num = 0;
  this->tContextBegan = -1.0;
  this->tCurStateBegan = -1.0;
  this->eStatus = 0;
  this->bAdvancing = 0;
  this->iDelayedNextStateNumber = -2147483647;
  this->pCurrentState = 0;
  this->iMaxStateNumber = -2147483647;
}
// 7FDA90: using guessed type int (__thiscall *CAsyncStateMachine::CAsyncStateData::vftable[3])(void *, char);

//----- (0065DD10) --------------------------------------------------------  // acclient.c:627648
void __stdcall CAsyncStateMachine::AllocateStateData(AsyncContext hContext)
{
  CAsyncStateMachine::CAsyncStateData *v2; // eax@1

  v2 = (CAsyncStateMachine::CAsyncStateData *)operator new(0x48u);
  if ( v2 )
    CAsyncStateMachine::CAsyncStateData::CAsyncStateData(v2, hContext);
}

//----- (0065DD30) --------------------------------------------------------  // acclient.c:627658
IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *__thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::find_internal(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *this, IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *result, PStringBase<char> *_key)
{
  PSRefBufferCharData<char> *v3; // esi@1
  unsigned int v4; // eax@1
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *v5; // edi@1
  unsigned int v6; // ebx@1
  int v7; // edx@3
  HashTableData<PStringBase<char>,unsigned long> **v8; // eax@3
  HashTableData<PStringBase<char>,unsigned long> *v9; // esi@3
  HashTableData<PStringBase<char>,unsigned long> **i; // ebx@3
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *v11; // eax@6

  v3 = _key->m_charbuffer;
  v4 = *(_DWORD *)&_key->m_charbuffer[-1].m_data[8];
  v5 = this;
  v6 = this->m_numBuckets;
  if ( v4 == -1 )
  {
    v4 = compute_str_hash<char>(_key->m_charbuffer->m_data);
    *(_DWORD *)&v3[-1].m_data[8] = v4;
  }
  v7 = v4 % v6;
  v8 = v5->m_buckets;
  v9 = v8[v7];
  for ( i = &v8[v7]; v9; v9 = v9->m_hashNext )
  {
    if ( PStringBase<char>::operator==(&v9->m_hashKey, _key) )
      break;
  }
  v11 = result;
  result->m_currHashTable = v5;
  result->m_currElement = v9;
  result->m_currBucket = i;
  return v11;
}

//----- (0065DD90) --------------------------------------------------------  // acclient.c:627695
bool __thiscall IntrusiveHashTable<int,CAsyncStateHandler *,1>::contains(IntrusiveHashTable<int,CAsyncStateHandler *,1> *this, const int *key)
{
  CAsyncStateHandler *v2; // edx@1
  bool v3; // zf@1

  v2 = this->m_buckets[*key % this->m_numBuckets];
  v3 = v2 == 0;
  if ( v2 )
  {
    do
    {
      if ( v2->m_hashKey == *key )
        break;
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    v3 = v2 == 0;
  }
  return !v3;
}

//----- (0065DDC0) --------------------------------------------------------  // acclient.c:627717
CAsyncStateMachine::CAsyncStateData *__thiscall CAsyncStateMachine::CAsyncStateData::vector_deleting_destructor(CAsyncStateMachine::CAsyncStateData *this, unsigned int a2)
{
  CAsyncStateMachine::CAsyncStateData *v2; // esi@1

  v2 = this;
  SmartArray<char *,1>::~SmartArray<char *,1>(&this->Data);
  v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);

//----- (0065DDF0) --------------------------------------------------------  // acclient.c:627731
int __thiscall CAsyncStateMachine::BeginContext(CAsyncStateMachine *this, AsyncContext hContext, int StartState)
{
  CAsyncStateMachine *v3; // edi@1
  CAsyncStateMachine::CAsyncStateData *v4; // edx@1
  int result; // eax@4
  long double v6; // st7@7
  DLListData *v7; // eax@8
  int v8; // esi@9
  int v9; // esi@10
  int v10; // eax@11

  v3 = this;
  v4 = this->m_ContextHash.m_hash.m_buckets[hContext.m_id % this->m_ContextHash.m_hash.m_numBuckets];
  if ( !v4 )
    goto LABEL_16;
  while ( v4->m_hashKey.m_id != hContext.m_id )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      return 5;
  }
  if ( v4 )
  {
    v6 = this->m_pTimer->m_tElapsedTime;
    v4->eStatus = 1;
    v4->tContextBegan = v6;
    ((void (__stdcall *)(unsigned int))this->vfptr->OnContextBegun)(hContext.m_id);
    if ( v3->m_States.m_hash.m_numElements )
    {
      v7 = v3->m_States.m_list.head_;
      if ( v7 )
      {
        v8 = (int)&v7[-2].dllist_prev;
        if ( v7 != (DLListData *)12 )
        {
          do
          {
            (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v8 + 4))(v8, hContext.m_id);
            v9 = *(_DWORD *)(v8 + 12);
            if ( !v9 )
              break;
            v10 = v9 - 8;
            if ( v9 == 8 )
              break;
            v8 = v9 - 12;
          }
          while ( v10 != 4 );
        }
      }
    }
    result = ((int (__thiscall *)(CAsyncStateMachine *, unsigned int, int))v3->vfptr->OnHandlerDoneOK)(
               v3,
               hContext.m_id,
               StartState);
  }
  else
  {
LABEL_16:
    result = 5;
  }
  return result;
}

//----- (0065DEA0) --------------------------------------------------------  // acclient.c:627795
int __thiscall CAsyncStateMachine::GetContextData(CAsyncStateMachine *this, AsyncContext hContext, unsigned int dwDataIndex)
{
  CAsyncStateMachine::CAsyncStateData *v3; // edx@1
  int result; // eax@4

  v3 = this->m_ContextHash.m_hash.m_buckets[hContext.m_id % this->m_ContextHash.m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.m_id != hContext.m_id )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
    result = v3->Data.m_data[dwDataIndex];
  else
LABEL_4:
    result = 0;
  return result;
}

//----- (0065DEF0) --------------------------------------------------------  // acclient.c:627818
char __thiscall CAsyncStateMachine::SetContextData(CAsyncStateMachine *this, AsyncContext hContext, unsigned int dwDataIndex, int dwData)
{
  CAsyncStateMachine::CAsyncStateData *v4; // edx@1
  char result; // al@4

  v4 = this->m_ContextHash.m_hash.m_buckets[hContext.m_id % this->m_ContextHash.m_hash.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.m_id != hContext.m_id )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    v4->Data.m_data[dwDataIndex] = dwData;
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (0065DF40) --------------------------------------------------------  // acclient.c:627846
signed int __thiscall CAsyncStateMachine::Advance(CAsyncStateMachine *this, AsyncContext hContext, int NextStateNumber)
{
  CAsyncStateMachine *v3; // ebp@1
  CAsyncStateMachine::CAsyncStateData *v4; // esi@1
  int v6; // edi@7
  CAsyncStateHandler *v7; // ecx@8
  CAsyncStateHandler *v8; // eax@11
  DLListData *v9; // eax@12
  int v10; // eax@13
  int v11; // eax@14
  int v12; // ecx@16
  CAsyncStateHandler *v13; // edx@22
  DLListData *v14; // eax@28
  int i; // edx@33
  int v16; // eax@38
  int v17; // eax@39
  AsyncStateMachineStatus eRet; // [sp+Ch] [bp-4h]@1

  v3 = this;
  eRet = 5;
  v4 = this->m_ContextHash.m_hash.m_buckets[hContext.m_id % this->m_ContextHash.m_hash.m_numBuckets];
  if ( !v4 )
    return eRet;
  do
  {
    if ( v4->m_hashKey.m_id == hContext.m_id )
      break;
    v4 = v4->m_hashNext;
  }
  while ( v4 );
  if ( !v4 )
    return eRet;
  if ( v4->bAdvancing )
  {
    v4->iDelayedNextStateNumber = NextStateNumber;
    return 1;
  }
  v4->bAdvancing = 1;
  InterlockedIncrement((volatile LONG *)&v4->m_cRef);
  v6 = NextStateNumber;
  while ( 1 )
  {
    v7 = v4->pCurrentState;
    if ( v7 )
    {
      ((void (__stdcall *)(unsigned int, signed int))v7->vfptr->OnStateEnded)(hContext.m_id, 1);
      if ( v4->eStatus != 1 )
        break;
    }
    v4->iDelayedNextStateNumber = -2147483647;
    eRet = 1;
    if ( v6 == 2147483646 )
    {
      v8 = v4->pCurrentState;
      if ( !v8 )
        goto LABEL_31;
      v9 = v8->dllist_next;
      if ( !v9 || (v10 = (int)&v9[-1]) == 0 )
      {
LABEL_41:
        v4->pCurrentState = 0;
        eRet = 2;
        goto LABEL_42;
      }
      v11 = v10 - 4;
    }
    else
    {
      v13 = v3->m_States.m_hash.m_buckets[v6 % v3->m_States.m_hash.m_numBuckets];
      if ( !v13 )
        goto LABEL_25;
      while ( v13->m_hashKey != v6 )
      {
        v13 = v13->m_hashNext;
        if ( !v13 )
          goto LABEL_25;
      }
      if ( v13 )
      {
        for ( i = (int)v3->m_States.m_hash.m_buckets[v6 % v3->m_States.m_hash.m_numBuckets]; i; i = *(_DWORD *)(i + 8) )
        {
          if ( *(_DWORD *)(i + 4) == v6 )
            break;
        }
        v11 = i;
      }
      else
      {
LABEL_25:
        v11 = (int)v4->pCurrentState;
        if ( !v11 || *(_DWORD *)(v11 + 4) >= v6 )
        {
          if ( !v3->m_States.m_hash.m_numElements || (v14 = v3->m_States.m_list.head_) == 0 )
          {
LABEL_31:
            eRet = 5;
            goto LABEL_19;
          }
          v11 = (int)&v14[-2].dllist_prev;
        }
        if ( !v11 )
          goto LABEL_31;
        while ( *(_DWORD *)(v11 + 4) < v6 )
        {
          v16 = *(_DWORD *)(v11 + 12);
          if ( v16 )
          {
            v17 = v16 - 8;
            if ( v17 )
            {
              v11 = v17 - 4;
              if ( v11 )
                continue;
            }
          }
          goto LABEL_41;
        }
      }
    }
    if ( !v11 )
      goto LABEL_41;
    v4->pCurrentState = (CAsyncStateHandler *)v11;
    v12 = *(_DWORD *)(v11 + 4);
    if ( v12 > v4->iMaxStateNumber )
      v4->iMaxStateNumber = v12;
    v4->tCurStateBegan = v3->m_pTimer->m_tElapsedTime;
    (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v11 + 8))(v11, hContext.m_id);
LABEL_19:
    v6 = v4->iDelayedNextStateNumber;
    if ( v6 == -2147483647 || v4->eStatus != 1 )
      goto LABEL_42;
  }
  eRet = v4->eStatus;
LABEL_42:
  v4->bAdvancing = 0;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 1u);
  return eRet;
}

//----- (0065E120) --------------------------------------------------------  // acclient.c:627987
char __thiscall IntrusiveHashTable<int,CAsyncStateHandler *,1>::grow(IntrusiveHashTable<int,CAsyncStateHandler *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<int,CAsyncStateHandler *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+Ch] [bp-4h]@1

  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(
                         g_bucketSizesBegin,
                         g_bucketSizesEnd,
                         &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<int,CAsyncStateHandler *,1>::resize_internal(v2, *v3);
}

//----- (0065E180) --------------------------------------------------------  // acclient.c:628007
char __thiscall IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::grow(IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+Ch] [bp-4h]@1

  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(
                         g_bucketSizesBegin,
                         g_bucketSizesEnd,
                         &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::resize_internal(v2, *v3);
}

//----- (0065E1E0) --------------------------------------------------------  // acclient.c:628027
int __thiscall CAsyncStateHandler::GetContextData(CAsyncStateHandler *this, AsyncContext hContext, unsigned int dwDataIndex)
{
  return CAsyncStateMachine::GetContextData(this->m_pMachine, hContext, dwDataIndex);
}

//----- (0065E1F0) --------------------------------------------------------  // acclient.c:628033
char __thiscall CAsyncStateHandler::SetContextData(CAsyncStateHandler *this, AsyncContext hContext, unsigned int dwDataIndex, int dwData)
{
  return CAsyncStateMachine::SetContextData(this->m_pMachine, hContext, dwDataIndex, dwData);
}

//----- (0065E200) --------------------------------------------------------  // acclient.c:628039
AsyncContext *__thiscall CAsyncStateMachine::AllocateAndBeginContext(CAsyncStateMachine *this, AsyncContext *result)
{
  CAsyncStateMachine *v2; // esi@1
  AsyncContext *v3; // eax@2
  AsyncContext hContext; // [sp+4h] [bp-4h]@1

  hContext.m_id = (unsigned int)this;
  v2 = this;
  (*(void (__stdcall **)(AsyncContext *))&this->vfptr->gap4[0])(&hContext);
  if ( hContext.m_id == INVALID_ASYNCCONTEXT_34.m_id )
  {
    v3 = result;
    result->m_id = hContext.m_id;
  }
  else
  {
    CAsyncStateMachine::BeginContext(v2, hContext, -2147483392);
    v3 = result;
    result->m_id = hContext.m_id;
  }
  return v3;
}

//----- (0065E250) --------------------------------------------------------  // acclient.c:628063
void __thiscall IntrusiveHashTable<int,CAsyncStateHandler *,1>::IntrusiveHashTable<int,CAsyncStateHandler *,1>(IntrusiveHashTable<int,CAsyncStateHandler *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<int,CAsyncStateHandler *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6
  unsigned int __val; // [sp+0h] [bp-4h]@1

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<int,CAsyncStateHandler *,1>Vtbl *)IntrusiveHashTable<int,CAsyncStateHandler *,1>::vftable;
  v3 = g_bucketSizesEnd;
  __val = _numBuckets;
  v4 = _STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(
         g_bucketSizesBegin,
         g_bucketSizesEnd,
         &__val);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (CAsyncStateHandler **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (CAsyncStateHandler **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FDA64: using guessed type int (__thiscall *IntrusiveHashTable<int,CAsyncStateHandler *,1>::vftable[4])(void *, char);

//----- (0065E2F0) --------------------------------------------------------  // acclient.c:628101
void __thiscall IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>(IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6
  unsigned int __val; // [sp+0h] [bp-4h]@1

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>Vtbl *)IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::vftable;
  v3 = g_bucketSizesEnd;
  __val = _numBuckets;
  v4 = _STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(
         g_bucketSizesBegin,
         g_bucketSizesEnd,
         &__val);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (CAsyncStateMachine::CAsyncStateData **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (CAsyncStateMachine::CAsyncStateData **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FDA68: using guessed type int (__thiscall *IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::vftable[3])(void *, char);

//----- (0065E390) --------------------------------------------------------  // acclient.c:628139
void __thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6
  unsigned int __val; // [sp+0h] [bp-4h]@1

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>Vtbl *)IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  __val = _numBuckets;
  v4 = _STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(
         g_bucketSizesBegin,
         g_bucketSizesEnd,
         &__val);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<PStringBase<char>,unsigned long> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<PStringBase<char>,unsigned long> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FDA6C: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::vftable[2])(void *, char);

//----- (0065E430) --------------------------------------------------------  // acclient.c:628177
char __thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::grow(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+Ch] [bp-4h]@1

  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(
                         g_bucketSizesBegin,
                         g_bucketSizesEnd,
                         &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::resize_internal(
           v2,
           *v3);
}

//----- (0065E490) --------------------------------------------------------  // acclient.c:628199
void __thiscall IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::remove(IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *this, IntrusiveHashIterator<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> iter)
{
  CAsyncStateMachine::CAsyncStateData *v2; // eax@1
  CAsyncStateMachine::CAsyncStateData *v3; // edx@2

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

//----- (0065E4D0) --------------------------------------------------------  // acclient.c:628227
char __thiscall IntrusiveHashTable<int,CAsyncStateHandler *,1>::resize_internal(IntrusiveHashTable<int,CAsyncStateHandler *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<int,CAsyncStateHandler *,1> *v2; // esi@1
  char result; // al@2
  CAsyncStateHandler *v4; // ebp@3
  int v5; // ecx@4
  CAsyncStateHandler **v6; // eax@5
  int v7; // eax@6
  CAsyncStateHandler **v8; // ecx@7
  CAsyncStateHandler *v9; // edi@7
  _BYTE v10[12]; // ST00_12@9
  CAsyncStateHandler *v11; // edi@12
  CAsyncStateHandler *v12; // ebp@13
  int v13; // edx@15
  CAsyncStateHandler **v14; // eax@15
  int v15; // eax@15

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (CAsyncStateHandler **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (CAsyncStateHandler **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        *(_QWORD *)&v10[4] = __PAIR__((unsigned int)v9, (unsigned int)v8);
        *(_DWORD *)v10 = v2;
        IntrusiveHashTable<int,CAsyncStateHandler *,1>::remove(
          v2,
          *(IntrusiveHashIterator<int,CAsyncStateHandler *,1> *)v10);
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (CAsyncStateHandler **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<int,CAsyncStateHandler *,1>::init(
      (IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *)v2,
      _numBuckets);
    v11 = v4;
    if ( v4 )
    {
      do
      {
        v12 = v11->m_hashNext;
        if ( (signed int)(2 * v2->m_numBuckets) < (signed int)(v2->m_numElements + 1) )
          IntrusiveHashTable<int,CAsyncStateHandler *,1>::grow(v2);
        v13 = v11->m_hashKey % v2->m_numBuckets;
        v14 = v2->m_buckets;
        v11->m_hashNext = v14[v13];
        v14[v13] = v11;
        v15 = (int)&v14[v13];
        if ( (CAsyncStateHandler **)v15 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (CAsyncStateHandler **)v15;
        ++v2->m_numElements;
        v11 = v12;
      }
      while ( v12 );
    }
    result = 1;
  }
  return result;
}

//----- (0065E5C0) --------------------------------------------------------  // acclient.c:628323
char __thiscall IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::resize_internal(IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *v2; // esi@1
  char result; // al@2
  CAsyncStateMachine::CAsyncStateData *v4; // edi@3
  int v5; // ecx@4
  CAsyncStateMachine::CAsyncStateData **v6; // eax@5
  int v7; // eax@6
  CAsyncStateMachine::CAsyncStateData **v8; // ebp@7
  CAsyncStateMachine::CAsyncStateData *v9; // ecx@7
  CAsyncStateMachine::CAsyncStateData *v10; // eax@9
  CAsyncStateMachine::CAsyncStateData *v11; // edx@10
  CAsyncStateMachine::CAsyncStateData *v12; // ebp@18
  int v13; // edx@20
  CAsyncStateMachine::CAsyncStateData **v14; // eax@20
  int v15; // eax@20

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (CAsyncStateMachine::CAsyncStateData **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (CAsyncStateMachine::CAsyncStateData **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_26;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_26:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (CAsyncStateMachine::CAsyncStateData **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<int,CAsyncStateHandler *,1>::init(
      (IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *)v2,
      _numBuckets);
    if ( v4 )
    {
      do
      {
        v12 = v4->m_hashNext;
        if ( (signed int)(2 * v2->m_numBuckets) < (signed int)(v2->m_numElements + 1) )
          IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::grow(v2);
        v13 = v4->m_hashKey.m_id % v2->m_numBuckets;
        v14 = v2->m_buckets;
        v4->m_hashNext = v14[v13];
        v14[v13] = v4;
        v15 = (int)&v14[v13];
        if ( (CAsyncStateMachine::CAsyncStateData **)v15 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (CAsyncStateMachine::CAsyncStateData **)v15;
        ++v2->m_numElements;
        v4 = v12;
      }
      while ( v12 );
    }
    result = 1;
  }
  return result;
}

//----- (0065E770) --------------------------------------------------------  // acclient.c:628494
void __thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::add_internal(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *this, HashTableData<PStringBase<char>,unsigned long> *data)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *v2; // esi@1
  unsigned int v3; // ebp@3
  PSRefBufferCharData<char> *v4; // edi@3
  unsigned int v5; // eax@3
  int v6; // edx@5
  HashTableData<PStringBase<char>,unsigned long> **v7; // eax@5
  int v8; // eax@5

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::grow(this);
  v3 = v2->m_numBuckets;
  v4 = data->m_hashKey.m_charbuffer;
  v5 = *(_DWORD *)&data->m_hashKey.m_charbuffer[-1].m_data[8];
  if ( v5 == -1 )
  {
    v5 = compute_str_hash<char>(data->m_hashKey.m_charbuffer->m_data);
    *(_DWORD *)&v4[-1].m_data[8] = v5;
  }
  v6 = v5 % v3;
  v7 = v2->m_buckets;
  data->m_hashNext = v7[v6];
  v7[v6] = data;
  v8 = (int)&v7[v6];
  if ( (HashTableData<PStringBase<char>,unsigned long> **)v8 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = (HashTableData<PStringBase<char>,unsigned long> **)v8;
  ++v2->m_numElements;
}

//----- (0065E7D0) --------------------------------------------------------  // acclient.c:628526
char __thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::resize_internal(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *v2; // esi@1
  char result; // al@2
  unsigned int v4; // edi@3
  int v5; // ecx@4
  HashTableData<PStringBase<char>,unsigned long> **v6; // eax@5
  int v7; // eax@6
  HashTableData<PStringBase<char>,unsigned long> **v8; // ebp@7
  HashTableData<PStringBase<char>,unsigned long> *v9; // ecx@7
  HashTableData<PStringBase<char>,unsigned long> *v10; // eax@9
  HashTableData<PStringBase<char>,unsigned long> *v11; // edx@10
  const char *v12; // ebp@20
  unsigned int v13; // eax@20
  unsigned int v14; // ebx@20
  int v15; // edx@22
  HashTableData<PStringBase<char>,unsigned long> **v16; // eax@22
  int v17; // eax@22
  unsigned int _numBucketsa; // [sp+8h] [bp+4h]@18

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (HashTableData<PStringBase<char>,unsigned long> **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (HashTableData<PStringBase<char>,unsigned long> **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_28;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_28:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = (HashTableData<PStringBase<char>,unsigned long> *)v4;
        v4 = (unsigned int)v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashTableData<PStringBase<char>,unsigned long> **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<int,CAsyncStateHandler *,1>::init(
      (IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *)v2,
      _numBuckets);
    if ( v4 )
    {
      do
      {
        _numBucketsa = *(_DWORD *)(v4 + 4);
        if ( (signed int)(2 * v2->m_numBuckets) < (signed int)(v2->m_numElements + 1) )
          IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::grow(v2);
        v12 = *(const char **)v4;
        v13 = *(_DWORD *)(*(_DWORD *)v4 - 8);
        v14 = v2->m_numBuckets;
        if ( v13 == -1 )
        {
          v13 = compute_str_hash<char>(*(const char **)v4);
          *((_DWORD *)v12 - 2) = v13;
        }
        v15 = v13 % v14;
        v16 = v2->m_buckets;
        *(_DWORD *)(v4 + 4) = v16[v15];
        v16[v15] = (HashTableData<PStringBase<char>,unsigned long> *)v4;
        v17 = (int)&v16[v15];
        if ( (HashTableData<PStringBase<char>,unsigned long> **)v17 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (HashTableData<PStringBase<char>,unsigned long> **)v17;
        v4 = _numBucketsa;
        ++v2->m_numElements;
      }
      while ( _numBucketsa );
    }
    result = 1;
  }
  return result;
}

//----- (0065E8F0) --------------------------------------------------------  // acclient.c:628642
char __thiscall IntrusiveHashTable<int,CAsyncStateHandler *,1>::add(IntrusiveHashTable<int,CAsyncStateHandler *,1> *this, CAsyncStateHandler *data)
{
  IntrusiveHashTable<int,CAsyncStateHandler *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  CAsyncStateHandler *v4; // edx@1
  unsigned int v5; // edx@6
  CAsyncStateHandler **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != data->m_hashKey )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<int,CAsyncStateHandler *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (CAsyncStateHandler **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (CAsyncStateHandler **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (0065E970) --------------------------------------------------------  // acclient.c:628686
char __thiscall IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::add(IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *this, CAsyncStateMachine::CAsyncStateData *data)
{
  IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  CAsyncStateMachine::CAsyncStateData *v4; // edx@1
  unsigned int v5; // edx@6
  CAsyncStateMachine::CAsyncStateData **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey.m_id % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.m_id != data->m_hashKey.m_id )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::grow(this);
    v5 = data->m_hashKey.m_id % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (CAsyncStateMachine::CAsyncStateData **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (CAsyncStateMachine::CAsyncStateData **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (0065E9F0) --------------------------------------------------------  // acclient.c:628730
CAsyncStateMachine::CAsyncStateData *__thiscall IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::remove(IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *this, AsyncContext *key)
{
  unsigned int v2; // edx@1
  CAsyncStateMachine::CAsyncStateData **v3; // eax@1
  CAsyncStateMachine::CAsyncStateData *v4; // esi@1
  int v5; // edx@1
  CAsyncStateMachine::CAsyncStateData *result; // eax@4
  _BYTE v7[12]; // ST00_12@6

  v2 = key->m_id % this->m_numBuckets;
  v3 = this->m_buckets;
  v4 = v3[v2];
  v5 = (int)&v3[v2];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.m_id != key->m_id )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    *(_DWORD *)v7 = this;
    *(_QWORD *)&v7[4] = __PAIR__((unsigned int)v4, v5);
    IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::remove(
      this,
      *(IntrusiveHashIterator<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *)v7);
    result = v4;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (0065EA50) --------------------------------------------------------  // acclient.c:628769
char __thiscall IntrusiveHashList<int,CAsyncStateHandler *,1>::push_head(IntrusiveHashList<int,CAsyncStateHandler *,1> *this, CAsyncStateHandler *val)
{
  IntrusiveHashList<int,CAsyncStateHandler *,1> *v2; // esi@1
  CAsyncStateHandler *v3; // edx@1
  char *v4; // eax@5
  char result; // al@7
  DLListData *v6; // ecx@9

  v2 = this;
  v3 = v2->m_hash.m_buckets[val->m_hashKey % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != val->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    IntrusiveHashTable<int,CAsyncStateHandler *,1>::add(&this->m_hash, val);
    if ( val == (CAsyncStateHandler *)-4 )
      v4 = 0;
    else
      v4 = (char *)&val->dllist_next;
    *(_DWORD *)v4 = v2->m_list.head_;
    v6 = v2->m_list.head_;
    if ( v6 )
    {
      v6->dllist_prev = (DLListData *)v4;
      v2->m_list.head_ = (DLListData *)v4;
      *((_DWORD *)v4 + 1) = 0;
      result = 1;
    }
    else
    {
      v2->m_list.tail_ = (DLListData *)v4;
      v2->m_list.head_ = (DLListData *)v4;
      *((_DWORD *)v4 + 1) = 0;
      result = 1;
    }
  }
  return result;
}

//----- (0065EAE0) --------------------------------------------------------  // acclient.c:628820
char __thiscall IntrusiveHashList<int,CAsyncStateHandler *,1>::push_tail(IntrusiveHashList<int,CAsyncStateHandler *,1> *this, CAsyncStateHandler *val)
{
  IntrusiveHashList<int,CAsyncStateHandler *,1> *v2; // esi@1
  CAsyncStateHandler *v3; // edx@1
  DLListData *v4; // eax@5
  char result; // al@7

  v2 = this;
  v3 = v2->m_hash.m_buckets[val->m_hashKey % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != val->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    IntrusiveHashTable<int,CAsyncStateHandler *,1>::add(&this->m_hash, val);
    if ( val == (CAsyncStateHandler *)-4 )
      v4 = 0;
    else
      v4 = (DLListData *)&val->dllist_next;
    DLListBase::InsertAfter(&v2->m_list, v4, v2->m_list.tail_);
    result = 1;
  }
  return result;
}

//----- (0065EB40) --------------------------------------------------------  // acclient.c:628856
char __thiscall IntrusiveHashList<int,CAsyncStateHandler *,1>::insert_after(IntrusiveHashList<int,CAsyncStateHandler *,1> *this, CAsyncStateHandler *pExisting, CAsyncStateHandler *pNew)
{
  IntrusiveHashList<int,CAsyncStateHandler *,1> *v3; // esi@1
  char result; // al@2
  DLListData *v5; // ecx@6

  v3 = this;
  if ( pExisting )
  {
    if ( IntrusiveHashTable<int,CAsyncStateHandler *,1>::contains(&this->m_hash, &pNew->m_hashKey) )
    {
      result = 0;
    }
    else
    {
      IntrusiveHashTable<int,CAsyncStateHandler *,1>::add(&v3->m_hash, pNew);
      if ( pExisting == (CAsyncStateHandler *)-4 )
        v5 = 0;
      else
        v5 = (DLListData *)&pExisting->dllist_next;
      if ( pNew == (CAsyncStateHandler *)-4 )
      {
        DLListBase::InsertAfter(&v3->m_list, 0, v5);
        result = 1;
      }
      else
      {
        DLListBase::InsertAfter(&v3->m_list, (DLListData *)&pNew->dllist_next, v5);
        result = 1;
      }
    }
  }
  else
  {
    result = IntrusiveHashList<int,CAsyncStateHandler *,1>::push_head(this, pNew);
  }
  return result;
}

//----- (0065EBC0) --------------------------------------------------------  // acclient.c:628896
char __thiscall IntrusiveHashList<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::push_tail(IntrusiveHashList<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *this, CAsyncStateMachine::CAsyncStateData *val)
{
  IntrusiveHashList<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *v2; // esi@1
  CAsyncStateMachine::CAsyncStateData *v3; // edx@1
  DLListData *v4; // eax@5
  char result; // al@7

  v2 = this;
  v3 = v2->m_hash.m_buckets[val->m_hashKey.m_id % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.m_id != val->m_hashKey.m_id )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::add(&this->m_hash, val);
    if ( val == (CAsyncStateMachine::CAsyncStateData *)-8 )
      v4 = 0;
    else
      v4 = (DLListData *)&val->dllist_next;
    DLListBase::InsertAfter(&v2->m_list, v4, v2->m_list.tail_);
    result = 1;
  }
  return result;
}

//----- (0065EC20) --------------------------------------------------------  // acclient.c:628932
CAsyncStateMachine::CAsyncStateData *__thiscall IntrusiveHashList<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::remove(IntrusiveHashList<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *this, AsyncContext *val)
{
  IntrusiveHashList<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *v2; // edi@1
  CAsyncStateMachine::CAsyncStateData *v3; // esi@1
  DLListData *v5; // eax@7

  v2 = this;
  v3 = v2->m_hash.m_buckets[val->m_id % v2->m_hash.m_numBuckets];
  if ( v3 )
  {
    while ( v3->m_hashKey.m_id != val->m_id )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        return 0;
    }
    if ( v3 )
    {
      if ( v3 == (CAsyncStateMachine::CAsyncStateData *)-8 )
        v5 = 0;
      else
        v5 = (DLListData *)&v3->dllist_next;
      DLListBase::Remove(&this->m_list, v5);
      IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::remove(&v2->m_hash, val);
    }
  }
  return v3;
}

//----- (0065EC80) --------------------------------------------------------  // acclient.c:628962
void __thiscall IntrusiveHashTable<int,CAsyncStateHandler *,1>::remove(IntrusiveHashTable<int,CAsyncStateHandler *,1> *this, IntrusiveHashIterator<int,CAsyncStateHandler *,1> iter)
{
  CAsyncStateHandler *v2; // eax@1
  CAsyncStateHandler *v3; // edx@2

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

//----- (0065ECC0) --------------------------------------------------------  // acclient.c:628990
char __thiscall CAsyncStateMachine::AddStateHandler(CAsyncStateMachine *this, CAsyncStateHandler *pStateHandler)
{
  char v2; // bl@1
  char *v3; // ecx@1
  int v4; // eax@2
  int v5; // edi@5
  int v6; // eax@6
  unsigned int i; // esi@9
  int v8; // eax@12
  int v9; // eax@14
  int v10; // eax@15
  int v11; // edx@21
  int v13; // eax@30
  int v14; // eax@31
  int v15; // eax@32
  CAsyncStateHandlerVtbl *v16; // edx@40
  CAsyncStateMachine *v17; // [sp+10h] [bp-14h]@1
  int head; // [sp+14h] [bp-10h]@1

  v17 = this;
  v2 = 0;
  v3 = (char *)&this->m_States;
  head = 0;
  if ( *((_DWORD *)v3 + 27) )
  {
    v4 = *((_DWORD *)v3 + 28);
    if ( v4 )
      head = v4 - 12;
    else
      head = 0;
  }
  v5 = 0;
  if ( *((_DWORD *)v3 + 27) > 0u )
  {
    v6 = *((_DWORD *)v3 + 29);
    if ( v6 )
      v5 = v6 - 12;
    else
      v5 = 0;
  }
  i = pStateHandler->m_hashKey;
  if ( (signed int)i < -2147483392 )
    return 0;
  if ( (signed int)i > 2147483391 )
  {
    if ( i == 2147483645 )
    {
      v8 = v5;
      for ( i = 2147483391; v8; --i )
      {
        if ( *(_DWORD *)(v8 + 4) != i )
          break;
        v9 = *(_DWORD *)(v8 + 16);
        if ( v9 && (v10 = v9 - 8) != 0 )
          v8 = v10 - 4;
        else
          v8 = 0;
      }
      pStateHandler->m_hashKey = i;
    }
    if ( (signed int)i > 2147483391 )
      return 0;
  }
  v11 = *(_DWORD *)(*((_DWORD *)v3 + 24) + 4 * (i % *((_DWORD *)v3 + 26)));
  if ( v11 )
  {
    while ( *(_DWORD *)(v11 + 4) != i )
    {
      v11 = *(_DWORD *)(v11 + 8);
      if ( !v11 )
        goto LABEL_24;
    }
    if ( v11 )
      return 0;
  }
LABEL_24:
  if ( !v5 || *(_DWORD *)(v5 + 4) < (signed int)i )
  {
    IntrusiveHashList<int,CAsyncStateHandler *,1>::push_tail(
      (IntrusiveHashList<int,CAsyncStateHandler *,1> *)v3,
      pStateHandler);
    goto LABEL_40;
  }
  if ( *(_DWORD *)(head + 4) > (signed int)i )
  {
    IntrusiveHashList<int,CAsyncStateHandler *,1>::push_head(
      (IntrusiveHashList<int,CAsyncStateHandler *,1> *)v3,
      pStateHandler);
LABEL_40:
    v16 = pStateHandler->vfptr;
    pStateHandler->m_pMachine = v17;
    v2 = 1;
    v16->OnStateHandlerInit(pStateHandler);
    return v2;
  }
  v13 = v5;
  if ( head != v5 )
  {
    while ( 1 )
    {
      v14 = *(_DWORD *)(v13 + 16);
      if ( v14 && (v15 = v14 - 8) != 0 )
        v13 = v15 - 4;
      else
        v13 = 0;
      if ( *(_DWORD *)(v13 + 4) < (signed int)i )
        break;
      if ( head == v13 )
        return 0;
    }
    IntrusiveHashList<int,CAsyncStateHandler *,1>::insert_after(
      (IntrusiveHashList<int,CAsyncStateHandler *,1> *)v3,
      (CAsyncStateHandler *)v13,
      pStateHandler);
    goto LABEL_40;
  }
  return v2;
}

//----- (0065EE10) --------------------------------------------------------  // acclient.c:629110
AsyncContext *__thiscall CAsyncStateMachine::AllocateContext(CAsyncStateMachine *this, AsyncContext *result)
{
  CAsyncStateMachine *v2; // edi@1
  unsigned int v3; // ebp@3
  CAsyncStateMachineVtbl *v4; // edx@3
  unsigned int v5; // ST04_4@3
  CAsyncStateMachine::CAsyncStateData *v6; // eax@3
  CAsyncStateMachine::CAsyncStateData *v7; // esi@3
  AsyncContext *v8; // eax@4
  unsigned int v9; // edx@5
  unsigned int v10; // ebx@5
  int v11; // esi@5
  unsigned int v12; // eax@8
  unsigned int v13; // eax@11

  v2 = this;
  if ( !this->m_dwNextContextNumber )
    this->m_dwNextContextNumber = 1;
  v3 = this->m_dwNextContextNumber;
  v4 = this->vfptr;
  v5 = this->m_dwNextContextNumber;
  this->m_dwNextContextNumber = v3 + 1;
  v6 = (CAsyncStateMachine::CAsyncStateData *)((int (__stdcall *)(unsigned int))v4->AllocateStateData)(v5);
  v7 = v6;
  if ( !v6 )
  {
    v8 = result;
    result->m_id = INVALID_ASYNCCONTEXT_34.m_id;
    return v8;
  }
  IntrusiveHashList<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::push_tail(&v2->m_ContextHash, v6);
  v9 = v7->Data.m_sizeAndDeallocate;
  v10 = v2->m_DataNames.m_intrusiveTable.m_numElements;
  v11 = (int)&v7->Data;
  if ( (v9 & 0x7FFFFFFF) >= v10 )
  {
    v12 = v2->m_DataNames.m_intrusiveTable.m_numElements;
    if ( v10 < *(_DWORD *)(v11 + 8) )
    {
      do
        *(_DWORD *)(*(_DWORD *)v11 + 4 * v12++) = 0;
      while ( v12 < *(_DWORD *)(v11 + 8) );
    }
    goto LABEL_10;
  }
  if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v11, v2->m_DataNames.m_intrusiveTable.m_numElements) )
LABEL_10:
    *(_DWORD *)(v11 + 8) = v10;
  v13 = 0;
  if ( v2->m_DataNames.m_intrusiveTable.m_numElements )
  {
    do
      *(_DWORD *)(*(_DWORD *)v11 + 4 * v13++) = 0;
    while ( v13 < v2->m_DataNames.m_intrusiveTable.m_numElements );
  }
  v8 = result;
  result->m_id = v3;
  return v8;
}

//----- (0065EED0) --------------------------------------------------------  // acclient.c:629171
void __userpurge CAsyncStateMachine::EndAndReleaseContext(CAsyncStateMachine *this@<ecx>, int a2@<edi>, AsyncContext hContext, AsyncStateMachineStatus i_eFinalStatus)
{
  unsigned int v4; // ebx@1
  CAsyncStateMachine::CAsyncStateData *v5; // ebp@1
  signed int v6; // eax@6
  AsyncStateMachineStatus v7; // edi@7
  CAsyncStateHandler *v8; // ecx@8
  int v9; // esi@10
  bool v10; // zf@10
  DLListData *v11; // eax@11
  int v12; // esi@15
  int v13; // eax@16
  int v14; // esi@18
  int v15; // eax@19
  int v16; // esi@23
  int v17; // eax@24
  int v18; // [sp+8h] [bp-1Ch]@7
  CAsyncStateMachine *iter; // [sp+18h] [bp-Ch]@1
  int iter_4; // [sp+1Ch] [bp-8h]@0
  IntrusiveHashList<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1> *v21; // [sp+20h] [bp-4h]@1

  v4 = hContext.m_id;
  iter = this;
  v21 = &this->m_ContextHash;
  v5 = this->m_ContextHash.m_hash.m_buckets[hContext.m_id % this->m_ContextHash.m_hash.m_numBuckets];
  if ( v5 )
  {
    while ( v5->m_hashKey.m_id != hContext.m_id )
    {
      v5 = v5->m_hashNext;
      if ( !v5 )
        return;
    }
    if ( v5 )
    {
      v6 = v5->eStatus;
      if ( v6 <= 1 )
      {
        v18 = a2;
        v7 = i_eFinalStatus;
        v5->eStatus = i_eFinalStatus;
        if ( v6 == 1 )
        {
          v8 = v5->pCurrentState;
          if ( v8 )
            ((void (__stdcall *)(unsigned int, AsyncStateMachineStatus))v8->vfptr->OnStateEnded)(v4, v7);
        }
        v9 = 0;
        v10 = iter->m_States.m_hash.m_numElements == 0;
        i_eFinalStatus = (AsyncStateMachineStatus)&iter->m_States;
        if ( !v10 )
        {
          v11 = iter->m_States.m_list.head_;
          if ( v11 )
            v9 = (int)&v11[-2].dllist_prev;
          else
            v9 = 0;
        }
        ((void (__stdcall *)(unsigned int, AsyncStateMachineStatus, int))iter->vfptr->OnContextEnded)(v4, v7, v18);
        if ( v9 )
        {
          do
          {
            (*(void (__thiscall **)(int, unsigned int, AsyncStateMachineStatus))(*(_DWORD *)v9 + 16))(v9, v4, v7);
            v12 = *(_DWORD *)(v9 + 12);
            if ( !v12 )
              break;
            v13 = v12 - 8;
            if ( v12 == 8 )
              break;
            v9 = v12 - 12;
          }
          while ( v13 != 4 );
        }
        (*(void (__cdecl **)(unsigned int))(*(_DWORD *)iter_4 + 16))(v4);
        v14 = 0;
        if ( *(_DWORD *)(i_eFinalStatus + 108) )
        {
          v15 = *(_DWORD *)(i_eFinalStatus + 112);
          if ( v15 )
            v14 = v15 - 12;
          else
            v14 = 0;
        }
        if ( v14 )
        {
          do
          {
            (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v14 + 20))(v14, v4);
            v16 = *(_DWORD *)(v14 + 12);
            if ( !v16 )
              break;
            v17 = v16 - 8;
            if ( v16 == 8 )
              break;
            v14 = v16 - 12;
          }
          while ( v17 != 4 );
        }
        IntrusiveHashList<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::remove(v21, &hContext);
        if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) )
          v5->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 1u);
      }
    }
  }
}
// 65EED0: could not find valid save-restore pair for edi

//----- (0065F010) --------------------------------------------------------  // acclient.c:629280
AsyncStateMachineStatus __thiscall CAsyncStateMachine::OnHandlerDoneOK(CAsyncStateMachine *this, AsyncContext hContext, int NextStateNumber)
{
  CAsyncStateMachine *v3; // edi@1
  AsyncStateMachineStatus v4; // eax@1
  AsyncStateMachineStatus v5; // esi@1

  v3 = this;
  v4 = ((int (__stdcall *)(unsigned int, int))this->vfptr->Advance)(hContext.m_id, NextStateNumber);
  v5 = v4;
  if ( v4 != 1 )
    CAsyncStateMachine::EndAndReleaseContext(v3, (int)v3, hContext, v4);
  return v5;
}

//----- (0065F040) --------------------------------------------------------  // acclient.c:629295
void __userpurge CAsyncStateMachine::OnHandlerFailed(CAsyncStateMachine *this@<ecx>, int a2@<edi>, AsyncContext hContext)
{
  CAsyncStateMachine::EndAndReleaseContext(this, a2, hContext, AsyncStateMachine_Failed);
}

//----- (0065F050) --------------------------------------------------------  // acclient.c:629301
char __thiscall HashTable<PStringBase<char>,unsigned long,1>::add(HashTable<PStringBase<char>,unsigned long,1> *this, PStringBase<char> *_key, const unsigned int *_data)
{
  HashTable<PStringBase<char>,unsigned long,1> *v3; // edi@1
  void *v4; // esi@1
  PSRefBufferCharData<char> *v5; // eax@2
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> *v6; // edi@4
  char v7; // al@5
  int v8; // edi@7
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> result; // [sp+8h] [bp-Ch]@4

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    v5 = _key->m_charbuffer;
    *(_DWORD *)v4 = _key->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = *_data;
  }
  else
  {
    v4 = 0;
  }
  v6 = &v3->m_intrusiveTable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::find_internal(
    v6,
    &result,
    (PStringBase<char> *)v4);
  if ( result.m_currElement )
  {
    if ( v4 )
    {
      v8 = *(_DWORD *)v4 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) )
      {
        if ( v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      }
      operator delete(v4);
    }
    v7 = 0;
  }
  else
  {
    IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::add_internal(
      v6,
      (HashTableData<PStringBase<char>,unsigned long> *)v4);
    v7 = 1;
  }
  return v7;
}

//----- (0065F0F0) --------------------------------------------------------  // acclient.c:629355
CAsyncStateHandler *__thiscall IntrusiveHashTable<int,CAsyncStateHandler *,1>::remove(IntrusiveHashTable<int,CAsyncStateHandler *,1> *this, const int *key)
{
  unsigned int v2; // edx@1
  CAsyncStateHandler **v3; // eax@1
  CAsyncStateHandler *v4; // esi@1
  int v5; // edx@1
  CAsyncStateHandler *result; // eax@4
  _BYTE v7[12]; // ST00_12@6

  v2 = *key % this->m_numBuckets;
  v3 = this->m_buckets;
  v4 = v3[v2];
  v5 = (int)&v3[v2];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != *key )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    *(_DWORD *)v7 = this;
    *(_QWORD *)&v7[4] = __PAIR__((unsigned int)v4, v5);
    IntrusiveHashTable<int,CAsyncStateHandler *,1>::remove(
      this,
      *(IntrusiveHashIterator<int,CAsyncStateHandler *,1> *)v7);
    result = v4;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (0065F150) --------------------------------------------------------  // acclient.c:629394
unsigned int __thiscall CAsyncStateMachine::RegisterContextDataName(CAsyncStateMachine *this, PStringBase<char> *DataName)
{
  PStringBase<char> *v2; // ebx@1
  CAsyncStateMachine *v3; // esi@1
  unsigned int v4; // eax@2
  PStringBase<char> *v5; // edi@3
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1> result; // [sp+8h] [bp-Ch]@1

  v2 = DataName;
  v3 = this;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::find_internal(
    &this->m_DataNames.m_intrusiveTable,
    &result,
    DataName);
  if ( result.m_currElement )
  {
    v4 = result.m_currElement->m_data;
  }
  else
  {
    DataName = (PStringBase<char> *)v3->m_DataNames.m_intrusiveTable.m_numElements;
    v5 = DataName;
    HashTable<PStringBase<char>,unsigned long,1>::add(
      (HashTable<PStringBase<char>,unsigned long,1> *)&v3->m_DataNames.vfptr,
      v2,
      (const unsigned int *)&DataName);
    v4 = (unsigned int)v5;
  }
  return v4;
}

//----- (0065F1B0) --------------------------------------------------------  // acclient.c:629426
AutoGrowHashTable<PStringBase<char>,unsigned long> *__thiscall HashTable<PStringBase<char>,unsigned long,1>::scalar_deleting_destructor(AutoGrowHashTable<PStringBase<char>,unsigned long> *this, unsigned int a2)
{
  AutoGrowHashTable<PStringBase<char>,unsigned long> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<PStringBase<char>,unsigned long,1>Vtbl *)AutoGrowHashTable<PStringBase<char>,unsigned long>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::delete_contents((IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::vftable;
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
// 7FDA6C: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::vftable[2])(void *, char);
// 7FDA94: using guessed type int (__thiscall *AutoGrowHashTable<PStringBase<char>,unsigned long>::vftable[2])(void *, char);

//----- (0065F210) --------------------------------------------------------  // acclient.c:629452
CAsyncStateHandler *__thiscall IntrusiveHashList<int,CAsyncStateHandler *,1>::remove(IntrusiveHashList<int,CAsyncStateHandler *,1> *this, const int *val)
{
  IntrusiveHashList<int,CAsyncStateHandler *,1> *v2; // edi@1
  CAsyncStateHandler *v3; // esi@1
  DLListData *v5; // eax@7

  v2 = this;
  v3 = v2->m_hash.m_buckets[*val % v2->m_hash.m_numBuckets];
  if ( v3 )
  {
    while ( v3->m_hashKey != *val )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        return 0;
    }
    if ( v3 )
    {
      if ( v3 == (CAsyncStateHandler *)-4 )
        v5 = 0;
      else
        v5 = (DLListData *)&v3->dllist_next;
      DLListBase::Remove(&this->m_list, v5);
      IntrusiveHashTable<int,CAsyncStateHandler *,1>::remove(&v2->m_hash, val);
    }
  }
  return v3;
}

//----- (0065F270) --------------------------------------------------------  // acclient.c:629482
unsigned int __thiscall CAsyncStateHandler::RegisterContextDataName(CAsyncStateHandler *this, PStringBase<char> *DataName)
{
  return CAsyncStateMachine::RegisterContextDataName(this->m_pMachine, DataName);
}

//----- (0065F280) --------------------------------------------------------  // acclient.c:629488
void __thiscall CAsyncStateMachine::CAsyncStateMachine(CAsyncStateMachine *this)
{
  CAsyncStateMachine *v1; // esi@1
  char *v2; // edi@1
  PreciseTimerInstance *v3; // eax@1

  v1 = this;
  v2 = (char *)&this->m_States;
  this->vfptr = (CAsyncStateMachineVtbl *)&CAsyncStateMachine::vftable;
  IntrusiveHashTable<int,CAsyncStateHandler *,1>::IntrusiveHashTable<int,CAsyncStateHandler *,1>(
    &this->m_States.m_hash,
    0);
  *((_DWORD *)v2 + 28) = 0;
  *((_DWORD *)v2 + 29) = 0;
  IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>(
    &v1->m_ContextHash.m_hash,
    0);
  v1->m_ContextHash.m_list.head_ = 0;
  v1->m_ContextHash.m_list.tail_ = 0;
  v1->m_DataNames.vfptr = (HashTable<PStringBase<char>,unsigned long,1>Vtbl *)AutoGrowHashTable<PStringBase<char>,unsigned long>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>(
    &v1->m_DataNames.m_intrusiveTable,
    0);
  v1->m_DataNames.vfptr = (HashTable<PStringBase<char>,unsigned long,1>Vtbl *)AutoGrowHashTable<PStringBase<char>,unsigned long>::vftable;
  v1->m_dwNextContextNumber = 1;
  v1->m_pTimer = 0;
  Timer::GetTimerInstance();
  CAsyncStateMachine::SetTimerInstance(v1, v3);
}
// 7FDA94: using guessed type int (__thiscall *AutoGrowHashTable<PStringBase<char>,unsigned long>::vftable[2])(void *, char);
// 7FDA98: using guessed type int (__thiscall *CAsyncStateMachine::vftable)(void *, char);

//----- (0065F320) --------------------------------------------------------  // acclient.c:629521
void __thiscall CAsyncStateMachine::~CAsyncStateMachine(CAsyncStateMachine *this)
{
  CAsyncStateMachine *v1; // ebx@1
  int v2; // esi@1
  DLListData *v3; // eax@2
  int v4; // eax@3
  AsyncContext v5; // ecx@4
  int v6; // edx@4
  DLListData *v7; // eax@11
  DLListData *v8; // eax@16
  int v9; // ebp@17
  int v10; // edx@18
  int v11; // eax@18
  int v12; // ecx@18
  int v13; // eax@19
  int v14; // edx@22
  int v15; // eax@23
  int v16; // ecx@25
  DLListData *v17; // ecx@27
  DLListData *v18; // ecx@31
  int v19; // esi@33
  int v20; // edx@33
  CAsyncStateHandler **v21; // eax@33
  CAsyncStateHandler *v22; // ecx@33
  int v23; // edi@33
  CAsyncStateHandler *v24; // eax@33
  CAsyncStateHandler *v25; // edx@39
  void *v26; // eax@45
  void *v27; // eax@47
  void *v28; // eax@49

  v1 = this;
  v2 = (int)&this->m_ContextHash;
  this->vfptr = (CAsyncStateMachineVtbl *)&CAsyncStateMachine::vftable;
  if ( this->m_ContextHash.m_hash.m_numElements )
  {
    v3 = this->m_ContextHash.m_list.head_;
    if ( v3 )
    {
      v4 = (int)&v3[-2];
      while ( v4 )
      {
        v5.m_id = *(_DWORD *)(v4 + 8);
        v6 = *(_DWORD *)(*(_DWORD *)(v2 + 96) + 4 * (*(_DWORD *)(v4 + 8) % *(_DWORD *)(v2 + 104)));
        if ( v6 )
        {
          while ( *(_DWORD *)(v6 + 8) != v5.m_id )
          {
            v6 = *(_DWORD *)(v6 + 12);
            if ( !v6 )
              goto LABEL_10;
          }
          if ( v6 )
            CAsyncStateMachine::EndAndReleaseContext(v1, 0, v5, AsyncStateMachine_Failed);
        }
LABEL_10:
        v2 = (int)&v1->m_ContextHash;
        v4 = 0;
        if ( v1->m_ContextHash.m_hash.m_numElements > 0 )
        {
          v7 = v1->m_ContextHash.m_list.head_;
          if ( v7 )
            v4 = (int)&v7[-2];
          else
            v4 = 0;
        }
      }
    }
  }
  if ( v1->m_States.m_hash.m_numElements > 0 )
  {
    v8 = v1->m_States.m_list.head_;
    if ( v8 )
    {
      v9 = (int)&v8[-2].dllist_prev;
      if ( v8 != (DLListData *)12 )
      {
        do
        {
          v10 = *(_DWORD *)v9;
          *(_DWORD *)(v9 + 20) = 0;
          (*(void (__thiscall **)(int))(v10 + 28))(v9);
          v11 = *(_DWORD *)(v9 + 12);
          v12 = v9;
          if ( v11 && (v13 = v11 - 8) != 0 )
            v9 = v13 - 4;
          else
            v9 = 0;
          v14 = v12 + 4;
          if ( v12 == -4 )
            v15 = 0;
          else
            v15 = v12 + 12;
          v16 = *(_DWORD *)(v15 + 4);
          if ( v16 )
          {
            *(_DWORD *)v16 = *(_DWORD *)v15;
          }
          else
          {
            v17 = v1->m_States.m_list.head_->dllist_next;
            v1->m_States.m_list.head_ = v17;
            if ( v17 )
              v17->dllist_prev = 0;
          }
          if ( *(_DWORD *)v15 )
          {
            *(_DWORD *)(*(_DWORD *)v15 + 4) = *(_DWORD *)(v15 + 4);
          }
          else
          {
            v18 = v1->m_States.m_list.tail_->dllist_prev;
            v1->m_States.m_list.tail_ = v18;
            if ( v18 )
              v18->dllist_next = 0;
          }
          *(_DWORD *)v15 = 0;
          *(_DWORD *)(v15 + 4) = 0;
          v19 = *(_DWORD *)v14;
          v20 = *(_DWORD *)v14 % v1->m_States.m_hash.m_numBuckets;
          v21 = v1->m_States.m_hash.m_buckets;
          v22 = v21[v20];
          v23 = (int)&v21[v20];
          v24 = v21[v20];
          if ( v24 )
          {
            while ( v24->m_hashKey != v19 )
            {
              v24 = v24->m_hashNext;
              if ( !v24 )
                goto LABEL_44;
            }
            if ( v24 )
            {
              if ( v22 == v24 )
                goto LABEL_54;
              do
              {
                v25 = v22;
                v22 = v22->m_hashNext;
              }
              while ( v22 != v24 );
              if ( v25 )
                v25->m_hashNext = v22->m_hashNext;
              else
LABEL_54:
                *(_DWORD *)v23 = v22->m_hashNext;
              --v1->m_States.m_hash.m_numElements;
            }
          }
LABEL_44:
          ;
        }
        while ( v9 );
      }
    }
  }
  v1->m_DataNames.vfptr = (HashTable<PStringBase<char>,unsigned long,1>Vtbl *)AutoGrowHashTable<PStringBase<char>,unsigned long>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::delete_contents((IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *)&v1->m_DataNames.m_intrusiveTable);
  v26 = v1->m_DataNames.m_intrusiveTable.m_buckets;
  v1->m_DataNames.m_intrusiveTable.vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>Vtbl *)IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::vftable;
  if ( v26 != v1->m_DataNames.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v26);
  v1->m_DataNames.m_intrusiveTable.m_buckets = 0;
  v1->m_DataNames.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_DataNames.m_intrusiveTable.m_numBuckets = 0;
  v1->m_DataNames.m_intrusiveTable.m_numElements = 0;
  v27 = v1->m_ContextHash.m_hash.m_buckets;
  v1->m_ContextHash.m_hash.vfptr = (IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>Vtbl *)IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::vftable;
  if ( v27 != v1->m_ContextHash.m_hash.m_aInplaceBuckets )
    operator delete[](v27);
  v1->m_ContextHash.m_hash.m_buckets = 0;
  v1->m_ContextHash.m_hash.m_firstInterestingBucket = 0;
  v1->m_ContextHash.m_hash.m_numBuckets = 0;
  v1->m_ContextHash.m_hash.m_numElements = 0;
  v28 = v1->m_States.m_hash.m_buckets;
  v1->m_States.m_hash.vfptr = (IntrusiveHashTable<int,CAsyncStateHandler *,1>Vtbl *)IntrusiveHashTable<int,CAsyncStateHandler *,1>::vftable;
  if ( v28 != v1->m_States.m_hash.m_aInplaceBuckets )
    operator delete[](v28);
  v1->m_States.m_hash.m_buckets = 0;
  v1->m_States.m_hash.m_firstInterestingBucket = 0;
  v1->m_States.m_hash.m_numBuckets = 0;
  v1->m_States.m_hash.m_numElements = 0;
}
// 7FDA64: using guessed type int (__thiscall *IntrusiveHashTable<int,CAsyncStateHandler *,1>::vftable[4])(void *, char);
// 7FDA68: using guessed type int (__thiscall *IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::vftable[3])(void *, char);
// 7FDA6C: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::vftable[2])(void *, char);
// 7FDA94: using guessed type int (__thiscall *AutoGrowHashTable<PStringBase<char>,unsigned long>::vftable[2])(void *, char);
// 7FDA98: using guessed type int (__thiscall *CAsyncStateMachine::vftable)(void *, char);

//----- (0065F540) --------------------------------------------------------  // acclient.c:629712
char __thiscall CAsyncStateMachine::RemoveStateHandler(CAsyncStateMachine *this, int StateNumber)
{
  CAsyncStateMachine *v2; // edi@1
  IntrusiveHashList<int,CAsyncStateHandler *,1> *v3; // ebx@1
  CAsyncStateHandler *v4; // esi@1
  char result; // al@4
  char *v6; // ecx@7
  DLListData *v7; // eax@8
  int v8; // eax@9
  char *v9; // ebx@10
  int v10; // ecx@10
  int v11; // ecx@11
  int v12; // edi@12
  CAsyncStateHandlerVtbl *v13; // edx@18
  CAsyncStateMachine *v14; // [sp+Ch] [bp-10h]@1
  char *v15; // [sp+10h] [bp-Ch]@1

  v2 = this;
  v3 = &this->m_States;
  v14 = this;
  v15 = (char *)&this->m_States;
  v4 = this->m_States.m_hash.m_buckets[StateNumber % this->m_States.m_hash.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != StateNumber )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    if ( this->m_ContextHash.m_hash.m_numElements )
    {
      v6 = (char *)&this->m_ContextHash;
      if ( v2->m_ContextHash.m_hash.m_numElements )
      {
        v7 = v2->m_ContextHash.m_list.head_;
        if ( v7 )
        {
          v8 = (int)&v7[-2];
          if ( v8 )
          {
            do
            {
              v9 = v6;
              v10 = *(_DWORD *)(v8 + 16);
              if ( v10 && (v11 = v10 - 8) != 0 )
                v12 = v11 - 8;
              else
                v12 = 0;
              if ( *(CAsyncStateHandler **)(v8 + 48) == v4 )
                CAsyncStateMachine::EndAndReleaseContext(
                  v14,
                  v12,
                  *(AsyncContext *)(v8 + 8),
                  AsyncStateMachine_InternalError);
              v8 = v12;
              v6 = v9;
            }
            while ( v12 );
            v3 = (IntrusiveHashList<int,CAsyncStateHandler *,1> *)v15;
          }
        }
      }
    }
    v13 = v4->vfptr;
    v4->m_pMachine = 0;
    v13->OnStateHandlerDone(v4);
    IntrusiveHashList<int,CAsyncStateHandler *,1>::remove(v3, &StateNumber);
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (0065F610) --------------------------------------------------------  // acclient.c:629793
void __thiscall CAsyncStateHandler::~CAsyncStateHandler(CAsyncStateHandler *this)
{
  CAsyncStateHandler *v1; // esi@1
  CAsyncStateMachine *v2; // ecx@1

  v1 = this;
  v2 = this->m_pMachine;
  v1->vfptr = (CAsyncStateHandlerVtbl *)&CAsyncStateHandler::vftable;
  if ( v2 )
    CAsyncStateMachine::RemoveStateHandler(v2, v1->m_hashKey);
  v1->m_pMachine = 0;
}
// 7FDA70: using guessed type int (__thiscall *CAsyncStateHandler::vftable)(void *, char);

//----- (0065F640) --------------------------------------------------------  // acclient.c:629808
CAsyncStateMachine *__thiscall CAsyncStateMachine::scalar_deleting_destructor(CAsyncStateMachine *this, unsigned int a2)
{
  CAsyncStateMachine *v2; // esi@1

  v2 = this;
  CAsyncStateMachine::~CAsyncStateMachine(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0065F660) --------------------------------------------------------  // acclient.c:629820
CAsyncStateHandler *__thiscall CAsyncStateHandler::vector_deleting_destructor(CAsyncStateHandler *this, unsigned int a2)
{
  CAsyncStateHandler *v2; // esi@1
  CAsyncStateMachine *v3; // ecx@1

  v2 = this;
  v3 = this->m_pMachine;
  v2->vfptr = (CAsyncStateHandlerVtbl *)&CAsyncStateHandler::vftable;
  if ( v3 )
    CAsyncStateMachine::RemoveStateHandler(v3, v2->m_hashKey);
  v2->m_pMachine = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7FDA70: using guessed type int (__thiscall *CAsyncStateHandler::vftable)(void *, char);

