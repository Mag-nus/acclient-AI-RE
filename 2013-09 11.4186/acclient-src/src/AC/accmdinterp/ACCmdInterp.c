/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ACCmdInterp
   Object     : AC\accmdinterp\ACCmdInterp.obj
   Functions  : 40
   Addresses  : 0043C580 - 0070A780 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0043C580) --------------------------------------------------------  // acclient.c:121193
unsigned int *__thiscall HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(HashTable<unsigned long,unsigned long,0> *this, const unsigned int *_key)
{
  HashTableData<unsigned long,unsigned long> *v2; // eax@1
  unsigned int *result; // eax@4

  v2 = this->m_intrusiveTable.m_buckets[*_key % this->m_intrusiveTable.m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey != *_key )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 )
    result = &v2->m_data;
  else
LABEL_4:
    result = 0;
  return result;
}

//----- (0058B160) --------------------------------------------------------  // acclient.c:435802
void __thiscall ACCmdInterp::TakeControlFromServer(ACCmdInterp *this)
{
  CommandInterpreter *v1; // esi@1
  ClientCombatSystem *v2; // eax@2

  v1 = (CommandInterpreter *)this;
  if ( ClientCombatSystem::GetCombatSystem() )
  {
    v2 = ClientCombatSystem::GetCombatSystem();
    ClientCombatSystem::AbortAutomaticAttack(v2);
  }
  CommandInterpreter::TakeControlFromServer(v1);
}

//----- (0058B180) --------------------------------------------------------  // acclient.c:435817
int ACCmdInterp::UITogglesRun()
{
  CPlayerSystem *v1; // eax@1
  int result; // eax@2

  v1 = CPlayerSystem::GetPlayerSystem();
  if ( v1 )
    result = (unsigned __int8)PlayerModule::ToggleRun((PlayerModule *)&v1->playerModule.vfptr);
  else
    result = 0;
  return result;
}

//----- (0058B1A0) --------------------------------------------------------  // acclient.c:435831
void __thiscall ACCmdInterp::CommenceJump(ACCmdInterp *this)
{
  DiskSpace *v1; // esi@1
  ClientCombatSystem *v2; // eax@1

  v1 = (DiskSpace *)this;
  v2 = ClientCombatSystem::GetCombatSystem();
  ClientCombatSystem::CommenceJump(v2);
  gmNoticeHandler::RecvNotice_PrevSpellSelection(v1);
}

//----- (0058B1C0) --------------------------------------------------------  // acclient.c:435843
void __stdcall ACCmdInterp::DoJump(bool autonomous)
{
  ClientCombatSystem *v2; // eax@1

  v2 = ClientCombatSystem::GetCombatSystem();
  ClientCombatSystem::DoJump(v2, autonomous);
}

//----- (0058B1D0) --------------------------------------------------------  // acclient.c:435852
void __thiscall ACCmdInterp::FinishJump(ACCmdInterp *this)
{
  DiskSpace *v1; // esi@1
  ClientCombatSystem *v2; // eax@1

  v1 = (DiskSpace *)this;
  v2 = ClientCombatSystem::GetCombatSystem();
  if ( v2 )
    ClientCombatSystem::FinishJump(v2);
  gmNoticeHandler::RecvNotice_PrevSpellSelection(v1);
}

//----- (0058B1F0) --------------------------------------------------------  // acclient.c:435865
void __thiscall ACCmdInterp::HandleNewForwardMovement(ACCmdInterp *this)
{
  CommandInterpreter *v1; // esi@1
  ClientCombatSystem *v2; // eax@2

  v1 = (CommandInterpreter *)this;
  if ( ClientCombatSystem::GetCombatSystem() )
  {
    v2 = ClientCombatSystem::GetCombatSystem();
    ClientCombatSystem::AbortAutomaticAttack(v2);
  }
  CommandInterpreter::HandleNewForwardMovement(v1);
}

//----- (0058B210) --------------------------------------------------------  // acclient.c:435880
BOOL __stdcall ACCmdInterp::SendAutonomyLevelEvent(unsigned int level)
{
  return CM_Movement::Event_AutonomyLevel(level);
}

//----- (0058B230) --------------------------------------------------------  // acclient.c:435886
BOOL __stdcall ACCmdInterp::SendDoMovementEvent(unsigned int motion, float speed, HoldKey hold_key)
{
  return CM_Movement::Event_DoMovementCommand(motion, speed, hold_key);
}

//----- (0058B250) --------------------------------------------------------  // acclient.c:435892
BOOL __stdcall ACCmdInterp::SendStopMovementEvent(unsigned int motion, HoldKey hold_key)
{
  return CM_Movement::Event_StopMovementCommand(motion, hold_key);
}

//----- (0058B270) --------------------------------------------------------  // acclient.c:435898
BOOL __stdcall ACCmdInterp::SendMoveToStateEvent(MoveToStatePack *mtsp)
{
  return CM_Movement::Event_MoveToState(mtsp);
}

//----- (0058B290) --------------------------------------------------------  // acclient.c:435904
BOOL __stdcall ACCmdInterp::SendAutonomousPositionEvent(AutonomousPositionPack *app)
{
  return CM_Movement::Event_AutonomousPosition(app);
}

//----- (0058B2B0) --------------------------------------------------------  // acclient.c:435910
BOOL __stdcall ACCmdInterp::SendTurnToEvent(TurnToEventPack *tep)
{
  return CM_Movement::Event_TurnToEvent(tep);
}

//----- (0058B2D0) --------------------------------------------------------  // acclient.c:435916
void __thiscall ACCmdInterp::RecvNotice_PlayerOptionChanged(ACCmdInterp *this, PlayerOption i_eOption)
{
  ACCmdInterp *v2; // esi@1
  int v3; // ST00_4@3
  CMotionInterp *v4; // eax@3

  v2 = this;
  if ( i_eOption == 10 )
  {
    if ( LODWORD(this[-1].last_sent_position.frame.m_fOrigin.y) )
    {
      v3 = (*(int (__thiscall **)(float *))(LODWORD(this[-1].last_sent_position.frame.qy) + 60))(&this[-1].last_sent_position.frame.qy);
      v4 = CPhysicsObj::get_minterp(LODWORD(v2[-1].last_sent_position.frame.m_fl2gv[0]));
      CMotionInterp::set_hold_run(v4, v3, 1);
    }
  }
}

//----- (0058B310) --------------------------------------------------------  // acclient.c:435935
void __thiscall ACCmdInterp::SetMotion(ACCmdInterp *this, unsigned int motion, bool fOn)
{
  CmdStruct cmdstruct; // [sp+0h] [bp-10Ch]@2

  if ( this->player )
  {
    cmdstruct.curr = 0;
    cmdstruct.command = motion;
    *(_DWORD *)&cmdstruct.args[0] = fOn;
    cmdstruct.size = 4;
    ((void (__stdcall *)(_DWORD))SmartBox::smartbox->cmdinterp->vfptr[12].OnLoseFocus)(&cmdstruct);
  }
}

//----- (0058B370) --------------------------------------------------------  // acclient.c:435950
char __thiscall ACCmdInterp::OnAction(ACCmdInterp *this, InputEvent *i_evt)
{
  ACCmdInterp *v2; // esi@1
  char result; // al@2
  unsigned int *v4; // eax@17

  v2 = this;
  if ( ((int (*)(void))this->vfptr[12].__vecDelDtor)() )
  {
    switch ( i_evt->m_InputAction )
    {
      case 0x32u:
        ((void (__thiscall *)(ACCmdInterp *, _DWORD))v2->vfptr[2].OnLoseFocus)(v2, i_evt->m_fStart);
        result = 1;
        break;
      case 0x30u:
        ACCmdInterp::SetMotion(v2, 0x90000C7u, 1);
        result = 1;
        break;
      case 0x29u:
        ACCmdInterp::SetMotion(v2, 0x45000005u, i_evt->m_fStart);
        result = 1;
        break;
      case 0x2Au:
        ACCmdInterp::SetMotion(v2, 0x45000006u, i_evt->m_fStart);
        result = 1;
        break;
      case 0x2Bu:
        ACCmdInterp::SetMotion(v2, 0x41000003u, 1);
        result = 1;
        break;
      case 0x2Eu:
        ACCmdInterp::SetMotion(v2, 0x6500000Du, i_evt->m_fStart);
        result = 1;
        break;
      case 0x2Fu:
        ACCmdInterp::SetMotion(v2, 0x6500000Eu, i_evt->m_fStart);
        result = 1;
        break;
      case 0x2Cu:
        ACCmdInterp::SetMotion(v2, 0x6500000Fu, i_evt->m_fStart);
        result = 1;
        break;
      case 0x2Du:
        ACCmdInterp::SetMotion(v2, 0x65000010u, i_evt->m_fStart);
        result = 1;
        break;
      case 0x31u:
        if ( i_evt->m_fStart )
        {
          ((void (__thiscall *)(ACCmdInterp *))v2->vfptr[5].OnAction)(v2);
          result = 1;
        }
        else
        {
          ((void (__thiscall *)(ACCmdInterp *, signed int))v2->vfptr[5].OnLoseFocus)(v2, 1);
          result = 1;
        }
        break;
      default:
        if ( HashSet<unsigned long>::contains(&v2->m_hashEmoteInputActionsToCommands, &i_evt->m_InputAction)
          && (v4 = HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
                     &v2->m_hashEmoteInputActionsToCommands,
                     &i_evt->m_InputAction)) != 0 )
        {
          ACCmdInterp::SetMotion(v2, *v4, 1);
          result = 1;
        }
        else
        {
          result = 0;
        }
        break;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0058B510) --------------------------------------------------------  // acclient.c:436033
void __thiscall ACCmdInterp::InitializeEmoteInputActionHash(ACCmdInterp *this)
{
  HashTable<unsigned long,RenderVertexStreamD3D *,0> *v1; // esi@1

  v1 = (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&this->m_hashEmoteInputActionsToCommands;
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&this->m_hashEmoteInputActionsToCommands,
    &Ready,
    &Motion_Ready);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Crouch, &Motion_Crouch);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Sitting, &Motion_Sitting);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Sleeping, &Motion_Sleeping);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    v1,
    &ShakeFistState,
    &Motion_ShakeFistState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &PrayState, &Motion_PrayState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &BowDeepState, &Motion_BowDeepState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    v1,
    &ClapHandsState,
    &Motion_ClapHandsState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    v1,
    &CrossArmsState,
    &Motion_CrossArmsState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &ShiverState, &Motion_ShiverState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &PointState, &Motion_PointState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &WaveState, &Motion_WaveState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &AkimboState, &Motion_AkimboState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &SaluteState, &Motion_SaluteState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    v1,
    &ScratchHeadState,
    &Motion_ScratchHeadState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &TapFootState, &Motion_TapFootState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &LeanState, &Motion_LeanState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &KneelState, &Motion_KneelState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &PleadState, &Motion_PleadState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &ATOYOT, &Motion_ATOYOT);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &SlouchState, &Motion_SlouchState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    v1,
    &SurrenderState,
    &Motion_SurrenderState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &WoahState, &Motion_WoahState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &WindedState, &Motion_WindedState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    v1,
    &SnowAngelState,
    &Motion_SnowAngelState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &CurtseyState, &Motion_CurtseyState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &AFKState, &Motion_AFKState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &MeditateState, &Motion_MeditateState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &SitState, &Motion_SitState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    v1,
    &SitCrossleggedState,
    &Motion_SitCrossleggedState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &SitBackState, &Motion_SitBackState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    v1,
    &PointLeftState,
    &Motion_PointLeftState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    v1,
    &PointRightState,
    &Motion_PointRightState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    v1,
    &TalktotheHandState,
    &Motion_TalktotheHandState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    v1,
    &PointDownState,
    &Motion_PointDownState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    v1,
    &DrudgeDanceState,
    &Motion_DrudgeDanceState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &PossumState, &Motion_PossumState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &ReadState, &Motion_ReadState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &ThinkerState, &Motion_ThinkerState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
    v1,
    &HaveASeatState,
    &Motion_HaveASeatState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &AtEaseState, &Motion_AtEaseState);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Cheer, &Motion_Cheer);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Cry, &Motion_Cry);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &ShakeFist, &Motion_ShakeFist);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Beckon, &Motion_Beckon);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &BeSeeingYou, &Motion_BeSeeingYou);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &BlowKiss, &Motion_BlowKiss);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &BowDeep, &Motion_BowDeep);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &ClapHands, &Motion_ClapHands);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Laugh, &Motion_Laugh);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &MimeEat, &Motion_MimeEat);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &MimeDrink, &Motion_MimeDrink);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Nod, &Motion_Nod);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Point, &Motion_Point);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &ShakeHead, &Motion_ShakeHead);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Shrug, &Motion_Shrug);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Wave, &Motion_Wave);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Akimbo, &Motion_Akimbo);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &HeartyLaugh, &Motion_HeartyLaugh);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Salute, &Motion_Salute);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &ScratchHead, &Motion_ScratchHead);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &SmackHead, &Motion_SmackHead);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &TapFoot, &Motion_TapFoot);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &WaveHigh, &Motion_WaveHigh);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &WaveLow, &Motion_WaveLow);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &YawnStretch, &Motion_YawnStretch);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Cringe, &Motion_Cringe);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Kneel, &Motion_Kneel);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Plead, &Motion_Plead);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Shiver, &Motion_Shiver);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Shoo, &Motion_Shoo);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Slouch, &Motion_Slouch);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Spit, &Motion_Spit);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Surrender, &Motion_Surrender);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Woah, &Motion_Woah);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Winded, &Motion_Winded);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &YMCA, &Motion_YMCA);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Pray, &Motion_Pray);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Mock, &Motion_Mock);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Teapot, &Motion_Teapot);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &WarmHands, &Motion_WarmHands);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &NudgeLeft, &Motion_NudgeLeft);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &NudgeRight, &Motion_NudgeRight);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &PointLeft, &Motion_PointLeft);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &PointRight, &Motion_PointRight);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &PointDown, &Motion_PointDown);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Knock, &Motion_Knock);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &ScanHorizon, &Motion_ScanHorizon);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &DrudgeDance, &Motion_DrudgeDance);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &HaveASeat, &Motion_HaveASeat);
  HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(v1, &Helper, &Motion_Helper);
}

//----- (0058BB30) --------------------------------------------------------  // acclient.c:436174
void __thiscall ACCmdInterp::ACCmdInterp(ACCmdInterp *this)
{
  ACCmdInterp *v1; // esi@1
  int v2; // edi@1
  GlobalEventHandler *v3; // eax@1

  v1 = this;
  CommandInterpreter::CommandInterpreter((CommandInterpreter *)&this->vfptr);
  v2 = (int)&v1->vfptr;
  *(_DWORD *)v2 = &ClientHousingSystem::vftable;
  v1->vfptr = (IInputActionCallbackVtbl *)&ACCmdInterp::vftable;
  *(_DWORD *)v2 = &ACCmdInterp::vftable;
  v1->m_hashEmoteInputActionsToCommands.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>(
    &v1->m_hashEmoteInputActionsToCommands.m_intrusiveTable,
    0x80u);
  ACCmdInterp::InitializeEmoteInputActionHash(v1);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v3,
      (unsigned int)((char *)&loc_4DD21E + 1),
      (NoticeHandler *)&v1->vfptr);
}
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7E3858: using guessed type bool (__thiscall *ACCmdInterp::vftable)(DBCache *this);
// 7E3B00: using guessed type int (__thiscall *ACCmdInterp::vftable)(void *, char);

//----- (0058BB90) --------------------------------------------------------  // acclient.c:436204
int __thiscall CommandInterpreter::IsEnabled(CommandInterpreter *this)
{
  return this->enabled;
}

//----- (0058BBA0) --------------------------------------------------------  // acclient.c:436210
void __thiscall CommandInterpreter::SetMouseLookActive(CommandInterpreter *this, int active)
{
  this->mouselook_active = active;
}

//----- (0058BBB0) --------------------------------------------------------  // acclient.c:436216
int __thiscall CommandInterpreter::GetMouseLookActive(CommandInterpreter *this)
{
  return this->mouselook_active;
}

//----- (0058BBC0) --------------------------------------------------------  // acclient.c:436222
void __thiscall CommandInterpreter::SetMouseLeftDown(CommandInterpreter *this, int active)
{
  this->mouseleft_down = active;
}

//----- (0058BBD0) --------------------------------------------------------  // acclient.c:436228
int __thiscall CommandInterpreter::GetMouseLeftDown(CommandInterpreter *this)
{
  return this->mouseleft_down;
}

//----- (0058BBE0) --------------------------------------------------------  // acclient.c:436234
void __thiscall ACCmdInterp::~ACCmdInterp(ACCmdInterp *this)
{
  ACCmdInterp *v1; // edi@1
  NoticeHandler *v2; // ebx@1
  GlobalEventHandler *v3; // eax@1
  void *v4; // eax@3

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&ACCmdInterp::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ACCmdInterp::vftable;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v1->m_hashEmoteInputActionsToCommands.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashEmoteInputActionsToCommands.m_intrusiveTable);
  v4 = v1->m_hashEmoteInputActionsToCommands.m_intrusiveTable.m_buckets;
  v1->m_hashEmoteInputActionsToCommands.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable;
  if ( v4 != v1->m_hashEmoteInputActionsToCommands.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v4);
  v1->m_hashEmoteInputActionsToCommands.m_intrusiveTable.m_buckets = 0;
  v1->m_hashEmoteInputActionsToCommands.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_hashEmoteInputActionsToCommands.m_intrusiveTable.m_numBuckets = 0;
  v1->m_hashEmoteInputActionsToCommands.m_intrusiveTable.m_numElements = 0;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  v1->last_sent_position.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (IInputActionCallbackVtbl *)&IInputActionCallback::vftable;
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(v1);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 79C9A8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable[3])(void *, char);
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7E3858: using guessed type bool (__thiscall *ACCmdInterp::vftable)(DBCache *this);
// 7E3B00: using guessed type int (__thiscall *ACCmdInterp::vftable)(void *, char);

//----- (0058BC80) --------------------------------------------------------  // acclient.c:436274
ACCmdInterp *__thiscall ACCmdInterp::vector_deleting_destructor(ACCmdInterp *this, unsigned int a2)
{
  ACCmdInterp *v2; // esi@1

  v2 = this;
  ACCmdInterp::~ACCmdInterp(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0070A640) --------------------------------------------------------  // acclient.c:797585
void sub_70A640()
{
  flt_870DD4 = 1000.0 + 1.0;
}

//----- (0070A660) --------------------------------------------------------  // acclient.c:797591
void sub_70A660()
{
  flt_870DD8 = 24.0 * 8.0;
}

//----- (0070A680) --------------------------------------------------------  // acclient.c:797597
void sub_70A680()
{
  flt_870DDC = 24.0 * 0.5;
}

//----- (0070A6A0) --------------------------------------------------------  // acclient.c:797603
int sub_70A6A0()
{
  return atexit(nullsub_1407);
}

//----- (0070A6B0) --------------------------------------------------------  // acclient.c:797609
int sub_70A6B0()
{
  return atexit(nullsub_1408);
}

//----- (0070A6C0) --------------------------------------------------------  // acclient.c:797615
int sub_70A6C0()
{
  return atexit(nullsub_1409);
}

//----- (0070A6D0) --------------------------------------------------------  // acclient.c:797621
void sub_70A6D0()
{
  dword_870DE4 = 1024;
}

//----- (0070A6E0) --------------------------------------------------------  // acclient.c:797627
void _E108_97()
{
  dword_870DE8 = 0x7FFF;
}

//----- (0070A6F0) --------------------------------------------------------  // acclient.c:797633
int _E110_80()
{
  const int result; // eax@1

  result = dword_870DE4;
  dword_870DEC = dword_870DE4;
  return result;
}

//----- (0070A700) --------------------------------------------------------  // acclient.c:797643
void sub_70A700()
{
  flt_870DF0 = 0.00019999999 * 3.0 + 0.1;
}

//----- (0070A720) --------------------------------------------------------  // acclient.c:797649
void _E114_62()
{
  dbl_870DF8 = 1.0 / 30.0;
}

//----- (0070A740) --------------------------------------------------------  // acclient.c:797655
void _E116_25()
{
  dbl_870E00 = 1.0 / 5.0;
}

//----- (0070A760) --------------------------------------------------------  // acclient.c:797661
void _E118_78()
{
  PixelFormatDesc::PixelFormatDesc(&stru_870E08, PFID_A8R8G8B8);
}

//----- (0070A770) --------------------------------------------------------  // acclient.c:797667
int _E120_71()
{
  return atexit(nullsub_1405);
}

//----- (0070A780) --------------------------------------------------------  // acclient.c:797673
int sub_70A780()
{
  return atexit(nullsub_1406);
}

