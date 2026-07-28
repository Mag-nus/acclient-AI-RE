/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSpellTable
   Object     : AC\accmagic\CSpellTable.obj
   Functions  : 42
   Addresses  : 00427010 - 0070AD50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00427010) --------------------------------------------------------  // acclient.c:99354
const unsigned int *__cdecl IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::get_bucket_size_pointer(unsigned int _n)
{
  const unsigned int *v1; // esi@1
  const unsigned int *result; // eax@1

  v1 = g_bucketSizesEnd;
  result = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_n);
  if ( result == v1 )
    --result;
  return result;
}

//----- (004290E0) --------------------------------------------------------  // acclient.c:101605
IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *__thiscall IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::operator++(IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *this)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *result; // eax@1
  HashTableData<unsigned long,SpellSet> *v2; // ecx@1
  HashTableData<unsigned long,SpellSet> **v3; // edx@2
  HashTableData<unsigned long,SpellSet> **v4; // ecx@3

  result = this;
  v2 = this->m_currElement->m_hashNext;
  result->m_currElement = v2;
  if ( !v2 )
  {
    v3 = &result->m_currHashTable->m_buckets[result->m_currHashTable->m_numBuckets];
    while ( 1 )
    {
      v4 = result->m_currBucket + 1;
      result->m_currBucket = v4;
      if ( v4 == v3 )
        break;
      if ( *v4 )
      {
        result->m_currElement = *v4;
        return result;
      }
    }
  }
  return result;
}

//----- (004E6180) --------------------------------------------------------  // acclient.c:276029
signed int gmUIElement_PortalStormIndicator::GetUIElementType()
{
  return 268435461;
}

//----- (005974C0) --------------------------------------------------------  // acclient.c:449234
PackableHashIterator<unsigned long,CSpellBase> *__thiscall PackableHashIterator<unsigned long,CSpellBase>::scalar_deleting_destructor(PackableHashIterator<unsigned long,CSpellBase> *this, unsigned int a2)
{
  PackableHashIterator<unsigned long,CSpellBase> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackableHashIterator<unsigned long,CSpellBase>Vtbl *)PackableHashIterator<unsigned long,CSpellBase>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7E4858: using guessed type int (__thiscall *PackableHashIterator<unsigned long,CSpellBase>::vftable[3])(void *, char);

//----- (005974E0) --------------------------------------------------------  // acclient.c:449247
unsigned int __thiscall CSpellTable::Pack(CSpellTable *this, void **addr, unsigned int size)
{
  CSpellTable *v3; // edi@1
  HashTableData<unsigned long,SpellSet> *v4; // eax@1
  char *v5; // ebx@1
  int v6; // esi@1
  unsigned int v7; // esi@1
  CSpellTable *v9; // [sp+8h] [bp-4h]@1

  v9 = this;
  v3 = this;
  v4 = this->m_SpellSetHash.m_intrusiveTable.m_aInplaceBuckets[15];
  v9 = 0;
  v5 = (char *)&this->m_bLoaded;
  v6 = ((int (__thiscall *)(HashTableData<unsigned long,SpellSet> **, int *, _DWORD))v4->m_data.m_countTiers.vfptr)(
         &this->m_SpellSetHash.m_intrusiveTable.m_aInplaceBuckets[15],
         &v9,
         0);
  v7 = (*(int (__thiscall **)(int, int *, _DWORD))(*(_DWORD *)v5 + 12))(&v3->m_bLoaded, &v9, 0) + v6;
  if ( size >= v7 )
  {
    (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)&v3->m_bLoaded + 12))(&v3->m_bLoaded, addr, size);
    ((void (__thiscall *)(int, void **, unsigned int))v3->m_SpellSetHash.m_intrusiveTable.m_aInplaceBuckets[15]->m_data.m_countTiers.vfptr)(
      &v3->m_SpellSetHash.m_intrusiveTable.m_aInplaceBuckets[15],
      addr,
      size);
  }
  return v7;
}

//----- (00597550) --------------------------------------------------------  // acclient.c:449278
int __thiscall CSpellTable::UnPack(CSpellTable *this, void **addr, unsigned int size)
{
  void **v3; // edi@1
  void *v4; // ebp@1
  CSpellTable *v5; // esi@1
  int v6; // eax@1
  char *v7; // ebx@1
  int v8; // ST18_4@1
  int v9; // eax@1
  unsigned int v10; // ebx@1

  v3 = addr;
  v4 = *addr;
  v5 = this;
  v6 = *(_DWORD *)&this->m_bLoaded;
  addr = 0;
  v7 = (char *)&this->m_SpellSetHash.m_intrusiveTable.m_aInplaceBuckets[15];
  v8 = (*(int (__thiscall **)(bool *, void ***, _DWORD))(v6 + 12))(&this->m_bLoaded, &addr, 0);
  v9 = (*(int (__thiscall **)(int, void ***, _DWORD))(*(_DWORD *)v7 + 12))(
         &v5->m_SpellSetHash.m_intrusiveTable.m_aInplaceBuckets[15],
         &addr,
         0);
  v10 = size;
  if ( size < v9 + v8 )
    return 0;
  (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)&v5->m_bLoaded + 16))(&v5->m_bLoaded, v3, size);
  ((void (__thiscall *)(int, void **, unsigned int))v5->m_SpellSetHash.m_intrusiveTable.m_aInplaceBuckets[15]->m_data.m_countTiers._head)(
    &v5->m_SpellSetHash.m_intrusiveTable.m_aInplaceBuckets[15],
    v3,
    v10);
  if ( v10 < (_BYTE *)*v3 - (_BYTE *)v4 )
  {
    *v3 = v4;
    return 0;
  }
  return 1;
}

//----- (005975E0) --------------------------------------------------------  // acclient.c:449317
PackableHashIterator<unsigned long,CSpellBase> *__thiscall PackableHashTable<unsigned long,CSpellBase>::begin(PackableHashTable<unsigned long,CSpellBase> *this, PackableHashIterator<unsigned long,CSpellBase> *result)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  PackableHashData<unsigned long,CSpellBase> **v4; // edi@2
  PackableHashData<unsigned long,CSpellBase> **v5; // esi@2
  PackableHashData<unsigned long,CSpellBase> **v6; // ecx@5
  PackableHashIterator<unsigned long,CSpellBase> *v7; // eax@5
  PackableHashData<unsigned long,CSpellBase> *v8; // ecx@6

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
    result->vfptr = (PackableHashIterator<unsigned long,CSpellBase>Vtbl *)PackableHashIterator<unsigned long,CSpellBase>::vftable;
    result->_table_size = v2;
  }
  else
  {
LABEL_5:
    v6 = this->_buckets;
    v7 = result;
    result->_current = 0;
    result->_buckets = v6;
    result->vfptr = (PackableHashIterator<unsigned long,CSpellBase>Vtbl *)PackableHashIterator<unsigned long,CSpellBase>::vftable;
    result->_table_size = v2;
  }
  return v7;
}
// 7E4858: using guessed type int (__thiscall *PackableHashIterator<unsigned long,CSpellBase>::vftable[3])(void *, char);

//----- (00597640) --------------------------------------------------------  // acclient.c:449362
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *v2; // esi@1
  HashTableData<unsigned long,SpellSet> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::vftable;
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
// 7E4874: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::vftable[2])(void *, char);

//----- (00597680) --------------------------------------------------------  // acclient.c:449383
signed int __thiscall PackableHashTable<unsigned long,CSpellBase>::Pack(PackableHashTable<unsigned long,CSpellBase> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,CSpellBase> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<unsigned long,CSpellBase> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<unsigned long,CSpellBase>::pack_size(this);
  v5 = size;
  retVal = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    *addr = (char *)*addr + 4;
    v6 = 0;
    sizea = 0;
    if ( v3->_table_size )
    {
      do
      {
        v7 = v3->_buckets[v6];
        if ( v7 )
        {
          do
          {
            if ( v5 >= 4 )
            {
              *(_DWORD *)*addr = v7->_key;
              *addr = (char *)*addr + 4;
            }
            ((void (__thiscall *)(int, void **, unsigned int))v7->_data.vfptr->Pack)(&v7->_data, addr, v5);
            v7 = v7->_next;
          }
          while ( v7 );
          result = retVal;
          v6 = sizea;
        }
        ++v6;
        sizea = v6;
      }
      while ( v6 < v3->_table_size );
    }
  }
  return result;
}

//----- (00597710) --------------------------------------------------------  // acclient.c:449434
signed int __thiscall PackableHashTable<unsigned long,CSpellBase>::pack_size(PackableHashTable<unsigned long,CSpellBase> *this)
{
  PackableHashTable<unsigned long,CSpellBase> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<unsigned long,CSpellBase> *i; // esi@2
  int v6; // eax@3
  void *addr; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = this->_table_size;
  v3 = 0;
  v4 = 4;
  addr = 0;
  if ( v2 )
  {
    do
    {
      for ( i = v1->_buckets[v3]; i; v4 += v6 + 4 )
      {
        v6 = ((int (__thiscall *)(int, void **, _DWORD))i->_data.vfptr->Pack)(&i->_data, &addr, 0);
        i = i->_next;
      }
      ++v3;
    }
    while ( v3 < v1->_table_size );
  }
  return v4;
}

//----- (00597770) --------------------------------------------------------  // acclient.c:449466
void __thiscall CSpellTable::GetSubDataIDs(CSpellTable *this, QualifiedDataIDArray *id_array)
{
  PackableHashData<unsigned long,CSpellBase> *v2; // esi@1
  unsigned int v3; // ebx@2
  PackableHashData<unsigned long,CSpellBase> **v4; // edi@2
  QualifiedDataID *v5; // eax@3
  PackableHashData<unsigned long,CSpellBase> *v6; // eax@3
  int v7; // eax@4
  PackableHashIterator<unsigned long,CSpellBase> iter; // [sp+4h] [bp-10h]@1

  PackableHashTable<unsigned long,CSpellBase>::begin(&this->_spellBaseHash, &iter);
  v2 = iter._current;
  if ( iter._current )
  {
    v3 = iter._table_size;
    v4 = iter._buckets;
    do
    {
      QualifiedDataID::QualifiedDataID((QualifiedDataID *)&iter, v2->_data._iconID, 0);
      QualifiedDataIDArray::AddQDID(id_array, v5, 8u);
      v6 = v2->_next;
      if ( !v6 )
      {
        v7 = v2->_hashVal + 1;
        if ( v7 >= v3 )
        {
LABEL_7:
          v6 = 0;
        }
        else
        {
          while ( !v4[v7] )
          {
            ++v7;
            if ( v7 >= v3 )
              goto LABEL_7;
          }
          v6 = v4[v7];
        }
      }
      v2 = v6;
    }
    while ( v6 );
  }
}

//----- (005977F0) --------------------------------------------------------  // acclient.c:449513
void __thiscall PackableHashTable<unsigned long,CSpellBase>::EmptyContents(PackableHashTable<unsigned long,CSpellBase> *this)
{
  unsigned int v1; // eax@2
  PackableHashData<unsigned long,CSpellBase> *v2; // esi@3
  PackableHashData<unsigned long,CSpellBase> *v3; // ebx@4
  AC1Legacy::PSRefBuffer<char> *v4; // edi@4
  AC1Legacy::PSRefBuffer<char> *v5; // edi@7
  unsigned int i; // [sp+8h] [bp-8h]@2
  PackableHashTable<unsigned long,CSpellBase> *v7; // [sp+Ch] [bp-4h]@1

  v7 = this;
  if ( this->_buckets )
  {
    v1 = 0;
    i = 0;
    if ( this->_table_size )
    {
      do
      {
        v2 = this->_buckets[v1];
        if ( v2 )
        {
          do
          {
            v3 = v2->_next;
            MetaSpell::~MetaSpell(&v2->_data._meta_spell);
            v4 = v2->_data._desc.m_buffer;
            v2->_data._formula.vfptr = (PackObjVtbl *)&PackObj::vftable;
            if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
              v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
            v5 = v2->_data._name.m_buffer;
            if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
              v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
            v2->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
            operator delete(v2);
            v2 = v3;
          }
          while ( v3 );
          v1 = i;
          this = v7;
        }
        this->_buckets[v1++] = 0;
        i = v1;
      }
      while ( v1 < this->_table_size );
    }
  }
  this->_currNum = 0;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005978D0) --------------------------------------------------------  // acclient.c:449565
unsigned int __cdecl IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::nice_num_buckets(unsigned int _n)
{
  unsigned int *v1; // esi@1
  const unsigned int *v2; // eax@1

  v1 = g_bucketSizesEnd;
  v2 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_n);
  if ( v2 == v1 )
    --v2;
  return *v2;
}

//----- (00597910) --------------------------------------------------------  // acclient.c:449578
int __thiscall PackableHashTable<unsigned long,CSpellBase>::UnPack(PackableHashTable<unsigned long,CSpellBase> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,CSpellBase> *v3; // esi@1
  unsigned int v5; // eax@5
  unsigned int v6; // ecx@5
  unsigned int v7; // eax@5
  unsigned int v8; // ebx@5
  unsigned int v9; // ebp@5
  void *v10; // eax@12
  PackObjVtbl *v11; // edx@12
  CSpellBase *v12; // ecx@16
  unsigned int i; // [sp+8h] [bp-A0h]@10
  void *start_addr; // [sp+Ch] [bp-9Ch]@3
  unsigned int tempKey; // [sp+14h] [bp-94h]@12
  CSpellBase tempData; // [sp+18h] [bp-90h]@10

  v3 = this;
  if ( size < 4 )
    return 0;
  start_addr = *addr;
  PackableHashTable<unsigned long,CSpellBase>::EmptyContents(this);
  if ( v3->_buckets )
  {
    operator delete[](v3->_buckets);
    v3->_buckets = 0;
  }
  v3->_table_size = 0;
  v5 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  v6 = v5 >> 16;
  v7 = (unsigned __int16)v5;
  v8 = size - 4;
  v3->_table_size = v6;
  v9 = v7;
  if ( !v6 )
    return v7 == 0;
  if ( v6 <= 0x10000
    && v7 <= 0x10000
    && PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3) )
  {
    CSpellBase::CSpellBase(&tempData);
    i = 0;
    if ( v9 )
    {
      while ( v8 >= 4 )
      {
        v10 = *addr;
        v11 = tempData.vfptr;
        tempKey = *(_DWORD *)*addr;
        *addr = (char *)v10 + 4;
        if ( !((int (__thiscall *)(CSpellBase *, void **, unsigned int))v11->UnPack)(&tempData, addr, v8)
          || !PackableHashTable<unsigned long,CSpellBase>::add(v3, &tempKey, &tempData)
          && !v3->m_fThrowawayDuplicateKeysOnUnPack )
          break;
        ++i;
        if ( i >= v9 )
          goto LABEL_16;
      }
      v12 = &tempData;
    }
    else
    {
LABEL_16:
      v12 = &tempData;
      if ( size >= (_BYTE *)*addr - (_BYTE *)start_addr )
      {
        CSpellBase::~CSpellBase(&tempData);
        return 1;
      }
    }
    CSpellBase::~CSpellBase(v12);
  }
  return 0;
}

//----- (00597A70) --------------------------------------------------------  // acclient.c:449654
int __thiscall PackableHashTable<unsigned long,CSpellBase>::add(PackableHashTable<unsigned long,CSpellBase> *this, const unsigned int *key, CSpellBase *data)
{
  PackableHashTable<unsigned long,CSpellBase> *v3; // edi@1
  unsigned int v4; // esi@1
  PackableHashData<unsigned long,CSpellBase> **v5; // ebx@2
  PackableHashData<unsigned long,CSpellBase> *v6; // edx@3
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
  if ( v6 == (PackableHashData<unsigned long,CSpellBase> *)-8 )
  {
LABEL_8:
    v7 = operator new(0xA0u);
    if ( v7 )
    {
      v8 = v3->_table_size;
      *(_DWORD *)v7 = *key;
      CSpellBase::CSpellBase((CSpellBase *)((char *)v7 + 8), data);
      *((_DWORD *)v7 + 38) = 0;
      v9 = *key % v8;
      *((_DWORD *)v7 + 39) = v9;
      *((_DWORD *)v7 + 38) = v3->_buckets[v9];
      v3->_buckets[v9] = (PackableHashData<unsigned long,CSpellBase> *)v7;
      ++v3->_currNum;
      return 1;
    }
  }
  return 0;
}

//----- (00597B20) --------------------------------------------------------  // acclient.c:449702
PackableHashTable<unsigned long,CSpellBase> *__thiscall PackableHashTable<unsigned long,CSpellBase>::vector_deleting_destructor(PackableHashTable<unsigned long,CSpellBase> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,CSpellBase> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,CSpellBase>::vftable;
  PackableHashTable<unsigned long,CSpellBase>::EmptyContents(this);
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
// 7E4860: using guessed type int (__thiscall *PackableHashTable<unsigned long,CSpellBase>::vftable)(void *, char);

//----- (00597B70) --------------------------------------------------------  // acclient.c:449724
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,SpellSet> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,SpellSet> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7E4874: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::vftable[2])(void *, char);

//----- (00597C00) --------------------------------------------------------  // acclient.c:449757
SpellSetTierList *__thiscall SpellSetTierList::scalar_deleting_destructor(SpellSetTierList *this, unsigned int a2)
{
  SpellSetTierList *v2; // esi@1
  char *v3; // ecx@1

  v2 = this;
  v3 = (char *)&this->m_SpellList;
  *((_DWORD *)v3 + 4) = &PList<unsigned long>::vftable;
  *((_DWORD *)v3 + 4) = &PackObj::vftable;
  *(_DWORD *)v3 = &AC1Legacy::List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)v3);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4110: using guessed type int (__thiscall *AC1Legacy::List<unsigned long>::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;

//----- (00597C40) --------------------------------------------------------  // acclient.c:449778
int __thiscall AC1Legacy::List<SpellSetTierList>::pop_front(AC1Legacy::List<SpellSetTierList> *this, SpellSetTierList *retval)
{
  AC1Legacy::List<SpellSetTierList> *v2; // edi@1
  int v3; // esi@1
  int result; // eax@2
  int v5; // eax@3
  int v6; // ecx@7

  v2 = this;
  v3 = (int)this->_head;
  if ( v3 )
  {
    v5 = *(_DWORD *)(v3 + 28);
    this->_head = (AC1Legacy::ListNode<SpellSetTierList> *)v5;
    if ( v5 )
      *(_DWORD *)(v5 + 32) = 0;
    else
      this->_tail = 0;
    CharacterTitleTable::operator=((int)retval, v3);
    if ( v3 )
    {
      v6 = v3 + 8;
      *(_DWORD *)(v6 + 16) = &PList<unsigned long>::vftable;
      *(_DWORD *)(v6 + 16) = &PackObj::vftable;
      *(_DWORD *)v6 = &AC1Legacy::List<unsigned long>::vftable;
      List<SkillRecord *>::flush((List<SkillRecord *> *)(v3 + 8));
      *(_DWORD *)v3 = &PackObj::vftable;
      operator delete((void *)v3);
    }
    --v2->_num_elements;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4110: using guessed type int (__thiscall *AC1Legacy::List<unsigned long>::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;

//----- (00597CC0) --------------------------------------------------------  // acclient.c:449821
void __thiscall AC1Legacy::List<SpellSetTierList>::flush(AC1Legacy::List<SpellSetTierList> *this)
{
  AC1Legacy::List<SpellSetTierList> *v1; // edi@1
  AC1Legacy::ListNode<unsigned long> *v2; // eax@3
  void *v3; // ecx@5
  SpellSetTierList retval; // [sp+Ch] [bp-1Ch]@3

  v1 = this;
  while ( v1->_head )
  {
    retval.vfptr = (PackObjVtbl *)&SpellSetTierList::vftable;
    retval.m_PieceCount = 0;
    retval.m_SpellList._head = 0;
    retval.m_SpellList._tail = 0;
    retval.m_SpellList._num_elements = 0;
    retval.m_SpellList.vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&PList<unsigned long>::vftable;
    retval.m_SpellList.vfptr = (PackObjVtbl *)&PList<unsigned long>::vftable;
    AC1Legacy::List<SpellSetTierList>::pop_front(v1, &retval);
    v2 = retval.m_SpellList._head;
    retval.m_SpellList.vfptr = (PackObjVtbl *)&PackObj::vftable;
    retval.m_SpellList.vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&AC1Legacy::List<unsigned long>::vftable;
    while ( v2 )
    {
      v3 = v2;
      v2 = v2->next;
      retval.m_SpellList._head = v2;
      if ( v2 )
      {
        v2->prev = 0;
        v2 = retval.m_SpellList._head;
      }
      else
      {
        retval.m_SpellList._tail = 0;
      }
      if ( v3 )
      {
        operator delete(v3);
        v2 = retval.m_SpellList._head;
      }
      --retval.m_SpellList._num_elements;
    }
    retval.vfptr = (PackObjVtbl *)&PackObj::vftable;
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4110: using guessed type int (__thiscall *AC1Legacy::List<unsigned long>::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;
// 7A7388: using guessed type int (__thiscall *PList<unsigned long>::vftable)(void *, char);
// 7E4878: using guessed type int (__thiscall *SpellSetTierList::vftable)(void *, char);

//----- (00597D70) --------------------------------------------------------  // acclient.c:449873
PList<SpellSetTierList> *__thiscall PList<SpellSetTierList>::vector_deleting_destructor(PList<SpellSetTierList> *this, unsigned int a2)
{
  return PList<SpellSetTierList>::vector_deleting_destructor((PList<SpellSetTierList> *)((char *)this - 16), a2);
}

//----- (00597D80) --------------------------------------------------------  // acclient.c:449879
unsigned int __thiscall PList<SpellSetTierList>::Pack(PList<SpellSetTierList> *this, void **addr, unsigned int size)
{
  PList<SpellSetTierList> *v3; // esi@1
  unsigned int v4; // ebp@1
  AC1Legacy::ListNode<SpellSetTierList> *i; // esi@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr[2].__vecDelDtor)();
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3[-1].vfptr;
    *addr = (char *)*addr + 4;
    for ( i = v3[-1]._tail; i; i = i->next )
      ((void (__thiscall *)(AC1Legacy::ListNode<SpellSetTierList> *, void **, unsigned int))i->data.vfptr->Pack)(
        i,
        addr,
        size);
  }
  return v4;
}

//----- (00597DD0) --------------------------------------------------------  // acclient.c:449901
signed int __thiscall PList<SpellSetTierList>::GetPackSize(PList<SpellSetTierList> *this)
{
  AC1Legacy::ListNode<SpellSetTierList> *v1; // esi@1
  signed int v2; // edi@1
  int v3; // eax@2
  void *foo; // [sp+0h] [bp-4h]@1

  foo = this;
  v1 = this[-1]._tail;
  v2 = 4;
  for ( foo = 0; v1; v2 += v3 )
  {
    v3 = ((int (__thiscall *)(AC1Legacy::ListNode<SpellSetTierList> *, void **, _DWORD))v1->data.vfptr->Pack)(
           v1,
           &foo,
           0);
    v1 = v1->next;
  }
  return v2;
}

//----- (00597E10) --------------------------------------------------------  // acclient.c:449923
int __thiscall PList<SpellSetTierList>::UnPack(PList<SpellSetTierList> *this, void **addr, unsigned int size)
{
  int result; // eax@2
  void **v4; // esi@3
  void *v5; // ebx@3
  AC1Legacy::List<SpellSetTierList> *v6; // ebp@3
  unsigned int v7; // edi@3
  unsigned int v8; // ecx@3
  int v9; // eax@6
  SpellSetTierList tmp; // [sp+0h] [bp-1Ch]@3
  void **addra; // [sp+20h] [bp+4h]@3

  if ( size >= 4 )
  {
    v4 = addr;
    v5 = *addr;
    v6 = (AC1Legacy::List<SpellSetTierList> *)&this[-1]._head;
    AC1Legacy::List<SpellSetTierList>::flush((AC1Legacy::List<SpellSetTierList> *)&this[-1]._head);
    v7 = *(_DWORD *)*addr;
    v8 = 0;
    *v4 = (char *)*v4 + 4;
    tmp.vfptr = (PackObjVtbl *)&SpellSetTierList::vftable;
    tmp.m_PieceCount = 0;
    tmp.m_SpellList._head = 0;
    tmp.m_SpellList._tail = 0;
    tmp.m_SpellList._num_elements = 0;
    tmp.m_SpellList.vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&PList<unsigned long>::vftable;
    tmp.m_SpellList.vfptr = (PackObjVtbl *)&PList<unsigned long>::vftable;
    addra = 0;
    if ( v7 )
    {
      while ( 1 )
      {
        v9 = (_BYTE *)*v4 - (_BYTE *)v5;
        if ( size > v9 )
          v8 = size - v9;
        if ( !((int (__thiscall *)(SpellSetTierList *, void **, unsigned int))tmp.vfptr->UnPack)(&tmp, v4, v8)
          || !AC1Legacy::List<SpellSetTierList>::push_back(v6, &tmp) )
          break;
        addra = (void **)((char *)addra + 1);
        if ( (unsigned int)addra >= v7 )
          goto LABEL_4;
        v8 = 0;
      }
      tmp.m_SpellList.vfptr = (PackObjVtbl *)&PackObj::vftable;
      tmp.m_SpellList.vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&AC1Legacy::List<unsigned long>::vftable;
      List<SkillRecord *>::flush((List<SkillRecord *> *)&tmp.m_SpellList);
      result = 0;
    }
    else
    {
LABEL_4:
      tmp.m_SpellList.vfptr = (PackObjVtbl *)&PackObj::vftable;
      tmp.m_SpellList.vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&AC1Legacy::List<unsigned long>::vftable;
      List<SkillRecord *>::flush((List<SkillRecord *> *)&tmp.m_SpellList);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4110: using guessed type int (__thiscall *AC1Legacy::List<unsigned long>::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;
// 7A7388: using guessed type int (__thiscall *PList<unsigned long>::vftable)(void *, char);
// 7E4878: using guessed type int (__thiscall *SpellSetTierList::vftable)(void *, char);

//----- (00597F10) --------------------------------------------------------  // acclient.c:449994
int __thiscall AC1Legacy::List<SpellSetTierList>::push_back(AC1Legacy::List<SpellSetTierList> *this, SpellSetTierList *val)
{
  AC1Legacy::List<SpellSetTierList> *v2; // edi@1
  void *v3; // esi@1
  int v4; // eax@3
  int result; // eax@3
  AC1Legacy::ListNode<SpellSetTierList> *v6; // eax@5
  int v7; // eax@5

  v2 = this;
  v3 = operator new(0x24u);
  if ( v3 )
  {
    SpellSetTierList::SpellSetTierList((SpellSetTierList *)v3, val);
    *((_DWORD *)v3 + 7) = 0;
    *((_DWORD *)v3 + 8) = 0;
    if ( v2->_head )
    {
      v6 = v2->_tail;
      v6->next = (AC1Legacy::ListNode<SpellSetTierList> *)v3;
      *((_DWORD *)v3 + 8) = v6;
      v7 = v2->_num_elements + 1;
      v2->_tail = (AC1Legacy::ListNode<SpellSetTierList> *)v3;
      v2->_num_elements = v7;
      result = 1;
    }
    else
    {
      v4 = v2->_num_elements + 1;
      v2->_head = (AC1Legacy::ListNode<SpellSetTierList> *)v3;
      v2->_tail = (AC1Legacy::ListNode<SpellSetTierList> *)v3;
      v2->_num_elements = v4;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00597F80) --------------------------------------------------------  // acclient.c:450037
AC1Legacy::List<SpellSetTierList> *__thiscall AC1Legacy::List<SpellSetTierList>::vector_deleting_destructor(AC1Legacy::List<SpellSetTierList> *this, unsigned int a2)
{
  AC1Legacy::List<SpellSetTierList> *v2; // esi@1

  v2 = this;
  this->vfptr = (AC1Legacy::List<SpellSetTierList>Vtbl *)AC1Legacy::List<SpellSetTierList>::vftable;
  AC1Legacy::List<SpellSetTierList>::flush(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E485C: using guessed type int (__thiscall *AC1Legacy::List<SpellSetTierList>::vftable[2])(void *, char);

//----- (00597FB0) --------------------------------------------------------  // acclient.c:450051
PList<SpellSetTierList> *__thiscall PList<SpellSetTierList>::vector_deleting_destructor(PList<SpellSetTierList> *this, unsigned int a2)
{
  PList<SpellSetTierList> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PList<SpellSetTierList>::vftable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (AC1Legacy::List<SpellSetTierList>Vtbl *)AC1Legacy::List<SpellSetTierList>::vftable;
  AC1Legacy::List<SpellSetTierList>::flush((AC1Legacy::List<SpellSetTierList> *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E485C: using guessed type int (__thiscall *AC1Legacy::List<SpellSetTierList>::vftable[2])(void *, char);
// 7E4890: using guessed type void *PList<SpellSetTierList>::vftable;

//----- (00597FF0) --------------------------------------------------------  // acclient.c:450069
void __thiscall SpellSet::SpellSet(SpellSet *this)
{
  this->vfptr = (PackObjVtbl *)&SpellSet::vftable;
  this->m_countTiers._head = 0;
  this->m_countTiers._tail = 0;
  this->m_countTiers._num_elements = 0;
  this->m_countTiers.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->m_countTiers.vfptr = (AC1Legacy::List<SpellSetTierList>Vtbl *)PList<SpellSetTierList>::vftable;
  this->m_countTiers.vfptr = (PackObjVtbl *)&PList<SpellSetTierList>::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4890: using guessed type void *PList<SpellSetTierList>::vftable;
// 7E48A4: using guessed type int (__thiscall *PList<SpellSetTierList>::vftable[2])(void *, char);
// 7E48A8: using guessed type int (__thiscall *SpellSet::vftable)(void *, char);

//----- (00598020) --------------------------------------------------------  // acclient.c:450085
SpellSet *__thiscall SpellSet::scalar_deleting_destructor(SpellSet *this, unsigned int a2)
{
  SpellSet *v2; // esi@1
  char *v3; // ecx@1

  v2 = this;
  v3 = (char *)&this->m_countTiers;
  *((_DWORD *)v3 + 4) = &PList<SpellSetTierList>::vftable;
  *((_DWORD *)v3 + 4) = &PackObj::vftable;
  *(_DWORD *)v3 = AC1Legacy::List<SpellSetTierList>::vftable;
  AC1Legacy::List<SpellSetTierList>::flush((AC1Legacy::List<SpellSetTierList> *)v3);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E485C: using guessed type int (__thiscall *AC1Legacy::List<SpellSetTierList>::vftable[2])(void *, char);
// 7E4890: using guessed type void *PList<SpellSetTierList>::vftable;

//----- (00598060) --------------------------------------------------------  // acclient.c:450106
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *v1; // edi@1
  int v2; // ecx@2
  HashTableData<unsigned long,SpellSet> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,SpellSet> **v5; // edx@5
  HashTableData<unsigned long,SpellSet> *v6; // esi@5
  HashTableData<unsigned long,SpellSet> *v7; // eax@7
  HashTableData<unsigned long,SpellSet> *v8; // ecx@8
  int v9; // ecx@13

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,SpellSet> **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,SpellSet> **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_17;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_17:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      v9 = (int)&v6->m_data.m_countTiers;
      *(_DWORD *)(v9 + 16) = &PList<SpellSetTierList>::vftable;
      *(_DWORD *)(v9 + 16) = &PackObj::vftable;
      *(_DWORD *)v9 = AC1Legacy::List<SpellSetTierList>::vftable;
      AC1Legacy::List<SpellSetTierList>::flush((AC1Legacy::List<SpellSetTierList> *)&v6->m_data.m_countTiers.vfptr);
      v6->m_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
      operator delete(v6);
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E485C: using guessed type int (__thiscall *AC1Legacy::List<SpellSetTierList>::vftable[2])(void *, char);
// 7E4890: using guessed type void *PList<SpellSetTierList>::vftable;

//----- (00598100) --------------------------------------------------------  // acclient.c:450175
HashTable<unsigned long,SpellSet,0> *__thiscall HashTable<unsigned long,SpellSet,0>::vector_deleting_destructor(HashTable<unsigned long,SpellSet,0> *this, unsigned int a2)
{
  HashTable<unsigned long,SpellSet,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,SpellSet,0>Vtbl *)&HashTable<unsigned long,SpellSet,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::vftable;
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
// 7E4874: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::vftable[2])(void *, char);
// 7E488C: using guessed type int (__thiscall *HashTable<unsigned long,SpellSet,0>::vftable)(void *, char);

//----- (00598160) --------------------------------------------------------  // acclient.c:450201
PHashTable<unsigned long,SpellSet> *__thiscall PHashTable<unsigned long,SpellSet>::vector_deleting_destructor(PHashTable<unsigned long,SpellSet> *this, unsigned int a2)
{
  return PHashTable<unsigned long,SpellSet>::vector_deleting_destructor(
           (PHashTable<unsigned long,SpellSet> *)((char *)this - 116),
           a2);
}

//----- (00598170) --------------------------------------------------------  // acclient.c:450209
int __thiscall PHashTable<unsigned long,SpellSet>::StreamPack(PHashTable<unsigned long,SpellSet> *this, STREAMTYPE op, void **addr, unsigned int *size)
{
  STREAMTYPE v4; // esi@1
  PHashTable<unsigned long,SpellSet> *v5; // edi@1
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
  HashIterator<unsigned long,SpellSet,0> iter; // [sp+14h] [bp-24h]@4
  HashIterator<unsigned long,SpellSet,0> v24; // [sp+20h] [bp-18h]@4
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+2Ch] [bp-Ch]@4

  v4 = op;
  v5 = this;
  if ( op == 2 )
  {
    v13 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)this[-1].m_intrusiveTable.m_aInplaceBuckets;
    v22 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)this[-1].m_intrusiveTable.m_aInplaceBuckets;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *)((char *)&this[-1].m_intrusiveTable + 4));
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
        v19 = operator new(0x20u);
        v20 = v19;
        if ( v19 )
        {
          *((_DWORD *)v19 + 1) = 0;
          SpellSet::SpellSet((SpellSet *)((char *)v19 + 8));
        }
        else
        {
          v20 = 0;
        }
        if ( !STREAMPACK(STREAM_UNPACK, (unsigned int *)v20, addr, size)
          || !STREAMPACK(STREAM_UNPACK, (SpellSet *)((char *)v20 + 8), addr, size) )
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
        for ( iter = v24;
              ;
              IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::operator++(&iter.m_iter) )
        {
          v12 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::end(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *)v10,
                  (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *)&result);
          HashIterator<unsigned long,SpellSet,0>::HashIterator<unsigned long,SpellSet,0>(&v24, v12);
          if ( iter.m_iter.m_currElement == v24.m_iter.m_currElement )
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

//----- (00598370) --------------------------------------------------------  // acclient.c:450319
int __cdecl STREAMPACK(STREAMTYPE op, SpellSet *obj, void **addr, unsigned int *size)
{
  int result; // eax@4
  void *v5; // esi@5

  if ( op )
  {
    if ( op == 1 )
    {
      *size -= ((int (__stdcall *)(void **, unsigned int))obj->vfptr->Pack)(addr, *size);
      result = 1;
    }
    else if ( op == 2 )
    {
      v5 = *addr;
      result = ((int (__stdcall *)(void **, unsigned int))obj->vfptr->UnPack)(addr, *size);
      *size += (_BYTE *)v5 - (_BYTE *)*addr;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    *size -= ((int (*)(void))obj->vfptr->GetPackSize)();
    result = 1;
  }
  return result;
}

//----- (005983E0) --------------------------------------------------------  // acclient.c:450351
PHashTable<unsigned long,SpellSet> *__thiscall PHashTable<unsigned long,SpellSet>::vector_deleting_destructor(PHashTable<unsigned long,SpellSet> *this, unsigned int a2)
{
  PHashTable<unsigned long,SpellSet> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PHashTable<unsigned long,SpellSet>::vftable;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (HashTable<unsigned long,SpellSet,0>Vtbl *)&HashTable<unsigned long,SpellSet,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::vftable;
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
// 7E4874: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::vftable[2])(void *, char);
// 7E488C: using guessed type int (__thiscall *HashTable<unsigned long,SpellSet,0>::vftable)(void *, char);
// 7E48BC: using guessed type void *PHashTable<unsigned long,SpellSet>::vftable;

//----- (00598440) --------------------------------------------------------  // acclient.c:450381
void __thiscall CSpellTable::CSpellTable(CSpellTable *this, IDClass<_tagDataID,32,0> did)
{
  CSpellTable *v2; // esi@1
  int v3; // ecx@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, did);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v3 = (int)&v2->_spellBaseHash;
  v2->vfptr = (InterfaceVtbl *)&CSpellTable::vftable;
  v2->vfptr = (PackObjVtbl *)&CSpellTable::vftable;
  *(_DWORD *)v3 = &PackableHashTable<unsigned long,CSpellBase>::vftable;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 0x2000;
  *(_DWORD *)(v3 + 16) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&v2->_spellBaseHash);
  v2->m_SpellSetHash.vfptr = (HashTable<unsigned long,SpellSet,0>Vtbl *)&HashTable<unsigned long,SpellSet,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>(
    &v2->m_SpellSetHash.m_intrusiveTable,
    0x17u);
  v2->m_SpellSetHash.vfptr = (PackObjVtbl *)&StreamPackObj::vftable;
  v2->m_SpellSetHash.vfptr = (HashTable<unsigned long,SpellSet,0>Vtbl *)&PHashTable<unsigned long,SpellSet>::vftable;
  v2->m_SpellSetHash.vfptr = (PackObjVtbl *)&PHashTable<unsigned long,SpellSet>::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C9DC0: using guessed type int (__thiscall *StreamPackObj::vftable)(void *, char);
// 7E4860: using guessed type int (__thiscall *PackableHashTable<unsigned long,CSpellBase>::vftable)(void *, char);
// 7E488C: using guessed type int (__thiscall *HashTable<unsigned long,SpellSet,0>::vftable)(void *, char);
// 7E48BC: using guessed type void *PHashTable<unsigned long,SpellSet>::vftable;
// 7E48D4: using guessed type int (__thiscall *PHashTable<unsigned long,SpellSet>::vftable)(void *, char);
// 7E48D8: using guessed type void *CSpellTable::vftable;
// 7E48F0: using guessed type __int32 (__stdcall *CSpellTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005984C0) --------------------------------------------------------  // acclient.c:450416
CSpellTable *__thiscall CSpellTable::vector_deleting_destructor(CSpellTable *this, unsigned int a2)
{
  return CSpellTable::vector_deleting_destructor((CSpellTable *)((char *)this - 48), a2);
}

//----- (005984D0) --------------------------------------------------------  // acclient.c:450422
CSpellTable *__thiscall CSpellTable::vector_deleting_destructor(CSpellTable *this, unsigned int a2)
{
  CSpellTable *v2; // esi@1

  v2 = this;
  CSpellTable::~CSpellTable(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005984F0) --------------------------------------------------------  // acclient.c:450434
void __thiscall CSpellTable::~CSpellTable(CSpellTable *this)
{
  CSpellTable *v1; // edi@1
  char *v2; // esi@1
  void *v3; // eax@1

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&CSpellTable::vftable;
  this->vfptr = (PackObjVtbl *)&CSpellTable::vftable;
  this->m_SpellSetHash.vfptr = (PackObjVtbl *)&PHashTable<unsigned long,SpellSet>::vftable;
  v2 = (char *)&this->m_SpellSetHash.m_intrusiveTable;
  this->m_SpellSetHash.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->m_SpellSetHash.vfptr = (HashTable<unsigned long,SpellSet,0>Vtbl *)&HashTable<unsigned long,SpellSet,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::delete_contents(&this->m_SpellSetHash.m_intrusiveTable);
  v3 = (void *)*((_DWORD *)v2 + 24);
  *(_DWORD *)v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::vftable;
  if ( v3 != v2 + 4 )
    operator delete[](v3);
  *((_DWORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 25) = 0;
  *((_DWORD *)v2 + 26) = 0;
  *((_DWORD *)v2 + 27) = 0;
  v1->_spellBaseHash.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,CSpellBase>::vftable;
  PackableHashTable<unsigned long,CSpellBase>::EmptyContents(&v1->_spellBaseHash);
  if ( v1->_spellBaseHash._buckets )
  {
    operator delete[](v1->_spellBaseHash._buckets);
    v1->_spellBaseHash._buckets = 0;
  }
  v1->_spellBaseHash._table_size = 0;
  v1->_spellBaseHash.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4860: using guessed type int (__thiscall *PackableHashTable<unsigned long,CSpellBase>::vftable)(void *, char);
// 7E4874: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::vftable[2])(void *, char);
// 7E488C: using guessed type int (__thiscall *HashTable<unsigned long,SpellSet,0>::vftable)(void *, char);
// 7E48BC: using guessed type void *PHashTable<unsigned long,SpellSet>::vftable;
// 7E48D8: using guessed type void *CSpellTable::vftable;
// 7E48F0: using guessed type __int32 (__stdcall *CSpellTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006B3000) --------------------------------------------------------  // acclient.c:716717
void __thiscall HashIterator<unsigned long,SpellSet,0>::HashIterator<unsigned long,SpellSet,0>(HashIterator<unsigned long,SpellSet,0> *this, IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *_intrusiveIter)
{
  *this = (HashIterator<unsigned long,SpellSet,0>)*_intrusiveIter;
}

//----- (006B3020) --------------------------------------------------------  // acclient.c:716723
IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::end(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *this, IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *result)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *v2; // eax@1

  v2 = result;
  result->m_currHashTable = this;
  result->m_currBucket = 0;
  result->m_currElement = 0;
  return v2;
}

//----- (0070AD50) --------------------------------------------------------  // acclient.c:798038
int sub_70AD50()
{
  return atexit(nullsub_1425);
}

