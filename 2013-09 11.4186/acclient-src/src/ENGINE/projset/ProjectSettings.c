/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ProjectSettings
   Object     : ENGINE\projset\ProjectSettings.obj
   Functions  : 74
   Addresses  : 004228E0 - 00727700 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004228E0) --------------------------------------------------------  // acclient.c:94312
void __cdecl _STL::fill(void **__first, void **__last, void *const *__val)
{
  void **i; // eax@1

  for ( i = __first; i != __last; ++i )
    *i = *__val;
}

//----- (00422900) --------------------------------------------------------  // acclient.c:94321
const unsigned int *__cdecl _STL::__lower_bound(const unsigned int *__first, const unsigned int *__last, const unsigned int *__val)
{
  const unsigned int *result; // eax@1
  signed int v4; // edx@1
  signed int v5; // ecx@2

  result = __first;
  v4 = __last - __first;
  while ( v4 > 0 )
  {
    v5 = v4 >> 1;
    if ( result[v4 >> 1] >= *__val )
    {
      v4 >>= 1;
    }
    else
    {
      result += v5 + 1;
      v4 += -1 - v5;
    }
  }
  return result;
}

//----- (00422940) --------------------------------------------------------  // acclient.c:94346
int __thiscall _STL::hashtable<_STL::pair<PStringBase<char> const,PStringBase<char>>,PStringBase<char>,_STL::hash<PStringBase<char>>,_STL::_Select1st<_STL::pair<PStringBase<char> const,PStringBase<char>>>,_STL::equal_to<PStringBase<char>>,_STL::allocator<_STL::pair<PStringBase<char> const,PStringBase<char>>>>::_M_find(void *this, PStringBase<char> *rhs)
{
  char *v2; // edi@1
  unsigned int v3; // eax@1
  void *v4; // esi@1
  int i; // esi@3

  v2 = rhs->m_charbuffer->m_data;
  v3 = *(_DWORD *)&rhs->m_charbuffer[-1].m_data[8];
  v4 = this;
  if ( v3 == -1 )
  {
    v3 = compute_str_hash(v2);
    *((_DWORD *)v2 - 2) = v3;
  }
  for ( i = *(_DWORD *)(*((_DWORD *)v4 + 1) + 4 * (v3 % ((*((_DWORD *)v4 + 2) - *((_DWORD *)v4 + 1)) >> 2)));
        i;
        i = *(_DWORD *)i )
  {
    if ( PStringBase<char>::operator==((PStringBase<char> *)(i + 4), rhs) )
      break;
  }
  return i;
}

//----- (004229A0) --------------------------------------------------------  // acclient.c:94372
char *__stdcall _STL::vector<void *,_STL::allocator<void *>>::_M_allocate_and_copy(int a1, void *Src, int a3)
{
  char *v3; // esi@3
  unsigned int v5; // [sp-4h] [bp-8h]@2

  if ( a1 )
  {
    v5 = 4 * a1;
    if ( (unsigned int)(4 * a1) <= 0x80 )
      v3 = _STL::__node_alloc<1,0>::_M_allocate(v5);
    else
      v3 = (char *)operator new(v5);
  }
  else
  {
    v3 = 0;
  }
  if ( (void *)a3 != Src )
    _memmove(v3, Src, a3 - (_DWORD)Src);
  return v3;
}

//----- (004229F0) --------------------------------------------------------  // acclient.c:94395
void __thiscall _STL::vector<void *,_STL::allocator<void *>>::reserve(_STL::vector<void *,_STL::allocator<void *> > *this, unsigned int __n)
{
  _STL::vector<void *,_STL::allocator<void *> > *v2; // esi@1
  void **v3; // eax@1
  int v4; // ecx@2
  int v5; // ebx@2
  char *v6; // edi@3
  unsigned int v7; // [sp-Ch] [bp-14h]@6

  v2 = this;
  v3 = this->_M_start;
  if ( this->_M_end_of_storage._M_data - this->_M_start < __n )
  {
    v4 = (int)this->_M_finish;
    v5 = (v4 - (signed int)v3) >> 2;
    if ( v3 )
    {
      v6 = _STL::vector<void *,_STL::allocator<void *>>::_M_allocate_and_copy(__n, v3, v4);
      if ( v2->_M_start )
        _STL::__node_alloc<1,0>::deallocate(v2->_M_start, 4 * (v2->_M_end_of_storage._M_data - v2->_M_start));
    }
    else if ( __n )
    {
      v7 = 4 * __n;
      if ( 4 * __n <= 0x80 )
        v6 = _STL::__node_alloc<1,0>::_M_allocate(v7);
      else
        v6 = (char *)operator new(v7);
    }
    else
    {
      v6 = 0;
    }
    v2->_M_start = (void **)v6;
    v2->_M_finish = (void **)&v6[4 * v5];
    v2->_M_end_of_storage._M_data = (void **)&v6[4 * __n];
  }
}

//----- (00422A90) --------------------------------------------------------  // acclient.c:94435
void __thiscall _STL::vector<char const *,_STL::allocator<char const *>>::_M_insert_overflow(_STL::vector<void *,_STL::allocator<void *> > *this, void **__position, void *const *__x, _STL::__true_type *__formal, unsigned int __fill_len, bool __atend)
{
  _STL::vector<void *,_STL::allocator<void *> > *v6; // ebp@1
  unsigned int v7; // edi@1
  void *v8; // ecx@1
  int v9; // ecx@3
  bool v10; // zf@3
  const unsigned int v11; // ecx@3
  void **v12; // eax@8
  char *v13; // eax@9
  char *v14; // esi@10
  unsigned int v15; // ecx@12
  char *v16; // edi@14
  void **v17; // esi@15
  unsigned int v18; // eax@19
  const unsigned int v19; // edx@19
  unsigned int v20; // [sp-4h] [bp-14h]@4
  const unsigned int __len; // [sp+Ch] [bp-4h]@1

  v6 = this;
  v7 = __fill_len;
  __len = this->_M_finish - this->_M_start;
  v8 = &__fill_len;
  if ( __len >= __fill_len )
    v8 = (void *)&__len;
  v9 = *(_DWORD *)v8;
  v10 = __len + v9 == 0;
  v11 = __len + v9;
  __len = v11;
  if ( v10 )
  {
    __fill_len = 0;
  }
  else
  {
    v20 = 4 * v11;
    if ( 4 * v11 <= 0x80 )
      __fill_len = (unsigned int)_STL::__node_alloc<1,0>::_M_allocate(v20);
    else
      __fill_len = (unsigned int)operator new(v20);
  }
  v12 = v6->_M_start;
  if ( __position == v6->_M_start )
  {
    v13 = (char *)__fill_len;
  }
  else
  {
    v14 = (char *)((char *)__position - (char *)v12);
    v13 = (char *)_memmove((void *)__fill_len, v12, (char *)__position - (char *)v12) + (_DWORD)v14;
  }
  if ( v7 )
  {
    v15 = v7;
    do
    {
      *(_DWORD *)v13 = *__x;
      v13 += 4;
      --v15;
    }
    while ( v15 );
  }
  v16 = v13;
  if ( !__atend )
  {
    v17 = v6->_M_finish;
    if ( v17 != __position )
      v16 = (char *)_memmove(v13, __position, (char *)v17 - (char *)__position) + (char *)v17 - (char *)__position;
  }
  if ( v6->_M_start )
    _STL::__node_alloc<1,0>::deallocate(v6->_M_start, 4 * (v6->_M_end_of_storage._M_data - v6->_M_start));
  v18 = __fill_len;
  v19 = __len;
  v6->_M_finish = (void **)v16;
  v6->_M_start = (void **)v18;
  v6->_M_end_of_storage._M_data = (void **)(v18 + 4 * v19);
}

//----- (00422B90) --------------------------------------------------------  // acclient.c:94514
void __thiscall _STL::vector<void *,_STL::allocator<void *>>::vector<void *,_STL::allocator<void *>>(_STL::vector<void *,_STL::allocator<void *> > *this, unsigned int __n, void *const *__val, _STL::allocator<void *> *__a)
{
  _STL::vector<void *,_STL::allocator<void *> > *v4; // esi@1
  unsigned int v5; // edi@1
  char *v6; // eax@3
  unsigned int v7; // [sp-4h] [bp-Ch]@2

  v4 = this;
  v5 = __n;
  this->_M_start = 0;
  this->_M_finish = 0;
  this->_M_end_of_storage._M_data = 0;
  if ( __n )
  {
    v7 = 4 * __n;
    if ( 4 * __n <= 0x80 )
      v6 = _STL::__node_alloc<1,0>::_M_allocate(v7);
    else
      v6 = (char *)operator new(v7);
  }
  else
  {
    v6 = 0;
  }
  v4->_M_start = (void **)v6;
  v4->_M_finish = (void **)v6;
  v4->_M_end_of_storage._M_data = (void **)&v6[4 * __n];
  if ( __n )
  {
    do
    {
      *(_DWORD *)v6 = *__val;
      v6 += 4;
      --v5;
    }
    while ( v5 );
  }
  v4->_M_finish = (void **)v6;
}

//----- (00422C00) --------------------------------------------------------  // acclient.c:94555
void __thiscall _STL::vector<void *,_STL::allocator<void *>>::_M_fill_insert(_STL::vector<void *,_STL::allocator<void *> > *this, void **__position, unsigned int __n, void *const *__x)
{
  unsigned int v4; // edi@1
  _STL::vector<void *,_STL::allocator<void *> > *v5; // ebx@1
  void **v6; // ecx@2
  void **v7; // ebp@3
  int v8; // eax@3
  void *v9; // esi@3
  int v10; // ecx@3
  void **v11; // edx@3
  void *const *v12; // eax@4
  const void *v13; // edi@4
  size_t v14; // edi@6
  unsigned int v15; // ecx@9
  void *v16; // edi@11
  void **__positiona; // [sp+14h] [bp+4h]@3

  v4 = __n;
  v5 = this;
  if ( __n )
  {
    v6 = this->_M_finish;
    if ( v5->_M_end_of_storage._M_data - v6 < __n )
    {
      _STL::vector<char const *,_STL::allocator<char const *>>::_M_insert_overflow(
        v5,
        __position,
        __x,
        (_STL::__true_type *)&__x,
        __n,
        0);
    }
    else
    {
      v7 = __position;
      v8 = (int)*__x;
      v9 = v5->_M_finish;
      v10 = v6 - __position;
      v11 = (void **)v10;
      __n = (unsigned int)*__x;
      __positiona = (void **)v10;
      if ( v10 <= v4 )
      {
        v15 = v4 - v10;
        __x = (void *const *)(v4 - (_DWORD)v11);
        if ( (void **)v4 != v11 )
        {
          memset32(v9, v8, v15);
          v15 = (unsigned int)__x;
        }
        v16 = &v5->_M_finish[v15];
        v5->_M_finish = (void **)v16;
        if ( v9 != v7 )
        {
          _memmove(v16, v7, (_BYTE *)v9 - (_BYTE *)v7);
          v11 = __positiona;
        }
        v5->_M_finish += (signed int)v11;
        _STL::fill(v7, (void **)v9, (void *const *)&__n);
      }
      else
      {
        v12 = (void *const *)(4 * v4);
        v13 = (char *)v9 - 4 * v4;
        __x = v12;
        if ( v9 != v13 )
        {
          _memmove(v9, v13, (_BYTE *)v9 - (_BYTE *)v13);
          v12 = __x;
        }
        v14 = (_BYTE *)v13 - (_BYTE *)v7;
        v5->_M_finish = (void **)((char *)v5->_M_finish + (unsigned int)v12);
        if ( (signed int)v14 > 0 )
        {
          _memmove((char *)v9 - v14, v7, v14);
          v12 = __x;
        }
        _STL::fill(v7, (void **)((char *)v12 + (_DWORD)v7), (void *const *)&__n);
      }
    }
  }
}

//----- (00422D20) --------------------------------------------------------  // acclient.c:94639
void __thiscall _STL::hashtable<_STL::pair<PStringBase<char> const,PStringBase<char>>,PStringBase<char>,_STL::hash<PStringBase<char>>,_STL::_Select1st<_STL::pair<PStringBase<char> const,PStringBase<char>>>,_STL::equal_to<PStringBase<char>>,_STL::allocator<_STL::pair<PStringBase<char> const,PStringBase<char>>>>::clear(_STL::hashtable<_STL::pair<PStringBase<char> const ,PStringBase<char> >,PStringBase<char>,_STL::hash<PStringBase<char> >,_STL::_Select1st<_STL::pair<PStringBase<char> const ,PStringBase<char> > >,_STL::equal_to<PStringBase<char> >,_STL::allocator<_STL::pair<PStringBase<char> const ,PStringBase<char> > > > *this)
{
  unsigned int v1; // eax@1
  void *v2; // esi@2
  void *v3; // ebx@3
  int v4; // edi@3
  int v5; // edi@6
  unsigned int __i; // [sp+8h] [bp-8h]@1
  _STL::hashtable<_STL::pair<PStringBase<char> const ,PStringBase<char> >,PStringBase<char>,_STL::hash<PStringBase<char> >,_STL::_Select1st<_STL::pair<PStringBase<char> const ,PStringBase<char> > >,_STL::equal_to<PStringBase<char> >,_STL::allocator<_STL::pair<PStringBase<char> const ,PStringBase<char> > > > *v7; // [sp+Ch] [bp-4h]@1

  v1 = 0;
  v7 = this;
  __i = 0;
  if ( this->_M_buckets._M_finish - this->_M_buckets._M_start )
  {
    do
    {
      v2 = this->_M_buckets._M_start[v1];
      if ( v2 )
      {
        do
        {
          v3 = *(void **)v2;
          v4 = *((_DWORD *)v2 + 2) - 20;
          if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
          v5 = *((_DWORD *)v2 + 1) - 20;
          if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
          _STL::_STLP_mutex_spin<0>::_M_do_lock(&_STL::_Node_Alloc_Lock<1,0>::_S_lock);
          *(_DWORD *)v2 = dword_8366CC;
          dword_8366CC = (int)v2;
          _STL::_Node_Alloc_Lock<1,0>::_S_lock = 0;
          v2 = v3;
        }
        while ( v3 );
        v1 = __i;
        this = v7;
      }
      this->_M_buckets._M_start[v1++] = 0;
      __i = v1;
    }
    while ( v1 < this->_M_buckets._M_finish - this->_M_buckets._M_start );
  }
  this->_M_num_elements._M_data = 0;
}
// 8366CC: using guessed type int dword_8366CC;

//----- (00422DF0) --------------------------------------------------------  // acclient.c:94688
void __thiscall _STL::hashtable<_STL::pair<PStringBase<char> const,PStringBase<char>>,PStringBase<char>,_STL::hash<PStringBase<char>>,_STL::_Select1st<_STL::pair<PStringBase<char> const,PStringBase<char>>>,_STL::equal_to<PStringBase<char>>,_STL::allocator<_STL::pair<PStringBase<char> const,PStringBase<char>>>>::resize(_STL::hashtable<_STL::pair<PStringBase<char> const ,PStringBase<char> >,PStringBase<char>,_STL::hash<PStringBase<char> >,_STL::_Select1st<_STL::pair<PStringBase<char> const ,PStringBase<char> > >,_STL::equal_to<PStringBase<char> >,_STL::allocator<_STL::pair<PStringBase<char> const ,PStringBase<char> > > > *this, unsigned int __num_elements_hint)
{
  _STL::hashtable<_STL::pair<PStringBase<char> const ,PStringBase<char> >,PStringBase<char>,_STL::hash<PStringBase<char> >,_STL::_Select1st<_STL::pair<PStringBase<char> const ,PStringBase<char> > >,_STL::equal_to<PStringBase<char> >,_STL::allocator<_STL::pair<PStringBase<char> const ,PStringBase<char> > > > *v2; // edi@1
  const unsigned int v3; // ebp@1
  const unsigned int v4; // ebx@2
  unsigned int *v5; // eax@2
  const unsigned int v6; // eax@3
  void *v7; // esi@7
  int v8; // ebp@8
  unsigned int v9; // eax@8
  unsigned int v10; // edx@10
  void **v11; // eax@10
  void *v12; // ecx@13
  void **v13; // edx@13
  void **v14; // eax@13
  void *__val; // [sp+Ch] [bp-14h]@6
  const unsigned int __old_n; // [sp+10h] [bp-10h]@1
  _STL::vector<void *,_STL::allocator<void *> > __tmp; // [sp+14h] [bp-Ch]@6

  v2 = this;
  __old_n = this->_M_buckets._M_finish - this->_M_buckets._M_start;
  v3 = __old_n;
  if ( __num_elements_hint > __old_n )
  {
    v4 = 0;
    v5 = (unsigned int *)_STL::__lower_bound(
                           &_STL::_Stl_prime<bool>::_M_list,
                           (const unsigned int *)"config/ProjectSettings.xml",
                           &__num_elements_hint);
    if ( (char *)v5 == "config/ProjectSettings.xml" )
    {
      v6 = -5;
      __num_elements_hint = -5;
    }
    else
    {
      __num_elements_hint = *v5;
      v6 = __num_elements_hint;
    }
    if ( v6 > __old_n )
    {
      __val = 0;
      _STL::vector<void *,_STL::allocator<void *>>::vector<void *,_STL::allocator<void *>>(
        &__tmp,
        v6,
        &__val,
        (_STL::allocator<void *> *)&__num_elements_hint);
      if ( v3 > 0 )
      {
        do
        {
          v7 = v2->_M_buckets._M_start[v4];
          if ( v7 )
          {
            do
            {
              v8 = *((_DWORD *)v7 + 1);
              v9 = *(_DWORD *)(v8 - 8);
              if ( v9 == -1 )
              {
                v9 = compute_str_hash(*((char **)v7 + 1));
                *(_DWORD *)(v8 - 8) = v9;
              }
              v10 = v9 % __num_elements_hint;
              v2->_M_buckets._M_start[v4] = *(void **)v7;
              v11 = __tmp._M_start;
              *(_DWORD *)v7 = __tmp._M_start[v10];
              v11[v10] = v7;
              v7 = v2->_M_buckets._M_start[v4];
            }
            while ( v7 );
            v3 = __old_n;
          }
          ++v4;
        }
        while ( v4 < v3 );
      }
      v12 = v2->_M_buckets._M_start;
      v13 = __tmp._M_finish;
      v2->_M_buckets._M_start = __tmp._M_start;
      v2->_M_buckets._M_finish = v13;
      v14 = v2->_M_buckets._M_end_of_storage._M_data;
      v2->_M_buckets._M_end_of_storage._M_data = __tmp._M_end_of_storage._M_data;
      if ( v12 )
        _STL::__node_alloc<1,0>::deallocate(v12, 4 * (((char *)v14 - (_BYTE *)v12) >> 2));
    }
  }
}

//----- (00422F00) --------------------------------------------------------  // acclient.c:94778
int __thiscall _STL::hashtable<_STL::pair<PStringBase<char> const,PStringBase<char>>,PStringBase<char>,_STL::hash<PStringBase<char>>,_STL::_Select1st<_STL::pair<PStringBase<char> const,PStringBase<char>>>,_STL::equal_to<PStringBase<char>>,_STL::allocator<_STL::pair<PStringBase<char> const,PStringBase<char>>>>::_M_insert(_STL::hashtable<_STL::pair<PStringBase<char> const ,PStringBase<char> >,PStringBase<char>,_STL::hash<PStringBase<char> >,_STL::_Select1st<_STL::pair<PStringBase<char> const ,PStringBase<char> > >,_STL::equal_to<PStringBase<char> >,_STL::allocator<_STL::pair<PStringBase<char> const ,PStringBase<char> > > > *this, _STL::pair<PStringBase<char> const ,PStringBase<char> > *__obj)
{
  _STL::hashtable<_STL::pair<PStringBase<char> const ,PStringBase<char> >,PStringBase<char>,_STL::hash<PStringBase<char> >,_STL::_Select1st<_STL::pair<PStringBase<char> const ,PStringBase<char> > >,_STL::equal_to<PStringBase<char> >,_STL::allocator<_STL::pair<PStringBase<char> const ,PStringBase<char> > > > *v2; // esi@1
  PSRefBufferCharData<char> *v3; // ebx@1
  unsigned int v4; // eax@1
  int v5; // edi@1
  int v6; // ebp@3
  char *v7; // edi@3
  PSRefBufferCharData<char> *v8; // eax@4
  PSRefBufferCharData<char> *v9; // eax@4
  _STL::_Hashtable_node<_STL::pair<PStringBase<char> const ,PStringBase<char> > > *__first; // [sp+10h] [bp-4h]@3

  v2 = this;
  _STL::hashtable<_STL::pair<PStringBase<char> const,PStringBase<char>>,PStringBase<char>,_STL::hash<PStringBase<char>>,_STL::_Select1st<_STL::pair<PStringBase<char> const,PStringBase<char>>>,_STL::equal_to<PStringBase<char>>,_STL::allocator<_STL::pair<PStringBase<char> const,PStringBase<char>>>>::resize(
    this,
    this->_M_num_elements._M_data + 1);
  v3 = __obj->first.m_charbuffer;
  v4 = *(_DWORD *)&__obj->first.m_charbuffer[-1].m_data[8];
  v5 = v2->_M_buckets._M_finish - v2->_M_buckets._M_start;
  if ( v4 == -1 )
  {
    v4 = compute_str_hash(__obj->first.m_charbuffer->m_data);
    *(_DWORD *)&v3[-1].m_data[8] = v4;
  }
  v6 = v4 % v5;
  __first = (_STL::_Hashtable_node<_STL::pair<PStringBase<char> const ,PStringBase<char> > > *)v2->_M_buckets._M_start[v4 % v5];
  v7 = _STL::__node_alloc<1,0>::_M_allocate(0xCu);
  *(_DWORD *)v7 = 0;
  if ( v7 != (char *)-4 )
  {
    v8 = __obj->first.m_charbuffer;
    *((_DWORD *)v7 + 1) = __obj->first.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v8[-1]);
    v9 = __obj->second.m_charbuffer;
    *((_DWORD *)v7 + 2) = v9;
    InterlockedIncrement((volatile LONG *)&v9[-1]);
  }
  *(_DWORD *)v7 = __first;
  v2->_M_buckets._M_start[v6] = v7;
  ++v2->_M_num_elements._M_data;
  return (int)(v7 + 4);
}

//----- (00422FB0) --------------------------------------------------------  // acclient.c:94822
int __thiscall _STL::hash_map<PStringBase<char>,PStringBase<char>,_STL::hash<PStringBase<char>>,_STL::equal_to<PStringBase<char>>,_STL::allocator<_STL::pair<PStringBase<char> const,PStringBase<char>>>>::operator[](_STL::hash_map<PStringBase<char>,PStringBase<char>,_STL::hash<PStringBase<char> >,_STL::equal_to<PStringBase<char> >,_STL::allocator<_STL::pair<PStringBase<char> const ,PStringBase<char> > > > *this, PStringBase<char> *__key)
{
  PStringBase<char> *v2; // ebx@1
  _STL::hashtable<_STL::pair<PStringBase<char> const ,PStringBase<char> >,PStringBase<char>,_STL::hash<PStringBase<char> >,_STL::_Select1st<_STL::pair<PStringBase<char> const ,PStringBase<char> > >,_STL::equal_to<PStringBase<char> >,_STL::allocator<_STL::pair<PStringBase<char> const ,PStringBase<char> > > > *v3; // ebp@1
  int v4; // eax@1
  volatile LONG *v5; // esi@2
  PSRefBufferCharData<char> *v6; // ebx@2
  int v7; // esi@2
  char *v8; // edi@5
  int v9; // ebx@8
  char v11; // [sp+10h] [bp-Ch]@1
  _STL::pair<PStringBase<char> const ,PStringBase<char> > __obj; // [sp+14h] [bp-8h]@2

  v2 = __key;
  v3 = (_STL::hashtable<_STL::pair<PStringBase<char> const ,PStringBase<char> >,PStringBase<char>,_STL::hash<PStringBase<char> >,_STL::_Select1st<_STL::pair<PStringBase<char> const ,PStringBase<char> > >,_STL::equal_to<PStringBase<char> >,_STL::allocator<_STL::pair<PStringBase<char> const ,PStringBase<char> > > > *)this;
  v11 = 0;
  v4 = _STL::hashtable<_STL::pair<PStringBase<char> const,PStringBase<char>>,PStringBase<char>,_STL::hash<PStringBase<char>>,_STL::_Select1st<_STL::pair<PStringBase<char> const,PStringBase<char>>>,_STL::equal_to<PStringBase<char>>,_STL::allocator<_STL::pair<PStringBase<char> const,PStringBase<char>>>>::_M_find(
         this,
         __key);
  if ( v4 )
  {
    v6 = __obj.first.m_charbuffer;
    v7 = v4 + 8;
  }
  else
  {
    v5 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v11 = 3;
    __key = (PStringBase<char> *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v6 = v2->m_charbuffer;
    __obj.first.m_charbuffer = v6;
    InterlockedIncrement((volatile LONG *)&v6[-1]);
    __obj.second.m_charbuffer = (PSRefBufferCharData<char> *)__key;
    InterlockedIncrement(v5);
    v7 = _STL::hashtable<_STL::pair<PStringBase<char> const,PStringBase<char>>,PStringBase<char>,_STL::hash<PStringBase<char>>,_STL::_Select1st<_STL::pair<PStringBase<char> const,PStringBase<char>>>,_STL::equal_to<PStringBase<char>>,_STL::allocator<_STL::pair<PStringBase<char> const,PStringBase<char>>>>::_M_insert(
           v3,
           &__obj)
       + 4;
  }
  if ( v11 & 2 )
  {
    v11 &= 0xFDu;
    v8 = &__obj.second.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&__obj.second.m_charbuffer[-1]) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    v9 = (int)&v6[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  }
  if ( v11 & 1 && !InterlockedDecrement((volatile LONG *)&__key[-4]) && __key != (PStringBase<char> *)20 )
    (*(void (__thiscall **)(_DWORD, _DWORD))__key[-5].m_charbuffer)(&__key[-5], 1);
  return v7;
}

//----- (004230A0) --------------------------------------------------------  // acclient.c:94878
void __thiscall _STL::hashtable<_STL::pair<PStringBase<char> const,PStringBase<char>>,PStringBase<char>,_STL::hash<PStringBase<char>>,_STL::_Select1st<_STL::pair<PStringBase<char> const,PStringBase<char>>>,_STL::equal_to<PStringBase<char>>,_STL::allocator<_STL::pair<PStringBase<char> const,PStringBase<char>>>>::_M_initialize_buckets(_STL::hashtable<_STL::pair<PStringBase<char> const ,PStringBase<char> >,PStringBase<char>,_STL::hash<PStringBase<char> >,_STL::_Select1st<_STL::pair<PStringBase<char> const ,PStringBase<char> > >,_STL::equal_to<PStringBase<char> >,_STL::allocator<_STL::pair<PStringBase<char> const ,PStringBase<char> > > > *this, unsigned int __n)
{
  _STL::hashtable<_STL::pair<PStringBase<char> const ,PStringBase<char> >,PStringBase<char>,_STL::hash<PStringBase<char> >,_STL::_Select1st<_STL::pair<PStringBase<char> const ,PStringBase<char> > >,_STL::equal_to<PStringBase<char> >,_STL::allocator<_STL::pair<PStringBase<char> const ,PStringBase<char> > > > *v2; // esi@1
  char *v3; // eax@1
  unsigned int v4; // ebx@1
  void **v5; // ST08_4@3

  v2 = this;
  v3 = (char *)_STL::__lower_bound(
                 &_STL::_Stl_prime<bool>::_M_list,
                 (const unsigned int *)"config/ProjectSettings.xml",
                 &__n);
  v4 = -5;
  if ( v3 != "config/ProjectSettings.xml" )
    v4 = *(_DWORD *)v3;
  _STL::vector<void *,_STL::allocator<void *>>::reserve(&v2->_M_buckets, v4);
  v5 = v2->_M_buckets._M_finish;
  __n = 0;
  _STL::vector<void *,_STL::allocator<void *>>::_M_fill_insert(&v2->_M_buckets, v5, v4, (void *const *)&__n);
  v2->_M_num_elements._M_data = 0;
}

//----- (00423110) --------------------------------------------------------  // acclient.c:94901
PStringBase<char> *__cdecl ProjectSettings::CompleteProjectPath(PStringBase<char> *result, PStringBase<char> *_path)
{
  PSRefBufferCharData<char> *v2; // ecx@0
  int v3; // eax@1
  PSRefBufferCharData<char> *v4; // eax@1
  char *v5; // esi@1
  PStringBase<char> retval; // [sp+0h] [bp-4h]@1

  retval.m_charbuffer = v2;
  v3 = _STL::hash_map<PStringBase<char>,PStringBase<char>,_STL::hash<PStringBase<char>>,_STL::equal_to<PStringBase<char>>,_STL::allocator<_STL::pair<PStringBase<char> const,PStringBase<char>>>>::operator[](
         &ProjectSettings::sm_settings,
         &BRANCHBASEDIR_0);
  PStringBase<char>::operator+((PStringBase<char> *)v3, &retval, _path);
  PSUtils::cleanup_filename(&retval, 0);
  v4 = retval.m_charbuffer;
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v4[-1]);
  v5 = &retval.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&retval.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
  return result;
}

//----- (006C4B00) --------------------------------------------------------  // acclient.c:733049
int _E73_18()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"ProjectSetting");
  PStringBase<unsigned short>::allocate_ref_buffer(&PROJECTSETTING_0, v0);
  _wcscpy(PROJECTSETTING_0.m_charbuffer->m_data, L"ProjectSetting");
  return atexit(_E74_21);
}

//----- (006C4B40) --------------------------------------------------------  // acclient.c:733060
int _E76_11()
{
  PStringBase<char>::PStringBase<char>(&NAME_0, "name");
  return atexit(_E77_39);
}

//----- (006C4B60) --------------------------------------------------------  // acclient.c:733067
int _E79_11()
{
  PStringBase<char>::PStringBase<char>(&VALUE_0, "value");
  return atexit(_E80_13);
}

//----- (006C4B80) --------------------------------------------------------  // acclient.c:733074
int _E82_3()
{
  PStringBase<char>::PStringBase<char>(&BRANCH_0, "branch");
  return atexit(_E83_4);
}

//----- (006C4BA0) --------------------------------------------------------  // acclient.c:733081
int _E85_0()
{
  PStringBase<char>::PStringBase<char>(&BRANCHBASEDIR_0, "branchbasedir");
  return atexit(_E86_2);
}

//----- (006C4BC0) --------------------------------------------------------  // acclient.c:733088
int _E88_0()
{
  PStringBase<char>::PStringBase<char>(&PROJECTNAME_0, "projectname");
  return atexit(_E89_13);
}

//----- (006C4BE0) --------------------------------------------------------  // acclient.c:733095
int _E91_0()
{
  PStringBase<char>::PStringBase<char>(&LONGNAME_0, "longname");
  return atexit(_E92_10);
}

//----- (006C4C00) --------------------------------------------------------  // acclient.c:733102
int _E94_0()
{
  PStringBase<char>::PStringBase<char>(&ENUMDB_0, "enumdb");
  return atexit(sub_7272E0);
}

//----- (006C4C20) --------------------------------------------------------  // acclient.c:733109
int _E97_0()
{
  PStringBase<char>::PStringBase<char>(&DIDNAME_0, "didname");
  return atexit(_E98_23);
}

//----- (006C4C40) --------------------------------------------------------  // acclient.c:733116
int _E100_3()
{
  PStringBase<char>::PStringBase<char>(&RCS_0, "rcs");
  return atexit(_E101_53);
}

//----- (006C4C60) --------------------------------------------------------  // acclient.c:733123
int _E103_0()
{
  PStringBase<char>::PStringBase<char>(&PREPROC_KEYS_BASE_PATH_0, "SOFTWARE\\Turbine\\Preproc");
  return atexit(_E104_23);
}

//----- (006C4C80) --------------------------------------------------------  // acclient.c:733130
int _E106_2()
{
  PStringBase<char>::PStringBase<char>(&CURRENT_PROJECT_0, "CURRENT_PROJECT");
  return atexit(_E107_55);
}

//----- (006C4CA0) --------------------------------------------------------  // acclient.c:733137
int _E109_0()
{
  PStringBase<char>::PStringBase<char>(&DATA_GAME_PATH_0, "data/game");
  return atexit(sub_7273D0);
}

//----- (006C4CC0) --------------------------------------------------------  // acclient.c:733144
int _E112_2()
{
  PStringBase<char>::PStringBase<char>(&DATA_ENGINE_PATH_0, "data/engine");
  return atexit(_E113_36);
}

//----- (006C4CE0) --------------------------------------------------------  // acclient.c:733151
int _E115_0()
{
  PStringBase<char>::PStringBase<char>(&SOURCE_GAME_PATH_0, "src/game");
  return atexit(_E116_28);
}

//----- (006C4D00) --------------------------------------------------------  // acclient.c:733158
int _E118_2()
{
  PStringBase<char>::PStringBase<char>(&SOURCE_ENGINE_PATH_0, "src/engine");
  return atexit(_E119_54);
}

//----- (006C4D20) --------------------------------------------------------  // acclient.c:733165
int _E121_2()
{
  PStringBase<char>::PStringBase<char>(&TOOLS_BIN_PATH_0, "tools/bin");
  return atexit(_E122_41);
}

//----- (006C4D40) --------------------------------------------------------  // acclient.c:733172
int _E124_2()
{
  PStringBase<char>::PStringBase<char>(&CONFIG_TOOLS_PATH_0, "config/tools");
  return atexit(_E125_17);
}

//----- (006C4D60) --------------------------------------------------------  // acclient.c:733179
int _E127_2()
{
  PStringBase<char>::PStringBase<char>(&OUTPUT_INI_PATH_0, "output/ini");
  return atexit(_E128_18);
}

//----- (006C4D80) --------------------------------------------------------  // acclient.c:733186
int _E130_2()
{
  PStringBase<char>::PStringBase<char>(&DATA_PATH_0, "data");
  return atexit(_E131_14);
}

//----- (006C4DA0) --------------------------------------------------------  // acclient.c:733193
int _E133_2()
{
  PStringBase<char>::PStringBase<char>(&DOC_PATH_0, "doc");
  return atexit(_E134_13);
}

//----- (006C4DC0) --------------------------------------------------------  // acclient.c:733200
int _E136_1()
{
  PStringBase<char>::PStringBase<char>(&EXPORT_PATH_0, "export");
  return atexit(_E137_14);
}

//----- (006C4DE0) --------------------------------------------------------  // acclient.c:733207
int _E139_1()
{
  PStringBase<char>::PStringBase<char>(&SDK_PATH_0, "sdk");
  return atexit(_E140_9);
}

//----- (006C4E00) --------------------------------------------------------  // acclient.c:733214
int _E142_1()
{
  PStringBase<char>::PStringBase<char>(&SOURCE_PATH_0, "src");
  return atexit(_E143_11);
}

//----- (006C4E20) --------------------------------------------------------  // acclient.c:733221
int _E145_1()
{
  PStringBase<char>::PStringBase<char>(&TOOLS_PATH_0, "tools");
  return atexit(_E146_10);
}

//----- (006C4E40) --------------------------------------------------------  // acclient.c:733228
int _E148_1()
{
  PStringBase<char>::PStringBase<char>(&PORTAL_PATH_0, "portal");
  return atexit(_E149_10);
}

//----- (006C4E60) --------------------------------------------------------  // acclient.c:733235
int _E151_1()
{
  PStringBase<char>::PStringBase<char>(&AC_PATH_0, "ac");
  return atexit(_E152_9);
}

//----- (006C4E80) --------------------------------------------------------  // acclient.c:733242
int _E154_2()
{
  PStringBase<char>::PStringBase<char>(&ProjectSettings::sm_settingsFilePath, "config/ProjectSettings.xml");
  return atexit(_E155_7);
}

//----- (006C4EA0) --------------------------------------------------------  // acclient.c:733249
int _E157_1()
{
  ProjectSettings::sm_settingsFile = (int)PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(_E158_10);
}
// 836D44: using guessed type int ProjectSettings::sm_settingsFile;

//----- (006C4EC0) --------------------------------------------------------  // acclient.c:733258
int __fastcall _E160_2(int a1)
{
  ProjectSettings::sm_settings._M_ht._M_equals.0 = (_STL::binary_function<PStringBase<char>,PStringBase<char>,bool>)BYTE3(a1);
  ProjectSettings::sm_settings._M_ht._M_hash = (_STL::hash<PStringBase<char> >)BYTE3(a1);
  ProjectSettings::sm_settings._M_ht._M_get_key.0 = (_STL::unary_function<_STL::pair<PStringBase<char> const ,PStringBase<char> >,PStringBase<char> const >)BYTE3(a1);
  _STL::hashtable<_STL::pair<PStringBase<char> const,PStringBase<char>>,PStringBase<char>,_STL::hash<PStringBase<char>>,_STL::_Select1st<_STL::pair<PStringBase<char> const,PStringBase<char>>>,_STL::equal_to<PStringBase<char>>,_STL::allocator<_STL::pair<PStringBase<char> const,PStringBase<char>>>>::_M_initialize_buckets(
    &ProjectSettings::sm_settings._M_ht,
    0x64u);
  return atexit(_E161_7);
}

//----- (00727190) --------------------------------------------------------  // acclient.c:824899
void __cdecl _E74_21()
{
  char *v0; // esi@1

  v0 = (char *)&PROJECTSETTING_0.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&PROJECTSETTING_0.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007271C0) --------------------------------------------------------  // acclient.c:824912
void __cdecl _E77_39()
{
  char *v0; // esi@1

  v0 = &NAME_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NAME_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007271F0) --------------------------------------------------------  // acclient.c:824925
void __cdecl _E80_13()
{
  char *v0; // esi@1

  v0 = &VALUE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VALUE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727220) --------------------------------------------------------  // acclient.c:824938
void __cdecl _E83_4()
{
  char *v0; // esi@1

  v0 = &BRANCH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BRANCH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727250) --------------------------------------------------------  // acclient.c:824951
void __cdecl _E86_2()
{
  char *v0; // esi@1

  v0 = &BRANCHBASEDIR_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BRANCHBASEDIR_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727280) --------------------------------------------------------  // acclient.c:824964
void __cdecl _E89_13()
{
  char *v0; // esi@1

  v0 = &PROJECTNAME_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PROJECTNAME_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007272B0) --------------------------------------------------------  // acclient.c:824977
void __cdecl _E92_10()
{
  char *v0; // esi@1

  v0 = &LONGNAME_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LONGNAME_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007272E0) --------------------------------------------------------  // acclient.c:824990
void __cdecl sub_7272E0()
{
  char *v0; // esi@1

  v0 = &ENUMDB_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ENUMDB_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727310) --------------------------------------------------------  // acclient.c:825003
void __cdecl _E98_23()
{
  char *v0; // esi@1

  v0 = &DIDNAME_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DIDNAME_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727340) --------------------------------------------------------  // acclient.c:825016
void __cdecl _E101_53()
{
  char *v0; // esi@1

  v0 = &RCS_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RCS_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727370) --------------------------------------------------------  // acclient.c:825029
void __cdecl _E104_23()
{
  char *v0; // esi@1

  v0 = &PREPROC_KEYS_BASE_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PREPROC_KEYS_BASE_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007273A0) --------------------------------------------------------  // acclient.c:825042
void __cdecl _E107_55()
{
  char *v0; // esi@1

  v0 = &CURRENT_PROJECT_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CURRENT_PROJECT_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007273D0) --------------------------------------------------------  // acclient.c:825055
void __cdecl sub_7273D0()
{
  char *v0; // esi@1

  v0 = &DATA_GAME_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DATA_GAME_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727400) --------------------------------------------------------  // acclient.c:825068
void __cdecl _E113_36()
{
  char *v0; // esi@1

  v0 = &DATA_ENGINE_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DATA_ENGINE_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727430) --------------------------------------------------------  // acclient.c:825081
void __cdecl _E116_28()
{
  char *v0; // esi@1

  v0 = &SOURCE_GAME_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SOURCE_GAME_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727460) --------------------------------------------------------  // acclient.c:825094
void __cdecl _E119_54()
{
  char *v0; // esi@1

  v0 = &SOURCE_ENGINE_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SOURCE_ENGINE_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727490) --------------------------------------------------------  // acclient.c:825107
void __cdecl _E122_41()
{
  char *v0; // esi@1

  v0 = &TOOLS_BIN_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TOOLS_BIN_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007274C0) --------------------------------------------------------  // acclient.c:825120
void __cdecl _E125_17()
{
  char *v0; // esi@1

  v0 = &CONFIG_TOOLS_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CONFIG_TOOLS_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007274F0) --------------------------------------------------------  // acclient.c:825133
void __cdecl _E128_18()
{
  char *v0; // esi@1

  v0 = &OUTPUT_INI_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OUTPUT_INI_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727520) --------------------------------------------------------  // acclient.c:825146
void __cdecl _E131_14()
{
  char *v0; // esi@1

  v0 = &DATA_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DATA_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727550) --------------------------------------------------------  // acclient.c:825159
void __cdecl _E134_13()
{
  char *v0; // esi@1

  v0 = &DOC_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DOC_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727580) --------------------------------------------------------  // acclient.c:825172
void __cdecl _E137_14()
{
  char *v0; // esi@1

  v0 = &EXPORT_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EXPORT_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007275B0) --------------------------------------------------------  // acclient.c:825185
void __cdecl _E140_9()
{
  char *v0; // esi@1

  v0 = &SDK_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SDK_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007275E0) --------------------------------------------------------  // acclient.c:825198
void __cdecl _E143_11()
{
  char *v0; // esi@1

  v0 = &SOURCE_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SOURCE_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727610) --------------------------------------------------------  // acclient.c:825211
void __cdecl _E146_10()
{
  char *v0; // esi@1

  v0 = &TOOLS_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TOOLS_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727640) --------------------------------------------------------  // acclient.c:825224
void __cdecl _E149_10()
{
  char *v0; // esi@1

  v0 = &PORTAL_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PORTAL_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727670) --------------------------------------------------------  // acclient.c:825237
void __cdecl _E152_9()
{
  char *v0; // esi@1

  v0 = &AC_PATH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AC_PATH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007276A0) --------------------------------------------------------  // acclient.c:825250
void __cdecl _E155_7()
{
  char *v0; // esi@1

  v0 = &ProjectSettings::sm_settingsFilePath.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ProjectSettings::sm_settingsFilePath.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007276D0) --------------------------------------------------------  // acclient.c:825263
void __cdecl _E158_10()
{
  int v0; // esi@1

  v0 = ProjectSettings::sm_settingsFile - 20;
  if ( !InterlockedDecrement((volatile LONG *)(ProjectSettings::sm_settingsFile - 20 + 4)) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}
// 836D44: using guessed type int ProjectSettings::sm_settingsFile;

//----- (00727700) --------------------------------------------------------  // acclient.c:825277
void __cdecl _E161_7()
{
  _STL::hashtable<_STL::pair<PStringBase<char> const,PStringBase<char>>,PStringBase<char>,_STL::hash<PStringBase<char>>,_STL::_Select1st<_STL::pair<PStringBase<char> const,PStringBase<char>>>,_STL::equal_to<PStringBase<char>>,_STL::allocator<_STL::pair<PStringBase<char> const,PStringBase<char>>>>::clear(&ProjectSettings::sm_settings._M_ht);
  if ( ProjectSettings::sm_settings._M_ht._M_buckets._M_start )
    _STL::__node_alloc<1,0>::deallocate(
      ProjectSettings::sm_settings._M_ht._M_buckets._M_start,
      4
    * (ProjectSettings::sm_settings._M_ht._M_buckets._M_end_of_storage._M_data
     - ProjectSettings::sm_settings._M_ht._M_buckets._M_start));
}

