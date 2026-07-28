/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SkillTable
   Object     : AC\acqualities\SkillTable.obj
   Functions  : 15
   Addresses  : 004E6380 - 00710000 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E6380) --------------------------------------------------------  // acclient.c:276162
signed int SkillTable::GetDBOType()
{
  return 268435460;
}

//----- (004FDB10) --------------------------------------------------------  // acclient.c:297841
int __thiscall SkillTable::UnPack(SkillTable *this, void **addr, unsigned int size)
{
  void **v3; // esi@1
  void *v4; // ebp@1
  SkillTable *v5; // edi@1
  int v6; // eax@1
  unsigned int v7; // eax@1
  unsigned int v8; // ebx@1

  v3 = addr;
  v4 = *addr;
  v5 = this;
  v6 = *(_DWORD *)&this->m_bLoaded;
  addr = 0;
  v7 = (*(int (__thiscall **)(bool *, void ***, _DWORD))(v6 + 12))(&this->m_bLoaded, &addr, 0);
  v8 = size;
  if ( size < v7 )
    return 0;
  (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)&v5->m_bLoaded + 16))(&v5->m_bLoaded, v3, size);
  if ( v8 < (_BYTE *)*v3 - (_BYTE *)v4 )
  {
    *v3 = v4;
    return 0;
  }
  return 1;
}

//----- (005CB620) --------------------------------------------------------  // acclient.c:503012
signed int __thiscall PackableHashTable<unsigned long,SkillBase>::Pack(PackableHashTable<unsigned long,SkillBase> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,SkillBase> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<unsigned long,SkillBase> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<unsigned long,SkillBase>::pack_size(this);
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

//----- (005CB6B0) --------------------------------------------------------  // acclient.c:503063
signed int __thiscall PackableHashTable<unsigned long,SkillBase>::pack_size(PackableHashTable<unsigned long,SkillBase> *this)
{
  PackableHashTable<unsigned long,SkillBase> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<unsigned long,SkillBase> *i; // esi@2
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

//----- (005CB710) --------------------------------------------------------  // acclient.c:503095
void __thiscall SkillTable::GetSubDataIDs(SkillTable *this, QualifiedDataIDArray *id_array)
{
  PackableHashData<unsigned long,SkillBase> *v2; // esi@1
  unsigned int v3; // ebx@2
  PackableHashData<unsigned long,SkillBase> **v4; // edi@2
  QualifiedDataID *v5; // eax@3
  PackableHashData<unsigned long,SkillBase> *v6; // eax@3
  int v7; // eax@4
  PackableHashIterator<unsigned long,SkillBase> iter; // [sp+4h] [bp-10h]@1

  PackableHashTable<unsigned long,SkillBase>::begin(&this->_skillBaseHash, &iter);
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

//----- (005CB790) --------------------------------------------------------  // acclient.c:503142
void __thiscall PackableHashTable<unsigned long,SkillBase>::EmptyContents(PackableHashTable<unsigned long,SkillBase> *this)
{
  unsigned int v1; // eax@2
  PackableHashData<unsigned long,SkillBase> *v2; // esi@3
  AC1Legacy::PSRefBuffer<char> *v3; // edi@4
  PackableHashData<unsigned long,SkillBase> *v4; // ebx@4
  AC1Legacy::PSRefBuffer<char> *v5; // edi@7
  unsigned int i; // [sp+8h] [bp-8h]@2
  PackableHashTable<unsigned long,SkillBase> *v7; // [sp+Ch] [bp-4h]@1

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
            v3 = v2->_data._name.m_buffer;
            v4 = v2->_next;
            v2->_data._formula.vfptr = (PackObjVtbl *)&PackObj::vftable;
            if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
              v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
            v5 = v2->_data._description.m_buffer;
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

//----- (005CB850) --------------------------------------------------------  // acclient.c:503193
void __thiscall PackableHashTable<unsigned long,SkillBase>::~PackableHashTable<unsigned long,SkillBase>(PackableHashTable<unsigned long,SkillBase> *this)
{
  PackableHashTable<unsigned long,SkillBase> *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,SkillBase>::vftable;
  PackableHashTable<unsigned long,SkillBase>::EmptyContents(this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E81C0: using guessed type int (__thiscall *PackableHashTable<unsigned long,SkillBase>::vftable)(void *, char);

//----- (005CB890) --------------------------------------------------------  // acclient.c:503212
int __thiscall PackableHashTable<unsigned long,SkillBase>::UnPack(PackableHashTable<unsigned long,SkillBase> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<unsigned long,SkillBase> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  int v10; // ebx@5
  unsigned int v11; // ebp@5
  void *v12; // eax@12
  PackObjVtbl *v13; // edx@12
  SkillBase *v14; // ecx@16
  void *start_addr; // [sp+8h] [bp-60h]@3
  unsigned int blob_size; // [sp+Ch] [bp-5Ch]@3
  SkillBase tempData; // [sp+10h] [bp-58h]@10

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,SkillBase>::EmptyContents(this);
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
    SkillBase::SkillBase(&tempData);
    size = 0;
    if ( v11 )
    {
      while ( (unsigned int)v10 >= 4 )
      {
        v12 = *v6;
        v13 = tempData.vfptr;
        addr = *(void ***)*v6;
        *v6 = (char *)v12 + 4;
        if ( !((int (__thiscall *)(SkillBase *, void **, int))v13->UnPack)(&tempData, v6, v10)
          || !PackableHashTable<unsigned long,SkillBase>::add(v4, (const unsigned int *)&addr, &tempData)
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
        SkillBase::~SkillBase(&tempData);
        return 1;
      }
    }
    SkillBase::~SkillBase(v14);
  }
  return 0;
}

//----- (005CB9D0) --------------------------------------------------------  // acclient.c:503292
int __thiscall PackableHashTable<unsigned long,SkillBase>::add(PackableHashTable<unsigned long,SkillBase> *this, const unsigned int *key, SkillBase *data)
{
  PackableHashTable<unsigned long,SkillBase> *v3; // edi@1
  unsigned int v4; // esi@1
  PackableHashData<unsigned long,SkillBase> **v5; // ebx@2
  PackableHashData<unsigned long,SkillBase> *v6; // edx@3
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
  if ( v6 == (PackableHashData<unsigned long,SkillBase> *)-8 )
  {
LABEL_8:
    v7 = operator new(0x68u);
    if ( v7 )
    {
      v8 = v3->_table_size;
      *(_DWORD *)v7 = *key;
      SkillBase::SkillBase((SkillBase *)((char *)v7 + 8), data);
      *((_DWORD *)v7 + 24) = 0;
      v9 = *key % v8;
      *((_DWORD *)v7 + 25) = v9;
      *((_DWORD *)v7 + 24) = v3->_buckets[v9];
      v3->_buckets[v9] = (PackableHashData<unsigned long,SkillBase> *)v7;
      ++v3->_currNum;
      return 1;
    }
  }
  return 0;
}

//----- (005CBA70) --------------------------------------------------------  // acclient.c:503340
void __thiscall SkillBase::SkillBase(SkillBase *this, SkillBase *__that)
{
  SkillBase *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // eax@1
  AC1Legacy::PSRefBuffer<char> *v4; // eax@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&SkillBase::vftable;
  v3 = __that->_description.m_buffer;
  this->_description.m_buffer = v3;
  InterlockedIncrement((volatile LONG *)&v3->m_cRef);
  v4 = __that->_name.m_buffer;
  v2->_name.m_buffer = v4;
  InterlockedIncrement((volatile LONG *)&v4->m_cRef);
  v2->_iconID.id = __that->_iconID.id;
  v2->_trained_cost = __that->_trained_cost;
  v2->_specialized_cost = __that->_specialized_cost;
  v2->_category = __that->_category;
  v2->_chargen_use = __that->_chargen_use;
  v2->_min_level = __that->_min_level;
  SkillFormula::SkillFormula(&v2->_formula, &__that->_formula);
  v2->_upper_bound = __that->_upper_bound;
  v2->_lower_bound = __that->_lower_bound;
  v2->_learn_mod = __that->_learn_mod;
}
// 7C4020: using guessed type int (__thiscall *SkillBase::vftable)(void *, char);

//----- (005CBB00) --------------------------------------------------------  // acclient.c:503368
PackableHashTable<unsigned long,SkillBase> *__thiscall PackableHashTable<unsigned long,SkillBase>::vector_deleting_destructor(PackableHashTable<unsigned long,SkillBase> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,SkillBase> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,SkillBase>::vftable;
  PackableHashTable<unsigned long,SkillBase>::EmptyContents(this);
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
// 7E81C0: using guessed type int (__thiscall *PackableHashTable<unsigned long,SkillBase>::vftable)(void *, char);

//----- (005CBB50) --------------------------------------------------------  // acclient.c:503390
void __thiscall SkillTable::SkillTable(SkillTable *this, IDClass<_tagDataID,32,0> did)
{
  SkillTable *v2; // esi@1
  int v3; // ecx@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, did);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v3 = (int)&v2->_skillBaseHash;
  v2->vfptr = (InterfaceVtbl *)&SkillTable::vftable;
  v2->vfptr = (PackObjVtbl *)&SkillTable::vftable;
  *(_DWORD *)v3 = &PackableHashTable<unsigned long,SkillBase>::vftable;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 32;
  *(_DWORD *)(v3 + 16) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&v2->_skillBaseHash);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E81C0: using guessed type int (__thiscall *PackableHashTable<unsigned long,SkillBase>::vftable)(void *, char);
// 7E81D4: using guessed type void *SkillTable::vftable;
// 7E81E8: using guessed type __int32 (__stdcall *SkillTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005CBBA0) --------------------------------------------------------  // acclient.c:503414
SerializeUsingPackDBObj *__thiscall SkillTable::vector_deleting_destructor(SkillTable *this, unsigned int a2)
{
  return SkillTable::scalar_deleting_destructor((SkillTable *)((char *)this - 48), a2);
}

//----- (005CBBB0) --------------------------------------------------------  // acclient.c:503420
SerializeUsingPackDBObj *__thiscall SkillTable::scalar_deleting_destructor(SkillTable *this, unsigned int a2)
{
  SerializeUsingPackDBObj *v2; // esi@1

  v2 = (SerializeUsingPackDBObj *)this;
  this->vfptr = (InterfaceVtbl *)&SkillTable::vftable;
  this->vfptr = (PackObjVtbl *)&SkillTable::vftable;
  PackableHashTable<unsigned long,SkillBase>::~PackableHashTable<unsigned long,SkillBase>(&this->_skillBaseHash);
  SerializeUsingPackDBObj::~SerializeUsingPackDBObj(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E81D4: using guessed type void *SkillTable::vftable;
// 7E81E8: using guessed type __int32 (__stdcall *SkillTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00710000) --------------------------------------------------------  // acclient.c:803277
int sub_710000()
{
  return atexit(nullsub_1832);
}

