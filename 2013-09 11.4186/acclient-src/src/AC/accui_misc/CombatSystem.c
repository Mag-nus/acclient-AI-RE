/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CombatSystem
   Object     : AC\accui_misc\CombatSystem.obj
   Functions  : 92
   Addresses  : 0056A400 - 00773BC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0056A400) --------------------------------------------------------  // acclient.c:407253
int __thiscall Subpalette::vector_deleting_destructor(CombatManeuver *this, unsigned int a2)
{
  CombatManeuver *v2; // esi@1
  unsigned int v3; // ecx@2
  int v4; // eax@2
  int v5; // ecx@2
  int v6; // eax@2
  int v7; // ecx@3
  int result; // eax@7

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].motion;
    v4 = 3 * v3;
    v5 = v3 - 1;
    v6 = (int)&v2[8 * v4 / 0x18u];
    if ( v5 >= 0 )
    {
      v7 = v5 + 1;
      do
      {
        v6 -= 24;
        --v7;
        *(_DWORD *)v6 = &PackObj::vftable;
      }
      while ( v7 );
    }
    if ( a2 & 1 )
      operator delete[](&v2[-1].motion);
    result = (int)&v2[-1].motion;
  }
  else
  {
    this->vfptr = (PackObjVtbl *)&PackObj::vftable;
    if ( a2 & 1 )
      operator delete(this);
    result = (int)v2;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0056A460) --------------------------------------------------------  // acclient.c:407297
void __thiscall ClientCombatSystem::Begin(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  GlobalEventHandler *v2; // eax@1

  v1 = this;
  this->combatMode = 1;
  this->pendingCombatMode = 0;
  this->jump_pending = 0;
  *(_QWORD *)&this->buildStartTime = 0i64;
  this->buildInProgress = 0;
  this->powerBarMode = 0;
  LODWORD(this->latestPowerBarLevel) = 0;
  this->attackServerResponsePending = 0;
  this->attackWhenResponseReceived = 0;
  LODWORD(this->attackWhenResponseReceived_Power) = 0;
  this->attackRequestInProgress = 0;
  this->attackInProgress = 0;
  LODWORD(this->requestedAttackPower) = 0;
  this->requestedAttackHeight = 2;
  this->currentBuildIsAutomatic = 0;
  this->targetWillinglyLost = 0;
  this->repeatAttacking = 0;
  LODWORD(this->m_rUIRequestedPower) = 1056964608;
  this->m_bTrackingTarget = 0;
  this->m_bAdvancedCombatMode = 0;
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
    v2->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v2,
      (unsigned int)((char *)&loc_4DD1EE + 1),
      (NoticeHandler *)&v1->vfptr);
}

//----- (0056A4D0) --------------------------------------------------------  // acclient.c:407332
ClientCombatSystem *__cdecl ClientCombatSystem::GetCombatSystem()
{
  return ClientCombatSystem::s_pCombatSystem;
}
// 87065C: using guessed type struct ClientCombatSystem *ClientCombatSystem::s_pCombatSystem;

//----- (0056A4E0) --------------------------------------------------------  // acclient.c:407339
void __thiscall ClientCombatSystem::OnStartup(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1

  v1 = this;
  ClientCombatSystem::s_pCombatSystem = this;
  ((void (*)(void))this->vfptr->AddRef)();
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    40,
    &v1->vfptr);
}
// 87065C: using guessed type struct ClientCombatSystem *ClientCombatSystem::s_pCombatSystem;

//----- (0056A510) --------------------------------------------------------  // acclient.c:407354
void __thiscall ClientCombatSystem::OnShutdown(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1

  v1 = this;
  if ( ClientCombatSystem::s_pCombatSystem )
  {
    ((void (*)(void))ClientCombatSystem::s_pCombatSystem->vfptr->Release)();
    ClientCombatSystem::s_pCombatSystem = 0;
  }
  if ( v1 )
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
      1,
      40,
      &v1->vfptr);
  else
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
      1,
      40,
      0);
}
// 87065C: using guessed type struct ClientCombatSystem *ClientCombatSystem::s_pCombatSystem;

//----- (0056A560) --------------------------------------------------------  // acclient.c:407378
unsigned int __stdcall ClientCombatSystem::Handle_Combat__QueryHealthResponse(unsigned int target, float health)
{
  CM_Combat::SendNotice_UpdateObjectHealth(target, health);
  return 0;
}

//----- (0056A580) --------------------------------------------------------  // acclient.c:407385
char __stdcall ClientCombatSystem::CompatibleCombatMode(COMBAT_MODE i_combatMode)
{
  if ( i_combatMode == 4 )
  {
    if ( !((CPlayerSystem::GetPlayerSystem()->inventoryMask >> 22) & 1) )
      return 0;
    return 1;
  }
  if ( i_combatMode == 8 )
  {
    if ( !(BYTE3(CPlayerSystem::GetPlayerSystem()->inventoryMask) & 1) )
      return 0;
  }
  else if ( i_combatMode == 2
         && !((CPlayerSystem::GetPlayerSystem()->inventoryMask >> 20) & 1)
         && !((CPlayerSystem::GetPlayerSystem()->inventoryMask >> 25) & 1)
         && CPlayerSystem::GetPlayerSystem()->inventoryMask & 0x3500000 )
  {
    return 0;
  }
  return 1;
}

//----- (0056A600) --------------------------------------------------------  // acclient.c:407409
char __stdcall ClientCombatSystem::ObjectIsAttackable(unsigned int _objectID)
{
  unsigned int v2; // eax@3
  HashBaseData<unsigned long> *v4; // esi@7
  CPlayerSystem *v5; // eax@10
  HashBaseData<unsigned long> *v6; // eax@10
  HashBaseData<unsigned long> *v7; // edi@10

  if ( !_objectID )
    return 1;
  v2 = SmartBox::smartbox ? SmartBox::smartbox->player_id : 0;
  if ( _objectID == v2 )
    return 1;
  v4 = ClientObjMaintSystem::GetWeenieObject(_objectID);
  if ( !v4 || !(((int (__thiscall *)(HashBaseData<unsigned long> *))v4->vfptr[6].__vecDelDtor)(v4) & 0x10) )
    return 0;
  if ( (unsigned int)v4[21].hash_next & 0x200000 )
    return 1;
  v5 = CPlayerSystem::GetPlayerSystem();
  v6 = ClientObjMaintSystem::GetWeenieObject(v5->playerID);
  v7 = v6;
  if ( !v6 )
    return 0;
  if ( (unsigned int)v6[21].hash_next & 0x200000 )
    return 1;
  if ( ((int (__thiscall *)(HashBaseData<unsigned long> *))v4->vfptr[4].__vecDelDtor)(v4) )
  {
    if ( ((int (__thiscall *)(HashBaseData<unsigned long> *))v4->vfptr[8].__vecDelDtor)(v4)
      && ((int (__thiscall *)(HashBaseData<unsigned long> *))v7->vfptr[8].__vecDelDtor)(v7)
      || ((int (__thiscall *)(HashBaseData<unsigned long> *))v4->vfptr[9].__vecDelDtor)(v4)
      && ((int (__thiscall *)(HashBaseData<unsigned long> *))v7->vfptr[9].__vecDelDtor)(v7) )
      return 1;
  }
  else if ( !v4[26].id )
  {
    return (LOBYTE(v4[21].hash_next) >> 4) & 1;
  }
  return 0;
}

//----- (0056A6E0) --------------------------------------------------------  // acclient.c:407450
char __stdcall ClientCombatSystem::HandleMagicAction(InputEvent *i_evt)
{
  char result; // al@3

  if ( i_evt->m_fStart )
  {
    switch ( i_evt->m_InputAction )
    {
      case 0x10000063u:
        CM_Magic::SendNotice_PrevSpellTab();
        result = 1;
        break;
      case 0x10000064u:
        CM_Magic::SendNotice_NextSpellTab();
        result = 1;
        break;
      case 0x10000062u:
        CM_Magic::SendNotice_NextSpellSelection();
        result = 1;
        break;
      case 0x10000060u:
        CM_Magic::SendNotice_CastCurrentSpell();
        result = 1;
        break;
      case 0x10000061u:
        CM_Magic::SendNotice_PrevSpellSelection();
        result = 1;
        break;
      case 0x10000104u:
        CM_Magic::SendNotice_FirstSpellTab();
        result = 1;
        break;
      case 0x10000105u:
        CM_Magic::SendNotice_LastSpellTab();
        result = 1;
        break;
      case 0x10000102u:
        CM_Magic::SendNotice_FirstSpellSelection();
        result = 1;
        break;
      case 0x10000103u:
        CM_Magic::SendNotice_LastSpellSelection();
        result = 1;
        break;
      case 0x10000065u:
      case 0x10000066u:
      case 0x10000067u:
      case 0x10000068u:
      case 0x10000069u:
      case 0x1000006Au:
      case 0x1000006Bu:
      case 0x1000006Cu:
      case 0x1000006Du:
      case 0x1000006Eu:
      case 0x1000006Fu:
      case 0x10000070u:
        CM_Magic::SendNotice_CastQuickslotSpell(i_evt->m_InputAction - 268435557);
        result = 1;
        break;
      default:
        goto LABEL_13;
    }
  }
  else
  {
LABEL_13:
    result = 0;
  }
  return result;
}

//----- (0056A860) --------------------------------------------------------  // acclient.c:407522
signed int __thiscall ClientCombatSystem::RepeatAttackInProgress(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  CPlayerSystem *v2; // eax@1
  signed int result; // eax@2

  v1 = this;
  v2 = CPlayerSystem::GetPlayerSystem();
  if ( !(unsigned __int8)PlayerModule::AutoRepeatAttack((PlayerModule *)&v2->playerModule.vfptr)
    || (result = 1, !v1->attackInProgress) && v1->powerBarMode != 1 )
    result = 0;
  return result;
}

//----- (0056A890) --------------------------------------------------------  // acclient.c:407537
void __thiscall ClientCombatSystem::SetPowerBarLevel(ClientCombatSystem *this, float level)
{
  ClientCombatSystem *v2; // esi@1

  v2 = this;
  CM_Character::SendNotice_SetPowerbarLevel(this->powerBarMode, level);
  v2->latestPowerBarLevel = level;
}

//----- (0056A8B0) --------------------------------------------------------  // acclient.c:407547
void __thiscall ClientCombatSystem::HidePowerBar(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  PowerBarMode v2; // eax@1

  v1 = this;
  v2 = this->powerBarMode;
  this->buildInProgress = 0;
  *(_QWORD *)&this->buildStartTime = 0i64;
  if ( v2 == 1 )
  {
    CM_Character::SendNotice_SetPowerbarLevel(PBM_COMBAT, 0.0);
    v1->powerBarMode = 0;
  }
  else
  {
    CM_Character::SendNotice_FinishPowerbar(v2);
    v1->powerBarMode = 0;
  }
}

//----- (0056A8F0) --------------------------------------------------------  // acclient.c:407569
unsigned int ClientCombatSystem::GetAttackTarget()
{
  unsigned int v1; // esi@1
  HashBaseData<unsigned long> *v2; // eax@2
  HashBaseData<unsigned long> *v3; // eax@4
  HashBaseData<unsigned long> *v4; // eax@5
  unsigned int result; // eax@9

  v1 = ACCWeenieObject::selectedID;
  if ( ACCWeenieObject::selectedID == Formatted )
    goto LABEL_13;
  v2 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
  if ( !v2 || ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v2) )
    goto LABEL_13;
  v3 = ClientObjMaintSystem::GetPhysicsObject(v1);
  if ( v3 )
  {
    v4 = v3[5].hash_next;
    if ( v4 )
      v1 = v4->id;
  }
  if ( !v1 || ClientObjMaintSystem::GetWeenieObject(v1) )
    result = v1;
  else
LABEL_13:
    result = 0;
  return result;
}

//----- (0056A950) --------------------------------------------------------  // acclient.c:407599
void __thiscall ClientCombatSystem::UpdateTargetTracking(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  ClientUISystem *v2; // eax@1
  CameraSet *v3; // ebx@1
  COMBAT_MODE v4; // eax@3
  unsigned int v5; // eax@5
  unsigned int v6; // edi@5

  v1 = this;
  v2 = ClientUISystem::GetUISystem();
  v3 = ClientUISystem::AccessCameraSet(v2);
  if ( v3 )
  {
    if ( v1->m_bTrackingTarget
      && ((v4 = v1->combatMode, v4 == 2) || v4 == 4)
      && (v5 = ClientCombatSystem::GetAttackTarget(), (v6 = v5) != 0)
      && ClientCombatSystem::ObjectIsAttackable(v5) )
      CameraSet::TrackTarget(v3, v6);
    else
      CameraSet::TrackTarget(v3, 0);
  }
}

//----- (0056A9B0) --------------------------------------------------------  // acclient.c:407624
void __thiscall ClientCombatSystem::FinishJump(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  PowerBarMode v2; // eax@2
  CPhysicsObj *v3; // edi@6

  v1 = this;
  if ( this->jump_pending )
  {
    v2 = this->powerBarMode;
    this->buildInProgress = 0;
    *(_QWORD *)&this->buildStartTime = 0i64;
    if ( v2 == 1 )
      CM_Character::SendNotice_SetPowerbarLevel(PBM_COMBAT, 0.0);
    else
      CM_Character::SendNotice_FinishPowerbar(v2);
    v1->powerBarMode = 0;
  }
  v3 = SmartBox::smartbox->player;
  if ( v3 && CPhysicsObj::get_minterp(SmartBox::smartbox->player) )
    CPhysicsObj::get_minterp(v3)->standing_longjump = 0;
  v1->jump_pending = 0;
}

//----- (0056AA20) --------------------------------------------------------  // acclient.c:407649
void __thiscall ClientCombatSystem::RegisterInputMaps(ClientCombatSystem *this, COMBAT_MODE i_CurrentMode, COMBAT_MODE i_PreviousMode)
{
  CInputManager *v3; // esi@1
  ClientCombatSystem *v4; // edi@1
  IInputActionCallback *v5; // eax@12
  int v6; // eax@16
  int v7; // eax@28

  v3 = ICIDM::s_cidm;
  v4 = this;
  if ( ICIDM::s_cidm )
  {
    switch ( i_PreviousMode )
    {
      case 2:
        if ( this )
          v5 = (IInputActionCallback *)&this->vfptr;
        else
          v5 = 0;
        ICIDM::s_cidm->vfptr->UnregisterInputMap((ICIDM *)ICIDM::s_cidm, 268435459u, v5);
        break;
      case 4:
        if ( this )
          ICIDM::s_cidm->vfptr->UnregisterInputMap(
            (ICIDM *)ICIDM::s_cidm,
            268435460u,
            (IInputActionCallback *)&this->vfptr);
        else
          ICIDM::s_cidm->vfptr->UnregisterInputMap((ICIDM *)ICIDM::s_cidm, 268435460u, 0);
        break;
      case 8:
        if ( this )
          ICIDM::s_cidm->vfptr->UnregisterInputMap(
            (ICIDM *)ICIDM::s_cidm,
            268435461u,
            (IInputActionCallback *)&this->vfptr);
        else
          ICIDM::s_cidm->vfptr->UnregisterInputMap((ICIDM *)ICIDM::s_cidm, 268435461u, 0);
        break;
    }
    if ( v4 )
      v6 = (int)&v4->vfptr;
    else
      v6 = 0;
    v3->vfptr->RegisterInputMap((ICIDM *)v3, 268435458u, (IInputActionCallback *)v6, 1000);
    switch ( i_CurrentMode )
    {
      case 2:
        if ( v4 )
          v7 = (int)&v4->vfptr;
        else
          v7 = 0;
        v3->vfptr->RegisterInputMap((ICIDM *)v3, 268435459u, (IInputActionCallback *)v7, 1000);
        break;
      case 4:
        if ( v4 )
          v3->vfptr->RegisterInputMap((ICIDM *)v3, 268435460u, (IInputActionCallback *)&v4->vfptr, 1000);
        else
          v3->vfptr->RegisterInputMap((ICIDM *)v3, 268435460u, 0, 1000);
        break;
      case 8:
        if ( v4 )
          v3->vfptr->RegisterInputMap((ICIDM *)v3, 268435461u, (IInputActionCallback *)&v4->vfptr, 1000);
        else
          v3->vfptr->RegisterInputMap((ICIDM *)v3, 268435461u, 0, 1000);
        break;
    }
  }
}

//----- (0056AB60) --------------------------------------------------------  // acclient.c:407720
int __cdecl CombatManeuverTable::Get(IDClass<_tagDataID,32,0> did)
{
  QualifiedDataID *v1; // eax@1
  QualifiedDataID v3; // [sp+0h] [bp-8h]@1

  QualifiedDataID::QualifiedDataID(&v3, did, 0x1000000Du);
  return DBObj::Get(v1);
}

//----- (0056AB80) --------------------------------------------------------  // acclient.c:407730
void __thiscall ClientCombatSystem::~ClientCombatSystem(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  char *v2; // edi@1
  GlobalEventHandler *v3; // eax@1
  int v4; // ecx@3

  v1 = this;
  v2 = (char *)&this[-1].lastAttackedTime;
  LODWORD(this[-1].lastAttackedTime) = &ClientCombatSystem::vftable;
  HIDWORD(this[-1].lastAttackedTime) = &ClientCombatSystem::vftable;
  this->vfptr = (InterfaceVtbl *)&ClientCombatSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientCombatSystem::vftable;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
  {
    if ( v2 )
      v4 = (int)(v2 + 4);
    else
      v4 = 0;
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, (NoticeHandler *)v4);
  }
  v1->vfptr = (IInputActionCallbackVtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  *(_DWORD *)(v1 != (ClientCombatSystem *)8 ? (unsigned int)v1 : 0) = &IInputActionCallback::vftable;
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(v1 != (ClientCombatSystem *)8 ? (unsigned int)v1 : 0);
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
// 7CF1DC: using guessed type void (__thiscall *ClientCombatSystem::vftable)(ClientCombatSystem *this, CWeenieObject *cwobj, enum StatType mode, unsigned __int32);
// 7CF1E4: using guessed type int (__stdcall *ClientCombatSystem::vftable)(char);
// 7CF1F0: using guessed type bool (__thiscall *ClientCombatSystem::vftable)(DBCache *this);
// 7CF498: using guessed type __int32 (__stdcall *ClientCombatSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0056AC10) --------------------------------------------------------  // acclient.c:407776
LONG __thiscall ClientObjMaintSystem::AddRef(ClientCombatSystem *this)
{
  return InterlockedIncrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef);
}

//----- (0056AC20) --------------------------------------------------------  // acclient.c:407782
unsigned int __thiscall ClientCombatSystem::Release(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
    v1->vfptr->__vecDelDtor(&v1->vfptr, 1);
  return v2;
}

//----- (0056AC50) --------------------------------------------------------  // acclient.c:407795
TResult *__thiscall ClientCombatSystem::QueryInterface(ClientCombatSystem *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( _S160_6 & 1 )
  {
    v4 = Offsets_8[0].key;
  }
  else
  {
    v4 = (_GUID *)&ClientCombatSystem_InterfaceType_60;
    _S160_6 |= 1u;
    Offsets_8[0].key = (_GUID *)&ClientCombatSystem_InterfaceType_60;
    dword_870714 = 0;
    dword_870718 = (int)&ClientSystem_InterfaceType_87;
    dword_87071C = 0;
    dword_870720 = (int)&stru_7CF1C8;
    dword_870724 = 0;
    dword_870728 = 0;
    dword_87072C = 0;
  }
  v5 = (int)Offsets_8;
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
// 870714: using guessed type int dword_870714;
// 870718: using guessed type int dword_870718;
// 87071C: using guessed type int dword_87071C;
// 870720: using guessed type int dword_870720;
// 870724: using guessed type int dword_870724;
// 870728: using guessed type int dword_870728;
// 87072C: using guessed type int dword_87072C;

//----- (0056AD20) --------------------------------------------------------  // acclient.c:407862
void __thiscall ClientCombatSystem::HandleCommenceAttackEvent(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  bool v2; // al@1
  bool v3; // cl@3
  int v4; // eax@3
  float v5; // ST0C_4@6
  ClientUISystem *v6; // eax@7

  v1 = this;
  v2 = this->attackRequestInProgress;
  this->attackInProgress = 1;
  this->attackServerResponsePending = 1;
  if ( !v2 )
  {
    if ( this->powerBarMode == PBM_UNDEF )
    {
      v3 = this->m_bAdvancedCombatMode;
      v4 = (v3 != 0) + 1;
      v1->powerBarMode = v4;
      if ( v4 == 1 )
        CM_Character::SendNotice_SetPowerbarLevel(PBM_COMBAT, 0.0);
      else
        CM_Character::SendNotice_BeginPowerbar((PowerBarMode)((v3 != 0) + 1));
    }
    v5 = v1->requestedAttackPower;
    CM_Character::SendNotice_SetPowerbarLevel(v1->powerBarMode, v5);
    v1->latestPowerBarLevel = v5;
    v1->buildInProgress = 0;
    LODWORD(v1->buildStartTime) = 0;
    HIDWORD(v1->buildStartTime) = 0;
  }
  ACCWeenieObject::attackInProgress = 1;
  v6 = ClientUISystem::GetUISystem();
  ClientUISystem::IncrementBusyCount(v6);
}
// 870ED0: using guessed type int ACCWeenieObject::attackInProgress;

//----- (0056ADB0) --------------------------------------------------------  // acclient.c:407901
void __thiscall ClientCombatSystem::StartPowerBarBuild(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  PowerBarMode v2; // edx@1
  unsigned int v3; // ecx@1

  v1 = this;
  v2 = this->powerBarMode;
  this->buildInProgress = 1;
  v3 = Timer::cur_time.Param;
  LODWORD(v1->buildStartTime) = Timer::cur_time.Cmd;
  HIDWORD(v1->buildStartTime) = v3;
  CM_Character::SendNotice_SetPowerbarLevel(v2, 0.0);
  LODWORD(v1->latestPowerBarLevel) = 0;
}

//----- (0056ADE0) --------------------------------------------------------  // acclient.c:407918
double __thiscall ClientCombatSystem::GetPowerBarLevel(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  double result; // st7@2
  unsigned int v3; // eax@4
  HashBaseData<unsigned long> *v4; // eax@6
  double v5; // st7@7

  v1 = this;
  if ( this->buildInProgress )
  {
    if ( SmartBox::smartbox )
      v3 = SmartBox::smartbox->player_id;
    else
      v3 = 0;
    v4 = ClientObjMaintSystem::GetPhysicsObject(v3);
    if ( *(_DWORD *)(CPhysicsObj::InqInterpretedMotionState((CPhysicsObj *)v4) + 4) == -2147483578 )
      v5 = 0.8;
    else
      v5 = 1.0;
    result = (COERCE_DOUBLE(Timer::cur_time.Cmd) - v1->buildStartTime) / v5;
    if ( result <= 1.0 )
    {
      if ( result < 0.0 )
        result = 0.0;
    }
    else
    {
      result = 1.0;
    }
  }
  else
  {
    result = 0.0;
  }
  return result;
}

//----- (0056AE90) --------------------------------------------------------  // acclient.c:407957
void __thiscall ClientCombatSystem::AbortAutomaticAttack(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  bool v2; // al@5

  v1 = this;
  if ( this->attackServerResponsePending
    || this->attackRequestInProgress
    || this->attackInProgress
    || this->repeatAttacking )
  {
    CM_Combat::Event_CancelAttack();
    v2 = v1->buildInProgress;
    v1->repeatAttacking = 0;
    if ( v2 && v1->powerBarMode == 1 )
      ClientCombatSystem::HidePowerBar(v1);
  }
}

//----- (0056AED0) --------------------------------------------------------  // acclient.c:407977
void __thiscall ClientCombatSystem::TrackTarget(ClientCombatSystem *this, bool i_bTrackTarget)
{
  if ( i_bTrackTarget != this->m_bTrackingTarget )
  {
    this->m_bTrackingTarget = i_bTrackTarget;
    ClientCombatSystem::UpdateTargetTracking(this);
  }
}

//----- (0056AEF0) --------------------------------------------------------  // acclient.c:407987
void __thiscall ClientCombatSystem::OnBeginCharacterSession(ClientCombatSystem *this)
{
  if ( ICIDM::s_cidm )
  {
    if ( this )
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(
        268435458,
        &this->vfptr,
        1000);
    else
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(268435458, 0, 1000);
  }
}

//----- (0056AF30) --------------------------------------------------------  // acclient.c:408002
void __thiscall ClientCombatSystem::OnEndCharacterSession(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  char *v2; // eax@3
  GlobalEventHandler *v3; // eax@6

  v1 = this;
  if ( ICIDM::s_cidm )
  {
    if ( this )
      v2 = (char *)&this->vfptr;
    else
      v2 = 0;
    ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(v2);
  }
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
  {
    if ( v1 )
    {
      v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, (NoticeHandler *)&v1->vfptr);
      ClientCombatSystem::Begin(v1);
      return;
    }
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, 0);
  }
  ClientCombatSystem::Begin(v1);
}

//----- (0056AF90) --------------------------------------------------------  // acclient.c:408032
void __thiscall ClientCombatSystem::CommenceJump(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  CMotionInterp *v2; // eax@2
  signed int v3; // eax@2
  int v4; // eax@3
  CPlayerSystem *v5; // eax@9

  v1 = this;
  if ( !this->jump_pending )
  {
    v2 = CPhysicsObj::get_minterp(SmartBox::smartbox->player);
    v3 = CMotionInterp::charge_jump(v2);
    if ( v3 )
    {
      v4 = v3 - 72;
      if ( v4 )
      {
        if ( v4 == 1 )
          ClientSystem::AddTextToScroll((ClientSystem *)&v1->vfptr, &cant_jump_load, 0x1Au, 1, 0);
        else
          ClientSystem::AddTextToScroll((ClientSystem *)&v1->vfptr, &cant_jump_in_air, 0x1Au, 1, 0);
      }
      else
      {
        ClientSystem::AddTextToScroll((ClientSystem *)&v1->vfptr, &cant_jump_position, 0x1Au, 1, 0);
      }
    }
    else
    {
      v5 = CPlayerSystem::GetPlayerSystem();
      if ( (unsigned __int8)PlayerModule::AutoRepeatAttack((PlayerModule *)&v5->playerModule.vfptr) )
      {
        CM_Combat::Event_CancelAttack();
        v1->repeatAttacking = 0;
      }
      CM_Character::SendNotice_SetPowerbarLevel(v1->powerBarMode, 0.0);
      LODWORD(v1->latestPowerBarLevel) = 0;
      v1->jump_pending = 1;
      v1->powerBarMode = 3;
      CM_Character::SendNotice_BeginPowerbar(PBM_JUMP);
      ClientCombatSystem::StartPowerBarBuild(v1);
      ((void (*)(void))SmartBox::smartbox->cmdinterp->vfptr[6].OnAction)();
    }
  }
}

//----- (0056B050) --------------------------------------------------------  // acclient.c:408080
double __thiscall ClientCombatSystem::GetJumpPowerLevel(ClientCombatSystem *this)
{
  double v1; // st7@2
  float *v2; // eax@2
  double result; // st7@4
  ClientCombatSystem *v4; // [sp+0h] [bp-4h]@1

  v4 = this;
  if ( this->jump_pending )
  {
    v1 = ClientCombatSystem::GetPowerBarLevel(this);
    *(float *)&v4 = v1;
    v2 = (float *)&MIN_JUMP_EXTENT;
    if ( v1 >= 0.001 )
      v2 = (float *)&v4;
    result = *v2;
  }
  else
  {
    result = 0.0;
  }
  return result;
}

//----- (0056B090) --------------------------------------------------------  // acclient.c:408105
void __thiscall ClientCombatSystem::ClientCombatSystem(ClientCombatSystem *this)
{
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&IInputActionCallback::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)QualityChangeHandler::vftable;
  this->vfptr = (InterfaceVtbl *)&ClientCombatSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientCombatSystem::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&ClientCombatSystem::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)&ClientCombatSystem::vftable;
  this->m_cTurbineRefCount.m_cRef = 1;
  this->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  ClientCombatSystem::Begin(this);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 7A5AA4: using guessed type void (__thiscall *QualityChangeHandler::vftable[2])(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CF1DC: using guessed type void (__thiscall *ClientCombatSystem::vftable)(ClientCombatSystem *this, CWeenieObject *cwobj, enum StatType mode, unsigned __int32);
// 7CF1E4: using guessed type int (__stdcall *ClientCombatSystem::vftable)(char);
// 7CF1F0: using guessed type bool (__thiscall *ClientCombatSystem::vftable)(DBCache *this);
// 7CF498: using guessed type __int32 (__stdcall *ClientCombatSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0056B0E0) --------------------------------------------------------  // acclient.c:408128
int __thiscall ClientCombatSystem::vector_deleting_destructor(ClientCombatSystem *this, char a2)
{
  ClientCombatSystem *v2; // esi@1
  int result; // eax@1

  v2 = this;
  ClientCombatSystem::~ClientCombatSystem(this);
  result = (int)&v2[-1].lastAttackedTime;
  if ( a2 & 1 )
  {
    operator delete(&v2[-1].lastAttackedTime);
    result = (int)&v2[-1].lastAttackedTime;
  }
  return result;
}

//----- (0056B110) --------------------------------------------------------  // acclient.c:408145
void __thiscall ClientCombatSystem::DoJump(ClientCombatSystem *this, bool autonomous)
{
  ClientCombatSystem *v2; // edi@1
  double v3; // st7@3
  const float *v4; // eax@3
  double v5; // st7@8
  const float *v6; // eax@8
  CPhysicsObj *v7; // esi@10
  float v8; // ebp@10
  float v9; // ST14_4@10
  CMotionInterp *v10; // eax@10
  signed int v11; // ebx@10
  float extent; // [sp+4h] [bp-78h]@3
  int adj; // [sp+8h] [bp-74h]@10
  AC1Legacy::Vector3 v; // [sp+Ch] [bp-70h]@10
  JumpPack jp; // [sp+18h] [bp-64h]@11

  v2 = this;
  if ( autonomous )
  {
    if ( this->jump_pending )
    {
      v5 = ClientCombatSystem::GetPowerBarLevel(this);
      extent = v5;
      v6 = &MIN_JUMP_EXTENT;
      if ( v5 >= 0.001 )
        v6 = &extent;
      extent = *v6;
      ClientCombatSystem::FinishJump(v2);
      v7 = SmartBox::smartbox->player;
      v8 = extent;
      v9 = extent;
      v10 = CPhysicsObj::get_minterp(SmartBox::smartbox->player);
      v11 = CMotionInterp::jump(v10, v9, &adj);
      CPhysicsObj::get_local_physics_velocity(v7, &v);
      switch ( v11 )
      {
        case 0:
          JumpPack::JumpPack(
            &jp,
            v8,
            &v,
            &v7->m_position,
            v7->update_times[8],
            v7->update_times[5],
            v7->update_times[4],
            v7->update_times[6]);
          CM_Movement::Event_Jump(&jp);
          break;
        case 73:
          ClientSystem::AddTextToScroll((ClientSystem *)&v2->vfptr, &cant_jump_load, 0x1Au, 1, 0);
          break;
        case 72:
          ClientSystem::AddTextToScroll((ClientSystem *)&v2->vfptr, &cant_jump_position, 0x1Au, 1, 0);
          break;
        case 36:
          ClientSystem::AddTextToScroll((ClientSystem *)&v2->vfptr, &cant_jump_in_air, 0x1Au, 1, 0);
          break;
        default:
          return;
      }
    }
  }
  else
  {
    ClientCombatSystem::FinishJump(this);
    if ( v2->jump_pending )
    {
      v3 = ClientCombatSystem::GetPowerBarLevel(v2);
      extent = v3;
      v4 = &MIN_JUMP_EXTENT;
      if ( v3 >= 0.001 )
        v4 = &extent;
      CM_Movement::Event_Jump_NonAutonomous(*v4);
    }
    else
    {
      extent = 0.0;
      CM_Movement::Event_Jump_NonAutonomous(0.0);
    }
  }
}

//----- (0056B310) --------------------------------------------------------  // acclient.c:408229
signed int __thiscall ClientCombatSystem::GetDefaultCombatMode(ClientCombatSystem *this, CaseInsensitiveStringBase<PStringBase<char> > _quiet)
{
  ClientSystem *v2; // edi@1
  unsigned int v3; // eax@2
  HashBaseData<unsigned long> *v4; // eax@4
  ACCWeenieObject *v5; // esi@4
  unsigned int v6; // eax@5
  HashBaseData<unsigned long> *v7; // eax@6
  unsigned int v9; // eax@9
  HashBaseData<unsigned long> *v10; // esi@10
  int v11; // eax@11
  PStringBase<unsigned short> *v12; // eax@14
  PStringBase<unsigned short> result; // [sp+0h] [bp-4h]@1

  result.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v2 = (ClientSystem *)this;
  if ( SmartBox::smartbox )
    v3 = SmartBox::smartbox->player_id;
  else
    v3 = 0;
  v4 = ClientObjMaintSystem::GetWeenieObject(v3);
  v5 = (ACCWeenieObject *)v4;
  if ( !v4 )
    return 1;
  v6 = (unsigned int)ACCWeenieObject::GetObjectAtLocation((ACCWeenieObject *)v4, 0x2500000u, 0);
  if ( v6 )
  {
    v7 = ClientObjMaintSystem::GetWeenieObject(v6);
    if ( v7 )
    {
      if ( v7[19].id == 2 )
        return 4;
      return 2;
    }
    return 1;
  }
  v9 = (unsigned int)ACCWeenieObject::GetObjectAtLocation(v5, 0x1000000u, 0);
  if ( v9 )
  {
    v10 = ClientObjMaintSystem::GetWeenieObject(v9);
    if ( v10 )
    {
      v11 = ((int (__thiscall *)(HashBaseData<unsigned long> *))v10->vfptr[6].__vecDelDtor)(v10);
      if ( SBYTE1(v11) < 0 )
        return 8;
      if ( !(_BYTE)_quiet.m_charbuffer )
      {
        v12 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v10, &result, NAME_APPROPRIATE, 0);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&_quiet,
          0,
          L"You can't enter combat mode while wielding the %s",
          v12->m_charbuffer);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ClientSystem::AddTextToScroll(v2, (PStringBase<unsigned short> *)&_quiet, 0x1Au, 1, 0);
        PStringBase<char>::~PStringBase<char>(&_quiet);
      }
    }
    return 1;
  }
  return 2;
}

//----- (0056B420) --------------------------------------------------------  // acclient.c:408293
void __thiscall ClientCombatSystem::HandleAttackerNotificationEvent(ClientCombatSystem *this, AC1Legacy::PStringBase<char> *defenders_name, DAMAGE_TYPE dtype, const long double php, const int hp, int critical, const __int64 attack_conditions)
{
  int v7; // eax@1
  AC1Legacy::PSRefBuffer<char> *v8; // esi@1
  bool v9; // bl@1
  DAMAGE_TYPE v10; // esi@5
  char v11; // bl@5
  PStringBase<char> *v12; // eax@6
  PSRefBufferCharData<char> **v13; // edi@8
  char *v14; // esi@9
  int v15; // esi@14
  __int32 v16; // esi@18
  char *v17; // esi@22
  DAMAGE_TYPE v18; // ebx@25
  const int v19; // edi@25
  char v20; // si@29
  DAMAGE_TYPE v21; // eax@34
  int v22; // ecx@34
  LONG (__stdcall *v23)(volatile LONG *); // edi@36
  int v24; // esi@36
  DAMAGE_TYPE v25; // eax@40
  int v26; // ecx@40
  int v27; // esi@42
  PStringBase<unsigned short> *v28; // eax@45
  __int32 v29; // esi@45
  char *v30; // esi@48
  char *v31; // esi@54
  AC1Legacy::PSRefBuffer<char> *v32; // esi@57
  AC1Legacy::PSRefBuffer<char> *v33; // esi@60
  PStringBase<char> msg; // [sp+24h] [bp-58h]@27
  PStringBase<char> damageType; // [sp+28h] [bp-54h]@5
  AC1Legacy::PStringBase<char> single; // [sp+2Ch] [bp-50h]@1
  AC1Legacy::PStringBase<char> dummy; // [sp+30h] [bp-4Ch]@5
  PStringBase<char> v38; // [sp+34h] [bp-48h]@1
  ClientSystem *v39; // [sp+38h] [bp-44h]@1
  char dtmsg[64]; // [sp+3Ch] [bp-40h]@5

  v39 = (ClientSystem *)this;
  v38.m_charbuffer = 0;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&single, &name);
  v7 = gmCCommunicationSystem::IsSquelched(0, &single, 6u);
  v8 = single.m_buffer;
  v9 = v7 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&single.m_buffer->m_cRef) && v8 )
    v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
  if ( v9 )
  {
    single.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    dummy.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    v10 = dtype;
    CombatSystem::InqCombatHitAdjectives(dtype, php, &single, &dummy);
    AppraisalSystem::DamageTypeToString(v10, dtmsg, 0x40u);
    PStringBase<char>::PStringBase<char>(&damageType, dtmsg);
    PStringBase<char>::break_reference(&damageType);
    __strlwr(damageType.m_charbuffer->m_data);
    v11 = 1;
    if ( *(_DWORD *)&damageType.m_charbuffer[-1].m_data[12] == 1 )
    {
      PStringBase<char>::PStringBase<char>(&v38, &name);
    }
    else
    {
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&dtype, " ");
      v11 = 6;
      v12 = PStringBase<char>::operator+(&damageType, (PStringBase<char> *)&php, (PStringBase<char> *)&dtype);
    }
    v13 = (PSRefBufferCharData<char> **)v12;
    if ( damageType.m_charbuffer != v12->m_charbuffer )
    {
      v14 = &damageType.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&damageType.m_charbuffer[-1]) && v14 )
        (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
      damageType.m_charbuffer = *v13;
      InterlockedIncrement((volatile LONG *)&damageType.m_charbuffer[-1]);
    }
    if ( v11 & 4 )
    {
      v15 = LODWORD(php) - 20;
      v11 &= 0xFBu;
      if ( !InterlockedDecrement((volatile LONG *)(LODWORD(php) - 20 + 4)) )
      {
        if ( v15 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
      }
    }
    if ( v11 & 2 )
    {
      v16 = dtype - 20;
      v11 &= 0xFDu;
      if ( !InterlockedDecrement((volatile LONG *)(dtype - 20 + 4)) )
      {
        if ( v16 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
      }
    }
    if ( v11 & 1 )
    {
      v17 = &v38.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v38.m_charbuffer[-1]) )
      {
        if ( v17 )
          (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
      }
    }
    v18 = AC1Legacy::PStringBase<char>::s_NullBuffer;
    dtype = AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    v19 = hp;
    if ( hp != 1 )
    {
      AC1Legacy::PStringBase<char>::set((AC1Legacy::PStringBase<char> *)&dtype, "s");
      v18 = dtype;
    }
    msg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    if ( critical )
      PStringBase<char>::set(&msg, "Critical hit!  ");
    v20 = attack_conditions;
    if ( attack_conditions & 4 )
      PStringBase<char>::sprintf_append(&msg, "Sneak Attack! ");
    if ( v20 & 2 )
      PStringBase<char>::sprintf_append(&msg, "Recklessness! ");
    PStringBase<char>::sprintf_append(
      &msg,
      "You %s %s for %d point%s of %sdamage!",
      single.m_buffer->m_data,
      defenders_name->m_buffer->m_data,
      v19,
      v18 + 20,
      damageType.m_charbuffer);
    if ( v20 & 1 )
    {
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&dtype,
        " Your target's Critical Protection augmentation allows them to avoid your critical hit!");
      v21 = dtype;
      v22 = *(_DWORD *)(dtype - 4);
      if ( v22 != 1 )
      {
        PStringBase<char>::append_n_chars(&msg, (const char *)dtype, v22 - 1);
        v21 = dtype;
      }
      v23 = InterlockedDecrement;
      v24 = v21 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v21 - 20 + 4)) && v24 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v24)(v24, 1);
    }
    else
    {
      v23 = InterlockedDecrement;
    }
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&dtype, "\n");
    v25 = dtype;
    v26 = *(_DWORD *)(dtype - 4);
    if ( v26 != 1 )
    {
      PStringBase<char>::append_n_chars(&msg, (const char *)dtype, v26 - 1);
      v25 = dtype;
    }
    v27 = v25 - 20;
    if ( !v23((volatile LONG *)(v25 - 20 + 4)) && v27 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
    v28 = PStringBase<char>::to_wpstring(&msg, (PStringBase<unsigned short> *)&dtype, 0);
    ClientSystem::AddTextToScroll(v39, v28, 0x16u, 1, 0);
    v29 = dtype - 20;
    if ( !v23((volatile LONG *)(dtype - 20 + 4)) && v29 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v29)(v29, 1);
    v30 = &msg.m_charbuffer[-2].m_data[12];
    if ( !v23((volatile LONG *)&msg.m_charbuffer[-1]) && v30 )
      (**(void (__thiscall ***)(char *, signed int))v30)(v30, 1);
    if ( !v23((volatile LONG *)(v18 + 4)) && v18 )
      (**(void (__thiscall ***)(DAMAGE_TYPE, signed int))v18)(v18, 1);
    v31 = &damageType.m_charbuffer[-2].m_data[12];
    if ( !v23((volatile LONG *)&damageType.m_charbuffer[-1]) && v31 )
      (**(void (__thiscall ***)(char *, signed int))v31)(v31, 1);
    v32 = dummy.m_buffer;
    if ( !v23((volatile LONG *)&dummy.m_buffer->m_cRef) && v32 )
      v32->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v32, 1u);
    v33 = single.m_buffer;
    if ( !v23((volatile LONG *)&single.m_buffer->m_cRef) )
    {
      if ( v33 )
        v33->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v33, 1u);
    }
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0056B820) --------------------------------------------------------  // acclient.c:408484
bool __thiscall ClientCombatSystem::PlayerInReadyPosition(ClientCombatSystem *this, bool _considerAttackingReady)
{
  ClientCombatSystem *v2; // esi@1
  unsigned int v3; // eax@2
  HashBaseData<unsigned long> *v4; // edi@4
  int v5; // eax@6
  InterfacePtr<Interface> *v6; // eax@7
  PlayerDesc *v7; // esi@9
  CBaseQualities *v8; // ebx@9
  int v9; // eax@15
  bool v10; // bl@22
  int v11; // esi@25
  int v12; // eax@25
  AttackType at; // [sp+Ch] [bp-18h]@7
  IDClass<_tagDataID,32,0> cmt_id; // [sp+10h] [bp-14h]@11
  InterfacePtr<Interface> result; // [sp+14h] [bp-10h]@7
  InterfacePtr<PlayerDesc> pPlayerDesc; // [sp+1Ch] [bp-8h]@7

  v2 = this;
  if ( SmartBox::smartbox )
    v3 = SmartBox::smartbox->player_id;
  else
    v3 = 0;
  v4 = ClientObjMaintSystem::GetPhysicsObject(v3);
  if ( v4 )
  {
    switch ( v2->combatMode )
    {
      case 1:
      case 8:
$L167453:
        return CPhysicsObj::motions_pending((CPhysicsObj *)v4) == 0;
      case 2:
        at = 0;
        v6 = GetClassObject(&result, &PlayerDesc_ClassType_29);
        InterfacePtr<PlayerDesc>::InterfacePtr<PlayerDesc>(&pPlayerDesc, v6);
        if ( (_DWORD)result.m_pInterface )
          ((void (*)(void))result.m_pInterface->vfptr->Release)();
        v7 = pPlayerDesc.m_pInterface;
        v8 = (CBaseQualities *)&pPlayerDesc.m_pInterface->vfptr;
        CBaseQualities::InqInt((CBaseQualities *)&pPlayerDesc.m_pInterface->vfptr, 0x2Fu, (int *)&at, 0, 0);
        if ( at == Undef_AttackType )
          at = 25;
        CPhysicsObj::InqInterpretedMotionState((CPhysicsObj *)v4);
        cmt_id.id = stru_870678.id;
        CBaseQualities::InqDataID(v8, 4u, &cmt_id);
        if ( cmt_id.id == stru_870678.id )
        {
          if ( v7 )
            v7->vfptr->Release((Interface *)v7);
          goto LABEL_14;
        }
        v9 = CombatManeuverTable::Get(cmt_id);
        if ( v9 )
        {
          if ( _considerAttackingReady )
          {
            if ( v7 )
              v7->vfptr->Release((Interface *)v7);
            LOBYTE(v5) = 1;
          }
          else
          {
            (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 20))(v9);
            v10 = CPhysicsObj::motions_pending((CPhysicsObj *)v4) == 0;
            if ( v7 )
              v7->vfptr->Release((Interface *)v7);
            LOBYTE(v5) = v10;
          }
        }
        else
        {
          if ( !v7 )
            goto LABEL_14;
          v7->vfptr->Release((Interface *)v7);
          LOBYTE(v5) = 0;
        }
        break;
      default:
        goto LABEL_14;
      case 4:
        v11 = *(_DWORD *)(CPhysicsObj::InqInterpretedMotionState((CPhysicsObj *)v4) + 4);
        v12 = *(_DWORD *)(CPhysicsObj::InqInterpretedMotionState((CPhysicsObj *)v4) + 8);
        switch ( v11 )
        {
          default:
            goto LABEL_14;
          case -2147483585:
          case -2147483583:
          case -2147483581:
          case -2147483577:
          case -2147483336:
          case -2147483335:
            if ( v12 != 1090519043 )
              goto LABEL_14;
            if ( !_considerAttackingReady )
              goto $L167453;
            LOBYTE(v5) = 1;
            break;
        }
        return v5;
    }
  }
  else
  {
LABEL_14:
    LOBYTE(v5) = 0;
  }
  return v5;
}

//----- (0056BB00) --------------------------------------------------------  // acclient.c:408596
void __thiscall ClientCombatSystem::AttemptStartBuildingAttack(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  bool v2; // cl@3
  int v3; // eax@3
  PowerBarMode v4; // edx@6
  unsigned int v5; // ecx@6

  v1 = this;
  if ( ClientCombatSystem::PlayerInReadyPosition(this, 1) && !v1->buildInProgress )
  {
    v2 = v1->m_bAdvancedCombatMode;
    v3 = (v2 != 0) + 1;
    v1->powerBarMode = v3;
    if ( v3 == 1 )
      CM_Character::SendNotice_SetPowerbarLevel(PBM_COMBAT, 0.0);
    else
      CM_Character::SendNotice_BeginPowerbar((PowerBarMode)((v2 != 0) + 1));
    v4 = v1->powerBarMode;
    v1->buildInProgress = 1;
    v5 = Timer::cur_time.Param;
    LODWORD(v1->buildStartTime) = Timer::cur_time.Cmd;
    HIDWORD(v1->buildStartTime) = v5;
    CM_Character::SendNotice_SetPowerbarLevel(v4, 0.0);
    LODWORD(v1->latestPowerBarLevel) = 0;
  }
}

//----- (0056BB70) --------------------------------------------------------  // acclient.c:408625
void __thiscall ClientCombatSystem::ExecuteAttack(ClientCombatSystem *this, ATTACK_HEIGHT _attackHeight, bool _expectServerResponse)
{
  ClientCombatSystem *v3; // esi@1
  unsigned int v4; // edi@1
  unsigned int v5; // eax@1
  CPlayerSystem *v6; // eax@9
  __int32 v7; // edi@13
  PowerBarMode v8; // eax@17

  v3 = this;
  this->buildInProgress = 0;
  *(_QWORD *)&this->buildStartTime = 0i64;
  v4 = ClientCombatSystem::GetAttackTarget();
  v5 = ClientCombatSystem::GetAttackTarget();
  if ( !ClientCombatSystem::ObjectIsAttackable(v5) )
    v4 = 0;
  if ( ClientCombatSystem::PlayerInReadyPosition(v3, 1) )
  {
    if ( v4 )
    {
      if ( v3->combatMode == 2 )
      {
        CM_Combat::Event_TargetedMeleeAttack(v4, _attackHeight, v3->requestedAttackPower);
      }
      else if ( v3->combatMode == 4 )
      {
        CM_Combat::Event_TargetedMissileAttack(v4, _attackHeight, v3->requestedAttackPower);
      }
      v6 = CPlayerSystem::GetPlayerSystem();
      if ( (unsigned __int8)PlayerModule::AutoRepeatAttack((PlayerModule *)&v6->playerModule.vfptr) )
        v3->repeatAttacking = 1;
      v3->attackServerResponsePending = 1;
      goto LABEL_16;
    }
  }
  else if ( v4 )
  {
    goto LABEL_16;
  }
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&_attackHeight,
    L"You must select a valid combat target before attacking");
  ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, (PStringBase<unsigned short> *)&_attackHeight, 0x1Au, 1, 0);
  v7 = _attackHeight - 20;
  if ( !InterlockedDecrement((volatile LONG *)(_attackHeight - 20 + 4)) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
LABEL_16:
  if ( !v3->attackServerResponsePending )
  {
    v8 = v3->powerBarMode;
    v3->buildInProgress = 0;
    LODWORD(v3->buildStartTime) = 0;
    HIDWORD(v3->buildStartTime) = 0;
    if ( v8 == 1 )
      CM_Character::SendNotice_SetPowerbarLevel(PBM_COMBAT, 0.0);
    else
      CM_Character::SendNotice_FinishPowerbar(v8);
    v3->powerBarMode = 0;
  }
  if ( !_expectServerResponse )
    v3->attackServerResponsePending = 0;
}

//----- (0056BC80) --------------------------------------------------------  // acclient.c:408689
void __thiscall ClientCombatSystem::AutoTarget(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // ebx@1
  InterfaceSystem *v2; // eax@1
  Interface *v3; // edi@1
  PlayerDesc *v4; // edi@5
  HashBaseData<unsigned long> *v5; // eax@9
  CPlayerSystem *v6; // eax@13
  int v7; // [sp-8h] [bp-2Ch]@1
  unsigned int curAttackerID; // [sp+Ch] [bp-18h]@1
  Interface *_rpInterface; // [sp+10h] [bp-14h]@1
  TResult result; // [sp+14h] [bp-10h]@1
  char v11; // [sp+18h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> pPD; // [sp+1Ch] [bp-8h]@1

  v1 = this;
  curAttackerID = 0;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_29, &_rpInterface);
  v7 = (int)_rpInterface;
  v3 = _rpInterface;
  pPD.m_pInterface = 0;
  pPD.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  InterfacePtr<PlayerDesc>::_QueryInterface(&pPD, (int)&v11, v7, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v4 = pPD.m_pInterface;
  if ( (_DWORD)pPD.m_pInterface )
    CBaseQualities::InqInstanceID((CBaseQualities *)&pPD.m_pInterface->vfptr, 0xBu, &curAttackerID);
  if ( curAttackerID
    && COERCE_DOUBLE(Timer::cur_time.Cmd) - v1->lastAttackedTime < 15.0
    && (v5 = ClientObjMaintSystem::GetWeenieObject(curAttackerID)) != 0
    && !v5[8].hash_next )
  {
    ACCWeenieObject::SetSelectedObject(curAttackerID, 0);
    if ( v4 )
      v4->vfptr->Release((Interface *)v4);
  }
  else
  {
    v6 = CPlayerSystem::GetPlayerSystem();
    CPlayerSystem::SelectNext(v6, 1, 1, SELECTION_TYPE_COMPASS_ITEM, 0);
    if ( v4 )
      v4->vfptr->Release((Interface *)v4);
  }
}

//----- (0056BD80) --------------------------------------------------------  // acclient.c:408740
void __thiscall ClientCombatSystem::RecvNotice_SelectionChanged(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // edi@1
  char *v2; // esi@1
  CPlayerSystem *v3; // eax@1
  char v4; // al@8
  int v5; // eax@15
  CPlayerSystem *v6; // eax@17

  v1 = this;
  v2 = (char *)&this[-1].lastAttackedTime + 4;
  ClientCombatSystem::UpdateTargetTracking((ClientCombatSystem *)((char *)this - 4));
  v3 = CPlayerSystem::GetPlayerSystem();
  if ( (unsigned __int8)PlayerModule::AutoRepeatAttack((PlayerModule *)&v3->playerModule.vfptr)
    && (v2[60] || *((_DWORD *)v2 + 13) == 1)
    && (v2[61] || v2[62] || v2[60] || v2[68]) )
  {
    CM_Combat::Event_CancelAttack();
    v4 = v2[48];
    v2[68] = 0;
    if ( v4 )
    {
      if ( *((_DWORD *)v2 + 13) == 1 )
        ClientCombatSystem::HidePowerBar((ClientCombatSystem *)v2);
    }
  }
  if ( ACCWeenieObject::selectedID == Formatted )
  {
    if ( BYTE2(v1->requestedAttackPower) )
    {
      BYTE2(v1->requestedAttackPower) = 0;
    }
    else
    {
      v5 = *(_DWORD *)&v1->jump_pending;
      if ( v5 == 2 || v5 == 4 )
      {
        v6 = CPlayerSystem::GetPlayerSystem();
        if ( (unsigned __int8)PlayerModule::AutoTarget((PlayerModule *)&v6->playerModule.vfptr) )
          ClientCombatSystem::AutoTarget((ClientCombatSystem *)v2);
      }
    }
  }
}

//----- (0056BE30) --------------------------------------------------------  // acclient.c:408786
void __thiscall ClientCombatSystem::SetCombatMode(ClientCombatSystem *this, COMBAT_MODE i_NewCombatMode, CaseInsensitiveStringBase<PStringBase<char> > i_bPlayerRequested)
{
  ClientCombatSystem *v3; // esi@1
  COMBAT_MODE v4; // edi@1
  COMBAT_MODE v5; // ebx@1
  CPlayerSystem *v6; // eax@4
  HashBaseData<unsigned long> *v7; // ebx@4
  char *v8; // edi@5
  PStringBase<unsigned short> *v9; // eax@5
  ClientUISystem *v10; // eax@11
  CPlayerSystem *v11; // eax@15
  char v12; // al@15
  COMBAT_MODE v13; // ST10_4@15
  COMBAT_MODE v14; // eax@15
  _Formatted v15; // ebp@17
  unsigned int v16; // edi@17
  unsigned int v17; // eax@18
  CPlayerSystem *v18; // eax@26
  unsigned int v19; // eax@28
  IACPlugin *v20; // eax@31
  bool *v21; // [sp-1Ch] [bp-20h]@5
  unsigned int v22; // [sp-18h] [bp-1Ch]@22
  bool v23; // [sp-14h] [bp-18h]@5
  PStringBase<unsigned short> result; // [sp+0h] [bp-4h]@1

  result.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v3 = this;
  v4 = i_NewCombatMode;
  v5 = this->combatMode;
  if ( i_NewCombatMode != v5 )
  {
    if ( (_BYTE)i_bPlayerRequested.m_charbuffer )
    {
      if ( !ClientCombatSystem::CompatibleCombatMode(i_NewCombatMode) )
      {
        v6 = CPlayerSystem::GetPlayerSystem();
        v7 = ClientObjMaintSystem::GetWeenieObject(v6->m_invSlotModule.weaponReadySlot->m_itemID);
        if ( !v7 )
          return;
        v8 = CombatEnumMapper::CombatModeToString((AC1Legacy::PStringBase<char> *)&i_NewCombatMode, v4)->m_buffer->m_data;
        v9 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v7, &result, NAME_APPROPRIATE, 0);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&i_bPlayerRequested,
          0,
          L"You can't enter %hs mode while wielding the %s",
          v8,
          v9->m_charbuffer);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&i_NewCombatMode);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        v23 = 1;
        v21 = (bool *)&i_bPlayerRequested;
        goto LABEL_8;
      }
      if ( CPlayerSystem::GetPlayerSystem()->teleportInProgress )
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&i_bPlayerRequested,
          L"You can't enter combat mode while in portal space");
        v23 = 1;
        v21 = (bool *)&i_bPlayerRequested;
LABEL_8:
        ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, (PStringBase<unsigned short> *)v21, 0x1Au, v23, 0);
        PStringBase<char>::~PStringBase<char>(&i_bPlayerRequested);
        return;
      }
      if ( !ClientCombatSystem::PlayerInReadyPosition(v3, 0) )
      {
        v3->pendingCombatMode = v4;
        return;
      }
    }
    v3->combatMode = v4;
    v10 = ClientUISystem::GetUISystem();
    ClientUISystem::UpdateCursorState(v10);
    if ( v3->m_bTrackingTarget )
      ClientCombatSystem::UpdateTargetTracking(v3);
    if ( (_BYTE)i_bPlayerRequested.m_charbuffer )
      CM_Combat::Event_ChangeCombatMode(v3->combatMode);
    v11 = CPlayerSystem::GetPlayerSystem();
    v12 = PlayerModule::AdvancedCombatUI((PlayerModule *)&v11->playerModule.vfptr);
    v13 = v3->combatMode;
    v3->m_bAdvancedCombatMode = v12;
    CM_Combat::SendNotice_SetCombatMode(v13);
    ClientCombatSystem::RegisterInputMaps(v3, v3->combatMode, v5);
    v14 = v3->combatMode;
    if ( v14 != 2 && v14 != 4 )
      goto LABEL_30;
    v15 = ACCWeenieObject::selectedID;
    v16 = ClientCombatSystem::GetAttackTarget();
    if ( SmartBox::smartbox )
      v17 = SmartBox::smartbox->player_id;
    else
      v17 = 0;
    if ( v15 != v17 )
    {
      if ( !ClientCombatSystem::ObjectIsAttackable(v16) )
      {
        v22 = 0;
LABEL_25:
        ACCWeenieObject::SetSelectedObject(v22, 0);
        goto LABEL_26;
      }
      if ( v15 != v16 )
      {
        v22 = v16;
        goto LABEL_25;
      }
    }
LABEL_26:
    v18 = CPlayerSystem::GetPlayerSystem();
    if ( (unsigned __int8)PlayerModule::AutoTarget((PlayerModule *)&v18->playerModule.vfptr) )
    {
      if ( !ClientCombatSystem::GetAttackTarget()
        || (v19 = ClientCombatSystem::GetAttackTarget(), !ClientCombatSystem::ObjectIsAttackable(v19)) )
        ClientCombatSystem::AutoTarget(v3);
    }
LABEL_30:
    if ( APIManager::APIIsReady() )
    {
      v20 = APIManager::GetACPlugin();
      ((void (__stdcall *)(IACPlugin *, COMBAT_MODE, COMBAT_MODE, _DWORD))v20->vfptr[3].Release)(
        v20,
        v5,
        v3->combatMode,
        (unsigned __int8)i_bPlayerRequested.m_charbuffer);
    }
  }
}

//----- (0056C040) --------------------------------------------------------  // acclient.c:408916
void __thiscall ClientCombatSystem::StartAttackRequest(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  unsigned int v2; // eax@1
  char *v3; // esi@4
  PStringBase<unsigned short> i_text; // [sp+0h] [bp-4h]@1

  i_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v1 = this;
  v2 = ClientCombatSystem::GetAttackTarget();
  if ( v1->m_bAdvancedCombatMode || v2 && ClientCombatSystem::ObjectIsAttackable(v2) )
  {
    v1->attackRequestInProgress = 1;
    LODWORD(v1->requestedAttackPower) = 1065353216;
    ((void (*)(void))SmartBox::smartbox->cmdinterp->vfptr[6].OnLoseFocus)();
    ((void (*)(void))SmartBox::smartbox->cmdinterp->vfptr[16].__vecDelDtor)();
    v1->currentBuildIsAutomatic = 0;
    ClientCombatSystem::AttemptStartBuildingAttack(v1);
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &i_text,
      L"You must select a valid combat target before attacking");
    ClientSystem::AddTextToScroll((ClientSystem *)&v1->vfptr, &i_text, 0x1Au, 1, 0);
    v3 = (char *)&i_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
  }
}

//----- (0056C0E0) --------------------------------------------------------  // acclient.c:408951
void __thiscall ClientCombatSystem::EndAttackRequest(ClientCombatSystem *this, ATTACK_HEIGHT _attackHeight, float _power)
{
  ClientCombatSystem *v3; // esi@1
  double v4; // st7@4
  float *v5; // eax@4
  float v6; // eax@10
  float powerBarLevel; // [sp+0h] [bp-4h]@1

  powerBarLevel = *(float *)&this;
  v3 = this;
  if ( this->attackRequestInProgress )
  {
    this->attackRequestInProgress = 0;
    powerBarLevel = ClientCombatSystem::GetPowerBarLevel(this);
    if ( _power == -1.0 )
    {
      if ( v3->m_bAdvancedCombatMode )
      {
        v3->requestedAttackPower = powerBarLevel;
      }
      else
      {
        v4 = v3->m_rUIRequestedPower;
        _power = v3->m_rUIRequestedPower;
        v5 = &powerBarLevel;
        if ( v4 >= powerBarLevel )
          v5 = &_power;
        LODWORD(v3->requestedAttackPower) = *(_DWORD *)v5;
      }
    }
    else
    {
      v3->requestedAttackPower = _power;
    }
    if ( v3->attackServerResponsePending )
    {
      v6 = v3->requestedAttackPower;
      v3->attackWhenResponseReceived = 1;
      v3->attackWhenResponseReceived_Power = v6;
    }
    else if ( v3->m_bAdvancedCombatMode || v3->m_rUIRequestedPower <= (double)powerBarLevel || v3->repeatAttacking )
    {
      ClientCombatSystem::ExecuteAttack(v3, _attackHeight, 1);
      if ( !v3->m_bAdvancedCombatMode && v3->requestedAttackPower > (double)v3->m_rUIRequestedPower )
      {
        v3->requestedAttackPower = v3->m_rUIRequestedPower;
        ClientCombatSystem::ExecuteAttack(v3, _attackHeight, 1);
      }
    }
  }
}

//----- (0056C1B0) --------------------------------------------------------  // acclient.c:409004
void __thiscall ClientCombatSystem::OnQualityChanged(ClientCombatSystem *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  ClientCombatSystem *v4; // esi@1

  v4 = this;
  if ( CBaseQualities::InqInt((CBaseQualities *)&cwobj[4].vfptr[2].GetNoticeHandlers, 0x28u, (int *)&cwobj, 0, 0) )
    ClientCombatSystem::SetCombatMode((ClientCombatSystem *)((char *)v4 - 12), (COMBAT_MODE)cwobj, 0);
}

//----- (0056C1F0) --------------------------------------------------------  // acclient.c:409014
void __thiscall ClientCombatSystem::UseTime(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  signed int v2; // eax@2
  float *v3; // eax@10
  CPlayerSystem *v4; // eax@14
  float newPowerLevel; // [sp+0h] [bp-4h]@1

  newPowerLevel = *(float *)&this;
  v1 = this;
  if ( this->buildInProgress )
  {
    newPowerLevel = ClientCombatSystem::GetPowerBarLevel(this);
    v2 = v1->powerBarMode;
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        if ( ClientCombatSystem::PlayerInReadyPosition(v1, 1) )
        {
          if ( v1->attackRequestInProgress
            || v1->m_bAdvancedCombatMode
            || newPowerLevel < (double)v1->requestedAttackPower )
          {
            ClientCombatSystem::SetPowerBarLevel(v1, newPowerLevel);
          }
          else
          {
            v3 = (float *)_STL::min(&v1->requestedAttackPower, &newPowerLevel);
            ClientCombatSystem::SetPowerBarLevel(v1, *v3);
            if ( v1->currentBuildIsAutomatic )
            {
              v1->buildInProgress = 0;
              LODWORD(v1->buildStartTime) = 0;
              HIDWORD(v1->buildStartTime) = 0;
            }
            else
            {
              ClientCombatSystem::ExecuteAttack(v1, v1->requestedAttackHeight, 1);
            }
          }
        }
        else
        {
          v4 = CPlayerSystem::GetPlayerSystem();
          if ( (unsigned __int8)PlayerModule::AutoRepeatAttack((PlayerModule *)&v4->playerModule.vfptr) )
          {
            CM_Combat::Event_CancelAttack();
            v1->repeatAttacking = 0;
          }
          if ( v1->attackRequestInProgress )
          {
            v1->buildInProgress = 0;
            LODWORD(v1->buildStartTime) = 0;
            HIDWORD(v1->buildStartTime) = 0;
            ClientCombatSystem::SetPowerBarLevel(v1, 0.0);
          }
          else
          {
            ClientCombatSystem::HidePowerBar(v1);
          }
        }
      }
      else if ( v2 == 3 )
      {
        ClientCombatSystem::SetPowerBarLevel(v1, newPowerLevel);
      }
    }
  }
  if ( v1->attackRequestInProgress && !v1->buildInProgress && !v1->attackServerResponsePending )
    ClientCombatSystem::AttemptStartBuildingAttack(v1);
  if ( v1->pendingCombatMode )
  {
    if ( ClientCombatSystem::PlayerInReadyPosition(v1, 0) )
    {
      ClientCombatSystem::SetCombatMode(v1, v1->pendingCombatMode, (CaseInsensitiveStringBase<PStringBase<char> >)1);
      v1->pendingCombatMode = 0;
    }
  }
}

//----- (0056C320) --------------------------------------------------------  // acclient.c:409096
int __thiscall ClientCombatSystem::HandlePlayerDeathEvent(ClientCombatSystem *this, void *buff, unsigned int size)
{
  ClientSystem *v3; // edi@1
  unsigned int v4; // esi@2
  AC1Legacy::PSRefBuffer<char> *v5; // esi@5
  int result; // eax@8
  AC1Legacy::PSRefBuffer<char> *v7; // esi@11
  AC1Legacy::PStringBase<char> msg; // [sp+0h] [bp-4h]@1

  msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)this;
  v3 = (ClientSystem *)this;
  if ( SmartBox::smartbox )
    v4 = SmartBox::smartbox->player_id;
  else
    v4 = 0;
  msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  if ( AC1Legacy::PStringBase<char>::UnPack(&msg, &buff, size) )
  {
    if ( v4 == *(_DWORD *)buff || v4 == *((_DWORD *)buff + 1) )
    {
      v7 = msg.m_buffer;
    }
    else
    {
      v7 = msg.m_buffer;
      if ( msg.m_buffer->m_len != 1 )
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&buff, "\n");
        AC1Legacy::PStringBase<char>::operator+=(&msg, (AC1Legacy::PStringBase<char> *)&buff);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&buff);
        v7 = msg.m_buffer;
        ClientSystem::AddTextToScroll(v3, msg.m_buffer->m_data, 0, 1, 0);
      }
    }
    if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) && v7 )
      v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
    result = 1;
  }
  else
  {
    v5 = msg.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer->m_cRef) )
    {
      if ( v5 )
        v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
    }
    result = 0;
  }
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0056C410) --------------------------------------------------------  // acclient.c:409150
int __thiscall ClientCombatSystem::HandleVictimNotificationEvent(ClientCombatSystem *this, void *buff, unsigned int size)
{
  ClientSystem *v3; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@2
  int result; // eax@5
  AC1Legacy::PSRefBuffer<char> *v6; // edi@6
  unsigned int v7; // esi@7
  int v8; // eax@7
  AC1Legacy::PStringBase<char> msg; // [sp+0h] [bp-4h]@1

  msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v3 = (ClientSystem *)this;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  if ( AC1Legacy::PStringBase<char>::UnPack(&msg, &buff, size) )
  {
    v6 = msg.m_buffer;
    if ( msg.m_buffer->m_len != 1 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&size, "\n");
      v7 = size;
      v8 = *(_DWORD *)(size + 8);
      if ( v8 != 1 && size != AC1Legacy::PStringBase<char>::s_NullBuffer )
      {
        AC1Legacy::PStringBase<char>::append_n_chars(&msg, (const char *)(size + 20), v8 - 1);
        v6 = msg.m_buffer;
      }
      if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      ClientSystem::AddTextToScroll(v3, v6->m_data, 0, 1, 0);
    }
    if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    result = 1;
  }
  else
  {
    v4 = msg.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer->m_cRef) )
    {
      if ( v4 )
        v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
    }
    result = 0;
  }
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0056C500) --------------------------------------------------------  // acclient.c:409199
void __thiscall ClientCombatSystem::HandleAttackDoneEvent(ClientCombatSystem *this, const unsigned int etype)
{
  ClientCombatSystem *v2; // esi@1
  ClientUISystem *v3; // eax@2
  CPlayerSystem *v4; // eax@8
  ATTACK_HEIGHT v5; // ST00_4@11
  CPlayerSystem *v6; // eax@12
  PowerBarMode v7; // eax@16

  v2 = this;
  if ( this->attackInProgress )
  {
    v3 = ClientUISystem::GetUISystem();
    ClientUISystem::DecrementBusyCount(v3);
    v2->attackInProgress = 0;
  }
  v2->attackServerResponsePending = 0;
  ACCWeenieObject::attackInProgress = 0;
  if ( etype && v2->repeatAttacking )
    ClientCombatSystem::AbortAutomaticAttack(v2);
  if ( !v2->attackRequestInProgress && !v2->m_bAdvancedCombatMode )
  {
    v4 = CPlayerSystem::GetPlayerSystem();
    if ( (unsigned __int8)PlayerModule::AutoRepeatAttack((PlayerModule *)&v4->playerModule.vfptr) )
    {
      if ( v2->repeatAttacking && fabs(v2->requestedAttackPower - v2->m_rUIRequestedPower) > 0.0099999998 )
      {
        v5 = v2->requestedAttackHeight;
        v2->requestedAttackPower = v2->m_rUIRequestedPower;
        ClientCombatSystem::ExecuteAttack(v2, v5, 0);
      }
    }
  }
  v6 = CPlayerSystem::GetPlayerSystem();
  if ( !(unsigned __int8)PlayerModule::AutoRepeatAttack((PlayerModule *)&v6->playerModule.vfptr) || !v2->repeatAttacking )
  {
    v7 = v2->powerBarMode;
    v2->repeatAttacking = 0;
    if ( v7 != 3 )
    {
      v2->buildInProgress = 0;
      LODWORD(v2->buildStartTime) = 0;
      HIDWORD(v2->buildStartTime) = 0;
      if ( v7 == 1 )
        CM_Character::SendNotice_SetPowerbarLevel(PBM_COMBAT, 0.0);
      else
        CM_Character::SendNotice_FinishPowerbar(v7);
      v2->powerBarMode = 0;
    }
LABEL_21:
    if ( !v2->attackRequestInProgress )
      goto LABEL_25;
    goto LABEL_22;
  }
  if ( !v2->attackRequestInProgress )
  {
    ClientCombatSystem::StartPowerBarBuild(v2);
    v2->currentBuildIsAutomatic = 1;
    goto LABEL_21;
  }
LABEL_22:
  if ( !v2->buildInProgress && !v2->attackServerResponsePending )
    ClientCombatSystem::AttemptStartBuildingAttack(v2);
LABEL_25:
  if ( v2->attackWhenResponseReceived )
  {
    ClientCombatSystem::StartAttackRequest(v2);
    ClientCombatSystem::EndAttackRequest(v2, v2->requestedAttackHeight, v2->attackWhenResponseReceived_Power);
    v2->attackWhenResponseReceived = 0;
    LODWORD(v2->attackWhenResponseReceived_Power) = 0;
  }
}
// 870ED0: using guessed type int ACCWeenieObject::attackInProgress;

//----- (0056C620) --------------------------------------------------------  // acclient.c:409274
void __thiscall ClientCombatSystem::HandleEvasionDefenderNotificationEvent(ClientCombatSystem *this, AC1Legacy::PStringBase<char> *attackers_name)
{
  AC1Legacy::PSRefBuffer<char> *v2; // eax@1
  unsigned int v3; // ecx@1
  AC1Legacy::PStringBase<char> *v4; // esi@4
  AC1Legacy::PSRefBuffer<char> *v5; // eax@4
  int v6; // eax@9
  AC1Legacy::PStringBase<char> *v7; // esi@9
  bool v8; // bl@9
  AC1Legacy::PSRefBuffer<char> *v9; // edi@12
  ClientSystem *v10; // ebx@13
  AC1Legacy::PStringBase<char> *v11; // esi@13
  unsigned int v12; // ecx@17
  NoticeHandlerVtbl *v13; // eax@17
  CPlayerSystem *v14; // eax@19
  AC1Legacy::PStringBase<char> msg; // [sp+8h] [bp-8h]@1
  ClientSystem *v16; // [sp+Ch] [bp-4h]@1

  v16 = (ClientSystem *)this;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&msg, "You evaded ");
  v2 = attackers_name->m_buffer;
  v3 = attackers_name->m_buffer->m_len;
  if ( v3 != 1 && v2 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(&msg, v2->m_data, v3 - 1);
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&attackers_name, "!\n");
  v4 = attackers_name;
  v5 = attackers_name[2].m_buffer;
  if ( v5 != (AC1Legacy::PSRefBuffer<char> *)1
    && attackers_name != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(
      &msg,
      (const char *)&attackers_name[5],
      (unsigned int)&v5[-1].m_data[3]);
  if ( !InterlockedDecrement((volatile LONG *)&v4[1]) )
    ((void (__thiscall *)(_DWORD, _DWORD))v4->m_buffer->vfptr)(v4, 1);
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&attackers_name, &name);
  v6 = gmCCommunicationSystem::IsSquelched(0, (AC1Legacy::PStringBase<char> *)&attackers_name, 6u);
  v7 = attackers_name;
  v8 = v6 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&attackers_name[1]) && v7 )
    ((void (__thiscall *)(_DWORD, _DWORD))v7->m_buffer->vfptr)(v7, 1);
  v9 = msg.m_buffer;
  if ( v8 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&attackers_name,
      0,
      msg.m_buffer->m_data);
    v10 = v16;
    ClientSystem::AddTextToScroll(v16, (PStringBase<unsigned short> *)&attackers_name, 0x15u, 1, 0);
    v11 = attackers_name - 5;
    if ( !InterlockedDecrement((volatile LONG *)&attackers_name[-4]) && v11 )
      ((void (__thiscall *)(_DWORD, _DWORD))v11->m_buffer->vfptr)(v11, 1);
  }
  else
  {
    v10 = v16;
  }
  v12 = Timer::cur_time.Param;
  v10[11].vfptr = (InterfaceVtbl *)Timer::cur_time.Cmd;
  v13 = v10[3].vfptr;
  v10[11].vfptr = (NoticeHandlerVtbl *)v12;
  if ( v13 == (NoticeHandlerVtbl *)2 || v13 == (NoticeHandlerVtbl *)4 )
  {
    v14 = CPlayerSystem::GetPlayerSystem();
    if ( (unsigned __int8)PlayerModule::AutoTarget((PlayerModule *)&v14->playerModule.vfptr) )
    {
      if ( ACCWeenieObject::selectedID == Formatted )
        ClientCombatSystem::AutoTarget((ClientCombatSystem *)v10);
    }
  }
  if ( !InterlockedDecrement((volatile LONG *)&v9->m_cRef) )
  {
    if ( v9 )
      v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0056C7A0) --------------------------------------------------------  // acclient.c:409354
void __thiscall ClientCombatSystem::HandleEvasionAttackerNotificationEvent(ClientCombatSystem *this, AC1Legacy::PStringBase<char> *defenders_name)
{
  void *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1
  unsigned int v4; // eax@1
  int v5; // eax@6
  AC1Legacy::PStringBase<char> *v6; // esi@6
  bool v7; // bl@6
  AC1Legacy::PStringBase<char> *v8; // esi@10
  AC1Legacy::PStringBase<char> v9; // [sp+Ch] [bp-8h]@1
  ClientSystem *v10; // [sp+10h] [bp-4h]@1

  v2 = defenders_name->m_buffer;
  v10 = (ClientSystem *)this;
  defenders_name = (AC1Legacy::PStringBase<char> *)v2;
  InterlockedIncrement((volatile LONG *)v2 + 1);
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v9, " evaded your attack.\n");
  v3 = v9.m_buffer;
  v4 = v9.m_buffer->m_len;
  if ( v4 != 1 && v9.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    AC1Legacy::PStringBase<char>::append_n_chars(
      (AC1Legacy::PStringBase<char> *)&defenders_name,
      v9.m_buffer->m_data,
      v4 - 1);
    v2 = defenders_name;
  }
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&defenders_name, &name);
  v5 = gmCCommunicationSystem::IsSquelched(0, (AC1Legacy::PStringBase<char> *)&defenders_name, 6u);
  v6 = defenders_name;
  v7 = v5 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&defenders_name[1]) && v6 )
    ((void (__thiscall *)(_DWORD, _DWORD))v6->m_buffer->vfptr)(v6, 1);
  if ( v7 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&defenders_name,
      0,
      (const char *)v2 + 20);
    ClientSystem::AddTextToScroll(v10, (PStringBase<unsigned short> *)&defenders_name, 0x16u, 1, 0);
    v8 = defenders_name - 5;
    if ( !InterlockedDecrement((volatile LONG *)&defenders_name[-4]) )
    {
      if ( v8 )
        ((void (__thiscall *)(_DWORD, _DWORD))v8->m_buffer->vfptr)(v8, 1);
    }
  }
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) )
  {
    if ( v2 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0056C8C0) --------------------------------------------------------  // acclient.c:409412
void __thiscall ClientCombatSystem::ToggleCombatMode(ClientCombatSystem *this)
{
  ClientCombatSystem *v1; // esi@1
  signed int v2; // eax@2

  v1 = this;
  if ( this->combatMode == 1 )
  {
    v2 = ClientCombatSystem::GetDefaultCombatMode(this, 0);
    ClientCombatSystem::SetCombatMode(v1, (COMBAT_MODE)v2, (CaseInsensitiveStringBase<PStringBase<char> >)1);
  }
  else
  {
    ClientCombatSystem::SetCombatMode(this, NONCOMBAT_COMBAT_MODE, (CaseInsensitiveStringBase<PStringBase<char> >)1);
  }
}

//----- (0056C8F0) --------------------------------------------------------  // acclient.c:409430
void __thiscall ClientCombatSystem::SetRequestedAttackHeight(ClientCombatSystem *this, ATTACK_HEIGHT _height)
{
  bool v2; // dl@1

  v2 = this->requestedAttackHeight != _height;
  this->requestedAttackHeight = _height;
  if ( v2 || !this->attackRequestInProgress )
    ClientCombatSystem::StartAttackRequest(this);
}

//----- (0056C920) --------------------------------------------------------  // acclient.c:409441
void __thiscall ClientCombatSystem::HandleDefenderNotificationEvent(ClientCombatSystem *this, AC1Legacy::PStringBase<char> *attackers_name, DAMAGE_TYPE dtype, const long double php, const int hp, const int part, const int critical, const __int64 attack_conditions)
{
  char v8; // bl@1
  AC1Legacy::PSRefBuffer<char> *v9; // eax@2
  char *v10; // edi@5
  char *v11; // edi@10
  char *v12; // edi@14
  int v13; // edi@18
  int v14; // ebx@23
  int v15; // eax@26
  int v16; // eax@26
  int v17; // ecx@26
  PSRefBufferCharData<char> *v18; // edi@29
  int v19; // eax@33
  int v20; // eax@33
  int v21; // ecx@33
  PSRefBufferCharData<char> *v22; // edi@36
  AC1Legacy::PStringBase<char> *v23; // eax@40
  AC1Legacy::PStringBase<char> *v24; // ST64_4@40
  AC1Legacy::PStringBase<char> *v25; // eax@40
  AC1Legacy::PStringBase<char> *v26; // ST54_4@40
  AC1Legacy::PStringBase<char> *v27; // eax@40
  AC1Legacy::PStringBase<char> *v28; // ST44_4@40
  AC1Legacy::PStringBase<char> *v29; // eax@40
  AC1Legacy::PStringBase<char> *v30; // ST34_4@40
  AC1Legacy::PStringBase<char> *v31; // eax@40
  AC1Legacy::PStringBase<char> *v32; // ST24_4@40
  AC1Legacy::PStringBase<char> *v33; // eax@40
  AC1Legacy::PStringBase<char> *v34; // ST14_4@40
  AC1Legacy::PStringBase<char> *v35; // eax@40
  AC1Legacy::PStringBase<char> *v36; // eax@40
  AC1Legacy::PStringBase<char> *v37; // eax@40
  AC1Legacy::PStringBase<char> *v38; // eax@40
  AC1Legacy::PStringBase<char> *v39; // eax@40
  AC1Legacy::PStringBase<char> *v40; // eax@40
  AC1Legacy::PStringBase<char> *v41; // eax@40
  AC1Legacy::PStringBase<char> *v42; // eax@40
  AC1Legacy::PStringBase<char> *v43; // eax@40
  AC1Legacy::PStringBase<char> *v44; // eax@40
  AC1Legacy::PStringBase<char> *v45; // eax@40
  AC1Legacy::PSRefBuffer<char> **v46; // edi@40
  AC1Legacy::PSRefBuffer<char> *v47; // esi@45
  AC1Legacy::PSRefBuffer<char> *v48; // esi@48
  AC1Legacy::PSRefBuffer<char> *v49; // esi@51
  AC1Legacy::PSRefBuffer<char> *v50; // esi@54
  AC1Legacy::PSRefBuffer<char> *v51; // esi@57
  AC1Legacy::PSRefBuffer<char> *v52; // esi@60
  AC1Legacy::PSRefBuffer<char> *v53; // esi@63
  AC1Legacy::PSRefBuffer<char> *v54; // esi@66
  AC1Legacy::PSRefBuffer<char> *v55; // esi@69
  AC1Legacy::PSRefBuffer<char> *v56; // esi@72
  AC1Legacy::PSRefBuffer<char> *v57; // esi@75
  AC1Legacy::PSRefBuffer<char> *v58; // esi@78
  AC1Legacy::PSRefBuffer<char> *v59; // esi@81
  AC1Legacy::PSRefBuffer<char> *v60; // esi@84
  AC1Legacy::PSRefBuffer<char> *v61; // esi@87
  AC1Legacy::PSRefBuffer<char> *v62; // esi@93
  PSRefBufferCharData<char> *v63; // esi@96
  AC1Legacy::PSRefBuffer<char> *v64; // esi@99
  AC1Legacy::PSRefBuffer<char> *v65; // esi@102
  AC1Legacy::PSRefBuffer<char> *v66; // esi@105
  PSRefBufferCharData<char> *v67; // esi@108
  AC1Legacy::PStringBase<char> *v68; // eax@109
  AC1Legacy::PStringBase<char> *v69; // ST64_4@109
  AC1Legacy::PStringBase<char> *v70; // eax@109
  AC1Legacy::PStringBase<char> *v71; // ST54_4@109
  AC1Legacy::PStringBase<char> *v72; // eax@109
  AC1Legacy::PStringBase<char> *v73; // ST44_4@109
  AC1Legacy::PStringBase<char> *v74; // eax@109
  AC1Legacy::PStringBase<char> *v75; // ST34_4@109
  AC1Legacy::PStringBase<char> *v76; // eax@109
  AC1Legacy::PStringBase<char> *v77; // ST2C_4@109
  AC1Legacy::PStringBase<char> *v78; // eax@109
  AC1Legacy::PStringBase<char> *v79; // ST1C_4@109
  AC1Legacy::PStringBase<char> *v80; // eax@109
  AC1Legacy::PStringBase<char> *v81; // eax@109
  AC1Legacy::PStringBase<char> *v82; // eax@109
  AC1Legacy::PStringBase<char> *v83; // eax@109
  AC1Legacy::PStringBase<char> *v84; // eax@109
  AC1Legacy::PStringBase<char> *v85; // eax@109
  AC1Legacy::PStringBase<char> *v86; // eax@109
  AC1Legacy::PStringBase<char> *v87; // eax@109
  AC1Legacy::PStringBase<char> *v88; // eax@109
  AC1Legacy::PStringBase<char> *v89; // eax@109
  AC1Legacy::PSRefBuffer<char> **v90; // edi@109
  AC1Legacy::PSRefBuffer<char> *v91; // esi@114
  AC1Legacy::PSRefBuffer<char> *v92; // esi@117
  AC1Legacy::PSRefBuffer<char> *v93; // esi@120
  AC1Legacy::PSRefBuffer<char> *v94; // esi@123
  volatile LONG *v95; // esi@126
  AC1Legacy::PSRefBuffer<char> *v96; // esi@129
  AC1Legacy::PSRefBuffer<char> *v97; // esi@132
  AC1Legacy::PSRefBuffer<char> *v98; // esi@135
  AC1Legacy::PSRefBuffer<char> *v99; // esi@138
  AC1Legacy::PSRefBuffer<char> *v100; // esi@141
  AC1Legacy::PSRefBuffer<char> *v101; // esi@144
  PSRefBufferCharData<char> *v102; // esi@147
  AC1Legacy::PSRefBuffer<char> *v103; // esi@150
  AC1Legacy::PSRefBuffer<char> *v104; // esi@153
  AC1Legacy::PSRefBuffer<char> *v105; // esi@156
  PSRefBufferCharData<char> *v106; // esi@159
  AC1Legacy::PSRefBuffer<char> *v107; // esi@162
  AC1Legacy::PSRefBuffer<char> *v108; // esi@165
  AC1Legacy::PSRefBuffer<char> *v109; // esi@168
  int v110; // eax@175
  PSRefBufferCharData<char> *v111; // esi@175
  bool v112; // bl@175
  AC1Legacy::PSRefBuffer<char> *v113; // esi@180
  unsigned int v114; // eax@180
  AC1Legacy::PSRefBuffer<char> *v115; // esi@185
  unsigned int v116; // eax@185
  ClientSystem *v117; // edi@190
  char *v118; // esi@190
  unsigned int v119; // edx@194
  NoticeHandlerVtbl *v120; // eax@194
  CPlayerSystem *v121; // eax@196
  AC1Legacy::PSRefBuffer<char> *v122; // esi@199
  AC1Legacy::PSRefBuffer<char> *v123; // esi@202
  AC1Legacy::PSRefBuffer<char> *v124; // esi@205
  AC1Legacy::PSRefBuffer<char> *v125; // esi@208
  char *v126; // esi@211
  AC1Legacy::PSRefBuffer<char> *v127; // esi@214
  AC1Legacy::PSRefBuffer<char> *v128; // esi@217
  AC1Legacy::PSRefBuffer<char> *v129; // esi@220
  PStringBase<char> result; // [sp+78h] [bp-1C0h]@3
  AC1Legacy::PStringBase<char> msg; // [sp+7Ch] [bp-1BCh]@4
  PStringBase<char> rhs; // [sp+80h] [bp-1B8h]@3
  PStringBase<char> damageType; // [sp+84h] [bp-1B4h]@1
  int conversionWorked; // [sp+88h] [bp-1B0h]@2
  AC1Legacy::PStringBase<char> v135; // [sp+8Ch] [bp-1ACh]@1
  AC1Legacy::PStringBase<char> crit_string; // [sp+90h] [bp-1A8h]@23
  AC1Legacy::PStringBase<char> plural; // [sp+94h] [bp-1A4h]@1
  AC1Legacy::PStringBase<char> s; // [sp+98h] [bp-1A0h]@1
  AC1Legacy::PStringBase<char> v139; // [sp+9Ch] [bp-19Ch]@40
  AC1Legacy::PStringBase<char> v140; // [sp+A0h] [bp-198h]@40
  AC1Legacy::PStringBase<char> v141; // [sp+A4h] [bp-194h]@40
  AC1Legacy::PStringBase<char> v142; // [sp+A8h] [bp-190h]@40
  AC1Legacy::PStringBase<char> v143; // [sp+ACh] [bp-18Ch]@40
  AC1Legacy::PStringBase<char> v144; // [sp+B0h] [bp-188h]@40
  AC1Legacy::PStringBase<char> v145; // [sp+B4h] [bp-184h]@40
  AC1Legacy::PStringBase<char> v146; // [sp+B8h] [bp-180h]@40
  AC1Legacy::PStringBase<char> v147; // [sp+BCh] [bp-17Ch]@40
  AC1Legacy::PStringBase<char> v148; // [sp+C0h] [bp-178h]@40
  AC1Legacy::PStringBase<char> v149; // [sp+C4h] [bp-174h]@40
  AC1Legacy::PStringBase<char> printable_body_part; // [sp+C8h] [bp-170h]@23
  volatile LONG *lpAddend; // [sp+CCh] [bp-16Ch]@40
  AC1Legacy::PStringBase<char> v152; // [sp+D0h] [bp-168h]@40
  AC1Legacy::PStringBase<char> v153; // [sp+D4h] [bp-164h]@40
  AC1Legacy::PStringBase<char> v154; // [sp+D8h] [bp-160h]@40
  AC1Legacy::PStringBase<char> v155; // [sp+DCh] [bp-15Ch]@40
  AC1Legacy::PStringBase<char> body_part; // [sp+E0h] [bp-158h]@23
  AC1Legacy::PStringBase<char> dummy; // [sp+E4h] [bp-154h]@1
  AC1Legacy::PStringBase<char> v158; // [sp+E8h] [bp-150h]@40
  ClientSystem *v159; // [sp+ECh] [bp-14Ch]@1
  AC1Legacy::PStringBase<char> v160; // [sp+F0h] [bp-148h]@40
  AC1Legacy::PStringBase<char> v161; // [sp+F4h] [bp-144h]@40
  char dtmsg[64]; // [sp+F8h] [bp-140h]@1
  char rbuf[256]; // [sp+138h] [bp-100h]@23

  v135.m_buffer = 0;
  dummy.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v159 = (ClientSystem *)this;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  plural.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  s.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  CombatSystem::InqCombatHitAdjectives(dtype, php, &dummy, &plural);
  AppraisalSystem::DamageTypeToString(dtype, dtmsg, 0x40u);
  PStringBase<char>::PStringBase<char>(&damageType, dtmsg);
  PStringBase<char>::break_reference(&damageType);
  __strlwr(damageType.m_charbuffer->m_data);
  v8 = 1;
  if ( *(_DWORD *)&damageType.m_charbuffer[-1].m_data[12] == 1 )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&conversionWorked, &name);
  }
  else
  {
    PStringBase<char>::PStringBase<char>(&rhs, " ");
    v8 = 6;
    v9 = (AC1Legacy::PSRefBuffer<char> *)PStringBase<char>::operator+(&damageType, &result, &rhs);
  }
  msg.m_buffer = v9;
  if ( damageType.m_charbuffer != (PSRefBufferCharData<char> *)v9->vfptr )
  {
    v10 = &damageType.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&damageType.m_charbuffer[-1]) && v10 )
      (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
    damageType.m_charbuffer = (PSRefBufferCharData<char> *)msg.m_buffer->vfptr;
    InterlockedIncrement((volatile LONG *)&damageType.m_charbuffer[-1]);
  }
  if ( v8 & 4 )
  {
    v11 = &result.m_charbuffer[-2].m_data[12];
    v8 &= 0xFBu;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) )
    {
      if ( v11 )
        (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
    }
  }
  if ( v8 & 2 )
  {
    v12 = &rhs.m_charbuffer[-2].m_data[12];
    v8 &= 0xFDu;
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) )
    {
      if ( v12 )
        (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    }
  }
  if ( v8 & 1 )
  {
    v13 = conversionWorked - 20;
    if ( !InterlockedDecrement((volatile LONG *)(conversionWorked - 20 + 4)) )
    {
      if ( v13 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
    }
  }
  if ( hp != 1 )
    AC1Legacy::PStringBase<char>::set(&s, "s");
  rbuf[0] = 0;
  memset(&rbuf[1], 0, 0xFCu);
  *(_WORD *)&rbuf[253] = 0;
  rbuf[255] = 0;
  printable_body_part.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v14 = AC1Legacy::PStringBase<char>::s_NullBuffer;
  msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  BodyPartEnumMapper::BodyPartToString(part, rbuf, 0x100u);
  AC1Legacy::PStringBase<char>::PStringBase<char>(&body_part, rbuf);
  conversionWorked = EmapToDisplay::LowerCaseRemoveUnderscores(&body_part, &printable_body_part);
  crit_string.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  if ( critical )
    AC1Legacy::PStringBase<char>::set(&crit_string, "Critical hit! ");
  if ( attack_conditions & 4 )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&result, "Sneak Attack! ");
    v16 = *(_DWORD *)v15;
    v17 = *(_DWORD *)(v16 + 8);
    if ( v17 != 1 && v16 != AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(&crit_string, (const char *)(v16 + 20), v17 - 1);
    v18 = result.m_charbuffer;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer->m_data[4]) && v18 )
      (**(void (__thiscall ***)(PSRefBufferCharData<char> *, signed int))&v18->m_data[0])(v18, 1);
  }
  if ( attack_conditions & 2 )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&result, "Reckless! ");
    v20 = *(_DWORD *)v19;
    v21 = *(_DWORD *)(v20 + 8);
    if ( v21 != 1 && v20 != AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(&crit_string, (const char *)(v20 + 20), v21 - 1);
    v22 = result.m_charbuffer;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer->m_data[4]) && v22 )
      (**(void (__thiscall ***)(PSRefBufferCharData<char> *, signed int))&v22->m_data[0])(v22, 1);
  }
  if ( conversionWorked )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(
      (AC1Legacy::PStringBase<char> *)&result,
      damageType.m_charbuffer->m_data);
    rhs.m_charbuffer = (PSRefBufferCharData<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    AC1Legacy::PStringBase<char>::operator=((AC1Legacy::PStringBase<char> *)&rhs, hp);
    conversionWorked = (int)printable_body_part.m_buffer;
    lpAddend = (volatile LONG *)&printable_body_part.m_buffer->m_cRef;
    InterlockedIncrement((volatile LONG *)&printable_body_part.m_buffer->m_cRef);
    v158.m_buffer = attackers_name->m_buffer;
    InterlockedIncrement((volatile LONG *)&v158.m_buffer->m_cRef);
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v135, "damage!");
    v24 = v23;
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v152, " of ");
    v26 = v25;
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v155, " point");
    v28 = v27;
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v153, " for ");
    v30 = v29;
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v149, " your ");
    v32 = v31;
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v147, " ");
    v34 = v33;
    v35 = AC1Legacy::PStringBase<char>::operator+(&crit_string, &v145, &v158);
    v36 = AC1Legacy::PStringBase<char>::operator+(v35, &v143, v34);
    v37 = AC1Legacy::PStringBase<char>::operator+(v36, &v141, &plural);
    v38 = AC1Legacy::PStringBase<char>::operator+(v37, &v140, v32);
    v39 = AC1Legacy::PStringBase<char>::operator+(v38, &v142, (AC1Legacy::PStringBase<char> *)&conversionWorked);
    v40 = AC1Legacy::PStringBase<char>::operator+(v39, &v148, v30);
    v41 = AC1Legacy::PStringBase<char>::operator+(v40, &v154, (AC1Legacy::PStringBase<char> *)&rhs);
    v42 = AC1Legacy::PStringBase<char>::operator+(v41, &v146, v28);
    v43 = AC1Legacy::PStringBase<char>::operator+(v42, &v139, &s);
    v44 = AC1Legacy::PStringBase<char>::operator+(v43, &v144, v26);
    v45 = AC1Legacy::PStringBase<char>::operator+(v44, &v161, (AC1Legacy::PStringBase<char> *)&result);
    v46 = (AC1Legacy::PSRefBuffer<char> **)AC1Legacy::PStringBase<char>::operator+(v45, &v160, v24);
    if ( (AC1Legacy::PSRefBuffer<char> *)v14 != *v46 )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v14 + 4)) && v14 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
      msg.m_buffer = *v46;
      InterlockedIncrement((volatile LONG *)&msg.m_buffer->m_cRef);
    }
    v47 = v160.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v160.m_buffer->m_cRef) && v47 )
      v47->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v47, 1u);
    v48 = v161.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v161.m_buffer->m_cRef) && v48 )
      v48->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v48, 1u);
    v49 = v144.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v144.m_buffer->m_cRef) && v49 )
      v49->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v49, 1u);
    v50 = v139.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v139.m_buffer->m_cRef) && v50 )
      v50->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v50, 1u);
    v51 = v146.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v146.m_buffer->m_cRef) && v51 )
      v51->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v51, 1u);
    v52 = v154.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v154.m_buffer->m_cRef) && v52 )
      v52->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v52, 1u);
    v53 = v148.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v148.m_buffer->m_cRef) && v53 )
      v53->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v53, 1u);
    v54 = v142.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v142.m_buffer->m_cRef) && v54 )
      v54->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v54, 1u);
    v55 = v140.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v140.m_buffer->m_cRef) && v55 )
      v55->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v55, 1u);
    v56 = v141.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v141.m_buffer->m_cRef) && v56 )
      v56->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v56, 1u);
    v57 = v143.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v143.m_buffer->m_cRef) && v57 )
      v57->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v57, 1u);
    v58 = v145.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v145.m_buffer->m_cRef) && v58 )
      v58->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v58, 1u);
    v59 = v158.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v158.m_buffer->m_cRef) && v59 )
      v59->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v59, 1u);
    v60 = v147.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v147.m_buffer->m_cRef) && v60 )
      v60->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v60, 1u);
    v61 = v149.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v149.m_buffer->m_cRef) && v61 )
      v61->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v61, 1u);
    if ( !InterlockedDecrement(lpAddend) && conversionWorked )
      (**(void (__stdcall ***)(_DWORD))conversionWorked)(1);
    v62 = v153.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v153.m_buffer->m_cRef) && v62 )
      v62->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v62, 1u);
    v63 = rhs.m_charbuffer;
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer->m_data[4]) && v63 )
      (**(void (__thiscall ***)(PSRefBufferCharData<char> *, signed int))&v63->m_data[0])(v63, 1);
    v64 = v155.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v155.m_buffer->m_cRef) && v64 )
      v64->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v64, 1u);
    v65 = v152.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v152.m_buffer->m_cRef) && v65 )
      v65->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v65, 1u);
    v66 = v135.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v135.m_buffer->m_cRef) && v66 )
      v66->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v66, 1u);
    v67 = result.m_charbuffer;
  }
  else
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(
      (AC1Legacy::PStringBase<char> *)&conversionWorked,
      damageType.m_charbuffer->m_data);
    rhs.m_charbuffer = (PSRefBufferCharData<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    AC1Legacy::PStringBase<char>::operator=((AC1Legacy::PStringBase<char> *)&rhs, hp);
    result.m_charbuffer = (PSRefBufferCharData<char> *)attackers_name->m_buffer;
    InterlockedIncrement((volatile LONG *)&result.m_charbuffer->m_data[4]);
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v144, "damage!");
    v69 = v68;
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v139, " of ");
    v71 = v70;
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v146, " point");
    v73 = v72;
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v154, " for ");
    v75 = v74;
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v148, " you");
    v77 = v76;
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v142, " ");
    v79 = v78;
    v80 = AC1Legacy::PStringBase<char>::operator+(&crit_string, &v140, (AC1Legacy::PStringBase<char> *)&result);
    v81 = AC1Legacy::PStringBase<char>::operator+(v80, &v141, v79);
    v82 = AC1Legacy::PStringBase<char>::operator+(v81, &v143, &plural);
    v83 = AC1Legacy::PStringBase<char>::operator+(v82, &v145, v77);
    v84 = AC1Legacy::PStringBase<char>::operator+(v83, &v147, v75);
    v85 = AC1Legacy::PStringBase<char>::operator+(v84, &v149, (AC1Legacy::PStringBase<char> *)&rhs);
    v86 = AC1Legacy::PStringBase<char>::operator+(v85, (AC1Legacy::PStringBase<char> *)&lpAddend, v73);
    v87 = AC1Legacy::PStringBase<char>::operator+(v86, &v153, &s);
    v88 = AC1Legacy::PStringBase<char>::operator+(v87, &v155, v71);
    v89 = AC1Legacy::PStringBase<char>::operator+(v88, &v152, (AC1Legacy::PStringBase<char> *)&conversionWorked);
    v90 = (AC1Legacy::PSRefBuffer<char> **)AC1Legacy::PStringBase<char>::operator+(v89, &v135, v69);
    if ( (AC1Legacy::PSRefBuffer<char> *)v14 != *v90 )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v14 + 4)) && v14 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
      msg.m_buffer = *v90;
      InterlockedIncrement((volatile LONG *)&msg.m_buffer->m_cRef);
    }
    v91 = v135.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v135.m_buffer->m_cRef) && v91 )
      v91->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v91, 1u);
    v92 = v152.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v152.m_buffer->m_cRef) && v92 )
      v92->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v92, 1u);
    v93 = v155.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v155.m_buffer->m_cRef) && v93 )
      v93->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v93, 1u);
    v94 = v153.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v153.m_buffer->m_cRef) && v94 )
      v94->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v94, 1u);
    v95 = lpAddend;
    if ( !InterlockedDecrement(lpAddend + 1) && v95 )
      (**(void (__thiscall ***)(volatile LONG *, signed int))v95)(v95, 1);
    v96 = v149.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v149.m_buffer->m_cRef) && v96 )
      v96->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v96, 1u);
    v97 = v147.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v147.m_buffer->m_cRef) && v97 )
      v97->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v97, 1u);
    v98 = v145.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v145.m_buffer->m_cRef) && v98 )
      v98->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v98, 1u);
    v99 = v143.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v143.m_buffer->m_cRef) && v99 )
      v99->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v99, 1u);
    v100 = v141.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v141.m_buffer->m_cRef) && v100 )
      v100->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v100, 1u);
    v101 = v140.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v140.m_buffer->m_cRef) && v101 )
      v101->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v101, 1u);
    v102 = result.m_charbuffer;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer->m_data[4]) && v102 )
      (**(void (__thiscall ***)(PSRefBufferCharData<char> *, signed int))&v102->m_data[0])(v102, 1);
    v103 = v142.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v142.m_buffer->m_cRef) && v103 )
      v103->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v103, 1u);
    v104 = v148.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v148.m_buffer->m_cRef) && v104 )
      v104->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v104, 1u);
    v105 = v154.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v154.m_buffer->m_cRef) && v105 )
      v105->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v105, 1u);
    v106 = rhs.m_charbuffer;
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer->m_data[4]) && v106 )
      (**(void (__thiscall ***)(PSRefBufferCharData<char> *, signed int))&v106->m_data[0])(v106, 1);
    v107 = v146.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v146.m_buffer->m_cRef) && v107 )
      v107->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v107, 1u);
    v108 = v139.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v139.m_buffer->m_cRef) && v108 )
      v108->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v108, 1u);
    v109 = v144.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v144.m_buffer->m_cRef) && v109 )
      v109->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v109, 1u);
    v67 = (PSRefBufferCharData<char> *)conversionWorked;
  }
  if ( !InterlockedDecrement((volatile LONG *)&v67->m_data[4]) && v67 )
    (**(void (__thiscall ***)(PSRefBufferCharData<char> *, signed int))&v67->m_data[0])(v67, 1);
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&result, &name);
  v110 = gmCCommunicationSystem::IsSquelched(0, (AC1Legacy::PStringBase<char> *)&result, 6u);
  v111 = result.m_charbuffer;
  v112 = v110 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer->m_data[4]) && v111 )
    (**(void (__thiscall ***)(PSRefBufferCharData<char> *, signed int))&v111->m_data[0])(v111, 1);
  if ( v112 )
  {
    if ( attack_conditions & 1 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(
        &v135,
        " Your Critical Protection augmentation allows you to avoid a critical hit!");
      v113 = v135.m_buffer;
      v114 = v135.m_buffer->m_len;
      if ( v114 != 1 && v135.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(&msg, v135.m_buffer->m_data, v114 - 1);
      if ( !InterlockedDecrement((volatile LONG *)&v113->m_cRef) )
        v113->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v113, 1u);
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v135, "\n");
    v115 = v135.m_buffer;
    v116 = v135.m_buffer->m_len;
    if ( v116 != 1 && v135.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(&msg, v135.m_buffer->m_data, v116 - 1);
    if ( !InterlockedDecrement((volatile LONG *)&v115->m_cRef) )
      v115->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v115, 1u);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&result,
      0,
      msg.m_buffer->m_data);
    v117 = v159;
    ClientSystem::AddTextToScroll(v159, (PStringBase<unsigned short> *)&result, 0x15u, 1, 0);
    v118 = &result.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v118 )
      (**(void (__thiscall ***)(char *, signed int))v118)(v118, 1);
  }
  else
  {
    v117 = v159;
  }
  v119 = Timer::cur_time.Param;
  v120 = v117[3].vfptr;
  v117[11].vfptr = (InterfaceVtbl *)Timer::cur_time.Cmd;
  v117[11].vfptr = (NoticeHandlerVtbl *)v119;
  if ( v120 == (NoticeHandlerVtbl *)2 || v120 == (NoticeHandlerVtbl *)4 )
  {
    v121 = CPlayerSystem::GetPlayerSystem();
    if ( (unsigned __int8)PlayerModule::AutoTarget((PlayerModule *)&v121->playerModule.vfptr) )
    {
      if ( ACCWeenieObject::selectedID == Formatted )
        ClientCombatSystem::AutoTarget((ClientCombatSystem *)v117);
    }
  }
  v122 = crit_string.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&crit_string.m_buffer->m_cRef) && v122 )
    v122->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v122, 1u);
  v123 = body_part.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&body_part.m_buffer->m_cRef) && v123 )
    v123->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v123, 1u);
  v124 = msg.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer->m_cRef) && v124 )
    v124->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v124, 1u);
  v125 = printable_body_part.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&printable_body_part.m_buffer->m_cRef) && v125 )
    v125->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v125, 1u);
  v126 = &damageType.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&damageType.m_charbuffer[-1]) && v126 )
    (**(void (__thiscall ***)(char *, signed int))v126)(v126, 1);
  v127 = s.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&s.m_buffer->m_cRef) && v127 )
    v127->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v127, 1u);
  v128 = plural.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&plural.m_buffer->m_cRef) && v128 )
    v128->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v128, 1u);
  v129 = dummy.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&dummy.m_buffer->m_cRef) )
  {
    if ( v129 )
      v129->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v129, 1u);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0056D600) --------------------------------------------------------  // acclient.c:409996
char __thiscall ClientCombatSystem::HandleCombatAction(ClientCombatSystem *this, InputEvent *i_evt)
{
  ClientCombatSystem *v2; // esi@1
  unsigned int v3; // edi@2
  unsigned __int64 v4; // rax@3
  char v5; // cl@3
  float _Number; // ST04_4@6
  char result; // al@6
  float i_evta; // [sp+18h] [bp+4h]@6

  v2 = this;
  if ( i_evt->m_fStart )
  {
    v3 = i_evt->m_InputAction;
    switch ( i_evt->m_InputAction )
    {
      case 0x1000005Bu:
      case 0x1000005Cu:
      case 0x100000EFu:
      case 0x100000F0u:
        v4 = (unsigned __int64)((this->m_rUIRequestedPower + 0.083333336) * 6.0);
        v5 = 0;
        if ( v3 == 268435548 || v3 == 268435696 )
          v5 = 1;
        _Number = (double)(signed int)(v4 + 2 * (v5 != 0) - 1) * 0.16666667;
        i_evta = MathLib::Clamp(_Number, 0.0, 1.0);
        v2->m_rUIRequestedPower = i_evta;
        CM_Combat::SendNotice_DesiredAttackPowerChanged(i_evta);
        result = 1;
        break;
      case 0x1000005Fu:
      case 0x100000F3u:
        ClientCombatSystem::SetRequestedAttackHeight(this, HIGH_ATTACK_HEIGHT);
        CM_Combat::SendNotice_AttackHeightChanged(v2->requestedAttackHeight);
        result = 1;
        break;
      case 0x1000005Eu:
      case 0x100000F2u:
        ClientCombatSystem::SetRequestedAttackHeight(this, MEDIUM_ATTACK_HEIGHT);
        CM_Combat::SendNotice_AttackHeightChanged(v2->requestedAttackHeight);
        result = 1;
        break;
      case 0x1000005Du:
      case 0x100000F1u:
        ClientCombatSystem::SetRequestedAttackHeight(this, LOW_ATTACK_HEIGHT);
        CM_Combat::SendNotice_AttackHeightChanged(v2->requestedAttackHeight);
        result = 1;
        break;
      default:
        goto LABEL_12;
    }
  }
  else
  {
    switch ( i_evt->m_InputAction )
    {
      case 0x1000005Du:
      case 0x1000005Eu:
      case 0x1000005Fu:
      case 0x100000F1u:
      case 0x100000F2u:
      case 0x100000F3u:
        ClientCombatSystem::EndAttackRequest(this, this->requestedAttackHeight, -1.0);
        result = 1;
        break;
      default:
LABEL_12:
        result = 0;
        break;
    }
  }
  return result;
}

//----- (0056D890) --------------------------------------------------------  // acclient.c:410071
char __thiscall ClientCombatSystem::OnAction(ClientCombatSystem *this, InputEvent *i_evt)
{
  unsigned int v2; // eax@2
  ClientCombatSystem *v3; // esi@2
  ClientCombatSystem *v4; // ecx@2
  signed int v5; // eax@3
  char result; // al@3

  if ( i_evt->m_InputAction == 268435546 )
  {
    v2 = this->m_cTurbineRefCount.m_cRef;
    v3 = (ClientCombatSystem *)((char *)this - 8);
    v4 = (ClientCombatSystem *)((char *)this - 8);
    if ( v2 == 1 )
    {
      v5 = ClientCombatSystem::GetDefaultCombatMode(v4, 0);
      ClientCombatSystem::SetCombatMode(v3, (COMBAT_MODE)v5, (CaseInsensitiveStringBase<PStringBase<char> >)1);
      result = 1;
    }
    else
    {
      ClientCombatSystem::SetCombatMode(v4, NONCOMBAT_COMBAT_MODE, (CaseInsensitiveStringBase<PStringBase<char> >)1);
      result = 1;
    }
  }
  else if ( this->m_cTurbineRefCount.m_cRef == 2 || this->m_cTurbineRefCount.m_cRef == 4 )
  {
    result = ClientCombatSystem::HandleCombatAction((ClientCombatSystem *)((char *)this - 8), i_evt);
  }
  else if ( this->m_cTurbineRefCount.m_cRef == 8 )
  {
    result = ClientCombatSystem::HandleMagicAction(i_evt);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00708DC0) --------------------------------------------------------  // acclient.c:796148
void sub_708DC0()
{
  flt_87067C = 1000.0 + 1.0;
}

//----- (00708DE0) --------------------------------------------------------  // acclient.c:796154
void sub_708DE0()
{
  flt_870680 = 24.0 * 8.0;
}

//----- (00708E00) --------------------------------------------------------  // acclient.c:796160
void sub_708E00()
{
  flt_870684 = 24.0 * 0.5;
}

//----- (00708E20) --------------------------------------------------------  // acclient.c:796166
int sub_708E20()
{
  return atexit(nullsub_1340);
}

//----- (00708E30) --------------------------------------------------------  // acclient.c:796172
int sub_708E30()
{
  return atexit(nullsub_1341);
}

//----- (00708E40) --------------------------------------------------------  // acclient.c:796178
int sub_708E40()
{
  return atexit(nullsub_1342);
}

//----- (00708E50) --------------------------------------------------------  // acclient.c:796184
void sub_708E50()
{
  flt_870688 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00708E70) --------------------------------------------------------  // acclient.c:796190
void _E108_91()
{
  dbl_870690 = 1.0 / 30.0;
}

//----- (00708E90) --------------------------------------------------------  // acclient.c:796196
void _E110_75()
{
  dbl_870698 = 1.0 / 5.0;
}

//----- (00708EB0) --------------------------------------------------------  // acclient.c:796202
void sub_708EB0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8706A0, PFID_A8R8G8B8);
}

//----- (00708EC0) --------------------------------------------------------  // acclient.c:796208
void _E115_75()
{
  dword_8706D8 = 1024;
}

//----- (00708ED0) --------------------------------------------------------  // acclient.c:796214
void _E117_71()
{
  dword_8706DC = 0x7FFF;
}

//----- (00708EE0) --------------------------------------------------------  // acclient.c:796220
int _E119_25()
{
  const int result; // eax@1

  result = dword_8706D8;
  dword_8706E0 = dword_8706D8;
  return result;
}

//----- (00708EF0) --------------------------------------------------------  // acclient.c:796230
int _E121_66()
{
  return atexit(_E122_93);
}

//----- (00708F00) --------------------------------------------------------  // acclient.c:796236
int _E124_65()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't sit down while in combat mode");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_sit_combat, v0);
  _wcscpy(cant_sit_combat.m_charbuffer->m_data, L"You can't sit down while in combat mode");
  return atexit(_E125_63);
}

//----- (00708F40) --------------------------------------------------------  // acclient.c:796247
int _E127_56()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't lie down while in combat mode");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_lie_down_combat, v0);
  _wcscpy(cant_lie_down_combat.m_charbuffer->m_data, L"You can't lie down while in combat mode");
  return atexit(_E128_62);
}

//----- (00708F80) --------------------------------------------------------  // acclient.c:796258
int _E130_51()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't crouch while in combat mode");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_crouch_combat, v0);
  _wcscpy(cant_crouch_combat.m_charbuffer->m_data, L"You can't crouch while in combat mode");
  return atexit(_E131_53);
}

//----- (00708FC0) --------------------------------------------------------  // acclient.c:796269
int _E133_44()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't use chat emotes from this position");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_emote_position, v0);
  _wcscpy(cant_emote_position.m_charbuffer->m_data, L"You can't use chat emotes from this position");
  return atexit(_E134_38);
}

//----- (00709000) --------------------------------------------------------  // acclient.c:796280
int _E136_30()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't use chat emotes in combat mode");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_emote_combat, v0);
  _wcscpy(cant_emote_combat.m_charbuffer->m_data, L"You can't use chat emotes in combat mode");
  return atexit(_E137_37);
}

//----- (00709040) --------------------------------------------------------  // acclient.c:796291
int _E139_30()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't jump from this position");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_position, v0);
  _wcscpy(cant_jump_position.m_charbuffer->m_data, L"You can't jump from this position");
  return atexit(_E140_31);
}

//----- (00709080) --------------------------------------------------------  // acclient.c:796302
int _E142_27()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't jump while in the air");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_in_air, v0);
  _wcscpy(cant_jump_in_air.m_charbuffer->m_data, L"You can't jump while in the air");
  return atexit(_E143_31);
}

//----- (007090C0) --------------------------------------------------------  // acclient.c:796313
int _E145_29()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You're too loaded down to jump");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_load, v0);
  _wcscpy(cant_jump_load.m_charbuffer->m_data, L"You're too loaded down to jump");
  return atexit(_E146_31);
}

//----- (00709100) --------------------------------------------------------  // acclient.c:796324
int _E148_29()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You're too tired to jump!");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_stamina, v0);
  _wcscpy(cant_jump_stamina.m_charbuffer->m_data, L"You're too tired to jump!");
  return atexit(_E149_31);
}

//----- (00709140) --------------------------------------------------------  // acclient.c:796335
int _E151_27()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You've jumped too recently!");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_recent, v0);
  _wcscpy(cant_jump_recent.m_charbuffer->m_data, L"You've jumped too recently!");
  return atexit(_E152_32);
}

//----- (00709180) --------------------------------------------------------  // acclient.c:796346
int _E154_28()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You are too tired to move!");
  PStringBase<unsigned short>::allocate_ref_buffer(&too_tired, v0);
  _wcscpy(too_tired.m_charbuffer->m_data, L"You are too tired to move!");
  return atexit(_E155_28);
}

//----- (007091C0) --------------------------------------------------------  // acclient.c:796357
int sub_7091C0()
{
  return atexit(nullsub_1339);
}

//----- (007739E0) --------------------------------------------------------  // acclient.c:907291
void __cdecl _E125_63()
{
  char *v0; // esi@1

  v0 = (char *)&cant_sit_combat.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_sit_combat.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773A10) --------------------------------------------------------  // acclient.c:907304
void __cdecl _E128_62()
{
  char *v0; // esi@1

  v0 = (char *)&cant_lie_down_combat.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_lie_down_combat.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773A40) --------------------------------------------------------  // acclient.c:907317
void __cdecl _E131_53()
{
  char *v0; // esi@1

  v0 = (char *)&cant_crouch_combat.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_crouch_combat.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773A70) --------------------------------------------------------  // acclient.c:907330
void __cdecl _E134_38()
{
  char *v0; // esi@1

  v0 = (char *)&cant_emote_position.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_emote_position.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773AA0) --------------------------------------------------------  // acclient.c:907343
void __cdecl _E137_37()
{
  char *v0; // esi@1

  v0 = (char *)&cant_emote_combat.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_emote_combat.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773AD0) --------------------------------------------------------  // acclient.c:907356
void __cdecl _E140_31()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_position.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_position.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773B00) --------------------------------------------------------  // acclient.c:907369
void __cdecl _E143_31()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_in_air.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_in_air.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773B30) --------------------------------------------------------  // acclient.c:907382
void __cdecl _E146_31()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_load.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_load.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773B60) --------------------------------------------------------  // acclient.c:907395
void __cdecl _E149_31()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_stamina.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_stamina.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773B90) --------------------------------------------------------  // acclient.c:907408
void __cdecl _E152_32()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_recent.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_recent.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773BC0) --------------------------------------------------------  // acclient.c:907421
void __cdecl _E155_28()
{
  char *v0; // esi@1

  v0 = (char *)&too_tired.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&too_tired.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

