/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIQueueManager
   Object     : AC\accui_misc\UIQueueManager.obj
   Functions  : 41
   Addresses  : 00402480 - 00708160 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00402480) --------------------------------------------------------  // acclient.c:62012
LONG __thiscall RefCountInterface<GlobalRegistryCommands>::AddRef(UIQueueManager *this)
{
  return InterlockedIncrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef);
}

//----- (0055A520) --------------------------------------------------------  // acclient.c:393614
void __thiscall AllegianceProfile::~AllegianceProfile(AllegianceProfile *this)
{
  AllegianceProfile *v1; // esi@1

  v1 = this;
  AllegianceHierarchy::~AllegianceHierarchy(&this->_allegiance);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0055A540) --------------------------------------------------------  // acclient.c:393625
void __thiscall PageData::~PageData(PageData *this)
{
  PageData *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@4
  AC1Legacy::PSRefBuffer<char> *v4; // edi@7

  v1 = this;
  v2 = this->pageText.m_buffer;
  this->vfptr = (PackObjVtbl *)&PageData::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v3 = v1->authorAccount.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v4 = v1->authorName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CC420: using guessed type int (__thiscall *PageData::vftable)(void *, char);

//----- (0055A5B0) --------------------------------------------------------  // acclient.c:393649
PageData *__thiscall PageData::scalar_deleting_destructor(PageData *this, unsigned int a2)
{
  PageData *v2; // esi@1

  v2 = this;
  PageData::~PageData(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0055A5D0) --------------------------------------------------------  // acclient.c:393661
TResult *__thiscall UIQueueManager::QueryInterface(UIQueueManager *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( _S127_16 & 1 )
  {
    v4 = Offsets_2[0].key;
  }
  else
  {
    v4 = (_GUID *)&UIQueueManager_InterfaceType_52;
    _S127_16 |= 1u;
    Offsets_2[0].key = (_GUID *)&UIQueueManager_InterfaceType_52;
    dword_8700DC = 0;
    dword_8700E0 = (int)&IQueuedUIEventDeliverer_InterfaceType_61;
    dword_8700E4 = 0;
    dword_8700E8 = (int)&stru_7CC3D0;
    dword_8700EC = 0;
    dword_8700F0 = 0;
    dword_8700F4 = 0;
  }
  v5 = (int)Offsets_2;
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
// 8700DC: using guessed type int dword_8700DC;
// 8700E0: using guessed type int dword_8700E0;
// 8700E4: using guessed type int dword_8700E4;
// 8700E8: using guessed type int dword_8700E8;
// 8700EC: using guessed type int dword_8700EC;
// 8700F0: using guessed type int dword_8700F0;
// 8700F4: using guessed type int dword_8700F4;

//----- (0055A6A0) --------------------------------------------------------  // acclient.c:393728
void __thiscall UIQueueManager::OnBeginCharacterSession(UIQueueManager *this)
{
  UIQueueManager *v1; // edi@1
  unsigned int v2; // esi@1

  v1 = this;
  v2 = 0;
  if ( this->m_rgSystems.m_num )
  {
    do
      ((void (*)(void))v1->m_rgSystems.m_data[v2++]->vfptr[1].IUnknown_Release)();
    while ( v2 < v1->m_rgSystems.m_num );
  }
}

//----- (0055A6D0) --------------------------------------------------------  // acclient.c:393744
void __thiscall UIQueueManager::OnEndCharacterSession(UIQueueManager *this)
{
  UIQueueManager *v1; // edi@1
  unsigned int v2; // esi@1

  v1 = this;
  v2 = 0;
  if ( this->m_rgSystems.m_num )
  {
    do
      ((void (*)(void))v1->m_rgSystems.m_data[v2++]->vfptr[1].QueryInterface)();
    while ( v2 < v1->m_rgSystems.m_num );
  }
}

//----- (0055A700) --------------------------------------------------------  // acclient.c:393760
void __thiscall UIQueueManager::OnShutdown(UIQueueManager *this)
{
  UIQueueManager *v1; // esi@1
  unsigned int v2; // edi@1
  ClientMagicSystem *v3; // ecx@3
  ClientCommunicationSystem *v4; // ecx@5
  ClientObjMaintSystem *v5; // ecx@7
  ClientUISystem *v6; // ecx@9
  ClientAllegianceSystem *v7; // ecx@11
  ClientFellowshipSystem *v8; // ecx@13
  CPlayerSystem *v9; // ecx@15
  ClientHousingSystem *v10; // ecx@17
  ClientMiniGameSystem *v11; // ecx@19
  ClientAdminSystem *v12; // ecx@21
  ClientCombatSystem *v13; // ecx@23
  ClientTradeSystem *v14; // ecx@25

  v1 = this;
  v2 = 0;
  if ( this->m_rgSystems.m_num )
  {
    do
      ((void (*)(void))v1->m_rgSystems.m_data[v2++]->vfptr[1].AddRef)();
    while ( v2 < v1->m_rgSystems.m_num );
  }
  v3 = v1->m_pMagicSystem;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v1->m_pMagicSystem = 0;
  }
  v4 = v1->m_pCommunicationSystem;
  if ( v4 )
  {
    ((void (*)(void))v4->vfptr->Release)();
    v1->m_pCommunicationSystem = 0;
  }
  v5 = v1->m_pObjMaintSystem;
  if ( v5 )
  {
    ((void (*)(void))v5->vfptr->Release)();
    v1->m_pObjMaintSystem = 0;
  }
  v6 = v1->m_pUISystem;
  if ( v6 )
  {
    ((void (*)(void))v6->vfptr->Release)();
    v1->m_pUISystem = 0;
  }
  v7 = v1->m_pAllegianceSystem;
  if ( v7 )
  {
    ((void (*)(void))v7->vfptr->Release)();
    v1->m_pAllegianceSystem = 0;
  }
  v8 = v1->m_pFellowshipSystem;
  if ( v8 )
  {
    ((void (*)(void))v8->vfptr->Release)();
    v1->m_pFellowshipSystem = 0;
  }
  v9 = v1->m_pPlayerSystem;
  if ( v9 )
  {
    ((void (*)(void))v9->vfptr->Release)();
    v1->m_pPlayerSystem = 0;
  }
  v10 = v1->m_pHousingSystem;
  if ( v10 )
  {
    ((void (*)(void))v10->vfptr->Release)();
    v1->m_pHousingSystem = 0;
  }
  v11 = v1->m_pMiniGameSystem;
  if ( v11 )
  {
    ((void (*)(void))v11->vfptr->Release)();
    v1->m_pMiniGameSystem = 0;
  }
  v12 = v1->m_pAdminSystem;
  if ( v12 )
  {
    ((void (*)(void))v12->vfptr->Release)();
    v1->m_pAdminSystem = 0;
  }
  v13 = v1->m_pCombatSystem;
  if ( v13 )
  {
    ((void (*)(void))v13->vfptr->Release)();
    v1->m_pCombatSystem = 0;
  }
  v14 = v1->m_pTradeSystem;
  if ( v14 )
  {
    ((void (*)(void))v14->vfptr->Release)();
    v1->m_pTradeSystem = 0;
  }
  IQueuedUIEventDeliverer::OnShutdown();
}

//----- (0055A7F0) --------------------------------------------------------  // acclient.c:393861
void __thiscall UIQueueManager::CrucialOrderedEventsReceived(UIQueueManager *this)
{
  UIQueueManager *v1; // esi@1
  NIListElement<NetBlob *> *v2; // eax@1
  NIListElement<NetBlob *> *v3; // eax@2
  NetBlob *v4; // edi@3
  NIListElement<NetBlob *> *v5; // ecx@4

  v1 = this;
  v2 = this->m_rgWaitingBlobs.head_;
  this->m_fCrucialOrderedEventsReceived = 1;
  if ( v2 )
  {
    do
    {
      v3 = v1->m_rgWaitingBlobs.head_;
      if ( v3 )
      {
        v5 = v3->next_;
        v1->m_rgWaitingBlobs.head_ = v5;
        if ( !v5 )
          v1->m_rgWaitingBlobs.tail_ = 0;
        v4 = v3->data_;
        operator delete(v3);
      }
      else
      {
        v4 = 0;
      }
      ((void (__thiscall *)(UIQueueManager *, _DWORD))v1->vfptr[1].AddRef)(v1, v4);
      if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
      {
        if ( v4 )
          v4->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 1u);
      }
    }
    while ( v1->m_rgWaitingBlobs.head_ );
  }
}

//----- (0055A860) --------------------------------------------------------  // acclient.c:393902
void __thiscall UIQueueManager::UIQueueManager(UIQueueManager *this, NIList<NetBlob *> *pqueue)
{
  UIQueueManager *v2; // esi@1

  v2 = this;
  IQueuedUIEventDeliverer::IQueuedUIEventDeliverer((IQueuedUIEventDeliverer *)&this->vfptr);
  v2->vfptr = (InterfaceVtbl *)&UIQueueManager::vftable;
  v2->m_cTurbineRefCount.m_cRef = 1;
  v2->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  v2->m_rgWaitingBlobs.head_ = 0;
  v2->m_rgWaitingBlobs.tail_ = 0;
  v2->m_fCrucialOrderedEventsReceived = 0;
  v2->m_pUIQueue = pqueue;
  v2->m_rgSystems.m_data = 0;
  v2->m_rgSystems.m_sizeAndDeallocate = 0;
  v2->m_rgSystems.m_num = 0;
  v2->m_pMagicSystem = 0;
  v2->m_pCommunicationSystem = 0;
  v2->m_pObjMaintSystem = 0;
  v2->m_pUISystem = 0;
  v2->m_pAllegianceSystem = 0;
  v2->m_pFellowshipSystem = 0;
  v2->m_pPlayerSystem = 0;
  v2->m_pHousingSystem = 0;
  v2->m_pMiniGameSystem = 0;
  v2->m_pAdminSystem = 0;
  v2->m_pCombatSystem = 0;
  v2->m_pTradeSystem = 0;
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7CC434: using guessed type __int32 (__stdcall *UIQueueManager::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0055A8D0) --------------------------------------------------------  // acclient.c:393935
void __thiscall UIQueueManager::~UIQueueManager(UIQueueManager *this)
{
  UIQueueManager *v1; // esi@1

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&UIQueueManager::vftable;
  if ( (this->m_rgSystems.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](this->m_rgSystems.m_data);
  NIList<unsigned long>::DeleteContents((NIList<NetPacket *> *)&v1->m_rgWaitingBlobs);
  v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  IQueuedUIEventDeliverer::~IQueuedUIEventDeliverer((IQueuedUIEventDeliverer *)&v1->vfptr);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7CC434: using guessed type __int32 (__stdcall *UIQueueManager::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0055A910) --------------------------------------------------------  // acclient.c:393951
int __thiscall PackableList<ContentProfile>::InsertTail(PackableList<ContentProfile> *this, ContentProfile *val)
{
  PackableList<ContentProfile> *v2; // esi@1
  void *v3; // eax@1
  int result; // eax@5
  PackableLLNode<ContentProfile> *v5; // ecx@6

  v2 = this;
  v3 = operator new(0x14u);
  if ( v3 )
  {
    *(_DWORD *)v3 = &ContentProfile::vftable;
    *((_DWORD *)v3 + 1) = val->m_iid;
    *((_DWORD *)v3 + 2) = val->m_uContainerProperties;
    *((_DWORD *)v3 + 3) = 0;
    *((_DWORD *)v3 + 4) = 0;
  }
  else
  {
    v3 = 0;
  }
  if ( v2->head )
  {
    v5 = v2->tail;
    v5->next = (PackableLLNode<ContentProfile> *)v3;
    *((_DWORD *)v3 + 4) = v5;
    v2->tail = (PackableLLNode<ContentProfile> *)v3;
    result = v2->curNum + 1;
    v2->curNum = result;
  }
  else
  {
    v2->head = (PackableLLNode<ContentProfile> *)v3;
    v2->tail = (PackableLLNode<ContentProfile> *)v3;
    result = v2->curNum + 1;
    v2->curNum = result;
  }
  return result;
}
// 7CC40C: using guessed type int (__thiscall *ContentProfile::vftable)(void *, char);

//----- (0055A980) --------------------------------------------------------  // acclient.c:393993
int __thiscall UIQueueManager::HandleStringUpdateEvents(UIQueueManager *this, void *buff, unsigned int size, unsigned int etype)
{
  unsigned int v5; // ebx@3
  void *v6; // esi@3
  char *v7; // eax@5
  unsigned int v8; // ebp@5
  unsigned int v9; // edi@7
  int v10; // edi@8
  unsigned int v11; // esi@8
  unsigned int v12; // esi@11
  char wts; // [sp+0h] [bp-8h]@5
  UIQueueManager *v14; // [sp+4h] [bp-4h]@1

  v14 = this;
  if ( !this->m_pObjMaintSystem )
    return 0;
  v5 = etype;
  v6 = buff;
  if ( etype != *(_DWORD *)buff )
    return 0;
  v7 = (char *)buff + 5;
  v8 = 0;
  wts = *((_BYTE *)buff + 4);
  if ( etype == 726 )
  {
    v8 = *(_DWORD *)v7;
    v7 = (char *)buff + 9;
  }
  v9 = *(_DWORD *)v7;
  buff = v7 + 4;
  PackObj::ALIGN_PTR(&buff);
  etype = AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  AC1Legacy::PStringBase<char>::UnPack(
    (AC1Legacy::PStringBase<char> *)&etype,
    &buff,
    size + (_BYTE *)v6 - (_BYTE *)buff);
  if ( v5 == 726 )
  {
    v10 = ClientObjMaintSystem::Handle_Qualities__UpdateString(
            v14->m_pObjMaintSystem,
            wts,
            v8,
            v9,
            (AC1Legacy::PStringBase<char> *)&etype);
    v11 = etype;
    if ( !InterlockedDecrement((volatile LONG *)(etype + 4)) && v11 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      return v10;
    }
  }
  else
  {
    v10 = ClientObjMaintSystem::Handle_Qualities__PrivateUpdateString(
            v14->m_pObjMaintSystem,
            wts,
            v9,
            (AC1Legacy::PStringBase<char> *)&etype);
    v12 = etype;
    if ( !InterlockedDecrement((volatile LONG *)(etype + 4)) && v12 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  }
  return v10;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0055AAB0) --------------------------------------------------------  // acclient.c:394061
void __thiscall PackableList<ContentProfile>::Flush(PackableList<ContentProfile> *this)
{
  PackableList<ContentProfile> *v1; // esi@1
  PackableLLNode<ContentProfile> *v2; // eax@2
  PackableLLNode<ContentProfile> *v3; // ecx@3
  ContentProfile dummyData; // [sp+8h] [bp-Ch]@1

  v1 = this;
  ContentProfile::ContentProfile(&dummyData);
  while ( v1->head )
  {
    v2 = v1->head;
    if ( v2 )
    {
      v3 = v2->next;
      v1->head = v3;
      if ( v3 )
        v3->prev = 0;
      else
        v1->tail = 0;
      dummyData.m_iid = v2->data.m_iid;
      dummyData.m_uContainerProperties = v2->data.m_uContainerProperties;
      v2->data.vfptr = (PackObjVtbl *)&PackObj::vftable;
      operator delete(v2);
      --v1->curNum;
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0055AB20) --------------------------------------------------------  // acclient.c:394092
unsigned int __thiscall UIQueueManager::Release(UIQueueManager *this)
{
  UIQueueManager *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
  {
    UIQueueManager::~UIQueueManager(v1);
    operator delete(v1);
  }
  return v2;
}

//----- (0055AB50) --------------------------------------------------------  // acclient.c:394108
void __thiscall UIQueueManager::OnStartup(UIQueueManager *this)
{
  UIQueueManager *v1; // ebx@1
  ClientMagicSystem *v2; // eax@1
  unsigned int v3; // edi@1
  ClientMagicSystem *v4; // eax@2
  ClientMagicSystem *v5; // ebp@2
  int v6; // esi@4
  int v7; // eax@4
  unsigned int v8; // eax@5
  ClientCommunicationSystem *v9; // eax@7
  ClientCommunicationSystem *v10; // eax@8
  ClientCommunicationSystem *v11; // ebp@8
  int v12; // eax@10
  unsigned int v13; // eax@11
  ClientUISystem *v14; // eax@13
  ClientUISystem *v15; // eax@14
  ClientUISystem *v16; // ebp@14
  int v17; // eax@16
  unsigned int v18; // eax@17
  ClientAllegianceSystem *v19; // eax@19
  ClientAllegianceSystem *v20; // eax@20
  ClientAllegianceSystem *v21; // ebp@20
  int v22; // eax@22
  unsigned int v23; // eax@23
  ClientFellowshipSystem *v24; // eax@25
  ClientFellowshipSystem *v25; // eax@26
  ClientFellowshipSystem *v26; // ebp@26
  int v27; // eax@28
  unsigned int v28; // eax@29
  CPlayerSystem *v29; // eax@31
  CPlayerSystem *v30; // eax@32
  CPlayerSystem *v31; // ebp@32
  int v32; // eax@34
  unsigned int v33; // eax@35
  ClientHousingSystem *v34; // eax@37
  ClientHousingSystem *v35; // eax@38
  ClientHousingSystem *v36; // ebp@38
  int v37; // eax@40
  unsigned int v38; // eax@41
  ClientMiniGameSystem *v39; // eax@43
  ClientMiniGameSystem *v40; // eax@44
  ClientMiniGameSystem *v41; // ebp@44
  int v42; // eax@46
  unsigned int v43; // eax@47
  ClientCombatSystem *v44; // eax@49
  ClientCombatSystem *v45; // eax@50
  ClientCombatSystem *v46; // ebp@50
  int v47; // eax@52
  unsigned int v48; // eax@53
  ClientTradeSystem *v49; // eax@55
  ClientTradeSystem *v50; // eax@56
  ClientTradeSystem *v51; // ebp@56
  int v52; // eax@58
  unsigned int v53; // eax@59
  InterfaceSystem *v54; // eax@61
  Interface *v55; // ebp@61
  ClientObjMaintSystem *v56; // ebp@65
  bool v57; // zf@65
  int v58; // eax@66
  unsigned int v59; // eax@67
  int v60; // [sp-8h] [bp-2Ch]@61
  Interface *_rpInterface; // [sp+10h] [bp-14h]@61
  TResult result; // [sp+14h] [bp-10h]@61
  char v63; // [sp+18h] [bp-Ch]@63
  InterfacePtr<ClientObjMaintSystem> spObjMaint; // [sp+1Ch] [bp-8h]@61

  v1 = this;
  v2 = (ClientMagicSystem *)operator new(0x104u);
  v3 = 0;
  if ( v2 )
  {
    ClientMagicSystem::ClientMagicSystem(v2);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v6 = (int)&v1->m_rgSystems;
  v1->m_pMagicSystem = v5;
  v7 = v1->m_rgSystems.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_rgSystems.m_num < v7
    || (v8 = SmartArray<UIChildFramework *,1>::get_new_size(v7 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_rgSystems, v8)) )
    *(_DWORD *)(*(_DWORD *)v6 + 4 * v1->m_rgSystems.m_num++) = v5;
  v9 = (ClientCommunicationSystem *)operator new(0x9Cu);
  if ( v9 )
  {
    ClientCommunicationSystem::ClientCommunicationSystem(v9);
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  v1->m_pCommunicationSystem = v11;
  v12 = v1->m_rgSystems.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_rgSystems.m_num < v12
    || (v13 = SmartArray<UIChildFramework *,1>::get_new_size(v12 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_rgSystems, v13)) )
    *(_DWORD *)(*(_DWORD *)v6 + 4 * v1->m_rgSystems.m_num++) = v11;
  v14 = (ClientUISystem *)operator new(0x44u);
  if ( v14 )
  {
    ClientUISystem::ClientUISystem(v14);
    v16 = v15;
  }
  else
  {
    v16 = 0;
  }
  v1->m_pUISystem = v16;
  v17 = v1->m_rgSystems.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_rgSystems.m_num < v17
    || (v18 = SmartArray<UIChildFramework *,1>::get_new_size(v17 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_rgSystems, v18)) )
    *(_DWORD *)(*(_DWORD *)v6 + 4 * v1->m_rgSystems.m_num++) = v16;
  v19 = (ClientAllegianceSystem *)operator new(0x128u);
  if ( v19 )
  {
    ClientAllegianceSystem::ClientAllegianceSystem(v19);
    v21 = v20;
  }
  else
  {
    v21 = 0;
  }
  v1->m_pAllegianceSystem = v21;
  v22 = v1->m_rgSystems.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_rgSystems.m_num < v22
    || (v23 = SmartArray<UIChildFramework *,1>::get_new_size(v22 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_rgSystems, v23)) )
    *(_DWORD *)(*(_DWORD *)v6 + 4 * v1->m_rgSystems.m_num++) = v21;
  v24 = (ClientFellowshipSystem *)operator new(0x14u);
  if ( v24 )
  {
    ClientFellowshipSystem::ClientFellowshipSystem(v24);
    v26 = v25;
  }
  else
  {
    v26 = 0;
  }
  v1->m_pFellowshipSystem = v26;
  v27 = v1->m_rgSystems.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_rgSystems.m_num < v27
    || (v28 = SmartArray<UIChildFramework *,1>::get_new_size(v27 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_rgSystems, v28)) )
    *(_DWORD *)(*(_DWORD *)v6 + 4 * v1->m_rgSystems.m_num++) = v26;
  v29 = (CPlayerSystem *)operator new(0x300u);
  if ( v29 )
  {
    CPlayerSystem::CPlayerSystem(v29);
    v31 = v30;
  }
  else
  {
    v31 = 0;
  }
  v1->m_pPlayerSystem = v31;
  v32 = v1->m_rgSystems.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_rgSystems.m_num < v32
    || (v33 = SmartArray<UIChildFramework *,1>::get_new_size(v32 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_rgSystems, v33)) )
    *(_DWORD *)(*(_DWORD *)v6 + 4 * v1->m_rgSystems.m_num++) = v31;
  v34 = (ClientHousingSystem *)operator new(0x10u);
  if ( v34 )
  {
    ClientHousingSystem::ClientHousingSystem(v34);
    v36 = v35;
  }
  else
  {
    v36 = 0;
  }
  v1->m_pHousingSystem = v36;
  v37 = v1->m_rgSystems.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_rgSystems.m_num < v37
    || (v38 = SmartArray<UIChildFramework *,1>::get_new_size(v37 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_rgSystems, v38)) )
    *(_DWORD *)(*(_DWORD *)v6 + 4 * v1->m_rgSystems.m_num++) = v36;
  v39 = (ClientMiniGameSystem *)operator new(0x10u);
  if ( v39 )
  {
    ClientMiniGameSystem::ClientMiniGameSystem(v39);
    v41 = v40;
  }
  else
  {
    v41 = 0;
  }
  v1->m_pMiniGameSystem = v41;
  v42 = v1->m_rgSystems.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_rgSystems.m_num < v42
    || (v43 = SmartArray<UIChildFramework *,1>::get_new_size(v42 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_rgSystems, v43)) )
    *(_DWORD *)(*(_DWORD *)v6 + 4 * v1->m_rgSystems.m_num++) = v41;
  v44 = (ClientCombatSystem *)operator new(0x60u);
  if ( v44 )
  {
    ClientCombatSystem::ClientCombatSystem(v44);
    v46 = v45;
  }
  else
  {
    v46 = 0;
  }
  v1->m_pCombatSystem = v46;
  v47 = v1->m_rgSystems.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_rgSystems.m_num < v47
    || (v48 = SmartArray<UIChildFramework *,1>::get_new_size(v47 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_rgSystems, v48)) )
    *(_DWORD *)(*(_DWORD *)v6 + 4 * v1->m_rgSystems.m_num++) = v46;
  v49 = (ClientTradeSystem *)operator new(0x24u);
  if ( v49 )
  {
    ClientTradeSystem::ClientTradeSystem(v49);
    v51 = v50;
  }
  else
  {
    v51 = 0;
  }
  v1->m_pTradeSystem = v51;
  v52 = v1->m_rgSystems.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_rgSystems.m_num < v52
    || (v53 = SmartArray<UIChildFramework *,1>::get_new_size(v52 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_rgSystems, v53)) )
    *(_DWORD *)(*(_DWORD *)v6 + 4 * v1->m_rgSystems.m_num++) = v51;
  _rpInterface = 0;
  v54 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v54, &result, &ClientObjMaintSystem_ClassType_2, &_rpInterface);
  v60 = (int)_rpInterface;
  v55 = _rpInterface;
  spObjMaint.m_pInterface = 0;
  spObjMaint.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  InterfacePtr<ClientObjMaintSystem>::_QueryInterface(&spObjMaint, (int)&v63, v60, 0);
  if ( v55 )
    v55->vfptr->Release(v55);
  v56 = spObjMaint.m_pInterface;
  v57 = (_DWORD)spObjMaint.m_pInterface == 0;
  v1->m_pObjMaintSystem = spObjMaint.m_pInterface;
  if ( !v57 )
  {
    v58 = v1->m_rgSystems.m_sizeAndDeallocate & 0x7FFFFFFF;
    if ( v1->m_rgSystems.m_num < v58
      || (v59 = SmartArray<UIChildFramework *,1>::get_new_size(v58 + 1),
          SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_rgSystems, v59)) )
      *(_DWORD *)(*(_DWORD *)v6 + 4 * v1->m_rgSystems.m_num++) = v56;
  }
  if ( v1->m_rgSystems.m_num > 0 )
  {
    do
      (*(void (**)(void))(**(_DWORD **)(*(_DWORD *)v6 + 4 * v3++) + 24))();
    while ( v3 < v1->m_rgSystems.m_num );
  }
}

//----- (0055AF30) --------------------------------------------------------  // acclient.c:394370
void __thiscall PackableList<ContentProfile>::~PackableList<ContentProfile>(PackableList<ContentProfile> *this)
{
  PackableList<ContentProfile> *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<ContentProfile>::vftable;
  PackableList<ContentProfile>::Flush(this);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CC3F8: using guessed type int (__thiscall *PackableList<ContentProfile>::vftable)(void *, char);

//----- (0055AF50) --------------------------------------------------------  // acclient.c:394383
int __thiscall PackableList<ContentProfile>::UnPack(PackableList<ContentProfile> *this, void **addr, unsigned int size)
{
  PackableList<ContentProfile> *v3; // ebp@1
  int v4; // edi@2
  int v5; // esi@2
  int result; // eax@5
  ContentProfile temp; // [sp+8h] [bp-Ch]@2

  v3 = this;
  PackableList<ContentProfile>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    ContentProfile::ContentProfile(&temp);
    v5 = 0;
    if ( v4 <= 0 )
    {
LABEL_5:
      result = 1;
    }
    else
    {
      while ( ((int (__thiscall *)(ContentProfile *, void **, unsigned int))temp.vfptr->UnPack)(&temp, addr, size) )
      {
        PackableList<ContentProfile>::InsertTail(v3, &temp);
        ++v5;
        if ( v5 >= v4 )
          goto LABEL_5;
      }
      result = 0;
    }
  }
  return result;
}

//----- (0055AFD0) --------------------------------------------------------  // acclient.c:394424
PackableList<ContentProfile> *__thiscall PackableList<ContentProfile>::vector_deleting_destructor(PackableList<ContentProfile> *this, unsigned int a2)
{
  PackableList<ContentProfile> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<ContentProfile>::vftable;
  PackableList<ContentProfile>::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CC3F8: using guessed type int (__thiscall *PackableList<ContentProfile>::vftable)(void *, char);

//----- (0055B000) --------------------------------------------------------  // acclient.c:394440
unsigned int __thiscall UIQueueManager::ProcessNetBlobData(UIQueueManager *this, void *buff, unsigned int size)
{
  UIQueueManager *v3; // edi@1
  unsigned int v4; // edx@1
  void *v5; // eax@1
  char *v6; // esi@1
  char *v7; // ecx@1
  bool v8; // cf@1
  bool v9; // zf@1
  unsigned int result; // eax@8
  unsigned int v11; // esi@17
  ClientUISystem *v12; // ecx@17
  unsigned int v13; // esi@20
  unsigned int v14; // ebp@20
  int v15; // eax@20
  int v16; // edx@20
  CObjectMaint *v17; // ecx@20
  HashBaseData<unsigned long> *v18; // eax@20
  HashBaseData<unsigned long> *v19; // eax@22
  unsigned int v20; // esi@25
  unsigned int v21; // ebp@25
  HashBaseData<unsigned long> *v22; // edi@25
  unsigned int v23; // eax@26
  unsigned int v24; // ST1C_4@27
  unsigned int v25; // ebp@28
  HashBaseData<unsigned long> *v26; // eax@28
  ACCWeenieObject *v27; // esi@28
  unsigned int v28; // edx@31
  unsigned int v29; // esi@31
  HashBaseData<unsigned long> *v30; // eax@33
  unsigned int v31; // ebp@43
  int v32; // ecx@43
  unsigned int v33; // ST20_4@43
  unsigned int v34; // eax@44
  int v35; // edx@44
  int v36; // ST20_4@44
  unsigned int v37; // eax@45
  int v38; // edx@45
  int v39; // ST20_4@45
  unsigned int v40; // edi@46
  int v41; // ebp@46
  unsigned int v42; // ST20_4@46
  unsigned int v43; // ebp@48
  unsigned int v44; // ST20_4@48
  unsigned int v45; // ST20_4@49
  unsigned int v46; // ST20_4@49
  unsigned int v47; // esi@58
  HashBaseData<unsigned long> *v48; // eax@58
  const unsigned int v49; // eax@62
  DAMAGE_TYPE v50; // esi@64
  unsigned int v51; // edx@64
  unsigned int v52; // eax@64
  const int v53; // ebp@64
  int v54; // edx@64
  unsigned int v55; // eax@64
  DAMAGE_TYPE v56; // esi@65
  unsigned int v57; // edx@65
  unsigned int v58; // eax@65
  const int v59; // ebp@65
  const int v60; // edx@65
  int v61; // eax@65
  unsigned int v62; // eax@65
  void *v63; // ecx@68
  unsigned int v64; // ebp@68
  char v65; // al@72
  int v66; // ecx@72
  unsigned int v67; // eax@72
  unsigned int v68; // edx@72
  unsigned int v69; // ST20_4@72
  unsigned int v70; // edi@73
  unsigned int v71; // ST20_4@73
  unsigned int v72; // eax@197
  charError v73; // eax@199
  void *v74; // ST1C_4@203
  CPlayerSystem *v75; // ecx@203
  void *v76; // ST1C_4@210
  CPlayerSystem *v77; // ecx@210
  AC1Legacy::PStringBase<char> scribeAccount; // [sp+10h] [bp-1C0h]@43
  int maxNumPages; // [sp+14h] [bp-1BCh]@43
  const long double scribeName; // [sp+18h] [bp-1B8h]@20
  const long double inscription; // [sp+20h] [bp-1B0h]@20
  int v82; // [sp+28h] [bp-1A8h]@68
  int v83; // [sp+2Ch] [bp-1A4h]@68
  PageData pageData; // [sp+30h] [bp-1A0h]@43
  AppraisalProfile prof; // [sp+54h] [bp-17Ch]@73
  CAllegianceProfile v86; // [sp+B8h] [bp-118h]@48

  v3 = this;
  v4 = *(_DWORD *)buff;
  v5 = buff;
  v6 = (char *)buff + size;
  v7 = (char *)buff + 4;
  v8 = *(_DWORD *)buff < 0x276u;
  v9 = *(_DWORD *)buff == 630;
  buff = (char *)buff + 4;
  if ( v8 || v9 )
  {
    if ( v9 )
    {
      result = CM_Character::DispatchUI_ConfirmationDone(v3, v5);
    }
    else if ( v4 > 0x1C9 )
    {
      switch ( v4 )
      {
        case 0x274u:
          result = CM_Character::DispatchUI_ConfirmationRequest(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x1EAu:
          result = CM_Character::DispatchUI_ReturnPing(v3, v5);
          break;
        case 0x1E0u:
          result = CM_Communication::DispatchUI_HearEmote(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x1E2u:
          result = CM_Communication::DispatchUI_HearSoulEmote(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x1F4u:
          result = CM_Communication::DispatchUI_SetSquelchDB(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x1CAu:
          result = CM_Fellowship::DispatchUI_FellowStatsDone(v3, v5);
          break;
        case 0x271u:
          result = CM_House::DispatchUI_Recv_AvailableHouses(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x225u:
          result = CM_House::DispatchUI_Recv_HouseData(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x21Du:
          result = CM_House::DispatchUI_Recv_HouseProfile(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x226u:
          result = CM_House::DispatchUI_Recv_HouseStatus(v3, v5);
          break;
        case 0x259u:
          result = CM_House::DispatchUI_Recv_HouseTransaction(v3, v5);
          break;
        case 0x257u:
          result = CM_House::DispatchUI_Recv_UpdateHAR(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x228u:
          result = CM_House::DispatchUI_Recv_UpdateRentPayment(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x227u:
          result = CM_House::DispatchUI_Recv_UpdateRentTime(v3, v5);
          break;
        case 0x248u:
          result = CM_House::DispatchUI_Recv_UpdateRestrictions(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x1CBu:
          result = CM_Item::DispatchUI_AppraiseDone(v3, v5);
          break;
        case 0x264u:
          result = CM_Item::DispatchUI_QueryItemManaResponse(v3, v5);
          break;
        case 0x1D3u:
          result = CM_Qualities::DispatchUI_PrivateRemoveBoolEvent(v3, v5);
          break;
        case 0x1D9u:
          result = CM_Qualities::DispatchUI_PrivateRemoveDataIDEvent(v3, v5);
          break;
        case 0x1D5u:
          result = CM_Qualities::DispatchUI_PrivateRemoveFloatEvent(v3, v5);
          break;
        case 0x1DBu:
          result = CM_Qualities::DispatchUI_PrivateRemoveInstanceIDEvent(v3, v5);
          break;
        case 0x1D1u:
          result = CM_Qualities::DispatchUI_PrivateRemoveIntEvent(v3, v5);
          break;
        case 0x1DDu:
          result = CM_Qualities::DispatchUI_PrivateRemovePositionEvent(v3, v5);
          break;
        case 0x1D7u:
          result = CM_Qualities::DispatchUI_PrivateRemoveStringEvent(v3, v5);
          break;
        case 0x1D4u:
          result = CM_Qualities::DispatchUI_RemoveBoolEvent(v3, v5);
          break;
        case 0x1DAu:
          result = CM_Qualities::DispatchUI_RemoveDataIDEvent(v3, v5);
          break;
        case 0x1D6u:
          result = CM_Qualities::DispatchUI_RemoveFloatEvent(v3, v5);
          break;
        case 0x1DCu:
          result = CM_Qualities::DispatchUI_RemoveInstanceIDEvent(v3, v5);
          break;
        case 0x1D2u:
          result = CM_Qualities::DispatchUI_RemoveIntEvent(v3, v5);
          break;
        case 0x1DEu:
          result = CM_Qualities::DispatchUI_RemovePositionEvent(v3, v5);
          break;
        case 0x1D8u:
          result = CM_Qualities::DispatchUI_RemoveStringEvent(v3, v5);
          break;
        case 0x202u:
          result = CM_Trade::DispatchUI_Recv_AcceptTrade(v3, v5);
          break;
        case 0x200u:
          result = CM_Trade::DispatchUI_Recv_AddToTrade(v3, v5);
          break;
        case 0x208u:
          result = CM_Trade::DispatchUI_Recv_ClearTradeAcceptance(v3, v5);
          break;
        case 0x1FFu:
          result = CM_Trade::DispatchUI_Recv_CloseTrade(v3, v5);
          break;
        case 0x203u:
          result = CM_Trade::DispatchUI_Recv_DeclineTrade(v3, v5);
          break;
        case 0x1FEu:
          result = CM_Trade::DispatchUI_Recv_OpenTrade(v3, v5);
          break;
        case 0x1FDu:
          result = CM_Trade::DispatchUI_Recv_RegisterTrade(v3, v5);
          break;
        case 0x201u:
          result = CM_Trade::DispatchUI_Recv_RemoveFromTrade(v3, v5);
          break;
        case 0x205u:
          result = CM_Trade::DispatchUI_Recv_ResetTrade(v3, v5);
          break;
        case 0x207u:
          result = CM_Trade::DispatchUI_Recv_TradeFailure(v3, v5);
          break;
        default:
          goto $L170112;
      }
    }
    else if ( v4 == 457 )
    {
      result = CM_Fellowship::DispatchUI_FellowUpdateDone(v3, v5);
    }
    else
    {
      if ( v4 > 0xC3 )
      {
        switch ( v4 )
        {
          case 0x1C3u:
            return CM_Character::DispatchUI_QueryAgeResponse(v3, v5, v6 - (_BYTE *)v5);
          case 0x1C0u:
            return CM_Combat::DispatchUI_QueryHealthResponse(v3, v5);
          case 0x147u:
            return CM_Communication::DispatchUI_ChannelBroadcast(v3, v5, v6 - (_BYTE *)v5);
          case 0x149u:
            return CM_Communication::DispatchUI_ChannelIndex(v3, v5, v6 - (_BYTE *)v5);
          case 0x148u:
            return CM_Communication::DispatchUI_ChannelList(v3, v5, v6 - (_BYTE *)v5);
          case 0x1C7u:
            return CM_Item::DispatchUI_UseDone(v3, v5);
          case 0x1A8u:
            return CM_Magic::DispatchUI_RemoveSpell(v3, v5);
          case 0x19Au:
            v47 = *(_DWORD *)v7;
            buff = v7 + 4;
            v48 = CObjectMaint::GetWeenieObject((CObjectMaint *)&v3->m_pObjMaintSystem->vfptr, v47);
            if ( v48 )
            {
              ACCWeenieObject::ServerSaysMoveItem((ACCWeenieObject *)v48, 0, 0, 0, 0, 1);
              return 0;
            }
            GenItemHolder::ServerSaysMoveItem_s(v47, 0, 0, 0, 0, 0, 0, 0);
            break;
          case 0x1A7u:
            v49 = *(_DWORD *)v7;
            buff = v7 + 4;
            ClientCombatSystem::HandleAttackDoneEvent(v3->m_pCombatSystem, v49);
            return 0;
          case 0x1B8u:
            ClientCombatSystem::HandleCommenceAttackEvent(v3->m_pCombatSystem);
            return 0;
          case 0x1B1u:
            AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&scribeAccount);
            AC1Legacy::PStringBase<char>::UnPack(&scribeAccount, &buff, v6 - (_BYTE *)buff);
            v50 = *(_DWORD *)buff;
            buff = (char *)buff + 4;
            v51 = *(_DWORD *)buff;
            v52 = *((_DWORD *)buff + 1);
            buff = (char *)buff + 8;
            v53 = *(_DWORD *)buff;
            buff = (char *)buff + 4;
            inscription = COERCE_DOUBLE(__PAIR__(v52, v51));
            v54 = *(_DWORD *)buff;
            buff = (char *)buff + 4;
            v55 = *(_DWORD *)buff;
            maxNumPages = v54;
            buff = (char *)buff + 4;
            ClientCombatSystem::HandleAttackerNotificationEvent(
              v3->m_pCombatSystem,
              &scribeAccount,
              v50,
              inscription,
              v53,
              v54,
              (signed int)v55);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&scribeAccount);
            return 0;
          case 0x1B2u:
            AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&scribeAccount);
            AC1Legacy::PStringBase<char>::UnPack(&scribeAccount, &buff, v6 - (_BYTE *)buff);
            v56 = *(_DWORD *)buff;
            buff = (char *)buff + 4;
            v57 = *(_DWORD *)buff;
            v58 = *((_DWORD *)buff + 1);
            buff = (char *)buff + 8;
            v59 = *(_DWORD *)buff;
            buff = (char *)buff + 4;
            scribeName = COERCE_DOUBLE(__PAIR__(v58, v57));
            v60 = *(_DWORD *)buff;
            buff = (char *)buff + 4;
            v61 = *(_DWORD *)buff;
            buff = (char *)buff + 4;
            maxNumPages = v61;
            v62 = *(_DWORD *)buff;
            LODWORD(inscription) = v60;
            buff = (char *)buff + 4;
            ClientCombatSystem::HandleDefenderNotificationEvent(
              v3->m_pCombatSystem,
              &scribeAccount,
              v56,
              scribeName,
              v59,
              v60,
              maxNumPages,
              (signed int)v62);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&scribeAccount);
            return 0;
          case 0x1B4u:
            AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&scribeAccount);
            AC1Legacy::PStringBase<char>::UnPack(&scribeAccount, &buff, v6 - (_BYTE *)buff);
            ClientCombatSystem::HandleEvasionDefenderNotificationEvent(v3->m_pCombatSystem, &scribeAccount);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&scribeAccount);
            return 0;
          case 0x1B3u:
            AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&scribeAccount);
            AC1Legacy::PStringBase<char>::UnPack(&scribeAccount, &buff, v6 - (_BYTE *)buff);
            ClientCombatSystem::HandleEvasionAttackerNotificationEvent(v3->m_pCombatSystem, &scribeAccount);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&scribeAccount);
            return 0;
          case 0x196u:
            v63 = v7 + 4;
            LODWORD(inscription) = &PackableList<ContentProfile>::vftable;
            HIDWORD(inscription) = 0;
            v82 = 0;
            v83 = 0;
            v64 = *((_DWORD *)v63 - 1);
            buff = v63;
            PackableList<ContentProfile>::UnPack((PackableList<ContentProfile> *)&inscription, &buff, v6 - (_BYTE *)v63);
            ClientUISystem::OnViewContents(v3->m_pUISystem, v64, (PackableList<ContentProfile> *)&inscription);
            PackableList<ContentProfile>::~PackableList<ContentProfile>((PackableList<ContentProfile> *)&inscription);
            return 0;
          case 0x19Eu:
            ClientCombatSystem::HandlePlayerDeathEvent(v3->m_pCombatSystem, v7, size);
            return 0;
          case 0x1ACu:
            ClientCombatSystem::HandleVictimNotificationEvent(v3->m_pCombatSystem, v7, size);
            return 0;
          case 0x1ADu:
            ClientCombatSystem::HandleVictimNotificationEvent(v3->m_pCombatSystem, v7, size);
            return 0;
          case 0x197u:
            v65 = *v7;
            v66 = (int)(v7 + 1);
            buff = (void *)v66;
            v66 += 4;
            LOBYTE(maxNumPages) = v65;
            v67 = *(_DWORD *)(v66 - 4);
            buff = (void *)v66;
            v68 = *(_DWORD *)v66;
            buff = (void *)(v66 + 4);
            v69 = *(_DWORD *)(v66 + 4);
            buff = (void *)(v66 + 8);
            ClientObjMaintSystem::UpdateStackSize(v3->m_pObjMaintSystem, maxNumPages, v67, v68, v69);
            return 0;
          case 0xC9u:
            AppraisalProfile::AppraisalProfile(&prof);
            v70 = *(_DWORD *)buff;
            v71 = v6 - ((_BYTE *)buff + 4);
            buff = (char *)buff + 4;
            AppraisalProfile::UnPack(&prof, &buff, v71);
            CM_Examine::SendNotice_SetAppraiseInfo(v70, &prof);
            AppraisalProfile::~AppraisalProfile(&prof);
            return 0;
          default:
            goto $L170112;
        }
      }
      else
      {
        if ( v4 == 195 )
        {
          AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&inscription);
          AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&scribeName);
          AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&scribeAccount);
          v45 = v6 - ((_BYTE *)buff + 4);
          buff = (char *)buff + 4;
          AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&inscription, &buff, v45);
          v46 = v6 - ((_BYTE *)buff + 4);
          buff = (char *)buff + 4;
          AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&scribeName, &buff, v46);
          AC1Legacy::PStringBase<char>::UnPack(&scribeAccount, &buff, v6 - (_BYTE *)buff);
          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&scribeAccount);
          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&scribeName);
          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&inscription);
          return 0;
        }
        switch ( v4 )
        {
          case 3u:
            return CM_Allegiance::DispatchUI_AllegianceUpdateAborted(v3, v5);
          case 0x75u:
            return CM_Character::DispatchUI_StartBarber(v3, v5);
          case 4u:
            return CM_Communication::DispatchUI_PopUpString(v3, v5, v6 - (_BYTE *)v5);
          case 0xA4u:
            return CM_Fellowship::DispatchUI_Dismiss(v3, v5);
          case 0xA3u:
            return CM_Fellowship::DispatchUI_Quit(v3, v5);
          case 0x2Bu:
            return CM_Social::DispatchUI_AddOrSetCharacterTitle(v3, v5);
          case 0x29u:
            return CM_Social::DispatchUI_CharacterTitleTable(v3, v5, v6 - (_BYTE *)v5);
          case 0x21u:
            return CM_Social::DispatchUI_FriendsUpdate(v3, v5, v6 - (_BYTE *)v5);
          case 0x13u:
            CPlayerSystem::Handle_PlayerDescription(v3->m_pPlayerSystem, v7, size);
            UIQueueManager::CrucialOrderedEventsReceived(v3);
            UIQueueManager::OnBeginCharacterSession(v3);
            return 0;
          case 0x52u:
            v11 = *(_DWORD *)v7;
            buff = v7 + 4;
            v12 = v3->m_pUISystem;
            if ( v11 == v12->groundObject )
            {
              ClientUISystem::SetGroundObject(v12, 0, 0);
              ACCWeenieObject::RecordResponse(v11);
            }
            ACCObjectMaint::StopViewingObjectContents((ACCObjectMaint *)&v3->m_pObjMaintSystem->vfptr, v11);
            return 0;
          case 0x22u:
            v13 = *(_DWORD *)v7;
            buff = v7 + 4;
            v14 = *((_DWORD *)v7 + 1);
            buff = v7 + 8;
            v15 = *((_DWORD *)v7 + 2);
            buff = v7 + 12;
            v16 = *((_DWORD *)v7 + 3);
            buff = v7 + 16;
            v17 = (CObjectMaint *)&v3->m_pObjMaintSystem->vfptr;
            LODWORD(scribeName) = v15;
            LODWORD(inscription) = v16;
            v18 = CObjectMaint::GetWeenieObject(v17, v13);
            if ( v18 )
            {
              ACCWeenieObject::ServerSaysMoveItem((ACCWeenieObject *)v18, v14, SLODWORD(scribeName), 0, 0, 1);
              result = 0;
            }
            else
            {
              v19 = CObjectMaint::GetWeenieObject((CObjectMaint *)&v3->m_pObjMaintSystem->vfptr, v14);
              if ( v19 )
                ACCWeenieObject::ServerSaysContainID(
                  (ACCWeenieObject *)v19,
                  v13,
                  SLODWORD(scribeName),
                  SLODWORD(inscription));
              GenItemHolder::ServerSaysMoveItem_s(v13, 0, 0, 0, v14, SLODWORD(scribeName), 0, 0);
              result = 0;
            }
            return result;
          case 0x23u:
            v20 = *(_DWORD *)v7;
            buff = v7 + 4;
            v21 = *((_DWORD *)v7 + 1);
            buff = v7 + 8;
            v22 = CObjectMaint::GetWeenieObject((CObjectMaint *)&v3->m_pObjMaintSystem->vfptr, v20);
            if ( v22 )
            {
              v23 = GetPlayerID();
              ACCWeenieObject::ServerSaysMoveItem((ACCWeenieObject *)v22, 0, 0, v23, v21, 1);
              return 0;
            }
            v24 = GetPlayerID();
            GenItemHolder::ServerSaysMoveItem_s(v20, 0, 0, 0, 0, 0, v24, v21);
            break;
          case 0x24u:
            v25 = *(_DWORD *)v7;
            buff = v7 + 4;
            v26 = CObjectMaint::GetWeenieObject((CObjectMaint *)&v3->m_pObjMaintSystem->vfptr, v25);
            v27 = (ACCWeenieObject *)v26;
            if ( v26 )
            {
              ACCWeenieObject::ServerSaysRemove((ACCWeenieObject *)v26);
              ACCWeenieObject::AddContentsToDestructionQueue(v27);
              CObjectMaint::AddObjectToBeDestroyed((CObjectMaint *)&v3->m_pObjMaintSystem->vfptr, v25);
              result = 0;
            }
            else
            {
              GenItemHolder::ServerSaysMoveItem_s(v25, 0, 0, 0, 0, 0, 0, 0);
              result = 0;
            }
            return result;
          case 0xA0u:
            v28 = *(_DWORD *)v7;
            buff = v7 + 4;
            v29 = *((_DWORD *)v7 + 1);
            buff = v7 + 8;
            if ( ACCWeenieObject::prevRequestObjectID )
              v28 = ACCWeenieObject::prevRequestObjectID;
            v30 = CObjectMaint::GetWeenieObject((CObjectMaint *)&v3->m_pObjMaintSystem->vfptr, v28);
            if ( v30 )
              ACCWeenieObject::ServerSaysAttemptFailed((ACCWeenieObject *)v30, v29, 1);
            if ( v29 == 1086 || v29 == 1130 || v29 == 1231 || v29 == 1007 || v29 == 43 || v29 == 30 || v29 == 1230 )
              goto $L170112;
            ClientCommunicationSystem::HandleFailureEvent(
              v3->m_pCommunicationSystem,
              v29,
              &PStringBase<unsigned short>::null_string);
            return 0;
          case 0xB4u:
            PageDataList::PageDataList((PageDataList *)&pageData);
            AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&scribeAccount);
            AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&scribeName);
            v31 = *(_DWORD *)buff;
            buff = (char *)buff + 4;
            v32 = *(_DWORD *)buff;
            buff = (char *)buff + 4;
            maxNumPages = v32;
            PageDataList::UnPack((PageDataList *)&pageData, &buff, v6 - (_BYTE *)buff);
            AC1Legacy::PStringBase<char>::UnPack(&scribeAccount, &buff, v6 - (_BYTE *)buff);
            v33 = v6 - ((_BYTE *)buff + 4);
            LODWORD(inscription) = *(_DWORD *)buff;
            buff = (char *)buff + 4;
            AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&scribeName, &buff, v33);
            CObjectMaint::GetWeenieObject((CObjectMaint *)&v3->m_pObjMaintSystem->vfptr, v31);
            CM_Writing::SendNotice_OpenBook(
              v31,
              maxNumPages,
              (PageDataList *)&pageData,
              &scribeAccount,
              LODWORD(inscription),
              (AC1Legacy::PStringBase<char> *)&scribeName);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&scribeName);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&scribeAccount);
            PageDataList::~PageDataList((PageDataList *)&pageData);
            return 0;
          case 0xB6u:
            v34 = *(_DWORD *)v7;
            buff = v7 + 4;
            v35 = *((_DWORD *)v7 + 1);
            buff = v7 + 8;
            v36 = *((_DWORD *)v7 + 2);
            buff = v7 + 12;
            CM_Writing::SendNotice_BookAddPageResponse(v34, v35, v36);
            return 0;
          case 0xB7u:
            v37 = *(_DWORD *)v7;
            buff = v7 + 4;
            v38 = *((_DWORD *)v7 + 1);
            buff = v7 + 8;
            v39 = *((_DWORD *)v7 + 2);
            buff = v7 + 12;
            CM_Writing::SendNotice_BookDeletePageResponse(v37, v38, v39);
            return 0;
          case 0xB8u:
            PageData::PageData(&pageData);
            v40 = *(_DWORD *)buff;
            buff = (char *)buff + 4;
            v41 = *(_DWORD *)buff;
            v42 = v6 - ((_BYTE *)buff + 4);
            buff = (char *)buff + 4;
            PageData::UnPack(&pageData, &buff, v42);
            CM_Writing::SendNotice_BookPageDataResponse(v40, v41, &pageData);
            PageData::~PageData(&pageData);
            return 0;
          case 0x62u:
            ClientUISystem::Handle_VendorInfo(v3->m_pUISystem, v7, size);
            return 0;
          case 0x20u:
            CAllegianceProfile::CAllegianceProfile(&v86);
            v43 = *(_DWORD *)buff;
            v44 = v6 - ((_BYTE *)buff + 4);
            buff = (char *)buff + 4;
            AllegianceProfile::UnPack((AllegianceProfile *)&v86.vfptr, &buff, v44);
            ClientAllegianceSystem::Handle_Allegiance__AllegianceUpdate(v3->m_pAllegianceSystem, &v86, v43);
            AllegianceHierarchy::~AllegianceHierarchy(&v86._allegiance);
            return 0;
          default:
            goto $L170112;
        }
      }
      result = 0;
    }
  }
  else if ( v4 > 0x2D3 )
  {
    if ( v4 > 0xEA60 )
    {
      if ( v4 > 0xF7C1 )
      {
        switch ( v4 )
        {
          case 0xF7CAu:
            result = CM_Admin::DispatchUI_ReceiveAccountData(v3, v5, v6 - (_BYTE *)v5);
            break;
          case 0xF7CBu:
            result = CM_Admin::DispatchUI_ReceivePlayerData(v3, v5, v6 - (_BYTE *)v5);
            break;
          case 0xF7DFu:
            result = CM_Character::DispatchUI_EnterGame_ServerReady(v3, v5);
            break;
          case 0xF7E0u:
            result = CM_Communication::DispatchUI_TextboxString(v3, v5, v6 - (_BYTE *)v5);
            break;
          case 0xF7E1u:
            result = CM_Login::DispatchUI_WorldInfo(v3, v5, v6 - (_BYTE *)v5);
            break;
          case 0xF7DCu:
            v76 = v7;
            v77 = v3->m_pPlayerSystem;
            CPlayerSystem::Handle_AccountBooted(v76, size);
            goto $L170112;
          default:
$L170112:
            result = 0;
            break;
        }
      }
      else if ( v4 == 63425 )
      {
        v74 = v7;
        v75 = v3->m_pPlayerSystem;
        CPlayerSystem::Handle_AccountBanned(v74, size);
        result = 0;
      }
      else
      {
        switch ( v4 )
        {
          case 0xF630u:
            AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&scribeAccount);
            AC1Legacy::PStringBase<char>::UnPack(&scribeAccount, &buff, v6 - (_BYTE *)buff);
            gmNoticeHandler::RecvNotice_UpdateRentPayment(
              (PlayerModule *)v3->m_pUISystem,
              (PlayerOption)scribeAccount.m_buffer->m_data);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&scribeAccount);
            result = 0;
            break;
          case 0xF651u:
            v72 = *(_DWORD *)v7;
            buff = v7 + 4;
            CPlayerSystem::Handle_AwaitingSubscriptionExpiration(v3->m_pPlayerSystem, v72);
            result = 0;
            break;
          case 0xF643u:
            CPlayerSystem::Handle_CharGenVerificationResponse(v3->m_pPlayerSystem, v7, size);
            result = 0;
            break;
          case 0xF659u:
            v73 = *(_DWORD *)v7;
            buff = v7 + 4;
            CPlayerSystem::Handle_CharacterError(v3->m_pPlayerSystem, v73);
            result = 0;
            break;
          case 0xF655u:
            CPlayerSystem::Handle_CharacterDelete(v3->m_pPlayerSystem);
            result = 0;
            break;
          case 0xF653u:
            CPlayerSystem::ExecuteLogOff(v3->m_pPlayerSystem);
            result = 0;
            break;
          case 0xF658u:
            CPlayerSystem::Handle_Login__CharacterSet(v3->m_pPlayerSystem, v7, size);
            result = 0;
            break;
          default:
            goto $L170112;
        }
      }
    }
    else if ( v4 == 60000 )
    {
      result = CM_Admin::DispatchUI_Environs(v3, v5);
    }
    else
    {
      switch ( v4 )
      {
        case 0x2EBu:
          result = CM_Communication::DispatchUI_TransientString(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x312u:
          result = CM_Magic::DispatchUI_PurgeBadEnchantments(v3, v5);
          break;
        case 0x2E3u:
          result = CM_Qualities::DispatchUI_PrivateUpdateAttribute(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x2E7u:
          result = CM_Qualities::DispatchUI_PrivateUpdateAttribute2nd(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x2E9u:
          result = CM_Qualities::DispatchUI_PrivateUpdateAttribute2ndLevel(v3, v5);
          break;
        case 0x2E5u:
          result = CM_Qualities::DispatchUI_PrivateUpdateAttributeLevel(v3, v5);
          break;
        case 0x2D7u:
          result = CM_Qualities::DispatchUI_PrivateUpdateDataID(v3, v5);
          break;
        case 0x2D9u:
          result = CM_Qualities::DispatchUI_PrivateUpdateInstanceID(v3, v5);
          break;
        case 0x2DBu:
          result = CM_Qualities::DispatchUI_PrivateUpdatePosition(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x2DDu:
          result = CM_Qualities::DispatchUI_PrivateUpdateSkill(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x2E1u:
          result = CM_Qualities::DispatchUI_PrivateUpdateSkillAC(v3, v5);
          break;
        case 0x2DFu:
          result = CM_Qualities::DispatchUI_PrivateUpdateSkillLevel(v3, v5);
          break;
        case 0x2E4u:
          result = CM_Qualities::DispatchUI_UpdateAttribute(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x2E8u:
          result = CM_Qualities::DispatchUI_UpdateAttribute2nd(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x2EAu:
          result = CM_Qualities::DispatchUI_UpdateAttribute2ndLevel(v3, v5);
          break;
        case 0x2E6u:
          result = CM_Qualities::DispatchUI_UpdateAttributeLevel(v3, v5);
          break;
        case 0x2D8u:
          result = CM_Qualities::DispatchUI_UpdateDataID(v3, v5);
          break;
        case 0x2D4u:
          result = CM_Qualities::DispatchUI_UpdateFloat(v3, v5);
          break;
        case 0x2DAu:
          result = CM_Qualities::DispatchUI_UpdateInstanceID(v3, v5);
          break;
        case 0x2DCu:
          result = CM_Qualities::DispatchUI_UpdatePosition(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x2DEu:
          result = CM_Qualities::DispatchUI_UpdateSkill(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x2E2u:
          result = CM_Qualities::DispatchUI_UpdateSkillAC(v3, v5);
          break;
        case 0x2E0u:
          result = CM_Qualities::DispatchUI_UpdateSkillLevel(v3, v5);
          break;
        case 0x315u:
          result = CM_Social::DispatchUI_SendClientContractTracker(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x314u:
          result = CM_Social::DispatchUI_SendClientContractTrackerTable(v3, v5, v6 - (_BYTE *)v5);
          break;
        case 0x2D5u:
        case 0x2D6u:
          UIQueueManager::HandleStringUpdateEvents(v3, v5, v6 - (_BYTE *)v5, v4);
          result = 0;
          break;
        default:
          goto $L170112;
      }
    }
  }
  else if ( v4 == 723 )
  {
    result = CM_Qualities::DispatchUI_PrivateUpdateFloat(v3, v5);
  }
  else
  {
    switch ( v4 )
    {
      case 0x2B1u:
        result = CM_Admin::DispatchUI_Recv_QueryPlugin(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x2AEu:
        result = CM_Admin::DispatchUI_Recv_QueryPluginList(v3, v5);
        break;
      case 0x2B3u:
        result = CM_Admin::DispatchUI_Recv_QueryPluginResponse(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x27Cu:
        result = CM_Allegiance::DispatchUI_AllegianceInfoResponseEvent(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x27Au:
        result = CM_Allegiance::DispatchUI_AllegianceLoginNotificationEvent(v3, v5);
        break;
      case 0x2BDu:
        result = CM_Communication::DispatchUI_HearDirectSpeech(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x2BCu:
        result = CM_Communication::DispatchUI_HearRangedSpeech(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x2BBu:
        result = CM_Communication::DispatchUI_HearSpeech(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x295u:
        result = CM_Communication::DispatchUI_Recv_ChatRoomTracker(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x28Au:
        result = CM_Communication::DispatchUI_WeenieError(v3, v5);
        break;
      case 0x28Bu:
        result = CM_Communication::DispatchUI_WeenieErrorWithString(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x2BFu:
        result = CM_Fellowship::DispatchUI_Disband(v3, v5);
        break;
      case 0x2BEu:
        result = CM_Fellowship::DispatchUI_FullUpdate(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x2C0u:
        result = CM_Fellowship::DispatchUI_UpdateFellow(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x28Cu:
        result = CM_Game::DispatchUI_Recv_GameOver(v3, v5);
        break;
      case 0x281u:
        result = CM_Game::DispatchUI_Recv_JoinGameResponse(v3, v5);
        break;
      case 0x283u:
        result = CM_Game::DispatchUI_Recv_MoveResponse(v3, v5);
        break;
      case 0x285u:
        result = CM_Game::DispatchUI_Recv_OppenentStalemateState(v3, v5);
        break;
      case 0x284u:
        result = CM_Game::DispatchUI_Recv_OpponentTurn(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x282u:
        result = CM_Game::DispatchUI_Recv_StartGame(v3, v5);
        break;
      case 0x2B4u:
        result = CM_Inventory::DispatchUI_Recv_SalvageOperationsResultData(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x2C7u:
        result = CM_Magic::DispatchUI_DispelEnchantment(v3, v5);
        break;
      case 0x2C8u:
        result = CM_Magic::DispatchUI_DispelMultipleEnchantments(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x2C6u:
        result = CM_Magic::DispatchUI_PurgeEnchantments(v3, v5);
        break;
      case 0x2C3u:
        result = CM_Magic::DispatchUI_RemoveEnchantment(v3, v5);
        break;
      case 0x2C5u:
        result = CM_Magic::DispatchUI_RemoveMultipleEnchantments(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x2C2u:
        result = CM_Magic::DispatchUI_UpdateEnchantment(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x2C4u:
        result = CM_Magic::DispatchUI_UpdateMultipleEnchantments(v3, v5, v6 - (_BYTE *)v5);
        break;
      case 0x2C1u:
        result = CM_Magic::DispatchUI_UpdateSpell(v3, v5);
        break;
      case 0x2CBu:
        result = CM_Misc::DispatchUI_PortalStorm(v3, v5);
        break;
      case 0x2C9u:
        result = CM_Misc::DispatchUI_PortalStormBrewing(v3, v5);
        break;
      case 0x2CAu:
        result = CM_Misc::DispatchUI_PortalStormImminent(v3, v5);
        break;
      case 0x2CCu:
        result = CM_Misc::DispatchUI_PortalStormSubsided(v3, v5);
        break;
      case 0x2B8u:
        result = CM_Qualities::DispatchUI_PrivateRemoveInt64Event(v3, v5);
        break;
      case 0x2D1u:
        result = CM_Qualities::DispatchUI_PrivateUpdateBool(v3, v5);
        break;
      case 0x2CDu:
        result = CM_Qualities::DispatchUI_PrivateUpdateInt(v3, v5);
        break;
      case 0x2CFu:
        result = CM_Qualities::DispatchUI_PrivateUpdateInt64(v3, v5);
        break;
      case 0x2B9u:
        result = CM_Qualities::DispatchUI_RemoveInt64Event(v3, v5);
        break;
      case 0x2D2u:
        result = CM_Qualities::DispatchUI_UpdateBool(v3, v5);
        break;
      case 0x2CEu:
        result = CM_Qualities::DispatchUI_UpdateInt(v3, v5);
        break;
      case 0x2D0u:
        result = CM_Qualities::DispatchUI_UpdateInt64(v3, v5);
        break;
      default:
        goto $L170112;
    }
  }
  return result;
}
// 7CC3F8: using guessed type int (__thiscall *PackableList<ContentProfile>::vftable)(void *, char);
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;

//----- (0055D060) --------------------------------------------------------  // acclient.c:395361
void __thiscall UIQueueManager::ProcessOrderedNetBlob(UIQueueManager *this, NetBlob *blob)
{
  unsigned int v2; // esi@1
  UIQueueManager *v3; // edi@1
  unsigned int v4; // ST04_4@1
  signed int v5; // eax@1
  WOrderHdr wHdr; // [sp+8h] [bp-10h]@1

  v2 = blob->bufSize_;
  v3 = this;
  v4 = blob->bufSize_;
  blob = (NetBlob *)blob->buf_;
  wHdr.vfptr = (PackObjVtbl *)&WOrderHdr::vftable;
  wHdr.iid_ = 0;
  wHdr.stamp_ = 0;
  WOrderHdr::UnPack(&wHdr, (void **)&blob, v4);
  v5 = UIElement_Text::GetUIElementType();
  UIQueueManager::ProcessNetBlobData(v3, blob, v2 - v5);
}
// 7CC3E4: using guessed type int (__thiscall *WOrderHdr::vftable)(void *, char);

//----- (0055D0C0) --------------------------------------------------------  // acclient.c:395383
void __thiscall UIQueueManager::ProcessEphemeralNetBlob(UIQueueManager *this, NetBlob *blob)
{
  UIQueueManager *v2; // esi@1
  NetBlob *v3; // edi@1
  void *v4; // eax@2
  NIListElement<NetBlob *> *v5; // ecx@5
  unsigned int v6; // esi@8
  InterfaceSystem *v7; // eax@9
  NetBlob *v8; // ebp@9
  unsigned int v9; // ST04_4@13
  ClientObjMaintSystem *v10; // esi@13
  int v11; // [sp-8h] [bp-28h]@9
  TResult result; // [sp+10h] [bp-10h]@9
  char v13; // [sp+14h] [bp-Ch]@11
  InterfacePtr<ClientObjMaintSystem> spObjMaint; // [sp+18h] [bp-8h]@9

  v2 = this;
  v3 = blob;
  if ( this->m_fCrucialOrderedEventsReceived )
  {
    v6 = UIQueueManager::ProcessNetBlobData(this, blob->buf_, blob->bufSize_);
    if ( v6 )
    {
      blob = 0;
      v7 = InterfaceSystem::GetInstance();
      InterfaceSystem::GetClass(v7, &result, &ClientObjMaintSystem_ClassType_2, (Interface **)&blob);
      v11 = (int)blob;
      v8 = blob;
      spObjMaint.m_pInterface = 0;
      spObjMaint.m_trStatus.m_val = 0;
      if ( blob )
        ((void (__thiscall *)(NetBlob *))blob->vfptr[4].__vecDelDtor)(blob);
      InterfacePtr<ClientObjMaintSystem>::_QueryInterface(&spObjMaint, (int)&v13, v11, 0);
      if ( v8 )
        ((void (__thiscall *)(NetBlob *))v8->vfptr[5].__vecDelDtor)(v8);
      v9 = v6;
      v10 = spObjMaint.m_pInterface;
      CObjectMaint::QueueBlobForWeenieObject((CObjectMaint *)&spObjMaint.m_pInterface->vfptr, v9, v3);
      if ( v10 )
        v10->vfptr->Release((Interface *)v10);
    }
  }
  else
  {
    InterlockedIncrement((volatile LONG *)&blob->m_cRef);
    v4 = operator new(8u);
    if ( v4 )
    {
      *(_DWORD *)v4 = v3;
      *((_DWORD *)v4 + 1) = 0;
    }
    else
    {
      v4 = 0;
    }
    v5 = v2->m_rgWaitingBlobs.tail_;
    if ( v5 )
    {
      v5->next_ = (NIListElement<NetBlob *> *)v4;
      v2->m_rgWaitingBlobs.tail_ = v2->m_rgWaitingBlobs.tail_->next_;
    }
    else
    {
      v2->m_rgWaitingBlobs.head_ = (NIListElement<NetBlob *> *)v4;
      v2->m_rgWaitingBlobs.tail_ = (NIListElement<NetBlob *> *)v4;
    }
  }
}

//----- (0055D1C0) --------------------------------------------------------  // acclient.c:395453
void __thiscall UIQueueManager::HandleOrderingForBlob(UIQueueManager *this, NetBlob *blob)
{
  NetBlob *v2; // ebx@1
  char *v3; // eax@1
  unsigned int v4; // esi@1
  UIQueueManager *v5; // ebp@1
  unsigned int v6; // ST08_4@1
  signed int v7; // eax@4
  InterfaceSystem *v8; // eax@5
  NetBlob *v9; // esi@5
  CObjectMaint *v10; // ebp@9
  HashBaseData<unsigned long> *v11; // eax@10
  HashBaseData<unsigned long> *v12; // esi@10
  int v13; // [sp-8h] [bp-40h]@5
  void *buff; // [sp+10h] [bp-28h]@1
  UIQueueManager *v15; // [sp+14h] [bp-24h]@1
  TResult result; // [sp+18h] [bp-20h]@5
  char v17; // [sp+1Ch] [bp-1Ch]@7
  InterfacePtr<CObjectMaint> objMaint; // [sp+20h] [bp-18h]@5
  WOrderHdr wHdr; // [sp+28h] [bp-10h]@1

  v2 = blob;
  v3 = blob->buf_;
  v4 = blob->bufSize_;
  v5 = this;
  v6 = blob->bufSize_;
  v15 = this;
  buff = v3;
  wHdr.vfptr = (PackObjVtbl *)&WOrderHdr::vftable;
  wHdr.iid_ = 0;
  wHdr.stamp_ = 0;
  if ( !WOrderHdr::UnPack(&wHdr, &buff, v6) )
  {
    UIQueueManager::ProcessNetBlobData(v5, v2->buf_, v2->bufSize_);
    return;
  }
  if ( !wHdr.iid_ )
  {
    v7 = UIElement_Text::GetUIElementType();
    UIQueueManager::ProcessNetBlobData(v5, buff, v4 - v7);
    return;
  }
  blob = 0;
  v8 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v8, &result, &CObjectMaint_ClassType_1, (Interface **)&blob);
  v13 = (int)blob;
  v9 = blob;
  objMaint.m_pInterface = 0;
  objMaint.m_trStatus.m_val = 0;
  if ( blob )
    ((void (__thiscall *)(NetBlob *))blob->vfptr[4].__vecDelDtor)(blob);
  InterfacePtr<CObjectMaint>::_QueryInterface(&objMaint, (int)&v17, v13, 0);
  if ( v9 )
    ((void (__thiscall *)(NetBlob *))v9->vfptr[5].__vecDelDtor)(v9);
  v10 = objMaint.m_pInterface;
  if ( (_DWORD)objMaint.m_pInterface )
  {
    v11 = CObjectMaint::GetWeenieObject(objMaint.m_pInterface, wHdr.iid_);
    v12 = v11;
    if ( v11 )
    {
      blob = 0;
      if ( CWeenieObject::fIsNextBlob((CWeenieObject *)v11, wHdr.stamp_, v2, &blob) == 1 )
      {
        ((void (__stdcall *)(NetBlob *))v15->vfptr[1].QueryInterface)(blob);
        ((void (__thiscall *)(HashBaseData<unsigned long> *))v12->vfptr[2].__vecDelDtor)(v12);
      }
      if ( blob )
      {
        ReferenceCountTemplate<1048576,0>::Release((ReferenceCountTemplate<1048576,0> *)&blob->vfptr);
        v10->vfptr->Release((Interface *)v10);
        return;
      }
    }
    else
    {
      CObjectMaint::QueueBlobForWeenieObject(v10, wHdr.iid_, wHdr.stamp_, v2);
    }
    v10->vfptr->Release((Interface *)v10);
  }
}
// 7CC3E4: using guessed type int (__thiscall *WOrderHdr::vftable)(void *, char);

//----- (0055D330) --------------------------------------------------------  // acclient.c:395537
void __thiscall UIQueueManager::UseTime(UIQueueManager *this)
{
  UIQueueManager *v1; // edi@1
  NIList<NetBlob *> *v2; // ecx@2
  NIListElement<NetBlob *> *v3; // eax@2
  NetBlob *v4; // esi@3
  NIListElement<NetBlob *> *v5; // edx@4
  unsigned __int64 v6; // rax@8
  unsigned int v7; // esi@14

  v1 = this;
  if ( this->m_pUIQueue )
  {
    while ( 1 )
    {
      v2 = v1->m_pUIQueue;
      v3 = v2->head_;
      if ( v2->head_ )
      {
        v5 = v3->next_;
        v2->head_ = v5;
        if ( !v5 )
          v2->tail_ = 0;
        v4 = v3->data_;
        operator delete(v3);
      }
      else
      {
        v4 = 0;
      }
      if ( !v4 )
        break;
      v6 = NetBlobIDUtils::GetOrderingType(v4->id);
      if ( (_DWORD)v6 || HIDWORD(v6) != 0x80000000 )
        UIQueueManager::HandleOrderingForBlob(v1, v4);
      else
        ((void (__thiscall *)(UIQueueManager *, _DWORD))v1->vfptr[1].AddRef)(v1, v4);
      if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
        v4->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 1u);
    }
    v7 = 0;
    if ( v1->m_rgSystems.m_num )
    {
      do
        ((void (*)(void))v1->m_rgSystems.m_data[v7++]->vfptr[1].IUnknown_AddRef)();
      while ( v7 < v1->m_rgSystems.m_num );
    }
  }
}

//----- (006ADA10) --------------------------------------------------------  // acclient.c:710857
signed int __thiscall PackableList<ContentProfile>::Pack(PackableList<ContentProfile> *this, void **addr, unsigned int size)
{
  PackableList<ContentProfile> *v3; // esi@1
  signed int v4; // ebp@1
  PackableLLNode<ContentProfile> *i; // esi@4

  v3 = this;
  v4 = PackableList<ContentProfile>::pack_size(this);
  if ( size >= v4 )
  {
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v3->curNum;
      *addr = (char *)*addr + 4;
    }
    for ( i = v3->head; i; i = i->next )
      ((void (__thiscall *)(PackableLLNode<ContentProfile> *, void **, unsigned int))i->data.vfptr->Pack)(i, addr, size);
  }
  return v4;
}

//----- (006ADA60) --------------------------------------------------------  // acclient.c:710879
signed int __thiscall PackableList<ContentProfile>::pack_size(PackableList<ContentProfile> *this)
{
  PackableLLNode<ContentProfile> *v1; // esi@1
  signed int v2; // edi@1
  int v3; // eax@2
  void *addr; // [sp+0h] [bp-4h]@1

  addr = this;
  v1 = this->head;
  v2 = 4;
  for ( addr = 0; v1; v2 += v3 )
  {
    v3 = ((int (__thiscall *)(PackableLLNode<ContentProfile> *, void **, _DWORD))v1->data.vfptr->Pack)(v1, &addr, 0);
    v1 = v1->next;
  }
  return v2;
}

//----- (00708020) --------------------------------------------------------  // acclient.c:795246
void sub_708020()
{
  flt_870120 = 1000.0 + 1.0;
}

//----- (00708040) --------------------------------------------------------  // acclient.c:795252
void sub_708040()
{
  flt_870124 = 24.0 * 8.0;
}

//----- (00708060) --------------------------------------------------------  // acclient.c:795258
void sub_708060()
{
  flt_870128 = 24.0 * 0.5;
}

//----- (00708080) --------------------------------------------------------  // acclient.c:795264
int sub_708080()
{
  return atexit(nullsub_1307);
}

//----- (00708090) --------------------------------------------------------  // acclient.c:795270
int sub_708090()
{
  return atexit(nullsub_1308);
}

//----- (007080A0) --------------------------------------------------------  // acclient.c:795276
int sub_7080A0()
{
  return atexit(nullsub_1309);
}

//----- (007080B0) --------------------------------------------------------  // acclient.c:795282
void sub_7080B0()
{
  flt_87012C = 0.00019999999 * 3.0 + 0.1;
}

//----- (007080D0) --------------------------------------------------------  // acclient.c:795288
void _E108_85()
{
  dbl_870130 = 1.0 / 30.0;
}

//----- (007080F0) --------------------------------------------------------  // acclient.c:795294
void _E110_68()
{
  dbl_870138 = 1.0 / 5.0;
}

//----- (00708110) --------------------------------------------------------  // acclient.c:795300
void _E112_98()
{
  PixelFormatDesc::PixelFormatDesc(&stru_870140, PFID_A8R8G8B8);
}

//----- (00708120) --------------------------------------------------------  // acclient.c:795306
void _E115_70()
{
  dword_870178 = 1024;
}

//----- (00708130) --------------------------------------------------------  // acclient.c:795312
void _E117_66()
{
  dword_87017C = 0x7FFF;
}

//----- (00708140) --------------------------------------------------------  // acclient.c:795318
int _E119_20()
{
  const int result; // eax@1

  result = dword_870178;
  dword_870180 = dword_870178;
  return result;
}

//----- (00708150) --------------------------------------------------------  // acclient.c:795328
int _E121_61()
{
  return atexit(_E122_88);
}

//----- (00708160) --------------------------------------------------------  // acclient.c:795334
int sub_708160()
{
  return atexit(nullsub_1306);
}

