/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PerfMonCounterInfo
   Object     : CORE\perfmon_app\PerfMonCounterInfo.obj
   Functions  : 18
   Addresses  : 00682A80 - 007155B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00682A80) --------------------------------------------------------  // acclient.c:666114
PerfMonCounterInfo *__cdecl PerfMonCounterInfo::LookupExistingCounterByName(PStringBase<unsigned short> *name, int language)
{
  PerfMonCounterInfo *result; // eax@2

  if ( PerfMonCounterManager::Sm_pPerfMonCounterManager )
    result = PerfMonCounterManager::LookupExistingCounterByName(
               PerfMonCounterManager::Sm_pPerfMonCounterManager,
               name,
               language);
  else
    result = 0;
  return result;
}

//----- (00682AA0) --------------------------------------------------------  // acclient.c:666129
void __thiscall ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp>::ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp>(ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *this, PerfMonCounterInfo::PerfMonCounterNameHelp *_data)
{
  int v2; // esi@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1

  v2 = (int)this;
  v3 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  this->data.m_name.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  *(_DWORD *)(v2 + 8) = PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v4);
  PerfMonCounterInfo::PerfMonCounterNameHelp::operator=(v2, (int)_data);
  *(_DWORD *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 16) = 0;
}

//----- (00682AF0) --------------------------------------------------------  // acclient.c:666148
PStringBase<unsigned short> *__thiscall PerfMonCounterInfo::GetFirstName(PerfMonCounterInfo *this, PStringBase<unsigned short> *result, unsigned __int16 *languageOUT)
{
  ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *v3; // eax@1
  PSRefBufferCharData<unsigned short> *v4; // eax@2
  PStringBase<unsigned short> *v5; // eax@2

  v3 = this->m_CounterNamesList._head;
  if ( v3 )
  {
    *languageOUT = v3->data.m_languageID;
    v4 = v3->data.m_name.m_charbuffer;
    result->m_charbuffer = v4;
    InterlockedIncrement((volatile LONG *)&v4[-1].m_data[8]);
    v5 = result;
  }
  else
  {
    *languageOUT = 0;
    PStringBase<unsigned short>::PStringBase<unsigned short>(result, &word_794320);
    v5 = result;
  }
  return v5;
}

//----- (00682B40) --------------------------------------------------------  // acclient.c:666173
char __thiscall PerfMonCounterInfo::LookupByLanguage(PerfMonCounterInfo *this, const unsigned __int16 language, PStringBase<unsigned short> *name)
{
  PSRefBufferCharData<unsigned short> *v3; // ebp@1
  volatile LONG *lpAddend; // ST14_4@1
  PSRefBufferCharData<unsigned short> *v5; // edi@1
  volatile LONG *v6; // ebx@1
  int v7; // edi@1
  ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *v8; // edi@7
  char result; // al@12
  PSRefBufferCharData<unsigned short> *v10; // eax@13
  int v11; // ebp@14
  PSRefBufferCharData<unsigned short> *v12; // edi@17
  PerfMonCounterInfo *v13; // [sp+14h] [bp-10h]@1
  PerfMonCounterInfo::PerfMonCounterNameHelp dummy; // [sp+18h] [bp-Ch]@1

  v3 = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v13 = this;
  lpAddend = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v5 = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v6 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  dummy.m_languageID = language;
  dummy.m_name.m_charbuffer = v5;
  InterlockedIncrement(v6);
  dummy.m_help.m_charbuffer = v3;
  InterlockedIncrement(lpAddend);
  v7 = (int)&v5[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  if ( !InterlockedDecrement((volatile LONG *)&v3[-1].m_data[8]) && v3 != (PSRefBufferCharData<unsigned short> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&v3[-1].m_data[6])(&v3[-1].m_data[6], 1);
  v8 = v13->m_CounterNamesList._head;
  if ( !v8 )
    goto LABEL_12;
  while ( v8->data.m_languageID != language )
  {
    v8 = v8->next;
    if ( !v8 )
      goto LABEL_12;
  }
  if ( v8 )
  {
    v10 = name->m_charbuffer;
    if ( name->m_charbuffer != v8->data.m_name.m_charbuffer )
    {
      v11 = (int)&v10[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v10[-1].m_data[8]) )
      {
        if ( v11 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      }
      v12 = v8->data.m_name.m_charbuffer;
      name->m_charbuffer = v12;
      InterlockedIncrement((volatile LONG *)&v12[-1].m_data[8]);
    }
    PerfMonCounterInfo::PerfMonCounterNameHelp::~PerfMonCounterNameHelp(&dummy);
    result = 1;
  }
  else
  {
LABEL_12:
    PStringBase<unsigned short>::set(name, &word_794320);
    PerfMonCounterInfo::PerfMonCounterNameHelp::~PerfMonCounterNameHelp(&dummy);
    result = 0;
  }
  return result;
}

//----- (00682C60) --------------------------------------------------------  // acclient.c:666243
char __thiscall List<PerfMonCounterInfo::PerfMonCounterNameHelp>::insert(List<PerfMonCounterInfo::PerfMonCounterNameHelp> *this, ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *node, PerfMonCounterInfo::PerfMonCounterNameHelp *val)
{
  List<PerfMonCounterInfo::PerfMonCounterNameHelp> *v3; // esi@1
  ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *v4; // eax@1
  int v5; // eax@2
  char result; // al@3
  ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *v7; // edx@6

  v3 = this;
  v4 = (ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *)operator new(0x14u);
  if ( v4
    && (ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp>::ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp>(
          v4,
          val),
        v5) )
  {
    if ( v3->_head )
    {
      *(_DWORD *)(v5 + 12) = node;
      *(_DWORD *)(v5 + 16) = node->prev;
      v7 = node->prev;
      if ( v7 )
      {
        v7->next = (ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *)v5;
        node->prev = (ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *)v5;
        result = 1;
        ++v3->_num_elements;
      }
      else
      {
        v3->_head = (ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *)v5;
        node->prev = (ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *)v5;
        result = 1;
        ++v3->_num_elements;
      }
    }
    else
    {
      v3->_head = (ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *)v5;
      v3->_tail = (ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *)v5;
      result = 1;
      ++v3->_num_elements;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00682CE0) --------------------------------------------------------  // acclient.c:666295
char __thiscall List<PerfMonCounterInfo::PerfMonCounterNameHelp>::insert_sort(List<PerfMonCounterInfo::PerfMonCounterNameHelp> *this, PerfMonCounterInfo::PerfMonCounterNameHelp *val)
{
  List<PerfMonCounterInfo::PerfMonCounterNameHelp> *v2; // edi@1
  ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *v3; // eax@1
  int v4; // esi@6
  volatile LONG *v5; // ST00_4@7
  volatile LONG *v6; // ST00_4@7
  char result; // al@8
  ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *v8; // eax@10

  v2 = this;
  v3 = this->_head;
  if ( !v3 )
    goto LABEL_6;
  while ( val->m_languageID >= v3->data.m_languageID )
  {
    v3 = v3->next;
    if ( !v3 )
      goto LABEL_6;
  }
  if ( v3 )
  {
    result = List<PerfMonCounterInfo::PerfMonCounterNameHelp>::insert(this, v3, val);
  }
  else
  {
LABEL_6:
    v4 = (int)operator new(0x14u);
    if ( v4 )
    {
      v5 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
      *(_DWORD *)(v4 + 4) = PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement(v5);
      v6 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
      *(_DWORD *)(v4 + 8) = PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement(v6);
      PerfMonCounterInfo::PerfMonCounterNameHelp::operator=(v4, (int)val);
      *(_DWORD *)(v4 + 12) = 0;
      *(_DWORD *)(v4 + 16) = 0;
      if ( v2->_head )
      {
        v8 = v2->_tail;
        v8->next = (ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *)v4;
        *(_DWORD *)(v4 + 16) = v8;
        v2->_tail = (ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *)v4;
        result = 1;
        ++v2->_num_elements;
      }
      else
      {
        v2->_head = (ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *)v4;
        v2->_tail = (ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *)v4;
        result = 1;
        ++v2->_num_elements;
      }
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (00682DA0) --------------------------------------------------------  // acclient.c:666360
char __thiscall PerfMonCounterInfo::AddLanguageNameAndHelp(PerfMonCounterInfo *this, const unsigned __int16 language, PStringBase<unsigned short> *name, PStringBase<unsigned short> *help)
{
  PerfMonCounterInfo *v4; // esi@1
  PSRefBufferCharData<unsigned short> *v5; // ebx@1
  volatile LONG *v6; // ST00_4@1
  PSRefBufferCharData<unsigned short> *v7; // ebp@1
  volatile LONG *v8; // ST00_4@1
  ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *v9; // eax@1
  char v10; // al@4
  PerfMonCounterInfo::PerfMonCounterNameHelp nameInfo; // [sp+10h] [bp-Ch]@1
  char languagea; // [sp+20h] [bp+4h]@4

  v4 = this;
  v5 = name->m_charbuffer;
  v6 = (volatile LONG *)&name->m_charbuffer[-1].m_data[8];
  nameInfo.m_languageID = language;
  nameInfo.m_name.m_charbuffer = v5;
  InterlockedIncrement(v6);
  v7 = help->m_charbuffer;
  v8 = (volatile LONG *)&help->m_charbuffer[-1].m_data[8];
  nameInfo.m_help.m_charbuffer = help->m_charbuffer;
  InterlockedIncrement(v8);
  v9 = v4->m_CounterNamesList._head;
  if ( v9 )
  {
    while ( v9->data.m_languageID != language )
    {
      v9 = v9->next;
      if ( !v9 )
        goto LABEL_4;
    }
    languagea = 0;
  }
  else
  {
LABEL_4:
    v10 = List<PerfMonCounterInfo::PerfMonCounterNameHelp>::insert_sort(&v4->m_CounterNamesList, &nameInfo);
    v5 = nameInfo.m_name.m_charbuffer;
    v7 = nameInfo.m_help.m_charbuffer;
    languagea = v10;
  }
  if ( !InterlockedDecrement((volatile LONG *)&v7[-1].m_data[8]) && v7 != (PSRefBufferCharData<unsigned short> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&v7[-1].m_data[6])(&v7[-1].m_data[6], 1);
  if ( !InterlockedDecrement((volatile LONG *)&v5[-1].m_data[8]) && v5 != (PSRefBufferCharData<unsigned short> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&v5[-1].m_data[6])(&v5[-1].m_data[6], 1);
  return languagea;
}

//----- (00682E60) --------------------------------------------------------  // acclient.c:666409
void __thiscall PerfMonCounterInfo::PerfMonCounterInfo(PerfMonCounterInfo *this, PerfMonCounterInfo::EPerfCounterType counterType, PStringBase<unsigned short> *name, PStringBase<unsigned short> *help, const unsigned __int16 language)
{
  PerfMonCounterInfo *v5; // esi@1

  v5 = this;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&PerfMonCounterInfo::vftable;
  this->m_CounterType = 65792;
  this->m_CounterNamesList.vfptr = (List<PerfMonCounterInfo::PerfMonCounterNameHelp>Vtbl *)List<PerfMonCounterInfo::PerfMonCounterNameHelp>::vftable;
  this->m_CounterNamesList._head = 0;
  this->m_CounterNamesList._tail = 0;
  this->m_CounterNamesList._num_elements = 0;
  this->m_fCounterExistedPreviously = 0;
  PerfMonCounterInfo::AddLanguageNameAndHelp(this, language, name, help);
  if ( counterType )
  {
    if ( counterType == 1 )
    {
      v5->m_CounterType = 256;
    }
    else if ( counterType == 2 )
    {
      v5->m_CounterType = 272696576;
    }
  }
  else
  {
    v5->m_CounterType = 65792;
  }
  if ( *(_DWORD *)&name->m_charbuffer[-1].m_data[14] != 1 )
  {
    if ( PerfMonCounterManager::Sm_pPerfMonCounterManager )
      PerfMonCounterManager::AddCounter(PerfMonCounterManager::Sm_pPerfMonCounterManager, v5);
  }
}
// 7C9E90: using guessed type int (__thiscall *List<PerfMonCounterInfo::PerfMonCounterNameHelp>::vftable[2])(void *, char);
// 7FEBF0: using guessed type int (__thiscall *PerfMonCounterInfo::vftable)(void *, char);

//----- (00682EF0) --------------------------------------------------------  // acclient.c:666448
PerfMonCounterInfo *__thiscall PerfMonCounterInfo::vector_deleting_destructor(PerfMonCounterInfo *this, unsigned int a2)
{
  PerfMonCounterInfo *v2; // esi@1

  v2 = this;
  List<PerfMonCounterInfo::PerfMonCounterNameHelp>::~List<PerfMonCounterInfo::PerfMonCounterNameHelp>(&this->m_CounterNamesList);
  v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);

//----- (007154F0) --------------------------------------------------------  // acclient.c:808289
int sub_7154F0()
{
  return atexit(nullsub_213);
}

//----- (00715500) --------------------------------------------------------  // acclient.c:808295
int _E4_33()
{
  return atexit(_E5_33);
}

//----- (00715510) --------------------------------------------------------  // acclient.c:808301
int _E7_33()
{
  Outside_CellID_33.id = Invalid_CellID_33.id + 1;
  return atexit(_E8_33);
}

//----- (00715530) --------------------------------------------------------  // acclient.c:808308
int _E10_32()
{
  In_Limbo_CellID_32.id = Outside_CellID_33.id + 1;
  return atexit(_E11_32);
}

//----- (00715550) --------------------------------------------------------  // acclient.c:808315
int _E13_32()
{
  First_Interior_CellID_32.id = In_Limbo_CellID_32.id + 1;
  return atexit(_E14_32);
}

//----- (00715570) --------------------------------------------------------  // acclient.c:808322
int _E16_32()
{
  Last_Interior_CellID_32.id = Invalid_CellID_33.id - 1;
  return atexit(_E17_32);
}

//----- (00715590) --------------------------------------------------------  // acclient.c:808329
int _E21_35()
{
  return atexit(_E22_35);
}

//----- (007155A0) --------------------------------------------------------  // acclient.c:808335
int _E40_34()
{
  return atexit(_E41_34);
}

//----- (007155B0) --------------------------------------------------------  // acclient.c:808341
int _E43_37()
{
  return atexit(_E44_37);
}

