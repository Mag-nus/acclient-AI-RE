/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : WTimeStamper
   Object     : PORTAL\weenie_net\WTimeStamper.obj
   Functions  : 16
   Addresses  : 006B2990 - 006B3040 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B2990) --------------------------------------------------------  // acclient.c:716248
int __thiscall WTimeStamper::UpdateHouseRestrictionTS(WTimeStamper *this, char ts)
{
  char v2; // bl@1
  bool v3; // cf@2
  int result; // eax@5

  v2 = this->_house_ts;
  if ( abs((unsigned __int8)ts - (unsigned __int8)v2) > 127 )
    v3 = (unsigned __int8)v2 < (unsigned __int8)ts;
  else
    v3 = (unsigned __int8)ts < (unsigned __int8)v2;
  if ( v3 )
  {
    result = 0;
  }
  else
  {
    this->_house_ts = ts;
    result = 1;
  }
  return result;
}

//----- (006B29D0) --------------------------------------------------------  // acclient.c:716272
int __thiscall WTimeStamper::GetPackSize(WTimeStamper *this)
{
  PackObjVtbl *v1; // eax@1
  int result; // eax@1
  void *mem; // [sp+0h] [bp-4h]@1

  mem = this;
  v1 = this->_table.vfptr;
  mem = 0;
  result = ((int (__thiscall *)(PackObjVtbl **, void **, _DWORD))v1->Pack)(&this->_table.vfptr, &mem, 0) + 1;
  if ( result & 3 )
    result += 4 - (result & 3);
  return result;
}

//----- (006B2A10) --------------------------------------------------------  // acclient.c:716288
unsigned int __thiscall WTimeStamper::Pack(WTimeStamper *this, void **addr, unsigned int size)
{
  WTimeStamper *v3; // edi@1
  unsigned int v4; // ebx@1

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    *(_BYTE *)*addr = v3->_house_ts;
    *addr = (char *)*addr + 1;
    ((void (__thiscall *)(int, void **, unsigned int))v3->_table.vfptr->Pack)(&v3->_table.vfptr, addr, size);
    PackObj::ALIGN_PTR(addr);
  }
  return v4;
}

//----- (006B2A50) --------------------------------------------------------  // acclient.c:716306
int __thiscall WTimeStamper::UnPack(WTimeStamper *this, void **addr, unsigned int size)
{
  void *v3; // edx@1
  char *v4; // eax@1
  int v5; // eax@1
  unsigned int v6; // edx@2
  int v7; // eax@4
  int v8; // eax@6

  v3 = *addr;
  this->_house_ts = *(_BYTE *)*addr;
  v4 = (char *)*addr + 1;
  *addr = v4;
  v5 = v4 - (_BYTE *)v3;
  if ( size <= v5 )
    v6 = 0;
  else
    v6 = size - v5;
  ((void (__thiscall *)(PackObjVtbl **, void **, unsigned int))this->_table.vfptr->UnPack)(
    &this->_table.vfptr,
    addr,
    v6);
  v7 = (signed int)*addr % 4;
  if ( v7 && 4 != v7 )
  {
    v8 = 4 - v7;
    do
    {
      *(_BYTE *)*addr = 0;
      --v8;
      *addr = (char *)*addr + 1;
    }
    while ( v8 );
  }
  return 1;
}

//----- (006B2AB0) --------------------------------------------------------  // acclient.c:716344
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0> *v2; // esi@1
  HashTableData<unsigned long,unsigned char> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::vftable;
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
// 803BF0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::vftable[2])(void *, char);

//----- (006B2AF0) --------------------------------------------------------  // acclient.c:716365
HashTable<unsigned long,unsigned char,0> *__thiscall HashTable<unsigned long,unsigned char,0>::vector_deleting_destructor(HashTable<unsigned long,unsigned char,0> *this, unsigned int a2)
{
  HashTable<unsigned long,unsigned char,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,unsigned char,0>Vtbl *)&HashTable<unsigned long,unsigned char,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::vftable;
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
// 803BF0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::vftable[2])(void *, char);
// 803BF4: using guessed type int (__thiscall *HashTable<unsigned long,unsigned char,0>::vftable)(void *, char);

//----- (006B2B50) --------------------------------------------------------  // acclient.c:716391
PHashTable<unsigned long,unsigned char> *__thiscall PHashTable<unsigned long,unsigned char>::vector_deleting_destructor(PHashTable<unsigned long,unsigned char> *this, unsigned int a2)
{
  return PHashTable<unsigned long,unsigned char>::scalar_deleting_destructor(
           (PHashTable<unsigned long,unsigned char> *)((char *)this - 116),
           a2);
}

//----- (006B2B60) --------------------------------------------------------  // acclient.c:716399
PHashTable<unsigned long,unsigned char> *__thiscall PHashTable<unsigned long,unsigned char>::scalar_deleting_destructor(PHashTable<unsigned long,unsigned char> *this, unsigned int a2)
{
  PHashTable<unsigned long,unsigned char> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PHashTable<unsigned long,unsigned char>::vftable;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (HashTable<unsigned long,unsigned char,0>Vtbl *)&HashTable<unsigned long,unsigned char,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::vftable;
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
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 803BF0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::vftable[2])(void *, char);
// 803BF4: using guessed type int (__thiscall *HashTable<unsigned long,unsigned char,0>::vftable)(void *, char);
// 803BF8: using guessed type void *PHashTable<unsigned long,unsigned char>::vftable;

//----- (006B2BC0) --------------------------------------------------------  // acclient.c:716429
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,unsigned char> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,unsigned char> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 803BF0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::vftable[2])(void *, char);

//----- (006B2C50) --------------------------------------------------------  // acclient.c:716462
void __thiscall WTimeStamper::~WTimeStamper(WTimeStamper *this)
{
  WTimeStamper *v1; // edi@1
  char *v2; // esi@1
  void *v3; // eax@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&WTimeStamper::vftable;
  this->_table.vfptr = (PackObjVtbl *)&PHashTable<unsigned long,unsigned char>::vftable;
  v2 = (char *)&this->_table.m_intrusiveTable;
  this->_table.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->_table.vfptr = (HashTable<unsigned long,unsigned char,0>Vtbl *)&HashTable<unsigned long,unsigned char,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->_table.m_intrusiveTable);
  v3 = (void *)*((_DWORD *)v2 + 24);
  *(_DWORD *)v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::vftable;
  if ( v3 != v2 + 4 )
    operator delete[](v3);
  *((_DWORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 25) = 0;
  *((_DWORD *)v2 + 26) = 0;
  *((_DWORD *)v2 + 27) = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 803BF0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::vftable[2])(void *, char);
// 803BF4: using guessed type int (__thiscall *HashTable<unsigned long,unsigned char,0>::vftable)(void *, char);
// 803BF8: using guessed type void *PHashTable<unsigned long,unsigned char>::vftable;
// 803C10: using guessed type int (__thiscall *WTimeStamper::vftable)(void *, char);

//----- (006B2CB0) --------------------------------------------------------  // acclient.c:716492
WTimeStamper *__thiscall WTimeStamper::scalar_deleting_destructor(WTimeStamper *this, unsigned int a2)
{
  WTimeStamper *v2; // esi@1

  v2 = this;
  WTimeStamper::~WTimeStamper(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006B2CD0) --------------------------------------------------------  // acclient.c:716504
void __thiscall WTimeStamper::WTimeStamper(WTimeStamper *this)
{
  WTimeStamper *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&WTimeStamper::vftable;
  this->_table.vfptr = (HashTable<unsigned long,unsigned char,0>Vtbl *)&HashTable<unsigned long,unsigned char,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>(
    &this->_table.m_intrusiveTable,
    0x17u);
  v1->_table.vfptr = (PackObjVtbl *)&StreamPackObj::vftable;
  v1->_table.vfptr = (HashTable<unsigned long,unsigned char,0>Vtbl *)&PHashTable<unsigned long,unsigned char>::vftable;
  v1->_table.vfptr = (PackObjVtbl *)&PHashTable<unsigned long,unsigned char>::vftable;
  v1->_house_ts = 0;
}
// 7C9DC0: using guessed type int (__thiscall *StreamPackObj::vftable)(void *, char);
// 803BF4: using guessed type int (__thiscall *HashTable<unsigned long,unsigned char,0>::vftable)(void *, char);
// 803BF8: using guessed type void *PHashTable<unsigned long,unsigned char>::vftable;
// 803C10: using guessed type int (__thiscall *WTimeStamper::vftable)(void *, char);
// 803C24: using guessed type int (__thiscall *PHashTable<unsigned long,unsigned char>::vftable)(void *, char);

//----- (006B2D10) --------------------------------------------------------  // acclient.c:716526
char __thiscall HashTable<unsigned long,unsigned char,0>::add(HashTable<unsigned long,unsigned char,0> *this, const unsigned int *_key, const char *_data)
{
  HashTable<unsigned long,unsigned char,0> *v3; // edi@1
  void *v4; // eax@1
  void *v5; // esi@2
  char result; // al@7

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    *((_DWORD *)v4 + 1) = 0;
    *((_BYTE *)v4 + 8) = *_data;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v3->m_intrusiveTable,
         (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v5) )
  {
    result = 1;
  }
  else
  {
    if ( v5 )
      operator delete(v5);
    result = 0;
  }
  return result;
}

//----- (006B2D70) --------------------------------------------------------  // acclient.c:716562
int __thiscall WTimeStamper::UpdateTS(WTimeStamper *this, unsigned int key, char new_ts)
{
  HashTableData<unsigned long,unsigned char> *v3; // eax@1
  int result; // eax@4
  int v5; // esi@6
  unsigned __int8 v6; // cl@7
  __int64 v7; // rax@7
  bool v8; // cf@8

  v3 = this->_table.m_intrusiveTable.m_buckets[key % this->_table.m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != key )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 && (v5 = (int)&v3->m_data, v3 != (HashTableData<unsigned long,unsigned char> *)-8) )
  {
    v6 = *(_BYTE *)v5;
    v7 = (unsigned __int8)new_ts - *(_BYTE *)v5;
    if ( (signed int)((HIDWORD(v7) ^ v7) - HIDWORD(v7)) > 127 )
      v8 = v6 < (unsigned __int8)new_ts;
    else
      v8 = (unsigned __int8)new_ts < v6;
    if ( v8 )
    {
      ++num_rejects;
      result = 0;
    }
    else
    {
      *(_BYTE *)v5 = new_ts;
      result = 1;
    }
  }
  else
  {
LABEL_4:
    result = (unsigned __int8)HashTable<unsigned long,unsigned char,0>::add(
                                (HashTable<unsigned long,unsigned char,0> *)&this->_table.vfptr,
                                &key,
                                &new_ts);
  }
  return result;
}

//----- (006B2E10) --------------------------------------------------------  // acclient.c:716611
int __thiscall PHashTable<unsigned long,unsigned char>::StreamPack(PHashTable<unsigned long,unsigned char> *this, STREAMTYPE op, void **addr, unsigned int *size)
{
  STREAMTYPE v4; // esi@1
  PHashTable<unsigned long,unsigned char> *v5; // edi@1
  STREAMTYPE v6; // ebx@2
  const unsigned int *v7; // eax@3
  void **v8; // ebp@3
  unsigned int *v9; // ebx@3
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // edi@4
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *v11; // eax@4
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *v12; // eax@5
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v13; // edi@9
  unsigned int v14; // eax@10
  unsigned int v15; // eax@12
  __int32 v16; // edi@12
  HashTableData<unsigned long,Sex_CG> *v17; // ebx@12
  unsigned int v18; // ebp@12
  void *v19; // eax@13
  void *v20; // esi@13
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *v22; // [sp+10h] [bp-28h]@9
  HashIterator<unsigned long,unsigned char,0> iter; // [sp+14h] [bp-24h]@4
  HashIterator<unsigned long,SpellSet,0> v24; // [sp+20h] [bp-18h]@4
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+2Ch] [bp-Ch]@4

  v4 = op;
  v5 = this;
  if ( op == 2 )
  {
    v13 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)this[-1].m_intrusiveTable.m_aInplaceBuckets;
    v22 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)this[-1].m_intrusiveTable.m_aInplaceBuckets;
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)this[-1].m_intrusiveTable.m_aInplaceBuckets);
    if ( STREAMPACK(STREAM_UNPACK, (unsigned int *)&op, addr, size) )
    {
      v14 = (unsigned int)op >> 24;
      if ( (unsigned int)op >> 24 >= g_numBucketSizes )
        v14 = g_numBucketSizes - 1;
      v15 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::nice_num_buckets(g_bucketSizesBegin[v14]);
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::resize_internal(v13, v15);
      v16 = op & 0xFFFFFF;
      v17 = 0;
      v18 = 0;
      if ( !(op & 0xFFFFFF) )
        return 1;
      while ( 1 )
      {
        v19 = operator new(0xCu);
        v20 = 0;
        if ( v19 )
        {
          *((_DWORD *)v19 + 1) = 0;
          v20 = v19;
        }
        if ( !STREAMPACK(STREAM_UNPACK, (unsigned int *)v20, addr, size)
          || !STREAMPACK(STREAM_UNPACK, (char *)v20 + 8, addr, size) )
          break;
        IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
          v22,
          (HashTableData<unsigned long,Sex_CG> *)v20,
          v17);
        ++v18;
        v17 = (HashTableData<unsigned long,Sex_CG> *)v20;
        if ( v18 >= v16 )
          return 1;
      }
    }
  }
  else
  {
    op = (STREAMTYPE)this[-1].vfptr;
    v6 = op;
    if ( (unsigned int)op <= 0xFFFFFF )
    {
      v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::get_bucket_size_pointer(this[-1].m_intrusiveTable.m_numElements);
      v8 = addr;
      op = ((v7 - g_bucketSizesBegin) << 24) | v6;
      v9 = size;
      if ( STREAMPACK(v4, (unsigned int *)&op, addr, size) )
      {
        v10 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v5[-1].m_intrusiveTable.m_aInplaceBuckets;
        v11 = (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
                                                                                                  v10,
                                                                                                  &result);
        HashIterator<unsigned long,SpellSet,0>::HashIterator<unsigned long,SpellSet,0>(&v24, v11);
        for ( iter = (HashIterator<unsigned long,unsigned char,0>)v24;
              ;
              IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::operator++((IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *)&iter) )
        {
          v12 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::end(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *)v10,
                  (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *)&result);
          HashIterator<unsigned long,SpellSet,0>::HashIterator<unsigned long,SpellSet,0>(&v24, v12);
          if ( iter.m_iter.m_currElement == (HashTableData<unsigned long,unsigned char> *)v24.m_iter.m_currElement )
            break;
          if ( !STREAMPACK(v4, &iter.m_iter.m_currElement->m_hashKey, v8, v9)
            || !STREAMPACK(v4, &iter.m_iter.m_currElement->m_data, v8, v9) )
            return 0;
        }
        return 1;
      }
    }
  }
  return 0;
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;

//----- (006B3040) --------------------------------------------------------  // acclient.c:716735
int __cdecl STREAMPACK(STREAMTYPE op, char *obj, void **addr, unsigned int *size)
{
  int result; // eax@4
  char *v5; // ecx@5
  unsigned int *v6; // eax@8

  if ( op == STREAM_GETPACKSIZE )
  {
    v6 = size;
LABEL_11:
    --*v6;
    return 1;
  }
  if ( op == 1 )
  {
    v6 = size;
    if ( *size >= 1 )
    {
      *(_BYTE *)*addr = *obj;
      *addr = (char *)*addr + 1;
      --*size;
      return 1;
    }
    goto LABEL_11;
  }
  if ( op == 2 )
  {
    v5 = (char *)*addr;
    if ( *size >= 1 )
    {
      *obj = *v5;
      *addr = (char *)*addr + 1;
      *size += v5 - (_BYTE *)*addr;
      result = 1;
    }
    else
    {
      result = 0;
      *size = *size;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

