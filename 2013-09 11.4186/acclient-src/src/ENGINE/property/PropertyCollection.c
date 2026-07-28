/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PropertyCollection
   Object     : ENGINE\property\PropertyCollection.obj
   Functions  : 43
   Addresses  : 0067F940 - 00715480 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0067F940) --------------------------------------------------------  // acclient.c:662731
BaseProperty *__cdecl _STL::__copy_backward(BaseProperty *__first, BaseProperty *__last, BaseProperty *__result)
{
  int v3; // edi@1
  BaseProperty *v4; // esi@2
  signed int v5; // ebx@2
  BaseProperty *result; // eax@4

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
      v3 -= 8;
      --v4;
      BaseProperty::operator=(v4, v3);
      --v5;
    }
    while ( v5 );
    result = v4;
  }
  return result;
}

//----- (0067F980) --------------------------------------------------------  // acclient.c:662761
bool __stdcall PropertyGroupNameSort::operator()(const unsigned int _lhs, const unsigned int _rhs)
{
  bool v3; // bl@3
  char *v4; // esi@3
  char *v5; // esi@6
  bool result; // al@9
  char *v7; // esi@10
  char *v8; // esi@13
  PStringBase<char> strRHS; // [sp+8h] [bp-8h]@1
  PStringBase<char> strLHS; // [sp+Ch] [bp-4h]@1

  strLHS.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  strRHS.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( MasterProperty::InqPropertyGroupNameStringStatic(_lhs, &strLHS)
    && MasterProperty::InqPropertyGroupNameStringStatic(_rhs, &strRHS) )
  {
    v3 = __stricmp(strLHS.m_charbuffer->m_data, strRHS.m_charbuffer->m_data) < 0;
    v4 = &strRHS.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strRHS.m_charbuffer[-1]) && v4 )
      (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    v5 = &strLHS.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strLHS.m_charbuffer[-1]) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
    }
    result = v3;
  }
  else
  {
    v7 = &strRHS.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strRHS.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    v8 = &strLHS.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strLHS.m_charbuffer[-1]) && v8 )
      (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
    result = 0;
  }
  return result;
}

//----- (0067FA90) --------------------------------------------------------  // acclient.c:662805
bool __stdcall BasePropertyNameSort::operator()(BaseProperty *_lhs, BaseProperty *_rhs)
{
  bool v3; // bl@3
  char *v4; // esi@3
  char *v5; // esi@6
  bool result; // al@9
  char *v7; // esi@10
  char *v8; // esi@13
  PStringBase<char> strRHS; // [sp+8h] [bp-8h]@1
  PStringBase<char> strLHS; // [sp+Ch] [bp-4h]@1

  strLHS.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  strRHS.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( BaseProperty::InqPropertyName(_lhs, &strLHS) && BaseProperty::InqPropertyName(_rhs, &strRHS) )
  {
    v3 = __stricmp(strLHS.m_charbuffer->m_data, strRHS.m_charbuffer->m_data) < 0;
    v4 = &strRHS.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strRHS.m_charbuffer[-1]) && v4 )
      (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    v5 = &strLHS.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strLHS.m_charbuffer[-1]) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
    }
    result = v3;
  }
  else
  {
    v7 = &strRHS.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strRHS.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    v8 = &strLHS.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strLHS.m_charbuffer[-1]) && v8 )
      (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
    result = 0;
  }
  return result;
}

//----- (0067FB90) --------------------------------------------------------  // acclient.c:662848
const unsigned int *__cdecl _STL::__median(const unsigned int *__a, const unsigned int *__b, const unsigned int *__c)
{
  const unsigned int *result; // eax@4
  bool v4; // zf@7

  if ( PropertyGroupNameSort::operator()(*__a, *__b) )
  {
    if ( !PropertyGroupNameSort::operator()(*__b, *__c) )
    {
      if ( PropertyGroupNameSort::operator()(*__a, *__c) )
        return __c;
      return __a;
    }
    return __b;
  }
  if ( PropertyGroupNameSort::operator()(*__a, *__c) )
    return __a;
  v4 = PropertyGroupNameSort::operator()(*__b, *__c) == 0;
  result = __c;
  if ( v4 )
    return __b;
  return result;
}

//----- (0067FC20) --------------------------------------------------------  // acclient.c:662873
unsigned int *__cdecl _STL::__unguarded_partition(unsigned int *__first, unsigned int *__last, unsigned int __pivot)
{
  unsigned int *v3; // esi@1
  unsigned int *v4; // edi@1
  const unsigned int v5; // ecx@3
  const unsigned int v6; // edx@4
  const unsigned int v7; // eax@5
  const unsigned int v8; // eax@7

  v3 = __first;
  v4 = __last;
  while ( 1 )
  {
    if ( PropertyGroupNameSort::operator()(*v3, __pivot) )
    {
      do
      {
        v5 = v3[1];
        ++v3;
      }
      while ( PropertyGroupNameSort::operator()(v5, __pivot) );
    }
    v6 = *(v4 - 1);
    --v4;
    if ( PropertyGroupNameSort::operator()(__pivot, v6) )
    {
      do
      {
        v7 = *(v4 - 1);
        --v4;
      }
      while ( PropertyGroupNameSort::operator()(__pivot, v7) );
    }
    if ( v3 >= v4 )
      break;
    v8 = *v3;
    *v3 = *v4;
    *v4 = v8;
    ++v3;
  }
  return v3;
}

//----- (0067FCA0) --------------------------------------------------------  // acclient.c:662917
void __cdecl _STL::__unguarded_linear_insert(unsigned int *__last, unsigned int __val)
{
  unsigned int *v2; // edi@1
  unsigned int *v3; // esi@1
  const unsigned int v4; // edx@2

  v2 = __last;
  v3 = __last - 1;
  if ( PropertyGroupNameSort::operator()(__val, *(__last - 1)) )
  {
    do
    {
      *v2 = *v3;
      v4 = *(v3 - 1);
      v2 = v3;
      --v3;
    }
    while ( PropertyGroupNameSort::operator()(__val, v4) );
  }
  *v2 = __val;
}

//----- (0067FCF0) --------------------------------------------------------  // acclient.c:662940
void __cdecl _STL::__unguarded_linear_insert(BaseProperty *__last, BaseProperty __val)
{
  BaseProperty *v2; // edi@1
  BaseProperty *i; // esi@1
  BasePropertyDesc *v4; // ecx@4
  unsigned int v5; // edx@4
  BasePropertyValue *v6; // ecx@8
  unsigned int v7; // edx@8

  v2 = __last;
  for ( i = __last - 1; BasePropertyNameSort::operator()(&__val, i); --i )
  {
    BaseProperty::operator=(v2, (int)i);
    v2 = i;
  }
  BaseProperty::operator=(v2, (int)&__val);
  if ( (_DWORD)__val.m_pcPropertyDesc )
  {
    v4 = __val.m_pcPropertyDesc;
    v5 = __val.m_pcPropertyDesc->m_cRef - 1;
    __val.m_pcPropertyDesc->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    __val.m_pcPropertyDesc = 0;
  }
  if ( __val.m_pcPropertyValue )
  {
    v6 = __val.m_pcPropertyValue;
    v7 = __val.m_pcPropertyValue->m_cRef - 1;
    __val.m_pcPropertyValue->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
  }
}

//----- (0067FD90) --------------------------------------------------------  // acclient.c:662976
void __cdecl _STL::__push_heap(unsigned int *__first, int __holeIndex, int __topIndex, unsigned int __val)
{
  int v4; // edi@1
  int v5; // esi@1

  v4 = __holeIndex;
  v5 = (__holeIndex - 1) / 2;
  if ( __holeIndex <= __topIndex )
  {
    __first[__holeIndex] = __val;
  }
  else
  {
    do
    {
      if ( !PropertyGroupNameSort::operator()(__first[v5], __val) )
        break;
      __first[v4] = __first[v5];
      v4 = v5;
      v5 = (v5 - 1) / 2;
    }
    while ( v4 > __topIndex );
    __first[v4] = __val;
  }
}

//----- (0067FE00) --------------------------------------------------------  // acclient.c:663003
void __cdecl _STL::__push_heap(BaseProperty *__first, int __holeIndex, int __topIndex, BaseProperty __val)
{
  int v4; // edi@1
  int i; // esi@1
  BasePropertyDesc *v6; // ecx@5
  unsigned int v7; // edx@5
  BasePropertyValue *v8; // ecx@9
  unsigned int v9; // edx@9

  v4 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v4 > __topIndex; i = (i - 1) / 2 )
  {
    if ( !BasePropertyNameSort::operator()(&__first[i], &__val) )
      break;
    BaseProperty::operator=(&__first[v4], (int)&__first[i]);
    v4 = i;
  }
  BaseProperty::operator=(&__first[v4], (int)&__val);
  if ( (_DWORD)__val.m_pcPropertyDesc )
  {
    v6 = __val.m_pcPropertyDesc;
    v7 = __val.m_pcPropertyDesc->m_cRef - 1;
    __val.m_pcPropertyDesc->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
    __val.m_pcPropertyDesc = 0;
  }
  if ( __val.m_pcPropertyValue )
  {
    v8 = __val.m_pcPropertyValue;
    v9 = __val.m_pcPropertyValue->m_cRef - 1;
    __val.m_pcPropertyValue->m_cRef = v9;
    if ( !v9 )
      ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
  }
}

//----- (0067FEB0) --------------------------------------------------------  // acclient.c:663041
void __thiscall PropertyCollection::GetSubDataIDs(PropertyCollection *this, QualifiedDataIDArray *_id_array)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@1

  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_hashProperties.m_intrusiveTable,
         &result);
  v3 = v2->m_currElement;
  v4 = v2->m_currHashTable;
  v5 = v2->m_currBucket;
  if ( v3 )
  {
    do
    {
LABEL_2:
      BaseProperty::GetSubDataIDs((BaseProperty *)&v3->m_data, _id_array);
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
          goto LABEL_2;
        return;
      }
    }
  }
}

//----- (0067FF10) --------------------------------------------------------  // acclient.c:663081
BaseProperty *__cdecl _STL::__unguarded_partition(BaseProperty *__first, BaseProperty *__last, BaseProperty __pivot)
{
  BaseProperty *v3; // esi@1
  BaseProperty *i; // edi@1
  BasePropertyDesc *v5; // ecx@9
  unsigned int v6; // edx@9
  BasePropertyValue *v7; // ecx@12
  bool v8; // zf@13

  v3 = __last;
  for ( i = __first; ; ++i )
  {
    for ( ; BasePropertyNameSort::operator()(i, &__pivot); ++i )
      ;
    for ( --v3; BasePropertyNameSort::operator()(&__pivot, v3); --v3 )
      ;
    if ( i >= v3 )
      break;
    _STL::swap(i, v3);
  }
  if ( (_DWORD)__pivot.m_pcPropertyDesc )
  {
    v5 = __pivot.m_pcPropertyDesc;
    v6 = __pivot.m_pcPropertyDesc->m_cRef - 1;
    __pivot.m_pcPropertyDesc->m_cRef = v6;
    if ( !v6 )
      ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
    __pivot.m_pcPropertyDesc = 0;
  }
  v7 = __pivot.m_pcPropertyValue;
  if ( __pivot.m_pcPropertyValue )
  {
    v8 = __pivot.m_pcPropertyValue->m_cRef-- == 1;
    if ( v8 )
      ((void (__stdcall *)(signed int))v7->vfptr->__vecDelDtor)(1);
  }
  return i;
}

//----- (0067FFE0) --------------------------------------------------------  // acclient.c:663121
void __cdecl _STL::__unguarded_insertion_sort_aux(unsigned int *__first, unsigned int *__last)
{
  unsigned int *i; // ebp@1
  const unsigned int v3; // ebx@2
  int v4; // esi@2
  unsigned int *v5; // edi@2
  const unsigned int v6; // edx@3

  for ( i = __first; i != __last; *v5 = v3 )
  {
    v3 = *i;
    v4 = (int)(i - 1);
    v5 = i;
    if ( PropertyGroupNameSort::operator()(*i, *(i - 1)) )
    {
      do
      {
        *v5 = *(_DWORD *)v4;
        v6 = *(_DWORD *)(v4 - 4);
        v5 = (unsigned int *)v4;
        v4 -= 4;
      }
      while ( PropertyGroupNameSort::operator()(v3, v6) );
    }
    ++i;
  }
}

//----- (00680040) --------------------------------------------------------  // acclient.c:663150
void __cdecl _STL::__unguarded_insertion_sort_aux(BaseProperty *__first, BaseProperty *__last, BaseProperty *__formal, int __comp)
{
  BaseProperty *i; // esi@1
  BaseProperty v5; // [sp-Ch] [bp-18h]@2
  int v6; // [sp-4h] [bp-10h]@2

  for ( i = __first; i != __last; ++i )
  {
    v6 = __comp;
    v5 = 0i64;
    BaseProperty::operator=(&v5, (int)i);
    _STL::__unguarded_linear_insert(i, v5);
  }
}

//----- (00680080) --------------------------------------------------------  // acclient.c:663166
void __cdecl _STL::__adjust_heap(unsigned int *__first, int __holeIndex, int __len, unsigned int __val)
{
  int v4; // edi@1
  int v5; // esi@1
  bool i; // zf@1

  v4 = __holeIndex;
  v5 = 2 * __holeIndex + 2;
  for ( i = v5 == __len; v5 < __len; i = v5 == __len )
  {
    if ( PropertyGroupNameSort::operator()(__first[v5], __first[v5 - 1]) )
      --v5;
    __first[v4] = __first[v5];
    v4 = v5;
    v5 = 2 * v5 + 2;
  }
  if ( i )
  {
    __first[v4] = __first[v5 - 1];
    v4 = v5 - 1;
  }
  _STL::__push_heap(__first, v4, __holeIndex, __val);
}

//----- (00680100) --------------------------------------------------------  // acclient.c:663191
void __cdecl _STL::__adjust_heap(BaseProperty *__first, int __holeIndex, int __len, BaseProperty __val, BasePropertyNameSort __comp)
{
  int v5; // edi@1
  int v6; // esi@1
  bool i; // zf@1
  BasePropertyDesc *v8; // ecx@8
  unsigned int v9; // edx@8
  ReferenceCountTemplate<1048576,1>Vtbl *v10; // edx@9
  BasePropertyValue *v11; // ecx@12
  unsigned int v12; // edx@12
  ReferenceCountTemplate<1048576,1>Vtbl *v13; // eax@13
  BaseProperty v14; // [sp-Ch] [bp-1Ch]@7
  signed int v15; // [sp-4h] [bp-14h]@7

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  for ( i = v6 == __len; v6 < __len; i = v6 == __len )
  {
    if ( BasePropertyNameSort::operator()(&__first[v6], &__first[v6 - 1]) )
      --v6;
    BaseProperty::operator=(&__first[v5], (int)&__first[v6]);
    v5 = v6;
    v6 = 2 * v6 + 2;
  }
  if ( i )
  {
    BaseProperty::operator=(&__first[v5], (int)&__first[v6 - 1]);
    v5 = v6 - 1;
  }
  v15 = *(_DWORD *)&__comp;
  v14 = 0i64;
  BaseProperty::operator=(&v14, (int)&__val);
  _STL::__push_heap(__first, v5, __holeIndex, v14);
  if ( (_DWORD)__val.m_pcPropertyDesc )
  {
    v8 = __val.m_pcPropertyDesc;
    v9 = __val.m_pcPropertyDesc->m_cRef - 1;
    __val.m_pcPropertyDesc->m_cRef = v9;
    if ( !v9 )
    {
      v10 = v8->vfptr;
      v15 = 1;
      ((void (__stdcall *)(_DWORD))v10->__vecDelDtor)(1);
    }
    __val.m_pcPropertyDesc = 0;
  }
  if ( __val.m_pcPropertyValue )
  {
    v11 = __val.m_pcPropertyValue;
    v12 = __val.m_pcPropertyValue->m_cRef - 1;
    __val.m_pcPropertyValue->m_cRef = v12;
    if ( !v12 )
    {
      v13 = v11->vfptr;
      v15 = 1;
      ((void (__stdcall *)(_DWORD))v13->__vecDelDtor)(1);
    }
  }
}

//----- (006801D0) --------------------------------------------------------  // acclient.c:663252
void __cdecl _STL::__insertion_sort(unsigned int *__first, unsigned int *__last)
{
  unsigned int *v2; // esi@2
  size_t v3; // edi@3
  unsigned int v4; // ebp@4

  if ( __first != __last )
  {
    v2 = __first + 1;
    if ( __first + 1 != __last )
    {
      v3 = 4;
      do
      {
        v4 = *v2;
        if ( PropertyGroupNameSort::operator()(*v2, *__first) )
        {
          if ( (signed int)v3 > 0 )
            _memmove(&v2[-v3 / 4 + 1], __first, v3);
          *__first = v4;
        }
        else
        {
          _STL::__unguarded_linear_insert(v2, v4);
        }
        ++v2;
        v3 += 4;
      }
      while ( v2 != __last );
    }
  }
}

//----- (00680240) --------------------------------------------------------  // acclient.c:663286
void __cdecl _STL::__linear_insert(BaseProperty *__first, BaseProperty *__last, BaseProperty __val, BasePropertyNameSort __comp)
{
  BasePropertyDesc *v4; // ecx@5
  unsigned int v5; // edx@5
  ReferenceCountTemplate<1048576,1>Vtbl *v6; // edx@6
  BasePropertyValue *v7; // ecx@9
  unsigned int v8; // edx@9
  ReferenceCountTemplate<1048576,1>Vtbl *v9; // eax@10
  BaseProperty v10; // [sp-Ch] [bp-10h]@3
  BaseProperty *v11; // [sp-8h] [bp-Ch]@2
  signed int v12; // [sp-4h] [bp-8h]@3

  if ( BasePropertyNameSort::operator()(&__val, __first) )
  {
    v11 = &__val;
    _STL::__copy_backward(__first, __last, __last + 1);
    BaseProperty::operator=(__first, (int)&__val);
  }
  else
  {
    v12 = *(_DWORD *)&__comp;
    v10 = 0i64;
    BaseProperty::operator=(&v10, (int)&__val);
    _STL::__unguarded_linear_insert(__last, v10);
  }
  if ( (_DWORD)__val.m_pcPropertyDesc )
  {
    v4 = __val.m_pcPropertyDesc;
    v5 = __val.m_pcPropertyDesc->m_cRef - 1;
    __val.m_pcPropertyDesc->m_cRef = v5;
    if ( !v5 )
    {
      v6 = v4->vfptr;
      v12 = 1;
      ((void (__stdcall *)(_DWORD))v6->__vecDelDtor)(1);
    }
    __val.m_pcPropertyDesc = 0;
  }
  if ( __val.m_pcPropertyValue )
  {
    v7 = __val.m_pcPropertyValue;
    v8 = __val.m_pcPropertyValue->m_cRef - 1;
    __val.m_pcPropertyValue->m_cRef = v8;
    if ( !v8 )
    {
      v9 = v7->vfptr;
      v12 = 1;
      ((void (__stdcall *)(_DWORD))v9->__vecDelDtor)(1);
    }
  }
}

//----- (00680300) --------------------------------------------------------  // acclient.c:663339
void __cdecl _STL::__pop_heap(BaseProperty *__first, BaseProperty *__last, BaseProperty *__result, BaseProperty __val, BasePropertyNameSort __comp)
{
  BasePropertyDesc *v5; // ecx@2
  unsigned int v6; // edx@2
  ReferenceCountTemplate<1048576,1>Vtbl *v7; // edx@3
  BasePropertyValue *v8; // ecx@6
  unsigned int v9; // edx@6
  ReferenceCountTemplate<1048576,1>Vtbl *v10; // eax@7
  BaseProperty v11; // [sp-Ch] [bp-10h]@1
  signed int v12; // [sp-4h] [bp-8h]@1

  BaseProperty::operator=(__result, (int)__first);
  v12 = *(_DWORD *)&__comp;
  v11 = 0i64;
  BaseProperty::operator=(&v11, (int)&__val);
  _STL::__adjust_heap(__first, 0, __last - __first, v11, (BasePropertyNameSort)v12);
  if ( (_DWORD)__val.m_pcPropertyDesc )
  {
    v5 = __val.m_pcPropertyDesc;
    v6 = __val.m_pcPropertyDesc->m_cRef - 1;
    __val.m_pcPropertyDesc->m_cRef = v6;
    if ( !v6 )
    {
      v7 = v5->vfptr;
      v12 = 1;
      ((void (__stdcall *)(_DWORD))v7->__vecDelDtor)(1);
    }
    __val.m_pcPropertyDesc = 0;
  }
  if ( __val.m_pcPropertyValue )
  {
    v8 = __val.m_pcPropertyValue;
    v9 = __val.m_pcPropertyValue->m_cRef - 1;
    __val.m_pcPropertyValue->m_cRef = v9;
    if ( !v9 )
    {
      v10 = v8->vfptr;
      v12 = 1;
      ((void (__stdcall *)(_DWORD))v10->__vecDelDtor)(1);
    }
  }
}

//----- (00680390) --------------------------------------------------------  // acclient.c:663383
void __cdecl _STL::__make_heap(unsigned int *__first, unsigned int *__last)
{
  int v2; // ebx@1
  int v3; // esi@2
  unsigned int v4; // ecx@3

  v2 = __last - __first;
  if ( v2 >= 2 )
  {
    v3 = (v2 - 2) / 2;
    _STL::__adjust_heap(__first, v3, __last - __first, __first[v3]);
    while ( v3 )
    {
      v4 = __first[v3-- - 1];
      _STL::__adjust_heap(__first, v3, v2, v4);
    }
  }
}

//----- (006803F0) --------------------------------------------------------  // acclient.c:663403
void __cdecl _STL::__make_heap(BaseProperty *__first, BaseProperty *__last, int __comp)
{
  int v3; // edi@1
  int v4; // esi@2
  int i; // ebx@2
  BaseProperty v6; // [sp-Ch] [bp-1Ch]@3
  int v7; // [sp-4h] [bp-14h]@3

  v3 = __last - __first;
  if ( v3 >= 2 )
  {
    v4 = (v3 - 2) / 2;
    for ( i = (int)&__first[v4]; ; i -= 8 )
    {
      v7 = __comp;
      v6 = 0i64;
      BaseProperty::operator=(&v6, i);
      _STL::__adjust_heap(__first, v4, v3, v6, (BasePropertyNameSort)v7);
      if ( !v4 )
        break;
      --v4;
    }
  }
}

//----- (00680450) --------------------------------------------------------  // acclient.c:663429
void __cdecl _STL::__insertion_sort(BaseProperty *__first, BaseProperty *__last, int __comp)
{
  BaseProperty *i; // esi@2
  BaseProperty v4; // [sp-Ch] [bp-1Ch]@3
  int v5; // [sp-4h] [bp-14h]@3

  if ( __first != __last )
  {
    for ( i = __first + 1; i != __last; ++i )
    {
      v5 = __comp;
      v4 = 0i64;
      BaseProperty::operator=(&v4, (int)i);
      _STL::__linear_insert(__first, i, v4, (BasePropertyNameSort)v5);
    }
  }
}

//----- (006804A0) --------------------------------------------------------  // acclient.c:663448
void __cdecl _STL::sort_heap(unsigned int *__first, unsigned int *__last)
{
  signed int v2; // eax@1
  unsigned int v3; // ecx@2
  int v4; // edi@2

  v2 = (char *)__last - (char *)__first;
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v3 = *(unsigned int *)((char *)__first + v2 - 4);
      v4 = v2 - 4;
      *(unsigned int *)((char *)__first + v2 - 4) = *__first;
      _STL::__adjust_heap(__first, 0, (v2 - 4) >> 2, v3);
      v2 = v4;
    }
    while ( (signed int)(v4 & 0xFFFFFFFC) > 4 );
  }
}

//----- (006804F0) --------------------------------------------------------  // acclient.c:663470
void __cdecl _STL::sort_heap(BaseProperty *__first, BaseProperty *__last, int __comp)
{
  BaseProperty *v3; // esi@2
  BaseProperty v4; // [sp-10h] [bp-20h]@3
  int v5; // [sp-8h] [bp-18h]@3
  int v6; // [sp-4h] [bp-14h]@3

  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFF8) > 8 )
  {
    v3 = __last - 1;
    do
    {
      v6 = 0;
      v5 = __comp;
      v4 = 0i64;
      BaseProperty::operator=(&v4, (int)v3);
      _STL::__pop_heap(__first, v3, v3, v4, (BasePropertyNameSort)v5);
      --v3;
    }
    while ( (signed int)((unsigned int)((char *)v3 + 8 - (_DWORD)__first) & 0xFFFFFFF8) > 8 );
  }
}

//----- (00680550) --------------------------------------------------------  // acclient.c:663494
void __cdecl _STL::__partial_sort(unsigned int *__first, unsigned int *__middle, unsigned int *__last)
{
  unsigned int *i; // esi@1
  unsigned int v4; // ST0C_4@3

  _STL::__make_heap(__first, __middle);
  for ( i = __middle; i < __last; ++i )
  {
    if ( PropertyGroupNameSort::operator()(*i, *__first) )
    {
      v4 = *i;
      *i = *__first;
      _STL::__adjust_heap(__first, 0, __middle - __first, v4);
    }
  }
  _STL::sort_heap(__first, __middle);
}

//----- (006805D0) --------------------------------------------------------  // acclient.c:663513
void __cdecl _STL::__partial_sort(BaseProperty *__first, BaseProperty *__middle, BaseProperty *__last, BaseProperty *__formal, int __comp)
{
  int v5; // esi@1
  BaseProperty v6; // [sp-10h] [bp-20h]@3
  int v7; // [sp-8h] [bp-18h]@1
  int v8; // [sp-4h] [bp-14h]@1

  v8 = 0;
  v7 = 0;
  _STL::__make_heap(__first, __middle, __comp);
  v5 = (int)__middle;
  if ( __middle < __last )
  {
    do
    {
      if ( BasePropertyNameSort::operator()((BaseProperty *)v5, __first) )
      {
        v8 = 0;
        v7 = __comp;
        v6 = 0i64;
        BaseProperty::operator=(&v6, v5);
        _STL::__pop_heap(__first, __middle, (BaseProperty *)v5, v6, (BasePropertyNameSort)v7);
      }
      v5 += 8;
    }
    while ( v5 < (unsigned int)__last );
  }
  _STL::sort_heap(__first, __middle, __comp);
}

//----- (00680650) --------------------------------------------------------  // acclient.c:663544
void __cdecl _STL::__introsort_loop(unsigned int *__first, unsigned int *__last, unsigned int *__formal, int __depth_limit, PropertyGroupNameSort __comp)
{
  unsigned int *v5; // edi@1
  unsigned int *v6; // eax@3
  unsigned int *v7; // esi@3

  v5 = __last;
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v6 = (unsigned int *)_STL::__median(__first, &__first[(v5 - __first) / 2], v5 - 1);
      v7 = _STL::__unguarded_partition(__first, v5, *v6);
      _STL::__introsort_loop(v7, v5, 0, __depth_limit, __comp);
      v5 = v7;
      if ( (signed int)(((char *)v7 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    _STL::__partial_sort(__first, v5, v5);
  }
}

//----- (006806E0) --------------------------------------------------------  // acclient.c:663568
void __cdecl _STL::__introsort_loop(BaseProperty *__first, BaseProperty *__last, BaseProperty *__formal, int __depth_limit, int __comp)
{
  BaseProperty *v5; // ebx@1
  int v6; // eax@3
  BaseProperty *v7; // ebp@3
  bool v8; // al@3
  int v9; // eax@6
  bool v10; // zf@9
  BaseProperty *v11; // esi@11
  BaseProperty v12; // [sp-Ch] [bp-1Ch]@11
  BaseProperty *v13; // [sp-4h] [bp-14h]@3

  v5 = __last;
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFF8) > 128 )
  {
    do
    {
      if ( !__depth_limit )
      {
        _STL::__partial_sort(__first, v5, v5, 0, __comp);
        return;
      }
      v6 = (v5 - __first) / 2;
      v7 = &__first[v6];
      --__depth_limit;
      v8 = BasePropertyNameSort::operator()(__first, &__first[v6]);
      v13 = v5 - 1;
      if ( v8 )
      {
        if ( BasePropertyNameSort::operator()(v7, v13) )
          goto LABEL_10;
        if ( !BasePropertyNameSort::operator()(__first, v5 - 1) )
        {
LABEL_8:
          v9 = (int)__first;
          goto LABEL_11;
        }
        v9 = (int)&v5[-1];
      }
      else
      {
        if ( BasePropertyNameSort::operator()(__first, v13) )
          goto LABEL_8;
        v10 = BasePropertyNameSort::operator()(v7, v5 - 1) == 0;
        v9 = (int)&v5[-1];
        if ( v10 )
        {
LABEL_10:
          v9 = (int)v7;
          goto LABEL_11;
        }
      }
LABEL_11:
      v13 = (BaseProperty *)__comp;
      v12 = 0i64;
      BaseProperty::operator=(&v12, v9);
      v11 = _STL::__unguarded_partition(__first, v5, v12);
      _STL::__introsort_loop(v11, v5, 0, __depth_limit, (BasePropertyNameSort)__comp);
      v5 = v11;
    }
    while ( (signed int)(((char *)v11 - (char *)__first) & 0xFFFFFFF8) > 128 );
  }
}

//----- (006807E0) --------------------------------------------------------  // acclient.c:663633
char __thiscall PropertyCollection::UpdateCollection(PropertyCollection *this, PropertyCollection *_collection, const bool _bAddNewProperties)
{
  PropertyCollection *v3; // ebx@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // esi@1
  HashTableData<unsigned long,HeritageGroup_CG> **v6; // ebp@1
  unsigned int v7; // eax@3
  unsigned int v8; // ecx@3
  HashTableData<unsigned long,BaseProperty> *v9; // eax@3
  char bRet; // [sp+13h] [bp-19h]@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *cIter; // [sp+14h] [bp-18h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+20h] [bp-Ch]@1

  v3 = this;
  bRet = 1;
  v4 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&_collection->m_hashProperties.m_intrusiveTable,
         &result);
  v5 = v4->m_currElement;
  v6 = v4->m_currBucket;
  cIter = v4->m_currHashTable;
  if ( v5 )
  {
    do
    {
LABEL_2:
      if ( _bAddNewProperties )
        goto LABEL_17;
      v7 = (unsigned int)BaseProperty::GetPropertyName((BaseProperty *)&v5->m_data);
      v8 = v7;
      v9 = v3->m_hashProperties.m_intrusiveTable.m_buckets[v7 % v3->m_hashProperties.m_intrusiveTable.m_numBuckets];
      if ( v9 )
      {
        while ( v9->m_hashKey != v8 )
        {
          v9 = v9->m_hashNext;
          if ( !v9 )
            goto LABEL_10;
        }
        if ( v9 && v9 != (HashTableData<unsigned long,BaseProperty> *)-8 )
        {
LABEL_17:
          _collection = (PropertyCollection *)BaseProperty::GetPropertyName((BaseProperty *)&v5->m_data);
          bRet &= HashTable<unsigned long,BaseProperty,1>::set(
                    (HashTable<unsigned long,BaseProperty,1> *)&v3->m_hashProperties.vfptr,
                    (const unsigned int *)&_collection,
                    (BaseProperty *)&v5->m_data);
        }
      }
LABEL_10:
      v5 = v5->m_hashNext;
    }
    while ( v5 );
    while ( 1 )
    {
      ++v6;
      if ( v6 == &cIter->m_buckets[cIter->m_numBuckets] )
        break;
      if ( *v6 )
      {
        v5 = *v6;
        if ( *v6 )
          goto LABEL_2;
        return bRet;
      }
    }
  }
  return bRet;
}

//----- (006808B0) --------------------------------------------------------  // acclient.c:663704
char __thiscall PropertyCollection::InqPropertyGroupNames(PropertyCollection *this, SmartArray<unsigned long,1> *_groupNames, const bool _bSort)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v4; // edi@1
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // ebp@1
  unsigned int v6; // eax@2
  unsigned int v7; // ecx@2
  unsigned int *v8; // edx@3
  unsigned int v9; // ebx@8
  unsigned int v10; // eax@8
  unsigned int v11; // eax@9
  unsigned int *v12; // edi@16
  unsigned int *v13; // ebx@16
  int v14; // eax@17
  int i; // ecx@17
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *cIter; // [sp+10h] [bp-18h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+1Ch] [bp-Ch]@1

  v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_hashProperties.m_intrusiveTable,
         &result);
  v4 = v3->m_currElement;
  v5 = v3->m_currBucket;
  cIter = v3->m_currHashTable;
  if ( v4 )
  {
    do
    {
LABEL_2:
      v6 = BaseProperty::GetGroupName((BaseProperty *)&v4->m_data);
      v7 = 0;
      if ( !_groupNames->m_num )
        goto LABEL_8;
      v8 = _groupNames->m_data;
      while ( *v8 != v6 )
      {
        ++v7;
        ++v8;
        if ( v7 >= _groupNames->m_num )
          goto LABEL_8;
      }
      if ( v7 == -1 )
      {
LABEL_8:
        v9 = BaseProperty::GetGroupName((BaseProperty *)&v4->m_data);
        v10 = _groupNames->m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( _groupNames->m_num < v10
          || (v11 = SmartArray<UIChildFramework *,1>::get_new_size(v10 + 1),
              SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)_groupNames, v11)) )
          _groupNames->m_data[_groupNames->m_num++] = v9;
      }
      v4 = v4->m_hashNext;
    }
    while ( v4 );
    while ( 1 )
    {
      ++v5;
      if ( v5 == &cIter->m_buckets[cIter->m_numBuckets] )
        break;
      if ( *v5 )
      {
        v4 = *v5;
        if ( *v5 )
          goto LABEL_2;
        break;
      }
    }
  }
  if ( _bSort )
  {
    v12 = _groupNames->m_data;
    v13 = &_groupNames->m_data[_groupNames->m_num];
    if ( _groupNames->m_data != v13 )
    {
      v14 = v13 - v12;
      for ( i = 0; v14 != 1; ++i )
        v14 >>= 1;
      _STL::__introsort_loop(v12, v13, 0, 2 * i, (PropertyGroupNameSort)_bSort);
      if ( v13 - v12 > 16 )
      {
        _STL::__insertion_sort(v12, v12 + 16);
        _STL::__unguarded_insertion_sort_aux(v12 + 16, v13);
        return 1;
      }
      _STL::__insertion_sort(v12, v13);
    }
  }
  return 1;
}

//----- (006809F0) --------------------------------------------------------  // acclient.c:663795
char __thiscall PropertyCollection::InqPropertiesByGroup(PropertyCollection *this, const unsigned int *_groupName, SmartArray<BaseProperty,1> *_properties, int _bSort)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // esi@1
  HashTableData<unsigned long,HeritageGroup_CG> **v6; // edi@1
  unsigned int v7; // eax@3
  unsigned int v8; // eax@4
  BaseProperty *v9; // edi@11
  BaseProperty *v10; // ebx@11
  int v11; // eax@12
  int i; // ecx@12
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *cIter; // [sp+10h] [bp-18h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+1Ch] [bp-Ch]@1

  v4 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_hashProperties.m_intrusiveTable,
         &result);
  v5 = v4->m_currElement;
  v6 = v4->m_currBucket;
  cIter = v4->m_currHashTable;
  if ( v5 )
  {
    do
    {
LABEL_2:
      if ( BaseProperty::GetGroupName((BaseProperty *)&v5->m_data) == *_groupName )
      {
        v7 = _properties->m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( _properties->m_num < v7
          || (v8 = SmartArray<UIChildFramework *,1>::get_new_size(v7 + 1),
              SmartArray<BaseProperty,1>::grow(_properties, v8)) )
          BaseProperty::operator=(&_properties->m_data[_properties->m_num++], (int)&v5->m_data);
      }
      v5 = v5->m_hashNext;
    }
    while ( v5 );
    while ( 1 )
    {
      ++v6;
      if ( v6 == &cIter->m_buckets[cIter->m_numBuckets] )
        break;
      if ( *v6 )
      {
        v5 = *v6;
        if ( *v6 )
          goto LABEL_2;
        break;
      }
    }
  }
  if ( (_BYTE)_bSort )
  {
    v9 = _properties->m_data;
    v10 = &_properties->m_data[_properties->m_num];
    if ( _properties->m_data != v10 )
    {
      v11 = v10 - v9;
      for ( i = 0; v11 != 1; ++i )
        v11 >>= 1;
      _STL::__introsort_loop(v9, v10, 0, 2 * i, _bSort);
      if ( v10 - v9 > 16 )
      {
        _STL::__insertion_sort(v9, v9 + 16, _bSort);
        _STL::__unguarded_insertion_sort_aux(v9 + 16, v10, 0, _bSort);
        return 1;
      }
      _STL::__insertion_sort(v9, v10, _bSort);
    }
  }
  return 1;
}

//----- (00680B20) --------------------------------------------------------  // acclient.c:663868
void __thiscall PropertyCollection::Destroy(PropertyCollection *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::delete_contents(&this->m_hashProperties.m_intrusiveTable);
}

//----- (00680B30) --------------------------------------------------------  // acclient.c:663874
char __thiscall PropertyCollection::ToFileNode(PropertyCollection *this, PFileNode *_node)
{
  PropertyCollection *v2; // esi@1
  unsigned int v3; // ebx@3
  PStringBase<char> v5; // ST08_4@11
  PFileNode *v6; // esi@11
  unsigned int v7; // edi@12
  char *v8; // esi@15
  char *v9; // esi@23
  LONG v10; // eax@23
  PStringBase<char> strGroupName; // [sp+10h] [bp-20h]@10
  PropertyCollection *v12; // [sp+14h] [bp-1Ch]@1
  SmartArray<unsigned long,1> arrayGroupNames; // [sp+18h] [bp-18h]@2
  SmartArray<BaseProperty,1> groupProperties; // [sp+24h] [bp-Ch]@8

  v2 = this;
  v12 = this;
  if ( !_node )
    return 0;
  arrayGroupNames.m_data = 0;
  arrayGroupNames.m_sizeAndDeallocate = 0;
  arrayGroupNames.m_num = 0;
  if ( !PropertyCollection::InqPropertyGroupNames(this, &arrayGroupNames, 1) )
  {
    if ( (arrayGroupNames.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](arrayGroupNames.m_data);
    return 0;
  }
  v3 = 0;
  if ( arrayGroupNames.m_num > 0 )
  {
    while ( 1 )
    {
      groupProperties.m_data = 0;
      groupProperties.m_sizeAndDeallocate = 0;
      groupProperties.m_num = 0;
      if ( !PropertyCollection::InqPropertiesByGroup(v2, &arrayGroupNames.m_data[v3], &groupProperties, 1) )
        break;
      if ( groupProperties.m_num )
      {
        strGroupName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        if ( !MasterProperty::InqPropertyGroupNameStringStatic(arrayGroupNames.m_data[v3], &strGroupName) )
        {
          v9 = &strGroupName.m_charbuffer[-2].m_data[12];
          v10 = InterlockedDecrement((volatile LONG *)&strGroupName.m_charbuffer[-1]);
LABEL_26:
          if ( !v10 && v9 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
          break;
        }
        v5.m_charbuffer = strGroupName.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&strGroupName.m_charbuffer[-1]);
        v6 = PFileNode::MakeSubNode(_node, v5);
        if ( !v6 )
        {
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strGroupName);
          break;
        }
        v7 = 0;
        if ( groupProperties.m_num > 0 )
        {
          while ( BaseProperty::ToFileNode(&groupProperties.m_data[v7], v6) )
          {
            ++v7;
            if ( v7 >= groupProperties.m_num )
              goto LABEL_15;
          }
          v9 = &strGroupName.m_charbuffer[-2].m_data[12];
          v10 = InterlockedDecrement((volatile LONG *)&strGroupName.m_charbuffer[-1]);
          goto LABEL_26;
        }
LABEL_15:
        v8 = &strGroupName.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&strGroupName.m_charbuffer[-1]) && v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      }
      if ( (groupProperties.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)groupProperties.m_data )
        BaseProperty::vector_deleting_destructor(groupProperties.m_data, 3u);
      ++v3;
      if ( v3 >= arrayGroupNames.m_num )
        goto LABEL_4;
      v2 = v12;
    }
    if ( (groupProperties.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)groupProperties.m_data )
      BaseProperty::vector_deleting_destructor(groupProperties.m_data, 3u);
    if ( (arrayGroupNames.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    {
      operator delete[](arrayGroupNames.m_data);
      return 0;
    }
    return 0;
  }
LABEL_4:
  if ( (arrayGroupNames.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](arrayGroupNames.m_data);
  return 1;
}

//----- (00680D60) --------------------------------------------------------  // acclient.c:663974
void __thiscall PropertyCollection::PruneForServer(PropertyCollection *this)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v1; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v2; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // edi@1
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // ebx@3
  HashTableData<unsigned long,HeritageGroup_CG> *v6; // ebp@3
  HashTableData<unsigned long,HeritageGroup_CG> **v7; // ecx@3
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // eax@7
  HashTableData<unsigned long,HeritageGroup_CG> *v9; // edx@8
  HeritageGroup_CGVtbl *v10; // ecx@12
  bool v11; // zf@13
  PSRefBufferCharData<char> *v12; // ecx@16
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *cIter; // [sp+Ch] [bp-18h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+18h] [bp-Ch]@1

  v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_hashProperties.m_intrusiveTable,
         &result);
  v2 = v1->m_currElement;
  v3 = v1->m_currHashTable;
  v4 = v1->m_currBucket;
  cIter = v1->m_currHashTable;
  if ( v2 )
  {
    do
    {
      while ( BaseProperty::IsClientOnlyData((BaseProperty *)&v2->m_data) )
      {
        v5 = v2->m_hashNext;
        v6 = v2;
        v7 = v4;
        if ( !v5 )
        {
          while ( 1 )
          {
            ++v7;
            if ( v7 == &cIter->m_buckets[cIter->m_numBuckets] )
              break;
            if ( *v7 )
            {
              v5 = *v7;
              break;
            }
          }
        }
        v8 = *v4;
        if ( *v4 == v2 )
          goto LABEL_28;
        do
        {
          v9 = v8;
          v8 = v8->m_hashNext;
        }
        while ( v8 != v2 );
        if ( v9 )
          v9->m_hashNext = v8->m_hashNext;
        else
LABEL_28:
          *v4 = v8->m_hashNext;
        --cIter->m_numElements;
        v4 = v7;
        v10 = v2->m_data.vfptr;
        v2 = v5;
        if ( v10 )
        {
          v11 = v10[1].Serialize-- == (void (__thiscall *)(HeritageGroup_CG *, Archive *))1;
          if ( v11 )
            (*(void (__stdcall **)(_DWORD))v10->Serialize)(1);
          v6->m_data.vfptr = 0;
        }
        v12 = v6->m_data.name.m_charbuffer;
        if ( v12 )
        {
          v11 = (*(_DWORD *)&v12->m_data[4])-- == 1;
          if ( v11 )
            (**(void (__stdcall ***)(_DWORD))&v12->m_data[0])(1);
          v6->m_data.name.m_charbuffer = 0;
        }
        operator delete(v6);
        v3 = cIter;
LABEL_25:
        if ( !v2 )
          return;
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
        goto LABEL_25;
      }
    }
  }
}

//----- (00680E60) --------------------------------------------------------  // acclient.c:664078
void __thiscall PropertyCollection::PruneForClient(PropertyCollection *this)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v1; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v2; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // edi@1
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // ebx@3
  HashTableData<unsigned long,HeritageGroup_CG> *v6; // ebp@3
  HashTableData<unsigned long,HeritageGroup_CG> **v7; // ecx@3
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // eax@7
  HashTableData<unsigned long,HeritageGroup_CG> *v9; // edx@8
  HeritageGroup_CGVtbl *v10; // ecx@12
  bool v11; // zf@13
  PSRefBufferCharData<char> *v12; // ecx@16
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *cIter; // [sp+Ch] [bp-18h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+18h] [bp-Ch]@1

  v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_hashProperties.m_intrusiveTable,
         &result);
  v2 = v1->m_currElement;
  v3 = v1->m_currHashTable;
  v4 = v1->m_currBucket;
  cIter = v1->m_currHashTable;
  if ( v2 )
  {
    do
    {
      while ( BaseProperty::IsServerOnlyData((BaseProperty *)&v2->m_data) )
      {
        v5 = v2->m_hashNext;
        v6 = v2;
        v7 = v4;
        if ( !v5 )
        {
          while ( 1 )
          {
            ++v7;
            if ( v7 == &cIter->m_buckets[cIter->m_numBuckets] )
              break;
            if ( *v7 )
            {
              v5 = *v7;
              break;
            }
          }
        }
        v8 = *v4;
        if ( *v4 == v2 )
          goto LABEL_28;
        do
        {
          v9 = v8;
          v8 = v8->m_hashNext;
        }
        while ( v8 != v2 );
        if ( v9 )
          v9->m_hashNext = v8->m_hashNext;
        else
LABEL_28:
          *v4 = v8->m_hashNext;
        --cIter->m_numElements;
        v4 = v7;
        v10 = v2->m_data.vfptr;
        v2 = v5;
        if ( v10 )
        {
          v11 = v10[1].Serialize-- == (void (__thiscall *)(HeritageGroup_CG *, Archive *))1;
          if ( v11 )
            (*(void (__stdcall **)(_DWORD))v10->Serialize)(1);
          v6->m_data.vfptr = 0;
        }
        v12 = v6->m_data.name.m_charbuffer;
        if ( v12 )
        {
          v11 = (*(_DWORD *)&v12->m_data[4])-- == 1;
          if ( v11 )
            (**(void (__stdcall ***)(_DWORD))&v12->m_data[0])(1);
          v6->m_data.name.m_charbuffer = 0;
        }
        operator delete(v6);
        v3 = cIter;
LABEL_25:
        if ( !v2 )
          return;
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
        goto LABEL_25;
      }
    }
  }
}

//----- (00680F60) --------------------------------------------------------  // acclient.c:664182
void __thiscall PropertyCollection::~PropertyCollection(PropertyCollection *this)
{
  char *v1; // esi@1
  void *v2; // eax@1

  this->vfptr = (PropertyCollectionVtbl *)&PropertyCollection::vftable;
  v1 = (char *)&this->m_hashProperties.m_intrusiveTable;
  this->m_hashProperties.vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::delete_contents(&this->m_hashProperties.m_intrusiveTable);
  v2 = (void *)*((_DWORD *)v1 + 24);
  *(_DWORD *)v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::vftable;
  if ( v2 != v1 + 4 )
    operator delete[](v2);
  *((_DWORD *)v1 + 24) = 0;
  *((_DWORD *)v1 + 25) = 0;
  *((_DWORD *)v1 + 26) = 0;
  *((_DWORD *)v1 + 27) = 0;
}
// 7970CC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::vftable[2])(void *, char);
// 797700: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,BaseProperty>::vftable)(void *, char);
// 79C058: using guessed type int (__thiscall *PropertyCollection::vftable)(void *, char);

//----- (00680FB0) --------------------------------------------------------  // acclient.c:664205
bool __thiscall PropertyCollection::FromFileNode(PropertyCollection *this, PFileNode *_node)
{
  PFileNode *v2; // esi@1
  PropertyCollection *v3; // edi@1
  unsigned int v4; // eax@5
  unsigned int v5; // ecx@5
  ReferenceCountTemplate<1048576,0>Vtbl *v6; // eax@6
  unsigned int *v7; // ecx@6
  int v8; // edi@6
  PSRefBufferCharData<char> *v9; // ebx@8
  PSRefBufferCharData<char> *v10; // ecx@8
  int v11; // ebx@9
  int v12; // eax@11
  PFileNode *v13; // esi@11
  int v14; // edi@13
  PSRefBufferCharData<char> *v15; // ecx@13
  int v16; // edx@15
  BasePropertyDesc *v17; // ecx@17
  unsigned int v18; // edx@17
  ReferenceCountTemplate<1048576,1>Vtbl *v19; // eax@18
  BasePropertyValue *v20; // ecx@21
  unsigned int v21; // edx@21
  ReferenceCountTemplate<1048576,1>Vtbl *v22; // edx@22
  BasePropertyDesc *v23; // eax@27
  int v24; // edi@29
  PSRefBufferCharData<char> *v25; // ecx@29
  int v26; // edx@31
  int v27; // edx@38
  int v29; // edi@48
  PSRefBufferCharData<char> *v30; // ecx@48
  int v31; // esi@48
  int v32; // edx@50
  BasePropertyDesc *v33; // ecx@52
  unsigned int v34; // edx@52
  ReferenceCountTemplate<1048576,1>Vtbl *v35; // eax@53
  BasePropertyValue *v36; // ecx@56
  unsigned int v37; // esi@56
  ReferenceCountTemplate<1048576,1>Vtbl *v38; // edx@57
  int v39; // ebx@59
  int v40; // edx@61
  PStringBase<char> v41; // [sp-Ah] [bp-44h]@13
  PStringBase<char> v42; // [sp-6h] [bp-40h]@8
  unsigned int *v43; // [sp-2h] [bp-3Ch]@6
  bool retval; // [sp+10h] [bp-2Ah]@5
  bool bIsAdder; // [sp+11h] [bp-29h]@3
  PFileNode *groupNode; // [sp+12h] [bp-28h]@6
  PStringBase<char> strGroupName; // [sp+16h] [bp-24h]@8
  PropertyCollection *v48; // [sp+1Ah] [bp-20h]@1
  PStringBase<char> strName; // [sp+1Eh] [bp-1Ch]@13
  unsigned int ig; // [sp+22h] [bp-18h]@5
  unsigned int nProperties; // [sp+26h] [bp-14h]@10
  unsigned int nGroups; // [sp+2Ah] [bp-10h]@5
  unsigned int group_name_enum; // [sp+2Eh] [bp-Ch]@8
  BaseProperty _data; // [sp+32h] [bp-8h]@12

  v2 = _node;
  v3 = this;
  v48 = this;
  if ( !_node )
    return 0;
  if ( ProgramTypeSystem::s_eProgramType == -2147483646
    || (bIsAdder = 0, ProgramTypeSystem::s_eProgramType == -2147483647) )
    bIsAdder = 1;
  retval = 1;
  v4 = PFileNode::GetNumSubNodes(_node);
  v5 = 0;
  nGroups = v4;
  ig = 0;
  if ( !v4 )
    goto LABEL_42;
  while ( 1 )
  {
    v6 = v2->vfptr;
    v43 = (unsigned int *)v5;
    v8 = (int)v6[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, v5);
    groupNode = (PFileNode *)v8;
    if ( v8 )
      break;
    v43 = v7;
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&v43,
      "unexpected end of filenode structure (invalid group!)");
    PFileNode::ReportError(0, v2, (PStringBase<char>)v43);
    retval = 0;
LABEL_40:
    v5 = ig++ + 1;
    if ( ig >= nGroups )
    {
      v3 = v48;
LABEL_42:
      if ( !DBCache::IsRunTime() )
      {
        if ( DBCache::IsClient() )
          PropertyCollection::PruneForClient(v3);
        if ( DBCache::IsServer() )
          PropertyCollection::PruneForServer(v3);
      }
      return retval;
    }
  }
  strGroupName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PFileNode::GetNameAsPString((PFileNode *)v8, v8, &strGroupName);
  v9 = strGroupName.m_charbuffer;
  v43 = &group_name_enum;
  v42.m_charbuffer = strGroupName.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&strGroupName.m_charbuffer[-1]);
  if ( !EnumMapper::GetEnum(0xAu, v42, v43) )
  {
    v43 = (unsigned int *)v9;
    v42.m_charbuffer = v10;
    PStringBase<char>::PStringBase<char>(&v42, "invalid property group '%s'");
    PFileNode::ReportError(v8, (PFileNode *)v8, v42);
    v11 = (int)&v9[-2].m_data[12];
    retval = 0;
    v43 = (unsigned int *)(v11 + 4);
    goto LABEL_36;
  }
  nProperties = PFileNode::GetNumSubNodes((PFileNode *)v8);
  strGroupName.m_charbuffer = 0;
  if ( !nProperties )
  {
LABEL_35:
    v11 = (int)&v9[-2].m_data[12];
    v43 = (unsigned int *)(v11 + 4);
LABEL_36:
    if ( !InterlockedDecrement((volatile LONG *)v43) && v11 )
    {
      v27 = *(_DWORD *)v11;
      v43 = (unsigned int *)1;
      (*(void (__thiscall **)(int, signed int))v27)(v11, 1);
    }
    v2 = _node;
    goto LABEL_40;
  }
  while ( 1 )
  {
    v12 = *(_DWORD *)v8;
    v43 = (unsigned int *)strGroupName.m_charbuffer;
    v13 = (PFileNode *)(*(int (__thiscall **)(int, PSRefBufferCharData<char> *))(v12 + 12))(
                         v8,
                         strGroupName.m_charbuffer);
    if ( !v13 )
      goto LABEL_34;
    _data.m_pcPropertyDesc = 0;
    _data.m_pcPropertyValue = 0;
    if ( !BaseProperty::FromFileNode(&_data, v13) )
    {
      strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PFileNode::GetNameAsPString(v13, v8, &strName);
      v14 = (int)strName.m_charbuffer;
      v43 = (unsigned int *)v9;
      v42.m_charbuffer = strName.m_charbuffer;
      v41.m_charbuffer = v15;
      PStringBase<char>::PStringBase<char>(&v41, "could not parse property [%s] from group [%s]");
      PFileNode::ReportError(v14, v13, v41);
      retval = 0;
      if ( !InterlockedDecrement((volatile LONG *)(v14 - 20 + 4)) && v14 != 20 )
      {
        v16 = *(_DWORD *)(v14 - 20);
        v43 = (unsigned int *)1;
        (*(void (__thiscall **)(int, signed int))v16)(v14 - 20, 1);
      }
      if ( (_DWORD)_data.m_pcPropertyDesc )
      {
        v17 = _data.m_pcPropertyDesc;
        v18 = _data.m_pcPropertyDesc->m_cRef - 1;
        _data.m_pcPropertyDesc->m_cRef = v18;
        if ( !v18 )
        {
          v19 = v17->vfptr;
          v43 = (unsigned int *)1;
          ((void (__stdcall *)(signed int))v19->__vecDelDtor)(1);
        }
        _data.m_pcPropertyDesc = 0;
      }
      if ( _data.m_pcPropertyValue )
      {
        v20 = _data.m_pcPropertyValue;
        v21 = _data.m_pcPropertyValue->m_cRef - 1;
        _data.m_pcPropertyValue->m_cRef = v21;
        if ( !v21 )
        {
          v22 = v20->vfptr;
          v43 = (unsigned int *)1;
          ((void (__stdcall *)(signed int))v22->__vecDelDtor)(1);
        }
        _data.m_pcPropertyValue = 0;
      }
LABEL_33:
      v8 = (int)groupNode;
      goto LABEL_34;
    }
    if ( bIsAdder && BaseProperty::IsToolOnly(&_data) )
      goto LABEL_26;
    v23 = BaseProperty::GetPropertyName(&_data);
    if ( PropertyCollection::ContainsProperty(v48, (const unsigned int)v23) )
      break;
    strName.m_charbuffer = (PSRefBufferCharData<char> *)BaseProperty::GetPropertyName(&_data);
    if ( !HashTable<unsigned long,BaseProperty,1>::add(
            (HashTable<unsigned long,BaseProperty,1> *)&v48->m_hashProperties.vfptr,
            (const unsigned int *)&strName,
            &_data) )
    {
      strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PFileNode::GetNameAsPString(v13, v8, &strName);
      v24 = (int)strName.m_charbuffer;
      v43 = (unsigned int *)v9;
      v42.m_charbuffer = strName.m_charbuffer;
      v41.m_charbuffer = v25;
      PStringBase<char>::PStringBase<char>(&v41, "failed adding property [%s] for group [%s]");
      PFileNode::ReportError(v24, v13, v41);
      retval = 0;
      if ( !InterlockedDecrement((volatile LONG *)(v24 - 20 + 4)) && v24 != 20 )
      {
        v26 = *(_DWORD *)(v24 - 20);
        v43 = (unsigned int *)1;
        (*(void (__thiscall **)(int, signed int))v26)(v24 - 20, 1);
      }
      BaseProperty::~BaseProperty(&_data);
      goto LABEL_33;
    }
LABEL_26:
    BaseProperty::~BaseProperty(&_data);
LABEL_34:
    ++strGroupName.m_charbuffer;
    if ( (unsigned int)strGroupName.m_charbuffer >= nProperties )
      goto LABEL_35;
  }
  ig = (unsigned int)PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PFileNode::GetNameAsPString(v13, v8, (PStringBase<char> *)&ig);
  v29 = ig;
  v43 = (unsigned int *)ig;
  v42.m_charbuffer = v30;
  PStringBase<char>::PStringBase<char>(&v42, "Error: Property [%s] occurs twice. Will fail.");
  PFileNode::ReportError(v29, v13, v42);
  v31 = v29 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v29 - 20 + 4)) && v29 != 20 )
  {
    v32 = *(_DWORD *)v31;
    v43 = (unsigned int *)1;
    (*(void (__thiscall **)(int, signed int))v32)(v31, 1);
  }
  if ( (_DWORD)_data.m_pcPropertyDesc )
  {
    v33 = _data.m_pcPropertyDesc;
    v34 = _data.m_pcPropertyDesc->m_cRef - 1;
    _data.m_pcPropertyDesc->m_cRef = v34;
    if ( !v34 )
    {
      v35 = v33->vfptr;
      v43 = (unsigned int *)1;
      ((void (__stdcall *)(signed int))v35->__vecDelDtor)(1);
    }
    _data.m_pcPropertyDesc = 0;
  }
  if ( _data.m_pcPropertyValue )
  {
    v36 = _data.m_pcPropertyValue;
    v37 = _data.m_pcPropertyValue->m_cRef - 1;
    _data.m_pcPropertyValue->m_cRef = v37;
    if ( !v37 )
    {
      v38 = v36->vfptr;
      v43 = (unsigned int *)1;
      ((void (__stdcall *)(signed int))v38->__vecDelDtor)(1);
    }
    _data.m_pcPropertyValue = 0;
  }
  v39 = (int)&v9[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v39 + 4)) && v39 )
  {
    v40 = *(_DWORD *)v39;
    v43 = (unsigned int *)1;
    (*(void (__thiscall **)(int, signed int))v40)(v39, 1);
  }
  return 0;
}
// 836720: using guessed type enum ProgramType ProgramTypeSystem::s_eProgramType;

//----- (006813D0) --------------------------------------------------------  // acclient.c:664489
void __thiscall PropertyCollection::PropertyCollection(PropertyCollection *this)
{
  PropertyCollection *v1; // esi@1

  v1 = this;
  this->vfptr = (PropertyCollectionVtbl *)&PropertyCollection::vftable;
  this->m_hashProperties.vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>(
    &this->m_hashProperties.m_intrusiveTable,
    0);
  v1->m_hashProperties.vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
}
// 797700: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,BaseProperty>::vftable)(void *, char);
// 79C058: using guessed type int (__thiscall *PropertyCollection::vftable)(void *, char);

//----- (00681400) --------------------------------------------------------  // acclient.c:664505
void *__thiscall PropertyCollection::operator=(void *this, void *a2)
{
  void *v2; // esi@1

  v2 = this;
  if ( this != a2 )
    HashTable<unsigned long,BaseProperty,1>::operator=((int)((char *)this + 4), (int)((char *)a2 + 4));
  return v2;
}

//----- (00681420) --------------------------------------------------------  // acclient.c:664516
void __thiscall PropertyCollection::Serialize(PropertyCollection *this, Archive *io_rcArchive)
{
  Archive *v2; // edi@1
  PropertyCollection *v3; // esi@1

  v2 = io_rcArchive;
  v3 = this;
  if ( ~LOBYTE(io_rcArchive->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::delete_contents(&this->m_hashProperties.m_intrusiveTable);
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>,HashTableData<unsigned long,BaseProperty> *,SB_Default>(
    (const int *)&io_rcArchive,
    &v3->m_hashProperties.m_intrusiveTable,
    v2);
}

//----- (00715450) --------------------------------------------------------  // acclient.c:808239
int sub_715450()
{
  return atexit(nullsub_181);
}

//----- (00715460) --------------------------------------------------------  // acclient.c:808245
int _E76_94()
{
  return atexit(nullsub_182);
}

//----- (00715470) --------------------------------------------------------  // acclient.c:808251
int _E79_89()
{
  return atexit(_E80_86);
}

//----- (00715480) --------------------------------------------------------  // acclient.c:808257
int sub_715480()
{
  return atexit(nullsub_180);
}

