/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PlayerSystem
   Object     : AC\accui_misc\PlayerSystem.obj
   Functions  : 127
   Addresses  : 0055D3E0 - 00773460 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0055D3E0) --------------------------------------------------------  // acclient.c:395588
unsigned int __thiscall ACCWeenieObject::BlocksUseOfShield(ACCWeenieObject *this)
{
  COMBAT_USE v1; // eax@1
  unsigned int result; // eax@3

  v1 = this->pwd._combatUse;
  if ( v1 == 2 && this->pwd._ammoType || v1 == 5 )
    result = 1;
  else
    result = ((unsigned int)((int (*)(void))this->vfptr[6].__vecDelDtor)() >> 15) & 1;
  return result;
}

//----- (0055D410) --------------------------------------------------------  // acclient.c:395602
void __thiscall CPlayerSystem::Begin(CPlayerSystem *this)
{
  this->playerID = 0;
  this->allContainedObjectsReceived = 0;
  this->player_initialized = 0;
  this->player_desc_received = 0;
  *(_QWORD *)&this->playerInitTime = 0i64;
  this->inventoryMask = 0;
  this->clothingPriorityMask = 0;
  this->teleportInProgress = 0;
  LODWORD(this->m_fLoad) = 0;
  this->lastFullyMergedSrcID = 0;
  this->lastFullyMergedDstID = 0;
  this->mOpenContainerID = 0;
  this->blockingID = 0;
  this->blockedID = 0;
  this->blockingDestID = 0;
  this->unblockAttemptNum = 0;
  this->blockedSpellID = 0;
  this->blockedSpellTargetID = 0;
  this->blockedSide = 0;
  this->componentTracker = 0;
  this->fReadyToEnterGame = 0;
  this->awaitingLogOn = 0;
  this->sendLoginCompletePending = 0;
  this->initialLoginComplete = 0;
}

//----- (0055D4B0) --------------------------------------------------------  // acclient.c:395631
CPlayerSystem *__cdecl CPlayerSystem::GetPlayerSystem()
{
  return CPlayerSystem::s_pPlayerSystem;
}
// 87018C: using guessed type struct CPlayerSystem *CPlayerSystem::s_pPlayerSystem;

//----- (0055D4C0) --------------------------------------------------------  // acclient.c:395638
void __thiscall CPlayerSystem::GetCharGenState(CPlayerSystem *this)
{
  CPlayerSystem *v1; // esi@1
  ClientCharGenState *v2; // eax@2
  ClientCharGenState *v3; // eax@3
  ClientCharGenState *v4; // eax@5

  v1 = this;
  if ( !this->m_pCharGenState )
  {
    v2 = (ClientCharGenState *)operator new(0x268u);
    if ( v2 )
    {
      ClientCharGenState::ClientCharGenState(v2);
      v1->m_pCharGenState = v3;
      return;
    }
    v1->m_pCharGenState = 0;
  }
  v4 = v1->m_pCharGenState;
}

//----- (0055D500) --------------------------------------------------------  // acclient.c:395661
void __thiscall CPlayerSystem::GetComponentTracker(CPlayerSystem *this)
{
  CPlayerSystem *v1; // edi@1
  ClientMagicSystem *v2; // eax@2
  SpellComponentTable *v3; // esi@2
  ComponentTracker *v4; // eax@2
  ComponentTracker *v5; // eax@3
  ComponentTracker *v6; // eax@5

  v1 = this;
  if ( !this->componentTracker )
  {
    v2 = ClientMagicSystem::GetMagicSystem();
    v3 = ClientMagicSystem::GetSpellComponentTable(v2);
    v4 = (ComponentTracker *)operator new(0x108u);
    if ( v4 )
    {
      ComponentTracker::ComponentTracker(v4, v3);
      v1->componentTracker = v5;
      return;
    }
    v1->componentTracker = 0;
  }
  v6 = v1->componentTracker;
}

//----- (0055D550) --------------------------------------------------------  // acclient.c:395688
void __thiscall CPlayerSystem::RecvNotice_NewParentContainer(CPlayerSystem *this, unsigned int i_newContainerID)
{
  CPlayerSystem *v2; // esi@1
  HashBaseData<unsigned long> *v3; // eax@1

  v2 = this;
  v3 = ClientObjMaintSystem::GetWeenieObject(i_newContainerID);
  if ( v3 )
  {
    if ( ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v3) )
      v2->unblockAttemptNum = i_newContainerID;
  }
}

//----- (0055D580) --------------------------------------------------------  // acclient.c:395703
void __thiscall CPlayerSystem::SetTeleportInProgress(CPlayerSystem *this, bool bInProgress)
{
  CPlayerSystem *v2; // esi@1
  ClientUISystem *v3; // eax@4
  ClientUISystem *v4; // eax@5

  v2 = this;
  if ( this->teleportInProgress != bInProgress )
  {
    this->teleportInProgress = bInProgress;
    if ( ClientUISystem::GetUISystem() )
    {
      if ( v2->teleportInProgress )
      {
        v3 = ClientUISystem::GetUISystem();
        ClientUISystem::IncrementBusyCount(v3);
      }
      else
      {
        v4 = ClientUISystem::GetUISystem();
        ClientUISystem::DecrementBusyCount(v4);
      }
    }
  }
}

//----- (0055D5D0) --------------------------------------------------------  // acclient.c:395730
void __thiscall CPlayerSystem::Handle_CharacterError(CPlayerSystem *this, charError _error)
{
  this->fReadyToEnterGame = 0;
  this->awaitingLogOn = 0;
  ECM_Login::SendNotice_CharacterError(_error);
}

//----- (0055D5F0) --------------------------------------------------------  // acclient.c:395738
void __thiscall CPlayerSystem::Handle_CharacterDelete(CPlayerSystem *this)
{
  CPlayerSystem *v1; // esi@1
  CharacterSet *v2; // edi@1
  ClientCharGenState *v3; // eax@2
  ClientCharGenState *v4; // eax@3

  v1 = this;
  v2 = (CharacterSet *)(((int (*)(void))UIFlow::m_instance->vfptr[1].QueryInterface)() + 4);
  if ( !v1->m_pCharGenState )
  {
    v3 = (ClientCharGenState *)operator new(0x268u);
    if ( v3 )
      ClientCharGenState::ClientCharGenState(v3);
    else
      v4 = 0;
    v1->m_pCharGenState = v4;
  }
  CharacterSet::ClearIdentity(v2, v1->m_pCharGenState->slot);
  LODWORD(v1->deleteCharRequestTime) = 0;
  HIDWORD(v1->deleteCharRequestTime) = 0;
  ECM_Character::SendNotice_CharacterSet(v2);
}
// 83D72C: using guessed type struct UIFlow *UIFlow::m_instance;

//----- (0055D660) --------------------------------------------------------  // acclient.c:395764
void __thiscall CPlayerSystem::Handle_AwaitingSubscriptionExpiration(CPlayerSystem *this, unsigned int secondsRemaining)
{
  CPlayerSystem *v2; // edi@1
  unsigned __int64 v3; // rax@5
  PlayerModule *v4; // eax@6
  char warningMsg[128]; // [sp+14h] [bp-80h]@2

  v2 = this;
  if ( secondsRemaining > 1 )
  {
    if ( secondsRemaining > 0x3C )
    {
      v3 = (unsigned __int64)_ceil((double)secondsRemaining * 0.01666666666666667);
      __snprintf(
        warningMsg,
        0x80u,
        "*** WARNING: Your subscription to this game runs out in less than %i %s. ***\n",
        v3,
        "minutes");
    }
    else
    {
      __snprintf(
        warningMsg,
        0x80u,
        "*** YOUR SUBSCRIPTION EXPIRES IN LESS THAN %i %s. PLEASE LOG OUT. ***\n",
        secondsRemaining,
        "SECONDS");
    }
  }
  else
  {
    __snprintf(
      warningMsg,
      0x80u,
      "*** YOUR SUBSCRIPTION EXPIRES IN LESS THAN %i %s. PLEASE LOG OUT. ***\n",
      1,
      "SECOND");
  }
  warningMsg[127] = 0;
  v4 = (PlayerModule *)ClientUISystem::GetUISystem();
  gmNoticeHandler::RecvNotice_UpdateRentPayment(v4, (PlayerOption)warningMsg);
  v2->awaitingExpiration = 1;
  v2->expirationTime = (double)secondsRemaining + COERCE_DOUBLE(Timer::cur_time.Cmd);
}

//----- (0055D750) --------------------------------------------------------  // acclient.c:395811
bool __thiscall CPlayerSystem::AccountHasThroneOfDestiny(CPlayerSystem *this)
{
  return this->m_accountHasThroneofDestiny;
}

//----- (0055D760) --------------------------------------------------------  // acclient.c:395817
void __stdcall CPlayerSystem::RestoreCharacter(unsigned int i_iidAvatar)
{
  Proto_UI::SendAdminRestoreCharacter(i_iidAvatar, &PStringBase<char>::null_string, &PStringBase<char>::null_string);
}

//----- (0055D780) --------------------------------------------------------  // acclient.c:395823
void __thiscall CPlayerSystem::ExecuteLogOff(CPlayerSystem *this)
{
  CPlayerSystem *v1; // esi@1
  unsigned int v2; // ecx@1

  v1 = this;
  this->initialLoginComplete = 0;
  this->logOffRequested = 0;
  v2 = Timer::cur_time.Param;
  LODWORD(v1->logOffTime) = Timer::cur_time.Cmd;
  HIDWORD(v1->logOffTime) = v2;
  ClientNet::ExitWorldDisconnect((ClientNet *)SharedNet::s_pNet);
  v1->player_initialized = 0;
  v1->player_desc_received = 0;
  v1->playerID = 0;
}

//----- (0055D7D0) --------------------------------------------------------  // acclient.c:395841
void __thiscall CPlayerSystem::SetLogOffStarted(CPlayerSystem *this)
{
  this->logOffRequested = 0;
}

//----- (0055D7E0) --------------------------------------------------------  // acclient.c:395847
long double __cdecl Get2DDistance(long double rX, long double rY)
{
  return sqrt(pow(rX, 2.0) + pow(rY, 2.0));
}

//----- (0055D810) --------------------------------------------------------  // acclient.c:395853
double __cdecl GetWeightedZDistance(long double rZ)
{
  long double v1; // st7@1

  v1 = rZ;
  if ( rZ < 0.0 )
    v1 = -rZ;
  return v1 * 1.2;
}

//----- (0055D830) --------------------------------------------------------  // acclient.c:395864
bool __stdcall CPlayerSystem::Farther(long double dist_a, unsigned int id_a, long double dist_b, unsigned int id_b)
{
  return dist_a > dist_b || dist_a >= dist_b && dist_a == dist_b && id_a > id_b;
}

//----- (0055D880) --------------------------------------------------------  // acclient.c:395870
double CPlayerSystem::GetRadarRadius()
{
  double result; // st7@2

  if ( SmartBox::is_player_outside(SmartBox::smartbox) )
    result = 75.0;
  else
    result = 25.0;
  return result;
}

//----- (0055D8A0) --------------------------------------------------------  // acclient.c:395882
bool CPlayerSystem::IsOutside()
{
  bool result; // al@2

  if ( SmartBox::smartbox )
    result = SmartBox::is_player_outside(SmartBox::smartbox) != 0;
  else
    result = 0;
  return result;
}

//----- (0055D8C0) --------------------------------------------------------  // acclient.c:395894
char __thiscall CPlayerSystem::PlaceInBackpack(CPlayerSystem *this, unsigned int i_iidItem, bool bPlaceInMainPack)
{
  CPlayerSystem *v3; // esi@1
  unsigned int v4; // ebx@2
  HashBaseData<unsigned long> *v6; // eax@7

  v3 = this;
  if ( i_iidItem )
  {
    CM_Item::SendNotice_ShowPendingInPlayer(i_iidItem);
    v4 = v3->mOpenContainerID;
    if ( bPlaceInMainPack || (unsigned __int8)PlayerModule::MainPackPreferred((PlayerModule *)&v3->playerModule.vfptr) )
      v4 = v3->playerID;
    if ( ItemHolder::AttemptToPlaceInContainer(i_iidItem, v3->playerID, v4, 1, 0) )
      return 1;
    v6 = ClientObjMaintSystem::GetWeenieObject(i_iidItem);
    if ( v6 )
      ACCWeenieObject::SetWaitingState((ACCWeenieObject *)v6, 0);
    CM_Item::SendNotice_EndPendingInPlayer();
  }
  return 0;
}

//----- (0055D940) --------------------------------------------------------  // acclient.c:395918
void __thiscall CPlayerSystem::ResetUnblocking(CPlayerSystem *this)
{
  this->blockingID = 0;
  this->blockedID = 0;
  this->blockedSide = 0;
  this->unblockAttemptNum = 0;
}

//----- (0055D960) --------------------------------------------------------  // acclient.c:395927
void __thiscall CInvSlotModule::CInvSlotModule(CInvSlotModule *this)
{
  CInvSlotModule *v1; // esi@1
  void *v2; // eax@1
  void *v3; // eax@4
  void *v4; // eax@7
  void *v5; // eax@10
  void *v6; // eax@13
  void *v7; // eax@16
  void *v8; // eax@19
  void *v9; // eax@22
  void *v10; // eax@25
  void *v11; // eax@28
  void *v12; // eax@31
  void *v13; // eax@34
  void *v14; // eax@37
  void *v15; // eax@40
  void *v16; // eax@43
  void *v17; // eax@46
  void *v18; // eax@49
  void *v19; // eax@52
  void *v20; // eax@55
  void *v21; // eax@58
  void *v22; // eax@61
  void *v23; // eax@64
  void *v24; // eax@67
  void *v25; // eax@70

  v1 = this;
  v2 = operator new(8u);
  if ( v2 )
  {
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = 0x8000;
  }
  else
  {
    v2 = 0;
  }
  v1->neckSlot = (CInvSlotInfo *)v2;
  v3 = operator new(8u);
  if ( v3 )
  {
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 1) = 0x10000;
  }
  else
  {
    v3 = 0;
  }
  v1->leftWristSlot = (CInvSlotInfo *)v3;
  v4 = operator new(8u);
  if ( v4 )
  {
    *(_DWORD *)v4 = 0;
    *((_DWORD *)v4 + 1) = 0x40000;
  }
  else
  {
    v4 = 0;
  }
  v1->leftRingSlot = (CInvSlotInfo *)v4;
  v5 = operator new(8u);
  if ( v5 )
  {
    *(_DWORD *)v5 = 0;
    *((_DWORD *)v5 + 1) = 0x20000;
  }
  else
  {
    v5 = 0;
  }
  v1->rightWristSlot = (CInvSlotInfo *)v5;
  v6 = operator new(8u);
  if ( v6 )
  {
    *(_DWORD *)v6 = 0;
    *((_DWORD *)v6 + 1) = 0x80000;
  }
  else
  {
    v6 = 0;
  }
  v1->rightRingSlot = (CInvSlotInfo *)v6;
  v7 = operator new(8u);
  if ( v7 )
  {
    *(_DWORD *)v7 = 0;
    *((_DWORD *)v7 + 1) = 55574528;
  }
  else
  {
    v7 = 0;
  }
  v1->weaponReadySlot = (CInvSlotInfo *)v7;
  v8 = operator new(8u);
  if ( v8 )
  {
    *(_DWORD *)v8 = 0;
    *((_DWORD *)v8 + 1) = "activation type (%s) with '%s' because of its toggle type (%s)";
  }
  else
  {
    v8 = 0;
  }
  v1->ammoReadySlot = (CInvSlotInfo *)v8;
  v9 = operator new(8u);
  if ( v9 )
  {
    *(_DWORD *)v9 = 0;
    *((_DWORD *)v9 + 1) = 3145728;
  }
  else
  {
    v9 = 0;
  }
  v1->shieldReadySlot = (CInvSlotInfo *)v9;
  v10 = operator new(8u);
  if ( v10 )
  {
    *(_DWORD *)v10 = 0;
    *((_DWORD *)v10 + 1) = 64;
  }
  else
  {
    v10 = 0;
  }
  v1->clothesPantsSlot = (CInvSlotInfo *)v10;
  v11 = operator new(8u);
  if ( v11 )
  {
    *(_DWORD *)v11 = 0;
    *((_DWORD *)v11 + 1) = 2;
  }
  else
  {
    v11 = 0;
  }
  v1->clothesShirtSlot = (CInvSlotInfo *)v11;
  v12 = operator new(8u);
  if ( v12 )
  {
    *(_DWORD *)v12 = 0;
    *((_DWORD *)v12 + 1) = 0x4000000;
  }
  else
  {
    v12 = 0;
  }
  v1->trinketOneSlot = (CInvSlotInfo *)v12;
  v13 = operator new(8u);
  if ( v13 )
  {
    *(_DWORD *)v13 = 0;
    *((_DWORD *)v13 + 1) = 0x8000000;
  }
  else
  {
    v13 = 0;
  }
  v1->cloakSlot = (CInvSlotInfo *)v13;
  v14 = operator new(8u);
  if ( v14 )
  {
    *(_DWORD *)v14 = 0;
    *((_DWORD *)v14 + 1) = 0x10000000;
  }
  else
  {
    v14 = 0;
  }
  v1->sigilOneSlot = (CInvSlotInfo *)v14;
  v15 = operator new(8u);
  if ( v15 )
  {
    *(_DWORD *)v15 = 0;
    *((_DWORD *)v15 + 1) = 0x20000000;
  }
  else
  {
    v15 = 0;
  }
  v1->sigilTwoSlot = (CInvSlotInfo *)v15;
  v16 = operator new(8u);
  if ( v16 )
  {
    *(_DWORD *)v16 = 0;
    *((_DWORD *)v16 + 1) = 0x40000000;
  }
  else
  {
    v16 = 0;
  }
  v1->sigilThreeSlot = (CInvSlotInfo *)v16;
  v17 = operator new(8u);
  if ( v17 )
  {
    *(_DWORD *)v17 = 0;
    *((_DWORD *)v17 + 1) = 1;
  }
  else
  {
    v17 = 0;
  }
  v1->headSlot = (CInvSlotInfo *)v17;
  v18 = operator new(8u);
  if ( v18 )
  {
    *(_DWORD *)v18 = 0;
    *((_DWORD *)v18 + 1) = 512;
  }
  else
  {
    v18 = 0;
  }
  v1->chestSlot = (CInvSlotInfo *)v18;
  v19 = operator new(8u);
  if ( v19 )
  {
    *(_DWORD *)v19 = 0;
    *((_DWORD *)v19 + 1) = 1024;
  }
  else
  {
    v19 = 0;
  }
  v1->abdomenSlot = (CInvSlotInfo *)v19;
  v20 = operator new(8u);
  if ( v20 )
  {
    *(_DWORD *)v20 = 0;
    *((_DWORD *)v20 + 1) = 2048;
  }
  else
  {
    v20 = 0;
  }
  v1->upperArmSlot = (CInvSlotInfo *)v20;
  v21 = operator new(8u);
  if ( v21 )
  {
    *(_DWORD *)v21 = 0;
    *((_DWORD *)v21 + 1) = 4096;
  }
  else
  {
    v21 = 0;
  }
  v1->lowerArmSlot = (CInvSlotInfo *)v21;
  v22 = operator new(8u);
  if ( v22 )
  {
    *(_DWORD *)v22 = 0;
    *((_DWORD *)v22 + 1) = 32;
  }
  else
  {
    v22 = 0;
  }
  v1->handSlot = (CInvSlotInfo *)v22;
  v23 = operator new(8u);
  if ( v23 )
  {
    *(_DWORD *)v23 = 0;
    *((_DWORD *)v23 + 1) = 0x2000;
  }
  else
  {
    v23 = 0;
  }
  v1->upperLegSlot = (CInvSlotInfo *)v23;
  v24 = operator new(8u);
  if ( v24 )
  {
    *(_DWORD *)v24 = 0;
    *((_DWORD *)v24 + 1) = 0x4000;
  }
  else
  {
    v24 = 0;
  }
  v1->lowerLegSlot = (CInvSlotInfo *)v24;
  v25 = operator new(8u);
  if ( v25 )
  {
    *(_DWORD *)v25 = 0;
    *((_DWORD *)v25 + 1) = 256;
    v1->footSlot = (CInvSlotInfo *)v25;
  }
  else
  {
    v1->footSlot = 0;
  }
}

//----- (0055DCA0) --------------------------------------------------------  // acclient.c:396223
void __thiscall CInvSlotModule::Reset(CInvSlotModule *this)
{
  this->neckSlot->m_itemID = 0;
  this->leftWristSlot->m_itemID = 0;
  this->leftRingSlot->m_itemID = 0;
  this->rightWristSlot->m_itemID = 0;
  this->rightRingSlot->m_itemID = 0;
  this->weaponReadySlot->m_itemID = 0;
  this->ammoReadySlot->m_itemID = 0;
  this->shieldReadySlot->m_itemID = 0;
  this->clothesPantsSlot->m_itemID = 0;
  this->clothesShirtSlot->m_itemID = 0;
  this->trinketOneSlot->m_itemID = 0;
  this->cloakSlot->m_itemID = 0;
  this->sigilOneSlot->m_itemID = 0;
  this->sigilTwoSlot->m_itemID = 0;
  this->sigilThreeSlot->m_itemID = 0;
  this->headSlot->m_itemID = 0;
  this->chestSlot->m_itemID = 0;
  this->abdomenSlot->m_itemID = 0;
  this->upperArmSlot->m_itemID = 0;
  this->lowerArmSlot->m_itemID = 0;
  this->handSlot->m_itemID = 0;
  this->upperLegSlot->m_itemID = 0;
  this->lowerLegSlot->m_itemID = 0;
  this->footSlot->m_itemID = 0;
}

//----- (0055DD80) --------------------------------------------------------  // acclient.c:396252
void __thiscall CPlayerSystem::RegisterInputMaps(CPlayerSystem *this)
{
  CInputManager *v1; // esi@1
  CPlayerSystem *v2; // edi@1
  IInputActionCallback *v3; // eax@3
  int v4; // eax@6
  CommandInterpreter *v5; // eax@9

  v1 = ICIDM::s_cidm;
  v2 = this;
  if ( ICIDM::s_cidm )
  {
    if ( this )
      v3 = (IInputActionCallback *)&this->vfptr;
    else
      v3 = 0;
    ICIDM::s_cidm->vfptr->RegisterInputMap((ICIDM *)ICIDM::s_cidm, 268435463u, v3, 1000);
    if ( v2 )
      v4 = (int)&v2->vfptr;
    else
      v4 = 0;
    v1->vfptr->RegisterInputMap((ICIDM *)v1, 268435464u, (IInputActionCallback *)v4, 1000);
    if ( SmartBox::smartbox )
    {
      v5 = SmartBox::smartbox->cmdinterp;
      if ( v5 )
      {
        v1->vfptr->RegisterInputMap((ICIDM *)v1, 4u, (IInputActionCallback *)v5, 1000);
        v1->vfptr->RegisterInputMap(
          (ICIDM *)v1,
          268435462u,
          (IInputActionCallback *)SmartBox::smartbox->cmdinterp,
          1000);
      }
    }
  }
}

//----- (0055DE10) --------------------------------------------------------  // acclient.c:396291
void __stdcall CPlayerSystem::SetDisplayContractTracker(CContractTracker contractTracker)
{
  CM_Social::SendNotice_SetDisplayContractTracker(&contractTracker);
}

//----- (0055DE20) --------------------------------------------------------  // acclient.c:396297
unsigned int __thiscall CPlayerSystem::Handle_Admin__Environs(CPlayerSystem *this, const int environs_option)
{
  unsigned int ST10_4_8; // ST10_4@8
  unsigned int ST10_4_10; // ST10_4@10
  unsigned int result; // eax@14
  ClientUISystem *v5; // ecx@18
  CSoundTable *v6; // eax@20
  CSoundTable *v7; // eax@21
  CSoundTable *v8; // eax@22
  CSoundTable *v9; // eax@23
  CSoundTable *v10; // eax@24
  CSoundTable *v11; // eax@25
  CSoundTable *v12; // eax@26
  CSoundTable *v13; // eax@27
  CSoundTable *v14; // eax@28
  CSoundTable *v15; // eax@29
  CSoundTable *v16; // eax@30
  CSoundTable *v17; // eax@31
  CSoundTable *v18; // eax@32
  CSoundTable *v19; // eax@33
  CSoundTable *v20; // eax@34
  CSoundTable *v21; // eax@35
  CSoundTable *v22; // eax@36
  CSoundTable *v23; // eax@37
  CSoundTable *v24; // eax@38
  CSoundTable *v25; // eax@39
  CSoundTable *v26; // eax@40
  unsigned int fog_color; // [sp+0h] [bp-4h]@4
  unsigned int environs_optiona; // [sp+8h] [bp+4h]@4
  unsigned int environs_optionc; // [sp+8h] [bp+4h]@8
  unsigned int environs_optiond; // [sp+8h] [bp+4h]@12
  unsigned int environs_optione; // [sp+8h] [bp+4h]@14

  if ( !environs_option )
  {
    LScape::m_override_enabled = 0;
    LODWORD(LScape::m_override_ambient_level) = 0;
    LODWORD(LScape::m_override_fog_max) = 0;
    LScape::m_override_ambient_color.color = 0;
    LScape::m_override_fog_color.color = 0;
LABEL_46:
    LODWORD(LScape::m_override_transition) = 0;
    LODWORD(LScape::m_override_fog_min) = 0;
    ClientUISystem::GetUISystem()->m_bRadarBlank = 0;
    return 0;
  }
  if ( environs_option == 1 )
  {
    environs_optiona = 1687552000;
    BYTE2(fog_color) = -106;
    LOWORD(fog_color) = 0;
    LODWORD(LScape::m_override_fog_max) = 1112014848;
LABEL_43:
    BYTE3(fog_color) = 100;
    LScape::m_override_ambient_color.color = environs_optiona;
    LScape::m_override_fog_color.color = fog_color;
    goto LABEL_44;
  }
  if ( environs_option == 2 )
  {
    LODWORD(LScape::m_override_ambient_level) = 1050253722;
    LODWORD(LScape::m_override_fog_max) = 1112014848;
    LScape::m_override_ambient_color.color = 1680998550;
    LScape::m_override_fog_color.color = 1680998550;
LABEL_45:
    LScape::m_override_enabled = 1;
    goto LABEL_46;
  }
  if ( environs_option == 3 )
  {
    *(_WORD *)((char *)&ST10_4_8 + 1) = 25700;
    LOBYTE(ST10_4_8) = 100;
    BYTE3(ST10_4_8) = 100;
    *(_WORD *)((char *)&environs_optionc + 1) = 25700;
    LOBYTE(environs_optionc) = 100;
    BYTE3(environs_optionc) = 100;
    LODWORD(LScape::m_override_fog_max) = 1106247680;
    LScape::m_override_ambient_color.color = environs_optionc;
    LScape::m_override_fog_color.color = ST10_4_8;
LABEL_44:
    LODWORD(LScape::m_override_ambient_level) = 1053609165;
    goto LABEL_45;
  }
  if ( environs_option == 4 )
  {
    *(_WORD *)((char *)&ST10_4_10 + 1) = 7780;
    LOBYTE(ST10_4_10) = 0;
    BYTE3(ST10_4_10) = 100;
    LODWORD(LScape::m_override_ambient_level) = 1050253722;
    LODWORD(LScape::m_override_fog_max) = 1112014848;
    LScape::m_override_ambient_color.color = 1679713280;
    LScape::m_override_fog_color.color = ST10_4_10;
    goto LABEL_45;
  }
  if ( environs_option == 5 )
  {
    *(_WORD *)((char *)&environs_optiond + 1) = -26986;
    LOBYTE(environs_optiond) = -106;
    BYTE3(environs_optiond) = 100;
    LODWORD(LScape::m_override_ambient_level) = 1061997773;
    LODWORD(LScape::m_override_fog_max) = 1109393408;
    LScape::m_override_ambient_color.color = environs_optiond;
    LScape::m_override_fog_color.color = 1677721600;
    goto LABEL_45;
  }
  if ( environs_option == 6 )
  {
    *(_WORD *)((char *)&environs_optione + 1) = -26986;
    LOBYTE(environs_optione) = -106;
    BYTE3(environs_optione) = 100;
    LScape::m_override_enabled = 1;
    LODWORD(LScape::m_override_transition) = 0;
    LODWORD(LScape::m_override_ambient_level) = 1061997773;
    LODWORD(LScape::m_override_fog_min) = 0;
    LODWORD(LScape::m_override_fog_max) = 1109393408;
    LScape::m_override_ambient_color.color = environs_optione;
    LScape::m_override_fog_color.color = 1677721600;
    ClientUISystem::GetUISystem()->m_bRadarBlank = 1;
    return 0;
  }
  if ( environs_option < 101 || environs_option > 124 )
  {
    if ( environs_option != 9999 )
      return 0;
    *(_WORD *)((char *)&environs_optiona + 1) = 25700;
    LOBYTE(environs_optiona) = 100;
    BYTE3(environs_optiona) = 50;
    *(_WORD *)((char *)&fog_color + 1) = 25700;
    LOBYTE(fog_color) = 100;
    LODWORD(LScape::m_override_fog_max) = 1106247680;
    goto LABEL_43;
  }
  if ( !ClientObjMaintSystem::GetPhysicsObject(this->playerID) )
    return 0;
  v5 = ClientUISystem::GetUISystem();
  if ( !v5 )
    return 0;
  switch ( environs_option )
  {
    case 101:
      v6 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_Roar, v6);
      result = 0;
      break;
    case 102:
      v7 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_Bell, v7);
      result = 0;
      break;
    case 103:
      v8 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_Chant1, v8);
      result = 0;
      break;
    case 104:
      v9 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_Chant2, v9);
      result = 0;
      break;
    case 105:
      v10 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_DarkWhispers1, v10);
      result = 0;
      break;
    case 106:
      v11 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_DarkWhispers2, v11);
      result = 0;
      break;
    case 107:
      v12 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_DarkLaugh, v12);
      result = 0;
      break;
    case 108:
      v13 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_DarkWind, v13);
      result = 0;
      break;
    case 109:
      v14 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_DarkSpeech, v14);
      result = 0;
      break;
    case 110:
      v15 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_Drums, v15);
      result = 0;
      break;
    case 111:
      v16 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_GhostSpeak, v16);
      result = 0;
      break;
    case 112:
      v17 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_Breathing, v17);
      result = 0;
      break;
    case 113:
      v18 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_Howl, v18);
      result = 0;
      break;
    case 114:
      v19 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_LostSouls, v19);
      result = 0;
      break;
    case 117:
      v20 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_Squeal, v20);
      result = 0;
      break;
    case 118:
      v21 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_Thunder1, v21);
      result = 0;
      break;
    case 119:
      v22 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_Thunder2, v22);
      result = 0;
      break;
    case 120:
      v23 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_Thunder3, v23);
      result = 0;
      break;
    case 121:
      v24 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_Thunder4, v24);
      result = 0;
      break;
    case 122:
      v25 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_Thunder5, v25);
      result = 0;
      break;
    case 123:
      v26 = ClientUISystem::GetUISoundTable(v5);
      SoundManager::PlaySoundFromCenter(Sound_UI_Thunder6, v26);
      result = 0;
      break;
    default:
      return 0;
  }
  return result;
}
// 841774: using guessed type struct RGBAUnion LScape::m_override_fog_color;
// 841778: using guessed type struct RGBAUnion LScape::m_override_ambient_color;
// 841799: using guessed type bool LScape::m_override_enabled;
// 84179C: using guessed type float LScape::m_override_ambient_level;
// 8417A0: using guessed type float LScape::m_override_fog_min;
// 8417A4: using guessed type float LScape::m_override_fog_max;
// 8417A8: using guessed type float LScape::m_override_transition;

//----- (0055E3B0) --------------------------------------------------------  // acclient.c:396555
LONG __thiscall CPlayerSystem::AddRef(CPlayerSystem *this)
{
  return InterlockedIncrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef);
}

//----- (0055E3C0) --------------------------------------------------------  // acclient.c:396561
TResult *__thiscall CPlayerSystem::QueryInterface(CPlayerSystem *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( _S164_45 & 1 )
  {
    v4 = Offsets_3[0].key;
  }
  else
  {
    v4 = (_GUID *)&CPlayerSystem_InterfaceType_78;
    _S164_45 |= 1u;
    Offsets_3[0].key = (_GUID *)&CPlayerSystem_InterfaceType_78;
    dword_870254 = 0;
    dword_870258 = (int)&ClientSystem_InterfaceType_81;
    dword_87025C = 0;
    dword_870260 = (int)&stru_7CC6B4;
    dword_870264 = 0;
    dword_870268 = 0;
    dword_87026C = 0;
  }
  v5 = (int)Offsets_3;
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
// 870254: using guessed type int dword_870254;
// 870258: using guessed type int dword_870258;
// 87025C: using guessed type int dword_87025C;
// 870260: using guessed type int dword_870260;
// 870264: using guessed type int dword_870264;
// 870268: using guessed type int dword_870268;
// 87026C: using guessed type int dword_87026C;

//----- (0055E490) --------------------------------------------------------  // acclient.c:396628
void __thiscall CPlayerSystem::RecvNotice_ServerSaysAttemptFailed(CPlayerSystem *this, unsigned int _itemID)
{
  CPlayerSystem *v2; // esi@1
  HashBaseData<unsigned long> *v3; // eax@3

  v2 = this;
  if ( this->blockedSide > 0 && this->m_invSlotModule.footSlot == (CInvSlotInfo *)_itemID )
  {
    v3 = ClientObjMaintSystem::GetWeenieObject(this->blockingID);
    if ( v3 )
      ACCWeenieObject::SetWaitingState((ACCWeenieObject *)v3, 0);
    v2->m_invSlotModule.footSlot = 0;
    v2->blockingID = 0;
    v2->blockedSpellID = 0;
    v2->blockedSide = 0;
  }
}

//----- (0055E4F0) --------------------------------------------------------  // acclient.c:396647
unsigned int __thiscall CPlayerSystem::Handle_Character__EnterGame_ServerReady(CPlayerSystem *this)
{
  CPlayerSystem *v1; // esi@1

  v1 = this;
  if ( this->awaitingLogOn )
  {
    ClientNet::ExitWorldDisconnect((ClientNet *)SharedNet::s_pNet);
    v1->fReadyToEnterGame = 1;
  }
  return 0;
}

//----- (0055E520) --------------------------------------------------------  // acclient.c:396661
void __thiscall CInvSlotModule::~CInvSlotModule(CInvSlotModule *this)
{
  CInvSlotModule *v1; // esi@1
  void *v2; // eax@3
  void *v3; // eax@5
  void *v4; // eax@7
  void *v5; // eax@9
  void *v6; // eax@11
  void *v7; // eax@13
  void *v8; // eax@15
  void *v9; // eax@17
  void *v10; // eax@19
  void *v11; // eax@21
  void *v12; // eax@23
  void *v13; // eax@25
  void *v14; // eax@27
  void *v15; // eax@29
  void *v16; // eax@31
  void *v17; // eax@33
  void *v18; // eax@35
  void *v19; // eax@37
  void *v20; // eax@39
  void *v21; // eax@41
  void *v22; // eax@43
  void *v23; // eax@45
  void *v24; // eax@47

  v1 = this;
  if ( this->neckSlot )
    operator delete(this->neckSlot);
  v2 = v1->leftWristSlot;
  v1->neckSlot = 0;
  if ( v2 )
    operator delete(v2);
  v3 = v1->leftRingSlot;
  v1->leftWristSlot = 0;
  if ( v3 )
    operator delete(v3);
  v4 = v1->rightWristSlot;
  v1->leftRingSlot = 0;
  if ( v4 )
    operator delete(v4);
  v5 = v1->rightRingSlot;
  v1->rightWristSlot = 0;
  if ( v5 )
    operator delete(v5);
  v6 = v1->weaponReadySlot;
  v1->rightRingSlot = 0;
  if ( v6 )
    operator delete(v6);
  v7 = v1->ammoReadySlot;
  v1->weaponReadySlot = 0;
  if ( v7 )
    operator delete(v7);
  v8 = v1->shieldReadySlot;
  v1->ammoReadySlot = 0;
  if ( v8 )
    operator delete(v8);
  v9 = v1->clothesPantsSlot;
  v1->shieldReadySlot = 0;
  if ( v9 )
    operator delete(v9);
  v10 = v1->clothesShirtSlot;
  v1->clothesPantsSlot = 0;
  if ( v10 )
    operator delete(v10);
  v11 = v1->trinketOneSlot;
  v1->clothesShirtSlot = 0;
  if ( v11 )
    operator delete(v11);
  v12 = v1->cloakSlot;
  v1->trinketOneSlot = 0;
  if ( v12 )
    operator delete(v12);
  v13 = v1->sigilOneSlot;
  v1->cloakSlot = 0;
  if ( v13 )
    operator delete(v13);
  v14 = v1->sigilTwoSlot;
  v1->sigilOneSlot = 0;
  if ( v14 )
    operator delete(v14);
  v15 = v1->sigilThreeSlot;
  v1->sigilTwoSlot = 0;
  if ( v15 )
    operator delete(v15);
  v16 = v1->headSlot;
  v1->sigilThreeSlot = 0;
  if ( v16 )
    operator delete(v16);
  v17 = v1->chestSlot;
  v1->headSlot = 0;
  if ( v17 )
    operator delete(v17);
  v18 = v1->abdomenSlot;
  v1->chestSlot = 0;
  if ( v18 )
    operator delete(v18);
  v19 = v1->upperArmSlot;
  v1->abdomenSlot = 0;
  if ( v19 )
    operator delete(v19);
  v20 = v1->lowerArmSlot;
  v1->upperArmSlot = 0;
  if ( v20 )
    operator delete(v20);
  v21 = v1->handSlot;
  v1->lowerArmSlot = 0;
  if ( v21 )
    operator delete(v21);
  v22 = v1->upperLegSlot;
  v1->handSlot = 0;
  if ( v22 )
    operator delete(v22);
  v23 = v1->lowerLegSlot;
  v1->upperLegSlot = 0;
  if ( v23 )
    operator delete(v23);
  v24 = v1->footSlot;
  v1->lowerLegSlot = 0;
  if ( v24 )
    operator delete(v24);
  v1->footSlot = 0;
}

//----- (0055E700) --------------------------------------------------------  // acclient.c:396787
char __thiscall List<ObjectRangeInfo>::insert(List<ObjectRangeInfo> *this, ListNode<ObjectRangeInfo> *node, ObjectRangeInfo *val)
{
  List<ObjectRangeInfo> *v3; // ebx@1
  void *v4; // eax@1
  char result; // al@3
  ListNode<ObjectRangeInfo> *v6; // edx@5

  v3 = this;
  v4 = operator new(0x48u);
  if ( v4 )
  {
    qmemcpy(v4, val, 0x40u);
    *((_DWORD *)v4 + 16) = 0;
    *((_DWORD *)v4 + 17) = 0;
    if ( v3->_head )
    {
      *((_DWORD *)v4 + 16) = node;
      *((_DWORD *)v4 + 17) = node->prev;
      v6 = node->prev;
      if ( v6 )
      {
        v6->next = (ListNode<ObjectRangeInfo> *)v4;
        node->prev = (ListNode<ObjectRangeInfo> *)v4;
        ++v3->_num_elements;
        result = 1;
      }
      else
      {
        v3->_head = (ListNode<ObjectRangeInfo> *)v4;
        node->prev = (ListNode<ObjectRangeInfo> *)v4;
        ++v3->_num_elements;
        result = 1;
      }
    }
    else
    {
      v3->_head = (ListNode<ObjectRangeInfo> *)v4;
      v3->_tail = (ListNode<ObjectRangeInfo> *)v4;
      ++v3->_num_elements;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0055E780) --------------------------------------------------------  // acclient.c:396837
int __thiscall InterfacePtr<Interface>::_QueryInterface(void *this, int a2, int a3)
{
  void *v3; // esi@1
  int v4; // eax@2
  int v5; // edi@2
  int v6; // ecx@2
  int result; // eax@5
  int v8; // ebx@6
  int v9; // ecx@9
  char v10; // [sp+Ch] [bp-4h]@2

  v3 = this;
  if ( a3 )
  {
    v4 = *(_DWORD *)a3;
    a3 = 0;
    v5 = *(_DWORD *)(*(int (__stdcall **)(char *, Turbine_GUID *, int *))(v4 + 12))(&v10, &stru_7CC6B4, &a3);
    v6 = *(_DWORD *)v3;
    if ( v5 >= 0 )
    {
      v8 = a3;
      if ( v6 )
        (*(void (**)(void))(*(_DWORD *)v6 + 20))();
      result = a2;
      *(_DWORD *)v3 = v8;
      *((_DWORD *)v3 + 1) = 0;
      *(_DWORD *)a2 = v5;
    }
    else
    {
      if ( v6 )
        (*(void (**)(void))(*(_DWORD *)v6 + 20))();
      result = a2;
      *(_DWORD *)v3 = 0;
      *((_DWORD *)v3 + 1) = 0;
      *(_DWORD *)a2 = v5;
    }
  }
  else
  {
    v9 = *(_DWORD *)this;
    if ( *(_DWORD *)v3 )
    {
      *(_DWORD *)v3 = 0;
      (*(void (**)(void))(*(_DWORD *)v9 + 20))();
      *((_DWORD *)v3 + 1) = 0;
    }
    result = a2;
    *(_DWORD *)a2 = -2147467262;
  }
  return result;
}

//----- (0055E810) --------------------------------------------------------  // acclient.c:396891
void __thiscall AC1Legacy::PStringBase<unsigned short>::set(AC1Legacy::PStringBase<unsigned short> *this, const unsigned __int16 *str)
{
  AC1Legacy::PStringBase<unsigned short> *v2; // edi@1
  AC1Legacy::PSRefBuffer<unsigned short> *v3; // esi@3
  unsigned int v4; // eax@6
  AC1Legacy::PSRefBuffer<unsigned short> *v5; // esi@8
  int v6; // eax@12

  v2 = this;
  if ( str && *str )
  {
    v3 = this->m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&this->m_buffer->m_cRef) )
    {
      if ( v3 )
        v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
    }
    v4 = _wcslen(str);
    AC1Legacy::PStringBase<unsigned short>::allocate_ref_buffer(v2, v4);
    _wcscpy(v2->m_buffer->m_data, str);
  }
  else
  {
    v5 = this->m_buffer;
    if ( this->m_buffer != (AC1Legacy::PSRefBuffer<unsigned short> *)AC1Legacy::PStringBase<unsigned short>::s_NullBuffer )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
        v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
      v6 = AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;
      v2->m_buffer = (AC1Legacy::PSRefBuffer<unsigned short> *)AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(v6 + 4));
    }
  }
}
// 8EE11C: using guessed type int AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;

//----- (0055E8B0) --------------------------------------------------------  // acclient.c:396928
void __thiscall CPlayerSystem::Handle_CharGenVerificationResponse(CPlayerSystem *this, void *buff, unsigned int size)
{
  CPlayerSystem *v3; // esi@1
  char *v4; // ebp@1
  int v5; // ecx@1
  CharacterSet *v6; // edi@2
  bool v7; // bl@2
  CharGenState *v8; // eax@2
  int v9; // eax@4
  CharacterIdentity *v10; // eax@4
  CharGenState *v11; // eax@6
  CharGenState *v12; // eax@8
  CharGenState *v13; // eax@8
  CharGenState *v14; // eax@9
  CharGenState *v15; // eax@9
  CharGenState *v16; // eax@10
  CharGenState *v17; // eax@10
  CharGenState *v18; // eax@11
  CharGenState *v19; // eax@11
  ClientCharGenState *v20; // eax@13
  ClientCharGenState *v21; // eax@14
  ClientCharGenState *v22; // eax@18
  ClientCharGenState *v23; // eax@19
  CharacterIdentity ident; // [sp+8h] [bp-10h]@3

  v3 = this;
  v4 = (char *)buff + size;
  v5 = *(_DWORD *)buff;
  buff = (char *)buff + 4;
  switch ( v5 )
  {
    case 1:
      v6 = (CharacterSet *)(((int (*)(void))UIFlow::m_instance->vfptr[1].QueryInterface)() + 4);
      v7 = 0;
      CPlayerSystem::GetCharGenState(v3);
      if ( CharGenState::GetVerificationState(v8) == 2 )
      {
        CharacterIdentity::CharacterIdentity(&ident);
        CharacterIdentity::UnPack(&ident, &buff, v4 - (_BYTE *)buff);
        v7 = CharacterSet::AddIdentity(v6, &ident) != 0;
        CharacterIdentity::~CharacterIdentity(&ident);
      }
      else
      {
        CPlayerSystem::GetCharGenState(v3);
        v10 = CharacterSet::GetIdentity(v6, *(_DWORD *)(v9 + 520));
        if ( v10 )
          v7 = ((int (__thiscall *)(CharacterIdentity *, void **, int))v10->vfptr->UnPack)(
                 v10,
                 &buff,
                 v4 - (_BYTE *)buff) != 0;
      }
      CM_CharGen::SendNotice_CharGenVerificationResponse(CG_VERIFICATION_RESPONSE_OK);
      CPlayerSystem::GetCharGenState(v3);
      CharGenState::SetVerificationState(v11, 0);
      if ( v7 )
        ECM_Character::SendNotice_CharacterSet(v6);
      break;
    case 3:
      CPlayerSystem::GetCharGenState(v3);
      CharGenState::SetSlot(v12, -1);
      CPlayerSystem::GetCharGenState(v3);
      CharGenState::SetVerificationState(v13, 0);
      CM_CharGen::SendNotice_CharGenVerificationResponse(CG_VERIFICATION_RESPONSE_NAME_IN_USE);
      break;
    case 7:
      CPlayerSystem::GetCharGenState(v3);
      CharGenState::SetSlot(v14, -1);
      CPlayerSystem::GetCharGenState(v3);
      CharGenState::SetVerificationState(v15, 0);
      CM_CharGen::SendNotice_CharGenVerificationResponse(CG_VERIFICATION_RESPONSE_ADMIN_PRIVILEGE_DENIED);
      break;
    case 4:
      CPlayerSystem::GetCharGenState(v3);
      CharGenState::SetSlot(v16, -1);
      CPlayerSystem::GetCharGenState(v3);
      CharGenState::SetVerificationState(v17, 0);
      CM_CharGen::SendNotice_CharGenVerificationResponse(CG_VERIFICATION_RESPONSE_NAME_BANNED);
      break;
    case 5:
    case 6:
      CPlayerSystem::GetCharGenState(v3);
      CharGenState::SetSlot(v18, -1);
      CPlayerSystem::GetCharGenState(v3);
      CharGenState::SetVerificationState(v19, 0);
      CM_CharGen::SendNotice_CharGenVerificationResponse(CG_VERIFICATION_RESPONSE_CORRUPT);
      break;
    default:
      if ( !v3->m_pCharGenState )
      {
        v20 = (ClientCharGenState *)operator new(0x268u);
        if ( v20 )
          ClientCharGenState::ClientCharGenState(v20);
        else
          v21 = 0;
        v3->m_pCharGenState = v21;
      }
      CharGenState::SetSlot((CharGenState *)&v3->m_pCharGenState->vfptr, -1);
      if ( !v3->m_pCharGenState )
      {
        v22 = (ClientCharGenState *)operator new(0x268u);
        if ( v22 )
          ClientCharGenState::ClientCharGenState(v22);
        else
          v23 = 0;
        v3->m_pCharGenState = v23;
      }
      CharGenState::SetVerificationState((CharGenState *)&v3->m_pCharGenState->vfptr, 0);
      CM_CharGen::SendNotice_CharGenVerificationResponse(0);
      break;
  }
}
// 83D72C: using guessed type struct UIFlow *UIFlow::m_instance;

//----- (0055EB00) --------------------------------------------------------  // acclient.c:397043
ComponentTrackerUpdate __thiscall CPlayerSystem::UpdateSpellComponent(CPlayerSystem *this, ACCWeenieObject *_weenObj, int _updateUI)
{
  CPlayerSystem *v3; // esi@1
  ACCWeenieObject *v4; // ST00_4@2
  ComponentTracker *v5; // eax@2
  ComponentTrackerUpdate result; // eax@4
  unsigned int v7; // edi@5
  void *v8; // eax@5
  NIListElement<unsigned long> *v9; // ecx@6
  NIListElement<unsigned long> *v10; // ecx@8

  v3 = this;
  if ( this->playerID )
  {
    v4 = _weenObj;
    CPlayerSystem::GetComponentTracker(this);
    ComponentTracker::UpdateComponent(v5, v4, (ComponentTrackerUpdate *)&_weenObj);
    if ( _updateUI )
      CM_Magic::SendNotice_UpdateSpellComponents((int)_weenObj);
    result = (ComponentTrackerUpdate)_weenObj;
  }
  else
  {
    v7 = _weenObj->id;
    v8 = operator new(8u);
    if ( v8 )
    {
      v9 = v3->pending_components_list.head_;
      *(_DWORD *)v8 = v7;
      *((_DWORD *)v8 + 1) = v9;
    }
    else
    {
      v8 = 0;
    }
    v10 = v3->pending_components_list.tail_;
    v3->pending_components_list.head_ = (NIListElement<unsigned long> *)v8;
    if ( !v10 )
      v3->pending_components_list.tail_ = (NIListElement<unsigned long> *)v8;
    result = 0;
  }
  return result;
}

//----- (0055EB90) --------------------------------------------------------  // acclient.c:397088
void __thiscall CPlayerSystem::UnregisterObjectRangeHandler(CPlayerSystem *this, ObjectRangeHandler *_handler, unsigned int _objectID)
{
  ListNode<ObjectRangeInfo> *i; // eax@1

  for ( i = this->m_objectRangeCheckList._head; i; i = i->next )
  {
    if ( i->data.m_handler == _handler && i->data.m_objectID == _objectID )
      i->data.m_queuedForDeletion = 1;
  }
}

//----- (0055EBC0) --------------------------------------------------------  // acclient.c:397100
void __thiscall CPlayerSystem::UnregisterAllObjectRangeHandlers(CPlayerSystem *this, ObjectRangeHandler *_handler)
{
  ListNode<ObjectRangeInfo> *i; // eax@1

  for ( i = this->m_objectRangeCheckList._head; i; i = i->next )
  {
    if ( i->data.m_handler == _handler )
      i->data.m_queuedForDeletion = 1;
  }
}

//----- (0055EBF0) --------------------------------------------------------  // acclient.c:397112
int __thiscall PackableHashTable<unsigned long,CContractTracker>::remove(PackableHashTable<unsigned long,CContractTracker> *this, const unsigned int *key, CContractTracker *retval)
{
  PackableHashTable<unsigned long,CContractTracker> *v3; // ebx@1
  unsigned int v4; // edi@1
  PackableHashData<unsigned long,CContractTracker> **v5; // esi@2
  const unsigned int v6; // edx@3
  PackableHashData<unsigned long,CContractTracker> *v7; // edi@3
  PackableHashData<unsigned long,CContractTracker> *v8; // esi@3
  int result; // eax@6
  PackableHashData<unsigned long,CContractTracker> *v10; // ecx@7

  v3 = this;
  v4 = this->_table_size;
  if ( v4 && (v5 = this->_buckets) != 0 && (v6 = *key % v4, v7 = 0, (v8 = v5[v6]) != 0) )
  {
    while ( v8->_key != *key )
    {
      v7 = v8;
      v8 = v8->_next;
      if ( !v8 )
        goto LABEL_6;
    }
    CContractTracker::operator=((int)retval, (int)&v8->_data);
    v10 = v8->_next;
    if ( v7 )
      v7->_next = v10;
    else
      v3->_buckets[*key % v3->_table_size] = v10;
    v8->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
    operator delete(v8);
    --v3->_currNum;
    result = 1;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0055EC80) --------------------------------------------------------  // acclient.c:397155
char __thiscall List<ObjectRangeInfo>::remove(List<ObjectRangeInfo> *this, ListNode<ObjectRangeInfo> *node)
{
  ListNode<ObjectRangeInfo> *v2; // edx@1
  List<ObjectRangeInfo> *v3; // esi@1
  ListNode<ObjectRangeInfo> *v4; // ecx@2
  ListNode<ObjectRangeInfo> *v6; // ecx@5

  v2 = 0;
  v3 = this;
  if ( !node )
    return 0;
  v4 = this->_head;
  if ( !v4 )
    return 0;
  if ( node != v4 )
  {
    node->prev->next = node->next;
    v6 = node->next;
    if ( !v6 )
    {
      v3->_tail = node->prev;
      goto LABEL_11;
    }
    v2 = node->prev;
    goto LABEL_9;
  }
  v6 = node->next;
  v3->_head = v6;
  if ( v6 )
  {
LABEL_9:
    v6->prev = v2;
    goto LABEL_11;
  }
  v3->_tail = 0;
LABEL_11:
  operator delete(node);
  --v3->_num_elements;
  return 1;
}

//----- (0055ECF0) --------------------------------------------------------  // acclient.c:397197
void __thiscall CPlayerSystem::OnShutdown(CPlayerSystem *this)
{
  CPlayerSystem *v1; // esi@1
  Interface *v2; // esi@3
  Interface *v3; // ST08_4@3
  InterfaceSystem *v4; // eax@3
  char v5; // [sp+4h] [bp-10h]@3
  TResult tr; // [sp+8h] [bp-Ch]@3
  InterfacePtr<Interface> spcIFace; // [sp+Ch] [bp-8h]@3

  v1 = this;
  if ( CPlayerSystem::s_pPlayerSystem )
  {
    ((void (*)(void))CPlayerSystem::s_pPlayerSystem->vfptr->Release)();
    CPlayerSystem::s_pPlayerSystem = 0;
  }
  spcIFace.m_pInterface = 0;
  spcIFace.m_trStatus.m_val = 0;
  InterfacePtr<Interface>::_QueryInterface(&spcIFace, (int)&v5, (int)&v1->playerModule);
  v2 = spcIFace.m_pInterface;
  v3 = spcIFace.m_pInterface;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::UnregisterClassA(v4, &tr, &CPlayerModule_ClassType_5, v3, 0);
  if ( v2 )
    v2->vfptr->Release(v2);
}
// 87018C: using guessed type struct CPlayerSystem *CPlayerSystem::s_pPlayerSystem;

//----- (0055ED60) --------------------------------------------------------  // acclient.c:397226
char __thiscall CPlayerSystem::AutoWieldIsLegal(CPlayerSystem *this, unsigned int _item, int _quiet)
{
  CPlayerSystem *v3; // esi@1
  HashBaseData<unsigned long> *v4; // eax@1
  ACCWeenieObject *v5; // edi@1
  HashBaseData<unsigned long>Vtbl *v7; // ebx@3
  unsigned int *v8; // ecx@4
  unsigned int v9; // esi@4
  HashBaseData<unsigned long> *v10; // eax@6
  HashBaseData<unsigned long> *v11; // ecx@7
  PStringBase<unsigned short> *v12; // eax@10
  HashBaseData<unsigned long> *v13; // eax@15
  ACCWeenieObject *v14; // esi@15
  PSRefBufferCharData<unsigned short> *v15; // ST0C_4@18
  int v16; // eax@21
  PSRefBufferCharData<unsigned short> *v17; // ST0C_4@23
  PStringBase<unsigned short> errorText; // [sp+8h] [bp-98h]@10
  PStringBase<unsigned short> result; // [sp+Ch] [bp-94h]@10
  StringInfo siError; // [sp+10h] [bp-90h]@10

  v3 = this;
  v4 = ClientObjMaintSystem::GetWeenieObject(_item);
  v5 = (ACCWeenieObject *)v4;
  if ( !v4 )
    return 0;
  v7 = v4[16].vfptr;
  if ( !((unsigned int)v7 & 0x7FFFFFFF) )
    return 0;
  v8 = &v3->m_invSlotModule.weaponReadySlot->m_itemID;
  v9 = *v8;
  if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & (unsigned int)v7 )
  {
    if ( v9 )
    {
      v10 = ClientObjMaintSystem::GetWeenieObject(*v8);
      if ( v10 )
      {
        v11 = v10[19].hash_next;
        if ( v11 )
        {
          if ( v11 != (HashBaseData<unsigned long> *)v5->pwd._ammoType )
          {
            if ( _quiet )
              return 0;
            v12 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v10, &result, NAME_APPROPRIATE, 0);
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &errorText,
              0,
              L"Cannot be used with %s",
              v12->m_charbuffer);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
            StringInfo::StringInfo(&siError);
            StringInfo::SetLiteralValue(&siError, &errorText, 1);
            ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_11:
            StringInfo::~StringInfo(&siError);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
            return 0;
          }
        }
      }
    }
  }
  if ( (unsigned int)v7 & 0x200000 )
  {
    if ( v9 )
    {
      v13 = ClientObjMaintSystem::GetWeenieObject(v9);
      v14 = (ACCWeenieObject *)v13;
      if ( v13 )
      {
        if ( ACCWeenieObject::BlocksUseOfShield((ACCWeenieObject *)v13) )
        {
          if ( _quiet )
            return 0;
          v15 = ACCWeenieObject::GetObjectNameWide(v14, &result, 0, 0)->m_charbuffer;
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            &errorText,
            0,
            L"A shield may not be worn with the %s",
            v15);
          goto LABEL_24;
        }
      }
    }
  }
  if ( (unsigned int)v7 & 0x1000000 )
  {
    if ( ClientCombatSystem::GetCombatSystem()->combatMode != 1 )
    {
      v16 = ((int (__thiscall *)(ACCWeenieObject *))v5->vfptr[6].__vecDelDtor)(v5);
      if ( SBYTE1(v16) >= 0 )
      {
        if ( _quiet )
          return 0;
        v17 = ACCWeenieObject::GetObjectNameWide(v5, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
        PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"Cannot hold %s while in combat", v17);
LABEL_24:
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        StringInfo::StringInfo(&siError);
        StringInfo::SetLiteralValue(&siError, &errorText, 1);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        goto LABEL_11;
      }
    }
  }
  return 1;
}
// 7CC7E8: using guessed type wchar_t aAShieldMayNotB[37];

//----- (0055EF40) --------------------------------------------------------  // acclient.c:397337
char __thiscall CPlayerSystem::AutoWearIsLegal(CPlayerSystem *this, unsigned int _item, int *_blockedBySelf, int _quiet)
{
  CPlayerSystem *v4; // ebx@1
  HashBaseData<unsigned long> *v6; // eax@3
  HashBaseData<unsigned long> *v7; // esi@3
  HashBaseData<unsigned long> *v8; // eax@7
  ACCWeenieObject *v9; // edi@7
  PSRefBufferCharData<unsigned short> *v10; // ST0C_4@12
  unsigned int v11; // eax@13
  HashBaseData<unsigned long> *v12; // eax@13
  PSRefBufferCharData<unsigned short> *v13; // ST0C_4@14
  PStringBase<unsigned short> errorText; // [sp+4h] [bp-98h]@12
  PStringBase<unsigned short> result; // [sp+8h] [bp-94h]@12
  StringInfo siError; // [sp+Ch] [bp-90h]@15

  v4 = this;
  *_blockedBySelf = 0;
  if ( !ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(0) )
    return 0;
  v6 = ClientObjMaintSystem::GetWeenieObject(_item);
  v7 = v6;
  if ( v6 && (unsigned int)v6[16].vfptr & 0x8007FFF )
  {
    if ( !(v4->clothingPriorityMask & v6[15].id) )
      return 1;
    v8 = ClientObjMaintSystem::GetWeenieObject(v4->playerID);
    v9 = (ACCWeenieObject *)v8;
    if ( v8 )
    {
      if ( ACCWeenieObject::GetLocationOnObject((ACCWeenieObject *)v8, _item) )
        *_blockedBySelf = 1;
    }
    if ( !_quiet )
    {
      if ( *_blockedBySelf )
      {
        v10 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v7, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
        PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"The %s is already being worn", v10);
LABEL_15:
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        StringInfo::StringInfo(&siError);
        StringInfo::SetLiteralValue(&siError, &errorText, 1);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
        return 0;
      }
      v11 = (unsigned int)ACCWeenieObject::GetObjectAtLocation(
                            v9,
                            (unsigned int)v7[16].vfptr & v4->inventoryMask,
                            v7[15].id);
      v12 = ClientObjMaintSystem::GetWeenieObject(v11);
      if ( v12 )
      {
        v13 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v12, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &errorText,
          0,
          L"You must remove your %s to wear that",
          v13);
        goto LABEL_15;
      }
    }
  }
  return 0;
}
// 7CC8B4: using guessed type wchar_t aTheSIsAlreadyB[29];

//----- (0055F0C0) --------------------------------------------------------  // acclient.c:397406
void __thiscall CPlayerSystem::UpdateContractTrackerTable(CPlayerSystem *this, CContractTrackerTable *contractTrackerTable)
{
  CContractTrackerTable *v2; // edi@1
  PackableHashData<unsigned long,CContractTracker> *v3; // esi@2
  unsigned int v4; // ebx@3
  PackableHashData<unsigned long,CContractTracker> **v5; // edi@3
  PackableHashData<unsigned long,CContractTracker> *v6; // eax@4
  int v7; // eax@5
  unsigned int key; // [sp+10h] [bp-40h]@4
  PackableHashTable<unsigned long,CContractTracker> *v9; // [sp+14h] [bp-3Ch]@1
  PackableHashIterator<unsigned long,CContractTracker> iter; // [sp+18h] [bp-38h]@2
  CContractTracker contractTracker; // [sp+28h] [bp-28h]@4

  v9 = &this->m_contractTrackerTable._contractTrackerHash;
  PackableHashTable<unsigned long,CContractTracker>::EmptyContents((PackableHashTable<unsigned long,GeneratorRegistryNode> *)&this->m_contractTrackerTable._contractTrackerHash);
  v2 = contractTrackerTable;
  if ( contractTrackerTable->_contractTrackerHash._currNum )
  {
    PackableHashTable<unsigned long,CContractTracker>::begin(&contractTrackerTable->_contractTrackerHash, &iter);
    v3 = iter._current;
    if ( iter._current )
    {
      v4 = iter._table_size;
      v5 = iter._buckets;
      do
      {
        CContractTracker::CContractTracker(&contractTracker, &v3->_data);
        *(_QWORD *)&contractTracker._time_of_server_update = Timer::cur_time;
        key = contractTracker._contract_id;
        PackableHashTable<unsigned long,CContractTracker>::add(v9, &key, &contractTracker);
        v6 = v3->_next;
        contractTracker.vfptr = (PackObjVtbl *)&PackObj::vftable;
        if ( !v6 )
        {
          v7 = v3->_hashVal + 1;
          if ( v7 >= v4 )
          {
LABEL_8:
            v6 = 0;
          }
          else
          {
            while ( !v5[v7] )
            {
              ++v7;
              if ( v7 >= v4 )
                goto LABEL_8;
            }
            v6 = v5[v7];
          }
        }
        v3 = v6;
      }
      while ( v6 );
      v2 = contractTrackerTable;
    }
  }
  CM_Social::SendNotice_UpdateContractTrackerTable(v2);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0055F190) --------------------------------------------------------  // acclient.c:397468
void __thiscall CPlayerSystem::UpdateContractTracker(CPlayerSystem *this, CContractTracker contractTracker, int deleteContract)
{
  int v3; // ebx@1
  char *v4; // edi@1
  unsigned int v5; // ecx@1
  int v6; // esi@2
  int v7; // edx@3
  int v8; // esi@6
  int v9; // ebp@7
  int v10; // edx@13
  int v11; // ecx@13
  unsigned int v12; // eax@13

  v3 = contractTracker._contract_id;
  v4 = (char *)&this->m_contractTrackerTable._contractTrackerHash;
  v5 = this->m_contractTrackerTable._contractTrackerHash._table_size;
  if ( v5 && (v6 = *((_DWORD *)v4 + 2)) != 0 && (v7 = *(_DWORD *)(v6 + 4 * (contractTracker._contract_id % v5))) != 0 )
  {
    while ( contractTracker._contract_id != *(_DWORD *)v7 )
    {
      v7 = *(_DWORD *)(v7 + 48);
      if ( !v7 )
        goto LABEL_6;
    }
    v8 = v7 + 8;
  }
  else
  {
LABEL_6:
    v8 = 0;
  }
  v9 = deleteContract;
  if ( deleteContract )
  {
    if ( !v8 )
      goto LABEL_11;
    deleteContract = contractTracker._contract_id;
    PackableHashTable<unsigned long,CContractTracker>::remove(
      (PackableHashTable<unsigned long,CContractTracker> *)v4,
      (const unsigned int *)&deleteContract,
      &contractTracker);
    v3 = contractTracker._contract_id;
  }
  if ( v8 )
  {
    *(_DWORD *)(v8 + 12) = contractTracker._contract_stage;
    v10 = HIDWORD(contractTracker._time_when_done);
    *(_DWORD *)(v8 + 16) = LODWORD(contractTracker._time_when_done);
    *(_DWORD *)(v8 + 20) = v10;
    v11 = HIDWORD(contractTracker._time_when_repeats);
    *(_DWORD *)(v8 + 24) = LODWORD(contractTracker._time_when_repeats);
    *(_DWORD *)(v8 + 28) = v11;
    v12 = Timer::cur_time.Param;
    *(_DWORD *)(v8 + 32) = Timer::cur_time.Cmd;
    *(_DWORD *)(v8 + 36) = v12;
    goto LABEL_14;
  }
LABEL_11:
  *(_QWORD *)&contractTracker._time_of_server_update = Timer::cur_time;
  deleteContract = v3;
  PackableHashTable<unsigned long,CContractTracker>::add(
    (PackableHashTable<unsigned long,CContractTracker> *)v4,
    (const unsigned int *)&deleteContract,
    &contractTracker);
LABEL_14:
  CM_Social::SendNotice_UpdateContractTracker(&contractTracker, v9);
}

//----- (0055F270) --------------------------------------------------------  // acclient.c:397537
void __thiscall List<ObjectRangeInfo>::flush(List<ObjectRangeInfo> *this)
{
  List<ObjectRangeInfo> *i; // esi@1
  ListNode<ObjectRangeInfo> *v2; // ecx@2
  ListNode<ObjectRangeInfo> *v3; // eax@3

  for ( i = this; ; --i->_num_elements )
  {
    v2 = i->_head;
    if ( !v2 )
      break;
    v3 = v2->next;
    i->_head = v3;
    if ( v3 )
      v3->prev = 0;
    else
      i->_tail = 0;
    if ( v2 )
      operator delete(v2);
  }
}

//----- (0055F2B0) --------------------------------------------------------  // acclient.c:397560
void __thiscall CContractTrackerTable::~CContractTrackerTable(CContractTrackerTable *this)
{
  CContractTrackerTable *v1; // edi@1
  char *v2; // esi@1

  v1 = this;
  v2 = (char *)&this->_contractTrackerHash;
  this->vfptr = (PackObjVtbl *)&CContractTrackerTable::vftable;
  this->_contractTrackerHash.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,CContractTracker>::vftable;
  PackableHashTable<unsigned long,CContractTracker>::EmptyContents((PackableHashTable<unsigned long,GeneratorRegistryNode> *)&this->_contractTrackerHash);
  if ( *((_DWORD *)v2 + 2) )
  {
    operator delete[](*((void **)v2 + 2));
    *((_DWORD *)v2 + 2) = 0;
  }
  *((_DWORD *)v2 + 3) = 0;
  *(_DWORD *)v2 = &PackObj::vftable;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A6930: using guessed type int (__thiscall *PackableHashTable<unsigned long,CContractTracker>::vftable)(void *, char);
// 7CC8F0: using guessed type int (__thiscall *CContractTrackerTable::vftable)(void *, char);

//----- (0055F300) --------------------------------------------------------  // acclient.c:397584
CContractTrackerTable *__thiscall CContractTrackerTable::vector_deleting_destructor(CContractTrackerTable *this, unsigned int a2)
{
  CContractTrackerTable *v2; // edi@1
  char *v3; // esi@1

  v2 = this;
  v3 = (char *)&this->_contractTrackerHash;
  this->vfptr = (PackObjVtbl *)&CContractTrackerTable::vftable;
  this->_contractTrackerHash.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,CContractTracker>::vftable;
  PackableHashTable<unsigned long,CContractTracker>::EmptyContents((PackableHashTable<unsigned long,GeneratorRegistryNode> *)&this->_contractTrackerHash);
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
// 7A6930: using guessed type int (__thiscall *PackableHashTable<unsigned long,CContractTracker>::vftable)(void *, char);
// 7CC8F0: using guessed type int (__thiscall *CContractTrackerTable::vftable)(void *, char);

//----- (0055F360) --------------------------------------------------------  // acclient.c:397611
void __thiscall CPlayerSystem::CalculateObjectRangeChecks(CPlayerSystem *this)
{
  CPlayerSystem *v1; // ebp@1
  ListNode<ObjectRangeInfo> *v2; // esi@2
  ListNode<ObjectRangeInfo> *v3; // eax@4
  bool v4; // dl@6
  bool v5; // cl@6
  double curTime; // [sp+10h] [bp-8h]@2

  v1 = this;
  if ( this->m_objectRangeCheckList._head )
  {
    v2 = this->m_objectRangeCheckList._head;
    curTime = *(double *)&Timer::cur_time;
    if ( v2 )
    {
      while ( v2->data.m_queuedForDeletion )
      {
        v3 = v2;
        v2 = v2->next;
        List<ObjectRangeInfo>::remove(&v1->m_objectRangeCheckList, v3);
LABEL_15:
        if ( !v2 )
          return;
      }
      if ( curTime > v2->data.m_nextUpdate )
      {
        v4 = v2->data.m_ignoreZDelta;
        v5 = v2->data.m_useRadii;
        v2->data.m_nextUpdate = curTime + v2->data.m_timeInterval;
        if ( ACCWeenieObject::ObjectsInRange(v2->data.m_objectID, v1->playerID, v2->data.m_range, v5, v4) )
        {
          if ( v2->data.m_timeOut <= 0.0 || curTime <= v2->data.m_executeAtTime || !v2->data.m_handler )
            goto LABEL_14;
          ((void (__stdcall *)(_DWORD))v2->data.m_handler->vfptr->OnObjectRangeTimeout)(v2->data.m_objectID);
          goto LABEL_13;
        }
        if ( v2->data.m_handler )
        {
          ((void (__stdcall *)(_DWORD))v2->data.m_handler->vfptr->OnObjectRangeExit)(v2->data.m_objectID);
LABEL_13:
          v2->data.m_queuedForDeletion = 1;
          goto LABEL_14;
        }
      }
LABEL_14:
      v2 = v2->next;
      goto LABEL_15;
    }
  }
}

//----- (0055F460) --------------------------------------------------------  // acclient.c:397664
void __thiscall CPlayerSystem::RecvNotice_ItemAttributesChanged(CPlayerSystem *this, unsigned int i_target, unsigned int i_attrib)
{
  CPlayerSystem *v3; // ebp@1
  InterfaceSystem *v4; // eax@1
  Interface *v5; // esi@1
  ClientObjMaintSystem *v6; // edi@5
  HashBaseData<unsigned long> *v7; // esi@5
  int v8; // eax@6
  int v9; // [sp-8h] [bp-2Ch]@1
  Interface *_rpInterface; // [sp+10h] [bp-14h]@1
  TResult result; // [sp+14h] [bp-10h]@1
  char v12; // [sp+18h] [bp-Ch]@3
  InterfacePtr<ClientObjMaintSystem> spObjMaint; // [sp+1Ch] [bp-8h]@1

  v3 = this;
  _rpInterface = 0;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v4, &result, &ClientObjMaintSystem_ClassType_3, &_rpInterface);
  v9 = (int)_rpInterface;
  v5 = _rpInterface;
  spObjMaint.m_pInterface = 0;
  spObjMaint.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  InterfacePtr<ClientObjMaintSystem>::_QueryInterface(&spObjMaint, (int)&v12, v9, 0);
  if ( v5 )
    v5->vfptr->Release(v5);
  v6 = spObjMaint.m_pInterface;
  v7 = CObjectMaint::GetWeenieObject((CObjectMaint *)&spObjMaint.m_pInterface->vfptr, i_target);
  if ( v7 )
  {
    v8 = ((int (__thiscall *)(HashBaseData<unsigned long> *))v7->vfptr[6].__vecDelDtor)(v7);
    if ( BYTE1(v8) & 0x10 )
      CPlayerSystem::UpdateSpellComponent((CPlayerSystem *)((char *)v3 - 4), (ACCWeenieObject *)v7, 1);
  }
  if ( v6 )
    v6->vfptr->Release((Interface *)v6);
}

//----- (0055F510) --------------------------------------------------------  // acclient.c:397704
char __thiscall CPlayerSystem::OnLoadChanged(CPlayerSystem *this)
{
  CPlayerSystem *v1; // ebx@1
  InterfaceSystem *v2; // eax@1
  Interface *v3; // esi@1
  int v4; // ebp@3
  PlayerDesc *v5; // esi@5
  float v7; // ST08_4@18
  int v8; // [sp-8h] [bp-C0h]@1
  Interface *_rpInterface; // [sp+10h] [bp-A8h]@1
  float fNewLoad; // [sp+14h] [bp-A4h]@9
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+18h] [bp-A0h]@1
  TResult result; // [sp+20h] [bp-98h]@1
  char v13; // [sp+24h] [bp-94h]@3
  StringInfo siError; // [sp+28h] [bp-90h]@13

  v1 = this;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_26, &_rpInterface);
  v8 = (int)_rpInterface;
  v3 = _rpInterface;
  spPlayerDesc.m_pInterface = 0;
  spPlayerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&v13, v8, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v5 = spPlayerDesc.m_pInterface;
  if ( !(_DWORD)spPlayerDesc.m_pInterface )
    return 0;
  if ( v4 < 0 )
  {
    spPlayerDesc.m_pInterface->vfptr->Release((Interface *)spPlayerDesc.m_pInterface);
    return 0;
  }
  fNewLoad = 0.0;
  CACQualities::InqLoad((CACQualities *)&spPlayerDesc.m_pInterface->vfptr, &fNewLoad);
  if ( fNewLoad == v1->m_fLoad )
  {
    v5->vfptr->Release((Interface *)v5);
    return 1;
  }
  if ( v1->m_fLoad >= 2.0 || fNewLoad < 2.0 )
  {
    if ( v1->m_fLoad >= 1.0 || fNewLoad < 1.0 )
      goto LABEL_18;
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&_rpInterface,
      L"You are encumbered!");
    StringInfo::SetLiteralValue(&siError, (PStringBase<unsigned short> *)&_rpInterface, 1);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_rpInterface);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
  }
  else
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&_rpInterface,
      L"You are severely encumbered!");
    StringInfo::SetLiteralValue(&siError, (PStringBase<unsigned short> *)&_rpInterface, 1);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_rpInterface);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
  }
  StringInfo::~StringInfo(&siError);
LABEL_18:
  v7 = fNewLoad;
  v1->m_fLoad = fNewLoad;
  CM_Character::SendNotice_LoadChanged(v7);
  v5->vfptr->Release((Interface *)v5);
  return 1;
}

//----- (0055F6D0) --------------------------------------------------------  // acclient.c:397780
void __thiscall CPlayerSystem::Handle_Login__CharacterSet(CPlayerSystem *this, void *buff, unsigned int size)
{
  CPlayerSystem *v3; // ebp@1
  AC1Legacy::PSRefBuffer<char> *v4; // ebx@1
  int v5; // edx@1
  int v6; // eax@1
  int v7; // ecx@1
  AC1Legacy::PSRefBuffer<char> *v8; // esi@7
  unsigned int v9; // esi@8
  int v10; // edx@10
  int v11; // [sp-4h] [bp-68h]@1
  accountID v12; // [sp+10h] [bp-54h]@1
  CharacterSet charSet; // [sp+20h] [bp-44h]@1

  charSet.account_.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v3 = this;
  charSet.vfptr = (PackObjVtbl *)&CharacterSet::vftable;
  charSet.set_.m_data = 0;
  charSet.set_.m_size = 0;
  charSet.set_.m_num = 0;
  charSet.delSet_.m_data = 0;
  charSet.delSet_.m_size = 0;
  charSet.delSet_.m_num = 0;
  charSet.status_ = 0;
  charSet.numAllowedCharacters_ = 5;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  charSet.account_.fIsDarkMajestyExpansion_ = 0;
  charSet.account_.m_fIsThroneOfDestinyExpansion = 0;
  charSet.account_.m_fPreOrderedThroneOfDestinyExpansion = 0;
  charSet.name = 0;
  CharacterSet::UnPack(&charSet, &buff, size);
  accountID::accountID(&v12, &charSet.account_);
  v4 = v12.m_buffer;
  AC1Legacy::PStringBase<char>::set((AC1Legacy::PStringBase<char> *)&v3->account_.m_buffer, v12.m_buffer->m_data);
  v5 = v12.m_fIsThroneOfDestinyExpansion;
  v6 = v12.m_fPreOrderedThroneOfDestinyExpansion;
  v3->account_.fIsDarkMajestyExpansion_ = v12.fIsDarkMajestyExpansion_;
  v11 = (int)&v4->m_cRef;
  v3->account_.m_fIsThroneOfDestinyExpansion = v5;
  v3->account_.m_fPreOrderedThroneOfDestinyExpansion = v6;
  if ( !InterlockedDecrement((volatile LONG *)v11) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  if ( charSet.numAllowedCharacters_ == -1 )
    charSet.numAllowedCharacters_ = 20;
  if ( charSet.m_fUseTurbineChat )
  {
    v8 = v3->account_.m_buffer;
    v11 = v7;
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&v11, v8->m_data);
    if ( !CCommunicationSystem::StartupTurbineChat((AC1Legacy::PStringBase<char>)v11) )
    {
      size = AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::set(
        (AC1Legacy::PStringBase<char> *)&size,
        "Failed to startup Turbine chat!\n\nVerify that chatclient.dll is in your Asheron's Call directory and try again.");
      v9 = size;
      if ( !InterlockedDecrement((volatile LONG *)(size + 4)) )
      {
        if ( v9 )
        {
          v10 = *(_DWORD *)v9;
          v11 = 1;
          (*(void (__thiscall **)(unsigned int, signed int))v10)(v9, 1);
        }
      }
    }
  }
  v11 = (int)&charSet;
  v3->m_accountHasThroneofDestiny = 1;
  ECM_Character::SendNotice_CharacterSet((CharacterSet *)v11);
  CharacterSet::~CharacterSet(&charSet);
}
// 79E250: using guessed type int (__thiscall *CharacterSet::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0055F830) --------------------------------------------------------  // acclient.c:397857
void __thiscall CPlayerSystem::DeleteCharacter(CPlayerSystem *this, unsigned int i_iidAvatar)
{
  CPlayerSystem *v2; // esi@1
  int v3; // eax@1
  unsigned int v4; // eax@2
  unsigned int v5; // ecx@3
  accountID v6; // [sp-14h] [bp-18h]@3
  int v7; // [sp-4h] [bp-8h]@3

  v2 = this;
  v3 = ((int (*)(void))UIFlow::m_instance->vfptr[1].QueryInterface)();
  if ( v3 )
  {
    v4 = CharacterSet::GetSlot((CharacterSet *)(v3 + 4), i_iidAvatar);
    if ( v4 != -1 )
    {
      v7 = v4;
      accountID::accountID(&v6, &v2->account_);
      Proto_UI::SendDeleteCharacter(v6, v7);
      v5 = Timer::cur_time.Param;
      LODWORD(v2->deleteCharRequestTime) = Timer::cur_time.Cmd;
      HIDWORD(v2->deleteCharRequestTime) = v5;
    }
  }
}
// 83D72C: using guessed type struct UIFlow *UIFlow::m_instance;

//----- (0055F890) --------------------------------------------------------  // acclient.c:397885
char __thiscall CPlayerSystem::LogOnCharacter(CPlayerSystem *this, unsigned int i_iidAvatar)
{
  CPlayerSystem *v2; // esi@1
  int v3; // eax@2
  unsigned int v5; // edi@8
  ClientCombatSystem *v6; // eax@13
  unsigned int v7; // ecx@13
  accountID v8; // [sp-10h] [bp-18h]@13
  COMBAT_MODE v9; // [sp-8h] [bp-10h]@13
  CaseInsensitiveStringBase<PStringBase<char> > v10; // [sp-4h] [bp-Ch]@13

  v2 = this;
  if ( !this->fReadyToEnterGame )
  {
    v3 = ((int (*)(void))UIFlow::m_instance->vfptr[1].QueryInterface)();
    if ( v3 )
    {
      *(_DWORD *)(v3 + 76) = i_iidAvatar;
      if ( !v2->awaitingLogOn )
      {
        ClientNet::ExitWorldDisconnect((ClientNet *)SharedNet::s_pNet);
        Proto_UI::SendEnterWorldRequest();
      }
      v2->awaitingLogOn = 1;
    }
    return 0;
  }
  gmCCommunicationSystem::ClearSquelchDB();
  if ( PacketController::Instance() )
  {
    v5 = *(_DWORD *)(((int (*)(void))UIFlow::m_instance->vfptr[1].QueryInterface)() + 76);
    if ( !v5 )
      return 0;
    if ( SmartBox::smartbox )
      SmartBox::Reset(SmartBox::smartbox, 1);
    if ( IQueuedUIEventDeliverer::s_pInstance )
      ((void (*)(void))IQueuedUIEventDeliverer::s_pInstance->vfptr[1].Release)();
    accountID::accountID(&v8, &v2->account_);
    Proto_UI::SendEnterWorld(v5, v8);
    v2->inventoryMask = 0;
    v2->clothingPriorityMask = 0;
    gmCCommunicationSystem::SetTalkFocus(1u);
    v10.m_charbuffer = (PSRefBufferCharData<char> *)1;
    v9 = 1;
    v6 = ClientCombatSystem::GetCombatSystem();
    ClientCombatSystem::SetCombatMode(v6, v9, v10);
    v2->fReadyToEnterGame = 0;
    ClientNet::EnterWorld((ClientNet *)SharedNet::s_pNet);
    v7 = Timer::cur_time.Param;
    LODWORD(v2->logOnRequestTime) = Timer::cur_time.Cmd;
    HIDWORD(v2->logOnRequestTime) = v7;
  }
  CM_Login::SendNotice_BeginEnterWorld();
  return 1;
}
// 83D72C: using guessed type struct UIFlow *UIFlow::m_instance;

//----- (0055F9A0) --------------------------------------------------------  // acclient.c:397943
void __thiscall CPlayerSystem::SelectNext(CPlayerSystem *this, bool _closer, bool _extreme, UI_SELECTION_TYPE sel_type, bool _ignore_wielded)
{
  InterfaceSystem *v5; // eax@1
  unsigned int v6; // esi@1
  unsigned int v7; // eax@5
  ClientObjMaintSystem *v8; // edi@7
  HashBaseData<unsigned long> *v9; // eax@7
  double v10; // st7@10
  bool v11; // al@12
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v12; // eax@15
  IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *v13; // ecx@15
  HashSetData<unsigned long> **v14; // edx@15
  HashSetData<unsigned long> *v15; // eax@15
  unsigned int v16; // esi@21
  CObjectMaint *v17; // edi@23
  HashBaseData<unsigned long> *v18; // ebx@23
  HashBaseData<unsigned long> *v19; // edi@23
  int v20; // eax@23
  bool v21; // zf@33
  HashBaseData<unsigned long> *v22; // eax@35
  ClientCombatSystem *v23; // edi@41
  COMBAT_MODE v24; // eax@41
  HashBaseData<unsigned long> *v25; // eax@45
  HashSetData<unsigned long> **v26; // ecx@55
  HashSetData<unsigned long> **v27; // eax@56
  HashSetData<unsigned long> *v28; // ecx@58
  double v29; // st7@66
  long double v30; // kr00_8@69
  HashSetData<unsigned long> **v31; // ecx@78
  HashSetData<unsigned long> **v32; // eax@78
  int v33; // [sp+8h] [bp-70h]@1
  int invalid_to_show; // [sp+1Ch] [bp-5Ch]@28
  CPlayerSystem *v35; // [sp+20h] [bp-58h]@1
  unsigned int oldObjID; // [sp+24h] [bp-54h]@1
  unsigned int newSelectionID; // [sp+28h] [bp-50h]@1
  CPhysicsObj *physobj; // [sp+2Ch] [bp-4Ch]@3
  long double dist; // [sp+30h] [bp-48h]@1
  long double curBestDist; // [sp+38h] [bp-40h]@10
  long double distToBeat; // [sp+40h] [bp-38h]@12
  InterfacePtr<ClientObjMaintSystem> spObjMaint; // [sp+4Ch] [bp-2Ch]@1
  HashSetIterator<unsigned long> id_iter; // [sp+54h] [bp-24h]@15
  AC1Legacy::Vector3 point; // [sp+60h] [bp-18h]@10
  AC1Legacy::Vector3 object_pos; // [sp+6Ch] [bp-Ch]@15

  v35 = this;
  newSelectionID = 0;
  oldObjID = 0;
  v5 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v5, (TResult *)&dist, &ClientObjMaintSystem_ClassType_3, (Interface **)&oldObjID);
  v33 = oldObjID;
  v6 = oldObjID;
  spObjMaint.m_pInterface = 0;
  spObjMaint.m_trStatus.m_val = 0;
  if ( oldObjID )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)oldObjID + 16))(oldObjID);
  InterfacePtr<ClientObjMaintSystem>::_QueryInterface(&spObjMaint, (int)&physobj, v33, 0);
  if ( v6 )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v6 + 20))(v6);
  v7 = ACCWeenieObject::selectedID;
  oldObjID = ACCWeenieObject::selectedID;
  if ( ACCWeenieObject::selectedID == Formatted )
  {
    v7 = ACCWeenieObject::prevSelectedID;
    oldObjID = ACCWeenieObject::prevSelectedID;
  }
  v8 = spObjMaint.m_pInterface;
  v9 = CObjectMaint::GetObjectA((CObjectMaint *)&spObjMaint.m_pInterface->vfptr, v7);
  if ( !_extreme && v9 && v9[12].vfptr )
  {
    SmartBox::convert_to_player_space(SmartBox::smartbox, (CPhysicsObj *)v9, &point);
    curBestDist = point.y;
    dist = point.x;
    v10 = point.z;
    if ( point.z < 0.0 )
      v10 = -v10;
    v11 = _closer;
    distToBeat = sqrt(pow(curBestDist, 2.0) + pow(dist, 2.0)) + v10 * 1.2;
LABEL_13:
    HIDWORD(curBestDist) = 0;
    if ( v11 )
      goto LABEL_15;
    goto LABEL_14;
  }
  v11 = _closer == 0;
  v21 = _closer != 0;
  _closer = _closer == 0;
  LODWORD(distToBeat) = 0;
  if ( !v21 )
  {
    HIDWORD(distToBeat) = 1089601536;
    goto LABEL_13;
  }
  HIDWORD(distToBeat) = 0;
LABEL_14:
  HIDWORD(curBestDist) = 1089601536;
LABEL_15:
  LODWORD(curBestDist) = 0;
  v12 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v8->visible_object_table.m_intrusiveTable,
          (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&object_pos);
  v13 = (IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *)v12->m_currHashTable;
  v14 = (HashSetData<unsigned long> **)v12->m_currBucket;
  v15 = (HashSetData<unsigned long> *)v12->m_currElement;
  id_iter.m_iter.m_currHashTable = v13;
  id_iter.m_iter.m_currBucket = v14;
  id_iter.m_iter.m_currElement = v15;
  if ( !v15 )
    goto LABEL_86;
  while ( 1 )
  {
    v16 = id_iter.m_iter.m_currElement->m_hashKey;
    if ( !id_iter.m_iter.m_currElement->m_hashKey || v16 == v35->lastFullyMergedSrcID )
      goto LABEL_77;
    v17 = (CObjectMaint *)&v8->vfptr;
    v18 = CObjectMaint::GetWeenieObject(v17, id_iter.m_iter.m_currElement->m_hashKey);
    v19 = CObjectMaint::GetObjectA(v17, v16);
    v20 = 0;
    physobj = (CPhysicsObj *)v19;
    if ( v19 )
      v20 = SmartBox::convert_to_player_space(SmartBox::smartbox, (CPhysicsObj *)v19, &object_pos);
    if ( !v18 || !v19 || !v20 )
      goto LABEL_77;
    invalid_to_show = 0;
    switch ( sel_type )
    {
      case 5:
        if ( !((int (__thiscall *)(HashBaseData<unsigned long> *))v18->vfptr[31].__vecDelDtor)(v18)
          || ACCWeenieObject::HasCorpseBeenOpened(v18->id) )
          goto LABEL_52;
        break;
      case 4:
        if ( !((int (__thiscall *)(HashBaseData<unsigned long> *))v18->vfptr[4].__vecDelDtor)(v18) )
          goto LABEL_52;
        v21 = ACCWeenieObject::InqShowableOnRadar((ACCWeenieObject *)v18, &object_pos) == 0;
        goto LABEL_51;
      case 3:
        ClientCombatSystem::GetCombatSystem();
        LODWORD(dist) = ClientFellowshipSystem::GetFellowshipSystem();
        if ( !ClientCombatSystem::ObjectIsAttackable(v16) )
          goto LABEL_52;
        v22 = v18[21].hash_next;
        if ( BYTE1(v22) & 2
          || !ACCWeenieObject::InqShowableOnRadar((ACCWeenieObject *)v18, &object_pos)
          || ClientFellowshipSystem::IsFellow(LODWORD(dist), v16) )
          goto LABEL_52;
        break;
      case 2:
        if ( !((unsigned int)v18[21].hash_next & 0x8044000)
          && !ACCWeenieObject::InqShowableOnRadar((ACCWeenieObject *)v18, &object_pos) )
          goto LABEL_52;
        v23 = ClientCombatSystem::GetCombatSystem();
        LODWORD(dist) = ClientFellowshipSystem::GetFellowshipSystem();
        v24 = v23->combatMode;
        if ( v24 == 2 || v24 == 4 )
        {
          if ( !ClientCombatSystem::ObjectIsAttackable(v16) )
            goto LABEL_52;
          if ( ClientFellowshipSystem::IsFellow(LODWORD(dist), v16) )
            goto LABEL_52;
          v25 = v18[21].hash_next;
          if ( BYTE1(v25) & 2 || physobj->state & 0x200000 )
            goto LABEL_52;
        }
        break;
      case 1:
        if ( v18[15].hash_next )
          goto LABEL_52;
        if ( v18[22].vfptr )
        {
          v21 = ((unsigned int)v18[21].hash_next & 0x8044000) == 0;
LABEL_51:
          if ( v21 )
LABEL_52:
            invalid_to_show = 1;
        }
        break;
      default:
        break;
    }
    if ( SLOBYTE(v18[21].hash_next) >= 0 )
      break;
    id_iter.m_iter.m_currElement = id_iter.m_iter.m_currElement->m_hashNext;
    if ( !id_iter.m_iter.m_currElement )
    {
      v26 = &id_iter.m_iter.m_currHashTable->m_buckets[id_iter.m_iter.m_currHashTable->m_numBuckets];
      while ( 1 )
      {
        v27 = id_iter.m_iter.m_currBucket + 1;
        ++id_iter.m_iter.m_currBucket;
        if ( id_iter.m_iter.m_currBucket == v26 )
          goto LABEL_83;
        if ( *v27 )
        {
          v28 = *v27;
          goto LABEL_82;
        }
      }
    }
LABEL_20:
    v8 = spObjMaint.m_pInterface;
  }
  if ( (!_ignore_wielded || v18[15].hash_next != (HashBaseData<unsigned long> *)v35->playerID)
    && !v18[8].hash_next
    && !invalid_to_show )
  {
    if ( physobj->cell )
    {
      if ( !(physobj->state & 0x100000) )
      {
        SmartBox::convert_to_player_space(SmartBox::smartbox, physobj, &point);
        dist = Get2DDistance(point.x, point.y);
        if ( CPlayerSystem::GetRadarRadius() >= dist )
        {
          v29 = GetWeightedZDistance(point.z);
          dist = v29 + dist;
          if ( (v16 != oldObjID || _extreme) && v16 != v35->playerID )
          {
            v30 = dist;
            if ( _closer )
            {
              if ( CPlayerSystem::Farther(dist, v16, curBestDist, newSelectionID) == 1
                && !CPlayerSystem::Farther(v30, v16, distToBeat, oldObjID) )
              {
                curBestDist = dist;
                goto LABEL_76;
              }
            }
            else if ( !CPlayerSystem::Farther(dist, v16, curBestDist, newSelectionID)
                   && CPlayerSystem::Farther(v30, v16, distToBeat, oldObjID) == 1 )
            {
              curBestDist = v30;
LABEL_76:
              newSelectionID = v16;
              goto LABEL_77;
            }
          }
        }
      }
    }
  }
LABEL_77:
  id_iter.m_iter.m_currElement = id_iter.m_iter.m_currElement->m_hashNext;
  if ( id_iter.m_iter.m_currElement )
    goto LABEL_20;
  v31 = id_iter.m_iter.m_currBucket;
  v32 = &id_iter.m_iter.m_currHashTable->m_buckets[id_iter.m_iter.m_currHashTable->m_numBuckets];
  while ( 1 )
  {
    ++v31;
    id_iter.m_iter.m_currBucket = v31;
    if ( v31 == v32 )
      break;
    if ( *v31 )
    {
      v28 = *v31;
LABEL_82:
      id_iter.m_iter.m_currElement = v28;
      if ( v28 )
        goto LABEL_20;
      break;
    }
  }
LABEL_83:
  if ( newSelectionID )
    ACCWeenieObject::SetSelectedObject(newSelectionID, 0);
  v8 = spObjMaint.m_pInterface;
LABEL_86:
  if ( v8 )
    v8->vfptr->Release((Interface *)v8);
}

//----- (0055FF70) --------------------------------------------------------  // acclient.c:398215
char __stdcall CPlayerSystem::ObjectIsWithinRadarRange(unsigned int _objectID)
{
  InterfaceSystem *v2; // eax@1
  Interface *v3; // esi@1
  int v4; // esi@5
  HashBaseData<unsigned long> *v5; // eax@5
  char v6; // al@13
  int v7; // [sp-8h] [bp-28h]@1
  Interface *_rpInterface; // [sp+8h] [bp-18h]@1
  TResult result; // [sp+Ch] [bp-14h]@1
  char v10; // [sp+10h] [bp-10h]@3
  AC1Legacy::Vector3 point; // [sp+14h] [bp-Ch]@1
  float _objectIDa; // [sp+24h] [bp+4h]@8

  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &ClientObjMaintSystem_ClassType_3, &_rpInterface);
  v7 = (int)_rpInterface;
  v3 = _rpInterface;
  LODWORD(point.x) = 0;
  LODWORD(point.y) = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  InterfacePtr<ClientObjMaintSystem>::_QueryInterface(&point, (int)&v10, v7, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v4 = (signed int)point.x;
  v5 = CObjectMaint::GetObjectA((CObjectMaint *)((_DWORD)point.x + 8), _objectID);
  if ( v5
    && v5[12].vfptr
    && ((SmartBox::convert_to_player_space(SmartBox::smartbox, (CPhysicsObj *)v5, &point),
         !SmartBox::is_player_outside(SmartBox::smartbox)) ? (_objectIDa = RADAR_INDOOR_RADIUS) : (_objectIDa = RADAR_OUTDOOR_RADIUS_1),
        _objectIDa > sqrt(pow(point.y, 2.0) + pow(point.x, 2.0))) )
  {
    if ( v4 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
    v6 = 1;
  }
  else
  {
    if ( v4 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
    v6 = 0;
  }
  return v6;
}

//----- (00560090) --------------------------------------------------------  // acclient.c:398263
char __thiscall CPlayerSystem::InqPlayerCoords(CPlayerSystem *this, long double *x, long double *y)
{
  long double *v3; // ebx@1
  long double *v4; // edi@1
  InterfaceSystem *v5; // eax@1
  long double *v6; // ebp@1
  ClientObjMaintSystem *v7; // ebp@5
  HashBaseData<unsigned long> *v8; // eax@5
  char result; // al@10
  int v10; // [sp-8h] [bp-28h]@1
  int worldLocY; // [sp+10h] [bp-10h]@1
  char v12; // [sp+14h] [bp-Ch]@3
  InterfacePtr<ClientObjMaintSystem> spObjMaint; // [sp+18h] [bp-8h]@1

  v3 = y;
  v4 = x;
  worldLocY = (int)this;
  *(_DWORD *)x = 0;
  *((_DWORD *)v4 + 1) = 0;
  *(_DWORD *)v3 = 0;
  *((_DWORD *)v3 + 1) = 0;
  x = 0;
  v5 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v5, (TResult *)&y, &ClientObjMaintSystem_ClassType_3, (Interface **)&x);
  v10 = (int)x;
  v6 = x;
  spObjMaint.m_pInterface = 0;
  spObjMaint.m_trStatus.m_val = 0;
  if ( x )
    (*(void (__thiscall **)(long double *))(*(_DWORD *)x + 16))(x);
  InterfacePtr<ClientObjMaintSystem>::_QueryInterface(&spObjMaint, (int)&v12, v10, 0);
  if ( v6 )
    (*(void (__thiscall **)(long double *))(*(_DWORD *)v6 + 20))(v6);
  v7 = spObjMaint.m_pInterface;
  v8 = CObjectMaint::GetObjectA((CObjectMaint *)&spObjMaint.m_pInterface->vfptr, *(_DWORD *)(worldLocY + 488));
  if ( v8 && v8[12].vfptr && CPhysicsObj::get_landscape_coord(SmartBox::smartbox->player, (int *)&x, &worldLocY) )
  {
    y = (long double *)(worldLocY - 1024);
    *v4 = (double)(signed int)(x - 128) * 0.1 + 0.5;
    *v3 = (double)(signed int)y * 0.1 + 0.5;
    if ( v7 )
      v7->vfptr->Release((Interface *)v7);
    result = 1;
  }
  else
  {
    if ( v7 )
      v7->vfptr->Release((Interface *)v7);
    result = 0;
  }
  return result;
}

//----- (005601C0) --------------------------------------------------------  // acclient.c:398317
bool __thiscall CPlayerSystem::AutoWear(CPlayerSystem *this, unsigned int _item, int *_blockedBySelf, int _quiet)
{
  char v4; // al@1
  int v5; // esi@1
  bool v6; // zf@1
  HashBaseData<unsigned long> *v7; // eax@2

  v4 = CPlayerSystem::AutoWearIsLegal(this, _item, _blockedBySelf, _quiet);
  v5 = (unsigned __int8)v4;
  v6 = v4 == 0;
  if ( v4 )
  {
    v7 = ClientObjMaintSystem::GetWeenieObject(_item);
    if ( v7 )
      ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v7, (unsigned int)v7[16].vfptr);
    v6 = v5 == 0;
  }
  return !v6;
}

//----- (00560210) --------------------------------------------------------  // acclient.c:398338
int __cdecl CPlayerSystem::IsOlthoi()
{
  InterfaceSystem *v0; // eax@1
  Interface *v1; // edi@1
  int v2; // ebx@3
  PlayerDesc *v3; // edi@5
  int v5; // [sp-8h] [bp-2Ch]@1
  Interface *_rpInterface; // [sp+Ch] [bp-18h]@1
  unsigned int heritage; // [sp+10h] [bp-14h]@1
  TResult result; // [sp+14h] [bp-10h]@1
  char v9; // [sp+18h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> spPD; // [sp+1Ch] [bp-8h]@1

  heritage = 0;
  _rpInterface = 0;
  v0 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v0, &result, &PlayerDesc_ClassType_26, &_rpInterface);
  v1 = _rpInterface;
  v5 = (int)_rpInterface;
  spPD.m_pInterface = 0;
  spPD.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v2 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPD, (int)&v9, v5, 0);
  if ( v1 )
    v1->vfptr->Release(v1);
  v3 = spPD.m_pInterface;
  if ( (_DWORD)spPD.m_pInterface )
  {
    if ( v2 >= 0 )
    {
      CBaseQualities::InqInt((CBaseQualities *)&spPD.m_pInterface->vfptr, 0xBCu, (int *)&heritage, 0, 0);
      if ( heritage == 12 || heritage == 13 )
      {
        v3->vfptr->Release((Interface *)v3);
        return 1;
      }
    }
    v3->vfptr->Release((Interface *)v3);
  }
  return 0;
}

//----- (005602D0) --------------------------------------------------------  // acclient.c:398382
void __thiscall CPlayerSystem::RegisterObjectRangeHandler(CPlayerSystem *this, ObjectRangeHandler *_handler, unsigned int _objectID, long double _range, bool _useRadii, bool _ignoreZDelta, long double _timeInterval, long double _timeOut)
{
  ListNode<ObjectRangeInfo> *i; // eax@1
  char *v9; // ecx@6
  ListNode<ObjectRangeInfo> *v10; // ST00_4@6
  ObjectRangeInfo rangeInfo; // [sp+4h] [bp-40h]@6

  for ( i = this->m_objectRangeCheckList._head; i; i = i->next )
  {
    if ( i->data.m_handler == _handler && i->data.m_objectID == _objectID )
      i->data.m_queuedForDeletion = 1;
  }
  rangeInfo.m_objectID = _objectID;
  rangeInfo.m_range = _range;
  rangeInfo.m_nextUpdate = COERCE_DOUBLE(Timer::cur_time.Cmd) + _timeInterval;
  rangeInfo.m_useRadii = _useRadii;
  rangeInfo.m_ignoreZDelta = _ignoreZDelta;
  rangeInfo.m_executeAtTime = COERCE_DOUBLE(Timer::cur_time.Cmd) + _timeOut;
  rangeInfo.m_timeInterval = _timeInterval;
  rangeInfo.m_timeOut = _timeOut;
  v9 = (char *)&this->m_objectRangeCheckList;
  v10 = (ListNode<ObjectRangeInfo> *)*((_DWORD *)v9 + 1);
  rangeInfo.m_handler = _handler;
  rangeInfo.m_queuedForDeletion = 0;
  List<ObjectRangeInfo>::insert((List<ObjectRangeInfo> *)v9, v10, &rangeInfo);
}

//----- (00560380) --------------------------------------------------------  // acclient.c:398410
int __thiscall PackableList<InventoryPlacement>::UnPack(PackableList<InventoryPlacement> *this, void **addr, unsigned int size)
{
  PackableList<InventoryPlacement> *v3; // ebp@1
  int v4; // esi@2
  int v5; // edi@2
  int result; // eax@5
  InventoryPlacement temp; // [sp+8h] [bp-10h]@2

  v3 = this;
  PackableList<InventoryPlacement>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    v5 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    temp.vfptr = (PackObjVtbl *)&InventoryPlacement::vftable;
    temp.iid_ = 0;
    temp.loc_ = 0;
    temp.priority_ = 0;
    if ( v5 <= 0 )
    {
LABEL_5:
      result = 1;
    }
    else
    {
      while ( ((int (__thiscall *)(InventoryPlacement *, void **, unsigned int))temp.vfptr->UnPack)(&temp, addr, size) )
      {
        PackableList<InventoryPlacement>::InsertTail(v3, &temp);
        ++v4;
        if ( v4 >= v5 )
          goto LABEL_5;
      }
      result = 0;
    }
  }
  return result;
}
// 7ABA64: using guessed type int (__thiscall *InventoryPlacement::vftable)(void *, char);

//----- (00560410) --------------------------------------------------------  // acclient.c:398455
PackableList<InventoryPlacement> *__thiscall PackableList<InventoryPlacement>::scalar_deleting_destructor(PackableList<InventoryPlacement> *this, unsigned int a2)
{
  PackableList<InventoryPlacement> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<InventoryPlacement>::vftable;
  PackableList<InventoryPlacement>::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CC790: using guessed type int (__thiscall *PackableList<InventoryPlacement>::vftable)(void *, char);

//----- (00560440) --------------------------------------------------------  // acclient.c:398471
List<ObjectRangeInfo> *__thiscall List<ObjectRangeInfo>::vector_deleting_destructor(List<ObjectRangeInfo> *this, unsigned int a2)
{
  List<ObjectRangeInfo> *v2; // esi@1

  v2 = this;
  this->vfptr = (List<ObjectRangeInfo>Vtbl *)&List<ObjectRangeInfo>::vftable;
  List<ObjectRangeInfo>::flush(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7CC7A4: using guessed type int (__thiscall *List<ObjectRangeInfo>::vftable)(void *, char);

//----- (00560470) --------------------------------------------------------  // acclient.c:398485
void __thiscall CPlayerSystem::CPlayerSystem(CPlayerSystem *this)
{
  CPlayerSystem *v1; // esi@1
  char *v2; // ebp@1
  char *v3; // edi@1
  volatile LONG *v4; // ST38_4@1
  Interface *v5; // ST34_4@1
  InterfaceSystem *v6; // eax@1
  GlobalEventHandler *v7; // eax@1
  GlobalEventHandler *v8; // edi@1
  char v9; // [sp+4Ch] [bp-10h]@1
  TResult tr; // [sp+50h] [bp-Ch]@1
  InterfacePtr<Interface> spcIFace; // [sp+54h] [bp-8h]@1

  v1 = this;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&IInputActionCallback::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)QualityChangeHandler::vftable;
  this->vfptr = (ObjectRangeHandlerVtbl *)&ObjectRangeHandler::vftable;
  v2 = (char *)&this->vfptr;
  v3 = (char *)&this->vfptr;
  this->vfptr = (InterfaceVtbl *)&CPlayerSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&CPlayerSystem::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&CPlayerSystem::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)CPlayerSystem::vftable;
  this->vfptr = (ObjectRangeHandlerVtbl *)&CPlayerSystem::vftable;
  this->m_cTurbineRefCount.m_cRef = 1;
  this->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  v4 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->account_.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v4);
  v1->account_.fIsDarkMajestyExpansion_ = 0;
  v1->account_.m_fIsThroneOfDestinyExpansion = 0;
  v1->account_.m_fPreOrderedThroneOfDestinyExpansion = 0;
  v1->m_pCharGenState = 0;
  CPlayerModule::CPlayerModule(&v1->playerModule);
  v1->m_accountHasThroneofDestiny = 0;
  LODWORD(v1->logOnRequestTime) = 0;
  HIDWORD(v1->logOnRequestTime) = 0;
  LODWORD(v1->logOffRequestTime) = 0;
  HIDWORD(v1->logOffRequestTime) = 0;
  LODWORD(v1->logOffTime) = 0;
  HIDWORD(v1->logOffTime) = 0;
  LODWORD(v1->deleteCharRequestTime) = 0;
  HIDWORD(v1->deleteCharRequestTime) = 0;
  v1->loggingOff = 0;
  v1->logOffRequested = 0;
  v1->connectionLost = 0;
  v1->awaitingExpiration = 0;
  LODWORD(v1->expirationTime) = 0;
  HIDWORD(v1->expirationTime) = 0;
  v1->teleportInProgress = 0;
  v1->m_layoutFromFile = 0;
  CInvSlotModule::CInvSlotModule(&v1->m_invSlotModule);
  v1->pending_components_list.head_ = 0;
  v1->pending_components_list.tail_ = 0;
  v1->m_objectRangeCheckList.vfptr = (List<ObjectRangeInfo>Vtbl *)&List<ObjectRangeInfo>::vftable;
  v1->m_objectRangeCheckList._head = 0;
  v1->m_objectRangeCheckList._tail = 0;
  v1->m_objectRangeCheckList._num_elements = 0;
  CContractTrackerTable::CContractTrackerTable(&v1->m_contractTrackerTable);
  CPlayerSystem::s_pPlayerSystem = v1;
  InterlockedIncrement((volatile LONG *)&v1->m_cTurbineRefCount.m_cRef);
  CPlayerSystem::Begin(v1);
  spcIFace.m_pInterface = 0;
  spcIFace.m_trStatus.m_val = 0;
  InterfacePtr<Interface>::_QueryInterface(&spcIFace, (int)&v9, (int)&v1->playerModule);
  v5 = spcIFace.m_pInterface;
  v6 = InterfaceSystem::GetInstance();
  InterfaceSystem::RegisterClassA(v6, &tr, &CPlayerModule_ClassType_5, v5, 0);
  ((void (__stdcall *)(signed int, signed int, char *))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    5,
    v3);
  ((void (__stdcall *)(signed int, signed int, char *))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    8,
    1,
    v3);
  ((void (__stdcall *)(signed int, signed int, char *))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    230,
    v3);
  v7 = GlobalEventHandler::GetGlobalEventHandler();
  v8 = v7;
  if ( v7 )
  {
    v7->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v7, 100008u, (NoticeHandler *)v2);
    v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, 100011u, (NoticeHandler *)v2);
    v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, 100009u, (NoticeHandler *)v2);
    v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, 100010u, (NoticeHandler *)v2);
    v8->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v8,
      (unsigned int)((char *)&loc_4DD200 + 1),
      (NoticeHandler *)v2);
    v8->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v8,
      (unsigned int)((char *)&loc_4DD1F5 + 1),
      (NoticeHandler *)v2);
  }
  if ( (_DWORD)spcIFace.m_pInterface )
    ((void (*)(void))spcIFace.m_pInterface->vfptr->Release)();
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 7A5AA4: using guessed type void (__thiscall *QualityChangeHandler::vftable[2])(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int);
// 7B2EEC: using guessed type void *ObjectRangeHandler::vftable;
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CC7A4: using guessed type int (__thiscall *List<ObjectRangeInfo>::vftable)(void *, char);
// 7CC9D8: using guessed type void (__thiscall *CPlayerSystem::vftable)(CPlayerSystem *this, unsigned __int32);
// 7CC9E0: using guessed type void (__thiscall *CPlayerSystem::vftable[2])(CPlayerSystem *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7CC9E8: using guessed type int (__stdcall *CPlayerSystem::vftable)(char);
// 7CC9F8: using guessed type bool (__thiscall *CPlayerSystem::vftable)(DBCache *this);
// 7CCCA0: using guessed type __int32 (__stdcall *CPlayerSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 87018C: using guessed type struct CPlayerSystem *CPlayerSystem::s_pPlayerSystem;
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00560690) --------------------------------------------------------  // acclient.c:398602
unsigned int __thiscall CPlayerSystem::Release(CPlayerSystem *this)
{
  CPlayerSystem *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
    v1->vfptr->__vecDelDtor(&v1->vfptr, 1);
  return v2;
}

//----- (005606C0) --------------------------------------------------------  // acclient.c:398615
void __thiscall CPlayerSystem::End(CPlayerSystem *this)
{
  CPlayerSystem *v1; // esi@1
  void *v2; // edi@1

  v1 = this;
  List<ObjectRangeInfo>::flush(&this->m_objectRangeCheckList);
  NIList<unsigned long>::DeleteContents((NIList<NetPacket *> *)&v1->pending_components_list);
  PlayerModule::Clear((PlayerModule *)&v1->playerModule.vfptr);
  CInvSlotModule::Reset(&v1->m_invSlotModule);
  v2 = v1->componentTracker;
  if ( v2 )
  {
    ComponentTracker::~ComponentTracker(v1->componentTracker);
    operator delete(v2);
  }
  v1->componentTracker = 0;
  PackableHashTable<unsigned long,CContractTracker>::EmptyContents((PackableHashTable<unsigned long,GeneratorRegistryNode> *)&v1->m_contractTrackerTable._contractTrackerHash);
}

//----- (00560720) --------------------------------------------------------  // acclient.c:398636
void __thiscall CPlayerSystem::RecvNotice_SetSelectedItem(CPlayerSystem *this, unsigned int _oldSelectedID, unsigned int _selectedID)
{
  CPlayerSystem *v3; // ebp@1
  char *v4; // edx@2
  List<ObjectRangeInfo>Vtbl *i; // eax@4
  HashBaseData<unsigned long> *v6; // eax@9
  ACCWeenieObject *v7; // esi@9
  char v8; // bl@10
  ClientUISystem *v9; // eax@13
  ClientUISystem *v10; // eax@16
  ClientTradeSystem *v11; // eax@19
  ObjectRangeHandler *v12; // esi@22
  long double v13; // st7@25
  CPlayerSystem *v14; // [sp+30h] [bp-4h]@4

  v3 = this;
  if ( this == (CPlayerSystem *)4 )
    v4 = 0;
  else
    v4 = (char *)&this->vfptr;
  v14 = (CPlayerSystem *)((char *)this - 4);
  for ( i = this->m_objectRangeCheckList.vfptr; i; i = (List<ObjectRangeInfo>Vtbl *)i[16].__vecDelDtor )
  {
    if ( (char *)i->__vecDelDtor == v4
      && i[1].__vecDelDtor == (void *(__thiscall *)(List<ObjectRangeInfo> *, unsigned int))_oldSelectedID )
      LOBYTE(i[14].__vecDelDtor) = 1;
  }
  v6 = ClientObjMaintSystem::GetWeenieObject(_selectedID);
  v7 = (ACCWeenieObject *)v6;
  if ( v6 )
  {
    v8 = 1;
    if ( ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v6) )
      v8 = 0;
    if ( ClientUISystem::GetUISystem()->groundObject )
    {
      v9 = ClientUISystem::GetUISystem();
      if ( ACCWeenieObject::IsOwnedByObject(v7, v9->groundObject) )
        v8 = 0;
    }
    if ( ClientUISystem::GetUISystem()->vendorID )
    {
      v10 = ClientUISystem::GetUISystem();
      if ( ACCWeenieObject::IsOwnedByObject(v7, v10->vendorID) )
        v8 = 0;
    }
    if ( !ClientTradeSystem::GetTradeSystem()->m_iidTradePartner
      || (v11 = ClientTradeSystem::GetTradeSystem(), !ACCWeenieObject::IsOwnedByObject(v7, v11->m_iidTradePartner)) )
    {
      if ( v8 )
      {
        if ( v3 == (CPlayerSystem *)4 )
          v12 = 0;
        else
          v12 = (ObjectRangeHandler *)&v3->vfptr;
        if ( SmartBox::is_player_outside(SmartBox::smartbox) )
          v13 = 75.0;
        else
          v13 = 25.0;
        CPlayerSystem::RegisterObjectRangeHandler(v14, v12, _selectedID, v13, 1, 1, 1.0, 0.0);
      }
    }
    SmartBox::set_selected_object_id(_selectedID);
  }
}

//----- (00560860) --------------------------------------------------------  // acclient.c:398703
void __thiscall CPlayerSystem::RecvNotice_EnchantmentsChanged(CPlayerSystem *this)
{
  CPlayerSystem::OnLoadChanged((CPlayerSystem *)((char *)this - 4));
}

//----- (00560870) --------------------------------------------------------  // acclient.c:398709
void __thiscall CPlayerSystem::OnObjectRangeExit(CPlayerSystem *this, unsigned int _objectID)
{
  CPlayerSystem *v2; // edi@1
  long double v3; // st7@4

  v2 = this;
  if ( _objectID == ACCWeenieObject::selectedID )
  {
    if ( SmartBox::is_selected_object_in_view() )
    {
      if ( SmartBox::is_player_outside(SmartBox::smartbox) )
        v3 = 75.0;
      else
        v3 = 25.0;
      CPlayerSystem::RegisterObjectRangeHandler(
        (CPlayerSystem *)((char *)v2 - 16),
        (ObjectRangeHandler *)(v2 != (CPlayerSystem *)16 ? (unsigned int)v2 : 0),
        _objectID,
        v3,
        1,
        1,
        1.0,
        0.0);
    }
    else
    {
      ACCWeenieObject::SetSelectedObject(0, 0);
    }
  }
}

//----- (005608F0) --------------------------------------------------------  // acclient.c:398741
void __thiscall CPlayerSystem::OnQualityRemoved(CPlayerSystem *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  CPlayerSystem::OnLoadChanged((CPlayerSystem *)((char *)this - 12));
}

//----- (00560900) --------------------------------------------------------  // acclient.c:398747
void __stdcall CPlayerSystem::SendQueryPluginData(unsigned int context)
{
  IACPlugin *v2; // eax@2
  unsigned __int16 *v3; // esi@3
  AC1Legacy::PSRefBuffer<unsigned short> *v4; // esi@6
  AC1Legacy::PStringBase<unsigned short> pluginList; // [sp+Ch] [bp-8h]@1
  unsigned __int16 *bstrPluginList; // [sp+10h] [bp-4h]@2

  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(&pluginList, L"3rd party API not in use.");
  if ( APIManager::APIIsReady() )
  {
    v2 = APIManager::GetACPlugin();
    ((void (__stdcall *)(IACPlugin *, unsigned __int16 **))v2->vfptr[1].QueryInterface)(v2, &bstrPluginList);
    AC1Legacy::PStringBase<unsigned short>::set(&pluginList, bstrPluginList);
  }
  AC1Legacy::PStringBase<unsigned short>::to_spstring(&pluginList, (AC1Legacy::PStringBase<char> *)&bstrPluginList, 0);
  CM_Admin::Event_QueryPluginListResponse(context, (AC1Legacy::PStringBase<char> *)&bstrPluginList);
  v3 = bstrPluginList;
  if ( !InterlockedDecrement((volatile LONG *)bstrPluginList + 1) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = pluginList.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&pluginList.m_buffer->m_cRef) )
  {
    if ( v4 )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  }
}

//----- (005609A0) --------------------------------------------------------  // acclient.c:398776
bool __thiscall CPlayerSystem::AutoSort(CPlayerSystem *this, unsigned int _item, int _wield, int _quiet)
{
  CPlayerSystem *v4; // edi@1
  unsigned int v6; // esi@3
  HashBaseData<unsigned long> *v7; // eax@3
  ACCWeenieObject *v8; // ebx@3
  HashBaseData<unsigned long>Vtbl *v9; // ebp@5
  int v10; // eax@6
  bool v11; // zf@7
  int v12; // eax@10

  v4 = this;
  if ( !ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(0) )
    return 0;
  v6 = _item;
  v7 = ClientObjMaintSystem::GetWeenieObject(_item);
  v8 = (ACCWeenieObject *)v7;
  if ( !v7 )
    return 0;
  v9 = v7[16].vfptr;
  if ( !((unsigned int)v9 & 0x8007FFF) )
    goto LABEL_16;
  _item = 0;
  v10 = CPlayerSystem::AutoWear(v4, v6, (int *)&_item, _quiet);
  if ( _item )
    return 0;
  v11 = v10 == 0;
  if ( !v10 )
  {
LABEL_16:
    if ( _wield )
    {
      if ( (unsigned int)v9 & 0x7EFF8000 )
      {
        v12 = CPlayerSystem::AutoWield(v4, v6, SLOT_SIDE_RIGHT, 1, 0, 0, 1);
        v11 = (unsigned __int8)v12 == 0;
        if ( (_BYTE)v12 )
          return !v11;
      }
    }
    if ( !ACCWeenieObject::IsOwnedByPlayer(v8) )
    {
      v11 = CPlayerSystem::PlaceInBackpack(v4, v6, 0) == 0;
      return !v11;
    }
    return 0;
  }
  return !v11;
}

//----- (00560A60) --------------------------------------------------------  // acclient.c:398827
bool __thiscall CPlayerSystem::AutoWield(CPlayerSystem *this, unsigned int _item, UI_SLOT_SIDE _slotSide, int _quiet, int _unblock, int _autosortOnFail, int _trySecondChoiceSide)
{
  CPlayerSystem *v7; // esi@1
  signed int v9; // ebp@3
  HashBaseData<unsigned long> *v10; // eax@3
  HashBaseData<unsigned long> *v11; // ebx@3
  HashBaseData<unsigned long> *v12; // eax@4
  PStringBase<unsigned short> *v13; // eax@7
  CInvSlotInfo *v14; // eax@93
  CInvSlotInfo *v15; // edx@93
  unsigned int v16; // edi@98
  unsigned int v17; // edx@102
  bool v18; // zf@113
  unsigned int v19; // ebp@114
  unsigned int v20; // edi@116
  unsigned int *v21; // edx@119
  unsigned int v22; // edi@119
  HashBaseData<unsigned long> *v23; // eax@121
  unsigned int v24; // eax@128
  HashBaseData<unsigned long> *v25; // eax@137
  PStringBase<unsigned short> *v26; // eax@140
  unsigned int v27; // ebp@143
  int v28; // edi@143
  int v29; // ebx@143
  int v30; // eax@143
  PStringBase<unsigned short> *v31; // eax@167
  ACCWeenieObject *v32; // eax@170
  int v33; // ebp@171
  ACCWeenieObject *v34; // eax@173
  PStringBase<unsigned short> result; // [sp+4h] [bp-A4h]@7
  int taken; // [sp+8h] [bp-A0h]@3
  unsigned int objLoc; // [sp+Ch] [bp-9Ch]@9
  PStringBase<unsigned short> errorText; // [sp+10h] [bp-98h]@3
  PStringBase<unsigned short> v39; // [sp+14h] [bp-94h]@140
  StringInfo siError; // [sp+18h] [bp-90h]@7

  v7 = this;
  if ( !ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(_quiet) )
    return 0;
  v9 = 0;
  taken = 0;
  v10 = ClientObjMaintSystem::GetWeenieObject(_item);
  v11 = v10;
  errorText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)v10;
  if ( !v10 )
    return 0;
  v12 = v10[15].hash_next;
  if ( v12 && v12 != (HashBaseData<unsigned long> *)v7->playerID )
  {
    if ( !_quiet )
    {
      v13 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v11, &result, NAME_APPROPRIATE, 0);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &errorText,
        0,
        L"The %s is being wielded by someone else",
        v13->m_charbuffer);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      StringInfo::StringInfo(&siError);
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      StringInfo::~StringInfo(&siError);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
    }
    return 0;
  }
  objLoc = (unsigned int)v11[16].vfptr;
  if ( !(objLoc & 0x7FFFFFFF) )
    return 0;
  if ( CPlayerSystem::AutoWieldIsLegal(v7, _item, _quiet) )
  {
    v18 = (unsigned __int16)(objLoc & 0x8000) == 0;
    v7->blockingID = 0;
    v7->blockedID = 0;
    v7->blockedSide = 0;
    v7->unblockAttemptNum = 0;
    if ( !v18 )
    {
      if ( !(v7->inventoryMask & 0x8000) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x8000u);
LABEL_104:
        v9 = 1;
        taken = 1;
        goto LABEL_110;
      }
      v7->blockingID = v7->m_invSlotModule.neckSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &result,
          L"You're already wearing jewelry on your neck.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    if ( objLoc & 0x4000000 )
    {
      if ( !(v7->inventoryMask & 0x4000000) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x4000000u);
        goto LABEL_104;
      }
      v7->blockingID = v7->m_invSlotModule.trinketOneSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"You're already wearing a trinket.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    if ( objLoc & 0x8000000 )
    {
      if ( !(v7->inventoryMask & 0x8000000) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x8000000u);
        goto LABEL_104;
      }
      v7->blockingID = v7->m_invSlotModule.cloakSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"You're already wearing a cloak.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    if ( objLoc & 0x10000000 )
    {
      if ( !(v7->inventoryMask & 0x10000000) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x10000000u);
        goto LABEL_104;
      }
      v7->blockingID = v7->m_invSlotModule.sigilOneSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"You're already using aetheria of Lyr.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    if ( objLoc & 0x20000000 )
    {
      if ( !(v7->inventoryMask & 0x20000000) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x20000000u);
        goto LABEL_104;
      }
      v7->blockingID = v7->m_invSlotModule.sigilTwoSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"You're already using aetheria of Kor.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    if ( objLoc & 0x40000000 )
    {
      if ( !(v7->inventoryMask & 0x40000000) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x40000000u);
        goto LABEL_104;
      }
      v7->blockingID = v7->m_invSlotModule.sigilThreeSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"You're already using aetheria of Tem.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    if ( objLoc & 1 )
    {
      if ( !(v7->inventoryMask & 1) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 1u);
        goto LABEL_104;
      }
      v7->blockingID = v7->m_invSlotModule.headSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"You're already wearing a helm.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    if ( objLoc & 0x200 )
    {
      if ( !(v7->inventoryMask & 0x200) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x200u);
        goto LABEL_104;
      }
      v7->blockingID = v7->m_invSlotModule.chestSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"You're already wearing chest armor.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    if ( objLoc & 0x400 )
    {
      if ( !(v7->inventoryMask & 0x400) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x400u);
        goto LABEL_104;
      }
      v7->blockingID = v7->m_invSlotModule.abdomenSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"You're already wearing abdomen armor.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    if ( objLoc & 0x800 )
    {
      if ( !(v7->inventoryMask & 0x800) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x800u);
        goto LABEL_104;
      }
      v7->blockingID = v7->m_invSlotModule.upperArmSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"You're already wearing upper arm armor.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    if ( objLoc & 0x1000 )
    {
      if ( !(v7->inventoryMask & 0x1000) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x1000u);
        goto LABEL_104;
      }
      v7->blockingID = v7->m_invSlotModule.lowerArmSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"You're already wearing lower arm armor.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    if ( objLoc & 0x20 )
    {
      if ( !(v7->inventoryMask & 0x20) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x20u);
        goto LABEL_104;
      }
      v7->blockingID = v7->m_invSlotModule.handSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"You're already wearing hand armor.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    if ( objLoc & 0x2000 )
    {
      if ( !(v7->inventoryMask & 0x2000) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x2000u);
        goto LABEL_104;
      }
      v7->blockingID = v7->m_invSlotModule.upperLegSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"You're already wearing upper leg armor.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    if ( objLoc & 0x4000 )
    {
      if ( !(v7->inventoryMask & 0x4000) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x4000u);
        goto LABEL_104;
      }
      v7->blockingID = v7->m_invSlotModule.lowerLegSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"You're already wearing lower leg armor.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    if ( objLoc & 0x100 )
    {
      if ( !(v7->inventoryMask & 0x100) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x100u);
        goto LABEL_104;
      }
      v7->blockingID = v7->m_invSlotModule.footSlot->m_itemID;
      if ( !_unblock )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"You're already wearing foot armor.");
        StringInfo::SetLiteralValue(&siError, &result, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
    }
    result.m_charbuffer = (PSRefBufferCharData<unsigned short> *)(objLoc & 0x30000);
    if ( objLoc & 0x30000 || objLoc & 0xC0000 )
    {
      if ( objLoc & 0x30000 )
      {
        if ( _slotSide == 1 )
        {
          v14 = v7->m_invSlotModule.leftWristSlot;
          v15 = v7->m_invSlotModule.rightWristSlot;
        }
        else
        {
          v14 = v7->m_invSlotModule.rightWristSlot;
          v15 = v7->m_invSlotModule.leftWristSlot;
        }
      }
      else if ( _slotSide == 1 )
      {
        v14 = v7->m_invSlotModule.leftRingSlot;
        v15 = v7->m_invSlotModule.rightRingSlot;
      }
      else
      {
        v14 = v7->m_invSlotModule.rightRingSlot;
        v15 = v7->m_invSlotModule.leftRingSlot;
      }
      v16 = v7->inventoryMask;
      if ( !(v14->m_invLoc & v16) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, v14->m_invLoc);
        goto LABEL_104;
      }
      if ( _trySecondChoiceSide )
      {
        if ( v14->m_itemID != _item )
        {
          v17 = v15->m_invLoc;
          if ( !(v17 & v16) )
          {
            ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, v17);
            goto LABEL_104;
          }
        }
      }
      v7->blockingID = v14->m_itemID;
      if ( !_unblock )
      {
        if ( result.m_charbuffer )
        {
          StringInfo::StringInfo(&siError);
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            &result,
            L"You're already wearing jewelry on both wrists.");
          StringInfo::SetLiteralValue(&siError, &result, 1);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
          ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        }
        else
        {
          StringInfo::StringInfo(&siError);
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            &result,
            L"You're already wearing jewelry on both hands.");
          StringInfo::SetLiteralValue(&siError, &result, 1);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
          ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        }
        StringInfo::~StringInfo(&siError);
      }
    }
LABEL_110:
    if ( objLoc & 0x2500000 && _slotSide == 1 )
      objLoc = 0x200000;
    v18 = v9 == 0;
    if ( v9 )
      return !v18;
    v19 = objLoc & 0x3500000;
    if ( objLoc & 0x3500000 )
    {
      if ( v7->inventoryMask & 0x3500000 )
      {
        if ( ItemHolder::AttemptMerge(_item, v7->m_invSlotModule.weaponReadySlot->m_itemID, 1) )
          return 1;
        v7->blockingID = v7->m_invSlotModule.weaponReadySlot->m_itemID;
      }
      else
      {
        v20 = v7->m_invSlotModule.shieldReadySlot->m_itemID;
        if ( v20 && ACCWeenieObject::BlocksUseOfShield((ACCWeenieObject *)v11) )
        {
          v7->blockingID = v20;
        }
        else
        {
          v21 = &v7->m_invSlotModule.ammoReadySlot->m_itemID;
          v22 = *v21;
          if ( v11[19].hash_next )
          {
            if ( v22 )
            {
              v23 = ClientObjMaintSystem::GetWeenieObject(*v21);
              if ( v23 )
              {
                if ( v11[19].hash_next != v23[19].hash_next )
                  v7->blockingID = v22;
              }
            }
          }
          if ( !v7->blockingID )
          {
            ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, v19);
            return 1;
          }
        }
      }
    }
    v24 = objLoc;
    if ( objLoc & 0x200000 )
    {
      if ( !(v7->inventoryMask & 0x200000) )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)v11, 0x200000u);
        return 1;
      }
      v7->blockingID = v7->m_invSlotModule.shieldReadySlot->m_itemID;
    }
    if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v24 )
    {
      if ( !((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v7->inventoryMask) )
      {
        ACCWeenieObject::UIAttemptWield(
          (ACCWeenieObject *)v11,
          (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)");
        return 1;
      }
      if ( ItemHolder::AttemptMerge(_item, v7->m_invSlotModule.ammoReadySlot->m_itemID, 1) )
        return 1;
      v25 = ClientObjMaintSystem::GetWeenieObject(v7->m_invSlotModule.ammoReadySlot->m_itemID);
      if ( v25 && v25[13].id == v11[13].id )
      {
        if ( !_quiet )
        {
          v26 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v11, &v39, NAME_PLURAL, 0);
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            &result,
            0,
            L"You cannot wield more %s",
            v26->m_charbuffer);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v39);
          StringInfo::StringInfo(&siError);
          StringInfo::SetLiteralValue(&siError, &result, 1);
          ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
          StringInfo::~StringInfo(&siError);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        }
      }
      else
      {
        v7->blockingID = v7->m_invSlotModule.ammoReadySlot->m_itemID;
      }
    }
    if ( objLoc & 0x80001FF )
    {
      v27 = objLoc & 0x8000000;
      v28 = v7->inventoryMask & 2;
      v29 = v7->inventoryMask & 0x40;
      v30 = v7->inventoryMask & 0x8000000;
      if ( objLoc & 2 )
      {
        if ( objLoc & 0x40 )
        {
          if ( !v28 && !v29 )
          {
            ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)errorText.m_charbuffer, 0x42u);
LABEL_157:
            taken = 1;
LABEL_177:
            v18 = taken == 0;
            return !v18;
          }
          StringInfo::StringInfo(&siError);
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            &result,
            L"You must unwield your shirt and pants to wield that.");
          StringInfo::SetLiteralValue(&siError, &result, 1);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
          ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
          StringInfo::~StringInfo(&siError);
          goto LABEL_167;
        }
        if ( !v28 )
        {
          ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)errorText.m_charbuffer, 2u);
          goto LABEL_157;
        }
      }
      else if ( objLoc & 0x40 && !v29 )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)errorText.m_charbuffer, 0x40u);
        goto LABEL_157;
      }
      if ( v27 && !v30 )
      {
        ACCWeenieObject::UIAttemptWield((ACCWeenieObject *)errorText.m_charbuffer, 0x8000000u);
        goto LABEL_157;
      }
      if ( objLoc & 2 && v28 )
      {
        v7->blockingID = v7->m_invSlotModule.clothesShirtSlot->m_itemID;
      }
      else if ( objLoc & 0x40 && v29 )
      {
        v7->blockingID = v7->m_invSlotModule.clothesPantsSlot->m_itemID;
      }
      else if ( v27 && v30 )
      {
        v7->blockingID = v7->m_invSlotModule.cloakSlot->m_itemID;
      }
    }
LABEL_167:
    v31 = (PStringBase<unsigned short> *)v7->blockingID;
    if ( !v31 )
      goto LABEL_177;
    if ( !_unblock )
    {
      CPlayerSystem::ResetUnblocking(v7);
      goto LABEL_177;
    }
    if ( v31 != (PStringBase<unsigned short> *)_item )
    {
      ++v7->unblockAttemptNum;
      v7->blockedID = _item;
      v7->blockedSide = _slotSide;
      v32 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)&v39, v31, 2u, 0);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"Moving %s to your backpack", v32->vfptr);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v39);
      if ( ItemHolder::AttemptToPlaceInContainer(v7->blockingID, v7->playerID, 0, 1, 0) )
      {
        v7->blockingDestID = v7->playerID;
        v33 = 1;
      }
      else
      {
        if ( ClientObjMaintSystem::GetWeenieObject(v7->blockingID) )
        {
          v34 = ACCWeenieObject::GetObjectNameWide(
                  (ACCWeenieObject *)&v39,
                  (PStringBase<unsigned short> *)v7->blockingID,
                  2u,
                  0);
          PStringBase<unsigned short>::sprintf_append(&errorText, L" - cannot unwield the %s", v34->vfptr);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v39);
        }
        CPlayerSystem::ResetUnblocking(v7);
        v33 = taken;
      }
      StringInfo::StringInfo(&siError);
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      StringInfo::~StringInfo(&siError);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
      return v33 != 0;
    }
    return 0;
  }
  if ( !_autosortOnFail || ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v11) )
    return 0;
  return CPlayerSystem::AutoSort(v7, _item, 0, 0);
}

//----- (00561890) --------------------------------------------------------  // acclient.c:399449
bool __thiscall CPlayerSystem::OnAction(CPlayerSystem *this, InputEvent *i_evt)
{
  CPlayerSystem *v2; // esi@1
  ClientUISystem *v3; // eax@3
  bool v4; // al@3
  ClientUISystem *v5; // eax@5
  unsigned int v6; // ST10_4@5
  ClientUISystem *v7; // eax@5
  unsigned int v8; // ebx@11
  unsigned int v9; // edi@11
  HashBaseData<unsigned long> *v10; // eax@14
  unsigned int v11; // edi@18
  HashBaseData<unsigned long> *v12; // eax@19
  _Formatted v13; // edi@27
  CPlayerSystem *v14; // esi@27
  _Formatted v15; // edi@29
  CPlayerSystem *v16; // esi@29
  _Formatted v17; // edi@32
  CPlayerSystem *v18; // esi@32
  _Formatted v19; // edi@34
  CPlayerSystem *v20; // esi@34
  _Formatted v21; // edi@37
  CPlayerSystem *v22; // esi@37
  _Formatted v23; // edi@39
  CPlayerSystem *v24; // esi@39
  InterfacePtr<Interface> *v25; // eax@41
  PlayerDesc *v26; // ebx@47
  InterfacePtr<Interface> *v27; // eax@50
  PlayerDesc *v28; // edi@52
  _Formatted v29; // edi@61
  CPlayerSystem *v30; // esi@61
  _Formatted v31; // edi@64
  CPlayerSystem *v32; // esi@64
  _Formatted v33; // edi@68
  CPlayerSystem *v34; // esi@68
  HashBaseData<unsigned long> *v35; // eax@71
  _Formatted v36; // edi@74
  CPlayerSystem *v37; // esi@74
  HashBaseData<unsigned long> *v38; // eax@76
  ClientFellowshipSystem *v39; // eax@80
  ClientFellowshipSystem *v40; // eax@81
  PlayerModule *v41; // esi@82
  char v42; // al@82
  PlayerModule *v43; // esi@83
  char v44; // al@83
  PlayerModule *v45; // esi@84
  char v46; // al@84
  PlayerModule *v47; // esi@85
  char v48; // al@85
  PlayerModule *v49; // esi@86
  char v50; // al@86
  PlayerModule *v51; // esi@87
  char v52; // al@87
  PlayerModule *v53; // esi@88
  char v54; // al@88
  PlayerModule *v55; // esi@89
  char v56; // al@89
  PlayerModule *v57; // esi@90
  char v58; // al@90
  PlayerModule *v59; // esi@91
  char v60; // al@91
  PlayerModule *v61; // esi@92
  char v62; // al@92
  PlayerModule *v63; // esi@93
  char v64; // al@93
  PlayerModule *v65; // esi@94
  char v66; // al@94
  PlayerModule *v67; // esi@95
  char v68; // al@95
  PlayerModule *v69; // esi@96
  char v70; // al@96
  PlayerModule *v71; // esi@97
  char v72; // al@97
  PlayerModule *v73; // esi@98
  char v74; // al@98
  PlayerModule *v75; // esi@99
  char v76; // al@99
  PlayerModule *v77; // esi@100
  char v78; // al@100
  PlayerModule *v79; // esi@101
  char v80; // al@101
  PlayerModule *v81; // esi@102
  char v82; // al@102
  PlayerModule *v83; // esi@103
  char v84; // al@103
  PlayerModule *v85; // esi@104
  char v86; // al@104
  PlayerModule *v87; // esi@105
  char v88; // al@105
  PlayerModule *v89; // esi@106
  char v90; // al@106
  PlayerModule *v91; // esi@107
  char v92; // al@107
  PlayerModule *v93; // esi@108
  char v94; // al@108
  PlayerModule *v95; // esi@109
  char v96; // al@109
  PlayerModule *v97; // esi@110
  char v98; // al@110
  PlayerModule *v99; // esi@111
  char v100; // al@111
  PlayerModule *v101; // esi@112
  char v102; // al@112
  PlayerModule *v103; // esi@113
  char v104; // al@113
  PlayerModule *v105; // esi@114
  char v106; // al@114
  PlayerModule *v107; // esi@115
  char v108; // al@115
  PlayerModule *v109; // esi@116
  char v110; // al@116
  PlayerModule *v111; // esi@117
  char v112; // al@117
  PlayerModule *v113; // esi@118
  char v114; // al@118
  PlayerModule *v115; // esi@119
  char v116; // al@119
  PlayerModule *v117; // esi@120
  char v118; // al@120
  PlayerModule *v119; // esi@121
  char v120; // al@121
  PlayerModule *v121; // esi@122
  char v122; // al@122
  PlayerModule *v123; // esi@123
  char v124; // al@123
  PlayerModule *v125; // esi@124
  char v126; // al@124
  PlayerModule *v127; // esi@125
  char v128; // al@125
  PlayerModule *v129; // esi@126
  char v130; // al@126
  PlayerModule *v131; // esi@127
  char v132; // al@127
  PlayerModule *v133; // esi@128
  char v134; // al@128
  PlayerModule *v135; // esi@129
  char v136; // al@129
  PlayerModule *v137; // esi@130
  char v138; // al@130
  PStringBase<unsigned short> i_text; // [sp+Ch] [bp-20h]@17
  PStringBase<unsigned short> v140; // [sp+10h] [bp-1Ch]@22
  InterfacePtr<PlayerDesc> pPlayerDesc; // [sp+14h] [bp-18h]@41
  InterfacePtr<Interface> result; // [sp+1Ch] [bp-10h]@41
  InterfacePtr<Interface> v143; // [sp+24h] [bp-8h]@50

  v2 = this;
  switch ( i_evt->m_InputAction )
  {
    case 0x1000002Au:
      if ( ClientUISystem::GetUISystem()->targetMode == 3 )
      {
        v3 = ClientUISystem::GetUISystem();
        ClientUISystem::SetTargetMode(v3, 0);
        ItemHolder::TargetAcquired(LODWORD(v2->playerModule.m_timeFirstDirtied));
        v4 = 1;
      }
      else if ( ClientUISystem::GetUISystem()->targetMode == 2 )
      {
        ACCWeenieObject::SetSelectedObject(LODWORD(v2->playerModule.m_timeFirstDirtied), 0);
        v5 = ClientUISystem::GetUISystem();
        ClientUISystem::SetTargetMode(v5, 0);
        v6 = LODWORD(v2->playerModule.m_timeFirstDirtied);
        v7 = ClientUISystem::GetUISystem();
        ClientUISystem::ExamineObject(v7, v6);
        v4 = 1;
      }
      else
      {
        ACCWeenieObject::SetSelectedObject(LODWORD(v2->playerModule.m_timeFirstDirtied), 0);
        v4 = 1;
      }
      return v4;
    case 0x1000002Cu:
      if ( ACCWeenieObject::selectedID == Formatted )
        return 1;
      CPlayerSystem::PlaceInBackpack((CPlayerSystem *)((char *)this - 8), ACCWeenieObject::selectedID, 0);
      return 1;
    case 0x1000011Cu:
      if ( ACCWeenieObject::selectedID == Formatted )
        return 1;
      CPlayerSystem::PlaceInBackpack((CPlayerSystem *)((char *)this - 8), ACCWeenieObject::selectedID, 1);
      return 1;
    case 0x10000040u:
      v8 = ACCWeenieObject::selectedID;
      v9 = ACCWeenieObject::prevSelectedID;
      if ( ACCWeenieObject::selectedID == Formatted
        || !ACCWeenieObject::prevSelectedID
        || ACCWeenieObject::selectedID == ACCWeenieObject::prevSelectedID )
        return 1;
      v10 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::prevSelectedID);
      if ( v10 && ((int (__thiscall *)(HashBaseData<unsigned long> *))v10->vfptr[6].__vecDelDtor)(v10) & 0x10 )
      {
        ItemHolder::AttemptPlaceIn3D(v8, v9, 0);
        ACCWeenieObject::SetSelectedObject(v9, 0);
        v4 = 1;
      }
      else
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &i_text,
          L"You must select a creature or a character to give that to.\n");
        ClientSystem::AddTextToScroll(
          (ClientSystem *)&v2[-1].m_contractTrackerTable._contractTrackerHash._table_size,
          &i_text,
          0x1Au,
          1,
          0);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_text);
        v4 = 1;
      }
      return v4;
    case 0x10000041u:
      v11 = ACCWeenieObject::selectedID;
      if ( ACCWeenieObject::selectedID == Formatted )
        return 1;
      v12 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
      if ( v12 && ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v12) )
      {
        ItemHolder::AttemptPlaceIn3D(v11, 0, 1);
        v4 = 1;
      }
      else
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v140, L"You must pick that up first");
        ClientSystem::AddTextToScroll(
          (ClientSystem *)&v2[-1].m_contractTrackerTable._contractTrackerHash._table_size,
          &v140,
          0x1Au,
          1,
          0);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v140);
        v4 = 1;
      }
      return v4;
    case 0x1000002Du:
      CM_UI::SendNotice_SplitStack(ACCWeenieObject::selectedID);
      return 1;
    case 0x1000002Eu:
      if ( !ACCWeenieObject::prevSelectedID )
        return 1;
      ACCWeenieObject::SetSelectedObject(ACCWeenieObject::prevSelectedID, 0);
      return 1;
    case 0x1000002Fu:
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 1, 1, SELECTION_TYPE_COMPASS_ITEM, 0);
      return 1;
    case 0x10000030u:
      v13 = ACCWeenieObject::selectedID;
      v14 = (CPlayerSystem *)((char *)this - 8);
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 1, 0, SELECTION_TYPE_COMPASS_ITEM, 0);
      if ( v13 != ACCWeenieObject::selectedID )
        return 1;
      CPlayerSystem::SelectNext(v14, 0, 1, SELECTION_TYPE_COMPASS_ITEM, 0);
      return 1;
    case 0x10000031u:
      v15 = ACCWeenieObject::selectedID;
      v16 = (CPlayerSystem *)((char *)this - 8);
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 0, 0, SELECTION_TYPE_COMPASS_ITEM, 0);
      if ( v15 != ACCWeenieObject::selectedID )
        return 1;
      CPlayerSystem::SelectNext(v16, 1, 1, SELECTION_TYPE_COMPASS_ITEM, 0);
      return 1;
    case 0x10000032u:
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 1, 1, SELECTION_TYPE_ITEM, 1);
      return 1;
    case 0x10000033u:
      v17 = ACCWeenieObject::selectedID;
      v18 = (CPlayerSystem *)((char *)this - 8);
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 1, 0, SELECTION_TYPE_ITEM, 0);
      if ( v17 != ACCWeenieObject::selectedID )
        return 1;
      CPlayerSystem::SelectNext(v18, 0, 1, SELECTION_TYPE_ITEM, 0);
      return 1;
    case 0x10000034u:
      v19 = ACCWeenieObject::selectedID;
      v20 = (CPlayerSystem *)((char *)this - 8);
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 0, 0, SELECTION_TYPE_ITEM, 0);
      if ( v19 != ACCWeenieObject::selectedID )
        return 1;
      CPlayerSystem::SelectNext(v20, 1, 1, SELECTION_TYPE_ITEM, 0);
      return 1;
    case 0x10000035u:
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 1, 1, SELECTION_TYPE_MONSTER, 0);
      return 1;
    case 0x10000036u:
      v21 = ACCWeenieObject::selectedID;
      v22 = (CPlayerSystem *)((char *)this - 8);
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 1, 0, SELECTION_TYPE_MONSTER, 0);
      if ( v21 != ACCWeenieObject::selectedID )
        return 1;
      CPlayerSystem::SelectNext(v22, 0, 1, SELECTION_TYPE_MONSTER, 0);
      return 1;
    case 0x10000037u:
      v23 = ACCWeenieObject::selectedID;
      v24 = (CPlayerSystem *)((char *)this - 8);
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 0, 0, SELECTION_TYPE_MONSTER, 0);
      if ( v23 != ACCWeenieObject::selectedID )
        return 1;
      CPlayerSystem::SelectNext(v24, 1, 1, SELECTION_TYPE_MONSTER, 0);
      return 1;
    case 0x10000038u:
      v25 = GetClassObject(&result, &PlayerDesc_ClassType_26);
      InterfacePtr<PlayerDesc>::InterfacePtr<PlayerDesc>(&pPlayerDesc, v25);
      if ( (_DWORD)result.m_pInterface )
        ((void (*)(void))result.m_pInterface->vfptr->Release)();
      if ( !(unsigned __int8)InterfacePtr<PlayerDesc>::IsValid(&pPlayerDesc) )
      {
        if ( (_DWORD)pPlayerDesc.m_pInterface )
          ((void (*)(void))pPlayerDesc.m_pInterface->vfptr->Release)();
        return 0;
      }
      v26 = pPlayerDesc.m_pInterface;
      i_evt = 0;
      CBaseQualities::InqInstanceID((CBaseQualities *)&pPlayerDesc.m_pInterface->vfptr, 0xBu, (unsigned int *)&i_evt);
      if ( i_evt )
      {
        v27 = GetClassObject(&v143, &ClientObjMaintSystem_ClassType_3);
        InterfacePtr<ClientObjMaintSystem>::InterfacePtr<ClientObjMaintSystem>(
          (InterfacePtr<ClientObjMaintSystem> *)&pPlayerDesc,
          v27);
        if ( (_DWORD)v143.m_pInterface )
          ((void (*)(void))v143.m_pInterface->vfptr->Release)();
        v28 = pPlayerDesc.m_pInterface;
        if ( HashSet<unsigned long>::contains(
               (HashTable<unsigned long,unsigned long,0> *)&pPlayerDesc.m_pInterface[1]._posStatsTable,
               (const unsigned int *)&i_evt)
          && CPlayerSystem::ObjectIsWithinRadarRange((unsigned int)i_evt) )
          ACCWeenieObject::SetSelectedObject((unsigned int)i_evt, 0);
        if ( v28 )
          v28->vfptr->Release((Interface *)v28);
        if ( v26 )
          v26->vfptr->Release((Interface *)v26);
      }
      else if ( v26 )
      {
        v26->vfptr->Release((Interface *)v26);
        return 1;
      }
      return 1;
    default:
      return 0;
    case 0x10000039u:
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 1, 1, SELECTION_TYPE_PLAYER, 0);
      return 1;
    case 0x1000003Au:
      v29 = ACCWeenieObject::selectedID;
      v30 = (CPlayerSystem *)((char *)this - 8);
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 1, 0, SELECTION_TYPE_PLAYER, 0);
      if ( v29 == ACCWeenieObject::selectedID )
        CPlayerSystem::SelectNext(v30, 0, 1, SELECTION_TYPE_PLAYER, 0);
      return 1;
    case 0x1000003Bu:
      v31 = ACCWeenieObject::selectedID;
      v32 = (CPlayerSystem *)((char *)this - 8);
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 0, 0, SELECTION_TYPE_PLAYER, 0);
      if ( v31 == ACCWeenieObject::selectedID )
        CPlayerSystem::SelectNext(v32, 1, 1, SELECTION_TYPE_PLAYER, 0);
      return 1;
    case 0x10000121u:
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 1, 1, SELECTION_TYPE_UNOPENED_CORPSE, 0);
      return 1;
    case 0x10000122u:
      v33 = ACCWeenieObject::selectedID;
      v34 = (CPlayerSystem *)((char *)this - 8);
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 0, 0, SELECTION_TYPE_UNOPENED_CORPSE, 0);
      if ( v33 == ACCWeenieObject::selectedID )
        CPlayerSystem::SelectNext(v34, 1, 1, SELECTION_TYPE_UNOPENED_CORPSE, 0);
      return 1;
    case 0x1000003Eu:
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 1, 1, SELECTION_TYPE_UNOPENED_CORPSE, 0);
      v35 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
      if ( !v35 || !((int (__thiscall *)(HashBaseData<unsigned long> *))v35->vfptr[31].__vecDelDtor)(v35) )
        return 1;
      ItemHolder::UseObject(ACCWeenieObject::selectedID, 1, 0);
      return 1;
    case 0x1000003Fu:
      v36 = ACCWeenieObject::selectedID;
      v37 = (CPlayerSystem *)((char *)this - 8);
      CPlayerSystem::SelectNext((CPlayerSystem *)((char *)this - 8), 0, 0, SELECTION_TYPE_UNOPENED_CORPSE, 0);
      if ( v36 == ACCWeenieObject::selectedID )
        CPlayerSystem::SelectNext(v37, 1, 1, SELECTION_TYPE_UNOPENED_CORPSE, 0);
      v38 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
      if ( v38 && ((int (__thiscall *)(HashBaseData<unsigned long> *))v38->vfptr[31].__vecDelDtor)(v38) )
        ItemHolder::UseObject(ACCWeenieObject::selectedID, 1, 0);
      return 1;
    case 0x1000003Cu:
      v39 = ClientFellowshipSystem::GetFellowshipSystem();
      ClientFellowshipSystem::SelectPreviousFellow(v39);
      return 1;
    case 0x1000003Du:
      v40 = ClientFellowshipSystem::GetFellowshipSystem();
      ClientFellowshipSystem::SelectNextFellow(v40);
      return 1;
    case 0x10000071u:
      v41 = (PlayerModule *)&this->m_pCharGenState;
      v42 = PlayerModule::AutoRepeatAttack((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetAutoRepeatAttack(v41, v42 == 0);
      return 1;
    case 0x10000072u:
      v43 = (PlayerModule *)&this->m_pCharGenState;
      v44 = PlayerModule::IgnoreAllegianceRequests((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetIgnoreAllegianceRequests(v43, v44 == 0);
      return 1;
    case 0x10000073u:
      v45 = (PlayerModule *)&this->m_pCharGenState;
      v46 = PlayerModule::IgnoreFellowshipRequests((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetIgnoreFellowshipRequests(v45, v46 == 0);
      return 1;
    case 0x10000074u:
      v47 = (PlayerModule *)&this->m_pCharGenState;
      v48 = PlayerModule::IgnoreTradeRequests((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetIgnoreTradeRequests(v47, v48 == 0);
      return 1;
    case 0x10000075u:
      v49 = (PlayerModule *)&this->m_pCharGenState;
      v50 = PlayerModule::DisableMostWeatherEffects((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetDisableMostWeatherEffects(v49, v50 == 0);
      return 1;
    case 0x10000076u:
      v51 = (PlayerModule *)&this->m_pCharGenState;
      v52 = PlayerModule::PersistentAtDay((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetPersistentAtDay(v51, v52 == 0);
      return 1;
    case 0x10000077u:
      v53 = (PlayerModule *)&this->m_pCharGenState;
      v54 = PlayerModule::AllowGive((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetAllowGive(v53, v54 == 0);
      return 1;
    case 0x10000078u:
      v55 = (PlayerModule *)&this->m_pCharGenState;
      v56 = PlayerModule::ViewCombatTarget((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetViewCombatTarget(v55, v56 == 0);
      return 1;
    case 0x10000079u:
      v57 = (PlayerModule *)&this->m_pCharGenState;
      v58 = PlayerModule::ShowTooltips((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetShowTooltips(v57, v58 == 0);
      return 1;
    case 0x1000007Au:
      v59 = (PlayerModule *)&this->m_pCharGenState;
      v60 = PlayerModule::UseDeception((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetUseDeception(v59, v60 == 0);
      return 1;
    case 0x1000007Bu:
      v61 = (PlayerModule *)&this->m_pCharGenState;
      v62 = PlayerModule::ToggleRun((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetToggleRun(v61, v62 == 0);
      return 1;
    case 0x1000007Cu:
      v63 = (PlayerModule *)&this->m_pCharGenState;
      v64 = PlayerModule::StayInChatMode((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetStayInChatMode(v63, v64 == 0);
      return 1;
    case 0x1000007Du:
      v65 = (PlayerModule *)&this->m_pCharGenState;
      v66 = PlayerModule::AdvancedCombatUI((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetAdvancedCombatUI(v65, v66 == 0);
      return 1;
    case 0x1000007Eu:
      v67 = (PlayerModule *)&this->m_pCharGenState;
      v68 = PlayerModule::AutoTarget((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetAutoTarget(v67, v68 == 0);
      return 1;
    case 0x1000007Fu:
      v69 = (PlayerModule *)&this->m_pCharGenState;
      v70 = PlayerModule::VividTargetingIndicator((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetVividTargetingIndicator(v69, v70 == 0);
      return 1;
    case 0x10000080u:
      v71 = (PlayerModule *)&this->m_pCharGenState;
      v72 = PlayerModule::FellowshipShareXP((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetFellowshipShareXP(v71, v72 == 0);
      return 1;
    case 0x10000081u:
      v73 = (PlayerModule *)&this->m_pCharGenState;
      v74 = PlayerModule::AcceptLootPermits((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetAcceptLootPermits(v73, v74 == 0);
      return 1;
    case 0x10000082u:
      v75 = (PlayerModule *)&this->m_pCharGenState;
      v76 = PlayerModule::FellowshipShareLoot((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetFellowshipShareLoot(v75, v76 == 0);
      return 1;
    case 0x10000083u:
      v77 = (PlayerModule *)&this->m_pCharGenState;
      v78 = PlayerModule::FellowshipAutoAcceptRequests((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetFellowshipAutoAcceptRequests(v77, v78 == 0);
      return 1;
    case 0x1000013Eu:
      v79 = (PlayerModule *)&this->m_pCharGenState;
      v80 = PlayerModule::SideBySideVitals((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetSideBySideVitals(v79, v80 == 0);
      return 1;
    case 0x10000085u:
      v81 = (PlayerModule *)&this->m_pCharGenState;
      v82 = PlayerModule::CoordinatesOnRadar((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetCoordinatesOnRadar(v81, v82 == 0);
      return 1;
    case 0x10000086u:
      v83 = (PlayerModule *)&this->m_pCharGenState;
      v84 = PlayerModule::SpellDuration((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetSpellDuration(v83, v84 == 0);
      return 1;
    case 0x10000087u:
      v85 = (PlayerModule *)&this->m_pCharGenState;
      v86 = PlayerModule::DisableHouseRestrictionEffects((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetDisableHouseRestrictionEffects(v85, v86 == 0);
      return 1;
    case 0x10000088u:
      v87 = (PlayerModule *)&this->m_pCharGenState;
      v88 = PlayerModule::DragItemOnPlayerOpensSecureTrade((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetDragItemOnPlayerOpensSecureTrade(v87, v88 == 0);
      return 1;
    case 0x10000089u:
      v89 = (PlayerModule *)&this->m_pCharGenState;
      v90 = PlayerModule::DisplayAllegianceLogonNotifications((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetDisplayAllegianceLogonNotifications(v89, v90 == 0);
      return 1;
    case 0x1000008Au:
      v91 = (PlayerModule *)&this->m_pCharGenState;
      v92 = PlayerModule::UseChargeAttack((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetUseChargeAttack(v91, v92 == 0);
      return 1;
    case 0x1000011Eu:
      v93 = (PlayerModule *)&this->m_pCharGenState;
      v94 = PlayerModule::LeadMissileTargets((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetLeadMissileTargets(v93, v94 == 0);
      return 1;
    case 0x1000011Fu:
      v95 = (PlayerModule *)&this->m_pCharGenState;
      v96 = PlayerModule::UseFastMissiles((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetUseFastMissiles(v95, v96 == 0);
      return 1;
    case 0x1000008Bu:
      v97 = (PlayerModule *)&this->m_pCharGenState;
      v98 = PlayerModule::UseCraftSuccessDialog((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetUseCraftSuccessDialog(v97, v98 == 0);
      return 1;
    case 0x10000123u:
      v99 = (PlayerModule *)&this->m_pCharGenState;
      v100 = PlayerModule::ConfirmVolatileRareUse((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetConfirmVolatileRareUse(v99, v100 == 0);
      return 1;
    case 0x1000008Cu:
      v101 = (PlayerModule *)&this->m_pCharGenState;
      v102 = PlayerModule::HearAllegianceChat((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetHearAllegianceChat(v101, v102 == 0);
      return 1;
    case 0x1000010Eu:
      v103 = (PlayerModule *)&this->m_pCharGenState;
      v104 = PlayerModule::HearGeneralChat((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetHearGeneralChat(v103, v104 == 0);
      return 1;
    case 0x1000010Fu:
      v105 = (PlayerModule *)&this->m_pCharGenState;
      v106 = PlayerModule::HearTradeChat((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetHearTradeChat(v105, v106 == 0);
      return 1;
    case 0x10000110u:
      v107 = (PlayerModule *)&this->m_pCharGenState;
      v108 = PlayerModule::HearLFGChat((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetHearLFGChat(v107, v108 == 0);
      return 1;
    case 0x10000112u:
      v109 = (PlayerModule *)&this->m_pCharGenState;
      v110 = PlayerModule::HearRoleplayChat((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetHearRoleplayChat(v109, v110 == 0);
      return 1;
    case 0x10000125u:
      v111 = (PlayerModule *)&this->m_pCharGenState;
      v112 = PlayerModule::HearSocietyChat((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetHearSocietyChat(v111, v112 == 0);
      return 1;
    case 0x1000008Du:
      v113 = (PlayerModule *)&this->m_pCharGenState;
      v114 = PlayerModule::DisplayDateOfBirth((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetDisplayDateOfBirth(v113, v114 == 0);
      return 1;
    case 0x1000008Eu:
      v115 = (PlayerModule *)&this->m_pCharGenState;
      v116 = PlayerModule::DisplayAge((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetDisplayAge(v115, v116 == 0);
      return 1;
    case 0x1000008Fu:
      v117 = (PlayerModule *)&this->m_pCharGenState;
      v118 = PlayerModule::DisplayChessRank((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetDisplayChessRank(v117, v118 == 0);
      return 1;
    case 0x10000090u:
      v119 = (PlayerModule *)&this->m_pCharGenState;
      v120 = PlayerModule::DisplayFishingSkill((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetDisplayFishingSkill(v119, v120 == 0);
      return 1;
    case 0x10000091u:
      v121 = (PlayerModule *)&this->m_pCharGenState;
      v122 = PlayerModule::DisplayNumberDeaths((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetDisplayNumberDeaths(v121, v122 == 0);
      return 1;
    case 0x1000011Bu:
      v123 = (PlayerModule *)&this->m_pCharGenState;
      v124 = PlayerModule::DisplayNumberCharacterTitles((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetDisplayNumberCharacterTitles(v123, v124 == 0);
      return 1;
    case 0x10000092u:
      v125 = (PlayerModule *)&this->m_pCharGenState;
      v126 = PlayerModule::DisplayTimeStamps((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetDisplayTimeStamps(v125, v126 == 0);
      return 1;
    case 0x10000120u:
      v127 = (PlayerModule *)&this->m_pCharGenState;
      v128 = PlayerModule::FilterLanguage((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetFilterLanguage(v127, v128 == 0);
      return 1;
    case 0x10000093u:
      v129 = (PlayerModule *)&this->m_pCharGenState;
      v130 = PlayerModule::SalvageMultiple((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetSalvageMultiple(v129, v130 == 0);
      return 1;
    case 0x1000011Du:
      v131 = (PlayerModule *)&this->m_pCharGenState;
      v132 = PlayerModule::MainPackPreferred((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetMainPackPreferred(v131, v132 == 0);
      return 1;
    case 0x1000012Au:
      v133 = (PlayerModule *)&this->m_pCharGenState;
      v134 = PlayerModule::ShowHelm((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetShowHelm(v133, v134 == 0);
      return 1;
    case 0x1000012Cu:
      v135 = (PlayerModule *)&this->m_pCharGenState;
      v136 = PlayerModule::DisableDistanceFog((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetDisableDistanceFog(v135, v136 == 0);
      return 1;
    case 0x1000012Du:
      v137 = (PlayerModule *)&this->m_pCharGenState;
      v138 = PlayerModule::UseMouseTurning((PlayerModule *)&this->m_pCharGenState);
      PlayerModule::SetUseMouseTurning(v137, v138 == 0);
      return 1;
  }
}

//----- (00562870) --------------------------------------------------------  // acclient.c:400090
void __thiscall CPlayerSystem::OnEndCharacterSession(CPlayerSystem *this)
{
  CInputManager *v1; // esi@1
  CPlayerSystem *v2; // edi@1
  IInputActionCallback *v3; // eax@3
  CommandInterpreter *v4; // eax@6

  v1 = ICIDM::s_cidm;
  v2 = this;
  if ( ICIDM::s_cidm )
  {
    if ( this )
      v3 = (IInputActionCallback *)&this->vfptr;
    else
      v3 = 0;
    ICIDM::s_cidm->vfptr->UnregisterCallback((ICIDM *)ICIDM::s_cidm, v3);
    if ( SmartBox::smartbox )
    {
      v4 = SmartBox::smartbox->cmdinterp;
      if ( v4 )
        v1->vfptr->UnregisterCallback((ICIDM *)v1, (IInputActionCallback *)v4);
    }
  }
  CPlayerSystem::End(v2);
  CPlayerSystem::Begin(v2);
}

//----- (005628C0) --------------------------------------------------------  // acclient.c:400118
void __thiscall CPlayerSystem::~CPlayerSystem(CPlayerSystem *this)
{
  CPlayerSystem *v1; // esi@1
  char *v2; // ebp@1
  char *v3; // ebx@1
  GlobalEventHandler *v4; // eax@1
  void *v5; // ebp@3
  ReferenceCountTemplate<1048576,2>Vtbl *v6; // ebp@7
  unsigned int v7; // edi@10
  char *v8; // [sp+30h] [bp-4h]@1

  v1 = this;
  v2 = (char *)&this[-1].m_contractTrackerTable._contractTrackerHash._currNum;
  v3 = (char *)&this->vfptr;
  v8 = (char *)&this[-1].m_contractTrackerTable._contractTrackerHash._table_size;
  this[-1].m_contractTrackerTable._contractTrackerHash._table_size = (unsigned int)&CPlayerSystem::vftable;
  this[-1].m_contractTrackerTable._contractTrackerHash._currNum = (unsigned int)&CPlayerSystem::vftable;
  this->vfptr = (InterfaceVtbl *)&CPlayerSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)CPlayerSystem::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&CPlayerSystem::vftable;
  CPlayerSystem::End((CPlayerSystem *)((char *)this - 8));
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    1,
    5,
    v1 != (CPlayerSystem *)8 ? (unsigned int)v3 : 0);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    8,
    1,
    v1 != (CPlayerSystem *)8 ? (unsigned int)v3 : 0);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    1,
    230,
    v1 != (CPlayerSystem *)8 ? (unsigned int)v3 : 0);
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers(
      (NoticeRegistrar *)v4,
      (NoticeHandler *)(v1 != (CPlayerSystem *)8 ? (unsigned int)v2 : 0));
  v5 = (void *)v1->account_.m_fIsThroneOfDestinyExpansion;
  if ( v5 )
  {
    ClientCharGenState::~ClientCharGenState((ClientCharGenState *)v1->account_.m_fIsThroneOfDestinyExpansion);
    operator delete(v5);
  }
  v1->account_.m_fIsThroneOfDestinyExpansion = 0;
  v1->m_objectRangeCheckList._tail = (ListNode<ObjectRangeInfo> *)&CContractTrackerTable::vftable;
  v1->m_objectRangeCheckList._num_elements = (unsigned int)&PackableHashTable<unsigned long,CContractTracker>::vftable;
  PackableHashTable<unsigned long,CContractTracker>::EmptyContents((PackableHashTable<unsigned long,GeneratorRegistryNode> *)&v1->m_objectRangeCheckList._num_elements);
  if ( v1->m_contractTrackerTable._contractTrackerHash.vfptr )
  {
    operator delete[](v1->m_contractTrackerTable._contractTrackerHash.vfptr);
    v1->m_contractTrackerTable._contractTrackerHash.vfptr = 0;
  }
  v1->m_contractTrackerTable._contractTrackerHash.m_fThrowawayDuplicateKeysOnUnPack = 0;
  v1->m_objectRangeCheckList._num_elements = (unsigned int)&PackObj::vftable;
  v1->m_objectRangeCheckList._tail = (ListNode<ObjectRangeInfo> *)&PackObj::vftable;
  v1->pending_components_list.tail_ = (NIListElement<unsigned long> *)&List<ObjectRangeInfo>::vftable;
  List<ObjectRangeInfo>::flush((List<ObjectRangeInfo> *)&v1->pending_components_list.tail_);
  NIList<unsigned long>::DeleteContents((NIList<NetPacket *> *)&v1->unblockAttemptNum);
  CInvSlotModule::~CInvSlotModule((CInvSlotModule *)&v1->lastFullyMergedSrcID);
  CPlayerModule::~CPlayerModule((CPlayerModule *)&v1->m_pCharGenState);
  v6 = v1->m_cTurbineRefCount.vfptr;
  if ( !InterlockedDecrement((volatile LONG *)&v6[1]) && v6 )
    (*(void (__thiscall **)(_DWORD, _DWORD))v6->__vecDelDtor)(v6, 1);
  v7 = v1 != (CPlayerSystem *)8 ? (unsigned int)v1 : 0;
  v1->vfptr = (QualityChangeHandlerVtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  *(_DWORD *)v7 = &IInputActionCallback::vftable;
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(v7);
  if ( v8 )
  {
    *((_DWORD *)v8 + 1) = &ClientHousingSystem::vftable;
    NoticeHandler::~NoticeHandler((NoticeHandler *)v8 + 1);
  }
  else
  {
    v0 = (size_t)&ClientHousingSystem::vftable;
    NoticeHandler::~NoticeHandler(0);
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 7A6930: using guessed type int (__thiscall *PackableHashTable<unsigned long,CContractTracker>::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CC7A4: using guessed type int (__thiscall *List<ObjectRangeInfo>::vftable)(void *, char);
// 7CC8F0: using guessed type int (__thiscall *CContractTrackerTable::vftable)(void *, char);
// 7CC9D8: using guessed type void (__thiscall *CPlayerSystem::vftable)(CPlayerSystem *this, unsigned __int32);
// 7CC9E0: using guessed type void (__thiscall *CPlayerSystem::vftable[2])(CPlayerSystem *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7CC9E8: using guessed type int (__stdcall *CPlayerSystem::vftable)(char);
// 7CC9F8: using guessed type bool (__thiscall *CPlayerSystem::vftable)(DBCache *this);
// 7CCCA0: using guessed type __int32 (__stdcall *CPlayerSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00562A70) --------------------------------------------------------  // acclient.c:400212
void __stdcall CPlayerSystem::Handle_AccountBooted(void *buff, unsigned int size)
{
  int v3; // eax@1
  AC1Legacy::PSRefBuffer<char> *v4; // ebp@1
  const unsigned __int16 *v5; // eax@3
  char *v6; // esi@3
  char *v7; // esi@7
  char *v8; // esi@10
  AC1Legacy::PStringBase<char> oldText; // [sp+10h] [bp-9Ch]@1
  PStringBase<unsigned short> additionalReasonText; // [sp+14h] [bp-98h]@1
  PStringBase<unsigned short> reasonText; // [sp+18h] [bp-94h]@7
  StringInfo info; // [sp+1Ch] [bp-90h]@7

  oldText.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  additionalReasonText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v3 = AC1Legacy::PStringBase<char>::UnPack(&oldText, &buff, size);
  v4 = oldText.m_buffer;
  if ( v3 && oldText.m_buffer->m_len != 1 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&oldText,
      0,
      oldText.m_buffer->m_data);
    PStringBase<unsigned short>::operator=(&additionalReasonText, v5);
    v6 = (char *)&oldText.m_buffer[-1].m_cRef;
    if ( !InterlockedDecrement((volatile LONG *)&oldText.m_buffer[-1].m_cRef + 1) && v6 )
      (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
  }
  else
  {
    PStringBase<unsigned short>::set(&additionalReasonText, L" for Code of Conduct Violations");
  }
  reasonText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  PStringBase<unsigned short>::sprintf(
    &reasonText,
    L"You have been booted from Asheron's Call%s.",
    additionalReasonText.m_charbuffer);
  StringInfo::StringInfo(&info);
  StringInfo::SetLiteralValue(&info, &reasonText, 1);
  ((void (__stdcall *)(signed int, StringInfo *))UIFlow::m_instance->vfptr[1].IUnknown_Release)(268435458, &info);
  StringInfo::~StringInfo(&info);
  v7 = (char *)&reasonText.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&reasonText.m_charbuffer[-1].m_data[8]) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  v8 = (char *)&additionalReasonText.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&additionalReasonText.m_charbuffer[-1].m_data[8]) && v8 )
    (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
  {
    if ( v4 )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  }
}
// 83D72C: using guessed type struct UIFlow *UIFlow::m_instance;
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00562BD0) --------------------------------------------------------  // acclient.c:400272
void __stdcall CPlayerSystem::Handle_AccountBanned(void *buff, unsigned int size)
{
  PSRefBufferCharData<unsigned short> *v3; // ebx@1
  int v4; // ebp@1
  const unsigned __int16 *v5; // eax@3
  int v6; // esi@3
  LONG (__stdcall *v7)(volatile LONG *); // edi@8
  signed int v8; // ecx@9
  struct tm *v9; // eax@11
  char *v10; // eax@11
  char *v11; // esi@11
  char *v12; // esi@14
  AC1Legacy::PSRefBuffer<char> *v13; // esi@17
  PStringBase<unsigned short> timeText; // [sp+10h] [bp-A0h]@1
  PStringBase<unsigned short> bannedText; // [sp+14h] [bp-9Ch]@7
  AC1Legacy::PStringBase<char> oldText; // [sp+18h] [bp-98h]@1
  int bannedUntil; // [sp+1Ch] [bp-94h]@3
  StringInfo info; // [sp+20h] [bp-90h]@14

  v3 = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v4 = *(_DWORD *)buff;
  buff = (char *)buff + 4;
  timeText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  oldText.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  if ( AC1Legacy::PStringBase<char>::UnPack(&oldText, &buff, size) && oldText.m_buffer->m_len != 1 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&bannedUntil,
      0,
      oldText.m_buffer->m_data);
    PStringBase<unsigned short>::operator=(&timeText, v5);
    v6 = bannedUntil - 20;
    if ( !InterlockedDecrement((volatile LONG *)(bannedUntil - 20 + 4)) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v3 = timeText.m_charbuffer;
  }
  bannedText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( v4 > 0 )
  {
    v8 = Timer::get_real_time();
    if ( v8 % 60 )
      v8 += 60 - v8 % 60;
    bannedUntil = v4 + v8;
    v9 = _localtime(&bannedUntil);
    v10 = _asctime(v9);
    v10[strlen(v10) - 1] = 0;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&timeText, 0, v10);
    PStringBase<unsigned short>::sprintf(
      &bannedText,
      L"You have been banned until %s%s. For ban appeals, please visit support.turbine.com",
      timeText.m_charbuffer,
      v3);
    v7 = InterlockedDecrement;
    v11 = (char *)&timeText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&timeText.m_charbuffer[-1].m_data[8]) && v11 )
      (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
  }
  else
  {
    PStringBase<unsigned short>::sprintf(&bannedText, L"You have been banned from Asheron's Call%s.", v3);
    v7 = InterlockedDecrement;
  }
  StringInfo::StringInfo(&info);
  StringInfo::SetLiteralValue(&info, &bannedText, 1);
  ((void (__stdcall *)(signed int, StringInfo *))UIFlow::m_instance->vfptr[1].IUnknown_Release)(268435458, &info);
  StringInfo::~StringInfo(&info);
  v12 = (char *)&bannedText.m_charbuffer[-1].m_data[6];
  if ( !v7((volatile LONG *)&bannedText.m_charbuffer[-1].m_data[8]) && v12 )
    (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
  v13 = oldText.m_buffer;
  if ( !v7((volatile LONG *)&oldText.m_buffer->m_cRef) && v13 )
    v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
  if ( !v7((volatile LONG *)&v3[-1].m_data[8]) && v3 != (PSRefBufferCharData<unsigned short> *)20 )
    (**(void (__thiscall ***)(unsigned __int16 *, signed int))&v3[-1].m_data[6])(&v3[-1].m_data[6], 1);
}
// 83D72C: using guessed type struct UIFlow *UIFlow::m_instance;
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00562DD0) --------------------------------------------------------  // acclient.c:400354
void __thiscall CPlayerSystem::RequestLogOff(CPlayerSystem *this)
{
  CPlayerSystem *v1; // esi@1
  char *v2; // edi@1
  unsigned int v3; // eax@4
  HashBaseData<unsigned long> *v4; // eax@4
  PStringBase<unsigned short> i_text; // [sp+0h] [bp-4h]@1

  i_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v1 = this;
  PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, 0, "Logging off...\n");
  ClientSystem::AddTextToScroll((ClientSystem *)&v1->vfptr, &i_text, 0, 1, 0);
  v2 = (char *)&i_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  Proto_UI::LogOffCharacter(v1->playerID);
  v3 = v1->playerID;
  v1->logOffRequested = 1;
  v1->logOffRequestTime = COERCE_DOUBLE(Timer::cur_time.Cmd) + 3.0;
  v4 = ClientObjMaintSystem::GetWeenieObject(v3);
  if ( v4 && ((int (__thiscall *)(HashBaseData<unsigned long> *))v4->vfptr[7].__vecDelDtor)(v4) )
    v1->logOffRequestTime = v1->logOffRequestTime + 20.0;
  ((void (*)(void))SmartBox::smartbox->cmdinterp->vfptr[12].OnAction)();
}

//----- (00562E90) --------------------------------------------------------  // acclient.c:400380
void __thiscall CPlayerSystem::SendLoginCompleteNotification(CPlayerSystem *this)
{
  CPlayerSystem *v1; // esi@1
  HashBaseData<unsigned long> *v2; // eax@1
  HashBaseData<unsigned long> *v3; // edi@1
  IACPlugin *v4; // eax@5

  v1 = this;
  v2 = ClientObjMaintSystem::GetWeenieObject(this->playerID);
  v3 = v2;
  if ( v2 && ACCWeenieObject::AllContainedObjectsExist((ACCWeenieObject *)v2) )
  {
    CM_Character::Event_LoginCompleteNotification();
    if ( !v1->initialLoginComplete )
    {
      PlayerDesc::PlayerIsPSR((PlayerDesc *)v3[27].id);
      if ( APIManager::APIIsReady() )
      {
        v4 = APIManager::GetACPlugin();
        ((void (__stdcall *)(IACPlugin *))v4->vfptr[2].QueryInterface)(v4);
        CPlayerSystem::SendQueryPluginData(0);
      }
    }
    v1->initialLoginComplete = 1;
    CM_UI::SendNotice_SetDisplayInventory(1);
    UIElementManager::BroadcastGlobalMessage(UIElementManager::s_pInstance, 0xBu, 0);
    v1->sendLoginCompletePending = 0;
  }
  else
  {
    v1->sendLoginCompletePending = 1;
  }
}

//----- (00562F20) --------------------------------------------------------  // acclient.c:400415
void __thiscall CPlayerSystem::AttemptSendLoginCompleteNotification(CPlayerSystem *this)
{
  CPlayerSystem *v1; // esi@1
  HashBaseData<unsigned long> *v2; // eax@1
  bool v3; // al@4

  v1 = this;
  v2 = ClientObjMaintSystem::GetWeenieObject(this->playerID);
  if ( v1->player_desc_received && v2 && ACCWeenieObject::AllContainedObjectsExist((ACCWeenieObject *)v2) )
  {
    v3 = v1->sendLoginCompletePending;
    v1->allContainedObjectsReceived = 1;
    if ( v3 )
      CPlayerSystem::SendLoginCompleteNotification(v1);
  }
}

//----- (00562F70) --------------------------------------------------------  // acclient.c:400433
bool __thiscall CPlayerSystem::UsingItem(CPlayerSystem *this, unsigned int _itemID, int _useable, int _forceUse)
{
  unsigned int v4; // edi@1
  signed int v5; // esi@1
  CPlayerSystem *v6; // ebx@1
  bool result; // al@2
  HashBaseData<unsigned long> *v8; // ebp@3

  v4 = _itemID;
  v5 = 0;
  v6 = this;
  if ( _itemID )
  {
    v8 = ClientObjMaintSystem::GetWeenieObject(_itemID);
    if ( v8 )
    {
      if ( !_forceUse )
      {
        switch ( ItemHolder::DetermineUseResult((ACCWeenieObject *)v8) )
        {
          case 2u:
            v5 = (unsigned __int8)CPlayerSystem::PlaceInBackpack(v6, v4, 0);
            break;
          case 3u:
            v5 = CPlayerSystem::AutoWield(v6, v4, SLOT_SIDE_RIGHT, 0, 1, 0, 1);
            break;
          case 8u:
            v5 = CPlayerSystem::AutoWield(v6, v4, SLOT_SIDE_LEFT, 0, 1, 0, 1);
            break;
          case 4u:
            v5 = CPlayerSystem::AutoSort(v6, v4, 1, 0);
            break;
          case 5u:
            ClientTradeSystem::GetTradeSystem();
            v5 = (unsigned __int8)ClientTradeSystem::AttemptToOpenTradeNegotiations(v4);
            break;
          case 6u:
            CM_Inventory::SendNotice_OpenSalvagePanel(v4);
            v5 = 1;
            break;
          case 7u:
            CM_Game::SendNotice_BeginGame(v4);
            break;
          default:
            break;
        }
      }
      ItemUses::ItemUses((ItemUses *)&_itemID, (const unsigned int)v8[18].vfptr);
      if ( ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v8)
        && ACCWeenieObject::IsContainer((ACCWeenieObject *)v8) )
      {
        CM_UI::SendNotice_OpenContainedContainer(v8->id);
        v5 = 1;
      }
      if ( ItemUses::IsUseable((ItemUses *)&_itemID)
        && !ItemUses::IsUseable_Targeted((ItemUses *)&_itemID)
        && ACCWeenieObject::IsContainer((ACCWeenieObject *)v8)
        && !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v8) )
      {
        ItemHolder::AttemptSetGroundObject(v4);
        v5 = 1;
      }
      result = v5 != 0;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005630E0) --------------------------------------------------------  // acclient.c:400510
int __thiscall CPlayerSystem::scalar_deleting_destructor(CPlayerSystem *this, char a2)
{
  CPlayerSystem *v2; // esi@1
  int result; // eax@1

  v2 = this;
  CPlayerSystem::~CPlayerSystem(this);
  result = (int)&v2[-1].m_contractTrackerTable._contractTrackerHash._table_size;
  if ( a2 & 1 )
  {
    operator delete(&v2[-1].m_contractTrackerTable._contractTrackerHash._table_size);
    result = (int)&v2[-1].m_contractTrackerTable._contractTrackerHash._table_size;
  }
  return result;
}

//----- (00563110) --------------------------------------------------------  // acclient.c:400527
void __thiscall CPlayerSystem::UseTime(CPlayerSystem *this)
{
  CPlayerSystem *v1; // esi@1
  int v2; // eax@3
  gmClient *v3; // eax@9
  long double v4; // st7@9
  int bNetConnected; // [sp+Ch] [bp-Ch]@9
  long double curTime; // [sp+10h] [bp-8h]@1

  v1 = this;
  curTime = *(double *)&Timer::cur_time;
  if ( this->awaitingLogOn )
  {
    if ( this->fReadyToEnterGame )
    {
      this->awaitingLogOn = 0;
      v2 = ((int (*)(void))UIFlow::m_instance->vfptr[1].QueryInterface)();
      if ( v2 )
        CPlayerSystem::LogOnCharacter(v1, *(_DWORD *)(v2 + 76));
    }
  }
  if ( v1->logOnRequestTime != 0.0 && curTime - v1->logOnRequestTime >= 110.0 )
  {
    LODWORD(v1->logOnRequestTime) = 0;
    HIDWORD(v1->logOnRequestTime) = 0;
    ECM_Login::SendNotice_ServerDied();
  }
  if ( curTime - lastCheckLinkStatusTime > 4.0 )
  {
    v3 = Client::GetInstance();
    v4 = LinkStatusHolder::GetConnectionStatus((LinkStatusHolder *)&v3->vfptr, &bNetConnected);
    if ( !v1->connectionLost && (v4 > 40.0 || !bNetConnected) )
      ECM_Login::SendNotice_ServerDied();
    lastCheckLinkStatusTime = curTime;
  }
  CPlayerModule::UseTime(&v1->playerModule);
  if ( v1->loggingOff && ACCWeenieObject::prevRequest == IR_NONE )
  {
    v1->loggingOff = 0;
    CPlayerSystem::RequestLogOff(v1);
  }
  if ( v1->awaitingExpiration && curTime >= v1->expirationTime )
  {
    ECM_Login::SendNotice_CharacterError(CHAR_ERROR_SUBSCRIPTION_EXPIRED);
    v1->awaitingExpiration = 0;
  }
  CPlayerSystem::CalculateObjectRangeChecks(v1);
}
// 83D72C: using guessed type struct UIFlow *UIFlow::m_instance;
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;

//----- (00563260) --------------------------------------------------------  // acclient.c:400579
void __thiscall CPlayerSystem::RecvNotice_ServerSaysMoveItem(CPlayerSystem *this, unsigned int _itemID, unsigned int _oldContainer, unsigned int _oldWielder, unsigned int _oldLocation, unsigned int _newContainer, int _place, unsigned int _newWielder, unsigned int _newLocation)
{
  CPlayerSystem *v9; // ebp@1
  HashBaseData<unsigned long> *v10; // esi@1
  int v11; // ebx@1
  ClientUISystem *v12; // eax@2
  ClientTradeSystem *v13; // edi@5
  ClientUISystem *v14; // ebp@5
  bool v15; // bl@13
  bool v16; // al@15
  unsigned int v17; // edi@36
  UI_SLOT_SIDE v18; // eax@37
  int v19; // ecx@37
  HashBaseData<unsigned long> *v20; // eax@39
  int v21; // eax@42
  int v22; // eax@44
  int v23; // eax@45
  IDList *v24; // eax@47
  IDList *v25; // edi@47
  int v26; // ebp@49
  unsigned int v27; // eax@50
  HashBaseData<unsigned long> *v28; // esi@50
  int v29; // eax@51
  bool objectOwnedByTradingPart; // [sp+13h] [bp-9h]@11
  CPlayerSystem *v31; // [sp+14h] [bp-8h]@1
  ClientObjMaintSystem *pObjMaint; // [sp+18h] [bp-4h]@6

  v9 = this;
  v31 = this;
  v10 = ClientObjMaintSystem::GetWeenieObject(_itemID);
  v11 = 0;
  if ( _itemID == ClientUISystem::GetUISystem()->groundObject )
  {
    v12 = ClientUISystem::GetUISystem();
    ClientUISystem::SetGroundObject(v12, 0, 1);
  }
  if ( _newContainer )
  {
    if ( !v10 )
      goto LABEL_34;
    v13 = ClientTradeSystem::GetTradeSystem();
    v14 = ClientUISystem::GetUISystem();
    if ( CObjectMaint::s_pcInstance )
      pObjMaint = (ClientObjMaintSystem *)&CObjectMaint::s_pcInstance[-1].object_destruction_queue.allocatedNodes;
    else
      pObjMaint = 0;
    objectOwnedByTradingPart = v13->m_iidTradePartner
                            && (ACCWeenieObject::IsOwnedByTrader((ACCWeenieObject *)v10, v13->m_iidTradePartner)
                             || ClientTradeSystem::IsPartnerTradingItem(v13, _itemID));
    v15 = ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v10) != 0;
    v16 = v14->groundObject && ACCWeenieObject::IsOwnedByObject((ACCWeenieObject *)v10, v14->groundObject);
    if ( v15 || v16 || objectOwnedByTradingPart )
    {
      ACCWeenieObject::RemoveContentsFromDestructionQueue((ACCWeenieObject *)v10);
      CObjectMaint::RemoveObjectToBeDestroyed((CObjectMaint *)&pObjMaint->vfptr, _itemID);
    }
    else
    {
      ACCWeenieObject::AddContentsToDestructionQueue((ACCWeenieObject *)v10);
      CObjectMaint::AddObjectToBeDestroyed((CObjectMaint *)&pObjMaint->vfptr, _itemID);
      if ( _itemID == ACCWeenieObject::selectedID )
        ACCWeenieObject::SetSelectedObject(0, 0);
    }
    if ( !v31->fReadyToEnterGame && v15 )
      CPlayerSystem::AttemptSendLoginCompleteNotification((CPlayerSystem *)((char *)v31 - 4));
    v9 = v31;
    v11 = 0;
  }
  if ( v10 )
  {
    if ( v10[9].id && !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v10) )
      ACCWeenieObject::SetSellState((ACCWeenieObject *)v10, 0);
    if ( v10[10].vfptr && !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v10) )
      ACCWeenieObject::SetTradeState((ACCWeenieObject *)v10, 0);
  }
LABEL_34:
  if ( v9->blockedSide > 0 && v9->m_invSlotModule.footSlot == (CInvSlotInfo *)_itemID )
  {
    v17 = v9->blockingID;
    if ( v17 )
    {
      v18 = v9->blockedSpellID;
      v19 = (int)&v9[-1].m_contractTrackerTable._contractTrackerHash._currNum;
      *(_DWORD *)(v19 + 684) = 0;
      *(_DWORD *)(v19 + 688) = 0;
      *(_DWORD *)(v19 + 704) = 0;
      *(_DWORD *)(v19 + 708) = 0;
      if ( v9->blockedID == _newContainer && !CPlayerSystem::AutoWield((CPlayerSystem *)v19, v17, v18, 0, 1, 0, 1) )
      {
        v20 = ClientObjMaintSystem::GetWeenieObject(v17);
        if ( v20 )
          ACCWeenieObject::SetWaitingState((ACCWeenieObject *)v20, 0);
      }
    }
  }
  if ( v10 )
  {
    v21 = ((int (__thiscall *)(HashBaseData<unsigned long> *))v10->vfptr[6].__vecDelDtor)(v10);
    if ( BYTE1(v21) & 0x10 )
      CPlayerSystem::UpdateSpellComponent((CPlayerSystem *)((char *)v9 - 4), (ACCWeenieObject *)v10, 1);
    v22 = ((int (__thiscall *)(HashBaseData<unsigned long> *))v10->vfptr[6].__vecDelDtor)(v10);
    if ( BYTE1(v22) & 2 )
    {
      v23 = HIDWORD(v9->playerModule.m_timeFirstDirtied);
      if ( _oldContainer == v23 || _newContainer == v23 )
      {
        v24 = ACCWeenieObject::GetContainedItemsList((ACCWeenieObject *)v10);
        v25 = v24;
        if ( v24 && (IDList::SetCurToNum(v24, 0), v25->numIDs > 0) )
        {
          v26 = _itemID;
          do
          {
            v27 = IDList::GetCurID(v25);
            v28 = ClientObjMaintSystem::GetWeenieObject(v27);
            if ( v28 )
            {
              v29 = ((int (__thiscall *)(HashBaseData<unsigned long> *))v28->vfptr[6].__vecDelDtor)(v28);
              if ( BYTE1(v29) & 0x10 )
                v26 = CPlayerSystem::UpdateSpellComponent((CPlayerSystem *)((char *)v31 - 4), (ACCWeenieObject *)v28, 0);
            }
            IDList::SetCurToNext(v25);
            ++v11;
          }
          while ( v11 < v25->numIDs );
          CM_Magic::SendNotice_UpdateSpellComponents(v26);
        }
        else
        {
          CM_Magic::SendNotice_UpdateSpellComponents(_itemID);
        }
      }
    }
  }
}

//----- (00563520) --------------------------------------------------------  // acclient.c:400716
void __thiscall CPlayerSystem::LogOffCharacter(CPlayerSystem *this, bool _immediate)
{
  CPlayerSystem *v2; // esi@1

  v2 = this;
  CPlayerModule::SaveToServer(&this->playerModule, 0);
  if ( _immediate )
  {
    CPlayerSystem::ExecuteLogOff(v2);
  }
  else if ( ACCWeenieObject::prevRequest )
  {
    ClientSystem::AddTextToScroll((ClientSystem *)&v2->vfptr, "Logging off...\n", 0, 1, 0);
    v2->loggingOff = 1;
  }
  else
  {
    CPlayerSystem::RequestLogOff(v2);
  }
}
// 870EC0: using guessed type enum InventoryRequest ACCWeenieObject::prevRequest;

//----- (00563570) --------------------------------------------------------  // acclient.c:400739
void __thiscall CPlayerSystem::InitializePlayer(CPlayerSystem *this)
{
  CPlayerSystem *v1; // esi@1
  unsigned int v2; // ecx@2
  unsigned int v3; // eax@2
  HashBaseData<unsigned long> *v4; // eax@2
  NIListElement<unsigned long> *v5; // eax@3
  unsigned int v6; // edi@4
  NIListElement<unsigned long> *v7; // ecx@5
  HashBaseData<unsigned long> *v8; // ebp@9
  ClientMagicSystem *v9; // eax@11
  SpellComponentTable *v10; // edi@11
  ComponentTracker *v11; // eax@11
  ComponentTracker *v12; // eax@12
  ComponentTrackerUpdate componentsChange; // [sp+0h] [bp-4h]@1

  componentsChange = (ComponentTrackerUpdate)this;
  v1 = this;
  if ( !this->player_initialized )
  {
    this->player_initialized = 1;
    v2 = Timer::cur_time.Param;
    LODWORD(v1->playerInitTime) = Timer::cur_time.Cmd;
    HIDWORD(v1->playerInitTime) = v2;
    v3 = SmartBox::smartbox->player_id;
    v1->playerID = v3;
    LODWORD(v1->logOnRequestTime) = 0;
    HIDWORD(v1->logOnRequestTime) = 0;
    v4 = ClientObjMaintSystem::GetWeenieObject(v3);
    ACCWeenieObject::RemoveContentsFromDestructionQueue((ACCWeenieObject *)v4);
    if ( v1->pending_components_list.head_ )
    {
      while ( 1 )
      {
        v5 = v1->pending_components_list.head_;
        if ( v5 )
        {
          v7 = v5->next_;
          v1->pending_components_list.head_ = v7;
          if ( !v7 )
            v1->pending_components_list.tail_ = 0;
          v6 = v5->data_;
          operator delete(v5);
        }
        else
        {
          v6 = 0;
        }
        if ( !v6 )
          break;
        v8 = ClientObjMaintSystem::GetWeenieObject(v6);
        if ( v8 )
        {
          if ( !v1->componentTracker )
          {
            v9 = ClientMagicSystem::GetMagicSystem();
            v10 = ClientMagicSystem::GetSpellComponentTable(v9);
            v11 = (ComponentTracker *)operator new(0x108u);
            if ( v11 )
              ComponentTracker::ComponentTracker(v11, v10);
            else
              v12 = 0;
            v1->componentTracker = v12;
          }
          ComponentTracker::UpdateComponent(v1->componentTracker, (ACCWeenieObject *)v8, &componentsChange);
        }
      }
    }
    CM_Magic::SendNotice_UpdateSpellComponents(1);
    if ( v1->sendLoginCompletePending )
      CPlayerSystem::AttemptSendLoginCompleteNotification(v1);
    CM_House::Event_QueryHouse();
  }
}

//----- (005636A0) --------------------------------------------------------  // acclient.c:400815
void __thiscall CPlayerSystem::Handle_PlayerDescription(CPlayerSystem *this, void *buff, unsigned int size)
{
  CPlayerSystem *v3; // edi@1
  char *v4; // esi@1
  InterfaceSystem *v5; // eax@1
  unsigned int v6; // ebp@1
  unsigned int v7; // ST08_4@6
  unsigned int v8; // esi@6
  InterfaceSystem *v9; // eax@9
  unsigned int v10; // ebp@9
  ACCObjectMaint *v11; // ebp@13
  CPlayerModule *v12; // edi@15
  PlayerDesc *v13; // esi@15
  int v14; // [sp-8h] [bp-50h]@1
  int v15; // [sp-8h] [bp-50h]@9
  TResult result; // [sp+10h] [bp-38h]@1
  TResult v17; // [sp+14h] [bp-34h]@3
  InterfacePtr<PlayerDesc> pPD; // [sp+18h] [bp-30h]@1
  InterfacePtr<ClientObjMaintSystem> pObjMaint; // [sp+20h] [bp-28h]@9
  PackableList<InventoryPlacement> ilist; // [sp+28h] [bp-20h]@6
  PackableList<ContentProfile> clist; // [sp+38h] [bp-10h]@6

  v3 = this;
  v4 = (char *)buff + size;
  size = 0;
  v5 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v5, &result, &PlayerDesc_ClassType_26, (Interface **)&size);
  v14 = size;
  v6 = size;
  pPD.m_pInterface = 0;
  pPD.m_trStatus.m_val = 0;
  if ( size )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)size + 16))(size);
  InterfacePtr<PlayerDesc>::_QueryInterface(&pPD, (int)&v17, v14, 0);
  if ( v6 )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v6 + 20))(v6);
  if ( (_DWORD)pPD.m_pInterface )
  {
    ((void (__stdcall *)(_DWORD, _DWORD))pPD.m_pInterface->vfptr->UnPack)(&buff, v4 - (_BYTE *)buff);
    PlayerModule::Clear((PlayerModule *)&v3->playerModule.vfptr);
    ((void (__thiscall *)(int, void **, int))v3->playerModule.vfptr->UnPack)(
      &v3->playerModule.vfptr,
      &buff,
      v4 - (_BYTE *)buff);
    v7 = v4 - (_BYTE *)buff;
    v3->player_desc_received = 1;
    clist.vfptr = (PackObjVtbl *)&PackableList<ContentProfile>::vftable;
    clist.head = 0;
    clist.tail = 0;
    clist.curNum = 0;
    ilist.vfptr = (PackObjVtbl *)&PackableList<InventoryPlacement>::vftable;
    ilist.head = 0;
    ilist.tail = 0;
    ilist.curNum = 0;
    PackableList<ContentProfile>::UnPack(&clist, &buff, v7);
    PackableList<InventoryPlacement>::UnPack(&ilist, &buff, v4 - (_BYTE *)buff);
    v8 = v3->playerID;
    if ( !v8 && SmartBox::smartbox )
      v8 = SmartBox::smartbox->player_id;
    size = 0;
    v9 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v9, &v17, &ClientObjMaintSystem_ClassType_3, (Interface **)&size);
    v15 = size;
    v10 = size;
    pObjMaint.m_pInterface = 0;
    pObjMaint.m_trStatus.m_val = 0;
    if ( size )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)size + 16))(size);
    InterfacePtr<ClientObjMaintSystem>::_QueryInterface(&pObjMaint, (int)&result, v15, 0);
    if ( v10 )
      (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v10 + 20))(v10);
    v11 = (ACCObjectMaint *)&pObjMaint.m_pInterface->vfptr;
    ACCObjectMaint::ViewObjectContents((ACCObjectMaint *)&pObjMaint.m_pInterface->vfptr, v8, &clist);
    ACCObjectMaint::UpdateObjectInventory(v11, v8, &ilist);
    if ( !v3->player_initialized )
      CPlayerSystem::InitializePlayer(v3);
    v12 = &v3->playerModule;
    CPlayerModule::OnInitialize(v12);
    v13 = pPD.m_pInterface;
    CM_UI::SendNotice_PlayerDescReceived((CACQualities *)&pPD.m_pInterface->vfptr, v12);
    CM_Character::SendNotice_ReloadOptions();
    if ( (_DWORD)pObjMaint.m_pInterface )
      ((void (*)(void))pObjMaint.m_pInterface->vfptr->Release)();
    ilist.vfptr = (PackObjVtbl *)&PackableList<InventoryPlacement>::vftable;
    PackableList<InventoryPlacement>::Flush(&ilist);
    ilist.vfptr = (PackObjVtbl *)&PackObj::vftable;
    clist.vfptr = (PackObjVtbl *)&PackableList<ContentProfile>::vftable;
    PackableList<ContentProfile>::Flush(&clist);
    v13->vfptr->Release((Interface *)v13);
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CC3F8: using guessed type int (__thiscall *PackableList<ContentProfile>::vftable)(void *, char);
// 7CC790: using guessed type int (__thiscall *PackableList<InventoryPlacement>::vftable)(void *, char);

//----- (00708170) --------------------------------------------------------  // acclient.c:795340
void sub_708170()
{
  flt_8701AC = 1000.0 + 1.0;
}

//----- (00708190) --------------------------------------------------------  // acclient.c:795346
void sub_708190()
{
  flt_8701B0 = 24.0 * 8.0;
}

//----- (007081B0) --------------------------------------------------------  // acclient.c:795352
void sub_7081B0()
{
  flt_8701B4 = 24.0 * 0.5;
}

//----- (007081D0) --------------------------------------------------------  // acclient.c:795358
int sub_7081D0()
{
  return atexit(nullsub_1370);
}

//----- (007081E0) --------------------------------------------------------  // acclient.c:795364
int sub_7081E0()
{
  return atexit(nullsub_1371);
}

//----- (007081F0) --------------------------------------------------------  // acclient.c:795370
int sub_7081F0()
{
  return atexit(nullsub_1372);
}

//----- (00708200) --------------------------------------------------------  // acclient.c:795376
void sub_708200()
{
  flt_8701B8 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00708220) --------------------------------------------------------  // acclient.c:795382
void _E108_86()
{
  dbl_8701C0 = 1.0 / 30.0;
}

//----- (00708240) --------------------------------------------------------  // acclient.c:795388
void _E110_69()
{
  dbl_8701C8 = 1.0 / 5.0;
}

//----- (00708260) --------------------------------------------------------  // acclient.c:795394
void sub_708260()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8701D0, PFID_A8R8G8B8);
}

//----- (00708270) --------------------------------------------------------  // acclient.c:795400
int _E114_59()
{
  return atexit(nullsub_1368);
}

//----- (00708280) --------------------------------------------------------  // acclient.c:795406
void _E118_74()
{
  dword_870208 = 1024;
}

//----- (00708290) --------------------------------------------------------  // acclient.c:795412
void _E120_66()
{
  dword_87020C = 0x7FFF;
}

//----- (007082A0) --------------------------------------------------------  // acclient.c:795418
int _E122_29()
{
  const int result; // eax@1

  result = dword_870208;
  dword_870210 = dword_870208;
  return result;
}

//----- (007082B0) --------------------------------------------------------  // acclient.c:795428
int _E124_64()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_45, "Misc.TooltipEnable");
  return atexit(_E125_62);
}

//----- (007082D0) --------------------------------------------------------  // acclient.c:795435
int _E127_54()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_45, "Misc.TooltipDelay");
  return atexit(_E128_60);
}

//----- (007082F0) --------------------------------------------------------  // acclient.c:795442
int _E133_42()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_20, "Sound.SoundDisabled");
  return atexit(_E134_36);
}

//----- (00708310) --------------------------------------------------------  // acclient.c:795449
int _E136_28()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_20, "Sound.SoundVolume");
  return atexit(_E137_35);
}

//----- (00708330) --------------------------------------------------------  // acclient.c:795456
int _E139_28()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_20, "Sound.AmbientSoundDisabled");
  return atexit(_E140_29);
}

//----- (00708350) --------------------------------------------------------  // acclient.c:795463
int _E142_25()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_20, "Sound.AmbientSoundVolume");
  return atexit(_E143_29);
}

//----- (00708370) --------------------------------------------------------  // acclient.c:795470
int _E145_27()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_20, "Sound.InterfaceSoundDisabled");
  return atexit(_E146_29);
}

//----- (00708390) --------------------------------------------------------  // acclient.c:795477
int _E148_27()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_20, "Sound.InterfaceSoundVolume");
  return atexit(_E149_29);
}

//----- (007083B0) --------------------------------------------------------  // acclient.c:795484
int _E151_25()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_20, "Sound.SoundFeatures");
  return atexit(_E152_30);
}

//----- (007083D0) --------------------------------------------------------  // acclient.c:795491
int _E154_26()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_20, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E155_26);
}

//----- (007083F0) --------------------------------------------------------  // acclient.c:795498
int _E157_24()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_20, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_870240, "Mono");
  return atexit(_E158_28);
}

//----- (00708420) --------------------------------------------------------  // acclient.c:795506
void _E160_27()
{
  VOL_MIN_DIST_SQ_17 = 5.0 * 5.0;
}

//----- (00708440) --------------------------------------------------------  // acclient.c:795512
void _E162_35()
{
  INV_LOG_OF_2_17 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (00708460) --------------------------------------------------------  // acclient.c:795518
int sub_708460()
{
  return atexit(nullsub_1369);
}

//----- (00773280) --------------------------------------------------------  // acclient.c:906929
void __cdecl _E125_62()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007732B0) --------------------------------------------------------  // acclient.c:906942
void __cdecl _E128_60()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007732E0) --------------------------------------------------------  // acclient.c:906955
void __cdecl _E134_36()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773310) --------------------------------------------------------  // acclient.c:906968
void __cdecl _E137_35()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773340) --------------------------------------------------------  // acclient.c:906981
void __cdecl _E140_29()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773370) --------------------------------------------------------  // acclient.c:906994
void __cdecl _E143_29()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007733A0) --------------------------------------------------------  // acclient.c:907007
void __cdecl _E146_29()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007733D0) --------------------------------------------------------  // acclient.c:907020
void __cdecl _E149_29()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773400) --------------------------------------------------------  // acclient.c:907033
void __cdecl _E152_30()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773430) --------------------------------------------------------  // acclient.c:907046
void __cdecl _E155_26()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773460) --------------------------------------------------------  // acclient.c:907059
void __cdecl _E158_28()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_17;
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

