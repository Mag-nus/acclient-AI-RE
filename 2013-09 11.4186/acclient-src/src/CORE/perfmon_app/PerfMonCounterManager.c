/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PerfMonCounterManager
   Object     : CORE\perfmon_app\PerfMonCounterManager.obj
   Functions  : 26
   Addresses  : 00682F20 - 0077F670 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00682F20) --------------------------------------------------------  // acclient.c:666462
void __thiscall PerfMonCounterManager::CrashCleanup(PerfMonCounterManager *this)
{
  this->m_pRpcServer = 0;
  PerfMonCounterManager::Sm_pPerfMonCounterManager = 0;
}

//----- (00682F30) --------------------------------------------------------  // acclient.c:666469
signed int __fastcall GetNumberPerfCounters(void *h1, unsigned int *arraySize)
{
  signed int result; // eax@2

  if ( PerfMonCounterManager::Sm_pPerfMonCounterManager )
  {
    *arraySize = PerfMonCounterManager::Sm_pPerfMonCounterManager->m_counters._num_elements;
    result = 1;
  }
  else
  {
    *arraySize = 0;
    result = 0;
  }
  return result;
}

//----- (00682F50) --------------------------------------------------------  // acclient.c:666487
char __thiscall List<PerfMonCounterInfo *>::push_back(List<PerfMonCounterInfo *> *this, PerfMonCounterInfo *const *val)
{
  List<PerfMonCounterInfo *> *v2; // esi@1
  void *v3; // eax@1
  char result; // al@3
  ListNode<PerfMonCounterInfo *> *v5; // ecx@5

  v2 = this;
  v3 = operator new(0xCu);
  if ( v3 )
  {
    *(_DWORD *)v3 = *val;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
    if ( v2->_head )
    {
      v5 = v2->_tail;
      v5->next = (ListNode<PerfMonCounterInfo *> *)v3;
      *((_DWORD *)v3 + 2) = v5;
      v2->_tail = (ListNode<PerfMonCounterInfo *> *)v3;
      result = 1;
      ++v2->_num_elements;
    }
    else
    {
      v2->_head = (ListNode<PerfMonCounterInfo *> *)v3;
      v2->_tail = (ListNode<PerfMonCounterInfo *> *)v3;
      result = 1;
      ++v2->_num_elements;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00682FB0) --------------------------------------------------------  // acclient.c:666526
PerfMonCounterInfo *__thiscall PerfMonCounterManager::LookupExistingCounterByName(PerfMonCounterManager *this, PStringBase<unsigned short> *name, int language)
{
  ListNode<PerfMonCounterInfo *> *v3; // esi@1
  PSRefBufferCharData<unsigned short> *v4; // eax@3
  PSRefBufferCharData<unsigned short> *v5; // ecx@3
  int v6; // edx@4
  int v7; // edi@4
  PerfMonCounterInfo *v8; // esi@11
  char *v9; // edi@11
  int v11; // esi@16
  PStringBase<unsigned short> existingName; // [sp+10h] [bp-4h]@1

  v3 = this->m_counters._head;
  existingName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( v3 )
  {
    while ( 1 )
    {
      if ( (unsigned __int8)((int (__stdcall *)(int, PStringBase<unsigned short> *))v3->data->vfptr[2].__vecDelDtor)(
                              language,
                              &existingName) )
      {
        v4 = name->m_charbuffer;
        v5 = existingName.m_charbuffer;
        if ( *(_DWORD *)&name->m_charbuffer[-1].m_data[14] != *(_DWORD *)&existingName.m_charbuffer[-1].m_data[14] )
          goto LABEL_9;
        v6 = *(_DWORD *)&v4[-1].m_data[12];
        v7 = *(_DWORD *)&existingName.m_charbuffer[-1].m_data[12];
        if ( v6 != v7 && v6 != -1 && v7 != -1 )
          goto LABEL_9;
        if ( _wcscmp(v4->m_data, existingName.m_charbuffer->m_data) == 0 )
        {
          InterlockedIncrement((volatile LONG *)&v3->data->m_cRef);
          v8 = v3->data;
          v9 = (char *)&existingName.m_charbuffer[-1].m_data[6];
          if ( !InterlockedDecrement((volatile LONG *)&existingName.m_charbuffer[-1].m_data[8]) && v9 )
            (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
          return v8;
        }
      }
      v5 = existingName.m_charbuffer;
LABEL_9:
      v3 = v3->next;
      if ( !v3 )
        goto LABEL_16;
    }
  }
  v5 = existingName.m_charbuffer;
LABEL_16:
  v11 = (int)&v5[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v5[-1].m_data[8]) )
  {
    if ( v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
  }
  return 0;
}

//----- (006830A0) --------------------------------------------------------  // acclient.c:666586
bool __thiscall PerfMonCounterManager::AddCounter(PerfMonCounterManager *this, PerfMonCounterInfo *counter)
{
  PerfMonCounterManager *v2; // esi@1
  RpcServer *v3; // eax@1
  bool result; // al@4
  PerfMonCounterInfo *v5; // edi@5
  ReferenceCountTemplate<1048576,0> *v6; // eax@5
  char *v7; // esi@6
  char v8; // al@10
  char *v9; // esi@10
  bool v10; // bl@10
  PStringBase<unsigned short> counterName; // [sp+4h] [bp-8h]@5
  int counterNameLanguage; // [sp+8h] [bp-4h]@5

  v2 = this;
  v3 = this->m_pRpcServer;
  if ( v3 && v3->m_fServerStarted || this->m_fInstalling )
  {
    result = 0;
  }
  else
  {
    v5 = counter;
    counterNameLanguage = 0;
    PerfMonCounterInfo::GetFirstName(counter, &counterName, (unsigned __int16 *)&counterNameLanguage);
    v6 = (ReferenceCountTemplate<1048576,0> *)PerfMonCounterManager::LookupExistingCounterByName(
                                                v2,
                                                &counterName,
                                                counterNameLanguage);
    if ( v6 )
    {
      ReferenceCountTemplate<1048576,0>::Release(v6);
      v7 = (char *)&counterName.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&counterName.m_charbuffer[-1].m_data[8]) )
      {
        if ( v7 )
          (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
      }
      result = 0;
    }
    else
    {
      InterlockedIncrement((volatile LONG *)&v5->m_cRef);
      v8 = List<PerfMonCounterInfo *>::push_back(&v2->m_counters, &counter);
      v9 = (char *)&counterName.m_charbuffer[-1].m_data[6];
      v10 = v8;
      if ( !InterlockedDecrement((volatile LONG *)&counterName.m_charbuffer[-1].m_data[8]) && v9 )
        (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
      result = v10;
    }
  }
  return result;
}

//----- (00683170) --------------------------------------------------------  // acclient.c:666641
void __thiscall SmartArray<__int64,1>::Reset(SmartArray<__int64,1> *this)
{
  SmartArray<__int64,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int i; // eax@4
  void *v5; // ecx@5

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    for ( i = (v2 & 0x7FFFFFFF) - 1; i >= 0; *((_DWORD *)v5 + 2 * i + 3) = 0 )
    {
      --i;
      v5 = v1->m_data;
      *((_DWORD *)v5 + 2 * i + 2) = 0;
    }
  }
}

//----- (006831D0) --------------------------------------------------------  // acclient.c:666671
char __thiscall PerfMonCounterManager::ShutdownAndResetInternal(PerfMonCounterManager *this)
{
  PerfMonCounterManager *v1; // esi@1
  RpcServer *v2; // edi@1
  ListNode<PerfMonCounterInfo *> *v3; // eax@4
  ListNode<PerfMonCounterInfo *> *v4; // ecx@5
  PerfMonCounterInfo *v5; // edi@8

  v1 = this;
  v2 = this->m_pRpcServer;
  if ( v2 )
  {
    RpcServer::~RpcServer(this->m_pRpcServer);
    operator delete(v2);
    v1->m_pRpcServer = 0;
  }
  while ( v1->m_counters._head )
  {
    v3 = v1->m_counters._head;
    if ( v3 )
    {
      v4 = v3->next;
      v1->m_counters._head = v4;
      if ( v4 )
        v4->prev = 0;
      else
        v1->m_counters._tail = 0;
      v5 = v3->data;
      operator delete(v3);
      --v1->m_counters._num_elements;
      if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) )
      {
        if ( v5 )
          v5->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 1u);
      }
    }
  }
  return 1;
}

//----- (00683250) --------------------------------------------------------  // acclient.c:666712
bool __thiscall SmartArray<__int64,1>::grow(SmartArray<__int64,1> *this, unsigned int i_nSize)
{
  SmartArray<__int64,1> *v2; // esi@1
  bool result; // al@5
  void *v4; // edi@6
  int i; // eax@8
  void *v6; // edx@9

  v2 = this;
  if ( i_nSize < this->m_num )
  {
    result = 0;
  }
  else
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<__int64,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](8 * i_nSize);
    if ( v4 )
    {
      if ( v2->m_data )
      {
        for ( i = v2->m_num - 1; i >= 0; *((_DWORD *)v4 + 2 * i + 3) = *((_DWORD *)v6 + 2 * i + 3) )
        {
          --i;
          v6 = v2->m_data;
          *((_DWORD *)v4 + 2 * i + 2) = LODWORD(v2->m_data[i + 1]);
        }
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = (__int64 *)v4;
      v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (00683300) --------------------------------------------------------  // acclient.c:666761
void __thiscall List<PerfMonCounterInfo *>::flush(List<PerfMonCounterInfo *> *this)
{
  List<PerfMonCounterInfo *> *i; // esi@1
  ListNode<PerfMonCounterInfo *> *v2; // ecx@2
  ListNode<PerfMonCounterInfo *> *v3; // eax@3

  for ( i = this; ; --i->_num_elements )
  {
    v2 = i->_head;
    if ( !v2 )
      break;
    v3 = v2->next;
    i->_head = v3;
    if ( v3 )
      v3->prev = 0;
    else
      i->_tail = 0;
    if ( v2 )
      operator delete(v2);
  }
}

//----- (00683340) --------------------------------------------------------  // acclient.c:666784
List<PerfMonCounterInfo *> *__thiscall List<PerfMonCounterInfo *>::scalar_deleting_destructor(List<PerfMonCounterInfo *> *this, unsigned int a2)
{
  List<PerfMonCounterInfo *> *v2; // esi@1

  v2 = this;
  this->vfptr = (List<PerfMonCounterInfo *>Vtbl *)List<PerfMonCounterInfo *>::vftable;
  List<PerfMonCounterInfo *>::flush(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7FEC20: using guessed type int (__thiscall *List<PerfMonCounterInfo *>::vftable[2])(void *, char);

//----- (00683370) --------------------------------------------------------  // acclient.c:666798
unsigned int __thiscall PerfMonCounterManager::FillInCounterTypes(PerfMonCounterManager *this, SmartArray<unsigned long,1> *counterTypes)
{
  ListNode<PerfMonCounterInfo *> *v2; // ebx@1
  unsigned int result; // eax@1
  SmartArray<unsigned long,1> *v4; // edi@2
  unsigned int v5; // ebp@3
  int v6; // eax@3
  unsigned int v7; // edx@4
  unsigned int cCounters; // [sp+0h] [bp-4h]@1
  SmartArray<unsigned long,1> *counterTypesa; // [sp+8h] [bp+4h]@9

  v2 = this->m_counters._head;
  result = 0;
  cCounters = 0;
  if ( v2 )
  {
    v4 = counterTypes;
    do
    {
      v5 = v2->data->m_CounterType;
      v6 = v4->m_sizeAndDeallocate & 0x7FFFFFFF;
      if ( v4->m_num < v6 )
        goto LABEL_17;
      v7 = v6 + 1;
      if ( (unsigned int)(v6 + 1) > 8 )
      {
        if ( v7 <= 0x4000 )
        {
          counterTypesa = (SmartArray<unsigned long,1> *)(v6 + 1);
          __asm { bsr     eax, [esp+14h+counterTypes] }
          if ( v7 > 1 << _EAX )
            v7 = 2 * (1 << _EAX);
        }
        else if ( v7 & 0x3FFF )
        {
          v7 += 0x4000 - (v7 & 0x3FFF);
        }
      }
      else
      {
        v7 = 8;
      }
      if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v4, v7) )
LABEL_17:
        v4->m_data[v4->m_num++] = v5;
      v2 = v2->next;
      ++cCounters;
    }
    while ( v2 );
    result = cCounters;
  }
  return result;
}

//----- (00683420) --------------------------------------------------------  // acclient.c:666853
unsigned int __thiscall PerfMonCounterManager::FillInCounterValues(PerfMonCounterManager *this, SmartArray<__int64,1> *counterValues)
{
  ListNode<PerfMonCounterInfo *> *v2; // ebx@1
  unsigned int result; // eax@1
  SmartArray<__int64,1> *v4; // esi@2
  int v5; // ebp@3
  int v6; // eax@3
  int v7; // edx@3
  unsigned int v8; // edx@4
  unsigned int v14; // edx@12
  __int64 *v15; // eax@12
  unsigned int cCounters; // [sp+4h] [bp-Ch]@1
  int v17; // [sp+Ch] [bp-4h]@3
  SmartArray<__int64,1> *counterValuesa; // [sp+14h] [bp+4h]@9

  v2 = this->m_counters._head;
  result = 0;
  cCounters = 0;
  if ( v2 )
  {
    v4 = counterValues;
    do
    {
      v5 = ((int (*)(void))v2->data->vfptr[1].__vecDelDtor)();
      v6 = v4->m_sizeAndDeallocate & 0x7FFFFFFF;
      v17 = v7;
      if ( v4->m_num < v6 )
        goto LABEL_17;
      v8 = v6 + 1;
      if ( (unsigned int)(v6 + 1) > 8 )
      {
        if ( v8 <= 0x4000 )
        {
          counterValuesa = (SmartArray<__int64,1> *)(v6 + 1);
          __asm { bsr     eax, [esp+1Ch+counterValues] }
          if ( v8 > 1 << _EAX )
            v8 = 2 * (1 << _EAX);
        }
        else if ( v8 & 0x3FFF )
        {
          v8 += 0x4000 - (v8 & 0x3FFF);
        }
      }
      else
      {
        v8 = 8;
      }
      if ( SmartArray<__int64,1>::grow(v4, v8) )
      {
LABEL_17:
        v14 = v4->m_num;
        v15 = v4->m_data;
        LODWORD(v15[v14]) = v5;
        HIDWORD(v15[v14]) = v17;
        ++v4->m_num;
      }
      v2 = v2->next;
      ++cCounters;
    }
    while ( v2 );
    result = cCounters;
  }
  return result;
}

//----- (006834F0) --------------------------------------------------------  // acclient.c:666919
signed int __fastcall GetPerfCounterDescriptions(void *h1, unsigned int arraySize, unsigned int *counterType)
{
  unsigned int v3; // esi@1
  unsigned int v4; // eax@2
  unsigned int *v6; // eax@6
  SmartArray<unsigned long,1> counterTypes; // [sp+Ch] [bp-Ch]@2

  v3 = 4 * arraySize;
  memset(counterType, 0, 4 * arraySize);
  if ( !PerfMonCounterManager::Sm_pPerfMonCounterManager )
    return 0;
  v4 = PerfMonCounterManager::Sm_pPerfMonCounterManager->m_counters._num_elements;
  counterTypes.m_data = 0;
  counterTypes.m_sizeAndDeallocate = 0;
  counterTypes.m_num = 0;
  if ( !SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&counterTypes, v4) )
  {
    if ( (counterTypes.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](counterTypes.m_data);
    return 0;
  }
  PerfMonCounterManager::FillInCounterTypes(PerfMonCounterManager::Sm_pPerfMonCounterManager, &counterTypes);
  v6 = counterTypes.m_data;
  qmemcpy(counterType, counterTypes.m_data, v3);
  if ( (counterTypes.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v6);
  return 1;
}

//----- (006835C0) --------------------------------------------------------  // acclient.c:666949
signed int __fastcall GetPerfCounterValues(void *h1, unsigned int arraySize, unsigned __int64 *values)
{
  unsigned int v3; // esi@1
  unsigned int v4; // eax@2
  __int64 *v6; // eax@6
  SmartArray<__int64,1> counterValues; // [sp+Ch] [bp-Ch]@2

  v3 = 8 * arraySize;
  memset(values, 0, 8 * arraySize);
  if ( !PerfMonCounterManager::Sm_pPerfMonCounterManager )
    return 0;
  v4 = PerfMonCounterManager::Sm_pPerfMonCounterManager->m_counters._num_elements;
  counterValues.m_data = 0;
  counterValues.m_sizeAndDeallocate = 0;
  counterValues.m_num = 0;
  if ( !SmartArray<__int64,1>::grow(&counterValues, v4) )
  {
    if ( (counterValues.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](counterValues.m_data);
    return 0;
  }
  PerfMonCounterManager::FillInCounterValues(PerfMonCounterManager::Sm_pPerfMonCounterManager, &counterValues);
  v6 = counterValues.m_data;
  qmemcpy(values, counterValues.m_data, v3);
  if ( (counterValues.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v6);
  return 1;
}

//----- (00683690) --------------------------------------------------------  // acclient.c:666979
PerfMonCounterManager *__thiscall PerfMonCounterManager::vector_deleting_destructor(PerfMonCounterManager *this, unsigned int a2)
{
  PerfMonCounterManager *v2; // esi@1

  v2 = this;
  this->vfptr = (CPluginPrototypeVtbl *)&PerfMonCounterManager::vftable;
  PerfMonCounterManager::ShutdownAndResetInternal(this);
  PerfMonCounterManager::Sm_pPerfMonCounterManager = 0;
  v2->m_counters.vfptr = (List<PerfMonCounterInfo *>Vtbl *)List<PerfMonCounterInfo *>::vftable;
  List<PerfMonCounterInfo *>::flush(&v2->m_counters);
  CrashCleaner::~CrashCleaner((CrashCleaner *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7FEC20: using guessed type int (__thiscall *List<PerfMonCounterInfo *>::vftable[2])(void *, char);
// 7FEC24: using guessed type int (__thiscall *PerfMonCounterManager::vftable)(void *, char);

//----- (007155C0) --------------------------------------------------------  // acclient.c:808347
int sub_7155C0()
{
  return atexit(nullsub_222);
}

//----- (007155D0) --------------------------------------------------------  // acclient.c:808353
int _E4_34()
{
  return atexit(_E5_34);
}

//----- (007155E0) --------------------------------------------------------  // acclient.c:808359
int _E7_34()
{
  Outside_CellID_34.id = Invalid_CellID_34.id + 1;
  return atexit(_E8_34);
}

//----- (00715600) --------------------------------------------------------  // acclient.c:808366
int _E10_33()
{
  In_Limbo_CellID_33.id = Outside_CellID_34.id + 1;
  return atexit(_E11_33);
}

//----- (00715620) --------------------------------------------------------  // acclient.c:808373
int _E13_33()
{
  First_Interior_CellID_33.id = In_Limbo_CellID_33.id + 1;
  return atexit(_E14_33);
}

//----- (00715640) --------------------------------------------------------  // acclient.c:808380
int _E16_33()
{
  Last_Interior_CellID_33.id = Invalid_CellID_34.id - 1;
  return atexit(_E17_33);
}

//----- (00715660) --------------------------------------------------------  // acclient.c:808387
int _E21_36()
{
  return atexit(_E22_36);
}

//----- (00715670) --------------------------------------------------------  // acclient.c:808393
int _E40_35()
{
  return atexit(_E41_35);
}

//----- (00715680) --------------------------------------------------------  // acclient.c:808399
int _E43_38()
{
  return atexit(_E44_38);
}

//----- (00715690) --------------------------------------------------------  // acclient.c:808405
int sub_715690()
{
  CrashCleaner::CrashCleaner(&G_PerfmonCounterManager);
  G_PerfmonCounterManager.vfptr = (CPluginPrototypeVtbl *)&PerfMonCounterManager::vftable;
  dword_8F7ACC = 0;
  stru_8F7AD0.vfptr = (List<PerfMonCounterInfo *>Vtbl *)List<PerfMonCounterInfo *>::vftable;
  stru_8F7AD0._head = 0;
  stru_8F7AD0._tail = 0;
  stru_8F7AD0._num_elements = 0;
  byte_8F7AE0 = 0;
  PerfMonCounterManager::Sm_pPerfMonCounterManager = (PerfMonCounterManager *)&G_PerfmonCounterManager;
  return atexit(sub_77F670);
}
// 7FEC20: using guessed type int (__thiscall *List<PerfMonCounterInfo *>::vftable[2])(void *, char);
// 7FEC24: using guessed type int (__thiscall *PerfMonCounterManager::vftable)(void *, char);
// 8F7ACC: using guessed type int dword_8F7ACC;
// 8F7AE0: using guessed type char byte_8F7AE0;

//----- (0077F670) --------------------------------------------------------  // acclient.c:918077
void __cdecl sub_77F670()
{
  G_PerfmonCounterManager.vfptr = (CPluginPrototypeVtbl *)&PerfMonCounterManager::vftable;
  PerfMonCounterManager::ShutdownAndResetInternal((PerfMonCounterManager *)&G_PerfmonCounterManager);
  PerfMonCounterManager::Sm_pPerfMonCounterManager = 0;
  stru_8F7AD0.vfptr = (List<PerfMonCounterInfo *>Vtbl *)List<PerfMonCounterInfo *>::vftable;
  List<PerfMonCounterInfo *>::flush(&stru_8F7AD0);
  CrashCleaner::~CrashCleaner(&G_PerfmonCounterManager);
}
// 7FEC20: using guessed type int (__thiscall *List<PerfMonCounterInfo *>::vftable[2])(void *, char);
// 7FEC24: using guessed type int (__thiscall *PerfMonCounterManager::vftable)(void *, char);

