/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : BasePropertyDesc
   Object     : ENGINE\property\BasePropertyDesc.obj
   Functions  : 83
   Addresses  : 0042A260 - 00728100 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0042A260) --------------------------------------------------------  // acclient.c:103044
char __thiscall BasePropertyDesc::InqPropertyEnum(BasePropertyDesc *this, const unsigned int _enum_val, PStringBase<char> *_enum_str)
{
  unsigned int v3; // eax@1
  char result; // al@2

  v3 = this->m_propertyType;
  if ( v3 == 9 )
  {
    result = EnumMapper::GetStringByDID((IDClass<_tagDataID,32,0>)this->m_data, _enum_val, _enum_str);
  }
  else if ( v3 == 20 )
  {
    result = MasterProperty::InqPropertyNameStringStatic(_enum_val, _enum_str);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0042A2A0) --------------------------------------------------------  // acclient.c:103066
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0> *v2; // esi@1
  HashTableData<unsigned long,AvailableProperty> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::vftable;
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
// 797908: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::vftable[3])(void *, char);

//----- (0042A2E0) --------------------------------------------------------  // acclient.c:103087
void __thiscall BasePropertyDesc::GetSubDataIDs(BasePropertyDesc *this, QualifiedDataIDArray *_id_array)
{
  QualifiedDataID *v2; // eax@3
  QualifiedDataID v3; // [sp+0h] [bp-8h]@3

  switch ( this->m_propertyType )
  {
    case 9u:
    case 0xFu:
    case 0x10u:
    case 0x14u:
      switch ( this->m_propertyType )
      {
        case 9u:
        case 0xFu:
        case 0x10u:
        case 0x14u:
          QualifiedDataID::QualifiedDataID(&v3, (IDClass<_tagDataID,32,0>)this->m_data, 0);
          QualifiedDataIDArray::AddQDID(_id_array, v2, 0);
          break;
        default:
          return;
      }
      return;
    default:
      return;
  }
}

//----- (0042A360) --------------------------------------------------------  // acclient.c:103117
void __thiscall BasePropertyDesc::Serialize(BasePropertyDesc *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  BasePropertyDesc *v3; // edi@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@5
  unsigned int v6; // eax@9
  unsigned int v7; // eax@13
  unsigned int v8; // eax@17
  unsigned int v9; // eax@21
  char v10; // al@25
  BasePropertyValue *v11; // ecx@26
  BasePropertyValue *v12; // ecx@29
  bool v13; // zf@30
  BasePropertyValue *v14; // eax@34
  char v15; // al@36
  BasePropertyValue *v16; // ecx@37
  BasePropertyValue *v17; // ecx@40
  BasePropertyValue *v18; // eax@45
  char v19; // al@47
  BasePropertyValue *v20; // ecx@48
  BasePropertyValue *v21; // ecx@51
  BasePropertyValue *v22; // eax@56
  unsigned int v23; // eax@58
  unsigned __int8 v24; // bl@62
  unsigned int v25; // eax@62
  unsigned __int8 v26; // bl@68
  unsigned int v27; // eax@68
  unsigned __int8 v28; // bl@74
  unsigned int v29; // eax@74
  unsigned __int8 v30; // bl@80
  unsigned int v31; // eax@80

  v2 = io_archive;
  v3 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(v2, 4u);
  if ( v4 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v4 = v3->m_propertyName;
    else
      v3->m_propertyName = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(v2, 4u);
  v5 = Archive::GetBytes(v2, 4u);
  if ( v5 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v5 = v3->m_propertyType;
    else
      v3->m_propertyType = *(_DWORD *)v5;
  }
  Archive::CheckAlignment(v2, 4u);
  v6 = Archive::GetBytes(v2, 4u);
  if ( v6 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v6 = v3->m_propertyGroup;
    else
      v3->m_propertyGroup = *(_DWORD *)v6;
  }
  Archive::CheckAlignment(v2, 4u);
  v7 = Archive::GetBytes(v2, 4u);
  if ( v7 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v7 = v3->m_propertyProvider;
    else
      v3->m_propertyProvider = *(_DWORD *)v7;
  }
  Archive::CheckAlignment(v2, 4u);
  v8 = Archive::GetBytes(v2, 4u);
  if ( v8 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v8 = v3->m_data;
    else
      v3->m_data = *(_DWORD *)v8;
  }
  Archive::CheckAlignment(v2, 4u);
  v9 = Archive::GetBytes(v2, 4u);
  if ( v9 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v9 = v3->m_ePatchFlags;
    else
      v3->m_ePatchFlags = *(_DWORD *)v9;
  }
  v10 = LOBYTE(v2->m_flags);
  if ( v10 & 1 )
  {
    LOBYTE(io_archive) = v3->m_defaultValue != 0;
    Serializer::SerializeObject((bool *)&io_archive, v2);
    v11 = v3->m_defaultValue;
    if ( v11 )
      ((void (__thiscall *)(BasePropertyValue *, Archive *, unsigned int))v11->vfptr[23].__vecDelDtor)(
        v11,
        v2,
        v3->m_propertyName);
  }
  else if ( ~v10 & 1 )
  {
    v12 = v3->m_defaultValue;
    if ( v12 )
    {
      v13 = v12->m_cRef-- == 1;
      if ( v13 )
        ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
      v3->m_defaultValue = 0;
    }
    LOBYTE(io_archive) = 0;
    Serializer::SerializeObject((bool *)&io_archive, v2);
    if ( (_BYTE)io_archive )
    {
      MasterProperty::AllocatePropertyValue(v3->m_propertyType);
      v3->m_defaultValue = v14;
      if ( v14 )
        ((void (__thiscall *)(BasePropertyValue *, Archive *, unsigned int))v14->vfptr[23].__vecDelDtor)(
          v14,
          v2,
          v3->m_propertyName);
    }
  }
  v15 = LOBYTE(v2->m_flags);
  if ( v15 & 1 )
  {
    LOBYTE(io_archive) = v3->m_minValue != 0;
    Serializer::SerializeObject((bool *)&io_archive, v2);
    v16 = v3->m_minValue;
    if ( v16 )
      ((void (__thiscall *)(BasePropertyValue *, Archive *, unsigned int))v16->vfptr[23].__vecDelDtor)(
        v16,
        v2,
        v3->m_propertyName);
  }
  else if ( ~v15 & 1 )
  {
    v17 = v3->m_minValue;
    if ( v17 )
    {
      v13 = v17->m_cRef-- == 1;
      if ( v13 )
        ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
      v3->m_minValue = 0;
    }
    LOBYTE(io_archive) = 0;
    Serializer::SerializeObject((bool *)&io_archive, v2);
    if ( (_BYTE)io_archive )
    {
      MasterProperty::AllocatePropertyValue(v3->m_propertyType);
      v3->m_minValue = v18;
      if ( v18 )
        ((void (__thiscall *)(BasePropertyValue *, Archive *, unsigned int))v18->vfptr[23].__vecDelDtor)(
          v18,
          v2,
          v3->m_propertyName);
    }
  }
  v19 = LOBYTE(v2->m_flags);
  if ( v19 & 1 )
  {
    LOBYTE(io_archive) = v3->m_maxValue != 0;
    Serializer::SerializeObject((bool *)&io_archive, v2);
    v20 = v3->m_maxValue;
    if ( v20 )
      ((void (__thiscall *)(BasePropertyValue *, Archive *, unsigned int))v20->vfptr[23].__vecDelDtor)(
        v20,
        v2,
        v3->m_propertyName);
  }
  else if ( ~v19 & 1 )
  {
    v21 = v3->m_maxValue;
    if ( v21 )
    {
      v13 = v21->m_cRef-- == 1;
      if ( v13 )
        ((void (__stdcall *)(signed int))v21->vfptr->__vecDelDtor)(1);
      v3->m_maxValue = 0;
    }
    LOBYTE(io_archive) = 0;
    Serializer::SerializeObject((bool *)&io_archive, v2);
    if ( (_BYTE)io_archive )
    {
      MasterProperty::AllocatePropertyValue(v3->m_propertyType);
      v3->m_maxValue = v22;
      if ( v22 )
        ((void (__thiscall *)(BasePropertyValue *, Archive *, unsigned int))v22->vfptr[23].__vecDelDtor)(
          v22,
          v2,
          v3->m_propertyName);
    }
  }
  Archive::CheckAlignment(v2, 4u);
  v23 = Archive::GetBytes(v2, 4u);
  if ( v23 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v23 = LODWORD(v3->m_fPredictionTimeout);
    else
      LODWORD(v3->m_fPredictionTimeout) = *(_DWORD *)v23;
  }
  v24 = LOBYTE(v3->m_inheritanceType);
  Archive::CheckAlignment(v2, 1u);
  v25 = Archive::GetBytes(v2, 1u);
  if ( v25 )
  {
    if ( v2->m_flags & 1 )
      *(_BYTE *)v25 = v24;
    else
      v24 = *(_BYTE *)v25;
  }
  if ( !(v2->m_flags & 5) )
    v3->m_inheritanceType = v24;
  v26 = LOBYTE(v3->m_datFileType);
  Archive::CheckAlignment(v2, 1u);
  v27 = Archive::GetBytes(v2, 1u);
  if ( v27 )
  {
    if ( v2->m_flags & 1 )
      *(_BYTE *)v27 = v26;
    else
      v26 = *(_BYTE *)v27;
  }
  if ( !(v2->m_flags & 5) )
    v3->m_datFileType = v26;
  v28 = LOBYTE(v3->m_propagationType);
  Archive::CheckAlignment(v2, 1u);
  v29 = Archive::GetBytes(v2, 1u);
  if ( v29 )
  {
    if ( v2->m_flags & 1 )
      *(_BYTE *)v29 = v28;
    else
      v28 = *(_BYTE *)v29;
  }
  if ( !(v2->m_flags & 5) )
    v3->m_propagationType = v28;
  v30 = LOBYTE(v3->m_cachingType);
  Archive::CheckAlignment(v2, 1u);
  v31 = Archive::GetBytes(v2, 1u);
  if ( v31 )
  {
    if ( v2->m_flags & 1 )
      *(_BYTE *)v31 = v30;
    else
      v30 = *(_BYTE *)v31;
  }
  if ( !(v2->m_flags & 5) )
    v3->m_cachingType = v30;
  Serializer::SerializeObject(&v3->m_bRequired, v2);
  Serializer::SerializeObject(&v3->m_bReadOnly, v2);
  Serializer::SerializeObject(&v3->m_bNoCheckpoint, v2);
  Serializer::SerializeObject(&v3->m_bRecorded, v2);
  Serializer::SerializeObject(&v3->m_bDoNotReplay, v2);
  Serializer::SerializeObject(&v3->m_bAbsoluteTimeStamp, v2);
  Serializer::SerializeObject(&v3->m_bGroupable, v2);
  Serializer::SerializeObject(&v3->m_bPropagateToChildren, v2);
  AvailablePropertySet::Serialize(&v3->m_availableProperties, v2);
}

//----- (0042A780) --------------------------------------------------------  // acclient.c:103380
void __cdecl BasePropertyDesc::InitializeAllAvailablePropertySet()
{
  MasterProperty *v0; // ebp@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v1; // eax@2
  HashTableData<unsigned long,HeritageGroup_CG> *v2; // esi@2
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // ebx@2
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // edi@2
  MasterPropertyGrabber mpr; // [sp+4h] [bp-10h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+8h] [bp-Ch]@2

  MasterPropertyGrabber::MasterPropertyGrabber(&mpr);
  v0 = mpr.m_object;
  if ( mpr.m_object )
  {
    v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&mpr.m_object->m_properties.m_intrusiveTable,
           &result);
    v2 = v1->m_currElement;
    v3 = v1->m_currHashTable;
    v4 = v1->m_currBucket;
    if ( v2 )
    {
      do
      {
LABEL_3:
        if ( v2->m_hashKey )
          AvailablePropertySet::AddProperty(&BasePropertyDesc::s_allAvailableProperties, v2->m_hashKey);
        v2 = v2->m_hashNext;
      }
      while ( v2 );
      while ( 1 )
      {
        ++v4;
        if ( v4 == &v3->m_buckets[v3->m_numBuckets] )
          break;
        if ( *v4 )
        {
          v2 = *v4;
          if ( *v4 )
            goto LABEL_3;
          break;
        }
      }
    }
    v0->vfptr->Release((Interface *)v0);
  }
}

//----- (0042A800) --------------------------------------------------------  // acclient.c:103429
AvailablePropertySet *__thiscall BasePropertyDesc::GetAvailablePropertySet(BasePropertyDesc *this)
{
  AvailablePropertySet *result; // eax@4

  if ( this->m_bAllAvailable )
  {
    if ( !stru_81796C.m_numElements )
      BasePropertyDesc::InitializeAllAvailablePropertySet();
    result = &BasePropertyDesc::s_allAvailableProperties;
  }
  else
  {
    result = &this->m_availableProperties;
  }
  return result;
}

//----- (0042A830) --------------------------------------------------------  // acclient.c:103447
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,AvailableProperty> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,AvailableProperty> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 797908: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::vftable[3])(void *, char);

//----- (0042A9B0) --------------------------------------------------------  // acclient.c:103581
HashTable<unsigned long,AvailableProperty,0> *__thiscall HashTable<unsigned long,AvailableProperty,0>::vector_deleting_destructor(HashTable<unsigned long,AvailableProperty,0> *this, unsigned int a2)
{
  HashTable<unsigned long,AvailableProperty,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,AvailableProperty,0>Vtbl *)HashTable<unsigned long,AvailableProperty,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::vftable;
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
// 797908: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::vftable[3])(void *, char);
// 79790C: using guessed type int (__thiscall *HashTable<unsigned long,AvailableProperty,0>::vftable[2])(void *, char);

//----- (0042AA10) --------------------------------------------------------  // acclient.c:103607
void __thiscall BasePropertyDesc::BasePropertyDesc(BasePropertyDesc *this)
{
  BasePropertyDesc *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&BasePropertyDesc::vftable;
  this->m_propertyName = 0;
  this->m_propertyType = 0;
  this->m_propertyGroup = 0;
  this->m_propertyProvider = 1;
  this->m_data = 0;
  this->m_ePatchFlags = 0;
  this->m_defaultValue = 0;
  this->m_minValue = 0;
  this->m_maxValue = 0;
  this->m_availableProperties.m_reqHash.vfptr = (HashTable<unsigned long,AvailableProperty,0>Vtbl *)HashTable<unsigned long,AvailableProperty,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>(
    &this->m_availableProperties.m_reqHash.m_intrusiveTable,
    0x17u);
  v1->m_inheritanceType = 2;
  v1->m_datFileType = 2;
  v1->m_propagationType = 4;
  v1->m_cachingType = 0;
  v1->m_bRequired = 0;
  v1->m_bReadOnly = 0;
  v1->m_bPropagateToChildren = 0;
  v1->m_bNoCheckpoint = 0;
  v1->m_bAbsoluteTimeStamp = 0;
  v1->m_bGroupable = 0;
  v1->m_bAllAvailable = 0;
  v1->m_bDoNotReplay = 0;
  v1->m_bRecorded = 0;
  v1->m_nMinElements = 0;
  v1->m_nMaxElements = 0xFFFF;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strHelp.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v1->m_fPredictionTimeout = Const_DefaultPredictedExpirationTime;
}
// 79790C: using guessed type int (__thiscall *HashTable<unsigned long,AvailableProperty,0>::vftable[2])(void *, char);
// 797910: using guessed type int (__thiscall *BasePropertyDesc::vftable)(void *, char);

//----- (0042AAE0) --------------------------------------------------------  // acclient.c:103652
void __thiscall BasePropertyDesc::~BasePropertyDesc(BasePropertyDesc *this)
{
  BasePropertyDesc *v1; // esi@1
  BasePropertyValue *v2; // ecx@1
  bool v3; // zf@2
  BasePropertyValue *v4; // ecx@5
  BasePropertyValue *v5; // ecx@9
  int v6; // edi@13
  void *v7; // eax@16

  v1 = this;
  v2 = this->m_defaultValue;
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&BasePropertyDesc::vftable;
  if ( v2 )
  {
    v3 = v2->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->m_defaultValue = 0;
  }
  v4 = v1->m_minValue;
  if ( v4 )
  {
    v3 = v4->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v1->m_minValue = 0;
  }
  v5 = v1->m_maxValue;
  if ( v5 )
  {
    v3 = v5->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    v1->m_maxValue = 0;
  }
  v6 = (int)&v1->m_strHelp.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v1->m_availableProperties.m_reqHash.vfptr = (HashTable<unsigned long,AvailableProperty,0>Vtbl *)HashTable<unsigned long,AvailableProperty,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_availableProperties.m_reqHash.m_intrusiveTable);
  v7 = v1->m_availableProperties.m_reqHash.m_intrusiveTable.m_buckets;
  v1->m_availableProperties.m_reqHash.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::vftable;
  if ( v7 != v1->m_availableProperties.m_reqHash.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v7);
  v1->m_availableProperties.m_reqHash.m_intrusiveTable.m_buckets = 0;
  v1->m_availableProperties.m_reqHash.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_availableProperties.m_reqHash.m_intrusiveTable.m_numBuckets = 0;
  v1->m_availableProperties.m_reqHash.m_intrusiveTable.m_numElements = 0;
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 797908: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::vftable[3])(void *, char);
// 79790C: using guessed type int (__thiscall *HashTable<unsigned long,AvailableProperty,0>::vftable[2])(void *, char);
// 797910: using guessed type int (__thiscall *BasePropertyDesc::vftable)(void *, char);

//----- (0042AB90) --------------------------------------------------------  // acclient.c:103709
BasePropertyDesc *__thiscall BasePropertyDesc::vector_deleting_destructor(BasePropertyDesc *this, unsigned int a2)
{
  BasePropertyDesc *v2; // esi@1

  v2 = this;
  BasePropertyDesc::~BasePropertyDesc(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006C51F0) --------------------------------------------------------  // acclient.c:733438
int _E73_19()
{
  PStringBase<char>::PStringBase<char>(&Type, "Type");
  return atexit(_E74_22);
}

//----- (006C5210) --------------------------------------------------------  // acclient.c:733445
int _E76_12()
{
  PStringBase<char>::PStringBase<char>(&Group, "Group");
  return atexit(_E77_40);
}

//----- (006C5230) --------------------------------------------------------  // acclient.c:733452
int _E79_12()
{
  PStringBase<char>::PStringBase<char>(&Default, "Default");
  return atexit(_E80_14);
}

//----- (006C5250) --------------------------------------------------------  // acclient.c:733459
int _E82_4()
{
  PStringBase<char>::PStringBase<char>(&Min, "Min");
  return atexit(_E83_5);
}

//----- (006C5270) --------------------------------------------------------  // acclient.c:733466
int _E85_1()
{
  PStringBase<char>::PStringBase<char>(&Max, "Max");
  return atexit(_E86_3);
}

//----- (006C5290) --------------------------------------------------------  // acclient.c:733473
int _E88_1()
{
  PStringBase<char>::PStringBase<char>(&Available, "Available");
  return atexit(_E89_14);
}

//----- (006C52B0) --------------------------------------------------------  // acclient.c:733480
int _E91_3()
{
  PStringBase<char>::PStringBase<char>(&AllAvailable, "AllAvailable");
  return atexit(_E92_11);
}

//----- (006C52D0) --------------------------------------------------------  // acclient.c:733487
int _E94_1()
{
  PStringBase<char>::PStringBase<char>(&Required, "Required");
  return atexit(sub_727C20);
}

//----- (006C52F0) --------------------------------------------------------  // acclient.c:733494
int _E97_3()
{
  PStringBase<char>::PStringBase<char>(&ClassOnly, "ClassOnly");
  return atexit(_E98_26);
}

//----- (006C5310) --------------------------------------------------------  // acclient.c:733501
int _E100_6()
{
  PStringBase<char>::PStringBase<char>(&InstanceOnly, "InstanceOnly");
  return atexit(_E101_56);
}

//----- (006C5330) --------------------------------------------------------  // acclient.c:733508
int _E103_3()
{
  PStringBase<char>::PStringBase<char>(&ClientOnlyData, "ClientOnlyData");
  return atexit(_E104_26);
}

//----- (006C5350) --------------------------------------------------------  // acclient.c:733515
int _E106_5()
{
  PStringBase<char>::PStringBase<char>(&ServerOnlyData, "ServerOnlyData");
  return atexit(_E107_58);
}

//----- (006C5370) --------------------------------------------------------  // acclient.c:733522
int _E109_2()
{
  PStringBase<char>::PStringBase<char>(&NetPredictedSharedVisually, "NetPredictedSharedVisually");
  return atexit(sub_727D10);
}

//----- (006C5390) --------------------------------------------------------  // acclient.c:733529
int _E112_4()
{
  PStringBase<char>::PStringBase<char>(&NetPredictedSharedPrivately, "NetPredictedSharedPrivately");
  return atexit(_E113_38);
}

//----- (006C53B0) --------------------------------------------------------  // acclient.c:733536
int _E115_2()
{
  PStringBase<char>::PStringBase<char>(&PredictionTimeout, "PredictionTimeout");
  return atexit(_E116_30);
}

//----- (006C53D0) --------------------------------------------------------  // acclient.c:733543
int _E118_4()
{
  PStringBase<char>::PStringBase<char>(&NetSharedVisually, "NetSharedVisually");
  return atexit(_E119_56);
}

//----- (006C53F0) --------------------------------------------------------  // acclient.c:733550
int _E121_4()
{
  PStringBase<char>::PStringBase<char>(&NetSharedPrivately, "NetSharedPrivately");
  return atexit(_E122_43);
}

//----- (006C5410) --------------------------------------------------------  // acclient.c:733557
int _E124_4()
{
  PStringBase<char>::PStringBase<char>(&WorldSharedWithServers, "WorldSharedWithServers");
  return atexit(_E125_19);
}

//----- (006C5430) --------------------------------------------------------  // acclient.c:733564
int _E127_4()
{
  PStringBase<char>::PStringBase<char>(&WorldSharedWithServersAndClients, "WorldSharedWithServersAndClients");
  return atexit(_E128_20);
}

//----- (006C5450) --------------------------------------------------------  // acclient.c:733571
int _E130_4()
{
  PStringBase<char>::PStringBase<char>(&NoCheckpoint, "NoCheckpoint");
  return atexit(_E131_16);
}

//----- (006C5470) --------------------------------------------------------  // acclient.c:733578
int _E133_4()
{
  PStringBase<char>::PStringBase<char>(&NoReplay, "NoReplay");
  return atexit(_E134_15);
}

//----- (006C5490) --------------------------------------------------------  // acclient.c:733585
int _E136_2()
{
  PStringBase<char>::PStringBase<char>(&AbsoluteTimeStamp, "AbsoluteTimeStamp");
  return atexit(_E137_15);
}

//----- (006C54B0) --------------------------------------------------------  // acclient.c:733592
int _E139_2()
{
  PStringBase<char>::PStringBase<char>(&Groupable, "Groupable");
  return atexit(_E140_10);
}

//----- (006C54D0) --------------------------------------------------------  // acclient.c:733599
int _E142_2()
{
  PStringBase<char>::PStringBase<char>(&MinElements, "MinElements");
  return atexit(_E143_12);
}

//----- (006C54F0) --------------------------------------------------------  // acclient.c:733606
int _E145_2()
{
  PStringBase<char>::PStringBase<char>(&MaxElements, "MaxElements");
  return atexit(_E146_11);
}

//----- (006C5510) --------------------------------------------------------  // acclient.c:733613
int _E148_2()
{
  PStringBase<char>::PStringBase<char>(&HelpString, "HelpString");
  return atexit(_E149_11);
}

//----- (006C5530) --------------------------------------------------------  // acclient.c:733620
int _E151_2()
{
  PStringBase<char>::PStringBase<char>(&Global, "Global");
  return atexit(_E152_10);
}

//----- (006C5550) --------------------------------------------------------  // acclient.c:733627
int _E154_3()
{
  PStringBase<char>::PStringBase<char>(&Internal, "Internal");
  return atexit(_E155_8);
}

//----- (006C5570) --------------------------------------------------------  // acclient.c:733634
int _E157_2()
{
  PStringBase<char>::PStringBase<char>(&PropagateToChildren, "PropagateToChildren");
  return atexit(_E158_11);
}

//----- (006C5590) --------------------------------------------------------  // acclient.c:733641
int _E160_3()
{
  PStringBase<char>::PStringBase<char>(&Provider, "Provider");
  return atexit(_E161_8);
}

//----- (006C55B0) --------------------------------------------------------  // acclient.c:733648
int _E163_1()
{
  PStringBase<char>::PStringBase<char>(&ReadOnly, "ReadOnly");
  return atexit(_E164_11);
}

//----- (006C55D0) --------------------------------------------------------  // acclient.c:733655
int _E166_2()
{
  PStringBase<char>::PStringBase<char>(&Recorded, "Recorded");
  return atexit(_E167_7);
}

//----- (006C55F0) --------------------------------------------------------  // acclient.c:733662
int _E169_0()
{
  PStringBase<char>::PStringBase<char>(&ToolOnly, "ToolOnly");
  return atexit(_E170_6);
}

//----- (006C5610) --------------------------------------------------------  // acclient.c:733669
int _E172_0()
{
  return atexit(_E173_5);
}

//----- (006C5620) --------------------------------------------------------  // acclient.c:733675
int _E175_0()
{
  return atexit(_E176_6);
}

//----- (006C5630) --------------------------------------------------------  // acclient.c:733681
int _E178_0()
{
  return atexit(_E179_5);
}

//----- (006C5640) --------------------------------------------------------  // acclient.c:733687
int _E181_0()
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>(
    &stru_81796C,
    0x3E8u);
  return atexit(_E182_5);
}

//----- (006C5660) --------------------------------------------------------  // acclient.c:733696
int _E1_18()
{
  return atexit(_E2_18);
}

//----- (00727AD0) --------------------------------------------------------  // acclient.c:825511
void __cdecl _E74_22()
{
  char *v0; // esi@1

  v0 = &Type.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Type.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727B00) --------------------------------------------------------  // acclient.c:825524
void __cdecl _E77_40()
{
  char *v0; // esi@1

  v0 = &Group.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Group.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727B30) --------------------------------------------------------  // acclient.c:825537
void __cdecl _E80_14()
{
  char *v0; // esi@1

  v0 = &Default.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Default.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727B60) --------------------------------------------------------  // acclient.c:825550
void __cdecl _E83_5()
{
  char *v0; // esi@1

  v0 = &Min.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Min.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727B90) --------------------------------------------------------  // acclient.c:825563
void __cdecl _E86_3()
{
  char *v0; // esi@1

  v0 = &Max.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Max.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727BC0) --------------------------------------------------------  // acclient.c:825576
void __cdecl _E89_14()
{
  char *v0; // esi@1

  v0 = &Available.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Available.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727BF0) --------------------------------------------------------  // acclient.c:825589
void __cdecl _E92_11()
{
  char *v0; // esi@1

  v0 = &AllAvailable.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AllAvailable.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727C20) --------------------------------------------------------  // acclient.c:825602
void __cdecl sub_727C20()
{
  char *v0; // esi@1

  v0 = &Required.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Required.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727C50) --------------------------------------------------------  // acclient.c:825615
void __cdecl _E98_26()
{
  char *v0; // esi@1

  v0 = &ClassOnly.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ClassOnly.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727C80) --------------------------------------------------------  // acclient.c:825628
void __cdecl _E101_56()
{
  char *v0; // esi@1

  v0 = &InstanceOnly.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&InstanceOnly.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727CB0) --------------------------------------------------------  // acclient.c:825641
void __cdecl _E104_26()
{
  char *v0; // esi@1

  v0 = &ClientOnlyData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ClientOnlyData.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727CE0) --------------------------------------------------------  // acclient.c:825654
void __cdecl _E107_58()
{
  char *v0; // esi@1

  v0 = &ServerOnlyData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ServerOnlyData.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727D10) --------------------------------------------------------  // acclient.c:825667
void __cdecl sub_727D10()
{
  char *v0; // esi@1

  v0 = &NetPredictedSharedVisually.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NetPredictedSharedVisually.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727D40) --------------------------------------------------------  // acclient.c:825680
void __cdecl _E113_38()
{
  char *v0; // esi@1

  v0 = &NetPredictedSharedPrivately.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NetPredictedSharedPrivately.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727D70) --------------------------------------------------------  // acclient.c:825693
void __cdecl _E116_30()
{
  char *v0; // esi@1

  v0 = &PredictionTimeout.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PredictionTimeout.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727DA0) --------------------------------------------------------  // acclient.c:825706
void __cdecl _E119_56()
{
  char *v0; // esi@1

  v0 = &NetSharedVisually.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NetSharedVisually.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727DD0) --------------------------------------------------------  // acclient.c:825719
void __cdecl _E122_43()
{
  char *v0; // esi@1

  v0 = &NetSharedPrivately.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NetSharedPrivately.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727E00) --------------------------------------------------------  // acclient.c:825732
void __cdecl _E125_19()
{
  char *v0; // esi@1

  v0 = &WorldSharedWithServers.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldSharedWithServers.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727E30) --------------------------------------------------------  // acclient.c:825745
void __cdecl _E128_20()
{
  char *v0; // esi@1

  v0 = &WorldSharedWithServersAndClients.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldSharedWithServersAndClients.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727E60) --------------------------------------------------------  // acclient.c:825758
void __cdecl _E131_16()
{
  char *v0; // esi@1

  v0 = &NoCheckpoint.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NoCheckpoint.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727E90) --------------------------------------------------------  // acclient.c:825771
void __cdecl _E134_15()
{
  char *v0; // esi@1

  v0 = &NoReplay.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NoReplay.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727EC0) --------------------------------------------------------  // acclient.c:825784
void __cdecl _E137_15()
{
  char *v0; // esi@1

  v0 = &AbsoluteTimeStamp.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AbsoluteTimeStamp.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727EF0) --------------------------------------------------------  // acclient.c:825797
void __cdecl _E140_10()
{
  char *v0; // esi@1

  v0 = &Groupable.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Groupable.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727F20) --------------------------------------------------------  // acclient.c:825810
void __cdecl _E143_12()
{
  char *v0; // esi@1

  v0 = &MinElements.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MinElements.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727F50) --------------------------------------------------------  // acclient.c:825823
void __cdecl _E146_11()
{
  char *v0; // esi@1

  v0 = &MaxElements.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxElements.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727F80) --------------------------------------------------------  // acclient.c:825836
void __cdecl _E149_11()
{
  char *v0; // esi@1

  v0 = &HelpString.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&HelpString.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727FB0) --------------------------------------------------------  // acclient.c:825849
void __cdecl _E152_10()
{
  char *v0; // esi@1

  v0 = &Global.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Global.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727FE0) --------------------------------------------------------  // acclient.c:825862
void __cdecl _E155_8()
{
  char *v0; // esi@1

  v0 = &Internal.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Internal.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728010) --------------------------------------------------------  // acclient.c:825875
void __cdecl _E158_11()
{
  char *v0; // esi@1

  v0 = &PropagateToChildren.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PropagateToChildren.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728040) --------------------------------------------------------  // acclient.c:825888
void __cdecl _E161_8()
{
  char *v0; // esi@1

  v0 = &Provider.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Provider.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728070) --------------------------------------------------------  // acclient.c:825901
void __cdecl _E164_11()
{
  char *v0; // esi@1

  v0 = &ReadOnly.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ReadOnly.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007280A0) --------------------------------------------------------  // acclient.c:825914
void __cdecl _E167_7()
{
  char *v0; // esi@1

  v0 = &Recorded.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Recorded.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007280D0) --------------------------------------------------------  // acclient.c:825927
void __cdecl _E170_6()
{
  char *v0; // esi@1

  v0 = &ToolOnly.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ToolOnly.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728100) --------------------------------------------------------  // acclient.c:825940
void __cdecl _E182_5()
{
  BasePropertyDesc::s_allAvailableProperties.m_reqHash.vfptr = (HashTable<unsigned long,AvailableProperty,0>Vtbl *)HashTable<unsigned long,AvailableProperty,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81796C);
  stru_81796C.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::vftable;
  if ( (HashTableData<unsigned long,AvailableProperty> **)stru_81796C.m_buckets != stru_81796C.m_aInplaceBuckets )
    operator delete[](stru_81796C.m_buckets);
  stru_81796C.m_buckets = 0;
  stru_81796C.m_firstInterestingBucket = 0;
  stru_81796C.m_numBuckets = 0;
  stru_81796C.m_numElements = 0;
}
// 797908: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::vftable[3])(void *, char);
// 79790C: using guessed type int (__thiscall *HashTable<unsigned long,AvailableProperty,0>::vftable[2])(void *, char);

