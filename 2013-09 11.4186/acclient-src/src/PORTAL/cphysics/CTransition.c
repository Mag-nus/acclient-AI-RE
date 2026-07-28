/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CTransition
   Object     : PORTAL\cphysics\CTransition.obj
   Functions  : 51
   Addresses  : 00509C50 - 00766A10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00509C50) --------------------------------------------------------  // acclient.c:311526
void __thiscall Plane::snap_to_plane(Plane *this, AC1Legacy::Vector3 *offset)
{
  if ( fabs(this->N.z) > 0.00019999999 )
  {
    LODWORD(offset->z) = 0;
    offset->z = -(offset->y * this->N.y + offset->x * this->N.x + this->N.z * 0.0 + this->d) * (1.0 / this->N.z)
              - 1.0 / this->N.z * -this->d;
  }
}

//----- (00509CB0) --------------------------------------------------------  // acclient.c:311537
int __thiscall Plane::operator=(int this, int a2)
{
  int result; // eax@1

  result = this;
  *(_DWORD *)this = *(_DWORD *)a2;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  return result;
}

//----- (00509CE0) --------------------------------------------------------  // acclient.c:311550
void __thiscall SPHEREPATH::set_walkable_check_pos(SPHEREPATH *this, CSphere *sphere)
{
  this->walkable_check_pos = *sphere;
}

//----- (00509D10) --------------------------------------------------------  // acclient.c:311556
void __thiscall SPHEREPATH::add_offset_to_check_pos(SPHEREPATH *this, AC1Legacy::Vector3 *offset)
{
  this->cell_array_valid = 0;
  this->check_pos.frame.m_fOrigin.x = this->check_pos.frame.m_fOrigin.x + offset->x;
  this->check_pos.frame.m_fOrigin.y = offset->y + this->check_pos.frame.m_fOrigin.y;
  this->check_pos.frame.m_fOrigin.z = offset->z + this->check_pos.frame.m_fOrigin.z;
  SPHEREPATH::cache_global_sphere(this, offset);
}

//----- (00509D60) --------------------------------------------------------  // acclient.c:311566
void __thiscall COLLISIONINFO::init(COLLISIONINFO *this)
{
  this->last_known_contact_plane_valid = 0;
  this->contact_plane_valid = 0;
  this->sliding_normal_valid = 0;
  this->collision_normal_valid = 0;
  this->num_collide_object = 0;
  this->last_collided_object = 0;
  this->collided_with_environment = 0;
  this->contact_plane_cell_id = 0;
  this->frames_stationary_fall = 0;
}

//----- (00509D80) --------------------------------------------------------  // acclient.c:311580
void __thiscall COLLISIONINFO::set_contact_plane(COLLISIONINFO *this, Plane *plane, int is_water)
{
  this->contact_plane_valid = 1;
  this->contact_plane = *plane;
  this->contact_plane_is_water = is_water;
}

//----- (00509DC0) --------------------------------------------------------  // acclient.c:311588
void __cdecl CTransition::cleanupTransition()
{
  --CTransition::transition_level;
}
// 841C5C: using guessed type int CTransition::transition_level;

//----- (00509DD0) --------------------------------------------------------  // acclient.c:311595
void __thiscall CTransition::init(CTransition *this)
{
  CTransition *v1; // esi@1

  v1 = this;
  this->object_info.object = 0;
  this->object_info.state = 0;
  this->object_info.targetID = 0;
  SPHEREPATH::init(&this->sphere_path);
  v1->collision_info.last_known_contact_plane_valid = 0;
  v1->collision_info.contact_plane_valid = 0;
  v1->collision_info.sliding_normal_valid = 0;
  v1->collision_info.collision_normal_valid = 0;
  v1->collision_info.num_collide_object = 0;
  v1->collision_info.last_collided_object = 0;
  v1->collision_info.collided_with_environment = 0;
  v1->collision_info.contact_plane_cell_id = 0;
  v1->collision_info.frames_stationary_fall = 0;
  v1->cell_array.num_cells = 0;
  v1->cell_array.added_outside = 0;
  v1->cell_array.do_not_load_cells = 0;
}

//----- (00509E50) --------------------------------------------------------  // acclient.c:311619
void __thiscall CTransition::init_sphere(CTransition *this, const unsigned int num_sphere, CSphere *sphere, const float scale)
{
  SPHEREPATH::init_sphere(&this->sphere_path, num_sphere, sphere, scale);
}

//----- (00509E60) --------------------------------------------------------  // acclient.c:311625
void __thiscall CTransition::init_path(CTransition *this, CObjCell *begin_cell, Position *begin_pos, Position *end_pos)
{
  SPHEREPATH::init_path(&this->sphere_path, begin_cell, begin_pos, end_pos);
}

//----- (00509E70) --------------------------------------------------------  // acclient.c:311631
int __thiscall CTransition::insert_into_cell(CTransition *this, CObjCell *cell, int num_insertion_attempts)
{
  CTransition *v3; // esi@1
  int v4; // ebx@2
  int result; // eax@2

  v3 = this;
  if ( cell )
  {
    v4 = 0;
    result = 1;
    if ( num_insertion_attempts > 0 )
    {
      while ( 2 )
      {
        result = ((int (__thiscall *)(_DWORD, _DWORD))cell->vfptr[5].AddRef)(cell, v3);
        switch ( result )
        {
          case 4:
            v3->collision_info.contact_plane_valid = 0;
            v3->collision_info.contact_plane_is_water = 0;
            goto $L93946;
          default:
$L93946:
            ++v4;
            if ( v4 >= num_insertion_attempts )
              return result;
            continue;
          case 1:
          case 2:
            return result;
        }
      }
    }
  }
  else
  {
    result = 2;
  }
  return result;
}

//----- (00509EE0) --------------------------------------------------------  // acclient.c:311674
void __thiscall CTransition::build_cell_array(CTransition *this, CObjCell **new_cell_p)
{
  this->sphere_path.cell_array_valid = 1;
  this->sphere_path.hits_interior_cell = 0;
  CObjCell::find_cell_list(&this->cell_array, new_cell_p, &this->sphere_path);
}

//----- (00509F10) --------------------------------------------------------  // acclient.c:311682
BOOL __thiscall AC1Legacy::Vector3::operator==(AC1Legacy::Vector3 *this, AC1Legacy::Vector3 *v)
{
  return fabs(this->x - v->x) <= 0.00019999999
      && fabs(this->y - v->y) <= 0.00019999999
      && fabs(this->z - v->z) <= 0.00019999999;
}

//----- (00509F60) --------------------------------------------------------  // acclient.c:311690
AC1Legacy::Vector3 *__thiscall Position::get_offset(Position *this, AC1Legacy::Vector3 *result, Position *p)
{
  Position *v3; // esi@1
  double v4; // st7@1
  AC1Legacy::Vector3 *v5; // eax@1
  double v6; // st6@1
  double v7; // st5@1
  double v8; // st7@1
  AC1Legacy::Vector3 v9; // [sp+8h] [bp-18h]@1
  float v10; // [sp+18h] [bp-8h]@1
  float v11; // [sp+1Ch] [bp-4h]@1

  v3 = this;
  LandDefs::get_block_offset(&v9, this->objcell_id, p->objcell_id);
  v4 = v9.x + p->frame.m_fOrigin.x;
  v5 = result;
  v10 = v9.y + p->frame.m_fOrigin.y;
  v11 = v9.z + p->frame.m_fOrigin.z;
  v6 = v10 - v3->frame.m_fOrigin.y;
  v7 = v4 - v3->frame.m_fOrigin.x;
  v8 = v11 - v3->frame.m_fOrigin.z;
  result->x = v7;
  result->y = v6;
  result->z = v8;
  return v5;
}

//----- (00509FD0) --------------------------------------------------------  // acclient.c:311718
AC1Legacy::Vector3 *__thiscall SPHEREPATH::get_curr_pos_check_pos_block_offset(SPHEREPATH *this, AC1Legacy::Vector3 *result)
{
  LandDefs::get_block_offset(result, this->curr_pos.objcell_id, this->check_pos.objcell_id);
  return result;
}

//----- (0050A000) --------------------------------------------------------  // acclient.c:311725
void __thiscall COLLISIONINFO::set_collision_normal(COLLISIONINFO *this, AC1Legacy::Vector3 *normal)
{
  char *v2; // esi@1
  AC1Legacy::Vector3 *v3; // ecx@1

  this->collision_normal_valid = 1;
  v2 = (char *)&this->collision_normal;
  v3 = &this->collision_normal;
  COERCE_AC1LEGACY__VECTOR3(v3->x) = *normal;
  if ( AC1Legacy::Vector3::normalize_check_small(v3) )
  {
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 2) = 0;
  }
}

//----- (0050A060) --------------------------------------------------------  // acclient.c:311743
void __thiscall COLLISIONINFO::set_sliding_normal(COLLISIONINFO *this, AC1Legacy::Vector3 *normal)
{
  COLLISIONINFO *v2; // esi@1
  char *v3; // edi@1

  v2 = this;
  this->sliding_normal_valid = 1;
  v3 = (char *)&this->sliding_normal;
  this->sliding_normal.x = normal->x;
  this->sliding_normal.y = normal->y;
  LODWORD(this->sliding_normal.z) = 0;
  if ( AC1Legacy::Vector3::normalize_check_small(&this->sliding_normal) )
  {
    *(_DWORD *)v3 = 0;
    LODWORD(v2->sliding_normal.y) = 0;
    LODWORD(v2->sliding_normal.z) = 0;
  }
}

//----- (0050A0B0) --------------------------------------------------------  // acclient.c:311763
void __thiscall CTransition::calc_num_steps(CTransition *this, AC1Legacy::Vector3 *offset, AC1Legacy::Vector3 *offset_per_step, unsigned int *num_steps)
{
  CTransition *v4; // edi@1
  Position *v5; // ecx@1
  AC1Legacy::Vector3 *v6; // eax@2
  double v7; // st7@2
  long double v8; // st3@2
  double v9; // st7@4
  double v10; // st5@4
  double v11; // st6@4
  float v12; // ST18_4@4
  float v13; // ST10_4@4
  float v14; // ST14_4@4
  double v15; // st6@6
  double v16; // st7@12
  double v17; // st5@12
  double v18; // st6@12
  float v19; // ST18_4@12
  float v20; // ST10_4@12
  float v21; // ST14_4@12
  AC1Legacy::Vector3 result; // [sp+1Ch] [bp-Ch]@2

  v4 = this;
  v5 = this->sphere_path.begin_pos;
  if ( v5 )
  {
    v6 = Position::get_offset(v5, &result, v4->sphere_path.end_pos);
    offset->x = v6->x;
    offset->y = v6->y;
    offset->z = v6->z;
    v7 = v4->sphere_path.local_sphere->radius;
    v8 = sqrt(offset->x * offset->x + offset->y * offset->y + offset->z * offset->z);
    if ( v4->object_info.state & 4 )
    {
      if ( v8 <= 0.00019999999 )
      {
        LODWORD(offset_per_step->x) = 0;
        LODWORD(offset_per_step->y) = 0;
        LODWORD(offset_per_step->z) = 0;
        *num_steps = 0;
      }
      else
      {
        v9 = v8 / v7;
        v10 = 1.0 / v9 * offset->x;
        v11 = 1.0 / v9 * offset->y;
        result.z = 1.0 / v9 * offset->z;
        v12 = result.z;
        v13 = v10;
        offset_per_step->x = v13;
        v14 = v11;
        offset_per_step->y = v14;
        offset_per_step->z = v12;
        *num_steps = (unsigned __int64)_floor(v9) + 1;
      }
    }
    else
    {
      v15 = v8 / (1.0 * v7);
      if ( v15 > 1.0 )
      {
        v16 = _ceil(v15);
        v17 = 1.0 / v16 * offset->x;
        v18 = 1.0 / v16 * offset->y;
        result.z = 1.0 / v16 * offset->z;
        v19 = result.z;
        v20 = v17;
        offset_per_step->x = v20;
        v21 = v18;
        offset_per_step->y = v21;
        offset_per_step->z = v19;
        *num_steps = (unsigned __int64)v16;
      }
      else if ( offset->x != 0.0 || offset->y != 0.0 || offset->z != 0.0 )
      {
        COERCE_AC1LEGACY__VECTOR3(offset_per_step->x) = *offset;
        *num_steps = 1;
      }
      else
      {
        LODWORD(offset_per_step->x) = 0;
        LODWORD(offset_per_step->y) = 0;
        LODWORD(offset_per_step->z) = 0;
        *num_steps = 0;
      }
    }
  }
  else
  {
    LODWORD(offset->x) = 0;
    LODWORD(offset->y) = 0;
    LODWORD(offset->z) = 0;
    LODWORD(offset_per_step->x) = 0;
    LODWORD(offset_per_step->y) = 0;
    LODWORD(offset_per_step->z) = 0;
    *num_steps = 1;
  }
}

//----- (0050A370) --------------------------------------------------------  // acclient.c:311863
AC1Legacy::Vector3 *__thiscall CTransition::adjust_offset(CTransition *this, AC1Legacy::Vector3 *result, AC1Legacy::Vector3 *offset)
{
  float v3; // edx@1
  CTransition *v4; // edi@1
  float v5; // ecx@1
  int v6; // eax@1
  signed int v7; // ecx@1
  int v8; // esi@6
  double v9; // st7@9
  double v10; // st7@12
  double v11; // st6@12
  CSphere *v12; // ecx@15
  double v13; // st7@15
  double v14; // st7@16
  double v15; // st7@19
  double v16; // st6@19
  AC1Legacy::Vector3 *v17; // eax@20
  float v18; // ecx@20
  float v19; // edx@20
  AC1Legacy::Vector3 new_offset; // [sp+4h] [bp-24h]@1
  AC1Legacy::Vector3 coffset; // [sp+10h] [bp-18h]@7
  float v22; // [sp+20h] [bp-8h]@19
  float v23; // [sp+24h] [bp-4h]@9
  float offseta; // [sp+30h] [bp+8h]@6

  v3 = offset->y;
  v4 = this;
  v5 = offset->x;
  new_offset.z = offset->z;
  v6 = v4->collision_info.sliding_normal_valid;
  new_offset.x = v5;
  v7 = 0;
  new_offset.y = v3;
  if ( v6 )
  {
    if ( new_offset.z * v4->collision_info.sliding_normal.z
       + new_offset.y * v4->collision_info.sliding_normal.y
       + new_offset.x * v4->collision_info.sliding_normal.x < 0.0 )
      v7 = 1;
    else
      v4->collision_info.sliding_normal_valid = 0;
  }
  if ( v4->collision_info.contact_plane_valid )
  {
    v8 = (int)&v4->collision_info.contact_plane;
    offseta = new_offset.z * v4->collision_info.contact_plane.N.z
            + new_offset.y * v4->collision_info.contact_plane.N.y
            + new_offset.x * v4->collision_info.contact_plane.N.x;
    if ( v7 )
    {
      coffset.x = v4->collision_info.sliding_normal.z * v4->collision_info.contact_plane.N.y
                - v4->collision_info.sliding_normal.y * v4->collision_info.contact_plane.N.z;
      coffset.y = v4->collision_info.sliding_normal.x * v4->collision_info.contact_plane.N.z
                - v4->collision_info.sliding_normal.z * v4->collision_info.contact_plane.N.x;
      coffset.z = v4->collision_info.sliding_normal.y * *(float *)v8
                - v4->collision_info.sliding_normal.x * v4->collision_info.contact_plane.N.y;
      if ( AC1Legacy::Vector3::normalize_check_small(&coffset) )
      {
        LODWORD(coffset.x) = 0;
        LODWORD(coffset.y) = 0;
        LODWORD(coffset.z) = 0;
        LODWORD(new_offset.x) = 0;
        LODWORD(new_offset.y) = 0;
        LODWORD(new_offset.z) = 0;
      }
      else
      {
        v9 = coffset.z * new_offset.z + coffset.y * new_offset.y + coffset.x * new_offset.x;
        v23 = coffset.z * v9;
        coffset.z = v23;
        coffset.x = coffset.x * v9;
        LODWORD(new_offset.x) = (_DWORD)coffset.x;
        coffset.y = coffset.y * v9;
        new_offset.y = coffset.y;
        new_offset.z = v23;
      }
    }
    else if ( offseta <= 0.0 )
    {
      v10 = offseta * *(float *)v8;
      v11 = offseta * v4->collision_info.contact_plane.N.y;
      v23 = offseta * v4->collision_info.contact_plane.N.z;
      coffset.x = new_offset.x - v10;
      new_offset = coffset;
      coffset.y = new_offset.y - v11;
      coffset.z = new_offset.z - v23;
    }
    else
    {
      Plane::snap_to_plane(&v4->collision_info.contact_plane, &new_offset);
    }
    if ( !v4->collision_info.contact_plane_is_water )
    {
      if ( v4->collision_info.contact_plane_cell_id )
      {
        LandDefs::get_block_offset(
          &coffset,
          v4->sphere_path.check_pos.objcell_id,
          v4->collision_info.contact_plane_cell_id);
        v12 = v4->sphere_path.global_sphere;
        v13 = (v12->center.z - coffset.z) * v4->collision_info.contact_plane.N.z
            + (v12->center.y - coffset.y) * v4->collision_info.contact_plane.N.y
            + (v12->center.x - coffset.x) * v4->collision_info.contact_plane.N.x
            + v4->collision_info.contact_plane.d;
        if ( v13 < v12->radius - 0.00019999999 )
        {
          v14 = (v12->radius - v13) / v4->collision_info.contact_plane.N.z;
          if ( v12->radius > fabs(v14) )
          {
            coffset.z = v14;
            LODWORD(coffset.x) = 0;
            LODWORD(coffset.y) = 0;
            SPHEREPATH::add_offset_to_check_pos(&v4->sphere_path, &coffset);
          }
        }
      }
    }
  }
  else if ( v7 )
  {
    v15 = new_offset.x * v4->collision_info.sliding_normal.x
        + new_offset.z * v4->collision_info.sliding_normal.z
        + new_offset.y * v4->collision_info.sliding_normal.y;
    v16 = v15 * v4->collision_info.sliding_normal.x;
    v22 = v15 * v4->collision_info.sliding_normal.y;
    v23 = v15 * v4->collision_info.sliding_normal.z;
    coffset.x = new_offset.x - v16;
    new_offset = coffset;
    coffset.y = new_offset.y - v22;
    coffset.z = new_offset.z - v23;
  }
  v17 = result;
  v18 = new_offset.y;
  result->x = new_offset.x;
  v19 = new_offset.z;
  result->y = v18;
  result->z = v19;
  return v17;
}

//----- (0050A6D0) --------------------------------------------------------  // acclient.c:312004
signed int __thiscall CTransition::cliff_slide(CTransition *this, Plane *contact_plane)
{
  CTransition *v2; // esi@1
  double v3; // st7@1
  double v4; // st6@1
  double v5; // st5@1
  signed int v6; // eax@2
  CSphere *v7; // ecx@3
  AC1Legacy::Vector3 *v8; // eax@3
  double v9; // st7@3
  double v10; // st6@3
  double v11; // st5@3
  SPHEREPATH *v12; // ecx@3
  double v13; // st7@3
  double v14; // st7@4
  AC1Legacy::Vector3 *v15; // edx@4
  AC1Legacy::Vector3 collision_normal; // [sp+4h] [bp-30h]@1
  AC1Legacy::Vector3 result; // [sp+10h] [bp-24h]@3
  float v18; // [sp+24h] [bp-10h]@3
  float v19; // [sp+28h] [bp-Ch]@3
  float v20; // [sp+30h] [bp-4h]@4

  v2 = this;
  v3 = contact_plane->N.y * this->collision_info.last_known_contact_plane.N.z
     - contact_plane->N.z * this->collision_info.last_known_contact_plane.N.y;
  v4 = v2->collision_info.last_known_contact_plane.N.x * contact_plane->N.z
     - v2->collision_info.last_known_contact_plane.N.z * contact_plane->N.x;
  v5 = (contact_plane->N.x * v2->collision_info.last_known_contact_plane.N.y
      - contact_plane->N.y * v2->collision_info.last_known_contact_plane.N.x)
     * 0.0;
  collision_normal.x = v5 - v4;
  collision_normal.y = v3 - v5;
  collision_normal.z = v4 * 0.0 - v3 * 0.0;
  if ( AC1Legacy::Vector3::normalize_check_small(&collision_normal) )
  {
    v6 = 1;
  }
  else
  {
    LandDefs::get_block_offset(&result, v2->sphere_path.curr_pos.objcell_id, v2->sphere_path.check_pos.objcell_id);
    v7 = v2->sphere_path.global_sphere;
    v8 = v2->sphere_path.global_curr_center;
    v9 = v7->center.x - v8->x;
    v10 = v7->center.y - v8->y;
    v11 = v7->center.z - v8->z;
    v12 = &v2->sphere_path;
    v18 = v11;
    v19 = result.x + v9;
    v13 = (result.z + v18) * collision_normal.z + (result.y + v10) * collision_normal.y + v19 * collision_normal.x;
    if ( v13 <= 0.0 )
    {
      v20 = collision_normal.z * v13;
      result.z = v20;
      result.x = collision_normal.x * v13;
      result.y = collision_normal.y * v13;
      SPHEREPATH::add_offset_to_check_pos(v12, &result);
      v15 = &collision_normal;
    }
    else
    {
      v14 = -v13;
      v20 = collision_normal.z * v14;
      result.z = v20;
      result.x = collision_normal.x * v14;
      result.y = collision_normal.y * v14;
      SPHEREPATH::add_offset_to_check_pos(v12, &result);
      v15 = &result;
      result.x = -collision_normal.x;
      result.y = -collision_normal.y;
      result.z = -collision_normal.z;
    }
    COLLISIONINFO::set_collision_normal(&v2->collision_info, v15);
    v6 = 3;
  }
  return v6;
}

//----- (0050A880) --------------------------------------------------------  // acclient.c:312082
void __thiscall SPHEREPATH::save_check_pos(SPHEREPATH *this)
{
  this->backup_cell = this->check_cell;
  this->backup_check_pos.objcell_id = this->check_pos.objcell_id;
  Frame::operator=((int)&this->backup_check_pos.frame, (int)&this->check_pos.frame);
}

//----- (0050A8B0) --------------------------------------------------------  // acclient.c:312090
void __thiscall SPHEREPATH::set_check_pos(SPHEREPATH *this, Position *p, CObjCell *cell)
{
  SPHEREPATH *v3; // esi@1

  v3 = this;
  this->check_pos.objcell_id = p->objcell_id;
  Frame::operator=((int)&this->check_pos.frame, (int)&p->frame);
  v3->check_cell = cell;
  v3->cell_array_valid = 0;
  SPHEREPATH::cache_global_sphere(v3, 0);
}

//----- (0050A8F0) --------------------------------------------------------  // acclient.c:312103
Position *__thiscall SPHEREPATH::get_walkable_pos(SPHEREPATH *this, Position *result)
{
  result->vfptr = (PackObjVtbl *)&Position::vftable;
  result->objcell_id = this->walkable_pos.objcell_id;
  Frame::operator=((int)&result->frame, (int)&this->walkable_pos.frame);
  return result;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (0050A920) --------------------------------------------------------  // acclient.c:312113
void __thiscall CELLARRAY::CELLARRAY(CELLARRAY *this)
{
  CELLARRAY *v1; // esi@1
  void *v2; // eax@1
  int v3; // edi@2

  v1 = this;
  this->num_cells = 0;
  v2 = operator new[](0x44u);
  if ( v2 )
  {
    v3 = (int)((char *)v2 + 4);
    *(_DWORD *)v2 = 8;
    vector_constructor_iterator(
      (char *)v2 + 4,
      8u,
      8,
      (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
  }
  else
  {
    v3 = 0;
  }
  v1->cells.data = (CELLINFO *)v3;
  v1->cells.next_available = 0;
  v1->cells.sizeOf = 8;
  v1->cells.blocksize = 8;
  v1->num_cells = 0;
  v1->added_outside = 0;
  v1->do_not_load_cells = 0;
  v1->cells.blocksize = 8;
}

//----- (0050A980) --------------------------------------------------------  // acclient.c:312147
void __thiscall CTransition::CTransition(CTransition *this)
{
  CTransition *v1; // esi@1

  v1 = this;
  this->object_info.object = 0;
  this->object_info.state = 0;
  this->object_info.targetID = 0;
  SPHEREPATH::SPHEREPATH(&this->sphere_path);
  v1->collision_info.collide_object.data = 0;
  v1->collision_info.collide_object.sizeOf = 0;
  v1->collision_info.collide_object.next_available = 0;
  v1->collision_info.collide_object.blocksize = 128;
  v1->collision_info.last_known_contact_plane_valid = 0;
  v1->collision_info.contact_plane_valid = 0;
  v1->collision_info.sliding_normal_valid = 0;
  v1->collision_info.collision_normal_valid = 0;
  v1->collision_info.num_collide_object = 0;
  v1->collision_info.last_collided_object = 0;
  v1->collision_info.collided_with_environment = 0;
  v1->collision_info.contact_plane_cell_id = 0;
  v1->collision_info.frames_stationary_fall = 0;
  CELLARRAY::CELLARRAY(&v1->cell_array);
  CTransition::init(v1);
}

//----- (0050AA00) --------------------------------------------------------  // acclient.c:312174
BOOL __thiscall CTransition::check_collisions(CTransition *this, CPhysicsObj *object)
{
  CTransition *v2; // esi@1
  CObjCell *v3; // ebx@1
  char *v4; // edi@1

  v2 = this;
  v3 = this->sphere_path.curr_cell;
  this->sphere_path.insert_type = 1;
  v4 = (char *)&this->sphere_path;
  this->sphere_path.check_pos.objcell_id = this->sphere_path.curr_pos.objcell_id;
  Frame::operator=((int)&this->sphere_path.check_pos.frame, (int)&this->sphere_path.curr_pos.frame);
  *((_DWORD *)v4 + 66) = v3;
  *((_DWORD *)v4 + 141) = 0;
  SPHEREPATH::cache_global_sphere((SPHEREPATH *)v4, 0);
  return CPhysicsObj::FindObjCollisions(object, v2) != 1;
}

//----- (0050AA70) --------------------------------------------------------  // acclient.c:312193
TransitionState __thiscall CTransition::validate_transition(CTransition *this, TransitionState ts, int *redo)
{
  TransitionState v3; // ebx@1
  CTransition *v4; // esi@1
  CObjCell *v5; // ebp@14
  CObjCell *v6; // ebp@14
  unsigned int v7; // ecx@18
  int v8; // eax@20
  CSphere *v9; // eax@24
  double v10; // st7@24
  double v11; // st7@24
  bool v12; // zf@24
  int v13; // eax@27
  int v14; // edi@28
  int v15; // edx@28
  int v16; // eax@30
  TransitionState result; // eax@31
  Plane contact_plane; // [sp+10h] [bp-10h]@12
  int *redoa; // [sp+28h] [bp+8h]@1

  v3 = ts;
  v4 = this;
  *redo = 0;
  redoa = (int *)1;
  if ( (ts != 1
     || this->sphere_path.check_pos.objcell_id == this->sphere_path.curr_pos.objcell_id
     && Frame::is_equal(&this->sphere_path.check_pos.frame, &this->sphere_path.curr_pos.frame))
    && (redoa = 0, ts != 1) )
  {
    if ( (signed int)ts > 1 && (signed int)ts <= 4 )
    {
      if ( v4->collision_info.last_known_contact_plane_valid )
      {
        OBJECTINFO::kill_velocity(&v4->object_info);
        if ( v4->sphere_path.global_sphere->radius + 0.00019999999 > fabs(v4->sphere_path.global_curr_center->z
                                                                        * v4->collision_info.last_known_contact_plane.N.z
                                                                        + v4->sphere_path.global_curr_center->y
                                                                        * v4->collision_info.last_known_contact_plane.N.y
                                                                        + v4->sphere_path.global_curr_center->x
                                                                        * v4->collision_info.last_known_contact_plane.N.x + v4->collision_info.last_known_contact_plane.d) )
        {
          COLLISIONINFO::set_contact_plane(
            &v4->collision_info,
            &v4->collision_info.last_known_contact_plane,
            v4->collision_info.last_known_contact_plane_is_water);
          v4->collision_info.contact_plane_cell_id = v4->collision_info.last_known_contact_plane_cell_id;
          if ( v4->object_info.state & 2 )
            redoa = (int *)1;
        }
      }
      if ( !v4->collision_info.collision_normal_valid )
      {
        LODWORD(contact_plane.N.x) = 0;
        LODWORD(contact_plane.N.y) = 0;
        LODWORD(contact_plane.N.z) = 1065353216;
        COLLISIONINFO::set_collision_normal(&v4->collision_info, &contact_plane.N);
      }
      SPHEREPATH::set_check_pos(&v4->sphere_path, &v4->sphere_path.curr_pos, v4->sphere_path.curr_cell);
      CTransition::build_cell_array(v4, 0);
      v3 = 1;
    }
  }
  else
  {
    v5 = v4->sphere_path.check_cell;
    v4->sphere_path.curr_pos.objcell_id = v4->sphere_path.check_pos.objcell_id;
    Frame::operator=((int)&v4->sphere_path.curr_pos.frame, (int)&v4->sphere_path.check_pos.frame);
    v4->sphere_path.curr_cell = v5;
    SPHEREPATH::cache_global_curr_center(&v4->sphere_path);
    v6 = v4->sphere_path.curr_cell;
    v4->sphere_path.check_pos.objcell_id = v4->sphere_path.curr_pos.objcell_id;
    Frame::operator=((int)&v4->sphere_path.check_pos.frame, (int)&v4->sphere_path.curr_pos.frame);
    v4->sphere_path.check_cell = v6;
    v4->sphere_path.cell_array_valid = 0;
    SPHEREPATH::cache_global_sphere(&v4->sphere_path, 0);
  }
  if ( v4->collision_info.collision_normal_valid )
    COLLISIONINFO::set_sliding_normal(&v4->collision_info, &v4->collision_info.collision_normal);
  if ( !(v4->object_info.state & 4) )
  {
    v7 = v4->object_info.object->state;
    if ( BYTE1(v7) & 4 )
    {
      if ( redoa )
      {
        v4->collision_info.frames_stationary_fall = 0;
      }
      else
      {
        v8 = v4->collision_info.frames_stationary_fall;
        if ( v8 )
        {
          if ( v8 == 1 )
          {
            v4->collision_info.frames_stationary_fall = 2;
          }
          else
          {
            v9 = v4->sphere_path.global_sphere;
            v4->collision_info.frames_stationary_fall = 3;
            v10 = v9->center.y + v9->center.x;
            LODWORD(contact_plane.N.x) = 0;
            v11 = v10 * 0.0 + v9->center.z;
            LODWORD(contact_plane.N.y) = 0;
            LODWORD(contact_plane.N.z) = 1065353216;
            contact_plane.d = v9->radius - v11;
            COLLISIONINFO::set_contact_plane(&v4->collision_info, &contact_plane, 0);
            v12 = (v4->object_info.state & 1) == 0;
            v4->collision_info.contact_plane_cell_id = v4->sphere_path.check_pos.objcell_id;
            if ( v12 )
            {
              COLLISIONINFO::set_collision_normal(&v4->collision_info, &contact_plane.N);
              v4->collision_info.collided_with_environment = 1;
            }
          }
        }
        else
        {
          v4->collision_info.frames_stationary_fall = 1;
        }
      }
    }
  }
  v13 = v4->collision_info.contact_plane_valid;
  v4->collision_info.last_known_contact_plane_valid = v13;
  if ( v13 )
  {
    v14 = (int)&v4->collision_info.last_known_contact_plane;
    *(_DWORD *)v14 = LODWORD(v4->collision_info.contact_plane.N.x);
    *(_DWORD *)(v14 + 4) = LODWORD(v4->collision_info.contact_plane.N.y);
    *(_DWORD *)(v14 + 8) = LODWORD(v4->collision_info.contact_plane.N.z);
    *(_DWORD *)(v14 + 12) = LODWORD(v4->collision_info.contact_plane.d);
    v15 = v4->collision_info.contact_plane_is_water;
    v4->collision_info.last_known_contact_plane_cell_id = v4->collision_info.contact_plane_cell_id;
    v4->collision_info.last_known_contact_plane_is_water = v15;
  }
  if ( v4->collision_info.contact_plane_valid )
  {
    v4->object_info.state |= 1u;
    v12 = OBJECTINFO::is_valid_walkable(&v4->object_info, &v4->collision_info.contact_plane.N) == 0;
    v16 = v4->object_info.state;
    if ( v12 )
    {
      v4->object_info.state = v16 & 0xFFFFFFFD;
      result = v3;
    }
    else
    {
      v4->object_info.state = v16 | 2;
      result = v3;
    }
  }
  else
  {
    v4->object_info.state &= 0xFFFFFFFC;
    result = v3;
  }
  return result;
}

//----- (0050ADC0) --------------------------------------------------------  // acclient.c:312354
signed int __thiscall CTransition::validate_placement_transition(CTransition *this, TransitionState ts, int *redo)
{
  CObjCell *v3; // edi@1
  char *v5; // esi@8

  *redo = 0;
  v3 = this->sphere_path.check_cell;
  if ( !v3 )
    return 2;
  if ( ts == 1 )
  {
    v5 = (char *)&this->sphere_path;
    this->sphere_path.curr_pos.objcell_id = this->sphere_path.check_pos.objcell_id;
    Frame::operator=((int)&this->sphere_path.curr_pos.frame, (int)&this->sphere_path.check_pos.frame);
    *((_DWORD *)v5 + 39) = v3;
    SPHEREPATH::cache_global_curr_center((SPHEREPATH *)v5);
  }
  else if ( (signed int)ts > 1 && (signed int)ts <= 4 && this->sphere_path.placement_allows_sliding )
  {
    COLLISIONINFO::init(&this->collision_info);
    return ts;
  }
  return ts;
}

//----- (0050AE50) --------------------------------------------------------  // acclient.c:312380
int __thiscall CTransition::check_other_cells(CTransition *this, CObjCell *curr_cell)
{
  CTransition *v2; // esi@1
  char *v3; // edi@1
  unsigned int v4; // ebx@1
  signed int v5; // ebp@1
  CObjCell *v6; // ecx@2
  int result; // eax@4
  CObjCell *v8; // eax@6
  bool v9; // zf@6
  unsigned int v10; // edx@11
  unsigned int v11; // eax@11
  CObjCell *new_cell2; // [sp+10h] [bp-4Ch]@1
  Position p; // [sp+14h] [bp-48h]@11

  v2 = this;
  v3 = (char *)&this->sphere_path;
  v4 = 0;
  v5 = 1;
  new_cell2 = 0;
  this->sphere_path.cell_array_valid = 1;
  this->sphere_path.hits_interior_cell = 0;
  CObjCell::find_cell_list(&this->cell_array, &new_cell2, &this->sphere_path);
  if ( v2->cell_array.num_cells )
  {
    while ( 1 )
    {
      v6 = v2->cell_array.cells.data[v4].cell;
      if ( v6 )
      {
        if ( v6 != curr_cell )
          break;
      }
$L93964:
      ++v4;
      if ( v4 >= v2->cell_array.num_cells )
        goto LABEL_6;
    }
    result = ((int (__stdcall *)(CTransition *))v6->vfptr[5].AddRef)(v2);
    v5 = result;
    switch ( result )
    {
      default:
        goto $L93964;
      case 4:
        v2->collision_info.contact_plane_valid = 0;
        v2->collision_info.contact_plane_is_water = 0;
        return result;
      case 2:
      case 3:
        return v5;
    }
  }
  else
  {
LABEL_6:
    v8 = new_cell2;
    v9 = new_cell2 == 0;
    v2->sphere_path.check_cell = new_cell2;
    if ( !v9 )
    {
      SPHEREPATH::adjust_check_pos((SPHEREPATH *)v3, v8->m_DID.id);
      return v5;
    }
    if ( v2->sphere_path.step_down )
      return 2;
    v10 = v2->sphere_path.check_pos.objcell_id;
    p.vfptr = (PackObjVtbl *)&Position::vftable;
    p.objcell_id = v10;
    Frame::operator=((int)&p.frame, (int)&v2->sphere_path.check_pos.frame);
    v11 = p.objcell_id;
    if ( LOWORD(p.objcell_id) < 0x100u )
    {
      LandDefs::adjust_to_outside(&p.objcell_id, &p.frame.m_fOrigin);
      v11 = p.objcell_id;
    }
    if ( v11 )
    {
      SPHEREPATH::adjust_check_pos((SPHEREPATH *)v3, v11);
      *((_DWORD *)v3 + 68) = p.objcell_id;
      Frame::operator=((int)(v3 + 276), (int)&p.frame);
      *((_DWORD *)v3 + 66) = 0;
      *((_DWORD *)v3 + 141) = 0;
      SPHEREPATH::cache_global_sphere((SPHEREPATH *)v3, 0);
      v2->sphere_path.cell_array_valid = 1;
      return v5;
    }
    v5 = 2;
  }
  return v5;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (0050AFF0) --------------------------------------------------------  // acclient.c:312474
int __thiscall CTransition::check_walkable(CTransition *this, float z_chk)
{
  CTransition *v2; // esi@1
  char *v3; // edi@2
  unsigned int v4; // eax@3
  CObjCell *v5; // ebp@3
  double v6; // st7@3
  bool v7; // cf@3
  CSphere *v8; // ecx@4
  signed int v9; // ebx@8
  int result; // eax@8
  AC1Legacy::Vector3 offset; // [sp+8h] [bp-54h]@8
  Position backup_check_pos; // [sp+14h] [bp-48h]@3

  v2 = this;
  if ( !(this->object_info.state & 2)
    || (v3 = (char *)&this->sphere_path, SPHEREPATH::check_walkables(&this->sphere_path)) )
  {
    result = 1;
  }
  else
  {
    v4 = v2->sphere_path.check_pos.objcell_id;
    v5 = v2->sphere_path.check_cell;
    backup_check_pos.vfptr = (PackObjVtbl *)&Position::vftable;
    backup_check_pos.objcell_id = v4;
    Frame::operator=((int)&backup_check_pos.frame, (int)&v2->sphere_path.check_pos.frame);
    v6 = v2->object_info.step_down_height;
    v7 = *(_DWORD *)v3 < 2u;
    v2->sphere_path.walkable_allowance = z_chk;
    v2->sphere_path.check_walkable = 1;
    if ( v7 )
    {
      v8 = v2->sphere_path.global_sphere;
      if ( v6 > v8->radius + v8->radius )
        v6 = v8->radius * 0.5;
    }
    if ( v6 > v2->sphere_path.global_sphere->radius + v2->sphere_path.global_sphere->radius )
      v6 = v6 * 0.5;
    offset.z = -v6;
    LODWORD(offset.x) = 0;
    LODWORD(offset.y) = 0;
    SPHEREPATH::add_offset_to_check_pos(&v2->sphere_path, &offset);
    v9 = CTransition::transitional_insert(v2, 1);
    v2->sphere_path.check_walkable = 0;
    SPHEREPATH::set_check_pos(&v2->sphere_path, &backup_check_pos, v5);
    result = v9 != 1;
  }
  return result;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (0050B100) --------------------------------------------------------  // acclient.c:312527
void __thiscall SPHEREPATH::restore_check_pos(SPHEREPATH *this)
{
  SPHEREPATH *v1; // esi@1
  CObjCell *v2; // edi@1

  v1 = this;
  v2 = this->backup_cell;
  this->check_pos.objcell_id = this->backup_check_pos.objcell_id;
  Frame::operator=((int)&this->check_pos.frame, (int)&this->backup_check_pos.frame);
  v1->check_cell = v2;
  v1->cell_array_valid = 0;
  SPHEREPATH::cache_global_sphere(v1, 0);
}

//----- (0050B150) --------------------------------------------------------  // acclient.c:312542
CTransition *__cdecl CTransition::makeTransition()
{
  CTransition *v0; // esi@2
  signed int v1; // edi@2
  CTransition *v2; // esi@6
  CTransition *result; // eax@6

  if ( !(dword_843B70 & 1) )
  {
    dword_843B70 |= 1u;
    v0 = transit;
    v1 = 10;
    do
    {
      CTransition::CTransition(v0);
      ++v0;
      --v1;
    }
    while ( v1 );
    atexit(sub_766A10);
  }
  if ( CTransition::transition_level >= 10 )
  {
    result = 0;
  }
  else
  {
    v2 = &transit[CTransition::transition_level];
    CTransition::init(&transit[CTransition::transition_level++]);
    result = v2;
  }
  return result;
}
// 841C5C: using guessed type int CTransition::transition_level;

//----- (0050B1D0) --------------------------------------------------------  // acclient.c:312578
int __thiscall CTransition::placement_insert(CTransition *this)
{
  CTransition *v1; // esi@1
  CObjCell *v2; // eax@1
  int result; // eax@2

  v1 = this;
  v2 = this->sphere_path.check_cell;
  if ( v2 )
  {
    result = CTransition::insert_into_cell(this, v2, 3);
    if ( result == 1 )
      result = CTransition::check_other_cells(v1, v1->sphere_path.check_cell);
  }
  else
  {
    result = 2;
  }
  return result;
}

//----- (0050B210) --------------------------------------------------------  // acclient.c:312600
TransitionState __thiscall CTransition::validate_placement(CTransition *this, TransitionState ts, int adjust)
{
  CTransition *v3; // esi@1
  CObjCell *v4; // ebx@1
  int v6; // eax@7
  char *v7; // edi@8

  v3 = this;
  v4 = this->sphere_path.check_cell;
  if ( !v4 )
    return 2;
  if ( ts == 1 )
  {
    v7 = (char *)&this->sphere_path;
    this->sphere_path.curr_pos.objcell_id = this->sphere_path.check_pos.objcell_id;
    Frame::operator=((int)&this->sphere_path.curr_pos.frame, (int)&this->sphere_path.check_pos.frame);
    *((_DWORD *)v7 + 39) = v4;
    SPHEREPATH::cache_global_curr_center((SPHEREPATH *)v7);
  }
  else if ( (signed int)ts > 2 && (signed int)ts <= 4 && adjust )
  {
    v6 = CTransition::placement_insert(this);
    return CTransition::validate_placement(v3, (TransitionState)v6, 0);
  }
  return ts;
}

//----- (0050B2A0) --------------------------------------------------------  // acclient.c:312628
int __thiscall CTransition::step_down(CTransition *this, float step_down_ht, float z_val)
{
  CTransition *v3; // edi@1
  char *v4; // esi@1
  float v5; // ecx@2
  int v6; // edx@2
  double v7; // st7@2
  signed int v8; // eax@3
  int v9; // eax@6
  signed int v10; // eax@9
  int result; // eax@9
  AC1Legacy::Vector3 offset; // [sp+8h] [bp-Ch]@2

  v3 = this;
  v4 = (char *)&this->sphere_path;
  this->sphere_path.neg_poly_hit = 0;
  this->sphere_path.step_down = 1;
  *((float *)v4 + 112) = step_down_ht;
  *((_DWORD *)v4 + 111) = 1065353216;
  if ( !this->sphere_path.step_up )
  {
    this->sphere_path.cell_array_valid = 0;
    v5 = this->sphere_path.check_pos.frame.m_fOrigin.x;
    v6 = *((_DWORD *)v4 + 83);
    offset.z = -step_down_ht;
    v7 = offset.z + *((float *)v4 + 84);
    *((float *)v4 + 82) = v5;
    *((float *)v4 + 84) = v7;
    LODWORD(offset.x) = 0;
    LODWORD(offset.y) = 0;
    *((_DWORD *)v4 + 83) = v6;
    SPHEREPATH::cache_global_sphere((SPHEREPATH *)v4, &offset);
  }
  v8 = CTransition::transitional_insert(v3, 5);
  v3->sphere_path.step_down = 0;
  if ( v8 == 1
    && v3->collision_info.contact_plane_valid
    && v3->collision_info.contact_plane.N.z >= (double)z_val
    && ((v9 = v3->object_info.state, !(BYTE1(v9) & 2))
     || v3->sphere_path.step_up
     || CTransition::check_walkable(v3, z_val)) )
  {
    *((_DWORD *)v4 + 87) = *((_DWORD *)v4 + 85);
    *((_DWORD *)v4 + 85) = 1;
    v10 = CTransition::transitional_insert(v3, 1);
    *((_DWORD *)v4 + 85) = *((_DWORD *)v4 + 87);
    result = v10 == 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0050B3D0) --------------------------------------------------------  // acclient.c:312684
int __thiscall CTransition::edge_slide(CTransition *this, TransitionState *ts, float step_down_ht, float z_val)
{
  CTransition *v4; // esi@1
  int v5; // eax@1
  int v6; // ecx@3
  int v7; // eax@5
  AC1Legacy::Vector3 *v8; // ecx@8
  CSphere *v9; // eax@8
  double v10; // st7@8
  double v11; // st6@8
  int v12; // ebp@8
  const float v13; // ST04_4@10
  Position *v14; // eax@10
  signed int v15; // eax@10
  int v16; // eax@12
  signed int v17; // eax@12
  CObjCell *v18; // ebp@13
  AC1Legacy::Vector3 move; // [sp+10h] [bp-54h]@8
  Position result; // [sp+1Ch] [bp-48h]@10

  v4 = this;
  v5 = this->object_info.state;
  if ( v5 & 2 && BYTE1(v5) & 2 )
  {
    v6 = this->collision_info.contact_plane_valid;
    if ( v6 && v4->collision_info.contact_plane.N.z < (double)z_val )
    {
      v4->sphere_path.walkable = 0;
      SPHEREPATH::restore_check_pos(&v4->sphere_path);
      *ts = CTransition::cliff_slide(v4, &v4->collision_info.contact_plane);
      v4->collision_info.contact_plane_valid = 0;
      v4->collision_info.contact_plane_is_water = 0;
      v7 = 0;
    }
    else if ( v4->sphere_path.walkable )
    {
      SPHEREPATH::restore_check_pos(&v4->sphere_path);
      v16 = (int)&v4->collision_info.last_known_contact_plane_valid;
      *(_DWORD *)(v16 + 24) = 0;
      *(_DWORD *)(v16 + 52) = 0;
      v17 = SPHEREPATH::precipice_slide(&v4->sphere_path, &v4->collision_info);
      *ts = v17;
      v7 = v17 == 2;
    }
    else if ( v6 )
    {
      v4->sphere_path.walkable = 0;
      SPHEREPATH::restore_check_pos(&v4->sphere_path);
      v7 = 1;
      v4->sphere_path.cell_array_valid = 1;
      v4->collision_info.contact_plane_valid = 0;
      v4->collision_info.contact_plane_is_water = 0;
      *ts = 1;
    }
    else
    {
      v8 = v4->sphere_path.global_curr_center;
      v9 = v4->sphere_path.global_sphere;
      v10 = v8->z - v9->center.z;
      v11 = v8->y - v9->center.y;
      move.x = v8->x - v9->center.x;
      move.y = v11;
      move.z = v10;
      SPHEREPATH::add_offset_to_check_pos(&v4->sphere_path, &move);
      CTransition::step_down(v4, step_down_ht, z_val);
      v12 = (int)&v4->collision_info.last_known_contact_plane_valid;
      *(_DWORD *)(v12 + 24) = 0;
      *(_DWORD *)(v12 + 52) = 0;
      SPHEREPATH::restore_check_pos(&v4->sphere_path);
      if ( v4->sphere_path.walkable )
      {
        v4->collision_info.contact_plane_valid = 0;
        v4->collision_info.contact_plane_is_water = 0;
        v13 = v4->sphere_path.walkable_scale;
        v14 = SPHEREPATH::get_walkable_pos(&v4->sphere_path, &result);
        SPHEREPATH::cache_localspace_sphere(&v4->sphere_path, v14, v13);
        SPHEREPATH::set_walkable_check_pos(&v4->sphere_path, v4->sphere_path.localspace_sphere);
        v15 = SPHEREPATH::precipice_slide(&v4->sphere_path, &v4->collision_info);
        *ts = v15;
        v7 = v15 == 2;
      }
      else
      {
        v4->sphere_path.walkable = 0;
        v7 = 1;
        *ts = 2;
        v4->sphere_path.cell_array_valid = 1;
      }
    }
  }
  else
  {
    this->sphere_path.walkable = 0;
    v18 = this->sphere_path.backup_cell;
    this->sphere_path.check_pos.objcell_id = this->sphere_path.backup_check_pos.objcell_id;
    Frame::operator=((int)&this->sphere_path.check_pos.frame, (int)&this->sphere_path.backup_check_pos.frame);
    v4->sphere_path.check_cell = v18;
    v4->sphere_path.cell_array_valid = 0;
    SPHEREPATH::cache_global_sphere(&v4->sphere_path, 0);
    v4->collision_info.contact_plane_valid = 0;
    v4->collision_info.contact_plane_is_water = 0;
    v7 = 1;
    v4->sphere_path.cell_array_valid = 1;
    *ts = 1;
  }
  return v7;
}

//----- (0050B610) --------------------------------------------------------  // acclient.c:312793
int __thiscall CTransition::step_up(CTransition *this, AC1Legacy::Vector3 *collision_normal)
{
  CTransition *v2; // esi@1
  int v3; // eax@3
  int result; // eax@4
  float step_down_ht; // [sp+0h] [bp-4h]@1
  float collision_normala; // [sp+8h] [bp+4h]@1

  v2 = this;
  this->collision_info.contact_plane_valid = 0;
  this->collision_info.contact_plane_is_water = 0;
  this->sphere_path.step_up = 1;
  this->sphere_path.step_up_normal = *collision_normal;
  step_down_ht = 0.039999999;
  collision_normala = z_for_landing;
  if ( this->object_info.state & 2 )
  {
    collision_normala = OBJECTINFO::get_walkable_z(&this->object_info);
    step_down_ht = v2->object_info.step_up_height;
  }
  v2->sphere_path.walkable_allowance = collision_normala;
  v2->sphere_path.backup_cell = v2->sphere_path.check_cell;
  v2->sphere_path.backup_check_pos.objcell_id = v2->sphere_path.check_pos.objcell_id;
  Frame::operator=((int)&v2->sphere_path.backup_check_pos.frame, (int)&v2->sphere_path.check_pos.frame);
  v3 = CTransition::step_down(v2, step_down_ht, collision_normala);
  v2->sphere_path.step_up = 0;
  v2->sphere_path.walkable = 0;
  if ( v3 )
  {
    result = 1;
  }
  else
  {
    SPHEREPATH::restore_check_pos(&v2->sphere_path);
    result = 0;
  }
  return result;
}

//----- (0050B6F0) --------------------------------------------------------  // acclient.c:312833
signed int __thiscall CTransition::transitional_insert(CTransition *this, int num_insertion_attempts)
{
  CTransition *v2; // esi@1
  signed int result; // eax@2
  int v4; // eax@3
  TransitionState v5; // edi@3
  int v6; // eax@5
  bool v7; // zf@16
  int v8; // eax@21
  CSphere *v9; // ecx@28
  double v10; // st7@30
  float v11; // edi@30
  float v12; // ebx@31
  float v13; // ebx@34
  int v14; // eax@33
  int v15; // eax@41
  signed int v16; // ebx@41
  int v17; // edi@47
  TransitionState ts; // [sp+8h] [bp-14h]@4
  float step_down_ht; // [sp+Ch] [bp-10h]@25
  float z_val; // [sp+10h] [bp-Ch]@25
  int i; // [sp+14h] [bp-8h]@3
  float v22; // [sp+18h] [bp-4h]@31

  v2 = this;
  if ( !this->sphere_path.check_cell )
    return 1;
  v4 = num_insertion_attempts;
  v5 = 0;
  i = 0;
  if ( num_insertion_attempts <= 0 )
    return v5;
  while ( 2 )
  {
    v5 = CTransition::insert_into_cell(v2, v2->sphere_path.check_cell, v4);
    ts = v5;
    switch ( v5 )
    {
      case 1:
        v6 = CTransition::check_other_cells(v2, v2->sphere_path.check_cell);
        v5 = v6;
        ts = v6;
        if ( v6 != 1 )
          v2->sphere_path.neg_poly_hit = 0;
        if ( v6 == 2 )
          goto LABEL_50;
        goto LABEL_11;
      case 4:
        v2->collision_info.contact_plane_valid = 0;
        v2->collision_info.contact_plane_is_water = 0;
        goto $L99778;
      case 3:
$L99778:
        v2->sphere_path.neg_poly_hit = 0;
        goto LABEL_11;
      case 2:
        result = v5;
        v2->sphere_path.neg_poly_hit = 0;
        return result;
      default:
LABEL_11:
        if ( v5 != 1 )
          goto LABEL_38;
        if ( v2->sphere_path.collide )
        {
          v15 = v2->collision_info.contact_plane_valid;
          v16 = 0;
          v2->sphere_path.collide = 0;
          if ( v15 && CTransition::check_walkable(v2, 0.0871557) )
          {
            v2->sphere_path.backup = v2->sphere_path.insert_type;
            v2->sphere_path.insert_type = 1;
            v5 = CTransition::transitional_insert(v2, num_insertion_attempts);
            v2->sphere_path.insert_type = v2->sphere_path.backup;
            if ( v5 != 1 )
            {
              v5 = 1;
              goto LABEL_45;
            }
          }
          else
          {
LABEL_45:
            v16 = 1;
          }
          v2->sphere_path.walkable = 0;
          if ( v16 )
          {
            SPHEREPATH::restore_check_pos(&v2->sphere_path);
            v17 = (int)&v2->collision_info.last_known_contact_plane_valid;
            *(_DWORD *)(v17 + 24) = 0;
            *(_DWORD *)(v17 + 52) = 0;
            if ( v2->collision_info.last_known_contact_plane_valid )
            {
              OBJECTINFO::kill_velocity(&v2->object_info);
              *(_DWORD *)v17 = 0;
LABEL_50:
              result = 2;
            }
            else
            {
              COLLISIONINFO::set_collision_normal((COLLISIONINFO *)v17, &v2->sphere_path.step_up_normal);
              result = 2;
            }
            return result;
          }
          return v5;
        }
        if ( v2->sphere_path.neg_poly_hit && !v2->sphere_path.step_down && !v2->sphere_path.step_up )
        {
          v7 = v2->sphere_path.neg_step_up == 0;
          v2->sphere_path.neg_poly_hit = 0;
          if ( v7 )
          {
            v5 = CSphere::slide_sphere(
                   v2->sphere_path.global_sphere,
                   &v2->sphere_path,
                   &v2->collision_info,
                   &v2->sphere_path.neg_collision_normal,
                   v2->sphere_path.global_curr_center);
          }
          else if ( !CTransition::step_up(v2, &v2->sphere_path.neg_collision_normal) )
          {
            v5 = SPHEREPATH::step_up_slide(&v2->sphere_path, &v2->object_info, &v2->collision_info);
          }
          goto LABEL_38;
        }
        if ( v2->collision_info.contact_plane_valid )
          return 1;
        v8 = v2->object_info.state;
        if ( !(v8 & 1) || v2->sphere_path.step_down || !v2->sphere_path.check_cell || !v2->object_info.step_down )
          return 1;
        step_down_ht = 0.039999999;
        z_val = z_for_landing;
        if ( v8 & 2 )
        {
          z_val = OBJECTINFO::get_walkable_z(&v2->object_info);
          step_down_ht = v2->object_info.step_down_height;
        }
        v2->sphere_path.walkable_allowance = z_val;
        SPHEREPATH::save_check_pos(&v2->sphere_path);
        if ( v2->sphere_path.num_sphere < 2 )
        {
          v9 = v2->sphere_path.global_sphere;
          if ( v9->radius + v9->radius < step_down_ht )
            step_down_ht = v9->radius * 0.5;
        }
        v10 = v2->sphere_path.global_sphere->radius;
        v11 = z_val;
        if ( v10 + v10 >= step_down_ht )
        {
          v13 = step_down_ht;
          if ( CTransition::step_down(v2, step_down_ht, z_val) )
            goto LABEL_52;
          v14 = CTransition::edge_slide(v2, &ts, v13, v11);
          goto LABEL_36;
        }
        v22 = step_down_ht * 0.5;
        v12 = v22;
        if ( !CTransition::step_down(v2, v22, z_val) && !CTransition::step_down(v2, v12, v11) )
        {
          v14 = CTransition::edge_slide(v2, &ts, v12, v11);
LABEL_36:
          if ( v14 )
            return ts;
          v5 = ts;
LABEL_38:
          v4 = num_insertion_attempts;
          ++i;
          if ( i >= num_insertion_attempts )
            return v5;
          continue;
        }
LABEL_52:
        v2->sphere_path.walkable = 0;
        return 1;
    }
  }
}

//----- (0050BA50) --------------------------------------------------------  // acclient.c:313014
int __thiscall CTransition::find_placement_pos(CTransition *this)
{
  CTransition *v1; // edi@1
  CObjCell *v2; // ebx@1
  char *v3; // esi@1
  signed int v4; // eax@1
  signed int v5; // ecx@3
  double v6; // st7@7
  double v8; // st7@11
  double v9; // st7@12
  unsigned __int64 v10; // rax@12
  unsigned int v11; // ebx@12
  int v12; // ebx@13
  int v13; // edx@14
  float v14; // ST04_4@14
  AC1Legacy::Vector3 *v15; // eax@14
  double v16; // st7@14
  double v17; // st6@14
  AC1Legacy::Vector3 *v18; // eax@14
  double v19; // st7@14
  unsigned __int8 v21; // c0@14
  unsigned __int8 v22; // c3@14
  signed int v23; // eax@15
  float j; // [sp+18h] [bp-98h]@3
  unsigned int ja; // [sp+18h] [bp-98h]@12
  float adjust_rad; // [sp+1Ch] [bp-94h]@3
  float adjust_rada; // [sp+1Ch] [bp-94h]@11
  float distance; // [sp+20h] [bp-90h]@11
  int redo; // [sp+24h] [bp-8Ch]@1
  const float angle_offset; // [sp+28h] [bp-88h]@12
  unsigned int i; // [sp+2Ch] [bp-84h]@11
  float dist_per_step; // [sp+30h] [bp-80h]@11
  unsigned int num_steps; // [sp+34h] [bp-7Ch]@11
  float d_num_radial; // [sp+38h] [bp-78h]@11
  unsigned int num_rad; // [sp+3Ch] [bp-74h]@12
  AC1Legacy::Vector3 offset; // [sp+40h] [bp-70h]@14
  float v37; // [sp+54h] [bp-5Ch]@14
  Frame offset_frame; // [sp+58h] [bp-58h]@12
  AC1Legacy::Vector3 v39; // [sp+98h] [bp-18h]@14
  AC1Legacy::Vector3 result; // [sp+A4h] [bp-Ch]@14

  v1 = this;
  v2 = this->sphere_path.curr_cell;
  v3 = (char *)&this->sphere_path;
  this->sphere_path.check_pos.objcell_id = this->sphere_path.curr_pos.objcell_id;
  Frame::operator=((int)&this->sphere_path.check_pos.frame, (int)&this->sphere_path.curr_pos.frame);
  *((_DWORD *)v3 + 66) = v2;
  *((_DWORD *)v3 + 141) = 0;
  SPHEREPATH::cache_global_sphere((SPHEREPATH *)v3, 0);
  v1->collision_info.sliding_normal_valid = 0;
  v1->collision_info.contact_plane_valid = 0;
  v1->collision_info.contact_plane_is_water = 0;
  v4 = CTransition::transitional_insert(v1, 3);
  if ( CTransition::validate_placement_transition(v1, (TransitionState)v4, &redo) != 1 )
  {
    if ( !v1->sphere_path.placement_allows_sliding )
      return 0;
    j = v1->sphere_path.local_sphere->radius;
    v5 = 0;
    adjust_rad = 4.0;
    if ( j >= 0.125 )
    {
      if ( j < 0.47999999 )
        j = 0.47999999;
    }
    else
    {
      v5 = 1;
      adjust_rad = 2.0;
    }
    v6 = 4.0 / (1.0 * j);
    if ( v5 )
      v6 = v6 * 0.5;
    if ( v6 <= 1.0 )
      return 0;
    v8 = _ceil(v6);
    dist_per_step = adjust_rad / v8;
    num_steps = (unsigned __int64)v8;
    distance = 0.0;
    adjust_rada = 0.0;
    i = 0;
    d_num_radial = dist_per_step / j * 3.1415999;
    if ( num_steps <= 0 )
      return 0;
    while ( 1 )
    {
      distance = distance + dist_per_step;
      v9 = d_num_radial + adjust_rada;
      adjust_rada = v9;
      v10 = (unsigned __int64)_ceil(v9);
      v11 = 2 * v10;
      num_rad = 2 * v10;
      LODWORD(offset_frame.qw) = 1065353216;
      LODWORD(offset_frame.qx) = 0;
      LODWORD(offset_frame.qy) = 0;
      LODWORD(offset_frame.qz) = 0;
      LODWORD(offset_frame.m_fOrigin.x) = 0;
      LODWORD(offset_frame.m_fOrigin.y) = 0;
      LODWORD(offset_frame.m_fOrigin.z) = 0;
      angle_offset = 360.0 / (double)(unsigned int)(2 * v10);
      Frame::cache(&offset_frame);
      ja = 0;
      if ( v11 > 0 )
        break;
LABEL_17:
      ++i;
      if ( i >= num_steps )
        return 0;
    }
    v12 = (int)&v1->sphere_path.global_offset;
    while ( 1 )
    {
      v13 = (int)v1->sphere_path.curr_cell;
      *((_DWORD *)v3 + 68) = v1->sphere_path.curr_pos.objcell_id;
      redo = v13;
      Frame::operator=((int)(v3 + 276), (int)&v1->sphere_path.curr_pos.frame);
      *((_DWORD *)v3 + 66) = redo;
      *((_DWORD *)v3 + 141) = 0;
      SPHEREPATH::cache_global_sphere((SPHEREPATH *)v3, 0);
      v14 = (double)ja * angle_offset;
      Frame::set_heading(&offset_frame, v14);
      v15 = Frame::get_vector_heading(&offset_frame, &result);
      v16 = distance * v15->x;
      v17 = distance * v15->y;
      v37 = distance * v15->z;
      offset.z = v37;
      offset.x = v16;
      offset.y = v17;
      v18 = CTransition::adjust_offset(v1, &v39, &offset);
      *(_DWORD *)v12 = LODWORD(v18->x);
      v1->sphere_path.global_offset.y = v18->y;
      v1->sphere_path.global_offset.z = v18->z;
      v19 = v1->sphere_path.global_offset.z;
      if ( v21 | v22 )
      {
        *((_DWORD *)v3 + 141) = 0;
        *((float *)v3 + 82) = *((float *)v3 + 82) + *(float *)v12;
        *((float *)v3 + 83) = v1->sphere_path.global_offset.y + *((float *)v3 + 83);
        *((float *)v3 + 84) = v1->sphere_path.global_offset.z + *((float *)v3 + 84);
        SPHEREPATH::cache_global_sphere((SPHEREPATH *)v3, &v1->sphere_path.global_offset);
        v1->collision_info.sliding_normal_valid = 0;
        v1->collision_info.contact_plane_valid = 0;
        v1->collision_info.contact_plane_is_water = 0;
        v23 = CTransition::transitional_insert(v1, 3);
        if ( CTransition::validate_placement_transition(v1, (TransitionState)v23, &redo) == 1 )
          break;
      }
      ++ja;
      if ( ja >= num_rad )
        goto LABEL_17;
    }
  }
  return 1;
}

//----- (0050BDF0) --------------------------------------------------------  // acclient.c:313170
int __thiscall CTransition::find_transitional_position(CTransition *this)
{
  CTransition *v1; // esi@1
  int v2; // eax@2
  CObjCell *v3; // ebx@5
  unsigned int v4; // ebx@5
  unsigned int v5; // ecx@5
  int v6; // ebp@7
  int v7; // ecx@10
  long double v8; // st7@11
  double v9; // st6@12
  long double v10; // st7@12
  AC1Legacy::Vector3 *v11; // eax@13
  int v12; // ecx@13
  double v13; // st7@14
  unsigned __int8 v15; // c0@14
  unsigned __int8 v16; // c3@14
  float t; // ST0C_4@16
  signed int v18; // eax@18
  signed int v19; // eax@21
  unsigned int num_steps; // [sp+14h] [bp-48h]@3
  TransitionState ts; // [sp+18h] [bp-44h]@3
  int redo; // [sp+1Ch] [bp-40h]@12
  AC1Legacy::Vector3 offset; // [sp+20h] [bp-3Ch]@3
  float v24; // [sp+2Ch] [bp-30h]@12
  float v25; // [sp+30h] [bp-2Ch]@12
  float v26; // [sp+34h] [bp-28h]@12
  AC1Legacy::Vector3 offset_per_step; // [sp+38h] [bp-24h]@3
  float v28; // [sp+4Ch] [bp-10h]@12
  AC1Legacy::Vector3 result; // [sp+50h] [bp-Ch]@13

  v1 = this;
  if ( this->sphere_path.begin_cell )
  {
    ts = 1;
    num_steps = 0;
    CTransition::calc_num_steps(this, &offset, &offset_per_step, &num_steps);
    if ( v1->object_info.state & 0x10 )
      Frame::set_rotate(
        &v1->sphere_path.curr_pos.frame,
        v1->sphere_path.end_pos->frame.qw,
        v1->sphere_path.end_pos->frame.qx,
        v1->sphere_path.end_pos->frame.qy,
        v1->sphere_path.end_pos->frame.qz);
    v3 = v1->sphere_path.curr_cell;
    v1->sphere_path.check_pos.objcell_id = v1->sphere_path.curr_pos.objcell_id;
    Frame::operator=((int)&v1->sphere_path.check_pos.frame, (int)&v1->sphere_path.curr_pos.frame);
    v1->sphere_path.check_cell = v3;
    v4 = 0;
    v1->sphere_path.cell_array_valid = 0;
    SPHEREPATH::cache_global_sphere(&v1->sphere_path, 0);
    v5 = num_steps;
    if ( num_steps <= 0 )
    {
      if ( !(v1->object_info.state & 0x10) )
        Frame::set_rotate(
          &v1->sphere_path.curr_pos.frame,
          v1->sphere_path.end_pos->frame.qw,
          v1->sphere_path.end_pos->frame.qx,
          v1->sphere_path.end_pos->frame.qy,
          v1->sphere_path.end_pos->frame.qz);
      SPHEREPATH::set_check_pos(&v1->sphere_path, &v1->sphere_path.curr_pos, v1->sphere_path.curr_cell);
      v1->sphere_path.cell_array_valid = 1;
      v1->sphere_path.hits_interior_cell = 0;
      CObjCell::find_cell_list(&v1->cell_array, 0, &v1->sphere_path);
      v2 = 1;
    }
    else if ( num_steps )
    {
      v6 = (int)&v1->sphere_path.global_offset;
      while ( 1 )
      {
        if ( v1->object_info.state & 4 )
        {
          v7 = v5 - 1;
          if ( v4 == v7 )
          {
            v8 = sqrt(offset.z * offset.z + offset.y * offset.y + offset.x * offset.x);
            if ( v8 > 0.00019999999 )
            {
              v9 = v1->sphere_path.local_sphere->radius;
              redo = v7;
              v10 = (v8 - v9 * (double)(unsigned int)v7) / v8;
              v28 = offset.z * v10;
              v26 = v28;
              v24 = offset.x * v10;
              offset_per_step.x = v24;
              v25 = offset.y * v10;
              offset_per_step.y = v25;
              offset_per_step.z = v28;
            }
          }
        }
        v11 = CTransition::adjust_offset(v1, &result, &offset_per_step);
        *(_DWORD *)v6 = LODWORD(v11->x);
        v1->sphere_path.global_offset.y = v11->y;
        v1->sphere_path.global_offset.z = v11->z;
        v12 = v1->object_info.state;
        if ( !(v12 & 4) )
        {
          v13 = v1->sphere_path.global_offset.z;
          if ( !(v15 | v16) )
            break;
        }
        if ( !(v12 & 0x10) )
        {
          redo = v4 + 1;
          t = (double)(v4 + 1) / (double)num_steps;
          Frame::interpolate_rotation(
            &v1->sphere_path.check_pos.frame,
            &v1->sphere_path.begin_pos->frame,
            &v1->sphere_path.end_pos->frame,
            t);
        }
        v1->collision_info.sliding_normal_valid = 0;
        v1->collision_info.contact_plane_valid = 0;
        v1->collision_info.contact_plane_is_water = 0;
        if ( v1->sphere_path.insert_type )
        {
          v19 = CTransition::transitional_insert(v1, 3);
          ts = CTransition::validate_placement_transition(v1, (TransitionState)v19, &redo);
          if ( ts == 1 )
            goto LABEL_20;
          if ( !v1->sphere_path.placement_allows_sliding )
            goto LABEL_29;
          SPHEREPATH::add_offset_to_check_pos(&v1->sphere_path, &v1->sphere_path.global_offset);
        }
        else
        {
          v1->sphere_path.cell_array_valid = 0;
          v1->sphere_path.check_pos.frame.m_fOrigin.x = *(float *)v6 + v1->sphere_path.check_pos.frame.m_fOrigin.x;
          v1->sphere_path.check_pos.frame.m_fOrigin.y = v1->sphere_path.global_offset.y
                                                      + v1->sphere_path.check_pos.frame.m_fOrigin.y;
          v1->sphere_path.check_pos.frame.m_fOrigin.z = v1->sphere_path.global_offset.z
                                                      + v1->sphere_path.check_pos.frame.m_fOrigin.z;
          SPHEREPATH::cache_global_sphere(&v1->sphere_path, &v1->sphere_path.global_offset);
          v18 = CTransition::transitional_insert(v1, 3);
          ts = CTransition::validate_transition(v1, (TransitionState)v18, &redo);
          if ( v1->collision_info.frames_stationary_fall )
            goto LABEL_19;
        }
        if ( v1->collision_info.collision_normal_valid && v1->object_info.state & 8 )
          goto LABEL_19;
        ++v4;
        if ( v4 >= num_steps )
          goto LABEL_19;
        v5 = num_steps;
      }
      if ( !v4 )
        goto LABEL_29;
LABEL_19:
      if ( ts == 1 )
        goto LABEL_20;
LABEL_29:
      v2 = 0;
    }
    else
    {
LABEL_20:
      v2 = 1;
    }
  }
  else
  {
    v2 = 0;
  }
  return v2;
}

//----- (0050C170) --------------------------------------------------------  // acclient.c:313340
int __thiscall CTransition::find_placement_position(CTransition *this)
{
  CTransition *v1; // esi@1
  CObjCell *v2; // ebx@1
  char *v3; // edi@1
  CObjCell *v4; // eax@1
  int v5; // eax@2
  CSphere *v7; // ecx@10
  int v8; // eax@14
  float step_down_ht; // [sp+10h] [bp-8h]@9
  float step_down_hta; // [sp+10h] [bp-8h]@13

  v1 = this;
  v2 = this->sphere_path.curr_cell;
  v3 = (char *)&this->sphere_path;
  this->sphere_path.check_pos.objcell_id = this->sphere_path.curr_pos.objcell_id;
  Frame::operator=((int)&this->sphere_path.check_pos.frame, (int)&this->sphere_path.curr_pos.frame);
  *((_DWORD *)v3 + 66) = v2;
  *((_DWORD *)v3 + 141) = 0;
  SPHEREPATH::cache_global_sphere((SPHEREPATH *)v3, 0);
  v4 = v1->sphere_path.check_cell;
  v1->sphere_path.insert_type = 2;
  if ( v4 )
  {
    v5 = CTransition::insert_into_cell(v1, v4, 3);
    if ( v5 == 1 )
      v5 = CTransition::check_other_cells(v1, v1->sphere_path.check_cell);
  }
  else
  {
    v5 = 2;
  }
  if ( CTransition::validate_placement(v1, (TransitionState)v5, 1) != 1 )
    return 0;
  v1->sphere_path.insert_type = 1;
  if ( !CTransition::find_placement_pos(v1) )
    return 0;
  if ( v1->object_info.step_down )
  {
    step_down_ht = v1->object_info.step_down_height;
    v1->sphere_path.walkable_allowance = z_for_landing;
    SPHEREPATH::save_check_pos((SPHEREPATH *)v3);
    *((_DWORD *)v3 + 87) = *((_DWORD *)v3 + 85);
    *((_DWORD *)v3 + 85) = 0;
    if ( *(_DWORD *)v3 < 2u )
    {
      v7 = v1->sphere_path.global_sphere;
      if ( v7->radius + v7->radius < step_down_ht )
        step_down_ht = v7->radius * 0.5;
    }
    if ( v1->sphere_path.global_sphere->radius + v1->sphere_path.global_sphere->radius >= step_down_ht )
    {
      v8 = CTransition::step_down(v1, step_down_ht, 0.0871557);
    }
    else
    {
      step_down_hta = step_down_ht * 0.5;
      if ( CTransition::step_down(v1, step_down_hta, 0.0871557) )
      {
LABEL_18:
        *((_DWORD *)v3 + 85) = *((_DWORD *)v3 + 87);
        v1->sphere_path.walkable = 0;
        return CTransition::validate_placement(v1, OK_TS, 1) == 1;
      }
      v8 = CTransition::step_down(v1, step_down_hta, 0.0871557);
    }
    if ( !v8 )
    {
      SPHEREPATH::restore_check_pos((SPHEREPATH *)v3);
      v1->collision_info.contact_plane_valid = 0;
      v1->collision_info.contact_plane_is_water = 0;
    }
    goto LABEL_18;
  }
  return CTransition::validate_placement(v1, OK_TS, 1) == 1;
}

//----- (0050C310) --------------------------------------------------------  // acclient.c:313418
int __thiscall CTransition::find_valid_position(CTransition *this)
{
  int result; // eax@2

  if ( this->sphere_path.insert_type )
    result = CTransition::find_placement_position(this);
  else
    result = CTransition::find_transitional_position(this);
  return result;
}

//----- (006FB360) --------------------------------------------------------  // acclient.c:783751
void sub_6FB360()
{
  flt_841C78 = 1000.0 + 1.0;
}

//----- (006FB380) --------------------------------------------------------  // acclient.c:783757
void sub_6FB380()
{
  flt_841C7C = 24.0 * 8.0;
}

//----- (006FB3A0) --------------------------------------------------------  // acclient.c:783763
void sub_6FB3A0()
{
  flt_841C80 = 24.0 * 0.5;
}

//----- (006FB3C0) --------------------------------------------------------  // acclient.c:783769
void sub_6FB3C0()
{
  DEFAULT_VIEW_RADIUS_94 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FB3E0) --------------------------------------------------------  // acclient.c:783775
void _E99_11()
{
  MIN_QUANTUM_94 = 1.0 / 30.0;
}

//----- (006FB400) --------------------------------------------------------  // acclient.c:783781
void _E101_7()
{
  MAX_QUANTUM_94 = 1.0 / 5.0;
}

//----- (006FB420) --------------------------------------------------------  // acclient.c:783787
int _E107_10()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_2;
  INITIAL_MAX_DATA_RATE_67 = LOWEST_DATA_RATE_2;
  return result;
}

//----- (006FB430) --------------------------------------------------------  // acclient.c:783797
int sub_6FB430()
{
  return atexit(nullsub_1078);
}

//----- (00766A10) --------------------------------------------------------  // acclient.c:893362
void __cdecl sub_766A10()
{
  PStringBase<char> *v0; // esi@1
  signed int v1; // ebp@1
  void *v2; // eax@2
  void *v3; // edi@3

  v0 = &Render_DegradeDistance_23;
  v1 = 10;
  do
  {
    v2 = v0[-187].m_charbuffer;
    v0 -= 197;
    if ( v2 )
    {
      v3 = (char *)v2 - 4;
      vector_destructor_iterator(
        v2,
        8u,
        *((_DWORD *)v2 - 1),
        (void (__thiscall *)(void *))gmNoticeHandler::RecvNotice_PrevSpellSelection);
      operator delete[](v3);
    }
    v0[10].m_charbuffer = 0;
    operator delete[](v0->m_charbuffer);
    v0->m_charbuffer = 0;
    SPHEREPATH::~SPHEREPATH((SPHEREPATH *)&v0[-174]);
    --v1;
  }
  while ( v1 );
}

