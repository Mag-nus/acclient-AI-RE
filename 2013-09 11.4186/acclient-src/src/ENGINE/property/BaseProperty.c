/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : BaseProperty
   Object     : ENGINE\property\BaseProperty.obj
   Functions  : 43
   Addresses  : 00429680 - 00727A40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00429680) --------------------------------------------------------  // acclient.c:102000
char __thiscall BasePropertyDesc::InqPatchFlags(BasePropertyDesc *this, unsigned int *o_ePatchFlags)
{
  char result; // al@2

  if ( this->m_propertyType == 10 )
  {
    *o_ePatchFlags = this->m_ePatchFlags;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004296A0) --------------------------------------------------------  // acclient.c:102017
bool __thiscall BaseProperty::InqEnum(BaseProperty *this, unsigned int *_value)
{
  BasePropertyValue *v2; // ecx@1
  bool result; // al@2

  v2 = this->m_pcPropertyValue;
  if ( v2 )
    result = ((int (__stdcall *)(unsigned int *))v2->vfptr[42].__vecDelDtor)(_value);
  else
    result = 0;
  return result;
}

//----- (004296C0) --------------------------------------------------------  // acclient.c:102031
bool __thiscall BaseProperty::IsClientOnlyData(BaseProperty *this)
{
  bool result; // al@2

  if ( this->m_pcPropertyDesc )
    result = this->m_pcPropertyDesc->m_datFileType == 0;
  else
    result = 0;
  return result;
}

//----- (004296E0) --------------------------------------------------------  // acclient.c:102043
bool __thiscall BaseProperty::IsServerOnlyData(BaseProperty *this)
{
  bool result; // al@2

  if ( this->m_pcPropertyDesc )
    result = this->m_pcPropertyDesc->m_datFileType == 1;
  else
    result = 0;
  return result;
}

//----- (00429700) --------------------------------------------------------  // acclient.c:102055
bool __thiscall BaseProperty::IsToolOnly(BaseProperty *this)
{
  bool result; // al@2

  if ( this->m_pcPropertyDesc )
    result = this->m_pcPropertyDesc->m_bToolOnly;
  else
    result = 0;
  return result;
}

//----- (00429710) --------------------------------------------------------  // acclient.c:102067
bool __thiscall BaseProperty::Compare(BaseProperty *this, BaseProperty *_p)
{
  BasePropertyDesc *v2; // esi@1
  BasePropertyValue *v3; // ecx@2
  bool result; // al@6

  v2 = this->m_pcPropertyDesc;
  if ( this->m_pcPropertyDesc && (v3 = this->m_pcPropertyValue) != 0 && _p->m_pcPropertyDesc )
    result = v2->m_propertyName == _p->m_pcPropertyDesc->m_propertyName
          && (unsigned __int8)((int (__stdcall *)(BasePropertyValue *))v3->vfptr[2].__vecDelDtor)(_p->m_pcPropertyValue);
  else
    result = 0;
  return result;
}

//----- (00429760) --------------------------------------------------------  // acclient.c:102083
BasePropertyDesc *__thiscall BaseProperty::GetPropertyName(BaseProperty *this)
{
  BasePropertyDesc *result; // eax@1

  result = this->m_pcPropertyDesc;
  if ( this->m_pcPropertyDesc )
    result = (BasePropertyDesc *)result->m_propertyName;
  return result;
}

//----- (00429770) --------------------------------------------------------  // acclient.c:102094
unsigned int __thiscall BaseProperty::GetGroupName(BaseProperty *this)
{
  unsigned int result; // eax@2

  if ( this->m_pcPropertyDesc )
    result = this->m_pcPropertyDesc->m_propertyGroup;
  else
    result = 0;
  return result;
}

//----- (00429780) --------------------------------------------------------  // acclient.c:102106
char __thiscall BaseProperty::InqPropertyName(BaseProperty *this, PStringBase<char> *_name_str)
{
  BasePropertyDesc *v2; // eax@1
  char result; // al@2

  v2 = this->m_pcPropertyDesc;
  if ( this->m_pcPropertyDesc )
    result = MasterProperty::InqPropertyNameStringStatic(v2->m_propertyName, _name_str);
  else
    result = MasterProperty::InqPropertyNameStringStatic(0, _name_str);
  return result;
}

//----- (004297B0) --------------------------------------------------------  // acclient.c:102120
__int32 __thiscall PStringBase<char>::to_int32(PStringBase<char> *this)
{
  PSRefBufferCharData<char> *v1; // esi@1

  v1 = this->m_charbuffer;
  *__errno() = 0;
  return _strtol(v1->m_data, 0, 0);
}

//----- (004297D0) --------------------------------------------------------  // acclient.c:102130
char __thiscall BasePropertyDesc::InqDataID(BasePropertyDesc *this, IDClass<_tagDataID,32,0> *_did)
{
  char result; // al@2

  switch ( this->m_propertyType )
  {
    case 9u:
    case 0xFu:
    case 0x10u:
    case 0x14u:
      _did->id = this->m_data;
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (00429810) --------------------------------------------------------  // acclient.c:102151
void *__thiscall BaseProperty::operator=(void *this, int a2)
{
  void *v2; // esi@1
  int v3; // ecx@2
  bool v4; // zf@3
  int v5; // eax@6
  int v6; // ecx@8
  int v7; // eax@12

  v2 = this;
  if ( this != (void *)a2 )
  {
    v3 = *(_DWORD *)this;
    if ( *(_DWORD *)v2 )
    {
      v4 = (*(_DWORD *)(v3 + 4))-- == 1;
      if ( v4 )
        (**(void (__stdcall ***)(_DWORD))v3)(1);
      *(_DWORD *)v2 = 0;
    }
    v5 = *(_DWORD *)a2;
    if ( *(_DWORD *)a2 )
    {
      *(_DWORD *)v2 = v5;
      ++*(_DWORD *)(v5 + 4);
    }
    v6 = *((_DWORD *)v2 + 1);
    if ( v6 )
    {
      v4 = (*(_DWORD *)(v6 + 4))-- == 1;
      if ( v4 )
        (**(void (__stdcall ***)(_DWORD))v6)(1);
      *((_DWORD *)v2 + 1) = 0;
    }
    v7 = *(_DWORD *)(a2 + 4);
    if ( v7 )
    {
      *((_DWORD *)v2 + 1) = v7;
      ++*(_DWORD *)(v7 + 4);
    }
  }
  return v2;
}

//----- (00429870) --------------------------------------------------------  // acclient.c:102196
void __thiscall BaseProperty::CheckCopyOnWrite(BaseProperty *this)
{
  BaseProperty *v1; // esi@1
  BasePropertyValue *v2; // ecx@1
  unsigned int v3; // eax@2
  int v4; // eax@3

  v1 = this;
  v2 = this->m_pcPropertyValue;
  if ( v2 )
  {
    v3 = v2->m_cRef;
    if ( v3 != 1 )
    {
      v4 = v3 - 1;
      v2->m_cRef = v4;
      if ( !v4 )
        ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
      v1->m_pcPropertyValue = (BasePropertyValue *)((int (*)(void))v1->m_pcPropertyValue->vfptr[1].__vecDelDtor)();
    }
  }
}

//----- (004298A0) --------------------------------------------------------  // acclient.c:102220
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *,0> *v2; // esi@1
  HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::vftable;
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
// 797888: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::vftable)(void *, char);

//----- (004298E0) --------------------------------------------------------  // acclient.c:102241
bool __thiscall BaseProperty::SetFloat(BaseProperty *this, const float _value)
{
  BaseProperty *v2; // esi@1
  BasePropertyValue *v3; // ecx@1
  unsigned int v4; // eax@2
  int v5; // eax@3
  bool result; // al@6

  v2 = this;
  v3 = this->m_pcPropertyValue;
  if ( v3 )
  {
    v4 = v3->m_cRef;
    if ( v4 != 1 )
    {
      v5 = v4 - 1;
      v3->m_cRef = v5;
      if ( !v5 )
        ((void (__stdcall *)(signed int))v3->vfptr->__vecDelDtor)(1);
      v2->m_pcPropertyValue = (BasePropertyValue *)((int (*)(void))v2->m_pcPropertyValue->vfptr[1].__vecDelDtor)();
    }
    result = ((int (__stdcall *)(_DWORD))v2->m_pcPropertyValue->vfptr[35].__vecDelDtor)(LODWORD(_value));
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00429920) --------------------------------------------------------  // acclient.c:102272
bool __thiscall BaseProperty::SetEnum(BaseProperty *this, const unsigned int _value)
{
  BaseProperty *v2; // esi@1
  BasePropertyValue *v3; // ecx@1
  unsigned int v4; // eax@2
  int v5; // eax@3
  bool result; // al@6

  v2 = this;
  v3 = this->m_pcPropertyValue;
  if ( v3 )
  {
    v4 = v3->m_cRef;
    if ( v4 != 1 )
    {
      v5 = v4 - 1;
      v3->m_cRef = v5;
      if ( !v5 )
        ((void (__stdcall *)(signed int))v3->vfptr->__vecDelDtor)(1);
      v2->m_pcPropertyValue = (BasePropertyValue *)((int (*)(void))v2->m_pcPropertyValue->vfptr[1].__vecDelDtor)();
    }
    result = ((int (__stdcall *)(const unsigned int))v2->m_pcPropertyValue->vfptr[43].__vecDelDtor)(_value);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00429960) --------------------------------------------------------  // acclient.c:102303
bool __thiscall BaseProperty::SetStringInfo(BaseProperty *this, StringInfo *_value)
{
  BaseProperty *v2; // esi@1
  BasePropertyValue *v3; // ecx@1
  unsigned int v4; // eax@2
  int v5; // eax@3
  bool result; // al@6

  v2 = this;
  v3 = this->m_pcPropertyValue;
  if ( v3 )
  {
    v4 = v3->m_cRef;
    if ( v4 != 1 )
    {
      v5 = v4 - 1;
      v3->m_cRef = v5;
      if ( !v5 )
        ((void (__stdcall *)(signed int))v3->vfptr->__vecDelDtor)(1);
      v2->m_pcPropertyValue = (BasePropertyValue *)((int (*)(void))v2->m_pcPropertyValue->vfptr[1].__vecDelDtor)();
    }
    result = ((int (__stdcall *)(StringInfo *))v2->m_pcPropertyValue->vfptr[49].__vecDelDtor)(_value);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004299A0) --------------------------------------------------------  // acclient.c:102334
void __thiscall FileNodeName_PString::FileNodeName_PString(FileNodeName_PString *this)
{
  volatile LONG *v1; // ST00_4@1

  this->vfptr = (IFileNodeNameVtbl *)&FileNodeName_PString::vftable;
  v1 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v1);
}
// 797140: using guessed type int (__thiscall *FileNodeName_PString::vftable)(void *, char);

//----- (00429A40) --------------------------------------------------------  // acclient.c:102391
void __thiscall BaseProperty::GetSubDataIDs(BaseProperty *this, QualifiedDataIDArray *_id_array)
{
  BaseProperty *v2; // esi@1
  unsigned int v3; // ebp@1
  QualifiedDataID *v4; // eax@2
  unsigned int v5; // eax@4
  BasePropertyValue *v6; // ecx@7
  BasePropertyDesc *v7; // ecx@9
  bool v8; // zf@9
  BasePropertyValue *v9; // ecx@12
  BasePropertyValue *v10; // ecx@16
  int v11; // eax@17
  BaseProperty *v12; // esi@18
  int v13; // edi@18
  BasePropertyValue *v14; // ecx@23
  HashTable<unsigned long,StringInfoData *,0> *v15; // eax@24
  HashTableData<unsigned long,BaseProperty> *i; // eax@25
  unsigned int ePatchFlags; // [sp+Ch] [bp-A0h]@1
  HashIterator<unsigned long,BaseProperty,1> cur; // [sp+10h] [bp-9Ch]@2
  StringInfo v19; // [sp+1Ch] [bp-90h]@12

  v2 = this;
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&ePatchFlags);
  v3 = ePatchFlags;
  if ( ePatchFlags )
  {
    QualifiedDataID::QualifiedDataID((QualifiedDataID *)&cur, *(IDClass<_tagDataID,32,0> *)(ePatchFlags + 40), 0);
    QualifiedDataIDArray::AddQDID(_id_array, v4, 0);
  }
  if ( v2->m_pcPropertyDesc )
    v5 = v2->m_pcPropertyDesc->m_propertyType;
  else
    v5 = 0;
  switch ( v5 )
  {
    case 0xAu:
      v6 = v2->m_pcPropertyValue;
      if ( v6
        && (unsigned __int8)((int (__stdcall *)(HashIterator<unsigned long,BaseProperty,1> *))v6->vfptr[44].__vecDelDtor)(&cur) )
      {
        v7 = v2->m_pcPropertyDesc;
        v8 = v2->m_pcPropertyDesc == 0;
        ePatchFlags = 0;
        if ( !v8 )
          BasePropertyDesc::InqPatchFlags(v7, &ePatchFlags);
        QualifiedDataIDArray::AddDID(_id_array, (IDClass<_tagDataID,32,0>)cur.m_iter.m_currHashTable, ePatchFlags);
      }
      goto LABEL_20;
    case 8u:
      StringInfo::StringInfo(&v19);
      v9 = v2->m_pcPropertyValue;
      if ( v9 && (unsigned __int8)((int (__stdcall *)(StringInfo *))v9->vfptr[48].__vecDelDtor)(&v19) )
        StringInfo::GetSubDataIDs(&v19, _id_array);
      StringInfo::~StringInfo(&v19);
      goto LABEL_20;
    case 0x11u:
      v10 = v2->m_pcPropertyValue;
      if ( !v10 )
        goto LABEL_29;
      v11 = ((int (*)(void))v10->vfptr[66].__vecDelDtor)();
      if ( !v11 )
        goto LABEL_28;
      v12 = *(BaseProperty **)v11;
      v13 = *(_DWORD *)v11 + 8 * *(_DWORD *)(v11 + 8);
      if ( *(_DWORD *)v11 != v13 )
      {
        do
        {
          BaseProperty::GetSubDataIDs(v12, _id_array);
          ++v12;
        }
        while ( v12 != (BaseProperty *)v13 );
      }
      goto LABEL_20;
    default:
      goto LABEL_20;
    case 0x12u:
      v14 = v2->m_pcPropertyValue;
      if ( v14 )
      {
        v15 = (HashTable<unsigned long,StringInfoData *,0> *)((int (*)(void))v14->vfptr[74].__vecDelDtor)();
        if ( v15 )
        {
          HashTable<unsigned long,BaseProperty,1>::begin(v15, (HashIterator<unsigned long,StringInfoData *,0> *)&cur);
          for ( i = cur.m_iter.m_currElement; cur.m_iter.m_currElement; i = cur.m_iter.m_currElement )
          {
            BaseProperty::GetSubDataIDs(&i->m_data, _id_array);
            HashSetIterator<UIListener *>::operator++((HashIterator<unsigned long,unsigned long,0> *)&cur);
          }
LABEL_20:
          if ( v3 )
            (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v3 + 20))(v3);
        }
        else
        {
LABEL_28:
          DBObjGrabber<StringTable>::~DBObjGrabber<StringTable>((DBObjGrabber<ACCharGenData> *)&ePatchFlags);
        }
      }
      else
      {
LABEL_29:
        if ( v3 )
          (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v3 + 20))(v3);
      }
      return;
  }
}

//----- (00429C00) --------------------------------------------------------  // acclient.c:102501
char __thiscall BaseProperty::ToFileNode(BaseProperty *this, PFileNode *_node)
{
  PFileNode *v2; // ebx@1
  BaseProperty *v3; // esi@1
  unsigned int v4; // eax@4
  PStringBase<char> v5; // ST04_4@7
  PFileNode *v6; // eax@7
  char v7; // al@8
  PFileNode **v8; // ecx@8

  v2 = _node;
  v3 = this;
  if ( _node && this->m_pcPropertyDesc && this->m_pcPropertyValue )
  {
    _node = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v4 = (unsigned int)v3->m_pcPropertyDesc;
    if ( v3->m_pcPropertyDesc )
      v4 = *(_DWORD *)(v4 + 8);
    if ( MasterProperty::InqPropertyNameStringStatic(v4, (PStringBase<char> *)&_node)
      && (v5.m_charbuffer = (PSRefBufferCharData<char> *)_node,
          InterlockedIncrement((volatile LONG *)&_node[-1].m_bProcessed),
          (v6 = PFileNode::MakeSubNode(v2, v5)) != 0) )
    {
      v7 = ((int (__stdcall *)(unsigned int, PFileNode *))v3->m_pcPropertyValue->vfptr[25].__vecDelDtor)(
             v3->m_pcPropertyDesc,
             v6);
      v8 = &_node;
      if ( v7 )
      {
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_node);
        return 1;
      }
    }
    else
    {
      v8 = &_node;
    }
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)v8);
  }
  return 0;
}

//----- (00429CA0) --------------------------------------------------------  // acclient.c:102545
char __thiscall BaseProperty::ValueFromFileNode(BaseProperty *this, PFileNode *_node)
{
  BaseProperty *v2; // esi@1
  PSRefBufferCharData<char> *v3; // ecx@5
  PStringBase<char> v5; // [sp-4h] [bp-Ch]@6

  v2 = this;
  if ( !this->m_pcPropertyDesc || !this->m_pcPropertyValue )
    return 0;
  if ( this->m_pcPropertyDesc->m_propertyName )
    BaseProperty::CheckCopyOnWrite(this);
  if ( !(unsigned __int8)((int (__stdcall *)(_DWORD, PFileNode *))v2->m_pcPropertyValue->vfptr[24].__vecDelDtor)(
                           v2->m_pcPropertyDesc,
                           _node) )
  {
    v5.m_charbuffer = v3;
    PStringBase<char>::PStringBase<char>(&v5, "unable to read property value");
    PFileNode::ReportError((int)_node, _node, v5);
    return 0;
  }
  return 1;
}

//----- (00429D00) --------------------------------------------------------  // acclient.c:102569
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 797888: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::vftable)(void *, char);

//----- (00429D90) --------------------------------------------------------  // acclient.c:102602
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *,0> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > **v5; // edx@5
  HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *v6; // edi@5
  HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *v7; // eax@7
  HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *v8; // ecx@8
  BasePropertyValue *v9; // ecx@13
  bool v10; // zf@14

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > **)v4;
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
      v9 = v6->m_data.m_data;
      if ( v9 )
      {
        v10 = v9->m_cRef-- == 1;
        if ( v10 )
          ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
      }
      operator delete(v6);
    }
  }
}

//----- (00429E20) --------------------------------------------------------  // acclient.c:102670
char __thiscall HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0>::add(HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0> *this, const unsigned int *_key, IntrusiveSmartPointer<BasePropertyValue> *_data)
{
  HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0> *v3; // edi@1
  void *v4; // eax@1
  BasePropertyValue *v5; // ecx@2
  void *v6; // esi@4
  int v7; // ecx@8
  bool v8; // zf@9
  char result; // al@12

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    *((_DWORD *)v4 + 1) = 0;
    v5 = _data->m_data;
    *((_DWORD *)v4 + 2) = _data->m_data;
    if ( v5 )
      ++v5->m_cRef;
    v6 = v4;
  }
  else
  {
    v6 = 0;
  }
  if ( IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v3->m_intrusiveTable,
         (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v6) )
  {
    result = 1;
  }
  else
  {
    if ( v6 )
    {
      v7 = *((_DWORD *)v6 + 2);
      if ( v7 )
      {
        v8 = (*(_DWORD *)(v7 + 4))-- == 1;
        if ( v8 )
          (**(void (__stdcall ***)(_DWORD))v7)(1);
      }
      operator delete(v6);
    }
    result = 0;
  }
  return result;
}

//----- (00429EA0) --------------------------------------------------------  // acclient.c:102721
BasePropertyValue *__cdecl GetInitialPropertyValue(unsigned int i_eType)
{
  BasePropertyValue *v1; // ecx@0
  HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *v2; // edx@1
  int v3; // eax@4
  int v4; // esi@4
  int v5; // eax@5
  bool v6; // zf@5
  BasePropertyValue *result; // eax@7
  IntrusiveSmartPointer<BasePropertyValue> _data; // [sp+0h] [bp-4h]@1

  _data.m_data = v1;
  v2 = stru_8178E4.m_buckets[i_eType % stru_8178E4.m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey != i_eType )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 && v2 != (HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *)-8 )
  {
    result = v2->m_data.m_data;
    ++result->m_cRef;
  }
  else
  {
LABEL_4:
    MasterProperty::AllocatePropertyValue(i_eType);
    v4 = v3;
    if ( v3 )
    {
      v5 = *(_DWORD *)(v3 + 4) + 1;
      _data.m_data = (BasePropertyValue *)v4;
      *(_DWORD *)(v4 + 4) = v5;
      HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0>::add(
        &s_AllocatedDefaultPropertyValues,
        &i_eType,
        &_data);
      v6 = (*(_DWORD *)(v4 + 4))-- == 1;
      if ( v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    result = (BasePropertyValue *)v4;
  }
  return result;
}

//----- (00429F20) --------------------------------------------------------  // acclient.c:102771
char __thiscall BaseProperty::InitToDefaultValue(BaseProperty *this)
{
  BaseProperty *v1; // esi@1
  BasePropertyValue *v2; // ecx@2
  bool v3; // zf@3
  BasePropertyDesc *v4; // ecx@6
  BasePropertyValue *v5; // eax@6
  char result; // al@7
  unsigned int v7; // ecx@9
  BasePropertyValue *v8; // eax@11

  v1 = this;
  if ( !this->m_pcPropertyDesc )
    goto LABEL_16;
  v2 = this->m_pcPropertyValue;
  if ( v2 )
  {
    v3 = v2->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->m_pcPropertyValue = 0;
  }
  v4 = v1->m_pcPropertyDesc;
  v5 = v1->m_pcPropertyDesc->m_defaultValue;
  if ( v5 )
  {
    v1->m_pcPropertyValue = v5;
    ++v5->m_cRef;
    return 1;
  }
  v7 = v4 ? v4->m_propertyType : 0;
  v8 = GetInitialPropertyValue(v7);
  v1->m_pcPropertyValue = v8;
  if ( v8 )
    result = 0;
  else
LABEL_16:
    result = 0;
  return result;
}

//----- (00429F80) --------------------------------------------------------  // acclient.c:102813
HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0> *__thiscall HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0>::scalar_deleting_destructor(HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0> *this, unsigned int a2)
{
  HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0>Vtbl *)&HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::vftable;
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
// 797888: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::vftable)(void *, char);
// 7978B4: using guessed type int (__thiscall *HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0>::vftable)(void *, char);

//----- (00429FE0) --------------------------------------------------------  // acclient.c:102839
char __thiscall BaseProperty::SetPropertyDesc(BaseProperty *this, BasePropertyDesc *i_pcDesc)
{
  BaseProperty *v2; // esi@1
  BasePropertyDesc *v3; // ecx@1
  bool v4; // zf@2
  BasePropertyValue *v5; // ecx@5

  v2 = this;
  v3 = this->m_pcPropertyDesc;
  if ( v3 )
  {
    v4 = v3->m_cRef-- == 1;
    if ( v4 )
      ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v2->m_pcPropertyDesc = 0;
  }
  v5 = v2->m_pcPropertyValue;
  if ( v5 )
  {
    v4 = v5->m_cRef-- == 1;
    if ( v4 )
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    v2->m_pcPropertyValue = 0;
  }
  if ( i_pcDesc )
  {
    v2->m_pcPropertyDesc = i_pcDesc;
    ++i_pcDesc->m_cRef;
    BaseProperty::InitToDefaultValue(v2);
  }
  return 1;
}

//----- (0042A030) --------------------------------------------------------  // acclient.c:102873
char __thiscall BaseProperty::SetPropertyName(BaseProperty *this, const unsigned int i_eName)
{
  unsigned int v2; // ebx@1
  BasePropertyDesc *v3; // esi@1
  BaseProperty *v4; // ebp@1
  const unsigned int v5; // edi@2

  v2 = i_eName;
  v3 = 0;
  v4 = this;
  if ( !i_eName )
    return BaseProperty::SetPropertyDesc(v4, v3);
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&i_eName);
  v5 = i_eName;
  if ( i_eName )
  {
    v3 = MasterProperty::AccessPropertyDesc((MasterProperty *)i_eName, v2);
    if ( v3 )
    {
      (*(void (__thiscall **)(const unsigned int))(*(_DWORD *)v5 + 20))(v5);
      return BaseProperty::SetPropertyDesc(v4, v3);
    }
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v5 + 20))(v5);
  }
  return 0;
}

//----- (0042A090) --------------------------------------------------------  // acclient.c:102901
void __thiscall BaseProperty::Serialize(BaseProperty *this, Archive *io_archive)
{
  BaseProperty *v2; // edi@1
  unsigned int v3; // ebp@3
  unsigned int v4; // eax@5
  unsigned int v5; // eax@9
  Archive *v6; // ecx@11
  BasePropertyValue *v7; // ecx@18
  unsigned int v8; // eax@19
  int v9; // eax@20
  unsigned int v10; // eax@24
  BasePropertyValue *v11; // ecx@25

  v2 = this;
  if ( io_archive->m_flags & 1 )
  {
    v3 = this->m_pcPropertyDesc ? this->m_pcPropertyDesc->m_propertyName : 0;
    Archive::CheckAlignment(io_archive, 4u);
    v4 = Archive::GetBytes(io_archive, 4u);
    if ( v4 )
    {
      if ( io_archive->m_flags & 1 )
        *(_DWORD *)v4 = v3;
    }
  }
  if ( !(~LOBYTE(io_archive->m_flags) & 1) )
    goto LABEL_23;
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
    {
      v6 = io_archive;
      *(_DWORD *)v5 = io_archive;
    }
    else
    {
      v6 = *(Archive **)v5;
    }
  }
  else
  {
    v6 = io_archive;
  }
  if ( !BaseProperty::SetPropertyName(v2, (const unsigned int)v6) )
    Archive::RaiseError(io_archive);
  if ( v2->m_pcPropertyDesc )
  {
    if ( v2->m_pcPropertyDesc->m_propertyName )
    {
      v7 = v2->m_pcPropertyValue;
      if ( v7 )
      {
        v8 = v7->m_cRef;
        if ( v8 != 1 )
        {
          v9 = v8 - 1;
          v7->m_cRef = v9;
          if ( !v9 )
            ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
          v2->m_pcPropertyValue = (BasePropertyValue *)((int (*)(void))v2->m_pcPropertyValue->vfptr[1].__vecDelDtor)();
        }
      }
    }
LABEL_23:
    if ( v2->m_pcPropertyDesc )
    {
      v10 = v2->m_pcPropertyDesc->m_propertyName;
      if ( v10 )
      {
        v11 = v2->m_pcPropertyValue;
        if ( v11 )
          ((void (__stdcall *)(Archive *, unsigned int))v11->vfptr[23].__vecDelDtor)(io_archive, v10);
        else
          Archive::RaiseError(io_archive);
      }
    }
  }
}

//----- (0042A180) --------------------------------------------------------  // acclient.c:102983
char __thiscall BaseProperty::FromFileNode(BaseProperty *this, PFileNode *_node)
{
  PFileNode *v2; // esi@1
  BaseProperty *v3; // edi@1
  PSRefBufferCharData<char> *v4; // ecx@2
  PSRefBufferCharData<char> *v5; // ecx@4
  char *v6; // esi@6
  int v7; // edx@8
  char result; // al@9
  PStringBase<char> v9; // [sp-10h] [bp-14h]@3
  PStringBase<char> v10; // [sp-Ch] [bp-10h]@3
  unsigned int name_enum; // [sp+0h] [bp-4h]@1

  name_enum = (unsigned int)this;
  v2 = _node;
  v3 = this;
  if ( !_node )
    return 0;
  _node = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PFileNode::GetNameAsPString(v2, (int)v3, (PStringBase<char> *)&_node);
  if ( !MasterProperty::InqPropertyNameEnumStatic((PStringBase<char> *)&_node, &name_enum) )
  {
    v10.m_charbuffer = (PSRefBufferCharData<char> *)_node;
    v9.m_charbuffer = v4;
    PStringBase<char>::PStringBase<char>(&v9, "invalid property name '%s'");
    PFileNode::ReportError((int)v3, v2, v9);
    goto LABEL_6;
  }
  if ( !BaseProperty::SetPropertyName(v3, name_enum) )
  {
    v10.m_charbuffer = v5;
    PStringBase<char>::PStringBase<char>(&v10, "unable to initialize property");
    PFileNode::ReportError((int)v3, v2, v10);
LABEL_6:
    v6 = (char *)&_node[-1].sub_nodes.m_num;
    if ( !InterlockedDecrement((volatile LONG *)&_node[-1].m_bProcessed) )
    {
      if ( v6 )
      {
        v7 = *(_DWORD *)v6;
        v10.m_charbuffer = (PSRefBufferCharData<char> *)1;
        (*(void (__thiscall **)(char *, signed int))v7)(v6, 1);
      }
    }
    return 0;
  }
  if ( BaseProperty::ValueFromFileNode(v3, v2) )
  {
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_node);
    result = 1;
  }
  else
  {
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_node);
    result = 0;
  }
  return result;
}

//----- (006C5100) --------------------------------------------------------  // acclient.c:733384
void _E91_2()
{
  outside_val_3 = 1000.0 + 1.0;
}

//----- (006C5120) --------------------------------------------------------  // acclient.c:733390
void _E93_0()
{
  block_length_3 = 24.0 * 8.0;
}

//----- (006C5140) --------------------------------------------------------  // acclient.c:733396
void _E95_0()
{
  half_square_length_3 = 24.0 * 0.5;
}

//----- (006C5160) --------------------------------------------------------  // acclient.c:733402
int _E97_2()
{
  PStringBase<char>::PStringBase<char>(&KW_TRUE_0, "True");
  return atexit(_E98_25);
}

//----- (006C5180) --------------------------------------------------------  // acclient.c:733409
int _E100_5()
{
  PStringBase<char>::PStringBase<char>(&KW_FALSE_0, "False");
  return atexit(_E101_55);
}

//----- (006C51A0) --------------------------------------------------------  // acclient.c:733416
int _E103_2()
{
  PStringBase<char>::PStringBase<char>(&KW_UNDEF_0, "Undef");
  return atexit(_E104_25);
}

//----- (006C51C0) --------------------------------------------------------  // acclient.c:733423
int _E106_4()
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>(
    &stru_8178E4,
    0x2Fu);
  return atexit(_E107_57);
}

//----- (006C51E0) --------------------------------------------------------  // acclient.c:733432
int _E1_17()
{
  return atexit(_E2_17);
}

//----- (007279B0) --------------------------------------------------------  // acclient.c:825456
void __cdecl _E98_25()
{
  char *v0; // esi@1

  v0 = &KW_TRUE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TRUE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007279E0) --------------------------------------------------------  // acclient.c:825469
void __cdecl _E101_55()
{
  char *v0; // esi@1

  v0 = &KW_FALSE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FALSE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727A10) --------------------------------------------------------  // acclient.c:825482
void __cdecl _E104_25()
{
  char *v0; // esi@1

  v0 = &KW_UNDEF_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_UNDEF_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727A40) --------------------------------------------------------  // acclient.c:825495
void __cdecl _E107_57()
{
  s_AllocatedDefaultPropertyValues.vfptr = (HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0>Vtbl *)&HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::delete_contents(&stru_8178E4);
  stru_8178E4.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::vftable;
  if ( (HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > **)stru_8178E4.m_buckets != stru_8178E4.m_aInplaceBuckets )
    operator delete[](stru_8178E4.m_buckets);
  stru_8178E4.m_buckets = 0;
  stru_8178E4.m_firstInterestingBucket = 0;
  stru_8178E4.m_numBuckets = 0;
  stru_8178E4.m_numElements = 0;
}
// 797888: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::vftable)(void *, char);
// 7978B4: using guessed type int (__thiscall *HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0>::vftable)(void *, char);

