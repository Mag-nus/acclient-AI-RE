/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CBSPTree
   Object     : PORTAL\cgeometry\CBSPTree.obj
   Functions  : 90
   Addresses  : 005397E0 - 0076A990 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005397E0) --------------------------------------------------------  // acclient.c:360661
CSphere *__thiscall BSPTREE::GetSphere(BSPTREE *this)
{
  return &this->root_node->sphere;
}

//----- (005397F0) --------------------------------------------------------  // acclient.c:360667
int __thiscall BSPTREE::Pack(BSPTREE *this, void **addr, unsigned int size)
{
  BSPNODE **v3; // esi@1
  BSPNODE *v4; // ST00_4@1
  int result; // eax@1
  void *v6; // [sp+0h] [bp-4h]@1

  v6 = this;
  v3 = (BSPNODE **)this;
  v4 = this->root_node;
  v6 = 0;
  result = BSPNODE::PackChild(v4, &v6, 0);
  if ( size >= result )
    result = BSPNODE::PackChild(*v3, addr, size);
  return result;
}

//----- (00539830) --------------------------------------------------------  // acclient.c:360685
int __thiscall BSPTREE::UnPack(BSPTREE *this, void **addr, unsigned int size)
{
  BSPNODE **v3; // esi@1
  BSPNODE *v4; // ecx@1

  v3 = (BSPNODE **)this;
  v4 = this->root_node;
  if ( v4 )
  {
    ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
    *v3 = 0;
  }
  return BSPNODE::UnPackChild(v3, addr, size);
}

//----- (00539860) --------------------------------------------------------  // acclient.c:360701
void __thiscall BSPTREE::build_draw_portals_only(BSPTREE *this, int portalPolyOrPortalContents)
{
  BSPNODE *v2; // ecx@1
  int v3; // eax@2

  v2 = this->root_node;
  if ( v2 )
  {
    v3 = v2->type;
    if ( v3 != 1279607110 )
    {
      if ( v3 == 1347375700 )
        BSPPORTAL::portal_draw_portals_only((BSPPORTAL *)v2, portalPolyOrPortalContents);
      else
        BSPNODE::build_draw_portals_only(v2, portalPolyOrPortalContents);
    }
  }
  ((void (*)(void))Render::m_pRenderer->vfptr->polyListFinishInternal)();
  Render::PolyNext = (struct polyListEntry *)&Render::PolyList;
}
// 8662D8: using guessed type struct polyListEntry *Render::PolyNext;

//----- (005398B0) --------------------------------------------------------  // acclient.c:360724
int __thiscall BSPTREE::box_intersects_cell_bsp(BSPTREE *this, BBox *box)
{
  return BSPNODE::box_intersects_cell_bsp(this->root_node, box);
}

//----- (005398C0) --------------------------------------------------------  // acclient.c:360730
int __thiscall BSPTREE::point_inside_cell_bsp(BSPTREE *this, AC1Legacy::Vector3 *origin)
{
  return BSPNODE::point_inside_cell_bsp(this->root_node, origin);
}

//----- (005398D0) --------------------------------------------------------  // acclient.c:360736
signed int __thiscall BSPTREE::sphere_intersects_cell_bsp(BSPTREE *this, CSphere *sphere)
{
  return BSPNODE::sphere_intersects_cell_bsp(this->root_node, sphere);
}

//----- (005398E0) --------------------------------------------------------  // acclient.c:360742
void __thiscall SPHEREPATH::set_neg_poly_hit(SPHEREPATH *this, int step_up, AC1Legacy::Vector3 *collision_normal)
{
  char *v3; // ecx@1
  float v4; // ST00_4@1
  float v5; // ST04_4@1
  double v6; // st7@1
  float v7; // ST08_4@1

  this->neg_step_up = step_up;
  this->neg_poly_hit = 1;
  v3 = (char *)&this->neg_collision_normal;
  v4 = -collision_normal->x;
  v5 = -collision_normal->y;
  v6 = -collision_normal->z;
  *(float *)v3 = v4;
  v7 = v6;
  *((float *)v3 + 1) = v5;
  *((float *)v3 + 2) = v7;
}

//----- (00539940) --------------------------------------------------------  // acclient.c:360763
void __thiscall BSPTREE::~BSPTREE(BSPTREE *this)
{
  BSPTREE *v1; // esi@1
  BSPNODE *v2; // ecx@1

  v1 = this;
  v2 = this->root_node;
  if ( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->root_node = 0;
  }
}

//----- (00539960) --------------------------------------------------------  // acclient.c:360778
signed int __thiscall BSPTREE::placement_insert(BSPTREE *this, CTransition *transition)
{
  CSphere *v2; // eax@1
  char *v3; // esi@1
  double v4; // st7@1
  unsigned int v5; // ecx@1
  int v6; // eax@2
  int v7; // eax@3
  int v8; // edi@3
  BSPNODE *v9; // ecx@6
  bool v10; // sf@15
  unsigned __int8 v11; // of@15
  int v13; // eax@18
  double v14; // st7@18
  double v15; // st6@18
  AC1Legacy::Vector3 *v16; // eax@18
  int v17; // eax@21
  double v18; // st7@21
  double v19; // st6@21
  double v20; // st5@21
  double v21; // rt0@21
  double v22; // st5@21
  double v23; // st6@21
  CPolygon *hit_poly; // [sp+28h] [bp-48h]@3
  int center_solid; // [sp+2Ch] [bp-44h]@6
  int i; // [sp+30h] [bp-40h]@5
  BSPTREE *v27; // [sp+34h] [bp-3Ch]@1
  AC1Legacy::Vector3 offset; // [sp+38h] [bp-38h]@18
  AC1Legacy::Vector3 result; // [sp+44h] [bp-2Ch]@18
  CSphere valid_pos; // [sp+50h] [bp-20h]@1
  CSphere valid_pos2; // [sp+60h] [bp-10h]@2
  float transitiona; // [sp+74h] [bp+4h]@1

  v2 = transition->sphere_path.localspace_sphere;
  v3 = (char *)&transition->sphere_path;
  v27 = this;
  valid_pos.center.x = v2->center.x;
  valid_pos.center.y = v2->center.y;
  valid_pos.center.z = v2->center.z;
  v4 = v2->radius;
  v5 = transition->sphere_path.num_sphere;
  valid_pos.radius = v2->radius;
  transitiona = v4;
  if ( v5 > 1 )
  {
    v6 = (int)&v2[1];
    LODWORD(valid_pos2.center.x) = *(_DWORD *)v6;
    LODWORD(valid_pos2.center.y) = *(_DWORD *)(v6 + 4);
    LODWORD(valid_pos2.center.z) = *(_DWORD *)(v6 + 8);
    LODWORD(valid_pos2.radius) = *(_DWORD *)(v6 + 12);
  }
  v7 = *((_DWORD *)v3 + 109);
  hit_poly = 0;
  v8 = 1;
  if ( v7 )
    v8 = *((_DWORD *)v3 + 108) == 0;
  i = 0;
  while ( 1 )
  {
    v9 = v27->root_node;
    center_solid = 0;
    if ( ((int (__stdcall *)(CSphere *, float, int *, CPolygon **, int))v9->vfptr->sphere_intersects_solid_poly)(
           &valid_pos,
           LODWORD(transitiona),
           &center_solid,
           &hit_poly,
           v8) )
    {
      if ( !hit_poly )
        goto LABEL_14;
      CPolygon::adjust_to_placement_poly(hit_poly, &valid_pos, &valid_pos2, transitiona, center_solid, v8);
      goto LABEL_13;
    }
    if ( *(_DWORD *)v3 <= 1u )
      break;
    if ( !((int (__stdcall *)(CSphere *, float, int *, CPolygon **, int))v27->root_node->vfptr->sphere_intersects_solid_poly)(
            &valid_pos2,
            LODWORD(transitiona),
            &center_solid,
            &hit_poly,
            v8) )
    {
      if ( i )
      {
        v13 = *((_DWORD *)v3 + 9);
        v14 = valid_pos.center.z - *(float *)(v13 + 8);
        v15 = valid_pos.center.y - *(float *)(v13 + 4);
        offset.x = valid_pos.center.x - *(float *)v13;
        offset.y = v15;
        offset.z = v14;
        v16 = Position::localtoglobalvec((Position *)(v3 + 60), &result, &offset);
        offset.x = v16->x;
        offset.y = v16->y;
        offset.z = v16->z;
        SPHEREPATH::add_offset_to_check_pos((SPHEREPATH *)v3, &offset);
        return 3;
      }
      return 1;
    }
    if ( !hit_poly )
    {
LABEL_14:
      transitiona = transitiona + transitiona;
      goto LABEL_15;
    }
    CPolygon::adjust_to_placement_poly(hit_poly, &valid_pos2, &valid_pos, transitiona, center_solid, v8);
LABEL_13:
    hit_poly = 0;
    transitiona = valid_pos.radius;
LABEL_15:
    v11 = __OFSUB__(i + 1, 20);
    v10 = i++ - 19 < 0;
    if ( !(v10 ^ v11) )
      return 2;
  }
  if ( !i )
    return 1;
  v17 = *((_DWORD *)v3 + 9);
  v18 = valid_pos.center.z - *(float *)(v17 + 8);
  v19 = valid_pos.center.y - *(float *)(v17 + 4);
  v20 = valid_pos.center.x - *(float *)v17;
  offset.x = v20 * *((float *)v3 + 21) + v19 * *((float *)v3 + 24) + v18 * *((float *)v3 + 27);
  result = offset;
  offset.y = v20 * *((float *)v3 + 22) + v19 * *((float *)v3 + 25) + v18 * *((float *)v3 + 28);
  v21 = v20 * *((float *)v3 + 23);
  v22 = v19 * *((float *)v3 + 26);
  v23 = v18 * *((float *)v3 + 29);
  *((_DWORD *)v3 + 141) = 0;
  offset.z = v21 + v22 + v23;
  *((float *)v3 + 82) = offset.x + *((float *)v3 + 82);
  *((float *)v3 + 83) = offset.y + *((float *)v3 + 83);
  *((float *)v3 + 84) = offset.z + *((float *)v3 + 84);
  SPHEREPATH::cache_global_sphere((SPHEREPATH *)v3, &result);
  return 3;
}

//----- (00539BF0) --------------------------------------------------------  // acclient.c:360915
int __thiscall BSPTREE::adjust_to_plane(BSPTREE *this, CSphere *check_pos, AC1Legacy::Vector3 curr_pos, CPolygon *hit_poly, AC1Legacy::Vector3 *contact_pt)
{
  BSPTREE *v5; // edi@1
  signed int v6; // ebx@1
  double v7; // st7@2
  unsigned __int8 v9; // c2@2
  unsigned __int8 v10; // c3@2
  double v11; // st5@3
  double v12; // st7@3
  float v13; // ecx@3
  int result; // eax@5
  long double v15; // ST30_8@9
  double v16; // st7@9
  float v17; // ecx@9
  double v18; // st7@14
  float v19; // edx@14
  double ltime; // [sp+10h] [bp-48h]@1
  double utime; // [sp+18h] [bp-40h]@1
  double time_touch; // [sp+20h] [bp-38h]@2
  AC1Legacy::Vector3 movement; // [sp+28h] [bp-30h]@1
  float v24; // [sp+34h] [bp-24h]@3
  float v25; // [sp+38h] [bp-20h]@3
  float v26; // [sp+3Ch] [bp-1Ch]@3
  float v27; // [sp+40h] [bp-18h]@3
  float v28; // [sp+44h] [bp-14h]@3
  int v29; // [sp+54h] [bp-4h]@3

  v5 = this;
  utime = 1.0;
  movement.x = check_pos->center.x - curr_pos.x;
  ltime = 0.0;
  v6 = 0;
  movement.y = check_pos->center.y - curr_pos.y;
  movement.z = check_pos->center.z - curr_pos.z;
  while ( 1 )
  {
    v7 = CPolygon::adjust_sphere_to_poly(hit_poly, check_pos, &curr_pos, &movement);
    time_touch = v7;
    if ( v10 | v9 )
      break;
    v27 = movement.x * v7;
    v28 = movement.y * v7;
    v11 = v7 * movement.z;
    v12 = v28 + curr_pos.y;
    *(float *)&v29 = v11 + curr_pos.z;
    v26 = *(float *)&v29;
    v24 = v27 + curr_pos.x;
    check_pos->center.x = v24;
    v13 = v26;
    v25 = v12;
    check_pos->center.y = v25;
    check_pos->center.z = v13;
    if ( !((int (__stdcall *)(CSphere *, AC1Legacy::Vector3 *, CPolygon **, AC1Legacy::Vector3 *))v5->root_node->vfptr->sphere_intersects_poly)(
            check_pos,
            &movement,
            &hit_poly,
            contact_pt) )
    {
      ltime = time_touch;
      break;
    }
    ++v6;
    utime = time_touch;
    if ( v6 >= 15 )
      return 0;
  }
  if ( v6 < 15 )
  {
    do
    {
      v15 = (ltime + utime) * 0.5;
      v27 = movement.x * v15;
      v28 = movement.y * v15;
      v16 = v28 + curr_pos.y;
      *(float *)&v29 = v15 * movement.z + curr_pos.z;
      v26 = *(float *)&v29;
      v24 = v27 + curr_pos.x;
      check_pos->center.x = v24;
      v17 = v26;
      v25 = v16;
      check_pos->center.y = v25;
      check_pos->center.z = v17;
      if ( ((int (__stdcall *)(CSphere *, AC1Legacy::Vector3 *, CPolygon **, AC1Legacy::Vector3 *))v5->root_node->vfptr->sphere_intersects_poly)(
             check_pos,
             &movement,
             &hit_poly,
             contact_pt) )
        utime = (ltime + utime) * 0.5;
      else
        ltime = (ltime + utime) * 0.5;
      if ( utime - ltime < 0.02 )
        break;
      ++v6;
    }
    while ( v6 < 15 );
    v27 = movement.x * ltime;
    v28 = movement.y * ltime;
    v18 = v28 + curr_pos.y;
    *(float *)&v29 = ltime * movement.z + curr_pos.z;
    v19 = *(float *)&v29;
    v24 = v27 + curr_pos.x;
    check_pos->center.x = v24;
    v25 = v18;
    check_pos->center.y = v25;
    check_pos->center.z = v19;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00539E50) --------------------------------------------------------  // acclient.c:361030
signed int __stdcall BSPTREE::slide_sphere(SPHEREPATH *path, COLLISIONINFO *collisions, AC1Legacy::Vector3 *collision_normal)
{
  CSphere *v4; // ecx@1
  AC1Legacy::Vector3 *v5; // ST0C_4@1
  AC1Legacy::Vector3 v7; // [sp+0h] [bp-Ch]@1

  v4 = path->global_sphere;
  v7.x = path->localspace_pos.frame.m_fl2gv[6] * collision_normal->z
       + path->localspace_pos.frame.m_fl2gv[0] * collision_normal->x
       + path->localspace_pos.frame.m_fl2gv[3] * collision_normal->y;
  v7.y = path->localspace_pos.frame.m_fl2gv[7] * collision_normal->z
       + path->localspace_pos.frame.m_fl2gv[1] * collision_normal->x
       + path->localspace_pos.frame.m_fl2gv[4] * collision_normal->y;
  v5 = path->global_curr_center;
  v7.z = path->localspace_pos.frame.m_fl2gv[8] * collision_normal->z
       + path->localspace_pos.frame.m_fl2gv[2] * collision_normal->x
       + path->localspace_pos.frame.m_fl2gv[5] * collision_normal->y;
  return CSphere::slide_sphere(v4, path, collisions, &v7, v5);
}

//----- (00539ED0) --------------------------------------------------------  // acclient.c:361051
int __thiscall BSPTREE::check_walkable(BSPTREE *this, SPHEREPATH *path, CSphere *check_pos, float scale)
{
  BSPNODE *v4; // ecx@1
  float v5; // edx@1
  CSphere valid_pos; // [sp+4h] [bp-10h]@1

  v4 = this->root_node;
  valid_pos.center.x = check_pos->center.x;
  valid_pos.center.y = check_pos->center.y;
  v5 = check_pos->center.z;
  valid_pos.radius = check_pos->radius;
  valid_pos.center.z = v5;
  return (((int (__stdcall *)(SPHEREPATH *, CSphere *, AC1Legacy::Vector3 *))v4->vfptr->hits_walkable)(
            path,
            &valid_pos,
            &path->localspace_z) != 0)
       + 1;
}

//----- (00539F20) --------------------------------------------------------  // acclient.c:361071
signed int __stdcall BSPTREE::step_sphere_up(CTransition *transition, AC1Legacy::Vector3 *collision_normal)
{
  signed int result; // eax@2
  AC1Legacy::Vector3 v4; // [sp+8h] [bp-Ch]@1

  v4.x = transition->sphere_path.localspace_pos.frame.m_fl2gv[6] * collision_normal->z
       + transition->sphere_path.localspace_pos.frame.m_fl2gv[0] * collision_normal->x
       + transition->sphere_path.localspace_pos.frame.m_fl2gv[3] * collision_normal->y;
  v4.y = transition->sphere_path.localspace_pos.frame.m_fl2gv[7] * collision_normal->z
       + transition->sphere_path.localspace_pos.frame.m_fl2gv[1] * collision_normal->x
       + transition->sphere_path.localspace_pos.frame.m_fl2gv[4] * collision_normal->y;
  v4.z = transition->sphere_path.localspace_pos.frame.m_fl2gv[8] * collision_normal->z
       + transition->sphere_path.localspace_pos.frame.m_fl2gv[2] * collision_normal->x
       + transition->sphere_path.localspace_pos.frame.m_fl2gv[5] * collision_normal->y;
  if ( CTransition::step_up(transition, &v4) )
    result = 1;
  else
    result = SPHEREPATH::step_up_slide(&transition->sphere_path, &transition->object_info, &transition->collision_info);
  return result;
}

//----- (00539FC0) --------------------------------------------------------  // acclient.c:361093
void __thiscall SPHEREPATH::set_walkable(SPHEREPATH *this, CSphere *sphere, CPolygon *poly, AC1Legacy::Vector3 *zaxis, Position *local_pos, float scale)
{
  SPHEREPATH *v6; // esi@1

  v6 = this;
  this->walkable_check_pos = *sphere;
  this->walkable = poly;
  this->walkable_up = *zaxis;
  this->walkable_pos.objcell_id = local_pos->objcell_id;
  Frame::operator=((int)&this->walkable_pos.frame, (int)&local_pos->frame);
  v6->walkable_scale = scale;
}

//----- (0053A040) --------------------------------------------------------  // acclient.c:361107
void __thiscall BSPTREE::RemoveNonPortalNodes(BSPTREE *this)
{
  BSPNODE **v1; // esi@1
  SmartArray<BSPNODE *,1> PortalsToKeep; // [sp+4h] [bp-Ch]@1

  PortalsToKeep.m_data = 0;
  PortalsToKeep.m_sizeAndDeallocate = 0;
  PortalsToKeep.m_num = 0;
  v1 = (BSPNODE **)this;
  BSPNODE::DetachPortalsAndPurgeNodes(this->root_node, &PortalsToKeep);
  BSPNODE::LinkPortalNodeChain(*v1, &PortalsToKeep);
  if ( (PortalsToKeep.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](PortalsToKeep.m_data);
}

//----- (0053A090) --------------------------------------------------------  // acclient.c:361123
signed int __thiscall BSPTREE::collide_with_pt(BSPTREE *this, OBJECTINFO *object, SPHEREPATH *path, COLLISIONINFO *collisions, CSphere *check_pos, AC1Legacy::Vector3 *curr_pos, CPolygon *hit_poly, AC1Legacy::Vector3 *contact_pt, float scale)
{
  float v10; // eax@4
  float v11; // edi@4
  _BYTE v12[12]; // ST04_12@4
  AC1Legacy::Vector3 *v13; // eax@5
  AC1Legacy::Vector3 *v14; // eax@5
  float v15; // eax@5
  AC1Legacy::Vector3 offset; // [sp+10h] [bp-28h]@2
  AC1Legacy::Vector3 result; // [sp+1Ch] [bp-1Ch]@5
  CSphere valid_pos; // [sp+28h] [bp-10h]@4

  if ( !(object->state & 0x40) )
  {
    offset.x = path->localspace_pos.frame.m_fl2gv[0] * hit_poly->plane.N.x
             + path->localspace_pos.frame.m_fl2gv[3] * hit_poly->plane.N.y
             + path->localspace_pos.frame.m_fl2gv[6] * hit_poly->plane.N.z;
    offset.y = path->localspace_pos.frame.m_fl2gv[1] * hit_poly->plane.N.x
             + path->localspace_pos.frame.m_fl2gv[4] * hit_poly->plane.N.y
             + path->localspace_pos.frame.m_fl2gv[7] * hit_poly->plane.N.z;
    offset.z = path->localspace_pos.frame.m_fl2gv[2] * hit_poly->plane.N.x
             + path->localspace_pos.frame.m_fl2gv[5] * hit_poly->plane.N.y
             + path->localspace_pos.frame.m_fl2gv[8] * hit_poly->plane.N.z;
    COLLISIONINFO::set_collision_normal(collisions, &offset);
    return 2;
  }
  v10 = check_pos->center.y;
  valid_pos.center.x = check_pos->center.x;
  valid_pos.center.z = check_pos->center.z;
  v11 = curr_pos->x;
  valid_pos.center.y = v10;
  valid_pos.radius = check_pos->radius;
  *(_DWORD *)v12 = LODWORD(v11);
  *(_QWORD *)&v12[4] = *(_QWORD *)&curr_pos->y;
  if ( !BSPTREE::adjust_to_plane(this, &valid_pos, *(AC1Legacy::Vector3 *)v12, hit_poly, contact_pt) )
    return 2;
  v13 = Position::localtoglobalvec(&path->localspace_pos, &result, &hit_poly->plane.N);
  COLLISIONINFO::set_collision_normal(collisions, v13);
  offset.x = valid_pos.center.x - check_pos->center.x;
  offset.y = valid_pos.center.y - check_pos->center.y;
  offset.z = valid_pos.center.z - check_pos->center.z;
  v14 = Position::localtoglobalvec(&path->localspace_pos, &result, &offset);
  offset.x = v14->x;
  offset.y = v14->y;
  v15 = v14->z;
  offset.x = offset.x * scale;
  offset.y = offset.y * scale;
  offset.z = v15 * scale;
  SPHEREPATH::add_offset_to_check_pos(path, &offset);
  return 3;
}

//----- (0053A210) --------------------------------------------------------  // acclient.c:361176
signed int __thiscall BSPTREE::step_sphere_down(BSPTREE *this, SPHEREPATH *path, COLLISIONINFO *collisions, CSphere *check_pos, float scale)
{
  SPHEREPATH *v5; // esi@1
  char *v6; // ebp@1
  CSphere *v7; // ebx@1
  double v8; // st7@1
  float v9; // edx@1
  double v10; // st6@1
  BSPNODE *v11; // ecx@1
  float v12; // eax@1
  double v13; // st6@1
  double v14; // st7@1
  double v15; // st6@1
  double v16; // st5@1
  double v17; // st7@1
  double v18; // st5@1
  double v19; // st7@2
  double v20; // st6@2
  double v21; // st5@2
  double v22; // st5@2
  double v23; // rt1@2
  double v24; // st5@2
  double v25; // st6@2
  double v26; // st7@2
  COLLISIONINFO *v27; // eax@2
  int v28; // ebx@2
  int v29; // edx@2
  float v30; // ST14_4@2
  signed int v31; // eax@2
  AC1Legacy::Vector3 offset; // [sp+18h] [bp-38h]@2
  Plane result; // [sp+24h] [bp-2Ch]@1
  AC1Legacy::Vector3 trans; // [sp+34h] [bp-1Ch]@1
  CSphere valid_pos; // [sp+40h] [bp-10h]@1

  v5 = path;
  v6 = (char *)&path->localspace_z;
  v7 = check_pos;
  v8 = -(path->step_down_amt * path->walk_interp);
  v9 = check_pos->center.y;
  v10 = v8 * path->localspace_z.x;
  v11 = this->root_node;
  valid_pos.center.x = check_pos->center.x;
  v12 = check_pos->center.z;
  result.N.x = v10;
  valid_pos.center.z = v12;
  valid_pos.center.y = v9;
  v13 = v8 * path->localspace_z.y;
  valid_pos.radius = check_pos->radius;
  result.N.y = v13;
  path = 0;
  v14 = v8 * *((float *)v6 + 2);
  v15 = 1.0 / scale;
  *(float *)&check_pos = v15;
  v16 = v14;
  v17 = result.N.y * *(float *)&check_pos;
  v18 = v16 * *(float *)&check_pos;
  *(float *)&check_pos = 0.0;
  result.N.z = v18;
  trans.z = result.N.z;
  trans.x = v15 * result.N.x;
  trans.y = v17;
  ((void (__stdcall *)(SPHEREPATH *, CSphere *, CSphere **, AC1Legacy::Vector3 *, char *, SPHEREPATH **))v11->vfptr->find_walkable)(
    v5,
    &valid_pos,
    &check_pos,
    &trans,
    v6,
    &path);
  if ( path )
  {
    v19 = valid_pos.center.x - v7->center.x;
    v20 = valid_pos.center.y - v7->center.y;
    v21 = valid_pos.center.z - v7->center.z;
    result.N.x = v21 * v5->localspace_pos.frame.m_fl2gv[6]
               + v20 * v5->localspace_pos.frame.m_fl2gv[3]
               + v19 * v5->localspace_pos.frame.m_fl2gv[0];
    LODWORD(offset.x) = (_DWORD)result.N.x;
    result.N.y = v21 * v5->localspace_pos.frame.m_fl2gv[7]
               + v20 * v5->localspace_pos.frame.m_fl2gv[4]
               + v19 * v5->localspace_pos.frame.m_fl2gv[1];
    v22 = v21 * v5->localspace_pos.frame.m_fl2gv[8];
    offset.y = result.N.y;
    v23 = v22;
    v24 = v20 * v5->localspace_pos.frame.m_fl2gv[5];
    v25 = v19 * v5->localspace_pos.frame.m_fl2gv[2];
    v5->cell_array_valid = 0;
    result.N.z = v23 + v24 + v25;
    offset.x = result.N.x * scale;
    offset.y = offset.y * scale;
    offset.z = result.N.z * scale;
    v5->check_pos.frame.m_fOrigin.x = offset.x + v5->check_pos.frame.m_fOrigin.x;
    v5->check_pos.frame.m_fOrigin.y = offset.y + v5->check_pos.frame.m_fOrigin.y;
    v5->check_pos.frame.m_fOrigin.z = offset.z + v5->check_pos.frame.m_fOrigin.z;
    SPHEREPATH::cache_global_sphere(v5, &offset);
    Plane::localtoglobal(&result, &v5->check_pos, &v5->localspace_pos, (Plane *)&check_pos[2]);
    v26 = result.d * scale;
    v27 = collisions;
    collisions->contact_plane_valid = 1;
    result.d = v26;
    v28 = (signed int)result.N.x;
    v27->contact_plane.d = v26;
    v29 = (int)&v27->contact_plane;
    *(_DWORD *)v29 = v28;
    *(_DWORD *)(v29 + 4) = LODWORD(result.N.y);
    *(_DWORD *)(v29 + 8) = LODWORD(result.N.z);
    v30 = scale;
    v27->contact_plane_is_water = 0;
    v27->contact_plane_cell_id = v5->check_pos.objcell_id;
    SPHEREPATH::set_walkable(v5, &valid_pos, (CPolygon *)check_pos, (AC1Legacy::Vector3 *)v6, &v5->localspace_pos, v30);
    v31 = 3;
  }
  else
  {
    v31 = 1;
  }
  return v31;
}

//----- (0053A440) --------------------------------------------------------  // acclient.c:361295
int __thiscall BSPTREE::find_collisions(BSPTREE *this, CTransition *transition, float scale)
{
  AC1Legacy::Vector3 *v3; // ebp@1
  char *v4; // esi@1
  CSphere *v5; // edi@1
  BSPTREE *v6; // ebx@1
  double v7; // st7@1
  bool v8; // zf@1
  double v9; // st6@1
  double v10; // st5@1
  double v11; // st5@1
  float v13; // edx@8
  BSPNODE *v14; // ebx@8
  AC1Legacy::Vector3 *v15; // eax@9
  float v16; // eax@9
  CPolygon *v17; // edx@9
  float v18; // ST1C_4@9
  int v19; // eax@10
  BSPNODE *v20; // ecx@10
  AC1Legacy::Vector3 *v21; // eax@16
  AC1Legacy::Vector3 *v22; // eax@18
  BSPNODEVtbl *v23; // eax@20
  AC1Legacy::Vector3 *v24; // eax@26
  signed int v25; // ebp@31
  CPolygon *hit_poly; // [sp+20h] [bp-5Ch]@1
  COLLISIONINFO *collisions; // [sp+24h] [bp-58h]@1
  int changed; // [sp+28h] [bp-54h]@8
  AC1Legacy::Vector3 collision_normal; // [sp+2Ch] [bp-50h]@9
  AC1Legacy::Vector3 movement; // [sp+38h] [bp-44h]@1
  AC1Legacy::Vector3 contact_pt; // [sp+44h] [bp-38h]@11
  AC1Legacy::Vector3 result; // [sp+50h] [bp-2Ch]@9
  CSphere valid_pos; // [sp+5Ch] [bp-20h]@8
  Plane trans; // [sp+6Ch] [bp-10h]@9

  v3 = transition->sphere_path.localspace_curr_center;
  v4 = (char *)&transition->sphere_path;
  v5 = transition->sphere_path.localspace_sphere;
  v6 = this;
  v7 = v5->center.z - v3->z;
  v8 = transition->sphere_path.insert_type == 1;
  v9 = v5->center.y - v3->y;
  v10 = v5->center.x;
  collisions = &transition->collision_info;
  v11 = v10 - v3->x;
  hit_poly = 0;
  movement.x = v11;
  movement.y = v9;
  movement.z = v7;
  if ( v8 || transition->sphere_path.obstruction_ethereal )
  {
    v25 = 1;
    if ( transition->sphere_path.bldg_check )
      v25 = transition->sphere_path.hits_interior_cell == 0;
    if ( ((int (__stdcall *)(CSphere *, signed int))this->root_node->vfptr->sphere_intersects_solid)(v5, v25)
      || *(_DWORD *)v4 > 1u
      && v6->root_node->vfptr->sphere_intersects_solid(v6->root_node, (CSphere *)(*((_DWORD *)v4 + 9) + 16), v25) )
      return 2;
  }
  else
  {
    if ( transition->sphere_path.check_walkable )
      return BSPTREE::check_walkable(this, &transition->sphere_path, v5, scale);
    if ( transition->sphere_path.step_down )
      return BSPTREE::step_sphere_down(this, &transition->sphere_path, &transition->collision_info, v5, scale);
    if ( transition->sphere_path.collide )
    {
      v13 = v5->center.x;
      v14 = this->root_node;
      valid_pos.center.y = v5->center.y;
      valid_pos.radius = v5->radius;
      transition = 0;
      changed = 0;
      valid_pos.center.x = v13;
      valid_pos.center.z = v5->center.z;
      v14->vfptr->find_walkable(
        v14,
        (SPHEREPATH *)v4,
        &valid_pos,
        (CPolygon **)&transition,
        &movement,
        (AC1Legacy::Vector3 *)(v4 + 132),
        &changed);
      if ( changed )
      {
        collision_normal.x = valid_pos.center.x - v5->center.x;
        collision_normal.y = valid_pos.center.y - v5->center.y;
        collision_normal.z = valid_pos.center.z - v5->center.z;
        v15 = Position::localtoglobalvec((Position *)(v4 + 60), &result, &collision_normal);
        collision_normal.x = v15->x;
        collision_normal.y = v15->y;
        v16 = v15->z;
        collision_normal.x = collision_normal.x * scale;
        collision_normal.y = collision_normal.y * scale;
        collision_normal.z = v16 * scale;
        SPHEREPATH::add_offset_to_check_pos((SPHEREPATH *)v4, &collision_normal);
        Plane::localtoglobal(&trans, (Position *)(v4 + 268), (Position *)(v4 + 60), (Plane *)&transition->sphere_path);
        trans.d = trans.d * scale;
        COLLISIONINFO::set_contact_plane(collisions, &trans, 0);
        v17 = (CPolygon *)transition;
        v18 = scale;
        collisions->contact_plane_cell_id = *((_DWORD *)v4 + 68);
        SPHEREPATH::set_walkable(
          (SPHEREPATH *)v4,
          &valid_pos,
          v17,
          (AC1Legacy::Vector3 *)v4 + 11,
          (Position *)(v4 + 60),
          v18);
        return 3;
      }
    }
    else
    {
      v19 = transition->object_info.state;
      v20 = this->root_node;
      if ( v19 & 1 )
      {
        if ( ((int (__stdcall *)(CSphere *, AC1Legacy::Vector3 *, CPolygon **, AC1Legacy::Vector3 *))v20->vfptr->sphere_intersects_poly)(
               v5,
               &movement,
               &hit_poly,
               &contact_pt) )
          return BSPTREE::step_sphere_up(transition, &hit_poly->plane.N);
        scale = 0.0;
        if ( *(_DWORD *)v4 > 1u )
        {
          if ( ((int (__stdcall *)(int, AC1Legacy::Vector3 *, float *, AC1Legacy::Vector3 *))v6->root_node->vfptr->sphere_intersects_poly)(
                 *((_DWORD *)v4 + 9) + 16,
                 &movement,
                 &scale,
                 &contact_pt) )
            return BSPTREE::slide_sphere((SPHEREPATH *)v4, collisions, (AC1Legacy::Vector3 *)(LODWORD(scale) + 32));
          if ( scale != 0.0 )
          {
            v21 = Position::localtoglobalvec(
                    (Position *)(v4 + 60),
                    &result,
                    (AC1Legacy::Vector3 *)(LODWORD(scale) + 32));
            SPHEREPATH::set_neg_poly_hit((SPHEREPATH *)v4, 0, v21);
            return 1;
          }
          if ( hit_poly )
          {
            v22 = Position::localtoglobalvec((Position *)(v4 + 60), &result, &hit_poly->plane.N);
            SPHEREPATH::set_neg_poly_hit((SPHEREPATH *)v4, 1, v22);
            return 1;
          }
        }
      }
      else
      {
        v8 = (v19 & 8) == 0;
        v23 = v20->vfptr;
        if ( v8 )
        {
          if ( ((int (__stdcall *)(CSphere *, AC1Legacy::Vector3 *, CPolygon **, AC1Legacy::Vector3 *))v23->sphere_intersects_poly)(
                 v5,
                 &movement,
                 &hit_poly,
                 &contact_pt)
            || hit_poly )
          {
            Position::localtoglobalvec((Position *)(v4 + 60), &collision_normal, &hit_poly->plane.N);
            SPHEREPATH::set_collide((SPHEREPATH *)v4, &collision_normal);
            *((_DWORD *)v4 + 110) = LODWORD(z_for_landing_1);
            return 3;
          }
          if ( *(_DWORD *)v4 > 1u
            && (v6->root_node->vfptr->sphere_intersects_poly(
                  v6->root_node,
                  (CSphere *)(*((_DWORD *)v4 + 9) + 16),
                  &movement,
                  &hit_poly,
                  &contact_pt)
             || hit_poly) )
          {
            v24 = Position::localtoglobalvec((Position *)(v4 + 60), &result, &hit_poly->plane.N);
            COLLISIONINFO::set_collision_normal(collisions, v24);
            return 2;
          }
        }
        else if ( ((int (__stdcall *)(CSphere *, AC1Legacy::Vector3 *, CPolygon **, AC1Legacy::Vector3 *))v23->sphere_intersects_poly)(
                    v5,
                    &movement,
                    &hit_poly,
                    &contact_pt)
               || hit_poly )
        {
          return BSPTREE::collide_with_pt(
                   v6,
                   &transition->object_info,
                   (SPHEREPATH *)v4,
                   collisions,
                   v5,
                   v3,
                   hit_poly,
                   &contact_pt,
                   scale);
        }
      }
    }
  }
  return 1;
}

//----- (007001A0) --------------------------------------------------------  // acclient.c:788055
int sub_7001A0()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_21;
  INITIAL_MAX_DATA_RATE_94 = LOWEST_DATA_RATE_21;
  return result;
}

//----- (007001B0) --------------------------------------------------------  // acclient.c:788065
void sub_7001B0()
{
  flt_845148 = 1000.0 + 1.0;
}

//----- (007001D0) --------------------------------------------------------  // acclient.c:788071
void _E99_33()
{
  flt_84514C = 24.0 * 8.0;
}

//----- (007001F0) --------------------------------------------------------  // acclient.c:788077
void _E101_31()
{
  flt_845150 = 24.0 * 0.5;
}

//----- (00700210) --------------------------------------------------------  // acclient.c:788083
void sub_700210()
{
  flt_845158 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00700230) --------------------------------------------------------  // acclient.c:788089
void _E105_37()
{
  dbl_845160 = 1.0 / 30.0;
}

//----- (00700250) --------------------------------------------------------  // acclient.c:788095
void _E107_30()
{
  dbl_845168 = 1.0 / 5.0;
}

//----- (00700270) --------------------------------------------------------  // acclient.c:788101
void _E109_67()
{
  PixelFormatDesc::PixelFormatDesc(&stru_845170, PFID_A8R8G8B8);
}

//----- (00700280) --------------------------------------------------------  // acclient.c:788107
int _E111_41()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_29, "Render.TextureFiltering");
  return atexit(sub_76A550);
}

//----- (007002A0) --------------------------------------------------------  // acclient.c:788114
int _E114_51()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_29, "Render.LandscapeDetailTextures");
  return atexit(sub_76A580);
}

//----- (007002C0) --------------------------------------------------------  // acclient.c:788121
int _E117_59()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_29, "Render.BuildingDetailTextures");
  return atexit(sub_76A5B0);
}

//----- (007002E0) --------------------------------------------------------  // acclient.c:788128
int _E120_57()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_29, "Render.FieldOfView");
  return atexit(sub_76A5E0);
}

//----- (00700300) --------------------------------------------------------  // acclient.c:788135
int _E123_35()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_29, "Render.LandscapeTextureDetail");
  return atexit(sub_76A610);
}

//----- (00700320) --------------------------------------------------------  // acclient.c:788142
int _E126_41()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_29, "Render.EnvironmentTextureDetail");
  return atexit(sub_76A640);
}

//----- (00700340) --------------------------------------------------------  // acclient.c:788149
int _E129_33()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_29, "Render.SceneryDrawDistance");
  return atexit(sub_76A670);
}

//----- (00700360) --------------------------------------------------------  // acclient.c:788156
int _E132_36()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_29, "Render.LandscapeDrawDistance");
  return atexit(_E133_95);
}

//----- (00700380) --------------------------------------------------------  // acclient.c:788163
int _E135_39()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_29, "Render.ScreenBrightness");
  return atexit(_E136_78);
}

//----- (007003A0) --------------------------------------------------------  // acclient.c:788170
int _E138_31()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_29, "Render.AspectRatio");
  return atexit(_E139_78);
}

//----- (007003C0) --------------------------------------------------------  // acclient.c:788177
int _E141_31()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_29, "Render.DisplayAdapter");
  return atexit(_E142_73);
}

//----- (007003E0) --------------------------------------------------------  // acclient.c:788184
int _E144_30()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_29, "Render.MaxHardwareClass");
  return atexit(_E145_75);
}

//----- (00700400) --------------------------------------------------------  // acclient.c:788191
int _E147_28()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_29, "Render.AutomaticDegrades");
  return atexit(_E148_71);
}

//----- (00700420) --------------------------------------------------------  // acclient.c:788198
int _E150_28()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_29, "Render.GraphicsPerformance");
  return atexit(_E151_69);
}

//----- (00700440) --------------------------------------------------------  // acclient.c:788205
int _E153_26()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_29, "Render.DegradeDistance");
  return atexit(_E154_70);
}

//----- (00700460) --------------------------------------------------------  // acclient.c:788212
int _E156_28()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_29, "Render.MultiPassAlpha");
  return atexit(_E157_66);
}

//----- (00700480) --------------------------------------------------------  // acclient.c:788219
int _E159_26()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_29, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8451EC, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8451F0, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8451F4, "Anisotropic");
  return atexit(_E160_69);
}

//----- (007004D0) --------------------------------------------------------  // acclient.c:788229
int _E162_28()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_29, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8451FC, "Low");
  PStringBase<char>::PStringBase<char>(&stru_845200, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_845204, "High");
  PStringBase<char>::PStringBase<char>(&stru_845208, "VeryHigh");
  return atexit(_E163_62);
}

//----- (00700530) --------------------------------------------------------  // acclient.c:788240
int _E165_24()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_29, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_845210, "Low");
  PStringBase<char>::PStringBase<char>(&stru_845214, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_845218, "High");
  PStringBase<char>::PStringBase<char>(&stru_84521C, "VeryHigh");
  return atexit(_E166_64);
}

//----- (00700590) --------------------------------------------------------  // acclient.c:788251
int _E168_25()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_29, "Low");
  PStringBase<char>::PStringBase<char>(&stru_845224, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_845228, "High");
  return atexit(_E169_63);
}

//----- (007005D0) --------------------------------------------------------  // acclient.c:788260
int _E171_24()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_29, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_845230, "Low");
  PStringBase<char>::PStringBase<char>(&stru_845234, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_845238, "High");
  PStringBase<char>::PStringBase<char>(&stru_84523C, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_845240, "Extreme");
  return atexit(_E172_61);
}

//----- (00700640) --------------------------------------------------------  // acclient.c:788272
int _E174_25()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_29, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_845248, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_84524C, "Wide");
  return atexit(_E175_58);
}

//----- (00700680) --------------------------------------------------------  // acclient.c:788281
int _E177_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_53, "None");
  return atexit(_E178_58);
}

//----- (007006A0) --------------------------------------------------------  // acclient.c:788288
int _E180_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_53, "Speed");
  return atexit(_E181_58);
}

//----- (007006C0) --------------------------------------------------------  // acclient.c:788295
int _E183_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_53, "Noise");
  return atexit(_E184_55);
}

//----- (007006E0) --------------------------------------------------------  // acclient.c:788302
int _E186_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_53, "Sine");
  return atexit(_E187_54);
}

//----- (00700700) --------------------------------------------------------  // acclient.c:788309
int _E189_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_53, "Square");
  return atexit(_E190_55);
}

//----- (00700720) --------------------------------------------------------  // acclient.c:788316
int _E192_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_53, "Bounce");
  return atexit(_E193_46);
}

//----- (00700740) --------------------------------------------------------  // acclient.c:788323
int _E195_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_53, "Perlin");
  return atexit(_E196_53);
}

//----- (00700760) --------------------------------------------------------  // acclient.c:788330
int _E198_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_53, "Fractal");
  return atexit(_E199_45);
}

//----- (00700780) --------------------------------------------------------  // acclient.c:788337
int _E201_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_53, "FrameLoop");
  return atexit(_E202_46);
}

//----- (007007A0) --------------------------------------------------------  // acclient.c:788344
int sub_7007A0()
{
  return atexit(nullsub_1176);
}

//----- (0076A3A0) --------------------------------------------------------  // acclient.c:897274
void __cdecl _E178_58()
{
  char *v0; // esi@1

  v0 = &waveform_None_53.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_53.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A3D0) --------------------------------------------------------  // acclient.c:897287
void __cdecl _E181_58()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_53.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_53.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A400) --------------------------------------------------------  // acclient.c:897300
void __cdecl _E184_55()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_53.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_53.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A430) --------------------------------------------------------  // acclient.c:897313
void __cdecl _E187_54()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_53.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_53.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A460) --------------------------------------------------------  // acclient.c:897326
void __cdecl _E190_55()
{
  char *v0; // esi@1

  v0 = &waveform_Square_53.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_53.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A490) --------------------------------------------------------  // acclient.c:897339
void __cdecl _E193_46()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_53.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_53.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A4C0) --------------------------------------------------------  // acclient.c:897352
void __cdecl _E196_53()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_53.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_53.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A4F0) --------------------------------------------------------  // acclient.c:897365
void __cdecl _E199_45()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_53.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_53.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A520) --------------------------------------------------------  // acclient.c:897378
void __cdecl _E202_46()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_53.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_53.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A550) --------------------------------------------------------  // acclient.c:897391
void __cdecl sub_76A550()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A580) --------------------------------------------------------  // acclient.c:897404
void __cdecl sub_76A580()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A5B0) --------------------------------------------------------  // acclient.c:897417
void __cdecl sub_76A5B0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A5E0) --------------------------------------------------------  // acclient.c:897430
void __cdecl sub_76A5E0()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A610) --------------------------------------------------------  // acclient.c:897443
void __cdecl sub_76A610()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A640) --------------------------------------------------------  // acclient.c:897456
void __cdecl sub_76A640()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A670) --------------------------------------------------------  // acclient.c:897469
void __cdecl sub_76A670()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A6A0) --------------------------------------------------------  // acclient.c:897482
void __cdecl _E133_95()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A6D0) --------------------------------------------------------  // acclient.c:897495
void __cdecl _E136_78()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A700) --------------------------------------------------------  // acclient.c:897508
void __cdecl _E139_78()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A730) --------------------------------------------------------  // acclient.c:897521
void __cdecl _E142_73()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A760) --------------------------------------------------------  // acclient.c:897534
void __cdecl _E145_75()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A790) --------------------------------------------------------  // acclient.c:897547
void __cdecl _E148_71()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A7C0) --------------------------------------------------------  // acclient.c:897560
void __cdecl _E151_69()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A7F0) --------------------------------------------------------  // acclient.c:897573
void __cdecl _E154_70()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A820) --------------------------------------------------------  // acclient.c:897586
void __cdecl _E157_66()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A850) --------------------------------------------------------  // acclient.c:897599
void __cdecl _E160_69()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_29;
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

//----- (0076A890) --------------------------------------------------------  // acclient.c:897624
void __cdecl _E163_62()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_29;
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

//----- (0076A8D0) --------------------------------------------------------  // acclient.c:897649
void __cdecl _E166_64()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_29;
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

//----- (0076A910) --------------------------------------------------------  // acclient.c:897674
void __cdecl _E169_63()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_29;
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

//----- (0076A950) --------------------------------------------------------  // acclient.c:897699
void __cdecl _E172_61()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_29;
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

//----- (0076A990) --------------------------------------------------------  // acclient.c:897724
void __cdecl _E175_58()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_53;
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

