/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSphere
   Object     : PORTAL\cgeometry\CSphere.obj
   Functions  : 25
   Addresses  : 005368D0 - 00700120 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005368D0) --------------------------------------------------------  // acclient.c:358474
BOOL __thiscall SPHEREPATH::is_walkable_allowable(SPHEREPATH *this, float zval)
{
  return zval > (double)this->walkable_allowance;
}

//----- (005368F0) --------------------------------------------------------  // acclient.c:358480
double __stdcall CSphere::find_time_of_collision(AC1Legacy::Vector3 *movement, AC1Legacy::Vector3 *disp, const float radsum)
{
  double v4; // st7@1
  double v5; // st6@1
  double v6; // st2@1
  long double v7; // st5@2
  long double v8; // st5@4
  double result; // st7@5

  v4 = movement->x * movement->x + movement->y * movement->y + movement->z * movement->z;
  v5 = -(disp->z * movement->z + disp->y * movement->y + movement->x * disp->x);
  v6 = disp->x * disp->x + disp->y * disp->y + disp->z * disp->z - radsum * radsum;
  if ( v6 < 0.00019999999 || (v7 = v5 * v5 - v6 * v4, v4 < 0.00019999999) || v7 < 0.0 )
  {
    result = -1.0;
  }
  else
  {
    v8 = sqrt(v7);
    if ( v5 - v8 < 0.0 )
      result = (v8 - (disp->z * movement->z + disp->y * movement->y + movement->x * disp->x)) / v4;
    else
      result = (v5 - v8) / v4;
  }
  return result;
}

//----- (005369E0) --------------------------------------------------------  // acclient.c:358508
BOOL __stdcall CSphere::collides_with_sphere(AC1Legacy::Vector3 *disp, const float radsum)
{
  double v3; // st7@1
  char v5; // c0@1

  v3 = disp->z;
  return v5 == 0;
}

//----- (00536A20) --------------------------------------------------------  // acclient.c:358518
void __thiscall Plane::Plane(Plane *this, AC1Legacy::Vector3 *normal, AC1Legacy::Vector3 *point)
{
  this->N = *normal;
  this->d = -(point->z * this->N.z + point->y * this->N.y + point->x * this->N.x);
}

//----- (00536A60) --------------------------------------------------------  // acclient.c:358525
void __thiscall SPHEREPATH::add_offset_to_check_pos(SPHEREPATH *this, AC1Legacy::Vector3 *offset, const float radius)
{
  this->cell_array_valid = 0;
  this->check_pos.frame.m_fOrigin.x = this->check_pos.frame.m_fOrigin.x + offset->x;
  this->check_pos.frame.m_fOrigin.y = offset->y + this->check_pos.frame.m_fOrigin.y;
  this->check_pos.frame.m_fOrigin.z = offset->z + this->check_pos.frame.m_fOrigin.z;
  SPHEREPATH::cache_global_sphere(this, offset);
}

//----- (00536AB0) --------------------------------------------------------  // acclient.c:358535
int __cdecl CSphere::attack(Position *target_pos, const float target_radius, const float target_height, Position *attack_pos, Vec2D *left, Vec2D *right, const float attackrad, const float attackht)
{
  double v8; // st7@3
  double v9; // st5@3
  float temp; // ST18_4@22
  signed int v12; // ecx@6
  int v13; // ecx@9
  int v14; // ecx@12
  float right_dist; // [sp+8h] [bp-2Ch]@16
  AC1Legacy::Vector3 center; // [sp+10h] [bp-24h]@1
  AC1Legacy::Vector3 v; // [sp+1Ch] [bp-18h]@1
  AC1Legacy::Vector3 hitpoint; // [sp+28h] [bp-Ch]@6
  float attackhta; // [sp+54h] [bp+20h]@16

  LODWORD(v.x) = 0;
  LODWORD(v.y) = 0;
  LODWORD(v.z) = 0;
  Position::localtolocal(attack_pos, &center, target_pos, &v);
  if ( attackht < 0.0 || attackht > (double)target_height )
    return 0;
  v8 = target_radius + attackrad;
  v9 = center.y * center.y + center.x * center.x;
  if ( v9 > v8 * v8 )
    return 0;
  if ( fabs(center.z) > v8 )
    return 0;
  LODWORD(v.x) = 0;
  LODWORD(v.y) = 0;
  LODWORD(v.z) = 0;
  Position::localtolocal(target_pos, &hitpoint, attack_pos, &v);
  v12 = 8;
  if ( hitpoint.x >= 0.0 )
    v12 = 16;
  if ( hitpoint.y >= 0.0 )
    v13 = v12 | 0x20;
  else
    v13 = v12 | 0x40;
  if ( target_height * 0.333333 <= attackht )
  {
    if ( target_height * 0.666667 <= attackht )
      v14 = v13 | 1;
    else
      v14 = v13 | 2;
  }
  else
  {
    v14 = v13 | 4;
  }
  attackhta = center.y * left->x - center.x * left->y;
  right_dist = center.x * right->y - center.y * right->x;
  if ( attackhta <= 0.0 && right_dist <= 0.0 )
    return v14;
  if ( left->x * right->y - left->y * right->x >= 0.0 )
  {
    if ( right_dist * attackhta <= 0.0 || attackhta <= (double)target_radius )
      return v14;
    goto LABEL_29;
  }
  if ( attackhta < 0.0 )
    goto LABEL_29;
  if ( right_dist >= 0.0 )
  {
    temp = v9;
    if ( target_radius * target_radius >= temp )
      return v14;
    return 0;
  }
  if ( attackhta < 0.0 )
  {
LABEL_29:
    if ( right_dist > (double)target_radius )
      return 0;
    return v14;
  }
  if ( attackhta <= (double)target_radius )
    return v14;
  return 0;
}

//----- (00536D20) --------------------------------------------------------  // acclient.c:358615
signed int __thiscall CSphere::step_sphere_down(CSphere *this, OBJECTINFO *object, SPHEREPATH *path, COLLISIONINFO *collisions, CSphere *check_pos, AC1Legacy::Vector3 *disp, float radsum)
{
  AC1Legacy::Vector3 *v7; // esi@1
  CSphere *v8; // ebx@1
  CSphere *v9; // eax@3
  double v10; // st7@3
  long double v11; // st7@4
  double v12; // st7@5
  long double v13; // st7@5
  double v14; // st6@5
  double v15; // st7@7
  double v16; // st6@7
  double v17; // st7@7
  signed int v18; // eax@8
  Vector3 *v19; // eax@9
  Vector3 *v20; // eax@9
  float v21; // ecx@9
  float v22; // edx@9
  float v23; // edx@9
  float v24; // [sp+Ch] [bp-34h]@1
  float timecheck; // [sp+10h] [bp-30h]@1
  double timechecka; // [sp+10h] [bp-30h]@5
  AC1Legacy::Vector3 disp2; // [sp+18h] [bp-28h]@3
  Vector3 result; // [sp+24h] [bp-1Ch]@9
  Plane rest_plane; // [sp+30h] [bp-10h]@9
  float dispa; // [sp+54h] [bp+14h]@4
  float dispb; // [sp+54h] [bp+14h]@7
  float pathz; // [sp+58h] [bp+18h]@5

  v7 = disp;
  v8 = this;
  timecheck = disp->y * disp->y;
  v24 = disp->x * disp->x;
  if ( radsum * radsum < disp->z * disp->z + v24 + timecheck )
  {
    if ( path->num_sphere <= 1 )
      return 1;
    v9 = path->global_sphere;
    v10 = v9[1].center.x;
    ++v9;
    disp2.x = v10 - this->center.x;
    disp2.y = v9->center.y - this->center.y;
    disp2.z = v9->center.z - this->center.z;
    if ( !CSphere::collides_with_sphere(&disp2, radsum) )
      return 1;
  }
  v11 = path->step_down_amt * path->walk_interp;
  dispa = v11;
  if ( fabs(v11) < 0.00019999999
    || (v12 = radsum + 0.00019999999,
        pathz = v12,
        v13 = (sqrt(v12 * pathz - (v24 + timecheck)) - v7->z) / dispa,
        v14 = (1.0 - v13) * path->walk_interp,
        timechecka = v14,
        v14 >= path->walk_interp)
    || v14 < -0.1 )
  {
    v18 = 2;
  }
  else
  {
    dispb = dispa * v13;
    v15 = dispb + v7->z;
    v7->z = v15;
    v16 = 1.0 / pathz;
    v7->x = v16 * v7->x;
    v7->y = v16 * v7->y;
    v17 = v15 * v16;
    v7->z = v17;
    if ( v17 <= path->walkable_allowance )
      return 1;
    v19 = operator*(&result, v8->radius, (Vector3 *)&v7->x);
    v20 = Vector3::operator+((Vector3 *)&v8->center.x, (Vector3 *)&rest_plane.N.x, v19);
    v21 = v20->y;
    disp2.x = v20->x;
    v22 = v20->z;
    disp2.y = v21;
    disp2.z = v22;
    Plane::Plane(&rest_plane, v7, &disp2);
    COLLISIONINFO::set_contact_plane(collisions, &rest_plane, 1);
    collisions->contact_plane_cell_id = path->check_pos.objcell_id;
    path->walk_interp = timechecka;
    v23 = check_pos->radius;
    disp2.z = dispb;
    LODWORD(disp2.x) = 0;
    LODWORD(disp2.y) = 0;
    SPHEREPATH::add_offset_to_check_pos(path, &disp2, v23);
    v18 = 3;
  }
  return v18;
}

//----- (00536F40) --------------------------------------------------------  // acclient.c:358708
signed int __thiscall CSphere::slide_sphere(CSphere *this, OBJECTINFO *object, SPHEREPATH *path, COLLISIONINFO *collisions, AC1Legacy::Vector3 *disp, float radsum, int sphere_num)
{
  CSphere *v7; // esi@1
  AC1Legacy::Vector3 *v8; // edi@1
  char *v9; // ebp@3
  float v10; // ecx@5
  float v11; // edx@5
  double v12; // st6@5
  unsigned int v13; // edx@5
  unsigned int v14; // ST08_4@5
  double v15; // st7@5
  double v16; // st6@5
  double v17; // st7@5
  double v18; // st6@8
  double v19; // st7@8
  unsigned __int8 v21; // c0@8
  unsigned __int8 v22; // c2@8
  AC1Legacy::Vector3 collision_normal; // [sp+Ch] [bp-48h]@1
  AC1Legacy::Vector3 skid_dir; // [sp+18h] [bp-3Ch]@5
  AC1Legacy::Vector3 direction; // [sp+24h] [bp-30h]@5
  float v27; // [sp+30h] [bp-24h]@5
  float v28; // [sp+34h] [bp-20h]@5
  float v29; // [sp+38h] [bp-1Ch]@5
  AC1Legacy::Vector3 result; // [sp+3Ch] [bp-18h]@5
  float v31; // [sp+50h] [bp-4h]@5
  int sphere_numa; // [sp+6Ch] [bp+18h]@7

  v7 = &path->global_sphere[sphere_num];
  v8 = &path->global_curr_center[sphere_num];
  collision_normal.x = v8->x - this->center.x;
  collision_normal.y = v8->y - this->center.y;
  collision_normal.z = v8->z - this->center.z;
  if ( AC1Legacy::Vector3::normalize_check_small(&collision_normal) )
    return 2;
  COLLISIONINFO::set_collision_normal(collisions, &collision_normal);
  if ( collisions->contact_plane_valid )
    v9 = (char *)&collisions->contact_plane;
  else
    v9 = (char *)&collisions->last_known_contact_plane;
  v10 = *(float *)v9;
  v11 = *((float *)v9 + 1);
  LODWORD(skid_dir.z) = *((_DWORD *)v9 + 2);
  skid_dir.y = v11;
  v12 = v11;
  v13 = path->curr_pos.objcell_id;
  skid_dir.x = v10;
  v14 = path->check_pos.objcell_id;
  direction.x = skid_dir.z * collision_normal.y - v12 * collision_normal.z;
  direction.y = collision_normal.z * v10 - skid_dir.z * collision_normal.x;
  direction.z = skid_dir.y * collision_normal.x - collision_normal.y * v10;
  LandDefs::get_block_offset(&result, v13, v14);
  v15 = v7->center.x - v8->x;
  v16 = v7->center.y - v8->y;
  v31 = v7->center.z - v8->z;
  v27 = result.x + v15;
  v28 = result.y + v16;
  v29 = result.z + v31;
  v17 = direction.z * direction.z + direction.y * direction.y + direction.x * direction.x;
  if ( v17 >= 0.00019999999 )
  {
    v18 = v29 * direction.z + v28 * direction.y + v27 * direction.x;
    skid_dir.x = direction.x * v18;
    skid_dir.y = direction.y * v18;
    skid_dir.z = direction.z * v18;
    v19 = 1.0 / v17;
    collision_normal.x = skid_dir.x * v19;
    LODWORD(skid_dir.x) = (_DWORD)collision_normal.x;
    LODWORD(direction.x) = (_DWORD)collision_normal.x;
    skid_dir.y = skid_dir.y * v19;
    direction.y = skid_dir.y;
    skid_dir.z = skid_dir.z * v19;
    direction.z = skid_dir.z;
    if ( !(v21 | v22) )
    {
      direction.x = collision_normal.x - v27;
      direction.y = direction.y - v28;
      direction.z = direction.z - v29;
      goto LABEL_11;
    }
    return 2;
  }
  if ( skid_dir.z * disp->z + skid_dir.y * disp->y + skid_dir.x * disp->x < 0.0 )
    return 2;
  result.y = -collision_normal.y;
  result.z = -collision_normal.z;
  *(float *)&sphere_numa = v29 * collision_normal.z + v28 * collision_normal.y + v27 * collision_normal.x;
  v31 = result.z * *(float *)&sphere_numa;
  v29 = v31;
  v27 = -collision_normal.x * *(float *)&sphere_numa;
  direction.x = v27;
  v28 = result.y * *(float *)&sphere_numa;
  direction.y = v28;
  direction.z = v31;
LABEL_11:
  SPHEREPATH::add_offset_to_check_pos(path, &direction, v7->radius);
  return 4;
}

//----- (00537230) --------------------------------------------------------  // acclient.c:358807
signed int __thiscall CSphere::collide_with_point(CSphere *this, OBJECTINFO *object, SPHEREPATH *path, COLLISIONINFO *collisions, CSphere *check_pos, AC1Legacy::Vector3 *disp, float radsum, int sphere_num)
{
  CSphere *v8; // esi@1
  AC1Legacy::Vector3 *v9; // edi@1
  signed int result; // eax@4
  unsigned int v11; // ecx@5
  unsigned int v12; // edx@5
  double v13; // st7@5
  double v14; // st6@5
  double v15; // st5@5
  double v16; // st6@5
  double v17; // st7@5
  double v18; // st7@7
  double v19; // st5@7
  double v20; // st4@7
  double v21; // st7@7
  double v22; // st6@7
  double v23; // st7@7
  double v24; // st6@7
  AC1Legacy::Vector3 offset; // [sp+Ch] [bp-30h]@2
  AC1Legacy::Vector3 collision_normal; // [sp+18h] [bp-24h]@5
  AC1Legacy::Vector3 old_disp; // [sp+24h] [bp-18h]@5
  float v28; // [sp+38h] [bp-4h]@5
  float radsuma; // [sp+54h] [bp+18h]@5

  v8 = this;
  v9 = &path->global_curr_center[sphere_num];
  if ( object->state & 0x40 )
  {
    v11 = path->check_pos.objcell_id;
    v12 = path->curr_pos.objcell_id;
    radsuma = radsum + 0.00019999999;
    old_disp.x = v9->x - v8->center.x;
    old_disp.y = v9->y - v8->center.y;
    old_disp.z = v9->z - v8->center.z;
    LandDefs::get_block_offset(&collision_normal, v12, v11);
    v13 = check_pos->center.x - v9->x;
    v14 = check_pos->center.y - v9->y;
    v28 = check_pos->center.z - v9->z;
    offset.x = collision_normal.x + v13;
    LODWORD(collision_normal.x) = (_DWORD)offset.x;
    v15 = collision_normal.y + v14;
    offset.y = v15;
    v16 = collision_normal.z + v28;
    offset.z = v16;
    collision_normal.y = v15;
    collision_normal.z = v16;
    v17 = CSphere::find_time_of_collision(&collision_normal, &old_disp, radsuma);
    if ( v17 < 0.00019999999 || v17 > 1.0 )
    {
      result = 2;
    }
    else
    {
      old_disp.y = offset.y * v17;
      old_disp.z = offset.z * v17;
      v18 = offset.x * v17 - offset.x;
      v19 = old_disp.z - offset.z;
      v28 = v19;
      offset.x = v18;
      v20 = old_disp.y - offset.y;
      offset.y = v20;
      offset.z = v19;
      old_disp.x = v18 + check_pos->center.x;
      v21 = v20 + check_pos->center.y;
      v22 = v28 + check_pos->center.z;
      old_disp.x = old_disp.x - v8->center.x;
      old_disp.y = v21 - v8->center.y;
      v23 = v22 - v8->center.z;
      v24 = 1.0 / radsuma;
      collision_normal.x = old_disp.x * v24;
      collision_normal.y = old_disp.y * v24;
      collision_normal.z = v23 * v24;
      COLLISIONINFO::set_collision_normal(collisions, &collision_normal);
      SPHEREPATH::add_offset_to_check_pos(path, &offset, check_pos->radius);
      result = 3;
    }
  }
  else
  {
    offset.x = v9->x - this->center.x;
    offset.y = v9->y - this->center.y;
    offset.z = v9->z - this->center.z;
    if ( !AC1Legacy::Vector3::normalize_check_small(&offset) )
      COLLISIONINFO::set_collision_normal(collisions, &offset);
    result = 2;
  }
  return result;
}

//----- (00537440) --------------------------------------------------------  // acclient.c:358898
signed int __thiscall CSphere::slide_sphere(CSphere *this, SPHEREPATH *path, COLLISIONINFO *collisions, AC1Legacy::Vector3 *collision_normal, AC1Legacy::Vector3 *curr_pos)
{
  CSphere *v5; // edi@1
  double v6; // st7@4
  float v7; // ST10_4@4
  SPHEREPATH *v9; // ebp@5
  double v10; // st7@5
  char *v11; // ecx@5
  double v12; // st6@5
  int v13; // eax@5
  double v14; // st7@7
  double v15; // st6@7
  double v16; // st6@7
  double v17; // st7@12
  const float v18; // eax@12
  double v19; // st6@13
  double v20; // st5@13
  double v21; // st7@13
  const float v22; // ST08_4@15
  float v23; // [sp+8h] [bp-24h]@5
  float v24; // [sp+Ch] [bp-20h]@5
  float v25; // [sp+10h] [bp-1Ch]@5
  AC1Legacy::Vector3 direction; // [sp+14h] [bp-18h]@4
  AC1Legacy::Vector3 offset; // [sp+20h] [bp-Ch]@4
  float patha; // [sp+30h] [bp+4h]@7
  SPHEREPATH *pathb; // [sp+30h] [bp+4h]@12
  SPHEREPATH *pathc; // [sp+30h] [bp+4h]@13

  v5 = this;
  if ( collision_normal->x == 0.0 && collision_normal->y == 0.0 && collision_normal->z == 0.0 )
  {
    v6 = curr_pos->x - this->center.x;
    v7 = this->radius;
    offset.y = curr_pos->y - this->center.y;
    offset.z = curr_pos->z - this->center.z;
    offset.z = offset.z * 0.5;
    direction.z = offset.z;
    direction.x = v6 * 0.5;
    direction.y = offset.y * 0.5;
    SPHEREPATH::add_offset_to_check_pos(path, &direction, v7);
    return 3;
  }
  COLLISIONINFO::set_collision_normal(collisions, collision_normal);
  v9 = path;
  LandDefs::get_block_offset(&offset, path->curr_pos.objcell_id, path->check_pos.objcell_id);
  v10 = v5->center.x - curr_pos->x;
  v11 = (char *)&collisions->contact_plane;
  v12 = v5->center.y - curr_pos->y;
  v13 = collisions->contact_plane_valid;
  direction.z = v5->center.z - curr_pos->z;
  v23 = offset.x + v10;
  v24 = offset.y + v12;
  v25 = offset.z + direction.z;
  if ( !v13 )
    v11 = (char *)&collisions->last_known_contact_plane;
  direction.x = collision_normal->y * *((float *)v11 + 2) - collision_normal->z * *((float *)v11 + 1);
  v14 = *(float *)v11 * collision_normal->z - *((float *)v11 + 2) * collision_normal->x;
  v15 = *((float *)v11 + 1) * collision_normal->x - *(float *)v11 * collision_normal->y;
  direction.z = v15;
  v16 = v15 * direction.z + v14 * v14 + direction.x * direction.x;
  patha = v16;
  if ( v16 >= 0.00019999999 )
  {
    v19 = direction.z * v25 + v14 * v24 + direction.x * v23;
    offset.y = v14 * v19;
    offset.z = direction.z * v19;
    v20 = 1.0 / patha;
    *(float *)&pathc = v20;
    v21 = direction.x * v19 * v20;
    direction.y = offset.y * *(float *)&pathc;
    offset.y = direction.y;
    direction.z = offset.z * *(float *)&pathc;
    offset.z = direction.z;
    offset.x = v21;
    if ( direction.z * direction.z + direction.y * direction.y + v21 * v21 < 0.00019999999 )
      return 2;
    v22 = v5->radius;
    offset.x = v21 - v23;
    offset.y = direction.y - v24;
    offset.z = direction.z - v25;
    SPHEREPATH::add_offset_to_check_pos(v9, &offset, v22);
    return 4;
  }
  if ( collision_normal->z * *((float *)v11 + 2)
     + collision_normal->y * *((float *)v11 + 1)
     + *(float *)v11 * collision_normal->x >= 0.0 )
  {
    v17 = -collision_normal->x;
    offset.y = -collision_normal->y;
    offset.z = -collision_normal->z;
    *(float *)&pathb = v23 * collision_normal->x + v25 * collision_normal->z + v24 * collision_normal->y;
    direction.z = offset.z * *(float *)&pathb;
    offset.z = direction.z;
    offset.x = v17 * *(float *)&pathb;
    LODWORD(direction.x) = (_DWORD)offset.x;
    v18 = v5->radius;
    offset.y = offset.y * *(float *)&pathb;
    direction.y = offset.y;
    SPHEREPATH::add_offset_to_check_pos(v9, &direction, v18);
    return 4;
  }
  offset.x = -v23;
  COERCE_AC1LEGACY__VECTOR3(collision_normal->x) = offset;
  offset.y = -v24;
  offset.z = -v25;
  if ( !AC1Legacy::Vector3::normalize_check_small(collision_normal) )
    COLLISIONINFO::set_collision_normal(collisions, collision_normal);
  return 2;
}

//----- (005377A0) --------------------------------------------------------  // acclient.c:359009
char __thiscall CSphere::sphere_intersects_ray(CSphere *this, Ray *ray, long double *o_fTimeOfIntersection)
{
  double v3; // st7@1
  long double v4; // st6@1
  double v5; // st4@1
  long double v6; // st5@2
  long double v7; // st5@4
  char result; // al@5
  float v9; // [sp+0h] [bp-Ch]@1
  float v10; // [sp+4h] [bp-8h]@1
  float v11; // [sp+8h] [bp-4h]@1

  v9 = ray->pt.x - this->center.x;
  v10 = ray->pt.y - this->center.y;
  v11 = ray->pt.z - this->center.z;
  v3 = ray->dir.z * ray->dir.z + ray->dir.y * ray->dir.y + ray->dir.x * ray->dir.x;
  v4 = -(v11 * ray->dir.z + v10 * ray->dir.y + v9 * ray->dir.x);
  v5 = v9 * v9 + v11 * v11 + v10 * v10 - this->radius * this->radius;
  if ( v5 <= 0.0 || (v6 = v4 * v4 - v5 * v3, v3 < 0.00019999999) || v6 < 0.0 )
  {
    result = 0;
  }
  else
  {
    v7 = sqrt(v6);
    if ( v4 <= v7 )
    {
      result = 1;
      *o_fTimeOfIntersection = (v7 - (v11 * ray->dir.z + v10 * ray->dir.y + v9 * ray->dir.x)) / v3;
    }
    else
    {
      *o_fTimeOfIntersection = (v4 - v7) / v3;
      result = 1;
    }
  }
  return result;
}

//----- (005378A0) --------------------------------------------------------  // acclient.c:359049
void __thiscall SPHEREPATH::set_collide(SPHEREPATH *this, AC1Legacy::Vector3 *collision_normal)
{
  SPHEREPATH *v2; // esi@1
  CObjCell *v3; // eax@1
  int v4; // eax@1
  float v5; // ecx@1

  v2 = this;
  v3 = this->check_cell;
  this->collide = 1;
  this->backup_cell = v3;
  this->backup_check_pos.objcell_id = this->check_pos.objcell_id;
  Frame::operator=((int)&this->backup_check_pos.frame, (int)&this->check_pos.frame);
  v4 = (int)&v2->step_up_normal;
  *(_DWORD *)v4 = LODWORD(collision_normal->x);
  *(_DWORD *)(v4 + 4) = LODWORD(collision_normal->y);
  v5 = collision_normal->z;
  LODWORD(v2->walk_interp) = 1065353216;
  *(float *)(v4 + 8) = v5;
}

//----- (00537900) --------------------------------------------------------  // acclient.c:359071
signed int __thiscall CSphere::step_sphere_up(CSphere *this, CTransition *transition, CSphere *check_pos, AC1Legacy::Vector3 *disp, float radsum)
{
  double v5; // st7@1
  AC1Legacy::Vector3 *v6; // eax@2
  double v7; // st7@2
  double v8; // st6@2
  signed int result; // eax@3
  AC1Legacy::Vector3 collision_normal; // [sp+0h] [bp-Ch]@2
  float radsuma; // [sp+1Ch] [bp+10h]@5

  v5 = radsum + 0.00019999999;
  if ( transition->object_info.step_up_height < v5 - disp->z )
  {
    radsuma = v5;
    result = CSphere::slide_sphere(
               this,
               &transition->object_info,
               &transition->sphere_path,
               &transition->collision_info,
               disp,
               radsuma,
               0);
  }
  else
  {
    v6 = transition->sphere_path.global_curr_center;
    v7 = v6->z - this->center.z;
    v8 = v6->y - this->center.y;
    collision_normal.x = v6->x - this->center.x;
    collision_normal.y = v8;
    collision_normal.z = v7;
    if ( CTransition::step_up(transition, &collision_normal) )
      result = 1;
    else
      result = SPHEREPATH::step_up_slide(
                 &transition->sphere_path,
                 &transition->object_info,
                 &transition->collision_info);
  }
  return result;
}

//----- (005379A0) --------------------------------------------------------  // acclient.c:359114
signed int __thiscall CSphere::land_on_sphere(CSphere *this, OBJECTINFO *object, SPHEREPATH *path, COLLISIONINFO *collisions, CSphere *check_pos, AC1Legacy::Vector3 *disp, float radsum)
{
  AC1Legacy::Vector3 *v7; // eax@1
  signed int result; // eax@2
  AC1Legacy::Vector3 collision_normal; // [sp+4h] [bp-Ch]@1

  v7 = path->global_curr_center;
  collision_normal.x = v7->x - this->center.x;
  collision_normal.y = v7->y - this->center.y;
  collision_normal.z = v7->z - this->center.z;
  if ( AC1Legacy::Vector3::normalize_check_small(&collision_normal) )
  {
    result = 2;
  }
  else
  {
    SPHEREPATH::set_collide(path, &collision_normal);
    path->walkable_allowance = z_for_landing_0;
    result = 3;
  }
  return result;
}

//----- (00537A10) --------------------------------------------------------  // acclient.c:359138
signed int __thiscall CSphere::slide_sphere(CSphere *this, OBJECTINFO *object, SPHEREPATH *path, COLLISIONINFO *collisions, CSphere *check_pos, AC1Legacy::Vector3 *disp, float *radsum, const int sphere_number)
{
  AC1Legacy::Vector3 *v8; // esi@1
  signed int result; // eax@2
  AC1Legacy::Vector3 collision_normal; // [sp+8h] [bp-Ch]@1

  v8 = &path->global_curr_center[sphere_number];
  collision_normal.x = v8->x - this->center.x;
  collision_normal.y = v8->y - this->center.y;
  collision_normal.z = v8->z - this->center.z;
  if ( AC1Legacy::Vector3::normalize_check_small(&collision_normal) )
    result = 2;
  else
    result = CSphere::slide_sphere(check_pos, path, collisions, &collision_normal, v8);
  return result;
}

//----- (00537A80) --------------------------------------------------------  // acclient.c:359156
signed int __thiscall CSphere::intersects_sphere(CSphere *this, CTransition *transition, int is_creature)
{
  CTransition *v3; // ebp@1
  char *v4; // ebx@1
  CSphere *v5; // edi@1
  AC1Legacy::Vector3 *v6; // esi@1
  int v7; // eax@1
  COLLISIONINFO *v8; // edx@1
  signed int result; // eax@2
  CTransition *v10; // ebp@7
  AC1Legacy::Vector3 *v11; // eax@9
  float v12; // ecx@9
  float v13; // edx@9
  float v14; // eax@9
  CTransition *v15; // ebp@12
  AC1Legacy::Vector3 *v16; // ST18_4@15
  AC1Legacy::Vector3 *v17; // eax@15
  long double v18; // st7@15
  double v19; // st6@15
  double v20; // st6@17
  long double v21; // st7@19
  double v22; // st6@19
  Vector3 *v23; // eax@22
  double v24; // st7@22
  double v25; // st6@22
  double v26; // st5@22
  int v27; // eax@23
  COLLISIONINFO *v28; // edx@25
  AC1Legacy::Vector3 *v29; // edi@27
  float v30; // edx@27
  COLLISIONINFO *v31; // edx@30
  float v32; // edx@32
  AC1Legacy::Vector3 *v33; // edi@34
  double v34; // st7@39
  BOOL v35; // eax@9
  bool v36; // zf@40
  COLLISIONINFO *collisions; // [sp+10h] [bp-40h]@1
  double timecheck; // [sp+14h] [bp-3Ch]@15
  double timechecka; // [sp+14h] [bp-3Ch]@19
  AC1Legacy::Vector3 disp; // [sp+1Ch] [bp-34h]@1
  AC1Legacy::Vector3 movement; // [sp+28h] [bp-28h]@15
  AC1Legacy::Vector3 disp2; // [sp+34h] [bp-1Ch]@14
  Plane contact_plane; // [sp+40h] [bp-10h]@9

  v3 = transition;
  v4 = (char *)&transition->sphere_path;
  v5 = transition->sphere_path.global_sphere;
  v6 = (AC1Legacy::Vector3 *)this;
  v7 = transition->sphere_path.obstruction_ethereal;
  v8 = &transition->collision_info;
  disp.x = v5->center.x - this->center.x;
  collisions = &transition->collision_info;
  disp.y = v5->center.y - this->center.y;
  disp.z = v5->center.z - this->center.z;
  *(float *)&transition = this->radius + v5->radius - 0.00019999999;
  if ( v7 || (result = 1, *((_DWORD *)v4 + 85) == 1) )
  {
    if ( *(float *)&transition * *(float *)&transition >= disp.y * disp.y + disp.x * disp.x + disp.z * disp.z )
      return 2;
    if ( *(_DWORD *)v4 > 1u )
    {
      movement.x = v5[1].center.x - this->center.x;
      v34 = v5[1].center.y;
      disp = movement;
      movement.y = v34 - this->center.y;
      movement.z = v5[1].center.z - this->center.z;
      v35 = CSphere::collides_with_sphere(&disp, *(const float *)&transition);
LABEL_40:
      v36 = v35 == 0;
      result = 2;
      if ( !v36 )
        return result;
      return 1;
    }
    return 1;
  }
  if ( !*((_DWORD *)v4 + 86) )
  {
    if ( *((_DWORD *)v4 + 118) )
    {
      v10 = transition;
      if ( !CSphere::collides_with_sphere(&disp, *(const float *)&transition) )
      {
        if ( *(_DWORD *)v4 > 1u )
        {
          v11 = AC1Legacy::Vector3::operator-(&v5[1].center, &contact_plane.N, v6);
          v12 = v11->x;
          v13 = v11->y;
          v14 = v11->z;
          disp.x = v12;
          disp.y = v13;
          disp.z = v14;
          v35 = CSphere::collides_with_sphere(&disp, *(const float *)&v10);
          goto LABEL_40;
        }
        return 1;
      }
      return 2;
    }
    if ( !*((_DWORD *)v4 + 65) )
    {
      v27 = v3->object_info.state;
      if ( v27 & 3 )
      {
        if ( CSphere::collides_with_sphere(&disp, *(const float *)&transition) )
          return CSphere::step_sphere_up((CSphere *)v6, v3, v5, &disp, v32);
        if ( *(_DWORD *)v4 > 1u )
        {
          v33 = &v5[1].center;
          AC1Legacy::Vector3::operator-(v33, &disp2, v6);
          if ( CSphere::collides_with_sphere(&disp2, *(const float *)&transition) )
            return CSphere::slide_sphere(
                     (CSphere *)v6,
                     &v3->object_info,
                     (SPHEREPATH *)v4,
                     collisions,
                     (CSphere *)v33,
                     &disp2,
                     (float *)&transition,
                     1);
        }
      }
      else if ( v27 & 8 )
      {
        if ( CSphere::collides_with_sphere(&disp, *(const float *)&transition) )
          return CSphere::collide_with_point(
                   (CSphere *)v6,
                   &v3->object_info,
                   (SPHEREPATH *)v4,
                   v31,
                   v5,
                   &disp,
                   *(float *)&transition,
                   0);
      }
      else
      {
        if ( CSphere::collides_with_sphere(&disp, *(const float *)&transition) )
          return CSphere::land_on_sphere(
                   (CSphere *)v6,
                   &v3->object_info,
                   (SPHEREPATH *)v4,
                   v28,
                   v5,
                   &disp,
                   *(float *)&transition);
        if ( *(_DWORD *)v4 > 1u )
        {
          v29 = &v5[1].center;
          AC1Legacy::Vector3::operator-(v29, &disp2, v6);
          if ( CSphere::collides_with_sphere(&disp2, *(const float *)&transition) )
            return CSphere::collide_with_point(
                     (CSphere *)v6,
                     &v3->object_info,
                     (SPHEREPATH *)v4,
                     collisions,
                     (CSphere *)v29,
                     &disp2,
                     v30,
                     1);
        }
      }
      return 1;
    }
    if ( is_creature )
      return result;
    v15 = transition;
    if ( CSphere::collides_with_sphere(&disp, *(const float *)&transition)
      || *(_DWORD *)v4 > 1u
      && (AC1Legacy::Vector3::operator-(&v5[1].center, &disp2, v6),
          CSphere::collides_with_sphere(&disp2, *(const float *)&v15)) )
    {
      v16 = SPHEREPATH::get_curr_pos_check_pos_block_offset((SPHEREPATH *)v4, &contact_plane.N);
      v17 = AC1Legacy::Vector3::operator-(*((AC1Legacy::Vector3 **)v4 + 14), &disp2, &v5->center);
      AC1Legacy::Vector3::operator-(v17, &movement, v16);
      *(float *)&transition = *(float *)&transition + 0.00019999999;
      v18 = movement.z * movement.z + movement.y * movement.y + movement.x * movement.x;
      v19 = -(movement.y * disp.y + movement.x * disp.x + movement.z * disp.z);
      timecheck = v19;
      if ( fabs(v18) >= 0.00019999999 )
      {
        v20 = sqrt(v19 * v19 - (disp.y * disp.y
                              + disp.x * disp.x
                              + disp.z * disp.z
                              - *(float *)&transition * *(float *)&transition)
                             * v18)
            - (movement.y * disp.y
             + movement.x * disp.x
             + movement.z * disp.z);
        if ( v20 > 1.0 )
          v20 = timecheck + timecheck - v20;
        v21 = v20 / v18;
        v22 = (1.0 - v21) * *((float *)v4 + 111);
        timechecka = v22;
        if ( v22 < *((float *)v4 + 111) && v22 >= -0.1 )
        {
          movement.x = movement.x * v21;
          movement.y = movement.y * v21;
          movement.z = movement.z * v21;
          disp.x = movement.x + disp.x;
          disp.y = movement.y + disp.y;
          disp.z = movement.z + disp.z;
          Vector3::operator=/((Vector3 *)&disp.x, *(const float *)&transition);
          if ( SPHEREPATH::is_walkable_allowable((SPHEREPATH *)v4, disp.z) )
          {
            v23 = operator*((Vector3 *)&contact_plane.N.x, v5->radius, (Vector3 *)&disp.x);
            v24 = v23->x;
            v25 = v23->y;
            v26 = v5->center.x;
            contact_plane.N.z = v23->z;
            disp2.x = v26 - v24;
            disp2.y = v5->center.y - v25;
            disp2.z = v5->center.z - contact_plane.N.z;
            Plane::Plane(&contact_plane, &disp, &disp2);
            COLLISIONINFO::set_contact_plane(collisions, &contact_plane, 1);
            collisions->contact_plane_cell_id = *((_DWORD *)v4 + 68);
            *((float *)v4 + 111) = timechecka;
            SPHEREPATH::add_offset_to_check_pos((SPHEREPATH *)v4, &movement, v5->radius);
            return 3;
          }
          return 1;
        }
      }
      return 2;
    }
    return 1;
  }
  if ( !is_creature )
    result = CSphere::step_sphere_down(this, &v3->object_info, (SPHEREPATH *)v4, v8, v5, &disp, *(float *)&transition);
  return result;
}

//----- (00537FD0) --------------------------------------------------------  // acclient.c:359389
signed int __thiscall CSphere::intersects_sphere(CSphere *this, Position *p, float scale, CTransition *transition, int is_creature)
{
  double v5; // st7@1
  double v6; // st6@1
  AC1Legacy::Vector3 *v7; // eax@1
  float v8; // ecx@1
  float v9; // edx@1
  float v10; // eax@1
  AC1Legacy::Vector3 v; // [sp+0h] [bp-28h]@1
  AC1Legacy::Vector3 result; // [sp+Ch] [bp-1Ch]@1
  CSphere global_sphere; // [sp+18h] [bp-10h]@1

  global_sphere.radius = scale * this->radius;
  v5 = scale * this->center.x;
  v6 = scale * this->center.y;
  result.z = scale * this->center.z;
  v.z = result.z;
  v.x = v5;
  v.y = v6;
  v7 = Position::localtoglobal(&transition->sphere_path.check_pos, &result, p, &v);
  v8 = v7->x;
  v9 = v7->y;
  v10 = v7->z;
  global_sphere.center.x = v8;
  global_sphere.center.y = v9;
  global_sphere.center.z = v10;
  return CSphere::intersects_sphere(&global_sphere, transition, is_creature);
}

//----- (00700050) --------------------------------------------------------  // acclient.c:787979
void sub_700050()
{
  flt_8450CC = 1000.0 + 1.0;
}

//----- (00700070) --------------------------------------------------------  // acclient.c:787985
void sub_700070()
{
  flt_8450D0 = 24.0 * 8.0;
}

//----- (00700090) --------------------------------------------------------  // acclient.c:787991
void sub_700090()
{
  flt_8450D4 = 24.0 * 0.5;
}

//----- (007000B0) --------------------------------------------------------  // acclient.c:787997
int _E101_30()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_20;
  INITIAL_MAX_DATA_RATE_93 = LOWEST_DATA_RATE_20;
  return result;
}

//----- (007000C0) --------------------------------------------------------  // acclient.c:788007
void sub_7000C0()
{
  flt_8450E0 = 0.00019999999 * 3.0 + 0.1;
}

//----- (007000E0) --------------------------------------------------------  // acclient.c:788013
void _E105_36()
{
  dbl_8450E8 = 1.0 / 30.0;
}

//----- (00700100) --------------------------------------------------------  // acclient.c:788019
void _E107_29()
{
  dbl_8450F0 = 1.0 / 5.0;
}

//----- (00700120) --------------------------------------------------------  // acclient.c:788025
int sub_700120()
{
  return atexit(nullsub_1185);
}

