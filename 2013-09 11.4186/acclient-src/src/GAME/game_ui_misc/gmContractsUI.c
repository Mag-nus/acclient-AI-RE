/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmContractsUI
   Object     : GAME\game_ui_misc\gmContractsUI.obj
   Functions  : 81
   Addresses  : 004979A0 - 0075FD10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004979A0) --------------------------------------------------------  // acclient.c:209467
int __cdecl LandDefs::inbound_valid_cellid(unsigned int cell_id)
{
  unsigned int v1; // ecx@6
  unsigned int v2; // eax@6
  int result; // eax@10

  result = 0;
  if ( (unsigned __int16)cell_id >= 1u && (unsigned __int16)cell_id <= 0x40u
    || (unsigned __int16)cell_id >= 0x100u && (unsigned __int16)cell_id <= 0xFFFDu
    || (unsigned __int16)cell_id == 0xFFFF )
  {
    v1 = (cell_id >> 21) & 0x7F8;
    v2 = (cell_id >> 13) & 0x7F8;
    if ( (v1 & 0x80000000) == 0 && (v2 & 0x80000000) == 0 && (signed int)v1 < 2040 && (signed int)v2 < 2040 )
      result = 1;
  }
  return result;
}

//----- (00497A10) --------------------------------------------------------  // acclient.c:209487
char __thiscall gmContractsUI::CheckForDoubleClick(gmContractsUI *this, const int selected_index)
{
  char result; // al@3

  if ( selected_index == this->m_LastClickIndex && COERCE_DOUBLE(Timer::cur_time.Cmd) <= this->m_LastClickTime + 1.0 )
  {
    result = 1;
    *(_QWORD *)&this->m_LastClickTime = 0i64;
    this->m_LastClickIndex = -1;
  }
  else
  {
    this->m_LastClickTime = *(double *)&Timer::cur_time;
    this->m_LastClickIndex = selected_index;
    result = 0;
  }
  return result;
}

//----- (00497A70) --------------------------------------------------------  // acclient.c:209507
PackableHashIterator<unsigned long,CContractTracker> *__thiscall PackableHashIterator<unsigned long,CContractTracker>::scalar_deleting_destructor(PackableHashIterator<unsigned long,CContractTracker> *this, unsigned int a2)
{
  PackableHashIterator<unsigned long,CContractTracker> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackableHashIterator<unsigned long,CContractTracker>Vtbl *)PackableHashIterator<unsigned long,CContractTracker>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7A692C: using guessed type int (__thiscall *PackableHashIterator<unsigned long,CContractTracker>::vftable[2])(void *, char);

//----- (00497A90) --------------------------------------------------------  // acclient.c:209520
int __cdecl LandDefs::gid_to_lcoord(unsigned int cell_id, int *x, int *y)
{
  int v3; // edi@3
  int result; // eax@7

  result = 0;
  if ( LandDefs::inbound_valid_cellid(cell_id) )
  {
    if ( (unsigned __int16)cell_id < 0x100u )
    {
      *x = (cell_id >> 21) & 0x7F8;
      *y = 8 * BYTE2(cell_id);
      *x += ((unsigned int)(unsigned __int16)cell_id - 1) >> 3;
      v3 = (((_BYTE)cell_id - 1) & 7) + *y;
      *y = v3;
      if ( *x >= 0 && v3 >= 0 && *x < 2040 && v3 < 2040 )
        result = 1;
    }
  }
  return result;
}

//----- (00497B10) --------------------------------------------------------  // acclient.c:209543
void __thiscall ContractInfo::~ContractInfo(ContractInfo *this)
{
  ContractInfo *v1; // edi@1
  char *v2; // esi@1
  int v3; // esi@4

  v1 = this;
  v2 = (char *)&this->m_Status.m_charbuffer[-1].m_data[6];
  this->m_ContractTracker.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->m_Name.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00497B60) --------------------------------------------------------  // acclient.c:209564
void __thiscall ContractInfo::ContractInfo(ContractInfo *this)
{
  ContractInfo *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1
  wchar_t *v4; // eax@1
  int v5; // ebx@2
  volatile LONG *v6; // ST00_4@5
  wchar_t *v7; // eax@6
  int v8; // ebx@7
  volatile LONG *v9; // ST00_4@10

  v1 = this;
  v2 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  this->m_Name.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->m_Status.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v3);
  CContractTracker::CContractTracker(&v1->m_ContractTracker);
  v4 = v1->m_Name.m_charbuffer->m_data;
  if ( (wchar_t *)v1->m_Name.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
  {
    v5 = (int)(v4 - 10);
    if ( !InterlockedDecrement((volatile LONG *)v4 - 4) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    v1->m_Name.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v6);
  }
  v7 = v1->m_Status.m_charbuffer->m_data;
  if ( v7 != PStringBase<unsigned short>::s_NullBuffer )
  {
    v8 = (int)(v7 - 10);
    if ( !InterlockedDecrement((volatile LONG *)v7 - 4) )
    {
      if ( v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    }
    v9 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    v1->m_Status.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v9);
  }
}

//----- (00497C10) --------------------------------------------------------  // acclient.c:209610
PackableHashIterator<unsigned long,CContractTracker> *__thiscall PackableHashTable<unsigned long,CContractTracker>::begin(PackableHashTable<unsigned long,CContractTracker> *this, PackableHashIterator<unsigned long,CContractTracker> *result)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  PackableHashData<unsigned long,CContractTracker> **v4; // edi@2
  PackableHashData<unsigned long,CContractTracker> **v5; // esi@2
  PackableHashData<unsigned long,CContractTracker> **v6; // ecx@5
  PackableHashIterator<unsigned long,CContractTracker> *v7; // eax@5
  PackableHashData<unsigned long,CContractTracker> *v8; // ecx@6

  v2 = this->_table_size;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->_buckets;
    v5 = this->_buckets;
    while ( !*v5 )
    {
      ++v3;
      ++v5;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
    v8 = v4[v3];
    v7 = result;
    result->_buckets = v4;
    result->_current = v8;
    result->vfptr = (PackableHashIterator<unsigned long,CContractTracker>Vtbl *)PackableHashIterator<unsigned long,CContractTracker>::vftable;
    result->_table_size = v2;
  }
  else
  {
LABEL_5:
    v6 = this->_buckets;
    v7 = result;
    result->_current = 0;
    result->_buckets = v6;
    result->vfptr = (PackableHashIterator<unsigned long,CContractTracker>Vtbl *)PackableHashIterator<unsigned long,CContractTracker>::vftable;
    result->_table_size = v2;
  }
  return v7;
}
// 7A692C: using guessed type int (__thiscall *PackableHashIterator<unsigned long,CContractTracker>::vftable[2])(void *, char);

//----- (00497C70) --------------------------------------------------------  // acclient.c:209655
void __thiscall PackableHashIterator<unsigned long,CContractTracker>::GetNext(PackableHashIterator<unsigned long,CContractTracker> *this)
{
  PackableHashData<unsigned long,CContractTracker> *v1; // eax@1
  PackableHashData<unsigned long,CContractTracker> *v2; // edx@1
  unsigned int v3; // eax@3
  PackableHashData<unsigned long,CContractTracker> **v4; // esi@4
  int v5; // edx@4

  v1 = this->_current;
  v2 = v1->_next;
  if ( v2 )
  {
    this->_current = v2;
  }
  else
  {
    v3 = v1->_hashVal + 1;
    if ( v3 >= this->_table_size )
    {
LABEL_7:
      this->_current = 0;
    }
    else
    {
      v4 = this->_buckets;
      v5 = (int)&v4[v3];
      while ( !*(_DWORD *)v5 )
      {
        ++v3;
        v5 += 4;
        if ( v3 >= this->_table_size )
          goto LABEL_7;
      }
      this->_current = v4[v3];
    }
  }
}

//----- (00497CC0) --------------------------------------------------------  // acclient.c:209694
CContract *__thiscall CContractTable::GetContract(CContractTable *this, const unsigned int key)
{
  unsigned int v2; // esi@1
  PackableHashData<unsigned long,CContract> **v3; // ecx@2
  PackableHashData<unsigned long,CContract> *v4; // edx@3
  CContract *result; // eax@6

  v2 = this->_contractHash._table_size;
  if ( v2 && (v3 = this->_contractHash._buckets) != 0 && (v4 = v3[key % v2]) != 0 )
  {
    while ( key != v4->_key )
    {
      v4 = v4->_next;
      if ( !v4 )
        goto LABEL_6;
    }
    result = &v4->_data;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (00497D00) --------------------------------------------------------  // acclient.c:209721
void __thiscall ContractInfo::ContractInfo(ContractInfo *this, ContractInfo *rhs)
{
  ContractInfo *v2; // esi@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1
  PSRefBufferCharData<unsigned short> *v5; // eax@1
  int v6; // ebp@2
  PSRefBufferCharData<unsigned short> *v7; // eax@5
  PSRefBufferCharData<unsigned short> *v8; // eax@6
  int v9; // ebp@7
  PSRefBufferCharData<unsigned short> *v10; // eax@10

  v2 = this;
  v3 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  this->m_Name.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v2->m_Status.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v4);
  CContractTracker::CContractTracker(&v2->m_ContractTracker);
  v5 = v2->m_Name.m_charbuffer;
  if ( v2->m_Name.m_charbuffer != rhs->m_Name.m_charbuffer )
  {
    v6 = (int)&v5[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v5[-1].m_data[8]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = rhs->m_Name.m_charbuffer;
    v2->m_Name.m_charbuffer = rhs->m_Name.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v7[-1].m_data[8]);
  }
  v8 = v2->m_Status.m_charbuffer;
  if ( v8 != rhs->m_Status.m_charbuffer )
  {
    v9 = (int)&v8[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v8[-1].m_data[8]) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v10 = rhs->m_Status.m_charbuffer;
    v2->m_Status.m_charbuffer = v10;
    InterlockedIncrement((volatile LONG *)&v10[-1].m_data[8]);
  }
  CContractTracker::operator=((int)&v2->m_ContractTracker, (int)&rhs->m_ContractTracker);
}

//----- (00497DB0) --------------------------------------------------------  // acclient.c:209765
void *__thiscall ContractInfo::operator=(void *this, int a2)
{
  void *v2; // esi@1
  int v3; // eax@1
  int v4; // ebx@2
  int v5; // eax@5
  int v6; // eax@6
  int v7; // ebx@7
  int v8; // eax@10

  v2 = this;
  v3 = *(_DWORD *)this;
  if ( *(_DWORD *)this != *(_DWORD *)a2 )
  {
    v4 = v3 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(_DWORD *)a2;
    *(_DWORD *)v2 = *(_DWORD *)a2;
    InterlockedIncrement((volatile LONG *)(v5 - 16));
  }
  v6 = *((_DWORD *)v2 + 1);
  if ( v6 != *(_DWORD *)(a2 + 4) )
  {
    v7 = v6 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v6 - 20 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    v8 = *(_DWORD *)(a2 + 4);
    *((_DWORD *)v2 + 1) = v8;
    InterlockedIncrement((volatile LONG *)(v8 - 16));
  }
  CContractTracker::operator=((int)((char *)v2 + 8), a2 + 8);
  return v2;
}

//----- (00497E40) --------------------------------------------------------  // acclient.c:209801
void __thiscall gmContractsUI::PostInit(gmContractsUI *this)
{
  gmContractsUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // eax@7
  int v7; // eax@8
  UIElement *v8; // eax@10
  int v9; // eax@11
  UIElement *v10; // eax@13
  int v11; // eax@14
  UIElement *v12; // eax@16
  int v13; // eax@17
  UIElement *v14; // eax@19
  int v15; // eax@20
  GlobalEventHandler *v16; // eax@22
  GlobalEventHandler *v17; // edi@22

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005CFu);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)5);
  else
    v3 = 0;
  v1->m_pContractsBox = (UIElement_ListBox *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005DFu);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)12);
  else
    v5 = 0;
  v1->m_pProgressText = (UIElement_Text *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005E0u);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)12);
  else
    v7 = 0;
  v1->m_pContactText = (UIElement_Text *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005E2u);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12);
  else
    v9 = 0;
  v1->m_pAreaText = (UIElement_Text *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005E1u);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)12);
  else
    v11 = 0;
  v1->m_pContactLocText = (UIElement_Text *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005E3u);
  if ( v12 )
    v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)12);
  else
    v13 = 0;
  v1->m_pTimedText = (UIElement_Text *)v13;
  v14 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005DEu);
  if ( v14 )
    v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)12);
  else
    v15 = 0;
  v1->m_pNotesText = (UIElement_Text *)v15;
  v16 = GlobalEventHandler::GetGlobalEventHandler();
  v17 = v16;
  if ( v16 )
  {
    v16->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v16, 5100161u, (NoticeHandler *)&v1->vfptr);
    v17->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v17, 5100162u, (NoticeHandler *)&v1->vfptr);
  }
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
}

//----- (00497FF0) --------------------------------------------------------  // acclient.c:209913
int __thiscall PackableHashTable<unsigned long,CContractTracker>::add(PackableHashTable<unsigned long,CContractTracker> *this, const unsigned int *key, CContractTracker *data)
{
  PackableHashTable<unsigned long,CContractTracker> *v3; // edi@1
  unsigned int v4; // esi@1
  PackableHashData<unsigned long,CContractTracker> **v5; // ebx@2
  PackableHashData<unsigned long,CContractTracker> *v6; // edx@3
  void *v7; // esi@8
  unsigned int v8; // ebx@9
  const unsigned int v9; // edx@9

  v3 = this;
  v4 = this->_table_size;
  if ( !v4 )
    goto LABEL_8;
  v5 = this->_buckets;
  if ( !v5 )
    goto LABEL_8;
  v6 = v5[*key % v4];
  if ( !v6 )
    goto LABEL_8;
  while ( *key != v6->_key )
  {
    v6 = v6->_next;
    if ( !v6 )
      goto LABEL_8;
  }
  if ( v6 == (PackableHashData<unsigned long,CContractTracker> *)-8 )
  {
LABEL_8:
    v7 = operator new(0x38u);
    if ( v7 )
    {
      v8 = v3->_table_size;
      *(_DWORD *)v7 = *key;
      CContractTracker::CContractTracker((CContractTracker *)((char *)v7 + 8), data);
      *((_DWORD *)v7 + 12) = 0;
      v9 = *key % v8;
      *((_DWORD *)v7 + 13) = v9;
      *((_DWORD *)v7 + 12) = v3->_buckets[v9];
      v3->_buckets[v9] = (PackableHashData<unsigned long,CContractTracker> *)v7;
      ++v3->_currNum;
      return 1;
    }
  }
  return 0;
}

//----- (00498090) --------------------------------------------------------  // acclient.c:209961
ContractInfo *__cdecl _STL::__uninitialized_copy(ContractInfo *__first, ContractInfo *__last, ContractInfo *__result)
{
  ContractInfo *v3; // esi@1
  ContractInfo *i; // edi@1

  v3 = __first;
  for ( i = __result; v3 != __last; ++i )
  {
    if ( i )
      ContractInfo::ContractInfo(i, v3);
    ++v3;
  }
  return i;
}

//----- (004980C0) --------------------------------------------------------  // acclient.c:209977
ContractInfo *__cdecl _STL::__copy_backward(ContractInfo *__first, ContractInfo *__last, ContractInfo *__result)
{
  int v3; // esi@1
  ContractInfo *v4; // edi@2
  signed int v5; // ebx@2
  ContractInfo *result; // eax@4

  v3 = (int)__last;
  if ( __last - __first <= 0 )
  {
    result = __result;
  }
  else
  {
    v4 = __result;
    v5 = __last - __first;
    do
    {
      v3 -= 48;
      --v4;
      ContractInfo::operator=(v4, v3);
      --v5;
    }
    while ( v5 );
    result = v4;
  }
  return result;
}

//----- (00498110) --------------------------------------------------------  // acclient.c:210007
ContractInfo *__cdecl _STL::__copy(ContractInfo *__first, ContractInfo *__last, ContractInfo *__result)
{
  int v3; // esi@1
  ContractInfo *v4; // edi@2
  signed int v5; // ebx@2
  ContractInfo *result; // eax@4

  v3 = (int)__first;
  if ( __last - __first <= 0 )
  {
    result = __result;
  }
  else
  {
    v4 = __result;
    v5 = __last - __first;
    do
    {
      ContractInfo::operator=(v4, v3);
      v3 += 48;
      ++v4;
      --v5;
    }
    while ( v5 );
    result = v4;
  }
  return result;
}

//----- (00498160) --------------------------------------------------------  // acclient.c:210037
void __cdecl _STL::swap(ContractInfo *__a, ContractInfo *__b)
{
  char *v2; // esi@1
  char *v3; // esi@4
  ContractInfo __tmp; // [sp+8h] [bp-30h]@1

  ContractInfo::ContractInfo(&__tmp, __a);
  ContractInfo::operator=(__a, (int)__b);
  ContractInfo::operator=(__b, (int)&__tmp);
  v2 = (char *)&__tmp.m_Status.m_charbuffer[-1].m_data[6];
  __tmp.m_ContractTracker.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&__tmp.m_Status.m_charbuffer[-1].m_data[8]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (char *)&__tmp.m_Name.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&__tmp.m_Name.m_charbuffer[-1].m_data[8]) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004981E0) --------------------------------------------------------  // acclient.c:210060
void __cdecl _STL::__unguarded_linear_insert(ContractInfo *__last, ContractInfo __val, bool (__cdecl *__comp)(ContractInfo *, ContractInfo *))
{
  bool (__cdecl *v3)(ContractInfo *, ContractInfo *); // ebx@1
  ContractInfo *v4; // edi@1
  int i; // esi@1
  char *v6; // esi@3
  char *v7; // esi@6

  v3 = __comp;
  v4 = __last;
  for ( i = (int)&__last[-1]; v3(&__val, (ContractInfo *)i); i -= 48 )
  {
    ContractInfo::operator=(v4, i);
    v4 = (ContractInfo *)i;
  }
  ContractInfo::operator=(v4, (int)&__val);
  v6 = (char *)&__val.m_Status.m_charbuffer[-1].m_data[6];
  __val.m_ContractTracker.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&__val.m_Status.m_charbuffer[-1].m_data[8]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v7 = (char *)&__val.m_Name.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&__val.m_Name.m_charbuffer[-1].m_data[8]) )
  {
    if ( v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00498280) --------------------------------------------------------  // acclient.c:210090
void __cdecl _STL::__push_heap(ContractInfo *__first, int __holeIndex, int __topIndex, ContractInfo __val, bool (__cdecl *__comp)(ContractInfo *, ContractInfo *))
{
  int v5; // esi@1
  int i; // edi@1
  char *v7; // esi@4
  char *v8; // esi@7

  v5 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v5 > __topIndex; i = (i - 1) / 2 )
  {
    if ( !__comp(&__first[i], &__val) )
      break;
    ContractInfo::operator=(&__first[v5], (int)&__first[i]);
    v5 = i;
  }
  ContractInfo::operator=(&__first[v5], (int)&__val);
  v7 = (char *)&__val.m_Status.m_charbuffer[-1].m_data[6];
  __val.m_ContractTracker.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&__val.m_Status.m_charbuffer[-1].m_data[8]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  v8 = (char *)&__val.m_Name.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&__val.m_Name.m_charbuffer[-1].m_data[8]) )
  {
    if ( v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00498340) --------------------------------------------------------  // acclient.c:210120
void __thiscall PackableHashTable<unsigned long,CContractTracker>::~PackableHashTable<unsigned long,CContractTracker>(PackableHashTable<unsigned long,CContractTracker> *this)
{
  PackableHashTable<unsigned long,CContractTracker> *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,CContractTracker>::vftable;
  PackableHashTable<unsigned long,CContractTracker>::EmptyContents((PackableHashTable<unsigned long,GeneratorRegistryNode> *)this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A6930: using guessed type int (__thiscall *PackableHashTable<unsigned long,CContractTracker>::vftable)(void *, char);

//----- (00498410) --------------------------------------------------------  // acclient.c:210190
int __thiscall PackableHashTable<unsigned long,CContractTracker>::UnPack(PackableHashTable<unsigned long,CContractTracker> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<unsigned long,CContractTracker> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  int v10; // ebx@5
  unsigned int v11; // ebp@5
  void *v12; // eax@13
  PackObjVtbl *v13; // edx@13
  void *start_addr; // [sp+8h] [bp-30h]@3
  unsigned int blob_size; // [sp+Ch] [bp-2Ch]@3
  CContractTracker tempData; // [sp+10h] [bp-28h]@11

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,CContractTracker>::EmptyContents((PackableHashTable<unsigned long,GeneratorRegistryNode> *)this);
  if ( v4->_buckets )
  {
    operator delete[](v4->_buckets);
    v4->_buckets = 0;
  }
  v4->_table_size = 0;
  v7 = *(_DWORD *)*v6;
  *v6 = (char *)*v6 + 4;
  v8 = v7 >> 16;
  v9 = (unsigned __int16)v7;
  v10 = v3 - 4;
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 > 0x10000
    || v9 > 0x10000
    || !PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
    return 0;
  CContractTracker::CContractTracker(&tempData);
  size = 0;
  if ( v11 )
  {
    while ( (unsigned int)v10 >= 4 )
    {
      v12 = *v6;
      v13 = tempData.vfptr;
      addr = *(void ***)*v6;
      *v6 = (char *)v12 + 4;
      if ( !((int (__thiscall *)(CContractTracker *, void **, int))v13->UnPack)(&tempData, v6, v10)
        || !PackableHashTable<unsigned long,CContractTracker>::add(v4, (const unsigned int *)&addr, &tempData)
        && !v4->m_fThrowawayDuplicateKeysOnUnPack )
        break;
      ++size;
      if ( size >= v11 )
        return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
    }
    return 0;
  }
  return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
}

//----- (00498530) --------------------------------------------------------  // acclient.c:210257
PackableHashTable<unsigned long,CContractTracker> *__thiscall PackableHashTable<unsigned long,CContractTracker>::scalar_deleting_destructor(PackableHashTable<unsigned long,CContractTracker> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,CContractTracker> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,CContractTracker>::vftable;
  PackableHashTable<unsigned long,CContractTracker>::EmptyContents((PackableHashTable<unsigned long,GeneratorRegistryNode> *)this);
  if ( v2->_buckets )
  {
    operator delete[](v2->_buckets);
    v2->_buckets = 0;
  }
  v2->_table_size = 0;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A6930: using guessed type int (__thiscall *PackableHashTable<unsigned long,CContractTracker>::vftable)(void *, char);

//----- (00498580) --------------------------------------------------------  // acclient.c:210279
PackableHashTable<unsigned long,CContractTracker> *__thiscall PackableHashTable<unsigned long,CContractTracker>::operator=(PackableHashTable<unsigned long,CContractTracker> *this, int a2)
{
  PackableHashTable<unsigned long,CContractTracker> *v2; // edi@1
  unsigned int v3; // ebx@2
  int v4; // eax@5
  int v5; // esi@6

  v2 = this;
  if ( this != (PackableHashTable<unsigned long,CContractTracker> *)a2 )
  {
    PackableHashTable<unsigned long,CContractTracker>::EmptyContents((PackableHashTable<unsigned long,GeneratorRegistryNode> *)this);
    v3 = 0;
    if ( v2->_buckets )
    {
      operator delete[](v2->_buckets);
      v2->_buckets = 0;
    }
    v2->_table_size = 0;
    v2->_table_size = *(_DWORD *)(a2 + 12);
    PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
    if ( *(_DWORD *)(a2 + 12) > 0u )
    {
      do
      {
        v4 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4 * v3);
        if ( v4 )
        {
          do
          {
            v5 = *(_DWORD *)(v4 + 48);
            PackableHashTable<unsigned long,CContractTracker>::add(
              v2,
              (const unsigned int *)v4,
              (CContractTracker *)(v4 + 8));
            v4 = v5;
          }
          while ( v5 );
        }
        ++v3;
      }
      while ( v3 < *(_DWORD *)(a2 + 12) );
    }
  }
  return v2;
}

//----- (00498600) --------------------------------------------------------  // acclient.c:210326
void __cdecl _STL::__destroy_aux(ContractInfo *__first, ContractInfo *__last)
{
  ContractInfo *i; // edi@1
  int v3; // esi@2
  int v4; // esi@5

  for ( i = __first; i != __last; ++i )
  {
    v3 = (int)&i->m_Status.m_charbuffer[-1].m_data[6];
    i->m_ContractTracker.vfptr = (PackObjVtbl *)&PackObj::vftable;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = (int)&i->m_Name.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00498670) --------------------------------------------------------  // acclient.c:210349
void __cdecl _STL::__unguarded_insertion_sort_aux(ContractInfo *__first, ContractInfo *__last, ContractInfo *__formal, bool (__cdecl *__comp)(ContractInfo *, ContractInfo *))
{
  ContractInfo *i; // esi@1
  ContractInfo v5; // [sp-34h] [bp-40h]@2
  bool (__cdecl *v6)(ContractInfo *, ContractInfo *); // [sp-4h] [bp-10h]@2

  for ( i = __first; i != __last; ++i )
  {
    v6 = __comp;
    ContractInfo::ContractInfo(&v5, i);
    _STL::__unguarded_linear_insert(i, v5, v6);
  }
}

//----- (004986B0) --------------------------------------------------------  // acclient.c:210364
void __cdecl _STL::__adjust_heap(ContractInfo *__first, int __holeIndex, int __len, ContractInfo __val, bool (__cdecl *__comp)(ContractInfo *, ContractInfo *))
{
  int v5; // edi@1
  int v6; // esi@1
  bool i; // zf@1
  char *v8; // esi@7
  int v9; // eax@9
  char *v10; // esi@10
  int v11; // edx@12
  ContractInfo v12; // [sp-34h] [bp-44h]@7
  bool (__cdecl *v13)(ContractInfo *, ContractInfo *); // [sp-4h] [bp-14h]@7

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  for ( i = v6 == __len; v6 < __len; i = v6 == __len )
  {
    if ( __comp(&__first[v6], &__first[v6 - 1]) )
      --v6;
    ContractInfo::operator=(&__first[v5], (int)&__first[v6]);
    v5 = v6;
    v6 = 2 * v6 + 2;
  }
  if ( i )
  {
    ContractInfo::operator=(&__first[v5], (int)&__first[v6 - 1]);
    v5 = v6 - 1;
  }
  v13 = __comp;
  ContractInfo::ContractInfo(&v12, &__val);
  _STL::__push_heap(__first, v5, __holeIndex, v12, v13);
  v8 = (char *)&__val.m_Status.m_charbuffer[-1].m_data[6];
  __val.m_ContractTracker.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&__val.m_Status.m_charbuffer[-1].m_data[8]) && v8 )
  {
    v9 = *(_DWORD *)v8;
    v13 = (bool (__cdecl *)(ContractInfo *, ContractInfo *))1;
    (*(void (__thiscall **)(char *, signed int))v9)(v8, 1);
  }
  v10 = (char *)&__val.m_Name.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&__val.m_Name.m_charbuffer[-1].m_data[8]) )
  {
    if ( v10 )
    {
      v11 = *(_DWORD *)v10;
      v13 = (bool (__cdecl *)(ContractInfo *, ContractInfo *))1;
      (*(void (__thiscall **)(char *, signed int))v11)(v10, 1);
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004987A0) --------------------------------------------------------  // acclient.c:210416
bool __cdecl ContractInfoSortStatus(ContractInfo *p1, ContractInfo *p2)
{
  int v2; // ecx@3
  ContractInfo *v3; // esi@5
  int v4; // eax@7
  PSRefBufferCharData<unsigned short> *v6; // eax@22
  PSRefBufferCharData<unsigned short> *v7; // ecx@22
  int v8; // edx@23
  int v9; // esi@23
  bool v10; // al@27
  char *v11; // esi@27
  bool v12; // bl@27
  LONG v13; // eax@27
  char *v14; // esi@33
  PStringBase<unsigned short> buffer_string2; // [sp+8h] [bp-8h]@12
  PStringBase<unsigned short> buffer_string1; // [sp+Ch] [bp-4h]@12

  v2 = p1->m_ContractTracker._contract_stage == 3 && p1->m_ContractTracker._time_of_server_update > 0.0;
  v3 = p2;
  v4 = p2->m_ContractTracker._contract_stage == 3 && p2->m_ContractTracker._time_of_server_update > 0.0;
  if ( v2 && v4 )
    return p2->m_ContractTracker._time_when_repeats
         - (COERCE_DOUBLE(Timer::cur_time.Cmd)
          - p2->m_ContractTracker._time_of_server_update) > p1->m_ContractTracker._time_when_repeats
                                                          - (COERCE_DOUBLE(Timer::cur_time.Cmd)
                                                           - p1->m_ContractTracker._time_of_server_update);
  buffer_string1.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  buffer_string2.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( buffer_string1.m_charbuffer != p1->m_Status.m_charbuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8])
      && buffer_string1.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&buffer_string1.m_charbuffer[-1].m_data[6])(
        &buffer_string1.m_charbuffer[-1].m_data[6],
        1);
    buffer_string1.m_charbuffer = p1->m_Status.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8]);
    v3 = p2;
  }
  if ( buffer_string2.m_charbuffer != v3->m_Status.m_charbuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8])
      && buffer_string2.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&buffer_string2.m_charbuffer[-1].m_data[6])(
        &buffer_string2.m_charbuffer[-1].m_data[6],
        1);
    buffer_string2.m_charbuffer = p2->m_Status.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8]);
  }
  PStringBase<unsigned short>::break_reference(&buffer_string1);
  __wcslwr(buffer_string1.m_charbuffer->m_data);
  PStringBase<unsigned short>::break_reference(&buffer_string2);
  __wcslwr(buffer_string2.m_charbuffer->m_data);
  v6 = buffer_string1.m_charbuffer;
  v7 = buffer_string2.m_charbuffer;
  if ( *(_DWORD *)&buffer_string1.m_charbuffer[-1].m_data[14] == *(_DWORD *)&buffer_string2.m_charbuffer[-1].m_data[14] )
  {
    v8 = *(_DWORD *)&buffer_string1.m_charbuffer[-1].m_data[12];
    v9 = *(_DWORD *)&buffer_string2.m_charbuffer[-1].m_data[12];
    if ( v8 == v9 || v8 == -1 || v9 == -1 )
    {
      if ( _wcscmp(buffer_string1.m_charbuffer->m_data, buffer_string2.m_charbuffer->m_data) == 0 )
      {
        v10 = PageInfoSortLabel((PageInfo *)p1, (PageInfo *)p2);
        v11 = (char *)&buffer_string2.m_charbuffer[-1].m_data[6];
        v12 = v10;
        v13 = InterlockedDecrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8]);
        goto LABEL_30;
      }
      v6 = buffer_string1.m_charbuffer;
      v7 = buffer_string2.m_charbuffer;
    }
  }
  v12 = _wcscmp(v6->m_data, v7->m_data) < 0;
  v11 = (char *)&buffer_string2.m_charbuffer[-1].m_data[6];
  v13 = InterlockedDecrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8]);
LABEL_30:
  if ( !v13 && v11 )
    (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
  v14 = (char *)&buffer_string1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8]) )
  {
    if ( v14 )
      (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
  }
  return v12;
}

//----- (004989A0) --------------------------------------------------------  // acclient.c:210507
bool __cdecl ContractInfoReverseSortStatus(ContractInfo *p1, ContractInfo *p2)
{
  int v2; // ecx@3
  ContractInfo *v3; // esi@5
  int v4; // eax@7
  PSRefBufferCharData<unsigned short> *v6; // eax@22
  PSRefBufferCharData<unsigned short> *v7; // ecx@22
  int v8; // edx@23
  int v9; // esi@23
  bool v10; // al@27
  char *v11; // esi@27
  bool v12; // bl@27
  LONG v13; // eax@27
  char *v14; // esi@33
  PStringBase<unsigned short> buffer_string2; // [sp+8h] [bp-8h]@12
  PStringBase<unsigned short> buffer_string1; // [sp+Ch] [bp-4h]@12

  v2 = p1->m_ContractTracker._contract_stage == 3 && p1->m_ContractTracker._time_of_server_update > 0.0;
  v3 = p2;
  v4 = p2->m_ContractTracker._contract_stage == 3 && p2->m_ContractTracker._time_of_server_update > 0.0;
  if ( v2 && v4 )
    return p2->m_ContractTracker._time_when_repeats
         - (COERCE_DOUBLE(Timer::cur_time.Cmd)
          - p2->m_ContractTracker._time_of_server_update) < p1->m_ContractTracker._time_when_repeats
                                                          - (COERCE_DOUBLE(Timer::cur_time.Cmd)
                                                           - p1->m_ContractTracker._time_of_server_update);
  buffer_string1.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  buffer_string2.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( buffer_string1.m_charbuffer != p1->m_Status.m_charbuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8])
      && buffer_string1.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&buffer_string1.m_charbuffer[-1].m_data[6])(
        &buffer_string1.m_charbuffer[-1].m_data[6],
        1);
    buffer_string1.m_charbuffer = p1->m_Status.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8]);
    v3 = p2;
  }
  if ( buffer_string2.m_charbuffer != v3->m_Status.m_charbuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8])
      && buffer_string2.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&buffer_string2.m_charbuffer[-1].m_data[6])(
        &buffer_string2.m_charbuffer[-1].m_data[6],
        1);
    buffer_string2.m_charbuffer = p2->m_Status.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8]);
  }
  PStringBase<unsigned short>::break_reference(&buffer_string1);
  __wcslwr(buffer_string1.m_charbuffer->m_data);
  PStringBase<unsigned short>::break_reference(&buffer_string2);
  __wcslwr(buffer_string2.m_charbuffer->m_data);
  v6 = buffer_string1.m_charbuffer;
  v7 = buffer_string2.m_charbuffer;
  if ( *(_DWORD *)&buffer_string1.m_charbuffer[-1].m_data[14] == *(_DWORD *)&buffer_string2.m_charbuffer[-1].m_data[14] )
  {
    v8 = *(_DWORD *)&buffer_string1.m_charbuffer[-1].m_data[12];
    v9 = *(_DWORD *)&buffer_string2.m_charbuffer[-1].m_data[12];
    if ( v8 == v9 || v8 == -1 || v9 == -1 )
    {
      if ( _wcscmp(buffer_string1.m_charbuffer->m_data, buffer_string2.m_charbuffer->m_data) == 0 )
      {
        v10 = PageInfoReverseSortLabel((PageInfo *)p1, (PageInfo *)p2);
        v11 = (char *)&buffer_string2.m_charbuffer[-1].m_data[6];
        v12 = v10;
        v13 = InterlockedDecrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8]);
        goto LABEL_30;
      }
      v6 = buffer_string1.m_charbuffer;
      v7 = buffer_string2.m_charbuffer;
    }
  }
  v12 = _wcscmp(v6->m_data, v7->m_data) > 0;
  v11 = (char *)&buffer_string2.m_charbuffer[-1].m_data[6];
  v13 = InterlockedDecrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8]);
LABEL_30:
  if ( !v13 && v11 )
    (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
  v14 = (char *)&buffer_string1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8]) )
  {
    if ( v14 )
      (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
  }
  return v12;
}

//----- (00498BA0) --------------------------------------------------------  // acclient.c:210598
ContractInfo *__cdecl _STL::__unguarded_partition(ContractInfo *__first, ContractInfo *__last, ContractInfo __pivot, bool (__cdecl *__comp)(ContractInfo *, ContractInfo *))
{
  bool (__cdecl *v4)(ContractInfo *, ContractInfo *); // ebx@1
  ContractInfo *v5; // esi@1
  ContractInfo *i; // edi@1

  v4 = __comp;
  v5 = __last;
  for ( i = __first; ; ++i )
  {
    for ( ; v4(i, &__pivot); ++i )
      ;
    for ( --v5; v4(&__pivot, v5); --v5 )
      ;
    if ( i >= v5 )
      break;
    _STL::swap(i, v5);
  }
  ContractInfo::~ContractInfo(&__pivot);
  return i;
}

//----- (00498C20) --------------------------------------------------------  // acclient.c:210621
void __cdecl _STL::__pop_heap(ContractInfo *__first, ContractInfo *__last, ContractInfo *__result, ContractInfo __val, bool (__cdecl *__comp)(ContractInfo *, ContractInfo *))
{
  char *v5; // esi@1
  int v6; // edx@3
  char *v7; // esi@4
  int v8; // edx@6
  ContractInfo v9; // [sp-34h] [bp-3Ch]@1
  bool (__cdecl *v10)(ContractInfo *, ContractInfo *); // [sp-4h] [bp-Ch]@1

  ContractInfo::operator=(__result, (int)__first);
  v10 = __comp;
  ContractInfo::ContractInfo(&v9, &__val);
  _STL::__adjust_heap(__first, 0, __last - __first, v9, v10);
  v5 = (char *)&__val.m_Status.m_charbuffer[-1].m_data[6];
  __val.m_ContractTracker.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&__val.m_Status.m_charbuffer[-1].m_data[8]) && v5 )
  {
    v6 = *(_DWORD *)v5;
    v10 = (bool (__cdecl *)(ContractInfo *, ContractInfo *))1;
    (*(void (__thiscall **)(char *, signed int))v6)(v5, 1);
  }
  v7 = (char *)&__val.m_Name.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&__val.m_Name.m_charbuffer[-1].m_data[8]) )
  {
    if ( v7 )
    {
      v8 = *(_DWORD *)v7;
      v10 = (bool (__cdecl *)(ContractInfo *, ContractInfo *))1;
      (*(void (__thiscall **)(char *, signed int))v8)(v7, 1);
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00498CC0) --------------------------------------------------------  // acclient.c:210656
void __cdecl _STL::__make_heap(ContractInfo *__first, ContractInfo *__last, bool (__cdecl *__comp)(ContractInfo *, ContractInfo *))
{
  int v3; // ebx@1
  int v4; // esi@2
  ContractInfo *i; // edi@2
  ContractInfo v6; // [sp-34h] [bp-44h]@3
  bool (__cdecl *v7)(ContractInfo *, ContractInfo *); // [sp-4h] [bp-14h]@3

  v3 = __last - __first;
  if ( v3 >= 2 )
  {
    v4 = (v3 - 2) / 2;
    for ( i = &__first[v4]; ; --i )
    {
      v7 = __comp;
      ContractInfo::ContractInfo(&v6, i);
      _STL::__adjust_heap(__first, v4, v3, v6, v7);
      if ( !v4 )
        break;
      --v4;
    }
  }
}

//----- (00498D30) --------------------------------------------------------  // acclient.c:210681
void __cdecl _STL::__linear_insert(ContractInfo *__first, ContractInfo *__last, ContractInfo __val, bool (__cdecl *__comp)(ContractInfo *, ContractInfo *))
{
  bool (__cdecl *v4)(ContractInfo *, ContractInfo *); // edi@1
  char *v5; // esi@4
  int v6; // edx@6
  char *v7; // esi@7
  int v8; // edx@9
  ContractInfo v9; // [sp-34h] [bp-3Ch]@3
  bool (__cdecl **v10)(ContractInfo *, ContractInfo *); // [sp-8h] [bp-10h]@2
  bool (__cdecl *v11)(ContractInfo *, ContractInfo *); // [sp-4h] [bp-Ch]@3

  v4 = __comp;
  if ( __comp(&__val, __first) )
  {
    v10 = &__comp;
    _STL::__copy_backward(__first, __last, __last + 1);
    ContractInfo::operator=(__first, (int)&__val);
  }
  else
  {
    v11 = v4;
    ContractInfo::ContractInfo(&v9, &__val);
    _STL::__unguarded_linear_insert(__last, v9, v11);
  }
  v5 = (char *)&__val.m_Status.m_charbuffer[-1].m_data[6];
  __val.m_ContractTracker.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&__val.m_Status.m_charbuffer[-1].m_data[8]) && v5 )
  {
    v6 = *(_DWORD *)v5;
    v11 = (bool (__cdecl *)(ContractInfo *, ContractInfo *))1;
    (*(void (__thiscall **)(char *, signed int))v6)(v5, 1);
  }
  v7 = (char *)&__val.m_Name.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&__val.m_Name.m_charbuffer[-1].m_data[8]) )
  {
    if ( v7 )
    {
      v8 = *(_DWORD *)v7;
      v11 = (bool (__cdecl *)(ContractInfo *, ContractInfo *))1;
      (*(void (__thiscall **)(char *, signed int))v8)(v7, 1);
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00498DE0) --------------------------------------------------------  // acclient.c:210727
void __stdcall gmContractsUI::FillProgressString(CContractTracker *contractTracker, CContract *contract, PStringBase<unsigned short> *status_string)
{
  CContractTracker *v4; // esi@1
  unsigned int v5; // eax@1
  PStringBase<unsigned short> *v6; // esi@8
  CContract *v7; // edi@14
  const unsigned __int16 *v8; // eax@16
  double delta; // [sp+10h] [bp-8h]@7

  v4 = contractTracker;
  v5 = contractTracker->_contract_stage;
  switch ( v5 )
  {
    case 1u:
      PStringBase<unsigned short>::sprintf(status_string, L"Available");
      break;
    case 2u:
      PStringBase<unsigned short>::sprintf(status_string, L"In Progress");
      break;
    case 3u:
      if ( contractTracker->_time_when_repeats <= 0.0 )
      {
        if ( contract->_questflag_repeat_time.m_buffer->m_len == 1 )
          PStringBase<unsigned short>::sprintf(status_string, L"Done");
        else
          PStringBase<unsigned short>::sprintf(status_string, L"Available");
      }
      else
      {
        delta = contractTracker->_time_when_repeats
              - (COERCE_DOUBLE(Timer::cur_time.Cmd)
               - contractTracker->_time_of_server_update);
        if ( delta <= 0.0 )
        {
          PStringBase<unsigned short>::sprintf(status_string, L"Available");
        }
        else
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&contract);
          contractTracker = (CContractTracker *)(unsigned __int64)delta;
          ClientUISystem::DeltaTimeToString(
            (double)(signed int)contractTracker,
            (PStringBase<unsigned short> *)&contract);
          v6 = status_string;
          PStringBase<unsigned short>::sprintf(status_string, L"Done (");
          PStringBase<unsigned short>::operator+=(v6, (PStringBase<unsigned short> *)&contract);
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (PStringBase<unsigned short> *)&status_string,
            L" to Repeat)");
          PStringBase<unsigned short>::operator+=(v6, (PStringBase<unsigned short> *)&status_string);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&status_string);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&contract);
        }
      }
      break;
    default:
      if ( v5 >= 4 )
      {
        v7 = contract;
        if ( contract->_description_progress.m_buffer->m_len == 1 )
        {
          PStringBase<unsigned short>::sprintf(status_string, L"In Progress");
        }
        else
        {
          PStringBase<char>::PStringBase<char>((PStringBase<char> *)&contract);
          PStringBase<char>::sprintf(
            (PStringBase<char> *)&contract,
            v7->_description_progress.m_buffer->m_data,
            v4->_contract_stage - 4);
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (PStringBase<unsigned short> *)&contractTracker,
            0,
            (const char *)contract);
          PStringBase<unsigned short>::operator=(status_string, v8);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&contractTracker);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&contract);
        }
      }
      break;
  }
}

//----- (00498FC0) --------------------------------------------------------  // acclient.c:210811
void __cdecl _STL::__insertion_sort(ContractInfo *__first, ContractInfo *__last, bool (__cdecl *__comp)(ContractInfo *, ContractInfo *))
{
  ContractInfo *i; // esi@2
  ContractInfo v4; // [sp-34h] [bp-44h]@3
  bool (__cdecl *v5)(ContractInfo *, ContractInfo *); // [sp-4h] [bp-14h]@3

  if ( __first != __last )
  {
    for ( i = __first + 1; i != __last; ++i )
    {
      v5 = __comp;
      ContractInfo::ContractInfo(&v4, i);
      _STL::__linear_insert(__first, i, v4, v5);
    }
  }
}

//----- (00499010) --------------------------------------------------------  // acclient.c:210829
void __cdecl _STL::sort_heap(ContractInfo *__first, ContractInfo *__last, bool (__cdecl *__comp)(ContractInfo *, ContractInfo *))
{
  ContractInfo *v3; // esi@2
  ContractInfo v4; // [sp-38h] [bp-48h]@3
  bool (__cdecl *v5)(ContractInfo *, ContractInfo *); // [sp-8h] [bp-18h]@3
  int v6; // [sp-4h] [bp-14h]@3

  if ( __last - __first > 1 )
  {
    v3 = __last - 1;
    do
    {
      v6 = 0;
      v5 = __comp;
      ContractInfo::ContractInfo(&v4, v3);
      _STL::__pop_heap(__first, v3, v3, v4, v5);
      --v3;
    }
    while ( (signed int)((char *)v3 + 48 - (_DWORD)__first) / 48 > 1 );
  }
}

//----- (00499080) --------------------------------------------------------  // acclient.c:210852
void __userpurge gmContractsUI::gmContractsUI(gmContractsUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmContractsUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmContractsUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmContractsUI::vftable;
  v4->m_ContractList._M_start = 0;
  v4->m_ContractList._M_finish = 0;
  v4->m_ContractList._M_end_of_storage._M_data = 0;
  v4->m_pContractsBox = 0;
  v4->m_SortCriteria = 0;
  v4->m_ReverseSort = 0;
  LODWORD(v4->m_LastClickTime) = 0;
  HIDWORD(v4->m_LastClickTime) = 0;
  LODWORD(v4->m_timeNextUpdate) = 0;
  HIDWORD(v4->m_timeNextUpdate) = 0;
  v4->m_LastClickIndex = -1;
}
// 7A69A8: using guessed type bool (__thiscall *gmContractsUI::vftable)(DBCache *this);
// 7A6C50: using guessed type int (__thiscall *gmContractsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (00499100) --------------------------------------------------------  // acclient.c:210878
gmContractsUI *__thiscall gmContractsUI::DynamicCast(gmContractsUI *this, unsigned int i_eType)
{
  gmContractsUI *result; // eax@1

  result = this;
  if ( i_eType != 268435531 )
    result = (gmContractsUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (00499120) --------------------------------------------------------  // acclient.c:210889
signed int gmContractsUI::GetUIElementType()
{
  return 268435531;
}

//----- (00499130) --------------------------------------------------------  // acclient.c:210895
void __thiscall gmContractsUI::~gmContractsUI(gmContractsUI *this)
{
  gmContractsUI *v1; // esi@1
  NoticeHandler *v2; // ebx@1
  GlobalEventHandler *v3; // eax@1
  void *v4; // edi@3
  gmContractsUI *v5; // [sp+2h] [bp-4h]@1

  v5 = this;
  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmContractsUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmContractsUI::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  _STL::__destroy_aux(v1->m_ContractList._M_start, v1->m_ContractList._M_finish);
  v4 = v1->m_ContractList._M_start;
  if ( v4 )
    _STL::__node_alloc<1,0>::deallocate(
      v4,
      48 * ((signed int)((char *)v1->m_ContractList._M_end_of_storage._M_data - (char *)v4) / 48));
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7A69A8: using guessed type bool (__thiscall *gmContractsUI::vftable)(DBCache *this);
// 7A6C50: using guessed type int (__thiscall *gmContractsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004991D0) --------------------------------------------------------  // acclient.c:210927
void __usercall gmContractsUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmContractsUI *v3; // eax@1

  v3 = (gmContractsUI *)operator new(0x640u);
  if ( v3 )
    gmContractsUI::gmContractsUI(v3, a1, _layout, _full_desc);
}

//----- (00499200) --------------------------------------------------------  // acclient.c:210937
void __thiscall gmContractsUI::UpdateButtons(gmContractsUI *this)
{
  gmContractsUI *v1; // esi@1
  UIElement_ListBox *v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // edi@1
  UIElement *v5; // edx@2
  UIElement **v6; // eax@2
  int v7; // ebx@7
  int v8; // ebp@8
  CContract *v9; // eax@8
  CContract *v10; // edi@8
  PStringBase<unsigned short> *v11; // eax@10
  int v12; // ebx@10
  AC1Legacy::PSRefBuffer<char> *v13; // ecx@13
  unsigned int v14; // eax@13
  unsigned int v15; // eax@14
  PStringBase<unsigned short> *v16; // eax@17
  unsigned int v17; // eax@17
  PStringBase<unsigned short> *v18; // eax@18
  unsigned __int16 *v19; // ecx@22
  unsigned __int16 *v20; // ebx@26
  unsigned __int16 *v21; // ST20_4@29
  long double time; // ST18_8@29
  unsigned __int64 v23; // st7@29
  unsigned int v24; // eax@32
  unsigned __int16 *v25; // ecx@35
  unsigned __int16 *v26; // ebx@39
  unsigned __int16 *v27; // ST20_4@42
  long double v28; // ST18_8@42
  unsigned __int64 v29; // st7@42
  PStringBase<unsigned short> *v30; // ecx@48
  char *v31; // esi@51
  int x_coord; // [sp+30h] [bp-24h]@13
  PStringBase<unsigned short> sTimeStr; // [sp+34h] [bp-20h]@13
  PStringBase<unsigned short> progress_msg; // [sp+38h] [bp-1Ch]@32
  double strCoords; // [sp+3Ch] [bp-18h]@10
  DBObjGrabber<CContractTable> contractdb; // [sp+48h] [bp-Ch]@7
  long double delta; // [sp+4Ch] [bp-8h]@21

  v1 = this;
  v2 = this->m_pContractsBox;
  v3 = v2->m_listItems.m_num;
  v4 = 0;
  if ( v3 )
  {
    v5 = v2->m_pSelectedItem;
    v6 = v2->m_listItems.m_data;
    while ( *v6 != v5 )
    {
      ++v4;
      ++v6;
      if ( v4 >= v3 )
        return;
    }
    if ( v4 != -1 )
    {
      v7 = DBObj::GetByEnum(23, 2, 0x10000010u);
      contractdb.m_object = (CContractTable *)v7;
      if ( v7 )
      {
        v8 = v4;
        v9 = CContractTable::GetContract(
               (CContractTable *)v7,
               v1->m_ContractList._M_start[v4].m_ContractTracker._contract_id);
        v10 = v9;
        if ( !v9 )
        {
          (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 20))(v7);
          return;
        }
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&strCoords,
          0,
          v9->_description.m_buffer->m_data);
        UIElement_Text::SetText(v1->m_pNotesText, v11);
        v12 = LODWORD(strCoords) - 20;
        if ( !InterlockedDecrement((volatile LONG *)(LODWORD(strCoords) - 20 + 4)) && v12 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
        v13 = v10->_name_npc_end.m_buffer;
        v14 = v13->m_len;
        x_coord = 0;
        sTimeStr.m_charbuffer = 0;
        if ( v14 == 1
          || (v15 = v1->m_ContractList._M_start[v8].m_ContractTracker._contract_stage, v15 != 2)
          && v15 < 4
          && v10->_name_npc_start.m_buffer->m_len != 1 )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (PStringBase<unsigned short> *)&strCoords,
            0,
            v10->_name_npc_start.m_buffer->m_data);
          UIElement_Text::SetText(v1->m_pContactText, v18);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strCoords);
          v17 = v10->_location_npc_start.objcell_id;
        }
        else
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (PStringBase<unsigned short> *)&strCoords,
            0,
            v13->m_data);
          UIElement_Text::SetText(v1->m_pContactText, v16);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strCoords);
          v17 = v10->_location_npc_end.objcell_id;
        }
        if ( v17 )
        {
          if ( LandDefs::gid_to_lcoord(v17, &x_coord, (int *)&sTimeStr) )
          {
            delta = (double)(x_coord - 1024) * 0.1 + 0.5;
            strCoords = (double)COERCE_SIGNED_INT(&sTimeStr.m_charbuffer[-32]) * 0.1 + 0.5;
            if ( delta >= 0.0 )
            {
              v19 = L"E";
              if ( delta <= 0.0 )
                v19 = &word_794320;
            }
            else
            {
              v19 = L"W";
            }
            if ( strCoords >= 0.0 )
            {
              v20 = L"N";
              if ( strCoords <= 0.0 )
                v20 = &word_794320;
            }
            else
            {
              v20 = L"S";
            }
            v21 = v19;
            time = abs(delta);
            *(double *)&v23 = abs(strCoords);
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              (PStringBase<unsigned short> *)&strCoords,
              0,
              L"%.1f%s, %.1f%s",
              v23,
              v23 >> 32,
              v20,
              time,
              v21);
            UIElement_Text::SetText(v1->m_pContactLocText, (PStringBase<unsigned short> *)&strCoords);
          }
          else
          {
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              (PStringBase<unsigned short> *)&strCoords,
              L"Indoors");
            UIElement_Text::SetText(v1->m_pContactLocText, (PStringBase<unsigned short> *)&strCoords);
          }
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strCoords);
        }
        progress_msg.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
        InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
        gmContractsUI::FillProgressString(&v1->m_ContractList._M_start[v8].m_ContractTracker, v10, &progress_msg);
        UIElement_Text::SetText(v1->m_pProgressText, &progress_msg);
        v24 = v10->_location_quest_area.objcell_id;
        if ( v24 )
        {
          if ( LandDefs::gid_to_lcoord(v24, &x_coord, (int *)&sTimeStr) )
          {
            delta = (double)(x_coord - 1024) * 0.1 + 0.5;
            strCoords = (double)COERCE_SIGNED_INT(&sTimeStr.m_charbuffer[-32]) * 0.1 + 0.5;
            if ( delta >= 0.0 )
            {
              v25 = L"E";
              if ( delta <= 0.0 )
                v25 = &word_794320;
            }
            else
            {
              v25 = L"W";
            }
            if ( strCoords >= 0.0 )
            {
              v26 = L"N";
              if ( strCoords <= 0.0 )
                v26 = &word_794320;
            }
            else
            {
              v26 = L"S";
            }
            v27 = v25;
            v28 = abs(delta);
            *(double *)&v29 = abs(strCoords);
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              (PStringBase<unsigned short> *)&strCoords,
              0,
              L"%.1f%s, %.1f%s",
              v29,
              v29 >> 32,
              v26,
              v28,
              v27);
            UIElement_Text::SetText(v1->m_pAreaText, (PStringBase<unsigned short> *)&strCoords);
          }
          else
          {
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              (PStringBase<unsigned short> *)&strCoords,
              L"Indoors");
            UIElement_Text::SetText(v1->m_pAreaText, (PStringBase<unsigned short> *)&strCoords);
          }
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strCoords);
        }
        if ( v10->_questflag_timer.m_buffer->m_len == 1 )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&strCoords, L"None");
          UIElement_Text::SetText(v1->m_pTimedText, (PStringBase<unsigned short> *)&strCoords);
        }
        else
        {
          delta = v1->m_ContractList._M_start[v8].m_ContractTracker._time_when_done
                - (COERCE_DOUBLE(Timer::cur_time.Cmd)
                 - v1->m_ContractList._M_start[v8].m_ContractTracker._time_of_server_update);
          if ( delta > 0.0 )
          {
            PStringBase<unsigned short>::PStringBase<unsigned short>(&sTimeStr);
            LODWORD(strCoords) = (unsigned __int64)delta;
            ClientUISystem::DeltaTimeToString((double)SLODWORD(strCoords), &sTimeStr);
            UIElement_Text::SetText(v1->m_pTimedText, &sTimeStr);
            v30 = &sTimeStr;
LABEL_51:
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)v30);
            v31 = (char *)&progress_msg.m_charbuffer[-1].m_data[6];
            if ( !InterlockedDecrement((volatile LONG *)&progress_msg.m_charbuffer[-1].m_data[8]) )
            {
              if ( v31 )
                (**(void (__thiscall ***)(char *, signed int))v31)(v31, 1);
            }
            ((void (*)(void))contractdb.m_object->vfptr->Release)();
            return;
          }
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (PStringBase<unsigned short> *)&strCoords,
            L"Finished");
          UIElement_Text::SetText(v1->m_pTimedText, (PStringBase<unsigned short> *)&strCoords);
        }
        v30 = (PStringBase<unsigned short> *)&strCoords;
        goto LABEL_51;
      }
    }
  }
}
// 7A659C: using guessed type wchar_t aN_1[2];
// 7A65A0: using guessed type wchar_t aS_9[2];
// 7A65A4: using guessed type wchar_t aE[2];
// 7A65A8: using guessed type wchar_t aW_0[2];

//----- (004996F0) --------------------------------------------------------  // acclient.c:211191
void __thiscall gmContractsUI::AddContractToListbox(gmContractsUI *this, ContractInfo *_info)
{
  gmContractsUI *v2; // ebp@1
  int v3; // eax@1
  ContractInfo *v4; // edi@2
  CContract *v5; // ebx@2
  int v6; // eax@2
  UIElement *v7; // esi@2
  UIElement *v8; // eax@2
  UIElement_Text *v9; // eax@3
  int v10; // esi@6
  UIElement *v11; // eax@7
  UIElement_Text *v12; // esi@8
  char *v13; // esi@9
  LONG v14; // eax@6
  PStringBase<unsigned short> column_text; // [sp+Ch] [bp-8h]@2
  DBObjGrabber<CContractTable> contractdb; // [sp+10h] [bp-4h]@1

  v2 = this;
  v3 = DBObj::GetByEnum(23, 2, 0x10000010u);
  contractdb.m_object = (CContractTable *)v3;
  if ( v3 )
  {
    v4 = _info;
    v5 = CContractTable::GetContract((CContractTable *)v3, _info->m_ContractTracker._contract_id);
    column_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    v6 = UIElement_ListBox::AddItemFromTemplateListByID(v2->m_pContractsBox, 0x100005D7u, 0);
    v7 = (UIElement *)v6;
    v8 = UIElement::GetChildRecursive((UIElement *)v6, 0x100005D1u);
    if ( v8 )
    {
      v9 = (UIElement_Text *)v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12);
      if ( v9 )
        UIElement_Text::SetText(v9, &v4->m_Name);
    }
    if ( v5 )
    {
      v11 = UIElement::GetChildRecursive(v7, 0x100005D2u);
      if ( v11 )
      {
        v12 = (UIElement_Text *)v11->vfptr[12].OnAction((IInputActionCallback *)v11, (InputEvent *)12);
        if ( v12 )
        {
          _info = (ContractInfo *)PStringBase<unsigned short>::s_NullBuffer;
          InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
          gmContractsUI::FillProgressString(&v4->m_ContractTracker, v5, (PStringBase<unsigned short> *)&_info);
          UIElement_Text::SetText(v12, (PStringBase<unsigned short> *)&_info);
          v13 = (char *)&_info[-1].m_ContractTracker._time_when_done + 4;
          if ( !InterlockedDecrement((volatile LONG *)&_info[-1].m_ContractTracker._time_when_repeats) )
          {
            if ( v13 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
          }
        }
      }
      v10 = (int)&column_text.m_charbuffer[-1].m_data[6];
      v14 = InterlockedDecrement((volatile LONG *)&column_text.m_charbuffer[-1].m_data[8]);
    }
    else
    {
      v10 = (int)&column_text.m_charbuffer[-1].m_data[6];
      v14 = InterlockedDecrement((volatile LONG *)&column_text.m_charbuffer[-1].m_data[8]);
    }
    if ( !v14 )
    {
      if ( v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    }
    ((void (*)(void))contractdb.m_object->vfptr->Release)();
  }
}

//----- (00499830) --------------------------------------------------------  // acclient.c:211265
void __thiscall gmContractsUI::RefreshContractListbox(gmContractsUI *this)
{
  gmContractsUI *v1; // esi@1
  signed int v2; // edx@1
  CContractTable *v3; // ebp@2
  signed int v4; // ecx@3
  unsigned int v5; // edi@3
  int v6; // ebx@4
  PSRefBufferCharData<unsigned short> *v7; // eax@5
  UIElement *v8; // eax@5
  UIElement_Text *v9; // eax@6
  unsigned int v10; // ecx@8
  unsigned int v11; // edi@8
  PackableHashData<unsigned long,CContract> **v12; // ebp@9
  PackableHashData<unsigned long,CContract> *v13; // edx@10
  CContract *v14; // ebp@14
  UIElement *v15; // eax@15
  UIElement_Text *v16; // edi@16
  char *v17; // edi@17
  signed int v18; // ecx@20
  PStringBase<unsigned short> progress_msg; // [sp+8h] [bp-Ch]@5
  unsigned int i; // [sp+Ch] [bp-8h]@3
  DBObjGrabber<CContractTable> contractdb; // [sp+10h] [bp-4h]@2

  v1 = this;
  v2 = (signed int)((unsigned __int64)(715827883i64
                                     * (unsigned int)((char *)this->m_ContractList._M_finish
                                                    - (char *)this->m_ContractList._M_start)) >> 32) >> 3;
  if ( this->m_pContractsBox->m_listItems.m_num == ((unsigned int)v2 >> 31) + v2 )
  {
    v3 = (CContractTable *)DBObj::GetByEnum(23, 2, 0x10000010u);
    contractdb.m_object = v3;
    if ( v3 )
    {
      v4 = (char *)v1->m_ContractList._M_finish - (char *)v1->m_ContractList._M_start;
      v5 = 0;
      i = 0;
      if ( v4 / 48 )
      {
        v6 = 0;
        do
        {
          v7 = (PSRefBufferCharData<unsigned short> *)UIElement_ListBox::GetItem(v1->m_pContractsBox, v5);
          progress_msg.m_charbuffer = v7;
          v8 = UIElement::GetChildRecursive((UIElement *)v7, 0x100005D1u);
          if ( v8 )
          {
            v9 = (UIElement_Text *)v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12);
            if ( v9 )
              UIElement_Text::SetText(v9, &v1->m_ContractList._M_start[v6].m_Name);
          }
          v10 = v3->_contractHash._table_size;
          v11 = v1->m_ContractList._M_start[v6].m_ContractTracker._contract_id;
          if ( v10 )
          {
            v12 = v3->_contractHash._buckets;
            if ( v12 )
            {
              v13 = v12[v11 % v10];
              if ( v13 )
              {
                while ( v11 != v13->_key )
                {
                  v13 = v13->_next;
                  if ( !v13 )
                    goto LABEL_20;
                }
                v14 = &v13->_data;
                if ( v13 != (PackableHashData<unsigned long,CContract> *)-4 )
                {
                  v15 = UIElement::GetChildRecursive((UIElement *)progress_msg.m_charbuffer, 0x100005D2u);
                  if ( v15 )
                  {
                    v16 = (UIElement_Text *)v15->vfptr[12].OnAction((IInputActionCallback *)v15, (InputEvent *)12);
                    if ( v16 )
                    {
                      progress_msg.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
                      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
                      gmContractsUI::FillProgressString(
                        &v1->m_ContractList._M_start[v6].m_ContractTracker,
                        v14,
                        &progress_msg);
                      PStringBase<unsigned short>::operator=(
                        &v1->m_ContractList._M_start[v6].m_Status,
                        (const unsigned __int16 *)&progress_msg);
                      UIElement_Text::SetText(v16, &progress_msg);
                      v17 = (char *)&progress_msg.m_charbuffer[-1].m_data[6];
                      if ( !InterlockedDecrement((volatile LONG *)&progress_msg.m_charbuffer[-1].m_data[8]) )
                      {
                        if ( v17 )
                          (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
                      }
                    }
                  }
                }
              }
            }
          }
LABEL_20:
          v3 = contractdb.m_object;
          v18 = (char *)v1->m_ContractList._M_finish - (char *)v1->m_ContractList._M_start;
          v5 = i + 1;
          ++v6;
          ++i;
        }
        while ( i < v18 / 48 );
      }
      gmContractsUI::UpdateButtons(v1);
      v3->vfptr->Release((Interface *)v3);
    }
  }
}

//----- (00499A30) --------------------------------------------------------  // acclient.c:211379
void __thiscall _STL::vector<ContractInfo,_STL::allocator<ContractInfo>>::_M_insert_overflow(_STL::vector<ContractInfo,_STL::allocator<ContractInfo> > *this, ContractInfo *__position, ContractInfo *__x, _STL::__false_type *__formal, unsigned int __fill_len, bool __atend)
{
  _STL::vector<ContractInfo,_STL::allocator<ContractInfo> > *v6; // ebx@1
  signed int v7; // ecx@1
  int v8; // edx@1
  void *v9; // eax@1
  int v10; // eax@3
  bool v11; // zf@3
  const unsigned int v12; // eax@3
  ContractInfo *v13; // edi@8
  ContractInfo *v14; // ebp@8
  ContractInfo *i; // esi@8
  unsigned int v16; // edi@12
  ContractInfo *v17; // edi@23
  signed int v18; // edx@24
  ContractInfo *v19; // eax@25
  const unsigned int v20; // ecx@25
  unsigned int v21; // [sp-4h] [bp-1Ch]@4
  ContractInfo *__new_start; // [sp+10h] [bp-8h]@1
  const unsigned int __len; // [sp+14h] [bp-4h]@3

  v6 = this;
  v7 = (char *)this->_M_finish - (char *)this->_M_start;
  v8 = v7 / 48;
  __new_start = (ContractInfo *)(v7 / 48);
  v9 = &__fill_len;
  if ( v7 / 48 >= __fill_len )
    v9 = &__new_start;
  v10 = *(_DWORD *)v9;
  v11 = v8 + v10 == 0;
  v12 = v8 + v10;
  __len = v12;
  if ( v11 )
  {
    __new_start = 0;
  }
  else
  {
    v21 = 48 * v12;
    if ( 48 * v12 <= 0x80 )
      __new_start = (ContractInfo *)_STL::__node_alloc<1,0>::_M_allocate(v21);
    else
      __new_start = (ContractInfo *)operator new(v21);
  }
  v13 = v6->_M_start;
  v14 = __position;
  for ( i = __new_start; v13 != __position; ++i )
  {
    if ( i )
      ContractInfo::ContractInfo(i, v13);
    ++v13;
  }
  v16 = __fill_len;
  if ( __fill_len == 1 )
  {
    if ( i )
      ContractInfo::ContractInfo(i, __x);
    ++i;
  }
  else if ( __fill_len )
  {
    do
    {
      if ( i )
        ContractInfo::ContractInfo(i, __x);
      ++i;
      --v16;
    }
    while ( v16 );
    v14 = __position;
  }
  if ( !__atend )
    i = _STL::__uninitialized_copy(v14, v6->_M_finish, i);
  _STL::__destroy_aux(v6->_M_start, v6->_M_finish);
  v17 = v6->_M_start;
  if ( v6->_M_start )
  {
    v18 = (signed int)((unsigned __int64)(715827883i64
                                        * (unsigned int)((char *)v6->_M_end_of_storage._M_data - (char *)v17)) >> 32) >> 3;
    _STL::__node_alloc<1,0>::deallocate(v17, 48 * (((unsigned int)v18 >> 31) + v18));
  }
  v19 = __new_start;
  v20 = 3 * __len;
  v6->_M_finish = i;
  v6->_M_start = v19;
  v6->_M_end_of_storage._M_data = &v19[16 * v20 / 0x30];
}

//----- (00499B90) --------------------------------------------------------  // acclient.c:211468
void __cdecl _STL::__final_insertion_sort(ContractInfo *__first, ContractInfo *__last, bool (__cdecl *__comp)(ContractInfo *, ContractInfo *))
{
  if ( __last - __first <= 16 )
  {
    _STL::__insertion_sort(__first, __last, __comp);
  }
  else
  {
    _STL::__insertion_sort(__first, __first + 16, __comp);
    _STL::__unguarded_insertion_sort_aux(__first + 16, __last, 0, __comp);
  }
}

//----- (00499BF0) --------------------------------------------------------  // acclient.c:211482
void __cdecl _STL::__partial_sort(ContractInfo *__first, ContractInfo *__middle, ContractInfo *__last, ContractInfo *__formal, bool (__cdecl *__comp)(ContractInfo *, ContractInfo *))
{
  ContractInfo *i; // esi@1
  ContractInfo v6; // [sp-38h] [bp-48h]@3
  bool (__cdecl *v7)(ContractInfo *, ContractInfo *); // [sp-8h] [bp-18h]@1
  int v8; // [sp-4h] [bp-14h]@1

  v8 = 0;
  v7 = 0;
  _STL::__make_heap(__first, __middle, __comp);
  for ( i = __middle; i < __last; ++i )
  {
    if ( __comp(i, __first) )
    {
      v8 = 0;
      v7 = __comp;
      ContractInfo::ContractInfo(&v6, i);
      _STL::__pop_heap(__first, __middle, i, v6, v7);
    }
  }
  _STL::sort_heap(__first, __middle, __comp);
}

//----- (00499C60) --------------------------------------------------------  // acclient.c:211506
gmContractsUI *__thiscall gmContractsUI::vector_deleting_destructor(gmContractsUI *this, unsigned int a2)
{
  gmContractsUI *v2; // esi@1

  v2 = this;
  gmContractsUI::~gmContractsUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00499C80) --------------------------------------------------------  // acclient.c:211518
void __cdecl gmContractsUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000004Bu,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmContractsUI::Create);
}

//----- (00499CA0) --------------------------------------------------------  // acclient.c:211526
void __thiscall gmContractsUI::RebuildContractListbox(gmContractsUI *this)
{
  gmContractsUI *v1; // esi@1
  UIElement_ListBox *v2; // ecx@1
  unsigned int v3; // edi@1
  unsigned int v4; // eax@1
  UIElement **v5; // edx@2
  unsigned int v6; // ebp@5
  unsigned int v7; // edi@6
  int v8; // ebx@7

  v1 = this;
  v2 = this->m_pContractsBox;
  v3 = v2->m_listItems.m_num;
  v4 = 0;
  if ( v3 )
  {
    v5 = v2->m_listItems.m_data;
    while ( *v5 != v2->m_pSelectedItem )
    {
      ++v4;
      ++v5;
      if ( v4 >= v3 )
        goto LABEL_5;
    }
    v6 = v4;
  }
  else
  {
LABEL_5:
    v6 = -1;
  }
  UIElement_ListBox::Flush(v2);
  UIElement_ListBox::SetSelectedItem(v1->m_pContractsBox, 0, 1);
  v7 = 0;
  if ( v1->m_ContractList._M_finish - v1->m_ContractList._M_start )
  {
    v8 = 0;
    do
    {
      gmContractsUI::AddContractToListbox(v1, &v1->m_ContractList._M_start[v8]);
      ++v7;
      ++v8;
    }
    while ( v7 < v1->m_ContractList._M_finish - v1->m_ContractList._M_start );
  }
  UIElement_ListBox::SetSelectedIndex(v1->m_pContractsBox, v6, 1);
  gmContractsUI::UpdateButtons(v1);
}

//----- (00499D70) --------------------------------------------------------  // acclient.c:211577
int __thiscall _STL::vector<ContractInfo,_STL::allocator<ContractInfo>>::insert(_STL::vector<ContractInfo,_STL::allocator<ContractInfo> > *this, ContractInfo *__position, ContractInfo *__x)
{
  _STL::vector<ContractInfo,_STL::allocator<ContractInfo> > *v3; // esi@1
  unsigned int v4; // edx@1
  ContractInfo *v5; // ecx@1
  int v6; // ebx@1
  ContractInfo *v7; // ecx@5
  int result; // eax@5
  ContractInfo __x_copy; // [sp+Ch] [bp-30h]@8

  v3 = this;
  v4 = (unsigned __int64)(715827883i64 * ((char *)__position - (char *)this->_M_start)) >> 32;
  v5 = this->_M_finish;
  v6 = (v4 >> 31) + ((signed int)v4 >> 3);
  if ( v5 == v3->_M_end_of_storage._M_data )
  {
    _STL::vector<ContractInfo,_STL::allocator<ContractInfo>>::_M_insert_overflow(
      v3,
      __position,
      __x,
      (_STL::__false_type *)&__x,
      1u,
      0);
    result = (int)&v3->_M_start[v6];
  }
  else if ( __position == v5 )
  {
    if ( v5 )
      ContractInfo::ContractInfo(v5, __x);
    v7 = v3->_M_start;
    ++v3->_M_finish;
    result = (int)&v7[v6];
  }
  else
  {
    if ( v5 )
      ContractInfo::ContractInfo(v5, v5 - 1);
    ++v3->_M_finish;
    ContractInfo::ContractInfo(&__x_copy, __x);
    _STL::__copy_backward(__position, v3->_M_finish - 2, v3->_M_finish - 1);
    ContractInfo::operator=(__position, (int)&__x_copy);
    ContractInfo::~ContractInfo(&__x_copy);
    result = (int)&v3->_M_start[v6];
  }
  return result;
}

//----- (00499E60) --------------------------------------------------------  // acclient.c:211625
void __thiscall gmContractsUI::ListenToGlobalMessage(gmContractsUI *this, unsigned int i_messageID, int i_data_int)
{
  gmContractsUI *v3; // esi@1

  v3 = this;
  if ( i_messageID == 3
    && (*((_DWORD *)&this->0 + 41) >> 1) & 1
    && COERCE_DOUBLE(Timer::cur_time.Cmd) >= this->m_timeNextUpdate )
  {
    gmContractsUI::RefreshContractListbox(this);
    v3->m_timeNextUpdate = COERCE_DOUBLE(Timer::cur_time.Cmd) + 0.5;
  }
}

//----- (00499EB0) --------------------------------------------------------  // acclient.c:211640
void __thiscall gmContractsUI::RebuildContractList(gmContractsUI *this)
{
  ContractInfo *v1; // eax@1
  char *v2; // ebp@1
  ContractInfo *v3; // esi@1
  CPlayerSystem *v4; // esi@1
  CContractTable *v5; // edi@2
  PackableHashData<unsigned long,CContractTracker> *i; // eax@5
  CContract *v7; // edi@6
  int v8; // eax@6
  char *v9; // esi@6
  CContract *v10; // ST14_4@9
  gmContractsUI *v11; // edi@9
  char *v12; // esi@10
  char *v13; // esi@14
  PStringBase<unsigned short> progress_msg; // [sp+10h] [bp-8Ch]@9
  DBObjGrabber<CContractTable> contractdb; // [sp+14h] [bp-88h]@2
  PackableHashTable<unsigned long,CContractTracker> contractHash; // [sp+18h] [bp-84h]@3
  gmContractsUI *v17; // [sp+2Ch] [bp-70h]@1
  PStringBase<unsigned short> v18; // [sp+30h] [bp-6Ch]@6
  PackableHashIterator<unsigned long,CContractTracker> iter; // [sp+34h] [bp-68h]@5
  ContractInfo contractInfo; // [sp+44h] [bp-58h]@6
  CContractTracker contractTracker; // [sp+74h] [bp-28h]@6

  v1 = this->m_ContractList._M_finish;
  v2 = (char *)&this->m_ContractList;
  v17 = this;
  v3 = _STL::__copy(v1, v1, this->m_ContractList._M_start);
  _STL::__destroy_aux(v3, *((ContractInfo **)v2 + 1));
  *((_DWORD *)v2 + 1) = v3;
  v4 = CPlayerSystem::GetPlayerSystem();
  if ( v4 )
  {
    v5 = (CContractTable *)DBObj::GetByEnum(23, 2, 0x10000010u);
    contractdb.m_object = v5;
    if ( v5 )
    {
      contractHash.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,CContractTracker>::vftable;
      contractHash._buckets = 0;
      contractHash._table_size = 0;
      contractHash._currNum = 0;
      PackableHashTable<unsigned long,CContractTracker>::operator=(
        &contractHash,
        (int)&v4->m_contractTrackerTable._contractTrackerHash);
      if ( contractHash._currNum )
      {
        PackableHashTable<unsigned long,CContractTracker>::begin(&contractHash, &iter);
        for ( i = iter._current; iter._current; v5 = contractdb.m_object )
        {
          CContractTracker::CContractTracker(&contractTracker, &i->_data);
          v7 = CContractTable::GetContract(v5, contractTracker._contract_id);
          ContractInfo::ContractInfo(&contractInfo);
          CContractTracker::operator=((int)&contractInfo.m_ContractTracker, (int)&contractTracker);
          PStringBase<unsigned short>::PStringBase<unsigned short>(&v18, 0, v7->_contract_name.m_buffer->m_data);
          PStringBase<unsigned short>::sprintf(&contractInfo.m_Name, L"%s", *(_DWORD *)v8);
          v9 = (char *)&v18.m_charbuffer[-1].m_data[6];
          if ( !InterlockedDecrement((volatile LONG *)&v18.m_charbuffer[-1].m_data[8]) && v9 )
            (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
          progress_msg.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
          InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
          v10 = v7;
          v11 = v17;
          gmContractsUI::FillProgressString(&contractTracker, v10, &progress_msg);
          if ( contractInfo.m_Status.m_charbuffer != progress_msg.m_charbuffer )
          {
            v12 = (char *)&contractInfo.m_Status.m_charbuffer[-1].m_data[6];
            if ( !InterlockedDecrement((volatile LONG *)&contractInfo.m_Status.m_charbuffer[-1].m_data[8]) && v12 )
              (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
            contractInfo.m_Status.m_charbuffer = progress_msg.m_charbuffer;
            InterlockedIncrement((volatile LONG *)&progress_msg.m_charbuffer[-1].m_data[8]);
          }
          _STL::vector<ContractInfo,_STL::allocator<ContractInfo>>::insert(
            (_STL::vector<ContractInfo,_STL::allocator<ContractInfo> > *)v2,
            v11->m_ContractList._M_finish,
            &contractInfo);
          v13 = (char *)&progress_msg.m_charbuffer[-1].m_data[6];
          if ( !InterlockedDecrement((volatile LONG *)&progress_msg.m_charbuffer[-1].m_data[8]) && v13 )
            (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
          ContractInfo::~ContractInfo(&contractInfo);
          contractTracker.vfptr = (PackObjVtbl *)&PackObj::vftable;
          PackableHashIterator<unsigned long,CContractTracker>::GetNext(&iter);
          i = iter._current;
        }
        contractHash.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,CContractTracker>::vftable;
        PackableHashTable<unsigned long,CContractTracker>::EmptyContents((PackableHashTable<unsigned long,GeneratorRegistryNode> *)&contractHash);
        if ( contractHash._buckets )
          operator delete[](contractHash._buckets);
        v5->vfptr->Release((Interface *)v5);
      }
      else
      {
        PackableHashTable<unsigned long,CContractTracker>::~PackableHashTable<unsigned long,CContractTracker>(&contractHash);
        v5->vfptr->Release((Interface *)v5);
      }
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A6930: using guessed type int (__thiscall *PackableHashTable<unsigned long,CContractTracker>::vftable)(void *, char);

//----- (0049A0F0) --------------------------------------------------------  // acclient.c:211741
void __cdecl _STL::__introsort_loop(ContractInfo *__first, ContractInfo *__last, ContractInfo *__formal, int __depth_limit, bool (__cdecl *__comp)(ContractInfo *, ContractInfo *))
{
  ContractInfo *v5; // ebx@1
  int v6; // eax@3
  ContractInfo *v7; // esi@3
  bool v8; // zf@3
  ContractInfo *v9; // esi@11
  ContractInfo v10; // [sp-34h] [bp-44h]@11
  bool (__cdecl *v11)(ContractInfo *, ContractInfo *); // [sp-4h] [bp-14h]@3

  v5 = __last;
  if ( __last - __first > 16 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v6 = (v5 - __first) / 2;
      v7 = &__first[v6];
      v8 = __comp(__first, &__first[v6]) == 0;
      v11 = (bool (__cdecl *)(ContractInfo *, ContractInfo *))&v5[-1];
      if ( v8 )
      {
        if ( __comp(__first, (ContractInfo *)v11) )
        {
          v7 = __first;
        }
        else if ( __comp(v7, v5 - 1) )
        {
          v7 = v5 - 1;
        }
      }
      else if ( !__comp(v7, (ContractInfo *)v11) )
      {
        v7 = v5 - 1;
        if ( !__comp(__first, v5 - 1) )
          v7 = __first;
      }
      v11 = __comp;
      ContractInfo::ContractInfo(&v10, v7);
      v9 = _STL::__unguarded_partition(__first, v5, v10, v11);
      _STL::__introsort_loop(v9, v5, 0, __depth_limit, __comp);
      v5 = v9;
      if ( v9 - __first <= 16 )
        return;
    }
    _STL::__partial_sort(__first, v5, v5, 0, __comp);
  }
}

//----- (0049A200) --------------------------------------------------------  // acclient.c:211791
void __cdecl _STL::sort(ContractInfo *__first, ContractInfo *__last, bool (__cdecl *__comp)(ContractInfo *, ContractInfo *))
{
  signed int v3; // edx@2
  int i; // eax@2

  if ( __first != __last )
  {
    v3 = __last - __first;
    for ( i = 0; v3 != 1; ++i )
      v3 >>= 1;
    _STL::__introsort_loop(__first, __last, 0, 2 * i, __comp);
    _STL::__final_insertion_sort(__first, __last, __comp);
  }
}

//----- (0049A260) --------------------------------------------------------  // acclient.c:211807
void __thiscall gmContractsUI::SortContractList(gmContractsUI *this)
{
  gmContractsUI *v1; // esi@1
  ContractSortCriteria v2; // eax@1
  bool v3; // zf@2
  bool v4; // al@2

  v1 = this;
  gmContractsUI::RebuildContractListbox(this);
  v2 = v1->m_SortCriteria;
  if ( v2 )
  {
    v3 = v2 == 1;
    v4 = v1->m_ReverseSort;
    if ( v3 )
    {
      if ( v4 )
      {
        _STL::sort(v1->m_ContractList._M_start, v1->m_ContractList._M_finish, ContractInfoReverseSortStatus);
        gmContractsUI::RebuildContractListbox(v1);
      }
      else
      {
        _STL::sort(v1->m_ContractList._M_start, v1->m_ContractList._M_finish, ContractInfoSortStatus);
        gmContractsUI::RebuildContractListbox(v1);
      }
    }
    else if ( v4 )
    {
      _STL::sort(
        v1->m_ContractList._M_start,
        v1->m_ContractList._M_finish,
        (bool (__cdecl *)(ContractInfo *, ContractInfo *))PageInfoReverseSortLabel);
      gmContractsUI::RebuildContractListbox(v1);
    }
    else
    {
      _STL::sort(
        v1->m_ContractList._M_start,
        v1->m_ContractList._M_finish,
        (bool (__cdecl *)(ContractInfo *, ContractInfo *))PageInfoSortLabel);
      gmContractsUI::RebuildContractListbox(v1);
    }
  }
  else if ( v1->m_ReverseSort )
  {
    _STL::sort(
      v1->m_ContractList._M_start,
      v1->m_ContractList._M_finish,
      (bool (__cdecl *)(ContractInfo *, ContractInfo *))PageInfoReverseSortLabel);
    gmContractsUI::RebuildContractListbox(v1);
  }
  else
  {
    _STL::sort(
      v1->m_ContractList._M_start,
      v1->m_ContractList._M_finish,
      (bool (__cdecl *)(ContractInfo *, ContractInfo *))PageInfoSortLabel);
    gmContractsUI::RebuildContractListbox(v1);
  }
}

//----- (0049A370) --------------------------------------------------------  // acclient.c:211870
void __thiscall gmContractsUI::RecvNotice_UpdateContractTrackerTable(gmContractsUI *this, CContractTrackerTable *contractTrackerTable)
{
  gmContractsUI *v2; // esi@1

  v2 = (gmContractsUI *)((char *)this - 1528);
  gmContractsUI::RebuildContractList((gmContractsUI *)((char *)this - 1528));
  gmContractsUI::SortContractList(v2);
}

//----- (0049A390) --------------------------------------------------------  // acclient.c:211880
void __thiscall gmContractsUI::RecvNotice_UpdateContractTracker(gmContractsUI *this, CContractTracker *contractTracker, int bDeleteContract)
{
  gmContractsUI *v3; // esi@1

  v3 = (gmContractsUI *)((char *)this - 1528);
  gmContractsUI::RebuildContractList((gmContractsUI *)((char *)this - 1528));
  gmContractsUI::SortContractList(v3);
}

//----- (0049A3B0) --------------------------------------------------------  // acclient.c:211890
int __thiscall gmContractsUI::ListenToElementMessage(gmContractsUI *this, UIElementMessageInfo *i_rMsg)
{
  gmContractsUI *v2; // esi@1
  unsigned int v3; // eax@4
  gmContractsUI *v4; // ecx@5
  unsigned int v6; // eax@9
  unsigned int v7; // eax@10
  ContractSortCriteria v8; // eax@12

  v2 = this;
  if ( i_rMsg->idMessage == 1 )
  {
    if ( i_rMsg->idElement == 268436942 )
    {
      v8 = 0;
      if ( this->m_SortCriteria == eName )
      {
        this->m_ReverseSort = this->m_ReverseSort == 0;
        goto LABEL_19;
      }
      this->m_ReverseSort = 0;
    }
    else
    {
      if ( i_rMsg->idElement != 268436950 )
      {
        if ( i_rMsg->idElement == 268436956 )
        {
          v6 = UIElement_ListBox::GetSelectedIndex(this->m_pContractsBox);
          if ( v6 != -1 )
          {
            v7 = v2->m_ContractList._M_start[v6].m_ContractTracker._contract_id;
            if ( v7 )
            {
              CM_Social::Event_AbandonContract(v7);
              gmContractsUI::UpdateButtons(v2);
              return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
            }
          }
        }
        goto LABEL_20;
      }
      v8 = 1;
      if ( this->m_SortCriteria == 1 )
      {
        this->m_ReverseSort = this->m_ReverseSort == 0;
LABEL_19:
        gmContractsUI::SortContractList(this);
        goto LABEL_20;
      }
      this->m_ReverseSort = 0;
    }
    this->m_SortCriteria = v8;
    goto LABEL_19;
  }
  if ( i_rMsg->idMessage == 4 )
  {
LABEL_20:
    gmContractsUI::UpdateButtons(v2);
    return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
  }
  if ( i_rMsg->idMessage == 67 )
  {
    v3 = UIElement_ListBox::GetSelectedIndex(this->m_pContractsBox);
    if ( v3 != -1 )
    {
      gmContractsUI::CheckForDoubleClick(v2, v3);
      gmContractsUI::UpdateButtons(v4);
      return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
    }
    goto LABEL_20;
  }
  return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
}

//----- (0049A4D0) --------------------------------------------------------  // acclient.c:211966
void __thiscall gmContractsUI::OnVisibilityChanged(gmContractsUI *this, bool i_bVisible)
{
  gmContractsUI *v2; // esi@1

  v2 = this;
  UIElement::OnVisibilityChanged((UIElement *)&this->vfptr, i_bVisible);
  if ( i_bVisible )
  {
    gmContractsUI::RebuildContractList(v2);
    gmContractsUI::SortContractList(v2);
  }
}

//----- (006EEC90) --------------------------------------------------------  // acclient.c:770870
void _E91_59()
{
  outside_val_51 = 1000.0 + 1.0;
}

//----- (006EECB0) --------------------------------------------------------  // acclient.c:770876
void _E93_35()
{
  block_length_51 = 24.0 * 8.0;
}

//----- (006EECD0) --------------------------------------------------------  // acclient.c:770882
void _E95_35()
{
  half_square_length_51 = 24.0 * 0.5;
}

//----- (006EECF0) --------------------------------------------------------  // acclient.c:770888
int _E97_60()
{
  return atexit(_E98_72);
}

//----- (006EED00) --------------------------------------------------------  // acclient.c:770894
int _E100_53()
{
  return atexit(_E101_90);
}

//----- (006EED10) --------------------------------------------------------  // acclient.c:770900
int _E103_45()
{
  return atexit(_E104_60);
}

//----- (006EED20) --------------------------------------------------------  // acclient.c:770906
void _E106_35()
{
  DEFAULT_VIEW_RADIUS_28 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EED40) --------------------------------------------------------  // acclient.c:770912
void _E108_25()
{
  MIN_QUANTUM_28 = 1.0 / 30.0;
}

//----- (006EED60) --------------------------------------------------------  // acclient.c:770918
void _E110_16()
{
  MAX_QUANTUM_28 = 1.0 / 5.0;
}

//----- (006EED80) --------------------------------------------------------  // acclient.c:770924
void _E112_30()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_63, PFID_A8R8G8B8);
}

//----- (006EED90) --------------------------------------------------------  // acclient.c:770930
void _E115_23()
{
  LOWEST_DATA_RATE_71 = 1024;
}

//----- (006EEDA0) --------------------------------------------------------  // acclient.c:770936
void _E117_20()
{
  HIGHEST_DATA_RATE_71 = 0x7FFF;
}

//----- (006EEDB0) --------------------------------------------------------  // acclient.c:770942
int _E119_9()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_71;
  INITIAL_MAX_DATA_RATE_19 = LOWEST_DATA_RATE_71;
  return result;
}

//----- (006EEDC0) --------------------------------------------------------  // acclient.c:770952
int _E121_30()
{
  return atexit(_E122_67);
}

//----- (006EEDD0) --------------------------------------------------------  // acclient.c:770958
int _E124_28()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_23, "Misc.TooltipEnable");
  return atexit(_E125_38);
}

//----- (006EEDF0) --------------------------------------------------------  // acclient.c:770965
int _E127_24()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_23, "Misc.TooltipDelay");
  return atexit(_E128_39);
}

//----- (006EEE10) --------------------------------------------------------  // acclient.c:770972
int _E7_1()
{
  Outside_CellID_1.id = Invalid_CellID_1.id + 1;
  return atexit(_E8_1);
}

//----- (006EEE30) --------------------------------------------------------  // acclient.c:770979
int _E4_1()
{
  return atexit(_E5_1);
}

//----- (006EEE40) --------------------------------------------------------  // acclient.c:770985
int _E43_1()
{
  return atexit(_E44_1);
}

//----- (006EEE50) --------------------------------------------------------  // acclient.c:770991
int sub_6EEE50()
{
  return atexit(nullsub_869);
}

//----- (0075FCE0) --------------------------------------------------------  // acclient.c:887575
void __cdecl _E125_38()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FD10) --------------------------------------------------------  // acclient.c:887588
void __cdecl _E128_39()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

