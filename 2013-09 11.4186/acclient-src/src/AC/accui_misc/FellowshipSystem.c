/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : FellowshipSystem
   Object     : AC\accui_misc\FellowshipSystem.obj
   Functions  : 44
   Addresses  : 00569060 - 00708C60 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00569060) --------------------------------------------------------  // acclient.c:405791
void __thiscall ClientFellowshipSystem::~ClientFellowshipSystem(ClientFellowshipSystem *this)
{
  ClientFellowshipSystem *v1; // eax@1
  NoticeHandler *v2; // ecx@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  v1->vfptr = (InterfaceVtbl *)&ClientFellowshipSystem::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CEC14: using guessed type __int32 (__stdcall *ClientFellowshipSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00569090) --------------------------------------------------------  // acclient.c:405809
ClientFellowshipSystem *__cdecl ClientFellowshipSystem::GetFellowshipSystem()
{
  return ClientFellowshipSystem::s_pFellowshipSystem;
}
// 8704FC: using guessed type struct ClientFellowshipSystem *ClientFellowshipSystem::s_pFellowshipSystem;

//----- (005690A0) --------------------------------------------------------  // acclient.c:405816
void __thiscall ClientFellowshipSystem::OnEndCharacterSession(ClientFellowshipSystem *this)
{
  ClientFellowshipSystem *v1; // esi@1
  CFellowship *v2; // ecx@1

  v1 = this;
  v2 = this->m_pFellowship;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v1->m_pFellowship = 0;
}

//----- (005690C0) --------------------------------------------------------  // acclient.c:405829
unsigned int __thiscall ClientFellowshipSystem::Handle_Fellowship__UpdateFellow(ClientFellowshipSystem *this, unsigned int id, Fellow *fellow, unsigned int updateType)
{
  ClientFellowshipSystem *v4; // edi@1
  bool v5; // bl@1
  HashBaseData<unsigned long> *v6; // eax@2

  v4 = this;
  v5 = Fellowship::IsFellow((Fellowship *)&this->m_pFellowship->vfptr, id) == 0;
  Fellowship::UpdateFellow((Fellowship *)&v4->m_pFellowship->vfptr, id, fellow);
  if ( v5 )
  {
    v6 = ClientObjMaintSystem::GetWeenieObject(id);
    if ( v6 )
      CM_Character::SendNotice_ChangeRadarLook((CWeenieObject *)v6);
    CM_Fellowship::SendNotice_FellowAdded(id);
  }
  CM_Fellowship::SendNotice_FellowUpdated(id, fellow, updateType);
  gmCCommunicationSystem::SetTalkFocusEnabled(3u, 1);
  return 0;
}

//----- (00569130) --------------------------------------------------------  // acclient.c:405851
bool __thiscall ClientFellowshipSystem::IsFellow(ClientFellowshipSystem *this, unsigned int i_iid)
{
  Fellowship *v2; // ecx@1
  bool result; // al@2

  v2 = (Fellowship *)&this->m_pFellowship->vfptr;
  if ( v2 )
    result = Fellowship::IsFellow(v2, i_iid) != 0;
  else
    result = 0;
  return result;
}

//----- (00569150) --------------------------------------------------------  // acclient.c:405865
bool __thiscall ClientFellowshipSystem::IsFellowshipLeader(ClientFellowshipSystem *this, unsigned int i_iid)
{
  CFellowship *v2; // eax@1
  bool result; // al@2

  v2 = this->m_pFellowship;
  if ( v2 )
    result = v2->_leader == i_iid;
  else
    result = 0;
  return result;
}

//----- (00569170) --------------------------------------------------------  // acclient.c:405879
TResult *__thiscall ClientFellowshipSystem::QueryInterface(ClientFellowshipSystem *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( _S127_17 & 1 )
  {
    v4 = Offsets_6[0].key;
  }
  else
  {
    v4 = (_GUID *)&ClientFellowshipSystem_InterfaceType_57;
    _S127_17 |= 1u;
    Offsets_6[0].key = (_GUID *)&ClientFellowshipSystem_InterfaceType_57;
    dword_870588 = 0;
    dword_87058C = (int)&ClientSystem_InterfaceType_85;
    dword_870590 = 0;
    dword_870594 = (int)&stru_7CEC00;
    dword_870598 = 0;
    dword_87059C = 0;
    dword_8705A0 = 0;
  }
  v5 = (int)Offsets_6;
  if ( v4 )
  {
    while ( v4->Data1 != i_rcInterface->m_data1
         || *(_DWORD *)&v4->Data2 != *(_DWORD *)&i_rcInterface->m_data2
         || *(_DWORD *)&v4->Data4[0] != *(_DWORD *)&i_rcInterface->m_data4[0]
         || *(_DWORD *)&v4->Data4[4] != *(_DWORD *)&i_rcInterface->m_data4[4] )
    {
      v4 = *(_GUID **)(v5 + 8);
      v5 += 8;
      if ( !v4 )
        goto LABEL_10;
    }
    if ( o_ppvInterface )
    {
      v7 = *(_DWORD *)(v5 + 4);
      v8 = *(int *)((char *)&this->vfptr + v7);
      v9 = (char *)this + v7;
      (*(void (__thiscall **)(char *))(v8 + 16))(v9);
      *o_ppvInterface = v9;
    }
    v6 = result;
    result->m_val = 0;
  }
  else
  {
LABEL_10:
    v6 = result;
    result->m_val = -2147467262;
  }
  return v6;
}
// 870588: using guessed type int dword_870588;
// 87058C: using guessed type int dword_87058C;
// 870590: using guessed type int dword_870590;
// 870594: using guessed type int dword_870594;
// 870598: using guessed type int dword_870598;
// 87059C: using guessed type int dword_87059C;
// 8705A0: using guessed type int dword_8705A0;

//----- (00569240) --------------------------------------------------------  // acclient.c:405946
unsigned int __thiscall ClientFellowshipSystem::Release(ClientFellowshipSystem *this)
{
  ClientFellowshipSystem *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
  {
    ClientFellowshipSystem::~ClientFellowshipSystem(v1);
    operator delete(v1);
  }
  return v2;
}

//----- (00569270) --------------------------------------------------------  // acclient.c:405962
void __thiscall ClientFellowshipSystem::ClientFellowshipSystem(ClientFellowshipSystem *this)
{
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->vfptr = (InterfaceVtbl *)&ClientFellowshipSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->m_cTurbineRefCount.m_cRef = 1;
  this->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  this->m_pFellowship = 0;
  ClientFellowshipSystem::s_pFellowshipSystem = this;
  InterlockedIncrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CEC14: using guessed type __int32 (__stdcall *ClientFellowshipSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 8704FC: using guessed type struct ClientFellowshipSystem *ClientFellowshipSystem::s_pFellowshipSystem;

//----- (00569370) --------------------------------------------------------  // acclient.c:406057
PackableHashTable<unsigned long,long> *__thiscall PackableHashTable<unsigned long,long>::vector_deleting_destructor(PackableHashTable<unsigned long,long> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,long> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,long>::vftable;
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
// 7CEC44: using guessed type int (__thiscall *PackableHashTable<unsigned long,long>::vftable)(void *, char);

//----- (005693C0) --------------------------------------------------------  // acclient.c:406079
unsigned int __thiscall ClientFellowshipSystem::Handle_Fellowship__FullUpdate(ClientFellowshipSystem *this, CFellowship *fellowship)
{
  ClientFellowshipSystem *v2; // esi@1
  CFellowship *v3; // eax@2
  CFellowship *v4; // eax@3
  int v5; // ecx@6
  unsigned int v6; // edi@6
  unsigned int v7; // ebp@6
  PackableHashData<unsigned long,Fellow> *v8; // esi@9
  PackableHashData<unsigned long,Fellow> **v9; // edi@10
  unsigned int v10; // ebx@10
  HashBaseData<unsigned long> *v11; // eax@11
  PackableHashData<unsigned long,Fellow> *v12; // eax@13
  int v13; // eax@14
  HashBaseData<unsigned long> *v14; // eax@22
  HashBaseData<unsigned long> *v15; // eax@24
  bool bNewFellowship; // [sp+13h] [bp-11h]@1
  PackableHashIterator<unsigned long,Fellow> iter; // [sp+14h] [bp-10h]@9

  v2 = this;
  bNewFellowship = 0;
  if ( !this->m_pFellowship )
  {
    bNewFellowship = 1;
    v3 = (CFellowship *)operator new(0x44u);
    if ( v3 )
      CFellowship::CFellowship(v3);
    else
      v4 = 0;
    v2->m_pFellowship = v4;
  }
  v5 = (int)v2->m_pFellowship;
  v6 = 0;
  v7 = 0;
  if ( *(_DWORD *)(v5 + 28) != fellowship->_leader )
  {
    v6 = *(_DWORD *)(v5 + 28);
    v7 = fellowship->_leader;
  }
  Fellowship::operator=(v5, (int)fellowship);
  CM_Fellowship::SendNotice_FellowshipUpdate(v2->m_pFellowship);
  if ( bNewFellowship )
  {
    PackableHashTable<unsigned long,Fellow>::begin(&v2->m_pFellowship->_fellowship_table, &iter);
    v8 = iter._current;
    if ( iter._current )
    {
      v9 = iter._buckets;
      v10 = iter._table_size;
      do
      {
        v11 = ClientObjMaintSystem::GetWeenieObject(v8->_key);
        if ( v11 )
          CM_Character::SendNotice_ChangeRadarLook((CWeenieObject *)v11);
        v12 = v8->_next;
        if ( !v12 )
        {
          v13 = v8->_hashVal + 1;
          if ( v13 >= v10 )
          {
LABEL_17:
            v12 = 0;
          }
          else
          {
            while ( !v9[v13] )
            {
              ++v13;
              if ( v13 >= v10 )
                goto LABEL_17;
            }
            v12 = v9[v13];
          }
        }
        v8 = v12;
      }
      while ( v12 );
    }
  }
  else if ( v6 != v7 )
  {
    v14 = ClientObjMaintSystem::GetWeenieObject(v6);
    if ( v14 )
      CM_Character::SendNotice_ChangeRadarLook((CWeenieObject *)v14);
    v15 = ClientObjMaintSystem::GetWeenieObject(v7);
    if ( v15 )
      CM_Character::SendNotice_ChangeRadarLook((CWeenieObject *)v15);
    CM_Fellowship::SendNotice_FellowshipLeaderChanged(v7, v6);
  }
  gmCCommunicationSystem::SetTalkFocusEnabled(3u, 1);
  return 0;
}

//----- (005694F0) --------------------------------------------------------  // acclient.c:406173
void __thiscall ClientFellowshipSystem::SelectNextFellow(ClientFellowshipSystem *this)
{
  ClientFellowshipSystem *v1; // ebx@1
  Fellowship *v2; // ecx@1
  unsigned int v3; // edi@3
  PackableHashData<unsigned long,Fellow> *v4; // eax@3
  unsigned int v5; // eax@7
  CFellowship *v6; // eax@12
  PackableHashIterator<unsigned long,Fellow> *v7; // eax@13
  PackableHashIterator<unsigned long,Fellow> iter; // [sp+4h] [bp-10h]@3

  v1 = this;
  v2 = (Fellowship *)&this->m_pFellowship->vfptr;
  if ( v2 )
  {
    if ( Fellowship::IsFellow(v2, ACCWeenieObject::selectedID) != 0
      && (v3 = 0,
          PackableHashTable<unsigned long,Fellow>::begin(&v1->m_pFellowship->_fellowship_table, &iter),
          (v4 = iter._current) != 0) )
    {
      while ( v3 != ACCWeenieObject::selectedID )
      {
        v3 = v4->_key;
        if ( v4->_next )
        {
          v4 = v4->_next;
        }
        else
        {
          v5 = v4->_hashVal + 1;
          if ( v5 >= iter._table_size )
          {
LABEL_10:
            v4 = 0;
          }
          else
          {
            while ( !iter._buckets[v5] )
            {
              ++v5;
              if ( v5 >= iter._table_size )
                goto LABEL_10;
            }
            v4 = iter._buckets[v5];
          }
        }
        if ( !v4 )
          goto LABEL_12;
      }
      ACCWeenieObject::SetSelectedObject(v4->_key, 0);
    }
    else
    {
LABEL_12:
      v6 = v1->m_pFellowship;
      if ( v6->_fellowship_table._currNum )
      {
        v7 = PackableHashTable<unsigned long,Fellow>::begin(&v6->_fellowship_table, &iter);
        ACCWeenieObject::SetSelectedObject(v7->_current->_key, 0);
      }
    }
  }
}

//----- (005695C0) --------------------------------------------------------  // acclient.c:406238
void __thiscall ClientFellowshipSystem::SelectPreviousFellow(ClientFellowshipSystem *this)
{
  CFellowship *v1; // eax@1
  PackableHashData<unsigned long,Fellow> *v2; // esi@2
  unsigned int v3; // ebx@2
  unsigned int v4; // ebp@3
  PackableHashData<unsigned long,Fellow> **v5; // edi@3
  Fellowship *v6; // ecx@5
  PackableHashData<unsigned long,Fellow> *v7; // eax@8
  int v8; // eax@9
  _Formatted iidSelected; // [sp+0h] [bp-18h]@1
  ClientFellowshipSystem *v10; // [sp+4h] [bp-14h]@1
  PackableHashIterator<unsigned long,Fellow> iter; // [sp+8h] [bp-10h]@2

  iidSelected = ACCWeenieObject::selectedID;
  v1 = this->m_pFellowship;
  v10 = this;
  if ( v1 )
  {
    PackableHashTable<unsigned long,Fellow>::begin(&v1->_fellowship_table, &iter);
    v2 = iter._current;
    v3 = 0;
    if ( iter._current )
    {
      v4 = iter._table_size;
      v5 = iter._buckets;
      do
      {
        if ( v3 )
        {
          v6 = (Fellowship *)&v10->m_pFellowship->vfptr;
          if ( v6 )
          {
            if ( Fellowship::IsFellow(v6, iidSelected) != 0 && v2->_key == iidSelected )
              break;
          }
        }
        v7 = v2->_next;
        v3 = v2->_key;
        if ( !v7 )
        {
          v8 = v2->_hashVal + 1;
          if ( v8 >= v4 )
          {
LABEL_12:
            v7 = 0;
          }
          else
          {
            while ( !v5[v8] )
            {
              ++v8;
              if ( v8 >= v4 )
                goto LABEL_12;
            }
            v7 = v5[v8];
          }
        }
        v2 = v7;
      }
      while ( v7 );
    }
    ACCWeenieObject::SetSelectedObject(v3, 0);
  }
}

//----- (00569670) --------------------------------------------------------  // acclient.c:406305
int __thiscall PackableHashTable<unsigned long,long>::UnPack(PackableHashTable<unsigned long,long> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebp@1
  PackableHashTable<unsigned long,long> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  int v10; // ebp@5
  unsigned int v11; // ebx@5
  unsigned int v12; // ecx@13
  int v13; // eax@13
  void **v14; // edx@13
  unsigned int tempKey; // [sp+8h] [bp-Ch]@13
  void *start_addr; // [sp+Ch] [bp-8h]@3
  unsigned int blob_size; // [sp+10h] [bp-4h]@3

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
    while ( (unsigned int)v10 >= 4 )
    {
      v12 = *(_DWORD *)*v6;
      v13 = (int)((char *)*v6 + 4);
      *v6 = (void *)v13;
      v14 = *(void ***)v13;
      *v6 = (void *)(v13 + 4);
      tempKey = v12;
      addr = v14;
      if ( !PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
              (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4,
              (IDClass<_tagDataID,32,0> *)&tempKey,
              (const int *)&addr)
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

//----- (00569790) --------------------------------------------------------  // acclient.c:406377
int __thiscall PackableHashTable<unsigned long,Fellow>::add(PackableHashTable<unsigned long,Fellow> *this, const unsigned int *key, Fellow *data)
{
  PackableHashTable<unsigned long,Fellow> *v3; // edi@1
  unsigned int v4; // esi@1
  PackableHashData<unsigned long,Fellow> **v5; // ebx@2
  PackableHashData<unsigned long,Fellow> *v6; // edx@3
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
  if ( v6 == (PackableHashData<unsigned long,Fellow> *)-4 )
  {
LABEL_8:
    v7 = operator new(0x3Cu);
    if ( v7 )
    {
      v8 = v3->_table_size;
      *(_DWORD *)v7 = *key;
      Fellow::Fellow((Fellow *)((char *)v7 + 4), data);
      *((_DWORD *)v7 + 13) = 0;
      v9 = *key % v8;
      *((_DWORD *)v7 + 14) = v9;
      *((_DWORD *)v7 + 13) = v3->_buckets[v9];
      v3->_buckets[v9] = (PackableHashData<unsigned long,Fellow> *)v7;
      ++v3->_currNum;
      return 1;
    }
  }
  return 0;
}

//----- (005698B0) --------------------------------------------------------  // acclient.c:406472
PackableHashData<unsigned long,Fellow> *__thiscall PackableHashData<unsigned long,Fellow>::scalar_deleting_destructor(PackableHashData<unsigned long,Fellow> *this, unsigned int a2)
{
  PackableHashData<unsigned long,Fellow> *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1

  v2 = this;
  v3 = this->_data._name.m_buffer;
  this->_data.vfptr = (PackObjVtbl *)&Fellow::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v2->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A515C: using guessed type int (__thiscall *Fellow::vftable)(void *, char);

//----- (00569900) --------------------------------------------------------  // acclient.c:406491
void __thiscall PackableHashTable<unsigned long,Fellow>::EmptyContents(PackableHashTable<unsigned long,Fellow> *this)
{
  PackableHashTable<unsigned long,Fellow> *v1; // ebp@1
  unsigned int v2; // eax@2
  PackableHashData<unsigned long,Fellow> *v3; // esi@3
  AC1Legacy::PSRefBuffer<char> *v4; // edi@4
  PackableHashData<unsigned long,Fellow> *v5; // ebx@4
  unsigned int i; // [sp+4h] [bp-4h]@2

  v1 = this;
  if ( this->_buckets )
  {
    v2 = 0;
    i = 0;
    if ( this->_table_size )
    {
      do
      {
        v3 = v1->_buckets[v2];
        if ( v3 )
        {
          do
          {
            v4 = v3->_data._name.m_buffer;
            v5 = v3->_next;
            v3->_data.vfptr = (PackObjVtbl *)&Fellow::vftable;
            if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
              v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
            v3->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
            operator delete(v3);
            v3 = v5;
          }
          while ( v5 );
          v2 = i;
        }
        v1->_buckets[v2++] = 0;
        i = v2;
      }
      while ( v2 < v1->_table_size );
    }
  }
  v1->_currNum = 0;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A515C: using guessed type int (__thiscall *Fellow::vftable)(void *, char);

//----- (005699A0) --------------------------------------------------------  // acclient.c:406538
signed int __thiscall PackableHashTable<unsigned long,Fellow>::Pack(PackableHashTable<unsigned long,Fellow> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,Fellow> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<unsigned long,Fellow> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<unsigned long,Fellow>::pack_size(this);
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

//----- (00569A30) --------------------------------------------------------  // acclient.c:406589
signed int __thiscall PackableHashTable<unsigned long,Fellow>::pack_size(PackableHashTable<unsigned long,Fellow> *this)
{
  PackableHashTable<unsigned long,Fellow> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<unsigned long,Fellow> *i; // esi@2
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

//----- (00569A90) --------------------------------------------------------  // acclient.c:406621
int __thiscall PackableHashTable<unsigned long,Fellow>::UnPack(PackableHashTable<unsigned long,Fellow> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<unsigned long,Fellow> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  int v10; // ebx@5
  unsigned int v11; // ebp@5
  void *v12; // eax@12
  PackObjVtbl *v13; // edx@12
  Fellow *v14; // ecx@16
  void *start_addr; // [sp+8h] [bp-38h]@3
  unsigned int blob_size; // [sp+Ch] [bp-34h]@3
  Fellow tempData; // [sp+10h] [bp-30h]@10

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,Fellow>::EmptyContents(this);
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
    Fellow::Fellow(&tempData);
    size = 0;
    if ( v11 )
    {
      while ( (unsigned int)v10 >= 4 )
      {
        v12 = *v6;
        v13 = tempData.vfptr;
        addr = *(void ***)*v6;
        *v6 = (char *)v12 + 4;
        if ( !((int (__thiscall *)(Fellow *, void **, int))v13->UnPack)(&tempData, v6, v10)
          || !PackableHashTable<unsigned long,Fellow>::add(v4, (const unsigned int *)&addr, &tempData)
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
        Fellow::~Fellow(&tempData);
        return 1;
      }
    }
    Fellow::~Fellow(v14);
  }
  return 0;
}

//----- (00569BD0) --------------------------------------------------------  // acclient.c:406701
PackableHashTable<unsigned long,Fellow> *__thiscall PackableHashTable<unsigned long,Fellow>::scalar_deleting_destructor(PackableHashTable<unsigned long,Fellow> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,Fellow> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,Fellow>::vftable;
  PackableHashTable<unsigned long,Fellow>::EmptyContents(this);
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
// 7CEC58: using guessed type int (__thiscall *PackableHashTable<unsigned long,Fellow>::vftable)(void *, char);

//----- (00569C20) --------------------------------------------------------  // acclient.c:406723
PackableHashTable<unsigned long,Fellow> *__thiscall PackableHashTable<unsigned long,Fellow>::operator=(PackableHashTable<unsigned long,Fellow> *this, int a2)
{
  PackableHashTable<unsigned long,Fellow> *v2; // edi@1
  unsigned int v3; // ebx@2
  int v4; // eax@5
  int v5; // esi@6

  v2 = this;
  if ( this != (PackableHashTable<unsigned long,Fellow> *)a2 )
  {
    PackableHashTable<unsigned long,Fellow>::EmptyContents(this);
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
            v5 = *(_DWORD *)(v4 + 52);
            PackableHashTable<unsigned long,Fellow>::add(v2, (const unsigned int *)v4, (Fellow *)(v4 + 4));
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

//----- (00569CA0) --------------------------------------------------------  // acclient.c:406767
void __thiscall Fellowship::~Fellowship(Fellowship *this)
{
  Fellowship *v1; // edi@1
  char *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@3

  v1 = this;
  v2 = (char *)&this->_fellows_departed;
  this->_fellows_departed.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,long>::vftable;
  PackableHashTable<unsigned long,unsigned long>::EmptyContents((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&this->_fellows_departed);
  if ( *((_DWORD *)v2 + 2) )
  {
    operator delete[](*((void **)v2 + 2));
    *((_DWORD *)v2 + 2) = 0;
  }
  *((_DWORD *)v2 + 3) = 0;
  *(_DWORD *)v2 = &PackObj::vftable;
  v3 = v1->_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v1->_fellowship_table.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,Fellow>::vftable;
  PackableHashTable<unsigned long,Fellow>::EmptyContents(&v1->_fellowship_table);
  if ( v1->_fellowship_table._buckets )
  {
    operator delete[](v1->_fellowship_table._buckets);
    v1->_fellowship_table._buckets = 0;
  }
  v1->_fellowship_table._table_size = 0;
  v1->_fellowship_table.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CEC44: using guessed type int (__thiscall *PackableHashTable<unsigned long,long>::vftable)(void *, char);
// 7CEC58: using guessed type int (__thiscall *PackableHashTable<unsigned long,Fellow>::vftable)(void *, char);

//----- (00569D30) --------------------------------------------------------  // acclient.c:406803
void __thiscall Fellowship::Fellowship(Fellowship *this, Fellowship *__that)
{
  Fellowship *v2; // esi@1
  char *v3; // ecx@1
  AC1Legacy::PSRefBuffer<char> *v4; // eax@1
  int v5; // ecx@1

  v2 = this;
  v3 = (char *)&this->_fellowship_table;
  v2->vfptr = (PackObjVtbl *)&CFellowship::vftable;
  *(_DWORD *)v3 = &PackableHashTable<unsigned long,Fellow>::vftable;
  *((_DWORD *)v3 + 2) = 0;
  *((_DWORD *)v3 + 3) = 0;
  *((_DWORD *)v3 + 4) = 0;
  PackableHashTable<unsigned long,Fellow>::operator=(
    (PackableHashTable<unsigned long,Fellow> *)v3,
    (int)&__that->_fellowship_table);
  v4 = __that->_name.m_buffer;
  v2->_name.m_buffer = v4;
  InterlockedIncrement((volatile LONG *)&v4->m_cRef);
  v2->_leader = __that->_leader;
  v2->_share_xp = __that->_share_xp;
  v2->_even_xp_split = __that->_even_xp_split;
  v2->_open_fellow = __that->_open_fellow;
  v5 = (int)&v2->_fellows_departed;
  v2->_locked = __that->_locked;
  *(_DWORD *)v5 = &PackableHashTable<unsigned long,long>::vftable;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  *(_DWORD *)(v5 + 16) = 0;
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::operator=(
    (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&v2->_fellows_departed,
    (int)&__that->_fellows_departed);
}
// 7CEC44: using guessed type int (__thiscall *PackableHashTable<unsigned long,long>::vftable)(void *, char);
// 7CEC58: using guessed type int (__thiscall *PackableHashTable<unsigned long,Fellow>::vftable)(void *, char);
// 7CEC6C: using guessed type int (__thiscall *CFellowship::vftable)(void *, char);

//----- (00569DB0) --------------------------------------------------------  // acclient.c:406842
void __thiscall ClientFellowshipSystem::DeleteFellowship(ClientFellowshipSystem *this)
{
  ClientFellowshipSystem *v1; // esi@1
  CFellowship *v2; // ecx@2
  PackableHashData<unsigned long,Fellow> *v3; // esi@4
  unsigned int v4; // ebx@5
  PackableHashData<unsigned long,Fellow> **v5; // edi@5
  HashBaseData<unsigned long> *v6; // eax@6
  PackableHashData<unsigned long,Fellow> *v7; // eax@8
  int v8; // eax@9
  PackableHashIterator<unsigned long,Fellow> iter; // [sp+4h] [bp-54h]@4
  Fellowship fellowship; // [sp+14h] [bp-44h]@2

  v1 = this;
  if ( this->m_pFellowship )
  {
    Fellowship::Fellowship(&fellowship, (Fellowship *)&this->m_pFellowship->vfptr);
    v2 = v1->m_pFellowship;
    if ( v2 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->m_pFellowship = 0;
    PackableHashTable<unsigned long,Fellow>::begin(&fellowship._fellowship_table, &iter);
    v3 = iter._current;
    if ( iter._current )
    {
      v4 = iter._table_size;
      v5 = iter._buckets;
      do
      {
        v6 = ClientObjMaintSystem::GetWeenieObject(v3->_key);
        if ( v6 )
          CM_Character::SendNotice_ChangeRadarLook((CWeenieObject *)v6);
        v7 = v3->_next;
        if ( !v7 )
        {
          v8 = v3->_hashVal + 1;
          if ( v8 >= v4 )
          {
LABEL_12:
            v7 = 0;
          }
          else
          {
            while ( !v5[v8] )
            {
              ++v8;
              if ( v8 >= v4 )
                goto LABEL_12;
            }
            v7 = v5[v8];
          }
        }
        v3 = v7;
      }
      while ( v7 );
    }
    Fellowship::~Fellowship(&fellowship);
  }
}

//----- (00569E50) --------------------------------------------------------  // acclient.c:406903
void __thiscall ClientFellowshipSystem::OnShutdown(ClientFellowshipSystem *this)
{
  ClientFellowshipSystem::DeleteFellowship(this);
  if ( ClientFellowshipSystem::s_pFellowshipSystem )
  {
    ((void (*)(void))ClientFellowshipSystem::s_pFellowshipSystem->vfptr->Release)();
    ClientFellowshipSystem::s_pFellowshipSystem = 0;
  }
}
// 8704FC: using guessed type struct ClientFellowshipSystem *ClientFellowshipSystem::s_pFellowshipSystem;

//----- (00569E70) --------------------------------------------------------  // acclient.c:406915
unsigned int __thiscall ClientFellowshipSystem::Handle_Fellowship__Disband(ClientFellowshipSystem *this)
{
  ClientFellowshipSystem::DeleteFellowship(this);
  CM_Fellowship::SendNotice_FellowshipDisbanded();
  gmCCommunicationSystem::SetTalkFocusEnabled(3u, 0);
  return 0;
}

//----- (00569E90) --------------------------------------------------------  // acclient.c:406924
unsigned int __thiscall ClientFellowshipSystem::Handle_Fellowship__Quit(ClientFellowshipSystem *this, unsigned int quitter)
{
  unsigned int v2; // eax@2
  HashBaseData<unsigned long> *v3; // eax@6
  unsigned int v4; // eax@9

  if ( SmartBox::smartbox )
    v2 = SmartBox::smartbox->player_id;
  else
    v2 = 0;
  if ( quitter == v2 )
  {
    ClientFellowshipSystem::DeleteFellowship(this);
  }
  else
  {
    Fellowship::RemoveFellow((Fellowship *)&this->m_pFellowship->vfptr, quitter);
    v3 = ClientObjMaintSystem::GetWeenieObject(quitter);
    if ( v3 )
      CM_Character::SendNotice_ChangeRadarLook((CWeenieObject *)v3);
  }
  CM_Fellowship::SendNotice_FellowQuit(quitter);
  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  if ( quitter == v4 )
    gmCCommunicationSystem::SetTalkFocusEnabled(3u, 0);
  return 0;
}

//----- (00569F10) --------------------------------------------------------  // acclient.c:406956
unsigned int __thiscall ClientFellowshipSystem::Handle_Fellowship__Dismiss(ClientFellowshipSystem *this, unsigned int dismissed)
{
  unsigned int v2; // eax@2
  HashBaseData<unsigned long> *v3; // eax@6
  unsigned int v4; // eax@9

  if ( SmartBox::smartbox )
    v2 = SmartBox::smartbox->player_id;
  else
    v2 = 0;
  if ( dismissed == v2 )
  {
    ClientFellowshipSystem::DeleteFellowship(this);
  }
  else
  {
    Fellowship::RemoveFellow((Fellowship *)&this->m_pFellowship->vfptr, dismissed);
    v3 = ClientObjMaintSystem::GetWeenieObject(dismissed);
    if ( v3 )
      CM_Character::SendNotice_ChangeRadarLook((CWeenieObject *)v3);
  }
  CM_Fellowship::SendNotice_FellowDismissed(dismissed);
  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  if ( dismissed == v4 )
    gmCCommunicationSystem::SetTalkFocusEnabled(3u, 0);
  return 0;
}

//----- (00708B20) --------------------------------------------------------  // acclient.c:795960
void sub_708B20()
{
  flt_87051C = 1000.0 + 1.0;
}

//----- (00708B40) --------------------------------------------------------  // acclient.c:795966
void sub_708B40()
{
  flt_870520 = 24.0 * 8.0;
}

//----- (00708B60) --------------------------------------------------------  // acclient.c:795972
void sub_708B60()
{
  flt_870524 = 24.0 * 0.5;
}

//----- (00708B80) --------------------------------------------------------  // acclient.c:795978
int sub_708B80()
{
  return atexit(nullsub_1350);
}

//----- (00708B90) --------------------------------------------------------  // acclient.c:795984
int sub_708B90()
{
  return atexit(nullsub_1351);
}

//----- (00708BA0) --------------------------------------------------------  // acclient.c:795990
int sub_708BA0()
{
  return atexit(nullsub_1352);
}

//----- (00708BB0) --------------------------------------------------------  // acclient.c:795996
void sub_708BB0()
{
  flt_870528 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00708BD0) --------------------------------------------------------  // acclient.c:796002
void _E108_89()
{
  dbl_870530 = 1.0 / 30.0;
}

//----- (00708BF0) --------------------------------------------------------  // acclient.c:796008
void _E110_73()
{
  dbl_870538 = 1.0 / 5.0;
}

//----- (00708C10) --------------------------------------------------------  // acclient.c:796014
void sub_708C10()
{
  PixelFormatDesc::PixelFormatDesc(&stru_870540, PFID_A8R8G8B8);
}

//----- (00708C20) --------------------------------------------------------  // acclient.c:796020
void _E115_73()
{
  dword_870578 = 1024;
}

//----- (00708C30) --------------------------------------------------------  // acclient.c:796026
void _E117_69()
{
  dword_87057C = 0x7FFF;
}

//----- (00708C40) --------------------------------------------------------  // acclient.c:796032
int _E119_23()
{
  const int result; // eax@1

  result = dword_870578;
  dword_870580 = dword_870578;
  return result;
}

//----- (00708C50) --------------------------------------------------------  // acclient.c:796042
int _E121_64()
{
  return atexit(_E122_91);
}

//----- (00708C60) --------------------------------------------------------  // acclient.c:796048
int sub_708C60()
{
  return atexit(nullsub_1349);
}

