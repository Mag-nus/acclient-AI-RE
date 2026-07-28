/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SpellComponentTable
   Object     : AC\acmagic\SpellComponentTable.obj
   Functions  : 29
   Addresses  : 004E5E90 - 0070EB40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E5E90) --------------------------------------------------------  // acclient.c:275835
signed int gmUIElement_VitaeIndicator::GetUIElementType()
{
  return 268435462;
}

//----- (005BBF50) --------------------------------------------------------  // acclient.c:487058
signed int __cdecl SpellComponentTable::GetTargetTypeFromComponentID(const unsigned int scid)
{
  signed int result; // eax@2

  switch ( scid )
  {
    case 0x31u:
    case 0x32u:
    case 0x33u:
    case 0x34u:
    case 0x35u:
    case 0x36u:
    case 0x37u:
    case 0x38u:
    case 0x3Cu:
    case 0x3Du:
    case 0x3Eu:
    case 0xBEu:
      result = 16;
      break;
    case 0x39u:
      result = 560015;
      break;
    case 0x3Bu:
      result = 268500992;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005BC030) --------------------------------------------------------  // acclient.c:487092
PackableHashIterator<unsigned long,SpellComponentBase> *__thiscall PackableHashIterator<unsigned long,SpellComponentBase>::scalar_deleting_destructor(PackableHashIterator<unsigned long,SpellComponentBase> *this, unsigned int a2)
{
  PackableHashIterator<unsigned long,SpellComponentBase> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackableHashIterator<unsigned long,SpellComponentBase>Vtbl *)PackableHashIterator<unsigned long,SpellComponentBase>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7E74C0: using guessed type int (__thiscall *PackableHashIterator<unsigned long,SpellComponentBase>::vftable[2])(void *, char);

//----- (005BC0A0) --------------------------------------------------------  // acclient.c:487134
PackableHashIterator<unsigned long,SpellComponentBase> *__thiscall PackableHashTable<unsigned long,SpellComponentBase>::begin(PackableHashTable<unsigned long,SpellComponentBase> *this, PackableHashIterator<unsigned long,SpellComponentBase> *result)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  PackableHashData<unsigned long,SpellComponentBase> **v4; // edi@2
  PackableHashData<unsigned long,SpellComponentBase> **v5; // esi@2
  PackableHashData<unsigned long,SpellComponentBase> **v6; // ecx@5
  PackableHashIterator<unsigned long,SpellComponentBase> *v7; // eax@5
  PackableHashData<unsigned long,SpellComponentBase> *v8; // ecx@6

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
    result->vfptr = (PackableHashIterator<unsigned long,SpellComponentBase>Vtbl *)PackableHashIterator<unsigned long,SpellComponentBase>::vftable;
    result->_table_size = v2;
  }
  else
  {
LABEL_5:
    v6 = this->_buckets;
    v7 = result;
    result->_current = 0;
    result->_buckets = v6;
    result->vfptr = (PackableHashIterator<unsigned long,SpellComponentBase>Vtbl *)PackableHashIterator<unsigned long,SpellComponentBase>::vftable;
    result->_table_size = v2;
  }
  return v7;
}
// 7E74C0: using guessed type int (__thiscall *PackableHashIterator<unsigned long,SpellComponentBase>::vftable[2])(void *, char);

//----- (005BC100) --------------------------------------------------------  // acclient.c:487179
signed int __thiscall PackableHashTable<unsigned long,SpellComponentBase>::Pack(PackableHashTable<unsigned long,SpellComponentBase> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,SpellComponentBase> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<unsigned long,SpellComponentBase> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<unsigned long,SpellComponentBase>::pack_size(this);
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

//----- (005BC190) --------------------------------------------------------  // acclient.c:487230
signed int __thiscall PackableHashTable<unsigned long,SpellComponentBase>::pack_size(PackableHashTable<unsigned long,SpellComponentBase> *this)
{
  PackableHashTable<unsigned long,SpellComponentBase> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<unsigned long,SpellComponentBase> *i; // esi@2
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

//----- (005BC1F0) --------------------------------------------------------  // acclient.c:487262
IDClass<_tagDataID,32,0> *__cdecl SpellComponentTable::SchoolOfMagic2WCID(IDClass<_tagDataID,32,0> *result, unsigned int scid)
{
  int v2; // esi@1
  IDClass<_tagDataID,32,0> did; // [sp+0h] [bp-4h]@1

  v2 = DBObj::GetByEnum(4, 268435457, 0x28u);
  did.id = stru_8EF5C0.id;
  if ( v2 )
    EnumIDMap::EnumToDID((EnumIDMap *)v2, scid, &did);
  result->id = did.id;
  if ( v2 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 20))(v2);
  return result;
}

//----- (005BC240) --------------------------------------------------------  // acclient.c:487278
unsigned int __cdecl SpellComponentTable::WCIDtoSCID(IDClass<_tagDataID,32,0> wcid)
{
  int v1; // esi@1
  unsigned int v2; // edi@1
  unsigned int retval; // [sp+0h] [bp-4h]@1

  v1 = DBObj::GetByEnum(3, 268435457, 0x28u);
  retval = 0;
  DualEnumIDMap::DIDToEnum((DualEnumIDMap *)v1, wcid, &retval);
  v2 = retval;
  if ( v1 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v1 + 20))(v1);
  return v2;
}

//----- (005BC290) --------------------------------------------------------  // acclient.c:487294
void __thiscall SpellComponentBase::SpellComponentBase(SpellComponentBase *this, SpellComponentBase *__that)
{
  SpellComponentBase *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // eax@1
  AC1Legacy::PSRefBuffer<char> *v4; // eax@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&SpellComponentBase::vftable;
  v3 = __that->_name.m_buffer;
  this->_name.m_buffer = v3;
  InterlockedIncrement((volatile LONG *)&v3->m_cRef);
  v2->_category = __that->_category;
  v2->_iconID.id = __that->_iconID.id;
  v2->_type = __that->_type;
  v2->_gesture = __that->_gesture;
  v2->_time = __that->_time;
  v4 = __that->_text.m_buffer;
  v2->_text.m_buffer = v4;
  InterlockedIncrement((volatile LONG *)&v4->m_cRef);
  v2->_CDM = __that->_CDM;
}
// 7A33CC: using guessed type int (__thiscall *SpellComponentBase::vftable)(void *, char);

//----- (005BC2F0) --------------------------------------------------------  // acclient.c:487318
IDClass<_tagDataID,32,0> *__cdecl SpellComponentTable::SCIDtoWCID(IDClass<_tagDataID,32,0> *result, const unsigned int scid)
{
  int v2; // esi@1
  IDClass<_tagDataID,32,0> did; // [sp+0h] [bp-4h]@1

  v2 = DBObj::GetByEnum(3, 268435457, 0x28u);
  did.id = stru_8EF5C0.id;
  EnumIDMap::EnumToDID((EnumIDMap *)v2, scid, &did);
  result->id = did.id;
  if ( v2 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 20))(v2);
  return result;
}

//----- (005BC340) --------------------------------------------------------  // acclient.c:487333
void __thiscall SpellComponentTable::GetSubDataIDs(SpellComponentTable *this, QualifiedDataIDArray *id_array)
{
  PackableHashData<unsigned long,SpellComponentBase> *v2; // esi@1
  unsigned int v3; // ebx@2
  PackableHashData<unsigned long,SpellComponentBase> **v4; // edi@2
  QualifiedDataID *v5; // eax@3
  PackableHashData<unsigned long,SpellComponentBase> *v6; // eax@3
  int v7; // eax@4
  PackableHashIterator<unsigned long,SpellComponentBase> iter; // [sp+4h] [bp-10h]@1

  PackableHashTable<unsigned long,SpellComponentBase>::begin(&this->_spellComponentBaseHash, &iter);
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

//----- (005BC3C0) --------------------------------------------------------  // acclient.c:487380
void __thiscall PackableHashTable<unsigned long,SpellComponentBase>::EmptyContents(PackableHashTable<unsigned long,SpellComponentBase> *this)
{
  unsigned int v1; // eax@2
  PackableHashData<unsigned long,SpellComponentBase> *v2; // esi@3
  AC1Legacy::PSRefBuffer<char> *v3; // edi@4
  PackableHashData<unsigned long,SpellComponentBase> *v4; // ebx@4
  AC1Legacy::PSRefBuffer<char> *v5; // edi@7
  unsigned int i; // [sp+8h] [bp-8h]@2
  PackableHashTable<unsigned long,SpellComponentBase> *v7; // [sp+Ch] [bp-4h]@1

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
            v3 = v2->_data._text.m_buffer;
            v4 = v2->_next;
            if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
              v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
            v5 = v2->_data._name.m_buffer;
            if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
              v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
            v2->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
            operator delete(v2);
            v2 = v4;
          }
          while ( v4 );
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

//----- (005BC480) --------------------------------------------------------  // acclient.c:487430
int __thiscall PackableHashTable<unsigned long,SpellComponentBase>::add(PackableHashTable<unsigned long,SpellComponentBase> *this, const unsigned int *key, SpellComponentBase *data)
{
  PackableHashTable<unsigned long,SpellComponentBase> *v3; // edi@1
  unsigned int v4; // esi@1
  PackableHashData<unsigned long,SpellComponentBase> **v5; // ebx@2
  PackableHashData<unsigned long,SpellComponentBase> *v6; // edx@3
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
  if ( v6 == (PackableHashData<unsigned long,SpellComponentBase> *)-4 )
  {
LABEL_8:
    v7 = operator new(0x30u);
    if ( v7 )
    {
      v8 = v3->_table_size;
      *(_DWORD *)v7 = *key;
      SpellComponentBase::SpellComponentBase((SpellComponentBase *)((char *)v7 + 4), data);
      *((_DWORD *)v7 + 10) = 0;
      v9 = *key % v8;
      *((_DWORD *)v7 + 11) = v9;
      *((_DWORD *)v7 + 10) = v3->_buckets[v9];
      v3->_buckets[v9] = (PackableHashData<unsigned long,SpellComponentBase> *)v7;
      ++v3->_currNum;
      return 1;
    }
  }
  return 0;
}

//----- (005BC520) --------------------------------------------------------  // acclient.c:487478
PackableHashTable<unsigned long,SpellComponentBase> *__thiscall PackableHashTable<unsigned long,SpellComponentBase>::operator=(PackableHashTable<unsigned long,SpellComponentBase> *this, int a2)
{
  PackableHashTable<unsigned long,SpellComponentBase> *v2; // edi@1
  unsigned int v3; // ebx@2
  int v4; // eax@5
  int v5; // esi@6

  v2 = this;
  if ( this != (PackableHashTable<unsigned long,SpellComponentBase> *)a2 )
  {
    PackableHashTable<unsigned long,SpellComponentBase>::EmptyContents(this);
    v3 = 0;
    if ( v2->_buckets )
    {
      operator delete[](v2->_buckets);
      v2->_buckets = 0;
    }
    v2->_table_size = 0;
    v2->_table_size = *(_DWORD *)(a2 + 12);
    PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
    if ( *(_DWORD *)(a2 + 12) > 0u )
    {
      do
      {
        v4 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4 * v3);
        if ( v4 )
        {
          do
          {
            v5 = *(_DWORD *)(v4 + 40);
            PackableHashTable<unsigned long,SpellComponentBase>::add(
              v2,
              (const unsigned int *)v4,
              (SpellComponentBase *)(v4 + 4));
            v4 = v5;
          }
          while ( v5 );
        }
        ++v3;
      }
      while ( v3 < *(_DWORD *)(a2 + 12) );
    }
  }
  return v2;
}

//----- (005BC5A0) --------------------------------------------------------  // acclient.c:487525
void __thiscall PackableHashTable<unsigned long,SpellComponentBase>::~PackableHashTable<unsigned long,SpellComponentBase>(PackableHashTable<unsigned long,SpellComponentBase> *this)
{
  PackableHashTable<unsigned long,SpellComponentBase> *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,SpellComponentBase>::vftable;
  PackableHashTable<unsigned long,SpellComponentBase>::EmptyContents(this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E74C4: using guessed type int (__thiscall *PackableHashTable<unsigned long,SpellComponentBase>::vftable)(void *, char);

//----- (005BC5E0) --------------------------------------------------------  // acclient.c:487544
int __thiscall PackableHashTable<unsigned long,SpellComponentBase>::UnPack(PackableHashTable<unsigned long,SpellComponentBase> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<unsigned long,SpellComponentBase> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  int v10; // ebx@5
  unsigned int v11; // ebp@5
  void *v12; // eax@12
  PackObjVtbl *v13; // edx@12
  SpellComponentBase *v14; // ecx@16
  void *start_addr; // [sp+8h] [bp-2Ch]@3
  unsigned int blob_size; // [sp+Ch] [bp-28h]@3
  SpellComponentBase tempData; // [sp+10h] [bp-24h]@10

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,SpellComponentBase>::EmptyContents(this);
  if ( v4->_buckets )
  {
    operator delete[](v4->_buckets);
    v4->_buckets = 0;
  }
  v4->_table_size = 0;
  v7 = *(_DWORD *)*v6;
  *v6 = (char *)*v6 + 4;
  v8 = v7 >> 16;
  v9 = (unsigned __int16)v7;
  v10 = v3 - 4;
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 <= 0x10000
    && v9 <= 0x10000
    && PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
  {
    SpellComponentBase::SpellComponentBase(&tempData);
    size = 0;
    if ( v11 )
    {
      while ( (unsigned int)v10 >= 4 )
      {
        v12 = *v6;
        v13 = tempData.vfptr;
        addr = *(void ***)*v6;
        *v6 = (char *)v12 + 4;
        if ( !((int (__thiscall *)(SpellComponentBase *, void **, int))v13->UnPack)(&tempData, v6, v10)
          || !PackableHashTable<unsigned long,SpellComponentBase>::add(v4, (const unsigned int *)&addr, &tempData)
          && !v4->m_fThrowawayDuplicateKeysOnUnPack )
          break;
        ++size;
        if ( size >= v11 )
          goto LABEL_16;
      }
      v14 = &tempData;
    }
    else
    {
LABEL_16:
      v14 = &tempData;
      if ( blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr )
      {
        SpellComponentBase::~SpellComponentBase(&tempData);
        return 1;
      }
    }
    SpellComponentBase::~SpellComponentBase(v14);
  }
  return 0;
}

//----- (005BC720) --------------------------------------------------------  // acclient.c:487624
PackableHashTable<unsigned long,SpellComponentBase> *__thiscall PackableHashTable<unsigned long,SpellComponentBase>::scalar_deleting_destructor(PackableHashTable<unsigned long,SpellComponentBase> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,SpellComponentBase> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,SpellComponentBase>::vftable;
  PackableHashTable<unsigned long,SpellComponentBase>::EmptyContents(this);
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
// 7E74C4: using guessed type int (__thiscall *PackableHashTable<unsigned long,SpellComponentBase>::vftable)(void *, char);

//----- (005BC770) --------------------------------------------------------  // acclient.c:487646
void __thiscall SpellComponentTable::SpellComponentTable(SpellComponentTable *this, IDClass<_tagDataID,32,0> did)
{
  SpellComponentTable *v2; // edi@1
  int v3; // ecx@1
  PackableHashTable<IDClass<_tagDataID,32,0>,long> v4; // [sp+Ch] [bp-14h]@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, did);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (InterfaceVtbl *)&SpellComponentTable::vftable;
  v2->vfptr = (PackObjVtbl *)&SpellComponentTable::vftable;
  v3 = (int)&v2->_spellComponentBaseHash;
  *(_DWORD *)v3 = &PackableHashTable<unsigned long,SpellComponentBase>::vftable;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 32;
  *(_DWORD *)(v3 + 16) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&v2->_spellComponentBaseHash);
  v4.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,SpellComponentBase>::vftable;
  v4.m_fThrowawayDuplicateKeysOnUnPack = 0;
  v4._buckets = 0;
  v4._table_size = 256;
  v4._currNum = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init(&v4);
  PackableHashTable<unsigned long,SpellComponentBase>::operator=(&v2->_spellComponentBaseHash, (int)&v4);
  v4.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,SpellComponentBase>::vftable;
  PackableHashTable<unsigned long,SpellComponentBase>::EmptyContents((PackableHashTable<unsigned long,SpellComponentBase> *)&v4);
  if ( v4._buckets )
    operator delete[](v4._buckets);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E74C4: using guessed type int (__thiscall *PackableHashTable<unsigned long,SpellComponentBase>::vftable)(void *, char);
// 7E74D8: using guessed type void *SpellComponentTable::vftable;
// 7E74F0: using guessed type __int32 (__stdcall *SpellComponentTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005BC820) --------------------------------------------------------  // acclient.c:487682
SerializeUsingPackDBObj *__thiscall SpellComponentTable::vector_deleting_destructor(SpellComponentTable *this, unsigned int a2)
{
  return SpellComponentTable::vector_deleting_destructor((SpellComponentTable *)((char *)this - 48), a2);
}

//----- (005BC830) --------------------------------------------------------  // acclient.c:487688
SerializeUsingPackDBObj *__thiscall SpellComponentTable::vector_deleting_destructor(SpellComponentTable *this, unsigned int a2)
{
  SerializeUsingPackDBObj *v2; // esi@1

  v2 = (SerializeUsingPackDBObj *)this;
  this->vfptr = (InterfaceVtbl *)&SpellComponentTable::vftable;
  this->vfptr = (PackObjVtbl *)&SpellComponentTable::vftable;
  PackableHashTable<unsigned long,SpellComponentBase>::~PackableHashTable<unsigned long,SpellComponentBase>(&this->_spellComponentBaseHash);
  SerializeUsingPackDBObj::~SerializeUsingPackDBObj(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E74D8: using guessed type void *SpellComponentTable::vftable;
// 7E74F0: using guessed type __int32 (__stdcall *SpellComponentTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0070EA80) --------------------------------------------------------  // acclient.c:801655
int sub_70EA80()
{
  return atexit(nullsub_1581);
}

//----- (0070EA90) --------------------------------------------------------  // acclient.c:801661
int _E4_7()
{
  return atexit(_E5_7);
}

//----- (0070EAA0) --------------------------------------------------------  // acclient.c:801667
int _E7_7()
{
  Outside_CellID_7.id = Invalid_CellID_7.id + 1;
  return atexit(_E8_7);
}

//----- (0070EAC0) --------------------------------------------------------  // acclient.c:801674
int _E10_6()
{
  In_Limbo_CellID_6.id = Outside_CellID_7.id + 1;
  return atexit(_E11_6);
}

//----- (0070EAE0) --------------------------------------------------------  // acclient.c:801681
int _E13_6()
{
  First_Interior_CellID_6.id = In_Limbo_CellID_6.id + 1;
  return atexit(_E14_6);
}

//----- (0070EB00) --------------------------------------------------------  // acclient.c:801688
int _E16_6()
{
  Last_Interior_CellID_6.id = Invalid_CellID_7.id - 1;
  return atexit(_E17_6);
}

//----- (0070EB20) --------------------------------------------------------  // acclient.c:801695
int _E21_8()
{
  return atexit(_E22_8);
}

//----- (0070EB30) --------------------------------------------------------  // acclient.c:801701
int _E40_8()
{
  return atexit(_E41_8);
}

//----- (0070EB40) --------------------------------------------------------  // acclient.c:801707
int _E43_11()
{
  return atexit(_E44_11);
}

