/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ActionMap
   Object     : ENGINE\actionmap\ActionMap.obj
   Functions  : 59
   Addresses  : 006845E0 - 0077F950 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006845E0) --------------------------------------------------------  // acclient.c:667813
char __thiscall ActionMapValue::GetDescriptionValues(ActionMapValue *this, IDClass<_tagDataID,32,0> i_didStringTable, PStringBase<unsigned short> *o_strName, PStringBase<unsigned short> *o_strDescription)
{
  ActionMapValue *v4; // esi@1
  char result; // al@2
  StringInfo info; // [sp+4h] [bp-90h]@1

  v4 = this;
  StringInfo::StringInfo(&info);
  StringInfo::SetStringIDandTableID(&info, v4->m_userBindingData.m_action_name, i_didStringTable);
  if ( StringInfo::InqString(&info, o_strName, 0) )
  {
    if ( v4->m_userBindingData.m_description )
    {
      info.m_stringID = v4->m_userBindingData.m_description;
      StringInfo::InqString(&info, o_strDescription, 0);
    }
    StringInfo::~StringInfo(&info);
    result = 1;
  }
  else
  {
    StringInfo::~StringInfo(&info);
    result = 0;
  }
  return result;
}

//----- (00684670) --------------------------------------------------------  // acclient.c:667841
IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *__thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::vftable;
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
// 7FEE04: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::vftable[3])(void *, char);

//----- (006846B0) --------------------------------------------------------  // acclient.c:667862
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0> *v2; // esi@1
  HashTableData<unsigned long,InputMapConflictsValue> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::vftable;
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
// 7FEE08: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::vftable[2])(void *, char);

//----- (006846F0) --------------------------------------------------------  // acclient.c:667883
void __cdecl Serializer::SerializeMagicNumber(int i_object, Archive *io_archive)
{
  unsigned int v2; // eax@1
  unsigned int v3; // eax@2
  unsigned int v4; // eax@7
  Archive *v5; // ecx@9

  v2 = io_archive->m_flags & 5;
  if ( v2 == 1 )
  {
    Archive::CheckAlignment(io_archive, 4u);
    v3 = Archive::GetBytes(io_archive, 4u);
    if ( v3 )
    {
      if ( io_archive->m_flags & 1 )
        *(_DWORD *)v3 = i_object;
    }
  }
  else if ( !v2 )
  {
    Archive::CheckAlignment(io_archive, 4u);
    v4 = Archive::GetBytes(io_archive, 4u);
    if ( v4 )
    {
      if ( io_archive->m_flags & 1 )
      {
        v5 = io_archive;
        *(_DWORD *)v4 = io_archive;
      }
      else
      {
        v5 = *(Archive **)v4;
      }
    }
    else
    {
      v5 = io_archive;
    }
    if ( v5 != (Archive *)i_object )
      Archive::RaiseError(io_archive);
  }
}

//----- (00684770) --------------------------------------------------------  // acclient.c:667927
char __cdecl FileNodeUtils::GetNameAsEnum(PFileNode *_node, unsigned int _mapID, unsigned int *_retvalue)
{
  PSRefBufferCharData<char> *v3; // esi@1
  char v4; // bl@1
  PSRefBufferCharData<char> *v5; // ecx@1
  int v6; // esi@3
  int v7; // edx@5
  PStringBase<char> v9; // [sp-8h] [bp-1Ch]@1
  signed int v10; // [sp-4h] [bp-18h]@2
  PStringBase<char> strName; // [sp+10h] [bp-4h]@1

  strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PFileNode::GetNameAsPString(_node, (int)InterlockedIncrement, &strName);
  v3 = strName.m_charbuffer;
  v4 = 1;
  v9.m_charbuffer = strName.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&strName.m_charbuffer[-1]);
  if ( !EnumMapper::GetEnum(_mapID, v9, _retvalue) )
  {
    v10 = (signed int)v3;
    v9.m_charbuffer = v5;
    PStringBase<char>::PStringBase<char>(&v9, "invalid emp value '%s'");
    PFileNode::ReportError((int)InterlockedIncrement, _node, v9);
    v4 = 0;
  }
  v6 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
  {
    v7 = *(_DWORD *)v6;
    v10 = 1;
    (*(void (__thiscall **)(int, signed int))v7)(v6, 1);
  }
  return v4;
}

//----- (00684840) --------------------------------------------------------  // acclient.c:667986
char __thiscall HashList<unsigned long,ActionMapValue,1>::find(HashList<unsigned long,ActionMapValue,1> *this, const unsigned int *key, ActionMapValue *data)
{
  HashList<unsigned long,ActionMapValue,1>::HashListData *v3; // eax@1
  char result; // al@4
  int v5; // eax@6

  v3 = this->m_ihlIntrusive.m_hash.m_buckets[*key % this->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != *key )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    v5 = (int)&v3->m_data;
    data->m_eToggleType = *(_DWORD *)v5;
    data->m_userBindingData.m_eActionClass = *(_DWORD *)(v5 + 4);
    data->m_userBindingData.m_action_name = *(_DWORD *)(v5 + 8);
    data->m_userBindingData.m_description = *(_DWORD *)(v5 + 12);
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (006848A0) --------------------------------------------------------  // acclient.c:668019
void __thiscall List<unsigned long>::Serialize(List<unsigned long> *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  unsigned int v3; // eax@1
  List<unsigned long> *v4; // ebx@1
  unsigned int v5; // eax@2
  ListNode<unsigned long> *i; // edi@6
  unsigned int v7; // eax@7
  unsigned int v8; // eax@15
  Archive *v9; // ebp@17
  unsigned int v10; // edi@23
  Archive **v11; // eax@24

  v2 = io_archive;
  v3 = io_archive->m_flags & 5;
  v4 = this;
  if ( v3 == 1 )
  {
    Archive::CheckAlignment(io_archive, 4u);
    v5 = Archive::GetBytes(v2, 4u);
    if ( v5 )
    {
      if ( v2->m_flags & 1 )
        *(_DWORD *)v5 = v4->_num_elements;
      else
        v4->_num_elements = *(_DWORD *)v5;
    }
    for ( i = v4->_head; i; i = i->next )
    {
      Archive::CheckAlignment(v2, 4u);
      v7 = Archive::GetBytes(v2, 4u);
      if ( v7 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v7 = i->data;
        else
          i->data = *(_DWORD *)v7;
      }
      if ( !i )
        break;
    }
  }
  else if ( !v3 )
  {
    List<SkillRecord *>::flush((List<SkillRecord *> *)this);
    Archive::CheckAlignment(v2, 4u);
    v8 = Archive::GetBytes(v2, 4u);
    if ( v8 )
    {
      if ( v2->m_flags & 1 )
      {
        v9 = io_archive;
        *(_DWORD *)v8 = io_archive;
      }
      else
      {
        v9 = *(Archive **)v8;
      }
    }
    else
    {
      v9 = io_archive;
    }
    if ( ~(unsigned __int8)(v2->m_flags >> 2) & 1 )
    {
      if ( (unsigned int)v9 <= Archive::GetSizeLeft(v2) )
      {
        v10 = 0;
        if ( v9 )
        {
          do
          {
            Archive::CheckAlignment(v2, 4u);
            v11 = (Archive **)Archive::GetBytes(v2, 4u);
            if ( v11 )
            {
              if ( v2->m_flags & 1 )
                *v11 = io_archive;
              else
                io_archive = *v11;
            }
            if ( (v2->m_flags >> 2) & 1 )
              break;
            List<PFileNode *>::push_back((List<UIElement_UIItem *> *)v4, (UIElement_UIItem *const *)&io_archive);
            ++v10;
          }
          while ( v10 < (unsigned int)v9 );
        }
      }
      else
      {
        Archive::RaiseError(v2);
      }
    }
  }
}

//----- (006849E0) --------------------------------------------------------  // acclient.c:668117
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::grow(IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::resize_internal(
           v2,
           *v3);
}

//----- (00684A30) --------------------------------------------------------  // acclient.c:668137
void __thiscall ActionMapValue::Serialize(ActionMapValue *this, Archive *io_archive)
{
  ActionMapValue *v2; // edi@1
  char v3; // bl@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@9
  List<unsigned long> listDummy; // [sp+Ch] [bp-10h]@13

  v2 = this;
  Serializer::SerializeMagicNumber(0, io_archive);
  v3 = 0;
  Archive::CheckAlignment(io_archive, 1u);
  v4 = Archive::GetBytes(io_archive, 1u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_BYTE *)v4 = 0;
    else
      v3 = *(_BYTE *)v4;
  }
  if ( !(io_archive->m_flags & 5) && v3 && v3 != 1 )
    Archive::RaiseError(io_archive);
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v5 = v2->m_eToggleType;
    else
      v2->m_eToggleType = *(_DWORD *)v5;
  }
  listDummy.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
  listDummy._head = 0;
  listDummy._tail = 0;
  listDummy._num_elements = 0;
  List<unsigned long>::Serialize(&listDummy, io_archive);
  QualifiedControl::Serialize((AC1Legacy::Vector3 *)&v2->m_userBindingData, io_archive);
  listDummy.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&listDummy);
}
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);

//----- (00684B00) --------------------------------------------------------  // acclient.c:668180
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,InputMapConflictsValue> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,InputMapConflictsValue> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FEE08: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::vftable[2])(void *, char);

//----- (00684B90) --------------------------------------------------------  // acclient.c:668213
void __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>(IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FEE04: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::vftable[3])(void *, char);

//----- (00684C20) --------------------------------------------------------  // acclient.c:668246
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::resize_internal(IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *v2; // esi@1
  char result; // al@2
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v4; // ebx@3
  int v5; // ecx@4
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **v6; // eax@5
  int v7; // eax@6
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **v8; // ecx@7
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v9; // edi@7
  _BYTE v10[12]; // ST08_12@9
  unsigned int v11; // ST10_4@12
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v12; // edi@12
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v13; // ebp@13
  unsigned int *v14; // ebx@14
  unsigned int *v15; // eax@14
  int v16; // eax@18

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        *(_QWORD *)&v10[4] = __PAIR__((unsigned int)v9, (unsigned int)v8);
        *(_DWORD *)v10 = v2;
        IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::remove(
          (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v2,
          *(IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v10);
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v11 = _numBuckets;
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v2,
      v11);
    v12 = v4;
    if ( v4 )
    {
      do
      {
        v13 = v12->m_hashNext;
        if ( (signed int)(2 * v2->m_numBuckets) < (signed int)(v2->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v2->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::resize_internal(
            v2,
            *v15);
        }
        v16 = (int)&v2->m_buckets[v12->m_hashKey % v2->m_numBuckets];
        v12->m_hashNext = *(HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **)v16;
        *(_DWORD *)v16 = v12;
        if ( (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **)v16 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **)v16;
        ++v2->m_numElements;
        v12 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (00684D50) --------------------------------------------------------  // acclient.c:668351
char __thiscall HashTable<unsigned long,InputMapConflictsValue,0>::find(HashTable<unsigned long,InputMapConflictsValue,0> *this, const unsigned int *_key, InputMapConflictsValue *_retval)
{
  HashTableData<unsigned long,InputMapConflictsValue> *v3; // eax@1
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
    _retval->m_eInputMap = v3->m_data.m_eInputMap;
    AC1Legacy::List<unsigned long>::operator=(
      (List<SkillRecord *> *)&_retval->m_listConflictingInputMaps,
      (int)&v3->m_data.m_listConflictingInputMaps);
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00684DA0) --------------------------------------------------------  // acclient.c:668382
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0> *v1; // edi@1
  int v2; // ecx@2
  HashTableData<unsigned long,InputMapConflictsValue> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,InputMapConflictsValue> **v5; // edx@5
  HashTableData<unsigned long,InputMapConflictsValue> *v6; // esi@5
  HashTableData<unsigned long,InputMapConflictsValue> *v7; // eax@7
  HashTableData<unsigned long,InputMapConflictsValue> *v8; // ecx@8
  ListNode<unsigned long> *v9; // ecx@14
  ListNode<unsigned long> *v10; // eax@15

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,InputMapConflictsValue> **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,InputMapConflictsValue> **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_25;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_25:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      v6->m_data.m_listConflictingInputMaps.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
      while ( 1 )
      {
        v9 = v6->m_data.m_listConflictingInputMaps._head;
        if ( !v9 )
          break;
        v10 = v9->next;
        v6->m_data.m_listConflictingInputMaps._head = v10;
        if ( v10 )
          v10->prev = 0;
        else
          v6->m_data.m_listConflictingInputMaps._tail = 0;
        if ( v9 )
          operator delete(v9);
        --v6->m_data.m_listConflictingInputMaps._num_elements;
      }
      operator delete(v6);
    }
  }
}
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);

//----- (00684E60) --------------------------------------------------------  // acclient.c:668460
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::add(IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *this, HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *data)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v4; // eax@1
  unsigned int v5; // edx@6
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != data->m_hashKey )
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
      IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (00684EE0) --------------------------------------------------------  // acclient.c:668504
char __thiscall ActionMap::GetConflictingInputMaps(ActionMap *this, unsigned int i_eMapID, List<unsigned long> *o_listConflictingInputMaps)
{
  HashTableData<unsigned long,InputMapConflictsValue> *v3; // eax@1
  List<unsigned long> *v4; // esi@4
  char result; // al@4
  InputMapConflictsValue val; // [sp+4h] [bp-14h]@6

  v3 = this->m_hashConflictingMaps.m_intrusiveTable.m_buckets[i_eMapID
                                                            % this->m_hashConflictingMaps.m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != i_eMapID )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    val.m_eInputMap = 0;
    val.m_listConflictingInputMaps._head = 0;
    val.m_listConflictingInputMaps._tail = 0;
    val.m_listConflictingInputMaps._num_elements = 0;
    val.m_listConflictingInputMaps.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
    HashTable<unsigned long,InputMapConflictsValue,0>::find(&this->m_hashConflictingMaps, &i_eMapID, &val);
    AC1Legacy::List<unsigned long>::operator=(
      (List<SkillRecord *> *)o_listConflictingInputMaps,
      (int)&val.m_listConflictingInputMaps);
    val.m_listConflictingInputMaps.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
    List<SkillRecord *>::flush((List<SkillRecord *> *)&val.m_listConflictingInputMaps);
    result = 1;
  }
  else
  {
LABEL_4:
    v4 = o_listConflictingInputMaps;
    List<SkillRecord *>::flush((List<SkillRecord *> *)o_listConflictingInputMaps);
    List<PFileNode *>::push_back((List<UIElement_UIItem *> *)v4, (UIElement_UIItem *const *)&i_eMapID);
    result = 1;
  }
  return result;
}
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);

//----- (00684F90) --------------------------------------------------------  // acclient.c:668549
char __thiscall IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::push_tail(IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *this, HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *val)
{
  IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v3; // eax@1
  char result; // al@4

  v2 = this;
  v3 = v2->m_hash.m_buckets[val->m_hashKey % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != val->m_hashKey )
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
    IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::add(
      &this->m_hash,
      val);
    DLListBase::InsertAfter(&v2->m_list, (DLListData *)&val->dllist_next, v2->m_list.tail_);
    result = 1;
  }
  return result;
}

//----- (00684FF0) --------------------------------------------------------  // acclient.c:668582
void __cdecl SerializeHashTableData<int,unsigned long,InputMapConflictsValue,SB_Default,SB_Default>(const int *_class, HashTableData<unsigned long,InputMapConflictsValue> *io_object, Archive *io_archive)
{
  unsigned int *v3; // eax@1
  unsigned int *v4; // eax@5

  Archive::CheckAlignment(io_archive, 4u);
  v3 = (unsigned int *)Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *v3 = io_object->m_hashKey;
    else
      io_object->m_hashKey = *v3;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v4 = (unsigned int *)Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *v4 = io_object->m_data.m_eInputMap;
      List<unsigned long>::Serialize(&io_object->m_data.m_listConflictingInputMaps, io_archive);
      return;
    }
    io_object->m_data.m_eInputMap = *v4;
  }
  List<unsigned long>::Serialize(&io_object->m_data.m_listConflictingInputMaps, io_archive);
}

//----- (00685060) --------------------------------------------------------  // acclient.c:668612
HashTable<unsigned long,InputMapConflictsValue,0> *__thiscall HashTable<unsigned long,InputMapConflictsValue,0>::vector_deleting_destructor(HashTable<unsigned long,InputMapConflictsValue,0> *this, unsigned int a2)
{
  HashTable<unsigned long,InputMapConflictsValue,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,InputMapConflictsValue,0>Vtbl *)&HashTable<unsigned long,InputMapConflictsValue,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::vftable;
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
// 7FEE08: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::vftable[2])(void *, char);
// 7FEE0C: using guessed type int (__thiscall *HashTable<unsigned long,InputMapConflictsValue,0>::vftable)(void *, char);

//----- (006850C0) --------------------------------------------------------  // acclient.c:668638
void __thiscall IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::flush(IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *this)
{
  DLListData *v1; // eax@1
  DLListData *v2; // edx@2
  DLListData *v3; // edx@4
  bool v4; // zf@4
  DLListData *v5; // edx@8

  do
  {
    v1 = this->m_list.head_;
    if ( !v1 )
      break;
    v2 = v1->dllist_prev;
    if ( v2 )
    {
      v2->dllist_next = v1->dllist_next;
    }
    else
    {
      v3 = v1->dllist_next;
      v4 = v1->dllist_next == 0;
      this->m_list.head_ = v1->dllist_next;
      if ( !v4 )
        v3->dllist_prev = 0;
    }
    if ( v1->dllist_next )
    {
      v1->dllist_next->dllist_prev = v1->dllist_prev;
    }
    else
    {
      v5 = this->m_list.tail_->dllist_prev;
      this->m_list.tail_ = v5;
      if ( v5 )
        v5->dllist_next = 0;
    }
    v1->dllist_next = 0;
    v1->dllist_prev = 0;
  }
  while ( v1 );
  IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::clear((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)this);
}

//----- (00685120) --------------------------------------------------------  // acclient.c:668683
void __cdecl _SerializeIntrusiveHashList____HV__IntrusiveHashList_KPAUHashListData___HashList_KVActionMapValue___00___00__PAUHashListData___HashList_KVActionMapValue___00__USB_Default____YAXABHAAV__IntrusiveHashList_KPAUHashListData___HashList_KVActionMapValue___00___00__AAVArchive___Z(const int *_class, IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *io_object, Archive *io_archive)
{
  unsigned int v3; // ecx@0
  Archive *v4; // esi@1
  Archive *v5; // edi@5
  int v6; // edi@10
  DLListData *v7; // ecx@11
  unsigned int v8; // eax@16
  int v9; // edi@20
  unsigned int *v10; // edi@25
  unsigned int *v11; // eax@25
  unsigned int i; // ebp@27
  void *v13; // eax@28
  void *v14; // edi@29
  unsigned int v15; // eax@31
  unsigned int nBuckets; // [sp+0h] [bp-4h]@1

  nBuckets = v3;
  v4 = io_archive;
  if ( ~(unsigned __int8)(io_archive->m_flags >> 2) & 1 )
  {
    if ( ~LOBYTE(io_archive->m_flags) & 1 )
      IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::flush(io_object);
    nBuckets = io_object->m_hash.m_numBuckets;
    SB_As32Bit_Compressed::Serialize((const int *)&io_archive, &nBuckets, v4);
    io_archive = (Archive *)io_object->m_hash.m_numElements;
    SB_As32Bit_Compressed::Serialize((const int *)&io_archive, (unsigned int *)&io_archive, v4);
    if ( !((v4->m_flags >> 2) & 1) )
    {
      v5 = io_archive;
      if ( (signed int)(2 * nBuckets) < (signed int)io_archive
        || !(v4->m_flags & 5) && (unsigned int)v5 > Archive::GetSizeLeft(v4) )
        Archive::RaiseError(v4);
    }
    if ( (v4->m_flags & 5) == 1 )
    {
      v6 = 0;
      if ( io_object->m_hash.m_numElements > 0 )
      {
        v7 = io_object->m_list.head_;
        if ( v7 )
          v6 = (int)&v7[-1];
        else
          v6 = 0;
      }
      while ( ~(unsigned __int8)(v4->m_flags >> 2) & 1 )
      {
        if ( !v6 )
          break;
        Archive::CheckAlignment(v4, 4u);
        v8 = Archive::GetBytes(v4, 4u);
        if ( v8 )
        {
          if ( v4->m_flags & 1 )
            *(_DWORD *)v8 = *(_DWORD *)v6;
          else
            *(_DWORD *)v6 = *(_DWORD *)v8;
        }
        ActionMapValue::Serialize((ActionMapValue *)(v6 + 16), v4);
        v9 = *(_DWORD *)(v6 + 8);
        v6 = v9 ? v9 - 8 : 0;
      }
    }
    if ( !(v4->m_flags & 5) )
    {
      v10 = g_bucketSizesEnd;
      v11 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &nBuckets);
      if ( v11 == v10 )
        --v11;
      IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::resize_internal(
        &io_object->m_hash,
        *v11);
      for ( i = 0; i < (unsigned int)io_archive; ++i )
      {
        v13 = operator new(0x20u);
        if ( v13 )
        {
          *((_DWORD *)v13 + 1) = 0;
          *((_DWORD *)v13 + 2) = 0;
          *((_DWORD *)v13 + 3) = 0;
          *((_DWORD *)v13 + 4) = 0;
          *((_DWORD *)v13 + 5) = 0;
          *((_DWORD *)v13 + 6) = 0;
          *((_DWORD *)v13 + 7) = 0;
          v14 = v13;
        }
        else
        {
          v14 = 0;
        }
        Archive::CheckAlignment(v4, 4u);
        v15 = Archive::GetBytes(v4, 4u);
        if ( v15 )
        {
          if ( v4->m_flags & 1 )
            *(_DWORD *)v15 = *(_DWORD *)v14;
          else
            *(_DWORD *)v14 = *(_DWORD *)v15;
        }
        ActionMapValue::Serialize((ActionMapValue *)v14 + 1, v4);
        if ( (v4->m_flags >> 2) & 1 )
          break;
        IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::push_tail(
          io_object,
          (HashList<unsigned long,ActionMapValue,1>::HashListData *)v14);
      }
    }
  }
}

//----- (00685300) --------------------------------------------------------  // acclient.c:668794
char __thiscall HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::find(HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1> *this, const unsigned int *key, HashList<unsigned long,ActionMapValue,1> *data)
{
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v3; // eax@1
  char result; // al@4

  v3 = this->m_ihlIntrusive.m_hash.m_buckets[*key % this->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != *key )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    HashList<unsigned long,ActionMapValue,1>::operator=(data, (int)&v3->m_data);
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00685350) --------------------------------------------------------  // acclient.c:668822
unsigned int __thiscall ActionMap::GetToggleType(ActionMap *this, unsigned int i_eAction, unsigned int i_eMapID)
{
  ActionMap *v3; // esi@1
  unsigned int result; // eax@5
  ActionMapValue value; // [sp+0h] [bp-88h]@2
  HashList<unsigned long,ActionMapValue,1> hashActions; // [sp+10h] [bp-78h]@1

  v3 = this;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>(
    &hashActions.m_ihlIntrusive.m_hash,
    0);
  hashActions.m_ihlIntrusive.m_list.head_ = 0;
  hashActions.m_ihlIntrusive.m_list.tail_ = 0;
  if ( HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::find(
         &v3->m_hashInputMaps,
         &i_eMapID,
         &hashActions)
    && (value.m_eToggleType = 0, HashList<unsigned long,ActionMapValue,1>::find(&hashActions, &i_eAction, &value)) )
  {
    IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents(&hashActions.m_ihlIntrusive);
    hashActions.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
    if ( (HashList<unsigned long,ActionMapValue,1>::HashListData **)hashActions.m_ihlIntrusive.m_hash.m_buckets != hashActions.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
      operator delete[](hashActions.m_ihlIntrusive.m_hash.m_buckets);
    result = value.m_eToggleType;
  }
  else
  {
    IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents(&hashActions.m_ihlIntrusive);
    hashActions.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
    if ( (HashList<unsigned long,ActionMapValue,1>::HashListData **)hashActions.m_ihlIntrusive.m_hash.m_buckets != hashActions.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
      operator delete[](hashActions.m_ihlIntrusive.m_hash.m_buckets);
    result = 0;
  }
  return result;
}
// 7BE66C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable[4])(void *, char);

//----- (00685420) --------------------------------------------------------  // acclient.c:668860
char __thiscall ActionMap::IsActionAllowedInInputMap(ActionMap *this, unsigned int i_eAction, unsigned int i_eMapID)
{
  ActionMap *v3; // esi@1
  char result; // al@1
  bool v5; // bl@3
  HashList<unsigned long,ActionMapValue,1> hashActions; // [sp+4h] [bp-78h]@2

  v3 = this;
  result = 1;
  if ( i_eAction != 1 )
  {
    IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>(
      &hashActions.m_ihlIntrusive.m_hash,
      0);
    hashActions.m_ihlIntrusive.m_list.head_ = 0;
    hashActions.m_ihlIntrusive.m_list.tail_ = 0;
    if ( HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::find(
           &v3->m_hashInputMaps,
           &i_eMapID,
           &hashActions) )
    {
      v5 = IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::contains(
             (IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *)&hashActions,
             (UIObject *const *)&i_eAction);
      IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents(&hashActions.m_ihlIntrusive);
      hashActions.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
      if ( (HashList<unsigned long,ActionMapValue,1>::HashListData **)hashActions.m_ihlIntrusive.m_hash.m_buckets != hashActions.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
        operator delete[](hashActions.m_ihlIntrusive.m_hash.m_buckets);
      result = v5;
    }
    else
    {
      IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents(&hashActions.m_ihlIntrusive);
      hashActions.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
      if ( (HashList<unsigned long,ActionMapValue,1>::HashListData **)hashActions.m_ihlIntrusive.m_hash.m_buckets != hashActions.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
        operator delete[](hashActions.m_ihlIntrusive.m_hash.m_buckets);
      result = 0;
    }
  }
  return result;
}
// 7BE66C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable[4])(void *, char);

//----- (006854E0) --------------------------------------------------------  // acclient.c:668904
char __thiscall ActionMap::IsUserBindable(ActionMap *this, unsigned int i_eAction, unsigned int i_eMapID)
{
  ActionMap *v3; // esi@1
  char v4; // bl@1
  char result; // al@8
  ActionMapValue val; // [sp+8h] [bp-88h]@2
  HashList<unsigned long,ActionMapValue,1> hashActions; // [sp+18h] [bp-78h]@1

  v3 = this;
  v4 = 0;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>(
    &hashActions.m_ihlIntrusive.m_hash,
    0);
  hashActions.m_ihlIntrusive.m_list.head_ = 0;
  hashActions.m_ihlIntrusive.m_list.tail_ = 0;
  if ( HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::find(
         &v3->m_hashInputMaps,
         &i_eMapID,
         &hashActions)
    && (val.m_userBindingData.m_eActionClass = 0,
        val.m_userBindingData.m_action_name = 0,
        HashList<unsigned long,ActionMapValue,1>::find(&hashActions, &i_eAction, &val)) )
  {
    if ( val.m_userBindingData.m_eActionClass && val.m_userBindingData.m_action_name )
      v4 = 1;
    IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents(&hashActions.m_ihlIntrusive);
    hashActions.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
    if ( (HashList<unsigned long,ActionMapValue,1>::HashListData **)hashActions.m_ihlIntrusive.m_hash.m_buckets != hashActions.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
      operator delete[](hashActions.m_ihlIntrusive.m_hash.m_buckets);
    result = v4;
  }
  else
  {
    IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents(&hashActions.m_ihlIntrusive);
    hashActions.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
    if ( (HashList<unsigned long,ActionMapValue,1>::HashListData **)hashActions.m_ihlIntrusive.m_hash.m_buckets != hashActions.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
      operator delete[](hashActions.m_ihlIntrusive.m_hash.m_buckets);
    result = 0;
  }
  return result;
}
// 7BE66C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable[4])(void *, char);

//----- (006855C0) --------------------------------------------------------  // acclient.c:668948
unsigned int __thiscall ActionMap::GetActionClass(ActionMap *this, unsigned int i_eAction, unsigned int i_eMapID)
{
  ActionMap *v3; // esi@1
  unsigned int result; // eax@5
  ActionMapValue val; // [sp+0h] [bp-88h]@2
  HashList<unsigned long,ActionMapValue,1> hashActions; // [sp+10h] [bp-78h]@1

  v3 = this;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>(
    &hashActions.m_ihlIntrusive.m_hash,
    0);
  hashActions.m_ihlIntrusive.m_list.head_ = 0;
  hashActions.m_ihlIntrusive.m_list.tail_ = 0;
  if ( HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::find(
         &v3->m_hashInputMaps,
         &i_eMapID,
         &hashActions)
    && (val.m_userBindingData.m_eActionClass = 0,
        HashList<unsigned long,ActionMapValue,1>::find(&hashActions, &i_eAction, &val)) )
  {
    IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents(&hashActions.m_ihlIntrusive);
    hashActions.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
    if ( (HashList<unsigned long,ActionMapValue,1>::HashListData **)hashActions.m_ihlIntrusive.m_hash.m_buckets != hashActions.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
      operator delete[](hashActions.m_ihlIntrusive.m_hash.m_buckets);
    result = val.m_userBindingData.m_eActionClass;
  }
  else
  {
    IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents(&hashActions.m_ihlIntrusive);
    hashActions.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
    if ( (HashList<unsigned long,ActionMapValue,1>::HashListData **)hashActions.m_ihlIntrusive.m_hash.m_buckets != hashActions.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
      operator delete[](hashActions.m_ihlIntrusive.m_hash.m_buckets);
    result = 0;
  }
  return result;
}
// 7BE66C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable[4])(void *, char);

//----- (00685690) --------------------------------------------------------  // acclient.c:668987
char __thiscall ActionMap::GetDescripValues(ActionMap *this, unsigned int i_eAction, unsigned int i_eMapID, PStringBase<unsigned short> *o_strName, PStringBase<unsigned short> *o_strDescrip)
{
  ActionMap *v5; // esi@1
  char v6; // bl@3
  char result; // al@5
  ActionMapValue val; // [sp+8h] [bp-88h]@2
  HashList<unsigned long,ActionMapValue,1> hashActions; // [sp+18h] [bp-78h]@1

  v5 = this;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>(
    &hashActions.m_ihlIntrusive.m_hash,
    0);
  hashActions.m_ihlIntrusive.m_list.head_ = 0;
  hashActions.m_ihlIntrusive.m_list.tail_ = 0;
  if ( HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::find(
         &v5->m_hashInputMaps,
         &i_eMapID,
         &hashActions)
    && (val.m_eToggleType = 0,
        val.m_userBindingData.m_eActionClass = 0,
        val.m_userBindingData.m_action_name = 0,
        val.m_userBindingData.m_description = 0,
        HashList<unsigned long,ActionMapValue,1>::find(&hashActions, &i_eAction, &val)) )
  {
    v6 = ActionMapValue::GetDescriptionValues(&val, v5->m_didStringTable, o_strName, o_strDescrip);
    IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents(&hashActions.m_ihlIntrusive);
    hashActions.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
    if ( (HashList<unsigned long,ActionMapValue,1>::HashListData **)hashActions.m_ihlIntrusive.m_hash.m_buckets != hashActions.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
      operator delete[](hashActions.m_ihlIntrusive.m_hash.m_buckets);
    result = v6;
  }
  else
  {
    IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents(&hashActions.m_ihlIntrusive);
    hashActions.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
    if ( (HashList<unsigned long,ActionMapValue,1>::HashListData **)hashActions.m_ihlIntrusive.m_hash.m_buckets != hashActions.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
      operator delete[](hashActions.m_ihlIntrusive.m_hash.m_buckets);
    result = 0;
  }
  return result;
}
// 7BE66C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable[4])(void *, char);

//----- (00685790) --------------------------------------------------------  // acclient.c:669031
void __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::delete_contents(IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *this)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *v1; // edi@1
  int v2; // ecx@2
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **v3; // eax@3
  int v4; // eax@4
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **v5; // edx@5
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v6; // ebx@5
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v7; // eax@7
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v8; // ecx@8
  void *v9; // eax@13

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **)v2 )
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
        v1->m_firstInterestingBucket = (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **)v4;
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
      IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents(&v6->m_data.m_ihlIntrusive);
      v9 = v6->m_data.m_ihlIntrusive.m_hash.m_buckets;
      v6->m_data.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
      if ( v9 != v6->m_data.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
        operator delete[](v9);
      v6->m_data.m_ihlIntrusive.m_hash.m_buckets = 0;
      v6->m_data.m_ihlIntrusive.m_hash.m_firstInterestingBucket = 0;
      v6->m_data.m_ihlIntrusive.m_hash.m_numBuckets = 0;
      v6->m_data.m_ihlIntrusive.m_hash.m_numElements = 0;
      operator delete(v6);
    }
  }
}
// 7BE66C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable[4])(void *, char);

//----- (00685840) --------------------------------------------------------  // acclient.c:669101
void __cdecl SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>,HashTableData<unsigned long,InputMapConflictsValue> *,SB_Default>(const int *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0> *io_object, Archive *io_archive)
{
  Archive *v3; // ebp@1
  unsigned int *v4; // esi@4
  unsigned int *v5; // edi@4
  const unsigned int *v6; // eax@4
  int v7; // ebx@6
  unsigned int v8; // eax@8
  HashTableData<unsigned long,InputMapConflictsValue> *v9; // esi@8
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // eax@19
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v11; // ebx@19
  HashTableData<unsigned long,HeritageGroup_CG> *v12; // edi@19
  HashTableData<unsigned long,HeritageGroup_CG> **v13; // esi@19
  unsigned int v14; // eax@27
  HashTableData<unsigned long,Sex_CG> *v15; // ebx@28
  unsigned int v16; // edi@28
  void *v17; // eax@31
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
  v9 = 0;
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
    v10 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
            (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)io_object,
            &result);
    v11 = v10->m_currHashTable;
    v12 = v10->m_currElement;
    v13 = v10->m_currBucket;
LABEL_20:
    while ( v12 )
    {
      do
      {
        SerializeHashTableData<int,unsigned long,InputMapConflictsValue,SB_Default,SB_Default>(
          (const int *)&io_archive,
          (HashTableData<unsigned long,InputMapConflictsValue> *)v12,
          v3);
        v12 = v12->m_hashNext;
      }
      while ( v12 );
      while ( 1 )
      {
        ++v13;
        if ( v13 == &v11->m_buckets[v11->m_numBuckets] )
          break;
        if ( *v13 )
        {
          v12 = *v13;
          goto LABEL_20;
        }
      }
    }
    v9 = 0;
  }
  if ( !(v3->m_flags & 5) )
  {
    v14 = Archive::GetSizeLeft(v3);
    if ( (unsigned int)io_archive > v14 )
    {
LABEL_37:
      Archive::RaiseError(v3);
    }
    else
    {
      v15 = 0;
      v16 = 0;
      if ( (unsigned int)io_archive > 0 )
      {
        while ( 1 )
        {
          v17 = operator new(0x1Cu);
          if ( v17 )
          {
            *((_DWORD *)v17 + 1) = 0;
            *((_DWORD *)v17 + 2) = 0;
            *((_DWORD *)v17 + 4) = 0;
            *((_DWORD *)v17 + 5) = 0;
            *((_DWORD *)v17 + 6) = 0;
            *((_DWORD *)v17 + 3) = List<unsigned long>::vftable;
            v9 = (HashTableData<unsigned long,InputMapConflictsValue> *)v17;
          }
          SerializeHashTableData<int,unsigned long,InputMapConflictsValue,SB_Default,SB_Default>(
            (const int *)&io_archive,
            v9,
            v3);
          if ( (v3->m_flags >> 2) & 1 )
            break;
          if ( !IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
                  (HashTableData<unsigned long,Sex_CG> *)v9,
                  v15) )
            goto LABEL_37;
          ++v16;
          v15 = (HashTableData<unsigned long,Sex_CG> *)v9;
          if ( v16 >= (unsigned int)io_archive )
            break;
          v9 = 0;
        }
      }
    }
  }
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);

//----- (00685A20) --------------------------------------------------------  // acclient.c:669245
void __thiscall HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::flush(HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1> *this)
{
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1> *v1; // ebp@1
  int v2; // ebx@2
  DLListData *v3; // eax@3
  DLListData *v4; // ecx@4
  DLListData *v5; // ecx@6
  bool v6; // zf@6
  DLListData *v7; // ecx@10
  int v8; // edx@14
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData **v9; // eax@14
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v10; // ecx@14
  int v11; // edi@14
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v12; // eax@14
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v13; // edx@20
  void *v14; // eax@25

  v1 = this;
  while ( 1 )
  {
    v2 = 0;
    if ( !v1->m_ihlIntrusive.m_hash.m_numElements )
      break;
    v3 = v1->m_ihlIntrusive.m_list.head_;
    if ( v3 )
    {
      v4 = v3->dllist_prev;
      if ( v4 )
      {
        v4->dllist_next = v3->dllist_next;
      }
      else
      {
        v5 = v3->dllist_next;
        v6 = v3->dllist_next == 0;
        v1->m_ihlIntrusive.m_list.head_ = v3->dllist_next;
        if ( !v6 )
          v5->dllist_prev = 0;
      }
      if ( v3->dllist_next )
      {
        v3->dllist_next->dllist_prev = v3->dllist_prev;
      }
      else
      {
        v7 = v1->m_ihlIntrusive.m_list.tail_->dllist_prev;
        v1->m_ihlIntrusive.m_list.tail_ = v7;
        if ( v7 )
          v7->dllist_next = 0;
      }
      v3->dllist_next = 0;
      v3->dllist_prev = 0;
      if ( v3 )
        v2 = (int)&v3[-1];
    }
    v8 = *(_DWORD *)v2 % v1->m_ihlIntrusive.m_hash.m_numBuckets;
    v9 = v1->m_ihlIntrusive.m_hash.m_buckets;
    v10 = v9[v8];
    v11 = (int)&v9[v8];
    v12 = v9[v8];
    if ( v12 )
    {
      while ( v12->m_hashKey != *(_DWORD *)v2 )
      {
        v12 = v12->m_hashNext;
        if ( !v12 )
          goto LABEL_25;
      }
      if ( v12 )
      {
        if ( v10 == v12 )
          goto LABEL_30;
        do
        {
          v13 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v12 );
        if ( v13 )
          v13->m_hashNext = v10->m_hashNext;
        else
LABEL_30:
          *(_DWORD *)v11 = v10->m_hashNext;
        --v1->m_ihlIntrusive.m_hash.m_numElements;
      }
    }
LABEL_25:
    IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents((IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *)(v2 + 16));
    v14 = *(void **)(v2 + 112);
    *(_DWORD *)(v2 + 16) = IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
    if ( v14 != (void *)(v2 + 20) )
      operator delete[](v14);
    *(_DWORD *)(v2 + 112) = 0;
    *(_DWORD *)(v2 + 116) = 0;
    *(_DWORD *)(v2 + 120) = 0;
    *(_DWORD *)(v2 + 124) = 0;
    operator delete((void *)v2);
  }
}
// 7BE66C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable[4])(void *, char);

//----- (00685B20) --------------------------------------------------------  // acclient.c:669347
void __thiscall IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::delete_contents(IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *this)
{
  DLListData *v1; // eax@1
  DLListData *v2; // edx@2
  DLListData *v3; // edx@4
  bool v4; // zf@4
  DLListData *v5; // edx@8

  do
  {
    v1 = this->m_list.head_;
    if ( !v1 )
      break;
    v2 = v1->dllist_prev;
    if ( v2 )
    {
      v2->dllist_next = v1->dllist_next;
    }
    else
    {
      v3 = v1->dllist_next;
      v4 = v1->dllist_next == 0;
      this->m_list.head_ = v1->dllist_next;
      if ( !v4 )
        v3->dllist_prev = 0;
    }
    if ( v1->dllist_next )
    {
      v1->dllist_next->dllist_prev = v1->dllist_prev;
    }
    else
    {
      v5 = this->m_list.tail_->dllist_prev;
      this->m_list.tail_ = v5;
      if ( v5 )
        v5->dllist_next = 0;
    }
    v1->dllist_next = 0;
    v1->dllist_prev = 0;
  }
  while ( v1 );
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::delete_contents(&this->m_hash);
}

//----- (00685B80) --------------------------------------------------------  // acclient.c:669392
void __thiscall ActionMap::Destroy(ActionMap *this)
{
  this->m_didStringTable.id = stru_8F7B88.id;
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::flush(&this->m_hashInputMaps);
}

//----- (00685BA0) --------------------------------------------------------  // acclient.c:669399
void __thiscall ActionMap::ActionMap(ActionMap *this)
{
  ActionMap *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_8F7B88);
  v1->vfptr = (InterfaceVtbl *)&ActionMap::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>(
    &v1->m_hashInputMaps.m_ihlIntrusive.m_hash,
    0);
  v1->m_hashInputMaps.m_ihlIntrusive.m_list.head_ = 0;
  v1->m_hashInputMaps.m_ihlIntrusive.m_list.tail_ = 0;
  v1->m_didStringTable.id = stru_8F7B88.id;
  v1->m_hashConflictingMaps.vfptr = (HashTable<unsigned long,InputMapConflictsValue,0>Vtbl *)&HashTable<unsigned long,InputMapConflictsValue,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>(
    &v1->m_hashConflictingMaps.m_intrusiveTable,
    0x17u);
}
// 7FEE0C: using guessed type int (__thiscall *HashTable<unsigned long,InputMapConflictsValue,0>::vftable)(void *, char);
// 7FEE10: using guessed type __int32 (__stdcall *ActionMap::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00685C00) --------------------------------------------------------  // acclient.c:669421
signed int ActionMap::GetDBOType()
{
  return 39;
}

//----- (00685C10) --------------------------------------------------------  // acclient.c:669427
void __thiscall ActionMap::~ActionMap(ActionMap *this)
{
  ActionMap *v1; // edi@1
  char *v2; // esi@1
  void *v3; // eax@1
  void *v4; // eax@3

  v1 = this;
  v2 = (char *)&this->m_hashConflictingMaps.m_intrusiveTable;
  this->vfptr = (InterfaceVtbl *)&ActionMap::vftable;
  this->m_hashConflictingMaps.vfptr = (HashTable<unsigned long,InputMapConflictsValue,0>Vtbl *)&HashTable<unsigned long,InputMapConflictsValue,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::delete_contents(&this->m_hashConflictingMaps.m_intrusiveTable);
  v3 = (void *)*((_DWORD *)v2 + 24);
  *(_DWORD *)v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::vftable;
  if ( v3 != v2 + 4 )
    operator delete[](v3);
  *((_DWORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 25) = 0;
  *((_DWORD *)v2 + 26) = 0;
  *((_DWORD *)v2 + 27) = 0;
  IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::delete_contents(&v1->m_hashInputMaps.m_ihlIntrusive);
  v4 = v1->m_hashInputMaps.m_ihlIntrusive.m_hash.m_buckets;
  v1->m_hashInputMaps.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::vftable;
  if ( v4 != v1->m_hashInputMaps.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
    operator delete[](v4);
  v1->m_hashInputMaps.m_ihlIntrusive.m_hash.m_buckets = 0;
  v1->m_hashInputMaps.m_ihlIntrusive.m_hash.m_firstInterestingBucket = 0;
  v1->m_hashInputMaps.m_ihlIntrusive.m_hash.m_numBuckets = 0;
  v1->m_hashInputMaps.m_ihlIntrusive.m_hash.m_numElements = 0;
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 7FEE04: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::vftable[3])(void *, char);
// 7FEE08: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::vftable[2])(void *, char);
// 7FEE0C: using guessed type int (__thiscall *HashTable<unsigned long,InputMapConflictsValue,0>::vftable)(void *, char);
// 7FEE10: using guessed type __int32 (__stdcall *ActionMap::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00685CB0) --------------------------------------------------------  // acclient.c:669464
ActionMap *__thiscall ActionMap::vector_deleting_destructor(ActionMap *this, unsigned int a2)
{
  ActionMap *v2; // esi@1

  v2 = this;
  ActionMap::~ActionMap(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00685CD0) --------------------------------------------------------  // acclient.c:669476
void __cdecl Serializer::SerializeObject(HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *io_object, Archive *io_archive)
{
  Archive *v2; // esi@1
  unsigned int *v3; // eax@1
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v4; // ecx@1
  IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *v5; // ST04_4@3

  v2 = io_archive;
  Archive::CheckAlignment(io_archive, 4u);
  v3 = (unsigned int *)Archive::GetBytes(v2, 4u);
  v4 = io_object;
  if ( v3 )
  {
    if ( v2->m_flags & 1 )
    {
      v5 = &io_object->m_data.m_ihlIntrusive;
      *v3 = io_object->m_hashKey;
      _SerializeIntrusiveHashList____HV__IntrusiveHashList_KPAUHashListData___HashList_KVActionMapValue___00___00__PAUHashListData___HashList_KVActionMapValue___00__USB_Default____YAXABHAAV__IntrusiveHashList_KPAUHashListData___HashList_KVActionMapValue___00___00__AAVArchive___Z(
        (const int *)&io_object,
        v5,
        v2);
      return;
    }
    io_object->m_hashKey = *v3;
  }
  _SerializeIntrusiveHashList____HV__IntrusiveHashList_KPAUHashListData___HashList_KVActionMapValue___00___00__PAUHashListData___HashList_KVActionMapValue___00__USB_Default____YAXABHAAV__IntrusiveHashList_KPAUHashListData___HashList_KVActionMapValue___00___00__AAVArchive___Z(
    (const int *)&io_object,
    &v4->m_data.m_ihlIntrusive,
    v2);
}

//----- (00685D30) --------------------------------------------------------  // acclient.c:669508
void __cdecl _SerializeIntrusiveHashList____HV__IntrusiveHashList_KPAUHashListData___HashList_KV__HashList_KVActionMapValue___00___00___00__PAUHashListData___HashList_KV__HashList_KVActionMapValue___00___00__USB_Default____YAXABHAAV__IntrusiveHashList_KPAUHashListData___HashList_KV__HashList_KVActionMapValue___00___00___00__AAVArchive___Z(const int *_class, IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *io_object, Archive *io_archive)
{
  unsigned int v3; // ecx@0
  Archive *v4; // edi@1
  Archive *v5; // esi@5
  int v6; // esi@10
  DLListData *v7; // eax@11
  int v8; // esi@16
  unsigned int *v9; // esi@21
  unsigned int *v10; // eax@21
  unsigned int i; // ebx@23
  void *v12; // eax@24
  void *v13; // esi@24
  unsigned int v14; // eax@27
  unsigned int nBuckets; // [sp+0h] [bp-4h]@1

  nBuckets = v3;
  v4 = io_archive;
  if ( ~(unsigned __int8)(io_archive->m_flags >> 2) & 1 )
  {
    if ( ~LOBYTE(io_archive->m_flags) & 1 )
      IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::flush((IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *)io_object);
    nBuckets = io_object->m_hash.m_numBuckets;
    SB_As32Bit_Compressed::Serialize((const int *)&io_archive, &nBuckets, v4);
    io_archive = (Archive *)io_object->m_hash.m_numElements;
    SB_As32Bit_Compressed::Serialize((const int *)&io_archive, (unsigned int *)&io_archive, v4);
    if ( !((v4->m_flags >> 2) & 1) )
    {
      v5 = io_archive;
      if ( (signed int)(2 * nBuckets) < (signed int)io_archive
        || !(v4->m_flags & 5) && (unsigned int)v5 > Archive::GetSizeLeft(v4) )
        Archive::RaiseError(v4);
    }
    if ( (v4->m_flags & 5) == 1 )
    {
      v6 = 0;
      if ( io_object->m_hash.m_numElements > 0 )
      {
        v7 = io_object->m_list.head_;
        if ( v7 )
          v6 = (int)&v7[-1];
        else
          v6 = 0;
      }
      while ( ~(unsigned __int8)(v4->m_flags >> 2) & 1 )
      {
        if ( !v6 )
          break;
        Serializer::SerializeObject(
          (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *)v6,
          v4);
        v8 = *(_DWORD *)(v6 + 8);
        v6 = v8 ? v8 - 8 : 0;
      }
    }
    if ( !(v4->m_flags & 5) )
    {
      v9 = g_bucketSizesEnd;
      v10 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &nBuckets);
      if ( v10 == v9 )
        --v10;
      IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::resize_internal(
        &io_object->m_hash,
        *v10);
      for ( i = 0; i < (unsigned int)io_archive; ++i )
      {
        v12 = operator new(0x88u);
        v13 = v12;
        if ( v12 )
        {
          *((_DWORD *)v12 + 1) = 0;
          *((_DWORD *)v12 + 2) = 0;
          *((_DWORD *)v12 + 3) = 0;
          IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>(
            (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *)((char *)v12 + 16),
            0);
          *((_DWORD *)v13 + 32) = 0;
          *((_DWORD *)v13 + 33) = 0;
        }
        else
        {
          v13 = 0;
        }
        Archive::CheckAlignment(v4, 4u);
        v14 = Archive::GetBytes(v4, 4u);
        if ( v14 )
        {
          if ( v4->m_flags & 1 )
            *(_DWORD *)v14 = *(_DWORD *)v13;
          else
            *(_DWORD *)v13 = *(_DWORD *)v14;
        }
        _SerializeIntrusiveHashList____HV__IntrusiveHashList_KPAUHashListData___HashList_KVActionMapValue___00___00__PAUHashListData___HashList_KVActionMapValue___00__USB_Default____YAXABHAAV__IntrusiveHashList_KPAUHashListData___HashList_KVActionMapValue___00___00__AAVArchive___Z(
          (const int *)&io_archive,
          (IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *)((char *)v13 + 16),
          v4);
        if ( (v4->m_flags >> 2) & 1 )
          break;
        IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::push_tail(
          io_object,
          (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *)v13);
      }
    }
  }
}

//----- (00685F10) --------------------------------------------------------  // acclient.c:669615
void __thiscall ActionMap::Serialize(ActionMap *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  ActionMap *v3; // edi@1
  unsigned int v4; // eax@1

  v2 = io_archive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  _SerializeIntrusiveHashList____HV__IntrusiveHashList_KPAUHashListData___HashList_KV__HashList_KVActionMapValue___00___00___00__PAUHashListData___HashList_KV__HashList_KVActionMapValue___00___00__USB_Default____YAXABHAAV__IntrusiveHashList_KPAUHashListData___HashList_KV__HashList_KVActionMapValue___00___00___00__AAVArchive___Z(
    (const int *)&io_archive,
    &v3->m_hashInputMaps.m_ihlIntrusive,
    v2);
  Archive::CheckAlignment(v2, 4u);
  v4 = Archive::GetBytes(v2, 4u);
  if ( v4 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v4 = v3->m_didStringTable.id;
    else
      v3->m_didStringTable.id = *(_DWORD *)v4;
  }
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::delete_contents(&v3->m_hashConflictingMaps.m_intrusiveTable);
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>,HashTableData<unsigned long,InputMapConflictsValue> *,SB_Default>(
    (const int *)&io_archive,
    &v3->m_hashConflictingMaps.m_intrusiveTable,
    v2);
}

//----- (00715810) --------------------------------------------------------  // acclient.c:808508
int sub_715810()
{
  return atexit(nullsub_232);
}

//----- (00715820) --------------------------------------------------------  // acclient.c:808514
int _E76_97()
{
  return atexit(nullsub_233);
}

//----- (00715830) --------------------------------------------------------  // acclient.c:808520
int _E79_90()
{
  return atexit(_E80_87);
}

//----- (00715840) --------------------------------------------------------  // acclient.c:808526
int _E82_54()
{
  PStringBase<char>::PStringBase<char>(&KW_INPUTMAPCONFLICTS, "InputMapConflicts");
  return atexit(_E83_52);
}

//----- (00715860) --------------------------------------------------------  // acclient.c:808533
int _E85_39()
{
  PStringBase<char>::PStringBase<char>(&KW_ACTIONMAPS, "ActionMaps");
  return atexit(_E86_32);
}

//----- (00715880) --------------------------------------------------------  // acclient.c:808540
int _E88_29()
{
  PStringBase<char>::PStringBase<char>(&KW_TOGGLETYPE, "ToggleType");
  return atexit(_E89_42);
}

//----- (007158A0) --------------------------------------------------------  // acclient.c:808547
int sub_7158A0()
{
  PStringBase<char>::PStringBase<char>(&KW_USERBINDING, "UserBinding");
  return atexit(_E92_47);
}

//----- (007158C0) --------------------------------------------------------  // acclient.c:808554
int _E94_38()
{
  PStringBase<char>::PStringBase<char>(&KW_CATEGORY, "Category");
  return atexit(sub_77F8C0);
}

//----- (007158E0) --------------------------------------------------------  // acclient.c:808561
int sub_7158E0()
{
  PStringBase<char>::PStringBase<char>(&KW_DESCRIPTION, "Description");
  return atexit(sub_77F8F0);
}

//----- (00715900) --------------------------------------------------------  // acclient.c:808568
int sub_715900()
{
  PStringBase<char>::PStringBase<char>(&KW_NAME, "Name");
  return atexit(sub_77F920);
}

//----- (00715920) --------------------------------------------------------  // acclient.c:808575
int sub_715920()
{
  PStringBase<char>::PStringBase<char>(&KW_ABOUT, "About");
  return atexit(sub_77F950);
}

//----- (00715940) --------------------------------------------------------  // acclient.c:808582
int sub_715940()
{
  return atexit(nullsub_231);
}

//----- (0077F800) --------------------------------------------------------  // acclient.c:918116
void __cdecl _E83_52()
{
  char *v0; // esi@1

  v0 = &KW_INPUTMAPCONFLICTS.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_INPUTMAPCONFLICTS.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077F830) --------------------------------------------------------  // acclient.c:918129
void __cdecl _E86_32()
{
  char *v0; // esi@1

  v0 = &KW_ACTIONMAPS.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ACTIONMAPS.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077F860) --------------------------------------------------------  // acclient.c:918142
void __cdecl _E89_42()
{
  char *v0; // esi@1

  v0 = &KW_TOGGLETYPE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOGGLETYPE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077F890) --------------------------------------------------------  // acclient.c:918155
void __cdecl _E92_47()
{
  char *v0; // esi@1

  v0 = &KW_USERBINDING.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_USERBINDING.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077F8C0) --------------------------------------------------------  // acclient.c:918168
void __cdecl sub_77F8C0()
{
  char *v0; // esi@1

  v0 = &KW_CATEGORY.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CATEGORY.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077F8F0) --------------------------------------------------------  // acclient.c:918181
void __cdecl sub_77F8F0()
{
  char *v0; // esi@1

  v0 = &KW_DESCRIPTION.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DESCRIPTION.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077F920) --------------------------------------------------------  // acclient.c:918194
void __cdecl sub_77F920()
{
  char *v0; // esi@1

  v0 = &KW_NAME.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NAME.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077F950) --------------------------------------------------------  // acclient.c:918207
void __cdecl sub_77F950()
{
  char *v0; // esi@1

  v0 = &KW_ABOUT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ABOUT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

