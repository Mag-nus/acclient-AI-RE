/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : EnumMapper
   Object     : ENGINE\enummap\EnumMapper.obj
   Functions  : 46
   Addresses  : 004011B0 - 006C4A40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004011B0) --------------------------------------------------------  // acclient.c:60906
void __thiscall PStringBase<char>::~PStringBase<char>(CaseInsensitiveStringBase<PStringBase<char> > *this)
{
  char *v1; // esi@1

  v1 = &this->m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)v1 + 1) )
  {
    if ( v1 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
  }
}

//----- (0041A630) --------------------------------------------------------  // acclient.c:87667
char __thiscall EnumMapper::ReleaseSubObjects(EnumMapper *this)
{
  EnumMapper *v1; // esi@1
  EnumMapper *v2; // ecx@1

  v1 = this;
  v2 = this->m_base_emp;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_base_emp = 0;
  }
  return 1;
}

//----- (0041A650) --------------------------------------------------------  // acclient.c:87683
bool __thiscall EnumMapper::GetSubObjects(EnumMapper *this)
{
  EnumMapper *v1; // esi@1
  unsigned int v2; // eax@1
  QualifiedDataID *v3; // eax@2
  int v4; // eax@2
  bool result; // al@3
  QualifiedDataID v6; // [sp+8h] [bp-8h]@2

  v1 = this;
  v2 = this->m_base_emp_did.id;
  result = 1;
  if ( v2 )
  {
    QualifiedDataID::QualifiedDataID(&v6, (IDClass<_tagDataID,32,0>)v2, 0x24u);
    v4 = DBObj::Get(v3);
    v1->m_base_emp = (EnumMapper *)v4;
    if ( !v4 )
      result = 0;
  }
  return result;
}

//----- (0041A690) --------------------------------------------------------  // acclient.c:87707
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1> *v2; // esi@1
  HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::vftable;
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
// 795464: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::vftable[4])(void *, char);

//----- (0041A6D0) --------------------------------------------------------  // acclient.c:87728
IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1> *__thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::scalar_deleting_destructor(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1> *v2; // esi@1
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1>Vtbl *)IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::vftable;
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
// 795468: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::vftable[3])(void *, char);

//----- (0041A710) --------------------------------------------------------  // acclient.c:87749
unsigned int __thiscall CaseInsensitiveStringBase<PStringBase<char>>::case_insensitive_hash(CaseInsensitiveStringBase<PStringBase<char> > *this)
{
  PSRefBufferCharData<char> *v1; // edi@1
  char v2; // al@1
  unsigned int i; // esi@1

  v1 = this->m_charbuffer;
  v2 = this->m_charbuffer->m_data[0];
  for ( i = 0; v2; v1 = (PSRefBufferCharData<char> *)((char *)v1 + 1) )
  {
    i = (char)_tolower(v2) + 16 * i;
    if ( i & 0xF0000000 )
      i = (i ^ ((i & 0xF0000000) >> 24)) & 0xFFFFFFF;
    v2 = v1->m_data[1];
  }
  return i;
}

//----- (0041A760) --------------------------------------------------------  // acclient.c:87768
bool __thiscall QualifiedDataIDArray::AddDID(QualifiedDataIDArray *this, IDClass<_tagDataID,32,0> i_did, unsigned int i_dwSubDataIDFlags)
{
  QualifiedDataIDArray *v3; // esi@1
  QualifiedDataID *v4; // eax@1
  QualifiedDataID v6; // [sp+4h] [bp-8h]@1

  v3 = this;
  QualifiedDataID::QualifiedDataID(&v6, i_did, 0);
  return QualifiedDataIDArray::AddQDID(v3, v4, i_dwSubDataIDFlags);
}

//----- (0041A790) --------------------------------------------------------  // acclient.c:87780
void __thiscall EnumMapper::GetSubDataIDs(EnumMapper *this, QualifiedDataIDArray *id_array)
{
  unsigned int v2; // eax@1
  QualifiedDataID *v3; // eax@2
  QualifiedDataID v4; // [sp+0h] [bp-8h]@2

  v2 = this->m_base_emp_did.id;
  if ( v2 )
  {
    QualifiedDataID::QualifiedDataID(&v4, (IDClass<_tagDataID,32,0>)v2, 0);
    QualifiedDataIDArray::AddQDID(id_array, v3, 0);
  }
}

//----- (0041A7C0) --------------------------------------------------------  // acclient.c:87795
bool __thiscall EnumMapper::iterator::operator!=(EnumMapper::iterator *this, EnumMapper::iterator *_rhs)
{
  bool result; // al@2

  if ( this->m_mapper )
    result = this->m_mapper != _rhs->m_mapper || this->m_iter.m_iter.m_currElement != _rhs->m_iter.m_iter.m_currElement;
  else
    result = _rhs->m_mapper != 0;
  return result;
}

//----- (0041A810) --------------------------------------------------------  // acclient.c:87807
unsigned int __thiscall EnumMapper::iterator::get_enum(EnumMapper::iterator *this)
{
  return this->m_iter.m_iter.m_currElement->m_hashKey;
}

//----- (0041A820) --------------------------------------------------------  // acclient.c:87813
PStringBase<char> *__thiscall EnumMapper::iterator::get_string(EnumMapper::iterator *this, PStringBase<char> *result)
{
  PSRefBufferCharData<char> *v2; // eax@1

  v2 = this->m_iter.m_iter.m_currElement->m_data.m_charbuffer;
  result->m_charbuffer = v2;
  InterlockedIncrement((volatile LONG *)&v2[-1]);
  return result;
}

//----- (0041A840) --------------------------------------------------------  // acclient.c:87824
void __thiscall PStringBase<unsigned short>::PStringBase<unsigned short>(CaseInsensitiveStringBase<PStringBase<char> > *this, PStringBase<char> *from)
{
  PSRefBufferCharData<char> *v2; // eax@1

  v2 = from->m_charbuffer;
  this->m_charbuffer = from->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v2[-1]);
}

//----- (0041A860) --------------------------------------------------------  // acclient.c:87834
void __thiscall DBObjGrabber<EnumMapper>::DBObjGrabber<EnumMapper>(DBObjGrabber<EnumMapper> *this, IDClass<_tagDataID,32,0> _did)
{
  DBObjGrabber<EnumMapper> *v2; // esi@1
  QualifiedDataID *v3; // eax@1
  QualifiedDataID v4; // [sp+4h] [bp-8h]@1

  v2 = this;
  this->m_object = 0;
  QualifiedDataID::QualifiedDataID(&v4, _did, 0x24u);
  v2->m_object = (EnumMapper *)DBObj::Get(v3);
}

//----- (0041A890) --------------------------------------------------------  // acclient.c:87847
void __thiscall DBObjGrabber<EnumIDMap>::DBObjGrabber<EnumIDMap>(DBObjGrabber<EnumIDMap> *this, IDClass<_tagDataID,32,0> _did)
{
  DBObjGrabber<EnumIDMap> *v2; // esi@1
  QualifiedDataID *v3; // eax@1
  QualifiedDataID v4; // [sp+4h] [bp-8h]@1

  v2 = this;
  this->m_object = 0;
  QualifiedDataID::QualifiedDataID(&v4, _did, 0x26u);
  v2->m_object = (EnumIDMap *)DBObj::Get(v3);
}

//----- (0041A8C0) --------------------------------------------------------  // acclient.c:87860
void __thiscall DBObjGrabber<DualEnumIDMap>::DBObjGrabber<DualEnumIDMap>(DBObjGrabber<DualEnumIDMap> *this, IDClass<_tagDataID,32,0> _did)
{
  DBObjGrabber<DualEnumIDMap> *v2; // esi@1
  QualifiedDataID *v3; // eax@1
  QualifiedDataID v4; // [sp+4h] [bp-8h]@1

  v2 = this;
  this->m_object = 0;
  QualifiedDataID::QualifiedDataID(&v4, _did, 0x28u);
  v2->m_object = (DualEnumIDMap *)DBObj::Get(v3);
}

//----- (0041A8F0) --------------------------------------------------------  // acclient.c:87873
EnumMapper::iterator *__thiscall EnumMapper::end(EnumMapper *this, EnumMapper::iterator *result)
{
  HashIterator<unsigned long,CaseInsensitiveStringBase<PStringBase<char> >,1> _i; // [sp+4h] [bp-Ch]@1

  _i.m_iter.m_currHashTable = &this->m_id_to_string_map.m_intrusiveTable;
  _i.m_iter.m_currBucket = 0;
  _i.m_iter.m_currElement = 0;
  EnumMapper::iterator::iterator(result, 0, &_i);
  return result;
}

//----- (0041A920) --------------------------------------------------------  // acclient.c:87885
void __thiscall EnumMapper::iterator::iterator(EnumMapper::iterator *this, EnumMapper *_mapper, HashIterator<unsigned long,CaseInsensitiveStringBase<PStringBase<char> >,1> *_i)
{
  EnumMapper::iterator *v3; // esi@1
  EnumMapper *v4; // edi@3
  HashIterator<unsigned long,CaseInsensitiveStringBase<PStringBase<char> >,1> *v5; // eax@4
  HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *v6; // ecx@4
  HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **v7; // edx@4
  HashIterator<unsigned long,CaseInsensitiveStringBase<PStringBase<char> >,1> v8; // [sp+8h] [bp-38h]@2
  HashIterator<unsigned long,StringInfoData *,0> result; // [sp+14h] [bp-2Ch]@4
  EnumMapper::iterator v10; // [sp+20h] [bp-20h]@4
  EnumMapper::iterator v11; // [sp+30h] [bp-10h]@2

  v3 = this;
  this->m_mapper = _mapper;
  this->m_iter = *_i;
  while ( v3->m_mapper )
  {
    v8.m_iter.m_currHashTable = &v3->m_mapper->m_id_to_string_map.m_intrusiveTable;
    v8.m_iter.m_currBucket = 0;
    v8.m_iter.m_currElement = 0;
    EnumMapper::iterator::iterator(&v11, 0, &v8);
    if ( v3->m_iter.m_iter.m_currElement != v11.m_iter.m_iter.m_currElement )
      break;
    v4 = v3->m_mapper->m_base_emp;
    v3->m_mapper = v4;
    if ( v4 )
    {
      v5 = (HashIterator<unsigned long,CaseInsensitiveStringBase<PStringBase<char> >,1> *)HashTable<unsigned long,BaseProperty,1>::begin(
                                                                                            (HashTable<unsigned long,StringInfoData *,0> *)&v4->m_id_to_string_map,
                                                                                            &result);
      EnumMapper::iterator::iterator(&v10, v4, v5);
      v6 = v10.m_iter.m_iter.m_currElement;
      v7 = v10.m_iter.m_iter.m_currBucket;
      v3->m_iter.m_iter.m_currHashTable = v10.m_iter.m_iter.m_currHashTable;
      v3->m_iter.m_iter.m_currElement = v6;
      v3->m_iter.m_iter.m_currBucket = v7;
    }
  }
}

//----- (0041A9C0) --------------------------------------------------------  // acclient.c:87926
EnumMapper::iterator *__thiscall EnumMapper::begin(EnumMapper *this, EnumMapper::iterator *result)
{
  EnumMapper *v2; // esi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1> *v4; // ecx@1
  HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **v5; // edx@1
  HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *v6; // eax@1
  HashIterator<unsigned long,CaseInsensitiveStringBase<PStringBase<char> >,1> _i; // [sp+4h] [bp-18h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> v9; // [sp+10h] [bp-Ch]@1

  v2 = this;
  v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_id_to_string_map.m_intrusiveTable,
         &v9);
  v4 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1> *)v3->m_currHashTable;
  v5 = (HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **)v3->m_currBucket;
  v6 = (HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *)v3->m_currElement;
  _i.m_iter.m_currHashTable = v4;
  _i.m_iter.m_currBucket = v5;
  _i.m_iter.m_currElement = v6;
  EnumMapper::iterator::iterator(result, v2, &_i);
  return result;
}

//----- (0041AA10) --------------------------------------------------------  // acclient.c:87951
EnumMapper::iterator *__thiscall EnumMapper::iterator::operator++(EnumMapper::iterator *this)
{
  EnumMapper::iterator *v1; // edi@1
  char *v2; // ebx@1
  EnumMapper *v3; // esi@4
  int v4; // edx@5
  HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **v5; // ecx@6
  int v6; // ecx@7
  HashTableData<unsigned long,StringInfoData *> **v7; // ecx@8
  HashTableData<unsigned long,StringInfoData *> *v8; // edx@8
  HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *v9; // ecx@10
  HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **v10; // edx@10
  HashIterator<unsigned long,CaseInsensitiveStringBase<PStringBase<char> >,1> _i; // [sp+8h] [bp-38h]@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> result; // [sp+14h] [bp-2Ch]@1
  EnumMapper::iterator v14; // [sp+20h] [bp-20h]@10
  EnumMapper::iterator v15; // [sp+30h] [bp-10h]@3

  v1 = this;
  v2 = (char *)&this->m_iter;
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::operator++(
    (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *)&this->m_iter,
    &result,
    0);
  if ( v1->m_mapper )
  {
    _i.m_iter.m_currBucket = 0;
    _i.m_iter.m_currElement = 0;
    do
    {
      _i.m_iter.m_currHashTable = &v1->m_mapper->m_id_to_string_map.m_intrusiveTable;
      EnumMapper::iterator::iterator(&v15, 0, &_i);
      if ( v1->m_iter.m_iter.m_currElement != v15.m_iter.m_iter.m_currElement )
        break;
      v3 = v1->m_mapper->m_base_emp;
      v1->m_mapper = v3;
      if ( v3 )
      {
        v4 = (int)&v3->m_id_to_string_map.m_intrusiveTable.m_buckets[v3->m_id_to_string_map.m_intrusiveTable.m_numBuckets];
        if ( v3->m_id_to_string_map.m_intrusiveTable.m_firstInterestingBucket == (HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **)v4 )
        {
LABEL_8:
          v7 = 0;
          v8 = 0;
        }
        else
        {
          while ( 1 )
          {
            v5 = v3->m_id_to_string_map.m_intrusiveTable.m_firstInterestingBucket;
            if ( *v5 )
              break;
            v6 = (int)(v5 + 1);
            v3->m_id_to_string_map.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **)v6;
            if ( v6 == v4 )
              goto LABEL_8;
          }
          v7 = (HashTableData<unsigned long,StringInfoData *> **)v3->m_id_to_string_map.m_intrusiveTable.m_firstInterestingBucket;
          v8 = *v7;
        }
        result.m_currElement = v8;
        result.m_currBucket = v7;
        result.m_currHashTable = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0> *)&v3->m_id_to_string_map.m_intrusiveTable;
        EnumMapper::iterator::iterator(
          &v14,
          v3,
          (HashIterator<unsigned long,CaseInsensitiveStringBase<PStringBase<char> >,1> *)&result);
        v9 = v14.m_iter.m_iter.m_currElement;
        v10 = v14.m_iter.m_iter.m_currBucket;
        *(_DWORD *)v2 = v14.m_iter.m_iter.m_currHashTable;
        *((_DWORD *)v2 + 2) = v9;
        *((_DWORD *)v2 + 1) = v10;
      }
    }
    while ( v1->m_mapper );
  }
  return v1;
}

//----- (0041AAF0) --------------------------------------------------------  // acclient.c:88030
char __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::grow(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::resize_internal(
           v2,
           *v3);
}

//----- (0041AB40) --------------------------------------------------------  // acclient.c:88050
char __thiscall EnumMapper::GetString(unsigned int _val, PStringBase<char> *_out, PStringBase<char> *_outa)
{
  unsigned int v3; // esi@1
  PStringBase<char> *v4; // ebx@2
  PSRefBufferCharData<char> *v5; // eax@2
  PSRefBufferCharData<char> *v6; // edi@2
  int v7; // esi@3
  char result; // al@10
  unsigned int v9; // ecx@11
  bool v10; // al@12
  char *v11; // esi@12
  char v12; // bl@12
  char *v13; // esi@16
  CaseInsensitiveStringBase<PStringBase<char> > out; // [sp+0h] [bp-4h]@1

  out.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v3 = _val;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( HashTable<unsigned long,PStringBase<unsigned short>,0>::find(
         (HashTable<unsigned long,PStringBase<unsigned short>,0> *)(v3 + 56),
         (const unsigned int *)&_out,
         (PStringBase<unsigned short> *)&out) )
  {
    v4 = _outa;
    v5 = _outa->m_charbuffer;
    v6 = out.m_charbuffer;
    if ( _outa->m_charbuffer != out.m_charbuffer )
    {
      v7 = (int)&v5[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      v4->m_charbuffer = v6;
      InterlockedIncrement((volatile LONG *)&v6[-1]);
    }
    if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v6 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&v6[-2].m_data[12])(&v6[-2].m_data[12], 1);
    result = 1;
  }
  else
  {
    v9 = *(_DWORD *)(v3 + 52);
    if ( v9 )
    {
      v10 = EnumMapper::GetString(v9, _out);
      v11 = &out.m_charbuffer[-2].m_data[12];
      v12 = v10;
      if ( !InterlockedDecrement((volatile LONG *)&out.m_charbuffer[-1]) && v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      result = v12;
    }
    else
    {
      v13 = &out.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&out.m_charbuffer[-1]) && v13 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
      result = 0;
    }
  }
  return result;
}

//----- (0041AC40) --------------------------------------------------------  // acclient.c:88112
char __cdecl EnumMapper::GetString(const unsigned int mapid, const unsigned int val, PStringBase<char> *out)
{
  char v3; // bl@1
  int v5; // eax@3
  int v6; // eax@4
  DualEnumIDMap *v7; // esi@6
  char v8; // al@7
  DualEnumIDMap *v9; // esi@8
  IDClass<_tagDataID,32,0> did; // [sp+4h] [bp-8h]@1
  DBObjGrabber<DualEnumIDMap> enumidmap; // [sp+8h] [bp-4h]@6

  v3 = 0;
  DBObj::GetDIDByEnum(&did, mapid, 1);
  if ( did.id == INVALID_DID_11.id )
    return 0;
  v5 = MasterDBMap::DivineType(did) - 36;
  if ( !v5 )
  {
    DBObjGrabber<EnumMapper>::DBObjGrabber<EnumMapper>((DBObjGrabber<EnumMapper> *)&enumidmap, did);
    v7 = enumidmap.m_object;
    if ( enumidmap.m_object )
    {
      v8 = EnumMapper::GetString((unsigned int)enumidmap.m_object, (PStringBase<char> *)val, out);
      goto LABEL_14;
    }
    return v3;
  }
  v6 = v5 - 2;
  if ( v6 )
  {
    if ( v6 == 2 )
    {
      DBObjGrabber<DualEnumIDMap>::DBObjGrabber<DualEnumIDMap>(&enumidmap, did);
      v7 = enumidmap.m_object;
      if ( enumidmap.m_object )
      {
        v8 = EnumIDMap::GetName((EnumIDMap *)&enumidmap.m_object->vfptr, val, out);
LABEL_14:
        if ( v8 )
          v3 = 1;
        v7->vfptr->Release((Interface *)v7);
        return v3;
      }
    }
    return v3;
  }
  DBObjGrabber<EnumIDMap>::DBObjGrabber<EnumIDMap>((DBObjGrabber<EnumIDMap> *)&enumidmap, did);
  v9 = enumidmap.m_object;
  if ( !enumidmap.m_object )
    return v3;
  if ( (unsigned __int8)EnumIDMap::GetName((EnumIDMap *)&enumidmap.m_object->vfptr, val, out) )
    v3 = 1;
  v9->vfptr->Release((Interface *)v9);
  return v3;
}

//----- (0041AD40) --------------------------------------------------------  // acclient.c:88169
char __cdecl EnumMapper::InqString(const unsigned int mapid, const unsigned int val, PStringBase<unsigned short> *out)
{
  PStringBase<unsigned short> *v3; // esi@1
  PStringBase<unsigned short> *v4; // edi@1
  PSRefBufferCharData<unsigned short> *v5; // eax@1
  int v6; // ebp@2
  PSRefBufferCharData<unsigned short> *v7; // edi@5
  char *v8; // esi@6
  char *v9; // esi@9
  PStringBase<char> str; // [sp+Ch] [bp-8h]@1
  PStringBase<unsigned short> result; // [sp+10h] [bp-4h]@1
  char outa; // [sp+20h] [bp+Ch]@1

  v3 = out;
  PSUtils::narrowify(&str, out);
  outa = EnumMapper::GetString(mapid, val, &str);
  v4 = PSUtils::widify(&result, &str);
  v5 = v3->m_charbuffer;
  if ( v3->m_charbuffer != v4->m_charbuffer )
  {
    v6 = (int)&v5[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v5[-1].m_data[8]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = v4->m_charbuffer;
    v3->m_charbuffer = v7;
    InterlockedIncrement((volatile LONG *)&v7[-1].m_data[8]);
  }
  v8 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  v9 = &str.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  return outa;
}

//----- (0041AE00) --------------------------------------------------------  // acclient.c:88206
char __cdecl EnumMapper::GetStringByDID(IDClass<_tagDataID,32,0> did, const unsigned int val, PStringBase<char> *out)
{
  char v3; // bl@1
  int v4; // eax@1
  int v5; // eax@2
  QualifiedDataID *v6; // eax@4
  int v7; // esi@6
  char v8; // al@7
  QualifiedDataID *v9; // eax@8
  QualifiedDataID v11; // [sp+8h] [bp-8h]@4

  v3 = 0;
  v4 = MasterDBMap::DivineType(did) - 36;
  if ( v4 )
  {
    v5 = v4 - 2;
    if ( v5 )
    {
      if ( v5 != 2 )
        return v3;
      QualifiedDataID::QualifiedDataID(&v11, did, 0x28u);
    }
    else
    {
      QualifiedDataID::QualifiedDataID(&v11, did, 0x26u);
    }
    v7 = DBObj::Get(v6);
    if ( !v7 )
      return v3;
    v8 = EnumIDMap::GetName((EnumIDMap *)v7, val, out);
  }
  else
  {
    QualifiedDataID::QualifiedDataID(&v11, did, 0x24u);
    v7 = DBObj::Get(v9);
    if ( !v7 )
      return v3;
    v8 = EnumMapper::GetString(v7, (PStringBase<char> *)val, out);
  }
  if ( v8 )
    v3 = 1;
  (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 20))(v7);
  return v3;
}

//----- (0041AEA0) --------------------------------------------------------  // acclient.c:88252
AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *__thiscall AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::scalar_deleting_destructor(AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *this, unsigned int a2)
{
  AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long,1>Vtbl *)&AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::vftable;
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
// 795468: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::vftable[3])(void *, char);
// 795470: using guessed type int (__thiscall *AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::vftable)(void *, char);

//----- (0041AF00) --------------------------------------------------------  // acclient.c:88278
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 795464: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::vftable[4])(void *, char);

//----- (0041AF90) --------------------------------------------------------  // acclient.c:88311
void __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1>Vtbl *)IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 795468: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::vftable[3])(void *, char);

//----- (0041B020) --------------------------------------------------------  // acclient.c:88344
void __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::add_internal(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1> *this, HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *data)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1> *v2; // esi@1
  unsigned int v3; // ebx@3
  unsigned int v4; // edx@3
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> **v5; // eax@3
  int v6; // eax@3

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::grow(this);
  v3 = v2->m_numBuckets;
  v4 = CaseInsensitiveStringBase<PStringBase<char>>::case_insensitive_hash(&data->m_hashKey) % v3;
  v5 = v2->m_buckets;
  data->m_hashNext = v5[v4];
  v5[v4] = data;
  v6 = (int)&v5[v4];
  if ( (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> **)v6 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> **)v6;
  ++v2->m_numElements;
}

//----- (0041B070) --------------------------------------------------------  // acclient.c:88367
unsigned int __thiscall EnumMapper::GetEnum(PStringBase<char> _string, PStringBase<char> _stringa)
{
  PSRefBufferCharData<char> *v2; // edi@1
  PSRefBufferCharData<char> *v3; // ebx@1
  int v4; // esi@4
  unsigned int v5; // edi@8
  volatile LONG *lpAddend; // [sp+10h] [bp-10h]@1
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> result; // [sp+14h] [bp-Ch]@1

  v2 = _stringa.m_charbuffer;
  v3 = _string.m_charbuffer;
  lpAddend = (volatile LONG *)&_stringa.m_charbuffer[-1];
  InterlockedIncrement((volatile LONG *)&_stringa.m_charbuffer[-1]);
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)&v3[11],
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)&_stringa);
  if ( result.m_currElement )
    _stringa.m_charbuffer = (PSRefBufferCharData<char> *)&result.m_currElement->func;
  else
    _stringa.m_charbuffer = 0;
  v4 = (int)&v2[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) && v2 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))v4)(&v2[-2].m_data[12], 1);
  if ( _stringa.m_charbuffer )
  {
    v5 = *(_DWORD *)&_stringa.m_charbuffer->m_data[0];
LABEL_11:
    if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    return v5;
  }
  if ( *(_DWORD *)&v3[3].m_data[4] )
  {
    InterlockedIncrement(lpAddend);
    v5 = EnumMapper::GetEnum(*(PStringBase<char> *)&v3[3].m_data[4]);
    goto LABEL_11;
  }
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v2 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))v4)(&v2[-2].m_data[12], 1);
  return 0;
}

//----- (0041B150) --------------------------------------------------------  // acclient.c:88414
char __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::resize_internal(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1> *v3; // esi@1
  char result; // al@2
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *v5; // edi@3
  int v6; // ecx@4
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> **v7; // eax@5
  int v8; // eax@6
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> **v9; // ebx@7
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *v10; // ecx@7
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *v11; // eax@9
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *v12; // edx@10
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  unsigned int v16; // ebx@23
  unsigned int v17; // edx@23
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> **v18; // eax@23
  int v19; // eax@23

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
        if ( v3->m_firstInterestingBucket == (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> **)v6 )
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
            v3->m_firstInterestingBucket = (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> **)v8;
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
    if ( (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> **)v3->m_buckets != v3->m_aInplaceBuckets )
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
          IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::resize_internal(
            v3,
            *v15);
        }
        v16 = v3->m_numBuckets;
        v17 = CaseInsensitiveStringBase<PStringBase<char>>::case_insensitive_hash(&v5->m_hashKey) % v16;
        v18 = v3->m_buckets;
        v5->m_hashNext = v18[v17];
        v18[v17] = v5;
        v19 = (int)&v18[v17];
        if ( (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> **)v19 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> **)v19;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (0041B290) --------------------------------------------------------  // acclient.c:88534
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::resize_internal(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1> *v2; // esi@1
  char result; // al@2
  HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *v4; // ebx@3
  int v5; // ecx@4
  HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **v6; // eax@5
  int v7; // eax@6
  HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **v8; // ecx@7
  HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *v9; // edi@7
  _BYTE v10[12]; // ST08_12@9
  unsigned int v11; // ST10_4@12
  HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *v12; // edi@12
  HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *v13; // ebp@13
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
        if ( v2->m_firstInterestingBucket == (HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **)v5 )
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
            v2->m_firstInterestingBucket = (HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **)v7;
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
    if ( (HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **)v2->m_buckets != v2->m_aInplaceBuckets )
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
          IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::resize_internal(
            v2,
            *v15);
        }
        v16 = (int)&v2->m_buckets[v12->m_hashKey % v2->m_numBuckets];
        v12->m_hashNext = *(HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **)v16;
        *(_DWORD *)v16 = v12;
        if ( (HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **)v16 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > **)v16;
        ++v2->m_numElements;
        v12 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (0041B3C0) --------------------------------------------------------  // acclient.c:88639
char __thiscall EnumMapper::GetEnum(PStringBase<char> _string, unsigned int *_out, unsigned int *_outa)
{
  unsigned int *v3; // edi@1
  unsigned int *v4; // esi@1
  PSRefBufferCharData<char> *v5; // ebp@1
  char v6; // al@11
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> result; // [sp+10h] [bp-Ch]@1

  v3 = _out;
  v4 = _out - 5;
  v5 = _string.m_charbuffer;
  InterlockedIncrement((volatile LONG *)_out - 4);
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)&v5[11],
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)&_out);
  if ( result.m_currElement )
  {
    *_outa = (unsigned int)result.m_currElement->func;
    LOBYTE(_out) = 1;
  }
  else
  {
    LOBYTE(_out) = 0;
  }
  if ( !InterlockedDecrement((volatile LONG *)v4 + 1) && v4 )
    (*(void (__thiscall **)(_DWORD, _DWORD))*v4)(v4, 1);
  if ( (_BYTE)_out )
  {
    if ( !InterlockedDecrement((volatile LONG *)v4 + 1) )
    {
      if ( v4 )
        (*(void (__thiscall **)(_DWORD, _DWORD))*v4)(v4, 1);
    }
    v6 = 1;
  }
  else if ( *(_DWORD *)&v5[3].m_data[4] )
  {
    InterlockedIncrement((volatile LONG *)v3 - 4);
    LOBYTE(_outa) = EnumMapper::GetEnum(*(PStringBase<char> *)&v5[3].m_data[4], v3);
    if ( !InterlockedDecrement((volatile LONG *)v4 + 1) && v4 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v4)(v4, 1);
    v6 = (char)_outa;
  }
  else
  {
    if ( !InterlockedDecrement((volatile LONG *)v4 + 1) && v4 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v4)(v4, 1);
    v6 = 0;
  }
  return v6;
}

//----- (0041B4D0) --------------------------------------------------------  // acclient.c:88693
char __cdecl EnumMapper::GetEnum(const unsigned int mapid, PStringBase<char> string, unsigned int *out)
{
  char v3; // bl@1
  char *v4; // esi@2
  int v6; // eax@6
  int v7; // eax@7
  DualEnumIDMap *v8; // esi@9
  PStringBase<char> v9; // esi@13
  char v10; // al@14
  unsigned int *v11; // ST08_4@16
  unsigned int *v12; // ST04_4@16
  char *v13; // esi@20
  IDClass<_tagDataID,32,0> did; // [sp+8h] [bp-8h]@1
  DBObjGrabber<DualEnumIDMap> enumidmap; // [sp+Ch] [bp-4h]@9

  v3 = 0;
  DBObj::GetDIDByEnum(&did, mapid, 1);
  if ( did.id == INVALID_DID_11.id )
  {
    v4 = &string.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&string.m_charbuffer[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    return 0;
  }
  v6 = MasterDBMap::DivineType(did) - 36;
  if ( v6 )
  {
    v7 = v6 - 2;
    if ( v7 )
    {
      if ( v7 == 2 )
      {
        DBObjGrabber<DualEnumIDMap>::DBObjGrabber<DualEnumIDMap>(&enumidmap, did);
        v8 = enumidmap.m_object;
        if ( enumidmap.m_object )
        {
          if ( EnumIDMap::NameToEnum((EnumIDMap *)&enumidmap.m_object->vfptr, &string, out) )
            v3 = 1;
          v8->vfptr->Release((Interface *)v8);
        }
      }
      goto LABEL_20;
    }
    DBObjGrabber<EnumIDMap>::DBObjGrabber<EnumIDMap>((DBObjGrabber<EnumIDMap> *)&enumidmap, did);
    v9.m_charbuffer = (PSRefBufferCharData<char> *)enumidmap.m_object;
    if ( enumidmap.m_object )
    {
      v10 = EnumIDMap::NameToEnum((EnumIDMap *)&enumidmap.m_object->vfptr, &string, out);
LABEL_17:
      if ( v10 )
        v3 = 1;
      (*(void (__thiscall **)(PStringBase<char>))(*(_DWORD *)&v9.m_charbuffer->m_data[0] + 20))(v9.m_charbuffer);
      goto LABEL_20;
    }
  }
  else
  {
    DBObjGrabber<EnumMapper>::DBObjGrabber<EnumMapper>((DBObjGrabber<EnumMapper> *)&enumidmap, did);
    v9.m_charbuffer = (PSRefBufferCharData<char> *)enumidmap.m_object;
    if ( enumidmap.m_object )
    {
      v11 = out;
      v12 = (unsigned int *)string.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&string.m_charbuffer[-1]);
      v10 = EnumMapper::GetEnum(v9, v12, v11);
      goto LABEL_17;
    }
  }
LABEL_20:
  v13 = &string.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&string.m_charbuffer[-1]) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  return v3;
}

//----- (0041B610) --------------------------------------------------------  // acclient.c:88772
char __cdecl EnumMapper::InqEnum(const unsigned int mapid, PStringBase<unsigned short> string, unsigned int *out)
{
  PSRefBufferCharData<char> *v3; // ecx@0
  unsigned int *v4; // ST08_4@1
  PStringBase<char> v5; // ST04_4@1
  char v6; // al@1
  char *v7; // esi@1
  char v8; // bl@1
  char *v9; // esi@4
  PStringBase<char> str; // [sp+0h] [bp-4h]@1

  str.m_charbuffer = v3;
  PSUtils::narrowify(&str, &string);
  v4 = out;
  v5.m_charbuffer = str.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&str.m_charbuffer[-1]);
  v6 = EnumMapper::GetEnum(mapid, v5, v4);
  v7 = &str.m_charbuffer[-2].m_data[12];
  v8 = v6;
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  v9 = (char *)&string.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&string.m_charbuffer[-1].m_data[8]) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  return v8;
}

//----- (0041B6A0) --------------------------------------------------------  // acclient.c:88800
char __cdecl EnumMapper::GetEnumByDID(IDClass<_tagDataID,32,0> did, PStringBase<char> string, unsigned int *out)
{
  char v3; // bl@1
  int v4; // eax@1
  int v5; // eax@2
  QualifiedDataID *v6; // eax@4
  int v7; // esi@4
  QualifiedDataID *v8; // eax@8
  int v9; // esi@8
  QualifiedDataID *v10; // eax@12
  int v11; // esi@12
  unsigned int *v12; // ST08_4@13
  unsigned int *v13; // ST04_4@13
  char *v14; // esi@16
  QualifiedDataID v16; // [sp+8h] [bp-8h]@4

  v3 = 0;
  v4 = MasterDBMap::DivineType(did) - 36;
  if ( v4 )
  {
    v5 = v4 - 2;
    if ( v5 )
    {
      if ( v5 == 2 )
      {
        QualifiedDataID::QualifiedDataID(&v16, did, 0x28u);
        v7 = DBObj::Get(v6);
        if ( v7 )
        {
          if ( EnumIDMap::NameToEnum((EnumIDMap *)v7, &string, out) )
            v3 = 1;
          (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 20))(v7);
        }
      }
    }
    else
    {
      QualifiedDataID::QualifiedDataID(&v16, did, 0x26u);
      v9 = DBObj::Get(v8);
      if ( v9 )
      {
        if ( EnumIDMap::NameToEnum((EnumIDMap *)v9, &string, out) )
          v3 = 1;
        (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 20))(v9);
      }
    }
  }
  else
  {
    QualifiedDataID::QualifiedDataID(&v16, did, 0x24u);
    v11 = DBObj::Get(v10);
    if ( v11 )
    {
      v12 = out;
      v13 = (unsigned int *)string.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&string.m_charbuffer[-1]);
      if ( EnumMapper::GetEnum((PStringBase<char>)v11, v13, v12) )
        v3 = 1;
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 20))(v11);
    }
  }
  v14 = &string.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&string.m_charbuffer[-1]) && v14 )
    (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
  return v3;
}

//----- (0041B7C0) --------------------------------------------------------  // acclient.c:88868
char __thiscall HashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long,1>::set(HashTable<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long,1> *this, CaseInsensitiveStringBase<PStringBase<char> > *_key, const unsigned int *_data)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v3; // edi@1
  char v4; // al@2
  void *v5; // esi@3
  PSRefBufferCharData<char> *v6; // eax@4
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> result; // [sp+8h] [bp-Ch]@1

  v3 = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)&this->m_intrusiveTable;
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)&this->m_intrusiveTable,
    &result,
    _key);
  if ( result.m_currElement )
  {
    result.m_currElement->func = (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))*_data;
    v4 = 1;
  }
  else
  {
    v5 = operator new(0xCu);
    if ( v5 )
    {
      v6 = _key->m_charbuffer;
      *(_DWORD *)v5 = _key->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v6[-1]);
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = *_data;
    }
    else
    {
      v5 = 0;
    }
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
      v3,
      &result,
      (CaseInsensitiveStringBase<PStringBase<char> > *)v5);
    if ( !result.m_currElement )
      IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::add_internal(
        (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1> *)v3,
        (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *)v5);
    v4 = 1;
  }
  return v4;
}

//----- (0041B850) --------------------------------------------------------  // acclient.c:88915
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::resize(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1> *this, unsigned int _numBuckets)
{
  unsigned int *v2; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1> *v3; // edi@1
  unsigned int *v4; // eax@1

  v2 = g_bucketSizesEnd;
  v3 = this;
  v4 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v2 )
    --v4;
  return IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::resize_internal(
           v3,
           *v4);
}

//----- (0041B8A0) --------------------------------------------------------  // acclient.c:88932
void __cdecl SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,SB_Default>(const int *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1> *io_object, Archive *io_archive)
{
  Archive *v3; // edi@1
  unsigned int *v4; // esi@4
  unsigned int *v5; // ebp@4
  const unsigned int *v6; // eax@4
  int v7; // ebx@6
  unsigned int v8; // eax@8
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // eax@19
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // ebx@19
  HashTableData<unsigned long,HeritageGroup_CG> *v11; // esi@19
  HashTableData<unsigned long,HeritageGroup_CG> **v12; // ebp@19
  unsigned int v13; // eax@21
  unsigned int v14; // eax@30
  HashTableData<unsigned long,Sex_CG> *v15; // ebx@31
  unsigned int v16; // ebp@31
  void *v17; // eax@32
  void *v18; // esi@32
  volatile LONG *v19; // ST10_4@33
  unsigned int v20; // eax@35
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
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::resize(
        io_object,
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
        PStringBase<char>::Serialize((PStringBase<char> *)&v11->m_data, v3);
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
            v19 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
            *((_DWORD *)v17 + 2) = PStringBase<char>::s_NullBuffer.m_charbuffer;
            InterlockedIncrement(v19);
          }
          else
          {
            v18 = 0;
          }
          Archive::CheckAlignment(v3, 4u);
          v20 = Archive::GetBytes(v3, 4u);
          if ( v20 )
          {
            if ( v3->m_flags & 1 )
              *(_DWORD *)v20 = *(_DWORD *)v18;
            else
              *(_DWORD *)v18 = *(_DWORD *)v20;
          }
          PStringBase<char>::Serialize((PStringBase<char> *)v18 + 2, v3);
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

//----- (0041BAC0) --------------------------------------------------------  // acclient.c:89088
void __thiscall EnumMapper::Destroy(EnumMapper *this)
{
  EnumMapper *v1; // esi@1
  EnumMapper *v2; // ecx@1

  v1 = this;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_string_to_id_map.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *)&v1->m_id_to_string_map.m_intrusiveTable);
  v2 = v1->m_base_emp;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_base_emp = 0;
    v1->m_base_emp_did.id = INVALID_DID_11.id;
  }
  else
  {
    v1->m_base_emp_did.id = INVALID_DID_11.id;
  }
}

//----- (0041BB00) --------------------------------------------------------  // acclient.c:89110
AutoGrowHashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *__thiscall AutoGrowHashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>>::vector_deleting_destructor(AutoGrowHashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *this, unsigned int a2)
{
  AutoGrowHashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char> >,1>Vtbl *)HashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>,1>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::vftable;
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
// 795464: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::vftable[4])(void *, char);
// 79546C: using guessed type int (__thiscall *HashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>,1>::vftable[2])(void *, char);

//----- (0041BB60) --------------------------------------------------------  // acclient.c:89136
void __thiscall EnumMapper::~EnumMapper(EnumMapper *this)
{
  EnumMapper *v1; // esi@1
  EnumMapper *v2; // ecx@1
  void *v3; // eax@3
  void *v4; // eax@5

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&EnumMapper::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_string_to_id_map.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *)&v1->m_id_to_string_map.m_intrusiveTable);
  v2 = v1->m_base_emp;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_base_emp = 0;
  }
  v1->m_base_emp_did.id = INVALID_DID_11.id;
  v1->m_string_to_id_map.vfptr = (HashTable<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long,1>Vtbl *)&AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&v1->m_string_to_id_map.m_intrusiveTable);
  v3 = v1->m_string_to_id_map.m_intrusiveTable.m_buckets;
  v1->m_string_to_id_map.m_intrusiveTable.vfptr = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long> *,1>Vtbl *)IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::vftable;
  if ( v3 != v1->m_string_to_id_map.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v3);
  v1->m_string_to_id_map.m_intrusiveTable.m_buckets = 0;
  v1->m_string_to_id_map.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_string_to_id_map.m_intrusiveTable.m_numBuckets = 0;
  v1->m_string_to_id_map.m_intrusiveTable.m_numElements = 0;
  v1->m_id_to_string_map.vfptr = (HashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char> >,1>Vtbl *)HashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>,1>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *)&v1->m_id_to_string_map.m_intrusiveTable);
  v4 = v1->m_id_to_string_map.m_intrusiveTable.m_buckets;
  v1->m_id_to_string_map.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char> > > *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::vftable;
  if ( v4 != v1->m_id_to_string_map.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v4);
  v1->m_id_to_string_map.m_intrusiveTable.m_buckets = 0;
  v1->m_id_to_string_map.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_id_to_string_map.m_intrusiveTable.m_numBuckets = 0;
  v1->m_id_to_string_map.m_intrusiveTable.m_numElements = 0;
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 795464: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::vftable[4])(void *, char);
// 795468: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::vftable[3])(void *, char);
// 79546C: using guessed type int (__thiscall *HashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>,1>::vftable[2])(void *, char);
// 795470: using guessed type int (__thiscall *AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::vftable)(void *, char);
// 795478: using guessed type __int32 (__stdcall *EnumMapper::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0041BC30) --------------------------------------------------------  // acclient.c:89189
void __thiscall EnumMapper::EnumMapper(EnumMapper *this)
{
  EnumMapper *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, INVALID_DID_11);
  v1->vfptr = (InterfaceVtbl *)&EnumMapper::vftable;
  v1->m_base_emp_did.id = INVALID_DID_11.id;
  v1->m_base_emp = 0;
  v1->m_id_to_string_map.vfptr = (HashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char> >,1>Vtbl *)HashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>,1>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>(
    &v1->m_id_to_string_map.m_intrusiveTable,
    0);
  v1->m_id_to_string_map.vfptr = (HashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char> >,1>Vtbl *)HashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>,1>::vftable;
  v1->m_string_to_id_map.vfptr = (HashTable<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long,1>Vtbl *)&AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::vftable;
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>(
    &v1->m_string_to_id_map.m_intrusiveTable,
    0);
  v1->m_string_to_id_map.vfptr = (HashTable<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long,1>Vtbl *)&AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::vftable;
}
// 79546C: using guessed type int (__thiscall *HashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>,1>::vftable[2])(void *, char);
// 795470: using guessed type int (__thiscall *AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::vftable)(void *, char);
// 795478: using guessed type __int32 (__stdcall *EnumMapper::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0041BCA0) --------------------------------------------------------  // acclient.c:89214
EnumMapper *__thiscall EnumMapper::scalar_deleting_destructor(EnumMapper *this, unsigned int a2)
{
  EnumMapper *v2; // esi@1

  v2 = this;
  EnumMapper::~EnumMapper(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0041BCD0) --------------------------------------------------------  // acclient.c:89226
void __cdecl EnumMapper::Allocator()
{
  EnumMapper *v0; // eax@1

  v0 = (EnumMapper *)operator new(0x120u);
  if ( v0 )
    EnumMapper::EnumMapper(v0);
}

//----- (0041BCF0) --------------------------------------------------------  // acclient.c:89236
void __thiscall EnumMapper::Serialize(EnumMapper *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  EnumMapper *v3; // ebx@1
  unsigned int v4; // eax@1
  unsigned int *v5; // edi@8
  unsigned int *v6; // eax@8
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // eax@10
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // esi@10
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // ebp@10
  HashTableData<unsigned long,HeritageGroup_CG> **v10; // edi@10
  HashTable<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long,1> *v11; // ebx@11
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+8h] [bp-Ch]@10

  v2 = io_archive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  Archive::CheckAlignment(v2, 4u);
  v4 = Archive::GetBytes(v2, 4u);
  if ( v4 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v4 = v3->m_base_emp_did.id;
    else
      v3->m_base_emp_did.id = *(_DWORD *)v4;
  }
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short> > *,0> *)&v3->m_id_to_string_map.m_intrusiveTable);
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,SB_Default>(
    (const int *)&io_archive,
    &v3->m_id_to_string_map.m_intrusiveTable,
    v2);
  if ( ~LOBYTE(v2->m_flags) & 1 )
  {
    IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&v3->m_string_to_id_map.m_intrusiveTable);
    v5 = g_bucketSizesEnd;
    io_archive = (Archive *)v3->m_id_to_string_map.m_intrusiveTable.m_numElements;
    v6 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, (const unsigned int *)&io_archive);
    if ( v6 == v5 )
      --v6;
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::resize_internal(
      &v3->m_string_to_id_map.m_intrusiveTable,
      *v6);
    v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v3->m_id_to_string_map.m_intrusiveTable,
           &result);
    v8 = v7->m_currElement;
    v9 = v7->m_currHashTable;
    v10 = v7->m_currBucket;
    if ( v8 )
    {
      v11 = (HashTable<CaseInsensitiveStringBase<PStringBase<char> >,unsigned long,1> *)&v3->m_string_to_id_map.vfptr;
      do
      {
LABEL_12:
        HashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long,1>::set(
          v11,
          (CaseInsensitiveStringBase<PStringBase<char> > *)&v8->m_data,
          &v8->m_hashKey);
        v8 = v8->m_hashNext;
      }
      while ( v8 );
      while ( 1 )
      {
        ++v10;
        if ( v10 == &v9->m_buckets[v9->m_numBuckets] )
          break;
        if ( *v10 )
        {
          v8 = *v10;
          if ( *v10 )
            goto LABEL_12;
          return;
        }
      }
    }
  }
}

//----- (006C4A40) --------------------------------------------------------  // acclient.c:732990
int _E1_11()
{
  return atexit(_E2_11);
}

