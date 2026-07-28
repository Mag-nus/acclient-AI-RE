/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GeneratorRegistry
   Object     : AC\acgenerator\GeneratorRegistry.obj
   Functions  : 12
   Addresses  : 00497F90 - 00710310 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00497F90) --------------------------------------------------------  // acclient.c:209876
void __thiscall PackableHashTable<unsigned long,CContractTracker>::EmptyContents(PackableHashTable<unsigned long,GeneratorRegistryNode> *this)
{
  PackableHashTable<unsigned long,GeneratorRegistryNode> *v1; // edi@1
  unsigned int v2; // ebx@2
  PackableHashData<unsigned long,GeneratorRegistryNode> *v3; // eax@3
  PackableHashData<unsigned long,GeneratorRegistryNode> *v4; // esi@4

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
            v3->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
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
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00498380) --------------------------------------------------------  // acclient.c:210139
signed int __thiscall PackableHashTable<unsigned long,GeneratorRegistryNode>::Pack(PackableHashTable<unsigned long,GeneratorRegistryNode> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,GeneratorRegistryNode> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<unsigned long,GeneratorRegistryNode> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<unsigned long,CContractTracker>::pack_size(this);
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

//----- (005D03C0) --------------------------------------------------------  // acclient.c:508092
int __thiscall PackableHashTable<unsigned long,GeneratorRegistryNode>::add(PackableHashTable<unsigned long,GeneratorRegistryNode> *this, const unsigned int *key, GeneratorRegistryNode *data)
{
  PackableHashTable<unsigned long,GeneratorRegistryNode> *v3; // edi@1
  unsigned int v4; // esi@1
  PackableHashData<unsigned long,GeneratorRegistryNode> **v5; // ebx@2
  PackableHashData<unsigned long,GeneratorRegistryNode> *v6; // edx@3
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
  if ( v6 == (PackableHashData<unsigned long,GeneratorRegistryNode> *)-8 )
  {
LABEL_8:
    v7 = operator new(0x38u);
    if ( v7 )
    {
      v8 = v3->_table_size;
      *(_DWORD *)v7 = *key;
      GeneratorRegistryNode::GeneratorRegistryNode((GeneratorRegistryNode *)((char *)v7 + 8), data);
      *((_DWORD *)v7 + 12) = 0;
      v9 = *key % v8;
      *((_DWORD *)v7 + 13) = v9;
      *((_DWORD *)v7 + 12) = v3->_buckets[v9];
      v3->_buckets[v9] = (PackableHashData<unsigned long,GeneratorRegistryNode> *)v7;
      ++v3->_currNum;
      return 1;
    }
  }
  return 0;
}

//----- (005D0460) --------------------------------------------------------  // acclient.c:508140
signed int __thiscall PackableHashTable<unsigned long,CContractTracker>::pack_size(PackableHashTable<unsigned long,GeneratorRegistryNode> *this)
{
  PackableHashTable<unsigned long,GeneratorRegistryNode> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<unsigned long,GeneratorRegistryNode> *i; // esi@2
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

//----- (005D04C0) --------------------------------------------------------  // acclient.c:508172
int __thiscall PackableHashTable<unsigned long,GeneratorRegistryNode>::UnPack(PackableHashTable<unsigned long,GeneratorRegistryNode> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<unsigned long,GeneratorRegistryNode> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  int v10; // ebx@5
  unsigned int v11; // ebp@5
  void *v12; // eax@13
  PackObjVtbl *v13; // edx@13
  void *start_addr; // [sp+8h] [bp-30h]@3
  unsigned int blob_size; // [sp+Ch] [bp-2Ch]@3
  GeneratorRegistryNode tempData; // [sp+10h] [bp-28h]@11

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,CContractTracker>::EmptyContents(this);
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
  if ( v8 > 0x10000
    || v9 > 0x10000
    || !PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
    return 0;
  GeneratorRegistryNode::GeneratorRegistryNode(&tempData);
  size = 0;
  if ( v11 )
  {
    while ( (unsigned int)v10 >= 4 )
    {
      v12 = *v6;
      v13 = tempData.vfptr;
      addr = *(void ***)*v6;
      *v6 = (char *)v12 + 4;
      if ( !((int (__thiscall *)(GeneratorRegistryNode *, void **, int))v13->UnPack)(&tempData, v6, v10)
        || !PackableHashTable<unsigned long,GeneratorRegistryNode>::add(v4, (const unsigned int *)&addr, &tempData)
        && !v4->m_fThrowawayDuplicateKeysOnUnPack )
        break;
      ++size;
      if ( size >= v11 )
        return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
    }
    return 0;
  }
  return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
}

//----- (005D05E0) --------------------------------------------------------  // acclient.c:508239
PackableHashTable<unsigned long,GeneratorRegistryNode> *__thiscall PackableHashTable<unsigned long,GeneratorRegistryNode>::scalar_deleting_destructor(PackableHashTable<unsigned long,GeneratorRegistryNode> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,GeneratorRegistryNode> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,GeneratorRegistryNode>::vftable;
  PackableHashTable<unsigned long,CContractTracker>::EmptyContents(this);
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
// 7E8720: using guessed type int (__thiscall *PackableHashTable<unsigned long,GeneratorRegistryNode>::vftable)(void *, char);

//----- (005D0630) --------------------------------------------------------  // acclient.c:508261
void __thiscall GeneratorRegistry::GeneratorRegistry(GeneratorRegistry *this)
{
  GeneratorRegistry *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  v2 = (char *)&this->_registry;
  v1->vfptr = (PackObjVtbl *)&GeneratorRegistry::vftable;
  *(_DWORD *)v2 = &PackableHashTable<unsigned long,GeneratorRegistryNode>::vftable;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 32;
  *((_DWORD *)v2 + 4) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
}
// 7E8720: using guessed type int (__thiscall *PackableHashTable<unsigned long,GeneratorRegistryNode>::vftable)(void *, char);
// 7E8734: using guessed type int (__thiscall *GeneratorRegistry::vftable)(void *, char);

//----- (005D0660) --------------------------------------------------------  // acclient.c:508280
GeneratorRegistry *__thiscall GeneratorRegistry::vector_deleting_destructor(GeneratorRegistry *this, unsigned int a2)
{
  GeneratorRegistry *v2; // edi@1
  char *v3; // esi@1

  v2 = this;
  v3 = (char *)&this->_registry;
  this->vfptr = (PackObjVtbl *)&GeneratorRegistry::vftable;
  this->_registry.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,GeneratorRegistryNode>::vftable;
  PackableHashTable<unsigned long,CContractTracker>::EmptyContents(&this->_registry);
  if ( *((_DWORD *)v3 + 2) )
  {
    operator delete[](*((void **)v3 + 2));
    *((_DWORD *)v3 + 2) = 0;
  }
  *((_DWORD *)v3 + 3) = 0;
  *(_DWORD *)v3 = &PackObj::vftable;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E8720: using guessed type int (__thiscall *PackableHashTable<unsigned long,GeneratorRegistryNode>::vftable)(void *, char);
// 7E8734: using guessed type int (__thiscall *GeneratorRegistry::vftable)(void *, char);

//----- (007102B0) --------------------------------------------------------  // acclient.c:803447
void sub_7102B0()
{
  flt_8EFF48 = 1000.0 + 1.0;
}

//----- (007102D0) --------------------------------------------------------  // acclient.c:803453
void sub_7102D0()
{
  flt_8EFF4C = 24.0 * 8.0;
}

//----- (007102F0) --------------------------------------------------------  // acclient.c:803459
void sub_7102F0()
{
  flt_8EFF50 = 24.0 * 0.5;
}

//----- (00710310) --------------------------------------------------------  // acclient.c:803465
int sub_710310()
{
  return atexit(nullsub_1839);
}

