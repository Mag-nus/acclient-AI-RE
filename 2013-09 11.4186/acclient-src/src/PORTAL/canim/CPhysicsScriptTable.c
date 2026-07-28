/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPhysicsScriptTable
   Object     : PORTAL\canim\CPhysicsScriptTable.obj
   Functions  : 21
   Addresses  : 00500EA0 - 006FD640 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00500EA0) --------------------------------------------------------  // acclient.c:301693
void __thiscall AC1Legacy::SmartArray<ScriptAndModData>::Reset(AC1Legacy::SmartArray<ScriptAndModData> *this)
{
  AC1Legacy::SmartArray<ScriptAndModData> *v1; // esi@1
  ScriptAndModData *v2; // eax@1
  bool v3; // zf@1

  v1 = this;
  v2 = this->m_data;
  v3 = this->m_data == 0;
  this->m_num = 0;
  this->m_size = 0;
  if ( !v3 )
    operator delete[](&v2[-1].script_id);
  v1->m_data = 0;
}

//----- (00521A20) --------------------------------------------------------  // acclient.c:336551
IDClass<_tagDataID,32,0> *__thiscall PhysicsScriptTableData::GetScript(PhysicsScriptTableData *this, IDClass<_tagDataID,32,0> *result, float mod)
{
  unsigned int v3; // esi@1
  unsigned int v4; // edx@1
  ScriptAndModData *v5; // ecx@2
  IDClass<_tagDataID,32,0> *v6; // eax@5

  v3 = this->script_array.m_num;
  v4 = 0;
  if ( v3 )
  {
    v5 = this->script_array.m_data;
    while ( mod > (double)v5->mod )
    {
      ++v4;
      ++v5;
      if ( v4 >= v3 )
        goto LABEL_5;
    }
    v6 = result;
    result->id = v5->script_id.id;
  }
  else
  {
LABEL_5:
    v6 = result;
    result->id = stru_8444D0.id;
  }
  return v6;
}

//----- (00521A70) --------------------------------------------------------  // acclient.c:336583
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0> *v2; // esi@1
  HashTableData<unsigned long,PhysicsScriptTableData *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>::vftable;
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
// 7C7C58: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>::vftable[2])(void *, char);

//----- (00521AB0) --------------------------------------------------------  // acclient.c:336604
int __thiscall PhysicsScriptTableData::Pack(PhysicsScriptTableData *this, void **addr, unsigned int size)
{
  unsigned int v3; // esi@1
  int result; // eax@1
  char *v5; // edi@4
  unsigned int v6; // ebx@4
  ScriptAndModData *v7; // esi@5
  char *v8; // edi@6
  char *v9; // eax@6
  int v10; // [sp+8h] [bp-4h]@1

  v3 = this->script_array.m_num;
  result = 4;
  v10 = 4;
  if ( v3 )
  {
    result = 8 * v3 + 4;
    v10 = 8 * v3 + 4;
  }
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3;
    v5 = (char *)*addr + 4;
    *addr = v5;
    v6 = 0;
    if ( this->script_array.m_num )
    {
      do
      {
        v7 = &this->script_array.m_data[v6];
        if ( size >= 8 )
        {
          *(_DWORD *)v5 = LODWORD(v7->mod);
          v8 = (char *)*addr + 4;
          *addr = v8;
          *(_DWORD *)v8 = v7->script_id.id;
          v9 = (char *)*addr + 4;
          *addr = v9;
          v5 = v9;
          result = v10;
        }
        ++v6;
      }
      while ( v6 < this->script_array.m_num );
    }
  }
  return result;
}

//----- (00521B30) --------------------------------------------------------  // acclient.c:336654
void __thiscall PhysicsScriptTableData::GetSubDataIDs(PhysicsScriptTableData *this, QualifiedDataIDArray *id_array)
{
  PhysicsScriptTableData *v2; // edi@1
  unsigned int v3; // esi@1
  QualifiedDataID *v4; // eax@2
  QualifiedDataID v5; // [sp+8h] [bp-8h]@2

  v2 = this;
  v3 = 0;
  if ( this->script_array.m_num )
  {
    do
    {
      QualifiedDataID::QualifiedDataID(&v5, v2->script_array.m_data[v3].script_id, 0);
      QualifiedDataIDArray::AddQDID(id_array, v4, 8u);
      ++v3;
    }
    while ( v3 < v2->script_array.m_num );
  }
}

//----- (00521B80) --------------------------------------------------------  // acclient.c:336676
int __thiscall AC1Legacy::SmartArray<ScriptAndModData>::grow(AC1Legacy::SmartArray<ScriptAndModData> *this, unsigned int _size)
{
  AC1Legacy::SmartArray<ScriptAndModData> *v2; // esi@1
  void *v4; // eax@5
  int v5; // edi@6
  unsigned int v6; // eax@8
  ScriptAndModData *v7; // ecx@9

  v2 = this;
  if ( _size >= this->m_num )
  {
    if ( _size <= this->m_size )
      return 1;
    if ( !_size )
    {
      AC1Legacy::SmartArray<ScriptAndModData>::Reset(this);
      return 1;
    }
    v4 = operator new[](8 * _size + 4);
    if ( v4 )
    {
      v5 = (int)((char *)v4 + 4);
      *(_DWORD *)v4 = _size;
      vector_constructor_iterator(
        (char *)v4 + 4,
        8u,
        _size,
        (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
      if ( v5 )
      {
        if ( v2->m_data )
        {
          v6 = 0;
          if ( v2->m_num )
          {
            do
            {
              v7 = v2->m_data;
              *(_DWORD *)(v5 + 8 * v6) = LODWORD(v2->m_data[v6].mod);
              *(_DWORD *)(v5 + 8 * v6 + 4) = v7[v6].script_id.id;
              ++v6;
            }
            while ( v6 < v2->m_num );
          }
          if ( v2->m_data )
            operator delete[](&v2->m_data[-1].script_id);
        }
        v2->m_data = (ScriptAndModData *)v5;
        v2->m_size = _size;
        return 1;
      }
    }
  }
  return 0;
}

//----- (00521C30) --------------------------------------------------------  // acclient.c:336733
signed int __thiscall PhysicsScriptTable::pack_size(PhysicsScriptTable *this, int *num_scripts)
{
  signed int v2; // ebx@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // ebp@1
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // ecx@1
  HashTableData<unsigned long,HeritageGroup_CG> *v6; // eax@1
  void (__thiscall *v7)(HeritageGroup_CG *, Archive *); // edx@2
  int v8; // esi@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@1

  v2 = 4;
  *num_scripts = 0;
  v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->script_table.m_intrusiveTable,
         &result);
  v4 = v3->m_currHashTable;
  v5 = v3->m_currBucket;
  v6 = v3->m_currElement;
  if ( v6 )
  {
    do
    {
LABEL_2:
      ++*num_scripts;
      v7 = v6->m_data.vfptr[2].Serialize;
      v8 = 4;
      if ( v7 )
        v8 = 8 * (_DWORD)v7 + 4;
      v6 = v6->m_hashNext;
      v2 += v8 + 4;
    }
    while ( v6 );
    while ( 1 )
    {
      ++v5;
      if ( v5 == &v4->m_buckets[v4->m_numBuckets] )
        break;
      if ( *v5 )
      {
        v6 = *v5;
        if ( *v5 )
          goto LABEL_2;
        return v2;
      }
    }
  }
  return v2;
}

//----- (00521CB0) --------------------------------------------------------  // acclient.c:336784
unsigned int __thiscall PhysicsScriptTable::Pack(PhysicsScriptTable *this, void **addr, unsigned int size)
{
  PhysicsScriptTable *v3; // esi@1
  unsigned int v4; // eax@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // eax@2
  HashTableData<unsigned long,HeritageGroup_CG> *v6; // esi@2
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // ebp@2
  HashTableData<unsigned long,HeritageGroup_CG> **v8; // ebx@2
  PhysicsScriptTableData *v9; // ecx@3
  int num_physics_scripts; // [sp+4h] [bp-14h]@1
  unsigned int retval; // [sp+8h] [bp-10h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@2

  v3 = this;
  num_physics_scripts = 0;
  v4 = PhysicsScriptTable::pack_size((PhysicsScriptTable *)((char *)this - 48), &num_physics_scripts);
  retval = v4;
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = num_physics_scripts;
    *addr = (char *)*addr + 4;
    v5 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)(&v3->m_bLoaded + 4),
           &result);
    v6 = v5->m_currElement;
    v7 = v5->m_currHashTable;
    v8 = v5->m_currBucket;
    if ( v6 )
    {
      do
      {
LABEL_3:
        v9 = (PhysicsScriptTableData *)v6->m_data.vfptr;
        *(_DWORD *)*addr = v6->m_hashKey;
        *addr = (char *)*addr + 4;
        PhysicsScriptTableData::Pack(v9, addr, size);
        v6 = v6->m_hashNext;
      }
      while ( v6 );
      while ( 1 )
      {
        ++v8;
        if ( v8 == &v7->m_buckets[v7->m_numBuckets] )
          break;
        if ( *v8 )
        {
          v6 = *v8;
          if ( *v8 )
            goto LABEL_3;
          break;
        }
      }
    }
    v4 = retval;
  }
  return v4;
}

//----- (00521D60) --------------------------------------------------------  // acclient.c:336843
void __thiscall PhysicsScriptTable::GetSubDataIDs(PhysicsScriptTable *this, QualifiedDataIDArray *id_array)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@1

  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->script_table.m_intrusiveTable,
         &result);
  v3 = v2->m_currElement;
  v4 = v2->m_currHashTable;
  v5 = v2->m_currBucket;
  if ( v3 )
  {
    do
    {
LABEL_2:
      PhysicsScriptTableData::GetSubDataIDs((PhysicsScriptTableData *)v3->m_data.vfptr, id_array);
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

//----- (00521DC0) --------------------------------------------------------  // acclient.c:336883
int __thiscall PhysicsScriptTableData::UnPack(PhysicsScriptTableData *this, void **addr, unsigned int size)
{
  int v3; // ebx@1
  unsigned int v4; // ST04_4@1
  PhysicsScriptTableData *v5; // esi@1
  float v6; // ecx@2
  char *v7; // eax@2
  unsigned int v8; // ebp@2
  unsigned int v9; // eax@2
  unsigned int v10; // eax@4
  unsigned int v11; // edx@7
  ScriptAndModData *v12; // eax@7
  float data; // [sp+Ch] [bp-8h]@2

  v3 = *(_DWORD *)*addr;
  v4 = *(_DWORD *)*addr;
  v5 = this;
  *addr = (char *)*addr + 4;
  AC1Legacy::SmartArray<ScriptAndModData>::grow(&this->script_array, v4);
  if ( v3 > 0 )
  {
    do
    {
      v6 = *(float *)*addr;
      v7 = (char *)*addr + 4;
      *addr = v7;
      v8 = *(_DWORD *)v7;
      *addr = v7 + 4;
      v9 = v5->script_array.m_size;
      data = v6;
      if ( v5->script_array.m_num < v9
        || (!v9 ? (v10 = 8) : (v10 = 2 * v9), AC1Legacy::SmartArray<ScriptAndModData>::grow(&v5->script_array, v10)) )
      {
        v11 = v5->script_array.m_num;
        v12 = v5->script_array.m_data;
        v12[v11].mod = data;
        v12[v11].script_id.id = v8;
        ++v5->script_array.m_num;
      }
      --v3;
    }
    while ( v3 );
  }
  return 1;
}

//----- (00521E40) --------------------------------------------------------  // acclient.c:336930
IDClass<_tagDataID,32,0> *__thiscall PhysicsScriptTable::GetScript(PhysicsScriptTable *this, IDClass<_tagDataID,32,0> *result, PScriptType type, float mod)
{
  HashTableData<unsigned long,PhysicsScriptTableData *> *v4; // eax@1
  IDClass<_tagDataID,32,0> *v5; // eax@4

  v4 = this->script_table.m_intrusiveTable.m_buckets[type % this->script_table.m_intrusiveTable.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != type )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result->id = PhysicsScriptTableData::GetScript(v4->m_data, (IDClass<_tagDataID,32,0> *)&type, mod)->id;
    v5 = result;
  }
  else
  {
LABEL_4:
    v5 = result;
    result->id = stru_8444D0.id;
  }
  return v5;
}

//----- (00521EB0) --------------------------------------------------------  // acclient.c:336959
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,PhysicsScriptTableData *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,PhysicsScriptTableData *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7C7C58: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>::vftable[2])(void *, char);

//----- (00521F40) --------------------------------------------------------  // acclient.c:336992
HashTable<unsigned long,PhysicsScriptTableData *,0> *__thiscall HashTable<unsigned long,PhysicsScriptTableData *,0>::scalar_deleting_destructor(HashTable<unsigned long,PhysicsScriptTableData *,0> *this, unsigned int a2)
{
  HashTable<unsigned long,PhysicsScriptTableData *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,PhysicsScriptTableData *,0>Vtbl *)&HashTable<unsigned long,PhysicsScriptTableData *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>::vftable;
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
// 7C7C58: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>::vftable[2])(void *, char);
// 7C7C5C: using guessed type int (__thiscall *HashTable<unsigned long,PhysicsScriptTableData *,0>::vftable)(void *, char);

//----- (00521FA0) --------------------------------------------------------  // acclient.c:337018
void __thiscall PhysicsScriptTable::PhysicsScriptTable(PhysicsScriptTable *this)
{
  PhysicsScriptTable *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_8444D0);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (InterfaceVtbl *)&PhysicsScriptTable::vftable;
  v1->vfptr = (PackObjVtbl *)&PhysicsScriptTable::vftable;
  v1->script_table.vfptr = (HashTable<unsigned long,PhysicsScriptTableData *,0>Vtbl *)&HashTable<unsigned long,PhysicsScriptTableData *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>(
    &v1->script_table.m_intrusiveTable,
    4u);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C7C5C: using guessed type int (__thiscall *HashTable<unsigned long,PhysicsScriptTableData *,0>::vftable)(void *, char);
// 7C7C60: using guessed type void *PhysicsScriptTable::vftable;
// 7C7C78: using guessed type __int32 (__stdcall *PhysicsScriptTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00521FE0) --------------------------------------------------------  // acclient.c:337038
signed int PhysicsScriptTable::GetDBOType()
{
  return 44;
}

//----- (00521FF0) --------------------------------------------------------  // acclient.c:337044
PhysicsScriptTable *__thiscall PhysicsScriptTable::vector_deleting_destructor(PhysicsScriptTable *this, unsigned int a2)
{
  return PhysicsScriptTable::vector_deleting_destructor((PhysicsScriptTable *)((char *)this - 48), a2);
}

//----- (00522000) --------------------------------------------------------  // acclient.c:337050
void __thiscall PhysicsScriptTable::Destroy(PhysicsScriptTable *this)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v1; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v2; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // edx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // edi@4
  void *v6; // ebp@4
  HashTableData<unsigned long,HeritageGroup_CG> **v7; // ecx@4
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // eax@8
  HashTableData<unsigned long,HeritageGroup_CG> *v9; // edx@9
  PhysicsScriptTableData *data; // [sp+8h] [bp-1Ch]@4
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *iter; // [sp+Ch] [bp-18h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+18h] [bp-Ch]@1

  v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->script_table.m_intrusiveTable,
         &result);
  v2 = v1->m_currElement;
  v3 = v1->m_currHashTable;
  v4 = v1->m_currBucket;
  iter = v1->m_currHashTable;
  if ( v2 )
  {
    while ( 1 )
    {
      v5 = v2->m_hashNext;
      data = (PhysicsScriptTableData *)v2->m_data.vfptr;
      v6 = v2;
      v7 = v4;
      if ( !v5 )
      {
        while ( 1 )
        {
          ++v7;
          if ( v7 == &v3->m_buckets[v3->m_numBuckets] )
            break;
          if ( *v7 )
          {
            v5 = *v7;
            break;
          }
        }
      }
      v8 = *v4;
      if ( *v4 == v2 )
        goto LABEL_22;
      do
      {
        v9 = v8;
        v8 = v8->m_hashNext;
      }
      while ( v8 != v2 );
      if ( v9 )
        v9->m_hashNext = v8->m_hashNext;
      else
LABEL_22:
        *v4 = v8->m_hashNext;
      --iter->m_numElements;
      v2 = v5;
      v4 = v7;
      if ( v6 )
        operator delete(v6);
      if ( data )
      {
        if ( data->script_array.m_data )
          operator delete[](&data->script_array.m_data[-1].script_id);
        operator delete(data);
      }
      if ( !v5 )
        break;
      v3 = iter;
    }
  }
}

//----- (005220E0) --------------------------------------------------------  // acclient.c:337127
int __thiscall PhysicsScriptTable::UnPack(PhysicsScriptTable *this, void **addr, unsigned int size)
{
  PhysicsScriptTable *v3; // ebx@1
  void **v4; // ebp@1
  void **v5; // ecx@1
  int v6; // edi@3
  void *v7; // esi@3
  void *v8; // eax@6
  void *v9; // esi@7
  int v10; // ecx@9
  int v11; // eax@9
  void **addra; // [sp+Ch] [bp+4h]@2

  v3 = this;
  ((void (__thiscall *)(HashTableData<unsigned long,PhysicsScriptTableData *> **))this[-1].script_table.m_intrusiveTable.m_aInplaceBuckets[16][5].m_hashKey)(&this[-1].script_table.m_intrusiveTable.m_aInplaceBuckets[16]);
  v4 = addr;
  v5 = *(void ***)*addr;
  *addr = (char *)*addr + 4;
  if ( (signed int)v5 > 0 )
  {
    addra = v5;
    do
    {
      v6 = *(_DWORD *)*v4;
      *v4 = (char *)*v4 + 4;
      v7 = operator new(0xCu);
      if ( v7 )
      {
        *(_DWORD *)v7 = 0;
        *((_DWORD *)v7 + 1) = 0;
        *((_DWORD *)v7 + 2) = 0;
        AC1Legacy::SmartArray<ScriptAndModData>::grow((AC1Legacy::SmartArray<ScriptAndModData> *)v7, 4u);
      }
      else
      {
        v7 = 0;
      }
      PhysicsScriptTableData::UnPack((PhysicsScriptTableData *)v7, v4, size);
      v8 = operator new(0xCu);
      if ( v8 )
      {
        *((_DWORD *)v8 + 2) = v7;
        *(_DWORD *)v8 = v6;
        *((_DWORD *)v8 + 1) = 0;
        v9 = v8;
      }
      else
      {
        v9 = 0;
      }
      v10 = (int)((char *)v3->script_table.m_intrusiveTable.m_aInplaceBuckets[11]
                + 4 * (*(_DWORD *)v9 % (unsigned int)v3->script_table.m_intrusiveTable.m_aInplaceBuckets[13]));
      v11 = *(_DWORD *)v10;
      if ( !*(_DWORD *)v10 )
        goto LABEL_14;
      while ( *(_DWORD *)v11 != *(_DWORD *)v9 )
      {
        v11 = *(_DWORD *)(v11 + 4);
        if ( !v11 )
          goto LABEL_14;
      }
      if ( v11 )
      {
        operator delete(v9);
      }
      else
      {
LABEL_14:
        *((_DWORD *)v9 + 1) = *(_DWORD *)v10;
        *(_DWORD *)v10 = v9;
        if ( (HashTableData<unsigned long,PhysicsScriptTableData *> *)v10 < v3->script_table.m_intrusiveTable.m_aInplaceBuckets[12] )
          v3->script_table.m_intrusiveTable.m_aInplaceBuckets[12] = (HashTableData<unsigned long,PhysicsScriptTableData *> *)v10;
        ++v3->script_table.m_intrusiveTable.m_aInplaceBuckets[14];
      }
      addra = (void **)((char *)addra - 1);
    }
    while ( addra );
  }
  return 1;
}

//----- (005221E0) --------------------------------------------------------  // acclient.c:337209
void __thiscall PhysicsScriptTable::~PhysicsScriptTable(PhysicsScriptTable *this)
{
  PhysicsScriptTable *v1; // edi@1
  void *v2; // eax@1

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&PhysicsScriptTable::vftable;
  this->vfptr = (PackObjVtbl *)&PhysicsScriptTable::vftable;
  PhysicsScriptTable::Destroy(this);
  v1->script_table.vfptr = (HashTable<unsigned long,PhysicsScriptTableData *,0>Vtbl *)&HashTable<unsigned long,PhysicsScriptTableData *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->script_table.m_intrusiveTable);
  v2 = v1->script_table.m_intrusiveTable.m_buckets;
  v1->script_table.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>::vftable;
  if ( v2 != v1->script_table.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v2);
  v1->script_table.m_intrusiveTable.m_buckets = 0;
  v1->script_table.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->script_table.m_intrusiveTable.m_numBuckets = 0;
  v1->script_table.m_intrusiveTable.m_numElements = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C7C58: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>::vftable[2])(void *, char);
// 7C7C5C: using guessed type int (__thiscall *HashTable<unsigned long,PhysicsScriptTableData *,0>::vftable)(void *, char);
// 7C7C60: using guessed type void *PhysicsScriptTable::vftable;
// 7C7C78: using guessed type __int32 (__stdcall *PhysicsScriptTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00522240) --------------------------------------------------------  // acclient.c:337238
PhysicsScriptTable *__thiscall PhysicsScriptTable::vector_deleting_destructor(PhysicsScriptTable *this, unsigned int a2)
{
  PhysicsScriptTable *v2; // esi@1

  v2 = this;
  PhysicsScriptTable::~PhysicsScriptTable(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006FD640) --------------------------------------------------------  // acclient.c:785656
int sub_6FD640()
{
  return atexit(nullsub_1130);
}

