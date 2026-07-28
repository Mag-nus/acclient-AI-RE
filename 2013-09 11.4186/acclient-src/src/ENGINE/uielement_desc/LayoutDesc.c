/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : LayoutDesc
   Object     : ENGINE\uielement_desc\LayoutDesc.obj
   Functions  : 129
   Addresses  : 006997F0 - 00787650 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006997F0) --------------------------------------------------------  // acclient.c:689401
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::~IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0> *v1; // esi@1
  HashTableData<unsigned long,ElementDesc> **v2; // eax@1

  v1 = this;
  v2 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable;
  if ( v2 != this->m_aInplaceBuckets )
    operator delete[](v2);
  v1->m_buckets = 0;
  v1->m_firstInterestingBucket = 0;
  v1->m_numBuckets = 0;
  v1->m_numElements = 0;
}
// 800ABC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable[4])(void *, char);

//----- (00699820) --------------------------------------------------------  // acclient.c:689419
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0> *v2; // esi@1
  HashTableData<unsigned long,ElementDesc> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable;
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
// 800ABC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable[4])(void *, char);

//----- (00699860) --------------------------------------------------------  // acclient.c:689440
IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > *,0> *__thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::vector_deleting_destructor(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > *,0> *v2; // esi@1
  HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > *,0>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::vftable;
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
// 800AC0: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::vftable[3])(void *, char);

//----- (006998A0) --------------------------------------------------------  // acclient.c:689461
BOOL __thiscall SmartArray<BaseInfo,1>::contains(SmartArray<BaseInfo,1> *this, BaseInfo *data)
{
  unsigned int v2; // esi@1
  signed int v3; // edx@1
  BaseInfo *v4; // eax@2

  v2 = this->m_num;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->m_data;
    while ( v4->elementID != data->elementID || v4->layoutID.id != data->layoutID.id )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v3 = -1;
  }
  return v3 != -1;
}

//----- (006998E0) --------------------------------------------------------  // acclient.c:689489
void __thiscall LayoutDesc::GetSubDataIDs(LayoutDesc *this, QualifiedDataIDArray *_id_array)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@1

  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_elements.m_intrusiveTable,
         &result);
  v3 = v2->m_currElement;
  v4 = v2->m_currHashTable;
  v5 = v2->m_currBucket;
  if ( v3 )
  {
    do
    {
LABEL_2:
      v3->m_data.vfptr[2].Serialize(&v3->m_data, (Archive *)_id_array);
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

//----- (00699940) --------------------------------------------------------  // acclient.c:689529
char __thiscall HashTable<unsigned long,ElementDesc,0>::find(HashTable<unsigned long,ElementDesc,0> *this, const unsigned int *_key, ElementDesc *_retval)
{
  HashTableData<unsigned long,ElementDesc> *v3; // eax@1
  char result; // al@4

  v3 = this->m_intrusiveTable.m_buckets[*_key % this->m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != *_key )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    ElementDesc::operator=((StateDesc *)&_retval->vfptr, (StateDesc *)&v3->m_data.vfptr);
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00699990) --------------------------------------------------------  // acclient.c:689557
ElementDesc *__thiscall LayoutDesc::AccessElementDesc(LayoutDesc *this, unsigned int _elementID)
{
  HashTableData<unsigned long,ElementDesc> *v2; // eax@1
  ElementDesc *result; // eax@4

  v2 = this->m_elements.m_intrusiveTable.m_buckets[_elementID % this->m_elements.m_intrusiveTable.m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey != _elementID )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 )
    result = &v2->m_data;
  else
LABEL_4:
    result = 0;
  return result;
}

//----- (006999D0) --------------------------------------------------------  // acclient.c:689580
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,ElementDesc> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,ElementDesc> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 800ABC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable[4])(void *, char);

//----- (00699A60) --------------------------------------------------------  // acclient.c:689613
void __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > *,0>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 800AC0: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::vftable[3])(void *, char);

//----- (00699B40) --------------------------------------------------------  // acclient.c:689672
char __thiscall SmartArray<BaseInfo,1>::add_unique(SmartArray<BaseInfo,1> *this, BaseInfo *_data)
{
  SmartArray<QualifiedDataID,1> *v2; // esi@1
  char result; // al@2

  v2 = (SmartArray<QualifiedDataID,1> *)this;
  if ( (unsigned __int8)SmartArray<BaseInfo,1>::contains(this, _data) )
    result = 0;
  else
    result = SmartArray<BaseInfo,1>::add(v2, (QualifiedDataID *)_data);
  return result;
}

//----- (00699B70) --------------------------------------------------------  // acclient.c:689686
char __thiscall HashTable<unsigned long,ElementDesc,0>::add(HashTable<unsigned long,ElementDesc,0> *this, const unsigned int *_key, ElementDesc *_data)
{
  HashTable<unsigned long,ElementDesc,0> *v3; // edi@1
  void *v4; // esi@1
  char result; // al@7

  v3 = this;
  v4 = operator new(0x1CCu);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    *((_DWORD *)v4 + 1) = 0;
    ElementDesc::ElementDesc((ElementDesc *)((char *)v4 + 8), _data);
  }
  else
  {
    v4 = 0;
  }
  if ( IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v3->m_intrusiveTable,
         (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v4) )
  {
    result = 1;
  }
  else
  {
    if ( v4 )
    {
      ElementDesc::~ElementDesc((ElementDesc *)((char *)v4 + 8));
      operator delete(v4);
    }
    result = 0;
  }
  return result;
}

//----- (00699BE0) --------------------------------------------------------  // acclient.c:689723
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned long,ElementDesc> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,ElementDesc> **v5; // edx@5
  HashTableData<unsigned long,ElementDesc> *v6; // edi@5
  HashTableData<unsigned long,ElementDesc> *v7; // eax@7
  HashTableData<unsigned long,ElementDesc> *v8; // ecx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,ElementDesc> **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,ElementDesc> **)v4;
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
      ElementDesc::~ElementDesc(&v6->m_data);
      operator delete(v6);
    }
  }
}

//----- (00699C70) --------------------------------------------------------  // acclient.c:689783
void __cdecl SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>,HashTableData<unsigned long,ElementDesc> *,SB_Default>(const int *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0> *io_object, Archive *io_archive)
{
  Archive *v3; // esi@1
  unsigned int *v4; // edi@4
  unsigned int *v5; // ebp@4
  const unsigned int *v6; // eax@4
  int v7; // ebx@6
  unsigned int v8; // eax@8
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // eax@19
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // ebx@19
  HashTableData<unsigned long,HeritageGroup_CG> *v11; // edi@19
  HashTableData<unsigned long,HeritageGroup_CG> **v12; // ebp@19
  unsigned int v13; // eax@21
  unsigned int v14; // eax@30
  HashTableData<unsigned long,Sex_CG> *v15; // ebx@31
  unsigned int v16; // ebp@31
  void *v17; // eax@32
  void *v18; // edi@32
  unsigned int v19; // eax@35
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@19

  v3 = io_archive;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::clear((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object);
  if ( (v3->m_flags & 5) == 1 )
  {
    v4 = g_bucketSizesEnd;
    v5 = g_bucketSizesBegin;
    io_archive = (Archive *)io_object->m_numBuckets;
    v6 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, (const unsigned int *)&io_archive);
    if ( v6 == v4 )
      --v6;
    v7 = v6 - v5;
  }
  else
  {
    LOBYTE(v7) = (_BYTE)io_archive;
  }
  Archive::CheckAlignment(v3, 1u);
  v8 = Archive::GetBytes(v3, 1u);
  if ( v8 )
  {
    if ( v3->m_flags & 1 )
      *(_BYTE *)v8 = v7;
    else
      LOBYTE(v7) = *(_BYTE *)v8;
  }
  if ( !(v3->m_flags & 5) )
  {
    if ( (unsigned __int8)v7 < g_numBucketSizes )
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::resize(
        (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *)io_object,
        g_bucketSizesBegin[(unsigned __int8)v7]);
    else
      Archive::RaiseError(v3);
  }
  if ( (v3->m_flags & 5) == 1 )
    io_archive = (Archive *)io_object->m_numElements;
  SB_As32Bit_Compressed::Serialize((const int *)&io_archive, (unsigned int *)&io_archive, v3);
  if ( (v3->m_flags & 5) == 1 )
  {
    v9 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)io_object,
           &result);
    v10 = v9->m_currHashTable;
    v11 = v9->m_currElement;
    v12 = v9->m_currBucket;
LABEL_20:
    while ( v11 )
    {
      do
      {
        Archive::CheckAlignment(v3, 4u);
        v13 = Archive::GetBytes(v3, 4u);
        if ( v13 )
        {
          if ( v3->m_flags & 1 )
            *(_DWORD *)v13 = v11->m_hashKey;
          else
            v11->m_hashKey = *(_DWORD *)v13;
        }
        v11->m_data.vfptr[1].Serialize(&v11->m_data, v3);
        v11 = v11->m_hashNext;
      }
      while ( v11 );
      while ( 1 )
      {
        ++v12;
        if ( v12 == &v10->m_buckets[v10->m_numBuckets] )
          break;
        if ( *v12 )
        {
          v11 = *v12;
          goto LABEL_20;
        }
      }
    }
  }
  if ( !(v3->m_flags & 5) )
  {
    v14 = Archive::GetSizeLeft(v3);
    if ( (unsigned int)io_archive > v14 )
    {
LABEL_43:
      Archive::RaiseError(v3);
    }
    else
    {
      v15 = 0;
      v16 = 0;
      if ( io_archive )
      {
        do
        {
          v17 = operator new(0x1CCu);
          v18 = v17;
          if ( v17 )
          {
            *((_DWORD *)v17 + 1) = 0;
            ElementDesc::ElementDesc((ElementDesc *)((char *)v17 + 8));
          }
          else
          {
            v18 = 0;
          }
          Archive::CheckAlignment(v3, 4u);
          v19 = Archive::GetBytes(v3, 4u);
          if ( v19 )
          {
            if ( v3->m_flags & 1 )
              *(_DWORD *)v19 = *(_DWORD *)v18;
            else
              *(_DWORD *)v18 = *(_DWORD *)v19;
          }
          (*(void (__thiscall **)(int, Archive *))(*((_DWORD *)v18 + 2) + 4))((char *)v18 + 8, v3);
          if ( (v3->m_flags >> 2) & 1 )
            break;
          if ( !IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
                  (HashTableData<unsigned long,Sex_CG> *)v18,
                  v15) )
            goto LABEL_43;
          ++v16;
          v15 = (HashTableData<unsigned long,Sex_CG> *)v18;
        }
        while ( v16 < (unsigned int)io_archive );
      }
    }
  }
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;

//----- (00699E90) --------------------------------------------------------  // acclient.c:689936
void __thiscall LayoutDesc::Destroy(LayoutDesc *this)
{
  LayoutDesc *v1; // esi@1
  PSRefBufferCharData<char> *v2; // eax@1
  int v3; // edi@2
  volatile LONG *v4; // ST00_4@5
  PSRefBufferCharData<char> *v5; // eax@6
  int v6; // edi@7
  volatile LONG *v7; // ST00_4@10
  PSRefBufferCharData<char> *v8; // eax@11
  int v9; // edi@12
  volatile LONG *v10; // ST00_4@15
  PSRefBufferCharData<char> *v11; // eax@16
  int v12; // edi@17
  volatile LONG *v13; // ST00_4@20

  v1 = this;
  this->m_displayHeight = 0;
  this->m_displayWidth = 0;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::delete_contents(&this->m_elements.m_intrusiveTable);
  v2 = v1->m_strElementHeader.m_charbuffer;
  if ( v2 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_strElementHeader.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v4);
  }
  v5 = v1->m_strElementWHeader.m_charbuffer;
  if ( v5 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v6 = (int)&v5[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_strElementWHeader.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v7);
  }
  v8 = v1->m_strStateHeader.m_charbuffer;
  if ( v8 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v9 = (int)&v8[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v8[-1]) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v10 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_strStateHeader.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v10);
  }
  v11 = v1->m_strStateWHeader.m_charbuffer;
  if ( v11 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v12 = (int)&v11[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v11[-1]) )
    {
      if ( v12 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
    }
    v13 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_strStateWHeader.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v13);
  }
}

//----- (00699FB0) --------------------------------------------------------  // acclient.c:690002
void __thiscall HashTable<unsigned long,ElementDesc,0>::~HashTable<unsigned long,ElementDesc,0>(HashTable<unsigned long,ElementDesc,0> *this)
{
  char *v1; // esi@1
  void *v2; // eax@1

  v1 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,ElementDesc,0>Vtbl *)HashTable<unsigned long,ElementDesc,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::delete_contents(&this->m_intrusiveTable);
  v2 = (void *)*((_DWORD *)v1 + 24);
  *(_DWORD *)v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable;
  if ( v2 != v1 + 4 )
    operator delete[](v2);
  *((_DWORD *)v1 + 24) = 0;
  *((_DWORD *)v1 + 25) = 0;
  *((_DWORD *)v1 + 26) = 0;
  *((_DWORD *)v1 + 27) = 0;
}
// 800ABC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable[4])(void *, char);
// 800AC4: using guessed type int (__thiscall *HashTable<unsigned long,ElementDesc,0>::vftable[2])(void *, char);

//----- (00699FF0) --------------------------------------------------------  // acclient.c:690023
int __thiscall HashTable<unsigned long,ElementDesc,0>::operator=(int this, unsigned int __val)
{
  unsigned int v2; // edi@1
  int v3; // ebx@1
  unsigned int *v4; // ebp@2
  unsigned int *v5; // eax@2
  void *v6; // ebp@4
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // eax@4
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // edi@4
  void *v9; // esi@7
  unsigned int v10; // ebx@10
  int v11; // ecx@10
  int v12; // edx@11
  int v13; // eax@14
  HashTableData<unsigned long,HeritageGroup_CG> **v14; // ecx@18
  HashTableData<unsigned long,HeritageGroup_CG> **v15; // eax@19
  int v17; // [sp+8h] [bp-1Ch]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-18h]@4
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v19; // [sp+18h] [bp-Ch]@4

  v2 = __val;
  v3 = this;
  v17 = this;
  if ( this == __val )
    return v3;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0> *)(this + 4));
  v4 = g_bucketSizesEnd;
  __val = *(_DWORD *)(v2 + 108);
  v5 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v5 == v4 )
    --v5;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::resize_internal(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *)(v3 + 4),
    *v5);
  v6 = 0;
  v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)(v2 + 4),
         &result);
  v8 = v7->m_currElement;
  v19 = v7->m_currHashTable;
  result.m_currBucket = v7->m_currBucket;
  if ( !v8 )
    return v3;
  while ( 1 )
  {
    v9 = operator new(0x1CCu);
    if ( v9 )
    {
      *(_DWORD *)v9 = v8->m_hashKey;
      *((_DWORD *)v9 + 1) = 0;
      ElementDesc::ElementDesc((ElementDesc *)((char *)v9 + 8), (ElementDesc *)&v8->m_data);
    }
    else
    {
      v9 = 0;
    }
    v10 = *(_DWORD *)(v3 + 108);
    v11 = *(_DWORD *)v9 % v10;
    if ( !v6 )
      goto LABEL_14;
    v12 = *(_DWORD *)v6 % v10;
    if ( v11 != v12 )
    {
      if ( v11 <= (unsigned int)v12 )
        goto LABEL_17;
LABEL_14:
      v13 = *(_DWORD *)(v17 + 100) + 4 * v11;
      *(_DWORD *)v13 = v9;
      if ( !v6 )
        *(_DWORD *)(v17 + 104) = v13;
      goto LABEL_16;
    }
    *((_DWORD *)v6 + 1) = v9;
LABEL_16:
    ++*(_DWORD *)(v17 + 112);
LABEL_17:
    v8 = v8->m_hashNext;
    v6 = v9;
    if ( !v8 )
      break;
LABEL_6:
    v3 = v17;
  }
  v14 = &v19->m_buckets[v19->m_numBuckets];
  while ( 1 )
  {
    v15 = result.m_currBucket + 1;
    ++result.m_currBucket;
    if ( result.m_currBucket == v14 )
      return v17;
    if ( *v15 )
    {
      v8 = *v15;
      if ( *v15 )
        goto LABEL_6;
      return v17;
    }
  }
}

//----- (0069A140) --------------------------------------------------------  // acclient.c:690124
HashTable<unsigned long,ElementDesc,0> *__thiscall HashTable<unsigned long,ElementDesc,0>::scalar_deleting_destructor(HashTable<unsigned long,ElementDesc,0> *this, unsigned int a2)
{
  HashTable<unsigned long,ElementDesc,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,ElementDesc,0>Vtbl *)HashTable<unsigned long,ElementDesc,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable;
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
// 800ABC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable[4])(void *, char);
// 800AC4: using guessed type int (__thiscall *HashTable<unsigned long,ElementDesc,0>::vftable[2])(void *, char);

//----- (0069A1A0) --------------------------------------------------------  // acclient.c:690150
void __thiscall LayoutDesc::LayoutDesc(LayoutDesc *this)
{
  LayoutDesc *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1
  volatile LONG *v5; // ST00_4@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_8F900C);
  v1->vfptr = (InterfaceVtbl *)&NonDBObjLayoutDesc::vftable;
  v1->m_displayWidth = 0;
  v1->m_displayHeight = 0;
  v1->m_elements.vfptr = (HashTable<unsigned long,ElementDesc,0>Vtbl *)HashTable<unsigned long,ElementDesc,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>(
    &v1->m_elements.m_intrusiveTable,
    0x17u);
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strElementHeader.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strElementWHeader.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strStateHeader.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strStateWHeader.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v5);
}
// 800AC4: using guessed type int (__thiscall *HashTable<unsigned long,ElementDesc,0>::vftable[2])(void *, char);
// 800AD0: using guessed type __int32 (__stdcall *NonDBObjLayoutDesc::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0069A230) --------------------------------------------------------  // acclient.c:690184
void __thiscall LayoutDesc::~LayoutDesc(LayoutDesc *this)
{
  LayoutDesc *v1; // esi@1
  int v2; // edi@1
  int v3; // edi@4
  int v4; // edi@7
  int v5; // edi@10
  void *v6; // eax@13

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&NonDBObjLayoutDesc::vftable;
  LayoutDesc::Destroy(this);
  v2 = (int)&v1->m_strStateWHeader.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v2 + 4)) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->m_strStateHeader.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = (int)&v1->m_strElementWHeader.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  v5 = (int)&v1->m_strElementHeader.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v1->m_elements.vfptr = (HashTable<unsigned long,ElementDesc,0>Vtbl *)HashTable<unsigned long,ElementDesc,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::delete_contents(&v1->m_elements.m_intrusiveTable);
  v6 = v1->m_elements.m_intrusiveTable.m_buckets;
  v1->m_elements.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable;
  if ( v6 != v1->m_elements.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v6);
  v1->m_elements.m_intrusiveTable.m_buckets = 0;
  v1->m_elements.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_elements.m_intrusiveTable.m_numBuckets = 0;
  v1->m_elements.m_intrusiveTable.m_numElements = 0;
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 800ABC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable[4])(void *, char);
// 800AC4: using guessed type int (__thiscall *HashTable<unsigned long,ElementDesc,0>::vftable[2])(void *, char);
// 800AD0: using guessed type __int32 (__stdcall *NonDBObjLayoutDesc::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0069A310) --------------------------------------------------------  // acclient.c:690225
void __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::delete_contents(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > *,0> *this)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > *,0> *v1; // ebx@1
  int v2; // ecx@2
  HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > **v3; // eax@3
  int v4; // eax@4
  HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > **v5; // edx@5
  HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > *v6; // edi@5
  HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > *v7; // eax@7
  HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > *v8; // ecx@8
  void *v9; // eax@13

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_19;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_19:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      v6->m_data.vfptr = (HashTable<unsigned long,ElementDesc,0>Vtbl *)HashTable<unsigned long,ElementDesc,0>::vftable;
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::delete_contents(&v6->m_data.m_intrusiveTable);
      v9 = v6->m_data.m_intrusiveTable.m_buckets;
      v6->m_data.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable;
      if ( v9 != v6->m_data.m_intrusiveTable.m_aInplaceBuckets )
        operator delete[](v9);
      v6->m_data.m_intrusiveTable.m_buckets = 0;
      v6->m_data.m_intrusiveTable.m_firstInterestingBucket = 0;
      v6->m_data.m_intrusiveTable.m_numBuckets = 0;
      v6->m_data.m_intrusiveTable.m_numElements = 0;
      operator delete(v6);
    }
  }
}
// 800ABC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable[4])(void *, char);
// 800AC4: using guessed type int (__thiscall *HashTable<unsigned long,ElementDesc,0>::vftable[2])(void *, char);

//----- (0069A3D0) --------------------------------------------------------  // acclient.c:690297
char __thiscall HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0>::add(HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0> *this, IDClass<_tagDataID,32,0> *_key, HashTable<unsigned long,ElementDesc,0> *_data)
{
  void *v3; // esi@1
  void *v4; // eax@6
  char result; // al@9
  HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0> *v6; // [sp+Ch] [bp-4h]@1

  v6 = this;
  v3 = operator new(0x7Cu);
  if ( v3 )
  {
    *(_DWORD *)v3 = _key->id;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = HashTable<unsigned long,ElementDesc,0>::vftable;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0> *)((char *)v3 + 12),
      _data->m_intrusiveTable.m_numBuckets);
    HashTable<unsigned long,ElementDesc,0>::operator=((int)((char *)v3 + 8), (unsigned int)_data);
  }
  else
  {
    v3 = 0;
  }
  if ( IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v6->m_intrusiveTable,
         (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v3) )
  {
    result = 1;
  }
  else
  {
    if ( v3 )
    {
      *((_DWORD *)v3 + 2) = HashTable<unsigned long,ElementDesc,0>::vftable;
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0> *)((char *)v3 + 12));
      v4 = (void *)*((_DWORD *)v3 + 27);
      *((_DWORD *)v3 + 3) = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable;
      if ( v4 != (char *)v3 + 16 )
        operator delete[](v4);
      *((_DWORD *)v3 + 27) = 0;
      *((_DWORD *)v3 + 28) = 0;
      *((_DWORD *)v3 + 29) = 0;
      *((_DWORD *)v3 + 30) = 0;
      operator delete(v3);
    }
    result = 0;
  }
  return result;
}
// 800ABC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable[4])(void *, char);
// 800AC4: using guessed type int (__thiscall *HashTable<unsigned long,ElementDesc,0>::vftable[2])(void *, char);

//----- (0069A490) --------------------------------------------------------  // acclient.c:690350
void __thiscall LayoutDesc::Serialize(LayoutDesc *this, Archive *_io_archive)
{
  Archive *v2; // esi@1
  LayoutDesc *v3; // edi@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@5

  v2 = _io_archive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, _io_archive);
  Archive::CheckAlignment(v2, 4u);
  v4 = Archive::GetBytes(v2, 4u);
  if ( v4 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v4 = v3->m_displayWidth;
    else
      v3->m_displayWidth = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(v2, 4u);
  v5 = Archive::GetBytes(v2, 4u);
  if ( v5 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v5 = v3->m_displayHeight;
    else
      v3->m_displayHeight = *(_DWORD *)v5;
  }
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::delete_contents(&v3->m_elements.m_intrusiveTable);
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>,HashTableData<unsigned long,ElementDesc> *,SB_Default>(
    (const int *)&_io_archive,
    &v3->m_elements.m_intrusiveTable,
    v2);
}

//----- (0069A520) --------------------------------------------------------  // acclient.c:690387
bool __cdecl LayoutDesc::InqFullDesc(ElementDesc *_local_desc, ElementDesc *_full_desc, SmartArray<BaseInfo,1> *_recurse)
{
  ElementDesc *v3; // edi@1
  unsigned int v5; // ebx@3
  IDClass<_tagDataID,32,0> v6; // ebp@3
  HashTable<unsigned long,ElementDesc,0> *v7; // esi@3
  QualifiedDataID *v8; // eax@8
  int v9; // ecx@8
  int v10; // ecx@9
  ElementDesc *v11; // edi@9
  DBObjGrabber<LayoutDesc> layout; // [sp+4h] [bp-84h]@3
  unsigned int elementID; // [sp+8h] [bp-80h]@3
  BaseInfo bi; // [sp+Ch] [bp-7Ch]@8
  HashTable<unsigned long,ElementDesc,0> _data; // [sp+14h] [bp-74h]@5

  v3 = _local_desc;
  if ( _local_desc->m_type )
  {
    ElementDesc::operator=((StateDesc *)&_full_desc->vfptr, (StateDesc *)&_local_desc->vfptr);
    return 1;
  }
  v5 = _local_desc->m_baseElement;
  v6.id = _local_desc->m_baseLayout.id;
  v7 = 0;
  layout.m_object = (LayoutDesc *)_local_desc->m_baseLayout.id;
  elementID = v5;
  if ( !LayoutDesc::s_bUseDescCache )
    goto LABEL_21;
  v7 = (HashTable<unsigned long,ElementDesc,0> *)HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
                                                   &LayoutDesc::s_DescCache,
                                                   (const unsigned int *)&layout);
  if ( !v7 )
  {
    _data.vfptr = (HashTable<unsigned long,ElementDesc,0>Vtbl *)HashTable<unsigned long,ElementDesc,0>::vftable;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>(
      &_data.m_intrusiveTable,
      0x17u);
    HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0>::add(
      (HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0> *)&LayoutDesc::s_DescCache,
      (IDClass<_tagDataID,32,0> *)&layout,
      &_data);
    HashTable<unsigned long,ElementDesc,0>::~HashTable<unsigned long,ElementDesc,0>(&_data);
    v7 = (HashTable<unsigned long,ElementDesc,0> *)HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
                                                     &LayoutDesc::s_DescCache,
                                                     (const unsigned int *)&layout);
    if ( !v7 )
      return 0;
  }
  if ( !LayoutDesc::s_bUseDescCache || !HashTable<unsigned long,ElementDesc,0>::find(v7, &elementID, _full_desc) )
  {
LABEL_21:
    QualifiedDataID::QualifiedDataID((QualifiedDataID *)&bi, v6, 0x23u);
    v9 = DBObj::Get(v8);
    layout.m_object = (LayoutDesc *)v9;
    if ( !v9 )
      return 0;
    v11 = LayoutDesc::AccessElementDesc((LayoutDesc *)v9, v5);
    if ( !v11 )
    {
      (*(void (**)(void))(*(_DWORD *)v10 + 20))();
      return 0;
    }
    bi.elementID = v5;
    bi.layoutID.id = v6.id;
    if ( !SmartArray<BaseInfo,1>::add_unique(_recurse, &bi) || !LayoutDesc::InqFullDesc(v11, _full_desc, _recurse) )
    {
      DBObjGrabber<StringTable>::~DBObjGrabber<StringTable>((DBObjGrabber<ACCharGenData> *)&layout);
      return 0;
    }
    if ( LayoutDesc::s_bUseDescCache )
      HashTable<unsigned long,ElementDesc,0>::add(v7, &elementID, _full_desc);
    DBObjGrabber<StringTable>::~DBObjGrabber<StringTable>((DBObjGrabber<ACCharGenData> *)&layout);
    v3 = _local_desc;
  }
  return ElementDesc::Incorporate(_full_desc, v3) != 0;
}
// 800AC4: using guessed type int (__thiscall *HashTable<unsigned long,ElementDesc,0>::vftable[2])(void *, char);
// 834A70: using guessed type bool LayoutDesc::s_bUseDescCache;

//----- (0069A6C0) --------------------------------------------------------  // acclient.c:690467
HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0> *__thiscall HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0>::vector_deleting_destructor(HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0> *this, unsigned int a2)
{
  HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0>Vtbl *)&HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0>::vftable;
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::vftable;
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
// 800AC0: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::vftable[3])(void *, char);
// 800AC8: using guessed type int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0>::vftable)(void *, char);

//----- (0071B440) --------------------------------------------------------  // acclient.c:813582
int sub_71B440()
{
  KW_NULL_3.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_786CC0);
}

//----- (0071B460) --------------------------------------------------------  // acclient.c:813590
int sub_71B460()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE, "Base");
  return atexit(sub_786CF0);
}

//----- (0071B480) --------------------------------------------------------  // acclient.c:813597
int _E79_95()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE, "BottomEdge");
  return atexit(_E80_92);
}

//----- (0071B4A0) --------------------------------------------------------  // acclient.c:813604
int _E82_60()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD, "Child");
  return atexit(_E83_56);
}

//----- (0071B4C0) --------------------------------------------------------  // acclient.c:813611
int _E85_43()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE, "Code");
  return atexit(_E86_35);
}

//----- (0071B4E0) --------------------------------------------------------  // acclient.c:813618
int _E88_32()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE, "DefaultState");
  return atexit(_E89_45);
}

//----- (0071B500) --------------------------------------------------------  // acclient.c:813625
int sub_71B500()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT, "DisplayHeight");
  return atexit(_E92_54);
}

//----- (0071B520) --------------------------------------------------------  // acclient.c:813632
int _E94_45()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH, "DisplayWidth");
  return atexit(sub_786E10);
}

//----- (0071B540) --------------------------------------------------------  // acclient.c:813639
int sub_71B540()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE, "DrawMode");
  return atexit(sub_786E40);
}

//----- (0071B560) --------------------------------------------------------  // acclient.c:813646
int sub_71B560()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION, "Duration");
  return atexit(sub_786E70);
}

//----- (0071B580) --------------------------------------------------------  // acclient.c:813653
int sub_71B580()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT, "Element");
  return atexit(sub_786EA0);
}

//----- (0071B5A0) --------------------------------------------------------  // acclient.c:813660
int sub_71B5A0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER, "ElementHeader");
  return atexit(sub_786ED0);
}

//----- (0071B5C0) --------------------------------------------------------  // acclient.c:813667
int _E109_93()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER, "ElementWHeader");
  return atexit(sub_786F00);
}

//----- (0071B5E0) --------------------------------------------------------  // acclient.c:813674
int sub_71B5E0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID, "ElementID");
  return atexit(_E113_78);
}

//----- (0071B600) --------------------------------------------------------  // acclient.c:813681
int _E115_97()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA, "EndAlpha");
  return atexit(_E116_70);
}

//----- (0071B620) --------------------------------------------------------  // acclient.c:813688
int _E118_88()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE, "EngineType");
  return atexit(_E119_93);
}

//----- (0071B640) --------------------------------------------------------  // acclient.c:813695
int _E121_79()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID, "EventID");
  return atexit(sub_786FC0);
}

//----- (0071B660) --------------------------------------------------------  // acclient.c:813702
int _E124_79()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE, "File");
  return atexit(_E125_73);
}

//----- (0071B680) --------------------------------------------------------  // acclient.c:813709
int _E127_66()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES, "Frames");
  return atexit(_E128_71);
}

//----- (0071B6A0) --------------------------------------------------------  // acclient.c:813716
int _E130_59()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER, "PREPROC_HEADER");
  return atexit(_E131_60);
}

//----- (0071B6C0) --------------------------------------------------------  // acclient.c:813723
int _E133_52()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT, "Height");
  return atexit(_E134_44);
}

//----- (0071B6E0) --------------------------------------------------------  // acclient.c:813730
int _E136_36()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX, "JumpItemIndex");
  return atexit(_E137_43);
}

//----- (0071B700) --------------------------------------------------------  // acclient.c:813737
int _E139_36()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE, "LeftEdge");
  return atexit(_E140_37);
}

//----- (0071B720) --------------------------------------------------------  // acclient.c:813744
int _E142_33()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION, "MaxDuration");
  return atexit(_E143_37);
}

//----- (0071B740) --------------------------------------------------------  // acclient.c:813751
int _E145_35()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA, "Media");
  return atexit(_E146_37);
}

//----- (0071B760) --------------------------------------------------------  // acclient.c:813758
int _E148_34()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE, "MediaType");
  return atexit(_E149_36);
}

//----- (0071B780) --------------------------------------------------------  // acclient.c:813765
int _E151_32()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION, "MinDuration");
  return atexit(_E152_37);
}

//----- (0071B7A0) --------------------------------------------------------  // acclient.c:813772
int _E154_33()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE, "NoDBFile");
  return atexit(_E155_33);
}

//----- (0071B7C0) --------------------------------------------------------  // acclient.c:813779
int _E157_30()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN, "StretchToFullScreen");
  return atexit(_E158_34);
}

//----- (0071B7E0) --------------------------------------------------------  // acclient.c:813786
int _E160_33()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN, "PassToChildren");
  return atexit(_E161_31);
}

//----- (0071B800) --------------------------------------------------------  // acclient.c:813793
int _E163_26()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY, "Probability");
  return atexit(_E164_33);
}

//----- (0071B820) --------------------------------------------------------  // acclient.c:813800
int _E166_28()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_0, "Properties");
  return atexit(_E167_29);
}

//----- (0071B840) --------------------------------------------------------  // acclient.c:813807
int _E169_26()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE, "Remove");
  return atexit(_E170_29);
}

//----- (0071B860) --------------------------------------------------------  // acclient.c:813814
int _E172_24()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE, "RightEdge");
  return atexit(_E173_24);
}

//----- (0071B880) --------------------------------------------------------  // acclient.c:813821
int _E175_21()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME, "SoundName");
  return atexit(_E176_26);
}

//----- (0071B8A0) --------------------------------------------------------  // acclient.c:813828
int _E178_21()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE, "SoundTable");
  return atexit(_E179_25);
}

//----- (0071B8C0) --------------------------------------------------------  // acclient.c:813835
int _E181_21()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA, "StartAlpha");
  return atexit(_E182_25);
}

//----- (0071B8E0) --------------------------------------------------------  // acclient.c:813842
int _E184_19()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE, "State");
  return atexit(_E185_22);
}

//----- (0071B900) --------------------------------------------------------  // acclient.c:813849
int _E187_18()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER, "StateHeader");
  return atexit(_E188_23);
}

//----- (0071B920) --------------------------------------------------------  // acclient.c:813856
int _E190_19()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER, "StateWHeader");
  return atexit(_E191_22);
}

//----- (0071B940) --------------------------------------------------------  // acclient.c:813863
int _E193_18()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID, "StateID");
  return atexit(_E194_29);
}

//----- (0071B960) --------------------------------------------------------  // acclient.c:813870
int _E196_25()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE, "TopEdge");
  return atexit(_E197_19);
}

//----- (0071B980) --------------------------------------------------------  // acclient.c:813877
int _E199_17()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE, "Type");
  return atexit(_E200_23);
}

//----- (0071B9A0) --------------------------------------------------------  // acclient.c:813884
int _E202_21()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH, "Width");
  return atexit(_E203_22);
}

//----- (0071B9C0) --------------------------------------------------------  // acclient.c:813891
int _E205_19()
{
  PStringBase<char>::PStringBase<char>(&KW_X, "X");
  return atexit(_E206_26);
}

//----- (0071B9E0) --------------------------------------------------------  // acclient.c:813898
int _E208_23()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT, "XHotspot");
  return atexit(_E209_20);
}

//----- (0071BA00) --------------------------------------------------------  // acclient.c:813905
int _E211_18()
{
  PStringBase<char>::PStringBase<char>(&KW_Y, "Y");
  return atexit(_E212_23);
}

//----- (0071BA20) --------------------------------------------------------  // acclient.c:813912
int _E214_20()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT, "YHotspot");
  return atexit(_E215_20);
}

//----- (0071BA40) --------------------------------------------------------  // acclient.c:813919
int _E217_17()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL, "ZLevel");
  return atexit(_E218_20);
}

//----- (0071BA60) --------------------------------------------------------  // acclient.c:813926
int _E220_17()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS, "Comments");
  return atexit(_E221_20);
}

//----- (0071BA80) --------------------------------------------------------  // acclient.c:813933
int _E223_18()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA, "HasAlpha");
  return atexit(_E224_20);
}

//----- (0071BAA0) --------------------------------------------------------  // acclient.c:813940
int _E226_17()
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>(
    &stru_834A7C,
    0x17u);
  return atexit(_E227_20);
}

//----- (0071BAC0) --------------------------------------------------------  // acclient.c:813949
int sub_71BAC0()
{
  return atexit(nullsub_310);
}

//----- (00786CC0) --------------------------------------------------------  // acclient.c:926347
void __cdecl sub_786CC0()
{
  char *v0; // esi@1

  v0 = &KW_NULL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786CF0) --------------------------------------------------------  // acclient.c:926360
void __cdecl sub_786CF0()
{
  char *v0; // esi@1

  v0 = &KW_BASE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786D20) --------------------------------------------------------  // acclient.c:926373
void __cdecl _E80_92()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786D50) --------------------------------------------------------  // acclient.c:926386
void __cdecl _E83_56()
{
  char *v0; // esi@1

  v0 = &KW_CHILD.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786D80) --------------------------------------------------------  // acclient.c:926399
void __cdecl _E86_35()
{
  char *v0; // esi@1

  v0 = &KW_CODE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786DB0) --------------------------------------------------------  // acclient.c:926412
void __cdecl _E89_45()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786DE0) --------------------------------------------------------  // acclient.c:926425
void __cdecl _E92_54()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786E10) --------------------------------------------------------  // acclient.c:926438
void __cdecl sub_786E10()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786E40) --------------------------------------------------------  // acclient.c:926451
void __cdecl sub_786E40()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786E70) --------------------------------------------------------  // acclient.c:926464
void __cdecl sub_786E70()
{
  char *v0; // esi@1

  v0 = &KW_DURATION.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786EA0) --------------------------------------------------------  // acclient.c:926477
void __cdecl sub_786EA0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786ED0) --------------------------------------------------------  // acclient.c:926490
void __cdecl sub_786ED0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786F00) --------------------------------------------------------  // acclient.c:926503
void __cdecl sub_786F00()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786F30) --------------------------------------------------------  // acclient.c:926516
void __cdecl _E113_78()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786F60) --------------------------------------------------------  // acclient.c:926529
void __cdecl _E116_70()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786F90) --------------------------------------------------------  // acclient.c:926542
void __cdecl _E119_93()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786FC0) --------------------------------------------------------  // acclient.c:926555
void __cdecl sub_786FC0()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786FF0) --------------------------------------------------------  // acclient.c:926568
void __cdecl _E125_73()
{
  char *v0; // esi@1

  v0 = &KW_FILE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787020) --------------------------------------------------------  // acclient.c:926581
void __cdecl _E128_71()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787050) --------------------------------------------------------  // acclient.c:926594
void __cdecl _E131_60()
{
  char *v0; // esi@1

  v0 = &KW_HEADER.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787080) --------------------------------------------------------  // acclient.c:926607
void __cdecl _E134_44()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007870B0) --------------------------------------------------------  // acclient.c:926620
void __cdecl _E137_43()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007870E0) --------------------------------------------------------  // acclient.c:926633
void __cdecl _E140_37()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787110) --------------------------------------------------------  // acclient.c:926646
void __cdecl _E143_37()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787140) --------------------------------------------------------  // acclient.c:926659
void __cdecl _E146_37()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787170) --------------------------------------------------------  // acclient.c:926672
void __cdecl _E149_36()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007871A0) --------------------------------------------------------  // acclient.c:926685
void __cdecl _E152_37()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007871D0) --------------------------------------------------------  // acclient.c:926698
void __cdecl _E155_33()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787200) --------------------------------------------------------  // acclient.c:926711
void __cdecl _E158_34()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787230) --------------------------------------------------------  // acclient.c:926724
void __cdecl _E161_31()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787260) --------------------------------------------------------  // acclient.c:926737
void __cdecl _E164_33()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787290) --------------------------------------------------------  // acclient.c:926750
void __cdecl _E167_29()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007872C0) --------------------------------------------------------  // acclient.c:926763
void __cdecl _E170_29()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007872F0) --------------------------------------------------------  // acclient.c:926776
void __cdecl _E173_24()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787320) --------------------------------------------------------  // acclient.c:926789
void __cdecl _E176_26()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787350) --------------------------------------------------------  // acclient.c:926802
void __cdecl _E179_25()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787380) --------------------------------------------------------  // acclient.c:926815
void __cdecl _E182_25()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007873B0) --------------------------------------------------------  // acclient.c:926828
void __cdecl _E185_22()
{
  char *v0; // esi@1

  v0 = &KW_STATE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007873E0) --------------------------------------------------------  // acclient.c:926841
void __cdecl _E188_23()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787410) --------------------------------------------------------  // acclient.c:926854
void __cdecl _E191_22()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787440) --------------------------------------------------------  // acclient.c:926867
void __cdecl _E194_29()
{
  char *v0; // esi@1

  v0 = &KW_STATEID.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787470) --------------------------------------------------------  // acclient.c:926880
void __cdecl _E197_19()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007874A0) --------------------------------------------------------  // acclient.c:926893
void __cdecl _E200_23()
{
  char *v0; // esi@1

  v0 = &KW_TYPE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007874D0) --------------------------------------------------------  // acclient.c:926906
void __cdecl _E203_22()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787500) --------------------------------------------------------  // acclient.c:926919
void __cdecl _E206_26()
{
  char *v0; // esi@1

  v0 = &KW_X.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787530) --------------------------------------------------------  // acclient.c:926932
void __cdecl _E209_20()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787560) --------------------------------------------------------  // acclient.c:926945
void __cdecl _E212_23()
{
  char *v0; // esi@1

  v0 = &KW_Y.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787590) --------------------------------------------------------  // acclient.c:926958
void __cdecl _E215_20()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007875C0) --------------------------------------------------------  // acclient.c:926971
void __cdecl _E218_20()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007875F0) --------------------------------------------------------  // acclient.c:926984
void __cdecl _E221_20()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787620) --------------------------------------------------------  // acclient.c:926997
void __cdecl _E224_20()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787650) --------------------------------------------------------  // acclient.c:927010
void __cdecl _E227_20()
{
  LayoutDesc::s_DescCache.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)&HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0>::vftable;
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::delete_contents(&stru_834A7C);
  stru_834A7C.vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > *,0>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::vftable;
  if ( (HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > **)stru_834A7C.m_buckets != stru_834A7C.m_aInplaceBuckets )
    operator delete[](stru_834A7C.m_buckets);
  stru_834A7C.m_buckets = 0;
  stru_834A7C.m_firstInterestingBucket = 0;
  stru_834A7C.m_numBuckets = 0;
  stru_834A7C.m_numElements = 0;
}
// 800AC0: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::vftable[3])(void *, char);
// 800AC8: using guessed type int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0>::vftable)(void *, char);

