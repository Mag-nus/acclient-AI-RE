/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AvailablePropertySet
   Object     : ENGINE\property\AvailablePropertySet.obj
   Functions  : 8
   Addresses  : 0042BAF0 - 007281C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0042BAF0) --------------------------------------------------------  // acclient.c:104686
HashIterator<unsigned long,AvailableProperty,0> *__thiscall AvailablePropertySet::end(AvailablePropertySet *this, HashIterator<unsigned long,AvailableProperty,0> *result)
{
  HashIterator<unsigned long,AvailableProperty,0> *v2; // eax@1

  v2 = result;
  result->m_iter.m_currHashTable = &this->m_reqHash.m_intrusiveTable;
  result->m_iter.m_currBucket = 0;
  result->m_iter.m_currElement = 0;
  return v2;
}

//----- (0042BB10) --------------------------------------------------------  // acclient.c:104698
bool __thiscall AvailablePropertySet::contains(AvailablePropertySet *this, unsigned int _name)
{
  HashTableData<unsigned long,AvailableProperty> *v2; // eax@1
  bool v3; // zf@1

  v2 = this->m_reqHash.m_intrusiveTable.m_buckets[_name % this->m_reqHash.m_intrusiveTable.m_numBuckets];
  v3 = v2 == 0;
  if ( v2 )
  {
    do
    {
      if ( v2->m_hashKey == _name )
        break;
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    v3 = v2 == 0;
  }
  return !v3;
}

//----- (0042BB40) --------------------------------------------------------  // acclient.c:104720
char __thiscall HashTable<unsigned long,AvailableProperty,0>::set(HashTable<unsigned long,AvailableProperty,0> *this, const unsigned int *_key, AvailableProperty *_data)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *v3; // edi@1
  HashTableData<unsigned long,AvailableProperty> *v4; // eax@1
  void *v5; // esi@4
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
    AvailableProperty::operator=(&v4->m_data, _data);
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
      AvailableProperty::operator=((AvailableProperty *)v5 + 2, _data);
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

//----- (0042BBD0) --------------------------------------------------------  // acclient.c:104768
char __thiscall AvailablePropertySet::AddProperty(AvailablePropertySet *this, unsigned int _name)
{
  HashTable<unsigned long,AvailableProperty,0> *v2; // esi@1
  AvailableProperty req; // [sp+0h] [bp-4h]@1

  req.m_name = (unsigned int)this;
  v2 = (HashTable<unsigned long,AvailableProperty,0> *)this;
  ClipPlane::ClipPlane((ClipPlane *)&req);
  req.m_name = _name;
  return HashTable<unsigned long,AvailableProperty,0>::set(v2, &_name, &req);
}

//----- (0042BC00) --------------------------------------------------------  // acclient.c:104781
void __cdecl SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>,HashTableData<unsigned long,AvailableProperty> *,SB_Default>(const int *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0> *io_object, Archive *io_archive)
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
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::resize(
        (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
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
        ControlSpecification::Serialize((ControlSpecification *)&v11->m_data, v3);
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
          v17 = operator new(0xCu);
          v18 = v17;
          if ( v17 )
          {
            *((_DWORD *)v17 + 1) = 0;
            ClipPlane::ClipPlane((ClipPlane *)v17 + 1);
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
          ControlSpecification::Serialize((ControlSpecification *)v18 + 2, v3);
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

//----- (0042BE10) --------------------------------------------------------  // acclient.c:104934
void __thiscall AvailablePropertySet::Serialize(AvailablePropertySet *this, Archive *_io_archive)
{
  Archive *v2; // edi@1
  AvailablePropertySet *v3; // esi@1

  v2 = _io_archive;
  v3 = this;
  if ( ~LOBYTE(_io_archive->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_reqHash.m_intrusiveTable);
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>,HashTableData<unsigned long,AvailableProperty> *,SB_Default>(
    (const int *)&_io_archive,
    &v3->m_reqHash.m_intrusiveTable,
    v2);
}

//----- (006C56E0) --------------------------------------------------------  // acclient.c:733744
int _E73_21()
{
  KW_NULL.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(_E74_24);
}

//----- (007281C0) --------------------------------------------------------  // acclient.c:825956
void __cdecl _E74_24()
{
  char *v0; // esi@1

  v0 = &KW_NULL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

