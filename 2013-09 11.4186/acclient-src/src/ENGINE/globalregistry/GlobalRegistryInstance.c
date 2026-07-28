/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GlobalRegistryInstance
   Object     : ENGINE\globalregistry\GlobalRegistryInstance.obj
   Functions  : 61
   Addresses  : 004327F0 - 00728A40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004327F0) --------------------------------------------------------  // acclient.c:112076
TResult *__thiscall GlobalRegistryCommands::QueryInterface(GlobalRegistryCommands *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( dword_837094 & 1 )
  {
    v4 = Offsets[0].key;
  }
  else
  {
    v4 = (_GUID *)&Interface_InterfaceType_14;
    dword_837094 |= 1u;
    Offsets[0].key = (_GUID *)&Interface_InterfaceType_14;
    dword_837088 = 0;
    dword_83708C = 0;
    dword_837090 = 0;
  }
  v5 = (int)Offsets;
  if ( v4 )
  {
    while ( v4->Data1 != i_rcInterface->m_data1
         || *(_DWORD *)&v4->Data2 != *(_DWORD *)&i_rcInterface->m_data2
         || *(_DWORD *)&v4->Data4[0] != *(_DWORD *)&i_rcInterface->m_data4[0]
         || *(_DWORD *)&v4->Data4[4] != *(_DWORD *)&i_rcInterface->m_data4[4] )
    {
      v4 = *(_GUID **)(v5 + 8);
      v5 += 8;
      if ( !v4 )
        goto LABEL_10;
    }
    if ( o_ppvInterface )
    {
      v7 = *(_DWORD *)(v5 + 4);
      v8 = *(int *)((char *)&this->vfptr + v7);
      v9 = (char *)this + v7;
      (*(void (__thiscall **)(char *))(v8 + 16))(v9);
      *o_ppvInterface = v9;
    }
    v6 = result;
    result->m_val = 0;
  }
  else
  {
LABEL_10:
    v6 = result;
    result->m_val = -2147467262;
  }
  return v6;
}
// 837088: using guessed type int dword_837088;
// 83708C: using guessed type int dword_83708C;
// 837090: using guessed type int dword_837090;

//----- (004328B0) --------------------------------------------------------  // acclient.c:112135
IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0> *__thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::scalar_deleting_destructor(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0> *v2; // esi@1
  HashTableData<PStringBase<char>,GRPCommand *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>Vtbl *)IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::vftable;
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
// 7984F4: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::vftable[2])(void *, char);

//----- (004328F0) --------------------------------------------------------  // acclient.c:112156
IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0> *__thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::vector_deleting_destructor(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0> *v2; // esi@1
  HashTableData<PStringBase<char>,GRPObject *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>Vtbl *)&IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::vftable;
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
// 7984F8: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::vftable)(void *, char);

//----- (00432930) --------------------------------------------------------  // acclient.c:112177
bool __stdcall _STL::less<PStringBase<char>>::operator()(PStringBase<char> *__x, PStringBase<char> *__y)
{
  int v3; // kr00_4@1
  bool result; // al@2

  v3 = strcmp(__x->m_charbuffer->m_data, __y->m_charbuffer->m_data);
  if ( v3 )
    result = -(v3 < 0) - ((v3 < 0) - 1) < 0;
  else
    result = 0;
  return result;
}

//----- (00432990) --------------------------------------------------------  // acclient.c:112191
void __thiscall GRPTypedVariableObject::SetVariable(GRPTypedVariableObject *this, const bool *a2)
{
  GRPTypedVariableObject *v2; // esi@1
  const bool *v3; // esi@3

  v2 = this;
  if ( this->m_Type == 2 )
  {
    *(_BYTE *)this->m_pVariable = *a2;
    if ( this->m_OnChangedCallbackFunction )
    {
      a2 = (const bool *)this->m_Name.m_charbuffer;
      InterlockedIncrement((volatile LONG *)a2 - 4);
      v2->m_OnChangedCallbackFunction((PStringBase<char> *)&a2);
      v3 = a2 - 20;
      if ( !InterlockedDecrement((volatile LONG *)a2 - 4) )
      {
        if ( v3 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      }
    }
  }
}

//----- (004329F0) --------------------------------------------------------  // acclient.c:112216
PStringBase<char> *__cdecl _STL::__median(PStringBase<char> *__a, PStringBase<char> *__b, PStringBase<char> *__c)
{
  PStringBase<char> *result; // eax@4
  bool v4; // zf@7

  if ( strcmp(__a->m_charbuffer->m_data, __b->m_charbuffer->m_data) < 0 )
  {
    if ( !_STL::less<PStringBase<char>>::operator()(__b, __c) )
    {
      if ( _STL::less<PStringBase<char>>::operator()(__a, __c) )
        return __c;
      return __a;
    }
    return __b;
  }
  if ( _STL::less<PStringBase<char>>::operator()(__a, __c) )
    return __a;
  v4 = _STL::less<PStringBase<char>>::operator()(__b, __c) == 0;
  result = __c;
  if ( v4 )
    return __b;
  return result;
}

//----- (00432A90) --------------------------------------------------------  // acclient.c:112241
void __cdecl _STL::swap(PStringBase<char> *__a, PStringBase<char> *__b)
{
  PSRefBufferCharData<char> *v2; // esi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // ebp@2
  PSRefBufferCharData<char> *v5; // eax@5
  char *v6; // edi@7
  int v7; // esi@11

  v2 = __a->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&__a->m_charbuffer[-1]);
  v3 = __a->m_charbuffer;
  if ( __a->m_charbuffer != __b->m_charbuffer )
  {
    v4 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = __b->m_charbuffer;
    __a->m_charbuffer = __b->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
  }
  if ( __b->m_charbuffer != v2 )
  {
    v6 = &__b->m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)v6 + 1) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    __b->m_charbuffer = v2;
    InterlockedIncrement((volatile LONG *)&v2[-1]);
  }
  v7 = (int)&v2[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) )
  {
    if ( v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  }
}

//----- (00432B30) --------------------------------------------------------  // acclient.c:112279
void __cdecl _STL::__unguarded_linear_insert(PStringBase<char> *__last, PStringBase<char> __val)
{
  PStringBase<char> *v2; // ebx@1
  PSRefBufferCharData<char> *v3; // ebp@1
  PStringBase<char> *i; // edi@1
  PSRefBufferCharData<char> *v5; // eax@2
  int v6; // esi@3
  PSRefBufferCharData<char> *v7; // eax@6
  PSRefBufferCharData<char> *v8; // eax@8
  int v9; // esi@9

  v2 = __last;
  v3 = __last[-1].m_charbuffer;
  for ( i = __last - 1; strcmp(__val.m_charbuffer->m_data, v3->m_data) < 0; --i )
  {
    v5 = v2->m_charbuffer;
    if ( v2->m_charbuffer != v3 )
    {
      v6 = (int)&v5[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      v7 = i->m_charbuffer;
      v2->m_charbuffer = i->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v7[-1]);
    }
    v3 = i[-1].m_charbuffer;
    v2 = i;
  }
  v8 = v2->m_charbuffer;
  if ( v2->m_charbuffer != __val.m_charbuffer )
  {
    v9 = (int)&v8[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v8[-1]) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v2->m_charbuffer = __val.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&__val.m_charbuffer[-1]);
  }
  if ( !InterlockedDecrement((volatile LONG *)&__val.m_charbuffer[-1])
    && __val.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&__val.m_charbuffer[-2].m_data[12])(&__val.m_charbuffer[-2].m_data[12], 1);
}

//----- (00432C40) --------------------------------------------------------  // acclient.c:112322
void __cdecl _STL::__push_heap(PStringBase<char> *__first, int __holeIndex, int __topIndex, PStringBase<char> __val)
{
  int v4; // ebp@1
  int i; // edi@1
  PSRefBufferCharData<char> *v6; // eax@3
  int v7; // esi@4
  PSRefBufferCharData<char> *v8; // eax@7
  PSRefBufferCharData<char> *v9; // eax@9
  int v10; // esi@10

  v4 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v4 > __topIndex; i = (i - 1) / 2 )
  {
    if ( strcmp(__first[i].m_charbuffer->m_data, __val.m_charbuffer->m_data) >= 0 )
      break;
    v6 = __first[v4].m_charbuffer;
    if ( v6 != __first[i].m_charbuffer )
    {
      v7 = (int)&v6[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      v8 = __first[i].m_charbuffer;
      __first[v4].m_charbuffer = v8;
      InterlockedIncrement((volatile LONG *)&v8[-1]);
    }
    v4 = i;
  }
  v9 = __first[v4].m_charbuffer;
  if ( v9 != __val.m_charbuffer )
  {
    v10 = (int)&v9[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    __first[v4].m_charbuffer = __val.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&__val.m_charbuffer[-1]);
  }
  if ( !InterlockedDecrement((volatile LONG *)&__val.m_charbuffer[-1])
    && __val.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&__val.m_charbuffer[-2].m_data[12])(&__val.m_charbuffer[-2].m_data[12], 1);
}

//----- (00432D40) --------------------------------------------------------  // acclient.c:112364
PStringBase<char> *__cdecl _STL::__copy_backward(PStringBase<char> *__first, PStringBase<char> *__last, PStringBase<char> *__result)
{
  PStringBase<char> *v3; // ebx@1
  PStringBase<char> *v4; // edi@2
  PSRefBufferCharData<char> *v5; // eax@3
  PSRefBufferCharData<char> *v6; // ecx@3
  int v7; // esi@4
  PSRefBufferCharData<char> *v8; // eax@7
  PStringBase<char> *result; // eax@9
  PStringBase<char> *__lasta; // [sp+10h] [bp+8h]@2

  v3 = __last;
  if ( __last - __first <= 0 )
  {
    result = __result;
  }
  else
  {
    v4 = __result;
    __lasta = (PStringBase<char> *)(__last - __first);
    do
    {
      v5 = v4[-1].m_charbuffer;
      v6 = v3[-1].m_charbuffer;
      --v3;
      --v4;
      if ( v5 != v6 )
      {
        v7 = (int)&v5[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) )
        {
          if ( v7 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
        }
        v8 = v3->m_charbuffer;
        v4->m_charbuffer = v3->m_charbuffer;
        InterlockedIncrement((volatile LONG *)&v8[-1]);
      }
      __lasta = (PStringBase<char> *)((char *)__lasta - 1);
    }
    while ( __lasta );
    result = v4;
  }
  return result;
}

//----- (00432DB0) --------------------------------------------------------  // acclient.c:112411
char __thiscall GlobalRegistryInstance::IsEmpty(GlobalRegistryInstance *this)
{
  char v1; // al@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@3
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // esi@3
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // ebx@3
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edi@3
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+0h] [bp-Ch]@3

  if ( this->m_CommandHash.m_intrusiveTable.m_numElements )
  {
    v1 = 0;
  }
  else
  {
    v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_ObjectHash.m_intrusiveTable,
           &result);
    v3 = v2->m_currElement;
    v4 = v2->m_currHashTable;
    v5 = v2->m_currBucket;
    if ( v3 )
    {
      do
      {
LABEL_4:
        if ( !(*((int (**)(void))v3->m_data.vfptr->Serialize + 15))() )
          return 0;
        v3 = v3->m_hashNext;
      }
      while ( v3 );
      while ( 1 )
      {
        ++v5;
        if ( v5 == &v4->m_buckets[v4->m_numBuckets] )
          break;
        if ( *v5 )
        {
          v3 = *v5;
          if ( *v5 )
            goto LABEL_4;
          break;
        }
      }
    }
    v1 = 1;
  }
  return v1;
}

//----- (00432E30) --------------------------------------------------------  // acclient.c:112462
void __thiscall GlobalRegistryInstance::CheckForLeakedData(GlobalRegistryInstance *this)
{
  GlobalRegistryInstance *v1; // ebx@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // edx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // ecx@1
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // eax@1
  int v6; // ecx@6
  HashTableData<PStringBase<char>,GRPObject *> **v7; // eax@7
  int v8; // eax@8
  HashTableData<PStringBase<char>,GRPObject *> **v9; // eax@9
  HashTableData<PStringBase<char>,GRPObject *> *v10; // esi@9
  HashTableData<PStringBase<char>,GRPObject *> **v11; // edi@11
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@1

  v1 = this;
  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_CommandHash.m_intrusiveTable,
         &result);
  v3 = v2->m_currHashTable;
  v4 = v2->m_currBucket;
  v5 = v2->m_currElement;
  if ( v5 )
  {
    do
LABEL_2:
      v5 = v5->m_hashNext;
    while ( v5 );
    while ( 1 )
    {
      ++v4;
      if ( v4 == &v3->m_buckets[v3->m_numBuckets] )
        break;
      if ( *v4 )
      {
        v5 = *v4;
        if ( *v4 )
          goto LABEL_2;
        break;
      }
    }
  }
  v6 = (int)&v1->m_ObjectHash.m_intrusiveTable.m_buckets[v1->m_ObjectHash.m_intrusiveTable.m_numBuckets];
  if ( v1->m_ObjectHash.m_intrusiveTable.m_firstInterestingBucket == (HashTableData<PStringBase<char>,GRPObject *> **)v6 )
  {
LABEL_9:
    v9 = 0;
    v10 = 0;
  }
  else
  {
    while ( 1 )
    {
      v7 = v1->m_ObjectHash.m_intrusiveTable.m_firstInterestingBucket;
      if ( *v7 )
        break;
      v8 = (int)(v7 + 1);
      v1->m_ObjectHash.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<PStringBase<char>,GRPObject *> **)v8;
      if ( v8 == v6 )
        goto LABEL_9;
    }
    v9 = v1->m_ObjectHash.m_intrusiveTable.m_firstInterestingBucket;
    v10 = *v9;
  }
  v11 = v9;
  if ( v10 )
  {
    do
    {
LABEL_12:
      if ( !((int (*)(void))v10->m_data->vfptr->AsShadowVariableObject)() )
        ((void (*)(void))v10->m_data->vfptr->AsVariableObject)();
      v10 = v10->m_hashNext;
    }
    while ( v10 );
    while ( 1 )
    {
      ++v11;
      if ( v11 == &v1->m_ObjectHash.m_intrusiveTable.m_buckets[v1->m_ObjectHash.m_intrusiveTable.m_numBuckets] )
        break;
      if ( *v11 )
      {
        v10 = *v11;
        if ( *v11 )
          goto LABEL_12;
        return;
      }
    }
  }
}

//----- (00432F10) --------------------------------------------------------  // acclient.c:112554
void __cdecl _STL::__unguarded_insertion_sort_aux(PStringBase<char> *__first, PStringBase<char> *__last)
{
  PStringBase<char> *i; // esi@1
  PStringBase<char> v3; // ST04_4@2

  for ( i = __first; i != __last; ++i )
  {
    v3.m_charbuffer = i->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&i->m_charbuffer[-1]);
    _STL::__unguarded_linear_insert(i, v3);
  }
}

//----- (00432F60) --------------------------------------------------------  // acclient.c:112568
void __cdecl _STL::__adjust_heap(PStringBase<char> *__first, int __holeIndex, int __len, PStringBase<char> __val)
{
  int v4; // ebx@1
  int v5; // esi@1
  bool v6; // zf@1
  PSRefBufferCharData<char> *v7; // eax@4
  int v8; // edi@5
  PSRefBufferCharData<char> *v9; // eax@8
  PSRefBufferCharData<char> *v10; // eax@12
  int v11; // edi@13
  PSRefBufferCharData<char> *v12; // eax@16

  v4 = __holeIndex;
  v5 = 2 * __holeIndex + 2;
  v6 = v5 == __len;
  if ( v5 < __len )
  {
    do
    {
      if ( strcmp(__first[v5].m_charbuffer->m_data, __first[v5 - 1].m_charbuffer->m_data) < 0 )
        --v5;
      v7 = __first[v4].m_charbuffer;
      if ( v7 != __first[v5].m_charbuffer )
      {
        v8 = (int)&v7[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v7[-1]) && v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
        v9 = __first[v5].m_charbuffer;
        __first[v4].m_charbuffer = v9;
        InterlockedIncrement((volatile LONG *)&v9[-1]);
      }
      v4 = v5;
      v5 = 2 * v5 + 2;
    }
    while ( v5 < __len );
    v6 = v5 == __len;
  }
  if ( v6 )
  {
    v10 = __first[v4].m_charbuffer;
    if ( v10 != __first[v5 - 1].m_charbuffer )
    {
      v11 = (int)&v10[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v10[-1]) && v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      v12 = __first[v5 - 1].m_charbuffer;
      __first[v4].m_charbuffer = v12;
      InterlockedIncrement((volatile LONG *)&v12[-1]);
    }
    v4 = v5 - 1;
  }
  InterlockedIncrement((volatile LONG *)&__val.m_charbuffer[-1]);
  _STL::__push_heap(__first, v4, __holeIndex, __val);
  if ( !InterlockedDecrement((volatile LONG *)&__val.m_charbuffer[-1])
    && __val.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&__val.m_charbuffer[-2].m_data[12])(&__val.m_charbuffer[-2].m_data[12], 1);
}

//----- (00433090) --------------------------------------------------------  // acclient.c:112627
void __thiscall GlobalRegistryCommands::~GlobalRegistryCommands(GlobalRegistryCommands *this)
{
  char *v1; // esi@1
  char *v2; // esi@4
  char *v3; // esi@7
  char *v4; // esi@10
  char *v5; // esi@13
  char *v6; // esi@16
  PStringBase<char> _Name; // [sp+14h] [bp-4h]@1

  _Name.m_charbuffer = (PSRefBufferCharData<char> *)this;
  this->vfptr = (InterfaceVtbl *)&GlobalRegistryCommands::vftable;
  PStringBase<char>::PStringBase<char>(&_Name, "Toggle");
  GlobalRegistry::UnregisterCommand(&_Name);
  v1 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v1 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Set");
  GlobalRegistry::UnregisterCommand(&_Name);
  v2 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Dump");
  GlobalRegistry::UnregisterCommand(&_Name);
  v3 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Help");
  GlobalRegistry::UnregisterCommand(&_Name);
  v4 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "ListObjects");
  GlobalRegistry::UnregisterCommand(&_Name);
  v5 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "ListCommands");
  GlobalRegistry::UnregisterCommand(&_Name);
  v6 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) )
  {
    if ( v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  }
}
// 798534: using guessed type __int32 (__stdcall *GlobalRegistryCommands::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00433200) --------------------------------------------------------  // acclient.c:112676
PStringBase<char> *__cdecl _STL::__unguarded_partition(PStringBase<char> *__first, PStringBase<char> *__last, PStringBase<char> __pivot)
{
  PStringBase<char> *v3; // ebx@1
  PStringBase<char> *v4; // edi@1
  const char *v5; // eax@3
  const char *v6; // esi@4
  const char *v7; // esi@5

  v3 = __first;
  v4 = __last;
  while ( 1 )
  {
    if ( strcmp(v3->m_charbuffer->m_data, __pivot.m_charbuffer->m_data) < 0 )
    {
      do
      {
        v5 = v3[1].m_charbuffer->m_data;
        ++v3;
      }
      while ( strcmp(v5, __pivot.m_charbuffer->m_data) < 0 );
    }
    v6 = v4[-1].m_charbuffer->m_data;
    --v4;
    if ( strcmp(__pivot.m_charbuffer->m_data, v6) < 0 )
    {
      do
      {
        v7 = v4[-1].m_charbuffer->m_data;
        --v4;
      }
      while ( strcmp(__pivot.m_charbuffer->m_data, v7) < 0 );
    }
    if ( v3 >= v4 )
      break;
    _STL::swap(v3, v4);
    ++v3;
  }
  if ( !InterlockedDecrement((volatile LONG *)&__pivot.m_charbuffer[-1])
    && __pivot.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&__pivot.m_charbuffer[-2].m_data[12])(
      &__pivot.m_charbuffer[-2].m_data[12],
      1);
  return v3;
}

//----- (00433330) --------------------------------------------------------  // acclient.c:112722
void __cdecl _STL::__pop_heap(PStringBase<char> *__first, PStringBase<char> *__last, PStringBase<char> *__result, PStringBase<char> __val)
{
  PSRefBufferCharData<char> *v4; // eax@1
  int v5; // edi@2
  PSRefBufferCharData<char> *v6; // eax@5

  v4 = __result->m_charbuffer;
  if ( __result->m_charbuffer != __first->m_charbuffer )
  {
    v5 = (int)&v4[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = __first->m_charbuffer;
    __result->m_charbuffer = __first->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v6[-1]);
  }
  InterlockedIncrement((volatile LONG *)&__val.m_charbuffer[-1]);
  _STL::__adjust_heap(__first, 0, __last - __first, __val);
  if ( !InterlockedDecrement((volatile LONG *)&__val.m_charbuffer[-1])
    && __val.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&__val.m_charbuffer[-2].m_data[12])(&__val.m_charbuffer[-2].m_data[12], 1);
}

//----- (004333C0) --------------------------------------------------------  // acclient.c:112746
void __cdecl _STL::__make_heap(PStringBase<char> *__first, PStringBase<char> *__last)
{
  int v2; // ebx@1
  int i; // esi@2
  PStringBase<char> v4; // ST0C_4@3

  v2 = __last - __first;
  if ( v2 >= 2 )
  {
    for ( i = (v2 - 2) / 2; ; --i )
    {
      v4.m_charbuffer = __first[i].m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v4.m_charbuffer[-1]);
      _STL::__adjust_heap(__first, i, v2, v4);
      if ( !i )
        break;
    }
  }
}

//----- (00433410) --------------------------------------------------------  // acclient.c:112767
char __thiscall GlobalRegistryInstance::FindCommandByName(GlobalRegistryInstance *this, PStringBase<char> *_Name, GRPCommand **_pFoundCommand)
{
  GRPCommand **v3; // edi@1
  GlobalRegistryInstance *v4; // esi@1
  GRPCommand **v5; // esi@1
  char v6; // al@5
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+8h] [bp-Ch]@1

  v3 = _pFoundCommand;
  *_pFoundCommand = 0;
  _pFoundCommand = (GRPCommand **)_Name->m_charbuffer;
  v4 = this;
  InterlockedIncrement((volatile LONG *)_pFoundCommand - 4);
  PStringBase<char>::break_reference((PStringBase<char> *)&_pFoundCommand);
  __strlwr((char *)_pFoundCommand);
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&v4->m_CommandHash.m_intrusiveTable,
    &result,
    (PStringBase<char> *)&_pFoundCommand);
  v5 = _pFoundCommand - 5;
  if ( result.m_currElement )
  {
    *v3 = (GRPCommand *)result.m_currElement->m_data;
    if ( !InterlockedDecrement((volatile LONG *)v5 + 1) )
    {
      if ( v5 )
        ((void (__thiscall *)(_DWORD, _DWORD))(*v5)->vfptr)(v5, 1);
    }
    v6 = 1;
  }
  else
  {
    if ( !InterlockedDecrement((volatile LONG *)v5 + 1) && v5 )
      ((void (__thiscall *)(_DWORD, _DWORD))(*v5)->vfptr)(v5, 1);
    v6 = 0;
  }
  return v6;
}

//----- (004334C0) --------------------------------------------------------  // acclient.c:112807
char __thiscall GlobalRegistryInstance::FindObjectByName(GlobalRegistryInstance *this, PStringBase<char> *_Name, GRPObject **_pFoundObject)
{
  GRPObject **v3; // edi@1
  GlobalRegistryInstance *v4; // esi@1
  GRPObject **v5; // esi@1
  char v6; // al@5
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+8h] [bp-Ch]@1

  v3 = _pFoundObject;
  *_pFoundObject = 0;
  _pFoundObject = (GRPObject **)_Name->m_charbuffer;
  v4 = this;
  InterlockedIncrement((volatile LONG *)_pFoundObject - 4);
  PStringBase<char>::break_reference((PStringBase<char> *)&_pFoundObject);
  __strlwr((char *)_pFoundObject);
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&v4->m_ObjectHash.m_intrusiveTable,
    &result,
    (PStringBase<char> *)&_pFoundObject);
  v5 = _pFoundObject - 5;
  if ( result.m_currElement )
  {
    *v3 = (GRPObject *)result.m_currElement->m_data;
    if ( !InterlockedDecrement((volatile LONG *)v5 + 1) )
    {
      if ( v5 )
        ((void (__thiscall *)(_DWORD, _DWORD))(*v5)->vfptr)(v5, 1);
    }
    v6 = 1;
  }
  else
  {
    if ( !InterlockedDecrement((volatile LONG *)v5 + 1) && v5 )
      ((void (__thiscall *)(_DWORD, _DWORD))(*v5)->vfptr)(v5, 1);
    v6 = 0;
  }
  return v6;
}

//----- (00433570) --------------------------------------------------------  // acclient.c:112847
void __thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>Vtbl *)IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<PStringBase<char>,GRPCommand *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<PStringBase<char>,GRPCommand *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7984F4: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::vftable[2])(void *, char);

//----- (00433600) --------------------------------------------------------  // acclient.c:112880
void __thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>Vtbl *)&IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<PStringBase<char>,GRPObject *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<PStringBase<char>,GRPObject *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7984F8: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::vftable)(void *, char);

//----- (00433690) --------------------------------------------------------  // acclient.c:112913
void __cdecl _STL::__linear_insert(PStringBase<char> *__first, PStringBase<char> *__last, PStringBase<char> __val)
{
  PStringBase<char> *v3; // ebx@1
  PSRefBufferCharData<char> *v4; // ebp@1
  PSRefBufferCharData<char> *v5; // eax@2
  int v6; // esi@3
  PStringBase<char> v7; // ST0C_4@7

  v3 = __first;
  v4 = __val.m_charbuffer;
  if ( strcmp(__val.m_charbuffer->m_data, __first->m_charbuffer->m_data) >= 0 )
  {
    v7.m_charbuffer = __val.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&__val.m_charbuffer[-1]);
    _STL::__unguarded_linear_insert(__last, v7);
  }
  else
  {
    _STL::__copy_backward(__first, __last, __last + 1);
    v5 = v3->m_charbuffer;
    if ( v3->m_charbuffer != v4 )
    {
      v6 = (int)&v5[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      v3->m_charbuffer = v4;
      InterlockedIncrement((volatile LONG *)&v4[-1]);
    }
  }
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v4 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&v4[-2].m_data[12])(&v4[-2].m_data[12], 1);
}

//----- (00433760) --------------------------------------------------------  // acclient.c:112947
void __cdecl _STL::sort_heap(PStringBase<char> *__first, PStringBase<char> *__last)
{
  PStringBase<char> *v2; // esi@2
  PStringBase<char> v3; // ST0C_4@3

  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 4 )
  {
    v2 = __last - 1;
    do
    {
      v3.m_charbuffer = v2->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v2->m_charbuffer[-1]);
      _STL::__pop_heap(__first, v2, v2, v3);
      --v2;
    }
    while ( (signed int)((unsigned int)((char *)v2 + 4 - (_DWORD)__first) & 0xFFFFFFFC) > 4 );
  }
}

//----- (004337C0) --------------------------------------------------------  // acclient.c:112967
void __cdecl _STL::__insertion_sort(PStringBase<char> *__first, PStringBase<char> *__last)
{
  PStringBase<char> *i; // esi@2
  PStringBase<char> v3; // ST08_4@3

  if ( __first != __last )
  {
    for ( i = __first + 1; i != __last; ++i )
    {
      v3.m_charbuffer = i->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&i->m_charbuffer[-1]);
      _STL::__linear_insert(__first, i, v3);
    }
  }
}

//----- (00433810) --------------------------------------------------------  // acclient.c:112984
void __cdecl _STL::__partial_sort(PStringBase<char> *__first, PStringBase<char> *__middle, PStringBase<char> *__last)
{
  PStringBase<char> *v3; // ebp@1
  PStringBase<char> v4; // edi@2

  v3 = __middle;
  _STL::__make_heap(__first, __middle);
  if ( __middle < __last )
  {
    do
    {
      v4.m_charbuffer = v3->m_charbuffer;
      if ( strcmp(v3->m_charbuffer->m_data, __first->m_charbuffer->m_data) < 0 )
      {
        InterlockedIncrement((volatile LONG *)&v4.m_charbuffer[-1]);
        _STL::__pop_heap(__first, __middle, v3, v4);
      }
      ++v3;
    }
    while ( v3 < __last );
    v3 = __middle;
  }
  _STL::sort_heap(__first, v3);
}

//----- (004338C0) --------------------------------------------------------  // acclient.c:113010
HashTable<PStringBase<char>,GRPCommand *,0> *__thiscall HashTable<PStringBase<char>,GRPCommand *,0>::scalar_deleting_destructor(HashTable<PStringBase<char>,GRPCommand *,0> *this, unsigned int a2)
{
  HashTable<PStringBase<char>,GRPCommand *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<PStringBase<char>,GRPCommand *,0>Vtbl *)HashTable<PStringBase<char>,GRPCommand *,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::vftable;
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
// 7984F4: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::vftable[2])(void *, char);
// 79854C: using guessed type int (__thiscall *HashTable<PStringBase<char>,GRPCommand *,0>::vftable[2])(void *, char);

//----- (00433920) --------------------------------------------------------  // acclient.c:113036
HashTable<PStringBase<char>,GRPObject *,0> *__thiscall HashTable<PStringBase<char>,GRPObject *,0>::vector_deleting_destructor(HashTable<PStringBase<char>,GRPObject *,0> *this, unsigned int a2)
{
  HashTable<PStringBase<char>,GRPObject *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<PStringBase<char>,GRPObject *,0>Vtbl *)&HashTable<PStringBase<char>,GRPObject *,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::vftable;
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
// 7984F8: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::vftable)(void *, char);
// 798550: using guessed type int (__thiscall *HashTable<PStringBase<char>,GRPObject *,0>::vftable)(void *, char);

//----- (00433980) --------------------------------------------------------  // acclient.c:113062
void __cdecl _STL::__introsort_loop(PStringBase<char> *__first, PStringBase<char> *__last, PStringBase<char> *__formal, int __depth_limit, _STL::less<PStringBase<char> > __comp)
{
  PStringBase<char> *v5; // edi@1
  PStringBase<char> v6; // ST1C_4@3
  PStringBase<char> *v7; // esi@3

  v5 = __last;
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v6.m_charbuffer = _STL::__median(__first, &__first[(v5 - __first) / 2], v5 - 1)->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v6.m_charbuffer[-1]);
      v7 = _STL::__unguarded_partition(__first, v5, v6);
      _STL::__introsort_loop(v7, v5, 0, __depth_limit, __comp);
      v5 = v7;
      if ( (signed int)(((char *)v7 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    _STL::__partial_sort(__first, v5, v5);
  }
}

//----- (00433A20) --------------------------------------------------------  // acclient.c:113087
void __thiscall GlobalRegistryInstance::GlobalRegistryInstance(GlobalRegistryInstance *this)
{
  GlobalRegistryInstance *v1; // esi@1

  v1 = this;
  this->m_Characters.m_nStartIndex = 0;
  this->m_Characters.m_nEndIndex = 0;
  this->m_Characters.m_nNumElements = 0;
  this->m_CommandHash.vfptr = (HashTable<PStringBase<char>,GRPCommand *,0>Vtbl *)HashTable<PStringBase<char>,GRPCommand *,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>(
    &this->m_CommandHash.m_intrusiveTable,
    0x17u);
  v1->m_ObjectHash.vfptr = (HashTable<PStringBase<char>,GRPObject *,0>Vtbl *)&HashTable<PStringBase<char>,GRPObject *,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>(
    &v1->m_ObjectHash.m_intrusiveTable,
    0x17u);
  v1->m_ConsoleCallbackObjects.m_data = 0;
  v1->m_ConsoleCallbackObjects.m_sizeAndDeallocate = 0;
  v1->m_ConsoleCallbackObjects.m_num = 0;
}
// 79854C: using guessed type int (__thiscall *HashTable<PStringBase<char>,GRPCommand *,0>::vftable[2])(void *, char);
// 798550: using guessed type int (__thiscall *HashTable<PStringBase<char>,GRPObject *,0>::vftable)(void *, char);

//----- (00433A80) --------------------------------------------------------  // acclient.c:113111
void __thiscall GlobalRegistryInstance::~GlobalRegistryInstance(GlobalRegistryInstance *this)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v1; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v2; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // edi@1
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // ebx@1
  HeritageGroup_CGVtbl *v5; // ebp@5
  int v6; // edi@6
  int v7; // edi@9
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // edi@13
  HashTableData<unsigned long,HeritageGroup_CG> **v9; // ecx@13
  HashTableData<unsigned long,HeritageGroup_CG> *v10; // eax@17
  HashTableData<unsigned long,HeritageGroup_CG> *v11; // edx@18
  int v12; // edi@23
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v13; // eax@32
  HashTableData<unsigned long,HeritageGroup_CG> *v14; // edi@32
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v15; // ecx@32
  HashTableData<unsigned long,HeritageGroup_CG> **v16; // ebp@32
  HeritageGroup_CGVtbl *v17; // ebx@33
  int v18; // esi@34
  int v19; // esi@37
  GlobalRegistryInstance *v20; // esi@45
  int v21; // ecx@45
  HashTableData<PStringBase<char>,GRPObject *> **v22; // eax@46
  int v23; // eax@47
  HashTableData<PStringBase<char>,GRPObject *> **v24; // eax@48
  HashTableData<PStringBase<char>,GRPObject *> *v25; // edi@48
  HashTableData<PStringBase<char>,GRPObject *> **v26; // ebp@50
  GRPObject *v27; // ebx@51
  int v28; // esi@52
  int v29; // esi@55
  unsigned int v30; // eax@63
  unsigned int v31; // edx@63
  int i; // eax@66
  int v33; // esi@70
  void *v34; // eax@70
  void *v35; // eax@72
  GlobalRegistryInstance *v36; // [sp+10h] [bp-20h]@1
  void *v37; // [sp+14h] [bp-1Ch]@13
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *ObjectIter; // [sp+18h] [bp-18h]@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *ObjectItera; // [sp+18h] [bp-18h]@32
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+24h] [bp-Ch]@1

  v36 = this;
  v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_ObjectHash.m_intrusiveTable,
         &result);
  v2 = v1->m_currElement;
  v3 = v1->m_currHashTable;
  v4 = v1->m_currBucket;
  ObjectIter = v1->m_currHashTable;
  if ( v2 )
  {
    do
    {
      while ( (*((int (**)(void))v2->m_data.vfptr->Serialize + 15))() )
      {
        v5 = v2->m_data.vfptr;
        if ( v5 )
        {
          v6 = (int)((char *)v5[2].Serialize - 20);
          if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
          v7 = (int)((char *)v5[1].Serialize - 20);
          if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
          operator delete(v5);
        }
        v2->m_data.vfptr = 0;
        v8 = v2->m_hashNext;
        v37 = v2;
        v9 = v4;
        if ( !v8 )
        {
          while ( 1 )
          {
            ++v9;
            if ( v9 == &ObjectIter->m_buckets[ObjectIter->m_numBuckets] )
              break;
            if ( *v9 )
            {
              v8 = *v9;
              break;
            }
          }
        }
        v10 = *v4;
        if ( *v4 == v2 )
          goto LABEL_77;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v2 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_77:
          *v4 = v10->m_hashNext;
        --ObjectIter->m_numElements;
        v2 = v8;
        v4 = v9;
        if ( v37 )
        {
          v12 = *(_DWORD *)v37 - 20;
          if ( !InterlockedDecrement((volatile LONG *)(v12 + 4)) && v12 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
          operator delete(v37);
        }
LABEL_31:
        if ( !v2 )
          goto LABEL_32;
        v3 = ObjectIter;
      }
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    while ( 1 )
    {
      ++v4;
      if ( v4 == &v3->m_buckets[v3->m_numBuckets] )
        break;
      if ( *v4 )
      {
        v2 = *v4;
        goto LABEL_31;
      }
    }
  }
LABEL_32:
  v13 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v36->m_CommandHash.m_intrusiveTable,
          &result);
  v14 = v13->m_currElement;
  v15 = v13->m_currHashTable;
  v16 = v13->m_currBucket;
  ObjectItera = v13->m_currHashTable;
  if ( v14 )
  {
    do
    {
LABEL_33:
      v17 = v14->m_data.vfptr;
      if ( v17 )
      {
        v18 = (int)((char *)v17[2].Serialize - 20);
        if ( !InterlockedDecrement((volatile LONG *)(v18 + 4)) && v18 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
        v19 = (int)((char *)v17[1].Serialize - 20);
        if ( !InterlockedDecrement((volatile LONG *)(v19 + 4)) && v19 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
        operator delete(v17);
        v15 = ObjectItera;
      }
      v14->m_data.vfptr = 0;
      v14 = v14->m_hashNext;
    }
    while ( v14 );
    while ( 1 )
    {
      ++v16;
      if ( v16 == &v15->m_buckets[v15->m_numBuckets] )
        break;
      if ( *v16 )
      {
        v14 = *v16;
        if ( *v16 )
          goto LABEL_33;
        break;
      }
    }
  }
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&v36->m_CommandHash.m_intrusiveTable);
  v20 = v36;
  v21 = (int)&v36->m_ObjectHash.m_intrusiveTable.m_buckets[v36->m_ObjectHash.m_intrusiveTable.m_numBuckets];
  if ( v36->m_ObjectHash.m_intrusiveTable.m_firstInterestingBucket == (HashTableData<PStringBase<char>,GRPObject *> **)v21 )
  {
LABEL_48:
    v24 = 0;
    v25 = 0;
  }
  else
  {
    while ( 1 )
    {
      v22 = v36->m_ObjectHash.m_intrusiveTable.m_firstInterestingBucket;
      if ( *v22 )
        break;
      v23 = (int)(v22 + 1);
      v36->m_ObjectHash.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<PStringBase<char>,GRPObject *> **)v23;
      if ( v23 == v21 )
        goto LABEL_48;
    }
    v24 = v36->m_ObjectHash.m_intrusiveTable.m_firstInterestingBucket;
    v25 = *v24;
  }
  v26 = v24;
  if ( v25 )
  {
    do
    {
LABEL_51:
      v27 = v25->m_data;
      if ( v27 )
      {
        v28 = (int)&v27->m_Description.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)(v28 + 4)) && v28 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v28)(v28, 1);
        v29 = (int)&v27->m_Name.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)(v29 + 4)) && v29 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v29)(v29, 1);
        operator delete(v27);
        v20 = v36;
      }
      v25->m_data = 0;
      v25 = v25->m_hashNext;
    }
    while ( v25 );
    while ( 1 )
    {
      ++v26;
      if ( v26 == &v20->m_ObjectHash.m_intrusiveTable.m_buckets[v20->m_ObjectHash.m_intrusiveTable.m_numBuckets] )
        break;
      if ( *v26 )
      {
        v25 = *v26;
        if ( *v26 )
          goto LABEL_51;
        break;
      }
    }
  }
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&v20->m_ObjectHash.m_intrusiveTable);
  v30 = v20->m_ConsoleCallbackObjects.m_sizeAndDeallocate;
  v31 = v20->m_ConsoleCallbackObjects.m_sizeAndDeallocate & 0x80000000;
  v20->m_ConsoleCallbackObjects.m_num = 0;
  if ( v31 == 0x80000000 )
  {
    operator delete[](v20->m_ConsoleCallbackObjects.m_data);
    v20->m_ConsoleCallbackObjects.m_data = 0;
    v20->m_ConsoleCallbackObjects.m_sizeAndDeallocate = 0;
  }
  else if ( v20->m_ConsoleCallbackObjects.m_data )
  {
    for ( i = (v30 & 0x7FFFFFFF) - 1; i >= 0; v20->m_ConsoleCallbackObjects.m_data[i + 1] = 0 )
      --i;
  }
  if ( (v20->m_ConsoleCallbackObjects.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v20->m_ConsoleCallbackObjects.m_data);
  v20->m_ObjectHash.vfptr = (HashTable<PStringBase<char>,GRPObject *,0>Vtbl *)&HashTable<PStringBase<char>,GRPObject *,0>::vftable;
  v33 = (int)&v20->m_ObjectHash.m_intrusiveTable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v33);
  v34 = *(void **)(v33 + 96);
  *(_DWORD *)v33 = &IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::vftable;
  if ( v34 != (void *)(v33 + 4) )
    operator delete[](v34);
  *(_DWORD *)(v33 + 96) = 0;
  *(_DWORD *)(v33 + 100) = 0;
  *(_DWORD *)(v33 + 104) = 0;
  *(_DWORD *)(v33 + 108) = 0;
  v36->m_CommandHash.vfptr = (HashTable<PStringBase<char>,GRPCommand *,0>Vtbl *)HashTable<PStringBase<char>,GRPCommand *,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&v36->m_CommandHash.m_intrusiveTable);
  v35 = v36->m_CommandHash.m_intrusiveTable.m_buckets;
  v36->m_CommandHash.m_intrusiveTable.vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>Vtbl *)IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::vftable;
  if ( v35 != v36->m_CommandHash.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v35);
  v36->m_CommandHash.m_intrusiveTable.m_buckets = 0;
  v36->m_CommandHash.m_intrusiveTable.m_firstInterestingBucket = 0;
  v36->m_CommandHash.m_intrusiveTable.m_numBuckets = 0;
  v36->m_CommandHash.m_intrusiveTable.m_numElements = 0;
}
// 7984F4: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::vftable[2])(void *, char);
// 7984F8: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::vftable)(void *, char);
// 79854C: using guessed type int (__thiscall *HashTable<PStringBase<char>,GRPCommand *,0>::vftable[2])(void *, char);
// 798550: using guessed type int (__thiscall *HashTable<PStringBase<char>,GRPObject *,0>::vftable)(void *, char);

//----- (00433E80) --------------------------------------------------------  // acclient.c:113389
char __cdecl GlobalRegistryInstance::ConsoleCommand_Dump(PStringBaseArray<char> *_Args)
{
  PSRefBufferCharData<char> *v1; // ecx@0
  PStringBase<char> **v2; // esi@1
  GlobalRegistryInstance *v4; // eax@3
  char v5; // bl@3
  GlobalRegistryInstance *v6; // eax@4
  int v7; // esi@9
  char *v8; // esi@10
  char *v9; // esi@13
  LONG v10; // eax@13
  PStringBase<char> ValueString; // [sp+8h] [bp-4h]@1

  ValueString.m_charbuffer = v1;
  v2 = (PStringBase<char> **)_Args;
  if ( _Args->m_num < 1 )
    return 0;
  v4 = GlobalRegistry::s_pcGlobalRegistry;
  v5 = 1;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v6 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v6 )
      GlobalRegistryInstance::GlobalRegistryInstance(v6);
    else
      v4 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v4;
  }
  if ( !GlobalRegistryInstance::FindObjectByName(v4, *v2, (GRPObject **)&_Args) )
  {
    _Args = (PStringBaseArray<char> *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::sprintf((PStringBase<char> *)&_Args, "Unrecognized object: %s\n\n", (*v2)->m_charbuffer);
    GlobalRegistry::OutputText((PStringBase<char> *)&_Args);
    v9 = (char *)&_Args[-2].m_sizeAndDeallocate;
    v5 = 0;
    v10 = InterlockedDecrement((volatile LONG *)&_Args[-2].m_sizeAndDeallocate + 1);
LABEL_15:
    if ( !v10 )
    {
      if ( v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    }
    return v5;
  }
  v7 = ((int (*)(void))_Args->m_data[13].m_charbuffer)();
  if ( v7 )
  {
    ValueString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    (*(void (__thiscall **)(int, PStringBase<char> *))(*(_DWORD *)v7 + 76))(v7, &ValueString);
    _Args = (PStringBaseArray<char> *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::sprintf(
      (PStringBase<char> *)&_Args,
      "%s == %s\n\n",
      *(_DWORD *)(v7 + 4),
      ValueString.m_charbuffer);
    GlobalRegistry::OutputText((PStringBase<char> *)&_Args);
    v8 = (char *)&_Args[-2].m_sizeAndDeallocate;
    if ( !InterlockedDecrement((volatile LONG *)&_Args[-2].m_sizeAndDeallocate + 1) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    v9 = &ValueString.m_charbuffer[-2].m_data[12];
    v10 = InterlockedDecrement((volatile LONG *)&ValueString.m_charbuffer[-1]);
    goto LABEL_15;
  }
  return v5;
}

//----- (00433FD0) --------------------------------------------------------  // acclient.c:113459
char __cdecl GlobalRegistryInstance::ConsoleCommand_Set(PStringBaseArray<char> *_Args)
{
  PStringBaseArray<char> *v1; // ebp@1
  unsigned int v2; // eax@1
  GlobalRegistryInstance *v4; // eax@5
  GlobalRegistryInstance *v5; // eax@6
  int v6; // ebx@11
  void (__stdcall *v7)(volatile LONG *); // esi@12
  signed int v8; // edi@12
  PSRefBufferCharData<char> *v9; // ecx@14
  int v10; // eax@14
  int v11; // esi@16
  const char *v12; // eax@19
  int v13; // ecx@19
  LONG (__stdcall *v14)(volatile LONG *); // edi@24
  char *v15; // esi@24
  char *v16; // esi@27
  char *v17; // esi@29
  LONG v18; // eax@29
  char *v19; // esi@30
  PStringBase<char> Params; // [sp+14h] [bp-Ch]@12
  PStringBase<char> Msg; // [sp+18h] [bp-8h]@24
  PStringBase<char> ValueString; // [sp+1Ch] [bp-4h]@10

  v1 = _Args;
  v2 = _Args->m_num;
  if ( v2 < 1 )
    return 0;
  if ( v2 == 1 )
    return GlobalRegistryInstance::ConsoleCommand_Dump(_Args);
  v4 = GlobalRegistry::s_pcGlobalRegistry;
  LOBYTE(_Args) = 1;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v5 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v5 )
      GlobalRegistryInstance::GlobalRegistryInstance(v5);
    else
      v4 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v4;
  }
  if ( !GlobalRegistryInstance::FindObjectByName(v4, v1->m_data, (GRPObject **)&ValueString) )
  {
    ValueString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::sprintf(&ValueString, "Unrecognized object: %s\n\n", v1->m_data->m_charbuffer);
    GlobalRegistry::OutputText(&ValueString);
    v17 = &ValueString.m_charbuffer[-2].m_data[12];
    LOBYTE(_Args) = 0;
    v18 = InterlockedDecrement((volatile LONG *)&ValueString.m_charbuffer[-1]);
    goto LABEL_36;
  }
  v6 = (*(int (**)(void))(*(_DWORD *)&ValueString.m_charbuffer->m_data[0] + 52))();
  if ( v6 )
  {
    v7 = (void (__stdcall *)(volatile LONG *))InterlockedIncrement;
    Params.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v8 = 1;
    if ( v1->m_num > 1 )
    {
      do
      {
        if ( (unsigned int)v8 > 1 )
        {
          PStringBase<char>::PStringBase<char>(&ValueString, " ");
          v9 = ValueString.m_charbuffer;
          v10 = *(_DWORD *)&ValueString.m_charbuffer[-1].m_data[12];
          if ( v10 != 1 )
          {
            PStringBase<char>::append_n_chars(&Params, ValueString.m_charbuffer->m_data, v10 - 1);
            v9 = ValueString.m_charbuffer;
          }
          v11 = (int)&v9[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) && v11 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
        }
        v12 = v1->m_data[v8].m_charbuffer->m_data;
        v13 = *((_DWORD *)v12 - 1);
        if ( v13 != 1 )
          PStringBase<char>::append_n_chars(&Params, v12, v13 - 1);
        ++v8;
      }
      while ( v8 < v1->m_num );
      v7 = (void (__stdcall *)(volatile LONG *))InterlockedIncrement;
    }
    if ( (unsigned __int8)(*(int (__thiscall **)(int, PStringBase<char> *))(*(_DWORD *)v6 + 80))(v6, &Params) )
    {
      ValueString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      v7((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      (*(void (__thiscall **)(int, PStringBase<char> *))(*(_DWORD *)v6 + 76))(v6, &ValueString);
      Msg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      v7((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PStringBase<char>::sprintf(&Msg, "%s = %s\n\n", *(_DWORD *)(v6 + 4), ValueString.m_charbuffer);
      GlobalRegistry::OutputText(&Msg);
      v14 = InterlockedDecrement;
      v15 = &Msg.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&Msg.m_charbuffer[-1]) && v15 )
        (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
      v16 = &ValueString.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&ValueString.m_charbuffer[-1]) && v16 )
      {
        (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
        v17 = &Params.m_charbuffer[-2].m_data[12];
        v18 = InterlockedDecrement((volatile LONG *)&Params.m_charbuffer[-1]);
        goto LABEL_36;
      }
    }
    else
    {
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&_Args,
        "Error setting variable.  Make sure your value is appropriate for this variable's type.\n");
      GlobalRegistry::OutputText((PStringBase<char> *)&_Args);
      v19 = (char *)&_Args[-2].m_sizeAndDeallocate;
      if ( !InterlockedDecrement((volatile LONG *)&_Args[-2].m_sizeAndDeallocate + 1) && v19 )
        (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
      v14 = InterlockedDecrement;
      LOBYTE(_Args) = 0;
    }
    v17 = &Params.m_charbuffer[-2].m_data[12];
    v18 = v14((volatile LONG *)&Params.m_charbuffer[-1]);
LABEL_36:
    if ( !v18 )
    {
      if ( v17 )
        (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
    }
  }
  return (char)_Args;
}

//----- (00434260) --------------------------------------------------------  // acclient.c:113592
char __cdecl GlobalRegistryInstance::ConsoleCommand_Toggle(PStringBaseArray<char> *_Args)
{
  PStringBase<char> **v1; // esi@1
  char result; // al@2
  GlobalRegistryInstance *v3; // eax@3
  GlobalRegistryInstance *v4; // eax@4
  int v5; // eax@9
  int v6; // esi@9
  char *v7; // esi@13
  PStringBase<char> Msg; // [sp+4h] [bp-8h]@11
  PStringBase<char> ValueString; // [sp+8h] [bp-4h]@11

  v1 = (PStringBase<char> **)_Args;
  if ( _Args->m_num < 1 )
    return 0;
  v3 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v4 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v4 )
      GlobalRegistryInstance::GlobalRegistryInstance(v4);
    else
      v3 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v3;
  }
  if ( !GlobalRegistryInstance::FindObjectByName(v3, *v1, (GRPObject **)&_Args) )
  {
    _Args = (PStringBaseArray<char> *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::sprintf((PStringBase<char> *)&_Args, "Unrecognized object: %s\n\n", (*v1)->m_charbuffer);
    GlobalRegistry::OutputText((PStringBase<char> *)&_Args);
    v7 = (char *)&_Args[-2].m_sizeAndDeallocate;
    if ( !InterlockedDecrement((volatile LONG *)&_Args[-2].m_sizeAndDeallocate + 1) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    return 0;
  }
  v5 = ((int (*)(void))_Args->m_data[17].m_charbuffer)();
  v6 = v5;
  if ( !v5 )
    return 0;
  if ( *(_DWORD *)(v5 + 16) == 2 )
  {
    LOBYTE(_Args) = **(_BYTE **)(v5 + 12) == 0;
    GRPTypedVariableObject::SetVariable((GRPTypedVariableObject *)v5, (const bool *)&_Args);
    ValueString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    (*(void (__thiscall **)(int, PStringBase<char> *))(*(_DWORD *)v6 + 76))(v6, &ValueString);
    Msg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::sprintf(&Msg, "%s = %s\n\n", *(_DWORD *)(v6 + 4), ValueString.m_charbuffer);
    GlobalRegistry::OutputText(&Msg);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&Msg);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ValueString);
    result = 1;
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&_Args,
      "The variable's data type is not supported by this function.\n");
    GlobalRegistry::OutputText((PStringBase<char> *)&_Args);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_Args);
    result = 0;
  }
  return result;
}

//----- (004343F0) --------------------------------------------------------  // acclient.c:113660
char __cdecl GlobalRegistryInstance::ConsoleCommand_ListCommands()
{
  char *v0; // esi@1
  GlobalRegistryInstance *v1; // eax@4
  PStringBase<char> *v2; // ebp@4
  GlobalRegistryInstance *v3; // eax@5
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // eax@9
  HashTableData<PStringBase<char>,GRPCommand *> **v5; // edi@9
  HashTableData<PStringBase<char>,GRPCommand *> *v6; // esi@9
  GlobalRegistryInstance *v7; // eax@10
  GlobalRegistryInstance *v8; // eax@11
  GRPCommand *v9; // ebx@14
  unsigned int v10; // eax@14
  unsigned int v11; // edx@15
  bool v17; // al@23
  HashTableData<PStringBase<char>,GRPCommand *> **v18; // eax@26
  PStringBase<char> *v19; // edi@30
  signed int v20; // esi@31
  signed int v21; // eax@31
  int i; // ecx@31
  unsigned int v23; // edi@36
  PStringBase<char> *v24; // esi@37
  char *v25; // esi@39
  PSRefBufferCharData<char> *v26; // eax@44
  void *v27; // ebx@44
  int v28; // edi@44
  int v29; // eax@44
  int v30; // ebp@45
  int v31; // esi@46
  int v32; // esi@46
  PStringBase<char> _Text; // [sp+10h] [bp-28h]@1
  PStringBaseArray<char> OutputStrings; // [sp+14h] [bp-24h]@4
  HashIterator<PStringBase<char>,GRPCommand *,0> CommandIter; // [sp+20h] [bp-18h]@9
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+2Ch] [bp-Ch]@9

  PStringBase<char>::PStringBase<char>(&_Text, "Listing available commands:\n\n");
  GlobalRegistry::OutputText(&_Text);
  v0 = &_Text.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Text.m_charbuffer[-1]) && v0 )
    (**(void (__thiscall ***)(char *, signed int))v0)(v0, 1);
  v1 = GlobalRegistry::s_pcGlobalRegistry;
  v2 = 0;
  OutputStrings.m_data = 0;
  OutputStrings.m_sizeAndDeallocate = 0;
  OutputStrings.m_num = 0;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v3 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v3 )
      GlobalRegistryInstance::GlobalRegistryInstance(v3);
    else
      v1 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v1;
  }
  v4 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v1->m_CommandHash.m_intrusiveTable,
         &result);
  v5 = (HashTableData<PStringBase<char>,GRPCommand *> **)v4->m_currBucket;
  v6 = (HashTableData<PStringBase<char>,GRPCommand *> *)v4->m_currElement;
  CommandIter.m_iter.m_currHashTable = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0> *)v4->m_currHashTable;
  CommandIter.m_iter.m_currBucket = v5;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v7 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v7 )
    {
      GlobalRegistryInstance::GlobalRegistryInstance(v7);
      GlobalRegistry::s_pcGlobalRegistry = v8;
    }
    else
    {
      GlobalRegistry::s_pcGlobalRegistry = 0;
    }
  }
  if ( v6 )
  {
    do
    {
LABEL_14:
      v9 = v6->m_data;
      v10 = OutputStrings.m_sizeAndDeallocate & 0x7FFFFFFF;
      if ( OutputStrings.m_num < (OutputStrings.m_sizeAndDeallocate & 0x7FFFFFFF) )
        goto LABEL_54;
      v11 = v10 + 1;
      if ( v10 + 1 > 8 )
      {
        if ( v11 <= 0x4000 )
        {
          _Text.m_charbuffer = (PSRefBufferCharData<char> *)(v10 + 1);
          __asm { bsr     eax, [esp+38h+_Text.m_charbuffer] }
          if ( v11 > 1 << _EAX )
            v11 = 2 * (1 << _EAX);
          v5 = CommandIter.m_iter.m_currBucket;
        }
        else if ( v11 & 0x3FFF )
        {
          v11 += 0x4000 - (v11 & 0x3FFF);
        }
      }
      else
      {
        v11 = 8;
      }
      v17 = SmartArray<PStringBase<char>,1>::grow((SmartArray<PStringBase<char>,1> *)&OutputStrings.m_data, v11);
      v2 = OutputStrings.m_data;
      if ( v17 )
LABEL_54:
        ++OutputStrings.m_num;
      PStringBase<char>::sprintf(
        &v2[OutputStrings.m_num - 1],
        "%s - %s\n",
        v9->m_Name.m_charbuffer,
        v9->m_Description.m_charbuffer);
      v6 = v6->m_hashNext;
    }
    while ( v6 );
    v18 = &CommandIter.m_iter.m_currHashTable->m_buckets[CommandIter.m_iter.m_currHashTable->m_numBuckets];
    while ( 1 )
    {
      ++v5;
      CommandIter.m_iter.m_currBucket = v5;
      if ( v5 == v18 )
        break;
      if ( *v5 )
      {
        v6 = *v5;
        if ( *v5 )
          goto LABEL_14;
        break;
      }
    }
  }
  v19 = &v2[OutputStrings.m_num];
  if ( v2 != v19 )
  {
    v20 = (signed int)(4 * OutputStrings.m_num) >> 2;
    v21 = (signed int)(4 * OutputStrings.m_num) >> 2;
    for ( i = 0; v21 != 1; ++i )
      v21 >>= 1;
    _STL::__introsort_loop(v2, &v2[OutputStrings.m_num], 0, 2 * i, (_STL::less<PStringBase<char> >)_Text.m_charbuffer);
    if ( v20 <= 16 )
    {
      _STL::__insertion_sort(v2, v19);
    }
    else
    {
      _STL::__insertion_sort(v2, v2 + 16);
      _STL::__unguarded_insertion_sort_aux(v2 + 16, v19);
    }
  }
  v23 = OutputStrings.m_num;
  if ( OutputStrings.m_num )
  {
    v24 = v2;
    do
    {
      GlobalRegistry::OutputText(v24);
      ++v24;
      --v23;
    }
    while ( v23 );
  }
  PStringBase<char>::allocate_ref_buffer(&_Text, strlen("\n"));
  strcpy(_Text.m_charbuffer->m_data, "\n");
  GlobalRegistry::OutputText(&_Text);
  v25 = &_Text.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Text.m_charbuffer[-1]) && v25 )
    (**(void (__thiscall ***)(char *, signed int))v25)(v25, 1);
  if ( (OutputStrings.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && v2 )
  {
    v26 = v2[-1].m_charbuffer;
    v27 = &v2[-1];
    v28 = (int)&v2[(_DWORD)v26];
    v29 = (int)&v26[-1].m_data[15];
    if ( v29 >= 0 )
    {
      v30 = v29 + 1;
      do
      {
        v31 = *(_DWORD *)(v28 - 4);
        v28 -= 4;
        v32 = v31 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v32 + 4)) && v32 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v32)(v32, 1);
        --v30;
      }
      while ( v30 );
    }
    operator delete[](v27);
  }
  return 1;
}

//----- (004346D0) --------------------------------------------------------  // acclient.c:113854
char __cdecl GlobalRegistryInstance::ConsoleCommand_ListObjects()
{
  char *v0; // esi@1
  GlobalRegistryInstance *v1; // eax@4
  PStringBase<char> *v2; // ebp@4
  GlobalRegistryInstance *v3; // eax@5
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // eax@9
  HashTableData<PStringBase<char>,GRPObject *> **v5; // edi@9
  HashTableData<PStringBase<char>,GRPObject *> *v6; // esi@9
  GlobalRegistryInstance *v7; // eax@10
  GlobalRegistryInstance *v8; // eax@11
  GRPObject *v9; // ebx@14
  unsigned int v10; // eax@14
  unsigned int v11; // edx@15
  bool v17; // al@23
  HashTableData<PStringBase<char>,GRPObject *> **v18; // eax@26
  PStringBase<char> *v19; // edi@30
  signed int v20; // esi@31
  signed int v21; // eax@31
  int i; // ecx@31
  unsigned int v23; // edi@36
  PStringBase<char> *v24; // esi@37
  char *v25; // esi@39
  PSRefBufferCharData<char> *v26; // eax@44
  void *v27; // ebx@44
  int v28; // edi@44
  int v29; // eax@44
  int v30; // ebp@45
  int v31; // esi@46
  int v32; // esi@46
  PStringBase<char> _Text; // [sp+10h] [bp-28h]@1
  PStringBaseArray<char> OutputStrings; // [sp+14h] [bp-24h]@4
  HashIterator<PStringBase<char>,GRPObject *,0> ObjectIter; // [sp+20h] [bp-18h]@9
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+2Ch] [bp-Ch]@9

  PStringBase<char>::PStringBase<char>(&_Text, "Listing available objects:\n\n");
  GlobalRegistry::OutputText(&_Text);
  v0 = &_Text.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Text.m_charbuffer[-1]) && v0 )
    (**(void (__thiscall ***)(char *, signed int))v0)(v0, 1);
  v1 = GlobalRegistry::s_pcGlobalRegistry;
  v2 = 0;
  OutputStrings.m_data = 0;
  OutputStrings.m_sizeAndDeallocate = 0;
  OutputStrings.m_num = 0;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v3 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v3 )
      GlobalRegistryInstance::GlobalRegistryInstance(v3);
    else
      v1 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v1;
  }
  v4 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v1->m_ObjectHash.m_intrusiveTable,
         &result);
  v5 = (HashTableData<PStringBase<char>,GRPObject *> **)v4->m_currBucket;
  v6 = (HashTableData<PStringBase<char>,GRPObject *> *)v4->m_currElement;
  ObjectIter.m_iter.m_currHashTable = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0> *)v4->m_currHashTable;
  ObjectIter.m_iter.m_currBucket = v5;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v7 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v7 )
    {
      GlobalRegistryInstance::GlobalRegistryInstance(v7);
      GlobalRegistry::s_pcGlobalRegistry = v8;
    }
    else
    {
      GlobalRegistry::s_pcGlobalRegistry = 0;
    }
  }
  if ( v6 )
  {
    do
    {
LABEL_14:
      v9 = v6->m_data;
      v10 = OutputStrings.m_sizeAndDeallocate & 0x7FFFFFFF;
      if ( OutputStrings.m_num < (OutputStrings.m_sizeAndDeallocate & 0x7FFFFFFF) )
        goto LABEL_54;
      v11 = v10 + 1;
      if ( v10 + 1 > 8 )
      {
        if ( v11 <= 0x4000 )
        {
          _Text.m_charbuffer = (PSRefBufferCharData<char> *)(v10 + 1);
          __asm { bsr     eax, [esp+38h+_Text.m_charbuffer] }
          if ( v11 > 1 << _EAX )
            v11 = 2 * (1 << _EAX);
          v5 = ObjectIter.m_iter.m_currBucket;
        }
        else if ( v11 & 0x3FFF )
        {
          v11 += 0x4000 - (v11 & 0x3FFF);
        }
      }
      else
      {
        v11 = 8;
      }
      v17 = SmartArray<PStringBase<char>,1>::grow((SmartArray<PStringBase<char>,1> *)&OutputStrings.m_data, v11);
      v2 = OutputStrings.m_data;
      if ( v17 )
LABEL_54:
        ++OutputStrings.m_num;
      PStringBase<char>::sprintf(
        &v2[OutputStrings.m_num - 1],
        "%s - %s\n",
        v9->m_Name.m_charbuffer,
        v9->m_Description.m_charbuffer);
      v6 = v6->m_hashNext;
    }
    while ( v6 );
    v18 = &ObjectIter.m_iter.m_currHashTable->m_buckets[ObjectIter.m_iter.m_currHashTable->m_numBuckets];
    while ( 1 )
    {
      ++v5;
      ObjectIter.m_iter.m_currBucket = v5;
      if ( v5 == v18 )
        break;
      if ( *v5 )
      {
        v6 = *v5;
        if ( *v5 )
          goto LABEL_14;
        break;
      }
    }
  }
  v19 = &v2[OutputStrings.m_num];
  if ( v2 != v19 )
  {
    v20 = (signed int)(4 * OutputStrings.m_num) >> 2;
    v21 = (signed int)(4 * OutputStrings.m_num) >> 2;
    for ( i = 0; v21 != 1; ++i )
      v21 >>= 1;
    _STL::__introsort_loop(v2, &v2[OutputStrings.m_num], 0, 2 * i, (_STL::less<PStringBase<char> >)_Text.m_charbuffer);
    if ( v20 <= 16 )
    {
      _STL::__insertion_sort(v2, v19);
    }
    else
    {
      _STL::__insertion_sort(v2, v2 + 16);
      _STL::__unguarded_insertion_sort_aux(v2 + 16, v19);
    }
  }
  v23 = OutputStrings.m_num;
  if ( OutputStrings.m_num )
  {
    v24 = v2;
    do
    {
      GlobalRegistry::OutputText(v24);
      ++v24;
      --v23;
    }
    while ( v23 );
  }
  PStringBase<char>::allocate_ref_buffer(&_Text, strlen("\n"));
  strcpy(_Text.m_charbuffer->m_data, "\n");
  GlobalRegistry::OutputText(&_Text);
  v25 = &_Text.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Text.m_charbuffer[-1]) && v25 )
    (**(void (__thiscall ***)(char *, signed int))v25)(v25, 1);
  if ( (OutputStrings.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && v2 )
  {
    v26 = v2[-1].m_charbuffer;
    v27 = &v2[-1];
    v28 = (int)&v2[(_DWORD)v26];
    v29 = (int)&v26[-1].m_data[15];
    if ( v29 >= 0 )
    {
      v30 = v29 + 1;
      do
      {
        v31 = *(_DWORD *)(v28 - 4);
        v28 -= 4;
        v32 = v31 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v32 + 4)) && v32 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v32)(v32, 1);
        --v30;
      }
      while ( v30 );
    }
    operator delete[](v27);
  }
  return 1;
}

//----- (004349B0) --------------------------------------------------------  // acclient.c:114048
bool __cdecl GlobalRegistryInstance::ConsoleCommand_Help(PStringBaseArray<char> *_Args)
{
  GRPCommand *v1; // ecx@0
  PStringBase<char> **v2; // esi@1
  char v3; // bl@1
  bool result; // al@4
  GlobalRegistryInstance *v5; // eax@6
  GlobalRegistryInstance *v6; // eax@7
  char v7; // al@11
  GRPCommand *v8; // esi@12
  int v9; // eax@14
  int v10; // eax@15
  char *v11; // esi@17
  char *v12; // esi@20
  LONG v13; // eax@20
  GRPCommand *pFoundCommand; // [sp+0h] [bp-4h]@1

  pFoundCommand = v1;
  v2 = (PStringBase<char> **)_Args;
  v3 = 1;
  if ( _Args->m_num )
  {
    v5 = GlobalRegistry::s_pcGlobalRegistry;
    if ( !GlobalRegistry::s_pcGlobalRegistry )
    {
      v6 = (GlobalRegistryInstance *)operator new(0x8100u);
      if ( v6 )
        GlobalRegistryInstance::GlobalRegistryInstance(v6);
      else
        v5 = 0;
      GlobalRegistry::s_pcGlobalRegistry = v5;
    }
    v7 = GlobalRegistryInstance::FindCommandByName(v5, *v2, &pFoundCommand);
    _Args = (PStringBaseArray<char> *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    if ( v7 )
    {
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      v8 = pFoundCommand;
      PStringBase<char>::sprintf((PStringBase<char> *)&_Args, "         Name: %s\n", pFoundCommand->m_Name.m_charbuffer);
      GlobalRegistry::OutputText((PStringBase<char> *)&_Args);
      if ( *(_DWORD *)&v8->m_Description.m_charbuffer[-1].m_data[12] != 1 )
      {
        PStringBase<char>::sprintf((PStringBase<char> *)&_Args, "  Description: %s\n", v8->m_Description.m_charbuffer);
        GlobalRegistry::OutputText((PStringBase<char> *)&_Args);
      }
      v9 = (int)v8->vfptr->AsWithArgsCommand((GRPGeneric *)v8);
      if ( v9 )
      {
        v10 = *(_DWORD *)(v9 + 12);
        if ( *(_DWORD *)(v10 - 4) != 1 )
        {
          PStringBase<char>::sprintf((PStringBase<char> *)&_Args, "        Usage: %s\n\n", v10);
          GlobalRegistry::OutputText((PStringBase<char> *)&_Args);
        }
      }
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&pFoundCommand, "\n");
      GlobalRegistry::OutputText((PStringBase<char> *)&pFoundCommand);
      v11 = (char *)&pFoundCommand[-2].m_Name;
      if ( !InterlockedDecrement((volatile LONG *)&pFoundCommand[-2].m_Name + 1) && v11 )
        (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
      v12 = (char *)&_Args[-2].m_sizeAndDeallocate;
      v13 = InterlockedDecrement((volatile LONG *)&_Args[-2].m_sizeAndDeallocate + 1);
    }
    else
    {
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PStringBase<char>::sprintf(
        (PStringBase<char> *)&_Args,
        "Can't provide help for unrecognized command: %s\n\n",
        (*v2)->m_charbuffer);
      GlobalRegistry::OutputText((PStringBase<char> *)&_Args);
      v12 = (char *)&_Args[-2].m_sizeAndDeallocate;
      v3 = 0;
      v13 = InterlockedDecrement((volatile LONG *)&_Args[-2].m_sizeAndDeallocate + 1);
    }
    if ( !v13 && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    result = v3;
  }
  else
  {
    result = GlobalRegistryInstance::ConsoleCommand_ListCommands()
          && GlobalRegistryInstance::ConsoleCommand_ListObjects();
  }
  return result;
}

//----- (00434B60) --------------------------------------------------------  // acclient.c:114136
void __thiscall GlobalRegistryCommands::GlobalRegistryCommands(GlobalRegistryCommands *this)
{
  char *v1; // edi@1
  char *v2; // edi@4
  char *v3; // edi@7
  char *v4; // edi@10
  char *v5; // edi@13
  char *v6; // edi@16
  char *v7; // edi@19
  char *v8; // edi@22
  char *v9; // edi@25
  char *v10; // edi@28
  char *v11; // edi@31
  char *v12; // edi@34
  char *v13; // edi@37
  char *v14; // edi@40
  char *v15; // edi@43
  char *v16; // edi@46
  char *v17; // edi@49
  PStringBase<char> _Name; // [sp+3Ch] [bp-Ch]@1
  PStringBase<char> _Description; // [sp+40h] [bp-8h]@1
  PStringBase<char> _Usage; // [sp+44h] [bp-4h]@13

  this->vfptr = (InterfaceVtbl *)&GlobalRegistryCommands::vftable;
  PStringBase<char>::PStringBase<char>(&_Description, "Displays a list of each command with a brief description");
  PStringBase<char>::PStringBase<char>(&_Name, "ListCommands");
  GlobalRegistry::RegisterCommand(
    (bool (__cdecl *)())GlobalRegistryInstance::ConsoleCommand_ListCommands,
    &_Name,
    &_Description);
  v1 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v1 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
  v2 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Displays a list of each object with a brief description");
  PStringBase<char>::PStringBase<char>(&_Description, "ListObjects");
  GlobalRegistry::RegisterCommand(
    (bool (__cdecl *)())GlobalRegistryInstance::ConsoleCommand_ListObjects,
    &_Description,
    &_Name);
  v3 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  PStringBase<char>::PStringBase<char>(
    &_Usage,
    "Help [command name]  (if you omit the command name, a list of available commands will be provided.)");
  PStringBase<char>::PStringBase<char>(&_Name, "Displays description and usage information for commands and variables");
  PStringBase<char>::PStringBase<char>(&_Description, "Help");
  GlobalRegistry::RegisterCommand(GlobalRegistryInstance::ConsoleCommand_Help, &_Description, &_Name, &_Usage);
  v5 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v6 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v7 = &_Usage.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Usage.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Dump <object name>");
  PStringBase<char>::PStringBase<char>(&_Description, "Displays information about an object");
  PStringBase<char>::PStringBase<char>(&_Usage, "Dump");
  GlobalRegistry::RegisterCommand(
    (bool (__cdecl *)(PStringBaseArray<char> *))GlobalRegistryInstance::ConsoleCommand_Dump,
    &_Usage,
    &_Description,
    &_Name);
  v8 = &_Usage.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Usage.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  v9 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  v10 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Set <object name> [component name] <data>");
  PStringBase<char>::PStringBase<char>(&_Description, "Sets the contents of an object");
  PStringBase<char>::PStringBase<char>(&_Usage, "Set");
  GlobalRegistry::RegisterCommand(
    (bool (__cdecl *)(PStringBaseArray<char> *))GlobalRegistryInstance::ConsoleCommand_Set,
    &_Usage,
    &_Description,
    &_Name);
  v11 = &_Usage.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Usage.m_charbuffer[-1]) && v11 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
  v12 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  v13 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Toggle <object name>");
  PStringBase<char>::PStringBase<char>(&_Description, "Toggles the contents of a boolean variable");
  PStringBase<char>::PStringBase<char>(&_Usage, "Toggle");
  GlobalRegistry::RegisterCommand(
    (bool (__cdecl *)(PStringBaseArray<char> *))GlobalRegistryInstance::ConsoleCommand_Toggle,
    &_Usage,
    &_Description,
    &_Name);
  v14 = &_Usage.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Usage.m_charbuffer[-1]) && v14 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  v15 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v15 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
  v16 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v16 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
  PStringBase<char>::PStringBase<char>(&_Usage, "Console initialized.\n\n");
  GlobalRegistry::OutputText(&_Usage);
  v17 = &_Usage.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Usage.m_charbuffer[-1]) )
  {
    if ( v17 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  }
}
// 798534: using guessed type __int32 (__stdcall *GlobalRegistryCommands::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00434F10) --------------------------------------------------------  // acclient.c:114262
unsigned int __thiscall RefCountInterface<GlobalRegistryCommands>::Release(RefCountInterface<GlobalRegistryCommands> *this)
{
  return ReferenceCountTemplate<1048576,0>::Release((ReferenceCountTemplate<1048576,0> *)&this->vfptr);
}

//----- (00434F20) --------------------------------------------------------  // acclient.c:114268
int __thiscall RefCountInterface<GlobalRegistryCommands>::vector_deleting_destructor(RefCountInterface<GlobalRegistryCommands> *this, char a2)
{
  RefCountInterface<GlobalRegistryCommands> *v2; // esi@1
  int result; // eax@1

  v2 = this;
  RefCountInterface<GlobalRegistryCommands>::~RefCountInterface<GlobalRegistryCommands>(this);
  result = (int)&v2[-1].m_cRef;
  if ( a2 & 1 )
  {
    operator delete(&v2[-1].m_cRef);
    result = (int)&v2[-1].m_cRef;
  }
  return result;
}

//----- (00434F50) --------------------------------------------------------  // acclient.c:114285
void __thiscall RefCountInterface<GlobalRegistryCommands>::~RefCountInterface<GlobalRegistryCommands>(RefCountInterface<GlobalRegistryCommands> *this)
{
  this->vfptr = (InterfaceVtbl *)&RefCountInterface<GlobalRegistryCommands>::vftable;
  this[-1].m_cRef = (unsigned int)&RefCountInterface<GlobalRegistryCommands>::vftable;
  *(_DWORD *)(this != (RefCountInterface<GlobalRegistryCommands> *)4 ? (unsigned int)this : 0) = TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  GlobalRegistryCommands::~GlobalRegistryCommands((GlobalRegistryCommands *)&this[-1].m_cRef);
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 7988E8: using guessed type int (__stdcall *RefCountInterface<GlobalRegistryCommands>::vftable)(char);
// 7988EC: using guessed type __int32 (__stdcall *RefCountInterface<GlobalRegistryCommands>::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00434F80) --------------------------------------------------------  // acclient.c:114297
void __thiscall ClassRegistrarGlobalRegistryCommands_ClassType::ClassRegistrarGlobalRegistryCommands_ClassType(ClassRegistrarGlobalRegistryCommands_ClassType *this)
{
  GlobalRegistryCommands *v1; // eax@1
  GlobalRegistryCommands *v2; // esi@1
  InterfaceSystem *v3; // eax@2
  TResult result; // [sp+0h] [bp-4h]@1

  result.m_val = (unsigned int)this;
  v1 = (GlobalRegistryCommands *)operator new(0xCu);
  v2 = v1;
  if ( v1 )
  {
    GlobalRegistryCommands::GlobalRegistryCommands(v1);
    v2[1].vfptr = (InterfaceVtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
    v2[2].vfptr = (InterfaceVtbl *)1;
    v2->vfptr = (InterfaceVtbl *)&RefCountInterface<GlobalRegistryCommands>::vftable;
    v2[1].vfptr = (InterfaceVtbl *)&RefCountInterface<GlobalRegistryCommands>::vftable;
    v3 = InterfaceSystem::GetInstance();
    InterfaceSystem::RegisterClassA(v3, &result, &GlobalRegistryCommands_ClassType_3, (Interface *)&v2->vfptr, 0);
    v2->vfptr->Release((Interface *)v2);
  }
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 7988E8: using guessed type int (__stdcall *RefCountInterface<GlobalRegistryCommands>::vftable)(char);
// 7988EC: using guessed type __int32 (__stdcall *RefCountInterface<GlobalRegistryCommands>::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006C5C60) --------------------------------------------------------  // acclient.c:734081
int _E73_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_4, "None");
  return atexit(_E74_28);
}

//----- (006C5C80) --------------------------------------------------------  // acclient.c:734088
int _E76_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_4, "Speed");
  return atexit(_E77_44);
}

//----- (006C5CA0) --------------------------------------------------------  // acclient.c:734095
int _E79_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_4, "Noise");
  return atexit(_E80_18);
}

//----- (006C5CC0) --------------------------------------------------------  // acclient.c:734102
int _E82_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_4, "Sine");
  return atexit(_E83_8);
}

//----- (006C5CE0) --------------------------------------------------------  // acclient.c:734109
int _E85_4()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_4, "Square");
  return atexit(_E86_5);
}

//----- (006C5D00) --------------------------------------------------------  // acclient.c:734116
int _E88_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_4, "Bounce");
  return atexit(_E89_16);
}

//----- (006C5D20) --------------------------------------------------------  // acclient.c:734123
int _E91_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_4, "Perlin");
  return atexit(_E92_14);
}

//----- (006C5D40) --------------------------------------------------------  // acclient.c:734130
int _E94_4()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_4, "Fractal");
  return atexit(sub_728A10);
}

//----- (006C5D60) --------------------------------------------------------  // acclient.c:734137
int _E97_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_4, "FrameLoop");
  return atexit(_E98_29);
}

//----- (006C5D80) --------------------------------------------------------  // acclient.c:734144
void _E100_8()
{
  ClassRegistrarGlobalRegistryCommands_ClassType::ClassRegistrarGlobalRegistryCommands_ClassType((ClassRegistrarGlobalRegistryCommands_ClassType *)&s_ClassRegistrarGlobalRegistryCommands_ClassType);
}

//----- (007288C0) --------------------------------------------------------  // acclient.c:826411
void __cdecl _E74_28()
{
  char *v0; // esi@1

  v0 = &waveform_None_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007288F0) --------------------------------------------------------  // acclient.c:826424
void __cdecl _E77_44()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728920) --------------------------------------------------------  // acclient.c:826437
void __cdecl _E80_18()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728950) --------------------------------------------------------  // acclient.c:826450
void __cdecl _E83_8()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728980) --------------------------------------------------------  // acclient.c:826463
void __cdecl _E86_5()
{
  char *v0; // esi@1

  v0 = &waveform_Square_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007289B0) --------------------------------------------------------  // acclient.c:826476
void __cdecl _E89_16()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007289E0) --------------------------------------------------------  // acclient.c:826489
void __cdecl _E92_14()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728A10) --------------------------------------------------------  // acclient.c:826502
void __cdecl sub_728A10()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728A40) --------------------------------------------------------  // acclient.c:826515
void __cdecl _E98_29()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

