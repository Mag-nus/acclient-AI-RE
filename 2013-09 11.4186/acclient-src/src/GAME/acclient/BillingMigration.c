/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : BillingMigration
   Object     : GAME\acclient\BillingMigration.obj
   Functions  : 17
   Addresses  : 00404940 - 004050A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00404940) --------------------------------------------------------  // acclient.c:63466
int __thiscall PStringBase<char>::cmp(PStringBase<char> *this, PStringBase<char> *rhs, bool case_sensitive)
{
  int result; // eax@2

  if ( case_sensitive )
    result = strcmp(this->m_charbuffer->m_data, rhs->m_charbuffer->m_data);
  else
    result = __stricmp(this->m_charbuffer->m_data, rhs->m_charbuffer->m_data);
  return result;
}

//----- (004049A0) --------------------------------------------------------  // acclient.c:63478
int __cdecl _STL::__node_alloc<1,0>::_S_chunk_alloc(unsigned int _p_size, int *__nobjs)
{
  int result; // eax@1
  unsigned int v3; // ecx@1
  unsigned int v4; // edx@1
  unsigned int v5; // esi@2
  unsigned int v6; // edi@4
  unsigned int v7; // ecx@5
  unsigned int v8; // ecx@7
  unsigned int v9; // edx@8
  int *v10; // edx@8
  char *v11; // edx@11
  unsigned int v12; // eax@15
  int v13; // edx@15

  result = _STL::__node_alloc<1,0>::_S_start_free;
  v3 = _p_size * *__nobjs;
  v4 = _STL::__node_alloc<1,0>::_S_end_free - _STL::__node_alloc<1,0>::_S_start_free;
  if ( _STL::__node_alloc<1,0>::_S_end_free - _STL::__node_alloc<1,0>::_S_start_free >= v3 )
  {
LABEL_13:
    _STL::__node_alloc<1,0>::_S_start_free = v3 + result;
    return result;
  }
  v5 = _STL::__node_alloc<1,0>::_S_heap_size;
  while ( v4 < _p_size )
  {
    v6 = (((v5 >> 4) + 7) & 0xFFFFFFF8) + 2 * v3;
    if ( v4 )
    {
      v7 = (v4 - 1) >> 3;
      *(_DWORD *)result = _STL::__node_alloc<1,0>::_S_free_list[v7];
      _STL::__node_alloc<1,0>::_S_free_list[v7] = _STL::__node_alloc<1,0>::_S_start_free;
    }
    result = (int)operator new(v6);
    _STL::__node_alloc<1,0>::_S_start_free = result;
    if ( !result )
    {
      v8 = _p_size;
      if ( _p_size <= 0x80 )
      {
        while ( 1 )
        {
          v9 = (v8 - 1) >> 3;
          result = _STL::__node_alloc<1,0>::_S_free_list[v9];
          v10 = &_STL::__node_alloc<1,0>::_S_free_list[v9];
          if ( result )
            break;
          v8 += 8;
          if ( v8 > 0x80 )
            goto LABEL_10;
        }
        *v10 = *(_DWORD *)result;
        v5 = _STL::__node_alloc<1,0>::_S_heap_size;
        _STL::__node_alloc<1,0>::_S_start_free = result;
        v11 = (char *)(result + v8);
        goto LABEL_12;
      }
LABEL_10:
      _STL::__node_alloc<1,0>::_S_end_free = 0;
      result = (int)operator new(v6);
      _STL::__node_alloc<1,0>::_S_start_free = result;
    }
    v5 = v6 + _STL::__node_alloc<1,0>::_S_heap_size;
    _STL::__node_alloc<1,0>::_S_heap_size += v6;
    v11 = (char *)(result + v6);
LABEL_12:
    _STL::__node_alloc<1,0>::_S_end_free = (int)v11;
    v3 = _p_size * *__nobjs;
    v4 = (unsigned int)&v11[-result];
    if ( v4 >= v3 )
      goto LABEL_13;
  }
  *__nobjs = v4 / _p_size;
  v12 = _p_size * (v4 / _p_size);
  v13 = _STL::__node_alloc<1,0>::_S_start_free;
  _STL::__node_alloc<1,0>::_S_start_free += v12;
  return v13;
}
// 8366C8: using guessed type int _STL::__node_alloc<1,0>::_S_free_list[];
// 836708: using guessed type int _STL::__node_alloc<1,0>::_S_heap_size;
// 83670C: using guessed type int _STL::__node_alloc<1,0>::_S_start_free;
// 836710: using guessed type int _STL::__node_alloc<1,0>::_S_end_free;

//----- (00404AD0) --------------------------------------------------------  // acclient.c:63563
void __thiscall PStringBase<char>::clear(PStringBase<char> *this)
{
  PStringBase<char> *v1; // edi@1
  PSRefBufferCharData<char> *v2; // eax@1
  int v3; // esi@2
  volatile LONG *v4; // ST00_4@5

  v1 = this;
  v2 = this->m_charbuffer;
  if ( this->m_charbuffer != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v4);
  }
}

//----- (00404B20) --------------------------------------------------------  // acclient.c:63587
BOOL __thiscall PStringBase<char>::eq(PStringBase<char> *this, PStringBase<char> *rhs, bool case_sensitive)
{
  return PStringBase<char>::cmp(this, rhs, case_sensitive) == 0;
}

//----- (00404B40) --------------------------------------------------------  // acclient.c:63593
int __thiscall PStringBase<char>::find_substring(PStringBase<char> *this, PStringBase<char> *str)
{
  PStringBase<char> *v2; // esi@1
  char *v3; // eax@1
  int result; // eax@2

  v2 = this;
  v3 = _strstr(this->m_charbuffer->m_data, str->m_charbuffer->m_data);
  if ( v3 )
    result = v3 - (char *)v2->m_charbuffer;
  else
    result = -1;
  return result;
}

//----- (00404B70) --------------------------------------------------------  // acclient.c:63609
unsigned __int32 __thiscall PStringBase<char>::to_uint32(PStringBase<char> *this)
{
  PSRefBufferCharData<char> *v1; // esi@1

  v1 = this->m_charbuffer;
  *__errno() = 0;
  return _strtoul(v1->m_data, 0, 0);
}

//----- (00404B90) --------------------------------------------------------  // acclient.c:63619
void __cdecl _STL::_STLP_mutex_spin<0>::_M_do_lock(volatile int *__lock)
{
  int v1; // edi@2
  int v2; // esi@2
  unsigned int v3; // ebx@3
  signed int v4; // edi@11
  signed int v5; // esi@12
  volatile unsigned int __junk; // [sp+4h] [bp-4h]@2

  if ( InterlockedExchange(__lock, 1) )
  {
    v1 = _STL::_STLP_mutex_spin<0>::__max;
    v2 = 0;
    __junk = 17;
    if ( _STL::_STLP_mutex_spin<0>::__max )
    {
      v3 = (unsigned int)_STL::_STLP_mutex_spin<0>::__last >> 1;
      do
      {
        if ( v2 < v3 || *__lock )
        {
          __junk *= __junk
                  * __junk
                  * __junk
                  * __junk
                  * __junk
                  * __junk
                  * __junk
                  * __junk
                  * __junk
                  * __junk
                  * __junk
                  * __junk
                  * __junk
                  * __junk
                  * __junk;
        }
        else if ( !InterlockedExchange(__lock, 1) )
        {
          _STL::_STLP_mutex_spin<0>::__last = v2;
          _STL::_STLP_mutex_spin<0>::__max = 1000;
          return;
        }
        ++v2;
      }
      while ( v2 < (unsigned int)v1 );
    }
    _STL::_STLP_mutex_spin<0>::__max = 30;
    v4 = 6;
    while ( 1 )
    {
      v5 = v4;
      if ( v4 > 27 )
        v5 = 27;
      if ( !InterlockedExchange(__lock, 1) )
        break;
      if ( v5 > 20 )
      {
        Sleep(1 << (v5 - 20));
        ++v4;
      }
      else
      {
        Sleep(1u);
        ++v4;
      }
    }
  }
}
// 817298: using guessed type int _STL::_STLP_mutex_spin<0>::__max;
// 836714: using guessed type int _STL::_STLP_mutex_spin<0>::__last;

//----- (00404C80) --------------------------------------------------------  // acclient.c:63692
char *__cdecl _STL::__node_alloc<1,0>::_S_refill(unsigned int __n)
{
  unsigned int v1; // esi@1
  char *result; // eax@1
  int v3; // ebx@1
  char *v4; // edx@2
  char *v5; // ecx@2
  signed int v6; // edi@2
  int __nobjs; // [sp+0h] [bp-4h]@1

  v1 = (__n + 7) & 0xFFFFFFF8;
  __nobjs = 20;
  result = (char *)_STL::__node_alloc<1,0>::_S_chunk_alloc(v1, &__nobjs);
  v3 = __nobjs;
  if ( __nobjs != 1 )
  {
    _STL::__node_alloc<1,0>::_S_free_list[(v1 - 1) >> 3] = (int)&result[v1];
    v4 = &result[v1];
    v5 = &result[v1] + v1;
    v6 = 1;
    if ( v3 != 2 )
    {
      do
      {
        *(_DWORD *)v4 = v5;
        ++v6;
        v4 = v5;
        v5 += v1;
      }
      while ( __nobjs - 1 != v6 );
    }
    *(_DWORD *)v4 = 0;
  }
  return result;
}
// 8366C8: using guessed type int _STL::__node_alloc<1,0>::_S_free_list[];

//----- (00404CF0) --------------------------------------------------------  // acclient.c:63730
void __thiscall PStringBase<char>::append_n_chars(PStringBase<char> *this, const char *str, unsigned int count)
{
  const char *v3; // edx@1
  PStringBase<char> *v4; // esi@1
  PSRefBufferCharData<char> *v5; // eax@4
  int v6; // ebx@4
  unsigned int v7; // ecx@4
  int v8; // edi@7

  v3 = str;
  v4 = this;
  if ( str && *str && count )
  {
    v5 = this->m_charbuffer;
    v6 = *(_DWORD *)&this->m_charbuffer[-1].m_data[12];
    v7 = v6 + count;
    if ( *(_DWORD *)&v5[-1].m_data[0] != 1 || v7 > *(_DWORD *)&v5[-1].m_data[4] )
    {
      v8 = (int)&v5[-2].m_data[12];
      PStringBase<char>::allocate_ref_buffer(v4, v7 - 1);
      ps_strcpy(v4->m_charbuffer->m_data, (const char *)(v8 + 20));
      ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)v8);
      v3 = str;
    }
    else
    {
      *(_DWORD *)&v5[-1].m_data[12] = v7;
      *(_DWORD *)&v4->m_charbuffer[-1].m_data[8] = -1;
    }
    _strncpy((char *)v4->m_charbuffer + v6 - 1, v3, count);
    v4->m_charbuffer->m_data[*(_DWORD *)&v4->m_charbuffer[-1].m_data[12] - 1] = 0;
  }
}

//----- (00404D80) --------------------------------------------------------  // acclient.c:63765
PStringBase<char> *__thiscall PStringBase<char>::substring(PStringBase<char> *this, PStringBase<char> *result, unsigned int first, unsigned int last)
{
  PStringBase<char> *v4; // esi@1
  PSRefBufferCharData<char> *v5; // esi@1
  unsigned int v6; // ecx@1
  unsigned int v7; // eax@2
  PSRefBufferCharData<char> *v8; // eax@5
  char *v9; // esi@5
  PStringBase<char> retval; // [sp+0h] [bp-4h]@1

  retval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v4 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v5 = v4->m_charbuffer;
  v6 = *(_DWORD *)&v5[-1].m_data[12] - 1;
  if ( first < v6 )
  {
    v7 = last;
    if ( last >= v6 )
      v7 = *(_DWORD *)&v5[-1].m_data[12] - 2;
    PStringBase<char>::append_n_chars(&retval, (const char *)v5 + first, v7 - first + 1);
  }
  v8 = retval.m_charbuffer;
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v8[-1]);
  v9 = &retval.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&retval.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
  return result;
}

//----- (00404E00) --------------------------------------------------------  // acclient.c:63797
void __thiscall PStringBase<char>::set(PStringBase<char> *this, const char *str)
{
  PStringBase<char> *v2; // ebx@1
  unsigned int v3; // esi@3
  PStringBase<char> v4; // eax@3
  int v5; // edi@6
  PSRefBufferCharData<char> *v6; // ecx@12
  int v7; // esi@13
  volatile LONG *v8; // edx@16

  v2 = this;
  if ( str && *str )
  {
    v3 = strlen(str);
    v4.m_charbuffer = v2->m_charbuffer;
    if ( *(_DWORD *)&v2->m_charbuffer[-1].m_data[0] != 1 || *(_DWORD *)&v4.m_charbuffer[-1].m_data[4] <= v3 )
    {
      v5 = (int)&v4.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v4.m_charbuffer[-1]) )
      {
        if ( v5 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      }
      PStringBase<char>::allocate_ref_buffer(v2, v3);
    }
    else
    {
      *(_DWORD *)&v4.m_charbuffer[-1].m_data[8] = -1;
      *(_DWORD *)&v2->m_charbuffer[-1].m_data[12] = v3 + 1;
    }
    _strncpy(v2->m_charbuffer->m_data, str, v3 + 1);
  }
  else
  {
    v6 = this->m_charbuffer;
    if ( (v2->m_charbuffer != (PSRefBufferCharData<char> *)20 ? v2->m_charbuffer : 0) != PStringBase<char>::s_NullBuffer.m_charbuffer )
    {
      v7 = (int)&v6[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      v8 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
      v2->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement(v8);
    }
  }
}

//----- (00404ED0) --------------------------------------------------------  // acclient.c:63845
char *__cdecl _STL::__node_alloc<1,0>::_M_allocate(unsigned int __n)
{
  int *v1; // esi@1
  char *result; // eax@1

  v1 = &_STL::__node_alloc<1,0>::_S_free_list[(__n - 1) >> 3];
  _STL::_STLP_mutex_spin<0>::_M_do_lock(&_STL::_Node_Alloc_Lock<1,0>::_S_lock);
  result = (char *)*v1;
  if ( *v1 )
  {
    *v1 = *(_DWORD *)result;
    _STL::_Node_Alloc_Lock<1,0>::_S_lock = 0;
  }
  else
  {
    result = _STL::__node_alloc<1,0>::_S_refill(__n);
    _STL::_Node_Alloc_Lock<1,0>::_S_lock = 0;
  }
  return result;
}
// 8366C8: using guessed type int _STL::__node_alloc<1,0>::_S_free_list[];

//----- (00404F20) --------------------------------------------------------  // acclient.c:63868
char __thiscall List<PStringBase<char>>::pop_front(List<PStringBase<char> > *this, PStringBase<char> *retval)
{
  List<PStringBase<char> > *v2; // ebx@1
  ListNode<PStringBase<char> > *v3; // edi@1
  char result; // al@2
  ListNode<PStringBase<char> > *v5; // eax@3
  PSRefBufferCharData<char> *v6; // eax@6
  int v7; // esi@7
  PSRefBufferCharData<char> *v8; // eax@10
  int v9; // esi@11

  v2 = this;
  v3 = this->_head;
  if ( v3 )
  {
    v5 = v3->next;
    this->_head = v5;
    if ( v5 )
      v5->prev = 0;
    else
      this->_tail = 0;
    v6 = retval->m_charbuffer;
    if ( retval->m_charbuffer != v3->data.m_charbuffer )
    {
      v7 = (int)&v6[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      v8 = v3->data.m_charbuffer;
      retval->m_charbuffer = v3->data.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v8[-1]);
    }
    v9 = (int)&v3->data.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) )
    {
      if ( v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    }
    operator delete(v3);
    --v2->_num_elements;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00404FC0) --------------------------------------------------------  // acclient.c:63917
void __cdecl _STL::__node_alloc<1,0>::deallocate(void *__p, unsigned int __n)
{
  int *v2; // esi@3

  if ( __n <= 0x80 )
  {
    v2 = &_STL::__node_alloc<1,0>::_S_free_list[(__n - 1) >> 3];
    _STL::_STLP_mutex_spin<0>::_M_do_lock(&_STL::_Node_Alloc_Lock<1,0>::_S_lock);
    *(_DWORD *)__p = *v2;
    *v2 = (int)__p;
    _STL::_Node_Alloc_Lock<1,0>::_S_lock = 0;
  }
  else
  {
    operator delete(__p);
  }
}
// 8366C8: using guessed type int _STL::__node_alloc<1,0>::_S_free_list[];

//----- (00405010) --------------------------------------------------------  // acclient.c:63937
void __thiscall List<PStringBase<char>>::flush(List<PStringBase<char> > *this)
{
  List<PStringBase<char> > *v1; // edi@1
  char *v2; // esi@3
  PStringBase<char> retval; // [sp+10h] [bp-4h]@3

  v1 = this;
  while ( v1->_head )
  {
    retval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    List<PStringBase<char>>::pop_front(v1, &retval);
    v2 = &retval.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&retval.m_charbuffer[-1]) )
    {
      if ( v2 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
    }
  }
}

//----- (00405070) --------------------------------------------------------  // acclient.c:63959
List<PStringBase<char> > *__thiscall List<PStringBase<char>>::vector_deleting_destructor(List<PStringBase<char> > *this, unsigned int a2)
{
  List<PStringBase<char> > *v2; // esi@1

  v2 = this;
  this->vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
  List<PStringBase<char>>::flush(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);

//----- (004050A0) --------------------------------------------------------  // acclient.c:63973
const char *__thiscall PStringBase<char>::replace(PStringBase<char> *this, PStringBase<char> *search, PStringBase<char> *str)
{
  PStringBase<char> *v3; // ebp@1
  void **v4; // edi@1
  PSRefBufferCharData<char> *v5; // ST10_4@1
  PSRefBufferCharData<char> *v6; // ST0C_4@1
  char *v7; // esi@1
  int v8; // edi@8
  const char *result; // eax@11
  PSRefBuffer<char> *v10; // esi@12
  unsigned int v11; // ST10_4@12
  int v12; // edi@12
  int v13; // ebx@12
  size_t v14; // esi@13
  char *v15; // edi@13
  int v16; // edi@15
  const char v17; // al@16
  unsigned int c; // [sp+10h] [bp-18h]@12
  const char *p; // [sp+14h] [bp-14h]@1
  PSRefBuffer<char> *old_buffer; // [sp+18h] [bp-10h]@12
  _STL::vector<char const *,_STL::allocator<char const *> > matches; // [sp+1Ch] [bp-Ch]@1

  v3 = this;
  v4 = 0;
  v5 = search->m_charbuffer;
  v6 = this->m_charbuffer;
  matches._M_start = 0;
  matches._M_finish = 0;
  matches._M_end_of_storage._M_data = 0;
  v7 = _strstr(v6->m_data, v5->m_data);
  for ( p = v7; v7; p = v7 )
  {
    if ( v4 == (void **)matches._M_end_of_storage._M_data )
    {
      _STL::vector<char const *,_STL::allocator<char const *>>::_M_insert_overflow(
        (_STL::vector<void *,_STL::allocator<void *> > *)&matches,
        v4,
        (void *const *)&p,
        (_STL::__true_type *)&str,
        1u,
        1);
      v4 = (void **)matches._M_finish;
    }
    else
    {
      if ( v4 )
        *v4 = v7;
      ++v4;
      matches._M_finish = (const char **)v4;
    }
    v7 = _strstr(&v7[*(_DWORD *)&search->m_charbuffer[-1].m_data[12] - 1], search->m_charbuffer->m_data);
  }
  v8 = (signed int)((char *)v4 - (char *)matches._M_start) >> 2;
  p = (const char *)v8;
  if ( v8 )
  {
    v11 = v8 * (*(_DWORD *)&str->m_charbuffer[-1].m_data[12] - *(_DWORD *)&search->m_charbuffer[-1].m_data[12])
        + *(_DWORD *)&v3->m_charbuffer[-1].m_data[12]
        - 1;
    old_buffer = (PSRefBuffer<char> *)&v3->m_charbuffer[-2].m_data[12];
    v10 = old_buffer;
    PStringBase<char>::allocate_ref_buffer(v3, v11);
    v12 = (int)v3->m_charbuffer;
    v13 = (int)v10->m_data;
    c = 0;
    if ( p )
    {
      do
      {
        v14 = (size_t)&matches._M_start[c][-v13];
        _strncpy((char *)v12, (const char *)v13, v14);
        v15 = (char *)(v14 + v12);
        strcpy(v15, str->m_charbuffer->m_data);
        v12 = (int)&v15[*(_DWORD *)&str->m_charbuffer[-1].m_data[12] - 1];
        v13 = v13 + v14 + *(_DWORD *)&search->m_charbuffer[-1].m_data[12] - 1;
        ++c;
      }
      while ( c < (unsigned int)p );
      v10 = old_buffer;
    }
    v16 = v12 - v13;
    do
    {
      v17 = *(_BYTE *)v13;
      *(_BYTE *)(v16 + v13) = *(_BYTE *)v13;
      ++v13;
    }
    while ( v17 );
    if ( !InterlockedDecrement((volatile LONG *)&v10->m_cRef) && v10 )
      v10->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v10, 1u);
    if ( (_DWORD)matches._M_start )
      _STL::__node_alloc<1,0>::deallocate(matches._M_start, 4 * (matches._M_end_of_storage._M_data - matches._M_start));
    result = p;
  }
  else
  {
    if ( (_DWORD)matches._M_start )
      _STL::__node_alloc<1,0>::deallocate(matches._M_start, 4 * (matches._M_end_of_storage._M_data - matches._M_start));
    result = 0;
  }
  return result;
}

