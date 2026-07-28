/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : falloc
   Object     : CORE\falloc\falloc.obj
   Functions  : 4
   Addresses  : 0065FFB0 - 00660170 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0065FFB0) --------------------------------------------------------  // acclient.c:630426
void __thiscall _STL::vector<unsigned char *,_STL::allocator<unsigned char *>>::_M_insert_overflow(_STL::vector<unsigned char *,_STL::allocator<unsigned char *> > *this, char **__position, char *const *__x, _STL::__true_type *__formal, unsigned int __fill_len, bool __atend)
{
  _STL::vector<unsigned char *,_STL::allocator<unsigned char *> > *v6; // ebp@1
  unsigned int v7; // edi@1
  void *v8; // ecx@1
  int v9; // ecx@3
  bool v10; // zf@3
  const unsigned int v11; // ecx@3
  char **v12; // eax@8
  char *v13; // eax@9
  char *v14; // esi@10
  unsigned int v15; // ecx@12
  char *v16; // edi@14
  char **v17; // esi@15
  unsigned int v18; // eax@19
  const unsigned int v19; // edx@19
  unsigned int v20; // [sp-4h] [bp-10h]@4
  const unsigned int __len; // [sp+8h] [bp-4h]@1

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
  v6->_M_start = (char **)__fill_len;
  v6->_M_finish = (char **)v16;
  v6->_M_end_of_storage._M_data = (char **)(v18 + 4 * v19);
}

//----- (006600B0) --------------------------------------------------------  // acclient.c:630505
void __thiscall FallocPool::FallocPool(FallocPool *this, unsigned int _chunkSize, unsigned int _chunksPerPool, void (__cdecl *_dumpFunction)(char *, unsigned int))
{
  this->m_chunkSize = _chunkSize;
  this->m_chunksPerPool = _chunksPerPool;
  this->m_poolArray._M_start = 0;
  this->m_poolArray._M_finish = 0;
  this->m_poolArray._M_end_of_storage._M_data = 0;
  this->m_firstFreeChunk = 0;
  if ( _dumpFunction )
    this->m_dumpFunction = _dumpFunction;
  else
    this->m_dumpFunction = (void (__cdecl *)(char *, unsigned int))CAsyncStateHandler::OnStateHandlerInit;
}

//----- (006600F0) --------------------------------------------------------  // acclient.c:630520
void __thiscall FallocPool::~FallocPool(FallocPool *this)
{
  FallocPool *v1; // edi@1
  void **v2; // esi@1
  int v3; // esi@3
  int v4; // eax@4
  int *v5; // edi@6

  v1 = this;
  v2 = (void **)this->m_poolArray._M_start;
  if ( v2 != (void **)this->m_poolArray._M_finish )
  {
    do
    {
      operator delete[](*v2);
      ++v2;
    }
    while ( v2 != (void **)v1->m_poolArray._M_finish );
  }
  v3 = (int)v1->m_poolArray._M_start;
  if ( v3 )
  {
    v4 = 4 * ((signed int)((char *)v1->m_poolArray._M_end_of_storage._M_data - v3) >> 2);
    if ( (unsigned int)v4 <= 0x80 )
    {
      v5 = &_STL::__node_alloc<1,0>::_S_free_list[(unsigned int)(v4 - 1) >> 3];
      _STL::_STLP_mutex_spin<0>::_M_do_lock(&_STL::_Node_Alloc_Lock<1,0>::_S_lock);
      *(_DWORD *)v3 = *v5;
      *v5 = v3;
      _STL::_Node_Alloc_Lock<1,0>::_S_lock = 0;
    }
    else
    {
      operator delete(v1->m_poolArray._M_start);
    }
  }
}
// 8366C8: using guessed type int _STL::__node_alloc<1,0>::_S_free_list[];

//----- (00660170) --------------------------------------------------------  // acclient.c:630560
void __thiscall FallocPool::AllocateNewPool(FallocPool *this)
{
  FallocPool *v1; // esi@1
  char *v2; // eax@1
  const unsigned int v3; // edi@1
  int v4; // ecx@1
  char *i; // edx@1
  char **v6; // edx@3
  char v7; // [sp+Bh] [bp-5h]@7
  char *newPool; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = (char *)operator new[](this->m_chunksPerPool * this->m_chunkSize);
  v3 = v1->m_chunkSize;
  v4 = (int)&v2[v1->m_chunkSize * (v1->m_chunksPerPool - 1)];
  newPool = v2;
  for ( i = v2; i != (char *)v4; i += v1->m_chunkSize )
  {
    *(_DWORD *)i = &i[v3];
    v3 = v1->m_chunkSize;
  }
  *(_DWORD *)i = v1->m_firstFreeChunk;
  v1->m_firstFreeChunk = v2;
  v6 = v1->m_poolArray._M_finish;
  if ( v6 == v1->m_poolArray._M_end_of_storage._M_data )
  {
    _STL::vector<unsigned char *,_STL::allocator<unsigned char *>>::_M_insert_overflow(
      &v1->m_poolArray,
      v6,
      &newPool,
      (_STL::__true_type *)&v7,
      1u,
      1);
  }
  else
  {
    if ( v6 )
      *v6 = v2;
    ++v1->m_poolArray._M_finish;
  }
}

