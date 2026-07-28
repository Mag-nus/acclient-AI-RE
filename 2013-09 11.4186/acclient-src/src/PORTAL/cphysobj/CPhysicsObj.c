/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPhysicsObj
   Object     : PORTAL\cphysobj\CPhysicsObj.obj
   Functions  : 336
   Addresses  : 0050E7B0 - 00767940 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0050E7B0) --------------------------------------------------------  // acclient.c:315576
BOOL __thiscall AC1Legacy::Vector3::is_zero(AC1Legacy::Vector3 *this)
{
  return fabs(this->x) < 0.00019999999 && fabs(this->y) < 0.00019999999 && fabs(this->z) < 0.00019999999;
}

//----- (0050E800) --------------------------------------------------------  // acclient.c:315582
int __cdecl LandDefs::within_block(AC1Legacy::Vector3 *vc, float radius)
{
  double v2; // st7@3
  int result; // eax@5

  result = 0;
  if ( vc->x >= (double)radius && vc->y >= (double)radius )
  {
    v2 = flt_843D7C - radius;
    if ( v2 > vc->x && v2 > vc->y )
      result = 1;
  }
  return result;
}

//----- (0050E850) --------------------------------------------------------  // acclient.c:315598
void __thiscall CTransition::init_contact_plane(CTransition *this, unsigned int cell_id, Plane *plane, int is_water)
{
  this->collision_info.last_known_contact_plane_valid = 1;
  this->collision_info.last_known_contact_plane = *plane;
  this->collision_info.last_known_contact_plane_is_water = is_water;
  this->collision_info.last_known_contact_plane_cell_id = cell_id;
  this->collision_info.contact_plane_valid = 1;
  this->collision_info.contact_plane = *plane;
  this->collision_info.contact_plane_is_water = is_water;
  this->collision_info.contact_plane_cell_id = cell_id;
}

//----- (0050E8E0) --------------------------------------------------------  // acclient.c:315611
void __thiscall CTransition::init_last_known_contact_plane(CTransition *this, unsigned int cell_id, Plane *plane, int is_water)
{
  this->collision_info.last_known_contact_plane_valid = 1;
  this->collision_info.last_known_contact_plane = *plane;
  this->collision_info.last_known_contact_plane_is_water = is_water;
  this->collision_info.contact_plane_cell_id = cell_id;
}

//----- (0050E930) --------------------------------------------------------  // acclient.c:315620
BOOL __thiscall CPhysicsObj::makeAnimObject(CPhysicsObj *this, IDClass<_tagDataID,32,0> setup_id, int bCreateParts)
{
  CPhysicsObj *v3; // esi@1
  CPartArray *v4; // eax@1

  v3 = this;
  v4 = CPartArray::CreateSetup(this, setup_id, bCreateParts);
  v3->part_array = v4;
  return v4 != 0;
}

//----- (0050E960) --------------------------------------------------------  // acclient.c:315632
IDClass<_tagDataID,32,0> *__thiscall CPhysicsObj::GetSetupID(CPhysicsObj *this, IDClass<_tagDataID,32,0> *result)
{
  CPartArray *v2; // ecx@1
  IDClass<_tagDataID,32,0> *v3; // eax@2

  v2 = this->part_array;
  if ( v2 )
  {
    CPartArray::GetSetupID(v2, result);
    v3 = result;
  }
  else
  {
    v3 = result;
    result->id = stru_843D84.id;
  }
  return v3;
}

//----- (0050E990) --------------------------------------------------------  // acclient.c:315652
IDClass<_tagDataID,32,0> *__thiscall CPhysicsObj::GetDataID(CPhysicsObj *this, IDClass<_tagDataID,32,0> *result)
{
  CPartArray *v2; // ecx@1
  IDClass<_tagDataID,32,0> *v3; // eax@2

  v2 = this->part_array;
  if ( v2 )
  {
    CPartArray::GetDataID(v2, result);
    v3 = result;
  }
  else
  {
    v3 = result;
    result->id = stru_843D84.id;
  }
  return v3;
}

//----- (0050E9C0) --------------------------------------------------------  // acclient.c:315672
double __thiscall CPhysicsObj::GetRadius(CPhysicsObj *this)
{
  CPartArray *v1; // ecx@1
  double result; // st7@2

  v1 = this->part_array;
  if ( v1 )
    result = CPartArray::GetRadius(v1);
  else
    result = 0.0;
  return result;
}

//----- (0050E9E0) --------------------------------------------------------  // acclient.c:315686
double __thiscall CPhysicsObj::GetHeight(CPhysicsObj *this)
{
  CPartArray *v1; // ecx@1
  double result; // st7@2

  v1 = this->part_array;
  if ( v1 )
    result = CPartArray::GetHeight(v1);
  else
    result = 0.0;
  return result;
}

//----- (0050EA00) --------------------------------------------------------  // acclient.c:315700
double __thiscall CPhysicsObj::GetStepUpHeight(CPhysicsObj *this)
{
  CPartArray *v1; // ecx@1
  double result; // st7@2

  v1 = this->part_array;
  if ( v1 )
    result = CPartArray::GetStepUpHeight(v1);
  else
    result = 0.0;
  return result;
}

//----- (0050EA20) --------------------------------------------------------  // acclient.c:315714
double __thiscall CPhysicsObj::GetStepDownHeight(CPhysicsObj *this)
{
  CPartArray *v1; // ecx@1
  double result; // st7@2

  v1 = this->part_array;
  if ( v1 )
    result = CPartArray::GetStepDownHeight(v1);
  else
    result = 0.0;
  return result;
}

//----- (0050EA40) --------------------------------------------------------  // acclient.c:315728
int __thiscall CPhysicsObj::GetSelectionSphere(CPhysicsObj *this, CSphere *selection_sphere)
{
  CPartArray *v2; // ecx@1
  int result; // eax@2

  v2 = this->part_array;
  if ( v2 )
    result = CPartArray::GetSelectionSphere(v2, selection_sphere);
  else
    result = 0;
  return result;
}

//----- (0050EA60) --------------------------------------------------------  // acclient.c:315742
void __thiscall CPhysicsObj::InitializeMotionTables(CPhysicsObj *this)
{
  CPartArray *v1; // ecx@1

  v1 = this->part_array;
  if ( v1 )
    CPartArray::InitializeMotionTables(v1);
}

//----- (0050EA70) --------------------------------------------------------  // acclient.c:315752
signed int __thiscall CPhysicsObj::DoInterpretedMotion(CPhysicsObj *this, unsigned int motion, MovementParameters *params)
{
  CPartArray *v3; // ecx@1
  signed int result; // eax@1

  v3 = this->part_array;
  result = 71;
  if ( v3 )
    result = CPartArray::DoInterpretedMotion(v3, motion, params);
  return result;
}

//----- (0050EA90) --------------------------------------------------------  // acclient.c:315765
signed int __thiscall CPhysicsObj::StopInterpretedMotion(CPhysicsObj *this, unsigned int motion, MovementParameters *params)
{
  CPartArray *v3; // ecx@1
  signed int result; // eax@1

  v3 = this->part_array;
  result = 71;
  if ( v3 )
    result = CPartArray::StopInterpretedMotion(v3, motion, params);
  return result;
}

//----- (0050EAB0) --------------------------------------------------------  // acclient.c:315778
BOOL __thiscall CPhysicsObj::motions_pending(CPhysicsObj *this)
{
  MovementManager *v1; // ecx@1

  v1 = this->movement_manager;
  return v1 && MovementManager::motions_pending(v1);
}

//----- (0050EAD0) --------------------------------------------------------  // acclient.c:315787
void __thiscall CPhysicsObj::StopCompletely_Internal(CPhysicsObj *this)
{
  CPartArray *v1; // ecx@1

  v1 = this->part_array;
  if ( v1 )
    CPartArray::StopCompletelyInternal(v1);
}

//----- (0050EAE0) --------------------------------------------------------  // acclient.c:315797
void __thiscall CPhysicsObj::unstick_from_object(CPhysicsObj *this)
{
  PositionManager *v1; // ecx@1

  v1 = this->position_manager;
  if ( v1 )
    PositionManager::UnStick(v1);
}

//----- (0050EAF0) --------------------------------------------------------  // acclient.c:315807
unsigned int __thiscall CPhysicsObj::get_sticky_object_id(CPhysicsObj *this)
{
  PositionManager *v1; // ecx@1
  unsigned int result; // eax@2

  v1 = this->position_manager;
  if ( v1 )
    result = PositionManager::GetStickyObjectID(v1);
  else
    result = 0;
  return result;
}

//----- (0050EB10) --------------------------------------------------------  // acclient.c:315821
BOOL __thiscall CPhysicsObj::IsMovingTo(CPhysicsObj *this)
{
  MovementManager *v1; // ecx@1

  v1 = this->movement_manager;
  return v1 && MovementManager::IsMovingTo(v1);
}

//----- (0050EB30) --------------------------------------------------------  // acclient.c:315830
int __thiscall CPhysicsObj::movement_is_autonomous(CPhysicsObj *this)
{
  return this->last_move_was_autonomous;
}

//----- (0050EB40) --------------------------------------------------------  // acclient.c:315836
void __thiscall CPhysicsObj::StopInterpolating(CPhysicsObj *this)
{
  PositionManager *v1; // ecx@1

  v1 = this->position_manager;
  if ( v1 )
    PositionManager::StopInterpolating(v1);
}

//----- (0050EB50) --------------------------------------------------------  // acclient.c:315846
int __thiscall CPhysicsObj::IsInterpolating(CPhysicsObj *this)
{
  PositionManager *v1; // ecx@1
  int result; // eax@2

  v1 = this->position_manager;
  if ( v1 )
    result = PositionManager::IsInterpolating(v1);
  else
    result = 0;
  return result;
}

//----- (0050EB70) --------------------------------------------------------  // acclient.c:315860
double __thiscall CPhysicsObj::GetAutonomyBlipDistance(CPhysicsObj *this)
{
  double result; // st7@3

  if ( this == CPhysicsObj::player_object )
  {
    if ( (this->m_position.objcell_id & 0xFFFF) >= 0x100 )
      result = 25.0;
    else
      result = 100.0;
  }
  else if ( (this->m_position.objcell_id & 0xFFFF) >= 0x100 )
  {
    result = 20.0;
  }
  else
  {
    result = 100.0;
  }
  return result;
}
// 843D58: using guessed type struct CPhysicsObj *CPhysicsObj::player_object;

//----- (0050EBC0) --------------------------------------------------------  // acclient.c:315884
double __thiscall CPhysicsObj::GetStartConstraintDistance(CPhysicsObj *this)
{
  double result; // st7@3

  if ( this == CPhysicsObj::player_object )
  {
    if ( (this->m_position.objcell_id & 0xFFFF) >= 0x100 )
      result = 5.0;
    else
      result = 10.0;
  }
  else if ( (this->m_position.objcell_id & 0xFFFF) >= 0x100 )
  {
    result = 5.0;
  }
  else
  {
    result = 10.0;
  }
  return result;
}
// 843D58: using guessed type struct CPhysicsObj *CPhysicsObj::player_object;

//----- (0050EC10) --------------------------------------------------------  // acclient.c:315908
double __thiscall CPhysicsObj::GetMaxConstraintDistance(CPhysicsObj *this)
{
  double result; // st7@3

  if ( this == CPhysicsObj::player_object )
  {
    if ( (this->m_position.objcell_id & 0xFFFF) >= 0x100 )
      result = 20.0;
    else
      result = 50.0;
  }
  else if ( (this->m_position.objcell_id & 0xFFFF) >= 0x100 )
  {
    result = 20.0;
  }
  else
  {
    result = 50.0;
  }
  return result;
}
// 843D58: using guessed type struct CPhysicsObj *CPhysicsObj::player_object;

//----- (0050EC60) --------------------------------------------------------  // acclient.c:315932
int __thiscall CPhysicsObj::IsFullyConstrained(CPhysicsObj *this)
{
  PositionManager *v1; // ecx@1
  int result; // eax@2

  v1 = this->position_manager;
  if ( v1 )
    result = PositionManager::IsFullyConstrained(v1);
  else
    result = 0;
  return result;
}

//----- (0050EC80) --------------------------------------------------------  // acclient.c:315946
int __thiscall CPhysicsObj::check_attack(CPhysicsObj *this, Position *attacker_pos, const float attacker_scale, AttackCone *attack_cone, float attacker_attack_radius)
{
  CPhysicsObj *v5; // esi@1
  unsigned int v6; // eax@2
  CPartArray *v7; // ecx@4
  CPartArray *v8; // ecx@7
  float attackht; // ST1C_4@10
  float attackrad; // ST18_4@10
  int result; // eax@10
  float target_height; // [sp+Ch] [bp-8h]@5
  float target_radius; // [sp+10h] [bp-4h]@8

  v5 = this;
  if ( this->parent || (v6 = this->state, v6 & 0x10) || v6 & 0x200000 )
  {
    result = 0;
  }
  else
  {
    v7 = this->part_array;
    if ( v7 )
      target_height = CPartArray::GetHeight(v7);
    else
      target_height = 0.0;
    v8 = v5->part_array;
    if ( v8 )
      target_radius = CPartArray::GetRadius(v8);
    else
      target_radius = 0.0;
    attackht = attacker_scale * attack_cone->height;
    attackrad = attacker_scale * attack_cone->radius + attacker_attack_radius;
    result = CSphere::attack(
               &v5->m_position,
               target_radius,
               target_height,
               attacker_pos,
               &attack_cone->left,
               &attack_cone->right,
               attackrad,
               attackht);
  }
  return result;
}

//----- (0050ED30) --------------------------------------------------------  // acclient.c:315991
void __thiscall CPhysicsObj::set_target(CPhysicsObj *this, unsigned int context_id, unsigned int object_id, float radius, long double quantum)
{
  CPhysicsObj *v5; // esi@1
  TargetManager *v6; // eax@2
  TargetManager *v7; // eax@3

  v5 = this;
  if ( !this->target_manager )
  {
    v6 = (TargetManager *)operator new(0x18u);
    if ( v6 )
      TargetManager::TargetManager(v6, v5);
    else
      v7 = 0;
    v5->target_manager = v7;
  }
  TargetManager::SetTarget(v5->target_manager, context_id, object_id, radius, quantum);
}

//----- (0050ED90) --------------------------------------------------------  // acclient.c:316011
void __thiscall CPhysicsObj::clear_target(CPhysicsObj *this)
{
  TargetManager *v1; // ecx@1

  v1 = this->target_manager;
  if ( v1 )
    TargetManager::ClearTarget(v1);
}

//----- (0050EDA0) --------------------------------------------------------  // acclient.c:316021
void __thiscall CPhysicsObj::set_target_quantum(CPhysicsObj *this, long double new_quantum)
{
  TargetManager *v2; // ecx@1

  v2 = this->target_manager;
  if ( v2 )
    TargetManager::SetTargetQuantum(v2, new_quantum);
}

//----- (0050EDC0) --------------------------------------------------------  // acclient.c:316031
double __thiscall CPhysicsObj::get_target_quantum(CPhysicsObj *this)
{
  TargetManager *v1; // eax@1
  TargetInfo *v2; // eax@2
  double result; // st7@3

  v1 = this->target_manager;
  if ( v1 && (v2 = v1->target_info) != 0 )
    result = v2->quantum;
  else
    result = 0.0;
  return result;
}

//----- (0050EDE0) --------------------------------------------------------  // acclient.c:316046
void __thiscall CPhysicsObj::receive_target_update(CPhysicsObj *this, TargetInfo *info)
{
  TargetManager *v2; // ecx@1

  v2 = this->target_manager;
  if ( v2 )
    TargetManager::ReceiveUpdate(v2, info);
}

//----- (0050EE00) --------------------------------------------------------  // acclient.c:316056
void __thiscall CPhysicsObj::add_voyeur(CPhysicsObj *this, unsigned int object_id, float radius, float quantum)
{
  CPhysicsObj *v4; // esi@1
  TargetManager *v5; // eax@2
  TargetManager *v6; // eax@3

  v4 = this;
  if ( !this->target_manager )
  {
    v5 = (TargetManager *)operator new(0x18u);
    if ( v5 )
      TargetManager::TargetManager(v5, v4);
    else
      v6 = 0;
    v4->target_manager = v6;
  }
  TargetManager::AddVoyeur(v4->target_manager, object_id, radius, quantum);
}

//----- (0050EE50) --------------------------------------------------------  // acclient.c:316076
int __thiscall CPhysicsObj::remove_voyeur(CPhysicsObj *this, unsigned int object_id)
{
  TargetManager *v2; // ecx@1
  int result; // eax@2

  v2 = this->target_manager;
  if ( v2 )
    result = TargetManager::RemoveVoyeur(v2, object_id);
  else
    result = 0;
  return result;
}

//----- (0050EE70) --------------------------------------------------------  // acclient.c:316090
void __thiscall CPhysicsObj::calc_friction(CPhysicsObj *this, float quantum, float velocity_mag2)
{
  double v3; // st7@3
  double v4; // st6@4
  double v5; // st5@4
  double v6; // st7@4
  float v7; // ST10_4@4
  double v8; // st7@5
  double v9; // st7@10
  double v10; // st6@11
  double v11; // st5@11
  double v12; // st7@11
  float v13; // ST10_4@11
  long double v14; // st7@12
  float frict; // [sp+4h] [bp-10h]@4

  if ( this->transient_state & 2 )
  {
    if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & this->state )
    {
      v3 = this->m_velocityVector.z * this->contact_plane.N.z
         + this->m_velocityVector.y * this->contact_plane.N.y
         + this->m_velocityVector.x * this->contact_plane.N.x;
      if ( v3 >= 0.25 )
        return;
      frict = 0.2;
      v4 = v3 * this->contact_plane.N.x;
      v5 = v3;
      v6 = v3 * this->contact_plane.N.y;
      v7 = v5 * this->contact_plane.N.z;
      this->m_velocityVector.x = this->m_velocityVector.x - v4;
      this->m_velocityVector.y = this->m_velocityVector.y - v6;
      this->m_velocityVector.z = this->m_velocityVector.z - v7;
      if ( velocity_mag2 >= 1.5625 )
      {
        if ( velocity_mag2 < 6.25 || cos(0.1745329251994329) <= this->contact_plane.N.z )
          frict = this->friction;
        v8 = frict;
      }
      else
      {
        v8 = 1.0;
      }
    }
    else
    {
      v9 = this->contact_plane.N.z * this->m_velocityVector.z
         + this->contact_plane.N.y * this->m_velocityVector.y
         + this->contact_plane.N.x * this->m_velocityVector.x;
      if ( v9 >= 0.25 )
        return;
      v10 = v9 * this->contact_plane.N.x;
      v11 = v9;
      v12 = v9 * this->contact_plane.N.y;
      v13 = v11 * this->contact_plane.N.z;
      this->m_velocityVector.x = this->m_velocityVector.x - v10;
      this->m_velocityVector.y = this->m_velocityVector.y - v12;
      this->m_velocityVector.z = this->m_velocityVector.z - v13;
      v8 = this->friction;
    }
    v14 = pow(1.0 - v8, quantum);
    this->m_velocityVector.x = v14 * this->m_velocityVector.x;
    this->m_velocityVector.y = v14 * this->m_velocityVector.y;
    this->m_velocityVector.z = v14 * this->m_velocityVector.z;
  }
}

//----- (0050F050) --------------------------------------------------------  // acclient.c:316158
signed int __thiscall CPhysicsObj::FindObjCollisions(CPhysicsObj *this, CTransition *transition)
{
  CTransition *v2; // ebx@1
  CPhysicsObj *v3; // esi@1
  unsigned int v4; // eax@1
  CWeenieObject *v5; // ecx@3
  signed int result; // eax@6
  unsigned int v7; // eax@7
  CWeenieObject *v8; // ecx@12
  int v9; // eax@14
  signed int v10; // ebp@15
  int v11; // eax@17
  int v12; // eax@19
  signed int v13; // edi@22
  CWeenieObject *v14; // ecx@23
  CPartArray *v15; // ecx@29
  CPartArray *v16; // ecx@32
  unsigned int v17; // ebx@36
  CPartArray *v18; // ecx@37
  CPartArray *v19; // ecx@39
  CCylSphere *v20; // eax@40
  CPartArray *v21; // ecx@44
  CPartArray *v22; // ecx@49
  CPartArray *v23; // ecx@51
  CSphere *v24; // eax@52
  int v25; // eax@63
  signed int ethereal; // [sp+8h] [bp-Ch]@10
  signed int is_creature; // [sp+Ch] [bp-8h]@22
  float scale; // [sp+10h] [bp-4h]@39
  float scalea; // [sp+10h] [bp-4h]@51
  CTransition *transitiona; // [sp+18h] [bp+4h]@48

  v2 = transition;
  v3 = this;
  v4 = this->state;
  if ( v4 & 4 && v4 & 0x10 )
    return 1;
  v5 = this->weenie_obj;
  if ( v5 )
  {
    if ( transition->object_info.state & 4 && ((int (*)(void))v5->vfptr[11].__vecDelDtor)() )
      return 1;
  }
  v7 = v3->state;
  if ( v7 & 4 || transition->object_info.ethereal && !(v7 & 1) )
  {
    result = 1;
    ethereal = 1;
    if ( transition->sphere_path.step_down )
      return result;
  }
  else
  {
    ethereal = 0;
  }
  transition->sphere_path.obstruction_ethereal = ethereal;
  v8 = v3->weenie_obj;
  if ( !v8
    || !((int (*)(void))v8->vfptr[4].__vecDelDtor)()
    || (v9 = transition->object_info.state, !(BYTE1(v9) & 1))
    || (v10 = 1, (char)v9 < 0)
    || ((int (*)(void))v3->weenie_obj->vfptr[10].__vecDelDtor)()
    || (v11 = transition->object_info.state, BYTE1(v11) & 8) && ((int (*)(void))v3->weenie_obj->vfptr[8].__vecDelDtor)()
    || (v12 = transition->object_info.state, BYTE1(v12) & 0x10)
    && ((int (*)(void))v3->weenie_obj->vfptr[9].__vecDelDtor)() )
    v10 = 0;
  v13 = 1;
  is_creature = 0;
  if ( v3->state & 0x40 || (v14 = v3->weenie_obj) != 0 && ((int (*)(void))v14->vfptr[11].__vecDelDtor)() )
    is_creature = 1;
  if ( !(v3->state & 0x10000) || v10 || OBJECTINFO::missile_ignore(&transition->object_info, v3) )
  {
    v16 = v3->part_array;
    if ( !v16 || !CPartArray::GetNumCylsphere(v16) || v10 || OBJECTINFO::missile_ignore(&transition->object_info, v3) )
    {
      v21 = v3->part_array;
      if ( v21 && CPartArray::GetNumSphere(v21) && !v10 && !OBJECTINFO::missile_ignore(&transition->object_info, v3) )
      {
        transitiona = 0;
        while ( 1 )
        {
          v22 = v3->part_array;
          if ( !v22 || (unsigned int)transitiona >= CPartArray::GetNumSphere(v22) )
            break;
          v23 = v3->part_array;
          scalea = v3->m_scale;
          if ( v23 )
            v24 = CPartArray::GetSphere(v23);
          else
            v24 = 0;
          v13 = CSphere::intersects_sphere((CSphere *)((char *)v24 + v10), &v3->m_position, scalea, v2, is_creature);
          if ( v13 != 1 )
            goto LABEL_57;
          transitiona = (CTransition *)((char *)transitiona + 1);
          v10 += 16;
        }
      }
    }
    else
    {
      v17 = 0;
      while ( 1 )
      {
        v18 = v3->part_array;
        if ( !v18 || v17 >= CPartArray::GetNumCylsphere(v18) )
          break;
        v19 = v3->part_array;
        scale = v3->m_scale;
        if ( v19 )
          v20 = CPartArray::GetCylsphere(v19);
        else
          v20 = 0;
        v13 = CCylSphere::intersects_sphere((CCylSphere *)((char *)v20 + v10), &v3->m_position, scale, transition);
        if ( v13 != 1 )
        {
          v2 = transition;
          goto LABEL_57;
        }
        ++v17;
        v10 += 20;
      }
      v2 = transition;
    }
  }
  else
  {
    v15 = v3->part_array;
    if ( v15 )
    {
      v13 = CPartArray::FindObjCollisions(v15, transition);
      if ( v13 != 1 )
      {
LABEL_57:
        if ( !v2->sphere_path.step_down )
        {
          if ( v3->state & 1 )
          {
            if ( !(v2->object_info.state & 1) )
              v2->collision_info.collided_with_environment = 1;
          }
          else if ( ethereal || is_creature && (v25 = v2->object_info.state, BYTE1(v25) & 4) )
          {
            v13 = 1;
            v2->collision_info.collision_normal_valid = 0;
            COLLISIONINFO::add_object(&v2->collision_info, v3, OK_TS);
          }
          else
          {
            COLLISIONINFO::add_object(&v2->collision_info, v3, (TransitionState)v13);
          }
        }
      }
    }
  }
  result = v13;
  v2->sphere_path.obstruction_ethereal = 0;
  return result;
}

//----- (0050F340) --------------------------------------------------------  // acclient.c:316318
void __thiscall CPhysicsObj::UpdateViewerDistance(CPhysicsObj *this, float _CYpt, AC1Legacy::Vector3 *_viewer_heading)
{
  CPartArray *v3; // ecx@1

  this->CYpt = _CYpt;
  v3 = this->part_array;
  if ( v3 )
    CPartArray::UpdateViewerDistance(v3, _CYpt, _viewer_heading);
}

//----- (0050F360) --------------------------------------------------------  // acclient.c:316329
unsigned int __thiscall CPhysicsObj::create_particle_emitter(CPhysicsObj *this, IDClass<_tagDataID,32,0> emitter_info_id, unsigned int part_index, Frame *offset, unsigned int emitter_id)
{
  CPhysicsObj *v5; // esi@1
  ParticleManager *v6; // eax@2
  ParticleManager *v7; // eax@3

  v5 = this;
  if ( !this->particle_manager )
  {
    v6 = (ParticleManager *)operator new(0xCu);
    if ( v6 )
      ParticleManager::ParticleManager(v6);
    else
      v7 = 0;
    v5->particle_manager = v7;
  }
  return ParticleManager::CreateParticleEmitter(
           v5->particle_manager,
           v5,
           emitter_info_id,
           part_index,
           offset,
           emitter_id);
}

//----- (0050F3B0) --------------------------------------------------------  // acclient.c:316355
unsigned int __thiscall CPhysicsObj::create_blocking_particle_emitter(CPhysicsObj *this, IDClass<_tagDataID,32,0> emitter_info_id, unsigned int part_index, Frame *offset, unsigned int emitter_id)
{
  CPhysicsObj *v5; // esi@1
  ParticleManager *v6; // eax@2
  ParticleManager *v7; // eax@3

  v5 = this;
  if ( !this->particle_manager )
  {
    v6 = (ParticleManager *)operator new(0xCu);
    if ( v6 )
      ParticleManager::ParticleManager(v6);
    else
      v7 = 0;
    v5->particle_manager = v7;
  }
  return ParticleManager::CreateBlockingParticleEmitter(
           v5->particle_manager,
           v5,
           emitter_info_id,
           part_index,
           offset,
           emitter_id);
}

//----- (0050F400) --------------------------------------------------------  // acclient.c:316381
unsigned int __thiscall CPhysicsObj::destroy_particle_emitter(CPhysicsObj *this, unsigned int emitter_id)
{
  ParticleManager *v2; // ecx@1
  unsigned int result; // eax@2

  v2 = this->particle_manager;
  if ( v2 )
    result = ParticleManager::DestroyParticleEmitter(v2, emitter_id);
  else
    result = 0;
  return result;
}

//----- (0050F420) --------------------------------------------------------  // acclient.c:316395
int __thiscall CPhysicsObj::stop_particle_emitter(CPhysicsObj *this, unsigned int emitter_id)
{
  ParticleManager *v2; // ecx@1
  int result; // eax@2

  v2 = this->particle_manager;
  if ( v2 )
    result = ParticleManager::StopParticleEmitter(v2, emitter_id);
  else
    result = 0;
  return result;
}

//----- (0050F440) --------------------------------------------------------  // acclient.c:316409
int __thiscall CPhysicsObj::get_num_emitters(CPhysicsObj *this)
{
  ParticleManager *v1; // ecx@1
  int result; // eax@2

  v1 = this->particle_manager;
  if ( v1 )
    result = ParticleManager::GetNumEmitters(v1);
  else
    result = 0;
  return result;
}

//----- (0050F460) --------------------------------------------------------  // acclient.c:316423
int __thiscall CPhysicsObj::play_sound(CPhysicsObj *this, SoundType sound_type, float volume)
{
  int result; // eax@1

  result = 0;
  if ( this->sound_table )
  {
    SoundManager::PlaySoundA(sound_type, this, volume);
    result = 1;
  }
  return result;
}

//----- (0050F490) --------------------------------------------------------  // acclient.c:316437
HashBaseData<unsigned long> *__cdecl CPhysicsObj::GetObjectA(unsigned int object_id)
{
  HashBaseData<unsigned long> *result; // eax@2

  if ( CPhysicsObj::obj_maint )
    result = CObjectMaint::GetObjectA(CPhysicsObj::obj_maint, object_id);
  else
    result = 0;
  return result;
}

//----- (0050F4B0) --------------------------------------------------------  // acclient.c:316449
void __cdecl CPhysicsObj::SetObjectMaintainer(CObjectMaint *_obj_maint)
{
  CPhysicsObj::obj_maint = _obj_maint;
}

//----- (0050F4C0) --------------------------------------------------------  // acclient.c:316455
void __cdecl CPhysicsObj::SetPlayer(CPhysicsObj *new_player_object)
{
  CPhysicsObj::player_object = new_player_object;
}
// 843D58: using guessed type struct CPhysicsObj *CPhysicsObj::player_object;

//----- (0050F4D0) --------------------------------------------------------  // acclient.c:316462
void __thiscall CPhysicsObj::set_weenie_obj_ptr(CPhysicsObj *this, CWeenieObject *wobj)
{
  MovementManager *v2; // ecx@1

  this->weenie_obj = wobj;
  v2 = this->movement_manager;
  if ( v2 )
    MovementManager::SetWeenieObject(v2, wobj);
}

//----- (0050F4F0) --------------------------------------------------------  // acclient.c:316473
void __thiscall CPhysicsObj::set_cell_id(CPhysicsObj *this, unsigned int new_cell_id)
{
  unsigned int v2; // edx@1
  CPartArray *v3; // ecx@2

  v2 = this->state;
  this->m_position.objcell_id = new_cell_id;
  if ( !(BYTE1(v2) & 0x10) )
  {
    v3 = this->part_array;
    if ( v3 )
      CPartArray::SetCellID(v3, new_cell_id);
  }
}

//----- (0050F520) --------------------------------------------------------  // acclient.c:316489
void __thiscall CPhysicsObj::remove_parts(CPhysicsObj *this, CObjCell *obj_cell)
{
  CPartArray *v2; // ecx@1

  v2 = this->part_array;
  if ( v2 )
    CPartArray::RemoveParts(v2, obj_cell);
}

//----- (0050F530) --------------------------------------------------------  // acclient.c:316499
BOOL __stdcall CPhysicsObj::is_valid_walkable(AC1Legacy::Vector3 *normal)
{
  return normal->z >= (double)PhysicsGlobals::floor_z;
}
// 8EDE5C: using guessed type float PhysicsGlobals::floor_z;

//----- (0050F560) --------------------------------------------------------  // acclient.c:316506
double CPhysicsObj::get_walkable_z()
{
  return PhysicsGlobals::floor_z;
}
// 8EDE5C: using guessed type float PhysicsGlobals::floor_z;

//----- (0050F570) --------------------------------------------------------  // acclient.c:316513
int __thiscall CPhysicsObj::CacheHasPhysicsBSP(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  CPartArray *v2; // ecx@1
  int result; // eax@3

  v1 = this;
  v2 = this->part_array;
  if ( v2 && CPartArray::CacheHasPhysicsBSP(v2) )
  {
    v1->state |= 0x10000u;
    result = 1;
  }
  else
  {
    v1->state &= 0xFFFEFFFF;
    result = 0;
  }
  return result;
}

//----- (0050F5B0) --------------------------------------------------------  // acclient.c:316535
int __thiscall CPhysicsObj::check_contact(CPhysicsObj *this, int contact)
{
  int result; // eax@3

  if ( this->transient_state & 1
    && this->m_velocityVector.z * this->contact_plane.N.z
     + this->m_velocityVector.y * this->contact_plane.N.y
     + this->m_velocityVector.x * this->contact_plane.N.x > 0.00019999999 )
    result = 0;
  else
    result = contact;
  return result;
}

//----- (0050F600) --------------------------------------------------------  // acclient.c:316550
int __stdcall CPhysicsObj::build_collision_profile(ObjCollisionProfile *prof, CPhysicsObj *obj, AC1Legacy::Vector3 *vel, const int amIInContact, const int objIsMissile, const int objHasContact)
{
  CWeenieObject *v7; // ecx@1
  int result; // eax@3

  v7 = obj->weenie_obj;
  if ( v7 && ((int (__stdcall *)(ObjCollisionProfile *))v7->vfptr[23].__vecDelDtor)(prof) )
  {
    prof->id = obj->id;
    prof->velocity = *vel;
    ObjCollisionProfile::SetMissile(prof, objIsMissile);
    ObjCollisionProfile::SetInContact(prof, objHasContact);
    ObjCollisionProfile::SetMeInContact(prof, amIInContact);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0050F670) --------------------------------------------------------  // acclient.c:316573
void __thiscall CPhysicsObj::UpdatePartsInternal(CPhysicsObj *this)
{
  unsigned int v1; // eax@1
  CPartArray *v2; // eax@2

  v1 = this->state;
  if ( !(BYTE1(v1) & 0x10) )
  {
    v2 = this->part_array;
    if ( v2 )
      CPartArray::SetFrame(v2, &this->m_position.frame);
  }
}

//----- (0050F690) --------------------------------------------------------  // acclient.c:316588
int __thiscall CPhysicsObj::SetPlacementFrameInternal(CPhysicsObj *this, unsigned int frame_id)
{
  CPhysicsObj *v2; // esi@1
  CPartArray *v3; // ecx@1
  int v4; // edi@1
  unsigned int v5; // eax@3
  CPartArray *v6; // ecx@4

  v2 = this;
  v3 = this->part_array;
  v4 = 0;
  if ( v3 )
    v4 = CPartArray::SetPlacementFrame(v3, frame_id);
  v5 = v2->state;
  if ( !(BYTE1(v5) & 0x10) )
  {
    v6 = v2->part_array;
    if ( v6 )
      CPartArray::SetFrame(v6, &v2->m_position.frame);
  }
  return v4;
}

//----- (0050F6D0) --------------------------------------------------------  // acclient.c:316612
void __thiscall CPhysicsObj::set_omega(CPhysicsObj *this, AC1Legacy::Vector3 *new_omega, int send_event)
{
  this->m_omegaVector = *new_omega;
}

//----- (0050F6F0) --------------------------------------------------------  // acclient.c:316618
void __thiscall CPhysicsObj::set_sequence_animation(CPhysicsObj *this, IDClass<_tagDataID,32,0> anim_id, int interrupt, unsigned int start_frame, float frame_rate)
{
  CPhysicsObj *v5; // esi@1
  AnimData animdata; // [sp+4h] [bp-14h]@2

  v5 = this;
  if ( this->part_array )
  {
    AnimData::AnimData(&animdata);
    animdata.anim_id.id = anim_id.id;
    animdata.framerate = frame_rate;
    animdata.low_frame = start_frame;
    if ( interrupt )
      CSequence::clear(&v5->part_array->sequence);
    CSequence::append_animation(&v5->part_array->sequence, &animdata);
    WeenieDesc::~WeenieDesc((WeenieDesc *)&animdata);
  }
}

//----- (0050F760) --------------------------------------------------------  // acclient.c:316638
void __thiscall CPhysicsObj::clear_sequence_anims(CPhysicsObj *this)
{
  CPartArray *v1; // eax@1

  v1 = this->part_array;
  if ( v1 )
    CSequence::clear_animations(&v1->sequence);
}

//----- (0050F770) --------------------------------------------------------  // acclient.c:316648
int __thiscall CPhysicsObj::HasAnims(CPhysicsObj *this)
{
  CPartArray *v1; // ecx@1
  int result; // eax@2

  v1 = this->part_array;
  if ( v1 )
    result = CPartArray::HasAnims(v1);
  else
    result = 0;
  return result;
}

//----- (0050F780) --------------------------------------------------------  // acclient.c:316662
unsigned int __thiscall CPhysicsObj::get_curr_frame_number(CPhysicsObj *this)
{
  CPartArray *v1; // eax@1
  unsigned int result; // eax@2

  v1 = this->part_array;
  if ( v1 )
    result = CSequence::get_curr_frame_number(&v1->sequence);
  else
    result = 0;
  return result;
}

//----- (0050F7A0) --------------------------------------------------------  // acclient.c:316676
double __thiscall CPhysicsObj::get_distance_to_object(CPhysicsObj *this, CPhysicsObj *object, int use_cyls)
{
  CPhysicsObj *v3; // esi@1
  CPhysicsObj *v4; // edi@2
  CPartArray *v5; // ecx@2
  CPartArray *v6; // ecx@5
  CPartArray *v7; // ecx@8
  CPartArray *v8; // ecx@11
  float r1; // ST24_4@12
  double result; // st7@12
  float h1; // [sp+4h] [bp-8h]@9
  float objecta; // [sp+10h] [bp+4h]@3
  float use_cylsa; // [sp+14h] [bp+8h]@6

  v3 = this;
  if ( use_cyls )
  {
    v4 = object;
    v5 = object->part_array;
    if ( v5 )
      objecta = CPartArray::GetHeight(v5);
    else
      objecta = 0.0;
    v6 = v4->part_array;
    if ( v6 )
      use_cylsa = CPartArray::GetRadius(v6);
    else
      use_cylsa = 0.0;
    v7 = v3->part_array;
    if ( v7 )
      h1 = CPartArray::GetHeight(v7);
    else
      h1 = 0.0;
    v8 = v3->part_array;
    if ( v8 )
    {
      r1 = CPartArray::GetRadius(v8);
      result = Position::cylinder_distance(r1, h1, &v3->m_position, use_cylsa, objecta, &v4->m_position);
    }
    else
    {
      result = Position::cylinder_distance(0.0, h1, &v3->m_position, use_cylsa, objecta, &v4->m_position);
    }
  }
  else
  {
    result = Position::distance(&this->m_position, &object->m_position);
  }
  return result;
}

//----- (0050F870) --------------------------------------------------------  // acclient.c:316728
int __thiscall CPhysicsObj::add_child(CPhysicsObj *this, CPhysicsObj *obj, unsigned int where)
{
  CPhysicsObj *v3; // edi@1
  int result; // eax@2
  CPartArray *v5; // eax@3
  HashBaseData<unsigned long> *v6; // esi@4
  CHILDLIST *v7; // eax@6
  CHILDLIST *v8; // eax@7

  v3 = this;
  if ( obj == this )
  {
    result = 0;
  }
  else
  {
    v5 = this->part_array;
    if ( v5 && (v6 = CSetup::GetHoldingLocation(v5->setup, where)) != 0 )
    {
      if ( !v3->children )
      {
        v7 = (CHILDLIST *)operator new(0x24u);
        if ( v7 )
          CHILDLIST::CHILDLIST(v7);
        else
          v8 = 0;
        v3->children = v8;
      }
      CHILDLIST::add_child(v3->children, obj, (Frame *)&v6[1].hash_next, (unsigned int)v6[1].vfptr, where);
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (0050F8F0) --------------------------------------------------------  // acclient.c:316768
int __thiscall CPhysicsObj::add_child(CPhysicsObj *this, CPhysicsObj *obj, unsigned int part_index, Frame *frame)
{
  CPhysicsObj *v4; // esi@1
  int result; // eax@2
  CHILDLIST *v6; // eax@7
  CHILDLIST *v7; // eax@8

  v4 = this;
  if ( obj == this )
  {
    result = 0;
  }
  else if ( part_index == -1 || part_index < this->part_array->num_parts )
  {
    if ( !this->children )
    {
      v6 = (CHILDLIST *)operator new(0x24u);
      if ( v6 )
        CHILDLIST::CHILDLIST(v6);
      else
        v7 = 0;
      v4->children = v7;
    }
    CHILDLIST::add_child(v4->children, obj, frame, part_index, 0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0050F960) --------------------------------------------------------  // acclient.c:316802
void __thiscall CPhysicsObj::SetTranslucencyInternal(CPhysicsObj *this, float _translucency)
{
  CPartArray *v2; // ecx@3

  if ( _translucency < (double)this->translucencyOriginal )
    _translucency = this->translucencyOriginal;
  this->translucency = _translucency;
  v2 = this->part_array;
  if ( v2 )
    CPartArray::SetTranslucencyInternal(v2, _translucency);
}

//----- (0050F9A0) --------------------------------------------------------  // acclient.c:316815
void __thiscall CPhysicsObj::SetNoDraw(CPhysicsObj *this, int no_draw)
{
  CPartArray *v2; // ecx@1

  v2 = this->part_array;
  if ( v2 )
    CPartArray::SetNoDrawInternal(v2, no_draw);
}

//----- (0050F9B0) --------------------------------------------------------  // acclient.c:316825
int __thiscall CPhysicsObj::DoObjDescChangesFromDefault(CPhysicsObj *this, ObjDesc *objdesc)
{
  CPhysicsObj *v2; // esi@1
  CPartArray *v3; // ecx@1
  int v4; // edi@1
  CPartArray *v5; // ecx@6
  float objdesca; // [sp+Ch] [bp+4h]@4

  v2 = this;
  v3 = this->part_array;
  v4 = 0;
  if ( v3 )
    v4 = CPartArray::DoObjDescChangesFromDefault(v3, objdesc);
  if ( v2->translucency != 0.0 )
  {
    objdesca = v2->translucency;
    if ( objdesca < (double)v2->translucencyOriginal )
      objdesca = v2->translucencyOriginal;
    v5 = v2->part_array;
    v2->translucency = objdesca;
    if ( v5 )
      CPartArray::SetTranslucencyInternal(v5, objdesca);
  }
  return v4;
}

//----- (0050FA30) --------------------------------------------------------  // acclient.c:316852
int __thiscall CPhysicsObj::DoObjDescChanges(CPhysicsObj *this, ObjDesc *objdesc)
{
  CPhysicsObj *v2; // esi@1
  CPartArray *v3; // ecx@1
  int v4; // edi@1
  CPartArray *v5; // ecx@6
  float objdesca; // [sp+Ch] [bp+4h]@4

  v2 = this;
  v3 = this->part_array;
  v4 = 0;
  if ( v3 )
    v4 = CPartArray::DoObjDescChanges(v3, objdesc);
  if ( v2->translucency != 0.0 )
  {
    objdesca = v2->translucency;
    if ( objdesca < (double)v2->translucencyOriginal )
      objdesca = v2->translucencyOriginal;
    v5 = v2->part_array;
    v2->translucency = objdesca;
    if ( v5 )
      CPartArray::SetTranslucencyInternal(v5, objdesca);
  }
  return v4;
}

//----- (0050FAB0) --------------------------------------------------------  // acclient.c:316879
int __thiscall CPhysicsObj::MorphToExistingObject(CPhysicsObj *this, CPhysicsObj *pObj)
{
  CPhysicsObj *v2; // esi@1
  CPartArray *v3; // ecx@1
  int v4; // edi@1
  double v5; // st7@4
  CPartArray *v6; // ecx@7
  int result; // eax@8
  float pObja; // [sp+10h] [bp+4h]@5

  v2 = this;
  v3 = this->part_array;
  v4 = 0;
  if ( v3 && pObj->part_array )
    v4 = CPartArray::MorphToExistingObject(v3, pObj->part_array);
  v2->translucency = pObj->translucencyOriginal;
  v5 = pObj->translucencyOriginal;
  v2->translucencyOriginal = pObj->translucencyOriginal;
  if ( v2->translucency == 0.0 )
    goto LABEL_12;
  pObja = v2->translucency;
  if ( pObja < v5 )
    pObja = v5;
  v6 = v2->part_array;
  v2->translucency = pObja;
  if ( v6 )
  {
    CPartArray::SetTranslucencyInternal(v6, pObja);
    result = v4;
    v2->m_bExaminationObject = 1;
  }
  else
  {
LABEL_12:
    result = v4;
    v2->m_bExaminationObject = 1;
  }
  return result;
}

//----- (0050FB50) --------------------------------------------------------  // acclient.c:316920
void __thiscall CPhysicsObj::SetTranslucency2(CPhysicsObj *this, float _start_translucency, float _end_translucency, long double delta)
{
  CPhysicsObj *v4; // esi@1
  CPartArray *v5; // ecx@4
  FPHook *v6; // eax@6
  int v7; // eax@7
  PhysicsObjHook *v8; // edx@9
  PhysicsObjHook *i; // ecx@9
  float _start_translucencya; // [sp+8h] [bp+4h]@2

  v4 = this;
  if ( delta >= 0.00019999999 )
  {
    v6 = (FPHook *)operator new(0x38u);
    if ( v6 )
      FPHook::FPHook(v6, CSetup, PhysicsTimer::curr_time, delta, _start_translucency, _end_translucency, 0);
    else
      v7 = 0;
    v8 = v4->hooks;
    for ( i = v4->hooks; i; i = i->next )
      ;
    if ( v8 )
      v8->prev = (PhysicsObjHook *)v7;
    *(_DWORD *)(v7 + 36) = v4->hooks;
    v4->hooks = (PhysicsObjHook *)v7;
  }
  else
  {
    _start_translucencya = _end_translucency;
    if ( _end_translucency < (double)this->translucencyOriginal )
      _start_translucencya = this->translucencyOriginal;
    v5 = this->part_array;
    v4->translucency = _start_translucencya;
    if ( v5 )
      CPartArray::SetTranslucencyInternal(v5, _start_translucencya);
  }
}

//----- (0050FC20) --------------------------------------------------------  // acclient.c:316959
void __thiscall CPhysicsObj::SetTextureVelocity(CPhysicsObj *this, float du, float dv)
{
  CPartArray *v3; // ecx@1

  v3 = this->part_array;
  if ( v3 )
    CPartArray::SetTextureVelocityInternal(v3, du, dv);
}

//----- (0050FC30) --------------------------------------------------------  // acclient.c:316969
void __thiscall CPhysicsObj::SetPartTextureVelocity(CPhysicsObj *this, unsigned int part_index, float du, float dv)
{
  CPartArray *v4; // ecx@1

  v4 = this->part_array;
  if ( v4 )
    CPartArray::SetPartTextureVelocityInternal(v4, part_index, du, dv);
}

//----- (0050FC40) --------------------------------------------------------  // acclient.c:316979
int __thiscall CPhysicsObj::set_active(CPhysicsObj *this, int _active)
{
  int result; // eax@3
  unsigned int v3; // eax@4

  if ( _active )
  {
    if ( this->state & 1 )
    {
      result = 0;
    }
    else
    {
      v3 = this->transient_state;
      if ( (v3 & 0x80u) == 0 )
        *(_QWORD *)&this->update_time = Timer::cur_time;
      this->transient_state = v3 | 0x80;
      result = 1;
    }
  }
  else
  {
    this->transient_state &= 0xFFFFFF7F;
    result = 1;
  }
  return result;
}

//----- (0050FCA0) --------------------------------------------------------  // acclient.c:317008
int __thiscall CPhysicsObj::set_nodraw(CPhysicsObj *this, int nodraw, int send_event)
{
  unsigned int v3; // edx@1
  CPartArray *v4; // ecx@2
  CPartArray *v6; // ecx@4

  v3 = this->state;
  if ( nodraw )
  {
    this->state = v3 | 0x20;
    v4 = this->part_array;
    if ( v4 )
    {
      CPartArray::SetNoDrawInternal(v4, 1);
      return 1;
    }
  }
  else
  {
    this->state = v3 & 0xFFFFFFDF;
    v6 = this->part_array;
    if ( v6 )
      CPartArray::SetNoDrawInternal(v6, 0);
  }
  return 1;
}

//----- (0050FCF0) --------------------------------------------------------  // acclient.c:317036
void __thiscall CPhysicsObj::set_lights(CPhysicsObj *this, int lights_on, int send_event)
{
  unsigned int v3; // edx@1
  CPartArray *v4; // ecx@2
  CPartArray *v5; // ecx@4

  v3 = this->state;
  if ( lights_on )
  {
    this->state = v3 | 0x800;
    v4 = this->part_array;
    if ( v4 )
      CPartArray::InitLights(v4);
  }
  else
  {
    this->state = v3 & 0xFFFFF7FF;
    v5 = this->part_array;
    if ( v5 )
      CPartArray::DestroyLights(v5);
  }
}

//----- (0050FD40) --------------------------------------------------------  // acclient.c:317060
int __thiscall CPhysicsObj::set_elasticity(CPhysicsObj *this, float _elasticity)
{
  int result; // eax@2

  if ( _elasticity >= 0.0 )
  {
    if ( _elasticity <= 0.1 )
    {
      this->elasticity = _elasticity;
      result = 1;
    }
    else
    {
      LODWORD(this->elasticity) = 1036831949;
      result = 1;
    }
  }
  else
  {
    LODWORD(this->elasticity) = 0;
    result = 1;
  }
  return result;
}

//----- (0050FDA0) --------------------------------------------------------  // acclient.c:317086
void __thiscall CPhysicsObj::Hook_AnimDone(CPhysicsObj *this)
{
  CPartArray *v1; // ecx@1

  v1 = this->part_array;
  if ( v1 )
    CPartArray::AnimationDone(v1, 1);
}

//----- (0050FDB0) --------------------------------------------------------  // acclient.c:317096
void __thiscall CPhysicsObj::MotionDone(CPhysicsObj *this, unsigned int motion, int success)
{
  MovementManager *v3; // ecx@1

  v3 = this->movement_manager;
  if ( v3 )
    MovementManager::MotionDone(v3, motion, success);
}

//----- (0050FDD0) --------------------------------------------------------  // acclient.c:317106
void __thiscall CPhysicsObj::report_exhaustion(CPhysicsObj *this)
{
  MovementManager *v1; // ecx@1

  v1 = this->movement_manager;
  if ( v1 )
    MovementManager::ReportExhaustion(v1);
}

//----- (0050FDE0) --------------------------------------------------------  // acclient.c:317116
int __thiscall CPhysicsObj::InqRawMotionState(CPhysicsObj *this)
{
  MovementManager *v1; // ecx@1
  int result; // eax@2

  v1 = this->movement_manager;
  if ( v1 )
    result = MovementManager::InqRawMotionState(v1);
  else
    result = 0;
  return result;
}

//----- (0050FE00) --------------------------------------------------------  // acclient.c:317130
int __thiscall CPhysicsObj::InqInterpretedMotionState(CPhysicsObj *this)
{
  MovementManager *v1; // ecx@1
  int result; // eax@2

  v1 = this->movement_manager;
  if ( v1 )
    result = MovementManager::InqInterpretedMotionState(v1);
  else
    result = 0;
  return result;
}

//----- (0050FE20) --------------------------------------------------------  // acclient.c:317144
void __thiscall CPhysicsObj::RemoveLinkAnimations(CPhysicsObj *this)
{
  CPartArray *v1; // ecx@1

  v1 = this->part_array;
  if ( v1 )
    CPartArray::HandleEnterWorld(v1);
}

//----- (0050FE30) --------------------------------------------------------  // acclient.c:317154
void __thiscall CPhysicsObj::CheckForCompletedMotions(CPhysicsObj *this)
{
  CPartArray *v1; // ecx@1

  v1 = this->part_array;
  if ( v1 )
    CPartArray::CheckForCompletedMotions(v1);
}

//----- (0050FE40) --------------------------------------------------------  // acclient.c:317164
char __thiscall CPhysicsObj::GetBoundingBox(CPhysicsObj *this, BBox *o_bbox)
{
  CPartArray *v2; // ecx@1
  char result; // al@2

  v2 = this->part_array;
  if ( v2 )
  {
    CPartArray::GetBoundingBox(v2, o_bbox);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0050FE60) --------------------------------------------------------  // acclient.c:317183
bool __thiscall CPhysicsObj::ShouldDrawParticles(CPhysicsObj *this, float i_fDegradeDistance)
{
  CObjCell *v2; // ecx@3
  bool result; // al@5

  result = 1;
  if ( !this->m_bExaminationObject )
  {
    if ( this->CYpt > (double)i_fDegradeDistance
      || (v2 = this->cell) == 0
      || !((int (*)(void))v2->vfptr[4].IUnknown_Release)() )
      result = 0;
  }
  return result;
}

//----- (0050FEA0) --------------------------------------------------------  // acclient.c:317200
unsigned int __thiscall AC1Legacy::SmartArray<CAnimHook *>::shrink(AC1Legacy::SmartArray<CAnimHook *> *this)
{
  AC1Legacy::SmartArray<CAnimHook *> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int result; // eax@2
  void *v4; // edi@4
  unsigned int v5; // ecx@9

  v1 = this;
  v2 = this->m_num;
  if ( v2 == this->m_size )
    return 0;
  if ( v2 )
  {
    v4 = operator new[](4 * v2);
    result = 0;
    if ( !v4 )
      return result;
    if ( v1->m_num )
    {
      do
      {
        *((_DWORD *)v4 + result) = v1->m_data[result];
        ++result;
      }
      while ( result < v1->m_num );
    }
  }
  else
  {
    v4 = 0;
  }
  operator delete[](v1->m_data);
  v5 = v1->m_num;
  v1->m_data = (CAnimHook **)v4;
  v1->m_size = v5;
  return 1;
}

//----- (0050FF00) --------------------------------------------------------  // acclient.c:317240
void __thiscall CShadowObj::CShadowObj(CShadowObj *this)
{
  this->hash_next = 0;
  this->id = 0;
  this->vfptr = (HashBaseData<unsigned long>Vtbl *)&CShadowObj::vftable;
  this->physobj = 0;
  this->cell_id = 0;
  this->cell = 0;
}
// 7C6B40: using guessed type int (__thiscall *CShadowObj::vftable)(void *, char);

//----- (0050FF20) --------------------------------------------------------  // acclient.c:317252
void __thiscall CTransition::init_sliding_normal(CTransition *this, AC1Legacy::Vector3 *normal)
{
  CTransition *v2; // esi@1
  char *v3; // edi@1

  v2 = this;
  this->collision_info.sliding_normal_valid = 1;
  v3 = (char *)&this->collision_info.sliding_normal;
  this->collision_info.sliding_normal.x = normal->x;
  this->collision_info.sliding_normal.y = normal->y;
  LODWORD(this->collision_info.sliding_normal.z) = 0;
  if ( AC1Legacy::Vector3::normalize_check_small(&this->collision_info.sliding_normal) )
  {
    *(_DWORD *)v3 = 0;
    LODWORD(v2->collision_info.sliding_normal.y) = 0;
    LODWORD(v2->collision_info.sliding_normal.z) = 0;
  }
}

//----- (0050FF80) --------------------------------------------------------  // acclient.c:317272
int __thiscall CPhysicsObj::InitObjectBegin(CPhysicsObj *this, unsigned int object_iid, int bDynamic)
{
  unsigned int v3; // edx@1
  int result; // eax@1
  unsigned int v5; // edx@2

  this->id = object_iid;
  v3 = this->state;
  result = 1;
  if ( bDynamic )
    v5 = v3 & 0xFFFFFFFE;
  else
    v5 = v3 | 1;
  this->state = v5;
  this->transient_state &= 0xFFFFFF7F;
  *(_QWORD *)&this->update_time = Timer::cur_time;
  return result;
}

//----- (0050FFE0) --------------------------------------------------------  // acclient.c:317292
int __thiscall CPhysicsObj::InitObjectEnd(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  CPartArray *v2; // ecx@1
  unsigned int v3; // eax@3
  CPartArray *v4; // ecx@4

  v1 = this;
  v2 = this->part_array;
  if ( v2 )
    CPartArray::SetPlacementFrame(v2, 0x65u);
  v3 = v1->state;
  if ( !(BYTE1(v3) & 0x10) )
  {
    v4 = v1->part_array;
    if ( v4 )
      CPartArray::SetFrame(v4, &v1->m_position.frame);
  }
  return 1;
}

//----- (00510020) --------------------------------------------------------  // acclient.c:317314
signed int __thiscall CPhysicsObj::DoMotion(CPhysicsObj *this, unsigned int motion, MovementParameters *params, int send_event)
{
  CPhysicsObj *v4; // esi@1
  MovementManager *v5; // ecx@1
  signed int result; // eax@2
  MovementManager *v7; // ecx@3
  MovementStruct mvs; // [sp+4h] [bp-64h]@3

  v4 = this;
  v5 = this->movement_manager;
  v4->last_move_was_autonomous = 1;
  if ( v5 )
  {
    mvs.type = 0;
    mvs.pos.vfptr = (PackObjVtbl *)&Position::vftable;
    mvs.pos.objcell_id = 0;
    LODWORD(mvs.pos.frame.qw) = 1065353216;
    LODWORD(mvs.pos.frame.qx) = 0;
    LODWORD(mvs.pos.frame.qy) = 0;
    LODWORD(mvs.pos.frame.qz) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.x) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.y) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.z) = 0;
    Frame::cache(&mvs.pos.frame);
    mvs.params = params;
    v7 = v4->movement_manager;
    mvs.type = 1;
    mvs.motion = motion;
    result = MovementManager::PerformMovement(v7, &mvs);
  }
  else
  {
    result = 7;
  }
  return result;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (005100D0) --------------------------------------------------------  // acclient.c:317353
signed int __thiscall CPhysicsObj::StopMotion(CPhysicsObj *this, unsigned int motion, MovementParameters *params, int send_event)
{
  CPhysicsObj *v4; // esi@1
  MovementManager *v5; // ecx@1
  signed int result; // eax@2
  MovementManager *v7; // ecx@3
  MovementStruct mvs; // [sp+4h] [bp-64h]@3

  v4 = this;
  v5 = this->movement_manager;
  v4->last_move_was_autonomous = 1;
  if ( v5 )
  {
    mvs.type = 0;
    mvs.pos.vfptr = (PackObjVtbl *)&Position::vftable;
    mvs.pos.objcell_id = 0;
    LODWORD(mvs.pos.frame.qw) = 1065353216;
    LODWORD(mvs.pos.frame.qx) = 0;
    LODWORD(mvs.pos.frame.qy) = 0;
    LODWORD(mvs.pos.frame.qz) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.x) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.y) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.z) = 0;
    Frame::cache(&mvs.pos.frame);
    mvs.params = params;
    v7 = v4->movement_manager;
    mvs.type = 3;
    mvs.motion = motion;
    result = MovementManager::PerformMovement(v7, &mvs);
  }
  else
  {
    result = 7;
  }
  return result;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00510180) --------------------------------------------------------  // acclient.c:317392
void __thiscall CPhysicsObj::StopCompletely(CPhysicsObj *this, int send_event)
{
  CPhysicsObj *v2; // esi@1
  MovementManager *v3; // ecx@2
  MovementStruct mvs; // [sp+4h] [bp-64h]@2

  v2 = this;
  if ( this->movement_manager )
  {
    mvs.type = 0;
    mvs.pos.vfptr = (PackObjVtbl *)&Position::vftable;
    mvs.pos.objcell_id = 0;
    LODWORD(mvs.pos.frame.qw) = 1065353216;
    LODWORD(mvs.pos.frame.qx) = 0;
    LODWORD(mvs.pos.frame.qy) = 0;
    LODWORD(mvs.pos.frame.qz) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.x) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.y) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.z) = 0;
    Frame::cache(&mvs.pos.frame);
    v3 = v2->movement_manager;
    mvs.type = 5;
    MovementManager::PerformMovement(v3, &mvs);
  }
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (005101F0) --------------------------------------------------------  // acclient.c:317420
void __thiscall CPhysicsObj::cancel_moveto(CPhysicsObj *this)
{
  MovementManager *v1; // ecx@1

  v1 = this->movement_manager;
  if ( v1 )
    MovementManager::CancelMoveTo(v1, 0x36u);
}

//----- (00510210) --------------------------------------------------------  // acclient.c:317430
void __thiscall CPhysicsObj::MakePositionManager(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  unsigned int v2; // eax@4
  unsigned int v3; // edx@5

  v1 = this;
  if ( !this->position_manager )
    this->position_manager = PositionManager::Create(this);
  if ( !(v1->state & 1) )
  {
    v2 = v1->transient_state;
    if ( (v2 & 0x80u) == 0 )
    {
      v3 = Timer::cur_time.Param;
      LODWORD(v1->update_time) = Timer::cur_time.Cmd;
      HIDWORD(v1->update_time) = v3;
    }
    v1->transient_state = v2 | 0x80;
  }
}

//----- (00510270) --------------------------------------------------------  // acclient.c:317453
void __thiscall CPhysicsObj::MakeMovementManager(CPhysicsObj *this, int init_motion)
{
  CPhysicsObj *v2; // esi@1
  MovementManager *v3; // eax@2
  unsigned int v4; // eax@5
  unsigned int v5; // edx@6

  v2 = this;
  if ( !this->movement_manager )
  {
    v3 = MovementManager::Create(this, this->weenie_obj);
    v2->movement_manager = v3;
    if ( init_motion )
      MovementManager::EnterDefaultState(v3);
    if ( !(v2->state & 1) )
    {
      v4 = v2->transient_state;
      if ( (v4 & 0x80u) == 0 )
      {
        v5 = Timer::cur_time.Param;
        LODWORD(v2->update_time) = Timer::cur_time.Cmd;
        HIDWORD(v2->update_time) = v5;
      }
      v2->transient_state = v4 | 0x80;
    }
  }
}

//----- (005102E0) --------------------------------------------------------  // acclient.c:317482
void __thiscall CPhysicsObj::MoveToObject_Internal(CPhysicsObj *this, unsigned int object_id, unsigned int top_level_id, float object_radius, float object_height, MovementParameters *params)
{
  CPhysicsObj *v6; // esi@1
  MovementManager *v7; // eax@2
  unsigned int v8; // eax@3
  unsigned int v9; // edx@4
  MovementManager *v10; // ecx@6
  MovementStruct mvs; // [sp+4h] [bp-64h]@6

  v6 = this;
  if ( !this->movement_manager )
  {
    v7 = MovementManager::Create(this, this->weenie_obj);
    v6->movement_manager = v7;
    MovementManager::EnterDefaultState(v7);
    if ( !(v6->state & 1) )
    {
      v8 = v6->transient_state;
      if ( (v8 & 0x80u) == 0 )
      {
        v9 = Timer::cur_time.Param;
        LODWORD(v6->update_time) = Timer::cur_time.Cmd;
        HIDWORD(v6->update_time) = v9;
      }
      v6->transient_state = v8 | 0x80;
    }
  }
  mvs.type = 0;
  mvs.pos.vfptr = (PackObjVtbl *)&Position::vftable;
  mvs.pos.objcell_id = 0;
  LODWORD(mvs.pos.frame.qw) = 1065353216;
  LODWORD(mvs.pos.frame.qx) = 0;
  LODWORD(mvs.pos.frame.qy) = 0;
  LODWORD(mvs.pos.frame.qz) = 0;
  LODWORD(mvs.pos.frame.m_fOrigin.x) = 0;
  LODWORD(mvs.pos.frame.m_fOrigin.y) = 0;
  LODWORD(mvs.pos.frame.m_fOrigin.z) = 0;
  Frame::cache(&mvs.pos.frame);
  mvs.top_level_id = top_level_id;
  mvs.radius = object_radius;
  mvs.object_id = object_id;
  mvs.params = params;
  v10 = v6->movement_manager;
  mvs.type = 6;
  mvs.height = object_height;
  MovementManager::PerformMovement(v10, &mvs);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (005103F0) --------------------------------------------------------  // acclient.c:317532
void __thiscall CPhysicsObj::TurnToObject_Internal(CPhysicsObj *this, unsigned int object_id, unsigned int top_level_id, MovementParameters *params)
{
  CPhysicsObj *v4; // esi@1
  MovementManager *v5; // eax@2
  unsigned int v6; // eax@3
  unsigned int v7; // edx@4
  MovementManager *v8; // ecx@6
  MovementStruct mvs; // [sp+4h] [bp-64h]@6

  v4 = this;
  if ( !this->movement_manager )
  {
    v5 = MovementManager::Create(this, this->weenie_obj);
    v4->movement_manager = v5;
    MovementManager::EnterDefaultState(v5);
    if ( !(v4->state & 1) )
    {
      v6 = v4->transient_state;
      if ( (v6 & 0x80u) == 0 )
      {
        v7 = Timer::cur_time.Param;
        LODWORD(v4->update_time) = Timer::cur_time.Cmd;
        HIDWORD(v4->update_time) = v7;
      }
      v4->transient_state = v6 | 0x80;
    }
  }
  mvs.type = 0;
  mvs.pos.vfptr = (PackObjVtbl *)&Position::vftable;
  mvs.pos.objcell_id = 0;
  LODWORD(mvs.pos.frame.qw) = 1065353216;
  LODWORD(mvs.pos.frame.qx) = 0;
  LODWORD(mvs.pos.frame.qy) = 0;
  LODWORD(mvs.pos.frame.qz) = 0;
  LODWORD(mvs.pos.frame.m_fOrigin.x) = 0;
  LODWORD(mvs.pos.frame.m_fOrigin.y) = 0;
  LODWORD(mvs.pos.frame.m_fOrigin.z) = 0;
  Frame::cache(&mvs.pos.frame);
  mvs.object_id = object_id;
  mvs.top_level_id = top_level_id;
  v8 = v4->movement_manager;
  mvs.type = 8;
  mvs.params = params;
  MovementManager::PerformMovement(v8, &mvs);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (005104F0) --------------------------------------------------------  // acclient.c:317580
void __thiscall CPhysicsObj::InterpolateTo(CPhysicsObj *this, Position *p, int keep_heading)
{
  CPhysicsObj *v3; // esi@1

  v3 = this;
  CPhysicsObj::MakePositionManager(this);
  PositionManager::InterpolateTo(v3->position_manager, p, keep_heading);
}

//----- (00510520) --------------------------------------------------------  // acclient.c:317590
void __thiscall CPhysicsObj::ConstrainTo(CPhysicsObj *this, Position *p, float start_distance, float max_distance)
{
  CPhysicsObj *v4; // esi@1
  PositionManager *v5; // ecx@1

  v4 = this;
  CPhysicsObj::MakePositionManager(this);
  v5 = v4->position_manager;
  if ( v5 )
    PositionManager::ConstrainTo(v5, p, start_distance, max_distance);
}

//----- (00510540) --------------------------------------------------------  // acclient.c:317603
void __thiscall CPhysicsObj::report_attacks(CPhysicsObj *this, AttackInfo *attack_info)
{
  CPhysicsObj *v2; // ebx@1
  CWeenieObject *v3; // ecx@1
  unsigned int v4; // ebp@3
  ObjectInfo *v5; // esi@4
  unsigned int v6; // ecx@5
  int v7; // edx@5
  CWeenieObject *v8; // ecx@5
  AttackManager *v9; // ebx@7
  AtkCollisionProfile prof; // [sp+8h] [bp-Ch]@5

  v2 = this;
  v3 = this->weenie_obj;
  if ( v3 )
    ((void (*)(void))v3->vfptr[24].__vecDelDtor)();
  v4 = 0;
  if ( attack_info->num_objects )
  {
    do
    {
      v5 = &attack_info->object_list.data[v4];
      if ( v2->weenie_obj )
      {
        AtkCollisionProfile::AtkCollisionProfile(&prof);
        v6 = v5->hit_location;
        v7 = attack_info->part_index;
        prof.id = v5->object_id;
        prof.location = v6;
        v8 = v2->weenie_obj;
        prof.part = v7;
        ((void (__stdcall *)(AtkCollisionProfile *))v8->vfptr[21].__vecDelDtor)(&prof);
      }
      ++v4;
    }
    while ( v4 < attack_info->num_objects );
  }
  v9 = v2->attack_manager;
  if ( v9 )
    AttackManager::AttackDone(v9, attack_info);
}

//----- (005105D0) --------------------------------------------------------  // acclient.c:317646
void __thiscall CPhysicsObj::receive_detection_update(CPhysicsObj *this, DetectionInfo *info)
{
  CPhysicsObj *v2; // esi@1
  DetectionManager *v3; // ecx@1
  unsigned int v4; // eax@3
  unsigned int v5; // edx@4

  v2 = this;
  v3 = this->detection_manager;
  if ( v3 )
  {
    DetectionManager::ReceiveDetectionUpdate(v3, info);
    if ( !(v2->state & 1) )
    {
      v4 = v2->transient_state;
      if ( (v4 & 0x80u) == 0 )
      {
        v5 = Timer::cur_time.Param;
        LODWORD(v2->update_time) = Timer::cur_time.Cmd;
        HIDWORD(v2->update_time) = v5;
      }
      v2->transient_state = v4 | 0x80;
    }
  }
}

//----- (00510630) --------------------------------------------------------  // acclient.c:317673
void __thiscall TargetInfo::TargetInfo(TargetInfo *this, TargetInfo *__that)
{
  TargetInfo *v2; // esi@1

  v2 = this;
  this->context_id = __that->context_id;
  this->object_id = __that->object_id;
  this->radius = __that->radius;
  this->quantum = __that->quantum;
  this->target_position.vfptr = (PackObjVtbl *)&Position::vftable;
  this->target_position.objcell_id = __that->target_position.objcell_id;
  Frame::operator=((int)&this->target_position.frame, (int)&__that->target_position.frame);
  v2->interpolated_position.vfptr = (PackObjVtbl *)&Position::vftable;
  v2->interpolated_position.objcell_id = __that->interpolated_position.objcell_id;
  Frame::operator=((int)&v2->interpolated_position.frame, (int)&__that->interpolated_position.frame);
  v2->interpolated_heading.x = __that->interpolated_heading.x;
  v2->interpolated_heading.y = __that->interpolated_heading.y;
  v2->interpolated_heading.z = __that->interpolated_heading.z;
  v2->velocity.x = __that->velocity.x;
  v2->velocity.y = __that->velocity.y;
  v2->velocity.z = __that->velocity.z;
  v2->status = __that->status;
  v2->last_update_time = __that->last_update_time;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00510700) --------------------------------------------------------  // acclient.c:317700
void __thiscall CPhysicsObj::UpdatePhysicsInternal(CPhysicsObj *this, float quantum, Frame *offset_frame)
{
  CPhysicsObj *v3; // edi@1
  char *v4; // esi@1
  Frame *v5; // ebx@1
  double v6; // st7@6
  double v7; // st6@6
  float v8; // ST18_4@6
  float v9; // ST18_4@6
  float v10; // ST1C_4@6
  double v11; // st6@6
  double v12; // st5@6
  unsigned int v13; // eax@8
  double v14; // st7@10
  double v15; // st6@10
  double v16; // st7@10
  double v17; // st6@10
  float velocity_mag2; // [sp+Ch] [bp-28h]@1
  AC1Legacy::Vector3 w; // [sp+1Ch] [bp-18h]@6
  AC1Legacy::Vector3 result; // [sp+28h] [bp-Ch]@3
  Frame *offset_framea; // [sp+3Ch] [bp+8h]@2

  v3 = this;
  v4 = (char *)&this->m_velocityVector;
  v5 = offset_frame;
  velocity_mag2 = this->m_velocityVector.x * this->m_velocityVector.x
                + this->m_velocityVector.y * this->m_velocityVector.y
                + this->m_velocityVector.z * this->m_velocityVector.z;
  if ( velocity_mag2 <= 0.0 )
  {
    if ( !this->movement_manager )
    {
      v13 = this->transient_state;
      if ( v13 & 2 )
        this->transient_state = v13 & 0xFFFFFF7F;
    }
  }
  else
  {
    *(float *)&offset_framea = 50.0 * 50.0;
    if ( velocity_mag2 > (double)*(float *)&offset_framea )
    {
      AC1Legacy::Vector3::normalize(&this->m_velocityVector, &result);
      velocity_mag2 = 50.0 * 50.0;
      *(float *)v4 = 50.0 * *(float *)v4;
      *((float *)v4 + 1) = 50.0 * *((float *)v4 + 1);
      *((float *)v4 + 2) = 50.0 * *((float *)v4 + 2);
    }
    CPhysicsObj::calc_friction(v3, quantum, velocity_mag2);
    if ( velocity_mag2 - 0.25 * 0.25 < 0.00019999999 )
    {
      *(_DWORD *)v4 = 0;
      *((_DWORD *)v4 + 1) = 0;
      *((_DWORD *)v4 + 2) = 0;
    }
    v6 = v3->m_accelerationVector.x * 0.5;
    v7 = v3->m_accelerationVector.y * 0.5;
    w.z = v3->m_accelerationVector.z * 0.5;
    v8 = v6 * quantum;
    v9 = v8 * quantum;
    v10 = v7 * quantum * quantum;
    v11 = quantum * *(float *)v4;
    v12 = quantum * *((float *)v4 + 1);
    result.z = quantum * *((float *)v4 + 2);
    w.x = v11 + v9;
    w.z = result.z + w.z * quantum * quantum;
    v5->m_fOrigin.x = w.x + v5->m_fOrigin.x;
    v5->m_fOrigin.y = v12 + v10 + v5->m_fOrigin.y;
    v5->m_fOrigin.z = w.z + v5->m_fOrigin.z;
  }
  v14 = quantum * v3->m_accelerationVector.x;
  v15 = quantum * v3->m_accelerationVector.y;
  result.z = quantum * v3->m_accelerationVector.z;
  *(float *)v4 = v14 + *(float *)v4;
  *((float *)v4 + 1) = v15 + *((float *)v4 + 1);
  *((float *)v4 + 2) = result.z + *((float *)v4 + 2);
  v16 = quantum * v3->m_omegaVector.x;
  v17 = quantum * v3->m_omegaVector.y;
  result.z = quantum * v3->m_omegaVector.z;
  w.z = result.z;
  w.x = v16;
  w.y = v17;
  Frame::grotate(v5, &w);
}

//----- (00510950) --------------------------------------------------------  // acclient.c:317786
void __thiscall CPhysicsObj::calc_acceleration(CPhysicsObj *this)
{
  unsigned int v1; // eax@1
  char *v2; // eax@4
  char *v3; // ecx@4
  unsigned int v4; // eax@5
  char *v5; // ecx@5
  float v6; // ST08_4@6

  v1 = this->transient_state;
  if ( v1 & 1
    && v1 & 2
    && !((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & this->state) )
  {
    v2 = (char *)&this->m_accelerationVector;
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 2) = 0;
    v3 = (char *)&this->m_omegaVector;
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
  }
  else
  {
    v4 = this->state;
    v5 = (char *)&this->m_accelerationVector;
    if ( BYTE1(v4) & 4 )
    {
      v6 = PhysicsGlobals::gravity;
      *(_DWORD *)v5 = 0;
      *((_DWORD *)v5 + 1) = 0;
      *((float *)v5 + 2) = v6;
    }
    else
    {
      *(_DWORD *)v5 = 0;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
    }
  }
}
// 82122C: using guessed type float PhysicsGlobals::gravity;

//----- (00510A40) --------------------------------------------------------  // acclient.c:317831
int __thiscall CPhysicsObj::ethereal_check_for_collisions(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  unsigned int v2; // ebx@1
  int v3; // edi@2
  CObjCell *v4; // ecx@3
  int result; // eax@6

  v1 = this;
  v2 = 0;
  if ( this->num_shadow_objects )
  {
    v3 = 0;
    while ( 1 )
    {
      v4 = v1->shadow_objects.data[v3].cell;
      if ( v4 )
      {
        if ( CObjCell::check_collisions(v4, v1) )
          break;
      }
      ++v2;
      ++v3;
      if ( v2 >= v1->num_shadow_objects )
        goto LABEL_6;
    }
    result = 1;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (00510A90) --------------------------------------------------------  // acclient.c:317868
int __thiscall CPhysicsObj::report_object_collision_end(CPhysicsObj *this, const unsigned int object_id)
{
  CPhysicsObj *v2; // edi@1
  HashBaseData<unsigned long> *v3; // eax@2
  HashBaseData<unsigned long> *v4; // esi@2
  CWeenieObject *v5; // ecx@5
  HashBaseData<unsigned long>Vtbl *v6; // ecx@8
  int result; // eax@10
  CWeenieObject *v8; // ecx@12

  v2 = this;
  if ( CPhysicsObj::obj_maint && (v3 = CObjectMaint::GetObjectA(CPhysicsObj::obj_maint, object_id), (v4 = v3) != 0) )
  {
    if ( !((unsigned int)v3[14].vfptr & 0x200000) )
    {
      if ( v2->state & 8 )
      {
        v5 = v2->weenie_obj;
        if ( v5 )
          ((void (__stdcall *)(const unsigned int))v5->vfptr[22].__vecDelDtor)(object_id);
      }
      if ( (unsigned int)v4[14].vfptr & 8 )
      {
        v6 = v4[25].vfptr;
        if ( v6 )
          (*((void (__stdcall **)(unsigned int))v6->__vecDelDtor + 22))(v2->id);
      }
    }
    result = 1;
  }
  else
  {
    if ( v2->state & 8 )
    {
      v8 = v2->weenie_obj;
      if ( v8 )
        ((void (__stdcall *)(const unsigned int))v8->vfptr[22].__vecDelDtor)(object_id);
    }
    result = 0;
  }
  return result;
}

//----- (00510B30) --------------------------------------------------------  // acclient.c:317912
void __thiscall CPhysicsObj::UpdateViewerDistance(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  unsigned int v2; // eax@1
  double v3; // st7@4
  double v4; // st6@4
  CPartArray *v5; // ecx@5
  double v6; // st7@8
  CPartArray *v7; // ecx@10
  float _CYpt; // [sp+4h] [bp-20h]@4
  float min_2D_degrade_distance_sq; // [sp+8h] [bp-1Ch]@2
  AC1Legacy::Vector3 viewer_heading; // [sp+Ch] [bp-18h]@4
  float v11; // [sp+18h] [bp-Ch]@8
  float v12; // [sp+1Ch] [bp-8h]@8
  float v13; // [sp+20h] [bp-4h]@8

  v1 = this;
  v2 = this->state;
  if ( BYTE1(v2) & 0x10 )
    min_2D_degrade_distance_sq = Render::particle_distance_2dsq;
  else
    min_2D_degrade_distance_sq = Render::object_distance_2dsq;
  Position::get_offset(&Render::viewer_pos, &viewer_heading, &this->m_position);
  v3 = viewer_heading.y * viewer_heading.y;
  v4 = viewer_heading.x * viewer_heading.x;
  _CYpt = sqrt(viewer_heading.z * viewer_heading.z + v4 + v3);
  v1->CYpt = _CYpt;
  if ( v4 + v3 >= min_2D_degrade_distance_sq )
  {
    if ( _CYpt <= 0.00019999999 )
    {
      v11 = 0.0;
      v12 = 0.0;
      v13 = 1.0;
    }
    else
    {
      v6 = 1.0 / _CYpt;
      viewer_heading.z = v6 * viewer_heading.z;
      v13 = viewer_heading.z;
      v11 = viewer_heading.x * v6;
      v12 = v6 * viewer_heading.y;
    }
    viewer_heading.y = v12;
    v7 = v1->part_array;
    viewer_heading.x = v11;
    viewer_heading.z = v13;
    if ( v7 )
      CPartArray::UpdateViewerDistance(v7, _CYpt, &viewer_heading);
  }
  else
  {
    v5 = v1->part_array;
    if ( v5 )
      CPartArray::UpdateViewerDistance(v5);
  }
}
// 866404: using guessed type float Render::object_distance_2dsq;
// 86B1F8: using guessed type float Render::particle_distance_2dsq;

//----- (00510C50) --------------------------------------------------------  // acclient.c:317973
void __thiscall CPhysicsObj::UpdateViewerDistanceRecursive(CPhysicsObj *this)
{
  CPhysicsObj *v1; // edi@1
  CHILDLIST *v2; // eax@1
  unsigned __int16 v3; // si@2
  CPhysicsObj *v4; // ecx@3

  v1 = this;
  CPhysicsObj::UpdateViewerDistance(this);
  v2 = v1->children;
  if ( v2 )
  {
    v3 = 0;
    if ( v2->num_objects )
    {
      do
      {
        v4 = v2->objects.data[v3];
        if ( v4 )
          CPhysicsObj::UpdateViewerDistanceRecursive(v4);
        v2 = v1->children;
        ++v3;
      }
      while ( v3 < v2->num_objects );
    }
  }
}

//----- (00510C90) --------------------------------------------------------  // acclient.c:318002
void __thiscall CPhysicsObj::DrawRecursive(CPhysicsObj *this)
{
  CPhysicsObj *v1; // edi@1
  CPartArray *v2; // ecx@1
  CHILDLIST *v3; // eax@3
  unsigned __int16 v4; // si@4
  CPhysicsObj *v5; // ecx@5

  v1 = this;
  v2 = this->part_array;
  if ( v2 )
    CPartArray::Draw(v2, &v1->m_position);
  v3 = v1->children;
  if ( v3 )
  {
    v4 = 0;
    if ( v3->num_objects )
    {
      do
      {
        v5 = v3->objects.data[v4];
        if ( v5 )
          CPhysicsObj::DrawRecursive(v5);
        v3 = v1->children;
        ++v4;
      }
      while ( v4 < v3->num_objects );
    }
  }
}

//----- (00510CD0) --------------------------------------------------------  // acclient.c:318034
int __thiscall CPhysicsObj::play_script_internal(CPhysicsObj *this, IDClass<_tagDataID,32,0> script_id)
{
  CPhysicsObj *v2; // esi@1
  int result; // eax@2
  int v4; // edi@3
  ScriptManager *v5; // eax@4
  ScriptManager *v6; // eax@5
  ScriptManager *v7; // ecx@8

  v2 = this;
  if ( script_id.id )
  {
    v4 = 0;
    if ( !this->script_manager )
    {
      v5 = (ScriptManager *)operator new(0x18u);
      if ( v5 )
        ScriptManager::ScriptManager(v5, v2);
      else
        v6 = 0;
      v2->script_manager = v6;
    }
    v7 = v2->script_manager;
    if ( v7 )
      v4 = ScriptManager::AddScript(v7, script_id);
    result = v4;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00510D30) --------------------------------------------------------  // acclient.c:318069
int __thiscall CPhysicsObj::play_script(CPhysicsObj *this, IDClass<_tagDataID,32,0> script_id)
{
  int result; // eax@2

  if ( this->cell )
    result = CPhysicsObj::play_script_internal(this, script_id);
  else
    result = 1;
  return result;
}

//----- (00510D50) --------------------------------------------------------  // acclient.c:318081
void __thiscall CPhysicsObj::destroy_particle_manager(CPhysicsObj *this)
{
  CPhysicsObj *v1; // edi@1
  ParticleManager *v2; // esi@1

  v1 = this;
  v2 = this->particle_manager;
  if ( v2 )
  {
    ParticleManager::~ParticleManager(this->particle_manager);
    operator delete(v2);
    v1->particle_manager = 0;
  }
}

//----- (00510D80) --------------------------------------------------------  // acclient.c:318097
int __thiscall CPhysicsObj::get_landscape_coord(CPhysicsObj *this, int *x, int *y)
{
  return LandDefs::gid_to_lcoord(this->m_position.objcell_id, x, y);
}

//----- (00510DA0) --------------------------------------------------------  // acclient.c:318103
void __thiscall CPhysicsObj::set_cell_id_recursive(CPhysicsObj *this, unsigned int new_cell_id)
{
  CPhysicsObj *v2; // esi@1
  unsigned int v3; // eax@1
  CPartArray *v4; // ecx@2
  CHILDLIST *v5; // eax@4
  unsigned __int16 v6; // di@5
  CPhysicsObj *v7; // ecx@6

  v2 = this;
  v3 = this->state;
  this->m_position.objcell_id = new_cell_id;
  if ( !(BYTE1(v3) & 0x10) )
  {
    v4 = this->part_array;
    if ( v4 )
      CPartArray::SetCellID(v4, new_cell_id);
  }
  v5 = v2->children;
  if ( v5 )
  {
    v6 = 0;
    if ( v5->num_objects )
    {
      do
      {
        v7 = v2->children->objects.data[v6];
        if ( v7 )
          CPhysicsObj::set_cell_id_recursive(v7, new_cell_id);
        ++v6;
      }
      while ( v6 < v2->children->num_objects );
    }
  }
}

//----- (00510E00) --------------------------------------------------------  // acclient.c:318140
void __thiscall CPhysicsObj::AddPartToShadowCells(CPhysicsObj *this, CPhysicsPart *part)
{
  CPhysicsObj *v2; // esi@1
  CObjCell *v3; // eax@1
  unsigned int v4; // edx@3
  unsigned int v5; // ebx@3
  int v6; // edi@4
  CObjCell *v7; // eax@5

  v2 = this;
  v3 = this->cell;
  if ( v3 )
    part->pos.objcell_id = v3->m_DID.id;
  v4 = this->num_shadow_objects;
  v5 = 0;
  if ( v4 )
  {
    v6 = 0;
    do
    {
      v7 = v2->shadow_objects.data[v6].cell;
      if ( v7 )
        v7->vfptr->add_part(&v7->vfptr, part, 0, &v7->pos.frame, v4);
      v4 = v2->num_shadow_objects;
      ++v5;
      ++v6;
    }
    while ( v5 < v4 );
  }
}

//----- (00510E70) --------------------------------------------------------  // acclient.c:318172
void __thiscall CPhysicsObj::RemovePartFromShadowCells(CPhysicsObj *this, CPhysicsPart *part)
{
  CPhysicsObj *v2; // esi@1
  CObjCell *v3; // eax@1
  unsigned int v4; // ebx@3
  int v5; // edi@4
  CObjCell *v6; // eax@5

  v2 = this;
  v3 = this->cell;
  if ( v3 )
    part->pos.objcell_id = v3->m_DID.id;
  v4 = 0;
  if ( this->num_shadow_objects )
  {
    v5 = 0;
    do
    {
      v6 = v2->shadow_objects.data[v5].cell;
      if ( v6 )
        v6->vfptr->remove_part((CPartCell *)&v6->vfptr, part);
      ++v4;
      ++v5;
    }
    while ( v4 < v2->num_shadow_objects );
  }
}

//----- (00510ED0) --------------------------------------------------------  // acclient.c:318201
void __thiscall CPhysicsObj::enter_cell(CPhysicsObj *this, CObjCell *new_cell)
{
  CPhysicsObj *v2; // esi@1
  CHILDLIST *v3; // eax@2
  unsigned __int16 v4; // di@3
  unsigned int v5; // ecx@5
  unsigned int v6; // eax@5
  CPartArray *v7; // ecx@6
  CPartArray *v8; // ecx@8

  v2 = this;
  if ( this->part_array )
  {
    CObjCell::add_object(new_cell, this);
    v3 = v2->children;
    if ( v3 )
    {
      v4 = 0;
      if ( v3->num_objects )
      {
        do
          CPhysicsObj::enter_cell(v2->children->objects.data[v4++], new_cell);
        while ( v4 < v2->children->num_objects );
      }
    }
    v5 = v2->state;
    v6 = new_cell->m_DID.id;
    v2->m_position.objcell_id = v6;
    if ( !(BYTE1(v5) & 0x10) )
    {
      v7 = v2->part_array;
      if ( v7 )
        CPartArray::SetCellID(v7, v6);
    }
    v8 = v2->part_array;
    v2->cell = new_cell;
    if ( v8 )
      CPartArray::AddLightsToCell(v8, new_cell);
  }
}

//----- (00510F50) --------------------------------------------------------  // acclient.c:318243
void __thiscall CPhysicsObj::leave_cell(CPhysicsObj *this, int is_changing_cell)
{
  CPhysicsObj *v2; // esi@1
  CObjCell *v3; // ecx@1
  CHILDLIST *v4; // eax@2
  unsigned __int16 v5; // di@3
  CPartArray *v6; // ecx@5

  v2 = this;
  v3 = this->cell;
  if ( v3 )
  {
    CObjCell::remove_object(v3, v2);
    v4 = v2->children;
    if ( v4 )
    {
      v5 = 0;
      if ( v4->num_objects )
      {
        do
          CPhysicsObj::leave_cell(v2->children->objects.data[v5++], is_changing_cell);
        while ( v5 < v2->children->num_objects );
      }
    }
    v6 = v2->part_array;
    if ( v6 )
      CPartArray::RemoveLightsFromCell(v6, v2->cell);
    v2->cell = 0;
  }
}

//----- (00510FC0) --------------------------------------------------------  // acclient.c:318275
void __thiscall CPhysicsObj::find_bbox_cell_list(CPhysicsObj *this, CELLARRAY *cell_array)
{
  CPhysicsObj *v2; // ebx@1
  unsigned int v3; // edi@3
  CObjCell *v4; // eax@4

  v2 = this;
  cell_array->num_cells = 0;
  cell_array->added_outside = 0;
  CELLARRAY::add_cell(cell_array, this->cell->m_DID.id, this->cell);
  if ( v2->cell )
  {
    if ( v2->part_array )
    {
      v3 = 0;
      if ( cell_array->num_cells )
      {
        do
        {
          v4 = cell_array->cells.data[v3].cell;
          if ( v4 )
            CPartArray::calc_cross_cells_static(v2->part_array, v4, cell_array);
          ++v3;
        }
        while ( v3 < cell_array->num_cells );
      }
    }
  }
}

//----- (00511030) --------------------------------------------------------  // acclient.c:318306
int __thiscall CPhysicsObj::obj_within_block(CPhysicsObj *this)
{
  CPhysicsObj *v1; // ebx@1
  bool v2; // zf@1
  CPartArray *v3; // ecx@1
  CSphere *v4; // esi@3
  double v5; // st7@7
  int v7; // edi@10
  CPartArray *v8; // ecx@12
  unsigned int v9; // ebp@15
  Frame *v10; // esi@16
  CPartArray *v11; // ecx@17
  CCylSphere *v12; // eax@18
  double v13; // st7@20
  double v14; // st6@20
  CPartArray *v15; // ecx@27
  CPartArray *v16; // ecx@29
  CSphere *v17; // esi@30
  int v18; // eax@32
  float num_cylsphere; // [sp+10h] [bp-14h]@5
  unsigned int num_cylspherea; // [sp+10h] [bp-14h]@13
  float v21; // [sp+14h] [bp-10h]@22
  AC1Legacy::Vector3 global_center; // [sp+18h] [bp-Ch]@5

  v1 = this;
  v2 = (this->state & 0x10000) == 0;
  v3 = this->part_array;
  if ( !v2 )
  {
    if ( v3 )
      v4 = CPartArray::GetSortingSphere(v3);
    else
      v4 = &dummy_sphere;
    Frame::localtoglobal(&v1->m_position.frame, &global_center, &v4->center);
    num_cylsphere = v4->radius;
    if ( global_center.x >= (double)num_cylsphere && global_center.y >= (double)num_cylsphere )
    {
      v5 = flt_843D7C - num_cylsphere;
      if ( global_center.x < v5 )
      {
        if ( global_center.y >= v5 )
          return 0;
        return 1;
      }
    }
    return 0;
  }
  v7 = 0;
  if ( v3 && CPartArray::GetNumCylsphere(v3) )
  {
    v8 = v1->part_array;
    if ( v8 )
      num_cylspherea = CPartArray::GetNumCylsphere(v8);
    else
      num_cylspherea = 0;
    v9 = 0;
    if ( num_cylspherea > 0 )
    {
      v10 = CPhysicsObj::get_frame(v1);
      while ( 1 )
      {
        v11 = v1->part_array;
        v12 = v11 ? CPartArray::GetCylsphere(v11) : 0;
        v13 = v10->m_fl2gv[3] * v12[v7].low_pt.y
            + v12[v7].low_pt.z * v10->m_fl2gv[6]
            + v10->m_fl2gv[0] * v12[v7].low_pt.x
            + v10->m_fOrigin.x;
        global_center.y = v10->m_fl2gv[4] * v12[v7].low_pt.y
                        + v10->m_fl2gv[1] * v12[v7].low_pt.x
                        + v10->m_fl2gv[7] * v12[v7].low_pt.z
                        + v10->m_fOrigin.y;
        v14 = v12[v7].radius;
        if ( v13 < v14 )
          break;
        if ( global_center.y < v14 )
          break;
        v21 = flt_843D7C - v14;
        if ( v13 >= v21 || global_center.y >= (double)v21 )
          break;
        ++v9;
        ++v7;
        if ( v9 >= num_cylspherea )
          return 1;
      }
      return 0;
    }
  }
  else
  {
    v15 = v1->part_array;
    if ( v15 && CPartArray::GetNumSphere(v15) )
    {
      v16 = v1->part_array;
      if ( v16 )
        v17 = CPartArray::GetSortingSphere(v16);
      else
        v17 = &dummy_sphere;
      Frame::localtoglobal(&v1->m_position.frame, &global_center, &v17->center);
      v18 = LandDefs::within_block(&global_center, v17->radius);
    }
    else
    {
      v18 = LandDefs::within_block(&v1->m_position.frame.m_fOrigin, 0.0);
    }
    if ( !v18 )
      return 0;
  }
  return 1;
}

//----- (00511230) --------------------------------------------------------  // acclient.c:318417
void __thiscall CPhysicsObj::remove_shadows_from_cells(CPhysicsObj *this)
{
  CPhysicsObj *v1; // edi@1
  unsigned int v2; // ebp@1
  int v3; // ebx@2
  CShadowObj *v4; // eax@3
  CObjCell *v5; // esi@3
  CShadowObj *v6; // eax@3
  CPartArray *v7; // ecx@4
  unsigned int v8; // esi@7
  CHILDLIST *v9; // eax@8
  unsigned __int16 v10; // cx@9

  v1 = this;
  v2 = 0;
  if ( this->num_shadow_objects )
  {
    v3 = 0;
    do
    {
      v4 = v1->shadow_objects.data;
      v5 = v4[v3].cell;
      v6 = &v4[v3];
      if ( v5 )
      {
        CObjCell::remove_shadow_object(v5, v6);
        v7 = v1->part_array;
        if ( v7 )
          CPartArray::RemoveParts(v7, v5);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < v1->num_shadow_objects );
  }
  v8 = 0;
  v1->num_shadow_objects = 0;
  while ( 1 )
  {
    v9 = v1->children;
    v10 = v9 ? v9->num_objects : 0;
    if ( v8 >= v10 )
      break;
    if ( v9 )
    {
      CPhysicsObj::remove_shadows_from_cells(v9->objects.data[(unsigned __int16)v8++]);
    }
    else
    {
      CPhysicsObj::remove_shadows_from_cells(0);
      ++v8;
    }
  }
}

//----- (005112C0) --------------------------------------------------------  // acclient.c:318473
int __thiscall CPhysicsObj::is_completely_visible(CPhysicsObj *this)
{
  unsigned int v2; // esi@3
  unsigned int v3; // edx@5
  char *v4; // eax@6

  if ( !this->cell )
    return 0;
  v2 = this->num_shadow_objects;
  if ( !v2 )
    return 0;
  v3 = 0;
  if ( v2 )
  {
    v4 = (char *)&this->shadow_objects.data->cell;
    while ( *(_DWORD *)v4 )
    {
      ++v3;
      v4 += 24;
      if ( v3 >= v2 )
        return 1;
    }
    return 0;
  }
  return 1;
}

//----- (00511310) --------------------------------------------------------  // acclient.c:318501
void __thiscall CPhysicsObj::set_on_walkable(CPhysicsObj *this, int is_on_walkable)
{
  CPhysicsObj *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // ecx@1
  unsigned int v5; // eax@2
  MovementManager *v6; // ecx@6
  MovementManager *v7; // ecx@9

  v2 = this;
  v3 = this->transient_state;
  v4 = this->transient_state & 2;
  if ( is_on_walkable )
    v5 = v3 | 2;
  else
    v5 = v3 & 0xFFFFFFFD;
  v2->transient_state = v5;
  if ( v4 )
  {
    if ( !is_on_walkable )
    {
      v6 = v2->movement_manager;
      if ( v6 )
      {
        MovementManager::LeaveGround(v6);
        CPhysicsObj::calc_acceleration(v2);
        return;
      }
    }
  }
  else if ( is_on_walkable )
  {
    v7 = v2->movement_manager;
    if ( v7 )
      MovementManager::HitGround(v7);
  }
  CPhysicsObj::calc_acceleration(v2);
}

//----- (00511380) --------------------------------------------------------  // acclient.c:318541
int __thiscall CPhysicsObj::SetPlacementFrame(CPhysicsObj *this, unsigned int frame_id, int send_event)
{
  CPhysicsObj *v3; // esi@1
  CPartArray *v4; // ecx@1
  int v5; // edi@1
  unsigned int v6; // eax@3
  CPartArray *v7; // ecx@4

  v3 = this;
  v4 = this->part_array;
  v5 = 0;
  if ( v4 )
    v5 = CPartArray::SetPlacementFrame(v4, frame_id);
  v6 = v3->state;
  if ( !(BYTE1(v6) & 0x10) )
  {
    v7 = v3->part_array;
    if ( v7 )
      CPartArray::SetFrame(v7, &v3->m_position.frame);
  }
  return v5;
}

//----- (005113C0) --------------------------------------------------------  // acclient.c:318565
AC1Legacy::Vector3 *__thiscall CPhysicsObj::get_velocity(CPhysicsObj *this, AC1Legacy::Vector3 *result)
{
  AC1Legacy::Vector3 *v2; // eax@1

  v2 = result;
  result->x = this->cached_velocity.x;
  result->y = this->cached_velocity.y;
  result->z = this->cached_velocity.z;
  return v2;
}

//----- (005113F0) --------------------------------------------------------  // acclient.c:318577
void __thiscall CPhysicsObj::set_velocity(CPhysicsObj *this, AC1Legacy::Vector3 *new_velocity, int send_event)
{
  CPhysicsObj *v3; // edi@1
  char *v4; // esi@1
  double v5; // st7@2
  unsigned __int8 v7; // c0@2
  unsigned __int8 v8; // c2@2
  unsigned int v9; // eax@6
  unsigned int v10; // edx@7
  AC1Legacy::Vector3 result; // [sp+Ch] [bp-Ch]@3

  v3 = this;
  v4 = (char *)&this->m_velocityVector;
  if ( (unsigned __int8)Vector3::operator!=((Vector3 *)&new_velocity->x, (Vector3 *)&this->m_velocityVector.x) )
  {
    *(AC1Legacy::Vector3 *)v4 = *new_velocity;
    v5 = *((float *)v4 + 2);
    if ( v7 | v8 )
    {
      AC1Legacy::Vector3::normalize((AC1Legacy::Vector3 *)v4, &result);
      *(float *)v4 = 50.0 * *(float *)v4;
      *((float *)v4 + 1) = 50.0 * *((float *)v4 + 1);
      *((float *)v4 + 2) = 50.0 * *((float *)v4 + 2);
    }
    v3->jumped_this_frame = 1;
  }
  if ( !(v3->state & 1) )
  {
    v9 = v3->transient_state;
    if ( (v9 & 0x80u) == 0 )
    {
      v10 = Timer::cur_time.Param;
      LODWORD(v3->update_time) = Timer::cur_time.Cmd;
      HIDWORD(v3->update_time) = v10;
    }
    v3->transient_state = v9 | 0x80;
  }
}

//----- (005114D0) --------------------------------------------------------  // acclient.c:318617
void __thiscall CPhysicsObj::set_local_velocity(CPhysicsObj *this, AC1Legacy::Vector3 *new_velocity, int send_event)
{
  AC1Legacy::Vector3 new_global_velocity; // [sp+0h] [bp-Ch]@1

  new_global_velocity.x = this->m_position.frame.m_fl2gv[0] * new_velocity->x
                        + this->m_position.frame.m_fl2gv[3] * new_velocity->y
                        + this->m_position.frame.m_fl2gv[6] * new_velocity->z;
  new_global_velocity.y = this->m_position.frame.m_fl2gv[1] * new_velocity->x
                        + this->m_position.frame.m_fl2gv[4] * new_velocity->y
                        + this->m_position.frame.m_fl2gv[7] * new_velocity->z;
  new_global_velocity.z = this->m_position.frame.m_fl2gv[2] * new_velocity->x
                        + this->m_position.frame.m_fl2gv[5] * new_velocity->y
                        + this->m_position.frame.m_fl2gv[8] * new_velocity->z;
  CPhysicsObj::set_velocity(this, &new_global_velocity, send_event);
}

//----- (00511540) --------------------------------------------------------  // acclient.c:318634
double __thiscall CPhysicsObj::get_heading(CPhysicsObj *this)
{
  return Frame::get_heading(&this->m_position.frame);
}

//----- (00511550) --------------------------------------------------------  // acclient.c:318640
void __thiscall CPhysicsObj::process_hooks(CPhysicsObj *this)
{
  CPhysicsObj *v1; // edi@1
  PhysicsObjHook *v2; // esi@1
  PhysicsObjHook *v3; // ebx@2
  PhysicsObjHook *v4; // eax@3
  PhysicsObjHook *v5; // eax@5
  unsigned int v6; // eax@10
  unsigned int v7; // esi@11

  v1 = this;
  v2 = this->hooks;
  if ( v2 )
  {
    do
    {
      v3 = v2->next;
      if ( v2->vfptr->Execute(v2, v1) )
      {
        v4 = v2->next;
        if ( v4 )
          v4->prev = v2->prev;
        v5 = v2->prev;
        if ( v5 )
          v5->next = v2->next;
        else
          v1->hooks = v2->next;
        v2->prev = 0;
        v2->next = 0;
        v2->vfptr = (PhysicsObjHookVtbl *)&PhysicsObjHook::vftable;
        operator delete(v2);
      }
      v2 = v3;
    }
    while ( v3 );
  }
  v6 = v1->anim_hooks.m_num;
  if ( v6 > 0 )
  {
    v7 = 0;
    if ( v6 > 0 )
    {
      do
        ((void (__stdcall *)(CPhysicsObj *))v1->anim_hooks.m_data[v7++]->vfptr->Execute)(v1);
      while ( v7 < v1->anim_hooks.m_num );
    }
    AC1Legacy::SmartArray<CAnimHook *>::shrink(&v1->anim_hooks);
    v1->anim_hooks.m_num = 0;
  }
}
// 7C6B20: using guessed type void *PhysicsObjHook::vftable;

//----- (005115F0) --------------------------------------------------------  // acclient.c:318693
void __thiscall CPhysicsObj::SetTranslucency(CPhysicsObj *this, float _translucency, long double delta)
{
  CPhysicsObj *v3; // esi@1
  CPartArray *v4; // ecx@4
  FPHook *v5; // eax@6
  int v6; // eax@7
  PhysicsObjHook *v7; // edx@9
  PhysicsObjHook *i; // ecx@9
  float deltaa; // [sp+Ch] [bp+8h]@2

  v3 = this;
  if ( delta >= 0.00019999999 )
  {
    v5 = (FPHook *)operator new(0x38u);
    if ( v5 )
      FPHook::FPHook(v5, CSetup, PhysicsTimer::curr_time, delta, 0.0, _translucency, 0);
    else
      v6 = 0;
    v7 = v3->hooks;
    for ( i = v3->hooks; i; i = i->next )
      ;
    if ( v7 )
      v7->prev = (PhysicsObjHook *)v6;
    *(_DWORD *)(v6 + 36) = v3->hooks;
    v3->hooks = (PhysicsObjHook *)v6;
  }
  else
  {
    deltaa = _translucency;
    if ( _translucency < (double)this->translucencyOriginal )
      deltaa = this->translucencyOriginal;
    v4 = this->part_array;
    v3->translucency = deltaa;
    if ( v4 )
      CPartArray::SetTranslucencyInternal(v4, deltaa);
  }
}

//----- (005116C0) --------------------------------------------------------  // acclient.c:318732
void __thiscall CPhysicsObj::SetTranslucencyHierarchical(CPhysicsObj *this, float _translucency)
{
  CPhysicsObj *v2; // edi@1
  CPartArray *v3; // ecx@3
  unsigned __int16 i; // si@5
  CHILDLIST *v5; // eax@6
  float v6; // [sp+0h] [bp-4h]@1

  v2 = this;
  v6 = _translucency;
  if ( _translucency < (double)this->translucencyOriginal )
    v6 = this->translucencyOriginal;
  v3 = this->part_array;
  v2->translucency = v6;
  if ( v3 )
    CPartArray::SetTranslucencyInternal(v3, v6);
  for ( i = 0; ; ++i )
  {
    v5 = v2->children;
    if ( !v5 || i >= v5->num_objects )
      break;
    CPhysicsObj::SetTranslucencyHierarchical(v5->objects.data[i], _translucency);
  }
}

//----- (00511730) --------------------------------------------------------  // acclient.c:318758
void __thiscall CPhysicsObj::SetPartTranslucency(CPhysicsObj *this, unsigned int part_index, float start_trans, float end_trans, long double delta)
{
  CPhysicsObj *v5; // esi@1
  CPartArray *v6; // ecx@2
  FPHook *v7; // eax@4
  int v8; // eax@5
  PhysicsObjHook *v9; // edx@7
  PhysicsObjHook *i; // ecx@7

  v5 = this;
  if ( delta >= 0.00019999999 )
  {
    v7 = (FPHook *)operator new(0x38u);
    if ( v7 )
      FPHook::FPHook(v7, MTABLE, PhysicsTimer::curr_time, delta, start_trans, end_trans, (void *)part_index);
    else
      v8 = 0;
    v9 = v5->hooks;
    for ( i = v5->hooks; i; i = i->next )
      ;
    if ( v9 )
      v9->prev = (PhysicsObjHook *)v8;
    *(_DWORD *)(v8 + 36) = v5->hooks;
    v5->hooks = (PhysicsObjHook *)v8;
  }
  else
  {
    v6 = this->part_array;
    if ( v6 )
      CPartArray::SetPartTranslucencyInternal(v6, part_index, end_trans);
  }
}

//----- (005117E0) --------------------------------------------------------  // acclient.c:318792
void __thiscall CPhysicsObj::SetPartLuminosity(CPhysicsObj *this, unsigned int part, float start, float end, long double delta)
{
  CPhysicsObj *v5; // esi@1
  CPartArray *v6; // ecx@2
  FPHook *v7; // eax@4
  int v8; // eax@5
  PhysicsObjHook *v9; // edx@7
  PhysicsObjHook *i; // ecx@7

  v5 = this;
  if ( delta >= 0.00019999999 )
  {
    v7 = (FPHook *)operator new(0x38u);
    if ( v7 )
      FPHook::FPHook(v7, VELOCITY|CSetup, PhysicsTimer::curr_time, delta, start, end, (void *)part);
    else
      v8 = 0;
    v9 = v5->hooks;
    for ( i = v5->hooks; i; i = i->next )
      ;
    if ( v9 )
      v9->prev = (PhysicsObjHook *)v8;
    *(_DWORD *)(v8 + 36) = v5->hooks;
    v5->hooks = (PhysicsObjHook *)v8;
  }
  else
  {
    v6 = this->part_array;
    if ( v6 )
      CPartArray::SetPartLuminosityInternal(v6, part, end);
  }
}

//----- (00511890) --------------------------------------------------------  // acclient.c:318826
void __thiscall CPhysicsObj::SetLuminosity(CPhysicsObj *this, float start, float end, long double delta)
{
  CPhysicsObj *v4; // esi@1
  CPartArray *v5; // ecx@2
  FPHook *v6; // eax@4
  int v7; // eax@5
  PhysicsObjHook *v8; // edx@7
  PhysicsObjHook *i; // ecx@7

  v4 = this;
  if ( delta >= 0.00019999999 )
  {
    v6 = (FPHook *)operator new(0x38u);
    if ( v6 )
      FPHook::FPHook(v6, MTABLE|CSetup, PhysicsTimer::curr_time, delta, start, end, 0);
    else
      v7 = 0;
    v8 = v4->hooks;
    for ( i = v4->hooks; i; i = i->next )
      ;
    if ( v8 )
      v8->prev = (PhysicsObjHook *)v7;
    *(_DWORD *)(v7 + 36) = v4->hooks;
    v4->hooks = (PhysicsObjHook *)v7;
  }
  else
  {
    v5 = this->part_array;
    if ( v5 )
      CPartArray::SetLuminosityInternal(v5, end);
  }
}

//----- (00511930) --------------------------------------------------------  // acclient.c:318860
void __thiscall CPhysicsObj::SetPartDiffusion(CPhysicsObj *this, unsigned int part, float start, float end, long double delta)
{
  CPhysicsObj *v5; // esi@1
  CPartArray *v6; // ecx@2
  FPHook *v7; // eax@4
  int v8; // eax@5
  PhysicsObjHook *v9; // edx@7
  PhysicsObjHook *i; // ecx@7

  v5 = this;
  if ( delta >= 0.00019999999 )
  {
    v7 = (FPHook *)operator new(0x38u);
    if ( v7 )
      FPHook::FPHook(v7, VELOCITY|MTABLE, PhysicsTimer::curr_time, delta, start, end, (void *)part);
    else
      v8 = 0;
    v9 = v5->hooks;
    for ( i = v5->hooks; i; i = i->next )
      ;
    if ( v9 )
      v9->prev = (PhysicsObjHook *)v8;
    *(_DWORD *)(v8 + 36) = v5->hooks;
    v5->hooks = (PhysicsObjHook *)v8;
  }
  else
  {
    v6 = this->part_array;
    if ( v6 )
      CPartArray::SetPartDiffusionInternal(v6, part, end);
  }
}

//----- (005119E0) --------------------------------------------------------  // acclient.c:318894
void __thiscall CPhysicsObj::SetDiffusion(CPhysicsObj *this, float start, float end, long double delta)
{
  CPhysicsObj *v4; // esi@1
  CPartArray *v5; // ecx@2
  FPHook *v6; // eax@4
  int v7; // eax@5
  PhysicsObjHook *v8; // edx@7
  PhysicsObjHook *i; // ecx@7

  v4 = this;
  if ( delta >= 0.00019999999 )
  {
    v6 = (FPHook *)operator new(0x38u);
    if ( v6 )
      FPHook::FPHook(v6, VELOCITY, PhysicsTimer::curr_time, delta, start, end, 0);
    else
      v7 = 0;
    v8 = v4->hooks;
    for ( i = v4->hooks; i; i = i->next )
      ;
    if ( v8 )
      v8->prev = (PhysicsObjHook *)v7;
    *(_DWORD *)(v7 + 36) = v4->hooks;
    v4->hooks = (PhysicsObjHook *)v7;
  }
  else
  {
    v5 = this->part_array;
    if ( v5 )
      CPartArray::SetDiffusionInternal(v5, end);
  }
}

//----- (00511A80) --------------------------------------------------------  // acclient.c:318928
void __thiscall CPhysicsObj::SetLighting(CPhysicsObj *this, float luminosity, float diffuse)
{
  CPartArray *v3; // ecx@1

  v3 = this->part_array;
  if ( v3 )
    CPartArray::SetLightingInternal(v3, luminosity, diffuse);
}

//----- (00511A90) --------------------------------------------------------  // acclient.c:318938
int __thiscall CPhysicsObj::SetPartLighting(CPhysicsObj *this, unsigned int part_index, float luminosity, float diffuse)
{
  CPartArray *v4; // ecx@1
  int result; // eax@2

  v4 = this->part_array;
  if ( v4 )
    result = CPartArray::SetPartLightingInternal(v4, part_index, luminosity, diffuse);
  else
    result = 0;
  return result;
}

//----- (00511AB0) --------------------------------------------------------  // acclient.c:318952
void __thiscall CPhysicsObj::RestoreLighting(CPhysicsObj *this)
{
  CPartArray *v1; // ecx@1

  v1 = this->part_array;
  if ( v1 )
    CPartArray::RestoreLightingInternal(v1);
}

//----- (00511AC0) --------------------------------------------------------  // acclient.c:318962
void __thiscall CPhysicsObj::CallPESInternal(CPhysicsObj *this, IDClass<_tagDataID,32,0> pes, float cur_value)
{
  if ( cur_value >= 1.0 )
  {
    if ( this->cell )
      CPhysicsObj::play_script_internal(this, pes);
  }
}

//----- (00511AF0) --------------------------------------------------------  // acclient.c:318972
void __thiscall CPhysicsObj::CallPES(CPhysicsObj *this, IDClass<_tagDataID,32,0> pes, long double delta)
{
  CPhysicsObj *v3; // esi@1
  float upper_bound; // ST1C_4@4
  FPHook *v5; // eax@4
  int v6; // eax@5
  PhysicsObjHook *v7; // edx@7
  PhysicsObjHook *i; // ecx@7
  float randp; // [sp+20h] [bp+8h]@4

  v3 = this;
  if ( delta >= 0.00019999999 )
  {
    upper_bound = delta;
    randp = Random::RollDice(0.0, upper_bound);
    v5 = (FPHook *)operator new(0x38u);
    if ( v5 )
      FPHook::FPHook(v5, VELOCITY|MTABLE|CSetup, PhysicsTimer::curr_time, randp, 0.0, 1.0, (void *)pes.id);
    else
      v6 = 0;
    v7 = v3->hooks;
    for ( i = v3->hooks; i; i = i->next )
      ;
    if ( v7 )
      v7->prev = (PhysicsObjHook *)v6;
    *(_DWORD *)(v6 + 36) = v3->hooks;
    v3->hooks = (PhysicsObjHook *)v6;
  }
  else if ( this->cell )
  {
    CPhysicsObj::play_script_internal(this, pes);
  }
}

//----- (00511BB0) --------------------------------------------------------  // acclient.c:319007
void __thiscall CPhysicsObj::SetScaleStatic(CPhysicsObj *this, float new_scale)
{
  CPartArray *v2; // ecx@1
  AC1Legacy::Vector3 v3; // [sp+0h] [bp-Ch]@2

  this->m_scale = new_scale;
  v2 = this->part_array;
  if ( v2 )
  {
    v3.y = new_scale;
    v3.x = new_scale;
    v3.z = new_scale;
    CPartArray::SetScaleInternal(v2, &v3);
  }
}

//----- (00511BF0) --------------------------------------------------------  // acclient.c:319024
void __thiscall CPhysicsObj::clear_transient_states(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  int v2; // ecx@1
  MovementManager *v3; // ecx@2

  v1 = this;
  v1->transient_state &= 0xFFFFFFFE;
  CPhysicsObj::calc_acceleration(this);
  v2 = v1->transient_state & 2;
  v1->transient_state &= 0xFFFFFFF5;
  if ( v2 )
  {
    v3 = v1->movement_manager;
    if ( v3 )
      MovementManager::LeaveGround(v3);
  }
  CPhysicsObj::calc_acceleration(v1);
  v1->transient_state &= 0xFFFFFE0B;
}

//----- (00511C40) --------------------------------------------------------  // acclient.c:319046
int __thiscall CPhysicsObj::set_ethereal(CPhysicsObj *this, int ethereal, int send_event)
{
  CPhysicsObj *v3; // esi@1
  unsigned int v4; // ecx@1
  CPhysicsObj *v6; // eax@4
  int v7; // ecx@7

  v3 = this;
  v4 = this->state;
  if ( ethereal )
  {
    v3->state = v4 | 4;
LABEL_3:
    v3->transient_state &= 0xFFFFFEFF;
    return 1;
  }
  v6 = v3->parent;
  v3->state = v4 & 0xFFFFFFFB;
  if ( v6 || !v3->cell || !CPhysicsObj::ethereal_check_for_collisions(v3) )
    goto LABEL_3;
  v7 = v3->transient_state | 0x100;
  v3->state |= 4u;
  v3->transient_state = v7;
  return 0;
}

//----- (00511CC0) --------------------------------------------------------  // acclient.c:319073
signed int __thiscall CPhysicsObj::get_object_info(CPhysicsObj *this, CTransition *transit, int admin_move)
{
  CPhysicsObj *v3; // esi@1
  signed int v4; // ebx@1
  int v5; // eax@5
  char v6; // dl@5
  CPartArray *v7; // ecx@11
  int v9; // [sp-8h] [bp-10h]@5

  v3 = this;
  v4 = 0;
  if ( this->state & 0x400000 )
    v4 = 512;
  if ( !admin_move )
  {
    if ( this->transient_state & 1 )
    {
      v5 = CPhysicsObj::check_contact(this, 1);
      v9 = v6 & 8;
      if ( v5 )
      {
        CTransition::init_contact_plane(transit, v3->contact_plane_cell_id, &v3->contact_plane, v9);
        v4 |= 1u;
        if ( v3->transient_state & 2 )
          v4 |= 2u;
      }
      else
      {
        CTransition::init_last_known_contact_plane(transit, v3->contact_plane_cell_id, &v3->contact_plane, v9);
      }
    }
    if ( v3->transient_state & 4 )
      CTransition::init_sliding_normal(transit, &v3->sliding_normal);
  }
  v7 = v3->part_array;
  if ( v7 && CPartArray::AllowsFreeHeading(v7) )
    v4 |= 0x10u;
  if ( v3->state & 0x40 )
    v4 |= 8u;
  return v4;
}

//----- (00511D80) --------------------------------------------------------  // acclient.c:319116
int __cdecl CPhysicsObj::AdjustPosition(Position *p, AC1Legacy::Vector3 *low_pt, CObjCell **new_cell, int bDontCreateCells, int bSearchCells)
{
  unsigned int *v5; // esi@1
  unsigned int v6; // eax@1
  signed int v8; // ebx@7
  unsigned int v9; // esi@8
  unsigned int v10; // ebp@10
  RenderVertexStreamD3D *v11; // eax@11
  unsigned int v12; // esi@14
  AC1Legacy::Vector3 pt; // [sp+8h] [bp-Ch]@11

  v5 = &p->objcell_id;
  v6 = p->objcell_id & 0xFFFF;
  if ( (v6 < 1 || v6 > 0x40) && (v6 < 0x100 || v6 > 0xFFFD) && v6 != 0xFFFF )
    return 0;
  v8 = 0;
  *new_cell = 0;
  if ( (unsigned __int16)*v5 >= 0x100u )
  {
    v10 = CObjCell::GetVisible(*v5);
    if ( v10 )
    {
      Position::localtoglobal(p, &pt, p, low_pt);
      v11 = CEnvCell::find_visible_child_cell((CEnvCell *)v10, &pt, bSearchCells);
      if ( v11 )
      {
        *v5 = (unsigned int)v11->m_pD3DVertexBuffer;
        *new_cell = (CObjCell *)v11;
        return 1;
      }
      if ( *(_DWORD *)(v10 + 232) )
      {
        Position::adjust_to_outside(p);
        v12 = *v5;
        if ( v12 )
        {
          *new_cell = (CObjCell *)CObjCell::GetVisible(v12);
          v8 = 1;
        }
      }
    }
  }
  else
  {
    LandDefs::adjust_to_outside(v5, &p->frame.m_fOrigin);
    v9 = *v5;
    if ( v9 )
    {
      *new_cell = (CObjCell *)CObjCell::GetVisible(v9);
      return 1;
    }
  }
  return v8;
}

//----- (00511E90) --------------------------------------------------------  // acclient.c:319172
int __stdcall CPhysicsObj::CheckPositionInternal(CObjCell *new_cell, Position *new_pos, CTransition *transit, SetPositionStruct *sps)
{
  CTransition::init_path(transit, new_cell, 0, new_pos);
  if ( !(sps->flags & 0x10) )
    transit->sphere_path.placement_allows_sliding = 0;
  if ( CTransition::find_valid_position(transit) )
  {
    if ( sps->flags & 0x10 )
      return 1;
    if ( transit->sphere_path.curr_pos.frame.m_fOrigin.x - new_pos->frame.m_fOrigin.x < 0.050000001
      && transit->sphere_path.curr_pos.frame.m_fOrigin.y - new_pos->frame.m_fOrigin.y < 0.050000001
      && transit->sphere_path.curr_pos.objcell_id == new_cell->m_DID.id )
    {
      new_pos->frame.m_fOrigin.x = transit->sphere_path.curr_pos.frame.m_fOrigin.x;
      new_pos->frame.m_fOrigin.y = transit->sphere_path.curr_pos.frame.m_fOrigin.y;
      new_pos->frame.m_fOrigin.z = transit->sphere_path.curr_pos.frame.m_fOrigin.z;
      return 1;
    }
  }
  return 0;
}

//----- (00511F40) --------------------------------------------------------  // acclient.c:319195
int __thiscall CPhysicsObj::prepare_to_leave_visibility(CPhysicsObj *this)
{
  CPhysicsObj *v1; // edi@1
  unsigned __int16 i; // si@1
  CHILDLIST *v3; // eax@2

  v1 = this;
  CPhysicsObj::remove_shadows_from_cells(this);
  CObjectMaint::RemoveFromLostCell(CPhysicsObj::obj_maint, v1);
  CPhysicsObj::leave_cell(v1, 0);
  CObjectMaint::AddObjectToBeDestroyed(CPhysicsObj::obj_maint, v1->id);
  for ( i = 0; ; ++i )
  {
    v3 = v1->children;
    if ( !v3 || i >= v3->num_objects )
      break;
    CObjectMaint::AddObjectToBeDestroyed(CPhysicsObj::obj_maint, v3->objects.data[i]->id);
  }
  return 1;
}

//----- (00511FA0) --------------------------------------------------------  // acclient.c:319217
void __thiscall CPhysicsObj::prepare_to_enter_world(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  unsigned int v2; // ecx@1
  unsigned __int16 i; // di@1
  CHILDLIST *v4; // eax@2
  unsigned int v5; // eax@6
  unsigned int v6; // edx@7

  v1 = this;
  v2 = Timer::cur_time.Param;
  LODWORD(v1->update_time) = Timer::cur_time.Cmd;
  HIDWORD(v1->update_time) = v2;
  CObjectMaint::RemoveFromLostCell(CPhysicsObj::obj_maint, v1);
  CObjectMaint::RemoveObjectToBeDestroyed(CPhysicsObj::obj_maint, v1->id);
  for ( i = 0; ; ++i )
  {
    v4 = v1->children;
    if ( !v4 || i >= v4->num_objects )
      break;
    CObjectMaint::RemoveObjectToBeDestroyed(CPhysicsObj::obj_maint, v4->objects.data[i]->id);
  }
  if ( !(v1->state & 1) )
  {
    v5 = v1->transient_state;
    if ( (v5 & 0x80u) == 0 )
    {
      v6 = Timer::cur_time.Param;
      LODWORD(v1->update_time) = Timer::cur_time.Cmd;
      HIDWORD(v1->update_time) = v6;
    }
    v1->transient_state = v5 | 0x80;
  }
}

//----- (00512040) --------------------------------------------------------  // acclient.c:319253
void __thiscall CPhysicsObj::unpack_movement(CPhysicsObj *this, void **addr, unsigned int size)
{
  CPhysicsObj *v3; // esi@1
  unsigned int v4; // eax@3
  unsigned int v5; // edx@4

  v3 = this;
  if ( !this->movement_manager )
  {
    this->movement_manager = MovementManager::Create(this, this->weenie_obj);
    if ( !(v3->state & 1) )
    {
      v4 = v3->transient_state;
      if ( (v4 & 0x80u) == 0 )
      {
        v5 = Timer::cur_time.Param;
        LODWORD(v3->update_time) = Timer::cur_time.Cmd;
        HIDWORD(v3->update_time) = v5;
      }
      v3->transient_state = v4 | 0x80;
    }
  }
  MovementManager::unpack_movement(v3->movement_manager, addr, size);
}

//----- (005120C0) --------------------------------------------------------  // acclient.c:319279
CMotionInterp *__thiscall CPhysicsObj::get_minterp(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  MovementManager *v2; // eax@2
  unsigned int v3; // eax@3
  unsigned int v4; // edx@4

  v1 = this;
  if ( !this->movement_manager )
  {
    v2 = MovementManager::Create(this, this->weenie_obj);
    v1->movement_manager = v2;
    MovementManager::EnterDefaultState(v2);
    if ( !(v1->state & 1) )
    {
      v3 = v1->transient_state;
      if ( (v3 & 0x80u) == 0 )
      {
        v4 = Timer::cur_time.Param;
        LODWORD(v1->update_time) = Timer::cur_time.Cmd;
        HIDWORD(v1->update_time) = v4;
      }
      v1->transient_state = v3 | 0x80;
    }
  }
  return MovementManager::get_minterp(v1->movement_manager);
}

//----- (00512130) --------------------------------------------------------  // acclient.c:319308
PositionManager *__thiscall CPhysicsObj::get_position_manager(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1

  v1 = this;
  CPhysicsObj::MakePositionManager(this);
  return v1->position_manager;
}

//----- (00512140) --------------------------------------------------------  // acclient.c:319318
void __thiscall CPhysicsObj::get_local_physics_velocity(CPhysicsObj *this, AC1Legacy::Vector3 *retval)
{
  float v2; // ST00_4@1
  float v3; // ST04_4@1
  double v4; // st7@1
  double v5; // st6@1
  float v6; // ST08_4@1

  v2 = this->m_position.frame.m_fl2gv[1] * this->m_velocityVector.y
     + this->m_position.frame.m_fl2gv[0] * this->m_velocityVector.x
     + this->m_position.frame.m_fl2gv[2] * this->m_velocityVector.z;
  v3 = this->m_position.frame.m_fl2gv[4] * this->m_velocityVector.y
     + this->m_position.frame.m_fl2gv[3] * this->m_velocityVector.x
     + this->m_position.frame.m_fl2gv[5] * this->m_velocityVector.z;
  v4 = this->m_position.frame.m_fl2gv[7] * this->m_velocityVector.y
     + this->m_position.frame.m_fl2gv[6] * this->m_velocityVector.x;
  v5 = this->m_position.frame.m_fl2gv[8] * this->m_velocityVector.z;
  retval->x = v2;
  retval->y = v3;
  v6 = v4 + v5;
  retval->z = v6;
}

//----- (005121D0) --------------------------------------------------------  // acclient.c:319342
int __thiscall CShadowObj::vector_deleting_destructor(CShadowObj *this, unsigned int a2)
{
  CShadowObj *v2; // esi@1
  CObjCell *v3; // ecx@2
  int v4; // eax@2
  int v5; // ecx@2
  int v6; // eax@2
  int v7; // edx@3
  int result; // eax@7

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].cell;
    v4 = 3 * (_DWORD)v3;
    v5 = (int)((char *)&v3[-1].myLandBlock_ + 7);
    v6 = (int)&v2[8 * v4 / 0x18u];
    if ( v5 >= 0 )
    {
      v7 = v5 + 1;
      do
      {
        v6 -= 24;
        --v7;
        *(_DWORD *)v6 = LongHashData::vftable;
        *(_DWORD *)(v6 + 4) = 0;
        *(_DWORD *)(v6 + 8) = 0;
      }
      while ( v7 );
    }
    if ( a2 & 1 )
      operator delete[](&v2[-1].cell);
    result = (int)&v2[-1].cell;
  }
  else
  {
    this->vfptr = (HashBaseData<unsigned long>Vtbl *)LongHashData::vftable;
    this->hash_next = 0;
    this->id = 0;
    if ( a2 & 1 )
      operator delete(this);
    result = (int)v2;
  }
  return result;
}
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);

//----- (00512240) --------------------------------------------------------  // acclient.c:319390
HashBaseData<unsigned long> *__thiscall HashBase<unsigned long>::clobber(HashBase<unsigned long> *this, HashBaseData<unsigned long> *newData)
{
  unsigned int v2; // ebx@1
  HashBase<unsigned long> *v3; // esi@1
  HashBaseData<unsigned long> *v4; // ebp@1
  unsigned int v5; // edx@1
  HashBaseData<unsigned long> **v6; // ecx@1
  HashBaseData<unsigned long> *result; // eax@1

  v2 = newData->id;
  v3 = this;
  v4 = 0;
  v5 = this->table_mask & (v2 ^ (newData->id >> this->key_shift));
  v6 = &this->buckets[v5];
  result = *v6;
  if ( *v6 )
  {
    if ( result->id == v2 )
    {
LABEL_6:
      if ( result != newData )
      {
        if ( v4 )
        {
          v4->hash_next = newData;
          newData->hash_next = result->hash_next;
        }
        else
        {
          newData->hash_next = result->hash_next;
          v3->buckets[v5] = newData;
        }
      }
    }
    else
    {
      while ( 1 )
      {
        v4 = result;
        result = result->hash_next;
        if ( !result )
          break;
        if ( result->id == newData->id )
          goto LABEL_6;
      }
      newData->hash_next = *v6;
      v3->buckets[v5] = newData;
      result = 0;
    }
  }
  else
  {
    *v6 = newData;
  }
  return result;
}

//----- (005122E0) --------------------------------------------------------  // acclient.c:319448
void __thiscall Frame::combine(Frame *this, Frame *_f1, Frame *_f2)
{
  Frame *v3; // eax@1
  Frame *v4; // edx@1
  char *v5; // esi@1
  float v6; // ST18_4@1
  float v7; // ST1C_4@1
  double v8; // st7@1
  float v9; // ST20_4@1
  float new_qz; // ST0C_4@1
  float new_qy; // ST08_4@1
  float new_qx; // ST04_4@1
  float new_qw; // ST00_4@1

  v3 = _f1;
  v4 = _f2;
  v5 = (char *)&this->m_fOrigin;
  v6 = _f1->m_fl2gv[6] * _f2->m_fOrigin.z
     + _f1->m_fl2gv[0] * _f2->m_fOrigin.x
     + _f1->m_fl2gv[3] * _f2->m_fOrigin.y
     + _f1->m_fOrigin.x;
  v7 = _f1->m_fl2gv[7] * _f2->m_fOrigin.z
     + _f1->m_fl2gv[1] * _f2->m_fOrigin.x
     + _f1->m_fl2gv[4] * _f2->m_fOrigin.y
     + _f1->m_fOrigin.y;
  v8 = _f1->m_fl2gv[8] * _f2->m_fOrigin.z
     + _f1->m_fl2gv[2] * _f2->m_fOrigin.x
     + _f1->m_fl2gv[5] * _f2->m_fOrigin.y
     + _f1->m_fOrigin.z;
  *(float *)v5 = v6;
  *((float *)v5 + 1) = v7;
  v9 = v8;
  *((float *)v5 + 2) = v9;
  new_qz = v4->qy * v3->qx + v4->qz * v3->qw - v3->qy * v4->qx + v3->qz * v4->qw;
  new_qy = v4->qy * v3->qw - v4->qz * v3->qx + v3->qz * v4->qx + v3->qy * v4->qw;
  new_qx = v3->qw * v4->qx + v4->qz * v3->qy + v4->qw * v3->qx - v4->qy * v3->qz;
  new_qw = v3->qw * v4->qw - v4->qx * v3->qx - v4->qy * v3->qy - _f2->qz * _f1->qz;
  Frame::set_rotate(this, new_qw, new_qx, new_qy, new_qz);
}

//----- (005123F0) --------------------------------------------------------  // acclient.c:319489
void __thiscall CPhysicsObj::CPhysicsObj(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  char *v2; // ecx@1
  void *v3; // eax@1
  int v4; // edi@2
  int v5; // eax@2

  v1 = this;
  this->hash_next = 0;
  this->id = 0;
  this->vfptr = (HashBaseData<unsigned long>Vtbl *)CPhysicsObj::vftable;
  this->netblob_list = 0;
  this->part_array = 0;
  LODWORD(this->player_vector.x) = 0;
  LODWORD(this->player_vector.y) = 0;
  LODWORD(this->player_vector.z) = 1065353216;
  this->sound_table = 0;
  this->m_bExaminationObject = 0;
  this->script_manager = 0;
  this->physics_script_table = 0;
  this->default_script = 0;
  LODWORD(this->default_script_intensity) = 0;
  this->parent = 0;
  this->children = 0;
  v2 = (char *)&this->m_position.frame;
  LODWORD(v1->player_distance) = 2139095039;
  LODWORD(v1->CYpt) = 2139095039;
  v1->m_position.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->m_position.objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  v1->cell = 0;
  v1->num_shadow_objects = 0;
  v3 = operator new[](0x64u);
  if ( v3 )
  {
    v4 = (int)((char *)v3 + 4);
    *(_DWORD *)v3 = 4;
    vector_constructor_iterator((char *)v3 + 4, 0x18u, 4, (void *(__thiscall *)(void *))CShadowObj::CShadowObj);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v1->shadow_objects.data = (CShadowObj *)v5;
  v1->shadow_objects.next_available = 0;
  v1->shadow_objects.sizeOf = 4;
  v1->shadow_objects.blocksize = 4;
  v1->elasticity = DEFAULT_ELASTICITY;
  v1->transient_state = 0;
  v1->translucency = DEFAULT_TRANSLUCENCY;
  v1->friction = DEFAULT_FRICTION;
  v1->movement_manager = 0;
  v1->position_manager = 0;
  v1->last_move_was_autonomous = 0;
  v1->jumped_this_frame = 0;
  v1->state = 4197384;
  v1->translucencyOriginal = DEFAULT_TRANSLUCENCY;
  v1->massinv = 1.0 / 1.0;
  LODWORD(v1->m_velocityVector.x) = 0;
  LODWORD(v1->m_velocityVector.y) = 0;
  LODWORD(v1->m_velocityVector.z) = 0;
  LODWORD(v1->m_accelerationVector.x) = 0;
  LODWORD(v1->m_accelerationVector.y) = 0;
  LODWORD(v1->m_accelerationVector.z) = 0;
  LODWORD(v1->m_omegaVector.x) = 0;
  LODWORD(v1->m_omegaVector.y) = 0;
  LODWORD(v1->m_omegaVector.z) = 0;
  v1->hooks = 0;
  v1->anim_hooks.m_data = 0;
  v1->anim_hooks.m_size = 0;
  v1->anim_hooks.m_num = 0;
  LODWORD(v1->attack_radius) = 0;
  v1->detection_manager = 0;
  v1->attack_manager = 0;
  v1->target_manager = 0;
  v1->particle_manager = 0;
  v1->weenie_obj = 0;
  v1->contact_plane_cell_id = 0;
  LODWORD(v1->m_scale) = 1065353216;
  LODWORD(v1->sliding_normal.x) = 0;
  LODWORD(v1->sliding_normal.y) = 0;
  LODWORD(v1->sliding_normal.z) = 0;
  LODWORD(v1->cached_velocity.x) = 0;
  LODWORD(v1->cached_velocity.y) = 0;
  LODWORD(v1->cached_velocity.z) = 0;
  v1->collision_table = 0;
  v1->colliding_with_environment = 0;
  *(_DWORD *)&v1->update_times[0] = 0;
  *(_DWORD *)&v1->update_times[2] = 0;
  *(_DWORD *)&v1->update_times[4] = 0;
  *(_DWORD *)&v1->update_times[6] = 0;
  v1->update_times[8] = 0;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7C6B48: using guessed type int (__thiscall *CPhysicsObj::vftable[2])(void *, char);

//----- (00512600) --------------------------------------------------------  // acclient.c:319595
int __cdecl CPhysicsObj::makeNullObject(unsigned int object_iid, int bDynamic)
{
  CPhysicsObj *v2; // eax@1
  CPhysicsObj *v3; // eax@2
  int v4; // ecx@3

  v2 = (CPhysicsObj *)operator new(0x178u);
  if ( v2 )
  {
    CPhysicsObj::CPhysicsObj(v2);
    if ( v3 )
    {
      if ( CPhysicsObj::InitObjectBegin(v3, object_iid, bDynamic) )
        return v4;
      (**(void (__stdcall ***)(_DWORD))v4)(1);
    }
  }
  return 0;
}

//----- (00512640) --------------------------------------------------------  // acclient.c:319616
int __cdecl CPhysicsObj::makeParticleObject(unsigned int num_parts)
{
  CPhysicsObj *v1; // eax@1
  int v2; // eax@2
  int v3; // esi@2
  int v4; // edx@3
  CPartArray *v5; // eax@3

  v1 = (CPhysicsObj *)operator new(0x178u);
  if ( v1 )
  {
    CPhysicsObj::CPhysicsObj(v1);
    v3 = v2;
    if ( v2 )
    {
      v4 = *(_DWORD *)(v2 + 168) | 0x1001;
      *(_DWORD *)(v2 + 8) = 0;
      *(_DWORD *)(v2 + 168) = v4;
      v5 = CPartArray::CreateParticle((CPhysicsObj *)v2, num_parts);
      *(_DWORD *)(v3 + 16) = v5;
      if ( v5 )
        return v3;
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
  }
  return 0;
}

//----- (005126B0) --------------------------------------------------------  // acclient.c:319645
int __thiscall CPhysicsObj::InitPartArrayObject(CPhysicsObj *this, IDClass<_tagDataID,32,0> data_did, int bCreateParts)
{
  CPhysicsObj *v3; // esi@1
  signed int v5; // ebx@3
  int v6; // eax@3
  CPartArray *v7; // eax@4
  unsigned int v8; // edx@12

  v3 = this;
  if ( data_did.id == stru_843D84.id )
    return 0;
  v5 = 0;
  v6 = MasterDBMap::DivineType(data_did);
  if ( v6 == 6 )
  {
    v7 = CPartArray::CreateMesh(v3, data_did);
  }
  else
  {
    if ( v6 != 7 )
    {
      if ( data_did.id & 0xFF000000 )
        return 0;
      v5 = 1;
      if ( !CPhysicsObj::makeAnimObject(v3, (IDClass<_tagDataID,32,0>)(data_did.id | 0x2000000), bCreateParts) )
        return 0;
      goto LABEL_11;
    }
    v7 = CPartArray::CreateSetup(v3, data_did, bCreateParts);
  }
  v3->part_array = v7;
  if ( !v7 )
    return 0;
LABEL_11:
  CPhysicsObj::CacheHasPhysicsBSP(v3);
  if ( v5 )
  {
    v8 = v3->transient_state & 0xFFFFFEFF;
    v3->state |= 4u;
    v3->transient_state = v8;
    CPhysicsObj::SetTranslucencyInternal(v3, 0.25);
    v3->state |= 0x10u;
  }
  return 1;
}

//----- (00512780) --------------------------------------------------------  // acclient.c:319692
int __thiscall CPhysicsObj::SetMotionTableID(CPhysicsObj *this, IDClass<_tagDataID,32,0> mtable_id)
{
  CPhysicsObj *v2; // esi@1
  CPartArray *v3; // ecx@1
  int result; // eax@1
  int v5; // edi@2
  void *v6; // ebx@3

  v2 = this;
  v3 = this->part_array;
  result = 0;
  if ( v3 )
  {
    v5 = CPartArray::SetMotionTableID(v3, mtable_id);
    if ( v5 )
    {
      v6 = v2->movement_manager;
      if ( v6 )
      {
        MovementManager::Destroy(v2->movement_manager);
        operator delete(v6);
      }
      v2->movement_manager = 0;
      if ( mtable_id.id != stru_843D84.id )
        CPhysicsObj::MakeMovementManager(v2, 1);
    }
    result = v5;
  }
  return result;
}

//----- (005127E0) --------------------------------------------------------  // acclient.c:319724
void __thiscall CPhysicsObj::stick_to_object(CPhysicsObj *this, unsigned int object_id)
{
  CPhysicsObj *v2; // edi@1
  HashBaseData<unsigned long> *v3; // eax@2
  HashBaseData<unsigned long> *v4; // esi@3
  HashBaseData<unsigned long> *v5; // eax@3
  CPartArray *v6; // ecx@5
  CPartArray *v7; // ecx@8
  float radius; // ST14_4@9
  float object_ida; // [sp+8h] [bp+4h]@6

  v2 = this;
  CPhysicsObj::MakePositionManager(this);
  if ( CPhysicsObj::obj_maint )
  {
    v3 = CObjectMaint::GetObjectA(CPhysicsObj::obj_maint, object_id);
    if ( v3 )
    {
      v4 = v3;
      v5 = v3[5].hash_next;
      if ( v5 )
        v4 = v5;
      v6 = (CPartArray *)v4[1].hash_next;
      if ( v6 )
        object_ida = CPartArray::GetHeight(v6);
      else
        object_ida = 0.0;
      v7 = (CPartArray *)v4[1].hash_next;
      if ( v7 )
      {
        radius = CPartArray::GetRadius(v7);
        PositionManager::StickTo(v2->position_manager, v4->id, radius, object_ida);
      }
      else
      {
        PositionManager::StickTo(v2->position_manager, v4->id, 0.0, object_ida);
      }
    }
  }
}

//----- (00512860) --------------------------------------------------------  // acclient.c:319766
void __thiscall CPhysicsObj::MoveToObject(CPhysicsObj *this, unsigned int object_id, MovementParameters *params)
{
  CPhysicsObj *v3; // edi@1
  MovementManager *v4; // eax@2
  unsigned int v5; // eax@3
  unsigned int v6; // edx@4
  unsigned int v7; // ebx@7
  HashBaseData<unsigned long> *v8; // eax@7
  HashBaseData<unsigned long> *v9; // esi@7
  CPartArray *v10; // ecx@8
  CPartArray *v11; // ecx@11
  HashBaseData<unsigned long> *v12; // eax@14
  HashBaseData<unsigned long> *v13; // esi@14
  float object_radius; // [sp+0h] [bp-4h]@12
  float object_ida; // [sp+8h] [bp+4h]@9

  v3 = this;
  if ( !this->movement_manager )
  {
    v4 = MovementManager::Create(this, this->weenie_obj);
    v3->movement_manager = v4;
    MovementManager::EnterDefaultState(v4);
    if ( !(v3->state & 1) )
    {
      v5 = v3->transient_state;
      if ( (v5 & 0x80u) == 0 )
      {
        v6 = Timer::cur_time.Param;
        LODWORD(v3->update_time) = Timer::cur_time.Cmd;
        HIDWORD(v3->update_time) = v6;
      }
      v3->transient_state = v5 | 0x80;
    }
  }
  if ( CPhysicsObj::obj_maint )
  {
    v7 = object_id;
    v8 = CObjectMaint::GetObjectA(CPhysicsObj::obj_maint, object_id);
    v9 = v8;
    if ( v8 )
    {
      v10 = (CPartArray *)v8[1].hash_next;
      if ( v10 )
        object_ida = CPartArray::GetHeight(v10);
      else
        object_ida = 0.0;
      v11 = (CPartArray *)v9[1].hash_next;
      if ( v11 )
        object_radius = CPartArray::GetRadius(v11);
      else
        object_radius = 0.0;
      v12 = v9;
      v13 = v9[5].hash_next;
      if ( v13 )
        v12 = v13;
      CPhysicsObj::MoveToObject_Internal(v3, v7, v12->id, object_radius, object_ida, params);
    }
  }
}

//----- (00512940) --------------------------------------------------------  // acclient.c:319827
void __thiscall CPhysicsObj::TurnToObject(CPhysicsObj *this, unsigned int object_id, MovementParameters *params)
{
  CPhysicsObj *v3; // edi@1
  HashBaseData<unsigned long> *v4; // eax@2
  HashBaseData<unsigned long> *v5; // ecx@3
  HashBaseData<unsigned long> *v6; // eax@3

  v3 = this;
  if ( CPhysicsObj::obj_maint )
  {
    v4 = CObjectMaint::GetObjectA(CPhysicsObj::obj_maint, object_id);
    if ( v4 )
    {
      v5 = v4;
      v6 = v4[5].hash_next;
      if ( v6 )
        v5 = v6;
      CPhysicsObj::TurnToObject_Internal(v3, object_id, v5->id, params);
    }
  }
}

//----- (00512980) --------------------------------------------------------  // acclient.c:319850
void __thiscall CPhysicsObj::TurnToHeading(CPhysicsObj *this, MovementParameters *params)
{
  CPhysicsObj *v2; // esi@1
  MovementManager *v3; // eax@2
  unsigned int v4; // eax@3
  unsigned int v5; // edx@4
  MovementManager *v6; // ecx@6
  MovementStruct mvs; // [sp+4h] [bp-64h]@6

  v2 = this;
  if ( !this->movement_manager )
  {
    v3 = MovementManager::Create(this, this->weenie_obj);
    v2->movement_manager = v3;
    MovementManager::EnterDefaultState(v3);
    if ( !(v2->state & 1) )
    {
      v4 = v2->transient_state;
      if ( (v4 & 0x80u) == 0 )
      {
        v5 = Timer::cur_time.Param;
        LODWORD(v2->update_time) = Timer::cur_time.Cmd;
        HIDWORD(v2->update_time) = v5;
      }
      v2->transient_state = v4 | 0x80;
    }
  }
  mvs.type = 0;
  mvs.pos.vfptr = (PackObjVtbl *)&Position::vftable;
  mvs.pos.objcell_id = 0;
  LODWORD(mvs.pos.frame.qw) = 1065353216;
  LODWORD(mvs.pos.frame.qx) = 0;
  LODWORD(mvs.pos.frame.qy) = 0;
  LODWORD(mvs.pos.frame.qz) = 0;
  LODWORD(mvs.pos.frame.m_fOrigin.x) = 0;
  LODWORD(mvs.pos.frame.m_fOrigin.y) = 0;
  LODWORD(mvs.pos.frame.m_fOrigin.z) = 0;
  Frame::cache(&mvs.pos.frame);
  v6 = v2->movement_manager;
  mvs.type = 9;
  mvs.params = params;
  MovementManager::PerformMovement(v6, &mvs);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00512A70) --------------------------------------------------------  // acclient.c:319896
void __thiscall CPhysicsObj::attack(CPhysicsObj *this, AttackCone *attack_cone)
{
  CPhysicsObj *v2; // esi@1
  AttackManager *v3; // eax@3
  AttackManager *v4; // eax@4
  AttackCone *v5; // edi@7
  float v6; // ST2C_4@7
  double v7; // st7@7
  AttackManager *v8; // eax@7
  double v9; // st6@8
  int v10; // ebp@10
  unsigned int v11; // eax@10
  CObjCell *v12; // ecx@11
  CSphere sphere; // [sp+10h] [bp-2Ch]@7
  CELLARRAY cell_array; // [sp+20h] [bp-1Ch]@10
  AttackCone *attack_conea; // [sp+40h] [bp+4h]@10

  v2 = this;
  if ( this->cell->m_DID.id != stru_843D84.id )
  {
    if ( !this->attack_manager )
    {
      v3 = (AttackManager *)operator new(0x10u);
      if ( v3 )
        AttackManager::AttackManager(v3);
      else
        v4 = 0;
      v2->attack_manager = v4;
    }
    v5 = attack_cone;
    v6 = attack_cone->height * v2->m_scale;
    v7 = v2->m_scale;
    sphere.center.z = v6;
    v8 = v2->attack_manager;
    LODWORD(sphere.center.x) = 0;
    LODWORD(sphere.center.y) = 0;
    if ( v8 )
      v9 = v8->attack_radius;
    else
      v9 = 0.0;
    sphere.radius = v7 * attack_cone->radius + v9;
    CELLARRAY::CELLARRAY(&cell_array);
    cell_array.do_not_load_cells = 1;
    CObjCell::find_cell_list(&v2->m_position, &sphere, &cell_array, 0);
    v10 = AttackManager::NewAttack(v2->attack_manager, attack_cone->part_index);
    v11 = 0;
    attack_conea = 0;
    if ( cell_array.num_cells )
    {
      do
      {
        v12 = cell_array.cells.data[v11].cell;
        if ( v12 )
        {
          CObjCell::check_attack(v12, v2->id, &v2->m_position, v2->m_scale, v5, (AttackInfo *)v10);
          v11 = (unsigned int)attack_conea;
        }
        ++v11;
        attack_conea = (AttackCone *)v11;
      }
      while ( v11 < cell_array.num_cells );
    }
    if ( !*(_DWORD *)(v10 + 12) )
      CPhysicsObj::report_attacks(v2, (AttackInfo *)v10);
    if ( cell_array.cells.data )
      operator delete[](&cell_array.cells.data[-1].cell);
  }
}

//----- (00512BC0) --------------------------------------------------------  // acclient.c:319966
void __thiscall CPhysicsObj::HandleUpdateTarget(CPhysicsObj *this, TargetInfo target_info)
{
  CPhysicsObj *v2; // esi@1
  TargetInfo v3; // [sp-D0h] [bp-D4h]@3

  v2 = this;
  if ( !target_info.context_id )
  {
    if ( this->movement_manager )
    {
      TargetInfo::TargetInfo(&v3, &target_info);
      MovementManager::HandleUpdateTarget(v2->movement_manager, v3);
    }
    if ( v2->position_manager )
    {
      TargetInfo::TargetInfo(&v3, &target_info);
      PositionManager::HandleUpdateTarget(v2->position_manager, v3);
    }
  }
}

//----- (00512C30) --------------------------------------------------------  // acclient.c:319988
void __thiscall CPhysicsObj::UpdatePositionInternal(CPhysicsObj *this, float quantum, Frame *o_newFrame)
{
  CPhysicsObj *v3; // esi@1
  unsigned int v4; // eax@1
  CPartArray *v5; // ecx@2
  double v6; // st7@5
  PositionManager *v7; // ecx@7
  unsigned int v8; // eax@9
  Frame offset_frame; // [sp+14h] [bp-40h]@1

  v3 = this;
  LODWORD(offset_frame.qw) = 1065353216;
  LODWORD(offset_frame.qx) = 0;
  LODWORD(offset_frame.qy) = 0;
  LODWORD(offset_frame.qz) = 0;
  LODWORD(offset_frame.m_fOrigin.x) = 0;
  LODWORD(offset_frame.m_fOrigin.y) = 0;
  LODWORD(offset_frame.m_fOrigin.z) = 0;
  Frame::cache(&offset_frame);
  v4 = v3->state;
  if ( !(BYTE1(v4) & 0x40) )
  {
    v5 = v3->part_array;
    if ( v5 )
      CPartArray::Update(v5, quantum, &offset_frame);
    if ( v3->transient_state & 2 )
    {
      v6 = v3->m_scale;
      offset_frame.m_fOrigin.x = offset_frame.m_fOrigin.x * v6;
      offset_frame.m_fOrigin.y = offset_frame.m_fOrigin.y * v6;
      offset_frame.m_fOrigin.z = offset_frame.m_fOrigin.z * v6;
    }
    else
    {
      offset_frame.m_fOrigin.x = offset_frame.m_fOrigin.x * 0.0;
      offset_frame.m_fOrigin.y = offset_frame.m_fOrigin.y * 0.0;
      offset_frame.m_fOrigin.z = offset_frame.m_fOrigin.z * 0.0;
    }
  }
  v7 = v3->position_manager;
  if ( v7 )
    PositionManager::adjust_offset(v7, &offset_frame, quantum);
  Frame::combine(o_newFrame, &v3->m_position.frame, &offset_frame);
  v8 = v3->state;
  if ( !(BYTE1(v8) & 0x40) )
    CPhysicsObj::UpdatePhysicsInternal(v3, quantum, o_newFrame);
  CPhysicsObj::process_hooks(v3);
}

//----- (00512D50) --------------------------------------------------------  // acclient.c:320038
void __thiscall CPhysicsObj::UpdateChild(CPhysicsObj *this, CPhysicsObj *child_obj, unsigned int part_index, Frame *child_frame)
{
  CPartArray *v4; // eax@1
  ParticleManager *v5; // ecx@4
  ScriptManager *v6; // ecx@6
  Frame new_frame; // [sp+4h] [bp-40h]@2

  v4 = this->part_array;
  if ( part_index >= v4->num_parts )
    Frame::combine(&new_frame, &this->m_position.frame, child_frame);
  else
    Frame::combine(&new_frame, &v4->parts[part_index]->pos.frame, child_frame);
  CPhysicsObj::set_frame(child_obj, &new_frame);
  v5 = child_obj->particle_manager;
  if ( v5 )
    ParticleManager::UpdateParticles(v5);
  v6 = child_obj->script_manager;
  if ( v6 )
    ScriptManager::UpdateScripts(v6);
}

//----- (00512DC0) --------------------------------------------------------  // acclient.c:320060
CTransition *__thiscall CPhysicsObj::transition(CPhysicsObj *this, Position *old_pos, Position *new_pos, int admin_move)
{
  CPhysicsObj *v4; // edi@1
  CTransition *v5; // esi@1
  int v6; // eax@2
  CPartArray *v7; // ecx@2
  CPartArray *v8; // ecx@4
  CSphere *v9; // ebx@5
  CPartArray *v10; // ecx@7
  const unsigned int v11; // eax@8
  unsigned int v12; // eax@11
  int v13; // edi@17
  CTransition *result; // eax@18
  int admin_movea; // [sp+14h] [bp+Ch]@4

  v4 = this;
  v5 = CTransition::makeTransition();
  if ( !v5 )
    goto LABEL_22;
  v6 = CPhysicsObj::get_object_info(v4, v5, admin_move);
  CTransition::init_object(v5, v4, v6);
  v7 = v4->part_array;
  if ( v7 && CPartArray::GetNumSphere(v7) )
  {
    admin_movea = LODWORD(v4->m_scale);
    v8 = v4->part_array;
    v9 = v8 ? CPartArray::GetSphere(v8) : 0;
    v10 = v4->part_array;
    if ( v10 )
    {
      v11 = CPartArray::GetNumSphere(v10);
      CTransition::init_sphere(v5, v11, v9, *(const float *)&admin_movea);
    }
    else
    {
      CTransition::init_sphere(v5, 0, v9, *(const float *)&admin_movea);
    }
  }
  else
  {
    CTransition::init_sphere(v5, 1u, &dummy_sphere, 1.0);
  }
  CTransition::init_path(v5, v4->cell, old_pos, new_pos);
  v12 = v4->transient_state;
  if ( v12 & 0x40 )
  {
    v5->collision_info.frames_stationary_fall = 3;
  }
  else if ( v12 & 0x20 )
  {
    v5->collision_info.frames_stationary_fall = 2;
  }
  else if ( v12 & 0x10 )
  {
    v5->collision_info.frames_stationary_fall = 1;
  }
  v13 = CTransition::find_valid_position(v5);
  CTransition::cleanupTransition();
  if ( v13 )
    result = v5;
  else
LABEL_22:
    result = 0;
  return result;
}

//----- (00512ED0) --------------------------------------------------------  // acclient.c:320127
int __thiscall CPhysicsObj::check_collision(CPhysicsObj *this, CPhysicsObj *object)
{
  CPhysicsObj *v2; // esi@1
  int result; // eax@2
  CTransition *v4; // eax@3
  CTransition *v5; // edi@3
  int v6; // eax@4
  CPartArray *v7; // ecx@4
  CPartArray *v8; // ecx@6
  CSphere *v9; // ebx@7
  CPartArray *v10; // ecx@9
  const unsigned int v11; // eax@10
  int v12; // esi@13
  float scale; // [sp+0h] [bp-4h]@6

  v2 = this;
  if ( this->state & 1 )
  {
    result = 0;
  }
  else
  {
    v4 = CTransition::makeTransition();
    v5 = v4;
    if ( v4 )
    {
      v6 = CPhysicsObj::get_object_info(v2, v4, 0);
      CTransition::init_object(v5, v2, v6);
      v7 = v2->part_array;
      if ( v7 && CPartArray::GetNumSphere(v7) )
      {
        v8 = v2->part_array;
        scale = v2->m_scale;
        if ( v8 )
          v9 = CPartArray::GetSphere(v8);
        else
          v9 = 0;
        v10 = v2->part_array;
        if ( v10 )
        {
          v11 = CPartArray::GetNumSphere(v10);
          CTransition::init_sphere(v5, v11, v9, scale);
        }
        else
        {
          CTransition::init_sphere(v5, 0, v9, scale);
        }
      }
      else
      {
        CTransition::init_sphere(v5, 1u, &dummy_sphere, 1.0);
      }
      CTransition::init_path(v5, v2->cell, &v2->m_position, &v2->m_position);
      v12 = CTransition::check_collisions(v5, object);
      CTransition::cleanupTransition();
      result = v12;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (00512FC0) --------------------------------------------------------  // acclient.c:320193
int __thiscall CPhysicsObj::report_environment_collision(CPhysicsObj *this, int prev_has_contact)
{
  CPhysicsObj *v2; // esi@1
  int result; // eax@1
  float v4; // edx@4
  float v5; // eax@4
  unsigned int v6; // ecx@5
  EnvCollisionProfile prof; // [sp+4h] [bp-10h]@4

  v2 = this;
  result = 0;
  if ( !this->colliding_with_environment )
  {
    if ( this->state & 8 && this->weenie_obj )
    {
      EnvCollisionProfile::EnvCollisionProfile(&prof);
      v4 = v2->m_velocityVector.y;
      v5 = v2->m_velocityVector.z;
      prof.velocity.x = v2->m_velocityVector.x;
      prof.velocity.y = v4;
      prof.velocity.z = v5;
      EnvCollisionProfile::SetMeInContact(&prof, prev_has_contact);
      ((void (__stdcall *)(EnvCollisionProfile *))v2->weenie_obj->vfptr[19].__vecDelDtor)(&prof);
      result = 1;
    }
    v6 = v2->state;
    v2->colliding_with_environment = 1;
    if ( v6 & 0x40 )
      v2->state = v6 & 0xFFFFFCBF;
  }
  return result;
}

//----- (00513060) --------------------------------------------------------  // acclient.c:320227
int __thiscall CPhysicsObj::report_object_collision(CPhysicsObj *this, CPhysicsObj *object, int prev_has_contact)
{
  unsigned int v3; // edx@1
  int result; // eax@1
  CPhysicsObj *v5; // edi@1
  unsigned int v6; // ecx@3
  int v7; // ebx@3
  float height; // ST0C_4@7
  int v9; // ebp@7
  CWeenieObject *v10; // ecx@7
  unsigned int v11; // ecx@12
  float v12; // ST10_4@16
  int v13; // ebx@16
  CWeenieObject *v14; // ecx@16
  AtkCollisionProfile prof; // [sp+18h] [bp-34h]@7
  AC1Legacy::Vector3 collision_velocity; // [sp+24h] [bp-28h]@3
  ObjCollisionProfile v17; // [sp+30h] [bp-1Ch]@8

  v3 = object->state;
  result = 0;
  v5 = this;
  if ( v3 & 0x200000 )
  {
    result = CPhysicsObj::report_environment_collision(this, prev_has_contact);
  }
  else
  {
    v6 = this->state;
    v7 = v6 & 0x40;
    collision_velocity.x = v5->m_velocityVector.x - object->m_velocityVector.x;
    collision_velocity.y = v5->m_velocityVector.y - object->m_velocityVector.y;
    collision_velocity.z = v5->m_velocityVector.z - object->m_velocityVector.z;
    if ( !(v3 & 0x10) )
    {
      if ( v6 & 8 && v5->weenie_obj )
      {
        if ( v6 & 0x40 )
        {
          height = CPhysicsObj::GetHeight(object);
          v9 = Position::determine_quadrant(&object->m_position, height, &v5->m_position);
          AtkCollisionProfile::AtkCollisionProfile(&prof);
          v10 = v5->weenie_obj;
          prof.id = object->id;
          prof.part = -1;
          prof.location = v9;
          ((void (__stdcall *)(AtkCollisionProfile *))v10->vfptr[21].__vecDelDtor)(&prof);
        }
        else
        {
          ObjCollisionProfile::ObjCollisionProfile(&v17);
          CPhysicsObj::build_collision_profile(
            &v17,
            object,
            &collision_velocity,
            prev_has_contact,
            object->state & 0x40,
            object->transient_state & 1);
          ((void (__stdcall *)(ObjCollisionProfile *))v5->weenie_obj->vfptr[20].__vecDelDtor)(&v17);
        }
        result = 1;
      }
      if ( v7 )
        v5->state &= 0xFFFFFCBF;
    }
    v11 = object->state;
    if ( v11 & 8 && !(v5->state & 0x10) && object->weenie_obj )
    {
      if ( v11 & 0x40 )
      {
        v12 = CPhysicsObj::GetHeight(v5);
        v13 = Position::determine_quadrant(&v5->m_position, v12, &object->m_position);
        AtkCollisionProfile::AtkCollisionProfile(&prof);
        v14 = object->weenie_obj;
        prof.id = v5->id;
        prof.part = -1;
        prof.location = v13;
        ((void (__stdcall *)(AtkCollisionProfile *))v14->vfptr[21].__vecDelDtor)(&prof);
        result = 1;
      }
      else
      {
        ObjCollisionProfile::ObjCollisionProfile(&v17);
        CPhysicsObj::build_collision_profile(
          &v17,
          v5,
          &collision_velocity,
          object->transient_state & 1,
          prev_has_contact,
          v7);
        ((void (__stdcall *)(ObjCollisionProfile *))object->weenie_obj->vfptr[20].__vecDelDtor)(&v17);
        result = 1;
      }
    }
  }
  return result;
}

//----- (00513260) --------------------------------------------------------  // acclient.c:320325
int __thiscall CPhysicsObj::play_script(CPhysicsObj *this, PScriptType script_type, float mod)
{
  CPhysicsObj *v3; // esi@1
  int result; // eax@2
  PhysicsScriptTable *v5; // ecx@3

  v3 = this;
  if ( this->cell )
  {
    v5 = this->physics_script_table;
    result = 0;
    if ( v5 )
    {
      PhysicsScriptTable::GetScript(v5, (IDClass<_tagDataID,32,0> *)&mod, script_type, mod);
      result = CPhysicsObj::play_script_internal(v3, LODWORD(mod));
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (005132B0) --------------------------------------------------------  // acclient.c:320350
int __thiscall CPhysicsObj::play_default_script(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  int v2; // eax@2
  PhysicsScriptTable *v3; // ecx@3
  IDClass<_tagDataID,32,0> result; // [sp+8h] [bp-4h]@1

  result.id = (unsigned int)this;
  v1 = this;
  if ( this->cell )
  {
    v3 = this->physics_script_table;
    v2 = 0;
    if ( v3 )
    {
      PhysicsScriptTable::GetScript(v3, &result, v1->default_script, v1->default_script_intensity);
      v2 = CPhysicsObj::play_script_internal(v1, result);
    }
  }
  else
  {
    v2 = 1;
  }
  return v2;
}

//----- (00513300) --------------------------------------------------------  // acclient.c:320377
int __thiscall CPhysicsObj::play_default_script(CPhysicsObj *this, unsigned int part_index)
{
  CHILDLIST *v2; // ecx@1
  unsigned __int16 i; // dx@2
  int v4; // eax@4
  CPhysicsObj *v5; // esi@7
  int result; // eax@8
  PhysicsScriptTable *v7; // ecx@9

  v2 = this->children;
  if ( v2 )
  {
    for ( i = 0; i < v2->num_objects; ++i )
    {
      v4 = i;
      if ( v2->part_numbers.data[v4] == part_index && v2->objects.data[v4] )
      {
        v5 = v2->objects.data[i];
        if ( v5->cell )
        {
          v7 = v5->physics_script_table;
          result = 0;
          if ( v7 )
          {
            PhysicsScriptTable::GetScript(
              v7,
              (IDClass<_tagDataID,32,0> *)&part_index,
              v5->default_script,
              v5->default_script_intensity);
            result = CPhysicsObj::play_script_internal(v5, (IDClass<_tagDataID,32,0>)part_index);
          }
        }
        else
        {
          result = 1;
        }
        return result;
      }
    }
  }
  return 0;
}

//----- (00513390) --------------------------------------------------------  // acclient.c:320421
void __thiscall CPhysicsObj::change_cell(CPhysicsObj *this, CObjCell *new_cell)
{
  CPhysicsObj *v2; // esi@1
  unsigned int v3; // eax@5
  CPartArray *v4; // ecx@6

  v2 = this;
  if ( this->cell )
    CPhysicsObj::leave_cell(this, 1);
  if ( new_cell )
  {
    CPhysicsObj::enter_cell(v2, new_cell);
  }
  else
  {
    v3 = v2->state;
    v2->m_position.objcell_id = 0;
    if ( !(BYTE1(v3) & 0x10) )
    {
      v4 = v2->part_array;
      if ( v4 )
        CPartArray::SetCellID(v4, 0);
    }
    v2->cell = 0;
  }
}

//----- (005133F0) --------------------------------------------------------  // acclient.c:320449
void __thiscall CPhysicsObj::RemoveObjectFromSingleCell(CPhysicsObj *this, CObjCell *obj_cell)
{
  CPhysicsObj *v2; // esi@1
  unsigned int v3; // eax@3
  CPartArray *v4; // ecx@4
  CPartArray *v5; // ecx@7

  v2 = this;
  if ( this->cell )
    CPhysicsObj::leave_cell(this, 1);
  v3 = v2->state;
  v2->m_position.objcell_id = 0;
  if ( !(BYTE1(v3) & 0x10) )
  {
    v4 = v2->part_array;
    if ( v4 )
      CPartArray::SetCellID(v4, 0);
  }
  v2->cell = 0;
  if ( obj_cell )
  {
    CObjCell::remove_shadow_object(obj_cell, v2->shadow_objects.data);
    v5 = v2->part_array;
    v2->num_shadow_objects = 0;
    if ( v5 )
      CPartArray::RemoveParts(v5, obj_cell);
  }
}

//----- (00513470) --------------------------------------------------------  // acclient.c:320479
void __thiscall CPhysicsObj::unset_parent(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  CPhysicsObj *v2; // eax@1
  CHILDLIST *v3; // eax@2
  unsigned int v4; // ecx@4
  CPartArray *v5; // ecx@5
  unsigned int v6; // edx@7

  v1 = this;
  v2 = this->parent;
  if ( v2 )
  {
    v3 = v2->children;
    if ( v3 )
      CHILDLIST::remove_child(v3, this);
    v4 = v1->parent->state;
    if ( BYTE1(v4) & 0x40 )
    {
      v1->state &= 0xFFFFFFDF;
      v5 = v1->part_array;
      if ( v5 )
        CPartArray::SetNoDrawInternal(v5, 0);
    }
    v1->parent = 0;
    v6 = Timer::cur_time.Param;
    LODWORD(v1->update_time) = Timer::cur_time.Cmd;
    HIDWORD(v1->update_time) = v6;
    CPhysicsObj::clear_transient_states(v1);
  }
}

//----- (005134E0) --------------------------------------------------------  // acclient.c:320512
void __thiscall CPhysicsObj::unparent_children(CPhysicsObj *this)
{
  CHILDLIST *v1; // eax@2
  CPhysicsObj **v2; // ecx@4
  CPhysicsObj *v3; // esi@4
  CPhysicsObj *v4; // eax@4
  CHILDLIST *v5; // eax@5
  unsigned int v6; // eax@7
  CPartArray *v7; // ecx@8
  unsigned int v8; // edx@10
  ICMDCommandEnum v9; // eax@10
  int v10; // ecx@10
  MovementManager *v11; // ecx@11
  CPhysicsObj *v12; // [sp+0h] [bp-4h]@1

  v12 = this;
  while ( 1 )
  {
    v1 = v12->children;
    if ( !v1 || !v1->num_objects )
      break;
    v2 = v1->objects.data;
    v3 = *v2;
    v4 = (*v2)->parent;
    if ( v4 )
    {
      v5 = v4->children;
      if ( v5 )
        CHILDLIST::remove_child(v5, *v2);
      v6 = v3->parent->state;
      if ( BYTE1(v6) & 0x40 )
      {
        v3->state &= 0xFFFFFFDF;
        v7 = v3->part_array;
        if ( v7 )
          CPartArray::SetNoDrawInternal(v7, 0);
      }
      v8 = v3->transient_state;
      v3->parent = 0;
      v9 = (signed int)Timer::cur_time.Cmd;
      HIDWORD(v3->update_time) = Timer::cur_time.Param;
      LODWORD(v3->update_time) = v9;
      v3->transient_state = v8 & 0xFFFFFFFE;
      CPhysicsObj::calc_acceleration(v3);
      v10 = v3->transient_state & 2;
      v3->transient_state &= 0xFFFFFFF5;
      if ( v10 )
      {
        v11 = v3->movement_manager;
        if ( v11 )
          MovementManager::LeaveGround(v11);
      }
      CPhysicsObj::calc_acceleration(v3);
      v3->transient_state &= 0xFFFFFE0B;
    }
  }
}

//----- (005135C0) --------------------------------------------------------  // acclient.c:320571
void __thiscall CPhysicsObj::process_fp_hook(CPhysicsObj *this, int type, float curr_value, void *user_data)
{
  CPartArray *v4; // ecx@4
  CPartArray *v5; // ecx@6
  CPartArray *v6; // ecx@8
  CPartArray *v7; // ecx@10
  CPartArray *v8; // ecx@12

  switch ( type )
  {
    case 0:
      CPhysicsObj::SetScaleStatic(this, curr_value);
      break;
    case 1:
      CPhysicsObj::SetTranslucencyInternal(this, curr_value);
      break;
    case 2:
      v4 = this->part_array;
      if ( v4 )
        CPartArray::SetPartTranslucencyInternal(v4, (unsigned int)user_data, curr_value);
      break;
    case 3:
      v5 = this->part_array;
      if ( v5 )
        CPartArray::SetLuminosityInternal(v5, curr_value);
      break;
    case 5:
      v6 = this->part_array;
      if ( v6 )
        CPartArray::SetPartLuminosityInternal(v6, (unsigned int)user_data, curr_value);
      break;
    case 4:
      v7 = this->part_array;
      if ( v7 )
        CPartArray::SetDiffusionInternal(v7, curr_value);
      break;
    case 6:
      v8 = this->part_array;
      if ( v8 )
        CPartArray::SetPartDiffusionInternal(v8, (unsigned int)user_data, curr_value);
      break;
    case 7:
      CPhysicsObj::CallPESInternal(this, (IDClass<_tagDataID,32,0>)user_data, curr_value);
      break;
    default:
      return;
  }
}

//----- (005136A0) --------------------------------------------------------  // acclient.c:320621
void __thiscall CPhysicsObj::SetScale(CPhysicsObj *this, float new_scale, long double delta)
{
  CPhysicsObj *v3; // esi@1
  CPartArray *v4; // ecx@2
  FPHook *v5; // eax@4
  int v6; // eax@5
  PhysicsObjHook *v7; // edx@7
  PhysicsObjHook *i; // ecx@7
  AC1Legacy::Vector3 v9; // [sp+4h] [bp-Ch]@3

  v3 = this;
  if ( delta >= 0.00019999999 )
  {
    v5 = (FPHook *)operator new(0x38u);
    if ( v5 )
      FPHook::FPHook(v5, 0, PhysicsTimer::curr_time, delta, v3->m_scale, new_scale, 0);
    else
      v6 = 0;
    v7 = v3->hooks;
    for ( i = v3->hooks; i; i = i->next )
      ;
    if ( v7 )
      v7->prev = (PhysicsObjHook *)v6;
    *(_DWORD *)(v6 + 36) = v3->hooks;
    v3->hooks = (PhysicsObjHook *)v6;
  }
  else
  {
    v4 = this->part_array;
    v3->m_scale = new_scale;
    if ( v4 )
    {
      v9.y = new_scale;
      v9.x = new_scale;
      v9.z = new_scale;
      CPartArray::SetScaleInternal(v4, &v9);
    }
  }
}

//----- (00513770) --------------------------------------------------------  // acclient.c:320662
void __thiscall CPhysicsObj::queue_netblob(CPhysicsObj *this, NetBlob *blob)
{
  CPhysicsObj *v2; // esi@1
  void *v3; // eax@2
  NIList<NetBlob *> *v4; // esi@6
  void *v5; // eax@6
  NIListElement<NetBlob *> *v6; // ecx@9

  v2 = this;
  if ( !this->netblob_list )
  {
    v3 = operator new(8u);
    if ( v3 )
    {
      *(_DWORD *)v3 = 0;
      *((_DWORD *)v3 + 1) = 0;
    }
    else
    {
      v3 = 0;
    }
    v2->netblob_list = (NIList<NetBlob *> *)v3;
  }
  InterlockedIncrement((volatile LONG *)&blob->m_cRef);
  v4 = v2->netblob_list;
  v5 = operator new(8u);
  if ( v5 )
  {
    *(_DWORD *)v5 = blob;
    *((_DWORD *)v5 + 1) = 0;
  }
  else
  {
    v5 = 0;
  }
  v6 = v4->tail_;
  if ( v6 )
  {
    v6->next_ = (NIListElement<NetBlob *> *)v5;
    v4->tail_ = v4->tail_->next_;
  }
  else
  {
    v4->head_ = (NIListElement<NetBlob *> *)v5;
    v4->tail_ = (NIListElement<NetBlob *> *)v5;
  }
}

//----- (005137F0) --------------------------------------------------------  // acclient.c:320711
void __thiscall LongNIValHash<CPhysicsObj::CollisionRecord>::LongNIValHash<CPhysicsObj::CollisionRecord>(LongNIValHash<CPhysicsObj::CollisionRecord> *this, unsigned int _table_size)
{
  HashBase<unsigned long> *v2; // esi@1

  v2 = (HashBase<unsigned long> *)this;
  this->vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  this->fPlacementNew_ = 0;
  this->buckets = (HashBaseData<unsigned long> **)operator new[](4 * _table_size);
  HashBase<unsigned long>::InternalInit(v2, _table_size);
  v2->vfptr = (HashBase<unsigned long>Vtbl *)&LongNIValHash<CPhysicsObj::CollisionRecord>::vftable;
}
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);
// 7C6B4C: using guessed type int (__thiscall *LongNIValHash<CPhysicsObj::CollisionRecord>::vftable)(void *, char);

//----- (00513830) --------------------------------------------------------  // acclient.c:320726
int __thiscall LongNIValHash<CPhysicsObj::CollisionRecord>::clobber(LongNIValHash<CPhysicsObj::CollisionRecord> *this, CPhysicsObj::CollisionRecord *data, unsigned int key)
{
  void *v3; // eax@1
  int v4; // ecx@2
  int v5; // edx@2
  int v6; // edi@2
  int v7; // ebx@2
  int v8; // ebp@2
  int result; // eax@4
  HashBase<unsigned long> *v10; // [sp+0h] [bp-4h]@1

  v10 = (HashBase<unsigned long> *)this;
  v3 = operator new(0x20u);
  if ( v3 )
  {
    v4 = LODWORD(data->touched_time);
    v5 = HIDWORD(data->touched_time);
    v6 = data->ethereal;
    v7 = *(&data->ethereal + 1);
    *((_DWORD *)v3 + 2) = key;
    v8 = (int)((char *)v3 + 16);
    *(_DWORD *)v8 = v4;
    *(_DWORD *)(v8 + 4) = v5;
    *(_DWORD *)(v8 + 8) = v6;
    *(_DWORD *)(v8 + 12) = v7;
    *((_DWORD *)v3 + 1) = 0;
    *(_DWORD *)v3 = LongHashData::vftable;
  }
  else
  {
    v3 = 0;
  }
  result = (int)HashBase<unsigned long>::clobber(v10, (HashBaseData<unsigned long> *)v3);
  if ( result )
  {
    *(_QWORD *)&data->touched_time = *(_QWORD *)(result + 16);
    data->ethereal = *(_DWORD *)(result + 24);
    *(&data->ethereal + 1) = *(_DWORD *)(result + 28);
    (**(void (__thiscall ***)(_DWORD, _DWORD))result)(result, 1);
    result = 1;
  }
  return result;
}
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);

//----- (00513910) --------------------------------------------------------  // acclient.c:320795
int __thiscall CPhysicsObj::InitNullObject(CPhysicsObj *this, IDClass<_tagDataID,32,0> data_did)
{
  CPhysicsObj *v2; // esi@1
  CPartArray *v3; // ecx@1
  int result; // eax@2
  CPartArray *v5; // ecx@5
  unsigned int v6; // eax@7
  CPartArray *v7; // ecx@8

  v2 = this;
  v3 = this->part_array;
  if ( v3 )
    result = CPartArray::SetSetupID(v3, data_did, 1);
  else
    result = CPhysicsObj::InitPartArrayObject(v2, data_did, 1);
  if ( result )
  {
    v5 = v2->part_array;
    if ( v5 )
      CPartArray::SetPlacementFrame(v5, 0x65u);
    v6 = v2->state;
    if ( !(BYTE1(v6) & 0x10) )
    {
      v7 = v2->part_array;
      if ( v7 )
        CPartArray::SetFrame(v7, &v2->m_position.frame);
    }
    result = 1;
  }
  return result;
}

//----- (00513970) --------------------------------------------------------  // acclient.c:320828
CPhysicsObj *__cdecl CPhysicsObj::makeObject(IDClass<_tagDataID,32,0> data_did, unsigned int object_iid, int bDynamic)
{
  CPhysicsObj *v3; // eax@1
  CPhysicsObj *v4; // eax@2
  CPhysicsObj *v5; // esi@2
  CPhysicsObj *v6; // ecx@3

  v3 = (CPhysicsObj *)operator new(0x178u);
  if ( v3 )
  {
    CPhysicsObj::CPhysicsObj(v3);
    v5 = v4;
    if ( v4 )
    {
      if ( CPhysicsObj::InitObjectBegin(v4, object_iid, bDynamic)
        && CPhysicsObj::InitPartArrayObject(v6, data_did, 1)
        && CPhysicsObj::InitObjectEnd(v5) )
        return v5;
      v5->vfptr->__vecDelDtor((HashBaseData<unsigned long> *)v5, 1u);
    }
  }
  return 0;
}

//----- (005139D0) --------------------------------------------------------  // acclient.c:320853
void __thiscall CPhysicsObj::InitDefaults(CPhysicsObj *this, CSetup *setup)
{
  CPhysicsObj *v2; // esi@1
  unsigned int v3; // edi@5
  CSoundTable *v4; // ecx@6
  QualifiedDataID *v5; // eax@9
  unsigned int v6; // edi@10
  PhysicsScriptTable *v7; // ecx@11
  QualifiedDataID *v8; // eax@14
  unsigned int v9; // eax@15
  QualifiedDataID v10; // [sp+8h] [bp-8h]@9

  v2 = this;
  if ( setup->default_script_id.id )
    CPhysicsObj::play_script_internal(this, setup->default_script_id);
  if ( setup->default_mtable_id.id )
    CPhysicsObj::SetMotionTableID(v2, setup->default_mtable_id);
  v3 = setup->default_stable_id.id;
  if ( v3 )
  {
    v4 = v2->sound_table;
    if ( v4 )
    {
      ((void (*)(void))v4->vfptr->Release)();
      v2->sound_table = 0;
    }
    if ( v3 )
    {
      QualifiedDataID::QualifiedDataID(&v10, (IDClass<_tagDataID,32,0>)v3, 0x22u);
      v2->sound_table = (CSoundTable *)DBObj::Get(v5);
    }
  }
  v6 = setup->default_phstable_id.id;
  if ( v6 )
  {
    v7 = v2->physics_script_table;
    if ( v7 )
    {
      ((void (*)(void))v7->vfptr->Release)();
      v2->physics_script_table = 0;
    }
    if ( v6 )
    {
      QualifiedDataID::QualifiedDataID(&v10, (IDClass<_tagDataID,32,0>)v6, 0x2Cu);
      v2->physics_script_table = (PhysicsScriptTable *)DBObj::Get(v8);
    }
  }
  v9 = v2->state;
  if ( v9 & 1 )
  {
    if ( setup->default_anim_id.id )
      v2->state = v9 | 0x40000;
    if ( setup->default_script_id.id )
      v2->state |= 0x80000u;
    if ( v2->state & 0xC0000 )
      CPhysics::AddStaticAnimatingObject(v2);
  }
}

//----- (00513AD0) --------------------------------------------------------  // acclient.c:320913
void __thiscall CPhysicsObj::Destroy(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  MovementManager *v2; // edi@1
  PositionManager *v3; // edi@3
  ParticleManager *v4; // edi@5
  void *v5; // edi@7
  PhysicsObjHook *v6; // eax@9
  PhysicsObjHook *v7; // edi@10
  unsigned int v8; // eax@11
  PhysicsScriptTable *v9; // ecx@14
  NIList<NetBlob *> *v10; // eax@16
  NIList<NetBlob *> *v11; // ecx@18
  NIListElement<NetBlob *> *v12; // eax@18
  NetBlob *v13; // edi@19
  NIListElement<NetBlob *> *v14; // edx@20
  void *v15; // edi@27
  CSoundTable *v16; // ecx@30
  unsigned int v17; // eax@32
  CPartArray *v18; // ecx@33
  void *v19; // edi@35
  LongNIValHash<CPhysicsObj::CollisionRecord> *v20; // ecx@37
  void *v21; // edi@39
  void *v22; // edi@41
  void *v23; // edi@43
  void *v24; // edi@45

  v1 = this;
  v2 = this->movement_manager;
  if ( v2 )
  {
    MovementManager::Destroy(this->movement_manager);
    operator delete(v2);
  }
  v3 = v1->position_manager;
  v1->movement_manager = 0;
  if ( v3 )
  {
    PositionManager::~PositionManager(v3);
    operator delete(v3);
  }
  v4 = v1->particle_manager;
  v1->position_manager = 0;
  if ( v4 )
  {
    ParticleManager::~ParticleManager(v4);
    operator delete(v4);
    v1->particle_manager = 0;
  }
  v5 = v1->script_manager;
  if ( v5 )
  {
    ScriptManager::~ScriptManager(v1->script_manager);
    operator delete(v5);
    v1->script_manager = 0;
  }
  v6 = v1->hooks;
  if ( v6 )
  {
    do
    {
      v7 = v6->next;
      v6->vfptr = (PhysicsObjHookVtbl *)&PhysicsObjHook::vftable;
      operator delete(v6);
      v6 = v7;
    }
    while ( v7 );
  }
  v8 = v1->state;
  v1->hooks = 0;
  if ( v8 & 1 && v8 & 0xC0000 )
    CPhysics::RemoveStaticAnimatingObject(v1);
  v9 = v1->physics_script_table;
  if ( v9 )
  {
    ((void (*)(void))v9->vfptr->Release)();
    v1->physics_script_table = 0;
  }
  v10 = v1->netblob_list;
  if ( v10 )
  {
    if ( v10->head_ )
    {
      do
      {
        v11 = v1->netblob_list;
        v12 = v11->head_;
        if ( v11->head_ )
        {
          v14 = v12->next_;
          v11->head_ = v14;
          if ( !v14 )
            v11->tail_ = 0;
          v13 = v12->data_;
          operator delete(v12);
        }
        else
        {
          v13 = 0;
        }
        if ( !InterlockedDecrement((volatile LONG *)&v13->m_cRef) && v13 )
          v13->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v13, 1u);
      }
      while ( v1->netblob_list->head_ );
    }
    v15 = v1->netblob_list;
    if ( v15 )
    {
      NIList<unsigned long>::DeleteContents((NIList<NetPacket *> *)v1->netblob_list);
      operator delete(v15);
    }
    v1->netblob_list = 0;
  }
  v16 = v1->sound_table;
  if ( v16 )
  {
    ((void (*)(void))v16->vfptr->Release)();
    v1->sound_table = 0;
  }
  v17 = v1->state;
  v1->m_position.objcell_id = 0;
  if ( !(BYTE1(v17) & 0x10) )
  {
    v18 = v1->part_array;
    if ( v18 )
      CPartArray::SetCellID(v18, 0);
  }
  v19 = v1->part_array;
  if ( v19 )
  {
    CPartArray::~CPartArray(v1->part_array);
    operator delete(v19);
    v1->part_array = 0;
  }
  *(_DWORD *)&v1->update_times[0] = 0;
  *(_DWORD *)&v1->update_times[2] = 0;
  *(_DWORD *)&v1->update_times[4] = 0;
  *(_DWORD *)&v1->update_times[6] = 0;
  v1->update_times[8] = 0;
  v20 = v1->collision_table;
  v1->weenie_obj = 0;
  if ( v20 )
  {
    ((void (__stdcall *)(_DWORD))v20->vfptr->__vecDelDtor)(1);
    v1->collision_table = 0;
  }
  v21 = v1->detection_manager;
  if ( v21 )
  {
    DetectionManager::~DetectionManager(v1->detection_manager);
    operator delete(v21);
    v1->detection_manager = 0;
  }
  v22 = v1->attack_manager;
  if ( v22 )
  {
    AttackManager::~AttackManager(v1->attack_manager);
    operator delete(v22);
    v1->attack_manager = 0;
  }
  v23 = v1->target_manager;
  if ( v23 )
  {
    TargetManager::~TargetManager(v1->target_manager);
    operator delete(v23);
    v1->target_manager = 0;
  }
  v24 = v1->children;
  if ( v24 )
  {
    CHILDLIST::~CHILDLIST(v1->children);
    operator delete(v24);
    v1->children = 0;
  }
  v1->transient_state = 0;
  v1->state = 4197384;
}
// 7C6B20: using guessed type void *PhysicsObjHook::vftable;

//----- (00513D30) --------------------------------------------------------  // acclient.c:321093
void __thiscall CPhysicsObj::~CPhysicsObj(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  CShadowObj *v2; // ecx@1

  v1 = this;
  this->vfptr = (HashBaseData<unsigned long>Vtbl *)CPhysicsObj::vftable;
  CPhysicsObj::Destroy(this);
  operator delete[](v1->anim_hooks.m_data);
  v2 = v1->shadow_objects.data;
  if ( v2 )
  {
    if ( v2[-1].cell )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(3);
    else
      operator delete[](&v2[-1].cell);
  }
  v1->shadow_objects.data = 0;
  v1->m_position.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (HashBaseData<unsigned long>Vtbl *)LongHashData::vftable;
  v1->hash_next = 0;
  v1->id = 0;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);
// 7C6B48: using guessed type int (__thiscall *CPhysicsObj::vftable[2])(void *, char);

//----- (00513DA0) --------------------------------------------------------  // acclient.c:321121
void __thiscall CPhysicsObj::UpdateChildrenInternal(CPhysicsObj *this)
{
  CPhysicsObj *v1; // edi@1
  CHILDLIST *v2; // eax@2
  unsigned __int16 v3; // si@3

  v1 = this;
  if ( this->part_array )
  {
    v2 = this->children;
    if ( v2 )
    {
      v3 = 0;
      if ( v2->num_objects )
      {
        do
        {
          CPhysicsObj::UpdateChild(v1, v2->objects.data[v3], v2->part_numbers.data[v3], &v2->frames.data[v3]);
          v2 = v1->children;
          ++v3;
        }
        while ( v3 < v2->num_objects );
      }
    }
  }
}

//----- (00513DF0) --------------------------------------------------------  // acclient.c:321149
void __thiscall CPhysicsObj::animate_static_object(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  unsigned int v2; // ecx@2
  long double v3; // st7@2
  unsigned int v4; // edx@7
  CPartArray *v5; // ecx@8
  float quantum; // ST00_4@10
  ScriptManager *v7; // ecx@12
  ParticleManager *v8; // ecx@14
  unsigned int v9; // edx@17

  v1 = this;
  if ( this->cell )
  {
    v2 = Timer::cur_time.Param;
    *(_QWORD *)&PhysicsTimer::curr_time = Timer::cur_time;
    v3 = COERCE_DOUBLE(Timer::cur_time.Cmd) - v1->update_time;
    if ( v3 > 0.00019999999 )
    {
      if ( v3 >= MIN_QUANTUM_97 )
      {
        if ( v3 <= 2.0 )
        {
          v5 = v1->part_array;
          if ( v5 )
          {
            if ( v1->state & 0x40000 )
            {
              quantum = v3;
              CPartArray::Update(v5, quantum, 0);
              Frame::grotate(&v1->m_position.frame, &v1->m_omegaVector);
              CPhysicsObj::UpdatePartsInternal(v1);
              CPhysicsObj::UpdateChildrenInternal(v1);
            }
            if ( v1->state & 0x80000 )
            {
              v7 = v1->script_manager;
              if ( v7 )
                ScriptManager::UpdateScripts(v7);
            }
            v8 = v1->particle_manager;
            if ( v8 )
              ParticleManager::UpdateParticles(v8);
            CPhysicsObj::process_hooks(v1);
          }
          v9 = Timer::cur_time.Param;
          LODWORD(v1->update_time) = Timer::cur_time.Cmd;
          HIDWORD(v1->update_time) = v9;
        }
        else
        {
          v4 = Timer::cur_time.Param;
          LODWORD(v1->update_time) = Timer::cur_time.Cmd;
          HIDWORD(v1->update_time) = v4;
        }
      }
    }
    else
    {
      LODWORD(v1->update_time) = Timer::cur_time.Cmd;
      HIDWORD(v1->update_time) = v2;
    }
  }
}

//----- (00513F10) --------------------------------------------------------  // acclient.c:321216
int __thiscall CPhysicsObj::track_object_collision(CPhysicsObj *this, CPhysicsObj *object, int prev_has_contact)
{
  CPhysicsObj *v3; // esi@1
  int result; // eax@2
  LongNIValHash<CPhysicsObj::CollisionRecord> *v5; // eax@4
  LongNIValHash<CPhysicsObj::CollisionRecord> *v6; // eax@5
  LongNIValHash<CPhysicsObj::CollisionRecord> *v7; // ecx@8
  unsigned int v8; // eax@9
  CPhysicsObj::CollisionRecord record; // [sp+Ch] [bp-10h]@9

  v3 = this;
  if ( object->state & 1 )
  {
    result = CPhysicsObj::report_environment_collision(this, prev_has_contact);
  }
  else
  {
    if ( !this->collision_table )
    {
      v5 = (LongNIValHash<CPhysicsObj::CollisionRecord> *)operator new(0x18u);
      if ( v5 )
        LongNIValHash<CPhysicsObj::CollisionRecord>::LongNIValHash<CPhysicsObj::CollisionRecord>(v5, 4u);
      else
        v6 = 0;
      v3->collision_table = v6;
    }
    v7 = v3->collision_table;
    if ( v7 )
    {
      record.touched_time = PhysicsTimer::curr_time;
      v8 = object->id;
      record.ethereal = object->state & 4;
      if ( LongNIValHash<CPhysicsObj::CollisionRecord>::clobber(v7, &record, v8) )
        result = 0;
      else
        result = CPhysicsObj::report_object_collision(v3, object, prev_has_contact);
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (00513FD0) --------------------------------------------------------  // acclient.c:321262
void __thiscall CPhysicsObj::report_collision_start(CPhysicsObj *this)
{
  CPhysicsObj *v1; // ebp@1
  LongNIValHash<CPhysicsObj::CollisionRecord> *v2; // eax@1
  unsigned int v3; // edi@1
  void *v4; // ebx@2
  HashBaseData<unsigned long> *v5; // esi@2
  HashBaseData<unsigned long> *v6; // eax@8
  unsigned int object_id; // [sp+8h] [bp-18h]@0
  LongNIValHashIter<CPhysicsObj::CollisionRecord> iter; // [sp+Ch] [bp-14h]@2

  v1 = this;
  v2 = this->collision_table;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->collision_table;
    v5 = *v2->buckets;
    iter.myHash_ = (HashBase<unsigned long> *)&this->collision_table->vfptr;
    iter.lastThisChain_ = 0;
    iter.curBucket_ = 0;
    iter.fEnd_ = 0;
    iter.curPtr_ = v5;
    if ( v5 )
      goto LABEL_5;
    HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&iter.myHash_);
    if ( !iter.fEnd_ )
    {
      v5 = iter.curPtr_;
      v3 = iter.curBucket_;
      v4 = iter.myHash_;
      while ( 1 )
      {
LABEL_5:
        if ( v5 )
          object_id = v5->id;
        if ( CPhysicsObj::obj_maint )
        {
          v6 = CObjectMaint::GetObjectA(CPhysicsObj::obj_maint, object_id);
          if ( v6 )
            CPhysicsObj::report_object_collision(v1, (CPhysicsObj *)v6, v1->transient_state & 1);
        }
        if ( !v5 )
          break;
        v5 = v5->hash_next;
        if ( !v5 )
          break;
LABEL_14:
        if ( iter.fEnd_ )
          return;
      }
      while ( 1 )
      {
        ++v3;
        if ( v3 >= *((_DWORD *)v4 + 4) )
          break;
        v5 = *(HashBaseData<unsigned long> **)(*((_DWORD *)v4 + 3) + 4 * v3);
        if ( v5 )
          goto LABEL_14;
      }
    }
  }
}

//----- (00514090) --------------------------------------------------------  // acclient.c:321327
void __thiscall CPhysicsObj::set_frame(CPhysicsObj *this, Frame *i_frame)
{
  CPhysicsObj *v2; // esi@1
  unsigned int v3; // eax@4
  CPartArray *v4; // ecx@5
  Frame frame; // [sp+8h] [bp-40h]@1

  v2 = this;
  Frame::operator=((int)&frame, (int)i_frame);
  if ( !Frame::IsValid(&frame) && Frame::IsValidExceptForHeading(&frame) )
  {
    LODWORD(frame.qw) = 0;
    LODWORD(frame.qx) = 0;
    LODWORD(frame.qy) = 0;
    LODWORD(frame.qz) = 0;
  }
  Frame::operator=((int)&v2->m_position.frame, (int)&frame);
  v3 = v2->state;
  if ( !(BYTE1(v3) & 0x10) )
  {
    v4 = v2->part_array;
    if ( v4 )
      CPartArray::SetFrame(v4, &v2->m_position.frame);
  }
  CPhysicsObj::UpdateChildrenInternal(v2);
}

//----- (00514120) --------------------------------------------------------  // acclient.c:321355
void __thiscall CPhysicsObj::set_initial_frame(CPhysicsObj *this, Frame *frame)
{
  CPhysicsObj *v2; // esi@1
  Frame *v3; // edi@1
  unsigned int v4; // eax@1
  CPartArray *v5; // ecx@2

  v2 = this;
  v3 = &this->m_position.frame;
  Frame::operator=((int)&this->m_position.frame, (int)frame);
  v4 = v2->state;
  if ( !(BYTE1(v4) & 0x10) )
  {
    v5 = v2->part_array;
    if ( v5 )
      CPartArray::SetFrame(v5, v3);
  }
  CPhysicsObj::UpdateChildrenInternal(v2);
}

//----- (00514160) --------------------------------------------------------  // acclient.c:321376
void __thiscall CPhysicsObj::set_heading(CPhysicsObj *this, float degrees, int send_event)
{
  CPhysicsObj *v3; // esi@1
  Frame new_frame; // [sp+4h] [bp-40h]@1

  v3 = this;
  Frame::operator=((int)&new_frame, (int)&this->m_position.frame);
  Frame::set_heading(&new_frame, degrees);
  CPhysicsObj::set_frame(v3, &new_frame);
}

//----- (005141A0) --------------------------------------------------------  // acclient.c:321388
void __thiscall CPhysicsObj::store_position(CPhysicsObj *this, Position *p)
{
  CPhysicsObj *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // ecx@3
  CPartArray *v5; // ecx@4
  Position new_p; // [sp+4h] [bp-48h]@1

  v2 = this;
  new_p.objcell_id = p->objcell_id;
  Frame::operator=((int)&new_p.frame, (int)&p->frame);
  v3 = new_p.objcell_id;
  if ( LOWORD(new_p.objcell_id) < 0x100u )
  {
    LandDefs::adjust_to_outside(&new_p.objcell_id, &new_p.frame.m_fOrigin);
    v3 = new_p.objcell_id;
  }
  v4 = v2->state;
  v2->m_position.objcell_id = v3;
  if ( !(BYTE1(v4) & 0x10) )
  {
    v5 = v2->part_array;
    if ( v5 )
      CPartArray::SetCellID(v5, v3);
  }
  CPhysicsObj::set_frame(v2, &new_p.frame);
}

//----- (00514220) --------------------------------------------------------  // acclient.c:321417
void __thiscall CPhysicsObj::leave_visibility(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1

  v1 = this;
  CPhysicsObj::prepare_to_leave_visibility(this);
  CPhysicsObj::store_position(v1, &v1->m_position);
  CObjectMaint::GotoLostCell(CPhysicsObj::obj_maint, v1, v1->m_position.objcell_id);
  v1->transient_state &= 0xFFFFFF7F;
}

//----- (00514250) --------------------------------------------------------  // acclient.c:321429
void __thiscall DArray<CShadowObj>::grow(DArray<CShadowObj> *this, unsigned int size)
{
  DArray<CShadowObj> *v2; // esi@1
  void *v3; // eax@3
  int v4; // edi@4
  int v5; // ebp@4
  unsigned int v6; // edx@6
  int v7; // ecx@7
  int v8; // eax@8
  CShadowObj *v9; // ecx@9

  v2 = this;
  if ( size <= this->sizeOf )
  {
    DArray<CShadowObj>::shrink(this, size);
    return;
  }
  v3 = operator new[](24 * size + 4);
  if ( v3 )
  {
    v4 = (int)((char *)v3 + 4);
    *(_DWORD *)v3 = size;
    vector_constructor_iterator((char *)v3 + 4, 0x18u, size, (void *(__thiscall *)(void *))CShadowObj::CShadowObj);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v6 = 0;
  if ( v2->sizeOf )
  {
    v7 = v5 + 8;
    do
    {
      v8 = (int)((char *)v2->data + -8 - v5 + v7);
      *(_DWORD *)(v7 - 4) = *(_DWORD *)(v8 + 4);
      *(_DWORD *)v7 = *(_DWORD *)(v8 + 8);
      *(_DWORD *)(v7 + 4) = *(_DWORD *)(v8 + 12);
      *(_DWORD *)(v7 + 8) = *(_DWORD *)(v8 + 16);
      *(_DWORD *)(v7 + 12) = *(_DWORD *)(v8 + 20);
      ++v6;
      v7 += 24;
    }
    while ( v6 < v2->sizeOf );
  }
  v9 = v2->data;
  if ( v2->data )
  {
    if ( v9[-1].cell )
    {
      ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(3);
      v2->data = (CShadowObj *)v5;
      v2->sizeOf = size;
      return;
    }
    operator delete[](&v9[-1].cell);
  }
  v2->data = (CShadowObj *)v5;
  v2->sizeOf = size;
}

//----- (00514320) --------------------------------------------------------  // acclient.c:321492
LongNIValHash<CPhysicsObj::CollisionRecord> *__thiscall LongNIValHash<CPhysicsObj::CollisionRecord>::vector_deleting_destructor(LongNIValHash<CPhysicsObj::CollisionRecord> *this, unsigned int a2)
{
  LongNIValHash<CPhysicsObj::CollisionRecord> *v2; // esi@1

  v2 = this;
  LongNIValHash<CPhysicsObj::CollisionRecord>::~LongNIValHash<CPhysicsObj::CollisionRecord>(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00514340) --------------------------------------------------------  // acclient.c:321504
void __thiscall LongNIValHash<CPhysicsObj::CollisionRecord>::~LongNIValHash<CPhysicsObj::CollisionRecord>(LongNIValHash<CPhysicsObj::CollisionRecord> *this)
{
  LongNIValHash<CPhysicsObj::CollisionRecord> *v1; // esi@1
  int v2; // eax@3
  LongNIValHashIter<GlobalVoyeurInfo> v3; // [sp+4h] [bp-14h]@1

  v1 = this;
  this->vfptr = (HashBase<unsigned long>Vtbl *)&LongNIValHash<CPhysicsObj::CollisionRecord>::vftable;
  LongNIValHashIter<SurfInfo *>::LongNIValHashIter<SurfInfo *>(&v3, (LongNIValHash<GlobalVoyeurInfo> *)this);
  while ( !v3.fEnd_ )
    HashBaseIter<unsigned long>::DeleteCurrent((HashBaseIter<unsigned long> *)&v3.myHash_);
  v2 = v1->fPlacementNew_;
  v1->vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( !v2 )
    operator delete[](v1->buckets);
}
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);
// 7C6B4C: using guessed type int (__thiscall *LongNIValHash<CPhysicsObj::CollisionRecord>::vftable)(void *, char);

//----- (00514390) --------------------------------------------------------  // acclient.c:321524
void __thiscall DArray<CShadowObj>::shrink(DArray<CShadowObj> *this, unsigned int size)
{
  DArray<CShadowObj> *v2; // esi@1
  int v3; // ebp@3
  CShadowObj *v4; // ecx@4
  bool v5; // zf@4
  int v6; // eax@5
  void *v7; // eax@7
  int v8; // edi@8
  unsigned int v9; // edx@9
  int v10; // ecx@10
  int v11; // eax@11
  CShadowObj *v12; // ecx@12
  bool v13; // cf@16

  v2 = this;
  if ( size > this->sizeOf )
  {
    DArray<CShadowObj>::grow(this, size);
    return;
  }
  v3 = 0;
  if ( size )
  {
    v7 = operator new[](24 * size + 4);
    if ( v7 )
    {
      v8 = (int)((char *)v7 + 4);
      *(_DWORD *)v7 = size;
      vector_constructor_iterator((char *)v7 + 4, 0x18u, size, (void *(__thiscall *)(void *))CShadowObj::CShadowObj);
      v3 = v8;
    }
    v9 = 0;
    v2->sizeOf = size;
    if ( size )
    {
      v10 = v3 + 8;
      do
      {
        v11 = (int)((char *)v2->data + -8 - v3 + v10);
        *(_DWORD *)(v10 - 4) = *(_DWORD *)(v11 + 4);
        *(_DWORD *)v10 = *(_DWORD *)(v11 + 8);
        *(_DWORD *)(v10 + 4) = *(_DWORD *)(v11 + 12);
        *(_DWORD *)(v10 + 8) = *(_DWORD *)(v11 + 16);
        *(_DWORD *)(v10 + 12) = *(_DWORD *)(v11 + 20);
        ++v9;
        v10 += 24;
      }
      while ( v9 < v2->sizeOf );
    }
    v12 = v2->data;
    if ( !v2->data )
      goto LABEL_16;
    v6 = (int)&v12[-1].cell;
    if ( v12[-1].cell )
    {
      ((void (__stdcall *)(_DWORD))v12->vfptr->__vecDelDtor)(3);
      goto LABEL_16;
    }
  }
  else
  {
    v4 = this->data;
    v5 = v2->data == 0;
    v2->sizeOf = 0;
    if ( v5 )
      goto LABEL_16;
    v6 = (int)&v4[-1].cell;
    if ( v4[-1].cell )
    {
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(3);
      goto LABEL_16;
    }
  }
  operator delete[]((void *)v6);
LABEL_16:
  v13 = v2->next_available < size;
  v5 = v2->next_available == size;
  v2->data = (CShadowObj *)v3;
  if ( !v13 && !v5 )
    v2->next_available = size;
}

//----- (00514490) --------------------------------------------------------  // acclient.c:321608
CPhysicsObj *__thiscall CPhysicsObj::scalar_deleting_destructor(CPhysicsObj *this, unsigned int a2)
{
  CPhysicsObj *v2; // esi@1

  v2 = this;
  CPhysicsObj::~CPhysicsObj(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005144B0) --------------------------------------------------------  // acclient.c:321620
CPhysicsObj *__cdecl CPhysicsObj::makeObject(CPhysicsObj *pTemplate)
{
  CPhysicsObj *v1; // edi@1
  CPartArray *v2; // ecx@1
  CPhysicsObj *v3; // eax@4
  CPhysicsObj *v4; // esi@4
  CPartArray *v5; // eax@5
  CSetup *v6; // eax@6
  IDClass<_tagDataID,32,0> v7; // ecx@7

  v1 = pTemplate;
  v2 = pTemplate->part_array;
  if ( v2 )
    CPartArray::GetDataID(v2, (IDClass<_tagDataID,32,0> *)&pTemplate);
  else
    pTemplate = (CPhysicsObj *)stru_843D84.id;
  v3 = CPhysicsObj::makeObject((IDClass<_tagDataID,32,0>)pTemplate, 0, 1);
  v4 = v3;
  if ( v3 )
  {
    CPhysicsObj::MorphToExistingObject(v3, v1);
    v5 = v4->part_array;
    if ( v5 )
    {
      v6 = v5->setup;
      if ( v6 )
      {
        v7.id = v6->default_script_id.id;
        if ( v7.id )
          CPhysicsObj::play_script_internal(v4, v7);
      }
    }
  }
  return v4;
}

//----- (00514520) --------------------------------------------------------  // acclient.c:321657
void __thiscall CPhysicsObj::update_position(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  unsigned int v2; // ecx@2
  long double v3; // st7@2
  unsigned int v4; // edx@7
  float v5; // ST00_4@8
  ParticleManager *v6; // ecx@8
  ScriptManager *v7; // ecx@10
  unsigned int v8; // eax@12
  Frame new_frame; // [sp+18h] [bp-40h]@8

  v1 = this;
  if ( !this->parent )
  {
    v2 = Timer::cur_time.Param;
    *(_QWORD *)&PhysicsTimer::curr_time = Timer::cur_time;
    v3 = COERCE_DOUBLE(Timer::cur_time.Cmd) - v1->update_time;
    if ( v3 > 0.00019999999 )
    {
      if ( v3 >= MIN_QUANTUM_97 )
      {
        if ( v3 <= 2.0 )
        {
          Frame::Frame(&new_frame);
          v5 = v3;
          CPhysicsObj::UpdatePositionInternal(v1, v5, &new_frame);
          CPhysicsObj::set_frame(v1, &new_frame);
          v6 = v1->particle_manager;
          if ( v6 )
            ParticleManager::UpdateParticles(v6);
          v7 = v1->script_manager;
          if ( v7 )
            ScriptManager::UpdateScripts(v7);
          v8 = Timer::cur_time.Param;
          LODWORD(v1->update_time) = Timer::cur_time.Cmd;
          HIDWORD(v1->update_time) = v8;
        }
        else
        {
          v4 = Timer::cur_time.Param;
          LODWORD(v1->update_time) = Timer::cur_time.Cmd;
          HIDWORD(v1->update_time) = v4;
        }
      }
    }
    else
    {
      LODWORD(v1->update_time) = Timer::cur_time.Cmd;
      HIDWORD(v1->update_time) = v2;
    }
  }
}

//----- (00514620) --------------------------------------------------------  // acclient.c:321712
void __thiscall CPhysicsObj::report_collision_end(CPhysicsObj *this, const int force_end)
{
  LongNIValHash<CPhysicsObj::CollisionRecord> *v2; // eax@1
  HashBaseData<unsigned long> *v3; // edi@2
  unsigned int v4; // ebx@5
  unsigned int v5; // esi@5
  const int v6; // ebp@5
  unsigned int v7; // eax@8
  int v8; // edx@8
  int v9; // eax@8
  unsigned int v10; // eax@15
  int v11; // eax@17
  unsigned int v12; // esi@20
  CPhysicsObj *v13; // [sp+4h] [bp-34h]@1
  AC1Legacy::SmartArray<unsigned long> end_array; // [sp+8h] [bp-30h]@5
  CPhysicsObj::CollisionRecord record; // [sp+14h] [bp-24h]@8
  LongNIValHashIter<CPhysicsObj::CollisionRecord> iter; // [sp+24h] [bp-14h]@2

  v2 = this->collision_table;
  v13 = this;
  if ( v2 )
  {
    iter.myHash_ = (HashBase<unsigned long> *)&this->collision_table->vfptr;
    v3 = *v2->buckets;
    iter.lastThisChain_ = 0;
    iter.curBucket_ = 0;
    iter.fEnd_ = 0;
    iter.curPtr_ = v3;
    if ( !v3 )
    {
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&iter.myHash_);
      if ( iter.fEnd_ )
        return;
      v3 = iter.curPtr_;
    }
    end_array.m_data = 0;
    end_array.m_size = 0;
    end_array.m_num = 0;
    AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&end_array, 0xAu);
    v4 = end_array.m_num;
    v5 = end_array.m_size;
    v6 = force_end;
    while ( 1 )
    {
      if ( v3 )
      {
        v6 = v3->id;
        v7 = v3[1].id;
        LODWORD(record.touched_time) = v3[1].hash_next;
        v8 = (int)v3[2].vfptr;
        HIDWORD(record.touched_time) = v7;
        v9 = (int)v3[2].hash_next;
        record.ethereal = v8;
        *(&record.ethereal + 1) = v9;
      }
      if ( PhysicsTimer::curr_time - record.touched_time > 1.0
        || record.ethereal && PhysicsTimer::curr_time - record.touched_time > 0.0
        || force_end )
      {
        HashBaseIter<unsigned long>::DeleteCurrent((HashBaseIter<unsigned long> *)&iter.myHash_);
        if ( v4 < v5 )
          goto LABEL_25;
        v10 = 2 * v5;
        if ( !v5 )
          v10 = 8;
        v11 = AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&end_array, v10);
        v5 = end_array.m_size;
        v4 = end_array.m_num;
        if ( v11 )
        {
LABEL_25:
          end_array.m_data[v4++] = v6;
          end_array.m_num = v4;
        }
      }
      else
      {
        HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&iter.myHash_);
      }
      if ( iter.fEnd_ )
        break;
      v3 = iter.curPtr_;
    }
    v12 = 0;
    if ( v4 )
    {
      do
        CPhysicsObj::report_object_collision_end(v13, end_array.m_data[v12++]);
      while ( v12 < v4 );
    }
    operator delete[](end_array.m_data);
  }
}

//----- (00514780) --------------------------------------------------------  // acclient.c:321807
int __thiscall CPhysicsObj::handle_all_collisions(CPhysicsObj *this, COLLISIONINFO *collisions, int prev_has_contact, int prev_on_walkable)
{
  unsigned int v4; // ebp@1
  CPhysicsObj *v5; // esi@1
  CPhysicsObj *v6; // eax@6
  int v7; // eax@10
  int v8; // eax@15
  signed int v9; // edx@15
  int v10; // ecx@17
  int v11; // eax@18
  int v12; // eax@23
  double v13; // st7@24
  double v14; // st7@25
  float v15; // ST24_4@25
  float v16; // ST28_4@25
  int result; // eax@27
  unsigned int v18; // eax@28
  int retval; // [sp+10h] [bp-14h]@5
  int apply_bounce; // [sp+14h] [bp-10h]@3

  v4 = 0;
  v5 = this;
  if ( !prev_on_walkable
    || !(this->transient_state & 2)
    || (apply_bounce = 0, (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & this->state) )
    apply_bounce = 1;
  retval = 0;
  if ( collisions->num_collide_object )
  {
    do
    {
      v6 = collisions->collide_object.data[v4];
      if ( v6 && CPhysicsObj::track_object_collision(v5, v6, prev_has_contact) )
        retval = 1;
      ++v4;
    }
    while ( v4 < collisions->num_collide_object );
  }
  CPhysicsObj::report_collision_end(v5, 0);
  v7 = collisions->collided_with_environment;
  if ( v5->colliding_with_environment )
  {
    v5->colliding_with_environment = v7 != 0;
LABEL_16:
    v9 = retval;
    goto LABEL_17;
  }
  if ( !v7 && (prev_on_walkable || !(v5->transient_state & 2)) )
    goto LABEL_16;
  v8 = CPhysicsObj::report_environment_collision(v5, prev_has_contact);
  v9 = 1;
  if ( !v8 )
    goto LABEL_16;
LABEL_17:
  v10 = collisions->frames_stationary_fall;
  if ( v10 <= 1 )
  {
    if ( apply_bounce && collisions->collision_normal_valid )
    {
      if ( v5->state & 0x20000 )
      {
        v12 = (int)&v5->m_velocityVector;
        *(_DWORD *)v12 = 0;
        *(_DWORD *)(v12 + 4) = 0;
        *(_DWORD *)(v12 + 8) = 0;
      }
      else
      {
        v13 = v5->m_velocityVector.z * collisions->collision_normal.z
            + v5->m_velocityVector.y * collisions->collision_normal.y
            + collisions->collision_normal.x * v5->m_velocityVector.x;
        if ( v13 < 0.0 )
        {
          v14 = -(v13 * (v5->elasticity + 1.0));
          v15 = v14 * collisions->collision_normal.y;
          v16 = v14 * collisions->collision_normal.z;
          v5->m_velocityVector.x = v14 * collisions->collision_normal.x + v5->m_velocityVector.x;
          v5->m_velocityVector.y = v15 + v5->m_velocityVector.y;
          v5->m_velocityVector.z = v16 + v5->m_velocityVector.z;
        }
      }
    }
  }
  else
  {
    v11 = (int)&v5->m_velocityVector;
    *(_DWORD *)v11 = 0;
    *(_DWORD *)(v11 + 4) = 0;
    *(_DWORD *)(v11 + 8) = 0;
    if ( v10 == 3 )
    {
LABEL_27:
      v5->transient_state &= 0xFFFFFF8F;
      return v9;
    }
  }
  if ( !v10 )
    goto LABEL_27;
  v18 = v5->transient_state;
  if ( v10 == 1 )
  {
    v5->transient_state = v18 | 0x10;
    result = v9;
  }
  else if ( v10 == 2 )
  {
    v5->transient_state = v18 | 0x20;
    result = v9;
  }
  else
  {
    v5->transient_state = v18 | 0x40;
    result = v9;
  }
  return result;
}

//----- (005149E0) --------------------------------------------------------  // acclient.c:321925
void __thiscall CPhysicsObj::AddObjectToSingleCell(CPhysicsObj *this, CObjCell *obj_cell)
{
  CPhysicsObj *v2; // esi@1
  CObjCell *v3; // eax@1
  bool v4; // cf@5
  CPartArray *v5; // ecx@7

  v2 = this;
  v3 = this->cell;
  if ( v3 )
  {
    if ( obj_cell == v3 )
      return;
    CPhysicsObj::RemoveObjectFromSingleCell(this, this->cell);
  }
  CPhysicsObj::change_cell(v2, obj_cell);
  if ( obj_cell )
  {
    v4 = v2->shadow_objects.sizeOf < 1;
    v2->num_shadow_objects = 1;
    if ( v4 )
      DArray<CShadowObj>::grow(&v2->shadow_objects, 1u);
    CShadowObj::set_physobj(v2->shadow_objects.data, v2);
    v2->shadow_objects.data->cell_id = obj_cell->m_DID.id;
    CObjCell::add_shadow_object(obj_cell, v2->shadow_objects.data, 1u);
    v5 = v2->part_array;
    if ( v5 )
      CPartArray::AddPartsShadow(v5, obj_cell, 1u);
  }
}

//----- (00514A70) --------------------------------------------------------  // acclient.c:321957
void __thiscall CPhysicsObj::add_particle_shadow_to_cell(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  bool v2; // cf@1
  CPartArray *v3; // ecx@3

  v1 = this;
  v2 = this->shadow_objects.sizeOf < 1;
  this->num_shadow_objects = 1;
  if ( v2 )
    DArray<CShadowObj>::grow(&this->shadow_objects, 1u);
  CShadowObj::set_physobj(v1->shadow_objects.data, v1);
  v1->shadow_objects.data->cell_id = v1->cell->m_DID.id;
  CObjCell::add_shadow_object(v1->cell, v1->shadow_objects.data, 1u);
  v3 = v1->part_array;
  if ( v3 )
    CPartArray::AddPartsShadow(v3, v1->cell, 1u);
}

//----- (00514AE0) --------------------------------------------------------  // acclient.c:321977
void __thiscall CPhysicsObj::add_shadows_to_cells(CPhysicsObj *this, CELLARRAY *cell_array)
{
  CPhysicsObj *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // ecx@3
  unsigned int v5; // eax@3
  unsigned int v6; // edi@5
  int v7; // ebx@6
  unsigned int v8; // ebp@8
  int v9; // ebx@9
  CObjCell *v10; // edi@10
  CPartArray *v11; // ecx@11
  unsigned int v12; // edi@15
  CHILDLIST *v13; // eax@16
  unsigned __int16 v14; // cx@17

  v2 = this;
  v3 = this->state;
  if ( BYTE1(v3) & 0x10 )
  {
    CPhysicsObj::add_particle_shadow_to_cell(this);
  }
  else
  {
    v4 = this->shadow_objects.sizeOf;
    v5 = cell_array->num_cells;
    v2->num_shadow_objects = v5;
    if ( v5 > v4 )
      DArray<CShadowObj>::grow(&v2->shadow_objects, v5);
    v6 = 0;
    if ( v2->num_shadow_objects )
    {
      v7 = 0;
      do
      {
        CShadowObj::set_physobj(&v2->shadow_objects.data[v7], v2);
        v2->shadow_objects.data[v7].cell_id = cell_array->cells.data[v6++].cell_id;
        ++v7;
      }
      while ( v6 < v2->num_shadow_objects );
    }
    v8 = 0;
    if ( v2->num_shadow_objects )
    {
      v9 = 0;
      do
      {
        v10 = cell_array->cells.data[v8].cell;
        if ( v10 )
        {
          CObjCell::add_shadow_object(v10, &v2->shadow_objects.data[v9], cell_array->num_cells);
          v11 = v2->part_array;
          if ( v11 )
            CPartArray::AddPartsShadow(v11, v10, v2->num_shadow_objects);
        }
        else
        {
          v2->shadow_objects.data[v9].cell = 0;
        }
        ++v8;
        ++v9;
      }
      while ( v8 < v2->num_shadow_objects );
    }
  }
  v12 = 0;
  while ( 1 )
  {
    v13 = v2->children;
    v14 = v13 ? v13->num_objects : 0;
    if ( v12 >= v14 )
      break;
    if ( v13 )
    {
      CPhysicsObj::add_shadows_to_cells(v13->objects.data[(unsigned __int16)v12++], cell_array);
    }
    else
    {
      CPhysicsObj::add_shadows_to_cells(0, cell_array);
      ++v12;
    }
  }
}

//----- (00514C20) --------------------------------------------------------  // acclient.c:322062
void __thiscall CPhysicsObj::add_anim_hook(CPhysicsObj *this, CAnimHook *hook)
{
  unsigned int v2; // eax@1
  char *v3; // esi@1
  unsigned int v4; // eax@3

  v2 = this->anim_hooks.m_size;
  v3 = (char *)&this->anim_hooks;
  if ( this->anim_hooks.m_num < v2
    || (!v2 ? (v4 = 8) : (v4 = 2 * v2),
        AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&this->anim_hooks, v4)) )
    *(_DWORD *)(*(_DWORD *)v3 + 4 * (*((_DWORD *)v3 + 2))++) = hook;
}

//----- (00514C60) --------------------------------------------------------  // acclient.c:322077
void __thiscall CPhysicsObj::set_hidden(CPhysicsObj *this, int hidden, int send_event)
{
  CPhysicsObj *v3; // esi@1
  unsigned int v4; // ecx@1
  PhysicsScriptTable *v5; // ecx@2
  unsigned __int16 i; // di@4
  CHILDLIST *v7; // eax@5
  CPhysicsObj *v8; // eax@7
  CPartArray *v9; // eax@7
  CObjCell *v10; // ecx@12
  CPartArray *v11; // ecx@14
  PhysicsScriptTable *v12; // ecx@16
  unsigned __int16 j; // di@18
  CHILDLIST *v14; // eax@19
  CPhysicsObj *v15; // eax@21
  CPartArray *v16; // eax@21
  unsigned int v17; // edx@24
  bool v18; // zf@24
  CPartArray *v19; // ecx@26
  CObjCell *v20; // ecx@28

  v3 = this;
  v4 = this->state;
  if ( hidden )
  {
    v3->state = v4 | 0x4000;
    v5 = v3->physics_script_table;
    if ( v5 )
    {
      PhysicsScriptTable::GetScript(v5, (IDClass<_tagDataID,32,0> *)&hidden, PS_Hidden, 1.0);
      CPhysicsObj::play_script_internal(v3, (IDClass<_tagDataID,32,0>)hidden);
    }
    for ( i = 0; ; ++i )
    {
      v7 = v3->children;
      if ( !v7 || i >= v7->num_objects )
        break;
      v8 = v7->objects.data[i];
      v8->state |= 0x20u;
      v9 = v8->part_array;
      if ( v9 )
        CPartArray::SetNoDrawInternal(v9, 1);
    }
    if ( v3->state & 8 )
    {
      CPhysicsObj::report_collision_end(v3, 1);
      v3->state &= 0xFFFFFFF7;
    }
    v3->state |= 0x10u;
    v10 = v3->cell;
    if ( v10 )
      CObjCell::hide_object(v10, v3);
    v11 = v3->part_array;
    if ( v11 )
      CPartArray::HandleEnterWorld(v11);
  }
  else
  {
    v3->state = v4 & 0xFFFFBFFF;
    v12 = v3->physics_script_table;
    if ( v12 )
    {
      PhysicsScriptTable::GetScript(v12, (IDClass<_tagDataID,32,0> *)&hidden, PS_UnHide, 1.0);
      CPhysicsObj::play_script_internal(v3, (IDClass<_tagDataID,32,0>)hidden);
    }
    for ( j = 0; ; ++j )
    {
      v14 = v3->children;
      if ( !v14 || j >= v14->num_objects )
        break;
      v15 = v14->objects.data[j];
      v15->state &= 0xFFFFFFDF;
      v16 = v15->part_array;
      if ( v16 )
        CPartArray::SetNoDrawInternal(v16, 0);
    }
    v17 = v3->state & 0xFFFFFFEF;
    v18 = (v3->state & 8) == 0;
    v3->state = v17;
    if ( v18 )
    {
      v3->state = v17 | 8;
      CPhysicsObj::report_collision_start(v3);
    }
    v19 = v3->part_array;
    if ( v19 )
      CPartArray::HandleEnterWorld(v19);
    v20 = v3->cell;
    if ( v20 )
      CObjCell::unhide_object(v20, v3);
  }
}

//----- (00514DD0) --------------------------------------------------------  // acclient.c:322171
int __thiscall CPhysicsObj::set_state(CPhysicsObj *this, unsigned int new_state, int send_event)
{
  CPhysicsObj *v3; // esi@1
  unsigned int v4; // ebx@1
  CPartArray *v5; // ecx@2

  v3 = this;
  v4 = new_state ^ this->state;
  this->state = new_state;
  if ( BYTE1(v4) & 8 )
  {
    v5 = this->part_array;
    if ( BYTE1(new_state) & 8 )
    {
      v3->state = new_state | 0x800;
      if ( v5 )
        CPartArray::InitLights(v5);
    }
    else
    {
      v3->state = new_state & 0xFFFFF7FF;
      if ( v5 )
        CPartArray::DestroyLights(v5);
    }
  }
  if ( v4 & 0x20 )
    CPhysicsObj::set_nodraw(v3, v3->state & 0x20, 0);
  if ( BYTE1(v4) & 0x40 )
    CPhysicsObj::set_hidden(v3, v3->state & 0x4000, 0);
  return 1;
}

//----- (00514E60) --------------------------------------------------------  // acclient.c:322204
void __thiscall CPhysicsObj::exit_world(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  CPartArray *v2; // ecx@1
  MovementManager *v3; // ecx@3
  PositionManager *v4; // ecx@5
  TargetManager *v5; // ecx@7
  DetectionManager *v6; // ecx@9

  v1 = this;
  v2 = this->part_array;
  if ( v2 )
    CPartArray::HandleExitWorld(v2);
  v3 = v1->movement_manager;
  if ( v3 )
    MovementManager::HandleExitWorld(v3);
  v4 = v1->position_manager;
  if ( v4 )
    PositionManager::UnStick(v4);
  v5 = v1->target_manager;
  if ( v5 )
  {
    TargetManager::ClearTarget(v5);
    TargetManager::NotifyVoyeurOfEvent(v1->target_manager, ExitWorld_TargetStatus);
  }
  v6 = v1->detection_manager;
  if ( v6 )
    DetectionManager::DestroyDetectionCylsphere(v6, 0);
  CPhysicsObj::report_collision_end(v1, 1);
}

//----- (00514ED0) --------------------------------------------------------  // acclient.c:322236
void __thiscall CPhysicsObj::teleport_hook(CPhysicsObj *this, int hide)
{
  CPhysicsObj *v2; // esi@1
  MovementManager *v3; // ecx@1
  PositionManager *v4; // ecx@3
  PositionManager *v5; // ecx@5
  PositionManager *v6; // ecx@7
  TargetManager *v7; // ecx@9

  v2 = this;
  v3 = this->movement_manager;
  if ( v3 )
    MovementManager::CancelMoveTo(v3, 0x3Cu);
  v4 = v2->position_manager;
  if ( v4 )
    PositionManager::UnStick(v4);
  v5 = v2->position_manager;
  if ( v5 )
    PositionManager::StopInterpolating(v5);
  v6 = v2->position_manager;
  if ( v6 )
    PositionManager::UnConstrain(v6);
  v7 = v2->target_manager;
  if ( v7 )
  {
    TargetManager::ClearTarget(v7);
    TargetManager::NotifyVoyeurOfEvent(v2->target_manager, Teleported_TargetStatus);
  }
  CPhysicsObj::report_collision_end(v2, 1);
}

//----- (00514F40) --------------------------------------------------------  // acclient.c:322268
int __thiscall CPhysicsObj::set_description(CPhysicsObj *this, PhysicsDesc *desc, int set_movement)
{
  PhysicsDesc *v3; // esi@1
  CPhysicsObj *v4; // edi@1
  IDClass<_tagDataID,32,0> *v5; // eax@1
  int result; // eax@1
  CSoundTable *v7; // ecx@2
  unsigned int v8; // ebx@2
  IDClass<_tagDataID,32,0> v9; // ebp@2
  QualifiedDataID *v10; // eax@5
  PhysicsScriptTable *v11; // ecx@6
  IDClass<_tagDataID,32,0> v12; // ebp@6
  QualifiedDataID *v13; // eax@9
  unsigned int v14; // eax@12
  unsigned int v15; // eax@13
  double v16; // st7@14
  CPartArray *v17; // ecx@14
  double v18; // st7@16
  float v19; // ecx@19
  float v20; // edx@19
  float v21; // eax@20
  CPartArray *v22; // ecx@20
  unsigned int v23; // ecx@22
  float v24; // edx@22
  unsigned int v25; // edx@22
  float v26; // eax@22
  int v27; // ecx@22
  PScriptType v28; // eax@22
  int v29; // edi@22
  void *packed_movement; // [sp+14h] [bp-10h]@10
  QualifiedDataID v31; // [sp+18h] [bp-Ch]@5
  float v32; // [sp+20h] [bp-4h]@15

  v3 = desc;
  v4 = this;
  v5 = PhysicsDesc::get_mtable_id(desc, (IDClass<_tagDataID,32,0> *)&desc);
  result = CPhysicsObj::SetMotionTableID(v4, (IDClass<_tagDataID,32,0>)v5->id);
  if ( result )
  {
    v7 = v4->sound_table;
    v8 = 0;
    v9.id = v3->stable_id.id;
    if ( v7 )
    {
      ((void (*)(void))v7->vfptr->Release)();
      v4->sound_table = 0;
    }
    if ( v9.id )
    {
      QualifiedDataID::QualifiedDataID(&v31, v9, 0x22u);
      v4->sound_table = (CSoundTable *)DBObj::Get(v10);
    }
    v11 = v4->physics_script_table;
    v12.id = v3->phstable_id.id;
    if ( v11 )
    {
      ((void (*)(void))v11->vfptr->Release)();
      v4->physics_script_table = 0;
    }
    if ( v12.id )
    {
      QualifiedDataID::QualifiedDataID(&v31, v12, 0x2Cu);
      v4->physics_script_table = (PhysicsScriptTable *)DBObj::Get(v13);
    }
    packed_movement = (void *)HookAppraisalProfile::GetValidLocations((ChatDisplayInfo *)v3);
    if ( packed_movement )
    {
      v4->last_move_was_autonomous = PhysicsDesc::get_autonomous_movement((ChatRoomTracker *)v3);
      if ( set_movement )
      {
        v14 = ChatRoomTracker::GetGlobalTradeRoomID((ChatRoomTracker *)v3);
        CPhysicsObj::unpack_movement(v4, &packed_movement, v14);
      }
    }
    else
    {
      v15 = PhysicsDesc::get_animframe_id((ChatRoomTracker *)v3);
      CPhysicsObj::SetPlacementFrameInternal(v4, v15);
    }
    CPhysicsObj::set_state(v4, v3->state, 1);
    v16 = v3->object_scale;
    v17 = v4->part_array;
    v4->m_scale = v3->object_scale;
    if ( v17 )
    {
      *(float *)&v31.Type = v16;
      *(float *)&v31.ID.id = v16;
      v32 = v16;
      CPartArray::SetScaleInternal(v17, (AC1Legacy::Vector3 *)&v31);
    }
    v18 = v3->friction;
    if ( v18 >= 0.0 && v18 <= 1.0 )
      v4->friction = v3->friction;
    CPhysicsObj::set_elasticity(v4, v3->elasticity);
    v19 = v3->translucency;
    desc = (PhysicsDesc *)LODWORD(v19);
    v20 = v19;
    v4->translucencyOriginal = v19;
    if ( v19 != 0.0 )
    {
      v21 = v19;
      v22 = v4->part_array;
      v4->translucency = v21;
      if ( v22 )
        CPartArray::SetTranslucencyInternal(v22, v20);
    }
    v23 = LODWORD(v3->velocity.y);
    v24 = v3->velocity.z;
    v31.Type = LODWORD(v3->velocity.x);
    v31.ID.id = v23;
    v32 = v24;
    CPhysicsObj::set_velocity(v4, (AC1Legacy::Vector3 *)&v31, 1);
    v25 = LODWORD(v3->omega.y);
    v26 = v3->omega.z;
    v31.Type = LODWORD(v3->omega.x);
    v31.ID.id = v25;
    v27 = (int)&v4->m_omegaVector;
    *(_QWORD *)v27 = v31;
    v32 = v26;
    *(float *)(v27 + 8) = v26;
    v28 = v3->default_script;
    v4->default_script_intensity = v3->default_script_intensity;
    v4->default_script = v28;
    v29 = (int)v4->update_times;
    do
    {
      *(_WORD *)v29 = PhysicsDesc::get_timestamp(v3, (PhysicsTimeStamp)v8++);
      v29 += 2;
    }
    while ( v8 < 9 );
    result = 1;
  }
  return result;
}

//----- (00515160) --------------------------------------------------------  // acclient.c:322404
void __thiscall CPhysicsObj::calc_cross_cells_static(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  CPartArray *v2; // ecx@4
  CPartArray *v3; // ecx@6
  CCylSphere *v4; // edi@7
  CPartArray *v5; // ecx@9
  const unsigned int v6; // eax@10

  v1 = this;
  if ( !(_S247_1 & 1) )
  {
    _S247_1 |= 1u;
    CELLARRAY::CELLARRAY(&cell_array);
    atexit(_E248_13);
  }
  cell_array.num_cells = 0;
  cell_array.added_outside = 0;
  cell_array.do_not_load_cells = 1;
  if ( !(v1->state & 0x10000) && (v2 = v1->part_array) != 0 && CPartArray::GetNumCylsphere(v2) )
  {
    v3 = v1->part_array;
    if ( v3 )
      v4 = CPartArray::GetCylsphere(v3);
    else
      v4 = 0;
    v5 = v1->part_array;
    if ( v5 )
      v6 = CPartArray::GetNumCylsphere(v5);
    else
      v6 = 0;
    CObjCell::find_cell_list(&v1->m_position, v6, v4, &cell_array, 0);
  }
  else
  {
    CPhysicsObj::find_bbox_cell_list(v1, &cell_array);
  }
  CPhysicsObj::remove_shadows_from_cells(v1);
  CPhysicsObj::add_shadows_to_cells(v1, &cell_array);
}

//----- (00515230) --------------------------------------------------------  // acclient.c:322446
void __thiscall CPhysicsObj::calc_cross_cells(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  CPartArray *v2; // ecx@4
  CPartArray *v3; // ecx@6
  CCylSphere *v4; // edi@7
  CPartArray *v5; // ecx@9
  const unsigned int v6; // eax@10
  CPartArray *v7; // ecx@13
  CSphere *v8; // eax@14

  v1 = this;
  if ( !(_S249_15 & 1) )
  {
    _S249_15 |= 1u;
    CELLARRAY::CELLARRAY(&cell_array_0);
    atexit(_E250_21);
  }
  cell_array_0.num_cells = 0;
  cell_array_0.added_outside = 0;
  cell_array_0.do_not_load_cells = 0;
  if ( v1->state & 0x10000 )
  {
    CPhysicsObj::find_bbox_cell_list(v1, &cell_array_0);
  }
  else
  {
    v2 = v1->part_array;
    if ( v2 && CPartArray::GetNumCylsphere(v2) )
    {
      v3 = v1->part_array;
      if ( v3 )
        v4 = CPartArray::GetCylsphere(v3);
      else
        v4 = 0;
      v5 = v1->part_array;
      if ( v5 )
        v6 = CPartArray::GetNumCylsphere(v5);
      else
        v6 = 0;
      CObjCell::find_cell_list(&v1->m_position, v6, v4, &cell_array_0, 0);
    }
    else
    {
      v7 = v1->part_array;
      if ( v7 )
        v8 = CPartArray::GetSortingSphere(v7);
      else
        v8 = &dummy_sphere;
      CObjCell::find_cell_list(&v1->m_position, v8, &cell_array_0, 0);
    }
  }
  CPhysicsObj::remove_shadows_from_cells(v1);
  CPhysicsObj::add_shadows_to_cells(v1, &cell_array_0);
}

//----- (00515330) --------------------------------------------------------  // acclient.c:322503
int __thiscall CPhysicsObj::SetPositionInternal(CPhysicsObj *this, CTransition *transit)
{
  CPhysicsObj *v2; // esi@1
  CObjCell *v3; // eax@1
  unsigned int v4; // ecx@4
  unsigned int v5; // eax@4
  CPartArray *v6; // ecx@5
  CHILDLIST *v7; // eax@7
  unsigned __int16 v8; // bx@8
  CPhysicsObj *v9; // eax@9
  unsigned int v10; // ecx@9
  unsigned int v11; // edx@9
  CPartArray *v12; // eax@10
  int v13; // ecx@13
  int v14; // eax@13
  unsigned int v15; // eax@13
  unsigned int v16; // eax@14
  unsigned int v17; // eax@16
  unsigned int v18; // eax@17
  MovementManager *v19; // ecx@24
  int v20; // eax@27
  unsigned int v21; // eax@27
  unsigned int v22; // eax@28
  int is_water; // [sp+Ch] [bp-Ch]@13
  unsigned int prev_on_walkable; // [sp+10h] [bp-8h]@1
  unsigned int prev_contact; // [sp+14h] [bp-4h]@1

  v2 = this;
  prev_on_walkable = this->transient_state & 2;
  v3 = transit->sphere_path.curr_cell;
  prev_contact = this->transient_state & 1;
  if ( v3 )
  {
    if ( this->cell == v3 )
    {
      v4 = this->state;
      v5 = transit->sphere_path.curr_pos.objcell_id;
      v2->m_position.objcell_id = v5;
      if ( !(BYTE1(v4) & 0x10) )
      {
        v6 = v2->part_array;
        if ( v6 )
          CPartArray::SetCellID(v6, v5);
      }
      v7 = v2->children;
      if ( v7 )
      {
        v8 = 0;
        if ( v7->num_objects )
        {
          do
          {
            v9 = v2->children->objects.data[v8];
            v10 = v9->state;
            v11 = transit->sphere_path.curr_pos.objcell_id;
            v9->m_position.objcell_id = v11;
            if ( !(BYTE1(v10) & 0x10) )
            {
              v12 = v9->part_array;
              if ( v12 )
                CPartArray::SetCellID(v12, v11);
            }
            ++v8;
          }
          while ( v8 < v2->children->num_objects );
        }
      }
    }
    else
    {
      CPhysicsObj::change_cell(this, v3);
    }
    CPhysicsObj::set_frame(v2, &transit->sphere_path.curr_pos.frame);
    v13 = transit->collision_info.contact_plane_is_water;
    v2->contact_plane_cell_id = transit->collision_info.contact_plane_cell_id;
    is_water = v13;
    v14 = (int)&v2->contact_plane;
    *(_DWORD *)v14 = LODWORD(transit->collision_info.contact_plane.N.x);
    *(_DWORD *)(v14 + 4) = LODWORD(transit->collision_info.contact_plane.N.y);
    *(_DWORD *)(v14 + 8) = LODWORD(transit->collision_info.contact_plane.N.z);
    *(_DWORD *)(v14 + 12) = LODWORD(transit->collision_info.contact_plane.d);
    v15 = v2->transient_state;
    if ( transit->collision_info.contact_plane_valid )
      v16 = v15 | 1;
    else
      v16 = v15 & 0xFFFFFFFE;
    v2->transient_state = v16;
    CPhysicsObj::calc_acceleration(v2);
    v17 = v2->transient_state;
    if ( is_water )
      v18 = v17 | 8;
    else
      v18 = v17 & 0xFFFFFFF7;
    v2->transient_state = v18;
    if ( v18 & 1 )
    {
      if ( v2->contact_plane.N.z < (double)PhysicsGlobals::floor_z )
        CPhysicsObj::set_on_walkable(v2, 0);
      else
        CPhysicsObj::set_on_walkable(v2, 1);
    }
    else
    {
      v2->transient_state = v18 & 0xFFFFFFFD;
      if ( v18 & 2 )
      {
        v19 = v2->movement_manager;
        if ( v19 )
          MovementManager::LeaveGround(v19);
      }
      CPhysicsObj::calc_acceleration(v2);
    }
    v20 = (int)&v2->sliding_normal;
    *(_DWORD *)v20 = LODWORD(transit->collision_info.sliding_normal.x);
    *(_DWORD *)(v20 + 4) = LODWORD(transit->collision_info.sliding_normal.y);
    *(_DWORD *)(v20 + 8) = LODWORD(transit->collision_info.sliding_normal.z);
    v21 = v2->transient_state;
    if ( transit->collision_info.sliding_normal_valid )
      v22 = v21 | 4;
    else
      v22 = v21 & 0xFFFFFFFB;
    v2->transient_state = v22;
    CPhysicsObj::handle_all_collisions(v2, &transit->collision_info, prev_contact, prev_on_walkable);
    if ( v2->cell )
    {
      if ( v2->state & 0x10000 )
      {
        CPhysicsObj::calc_cross_cells(v2);
        return 1;
      }
      if ( transit->cell_array.num_cells )
      {
        CPhysicsObj::remove_shadows_from_cells(v2);
        CPhysicsObj::add_shadows_to_cells(v2, &transit->cell_array);
        return 1;
      }
    }
  }
  else
  {
    CPhysicsObj::prepare_to_leave_visibility(this);
    CPhysicsObj::store_position(v2, &transit->sphere_path.curr_pos);
    CObjectMaint::GotoLostCell(CPhysicsObj::obj_maint, v2, v2->m_position.objcell_id);
    v2->transient_state &= 0xFFFFFF7F;
  }
  return 1;
}
// 8EDE5C: using guessed type float PhysicsGlobals::floor_z;

//----- (005155A0) --------------------------------------------------------  // acclient.c:322653
void __thiscall CPhysicsObj::leave_world(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  unsigned int v2; // eax@3
  CPartArray *v3; // ecx@4
  int v4; // ecx@6
  MovementManager *v5; // ecx@7

  v1 = this;
  CPhysicsObj::report_collision_end(this, 1);
  if ( CPhysicsObj::obj_maint )
  {
    CObjectMaint::RemoveFromLostCell(CPhysicsObj::obj_maint, v1);
    CObjectMaint::RemoveObjectToBeDestroyed(CPhysicsObj::obj_maint, v1->id);
  }
  v1->transient_state &= 0xFFFFFF7F;
  CPhysicsObj::remove_shadows_from_cells(v1);
  CPhysicsObj::leave_cell(v1, 0);
  v2 = v1->state;
  v1->m_position.objcell_id = 0;
  if ( !(BYTE1(v2) & 0x10) )
  {
    v3 = v1->part_array;
    if ( v3 )
      CPartArray::SetCellID(v3, 0);
  }
  v1->transient_state &= 0xFFFFFFFE;
  CPhysicsObj::calc_acceleration(v1);
  v4 = v1->transient_state & 2;
  v1->transient_state &= 0xFFFFFFF5;
  if ( v4 )
  {
    v5 = v1->movement_manager;
    if ( v5 )
      MovementManager::LeaveGround(v5);
  }
  CPhysicsObj::calc_acceleration(v1);
  v1->transient_state &= 0xFFFFFE0B;
}

//----- (00515660) --------------------------------------------------------  // acclient.c:322694
signed int __thiscall CPhysicsObj::ForceIntoCell(CPhysicsObj *this, CObjCell *_pNewCell, Position *_pos)
{
  CPhysicsObj *v3; // esi@1
  signed int result; // eax@4

  v3 = this;
  if ( _pNewCell )
  {
    CPhysicsObj::set_frame(this, &_pos->frame);
    if ( v3->cell != _pNewCell )
    {
      CPhysicsObj::change_cell(v3, _pNewCell);
      CPhysicsObj::calc_cross_cells(v3);
    }
    result = 0;
  }
  else
  {
    result = 3;
  }
  return result;
}

//----- (005156B0) --------------------------------------------------------  // acclient.c:322718
void __thiscall CPhysicsObj::UpdateObjectInternal(CPhysicsObj *this, float quantum)
{
  CPhysicsObj *v2; // esi@1
  unsigned int v3; // eax@1
  CPartArray *v4; // ecx@5
  unsigned int v5; // eax@8
  float v6; // edx@10
  float v7; // eax@10
  int v8; // edx@10
  float *v9; // ebp@11
  float v10; // edx@12
  float v11; // eax@12
  int v12; // edx@12
  unsigned int v13; // eax@13
  float degrees; // ST08_4@17
  CTransition *v15; // eax@18
  CTransition *v16; // edi@18
  Vector3 *v17; // eax@19
  float v18; // ecx@19
  float v19; // edx@19
  float v20; // edx@19
  int v21; // eax@19
  float v22; // ecx@19
  float v23; // ecx@20
  float v24; // eax@20
  int v25; // eax@20
  DetectionManager *v26; // ecx@21
  TargetManager *v27; // ecx@23
  MovementManager *v28; // ecx@25
  CPartArray *v29; // ecx@27
  PositionManager *v30; // ecx@29
  ParticleManager *v31; // ecx@31
  ScriptManager *v32; // esi@33
  AC1Legacy::Vector3 diff; // [sp+14h] [bp-60h]@10
  Vector3 result; // [sp+20h] [bp-54h]@19
  Position new_pos; // [sp+2Ch] [bp-48h]@5

  v2 = this;
  v3 = this->transient_state;
  if ( (v3 & 0x80u) != 0 )
  {
    if ( !this->cell )
      return;
    if ( BYTE1(v3) & 1 )
      CPhysicsObj::set_ethereal(this, 0, 0);
    v2->jumped_this_frame = 0;
    new_pos.vfptr = (PackObjVtbl *)&Position::vftable;
    new_pos.objcell_id = 0;
    LODWORD(new_pos.frame.qw) = 1065353216;
    LODWORD(new_pos.frame.qx) = 0;
    LODWORD(new_pos.frame.qy) = 0;
    LODWORD(new_pos.frame.qz) = 0;
    LODWORD(new_pos.frame.m_fOrigin.x) = 0;
    LODWORD(new_pos.frame.m_fOrigin.y) = 0;
    LODWORD(new_pos.frame.m_fOrigin.z) = 0;
    Frame::cache(&new_pos.frame);
    new_pos.objcell_id = v2->m_position.objcell_id;
    CPhysicsObj::UpdatePositionInternal(v2, quantum, &new_pos.frame);
    v4 = v2->part_array;
    if ( v4 && CPartArray::GetNumSphere(v4) )
    {
      v9 = &v2->m_position.frame.m_fOrigin.x;
      if ( (unsigned __int8)AC1Legacy::Vector3::operator==(&new_pos.frame.m_fOrigin, &v2->m_position.frame.m_fOrigin) )
      {
        v10 = v2->m_position.frame.m_fOrigin.y;
        v11 = v2->m_position.frame.m_fOrigin.z;
        LODWORD(new_pos.frame.m_fOrigin.x) = *(_DWORD *)v9;
        new_pos.frame.m_fOrigin.y = v10;
        new_pos.frame.m_fOrigin.z = v11;
        CPhysicsObj::set_frame(v2, &new_pos.frame);
        LODWORD(diff.x) = 0;
        v12 = (int)&v2->cached_velocity;
        *(_DWORD *)v12 = 0;
        LODWORD(diff.y) = 0;
        LODWORD(diff.z) = 0;
        *(_DWORD *)(v12 + 4) = 0;
        *(_DWORD *)(v12 + 8) = 0;
      }
      else
      {
        v13 = v2->state;
        if ( BYTE1(v13) & 1 )
        {
          AC1Legacy::Vector3::operator-(&new_pos.frame.m_fOrigin, &diff, &v2->m_position.frame.m_fOrigin);
          Vector3::Normalize((Vector3 *)&diff.x);
          Frame::set_vector_heading(&new_pos.frame, &diff);
        }
        else if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v13
               && !AC1Legacy::Vector3::is_zero(&v2->m_velocityVector) )
        {
          degrees = AC1Legacy::Vector3::get_heading(&v2->m_velocityVector);
          Frame::set_heading(&new_pos.frame, degrees);
        }
        v15 = CPhysicsObj::transition(v2, &v2->m_position, &new_pos, 0);
        v16 = v15;
        if ( v15 )
        {
          Position::get_offset(&v2->m_position, &diff, &v15->sphere_path.curr_pos);
          v17 = Vector3::operator/((Vector3 *)&diff.x, &result, quantum);
          v18 = v17->y;
          diff.x = v17->x;
          v19 = v17->z;
          diff.y = v18;
          diff.z = v19;
          v20 = v18;
          v21 = (int)&v2->cached_velocity;
          *(_DWORD *)v21 = (_DWORD)diff.x;
          v22 = diff.z;
          *(float *)(v21 + 4) = v20;
          *(float *)(v21 + 8) = v22;
          CPhysicsObj::SetPositionInternal(v2, v16);
        }
        else
        {
          v23 = v2->m_position.frame.m_fOrigin.z;
          v24 = v2->m_position.frame.m_fOrigin.y;
          LODWORD(new_pos.frame.m_fOrigin.x) = *(_DWORD *)v9;
          new_pos.frame.m_fOrigin.z = v23;
          new_pos.frame.m_fOrigin.y = v24;
          CPhysicsObj::set_frame(v2, &new_pos.frame);
          LODWORD(diff.x) = 0;
          v25 = (int)&v2->cached_velocity;
          *(_DWORD *)v25 = 0;
          LODWORD(diff.y) = 0;
          LODWORD(diff.z) = 0;
          *(_DWORD *)(v25 + 4) = 0;
          *(_DWORD *)(v25 + 8) = 0;
        }
      }
    }
    else
    {
      if ( !v2->movement_manager )
      {
        v5 = v2->transient_state;
        if ( v5 & 2 )
          v2->transient_state = v5 & 0xFFFFFF7F;
      }
      v6 = v2->m_position.frame.m_fOrigin.y;
      v7 = v2->m_position.frame.m_fOrigin.z;
      new_pos.frame.m_fOrigin.x = v2->m_position.frame.m_fOrigin.x;
      new_pos.frame.m_fOrigin.y = v6;
      new_pos.frame.m_fOrigin.z = v7;
      CPhysicsObj::set_frame(v2, &new_pos.frame);
      LODWORD(diff.x) = 0;
      v8 = (int)&v2->cached_velocity;
      *(_DWORD *)v8 = 0;
      LODWORD(diff.y) = 0;
      LODWORD(diff.z) = 0;
      *(_DWORD *)(v8 + 4) = 0;
      *(_DWORD *)(v8 + 8) = 0;
    }
    v26 = v2->detection_manager;
    if ( v26 )
      DetectionManager::CheckDetection(v26);
    v27 = v2->target_manager;
    if ( v27 )
      TargetManager::HandleTargetting(v27);
    v28 = v2->movement_manager;
    if ( v28 )
      MovementManager::UseTime(v28);
    v29 = v2->part_array;
    if ( v29 )
      CPartArray::HandleMovement(v29);
    v30 = v2->position_manager;
    if ( v30 )
      PositionManager::UseTime(v30);
  }
  v31 = v2->particle_manager;
  if ( v31 )
    ParticleManager::UpdateParticles(v31);
  v32 = v2->script_manager;
  if ( v32 )
    ScriptManager::UpdateScripts(v32);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (005159E0) --------------------------------------------------------  // acclient.c:322896
void __thiscall CPhysicsObj::add_obj_to_cell(CPhysicsObj *this, CObjCell *new_cell, Frame *new_frame)
{
  CPhysicsObj *v3; // esi@1
  unsigned int v4; // eax@1
  CPartArray *v5; // ecx@2

  v3 = this;
  CPhysicsObj::enter_cell(this, new_cell);
  Frame::operator=((int)&v3->m_position.frame, (int)new_frame);
  v4 = v3->state;
  if ( !(BYTE1(v4) & 0x10) )
  {
    v5 = v3->part_array;
    if ( v5 )
      CPartArray::SetFrame(v5, &v3->m_position.frame);
  }
  CPhysicsObj::UpdateChildrenInternal(v3);
  CPhysicsObj::calc_cross_cells_static(v3);
}

//----- (00515A30) --------------------------------------------------------  // acclient.c:322917
void __thiscall CPhysicsObj::recalc_cross_cells(CPhysicsObj *this)
{
  CPhysicsObj *v1; // edi@1
  unsigned int v2; // eax@4
  unsigned __int16 i; // si@7
  CHILDLIST *v4; // eax@8

  v1 = this;
  if ( this->part_array )
  {
    if ( this->m_position.objcell_id )
    {
      CPhysicsObj::calc_cross_cells(this);
    }
    else
    {
      if ( !this->m_bExaminationObject )
        return;
      v2 = this->state;
      if ( !(BYTE1(v2) & 0x10) )
        return;
      CPhysicsObj::add_particle_shadow_to_cell(this);
    }
    for ( i = 0; ; ++i )
    {
      v4 = v1->children;
      if ( !v4 || i >= v4->num_objects )
        break;
      CPhysicsObj::recalc_cross_cells(v4->objects.data[i]);
    }
  }
}

//----- (00515A90) --------------------------------------------------------  // acclient.c:322951
int __thiscall CPhysicsObj::set_parent(CPhysicsObj *this, CPhysicsObj *obj, unsigned int where)
{
  CPhysicsObj *v3; // edi@1
  CPhysicsObj *v4; // esi@1
  CHILDLIST *v5; // ecx@4
  unsigned int v6; // eax@7
  CPartArray *v7; // ecx@8
  int result; // eax@10

  v3 = obj;
  v4 = this;
  if ( obj && CPhysicsObj::add_child(obj, this, where) )
  {
    CPhysicsObj::unset_parent(v4);
    CPhysicsObj::leave_world(v4);
    v4->parent = v3;
    if ( v3->cell )
    {
      CPhysicsObj::change_cell(v4, v3->cell);
      v5 = v3->children;
      if ( v5 )
      {
        if ( CHILDLIST::FindChildIndex(v5, v4, (unsigned __int16 *)&obj) )
        {
          CPhysicsObj::UpdateChild(
            v3,
            v4,
            v3->children->part_numbers.data[(unsigned __int16)obj],
            &v3->children->frames.data[(unsigned __int16)obj]);
          CPhysicsObj::recalc_cross_cells(v4);
        }
      }
    }
    v6 = v4->parent->state;
    if ( BYTE1(v6) & 0x40 )
    {
      v4->state |= 0x20u;
      v7 = v4->part_array;
      if ( v7 )
        CPartArray::SetNoDrawInternal(v7, 1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00515B50) --------------------------------------------------------  // acclient.c:323002
int __thiscall CPhysicsObj::set_parent(CPhysicsObj *this, CPhysicsObj *obj, unsigned int part_index, Frame *frame)
{
  int result; // eax@1
  CPhysicsObj *v5; // esi@1

  result = 0;
  v5 = this;
  if ( obj )
  {
    if ( CPhysicsObj::add_child(obj, this, part_index, frame) )
    {
      v5->m_bExaminationObject = obj->m_bExaminationObject;
      CPhysicsObj::unset_parent(v5);
      CPhysicsObj::leave_world(v5);
      v5->parent = obj;
      if ( obj->cell )
      {
        CPhysicsObj::change_cell(v5, obj->cell);
        CPhysicsObj::UpdateChild(obj, v5, part_index, frame);
        CPhysicsObj::recalc_cross_cells(v5);
      }
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (00515BD0) --------------------------------------------------------  // acclient.c:323034
signed int __thiscall CPhysicsObj::SetPositionInternal(CPhysicsObj *this, Position *p, SetPositionStruct *sps, CTransition *transit)
{
  CPhysicsObj *v4; // esi@1
  CTransition *v5; // edi@1
  AC1Legacy::Vector3 *v6; // ebx@1
  int v7; // ST0C_4@3
  CObjCell *v8; // ebp@3
  CWeenieObject *v9; // ecx@4

  v4 = this;
  v5 = transit;
  v6 = &transit->sphere_path.local_sphere->center;
  if ( !this->cell )
    CPhysicsObj::prepare_to_enter_world(this);
  v7 = (sps->flags >> 5) & 1;
  transit = 0;
  CPhysicsObj::AdjustPosition(p, v6, (CObjCell **)&transit, v7, 1);
  v8 = (CObjCell *)transit;
  if ( transit )
  {
    v9 = v4->weenie_obj;
    if ( v9
      && (((int (*)(void))v9->vfptr[29].__vecDelDtor)()
       || ((int (*)(void))v4->weenie_obj->vfptr[30].__vecDelDtor)()
       || ((int (*)(void))v4->weenie_obj->vfptr[31].__vecDelDtor)()) )
      return CPhysicsObj::ForceIntoCell(v4, v8, p);
    if ( sps->flags & 0x20 )
      v5->cell_array.do_not_load_cells = 1;
    if ( !CPhysicsObj::CheckPositionInternal(v8, p, v5, sps) )
      return CPhysicsObj::handle_all_collisions(v4, &v5->collision_info, 0, 0) != 0 ? 4 : 2;
    if ( !v5->sphere_path.curr_cell )
      return 3;
    if ( !CPhysicsObj::SetPositionInternal(v4, v5) )
      return 1;
  }
  else
  {
    CPhysicsObj::prepare_to_leave_visibility(v4);
    CPhysicsObj::store_position(v4, p);
    CObjectMaint::GotoLostCell(CPhysicsObj::obj_maint, v4, v4->m_position.objcell_id);
    v4->transient_state &= 0xFFFFFF7F;
  }
  return 0;
}

//----- (00515D10) --------------------------------------------------------  // acclient.c:323080
void __thiscall CPhysicsObj::update_object(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  AC1Legacy::Vector3 *v2; // eax@5
  int v3; // edx@5
  long double v4; // st7@5
  int v5; // eax@9
  long double v6; // st7@9
  unsigned int v7; // edx@10
  unsigned int v8; // ecx@12
  float v9; // ST04_4@14
  unsigned __int8 v11; // c0@14
  unsigned __int8 v12; // c3@14
  float v13; // ST04_4@16
  int v14; // eax@17
  AC1Legacy::Vector3 quantum; // [sp+Ch] [bp-10h]@5

  v1 = this;
  if ( this->parent || !this->cell || this->state & 0x1000000 )
  {
    this->transient_state &= 0xFFFFFF7F;
  }
  else
  {
    if ( CPhysicsObj::player_object )
    {
      v2 = Position::get_offset(&CPhysicsObj::player_object->m_position, &quantum, &this->m_position);
      v3 = (int)&v1->player_vector;
      *(_DWORD *)v3 = LODWORD(v2->x);
      *(_DWORD *)(v3 + 4) = LODWORD(v2->y);
      *(_DWORD *)(v3 + 8) = LODWORD(v2->z);
      v4 = sqrt(v1->player_vector.x * v1->player_vector.x + v1->player_vector.y * v1->player_vector.y + v1->player_vector.z * v1->player_vector.z);
      v1->player_distance = v4;
      if ( v4 > 96.0 && CPhysicsObj::obj_maint->is_active )
        v1->transient_state &= 0xFFFFFF7F;
      else
        CPhysicsObj::set_active(v1, 1);
    }
    v5 = HIDWORD(v1->update_time);
    v6 = COERCE_DOUBLE(Timer::cur_time.Cmd) - v1->update_time;
    PhysicsTimer::curr_time = v1->update_time;
    *(double *)&quantum.x = v6;
    if ( v6 > 0.00019999999 )
    {
      if ( v6 <= 2.0 )
      {
        if ( v6 <= MAX_QUANTUM_97 )
          goto LABEL_21;
        do
        {
          PhysicsTimer::curr_time = PhysicsTimer::curr_time + MAX_QUANTUM_97;
          v9 = MAX_QUANTUM_97;
          CPhysicsObj::UpdateObjectInternal(v1, v9);
          v6 = *(double *)&quantum.x - MAX_QUANTUM_97;
          *(double *)&quantum.x = *(double *)&quantum.x - MAX_QUANTUM_97;
        }
        while ( !(v11 | v12) );
        if ( v6 > MIN_QUANTUM_97 )
        {
LABEL_21:
          PhysicsTimer::curr_time = PhysicsTimer::curr_time + v6;
          v13 = v6;
          CPhysicsObj::UpdateObjectInternal(v1, v13);
        }
        v14 = HIDWORD(PhysicsTimer::curr_time);
        LODWORD(v1->update_time) = LODWORD(PhysicsTimer::curr_time);
        HIDWORD(v1->update_time) = v14;
      }
      else
      {
        v8 = Timer::cur_time.Param;
        LODWORD(v1->update_time) = Timer::cur_time.Cmd;
        HIDWORD(v1->update_time) = v8;
      }
    }
    else
    {
      v7 = Timer::cur_time.Param;
      LODWORD(v1->update_time) = Timer::cur_time.Cmd;
      HIDWORD(v1->update_time) = v7;
    }
  }
}
// 843D58: using guessed type struct CPhysicsObj *CPhysicsObj::player_object;

//----- (00515F00) --------------------------------------------------------  // acclient.c:323166
signed int __thiscall CPhysicsObj::SetScatterPositionInternal(CPhysicsObj *this, SetPositionStruct *sps, CTransition *transit)
{
  CPhysicsObj *v3; // ebx@1
  signed int result; // eax@1
  AC1Legacy::Vector3 *v5; // edi@2
  float v6; // eax@3
  float v7; // ecx@3
  float v8; // edx@3
  float v9; // eax@3
  float v10; // ecx@3
  float v11; // edx@3
  float v12; // eax@3
  float v13; // ecx@3
  float v14; // edx@3
  float v15; // eax@3
  float v16; // ecx@3
  float v17; // edx@3
  float v18; // eax@3
  float v19; // ecx@3
  float v20; // edx@3
  float v21; // ST24_4@3
  double v22; // st7@3
  float v23; // eax@3
  double v24; // st7@3
  bool v25; // cf@4
  unsigned int i; // [sp+10h] [bp-58h]@1
  Position new_p; // [sp+20h] [bp-48h]@2

  v3 = this;
  result = 1;
  i = 0;
  if ( sps->num_tries )
  {
    v5 = Position::get_origin(&new_p);
    do
    {
      new_p.objcell_id = sps->pos.objcell_id;
      v6 = sps->pos.frame.m_fOrigin.y;
      v7 = sps->pos.frame.m_fOrigin.z;
      new_p.frame.m_fOrigin.x = sps->pos.frame.m_fOrigin.x;
      v8 = sps->pos.frame.qw;
      new_p.frame.m_fOrigin.y = v6;
      v9 = sps->pos.frame.qx;
      new_p.frame.m_fOrigin.z = v7;
      v10 = sps->pos.frame.qy;
      new_p.frame.qw = v8;
      v11 = sps->pos.frame.qz;
      new_p.frame.qx = v9;
      v12 = sps->pos.frame.m_fl2gv[0];
      new_p.frame.qy = v10;
      v13 = sps->pos.frame.m_fl2gv[1];
      new_p.frame.qz = v11;
      v14 = sps->pos.frame.m_fl2gv[2];
      new_p.frame.m_fl2gv[0] = v12;
      v15 = sps->pos.frame.m_fl2gv[3];
      new_p.frame.m_fl2gv[1] = v13;
      v16 = sps->pos.frame.m_fl2gv[4];
      new_p.frame.m_fl2gv[2] = v14;
      v17 = sps->pos.frame.m_fl2gv[5];
      new_p.frame.m_fl2gv[3] = v15;
      v18 = sps->pos.frame.m_fl2gv[6];
      new_p.frame.m_fl2gv[4] = v16;
      v19 = sps->pos.frame.m_fl2gv[7];
      new_p.frame.m_fl2gv[5] = v17;
      v20 = sps->pos.frame.m_fl2gv[8];
      new_p.vfptr = (PackObjVtbl *)&Position::vftable;
      new_p.frame.m_fl2gv[6] = v18;
      new_p.frame.m_fl2gv[7] = v19;
      new_p.frame.m_fl2gv[8] = v20;
      v21 = Random::RollDice(-1.0, 1.0) * sps->xrad;
      v22 = Random::RollDice(-1.0, 1.0) * sps->yrad;
      v23 = v5->z;
      v5->x = v21 + v5->x;
      v24 = v22 + v5->y;
      v5->z = v23;
      v5->y = v24;
      result = CPhysicsObj::SetPositionInternal(v3, &new_p, sps, transit);
      if ( !result )
        break;
      v25 = i + 1 < sps->num_tries;
      new_p.vfptr = (PackObjVtbl *)&PackObj::vftable;
      ++i;
    }
    while ( v25 );
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00516040) --------------------------------------------------------  // acclient.c:323257
signed int __thiscall CPhysicsObj::SetPositionInternal(CPhysicsObj *this, SetPositionStruct *sps, CTransition *transit)
{
  unsigned int v3; // eax@1
  CPhysicsObj *v4; // edi@1
  signed int result; // eax@2
  unsigned int v6; // ecx@4
  Position p; // [sp+8h] [bp-48h]@3

  v3 = sps->flags;
  v4 = this;
  if ( BYTE1(v3) & 2 )
  {
    result = CPhysicsObj::SetScatterPositionInternal(this, sps, transit);
  }
  else
  {
    p.objcell_id = sps->pos.objcell_id;
    p.vfptr = (PackObjVtbl *)&Position::vftable;
    Frame::operator=((int)&p.frame, (int)&sps->pos.frame);
    result = CPhysicsObj::SetPositionInternal(v4, &p, sps, transit);
    if ( result )
    {
      v6 = sps->flags;
      if ( BYTE1(v6) & 1 )
        result = CPhysicsObj::SetScatterPositionInternal(v4, sps, transit);
    }
  }
  return result;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (005160C0) --------------------------------------------------------  // acclient.c:323289
signed int __thiscall CPhysicsObj::SetPosition(CPhysicsObj *this, SetPositionStruct *sps)
{
  CPhysicsObj *v2; // esi@1
  CTransition *v3; // eax@1
  CTransition *v4; // edi@1
  CPartArray *v5; // ecx@2
  CPartArray *v6; // ecx@4
  CSphere *v7; // ebx@5
  CPartArray *v8; // ecx@7
  const unsigned int v9; // ST00_4@8
  signed int v10; // esi@11
  signed int result; // eax@11
  const float v12; // [sp+0h] [bp-4h]@4

  v2 = this;
  v3 = CTransition::makeTransition();
  v4 = v3;
  if ( v3 )
  {
    CTransition::init_object(v3, v2, 0);
    v5 = v2->part_array;
    if ( v5 && CPartArray::GetNumSphere(v5) )
    {
      v6 = v2->part_array;
      v12 = v2->m_scale;
      if ( v6 )
        v7 = CPartArray::GetSphere(v6);
      else
        v7 = 0;
      v8 = v2->part_array;
      if ( v8 )
      {
        v9 = CPartArray::GetNumSphere(v8);
        CTransition::init_sphere(v4, v9, v7, v12);
      }
      else
      {
        CTransition::init_sphere(v4, 0, v7, v12);
      }
    }
    else
    {
      CTransition::init_sphere(v4, 1u, &dummy_sphere, 1.0);
    }
    v10 = CPhysicsObj::SetPositionInternal(v2, sps, v4);
    CTransition::cleanupTransition();
    result = v10;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (00516170) --------------------------------------------------------  // acclient.c:323345
int __thiscall CPhysicsObj::enter_world(CPhysicsObj *this, const int slide)
{
  CPhysicsObj *v2; // esi@1
  unsigned int v3; // ecx@2
  const unsigned int v4; // edi@2
  unsigned int v6; // eax@8
  unsigned int v7; // edx@9
  CPartArray *v8; // ecx@11
  MovementManager *v9; // ecx@13
  SetPositionStruct sps; // [sp+4h] [bp-64h]@4

  v2 = this;
  if ( this->parent )
    return 0;
  v3 = Timer::cur_time.Param;
  LODWORD(v2->update_time) = Timer::cur_time.Cmd;
  HIDWORD(v2->update_time) = v3;
  v4 = 1;
  if ( slide )
    v4 = 17;
  SetPositionStruct::SetPositionStruct(&sps);
  SetPositionStruct::SetPosition(&sps, &v2->m_position);
  SetPositionStruct::SetFlags(&sps, v4);
  if ( CPhysicsObj::SetPosition(v2, &sps) )
  {
    WeenieDesc::~WeenieDesc((WeenieDesc *)&sps);
    return 0;
  }
  WeenieDesc::~WeenieDesc((WeenieDesc *)&sps);
  if ( !(v2->state & 1) )
  {
    v6 = v2->transient_state;
    if ( (v6 & 0x80u) == 0 )
    {
      v7 = Timer::cur_time.Param;
      LODWORD(v2->update_time) = Timer::cur_time.Cmd;
      HIDWORD(v2->update_time) = v7;
    }
    v2->transient_state = v6 | 0x80;
  }
  v8 = v2->part_array;
  if ( v8 )
    CPartArray::HandleEnterWorld(v8);
  v9 = v2->movement_manager;
  if ( v9 )
    MovementManager::HandleEnterWorld(v9);
  return 1;
}

//----- (00516250) --------------------------------------------------------  // acclient.c:323395
int __thiscall CPhysicsObj::reenter_visibility(CPhysicsObj *this)
{
  CPhysicsObj *v1; // esi@1
  int result; // eax@2
  SetPositionStruct sps; // [sp+0h] [bp-64h]@1

  v1 = this;
  CPhysicsObj::prepare_to_enter_world(this);
  SetPositionStruct::SetPositionStruct(&sps);
  SetPositionStruct::SetPosition(&sps, &v1->m_position);
  SetPositionStruct::SetFlags(&sps, 0x11u);
  if ( CPhysicsObj::SetPosition(v1, &sps) )
  {
    WeenieDesc::~WeenieDesc((WeenieDesc *)&sps);
    result = 0;
  }
  else
  {
    WeenieDesc::~WeenieDesc((WeenieDesc *)&sps);
    result = 1;
  }
  return result;
}

//----- (005162B0) --------------------------------------------------------  // acclient.c:323420
signed int __thiscall CPhysicsObj::SetPositionSimple(CPhysicsObj *this, Position *p, int sliding)
{
  CPhysicsObj *v3; // edi@1
  const unsigned int v4; // esi@1
  signed int v5; // esi@3
  SetPositionStruct sps; // [sp+8h] [bp-64h]@3

  v3 = this;
  v4 = 4098;
  if ( sliding )
    v4 = 4114;
  SetPositionStruct::SetPositionStruct(&sps);
  SetPositionStruct::SetPosition(&sps, p);
  SetPositionStruct::SetFlags(&sps, v4);
  v5 = CPhysicsObj::SetPosition(v3, &sps);
  WeenieDesc::~WeenieDesc((WeenieDesc *)&sps);
  return v5;
}

//----- (00516310) --------------------------------------------------------  // acclient.c:323440
int __thiscall CPhysicsObj::enter_world(CPhysicsObj *this, Position *p)
{
  CPhysicsObj *v2; // esi@1

  v2 = this;
  CPhysicsObj::store_position(this, p);
  return CPhysicsObj::enter_world(v2, 1);
}

//----- (00516330) --------------------------------------------------------  // acclient.c:323450
int __thiscall CPhysicsObj::MoveOrTeleport(CPhysicsObj *this, Position *p, unsigned __int16 teleport_timestamp, int contact, AC1Legacy::Vector3 *velocity)
{
  CPhysicsObj *v5; // esi@1
  unsigned __int16 v6; // cx@1
  bool v7; // cf@2
  int result; // eax@5
  int v9; // eax@10
  PositionManager *v10; // ecx@11
  SetPositionStruct sps; // [sp+8h] [bp-64h]@14

  v5 = this;
  v6 = this->update_times[4];
  if ( abs(v6 - teleport_timestamp) > 0x7FFF )
    v7 = v6 < teleport_timestamp;
  else
    v7 = teleport_timestamp < v6;
  if ( v7 )
    return 0;
  if ( CPhysicsObj::newer_event(v5, TELEPORT_TS, teleport_timestamp) || !v5->cell )
  {
    CPhysicsObj::teleport_hook(v5, 1);
    SetPositionStruct::SetPositionStruct(&sps);
    SetPositionStruct::SetPosition(&sps, p);
    SetPositionStruct::SetFlags(&sps, 0x1012u);
    CPhysicsObj::SetPosition(v5, &sps);
    WeenieDesc::~WeenieDesc((WeenieDesc *)&sps);
    result = 1;
  }
  else
  {
    if ( !contact )
      return 0;
    if ( v5->player_distance >= 96.0 )
    {
      v10 = v5->position_manager;
      if ( v10 )
        PositionManager::StopInterpolating(v10);
      CPhysicsObj::SetPositionSimple(v5, p, 1);
      result = 1;
    }
    else
    {
      v9 = CPhysicsObj::IsMovingTo(v5);
      CPhysicsObj::InterpolateTo(v5, p, v9);
      result = 1;
    }
  }
  return result;
}

//----- (006FBBD0) --------------------------------------------------------  // acclient.c:784192
int _E77_1()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_4;
  INITIAL_MAX_DATA_RATE_70 = LOWEST_DATA_RATE_4;
  return result;
}

//----- (006FBBE0) --------------------------------------------------------  // acclient.c:784202
void sub_6FBBE0()
{
  flt_843D78 = 1000.0 + 1.0;
}

//----- (006FBC00) --------------------------------------------------------  // acclient.c:784208
void _E99_14()
{
  flt_843D7C = 24.0 * 8.0;
}

//----- (006FBC20) --------------------------------------------------------  // acclient.c:784214
void _E101_9()
{
  flt_843D80 = 24.0 * 0.5;
}

//----- (006FBC40) --------------------------------------------------------  // acclient.c:784220
void sub_6FBC40()
{
  DEFAULT_VIEW_RADIUS_97 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FBC60) --------------------------------------------------------  // acclient.c:784226
void _E105_17()
{
  MIN_QUANTUM_97 = 1.0 / 30.0;
}

//----- (006FBC80) --------------------------------------------------------  // acclient.c:784232
void _E107_12()
{
  MAX_QUANTUM_97 = 1.0 / 5.0;
}

//----- (006FBCA0) --------------------------------------------------------  // acclient.c:784238
int _E109_60()
{
  return atexit(nullsub_1088);
}

//----- (006FBCB0) --------------------------------------------------------  // acclient.c:784244
int _E112_84()
{
  return atexit(_E113_63);
}

//----- (006FBCC0) --------------------------------------------------------  // acclient.c:784250
int _E115_64()
{
  return atexit(_E116_55);
}

//----- (006FBCD0) --------------------------------------------------------  // acclient.c:784256
void _E118_64()
{
  PixelFormatDesc::PixelFormatDesc(&stru_843DA0, PFID_A8R8G8B8);
}

//----- (006FBCE0) --------------------------------------------------------  // acclient.c:784262
int _E120_51()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_13, "Sound.SoundDisabled");
  return atexit(sub_767130);
}

//----- (006FBD00) --------------------------------------------------------  // acclient.c:784269
int _E123_28()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_13, "Sound.SoundVolume");
  return atexit(sub_767160);
}

//----- (006FBD20) --------------------------------------------------------  // acclient.c:784276
int _E126_34()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_13, "Sound.AmbientSoundDisabled");
  return atexit(sub_767190);
}

//----- (006FBD40) --------------------------------------------------------  // acclient.c:784283
int _E129_26()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_13, "Sound.AmbientSoundVolume");
  return atexit(_E130_94);
}

//----- (006FBD60) --------------------------------------------------------  // acclient.c:784290
int _E132_29()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_13, "Sound.InterfaceSoundDisabled");
  return atexit(_E133_88);
}

//----- (006FBD80) --------------------------------------------------------  // acclient.c:784297
int _E135_32()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_13, "Sound.InterfaceSoundVolume");
  return atexit(_E136_71);
}

//----- (006FBDA0) --------------------------------------------------------  // acclient.c:784304
int _E138_24()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_13, "Sound.SoundFeatures");
  return atexit(_E139_71);
}

//----- (006FBDC0) --------------------------------------------------------  // acclient.c:784311
int _E141_24()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_13, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E142_66);
}

//----- (006FBDE0) --------------------------------------------------------  // acclient.c:784318
int _E144_23()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_13, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_843DFC, "Mono");
  return atexit(_E145_68);
}

//----- (006FBE10) --------------------------------------------------------  // acclient.c:784326
void _E147_20()
{
  VOL_MIN_DIST_SQ_10 = 5.0 * 5.0;
}

//----- (006FBE30) --------------------------------------------------------  // acclient.c:784332
void _E149_3()
{
  INV_LOG_OF_2_10 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (006FBE50) --------------------------------------------------------  // acclient.c:784338
int _E151_23()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_23, "Render.TextureFiltering");
  return atexit(_E152_27);
}

//----- (006FBE70) --------------------------------------------------------  // acclient.c:784345
int _E154_24()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_23, "Render.LandscapeDetailTextures");
  return atexit(_E155_24);
}

//----- (006FBE90) --------------------------------------------------------  // acclient.c:784352
int _E157_22()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_23, "Render.BuildingDetailTextures");
  return atexit(_E158_26);
}

//----- (006FBEB0) --------------------------------------------------------  // acclient.c:784359
int _E160_25()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_23, "Render.FieldOfView");
  return atexit(_E161_24);
}

//----- (006FBED0) --------------------------------------------------------  // acclient.c:784366
int _E163_19()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_23, "Render.LandscapeTextureDetail");
  return atexit(_E164_26);
}

//----- (006FBEF0) --------------------------------------------------------  // acclient.c:784373
int _E166_21()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_23, "Render.EnvironmentTextureDetail");
  return atexit(_E167_22);
}

//----- (006FBF10) --------------------------------------------------------  // acclient.c:784380
int _E169_19()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_23, "Render.SceneryDrawDistance");
  return atexit(_E170_22);
}

//----- (006FBF30) --------------------------------------------------------  // acclient.c:784387
int _E172_17()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_23, "Render.LandscapeDrawDistance");
  return atexit(_E173_18);
}

//----- (006FBF50) --------------------------------------------------------  // acclient.c:784394
int _E175_15()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_23, "Render.ScreenBrightness");
  return atexit(_E176_20);
}

//----- (006FBF70) --------------------------------------------------------  // acclient.c:784401
int _E178_15()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_23, "Render.AspectRatio");
  return atexit(_E179_19);
}

//----- (006FBF90) --------------------------------------------------------  // acclient.c:784408
int _E181_15()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_23, "Render.DisplayAdapter");
  return atexit(_E182_19);
}

//----- (006FBFB0) --------------------------------------------------------  // acclient.c:784415
int _E184_13()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_23, "Render.MaxHardwareClass");
  return atexit(_E185_16);
}

//----- (006FBFD0) --------------------------------------------------------  // acclient.c:784422
int _E187_12()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_23, "Render.AutomaticDegrades");
  return atexit(_E188_17);
}

//----- (006FBFF0) --------------------------------------------------------  // acclient.c:784429
int _E190_13()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_23, "Render.GraphicsPerformance");
  return atexit(_E191_16);
}

//----- (006FC010) --------------------------------------------------------  // acclient.c:784436
int _E193_12()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_23, "Render.DegradeDistance");
  return atexit(_E194_23);
}

//----- (006FC030) --------------------------------------------------------  // acclient.c:784443
int _E196_16()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_23, "Render.MultiPassAlpha");
  return atexit(_E197_14);
}

//----- (006FC050) --------------------------------------------------------  // acclient.c:784450
int _E199_12()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_23, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_843E54, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_843E58, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_843E5C, "Anisotropic");
  return atexit(_E200_18);
}

//----- (006FC0A0) --------------------------------------------------------  // acclient.c:784460
int _E202_13()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_23, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_843E64, "Low");
  PStringBase<char>::PStringBase<char>(&stru_843E68, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_843E6C, "High");
  PStringBase<char>::PStringBase<char>(&stru_843E70, "VeryHigh");
  return atexit(_E203_17);
}

//----- (006FC100) --------------------------------------------------------  // acclient.c:784471
int _E205_13()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_23, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_843E78, "Low");
  PStringBase<char>::PStringBase<char>(&stru_843E7C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_843E80, "High");
  PStringBase<char>::PStringBase<char>(&stru_843E84, "VeryHigh");
  return atexit(_E206_20);
}

//----- (006FC160) --------------------------------------------------------  // acclient.c:784482
int _E208_17()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_23, "Low");
  PStringBase<char>::PStringBase<char>(&stru_843E8C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_843E90, "High");
  return atexit(_E209_15);
}

//----- (006FC1A0) --------------------------------------------------------  // acclient.c:784491
int _E211_13()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_23, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_843E98, "Low");
  PStringBase<char>::PStringBase<char>(&stru_843E9C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_843EA0, "High");
  PStringBase<char>::PStringBase<char>(&stru_843EA4, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_843EA8, "Extreme");
  return atexit(_E212_18);
}

//----- (006FC210) --------------------------------------------------------  // acclient.c:784503
int _E214_15()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_23, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_843EB0, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_843EB4, "Wide");
  return atexit(_E215_14);
}

//----- (006FC250) --------------------------------------------------------  // acclient.c:784512
int _E217_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_47, "None");
  return atexit(_E218_15);
}

//----- (006FC270) --------------------------------------------------------  // acclient.c:784519
int _E220_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_47, "Speed");
  return atexit(_E221_15);
}

//----- (006FC290) --------------------------------------------------------  // acclient.c:784526
int _E223_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_47, "Noise");
  return atexit(_E224_15);
}

//----- (006FC2B0) --------------------------------------------------------  // acclient.c:784533
int _E226_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_47, "Sine");
  return atexit(_E227_15);
}

//----- (006FC2D0) --------------------------------------------------------  // acclient.c:784540
int _E229_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_47, "Square");
  return atexit(_E230_15);
}

//----- (006FC2F0) --------------------------------------------------------  // acclient.c:784547
int _E232_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_47, "Bounce");
  return atexit(_E233_14);
}

//----- (006FC310) --------------------------------------------------------  // acclient.c:784554
int _E235_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_47, "Perlin");
  return atexit(_E236_14);
}

//----- (006FC330) --------------------------------------------------------  // acclient.c:784561
int _E238_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_47, "Fractal");
  return atexit(_E239_14);
}

//----- (006FC350) --------------------------------------------------------  // acclient.c:784568
int _E241_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_47, "FrameLoop");
  return atexit(_E242_14);
}

//----- (006FC370) --------------------------------------------------------  // acclient.c:784575
int _E244_11()
{
  LODWORD(dummy_sphere.center.x) = 0;
  LODWORD(dummy_sphere.center.y) = 0;
  dummy_sphere.center.z = DUMMY_SPHERE_RADIUS;
  dummy_sphere.radius = DUMMY_SPHERE_RADIUS;
  return atexit(_E245_13);
}

//----- (006FC3C0) --------------------------------------------------------  // acclient.c:784585
int sub_6FC3C0()
{
  return atexit(nullsub_1087);
}

//----- (00767130) --------------------------------------------------------  // acclient.c:893870
void __cdecl sub_767130()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767160) --------------------------------------------------------  // acclient.c:893883
void __cdecl sub_767160()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767190) --------------------------------------------------------  // acclient.c:893896
void __cdecl sub_767190()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007671C0) --------------------------------------------------------  // acclient.c:893909
void __cdecl _E130_94()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007671F0) --------------------------------------------------------  // acclient.c:893922
void __cdecl _E133_88()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767220) --------------------------------------------------------  // acclient.c:893935
void __cdecl _E136_71()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767250) --------------------------------------------------------  // acclient.c:893948
void __cdecl _E139_71()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767280) --------------------------------------------------------  // acclient.c:893961
void __cdecl _E142_66()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007672B0) --------------------------------------------------------  // acclient.c:893974
void __cdecl _E145_68()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_10;
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

//----- (007672F0) --------------------------------------------------------  // acclient.c:893999
void __cdecl _E152_27()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767320) --------------------------------------------------------  // acclient.c:894012
void __cdecl _E155_24()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767350) --------------------------------------------------------  // acclient.c:894025
void __cdecl _E158_26()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767380) --------------------------------------------------------  // acclient.c:894038
void __cdecl _E161_24()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007673B0) --------------------------------------------------------  // acclient.c:894051
void __cdecl _E164_26()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007673E0) --------------------------------------------------------  // acclient.c:894064
void __cdecl _E167_22()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767410) --------------------------------------------------------  // acclient.c:894077
void __cdecl _E170_22()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767440) --------------------------------------------------------  // acclient.c:894090
void __cdecl _E173_18()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767470) --------------------------------------------------------  // acclient.c:894103
void __cdecl _E176_20()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007674A0) --------------------------------------------------------  // acclient.c:894116
void __cdecl _E179_19()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007674D0) --------------------------------------------------------  // acclient.c:894129
void __cdecl _E182_19()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767500) --------------------------------------------------------  // acclient.c:894142
void __cdecl _E185_16()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767530) --------------------------------------------------------  // acclient.c:894155
void __cdecl _E188_17()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767560) --------------------------------------------------------  // acclient.c:894168
void __cdecl _E191_16()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767590) --------------------------------------------------------  // acclient.c:894181
void __cdecl _E194_23()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007675C0) --------------------------------------------------------  // acclient.c:894194
void __cdecl _E197_14()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007675F0) --------------------------------------------------------  // acclient.c:894207
void __cdecl _E200_18()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_23;
  v1 = 4;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
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

//----- (00767630) --------------------------------------------------------  // acclient.c:894232
void __cdecl _E203_17()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_23;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
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

//----- (00767670) --------------------------------------------------------  // acclient.c:894257
void __cdecl _E206_20()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_23;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
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

//----- (007676B0) --------------------------------------------------------  // acclient.c:894282
void __cdecl _E209_15()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_23;
  v1 = 3;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
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

//----- (007676F0) --------------------------------------------------------  // acclient.c:894307
void __cdecl _E212_18()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_23;
  v1 = 6;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
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

//----- (00767730) --------------------------------------------------------  // acclient.c:894332
void __cdecl _E215_14()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_47;
  v1 = 3;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00767770) --------------------------------------------------------  // acclient.c:894357
void __cdecl _E218_15()
{
  char *v0; // esi@1

  v0 = &waveform_None_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007677A0) --------------------------------------------------------  // acclient.c:894370
void __cdecl _E221_15()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007677D0) --------------------------------------------------------  // acclient.c:894383
void __cdecl _E224_15()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767800) --------------------------------------------------------  // acclient.c:894396
void __cdecl _E227_15()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767830) --------------------------------------------------------  // acclient.c:894409
void __cdecl _E230_15()
{
  char *v0; // esi@1

  v0 = &waveform_Square_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767860) --------------------------------------------------------  // acclient.c:894422
void __cdecl _E233_14()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767890) --------------------------------------------------------  // acclient.c:894435
void __cdecl _E236_14()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007678C0) --------------------------------------------------------  // acclient.c:894448
void __cdecl _E239_14()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007678F0) --------------------------------------------------------  // acclient.c:894461
void __cdecl _E242_14()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767920) --------------------------------------------------------  // acclient.c:894474
void __cdecl _E248_13()
{
  if ( cell_array.cells.data )
    operator delete[](&cell_array.cells.data[-1].cell);
  cell_array.cells.data = 0;
}

//----- (00767940) --------------------------------------------------------  // acclient.c:894482
void __cdecl _E250_21()
{
  if ( cell_array_0.cells.data )
    operator delete[](&cell_array_0.cells.data[-1].cell);
  cell_array_0.cells.data = 0;
}

