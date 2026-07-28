/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UI
   Object     : AC\accui_misc\UI.obj
   Functions  : 104
   Addresses  : 00563F90 - 00773860 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00563F90) --------------------------------------------------------  // acclient.c:401273
ClientUISystem *__cdecl ClientUISystem::GetUISystem()
{
  return ClientUISystem::s_pUISystem;
}

//----- (00563FA0) --------------------------------------------------------  // acclient.c:401279
void ClientUISystem::OnStartup()
{
  APIManager::SetUIReady(1);
}

//----- (00563FB0) --------------------------------------------------------  // acclient.c:401285
CSoundTable *__thiscall ClientUISystem::GetUISoundTable(ClientUISystem *this)
{
  ClientUISystem *v1; // esi@1

  v1 = this;
  if ( !this->soundTable )
    this->soundTable = (CSoundTable *)DBObj::GetByEnum(268435459, 7, 0x22u);
  return v1->soundTable;
}

//----- (00563FE0) --------------------------------------------------------  // acclient.c:401296
unsigned int __stdcall ClientUISystem::Handle_Item__QueryItemManaResponse(unsigned int target, float mana, int fSuccess)
{
  CM_Item::SendNotice_UpdateItemMana(target, mana, fSuccess != 0);
  return 0;
}

//----- (00564010) --------------------------------------------------------  // acclient.c:401303
void __thiscall ClientUISystem::AttemptSellToVendor(ClientUISystem *this, unsigned int _vendorID, unsigned int _objectID)
{
  ClientUISystem *v3; // esi@1
  HashBaseData<unsigned long> *v4; // eax@1

  v3 = this;
  v4 = ClientObjMaintSystem::GetWeenieObject(_objectID);
  if ( v4 && ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v4) )
  {
    if ( v3->vendorID == _vendorID )
    {
      CM_Vendor::SendNotice_AddItemToSell(_objectID);
    }
    else
    {
      ItemHolder::UseObject(_vendorID, 0, 0);
      v3->attemptOpenVendorID = _vendorID;
      v3->attemptSaleObjectID = _objectID;
    }
  }
}

//----- (00564070) --------------------------------------------------------  // acclient.c:401326
void __thiscall ClientUISystem::CloseVendor(ClientUISystem *this, int _updating)
{
  if ( this->vendorID )
  {
    if ( !(_BYTE)_updating )
      this->vendorID = 0;
    CM_Vendor::SendNotice_CloseVendor(_updating);
  }
}

//----- (00564090) --------------------------------------------------------  // acclient.c:401337
unsigned int ClientUISystem::Handle_Character__ReturnPing()
{
  CM_Character::SendNotice_Ping();
  return 0;
}

//----- (005640A0) --------------------------------------------------------  // acclient.c:401344
unsigned int __stdcall ClientUISystem::Handle_Character__ConfirmationRequest(int confirm, unsigned int context, AC1Legacy::PStringBase<char> *userData)
{
  unsigned int result; // eax@2

  switch ( confirm )
  {
    case 1:
      CM_Allegiance::SendNotice_SwearAllegianceRequest(userData, context);
      result = 0;
      break;
    case 4:
      CM_Fellowship::SendNotice_FellowshipRequest(userData, context);
      result = 0;
      break;
    case 2:
      CM_Character::SendNotice_AlterSkill_ConfirmationRequest(userData, context);
      result = 0;
      break;
    case 3:
      CM_Character::SendNotice_AlterAttribute_ConfirmationRequest(userData, context);
      result = 0;
      break;
    case 6:
      CM_Character::SendNotice_Augmentation_ConfirmationRequest(userData, context);
      result = 0;
      break;
    case 5:
      CM_Character::SendNotice_CraftInteraction_ConfirmationRequest(userData, context);
      result = 0;
      break;
    case 7:
      CM_Character::SendNotice_YesNo_ConfirmationRequest(userData, context);
      goto LABEL_9;
    default:
LABEL_9:
      result = 0;
      break;
  }
  return result;
}

//----- (00564180) --------------------------------------------------------  // acclient.c:401386
unsigned int __stdcall ClientUISystem::Handle_Character__ConfirmationDone(int confirm, unsigned int context)
{
  CM_Character::SendNotice_AbortConfirmationRequest(confirm, context);
  return 0;
}

//----- (005641A0) --------------------------------------------------------  // acclient.c:401393
unsigned int __stdcall ClientUISystem::Handle_Login__WorldInfo(int cConnections, int cMaxConnections, AC1Legacy::PStringBase<char> *strWorldName)
{
  ECM_Login::SendNotice_WorldName(strWorldName);
  return 0;
}

//----- (005641C0) --------------------------------------------------------  // acclient.c:401400
void __thiscall ClientUISystem::InitializeCameraSet(ClientUISystem *this, SmartBox *i_pSmartBox)
{
  ClientUISystem *v2; // esi@1
  CameraSet *v3; // eax@1
  CameraSet *v4; // eax@2

  v2 = this;
  v3 = (CameraSet *)operator new(0x88u);
  if ( v3 )
  {
    CameraSet::CameraSet(v3, i_pSmartBox);
    v2->m_pCameraSet = v4;
  }
  else
  {
    v2->m_pCameraSet = 0;
  }
}

//----- (005641F0) --------------------------------------------------------  // acclient.c:401420
CameraSet *__thiscall ClientUISystem::AccessCameraSet(ClientUISystem *this)
{
  return this->m_pCameraSet;
}

//----- (00564200) --------------------------------------------------------  // acclient.c:401426
void __stdcall ClientUISystem::RecvNotice_ToggleChatEntry(bool i_bActive)
{
  if ( i_bActive )
    ((void (*)(void))SmartBox::smartbox->cmdinterp->vfptr[6].OnLoseFocus)();
}

//----- (00564220) --------------------------------------------------------  // acclient.c:401433
unsigned int __stdcall ClientUISystem::Handle_Social__FriendsUpdate(FriendDataList *friendDataList, int updateType)
{
  CM_Social::SendNotice_UpdateFriendsList(friendDataList, updateType);
  return 0;
}

//----- (00564240) --------------------------------------------------------  // acclient.c:401440
unsigned int __stdcall ClientUISystem::Handle_Social__CharacterTitleTable(CharacterTitleTable *titleTable)
{
  CM_Social::SendNotice_UpdateCharacterTitleTable(titleTable);
  return 0;
}

//----- (00564260) --------------------------------------------------------  // acclient.c:401447
unsigned int __stdcall ClientUISystem::Handle_Social__AddOrSetCharacterTitle(unsigned int newTitle, int bSetAsDisplayTitle)
{
  CM_Social::SendNotice_AddCharacterTitle(newTitle);
  if ( bSetAsDisplayTitle )
    CM_Social::SendNotice_SetDisplayCharacterTitle(newTitle);
  return 0;
}

//----- (00564290) --------------------------------------------------------  // acclient.c:401456
unsigned int __stdcall ClientUISystem::Handle_Social__SendClientContractTrackerTable(CContractTrackerTable *contractTrackerTable)
{
  CPlayerSystem *v2; // eax@1

  v2 = CPlayerSystem::GetPlayerSystem();
  CPlayerSystem::UpdateContractTrackerTable(v2, contractTrackerTable);
  return 0;
}

//----- (005642B0) --------------------------------------------------------  // acclient.c:401466
unsigned int __stdcall ClientUISystem::Handle_Character__StartBarber(IDClass<_tagDataID,32,0> _base_palette, IDClass<_tagDataID,32,0> _head_object, IDClass<_tagDataID,32,0> _head_texture, IDClass<_tagDataID,32,0> _default_head_texture, IDClass<_tagDataID,32,0> _eyes_texture, IDClass<_tagDataID,32,0> _default_eyes_texture, IDClass<_tagDataID,32,0> _nose_texture, IDClass<_tagDataID,32,0> _default_nose_texture, IDClass<_tagDataID,32,0> _mouth_texture, IDClass<_tagDataID,32,0> _default_mouth_texture, IDClass<_tagDataID,32,0> _skin_palette, IDClass<_tagDataID,32,0> _hair_palette, IDClass<_tagDataID,32,0> _eyes_palette, IDClass<_tagDataID,32,0> _setup_id, int option1, int option2)
{
  CM_Character::SendNotice_StartBarberNotice(
    _base_palette,
    _head_object,
    _head_texture,
    _default_head_texture,
    _eyes_texture,
    _default_eyes_texture,
    _nose_texture,
    _default_nose_texture,
    _mouth_texture,
    _default_mouth_texture,
    _skin_palette,
    _hair_palette,
    _eyes_palette,
    _setup_id,
    option1,
    option2);
  return 0;
}

//----- (00564310) --------------------------------------------------------  // acclient.c:401489
void __thiscall ClientUISystem::~ClientUISystem(ClientUISystem *this)
{
  ClientUISystem *v1; // esi@1
  char *v2; // ebx@1
  char *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v1 = this;
  v2 = (char *)&this[-1].m_pCameraSet;
  v3 = (char *)&this[-1].m_bRadarVisible;
  this[-1].m_pCameraSet = (CameraSet *)&ClientUISystem::vftable;
  *(_DWORD *)&this[-1].m_bRadarVisible = &ClientUISystem::vftable;
  this->vfptr = (InterfaceVtbl *)&ClientUISystem::vftable;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers(
      (NoticeRegistrar *)v4,
      (NoticeHandler *)(v1 != (ClientUISystem *)8 ? (unsigned int)v3 : 0));
  v1->vfptr = (NoticeHandlerVtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  *(_DWORD *)(v1 != (ClientUISystem *)8 ? (unsigned int)v1 : 0) = &IInputActionCallback::vftable;
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(v1 != (ClientUISystem *)8 ? (unsigned int)v1 : 0);
  if ( v2 )
  {
    *((_DWORD *)v2 + 1) = &ClientHousingSystem::vftable;
    NoticeHandler::~NoticeHandler((NoticeHandler *)v2 + 1);
  }
  else
  {
    v0 = (size_t)&ClientHousingSystem::vftable;
    NoticeHandler::~NoticeHandler(0);
  }
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CDB74: using guessed type int (__stdcall *ClientUISystem::vftable)(char);
// 7CDB80: using guessed type bool (__thiscall *ClientUISystem::vftable)(DBCache *this);
// 7CDE28: using guessed type __int32 (__stdcall *ClientUISystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005643A0) --------------------------------------------------------  // acclient.c:401530
unsigned int __thiscall ClientUISystem::Release(ClientUISystem *this)
{
  ClientUISystem *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
    v1->vfptr->__vecDelDtor(&v1->vfptr, 1);
  return v2;
}

//----- (005643D0) --------------------------------------------------------  // acclient.c:401543
void __thiscall ClientUISystem::OnShutdown(ClientUISystem *this)
{
  ClientUISystem *v1; // edi@1
  CSoundTable *v2; // ecx@3
  CameraSet *v3; // esi@5

  v1 = this;
  APIManager::SetUIReady(0);
  if ( ClientUISystem::s_pUISystem )
  {
    ((void (*)(void))ClientUISystem::s_pUISystem->vfptr->Release)();
    ClientUISystem::s_pUISystem = 0;
  }
  v2 = v1->soundTable;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->soundTable = 0;
  }
  v3 = v1->m_pCameraSet;
  if ( v3 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
    {
      if ( v3 )
        v3->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 1u);
    }
    v1->m_pCameraSet = 0;
  }
}

//----- (00564440) --------------------------------------------------------  // acclient.c:401575
TResult *__thiscall ClientUISystem::QueryInterface(ClientUISystem *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( _S176_44 & 1 )
  {
    v4 = Offsets_4[0].key;
  }
  else
  {
    v4 = (_GUID *)&ClientUISystem_InterfaceType_55;
    _S176_44 |= 1u;
    Offsets_4[0].key = (_GUID *)&ClientUISystem_InterfaceType_55;
    dword_870414 = 0;
    dword_870418 = (int)&ClientSystem_InterfaceType_83;
    dword_87041C = 0;
    dword_870420 = (int)&stru_7CDB58;
    dword_870424 = 0;
    dword_870428 = 0;
    dword_87042C = 0;
  }
  v5 = (int)Offsets_4;
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
// 870414: using guessed type int dword_870414;
// 870418: using guessed type int dword_870418;
// 87041C: using guessed type int dword_87041C;
// 870420: using guessed type int dword_870420;
// 870424: using guessed type int dword_870424;
// 870428: using guessed type int dword_870428;
// 87042C: using guessed type int dword_87042C;

//----- (00564510) --------------------------------------------------------  // acclient.c:401642
void __thiscall ClientUISystem::SetGroundObject(ClientUISystem *this, unsigned int _groundObject, bool _askServer)
{
  ClientUISystem *v3; // esi@1
  HashBaseData<unsigned long> *v4; // eax@5
  unsigned int v5; // ecx@9
  HashBaseData<unsigned long> *v6; // eax@12
  HashBaseData<unsigned long> *v7; // eax@16

  v3 = this;
  if ( this->groundObject != _groundObject )
  {
    if ( this->vendorID )
    {
      this->vendorID = 0;
      CM_Vendor::SendNotice_CloseVendor(0);
    }
    if ( v3->groundObject )
    {
      v4 = ClientObjMaintSystem::GetWeenieObject(v3->groundObject);
      if ( v4 )
        ACCWeenieObject::AddContentsToDestructionQueue((ACCWeenieObject *)v4);
      CM_Item::SendNotice_SetGroundObject(0);
      if ( _askServer )
        CM_Inventory::Event_NoLongerViewingContents(v3->groundObject);
    }
    v5 = v3->groundObject;
    if ( v5 )
    {
      if ( ACCWeenieObject::selectedID )
      {
        if ( ACCWeenieObject::selectedID != v5 )
        {
          v6 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
          if ( v6 )
          {
            if ( ACCWeenieObject::IsOwnedByObject((ACCWeenieObject *)v6, v3->groundObject) )
              ACCWeenieObject::SetSelectedObject(0, 0);
          }
        }
      }
    }
    v3->groundObject = _groundObject;
    v3->requestedGroundObject = _groundObject;
    if ( _groundObject )
    {
      v7 = ClientObjMaintSystem::GetWeenieObject(_groundObject);
      if ( ((int (__thiscall *)(HashBaseData<unsigned long> *))v7->vfptr[31].__vecDelDtor)(v7) )
        ACCWeenieObject::SetCorpseOpened(v3->groundObject);
    }
  }
}

//----- (005645E0) --------------------------------------------------------  // acclient.c:401695
void __thiscall ClientUISystem::OnBeginCharacterSession(ClientUISystem *this)
{
  CInputManager *v1; // esi@1
  ClientUISystem *v2; // edi@1
  IInputActionCallback *v3; // eax@3
  int v4; // eax@6

  v1 = ICIDM::s_cidm;
  v2 = this;
  if ( ICIDM::s_cidm )
  {
    if ( this )
      v3 = (IInputActionCallback *)&this->vfptr;
    else
      v3 = 0;
    ICIDM::s_cidm->vfptr->RegisterInputMap((ICIDM *)ICIDM::s_cidm, 268435465u, v3, 1000);
    if ( v2 )
      v4 = (int)&v2->vfptr;
    else
      v4 = 0;
    v1->vfptr->RegisterInputMap((ICIDM *)v1, 268435468u, (IInputActionCallback *)v4, 1000);
  }
}

//----- (00564630) --------------------------------------------------------  // acclient.c:401720
void __thiscall ClientUISystem::UpdateCursorState(ClientUISystem *this)
{
  bool v1; // bl@1
  int v2; // edi@1
  int v3; // ebp@1
  int v4; // esi@1
  Target_Mode v5; // eax@3
  int v6; // eax@4
  int v7; // eax@5
  unsigned __int32 v8; // eax@8
  int v9; // edx@10
  __int32 v10; // eax@12
  int v11; // eax@13
  unsigned int v12; // eax@18
  ClientUISystem *v13; // [sp+10h] [bp-8h]@1
  IDClass<_tagDataID,32,0> didCursor; // [sp+14h] [bp-4h]@18

  v13 = this;
  v1 = SmartBox::get_found_object_id() != 0;
  v2 = 0;
  v3 = 0;
  v4 = v1 + 1;
  if ( v13->m_cBusy )
  {
    v4 = (v1 != 0) + 14;
    goto LABEL_18;
  }
  v5 = v13->targetMode;
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( !v6 )
    {
      v2 = 14;
      v3 = 14;
      v4 = (v1 != 0) + 12;
      goto LABEL_18;
    }
    v7 = v6 - 1;
    if ( v7 )
    {
      if ( v7 == 1 )
      {
        if ( v1 )
        {
          v8 = SmartBox::get_found_object_id();
          v2 = 14;
          v3 = 14;
          v4 = 41 - (ItemHolder::IsTargetCompatibleWithTargetingObject(v8) != 0);
        }
        else
        {
          v2 = 14;
          v4 = 39;
          v3 = 14;
        }
      }
      goto LABEL_18;
    }
    v9 = (v1 != 0) + 10;
LABEL_17:
    v4 = v9;
    goto LABEL_18;
  }
  v10 = ClientCombatSystem::GetCombatSystem()->combatMode - 2;
  if ( !v10 || (v11 = v10 - 2) == 0 )
  {
    v9 = (v1 != 0) + 3;
    goto LABEL_17;
  }
  if ( v11 == 4 )
    v4 = (v1 != 0) + 5;
LABEL_18:
  DBObj::GetDIDByEnum(&didCursor, v4, 6);
  v12 = didCursor.id;
  if ( didCursor.id != v13->m_didCurrentCursor.id )
  {
    v13->m_didCurrentCursor.id = didCursor.id;
    if ( UIElementManager::s_pInstance )
      UIElementManager::SetCursor(UIElementManager::s_pInstance, (IDClass<_tagDataID,32,0>)v12, v2, v3, 1);
  }
}

//----- (00564750) --------------------------------------------------------  // acclient.c:401804
unsigned int __stdcall ClientUISystem::Handle_Social__SendClientContractTracker(CContractTracker *contractTracker, int bDeleteContract, int bSetAsDisplayContract)
{
  CPlayerSystem *v4; // eax@1
  CContractTracker v6; // [sp-2Ch] [bp-30h]@1
  CContractTracker v7; // [sp-28h] [bp-2Ch]@2
  int v8; // [sp-4h] [bp-8h]@1

  v8 = bDeleteContract;
  CContractTracker::CContractTracker(&v6, contractTracker);
  v4 = CPlayerSystem::GetPlayerSystem();
  CPlayerSystem::UpdateContractTracker(v4, v6, v8);
  if ( bSetAsDisplayContract )
  {
    CContractTracker::CContractTracker(&v7, contractTracker);
    CPlayerSystem::GetPlayerSystem();
    CPlayerSystem::SetDisplayContractTracker(v7);
  }
  return 0;
}

//----- (005647A0) --------------------------------------------------------  // acclient.c:401825
void __thiscall ClientUISystem::ClientUISystem(ClientUISystem *this)
{
  ClientUISystem *v1; // esi@1
  char *v2; // edi@1
  GlobalEventHandler *v3; // eax@1

  v1 = this;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&IInputActionCallback::vftable;
  v2 = (char *)&this->vfptr;
  this->vfptr = (InterfaceVtbl *)&ClientUISystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientUISystem::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&ClientUISystem::vftable;
  this->m_cTurbineRefCount.m_cRef = 1;
  this->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  this->soundTable = 0;
  this->m_pCameraSet = 0;
  ClientUISystem::s_pUISystem = this;
  InterlockedIncrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef);
  v1->m_bLeaveTargetMode = 0;
  v1->targetMode = 0;
  v1->m_bRadarVisible = 1;
  v1->m_bRadarBlank = 0;
  v1->groundObject = 0;
  v1->requestedGroundObject = 0;
  v1->vendorID = 0;
  v1->attemptOpenVendorID = 0;
  v1->attemptSaleObjectID = 0;
  v1->m_cBusy = 0;
  v1->m_didCurrentCursor.id = stru_870360.id;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v3, (unsigned int)&loc_4DD26D, (NoticeHandler *)v2);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CDB74: using guessed type int (__stdcall *ClientUISystem::vftable)(char);
// 7CDB80: using guessed type bool (__thiscall *ClientUISystem::vftable)(DBCache *this);
// 7CDE28: using guessed type __int32 (__stdcall *ClientUISystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00564840) --------------------------------------------------------  // acclient.c:401867
int __thiscall ClientUISystem::scalar_deleting_destructor(ClientUISystem *this, char a2)
{
  ClientUISystem *v2; // esi@1
  int result; // eax@1

  v2 = this;
  ClientUISystem::~ClientUISystem(this);
  result = (int)&v2[-1].m_pCameraSet;
  if ( a2 & 1 )
  {
    operator delete(&v2[-1].m_pCameraSet);
    result = (int)&v2[-1].m_pCameraSet;
  }
  return result;
}

//----- (00564870) --------------------------------------------------------  // acclient.c:401884
void __thiscall ClientUISystem::IncrementBusyCount(ClientUISystem *this)
{
  unsigned int v1; // eax@1

  v1 = this->m_cBusy + 1;
  this->m_cBusy = v1;
  if ( v1 == 1 )
    ClientUISystem::UpdateCursorState(this);
}

//----- (00564890) --------------------------------------------------------  // acclient.c:401895
void __thiscall ClientUISystem::DecrementBusyCount(ClientUISystem *this)
{
  bool v1; // zf@1

  v1 = this->m_cBusy-- == 1;
  if ( v1 )
    ClientUISystem::UpdateCursorState(this);
}

//----- (005648A0) --------------------------------------------------------  // acclient.c:401905
void __thiscall ClientUISystem::CleanUpGameUI(ClientUISystem *this)
{
  ClientUISystem *v1; // esi@1

  v1 = this;
  CM_Trade::SendNotice_CloseTrade(0x451u);
  if ( v1->vendorID )
  {
    v1->vendorID = 0;
    CM_Vendor::SendNotice_CloseVendor(0);
  }
  ClientUISystem::SetGroundObject(v1, 0, 1);
  v1->requestedGroundObject = 0;
  ClientCombatSystem::GetCombatSystem()->targetWillinglyLost = 1;
  ACCWeenieObject::SetSelectedObject(0, 0);
}

//----- (00564900) --------------------------------------------------------  // acclient.c:401923
unsigned int __stdcall ClientUISystem::Handle_Item__UseDone(const unsigned int etype)
{
  ClientUISystem *v2; // ecx@1
  bool v3; // zf@1
  ClientCommunicationSystem *v4; // eax@4

  v2 = ClientUISystem::s_pUISystem;
  v3 = ClientUISystem::s_pUISystem->m_cBusy-- == 1;
  if ( v3 )
    ClientUISystem::UpdateCursorState(v2);
  if ( etype )
  {
    v4 = ClientCommunicationSystem::GetCommunicationSystem();
    if ( v4 )
      ClientCommunicationSystem::HandleFailureEvent(v4, etype, &PStringBase<unsigned short>::null_string);
  }
  return 0;
}

//----- (00564940) --------------------------------------------------------  // acclient.c:401943
void __thiscall ClientUISystem::SetTargetMode(ClientUISystem *this, Target_Mode i_targetMode)
{
  ClientUISystem *v2; // esi@1

  v2 = this;
  if ( this->targetMode != i_targetMode )
  {
    this->targetMode = i_targetMode;
    if ( i_targetMode )
    {
      if ( (signed int)i_targetMode > 0 && (signed int)i_targetMode <= 3 )
      {
        this->m_bLeaveTargetMode = 0;
        if ( ICIDM::s_cidm )
        {
          ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(
            268435467,
            &this->vfptr,
            2000);
          ClientUISystem::UpdateCursorState(v2);
          return;
        }
      }
    }
    else
    {
      this->m_bLeaveTargetMode = 0;
      if ( ICIDM::s_cidm )
        ((void (__stdcall *)(_DWORD, _DWORD))ICIDM::s_cidm->vfptr->UnregisterInputMap)(268435467, &this->vfptr);
    }
    ClientUISystem::UpdateCursorState(v2);
  }
}

//----- (005649B0) --------------------------------------------------------  // acclient.c:401978
void __thiscall ClientUISystem::UseObject(ClientUISystem *this, unsigned int i_iid)
{
  ClientUISystem *v2; // esi@1

  v2 = this;
  if ( i_iid )
  {
    ItemHolder::UseObject(i_iid, 0, 0);
  }
  else if ( this->targetMode != 1 )
  {
    this->targetMode = 1;
    this->m_bLeaveTargetMode = 0;
    if ( ICIDM::s_cidm )
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(
        268435467,
        &this->vfptr,
        2000);
    ClientUISystem::UpdateCursorState(v2);
  }
}

//----- (00564A10) --------------------------------------------------------  // acclient.c:402001
void __thiscall ClientUISystem::ExamineObject(ClientUISystem *this, unsigned int i_iid)
{
  ClientUISystem *v2; // esi@1

  v2 = this;
  if ( i_iid )
  {
    CM_Examine::SendNotice_ExamineObject(i_iid);
  }
  else if ( this->targetMode != 2 )
  {
    this->targetMode = 2;
    this->m_bLeaveTargetMode = 0;
    if ( ICIDM::s_cidm )
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(
        268435467,
        &this->vfptr,
        2000);
    ClientUISystem::UpdateCursorState(v2);
  }
}

//----- (00564A70) --------------------------------------------------------  // acclient.c:402024
void __thiscall ClientUISystem::ExamineSpell(ClientUISystem *this, unsigned int i_spellID)
{
  ClientUISystem *v2; // esi@1

  v2 = this;
  if ( i_spellID )
  {
    CM_Examine::SendNotice_ExamineSpell(i_spellID);
  }
  else if ( this->targetMode != 2 )
  {
    this->targetMode = 2;
    this->m_bLeaveTargetMode = 0;
    if ( ICIDM::s_cidm )
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(
        268435467,
        &this->vfptr,
        2000);
    ClientUISystem::UpdateCursorState(v2);
  }
}

//----- (00564AD0) --------------------------------------------------------  // acclient.c:402047
void __thiscall ClientUISystem::OnEndCharacterSession(ClientUISystem *this)
{
  ClientUISystem *v1; // esi@1
  char *v2; // eax@3

  v1 = this;
  if ( ICIDM::s_cidm )
  {
    if ( this )
      v2 = (char *)&this->vfptr;
    else
      v2 = 0;
    ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(v2);
  }
  ClientUISystem::CleanUpGameUI(v1);
  v1->m_bLeaveTargetMode = 0;
  v1->targetMode = 0;
  v1->m_bRadarBlank = 0;
  v1->groundObject = 0;
  v1->requestedGroundObject = 0;
  v1->vendorID = 0;
  v1->attemptOpenVendorID = 0;
  v1->attemptSaleObjectID = 0;
  v1->m_cBusy = 0;
  v1->m_bRadarVisible = 1;
  v1->m_didCurrentCursor.id = stru_870360.id;
  ClientUISystem::UpdateCursorState(v1);
}

//----- (00564B30) --------------------------------------------------------  // acclient.c:402077
void __thiscall ClientUISystem::ExecuteTargetModeForItem(ClientUISystem *this, unsigned int _itemID, Target_Mode _mode)
{
  switch ( _mode )
  {
    case 1:
      ItemHolder::UseObject(_itemID, 0, 0);
      break;
    case 2:
      ClientUISystem::ExamineObject(this, _itemID);
      break;
    case 3:
      ItemHolder::TargetAcquired(_itemID);
      break;
  }
}

//----- (00564B70) --------------------------------------------------------  // acclient.c:402094
void __stdcall ClientUISystem::ExecuteTargetModeForSpell(unsigned int _spellID, Target_Mode _mode)
{
  if ( _mode == 2 )
    ClientUISystem::ExamineSpell(ClientUISystem::s_pUISystem, _spellID);
}

//----- (00564B90) --------------------------------------------------------  // acclient.c:402101
bool __thiscall ClientUISystem::OnAction(ClientUISystem *this, InputEvent *i_evt)
{
  InputEvent *v2; // edx@1
  unsigned int v3; // eax@1
  ClientUISystem *v4; // esi@1
  bool result; // al@4
  UIElementManager *v6; // edi@5
  ClientCombatSystem *v7; // eax@5
  UIElement *v8; // ecx@8
  int v9; // eax@10
  bool v10; // bl@10
  ClientCombatSystem *v11; // eax@11
  ClientCombatSystem *v12; // eax@20
  ClientCombatSystem *v13; // eax@21
  int v14; // eax@33
  int v15; // eax@34
  UIElement *v16; // eax@38
  bool v17; // dl@43
  PStringBase<unsigned short> i_text; // [sp+Ch] [bp-8h]@19
  PStringBase<unsigned short> strMsg; // [sp+10h] [bp-4h]@23

  v2 = i_evt;
  v3 = i_evt->m_InputAction;
  v4 = this;
  if ( i_evt->m_InputAction > 0x7C )
  {
    v14 = v3 - 268435486;
    if ( v14 )
    {
      v15 = v14 - 7;
      if ( !v15 )
      {
        ClientUISystem::UseObject((ClientUISystem *)((char *)this - 8), ACCWeenieObject::selectedID);
        return 1;
      }
      if ( v15 != 6 )
        return 0;
      if ( UIElementManager::s_pInstance )
      {
        v16 = UIElementManager::GetElement(UIElementManager::s_pInstance, 0x100005F7u);
        if ( v16 && (*((_DWORD *)&v16->0 + 41) >> 1) & 1 )
        {
          v16->vfptr[2].__vecDelDtor((IInputActionCallback *)v16, 0);
          result = 1;
        }
        else
        {
          ClientUISystem::ExamineObject((ClientUISystem *)((char *)v4 - 8), ACCWeenieObject::selectedID);
          result = 1;
        }
        return result;
      }
    }
    else
    {
      v17 = this->m_bLeaveTargetMode;
      this->m_bLeaveTargetMode = v17 == 0;
      CM_UI::SendNotice_UpdateRadarVisibility(v17 == 0);
    }
    return 1;
  }
  if ( i_evt->m_InputAction != 124 )
  {
    switch ( v3 )
    {
      case 0x7Bu:
        KeyStone::OpenHelp(0, 268435457);
        return 1;
      case 0x27u:
        v6 = UIElementManager::s_pInstance;
        v7 = ClientCombatSystem::GetCombatSystem();
        if ( ClientCombatSystem::GetJumpPowerLevel(v7) > 0.0 )
        {
          ((void (*)(void))SmartBox::smartbox->cmdinterp->vfptr[6].OnLoseFocus)();
          return 1;
        }
        if ( v6 )
        {
          v8 = v6->m_focusElement;
          if ( v8 )
          {
            ((void (*)(void))v8->vfptr[22].__vecDelDtor)();
            return 1;
          }
        }
        v9 = ((int (*)(void))SmartBox::smartbox->cmdinterp->vfptr[15].OnAction)();
        v10 = v9 == 0;
        if ( v9 )
        {
          v11 = ClientCombatSystem::GetCombatSystem();
          if ( !(unsigned __int8)ClientCombatSystem::RepeatAttackInProgress(v11) )
          {
            if ( v4->attemptOpenVendorID )
            {
              ClientUISystem::SetTargetMode((ClientUISystem *)((char *)v4 - 8), 0);
              return 1;
            }
            if ( ACCWeenieObject::selectedID )
            {
              ClientCombatSystem::GetCombatSystem()->targetWillinglyLost = 1;
              ACCWeenieObject::SetSelectedObject(0, 0);
              return 1;
            }
            if ( v6 )
            {
              UIElementManager::DoVisibilityToggleAction(v6, 0x1000001Bu);
              return 1;
            }
            return 1;
          }
        }
        ((void (*)(void))SmartBox::smartbox->cmdinterp->vfptr[15].OnLoseFocus)();
        if ( v10 )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, L"Action interrupted");
          ClientSystem::AddTextToScroll((ClientSystem *)&v4[-1].m_pCameraSet, &i_text, 0x1Au, 1, 0);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_text);
        }
        v12 = ClientCombatSystem::GetCombatSystem();
        if ( (unsigned __int8)ClientCombatSystem::RepeatAttackInProgress(v12) )
        {
          v13 = ClientCombatSystem::GetCombatSystem();
          ClientCombatSystem::AbortAutomaticAttack(v13);
          return 0;
        }
        break;
      case 0x55u:
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&i_evt);
        if ( Device::SaveScreenshot((PStringBase<char> *)&i_evt) )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(&strMsg, 0, L"Screenshot saved to file '%hs'", i_evt);
          ClientSystem::AddTextToScroll((ClientSystem *)&v4[-1].m_pCameraSet, &strMsg, 0x1Au, 1, 0);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strMsg);
        }
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_evt);
        return 1;
      case 7u:
      case 8u:
        if ( i_evt->m_fStart && this->attemptOpenVendorID )
          LOBYTE(this->m_didCurrentCursor.id) = 1;
        if ( !UIElementManager::s_pInstance )
          return 0;
        return ((int (__stdcall *)(InputEvent *))UIElementManager::s_pInstance->vfptr->OnAction)(v2);
      default:
        return 0;
    }
    return 0;
  }
  if ( KeyStone::IsPluginManagerOpen() )
  {
    KeyStone::ClosePluginManager();
    result = 1;
  }
  else
  {
    KeyStone::OpenPluginManager();
    result = 1;
  }
  return result;
}

//----- (00564F30) --------------------------------------------------------  // acclient.c:402263
unsigned int ClientUISystem::Handle_Misc__PortalStormSubsided()
{
  unsigned int v1; // eax@1
  char *v2; // esi@1
  PStringBase<unsigned short> _value; // [sp+4h] [bp-94h]@1
  StringInfo siError; // [sp+8h] [bp-90h]@1

  StringInfo::StringInfo(&siError);
  v1 = _wcslen(L"The Portal Storm has subsided");
  PStringBase<unsigned short>::allocate_ref_buffer(&_value, v1);
  _wcscpy(_value.m_charbuffer->m_data, L"The Portal Storm has subsided");
  StringInfo::SetLiteralValue(&siError, &_value, 1);
  v2 = (char *)&_value.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v2 )
    (**(void (__thiscall ***)(char *, signed int))v2)(v2, 1);
  ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
  CM_Misc::SendNotice_PortalStormLevel(0.0);
  StringInfo::~StringInfo(&siError);
  return 0;
}

//----- (00564FD0) --------------------------------------------------------  // acclient.c:402285
unsigned int __stdcall ClientUISystem::Handle_Misc__PortalStormBrewing(float extent)
{
  unsigned int v2; // eax@1
  char *v3; // esi@1
  unsigned int v4; // eax@5
  HashBaseData<unsigned long> *v5; // eax@7
  PStringBase<unsigned short> _value; // [sp+0h] [bp-94h]@1
  StringInfo siError; // [sp+4h] [bp-90h]@1

  StringInfo::StringInfo(&siError);
  v2 = _wcslen(L"This area is getting too crowded - a Portal Storm is brewing.");
  PStringBase<unsigned short>::allocate_ref_buffer(&_value, v2);
  _wcscpy(_value.m_charbuffer->m_data, L"This area is getting too crowded - a Portal Storm is brewing.");
  StringInfo::SetLiteralValue(&siError, &_value, 1);
  v3 = (char *)&_value.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  v5 = ClientObjMaintSystem::GetPhysicsObject(v4);
  if ( v5 )
    CPhysicsObj::play_script((CPhysicsObj *)v5, PS_PortalStorm, 0.0);
  CM_Misc::SendNotice_PortalStormLevel(extent);
  StringInfo::~StringInfo(&siError);
  return 0;
}

//----- (005650A0) --------------------------------------------------------  // acclient.c:402316
unsigned int __stdcall ClientUISystem::Handle_Misc__PortalStormImminent(float extent)
{
  unsigned int v2; // eax@1
  char *v3; // esi@1
  unsigned int v4; // eax@5
  HashBaseData<unsigned long> *v5; // eax@7
  PStringBase<unsigned short> _value; // [sp+0h] [bp-94h]@1
  StringInfo siError; // [sp+4h] [bp-90h]@1

  StringInfo::StringInfo(&siError);
  v2 = _wcslen(L"A Portal Storm is imminent - leave this crowded area!");
  PStringBase<unsigned short>::allocate_ref_buffer(&_value, v2);
  _wcscpy(_value.m_charbuffer->m_data, L"A Portal Storm is imminent - leave this crowded area!");
  StringInfo::SetLiteralValue(&siError, &_value, 1);
  v3 = (char *)&_value.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  v5 = ClientObjMaintSystem::GetPhysicsObject(v4);
  if ( v5 )
    CPhysicsObj::play_script((CPhysicsObj *)v5, PS_PortalStorm, 1.0);
  CM_Misc::SendNotice_PortalStormLevel(extent);
  StringInfo::~StringInfo(&siError);
  return 0;
}

//----- (00565170) --------------------------------------------------------  // acclient.c:402347
unsigned int __thiscall ClientUISystem::Handle_Misc__PortalStorm(ClientUISystem *this)
{
  ClientSystem *v1; // esi@1
  unsigned int v2; // eax@1
  char *v3; // esi@1
  PStringBase<unsigned short> msg; // [sp+0h] [bp-4h]@1

  msg.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v1 = (ClientSystem *)this;
  v2 = _wcslen(L"The Portal Storm has teleported you away from the crowded area!\n");
  PStringBase<unsigned short>::allocate_ref_buffer(&msg, v2);
  _wcscpy(msg.m_charbuffer->m_data, L"The Portal Storm has teleported you away from the crowded area!\n");
  CM_Misc::SendNotice_PlayerPortalStormed();
  CM_Misc::SendNotice_PortalStormLevel(0.0);
  ClientSystem::AddTextToScroll(v1, &msg, 0, 1, 0);
  v3 = (char *)&msg.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  return 0;
}

//----- (005651F0) --------------------------------------------------------  // acclient.c:402369
void __usercall ClientUISystem::UseTime(ClientUISystem *this@<ecx>, double a2@<st0>)
{
  CInputManager *v2; // ebp@1
  ClientUISystem *v3; // esi@1
  InterfaceSystem *v4; // eax@1
  Interface *v5; // edi@1
  ICIDMVtbl *v6; // edx@5
  PlayerDesc *v7; // edi@5
  CPlayerSystem *v8; // eax@9
  int v9; // [sp-8h] [bp-30h]@1
  Interface *_rpInterface; // [sp+10h] [bp-18h]@1
  TResult result; // [sp+14h] [bp-14h]@1
  double v12; // [sp+18h] [bp-10h]@3
  InterfacePtr<PlayerDesc> spPD; // [sp+20h] [bp-8h]@1

  v2 = ICIDM::s_cidm;
  v3 = this;
  _rpInterface = 0;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v4, &result, &PlayerDesc_ClassType_27, &_rpInterface);
  v9 = (int)_rpInterface;
  v5 = _rpInterface;
  spPD.m_pInterface = 0;
  spPD.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  _rpInterface = *(Interface **)InterfacePtr<PlayerDesc>::_QueryInterface(&spPD, (int)&v12, v9, 0);
  if ( v5 )
    v5->vfptr->Release(v5);
  v6 = v2->vfptr;
  v12 = *(double *)&Timer::cur_time;
  (*(void (__thiscall **)(CInputManager *))&v6->gap4[16])(v2);
  v7 = spPD.m_pInterface;
  if ( v12 - a2 > 1200.0
    && (_DWORD)spPD.m_pInterface
    && (signed int)_rpInterface >= 0
    && !PlayerDesc::PlayerIsPSR(spPD.m_pInterface) )
  {
    v8 = CPlayerSystem::GetPlayerSystem();
    CPlayerSystem::LogOffCharacter(v8, 0);
  }
  if ( v3->m_bLeaveTargetMode )
  {
    if ( v3->targetMode )
    {
      v3->targetMode = 0;
      v3->m_bLeaveTargetMode = 0;
      if ( ICIDM::s_cidm )
        ((void (__stdcall *)(signed int, IInputActionCallbackVtbl **))ICIDM::s_cidm->vfptr->UnregisterInputMap)(
          268435467,
          &v3->vfptr);
      ClientUISystem::UpdateCursorState(v3);
    }
    v3->m_bLeaveTargetMode = 0;
  }
  if ( v7 )
    v7->vfptr->Release((Interface *)v7);
}

//----- (00565300) --------------------------------------------------------  // acclient.c:402429
PStringBase<char> *__cdecl GenerateMaterialsSalvagedString(PStringBase<char> *result, PackableList<SalvageResult> *resultList)
{
  PackableLLNode<SalvageResult> *v2; // ebp@1
  bool v3; // zf@2
  PlayerModule *v4; // edi@2
  bool v5; // bl@4
  unsigned int v6; // eax@4
  PSRefBufferCharData<char> *v7; // esi@4
  long double v8; // ST14_8@9
  unsigned int v9; // eax@9
  char *v10; // esi@9
  char *v11; // esi@12
  PSRefBufferCharData<char> *v12; // eax@16
  char *v13; // esi@16
  PStringBase<char> v15; // [sp+18h] [bp-Ch]@5
  PStringBase<char> materialName; // [sp+1Ch] [bp-8h]@4
  PStringBase<char> materialList; // [sp+20h] [bp-4h]@1
  char resultLista; // [sp+2Ch] [bp+8h]@1

  v2 = resultList->head;
  resultLista = 1;
  PStringBase<char>::PStringBase<char>(&materialList, &name);
  while ( v2 )
  {
    v3 = v2 == 0;
    v4 = (PlayerModule *)v2;
    if ( v2 )
    {
      v2 = v2->next;
      v3 = v2 == 0;
    }
    v5 = v3;
    PStringBase<char>::allocate_ref_buffer(&materialName, strlen("Unknown"));
    strcpy(materialName.m_charbuffer->m_data, "Unknown");
    v6 = (unsigned int)CInputManager::GetMouseX(v4);
    MaterialTypeEnumMapper::MaterialTypeToString(v6, &materialName);
    v7 = materialName.m_charbuffer;
    if ( resultLista )
    {
      v15.m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1]);
    }
    else if ( v5 )
    {
      PStringBase<char>::PStringBase<char>(&v15, " and ");
    }
    else
    {
      PStringBase<char>::PStringBase<char>(&v15, ", ");
    }
    v8 = PortalSummonSpell::InqDuration((SalvageResult *)v4);
    v9 = PhysicsDesc::get_autonomous_movement((ChatRoomTracker *)v4);
    PStringBase<char>::sprintf_append(&materialList, "%s%d %s (ws %.2lf)", v15.m_charbuffer, v9, v7, v8);
    v10 = &v15.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v15.m_charbuffer[-1]) && v10 )
      (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
    v11 = &materialName.m_charbuffer[-2].m_data[12];
    resultLista = 0;
    if ( !InterlockedDecrement((volatile LONG *)&materialName.m_charbuffer[-1]) && v11 )
      (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
  }
  v12 = materialList.m_charbuffer;
  result->m_charbuffer = materialList.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v12[-1]);
  v13 = &materialList.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&materialList.m_charbuffer[-1]) && v13 )
    (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
  return result;
}

//----- (00565480) --------------------------------------------------------  // acclient.c:402500
PStringBase<unsigned short> *__cdecl GenerateNonSuitablesString(PStringBase<unsigned short> *result, PackableList<unsigned long> *nonSuitables)
{
  unsigned int v2; // eax@1
  PackableLLNode<unsigned long> *v3; // ebp@1
  int v4; // esi@1
  HashBaseData<unsigned long> *v5; // eax@2
  int v6; // ebx@3
  HashBaseData<unsigned long>Vtbl *v7; // esi@5
  char *v8; // esi@12
  unsigned int v9; // eax@16
  PackableList<unsigned long> *v10; // ecx@16
  unsigned int v11; // eax@16
  int v12; // esi@18
  PSRefBufferCharData<unsigned short> *v13; // eax@21
  char *v14; // esi@21
  PStringBase<unsigned short> nonSalvagables; // [sp+Ch] [bp-8h]@1
  int numNotSuitible; // [sp+10h] [bp-4h]@1

  v2 = _wcslen(L" The following were not suitable for salvaging");
  PStringBase<unsigned short>::allocate_ref_buffer(&nonSalvagables, v2);
  _wcscpy(nonSalvagables.m_charbuffer->m_data, L" The following were not suitable for salvaging");
  v3 = nonSuitables->head;
  v4 = 0;
  numNotSuitible = 0;
  if ( !v3 )
    goto LABEL_27;
  do
  {
    v5 = ClientObjMaintSystem::GetWeenieObject(v3->data);
    if ( v5 )
    {
      v6 = (int)L": ";
      if ( v4 )
        v6 = (int)L", ";
      v7 = v5[13].vfptr;
      InterlockedIncrement((volatile LONG *)&v7[1]);
      PStringBase<unsigned short>::sprintf_append(&nonSalvagables, L"%s%hs", v6, &v7[5]);
      if ( !InterlockedDecrement((volatile LONG *)&v7[1]) && v7 )
        (*(void (__thiscall **)(HashBaseData<unsigned long>Vtbl *, signed int))v7->__vecDelDtor)(v7, 1);
      ++numNotSuitible;
      v4 = numNotSuitible;
    }
    v3 = v3->next;
  }
  while ( v3 );
  if ( v4 )
  {
    v9 = _wcslen(L".\n");
    PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)&nonSuitables, v9);
    _wcscpy((wchar_t *)nonSuitables, L".\n");
    v10 = nonSuitables;
    v11 = nonSuitables[-1].curNum;
    if ( v11 != 1 )
    {
      PStringBase<unsigned short>::append_n_chars(&nonSalvagables, (const unsigned __int16 *)nonSuitables, v11 - 1);
      v10 = nonSuitables;
    }
    v12 = (int)&v10[-2].curNum;
    if ( !InterlockedDecrement((volatile LONG *)&v10[-1]) && v12 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  }
  else
  {
LABEL_27:
    if ( (wchar_t *)nonSalvagables.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
    {
      v8 = (char *)&nonSalvagables.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&nonSalvagables.m_charbuffer[-1].m_data[8]) && v8 )
        (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
      nonSalvagables.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    }
  }
  v13 = nonSalvagables.m_charbuffer;
  result->m_charbuffer = nonSalvagables.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v13[-1].m_data[8]);
  v14 = (char *)&nonSalvagables.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&nonSalvagables.m_charbuffer[-1].m_data[8]) && v14 )
    (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
  return result;
}
// 7CE0A4: using guessed type wchar_t asc_7CE0A4[3];
// 7CE0AC: using guessed type wchar_t asc_7CE0AC[3];

//----- (00565620) --------------------------------------------------------  // acclient.c:402585
unsigned int __thiscall ClientUISystem::Handle_Inventory__Recv_SalvageOperationsResultData(ClientUISystem *this, SalvageOperationsResultData *operationsResultData)
{
  int v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1
  SalvageOperationsResultData *v4; // edi@5
  PackableList<SalvageResult> *v5; // eax@6
  unsigned int v6; // eax@6
  int v7; // eax@7
  PSRefBufferCharData<char> *v8; // ebp@8
  char *v9; // esi@8
  AC1Legacy::PSRefBuffer<char> *v10; // esi@11
  PackableList<unsigned long> *v11; // eax@18
  PStringBase<unsigned short> *v12; // eax@18
  char *v13; // esi@18
  char *v14; // esi@23
  char *v15; // esi@26
  AC1Legacy::PStringBase<char> skillName; // [sp+10h] [bp-10h]@1
  ClientSystem *v18; // [sp+14h] [bp-Ch]@1
  PStringBase<unsigned short> msg; // [sp+18h] [bp-8h]@5
  PStringBase<char> materialList; // [sp+1Ch] [bp-4h]@6

  v18 = (ClientSystem *)this;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&skillName, &name);
  v2 = gmCCommunicationSystem::IsSquelched(0, &skillName, 0x19u);
  v3 = skillName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&skillName.m_buffer->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  if ( !v2 )
  {
    msg.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    v4 = operationsResultData;
    if ( SalvageOperationsResultData::GetSalvageResults(operationsResultData)->head )
    {
      v5 = SalvageOperationsResultData::GetSalvageResults(v4);
      GenerateMaterialsSalvagedString(&materialList, v5);
      skillName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      v6 = (unsigned int)CInputManager::GetMouseX((PlayerModule *)v4);
      AppraisalSystem::SkillToString(v6, &skillName);
      operationsResultData = (SalvageOperationsResultData *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      if ( SalvageOperationsResultData::GetAugBonus(v4) )
      {
        v7 = SalvageOperationsResultData::GetAugBonus(v4);
        PStringBase<unsigned short>::sprintf(
          (PStringBase<unsigned short> *)&operationsResultData,
          L" Your augmentation has given you a return bonus of %d%%!",
          v7);
      }
      v8 = materialList.m_charbuffer;
      PStringBase<unsigned short>::sprintf(
        &msg,
        L"You obtain %hs using your knowledge of %hs.%s\n",
        materialList.m_charbuffer,
        skillName.m_buffer->m_data,
        operationsResultData);
      ClientSystem::AddTextToScroll(v18, &msg, 0, 1, 0);
      v9 = (char *)&operationsResultData[-1].m_salvageResults.curNum;
      if ( !InterlockedDecrement((volatile LONG *)&operationsResultData[-1].m_percentReturn) && v9 )
        (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
      v10 = skillName.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&skillName.m_buffer->m_cRef) && v10 )
        v10->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v10, 1u);
      if ( !InterlockedDecrement((volatile LONG *)&v8[-1]) && v8 != (PSRefBufferCharData<char> *)20 )
        (**(void (__thiscall ***)(char *, signed int))&v8[-2].m_data[12])(&v8[-2].m_data[12], 1);
    }
    if ( StructPropertyValue::GetHash((PageData *)v4)[1].m_buffer )
    {
      v11 = (PackableList<unsigned long> *)StructPropertyValue::GetHash((PageData *)v4);
      v12 = GenerateNonSuitablesString((PStringBase<unsigned short> *)&operationsResultData, v11);
      ClientSystem::AddTextToScroll(v18, v12, 0, 1, 0);
      v13 = (char *)&operationsResultData[-1].m_salvageResults.curNum;
      if ( !InterlockedDecrement((volatile LONG *)&operationsResultData[-1].m_percentReturn) )
      {
        if ( v13 )
          (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
      }
    }
    if ( !SalvageOperationsResultData::GetSalvageResults(v4)->head
      && !StructPropertyValue::GetHash((PageData *)v4)[1].m_buffer )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&operationsResultData,
        L"Salvaging Failed!\n");
      ClientSystem::AddTextToScroll(v18, (PStringBase<unsigned short> *)&operationsResultData, 0, 1, 0);
      v14 = (char *)&operationsResultData[-1].m_salvageResults.curNum;
      if ( !InterlockedDecrement((volatile LONG *)&operationsResultData[-1].m_percentReturn) )
      {
        if ( v14 )
          (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
      }
    }
    v15 = (char *)&msg.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1].m_data[8]) && v15 )
      (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
  }
  return 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00565870) --------------------------------------------------------  // acclient.c:402687
void __thiscall ClientUISystem::OnViewContents(ClientUISystem *this, unsigned int obj, PackableList<ContentProfile> *contents)
{
  InterfaceSystem *v3; // eax@1
  Interface *v4; // esi@1
  ClientObjMaintSystem *v5; // ebx@5
  HashBaseData<unsigned long> *v6; // eax@7
  int v7; // [sp-8h] [bp-30h]@1
  Interface *_rpInterface; // [sp+10h] [bp-18h]@1
  ClientUISystem *v9; // [sp+14h] [bp-14h]@1
  TResult result; // [sp+18h] [bp-10h]@1
  char v11; // [sp+1Ch] [bp-Ch]@3
  InterfacePtr<ClientObjMaintSystem> spObjMaint; // [sp+20h] [bp-8h]@1

  v9 = this;
  _rpInterface = 0;
  v3 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v3, &result, &ClientObjMaintSystem_ClassType_4, &_rpInterface);
  v7 = (int)_rpInterface;
  v4 = _rpInterface;
  spObjMaint.m_pInterface = 0;
  spObjMaint.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  _rpInterface = *(Interface **)InterfacePtr<ClientObjMaintSystem>::_QueryInterface(&spObjMaint, (int)&v11, v7, 0);
  if ( v4 )
    v4->vfptr->Release(v4);
  v5 = spObjMaint.m_pInterface;
  if ( (_DWORD)spObjMaint.m_pInterface )
  {
    if ( (signed int)_rpInterface >= 0 )
    {
      ACCObjectMaint::ViewObjectContents((ACCObjectMaint *)&spObjMaint.m_pInterface->vfptr, obj, contents);
      v6 = CObjectMaint::GetWeenieObject((CObjectMaint *)&v5->vfptr, obj);
      if ( v6 )
        ACCWeenieObject::RemoveContentsFromDestructionQueue((ACCWeenieObject *)v6);
    }
  }
  if ( obj == v9->requestedGroundObject
    && (obj != ACCWeenieObject::prevRequestObjectID || ACCWeenieObject::prevRequest != 4) )
  {
    CM_Item::SendNotice_SetGroundObject(v9->requestedGroundObject);
    ACCWeenieObject::RecordResponse(obj);
  }
  if ( v5 )
    v5->vfptr->Release((Interface *)v5);
}
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;
// 870EC4: using guessed type unsigned __int32 ACCWeenieObject::prevRequestObjectID;

//----- (00565960) --------------------------------------------------------  // acclient.c:402737
void __cdecl ClientUISystem::TargetedUsageCallback(PropertyCollection *i_rcResults)
{
  PropertyCollection *v1; // esi@1
  unsigned int v2; // edx@1
  HashTableData<unsigned long,BaseProperty> **v3; // eax@1
  HashTableData<unsigned long,BaseProperty> *v4; // eax@1
  BasePropertyValue *v5; // ecx@6
  unsigned int v6; // edx@9
  HashTableData<unsigned long,BaseProperty> **v7; // eax@9
  HashTableData<unsigned long,BaseProperty> *v8; // eax@9
  unsigned int v9; // edx@16
  HashTableData<unsigned long,BaseProperty> **v10; // eax@16
  HashTableData<unsigned long,BaseProperty> *v11; // eax@16
  ClientUISystem *v12; // ecx@25
  unsigned int v13; // edx@25
  unsigned int v14; // ST00_4@27
  CPlayerSystem *v15; // eax@27
  BasePropertyDesc *v16; // ecx@29
  unsigned int v17; // edx@29
  int v18; // edx@33
  int v19; // [sp+8h] [bp-10h]@1
  unsigned int targetID; // [sp+Ch] [bp-Ch]@16
  BaseProperty p; // [sp+10h] [bp-8h]@1

  v1 = i_rcResults;
  v2 = 0x92 % i_rcResults->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v3 = i_rcResults->m_hashProperties.m_intrusiveTable.m_buckets;
  BYTE3(v19) = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v4 = v3[v2];
  if ( v4 )
  {
    while ( v4->m_hashKey != 146 )
    {
      v4 = v4->m_hashNext;
      if ( !v4 )
        return;
    }
    if ( v4 )
    {
      BaseProperty::operator=(&p, (int)&v4->m_data);
      v5 = p.m_pcPropertyValue;
      if ( p.m_pcPropertyValue )
      {
        ((void (__stdcall *)(char *))p.m_pcPropertyValue->vfptr[28].__vecDelDtor)((char *)&v19 + 3);
        v5 = p.m_pcPropertyValue;
      }
      if ( BYTE3(v19) )
      {
        v6 = 0x1000003D % v1->m_hashProperties.m_intrusiveTable.m_numBuckets;
        v7 = v1->m_hashProperties.m_intrusiveTable.m_buckets;
        i_rcResults = 0;
        v8 = v7[v6];
        if ( v8 )
        {
          while ( v8->m_hashKey != 268435517 )
          {
            v8 = v8->m_hashNext;
            if ( !v8 )
              goto LABEL_16;
          }
          if ( v8 )
          {
            BaseProperty::operator=(&p, (int)&v8->m_data);
            v5 = p.m_pcPropertyValue;
            if ( p.m_pcPropertyValue )
            {
              ((void (__stdcall *)(PropertyCollection **))p.m_pcPropertyValue->vfptr[50].__vecDelDtor)(&i_rcResults);
              v5 = p.m_pcPropertyValue;
            }
          }
        }
LABEL_16:
        v9 = 0x1000003E % v1->m_hashProperties.m_intrusiveTable.m_numBuckets;
        v10 = v1->m_hashProperties.m_intrusiveTable.m_buckets;
        targetID = 0;
        v11 = v10[v9];
        if ( v11 )
        {
          while ( v11->m_hashKey != 268435518 )
          {
            v11 = v11->m_hashNext;
            if ( !v11 )
              goto LABEL_23;
          }
          if ( v11 )
          {
            BaseProperty::operator=(&p, (int)&v11->m_data);
            v5 = p.m_pcPropertyValue;
            if ( p.m_pcPropertyValue )
            {
              ((void (__stdcall *)(unsigned int *))p.m_pcPropertyValue->vfptr[50].__vecDelDtor)(&targetID);
              v5 = p.m_pcPropertyValue;
            }
          }
        }
LABEL_23:
        if ( i_rcResults && targetID )
        {
          CM_Inventory::Event_UseWithTargetEvent((unsigned int)i_rcResults, targetID);
          v12 = ClientUISystem::s_pUISystem;
          v13 = ClientUISystem::s_pUISystem->m_cBusy + 1;
          ClientUISystem::s_pUISystem->m_cBusy = v13;
          if ( v13 == 1 )
            ClientUISystem::UpdateCursorState(v12);
          v14 = (unsigned int)i_rcResults;
          v15 = CPlayerSystem::GetPlayerSystem();
          CPlayerSystem::UsingItem(v15, v14, 1, 0);
          v5 = p.m_pcPropertyValue;
        }
      }
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v16 = p.m_pcPropertyDesc;
        v17 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v17;
        if ( !v17 )
          ((void (__stdcall *)(signed int))v16->vfptr->__vecDelDtor)(1);
        v5 = p.m_pcPropertyValue;
        p.m_pcPropertyDesc = 0;
      }
      if ( v5 )
      {
        v18 = v5->m_cRef - 1;
        v5->m_cRef = v18;
        if ( !v18 )
          ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
      }
    }
  }
}

//----- (00565B20) --------------------------------------------------------  // acclient.c:402871
void __cdecl ClientUISystem::UsageCallback(PropertyCollection *i_rcResults)
{
  PropertyCollection *v1; // esi@1
  unsigned int v2; // edx@1
  HashTableData<unsigned long,BaseProperty> **v3; // eax@1
  HashTableData<unsigned long,BaseProperty> *v4; // eax@1
  BasePropertyValue *v5; // ecx@6
  unsigned int v6; // edx@9
  HashTableData<unsigned long,BaseProperty> **v7; // ecx@9
  HashTableData<unsigned long,BaseProperty> *v8; // eax@9
  ClientUISystem *v9; // ecx@16
  unsigned int v10; // esi@16
  unsigned int v11; // ST08_4@18
  CPlayerSystem *v12; // eax@18
  HashBaseData<unsigned long> *v13; // eax@18
  PStringBase<unsigned short> *v14; // eax@19
  char *v15; // esi@19
  char *v16; // esi@22
  BasePropertyDesc *v17; // ecx@27
  unsigned int v18; // edx@27
  int v19; // edx@31
  int v20; // [sp+8h] [bp-14h]@1
  PStringBase<unsigned short> errorText; // [sp+Ch] [bp-10h]@19
  PStringBase<unsigned short> result; // [sp+10h] [bp-Ch]@19
  BaseProperty p; // [sp+14h] [bp-8h]@1

  v1 = i_rcResults;
  v2 = 0x92 % i_rcResults->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v3 = i_rcResults->m_hashProperties.m_intrusiveTable.m_buckets;
  BYTE3(v20) = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v4 = v3[v2];
  if ( v4 )
  {
    while ( v4->m_hashKey != 146 )
    {
      v4 = v4->m_hashNext;
      if ( !v4 )
        return;
    }
    if ( v4 )
    {
      BaseProperty::operator=(&p, (int)&v4->m_data);
      v5 = p.m_pcPropertyValue;
      if ( p.m_pcPropertyValue )
      {
        ((void (__stdcall *)(char *))p.m_pcPropertyValue->vfptr[28].__vecDelDtor)((char *)&v20 + 3);
        v5 = p.m_pcPropertyValue;
      }
      if ( BYTE3(v20) )
      {
        v6 = 0x1000003D % v1->m_hashProperties.m_intrusiveTable.m_numBuckets;
        v7 = v1->m_hashProperties.m_intrusiveTable.m_buckets;
        i_rcResults = 0;
        v8 = v7[v6];
        if ( v8 )
        {
          while ( v8->m_hashKey != 268435517 )
          {
            v8 = v8->m_hashNext;
            if ( !v8 )
              goto LABEL_16;
          }
          if ( v8 )
          {
            BaseProperty::operator=(&p, (int)&v8->m_data);
            if ( p.m_pcPropertyValue )
              ((void (__stdcall *)(PropertyCollection **))p.m_pcPropertyValue->vfptr[50].__vecDelDtor)(&i_rcResults);
          }
        }
LABEL_16:
        CM_Inventory::Event_UseEvent((unsigned int)i_rcResults);
        v9 = ClientUISystem::s_pUISystem;
        v10 = ClientUISystem::s_pUISystem->m_cBusy + 1;
        ClientUISystem::s_pUISystem->m_cBusy = v10;
        if ( v10 == 1 )
          ClientUISystem::UpdateCursorState(v9);
        v11 = (unsigned int)i_rcResults;
        v12 = CPlayerSystem::GetPlayerSystem();
        CPlayerSystem::UsingItem(v12, v11, 1, 0);
        v13 = ClientObjMaintSystem::GetWeenieObject((unsigned int)i_rcResults);
        if ( v13 )
        {
          v14 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v13, &result, NAME_APPROPRIATE, 0);
          PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"Using the %s", v14->m_charbuffer);
          v15 = (char *)&result.m_charbuffer[-1].m_data[6];
          if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v15 )
            (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
          ClientSystem::AddTextToScroll((ClientSystem *)&ClientUISystem::s_pUISystem->vfptr, &errorText, 0x1Au, 1, 0);
          v16 = (char *)&errorText.m_charbuffer[-1].m_data[6];
          if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) && v16 )
            (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
        }
        v5 = p.m_pcPropertyValue;
      }
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v17 = p.m_pcPropertyDesc;
        v18 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v18;
        if ( !v18 )
          ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
        v5 = p.m_pcPropertyValue;
        p.m_pcPropertyDesc = 0;
      }
      if ( v5 )
      {
        v19 = v5->m_cRef - 1;
        v5->m_cRef = v19;
        if ( !v19 )
          ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
      }
    }
  }
}

//----- (00565D10) --------------------------------------------------------  // acclient.c:402989
void __thiscall ClientUISystem::Handle_VendorInfo(ClientUISystem *this, void *buff, unsigned int size)
{
  unsigned int v3; // edi@1
  ClientUISystem *v4; // esi@1
  char *v5; // ebx@1
  int v6; // edx@1
  AC1Legacy::PSRefBuffer<char> *v7; // esi@4
  PackableList<ItemProfile> itemProfileList; // [sp+10h] [bp-38h]@1
  VendorProfile vendorProfile; // [sp+20h] [bp-28h]@1

  v3 = *(_DWORD *)buff;
  v4 = this;
  v5 = (char *)buff + size + 4;
  buff = (char *)buff + 4;
  VendorProfile::VendorProfile(&vendorProfile);
  VendorProfile::UnPack(&vendorProfile, &buff, v5 - (_BYTE *)buff);
  itemProfileList.vfptr = (PackObjVtbl *)&PackableList<ItemProfile>::vftable;
  itemProfileList.head = 0;
  itemProfileList.tail = 0;
  itemProfileList.curNum = 0;
  PackableList<ItemProfile>::UnPack(&itemProfileList, &buff, v5 - (_BYTE *)buff);
  ClientUISystem::SetGroundObject(v4, 0, 1);
  v6 = v3 == v4->attemptOpenVendorID;
  v4->vendorID = v3;
  CM_Vendor::SendNotice_OpenVendor(v3, &vendorProfile, &itemProfileList, (ShopMode)(v6 + 2));
  if ( v3 == v4->attemptOpenVendorID && v4->attemptSaleObjectID )
    CM_Vendor::SendNotice_AddItemToSell(v4->attemptSaleObjectID);
  v4->attemptOpenVendorID = 0;
  v4->attemptSaleObjectID = 0;
  itemProfileList.vfptr = (PackObjVtbl *)&PackableList<ItemProfile>::vftable;
  PackableList<ItemProfile>::Flush(&itemProfileList);
  v7 = vendorProfile.trade_name.m_buffer;
  itemProfileList.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&vendorProfile.trade_name.m_buffer->m_cRef) )
  {
    if ( v7 )
      v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7B4FA8: using guessed type int (__thiscall *PackableList<ItemProfile>::vftable)(void *, char);

//----- (00565E10) --------------------------------------------------------  // acclient.c:403032
char __cdecl ClientUISystem::DeltaTimeToString(const long double time, PStringBase<unsigned short> *dst)
{
  unsigned int v2; // ecx@1
  unsigned int v3; // edi@1
  unsigned int v4; // ett@1
  unsigned int v5; // ebp@1
  char *v6; // esi@1
  const unsigned __int16 **v7; // eax@9
  const unsigned __int16 *v8; // eax@9
  int v9; // ecx@9
  char *v10; // esi@11
  PStringBase<unsigned short> v12; // [sp+0h] [bp-408h]@1
  unsigned int v13; // [sp+4h] [bp-404h]@1
  char buf[1024]; // [sp+8h] [bp-400h]@1
  void *retaddr; // [sp+408h] [bp+0h]@4

  v2 = (unsigned int)(unsigned __int64)time / 0x278D00;
  v3 = (unsigned int)(unsigned __int64)time % 0x278D00 / 0x15180;
  v4 = (unsigned int)(unsigned __int64)time % 0x278D00 % 0x15180;
  v5 = v4 / 0xE10;
  v4 %= 0xE10u;
  v6 = buf;
  v12.m_charbuffer = (PSRefBufferCharData<unsigned short> *)(v4 % 0x3C);
  v13 = v4 / 0x3C;
  if ( v2 )
    v6 = &buf[__snprintf(buf, 0x400u, "%dmo ", v2)];
  if ( v3 )
    v6 += __snprintf(v6, (char *)&retaddr - v6, "%dd ", v3);
  if ( v5 )
    v6 += __snprintf(v6, (char *)&retaddr - v6, "%dh ", v5);
  if ( v13 )
    v6 += __snprintf(v6, (char *)&retaddr - v6, "%dm ", v13);
  __snprintf(v6, (char *)&retaddr - v6, "%ds ", v12.m_charbuffer);
  *((_BYTE *)&v13 + strlen(buf) + 3) = 0;
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v12, 0, buf);
  v8 = *v7;
  v9 = *((_DWORD *)v8 - 1);
  if ( v9 != 1 )
    PStringBase<unsigned short>::append_n_chars(dst, v8, v9 - 1);
  v10 = (char *)&v12.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v12.m_charbuffer[-1].m_data[8]) && v10 )
    (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  return 1;
}

//----- (00565F70) --------------------------------------------------------  // acclient.c:403078
const char *__thiscall AC1Legacy::PStringBase<char>::replace(AC1Legacy::PStringBase<char> *this, AC1Legacy::PStringBase<char> *search, AC1Legacy::PStringBase<char> *str)
{
  AC1Legacy::PStringBase<char> *v3; // ebp@1
  void **v4; // edi@1
  const char *v5; // ST10_4@1
  const char *v6; // ST0C_4@1
  char *v7; // esi@1
  int v8; // eax@8
  const char *result; // eax@11
  int v10; // edi@12
  unsigned int v11; // ST10_4@12
  int v12; // esi@12
  int v13; // ebx@12
  size_t v14; // edi@13
  char *v15; // esi@13
  int v16; // esi@15
  const char v17; // al@16
  unsigned int c; // [sp+10h] [bp-18h]@12
  const char *p; // [sp+14h] [bp-14h]@1
  int v20; // [sp+18h] [bp-10h]@12
  _STL::vector<char const *,_STL::allocator<char const *> > matches; // [sp+1Ch] [bp-Ch]@1

  v3 = this;
  v4 = 0;
  v5 = search->m_buffer->m_data;
  v6 = this->m_buffer->m_data;
  matches._M_start = 0;
  matches._M_finish = 0;
  matches._M_end_of_storage._M_data = 0;
  v7 = _strstr(v6, v5);
  for ( p = v7; v7; p = v7 )
  {
    if ( v4 == (void **)matches._M_end_of_storage._M_data )
    {
      _STL::vector<char const *,_STL::allocator<char const *>>::_M_insert_overflow(
        (_STL::vector<void *,_STL::allocator<void *> > *)&matches,
        v4,
        (void *const *)&p,
        (_STL::__true_type *)&str,
        1u,
        1);
      v4 = (void **)matches._M_finish;
    }
    else
    {
      if ( v4 )
        *v4 = v7;
      ++v4;
      matches._M_finish = (const char **)v4;
    }
    v7 = _strstr(&v7[search->m_buffer->m_len - 1], search->m_buffer->m_data);
  }
  v8 = (signed int)((char *)v4 - (char *)matches._M_start) >> 2;
  p = (const char *)((signed int)((char *)v4 - (char *)matches._M_start) >> 2);
  if ( v8 )
  {
    v11 = v8 * (str->m_buffer->m_len - search->m_buffer->m_len) + v3->m_buffer->m_len - 1;
    v20 = (int)v3->m_buffer;
    v10 = v20;
    AC1Legacy::PStringBase<char>::allocate_ref_buffer(v3, v11);
    v12 = (int)v3->m_buffer->m_data;
    v13 = v10 + 20;
    c = 0;
    if ( p )
    {
      do
      {
        v14 = (size_t)&matches._M_start[c][-v13];
        _strncpy((char *)v12, (const char *)v13, v14);
        v15 = (char *)(v14 + v12);
        strcpy(v15, str->m_buffer->m_data);
        v12 = (int)&v15[str->m_buffer->m_len - 1];
        v13 = v13 + v14 + search->m_buffer->m_len - 1;
        ++c;
      }
      while ( c < (unsigned int)p );
      v10 = v20;
    }
    v16 = v12 - v13;
    do
    {
      v17 = *(_BYTE *)v13;
      *(_BYTE *)(v16 + v13) = *(_BYTE *)v13;
      ++v13;
    }
    while ( v17 );
    if ( !InterlockedDecrement((volatile LONG *)(v10 + 4)) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    if ( (_DWORD)matches._M_start )
      _STL::__node_alloc<1,0>::deallocate(matches._M_start, 4 * (matches._M_end_of_storage._M_data - matches._M_start));
    result = p;
  }
  else
  {
    if ( (_DWORD)matches._M_start )
      _STL::__node_alloc<1,0>::deallocate(matches._M_start, 4 * (matches._M_end_of_storage._M_data - matches._M_start));
    result = 0;
  }
  return result;
}

//----- (00566140) --------------------------------------------------------  // acclient.c:403180
char __stdcall ClientUISystem::TargetedUsageConfirmation_ManaStone(unsigned int toolID, unsigned int targetID)
{
  HashBaseData<unsigned long> *v3; // esi@1
  HashBaseData<unsigned long>Vtbl *v4; // esi@1
  void *(__thiscall *v5)(HashBaseData<unsigned long> *, unsigned int); // eax@1
  AC1Legacy::PSRefBuffer<char> *v6; // esi@6
  unsigned int v7; // eax@6
  AC1Legacy::PSRefBuffer<char> *v8; // edi@11
  PStringBase<unsigned short> *v9; // eax@11
  char *v10; // esi@11
  BasePropertyDesc *v11; // ecx@23
  unsigned int v12; // edx@23
  BasePropertyValue *v13; // ecx@27
  unsigned int v14; // esi@27
  BaseProperty p; // [sp+20h] [bp-118h]@14
  AC1Legacy::PStringBase<char> v17; // [sp+28h] [bp-110h]@6
  AC1Legacy::PStringBase<char> msg; // [sp+2Ch] [bp-10Ch]@1
  PropertyCollection pc; // [sp+30h] [bp-108h]@14
  StringInfo v20; // [sp+A8h] [bp-90h]@11

  v3 = ClientObjMaintSystem::GetWeenieObject(targetID);
  AC1Legacy::PStringBase<char>::PStringBase<char>(&msg, "\nAre you sure you want to attempt to destroy your ");
  v4 = v3[13].vfptr;
  InterlockedIncrement((volatile LONG *)&v4[1]);
  v5 = v4[2].__vecDelDtor;
  if ( v5 != (void *(__thiscall *)(HashBaseData<unsigned long> *, unsigned int))1
    && v4 != (HashBaseData<unsigned long>Vtbl *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(&msg, (const char *)&v4[5], (unsigned int)((char *)v5 - 1));
  if ( !InterlockedDecrement((volatile LONG *)&v4[1]) )
    (*(void (__thiscall **)(HashBaseData<unsigned long>Vtbl *, signed int))v4->__vecDelDtor)(v4, 1);
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v17, " and drain its mana into this stone?");
  v6 = v17.m_buffer;
  v7 = v17.m_buffer->m_len;
  if ( v7 != 1 && v17.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(&msg, v17.m_buffer->m_data, v7 - 1);
  if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) )
    v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
  StringInfo::StringInfo(&v20);
  v8 = msg.m_buffer;
  PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&v17, 0, msg.m_buffer->m_data);
  StringInfo::SetLiteralValue(&v20, v9, 1);
  v10 = (char *)&v17.m_buffer[-1].m_cRef;
  if ( !InterlockedDecrement((volatile LONG *)&v17.m_buffer[-1].m_cRef + 1) && v10 )
    (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  PropertyCollection::PropertyCollection(&pc);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x8Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
  }
  v17.m_buffer = (AC1Legacy::PSRefBuffer<char> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&v17,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC5u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(StringInfo *))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&v20);
  }
  v17.m_buffer = (AC1Legacy::PSRefBuffer<char> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&v17,
    &p);
  BaseProperty::SetPropertyName(&p, 0x1000003Du);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(unsigned int))p.m_pcPropertyValue->vfptr[51].__vecDelDtor)(toolID);
  }
  v17.m_buffer = (AC1Legacy::PSRefBuffer<char> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&v17,
    &p);
  BaseProperty::SetPropertyName(&p, 0x1000003Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(unsigned int))p.m_pcPropertyValue->vfptr[51].__vecDelDtor)(targetID);
  }
  v17.m_buffer = (AC1Legacy::PSRefBuffer<char> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&v17,
    &p);
  DialogFactory::MakeCallbackDialogInCurrentUI(&pc, ClientUISystem::TargetedUsageCallback);
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v11 = p.m_pcPropertyDesc;
    v12 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v12;
    if ( !v12 )
      ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v13 = p.m_pcPropertyValue;
    v14 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v14;
    if ( !v14 )
      ((void (__stdcall *)(signed int))v13->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&pc);
  StringInfo::~StringInfo(&v20);
  if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) && v8 )
    v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00566420) --------------------------------------------------------  // acclient.c:403299
char __stdcall ClientUISystem::UsageConfirmation_PKAltar(unsigned int altarID)
{
  unsigned int v2; // eax@1
  char *v3; // esi@1
  BasePropertyDesc *v4; // ecx@11
  unsigned int v5; // edx@11
  BasePropertyValue *v6; // ecx@15
  unsigned int v7; // esi@15
  BaseProperty p; // [sp+14h] [bp-114h]@4
  PStringBase<unsigned short> _value; // [sp+1Ch] [bp-10Ch]@1
  PropertyCollection pc; // [sp+20h] [bp-108h]@4
  StringInfo v12; // [sp+98h] [bp-90h]@1

  StringInfo::StringInfo(&v12);
  v2 = _wcslen(L"Using this altar will make you a player killer, able to attack or be attacked by other player killers. Are you sure you want to do this?");
  PStringBase<unsigned short>::allocate_ref_buffer(&_value, v2);
  _wcscpy(
    _value.m_charbuffer->m_data,
    L"Using this altar will make you a player killer, able to attack or be attacked by other player killers. Are you sure you want to do this?");
  StringInfo::SetLiteralValue(&v12, &_value, 1);
  v3 = (char *)&_value.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  PropertyCollection::PropertyCollection(&pc);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x8Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
  }
  _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&_value,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC5u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&v12);
  }
  _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&_value,
    &p);
  BaseProperty::SetPropertyName(&p, 0x1000003Du);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[51].__vecDelDtor)(altarID);
  }
  _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&_value,
    &p);
  DialogFactory::MakeCallbackDialogInCurrentUI(&pc, ClientUISystem::UsageCallback);
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v4 = p.m_pcPropertyDesc;
    v5 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v6 = p.m_pcPropertyValue;
    v7 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&pc);
  StringInfo::~StringInfo(&v12);
  return 1;
}

//----- (00566610) --------------------------------------------------------  // acclient.c:403383
char __stdcall ClientUISystem::UsageConfirmation_NPKAltar(unsigned int altarID)
{
  unsigned int v2; // eax@1
  char *v3; // esi@1
  BasePropertyDesc *v4; // ecx@11
  unsigned int v5; // edx@11
  BasePropertyValue *v6; // ecx@15
  unsigned int v7; // esi@15
  BaseProperty p; // [sp+14h] [bp-114h]@4
  PStringBase<unsigned short> _value; // [sp+1Ch] [bp-10Ch]@1
  PropertyCollection pc; // [sp+20h] [bp-108h]@4
  StringInfo v12; // [sp+98h] [bp-90h]@1

  StringInfo::StringInfo(&v12);
  v2 = _wcslen(L"Using this altar will make you a non-player killer, unable to attack or be attacked by other player killers. Are you sure you want to do this?");
  PStringBase<unsigned short>::allocate_ref_buffer(&_value, v2);
  _wcscpy(
    _value.m_charbuffer->m_data,
    L"Using this altar will make you a non-player killer, unable to attack or be attacked by other player killers. Are you sure you want to do this?");
  StringInfo::SetLiteralValue(&v12, &_value, 1);
  v3 = (char *)&_value.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  PropertyCollection::PropertyCollection(&pc);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x8Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
  }
  _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&_value,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC5u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&v12);
  }
  _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&_value,
    &p);
  BaseProperty::SetPropertyName(&p, 0x1000003Du);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[51].__vecDelDtor)(altarID);
  }
  _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&_value,
    &p);
  DialogFactory::MakeCallbackDialogInCurrentUI(&pc, ClientUISystem::UsageCallback);
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v4 = p.m_pcPropertyDesc;
    v5 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v6 = p.m_pcPropertyValue;
    v7 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&pc);
  StringInfo::~StringInfo(&v12);
  return 1;
}

//----- (00566800) --------------------------------------------------------  // acclient.c:403467
char __stdcall ClientUISystem::UsageConfirmation_VolatileRare(unsigned int rareID)
{
  unsigned int v2; // eax@1
  char *v3; // esi@1
  BasePropertyDesc *v4; // ecx@11
  unsigned int v5; // edx@11
  BasePropertyValue *v6; // ecx@15
  unsigned int v7; // esi@15
  BaseProperty p; // [sp+14h] [bp-114h]@4
  PStringBase<unsigned short> _value; // [sp+1Ch] [bp-10Ch]@1
  PropertyCollection pc; // [sp+20h] [bp-108h]@4
  StringInfo v12; // [sp+98h] [bp-90h]@1

  StringInfo::StringInfo(&v12);
  v2 = _wcslen(L"Are you sure you want to use this rare item?");
  PStringBase<unsigned short>::allocate_ref_buffer(&_value, v2);
  _wcscpy(_value.m_charbuffer->m_data, L"Are you sure you want to use this rare item?");
  StringInfo::SetLiteralValue(&v12, &_value, 1);
  v3 = (char *)&_value.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  PropertyCollection::PropertyCollection(&pc);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x8Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
  }
  _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&_value,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC5u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&v12);
  }
  _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&_value,
    &p);
  BaseProperty::SetPropertyName(&p, 0x1000003Du);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[51].__vecDelDtor)(rareID);
  }
  _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&_value,
    &p);
  DialogFactory::MakeCallbackDialogInCurrentUI(&pc, ClientUISystem::UsageCallback);
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v4 = p.m_pcPropertyDesc;
    v5 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v6 = p.m_pcPropertyValue;
    v7 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&pc);
  StringInfo::~StringInfo(&v12);
  return 1;
}

//----- (005669F0) --------------------------------------------------------  // acclient.c:403549
char __stdcall ClientUISystem::TargetedUsageConfirmation_Salvage(unsigned int toolID, unsigned int targetID)
{
  HashBaseData<unsigned long> *v3; // esi@1
  HashBaseData<unsigned long> *v4; // eax@1
  HashBaseData<unsigned long> *v5; // edi@1
  AC1Legacy::PSRefBuffer<char> *v6; // ebx@1
  AC1Legacy::PStringBase<char> *v7; // eax@4
  AC1Legacy::PStringBase<char> *v8; // eax@4
  AC1Legacy::PStringBase<char> *v9; // eax@4
  AC1Legacy::PStringBase<char> *v10; // eax@4
  AC1Legacy::PSRefBuffer<char> *v11; // eax@4
  unsigned int v12; // ecx@4
  AC1Legacy::PSRefBuffer<char> *v13; // esi@7
  AC1Legacy::PSRefBuffer<char> *v14; // esi@10
  AC1Legacy::PSRefBuffer<char> *v15; // esi@13
  AC1Legacy::PSRefBuffer<char> *v16; // esi@16
  AC1Legacy::PSRefBuffer<char> *v17; // esi@19
  AC1Legacy::PSRefBuffer<char> *v18; // esi@22
  AC1Legacy::PSRefBuffer<char> *v19; // esi@25
  AC1Legacy::PSRefBuffer<char> *v20; // esi@28
  AC1Legacy::PSRefBuffer<char> *v21; // ebx@31
  PStringBase<unsigned short> *v22; // eax@31
  char *v23; // esi@31
  BasePropertyDesc *v24; // ecx@43
  unsigned int v25; // edx@43
  BasePropertyValue *v26; // ecx@47
  unsigned int v27; // edx@47
  AC1Legacy::PSRefBuffer<char> *v28; // esi@56
  BaseProperty p; // [sp+3Ch] [bp-13Ch]@34
  AC1Legacy::PStringBase<char> result; // [sp+44h] [bp-134h]@4
  AC1Legacy::PStringBase<char> target; // [sp+48h] [bp-130h]@1
  AC1Legacy::PStringBase<char> material; // [sp+4Ch] [bp-12Ch]@1
  AC1Legacy::PStringBase<char> v34; // [sp+50h] [bp-128h]@4
  AC1Legacy::PStringBase<char> rhs; // [sp+54h] [bp-124h]@4
  AC1Legacy::PStringBase<char> msg; // [sp+58h] [bp-120h]@4
  AC1Legacy::PStringBase<char> v37; // [sp+5Ch] [bp-11Ch]@4
  AC1Legacy::PStringBase<char> v38; // [sp+60h] [bp-118h]@4
  AC1Legacy::PStringBase<char> v39; // [sp+64h] [bp-114h]@4
  AC1Legacy::PStringBase<char> v40; // [sp+68h] [bp-110h]@4
  AC1Legacy::PStringBase<char> v41; // [sp+6Ch] [bp-10Ch]@4
  PropertyCollection pc; // [sp+70h] [bp-108h]@34
  StringInfo v43; // [sp+E8h] [bp-90h]@31

  v3 = ClientObjMaintSystem::GetWeenieObject(toolID);
  v4 = ClientObjMaintSystem::GetWeenieObject(targetID);
  material.m_buffer = (AC1Legacy::PSRefBuffer<char> *)v3[13].vfptr;
  v5 = v4;
  InterlockedIncrement((volatile LONG *)&material.m_buffer->m_cRef);
  AC1Legacy::PStringBase<char>::PStringBase<char>(&target, " (100)");
  AC1Legacy::PStringBase<char>::replace(&material, &target, &AC1Legacy::PStringBase<char>::null_string);
  v6 = target.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&target.m_buffer->m_cRef) && v6 )
    v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
  target.m_buffer = (AC1Legacy::PSRefBuffer<char> *)v5[13].vfptr;
  InterlockedIncrement((volatile LONG *)&target.m_buffer->m_cRef);
  AC1Legacy::PStringBase<char>::PStringBase<char>(&msg, "\nAre you sure you want to apply the ");
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v37, " may be destroyed.");
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v34, "? The ");
  AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, " to the ");
  v7 = AC1Legacy::PStringBase<char>::operator+(&material, &result, &rhs);
  v8 = AC1Legacy::PStringBase<char>::operator+(v7, &v40, &target);
  v9 = AC1Legacy::PStringBase<char>::operator+(v8, &v39, &v34);
  v10 = AC1Legacy::PStringBase<char>::operator+(v9, &v41, &target);
  v11 = AC1Legacy::PStringBase<char>::operator+(v10, &v38, &v37)->m_buffer;
  v12 = v11->m_len;
  if ( v12 != 1 && v11 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(&msg, v11->m_data, v12 - 1);
  v13 = v38.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v38.m_buffer->m_cRef) && v13 )
    v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
  v14 = v41.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v41.m_buffer->m_cRef) && v14 )
    v14->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v14, 1u);
  v15 = v39.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v39.m_buffer->m_cRef) && v15 )
    v15->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v15, 1u);
  v16 = v40.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v40.m_buffer->m_cRef) && v16 )
    v16->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v16, 1u);
  v17 = result.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v17 )
    v17->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v17, 1u);
  v18 = rhs.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&rhs.m_buffer->m_cRef) && v18 )
    v18->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v18, 1u);
  v19 = v34.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v34.m_buffer->m_cRef) && v19 )
    v19->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v19, 1u);
  v20 = v37.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v37.m_buffer->m_cRef) && v20 )
    v20->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v20, 1u);
  StringInfo::StringInfo(&v43);
  v21 = msg.m_buffer;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&result,
    0,
    msg.m_buffer->m_data);
  StringInfo::SetLiteralValue(&v43, v22, 1);
  v23 = (char *)&result.m_buffer[-1].m_cRef;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer[-1].m_cRef + 1) && v23 )
    (**(void (__thiscall ***)(char *, signed int))v23)(v23, 1);
  PropertyCollection::PropertyCollection(&pc);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x8Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
  }
  result.m_buffer = (AC1Legacy::PSRefBuffer<char> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&result,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC5u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(StringInfo *))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&v43);
  }
  result.m_buffer = (AC1Legacy::PSRefBuffer<char> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&result,
    &p);
  BaseProperty::SetPropertyName(&p, 0x1000003Du);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(unsigned int))p.m_pcPropertyValue->vfptr[51].__vecDelDtor)(toolID);
  }
  result.m_buffer = (AC1Legacy::PSRefBuffer<char> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&result,
    &p);
  BaseProperty::SetPropertyName(&p, 0x1000003Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(unsigned int))p.m_pcPropertyValue->vfptr[51].__vecDelDtor)(targetID);
  }
  result.m_buffer = (AC1Legacy::PSRefBuffer<char> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&result,
    &p);
  DialogFactory::MakeCallbackDialogInCurrentUI(&pc, ClientUISystem::TargetedUsageCallback);
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v24 = p.m_pcPropertyDesc;
    v25 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v25;
    if ( !v25 )
      ((void (__stdcall *)(signed int))v24->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v26 = p.m_pcPropertyValue;
    v27 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v27;
    if ( !v27 )
      ((void (__stdcall *)(signed int))v26->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&pc);
  StringInfo::~StringInfo(&v43);
  if ( !InterlockedDecrement((volatile LONG *)&v21->m_cRef) && v21 )
    v21->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v21, 1u);
  if ( !InterlockedDecrement((volatile LONG *)&target.m_buffer->m_cRef) && target.m_buffer )
    ((void (__stdcall *)(signed int))target.m_buffer->vfptr->__vecDelDtor)(1);
  v28 = material.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&material.m_buffer->m_cRef) && v28 )
    v28->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v28, 1u);
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00708670) --------------------------------------------------------  // acclient.c:795666
void sub_708670()
{
  flt_870364 = 1000.0 + 1.0;
}

//----- (00708690) --------------------------------------------------------  // acclient.c:795672
void sub_708690()
{
  flt_870368 = 24.0 * 8.0;
}

//----- (007086B0) --------------------------------------------------------  // acclient.c:795678
void sub_7086B0()
{
  flt_87036C = 24.0 * 0.5;
}

//----- (007086D0) --------------------------------------------------------  // acclient.c:795684
int _E102_32()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_41;
  dword_870370 = LOWEST_DATA_RATE_41;
  return result;
}

//----- (007086E0) --------------------------------------------------------  // acclient.c:795694
int _E104_16()
{
  return atexit(_E105_68);
}

//----- (007086F0) --------------------------------------------------------  // acclient.c:795700
int _E107_39()
{
  return atexit(nullsub_1303);
}

//----- (00708700) --------------------------------------------------------  // acclient.c:795706
int _E110_71()
{
  return atexit(_E111_72);
}

//----- (00708710) --------------------------------------------------------  // acclient.c:795712
int _E113_24()
{
  return atexit(_E114_78);
}

//----- (00708720) --------------------------------------------------------  // acclient.c:795718
void _E116_24()
{
  flt_870374 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00708740) --------------------------------------------------------  // acclient.c:795724
void _E118_75()
{
  dbl_870378 = 1.0 / 30.0;
}

//----- (00708760) --------------------------------------------------------  // acclient.c:795730
void _E120_67()
{
  dbl_870380 = 1.0 / 5.0;
}

//----- (00708780) --------------------------------------------------------  // acclient.c:795736
void _E122_30()
{
  PixelFormatDesc::PixelFormatDesc(&stru_870388, PFID_A8R8G8B8);
}

//----- (00708790) --------------------------------------------------------  // acclient.c:795742
int _E127_55()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_32, "Display.Resolution");
  return atexit(_E128_61);
}

//----- (007087B0) --------------------------------------------------------  // acclient.c:795749
int _E130_50()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_32, "Display.FullScreen");
  return atexit(_E131_52);
}

//----- (007087D0) --------------------------------------------------------  // acclient.c:795756
int _E133_43()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_32, "Display.RefreshRate");
  return atexit(_E134_37);
}

//----- (007087F0) --------------------------------------------------------  // acclient.c:795763
int _E136_29()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_32, "Display.SyncToRefresh");
  return atexit(_E137_36);
}

//----- (00708810) --------------------------------------------------------  // acclient.c:795770
int _E139_29()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_46, "Misc.TooltipEnable");
  return atexit(_E140_30);
}

//----- (00708830) --------------------------------------------------------  // acclient.c:795777
int _E142_26()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_46, "Misc.TooltipDelay");
  return atexit(_E143_30);
}

//----- (00708850) --------------------------------------------------------  // acclient.c:795784
int _E145_28()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_21, "Sound.SoundDisabled");
  return atexit(_E146_30);
}

//----- (00708870) --------------------------------------------------------  // acclient.c:795791
int _E148_28()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_21, "Sound.SoundVolume");
  return atexit(_E149_30);
}

//----- (00708890) --------------------------------------------------------  // acclient.c:795798
int _E151_26()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_21, "Sound.AmbientSoundDisabled");
  return atexit(_E152_31);
}

//----- (007088B0) --------------------------------------------------------  // acclient.c:795805
int _E154_27()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_21, "Sound.AmbientSoundVolume");
  return atexit(_E155_27);
}

//----- (007088D0) --------------------------------------------------------  // acclient.c:795812
int _E157_25()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_21, "Sound.InterfaceSoundDisabled");
  return atexit(_E158_29);
}

//----- (007088F0) --------------------------------------------------------  // acclient.c:795819
int _E160_28()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_21, "Sound.InterfaceSoundVolume");
  return atexit(_E161_26);
}

//----- (00708910) --------------------------------------------------------  // acclient.c:795826
int _E163_21()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_21, "Sound.SoundFeatures");
  return atexit(_E164_28);
}

//----- (00708930) --------------------------------------------------------  // acclient.c:795833
int _E166_23()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_21, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E167_24);
}

//----- (00708950) --------------------------------------------------------  // acclient.c:795840
int _E169_21()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_21, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_8703FC, "Mono");
  return atexit(_E170_24);
}

//----- (00708980) --------------------------------------------------------  // acclient.c:795848
void _E172_19()
{
  VOL_MIN_DIST_SQ_18 = 5.0 * 5.0;
}

//----- (007089A0) --------------------------------------------------------  // acclient.c:795854
void _E174_32()
{
  INV_LOG_OF_2_18 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (007089C0) --------------------------------------------------------  // acclient.c:795860
int sub_7089C0()
{
  return atexit(nullsub_1301);
}

//----- (007735C0) --------------------------------------------------------  // acclient.c:907084
void __cdecl _E128_61()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007735F0) --------------------------------------------------------  // acclient.c:907097
void __cdecl _E131_52()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773620) --------------------------------------------------------  // acclient.c:907110
void __cdecl _E134_37()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773650) --------------------------------------------------------  // acclient.c:907123
void __cdecl _E137_36()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773680) --------------------------------------------------------  // acclient.c:907136
void __cdecl _E140_30()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007736B0) --------------------------------------------------------  // acclient.c:907149
void __cdecl _E143_30()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007736E0) --------------------------------------------------------  // acclient.c:907162
void __cdecl _E146_30()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773710) --------------------------------------------------------  // acclient.c:907175
void __cdecl _E149_30()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773740) --------------------------------------------------------  // acclient.c:907188
void __cdecl _E152_31()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773770) --------------------------------------------------------  // acclient.c:907201
void __cdecl _E155_27()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007737A0) --------------------------------------------------------  // acclient.c:907214
void __cdecl _E158_29()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007737D0) --------------------------------------------------------  // acclient.c:907227
void __cdecl _E161_26()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773800) --------------------------------------------------------  // acclient.c:907240
void __cdecl _E164_28()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773830) --------------------------------------------------------  // acclient.c:907253
void __cdecl _E167_24()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773860) --------------------------------------------------------  // acclient.c:907266
void __cdecl _E170_24()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_18;
  v1 = 2;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
    --v0;
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

