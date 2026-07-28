/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PFileNode
   Object     : CORE\serialize\PFileNode.obj
   Functions  : 55
   Addresses  : 0065B7F0 - 0077EDF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0065B7F0) --------------------------------------------------------  // acclient.c:625326
void __thiscall PFileNode::SetLineNumber(PFileNode *this, unsigned __int16 new_line_number)
{
  this->line_number = new_line_number;
}

//----- (0065B800) --------------------------------------------------------  // acclient.c:625332
void __thiscall PFileNode::SetColumnNumber(PFileNode *this, unsigned __int16 new_column_number)
{
  this->column_number = new_column_number;
}

//----- (0065B810) --------------------------------------------------------  // acclient.c:625338
PFileNode *__thiscall PFileNodeIter::Curr(PFileNodeIter *this)
{
  PFileNode *result; // eax@1

  result = this->file_node;
  if ( this->file_node )
    result = (PFileNode *)result->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)result, this->curr_index);
  return result;
}

//----- (0065B830) --------------------------------------------------------  // acclient.c:625349
char __thiscall SmartArray<PFileNode *,1>::RemoveOrderedByIndex(SmartArray<PFileNode *,1> *this, unsigned int index)
{
  SmartArray<PFileNode *,1> *v2; // edx@1
  unsigned int v3; // eax@1
  PFileNode **v4; // ecx@2
  int v5; // eax@2
  unsigned int v6; // edi@2
  int v7; // ecx@2
  char result; // al@4

  v2 = this;
  v3 = this->m_num;
  if ( index >= v3 )
  {
    result = 0;
  }
  else
  {
    v4 = this->m_data;
    v5 = v3 - 1;
    v6 = (unsigned int)&v4[index];
    v7 = (int)&v4[v5];
    v2->m_num = v5;
    if ( v6 < v7 )
      qmemcpy((void *)v6, (const void *)(v6 + 4), 4 * (((v7 - v6 - 1) >> 2) + 1));
    v2->m_data[v2->m_num] = 0;
    result = 1;
  }
  return result;
}

//----- (0065B880) --------------------------------------------------------  // acclient.c:625381
PFileNode *const *__cdecl _STL::__find<PFileNode * const *,PFileNode const *>(PFileNode *const *__first, PFileNode *const *__last, PFileNode *const *__val)
{
  PFileNode *const *result; // eax@1
  signed int v4; // ecx@1
  PFileNode *v5; // edx@2

  result = __first;
  v4 = ((char *)__last - (char *)__first) >> 4;
  if ( v4 <= 0 )
  {
LABEL_8:
    if ( __last - result != 1 )
    {
      if ( __last - result != 2 )
      {
        if ( __last - result != 3 )
          return __last;
        if ( *result == *__val )
          return result;
        ++result;
      }
      if ( *result == *__val )
        return result;
      ++result;
    }
    if ( *result == *__val )
      return result;
    return __last;
  }
  v5 = *__val;
  while ( *result != v5 )
  {
    ++result;
    if ( *result == v5 )
      break;
    ++result;
    if ( *result == v5 )
      break;
    ++result;
    if ( *result == v5 )
      break;
    --v4;
    ++result;
    if ( v4 <= 0 )
      goto LABEL_8;
  }
  return result;
}

//----- (0065B900) --------------------------------------------------------  // acclient.c:625431
PFileNode *const *__cdecl _STL::__median<PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(PFileNode *const *__a, PFileNode *const *__b, PFileNode *const *__c, bool (__cdecl *__comp)(PFileNode *, PFileNode *))
{
  PFileNode *const *result; // eax@4
  bool v5; // zf@7

  if ( __comp(*__a, *__b) )
  {
    if ( !__comp(*__b, *__c) )
    {
      if ( __comp(*__a, *__c) )
        return __c;
      return __a;
    }
    return __b;
  }
  if ( __comp(*__a, *__c) )
    return __a;
  v5 = __comp(*__b, *__c) == 0;
  result = __c;
  if ( v5 )
    return __b;
  return result;
}

//----- (0065B980) --------------------------------------------------------  // acclient.c:625456
void __cdecl _STL::__unguarded_linear_insert<PFileNode * *,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(PFileNode **__last, PFileNode *__val, bool (__cdecl *__comp)(PFileNode *, PFileNode *))
{
  PFileNode **v3; // edi@1
  PFileNode **v4; // esi@1
  PFileNode *v5; // edx@2

  v3 = __last;
  v4 = __last - 1;
  if ( __comp(__val, *(__last - 1)) )
  {
    do
    {
      *v3 = *v4;
      v5 = *(v4 - 1);
      v3 = v4;
      --v4;
    }
    while ( __comp(__val, v5) );
  }
  *v3 = __val;
}

//----- (0065B9C0) --------------------------------------------------------  // acclient.c:625479
void __cdecl _STL::__push_heap<PFileNode * *,int,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(PFileNode **__first, int __holeIndex, int __topIndex, PFileNode *__val, bool (__cdecl *__comp)(PFileNode *, PFileNode *))
{
  int v5; // edi@1
  int v6; // esi@1
  bool v7; // zf@3
  bool v8; // sf@3
  unsigned __int8 v9; // of@3

  v5 = __holeIndex;
  v6 = (__holeIndex - 1) / 2;
  if ( __holeIndex <= __topIndex )
  {
    __first[__holeIndex] = __val;
  }
  else
  {
    do
    {
      if ( !__comp(__first[v6], __val) )
        break;
      __first[v5] = __first[v6];
      v5 = v6;
      v9 = __OFSUB__(v6, __topIndex);
      v7 = v6 == __topIndex;
      v8 = v6 - __topIndex < 0;
      v6 = (v6 - 1) / 2;
    }
    while ( !((unsigned __int8)(v8 ^ v9) | v7) );
    __first[v5] = __val;
  }
}

//----- (0065BA20) --------------------------------------------------------  // acclient.c:625512
FileNodeFileInfo *__thiscall PFileNode::GetFileInfo(PFileNode *this)
{
  PFileNode *v1; // eax@1

  do
  {
    v1 = this;
    this = this->m_pcParent;
  }
  while ( this );
  return v1->m_fileInfo.m_data;
}

//----- (0065BA40) --------------------------------------------------------  // acclient.c:625526
unsigned int __thiscall PFileNode::GetNumSubNodes(PFileNode *this)
{
  return this->sub_nodes.m_num;
}

//----- (0065BA50) --------------------------------------------------------  // acclient.c:625532
PFileNode *__thiscall PFileNode::GetSubNode(PFileNode *this, unsigned int index)
{
  PFileNode *result; // eax@2

  if ( index < this->sub_nodes.m_num )
    result = this->sub_nodes.m_data[index];
  else
    result = 0;
  return result;
}

//----- (0065BA70) --------------------------------------------------------  // acclient.c:625544
int __thiscall PFileNode::GetOnlyChild(PFileNode *this)
{
  int result; // eax@2

  if ( this->sub_nodes.m_num == 1 )
    result = ((int (__stdcall *)(_DWORD))this->vfptr[3].__vecDelDtor)(0);
  else
    result = 0;
  return result;
}

//----- (0065BA90) --------------------------------------------------------  // acclient.c:625556
int __thiscall PFileNode::GetLeaf(PFileNode *this)
{
  int result; // eax@2

  if ( this->sub_nodes.m_num == 1 )
    result = ((int (__stdcall *)(_DWORD))this->vfptr[3].__vecDelDtor)(0);
  else
    result = 0;
  if ( result )
  {
    if ( *(_DWORD *)(result + 32) )
      result = 0;
  }
  return result;
}

//----- (0065BAB0) --------------------------------------------------------  // acclient.c:625573
int __thiscall PFileNode::RemoveSubNode(PFileNode *this, unsigned int index)
{
  PFileNode *v2; // esi@1
  int result; // eax@1
  int v4; // edi@2

  v2 = this;
  result = 0;
  if ( index < this->sub_nodes.m_num )
  {
    v4 = ((int (__stdcall *)(_DWORD))this->vfptr[2].__vecDelDtor)(index);
    SmartArray<PFileNode *,1>::RemoveOrderedByIndex(&v2->sub_nodes, index);
    *(_DWORD *)(v4 + 44) = 0;
    result = v4;
  }
  return result;
}

//----- (0065BAE0) --------------------------------------------------------  // acclient.c:625592
void __thiscall PFileNodeIter::~PFileNodeIter(PFileNodeIter *this)
{
  char *v1; // esi@1

  v1 = &this->search_string.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)v1 + 1) )
  {
    if ( v1 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
  }
}

//----- (0065BB10) --------------------------------------------------------  // acclient.c:625605
int __thiscall PFileNodeIter::Next(PFileNodeIter *this)
{
  PFileNodeIter *v1; // esi@1
  PFileNode *v2; // ecx@1
  int result; // eax@4

  v1 = this;
  v2 = this->file_node;
  if ( v2 && ((int (__stdcall *)(_DWORD))v2->vfptr[3].__vecDelDtor)(v1->curr_index) && (++v1->curr_index, v1->file_node) )
    result = ((int (__stdcall *)(_DWORD))v1->file_node->vfptr[3].__vecDelDtor)(v1->curr_index);
  else
    result = 0;
  return result;
}

//----- (0065BB40) --------------------------------------------------------  // acclient.c:625621
FileNodeFileInfo *__thiscall FileNodeFileInfo::scalar_deleting_destructor(FileNodeFileInfo *this, unsigned int a2)
{
  FileNodeFileInfo *v2; // esi@1

  v2 = this;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&this->m_filename);
  v2->vfptr = (ReferenceCountTemplate<268435456,0>Vtbl *)AC1Legacy::PSRefBuffer<char>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7CA074: using guessed type int (__thiscall *AC1Legacy::PSRefBuffer<char>::vftable[2])(void *, char);

//----- (0065BB70) --------------------------------------------------------  // acclient.c:625635
void __cdecl _STL::__unguarded_insertion_sort_aux<PFileNode * *,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(PFileNode **__first, PFileNode **__last, PFileNode **__formal, bool (__cdecl *__comp)(PFileNode *, PFileNode *))
{
  PFileNode **i; // ebp@1
  PFileNode *v5; // ebx@2
  int v6; // esi@2
  PFileNode **v7; // edi@2
  PFileNode *v8; // edx@3

  for ( i = __first; i != __last; *v7 = v5 )
  {
    v5 = *i;
    v6 = (int)(i - 1);
    v7 = i;
    if ( __comp(*i, *(i - 1)) )
    {
      do
      {
        *v7 = *(PFileNode **)v6;
        v8 = *(PFileNode **)(v6 - 4);
        v7 = (PFileNode **)v6;
        v6 -= 4;
      }
      while ( __comp(v5, v8) );
    }
    ++i;
  }
}

//----- (0065BBD0) --------------------------------------------------------  // acclient.c:625664
void __cdecl _STL::__adjust_heap<PFileNode * *,int,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(PFileNode **__first, int __holeIndex, int __len, PFileNode *__val, bool (__cdecl *__comp)(PFileNode *, PFileNode *))
{
  int v5; // ebx@1
  int v6; // esi@1
  bool i; // zf@1

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  for ( i = v6 == __len; v6 < __len; i = v6 == __len )
  {
    if ( __comp(__first[v6], __first[v6 - 1]) )
      --v6;
    __first[v5] = __first[v6];
    v5 = v6;
    v6 = 2 * v6 + 2;
  }
  if ( i )
  {
    __first[v5] = __first[v6 - 1];
    v5 = v6 - 1;
  }
  _STL::__push_heap<PFileNode * *,int,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
    __first,
    v5,
    __holeIndex,
    __val,
    __comp);
}

//----- (0065BC50) --------------------------------------------------------  // acclient.c:625694
char __userpurge PFileNode::IsKeyword@<al>(PFileNode *this@<ecx>, int a2@<edi>, PStringBase<char> *_keyword)
{
  PFileNode *v3; // esi@1
  char v4; // bl@1
  char v5; // al@1
  PSRefBufferCharData<char> *v6; // esi@1
  int v7; // esi@4
  PStringBase<char> name; // [sp+0h] [bp-4h]@1

  name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v3 = this;
  v4 = 0;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v5 = PFileNode::GetNameAsPString(v3, a2, &name);
  v6 = name.m_charbuffer;
  if ( v5 && !__stricmp(name.m_charbuffer->m_data, _keyword->m_charbuffer->m_data) )
    v4 = 1;
  v7 = (int)&v6[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  return v4;
}

//----- (0065BCC0) --------------------------------------------------------  // acclient.c:625718
char __cdecl PFileNodeSorter(PFileNode *_pA, PFileNode *_pB)
{
  PSRefBufferCharData<char> *v2; // ecx@0
  PFileNode *v3; // ebx@1
  PFileNode *v4; // edi@2
  PFileNode *v5; // esi@3
  PSRefBufferCharData<char> *v6; // edi@3
  bool v7; // bl@3
  int v8; // esi@3
  char result; // al@9
  PStringBase<char> aName; // [sp+0h] [bp-4h]@1

  aName.m_charbuffer = v2;
  v3 = _pA;
  if ( _pA )
  {
    v4 = _pB;
    if ( _pB )
    {
      aName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      _pA = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PFileNode::GetNameAsPString(v3, (int)v4, &aName);
      PFileNode::GetNameAsPString(v4, (int)v4, (PStringBase<char> *)&_pA);
      v5 = _pA;
      v6 = aName.m_charbuffer;
      v7 = __stricmp(aName.m_charbuffer->m_data, (const char *)_pA) < 0;
      v8 = (int)&v5[-1].sub_nodes.m_num;
      if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v6 != (PSRefBufferCharData<char> *)20 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))&v6[-2].m_data[12])(&v6[-2].m_data[12], 1);
      result = v7;
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0065BD80) --------------------------------------------------------  // acclient.c:625766
PFileNode *__userpurge PFileNode::FindSubNode@<eax>(PFileNode *this@<ecx>, int a2@<edi>, PStringBase<char> *n)
{
  PFileNode *v3; // ebx@1
  unsigned int v4; // esi@1
  PFileNode *result; // eax@1
  const char **v6; // ebp@2
  PStringBase<char> *v7; // edi@3
  int v8; // eax@3
  PFileNode *v9; // esi@9
  volatile LONG *v10; // [sp-Ch] [bp-14h]@3

  v3 = this;
  v4 = 0;
  result = 0;
  if ( this->sub_nodes.m_num )
  {
    v6 = (const char **)n;
    while ( 1 )
    {
      n = (PStringBase<char> *)PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PFileNode::GetNameAsPString(v3->sub_nodes.m_data[v4], a2, (PStringBase<char> *)&n);
      v7 = n;
      v8 = __stricmp((const char *)n, *v6);
      a2 = (int)&v7[-5];
      v10 = (volatile LONG *)(a2 + 4);
      if ( !v8 )
        break;
      if ( !InterlockedDecrement(v10) )
      {
        if ( a2 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))a2)(a2, 1);
      }
      ++v4;
      if ( v4 >= v3->sub_nodes.m_num )
        return 0;
    }
    v9 = v3->sub_nodes.m_data[v4];
    if ( !InterlockedDecrement(v10) && a2 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))a2)(a2, 1);
    result = v9;
  }
  return result;
}

//----- (0065BE40) --------------------------------------------------------  // acclient.c:625812
bool __thiscall PFileNode::ClearComments(PFileNode *this, bool recursive)
{
  PFileNode *v2; // esi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // edi@2
  volatile LONG *v5; // ST04_4@5
  unsigned int v6; // edi@7
  PFileNode *v7; // eax@8
  bool retval; // [sp+9h] [bp-1h]@1

  v2 = this;
  v3 = this->comment_string.m_charbuffer;
  retval = 1;
  if ( v3 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v4 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v2->comment_string.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v5);
  }
  if ( recursive )
  {
    v6 = 0;
    if ( v2->sub_nodes.m_num )
    {
      do
      {
        v7 = (PFileNode *)v2->vfptr[2].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, v6);
        if ( !PFileNode::ClearComments(v7, recursive) )
          retval = 0;
        ++v6;
      }
      while ( v6 < v2->sub_nodes.m_num );
    }
  }
  return retval;
}

//----- (0065BED0) --------------------------------------------------------  // acclient.c:625853
void __userpurge PFileNode::ReportErrorInternal(PFileNode *this@<ecx>, int a2@<edi>, PStringBase<char> *msg)
{
  PFileNode *v3; // esi@1
  PFileNode *v4; // ecx@1
  FileNodeFileInfo *v5; // eax@2
  PSRefBufferCharData<char> *v6; // esi@4
  int v7; // esi@4
  PStringBase<char> rName; // [sp+0h] [bp-4h]@1

  rName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v3 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PFileNode::GetNameAsPString(v3, a2, &rName);
  v4 = v3->m_pcParent;
  if ( v4 )
    v5 = PFileNode::GetFileInfo(v4);
  else
    v5 = v3->m_fileInfo.m_data;
  v6 = rName.m_charbuffer;
  ++v5->m_errorCount;
  v7 = (int)&v6[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) )
  {
    if ( v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  }
}

//----- (0065BF30) --------------------------------------------------------  // acclient.c:625882
void __userpurge PFileNode::ReportWarningInternal(PFileNode *this@<ecx>, int a2@<edi>, PStringBase<char> *msg)
{
  PFileNode *v3; // esi@1
  PFileNode *v4; // ecx@1
  FileNodeFileInfo *v5; // eax@2
  PSRefBufferCharData<char> *v6; // esi@4
  int v7; // esi@4
  PStringBase<char> rName; // [sp+0h] [bp-4h]@1

  rName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v3 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PFileNode::GetNameAsPString(v3, a2, &rName);
  v4 = v3->m_pcParent;
  if ( v4 )
    v5 = PFileNode::GetFileInfo(v4);
  else
    v5 = v3->m_fileInfo.m_data;
  v6 = rName.m_charbuffer;
  ++v5->m_warningCount;
  v7 = (int)&v6[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) )
  {
    if ( v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  }
}

//----- (0065BF90) --------------------------------------------------------  // acclient.c:625911
void __thiscall PFileNodeIter::PFileNodeIter(PFileNodeIter *this, PFileNode *_file_node)
{
  volatile LONG *v2; // ST00_4@1

  this->file_node = _file_node;
  this->curr_index = 0;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->search_string.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
}

//----- (0065BFC0) --------------------------------------------------------  // acclient.c:625923
void __thiscall IntrusiveSmartPointer<FileNodeFileInfo>::create(IntrusiveSmartPointer<FileNodeFileInfo> *this)
{
  IntrusiveSmartPointer<FileNodeFileInfo> *v1; // edi@1
  FileNodeFileInfo *v2; // esi@1
  void *v3; // eax@5
  void *v4; // esi@5
  volatile LONG *v5; // ST00_4@6

  v1 = this;
  v2 = this->m_data;
  if ( this->m_data && !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v3 = operator new(0x14u);
  v4 = v3;
  if ( v3 )
  {
    *((_DWORD *)v3 + 1) = 1;
    *(_DWORD *)v3 = &FileNodeFileInfo::vftable;
    v5 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    *((_DWORD *)v3 + 2) = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v5);
    *((_WORD *)v4 + 6) = 0;
    *((_WORD *)v4 + 7) = 0;
    *((_DWORD *)v4 + 4) = 0;
    v1->m_data = (FileNodeFileInfo *)v4;
  }
  else
  {
    v1->m_data = 0;
  }
}
// 7FDA1C: using guessed type int (__thiscall *FileNodeFileInfo::vftable)(void *, char);

//----- (0065C040) --------------------------------------------------------  // acclient.c:625957
char __thiscall SmartArray<PFileNode *,1>::shrink(SmartArray<PFileNode *,1> *this)
{
  SmartArray<PFileNode *,1> *v1; // esi@1
  unsigned int v2; // eax@1
  void *v4; // edi@4
  int i; // eax@5
  unsigned int v6; // edx@12

  v1 = this;
  v2 = this->m_num;
  if ( v2 == (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
    return 0;
  if ( v2 )
  {
    v4 = operator new[](4 * v2);
    if ( !v4 )
      return 0;
    for ( i = v1->m_num - 1; i >= 0; *((_DWORD *)v4 + i + 1) = v1->m_data[i + 1] )
      --i;
  }
  else
  {
    v4 = 0;
  }
  if ( (v1->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_data);
  v6 = v1->m_num;
  v1->m_data = (PFileNode **)v4;
  v1->m_sizeAndDeallocate = v6 | 0x80000000;
  return 1;
}

//----- (0065C0D0) --------------------------------------------------------  // acclient.c:625990
PFileNode **__cdecl _STL::__unguarded_partition<PFileNode * *,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(PFileNode **__first, PFileNode **__last, PFileNode *__pivot, bool (__cdecl *__comp)(PFileNode *, PFileNode *))
{
  PFileNode **v4; // esi@1
  PFileNode **i; // edi@1
  PFileNode *v6; // ecx@3
  PFileNode *v7; // edx@4
  PFileNode *v8; // eax@5
  PFileNode *v9; // eax@7

  v4 = __last;
  for ( i = __first; ; ++i )
  {
    if ( __comp(*i, __pivot) )
    {
      do
      {
        v6 = i[1];
        ++i;
      }
      while ( __comp(v6, __pivot) );
    }
    v7 = *(v4 - 1);
    --v4;
    if ( __comp(__pivot, v7) )
    {
      do
      {
        v8 = *(v4 - 1);
        --v4;
      }
      while ( __comp(__pivot, v8) );
    }
    if ( i >= v4 )
      break;
    v9 = *i;
    *i = *v4;
    *v4 = v9;
  }
  return i;
}

//----- (0065C140) --------------------------------------------------------  // acclient.c:626032
void __cdecl _STL::__make_heap<PFileNode * *,bool (__cdecl *)(PFileNode const *,PFileNode const *),PFileNode *,int>(PFileNode **__first, PFileNode **__last, bool (__cdecl *__comp)(PFileNode *, PFileNode *))
{
  int v3; // ebx@1
  int v4; // esi@2
  PFileNode *v5; // ecx@3

  v3 = __last - __first;
  if ( v3 >= 2 )
  {
    v4 = (v3 - 2) / 2;
    _STL::__adjust_heap<PFileNode * *,int,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
      __first,
      v4,
      __last - __first,
      __first[v4],
      __comp);
    while ( v4 )
    {
      v5 = __first[v4-- - 1];
      _STL::__adjust_heap<PFileNode * *,int,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
        __first,
        v4,
        v3,
        v5,
        __comp);
    }
  }
}

//----- (0065C1A0) --------------------------------------------------------  // acclient.c:626062
void __thiscall PFileNode::PFileNode(PFileNode *this)
{
  PFileNode *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&PFileNode::vftable;
  this->m_pcName = 0;
  this->line_number = 0;
  this->column_number = 0;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->comment_string.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_filename.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v1->sub_nodes.m_data = 0;
  v1->sub_nodes.m_sizeAndDeallocate = 0;
  v1->sub_nodes.m_num = 0;
  v1->m_bProcessed = 0;
  v1->m_fileInfo.m_data = 0;
  v1->m_pcParent = 0;
  v1->user_data = 0;
}
// 7FDA20: using guessed type int (__stdcall *PFileNode::vftable)(char);

//----- (0065C210) --------------------------------------------------------  // acclient.c:626091
void __thiscall PFileNode::Destroy(PFileNode *this)
{
  PFileNode *v1; // ebp@1
  IFileNodeName *v2; // ecx@1
  unsigned int v3; // ebx@3
  int v4; // esi@5
  unsigned int v5; // eax@5
  PFileNode **v6; // ecx@6
  int v7; // eax@6
  int v8; // edi@6
  int v9; // ecx@6
  PSRefBufferCharData<char> *v10; // eax@12
  int v11; // esi@13
  volatile LONG *v12; // ST00_4@16
  FileNodeFileInfo *v13; // esi@17
  PSRefBufferCharData<char> *v14; // eax@21
  int v15; // esi@22
  volatile LONG *v16; // ST00_4@25

  v1 = this;
  v2 = this->m_pcName;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v3 = v1->sub_nodes.m_num;
  v1->m_pcName = 0;
  while ( v3 )
  {
    --v3;
    if ( v3 < v1->sub_nodes.m_num )
    {
      v4 = (int)v1->vfptr[2].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v1, v3);
      v5 = v1->sub_nodes.m_num;
      if ( v3 < v5 )
      {
        v6 = v1->sub_nodes.m_data;
        v7 = v5 - 1;
        v8 = (int)&v6[v3];
        v9 = (int)&v6[v7];
        v1->sub_nodes.m_num = v7;
        if ( v8 < (unsigned int)v9 )
          qmemcpy((void *)v8, (const void *)(v8 + 4), 4 * (((unsigned int)(v9 - v8 - 1) >> 2) + 1));
        v1->sub_nodes.m_data[v1->sub_nodes.m_num] = 0;
      }
      *(_DWORD *)(v4 + 44) = 0;
      if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
  }
  v1->line_number = 0;
  v1->column_number = 0;
  v10 = v1->comment_string.m_charbuffer;
  if ( v10 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v11 = (int)&v10[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v10[-1]) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    v12 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->comment_string.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v12);
  }
  v1->m_bProcessed = 0;
  v13 = v1->m_fileInfo.m_data;
  if ( v13 && !InterlockedDecrement((volatile LONG *)&v13->m_cRef) && v13 )
    v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
  v1->m_fileInfo.m_data = 0;
  v14 = v1->m_filename.m_charbuffer;
  if ( v14 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v15 = (int)&v14[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v14[-1]) )
    {
      if ( v15 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    }
    v16 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_filename.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v16);
  }
}

//----- (0065C360) --------------------------------------------------------  // acclient.c:626172
char __thiscall PFileNode::RemoveSubNodePtr(PFileNode *this, PFileNode *node)
{
  PFileNode *v2; // edi@1
  PFileNode **v3; // ebx@1
  char *v4; // esi@1
  PFileNode *const *v5; // eax@1
  int v6; // eax@2
  unsigned int v7; // ebx@2
  char result; // al@3
  int v9; // edi@5

  v2 = this;
  v3 = this->sub_nodes.m_data;
  v4 = (char *)&this->sub_nodes;
  v5 = _STL::__find<PFileNode * const *,PFileNode const *>(this->sub_nodes.m_data, &v3[this->sub_nodes.m_num], &node);
  if ( v5 != &v3[*((_DWORD *)v4 + 2)] && (v6 = v5 - v3, v7 = v6, v6 != -1) )
  {
    if ( v6 < v2->sub_nodes.m_num )
    {
      v9 = (int)v2->vfptr[2].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, v6);
      SmartArray<PFileNode *,1>::RemoveOrderedByIndex((SmartArray<PFileNode *,1> *)v4, v7);
      *(_DWORD *)(v9 + 44) = 0;
      if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0065C3F0) --------------------------------------------------------  // acclient.c:626207
void __thiscall PFileNode::InitFileInfo(PFileNode *this, PStringBase<char> *i_filename)
{
  char *v2; // esi@1
  int v3; // esi@3
  PSRefBufferCharData<char> *v4; // eax@4
  int v5; // edi@5
  PSRefBufferCharData<char> *v6; // eax@8

  v2 = (char *)&this->m_fileInfo;
  if ( !this->m_fileInfo.m_data )
    IntrusiveSmartPointer<FileNodeFileInfo>::create(&this->m_fileInfo);
  v3 = *(_DWORD *)v2;
  if ( v3 )
  {
    v4 = *(PSRefBufferCharData<char> **)(v3 + 8);
    if ( v4 != i_filename->m_charbuffer )
    {
      v5 = (int)&v4[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) )
      {
        if ( v5 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      }
      v6 = i_filename->m_charbuffer;
      *(_DWORD *)(v3 + 8) = i_filename->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v6[-1]);
    }
  }
}

//----- (0065C450) --------------------------------------------------------  // acclient.c:626238
void __cdecl SB_TypeAlloc<IFileNodeNameResolver,SB_Default>::Serialize<int,IFileNodeName *>(SB_TypeAlloc<IFileNodeNameResolver,SB_Default> *this, const int *_class, IFileNodeName **_obj)
{
  IFileNodeName **v3; // esi@1
  IFileNodeName **v4; // ebx@2
  unsigned int v5; // eax@4
  const int v6; // eax@11
  unsigned __int8 _arca; // [sp+18h] [bp+Ch]@4

  v3 = _obj;
  if ( *((_BYTE *)_obj + 4) & 1 )
    v4 = (IFileNodeName **)IFileNodeName::GetNameType(*(IFileNodeName **)_class);
  else
    v4 = _obj;
  _arca = (unsigned __int8)v4;
  Archive::CheckAlignment((Archive *)v3, 1u);
  v5 = Archive::GetBytes((Archive *)v3, 1u);
  if ( v5 )
  {
    if ( *((_BYTE *)v3 + 4) & 1 )
      *(_BYTE *)v5 = (_BYTE)v4;
    else
      _arca = *(_BYTE *)v5;
  }
  if ( !(*((_BYTE *)v3 + 4) & 5) )
    v4 = (IFileNodeName **)_arca;
  if ( ~*((_BYTE *)v3 + 4) & 1 )
  {
    IFileNodeName::CreateFromEnum((NodeNameType)v4);
    *_class = v6;
  }
  if ( *_class )
    (*(void (__stdcall **)(IFileNodeName **))(**(_DWORD **)_class + 24))(v3);
}

//----- (0065C4D0) --------------------------------------------------------  // acclient.c:626273
void __thiscall PFileNode::~PFileNode(PFileNode *this)
{
  PFileNode *v1; // esi@1
  FileNodeFileInfo *v2; // edi@1
  int v3; // edi@7
  int v4; // edi@10

  v1 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&PFileNode::vftable;
  PFileNode::Destroy(this);
  v2 = v1->m_fileInfo.m_data;
  if ( v2 && !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  if ( (v1->sub_nodes.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->sub_nodes.m_data);
  v3 = (int)&v1->m_filename.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = (int)&v1->comment_string.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 7FDA20: using guessed type int (__stdcall *PFileNode::vftable)(char);

//----- (0065C560) --------------------------------------------------------  // acclient.c:626300
PStringBase<char> *__thiscall PFileNode::GetSourceFileName(PFileNode *this)
{
  PFileNode *v1; // esi@1
  PFileNode *v2; // ecx@3
  FileNodeFileInfo *v3; // eax@4
  PStringBase<char> *result; // eax@7

  v1 = this;
  if ( !(_S76_1 & 1) )
  {
    _S76_1 |= 1u;
    PStringBase<char>::PStringBase<char>(&unknown_file, "<unknown>");
    atexit(sub_77EDF0);
  }
  v2 = v1->m_pcParent;
  if ( v2 )
    v3 = PFileNode::GetFileInfo(v2);
  else
    v3 = v1->m_fileInfo.m_data;
  if ( v3 )
    result = &v3->m_filename;
  else
    result = &unknown_file;
  return result;
}

//----- (0065C5C0) --------------------------------------------------------  // acclient.c:626327
char __thiscall PFileNode::AddComment(PFileNode *this, PStringBase<char> *new_comment)
{
  PStringBase<char> *v2; // edi@1
  PFileNode *v3; // ebx@1
  int v4; // ecx@1
  int v5; // esi@2
  PSRefBufferCharData<char> *v6; // eax@4
  unsigned int v7; // edx@4
  int v8; // eax@5

  v2 = new_comment;
  v3 = this;
  v4 = *(_DWORD *)&new_comment->m_charbuffer[-1].m_data[12];
  if ( v4 != 1 )
  {
    v5 = *(_DWORD *)&new_comment->m_charbuffer[-1].m_data[12];
    if ( v4 != 1 )
      PStringBase<char>::append_n_chars(&v3->comment_string, new_comment->m_charbuffer->m_data, v4 - 1);
    v6 = v2->m_charbuffer;
    v7 = *(_DWORD *)&v2->m_charbuffer[-1].m_data[12];
    if ( v5 - 2 < v7 )
      v8 = (int)((char *)v6 + v5 - 2);
    else
      v8 = (int)((char *)v6 + v7 - 1);
    if ( *(_BYTE *)v8 != 10 )
    {
      LOBYTE(new_comment) = 10;
      PStringBase<char>::append_n_chars(&v3->comment_string, (const char *)&new_comment, 1u);
    }
  }
  return 1;
}

//----- (0065C620) --------------------------------------------------------  // acclient.c:626361
void __usercall PFileNode::ReportError(int a1@<edi>, PFileNode *this, PStringBase<char> fmt)
{
  char *v3; // esi@1
  char args; // [sp+10h] [bp+Ch]@0

  PStringBase<char>::vsprintf(&fmt, fmt.m_charbuffer->m_data, &args);
  PFileNode::ReportErrorInternal(this, a1, &fmt);
  v3 = &fmt.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&fmt.m_charbuffer[-1]) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}
// 65C620: erroneously detected ellipsis type has been ignored

//----- (0065C670) --------------------------------------------------------  // acclient.c:626378
void __usercall PFileNode::ReportWarning(int a1@<edi>, PFileNode *this, PStringBase<char> fmt)
{
  char *v3; // esi@1
  char args; // [sp+10h] [bp+Ch]@0

  PStringBase<char>::vsprintf(&fmt, fmt.m_charbuffer->m_data, &args);
  PFileNode::ReportWarningInternal(this, a1, &fmt);
  v3 = &fmt.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&fmt.m_charbuffer[-1]) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}
// 65C670: erroneously detected ellipsis type has been ignored

//----- (0065C6C0) --------------------------------------------------------  // acclient.c:626395
void __cdecl _STL::__insertion_sort<PFileNode * *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(PFileNode **__first, PFileNode **__last, bool (__cdecl *__comp)(PFileNode *, PFileNode *))
{
  PFileNode **v3; // esi@2
  size_t v4; // edi@3
  PFileNode *v5; // ebx@4

  if ( __first != __last )
  {
    v3 = __first + 1;
    if ( __first + 1 != __last )
    {
      v4 = 4;
      do
      {
        v5 = *v3;
        if ( __comp(*v3, *__first) )
        {
          if ( (signed int)v4 > 0 )
            _memmove(&v3[-v4 / 4 + 1], __first, v4);
          *__first = v5;
        }
        else
        {
          _STL::__unguarded_linear_insert<PFileNode * *,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
            v3,
            v5,
            __comp);
        }
        ++v3;
        v4 += 4;
      }
      while ( v3 != __last );
    }
  }
}

//----- (0065C730) --------------------------------------------------------  // acclient.c:626432
void __cdecl _STL::sort_heap<PFileNode * *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(PFileNode **__first, PFileNode **__last, bool (__cdecl *__comp)(PFileNode *, PFileNode *))
{
  signed int v3; // eax@1
  PFileNode *v4; // ecx@2
  int v5; // edi@2

  v3 = (char *)__last - (char *)__first;
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(PFileNode **)((char *)__first + v3 - 4);
      v5 = v3 - 4;
      *(PFileNode **)((char *)__first + v3 - 4) = *__first;
      _STL::__adjust_heap<PFileNode * *,int,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (signed int)(v5 & 0xFFFFFFFC) > 4 );
  }
}

//----- (0065C780) --------------------------------------------------------  // acclient.c:626459
char *__thiscall PFileNode::scalar_deleting_destructor(PFileNode *this, unsigned int a2)
{
  char *v2; // esi@1

  v2 = (char *)this;
  PFileNode::~PFileNode(this);
  if ( a2 & 1 )
  {
    *(_DWORD *)v2 = PFileNode::s_fallocPool.m_firstFreeChunk;
    PFileNode::s_fallocPool.m_firstFreeChunk = v2;
  }
  return v2;
}

//----- (0065C7B0) --------------------------------------------------------  // acclient.c:626474
void __thiscall PFileNode::AdoptSubNode(PFileNode *this, PFileNode *new_subnode)
{
  PFileNode *v2; // edi@1
  char *v3; // esi@2
  unsigned int v4; // eax@2
  unsigned int v5; // eax@3

  v2 = this;
  if ( new_subnode )
  {
    v3 = (char *)&this->sub_nodes;
    v4 = this->sub_nodes.m_sizeAndDeallocate & 0x7FFFFFFF;
    if ( this->sub_nodes.m_num < v4
      || (v5 = SmartArray<char *,1>::get_new_size(v4 + 1),
          SmartArray<Logger::ILoggingOutputHandler *,1>::grow((SmartArray<unsigned short *,1> *)&v2->sub_nodes, v5)) )
      *(_DWORD *)(*(_DWORD *)v3 + 4 * v2->sub_nodes.m_num++) = new_subnode;
    new_subnode->m_pcParent = v2;
  }
}

//----- (0065C800) --------------------------------------------------------  // acclient.c:626495
void __cdecl SB_Container<SB_Alloc<SB_DefaultAllocator,0,SB_Default>,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize<int,SmartArray<PFileNode *,1>>(SB_Container<SB_Alloc<SB_DefaultAllocator,0,SB_Default>,&SB_DEFAULT_ITEM_NAME> *this, const int *_class, SmartArray<PFileNode *,1> *_obj)
{
  SmartArray<PFileNode *,1> *v3; // ebp@1
  const int *v4; // edi@1
  char v5; // bl@1
  unsigned int v6; // eax@2
  const int *v7; // esi@2
  unsigned int v8; // eax@4
  const int v9; // esi@9
  char *v10; // ecx@14
  int v11; // eax@14

  v3 = _obj;
  v4 = _class;
  _class = (const int *)_class[2];
  SB_As32Bit_Compressed::Serialize<int,unsigned long>((int)this, (int)&_class, (char)_obj);
  v5 = 0;
  if ( ~LOBYTE(v3->m_sizeAndDeallocate) & 1 )
  {
    v6 = Archive::GetSizeLeft((Archive *)v3);
    v7 = _class;
    if ( (unsigned int)_class > v6 )
    {
      Archive::RaiseError((Archive *)v3);
      return;
    }
    v8 = v4[2];
    if ( (unsigned int)_class <= v8 )
    {
      if ( (unsigned int)_class < v8 )
      {
        *((_DWORD *)v4 + 2) = _class;
        SmartArray<PFileNode *,1>::shrink((SmartArray<PFileNode *,1> *)v4);
      }
    }
    else
    {
      SmartArray<Logger::ILoggingOutputHandler *,1>::grow((SmartArray<unsigned short *,1> *)v4, (unsigned int)_class);
      *((_DWORD *)v4 + 2) = v7;
    }
    v5 = 1;
  }
  v9 = *v4;
  if ( *v4 != *v4 + 4 * v4[2] )
  {
    while ( 1 )
    {
      if ( !((v3->m_sizeAndDeallocate >> 2) & 1) )
      {
        if ( ~LOBYTE(v3->m_sizeAndDeallocate) & 1 )
        {
          if ( !PFileNode::s_fallocPool.m_firstFreeChunk )
            FallocPool::AllocateNewPool(&PFileNode::s_fallocPool);
          v10 = PFileNode::s_fallocPool.m_firstFreeChunk;
          PFileNode::s_fallocPool.m_firstFreeChunk = *(char **)PFileNode::s_fallocPool.m_firstFreeChunk;
          PFileNode::PFileNode((PFileNode *)v10);
          *(_DWORD *)v9 = v11;
        }
        if ( *(_DWORD *)v9 )
          (*(void (__stdcall **)(SmartArray<PFileNode *,1> *))(**(_DWORD **)v9 + 20))(v3);
        else
          Archive::RaiseError((Archive *)v3);
      }
      if ( (v3->m_sizeAndDeallocate >> 2) & 1 )
        break;
      v9 += 4;
      if ( v9 == *v4 + 4 * v4[2] )
        return;
    }
    if ( v5 )
    {
      if ( v4[2] )
      {
        *((_DWORD *)v4 + 2) = 0;
        SmartArray<PFileNode *,1>::shrink((SmartArray<PFileNode *,1> *)v4);
      }
    }
  }
}

//----- (0065C910) --------------------------------------------------------  // acclient.c:626576
void __cdecl _STL::__final_insertion_sort<PFileNode * *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(PFileNode **__first, PFileNode **__last, bool (__cdecl *__comp)(PFileNode *, PFileNode *))
{
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    _STL::__insertion_sort<PFileNode * *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(__first, __last, __comp);
  }
  else
  {
    _STL::__insertion_sort<PFileNode * *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
      __first,
      __first + 16,
      __comp);
    _STL::__unguarded_insertion_sort_aux<PFileNode * *,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
      __first + 16,
      __last,
      0,
      __comp);
  }
}

//----- (0065C960) --------------------------------------------------------  // acclient.c:626597
void __cdecl _STL::__partial_sort<PFileNode * *,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(PFileNode **__first, PFileNode **__middle, PFileNode **__last, PFileNode **__formal, bool (__cdecl *__comp)(PFileNode *, PFileNode *))
{
  PFileNode **i; // esi@1
  PFileNode *v6; // ST0C_4@3

  _STL::__make_heap<PFileNode * *,bool (__cdecl *)(PFileNode const *,PFileNode const *),PFileNode *,int>(
    __first,
    __middle,
    __comp);
  for ( i = __middle; i < __last; ++i )
  {
    if ( __comp(*i, *__first) )
    {
      v6 = *i;
      *i = *__first;
      _STL::__adjust_heap<PFileNode * *,int,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
        __first,
        0,
        __middle - __first,
        v6,
        __comp);
    }
  }
  _STL::sort_heap<PFileNode * *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(__first, __middle, __comp);
}

//----- (0065C9D0) --------------------------------------------------------  // acclient.c:626624
PFileNode *__thiscall PFileNode::MakeSubNode(PFileNode *this)
{
  PFileNode *v1; // edi@1
  char *v2; // ecx@3
  PFileNode *v3; // eax@3
  PFileNode *v4; // esi@3

  v1 = this;
  if ( !PFileNode::s_fallocPool.m_firstFreeChunk )
    FallocPool::AllocateNewPool(&PFileNode::s_fallocPool);
  v2 = PFileNode::s_fallocPool.m_firstFreeChunk;
  PFileNode::s_fallocPool.m_firstFreeChunk = *(char **)PFileNode::s_fallocPool.m_firstFreeChunk;
  PFileNode::PFileNode((PFileNode *)v2);
  v4 = v3;
  if ( v3 )
    PFileNode::AdoptSubNode(v1, v3);
  return v4;
}

//----- (0065CA10) --------------------------------------------------------  // acclient.c:626644
void __thiscall PFileNode::Serialize(PFileNode *this, Archive *io_archive)
{
  Archive *v2; // ebx@1
  PFileNode *v3; // esi@1
  unsigned int v4; // ecx@4
  unsigned int v5; // eax@4
  PFileNode *v6; // edx@5

  v2 = io_archive;
  v3 = this;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
  {
    PFileNode::Destroy(this);
    v3->m_pcParent = 0;
  }
  SB_TypeAlloc<IFileNodeNameResolver,SB_Default>::Serialize<int,IFileNodeName *>(
    (SB_TypeAlloc<IFileNodeNameResolver,SB_Default> *)&io_archive,
    (const int *)&v3->m_pcName,
    (IFileNodeName **)v2);
  SB_Container<SB_Alloc<SB_DefaultAllocator,0,SB_Default>,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize<int,SmartArray<PFileNode *,1>>(
    (SB_Container<SB_Alloc<SB_DefaultAllocator,0,SB_Default>,&SB_DEFAULT_ITEM_NAME> *)&io_archive,
    (const int *)&v3->sub_nodes,
    (SmartArray<PFileNode *,1> *)v2);
  if ( ~LOBYTE(v2->m_flags) & 1 )
  {
    v4 = v3->sub_nodes.m_num;
    v5 = 0;
    if ( v4 )
    {
      do
      {
        v6 = v3->sub_nodes.m_data[v5++];
        v6->m_pcParent = v3;
      }
      while ( v5 < v4 );
    }
  }
}

//----- (0065CA80) --------------------------------------------------------  // acclient.c:626684
void __cdecl _STL::__introsort_loop<PFileNode * *,PFileNode *,int,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(PFileNode **__first, PFileNode **__last, PFileNode **__formal, int __depth_limit, bool (__cdecl *__comp)(PFileNode *, PFileNode *))
{
  PFileNode **v5; // edi@1
  signed int v6; // eax@1
  PFileNode **v7; // eax@3
  PFileNode **v8; // esi@3

  v5 = __last;
  v6 = (char *)__last - (char *)__first;
  LOBYTE(v6) = ((_BYTE)__last - (_BYTE)__first) & 0xFC;
  if ( v6 > 64 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v7 = (PFileNode **)_STL::__median<PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
                           __first,
                           &__first[(v5 - __first) / 2],
                           v5 - 1,
                           __comp);
      v8 = _STL::__unguarded_partition<PFileNode * *,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
             __first,
             v5,
             *v7,
             __comp);
      _STL::__introsort_loop<PFileNode * *,PFileNode *,int,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
        v8,
        v5,
        0,
        __depth_limit,
        __comp);
      v5 = v8;
      if ( (signed int)(((char *)v8 - (char *)__first) & 0xFFFFFFFC) <= 64 )
        return;
    }
    _STL::__partial_sort<PFileNode * *,PFileNode *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
      __first,
      v5,
      v5,
      0,
      __comp);
  }
}

//----- (0065CB10) --------------------------------------------------------  // acclient.c:626729
void __cdecl _STL::sort<PFileNode * *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(PFileNode **__first, PFileNode **__last, bool (__cdecl *__comp)(PFileNode *, PFileNode *))
{
  signed int v3; // eax@2
  int i; // ecx@2

  if ( __first != __last )
  {
    v3 = __last - __first;
    for ( i = 0; v3 != 1; ++i )
      v3 >>= 1;
    _STL::__introsort_loop<PFileNode * *,PFileNode *,int,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
      __first,
      __last,
      0,
      2 * i,
      __comp);
    _STL::__final_insertion_sort<PFileNode * *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
      __first,
      __last,
      __comp);
  }
}

//----- (0065CB60) --------------------------------------------------------  // acclient.c:626753
void __thiscall PFileNode::SortSubNodes(PFileNode *this)
{
  _STL::sort<PFileNode * *,bool (__cdecl *)(PFileNode const *,PFileNode const *)>(
    this->sub_nodes.m_data,
    &this->sub_nodes.m_data[this->sub_nodes.m_num],
    (bool (__cdecl *)(PFileNode *, PFileNode *))PFileNodeSorter);
}

//----- (00714C10) --------------------------------------------------------  // acclient.c:807601
int sub_714C10()
{
  FallocPool::FallocPool(&PFileNode::s_fallocPool, 0x34u, 0x2000u, 0);
  return atexit(sub_77EDE0);
}

//----- (0077EDE0) --------------------------------------------------------  // acclient.c:917986
void __cdecl sub_77EDE0()
{
  FallocPool::~FallocPool(&PFileNode::s_fallocPool);
}

//----- (0077EDF0) --------------------------------------------------------  // acclient.c:917992
void __cdecl sub_77EDF0()
{
  char *v0; // esi@1

  v0 = &unknown_file.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&unknown_file.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

