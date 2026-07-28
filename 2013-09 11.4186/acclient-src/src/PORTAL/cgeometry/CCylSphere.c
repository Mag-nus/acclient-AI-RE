/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CCylSphere
   Object     : PORTAL\cgeometry\CCylSphere.obj
   Functions  : 20
   Addresses  : 0053A880 - 00700880 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0053A880) --------------------------------------------------------  // acclient.c:361501
BOOL __thiscall CCylSphere::collides_with_sphere(CCylSphere *this, CSphere *check_pos, AC1Legacy::Vector3 *disp, const float radsum)
{
  return radsum * radsum >= disp->x * disp->x + disp->y * disp->y
      && check_pos->radius - 0.00019999999 + this->height * 0.5 >= fabs(this->height * 0.5 - disp->z);
}

//----- (0053A8E0) --------------------------------------------------------  // acclient.c:361508
void __thiscall CCylSphere::CCylSphere(CCylSphere *this)
{
  LODWORD(this->low_pt.x) = 0;
  LODWORD(this->low_pt.y) = 0;
  LODWORD(this->low_pt.z) = 0;
  LODWORD(this->height) = 0;
  LODWORD(this->radius) = 0;
}

//----- (0053A900) --------------------------------------------------------  // acclient.c:361518
signed int __thiscall CCylSphere::Pack(CCylSphere *this, void **addr, unsigned int size)
{
  char *v3; // edx@3
  char *v4; // esi@3
  char *v5; // edx@4

  if ( size >= 0x14 )
  {
    if ( size >= 0xC )
    {
      *(_DWORD *)*addr = LODWORD(this->low_pt.x);
      v3 = (char *)*addr + 4;
      *addr = v3;
      *(float *)v3 = this->low_pt.y;
      v4 = (char *)*addr + 4;
      *addr = v4;
      *(float *)v4 = this->low_pt.z;
      *addr = (char *)*addr + 4;
    }
    *(float *)*addr = this->radius;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = this->height;
    *addr = (char *)*addr + 4;
  }
  return 20;
}

//----- (0053A960) --------------------------------------------------------  // acclient.c:361547
int __thiscall CCylSphere::UnPack(CCylSphere *this, void **addr, unsigned int size)
{
  char *v3; // edx@2
  char *v4; // edx@2
  char *v5; // edx@3

  if ( size >= 0xC )
  {
    LODWORD(this->low_pt.x) = *(_DWORD *)*addr;
    v3 = (char *)*addr + 4;
    *addr = v3;
    LODWORD(this->low_pt.y) = *(_DWORD *)v3;
    v4 = (char *)*addr + 4;
    *addr = v4;
    LODWORD(this->low_pt.z) = *(_DWORD *)v4;
    *addr = (char *)*addr + 4;
  }
  LODWORD(this->radius) = *(_DWORD *)*addr;
  v5 = (char *)*addr + 4;
  *addr = v5;
  LODWORD(this->height) = *(_DWORD *)v5;
  *addr = (char *)*addr + 4;
  return 1;
}

//----- (0053A9B0) --------------------------------------------------------  // acclient.c:361573
signed int __thiscall CCylSphere::step_sphere_down(CCylSphere *this, OBJECTINFO *object, SPHEREPATH *path, COLLISIONINFO *collisions, CSphere *check_pos, AC1Legacy::Vector3 *disp, float radsum)
{
  int v7; // ecx@1
  CSphere *v8; // eax@3
  double v9; // st7@3
  signed int result; // eax@4
  long double v11; // st7@5
  double v12; // st6@7
  long double v13; // st7@7
  double v14; // st7@9
  float v15; // ecx@9
  double v16; // st7@9
  double v17; // st7@9
  float v18; // ST08_4@9
  AC1Legacy::Vector3 disp2; // [sp+10h] [bp-34h]@3
  AC1Legacy::Vector3 contact_pt; // [sp+1Ch] [bp-28h]@9
  AC1Legacy::Vector3 normal; // [sp+28h] [bp-1Ch]@9
  Plane contact_plane; // [sp+34h] [bp-10h]@9
  float radsuma; // [sp+5Ch] [bp+18h]@9

  if ( CCylSphere::collides_with_sphere(this, check_pos, disp, radsum)
    || path->num_sphere > 1
    && (v8 = path->global_sphere,
        v9 = v8[1].center.x,
        ++v8,
        disp2.x = v9 - *(float *)v7,
        disp2.y = v8->center.y - *(float *)(v7 + 4),
        disp2.z = v8->center.z - *(float *)(v7 + 8),
        CCylSphere::collides_with_sphere((CCylSphere *)v7, v8, &disp2, radsum)) )
  {
    v11 = path->step_down_amt * path->walk_interp;
    if ( fabs(v11) >= 0.00019999999 )
    {
      v12 = *(float *)(v7 + 12) + check_pos->radius - disp->z;
      v13 = (1.0 - v12 / v11) * path->walk_interp;
      *(double *)&disp2.x = v13;
      if ( v13 >= path->walk_interp || v13 < -0.1 )
      {
        result = 2;
      }
      else
      {
        radsuma = v12;
        v14 = radsuma - check_pos->radius;
        v15 = check_pos->center.y;
        contact_pt.x = check_pos->center.x;
        v16 = v14 + check_pos->center.z;
        contact_pt.y = v15;
        contact_pt.z = v16;
        LODWORD(normal.x) = 0;
        LODWORD(normal.y) = 0;
        LODWORD(normal.z) = 1065353216;
        Plane::Plane(&contact_plane, &normal, &contact_pt);
        COLLISIONINFO::set_contact_plane(collisions, &contact_plane, 1);
        v17 = *(double *)&disp2.x;
        collisions->contact_plane_cell_id = path->check_pos.objcell_id;
        path->walk_interp = v17;
        v18 = check_pos->radius;
        LODWORD(normal.x) = 0;
        LODWORD(normal.y) = 0;
        normal.z = v12;
        SPHEREPATH::add_offset_to_check_pos(path, &normal, v18);
        result = 3;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0053AB50) --------------------------------------------------------  // acclient.c:361651
int __thiscall CCylSphere::normal_of_collision(CCylSphere *this, SPHEREPATH *path, CSphere *check_pos, AC1Legacy::Vector3 *disp, float radsum, int sphere_num, AC1Legacy::Vector3 *normal)
{
  AC1Legacy::Vector3 *v7; // eax@1
  double v8; // st7@1
  double v9; // st5@1
  double v10; // st4@1
  int result; // eax@4
  float v12; // ST04_4@6
  float v13; // [sp+0h] [bp-18h]@2
  float v14; // [sp+4h] [bp-14h]@2
  float old_disp_8; // [sp+14h] [bp-4h]@1
  float patha; // [sp+1Ch] [bp+4h]@6
  int sphere_numa; // [sp+2Ch] [bp+14h]@6

  v7 = &path->global_curr_center[sphere_num];
  v8 = v7->x - this->low_pt.x;
  v9 = v7->y - this->low_pt.y;
  v10 = v7->z - this->low_pt.z;
  old_disp_8 = v10;
  if ( radsum * radsum < v9 * v9 + v8 * v8 )
  {
    v12 = v8;
    normal->x = v12;
    *(float *)&sphere_numa = v9;
    normal->y = *(float *)&sphere_numa;
    patha = v10;
    normal->z = patha;
    LODWORD(normal->z) = 0;
    if ( check_pos->radius - 0.00019999999 + this->height * 0.5 >= fabs(this->height * 0.5 - old_disp_8)
      || fabs(old_disp_8 - disp->z) <= 0.00019999999 )
      return 1;
    result = 0;
  }
  else
  {
    v13 = 0.0;
    v14 = 0.0;
    if ( disp->z - old_disp_8 <= 0.0 )
    {
      normal->x = v13;
      normal->y = v14;
      LODWORD(normal->z) = 1065353216;
      return 1;
    }
    normal->x = v13;
    normal->y = v14;
    LODWORD(normal->z) = -1082130432;
    result = 1;
  }
  return result;
}

//----- (0053ACB0) --------------------------------------------------------  // acclient.c:361704
signed int __thiscall CCylSphere::collide_with_point(CCylSphere *this, OBJECTINFO *object, SPHEREPATH *path, COLLISIONINFO *collisions, CSphere *check_pos, AC1Legacy::Vector3 *disp, float radsum, int sphere_num)
{
  CCylSphere *v8; // edi@1
  AC1Legacy::Vector3 *v10; // esi@4
  double v11; // st7@4
  double v12; // st6@4
  double v13; // st7@4
  double v14; // st6@7
  double v15; // st6@7
  long double v16; // st7@10
  double v17; // st6@11
  long double v18; // st5@11
  long double v19; // st5@13
  long double v20; // st7@14
  float _f; // ST10_4@16
  Vector3 *v22; // eax@16
  float v23; // ecx@16
  float v24; // edx@16
  Vector3 *v25; // eax@17
  Vector3 *v26; // eax@17
  float v27; // ecx@17
  float v28; // edx@17
  float v29; // eax@17
  double v30; // st7@21
  float v31; // ST10_4@23
  Vector3 *v32; // eax@23
  float v33; // ecx@23
  float v34; // edx@23
  float v35; // eax@23
  double v36; // st7@27
  double v37; // st6@27
  long double v38; // st5@27
  long double v39; // st5@29
  long double v40; // st7@30
  float v41; // ST10_4@32
  Vector3 *v42; // eax@32
  float v43; // ecx@32
  float v44; // edx@32
  Vector3 *v45; // eax@34
  Vector3 *v46; // eax@34
  float v47; // ecx@34
  float v48; // edx@34
  float v49; // eax@34
  Vector3 *v50; // eax@35
  Vector3 *v51; // eax@35
  float v52; // ecx@35
  float v53; // edx@35
  int definate; // [sp+14h] [bp-64h]@1
  int definatea; // [sp+14h] [bp-64h]@9
  double time; // [sp+18h] [bp-60h]@9
  double timea; // [sp+18h] [bp-60h]@30
  float v58; // [sp+24h] [bp-54h]@4
  float v59; // [sp+28h] [bp-50h]@4
  float v60; // [sp+2Ch] [bp-4Ch]@4
  float old_disp; // [sp+30h] [bp-48h]@4
  float old_disp_4; // [sp+34h] [bp-44h]@4
  float old_disp_8; // [sp+38h] [bp-40h]@4
  AC1Legacy::Vector3 collision_normal; // [sp+3Ch] [bp-3Ch]@1
  AC1Legacy::Vector3 offset; // [sp+48h] [bp-30h]@7
  Vector3 result; // [sp+54h] [bp-24h]@9
  Vector3 v67; // [sp+60h] [bp-18h]@4
  AC1Legacy::Vector3 movement; // [sp+6Ch] [bp-Ch]@4
  float radsuma; // [sp+94h] [bp+1Ch]@4

  v8 = this;
  definate = CCylSphere::normal_of_collision(this, path, check_pos, disp, radsum, sphere_num, &collision_normal);
  if ( AC1Legacy::Vector3::normalize_check_small(&collision_normal) )
    return 2;
  if ( !(object->state & 0x40) )
  {
    COLLISIONINFO::set_collision_normal(collisions, &collision_normal);
    return 2;
  }
  v10 = path->global_curr_center;
  LandDefs::get_block_offset(&movement, path->curr_pos.objcell_id, path->check_pos.objcell_id);
  v11 = check_pos->center.x - v10->x;
  v12 = check_pos->center.y - v10->y;
  v67.z = check_pos->center.z - v10->z;
  v58 = movement.x + v11;
  movement.x = v58;
  v59 = movement.y + v12;
  movement.y = v59;
  v60 = movement.z + v67.z;
  v13 = v10->x;
  movement.z = v60;
  old_disp = v13 - v8->low_pt.x;
  old_disp_4 = v10->y - v8->low_pt.y;
  old_disp_8 = v10->z - v8->low_pt.z;
  radsuma = radsum + 0.00019999999;
  if ( !definate )
  {
    if ( fabs(v60) < 0.00019999999 )
      return 2;
    if ( v60 > 0.0 )
    {
      LODWORD(offset.z) = -1082130432;
      v15 = -((old_disp_8 + check_pos->radius) / v60);
    }
    else
    {
      v14 = check_pos->radius;
      LODWORD(offset.z) = 1065353216;
      v15 = (v14 + v8->height - old_disp_8) / v60;
    }
    time = v15;
    collision_normal.z = offset.z;
    collision_normal.x = 0.0;
    collision_normal.y = 0.0;
    v67.x = v58 * v15;
    LODWORD(offset.x) = (_DWORD)v67.x;
    LODWORD(result.x) = (_DWORD)v67.x;
    v67.y = v59 * v15;
    result.y = v67.y;
    offset.y = v67.y;
    result.z = v15 * v60;
    offset.z = result.z;
    *(float *)&definatea = radsuma * radsuma;
    if ( (v67.y + old_disp_4) * (v67.y + old_disp_4) + (v67.x + old_disp) * (v67.x + old_disp) >= *(float *)&definatea )
    {
      v16 = v59 * v59 + v58 * v58;
      if ( fabs(v16) < 0.00019999999 )
        return 2;
      v17 = -(v59 * old_disp_4 + v58 * old_disp);
      v18 = v17 * v17 - (old_disp_4 * old_disp_4 + old_disp * old_disp - *(float *)&definatea) * v16;
      if ( v18 >= 0.0 && v16 > 0.00019999999 )
      {
        v19 = sqrt(v18);
        if ( v17 - v19 < 0.0 )
        {
          time = (v19 - (v59 * old_disp_4 + v58 * old_disp)) / v16;
          v20 = time;
        }
        else
        {
          v20 = (v17 - v19) / v16;
          time = v20;
        }
        _f = v20;
        v22 = operator*(&result, _f, (Vector3 *)&movement.x);
        v23 = v22->y;
        v67.x = v22->x;
        v24 = v22->z;
        v67.y = v23;
        v67.z = v24;
        LODWORD(offset.x) = (_DWORD)v67.x;
        offset.y = v23;
        offset.z = v24;
      }
      v25 = Vector3::operator+((Vector3 *)&v10->x, &result, (Vector3 *)&offset.x);
      v26 = Vector3::operator-(v25, (Vector3 *)&movement.x, (Vector3 *)&v8->low_pt.x);
      v27 = v26->x;
      v28 = v26->y;
      v29 = v26->z;
      v67.x = v27;
      collision_normal.x = v27;
      v67.y = v28;
      v67.z = v29;
      collision_normal.y = v28;
      LODWORD(collision_normal.z) = 0;
      Vector3::operator=/((Vector3 *)&collision_normal.x, radsuma);
    }
    goto LABEL_24;
  }
  if ( collision_normal.z != 0.0 )
  {
    if ( fabs(v60) < 0.00019999999 )
      return 2;
    if ( v60 > 0.0 )
      v30 = -((old_disp_8 + check_pos->radius) / v60);
    else
      v30 = (check_pos->radius + v8->height - old_disp_8) / v60;
    time = v30;
    v31 = v30;
    v32 = operator*(&result, v31, (Vector3 *)&movement.x);
    v33 = v32->x;
    v34 = v32->y;
    v35 = v32->z;
    v67.x = v33;
    v67.y = v34;
    v67.z = v35;
    offset.x = v33;
    offset.y = v34;
    offset.z = v35;
LABEL_24:
    if ( time >= 0.0 )
    {
      if ( time > 1.0 )
        return 2;
      goto LABEL_35;
    }
    return 2;
  }
  v36 = v59 * v59 + v58 * v58;
  v37 = -(v59 * old_disp_4 + v58 * old_disp);
  v38 = v37 * v37 - (old_disp_4 * old_disp_4 + old_disp * old_disp - radsuma * radsuma) * v36;
  if ( v38 >= 0.0 && v36 >= 0.00019999999 )
  {
    v39 = sqrt(v38);
    if ( v37 - v39 < 0.0 )
    {
      timea = (v39 - (v59 * old_disp_4 + v58 * old_disp)) / v36;
      v40 = timea;
    }
    else
    {
      v40 = (v37 - v39) / v36;
      timea = v40;
    }
    v41 = v40;
    v42 = operator*(&v67, v41, (Vector3 *)&movement.x);
    v43 = v42->x;
    v44 = v42->y;
    movement.z = v42->z;
    offset.z = movement.z;
    movement.x = v43;
    movement.y = v44;
    offset.x = v43;
    offset.y = v44;
    if ( timea >= 0.0 && timea <= 1.0 )
    {
      v45 = Vector3::operator+((Vector3 *)&v10->x, &result, (Vector3 *)&offset.x);
      v46 = Vector3::operator-(v45, &v67, (Vector3 *)&v8->low_pt.x);
      v47 = v46->x;
      v48 = v46->y;
      v49 = v46->z;
      movement.x = v47;
      collision_normal.x = v47;
      movement.y = v48;
      movement.z = v49;
      collision_normal.y = v48;
      LODWORD(collision_normal.z) = 0;
      Vector3::operator=/((Vector3 *)&collision_normal.x, radsuma);
LABEL_35:
      v50 = Vector3::operator+((Vector3 *)&v10->x, &result, (Vector3 *)&offset.x);
      v51 = Vector3::operator-(v50, &v67, (Vector3 *)&check_pos->center.x);
      v52 = v51->y;
      movement.x = v51->x;
      v53 = v51->z;
      LODWORD(offset.x) = (_DWORD)movement.x;
      movement.y = v52;
      offset.y = v52;
      movement.z = v53;
      offset.z = v53;
      COLLISIONINFO::set_collision_normal(collisions, &collision_normal);
      SPHEREPATH::add_offset_to_check_pos(path, &offset, check_pos->radius);
      return 3;
    }
  }
  return 2;
}

//----- (0053B2A0) --------------------------------------------------------  // acclient.c:361956
signed int __thiscall CCylSphere::slide_sphere(CCylSphere *this, OBJECTINFO *object, SPHEREPATH *path, COLLISIONINFO *collisions, CSphere *check_pos, AC1Legacy::Vector3 *disp, float radsum, int sphere_num)
{
  signed int result; // eax@2
  AC1Legacy::Vector3 collision_normal; // [sp+Ch] [bp-Ch]@1

  CCylSphere::normal_of_collision(this, path, check_pos, disp, radsum, sphere_num, &collision_normal);
  if ( AC1Legacy::Vector3::normalize_check_small(&collision_normal) )
    result = 2;
  else
    result = CSphere::slide_sphere(
               check_pos,
               path,
               collisions,
               &collision_normal,
               &path->global_curr_center[sphere_num]);
  return result;
}

//----- (0053B310) --------------------------------------------------------  // acclient.c:361975
signed int __thiscall CCylSphere::step_sphere_up(CCylSphere *this, CTransition *transition, CSphere *check_pos, AC1Legacy::Vector3 *disp, float radsum)
{
  signed int v5; // eax@3
  AC1Legacy::Vector3 *v6; // eax@4
  AC1Legacy::Vector3 collision_normal; // [sp+10h] [bp-18h]@2
  AC1Legacy::Vector3 result; // [sp+1Ch] [bp-Ch]@4

  if ( transition->object_info.step_up_height < check_pos->radius + this->height - disp->z )
  {
    v5 = CCylSphere::slide_sphere(
           this,
           &transition->object_info,
           &transition->sphere_path,
           &transition->collision_info,
           check_pos,
           disp,
           radsum,
           0);
  }
  else
  {
    CCylSphere::normal_of_collision(this, &transition->sphere_path, check_pos, disp, radsum, 0, &collision_normal);
    if ( AC1Legacy::Vector3::normalize_check_small(&collision_normal) )
    {
      v5 = 2;
    }
    else
    {
      v6 = Position::localtoglobalvec(&transition->sphere_path.localspace_pos, &result, &collision_normal);
      if ( CTransition::step_up(transition, v6) )
        v5 = 1;
      else
        v5 = SPHEREPATH::step_up_slide(&transition->sphere_path, &transition->object_info, &transition->collision_info);
    }
  }
  return v5;
}

//----- (0053B3D0) --------------------------------------------------------  // acclient.c:362014
signed int __thiscall CCylSphere::land_on_cylinder(CCylSphere *this, OBJECTINFO *object, SPHEREPATH *path, COLLISIONINFO *collisions, CSphere *check_pos, AC1Legacy::Vector3 *disp, float radsum)
{
  signed int result; // eax@2
  AC1Legacy::Vector3 collision_normal; // [sp+4h] [bp-Ch]@1

  CCylSphere::normal_of_collision(this, path, check_pos, disp, radsum, 0, &collision_normal);
  if ( AC1Legacy::Vector3::normalize_check_small(&collision_normal) )
  {
    result = 2;
  }
  else
  {
    SPHEREPATH::set_collide(path, &collision_normal);
    path->walkable_allowance = z_for_landing_2;
    result = 3;
  }
  return result;
}

//----- (0053B440) --------------------------------------------------------  // acclient.c:362034
signed int __thiscall CCylSphere::intersects_sphere(CCylSphere *this, CTransition *transition)
{
  CTransition *v2; // ebp@1
  char *v3; // ebx@1
  CCylSphere *v4; // esi@1
  CSphere *v5; // edi@1
  SPHEREPATH::InsertType v6; // ecx@1
  COLLISIONINFO *v7; // eax@1
  signed int result; // eax@4
  float v9; // ebp@6
  int v10; // edi@8
  AC1Legacy::Vector3 *v11; // eax@8
  float v12; // ecx@8
  float v13; // edx@8
  AC1Legacy::Vector3 *_rhs; // ST18_4@13
  AC1Legacy::Vector3 *v15; // eax@13
  float v16; // ST18_4@14
  Vector3 *v17; // eax@14
  long double v18; // st7@15
  Vector3 *v19; // eax@17
  double v20; // st7@17
  float v21; // edx@17
  long double v22; // st7@17
  int v23; // eax@19
  AC1Legacy::Vector3 *v24; // edi@23
  AC1Legacy::Vector3 *v25; // edi@30
  double v26; // st7@35
  double v27; // st7@35
  bool v28; // zf@36
  COLLISIONINFO *collisions; // [sp+14h] [bp-44h]@1
  AC1Legacy::Vector3 timecheck; // [sp+18h] [bp-40h]@13
  AC1Legacy::Vector3 disp; // [sp+24h] [bp-34h]@1
  AC1Legacy::Vector3 offset; // [sp+30h] [bp-28h]@14
  AC1Legacy::Vector3 disp2; // [sp+3Ch] [bp-1Ch]@8
  Plane contact_plane; // [sp+48h] [bp-10h]@13
  float transitiona; // [sp+5Ch] [bp+4h]@1

  v2 = transition;
  v3 = (char *)&transition->sphere_path;
  v4 = this;
  v5 = transition->sphere_path.global_sphere;
  v6 = transition->sphere_path.insert_type;
  v7 = &transition->collision_info;
  collisions = &transition->collision_info;
  disp.x = v5->center.x - v4->low_pt.x;
  disp.y = v5->center.y - v4->low_pt.y;
  disp.z = v5->center.z - v4->low_pt.z;
  transitiona = v4->radius - 0.00019999999 + v5->radius;
  if ( v6 == 1 || *((_DWORD *)v3 + 107) )
  {
    v9 = v4->radius - 0.00019999999 + v5->radius;
    if ( CCylSphere::collides_with_sphere(v4, v5, &disp, transitiona) )
      return 2;
    if ( *(_DWORD *)v3 > 1u )
    {
      v26 = v5[1].center.x;
      v10 = (int)&v5[1];
      offset.x = v26 - v4->low_pt.x;
      v27 = *(float *)(v10 + 4);
      LODWORD(disp.x) = (_DWORD)offset.x;
      offset.y = v27 - v4->low_pt.y;
      v12 = offset.y;
      offset.z = *(float *)(v10 + 8) - v4->low_pt.z;
      v13 = offset.z;
LABEL_36:
      disp.y = v12;
      disp.z = v13;
      v28 = CCylSphere::collides_with_sphere(v4, (CSphere *)v10, &disp, v9) == 0;
      result = 2;
      if ( !v28 )
        return result;
      return 1;
    }
  }
  else
  {
    if ( *((_DWORD *)v3 + 86) )
      return CCylSphere::step_sphere_down(v4, &v2->object_info, (SPHEREPATH *)v3, v7, v5, &disp, transitiona);
    if ( *((_DWORD *)v3 + 118) )
    {
      v9 = v4->radius - 0.00019999999 + v5->radius;
      if ( !CCylSphere::collides_with_sphere(v4, v5, &disp, transitiona) )
      {
        if ( *(_DWORD *)v3 > 1u )
        {
          v10 = (int)&v5[1];
          v11 = AC1Legacy::Vector3::operator-((AC1Legacy::Vector3 *)v10, &disp2, &v4->low_pt);
          v12 = v11->y;
          disp.x = v11->x;
          v13 = v11->z;
          goto LABEL_36;
        }
        return 1;
      }
      return 2;
    }
    if ( !*((_DWORD *)v3 + 65) )
    {
      v23 = v2->object_info.state;
      if ( v23 & 3 )
      {
        if ( CCylSphere::collides_with_sphere(v4, v5, &disp, transitiona) )
          return CCylSphere::step_sphere_up(v4, v2, v5, &disp, transitiona);
        if ( *(_DWORD *)v3 > 1u )
        {
          v25 = &v5[1].center;
          AC1Legacy::Vector3::operator-(v25, &disp2, &v4->low_pt);
          if ( CCylSphere::collides_with_sphere(v4, (CSphere *)v25, &disp2, transitiona) )
            return CCylSphere::slide_sphere(
                     v4,
                     &v2->object_info,
                     (SPHEREPATH *)v3,
                     collisions,
                     (CSphere *)v25,
                     &disp2,
                     transitiona,
                     1);
        }
      }
      else if ( v23 & 8 )
      {
        if ( CCylSphere::collides_with_sphere(v4, v5, &disp, transitiona) )
          return CCylSphere::collide_with_point(
                   v4,
                   &v2->object_info,
                   (SPHEREPATH *)v3,
                   collisions,
                   v5,
                   &disp,
                   transitiona,
                   0);
      }
      else
      {
        if ( CCylSphere::collides_with_sphere(v4, v5, &disp, transitiona) )
          return CCylSphere::land_on_cylinder(
                   v4,
                   &v2->object_info,
                   (SPHEREPATH *)v3,
                   collisions,
                   v5,
                   &disp,
                   transitiona);
        if ( *(_DWORD *)v3 > 1u )
        {
          v24 = &v5[1].center;
          AC1Legacy::Vector3::operator-(v24, &disp2, &v4->low_pt);
          if ( CCylSphere::collides_with_sphere(v4, (CSphere *)v24, &disp2, transitiona) )
            return CCylSphere::collide_with_point(
                     v4,
                     &v2->object_info,
                     (SPHEREPATH *)v3,
                     collisions,
                     (CSphere *)v24,
                     &disp2,
                     transitiona,
                     1);
        }
      }
      return 1;
    }
    if ( CCylSphere::collides_with_sphere(v4, v5, &disp, transitiona)
      || *(_DWORD *)v3 > 1u
      && (AC1Legacy::Vector3::operator-(&v5[1].center, &disp2, &v4->low_pt),
          CCylSphere::collides_with_sphere(v4, v5 + 1, &disp2, transitiona)) )
    {
      _rhs = SPHEREPATH::get_curr_pos_check_pos_block_offset((SPHEREPATH *)v3, &timecheck);
      v15 = AC1Legacy::Vector3::operator-(*((AC1Legacy::Vector3 **)v3 + 14), &contact_plane.N, &v5->center);
      AC1Legacy::Vector3::operator-(v15, &disp2, _rhs);
      if ( fabs(disp2.z) >= 0.00019999999 )
      {
        *(double *)&timecheck.x = (v4->height + v5->radius - disp.z) / disp2.z;
        v16 = *(double *)&timecheck.x;
        v17 = Vector3::operator*((Vector3 *)&disp2.x, (Vector3 *)&contact_plane.N.x, v16);
        offset.x = v17->x;
        offset.y = v17->y;
        offset.z = v17->z;
        if ( transitiona * transitiona < (offset.y + disp.y) * (offset.y + disp.y)
                                       + (offset.x + disp.x) * (offset.x + disp.x) )
          return 1;
        v18 = (1.0 - *(double *)&timecheck.x) * *((float *)v3 + 111);
        *(double *)&timecheck.x = v18;
        if ( v18 < *((float *)v3 + 111) && v18 >= -0.1 )
        {
          v19 = Vector3::operator+((Vector3 *)&v5->center.x, (Vector3 *)&contact_plane.N.x, (Vector3 *)&offset.x);
          v20 = v19->z;
          v21 = v19->y;
          disp2.x = v19->x;
          disp2.z = v20 - v5->radius;
          disp2.y = v21;
          LODWORD(disp.x) = 0;
          LODWORD(disp.y) = 0;
          LODWORD(disp.z) = 1065353216;
          Plane::Plane(&contact_plane, &disp, &disp2);
          COLLISIONINFO::set_contact_plane(collisions, &contact_plane, 1);
          v22 = *(double *)&timecheck.x;
          collisions->contact_plane_cell_id = *((_DWORD *)v3 + 68);
          *((float *)v3 + 111) = v22;
          SPHEREPATH::add_offset_to_check_pos((SPHEREPATH *)v3, &offset, v5->radius);
          return 3;
        }
      }
      return 2;
    }
  }
  return 1;
}

//----- (0053B8F0) --------------------------------------------------------  // acclient.c:362243
signed int __thiscall CCylSphere::intersects_sphere(CCylSphere *this, Position *p, float scale, CTransition *transition)
{
  CCylSphere *v4; // esi@1
  double v5; // st7@1
  double v6; // st6@1
  AC1Legacy::Vector3 *v7; // eax@1
  float v8; // ecx@1
  float v9; // edx@1
  float v10; // eax@1
  AC1Legacy::Vector3 v; // [sp+10h] [bp-2Ch]@1
  AC1Legacy::Vector3 result; // [sp+1Ch] [bp-20h]@1
  CCylSphere global_cylsphere; // [sp+28h] [bp-14h]@1

  v4 = this;
  SPHEREPATH::cache_localspace_sphere(&transition->sphere_path, p, 1.0);
  global_cylsphere.radius = scale * v4->radius;
  global_cylsphere.height = scale * v4->height;
  v5 = scale * v4->low_pt.x;
  v6 = scale * v4->low_pt.y;
  result.z = scale * v4->low_pt.z;
  v.z = result.z;
  v.x = v5;
  v.y = v6;
  v7 = Position::localtoglobal(&transition->sphere_path.check_pos, &result, p, &v);
  v8 = v7->x;
  v9 = v7->y;
  v10 = v7->z;
  global_cylsphere.low_pt.x = v8;
  global_cylsphere.low_pt.y = v9;
  global_cylsphere.low_pt.z = v10;
  return CCylSphere::intersects_sphere(&global_cylsphere, transition);
}

//----- (007007B0) --------------------------------------------------------  // acclient.c:788350
void sub_7007B0()
{
  flt_845294 = 1000.0 + 1.0;
}

//----- (007007D0) --------------------------------------------------------  // acclient.c:788356
void sub_7007D0()
{
  flt_845298 = 24.0 * 8.0;
}

//----- (007007F0) --------------------------------------------------------  // acclient.c:788362
void sub_7007F0()
{
  flt_84529C = 24.0 * 0.5;
}

//----- (00700810) --------------------------------------------------------  // acclient.c:788368
int _E101_32()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_22;
  INITIAL_MAX_DATA_RATE_95 = LOWEST_DATA_RATE_22;
  return result;
}

//----- (00700820) --------------------------------------------------------  // acclient.c:788378
void sub_700820()
{
  flt_8452A8 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00700840) --------------------------------------------------------  // acclient.c:788384
void _E105_38()
{
  dbl_8452B0 = 1.0 / 30.0;
}

//----- (00700860) --------------------------------------------------------  // acclient.c:788390
void _E107_31()
{
  dbl_8452B8 = 1.0 / 5.0;
}

//----- (00700880) --------------------------------------------------------  // acclient.c:788396
int sub_700880()
{
  return atexit(nullsub_1186);
}

