/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : StringTable
   Object     : ENGINE\stringtable\StringTable.obj
   Functions  : 25
   Addresses  : 0042F940 - 006C5830 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0042F940) --------------------------------------------------------  // acclient.c:108719
bool __thiscall PStringBase<char>::operator<(PStringBase<char> *this, PStringBase<char> *rhs)
{
  int v2; // kr00_4@1
  bool result; // al@2

  v2 = strcmp(this->m_charbuffer->m_data, rhs->m_charbuffer->m_data);
  if ( v2 )
    result = -(v2 < 0) - ((v2 < 0) - 1) < 0;
  else
    result = 0;
  return result;
}

//----- (0042F9A0) --------------------------------------------------------  // acclient.c:108733
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0> *v2; // esi@1
  HashTableData<unsigned long,StringTableString *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::vftable;
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
// 798124: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::vftable)(void *, char);

//----- (0042F9E0) --------------------------------------------------------  // acclient.c:108754
void __thiscall SmartArray<unsigned long,1>::Serialize(SmartArray<unsigned long,1> *this, Archive *io_rcArchive)
{
  SmartArray<unsigned long,1> *v2; // edi@1
  unsigned int v3; // ebx@1
  unsigned int v4; // eax@1
  unsigned int v5; // ebx@9
  int v6; // ebp@10
  unsigned int v7; // eax@10

  v2 = this;
  v3 = this->m_num;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v3;
    else
      v3 = *(_DWORD *)v4;
  }
  if ( ~LOBYTE(io_rcArchive->m_flags) & 1 )
  {
    if ( v3 > Archive::GetSizeLeft(io_rcArchive) )
    {
      Archive::RaiseError(io_rcArchive);
      return;
    }
    v2->m_num = 0;
    SmartArray<unsigned long,1>::SetNElements(v2, v3, 1);
  }
  v5 = 0;
  if ( v2->m_num )
  {
    do
    {
      v6 = (int)&v2->m_data[v5];
      Archive::CheckAlignment(io_rcArchive, 4u);
      v7 = Archive::GetBytes(io_rcArchive, 4u);
      if ( v7 )
      {
        if ( io_rcArchive->m_flags & 1 )
          *(_DWORD *)v7 = *(_DWORD *)v6;
        else
          *(_DWORD *)v6 = *(_DWORD *)v7;
      }
      ++v5;
    }
    while ( v5 < v2->m_num );
  }
}

//----- (0042FA90) --------------------------------------------------------  // acclient.c:108806
void __thiscall StringTable::GetSubDataIDs(StringTable *this, QualifiedDataIDArray *id_array)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // ebp@1
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edi@1
  QualifiedDataID *v6; // eax@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@1

  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_strings.m_intrusiveTable,
         &result);
  v3 = v2->m_currElement;
  v4 = v2->m_currHashTable;
  v5 = v2->m_currBucket;
  if ( v3 )
  {
    do
    {
LABEL_2:
      QualifiedDataID::QualifiedDataID(
        (QualifiedDataID *)&result,
        (IDClass<_tagDataID,32,0>)v3->m_data.vfptr->Serialize,
        0);
      QualifiedDataIDArray::AddQDID(id_array, v6, 1u);
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

//----- (0042FB00) --------------------------------------------------------  // acclient.c:108851
void __thiscall StringTableString::StringTableString(StringTableString *this)
{
  StringTableString *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->m_table.id = INVALID_DID_25.id;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v1->m_comments.m_data = 0;
  v1->m_comments.m_sizeAndDeallocate = 0;
  v1->m_comments.m_num = 0;
  v1->m_strings.m_data = 0;
  v1->m_strings.m_sizeAndDeallocate = 0;
  v1->m_strings.m_num = 0;
  v1->m_variables.m_data = 0;
  v1->m_variables.m_sizeAndDeallocate = 0;
  v1->m_variables.m_num = 0;
  v1->m_varNames.m_data = 0;
  v1->m_varNames.m_sizeAndDeallocate = 0;
  v1->m_varNames.m_num = 0;
  v1->m_numWords = 1;
}

//----- (0042FB50) --------------------------------------------------------  // acclient.c:108877
void __thiscall StringTableString::~StringTableString(StringTableString *this)
{
  StringTableString *v1; // esi@1
  PStringBase<char> *v2; // ecx@2
  PStringBase<char> *v3; // ecx@7
  PStringBase<char> *v4; // ecx@10
  int v5; // esi@12

  v1 = this;
  if ( (this->m_varNames.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v2 = (PStringBase<char> *)this->m_varNames.m_data;
    if ( v2 )
      PStringBase<unsigned short>::vector_deleting_destructor(v2, 3u);
  }
  if ( (v1->m_variables.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_variables.m_data);
  if ( (v1->m_strings.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v3 = (PStringBase<char> *)v1->m_strings.m_data;
    if ( v3 )
      PStringBase<unsigned short>::vector_deleting_destructor(v3, 3u);
  }
  if ( (v1->m_comments.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v4 = (PStringBase<char> *)v1->m_comments.m_data;
    if ( v4 )
      PStringBase<unsigned short>::vector_deleting_destructor(v4, 3u);
  }
  v5 = (int)&v1->m_name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
  {
    if ( v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  }
}

//----- (0042FBF0) --------------------------------------------------------  // acclient.c:108915
bool __thiscall StringTableString::IsVarNameTableWorthPacking(StringTableString *this)
{
  StringTableString *v1; // ebp@1
  unsigned int v2; // ecx@1
  unsigned int v3; // eax@2
  unsigned int v4; // edi@2
  const wchar_t *v5; // eax@2
  int v6; // edx@3
  int v7; // esi@3
  unsigned int v8; // eax@7
  PSRefBufferCharData<unsigned short> *v9; // ecx@7
  const wchar_t *v10; // eax@7
  bool v11; // bl@8
  int v12; // edx@9
  int v13; // esi@9
  int v14; // eax@13
  int v15; // esi@14
  unsigned int v16; // eax@18
  PSRefBufferCharData<unsigned short> *v17; // ecx@18
  const wchar_t *v18; // eax@18
  int v19; // edx@19
  int v20; // esi@19
  int v21; // eax@23
  int v22; // esi@24
  PSRefBufferCharData<unsigned short> *v23; // ecx@28
  const wchar_t *v24; // eax@28
  int v25; // edx@29
  int v26; // esi@29
  int v27; // eax@33
  int v28; // esi@34
  char *v29; // esi@39
  unsigned int v30; // ecx@44
  PStringBase<unsigned short> v32; // [sp+8h] [bp-18h]@7
  PStringBase<unsigned short> v33; // [sp+Ch] [bp-14h]@18
  PStringBase<unsigned short> v34; // [sp+10h] [bp-10h]@2
  unsigned int loop; // [sp+14h] [bp-Ch]@1
  int nFound; // [sp+18h] [bp-8h]@1
  PStringBase<unsigned short> v37; // [sp+1Ch] [bp-4h]@28

  v1 = this;
  v2 = this->m_varNames.m_num;
  nFound = 0;
  loop = 0;
  if ( v2 )
  {
    do
    {
      v3 = _wcslen(L"PRE");
      PStringBase<unsigned short>::allocate_ref_buffer(&v34, v3);
      _wcscpy(v34.m_charbuffer->m_data, L"PRE");
      v4 = loop;
      v5 = v1->m_varNames.m_data[loop].m_charbuffer->m_data;
      if ( *((_DWORD *)v5 - 1) == *(_DWORD *)&v34.m_charbuffer[-1].m_data[14] )
      {
        v6 = *((_DWORD *)v5 - 2);
        v7 = *(_DWORD *)&v34.m_charbuffer[-1].m_data[12];
        if ( (v6 == v7 || v6 == -1 || v7 == -1) && _wcscmp(v5, v34.m_charbuffer->m_data) == 0 )
          goto LABEL_48;
      }
      v8 = _wcslen(L"NAME");
      PStringBase<unsigned short>::allocate_ref_buffer(&v32, v8);
      _wcscpy(v32.m_charbuffer->m_data, L"NAME");
      v9 = v32.m_charbuffer;
      v10 = v1->m_varNames.m_data[v4].m_charbuffer->m_data;
      if ( *((_DWORD *)v10 - 1) == *(_DWORD *)&v32.m_charbuffer[-1].m_data[14] )
      {
        v12 = *((_DWORD *)v10 - 2);
        v13 = *(_DWORD *)&v32.m_charbuffer[-1].m_data[12];
        if ( v12 == v13 || v12 == -1 || v13 == -1 )
        {
          v14 = _wcscmp(v10, v32.m_charbuffer->m_data);
          v9 = v32.m_charbuffer;
          v11 = v14 == 0;
        }
        else
        {
          v11 = 0;
        }
      }
      else
      {
        v11 = 0;
      }
      v15 = (int)&v9[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v9[-1].m_data[8]) && v15 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
      if ( v11 )
        goto LABEL_48;
      v16 = _wcslen(L"MID");
      PStringBase<unsigned short>::allocate_ref_buffer(&v33, v16);
      _wcscpy(v33.m_charbuffer->m_data, L"MID");
      v17 = v33.m_charbuffer;
      v18 = v1->m_varNames.m_data[v4].m_charbuffer->m_data;
      if ( *((_DWORD *)v18 - 1) == *(_DWORD *)&v33.m_charbuffer[-1].m_data[14] )
      {
        v19 = *((_DWORD *)v18 - 2);
        v20 = *(_DWORD *)&v33.m_charbuffer[-1].m_data[12];
        if ( v19 == v20 || v19 == -1 || v20 == -1 )
        {
          v21 = _wcscmp(v18, v33.m_charbuffer->m_data);
          v17 = v33.m_charbuffer;
          v11 = v21 == 0;
        }
        else
        {
          v11 = 0;
        }
      }
      v22 = (int)&v17[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v17[-1].m_data[8]) && v22 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
      if ( v11 )
        goto LABEL_48;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v37, L"POST");
      v23 = v37.m_charbuffer;
      v24 = v1->m_varNames.m_data[v4].m_charbuffer->m_data;
      if ( *((_DWORD *)v24 - 1) == *(_DWORD *)&v37.m_charbuffer[-1].m_data[14] )
      {
        v25 = *((_DWORD *)v24 - 2);
        v26 = *(_DWORD *)&v37.m_charbuffer[-1].m_data[12];
        if ( v25 == v26 || v25 == -1 || v26 == -1 )
        {
          v27 = _wcscmp(v24, v37.m_charbuffer->m_data);
          v23 = v37.m_charbuffer;
          v11 = v27 == 0;
        }
        else
        {
          v11 = 0;
        }
      }
      v28 = (int)&v23[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v23[-1].m_data[8]) && v28 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v28)(v28, 1);
      if ( v11 )
LABEL_48:
        v11 = 1;
      v29 = (char *)&v34.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v34.m_charbuffer[-1].m_data[8]) && v29 )
        (**(void (__thiscall ***)(char *, signed int))v29)(v29, 1);
      if ( v11 )
        ++nFound;
      v30 = v1->m_varNames.m_num;
      ++loop;
    }
    while ( loop < v30 );
  }
  return nFound >= 2;
}

//----- (0042FE80) --------------------------------------------------------  // acclient.c:109066
char __thiscall HashTable<unsigned long,PStringBase<unsigned short>,0>::find(HashTable<unsigned long,PStringBase<unsigned short>,0> *this, const unsigned int *_key, PStringBase<unsigned short> *_retval)
{
  HashTableData<unsigned long,PStringBase<unsigned short> > *v3; // esi@1
  char result; // al@4
  PSRefBufferCharData<unsigned short> *v5; // eax@6
  int v6; // edi@7
  PSRefBufferCharData<unsigned short> *v7; // esi@10

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
    v5 = _retval->m_charbuffer;
    if ( _retval->m_charbuffer != v3->m_data.m_charbuffer )
    {
      v6 = (int)&v5[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v5[-1].m_data[8]) )
      {
        if ( v6 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      }
      v7 = v3->m_data.m_charbuffer;
      _retval->m_charbuffer = v7;
      InterlockedIncrement((volatile LONG *)&v7[-1].m_data[8]);
    }
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (0042FF00) --------------------------------------------------------  // acclient.c:109109
int PStringBase<unsigned short>::sprintf_append(PStringBase<unsigned short> *this, const unsigned __int16 *fmt, ...)
{
  int v2; // eax@1
  PSRefBufferCharData<unsigned short> *v3; // ecx@1
  int v4; // edi@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<unsigned short> new_str; // [sp+0h] [bp-4h]@1
  va_list va; // [sp+10h] [bp+Ch]@1

  va_start(va, fmt);
  new_str.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v2 = PStringBase<unsigned short>::vsprintf(&new_str, fmt, va);
  v3 = new_str.m_charbuffer;
  v4 = v2;
  v5 = *(_DWORD *)&new_str.m_charbuffer[-1].m_data[14];
  if ( v5 != 1 )
  {
    PStringBase<unsigned short>::append_n_chars(this, new_str.m_charbuffer->m_data, v5 - 1);
    v3 = new_str.m_charbuffer;
  }
  v6 = (int)&v3[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v3[-1].m_data[8]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return v4;
}

//----- (0042FF70) --------------------------------------------------------  // acclient.c:109138
void __thiscall SmartArray<PStringBase<unsigned short>,1>::Serialize(SmartArray<PStringBase<unsigned short>,1> *this, Archive *io_rcArchive)
{
  SmartArray<PStringBase<unsigned short>,1> *v2; // esi@1
  unsigned int v3; // ebx@1
  unsigned int v4; // eax@1
  unsigned int v5; // ebx@9

  v2 = this;
  v3 = this->m_num;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v3;
    else
      v3 = *(_DWORD *)v4;
  }
  if ( ~LOBYTE(io_rcArchive->m_flags) & 1 )
  {
    if ( v3 > Archive::GetSizeLeft(io_rcArchive) )
    {
      Archive::RaiseError(io_rcArchive);
      return;
    }
    v2->m_num = 0;
    SmartArray<PStringBase<unsigned short>,1>::SetNElements(v2, v3, 1);
  }
  v5 = 0;
  if ( v2->m_num )
  {
    do
      PStringBase<unsigned short>::Serialize(&v2->m_data[v5++], io_rcArchive);
    while ( v5 < v2->m_num );
  }
}

//----- (00430000) --------------------------------------------------------  // acclient.c:109176
StringTableString *__thiscall StringTable::GetStringTableString(StringTable *this, unsigned int _stringID)
{
  HashTableData<unsigned long,StringTableString *> *v2; // eax@1
  StringTableString *result; // eax@4

  v2 = this->m_strings.m_intrusiveTable.m_buckets[_stringID % this->m_strings.m_intrusiveTable.m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey != _stringID )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 )
    result = v2->m_data;
  else
LABEL_4:
    result = 0;
  return result;
}

//----- (00430040) --------------------------------------------------------  // acclient.c:109199
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,StringTableString *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,StringTableString *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 798124: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::vftable)(void *, char);

//----- (004300D0) --------------------------------------------------------  // acclient.c:109232
int __thiscall StringTable::GetString(StringTable *this, PStringBase<unsigned short> *_result, unsigned int _stringID, HashTable<unsigned long,PStringBase<unsigned short>,0> *_varTable, bool _useMetaLanguage)
{
  unsigned int v5; // edi@1
  unsigned int v6; // ebp@1
  HashTableData<unsigned long,StringTableString *> *v7; // eax@1
  int result; // eax@4
  StringTableString *v9; // esi@6
  QualifiedDataID *v10; // eax@9
  int v11; // ecx@9
  int v12; // ecx@11
  bool v13; // zf@15
  unsigned int v14; // edi@18
  char *v15; // esi@26
  char *v16; // esi@37
  PSRefBufferCharData<char> *v17; // esi@41
  int v18; // esi@41
  char *v19; // esi@50
  PStringBase<unsigned short> *v20; // ebx@54
  unsigned int v21; // ecx@54
  bool v22; // al@54
  const unsigned __int16 *v23; // eax@55
  int v24; // ecx@55
  PStringBase<unsigned short> *v25; // edi@60
  PSRefBufferCharData<unsigned short> *v26; // eax@60
  int v27; // edi@62
  SmartArray<PStringBase<unsigned short>,1> vars; // [sp+Ch] [bp-24h]@9
  SmartArray<PStringBase<unsigned short>,1> metas; // [sp+18h] [bp-18h]@30
  StringTableMetaLanguage::RenderErr err; // [sp+24h] [bp-Ch]@15

  v5 = _stringID;
  v6 = 0;
  v7 = this->m_strings.m_intrusiveTable.m_buckets[_stringID % this->m_strings.m_intrusiveTable.m_numBuckets];
  if ( !v7 )
    return 2;
  while ( v7->m_hashKey != _stringID )
  {
    v7 = v7->m_hashNext;
    if ( !v7 )
      return 2;
  }
  if ( !v7 )
    return 2;
  v9 = v7->m_data;
  if ( !v9 )
    return 2;
  if ( v9->m_table.id != INVALID_DID_25.id )
  {
    QualifiedDataID::QualifiedDataID((QualifiedDataID *)&vars, v9->m_table, 0x25u);
    v11 = DBObj::Get(v10);
    if ( !v11 )
      return 5;
    v9 = StringTable::GetStringTableString((StringTable *)v11, v5);
    if ( !v9 )
    {
      (*(void (**)(void))(*(_DWORD *)v12 + 20))();
      return 4;
    }
    (*(void (**)(void))(*(_DWORD *)v12 + 20))();
  }
  if ( _useMetaLanguage )
  {
    err.msg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v13 = v9->m_variables.m_num == 0;
    vars.m_data = 0;
    vars.m_sizeAndDeallocate = 0;
    vars.m_num = 0;
    _useMetaLanguage = 0;
    if ( v13 )
      goto LABEL_71;
    do
    {
      _stringID = (unsigned int)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      if ( !HashTable<unsigned long,PStringBase<unsigned short>,0>::find(
              _varTable,
              &v9->m_variables.m_data[v6],
              (PStringBase<unsigned short> *)&_stringID) )
        _useMetaLanguage = 1;
      SmartArray<PStringBase<unsigned short>,1>::AddToEnd(&vars, (PStringBase<unsigned short> *)&_stringID);
      v14 = _stringID - 20;
      if ( !InterlockedDecrement((volatile LONG *)(_stringID - 20 + 4)) && v14 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
      ++v6;
    }
    while ( v6 < v9->m_variables.m_num );
    if ( !_useMetaLanguage )
    {
LABEL_71:
      metas.m_data = 0;
      metas.m_sizeAndDeallocate = 0;
      metas.m_num = 0;
      if ( (unsigned __int8)StringTableMetaLanguage::RenderString(
                              &v9->m_strings,
                              &vars,
                              &v9->m_varNames,
                              _result,
                              &metas,
                              1u,
                              &err) )
      {
        if ( (metas.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)metas.m_data )
          PStringBase<unsigned short>::vector_deleting_destructor((PStringBase<char> *)metas.m_data, 3u);
        if ( (vars.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)vars.m_data )
          PStringBase<unsigned short>::vector_deleting_destructor((PStringBase<char> *)vars.m_data, 3u);
        v16 = &err.msg.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&err.msg.m_charbuffer[-1]) && v16 )
          (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
        result = 0;
      }
      else
      {
        v17 = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        v18 = (int)&v17[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)(v18 + 4)) && v18 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
        if ( (metas.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)metas.m_data )
          PStringBase<unsigned short>::vector_deleting_destructor((PStringBase<char> *)metas.m_data, 3u);
        if ( (vars.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)vars.m_data )
          PStringBase<unsigned short>::vector_deleting_destructor((PStringBase<char> *)vars.m_data, 3u);
        v19 = &err.msg.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&err.msg.m_charbuffer[-1]) && v19 )
          (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
        result = 7;
      }
    }
    else
    {
      if ( (vars.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)vars.m_data )
        PStringBase<unsigned short>::vector_deleting_destructor((PStringBase<char> *)vars.m_data, 3u);
      v15 = &err.msg.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&err.msg.m_charbuffer[-1]) )
      {
        if ( v15 )
          (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
      }
      result = 6;
    }
  }
  else
  {
    v20 = _result;
    PStringBase<unsigned short>::clear(_result);
    v21 = v9->m_strings.m_num;
    v22 = 0;
    _useMetaLanguage = 0;
    if ( v21 > 0 )
    {
      do
      {
        v23 = v9->m_strings.m_data[v6].m_charbuffer->m_data;
        v24 = *((_DWORD *)v23 - 1);
        if ( v24 != 1 )
          PStringBase<unsigned short>::append_n_chars(v20, v23, v24 - 1);
        if ( v6 < v9->m_variables.m_num )
        {
          _result = (PStringBase<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
          InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
          if ( !HashTable<unsigned long,PStringBase<unsigned short>,0>::find(
                  _varTable,
                  &v9->m_variables.m_data[v6],
                  (PStringBase<unsigned short> *)&_result) )
            _useMetaLanguage = 1;
          v25 = _result;
          v26 = _result[-1].m_charbuffer;
          if ( v26 != (PSRefBufferCharData<unsigned short> *)1 )
            PStringBase<unsigned short>::append_n_chars(
              v20,
              (const unsigned __int16 *)_result,
              (unsigned int)((char *)&v26[-1].m_data[15] + 1));
          v27 = (int)&v25[-5];
          if ( !InterlockedDecrement((volatile LONG *)(v27 + 4)) && v27 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
        }
        ++v6;
      }
      while ( v6 < v9->m_strings.m_num );
      v22 = _useMetaLanguage;
    }
    result = v22 != 0 ? 6 : 0;
  }
  return result;
}

//----- (00430480) --------------------------------------------------------  // acclient.c:109418
void __thiscall StringTableString::Serialize(StringTableString *this, Archive *_rArchive)
{
  StringTableString *v2; // edi@1
  unsigned int v3; // eax@1
  bool v4; // bl@5
  unsigned int v5; // eax@5

  v2 = this;
  Archive::CheckAlignment(_rArchive, 4u);
  v3 = Archive::GetBytes(_rArchive, 4u);
  if ( v3 )
  {
    if ( _rArchive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_table.id;
    else
      v2->m_table.id = *(_DWORD *)v3;
  }
  SmartArray<PStringBase<unsigned short>,1>::Serialize(&v2->m_strings, _rArchive);
  SmartArray<unsigned long,1>::Serialize(&v2->m_variables, _rArchive);
  v4 = StringTableString::IsVarNameTableWorthPacking(v2);
  Archive::CheckAlignment(_rArchive, 1u);
  v5 = Archive::GetBytes(_rArchive, 1u);
  if ( v5 )
  {
    if ( _rArchive->m_flags & 1 )
      *(_BYTE *)v5 = v4;
    else
      v4 = *(_BYTE *)v5;
  }
  if ( !(_rArchive->m_flags & 5) )
  {
    if ( !v4 )
      return;
    if ( v4 != 1 )
      Archive::RaiseError(_rArchive);
  }
  if ( v4 )
    SmartArray<PStringBase<unsigned short>,1>::Serialize(&v2->m_varNames, _rArchive);
}

//----- (00430520) --------------------------------------------------------  // acclient.c:109459
void __thiscall StringTable::Destroy(StringTable *this)
{
  StringTable *v1; // esi@1
  PSRefBufferCharData<unsigned short> *v2; // eax@1
  int v3; // edi@2
  volatile LONG *v4; // ST00_4@5
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *v5; // ebx@6
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v6; // eax@6
  HashTableData<unsigned long,HeritageGroup_CG> *v7; // esi@6
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v8; // ebp@6
  HashTableData<unsigned long,HeritageGroup_CG> **v9; // edi@6
  void *v10; // ebx@7
  int v11; // [sp+10h] [bp-10h]@6
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+14h] [bp-Ch]@6

  v1 = this;
  this->m_version = 0;
  v2 = this->m_description.m_charbuffer;
  if ( (wchar_t *)v2 != PStringBase<unsigned short>::s_NullBuffer )
  {
    v3 = (int)&v2[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1].m_data[8]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    v1->m_description.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v4);
  }
  v1->m_language = 0;
  v5 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_strings.m_intrusiveTable;
  v11 = (int)&v1->m_strings.m_intrusiveTable;
  v6 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v1->m_strings.m_intrusiveTable,
         &result);
  v7 = v6->m_currElement;
  v8 = v6->m_currHashTable;
  v9 = v6->m_currBucket;
  if ( v7 )
  {
    do
    {
LABEL_7:
      v10 = v7->m_data.vfptr;
      if ( v10 )
      {
        StringTableString::~StringTableString((StringTableString *)v7->m_data.vfptr);
        operator delete(v10);
      }
      v7->m_data.vfptr = 0;
      v7 = v7->m_hashNext;
    }
    while ( v7 );
    while ( 1 )
    {
      ++v9;
      if ( v9 == &v8->m_buckets[v8->m_numBuckets] )
        break;
      if ( *v9 )
      {
        v7 = *v9;
        if ( *v9 )
          goto LABEL_7;
        break;
      }
    }
    v5 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)v11;
  }
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents(v5);
}

//----- (004305F0) --------------------------------------------------------  // acclient.c:109529
HashTable<unsigned long,StringTableString *,0> *__thiscall HashTable<unsigned long,StringTableString *,0>::scalar_deleting_destructor(HashTable<unsigned long,StringTableString *,0> *this, unsigned int a2)
{
  HashTable<unsigned long,StringTableString *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,StringTableString *,0>Vtbl *)&HashTable<unsigned long,StringTableString *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::vftable;
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
// 798124: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::vftable)(void *, char);
// 798150: using guessed type int (__thiscall *HashTable<unsigned long,StringTableString *,0>::vftable)(void *, char);

//----- (00430650) --------------------------------------------------------  // acclient.c:109555
void __thiscall StringTable::StringTable(StringTable *this)
{
  StringTable *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, INVALID_DID_25);
  v1->vfptr = (InterfaceVtbl *)&StringTable::vftable;
  v1->m_version = 0;
  v2 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->m_description.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v2);
  v1->m_language = 0;
  v1->m_strings.vfptr = (HashTable<unsigned long,StringTableString *,0>Vtbl *)&HashTable<unsigned long,StringTableString *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>(
    &v1->m_strings.m_intrusiveTable,
    0x17u);
}
// 798150: using guessed type int (__thiscall *HashTable<unsigned long,StringTableString *,0>::vftable)(void *, char);
// 798158: using guessed type __int32 (__stdcall *StringTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (004306A0) --------------------------------------------------------  // acclient.c:109577
signed int StringTable::GetDBOType()
{
  return 37;
}

//----- (004306B0) --------------------------------------------------------  // acclient.c:109583
void __thiscall StringTable::~StringTable(StringTable *this)
{
  StringTable *v1; // edi@1
  void *v2; // eax@1
  int v3; // esi@3

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&StringTable::vftable;
  StringTable::Destroy(this);
  v1->m_strings.vfptr = (HashTable<unsigned long,StringTableString *,0>Vtbl *)&HashTable<unsigned long,StringTableString *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_strings.m_intrusiveTable);
  v2 = v1->m_strings.m_intrusiveTable.m_buckets;
  v1->m_strings.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::vftable;
  if ( v2 != v1->m_strings.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v2);
  v1->m_strings.m_intrusiveTable.m_buckets = 0;
  v1->m_strings.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_strings.m_intrusiveTable.m_numBuckets = 0;
  v1->m_strings.m_intrusiveTable.m_numElements = 0;
  v3 = (int)&v1->m_description.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 798124: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::vftable)(void *, char);
// 798150: using guessed type int (__thiscall *HashTable<unsigned long,StringTableString *,0>::vftable)(void *, char);
// 798158: using guessed type __int32 (__stdcall *StringTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00430730) --------------------------------------------------------  // acclient.c:109612
void __cdecl SerializeHashTableData<StringTable *,unsigned long,StringTableString *,SB_Default,SB_Alloc<SB_DefaultAllocator,0,SB_Default>>(StringTable *const *_class, HashTableData<unsigned long,StringTableString *> *io_object, Archive *io_archive)
{
  unsigned int *v3; // eax@1
  StringTableString *v4; // eax@7
  StringTableString *v5; // eax@8
  StringTableString *v6; // ecx@11

  Archive::CheckAlignment(io_archive, 4u);
  v3 = (unsigned int *)Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *v3 = io_object->m_hashKey;
    else
      io_object->m_hashKey = *v3;
  }
  if ( !((io_archive->m_flags >> 2) & 1) )
  {
    if ( ~LOBYTE(io_archive->m_flags) & 1 )
    {
      v4 = (StringTableString *)operator new(0x3Cu);
      if ( v4 )
        StringTableString::StringTableString(v4);
      else
        v5 = 0;
      io_object->m_data = v5;
    }
    v6 = io_object->m_data;
    if ( v6 )
      StringTableString::Serialize(v6, io_archive);
    else
      Archive::RaiseError(io_archive);
  }
}

//----- (004307C0) --------------------------------------------------------  // acclient.c:109648
void __cdecl StringTable::Allocator()
{
  StringTable *v0; // eax@1

  v0 = (StringTable *)operator new(0xB0u);
  if ( v0 )
    StringTable::StringTable(v0);
}

//----- (004307E0) --------------------------------------------------------  // acclient.c:109658
StringTable *__thiscall StringTable::vector_deleting_destructor(StringTable *this, unsigned int a2)
{
  StringTable *v2; // esi@1

  v2 = this;
  StringTable::~StringTable(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00430800) --------------------------------------------------------  // acclient.c:109670
void __cdecl _SerializeIntrusiveHashTable____PAVStringTable__V__IntrusiveHashTable_KPAV__HashTableData_KPAVStringTableString_____0A___PAV__HashTableData_KPAVStringTableString____USB_HashData___SB_Hash_USB_Default__U__SB_Alloc_USB_DefaultAllocator___0A_USB_Default_____1_SB_DEFAULT_ITEM_NAME__3QBDB_1_SB_DEFAULT_KEY_NAME__3QBDB_1_SB_DEFAULT_VALUE_NAME__3QBDB____YAXABQAVStringTable__AAV__IntrusiveHashTable_KPAV__HashTableData_KPAVStringTableString_____0A___AAVArchive___Z(StringTable *const *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0> *io_object, Archive *io_archive)
{
  Archive *v3; // ebp@1
  unsigned int *v4; // esi@4
  unsigned int *v5; // edi@4
  const unsigned int *v6; // eax@4
  int v7; // ebx@6
  unsigned int v8; // eax@8
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // eax@19
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // ebx@19
  HashTableData<unsigned long,HeritageGroup_CG> *v11; // esi@19
  HashTableData<unsigned long,HeritageGroup_CG> **v12; // edi@19
  unsigned int v13; // eax@26
  HashTableData<unsigned long,Sex_CG> *v14; // edi@27
  unsigned int v15; // ebx@27
  void *v16; // eax@28
  HashTableData<unsigned long,StringTableString *> *v17; // esi@28
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
        SerializeHashTableData<StringTable *,unsigned long,StringTableString *,SB_Default,SB_Alloc<SB_DefaultAllocator,0,SB_Default>>(
          _class,
          (HashTableData<unsigned long,StringTableString *> *)v11,
          v3);
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
    v13 = Archive::GetSizeLeft(v3);
    if ( (unsigned int)io_archive > v13 )
    {
LABEL_34:
      Archive::RaiseError(v3);
    }
    else
    {
      v14 = 0;
      v15 = 0;
      if ( io_archive )
      {
        do
        {
          v16 = operator new(0xCu);
          v17 = 0;
          if ( v16 )
          {
            *((_DWORD *)v16 + 1) = 0;
            v17 = (HashTableData<unsigned long,StringTableString *> *)v16;
          }
          SerializeHashTableData<StringTable *,unsigned long,StringTableString *,SB_Default,SB_Alloc<SB_DefaultAllocator,0,SB_Default>>(
            _class,
            v17,
            v3);
          if ( (v3->m_flags >> 2) & 1 )
            break;
          if ( !IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
                  (HashTableData<unsigned long,Sex_CG> *)v17,
                  v14) )
            goto LABEL_34;
          ++v15;
          v14 = (HashTableData<unsigned long,Sex_CG> *)v17;
        }
        while ( v15 < (unsigned int)io_archive );
      }
    }
  }
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;

//----- (004309C0) --------------------------------------------------------  // acclient.c:109805
void __thiscall StringTable::Serialize(StringTable *this, Archive *_rArchive)
{
  Archive *v2; // esi@1
  StringTable *v3; // edi@1
  unsigned int v4; // eax@1

  v2 = _rArchive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, _rArchive);
  Archive::CheckAlignment(v2, 4u);
  v4 = Archive::GetBytes(v2, 4u);
  if ( v4 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v4 = v3->m_version;
    else
      v3->m_version = *(_DWORD *)v4;
  }
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v3->m_strings.m_intrusiveTable);
  _SerializeIntrusiveHashTable____PAVStringTable__V__IntrusiveHashTable_KPAV__HashTableData_KPAVStringTableString_____0A___PAV__HashTableData_KPAVStringTableString____USB_HashData___SB_Hash_USB_Default__U__SB_Alloc_USB_DefaultAllocator___0A_USB_Default_____1_SB_DEFAULT_ITEM_NAME__3QBDB_1_SB_DEFAULT_KEY_NAME__3QBDB_1_SB_DEFAULT_VALUE_NAME__3QBDB____YAXABQAVStringTable__AAV__IntrusiveHashTable_KPAV__HashTableData_KPAVStringTableString_____0A___AAVArchive___Z(
    (StringTable *const *)&_rArchive,
    &v3->m_strings.m_intrusiveTable,
    v2);
}

//----- (006C5830) --------------------------------------------------------  // acclient.c:733833
int _E1_25()
{
  return atexit(_E2_25);
}

