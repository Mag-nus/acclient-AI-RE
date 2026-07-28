/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : BadData
   Object     : PORTAL\gameplay_engine\BadData.obj
   Functions  : 7
   Addresses  : 004FDBF0 - 006F9480 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004FDBF0) --------------------------------------------------------  // acclient.c:297915
void __thiscall PackableHashTable<IDClass<_tagDataID,32,0>,int>::~PackableHashTable<IDClass<_tagDataID,32,0>,int>(PackableHashTable<IDClass<_tagDataID,32,0>,int> *this)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,int> *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<IDClass<_tagDataID,32,0>,int>::vftable;
  PackableHashTable<unsigned long,unsigned long>::EmptyContents((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C5ED0: using guessed type int (__thiscall *PackableHashTable<IDClass<_tagDataID,32,0>,int>::vftable)(void *, char);

//----- (004FDC30) --------------------------------------------------------  // acclient.c:297934
int __thiscall PackableHashTable<IDClass<_tagDataID,32,0>,int>::UnPack(PackableHashTable<IDClass<_tagDataID,32,0>,int> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<IDClass<_tagDataID,32,0>,int> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  int v10; // ebx@5
  unsigned int v11; // ebp@5
  int v12; // ecx@14
  int data_r; // [sp+8h] [bp-14h]@12
  int tempData; // [sp+Ch] [bp-10h]@14
  IDClass<_tagDataID,32,0> tempKey; // [sp+10h] [bp-Ch]@13
  void *start_addr; // [sp+14h] [bp-8h]@3
  unsigned int blob_size; // [sp+18h] [bp-4h]@3

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,unsigned long>::EmptyContents((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
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
  size = 0;
  if ( v11 )
  {
    while ( 1 )
    {
      addr = (void **)v10;
      if ( !PackObj::UNPACK_TYPE(&data_r, v6, (unsigned int *)&addr) )
        break;
      tempKey.id = data_r;
      if ( (unsigned int)v10 < 4 )
        break;
      v12 = *(_DWORD *)*v6;
      *v6 = (char *)*v6 + 4;
      tempData = v12;
      if ( !PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
              (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4,
              &tempKey,
              &tempData)
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

//----- (004FDD60) --------------------------------------------------------  // acclient.c:298008
PackableHashTable<IDClass<_tagDataID,32,0>,int> *__thiscall PackableHashTable<IDClass<_tagDataID,32,0>,int>::vector_deleting_destructor(PackableHashTable<IDClass<_tagDataID,32,0>,int> *this, unsigned int a2)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,int> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<IDClass<_tagDataID,32,0>,int>::vftable;
  PackableHashTable<unsigned long,unsigned long>::EmptyContents((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
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
// 7C5ED0: using guessed type int (__thiscall *PackableHashTable<IDClass<_tagDataID,32,0>,int>::vftable)(void *, char);

//----- (004FDDB0) --------------------------------------------------------  // acclient.c:298030
void __thiscall BadData::BadData(BadData *this, IDClass<_tagDataID,32,0> did)
{
  BadData *v2; // esi@1
  int v3; // ecx@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, did);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v3 = (int)&v2->_bad;
  v2->vfptr = (InterfaceVtbl *)&BadData::vftable;
  v2->vfptr = (PackObjVtbl *)&BadData::vftable;
  *(_DWORD *)v3 = &PackableHashTable<IDClass<_tagDataID,32,0>,int>::vftable;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 32;
  *(_DWORD *)(v3 + 16) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&v2->_bad);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C5ED0: using guessed type int (__thiscall *PackableHashTable<IDClass<_tagDataID,32,0>,int>::vftable)(void *, char);
// 7C5EE4: using guessed type void *BadData::vftable;
// 7C5EF8: using guessed type __int32 (__stdcall *BadData::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (004FDE00) --------------------------------------------------------  // acclient.c:298054
SerializeUsingPackDBObj *__thiscall BadData::vector_deleting_destructor(BadData *this, unsigned int a2)
{
  return BadData::scalar_deleting_destructor((BadData *)((char *)this - 48), a2);
}

//----- (004FDE20) --------------------------------------------------------  // acclient.c:298060
SerializeUsingPackDBObj *__thiscall BadData::scalar_deleting_destructor(BadData *this, unsigned int a2)
{
  SerializeUsingPackDBObj *v2; // esi@1

  v2 = (SerializeUsingPackDBObj *)this;
  PackableHashTable<IDClass<_tagDataID,32,0>,int>::~PackableHashTable<IDClass<_tagDataID,32,0>,int>(&this->_bad);
  SerializeUsingPackDBObj::~SerializeUsingPackDBObj(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006F9480) --------------------------------------------------------  // acclient.c:782015
int sub_6F9480()
{
  return atexit(nullsub_1038);
}

