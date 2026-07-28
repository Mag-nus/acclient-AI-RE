/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DBObj
   Object     : ENGINE\engine_database\DBObj.obj
   Functions  : 23
   Addresses  : 00415120 - 00726ED0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00415120) --------------------------------------------------------  // acclient.c:81400
void __thiscall DBObj::AddToDataGraph(DBObj *this)
{
  DBCache::AddToDataGraph(this);
}

//----- (00415130) --------------------------------------------------------  // acclient.c:81406
int __thiscall DBObj::AddRef(DBObj *this)
{
  DBObj *v1; // esi@1
  DBOCache *v2; // ecx@1
  int result; // eax@2

  v1 = this;
  v2 = this->m_pMaintainer;
  if ( v2 )
  {
    DBOCache::GetIfUsing(v2, v1->m_DID);
    result = v1->m_numLinks;
  }
  else
  {
    result = v1->m_numLinks + 1;
    v1->m_numLinks = result;
  }
  return result;
}

//----- (00415160) --------------------------------------------------------  // acclient.c:81428
int __thiscall DBObj::Release(DBObj *this)
{
  DBOCache *v1; // eax@1
  int result; // eax@2

  v1 = this->m_pMaintainer;
  if ( v1 )
  {
    result = ((int (__thiscall *)(DBOCache *, unsigned int))v1->vfptr->Release)(v1, this->m_DID.id);
  }
  else
  {
    result = this->m_numLinks - 1;
    this->m_numLinks = result;
    if ( !result )
    {
      ((void (__stdcall *)(_DWORD))this->vfptr[1].IUnknown_QueryInterface)(1);
      result = 0;
    }
  }
  return result;
}

//----- (00415190) --------------------------------------------------------  // acclient.c:81452
int __cdecl DBObj::Get(QualifiedDataID *qdid)
{
  int result; // eax@2

  if ( DBCache::s_pCache )
    result = ((int (__stdcall *)(_DWORD, _DWORD))DBCache::s_pCache->vfptr->BlockingGet)(2, qdid);
  else
    result = 0;
  return result;
}

//----- (004151C0) --------------------------------------------------------  // acclient.c:81464
void __thiscall DBObj::DBObj(DBObj *this, IDClass<_tagDataID,32,0> id)
{
  this->m_dataCategory = 0;
  this->m_bLoaded = 0;
  *(_QWORD *)&this->m_timeStamp = 0i64;
  this->m_pNext = 0;
  this->m_pLast = 0;
  this->m_pMaintainer = 0;
  this->vfptr = (InterfaceVtbl *)&DBObj::vftable;
  this->m_numLinks = 1;
  this->m_DID.id = id.id;
  this->m_AllowedInFreeList = 1;
}
// 7951E0: using guessed type __int32 (__stdcall *DBObj::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00415210) --------------------------------------------------------  // acclient.c:81486
void __thiscall DBObj::~DBObj(DBObj *this)
{
  this->vfptr = (InterfaceVtbl *)&DBObj::vftable;
}
// 7951E0: using guessed type __int32 (__stdcall *DBObj::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00415220) --------------------------------------------------------  // acclient.c:81493
TResult *__thiscall DBObj::QueryInterface(DBObj *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppObject)
{
  TResult *v4; // eax@6

  if ( i_rcInterface->m_data1 == -559038737
    && *(_DWORD *)&i_rcInterface->m_data2 == *(_DWORD *)&Interface_InterfaceType_7.m_data2
    && *(_DWORD *)&i_rcInterface->m_data4[0] == *(_DWORD *)&Interface_InterfaceType_7.m_data4[0]
    && *(_DWORD *)&i_rcInterface->m_data4[4] == *(_DWORD *)&Interface_InterfaceType_7.m_data4[4]
    && this )
  {
    *o_ppObject = this;
    ((void (*)(void))this->vfptr->AddRef)();
    v4 = result;
    result->m_val = 0;
  }
  else
  {
    v4 = result;
    result->m_val = -2147467262;
  }
  return v4;
}

//----- (00415280) --------------------------------------------------------  // acclient.c:81517
bool __thiscall DBObj::ReloadFromDisk(DBObj *this)
{
  DBObj *v1; // esi@1
  unsigned int v2; // eax@2
  HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *v3; // eax@2
  bool result; // al@3

  v1 = this;
  if ( this->m_DID.id
    && (v2 = ((int (*)(void))this->vfptr[3].IUnknown_QueryInterface)(), (v3 = DBCache::GetDBOCache(v2)) != 0) )
    result = (*((int (__thiscall **)(HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *, _DWORD))v3->__vecDelDtor + 12))(
               v3,
               v1->m_DID.id);
  else
    result = 0;
  return result;
}

//----- (004152B0) --------------------------------------------------------  // acclient.c:81536
bool __thiscall DBObj::SaveToDisk(DBObj *this, PreprocHeader *header)
{
  DBObj *v2; // esi@1
  unsigned int v3; // eax@2
  HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *v4; // eax@2
  bool result; // al@3

  v2 = this;
  if ( this->m_DID.id
    && (v3 = ((int (*)(void))this->vfptr[3].IUnknown_QueryInterface)(), (v4 = DBCache::GetDBOCache(v3)) != 0) )
    result = (*((int (__thiscall **)(HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *, PreprocHeader *, DBObj *))v4->__vecDelDtor
              + 11))(
               v4,
               header,
               v2);
  else
    result = 0;
  return result;
}

//----- (004152F0) --------------------------------------------------------  // acclient.c:81557
void __thiscall DBObj::Serialize(DBObj *this, Archive *io_archive)
{
  DBObj *v2; // edi@1
  unsigned int v3; // eax@1
  const unsigned int v4; // eax@5
  unsigned int v5; // eax@6

  v2 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v3 = Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_DID.id;
    else
      v2->m_DID.id = *(_DWORD *)v3;
  }
  v4 = ((int (__thiscall *)(DBObj *))v2->vfptr[3].IUnknown_QueryInterface)(v2);
  if ( MasterDBMap::IsCategorized(v4) )
  {
    Archive::CheckAlignment(io_archive, 4u);
    v5 = Archive::GetBytes(io_archive, 4u);
    if ( v5 )
    {
      if ( io_archive->m_flags & 1 )
        *(_DWORD *)v5 = v2->m_dataCategory;
      else
        v2->m_dataCategory = *(_DWORD *)v5;
    }
  }
}

//----- (00415370) --------------------------------------------------------  // acclient.c:81590
void __cdecl DBObj::Remove(DBObj *pObj)
{
  unsigned int v1; // eax@2
  HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *v2; // eax@2

  if ( ((int (__thiscall *)(_DWORD))pObj->vfptr[3].IUnknown_QueryInterface)(pObj) )
  {
    v1 = ((int (__thiscall *)(_DWORD))pObj->vfptr[3].IUnknown_QueryInterface)(pObj);
    v2 = DBCache::GetDBOCache(v1);
    (*((void (__thiscall **)(HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *, unsigned int))v2->__vecDelDtor + 7))(
      v2,
      pObj->m_DID.id);
  }
}

//----- (004153A0) --------------------------------------------------------  // acclient.c:81606
IDClass<_tagDataID,32,0> *__cdecl DBObj::GetDIDByEnum(IDClass<_tagDataID,32,0> *result, int enum_id, int enum_group)
{
  DBCache::GetDIDFromEnumStatic(result, enum_id, enum_group);
  return result;
}

//----- (004153C0) --------------------------------------------------------  // acclient.c:81613
IntrusiveHashIterator<QualifiedDataID,DBObjSaveInfo *,1> *__thiscall IntrusiveHashIterator<QualifiedDataID,DBObjSaveInfo *,1>::operator++(IntrusiveHashIterator<QualifiedDataID,DBObjSaveInfo *,1> *this)
{
  IntrusiveHashIterator<QualifiedDataID,DBObjSaveInfo *,1> *result; // eax@1
  DBObjSaveInfo *v2; // ecx@1
  DBObjSaveInfo **v3; // edx@2
  DBObjSaveInfo **v4; // ecx@3

  result = this;
  v2 = this->m_currElement->m_hashNext;
  result->m_currElement = v2;
  if ( !v2 )
  {
    v3 = &result->m_currHashTable->m_buckets[result->m_currHashTable->m_numBuckets];
    while ( 1 )
    {
      v4 = result->m_currBucket + 1;
      result->m_currBucket = v4;
      if ( v4 == v3 )
        break;
      if ( *v4 )
      {
        result->m_currElement = *v4;
        return result;
      }
    }
  }
  return result;
}

//----- (00415400) --------------------------------------------------------  // acclient.c:81643
QualifiedDataID *__thiscall QualifiedDataIDArray::operator[](QualifiedDataIDArray *this, unsigned int idx)
{
  QualifiedDataIDArray *v2; // esi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@2
  unsigned int v4; // eax@3
  QualifiedDataID *v5; // eax@8
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+8h] [bp-Ch]@2

  v2 = this;
  if ( idx )
  {
    v4 = this->m_LastBracketIndex;
    if ( idx != v4 )
    {
      if ( this->m_CurBracketIterator.m_currElement && idx == v4 + 1 )
        IntrusiveHashIterator<QualifiedDataID,DBObjSaveInfo *,1>::operator++(&this->m_CurBracketIterator);
      else
        QualifiedDataIDArray::ExpensiveUpdateIterator(this, idx);
    }
  }
  else
  {
    v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)this,
           &result);
    v2->m_CurBracketIterator.m_currHashTable = (IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *)v3->m_currHashTable;
    v2->m_CurBracketIterator.m_currElement = (DBObjSaveInfo *)v3->m_currElement;
    v2->m_CurBracketIterator.m_currBucket = (DBObjSaveInfo **)v3->m_currBucket;
  }
  v5 = &v2->m_CurBracketIterator.m_currElement->m_hashKey;
  if ( v5 )
    v2->m_LastBracketIndex = idx;
  else
    v5 = (QualifiedDataID *)&INVALID_QDID;
  return v5;
}

//----- (00415470) --------------------------------------------------------  // acclient.c:81681
DBObj *__thiscall DBObj::scalar_deleting_destructor(DBObj *this, unsigned int a2)
{
  DBObj *v2; // esi@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&DBObj::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7951E0: using guessed type __int32 (__stdcall *DBObj::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00415490) --------------------------------------------------------  // acclient.c:81694
int __cdecl DBObj::GetByEnum(int enum_id, int enum_group, unsigned int MyType)
{
  unsigned int v3; // ecx@0
  IDClass<_tagDataID,32,0> result; // [sp+0h] [bp-4h]@1

  result.id = v3;
  DBCache::GetDIDFromEnumStatic(&result, enum_id, enum_group);
  return DBCache::Get(result, MyType);
}

//----- (004154C0) --------------------------------------------------------  // acclient.c:81705
void __thiscall DBObj::FillDataGraph(DBObj *this, IDataGraph *graph)
{
  DBObj *v2; // edi@1
  unsigned int v3; // esi@1
  InterfaceVtbl *v4; // edx@2
  unsigned int v5; // ebp@3
  IDataGraphVtbl *v6; // ebp@4
  QualifiedDataID *v7; // eax@4
  QualifiedDataIDArray sub_dids; // [sp+10h] [bp-80h]@2

  v2 = this;
  v3 = 0;
  if ( this->m_pMaintainer )
  {
    ((void (__thiscall *)(_DWORD, _DWORD))graph->vfptr->add_did)(graph, this->m_DID.id);
    IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>(
      (IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *)&sub_dids.vfptr,
      0x20u);
    v4 = v2->vfptr;
    sub_dids.m_CurBracketIterator.m_currHashTable = (IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1> *)&sub_dids;
    sub_dids.vfptr = (IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>Vtbl *)QualifiedDataIDArray::vftable;
    sub_dids.m_LastBracketIndex = -1;
    sub_dids.m_CurBracketIterator.m_currElement = 0;
    sub_dids.m_CurBracketIterator.m_currBucket = 0;
    ((void (__thiscall *)(DBObj *, QualifiedDataIDArray *))v4[1].IUnknown_Release)(v2, &sub_dids);
    if ( sub_dids.m_numElements > 0 )
    {
      do
      {
        v5 = INVALID_DID_6.id;
        if ( QualifiedDataIDArray::operator[](&sub_dids, v3)->ID.id != v5 )
        {
          v6 = graph->vfptr;
          v7 = QualifiedDataIDArray::operator[](&sub_dids, v3);
          (*(void (__thiscall **)(IDataGraph *, unsigned int, unsigned int))&v6->gap4[0])(
            graph,
            v2->m_DID.id,
            v7->ID.id);
        }
        ++v3;
      }
      while ( v3 < sub_dids.m_numElements );
    }
    QualifiedDataIDArray::~QualifiedDataIDArray(&sub_dids);
  }
}
// 794F98: using guessed type int (__thiscall *QualifiedDataIDArray::vftable[3])(void *, char);

//----- (006C48C0) --------------------------------------------------------  // acclient.c:732869
int _E73_11()
{
  return atexit(_E74_14);
}

//----- (006C48D0) --------------------------------------------------------  // acclient.c:732875
int _E76_6()
{
  return atexit(_E77_34);
}

//----- (006C48E0) --------------------------------------------------------  // acclient.c:732881
int _E79_6()
{
  return atexit(_E80_8);
}

//----- (006C48F0) --------------------------------------------------------  // acclient.c:732887
int _E82_2()
{
  PStringBase<char>::PStringBase<char>(PHEADER_STRINGS, "COMPATABILITY_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_836C30, "TOOL_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_836C34, "SOURCE_FILE_NAME");
  PStringBase<char>::PStringBase<char>(&stru_836C38, "PREPROC_OPTIONS");
  return atexit(_E83_2);
}

//----- (006C4940) --------------------------------------------------------  // acclient.c:732897
int _E1_6()
{
  return atexit(_E2_6);
}

//----- (00726ED0) --------------------------------------------------------  // acclient.c:824801
void __cdecl _E83_2()
{
  char *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (char *)&unk_836C3C;
  v1 = 4;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

