/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CKeyMap
   Object     : ENGINE\cinputmap_base\CKeyMap.obj
   Functions  : 872
   Addresses  : 0068C6C0 - 007844C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0068C6C0) --------------------------------------------------------  // acclient.c:675276
void __thiscall PFileNode::SetNameAsGuid(PFileNode *this, Turbine_GUID i_name)
{
  PFileNode *v2; // esi@1
  IFileNodeName *v3; // ecx@1
  void *v4; // eax@3

  v2 = this;
  v3 = this->m_pcName;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v2->m_pcName = 0;
  v4 = operator new(0x14u);
  if ( v4 )
  {
    *(_OWORD *)((char *)v4 + 4) = i_name;
    *(_DWORD *)v4 = &FileNodeName_Guid::vftable;
    v2->m_pcName = (IFileNodeName *)v4;
  }
  else
  {
    v2->m_pcName = 0;
  }
}
// 7FD8D8: using guessed type int (__thiscall *FileNodeName_Guid::vftable)(void *, char);

//----- (0068C720) --------------------------------------------------------  // acclient.c:675302
PFileNode *__thiscall PFileNode::MakeSubNodeAsGuid(PFileNode *this, Turbine_GUID i_name)
{
  PFileNode *result; // eax@1
  PFileNode *v3; // esi@1
  Turbine_GUID v4; // ST00_16@2

  result = (PFileNode *)((int (*)(void))this->vfptr[1].__vecDelDtor)();
  v3 = result;
  if ( result )
  {
    *(_QWORD *)&v4.m_data1 = *(_QWORD *)&i_name;
    *(_QWORD *)&v4.m_data4[0] = *(_QWORD *)&i_name.m_data4[0];
    PFileNode::SetNameAsGuid(result, v4);
    result = v3;
  }
  return result;
}

//----- (0068C760) --------------------------------------------------------  // acclient.c:675321
void __cdecl Serializer::SerializePrimitive(Turbine_GUID *io_object, Archive *io_archive)
{
  unsigned int v2; // eax@1

  Archive::CheckAlignment(io_archive, 0x10u);
  v2 = Archive::GetBytes(io_archive, 0x10u);
  if ( v2 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_OWORD *)v2 = *io_object;
    }
    else
    {
      io_object->m_data1 = *(_DWORD *)v2;
      *(_DWORD *)&io_object->m_data2 = *(_DWORD *)(v2 + 4);
      *(_DWORD *)&io_object->m_data4[0] = *(_DWORD *)(v2 + 8);
      *(_DWORD *)&io_object->m_data4[4] = *(_DWORD *)(v2 + 12);
    }
  }
}

//----- (0068C7C0) --------------------------------------------------------  // acclient.c:675344
unsigned int __cdecl BitUtils::ReverseBits(unsigned int i_bits)
{
  unsigned int v1; // ecx@1
  signed __int64 i; // rax@1

  v1 = i_bits;
  for ( i = 0x8000000000000000i64; v1; HIDWORD(i) >>= 1 )
  {
    if ( v1 & 1 )
      LODWORD(i) = HIDWORD(i) | i;
    v1 >>= 1;
  }
  return i;
}

//----- (0068C7E0) --------------------------------------------------------  // acclient.c:675360
void __thiscall SmartArray<DeviceKeyMapEntry,1>::Reset(SmartArray<DeviceKeyMapEntry,1> *this)
{
  SmartArray<DeviceKeyMapEntry,1> *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@4
  int v5; // ecx@4
  int v6; // eax@5
  int v7; // edx@5
  void *v8; // edi@6
  char v9; // [sp+8h] [bp-14h]@6

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    v5 = v4;
    if ( v4 >= 0 )
    {
      v6 = v4;
      v7 = v5 + 1;
      do
      {
        v8 = &v1->m_data[v6];
        --v6;
        --v7;
        qmemcpy(v8, &v9, 0x14u);
      }
      while ( v7 );
    }
  }
}

//----- (0068C850) --------------------------------------------------------  // acclient.c:675403
int __thiscall PFileNode::MakeSubNodeAsHex(PFileNode *this, unsigned int i_name)
{
  int result; // eax@1
  PFileNode *v3; // esi@1
  IFileNodeName *v4; // ecx@2
  void *v5; // eax@4

  result = ((int (*)(void))this->vfptr[1].__vecDelDtor)();
  v3 = (PFileNode *)result;
  if ( result )
  {
    v4 = *(IFileNodeName **)(result + 8);
    if ( v4 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v3->m_pcName = 0;
    v5 = operator new(8u);
    if ( v5 )
    {
      *((_DWORD *)v5 + 1) = i_name;
      *(_DWORD *)v5 = &FileNodeName_Hex::vftable;
      v3->m_pcName = (IFileNodeName *)v5;
      result = (int)v3;
    }
    else
    {
      v3->m_pcName = 0;
      result = (int)v3;
    }
  }
  return result;
}
// 7970EC: using guessed type int (__thiscall *FileNodeName_Hex::vftable)(void *, char);

//----- (0068C8B0) --------------------------------------------------------  // acclient.c:675437
IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *__thiscall IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::scalar_deleting_destructor(IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *v2; // esi@1
  HashList<QualifiedControl,unsigned long,1>::HashListData **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::vftable;
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
// 7FFFE0: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::vftable[3])(void *, char);

//----- (0068C8F0) --------------------------------------------------------  // acclient.c:675458
IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *__thiscall IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::vector_deleting_destructor(IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *v2; // esi@1
  HashList<ControlSpecification,unsigned long,1>::HashListData **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::vftable;
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
// 7FFFE4: using guessed type int (__thiscall *IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::vftable[2])(void *, char);

//----- (0068C930) --------------------------------------------------------  // acclient.c:675479
IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *__thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,CInputMap *,1>::HashListData **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>Vtbl *)&IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::vftable;
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
// 7FFFE8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::vftable)(void *, char);

//----- (0068C970) --------------------------------------------------------  // acclient.c:675500
signed int __thiscall SmartArray<DeviceKeyMapEntry,1>::WhatNum(SmartArray<DeviceKeyMapEntry,1> *this, DeviceKeyMapEntry *i_rData)
{
  unsigned int v2; // esi@1
  signed int result; // eax@1
  char *v4; // ecx@2

  v2 = this->m_num;
  result = 0;
  if ( v2 )
  {
    v4 = this->m_data->guid.m_data4;
    while ( *((_DWORD *)v4 - 2) != i_rData->guid.m_data1
         || *((_DWORD *)v4 - 1) != *(_DWORD *)&i_rData->guid.m_data2
         || *(_DWORD *)v4 != *(_DWORD *)&i_rData->guid.m_data4[0]
         || *((_DWORD *)v4 + 1) != *(_DWORD *)&i_rData->guid.m_data4[4] )
    {
      ++result;
      v4 += 20;
      if ( result >= v2 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    result = -1;
  }
  return result;
}

//----- (0068C9C0) --------------------------------------------------------  // acclient.c:675531
char __thiscall SmartArray<DeviceKeyMapEntry,1>::grow(SmartArray<DeviceKeyMapEntry,1> *this, unsigned int i_nSize)
{
  SmartArray<DeviceKeyMapEntry,1> *v2; // ebx@1
  unsigned int v3; // esi@1
  void *v5; // ebp@5
  int v6; // ecx@7
  int v7; // eax@8
  unsigned int v8; // edx@8
  const void *v9; // esi@9
  void *v10; // edi@9

  v2 = this;
  v3 = i_nSize;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<DeviceKeyMapEntry,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](20 * i_nSize);
    if ( v5 )
    {
      if ( v2->m_data )
      {
        v6 = v2->m_num - 1;
        if ( v6 >= 0 )
        {
          v7 = v6;
          v8 = v2->m_num;
          do
          {
            v9 = &v2->m_data[v7];
            v10 = (char *)v5 + v7 * 20;
            --v7;
            --v8;
            qmemcpy(v10, v9, 0x14u);
          }
          while ( v8 );
          v3 = i_nSize;
        }
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = (DeviceKeyMapEntry *)v5;
      v2->m_sizeAndDeallocate = v3 | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (0068CA70) --------------------------------------------------------  // acclient.c:675586
char __thiscall SmartArray<DeviceKeyMapEntry,1>::SetNElements(SmartArray<DeviceKeyMapEntry,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<DeviceKeyMapEntry,1> *v3; // ebx@1
  unsigned int v4; // eax@3
  char result; // al@5
  unsigned int v6; // edx@7
  const unsigned int v7; // eax@8
  char v8; // [sp+8h] [bp-14h]@9

  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    v6 = i_nSize;
    if ( i_nSize < this->m_num )
    {
      v7 = i_nSize;
      do
      {
        qmemcpy(&this->m_data[v7], &v8, sizeof(this->m_data[v7]));
        ++v6;
        ++v7;
      }
      while ( v6 < this->m_num );
    }
    goto LABEL_10;
  }
  if ( i_bGrowExactly )
    v4 = i_nSize;
  else
    v4 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<DeviceKeyMapEntry,1>::grow(v3, v4);
  if ( result )
  {
LABEL_10:
    v3->m_num = i_nSize;
    result = 1;
  }
  return result;
}

//----- (0068CAF0) --------------------------------------------------------  // acclient.c:675627
char __userpurge PFileNode::GetNameAsGuid@<al>(PFileNode *this@<ecx>, int a2@<edi>, Turbine_GUID *o_name)
{
  PFileNode *v3; // esi@1
  IFileNodeName *v4; // ecx@1
  char v5; // bl@1
  int v6; // esi@3
  void *v8; // eax@4
  void *v9; // edi@5
  IFileNodeName *v10; // ecx@8
  char *v11; // esi@12
  PStringBase<char> oldName; // [sp+Ch] [bp-4h]@1

  oldName.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v3 = this;
  v4 = this->m_pcName;
  v5 = 0;
  if ( v4 )
  {
    if ( ((int (*)(void))v4->vfptr->GetType)() == 14 )
    {
      v6 = (int)&v3->m_pcName[1];
      o_name->m_data1 = *(_DWORD *)v6;
      *(_DWORD *)&o_name->m_data2 = *(_DWORD *)(v6 + 4);
      *(_DWORD *)&o_name->m_data4[0] = *(_DWORD *)(v6 + 8);
      *(_DWORD *)&o_name->m_data4[4] = *(_DWORD *)(v6 + 12);
      return 1;
    }
    ((void (__stdcall *)(PStringBase<char> *, int))v3->m_pcName->vfptr->ToPString)(&oldName, a2);
    v8 = operator new(0x14u);
    if ( v8 )
    {
      *(_DWORD *)v8 = &FileNodeName_Guid::vftable;
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    if ( (unsigned __int8)(*(int (__thiscall **)(void *))(*(_DWORD *)v9 + 16))(v9) )
    {
      o_name->m_data1 = *((_DWORD *)v9 + 1);
      *(_DWORD *)&o_name->m_data2 = *((_DWORD *)v9 + 2);
      *(_DWORD *)&o_name->m_data4[0] = *((_DWORD *)v9 + 3);
      *(_DWORD *)&o_name->m_data4[4] = *((_DWORD *)v9 + 4);
      v10 = v3->m_pcName;
      if ( v10 )
        ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
      v3->m_pcName = (IFileNodeName *)v9;
      v5 = 1;
    }
    else
    {
      (**(void (__thiscall ***)(void *, signed int))v9)(v9, 1);
    }
    v11 = &oldName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&oldName.m_charbuffer[-1]) )
    {
      if ( v11 )
        (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
    }
  }
  return v5;
}
// 7FD8D8: using guessed type int (__thiscall *FileNodeName_Guid::vftable)(void *, char);

//----- (0068CBD0) --------------------------------------------------------  // acclient.c:675693
IntrusiveHashIterator<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *__thiscall IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::find_internal(IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *this, IntrusiveHashIterator<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *result, QualifiedControl *_key)
{
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *v3; // edi@1
  unsigned int v4; // edx@1
  HashList<QualifiedControl,unsigned long,1>::HashListData **v5; // eax@1
  HashList<QualifiedControl,unsigned long,1>::HashListData *v6; // esi@1
  HashList<QualifiedControl,unsigned long,1>::HashListData **i; // ebx@1
  IntrusiveHashIterator<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *v8; // eax@4

  v3 = this;
  v4 = _key->m_key.m_dwKey % this->m_numBuckets;
  v5 = this->m_buckets;
  v6 = v5[v4];
  for ( i = &v5[v4]; v6; v6 = v6->m_hashNext )
  {
    if ( QualifiedControl::operator==(&v6->m_hashKey, _key) )
      break;
  }
  v8 = result;
  result->m_currHashTable = v3;
  result->m_currElement = v6;
  result->m_currBucket = i;
  return v8;
}

//----- (0068CC20) --------------------------------------------------------  // acclient.c:675719
char __thiscall SmartArray<DeviceKeyMapEntry,1>::AddToEnd(SmartArray<DeviceKeyMapEntry,1> *this, DeviceKeyMapEntry *i_rData)
{
  SmartArray<DeviceKeyMapEntry,1> *v2; // ebx@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<DeviceKeyMapEntry,1>::grow(v2, v4)) != 0) )
  {
    qmemcpy(&v2->m_data[v2->m_num++], i_rData, sizeof(v2->m_data[v2->m_num++]));
    result = 1;
  }
  return result;
}

//----- (0068CC80) --------------------------------------------------------  // acclient.c:675739
char __cdecl FileNodeUtils::SetNameAsEnum(PFileNode *_node, unsigned int _mapID, unsigned int _value)
{
  char v3; // bl@1
  PStringBase<char> v4; // esi@2
  volatile LONG *v5; // edi@2
  int v6; // esi@2
  char *v7; // esi@6
  PStringBase<char> name; // [sp+10h] [bp-4h]@1

  name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v3 = 0;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( EnumMapper::GetString(_mapID, _value, &name) )
  {
    v4.m_charbuffer = name.m_charbuffer;
    v5 = (volatile LONG *)&name.m_charbuffer[-1];
    InterlockedIncrement((volatile LONG *)&name.m_charbuffer[-1]);
    InterlockedIncrement(v5);
    PFileNode::SetNameAsPString(_node, v4);
    v6 = (int)&v4.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v3 = 1;
  }
  v7 = &name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&name.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  return v3;
}

//----- (0068CD20) --------------------------------------------------------  // acclient.c:675770
PFileNode *__cdecl FileNodeUtils::MakeSubNodeAsEnum(PFileNode *_node, unsigned int _mapID, unsigned int _value)
{
  PFileNode *v3; // eax@1
  PFileNode *v4; // esi@1
  PFileNode *result; // eax@3

  v3 = (PFileNode *)((int (__thiscall *)(PFileNode *))_node->vfptr[1].__vecDelDtor)(_node);
  v4 = v3;
  if ( !v3 || FileNodeUtils::SetNameAsEnum(v3, _mapID, _value) )
  {
    result = v4;
  }
  else
  {
    PFileNode::RemoveSubNodePtr(_node, v4);
    result = 0;
  }
  return result;
}

//----- (0068CD60) --------------------------------------------------------  // acclient.c:675791
char __thiscall CInputMap::VerifyActivationAndToggleType(CInputMap *this, QualifiedControl *i_key, unsigned int i_idAction, PFileNode *i_pCurLine)
{
  CInputMap *v4; // edi@1
  char v5; // bl@1
  int v6; // esi@1
  unsigned int v7; // eax@2
  unsigned int v8; // edi@2
  unsigned int v9; // eax@2
  QualifiedControl *v10; // ebp@4
  PStringBase<char> v12; // [sp-10h] [bp-24h]@5
  unsigned int v13; // [sp-Ch] [bp-20h]@5
  QualifiedControl *v14; // [sp-8h] [bp-1Ch]@5
  PSRefBufferCharData<char> *v15; // [sp-4h] [bp-18h]@5
  PStringBase<char> strToggleType; // [sp+10h] [bp-4h]@5

  v4 = this;
  v5 = 1;
  v6 = DBObj::GetByEnum(1, 8, 0x27u);
  if ( v6 )
  {
    v7 = v4->m_eInputMapID;
    v8 = i_idAction;
    v9 = ActionMap::GetToggleType((ActionMap *)v6, i_idAction, v7);
    if ( v9 >= 4 && v9 <= 5 )
    {
      v10 = i_key;
      if ( !(i_key->m_activation & 0xA9) )
      {
        i_key = (QualifiedControl *)PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        PStringBase<char>::PStringBase<char>(&strToggleType, "momentary, etc.");
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&i_idAction, "tap, dblclick, etc");
        EnumMapper::GetString(0x19u, v8, (PStringBase<char> *)&i_key);
        ControlActivationTypeToString(v10->m_activation, (PStringBase<char> *)&i_idAction);
        v15 = strToggleType.m_charbuffer;
        v14 = i_key;
        v13 = i_idAction;
        v12.m_charbuffer = strToggleType.m_charbuffer;
        PStringBase<char>::PStringBase<char>(
          &v12,
          "Cannot use that activation type (%s) with '%s' because of its toggle type (%s)");
        PFileNode::ReportError(v8, i_pCurLine, v12);
        v5 = 0;
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_idAction);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strToggleType);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_key);
      }
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
  }
  return v5;
}

//----- (0068CE60) --------------------------------------------------------  // acclient.c:675845
char __userpurge CMasterInputMap::ReadGuidFromFileNode@<al>(CMasterInputMap *this@<ecx>, int a2@<edi>, PFileNode *i_pNode, Turbine_GUID *o_guid)
{
  PSRefBufferCharData<char> *v4; // ebp@2
  int v5; // eax@2
  char *v6; // esi@2
  bool v7; // bl@2
  int v9; // eax@10
  char *v10; // esi@10
  bool v11; // bl@10
  int v12; // ebp@14
  int v13; // eax@18
  char *v14; // esi@18
  bool v15; // bl@18
  PSRefBufferCharData<char> *v16; // ecx@24
  PStringBase<char> v17; // [sp-8h] [bp-20h]@25
  PSRefBufferCharData<char> *v18; // [sp-4h] [bp-1Ch]@25
  PStringBase<char> strName; // [sp+10h] [bp-8h]@2
  PStringBase<char> v20; // [sp+14h] [bp-4h]@2

  if ( !i_pNode )
    return 0;
  strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PFileNode::GetNameAsPString(i_pNode, a2, &strName);
  PStringBase<char>::PStringBase<char>(&v20, "GUID_SysMouse");
  v4 = strName.m_charbuffer;
  v5 = __stricmp(strName.m_charbuffer->m_data, v20.m_charbuffer->m_data);
  v6 = &v20.m_charbuffer[-2].m_data[12];
  v7 = v5 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v20.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  if ( v7 )
  {
    *o_guid = (Turbine_GUID)GUID_SysMouse;
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v4 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&v4[-2].m_data[12])(&v4[-2].m_data[12], 1);
    return 1;
  }
  PStringBase<char>::PStringBase<char>(&v20, "GUID_SysKeyboard");
  v9 = __stricmp(v4->m_data, v20.m_charbuffer->m_data);
  v10 = &v20.m_charbuffer[-2].m_data[12];
  v11 = v9 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v20.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  if ( !v11 )
  {
    PStringBase<char>::PStringBase<char>(&v20, "GUID_Virtual");
    v13 = __stricmp(v4->m_data, v20.m_charbuffer->m_data);
    v14 = &v20.m_charbuffer[-2].m_data[12];
    v15 = v13 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v20.m_charbuffer[-1]) && v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
    if ( v15 )
    {
      *o_guid = (Turbine_GUID)GUID_Virtual_0;
LABEL_23:
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strName);
      return 1;
    }
    if ( PFileNode::GetNameAsGuid(i_pNode, (int)InterlockedDecrement, o_guid) )
      goto LABEL_23;
    v18 = v4;
    v17.m_charbuffer = v16;
    PStringBase<char>::PStringBase<char>(&v17, "ERROR - invalid GUID \"%s\"\n");
    PFileNode::ReportError((int)InterlockedDecrement, i_pNode, v17);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strName);
    return 0;
  }
  *o_guid = (Turbine_GUID)GUID_SysKeyboard;
  v12 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v12 + 4)) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  return 1;
}

//----- (0068D080) --------------------------------------------------------  // acclient.c:675921
bool __stdcall CMasterInputMap::WriteGuidToFileNode(Turbine_GUID *i_guid, PFileNode *io_pNode)
{
  signed int v3; // ecx@1
  Turbine_GUID *v4; // edi@1
  GUID *v5; // esi@1
  bool v6; // zf@1
  bool result; // al@5
  signed int v8; // ecx@6
  Turbine_GUID *v9; // edi@6
  GUID *v10; // esi@6
  bool v11; // zf@6
  signed int v12; // ecx@11
  Turbine_GUID *v13; // edi@11
  GUID *v14; // esi@11
  bool v15; // zf@11
  Turbine_GUID v16; // ST00_16@16
  PStringBase<char> v17; // [sp-4h] [bp-Ch]@5

  v3 = 4;
  v4 = i_guid;
  v5 = &GUID_SysKeyboard;
  v6 = 1;
  do
  {
    if ( !v3 )
      break;
    v6 = v5->Data1 == v4->m_data1;
    v5 = (GUID *)((char *)v5 + 4);
    v4 = (Turbine_GUID *)((char *)v4 + 4);
    --v3;
  }
  while ( v6 );
  if ( v6 )
  {
    v17.m_charbuffer = (PSRefBufferCharData<char> *)v3;
    PStringBase<char>::PStringBase<char>(&v17, "GUID_SysKeyboard");
    result = PFileNode::MakeSubNodeAsPString(io_pNode, v17) != 0;
  }
  else
  {
    v8 = 4;
    v9 = i_guid;
    v10 = &GUID_SysMouse;
    v11 = 1;
    do
    {
      if ( !v8 )
        break;
      v11 = v10->Data1 == v9->m_data1;
      v10 = (GUID *)((char *)v10 + 4);
      v9 = (Turbine_GUID *)((char *)v9 + 4);
      --v8;
    }
    while ( v11 );
    if ( v11 )
    {
      v17.m_charbuffer = (PSRefBufferCharData<char> *)v8;
      PStringBase<char>::PStringBase<char>(&v17, "GUID_SysMouse");
      result = PFileNode::MakeSubNodeAsPString(io_pNode, v17) != 0;
    }
    else
    {
      v12 = 4;
      v13 = i_guid;
      v14 = &GUID_Virtual_0;
      v15 = 1;
      do
      {
        if ( !v12 )
          break;
        v15 = v14->Data1 == v13->m_data1;
        v14 = (GUID *)((char *)v14 + 4);
        v13 = (Turbine_GUID *)((char *)v13 + 4);
        --v12;
      }
      while ( v15 );
      if ( v15 )
      {
        v17.m_charbuffer = (PSRefBufferCharData<char> *)v12;
        PStringBase<char>::PStringBase<char>(&v17, "GUID_Virtual");
        result = PFileNode::MakeSubNodeAsPString(io_pNode, v17) != 0;
      }
      else
      {
        *(_QWORD *)&v16.m_data1 = *(_QWORD *)&i_guid->m_data1;
        *(_DWORD *)&v16.m_data4[0] = *(_DWORD *)&i_guid->m_data4[0];
        v17.m_charbuffer = *(PSRefBufferCharData<char> **)&i_guid->m_data4[4];
        result = PFileNode::MakeSubNodeAsGuid(io_pNode, v16) != 0;
      }
    }
  }
  return result;
}

//----- (0068D150) --------------------------------------------------------  // acclient.c:676016
int __thiscall CMasterInputMap::AddDeviceEntry(CMasterInputMap *this, DeviceKeyMapEntry *device)
{
  CMasterInputMap *v2; // esi@1
  SmartArray<DeviceKeyMapEntry,1> *v3; // edi@1
  int result; // eax@1
  int v5; // esi@2

  v2 = this;
  v3 = &this->m_rgDevices;
  result = SmartArray<DeviceKeyMapEntry,1>::WhatNum(&this->m_rgDevices, device);
  if ( result == -1 )
  {
    v5 = v2->m_rgDevices.m_num;
    SmartArray<DeviceKeyMapEntry,1>::AddToEnd(v3, device);
    result = v5;
  }
  return result;
}

//----- (0068D180) --------------------------------------------------------  // acclient.c:676036
void __thiscall SmartArray<DeviceKeyMapEntry,1>::Serialize(SmartArray<DeviceKeyMapEntry,1> *this, Archive *io_rcArchive)
{
  Archive *v2; // edi@1
  SmartArray<DeviceKeyMapEntry,1> *v3; // ebp@1
  unsigned int v4; // esi@1
  unsigned int v5; // eax@1
  unsigned __int8 v6; // bl@11
  int v7; // esi@11
  unsigned int v8; // eax@11
  int v9; // esi@17
  unsigned int v10; // eax@17
  bool v11; // cf@21
  unsigned int iq; // [sp+10h] [bp-4h]@9
  Archive *io_rcArchivea; // [sp+18h] [bp+4h]@10

  v2 = io_rcArchive;
  v3 = this;
  v4 = this->m_num;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v5 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v5 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v5 = v4;
    else
      v4 = *(_DWORD *)v5;
  }
  if ( ~LOBYTE(io_rcArchive->m_flags) & 1 )
  {
    if ( v4 > Archive::GetSizeLeft(io_rcArchive) )
    {
      Archive::RaiseError(io_rcArchive);
      return;
    }
    v3->m_num = 0;
    SmartArray<DeviceKeyMapEntry,1>::SetNElements(v3, v4, 1);
  }
  iq = 0;
  if ( v3->m_num )
  {
    io_rcArchivea = 0;
    do
    {
      v6 = *((_BYTE *)&v3->m_data->dt + (unsigned int)io_rcArchivea);
      v7 = (int)((char *)io_rcArchivea + (unsigned int)v3->m_data);
      Archive::CheckAlignment(v2, 1u);
      v8 = Archive::GetBytes(v2, 1u);
      if ( v8 )
      {
        if ( v2->m_flags & 1 )
          *(_BYTE *)v8 = v6;
        else
          v6 = *(_BYTE *)v8;
      }
      if ( !(v2->m_flags & 5) )
        *(_DWORD *)v7 = v6;
      v9 = v7 + 4;
      Archive::CheckAlignment(v2, 0x10u);
      v10 = Archive::GetBytes(v2, 0x10u);
      if ( v10 )
      {
        if ( v2->m_flags & 1 )
        {
          *(_DWORD *)v10 = *(_DWORD *)v9;
          *(_DWORD *)(v10 + 4) = *(_DWORD *)(v9 + 4);
          *(_DWORD *)(v10 + 8) = *(_DWORD *)(v9 + 8);
          *(_DWORD *)(v10 + 12) = *(_DWORD *)(v9 + 12);
        }
        else
        {
          *(_DWORD *)v9 = *(_DWORD *)v10;
          *(_DWORD *)(v9 + 4) = *(_DWORD *)(v10 + 4);
          *(_DWORD *)(v9 + 8) = *(_DWORD *)(v10 + 8);
          *(_DWORD *)(v9 + 12) = *(_DWORD *)(v10 + 12);
        }
      }
      v11 = iq++ + 1 < v3->m_num;
      io_rcArchivea = (Archive *)((char *)io_rcArchivea + 20);
    }
    while ( v11 );
  }
}

//----- (0068D2A0) --------------------------------------------------------  // acclient.c:676120
bool __thiscall CInputMap::ToFileNode(CInputMap *this, PFileNode *i_pNode)
{
  PFileNode *v2; // ebx@1
  unsigned int v3; // edx@2
  char *v4; // ecx@2
  int v5; // eax@2
  int v6; // eax@3
  int v7; // ebp@6
  unsigned int v8; // ecx@7
  unsigned int v9; // edx@7
  unsigned int v10; // edi@7
  ReferenceCountTemplate<1048576,0>Vtbl *v11; // eax@7
  PFileNode *v12; // eax@7
  PSRefBufferCharData<char> *v13; // ecx@7
  PFileNode *v14; // esi@7
  PFileNode *v15; // eax@11
  PSRefBufferCharData<char> *v16; // ecx@11
  bool v17; // bl@13
  unsigned int v18; // eax@15
  char *v19; // esi@18
  int v20; // edx@20
  int v21; // eax@22
  bool result; // al@24
  PStringBase<char> v23; // [sp-4h] [bp-30h]@10
  bool ret; // [sp+13h] [bp-19h]@2
  PStringBase<char> str; // [sp+14h] [bp-18h]@16
  char *v26; // [sp+18h] [bp-14h]@6
  CInputMap *v27; // [sp+1Ch] [bp-10h]@1
  QualifiedControl key; // [sp+20h] [bp-Ch]@7

  v2 = i_pNode;
  v27 = this;
  if ( i_pNode )
  {
    v3 = this->m_listMappings.m_ihlIntrusive.m_hash.m_numElements;
    v4 = (char *)&this->m_listMappings;
    v5 = 0;
    ret = 1;
    if ( v3 )
    {
      v6 = *((_DWORD *)v4 + 28);
      if ( v6 )
        v5 = v6 - 16;
      else
        v5 = 0;
    }
    v7 = v5;
    v26 = v4;
    if ( v5 )
    {
      while ( 1 )
      {
        v8 = *(_DWORD *)(v7 + 4);
        v9 = *(_DWORD *)(v7 + 8);
        v10 = *(_DWORD *)(v7 + 24);
        key.m_key.m_dwKey = *(_DWORD *)v7;
        v11 = v2->vfptr;
        key.m_metamode = v8;
        key.m_activation = v9;
        v12 = (PFileNode *)((int (__thiscall *)(PFileNode *))v11[1].__vecDelDtor)(v2);
        v14 = v12;
        if ( v12 )
        {
          if ( FileNodeUtils::SetNameAsEnum(v12, 0x19u, v10) )
          {
            v15 = (PFileNode *)((int (__thiscall *)(PFileNode *))v14->vfptr[1].__vecDelDtor)(v14);
            if ( ControlSpecification::ToFileNode(
                   &key.m_key,
                   v15,
                   v27->m_pParent->m_rgDevices.m_data[(unsigned __int8)key.m_key.m_dwKey].dt) )
            {
              v17 = key.m_activation != 3;
              if ( key.m_metamode || v17 )
              {
                v18 = BitUtils::ReverseBits(key.m_metamode);
                PFileNode::MakeSubNodeAsHex(v14, v18);
                if ( v17 )
                {
                  str.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
                  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
                  if ( ControlActivationTypeToString(key.m_activation, &str) )
                  {
                    v23.m_charbuffer = str.m_charbuffer;
                    InterlockedIncrement((volatile LONG *)&str.m_charbuffer[-1]);
                    PFileNode::MakeSubNode(v14, v23);
                  }
                  v19 = &str.m_charbuffer[-2].m_data[12];
                  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1]) && v19 )
                  {
                    v20 = *(_DWORD *)v19;
                    v23.m_charbuffer = (PSRefBufferCharData<char> *)1;
                    (*(void (__thiscall **)(char *, signed int))v20)(v19, 1);
                  }
                }
              }
              v2 = i_pNode;
            }
            else
            {
              v23.m_charbuffer = v16;
              PStringBase<char>::PStringBase<char>(&v23, "ERROR - failed to write control spec.\n");
              PFileNode::ReportError(v10, v14, v23);
              PFileNode::RemoveSubNodePtr(v2, v14);
              ret = 0;
            }
            goto LABEL_22;
          }
          PFileNode::RemoveSubNodePtr(v2, v14);
        }
        v23.m_charbuffer = v13;
        PStringBase<char>::PStringBase<char>(&v23, "ERROR - failed to write action.\n");
        PFileNode::ReportError(v10, v2, v23);
        ret = 0;
LABEL_22:
        v21 = *(_DWORD *)(v7 + 16);
        if ( v21 )
        {
          v7 = v21 - 16;
          if ( v21 != 16 )
            continue;
        }
        break;
      }
    }
    result = ret;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0068D460) --------------------------------------------------------  // acclient.c:676254
char __thiscall CInputMap::ActionBindingList::FindBestMatch(CInputMap::ActionBindingList *this, QualifiedControl *i_key, unsigned int *o_data, QualifiedControl *o_key)
{
  HashList<QualifiedControl,unsigned long,1>::HashListData *v4; // edi@1
  HashList<QualifiedControl,unsigned long,1>::HashListData *i; // esi@2
  char v6; // al@6
  IntrusiveHashIterator<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> result; // [sp+8h] [bp-Ch]@1

  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::find_internal(
    &this->m_ihlIntrusive.m_hash,
    &result,
    i_key);
  v4 = result.m_currElement;
  if ( result.m_currElement )
  {
    for ( i = result.m_currElement->m_hashNext; i; i = i->m_hashNext )
    {
      if ( QualifiedControl::IsBetterMatch(i_key, &v4->m_hashKey, &i->m_hashKey) )
        v4 = i;
    }
    o_key->m_key.m_dwKey = v4->m_hashKey.m_key.m_dwKey;
    o_key->m_metamode = v4->m_hashKey.m_metamode;
    o_key->m_activation = v4->m_hashKey.m_activation;
    *o_data = v4->m_data;
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  return v6;
}

//----- (0068D4D0) --------------------------------------------------------  // acclient.c:676287
BOOL __thiscall CInputMap::ActionBindingList::FindConflictingControls(CInputMap::ActionBindingList *this, QualifiedControl *i_key, SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *o_controls)
{
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *v3; // ST14_4@1
  unsigned int i; // esi@1
  SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *v5; // ecx@3
  unsigned int v6; // edx@3
  int v7; // ebx@3
  int v8; // ebp@3
  unsigned int v9; // eax@3
  int v10; // eax@3
  unsigned int v11; // edx@4
  int v12; // ST18_4@9
  int v18; // eax@13
  unsigned int v19; // edx@13
  _STL::pair<QualifiedControl,unsigned long> boundControl; // [sp+Ch] [bp-10h]@1

  v3 = (IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *)this;
  SmartArray<_STL::pair<QualifiedControl,unsigned long>,1>::SetNElements(o_controls, 0, 1);
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::find_internal(
    v3,
    (IntrusiveHashIterator<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *)&boundControl,
    i_key);
  for ( i = boundControl.first.m_activation; i; i = *(_DWORD *)(i + 12) )
  {
    if ( QualifiedControl::IsConflicting(i_key, (QualifiedControl *)i) )
    {
      v5 = o_controls;
      v6 = *(_DWORD *)(i + 8);
      v7 = *(_DWORD *)i;
      v8 = *(_DWORD *)(i + 4);
      boundControl.second = *(_DWORD *)(i + 24);
      v9 = o_controls->m_sizeAndDeallocate;
      boundControl.first.m_activation = v6;
      v10 = v9 & 0x7FFFFFFF;
      if ( o_controls->m_num >= v10 )
      {
        v11 = v10 + 1;
        if ( (unsigned int)(v10 + 1) > 8 )
        {
          if ( v11 <= 0x4000 )
          {
            v12 = v10 + 1;
            __asm { bsr     this, [esp+28h+var_14] }
            v5 = o_controls;
            if ( v11 > 1 << _EAX )
              v11 = 2 * (1 << _EAX);
          }
          else if ( v11 & 0x3FFF )
          {
            v11 += 0x4000 - (v11 & 0x3FFF);
          }
        }
        else
        {
          v11 = 8;
        }
        if ( !SmartArray<_STL::pair<QualifiedControl,unsigned long>,1>::grow(v5, v11) )
          continue;
        v5 = o_controls;
      }
      v18 = (int)&v5->m_data[v5->m_num];
      v19 = boundControl.second;
      *(_DWORD *)(v18 + 8) = boundControl.first.m_activation;
      *(_DWORD *)v18 = v7;
      *(_DWORD *)(v18 + 4) = v8;
      *(_DWORD *)(v18 + 12) = v19;
      ++o_controls->m_num;
    }
  }
  return o_controls->m_num != 0;
}

//----- (0068D5F0) --------------------------------------------------------  // acclient.c:676360
char __thiscall CInputMap::FindBestMatch(CInputMap *this, QualifiedControl *i_key, unsigned int *o_idAction, QualifiedControl *o_key)
{
  return CInputMap::ActionBindingList::FindBestMatch(&this->m_listMappings, i_key, o_idAction, o_key);
}

//----- (0068D600) --------------------------------------------------------  // acclient.c:676366
BOOL __thiscall CInputMap::FindConflictingControls(CInputMap *this, QualifiedControl *i_key, SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *o_controls)
{
  return CInputMap::ActionBindingList::FindConflictingControls(&this->m_listMappings, i_key, o_controls);
}

//----- (0068D610) --------------------------------------------------------  // acclient.c:676372
char __thiscall CInputMap::FindKeysForAction(CInputMap *this, unsigned int i_id, List<QualifiedControl> *o_list)
{
  char v3; // dl@1
  int v4; // esi@1
  DLListData *v5; // ecx@2
  void *v6; // eax@7
  ListNode<QualifiedControl> *v7; // ecx@10
  int v8; // esi@13

  v3 = 0;
  v4 = 0;
  if ( this->m_listMappings.m_ihlIntrusive.m_hash.m_numElements )
  {
    v5 = this->m_listMappings.m_ihlIntrusive.m_list.head_;
    if ( v5 )
      v4 = (int)&v5[-2];
    else
      v4 = 0;
  }
  for ( ; v4; v4 = v8 - 16 )
  {
    if ( *(_DWORD *)(v4 + 24) == i_id )
    {
      v6 = operator new(0x14u);
      if ( v6 )
      {
        *(_DWORD *)v6 = *(_DWORD *)v4;
        *((_DWORD *)v6 + 1) = *(_DWORD *)(v4 + 4);
        *((_DWORD *)v6 + 2) = *(_DWORD *)(v4 + 8);
        *((_DWORD *)v6 + 3) = 0;
        *((_DWORD *)v6 + 4) = 0;
        if ( o_list->_head )
        {
          v7 = o_list->_tail;
          v7->next = (ListNode<QualifiedControl> *)v6;
          *((_DWORD *)v6 + 4) = v7;
        }
        else
        {
          o_list->_head = (ListNode<QualifiedControl> *)v6;
        }
        o_list->_tail = (ListNode<QualifiedControl> *)v6;
        ++o_list->_num_elements;
      }
      v3 = 1;
    }
    v8 = *(_DWORD *)(v4 + 16);
    if ( !v8 )
      break;
  }
  return v3;
}

//----- (0068D6B0) --------------------------------------------------------  // acclient.c:676426
bool __thiscall CMasterInputMap::ReadDevicesFromFileNode(CMasterInputMap *this, PFileNode *i_pNode)
{
  int v2; // edi@1
  CMasterInputMap *v3; // ebx@1
  int v4; // ebp@1
  bool result; // al@2
  PFileNode *v6; // esi@4
  ReferenceCountTemplate<1048576,0>Vtbl *v7; // edx@5
  PFileNode *v8; // eax@5
  unsigned int v9; // eax@6
  unsigned int v10; // ecx@6
  int v11; // ebx@6
  int v12; // eax@6
  unsigned int v13; // eax@7
  char *v14; // esi@9
  char *v15; // esi@14
  int v16; // eax@16
  PStringBase<char> v17; // [sp-8h] [bp-38h]@14
  PSRefBufferCharData<char> *v18; // [sp-4h] [bp-34h]@5
  PStringBase<char> str; // [sp+10h] [bp-20h]@4
  CMasterInputMap *v20; // [sp+14h] [bp-1Ch]@1
  int iLast; // [sp+18h] [bp-18h]@1
  DeviceKeyMapEntry device; // [sp+1Ch] [bp-14h]@4

  v2 = (int)i_pNode;
  v3 = this;
  v20 = this;
  v4 = 0;
  iLast = PFileNode::GetNumSubNodes(i_pNode);
  if ( iLast > 0 )
  {
    while ( 1 )
    {
      v6 = (PFileNode *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 12))(v2, v4);
      str.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PFileNode::GetNameAsPString(v6, v2, &str);
      if ( !StringToDeviceType(&str, &device.dt) )
        break;
      v7 = v6->vfptr;
      v18 = (PSRefBufferCharData<char> *)&device.guid;
      v8 = (PFileNode *)v7[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 0);
      if ( !CMasterInputMap::ReadGuidFromFileNode(v3, v2, v8, &device.guid) )
        break;
      v9 = v3->m_rgDevices.m_sizeAndDeallocate;
      v10 = v3->m_rgDevices.m_num;
      v11 = (int)&v3->m_rgDevices;
      v12 = v9 & 0x7FFFFFFF;
      if ( v10 < v12
        || (v13 = SmartArray<UIChildFramework *,1>::get_new_size(v12 + 1),
            SmartArray<DeviceKeyMapEntry,1>::grow((SmartArray<DeviceKeyMapEntry,1> *)v11, v13)) )
      {
        qmemcpy((void *)(*(_DWORD *)v11 + 20 * *(_DWORD *)(v11 + 8)), &device, 0x14u);
        v2 = (int)i_pNode;
        ++*(_DWORD *)(v11 + 8);
      }
      v14 = &str.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1]) )
      {
        if ( v14 )
          (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
      }
      ++v4;
      if ( v4 >= iLast )
        return 1;
      v3 = v20;
    }
    v18 = str.m_charbuffer;
    v17.m_charbuffer = str.m_charbuffer;
    PStringBase<char>::PStringBase<char>(&v17, "ERROR - not a valid device \"%s\"\n");
    PFileNode::ReportError(v2, v6, v17);
    v15 = &str.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1]) && v15 )
    {
      v16 = *(_DWORD *)v15;
      v18 = (PSRefBufferCharData<char> *)1;
      (*(void (__thiscall **)(char *, signed int))v16)(v15, 1);
    }
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0068D810) --------------------------------------------------------  // acclient.c:676514
bool __thiscall CMasterInputMap::IsMetaKey(CMasterInputMap *this, ControlSpecification key)
{
  HashList<ControlSpecification,unsigned long,1>::HashListData *v2; // eax@1
  bool v3; // zf@1

  v2 = this->m_listMetaKeys.m_ihlIntrusive.m_hash.m_buckets[key.m_dwKey
                                                          % this->m_listMetaKeys.m_ihlIntrusive.m_hash.m_numBuckets];
  v3 = v2 == 0;
  if ( v2 )
  {
    do
    {
      if ( v2->m_hashKey.m_dwKey == key.m_dwKey )
        break;
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    v3 = v2 == 0;
  }
  return !v3;
}

//----- (0068D850) --------------------------------------------------------  // acclient.c:676537
unsigned int __thiscall CMasterInputMap::MetaModeFromKey(CMasterInputMap *this, ControlSpecification key)
{
  HashList<ControlSpecification,unsigned long,1>::HashListData *v2; // eax@1
  unsigned int result; // eax@4

  v2 = this->m_listMetaKeys.m_ihlIntrusive.m_hash.m_buckets[key.m_dwKey
                                                          % this->m_listMetaKeys.m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey.m_dwKey != key.m_dwKey )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 )
    result = v2->m_data;
  else
LABEL_4:
    result = 0;
  return result;
}

//----- (0068D890) --------------------------------------------------------  // acclient.c:676561
ControlSpecification *__thiscall CMasterInputMap::KeyFromMetaMode(CMasterInputMap *this, ControlSpecification *result, unsigned int _data)
{
  char *v3; // ecx@1
  int v4; // eax@1
  int v5; // eax@2
  int v6; // eax@7
  ControlSpecification *v7; // eax@9

  v3 = (char *)&this->m_listMetaKeys;
  v4 = 0;
  if ( *((_DWORD *)v3 + 27) )
  {
    v5 = *((_DWORD *)v3 + 28);
    if ( v5 )
      v4 = v5 - 8;
    else
      v4 = 0;
  }
  if ( v4 )
  {
    while ( _data != *(_DWORD *)(v4 + 16) )
    {
      v6 = *(_DWORD *)(v4 + 8);
      if ( v6 )
      {
        v4 = v6 - 8;
        if ( v4 )
          continue;
      }
      goto LABEL_9;
    }
    result->m_dwKey = *(_DWORD *)v4;
    v7 = result;
  }
  else
  {
LABEL_9:
    v7 = result;
    result->m_dwKey = -1;
  }
  return v7;
}

//----- (0068D900) --------------------------------------------------------  // acclient.c:676605
char __thiscall CMasterInputMap::ToFileNode(CMasterInputMap *this, PFileNode *pRootNode)
{
  PStringBase<char> v2; // esi@1
  PFileNode *v3; // edi@1
  int v4; // esi@1
  unsigned int v5; // eax@4
  PStringBase<unsigned short> *v6; // eax@4
  char *v7; // esi@4
  unsigned int v8; // esi@7
  unsigned int v9; // ecx@10
  PFileNode *v10; // eax@10
  PSRefBufferCharData<char> *v11; // ecx@10
  int v12; // edx@10
  PFileNode *v13; // ebx@10
  int v14; // ecx@12
  PSRefBufferCharData<char> *v15; // esi@13
  volatile LONG *v16; // edi@13
  int v17; // esi@13
  PFileNode *v18; // edi@13
  int v19; // edx@15
  char *v20; // esi@17
  int v21; // edx@19
  PFileNode *v23; // ebx@21
  int v24; // ebp@21
  int v25; // ebp@22
  int v30; // esi@26
  int v31; // eax@28
  int v32; // edi@28
  int v33; // ecx@29
  int v34; // edx@30
  void *v35; // eax@31
  int v36; // ebp@36
  PSRefBufferCharData<char> *v37; // edx@38
  int v38; // ecx@38
  char v39; // al@39
  int v40; // ebp@40
  char *v41; // esi@41
  int v42; // edx@43
  PSRefBufferCharData<char> *v43; // ecx@44
  PSRefBufferCharData<char> *v44; // edi@45
  PSRefBufferCharData<char> *v45; // ebx@45
  int v46; // ecx@45
  int v47; // eax@46
  void *v48; // eax@47
  void *v49; // esi@47
  int v50; // edx@52
  char *v51; // esi@53
  int v52; // edx@55
  int v53; // esi@57
  int v54; // esi@58
  unsigned int v55; // ebx@62
  CInputMap *v56; // ebp@62
  PFileNode *v57; // eax@62
  unsigned int v58; // edi@62
  char v59; // al@63
  int v60; // esi@64
  unsigned int v62; // [sp+10h] [bp-B8h]@10
  PStringBase<char> strDeviceType; // [sp+24h] [bp-A4h]@4
  PStringBase<char> i_name; // [sp+28h] [bp-A0h]@1
  PStringBase<char> v65; // [sp+2Ch] [bp-9Ch]@11
  unsigned int i; // [sp+30h] [bp-98h]@4
  char *v67; // [sp+34h] [bp-94h]@25
  StringInfo siKeymapHelp; // [sp+38h] [bp-90h]@4

  i_name.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v2.m_charbuffer = this->m_strName.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v2.m_charbuffer[-1]);
  InterlockedIncrement((volatile LONG *)&v2.m_charbuffer[-1]);
  v3 = PFileNode::MakeSubNodeAsPString(pRootNode, v2);
  v4 = (int)&v2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  StringInfo::StringInfo(&siKeymapHelp);
  v5 = compute_str_hash("ID_KeymapHelp");
  StringInfo::SetStringIDandTableEnum(&siKeymapHelp, v5, 3);
  v6 = StringInfo::GetString(&siKeymapHelp, (PStringBase<unsigned short> *)&i, 0);
  PStringBase<unsigned short>::to_spstring(v6, &strDeviceType, 0);
  PFileNode::AddComment(v3, &strDeviceType);
  v7 = &strDeviceType.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strDeviceType.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  v8 = i - 20;
  if ( !InterlockedDecrement((volatile LONG *)(i - 20 + 4)) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  CMasterInputMap::WriteGuidToFileNode((Turbine_GUID *)&i_name.m_charbuffer[3].m_data[4], v3);
  v62 = v9;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v62, "Devices");
  v10 = PFileNode::MakeSubNodeAsPString(pRootNode, (PStringBase<char>)v62);
  v11 = i_name.m_charbuffer;
  v12 = *(_DWORD *)&i_name.m_charbuffer[4].m_data[12];
  v13 = v10;
  i = 0;
  if ( v12 )
  {
    v65.m_charbuffer = 0;
    do
    {
      strDeviceType.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      v14 = *(_DWORD *)&i_name.m_charbuffer[4].m_data[4];
      v62 = (unsigned int)&strDeviceType;
      if ( DeviceTypeToString(*(DeviceType *)&v65.m_charbuffer->m_data[v14], &strDeviceType) )
      {
        v15 = strDeviceType.m_charbuffer;
        v16 = (volatile LONG *)&strDeviceType.m_charbuffer[-1];
        InterlockedIncrement((volatile LONG *)&strDeviceType.m_charbuffer[-1]);
        v62 = (unsigned int)v15;
        InterlockedIncrement(v16);
        v17 = (int)&v15[-2].m_data[12];
        v18 = PFileNode::MakeSubNodeAsPString(v13, (PStringBase<char>)v62);
        if ( !InterlockedDecrement((volatile LONG *)(v17 + 4)) && v17 )
        {
          v19 = *(_DWORD *)v17;
          v62 = 1;
          (*(void (__thiscall **)(int, signed int))v19)(v17, 1);
        }
        CMasterInputMap::WriteGuidToFileNode(
          (Turbine_GUID *)&v65.m_charbuffer->m_data[*(_DWORD *)&i_name.m_charbuffer[4].m_data[4] + 4],
          v18);
      }
      v20 = &strDeviceType.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&strDeviceType.m_charbuffer[-1]) && v20 )
      {
        v21 = *(_DWORD *)v20;
        v62 = 1;
        (*(void (__thiscall **)(char *, signed int))v21)(v20, 1);
      }
      v11 = i_name.m_charbuffer;
      _CF = i++ + 1 < *(_DWORD *)&i_name.m_charbuffer[4].m_data[12];
      v65.m_charbuffer = (PSRefBufferCharData<char> *)((char *)v65.m_charbuffer + 20);
    }
    while ( _CF );
  }
  v62 = (unsigned int)v11;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v62, "MetaKeys");
  v23 = PFileNode::MakeSubNodeAsPString(pRootNode, (PStringBase<char>)v62);
  v24 = 0;
  if ( *(_DWORD *)&i_name.m_charbuffer[11].m_data[12] )
  {
    v25 = *(_DWORD *)&i_name.m_charbuffer[12].m_data[0];
    if ( v25 )
      v24 = v25 - 8;
    else
      v24 = 0;
  }
  v67 = i_name.m_charbuffer[5].m_data;
  if ( v24 )
  {
    while ( 1 )
    {
      i = *(_DWORD *)(v24 + 16);
      __asm { bsf     this, [esp+0B4h+i] }
      v30 = 32 - _EAX;
      if ( _EAX == -1 )
        v30 = 0;
      v31 = ((int (__thiscall *)(PFileNode *))v23->vfptr[1].__vecDelDtor)(v23);
      v32 = v31;
      if ( v31 )
      {
        v33 = *(_DWORD *)(v31 + 8);
        if ( v33 )
        {
          v34 = *(_DWORD *)v33;
          v62 = 1;
          (*(void (__stdcall **)(signed int))v34)(1);
        }
        v62 = 8;
        *(_DWORD *)(v32 + 8) = 0;
        v35 = operator new(v62);
        if ( v35 )
        {
          *(_DWORD *)v35 = &FileNodeName_UInt32::vftable;
          *((_DWORD *)v35 + 1) = v30;
        }
        else
        {
          v35 = 0;
        }
        *(_DWORD *)(v32 + 8) = v35;
      }
      if ( !ControlSpecification::ToFileNode(
              (ControlSpecification *)v24,
              (PFileNode *)v32,
              *(DeviceType *)(*(_DWORD *)&i_name.m_charbuffer[4].m_data[4] + 20 * (*(_DWORD *)v24 & 0xFF))) )
        goto LABEL_68;
      v36 = *(_DWORD *)(v24 + 8);
      if ( v36 )
      {
        v24 = v36 - 8;
        if ( v24 )
          continue;
      }
      break;
    }
  }
  PStringBase<char>::allocate_ref_buffer(&v65, strlen("Bindings"));
  v37 = v65.m_charbuffer;
  v38 = (int)"Bindings";
  do
  {
    v39 = *(_BYTE *)v38++;
    v37->m_data[0] = v39;
    v37 = (PSRefBufferCharData<char> *)((char *)v37 + 1);
  }
  while ( v39 );
  v40 = ((int (__fastcall *)(PFileNode *, PSRefBufferCharData<char> *))pRootNode->vfptr[1].__vecDelDtor)(pRootNode, v37);
  if ( v40 )
  {
    v44 = v65.m_charbuffer - 1;
    v45 = v65.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v65.m_charbuffer[-1]);
    v46 = *(_DWORD *)(v40 + 8);
    if ( v46 )
    {
      v47 = *(_DWORD *)v46;
      v62 = 1;
      (*(void (__stdcall **)(signed int))v47)(1);
    }
    v62 = 8;
    *(_DWORD *)(v40 + 8) = 0;
    v48 = operator new(v62);
    v49 = v48;
    if ( v48 )
    {
      *(_DWORD *)v48 = &FileNodeName_PString::vftable;
      v62 = (unsigned int)v44;
      *((_DWORD *)v48 + 1) = v45;
      InterlockedIncrement((volatile LONG *)v62);
    }
    else
    {
      v49 = 0;
    }
    *(_DWORD *)(v40 + 8) = v49;
    if ( !InterlockedDecrement((volatile LONG *)&v45[-1]) && v45 != (PSRefBufferCharData<char> *)20 )
    {
      v50 = *(_DWORD *)&v45[-2].m_data[12];
      v62 = 1;
      (*(void (__thiscall **)(char *, signed int))v50)(&v45[-2].m_data[12], 1);
    }
    v51 = &v65.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v65.m_charbuffer[-1]) && v51 )
    {
      v52 = *(_DWORD *)v51;
      v62 = 1;
      (*(void (__thiscall **)(char *, signed int))v52)(v51, 1);
    }
    strDeviceType.m_charbuffer = (PSRefBufferCharData<char> *)v40;
    v43 = (PSRefBufferCharData<char> *)v40;
  }
  else
  {
    v41 = &v65.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v65.m_charbuffer[-1]) && v41 )
    {
      v42 = *(_DWORD *)v41;
      v62 = 1;
      (*(void (__thiscall **)(char *, signed int))v42)(v41, 1);
    }
    v43 = 0;
    strDeviceType.m_charbuffer = 0;
  }
  v53 = 0;
  if ( *(_DWORD *)&i_name.m_charbuffer[19].m_data[4] )
  {
    v54 = *(_DWORD *)&i_name.m_charbuffer[19].m_data[8];
    if ( v54 )
      v53 = v54 - 8;
    else
      v53 = 0;
  }
  v67 = &i_name.m_charbuffer[12].m_data[8];
  if ( v53 )
  {
    while ( 1 )
    {
      v55 = *(_DWORD *)v53;
      v56 = *(CInputMap **)(v53 + 16);
      v57 = (PFileNode *)(*(int (**)(void))(*(_DWORD *)&v43->m_data[0] + 4))();
      v58 = (unsigned int)v57;
      if ( !v57 )
        break;
      v59 = FileNodeUtils::SetNameAsEnum(v57, 0x1Au, v55);
      v62 = v58;
      if ( !v59 )
      {
        PFileNode::RemoveSubNodePtr((PFileNode *)strDeviceType.m_charbuffer, (PFileNode *)v62);
        break;
      }
      CInputMap::ToFileNode(v56, (PFileNode *)v62);
      v60 = *(_DWORD *)(v53 + 8);
      if ( !v60 )
        goto LABEL_69;
      v53 = v60 - 8;
      if ( !v53 )
        goto LABEL_69;
      v43 = strDeviceType.m_charbuffer;
    }
LABEL_68:
    StringInfo::~StringInfo(&siKeymapHelp);
    return 0;
  }
LABEL_69:
  StringInfo::~StringInfo(&siKeymapHelp);
  return 1;
}
// 797108: using guessed type int (__thiscall *FileNodeName_UInt32::vftable)(void *, char);
// 797140: using guessed type int (__thiscall *FileNodeName_PString::vftable)(void *, char);

//----- (0068DD70) --------------------------------------------------------  // acclient.c:676915
void __thiscall IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>(IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashList<QualifiedControl,unsigned long,1>::HashListData **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashList<QualifiedControl,unsigned long,1>::HashListData **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FFFE0: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::vftable[3])(void *, char);

//----- (0068DE00) --------------------------------------------------------  // acclient.c:676948
void __thiscall IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>(IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashList<ControlSpecification,unsigned long,1>::HashListData **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashList<ControlSpecification,unsigned long,1>::HashListData **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FFFE4: using guessed type int (__thiscall *IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::vftable[2])(void *, char);

//----- (0068DE90) --------------------------------------------------------  // acclient.c:676981
void __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>(IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>Vtbl *)&IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashList<unsigned long,CInputMap *,1>::HashListData **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashList<unsigned long,CInputMap *,1>::HashListData **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FFFE8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::vftable)(void *, char);

//----- (0068DF20) --------------------------------------------------------  // acclient.c:677014
void __thiscall IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::remove(IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *this, IntrusiveHashIterator<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> iter)
{
  HashList<QualifiedControl,unsigned long,1>::HashListData *v2; // eax@1
  HashList<QualifiedControl,unsigned long,1>::HashListData *v3; // edx@2

  v2 = *iter.m_currBucket;
  if ( *iter.m_currBucket == iter.m_currElement )
    goto LABEL_8;
  do
  {
    v3 = v2;
    v2 = v2->m_hashNext;
  }
  while ( v2 != iter.m_currElement );
  if ( v3 )
  {
    v3->m_hashNext = v2->m_hashNext;
    --this->m_numElements;
  }
  else
  {
LABEL_8:
    *iter.m_currBucket = v2->m_hashNext;
    --this->m_numElements;
  }
}

//----- (0068DF60) --------------------------------------------------------  // acclient.c:677042
char __thiscall IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::resize_internal(IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *v2; // esi@1
  char result; // al@2
  HashList<QualifiedControl,unsigned long,1>::HashListData *v4; // ebx@3
  int v5; // ecx@4
  HashList<QualifiedControl,unsigned long,1>::HashListData **v6; // eax@5
  int v7; // eax@6
  HashList<QualifiedControl,unsigned long,1>::HashListData **v8; // edi@7
  HashList<QualifiedControl,unsigned long,1>::HashListData *v9; // ecx@7
  HashList<QualifiedControl,unsigned long,1>::HashListData *v10; // eax@9
  HashList<QualifiedControl,unsigned long,1>::HashListData *v11; // edx@10
  HashList<QualifiedControl,unsigned long,1>::HashListData *v12; // eax@17
  HashList<QualifiedControl,unsigned long,1>::HashListData *v13; // edi@18

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
        if ( v2->m_firstInterestingBucket == (HashList<QualifiedControl,unsigned long,1>::HashListData **)v5 )
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
            v2->m_firstInterestingBucket = (HashList<QualifiedControl,unsigned long,1>::HashListData **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_22;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_22:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashList<QualifiedControl,unsigned long,1>::HashListData **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v2,
      _numBuckets);
    v12 = v4;
    if ( v4 )
    {
      do
      {
        v13 = v12->m_hashNext;
        IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::add_internal(
          v2,
          v12);
        v12 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (0068E030) --------------------------------------------------------  // acclient.c:677139
char __thiscall IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::resize_internal(IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *v2; // esi@1
  char result; // al@2
  HashList<ControlSpecification,unsigned long,1>::HashListData *v4; // ebx@3
  int v5; // ecx@4
  HashList<ControlSpecification,unsigned long,1>::HashListData **v6; // eax@5
  int v7; // eax@6
  HashList<ControlSpecification,unsigned long,1>::HashListData **v8; // edi@7
  HashList<ControlSpecification,unsigned long,1>::HashListData *v9; // ecx@7
  HashList<ControlSpecification,unsigned long,1>::HashListData *v10; // eax@9
  HashList<ControlSpecification,unsigned long,1>::HashListData *v11; // edx@10
  HashList<ControlSpecification,unsigned long,1>::HashListData *v12; // eax@17
  HashList<ControlSpecification,unsigned long,1>::HashListData *v13; // edi@18

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
        if ( v2->m_firstInterestingBucket == (HashList<ControlSpecification,unsigned long,1>::HashListData **)v5 )
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
            v2->m_firstInterestingBucket = (HashList<ControlSpecification,unsigned long,1>::HashListData **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_22;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_22:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashList<ControlSpecification,unsigned long,1>::HashListData **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v2,
      _numBuckets);
    v12 = v4;
    if ( v4 )
    {
      do
      {
        v13 = v12->m_hashNext;
        IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::add_internal(
          v2,
          v12);
        v12 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (0068E100) --------------------------------------------------------  // acclient.c:677236
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::resize_internal(IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *v2; // esi@1
  char result; // al@2
  HashList<unsigned long,CInputMap *,1>::HashListData *v4; // ebx@3
  int v5; // ecx@4
  HashList<unsigned long,CInputMap *,1>::HashListData **v6; // eax@5
  int v7; // eax@6
  HashList<unsigned long,CInputMap *,1>::HashListData **v8; // edi@7
  HashList<unsigned long,CInputMap *,1>::HashListData *v9; // ecx@7
  HashList<unsigned long,CInputMap *,1>::HashListData *v10; // eax@9
  HashList<unsigned long,CInputMap *,1>::HashListData *v11; // edx@10
  HashList<unsigned long,CInputMap *,1>::HashListData *v12; // eax@17
  HashList<unsigned long,CInputMap *,1>::HashListData *v13; // edi@18

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
        if ( v2->m_firstInterestingBucket == (HashList<unsigned long,CInputMap *,1>::HashListData **)v5 )
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
            v2->m_firstInterestingBucket = (HashList<unsigned long,CInputMap *,1>::HashListData **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_22;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_22:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashList<unsigned long,CInputMap *,1>::HashListData **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v2,
      _numBuckets);
    v12 = v4;
    if ( v4 )
    {
      do
      {
        v13 = v12->m_hashNext;
        IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::add_internal(v2, v12);
        v12 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (0068E1D0) --------------------------------------------------------  // acclient.c:677331
HashList<QualifiedControl,unsigned long,1>::HashListData *__thiscall IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::remove(IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *this, QualifiedControl *key)
{
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *v2; // esi@1
  HashList<QualifiedControl,unsigned long,1>::HashListData *v3; // edi@1
  _BYTE v4[12]; // ST00_12@2
  HashList<QualifiedControl,unsigned long,1>::HashListData *result; // eax@2
  IntrusiveHashIterator<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> iter; // [sp+Ch] [bp-Ch]@1

  v2 = this;
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::find_internal(
    this,
    &iter,
    key);
  v3 = iter.m_currElement;
  if ( iter.m_currElement )
  {
    *(_QWORD *)&v4[4] = *(_QWORD *)&iter.m_currBucket;
    *(_DWORD *)v4 = iter.m_currHashTable;
    IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::remove(
      v2,
      *(IntrusiveHashIterator<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *)v4);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0068E230) --------------------------------------------------------  // acclient.c:677362
void __thiscall IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::delete_contents(IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *this)
{
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *v1; // esi@1
  int v2; // ecx@2
  HashList<QualifiedControl,unsigned long,1>::HashListData **v3; // eax@3
  int v4; // eax@4
  HashList<QualifiedControl,unsigned long,1>::HashListData **v5; // edi@5
  void *v6; // ecx@5
  void *v7; // eax@7
  void *v8; // edx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashList<QualifiedControl,unsigned long,1>::HashListData **)v2 )
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
        v1->m_firstInterestingBucket = (HashList<QualifiedControl,unsigned long,1>::HashListData **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_17;
    do
    {
      v8 = v7;
      v7 = (void *)*((_DWORD *)v7 + 3);
    }
    while ( v7 != v6 );
    if ( v8 )
      *((_DWORD *)v8 + 3) = *((_DWORD *)v7 + 3);
    else
LABEL_17:
      *v5 = (HashList<QualifiedControl,unsigned long,1>::HashListData *)*((_DWORD *)v7 + 3);
    --v1->m_numElements;
    if ( v6 )
      operator delete(v6);
  }
}

//----- (0068E2B0) --------------------------------------------------------  // acclient.c:677419
char __thiscall IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::grow(IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::resize_internal(
           v2,
           *v3);
}

//----- (0068E300) --------------------------------------------------------  // acclient.c:677439
char __thiscall IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::grow(IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::resize_internal(
           v2,
           *v3);
}

//----- (0068E350) --------------------------------------------------------  // acclient.c:677459
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::grow(IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::resize_internal(
           v2,
           *v3);
}

//----- (0068E3A0) --------------------------------------------------------  // acclient.c:677479
void __thiscall IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::delete_contents(IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *this)
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
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::delete_contents(&this->m_hash);
}

//----- (0068E400) --------------------------------------------------------  // acclient.c:677524
void __thiscall IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::add_internal(IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *this, HashList<QualifiedControl,unsigned long,1>::HashListData *data)
{
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *v2; // esi@1
  HashList<QualifiedControl,unsigned long,1>::HashListData **v3; // eax@3

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::grow(this);
  v3 = &v2->m_buckets[data->m_hashKey.m_key.m_dwKey % v2->m_numBuckets];
  data->m_hashNext = *v3;
  *v3 = data;
  if ( v3 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = v3;
  ++v2->m_numElements;
}

//----- (0068E440) --------------------------------------------------------  // acclient.c:677541
void __thiscall IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::add_internal(IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *this, HashList<ControlSpecification,unsigned long,1>::HashListData *data)
{
  IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *v2; // esi@1
  HashList<ControlSpecification,unsigned long,1>::HashListData **v3; // eax@3

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::grow(this);
  v3 = &v2->m_buckets[data->m_hashKey.m_dwKey % v2->m_numBuckets];
  data->m_hashNext = *v3;
  *v3 = data;
  if ( v3 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = v3;
  ++v2->m_numElements;
}

//----- (0068E480) --------------------------------------------------------  // acclient.c:677558
void __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::add_internal(IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *this, HashList<unsigned long,CInputMap *,1>::HashListData *data)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,CInputMap *,1>::HashListData **v3; // eax@3

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::grow(this);
  v3 = &v2->m_buckets[data->m_hashKey % v2->m_numBuckets];
  data->m_hashNext = *v3;
  *v3 = data;
  if ( v3 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = v3;
  ++v2->m_numElements;
}

//----- (0068E4C0) --------------------------------------------------------  // acclient.c:677575
char __thiscall IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::add(IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *this, HashList<QualifiedControl,unsigned long,1>::HashListData *data)
{
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *v2; // esi@1
  char v3; // al@2
  unsigned int v4; // edx@5
  HashList<QualifiedControl,unsigned long,1>::HashListData **v5; // eax@5
  int v6; // eax@5
  IntrusiveHashIterator<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> result; // [sp+8h] [bp-Ch]@1

  v2 = this;
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::find_internal(
    this,
    &result,
    &data->m_hashKey);
  if ( result.m_currElement )
  {
    v3 = 0;
  }
  else
  {
    if ( (signed int)(2 * v2->m_numBuckets) < (signed int)(v2->m_numElements + 1) )
      IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::grow(v2);
    v4 = data->m_hashKey.m_key.m_dwKey % v2->m_numBuckets;
    v5 = v2->m_buckets;
    data->m_hashNext = v5[v4];
    v5[v4] = data;
    v6 = (int)&v5[v4];
    if ( (HashList<QualifiedControl,unsigned long,1>::HashListData **)v6 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashList<QualifiedControl,unsigned long,1>::HashListData **)v6;
    ++v2->m_numElements;
    v3 = 1;
  }
  return v3;
}

//----- (0068E530) --------------------------------------------------------  // acclient.c:677611
char __thiscall IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::add(IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *this, HashList<ControlSpecification,unsigned long,1>::HashListData *data)
{
  IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashList<ControlSpecification,unsigned long,1>::HashListData *v4; // eax@1
  unsigned int v5; // edx@6
  HashList<ControlSpecification,unsigned long,1>::HashListData **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey.m_dwKey % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.m_dwKey != data->m_hashKey.m_dwKey )
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
      IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::grow(this);
    v5 = data->m_hashKey.m_dwKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashList<ControlSpecification,unsigned long,1>::HashListData **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashList<ControlSpecification,unsigned long,1>::HashListData **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (0068E5B0) --------------------------------------------------------  // acclient.c:677655
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::add(IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *this, HashList<unsigned long,CInputMap *,1>::HashListData *data)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashList<unsigned long,CInputMap *,1>::HashListData *v4; // eax@1
  unsigned int v5; // edx@6
  HashList<unsigned long,CInputMap *,1>::HashListData **v6; // eax@6
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
      IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashList<unsigned long,CInputMap *,1>::HashListData **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashList<unsigned long,CInputMap *,1>::HashListData **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (0068E630) --------------------------------------------------------  // acclient.c:677699
char __thiscall IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::place_at_tail(IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *this, HashList<QualifiedControl,unsigned long,1>::HashListData *pMoving)
{
  IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *v2; // edi@1
  DLListData *v3; // eax@7
  IntrusiveHashIterator<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> result; // [sp+8h] [bp-Ch]@1

  v2 = this;
  if ( IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::find_internal(
         &this->m_hash,
         &result,
         &pMoving->m_hashKey)->m_currElement )
  {
    if ( pMoving )
      DLListBase::Remove(&v2->m_list, (DLListData *)&pMoving->dllist_next);
    else
      DLListBase::Remove(&v2->m_list, 0);
  }
  else
  {
    IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::add(
      &v2->m_hash,
      pMoving);
  }
  if ( pMoving )
    v3 = (DLListData *)&pMoving->dllist_next;
  else
    v3 = 0;
  DLListBase::InsertAfter(&v2->m_list, v3, v2->m_list.tail_);
  return 1;
}

//----- (0068E6A0) --------------------------------------------------------  // acclient.c:677731
char __thiscall IntrusiveHashList<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::place_at_tail(IntrusiveHashList<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *this, HashList<ControlSpecification,unsigned long,1>::HashListData *pMoving)
{
  IntrusiveHashList<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *v2; // esi@1
  HashList<ControlSpecification,unsigned long,1>::HashListData *v3; // eax@1

  v2 = this;
  v3 = v2->m_hash.m_buckets[pMoving->m_hashKey.m_dwKey % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.m_dwKey != pMoving->m_hashKey.m_dwKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
    DLListBase::Remove(&this->m_list, (DLListData *)&pMoving->dllist_next);
  else
LABEL_4:
    IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::add(
      &this->m_hash,
      pMoving);
  DLListBase::InsertAfter(&v2->m_list, (DLListData *)&pMoving->dllist_next, v2->m_list.tail_);
  return 1;
}

//----- (0068E700) --------------------------------------------------------  // acclient.c:677758
char __thiscall IntrusiveHashList<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::place_at_tail(IntrusiveHashList<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *this, HashList<unsigned long,CInputMap *,1>::HashListData *pMoving)
{
  IntrusiveHashList<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,CInputMap *,1>::HashListData *v3; // eax@1

  v2 = this;
  v3 = v2->m_hash.m_buckets[pMoving->m_hashKey % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != pMoving->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
    DLListBase::Remove(&this->m_list, (DLListData *)&pMoving->dllist_next);
  else
LABEL_4:
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::add(
      &this->m_hash,
      pMoving);
  DLListBase::InsertAfter(&v2->m_list, (DLListData *)&pMoving->dllist_next, v2->m_list.tail_);
  return 1;
}

//----- (0068E760) --------------------------------------------------------  // acclient.c:677785
BOOL __thiscall CInputMap::UnbindByKey(CInputMap *this, QualifiedControl i_key)
{
  char *v2; // esi@1
  HashList<QualifiedControl,unsigned long,1>::HashListData *v3; // edi@1
  IntrusiveHashIterator<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> result; // [sp+8h] [bp-Ch]@1

  v2 = (char *)&this->m_listMappings;
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::find_internal(
    &this->m_listMappings.m_ihlIntrusive.m_hash,
    &result,
    &i_key);
  v3 = result.m_currElement;
  if ( result.m_currElement )
  {
    DLListBase::Remove((DLListBase *)v2 + 14, (DLListData *)&result.m_currElement->dllist_next);
    IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::remove(
      (IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *)v2,
      &i_key);
    operator delete(v3);
  }
  return v3 != 0;
}

//----- (0068E7C0) --------------------------------------------------------  // acclient.c:677809
void __thiscall CMasterInputMap::CMasterInputMap(CMasterInputMap *this)
{
  CMasterInputMap *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_8F8498);
  v1->vfptr = (InterfaceVtbl *)&CMasterInputMap::vftable;
  PStringBase<char>::PStringBase<char>(&v1->m_strName, "User Defined Keymap");
  v1->m_rgDevices.m_data = 0;
  v1->m_rgDevices.m_sizeAndDeallocate = 0;
  v1->m_rgDevices.m_num = 0;
  IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>(
    &v1->m_listMetaKeys.m_ihlIntrusive.m_hash,
    0);
  v1->m_listMetaKeys.m_ihlIntrusive.m_list.head_ = 0;
  v1->m_listMetaKeys.m_ihlIntrusive.m_list.tail_ = 0;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>(
    &v1->m_hashSections.m_ihlIntrusive.m_hash,
    0);
  v1->m_hashSections.m_ihlIntrusive.m_list.head_ = 0;
  v1->m_hashSections.m_ihlIntrusive.m_list.tail_ = 0;
  v1->m_dwUsedMetaKeys = 0;
}
// 800158: using guessed type __int32 (__stdcall *CMasterInputMap::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0068E820) --------------------------------------------------------  // acclient.c:677835
signed int CMasterInputMap::GetDBOType()
{
  return 29;
}

//----- (0068E830) --------------------------------------------------------  // acclient.c:677841
char __thiscall IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::push_tail(IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *this, HashList<QualifiedControl,unsigned long,1>::HashListData *val)
{
  IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *v2; // esi@1
  char v3; // al@2
  DLListData *v4; // eax@4
  IntrusiveHashIterator<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> result; // [sp+8h] [bp-Ch]@1

  v2 = this;
  if ( IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::find_internal(
         &this->m_hash,
         &result,
         &val->m_hashKey)->m_currElement )
  {
    v3 = 0;
  }
  else
  {
    IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::add(
      &v2->m_hash,
      val);
    if ( val )
      v4 = (DLListData *)&val->dllist_next;
    else
      v4 = 0;
    DLListBase::InsertAfter(&v2->m_list, v4, v2->m_list.tail_);
    v3 = 1;
  }
  return v3;
}

//----- (0068E890) --------------------------------------------------------  // acclient.c:677872
char __thiscall HashList<ControlSpecification,unsigned long,1>::move_to_tail(HashList<ControlSpecification,unsigned long,1> *this, ControlSpecification *keyToMove)
{
  HashList<ControlSpecification,unsigned long,1>::HashListData *v2; // eax@1
  char result; // al@4

  v2 = this->m_ihlIntrusive.m_hash.m_buckets[keyToMove->m_dwKey % this->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v2 )
    goto LABEL_10;
  while ( v2->m_hashKey.m_dwKey != keyToMove->m_dwKey )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      return 0;
  }
  if ( v2 )
    result = IntrusiveHashList<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::place_at_tail(
               &this->m_ihlIntrusive,
               v2);
  else
LABEL_10:
    result = 0;
  return result;
}

//----- (0068E8E0) --------------------------------------------------------  // acclient.c:677897
char __thiscall IntrusiveHashList<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::push_tail(IntrusiveHashList<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *this, HashList<ControlSpecification,unsigned long,1>::HashListData *val)
{
  IntrusiveHashList<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1> *v2; // esi@1
  HashList<ControlSpecification,unsigned long,1>::HashListData *v3; // eax@1
  char result; // al@4

  v2 = this;
  v3 = v2->m_hash.m_buckets[val->m_hashKey.m_dwKey % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.m_dwKey != val->m_hashKey.m_dwKey )
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
    IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::add(
      &this->m_hash,
      val);
    DLListBase::InsertAfter(&v2->m_list, (DLListData *)&val->dllist_next, v2->m_list.tail_);
    result = 1;
  }
  return result;
}

//----- (0068E940) --------------------------------------------------------  // acclient.c:677930
char __thiscall HashList<unsigned long,CInputMap *,1>::move_to_tail(HashList<unsigned long,CInputMap *,1> *this, const unsigned int *keyToMove)
{
  HashList<unsigned long,CInputMap *,1>::HashListData *v2; // eax@1
  char result; // al@4

  v2 = this->m_ihlIntrusive.m_hash.m_buckets[*keyToMove % this->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v2 )
    goto LABEL_10;
  while ( v2->m_hashKey != *keyToMove )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      return 0;
  }
  if ( v2 )
    result = IntrusiveHashList<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::place_at_tail(
               &this->m_ihlIntrusive,
               v2);
  else
LABEL_10:
    result = 0;
  return result;
}

//----- (0068E990) --------------------------------------------------------  // acclient.c:677955
char __thiscall IntrusiveHashList<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::push_tail(IntrusiveHashList<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *this, HashList<unsigned long,CInputMap *,1>::HashListData *val)
{
  IntrusiveHashList<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,CInputMap *,1>::HashListData *v3; // eax@1
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
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::add(&this->m_hash, val);
    DLListBase::InsertAfter(&v2->m_list, (DLListData *)&val->dllist_next, v2->m_list.tail_);
    result = 1;
  }
  return result;
}

//----- (0068EA00) --------------------------------------------------------  // acclient.c:677986
char __thiscall CInputMap::UnbindAllByAction(CInputMap *this, unsigned int i_id)
{
  unsigned int v2; // esi@1
  char *v3; // ecx@1
  char v4; // dl@1
  int v5; // eax@1
  int v6; // eax@2
  char *v7; // esi@5
  int v8; // ebx@5
  int v9; // eax@7
  int v10; // ecx@7
  ControlSpecification *v11; // ebp@7
  int v12; // eax@10
  int v13; // ecx@10
  int v14; // ecx@12
  int v15; // ecx@16
  unsigned int v16; // eax@18
  int v17; // ecx@18
  int v18; // esi@18
  int v19; // edi@18
  int v20; // eax@23
  int v21; // ecx@24
  int v23; // eax@34
  char *iterCur_4; // [sp+18h] [bp-4h]@5

  v2 = this->m_listMappings.m_ihlIntrusive.m_hash.m_numElements;
  v3 = (char *)&this->m_listMappings;
  v4 = 0;
  v5 = 0;
  if ( v2 )
  {
    v6 = *((_DWORD *)v3 + 28);
    if ( v6 )
      v5 = v6 - 16;
    else
      v5 = 0;
  }
  v7 = v3;
  v8 = v5;
  iterCur_4 = v3;
  while ( v8 )
  {
    if ( *(_DWORD *)(v8 + 24) == i_id )
    {
      v9 = *(_DWORD *)(v8 + 16);
      v10 = v8 + 16;
      v11 = (ControlSpecification *)v8;
      if ( v9 )
        v8 = v9 - 16;
      else
        v8 = 0;
      v12 = v11 != 0 ? v10 : 0;
      v13 = *(_DWORD *)(v11 != 0 ? v10 + 4 : 4);
      if ( v13 )
      {
        *(_DWORD *)v13 = *(_DWORD *)v12;
      }
      else
      {
        v14 = **((_DWORD **)v7 + 28);
        *((_DWORD *)v7 + 28) = v14;
        if ( v14 )
          *(_DWORD *)(v14 + 4) = 0;
      }
      if ( *(_DWORD *)v12 )
      {
        *(_DWORD *)(*(_DWORD *)v12 + 4) = *(_DWORD *)(v12 + 4);
      }
      else
      {
        v15 = *(_DWORD *)(*((_DWORD *)v7 + 29) + 4);
        *((_DWORD *)v7 + 29) = v15;
        if ( v15 )
          *(_DWORD *)v15 = 0;
      }
      *(_DWORD *)v12 = 0;
      *(_DWORD *)(v12 + 4) = 0;
      v16 = ControlSpecification::operator%(v11, *((_DWORD *)v7 + 26));
      v17 = *((_DWORD *)v7 + 24);
      v18 = *(_DWORD *)(v17 + 4 * v16);
      v19 = v17 + 4 * v16;
      if ( v18 )
      {
        while ( !QualifiedControl::operator==((QualifiedControl *)v18, (QualifiedControl *)v11) )
        {
          v18 = *(_DWORD *)(v18 + 12);
          if ( !v18 )
            goto LABEL_29;
        }
        if ( v18 )
        {
          v20 = *(_DWORD *)v19;
          if ( *(_DWORD *)v19 == v18 )
            goto LABEL_38;
          do
          {
            v21 = v20;
            v20 = *(_DWORD *)(v20 + 12);
          }
          while ( v20 != v18 );
          if ( v21 )
            *(_DWORD *)(v21 + 12) = *(_DWORD *)(v20 + 12);
          else
LABEL_38:
            *(_DWORD *)v19 = *(_DWORD *)(v20 + 12);
          --*((_DWORD *)iterCur_4 + 27);
        }
      }
LABEL_29:
      if ( v11 )
        operator delete(v11);
      v7 = iterCur_4;
      v4 = 1;
    }
    else
    {
      v23 = *(_DWORD *)(v8 + 16);
      if ( !v23 )
        return v4;
      v8 = v23 - 16;
    }
  }
  return v4;
}

//----- (0068EB40) --------------------------------------------------------  // acclient.c:678112
void __thiscall CMasterInputMap::Clear(CMasterInputMap *this)
{
  CMasterInputMap *v1; // ebp@1
  int v2; // ebx@2
  DLListData *v3; // eax@3
  DLListData *v4; // ecx@4
  DLListData *v5; // ecx@6
  bool v6; // zf@6
  DLListData *v7; // ecx@10
  int v8; // edx@14
  HashList<unsigned long,CInputMap *,1>::HashListData **v9; // eax@14
  HashList<unsigned long,CInputMap *,1>::HashListData *v10; // ecx@14
  int v11; // edi@14
  HashList<unsigned long,CInputMap *,1>::HashListData *v12; // eax@14
  HashList<unsigned long,CInputMap *,1>::HashListData *v13; // edx@20
  int v14; // edi@25
  void *v15; // eax@26

  v1 = this;
  HashList<ControlSpecification,unsigned long,1>::flush((HashList<unsigned long,ActionMapValue,1> *)&this->m_listMetaKeys);
  while ( 1 )
  {
    v2 = 0;
    if ( !v1->m_hashSections.m_ihlIntrusive.m_hash.m_numElements )
      break;
    v3 = v1->m_hashSections.m_ihlIntrusive.m_list.head_;
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
        v1->m_hashSections.m_ihlIntrusive.m_list.head_ = v3->dllist_next;
        if ( !v6 )
          v5->dllist_prev = 0;
      }
      if ( v3->dllist_next )
      {
        v3->dllist_next->dllist_prev = v3->dllist_prev;
      }
      else
      {
        v7 = v1->m_hashSections.m_ihlIntrusive.m_list.tail_->dllist_prev;
        v1->m_hashSections.m_ihlIntrusive.m_list.tail_ = v7;
        if ( v7 )
          v7->dllist_next = 0;
      }
      v3->dllist_next = 0;
      v3->dllist_prev = 0;
      if ( v3 )
        v2 = (int)&v3[-1];
    }
    v8 = *(_DWORD *)v2 % v1->m_hashSections.m_ihlIntrusive.m_hash.m_numBuckets;
    v9 = v1->m_hashSections.m_ihlIntrusive.m_hash.m_buckets;
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
          goto LABEL_31;
        do
        {
          v13 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v12 );
        if ( v13 )
          v13->m_hashNext = v10->m_hashNext;
        else
LABEL_31:
          *(_DWORD *)v11 = v10->m_hashNext;
        --v1->m_hashSections.m_ihlIntrusive.m_hash.m_numElements;
      }
    }
LABEL_25:
    v14 = *(_DWORD *)(v2 + 16);
    operator delete((void *)v2);
    if ( v14 )
    {
      IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::delete_contents((IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *)(v14 + 8));
      v15 = *(void **)(v14 + 104);
      *(_DWORD *)(v14 + 8) = IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::vftable;
      if ( v15 != (void *)(v14 + 12) )
        operator delete[](v15);
      *(_DWORD *)(v14 + 104) = 0;
      *(_DWORD *)(v14 + 108) = 0;
      *(_DWORD *)(v14 + 112) = 0;
      *(_DWORD *)(v14 + 116) = 0;
      operator delete((void *)v14);
    }
  }
}
// 7FFFE0: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::vftable[3])(void *, char);

//----- (0068EC60) --------------------------------------------------------  // acclient.c:678221
char __thiscall HashList<QualifiedControl,unsigned long,1>::push_tail(HashList<QualifiedControl,unsigned long,1> *this, QualifiedControl *key, const unsigned int *val)
{
  IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *v3; // edi@1
  char v4; // al@3
  void *v5; // eax@5
  HashList<QualifiedControl,unsigned long,1>::HashListData *v6; // esi@6
  char v7; // bl@8
  IntrusiveHashIterator<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> result; // [sp+8h] [bp-Ch]@1

  v3 = (IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *)this;
  if ( IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::find_internal(
         &this->m_ihlIntrusive.m_hash,
         &result,
         key)->m_currElement )
  {
    IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::find_internal(
      v3,
      &result,
      key);
    if ( result.m_currElement )
      v4 = IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::place_at_tail(
             (IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *)v3,
             result.m_currElement);
    else
      v4 = 0;
  }
  else
  {
    v5 = operator new(0x1Cu);
    if ( v5 )
    {
      *(QualifiedControl *)v5 = *key;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 4) = 0;
      *((_DWORD *)v5 + 5) = 0;
      *((_DWORD *)v5 + 6) = *val;
      v6 = (HashList<QualifiedControl,unsigned long,1>::HashListData *)v5;
    }
    else
    {
      v6 = 0;
    }
    v7 = IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::push_tail(
           (IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *)v3,
           v6);
    if ( !v7 && v6 )
      operator delete(v6);
    v4 = v7;
  }
  return v4;
}

//----- (0068ED20) --------------------------------------------------------  // acclient.c:678274
char __thiscall HashList<ControlSpecification,unsigned long,1>::push_tail(HashList<ControlSpecification,unsigned long,1> *this, ControlSpecification *key, const unsigned int *val)
{
  HashList<ControlSpecification,unsigned long,1> *v3; // edi@1
  HashList<ControlSpecification,unsigned long,1>::HashListData *v4; // edx@1
  void *v5; // eax@4
  HashList<ControlSpecification,unsigned long,1>::HashListData *v6; // esi@5
  char result; // al@7
  char v8; // bl@9

  v3 = this;
  v4 = v3->m_ihlIntrusive.m_hash.m_buckets[key->m_dwKey % v3->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.m_dwKey != key->m_dwKey )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = HashList<ControlSpecification,unsigned long,1>::move_to_tail(this, key);
  }
  else
  {
LABEL_4:
    v5 = operator new(0x14u);
    if ( v5 )
    {
      *(_DWORD *)v5 = key->m_dwKey;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 4) = *val;
      v6 = (HashList<ControlSpecification,unsigned long,1>::HashListData *)v5;
    }
    else
    {
      v6 = 0;
    }
    v8 = IntrusiveHashList<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::push_tail(
           &v3->m_ihlIntrusive,
           v6);
    if ( !v8 )
    {
      if ( v6 )
        operator delete(v6);
    }
    result = v8;
  }
  return result;
}

//----- (0068EDC0) --------------------------------------------------------  // acclient.c:678328
char __thiscall HashList<unsigned long,CInputMap *,1>::push_tail(HashList<unsigned long,CInputMap *,1> *this, const unsigned int *key, CInputMap *const *val)
{
  HashList<unsigned long,CInputMap *,1> *v3; // edi@1
  HashList<unsigned long,CInputMap *,1>::HashListData *v4; // edx@1
  void *v5; // eax@4
  HashList<unsigned long,CInputMap *,1>::HashListData *v6; // esi@5
  char result; // al@7
  char v8; // bl@9

  v3 = this;
  v4 = v3->m_ihlIntrusive.m_hash.m_buckets[*key % v3->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != *key )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = HashList<unsigned long,CInputMap *,1>::move_to_tail(this, key);
  }
  else
  {
LABEL_4:
    v5 = operator new(0x14u);
    if ( v5 )
    {
      *(_DWORD *)v5 = *key;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 4) = *val;
      v6 = (HashList<unsigned long,CInputMap *,1>::HashListData *)v5;
    }
    else
    {
      v6 = 0;
    }
    v8 = IntrusiveHashList<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::push_tail(
           &v3->m_ihlIntrusive,
           v6);
    if ( !v8 )
    {
      if ( v6 )
        operator delete(v6);
    }
    result = v8;
  }
  return result;
}

//----- (0068EE60) --------------------------------------------------------  // acclient.c:678382
void __thiscall CInputMap::Serialize(CInputMap *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  CInputMap *v3; // ebp@1
  unsigned int v4; // edi@1
  unsigned int v5; // eax@1
  int v6; // edi@6
  DLListData *v7; // ecx@7
  unsigned int v8; // eax@11
  int v9; // edi@15
  unsigned int i; // ebx@18
  Archive **v11; // eax@19
  QualifiedControl qc; // [sp+Ch] [bp-Ch]@10

  v2 = io_archive;
  v3 = this;
  v4 = this->m_listMappings.m_ihlIntrusive.m_hash.m_numElements;
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(v2, 4u);
  if ( v5 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v5 = v4;
    else
      v4 = *(_DWORD *)v5;
  }
  if ( v2->m_flags & 1 )
  {
    v6 = 0;
    if ( v3->m_listMappings.m_ihlIntrusive.m_hash.m_numElements > 0 )
    {
      v7 = v3->m_listMappings.m_ihlIntrusive.m_list.head_;
      if ( v7 )
        v6 = (int)&v7[-2];
      else
        v6 = 0;
    }
    for ( qc.m_metamode = (unsigned int)&v3->m_listMappings; v6; v6 = v9 - 16 )
    {
      QualifiedControl::Serialize((AC1Legacy::Vector3 *)v6, v2);
      Archive::CheckAlignment(v2, 4u);
      v8 = Archive::GetBytes(v2, 4u);
      if ( v8 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v8 = *(_DWORD *)(v6 + 24);
        else
          *(_DWORD *)(v6 + 24) = *(_DWORD *)v8;
      }
      v9 = *(_DWORD *)(v6 + 16);
      if ( !v9 )
        break;
    }
  }
  else
  {
    for ( i = 0; i < v4; ++i )
    {
      qc.m_key.m_dwKey = -1;
      qc.m_metamode = 0;
      qc.m_activation = 0;
      QualifiedControl::Serialize((AC1Legacy::Vector3 *)&qc, v2);
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
      HashList<QualifiedControl,unsigned long,1>::push_tail(
        (HashList<QualifiedControl,unsigned long,1> *)&v3->m_listMappings.m_ihlIntrusive,
        &qc,
        (const unsigned int *)&io_archive);
    }
  }
}

//----- (0068EF90) --------------------------------------------------------  // acclient.c:678464
char __thiscall CInputMap::AddMapping(CInputMap *this, unsigned int id, QualifiedControl key)
{
  CInputManager *v3; // esi@1
  CInputMap *v4; // ebp@1
  ICIDMVtbl *v5; // eax@2
  unsigned int v6; // ST04_4@2
  ListNode<unsigned long> *v7; // edi@3
  unsigned int v8; // eax@4
  ICIDMVtbl *v9; // edx@5
  SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> aConflictingControls; // [sp+14h] [bp-1Ch]@5
  List<unsigned long> listMapIDs; // [sp+20h] [bp-10h]@2

  v3 = ICIDM::s_cidm;
  v4 = this;
  if ( !ICIDM::s_cidm )
    return HashList<QualifiedControl,unsigned long,1>::push_tail(
             (HashList<QualifiedControl,unsigned long,1> *)&v4->m_listMappings.m_ihlIntrusive,
             &key,
             &id);
  v5 = ICIDM::s_cidm->vfptr;
  v6 = this->m_eInputMapID;
  listMapIDs.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
  listMapIDs._head = 0;
  listMapIDs._tail = 0;
  listMapIDs._num_elements = 0;
  if ( !v5->FindConflictingInputMaps((ICIDM *)ICIDM::s_cidm, v6, &listMapIDs) || (v7 = listMapIDs._head) == 0 )
  {
LABEL_9:
    listMapIDs.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
    List<SkillRecord *>::flush((List<SkillRecord *> *)&listMapIDs);
    return HashList<QualifiedControl,unsigned long,1>::push_tail(
             (HashList<QualifiedControl,unsigned long,1> *)&v4->m_listMappings.m_ihlIntrusive,
             &key,
             &id);
  }
  while ( 1 )
  {
    v8 = v7->data;
    if ( v4->m_eInputMapID != v7->data )
      break;
LABEL_8:
    v7 = v7->next;
    if ( !v7 )
      goto LABEL_9;
  }
  v9 = v3->vfptr;
  aConflictingControls.m_data = 0;
  aConflictingControls.m_sizeAndDeallocate = 0;
  aConflictingControls.m_num = 0;
  if ( !v9->FindConflictingControls((ICIDM *)v3, &key, v8, &aConflictingControls) )
  {
    if ( (aConflictingControls.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](aConflictingControls.m_data);
    goto LABEL_8;
  }
  if ( (aConflictingControls.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](aConflictingControls.m_data);
  listMapIDs.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&listMapIDs);
  return 0;
}
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);

//----- (0068F0A0) --------------------------------------------------------  // acclient.c:678528
char __thiscall CInputMap::Merge(CInputMap *this, CInputMap *rhs, HashTable<unsigned long,unsigned long,0> *hashMap, bool fForce)
{
  CInputMap *v4; // edi@1
  int v5; // esi@1
  DLListData *v6; // ecx@2
  _BYTE v7[12]; // ST04_12@6
  int v8; // esi@8
  char result; // al@10

  v4 = this;
  v5 = 0;
  if ( rhs->m_listMappings.m_ihlIntrusive.m_hash.m_numElements )
  {
    v6 = rhs->m_listMappings.m_ihlIntrusive.m_list.head_;
    if ( v6 )
      v5 = (int)&v6[-2];
    else
      v5 = 0;
  }
  if ( v5 )
  {
    while ( 1 )
    {
      *(_DWORD *)v7 = *(_DWORD *)v5;
      *(_QWORD *)&v7[4] = *(_QWORD *)(v5 + 4);
      if ( !CInputMap::AddMapping(v4, *(_DWORD *)(v5 + 24), *(QualifiedControl *)v7) && !fForce )
        break;
      v8 = *(_DWORD *)(v5 + 16);
      if ( v8 )
      {
        v5 = v8 - 16;
        if ( v5 )
          continue;
      }
      goto LABEL_10;
    }
    result = 0;
  }
  else
  {
LABEL_10:
    result = 1;
  }
  return result;
}

//----- (0068F120) --------------------------------------------------------  // acclient.c:678575
void __thiscall CMasterInputMap::~CMasterInputMap(CMasterInputMap *this)
{
  CMasterInputMap *v1; // edi@1
  void *v2; // eax@1
  void *v3; // eax@3
  int v4; // esi@7

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&CMasterInputMap::vftable;
  CMasterInputMap::Clear(this);
  IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents((IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *)&v1->m_hashSections);
  v2 = v1->m_hashSections.m_ihlIntrusive.m_hash.m_buckets;
  v1->m_hashSections.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>Vtbl *)&IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::vftable;
  if ( v2 != v1->m_hashSections.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
    operator delete[](v2);
  v1->m_hashSections.m_ihlIntrusive.m_hash.m_buckets = 0;
  v1->m_hashSections.m_ihlIntrusive.m_hash.m_firstInterestingBucket = 0;
  v1->m_hashSections.m_ihlIntrusive.m_hash.m_numBuckets = 0;
  v1->m_hashSections.m_ihlIntrusive.m_hash.m_numElements = 0;
  IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents((IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *)&v1->m_listMetaKeys);
  v3 = v1->m_listMetaKeys.m_ihlIntrusive.m_hash.m_buckets;
  v1->m_listMetaKeys.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::vftable;
  if ( v3 != v1->m_listMetaKeys.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
    operator delete[](v3);
  v1->m_listMetaKeys.m_ihlIntrusive.m_hash.m_buckets = 0;
  v1->m_listMetaKeys.m_ihlIntrusive.m_hash.m_firstInterestingBucket = 0;
  v1->m_listMetaKeys.m_ihlIntrusive.m_hash.m_numBuckets = 0;
  v1->m_listMetaKeys.m_ihlIntrusive.m_hash.m_numElements = 0;
  if ( (v1->m_rgDevices.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_rgDevices.m_data);
  v4 = (int)&v1->m_strName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 7FFFE4: using guessed type int (__thiscall *IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::vftable[2])(void *, char);
// 7FFFE8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::vftable)(void *, char);
// 800158: using guessed type __int32 (__stdcall *CMasterInputMap::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0068F1E0) --------------------------------------------------------  // acclient.c:678615
bool __thiscall CMasterInputMap::ReadMetaKeysFromFileNode(CMasterInputMap *this, PFileNode *i_pNode)
{
  PFileNode *v2; // esi@1
  CMasterInputMap *v3; // ebp@1
  unsigned int v4; // ebx@1
  bool result; // al@2
  int v6; // edi@4
  PSRefBufferCharData<char> *v7; // ecx@4
  signed int v8; // esi@7
  unsigned int v9; // ecx@7
  bool v10; // sf@9
  unsigned __int8 v11; // of@9
  PStringBase<char> v12; // [sp-8h] [bp-24h]@12
  unsigned int v13; // [sp-4h] [bp-20h]@11
  ControlSpecification key; // [sp+10h] [bp-Ch]@7
  unsigned int index; // [sp+14h] [bp-8h]@4
  int iLast; // [sp+18h] [bp-4h]@1

  v2 = i_pNode;
  v3 = this;
  v4 = 0;
  iLast = PFileNode::GetNumSubNodes(i_pNode);
  if ( iLast > 0 )
  {
    while ( 1 )
    {
      v6 = (int)v2->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, v4);
      index = 0;
      if ( !PFileNode::GetNameAsUInt32((PFileNode *)v6, v6, &index) || index < 1 || index > 0x20 )
        break;
      v8 = 1 << (32 - index);
      key.m_dwKey = -1;
      index = 1 << (32 - index);
      if ( !ControlSpecification::FromFileNode(&key, v6, (PFileNode *)v6)
        || v3->m_rgDevices.m_num <= (unsigned __int8)key.m_dwKey )
      {
        v13 = v9;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v13, "ERROR - Invalid device.\n");
        PFileNode::ReportError(v6, (PFileNode *)v6, (PStringBase<char>)v13);
        return 0;
      }
      HashList<ControlSpecification,unsigned long,1>::push_tail(&v3->m_listMetaKeys, &key, &index);
      ++v4;
      v11 = __OFSUB__(v4, iLast);
      v10 = ((v4 - iLast) & 0x80000000) != 0;
      v3->m_dwUsedMetaKeys |= v8;
      if ( !(v10 ^ v11) )
        return 1;
      v2 = i_pNode;
    }
    v13 = index;
    v12.m_charbuffer = v7;
    PStringBase<char>::PStringBase<char>(&v12, "ERROR - Invalid index %d, index must be between 1 and 32\n");
    PFileNode::ReportError(v6, (PFileNode *)v6, v12);
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0068F310) --------------------------------------------------------  // acclient.c:678679
CInputMap *__thiscall CMasterInputMap::CreateInputMap(CMasterInputMap *this, unsigned int id)
{
  unsigned int v2; // ebp@1
  CMasterInputMap *v3; // edi@1
  HashList<unsigned long,CInputMap *,1> *v4; // ebx@1
  unsigned int v5; // edx@1
  HashList<unsigned long,CInputMap *,1>::HashListData **v6; // eax@1
  CInputMap *v7; // ecx@1
  HashList<unsigned long,CInputMap *,1>::HashListData *v8; // eax@1
  void *v9; // eax@8
  void *v10; // esi@8
  CInputMap *result; // eax@11
  CInputMap *pMap; // [sp+Ch] [bp-4h]@11

  v2 = id;
  v3 = this;
  v4 = &this->m_hashSections;
  v5 = id % this->m_hashSections.m_ihlIntrusive.m_hash.m_numBuckets;
  v6 = this->m_hashSections.m_ihlIntrusive.m_hash.m_buckets;
  v7 = 0;
  v8 = v6[v5];
  if ( v8 )
  {
    while ( v8->m_hashKey != id )
    {
      v8 = v8->m_hashNext;
      if ( !v8 )
        goto LABEL_7;
    }
    if ( v8 )
      v7 = v8->m_data;
  }
LABEL_7:
  if ( v7 )
  {
    result = v7;
  }
  else
  {
    v9 = operator new(0x80u);
    v10 = v9;
    if ( v9 )
    {
      *(_DWORD *)v9 = v3;
      *((_DWORD *)v9 + 1) = v2;
      IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>(
        (IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *)((char *)v9 + 8),
        0);
      *((_DWORD *)v10 + 30) = 0;
      *((_DWORD *)v10 + 31) = 0;
    }
    else
    {
      v10 = 0;
    }
    pMap = (CInputMap *)v10;
    HashList<unsigned long,CInputMap *,1>::push_tail(v4, &id, &pMap);
    result = (CInputMap *)v10;
  }
  return result;
}

//----- (0068F3B0) --------------------------------------------------------  // acclient.c:678742
bool __userpurge CInputMap::FromFileNode@<al>(CInputMap *this@<ecx>, int a2@<edi>, PFileNode *i_pNode)
{
  PFileNode *v3; // ebx@1
  CInputMap *v4; // ebp@1
  int v5; // eax@2
  int v6; // ecx@2
  ReferenceCountTemplate<1048576,0>Vtbl *v7; // eax@5
  PFileNode *v8; // eax@5
  PFileNode *v9; // esi@5
  PSRefBufferCharData<char> *v10; // ecx@8
  ReferenceCountTemplate<1048576,0>Vtbl *v11; // edx@9
  PFileNode *v12; // eax@9
  ReferenceCountTemplate<1048576,0>Vtbl *v13; // eax@10
  int v14; // eax@10
  PSRefBufferCharData<char> *v15; // ecx@12
  ReferenceCountTemplate<1048576,0>Vtbl *v16; // edx@13
  PSRefBufferCharData<char> *v17; // ecx@14
  ActionMap *v18; // eax@18
  unsigned int v19; // eax@21
  unsigned int v20; // ebx@21
  unsigned int v21; // ebp@21
  bool result; // al@26
  PStringBase<char> v23; // [sp-Ch] [bp-5Ch]@20
  PStringBase<char> v24; // [sp-8h] [bp-58h]@12
  PStringBase<char> v25; // [sp-4h] [bp-54h]@5
  int v26; // [sp+10h] [bp-40h]@2
  PStringBase<char> o_name; // [sp+14h] [bp-3Ch]@14
  unsigned int eAction; // [sp+18h] [bp-38h]@6
  PStringBase<char> str; // [sp+1Ch] [bp-34h]@12
  PStringBase<char> strInputMap; // [sp+20h] [bp-30h]@20
  PStringBase<char> strAction; // [sp+24h] [bp-2Ch]@20
  CInputMap *v32; // [sp+28h] [bp-28h]@1
  PStringBase<char> fmt; // [sp+2Ch] [bp-24h]@23
  ControlSpecification key; // [sp+30h] [bp-20h]@8
  unsigned int dwMetaBits; // [sp+34h] [bp-1Ch]@10
  unsigned int cat; // [sp+38h] [bp-18h]@13
  int iNode; // [sp+3Ch] [bp-14h]@2
  int iNodes; // [sp+40h] [bp-10h]@2
  QualifiedControl qc; // [sp+44h] [bp-Ch]@21

  v3 = i_pNode;
  v4 = this;
  v32 = this;
  if ( i_pNode )
  {
    BYTE3(v26) = 1;
    v5 = PFileNode::GetNumSubNodes(i_pNode);
    v6 = 0;
    iNodes = v5;
    iNode = 0;
    if ( v5 > 0 )
    {
      while ( 1 )
      {
        v7 = v3->vfptr;
        v25.m_charbuffer = (PSRefBufferCharData<char> *)v6;
        v8 = (PFileNode *)v7[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, v6);
        v9 = v8;
        if ( !v8 )
          goto LABEL_25;
        eAction = 0;
        if ( !FileNodeUtils::GetNameAsEnum(v8, 0x19u, &eAction) )
        {
          BYTE3(v26) = 0;
          goto LABEL_25;
        }
        key.m_dwKey = -1;
        if ( PFileNode::GetNumSubNodes(v9)
          && (v11 = v9->vfptr,
              v25.m_charbuffer = 0,
              v12 = (PFileNode *)v11[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v9, 0),
              ControlSpecification::FromFileNode(&key, a2, v12)) )
        {
          v13 = v9->vfptr;
          v25.m_charbuffer = (PSRefBufferCharData<char> *)1;
          v14 = (int)v13[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v9, 1u);
          a2 = v14;
          dwMetaBits = 0;
          if ( v14 && !PFileNode::GetNameAsUInt32((PFileNode *)v14, v14, &dwMetaBits) )
          {
            PStringBase<char>::PStringBase<char>(&str);
            PFileNode::GetNameAsPString((PFileNode *)a2, a2, &str);
            v25.m_charbuffer = str.m_charbuffer;
            v24.m_charbuffer = v15;
            PStringBase<char>::PStringBase<char>(&v24, "ERROR - invalid MetaKey flags \"%s\"\n");
            PFileNode::ReportError(a2, (PFileNode *)a2, v24);
            BYTE3(v26) = 0;
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&str);
            goto LABEL_25;
          }
          cat = 3;
          v16 = v9->vfptr;
          v25.m_charbuffer = (PSRefBufferCharData<char> *)2;
          a2 = (int)v16[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v9, 2u);
          if ( a2 )
          {
            o_name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
            InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
            PFileNode::GetNameAsPString((PFileNode *)a2, a2, &o_name);
            if ( !StringToControlActivationType(&o_name, &cat) )
            {
              v25.m_charbuffer = o_name.m_charbuffer;
              v24.m_charbuffer = v17;
              PStringBase<char>::PStringBase<char>(&v24, "ERROR - invalid control range \"%s\"\n");
              PFileNode::ReportError(a2, (PFileNode *)a2, v24);
              BYTE3(v26) = 0;
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&o_name);
              goto LABEL_25;
            }
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&o_name);
          }
          if ( ICIDM::s_cidm )
          {
            v18 = (ActionMap *)((int (*)(void))ICIDM::s_cidm->vfptr->GetActionMap)();
            if ( v18 )
            {
              if ( !ActionMap::IsActionAllowedInInputMap(v18, eAction, v4->m_eInputMapID) )
              {
                PStringBase<char>::PStringBase<char>(&strAction);
                PFileNode::GetNameAsPString(v9, a2, &strAction);
                PStringBase<char>::PStringBase<char>(&strInputMap);
                EnumMapper::GetString(0x1Au, v4->m_eInputMapID, &strInputMap);
                v25.m_charbuffer = strInputMap.m_charbuffer;
                v24.m_charbuffer = strAction.m_charbuffer;
                v23.m_charbuffer = strAction.m_charbuffer;
                PStringBase<char>::PStringBase<char>(&v23, "Control '%s' is not allowed in this InputMap ('%s').");
                PFileNode::ReportError(a2, v9, v23);
                BYTE3(v26) = 0;
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strInputMap);
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strAction);
              }
            }
          }
          a2 = key.m_dwKey;
          qc.m_key.m_dwKey = key.m_dwKey;
          v19 = BitUtils::ReverseBits(dwMetaBits);
          v20 = cat;
          v21 = v19;
          qc.m_metamode = v19;
          qc.m_activation = cat;
          if ( CInputMap::VerifyActivationAndToggleType(v32, &qc, eAction, v9) )
          {
            v23.m_charbuffer = (PSRefBufferCharData<char> *)a2;
            v24.m_charbuffer = (PSRefBufferCharData<char> *)v21;
            v25.m_charbuffer = (PSRefBufferCharData<char> *)v20;
            if ( !CInputMap::AddMapping(v32, eAction, *(QualifiedControl *)&v23.m_charbuffer) )
            {
              PStringBase<char>::PStringBase<char>(&fmt);
              PFileNode::GetNameAsPString(v9, a2, &fmt);
              v25.m_charbuffer = fmt.m_charbuffer;
              v24.m_charbuffer = fmt.m_charbuffer;
              PStringBase<char>::PStringBase<char>(&v24, "ERROR - Control conflicts with another mapping \"%s\"\n");
              PFileNode::ReportError(a2, v9, v24);
              BYTE3(v26) = 0;
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&fmt);
            }
          }
          v3 = i_pNode;
        }
        else
        {
          v25.m_charbuffer = v10;
          PStringBase<char>::PStringBase<char>(&v25, "ERROR - invalid Control Specification\n");
          PFileNode::ReportError(a2, v9, v25);
          BYTE3(v26) = 0;
        }
LABEL_25:
        v6 = iNode++ + 1;
        if ( iNode >= iNodes )
          break;
        v4 = v32;
      }
    }
    result = BYTE3(v26);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0068F6D0) --------------------------------------------------------  // acclient.c:678925
CMasterInputMap *__thiscall CMasterInputMap::scalar_deleting_destructor(CMasterInputMap *this, unsigned int a2)
{
  CMasterInputMap *v2; // esi@1

  v2 = this;
  CMasterInputMap::~CMasterInputMap(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0068F6F0) --------------------------------------------------------  // acclient.c:678937
char __thiscall CMasterInputMap::Merge(CMasterInputMap *this, CMasterInputMap *rhs, bool fForce)
{
  unsigned int v3; // edi@1
  unsigned int v4; // edx@3
  DeviceKeyMapEntry *v5; // ebp@3
  signed int v6; // ecx@3
  int v7; // eax@4
  unsigned int v8; // ebx@11
  int v9; // eax@12
  unsigned int v10; // eax@13
  DeviceType v11; // ebp@15
  int v12; // eax@15
  void *v13; // eax@18
  void *v14; // esi@18
  HashTableData<unsigned long,unsigned long> **v15; // edx@20
  HashTableData<unsigned long,unsigned long> *v16; // eax@20
  int v17; // ebx@30
  DLListData *v18; // ecx@31
  unsigned int v19; // ecx@35
  HashTableData<unsigned long,unsigned long> *v20; // edx@35
  int v21; // ecx@41
  int v22; // edx@41
  HashList<ControlSpecification,unsigned long,1>::HashListData **v23; // eax@41
  HashList<ControlSpecification,unsigned long,1>::HashListData *v24; // edx@41
  int v25; // ebx@45
  int v26; // esi@47
  DLListData *v27; // ecx@48
  HashTableData<unsigned long,unsigned long> **v28; // eax@53
  bool v29; // zf@53
  CInputMap *v30; // ebx@56
  CInputMap *v31; // eax@56
  int v32; // esi@57
  char result; // al@61
  CMasterInputMap *v34; // [sp+10h] [bp-88h]@1
  int v35; // [sp+14h] [bp-84h]@2
  unsigned int uRHSIndex; // [sp+18h] [bp-80h]@1
  ControlSpecification adjustedKey; // [sp+1Ch] [bp-7Ch]@1
  void *v38; // [sp+20h] [bp-78h]@34
  HashTable<unsigned long,unsigned long,0> hashDeviceMapping; // [sp+24h] [bp-74h]@1

  v34 = this;
  hashDeviceMapping.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>(
    &hashDeviceMapping.m_intrusiveTable,
    0x17u);
  v3 = 0;
  adjustedKey.m_dwKey = rhs->m_rgDevices.m_num;
  uRHSIndex = 0;
  if ( adjustedKey.m_dwKey )
  {
    v35 = 0;
    do
    {
      v4 = v34->m_rgDevices.m_num;
      v5 = &rhs->m_rgDevices.m_data[v35];
      v6 = 0;
      if ( v4 )
      {
        v7 = (int)v34->m_rgDevices.m_data->guid.m_data4;
        while ( *(_DWORD *)(v7 - 8) != v5->guid.m_data1
             || *(_DWORD *)(v7 - 4) != *(_DWORD *)&v5->guid.m_data2
             || *(_DWORD *)v7 != *(_DWORD *)&v5->guid.m_data4[0]
             || *(_DWORD *)(v7 + 4) != *(_DWORD *)&v5->guid.m_data4[4] )
        {
          ++v6;
          v7 += 20;
          if ( v6 >= v4 )
            goto LABEL_10;
        }
      }
      else
      {
LABEL_10:
        v6 = -1;
      }
      v8 = v6;
      if ( v6 == -1 )
      {
        v8 = v34->m_rgDevices.m_num;
        v9 = v34->m_rgDevices.m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( v34->m_rgDevices.m_num < v9
          || (v10 = SmartArray<UIChildFramework *,1>::get_new_size(v9 + 1),
              SmartArray<DeviceKeyMapEntry,1>::grow(&v34->m_rgDevices, v10)) )
        {
          qmemcpy(
            &v34->m_rgDevices.m_data[v34->m_rgDevices.m_num],
            v5,
            sizeof(v34->m_rgDevices.m_data[v34->m_rgDevices.m_num]));
          v3 = uRHSIndex;
          ++v34->m_rgDevices.m_num;
        }
      }
      v11 = v5->dt;
      v12 = (int)&v34->m_rgDevices.m_data[v8];
      if ( *(_DWORD *)v12 != v11 )
      {
        if ( !fForce )
          goto LABEL_62;
        *(_DWORD *)v12 = v11;
      }
      v13 = operator new(0xCu);
      v14 = 0;
      if ( v13 )
      {
        *((_DWORD *)v13 + 1) = 0;
        *(_DWORD *)v13 = v3;
        *((_DWORD *)v13 + 2) = v8;
        v14 = v13;
      }
      v15 = &hashDeviceMapping.m_intrusiveTable.m_buckets[*(_DWORD *)v14
                                                        % hashDeviceMapping.m_intrusiveTable.m_numBuckets];
      v16 = *v15;
      if ( !*v15 )
        goto LABEL_25;
      while ( v16->m_hashKey != *(_DWORD *)v14 )
      {
        v16 = v16->m_hashNext;
        if ( !v16 )
          goto LABEL_25;
      }
      if ( v16 )
      {
        operator delete(v14);
      }
      else
      {
LABEL_25:
        *((_DWORD *)v14 + 1) = *v15;
        *v15 = (HashTableData<unsigned long,unsigned long> *)v14;
        if ( v15 < hashDeviceMapping.m_intrusiveTable.m_firstInterestingBucket )
          hashDeviceMapping.m_intrusiveTable.m_firstInterestingBucket = v15;
        ++hashDeviceMapping.m_intrusiveTable.m_numElements;
      }
      ++v3;
      uRHSIndex = v3;
      ++v35;
    }
    while ( v3 < adjustedKey.m_dwKey );
  }
  v17 = 0;
  if ( rhs->m_listMetaKeys.m_ihlIntrusive.m_hash.m_numElements )
  {
    v18 = rhs->m_listMetaKeys.m_ihlIntrusive.m_list.head_;
    if ( v18 )
      v17 = (int)&v18[-1];
    else
      v17 = 0;
  }
  v38 = &rhs->m_listMetaKeys;
  if ( v17 )
  {
    while ( 1 )
    {
      v19 = (unsigned __int8)*(_DWORD *)v17;
      v20 = hashDeviceMapping.m_intrusiveTable.m_buckets[v19 % hashDeviceMapping.m_intrusiveTable.m_numBuckets];
      if ( v20 )
      {
        while ( v20->m_hashKey != v19 )
        {
          v20 = v20->m_hashNext;
          if ( !v20 )
            goto LABEL_41;
        }
        if ( v20 )
          v19 = v20->m_data;
      }
LABEL_41:
      v21 = *(_DWORD *)v17 ^ (unsigned __int8)(*(_DWORD *)v17 ^ v19);
      v22 = v21 % v34->m_listMetaKeys.m_ihlIntrusive.m_hash.m_numBuckets;
      v23 = v34->m_listMetaKeys.m_ihlIntrusive.m_hash.m_buckets;
      adjustedKey.m_dwKey = v21;
      v24 = v23[v22];
      if ( !v24 )
        goto LABEL_44;
      while ( v24->m_hashKey.m_dwKey != v21 )
      {
        v24 = v24->m_hashNext;
        if ( !v24 )
          goto LABEL_44;
      }
      if ( v24 )
      {
        if ( v24->m_data != *(_DWORD *)(v17 + 16) && !fForce )
        {
          hashDeviceMapping.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
          IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&hashDeviceMapping.m_intrusiveTable);
          v28 = hashDeviceMapping.m_intrusiveTable.m_buckets;
          v29 = hashDeviceMapping.m_intrusiveTable.m_buckets == (HashTableData<unsigned long,unsigned long> **)hashDeviceMapping.m_intrusiveTable.m_aInplaceBuckets;
          goto LABEL_63;
        }
      }
      else
      {
LABEL_44:
        HashList<ControlSpecification,unsigned long,1>::push_tail(
          &v34->m_listMetaKeys,
          &adjustedKey,
          (const unsigned int *)(v17 + 16));
        v34->m_dwUsedMetaKeys |= *(_DWORD *)(v17 + 16);
      }
      v25 = *(_DWORD *)(v17 + 8);
      if ( v25 )
      {
        v17 = v25 - 8;
        if ( v17 )
          continue;
      }
      break;
    }
  }
  v26 = 0;
  if ( rhs->m_hashSections.m_ihlIntrusive.m_hash.m_numElements )
  {
    v27 = rhs->m_hashSections.m_ihlIntrusive.m_list.head_;
    if ( v27 )
      v26 = (int)&v27[-1];
    else
      v26 = 0;
  }
  v38 = &rhs->m_hashSections;
  if ( v26 )
  {
    while ( 1 )
    {
      v30 = *(CInputMap **)(v26 + 16);
      v31 = CMasterInputMap::CreateInputMap(v34, *(_DWORD *)v26);
      if ( !CInputMap::Merge(v31, v30, &hashDeviceMapping, fForce) )
        break;
      v32 = *(_DWORD *)(v26 + 8);
      if ( v32 )
      {
        v26 = v32 - 8;
        if ( v26 )
          continue;
      }
      goto LABEL_59;
    }
LABEL_62:
    hashDeviceMapping.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&hashDeviceMapping.m_intrusiveTable);
    v28 = hashDeviceMapping.m_intrusiveTable.m_buckets;
    v29 = hashDeviceMapping.m_intrusiveTable.m_buckets == (HashTableData<unsigned long,unsigned long> **)hashDeviceMapping.m_intrusiveTable.m_aInplaceBuckets;
LABEL_63:
    hashDeviceMapping.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable;
    if ( !v29 )
      operator delete[](v28);
    result = 0;
  }
  else
  {
LABEL_59:
    hashDeviceMapping.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&hashDeviceMapping.m_intrusiveTable);
    hashDeviceMapping.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable;
    if ( (HashTableData<unsigned long,unsigned long> **)hashDeviceMapping.m_intrusiveTable.m_buckets != hashDeviceMapping.m_intrusiveTable.m_aInplaceBuckets )
      operator delete[](hashDeviceMapping.m_intrusiveTable.m_buckets);
    result = 1;
  }
  return result;
}
// 79C9A8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable[3])(void *, char);
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);

//----- (0068FA90) --------------------------------------------------------  // acclient.c:679201
bool __userpurge CMasterInputMap::ReadBindingsFromFileNode@<al>(CMasterInputMap *this@<ecx>, PSRefBufferCharData<char> *a2@<edi>, PFileNode *i_pNode)
{
  PFileNode *v3; // esi@1
  CMasterInputMap *v4; // ebp@1
  bool result; // al@2
  ReferenceCountTemplate<1048576,0>Vtbl *v6; // eax@4
  PFileNode *v7; // esi@4
  PSRefBufferCharData<char> *v8; // ecx@5
  int v9; // edx@7
  HashList<unsigned long,CInputMap *,1> *v10; // ebx@8
  HashList<unsigned long,CInputMap *,1>::HashListData *v11; // eax@8
  unsigned int v12; // eax@12
  PSRefBufferCharData<char> *v13; // ecx@12
  PSRefBufferCharData<char> *v14; // ecx@14
  int v15; // eax@16
  bool v16; // al@18
  PStringBase<char> v17; // [sp-8h] [bp-30h]@5
  unsigned int v18; // [sp-4h] [bp-2Ch]@4
  bool ret; // [sp+13h] [bp-15h]@1
  unsigned int idInputMapName; // [sp+14h] [bp-14h]@4
  int iTable; // [sp+18h] [bp-10h]@1
  PStringBase<char> str; // [sp+1Ch] [bp-Ch]@5
  CMasterInputMap *v23; // [sp+20h] [bp-8h]@1
  int cInputMaps; // [sp+24h] [bp-4h]@1

  v3 = i_pNode;
  v4 = this;
  v23 = this;
  ret = 1;
  cInputMaps = PFileNode::GetNumSubNodes(i_pNode);
  iTable = 0;
  if ( cInputMaps > 0 )
  {
    while ( 1 )
    {
      v6 = v3->vfptr;
      v18 = iTable;
      v7 = (PFileNode *)v6[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, iTable);
      if ( FileNodeUtils::GetNameAsEnum(v7, 0x1Au, &idInputMapName) )
      {
        v10 = &v4->m_hashSections;
        v11 = v4->m_hashSections.m_ihlIntrusive.m_hash.m_buckets[idInputMapName
                                                               % v4->m_hashSections.m_ihlIntrusive.m_hash.m_numBuckets];
        if ( !v11 )
          goto LABEL_11;
        while ( v11->m_hashKey != idInputMapName )
        {
          v11 = v11->m_hashNext;
          if ( !v11 )
            goto LABEL_11;
        }
        if ( v11 )
        {
          str.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
          PFileNode::GetNameAsPString(v7, (int)a2, &str);
          a2 = str.m_charbuffer;
          v18 = (unsigned int)str.m_charbuffer;
          v17.m_charbuffer = v14;
          PStringBase<char>::PStringBase<char>(&v17, "ERROR - duplicate input map name \"%s\" found.");
          PFileNode::ReportError((int)a2, v7, v17);
          ret = 0;
          if ( !InterlockedDecrement((volatile LONG *)&a2[-1]) && a2 != (PSRefBufferCharData<char> *)20 )
          {
            v15 = *(_DWORD *)&a2[-2].m_data[12];
            v18 = 1;
            (*(void (__thiscall **)(char *, signed int))v15)(&a2[-2].m_data[12], 1);
          }
        }
        else
        {
LABEL_11:
          a2 = (PSRefBufferCharData<char> *)operator new(0x80u);
          if ( a2 )
          {
            v12 = idInputMapName;
            *(_DWORD *)&a2->m_data[0] = v4;
            v18 = 0;
            *(_DWORD *)&a2->m_data[4] = v12;
            IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>(
              (IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *)&a2->m_data[8],
              v18);
            *(_DWORD *)&a2[7].m_data[8] = 0;
            *(_DWORD *)&a2[7].m_data[12] = 0;
            v4 = v23;
            v13 = a2;
          }
          else
          {
            v13 = 0;
          }
          str.m_charbuffer = v13;
          v16 = CInputMap::FromFileNode((CInputMap *)v13, (int)a2, v7);
          ret &= v16;
          HashList<unsigned long,CInputMap *,1>::push_tail(v10, &idInputMapName, (CInputMap *const *)&str);
        }
      }
      else
      {
        str.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        PFileNode::GetNameAsPString(v7, (int)a2, &str);
        a2 = str.m_charbuffer;
        v18 = (unsigned int)str.m_charbuffer;
        v17.m_charbuffer = v8;
        PStringBase<char>::PStringBase<char>(&v17, "ERROR - invalid input map name \"%s\" found.");
        PFileNode::ReportError((int)a2, v7, v17);
        ret = 0;
        if ( !InterlockedDecrement((volatile LONG *)&a2[-1]) && a2 != (PSRefBufferCharData<char> *)20 )
        {
          v9 = *(_DWORD *)&a2[-2].m_data[12];
          v18 = 1;
          (*(void (__thiscall **)(char *, signed int))v9)(&a2[-2].m_data[12], 1);
        }
      }
      ++iTable;
      if ( iTable >= cInputMaps )
        break;
      v3 = i_pNode;
    }
    result = ret;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0068FC70) --------------------------------------------------------  // acclient.c:679331
char __thiscall CMasterInputMap::CopyInto(CMasterInputMap *this, DBObj *retval)
{
  InterfaceVtbl *v2; // eax@1
  CMasterInputMap *v3; // esi@1
  int v4; // ebx@2
  InterfaceVtbl *v5; // eax@5
  char *v6; // ecx@6

  v2 = retval[1].vfptr;
  v3 = this;
  if ( (PSRefBufferCharData<char> *)v2 != this->m_strName.m_charbuffer )
  {
    v4 = (int)&v2[-1].IUnknown_AddRef;
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1].IUnknown_Release) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = (InterfaceVtbl *)v3->m_strName.m_charbuffer;
    retval[1].vfptr = v5;
    InterlockedIncrement((volatile LONG *)&v5[-1].IUnknown_Release);
  }
  v6 = (char *)&retval[1].m_dataCategory;
  *(_DWORD *)v6 = v3->m_guidMap.m_data1;
  *((_DWORD *)v6 + 1) = *(_DWORD *)&v3->m_guidMap.m_data2;
  *((_DWORD *)v6 + 2) = *(_DWORD *)&v3->m_guidMap.m_data4[0];
  *((_DWORD *)v6 + 3) = *(_DWORD *)&v3->m_guidMap.m_data4[4];
  return CMasterInputMap::Merge((CMasterInputMap *)retval, v3, 0);
}

//----- (0068FCE0) --------------------------------------------------------  // acclient.c:679359
void __thiscall CMasterInputMap::Serialize(CMasterInputMap *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  CMasterInputMap *v3; // ebx@1
  unsigned int v4; // edi@1
  unsigned int v5; // eax@1
  int v6; // edi@6
  DLListData *v7; // edi@7
  unsigned int v8; // eax@11
  int v9; // edi@15
  unsigned int v10; // ebp@18
  Archive **v11; // eax@19
  unsigned int v12; // ebp@25
  Archive **v13; // eax@25
  unsigned int v14; // eax@30
  int v15; // ebx@30
  int v16; // edi@30
  int v17; // edi@31
  unsigned int v18; // eax@35
  int v19; // edi@39
  unsigned int *v20; // eax@43
  void *v21; // edi@47
  unsigned int v22; // eax@48
  void *v23; // eax@54
  unsigned int id; // [sp+10h] [bp-10h]@19
  CInputMap *pInputMap; // [sp+14h] [bp-Ch]@50
  unsigned int i; // [sp+18h] [bp-8h]@42
  HashList<ControlSpecification,unsigned long,1> *j; // [sp+1Ch] [bp-4h]@10

  v2 = io_archive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  PStringBase<char>::Serialize(&v3->m_strName, v2);
  Serializer::SerializePrimitive(&v3->m_guidMap, v2);
  SmartArray<DeviceKeyMapEntry,1>::Serialize(&v3->m_rgDevices, v2);
  v4 = v3->m_listMetaKeys.m_ihlIntrusive.m_hash.m_numElements;
  Archive::CheckAlignment(v2, 4u);
  v5 = Archive::GetBytes(v2, 4u);
  if ( v5 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v5 = v4;
    else
      v4 = *(_DWORD *)v5;
  }
  if ( v2->m_flags & 1 )
  {
    v6 = 0;
    if ( v3->m_listMetaKeys.m_ihlIntrusive.m_hash.m_numElements )
    {
      v7 = v3->m_listMetaKeys.m_ihlIntrusive.m_list.head_;
      if ( v7 )
        v6 = (int)&v7[-1];
      else
        v6 = 0;
    }
    for ( j = &v3->m_listMetaKeys; v6; v6 = v9 - 8 )
    {
      ControlSpecification::Serialize((ControlSpecification *)v6, v2);
      Archive::CheckAlignment(v2, 4u);
      v8 = Archive::GetBytes(v2, 4u);
      if ( v8 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v8 = *(_DWORD *)(v6 + 16);
        else
          *(_DWORD *)(v6 + 16) = *(_DWORD *)v8;
      }
      v9 = *(_DWORD *)(v6 + 8);
      if ( !v9 )
        break;
    }
  }
  else
  {
    v10 = 0;
    if ( v4 )
    {
      do
      {
        id = -1;
        ControlSpecification::Serialize((ControlSpecification *)&id, v2);
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
        HashList<ControlSpecification,unsigned long,1>::push_tail(
          &v3->m_listMetaKeys,
          (ControlSpecification *)&id,
          (const unsigned int *)&io_archive);
        ++v10;
      }
      while ( v10 < v4 );
    }
  }
  v12 = v3->m_hashSections.m_ihlIntrusive.m_hash.m_numElements;
  io_archive = (Archive *)v3->m_hashSections.m_ihlIntrusive.m_hash.m_numElements;
  Archive::CheckAlignment(v2, 4u);
  v13 = (Archive **)Archive::GetBytes(v2, 4u);
  if ( v13 )
  {
    if ( v2->m_flags & 1 )
    {
      *v13 = (Archive *)v12;
    }
    else
    {
      io_archive = *v13;
      v12 = (unsigned int)io_archive;
    }
  }
  if ( v2->m_flags & 1 )
  {
    v14 = v3->m_hashSections.m_ihlIntrusive.m_hash.m_numElements;
    v15 = (int)&v3->m_hashSections;
    v16 = 0;
    if ( v14 )
    {
      v17 = *(_DWORD *)(v15 + 112);
      if ( v17 )
        v16 = v17 - 8;
      else
        v16 = 0;
    }
    for ( j = (HashList<ControlSpecification,unsigned long,1> *)v15; v16; v16 = v19 - 8 )
    {
      Archive::CheckAlignment(v2, 4u);
      v18 = Archive::GetBytes(v2, 4u);
      if ( v18 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v18 = *(_DWORD *)v16;
        else
          *(_DWORD *)v16 = *(_DWORD *)v18;
      }
      CInputMap::Serialize(*(CInputMap **)(v16 + 16), v2);
      v19 = *(_DWORD *)(v16 + 8);
      if ( !v19 )
        break;
    }
  }
  else
  {
    i = 0;
    if ( v12 )
    {
      while ( 1 )
      {
        Archive::CheckAlignment(v2, 4u);
        v20 = (unsigned int *)Archive::GetBytes(v2, 4u);
        if ( v20 )
        {
          if ( v2->m_flags & 1 )
            *v20 = id;
          else
            id = *v20;
        }
        v21 = operator new(0x80u);
        if ( v21 )
        {
          v22 = id;
          *(_DWORD *)v21 = v3;
          *((_DWORD *)v21 + 1) = v22;
          IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>(
            (IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *)((char *)v21 + 8),
            0);
          *((_DWORD *)v21 + 30) = 0;
          *((_DWORD *)v21 + 31) = 0;
          v12 = (unsigned int)io_archive;
        }
        else
        {
          v21 = 0;
        }
        pInputMap = (CInputMap *)v21;
        CInputMap::Serialize((CInputMap *)v21, v2);
        if ( (v2->m_flags >> 2) & 1 )
          break;
        HashList<unsigned long,CInputMap *,1>::push_tail(&v3->m_hashSections, &id, &pInputMap);
        ++i;
        if ( i >= v12 )
          return;
      }
      if ( v21 )
      {
        IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::delete_contents((IntrusiveHashList<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1> *)((char *)v21 + 8));
        v23 = (void *)*((_DWORD *)v21 + 26);
        *((_DWORD *)v21 + 2) = IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::vftable;
        if ( v23 != (char *)v21 + 12 )
          operator delete[](v23);
        *((_DWORD *)v21 + 26) = 0;
        *((_DWORD *)v21 + 27) = 0;
        *((_DWORD *)v21 + 28) = 0;
        *((_DWORD *)v21 + 29) = 0;
        operator delete(v21);
      }
    }
  }
}
// 7FFFE0: using guessed type int (__thiscall *IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::vftable[3])(void *, char);

//----- (0068FFE0) --------------------------------------------------------  // acclient.c:679568
bool __thiscall CMasterInputMap::FromFileNode(CMasterInputMap *this, PFileNode *pRootNode)
{
  int v2; // edi@1
  PSRefBufferCharData<char> *v3; // ecx@1
  ReferenceCountTemplate<1048576,0>Vtbl *v5; // eax@4
  PFileNode *v6; // ebx@4
  PFileNode *v7; // eax@4
  PFileNode *v8; // eax@5
  PFileNode *v9; // eax@6
  PFileNode *v10; // eax@7
  PStringBase<char> v11; // [sp-4h] [bp-10h]@2

  v2 = (int)this;
  if ( PFileNode::GetNumSubNodes(pRootNode) != 4 )
  {
    v11.m_charbuffer = v3;
    PStringBase<char>::PStringBase<char>(
      &v11,
      "ERROR - must have exactly 4 parts (Name, Devices, MetaKeys, Bindings)\n");
    PFileNode::ReportError(v2, pRootNode, v11);
    return 0;
  }
  v5 = pRootNode->vfptr;
  v11.m_charbuffer = 0;
  v6 = (PFileNode *)((int (__thiscall *)(PFileNode *))v5[3].__vecDelDtor)(pRootNode);
  PFileNode::GetNameAsPString(v6, v2, (PStringBase<char> *)(v2 + 48));
  v7 = (PFileNode *)((int (__thiscall *)(PFileNode *, _DWORD, int))v6->vfptr[3].__vecDelDtor)(v6, 0, v2 + 52);
  if ( !CMasterInputMap::ReadGuidFromFileNode((CMasterInputMap *)v2, v2, v7, 0) )
    return 0;
  v8 = (PFileNode *)pRootNode->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)pRootNode, 1u);
  if ( !CMasterInputMap::ReadDevicesFromFileNode((CMasterInputMap *)v2, v8) )
    return 0;
  v9 = (PFileNode *)pRootNode->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)pRootNode, 2u);
  if ( !CMasterInputMap::ReadMetaKeysFromFileNode((CMasterInputMap *)v2, v9) )
    return 0;
  v10 = (PFileNode *)pRootNode->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)pRootNode, 3u);
  return CMasterInputMap::ReadBindingsFromFileNode((CMasterInputMap *)v2, (PSRefBufferCharData<char> *)v2, v10) != 0;
}

//----- (00715CD0) --------------------------------------------------------  // acclient.c:808840
int sub_715CD0()
{
  PStringBase<char>::PStringBase<char>(&PHeader_13, "PREPROC_HEADER");
  return atexit(sub_77FAE0);
}

//----- (00715CF0) --------------------------------------------------------  // acclient.c:808847
int sub_715CF0()
{
  PStringBase<char>::PStringBase<char>(&VertexArray_10, "VertexArray");
  return atexit(sub_77FB10);
}

//----- (00715D10) --------------------------------------------------------  // acclient.c:808854
int _E79_91()
{
  PStringBase<char>::PStringBase<char>(&BinaryVertexArray_10, "BinaryVertexArray");
  return atexit(_E80_88);
}

//----- (00715D30) --------------------------------------------------------  // acclient.c:808861
int _E82_56()
{
  PStringBase<char>::PStringBase<char>(&VertexType_11, "VertexType");
  return atexit(_E83_53);
}

//----- (00715D50) --------------------------------------------------------  // acclient.c:808868
int _E85_40()
{
  PStringBase<char>::PStringBase<char>(&VertexData_10, "VertexData");
  return atexit(_E86_33);
}

//----- (00715D70) --------------------------------------------------------  // acclient.c:808875
int _E88_30()
{
  PStringBase<char>::PStringBase<char>(&Vertex_10, "Vertex");
  return atexit(_E89_43);
}

//----- (00715D90) --------------------------------------------------------  // acclient.c:808882
int sub_715D90()
{
  PStringBase<char>::PStringBase<char>(&Index_21, "Index");
  return atexit(_E92_48);
}

//----- (00715DB0) --------------------------------------------------------  // acclient.c:808889
int _E94_39()
{
  PStringBase<char>::PStringBase<char>(&Origin_21, "P");
  return atexit(sub_77FC30);
}

//----- (00715DD0) --------------------------------------------------------  // acclient.c:808896
int sub_715DD0()
{
  PStringBase<char>::PStringBase<char>(&Normal_10, "N");
  return atexit(sub_77FC60);
}

//----- (00715DF0) --------------------------------------------------------  // acclient.c:808903
int sub_715DF0()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_21, "Diffuse");
  return atexit(sub_77FC90);
}

//----- (00715E10) --------------------------------------------------------  // acclient.c:808910
int sub_715E10()
{
  PStringBase<char>::PStringBase<char>(&Specular_21, "Specular");
  return atexit(sub_77FCC0);
}

//----- (00715E30) --------------------------------------------------------  // acclient.c:808917
int sub_715E30()
{
  PStringBase<char>::PStringBase<char>(&UVS_10, "UVS");
  return atexit(sub_77FCF0);
}

//----- (00715E50) --------------------------------------------------------  // acclient.c:808924
int _E109_87()
{
  PStringBase<char>::PStringBase<char>(&VectorS_10, "VectorS");
  return atexit(sub_77FD20);
}

//----- (00715E70) --------------------------------------------------------  // acclient.c:808931
int sub_715E70()
{
  PStringBase<char>::PStringBase<char>(&VectorT_10, "VectorT");
  return atexit(_E113_74);
}

//----- (00715E90) --------------------------------------------------------  // acclient.c:808938
int _E115_93()
{
  PStringBase<char>::PStringBase<char>(&VectorSxT_10, "VectorSxT");
  return atexit(_E116_66);
}

//----- (00715EB0) --------------------------------------------------------  // acclient.c:808945
int _E118_84()
{
  PStringBase<char>::PStringBase<char>(&Weights_10, "Weights");
  return atexit(_E119_92);
}

//----- (00715ED0) --------------------------------------------------------  // acclient.c:808952
int _E121_78()
{
  PStringBase<char>::PStringBase<char>(&Importance_10, "Importance");
  return atexit(sub_77FDE0);
}

//----- (00715EF0) --------------------------------------------------------  // acclient.c:808959
int _E124_75()
{
  PStringBase<char>::PStringBase<char>(&PhysMtl_10, "PhysMtl");
  return atexit(_E125_72);
}

//----- (00715F10) --------------------------------------------------------  // acclient.c:808966
int _E127_65()
{
  PStringBase<char>::PStringBase<char>(&Material_46, "Material");
  return atexit(_E128_70);
}

//----- (00715F30) --------------------------------------------------------  // acclient.c:808973
int _E130_58()
{
  PStringBase<char>::PStringBase<char>(&ID_24, "ID");
  return atexit(_E131_59);
}

//----- (00715F50) --------------------------------------------------------  // acclient.c:808980
int _E133_51()
{
  PStringBase<char>::PStringBase<char>(&FileName_10, "FileName");
  return atexit(_E134_43);
}

//----- (00715F70) --------------------------------------------------------  // acclient.c:808987
int _E136_35()
{
  PStringBase<char>::PStringBase<char>(&Polygon_21, "Polygon");
  return atexit(_E137_42);
}

//----- (00715F90) --------------------------------------------------------  // acclient.c:808994
int _E139_35()
{
  PStringBase<char>::PStringBase<char>(&ID_25, "ID");
  return atexit(_E140_36);
}

//----- (00715FB0) --------------------------------------------------------  // acclient.c:809001
int _E142_32()
{
  PStringBase<char>::PStringBase<char>(&Indices_16, "INDICES");
  return atexit(_E143_36);
}

//----- (00715FD0) --------------------------------------------------------  // acclient.c:809008
int _E145_34()
{
  PStringBase<char>::PStringBase<char>(&MaterialID_10, "MaterialID");
  return atexit(_E146_36);
}

//----- (00715FF0) --------------------------------------------------------  // acclient.c:809015
int _E148_33()
{
  PStringBase<char>::PStringBase<char>(&PhysMaterialID_10, "PhysMaterialID");
  return atexit(_E149_35);
}

//----- (00716010) --------------------------------------------------------  // acclient.c:809022
int _E151_31()
{
  PStringBase<char>::PStringBase<char>(&Markings_10, "Markings");
  return atexit(_E152_36);
}

//----- (00716030) --------------------------------------------------------  // acclient.c:809029
int _E154_32()
{
  PStringBase<char>::PStringBase<char>(&Material_47, "Material");
  return atexit(_E155_32);
}

//----- (00716050) --------------------------------------------------------  // acclient.c:809036
int _E157_29()
{
  PStringBase<char>::PStringBase<char>(&Index_22, "Index");
  return atexit(_E158_33);
}

//----- (00716070) --------------------------------------------------------  // acclient.c:809043
int _E160_32()
{
  PStringBase<char>::PStringBase<char>(&Filename_10, "Filename");
  return atexit(_E161_30);
}

//----- (00716090) --------------------------------------------------------  // acclient.c:809050
int _E163_25()
{
  PStringBase<char>::PStringBase<char>(&Surface_10, "Surface");
  return atexit(_E164_32);
}

//----- (007160B0) --------------------------------------------------------  // acclient.c:809057
int _E166_27()
{
  PStringBase<char>::PStringBase<char>(&CellPoly_10, "CellPoly");
  return atexit(_E167_28);
}

//----- (007160D0) --------------------------------------------------------  // acclient.c:809064
int _E169_25()
{
  PStringBase<char>::PStringBase<char>(&Sphere_13, "Sphere");
  return atexit(_E170_28);
}

//----- (007160F0) --------------------------------------------------------  // acclient.c:809071
int _E172_23()
{
  PStringBase<char>::PStringBase<char>(&Side_10, "Side");
  return atexit(_E173_23);
}

//----- (00716110) --------------------------------------------------------  // acclient.c:809078
int _E175_20()
{
  PStringBase<char>::PStringBase<char>(&Positive_10, "Positive");
  return atexit(_E176_25);
}

//----- (00716130) --------------------------------------------------------  // acclient.c:809085
int _E178_20()
{
  PStringBase<char>::PStringBase<char>(&Negative_10, "Negative");
  return atexit(_E179_24);
}

//----- (00716150) --------------------------------------------------------  // acclient.c:809092
int _E181_20()
{
  PStringBase<char>::PStringBase<char>(&Polygon_22, "PolygonIndex");
  return atexit(_E182_24);
}

//----- (00716170) --------------------------------------------------------  // acclient.c:809099
int _E184_18()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_21, "OtherCellMeshIndex");
  return atexit(_E185_21);
}

//----- (00716190) --------------------------------------------------------  // acclient.c:809106
int _E187_17()
{
  PStringBase<char>::PStringBase<char>(&CellPortal_10, "CellPortal");
  return atexit(_E188_22);
}

//----- (007161B0) --------------------------------------------------------  // acclient.c:809113
int _E190_18()
{
  PStringBase<char>::PStringBase<char>(&Portal_13, "PortalIndex");
  return atexit(_E191_21);
}

//----- (007161D0) --------------------------------------------------------  // acclient.c:809120
int _E193_17()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_22, "OtherCellID");
  return atexit(_E194_28);
}

//----- (007161F0) --------------------------------------------------------  // acclient.c:809127
int _E196_24()
{
  PStringBase<char>::PStringBase<char>(&OtherPortal_10, "OtherPortalIndex");
  return atexit(_E197_18);
}

//----- (00716210) --------------------------------------------------------  // acclient.c:809134
int _E199_16()
{
  PStringBase<char>::PStringBase<char>(&ExactMatch_10, "ExactMatch");
  return atexit(_E200_22);
}

//----- (00716230) --------------------------------------------------------  // acclient.c:809141
int _E202_20()
{
  PStringBase<char>::PStringBase<char>(&StabList_10, "StabList");
  return atexit(_E203_21);
}

//----- (00716250) --------------------------------------------------------  // acclient.c:809148
int _E205_18()
{
  PStringBase<char>::PStringBase<char>(&Period_10, "Period");
  return atexit(_E206_25);
}

//----- (00716270) --------------------------------------------------------  // acclient.c:809155
int _E208_22()
{
  PStringBase<char>::PStringBase<char>(&GrannyAnimation_10, "GrannyAnimation");
  return atexit(_E209_19);
}

//----- (00716290) --------------------------------------------------------  // acclient.c:809162
int _E211_17()
{
  PStringBase<char>::PStringBase<char>(&Transform_10, "Transform");
  return atexit(_E212_22);
}

//----- (007162B0) --------------------------------------------------------  // acclient.c:809169
int _E214_19()
{
  PStringBase<char>::PStringBase<char>(&Scale_32, "Scale");
  return atexit(_E215_19);
}

//----- (007162D0) --------------------------------------------------------  // acclient.c:809176
int _E217_16()
{
  PStringBase<char>::PStringBase<char>(&Weight_10, "Weight");
  return atexit(_E218_19);
}

//----- (007162F0) --------------------------------------------------------  // acclient.c:809183
int _E220_16()
{
  PStringBase<char>::PStringBase<char>(&Offset_10, "Offset");
  return atexit(_E221_19);
}

//----- (00716310) --------------------------------------------------------  // acclient.c:809190
int _E223_17()
{
  PStringBase<char>::PStringBase<char>(&Quaternion_11, "Quaternion");
  return atexit(_E224_19);
}

//----- (00716330) --------------------------------------------------------  // acclient.c:809197
int _E226_16()
{
  PStringBase<char>::PStringBase<char>(&Rotation_21, "Rotation");
  return atexit(_E227_19);
}

//----- (00716350) --------------------------------------------------------  // acclient.c:809204
int _E229_17()
{
  PStringBase<char>::PStringBase<char>(&STime_10, "STime");
  return atexit(_E230_20);
}

//----- (00716370) --------------------------------------------------------  // acclient.c:809211
int _E232_17()
{
  PStringBase<char>::PStringBase<char>(&PhysicsSplines_10, "PhysicsSplines");
  return atexit(_E233_19);
}

//----- (00716390) --------------------------------------------------------  // acclient.c:809218
int _E235_17()
{
  PStringBase<char>::PStringBase<char>(&BoneOpacities_10, "BoneOpacities");
  return atexit(_E236_18);
}

//----- (007163B0) --------------------------------------------------------  // acclient.c:809225
int _E238_15()
{
  PStringBase<char>::PStringBase<char>(&LowPt_10, "LowPoint");
  return atexit(_E239_18);
}

//----- (007163D0) --------------------------------------------------------  // acclient.c:809232
int _E241_15()
{
  PStringBase<char>::PStringBase<char>(&Radius_10, "Radius");
  return atexit(_E242_18);
}

//----- (007163F0) --------------------------------------------------------  // acclient.c:809239
int _E244_15()
{
  PStringBase<char>::PStringBase<char>(&Height_10, "Height");
  return atexit(_E245_17);
}

//----- (00716410) --------------------------------------------------------  // acclient.c:809246
int _E247_14()
{
  PStringBase<char>::PStringBase<char>(&Texture2D_10, "Texture2D");
  return atexit(_E248_17);
}

//----- (00716430) --------------------------------------------------------  // acclient.c:809253
int _E250_14()
{
  PStringBase<char>::PStringBase<char>(&Texture3D_10, "Texture3D");
  return atexit(_E251_16);
}

//----- (00716450) --------------------------------------------------------  // acclient.c:809260
int _E253_14()
{
  PStringBase<char>::PStringBase<char>(&TextureCube_10, "TextureCube");
  return atexit(_E254_17);
}

//----- (00716470) --------------------------------------------------------  // acclient.c:809267
int _E256_14()
{
  PStringBase<char>::PStringBase<char>(&TextureMovie2D_10, "TextureMovie2D");
  return atexit(_E257_15);
}

//----- (00716490) --------------------------------------------------------  // acclient.c:809274
int _E259_15()
{
  PStringBase<char>::PStringBase<char>(&MovieFileName_10, "MovieFile");
  return atexit(_E260_16);
}

//----- (007164B0) --------------------------------------------------------  // acclient.c:809281
int _E262_15()
{
  PStringBase<char>::PStringBase<char>(&MovieFramesPerSecond_10, "MovieFPS");
  return atexit(_E263_15);
}

//----- (007164D0) --------------------------------------------------------  // acclient.c:809288
int _E265_15()
{
  PStringBase<char>::PStringBase<char>(&Levels_10, "Levels");
  return atexit(_E266_15);
}

//----- (007164F0) --------------------------------------------------------  // acclient.c:809295
int _E268_14()
{
  PStringBase<char>::PStringBase<char>(&stru_8F7F70, "Instance");
  return atexit(_E269_14);
}

//----- (00716510) --------------------------------------------------------  // acclient.c:809302
int _E271_13()
{
  PStringBase<char>::PStringBase<char>(&Material_48, "Material");
  return atexit(_E272_13);
}

//----- (00716530) --------------------------------------------------------  // acclient.c:809309
int _E274_13()
{
  PStringBase<char>::PStringBase<char>(&MaterialType_10, "MaterialType");
  return atexit(_E275_13);
}

//----- (00716550) --------------------------------------------------------  // acclient.c:809316
int _E277_13()
{
  PStringBase<char>::PStringBase<char>(&Modifier_10, "Modifier");
  return atexit(_E278_13);
}

//----- (00716570) --------------------------------------------------------  // acclient.c:809323
int _E280_12()
{
  PStringBase<char>::PStringBase<char>(&AllowStencilShadows_10, "AllowStencilShadows");
  return atexit(_E281_13);
}

//----- (00716590) --------------------------------------------------------  // acclient.c:809330
int _E283_12()
{
  PStringBase<char>::PStringBase<char>(&DiscardGeometry_10, "DiscardGeometry");
  return atexit(_E284_11);
}

//----- (007165B0) --------------------------------------------------------  // acclient.c:809337
int _E286_11()
{
  PStringBase<char>::PStringBase<char>(&stru_8F7F88, "Material");
  return atexit(_E287_12);
}

//----- (007165D0) --------------------------------------------------------  // acclient.c:809344
int _E289_10()
{
  PStringBase<char>::PStringBase<char>(&SortMode_10, "SortMode");
  return atexit(_E290_11);
}

//----- (007165F0) --------------------------------------------------------  // acclient.c:809351
int _E292_11()
{
  PStringBase<char>::PStringBase<char>(&SortMode_None_10, "None");
  return atexit(_E293_10);
}

//----- (00716610) --------------------------------------------------------  // acclient.c:809358
int _E295_10()
{
  PStringBase<char>::PStringBase<char>(&SortMode_Triangle_10, "Triangle");
  return atexit(_E296_11);
}

//----- (00716630) --------------------------------------------------------  // acclient.c:809365
int _E298_11()
{
  PStringBase<char>::PStringBase<char>(&stru_8F7F98, "Modifier");
  return atexit(_E299_9);
}

//----- (00716650) --------------------------------------------------------  // acclient.c:809372
int _E301_9()
{
  PStringBase<char>::PStringBase<char>(&stru_8F7F9C, "Property");
  return atexit(_E302_10);
}

//----- (00716670) --------------------------------------------------------  // acclient.c:809379
int _E304_10()
{
  PStringBase<char>::PStringBase<char>(&DataType_DATA_10, "Data");
  return atexit(_E305_9);
}

//----- (00716690) --------------------------------------------------------  // acclient.c:809386
int _E307_9()
{
  PStringBase<char>::PStringBase<char>(&DataType_WAVEFORM_10, "Waveform");
  return atexit(_E308_10);
}

//----- (007166B0) --------------------------------------------------------  // acclient.c:809393
int _E310_10()
{
  PStringBase<char>::PStringBase<char>(&DataType_COLOR_10, "Color");
  return atexit(_E311_9);
}

//----- (007166D0) --------------------------------------------------------  // acclient.c:809400
int _E313_9()
{
  PStringBase<char>::PStringBase<char>(&DataType_TEXTURE_10, "Texture");
  return atexit(_E314_10);
}

//----- (007166F0) --------------------------------------------------------  // acclient.c:809407
int _E316_10()
{
  PStringBase<char>::PStringBase<char>(&DataType_BOOL_10, "Bool");
  return atexit(_E317_9);
}

//----- (00716710) --------------------------------------------------------  // acclient.c:809414
int _E319_9()
{
  PStringBase<char>::PStringBase<char>(&stru_8F7FB4, "Layer");
  return atexit(_E320_10);
}

//----- (00716730) --------------------------------------------------------  // acclient.c:809421
int _E322_9()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTranslate_10, "UVTranslate");
  return atexit(_E323_8);
}

//----- (00716750) --------------------------------------------------------  // acclient.c:809428
int _E325_8()
{
  PStringBase<char>::PStringBase<char>(&modType_UVRotate_10, "UVRotate");
  return atexit(_E326_9);
}

//----- (00716770) --------------------------------------------------------  // acclient.c:809435
int _E328_9()
{
  PStringBase<char>::PStringBase<char>(&modType_UVScale_10, "UVScale");
  return atexit(_E329_8);
}

//----- (00716790) --------------------------------------------------------  // acclient.c:809442
int _E331_8()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTransform_10, "UVTransform");
  return atexit(_E332_9);
}

//----- (007167B0) --------------------------------------------------------  // acclient.c:809449
int _E334_8()
{
  PStringBase<char>::PStringBase<char>(&TrueFlags_10, "TrueFlags");
  return atexit(_E335_8);
}

//----- (007167D0) --------------------------------------------------------  // acclient.c:809456
int _E337_8()
{
  PStringBase<char>::PStringBase<char>(&FalseFlags_10, "FalseFlags");
  return atexit(_E338_8);
}

//----- (007167F0) --------------------------------------------------------  // acclient.c:809463
int _E340_8()
{
  PStringBase<char>::PStringBase<char>(&RenderPass_10, "RenderPass");
  return atexit(_E341_8);
}

//----- (00716810) --------------------------------------------------------  // acclient.c:809470
int _E343_5()
{
  PStringBase<char>::PStringBase<char>(&Blend_10, "Blend");
  return atexit(_E344_5);
}

//----- (00716830) --------------------------------------------------------  // acclient.c:809477
int _E346_5()
{
  PStringBase<char>::PStringBase<char>(&DepthTest_10, "DepthTest");
  return atexit(_E347_5);
}

//----- (00716850) --------------------------------------------------------  // acclient.c:809484
int _E349_5()
{
  PStringBase<char>::PStringBase<char>(&DepthWrite_10, "DepthWrite");
  return atexit(_E350_5);
}

//----- (00716870) --------------------------------------------------------  // acclient.c:809491
int _E352_5()
{
  PStringBase<char>::PStringBase<char>(&CullMode_10, "CullMode");
  return atexit(_E353_5);
}

//----- (00716890) --------------------------------------------------------  // acclient.c:809498
int _E355_5()
{
  PStringBase<char>::PStringBase<char>(&DepthFog_10, "DepthFog");
  return atexit(_E356_5);
}

//----- (007168B0) --------------------------------------------------------  // acclient.c:809505
int _E358_5()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestMode_10, "AlphaTestMode");
  return atexit(_E359_5);
}

//----- (007168D0) --------------------------------------------------------  // acclient.c:809512
int _E361_5()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestRef_10, "AlphaTestRef");
  return atexit(_E362_5);
}

//----- (007168F0) --------------------------------------------------------  // acclient.c:809519
int _E364_5()
{
  PStringBase<char>::PStringBase<char>(&FFUseLighting_10, "FFUseLighting");
  return atexit(_E365_5);
}

//----- (00716910) --------------------------------------------------------  // acclient.c:809526
int _E367_5()
{
  PStringBase<char>::PStringBase<char>(&FFUseDyeColorInTFactor_10, "FFUseDyeColorInTFactor");
  return atexit(_E368_5);
}

//----- (00716930) --------------------------------------------------------  // acclient.c:809533
int _E370_5()
{
  PStringBase<char>::PStringBase<char>(&FFUseSpecularLighting_10, "FFUseSpecularLighting");
  return atexit(_E371_5);
}

//----- (00716950) --------------------------------------------------------  // acclient.c:809540
int _E373_5()
{
  PStringBase<char>::PStringBase<char>(&FFUseDistanceFog_10, "FFUseDistanceFog");
  return atexit(_E374_5);
}

//----- (00716970) --------------------------------------------------------  // acclient.c:809547
int _E376_5()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexDiffuse_10, "FFUseVertexDiffuse");
  return atexit(_E377_5);
}

//----- (00716990) --------------------------------------------------------  // acclient.c:809554
int _E379_5()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexSpecular_10, "FFUseVertexSpecular");
  return atexit(_E380_5);
}

//----- (007169B0) --------------------------------------------------------  // acclient.c:809561
int _E382_5()
{
  PStringBase<char>::PStringBase<char>(&ShaderSupportsDynamicLights_10, "ShaderSupportsDynamicLights");
  return atexit(_E383_5);
}

//----- (007169D0) --------------------------------------------------------  // acclient.c:809568
int _E385_5()
{
  PStringBase<char>::PStringBase<char>(&UsesTransparency_10, "UsesTransparency");
  return atexit(_E386_5);
}

//----- (007169F0) --------------------------------------------------------  // acclient.c:809575
int _E388_5()
{
  PStringBase<char>::PStringBase<char>(&Ambient_10, "Ambient");
  return atexit(_E389_5);
}

//----- (00716A10) --------------------------------------------------------  // acclient.c:809582
int _E391_5()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_22, "Diffuse");
  return atexit(_E392_5);
}

//----- (00716A30) --------------------------------------------------------  // acclient.c:809589
int _E394_5()
{
  PStringBase<char>::PStringBase<char>(&Specular_22, "Specular");
  return atexit(_E395_5);
}

//----- (00716A50) --------------------------------------------------------  // acclient.c:809596
int _E397_5()
{
  PStringBase<char>::PStringBase<char>(&SpecularPower_10, "SpecularPower");
  return atexit(_E398_5);
}

//----- (00716A70) --------------------------------------------------------  // acclient.c:809603
int _E400_5()
{
  PStringBase<char>::PStringBase<char>(&Dye_10, "Dye");
  return atexit(_E401_5);
}

//----- (00716A90) --------------------------------------------------------  // acclient.c:809610
int _E403_5()
{
  PStringBase<char>::PStringBase<char>(&Emissive_10, "Emissive");
  return atexit(_E404_5);
}

//----- (00716AB0) --------------------------------------------------------  // acclient.c:809617
int _E406_5()
{
  PStringBase<char>::PStringBase<char>(&VertexFormat_10, "VertexFormat");
  return atexit(_E407_5);
}

//----- (00716AD0) --------------------------------------------------------  // acclient.c:809624
int _E409_5()
{
  PStringBase<char>::PStringBase<char>(&VertexShader_10, "VertexShader");
  return atexit(_E410_5);
}

//----- (00716AF0) --------------------------------------------------------  // acclient.c:809631
int _E412_5()
{
  PStringBase<char>::PStringBase<char>(&PixelShader_10, "PixelShader");
  return atexit(_E413_5);
}

//----- (00716B10) --------------------------------------------------------  // acclient.c:809638
int _E415_5()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_NONE_10, "None");
  return atexit(_E416_5);
}

//----- (00716B30) --------------------------------------------------------  // acclient.c:809645
int _E418_5()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_REFLECTIONS_10, "Reflections");
  return atexit(_E419_5);
}

//----- (00716B50) --------------------------------------------------------  // acclient.c:809652
int _E421_5()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_VIDEOPOST_10, "VideoPost");
  return atexit(_E422_5);
}

//----- (00716B70) --------------------------------------------------------  // acclient.c:809659
int _E424_5()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_HIGHDETAIL_10, "HighDetail");
  return atexit(_E425_5);
}

//----- (00716B90) --------------------------------------------------------  // acclient.c:809666
int _E427_5()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_SPECULAR_10, "Specular");
  return atexit(_E428_5);
}

//----- (00716BB0) --------------------------------------------------------  // acclient.c:809673
int _E430_5()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS1_10, "Class1");
  return atexit(_E431_5);
}

//----- (00716BD0) --------------------------------------------------------  // acclient.c:809680
int _E433_5()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS2_10, "Class2");
  return atexit(_E434_5);
}

//----- (00716BF0) --------------------------------------------------------  // acclient.c:809687
int _E436_5()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS3_10, "Class3");
  return atexit(_E437_5);
}

//----- (00716C10) --------------------------------------------------------  // acclient.c:809694
int _E439_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_Default_10, "Default");
  return atexit(_E440_5);
}

//----- (00716C30) --------------------------------------------------------  // acclient.c:809701
int _E442_5()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_DirectionalLightDiffuseAndSpecular_10,
    "DirectionalLightDiffuseAndSpecular");
  return atexit(_E443_5);
}

//----- (00716C50) --------------------------------------------------------  // acclient.c:809710
int _E445_5()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_PointLightDiffuseAndSpecular_10,
    "PointLightDiffuseAndSpecular");
  return atexit(_E446_5);
}

//----- (00716C70) --------------------------------------------------------  // acclient.c:809719
int _E448_5()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_PointLightDiffuseAndSpecularProjector_10,
    "PointLightDiffuseAndSpecularProjector");
  return atexit(_E449_5);
}

//----- (00716C90) --------------------------------------------------------  // acclient.c:809728
int _E451_5()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_10,
    "AmbientLight_DirectionalLightDiffuseAndSpecular");
  return atexit(_E452_5);
}

//----- (00716CB0) --------------------------------------------------------  // acclient.c:809737
int _E454_5()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_10,
    "AmbientLight_PointLightDiffuseAndSpecular");
  return atexit(_E455_5);
}

//----- (00716CD0) --------------------------------------------------------  // acclient.c:809746
int _E457_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_DistanceFog_10, "DistanceFog");
  return atexit(_E458_5);
}

//----- (00716CF0) --------------------------------------------------------  // acclient.c:809753
int _E460_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_FixedFunctionGlow_10, "FFGlow");
  return atexit(_E461_5);
}

//----- (00716D10) --------------------------------------------------------  // acclient.c:809760
int _E463_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_ShaderGlow_10, "ShaderGlow");
  return atexit(_E464_5);
}

//----- (00716D30) --------------------------------------------------------  // acclient.c:809767
int _E466_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_LandscapeShadowMap_10, "LandscapeShadowMap");
  return atexit(_E467_5);
}

//----- (00716D50) --------------------------------------------------------  // acclient.c:809774
int _E469_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AlphaBlend_10, "AlphaBlend");
  return atexit(_E470_5);
}

//----- (00716D70) --------------------------------------------------------  // acclient.c:809781
int _E472_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_10, "AL_0DL_0PL");
  return atexit(_E473_5);
}

//----- (00716D90) --------------------------------------------------------  // acclient.c:809788
int _E475_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_10, "AL_0DL_1PL");
  return atexit(_E476_5);
}

//----- (00716DB0) --------------------------------------------------------  // acclient.c:809795
int _E478_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_10, "AL_0DL_2PL");
  return atexit(_E479_5);
}

//----- (00716DD0) --------------------------------------------------------  // acclient.c:809802
int _E481_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_10, "AL_0DL_3PL");
  return atexit(_E482_5);
}

//----- (00716DF0) --------------------------------------------------------  // acclient.c:809809
int _E484_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_10, "AL_0DL_4PL");
  return atexit(_E485_5);
}

//----- (00716E10) --------------------------------------------------------  // acclient.c:809816
int _E487_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_10, "AL_0DL_5PL");
  return atexit(_E488_5);
}

//----- (00716E30) --------------------------------------------------------  // acclient.c:809823
int _E490_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_10, "AL_0DL_6PL");
  return atexit(_E491_5);
}

//----- (00716E50) --------------------------------------------------------  // acclient.c:809830
int _E493_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_10, "AL_0DL_7PL");
  return atexit(_E494_5);
}

//----- (00716E70) --------------------------------------------------------  // acclient.c:809837
int _E496_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_10, "AL_0DL_8PL");
  return atexit(_E497_5);
}

//----- (00716E90) --------------------------------------------------------  // acclient.c:809844
int _E499_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_10, "AL_1DL_0PL");
  return atexit(_E500_5);
}

//----- (00716EB0) --------------------------------------------------------  // acclient.c:809851
int _E502_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_10, "AL_1DL_1PL");
  return atexit(_E503_5);
}

//----- (00716ED0) --------------------------------------------------------  // acclient.c:809858
int _E505_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_10, "AL_1DL_2PL");
  return atexit(_E506_5);
}

//----- (00716EF0) --------------------------------------------------------  // acclient.c:809865
int _E508_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_10, "AL_1DL_3PL");
  return atexit(_E509_5);
}

//----- (00716F10) --------------------------------------------------------  // acclient.c:809872
int _E511_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_10, "AL_1DL_4PL");
  return atexit(_E512_5);
}

//----- (00716F30) --------------------------------------------------------  // acclient.c:809879
int _E514_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_10, "AL_1DL_5PL");
  return atexit(_E515_5);
}

//----- (00716F50) --------------------------------------------------------  // acclient.c:809886
int _E517_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_10, "AL_1DL_6PL");
  return atexit(_E518_5);
}

//----- (00716F70) --------------------------------------------------------  // acclient.c:809893
int _E520_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_10, "AL_1DL_7PL");
  return atexit(_E521_5);
}

//----- (00716F90) --------------------------------------------------------  // acclient.c:809900
int _E523_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_Fog_10, "AL_0DL_0PL_Fog");
  return atexit(_E524_5);
}

//----- (00716FB0) --------------------------------------------------------  // acclient.c:809907
int _E526_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_Fog_10, "AL_0DL_1PL_Fog");
  return atexit(_E527_5);
}

//----- (00716FD0) --------------------------------------------------------  // acclient.c:809914
int _E529_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_Fog_10, "AL_0DL_2PL_Fog");
  return atexit(_E530_5);
}

//----- (00716FF0) --------------------------------------------------------  // acclient.c:809921
int _E532_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_Fog_10, "AL_0DL_3PL_Fog");
  return atexit(_E533_5);
}

//----- (00717010) --------------------------------------------------------  // acclient.c:809928
int _E535_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_Fog_10, "AL_0DL_4PL_Fog");
  return atexit(_E536_5);
}

//----- (00717030) --------------------------------------------------------  // acclient.c:809935
int _E538_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_Fog_10, "AL_0DL_5PL_Fog");
  return atexit(_E539_5);
}

//----- (00717050) --------------------------------------------------------  // acclient.c:809942
int _E541_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_Fog_10, "AL_0DL_6PL_Fog");
  return atexit(_E542_5);
}

//----- (00717070) --------------------------------------------------------  // acclient.c:809949
int _E544_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_Fog_10, "AL_0DL_7PL_Fog");
  return atexit(_E545_5);
}

//----- (00717090) --------------------------------------------------------  // acclient.c:809956
int _E547_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_Fog_10, "AL_0DL_8PL_Fog");
  return atexit(_E548_5);
}

//----- (007170B0) --------------------------------------------------------  // acclient.c:809963
int _E550_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_Fog_10, "AL_1DL_0PL_Fog");
  return atexit(_E551_5);
}

//----- (007170D0) --------------------------------------------------------  // acclient.c:809970
int _E553_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_Fog_10, "AL_1DL_1PL_Fog");
  return atexit(_E554_5);
}

//----- (007170F0) --------------------------------------------------------  // acclient.c:809977
int _E556_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_Fog_10, "AL_1DL_2PL_Fog");
  return atexit(_E557_5);
}

//----- (00717110) --------------------------------------------------------  // acclient.c:809984
int _E559_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_Fog_10, "AL_1DL_3PL_Fog");
  return atexit(_E560_5);
}

//----- (00717130) --------------------------------------------------------  // acclient.c:809991
int _E562_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_Fog_10, "AL_1DL_4PL_Fog");
  return atexit(_E563_5);
}

//----- (00717150) --------------------------------------------------------  // acclient.c:809998
int _E565_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_Fog_10, "AL_1DL_5PL_Fog");
  return atexit(_E566_5);
}

//----- (00717170) --------------------------------------------------------  // acclient.c:810005
int _E568_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_Fog_10, "AL_1DL_6PL_Fog");
  return atexit(_E569_5);
}

//----- (00717190) --------------------------------------------------------  // acclient.c:810012
int _E571_5()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_Fog_10, "AL_1DL_7PL_Fog");
  return atexit(_E572_5);
}

//----- (007171B0) --------------------------------------------------------  // acclient.c:810019
int _E574_5()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ZERO_10, "Zero");
  return atexit(_E575_5);
}

//----- (007171D0) --------------------------------------------------------  // acclient.c:810026
int _E577_5()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ONE_10, "One");
  return atexit(_E578_5);
}

//----- (007171F0) --------------------------------------------------------  // acclient.c:810033
int _E580_5()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCCOLOR_10, "SrcColor");
  return atexit(_E581_5);
}

//----- (00717210) --------------------------------------------------------  // acclient.c:810040
int _E583_5()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCCOLOR_10, "InvSrcColor");
  return atexit(_E584_5);
}

//----- (00717230) --------------------------------------------------------  // acclient.c:810047
int _E586_5()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHA_10, "SrcAlpha");
  return atexit(_E587_5);
}

//----- (00717250) --------------------------------------------------------  // acclient.c:810054
int _E589_5()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCALPHA_10, "InvSrcAlpha");
  return atexit(_E590_5);
}

//----- (00717270) --------------------------------------------------------  // acclient.c:810061
int _E592_5()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTALPHA_10, "DstAlpha");
  return atexit(_E593_5);
}

//----- (00717290) --------------------------------------------------------  // acclient.c:810068
int _E595_5()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTALPHA_10, "InvDstAlpha");
  return atexit(_E596_5);
}

//----- (007172B0) --------------------------------------------------------  // acclient.c:810075
int _E598_5()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTCOLOR_10, "DstColor");
  return atexit(_E599_5);
}

//----- (007172D0) --------------------------------------------------------  // acclient.c:810082
int _E601_5()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTCOLOR_10, "InvDstColor");
  return atexit(_E602_5);
}

//----- (007172F0) --------------------------------------------------------  // acclient.c:810089
int _E604_5()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHASAT_10, "SrcAlphaSat");
  return atexit(_E605_5);
}

//----- (00717310) --------------------------------------------------------  // acclient.c:810096
int _E607_5()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESS_10, "Less");
  return atexit(_E608_5);
}

//----- (00717330) --------------------------------------------------------  // acclient.c:810103
int _E610_5()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_EQUAL_10, "Equal");
  return atexit(_E611_5);
}

//----- (00717350) --------------------------------------------------------  // acclient.c:810110
int _E613_5()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESSEQUAL_10, "LessEqual");
  return atexit(_E614_5);
}

//----- (00717370) --------------------------------------------------------  // acclient.c:810117
int _E616_5()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATER_10, "Greater");
  return atexit(_E617_5);
}

//----- (00717390) --------------------------------------------------------  // acclient.c:810124
int _E619_5()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_NOTEQUAL_10, "NotEqual");
  return atexit(_E620_5);
}

//----- (007173B0) --------------------------------------------------------  // acclient.c:810131
int _E622_5()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATEREQUAL_10, "GreaterEqual");
  return atexit(_E623_5);
}

//----- (007173D0) --------------------------------------------------------  // acclient.c:810138
int _E625_5()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_ALWAYS_10, "Always");
  return atexit(_E626_5);
}

//----- (007173F0) --------------------------------------------------------  // acclient.c:810145
int _E628_5()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_ON_10, "On");
  return atexit(_E629_5);
}

//----- (00717410) --------------------------------------------------------  // acclient.c:810152
int _E631_5()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_OFF_10, "Off");
  return atexit(_E632_5);
}

//----- (00717430) --------------------------------------------------------  // acclient.c:810159
int _E634_5()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERDIFFUSE_10, "LayerDiffuse");
  return atexit(_E635_5);
}

//----- (00717450) --------------------------------------------------------  // acclient.c:810166
int _E637_5()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERSPECULAR_10, "LayerSpecular");
  return atexit(_E638_5);
}

//----- (00717470) --------------------------------------------------------  // acclient.c:810173
int _E640_5()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXDIFFUSE_10, "VertexDiffuse");
  return atexit(_E641_5);
}

//----- (00717490) --------------------------------------------------------  // acclient.c:810180
int _E643_5()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXSPECULAR_10, "VertexSpecular");
  return atexit(_E644_5);
}

//----- (007174B0) --------------------------------------------------------  // acclient.c:810187
int _E646_5()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_NONE_10, "None");
  return atexit(_E647_5);
}

//----- (007174D0) --------------------------------------------------------  // acclient.c:810194
int _E649_5()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CW_10, "CW");
  return atexit(_E650_5);
}

//----- (007174F0) --------------------------------------------------------  // acclient.c:810201
int _E652_5()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CCW_10, "CCW");
  return atexit(_E653_5);
}

//----- (00717510) --------------------------------------------------------  // acclient.c:810208
int _E655_5()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_NONE_10, "None");
  return atexit(_E656_5);
}

//----- (00717530) --------------------------------------------------------  // acclient.c:810215
int _E658_5()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SIMPLE_10, "Simple");
  return atexit(_E659_5);
}

//----- (00717550) --------------------------------------------------------  // acclient.c:810222
int _E661_5()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_DIFFUSE_10, "Diffuse");
  return atexit(_E662_5);
}

//----- (00717570) --------------------------------------------------------  // acclient.c:810229
int _E664_5()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SPECULAR_10, "Specular");
  return atexit(_E665_5);
}

//----- (00717590) --------------------------------------------------------  // acclient.c:810236
int _E667_5()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_OFF_10, "Off");
  return atexit(_E668_5);
}

//----- (007175B0) --------------------------------------------------------  // acclient.c:810243
int _E670_5()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_ON_10, "On");
  return atexit(_E671_5);
}

//----- (007175D0) --------------------------------------------------------  // acclient.c:810250
int _E673_5()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_OFF_10, "Off");
  return atexit(_E674_5);
}

//----- (007175F0) --------------------------------------------------------  // acclient.c:810257
int _E676_5()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_ON_10, "On");
  return atexit(_E677_5);
}

//----- (00717610) --------------------------------------------------------  // acclient.c:810264
int _E679_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_ORIGIN_10, "Origin");
  return atexit(_E680_5);
}

//----- (00717630) --------------------------------------------------------  // acclient.c:810271
int _E682_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_NORMAL_10, "Normal");
  return atexit(_E683_5);
}

//----- (00717650) --------------------------------------------------------  // acclient.c:810278
int _E685_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_POINTSIZE_10, "PointSize");
  return atexit(_E686_5);
}

//----- (00717670) --------------------------------------------------------  // acclient.c:810285
int _E688_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_DIFFUSE_10, "Diffuse");
  return atexit(_E689_5);
}

//----- (00717690) --------------------------------------------------------  // acclient.c:810292
int _E691_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_SPECULAR_10, "Specular");
  return atexit(_E692_5);
}

//----- (007176B0) --------------------------------------------------------  // acclient.c:810299
int _E694_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx1_10, "TCPairX1");
  return atexit(_E695_5);
}

//----- (007176D0) --------------------------------------------------------  // acclient.c:810306
int _E697_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx2_10, "TCPairX2");
  return atexit(_E698_5);
}

//----- (007176F0) --------------------------------------------------------  // acclient.c:810313
int _E700_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx3_10, "TCPairX3");
  return atexit(_E701_5);
}

//----- (00717710) --------------------------------------------------------  // acclient.c:810320
int _E703_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx4_10, "TCPairX4");
  return atexit(_E704_5);
}

//----- (00717730) --------------------------------------------------------  // acclient.c:810327
int _E706_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx5_10, "TCPairX5");
  return atexit(_E707_5);
}

//----- (00717750) --------------------------------------------------------  // acclient.c:810334
int _E709_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx6_10, "TCPairX6");
  return atexit(_E710_5);
}

//----- (00717770) --------------------------------------------------------  // acclient.c:810341
int _E712_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx7_10, "TCPairX7");
  return atexit(_E713_5);
}

//----- (00717790) --------------------------------------------------------  // acclient.c:810348
int _E715_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx8_10, "TCPairX8");
  return atexit(_E716_5);
}

//----- (007177B0) --------------------------------------------------------  // acclient.c:810355
int _E718_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_S_10, "VectorS");
  return atexit(_E719_5);
}

//----- (007177D0) --------------------------------------------------------  // acclient.c:810362
int _E721_5()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_T_10, "VectorT");
  return atexit(_E722_5);
}

//----- (007177F0) --------------------------------------------------------  // acclient.c:810369
int _E724_5()
{
  PStringBase<char>::PStringBase<char>(&stru_8F81D0, "Stage");
  return atexit(_E725_5);
}

//----- (00717810) --------------------------------------------------------  // acclient.c:810376
int _E727_5()
{
  PStringBase<char>::PStringBase<char>(&SamplerNodeName_10, "Sampler");
  return atexit(_E728_5);
}

//----- (00717830) --------------------------------------------------------  // acclient.c:810383
int _E730_5()
{
  PStringBase<char>::PStringBase<char>(&SamplerName_10, "SamplerName");
  return atexit(_E731_5);
}

//----- (00717850) --------------------------------------------------------  // acclient.c:810390
int _E733_5()
{
  PStringBase<char>::PStringBase<char>(&Texture_10, "Texture");
  return atexit(_E734_5);
}

//----- (00717870) --------------------------------------------------------  // acclient.c:810397
int _E736_5()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_FrameBuffer_10, "!FrameBuffer");
  return atexit(_E737_5);
}

//----- (00717890) --------------------------------------------------------  // acclient.c:810404
int _E739_5()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Distortion_10, "!Distortion");
  return atexit(_E740_5);
}

//----- (007178B0) --------------------------------------------------------  // acclient.c:810411
int _E742_5()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Reflection_10, "!Reflection");
  return atexit(_E743_5);
}

//----- (007178D0) --------------------------------------------------------  // acclient.c:810418
int _E745_5()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_NormalizeCube_10, "!NormalizeCube");
  return atexit(_E746_5);
}

//----- (007178F0) --------------------------------------------------------  // acclient.c:810425
int _E748_5()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LightProjectorCube_10, "!LightProjectorCube");
  return atexit(_E749_5);
}

//----- (00717910) --------------------------------------------------------  // acclient.c:810432
int _E751_5()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_EnvironmentCube_10, "!EnvironmentCube");
  return atexit(_E752_5);
}

//----- (00717930) --------------------------------------------------------  // acclient.c:810439
int _E754_5()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LandscapeShadows_10, "!LandscapeShadows");
  return atexit(_E755_5);
}

//----- (00717950) --------------------------------------------------------  // acclient.c:810446
int _E757_5()
{
  PStringBase<char>::PStringBase<char>(&AddressMode_10, "AddressMode");
  return atexit(_E758_5);
}

//----- (00717970) --------------------------------------------------------  // acclient.c:810453
int _E760_5()
{
  PStringBase<char>::PStringBase<char>(&TexFilter_10, "FilterMode");
  return atexit(_E761_5);
}

//----- (00717990) --------------------------------------------------------  // acclient.c:810460
int _E763_5()
{
  PStringBase<char>::PStringBase<char>(&ColorOp_10, "FFColorOp");
  return atexit(_E764_5);
}

//----- (007179B0) --------------------------------------------------------  // acclient.c:810467
int _E766_5()
{
  PStringBase<char>::PStringBase<char>(&ColorArg1_10, "FFColorArg1");
  return atexit(_E767_5);
}

//----- (007179D0) --------------------------------------------------------  // acclient.c:810474
int _E769_5()
{
  PStringBase<char>::PStringBase<char>(&ColorArg2_10, "FFColorArg2");
  return atexit(_E770_5);
}

//----- (007179F0) --------------------------------------------------------  // acclient.c:810481
int _E772_5()
{
  PStringBase<char>::PStringBase<char>(&AlphaOp_10, "FFAlphaOp");
  return atexit(_E773_5);
}

//----- (00717A10) --------------------------------------------------------  // acclient.c:810488
int _E775_5()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg1_10, "FFAlphaArg1");
  return atexit(_E776_5);
}

//----- (00717A30) --------------------------------------------------------  // acclient.c:810495
int _E778_5()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg2_10, "FFAlphaArg2");
  return atexit(_E779_5);
}

//----- (00717A50) --------------------------------------------------------  // acclient.c:810502
int _E781_5()
{
  PStringBase<char>::PStringBase<char>(&TexCoord_10, "FFTexCoordIndex");
  return atexit(_E782_5);
}

//----- (00717A70) --------------------------------------------------------  // acclient.c:810509
int _E784_5()
{
  PStringBase<char>::PStringBase<char>(&UseProjection_10, "FFUseProjection");
  return atexit(_E785_5);
}

//----- (00717A90) --------------------------------------------------------  // acclient.c:810516
int _E787_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG1_10, "SelectArg1");
  return atexit(_E788_5);
}

//----- (00717AB0) --------------------------------------------------------  // acclient.c:810523
int _E790_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG2_10, "SelectArg2");
  return atexit(_E791_5);
}

//----- (00717AD0) --------------------------------------------------------  // acclient.c:810530
int _E793_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE_10, "Modulate");
  return atexit(_E794_5);
}

//----- (00717AF0) --------------------------------------------------------  // acclient.c:810537
int _E796_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE2X_10, "Modulate2X");
  return atexit(_E797_5);
}

//----- (00717B10) --------------------------------------------------------  // acclient.c:810544
int _E799_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE4X_10, "Modulate4X");
  return atexit(_E800_5);
}

//----- (00717B30) --------------------------------------------------------  // acclient.c:810551
int _E802_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADD_10, "Add");
  return atexit(_E803_5);
}

//----- (00717B50) --------------------------------------------------------  // acclient.c:810558
int _E805_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED_10, "AddSigned");
  return atexit(_E806_5);
}

//----- (00717B70) --------------------------------------------------------  // acclient.c:810565
int _E808_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED2X_10, "AddSigned2X");
  return atexit(_E809_5);
}

//----- (00717B90) --------------------------------------------------------  // acclient.c:810572
int _E811_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SUBTRACT_10, "Subtract");
  return atexit(_E812_5);
}

//----- (00717BB0) --------------------------------------------------------  // acclient.c:810579
int _E814_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSMOOTH_10, "AddSmooth");
  return atexit(_E815_5);
}

//----- (00717BD0) --------------------------------------------------------  // acclient.c:810586
int _E817_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDDIFFUSEALPHA_10, "BlendDiffuseAlpha");
  return atexit(_E818_5);
}

//----- (00717BF0) --------------------------------------------------------  // acclient.c:810593
int _E820_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHA_10, "BlendTextureAlpha");
  return atexit(_E821_5);
}

//----- (00717C10) --------------------------------------------------------  // acclient.c:810600
int _E823_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDFACTORALPHA_10, "BlendFactorAlpha");
  return atexit(_E824_5);
}

//----- (00717C30) --------------------------------------------------------  // acclient.c:810607
int _E826_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHAPM_10, "BlendTextureAlphaPM");
  return atexit(_E827_5);
}

//----- (00717C50) --------------------------------------------------------  // acclient.c:810614
int _E829_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDCURRENTALPHA_10, "BlendCurrentAlpha");
  return atexit(_E830_5);
}

//----- (00717C70) --------------------------------------------------------  // acclient.c:810621
int _E832_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_PREMODULATE_10, "Premodulate");
  return atexit(_E833_5);
}

//----- (00717C90) --------------------------------------------------------  // acclient.c:810628
int _E835_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEALPHA_ADDCOLOR_10, "ModulateAlphaAddColor");
  return atexit(_E836_5);
}

//----- (00717CB0) --------------------------------------------------------  // acclient.c:810635
int _E838_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATECOLOR_ADDALPHA_10, "ModulateColorAddAlpha");
  return atexit(_E839_5);
}

//----- (00717CD0) --------------------------------------------------------  // acclient.c:810642
int _E841_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_10, "ModulateInvAlphaAddColor");
  return atexit(_E842_5);
}

//----- (00717CF0) --------------------------------------------------------  // acclient.c:810649
int _E844_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_10, "ModulateInvColorAddAlpha");
  return atexit(_E845_5);
}

//----- (00717D10) --------------------------------------------------------  // acclient.c:810656
int _E847_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAP_10, "BumpEnvMap");
  return atexit(_E848_5);
}

//----- (00717D30) --------------------------------------------------------  // acclient.c:810663
int _E850_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAPLUMINANCE_10, "BumpEnvMapLuminance");
  return atexit(_E851_5);
}

//----- (00717D50) --------------------------------------------------------  // acclient.c:810670
int _E853_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_DOTPRODUCT3_10, "DotProduct3");
  return atexit(_E854_5);
}

//----- (00717D70) --------------------------------------------------------  // acclient.c:810677
int _E856_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MULTIPLYADD_10, "MultiplyAdd");
  return atexit(_E857_5);
}

//----- (00717D90) --------------------------------------------------------  // acclient.c:810684
int _E859_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_LERP_10, "Lerp");
  return atexit(_E860_5);
}

//----- (00717DB0) --------------------------------------------------------  // acclient.c:810691
int _E862_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_DIFFUSE_10, "Diffuse");
  return atexit(_E863_5);
}

//----- (00717DD0) --------------------------------------------------------  // acclient.c:810698
int _E865_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_SPECULAR_10, "Specular");
  return atexit(_E866_5);
}

//----- (00717DF0) --------------------------------------------------------  // acclient.c:810705
int _E868_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_CURRENT_10, "Current");
  return atexit(_E869_5);
}

//----- (00717E10) --------------------------------------------------------  // acclient.c:810712
int _E871_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TEXTURE_10, "Texture");
  return atexit(_E872_5);
}

//----- (00717E30) --------------------------------------------------------  // acclient.c:810719
int _E874_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TFACTOR_10, "TFactor");
  return atexit(_E875_5);
}

//----- (00717E50) --------------------------------------------------------  // acclient.c:810726
int _E877_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_WRAP_10, "Wrap");
  return atexit(_E878_5);
}

//----- (00717E70) --------------------------------------------------------  // acclient.c:810733
int _E880_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_MIRROR_10, "Mirror");
  return atexit(_E881_5);
}

//----- (00717E90) --------------------------------------------------------  // acclient.c:810740
int _E883_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_CLAMP_10, "Clamp");
  return atexit(_E884_5);
}

//----- (00717EB0) --------------------------------------------------------  // acclient.c:810747
int _E886_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_BORDER_10, "Border");
  return atexit(_E887_5);
}

//----- (00717ED0) --------------------------------------------------------  // acclient.c:810754
int _E889_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_NONE_10, "None");
  return atexit(_E890_5);
}

//----- (00717EF0) --------------------------------------------------------  // acclient.c:810761
int _E892_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_POINT_10, "Point");
  return atexit(_E893_5);
}

//----- (00717F10) --------------------------------------------------------  // acclient.c:810768
int _E895_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_LINEAR_10, "Linear");
  return atexit(_E896_5);
}

//----- (00717F30) --------------------------------------------------------  // acclient.c:810775
int _E898_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_ANISOTROPIC_10, "Anisotropic");
  return atexit(_E899_5);
}

//----- (00717F50) --------------------------------------------------------  // acclient.c:810782
int _E901_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ReflectionVector_10, "ReflectionVector");
  return atexit(_E902_5);
}

//----- (00717F70) --------------------------------------------------------  // acclient.c:810789
int _E904_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewNormal_10, "ViewNormal");
  return atexit(_E905_5);
}

//----- (00717F90) --------------------------------------------------------  // acclient.c:810796
int _E907_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewOrigin_10, "ViewOrigin");
  return atexit(_E908_5);
}

//----- (00717FB0) --------------------------------------------------------  // acclient.c:810803
int _E910_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_SphereMap_10, "SphereMap");
  return atexit(_E911_5);
}

//----- (00717FD0) --------------------------------------------------------  // acclient.c:810810
int _E913_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapReflection_10, "CubeMapReflection");
  return atexit(_E914_5);
}

//----- (00717FF0) --------------------------------------------------------  // acclient.c:810817
int _E916_5()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapFakeLight_10, "CubeMapFakeLight");
  return atexit(_E917_5);
}

//----- (00718010) --------------------------------------------------------  // acclient.c:810824
int _E919_5()
{
  PStringBase<char>::PStringBase<char>(&stru_8F82D4, "FFModifier");
  return atexit(_E920_5);
}

//----- (00718030) --------------------------------------------------------  // acclient.c:810831
int _E922_5()
{
  PStringBase<char>::PStringBase<char>(&ModType_Origin_10, "Origin");
  return atexit(_E923_5);
}

//----- (00718050) --------------------------------------------------------  // acclient.c:810838
int _E925_5()
{
  PStringBase<char>::PStringBase<char>(&ModType_Normal_10, "Normal");
  return atexit(_E926_5);
}

//----- (00718070) --------------------------------------------------------  // acclient.c:810845
int _E928_5()
{
  PStringBase<char>::PStringBase<char>(&ModType_Diffuse_10, "Diffuse");
  return atexit(_E929_5);
}

//----- (00718090) --------------------------------------------------------  // acclient.c:810852
int _E931_5()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTranslate_10, "UVTranslate");
  return atexit(_E932_5);
}

//----- (007180B0) --------------------------------------------------------  // acclient.c:810859
int _E934_5()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVRotate_10, "UVRotate");
  return atexit(_E935_5);
}

//----- (007180D0) --------------------------------------------------------  // acclient.c:810866
int _E937_5()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVScale_10, "UVScale");
  return atexit(_E938_5);
}

//----- (007180F0) --------------------------------------------------------  // acclient.c:810873
int _E940_5()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTransform_10, "UVTransform");
  return atexit(_E941_5);
}

//----- (00718110) --------------------------------------------------------  // acclient.c:810880
int _E943_5()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_texCoordIndex_10, "TexCoordIndex");
  return atexit(_E944_5);
}

//----- (00718130) --------------------------------------------------------  // acclient.c:810887
int _E946_5()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_translate_10, "Translate");
  return atexit(_E947_5);
}

//----- (00718150) --------------------------------------------------------  // acclient.c:810894
int _E949_5()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_texCoordIndex_10, "TexCoordIndex");
  return atexit(_E950_5);
}

//----- (00718170) --------------------------------------------------------  // acclient.c:810901
int _E952_5()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_rotate_10, "Rotate");
  return atexit(_E953_5);
}

//----- (00718190) --------------------------------------------------------  // acclient.c:810908
int _E955_5()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_texCoordIndex_10, "TexCoordIndex");
  return atexit(_E956_5);
}

//----- (007181B0) --------------------------------------------------------  // acclient.c:810915
int _E958_5()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_scale_10, "Scale");
  return atexit(_E959_5);
}

//----- (007181D0) --------------------------------------------------------  // acclient.c:810922
int _E961_5()
{
  PStringBase<char>::PStringBase<char>(&stru_8F830C, "PSDesc");
  return atexit(_E962_5);
}

//----- (007181F0) --------------------------------------------------------  // acclient.c:810929
int _E964_5()
{
  PStringBase<char>::PStringBase<char>(&PhysicsTimeStep_10, "PhysicsTimeStep");
  return atexit(_E965_5);
}

//----- (00718210) --------------------------------------------------------  // acclient.c:810936
int _E967_5()
{
  PStringBase<char>::PStringBase<char>(&FastForwardTime_10, "FastForwardTime");
  return atexit(_E968_5);
}

//----- (00718230) --------------------------------------------------------  // acclient.c:810943
int _E970_5()
{
  PStringBase<char>::PStringBase<char>(&StartFadeDistance_10, "StartFadeDistance");
  return atexit(_E971_5);
}

//----- (00718250) --------------------------------------------------------  // acclient.c:810950
int _E973_5()
{
  PStringBase<char>::PStringBase<char>(&StopFadeDistance_10, "StopFadeDistance");
  return atexit(_E974_5);
}

//----- (00718270) --------------------------------------------------------  // acclient.c:810957
int _E976_5()
{
  PStringBase<char>::PStringBase<char>(&PhysicsDuration_10, "PhysicsDuration");
  return atexit(_E977_5);
}

//----- (00718290) --------------------------------------------------------  // acclient.c:810964
int _E979_5()
{
  PStringBase<char>::PStringBase<char>(&ScaleType_10, "ScaleType");
  return atexit(_E980_5);
}

//----- (007182B0) --------------------------------------------------------  // acclient.c:810971
int _E982_5()
{
  PStringBase<char>::PStringBase<char>(&WorldSpace_10, "WorldSpace");
  return atexit(_E983_5);
}

//----- (007182D0) --------------------------------------------------------  // acclient.c:810978
int _E985_5()
{
  PStringBase<char>::PStringBase<char>(&ForceDraw_10, "ForceDraw");
  return atexit(_E986_5);
}

//----- (007182F0) --------------------------------------------------------  // acclient.c:810985
int _E988_5()
{
  PStringBase<char>::PStringBase<char>(&NumEmitters_10, "NumEmitters");
  return atexit(_E989_5);
}

//----- (00718310) --------------------------------------------------------  // acclient.c:810992
int _E991_5()
{
  PStringBase<char>::PStringBase<char>(&Material_49, "Material");
  return atexit(_E992_5);
}

//----- (00718330) --------------------------------------------------------  // acclient.c:810999
int _E994_5()
{
  PStringBase<char>::PStringBase<char>(&Version_10, "Version");
  return atexit(_E995_5);
}

//----- (00718350) --------------------------------------------------------  // acclient.c:811006
int _E997_5()
{
  PStringBase<char>::PStringBase<char>(&MaxParticles_10, "MaxParticles");
  return atexit(_E998_5);
}

//----- (00718370) --------------------------------------------------------  // acclient.c:811013
int _E1000_5()
{
  PStringBase<char>::PStringBase<char>(&stru_8F8340, "Emitter");
  return atexit(_E1001_5);
}

//----- (00718390) --------------------------------------------------------  // acclient.c:811020
int _E1003_5()
{
  PStringBase<char>::PStringBase<char>(&Origin_22, "Origin");
  return atexit(_E1004_5);
}

//----- (007183B0) --------------------------------------------------------  // acclient.c:811027
int _E1006_5()
{
  PStringBase<char>::PStringBase<char>(&Shape_10, "Shape");
  return atexit(_E1007_5);
}

//----- (007183D0) --------------------------------------------------------  // acclient.c:811034
int _E1009_5()
{
  PStringBase<char>::PStringBase<char>(&Shape_Point_10, "Point");
  return atexit(_E1010_5);
}

//----- (007183F0) --------------------------------------------------------  // acclient.c:811041
int _E1012_5()
{
  PStringBase<char>::PStringBase<char>(&Shape_Line_10, "Line");
  return atexit(_E1013_5);
}

//----- (00718410) --------------------------------------------------------  // acclient.c:811048
int _E1015_5()
{
  PStringBase<char>::PStringBase<char>(&Shape_Quad_10, "Quad");
  return atexit(_E1016_5);
}

//----- (00718430) --------------------------------------------------------  // acclient.c:811055
int _E1018_5()
{
  PStringBase<char>::PStringBase<char>(&Shape_Disc_10, "Disc");
  return atexit(_E1019_5);
}

//----- (00718450) --------------------------------------------------------  // acclient.c:811062
int _E1021_5()
{
  PStringBase<char>::PStringBase<char>(&Shape_Sphere_10, "Sphere");
  return atexit(_E1022_5);
}

//----- (00718470) --------------------------------------------------------  // acclient.c:811069
int _E1024_5()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_10, "ParticleShape");
  return atexit(_E1025_5);
}

//----- (00718490) --------------------------------------------------------  // acclient.c:811076
int _E1027_5()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Triangle_10, "Triangle");
  return atexit(_E1028_5);
}

//----- (007184B0) --------------------------------------------------------  // acclient.c:811083
int _E1030_5()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Quad_10, "Quad");
  return atexit(_E1031_5);
}

//----- (007184D0) --------------------------------------------------------  // acclient.c:811090
int _E1033_5()
{
  PStringBase<char>::PStringBase<char>(&Streak_10, "Streak");
  return atexit(_E1034_5);
}

//----- (007184F0) --------------------------------------------------------  // acclient.c:811097
int _E1036_5()
{
  PStringBase<char>::PStringBase<char>(&Rotation_22, "Rotation");
  return atexit(_E1037_5);
}

//----- (00718510) --------------------------------------------------------  // acclient.c:811104
int _E1039_5()
{
  PStringBase<char>::PStringBase<char>(&WorldRotation_10, "WorldRotation");
  return atexit(_E1040_5);
}

//----- (00718530) --------------------------------------------------------  // acclient.c:811111
int _E1042_5()
{
  PStringBase<char>::PStringBase<char>(&RotateVelocity_10, "RotateVelocity");
  return atexit(_E1043_5);
}

//----- (00718550) --------------------------------------------------------  // acclient.c:811118
int _E1045_5()
{
  PStringBase<char>::PStringBase<char>(&ParticleScale_10, "ParticleScale");
  return atexit(_E1046_5);
}

//----- (00718570) --------------------------------------------------------  // acclient.c:811125
int _E1048_5()
{
  PStringBase<char>::PStringBase<char>(&Scale_33, "Scale");
  return atexit(_E1049_5);
}

//----- (00718590) --------------------------------------------------------  // acclient.c:811132
int _E1051_5()
{
  PStringBase<char>::PStringBase<char>(&ExplodingDir_10, "ExplodingDir");
  return atexit(_E1052_5);
}

//----- (007185B0) --------------------------------------------------------  // acclient.c:811139
int _E1054_5()
{
  PStringBase<char>::PStringBase<char>(&BirthRate_10, "BirthRate");
  return atexit(_E1055_5);
}

//----- (007185D0) --------------------------------------------------------  // acclient.c:811146
int _E1057_5()
{
  PStringBase<char>::PStringBase<char>(&Lifespan_10, "Lifespan");
  return atexit(_E1058_5);
}

//----- (007185F0) --------------------------------------------------------  // acclient.c:811153
int _E1060_5()
{
  PStringBase<char>::PStringBase<char>(&Velocity_10, "Velocity");
  return atexit(_E1061_5);
}

//----- (00718610) --------------------------------------------------------  // acclient.c:811160
int _E1063_5()
{
  PStringBase<char>::PStringBase<char>(&Direction_10, "Direction");
  return atexit(_E1064_5);
}

//----- (00718630) --------------------------------------------------------  // acclient.c:811167
int _E1066_5()
{
  PStringBase<char>::PStringBase<char>(&MinSpread_10, "MinSpread");
  return atexit(_E1067_5);
}

//----- (00718650) --------------------------------------------------------  // acclient.c:811174
int _E1069_5()
{
  PStringBase<char>::PStringBase<char>(&MaxSpread_10, "MaxSpread");
  return atexit(_E1070_5);
}

//----- (00718670) --------------------------------------------------------  // acclient.c:811181
int _E1072_5()
{
  PStringBase<char>::PStringBase<char>(&EmissionLimit_10, "EmissionLimit");
  return atexit(_E1073_5);
}

//----- (00718690) --------------------------------------------------------  // acclient.c:811188
int _E1075_5()
{
  PStringBase<char>::PStringBase<char>(&BlastCount_10, "BlastCount");
  return atexit(_E1076_5);
}

//----- (007186B0) --------------------------------------------------------  // acclient.c:811195
int _E1078_5()
{
  PStringBase<char>::PStringBase<char>(&StartTime_10, "StartTime");
  return atexit(_E1079_5);
}

//----- (007186D0) --------------------------------------------------------  // acclient.c:811202
int _E1081_5()
{
  PStringBase<char>::PStringBase<char>(&TimeLimit_10, "TimeLimit");
  return atexit(_E1082_5);
}

//----- (007186F0) --------------------------------------------------------  // acclient.c:811209
int _E1084_5()
{
  PStringBase<char>::PStringBase<char>(&EmissionDistance_10, "EmissionDistance");
  return atexit(_E1085_5);
}

//----- (00718710) --------------------------------------------------------  // acclient.c:811216
int _E1087_5()
{
  PStringBase<char>::PStringBase<char>(&ParticleSnap_10, "ParticleSnap");
  return atexit(_E1088_5);
}

//----- (00718730) --------------------------------------------------------  // acclient.c:811223
int _E1090_5()
{
  PStringBase<char>::PStringBase<char>(&InclusiveShape_10, "InclusiveShape");
  return atexit(_E1091_5);
}

//----- (00718750) --------------------------------------------------------  // acclient.c:811230
int _E1093_5()
{
  PStringBase<char>::PStringBase<char>(&NumKeyframes_10, "NumKeyframes");
  return atexit(_E1094_5);
}

//----- (00718770) --------------------------------------------------------  // acclient.c:811237
int _E1096_5()
{
  PStringBase<char>::PStringBase<char>(&IsActive_10, "IsActive");
  return atexit(_E1097_5);
}

//----- (00718790) --------------------------------------------------------  // acclient.c:811244
int _E1099_5()
{
  PStringBase<char>::PStringBase<char>(&FadeIn_10, "FadeIn");
  return atexit(_E1100_5);
}

//----- (007187B0) --------------------------------------------------------  // acclient.c:811251
int _E1102_5()
{
  PStringBase<char>::PStringBase<char>(&FadeOut_10, "FadeOut");
  return atexit(_E1103_5);
}

//----- (007187D0) --------------------------------------------------------  // acclient.c:811258
int _E1105_5()
{
  PStringBase<char>::PStringBase<char>(&ConstrainX_10, "ConstrainX");
  return atexit(_E1106_5);
}

//----- (007187F0) --------------------------------------------------------  // acclient.c:811265
int _E1108_5()
{
  PStringBase<char>::PStringBase<char>(&ConstrainY_10, "ConstrainY");
  return atexit(_E1109_5);
}

//----- (00718810) --------------------------------------------------------  // acclient.c:811272
int _E1111_5()
{
  PStringBase<char>::PStringBase<char>(&ConstrainZ_10, "ConstrainZ");
  return atexit(_E1112_5);
}

//----- (00718830) --------------------------------------------------------  // acclient.c:811279
int _E1114_5()
{
  PStringBase<char>::PStringBase<char>(&stru_8F83D8, "Keyframe");
  return atexit(_E1115_5);
}

//----- (00718850) --------------------------------------------------------  // acclient.c:811286
int _E1117_5()
{
  PStringBase<char>::PStringBase<char>(&Time_10, "Time");
  return atexit(_E1118_5);
}

//----- (00718870) --------------------------------------------------------  // acclient.c:811293
int _E1120_5()
{
  PStringBase<char>::PStringBase<char>(&Flags_10, "Flags");
  return atexit(_E1121_5);
}

//----- (00718890) --------------------------------------------------------  // acclient.c:811300
int _E1123_5()
{
  PStringBase<char>::PStringBase<char>(&Flags_None_10, "None");
  return atexit(_E1124_5);
}

//----- (007188B0) --------------------------------------------------------  // acclient.c:811307
int _E1126_5()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendScale_10, "BlendScale");
  return atexit(_E1127_5);
}

//----- (007188D0) --------------------------------------------------------  // acclient.c:811314
int _E1129_5()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendColor_10, "BlendColor");
  return atexit(_E1130_5);
}

//----- (007188F0) --------------------------------------------------------  // acclient.c:811321
int _E1132_5()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendMass_10, "BlendMass");
  return atexit(_E1133_5);
}

//----- (00718910) --------------------------------------------------------  // acclient.c:811328
int _E1135_5()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetScale_10, "SetScale");
  return atexit(_E1136_5);
}

//----- (00718930) --------------------------------------------------------  // acclient.c:811335
int _E1138_5()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetColor_10, "SetColor");
  return atexit(_E1139_5);
}

//----- (00718950) --------------------------------------------------------  // acclient.c:811342
int _E1141_5()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetMass_10, "SetMass");
  return atexit(_E1142_5);
}

//----- (00718970) --------------------------------------------------------  // acclient.c:811349
int _E1144_5()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPFlags_10, "SetParticleFlags");
  return atexit(_E1145_5);
}

//----- (00718990) --------------------------------------------------------  // acclient.c:811356
int _E1147_5()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPCType_10, "SetControllerType");
  return atexit(_E1148_5);
}

//----- (007189B0) --------------------------------------------------------  // acclient.c:811363
int _E1150_5()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPhysFlags_10, "SetPhysicsFlags");
  return atexit(_E1151_5);
}

//----- (007189D0) --------------------------------------------------------  // acclient.c:811370
int _E1153_5()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetParams_10, "SetParams");
  return atexit(_E1154_5);
}

//----- (007189F0) --------------------------------------------------------  // acclient.c:811377
int _E1156_5()
{
  PStringBase<char>::PStringBase<char>(&Scale_34, "Scale");
  return atexit(_E1157_5);
}

//----- (00718A10) --------------------------------------------------------  // acclient.c:811384
int _E1159_5()
{
  PStringBase<char>::PStringBase<char>(&ScaleX_10, "ScaleX");
  return atexit(_E1160_5);
}

//----- (00718A30) --------------------------------------------------------  // acclient.c:811391
int _E1162_5()
{
  PStringBase<char>::PStringBase<char>(&ScaleY_10, "ScaleY");
  return atexit(_E1163_5);
}

//----- (00718A50) --------------------------------------------------------  // acclient.c:811398
int _E1165_5()
{
  PStringBase<char>::PStringBase<char>(&Color_10, "Color");
  return atexit(_E1166_5);
}

//----- (00718A70) --------------------------------------------------------  // acclient.c:811405
int _E1168_5()
{
  PStringBase<char>::PStringBase<char>(&Mass_10, "Mass");
  return atexit(_E1169_5);
}

//----- (00718A90) --------------------------------------------------------  // acclient.c:811412
int _E1171_5()
{
  PStringBase<char>::PStringBase<char>(&PFlags_10, "ParticleFlags");
  return atexit(_E1172_5);
}

//----- (00718AB0) --------------------------------------------------------  // acclient.c:811419
int _E1174_5()
{
  PStringBase<char>::PStringBase<char>(&PFlags_None_10, "None");
  return atexit(_E1175_5);
}

//----- (00718AD0) --------------------------------------------------------  // acclient.c:811426
int _E1177_5()
{
  PStringBase<char>::PStringBase<char>(&PCType_10, "ControllerType");
  return atexit(_E1178_5);
}

//----- (00718AF0) --------------------------------------------------------  // acclient.c:811433
int _E1180_5()
{
  PStringBase<char>::PStringBase<char>(&PCType_None_10, "None");
  return atexit(_E1181_5);
}

//----- (00718B10) --------------------------------------------------------  // acclient.c:811440
int _E1183_5()
{
  PStringBase<char>::PStringBase<char>(&PCType_Physics_10, "Physics");
  return atexit(_E1184_5);
}

//----- (00718B30) --------------------------------------------------------  // acclient.c:811447
int _E1186_5()
{
  PStringBase<char>::PStringBase<char>(&PCType_Parametric_10, "Parametric");
  return atexit(_E1187_5);
}

//----- (00718B50) --------------------------------------------------------  // acclient.c:811454
int _E1189_5()
{
  PStringBase<char>::PStringBase<char>(&PCType_AttractRepulse_10, "AttractRepulse");
  return atexit(_E1190_5);
}

//----- (00718B70) --------------------------------------------------------  // acclient.c:811461
int _E1192_5()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFile_10, "PointFile");
  return atexit(_E1193_5);
}

//----- (00718B90) --------------------------------------------------------  // acclient.c:811468
int _E1195_5()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFileLerp_10, "PointFileLerp");
  return atexit(_E1196_5);
}

//----- (00718BB0) --------------------------------------------------------  // acclient.c:811475
int _E1198_5()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_10, "PhysicsFlags");
  return atexit(_E1199_5);
}

//----- (00718BD0) --------------------------------------------------------  // acclient.c:811482
int _E1201_5()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_None_10, "None");
  return atexit(_E1202_5);
}

//----- (00718BF0) --------------------------------------------------------  // acclient.c:811489
int _E1204_5()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Gravity_10, "Gravity");
  return atexit(_E1205_5);
}

//----- (00718C10) --------------------------------------------------------  // acclient.c:811496
int _E1207_5()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Wind_10, "Wind");
  return atexit(_E1208_5);
}

//----- (00718C30) --------------------------------------------------------  // acclient.c:811503
int _E1210_5()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Momentum_10, "Momentum");
  return atexit(_E1211_5);
}

//----- (00718C50) --------------------------------------------------------  // acclient.c:811510
int _E1213_5()
{
  PStringBase<char>::PStringBase<char>(&PointfileFlags_RandomPoint_10, "RandomPoint");
  return atexit(_E1214_5);
}

//----- (00718C70) --------------------------------------------------------  // acclient.c:811517
int _E1216_5()
{
  PStringBase<char>::PStringBase<char>(&Position_11, "Position");
  return atexit(_E1217_5);
}

//----- (00718C90) --------------------------------------------------------  // acclient.c:811524
int _E1219_5()
{
  PStringBase<char>::PStringBase<char>(&PointList_10, "PointList");
  return atexit(_E1220_5);
}

//----- (00718CB0) --------------------------------------------------------  // acclient.c:811531
int _E1222_5()
{
  PStringBase<char>::PStringBase<char>(&Point_22, "pt");
  return atexit(_E1223_5);
}

//----- (00718CD0) --------------------------------------------------------  // acclient.c:811538
int _E1225_5()
{
  PStringBase<char>::PStringBase<char>(&DetailLevels_10, "DetailLevels");
  return atexit(_E1226_5);
}

//----- (00718CF0) --------------------------------------------------------  // acclient.c:811545
int _E1228_5()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Low_10, "Low");
  return atexit(_E1229_5);
}

//----- (00718D10) --------------------------------------------------------  // acclient.c:811552
int _E1231_5()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Medium_10, "Medium");
  return atexit(_E1232_5);
}

//----- (00718D30) --------------------------------------------------------  // acclient.c:811559
int _E1234_5()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_High_10, "High");
  return atexit(_E1235_5);
}

//----- (00718D50) --------------------------------------------------------  // acclient.c:811566
int _E1237_5()
{
  PStringBase<char>::PStringBase<char>(&FadeSpeed_10, "FadeSpeed");
  return atexit(_E1238_5);
}

//----- (00718D70) --------------------------------------------------------  // acclient.c:811573
int _E1240_5()
{
  PStringBase<char>::PStringBase<char>(&MaxOpacity_10, "MaxOpacity");
  return atexit(_E1241_5);
}

//----- (00718D90) --------------------------------------------------------  // acclient.c:811580
int _E1243_5()
{
  PStringBase<char>::PStringBase<char>(&Point_23, "Point");
  return atexit(_E1244_5);
}

//----- (00718DB0) --------------------------------------------------------  // acclient.c:811587
int _E1246_5()
{
  PStringBase<char>::PStringBase<char>(&PointAxisPos_10, "AxisPos");
  return atexit(_E1247_5);
}

//----- (00718DD0) --------------------------------------------------------  // acclient.c:811594
int _E1249_5()
{
  PStringBase<char>::PStringBase<char>(&PointTexture_10, "Texture");
  return atexit(_E1250_5);
}

//----- (00718DF0) --------------------------------------------------------  // acclient.c:811601
int _E1252_5()
{
  PStringBase<char>::PStringBase<char>(&PointSize_10, "Size");
  return atexit(_E1253_5);
}

//----- (00718E10) --------------------------------------------------------  // acclient.c:811608
int _E1255_5()
{
  PStringBase<char>::PStringBase<char>(&UseOcclusion_10, "UseOcclusion");
  return atexit(_E1256_5);
}

//----- (00718E30) --------------------------------------------------------  // acclient.c:811615
int sub_718E30()
{
  return atexit(nullsub_237);
}

//----- (0077FAE0) --------------------------------------------------------  // acclient.c:918304
void __cdecl sub_77FAE0()
{
  char *v0; // esi@1

  v0 = &PHeader_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FB10) --------------------------------------------------------  // acclient.c:918317
void __cdecl sub_77FB10()
{
  char *v0; // esi@1

  v0 = &VertexArray_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexArray_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FB40) --------------------------------------------------------  // acclient.c:918330
void __cdecl _E80_88()
{
  char *v0; // esi@1

  v0 = &BinaryVertexArray_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryVertexArray_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FB70) --------------------------------------------------------  // acclient.c:918343
void __cdecl _E83_53()
{
  char *v0; // esi@1

  v0 = &VertexType_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexType_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FBA0) --------------------------------------------------------  // acclient.c:918356
void __cdecl _E86_33()
{
  char *v0; // esi@1

  v0 = &VertexData_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexData_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FBD0) --------------------------------------------------------  // acclient.c:918369
void __cdecl _E89_43()
{
  char *v0; // esi@1

  v0 = &Vertex_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertex_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FC00) --------------------------------------------------------  // acclient.c:918382
void __cdecl _E92_48()
{
  char *v0; // esi@1

  v0 = &Index_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FC30) --------------------------------------------------------  // acclient.c:918395
void __cdecl sub_77FC30()
{
  char *v0; // esi@1

  v0 = &Origin_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FC60) --------------------------------------------------------  // acclient.c:918408
void __cdecl sub_77FC60()
{
  char *v0; // esi@1

  v0 = &Normal_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Normal_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FC90) --------------------------------------------------------  // acclient.c:918421
void __cdecl sub_77FC90()
{
  char *v0; // esi@1

  v0 = &Diffuse_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FCC0) --------------------------------------------------------  // acclient.c:918434
void __cdecl sub_77FCC0()
{
  char *v0; // esi@1

  v0 = &Specular_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FCF0) --------------------------------------------------------  // acclient.c:918447
void __cdecl sub_77FCF0()
{
  char *v0; // esi@1

  v0 = &UVS_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVS_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FD20) --------------------------------------------------------  // acclient.c:918460
void __cdecl sub_77FD20()
{
  char *v0; // esi@1

  v0 = &VectorS_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorS_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FD50) --------------------------------------------------------  // acclient.c:918473
void __cdecl _E113_74()
{
  char *v0; // esi@1

  v0 = &VectorT_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorT_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FD80) --------------------------------------------------------  // acclient.c:918486
void __cdecl _E116_66()
{
  char *v0; // esi@1

  v0 = &VectorSxT_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorSxT_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FDB0) --------------------------------------------------------  // acclient.c:918499
void __cdecl _E119_92()
{
  char *v0; // esi@1

  v0 = &Weights_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weights_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FDE0) --------------------------------------------------------  // acclient.c:918512
void __cdecl sub_77FDE0()
{
  char *v0; // esi@1

  v0 = &Importance_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Importance_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FE10) --------------------------------------------------------  // acclient.c:918525
void __cdecl _E125_72()
{
  char *v0; // esi@1

  v0 = &PhysMtl_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMtl_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FE40) --------------------------------------------------------  // acclient.c:918538
void __cdecl _E128_70()
{
  char *v0; // esi@1

  v0 = &Material_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FE70) --------------------------------------------------------  // acclient.c:918551
void __cdecl _E131_59()
{
  char *v0; // esi@1

  v0 = &ID_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FEA0) --------------------------------------------------------  // acclient.c:918564
void __cdecl _E134_43()
{
  char *v0; // esi@1

  v0 = &FileName_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FED0) --------------------------------------------------------  // acclient.c:918577
void __cdecl _E137_42()
{
  char *v0; // esi@1

  v0 = &Polygon_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FF00) --------------------------------------------------------  // acclient.c:918590
void __cdecl _E140_36()
{
  char *v0; // esi@1

  v0 = &ID_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FF30) --------------------------------------------------------  // acclient.c:918603
void __cdecl _E143_36()
{
  char *v0; // esi@1

  v0 = &Indices_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FF60) --------------------------------------------------------  // acclient.c:918616
void __cdecl _E146_36()
{
  char *v0; // esi@1

  v0 = &MaterialID_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialID_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FF90) --------------------------------------------------------  // acclient.c:918629
void __cdecl _E149_35()
{
  char *v0; // esi@1

  v0 = &PhysMaterialID_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMaterialID_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FFC0) --------------------------------------------------------  // acclient.c:918642
void __cdecl _E152_36()
{
  char *v0; // esi@1

  v0 = &Markings_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Markings_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FFF0) --------------------------------------------------------  // acclient.c:918655
void __cdecl _E155_32()
{
  char *v0; // esi@1

  v0 = &Material_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780020) --------------------------------------------------------  // acclient.c:918668
void __cdecl _E158_33()
{
  char *v0; // esi@1

  v0 = &Index_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780050) --------------------------------------------------------  // acclient.c:918681
void __cdecl _E161_30()
{
  char *v0; // esi@1

  v0 = &Filename_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Filename_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780080) --------------------------------------------------------  // acclient.c:918694
void __cdecl _E164_32()
{
  char *v0; // esi@1

  v0 = &Surface_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Surface_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007800B0) --------------------------------------------------------  // acclient.c:918707
void __cdecl _E167_28()
{
  char *v0; // esi@1

  v0 = &CellPoly_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPoly_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007800E0) --------------------------------------------------------  // acclient.c:918720
void __cdecl _E170_28()
{
  char *v0; // esi@1

  v0 = &Sphere_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780110) --------------------------------------------------------  // acclient.c:918733
void __cdecl _E173_23()
{
  char *v0; // esi@1

  v0 = &Side_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Side_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780140) --------------------------------------------------------  // acclient.c:918746
void __cdecl _E176_25()
{
  char *v0; // esi@1

  v0 = &Positive_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Positive_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780170) --------------------------------------------------------  // acclient.c:918759
void __cdecl _E179_24()
{
  char *v0; // esi@1

  v0 = &Negative_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Negative_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007801A0) --------------------------------------------------------  // acclient.c:918772
void __cdecl _E182_24()
{
  char *v0; // esi@1

  v0 = &Polygon_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007801D0) --------------------------------------------------------  // acclient.c:918785
void __cdecl _E185_21()
{
  char *v0; // esi@1

  v0 = &OtherCell_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780200) --------------------------------------------------------  // acclient.c:918798
void __cdecl _E188_22()
{
  char *v0; // esi@1

  v0 = &CellPortal_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPortal_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780230) --------------------------------------------------------  // acclient.c:918811
void __cdecl _E191_21()
{
  char *v0; // esi@1

  v0 = &Portal_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780260) --------------------------------------------------------  // acclient.c:918824
void __cdecl _E194_28()
{
  char *v0; // esi@1

  v0 = &OtherCell_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780290) --------------------------------------------------------  // acclient.c:918837
void __cdecl _E197_18()
{
  char *v0; // esi@1

  v0 = &OtherPortal_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherPortal_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007802C0) --------------------------------------------------------  // acclient.c:918850
void __cdecl _E200_22()
{
  char *v0; // esi@1

  v0 = &ExactMatch_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExactMatch_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007802F0) --------------------------------------------------------  // acclient.c:918863
void __cdecl _E203_21()
{
  char *v0; // esi@1

  v0 = &StabList_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StabList_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780320) --------------------------------------------------------  // acclient.c:918876
void __cdecl _E206_25()
{
  char *v0; // esi@1

  v0 = &Period_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Period_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780350) --------------------------------------------------------  // acclient.c:918889
void __cdecl _E209_19()
{
  char *v0; // esi@1

  v0 = &GrannyAnimation_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&GrannyAnimation_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780380) --------------------------------------------------------  // acclient.c:918902
void __cdecl _E212_22()
{
  char *v0; // esi@1

  v0 = &Transform_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Transform_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007803B0) --------------------------------------------------------  // acclient.c:918915
void __cdecl _E215_19()
{
  char *v0; // esi@1

  v0 = &Scale_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007803E0) --------------------------------------------------------  // acclient.c:918928
void __cdecl _E218_19()
{
  char *v0; // esi@1

  v0 = &Weight_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weight_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780410) --------------------------------------------------------  // acclient.c:918941
void __cdecl _E221_19()
{
  char *v0; // esi@1

  v0 = &Offset_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Offset_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780440) --------------------------------------------------------  // acclient.c:918954
void __cdecl _E224_19()
{
  char *v0; // esi@1

  v0 = &Quaternion_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Quaternion_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780470) --------------------------------------------------------  // acclient.c:918967
void __cdecl _E227_19()
{
  char *v0; // esi@1

  v0 = &Rotation_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007804A0) --------------------------------------------------------  // acclient.c:918980
void __cdecl _E230_20()
{
  char *v0; // esi@1

  v0 = &STime_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&STime_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007804D0) --------------------------------------------------------  // acclient.c:918993
void __cdecl _E233_19()
{
  char *v0; // esi@1

  v0 = &PhysicsSplines_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsSplines_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780500) --------------------------------------------------------  // acclient.c:919006
void __cdecl _E236_18()
{
  char *v0; // esi@1

  v0 = &BoneOpacities_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BoneOpacities_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780530) --------------------------------------------------------  // acclient.c:919019
void __cdecl _E239_18()
{
  char *v0; // esi@1

  v0 = &LowPt_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LowPt_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780560) --------------------------------------------------------  // acclient.c:919032
void __cdecl _E242_18()
{
  char *v0; // esi@1

  v0 = &Radius_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Radius_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780590) --------------------------------------------------------  // acclient.c:919045
void __cdecl _E245_17()
{
  char *v0; // esi@1

  v0 = &Height_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Height_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007805C0) --------------------------------------------------------  // acclient.c:919058
void __cdecl _E248_17()
{
  char *v0; // esi@1

  v0 = &Texture2D_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture2D_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007805F0) --------------------------------------------------------  // acclient.c:919071
void __cdecl _E251_16()
{
  char *v0; // esi@1

  v0 = &Texture3D_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture3D_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780620) --------------------------------------------------------  // acclient.c:919084
void __cdecl _E254_17()
{
  char *v0; // esi@1

  v0 = &TextureCube_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureCube_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780650) --------------------------------------------------------  // acclient.c:919097
void __cdecl _E257_15()
{
  char *v0; // esi@1

  v0 = &TextureMovie2D_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureMovie2D_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780680) --------------------------------------------------------  // acclient.c:919110
void __cdecl _E260_16()
{
  char *v0; // esi@1

  v0 = &MovieFileName_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFileName_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007806B0) --------------------------------------------------------  // acclient.c:919123
void __cdecl _E263_15()
{
  char *v0; // esi@1

  v0 = &MovieFramesPerSecond_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFramesPerSecond_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007806E0) --------------------------------------------------------  // acclient.c:919136
void __cdecl _E266_15()
{
  char *v0; // esi@1

  v0 = &Levels_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Levels_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780710) --------------------------------------------------------  // acclient.c:919149
void __cdecl _E269_14()
{
  char *v0; // esi@1

  v0 = &stru_8F7F70.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F7F70.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780740) --------------------------------------------------------  // acclient.c:919162
void __cdecl _E272_13()
{
  char *v0; // esi@1

  v0 = &Material_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780770) --------------------------------------------------------  // acclient.c:919175
void __cdecl _E275_13()
{
  char *v0; // esi@1

  v0 = &MaterialType_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialType_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007807A0) --------------------------------------------------------  // acclient.c:919188
void __cdecl _E278_13()
{
  char *v0; // esi@1

  v0 = &Modifier_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Modifier_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007807D0) --------------------------------------------------------  // acclient.c:919201
void __cdecl _E281_13()
{
  char *v0; // esi@1

  v0 = &AllowStencilShadows_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AllowStencilShadows_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780800) --------------------------------------------------------  // acclient.c:919214
void __cdecl _E284_11()
{
  char *v0; // esi@1

  v0 = &DiscardGeometry_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DiscardGeometry_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780830) --------------------------------------------------------  // acclient.c:919227
void __cdecl _E287_12()
{
  char *v0; // esi@1

  v0 = &stru_8F7F88.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F7F88.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780860) --------------------------------------------------------  // acclient.c:919240
void __cdecl _E290_11()
{
  char *v0; // esi@1

  v0 = &SortMode_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780890) --------------------------------------------------------  // acclient.c:919253
void __cdecl _E293_10()
{
  char *v0; // esi@1

  v0 = &SortMode_None_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_None_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007808C0) --------------------------------------------------------  // acclient.c:919266
void __cdecl _E296_11()
{
  char *v0; // esi@1

  v0 = &SortMode_Triangle_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_Triangle_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007808F0) --------------------------------------------------------  // acclient.c:919279
void __cdecl _E299_9()
{
  char *v0; // esi@1

  v0 = &stru_8F7F98.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F7F98.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780920) --------------------------------------------------------  // acclient.c:919292
void __cdecl _E302_10()
{
  char *v0; // esi@1

  v0 = &stru_8F7F9C.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F7F9C.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780950) --------------------------------------------------------  // acclient.c:919305
void __cdecl _E305_9()
{
  char *v0; // esi@1

  v0 = &DataType_DATA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_DATA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780980) --------------------------------------------------------  // acclient.c:919318
void __cdecl _E308_10()
{
  char *v0; // esi@1

  v0 = &DataType_WAVEFORM_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_WAVEFORM_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007809B0) --------------------------------------------------------  // acclient.c:919331
void __cdecl _E311_9()
{
  char *v0; // esi@1

  v0 = &DataType_COLOR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_COLOR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007809E0) --------------------------------------------------------  // acclient.c:919344
void __cdecl _E314_10()
{
  char *v0; // esi@1

  v0 = &DataType_TEXTURE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_TEXTURE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780A10) --------------------------------------------------------  // acclient.c:919357
void __cdecl _E317_9()
{
  char *v0; // esi@1

  v0 = &DataType_BOOL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_BOOL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780A40) --------------------------------------------------------  // acclient.c:919370
void __cdecl _E320_10()
{
  char *v0; // esi@1

  v0 = &stru_8F7FB4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F7FB4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780A70) --------------------------------------------------------  // acclient.c:919383
void __cdecl _E323_8()
{
  char *v0; // esi@1

  v0 = &modType_UVTranslate_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTranslate_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780AA0) --------------------------------------------------------  // acclient.c:919396
void __cdecl _E326_9()
{
  char *v0; // esi@1

  v0 = &modType_UVRotate_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVRotate_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780AD0) --------------------------------------------------------  // acclient.c:919409
void __cdecl _E329_8()
{
  char *v0; // esi@1

  v0 = &modType_UVScale_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVScale_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780B00) --------------------------------------------------------  // acclient.c:919422
void __cdecl _E332_9()
{
  char *v0; // esi@1

  v0 = &modType_UVTransform_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTransform_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780B30) --------------------------------------------------------  // acclient.c:919435
void __cdecl _E335_8()
{
  char *v0; // esi@1

  v0 = &TrueFlags_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TrueFlags_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780B60) --------------------------------------------------------  // acclient.c:919448
void __cdecl _E338_8()
{
  char *v0; // esi@1

  v0 = &FalseFlags_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FalseFlags_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780B90) --------------------------------------------------------  // acclient.c:919461
void __cdecl _E341_8()
{
  char *v0; // esi@1

  v0 = &RenderPass_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderPass_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780BC0) --------------------------------------------------------  // acclient.c:919474
void __cdecl _E344_5()
{
  char *v0; // esi@1

  v0 = &Blend_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Blend_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780BF0) --------------------------------------------------------  // acclient.c:919487
void __cdecl _E347_5()
{
  char *v0; // esi@1

  v0 = &DepthTest_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthTest_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780C20) --------------------------------------------------------  // acclient.c:919500
void __cdecl _E350_5()
{
  char *v0; // esi@1

  v0 = &DepthWrite_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthWrite_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780C50) --------------------------------------------------------  // acclient.c:919513
void __cdecl _E353_5()
{
  char *v0; // esi@1

  v0 = &CullMode_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CullMode_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780C80) --------------------------------------------------------  // acclient.c:919526
void __cdecl _E356_5()
{
  char *v0; // esi@1

  v0 = &DepthFog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthFog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780CB0) --------------------------------------------------------  // acclient.c:919539
void __cdecl _E359_5()
{
  char *v0; // esi@1

  v0 = &AlphaTestMode_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestMode_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780CE0) --------------------------------------------------------  // acclient.c:919552
void __cdecl _E362_5()
{
  char *v0; // esi@1

  v0 = &AlphaTestRef_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestRef_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780D10) --------------------------------------------------------  // acclient.c:919565
void __cdecl _E365_5()
{
  char *v0; // esi@1

  v0 = &FFUseLighting_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseLighting_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780D40) --------------------------------------------------------  // acclient.c:919578
void __cdecl _E368_5()
{
  char *v0; // esi@1

  v0 = &FFUseDyeColorInTFactor_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDyeColorInTFactor_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780D70) --------------------------------------------------------  // acclient.c:919591
void __cdecl _E371_5()
{
  char *v0; // esi@1

  v0 = &FFUseSpecularLighting_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseSpecularLighting_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780DA0) --------------------------------------------------------  // acclient.c:919604
void __cdecl _E374_5()
{
  char *v0; // esi@1

  v0 = &FFUseDistanceFog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDistanceFog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780DD0) --------------------------------------------------------  // acclient.c:919617
void __cdecl _E377_5()
{
  char *v0; // esi@1

  v0 = &FFUseVertexDiffuse_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexDiffuse_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780E00) --------------------------------------------------------  // acclient.c:919630
void __cdecl _E380_5()
{
  char *v0; // esi@1

  v0 = &FFUseVertexSpecular_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexSpecular_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780E30) --------------------------------------------------------  // acclient.c:919643
void __cdecl _E383_5()
{
  char *v0; // esi@1

  v0 = &ShaderSupportsDynamicLights_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ShaderSupportsDynamicLights_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780E60) --------------------------------------------------------  // acclient.c:919656
void __cdecl _E386_5()
{
  char *v0; // esi@1

  v0 = &UsesTransparency_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UsesTransparency_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780E90) --------------------------------------------------------  // acclient.c:919669
void __cdecl _E389_5()
{
  char *v0; // esi@1

  v0 = &Ambient_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Ambient_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780EC0) --------------------------------------------------------  // acclient.c:919682
void __cdecl _E392_5()
{
  char *v0; // esi@1

  v0 = &Diffuse_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780EF0) --------------------------------------------------------  // acclient.c:919695
void __cdecl _E395_5()
{
  char *v0; // esi@1

  v0 = &Specular_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780F20) --------------------------------------------------------  // acclient.c:919708
void __cdecl _E398_5()
{
  char *v0; // esi@1

  v0 = &SpecularPower_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecularPower_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780F50) --------------------------------------------------------  // acclient.c:919721
void __cdecl _E401_5()
{
  char *v0; // esi@1

  v0 = &Dye_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Dye_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780F80) --------------------------------------------------------  // acclient.c:919734
void __cdecl _E404_5()
{
  char *v0; // esi@1

  v0 = &Emissive_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Emissive_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780FB0) --------------------------------------------------------  // acclient.c:919747
void __cdecl _E407_5()
{
  char *v0; // esi@1

  v0 = &VertexFormat_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexFormat_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00780FE0) --------------------------------------------------------  // acclient.c:919760
void __cdecl _E410_5()
{
  char *v0; // esi@1

  v0 = &VertexShader_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexShader_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781010) --------------------------------------------------------  // acclient.c:919773
void __cdecl _E413_5()
{
  char *v0; // esi@1

  v0 = &PixelShader_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PixelShader_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781040) --------------------------------------------------------  // acclient.c:919786
void __cdecl _E416_5()
{
  char *v0; // esi@1

  v0 = &param_MLF_NONE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_NONE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781070) --------------------------------------------------------  // acclient.c:919799
void __cdecl _E419_5()
{
  char *v0; // esi@1

  v0 = &param_MLF_REFLECTIONS_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_REFLECTIONS_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007810A0) --------------------------------------------------------  // acclient.c:919812
void __cdecl _E422_5()
{
  char *v0; // esi@1

  v0 = &param_MLF_VIDEOPOST_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_VIDEOPOST_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007810D0) --------------------------------------------------------  // acclient.c:919825
void __cdecl _E425_5()
{
  char *v0; // esi@1

  v0 = &param_MLF_HIGHDETAIL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_HIGHDETAIL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781100) --------------------------------------------------------  // acclient.c:919838
void __cdecl _E428_5()
{
  char *v0; // esi@1

  v0 = &param_MLF_SPECULAR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_SPECULAR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781130) --------------------------------------------------------  // acclient.c:919851
void __cdecl _E431_5()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS1_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS1_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781160) --------------------------------------------------------  // acclient.c:919864
void __cdecl _E434_5()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS2_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS2_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781190) --------------------------------------------------------  // acclient.c:919877
void __cdecl _E437_5()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS3_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS3_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007811C0) --------------------------------------------------------  // acclient.c:919890
void __cdecl _E440_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_Default_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_Default_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007811F0) --------------------------------------------------------  // acclient.c:919903
void __cdecl _E443_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DirectionalLightDiffuseAndSpecular_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DirectionalLightDiffuseAndSpecular_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781220) --------------------------------------------------------  // acclient.c:919916
void __cdecl _E446_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecular_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecular_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781250) --------------------------------------------------------  // acclient.c:919929
void __cdecl _E449_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecularProjector_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecularProjector_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781280) --------------------------------------------------------  // acclient.c:919942
void __cdecl _E452_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007812B0) --------------------------------------------------------  // acclient.c:919955
void __cdecl _E455_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007812E0) --------------------------------------------------------  // acclient.c:919968
void __cdecl _E458_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DistanceFog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DistanceFog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781310) --------------------------------------------------------  // acclient.c:919981
void __cdecl _E461_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_FixedFunctionGlow_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_FixedFunctionGlow_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781340) --------------------------------------------------------  // acclient.c:919994
void __cdecl _E464_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_ShaderGlow_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_ShaderGlow_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781370) --------------------------------------------------------  // acclient.c:920007
void __cdecl _E467_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_LandscapeShadowMap_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_LandscapeShadowMap_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007813A0) --------------------------------------------------------  // acclient.c:920020
void __cdecl _E470_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AlphaBlend_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AlphaBlend_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007813D0) --------------------------------------------------------  // acclient.c:920033
void __cdecl _E473_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781400) --------------------------------------------------------  // acclient.c:920046
void __cdecl _E476_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781430) --------------------------------------------------------  // acclient.c:920059
void __cdecl _E479_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781460) --------------------------------------------------------  // acclient.c:920072
void __cdecl _E482_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781490) --------------------------------------------------------  // acclient.c:920085
void __cdecl _E485_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007814C0) --------------------------------------------------------  // acclient.c:920098
void __cdecl _E488_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007814F0) --------------------------------------------------------  // acclient.c:920111
void __cdecl _E491_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781520) --------------------------------------------------------  // acclient.c:920124
void __cdecl _E494_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781550) --------------------------------------------------------  // acclient.c:920137
void __cdecl _E497_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781580) --------------------------------------------------------  // acclient.c:920150
void __cdecl _E500_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007815B0) --------------------------------------------------------  // acclient.c:920163
void __cdecl _E503_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007815E0) --------------------------------------------------------  // acclient.c:920176
void __cdecl _E506_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781610) --------------------------------------------------------  // acclient.c:920189
void __cdecl _E509_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781640) --------------------------------------------------------  // acclient.c:920202
void __cdecl _E512_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781670) --------------------------------------------------------  // acclient.c:920215
void __cdecl _E515_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007816A0) --------------------------------------------------------  // acclient.c:920228
void __cdecl _E518_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007816D0) --------------------------------------------------------  // acclient.c:920241
void __cdecl _E521_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781700) --------------------------------------------------------  // acclient.c:920254
void __cdecl _E524_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781730) --------------------------------------------------------  // acclient.c:920267
void __cdecl _E527_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781760) --------------------------------------------------------  // acclient.c:920280
void __cdecl _E530_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781790) --------------------------------------------------------  // acclient.c:920293
void __cdecl _E533_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007817C0) --------------------------------------------------------  // acclient.c:920306
void __cdecl _E536_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007817F0) --------------------------------------------------------  // acclient.c:920319
void __cdecl _E539_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781820) --------------------------------------------------------  // acclient.c:920332
void __cdecl _E542_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781850) --------------------------------------------------------  // acclient.c:920345
void __cdecl _E545_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781880) --------------------------------------------------------  // acclient.c:920358
void __cdecl _E548_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007818B0) --------------------------------------------------------  // acclient.c:920371
void __cdecl _E551_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007818E0) --------------------------------------------------------  // acclient.c:920384
void __cdecl _E554_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781910) --------------------------------------------------------  // acclient.c:920397
void __cdecl _E557_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781940) --------------------------------------------------------  // acclient.c:920410
void __cdecl _E560_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781970) --------------------------------------------------------  // acclient.c:920423
void __cdecl _E563_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007819A0) --------------------------------------------------------  // acclient.c:920436
void __cdecl _E566_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007819D0) --------------------------------------------------------  // acclient.c:920449
void __cdecl _E569_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781A00) --------------------------------------------------------  // acclient.c:920462
void __cdecl _E572_5()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_Fog_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_Fog_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781A30) --------------------------------------------------------  // acclient.c:920475
void __cdecl _E575_5()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ZERO_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ZERO_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781A60) --------------------------------------------------------  // acclient.c:920488
void __cdecl _E578_5()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ONE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ONE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781A90) --------------------------------------------------------  // acclient.c:920501
void __cdecl _E581_5()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCCOLOR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCCOLOR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781AC0) --------------------------------------------------------  // acclient.c:920514
void __cdecl _E584_5()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCCOLOR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCCOLOR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781AF0) --------------------------------------------------------  // acclient.c:920527
void __cdecl _E587_5()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781B20) --------------------------------------------------------  // acclient.c:920540
void __cdecl _E590_5()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCALPHA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCALPHA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781B50) --------------------------------------------------------  // acclient.c:920553
void __cdecl _E593_5()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTALPHA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTALPHA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781B80) --------------------------------------------------------  // acclient.c:920566
void __cdecl _E596_5()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTALPHA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTALPHA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781BB0) --------------------------------------------------------  // acclient.c:920579
void __cdecl _E599_5()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTCOLOR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTCOLOR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781BE0) --------------------------------------------------------  // acclient.c:920592
void __cdecl _E602_5()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTCOLOR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTCOLOR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781C10) --------------------------------------------------------  // acclient.c:920605
void __cdecl _E605_5()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHASAT_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHASAT_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781C40) --------------------------------------------------------  // acclient.c:920618
void __cdecl _E608_5()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESS_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESS_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781C70) --------------------------------------------------------  // acclient.c:920631
void __cdecl _E611_5()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_EQUAL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_EQUAL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781CA0) --------------------------------------------------------  // acclient.c:920644
void __cdecl _E614_5()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESSEQUAL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESSEQUAL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781CD0) --------------------------------------------------------  // acclient.c:920657
void __cdecl _E617_5()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATER_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATER_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781D00) --------------------------------------------------------  // acclient.c:920670
void __cdecl _E620_5()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_NOTEQUAL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_NOTEQUAL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781D30) --------------------------------------------------------  // acclient.c:920683
void __cdecl _E623_5()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATEREQUAL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATEREQUAL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781D60) --------------------------------------------------------  // acclient.c:920696
void __cdecl _E626_5()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_ALWAYS_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_ALWAYS_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781D90) --------------------------------------------------------  // acclient.c:920709
void __cdecl _E629_5()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_ON_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_ON_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781DC0) --------------------------------------------------------  // acclient.c:920722
void __cdecl _E632_5()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_OFF_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_OFF_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781DF0) --------------------------------------------------------  // acclient.c:920735
void __cdecl _E635_5()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERDIFFUSE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERDIFFUSE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781E20) --------------------------------------------------------  // acclient.c:920748
void __cdecl _E638_5()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERSPECULAR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERSPECULAR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781E50) --------------------------------------------------------  // acclient.c:920761
void __cdecl _E641_5()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXDIFFUSE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXDIFFUSE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781E80) --------------------------------------------------------  // acclient.c:920774
void __cdecl _E644_5()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXSPECULAR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXSPECULAR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781EB0) --------------------------------------------------------  // acclient.c:920787
void __cdecl _E647_5()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_NONE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_NONE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781EE0) --------------------------------------------------------  // acclient.c:920800
void __cdecl _E650_5()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CW_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CW_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781F10) --------------------------------------------------------  // acclient.c:920813
void __cdecl _E653_5()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CCW_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CCW_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781F40) --------------------------------------------------------  // acclient.c:920826
void __cdecl _E656_5()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_NONE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_NONE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781F70) --------------------------------------------------------  // acclient.c:920839
void __cdecl _E659_5()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SIMPLE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SIMPLE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781FA0) --------------------------------------------------------  // acclient.c:920852
void __cdecl _E662_5()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_DIFFUSE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_DIFFUSE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00781FD0) --------------------------------------------------------  // acclient.c:920865
void __cdecl _E665_5()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SPECULAR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SPECULAR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782000) --------------------------------------------------------  // acclient.c:920878
void __cdecl _E668_5()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_OFF_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_OFF_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782030) --------------------------------------------------------  // acclient.c:920891
void __cdecl _E671_5()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_ON_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_ON_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782060) --------------------------------------------------------  // acclient.c:920904
void __cdecl _E674_5()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_OFF_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_OFF_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782090) --------------------------------------------------------  // acclient.c:920917
void __cdecl _E677_5()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_ON_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_ON_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007820C0) --------------------------------------------------------  // acclient.c:920930
void __cdecl _E680_5()
{
  char *v0; // esi@1

  v0 = &param_VF_ORIGIN_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_ORIGIN_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007820F0) --------------------------------------------------------  // acclient.c:920943
void __cdecl _E683_5()
{
  char *v0; // esi@1

  v0 = &param_VF_NORMAL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_NORMAL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782120) --------------------------------------------------------  // acclient.c:920956
void __cdecl _E686_5()
{
  char *v0; // esi@1

  v0 = &param_VF_POINTSIZE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_POINTSIZE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782150) --------------------------------------------------------  // acclient.c:920969
void __cdecl _E689_5()
{
  char *v0; // esi@1

  v0 = &param_VF_DIFFUSE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_DIFFUSE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782180) --------------------------------------------------------  // acclient.c:920982
void __cdecl _E692_5()
{
  char *v0; // esi@1

  v0 = &param_VF_SPECULAR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_SPECULAR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007821B0) --------------------------------------------------------  // acclient.c:920995
void __cdecl _E695_5()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx1_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx1_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007821E0) --------------------------------------------------------  // acclient.c:921008
void __cdecl _E698_5()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx2_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx2_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782210) --------------------------------------------------------  // acclient.c:921021
void __cdecl _E701_5()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx3_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx3_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782240) --------------------------------------------------------  // acclient.c:921034
void __cdecl _E704_5()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx4_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx4_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782270) --------------------------------------------------------  // acclient.c:921047
void __cdecl _E707_5()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx5_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx5_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007822A0) --------------------------------------------------------  // acclient.c:921060
void __cdecl _E710_5()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx6_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx6_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007822D0) --------------------------------------------------------  // acclient.c:921073
void __cdecl _E713_5()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx7_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx7_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782300) --------------------------------------------------------  // acclient.c:921086
void __cdecl _E716_5()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx8_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx8_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782330) --------------------------------------------------------  // acclient.c:921099
void __cdecl _E719_5()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_S_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_S_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782360) --------------------------------------------------------  // acclient.c:921112
void __cdecl _E722_5()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_T_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_T_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782390) --------------------------------------------------------  // acclient.c:921125
void __cdecl _E725_5()
{
  char *v0; // esi@1

  v0 = &stru_8F81D0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F81D0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007823C0) --------------------------------------------------------  // acclient.c:921138
void __cdecl _E728_5()
{
  char *v0; // esi@1

  v0 = &SamplerNodeName_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerNodeName_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007823F0) --------------------------------------------------------  // acclient.c:921151
void __cdecl _E731_5()
{
  char *v0; // esi@1

  v0 = &SamplerName_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerName_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782420) --------------------------------------------------------  // acclient.c:921164
void __cdecl _E734_5()
{
  char *v0; // esi@1

  v0 = &Texture_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782450) --------------------------------------------------------  // acclient.c:921177
void __cdecl _E737_5()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_FrameBuffer_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_FrameBuffer_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782480) --------------------------------------------------------  // acclient.c:921190
void __cdecl _E740_5()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Distortion_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Distortion_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007824B0) --------------------------------------------------------  // acclient.c:921203
void __cdecl _E743_5()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Reflection_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Reflection_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007824E0) --------------------------------------------------------  // acclient.c:921216
void __cdecl _E746_5()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_NormalizeCube_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_NormalizeCube_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782510) --------------------------------------------------------  // acclient.c:921229
void __cdecl _E749_5()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LightProjectorCube_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LightProjectorCube_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782540) --------------------------------------------------------  // acclient.c:921242
void __cdecl _E752_5()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_EnvironmentCube_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_EnvironmentCube_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782570) --------------------------------------------------------  // acclient.c:921255
void __cdecl _E755_5()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LandscapeShadows_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LandscapeShadows_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007825A0) --------------------------------------------------------  // acclient.c:921268
void __cdecl _E758_5()
{
  char *v0; // esi@1

  v0 = &AddressMode_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AddressMode_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007825D0) --------------------------------------------------------  // acclient.c:921281
void __cdecl _E761_5()
{
  char *v0; // esi@1

  v0 = &TexFilter_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexFilter_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782600) --------------------------------------------------------  // acclient.c:921294
void __cdecl _E764_5()
{
  char *v0; // esi@1

  v0 = &ColorOp_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorOp_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782630) --------------------------------------------------------  // acclient.c:921307
void __cdecl _E767_5()
{
  char *v0; // esi@1

  v0 = &ColorArg1_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg1_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782660) --------------------------------------------------------  // acclient.c:921320
void __cdecl _E770_5()
{
  char *v0; // esi@1

  v0 = &ColorArg2_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg2_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782690) --------------------------------------------------------  // acclient.c:921333
void __cdecl _E773_5()
{
  char *v0; // esi@1

  v0 = &AlphaOp_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaOp_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007826C0) --------------------------------------------------------  // acclient.c:921346
void __cdecl _E776_5()
{
  char *v0; // esi@1

  v0 = &AlphaArg1_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg1_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007826F0) --------------------------------------------------------  // acclient.c:921359
void __cdecl _E779_5()
{
  char *v0; // esi@1

  v0 = &AlphaArg2_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg2_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782720) --------------------------------------------------------  // acclient.c:921372
void __cdecl _E782_5()
{
  char *v0; // esi@1

  v0 = &TexCoord_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexCoord_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782750) --------------------------------------------------------  // acclient.c:921385
void __cdecl _E785_5()
{
  char *v0; // esi@1

  v0 = &UseProjection_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseProjection_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782780) --------------------------------------------------------  // acclient.c:921398
void __cdecl _E788_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG1_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG1_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007827B0) --------------------------------------------------------  // acclient.c:921411
void __cdecl _E791_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG2_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG2_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007827E0) --------------------------------------------------------  // acclient.c:921424
void __cdecl _E794_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782810) --------------------------------------------------------  // acclient.c:921437
void __cdecl _E797_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE2X_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE2X_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782840) --------------------------------------------------------  // acclient.c:921450
void __cdecl _E800_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE4X_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE4X_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782870) --------------------------------------------------------  // acclient.c:921463
void __cdecl _E803_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADD_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADD_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007828A0) --------------------------------------------------------  // acclient.c:921476
void __cdecl _E806_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007828D0) --------------------------------------------------------  // acclient.c:921489
void __cdecl _E809_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED2X_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED2X_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782900) --------------------------------------------------------  // acclient.c:921502
void __cdecl _E812_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SUBTRACT_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SUBTRACT_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782930) --------------------------------------------------------  // acclient.c:921515
void __cdecl _E815_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSMOOTH_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSMOOTH_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782960) --------------------------------------------------------  // acclient.c:921528
void __cdecl _E818_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDDIFFUSEALPHA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDDIFFUSEALPHA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782990) --------------------------------------------------------  // acclient.c:921541
void __cdecl _E821_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007829C0) --------------------------------------------------------  // acclient.c:921554
void __cdecl _E824_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDFACTORALPHA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDFACTORALPHA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007829F0) --------------------------------------------------------  // acclient.c:921567
void __cdecl _E827_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHAPM_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHAPM_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782A20) --------------------------------------------------------  // acclient.c:921580
void __cdecl _E830_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDCURRENTALPHA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDCURRENTALPHA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782A50) --------------------------------------------------------  // acclient.c:921593
void __cdecl _E833_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_PREMODULATE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_PREMODULATE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782A80) --------------------------------------------------------  // acclient.c:921606
void __cdecl _E836_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEALPHA_ADDCOLOR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEALPHA_ADDCOLOR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782AB0) --------------------------------------------------------  // acclient.c:921619
void __cdecl _E839_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATECOLOR_ADDALPHA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATECOLOR_ADDALPHA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782AE0) --------------------------------------------------------  // acclient.c:921632
void __cdecl _E842_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVALPHA_ADDCOLOR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782B10) --------------------------------------------------------  // acclient.c:921645
void __cdecl _E845_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVCOLOR_ADDALPHA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782B40) --------------------------------------------------------  // acclient.c:921658
void __cdecl _E848_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAP_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAP_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782B70) --------------------------------------------------------  // acclient.c:921671
void __cdecl _E851_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAPLUMINANCE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAPLUMINANCE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782BA0) --------------------------------------------------------  // acclient.c:921684
void __cdecl _E854_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_DOTPRODUCT3_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_DOTPRODUCT3_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782BD0) --------------------------------------------------------  // acclient.c:921697
void __cdecl _E857_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MULTIPLYADD_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MULTIPLYADD_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782C00) --------------------------------------------------------  // acclient.c:921710
void __cdecl _E860_5()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_LERP_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_LERP_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782C30) --------------------------------------------------------  // acclient.c:921723
void __cdecl _E863_5()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_DIFFUSE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_DIFFUSE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782C60) --------------------------------------------------------  // acclient.c:921736
void __cdecl _E866_5()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_SPECULAR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_SPECULAR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782C90) --------------------------------------------------------  // acclient.c:921749
void __cdecl _E869_5()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_CURRENT_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_CURRENT_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782CC0) --------------------------------------------------------  // acclient.c:921762
void __cdecl _E872_5()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TEXTURE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TEXTURE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782CF0) --------------------------------------------------------  // acclient.c:921775
void __cdecl _E875_5()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TFACTOR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TFACTOR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782D20) --------------------------------------------------------  // acclient.c:921788
void __cdecl _E878_5()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_WRAP_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_WRAP_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782D50) --------------------------------------------------------  // acclient.c:921801
void __cdecl _E881_5()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_MIRROR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_MIRROR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782D80) --------------------------------------------------------  // acclient.c:921814
void __cdecl _E884_5()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_CLAMP_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_CLAMP_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782DB0) --------------------------------------------------------  // acclient.c:921827
void __cdecl _E887_5()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_BORDER_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_BORDER_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782DE0) --------------------------------------------------------  // acclient.c:921840
void __cdecl _E890_5()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_NONE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_NONE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782E10) --------------------------------------------------------  // acclient.c:921853
void __cdecl _E893_5()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_POINT_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_POINT_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782E40) --------------------------------------------------------  // acclient.c:921866
void __cdecl _E896_5()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_LINEAR_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_LINEAR_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782E70) --------------------------------------------------------  // acclient.c:921879
void __cdecl _E899_5()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_ANISOTROPIC_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_ANISOTROPIC_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782EA0) --------------------------------------------------------  // acclient.c:921892
void __cdecl _E902_5()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ReflectionVector_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ReflectionVector_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782ED0) --------------------------------------------------------  // acclient.c:921905
void __cdecl _E905_5()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewNormal_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewNormal_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782F00) --------------------------------------------------------  // acclient.c:921918
void __cdecl _E908_5()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewOrigin_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewOrigin_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782F30) --------------------------------------------------------  // acclient.c:921931
void __cdecl _E911_5()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_SphereMap_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_SphereMap_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782F60) --------------------------------------------------------  // acclient.c:921944
void __cdecl _E914_5()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapReflection_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapReflection_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782F90) --------------------------------------------------------  // acclient.c:921957
void __cdecl _E917_5()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapFakeLight_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapFakeLight_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782FC0) --------------------------------------------------------  // acclient.c:921970
void __cdecl _E920_5()
{
  char *v0; // esi@1

  v0 = &stru_8F82D4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F82D4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00782FF0) --------------------------------------------------------  // acclient.c:921983
void __cdecl _E923_5()
{
  char *v0; // esi@1

  v0 = &ModType_Origin_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Origin_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783020) --------------------------------------------------------  // acclient.c:921996
void __cdecl _E926_5()
{
  char *v0; // esi@1

  v0 = &ModType_Normal_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Normal_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783050) --------------------------------------------------------  // acclient.c:922009
void __cdecl _E929_5()
{
  char *v0; // esi@1

  v0 = &ModType_Diffuse_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Diffuse_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783080) --------------------------------------------------------  // acclient.c:922022
void __cdecl _E932_5()
{
  char *v0; // esi@1

  v0 = &ModType_UVTranslate_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTranslate_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007830B0) --------------------------------------------------------  // acclient.c:922035
void __cdecl _E935_5()
{
  char *v0; // esi@1

  v0 = &ModType_UVRotate_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVRotate_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007830E0) --------------------------------------------------------  // acclient.c:922048
void __cdecl _E938_5()
{
  char *v0; // esi@1

  v0 = &ModType_UVScale_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVScale_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783110) --------------------------------------------------------  // acclient.c:922061
void __cdecl _E941_5()
{
  char *v0; // esi@1

  v0 = &ModType_UVTransform_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTransform_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783140) --------------------------------------------------------  // acclient.c:922074
void __cdecl _E944_5()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_texCoordIndex_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_texCoordIndex_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783170) --------------------------------------------------------  // acclient.c:922087
void __cdecl _E947_5()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_translate_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_translate_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007831A0) --------------------------------------------------------  // acclient.c:922100
void __cdecl _E950_5()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_texCoordIndex_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_texCoordIndex_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007831D0) --------------------------------------------------------  // acclient.c:922113
void __cdecl _E953_5()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_rotate_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_rotate_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783200) --------------------------------------------------------  // acclient.c:922126
void __cdecl _E956_5()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_texCoordIndex_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_texCoordIndex_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783230) --------------------------------------------------------  // acclient.c:922139
void __cdecl _E959_5()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_scale_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_scale_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783260) --------------------------------------------------------  // acclient.c:922152
void __cdecl _E962_5()
{
  char *v0; // esi@1

  v0 = &stru_8F830C.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F830C.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783290) --------------------------------------------------------  // acclient.c:922165
void __cdecl _E965_5()
{
  char *v0; // esi@1

  v0 = &PhysicsTimeStep_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsTimeStep_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007832C0) --------------------------------------------------------  // acclient.c:922178
void __cdecl _E968_5()
{
  char *v0; // esi@1

  v0 = &FastForwardTime_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FastForwardTime_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007832F0) --------------------------------------------------------  // acclient.c:922191
void __cdecl _E971_5()
{
  char *v0; // esi@1

  v0 = &StartFadeDistance_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartFadeDistance_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783320) --------------------------------------------------------  // acclient.c:922204
void __cdecl _E974_5()
{
  char *v0; // esi@1

  v0 = &StopFadeDistance_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StopFadeDistance_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783350) --------------------------------------------------------  // acclient.c:922217
void __cdecl _E977_5()
{
  char *v0; // esi@1

  v0 = &PhysicsDuration_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsDuration_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783380) --------------------------------------------------------  // acclient.c:922230
void __cdecl _E980_5()
{
  char *v0; // esi@1

  v0 = &ScaleType_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleType_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007833B0) --------------------------------------------------------  // acclient.c:922243
void __cdecl _E983_5()
{
  char *v0; // esi@1

  v0 = &WorldSpace_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldSpace_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007833E0) --------------------------------------------------------  // acclient.c:922256
void __cdecl _E986_5()
{
  char *v0; // esi@1

  v0 = &ForceDraw_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ForceDraw_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783410) --------------------------------------------------------  // acclient.c:922269
void __cdecl _E989_5()
{
  char *v0; // esi@1

  v0 = &NumEmitters_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumEmitters_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783440) --------------------------------------------------------  // acclient.c:922282
void __cdecl _E992_5()
{
  char *v0; // esi@1

  v0 = &Material_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783470) --------------------------------------------------------  // acclient.c:922295
void __cdecl _E995_5()
{
  char *v0; // esi@1

  v0 = &Version_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Version_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007834A0) --------------------------------------------------------  // acclient.c:922308
void __cdecl _E998_5()
{
  char *v0; // esi@1

  v0 = &MaxParticles_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxParticles_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007834D0) --------------------------------------------------------  // acclient.c:922321
void __cdecl _E1001_5()
{
  char *v0; // esi@1

  v0 = &stru_8F8340.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F8340.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783500) --------------------------------------------------------  // acclient.c:922334
void __cdecl _E1004_5()
{
  char *v0; // esi@1

  v0 = &Origin_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783530) --------------------------------------------------------  // acclient.c:922347
void __cdecl _E1007_5()
{
  char *v0; // esi@1

  v0 = &Shape_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783560) --------------------------------------------------------  // acclient.c:922360
void __cdecl _E1010_5()
{
  char *v0; // esi@1

  v0 = &Shape_Point_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Point_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783590) --------------------------------------------------------  // acclient.c:922373
void __cdecl _E1013_5()
{
  char *v0; // esi@1

  v0 = &Shape_Line_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Line_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007835C0) --------------------------------------------------------  // acclient.c:922386
void __cdecl _E1016_5()
{
  char *v0; // esi@1

  v0 = &Shape_Quad_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Quad_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007835F0) --------------------------------------------------------  // acclient.c:922399
void __cdecl _E1019_5()
{
  char *v0; // esi@1

  v0 = &Shape_Disc_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Disc_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783620) --------------------------------------------------------  // acclient.c:922412
void __cdecl _E1022_5()
{
  char *v0; // esi@1

  v0 = &Shape_Sphere_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Sphere_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783650) --------------------------------------------------------  // acclient.c:922425
void __cdecl _E1025_5()
{
  char *v0; // esi@1

  v0 = &ParticleShape_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783680) --------------------------------------------------------  // acclient.c:922438
void __cdecl _E1028_5()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Triangle_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Triangle_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007836B0) --------------------------------------------------------  // acclient.c:922451
void __cdecl _E1031_5()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Quad_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Quad_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007836E0) --------------------------------------------------------  // acclient.c:922464
void __cdecl _E1034_5()
{
  char *v0; // esi@1

  v0 = &Streak_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Streak_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783710) --------------------------------------------------------  // acclient.c:922477
void __cdecl _E1037_5()
{
  char *v0; // esi@1

  v0 = &Rotation_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783740) --------------------------------------------------------  // acclient.c:922490
void __cdecl _E1040_5()
{
  char *v0; // esi@1

  v0 = &WorldRotation_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldRotation_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783770) --------------------------------------------------------  // acclient.c:922503
void __cdecl _E1043_5()
{
  char *v0; // esi@1

  v0 = &RotateVelocity_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RotateVelocity_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007837A0) --------------------------------------------------------  // acclient.c:922516
void __cdecl _E1046_5()
{
  char *v0; // esi@1

  v0 = &ParticleScale_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleScale_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007837D0) --------------------------------------------------------  // acclient.c:922529
void __cdecl _E1049_5()
{
  char *v0; // esi@1

  v0 = &Scale_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783800) --------------------------------------------------------  // acclient.c:922542
void __cdecl _E1052_5()
{
  char *v0; // esi@1

  v0 = &ExplodingDir_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExplodingDir_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783830) --------------------------------------------------------  // acclient.c:922555
void __cdecl _E1055_5()
{
  char *v0; // esi@1

  v0 = &BirthRate_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BirthRate_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783860) --------------------------------------------------------  // acclient.c:922568
void __cdecl _E1058_5()
{
  char *v0; // esi@1

  v0 = &Lifespan_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Lifespan_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783890) --------------------------------------------------------  // acclient.c:922581
void __cdecl _E1061_5()
{
  char *v0; // esi@1

  v0 = &Velocity_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Velocity_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007838C0) --------------------------------------------------------  // acclient.c:922594
void __cdecl _E1064_5()
{
  char *v0; // esi@1

  v0 = &Direction_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Direction_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007838F0) --------------------------------------------------------  // acclient.c:922607
void __cdecl _E1067_5()
{
  char *v0; // esi@1

  v0 = &MinSpread_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MinSpread_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783920) --------------------------------------------------------  // acclient.c:922620
void __cdecl _E1070_5()
{
  char *v0; // esi@1

  v0 = &MaxSpread_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxSpread_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783950) --------------------------------------------------------  // acclient.c:922633
void __cdecl _E1073_5()
{
  char *v0; // esi@1

  v0 = &EmissionLimit_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionLimit_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783980) --------------------------------------------------------  // acclient.c:922646
void __cdecl _E1076_5()
{
  char *v0; // esi@1

  v0 = &BlastCount_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BlastCount_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007839B0) --------------------------------------------------------  // acclient.c:922659
void __cdecl _E1079_5()
{
  char *v0; // esi@1

  v0 = &StartTime_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartTime_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007839E0) --------------------------------------------------------  // acclient.c:922672
void __cdecl _E1082_5()
{
  char *v0; // esi@1

  v0 = &TimeLimit_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TimeLimit_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783A10) --------------------------------------------------------  // acclient.c:922685
void __cdecl _E1085_5()
{
  char *v0; // esi@1

  v0 = &EmissionDistance_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionDistance_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783A40) --------------------------------------------------------  // acclient.c:922698
void __cdecl _E1088_5()
{
  char *v0; // esi@1

  v0 = &ParticleSnap_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleSnap_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783A70) --------------------------------------------------------  // acclient.c:922711
void __cdecl _E1091_5()
{
  char *v0; // esi@1

  v0 = &InclusiveShape_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&InclusiveShape_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783AA0) --------------------------------------------------------  // acclient.c:922724
void __cdecl _E1094_5()
{
  char *v0; // esi@1

  v0 = &NumKeyframes_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumKeyframes_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783AD0) --------------------------------------------------------  // acclient.c:922737
void __cdecl _E1097_5()
{
  char *v0; // esi@1

  v0 = &IsActive_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&IsActive_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783B00) --------------------------------------------------------  // acclient.c:922750
void __cdecl _E1100_5()
{
  char *v0; // esi@1

  v0 = &FadeIn_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeIn_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783B30) --------------------------------------------------------  // acclient.c:922763
void __cdecl _E1103_5()
{
  char *v0; // esi@1

  v0 = &FadeOut_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeOut_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783B60) --------------------------------------------------------  // acclient.c:922776
void __cdecl _E1106_5()
{
  char *v0; // esi@1

  v0 = &ConstrainX_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainX_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783B90) --------------------------------------------------------  // acclient.c:922789
void __cdecl _E1109_5()
{
  char *v0; // esi@1

  v0 = &ConstrainY_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainY_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783BC0) --------------------------------------------------------  // acclient.c:922802
void __cdecl _E1112_5()
{
  char *v0; // esi@1

  v0 = &ConstrainZ_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainZ_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783BF0) --------------------------------------------------------  // acclient.c:922815
void __cdecl _E1115_5()
{
  char *v0; // esi@1

  v0 = &stru_8F83D8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F83D8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783C20) --------------------------------------------------------  // acclient.c:922828
void __cdecl _E1118_5()
{
  char *v0; // esi@1

  v0 = &Time_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Time_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783C50) --------------------------------------------------------  // acclient.c:922841
void __cdecl _E1121_5()
{
  char *v0; // esi@1

  v0 = &Flags_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783C80) --------------------------------------------------------  // acclient.c:922854
void __cdecl _E1124_5()
{
  char *v0; // esi@1

  v0 = &Flags_None_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_None_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783CB0) --------------------------------------------------------  // acclient.c:922867
void __cdecl _E1127_5()
{
  char *v0; // esi@1

  v0 = &Flags_BlendScale_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendScale_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783CE0) --------------------------------------------------------  // acclient.c:922880
void __cdecl _E1130_5()
{
  char *v0; // esi@1

  v0 = &Flags_BlendColor_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendColor_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783D10) --------------------------------------------------------  // acclient.c:922893
void __cdecl _E1133_5()
{
  char *v0; // esi@1

  v0 = &Flags_BlendMass_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendMass_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783D40) --------------------------------------------------------  // acclient.c:922906
void __cdecl _E1136_5()
{
  char *v0; // esi@1

  v0 = &Flags_SetScale_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetScale_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783D70) --------------------------------------------------------  // acclient.c:922919
void __cdecl _E1139_5()
{
  char *v0; // esi@1

  v0 = &Flags_SetColor_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetColor_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783DA0) --------------------------------------------------------  // acclient.c:922932
void __cdecl _E1142_5()
{
  char *v0; // esi@1

  v0 = &Flags_SetMass_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetMass_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783DD0) --------------------------------------------------------  // acclient.c:922945
void __cdecl _E1145_5()
{
  char *v0; // esi@1

  v0 = &Flags_SetPFlags_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPFlags_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783E00) --------------------------------------------------------  // acclient.c:922958
void __cdecl _E1148_5()
{
  char *v0; // esi@1

  v0 = &Flags_SetPCType_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPCType_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783E30) --------------------------------------------------------  // acclient.c:922971
void __cdecl _E1151_5()
{
  char *v0; // esi@1

  v0 = &Flags_SetPhysFlags_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPhysFlags_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783E60) --------------------------------------------------------  // acclient.c:922984
void __cdecl _E1154_5()
{
  char *v0; // esi@1

  v0 = &Flags_SetParams_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetParams_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783E90) --------------------------------------------------------  // acclient.c:922997
void __cdecl _E1157_5()
{
  char *v0; // esi@1

  v0 = &Scale_34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_34.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783EC0) --------------------------------------------------------  // acclient.c:923010
void __cdecl _E1160_5()
{
  char *v0; // esi@1

  v0 = &ScaleX_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleX_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783EF0) --------------------------------------------------------  // acclient.c:923023
void __cdecl _E1163_5()
{
  char *v0; // esi@1

  v0 = &ScaleY_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleY_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783F20) --------------------------------------------------------  // acclient.c:923036
void __cdecl _E1166_5()
{
  char *v0; // esi@1

  v0 = &Color_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Color_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783F50) --------------------------------------------------------  // acclient.c:923049
void __cdecl _E1169_5()
{
  char *v0; // esi@1

  v0 = &Mass_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mass_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783F80) --------------------------------------------------------  // acclient.c:923062
void __cdecl _E1172_5()
{
  char *v0; // esi@1

  v0 = &PFlags_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783FB0) --------------------------------------------------------  // acclient.c:923075
void __cdecl _E1175_5()
{
  char *v0; // esi@1

  v0 = &PFlags_None_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_None_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00783FE0) --------------------------------------------------------  // acclient.c:923088
void __cdecl _E1178_5()
{
  char *v0; // esi@1

  v0 = &PCType_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784010) --------------------------------------------------------  // acclient.c:923101
void __cdecl _E1181_5()
{
  char *v0; // esi@1

  v0 = &PCType_None_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_None_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784040) --------------------------------------------------------  // acclient.c:923114
void __cdecl _E1184_5()
{
  char *v0; // esi@1

  v0 = &PCType_Physics_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Physics_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784070) --------------------------------------------------------  // acclient.c:923127
void __cdecl _E1187_5()
{
  char *v0; // esi@1

  v0 = &PCType_Parametric_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Parametric_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007840A0) --------------------------------------------------------  // acclient.c:923140
void __cdecl _E1190_5()
{
  char *v0; // esi@1

  v0 = &PCType_AttractRepulse_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_AttractRepulse_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007840D0) --------------------------------------------------------  // acclient.c:923153
void __cdecl _E1193_5()
{
  char *v0; // esi@1

  v0 = &PCType_PointFile_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFile_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784100) --------------------------------------------------------  // acclient.c:923166
void __cdecl _E1196_5()
{
  char *v0; // esi@1

  v0 = &PCType_PointFileLerp_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFileLerp_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784130) --------------------------------------------------------  // acclient.c:923179
void __cdecl _E1199_5()
{
  char *v0; // esi@1

  v0 = &PhysFlags_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784160) --------------------------------------------------------  // acclient.c:923192
void __cdecl _E1202_5()
{
  char *v0; // esi@1

  v0 = &PhysFlags_None_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_None_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784190) --------------------------------------------------------  // acclient.c:923205
void __cdecl _E1205_5()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Gravity_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Gravity_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007841C0) --------------------------------------------------------  // acclient.c:923218
void __cdecl _E1208_5()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Wind_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Wind_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007841F0) --------------------------------------------------------  // acclient.c:923231
void __cdecl _E1211_5()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Momentum_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Momentum_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784220) --------------------------------------------------------  // acclient.c:923244
void __cdecl _E1214_5()
{
  char *v0; // esi@1

  v0 = &PointfileFlags_RandomPoint_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointfileFlags_RandomPoint_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784250) --------------------------------------------------------  // acclient.c:923257
void __cdecl _E1217_5()
{
  char *v0; // esi@1

  v0 = &Position_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Position_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784280) --------------------------------------------------------  // acclient.c:923270
void __cdecl _E1220_5()
{
  char *v0; // esi@1

  v0 = &PointList_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointList_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007842B0) --------------------------------------------------------  // acclient.c:923283
void __cdecl _E1223_5()
{
  char *v0; // esi@1

  v0 = &Point_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007842E0) --------------------------------------------------------  // acclient.c:923296
void __cdecl _E1226_5()
{
  char *v0; // esi@1

  v0 = &DetailLevels_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevels_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784310) --------------------------------------------------------  // acclient.c:923309
void __cdecl _E1229_5()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Low_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Low_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784340) --------------------------------------------------------  // acclient.c:923322
void __cdecl _E1232_5()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Medium_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Medium_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784370) --------------------------------------------------------  // acclient.c:923335
void __cdecl _E1235_5()
{
  char *v0; // esi@1

  v0 = &DetailLevel_High_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_High_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007843A0) --------------------------------------------------------  // acclient.c:923348
void __cdecl _E1238_5()
{
  char *v0; // esi@1

  v0 = &FadeSpeed_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeSpeed_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007843D0) --------------------------------------------------------  // acclient.c:923361
void __cdecl _E1241_5()
{
  char *v0; // esi@1

  v0 = &MaxOpacity_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxOpacity_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784400) --------------------------------------------------------  // acclient.c:923374
void __cdecl _E1244_5()
{
  char *v0; // esi@1

  v0 = &Point_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784430) --------------------------------------------------------  // acclient.c:923387
void __cdecl _E1247_5()
{
  char *v0; // esi@1

  v0 = &PointAxisPos_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointAxisPos_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784460) --------------------------------------------------------  // acclient.c:923400
void __cdecl _E1250_5()
{
  char *v0; // esi@1

  v0 = &PointTexture_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointTexture_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784490) --------------------------------------------------------  // acclient.c:923413
void __cdecl _E1253_5()
{
  char *v0; // esi@1

  v0 = &PointSize_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointSize_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007844C0) --------------------------------------------------------  // acclient.c:923426
void __cdecl _E1256_5()
{
  char *v0; // esi@1

  v0 = &UseOcclusion_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseOcclusion_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

