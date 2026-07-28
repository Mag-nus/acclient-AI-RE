/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ComponentTracker
   Object     : AC\accui_gameplay\ComponentTracker.obj
   Functions  : 38
   Addresses  : 0042D780 - 00709C50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0042D780) --------------------------------------------------------  // acclient.c:106702
char __thiscall HashTable<unsigned long,unsigned long,0>::set(HashTable<unsigned long,unsigned long,0> *this, const unsigned int *_key, const unsigned int *_data)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *v3; // esi@1
  HashTableData<unsigned long,unsigned long> *v4; // eax@1
  void *v5; // eax@4
  char result; // al@5

  v3 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable;
  v4 = this->m_intrusiveTable.m_buckets[*_key % this->m_intrusiveTable.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != *_key )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    v4->m_data = *_data;
    result = 1;
  }
  else
  {
LABEL_4:
    v5 = operator new(0xCu);
    if ( v5 )
    {
      *(_DWORD *)v5 = *_key;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = *_data;
      IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
        v3,
        (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v5);
      result = 1;
    }
    else
    {
      IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
        v3,
        0);
      result = 1;
    }
  }
  return result;
}

//----- (00585EA0) --------------------------------------------------------  // acclient.c:430850
IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *__thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::scalar_deleting_destructor(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *v2; // esi@1
  HashSetData<IDClass<_tagDataID,32,0> > **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::vftable;
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
// 7E1EF4: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::vftable[2])(void *, char);

//----- (00585F30) --------------------------------------------------------  // acclient.c:430890
unsigned int __thiscall ComponentData::GetFirstObjectID(ComponentData *this)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+0h] [bp-Ch]@1

  return IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->objects.m_intrusiveTable,
           &result)->m_currElement->m_hashKey;
}

//----- (00585F50) --------------------------------------------------------  // acclient.c:430900
signed int __thiscall ComponentTracker::DetermineComponentCategory(ComponentTracker *this, IDClass<_tagDataID,32,0> wcid)
{
  SpellComponentTable **v2; // esi@1
  const unsigned int v3; // edi@1
  signed int result; // eax@2
  SpellComponentCategory v5; // esi@3
  SpellComponentBase sc_base; // [sp+Ch] [bp-24h]@1

  v2 = (SpellComponentTable **)this;
  v3 = SpellComponentTable::WCIDtoSCID(wcid);
  sc_base._name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  sc_base.vfptr = (PackObjVtbl *)&SpellComponentBase::vftable;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  sc_base._text.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  SpellComponentBase::Init(&sc_base);
  if ( SpellComponentTable::InqSpellComponentBase(*v2, v3, &sc_base) )
  {
    v5 = sc_base._category;
    SpellComponentBase::~SpellComponentBase(&sc_base);
    result = v5;
  }
  else
  {
    SpellComponentBase::~SpellComponentBase(&sc_base);
    result = 8;
  }
  return result;
}
// 7A33CC: using guessed type int (__thiscall *SpellComponentBase::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00585FE0) --------------------------------------------------------  // acclient.c:430933
void __thiscall ComponentTracker::GetNumComponent(ComponentTracker *this, IDClass<_tagDataID,32,0> wcid, int *num)
{
  SpellComponentTable **v3; // esi@1
  const unsigned int v4; // edi@1
  InterfaceVtbl *v5; // eax@1
  SpellComponentBase spellComponentBase; // [sp+10h] [bp-24h]@1

  v3 = (SpellComponentTable **)this;
  v4 = SpellComponentTable::WCIDtoSCID(wcid);
  spellComponentBase._name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  spellComponentBase.vfptr = (PackObjVtbl *)&SpellComponentBase::vftable;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  spellComponentBase._text.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  SpellComponentBase::Init(&spellComponentBase);
  SpellComponentTable::InqSpellComponentBase(*v3, v4, &spellComponentBase);
  v5 = v3[spellComponentBase._category + 1]->vfptr;
  if ( v5 )
  {
    while ( v5->IUnknown_Release != (unsigned int (__stdcall *)(Interface *))wcid.id )
    {
      v5 = (InterfaceVtbl *)v5->IUnknown_QueryInterface;
      if ( !v5 )
        goto LABEL_4;
    }
    *num = (int)v5[5].AddRef;
    SpellComponentBase::~SpellComponentBase(&spellComponentBase);
  }
  else
  {
LABEL_4:
    *num = 0;
    SpellComponentBase::~SpellComponentBase(&spellComponentBase);
  }
}
// 7A33CC: using guessed type int (__thiscall *SpellComponentBase::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00586090) --------------------------------------------------------  // acclient.c:430972
void __thiscall ComponentTracker::GetCompNameFromWCID(ComponentTracker *this, IDClass<_tagDataID,32,0> wcid, AC1Legacy::PStringBase<char> *name)
{
  SpellComponentTable **v3; // esi@1
  const unsigned int v4; // ebx@1
  AC1Legacy::PStringBase<char> *v5; // eax@1
  AC1Legacy::PStringBase<char> *v6; // ebp@1
  AC1Legacy::PSRefBuffer<char> *v7; // esi@1
  AC1Legacy::PStringBase<char> *v8; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v9; // ebx@5
  unsigned int v10; // esi@6
  AC1Legacy::PSRefBuffer<char> *v11; // esi@9
  AC1Legacy::PSRefBuffer<char> *v12; // esi@12
  SpellComponentBase spellComponentBase; // [sp+10h] [bp-24h]@1

  v3 = (SpellComponentTable **)this;
  v4 = SpellComponentTable::WCIDtoSCID(wcid);
  spellComponentBase._name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  spellComponentBase.vfptr = (PackObjVtbl *)&SpellComponentBase::vftable;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  spellComponentBase._text.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  SpellComponentBase::Init(&spellComponentBase);
  SpellComponentTable::InqSpellComponentBase(*v3, v4, &spellComponentBase);
  v5 = SpellComponentBase::InqName(&spellComponentBase, (AC1Legacy::PStringBase<char> *)&wcid);
  v6 = name;
  v7 = name->m_buffer;
  v8 = v5;
  if ( name->m_buffer != v5->m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) && v7 )
      v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
    v9 = v8->m_buffer;
    v6->m_buffer = v9;
    InterlockedIncrement((volatile LONG *)&v9->m_cRef);
  }
  v10 = wcid.id;
  if ( !InterlockedDecrement((volatile LONG *)(wcid.id + 4)) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  v11 = spellComponentBase._text.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&spellComponentBase._text.m_buffer->m_cRef) && v11 )
    v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
  v12 = spellComponentBase._name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&spellComponentBase._name.m_buffer->m_cRef) )
  {
    if ( v12 )
      v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
  }
}
// 7A33CC: using guessed type int (__thiscall *SpellComponentBase::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00586190) --------------------------------------------------------  // acclient.c:431024
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::grow(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::resize_internal(
           v2,
           *v3);
}

//----- (005861E0) --------------------------------------------------------  // acclient.c:431044
int __thiscall ComponentTracker::ObjectIsOwnedComponent(ComponentTracker *this, unsigned int _objectID, IDClass<_tagDataID,32,0> *_classID)
{
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *v3; // eax@1
  int result; // eax@4

  v3 = this->objectIDHash.m_intrusiveTable.m_buckets[_objectID % this->objectIDHash.m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != _objectID )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    _classID->id = v3->m_data.id;
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00586230) --------------------------------------------------------  // acclient.c:431072
void __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashSetData<IDClass<_tagDataID,32,0> > **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashSetData<IDClass<_tagDataID,32,0> > **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7E1EF4: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::vftable[2])(void *, char);

//----- (00586340) --------------------------------------------------------  // acclient.c:431162
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::resize_internal(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *v3; // esi@1
  char result; // al@2
  HashSetData<IDClass<_tagDataID,32,0> > *v5; // edi@3
  int v6; // ecx@4
  HashSetData<IDClass<_tagDataID,32,0> > **v7; // eax@5
  int v8; // eax@6
  HashSetData<IDClass<_tagDataID,32,0> > **v9; // ebx@7
  HashSetData<IDClass<_tagDataID,32,0> > *v10; // ecx@7
  HashSetData<IDClass<_tagDataID,32,0> > *v11; // eax@9
  HashSetData<IDClass<_tagDataID,32,0> > *v12; // edx@10
  HashSetData<IDClass<_tagDataID,32,0> > *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  HashSetData<IDClass<_tagDataID,32,0> > **v17; // eax@23
  int v18; // eax@23

  v2 = _numBuckets;
  v3 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v6 = (int)&v3->m_buckets[v3->m_numBuckets];
        if ( v3->m_firstInterestingBucket == (HashSetData<IDClass<_tagDataID,32,0> > **)v6 )
        {
LABEL_7:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v3->m_firstInterestingBucket;
            if ( *v7 )
              break;
            v8 = (int)(v7 + 1);
            v3->m_firstInterestingBucket = (HashSetData<IDClass<_tagDataID,32,0> > **)v8;
            if ( v8 == v6 )
              goto LABEL_7;
          }
          v10 = *v3->m_firstInterestingBucket;
          v9 = v3->m_firstInterestingBucket;
        }
        v11 = *v9;
        if ( *v9 == v10 )
          goto LABEL_29;
        do
        {
          v12 = v11;
          v11 = v11->m_hashNext;
        }
        while ( v11 != v10 );
        if ( v12 )
          v12->m_hashNext = v11->m_hashNext;
        else
LABEL_29:
          *v9 = v11->m_hashNext;
        --v3->m_numElements;
        v10->m_hashNext = v5;
        v5 = v10;
      }
      while ( v3->m_numElements );
    }
    if ( (HashSetData<IDClass<_tagDataID,32,0> > **)v3->m_buckets != v3->m_aInplaceBuckets )
      operator delete[](v3->m_buckets);
    v3->m_buckets = 0;
    v3->m_firstInterestingBucket = 0;
    v3->m_numBuckets = 0;
    v3->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v3,
      v2);
    if ( v5 )
    {
      do
      {
        v13 = v5->m_hashNext;
        if ( (signed int)(2 * v3->m_numBuckets) < (signed int)(v3->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v3->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::resize_internal(
            v3,
            *v15);
        }
        v16 = v5->m_hashKey.id % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashSetData<IDClass<_tagDataID,32,0> > **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashSetData<IDClass<_tagDataID,32,0> > **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (00586480) --------------------------------------------------------  // acclient.c:431280
BOOL __thiscall ComponentTracker::ComponentIsOwned(ComponentTracker *this, IDClass<_tagDataID,32,0> _classID)
{
  HashSetData<IDClass<_tagDataID,32,0> > *v2; // eax@1
  bool v3; // zf@1

  v2 = this->classIDHash.m_intrusiveTable.m_buckets[_classID.id % this->classIDHash.m_intrusiveTable.m_numBuckets];
  v3 = v2 == 0;
  if ( v2 )
  {
    do
    {
      if ( v2->m_hashKey.id == _classID.id )
        break;
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    v3 = v2 == 0;
  }
  return !v3;
}

//----- (005864C0) --------------------------------------------------------  // acclient.c:431302
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::add(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *this, HashSetData<IDClass<_tagDataID,32,0> > *data)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashSetData<IDClass<_tagDataID,32,0> > *v4; // eax@1
  unsigned int v5; // edx@6
  HashSetData<IDClass<_tagDataID,32,0> > **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey.id % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.id != data->m_hashKey.id )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::grow(this);
    v5 = data->m_hashKey.id % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashSetData<IDClass<_tagDataID,32,0> > **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashSetData<IDClass<_tagDataID,32,0> > **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (00586540) --------------------------------------------------------  // acclient.c:431346
char __thiscall HashSet<IDClass<_tagDataID,32,0>>::add(HashSet<IDClass<_tagDataID,32,0> > *this, IDClass<_tagDataID,32,0> *_key)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *v2; // esi@1
  HashSetData<IDClass<_tagDataID,32,0> > *v3; // eax@1
  void *v4; // eax@4
  char result; // al@5

  v2 = &this->m_intrusiveTable;
  v3 = this->m_intrusiveTable.m_buckets[_key->id % this->m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.id != _key->id )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    v4 = operator new(8u);
    if ( v4 )
    {
      *(_DWORD *)v4 = _key->id;
      *((_DWORD *)v4 + 1) = 0;
      IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::add(
        v2,
        (HashSetData<IDClass<_tagDataID,32,0> > *)v4);
      result = 1;
    }
    else
    {
      IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::add(v2, 0);
      result = 1;
    }
  }
  return result;
}

//----- (005865B0) --------------------------------------------------------  // acclient.c:431390
HashSet<IDClass<_tagDataID,32,0> > *__thiscall HashSet<IDClass<_tagDataID,32,0>>::scalar_deleting_destructor(HashSet<IDClass<_tagDataID,32,0> > *this, unsigned int a2)
{
  HashSet<IDClass<_tagDataID,32,0> > *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashSet<IDClass<_tagDataID,32,0> >Vtbl *)&HashSet<IDClass<_tagDataID,32,0>>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::vftable;
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
// 7E1EF4: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::vftable[2])(void *, char);
// 7E1EF8: using guessed type int (__thiscall *HashSet<IDClass<_tagDataID,32,0>>::vftable)(void *, char);

//----- (00586610) --------------------------------------------------------  // acclient.c:431416
void __thiscall ComponentData::AddItem(ComponentData *this, ACCWeenieObject *_weenObj)
{
  ACCWeenieObject *v2; // edi@1
  ComponentData *v3; // esi@1
  unsigned int v4; // edi@3
  unsigned int _key; // [sp+0h] [bp-4h]@1

  _key = (unsigned int)this;
  v2 = _weenObj;
  v3 = this;
  _weenObj = (ACCWeenieObject *)_weenObj->pwd._stackSize;
  if ( !_weenObj )
    _weenObj = (ACCWeenieObject *)1;
  _key = v2->id;
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&this->objects,
    &_key,
    (RenderVertexStreamD3D *const *)&_weenObj);
  v4 = v2->pwd._stackSize;
  if ( v4 )
    v3->numItems += v4;
  else
    ++v3->numItems;
}

//----- (00586680) --------------------------------------------------------  // acclient.c:431442
void __thiscall ComponentData::RemoveItem(ComponentData *this, ACCWeenieObject *_weenObj)
{
  ACCWeenieObject *v2; // edi@1
  ComponentData *v3; // esi@1
  HashSetData<IDClass<_tagDataID,32,0> > *v4; // eax@1
  signed int v5; // eax@3

  v2 = _weenObj;
  v3 = this;
  _weenObj = (ACCWeenieObject *)_weenObj->id;
  v4 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->objects.m_intrusiveTable,
         (IDClass<_tagDataID,32,0> *)&_weenObj);
  if ( v4 )
    operator delete(v4);
  v5 = v2->pwd._stackSize;
  if ( !v5 )
    v5 = 1;
  v3->numItems -= v5;
}

//----- (005866D0) --------------------------------------------------------  // acclient.c:431464
void __thiscall ComponentData::UpdateStackSize(ComponentData *this, ACCWeenieObject *_weenObj, ComponentTrackerUpdate *_change)
{
  ACCWeenieObject *v3; // edi@1
  HashTableData<unsigned long,unsigned long> *v4; // eax@1
  ComponentTrackerUpdate *v5; // esi@4
  unsigned int v6; // edx@5
  char *v7; // ecx@11

  v3 = _weenObj;
  v4 = this->objects.m_intrusiveTable.m_buckets[_weenObj->id % this->objects.m_intrusiveTable.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != _weenObj->id )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
    v5 = (ComponentTrackerUpdate *)v4->m_data;
  else
LABEL_4:
    v5 = _change;
  v6 = _weenObj->pwd._stackSize;
  if ( !v6 )
    v6 = 1;
  _weenObj = (ACCWeenieObject *)v6;
  if ( v5 == (ComponentTrackerUpdate *)v6 )
  {
    *_change = 0;
  }
  else
  {
    v7 = (char *)&this->objects;
    *_change = ((unsigned int)v5 > v6) + 1;
    *((_DWORD *)v7 + 29) += v6 - (_DWORD)v5;
    _change = (ComponentTrackerUpdate *)v3->id;
    HashTable<unsigned long,unsigned long,0>::set(
      (HashTable<unsigned long,unsigned long,0> *)v7,
      (const unsigned int *)&_change,
      (const unsigned int *)&_weenObj);
  }
}

//----- (00586770) --------------------------------------------------------  // acclient.c:431509
void __thiscall ComponentTracker::ComponentTracker(ComponentTracker *this, SpellComponentTable *_spellComponentTable)
{
  ComponentTracker *v2; // esi@1
  int v3; // edi@1
  signed int v4; // ebx@1
  void *v5; // eax@2

  v2 = this;
  this->spellComponentTable = _spellComponentTable;
  this->objectIDHash.vfptr = (HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>Vtbl *)&HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>(
    &this->objectIDHash.m_intrusiveTable,
    0x20u);
  v2->classIDHash.vfptr = (HashSet<IDClass<_tagDataID,32,0> >Vtbl *)&HashSet<IDClass<_tagDataID,32,0>>::vftable;
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>(
    &v2->classIDHash.m_intrusiveTable,
    0x20u);
  v3 = (int)v2->componentLists;
  v4 = 7;
  do
  {
    v5 = operator new(8u);
    if ( v5 )
    {
      *(_DWORD *)v5 = 0;
      *((_DWORD *)v5 + 1) = 0;
    }
    else
    {
      v5 = 0;
    }
    *(_DWORD *)v3 = v5;
    v3 += 4;
    --v4;
  }
  while ( v4 );
}
// 7952A0: using guessed type int (__thiscall *HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::vftable)(void *, char);
// 7E1EF8: using guessed type int (__thiscall *HashSet<IDClass<_tagDataID,32,0>>::vftable)(void *, char);

//----- (005867E0) --------------------------------------------------------  // acclient.c:431550
void __thiscall ComponentTracker::UpdateComponentStackSize(ComponentTracker *this, ACCWeenieObject *_weenObj, ComponentTrackerUpdate *_change)
{
  DLListData *v3; // ecx@1

  v3 = this->componentLists[ComponentTracker::DetermineComponentCategory(this, _weenObj->pwd._wcid)]->head_;
  if ( v3 )
  {
    while ( v3[1].dllist_next != (DLListData *)_weenObj->pwd._wcid.id )
    {
      v3 = v3->dllist_next;
      if ( !v3 )
        return;
    }
    ComponentData::UpdateStackSize((ComponentData *)v3, _weenObj, _change);
  }
}

//----- (00586830) --------------------------------------------------------  // acclient.c:431568
void __thiscall ComponentData::ComponentData(ComponentData *this, ACCWeenieObject *_weenObj)
{
  ComponentData *v2; // esi@1
  volatile LONG *v3; // ST04_4@1
  ACCWeenieObject *v4; // edi@1
  AC1Legacy::PSRefBuffer<char> *v5; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v6; // ebp@1
  unsigned int v7; // edi@11
  unsigned int _key; // [sp+10h] [bp-4h]@11

  v2 = this;
  this->dllist_next = 0;
  this->dllist_prev = 0;
  this->classID.id = stru_870A74.id;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->componentName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v2->componentIconID.id = stru_870A74.id;
  v2->objects.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>(
    &v2->objects.m_intrusiveTable,
    4u);
  v2->numItems = 0;
  v4 = _weenObj;
  v2->classID.id = _weenObj->pwd._wcid.id;
  v2->componentIconID.id = *(_DWORD *)v4->vfptr[25].__vecDelDtor(
                                        (HashBaseData<unsigned long> *)v4,
                                        (unsigned int)&_weenObj);
  v5 = v4->pwd._name.m_buffer;
  InterlockedIncrement((volatile LONG *)&v5->m_cRef);
  v6 = v2->componentName.m_buffer;
  if ( v6 != v5 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    v2->componentName.m_buffer = v5;
    InterlockedIncrement((volatile LONG *)&v5->m_cRef);
  }
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
    v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  _weenObj = (ACCWeenieObject *)v4->pwd._stackSize;
  if ( !_weenObj )
    _weenObj = (ACCWeenieObject *)1;
  _key = v4->id;
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&v2->objects,
    &_key,
    (RenderVertexStreamD3D *const *)&_weenObj);
  v7 = v4->pwd._stackSize;
  if ( v7 )
    v2->numItems += v7;
  else
    ++v2->numItems;
}
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00586960) --------------------------------------------------------  // acclient.c:431626
void __thiscall ComponentData::~ComponentData(ComponentData *this)
{
  ComponentData *v1; // edi@1
  char *v2; // esi@1
  void *v3; // eax@1
  AC1Legacy::PSRefBuffer<char> *v4; // edi@3

  v1 = this;
  v2 = (char *)&this->objects.m_intrusiveTable;
  this->objects.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->objects.m_intrusiveTable);
  v3 = (void *)*((_DWORD *)v2 + 24);
  *(_DWORD *)v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable;
  if ( v3 != v2 + 4 )
    operator delete[](v3);
  *((_DWORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 25) = 0;
  *((_DWORD *)v2 + 26) = 0;
  *((_DWORD *)v2 + 27) = 0;
  v4 = v1->componentName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
  {
    if ( v4 )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  }
}
// 79C9A8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable[3])(void *, char);
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);

//----- (005869C0) --------------------------------------------------------  // acclient.c:431656
void __thiscall ComponentTracker::InsertNewComponentData(ComponentTracker *this, ACCWeenieObject *_weenObj, DLList<ComponentData> *_list, ComponentData *_after)
{
  ComponentTracker *v4; // edi@1
  ComponentData *v5; // eax@1
  ACCWeenieObject *v6; // esi@1
  DLListData *v7; // eax@2

  v4 = this;
  v5 = (ComponentData *)operator new(0x8Cu);
  v6 = _weenObj;
  if ( v5 )
    ComponentData::ComponentData(v5, _weenObj);
  else
    v7 = 0;
  DLListBase::InsertAfter((DLListBase *)&_list->head_, v7, (DLListData *)&_after->dllist_next);
  _weenObj = (ACCWeenieObject *)v6->pwd._wcid.id;
  HashSet<IDClass<_tagDataID,32,0>>::add(&v4->classIDHash, (IDClass<_tagDataID,32,0> *)&_weenObj);
}

//----- (00586A20) --------------------------------------------------------  // acclient.c:431676
void __thiscall ComponentTracker::AddComponent(ComponentTracker *this, ACCWeenieObject *_weenObj)
{
  ACCWeenieObject *v2; // esi@1
  ComponentTracker *v3; // edi@1
  unsigned int v4; // ecx@1
  DLList<ComponentData> *v5; // eax@1
  DLListData *v6; // ebp@1
  bool v7; // zf@1
  AC1Legacy::PSRefBuffer<char> *v8; // edi@2
  int v9; // esi@2
  ComponentData *prevNode; // [sp+10h] [bp-Ch]@1
  DLList<ComponentData> *list; // [sp+14h] [bp-8h]@1
  ComponentTracker *v12; // [sp+18h] [bp-4h]@1

  v2 = _weenObj;
  v3 = this;
  v4 = _weenObj->pwd._wcid.id;
  prevNode = (ComponentData *)_weenObj->id;
  list = (DLList<ComponentData> *)v4;
  v12 = v3;
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&v3->objectIDHash,
    (const unsigned int *)&prevNode,
    (RenderVertexStreamD3D *const *)&list);
  v5 = v3->componentLists[ComponentTracker::DetermineComponentCategory(v3, _weenObj->pwd._wcid)];
  v6 = v5->head_;
  v7 = v5->head_ == 0;
  list = v5;
  prevNode = 0;
  if ( v7 )
  {
LABEL_9:
    ComponentTracker::InsertNewComponentData(v3, v2, v5, prevNode);
  }
  else
  {
    while ( 1 )
    {
      v8 = v2->pwd._name.m_buffer;
      InterlockedIncrement((volatile LONG *)&v8->m_cRef);
      v9 = strcmp(v8->m_data, (const char *)&v6[1].dllist_prev[2].dllist_prev);
      if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) )
      {
        if ( v8 )
          v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
      }
      if ( !v9 )
      {
        ComponentData::AddItem((ComponentData *)v6, _weenObj);
        return;
      }
      if ( v9 < 0 )
        break;
      v2 = _weenObj;
      prevNode = (ComponentData *)v6;
      v6 = v6->dllist_next;
      if ( !v6 )
      {
        v3 = v12;
        v5 = list;
        goto LABEL_9;
      }
    }
    ComponentTracker::InsertNewComponentData(v12, _weenObj, list, prevNode);
  }
}

//----- (00586B50) --------------------------------------------------------  // acclient.c:431744
void __thiscall ComponentTracker::RemoveComponent(ComponentTracker *this, ACCWeenieObject *_weenObj)
{
  ACCWeenieObject *v2; // ebx@1
  ComponentTracker *v3; // edi@1
  HashSetData<IDClass<_tagDataID,32,0> > *v4; // eax@1
  DLListBase *v5; // ebp@3
  DLListData *v6; // esi@3
  HashSetData<IDClass<_tagDataID,32,0> > *v7; // eax@8

  v2 = _weenObj;
  v3 = this;
  _weenObj = (ACCWeenieObject *)_weenObj->id;
  v4 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->objectIDHash.m_intrusiveTable,
         (IDClass<_tagDataID,32,0> *)&_weenObj);
  if ( v4 )
    operator delete(v4);
  v5 = (DLListBase *)&v3->componentLists[ComponentTracker::DetermineComponentCategory(v3, v2->pwd._wcid)]->head_;
  v6 = v5->head_;
  if ( v5->head_ )
  {
    while ( v6[1].dllist_next != (DLListData *)v2->pwd._wcid.id )
    {
      v6 = v6->dllist_next;
      if ( !v6 )
        return;
    }
    ComponentData::RemoveItem((ComponentData *)v6, v2);
    if ( !v6[17].dllist_next )
    {
      _weenObj = (ACCWeenieObject *)v6[1].dllist_next;
      v7 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
             &v3->classIDHash.m_intrusiveTable,
             (IDClass<_tagDataID,32,0> *)&_weenObj);
      if ( v7 )
        operator delete(v7);
      DLListBase::Remove(v5, v6);
      ComponentData::~ComponentData((ComponentData *)v6);
      operator delete(v6);
    }
  }
}

//----- (00586C10) --------------------------------------------------------  // acclient.c:431788
void __thiscall ComponentTracker::~ComponentTracker(ComponentTracker *this)
{
  ComponentTracker *v1; // esi@1
  void **v2; // ebp@1
  void *v3; // ecx@2
  void *v4; // edi@2
  int v5; // eax@3
  int v6; // eax@5
  bool v7; // zf@5
  int v8; // eax@9
  void *v9; // eax@13
  int v10; // esi@15
  void *v11; // edx@19
  void *v12; // eax@19
  int v13; // ecx@20
  int v14; // ecx@22
  int v15; // ecx@26
  int v16; // esi@34
  void *v17; // eax@34
  void *v18; // eax@36
  signed int v19; // [sp+Ch] [bp-8h]@1
  ComponentTracker *v20; // [sp+10h] [bp-4h]@1

  v1 = this;
  v20 = this;
  v2 = (void **)this->componentLists;
  v19 = 7;
  do
  {
    v3 = *v2;
    v4 = *(void **)*v2;
    if ( v4 )
    {
      v5 = *((_DWORD *)v4 + 1);
      if ( v5 )
      {
        *(_DWORD *)v5 = *(_DWORD *)v4;
      }
      else
      {
        v6 = *(_DWORD *)v4;
        v7 = *(_DWORD *)v4 == 0;
        *(_DWORD *)v3 = *(_DWORD *)v4;
        if ( !v7 )
          *(_DWORD *)(v6 + 4) = 0;
      }
      if ( *(_DWORD *)v4 )
      {
        *(_DWORD *)(*(_DWORD *)v4 + 4) = *((_DWORD *)v4 + 1);
      }
      else
      {
        v8 = *(_DWORD *)(*((_DWORD *)v3 + 1) + 4);
        *((_DWORD *)v3 + 1) = v8;
        if ( v8 )
          *(_DWORD *)v8 = 0;
      }
      *(_DWORD *)v4 = 0;
      *((_DWORD *)v4 + 1) = 0;
      if ( v4 )
      {
        do
        {
          if ( v4 )
          {
            *((_DWORD *)v4 + 5) = HashTable<unsigned long,unsigned long,0>::vftable;
            IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)((char *)v4 + 24));
            v9 = (void *)*((_DWORD *)v4 + 30);
            *((_DWORD *)v4 + 6) = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable;
            if ( v9 != (char *)v4 + 28 )
              operator delete[](v9);
            *((_DWORD *)v4 + 30) = 0;
            *((_DWORD *)v4 + 31) = 0;
            *((_DWORD *)v4 + 32) = 0;
            *((_DWORD *)v4 + 33) = 0;
            v10 = *((_DWORD *)v4 + 3);
            if ( !InterlockedDecrement((volatile LONG *)(v10 + 4)) && v10 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
            operator delete(v4);
          }
          v11 = *v2;
          v12 = *(void **)*v2;
          if ( v12 )
          {
            v13 = *((_DWORD *)v12 + 1);
            if ( v13 )
            {
              *(_DWORD *)v13 = *(_DWORD *)v12;
            }
            else
            {
              v14 = *(_DWORD *)v12;
              v7 = *(_DWORD *)v12 == 0;
              *(_DWORD *)v11 = *(_DWORD *)v12;
              if ( !v7 )
                *(_DWORD *)(v14 + 4) = 0;
            }
            if ( *(_DWORD *)v12 )
            {
              *(_DWORD *)(*(_DWORD *)v12 + 4) = *((_DWORD *)v12 + 1);
            }
            else
            {
              v15 = *(_DWORD *)(*((_DWORD *)v11 + 1) + 4);
              *((_DWORD *)v11 + 1) = v15;
              if ( v15 )
                *(_DWORD *)v15 = 0;
            }
            *(_DWORD *)v12 = 0;
            *((_DWORD *)v12 + 1) = 0;
          }
          v4 = v12;
        }
        while ( v12 );
        v1 = v20;
      }
    }
    if ( *v2 )
      operator delete(*v2);
    ++v2;
    --v19;
  }
  while ( v19 );
  v1->classIDHash.vfptr = (HashSet<IDClass<_tagDataID,32,0> >Vtbl *)&HashSet<IDClass<_tagDataID,32,0>>::vftable;
  v16 = (int)&v1->classIDHash.m_intrusiveTable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)v16);
  v17 = *(void **)(v16 + 96);
  *(_DWORD *)v16 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::vftable;
  if ( v17 != (void *)(v16 + 4) )
    operator delete[](v17);
  *(_DWORD *)(v16 + 96) = 0;
  *(_DWORD *)(v16 + 100) = 0;
  *(_DWORD *)(v16 + 104) = 0;
  *(_DWORD *)(v16 + 108) = 0;
  v20->objectIDHash.vfptr = (HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>Vtbl *)&HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v20->objectIDHash.m_intrusiveTable);
  v18 = v20->objectIDHash.m_intrusiveTable.m_buckets;
  v20->objectIDHash.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vftable;
  if ( v18 != v20->objectIDHash.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v18);
  v20->objectIDHash.m_intrusiveTable.m_buckets = 0;
  v20->objectIDHash.m_intrusiveTable.m_firstInterestingBucket = 0;
  v20->objectIDHash.m_intrusiveTable.m_numBuckets = 0;
  v20->objectIDHash.m_intrusiveTable.m_numElements = 0;
}
// 795298: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vftable[3])(void *, char);
// 7952A0: using guessed type int (__thiscall *HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::vftable)(void *, char);
// 79C9A8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable[3])(void *, char);
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);
// 7E1EF4: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::vftable[2])(void *, char);
// 7E1EF8: using guessed type int (__thiscall *HashSet<IDClass<_tagDataID,32,0>>::vftable)(void *, char);

//----- (00586DE0) --------------------------------------------------------  // acclient.c:431941
void __thiscall ComponentTracker::UpdateComponent(ComponentTracker *this, ACCWeenieObject *_weenObj, ComponentTrackerUpdate *_change)
{
  ComponentTracker *v3; // esi@1
  int v4; // ebx@1
  HashTableData<unsigned long,IDClass<_tagDataID,32,0> > *v5; // eax@1
  int v6; // eax@4

  v3 = this;
  v4 = ACCWeenieObject::IsOwnedByPlayer(_weenObj);
  v5 = v3->objectIDHash.m_intrusiveTable.m_buckets[_weenObj->id % v3->objectIDHash.m_intrusiveTable.m_numBuckets];
  if ( !v5 )
    goto LABEL_4;
  while ( v5->m_hashKey != _weenObj->id )
  {
    v5 = v5->m_hashNext;
    if ( !v5 )
      goto LABEL_4;
  }
  if ( v5 )
    LOBYTE(v6) = 1;
  else
LABEL_4:
    LOBYTE(v6) = 0;
  v6 = (unsigned __int8)v6;
  if ( v4 )
  {
    if ( v6 )
    {
      ComponentTracker::UpdateComponentStackSize(v3, _weenObj, _change);
    }
    else
    {
      ComponentTracker::AddComponent(v3, _weenObj);
      *_change = 1;
    }
  }
  else if ( v6 )
  {
    ComponentTracker::RemoveComponent(v3, _weenObj);
    *_change = 2;
  }
  else
  {
    *_change = 0;
  }
}

//----- (00687C90) --------------------------------------------------------  // acclient.c:671640
HashSetData<IDClass<_tagDataID,32,0> > *__thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *this, IDClass<_tagDataID,32,0> *key)
{
  unsigned int v2; // edx@1
  HashSetData<IDClass<_tagDataID,32,0> > **v3; // eax@1
  HashSetData<IDClass<_tagDataID,32,0> > *v4; // esi@1
  int v5; // edx@1
  HashSetData<IDClass<_tagDataID,32,0> > *result; // eax@4
  _BYTE v7[12]; // ST00_12@6

  v2 = key->id % this->m_numBuckets;
  v3 = this->m_buckets;
  v4 = v3[v2];
  v5 = (int)&v3[v2];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.id != key->id )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    *(_DWORD *)v7 = this;
    *(_QWORD *)&v7[4] = __PAIR__((unsigned int)v4, v5);
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::remove(
      (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)this,
      *(IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v7);
    result = v4;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00709B50) --------------------------------------------------------  // acclient.c:796946
void _E94_27()
{
  flt_870A78 = 1000.0 + 1.0;
}

//----- (00709B70) --------------------------------------------------------  // acclient.c:796952
void _E96()
{
  flt_870A7C = 24.0 * 8.0;
}

//----- (00709B90) --------------------------------------------------------  // acclient.c:796958
void _E98_14()
{
  flt_870A80 = 24.0 * 0.5;
}

//----- (00709BB0) --------------------------------------------------------  // acclient.c:796964
int sub_709BB0()
{
  return atexit(nullsub_1384);
}

//----- (00709BC0) --------------------------------------------------------  // acclient.c:796970
int sub_709BC0()
{
  return atexit(nullsub_1385);
}

//----- (00709BD0) --------------------------------------------------------  // acclient.c:796976
int sub_709BD0()
{
  return atexit(_E107_94);
}

//----- (00709BE0) --------------------------------------------------------  // acclient.c:796982
void _E109_73()
{
  flt_870A84 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00709C00) --------------------------------------------------------  // acclient.c:796988
void _E111_48()
{
  dbl_870A88 = 1.0 / 30.0;
}

//----- (00709C20) --------------------------------------------------------  // acclient.c:796994
void _E113_25()
{
  dbl_870A90 = 1.0 / 5.0;
}

//----- (00709C40) --------------------------------------------------------  // acclient.c:797000
void _E115_79()
{
  PixelFormatDesc::PixelFormatDesc(&stru_870A98, PFID_A8R8G8B8);
}

//----- (00709C50) --------------------------------------------------------  // acclient.c:797006
int sub_709C50()
{
  return atexit(nullsub_1383);
}

