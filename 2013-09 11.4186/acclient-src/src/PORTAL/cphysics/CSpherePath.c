/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSpherePath
   Object     : PORTAL\cphysics\CSpherePath.obj
   Functions  : 17
   Addresses  : 0050C330 - 006FB4A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0050C330) --------------------------------------------------------  // acclient.c:313430
void __thiscall SPHEREPATH::init(SPHEREPATH *this)
{
  this->num_sphere = 0;
  this->begin_cell = 0;
  this->begin_pos = 0;
  this->curr_cell = 0;
  this->check_cell = 0;
  this->insert_type = 0;
  this->step_down = 0;
  this->step_up = 0;
  this->collide = 0;
  this->hits_interior_cell = 0;
  this->bldg_check = 0;
  this->obstruction_ethereal = 0;
  this->backup_cell = 0;
  LODWORD(this->walkable_allowance) = 0;
  this->walkable = 0;
  this->check_walkable = 0;
  this->cell_array_valid = 0;
  this->neg_step_up = 0;
  this->neg_poly_hit = 0;
  this->placement_allows_sliding = 1;
}

//----- (0050C3B0) --------------------------------------------------------  // acclient.c:313455
signed int __thiscall SPHEREPATH::step_up_slide(SPHEREPATH *this, OBJECTINFO *object, COLLISIONINFO *collisions)
{
  AC1Legacy::Vector3 *v3; // ST0C_4@1

  collisions->contact_plane_valid = 0;
  collisions->contact_plane_is_water = 0;
  v3 = this->global_curr_center;
  this->step_up = 0;
  return CSphere::slide_sphere(this->global_sphere, this, collisions, &this->step_up_normal, v3);
}

//----- (0050C3E0) --------------------------------------------------------  // acclient.c:313467
int __thiscall SPHEREPATH::check_walkables(SPHEREPATH *this)
{
  SPHEREPATH *v1; // eax@1
  CPolygon *v2; // ecx@1
  int result; // eax@2
  double v4; // st7@3
  AC1Legacy::Vector3 *v5; // ST04_4@3
  int v6; // eax@3

  v1 = this;
  v2 = this->walkable;
  if ( v2 )
  {
    v4 = v1->walkable_check_pos.radius * 0.5;
    v5 = &v1->walkable_up;
    v6 = (int)&v1->walkable_check_pos;
    *(float *)(v6 + 12) = v4;
    result = (int)CPolygon::check_walkable(v2, (CSphere *)v6, v5);
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0050C420) --------------------------------------------------------  // acclient.c:313494
AC1Legacy::Vector3 *__thiscall Position::globaltolocalvec(Position *this, AC1Legacy::Vector3 *result, AC1Legacy::Vector3 *v)
{
  double v3; // st7@1
  double v4; // st6@1
  AC1Legacy::Vector3 *v5; // eax@1

  v3 = this->frame.m_fl2gv[7] * v->y + this->frame.m_fl2gv[6] * v->x + this->frame.m_fl2gv[8] * v->z;
  v4 = this->frame.m_fl2gv[4] * v->y + this->frame.m_fl2gv[3] * v->x + this->frame.m_fl2gv[5] * v->z;
  v5 = result;
  result->x = this->frame.m_fl2gv[1] * v->y + this->frame.m_fl2gv[0] * v->x + this->frame.m_fl2gv[2] * v->z;
  result->y = v4;
  result->z = v3;
  return v5;
}

//----- (0050C480) --------------------------------------------------------  // acclient.c:313510
void __thiscall SPHEREPATH::SPHEREPATH(SPHEREPATH *this)
{
  SPHEREPATH *v1; // esi@1
  char *v2; // ecx@1
  int v3; // edi@1
  int v4; // ecx@1
  int v5; // ecx@1
  int v6; // ecx@1
  int v7; // ecx@1
  void *v8; // eax@1
  int v9; // eax@2
  void *v10; // eax@4
  int v11; // eax@5
  void *v12; // eax@7

  v1 = this;
  v2 = (char *)&this->localspace_pos.frame;
  v3 = 0;
  v1->localspace_pos.objcell_id = 0;
  v1->localspace_pos.vfptr = (PackObjVtbl *)&Position::vftable;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  v4 = (int)&v1->curr_pos.frame;
  v1->curr_pos.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->curr_pos.objcell_id = 0;
  *(_DWORD *)v4 = 1065353216;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = 0;
  *(_DWORD *)(v4 + 52) = 0;
  *(_DWORD *)(v4 + 56) = 0;
  *(_DWORD *)(v4 + 60) = 0;
  Frame::cache(&v1->curr_pos.frame);
  v5 = (int)&v1->check_pos.frame;
  v1->check_pos.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->check_pos.objcell_id = 0;
  *(_DWORD *)v5 = 1065353216;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  *(_DWORD *)(v5 + 52) = 0;
  *(_DWORD *)(v5 + 56) = 0;
  *(_DWORD *)(v5 + 60) = 0;
  Frame::cache(&v1->check_pos.frame);
  v6 = (int)&v1->backup_check_pos.frame;
  v1->backup_check_pos.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->backup_check_pos.objcell_id = 0;
  *(_DWORD *)v6 = 1065353216;
  *(_DWORD *)(v6 + 4) = 0;
  *(_DWORD *)(v6 + 8) = 0;
  *(_DWORD *)(v6 + 12) = 0;
  *(_DWORD *)(v6 + 52) = 0;
  *(_DWORD *)(v6 + 56) = 0;
  *(_DWORD *)(v6 + 60) = 0;
  Frame::cache(&v1->backup_check_pos.frame);
  v7 = (int)&v1->walkable_pos.frame;
  v1->walkable_pos.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->walkable_pos.objcell_id = 0;
  *(_DWORD *)v7 = 1065353216;
  *(_DWORD *)(v7 + 4) = 0;
  *(_DWORD *)(v7 + 8) = 0;
  *(_DWORD *)(v7 + 12) = 0;
  *(_DWORD *)(v7 + 52) = 0;
  *(_DWORD *)(v7 + 56) = 0;
  *(_DWORD *)(v7 + 60) = 0;
  Frame::cache(&v1->walkable_pos.frame);
  v8 = operator new[](0x24u);
  if ( v8 )
  {
    *(_DWORD *)v8 = 2;
    v9 = (int)((char *)v8 + 4);
  }
  else
  {
    v9 = 0;
  }
  v1->local_sphere = (CSphere *)v9;
  v10 = operator new[](0x24u);
  if ( v10 )
  {
    *(_DWORD *)v10 = 2;
    v11 = (int)((char *)v10 + 4);
  }
  else
  {
    v11 = 0;
  }
  v1->global_sphere = (CSphere *)v11;
  v12 = operator new[](0x24u);
  if ( v12 )
  {
    *(_DWORD *)v12 = 2;
    v3 = (int)((char *)v12 + 4);
  }
  v1->localspace_sphere = (CSphere *)v3;
  v1->localspace_curr_center = (AC1Legacy::Vector3 *)operator new[](0x18u);
  v1->global_curr_center = (AC1Legacy::Vector3 *)operator new[](0x18u);
  SPHEREPATH::init(v1);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (0050C5F0) --------------------------------------------------------  // acclient.c:313618
void __thiscall SPHEREPATH::~SPHEREPATH(SPHEREPATH *this)
{
  SPHEREPATH *v1; // esi@1
  CSphere *v2; // eax@1
  CSphere *v3; // eax@3
  CSphere *v4; // eax@5

  v1 = this;
  v2 = this->local_sphere;
  if ( v2 )
    operator delete[](&v2[-1].radius);
  v3 = v1->global_sphere;
  if ( v3 )
    operator delete[](&v3[-1].radius);
  v4 = v1->localspace_sphere;
  if ( v4 )
    operator delete[](&v4[-1].radius);
  operator delete[](v1->localspace_curr_center);
  operator delete[](v1->global_curr_center);
  v1->walkable_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->backup_check_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->check_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->curr_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->localspace_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0050C670) --------------------------------------------------------  // acclient.c:313646
void __thiscall SPHEREPATH::init_sphere(SPHEREPATH *this, const unsigned int _num_sphere, CSphere *_sphere, const float _scale)
{
  unsigned int v4; // esi@4
  char *v5; // eax@5
  int v6; // edi@5
  float v7; // ST24_4@6
  float v8; // ST10_4@6
  char *v9; // ebx@6
  float v10; // ST14_4@6
  CSphere *v11; // eax@7
  char *v12; // ecx@7
  float v13; // ST14_4@7
  double v14; // st6@7
  float v15; // ST18_4@7

  if ( _num_sphere <= 2 )
    this->num_sphere = _num_sphere;
  else
    this->num_sphere = 2;
  v4 = 0;
  if ( this->num_sphere )
  {
    v5 = (char *)&_sphere->center.z;
    v6 = -8 - (_DWORD)_sphere;
    do
    {
      v7 = _scale * *(float *)v5;
      v8 = _scale * *((float *)v5 - 2);
      v9 = &v5[v6] + (unsigned int)this->local_sphere;
      v10 = _scale * *((float *)v5 - 1);
      *(float *)v9 = v8;
      *((float *)v9 + 1) = v10;
      *((float *)v9 + 2) = v7;
      ++v4;
      *(float *)(&v5[(unsigned int)this->local_sphere + 12] + v6) = _scale * *((float *)v5 + 1);
      v5 += 16;
    }
    while ( v4 < this->num_sphere );
  }
  v11 = this->local_sphere;
  v12 = (char *)&this->local_low_point;
  v13 = v11->center.y;
  v14 = v11->center.z - v11->radius;
  *(_DWORD *)v12 = LODWORD(v11->center.x);
  v15 = v14;
  *((float *)v12 + 1) = v13;
  *((float *)v12 + 2) = v15;
}

//----- (0050C740) --------------------------------------------------------  // acclient.c:313696
void __thiscall SPHEREPATH::cache_global_curr_center(SPHEREPATH *this)
{
  unsigned int v1; // edi@1
  int v2; // esi@2
  int v3; // edx@2
  CSphere *v4; // eax@3
  double v5; // st7@3
  int v6; // eax@3
  float v7; // ST0C_4@3
  float v8; // ST10_4@3
  double v9; // st7@3
  double v10; // st6@3
  AC1Legacy::Vector3 *v11; // eax@3
  double v12; // st7@3
  float v13; // ST14_4@3

  v1 = 0;
  if ( this->num_sphere )
  {
    v2 = 0;
    v3 = 0;
    do
    {
      v4 = this->local_sphere;
      v5 = v4[v3].center.x;
      v6 = (int)&v4[v3];
      ++v3;
      v7 = v5 * this->curr_pos.frame.m_fl2gv[0]
         + *(float *)(v6 + 4) * this->curr_pos.frame.m_fl2gv[3]
         + *(float *)(v6 + 8) * this->curr_pos.frame.m_fl2gv[6]
         + this->curr_pos.frame.m_fOrigin.x;
      v8 = this->curr_pos.frame.m_fl2gv[7] * *(float *)(v6 + 8)
         + *(float *)v6 * this->curr_pos.frame.m_fl2gv[1]
         + this->curr_pos.frame.m_fl2gv[4] * *(float *)(v6 + 4)
         + this->curr_pos.frame.m_fOrigin.y;
      v9 = this->curr_pos.frame.m_fl2gv[8] * *(float *)(v6 + 8) + this->curr_pos.frame.m_fl2gv[5] * *(float *)(v6 + 4);
      v10 = this->curr_pos.frame.m_fl2gv[2] * *(float *)v6;
      v11 = &this->global_curr_center[v2];
      ++v1;
      ++v2;
      v12 = v9 + v10 + this->curr_pos.frame.m_fOrigin.z;
      v11->x = v7;
      v11->y = v8;
      v13 = v12;
      v11->z = v13;
    }
    while ( v1 < this->num_sphere );
  }
}

//----- (0050C810) --------------------------------------------------------  // acclient.c:313747
void __thiscall SPHEREPATH::cache_global_sphere(SPHEREPATH *this, AC1Legacy::Vector3 *offset)
{
  unsigned int v2; // eax@1
  unsigned int v3; // esi@1
  int v4; // edi@3
  CSphere *v5; // eax@4
  double v6; // st7@4
  int v7; // eax@4
  int v8; // edx@7
  CSphere *v9; // eax@8
  double v10; // st7@8
  int v11; // eax@8
  float v12; // ST08_4@8
  float v13; // ST0C_4@8
  double v14; // st7@8
  double v15; // st6@8
  CSphere *v16; // eax@8
  double v17; // st7@8
  float v18; // ST10_4@8
  double v19; // st7@9
  char *v20; // ecx@9
  float v21; // ST08_4@9
  float v22; // ST0C_4@9
  double v23; // st7@9
  float v24; // ST10_4@9

  v2 = this->num_sphere;
  v3 = 0;
  if ( offset )
  {
    if ( v2 )
    {
      v4 = 0;
      do
      {
        v5 = this->global_sphere;
        v6 = v5[v4].center.x;
        v7 = (int)&v5[v4];
        ++v3;
        ++v4;
        *(float *)v7 = v6 + offset->x;
        *(float *)(v7 + 4) = offset->y + *(float *)(v7 + 4);
        *(float *)(v7 + 8) = offset->z + *(float *)(v7 + 8);
      }
      while ( v3 < this->num_sphere );
    }
    this->global_low_point.x = offset->x + this->global_low_point.x;
    this->global_low_point.y = offset->y + this->global_low_point.y;
    this->global_low_point.z = offset->z + this->global_low_point.z;
  }
  else
  {
    if ( v2 )
    {
      v8 = 0;
      do
      {
        this->global_sphere[v8].radius = this->local_sphere[v8].radius;
        v9 = this->local_sphere;
        v10 = v9[v8].center.x;
        v11 = (int)&v9[v8];
        v12 = v10 * this->check_pos.frame.m_fl2gv[0]
            + *(float *)(v11 + 4) * this->check_pos.frame.m_fl2gv[3]
            + *(float *)(v11 + 8) * this->check_pos.frame.m_fl2gv[6]
            + this->check_pos.frame.m_fOrigin.x;
        v13 = this->check_pos.frame.m_fl2gv[7] * *(float *)(v11 + 8)
            + *(float *)v11 * this->check_pos.frame.m_fl2gv[1]
            + this->check_pos.frame.m_fl2gv[4] * *(float *)(v11 + 4)
            + this->check_pos.frame.m_fOrigin.y;
        v14 = this->check_pos.frame.m_fl2gv[8] * *(float *)(v11 + 8) + this->check_pos.frame.m_fl2gv[2] * *(float *)v11;
        v15 = this->check_pos.frame.m_fl2gv[5] * *(float *)(v11 + 4);
        v16 = &this->global_sphere[v8];
        ++v3;
        ++v8;
        v17 = v14 + v15 + this->check_pos.frame.m_fOrigin.z;
        v16->center.x = v12;
        v16->center.y = v13;
        v18 = v17;
        v16->center.z = v18;
      }
      while ( v3 < this->num_sphere );
    }
    v19 = this->check_pos.frame.m_fl2gv[6];
    v20 = (char *)&this->global_low_point;
    v21 = v19 * *((float *)v20 - 2)
        + *((float *)v20 + 67) * *((float *)v20 - 4)
        + *((float *)v20 + 70) * *((float *)v20 - 3)
        + *((float *)v20 + 76);
    v22 = *((float *)v20 + 74) * *((float *)v20 - 2)
        + *((float *)v20 + 68) * *((float *)v20 - 4)
        + *((float *)v20 + 71) * *((float *)v20 - 3)
        + *((float *)v20 + 77);
    v23 = *((float *)v20 + 75) * *((float *)v20 - 2)
        + *((float *)v20 + 69) * *((float *)v20 - 4)
        + *((float *)v20 + 72) * *((float *)v20 - 3)
        + *((float *)v20 + 78);
    *(float *)v20 = v21;
    *((float *)v20 + 1) = v22;
    v24 = v23;
    *((float *)v20 + 2) = v24;
  }
}

//----- (0050C9D0) --------------------------------------------------------  // acclient.c:313851
void __thiscall SPHEREPATH::cache_localspace_sphere(SPHEREPATH *this, Position *p, const float scale)
{
  SPHEREPATH *v3; // esi@1
  int v4; // ebp@1
  int v5; // edi@2
  AC1Legacy::Vector3 *v6; // eax@3
  int v7; // edx@3
  float v8; // ST40_4@3
  double v9; // st7@3
  float v10; // ST20_4@3
  float v11; // ST24_4@3
  AC1Legacy::Vector3 *v12; // eax@3
  int v13; // ecx@3
  float v14; // ST4C_4@3
  double v15; // st7@3
  float v16; // ST2C_4@3
  float v17; // ST30_4@3
  int v18; // edx@4
  int v19; // ecx@4
  float v20; // ST2C_4@4
  float v21; // ST30_4@4
  double v22; // st7@4
  float v23; // ST34_4@4
  CSphere *v24; // ecx@4
  float v25; // ST24_4@4
  float v26; // ST28_4@4
  float v27; // ST2C_4@4
  float v28; // ST30_4@4
  double v29; // st7@4
  int v30; // esi@4
  float v31; // ST34_4@4
  unsigned int i; // [sp+4h] [bp-4Ch]@1
  AC1Legacy::Vector3 result; // [sp+38h] [bp-18h]@3
  AC1Legacy::Vector3 v34; // [sp+44h] [bp-Ch]@3
  float scalea; // [sp+58h] [bp+8h]@1

  v3 = this;
  v4 = 0;
  i = 0;
  scalea = 1.0 / scale;
  if ( this->num_sphere )
  {
    v5 = 0;
    do
    {
      v3->localspace_sphere[v5].radius = scalea * v3->local_sphere[v5].radius;
      v6 = Position::localtolocal(p, &result, &v3->check_pos, &v3->local_sphere[v5].center);
      v7 = (int)&v3->localspace_sphere[v5];
      v8 = scalea * v6->z;
      v9 = scalea * v6->y;
      v10 = scalea * v6->x;
      *(float *)v7 = v10;
      v11 = v9;
      *(float *)(v7 + 4) = v11;
      *(float *)(v7 + 8) = v8;
      v12 = Position::localtolocal(p, &v34, &v3->curr_pos, &v3->local_sphere[v5].center);
      v13 = (int)&v3->localspace_curr_center[v4];
      ++v5;
      ++v4;
      v14 = scalea * v12->z;
      v15 = scalea * v12->y;
      v16 = scalea * v12->x;
      *(float *)v13 = v16;
      v17 = v15;
      *(float *)(v13 + 4) = v17;
      *(float *)(v13 + 8) = v14;
      ++i;
    }
    while ( i < v3->num_sphere );
  }
  v3->localspace_pos.objcell_id = p->objcell_id;
  v18 = (int)&v3->localspace_pos.frame.m_fOrigin;
  *(_DWORD *)v18 = LODWORD(p->frame.m_fOrigin.x);
  *(_DWORD *)(v18 + 4) = LODWORD(p->frame.m_fOrigin.y);
  *(_DWORD *)(v18 + 8) = LODWORD(p->frame.m_fOrigin.z);
  v3->localspace_pos.frame.qw = p->frame.qw;
  v3->localspace_pos.frame.qx = p->frame.qx;
  v3->localspace_pos.frame.qy = p->frame.qy;
  v3->localspace_pos.frame.qz = p->frame.qz;
  v3->localspace_pos.frame.m_fl2gv[0] = p->frame.m_fl2gv[0];
  v3->localspace_pos.frame.m_fl2gv[1] = p->frame.m_fl2gv[1];
  v3->localspace_pos.frame.m_fl2gv[2] = p->frame.m_fl2gv[2];
  v3->localspace_pos.frame.m_fl2gv[3] = p->frame.m_fl2gv[3];
  v3->localspace_pos.frame.m_fl2gv[4] = p->frame.m_fl2gv[4];
  v3->localspace_pos.frame.m_fl2gv[5] = p->frame.m_fl2gv[5];
  v3->localspace_pos.frame.m_fl2gv[6] = p->frame.m_fl2gv[6];
  v3->localspace_pos.frame.m_fl2gv[7] = p->frame.m_fl2gv[7];
  v3->localspace_pos.frame.m_fl2gv[8] = p->frame.m_fl2gv[8];
  v19 = (int)&v3->localspace_z;
  v20 = (p->frame.m_fl2gv[1] + p->frame.m_fl2gv[0]) * 0.0 + p->frame.m_fl2gv[2];
  v21 = (p->frame.m_fl2gv[4] + p->frame.m_fl2gv[3]) * 0.0 + p->frame.m_fl2gv[5];
  v22 = (p->frame.m_fl2gv[7] + p->frame.m_fl2gv[6]) * 0.0 + p->frame.m_fl2gv[8];
  *(float *)v19 = v20;
  *(float *)(v19 + 4) = v21;
  v23 = v22;
  *(float *)(v19 + 8) = v23;
  v24 = v3->localspace_sphere;
  v25 = v24->radius * v3->localspace_z.y;
  v26 = v24->radius * v3->localspace_z.z;
  v27 = v24->center.x - v24->radius * v3->localspace_z.x;
  v28 = v24->center.y - v25;
  v29 = v24->center.z - v26;
  v30 = (int)&v3->localspace_low_point;
  *(float *)v30 = v27;
  v31 = v29;
  *(float *)(v30 + 4) = v28;
  *(float *)(v30 + 8) = v31;
}

//----- (0050CC00) --------------------------------------------------------  // acclient.c:313961
void __thiscall SPHEREPATH::adjust_check_pos(SPHEREPATH *this, unsigned int cell_id)
{
  SPHEREPATH *v2; // esi@1
  AC1Legacy::Vector3 offset; // [sp+8h] [bp-Ch]@2

  v2 = this;
  if ( (unsigned __int16)cell_id < 0x100u )
  {
    LandDefs::get_block_offset(&offset, cell_id, this->check_pos.objcell_id);
    SPHEREPATH::cache_global_sphere(v2, &offset);
    v2->check_pos.frame.m_fOrigin.x = offset.x + v2->check_pos.frame.m_fOrigin.x;
    v2->check_pos.frame.m_fOrigin.y = offset.y + v2->check_pos.frame.m_fOrigin.y;
    v2->check_pos.frame.m_fOrigin.z = offset.z + v2->check_pos.frame.m_fOrigin.z;
  }
  v2->check_pos.objcell_id = cell_id;
}

//----- (0050CC80) --------------------------------------------------------  // acclient.c:313979
signed int __thiscall SPHEREPATH::precipice_slide(SPHEREPATH *this, COLLISIONINFO *collisions)
{
  SPHEREPATH *v2; // esi@1
  signed int v3; // eax@2
  double v4; // st7@3
  AC1Legacy::Vector3 *v5; // ebx@3
  CSphere *v6; // edi@3
  double v7; // st7@3
  double v8; // st6@3
  unsigned int v9; // ST0C_4@3
  unsigned int v10; // ST08_4@3
  double v11; // st7@3
  double v12; // st6@3
  AC1Legacy::Vector3 normal; // [sp+4h] [bp-3Ch]@1
  float v14; // [sp+10h] [bp-30h]@3
  float v15; // [sp+14h] [bp-2Ch]@3
  float v16; // [sp+18h] [bp-28h]@3
  AC1Legacy::Vector3 result; // [sp+1Ch] [bp-24h]@3
  float v18; // [sp+30h] [bp-10h]@3
  float v19; // [sp+34h] [bp-Ch]@3

  v2 = this;
  if ( CPolygon::find_crossed_edge(this->walkable, &this->walkable_check_pos, &this->walkable_up, &normal) )
  {
    v4 = normal.z;
    v2->walkable = 0;
    v2->step_up = 0;
    v5 = v2->global_curr_center;
    v6 = v2->global_sphere;
    v14 = v4 * v2->walkable_pos.frame.m_fl2gv[6]
        + normal.x * v2->walkable_pos.frame.m_fl2gv[0]
        + normal.y * v2->walkable_pos.frame.m_fl2gv[3];
    v15 = normal.z * v2->walkable_pos.frame.m_fl2gv[7]
        + normal.x * v2->walkable_pos.frame.m_fl2gv[1]
        + normal.y * v2->walkable_pos.frame.m_fl2gv[4];
    v7 = normal.z * v2->walkable_pos.frame.m_fl2gv[8];
    v8 = normal.x;
    normal = *(AC1Legacy::Vector3 *)&v14;
    v9 = v2->check_pos.objcell_id;
    v10 = v2->curr_pos.objcell_id;
    v16 = v7 + v8 * v2->walkable_pos.frame.m_fl2gv[2] + normal.y * v2->walkable_pos.frame.m_fl2gv[5];
    LandDefs::get_block_offset(&result, v10, v9);
    v11 = v6->center.x - v5->x;
    v12 = v6->center.y - v5->y;
    v18 = v6->center.z - v5->z;
    v19 = result.x + v11;
    if ( v16 * (result.z + v18) + (result.y + v12) * v15 + v19 * v14 > 0.0 )
    {
      normal.x = v14 * -1.0;
      normal.y = normal.y * -1.0;
      normal.z = normal.z * -1.0;
    }
    v3 = CSphere::slide_sphere(v6, v2, collisions, &normal, v5);
  }
  else
  {
    v2->walkable = 0;
    v3 = 2;
  }
  return v3;
}

//----- (0050CE20) --------------------------------------------------------  // acclient.c:314042
void __thiscall SPHEREPATH::init_path(SPHEREPATH *this, CObjCell *_begin_cell, Position *_begin_pos, Position *_end_pos)
{
  SPHEREPATH *v4; // esi@1

  v4 = this;
  this->begin_cell = _begin_cell;
  this->begin_pos = _begin_pos;
  this->end_pos = _end_pos;
  if ( _begin_pos )
  {
    this->curr_pos.objcell_id = _begin_pos->objcell_id;
    Frame::operator=((int)&this->curr_pos.frame, (int)&_begin_pos->frame);
    v4->curr_cell = _begin_cell;
    SPHEREPATH::cache_global_curr_center(v4);
    v4->insert_type = 0;
  }
  else
  {
    this->curr_pos.objcell_id = _end_pos->objcell_id;
    Frame::operator=((int)&this->curr_pos.frame, (int)&_end_pos->frame);
    v4->curr_cell = _begin_cell;
    SPHEREPATH::cache_global_curr_center(v4);
    v4->insert_type = 1;
  }
}

//----- (006FB440) --------------------------------------------------------  // acclient.c:783803
void sub_6FB440()
{
  flt_843B90 = 1000.0 + 1.0;
}

//----- (006FB460) --------------------------------------------------------  // acclient.c:783809
void sub_6FB460()
{
  flt_843B94 = 24.0 * 8.0;
}

//----- (006FB480) --------------------------------------------------------  // acclient.c:783815
void sub_6FB480()
{
  flt_843B98 = 24.0 * 0.5;
}

//----- (006FB4A0) --------------------------------------------------------  // acclient.c:783821
int sub_6FB4A0()
{
  return atexit(nullsub_1080);
}

