/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CObjectInfo
   Object     : PORTAL\cphysics\CObjectInfo.obj
   Functions  : 14
   Addresses  : 0050CEB0 - 006FB580 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0050CEB0) --------------------------------------------------------  // acclient.c:314069
int __thiscall OBJECTINFO::missile_ignore(OBJECTINFO *this, CPhysicsObj *collideobject)
{
  unsigned int v2; // edx@1
  int result; // eax@2
  unsigned int v4; // ecx@4
  CWeenieObject *v5; // eax@5

  v2 = collideobject->state;
  if ( v2 & 0x40 )
  {
    result = 1;
  }
  else
  {
    result = 0;
    if ( this->object->state & 0x40 )
    {
      v4 = this->targetID;
      if ( collideobject->id != v4 )
      {
        if ( (v5 = collideobject->weenie_obj, v2 & 4) && v5
          || v4 && v5 && ((int (__thiscall *)(CWeenieObject *))v5->vfptr[11].__vecDelDtor)(v5) )
          result = 1;
      }
    }
  }
  return result;
}

//----- (0050CF10) --------------------------------------------------------  // acclient.c:314099
BOOL __thiscall OBJECTINFO::is_valid_walkable(OBJECTINFO *this, AC1Legacy::Vector3 *normal)
{
  CPhysicsObj *v2; // ecx@1

  v2 = this->object;
  return CPhysicsObj::is_valid_walkable(normal);
}

//----- (0050CF20) --------------------------------------------------------  // acclient.c:314108
double __thiscall OBJECTINFO::get_walkable_z(OBJECTINFO *this)
{
  CPhysicsObj *v1; // ecx@1

  v1 = this->object;
  return CPhysicsObj::get_walkable_z();
}

//----- (0050CF30) --------------------------------------------------------  // acclient.c:314117
void __thiscall OBJECTINFO::init(OBJECTINFO *this, CPhysicsObj *_object, int object_state)
{
  OBJECTINFO *v3; // esi@1
  CPhysicsObj *v4; // eax@1
  CWeenieObject *v5; // edi@1

  v3 = this;
  this->object = _object;
  this->state = object_state;
  this->scale = _object->m_scale;
  this->step_up_height = CPhysicsObj::GetStepUpHeight(_object);
  v3->step_down_height = CPhysicsObj::GetStepDownHeight(v3->object);
  v4 = v3->object;
  v3->ethereal = v3->object->state & 4;
  v3->step_down = ~(unsigned __int8)(v4->state >> 6) & 1;
  v5 = v4->weenie_obj;
  if ( v5 )
  {
    if ( ((int (__thiscall *)(CWeenieObject *))v5->vfptr[10].__vecDelDtor)(v5) )
      v3->state |= 0x80u;
    if ( ((int (__thiscall *)(CWeenieObject *))v5->vfptr[4].__vecDelDtor)(v5) )
      v3->state |= 0x100u;
    if ( ((int (__thiscall *)(CWeenieObject *))v5->vfptr[8].__vecDelDtor)(v5) )
      v3->state |= 0x800u;
    if ( ((int (__thiscall *)(CWeenieObject *))v5->vfptr[9].__vecDelDtor)(v5) )
      v3->state |= 0x1000u;
  }
}

//----- (0050CFE0) --------------------------------------------------------  // acclient.c:314147
void __thiscall OBJECTINFO::kill_velocity(OBJECTINFO *this)
{
  CPhysicsObj *v1; // ecx@1
  AC1Legacy::Vector3 new_velocity; // [sp+0h] [bp-Ch]@1

  v1 = this->object;
  LODWORD(new_velocity.x) = 0;
  LODWORD(new_velocity.y) = 0;
  LODWORD(new_velocity.z) = 0;
  CPhysicsObj::set_velocity(v1, &new_velocity, 0);
}

//----- (0050D010) --------------------------------------------------------  // acclient.c:314160
signed int __thiscall OBJECTINFO::validate_walkable(OBJECTINFO *this, CSphere *check_pos, Plane *contact_plane, const int is_water, const float water_depth, SPHEREPATH *path, COLLISIONINFO *collisions, unsigned int land_cell_id)
{
  OBJECTINFO *v8; // ebp@1
  CSphere *v9; // edx@2
  double v10; // st7@2
  AC1Legacy::Vector3 *v11; // eax@3
  double v12; // st7@3
  double v13; // st6@3
  Position *v14; // eax@5
  signed int result; // eax@7
  double v16; // st6@8
  double v17; // st7@9
  SPHEREPATH *v18; // edi@10
  CPhysicsObj *v19; // ecx@12
  BOOL v20; // eax@12
  double v21; // st7@16
  CPhysicsObj *v22; // ecx@26
  BOOL v23; // eax@26
  TransitionState ts; // [sp+Ch] [bp-1Ch]@1
  AC1Legacy::Vector3 offset; // [sp+10h] [bp-18h]@3
  float v26; // [sp+24h] [bp-4h]@8
  float check_posa; // [sp+2Ch] [bp+4h]@2
  float patha; // [sp+3Ch] [bp+14h]@12

  v8 = this;
  ts = 1;
  if ( this->state & 4 )
  {
    v9 = check_pos;
    v10 = contact_plane->N.x * check_pos->center.x
        + contact_plane->N.y * check_pos->center.y
        + check_pos->center.z * contact_plane->N.z
        + contact_plane->d
        - check_pos->radius;
    check_posa = v10;
    if ( v10 > -0.00019999999
      || ((v11 = path->global_curr_center,
           offset.x = v9->center.x - v11->x,
           offset.y = v9->center.y - v11->y,
           v12 = v9->center.z - v11->z,
           v13 = check_posa / (v12 * contact_plane->N.z + offset.x * contact_plane->N.x + offset.y * contact_plane->N.y),
           v13 <= 0.0)
       || v13 > 1.0)
      && (v14 = path->begin_pos) != 0
      && (v14->objcell_id & 0xFFFF) >= 0x100 )
    {
      result = 1;
    }
    else
    {
      v16 = -v13;
      v26 = v12 * v16;
      offset.z = v26;
      offset.x = offset.x * v16;
      offset.y = offset.y * v16;
      SPHEREPATH::add_offset_to_check_pos(path, &offset);
      COLLISIONINFO::set_collision_normal(collisions, &contact_plane->N);
      collisions->collided_with_environment = 1;
      result = 3;
    }
  }
  else
  {
    v17 = check_pos->center.y * contact_plane->N.y
        + (check_pos->center.z - check_pos->radius) * contact_plane->N.z
        + check_pos->center.x * contact_plane->N.x
        + contact_plane->d
        + water_depth;
    if ( v17 >= -0.00019999999 )
    {
      if ( v17 > 0.00019999999 )
        return 1;
      v22 = this->object;
      v23 = CPhysicsObj::is_valid_walkable(&contact_plane->N);
      if ( path->step_down || !(v8->state & 2) || v23 )
      {
        COLLISIONINFO::set_contact_plane(collisions, contact_plane, is_water);
        collisions->contact_plane_cell_id = land_cell_id;
      }
      if ( !(v8->state & 1) && !path->step_down )
      {
        COLLISIONINFO::set_collision_normal(collisions, &contact_plane->N);
        collisions->collided_with_environment = 1;
      }
      ts = 1;
    }
    else
    {
      v18 = path;
      if ( path->check_walkable )
        return 2;
      v19 = this->object;
      patha = v17 / contact_plane->N.z;
      v20 = CPhysicsObj::is_valid_walkable(&contact_plane->N);
      if ( v18->step_down || !(v8->state & 2) || v20 )
      {
        COLLISIONINFO::set_contact_plane(collisions, contact_plane, is_water);
        collisions->contact_plane_cell_id = land_cell_id;
        if ( v18->step_down )
        {
          v21 = (1.0 - -1.0 / (v18->step_down_amt * v18->walk_interp) * patha) * v18->walk_interp;
          if ( v21 >= v18->walk_interp || v21 < -0.1 )
            return 2;
          v18->walk_interp = v21;
        }
        offset.z = -patha;
        LODWORD(offset.x) = 0;
        LODWORD(offset.y) = 0;
        SPHEREPATH::add_offset_to_check_pos(v18, &offset);
        ts = 3;
      }
      if ( !(v8->state & 1) && !v18->step_down )
      {
        COLLISIONINFO::set_collision_normal(collisions, &contact_plane->N);
        result = ts;
        collisions->collided_with_environment = 1;
        return result;
      }
    }
    result = ts;
  }
  return result;
}

//----- (006FB4B0) --------------------------------------------------------  // acclient.c:783827
int sub_6FB4B0()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_3;
  INITIAL_MAX_DATA_RATE_68 = LOWEST_DATA_RATE_3;
  return result;
}

//----- (006FB4C0) --------------------------------------------------------  // acclient.c:783837
void sub_6FB4C0()
{
  flt_843BC0 = 1000.0 + 1.0;
}

//----- (006FB4E0) --------------------------------------------------------  // acclient.c:783843
void _E99_12()
{
  flt_843BC4 = 24.0 * 8.0;
}

//----- (006FB500) --------------------------------------------------------  // acclient.c:783849
void _E101_8()
{
  flt_843BC8 = 24.0 * 0.5;
}

//----- (006FB520) --------------------------------------------------------  // acclient.c:783855
void sub_6FB520()
{
  DEFAULT_VIEW_RADIUS_95 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FB540) --------------------------------------------------------  // acclient.c:783861
void _E105_15()
{
  MIN_QUANTUM_95 = 1.0 / 30.0;
}

//----- (006FB560) --------------------------------------------------------  // acclient.c:783867
void _E107_11()
{
  MAX_QUANTUM_95 = 1.0 / 5.0;
}

//----- (006FB580) --------------------------------------------------------  // acclient.c:783873
int sub_6FB580()
{
  return atexit(nullsub_1081);
}

