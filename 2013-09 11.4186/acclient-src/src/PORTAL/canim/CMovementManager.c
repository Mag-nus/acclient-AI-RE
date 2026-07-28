/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CMovementManager
   Object     : PORTAL\canim\CMovementManager.obj
   Functions  : 31
   Addresses  : 00524000 - 006FD760 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00524000) --------------------------------------------------------  // acclient.c:339100
void __thiscall MovementManager::MakeMoveToManager(MovementManager *this)
{
  MovementManager *v1; // esi@1
  MoveToManager *v2; // eax@2

  v1 = this;
  if ( !this->moveto_manager )
  {
    MoveToManager::Create(this->physics_obj, this->weenie_obj);
    v1->moveto_manager = v2;
  }
}

//----- (00524020) --------------------------------------------------------  // acclient.c:339114
void __thiscall MovementManager::SetWeenieObject(MovementManager *this, CWeenieObject *_weenie_obj)
{
  MovementManager *v2; // esi@1
  CMotionInterp *v3; // ecx@1
  MoveToManager *v4; // ecx@3

  v2 = this;
  v3 = this->motion_interpreter;
  v2->weenie_obj = _weenie_obj;
  if ( v3 )
    CMotionInterp::SetWeenieObject(v3, _weenie_obj);
  v4 = v2->moveto_manager;
  if ( v4 )
    MoveToManager::SetWeenieObject(v4, _weenie_obj);
}

//----- (00524050) --------------------------------------------------------  // acclient.c:339131
MovementManager *__cdecl MovementManager::Create(CPhysicsObj *_physics_obj, CWeenieObject *_weenie_obj)
{
  void *v2; // eax@1
  void *v3; // esi@2
  CMotionInterp *v4; // ecx@4
  bool v5; // zf@4
  MoveToManager *v6; // ecx@6
  CMotionInterp *v7; // ecx@8
  MoveToManager *v8; // ecx@10

  v2 = operator new(0x10u);
  if ( v2 )
  {
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 2) = 0;
    *((_DWORD *)v2 + 3) = 0;
    v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  v4 = *(CMotionInterp **)v3;
  v5 = *(_DWORD *)v3 == 0;
  *((_DWORD *)v3 + 2) = _physics_obj;
  if ( !v5 )
    CMotionInterp::SetPhysicsObject(v4, _physics_obj);
  v6 = (MoveToManager *)*((_DWORD *)v3 + 1);
  if ( v6 )
    MoveToManager::SetPhysicsObject(v6, _physics_obj);
  v7 = *(CMotionInterp **)v3;
  v5 = *(_DWORD *)v3 == 0;
  *((_DWORD *)v3 + 3) = _weenie_obj;
  if ( !v5 )
    CMotionInterp::SetWeenieObject(v7, _weenie_obj);
  v8 = (MoveToManager *)*((_DWORD *)v3 + 1);
  if ( v8 )
    MoveToManager::SetWeenieObject(v8, _weenie_obj);
  return (MovementManager *)v3;
}

//----- (005240D0) --------------------------------------------------------  // acclient.c:339174
signed int __thiscall MovementManager::PerformMovement(MovementManager *this, MovementStruct *movement_struct)
{
  MovementManager *v2; // esi@1
  CMotionInterp *v3; // eax@3
  CPhysicsObj *v4; // ecx@3
  signed int result; // eax@5
  MoveToManager *v6; // eax@7

  v2 = this;
  CPhysicsObj::set_active(this->physics_obj, 1);
  switch ( movement_struct->type )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      if ( !v2->motion_interpreter )
      {
        v3 = CMotionInterp::Create(v2->physics_obj, v2->weenie_obj);
        v4 = v2->physics_obj;
        v2->motion_interpreter = v3;
        if ( v4 )
          CMotionInterp::enter_default_state(v3);
      }
      result = CMotionInterp::PerformMovement(v2->motion_interpreter, movement_struct);
      break;
    case 6:
    case 7:
    case 8:
    case 9:
      if ( !v2->moveto_manager )
      {
        MoveToManager::Create(v2->physics_obj, v2->weenie_obj);
        v2->moveto_manager = v6;
      }
      result = MoveToManager::PerformMovement(v2->moveto_manager, movement_struct);
      break;
    default:
      result = 71;
      break;
  }
  return result;
}

//----- (00524170) --------------------------------------------------------  // acclient.c:339220
void __thiscall MovementManager::move_to_interpreted_state(MovementManager *this, InterpretedMotionState *state)
{
  MovementManager *v2; // esi@1
  CMotionInterp *v3; // eax@2
  CPhysicsObj *v4; // ecx@2

  v2 = this;
  if ( !this->motion_interpreter )
  {
    v3 = CMotionInterp::Create(this->physics_obj, this->weenie_obj);
    v4 = v2->physics_obj;
    v2->motion_interpreter = v3;
    if ( v4 )
      CMotionInterp::enter_default_state(v3);
  }
  CMotionInterp::move_to_interpreted_state(v2->motion_interpreter, state);
}

//----- (005241B0) --------------------------------------------------------  // acclient.c:339239
void __thiscall MovementManager::CancelMoveTo(MovementManager *this, unsigned int err)
{
  MoveToManager *v2; // ecx@1

  v2 = this->moveto_manager;
  if ( v2 )
    MoveToManager::CancelMoveTo(v2, err);
}

//----- (005241C0) --------------------------------------------------------  // acclient.c:339249
void __thiscall MovementManager::EnterDefaultState(MovementManager *this)
{
  MovementManager *v1; // esi@1
  CPhysicsObj *v2; // eax@1
  CMotionInterp *v3; // eax@3
  CPhysicsObj *v4; // ecx@3

  v1 = this;
  v2 = this->physics_obj;
  if ( v2 )
  {
    if ( !this->motion_interpreter )
    {
      v3 = CMotionInterp::Create(v2, this->weenie_obj);
      v4 = v1->physics_obj;
      v1->motion_interpreter = v3;
      if ( v4 )
        CMotionInterp::enter_default_state(v3);
    }
    CMotionInterp::enter_default_state(v1->motion_interpreter);
  }
}

//----- (00524200) --------------------------------------------------------  // acclient.c:339273
int __thiscall MovementManager::InqRawMotionState(MovementManager *this)
{
  MovementManager *v1; // esi@1
  CMotionInterp *v2; // eax@2
  CPhysicsObj *v3; // ecx@2

  v1 = this;
  if ( !this->motion_interpreter )
  {
    v2 = CMotionInterp::Create(this->physics_obj, this->weenie_obj);
    v3 = v1->physics_obj;
    v1->motion_interpreter = v2;
    if ( v3 )
      CMotionInterp::enter_default_state(v2);
  }
  return (int)&v1->motion_interpreter->raw_state;
}

//----- (00524230) --------------------------------------------------------  // acclient.c:339292
int __thiscall MovementManager::InqInterpretedMotionState(MovementManager *this)
{
  MovementManager *v1; // esi@1
  CMotionInterp *v2; // eax@2
  CPhysicsObj *v3; // ecx@2

  v1 = this;
  if ( !this->motion_interpreter )
  {
    v2 = CMotionInterp::Create(this->physics_obj, this->weenie_obj);
    v3 = v1->physics_obj;
    v1->motion_interpreter = v2;
    if ( v3 )
      CMotionInterp::enter_default_state(v2);
  }
  return (int)&v1->motion_interpreter->interpreted_state;
}

//----- (00524260) --------------------------------------------------------  // acclient.c:339311
BOOL __thiscall MovementManager::IsMovingTo(MovementManager *this)
{
  MoveToManager *v1; // ecx@1

  v1 = this->moveto_manager;
  return v1 && MoveToManager::is_moving_to(v1);
}

//----- (00524280) --------------------------------------------------------  // acclient.c:339320
BOOL __thiscall MovementManager::motions_pending(MovementManager *this)
{
  CMotionInterp *v1; // ecx@1

  v1 = this->motion_interpreter;
  return v1 && CMotionInterp::motions_pending(v1);
}

//----- (005242A0) --------------------------------------------------------  // acclient.c:339329
CMotionInterp *__thiscall MovementManager::get_minterp(MovementManager *this)
{
  MovementManager *v1; // esi@1
  CMotionInterp *v2; // eax@2
  CPhysicsObj *v3; // ecx@2

  v1 = this;
  if ( !this->motion_interpreter )
  {
    v2 = CMotionInterp::Create(this->physics_obj, this->weenie_obj);
    v3 = v1->physics_obj;
    v1->motion_interpreter = v2;
    if ( v3 )
      CMotionInterp::enter_default_state(v2);
  }
  return v1->motion_interpreter;
}

//----- (005242D0) --------------------------------------------------------  // acclient.c:339348
void __thiscall MovementManager::MotionDone(MovementManager *this, unsigned int motion, int success)
{
  CMotionInterp *v3; // ecx@1

  v3 = this->motion_interpreter;
  if ( v3 )
    CMotionInterp::MotionDone(v3, success);
}

//----- (005242F0) --------------------------------------------------------  // acclient.c:339358
void __thiscall MovementManager::UseTime(MovementManager *this)
{
  MoveToManager *v1; // ecx@1

  v1 = this->moveto_manager;
  if ( v1 )
    MoveToManager::UseTime(v1);
}

//----- (00524300) --------------------------------------------------------  // acclient.c:339368
void __thiscall MovementManager::HitGround(MovementManager *this)
{
  MovementManager *v1; // esi@1
  CMotionInterp *v2; // ecx@1
  MoveToManager *v3; // ecx@3

  v1 = this;
  v2 = this->motion_interpreter;
  if ( v2 )
    CMotionInterp::HitGround(v2);
  v3 = v1->moveto_manager;
  if ( v3 )
    MoveToManager::HitGround(v3);
}

//----- (00524320) --------------------------------------------------------  // acclient.c:339384
void __thiscall MovementManager::LeaveGround(MovementManager *this)
{
  MovementManager *v1; // esi@1
  CMotionInterp *v2; // ecx@1
  DiskSpace *v3; // ecx@3

  v1 = this;
  v2 = this->motion_interpreter;
  if ( v2 )
    CMotionInterp::LeaveGround(v2);
  v3 = (DiskSpace *)v1->moveto_manager;
  if ( v3 )
    gmNoticeHandler::RecvNotice_PrevSpellSelection(v3);
}

//----- (00524340) --------------------------------------------------------  // acclient.c:339400
void __thiscall MovementManager::HandleEnterWorld(MovementManager *this)
{
  CMotionInterp *v1; // ecx@1

  v1 = this->motion_interpreter;
  if ( v1 )
    gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)v1);
}

//----- (00524350) --------------------------------------------------------  // acclient.c:339410
void __thiscall MovementManager::HandleExitWorld(MovementManager *this)
{
  CMotionInterp *v1; // ecx@1

  v1 = this->motion_interpreter;
  if ( v1 )
    CMotionInterp::HandleExitWorld(v1);
}

//----- (00524360) --------------------------------------------------------  // acclient.c:339420
void __thiscall MovementManager::ReportExhaustion(MovementManager *this)
{
  MovementManager *v1; // esi@1
  CMotionInterp *v2; // ecx@1
  DiskSpace *v3; // ecx@3

  v1 = this;
  v2 = this->motion_interpreter;
  if ( v2 )
    CMotionInterp::ReportExhaustion(v2);
  v3 = (DiskSpace *)v1->moveto_manager;
  if ( v3 )
    gmNoticeHandler::RecvNotice_PrevSpellSelection(v3);
}

//----- (00524380) --------------------------------------------------------  // acclient.c:339436
void __thiscall MovementParameters::MovementParameters(MovementParameters *this)
{
  MovementParameters *v1; // eax@1
  unsigned int v2; // ecx@3

  v1 = this;
  LODWORD(this->min_distance) = 0;
  LODWORD(this->distance_to_object) = 1058642330;
  LODWORD(this->fail_distance) = 2139095039;
  this->vfptr = (PackObjVtbl *)&MovementParameters::vftable;
  LODWORD(this->desired_heading) = 0;
  LODWORD(this->speed) = 1065353216;
  LODWORD(this->walk_run_threshhold) = 1097859072;
  this->context_id = 0;
  this->hold_key_to_apply = 0;
  this->action_stamp = 0;
  if ( MovementParameters::set_moveto_flags::_2::normal_bitfield )
  {
    this->bitfield = MovementParameters::set_moveto_flags::_2::normal_bitfield;
  }
  else
  {
    v2 = this->bitfield & 0xFFFDEE0F | 0x1EE0F;
    v1->bitfield = v2;
    MovementParameters::set_moveto_flags::_2::normal_bitfield = v2;
  }
}
// 7C83F8: using guessed type int (__thiscall *MovementParameters::vftable)(void *, char);
// 8444E8: using guessed type int MovementParameters::set_moveto_flags::_2::normal_bitfield;

//----- (005243F0) --------------------------------------------------------  // acclient.c:339467
void __thiscall MovementManager::Destroy(MovementManager *this)
{
  MovementManager *v1; // esi@1
  CMotionInterp *v2; // edi@1
  MoveToManager *v3; // edi@3

  v1 = this;
  v2 = this->motion_interpreter;
  if ( this->motion_interpreter )
  {
    CMotionInterp::~CMotionInterp(this->motion_interpreter);
    operator delete(v2);
  }
  v3 = v1->moveto_manager;
  v1->motion_interpreter = 0;
  if ( v3 )
  {
    MoveToManager::~MoveToManager(v3);
    operator delete(v3);
  }
  v1->moveto_manager = 0;
}

//----- (00524440) --------------------------------------------------------  // acclient.c:339491
int __thiscall MovementManager::unpack_movement(MovementManager *this, void **addr, unsigned int size)
{
  MovementManager *v3; // edi@1
  CPhysicsObj *v4; // ecx@2
  __int16 v5; // cx@3
  char *v6; // eax@3
  __int16 v7; // bp@3
  unsigned __int16 v8; // cx@3
  unsigned int v9; // ebx@7
  int v10; // ebp@9
  int result; // eax@11
  unsigned int v12; // ebx@12
  double v13; // st7@12
  double v14; // st7@14
  unsigned int v15; // ebx@16
  char *v16; // eax@16
  float pack_word; // [sp+10h] [bp-A4h]@16
  char pack_word_1; // [sp+11h] [bp-A3h]@3
  const unsigned int style; // [sp+14h] [bp-A0h]@3
  MovementParameters params; // [sp+18h] [bp-9Ch]@3
  Position pos; // [sp+44h] [bp-70h]@3
  InterpretedMotionState state; // [sp+8Ch] [bp-28h]@3

  v3 = this;
  if ( this->motion_interpreter && (v4 = this->physics_obj) != 0 )
  {
    CPhysicsObj::cancel_moveto(v4);
    CPhysicsObj::unstick_from_object(v3->physics_obj);
    pos.vfptr = (PackObjVtbl *)&Position::vftable;
    pos.objcell_id = 0;
    LODWORD(pos.frame.qw) = 1065353216;
    LODWORD(pos.frame.qx) = 0;
    LODWORD(pos.frame.qy) = 0;
    LODWORD(pos.frame.qz) = 0;
    LODWORD(pos.frame.m_fOrigin.x) = 0;
    LODWORD(pos.frame.m_fOrigin.y) = 0;
    LODWORD(pos.frame.m_fOrigin.z) = 0;
    Frame::cache(&pos.frame);
    MovementParameters::MovementParameters(&params);
    InterpretedMotionState::InterpretedMotionState(&state);
    v5 = *(_WORD *)*addr;
    v6 = (char *)*addr + 2;
    *addr = v6;
    v7 = v5;
    v6 += 2;
    pack_word_1 = HIBYTE(v5);
    v8 = *((_WORD *)v6 - 1);
    *addr = v6;
    style = command_ids_0[v8];
    if ( CMotionInterp::InqStyle(v3->motion_interpreter) != style )
      CMotionInterp::DoMotion(v3->motion_interpreter, style, &params);
    switch ( (unsigned __int8)v7 )
    {
      case 0u:
        InterpretedMotionState::UnPack(&state, addr, size);
        if ( pack_word_1 & 1 )
        {
          v9 = *(_DWORD *)*addr;
          *addr = (char *)*addr + 4;
        }
        else
        {
          v9 = 0;
        }
        v10 = v7 & 0x200;
        MovementManager::move_to_interpreted_state(v3, &state);
        if ( v9 )
          CPhysicsObj::stick_to_object(v3->physics_obj, v9);
        v3->motion_interpreter->standing_longjump = v10;
        InterpretedMotionState::~InterpretedMotionState(&state);
        return 1;
      case 6u:
        MovementManager::MakeMoveToManager(v3);
        v12 = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
        Position::UnPackOrigin(&pos, addr, size);
        MovementParameters::UnPackNet(&params, MoveToObject, addr, size);
        v13 = *(float *)*addr;
        *addr = (char *)*addr + 4;
        v3->motion_interpreter->my_run_rate = v13;
        if ( !CPhysicsObj::GetObjectA(v12) )
          goto LABEL_15;
        CPhysicsObj::MoveToObject(v3->physics_obj, v12, &params);
        InterpretedMotionState::~InterpretedMotionState(&state);
        return 1;
      case 7u:
        MovementManager::MakeMoveToManager(v3);
        Position::UnPackOrigin(&pos, addr, size);
        MovementParameters::UnPackNet(&params, MoveToPosition, addr, size);
        v14 = *(float *)*addr;
        *addr = (char *)*addr + 4;
        v3->motion_interpreter->my_run_rate = v14;
LABEL_15:
        MoveToManager::MoveToPosition(v3->moveto_manager, &pos, &params);
        InterpretedMotionState::~InterpretedMotionState(&state);
        return 1;
      case 8u:
        MovementManager::MakeMoveToManager(v3);
        v15 = *(_DWORD *)*addr;
        v16 = (char *)*addr + 4;
        *addr = v16;
        pack_word = *(float *)v16;
        *addr = v16 + 4;
        MovementParameters::UnPackNet(&params, TurnToObject, addr, size);
        if ( CPhysicsObj::GetObjectA(v15) )
        {
          CPhysicsObj::TurnToObject(v3->physics_obj, v15, &params);
          InterpretedMotionState::~InterpretedMotionState(&state);
          result = 1;
        }
        else
        {
          params.desired_heading = pack_word;
          MoveToManager::TurnToHeading(v3->moveto_manager, &params);
LABEL_20:
          InterpretedMotionState::~InterpretedMotionState(&state);
          result = 1;
        }
        break;
      case 9u:
        MovementManager::MakeMoveToManager(v3);
        MovementParameters::UnPackNet(&params, TurnToHeading, addr, size);
        MoveToManager::TurnToHeading(v3->moveto_manager, &params);
        goto LABEL_20;
      default:
        InterpretedMotionState::~InterpretedMotionState(&state);
        goto LABEL_22;
    }
  }
  else
  {
LABEL_22:
    result = 0;
  }
  return result;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00524790) --------------------------------------------------------  // acclient.c:339630
void __thiscall MovementManager::HandleUpdateTarget(MovementManager *this, TargetInfo target_info)
{
  MoveToManager *v2; // ecx@1

  v2 = this->moveto_manager;
  if ( v2 )
    MoveToManager::HandleUpdateTarget(v2, &target_info);
}

//----- (006FD690) --------------------------------------------------------  // acclient.c:785686
void sub_6FD690()
{
  flt_84450C = 1000.0 + 1.0;
}

//----- (006FD6B0) --------------------------------------------------------  // acclient.c:785692
void sub_6FD6B0()
{
  flt_844510 = 24.0 * 8.0;
}

//----- (006FD6D0) --------------------------------------------------------  // acclient.c:785698
void sub_6FD6D0()
{
  flt_844514 = 24.0 * 0.5;
}

//----- (006FD6F0) --------------------------------------------------------  // acclient.c:785704
int _E101_20()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_11;
  INITIAL_MAX_DATA_RATE_80 = LOWEST_DATA_RATE_11;
  return result;
}

//----- (006FD700) --------------------------------------------------------  // acclient.c:785714
void sub_6FD700()
{
  flt_844520 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FD720) --------------------------------------------------------  // acclient.c:785720
void _E105_26()
{
  dbl_844528 = 1.0 / 30.0;
}

//----- (006FD740) --------------------------------------------------------  // acclient.c:785726
void _E107_20()
{
  dbl_844530 = 1.0 / 5.0;
}

//----- (006FD760) --------------------------------------------------------  // acclient.c:785732
int sub_6FD760()
{
  return atexit(nullsub_1140);
}

