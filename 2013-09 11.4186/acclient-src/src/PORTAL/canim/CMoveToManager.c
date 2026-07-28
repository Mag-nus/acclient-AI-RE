/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CMoveToManager
   Object     : PORTAL\canim\CMoveToManager.obj
   Functions  : 43
   Addresses  : 00528F60 - 006FDCA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00528F60) --------------------------------------------------------  // acclient.c:344714
int __cdecl heading_greater(float x, float y, unsigned int motion)
{
  bool v3; // c0@2
  bool v4; // c3@2
  int result; // eax@4

  if ( fabs(x - y) <= 180.0 )
  {
    v3 = x < (double)y;
    v4 = x == y;
  }
  else
  {
    v3 = y < (double)x;
    v4 = y == x;
  }
  result = (v3 || v4) == 0;
  if ( motion != 1694498829 )
    result = (v3 || v4) != 0;
  return result;
}

//----- (00528FB0) --------------------------------------------------------  // acclient.c:344737
double __cdecl heading_diff(float x, float y, unsigned int motion)
{
  double result; // st7@1

  result = x - y;
  if ( fabs(result) < 0.00019999999 )
    result = 0.0;
  if ( result < -0.00019999999 )
    result = result + 360.0;
  if ( result > 0.00019999999 && motion != 1694498829 )
    result = 360.0 - result;
  return result;
}

//----- (00529010) --------------------------------------------------------  // acclient.c:344752
signed int __thiscall MoveToManager::_DoMotion(MoveToManager *this, unsigned int motion, MovementParameters *params)
{
  MoveToManager *v3; // esi@1
  CPhysicsObj *v4; // ecx@1
  signed int result; // eax@2
  MovementParameters *v6; // edi@5
  HoldKey v7; // ST08_4@5
  float *v8; // ST04_4@5
  CMotionInterp *v9; // eax@5
  unsigned int v10; // ST04_4@5
  CMotionInterp *v11; // eax@5

  v3 = this;
  v4 = this->physics_obj;
  if ( v4 )
  {
    if ( CPhysicsObj::get_minterp(v4) )
    {
      v6 = params;
      v7 = params->hold_key_to_apply;
      v8 = &params->speed;
      v9 = CPhysicsObj::get_minterp(v3->physics_obj);
      CMotionInterp::adjust_motion(v9, &motion, v8, v7);
      v10 = motion;
      v11 = CPhysicsObj::get_minterp(v3->physics_obj);
      result = CMotionInterp::DoInterpretedMotion(v11, v10, v6);
    }
    else
    {
      result = 11;
    }
  }
  else
  {
    result = 8;
  }
  return result;
}

//----- (00529080) --------------------------------------------------------  // acclient.c:344792
signed int __thiscall MoveToManager::_StopMotion(MoveToManager *this, unsigned int motion, MovementParameters *params)
{
  MoveToManager *v3; // esi@1
  CPhysicsObj *v4; // ecx@1
  signed int result; // eax@2
  MovementParameters *v6; // edi@5
  HoldKey v7; // ST08_4@5
  float *v8; // ST04_4@5
  CMotionInterp *v9; // eax@5
  unsigned int v10; // ST04_4@5
  CMotionInterp *v11; // eax@5

  v3 = this;
  v4 = this->physics_obj;
  if ( v4 )
  {
    if ( CPhysicsObj::get_minterp(v4) )
    {
      v6 = params;
      v7 = params->hold_key_to_apply;
      v8 = &params->speed;
      v9 = CPhysicsObj::get_minterp(v3->physics_obj);
      CMotionInterp::adjust_motion(v9, &motion, v8, v7);
      v10 = motion;
      v11 = CPhysicsObj::get_minterp(v3->physics_obj);
      result = CMotionInterp::StopInterpretedMotion(v11, v10, v6);
    }
    else
    {
      result = 11;
    }
  }
  else
  {
    result = 8;
  }
  return result;
}

//----- (005290F0) --------------------------------------------------------  // acclient.c:344832
int __thiscall MoveToManager::CheckProgressMade(MoveToManager *this, float curr_distance)
{
  long double v2; // st7@1
  int v3; // edx@2
  double v4; // st6@3
  double v5; // st6@7
  int result; // eax@10

  v2 = COERCE_DOUBLE(Timer::cur_time.Cmd) - this->previous_distance_time;
  result = 1;
  if ( v2 > 1.0 )
  {
    v3 = this->moving_away;
    v4 = v3 ? curr_distance - this->previous_distance : this->previous_distance - curr_distance;
    if ( v4 / v2 < 0.25
      || ((this->previous_distance = curr_distance, *(_QWORD *)&this->previous_distance_time = Timer::cur_time, !v3) ? (v5 = this->original_distance - curr_distance) : (v5 = curr_distance - this->original_distance),
          v5 / (COERCE_DOUBLE(Timer::cur_time.Cmd) - this->original_distance_time) < 0.25) )
      result = 0;
  }
  return result;
}

//----- (005291B0) --------------------------------------------------------  // acclient.c:344855
double __thiscall MoveToManager::GetCurrentDistance(MoveToManager *this)
{
  MoveToManager *v1; // esi@1
  CPhysicsObj *v2; // ecx@1
  double result; // st7@2
  unsigned int v4; // eax@3
  float v5; // ST10_4@4
  float v6; // ST0C_4@4
  Position *v7; // ST08_4@4
  float h1; // ST04_4@4
  float r1; // ST00_4@4

  v1 = this;
  v2 = this->physics_obj;
  if ( v2 )
  {
    v4 = v1->movement_params.bitfield;
    if ( BYTE1(v4) & 4 )
    {
      v5 = v1->sought_object_height;
      v6 = v1->sought_object_radius;
      v7 = &v2->m_position;
      h1 = CPhysicsObj::GetHeight(v2);
      r1 = CPhysicsObj::GetRadius(v1->physics_obj);
      result = Position::cylinder_distance(r1, h1, v7, v6, v5, &v1->current_target_position);
    }
    else
    {
      result = Position::distance(&v2->m_position, &v1->current_target_position);
    }
  }
  else
  {
    result = 3.4028235e38;
  }
  return result;
}

//----- (00529220) --------------------------------------------------------  // acclient.c:344894
BOOL __thiscall MoveToManager::is_moving_to(MoveToManager *this)
{
  return this->movement_type != 0;
}

//----- (00529230) --------------------------------------------------------  // acclient.c:344900
void __thiscall MoveToManager::SetWeenieObject(MoveToManager *this, CWeenieObject *wobj)
{
  this->weenie_obj = wobj;
}

//----- (00529240) --------------------------------------------------------  // acclient.c:344906
void __thiscall MoveToManager::SetPhysicsObject(MoveToManager *this, CPhysicsObj *pobj)
{
  this->physics_obj = pobj;
}

//----- (00529250) --------------------------------------------------------  // acclient.c:344912
void __thiscall MoveToManager::InitializeLocalVariables(MoveToManager *this)
{
  MoveToManager *v1; // esi@1
  unsigned int v2; // edx@1
  Frame v3; // [sp+10h] [bp-40h]@1

  v1 = this;
  this->movement_type = 0;
  this->movement_params.bitfield = 0;
  this->movement_params.context_id = 0;
  LODWORD(this->previous_distance) = 2139095039;
  v2 = Timer::cur_time.Param;
  LODWORD(this->previous_distance_time) = Timer::cur_time.Cmd;
  HIDWORD(this->previous_distance_time) = v2;
  LODWORD(this->original_distance) = 2139095039;
  *(_QWORD *)&this->original_distance_time = Timer::cur_time;
  LODWORD(this->previous_heading) = 0;
  this->fail_progress_count = 0;
  this->current_command = 0;
  this->aux_command = 0;
  this->moving_away = 0;
  this->initialized = 0;
  LODWORD(v3.qw) = 1065353216;
  LODWORD(v3.qx) = 0;
  LODWORD(v3.qy) = 0;
  LODWORD(v3.qz) = 0;
  LODWORD(v3.m_fOrigin.x) = 0;
  LODWORD(v3.m_fOrigin.y) = 0;
  LODWORD(v3.m_fOrigin.z) = 0;
  Frame::cache(&v3);
  v1->sought_position.objcell_id = 0;
  Frame::operator=((int)&v1->sought_position.frame, (int)&v3);
  LODWORD(v3.qw) = 1065353216;
  LODWORD(v3.qx) = 0;
  LODWORD(v3.qy) = 0;
  LODWORD(v3.qz) = 0;
  LODWORD(v3.m_fOrigin.x) = 0;
  LODWORD(v3.m_fOrigin.y) = 0;
  LODWORD(v3.m_fOrigin.z) = 0;
  Frame::cache(&v3);
  v1->current_target_position.objcell_id = 0;
  Frame::operator=((int)&v1->current_target_position.frame, (int)&v3);
  v1->sought_object_id = 0;
  v1->top_level_object_id = 0;
  LODWORD(v1->sought_object_radius) = 0;
  LODWORD(v1->sought_object_height) = 0;
}

//----- (00529380) --------------------------------------------------------  // acclient.c:344961
void __thiscall MoveToManager::RemovePendingActionsHead(MoveToManager *this)
{
  DLListBase *v1; // ecx@1
  void *v2; // esi@1

  v1 = (DLListBase *)&this->pending_actions.head_;
  v2 = v1->head_;
  if ( v1->head_ )
  {
    DLListBase::Remove(v1, v1->head_);
    if ( v2 )
      operator delete(v2);
  }
}

//----- (005293B0) --------------------------------------------------------  // acclient.c:344977
void __thiscall MoveToManager::MoveToManager(MoveToManager *this)
{
  MoveToManager *v1; // esi@1
  char *v2; // ecx@1
  int v3; // ecx@1
  int v4; // ecx@1

  v1 = this;
  v2 = (char *)&this->sought_position.frame;
  v1->sought_position.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->sought_position.objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  v3 = (int)&v1->current_target_position.frame;
  v1->current_target_position.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->current_target_position.objcell_id = 0;
  *(_DWORD *)v3 = 1065353216;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 0;
  *(_DWORD *)(v3 + 52) = 0;
  *(_DWORD *)(v3 + 56) = 0;
  *(_DWORD *)(v3 + 60) = 0;
  Frame::cache(&v1->current_target_position.frame);
  v4 = (int)&v1->starting_position.frame;
  v1->starting_position.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->starting_position.objcell_id = 0;
  *(_DWORD *)v4 = 1065353216;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = 0;
  *(_DWORD *)(v4 + 52) = 0;
  *(_DWORD *)(v4 + 56) = 0;
  *(_DWORD *)(v4 + 60) = 0;
  Frame::cache(&v1->starting_position.frame);
  MovementParameters::MovementParameters(&v1->movement_params);
  v1->pending_actions.head_ = 0;
  v1->pending_actions.tail_ = 0;
  v1->physics_obj = 0;
  v1->weenie_obj = 0;
  MoveToManager::InitializeLocalVariables(v1);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00529470) --------------------------------------------------------  // acclient.c:345028
void __cdecl MoveToManager::Create(CPhysicsObj *physics_obj, CWeenieObject *weenie_obj)
{
  MoveToManager *v2; // eax@1
  int v3; // eax@2

  v2 = (MoveToManager *)operator new(0x160u);
  if ( v2 )
  {
    MoveToManager::MoveToManager(v2);
    if ( v3 )
    {
      *(_DWORD *)(v3 + 340) = physics_obj;
      *(_DWORD *)(v3 + 344) = weenie_obj;
    }
  }
}

//----- (005294B0) --------------------------------------------------------  // acclient.c:345046
void __thiscall MoveToManager::Destroy(MoveToManager *this)
{
  MoveToManager *v1; // esi@1
  void *v2; // eax@2
  int v3; // ecx@3
  int v4; // ecx@5
  bool v5; // zf@5
  DLListData *v6; // ecx@9

  v1 = this;
  while ( v1->pending_actions.head_ )
  {
    v2 = v1->pending_actions.head_;
    if ( v2 )
    {
      v3 = *((_DWORD *)v2 + 1);
      if ( v3 )
      {
        *(_DWORD *)v3 = *(_DWORD *)v2;
      }
      else
      {
        v4 = *(_DWORD *)v2;
        v5 = *(_DWORD *)v2 == 0;
        v1->pending_actions.head_ = *(DLListData **)v2;
        if ( !v5 )
          *(_DWORD *)(v4 + 4) = 0;
      }
      if ( *(_DWORD *)v2 )
      {
        *(_DWORD *)(*(_DWORD *)v2 + 4) = *((_DWORD *)v2 + 1);
      }
      else
      {
        v6 = v1->pending_actions.tail_->dllist_prev;
        v1->pending_actions.tail_ = v6;
        if ( v6 )
          v6->dllist_next = 0;
      }
      *(_DWORD *)v2 = 0;
      *((_DWORD *)v2 + 1) = 0;
      if ( v2 )
        operator delete(v2);
    }
  }
  MoveToManager::InitializeLocalVariables(v1);
}

//----- (00529530) --------------------------------------------------------  // acclient.c:345095
void __thiscall MoveToManager::AddTurnToHeadingNode(MoveToManager *this, float global_heading)
{
  MoveToManager *v2; // esi@1
  void *v3; // eax@1

  v2 = this;
  v3 = operator new(0x10u);
  if ( v3 )
  {
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
    *((_DWORD *)v3 + 3) = 0;
  }
  else
  {
    v3 = 0;
  }
  *((float *)v3 + 3) = global_heading;
  *((_DWORD *)v3 + 2) = 9;
  DLListBase::InsertAfter((DLListBase *)&v2->pending_actions.head_, (DLListData *)v3, v2->pending_actions.tail_);
}

//----- (00529580) --------------------------------------------------------  // acclient.c:345119
void __thiscall MoveToManager::AddMoveToPositionNode(MoveToManager *this)
{
  MoveToManager *v1; // esi@1
  void *v2; // eax@1

  v1 = this;
  v2 = operator new(0x10u);
  if ( v2 )
  {
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 2) = 0;
    *((_DWORD *)v2 + 3) = 0;
  }
  else
  {
    v2 = 0;
  }
  *((_DWORD *)v2 + 2) = 7;
  DLListBase::InsertAfter((DLListBase *)&v1->pending_actions.head_, (DLListData *)v2, v1->pending_actions.tail_);
}

//----- (005295C0) --------------------------------------------------------  // acclient.c:345142
void __thiscall MoveToManager::CleanUp(MoveToManager *this)
{
  MoveToManager *v1; // esi@1
  CPhysicsObj *v2; // eax@1
  unsigned int v3; // eax@2
  unsigned int v4; // eax@4
  MovementParameters params; // [sp+4h] [bp-2Ch]@1

  v1 = this;
  MovementParameters::MovementParameters(&params);
  params.hold_key_to_apply = v1->movement_params.hold_key_to_apply;
  v2 = v1->physics_obj;
  params.bitfield &= 0xFFFF7FFF;
  if ( v2 )
  {
    v3 = v1->current_command;
    if ( v3 )
      MoveToManager::_StopMotion(v1, v3, &params);
    v4 = v1->aux_command;
    if ( v4 )
      MoveToManager::_StopMotion(v1, v4, &params);
    if ( v1->top_level_object_id && v1->movement_type )
      CPhysicsObj::clear_target(v1->physics_obj);
  }
  MoveToManager::InitializeLocalVariables(v1);
}

//----- (00529650) --------------------------------------------------------  // acclient.c:345170
void __thiscall MoveToManager::CleanUpAndCallWeenie(MoveToManager *this, unsigned int status)
{
  MoveToManager *v2; // esi@1
  CPhysicsObj *v3; // ecx@1

  v2 = this;
  MoveToManager::CleanUp(this);
  v3 = v2->physics_obj;
  if ( v3 )
    CPhysicsObj::StopCompletely(v3, 0);
}

//----- (00529680) --------------------------------------------------------  // acclient.c:345183
void __thiscall MoveToManager::MoveToObject(MoveToManager *this, unsigned int object_id, unsigned int top_level_id, float object_radius, float object_height, MovementParameters *params)
{
  MoveToManager *v6; // esi@1
  CPhysicsObj *v7; // ecx@1
  CPhysicsObj *v8; // eax@3
  CPhysicsObj *v9; // ecx@3
  CPhysicsObj *v10; // ecx@5
  Frame v11; // [sp+Ch] [bp-40h]@2

  v6 = this;
  v7 = this->physics_obj;
  if ( v7 )
  {
    CPhysicsObj::StopCompletely(v7, 0);
    v8 = v6->physics_obj;
    v6->starting_position.objcell_id = v8->m_position.objcell_id;
    Frame::operator=((int)&v6->starting_position.frame, (int)&v8->m_position.frame);
    v6->sought_object_id = object_id;
    v6->sought_object_radius = object_radius;
    v6->sought_object_height = object_height;
    v6->movement_type = 6;
    v6->top_level_object_id = top_level_id;
    v6->movement_params.bitfield = params->bitfield;
    v6->movement_params.distance_to_object = params->distance_to_object;
    v6->movement_params.min_distance = params->min_distance;
    v6->movement_params.desired_heading = params->desired_heading;
    v6->movement_params.speed = params->speed;
    v6->movement_params.fail_distance = params->fail_distance;
    v6->movement_params.walk_run_threshhold = params->walk_run_threshhold;
    v6->movement_params.context_id = params->context_id;
    v6->movement_params.hold_key_to_apply = params->hold_key_to_apply;
    v6->movement_params.action_stamp = params->action_stamp;
    v9 = v6->physics_obj;
    v6->initialized = 0;
    if ( top_level_id != v9->id )
    {
      CPhysicsObj::set_target(v9, 0, v6->top_level_object_id, 0.5, 0.0);
      return;
    }
    MoveToManager::CleanUp(v6);
  }
  else
  {
    LODWORD(v11.qx) = 0;
    LODWORD(v11.qy) = 0;
    LODWORD(v11.qz) = 0;
    LODWORD(v11.m_fOrigin.x) = 0;
    LODWORD(v11.m_fOrigin.y) = 0;
    LODWORD(v11.m_fOrigin.z) = 0;
    LODWORD(v11.qw) = 1065353216;
    Frame::cache(&v11);
  }
  v10 = v6->physics_obj;
  if ( v10 )
    CPhysicsObj::StopCompletely(v10, 0);
}

//----- (005297D0) --------------------------------------------------------  // acclient.c:345241
void __thiscall MoveToManager::TurnToObject(MoveToManager *this, unsigned int object_id, unsigned int top_level_id, MovementParameters *params)
{
  MoveToManager *v4; // esi@1
  CPhysicsObj *v5; // ecx@1
  CPhysicsObj *v6; // ecx@5
  CPhysicsObj *v7; // ecx@7
  Frame v8; // [sp+Ch] [bp-40h]@2

  v4 = this;
  v5 = this->physics_obj;
  if ( v5 )
  {
    if ( *((_BYTE *)&params->1 + 2) & 1 )
      CPhysicsObj::StopCompletely(v5, 0);
    v4->movement_type = 8;
    v4->sought_object_id = object_id;
    Frame::set_heading(&v4->current_target_position.frame, params->desired_heading);
    v4->top_level_object_id = top_level_id;
    v4->movement_params.bitfield = params->bitfield;
    v4->movement_params.distance_to_object = params->distance_to_object;
    v4->movement_params.min_distance = params->min_distance;
    v4->movement_params.desired_heading = params->desired_heading;
    v4->movement_params.speed = params->speed;
    v4->movement_params.fail_distance = params->fail_distance;
    v4->movement_params.walk_run_threshhold = params->walk_run_threshhold;
    v4->movement_params.context_id = params->context_id;
    v4->movement_params.hold_key_to_apply = params->hold_key_to_apply;
    v4->movement_params.action_stamp = params->action_stamp;
    v6 = v4->physics_obj;
    if ( top_level_id != v6->id )
    {
      v4->initialized = 0;
      CPhysicsObj::set_target(v6, 0, top_level_id, 0.5, 0.0);
      return;
    }
    MoveToManager::CleanUp(v4);
  }
  else
  {
    v4->movement_params.context_id = params->context_id;
    LODWORD(v8.qw) = 1065353216;
    LODWORD(v8.qx) = 0;
    LODWORD(v8.qy) = 0;
    LODWORD(v8.qz) = 0;
    LODWORD(v8.m_fOrigin.x) = 0;
    LODWORD(v8.m_fOrigin.y) = 0;
    LODWORD(v8.m_fOrigin.z) = 0;
    Frame::cache(&v8);
  }
  v7 = v4->physics_obj;
  if ( v7 )
    CPhysicsObj::StopCompletely(v7, 0);
}

//----- (00529930) --------------------------------------------------------  // acclient.c:345296
void __thiscall MoveToManager::CancelMoveTo(MoveToManager *this, unsigned int retval)
{
  MoveToManager *v2; // esi@1
  void *v3; // eax@3
  int v4; // ecx@4
  int v5; // ecx@6
  bool v6; // zf@6
  DLListData *v7; // ecx@10
  CPhysicsObj *v8; // ecx@15

  v2 = this;
  if ( this->movement_type )
  {
    if ( this->pending_actions.head_ )
    {
      do
      {
        v3 = v2->pending_actions.head_;
        if ( v3 )
        {
          v4 = *((_DWORD *)v3 + 1);
          if ( v4 )
          {
            *(_DWORD *)v4 = *(_DWORD *)v3;
          }
          else
          {
            v5 = *(_DWORD *)v3;
            v6 = *(_DWORD *)v3 == 0;
            v2->pending_actions.head_ = *(DLListData **)v3;
            if ( !v6 )
              *(_DWORD *)(v5 + 4) = 0;
          }
          if ( *(_DWORD *)v3 )
          {
            *(_DWORD *)(*(_DWORD *)v3 + 4) = *((_DWORD *)v3 + 1);
          }
          else
          {
            v7 = v2->pending_actions.tail_->dllist_prev;
            v2->pending_actions.tail_ = v7;
            if ( v7 )
              v7->dllist_next = 0;
          }
          *(_DWORD *)v3 = 0;
          *((_DWORD *)v3 + 1) = 0;
          if ( v3 )
            operator delete(v3);
        }
      }
      while ( v2->pending_actions.head_ );
    }
    MoveToManager::CleanUp(v2);
    v8 = v2->physics_obj;
    if ( v8 )
      CPhysicsObj::StopCompletely(v8, 0);
  }
}

//----- (005299D0) --------------------------------------------------------  // acclient.c:345356
void __thiscall MoveToManager::~MoveToManager(MoveToManager *this)
{
  MoveToManager *v1; // esi@1

  v1 = this;
  MoveToManager::Destroy(this);
  v1->movement_params.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->starting_position.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->current_target_position.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->sought_position.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00529A00) --------------------------------------------------------  // acclient.c:345370
void __thiscall MoveToManager::BeginMoveForward(MoveToManager *this)
{
  MoveToManager *v1; // esi@1
  CPhysicsObj *v2; // ecx@3
  Position *v3; // edi@3
  float v4; // ST1C_4@3
  long double v5; // st7@3
  unsigned int v6; // edi@7
  void *v7; // edi@8
  float v8; // eax@12
  signed int v9; // eax@12
  int v10; // ecx@14
  HoldKey v11; // edx@14
  unsigned int v12; // edx@14
  unsigned int v13; // edx@14
  float curr_heading; // [sp+4h] [bp-40h]@3
  float curr_distance; // [sp+8h] [bp-3Ch]@3
  unsigned int motion; // [sp+Ch] [bp-38h]@7
  HoldKey hold_key; // [sp+10h] [bp-34h]@7
  int move_away; // [sp+14h] [bp-30h]@7
  MovementParameters params; // [sp+18h] [bp-2Ch]@12

  v1 = this;
  if ( this->physics_obj )
  {
    curr_distance = MoveToManager::GetCurrentDistance(this);
    v2 = v1->physics_obj;
    v3 = &v2->m_position;
    v4 = CPhysicsObj::get_heading(v2);
    v5 = Position::heading(v3, &v1->current_target_position) - v4;
    curr_heading = v5;
    if ( fabs(v5) < 0.00019999999 )
      curr_heading = 0.0;
    if ( -0.00019999999 > curr_heading )
      curr_heading = curr_heading + 360.0;
    MovementParameters::get_command(&v1->movement_params, curr_distance, curr_heading, &motion, &hold_key, &move_away);
    v6 = motion;
    if ( motion )
    {
      MovementParameters::MovementParameters(&params);
      v8 = v1->movement_params.speed;
      params.hold_key_to_apply = hold_key;
      params.bitfield &= 0xFFFF7FFF;
      params.speed = v8;
      v9 = MoveToManager::_DoMotion(v1, v6, &params);
      if ( v9 )
      {
        MoveToManager::CancelMoveTo(v1, v9);
      }
      else
      {
        v10 = move_away;
        v11 = hold_key;
        v1->current_command = motion;
        v1->moving_away = v10;
        v1->movement_params.hold_key_to_apply = v11;
        v1->previous_distance = curr_distance;
        v12 = Timer::cur_time.Param;
        LODWORD(v1->previous_distance_time) = Timer::cur_time.Cmd;
        HIDWORD(v1->previous_distance_time) = v12;
        v1->original_distance = curr_distance;
        v13 = Timer::cur_time.Param;
        LODWORD(v1->original_distance_time) = Timer::cur_time.Cmd;
        HIDWORD(v1->original_distance_time) = v13;
      }
    }
    else
    {
      v7 = v1->pending_actions.head_;
      if ( v7 )
      {
        DLListBase::Remove((DLListBase *)&v1->pending_actions.head_, v1->pending_actions.head_);
        if ( v7 )
          operator delete(v7);
      }
      MoveToManager::BeginNextNode(v1);
    }
  }
  else
  {
    MoveToManager::CancelMoveTo(this, 8u);
  }
}

//----- (00529B90) --------------------------------------------------------  // acclient.c:345455
void __thiscall MoveToManager::BeginTurnToHeading(MoveToManager *this)
{
  MoveToManager *v1; // esi@1
  DLListData *v2; // edi@1
  CPhysicsObj *v3; // ecx@2
  float heading_diff_; // ST14_4@4
  float y; // ST04_4@4
  double v6; // st7@4
  float v8; // ST14_4@11
  unsigned __int8 v9; // c0@4
  unsigned __int8 v10; // c3@4
  unsigned int v11; // edi@6
  float v12; // edx@9
  HoldKey v13; // eax@9
  signed int v14; // eax@9
  MovementParameters params; // [sp+14h] [bp-2Ch]@9

  v1 = this;
  v2 = this->pending_actions.head_;
  if ( !v2 || (v3 = this->physics_obj) == 0 )
  {
    MoveToManager::CancelMoveTo(v1, 8u);
    return;
  }
  if ( CPhysicsObj::motions_pending(v3) )
    return;
  heading_diff_ = *(float *)&v2[1].dllist_prev;
  y = CPhysicsObj::get_heading(v1->physics_obj);
  v6 = heading_diff(heading_diff_, y, 0x6500000Du);
  if ( v9 | v10 )
  {
    if ( v6 > 0.00019999999 )
    {
      v11 = 1694498829;
      goto LABEL_9;
    }
LABEL_12:
    MoveToManager::RemovePendingActionsHead(v1);
    MoveToManager::BeginNextNode(v1);
    return;
  }
  if ( v6 + 0.00019999999 >= 360.0 )
    goto LABEL_12;
  v11 = 1694498830;
LABEL_9:
  MovementParameters::MovementParameters(&params);
  v12 = v1->movement_params.speed;
  v13 = v1->movement_params.hold_key_to_apply;
  params.bitfield &= 0xFFFF7FFF;
  params.speed = v12;
  params.hold_key_to_apply = v13;
  v14 = MoveToManager::_DoMotion(v1, v11, &params);
  if ( v14 )
  {
    MoveToManager::CancelMoveTo(v1, v14);
  }
  else
  {
    v1->current_command = v11;
    v8 = v6;
    v1->previous_heading = v8;
  }
}

//----- (00529CB0) --------------------------------------------------------  // acclient.c:345520
void __thiscall MoveToManager::BeginNextNode(MoveToManager *this)
{
  MoveToManager *v1; // esi@1
  DLListData *v2; // eax@1
  int v3; // eax@2
  unsigned int v4; // edi@7
  CPhysicsObj *v5; // ecx@7
  PositionManager *v6; // eax@9
  CPhysicsObj *v7; // ecx@10
  float old_object_height; // [sp+4h] [bp-8h]@7
  float old_object_radius; // [sp+8h] [bp-4h]@7

  v1 = this;
  v2 = this->pending_actions.head_;
  if ( v2 )
  {
    v3 = (int)((char *)&v2[1].dllist_next[-1].dllist_next + 1);
    if ( v3 )
    {
      if ( v3 == 2 )
        MoveToManager::BeginTurnToHeading(this);
    }
    else
    {
      MoveToManager::BeginMoveForward(this);
    }
  }
  else if ( SLOBYTE(this->movement_params.bitfield) >= 0 )
  {
    MoveToManager::CleanUp(this);
    v7 = v1->physics_obj;
    if ( v7 )
      CPhysicsObj::StopCompletely(v7, 0);
  }
  else
  {
    old_object_height = this->sought_object_height;
    v4 = this->top_level_object_id;
    old_object_radius = this->sought_object_radius;
    MoveToManager::CleanUp(this);
    v5 = v1->physics_obj;
    if ( v5 )
      CPhysicsObj::StopCompletely(v5, 0);
    v6 = CPhysicsObj::get_position_manager(v1->physics_obj);
    PositionManager::StickTo(v6, v4, old_object_radius, old_object_height);
  }
}

//----- (00529D70) --------------------------------------------------------  // acclient.c:345569
void __thiscall MoveToManager::HitGround(MoveToManager *this)
{
  if ( this->movement_type )
    MoveToManager::BeginNextNode(this);
}

//----- (00529D80) --------------------------------------------------------  // acclient.c:345576
void __thiscall MoveToManager::HandleMoveToPosition(MoveToManager *this)
{
  MoveToManager *v1; // esi@1
  CPhysicsObj *v2; // eax@1
  HoldKey v3; // eax@3
  CPhysicsObj *v4; // ecx@3
  float v5; // ST14_4@4
  double v6; // st7@4
  long double v7; // st7@6
  unsigned int v8; // edi@12
  unsigned int v9; // eax@16
  unsigned int v10; // eax@18
  int v11; // eax@22
  double v12; // st7@22
  void *v13; // edi@27
  unsigned int v14; // eax@30
  AC1Legacy::Vector3 *v15; // eax@38
  long double v16; // st4@38
  float approx_time_to_get_there; // [sp+8h] [bp-88h]@4
  float approx_time_to_get_therea; // [sp+8h] [bp-88h]@21
  double approx_time_to_get_thereb; // [sp+8h] [bp-88h]@39
  MovementParameters params; // [sp+10h] [bp-80h]@3
  AC1Legacy::Vector3 result; // [sp+3Ch] [bp-54h]@38
  Position curr_pos; // [sp+48h] [bp-48h]@3

  v1 = this;
  v2 = this->physics_obj;
  if ( !v2 )
  {
    MoveToManager::CancelMoveTo(this, 8u);
    return;
  }
  curr_pos.vfptr = (PackObjVtbl *)&Position::vftable;
  curr_pos.objcell_id = v2->m_position.objcell_id;
  Frame::operator=((int)&curr_pos.frame, (int)&v2->m_position.frame);
  MovementParameters::MovementParameters(&params);
  v3 = v1->movement_params.hold_key_to_apply;
  v4 = v1->physics_obj;
  params.speed = v1->movement_params.speed;
  params.bitfield &= 0xFFFF7FFF;
  params.hold_key_to_apply = v3;
  if ( CPhysicsObj::motions_pending(v4) )
  {
    v10 = v1->aux_command;
    if ( !v10 )
      goto LABEL_21;
    MoveToManager::_StopMotion(v1, v10, &params);
    goto LABEL_20;
  }
  v5 = Position::heading(&curr_pos, &v1->current_target_position);
  v6 = MovementParameters::get_desired_heading(v1->current_command, v1->moving_away) + v5;
  approx_time_to_get_there = v6;
  if ( v6 >= 360.0 )
    approx_time_to_get_there = approx_time_to_get_there - 360.0;
  v7 = approx_time_to_get_there - CPhysicsObj::get_heading(v1->physics_obj);
  if ( fabs(v7) < 0.00019999999 )
    v7 = 0.0;
  if ( v7 < -0.00019999999 )
    v7 = v7 + 360.0;
  if ( v7 <= 20.0 || v7 >= 360.0 - 20.0 )
  {
    v9 = v1->aux_command;
    if ( !v9 )
      goto LABEL_21;
    MoveToManager::_StopMotion(v1, v9, &params);
LABEL_20:
    v1->aux_command = 0;
    goto LABEL_21;
  }
  v8 = 1694498829;
  if ( v7 >= 180.0 )
    v8 = 1694498830;
  if ( v8 != v1->aux_command )
  {
    MoveToManager::_DoMotion(v1, v8, &params);
    v1->aux_command = v8;
  }
LABEL_21:
  approx_time_to_get_therea = MoveToManager::GetCurrentDistance(v1);
  if ( !MoveToManager::CheckProgressMade(v1, approx_time_to_get_therea) )
  {
    if ( !CPhysicsObj::IsInterpolating(v1->physics_obj) && !CPhysicsObj::motions_pending(v1->physics_obj) )
      ++v1->fail_progress_count;
    goto LABEL_36;
  }
  v11 = v1->moving_away;
  v12 = approx_time_to_get_therea;
  v1->fail_progress_count = 0;
  if ( v11 )
  {
    if ( v12 < v1->movement_params.min_distance )
      goto LABEL_24;
LABEL_27:
    v13 = v1->pending_actions.head_;
    if ( v13 )
    {
      DLListBase::Remove((DLListBase *)&v1->pending_actions.head_, v1->pending_actions.head_);
      if ( v13 )
        operator delete(v13);
    }
    MoveToManager::_StopMotion(v1, v1->current_command, &params);
    v14 = v1->aux_command;
    v1->current_command = 0;
    if ( v14 )
    {
      MoveToManager::_StopMotion(v1, v14, &params);
      v1->aux_command = 0;
    }
    MoveToManager::BeginNextNode(v1);
    goto LABEL_36;
  }
  if ( v12 <= v1->movement_params.distance_to_object )
    goto LABEL_27;
LABEL_24:
  if ( Position::distance(&v1->starting_position, &v1->physics_obj->m_position) > v1->movement_params.fail_distance )
    MoveToManager::CancelMoveTo(v1, 0x3Du);
LABEL_36:
  if ( v1->top_level_object_id )
  {
    if ( v1->movement_type )
    {
      v15 = CPhysicsObj::get_velocity(v1->physics_obj, &result);
      v16 = sqrt(v15->x * v15->x + v15->y * v15->y + v15->z * v15->z);
      if ( v16 > 0.1 )
      {
        approx_time_to_get_thereb = approx_time_to_get_therea / v16;
        if ( fabs(approx_time_to_get_thereb - CPhysicsObj::get_target_quantum(v1->physics_obj)) > 1.0 )
          CPhysicsObj::set_target_quantum(v1->physics_obj, approx_time_to_get_thereb);
      }
    }
  }
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (0052A0C0) --------------------------------------------------------  // acclient.c:345711
void __thiscall MoveToManager::HandleTurnToHeading(MoveToManager *this)
{
  MoveToManager *v1; // esi@1
  CPhysicsObj *v2; // ecx@1
  unsigned int v3; // eax@3
  DLListData *v4; // ebx@6
  DLListData **v5; // edi@6
  unsigned int v6; // ebp@6
  CPhysicsObj *v7; // ecx@7
  DLListData *v8; // ebx@7
  HoldKey v9; // eax@10
  unsigned int v10; // ST04_4@10
  double v11; // st7@11
  CPhysicsObj *v12; // ecx@14
  float curr_heading; // [sp+4h] [bp-30h]@6
  MovementParameters params; // [sp+8h] [bp-2Ch]@10

  v1 = this;
  v2 = this->physics_obj;
  if ( v2 )
  {
    v3 = v1->current_command;
    if ( v3 == 1694498830 || v3 == 1694498829 )
    {
      v4 = v1->pending_actions.head_;
      v5 = &v1->pending_actions.head_;
      curr_heading = CPhysicsObj::get_heading(v2);
      v6 = v1->current_command;
      if ( heading_greater(curr_heading, *(float *)&v4[1].dllist_prev, v1->current_command) )
      {
        v7 = v1->physics_obj;
        v1->fail_progress_count = 0;
        CPhysicsObj::set_heading(v7, *(float *)&v4[1].dllist_prev, 1);
        v8 = *v5;
        if ( *v5 )
        {
          DLListBase::Remove((DLListBase *)&v1->pending_actions.head_, *v5);
          if ( v8 )
            operator delete(v8);
        }
        MovementParameters::MovementParameters(&params);
        v9 = v1->movement_params.hold_key_to_apply;
        v10 = v1->current_command;
        params.bitfield &= 0xFFFF7FFF;
        params.hold_key_to_apply = v9;
        MoveToManager::_StopMotion(v1, v10, &params);
        v1->current_command = 0;
        MoveToManager::BeginNextNode(v1);
      }
      else
      {
        v11 = heading_diff(curr_heading, v1->previous_heading, v6);
        if ( v11 >= 180.0 || v11 <= 0.00019999999 )
        {
          v12 = v1->physics_obj;
          v1->previous_heading = curr_heading;
          if ( !CPhysicsObj::IsInterpolating(v12) && !CPhysicsObj::motions_pending(v1->physics_obj) )
            ++v1->fail_progress_count;
        }
        else
        {
          v1->fail_progress_count = 0;
          v1->previous_heading = curr_heading;
        }
      }
    }
    else
    {
      MoveToManager::BeginTurnToHeading(v1);
    }
  }
  else
  {
    MoveToManager::CancelMoveTo(v1, 8u);
  }
}

//----- (0052A240) --------------------------------------------------------  // acclient.c:345789
void __thiscall MoveToManager::MoveToPosition(MoveToManager *this, Position *p, MovementParameters *params)
{
  MoveToManager *v3; // esi@1
  CPhysicsObj *v4; // ecx@1
  Position *v5; // ebx@2
  int v6; // ebp@2
  CPhysicsObj *v7; // ecx@2
  Position *v8; // edi@2
  long double v9; // st7@2
  CPhysicsObj *v10; // eax@10
  float distance; // [sp+4h] [bp-10h]@2
  unsigned int command; // [sp+8h] [bp-Ch]@6
  int move_away; // [sp+Ch] [bp-8h]@6
  HoldKey hold_key; // [sp+10h] [bp-4h]@6
  Position *pb; // [sp+18h] [bp+4h]@2
  float pa; // [sp+18h] [bp+4h]@2
  float pc; // [sp+18h] [bp+4h]@7

  v3 = this;
  v4 = this->physics_obj;
  if ( v4 )
  {
    CPhysicsObj::StopCompletely(v4, 0);
    v5 = p;
    v6 = (int)&p->frame;
    v3->current_target_position.objcell_id = p->objcell_id;
    Frame::operator=((int)&v3->current_target_position.frame, (int)&p->frame);
    LODWORD(v3->sought_object_radius) = 0;
    distance = MoveToManager::GetCurrentDistance(v3);
    v7 = v3->physics_obj;
    v8 = &v7->m_position;
    *(float *)&pb = CPhysicsObj::get_heading(v7);
    v9 = Position::heading(v8, v5) - *(float *)&pb;
    pa = v9;
    if ( fabs(v9) < 0.00019999999 )
      pa = 0.0;
    if ( -0.00019999999 > pa )
      pa = pa + 360.0;
    MovementParameters::get_command(params, distance, pa, &command, &hold_key, &move_away);
    if ( command )
    {
      pc = Position::heading(&v3->physics_obj->m_position, v5);
      MoveToManager::AddTurnToHeadingNode(v3, pc);
      MoveToManager::AddMoveToPositionNode(v3);
    }
    if ( params->bitfield & 0x40 )
      MoveToManager::AddTurnToHeadingNode(v3, params->desired_heading);
    v3->sought_position.objcell_id = v5->objcell_id;
    Frame::operator=((int)&v3->sought_position.frame, v6);
    v10 = v3->physics_obj;
    v3->starting_position.objcell_id = v10->m_position.objcell_id;
    Frame::operator=((int)&v3->starting_position.frame, (int)&v10->m_position.frame);
    v3->movement_type = 7;
    v3->movement_params.bitfield = params->bitfield;
    v3->movement_params.distance_to_object = params->distance_to_object;
    v3->movement_params.min_distance = params->min_distance;
    v3->movement_params.desired_heading = params->desired_heading;
    v3->movement_params.speed = params->speed;
    v3->movement_params.fail_distance = params->fail_distance;
    v3->movement_params.walk_run_threshhold = params->walk_run_threshhold;
    v3->movement_params.context_id = params->context_id;
    v3->movement_params.hold_key_to_apply = params->hold_key_to_apply;
    v3->movement_params.action_stamp = params->action_stamp;
    v3->movement_params.bitfield &= 0xFFFFFF7F;
    MoveToManager::BeginNextNode(v3);
  }
}

//----- (0052A400) --------------------------------------------------------  // acclient.c:345858
void __thiscall MoveToManager::MoveToObject_Internal(MoveToManager *this, Position *_target_position, Position *interpolated_position)
{
  MoveToManager *v3; // esi@1
  long double v4; // st7@3
  double v5; // st7@10
  float distance; // [sp+4h] [bp-10h]@3
  unsigned int command; // [sp+8h] [bp-Ch]@7
  int move_away; // [sp+Ch] [bp-8h]@7
  HoldKey hold_key; // [sp+10h] [bp-4h]@7
  float _target_positiona; // [sp+18h] [bp+4h]@3
  float heading_to_object; // [sp+1Ch] [bp+8h]@3
  float heading_to_objecta; // [sp+1Ch] [bp+8h]@10

  v3 = this;
  if ( this->physics_obj )
  {
    this->sought_position.objcell_id = interpolated_position->objcell_id;
    Frame::operator=((int)&this->sought_position.frame, (int)&interpolated_position->frame);
    v3->current_target_position.objcell_id = _target_position->objcell_id;
    Frame::operator=((int)&v3->current_target_position.frame, (int)&_target_position->frame);
    _target_positiona = Position::heading(&v3->physics_obj->m_position, interpolated_position);
    distance = MoveToManager::GetCurrentDistance(v3);
    v4 = _target_positiona - CPhysicsObj::get_heading(v3->physics_obj);
    heading_to_object = v4;
    if ( fabs(v4) < 0.00019999999 )
      heading_to_object = 0.0;
    if ( -0.00019999999 > heading_to_object )
      heading_to_object = heading_to_object + 360.0;
    MovementParameters::get_command(&v3->movement_params, distance, heading_to_object, &command, &hold_key, &move_away);
    if ( command )
    {
      MoveToManager::AddTurnToHeadingNode(v3, _target_positiona);
      MoveToManager::AddMoveToPositionNode(v3);
    }
    if ( v3->movement_params.bitfield & 0x40 )
    {
      v5 = _target_positiona + v3->movement_params.desired_heading;
      heading_to_objecta = v5;
      if ( v5 >= 360.0 )
        heading_to_objecta = heading_to_objecta - 360.0;
      MoveToManager::AddTurnToHeadingNode(v3, heading_to_objecta);
    }
    v3->initialized = 1;
    MoveToManager::BeginNextNode(v3);
  }
  else
  {
    MoveToManager::CancelMoveTo(this, 8u);
  }
}

//----- (0052A550) --------------------------------------------------------  // acclient.c:345910
void __thiscall MoveToManager::TurnToObject_Internal(MoveToManager *this, Position *_target_position)
{
  MoveToManager *v2; // esi@1
  void *v3; // eax@3
  Position *_target_positionb; // [sp+8h] [bp+4h]@3
  float _target_positiona; // [sp+8h] [bp+4h]@3

  v2 = this;
  if ( this->physics_obj )
  {
    this->current_target_position.objcell_id = _target_position->objcell_id;
    Frame::operator=((int)&this->current_target_position.frame, (int)&_target_position->frame);
    *(float *)&_target_positionb = Frame::get_heading(&v2->sought_position.frame);
    _target_positiona = fmod(
                          Position::heading(&v2->physics_obj->m_position, &v2->current_target_position)
                        + *(float *)&_target_positionb,
                          360.0);
    Frame::set_heading(&v2->sought_position.frame, _target_positiona);
    v3 = operator new(0x10u);
    if ( v3 )
    {
      *(_DWORD *)v3 = 0;
      *((_DWORD *)v3 + 1) = 0;
      *((_DWORD *)v3 + 2) = 0;
      *((_DWORD *)v3 + 3) = 0;
    }
    else
    {
      v3 = 0;
    }
    *((float *)v3 + 3) = _target_positiona;
    *((_DWORD *)v3 + 2) = 9;
    DLListBase::InsertAfter((DLListBase *)&v2->pending_actions.head_, (DLListData *)v3, v2->pending_actions.tail_);
    v2->initialized = 1;
    MoveToManager::BeginNextNode(v2);
  }
  else
  {
    MoveToManager::CancelMoveTo(this, 8u);
  }
}

//----- (0052A630) --------------------------------------------------------  // acclient.c:345953
void __thiscall MoveToManager::TurnToHeading(MoveToManager *this, MovementParameters *params)
{
  MoveToManager *v2; // esi@1
  CPhysicsObj *v3; // ecx@1
  CPhysicsObj *v4; // ecx@2
  void *v5; // eax@6
  Frame v6; // [sp+10h] [bp-40h]@2
  float paramsa; // [sp+54h] [bp+4h]@6

  v2 = this;
  v3 = this->physics_obj;
  if ( v3 )
  {
    if ( *((_BYTE *)&params->1 + 2) & 1 )
      CPhysicsObj::StopCompletely(v3, 0);
    v2->movement_params.bitfield = params->bitfield;
    v2->movement_params.distance_to_object = params->distance_to_object;
    v2->movement_params.min_distance = params->min_distance;
    v2->movement_params.desired_heading = params->desired_heading;
    v2->movement_params.speed = params->speed;
    v2->movement_params.fail_distance = params->fail_distance;
    v2->movement_params.walk_run_threshhold = params->walk_run_threshhold;
    v2->movement_params.context_id = params->context_id;
    v2->movement_params.hold_key_to_apply = params->hold_key_to_apply;
    v2->movement_params.action_stamp = params->action_stamp;
    v2->movement_params.bitfield &= 0xFFFFFF7F;
    Frame::set_heading(&v2->sought_position.frame, params->desired_heading);
    v2->movement_type = 9;
    paramsa = params->desired_heading;
    v5 = operator new(0x10u);
    if ( v5 )
    {
      *(_DWORD *)v5 = 0;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
    }
    else
    {
      v5 = 0;
    }
    *((_DWORD *)v5 + 2) = 9;
    *((float *)v5 + 3) = paramsa;
    DLListBase::InsertAfter((DLListBase *)&v2->pending_actions.head_, (DLListData *)v5, v2->pending_actions.tail_);
    MoveToManager::BeginNextNode(v2);
  }
  else
  {
    v2->movement_params.context_id = params->context_id;
    LODWORD(v6.qw) = 1065353216;
    LODWORD(v6.qx) = 0;
    LODWORD(v6.qy) = 0;
    LODWORD(v6.qz) = 0;
    LODWORD(v6.m_fOrigin.x) = 0;
    LODWORD(v6.m_fOrigin.y) = 0;
    LODWORD(v6.m_fOrigin.z) = 0;
    Frame::cache(&v6);
    v4 = v2->physics_obj;
    if ( v4 )
      CPhysicsObj::StopCompletely(v4, 0);
  }
}

//----- (0052A780) --------------------------------------------------------  // acclient.c:346017
void __thiscall MoveToManager::UseTime(MoveToManager *this)
{
  CPhysicsObj *v1; // eax@1
  DLListData *v2; // eax@3
  int v3; // eax@7

  v1 = this->physics_obj;
  if ( v1 )
  {
    if ( v1->transient_state & 1 )
    {
      v2 = this->pending_actions.head_;
      if ( v2 )
      {
        if ( !this->top_level_object_id || this->movement_type == Invalid || this->initialized )
        {
          v3 = (int)((char *)&v2[1].dllist_next[-1].dllist_next + 1);
          if ( v3 )
          {
            if ( v3 == 2 )
              MoveToManager::HandleTurnToHeading(this);
          }
          else
          {
            MoveToManager::HandleMoveToPosition(this);
          }
        }
      }
    }
  }
}

//----- (0052A7D0) --------------------------------------------------------  // acclient.c:346050
void __thiscall MoveToManager::HandleUpdateTarget(MoveToManager *this, TargetInfo *target_info)
{
  MoveToManager *v2; // esi@1
  CPhysicsObj *v3; // eax@1
  unsigned int v4; // ecx@3
  unsigned int v5; // edx@8
  unsigned int v6; // ecx@8

  v2 = this;
  v3 = this->physics_obj;
  if ( v3 )
  {
    v4 = this->top_level_object_id;
    if ( v4 == target_info->object_id )
    {
      if ( v2->initialized )
      {
        if ( target_info->status == 1 )
        {
          if ( v2->movement_type == 6 )
          {
            Position::operator=((int)&v2->sought_position, (int)&target_info->interpolated_position);
            Position::operator=((int)&v2->current_target_position, (int)&target_info->target_position);
            LODWORD(v2->previous_distance) = 2139095039;
            v5 = Timer::cur_time.Param;
            LODWORD(v2->previous_distance_time) = Timer::cur_time.Cmd;
            HIDWORD(v2->previous_distance_time) = v5;
            LODWORD(v2->original_distance) = 2139095039;
            v6 = Timer::cur_time.Param;
            LODWORD(v2->original_distance_time) = Timer::cur_time.Cmd;
            HIDWORD(v2->original_distance_time) = v6;
          }
        }
        else
        {
          MoveToManager::CancelMoveTo(v2, 0x37u);
        }
      }
      else if ( v4 == v3->id )
      {
        Position::operator=((int)&v2->sought_position, (int)&v3->m_position);
        Position::operator=((int)&v2->current_target_position, (int)&v2->physics_obj->m_position);
        MoveToManager::CleanUpAndCallWeenie(v2, 0);
      }
      else if ( target_info->status == 1 )
      {
        if ( v2->movement_type == 6 )
        {
          MoveToManager::MoveToObject_Internal(v2, &target_info->target_position, &target_info->interpolated_position);
        }
        else if ( v2->movement_type == 8 )
        {
          MoveToManager::TurnToObject_Internal(v2, &target_info->target_position);
        }
      }
      else
      {
        MoveToManager::CancelMoveTo(v2, 0x38u);
      }
    }
  }
  else
  {
    MoveToManager::CancelMoveTo(this, 8u);
  }
}

//----- (0052A900) --------------------------------------------------------  // acclient.c:346118
unsigned int __thiscall MoveToManager::PerformMovement(MoveToManager *this, MovementStruct *mvs)
{
  MoveToManager *v2; // esi@1
  unsigned int result; // eax@2

  v2 = this;
  MoveToManager::CancelMoveTo(this, 0x36u);
  CPhysicsObj::unstick_from_object(v2->physics_obj);
  switch ( mvs->type )
  {
    case 6:
      MoveToManager::MoveToObject(v2, mvs->object_id, mvs->top_level_id, mvs->radius, mvs->height, mvs->params);
      result = 0;
      break;
    case 7:
      MoveToManager::MoveToPosition(v2, &mvs->pos, mvs->params);
      result = 0;
      break;
    case 8:
      MoveToManager::TurnToObject(v2, mvs->object_id, mvs->top_level_id, mvs->params);
      result = 0;
      break;
    case 9:
      MoveToManager::TurnToHeading(v2, mvs->params);
      goto LABEL_6;
    default:
LABEL_6:
      result = 0;
      break;
  }
  return result;
}

//----- (006FDBD0) --------------------------------------------------------  // acclient.c:786000
int _E77_3()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_15;
  INITIAL_MAX_DATA_RATE_84 = LOWEST_DATA_RATE_15;
  return result;
}

//----- (006FDBE0) --------------------------------------------------------  // acclient.c:786010
void sub_6FDBE0()
{
  flt_844690 = 1000.0 + 1.0;
}

//----- (006FDC00) --------------------------------------------------------  // acclient.c:786016
void _E99_25()
{
  flt_844694 = 24.0 * 8.0;
}

//----- (006FDC20) --------------------------------------------------------  // acclient.c:786022
void _E101_24()
{
  flt_844698 = 24.0 * 0.5;
}

//----- (006FDC40) --------------------------------------------------------  // acclient.c:786028
void sub_6FDC40()
{
  flt_8446A0 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FDC60) --------------------------------------------------------  // acclient.c:786034
void _E105_30()
{
  dbl_8446A8 = 1.0 / 30.0;
}

//----- (006FDC80) --------------------------------------------------------  // acclient.c:786040
void _E107_24()
{
  dbl_8446B0 = 1.0 / 5.0;
}

//----- (006FDCA0) --------------------------------------------------------  // acclient.c:786046
int sub_6FDCA0()
{
  return atexit(nullsub_1138);
}

