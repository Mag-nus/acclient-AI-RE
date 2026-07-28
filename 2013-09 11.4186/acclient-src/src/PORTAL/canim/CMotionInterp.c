/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CMotionInterp
   Object     : PORTAL\canim\CMotionInterp.obj
   Functions  : 49
   Addresses  : 005279E0 - 006FDBC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005279E0) --------------------------------------------------------  // acclient.c:343294
signed int __stdcall CMotionInterp::motion_allows_jump(unsigned int substate)
{
  if ( substate > 0x40000018 )
  {
    if ( substate > 0x41000014 || substate < 0x41000012 && (substate < 0x4000001E || substate > 0x40000039) )
      return 0;
  }
  else if ( substate < 0x40000016 )
  {
    if ( substate > 0x10000131 )
    {
      if ( substate != 1073741832 )
        return 0;
    }
    else if ( substate < 0x10000128 && (substate < 0x1000006F || substate > 0x10000078) )
    {
      return 0;
    }
  }
  return 72;
}

//----- (00527A50) --------------------------------------------------------  // acclient.c:343317
signed int __thiscall CMotionInterp::jump_charge_is_allowed(CMotionInterp *this)
{
  CMotionInterp *v1; // esi@1
  CWeenieObject *v2; // ecx@1
  signed int result; // eax@3
  unsigned int v4; // esi@4

  v1 = this;
  v2 = this->weenie_obj;
  if ( !v2 || (unsigned __int8)((int (__stdcall *)(_DWORD))v2->vfptr[15].__vecDelDtor)(LODWORD(v1->jump_extent)) )
  {
    v4 = v1->interpreted_state.forward_command;
    if ( v4 == 1073741832 || v4 > 0x41000011 && v4 <= 0x41000014 )
      result = 72;
    else
      result = 0;
  }
  else
  {
    result = 73;
  }
  return result;
}

//----- (00527AA0) --------------------------------------------------------  // acclient.c:343342
double __thiscall CMotionInterp::get_jump_v_z(CMotionInterp *this)
{
  CWeenieObject *v1; // ecx@4
  double result; // st7@5
  float extent; // [sp+8h] [bp-4h]@1

  extent = *(float *)&this;
  extent = this->jump_extent;
  if ( extent < 0.00019999999 )
    goto LABEL_11;
  if ( extent > 1.0 )
    extent = 1.0;
  v1 = this->weenie_obj;
  if ( !v1 )
    return 10.0;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD, float *))v1->vfptr[12].__vecDelDtor)(LODWORD(extent), &extent) )
    result = extent;
  else
LABEL_11:
    result = 0.0;
  return result;
}

//----- (00527B10) --------------------------------------------------------  // acclient.c:343366
unsigned int __thiscall CMotionInterp::InqStyle(CMotionInterp *this)
{
  return this->interpreted_state.current_style;
}

//----- (00527B20) --------------------------------------------------------  // acclient.c:343372
BOOL __thiscall CPhysicsObj::on_ground(CPhysicsObj *this)
{
  unsigned int v1; // eax@1

  v1 = this->transient_state;
  return v1 & 1 && v1 & 2;
}

//----- (00527B40) --------------------------------------------------------  // acclient.c:343381
void __thiscall CMotionInterp::Destroy(CMotionInterp *this)
{
  CMotionInterp *v1; // esi@1
  void *v2; // eax@2
  LListData *v3; // ecx@3
  bool v4; // zf@3

  v1 = this;
  while ( 1 )
  {
    v2 = v1->pending_motions.head_;
    if ( !v2 )
      break;
    v3 = *(LListData **)v2;
    v4 = *(_DWORD *)v2 == 0;
    v1->pending_motions.head_ = *(LListData **)v2;
    if ( v4 )
      v1->pending_motions.tail_ = v3;
    *(_DWORD *)v2 = 0;
    operator delete(v2);
  }
}

//----- (00527B80) --------------------------------------------------------  // acclient.c:343405
void __thiscall CMotionInterp::add_to_queue(CMotionInterp *this, unsigned int context_id, unsigned int motion, unsigned int jump_error_code)
{
  CMotionInterp *v4; // esi@1
  void *v5; // eax@1
  LListData *v6; // ecx@4

  v4 = this;
  v5 = operator new(0x10u);
  if ( v5 )
  {
    *((_DWORD *)v5 + 1) = context_id;
    *(_DWORD *)v5 = 0;
    *((_DWORD *)v5 + 2) = motion;
    *((_DWORD *)v5 + 3) = jump_error_code;
  }
  else
  {
    v5 = 0;
  }
  v6 = v4->pending_motions.tail_;
  if ( v6 )
  {
    v6->llist_next = (LListData *)v5;
    v4->pending_motions.tail_ = (LListData *)v5;
  }
  else
  {
    v4->pending_motions.head_ = (LListData *)v5;
    v4->pending_motions.tail_ = (LListData *)v5;
  }
}

//----- (00527BE0) --------------------------------------------------------  // acclient.c:343438
void __thiscall CMotionInterp::apply_run_to_command(CMotionInterp *this, unsigned int *motion, float *speed)
{
  CMotionInterp *v3; // esi@1
  CWeenieObject *v4; // ecx@1
  double v5; // st7@2
  double v6; // st7@9
  float run_factor; // [sp+4h] [bp-4h]@1

  run_factor = *(float *)&this;
  v3 = this;
  v4 = this->weenie_obj;
  if ( v4 )
  {
    if ( (unsigned __int8)((int (__stdcall *)(float *))v4->vfptr[13].__vecDelDtor)(&run_factor) )
      v5 = run_factor;
    else
      v5 = v3->my_run_rate;
  }
  else
  {
    v5 = 1.0;
  }
  switch ( *motion )
  {
    case 0x45000005u:
      if ( *speed > 0.0 )
        *motion = 1140850695;
      *speed = v5 * *speed;
      break;
    case 0x6500000Du:
      *speed = 1.5 * *speed;
      break;
    case 0x6500000Fu:
      v6 = v5 * *speed;
      *speed = v6;
      if ( fabs(v6) > 3.0 )
      {
        if ( v6 <= 0.0 )
          *speed = -1.0 * 3.0;
        else
          *speed = 1.0 * 3.0;
      }
      break;
  }
}

//----- (00527CB0) --------------------------------------------------------  // acclient.c:343485
double __thiscall CMotionInterp::get_max_speed(CMotionInterp *this)
{
  CMotionInterp *v1; // esi@1
  CWeenieObject *v2; // ecx@1
  double result; // st7@2
  float retval; // [sp+4h] [bp-4h]@1

  retval = *(float *)&this;
  v1 = this;
  v2 = this->weenie_obj;
  retval = 0.0;
  if ( v2 )
  {
    if ( (unsigned __int8)((int (__stdcall *)(float *))v2->vfptr[13].__vecDelDtor)(&retval) )
      result = retval * 4.0;
    else
      result = v1->my_run_rate * 4.0;
  }
  else
  {
    result = 1.0 * 4.0;
  }
  return result;
}

//----- (00527D00) --------------------------------------------------------  // acclient.c:343511
double __thiscall CMotionInterp::get_adjusted_max_speed(CMotionInterp *this)
{
  CMotionInterp *v1; // esi@1
  CWeenieObject *v2; // ecx@1
  double v3; // st7@2
  float run_factor; // [sp+4h] [bp-4h]@1

  run_factor = *(float *)&this;
  v1 = this;
  v2 = this->weenie_obj;
  if ( v2 )
  {
    if ( (unsigned __int8)((int (__stdcall *)(float *))v2->vfptr[13].__vecDelDtor)(&run_factor) )
      v3 = run_factor;
    else
      v3 = v1->my_run_rate;
  }
  else
  {
    v3 = 1.0;
  }
  if ( v1->interpreted_state.forward_command == 1140850695 )
    v3 = v1->interpreted_state.forward_speed / v1->current_speed_factor;
  return v3 * 4.0;
}

//----- (00527D50) --------------------------------------------------------  // acclient.c:343538
void __thiscall CMotionInterp::get_state_velocity(CMotionInterp *this, AC1Legacy::Vector3 *v)
{
  CMotionInterp *v2; // edi@1
  double v3; // st7@2
  AC1Legacy::Vector3 *v4; // esi@4
  unsigned int v5; // eax@4
  double v6; // st7@5
  CWeenieObject *v7; // ecx@9
  double v8; // st7@10
  long double v9; // st7@14
  long double v10; // st3@14

  v2 = this;
  if ( this->interpreted_state.sidestep_command == 1694498831 )
    v3 = 1.25 * this->interpreted_state.sidestep_speed;
  else
    v3 = 0.0;
  v4 = v;
  v->x = v3;
  v5 = this->interpreted_state.forward_command;
  if ( v5 == 1157627909 )
  {
    v6 = 3.1199999 * this->interpreted_state.forward_speed;
  }
  else if ( v5 == 1140850695 )
  {
    v6 = 4.0 * this->interpreted_state.forward_speed;
  }
  else
  {
    v6 = 0.0;
  }
  v4->y = v6;
  LODWORD(v4->z) = 0;
  v7 = this->weenie_obj;
  *(float *)&v = 0.0;
  if ( v7 )
  {
    if ( (unsigned __int8)((int (__stdcall *)(AC1Legacy::Vector3 **))v7->vfptr[13].__vecDelDtor)(&v) )
      v8 = *(float *)&v;
    else
      v8 = v2->my_run_rate;
  }
  else
  {
    v8 = 1.0;
  }
  v9 = v8 * 4.0;
  v10 = sqrt(v4->x * v4->x + v4->y * v4->y + v4->z * v4->z);
  if ( v10 > v9 )
  {
    v4->x = 1.0 / v10 * v4->x * v9;
    v4->y = 1.0 / v10 * v4->y * v9;
    v4->z = 1.0 / v10 * v4->z * v9;
  }
}

//----- (00527E40) --------------------------------------------------------  // acclient.c:343596
signed int __thiscall CMotionInterp::StopCompletely(CMotionInterp *this)
{
  CMotionInterp *v1; // esi@1
  CPhysicsObj *v2; // ecx@1
  signed int result; // eax@2
  signed int v4; // eax@3
  CPhysicsObj *v5; // ecx@3
  unsigned int v6; // edi@3
  CPhysicsObj *v7; // ecx@3

  v1 = this;
  v2 = this->physics_obj;
  if ( v2 )
  {
    CPhysicsObj::cancel_moveto(v2);
    v4 = CMotionInterp::motion_allows_jump(v1->interpreted_state.forward_command);
    v5 = v1->physics_obj;
    v6 = v4;
    v1->raw_state.forward_command = 1090519043;
    LODWORD(v1->raw_state.forward_speed) = 1065353216;
    v1->raw_state.sidestep_command = 0;
    v1->raw_state.turn_command = 0;
    v1->interpreted_state.forward_command = 1090519043;
    LODWORD(v1->interpreted_state.forward_speed) = 1065353216;
    v1->interpreted_state.sidestep_command = 0;
    v1->interpreted_state.turn_command = 0;
    CPhysicsObj::StopCompletely_Internal(v5);
    CMotionInterp::add_to_queue(v1, 0, 0x41000003u, v6);
    v7 = v1->physics_obj;
    if ( v7 )
    {
      if ( !v7->cell )
        CPhysicsObj::RemoveLinkAnimations(v7);
    }
    result = 0;
  }
  else
  {
    result = 8;
  }
  return result;
}

//----- (00527EC0) --------------------------------------------------------  // acclient.c:343640
void __thiscall CMotionInterp::MotionDone(CMotionInterp *this, int success)
{
  CMotionInterp *v2; // esi@1
  CPhysicsObj *v3; // ecx@1
  LListData *v4; // eax@2
  void *v5; // eax@5
  LListData *v6; // ecx@6
  bool v7; // zf@6

  v2 = this;
  v3 = this->physics_obj;
  if ( v3 )
  {
    v4 = v2->pending_motions.head_;
    if ( v4 )
    {
      if ( (unsigned int)v4[2].llist_next & 0x10000000 )
      {
        CPhysicsObj::unstick_from_object(v3);
        InterpretedMotionState::RemoveAction(&v2->interpreted_state);
        RawMotionState::RemoveAction(&v2->raw_state);
      }
      v5 = v2->pending_motions.head_;
      if ( v5 )
      {
        v6 = *(LListData **)v5;
        v7 = *(_DWORD *)v5 == 0;
        v2->pending_motions.head_ = *(LListData **)v5;
        if ( v7 )
          v2->pending_motions.tail_ = v6;
        *(_DWORD *)v5 = 0;
        operator delete(v5);
      }
    }
  }
}

//----- (00527F30) --------------------------------------------------------  // acclient.c:343678
void __thiscall CMotionInterp::HandleExitWorld(CMotionInterp *this)
{
  CMotionInterp *v1; // esi@1
  LListData *i; // eax@1
  CPhysicsObj *v3; // ecx@2
  void *v4; // eax@6
  LListData *v5; // ecx@7
  bool v6; // zf@7

  v1 = this;
  for ( i = this->pending_motions.head_; i; i = v1->pending_motions.head_ )
  {
    v3 = v1->physics_obj;
    if ( v3 && i )
    {
      if ( (unsigned int)i[2].llist_next & 0x10000000 )
      {
        CPhysicsObj::unstick_from_object(v3);
        InterpretedMotionState::RemoveAction(&v1->interpreted_state);
        RawMotionState::RemoveAction(&v1->raw_state);
      }
      v4 = v1->pending_motions.head_;
      if ( v4 )
      {
        v5 = *(LListData **)v4;
        v6 = *(_DWORD *)v4 == 0;
        v1->pending_motions.head_ = *(LListData **)v4;
        if ( v6 )
          v1->pending_motions.tail_ = v5;
        *(_DWORD *)v4 = 0;
        operator delete(v4);
      }
    }
  }
}

//----- (00527FA0) --------------------------------------------------------  // acclient.c:343715
BOOL __thiscall CMotionInterp::is_standing_still(CMotionInterp *this)
{
  unsigned int v1; // eax@1

  v1 = this->physics_obj->transient_state;
  return v1 & 1
      && v1 & 2
      && this->interpreted_state.forward_command == 1090519043
      && !this->interpreted_state.sidestep_command
      && !this->interpreted_state.turn_command;
}

//----- (00527FE0) --------------------------------------------------------  // acclient.c:343728
BOOL __thiscall CMotionInterp::motions_pending(CMotionInterp *this)
{
  return this->pending_motions.head_ != 0;
}

//----- (00527FF0) --------------------------------------------------------  // acclient.c:343734
void __thiscall CMotionInterp::~CMotionInterp(CMotionInterp *this)
{
  CMotionInterp *v1; // esi@1

  v1 = this;
  CMotionInterp::Destroy(this);
  InterpretedMotionState::~InterpretedMotionState(&v1->interpreted_state);
  RawMotionState::~RawMotionState(&v1->raw_state);
}

//----- (00528010) --------------------------------------------------------  // acclient.c:343745
void __thiscall CMotionInterp::adjust_motion(CMotionInterp *this, unsigned int *motion, float *speed, HoldKey key)
{
  CMotionInterp *v4; // edi@1
  CWeenieObject *v5; // ecx@1
  unsigned int v6; // eax@3
  double v7; // st7@7
  double v8; // st7@8
  int v9; // eax@9
  HoldKey v10; // esi@15
  int v11; // eax@15

  v4 = this;
  v5 = this->weenie_obj;
  if ( v5 && !((int (*)(void))v5->vfptr[11].__vecDelDtor)() )
    return;
  v6 = *motion;
  if ( *motion <= 0x6500000E )
  {
    if ( *motion == 1694498830 )
    {
      *motion = 1694498829;
      v8 = *speed * -1.0;
LABEL_14:
      *speed = v8;
      goto LABEL_15;
    }
    if ( v6 == 1140850695 )
      return;
    if ( v6 != 1157627910 )
      goto LABEL_15;
    *motion = 1157627909;
    v7 = -0.64999998;
LABEL_13:
    v8 = v7 * *speed;
    goto LABEL_14;
  }
  v9 = v6 - 1694498831;
  if ( !v9 )
  {
LABEL_12:
    v7 = 3.1199999 / 1.25 * 0.5;
    goto LABEL_13;
  }
  if ( v9 == 1 )
  {
    *motion = 1694498831;
    *speed = *speed * -1.0;
    goto LABEL_12;
  }
LABEL_15:
  v10 = key;
  v11 = 0;
  if ( key == HoldKey_Invalid )
    v10 = v4->raw_state.current_holdkey;
  LOBYTE(v11) = v10 == 2;
  if ( v11 )
    CMotionInterp::apply_run_to_command(v4, motion, speed);
}

//----- (005280C0) --------------------------------------------------------  // acclient.c:343805
void __thiscall CMotionInterp::get_leave_ground_velocity(CMotionInterp *this, AC1Legacy::Vector3 *v)
{
  AC1Legacy::Vector3 *v2; // esi@1
  CMotionInterp *v3; // edi@1
  long double v4; // st7@1
  CPhysicsObj *v5; // eax@4
  float v6; // ST0C_4@4
  float v7; // ST10_4@4
  double v8; // st7@4
  double v9; // st6@4
  float v10; // ST14_4@4
  float va; // [sp+18h] [bp+4h]@1

  v2 = v;
  v3 = this;
  CMotionInterp::get_state_velocity(this, v);
  va = CMotionInterp::get_jump_v_z(v3);
  v4 = fabs(v2->x);
  v2->z = va;
  if ( v4 < 0.00019999999 && fabs(v2->y) < 0.00019999999 && fabs(va) < 0.00019999999 )
  {
    v5 = v3->physics_obj;
    v6 = v5->m_position.frame.m_fl2gv[1] * v5->m_velocityVector.y
       + v5->m_position.frame.m_fl2gv[0] * v5->m_velocityVector.x
       + v5->m_position.frame.m_fl2gv[2] * v5->m_velocityVector.z;
    v7 = v5->m_position.frame.m_fl2gv[4] * v5->m_velocityVector.y
       + v5->m_position.frame.m_fl2gv[3] * v5->m_velocityVector.x
       + v5->m_position.frame.m_fl2gv[5] * v5->m_velocityVector.z;
    v8 = v5->m_position.frame.m_fl2gv[7] * v5->m_velocityVector.y
       + v5->m_position.frame.m_fl2gv[6] * v5->m_velocityVector.x;
    v9 = v5->m_position.frame.m_fl2gv[8] * v5->m_velocityVector.z;
    v2->x = v6;
    v2->y = v7;
    v10 = v8 + v9;
    v2->z = v10;
  }
}

//----- (005281C0) --------------------------------------------------------  // acclient.c:343844
signed int __thiscall CMotionInterp::charge_jump(CMotionInterp *this)
{
  CMotionInterp *v1; // esi@1
  CWeenieObject *v2; // ecx@1
  signed int result; // eax@3
  unsigned int v4; // edx@4
  unsigned int v5; // ecx@7

  v1 = this;
  v2 = this->weenie_obj;
  if ( !v2 || (unsigned __int8)((int (__stdcall *)(_DWORD))v2->vfptr[15].__vecDelDtor)(LODWORD(v1->jump_extent)) )
  {
    v4 = v1->interpreted_state.forward_command;
    if ( v4 == 1073741832 || v4 > 0x41000011 && v4 <= 0x41000014 )
    {
      result = 72;
    }
    else
    {
      v5 = v1->physics_obj->transient_state;
      result = 0;
      if ( v5 & 1
        && v5 & 2
        && v4 == 1090519043
        && !v1->interpreted_state.sidestep_command
        && !v1->interpreted_state.turn_command )
        v1->standing_longjump = 1;
    }
  }
  else
  {
    result = 73;
  }
  return result;
}

//----- (00528240) --------------------------------------------------------  // acclient.c:343881
int __thiscall CMotionInterp::contact_allows_move(CMotionInterp *this, unsigned int motion)
{
  CMotionInterp *v2; // esi@1
  CWeenieObject *v4; // ecx@8
  CPhysicsObj *v5; // eax@10
  unsigned int v6; // ecx@11
  unsigned int v7; // eax@12

  v2 = this;
  if ( this->physics_obj )
  {
    if ( motion > 0x40000015 )
    {
      if ( motion >= 0x6500000D && motion <= 0x6500000E )
        return 1;
    }
    else if ( motion == 1073741845 || motion == 1073741841 )
    {
      return 1;
    }
    v4 = this->weenie_obj;
    if ( v4 && !((int (*)(void))v4->vfptr[11].__vecDelDtor)() )
      return 1;
    v5 = v2->physics_obj;
    if ( !v5 )
      return 1;
    v6 = v5->state;
    if ( !(BYTE1(v6) & 4) )
      return 1;
    v7 = v5->transient_state;
    if ( v7 & 1 )
    {
      if ( v7 & 2 )
        return 1;
    }
  }
  return 0;
}

//----- (005282B0) --------------------------------------------------------  // acclient.c:343921
signed int __thiscall CMotionInterp::jump_is_allowed(CMotionInterp *this, float extent, int *stamina_cost)
{
  CMotionInterp *v3; // esi@1
  CWeenieObject *v4; // ecx@2
  CPhysicsObj *v5; // eax@4
  unsigned int v6; // ecx@5
  unsigned int v7; // eax@6
  signed int result; // eax@8
  LListData *v9; // eax@11
  signed int v10; // edi@14
  CWeenieObject *v11; // ecx@15
  bool v12; // zf@16

  v3 = this;
  if ( this->physics_obj
    && ((v4 = this->weenie_obj) != 0 && !((int (*)(void))v4->vfptr[11].__vecDelDtor)()
     || (v5 = v3->physics_obj) == 0
     || (v6 = v5->state, !(BYTE1(v6) & 4))
     || (v7 = v5->transient_state, v7 & 1) && v7 & 2) )
  {
    if ( CPhysicsObj::IsFullyConstrained(v3->physics_obj) )
    {
      result = 71;
    }
    else
    {
      v9 = v3->pending_motions.head_;
      if ( !v9 || (result = (signed int)v9[3].llist_next) == 0 )
      {
        result = CMotionInterp::jump_charge_is_allowed(v3);
        if ( !result )
        {
          v10 = CMotionInterp::motion_allows_jump(v3->interpreted_state.forward_command);
          if ( v10
            || (v11 = v3->weenie_obj) == 0
            || (v12 = (unsigned __int8)((int (__stdcall *)(_DWORD, int *))v11->vfptr[16].__vecDelDtor)(
                                         LODWORD(extent),
                                         stamina_cost) == 0,
                result = 71,
                !v12) )
            result = v10;
        }
      }
    }
  }
  else
  {
    result = 36;
  }
  return result;
}

//----- (00528360) --------------------------------------------------------  // acclient.c:343974
signed int __thiscall CMotionInterp::DoInterpretedMotion(CMotionInterp *this, unsigned int motion, MovementParameters *params)
{
  CMotionInterp *v3; // esi@1
  signed int v5; // ebp@10
  signed int v6; // eax@12
  unsigned int v7; // eax@16
  unsigned int v8; // ecx@20
  CPhysicsObj *v9; // ecx@23

  v3 = this;
  if ( !this->physics_obj )
    return 8;
  if ( CMotionInterp::contact_allows_move(this, motion) )
  {
    if ( !v3->standing_longjump || motion != 1157627909 && motion != 1140850695 && motion != 1694498831 )
    {
      if ( motion == 1073741841 )
        CPhysicsObj::RemoveLinkAnimations(v3->physics_obj);
      v5 = CPhysicsObj::DoInterpretedMotion(v3->physics_obj, motion, params);
      if ( !v5 )
      {
        if ( params->bitfield & 0x20000 )
        {
          v6 = 72;
        }
        else
        {
          v6 = CMotionInterp::motion_allows_jump(motion);
          if ( !v6 && !(motion & 0x10000000) )
            v6 = CMotionInterp::motion_allows_jump(v3->interpreted_state.forward_command);
        }
        CMotionInterp::add_to_queue(v3, params->context_id, motion, v6);
        v7 = params->bitfield;
        if ( BYTE1(v7) & 0x40 )
          InterpretedMotionState::ApplyMotion(&v3->interpreted_state, motion, params);
      }
      goto LABEL_23;
    }
LABEL_20:
    v8 = params->bitfield;
    if ( BYTE1(v8) & 0x40 )
      InterpretedMotionState::ApplyMotion(&v3->interpreted_state, motion, params);
    v5 = 0;
    goto LABEL_23;
  }
  if ( !(motion & 0x10000000) )
    goto LABEL_20;
  v5 = 36;
LABEL_23:
  v9 = v3->physics_obj;
  if ( v9 )
  {
    if ( !v9->cell )
      CPhysicsObj::RemoveLinkAnimations(v9);
  }
  return v5;
}

//----- (00528470) --------------------------------------------------------  // acclient.c:344033
signed int __thiscall CMotionInterp::StopInterpretedMotion(CMotionInterp *this, unsigned int motion, MovementParameters *params)
{
  CMotionInterp *v3; // esi@1
  signed int result; // eax@2
  signed int v5; // ebp@8
  unsigned int v6; // eax@9
  unsigned int v7; // eax@11
  CPhysicsObj *v8; // ecx@14

  v3 = this;
  if ( this->physics_obj )
  {
    if ( !CMotionInterp::contact_allows_move(this, motion)
      || v3->standing_longjump && (motion == 1157627909 || motion == 1140850695 || motion == 1694498831) )
    {
      v7 = params->bitfield;
      if ( BYTE1(v7) & 0x40 )
        InterpretedMotionState::RemoveMotion(&v3->interpreted_state, motion);
      v5 = 0;
    }
    else
    {
      v5 = CPhysicsObj::StopInterpretedMotion(v3->physics_obj, motion, params);
      if ( !v5 )
      {
        CMotionInterp::add_to_queue(v3, params->context_id, 0x41000003u, 0);
        v6 = params->bitfield;
        if ( BYTE1(v6) & 0x40 )
          InterpretedMotionState::RemoveMotion(&v3->interpreted_state, motion);
      }
    }
    v8 = v3->physics_obj;
    if ( v8 )
    {
      if ( !v8->cell )
        CPhysicsObj::RemoveLinkAnimations(v8);
    }
    result = v5;
  }
  else
  {
    result = 8;
  }
  return result;
}

//----- (00528530) --------------------------------------------------------  // acclient.c:344080
signed int __thiscall CMotionInterp::StopMotion(CMotionInterp *this, unsigned int motion, MovementParameters *params)
{
  CMotionInterp *v3; // edi@1
  CPhysicsObj *v4; // ecx@1
  signed int result; // eax@2
  MovementParameters *v6; // esi@3
  unsigned int v7; // eax@3
  float v8; // ecx@5
  float v9; // edx@5
  float v10; // eax@5
  float v11; // ecx@5
  HoldKey v12; // eax@5
  unsigned int v13; // ecx@5
  float v14; // edx@5
  unsigned int v15; // edx@5
  signed int v16; // ebx@5
  unsigned int v17; // eax@6
  MovementParameters adjusted_parameters; // [sp+4h] [bp-2Ch]@5

  v3 = this;
  v4 = this->physics_obj;
  if ( v4 )
  {
    v6 = params;
    v7 = params->bitfield;
    if ( SBYTE1(v7) < 0 )
      CPhysicsObj::cancel_moveto(v4);
    v8 = v6->distance_to_object;
    v9 = v6->min_distance;
    adjusted_parameters.bitfield = v6->bitfield;
    adjusted_parameters.desired_heading = v6->desired_heading;
    v10 = v6->walk_run_threshhold;
    adjusted_parameters.distance_to_object = v8;
    v11 = v6->speed;
    adjusted_parameters.walk_run_threshhold = v10;
    v12 = v6->hold_key_to_apply;
    adjusted_parameters.speed = v11;
    v13 = v6->context_id;
    adjusted_parameters.min_distance = v9;
    v14 = v6->fail_distance;
    adjusted_parameters.hold_key_to_apply = v12;
    adjusted_parameters.context_id = v13;
    adjusted_parameters.fail_distance = v14;
    v15 = v6->action_stamp;
    params = (MovementParameters *)motion;
    adjusted_parameters.vfptr = (PackObjVtbl *)&MovementParameters::vftable;
    adjusted_parameters.action_stamp = v15;
    CMotionInterp::adjust_motion(v3, (unsigned int *)&params, &adjusted_parameters.speed, v12);
    v16 = CMotionInterp::StopInterpretedMotion(v3, (unsigned int)params, &adjusted_parameters);
    if ( !v16 )
    {
      v17 = v6->bitfield;
      if ( BYTE1(v17) & 0x20 )
        RawMotionState::RemoveMotion(&v3->raw_state, motion);
    }
    result = v16;
  }
  else
  {
    result = 8;
  }
  return result;
}
// 7C83F8: using guessed type int (__thiscall *MovementParameters::vftable)(void *, char);

//----- (00528600) --------------------------------------------------------  // acclient.c:344146
void __thiscall CMotionInterp::apply_interpreted_movement(CMotionInterp *this, int cancel_moveto, int disallow_jump)
{
  CMotionInterp *v3; // esi@1
  unsigned int v4; // ST04_4@6
  unsigned int v5; // eax@6
  unsigned int v6; // eax@11
  CPhysicsObj *v7; // ecx@13
  CPhysicsObj *v8; // ecx@17
  MovementParameters params; // [sp+4h] [bp-2Ch]@2

  v3 = this;
  if ( this->physics_obj )
  {
    MovementParameters::MovementParameters(&params);
    params.bitfield = params.bitfield & 0xFFFD37FF | ((cancel_moveto & 1 | 4 * (disallow_jump & 1)) << 15);
    if ( v3->interpreted_state.forward_command == 1140850695 )
      v3->my_run_rate = v3->interpreted_state.forward_speed;
    CMotionInterp::DoInterpretedMotion(v3, v3->interpreted_state.current_style, &params);
    if ( CMotionInterp::contact_allows_move(v3, v3->interpreted_state.forward_command) )
    {
      if ( v3->standing_longjump )
      {
        LODWORD(params.speed) = 1065353216;
        CMotionInterp::DoInterpretedMotion(v3, 0x41000003u, &params);
        CMotionInterp::StopInterpretedMotion(v3, 0x6500000Fu, &params);
      }
      else
      {
        v4 = v3->interpreted_state.forward_command;
        params.speed = v3->interpreted_state.forward_speed;
        CMotionInterp::DoInterpretedMotion(v3, v4, &params);
        v5 = v3->interpreted_state.sidestep_command;
        if ( v5 )
        {
          params.speed = v3->interpreted_state.sidestep_speed;
          CMotionInterp::DoInterpretedMotion(v3, v5, &params);
        }
        else
        {
          CMotionInterp::StopInterpretedMotion(v3, 0x6500000Fu, &params);
        }
      }
    }
    else
    {
      LODWORD(params.speed) = 1065353216;
      CMotionInterp::DoInterpretedMotion(v3, 0x40000015u, &params);
    }
    v6 = v3->interpreted_state.turn_command;
    if ( v6 )
    {
      params.speed = v3->interpreted_state.turn_speed;
      CMotionInterp::DoInterpretedMotion(v3, v6, &params);
    }
    else
    {
      v7 = v3->physics_obj;
      if ( v7 )
      {
        if ( !CPhysicsObj::StopInterpretedMotion(v7, 0x6500000Du, &params) )
        {
          CMotionInterp::add_to_queue(v3, params.context_id, 0x41000003u, 0);
          if ( BYTE1(params.bitfield) & 0x40 )
            InterpretedMotionState::RemoveMotion(&v3->interpreted_state, 0x6500000Du);
        }
        v8 = v3->physics_obj;
        if ( v8 )
        {
          if ( !v8->cell )
            CPhysicsObj::RemoveLinkAnimations(v8);
        }
      }
    }
  }
}

//----- (00528780) --------------------------------------------------------  // acclient.c:344223
signed int __thiscall CMotionInterp::jump(CMotionInterp *this, float extent, int *stamina_adjustment)
{
  CMotionInterp *v3; // esi@1
  CPhysicsObj *v4; // ecx@1
  signed int result; // eax@2
  unsigned int v6; // edi@3
  CPhysicsObj *v7; // ecx@4

  v3 = this;
  v4 = this->physics_obj;
  if ( v4 )
  {
    CPhysicsObj::cancel_moveto(v4);
    result = CMotionInterp::jump_is_allowed(v3, extent, stamina_adjustment);
    v6 = result;
    if ( result )
    {
      v3->standing_longjump = 0;
    }
    else
    {
      v7 = v3->physics_obj;
      v3->jump_extent = extent;
      CPhysicsObj::set_on_walkable(v7, 0);
      result = v6;
    }
  }
  else
  {
    result = 8;
  }
  return result;
}

//----- (005287E0) --------------------------------------------------------  // acclient.c:344258
void __thiscall CMotionInterp::apply_raw_movement(CMotionInterp *this, int cancel_moveto, int disallow_jump)
{
  CMotionInterp *v3; // esi@1
  unsigned int v4; // eax@2
  unsigned int v5; // ecx@2
  float v6; // edx@2
  unsigned int v7; // edx@2

  v3 = this;
  if ( this->physics_obj )
  {
    v4 = this->raw_state.current_style;
    v5 = this->raw_state.forward_command;
    v6 = v3->raw_state.forward_speed;
    v3->interpreted_state.current_style = v4;
    v3->interpreted_state.forward_speed = v6;
    v7 = v3->raw_state.sidestep_command;
    v3->interpreted_state.forward_command = v5;
    v3->interpreted_state.sidestep_command = v7;
    v3->interpreted_state.sidestep_speed = v3->raw_state.sidestep_speed;
    v3->interpreted_state.turn_command = v3->raw_state.turn_command;
    v3->interpreted_state.turn_speed = v3->raw_state.turn_speed;
    CMotionInterp::adjust_motion(
      v3,
      &v3->interpreted_state.forward_command,
      &v3->interpreted_state.forward_speed,
      v3->raw_state.forward_holdkey);
    CMotionInterp::adjust_motion(
      v3,
      &v3->interpreted_state.sidestep_command,
      &v3->interpreted_state.sidestep_speed,
      v3->raw_state.sidestep_holdkey);
    CMotionInterp::adjust_motion(
      v3,
      &v3->interpreted_state.turn_command,
      &v3->interpreted_state.turn_speed,
      v3->raw_state.turn_holdkey);
    CMotionInterp::apply_interpreted_movement(v3, cancel_moveto, disallow_jump);
  }
}

//----- (00528870) --------------------------------------------------------  // acclient.c:344300
void __thiscall CMotionInterp::apply_current_movement(CMotionInterp *this, int cancel_moveto, int disallow_jump)
{
  CMotionInterp *v3; // esi@1
  CWeenieObject *v4; // ecx@3

  v3 = this;
  if ( this->physics_obj && this->initted )
  {
    v4 = this->weenie_obj;
    if ( (!v4 || ((int (*)(void))v4->vfptr[5].__vecDelDtor)()) && CPhysicsObj::movement_is_autonomous(v3->physics_obj) )
      CMotionInterp::apply_raw_movement(v3, cancel_moveto, disallow_jump);
    else
      CMotionInterp::apply_interpreted_movement(v3, cancel_moveto, disallow_jump);
  }
}

//----- (005288D0) --------------------------------------------------------  // acclient.c:344317
void __thiscall CMotionInterp::ReportExhaustion(CMotionInterp *this)
{
  CMotionInterp *v1; // esi@1
  CWeenieObject *v2; // ecx@3

  v1 = this;
  if ( this->physics_obj && this->initted )
  {
    v2 = this->weenie_obj;
    if ( (!v2 || ((int (*)(void))v2->vfptr[5].__vecDelDtor)()) && CPhysicsObj::movement_is_autonomous(v1->physics_obj) )
      CMotionInterp::apply_raw_movement(v1, 0, 0);
    else
      CMotionInterp::apply_interpreted_movement(v1, 0, 0);
  }
}

//----- (00528920) --------------------------------------------------------  // acclient.c:344334
void __thiscall CMotionInterp::SetWeenieObject(CMotionInterp *this, CWeenieObject *_weenie_obj)
{
  CMotionInterp *v2; // esi@1
  CPhysicsObj *v3; // eax@1

  v2 = this;
  v3 = this->physics_obj;
  this->weenie_obj = _weenie_obj;
  if ( v3 && this->initted )
  {
    if ( (!_weenie_obj || ((int (*)(void))_weenie_obj->vfptr[5].__vecDelDtor)())
      && CPhysicsObj::movement_is_autonomous(v2->physics_obj) )
      CMotionInterp::apply_raw_movement(v2, 1, 0);
    else
      CMotionInterp::apply_interpreted_movement(v2, 1, 0);
  }
}

//----- (00528970) --------------------------------------------------------  // acclient.c:344353
void __thiscall CMotionInterp::SetPhysicsObject(CMotionInterp *this, CPhysicsObj *_physics_obj)
{
  CMotionInterp *v2; // esi@1
  CWeenieObject *v3; // ecx@3

  v2 = this;
  this->physics_obj = _physics_obj;
  if ( _physics_obj && this->initted )
  {
    v3 = this->weenie_obj;
    if ( (!v3 || ((int (*)(void))v3->vfptr[5].__vecDelDtor)()) && CPhysicsObj::movement_is_autonomous(v2->physics_obj) )
      CMotionInterp::apply_raw_movement(v2, 1, 0);
    else
      CMotionInterp::apply_interpreted_movement(v2, 1, 0);
  }
}

//----- (005289C0) --------------------------------------------------------  // acclient.c:344371
int __thiscall CMotionInterp::move_to_interpreted_state(CMotionInterp *this, InterpretedMotionState *new_state)
{
  CMotionInterp *v2; // edi@1
  CPhysicsObj *v3; // ecx@1
  int result; // eax@2
  int v5; // esi@3
  LListData *i; // esi@3
  int v7; // eax@4
  int v8; // ecx@4
  int v9; // edx@5
  bool v10; // cf@8
  CWeenieObject *v11; // ecx@11
  MovementParameters params; // [sp+4h] [bp-2Ch]@3

  v2 = this;
  v3 = this->physics_obj;
  if ( v3 )
  {
    v2->raw_state.current_style = new_state->current_style;
    CPhysicsObj::cancel_moveto(v3);
    v5 = CMotionInterp::motion_allows_jump(v2->interpreted_state.forward_command) != 0;
    InterpretedMotionState::copy_movement_from(&v2->interpreted_state, new_state);
    CMotionInterp::apply_current_movement(v2, 1, v5);
    MovementParameters::MovementParameters(&params);
    for ( i = new_state->actions.head_; i; i = i->llist_next )
    {
      v7 = (unsigned int)i[3].llist_next & 0x7FFF;
      v8 = v2->server_action_stamp & 0x7FFF;
      if ( v7 <= (unsigned int)v8 )
        v9 = v8 - v7;
      else
        v9 = v7 - v8;
      if ( (unsigned int)v9 <= 0x3FFF )
        v10 = v8 < (unsigned int)v7;
      else
        v10 = v7 < (unsigned int)v8;
      if ( v10 )
      {
        if ( (v11 = v2->weenie_obj) != 0 && !((int (*)(void))v11->vfptr[5].__vecDelDtor)() || !i[4].llist_next )
        {
          v2->server_action_stamp = (unsigned int)i[3].llist_next;
          LODWORD(params.speed) = i[2].llist_next;
          params.bitfield ^= (LOWORD(params.bitfield) ^ (unsigned __int16)((unsigned __int16)i[4].llist_next << 12)) & 0x1000;
          CMotionInterp::DoInterpretedMotion(v2, (unsigned int)i[1].llist_next, &params);
        }
      }
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00528AC0) --------------------------------------------------------  // acclient.c:344428
void __thiscall CMotionInterp::HitGround(CMotionInterp *this)
{
  CMotionInterp *v1; // esi@1
  CWeenieObject *v2; // ecx@2
  CPhysicsObj *v3; // ecx@4
  unsigned int v4; // eax@5

  v1 = this;
  if ( this->physics_obj )
  {
    v2 = this->weenie_obj;
    if ( !v2 || ((int (*)(void))v2->vfptr[11].__vecDelDtor)() )
    {
      v3 = v1->physics_obj;
      if ( v3 )
      {
        v4 = v3->state;
        if ( BYTE1(v4) & 4 )
        {
          CPhysicsObj::RemoveLinkAnimations(v3);
          CMotionInterp::apply_current_movement(v1, 0, 0);
        }
      }
    }
  }
}

//----- (00528B00) --------------------------------------------------------  // acclient.c:344456
void __thiscall CMotionInterp::LeaveGround(CMotionInterp *this)
{
  CMotionInterp *v1; // esi@1
  CWeenieObject *v2; // ecx@2
  CPhysicsObj *v3; // eax@4
  unsigned int v4; // ecx@5
  CPhysicsObj *v5; // ecx@6
  AC1Legacy::Vector3 local_velocity; // [sp+4h] [bp-Ch]@6

  v1 = this;
  if ( this->physics_obj )
  {
    v2 = this->weenie_obj;
    if ( !v2 || ((int (*)(void))v2->vfptr[11].__vecDelDtor)() )
    {
      v3 = v1->physics_obj;
      if ( v3 )
      {
        v4 = v3->state;
        if ( BYTE1(v4) & 4 )
        {
          CMotionInterp::get_leave_ground_velocity(v1, &local_velocity);
          CPhysicsObj::set_local_velocity(v1->physics_obj, &local_velocity, 1);
          v5 = v1->physics_obj;
          v1->standing_longjump = 0;
          LODWORD(v1->jump_extent) = 0;
          CPhysicsObj::RemoveLinkAnimations(v5);
          CMotionInterp::apply_current_movement(v1, 0, 0);
        }
      }
    }
  }
}

//----- (00528B70) --------------------------------------------------------  // acclient.c:344491
void __thiscall CMotionInterp::set_hold_run(CMotionInterp *this, int val, int cancel_moveto)
{
  if ( (val == 0) != (this->raw_state.current_holdkey != 2) )
  {
    this->raw_state.current_holdkey = (val != 0) + 1;
    CMotionInterp::apply_current_movement(this, cancel_moveto, 0);
  }
}

//----- (00528BB0) --------------------------------------------------------  // acclient.c:344501
void __thiscall CMotionInterp::SetHoldKey(CMotionInterp *this, HoldKey key, int cancel_moveto)
{
  HoldKey v3; // eax@1

  v3 = this->raw_state.current_holdkey;
  if ( key != v3 )
  {
    if ( key == 1 )
    {
      if ( v3 == 2 )
      {
        this->raw_state.current_holdkey = 1;
        CMotionInterp::apply_current_movement(this, cancel_moveto, 0);
      }
    }
    else if ( key == 2 && v3 != 2 )
    {
      this->raw_state.current_holdkey = 2;
      CMotionInterp::apply_current_movement(this, cancel_moveto, 0);
    }
  }
}

//----- (00528C00) --------------------------------------------------------  // acclient.c:344525
CMotionInterp *__cdecl CMotionInterp::Create(CPhysicsObj *_physics_obj, CWeenieObject *_weenie_obj)
{
  void *v2; // eax@1
  void *v3; // esi@1
  CMotionInterp *result; // eax@2

  v2 = operator new(0x88u);
  v3 = v2;
  if ( v2 )
  {
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 2) = 0;
    RawMotionState::RawMotionState((RawMotionState *)((char *)v2 + 12));
    InterpretedMotionState::InterpretedMotionState((InterpretedMotionState *)((char *)v3 + 68));
    *((_DWORD *)v3 + 27) = 1065353216;
    *((_DWORD *)v3 + 31) = 1065353216;
    *((_DWORD *)v3 + 28) = 0;
    *((_DWORD *)v3 + 29) = 0;
    *((_DWORD *)v3 + 30) = 0;
    *((_DWORD *)v3 + 32) = 0;
    *((_DWORD *)v3 + 33) = 0;
    CMotionInterp::SetWeenieObject((CMotionInterp *)v3, _weenie_obj);
    CMotionInterp::SetPhysicsObject((CMotionInterp *)v3, _physics_obj);
    result = (CMotionInterp *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00528C80) --------------------------------------------------------  // acclient.c:344559
void __thiscall CMotionInterp::enter_default_state(CMotionInterp *this)
{
  CMotionInterp *v1; // esi@1
  int v2; // eax@1
  int v3; // eax@1
  void *v4; // eax@1
  LListData *v5; // ecx@4
  RawMotionState v6; // [sp+4h] [bp-38h]@1

  v1 = this;
  RawMotionState::RawMotionState(&v6);
  RawMotionState::operator=(&v1->raw_state, v2);
  RawMotionState::~RawMotionState(&v6);
  InterpretedMotionState::InterpretedMotionState((InterpretedMotionState *)&v6);
  InterpretedMotionState::operator=(&v1->interpreted_state, v3);
  InterpretedMotionState::~InterpretedMotionState((InterpretedMotionState *)&v6);
  CPhysicsObj::InitializeMotionTables(v1->physics_obj);
  v4 = operator new(0x10u);
  if ( v4 )
  {
    *(_DWORD *)v4 = 0;
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = 1090519043;
    *((_DWORD *)v4 + 3) = 0;
  }
  else
  {
    v4 = 0;
  }
  v5 = v1->pending_motions.tail_;
  if ( v5 )
    v5->llist_next = (LListData *)v4;
  else
    v1->pending_motions.head_ = (LListData *)v4;
  v1->pending_motions.tail_ = (LListData *)v4;
  v1->initted = 1;
  CMotionInterp::LeaveGround(v1);
}

//----- (00528D20) --------------------------------------------------------  // acclient.c:344599
signed int __thiscall CMotionInterp::DoMotion(CMotionInterp *this, unsigned int motion, MovementParameters *params)
{
  CMotionInterp *v3; // edi@1
  CPhysicsObj *v4; // ecx@1
  signed int result; // eax@2
  unsigned int v6; // ebp@3
  MovementParameters *v7; // esi@3
  unsigned int v8; // eax@3
  unsigned int v9; // edx@3
  unsigned int v10; // eax@5
  signed int v11; // ebx@19
  unsigned int v12; // eax@20
  MovementParameters adjusted_parameters; // [sp+4h] [bp-2Ch]@3

  v3 = this;
  v4 = this->physics_obj;
  if ( !v4 )
    return 8;
  v6 = motion;
  v7 = params;
  v8 = params->bitfield;
  adjusted_parameters.distance_to_object = params->distance_to_object;
  adjusted_parameters.min_distance = params->min_distance;
  adjusted_parameters.desired_heading = params->desired_heading;
  adjusted_parameters.speed = params->speed;
  adjusted_parameters.fail_distance = params->fail_distance;
  adjusted_parameters.walk_run_threshhold = params->walk_run_threshhold;
  adjusted_parameters.context_id = params->context_id;
  adjusted_parameters.hold_key_to_apply = params->hold_key_to_apply;
  v9 = params->action_stamp;
  adjusted_parameters.vfptr = (PackObjVtbl *)&MovementParameters::vftable;
  adjusted_parameters.bitfield = v8;
  adjusted_parameters.action_stamp = v9;
  if ( SBYTE1(v8) < 0 )
    CPhysicsObj::cancel_moveto(v4);
  v10 = v7->bitfield;
  if ( BYTE1(v10) & 8 )
    CMotionInterp::SetHoldKey(v3, v7->hold_key_to_apply, (v10 >> 15) & 1);
  CMotionInterp::adjust_motion(v3, &motion, &adjusted_parameters.speed, v7->hold_key_to_apply);
  if ( v3->interpreted_state.current_style != -2147483587 )
  {
    if ( v6 == 1090519058 )
      return 63;
    if ( v6 == 1090519059 )
      return 64;
    if ( v6 == 1090519060 )
      return 65;
    if ( v6 & 0x2000000 )
      return 66;
  }
  if ( v6 & 0x10000000 && InterpretedMotionState::GetNumActions(&v3->interpreted_state) >= 6 )
  {
    result = 69;
  }
  else
  {
    v11 = CMotionInterp::DoInterpretedMotion(v3, motion, &adjusted_parameters);
    if ( !v11 )
    {
      v12 = v7->bitfield;
      if ( BYTE1(v12) & 0x20 )
        RawMotionState::ApplyMotion(&v3->raw_state, v6, v7);
    }
    result = v11;
  }
  return result;
}
// 7C83F8: using guessed type int (__thiscall *MovementParameters::vftable)(void *, char);

//----- (00528E80) --------------------------------------------------------  // acclient.c:344669
signed int __thiscall CMotionInterp::PerformMovement(CMotionInterp *this, MovementStruct *mvs)
{
  CMotionInterp *v2; // esi@1
  signed int v3; // edi@2
  signed int result; // eax@2
  signed int v5; // edi@3
  signed int v6; // edi@4
  signed int v7; // edi@5

  v2 = this;
  switch ( mvs->type )
  {
    case 1:
      v3 = CMotionInterp::DoMotion(this, mvs->motion, mvs->params);
      CPhysicsObj::CheckForCompletedMotions(v2->physics_obj);
      result = v3;
      break;
    case 2:
      v5 = CMotionInterp::DoInterpretedMotion(this, mvs->motion, mvs->params);
      CPhysicsObj::CheckForCompletedMotions(v2->physics_obj);
      result = v5;
      break;
    case 3:
      v6 = CMotionInterp::StopMotion(this, mvs->motion, mvs->params);
      CPhysicsObj::CheckForCompletedMotions(v2->physics_obj);
      result = v6;
      break;
    case 4:
      v7 = CMotionInterp::StopInterpretedMotion(this, mvs->motion, mvs->params);
      CPhysicsObj::CheckForCompletedMotions(v2->physics_obj);
      result = v7;
      break;
    case 5:
      CMotionInterp::StopCompletely(this);
      CPhysicsObj::CheckForCompletedMotions(v2->physics_obj);
      result = 0;
      break;
    default:
      result = 71;
      break;
  }
  return result;
}

//----- (006FDAF0) --------------------------------------------------------  // acclient.c:785948
void sub_6FDAF0()
{
  flt_844644 = 1000.0 + 1.0;
}

//----- (006FDB10) --------------------------------------------------------  // acclient.c:785954
void sub_6FDB10()
{
  flt_844648 = 24.0 * 8.0;
}

//----- (006FDB30) --------------------------------------------------------  // acclient.c:785960
void sub_6FDB30()
{
  flt_84464C = 24.0 * 0.5;
}

//----- (006FDB50) --------------------------------------------------------  // acclient.c:785966
int _E101_23()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_14;
  INITIAL_MAX_DATA_RATE_83 = LOWEST_DATA_RATE_14;
  return result;
}

//----- (006FDB60) --------------------------------------------------------  // acclient.c:785976
void sub_6FDB60()
{
  flt_844658 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FDB80) --------------------------------------------------------  // acclient.c:785982
void _E105_29()
{
  dbl_844660 = 1.0 / 30.0;
}

//----- (006FDBA0) --------------------------------------------------------  // acclient.c:785988
void _E107_23()
{
  dbl_844668 = 1.0 / 5.0;
}

//----- (006FDBC0) --------------------------------------------------------  // acclient.c:785994
int sub_6FDBC0()
{
  return atexit(nullsub_1135);
}

