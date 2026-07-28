/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CContractTable
   Object     : AC\accquest\CContractTable.obj
   Functions  : 19
   Addresses  : 004D88D0 - 0070B000 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004D88D0) --------------------------------------------------------  // acclient.c:263560
signed int CContractTable::GetDBOType()
{
  return 268435472;
}

//----- (00599910) --------------------------------------------------------  // acclient.c:451910
PackableHashIterator<unsigned long,CContract> *__thiscall PackableHashIterator<unsigned long,CContract>::scalar_deleting_destructor(PackableHashIterator<unsigned long,CContract> *this, unsigned int a2)
{
  PackableHashIterator<unsigned long,CContract> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackableHashIterator<unsigned long,CContract>Vtbl *)PackableHashIterator<unsigned long,CContract>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7E5068: using guessed type int (__thiscall *PackableHashIterator<unsigned long,CContract>::vftable[2])(void *, char);

//----- (00599930) --------------------------------------------------------  // acclient.c:451923
PackableHashIterator<unsigned long,CContract> *__thiscall PackableHashTable<unsigned long,CContract>::begin(PackableHashTable<unsigned long,CContract> *this, PackableHashIterator<unsigned long,CContract> *result)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  PackableHashData<unsigned long,CContract> **v4; // edi@2
  PackableHashData<unsigned long,CContract> **v5; // esi@2
  PackableHashData<unsigned long,CContract> **v6; // ecx@5
  PackableHashIterator<unsigned long,CContract> *v7; // eax@5
  PackableHashData<unsigned long,CContract> *v8; // ecx@6

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
    result->vfptr = (PackableHashIterator<unsigned long,CContract>Vtbl *)PackableHashIterator<unsigned long,CContract>::vftable;
    result->_table_size = v2;
  }
  else
  {
LABEL_5:
    v6 = this->_buckets;
    v7 = result;
    result->_current = 0;
    result->_buckets = v6;
    result->vfptr = (PackableHashIterator<unsigned long,CContract>Vtbl *)PackableHashIterator<unsigned long,CContract>::vftable;
    result->_table_size = v2;
  }
  return v7;
}
// 7E5068: using guessed type int (__thiscall *PackableHashIterator<unsigned long,CContract>::vftable[2])(void *, char);

//----- (00599990) --------------------------------------------------------  // acclient.c:451968
signed int __thiscall PackableHashTable<unsigned long,CContract>::Pack(PackableHashTable<unsigned long,CContract> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,CContract> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<unsigned long,CContract> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<unsigned long,CContract>::pack_size(this);
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

//----- (00599A20) --------------------------------------------------------  // acclient.c:452019
signed int __thiscall PackableHashTable<unsigned long,CContract>::pack_size(PackableHashTable<unsigned long,CContract> *this)
{
  PackableHashTable<unsigned long,CContract> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<unsigned long,CContract> *i; // esi@2
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

//----- (00599A80) --------------------------------------------------------  // acclient.c:452051
void __thiscall CContract::~CContract(CContract *this)
{
  CContract *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@4
  AC1Legacy::PSRefBuffer<char> *v4; // edi@7
  AC1Legacy::PSRefBuffer<char> *v5; // edi@10
  AC1Legacy::PSRefBuffer<char> *v6; // edi@13
  AC1Legacy::PSRefBuffer<char> *v7; // edi@16
  AC1Legacy::PSRefBuffer<char> *v8; // edi@19
  AC1Legacy::PSRefBuffer<char> *v9; // edi@22
  AC1Legacy::PSRefBuffer<char> *v10; // edi@25
  AC1Legacy::PSRefBuffer<char> *v11; // edi@28
  AC1Legacy::PSRefBuffer<char> *v12; // edi@31

  v1 = this;
  v2 = this->_questflag_repeat_time.m_buffer;
  this->_location_quest_area.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->_location_npc_end.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->_location_npc_start.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v3 = v1->_questflag_timer.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v4 = v1->_questflag_progress.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  v5 = v1->_questflag_finished.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
    v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  v6 = v1->_questflag_started.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
    v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
  v7 = v1->_questflag_stamped.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) && v7 )
    v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
  v8 = v1->_name_npc_end.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) && v8 )
    v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
  v9 = v1->_name_npc_start.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v9->m_cRef) && v9 )
    v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
  v10 = v1->_description_progress.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v10->m_cRef) && v10 )
    v10->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v10, 1u);
  v11 = v1->_description.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v11->m_cRef) && v11 )
    v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
  v12 = v1->_contract_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v12->m_cRef) && v12 )
    v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00599BD0) --------------------------------------------------------  // acclient.c:452108
void __thiscall CContractTable::GetSubDataIDs(CContractTable *this, QualifiedDataIDArray *id_array)
{
  PackableHashData<unsigned long,CContract> *v2; // eax@1
  unsigned int v3; // eax@4
  PackableHashIterator<unsigned long,CContract> iter; // [sp+0h] [bp-10h]@1

  PackableHashTable<unsigned long,CContract>::begin(&this->_contractHash, &iter);
  v2 = iter._current;
  if ( iter._current )
  {
    do
    {
      if ( v2->_next )
      {
        v2 = v2->_next;
      }
      else
      {
        v3 = v2->_hashVal + 1;
        if ( v3 >= iter._table_size )
        {
LABEL_7:
          v2 = 0;
        }
        else
        {
          while ( !iter._buckets[v3] )
          {
            ++v3;
            if ( v3 >= iter._table_size )
              goto LABEL_7;
          }
          v2 = iter._buckets[v3];
        }
      }
    }
    while ( v2 );
  }
}

//----- (00599C30) --------------------------------------------------------  // acclient.c:452149
void __thiscall PackableHashTable<unsigned long,CContract>::EmptyContents(PackableHashTable<unsigned long,CContract> *this)
{
  PackableHashTable<unsigned long,CContract> *v1; // ebx@1
  unsigned int v2; // ebp@2
  PackableHashData<unsigned long,CContract> *v3; // esi@3
  PackableHashData<unsigned long,CContract> *v4; // edi@4

  v1 = this;
  if ( this->_buckets )
  {
    v2 = 0;
    if ( this->_table_size )
    {
      do
      {
        v3 = v1->_buckets[v2];
        if ( v3 )
        {
          do
          {
            v4 = v3->_next;
            CContract::~CContract(&v3->_data);
            operator delete(v3);
            v3 = v4;
          }
          while ( v4 );
        }
        v1->_buckets[v2++] = 0;
      }
      while ( v2 < v1->_table_size );
    }
  }
  v1->_currNum = 0;
}

//----- (00599C90) --------------------------------------------------------  // acclient.c:452185
void __thiscall PackableHashTable<unsigned long,CContract>::~PackableHashTable<unsigned long,CContract>(PackableHashTable<unsigned long,CContract> *this)
{
  PackableHashTable<unsigned long,CContract> *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,CContract>::vftable;
  PackableHashTable<unsigned long,CContract>::EmptyContents(this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E506C: using guessed type int (__thiscall *PackableHashTable<unsigned long,CContract>::vftable)(void *, char);

//----- (00599CD0) --------------------------------------------------------  // acclient.c:452204
int __thiscall PackableHashTable<unsigned long,CContract>::UnPack(PackableHashTable<unsigned long,CContract> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,CContract> *v3; // esi@1
  unsigned int v5; // eax@5
  unsigned int v6; // ecx@5
  unsigned int v7; // eax@5
  unsigned int v8; // ebx@5
  unsigned int v9; // ebp@5
  void *v10; // eax@12
  PackObjVtbl *v11; // edx@12
  CContract *v12; // ecx@16
  unsigned int i; // [sp+8h] [bp-120h]@10
  void *start_addr; // [sp+Ch] [bp-11Ch]@3
  unsigned int tempKey; // [sp+14h] [bp-114h]@12
  CContract tempData; // [sp+18h] [bp-110h]@10

  v3 = this;
  if ( size < 4 )
    return 0;
  start_addr = *addr;
  PackableHashTable<unsigned long,CContract>::EmptyContents(this);
  if ( v3->_buckets )
  {
    operator delete[](v3->_buckets);
    v3->_buckets = 0;
  }
  v3->_table_size = 0;
  v5 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  v6 = v5 >> 16;
  v7 = (unsigned __int16)v5;
  v8 = size - 4;
  v3->_table_size = v6;
  v9 = v7;
  if ( !v6 )
    return v7 == 0;
  if ( v6 <= 0x10000
    && v7 <= 0x10000
    && PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3) )
  {
    CContract::CContract(&tempData);
    i = 0;
    if ( v9 )
    {
      while ( v8 >= 4 )
      {
        v10 = *addr;
        v11 = tempData.vfptr;
        tempKey = *(_DWORD *)*addr;
        *addr = (char *)v10 + 4;
        if ( !((int (__thiscall *)(CContract *, void **, unsigned int))v11->UnPack)(&tempData, addr, v8)
          || !PackableHashTable<unsigned long,CContract>::add(v3, &tempKey, &tempData)
          && !v3->m_fThrowawayDuplicateKeysOnUnPack )
          break;
        ++i;
        if ( i >= v9 )
          goto LABEL_16;
      }
      v12 = &tempData;
    }
    else
    {
LABEL_16:
      v12 = &tempData;
      if ( size >= (_BYTE *)*addr - (_BYTE *)start_addr )
      {
        CContract::~CContract(&tempData);
        return 1;
      }
    }
    CContract::~CContract(v12);
  }
  return 0;
}

//----- (00599E30) --------------------------------------------------------  // acclient.c:452280
int __thiscall PackableHashTable<unsigned long,CContract>::add(PackableHashTable<unsigned long,CContract> *this, const unsigned int *key, CContract *data)
{
  PackableHashTable<unsigned long,CContract> *v3; // edi@1
  unsigned int v4; // esi@1
  PackableHashData<unsigned long,CContract> **v5; // ebx@2
  PackableHashData<unsigned long,CContract> *v6; // edx@3
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
  if ( v6 == (PackableHashData<unsigned long,CContract> *)-4 )
  {
LABEL_8:
    v7 = operator new(0x11Cu);
    if ( v7 )
    {
      v8 = v3->_table_size;
      *(_DWORD *)v7 = *key;
      CContract::CContract((CContract *)((char *)v7 + 4), data);
      *((_DWORD *)v7 + 69) = 0;
      v9 = *key % v8;
      *((_DWORD *)v7 + 70) = v9;
      *((_DWORD *)v7 + 69) = v3->_buckets[v9];
      v3->_buckets[v9] = (PackableHashData<unsigned long,CContract> *)v7;
      ++v3->_currNum;
      return 1;
    }
  }
  return 0;
}

//----- (00599EE0) --------------------------------------------------------  // acclient.c:452328
PackableHashTable<unsigned long,CContract> *__thiscall PackableHashTable<unsigned long,CContract>::vector_deleting_destructor(PackableHashTable<unsigned long,CContract> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,CContract> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,CContract>::vftable;
  PackableHashTable<unsigned long,CContract>::EmptyContents(this);
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
// 7E506C: using guessed type int (__thiscall *PackableHashTable<unsigned long,CContract>::vftable)(void *, char);

//----- (00599F30) --------------------------------------------------------  // acclient.c:452350
void __thiscall CContractTable::CContractTable(CContractTable *this, IDClass<_tagDataID,32,0> did)
{
  CContractTable *v2; // esi@1
  int v3; // ecx@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, did);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v3 = (int)&v2->_contractHash;
  v2->vfptr = (InterfaceVtbl *)&CContractTable::vftable;
  v2->vfptr = (PackObjVtbl *)&CContractTable::vftable;
  *(_DWORD *)v3 = &PackableHashTable<unsigned long,CContract>::vftable;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 4096;
  *(_DWORD *)(v3 + 16) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&v2->_contractHash);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E506C: using guessed type int (__thiscall *PackableHashTable<unsigned long,CContract>::vftable)(void *, char);
// 7E5080: using guessed type void *CContractTable::vftable;
// 7E5098: using guessed type __int32 (__stdcall *CContractTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00599F80) --------------------------------------------------------  // acclient.c:452374
SerializeUsingPackDBObj *__thiscall CContractTable::vector_deleting_destructor(CContractTable *this, unsigned int a2)
{
  return CContractTable::vector_deleting_destructor((CContractTable *)((char *)this - 48), a2);
}

//----- (00599F90) --------------------------------------------------------  // acclient.c:452380
SerializeUsingPackDBObj *__thiscall CContractTable::vector_deleting_destructor(CContractTable *this, unsigned int a2)
{
  SerializeUsingPackDBObj *v2; // esi@1

  v2 = (SerializeUsingPackDBObj *)this;
  this->vfptr = (InterfaceVtbl *)&CContractTable::vftable;
  this->vfptr = (PackObjVtbl *)&CContractTable::vftable;
  PackableHashTable<unsigned long,CContract>::~PackableHashTable<unsigned long,CContract>(&this->_contractHash);
  SerializeUsingPackDBObj::~SerializeUsingPackDBObj(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E5080: using guessed type void *CContractTable::vftable;
// 7E5098: using guessed type __int32 (__stdcall *CContractTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0070AFA0) --------------------------------------------------------  // acclient.c:798170
void sub_70AFA0()
{
  flt_871144 = 1000.0 + 1.0;
}

//----- (0070AFC0) --------------------------------------------------------  // acclient.c:798176
void sub_70AFC0()
{
  flt_871148 = 24.0 * 8.0;
}

//----- (0070AFE0) --------------------------------------------------------  // acclient.c:798182
void sub_70AFE0()
{
  flt_87114C = 24.0 * 0.5;
}

//----- (0070B000) --------------------------------------------------------  // acclient.c:798188
int sub_70B000()
{
  return atexit(nullsub_1432);
}

