/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : StringInfo
   Object     : ENGINE\stringtable\StringInfo.obj
   Functions  : 62
   Addresses  : 00415BB0 - 00728350 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00415BB0) --------------------------------------------------------  // acclient.c:82220
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned long,PStringBase<unsigned short> > **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,PStringBase<unsigned short> > **v5; // edx@5
  HashTableData<unsigned long,PStringBase<unsigned short> > *v6; // ebx@5
  HashTableData<unsigned long,PStringBase<unsigned short> > *v7; // eax@7
  HashTableData<unsigned long,PStringBase<unsigned short> > *v8; // ecx@8
  int v9; // edi@13

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,PStringBase<unsigned short> > **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,PStringBase<unsigned short> > **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_20;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_20:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      v9 = (int)&v6->m_data.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) )
      {
        if ( v9 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      }
      operator delete(v6);
    }
  }
}

//----- (004299D0) --------------------------------------------------------  // acclient.c:102346
HashIterator<unsigned long,StringInfoData *,0> *__thiscall HashTable<unsigned long,BaseProperty,1>::begin(HashTable<unsigned long,StringInfoData *,0> *this, HashIterator<unsigned long,StringInfoData *,0> *result)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> v4; // [sp+0h] [bp-Ch]@1

  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_intrusiveTable,
         &v4);
  result->m_iter.m_currHashTable = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *)v2->m_currHashTable;
  result->m_iter.m_currBucket = (HashTableData<unsigned long,StringInfoData *> **)v2->m_currBucket;
  result->m_iter.m_currElement = (HashTableData<unsigned long,StringInfoData *> *)v2->m_currElement;
  return result;
}

//----- (0042C660) --------------------------------------------------------  // acclient.c:105556
bool __thiscall PStringBase<unsigned short>::operator==(PStringBase<unsigned short> *this, PStringBase<unsigned short> *rhs)
{
  PSRefBufferCharData<unsigned short> *v2; // ecx@1
  int v3; // eax@2
  int v4; // esi@2
  int v5; // eax@5

  v2 = this->m_charbuffer;
  if ( *(_DWORD *)&v2[-1].m_data[14] == *(_DWORD *)&rhs->m_charbuffer[-1].m_data[14]
    && ((v3 = *(_DWORD *)&v2[-1].m_data[12], v4 = *(_DWORD *)&rhs->m_charbuffer[-1].m_data[12], v3 == v4)
     || v3 == -1
     || v4 == -1) )
    v5 = _wcscmp(v2->m_data, rhs->m_charbuffer->m_data) == 0;
  else
    LOBYTE(v5) = 0;
  return v5;
}

//----- (0042C6A0) --------------------------------------------------------  // acclient.c:105575
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *v2; // esi@1
  HashTableData<unsigned long,StringInfoData *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::vftable;
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
// 797D68: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::vftable[2])(void *, char);

//----- (0042C6E0) --------------------------------------------------------  // acclient.c:105596
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *v2; // esi@1
  HashTableData<unsigned long,PStringBase<unsigned short> > **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>::vftable;
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
// 797D6C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>::vftable)(void *, char);

//----- (0042C720) --------------------------------------------------------  // acclient.c:105617
void __thiscall StringInfo::SetTableEnum(StringInfo *this, int _strtableEnum)
{
  StringInfo *v2; // edi@1
  unsigned int v3; // esi@1

  v2 = this;
  v3 = DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&_strtableEnum, _strtableEnum, 4)->id;
  if ( MasterDBMap::DivineType((IDClass<_tagDataID,32,0>)v3) == 37 )
    v2->m_tableID.id = v3;
  else
    v2->m_tableID.id = INVALID_DID_23.id;
}

//----- (0042C760) --------------------------------------------------------  // acclient.c:105631
void __thiscall StringInfo::SetStringIDandTableEnum(StringInfo *this, unsigned int _stringID, int _strtableEnum)
{
  StringInfo *v3; // esi@1
  int v4; // ST08_4@1
  unsigned int v5; // edi@1

  v3 = this;
  v4 = _strtableEnum;
  this->m_stringID = _stringID;
  v5 = DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&_stringID, v4, 4)->id;
  if ( MasterDBMap::DivineType((IDClass<_tagDataID,32,0>)v5) == 37 )
    v3->m_tableID.id = v5;
  else
    v3->m_tableID.id = INVALID_DID_23.id;
}

//----- (0042C7B0) --------------------------------------------------------  // acclient.c:105648
void __thiscall StringInfo::SetStringIDandTableID(StringInfo *this, unsigned int _stringID, IDClass<_tagDataID,32,0> _strtableID)
{
  StringInfo *v3; // esi@1

  v3 = this;
  this->m_stringID = _stringID;
  if ( MasterDBMap::DivineType(_strtableID) == 37 )
    v3->m_tableID.id = _strtableID.id;
  else
    v3->m_tableID.id = INVALID_DID_23.id;
}

//----- (0042C7F0) --------------------------------------------------------  // acclient.c:105661
bool __thiscall StringInfo::InqStringTableFile(StringInfo *this, PStringBase<char> *_strDataFile)
{
  bool v2; // al@2
  unsigned int v3; // ST04_4@3
  PStringBase<char> *v4; // esi@3
  PSRefBufferCharData<char> *v5; // eax@3
  int v6; // edi@4
  PSRefBufferCharData<char> *v7; // esi@7
  char *v8; // esi@8
  PStringBase<char> result; // [sp+4h] [bp-4h]@1

  result.m_charbuffer = (PSRefBufferCharData<char> *)this;
  if ( this->m_tableID.id == INVALID_DID_23.id )
  {
    v2 = 0;
  }
  else
  {
    v3 = this->m_tableID.id;
    v4 = FileArray::GetRelativeFilePath(&result);
    v5 = _strDataFile->m_charbuffer;
    if ( _strDataFile->m_charbuffer != v4->m_charbuffer )
    {
      v6 = (int)&v5[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      v7 = v4->m_charbuffer;
      _strDataFile->m_charbuffer = v7;
      InterlockedIncrement((volatile LONG *)&v7[-1]);
    }
    v8 = &result.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) )
    {
      if ( v8 )
        (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
    }
    v2 = *(_DWORD *)&_strDataFile->m_charbuffer[-1].m_data[12] != 1;
  }
  return v2;
}

//----- (0042C890) --------------------------------------------------------  // acclient.c:105703
void __thiscall DBObjGrabber<StringTable>::DBObjGrabber<StringTable>(DBObjGrabber<StringTable> *this, IDClass<_tagDataID,32,0> _did)
{
  DBObjGrabber<StringTable> *v2; // esi@1
  QualifiedDataID *v3; // eax@1
  QualifiedDataID v4; // [sp+4h] [bp-8h]@1

  v2 = this;
  this->m_object = 0;
  QualifiedDataID::QualifiedDataID(&v4, _did, 0x25u);
  v2->m_object = (StringTable *)DBObj::Get(v3);
}

//----- (0042C8C0) --------------------------------------------------------  // acclient.c:105716
IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *__thiscall IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::operator++(IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *this, IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *result, int __formal)
{
  HashTableData<unsigned long,StringInfoData *> **v3; // ebp@1
  HashTableData<unsigned long,StringInfoData *> *v4; // esi@1
  HashTableData<unsigned long,StringInfoData *> *v5; // eax@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *v6; // edi@1
  int v7; // edx@2
  HashTableData<unsigned long,StringInfoData *> **v8; // eax@3
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *v9; // eax@6

  v3 = this->m_currBucket;
  v4 = this->m_currElement;
  v5 = v4->m_hashNext;
  v6 = this->m_currHashTable;
  this->m_currElement = v5;
  if ( !v5 )
  {
    v7 = (int)&v6->m_buckets[v6->m_numBuckets];
    while ( 1 )
    {
      v8 = this->m_currBucket + 1;
      this->m_currBucket = v8;
      if ( v8 == (HashTableData<unsigned long,StringInfoData *> **)v7 )
        break;
      if ( *v8 )
      {
        this->m_currElement = *v8;
        break;
      }
    }
  }
  v9 = result;
  result->m_currHashTable = v6;
  result->m_currElement = v4;
  result->m_currBucket = v3;
  return v9;
}

//----- (0042C910) --------------------------------------------------------  // acclient.c:105755
void __cdecl SB_TypeAlloc<StringInfoDataResolver,SB_Default>::Serialize(const int *_class, StringInfoData **_obj, Archive *_arc)
{
  unsigned __int16 v3; // di@2
  unsigned int v4; // eax@4
  StringInfoData *v5; // eax@9

  if ( _arc->m_flags & 1 )
    v3 = (*_obj)->m_eType;
  else
    v3 = (unsigned __int16)_arc;
  Archive::CheckAlignment(_arc, 2u);
  v4 = Archive::GetBytes(_arc, 2u);
  if ( v4 )
  {
    if ( _arc->m_flags & 1 )
      *(_WORD *)v4 = v3;
    else
      v3 = *(_WORD *)v4;
  }
  if ( ~LOBYTE(_arc->m_flags) & 1 )
  {
    StringInfoData::Create(v3);
    *_obj = v5;
  }
  if ( *_obj )
    ((void (__stdcall *)(_DWORD))(*_obj)->vfptr->Serialize)(_arc);
}

//----- (0042C980) --------------------------------------------------------  // acclient.c:105784
void __thiscall StringInfo::SetLiteralValue(StringInfo *this, PStringBase<unsigned short> *_value, bool _escape_metas)
{
  bool v3; // zf@1
  StringInfo *v4; // esi@1
  PStringBase<unsigned short> *v5; // ebx@2
  PSRefBufferCharData<unsigned short> *v6; // eax@2
  int v7; // edi@3
  PSRefBufferCharData<unsigned short> *v8; // eax@6
  int v9; // esi@7
  PSRefBufferCharData<unsigned short> *v10; // eax@10
  int v11; // edi@11
  PSRefBufferCharData<unsigned short> *v12; // eax@14

  v3 = _escape_metas == 0;
  v4 = this;
  this->m_Override = 1;
  if ( v3 )
  {
    v10 = this->m_LiteralValue.m_charbuffer;
    if ( v10 != _value->m_charbuffer )
    {
      v11 = (int)&v10[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v10[-1].m_data[8]) && v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      v12 = _value->m_charbuffer;
      v4->m_LiteralValue.m_charbuffer = _value->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v12[-1].m_data[8]);
    }
  }
  else
  {
    v5 = StringTableMetaLanguage::EscapeString((PStringBase<unsigned short> *)&_escape_metas, _value);
    v6 = v4->m_LiteralValue.m_charbuffer;
    if ( v6 != v5->m_charbuffer )
    {
      v7 = (int)&v6[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v6[-1].m_data[8]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      v8 = v5->m_charbuffer;
      v4->m_LiteralValue.m_charbuffer = v5->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v8[-1].m_data[8]);
    }
    v9 = _escape_metas - 20;
    if ( !InterlockedDecrement((volatile LONG *)(_escape_metas - 20 + 4)) )
    {
      if ( v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    }
  }
}

//----- (0042CA50) --------------------------------------------------------  // acclient.c:105836
PStringBase<unsigned short> *__thiscall StringInfo::GetLiteralValue(StringInfo *this, PStringBase<unsigned short> *result, bool bRetainMetas)
{
  PSRefBufferCharData<unsigned short> **v3; // edi@2
  char *v4; // esi@3
  int v5; // esi@7
  PSRefBufferCharData<unsigned short> **v6; // edi@10
  char *v7; // esi@11
  int v8; // esi@15
  PSRefBufferCharData<unsigned short> *v9; // eax@18
  char *v10; // esi@18
  PStringBase<unsigned short> resulta; // [sp+10h] [bp-4h]@1

  resulta.m_charbuffer = this->m_LiteralValue.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&resulta.m_charbuffer[-1].m_data[8]);
  if ( !bRetainMetas )
  {
    v3 = (PSRefBufferCharData<unsigned short> **)StringTableMetaLanguage::StripMetaLetters(
                                                   (PStringBase<unsigned short> *)&bRetainMetas,
                                                   &resulta);
    if ( resulta.m_charbuffer != *v3 )
    {
      v4 = (char *)&resulta.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&resulta.m_charbuffer[-1].m_data[8]) && v4 )
        (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
      resulta.m_charbuffer = *v3;
      InterlockedIncrement((volatile LONG *)&resulta.m_charbuffer[-1].m_data[8]);
    }
    v5 = bRetainMetas - 20;
    if ( !InterlockedDecrement((volatile LONG *)(bRetainMetas - 20 + 4)) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  }
  v6 = (PSRefBufferCharData<unsigned short> **)StringTableMetaLanguage::UnescapeString(
                                                 (PStringBase<unsigned short> *)&bRetainMetas,
                                                 &resulta);
  if ( resulta.m_charbuffer != *v6 )
  {
    v7 = (char *)&resulta.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&resulta.m_charbuffer[-1].m_data[8]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    resulta.m_charbuffer = *v6;
    InterlockedIncrement((volatile LONG *)&resulta.m_charbuffer[-1].m_data[8]);
  }
  v8 = bRetainMetas - 20;
  if ( !InterlockedDecrement((volatile LONG *)(bRetainMetas - 20 + 4)) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  v9 = resulta.m_charbuffer;
  result->m_charbuffer = resulta.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v9[-1].m_data[8]);
  v10 = (char *)&resulta.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&resulta.m_charbuffer[-1].m_data[8]) && v10 )
    (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  return result;
}

//----- (0042CB70) --------------------------------------------------------  // acclient.c:105891
HashIterator<unsigned long,StringInfoData *,0> *__thiscall HashIterator<unsigned long,StringInfoData *,0>::operator++(HashIterator<unsigned long,StringInfoData *,0> *this, HashIterator<unsigned long,StringInfoData *,0> *result, int __formal)
{
  HashTableData<unsigned long,StringInfoData *> *v3; // ebx@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *v4; // esi@1
  HashTableData<unsigned long,StringInfoData *> **v5; // edi@1
  HashIterator<unsigned long,StringInfoData *,0> *v6; // eax@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> v7; // [sp+Ch] [bp-Ch]@1

  v3 = this->m_iter.m_currElement;
  v4 = this->m_iter.m_currHashTable;
  v5 = this->m_iter.m_currBucket;
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::operator++(
    &this->m_iter,
    &v7,
    0);
  v6 = result;
  result->m_iter.m_currBucket = v5;
  result->m_iter.m_currHashTable = v4;
  result->m_iter.m_currElement = v3;
  return v6;
}

//----- (0042CBE0) --------------------------------------------------------  // acclient.c:105941
char __thiscall StringInfo::IsValid(StringInfo *this, int bValidateChildren)
{
  StringInfo *v2; // esi@1
  char v3; // cl@1
  IDClass<_tagDataID,32,0> v4; // eax@3
  StringTable *v6; // edi@7
  HashTableData<unsigned long,StringInfoData *> *i; // eax@12
  StringInfoData *v8; // ecx@13
  DBObjGrabber<StringTable> table; // [sp+4h] [bp-1Ch]@7
  HashIterator<unsigned long,StringInfoData *,0> iter; // [sp+8h] [bp-18h]@12
  HashIterator<unsigned long,StringInfoData *,0> result; // [sp+14h] [bp-Ch]@15

  v2 = this;
  v3 = this->m_Override;
  if ( v3 == 1 )
    return 1;
  if ( !v2->m_stringID )
    return 0;
  v4.id = v2->m_tableID.id;
  if ( v4.id == INVALID_DID_23.id )
    return 0;
  if ( v3 == 2 )
    return 1;
  DBObjGrabber<StringTable>::DBObjGrabber<StringTable>(&table, v4);
  v6 = table.m_object;
  if ( !table.m_object )
    return 0;
  if ( !StringTable::GetStringTableString(table.m_object, v2->m_stringID) )
  {
LABEL_9:
    DBObjGrabber<StringTable>::~DBObjGrabber<StringTable>((DBObjGrabber<ACCharGenData> *)&table);
    return 0;
  }
  if ( (_BYTE)bValidateChildren )
  {
    HashTable<unsigned long,BaseProperty,1>::begin(&v2->m_variables, &iter);
    for ( i = iter.m_iter.m_currElement; iter.m_iter.m_currElement; i = iter.m_iter.m_currElement )
    {
      v8 = i->m_data;
      if ( v8 )
      {
        if ( !(unsigned __int8)((int (__stdcall *)(_DWORD))v8->vfptr->IsValid)(bValidateChildren) )
          goto LABEL_9;
      }
      HashIterator<unsigned long,StringInfoData *,0>::operator++(&iter, &result, 0);
    }
  }
  v6->vfptr->Release((Interface *)v6);
  return 1;
}

//----- (0042CCB0) --------------------------------------------------------  // acclient.c:105993
void __thiscall StringInfo::GetSubDataIDs(StringInfo *this, QualifiedDataIDArray *id_array)
{
  StringInfo *v2; // esi@1
  QualifiedDataID *v3; // eax@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // eax@2
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // esi@2
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v6; // ebx@2
  HashTableData<unsigned long,HeritageGroup_CG> **v7; // edi@2
  HeritageGroup_CGVtbl *v8; // ecx@3
  QualifiedDataID v9; // [sp+4h] [bp-Ch]@2

  v2 = this;
  if ( this->m_Override != 1 )
  {
    QualifiedDataID::QualifiedDataID(&v9, this->m_tableID, 0);
    QualifiedDataIDArray::AddQDID(id_array, v3, 0);
    v4 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v2->m_variables.m_intrusiveTable,
           (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v9);
    v5 = v4->m_currElement;
    v6 = v4->m_currHashTable;
    v7 = v4->m_currBucket;
    if ( v5 )
    {
      do
      {
LABEL_3:
        v8 = v5->m_data.vfptr;
        if ( v8 )
          (*((void (__stdcall **)(QualifiedDataIDArray *))v8->Serialize + 1))(id_array);
        v5 = v5->m_hashNext;
      }
      while ( v5 );
      while ( 1 )
      {
        ++v7;
        if ( v7 == &v6->m_buckets[v6->m_numBuckets] )
          break;
        if ( *v7 )
        {
          v5 = *v7;
          if ( *v7 )
            goto LABEL_3;
          return;
        }
      }
    }
  }
}

//----- (0042CD40) --------------------------------------------------------  // acclient.c:106044
void __thiscall StringInfo::GetSubPrivateIDs(StringInfo *this, QualifiedDataIDArray *id_array, IDClass<_tagDataID,32,0> fromTable)
{
  StringInfo *v3; // esi@1
  unsigned int v4; // eax@1
  QualifiedDataID *v5; // eax@2
  int v6; // edi@2
  IDClass<_tagDataID,32,0> *v7; // eax@3
  QualifiedDataID *v8; // eax@4
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // eax@6
  HashTableData<unsigned long,HeritageGroup_CG> *v10; // esi@6
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v11; // ebx@6
  HashTableData<unsigned long,HeritageGroup_CG> **v12; // edi@6
  HeritageGroup_CGVtbl *v13; // ecx@7
  QualifiedDataID v14; // [sp+10h] [bp-14h]@2
  QualifiedDataID v15; // [sp+18h] [bp-Ch]@4

  v3 = this;
  v4 = this->m_tableID.id;
  if ( fromTable.id == v4 )
  {
    QualifiedDataID::QualifiedDataID(&v14, (IDClass<_tagDataID,32,0>)v4, 0x25u);
    v6 = DBObj::Get(v5);
    if ( v6 )
    {
      v7 = (IDClass<_tagDataID,32,0> *)StringTable::GetStringTableString((StringTable *)v6, v3->m_stringID);
      if ( v7 )
      {
        QualifiedDataID::QualifiedDataID(&v15, (IDClass<_tagDataID,32,0>)v7->id, 0);
        QualifiedDataIDArray::AddQDID(id_array, v8, 0);
      }
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
    }
  }
  v9 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v3->m_variables.m_intrusiveTable,
         (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v15);
  v10 = v9->m_currElement;
  v11 = v9->m_currHashTable;
  v12 = v9->m_currBucket;
  if ( v10 )
  {
    do
    {
LABEL_7:
      v13 = v10->m_data.vfptr;
      if ( v13 )
        (*((void (__stdcall **)(QualifiedDataIDArray *, unsigned int))v13->Serialize + 2))(id_array, fromTable.id);
      v10 = v10->m_hashNext;
    }
    while ( v10 );
    while ( 1 )
    {
      ++v12;
      if ( v12 == &v11->m_buckets[v11->m_numBuckets] )
        break;
      if ( *v12 )
      {
        v10 = *v12;
        if ( *v12 )
          goto LABEL_7;
        return;
      }
    }
  }
}

//----- (0042CE00) --------------------------------------------------------  // acclient.c:106111
bool __thiscall StringInfo::FromFileNode(StringInfo *this, PFileNode *_node)
{
  PFileNode *v2; // esi@1
  int v3; // edi@1
  PFileNode *v4; // esi@2
  int v5; // eax@4
  PSRefBufferCharData<char> *v6; // ecx@4
  PStringBase<char> *v7; // ecx@6
  int v8; // eax@8
  PSRefBufferCharData<char> *v9; // ecx@8
  int v10; // eax@13
  PSRefBufferCharData<char> *v11; // ecx@13
  int v12; // eax@18
  PSRefBufferCharData<char> *v13; // ecx@18
  PSRefBufferCharData<char> *v14; // ecx@22
  int v15; // eax@23
  PSRefBufferCharData<char> *v16; // ecx@23
  const unsigned __int16 *v17; // eax@26
  char v18; // al@29
  PStringBase<char> v19; // esi@31
  PSRefBufferCharData<char> *v20; // edx@32
  PStringBase<char> v21; // eax@32
  PStringBase<char> v22; // ST04_4@35
  PStringBase<char> v23; // esi@36
  unsigned int v24; // eax@36
  char *v25; // esi@38
  int v26; // edx@40
  char *v27; // esi@43
  int v28; // edx@45
  PStringBase<char> v30; // [sp-10h] [bp-3Ch]@32
  PStringBase<char> v31; // [sp-Ch] [bp-38h]@32
  PStringBase<char> v32; // [sp-8h] [bp-34h]@6
  PStringBase<char> v33; // [sp-4h] [bp-30h]@6
  bool bRetval; // [sp+12h] [bp-1Ah]@2
  bool bEnglishScanned; // [sp+13h] [bp-19h]@2
  PStringBase<char> stringTable; // [sp+14h] [bp-18h]@2
  PStringBase<char> literal; // [sp+18h] [bp-14h]@23
  PStringBase<unsigned short> result; // [sp+1Ch] [bp-10h]@26
  PFileNodeIter iter; // [sp+20h] [bp-Ch]@2

  v2 = _node;
  v3 = (int)this;
  if ( !_node )
    return 0;
  stringTable.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  bRetval = 1;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  bEnglishScanned = 0;
  PFileNodeIter::PFileNodeIter(&iter, v2);
  v4 = PFileNodeIter::Curr(&iter);
  if ( v4 )
  {
    while ( !PFileNode::IsKeyword(v4, v3, &KW_STRINGTABLE) )
    {
      if ( !PFileNode::IsKeyword(v4, v3, &KW_STRINGTOKEN) )
      {
        if ( PFileNode::IsKeyword(v4, v3, &KW_STRINGENGLISH) )
        {
          v10 = PFileNode::GetLeaf(v4);
          if ( v10 && PFileNode::GetNameAsPString((PFileNode *)v10, v3, (PStringBase<char> *)(v3 + 136)) )
          {
            bEnglishScanned = 1;
            *(_BYTE *)(v3 + 132) = 2;
          }
          else
          {
            v33.m_charbuffer = v11;
            PStringBase<char>::PStringBase<char>(&v33, "corrupt string english data");
            PFileNode::ReportError(v3, v4, v33);
            bRetval = 0;
            *(_BYTE *)(v3 + 132) = 2;
          }
        }
        else if ( PFileNode::IsKeyword(v4, v3, &KW_STRINGCOMMENT) )
        {
          v12 = PFileNode::GetLeaf(v4);
          if ( !v12 || !PFileNode::GetNameAsPString((PFileNode *)v12, v3, (PStringBase<char> *)(v3 + 140)) )
          {
            v33.m_charbuffer = v13;
            PStringBase<char>::PStringBase<char>(&v33, "corrupt string comment data");
            PFileNode::ReportError(v3, v4, v33);
            bRetval = 0;
          }
          *(_BYTE *)(v3 + 132) = 2;
        }
        else if ( PFileNode::IsKeyword(v4, v3, &KW_LITERAL) )
        {
          PStringBase<char>::PStringBase<char>(&literal);
          v15 = PFileNode::GetLeaf(v4);
          if ( !v15 || !PFileNode::GetNameAsPString((PFileNode *)v15, v3, &literal) )
          {
            v33.m_charbuffer = v16;
            PStringBase<char>::PStringBase<char>(&v33, "corrupt literal data");
            PFileNode::ReportError(v3, v4, v33);
            bRetval = 0;
          }
          v17 = (const unsigned __int16 *)PStringBase<char>::to_wpstring(&literal, &result, 0);
          PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)(v3 + 128), v17);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
          *(_BYTE *)(v3 + 132) = 1;
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&literal);
        }
        else
        {
          v33.m_charbuffer = v14;
          PStringBase<char>::PStringBase<char>(&v33, "unknown keyword");
          PFileNode::ReportWarning(v3, v4, v33);
        }
        goto LABEL_28;
      }
      v8 = PFileNode::GetLeaf(v4);
      if ( !v8 || !PFileNode::GetNameAsPString((PFileNode *)v8, v3, (PStringBase<char> *)v3) )
      {
        v33.m_charbuffer = v9;
        v7 = &v33;
        v32.m_charbuffer = (PSRefBufferCharData<char> *)"corrupt string token data";
LABEL_11:
        PStringBase<char>::PStringBase<char>(v7, v32.m_charbuffer->m_data);
        PFileNode::ReportError(v3, v4, v33);
        bRetval = 0;
      }
LABEL_28:
      v4 = (PFileNode *)PFileNodeIter::Next(&iter);
      if ( !v4 )
        goto LABEL_29;
    }
    v5 = PFileNode::GetLeaf(v4);
    if ( v5 && PFileNode::GetNameAsPString((PFileNode *)v5, v3, &stringTable) )
      goto LABEL_28;
    v33.m_charbuffer = v6;
    v7 = &v33;
    v32.m_charbuffer = (PSRefBufferCharData<char> *)"corrupt string table data";
    goto LABEL_11;
  }
LABEL_29:
  v18 = *(_BYTE *)(v3 + 132);
  if ( !v18 || v18 == 2 )
  {
    v19.m_charbuffer = stringTable.m_charbuffer;
    if ( *(_DWORD *)&stringTable.m_charbuffer[-1].m_data[12] == 1 )
    {
      v20 = *(PSRefBufferCharData<char> **)(v3 + 136);
      v21.m_charbuffer = *(PSRefBufferCharData<char> **)v3;
      v33.m_charbuffer = *(PSRefBufferCharData<char> **)(v3 + 140);
      v32.m_charbuffer = v20;
      v31.m_charbuffer = v21.m_charbuffer;
      v30.m_charbuffer = v33.m_charbuffer;
      PStringBase<char>::PStringBase<char>(
        &v30,
        "failed parsing the stringtable name! ( token: '%s', english: '%s', comment: '%s'");
      PFileNode::ReportError(v3, _node, v30);
    }
    else
    {
      if ( bEnglishScanned && !DBCache::IsRunTime() )
      {
        v33.m_charbuffer = *(PSRefBufferCharData<char> **)(v3 + 140);
        InterlockedIncrement((volatile LONG *)&v33.m_charbuffer[-1]);
        v32.m_charbuffer = *(PSRefBufferCharData<char> **)(v3 + 136);
        InterlockedIncrement((volatile LONG *)&v32.m_charbuffer[-1]);
        v31.m_charbuffer = *(PSRefBufferCharData<char> **)v3;
        InterlockedIncrement((volatile LONG *)&v31.m_charbuffer[-1]);
        v30.m_charbuffer = v19.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&v19.m_charbuffer[-1]);
        v22.m_charbuffer = PFileNode::GetSourceFileName(_node)->m_charbuffer;
        InterlockedIncrement((volatile LONG *)&v22.m_charbuffer[-1]);
        MasterStringTableGen::AddString(v22, v19, v31, v32, v33);
      }
      v23.m_charbuffer = *(PSRefBufferCharData<char> **)v3;
      v24 = *(_DWORD *)(*(_DWORD *)v3 - 8);
      if ( v24 == -1 )
      {
        v24 = compute_str_hash(*(char **)v3);
        *(_DWORD *)&v23.m_charbuffer[-1].m_data[8] = v24;
      }
      v33.m_charbuffer = 0;
      v32.m_charbuffer = (PSRefBufferCharData<char> *)&_node;
      *(_DWORD *)(v3 + 4) = v24;
      PStringBase<char>::to_wpstring(
        &stringTable,
        (PStringBase<unsigned short> *)v32.m_charbuffer,
        (const unsigned __int16)v33.m_charbuffer);
      v25 = (char *)&_node[-1].sub_nodes.m_num;
      if ( !InterlockedDecrement((volatile LONG *)&_node[-1].m_bProcessed) && v25 )
      {
        v26 = *(_DWORD *)v25;
        v33.m_charbuffer = (PSRefBufferCharData<char> *)1;
        (*(void (__thiscall **)(char *, signed int))v26)(v25, 1);
      }
      if ( *(_DWORD *)(v3 + 8) != INVALID_DID_23.id )
        goto LABEL_43;
    }
    bRetval = 0;
  }
LABEL_43:
  PFileNodeIter::~PFileNodeIter(&iter);
  v27 = &stringTable.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stringTable.m_charbuffer[-1]) )
  {
    if ( v27 )
    {
      v28 = *(_DWORD *)v27;
      v33.m_charbuffer = (PSRefBufferCharData<char> *)1;
      (*(void (__thiscall **)(char *, signed int))v28)(v27, 1);
    }
  }
  return bRetval;
}

//----- (0042D190) --------------------------------------------------------  // acclient.c:106321
SmartArray<PStringBase<unsigned short>,1> *__thiscall SmartArray<PStringBase<unsigned short>,1>::operator=(SmartArray<PStringBase<unsigned short>,1> *this, int a2)
{
  SmartArray<PStringBase<unsigned short>,1> *v2; // ebp@1
  int v3; // edi@1
  int v4; // eax@3
  PStringBase<unsigned short> *v5; // ebx@3
  unsigned int v6; // esi@3
  int v7; // ecx@3
  PSRefBufferCharData<unsigned short> *v8; // eax@4
  int v9; // edi@5
  PSRefBufferCharData<unsigned short> *v10; // eax@8
  unsigned int v11; // ebx@10
  wchar_t *v12; // esi@13
  volatile LONG *v13; // edi@13
  int v14; // ebx@13
  int v15; // eax@13
  int v16; // ebp@14
  int v17; // esi@18
  int v19; // [sp+Ch] [bp-8h]@3
  unsigned int v20; // [sp+Ch] [bp-8h]@10
  SmartArray<PStringBase<unsigned short>,1> *v21; // [sp+10h] [bp-4h]@1

  v2 = this;
  v3 = a2;
  v21 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<PStringBase<unsigned short>,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v4 = *(_DWORD *)(a2 + 8);
    v5 = v2->m_data;
    v6 = *(_DWORD *)a2;
    v7 = *(_DWORD *)a2 + 4 * v4;
    v19 = *(_DWORD *)a2 + 4 * v4;
    if ( *(_DWORD *)a2 < (unsigned int)v7 )
    {
      do
      {
        v8 = v5->m_charbuffer;
        if ( v5->m_charbuffer != *(PSRefBufferCharData<unsigned short> **)v6 )
        {
          v9 = (int)&v8[-1].m_data[6];
          if ( !InterlockedDecrement((volatile LONG *)&v8[-1].m_data[8]) && v9 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
          v10 = *(PSRefBufferCharData<unsigned short> **)v6;
          v5->m_charbuffer = *(PSRefBufferCharData<unsigned short> **)v6;
          InterlockedIncrement((volatile LONG *)&v10[-1].m_data[8]);
          v3 = a2;
          v7 = v19;
        }
        v6 += 4;
        ++v5;
      }
      while ( v6 < v7 );
    }
    v11 = *(_DWORD *)(v3 + 8);
    v20 = *(_DWORD *)(v3 + 8);
    if ( v11 < v2->m_num )
    {
      while ( 1 )
      {
        v12 = PStringBase<unsigned short>::s_NullBuffer;
        v13 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
        InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
        v14 = (int)&v2->m_data[v11];
        v15 = *(_DWORD *)v14;
        if ( *(wchar_t **)v14 != v12 )
        {
          v16 = v15 - 20;
          if ( !InterlockedDecrement((volatile LONG *)(v15 - 20 + 4)) && v16 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
          *(_DWORD *)v14 = v12;
          InterlockedIncrement(v13);
          v2 = v21;
        }
        v17 = (int)(v12 - 10);
        if ( !InterlockedDecrement((volatile LONG *)(v17 + 4)) && v17 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
        ++v20;
        if ( v20 >= v2->m_num )
          break;
        v11 = v20;
      }
      v3 = a2;
    }
    v2->m_num = *(_DWORD *)(v3 + 8);
  }
  return v2;
}

//----- (0042D2D0) --------------------------------------------------------  // acclient.c:106411
PStringBase<unsigned short> *__cdecl operator+(PStringBase<unsigned short> *result, const unsigned __int16 *lhs, PStringBase<unsigned short> *rhs)
{
  PStringBase<unsigned short> *v3; // edi@1
  PStringBase<unsigned short> *v4; // ST08_4@1
  PStringBase<unsigned short> *v5; // ST04_4@1
  PStringBase<unsigned short> *v6; // eax@1
  PStringBase<unsigned short> *v7; // esi@1

  v3 = result;
  v4 = rhs;
  v5 = result;
  PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&result, lhs);
  PStringBase<unsigned short>::operator+(v6, v5, v4);
  v7 = result - 5;
  if ( !InterlockedDecrement((volatile LONG *)&result[-4]) && v7 )
    (*(void (__thiscall **)(PStringBase<unsigned short> *, signed int))&v7->m_charbuffer->m_data[0])(v7, 1);
  return v3;
}

//----- (0042D320) --------------------------------------------------------  // acclient.c:106431
bool __thiscall StringInfo::operator==(StringInfo *this, StringInfo *comp)
{
  StringInfo *v2; // edi@1
  char v3; // cl@2
  HashTableData<unsigned long,StringInfoData *> *v5; // edi@12
  HashTableData<unsigned long,StringInfoData *> *v6; // eax@13
  HashIterator<unsigned long,StringInfoData *,0> iter; // [sp+8h] [bp-Ch]@12

  v2 = this;
  if ( this != comp )
  {
    v3 = this->m_Override;
    if ( v3 == 1 )
    {
      if ( comp->m_Override == 1 )
        return PStringBase<unsigned short>::operator==(&v2->m_LiteralValue, &comp->m_LiteralValue);
      return 0;
    }
    if ( v2->m_stringID != comp->m_stringID
      || v2->m_tableID.id != comp->m_tableID.id
      || v3 != comp->m_Override
      || PStringBase<char>::operator!=(&v2->m_strToken, &comp->m_strToken)
      || PStringBase<char>::operator!=(&v2->m_strEnglish, &comp->m_strEnglish)
      || PStringBase<char>::operator!=(&v2->m_strComment, &comp->m_strComment)
      || v2->m_variables.m_intrusiveTable.m_numElements != comp->m_variables.m_intrusiveTable.m_numElements )
      return 0;
    HashTable<unsigned long,BaseProperty,1>::begin(&v2->m_variables, &iter);
    v5 = iter.m_iter.m_currElement;
    if ( iter.m_iter.m_currElement )
    {
      while ( 1 )
      {
        v6 = comp->m_variables.m_intrusiveTable.m_buckets[v5->m_hashKey
                                                        % comp->m_variables.m_intrusiveTable.m_numBuckets];
        if ( !v6 )
          break;
        while ( v6->m_hashKey != v5->m_hashKey )
        {
          v6 = v6->m_hashNext;
          if ( !v6 )
            return 0;
        }
        if ( !v6 || !StringInfoData::Compare(v6->m_data, v5->m_data) )
          break;
        HashIterator<unsigned long,StringInfoData *,0>::next((HashIterator<unsigned long,unsigned long,0> *)&iter);
        v5 = iter.m_iter.m_currElement;
        if ( !iter.m_iter.m_currElement )
          return 1;
      }
      return 0;
    }
  }
  return 1;
}

//----- (0042D440) --------------------------------------------------------  // acclient.c:106487
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,StringInfoData *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,StringInfoData *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 797D68: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::vftable[2])(void *, char);

//----- (0042D4D0) --------------------------------------------------------  // acclient.c:106520
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,PStringBase<unsigned short> > **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,PStringBase<unsigned short> > **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 797D6C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>::vftable)(void *, char);

//----- (0042D560) --------------------------------------------------------  // acclient.c:106553
void __cdecl _SerializeIntrusiveHashTable____HV__IntrusiveHashTable_KPAV__HashTableData_KPAVStringInfoData_____0A___PAV__HashTableData_KPAVStringInfoData____USB_HashData___SB_Hash_USB_Default__U__SB_TypeAlloc_UStringInfoDataResolver__USB_Default_____1_SB_DEFAULT_ITEM_NAME__3QBDB_1_SB_DEFAULT_KEY_NAME__3QBDB_1_SB_DEFAULT_VALUE_NAME__3QBDB____YAXABHAAV__IntrusiveHashTable_KPAV__HashTableData_KPAVStringInfoData_____0A___AAVArchive___Z(const int *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *io_object, Archive *io_archive)
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
  HashTableData<unsigned long,Sex_CG> *v15; // ebp@31
  unsigned int v16; // ebx@31
  void *v17; // eax@32
  void *v18; // edi@32
  unsigned int v19; // eax@34
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
        SB_TypeAlloc<StringInfoDataResolver,SB_Default>::Serialize(_class, (StringInfoData **)&v11->m_data, v3);
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
LABEL_42:
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
          v18 = 0;
          if ( v17 )
          {
            *((_DWORD *)v17 + 1) = 0;
            v18 = v17;
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
          SB_TypeAlloc<StringInfoDataResolver,SB_Default>::Serialize(_class, (StringInfoData **)v18 + 2, v3);
          if ( (v3->m_flags >> 2) & 1 )
            break;
          if ( !IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
                  (HashTableData<unsigned long,Sex_CG> *)v18,
                  v15) )
            goto LABEL_42;
          ++v16;
          v15 = (HashTableData<unsigned long,Sex_CG> *)v18;
        }
        while ( v16 < (unsigned int)io_archive );
      }
    }
  }
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;

//----- (0042D810) --------------------------------------------------------  // acclient.c:106750
char __thiscall HashTable<unsigned long,PStringBase<unsigned short>,0>::set(HashTable<unsigned long,PStringBase<unsigned short>,0> *this, const unsigned int *_key, PStringBase<unsigned short> *_data)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *v3; // edi@1
  HashTableData<unsigned long,PStringBase<unsigned short> > *v4; // esi@1
  void *v5; // eax@4
  void *v6; // esi@4
  PSRefBufferCharData<unsigned short> *v7; // eax@5
  PSRefBufferCharData<unsigned short> *v9; // eax@7
  int v10; // edi@8
  PSRefBufferCharData<unsigned short> *v11; // eax@11

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
  if ( !v4 )
  {
LABEL_4:
    v5 = operator new(0xCu);
    v6 = v5;
    if ( v5 )
    {
      *(_DWORD *)v5 = *_key;
      *((_DWORD *)v5 + 1) = 0;
      v7 = _data->m_charbuffer;
      *((_DWORD *)v6 + 2) = _data->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v7[-1].m_data[8]);
      IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
        v3,
        (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v6);
      return 1;
    }
    IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
      v3,
      0);
    return 1;
  }
  v9 = v4->m_data.m_charbuffer;
  if ( v9 == _data->m_charbuffer )
    return 1;
  v10 = (int)&v9[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v9[-1].m_data[8]) )
  {
    if ( v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  }
  v11 = _data->m_charbuffer;
  v4->m_data.m_charbuffer = _data->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v11[-1].m_data[8]);
  return 1;
}

//----- (0042D8D0) --------------------------------------------------------  // acclient.c:106809
void __thiscall StringInfo::ClearVars(StringInfo *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *v1; // ebp@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edi@1
  HeritageGroup_CGVtbl *v6; // ecx@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@1

  v1 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_variables.m_intrusiveTable;
  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_variables.m_intrusiveTable,
         &result);
  v3 = v2->m_currElement;
  v4 = v2->m_currHashTable;
  v5 = v2->m_currBucket;
  if ( v3 )
  {
    do
    {
LABEL_2:
      v6 = v3->m_data.vfptr;
      if ( v6 )
        (*(void (__stdcall **)(_DWORD))v6->Serialize)(1);
      v3->m_data.vfptr = 0;
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
        break;
      }
    }
  }
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents(v1);
}

//----- (0042D940) --------------------------------------------------------  // acclient.c:106856
void __thiscall StringInfo::AddVar(StringInfo *this, StringInfoData *i_pcNewData)
{
  StringInfo *v2; // edi@1
  HashSetData<IDClass<_tagDataID,32,0> > *v3; // eax@2
  unsigned int v4; // esi@3
  unsigned int eVariable; // [sp+4h] [bp-4h]@1

  eVariable = (unsigned int)this;
  v2 = this;
  if ( i_pcNewData )
  {
    eVariable = i_pcNewData->m_eVarID;
    v3 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
           (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->m_variables.m_intrusiveTable,
           (IDClass<_tagDataID,32,0> *)&eVariable);
    if ( v3 )
    {
      v4 = v3[1].m_hashKey.id;
      operator delete(v3);
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    HashTable<unsigned long,unsigned long,0>::set(
      (HashTable<unsigned long,unsigned long,0> *)&v2->m_variables,
      &eVariable,
      (const unsigned int *)&i_pcNewData);
  }
}

//----- (0042D9A0) --------------------------------------------------------  // acclient.c:106886
HashTable<unsigned long,StringInfoData *,0> *__thiscall HashTable<unsigned long,StringInfoData *,0>::vector_deleting_destructor(HashTable<unsigned long,StringInfoData *,0> *this, unsigned int a2)
{
  HashTable<unsigned long,StringInfoData *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,StringInfoData *,0>Vtbl *)HashTable<unsigned long,StringInfoData *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::vftable;
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
// 797D68: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::vftable[2])(void *, char);
// 797E5C: using guessed type int (__thiscall *HashTable<unsigned long,StringInfoData *,0>::vftable[2])(void *, char);

//----- (0042DA00) --------------------------------------------------------  // acclient.c:106912
HashTable<unsigned long,PStringBase<unsigned short>,0> *__thiscall HashTable<unsigned long,PStringBase<unsigned short>,0>::vector_deleting_destructor(HashTable<unsigned long,PStringBase<unsigned short>,0> *this, unsigned int a2)
{
  HashTable<unsigned long,PStringBase<unsigned short>,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,PStringBase<unsigned short>,0>Vtbl *)&HashTable<unsigned long,PStringBase<unsigned short>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>::vftable;
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
// 797D6C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>::vftable)(void *, char);
// 797E60: using guessed type int (__thiscall *HashTable<unsigned long,PStringBase<unsigned short>,0>::vftable)(void *, char);

//----- (0042DA60) --------------------------------------------------------  // acclient.c:106938
void __thiscall StringInfo::StringInfo(StringInfo *this)
{
  StringInfo *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1
  volatile LONG *v5; // ST00_4@1

  v1 = this;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_strToken.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v1->m_stringID = 0;
  v1->m_tableID.id = INVALID_DID_23.id;
  v1->m_variables.vfptr = (HashTable<unsigned long,StringInfoData *,0>Vtbl *)HashTable<unsigned long,StringInfoData *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>(
    &v1->m_variables.m_intrusiveTable,
    0x17u);
  v3 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->m_LiteralValue.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v3);
  v1->m_Override = 0;
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strEnglish.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strComment.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v5);
}
// 797E5C: using guessed type int (__thiscall *HashTable<unsigned long,StringInfoData *,0>::vftable[2])(void *, char);

//----- (0042DAF0) --------------------------------------------------------  // acclient.c:106970
void __thiscall StringInfo::Reset(StringInfo *this)
{
  StringInfo *v1; // esi@1
  PSRefBufferCharData<char> *v2; // eax@1
  int v3; // edi@2
  volatile LONG *v4; // ST00_4@5
  wchar_t *v5; // eax@6
  int v6; // edi@7
  volatile LONG *v7; // ST00_4@10
  PSRefBufferCharData<char> *v8; // eax@11
  int v9; // edi@12
  volatile LONG *v10; // ST00_4@15
  PSRefBufferCharData<char> *v11; // eax@16
  int v12; // edi@17
  volatile LONG *v13; // ST00_4@20

  v1 = this;
  this->m_stringID = 0;
  this->m_tableID.id = INVALID_DID_23.id;
  v2 = this->m_strToken.m_charbuffer;
  this->m_Override = 0;
  if ( v2 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_strToken.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v4);
  }
  v5 = v1->m_LiteralValue.m_charbuffer->m_data;
  if ( v5 != PStringBase<unsigned short>::s_NullBuffer )
  {
    v6 = (int)(v5 - 10);
    if ( !InterlockedDecrement((volatile LONG *)v5 - 4) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    v1->m_LiteralValue.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v7);
  }
  v8 = v1->m_strEnglish.m_charbuffer;
  if ( v8 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v9 = (int)&v8[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v8[-1]) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v10 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_strEnglish.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v10);
  }
  v11 = v1->m_strComment.m_charbuffer;
  if ( v11 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v12 = (int)&v11[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v11[-1]) && v12 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
    v13 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_strComment.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v13);
  }
  StringInfo::ClearVars(v1);
}

//----- (0042DC10) --------------------------------------------------------  // acclient.c:107034
StringInfo *__thiscall StringInfo::operator=(StringInfo *this, int a2)
{
  StringInfo *v2; // ebp@1
  PSRefBufferCharData<char> *v3; // eax@2
  int v4; // edi@3
  PSRefBufferCharData<char> *v5; // eax@6
  PSRefBufferCharData<unsigned short> *v6; // eax@7
  int v7; // edi@8
  PSRefBufferCharData<unsigned short> *v8; // eax@11
  PSRefBufferCharData<char> *v9; // eax@12
  int v10; // edi@13
  PSRefBufferCharData<char> *v11; // eax@16
  PSRefBufferCharData<char> *v12; // edi@17
  int v13; // edi@18
  PSRefBufferCharData<char> *v14; // eax@21
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v15; // eax@22
  HashTableData<unsigned long,HeritageGroup_CG> *v16; // esi@22
  HashTableData<unsigned long,HeritageGroup_CG> **v17; // ebx@22
  int v18; // eax@23
  int v19; // edi@23
  void *v20; // eax@24
  unsigned int v21; // ecx@25
  void *v22; // edi@25
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v24; // [sp+10h] [bp-18h]@22
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+1Ch] [bp-Ch]@22

  v2 = this;
  if ( (StringInfo *)a2 != this )
  {
    v3 = this->m_strToken.m_charbuffer;
    if ( this->m_strToken.m_charbuffer != *(PSRefBufferCharData<char> **)a2 )
    {
      v4 = (int)&v3[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      v5 = *(PSRefBufferCharData<char> **)a2;
      v2->m_strToken.m_charbuffer = *(PSRefBufferCharData<char> **)a2;
      InterlockedIncrement((volatile LONG *)&v5[-1]);
    }
    v2->m_stringID = *(_DWORD *)(a2 + 4);
    v2->m_tableID.id = *(_DWORD *)(a2 + 8);
    v2->m_Override = *(_BYTE *)(a2 + 132);
    v6 = v2->m_LiteralValue.m_charbuffer;
    if ( v6 != *(PSRefBufferCharData<unsigned short> **)(a2 + 128) )
    {
      v7 = (int)&v6[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v6[-1].m_data[8]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      v8 = *(PSRefBufferCharData<unsigned short> **)(a2 + 128);
      v2->m_LiteralValue.m_charbuffer = v8;
      InterlockedIncrement((volatile LONG *)&v8[-1].m_data[8]);
    }
    v9 = v2->m_strEnglish.m_charbuffer;
    if ( v9 != *(PSRefBufferCharData<char> **)(a2 + 136) )
    {
      v10 = (int)&v9[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) && v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      v11 = *(PSRefBufferCharData<char> **)(a2 + 136);
      v2->m_strEnglish.m_charbuffer = v11;
      InterlockedIncrement((volatile LONG *)&v11[-1]);
    }
    v12 = v2->m_strComment.m_charbuffer;
    if ( v12 != *(PSRefBufferCharData<char> **)(a2 + 140) )
    {
      v13 = (int)&v12[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) && v13 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
      v14 = *(PSRefBufferCharData<char> **)(a2 + 140);
      v2->m_strComment.m_charbuffer = v14;
      InterlockedIncrement((volatile LONG *)&v14[-1]);
    }
    StringInfo::ClearVars(v2);
    v15 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
            (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)(a2 + 16),
            &result);
    v16 = v15->m_currElement;
    v17 = v15->m_currBucket;
    v24 = v15->m_currHashTable;
    if ( v16 )
    {
      do
      {
LABEL_23:
        StringInfoData::Copy((StringInfoData *)v16->m_data.vfptr);
        v19 = v18;
        if ( v18 )
        {
          v20 = operator new(0xCu);
          if ( v20 )
          {
            v21 = v16->m_hashKey;
            *((_DWORD *)v20 + 2) = v19;
            *(_DWORD *)v20 = v21;
            *((_DWORD *)v20 + 1) = 0;
            v22 = v20;
          }
          else
          {
            v22 = 0;
          }
          if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v2->m_variables.m_intrusiveTable,
                  (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v22)
            && v22 )
            operator delete(v22);
        }
        v16 = v16->m_hashNext;
      }
      while ( v16 );
      while ( 1 )
      {
        ++v17;
        if ( v17 == &v24->m_buckets[v24->m_numBuckets] )
          break;
        if ( *v17 )
        {
          v16 = *v17;
          if ( *v17 )
            goto LABEL_23;
          return v2;
        }
      }
    }
  }
  return v2;
}

//----- (0042DDE0) --------------------------------------------------------  // acclient.c:107163
void __thiscall StringInfo::AddVariable_Int(StringInfo *this, unsigned int _varID, __int64 _varValue)
{
  StringInfo *v3; // esi@1
  LInt_StringInfoData *v4; // eax@1
  int v5; // eax@2

  v3 = this;
  v4 = (LInt_StringInfoData *)operator new(0x18u);
  if ( v4 )
  {
    LInt_StringInfoData::LInt_StringInfoData(v4, _varID);
    if ( v5 )
    {
      *(_QWORD *)(v5 + 16) = _varValue;
      StringInfo::AddVar(v3, (StringInfoData *)v5);
    }
  }
}

//----- (0042DE20) --------------------------------------------------------  // acclient.c:107183
void __thiscall StringInfo::AddVariable_UInt(StringInfo *this, unsigned int _varID, unsigned __int64 _varValue)
{
  StringInfo *v3; // esi@1
  ULInt_StringInfoData *v4; // eax@1
  int v5; // eax@2

  v3 = this;
  v4 = (ULInt_StringInfoData *)operator new(0x18u);
  if ( v4 )
  {
    ULInt_StringInfoData::ULInt_StringInfoData(v4, _varID);
    if ( v5 )
    {
      *(_QWORD *)(v5 + 16) = _varValue;
      StringInfo::AddVar(v3, (StringInfoData *)v5);
    }
  }
}

//----- (0042DE60) --------------------------------------------------------  // acclient.c:107203
void __thiscall StringInfo::AddVariable_Float(StringInfo *this, unsigned int _varID, long double _varValue, unsigned __int16 _precision)
{
  StringInfo *v4; // esi@1
  Double_StringInfoData *v5; // eax@1
  int v6; // eax@2

  v4 = this;
  v5 = (Double_StringInfoData *)operator new(0x20u);
  if ( v5 )
  {
    Double_StringInfoData::Double_StringInfoData(v5, _varID);
    if ( v6 )
    {
      *(long double *)(v6 + 16) = _varValue;
      *(_WORD *)(v6 + 24) = _precision;
      StringInfo::AddVar(v4, (StringInfoData *)v6);
    }
  }
}

//----- (0042DEB0) --------------------------------------------------------  // acclient.c:107224
void __thiscall StringInfo::Serialize(StringInfo *this, Archive *_rArchive)
{
  StringInfo *v2; // edi@1
  char v3; // bl@4
  Archive *v4; // esi@7
  unsigned int v5; // eax@7
  unsigned int v6; // eax@15
  unsigned int v7; // eax@19
  bool v8; // bl@23
  unsigned int v9; // eax@23
  bool bHasStrings; // [sp+1h] [bp-1h]@2

  v2 = this;
  if ( ProgramTypeSystem::s_eProgramType == -2147483647
    || (bHasStrings = 1, ProgramTypeSystem::s_eProgramType == -2147483646) )
    bHasStrings = 0;
  v3 = this->m_Override;
  if ( !bHasStrings && v3 == 2 )
    v3 = 0;
  v4 = _rArchive;
  Archive::CheckAlignment(_rArchive, 1u);
  v5 = Archive::GetBytes(v4, 1u);
  if ( v5 )
  {
    if ( v4->m_flags & 1 )
      *(_BYTE *)v5 = v3;
    else
      v3 = *(_BYTE *)v5;
  }
  if ( ~LOBYTE(v4->m_flags) & 1 )
    v2->m_Override = v3;
  if ( v2->m_Override == 1 )
  {
    PStringBase<unsigned short>::Serialize(&v2->m_LiteralValue, v4);
  }
  else
  {
    Archive::CheckAlignment(v4, 4u);
    v6 = Archive::GetBytes(v4, 4u);
    if ( v6 )
    {
      if ( v4->m_flags & 1 )
        *(_DWORD *)v6 = v2->m_stringID;
      else
        v2->m_stringID = *(_DWORD *)v6;
    }
    Archive::CheckAlignment(v4, 4u);
    v7 = Archive::GetBytes(v4, 4u);
    if ( v7 )
    {
      if ( v4->m_flags & 1 )
        *(_DWORD *)v7 = v2->m_tableID.id;
      else
        v2->m_tableID.id = *(_DWORD *)v7;
    }
  }
  v8 = bHasStrings;
  Archive::CheckAlignment(v4, 1u);
  v9 = Archive::GetBytes(v4, 1u);
  if ( v9 )
  {
    if ( v4->m_flags & 1 )
      *(_BYTE *)v9 = bHasStrings;
    else
      v8 = *(_BYTE *)v9;
  }
  if ( !(v4->m_flags & 5) )
  {
    if ( !v8 )
      goto LABEL_33;
    if ( v8 != 1 )
      Archive::RaiseError(v4);
  }
  if ( v8 )
  {
    PStringBase<char>::Serialize(&v2->m_strToken, v4);
    PStringBase<char>::Serialize(&v2->m_strEnglish, v4);
    PStringBase<char>::Serialize(&v2->m_strComment, v4);
  }
LABEL_33:
  if ( ~LOBYTE(v4->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v2->m_variables.m_intrusiveTable);
  _SerializeIntrusiveHashTable____HV__IntrusiveHashTable_KPAV__HashTableData_KPAVStringInfoData_____0A___PAV__HashTableData_KPAVStringInfoData____USB_HashData___SB_Hash_USB_Default__U__SB_TypeAlloc_UStringInfoDataResolver__USB_Default_____1_SB_DEFAULT_ITEM_NAME__3QBDB_1_SB_DEFAULT_KEY_NAME__3QBDB_1_SB_DEFAULT_VALUE_NAME__3QBDB____YAXABHAAV__IntrusiveHashTable_KPAV__HashTableData_KPAVStringInfoData_____0A___AAVArchive___Z(
    (const int *)&_rArchive,
    &v2->m_variables.m_intrusiveTable,
    v4);
}
// 836720: using guessed type enum ProgramType ProgramTypeSystem::s_eProgramType;

//----- (0042E020) --------------------------------------------------------  // acclient.c:107314
signed int __thiscall StringInfo::InqStringInternal(StringInfo *this, PStringBase<unsigned short> *_result, bool _bRetainMetas)
{
  StringInfo *v3; // ebx@1
  char v4; // al@1
  PStringBase<unsigned short> *v5; // edi@2
  PSRefBufferCharData<unsigned short> *v6; // eax@2
  LONG (__stdcall *v7)(volatile LONG *); // ebp@2
  int v8; // esi@3
  PSRefBufferCharData<unsigned short> *v9; // eax@6
  const unsigned __int16 *v10; // eax@8
  char *v11; // esi@8
  const unsigned __int16 *v12; // eax@12
  char *v13; // esi@12
  signed int v14; // eax@15
  StringTable *v15; // ebp@21
  HashTableData<unsigned long,StringInfoData *> *v16; // esi@23
  HashTableData<unsigned long,StringInfoData *> **v17; // ebp@24
  StringInfoData *v18; // ecx@25
  PStringBase<unsigned short> *v19; // eax@26
  char *v20; // edi@26
  int v21; // edi@34
  const unsigned __int16 *v22; // eax@35
  char *v23; // esi@35
  DBObjGrabber<StringTable> table; // [sp+10h] [bp-88h]@8
  PStringBase<unsigned short> result; // [sp+14h] [bp-84h]@26
  HashIterator<unsigned long,StringInfoData *,0> iter; // [sp+18h] [bp-80h]@23
  HashTable<unsigned long,PStringBase<unsigned short>,0> varTable; // [sp+24h] [bp-74h]@23

  v3 = this;
  v4 = this->m_Override;
  if ( v4 == 1 )
  {
    v5 = _result;
    v6 = _result->m_charbuffer;
    v7 = InterlockedDecrement;
    if ( _result->m_charbuffer != this->m_LiteralValue.m_charbuffer )
    {
      v8 = (int)&v6[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v6[-1].m_data[8]) && v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      v9 = v3->m_LiteralValue.m_charbuffer;
      _result->m_charbuffer = v9;
      InterlockedIncrement((volatile LONG *)&v9[-1].m_data[8]);
    }
LABEL_11:
    if ( !_bRetainMetas )
    {
      v12 = (const unsigned __int16 *)StringTableMetaLanguage::StripMetaLetters(
                                        (PStringBase<unsigned short> *)&table,
                                        v5);
      PStringBase<unsigned short>::operator=(v5, v12);
      v13 = (char *)&table.m_object[-1].m_strings.m_intrusiveTable.m_aInplaceBuckets[22];
      if ( !v7((volatile LONG *)&table.m_object[-1].m_strings.m_intrusiveTable.m_buckets) )
      {
        if ( v13 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
      }
    }
    return 0;
  }
  if ( v4 == 2 )
  {
    v10 = (const unsigned __int16 *)PStringBase<char>::to_wpstring(
                                      &this->m_strEnglish,
                                      (PStringBase<unsigned short> *)&table,
                                      0);
    v5 = _result;
    PStringBase<unsigned short>::operator=(_result, v10);
    v7 = InterlockedDecrement;
    v11 = (char *)&table.m_object[-1].m_strings.m_intrusiveTable.m_aInplaceBuckets[22];
    if ( !InterlockedDecrement((volatile LONG *)&table.m_object[-1].m_strings.m_intrusiveTable.m_buckets) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    goto LABEL_11;
  }
  PStringBase<unsigned short>::sprintf(
    _result,
    L"<string table error; token: 0x%08X tableDID: 0x%08X>",
    this->m_stringID,
    this->m_tableID.id);
  if ( v3->m_stringID && v3->m_tableID.id != INVALID_DID_23.id )
  {
    DBObjGrabber<StringTable>::DBObjGrabber<StringTable>(&table, v3->m_tableID);
    v15 = table.m_object;
    if ( table.m_object )
    {
      varTable.vfptr = (HashTable<unsigned long,PStringBase<unsigned short>,0>Vtbl *)&HashTable<unsigned long,PStringBase<unsigned short>,0>::vftable;
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>(
        &varTable.m_intrusiveTable,
        0x17u);
      HashTable<unsigned long,BaseProperty,1>::begin(&v3->m_variables, &iter);
      v16 = iter.m_iter.m_currElement;
      if ( iter.m_iter.m_currElement )
      {
        v17 = iter.m_iter.m_currBucket;
        do
        {
LABEL_25:
          v18 = v16->m_data;
          if ( v18 )
          {
            v19 = (PStringBase<unsigned short> *)((int (__stdcall *)(PStringBase<unsigned short> *))v18->vfptr->ToString)(&result);
            HashTable<unsigned long,PStringBase<unsigned short>,0>::set(&varTable, &v16->m_hashKey, v19);
            v20 = (char *)&result.m_charbuffer[-1].m_data[6];
            if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) )
            {
              if ( v20 )
                (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
            }
          }
          v16 = v16->m_hashNext;
        }
        while ( v16 );
        while ( 1 )
        {
          ++v17;
          if ( v17 == &iter.m_iter.m_currHashTable->m_buckets[iter.m_iter.m_currHashTable->m_numBuckets] )
            break;
          if ( *v17 )
          {
            v16 = *v17;
            if ( *v17 )
              goto LABEL_25;
            break;
          }
        }
        v15 = table.m_object;
      }
      v21 = StringTable::GetString(v15, _result, v3->m_stringID, &varTable, 1);
      if ( !_bRetainMetas )
      {
        v22 = (const unsigned __int16 *)StringTableMetaLanguage::StripMetaLetters(&result, _result);
        PStringBase<unsigned short>::operator=(_result, v22);
        v23 = (char *)&result.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) )
        {
          if ( v23 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
        }
      }
      varTable.vfptr = (HashTable<unsigned long,PStringBase<unsigned short>,0>Vtbl *)&HashTable<unsigned long,PStringBase<unsigned short>,0>::vftable;
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents(&varTable.m_intrusiveTable);
      varTable.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>::vftable;
      if ( (HashTableData<unsigned long,PStringBase<unsigned short> > **)varTable.m_intrusiveTable.m_buckets != varTable.m_intrusiveTable.m_aInplaceBuckets )
        operator delete[](varTable.m_intrusiveTable.m_buckets);
      varTable.m_intrusiveTable.m_buckets = 0;
      varTable.m_intrusiveTable.m_firstInterestingBucket = 0;
      varTable.m_intrusiveTable.m_numBuckets = 0;
      varTable.m_intrusiveTable.m_numElements = 0;
      v15->vfptr->Release((Interface *)v15);
      v14 = v21;
    }
    else
    {
      v14 = 3;
    }
  }
  else
  {
    if ( DBCache::IsClient() )
      DBCache::IsRunTime();
    v14 = 1;
  }
  return v14;
}
// 797D6C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>::vftable)(void *, char);
// 797E60: using guessed type int (__thiscall *HashTable<unsigned long,PStringBase<unsigned short>,0>::vftable)(void *, char);

//----- (0042E2F0) --------------------------------------------------------  // acclient.c:107482
void __thiscall StringInfo::StringInfo(StringInfo *this, StringInfo *copy)
{
  StringInfo *v2; // esi@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1
  volatile LONG *v5; // ST00_4@1
  volatile LONG *v6; // ST00_4@1

  v2 = this;
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_strToken.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v2->m_variables.vfptr = (HashTable<unsigned long,StringInfoData *,0>Vtbl *)HashTable<unsigned long,StringInfoData *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>(
    &v2->m_variables.m_intrusiveTable,
    0x17u);
  v4 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v2->m_LiteralValue.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v4);
  v5 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v2->m_strEnglish.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v5);
  v6 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v2->m_strComment.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v6);
  StringInfo::operator=(v2, (int)copy);
}
// 797E5C: using guessed type int (__thiscall *HashTable<unsigned long,StringInfoData *,0>::vftable[2])(void *, char);

//----- (0042E370) --------------------------------------------------------  // acclient.c:107512
void __thiscall StringInfo::~StringInfo(StringInfo *this)
{
  StringInfo *v1; // edi@1
  int v2; // esi@1
  int v3; // esi@4
  int v4; // esi@7
  void *v5; // eax@10
  int v6; // edi@12

  v1 = this;
  StringInfo::Reset(this);
  v2 = (int)&v1->m_strComment.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v2 + 4)) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->m_strEnglish.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = (int)&v1->m_LiteralValue.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  v1->m_variables.vfptr = (HashTable<unsigned long,StringInfoData *,0>Vtbl *)HashTable<unsigned long,StringInfoData *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_variables.m_intrusiveTable);
  v5 = v1->m_variables.m_intrusiveTable.m_buckets;
  v1->m_variables.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::vftable;
  if ( v5 != v1->m_variables.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v5);
  v1->m_variables.m_intrusiveTable.m_buckets = 0;
  v1->m_variables.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_variables.m_intrusiveTable.m_numBuckets = 0;
  v1->m_variables.m_intrusiveTable.m_numElements = 0;
  v6 = (int)&v1->m_strToken.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) )
  {
    if ( v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  }
}
// 797D68: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::vftable[2])(void *, char);
// 797E5C: using guessed type int (__thiscall *HashTable<unsigned long,StringInfoData *,0>::vftable[2])(void *, char);

//----- (0042E440) --------------------------------------------------------  // acclient.c:107553
void __thiscall StringInfo::AddVariable_StringInfo(StringInfo *this, unsigned int _varID, StringInfo *_si)
{
  StringInfo *v3; // edi@1
  StringInfo_StringInfoData *v4; // eax@1
  int v5; // eax@2
  StringInfoData *v6; // esi@2

  v3 = this;
  v4 = (StringInfo_StringInfoData *)operator new(0x9Cu);
  if ( v4 )
  {
    StringInfo_StringInfoData::StringInfo_StringInfoData(v4, _varID);
    v6 = (StringInfoData *)v5;
    if ( v5 )
    {
      StringInfo::operator=((StringInfo *)(v5 + 12), (int)_si);
      StringInfo::AddVar(v3, v6);
    }
  }
}

//----- (0042E490) --------------------------------------------------------  // acclient.c:107575
char __thiscall StringInfo::InqString(StringInfo *this, PStringBase<unsigned short> *_result, bool _bRetainMetas)
{
  PStringBase<unsigned short> *v3; // ebx@2
  PSRefBufferCharData<unsigned short> *v4; // eax@2
  int v5; // edi@3
  PSRefBufferCharData<unsigned short> *v6; // ebx@6
  int v7; // esi@7
  char result; // al@10

  if ( StringInfo::InqStringInternal(this, _result, _bRetainMetas) )
  {
    result = 0;
  }
  else
  {
    v3 = StringTableMetaLanguage::UnescapeString((PStringBase<unsigned short> *)&_bRetainMetas, _result);
    v4 = _result->m_charbuffer;
    if ( _result->m_charbuffer != v3->m_charbuffer )
    {
      v5 = (int)&v4[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v4[-1].m_data[8]) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      v6 = v3->m_charbuffer;
      _result->m_charbuffer = v6;
      InterlockedIncrement((volatile LONG *)&v6[-1].m_data[8]);
    }
    v7 = _bRetainMetas - 20;
    if ( !InterlockedDecrement((volatile LONG *)(_bRetainMetas - 20 + 4)) )
    {
      if ( v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    }
    result = 1;
  }
  return result;
}

//----- (0042E520) --------------------------------------------------------  // acclient.c:107613
PStringBase<unsigned short> *__thiscall StringInfo::GetLogString(StringInfo *this, PStringBase<unsigned short> *result, bool _bRetainMetaTags)
{
  StringInfo *v3; // esi@1
  signed int v4; // eax@1
  unsigned int v5; // eax@2
  int v6; // esi@2
  PSRefBufferCharData<unsigned short> **v7; // edi@5
  char *v8; // esi@6
  char *v9; // esi@10
  char *v10; // esi@13
  char *v11; // esi@16
  PSRefBufferCharData<unsigned short> *v12; // eax@20
  char *v13; // esi@20
  PStringBase<unsigned short> temp; // [sp+10h] [bp-10h]@1
  PStringBase<unsigned short> v16; // [sp+14h] [bp-Ch]@2
  PStringBase<unsigned short> rhs; // [sp+18h] [bp-8h]@2
  PStringBase<unsigned short> v18; // [sp+1Ch] [bp-4h]@5

  temp.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v3 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v4 = StringInfo::InqStringInternal(v3, &temp, _bRetainMetaTags);
  if ( v4 )
  {
    PStringBase<unsigned short>::sprintf(
      &temp,
      L"<could not render string: table 0x%08X token 0x%08X. Reason = %d>",
      v3->m_tableID.id,
      v3->m_stringID,
      v4);
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&rhs, L")");
    v5 = _wcslen(L"(");
    PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)&_bRetainMetaTags, v5);
    _wcscpy((wchar_t *)_bRetainMetaTags, L"(");
    PStringBase<unsigned short>::operator+((PStringBase<unsigned short> *)&_bRetainMetaTags, &v16, &temp);
    v6 = _bRetainMetaTags - 20;
    if ( !InterlockedDecrement((volatile LONG *)(_bRetainMetaTags - 20 + 4)) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = (PSRefBufferCharData<unsigned short> **)PStringBase<unsigned short>::operator+(&v16, &v18, &rhs);
    if ( temp.m_charbuffer != *v7 )
    {
      v8 = (char *)&temp.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&temp.m_charbuffer[-1].m_data[8]) && v8 )
        (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
      temp.m_charbuffer = *v7;
      InterlockedIncrement((volatile LONG *)&temp.m_charbuffer[-1].m_data[8]);
    }
    v9 = (char *)&v18.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v18.m_charbuffer[-1].m_data[8]) && v9 )
      (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
    v10 = (char *)&v16.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v16.m_charbuffer[-1].m_data[8]) && v10 )
      (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
    v11 = (char *)&rhs.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1].m_data[8]) && v11 )
      (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
  }
  v12 = temp.m_charbuffer;
  result->m_charbuffer = temp.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v12[-1].m_data[8]);
  v13 = (char *)&temp.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&temp.m_charbuffer[-1].m_data[8]) && v13 )
    (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
  return result;
}

//----- (0042E6C0) --------------------------------------------------------  // acclient.c:107683
void __thiscall StringInfo::AddVariable_String(StringInfo *this, unsigned int _varID, PStringBase<unsigned short> _varValue)
{
  StringInfo *v3; // edi@1
  StringInfo_StringInfoData *v4; // eax@1
  int v5; // eax@2
  StringInfoData *v6; // esi@2
  char *v7; // esi@4
  StringInfo v8; // [sp+8h] [bp-90h]@1

  v3 = this;
  StringInfo::StringInfo(&v8);
  StringInfo::SetLiteralValue(&v8, &_varValue, 1);
  v4 = (StringInfo_StringInfoData *)operator new(0x9Cu);
  if ( v4 )
  {
    StringInfo_StringInfoData::StringInfo_StringInfoData(v4, _varID);
    v6 = (StringInfoData *)v5;
    if ( v5 )
    {
      StringInfo::operator=((StringInfo *)(v5 + 12), (int)&v8);
      StringInfo::AddVar(v3, v6);
    }
  }
  StringInfo::~StringInfo(&v8);
  v7 = (char *)&_varValue.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&_varValue.m_charbuffer[-1].m_data[8]) )
  {
    if ( v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  }
}

//----- (0042E760) --------------------------------------------------------  // acclient.c:107716
PStringBase<unsigned short> *__thiscall StringInfo::GetString(StringInfo *this, PStringBase<unsigned short> *result, bool bRetainMetas)
{
  StringInfo *v3; // esi@1
  PSRefBufferCharData<unsigned short> *v4; // eax@1
  char *v5; // esi@1
  PStringBase<unsigned short> temp; // [sp+0h] [bp-4h]@1

  temp.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v3 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  StringInfo::InqString(v3, &temp, bRetainMetas);
  v4 = temp.m_charbuffer;
  result->m_charbuffer = temp.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v4[-1].m_data[8]);
  v5 = (char *)&temp.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&temp.m_charbuffer[-1].m_data[8]) && v5 )
    (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
  return result;
}

//----- (0042E7D0) --------------------------------------------------------  // acclient.c:107737
void __thiscall StringInfo::AddVariable_String(StringInfo *this, unsigned int _varID, PStringBase<char> _varValue)
{
  StringInfo *v3; // esi@1
  char *v4; // esi@1
  int v5; // eax@3
  PStringBase<unsigned short> v6; // [sp-4h] [bp-8h]@1

  v6.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v3 = this;
  PStringBase<char>::to_wpstring(&_varValue, &v6, 0);
  StringInfo::AddVariable_String(v3, _varID, v6);
  v4 = &_varValue.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_varValue.m_charbuffer[-1]) )
  {
    if ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6.m_charbuffer = (PSRefBufferCharData<unsigned short> *)1;
      (*(void (__thiscall **)(char *, signed int))v5)(v4, 1);
    }
  }
}

//----- (006C5720) --------------------------------------------------------  // acclient.c:733760
int _E73_23()
{
  return atexit(_E74_26);
}

//----- (006C5730) --------------------------------------------------------  // acclient.c:733766
int _E76_14()
{
  return atexit(_E77_42);
}

//----- (006C5740) --------------------------------------------------------  // acclient.c:733772
int _E79_14()
{
  return atexit(_E80_16);
}

//----- (006C5750) --------------------------------------------------------  // acclient.c:733778
int _E82_5()
{
  KW_NULL_1.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(_E83_6);
}

//----- (006C5770) --------------------------------------------------------  // acclient.c:733786
int _E85_2()
{
  PStringBase<char>::PStringBase<char>(&KW_STRINGTABLE, "StringTable");
  return atexit(_E86_4);
}

//----- (006C5790) --------------------------------------------------------  // acclient.c:733793
int _E88_2()
{
  PStringBase<char>::PStringBase<char>(&KW_STRINGTOKEN, "StringToken");
  return atexit(_E89_15);
}

//----- (006C57B0) --------------------------------------------------------  // acclient.c:733800
int _E91_4()
{
  PStringBase<char>::PStringBase<char>(&KW_STRINGENGLISH, "StringEnglish");
  return atexit(_E92_12);
}

//----- (006C57D0) --------------------------------------------------------  // acclient.c:733807
int _E94_2()
{
  PStringBase<char>::PStringBase<char>(&KW_STRINGCOMMENT, "StringComment");
  return atexit(sub_728320);
}

//----- (006C57F0) --------------------------------------------------------  // acclient.c:733814
int _E97_4()
{
  PStringBase<char>::PStringBase<char>(&KW_LITERAL, "Literal");
  return atexit(_E98_27);
}

//----- (006C5810) --------------------------------------------------------  // acclient.c:733821
int _E1_23()
{
  return atexit(_E2_23);
}

//----- (00728260) --------------------------------------------------------  // acclient.c:825982
void __cdecl _E83_6()
{
  char *v0; // esi@1

  v0 = &KW_NULL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728290) --------------------------------------------------------  // acclient.c:825995
void __cdecl _E86_4()
{
  char *v0; // esi@1

  v0 = &KW_STRINGTABLE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRINGTABLE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007282C0) --------------------------------------------------------  // acclient.c:826008
void __cdecl _E89_15()
{
  char *v0; // esi@1

  v0 = &KW_STRINGTOKEN.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRINGTOKEN.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007282F0) --------------------------------------------------------  // acclient.c:826021
void __cdecl _E92_12()
{
  char *v0; // esi@1

  v0 = &KW_STRINGENGLISH.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRINGENGLISH.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728320) --------------------------------------------------------  // acclient.c:826034
void __cdecl sub_728320()
{
  char *v0; // esi@1

  v0 = &KW_STRINGCOMMENT.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRINGCOMMENT.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728350) --------------------------------------------------------  // acclient.c:826047
void __cdecl _E98_27()
{
  char *v0; // esi@1

  v0 = &KW_LITERAL.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LITERAL.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

