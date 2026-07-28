/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CLandCell
   Object     : PORTAL\ccell\CLandCell.obj
   Functions  : 97
   Addresses  : 00532C70 - 00769B80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00532C70) --------------------------------------------------------  // acclient.c:354817
void __thiscall CLandCell::CLandCell(CLandCell *this)
{
  CLandCell *v1; // esi@1

  v1 = this;
  CSortCell::CSortCell((CSortCell *)&this->vfptr);
  v1->vfptr = (InterfaceVtbl *)&CLandCell::vftable;
  v1->vfptr = (PackObjVtbl *)&CLandCell::vftable;
  v1->vfptr = (CPartCellVtbl *)&CLandCell::vftable;
  v1->polygons = (CPolygon **)operator new[](8u);
  v1->in_view = 0;
}
// 7C92EC: using guessed type void (__thiscall *CLandCell::vftable)(CSortCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32 num_shadow_parts);
// 7C92F8: using guessed type void *CLandCell::vftable;
// 7C9310: using guessed type __int32 (__stdcall *CLandCell::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00532CB0) --------------------------------------------------------  // acclient.c:354834
BoundingType __thiscall CLandCell::IsInView(CLandCell *this)
{
  return this->in_view;
}

//----- (00532CC0) --------------------------------------------------------  // acclient.c:354840
void __thiscall CLandCell::~CLandCell(CLandCell *this)
{
  CSortCell *v1; // esi@1
  CPolygon **v2; // ST00_4@1

  v1 = (CSortCell *)this;
  v2 = this->polygons;
  this->vfptr = (InterfaceVtbl *)&CLandCell::vftable;
  this->vfptr = (PackObjVtbl *)&CLandCell::vftable;
  this->vfptr = (CPartCellVtbl *)&CLandCell::vftable;
  operator delete[](v2);
  CSortCell::~CSortCell(v1);
}
// 7C92EC: using guessed type void (__thiscall *CLandCell::vftable)(CSortCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32 num_shadow_parts);
// 7C92F8: using guessed type void *CLandCell::vftable;
// 7C9310: using guessed type __int32 (__stdcall *CLandCell::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00532CF0) --------------------------------------------------------  // acclient.c:354858
int __thiscall CLandCell::find_terrain_poly(CLandCell *this, AC1Legacy::Vector3 *origin, CPolygon **walkable)
{
  CLandCell *v3; // edi@1
  signed int v4; // esi@1
  int result; // eax@2

  v3 = this;
  v4 = 0;
  while ( 1 )
  {
    result = CPolygon::point_in_poly2D(v3->polygons[v4], origin, 0);
    if ( result )
      break;
    ++v4;
    if ( v4 >= 2 )
      return result;
  }
  *walkable = v3->polygons[v4];
  return 1;
}

//----- (00532D40) --------------------------------------------------------  // acclient.c:354880
BOOL __thiscall CLandCell::point_in_cell(CLandCell *this, AC1Legacy::Vector3 *point)
{
  return CLandCell::find_terrain_poly(this, point, (CPolygon **)&point) != 0;
}

//----- (00532D60) --------------------------------------------------------  // acclient.c:354886
signed int __thiscall CLandCell::find_collisions(CLandCell *this, CTransition *transition)
{
  CSortCell *v2; // esi@1
  signed int result; // eax@1

  v2 = (CSortCell *)this;
  result = ((int (__stdcall *)(_DWORD))this->vfptr[5].Release)(transition);
  if ( result == 1 )
  {
    result = CSortCell::find_collisions(v2, transition);
    if ( result == 1 )
      result = CObjCell::find_obj_collisions((CObjCell *)&v2->vfptr, transition);
  }
  return result;
}

//----- (00532D90) --------------------------------------------------------  // acclient.c:354903
void CLandCell::grab_visible_cells()
{
  LScape::grab_visible_cells(CObjCell::landscape);
}

//----- (00532DA0) --------------------------------------------------------  // acclient.c:354909
void CLandCell::release_cells()
{
  LScape::release_visible_cells(CObjCell::landscape);
}

//----- (00532DB0) --------------------------------------------------------  // acclient.c:354915
unsigned int __cdecl CLandCell::Get(unsigned int cell_id)
{
  return LScape::get_landcell(CObjCell::landscape, cell_id);
}

//----- (00532DE0) --------------------------------------------------------  // acclient.c:354921
signed int __stdcall CLandCell::Trace(LOSParameters *_los)
{
  signed int result; // eax@2

  if ( _los->m_bCheckedOutside )
  {
    result = 0;
  }
  else
  {
    _los->m_bCheckedOutside = 1;
    result = 2;
  }
  return result;
}

//----- (00532E00) --------------------------------------------------------  // acclient.c:354938
void *__thiscall CLandCell::vector_deleting_destructor(CLandCell *this, unsigned int a2)
{
  return CLandCell::vector_deleting_destructor((CLandCell *)((char *)this - 48), a2);
}

//----- (00532E10) --------------------------------------------------------  // acclient.c:354944
void *__thiscall CLandCell::vector_deleting_destructor(CLandCell *this, unsigned int a2)
{
  return CLandCell::vector_deleting_destructor((CLandCell *)((char *)this - 56), a2);
}

//----- (00532E20) --------------------------------------------------------  // acclient.c:354950
SURFCHAR __thiscall CLandCell::find_terrain(CLandCell *this, Position *pos)
{
  CLandCell *v2; // esi@1
  AC1Legacy::Vector3 vc; // [sp+4h] [bp-54h]@1
  Position cell_pos; // [sp+10h] [bp-48h]@1

  v2 = this;
  cell_pos.vfptr = (PackObjVtbl *)&Position::vftable;
  cell_pos.objcell_id = 0;
  LODWORD(cell_pos.frame.qw) = 1065353216;
  LODWORD(cell_pos.frame.qx) = 0;
  LODWORD(cell_pos.frame.qy) = 0;
  LODWORD(cell_pos.frame.qz) = 0;
  LODWORD(cell_pos.frame.m_fOrigin.x) = 0;
  LODWORD(cell_pos.frame.m_fOrigin.y) = 0;
  LODWORD(cell_pos.frame.m_fOrigin.z) = 0;
  Frame::cache(&cell_pos.frame);
  cell_pos.objcell_id = v2->m_DID.id;
  Position::get_offset(&cell_pos, &vc, pos);
  return TERRAIN_SURF_CHAR_0[CLandBlock::get_terrain(v2->myLandBlock_, v2->m_DID.id, &vc)];
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00532EC0) --------------------------------------------------------  // acclient.c:354974
void __cdecl CLandCell::add_outside_cell(CELLARRAY *cell_array, int x, int y)
{
  unsigned int v3; // eax@5

  if ( x >= 0 && y >= 0 && x < 2040 && y < 2040 )
  {
    v3 = LScape::get_landcell(
           CObjCell::landscape,
           (((y >> 3) | 32 * (x & 0xFFFFFFF8)) << 16) | ((y & 7) + 8 * (x & 7) + 1));
    CELLARRAY::add_cell(
      cell_array,
      (((y >> 3) | 32 * (x & 0xFFFFFFF8)) << 16) | ((y & 7) + 8 * (x & 7) + 1),
      (CObjCell *)v3);
  }
}

//----- (00532F20) --------------------------------------------------------  // acclient.c:354991
signed int __thiscall CLandCell::find_env_collisions(CLandCell *this, CTransition *transition)
{
  CTransition *v2; // ebp@1
  CLandCell *v3; // edi@1
  signed int v4; // eax@1
  signed int v5; // ebx@1
  unsigned int v6; // eax@2
  unsigned int v7; // ecx@2
  AC1Legacy::Vector3 *v8; // eax@2
  double v9; // st7@2
  double v10; // st6@2
  float water_depth; // ST2C_4@7
  CSphere *v12; // eax@7
  unsigned int v13; // ebx@7
  unsigned int v14; // ST14_4@7
  AC1Legacy::Vector3 *v15; // eax@7
  LandDefs::WaterType v16; // edi@7
  AC1Legacy::Vector3 local_point; // [sp+10h] [bp-28h]@2
  AC1Legacy::Vector3 result; // [sp+1Ch] [bp-1Ch]@2
  CSphere check_pos; // [sp+28h] [bp-10h]@7

  v2 = transition;
  v3 = this;
  v4 = CObjCell::check_entry_restrictions((CObjCell *)&this->vfptr, transition);
  v5 = v4;
  if ( v4 == 1 )
  {
    v6 = v3->m_DID.id;
    v7 = v2->sphere_path.check_pos.objcell_id;
    transition = 0;
    v8 = LandDefs::get_block_offset(&result, v7, v6);
    v9 = v2->sphere_path.global_low_point.z - v8->z;
    v10 = v2->sphere_path.global_low_point.y - v8->y;
    local_point.x = v2->sphere_path.global_low_point.x - v8->x;
    local_point.y = v10;
    local_point.z = v9;
    if ( CLandCell::find_terrain_poly(v3, &local_point, (CPolygon **)&transition) )
    {
      if ( CObjCell::get_block_water_type((CObjCell *)&v3->vfptr) == 2
        && !(v2->object_info.state & 4)
        && !(v2->object_info.object->state & 0x40) )
        return 2;
      water_depth = CObjCell::get_water_depth((CObjCell *)&v3->vfptr, &local_point);
      v12 = v2->sphere_path.global_sphere;
      v13 = v3->m_DID.id;
      check_pos.center.x = v12->center.x;
      check_pos.center.y = v12->center.y;
      check_pos.center.z = v12->center.z;
      v14 = v2->sphere_path.check_pos.objcell_id;
      check_pos.radius = v12->radius;
      v15 = LandDefs::get_block_offset(&result, v14, v13);
      v16 = v3->water_type;
      check_pos.center.x = check_pos.center.x - v15->x;
      check_pos.center.y = check_pos.center.y - v15->y;
      check_pos.center.z = check_pos.center.z - v15->z;
      v5 = OBJECTINFO::validate_walkable(
             &v2->object_info,
             &check_pos,
             (Plane *)&transition->sphere_path,
             v16 != 0,
             water_depth,
             &v2->sphere_path,
             &v2->collision_info,
             v13);
    }
    v4 = v5;
  }
  return v4;
}

//----- (00533070) --------------------------------------------------------  // acclient.c:355062
int __thiscall CLandCell::handle_move_restriction(CLandCell *this, CTransition *transition)
{
  CTransition *v2; // esi@1
  bool v3; // c0@5
  AC1Legacy::Vector3 normal; // [sp+4h] [bp-18h]@7
  AC1Legacy::Vector3 offset; // [sp+10h] [bp-Ch]@1
  float transitiona; // [sp+20h] [bp+4h]@1

  v2 = transition;
  Position::get_offset(&this->pos, &offset, &transition->sphere_path.curr_pos);
  transitiona = -flt_844CF0;
  if ( offset.y >= (double)transitiona )
  {
    if ( offset.y <= (double)flt_844CF0 )
    {
      LODWORD(offset.y) = 0;
      v3 = offset.x < (double)transitiona;
      LODWORD(offset.x) = -1082130432;
      if ( !v3 )
        LODWORD(offset.x) = 1065353216;
    }
    else
    {
      LODWORD(offset.x) = 0;
      LODWORD(offset.y) = 1065353216;
    }
  }
  else
  {
    LODWORD(offset.x) = 0;
    LODWORD(offset.y) = -1082130432;
  }
  LODWORD(normal.x) = (_DWORD)offset.x;
  LODWORD(offset.z) = 0;
  normal.y = offset.y;
  LODWORD(normal.z) = 0;
  COLLISIONINFO::set_collision_normal(&v2->collision_info, &normal);
  return 1;
}

//----- (00533140) --------------------------------------------------------  // acclient.c:355103
double __thiscall CLandCell::GetViewerDistance(CLandCell *this, AC1Legacy::Vector3 *diff_vec)
{
  AC1Legacy::Vector3 *v2; // eax@1
  double v3; // st7@1
  double v4; // st6@1
  AC1Legacy::Vector3 result; // [sp+4h] [bp-Ch]@1

  v2 = Position::get_offset(&Render::viewer_pos, &result, &this->pos);
  diff_vec->x = v2->x;
  diff_vec->y = v2->y;
  diff_vec->z = v2->z;
  v3 = diff_vec->y;
  v4 = diff_vec->x;
  LODWORD(diff_vec->z) = 0;
  return sqrt(v4 * v4 + v3 * v3);
}

//----- (00533190) --------------------------------------------------------  // acclient.c:355121
SURFCHAR __thiscall CLandCell::walkable_surface_type(CLandCell *this, CPolygon *walkable, Position *pos)
{
  CPolygon **v3; // edx@1
  signed int v4; // eax@1

  v3 = this->polygons;
  v4 = 0;
  while ( walkable != *v3 )
  {
    ++v4;
    ++v3;
    if ( v4 >= 2 )
      return 0;
  }
  return CLandCell::find_terrain(this, pos);
}

//----- (005331D0) --------------------------------------------------------  // acclient.c:355139
void __cdecl CLandCell::add_cell_block(int min_x, int min_y, int max_x, int max_y, CELLARRAY *cell_array)
{
  int i; // ebx@1
  int j; // edi@2
  unsigned int v7; // esi@7
  unsigned int v8; // eax@7

  for ( i = min_x; i <= max_x; ++i )
  {
    for ( j = min_y; j <= max_y; ++j )
    {
      if ( i >= 0 && j >= 0 && i < 2040 && j < 2040 )
      {
        v7 = (((j >> 3) | 32 * (i & 0xFFFFFFF8)) << 16) | ((j & 7) + 8 * (i & 7) + 1);
        v8 = LScape::get_landcell(CObjCell::landscape, v7);
        CELLARRAY::add_cell(cell_array, v7, (CObjCell *)v8);
      }
    }
  }
}

//----- (00533260) --------------------------------------------------------  // acclient.c:355161
void __cdecl CLandCell::check_add_cell_boundary(CELLARRAY *cell_array, Vec2D *pt, int x, int y, float incell_max, float incell_min)
{
  int v6; // ebx@2
  int v7; // ebx@7

  if ( pt->x > (double)incell_max )
  {
    v6 = x + 1;
    CLandCell::add_outside_cell(cell_array, x + 1, y);
    if ( pt->y > (double)incell_max )
      CLandCell::add_outside_cell(cell_array, v6, y + 1);
    if ( pt->y < (double)incell_min )
      CLandCell::add_outside_cell(cell_array, v6, y - 1);
  }
  if ( pt->x < (double)incell_min )
  {
    v7 = x - 1;
    CLandCell::add_outside_cell(cell_array, x - 1, y);
    if ( pt->y > (double)incell_max )
      CLandCell::add_outside_cell(cell_array, v7, y + 1);
    if ( pt->y < (double)incell_min )
      CLandCell::add_outside_cell(cell_array, v7, y - 1);
  }
  if ( pt->y > (double)incell_max )
    CLandCell::add_outside_cell(cell_array, x, y + 1);
  if ( pt->y < (double)incell_min )
    CLandCell::add_outside_cell(cell_array, x, y - 1);
}

//----- (00533360) --------------------------------------------------------  // acclient.c:355191
void __cdecl CLandCell::add_all_outside_cells(const unsigned int num_parts, CPhysicsPart **parts, CELLARRAY *cell_array)
{
  const unsigned int v3; // eax@2
  const unsigned int v4; // edi@3
  CPhysicsPart **v5; // ebx@4
  CPhysicsPart *v6; // eax@7
  float v7; // ecx@7
  float v8; // edx@7
  float v9; // ecx@7
  float v10; // edx@7
  int v11; // eax@7
  int v12; // esi@7
  const unsigned int v13; // edi@13
  CPhysicsPart *v14; // ecx@14
  CPhysicsPart *v15; // eax@16
  CGfxObj *v16; // ecx@16
  CSphere *v17; // ecx@17
  float v18; // edx@19
  int v19; // esi@19
  int v20; // ebx@19
  unsigned __int64 v21; // rax@19
  double v22; // st7@19
  BBox *v23; // eax@20
  unsigned __int64 v24; // rax@21
  int v25; // esi@21
  int v26; // ebx@23
  int v27; // eax@27
  float radius; // [sp+18h] [bp-50h]@7
  int max_y; // [sp+1Ch] [bp-4Ch]@3
  int max_x; // [sp+20h] [bp-48h]@3
  int min_y; // [sp+24h] [bp-44h]@3
  int min_x; // [sp+28h] [bp-40h]@3
  int max_xc; // [sp+2Ch] [bp-3Ch]@9
  CObjCell *cell; // [sp+30h] [bp-38h]@11
  int lx; // [sp+34h] [bp-34h]@13
  int ly; // [sp+38h] [bp-30h]@13
  int y; // [sp+3Ch] [bp-2Ch]@12
  int x; // [sp+40h] [bp-28h]@12
  AC1Legacy::Vector3 loc; // [sp+44h] [bp-24h]@7
  BBox box; // [sp+50h] [bp-18h]@20

  if ( !cell_array->added_outside )
  {
    cell_array->added_outside = 1;
    v3 = num_parts;
    if ( num_parts )
    {
      v4 = 0;
      min_x = 0;
      min_y = 0;
      max_x = 0;
      max_y = 0;
      if ( num_parts <= 0 )
      {
        v5 = parts;
LABEL_9:
        v12 = max_xc;
      }
      else
      {
        while ( 1 )
        {
          v5 = parts;
          if ( parts[v4] )
            break;
          ++v4;
          if ( v4 >= num_parts )
            goto LABEL_9;
        }
        v6 = parts[v4];
        v7 = v6->pos.frame.m_fOrigin.x;
        v8 = v6->pos.frame.m_fOrigin.y;
        v6 = (CPhysicsPart *)((char *)v6 + 48);
        loc.x = v7;
        v9 = v6->pos.frame.qz;
        loc.y = v8;
        v10 = v6->viewer_heading.x;
        loc.z = v9;
        radius = v10;
        v11 = LandDefs::adjust_to_outside((unsigned int *)&radius, &loc);
        v12 = v11 != 0 ? LODWORD(radius) : 0;
        v3 = num_parts;
      }
      if ( v4 != v3 )
      {
        cell = (CObjCell *)LScape::get_landcell(CObjCell::landscape, v12);
        if ( cell )
        {
          if ( LandDefs::gid_to_lcoord(v12, &x, &y) )
          {
            lx = ((unsigned int)(unsigned __int16)v12 - 1) >> 3;
            v13 = 0;
            ly = ((_BYTE)v12 - 1) & 7;
            if ( num_parts )
            {
              do
              {
                v14 = v5[v13];
                if ( v14 )
                {
                  if ( CPhysicsPart::Always2D(v14) )
                  {
                    v15 = v5[v13];
                    v16 = *v15->gfxobj;
                    if ( v16->physics_sphere )
                      v17 = v16->physics_sphere;
                    else
                      v17 = v16->drawing_sphere;
                    v18 = v17->radius;
                    loc.x = v15->pos.frame.m_fOrigin.x;
                    radius = v18;
                    loc.y = v15->pos.frame.m_fOrigin.y;
                    v19 = (unsigned __int64)_floor((loc.x - v18) / 24.0);
                    v20 = (unsigned __int64)_floor((loc.y - radius) / 24.0);
                    v21 = (unsigned __int64)_floor((loc.x + radius) / 24.0);
                    v22 = loc.y + radius;
                  }
                  else
                  {
                    v23 = CPhysicsPart::GetBoundingBox(v5[v13]);
                    BBox::LocalToGlobal(&box, v23, &v5[v13]->pos, &cell->pos);
                    v19 = (unsigned __int64)_floor(box.m_vMin.x / 24.0);
                    v20 = (unsigned __int64)_floor(box.m_vMin.y / 24.0);
                    v21 = (unsigned __int64)_floor(box.m_vMax.x / 24.0);
                    v22 = box.m_vMax.y;
                  }
                  max_xc = v21;
                  v24 = (unsigned __int64)_floor(v22 / 24.0);
                  v25 = v19 - lx;
                  if ( v25 < min_x )
                    min_x = v25;
                  v26 = v20 - ly;
                  if ( v26 < min_y )
                    min_y = v26;
                  if ( max_xc - lx > max_x )
                    max_x = max_xc - lx;
                  v5 = parts;
                  v27 = v24 - ly;
                  if ( v27 > max_y )
                    max_y = v27;
                }
                ++v13;
              }
              while ( v13 < num_parts );
            }
            CLandCell::add_cell_block(min_x + x, min_y + y, x + max_x, y + max_y, cell_array);
          }
        }
      }
    }
  }
}

//----- (00533630) --------------------------------------------------------  // acclient.c:355345
void __cdecl CLandCell::add_all_outside_cells(Position *p, const unsigned int num_sphere, CSphere *sphere, CELLARRAY *cell_array)
{
  unsigned int v4; // edi@2
  char *v5; // esi@3
  float v6; // edx@4
  float v7; // ecx@4
  unsigned __int64 v8; // rax@5
  int v9; // edi@6
  int v10; // ebx@6
  float v11; // edx@9
  float v12; // ecx@9
  unsigned int v13; // edx@9
  int y; // [sp+18h] [bp-30h]@5
  int x; // [sp+1Ch] [bp-2Ch]@5
  unsigned int pt_cell; // [sp+20h] [bp-28h]@4
  float min_rad; // [sp+24h] [bp-24h]@5
  unsigned int i; // [sp+28h] [bp-20h]@3
  int xc; // [sp+2Ch] [bp-1Ch]@5
  float max_rad; // [sp+30h] [bp-18h]@5
  Vec2D pt1; // [sp+34h] [bp-14h]@5
  AC1Legacy::Vector3 point; // [sp+3Ch] [bp-Ch]@4

  if ( !cell_array->added_outside )
  {
    v4 = num_sphere;
    cell_array->added_outside = 1;
    if ( num_sphere )
    {
      i = 0;
      v5 = (char *)&sphere->center.z;
      do
      {
        v6 = *(float *)v5;
        v7 = *((float *)v5 - 1);
        LODWORD(point.x) = *((_DWORD *)v5 - 2);
        point.z = v6;
        point.y = v7;
        pt_cell = p->objcell_id;
        if ( !LandDefs::adjust_to_outside(&pt_cell, &point) )
          break;
        DeleteLeafTransactInfo::DynamicCast_DeleteLeaf();
        xc = (unsigned __int64)_floor(point.x / 24.0);
        v8 = (unsigned __int64)_floor(point.y / 24.0);
        min_rad = *((float *)v5 + 1);
        pt1.x = point.x - (double)xc * 24.0;
        pt1.y = point.y - (double)(signed int)v8 * 24.0;
        max_rad = 24.0 - min_rad;
        if ( LandDefs::gid_to_lcoord(pt_cell, &x, &y) )
        {
          v9 = y;
          v10 = x;
          CLandCell::add_outside_cell(cell_array, x, y);
          CLandCell::check_add_cell_boundary(cell_array, &pt1, v10, v9, max_rad, min_rad);
          v4 = num_sphere;
        }
        gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&pt1);
        v5 += 16;
        ++i;
      }
      while ( i < v4 );
    }
    else
    {
      v11 = p->frame.m_fOrigin.y;
      point.x = p->frame.m_fOrigin.x;
      v12 = p->frame.m_fOrigin.z;
      point.y = v11;
      v13 = p->objcell_id;
      point.z = v12;
      i = v13;
      if ( LandDefs::adjust_to_outside(&i, &point) && LandDefs::gid_to_lcoord(i, &x, &y) )
        CLandCell::add_outside_cell(cell_array, x, y);
    }
  }
}

//----- (00533800) --------------------------------------------------------  // acclient.c:355422
void __thiscall CLandCell::find_transit_cells(CLandCell *this, Position *p, const unsigned int num_sphere, CSphere *sphere, CELLARRAY *cell_array, SPHEREPATH *path)
{
  CSortCell *v6; // esi@1

  v6 = (CSortCell *)this;
  CLandCell::add_all_outside_cells(p, num_sphere, sphere, cell_array);
  CSortCell::find_transit_cells(v6, p, num_sphere, sphere, cell_array, path);
}

//----- (00533840) --------------------------------------------------------  // acclient.c:355432
void __thiscall CLandCell::find_transit_cells(CLandCell *this, const unsigned int num_parts, CPhysicsPart **parts, CELLARRAY *cell_array)
{
  CSortCell *v4; // esi@1

  v4 = (CSortCell *)this;
  CLandCell::add_all_outside_cells(num_parts, parts, cell_array);
  CSortCell::find_transit_cells(v4, num_parts, parts, cell_array);
}

//----- (006FF050) --------------------------------------------------------  // acclient.c:787119
void sub_6FF050()
{
  flt_844CE8 = 1000.0 + 1.0;
}

//----- (006FF070) --------------------------------------------------------  // acclient.c:787125
void sub_6FF070()
{
  flt_844CEC = 24.0 * 8.0;
}

//----- (006FF090) --------------------------------------------------------  // acclient.c:787131
void sub_6FF090()
{
  flt_844CF0 = 24.0 * 0.5;
}

//----- (006FF0B0) --------------------------------------------------------  // acclient.c:787137
void sub_6FF0B0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_844CF4, PFID_A8R8G8B8);
}

//----- (006FF0C0) --------------------------------------------------------  // acclient.c:787143
int _E99_31()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_27, "Render.TextureFiltering");
  return atexit(sub_769580);
}

//----- (006FF0E0) --------------------------------------------------------  // acclient.c:787150
int _E102_18()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_27, "Render.LandscapeDetailTextures");
  return atexit(sub_7695B0);
}

//----- (006FF100) --------------------------------------------------------  // acclient.c:787157
int _E105_34()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_27, "Render.BuildingDetailTextures");
  return atexit(sub_7695E0);
}

//----- (006FF120) --------------------------------------------------------  // acclient.c:787164
int _E108_73()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_27, "Render.FieldOfView");
  return atexit(sub_769610);
}

//----- (006FF140) --------------------------------------------------------  // acclient.c:787171
int _E111_40()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_27, "Render.LandscapeTextureDetail");
  return atexit(sub_769640);
}

//----- (006FF160) --------------------------------------------------------  // acclient.c:787178
int _E114_47()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_27, "Render.EnvironmentTextureDetail");
  return atexit(sub_769670);
}

//----- (006FF180) --------------------------------------------------------  // acclient.c:787185
int _E117_58()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_27, "Render.SceneryDrawDistance");
  return atexit(sub_7696A0);
}

//----- (006FF1A0) --------------------------------------------------------  // acclient.c:787192
int _E120_55()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_27, "Render.LandscapeDrawDistance");
  return atexit(sub_7696D0);
}

//----- (006FF1C0) --------------------------------------------------------  // acclient.c:787199
int _E123_33()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_27, "Render.ScreenBrightness");
  return atexit(sub_769700);
}

//----- (006FF1E0) --------------------------------------------------------  // acclient.c:787206
int _E126_39()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_27, "Render.AspectRatio");
  return atexit(sub_769730);
}

//----- (006FF200) --------------------------------------------------------  // acclient.c:787213
int _E129_31()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_27, "Render.DisplayAdapter");
  return atexit(sub_769760);
}

//----- (006FF220) --------------------------------------------------------  // acclient.c:787220
int _E132_34()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_27, "Render.MaxHardwareClass");
  return atexit(_E133_93);
}

//----- (006FF240) --------------------------------------------------------  // acclient.c:787227
int _E135_37()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_27, "Render.AutomaticDegrades");
  return atexit(_E136_76);
}

//----- (006FF260) --------------------------------------------------------  // acclient.c:787234
int _E138_29()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_27, "Render.GraphicsPerformance");
  return atexit(_E139_76);
}

//----- (006FF280) --------------------------------------------------------  // acclient.c:787241
int _E141_29()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_27, "Render.DegradeDistance");
  return atexit(_E142_71);
}

//----- (006FF2A0) --------------------------------------------------------  // acclient.c:787248
int _E144_28()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_27, "Render.MultiPassAlpha");
  return atexit(_E145_73);
}

//----- (006FF2C0) --------------------------------------------------------  // acclient.c:787255
int _E147_26()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_27, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_844D70, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_844D74, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_844D78, "Anisotropic");
  return atexit(_E148_69);
}

//----- (006FF310) --------------------------------------------------------  // acclient.c:787265
int _E150_26()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_27, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_844D80, "Low");
  PStringBase<char>::PStringBase<char>(&stru_844D84, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_844D88, "High");
  PStringBase<char>::PStringBase<char>(&stru_844D8C, "VeryHigh");
  return atexit(_E151_67);
}

//----- (006FF370) --------------------------------------------------------  // acclient.c:787276
int _E153_24()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_27, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_844D94, "Low");
  PStringBase<char>::PStringBase<char>(&stru_844D98, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_844D9C, "High");
  PStringBase<char>::PStringBase<char>(&stru_844DA0, "VeryHigh");
  return atexit(_E154_68);
}

//----- (006FF3D0) --------------------------------------------------------  // acclient.c:787287
int _E156_26()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_27, "Low");
  PStringBase<char>::PStringBase<char>(&stru_844DA8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_844DAC, "High");
  return atexit(_E157_64);
}

//----- (006FF410) --------------------------------------------------------  // acclient.c:787296
int _E159_24()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_27, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_844DB4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_844DB8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_844DBC, "High");
  PStringBase<char>::PStringBase<char>(&stru_844DC0, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_844DC4, "Extreme");
  return atexit(_E160_67);
}

//----- (006FF480) --------------------------------------------------------  // acclient.c:787308
int _E162_26()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_27, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_844DCC, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_844DD0, "Wide");
  return atexit(_E163_60);
}

//----- (006FF4C0) --------------------------------------------------------  // acclient.c:787317
int _E165_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_51, "None");
  return atexit(_E166_62);
}

//----- (006FF4E0) --------------------------------------------------------  // acclient.c:787324
int _E168_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_51, "Speed");
  return atexit(_E169_61);
}

//----- (006FF500) --------------------------------------------------------  // acclient.c:787331
int _E171_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_51, "Noise");
  return atexit(_E172_59);
}

//----- (006FF520) --------------------------------------------------------  // acclient.c:787338
int _E174_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_51, "Sine");
  return atexit(_E175_56);
}

//----- (006FF540) --------------------------------------------------------  // acclient.c:787345
int _E177_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_51, "Square");
  return atexit(_E178_56);
}

//----- (006FF560) --------------------------------------------------------  // acclient.c:787352
int _E180_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_51, "Bounce");
  return atexit(_E181_56);
}

//----- (006FF580) --------------------------------------------------------  // acclient.c:787359
int _E183_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_51, "Perlin");
  return atexit(_E184_53);
}

//----- (006FF5A0) --------------------------------------------------------  // acclient.c:787366
int _E186_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_51, "Fractal");
  return atexit(_E187_52);
}

//----- (006FF5C0) --------------------------------------------------------  // acclient.c:787373
int _E189_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_51, "FrameLoop");
  return atexit(_E190_53);
}

//----- (006FF5E0) --------------------------------------------------------  // acclient.c:787380
void _E192_17()
{
  dword_844DF8 = 1024;
}

//----- (006FF5F0) --------------------------------------------------------  // acclient.c:787386
void _E194_5()
{
  dword_844DFC = 0x7FFF;
}

//----- (006FF600) --------------------------------------------------------  // acclient.c:787392
int _E196_18()
{
  const int result; // eax@1

  result = dword_844DF8;
  INITIAL_MAX_DATA_RATE_89 = dword_844DF8;
  return result;
}

//----- (006FF610) --------------------------------------------------------  // acclient.c:787402
void _E198_15()
{
  flt_844E04 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FF630) --------------------------------------------------------  // acclient.c:787408
void _E200_3()
{
  dbl_844E08 = 1.0 / 30.0;
}

//----- (006FF650) --------------------------------------------------------  // acclient.c:787414
void _E202_15()
{
  dbl_844E10 = 1.0 / 5.0;
}

//----- (006FF670) --------------------------------------------------------  // acclient.c:787420
int sub_6FF670()
{
  return atexit(nullsub_1160);
}

//----- (00769580) --------------------------------------------------------  // acclient.c:896272
void __cdecl sub_769580()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007695B0) --------------------------------------------------------  // acclient.c:896285
void __cdecl sub_7695B0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007695E0) --------------------------------------------------------  // acclient.c:896298
void __cdecl sub_7695E0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769610) --------------------------------------------------------  // acclient.c:896311
void __cdecl sub_769610()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769640) --------------------------------------------------------  // acclient.c:896324
void __cdecl sub_769640()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769670) --------------------------------------------------------  // acclient.c:896337
void __cdecl sub_769670()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007696A0) --------------------------------------------------------  // acclient.c:896350
void __cdecl sub_7696A0()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007696D0) --------------------------------------------------------  // acclient.c:896363
void __cdecl sub_7696D0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769700) --------------------------------------------------------  // acclient.c:896376
void __cdecl sub_769700()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769730) --------------------------------------------------------  // acclient.c:896389
void __cdecl sub_769730()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769760) --------------------------------------------------------  // acclient.c:896402
void __cdecl sub_769760()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769790) --------------------------------------------------------  // acclient.c:896415
void __cdecl _E133_93()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007697C0) --------------------------------------------------------  // acclient.c:896428
void __cdecl _E136_76()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007697F0) --------------------------------------------------------  // acclient.c:896441
void __cdecl _E139_76()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769820) --------------------------------------------------------  // acclient.c:896454
void __cdecl _E142_71()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769850) --------------------------------------------------------  // acclient.c:896467
void __cdecl _E145_73()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769880) --------------------------------------------------------  // acclient.c:896480
void __cdecl _E148_69()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_27;
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

//----- (007698C0) --------------------------------------------------------  // acclient.c:896505
void __cdecl _E151_67()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_27;
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

//----- (00769900) --------------------------------------------------------  // acclient.c:896530
void __cdecl _E154_68()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_27;
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

//----- (00769940) --------------------------------------------------------  // acclient.c:896555
void __cdecl _E157_64()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_27;
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

//----- (00769980) --------------------------------------------------------  // acclient.c:896580
void __cdecl _E160_67()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_27;
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

//----- (007699C0) --------------------------------------------------------  // acclient.c:896605
void __cdecl _E163_60()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_51;
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

//----- (00769A00) --------------------------------------------------------  // acclient.c:896630
void __cdecl _E166_62()
{
  char *v0; // esi@1

  v0 = &waveform_None_51.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_51.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769A30) --------------------------------------------------------  // acclient.c:896643
void __cdecl _E169_61()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_51.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_51.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769A60) --------------------------------------------------------  // acclient.c:896656
void __cdecl _E172_59()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_51.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_51.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769A90) --------------------------------------------------------  // acclient.c:896669
void __cdecl _E175_56()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_51.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_51.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769AC0) --------------------------------------------------------  // acclient.c:896682
void __cdecl _E178_56()
{
  char *v0; // esi@1

  v0 = &waveform_Square_51.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_51.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769AF0) --------------------------------------------------------  // acclient.c:896695
void __cdecl _E181_56()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_51.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_51.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769B20) --------------------------------------------------------  // acclient.c:896708
void __cdecl _E184_53()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_51.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_51.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769B50) --------------------------------------------------------  // acclient.c:896721
void __cdecl _E187_52()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_51.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_51.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769B80) --------------------------------------------------------  // acclient.c:896734
void __cdecl _E190_53()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_51.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_51.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

