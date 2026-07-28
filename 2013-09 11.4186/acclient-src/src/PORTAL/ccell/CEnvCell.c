/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CEnvCell
   Object     : PORTAL\ccell\CEnvCell.obj
   Functions  : 126
   Addresses  : 0052C0C0 - 00769250 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0052C0C0) --------------------------------------------------------  // acclient.c:347797
bool __thiscall CEnvCell::GetDrawnThisFrame(CEnvCell *this)
{
  return this->m_current_render_frame_num == RenderDevice::render_device->m_nFrameStamp;
}

//----- (0052C0E0) --------------------------------------------------------  // acclient.c:347803
void __thiscall CEnvCell::SetDrawnThisFrame(CEnvCell *this)
{
  this->m_current_render_frame_num = RenderDevice::render_device->m_nFrameStamp;
}

//----- (0052C100) --------------------------------------------------------  // acclient.c:347809
signed int __thiscall CEnvCell::find_collisions(CEnvCell *this, CTransition *transition)
{
  CObjCell *v2; // esi@1
  signed int result; // eax@1

  v2 = (CObjCell *)this;
  result = ((int (__stdcall *)(_DWORD))this->vfptr[5].Release)(transition);
  if ( result == 1 )
    result = CObjCell::find_obj_collisions(v2, transition);
  return result;
}

//----- (0052C130) --------------------------------------------------------  // acclient.c:347822
signed int __thiscall CEnvCell::find_env_collisions(CEnvCell *this, CTransition *transition)
{
  CEnvCell *v2; // esi@1
  signed int result; // eax@1

  v2 = this;
  result = CObjCell::check_entry_restrictions((CObjCell *)&this->vfptr, transition);
  if ( result == 1 )
  {
    transition->sphere_path.obstruction_ethereal = 0;
    if ( v2->structure->physics_bsp )
    {
      SPHEREPATH::cache_localspace_sphere(&transition->sphere_path, &v2->pos, 1.0);
      if ( transition->sphere_path.insert_type == 2 )
        result = BSPTREE::placement_insert(v2->structure->physics_bsp, transition);
      else
        result = BSPTREE::find_collisions(v2->structure->physics_bsp, transition, 1.0);
      if ( result != 1 && !(transition->object_info.state & 1) )
        transition->collision_info.collided_with_environment = 1;
    }
  }
  return result;
}

//----- (0052C1D0) --------------------------------------------------------  // acclient.c:347853
int __thiscall CEnvCell::pack_size(CEnvCell *this)
{
  CEnvCell *v1; // esi@1
  unsigned int v2; // ebp@1
  unsigned int v3; // edi@1
  int v4; // ebx@2
  CCellPortal *v5; // ecx@3
  unsigned int v6; // ecx@4
  int result; // eax@4

  v1 = this;
  v2 = this->num_surfaces;
  v3 = 0;
  if ( this->num_portals )
  {
    v4 = 0;
    do
    {
      v5 = v1->portals;
      v2 += TextureVelocityHook::pack_size();
      ++v3;
      v4 += 24;
    }
    while ( v3 < v1->num_portals );
  }
  v6 = v1->num_static_objects;
  result = v2 + 2 * v1->num_stabs;
  if ( v6 )
    result += 32 * v6 + 4;
  if ( v1->restriction_obj )
    result += 4;
  return result;
}

//----- (0052C240) --------------------------------------------------------  // acclient.c:347888
void __thiscall CEnvCell::CEnvCell(CEnvCell *this)
{
  CEnvCell *v1; // esi@1

  v1 = this;
  CObjCell::CObjCell((CObjCell *)&this->vfptr);
  v1->num_surfaces = 0;
  v1->surfaces = 0;
  v1->structure = 0;
  v1->env = 0;
  v1->num_portals = 0;
  v1->portals = 0;
  v1->num_static_objects = 0;
  v1->static_object_ids = 0;
  v1->static_object_frames = 0;
  v1->static_objects = 0;
  v1->vfptr = (InterfaceVtbl *)&CEnvCell::vftable;
  v1->vfptr = (PackObjVtbl *)&CEnvCell::vftable;
  v1->vfptr = (CPartCellVtbl *)&CEnvCell::vftable;
  v1->portal_view.data = 0;
  v1->portal_view.sizeOf = 0;
  v1->portal_view.next_available = 0;
  v1->portal_view.blocksize = 128;
  v1->incell_timestamp = 0;
  v1->num_view = 0;
  v1->light_array = 0;
  v1->constructed_mesh = 0;
  v1->use_built_mesh = 0;
}
// 7C8C74: using guessed type void (__thiscall *CEnvCell::vftable)(CPartCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32);
// 7C8C80: using guessed type void *CEnvCell::vftable;
// 7C8C98: using guessed type __int32 (__stdcall *CEnvCell::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0052C2E0) --------------------------------------------------------  // acclient.c:347922
CEnvCell *__thiscall CEnvCell::vector_deleting_destructor(CEnvCell *this, unsigned int a2)
{
  return CEnvCell::scalar_deleting_destructor((CEnvCell *)((char *)this - 48), a2);
}

//----- (0052C2F0) --------------------------------------------------------  // acclient.c:347928
CEnvCell *__thiscall CEnvCell::vector_deleting_destructor(CEnvCell *this, unsigned int a2)
{
  return CEnvCell::scalar_deleting_destructor((CEnvCell *)((char *)this - 56), a2);
}

//----- (0052C300) --------------------------------------------------------  // acclient.c:347934
int __thiscall CEnvCell::point_in_cell(CEnvCell *this, AC1Legacy::Vector3 *point)
{
  CEnvCell *v2; // esi@1
  int result; // eax@2
  AC1Legacy::Vector3 localpoint; // [sp+4h] [bp-Ch]@3

  v2 = this;
  if ( this->portals )
  {
    Frame::globaltolocal(&this->pos.frame, &localpoint, point);
    result = CCellStruct::point_in_cell(v2->structure, &localpoint);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0052C350) --------------------------------------------------------  // acclient.c:347954
void __thiscall CEnvCell::init_static_objects(CEnvCell *this)
{
  CEnvCell *v1; // esi@1
  unsigned int v2; // ebx@2
  CPhysicsObj **v3; // eax@3
  CPhysicsObj *v4; // edi@3
  unsigned int v5; // eax@8
  unsigned int v6; // edi@9
  int v7; // ebx@10
  IDClass<_tagDataID,32,0> v8; // eax@11
  CPhysicsObj *v9; // ecx@14

  v1 = this;
  if ( this->static_objects )
  {
    v2 = 0;
    if ( this->num_static_objects )
    {
      do
      {
        v3 = v1->static_objects;
        v4 = v3[v2];
        if ( v4 )
        {
          if ( !CPhysicsObj::is_completely_visible(v3[v2]) )
            CPhysicsObj::calc_cross_cells_static(v4);
        }
        ++v2;
      }
      while ( v2 < v1->num_static_objects );
    }
  }
  else
  {
    v5 = this->num_static_objects;
    if ( v5 )
    {
      this->static_objects = (CPhysicsObj **)operator new[](4 * v5);
      v6 = 0;
      if ( v1->num_static_objects )
      {
        v7 = 0;
        do
        {
          v8.id = v1->static_object_ids[v6].id;
          if ( v8.id )
            v1->static_objects[v6] = CPhysicsObj::makeObject(v8, 0, 0);
          else
            v1->static_objects[v6] = 0;
          v9 = v1->static_objects[v6];
          if ( v9 )
            CPhysicsObj::add_obj_to_cell(v9, (CObjCell *)&v1->vfptr, &v1->static_object_frames[v7]);
          ++v6;
          ++v7;
        }
        while ( v6 < v1->num_static_objects );
      }
    }
  }
}

//----- (0052C430) --------------------------------------------------------  // acclient.c:348016
void __thiscall CEnvCell::setup_view(CEnvCell *this, unsigned int pres_view)
{
  Render::set_view(&this->portal_view.data[this->num_view - 1]->view, pres_view);
}

//----- (0052C460) --------------------------------------------------------  // acclient.c:348022
int __thiscall CEnvCell::PreFetchCells(CEnvCell *this, unsigned int *num_waiting_elements)
{
  CEnvCell *v2; // edi@1
  signed int v3; // ebp@1
  int v4; // esi@4
  QualifiedDataID *v5; // eax@4
  CACHE_OBJECT_CODES v6; // eax@4
  QualifiedDataID *v8; // eax@7
  int v9; // eax@7
  CLandBlock *v10; // ebx@7
  unsigned int v11; // esi@9
  QualifiedDataID *v12; // eax@9
  CACHE_OBJECT_CODES v13; // eax@9
  QualifiedDataID *v14; // eax@12
  int v15; // eax@12
  int v16; // ebx@12
  unsigned int v17; // edi@13
  unsigned int v18; // esi@13
  QualifiedDataID *v19; // eax@14
  CACHE_OBJECT_CODES v20; // eax@14
  CLandBlock *landblock; // [sp+Ch] [bp-20h]@4
  QualifiedDataID v22; // [sp+14h] [bp-18h]@7
  QualifiedDataID v23; // [sp+1Ch] [bp-10h]@9
  QualifiedDataID v24; // [sp+24h] [bp-8h]@14

  v2 = this;
  v3 = 1;
  if ( this->seen_outside
    && !LScape::PreFetchCells(
          CObjCell::landscape,
          (IDClass<_tagDataID,32,0>)(this->m_DID.id | 0xFFFF),
          num_waiting_elements) )
    v3 = 0;
  v4 = v2->m_DID.id | 0xFFFF;
  QualifiedDataID::QualifiedDataID((QualifiedDataID *)&landblock, (IDClass<_tagDataID,32,0>)v4, 1u);
  v6 = DBObj::PreFetch(v5);
  if ( v6 != 2 && v6 != 1 )
    return 0;
  QualifiedDataID::QualifiedDataID(&v22, (IDClass<_tagDataID,32,0>)v4, 1u);
  v9 = DBObj::Get(v8);
  v10 = (CLandBlock *)v9;
  landblock = (CLandBlock *)v9;
  if ( v9 )
  {
    if ( *(_DWORD *)(v9 + 236) )
    {
      v11 = v2->m_DID.id & 0xFFFFFFFE | 0xFFFE;
      QualifiedDataID::QualifiedDataID(&v23, (IDClass<_tagDataID,32,0>)v11, 2u);
      v13 = DBObj::PreFetch(v12);
      if ( v13 != 2 && v13 != 1 )
      {
        v10->vfptr->Release((Interface *)v10);
        return 0;
      }
      QualifiedDataID::QualifiedDataID(&v23, (IDClass<_tagDataID,32,0>)v11, 2u);
      v15 = DBObj::Get(v14);
      v16 = v15;
      if ( v15 )
      {
        v17 = v2->m_DID.id & 0xFFFF0100 | 0x100;
        v18 = 0;
        if ( *(_DWORD *)(v15 + 84) )
        {
          do
          {
            QualifiedDataID::QualifiedDataID(&v24, (IDClass<_tagDataID,32,0>)(v18 + v17), 3u);
            v20 = DBObj::PreFetch(v19);
            if ( v20 != 2 && v20 != 1 )
            {
              v3 = 0;
              if ( v20 == -1 )
                ++*num_waiting_elements;
            }
            ++v18;
          }
          while ( v18 < *(_DWORD *)(v16 + 84) );
        }
        (*(void (__thiscall **)(int))(*(_DWORD *)v16 + 20))(v16);
      }
      v10 = landblock;
    }
    v10->vfptr->Release((Interface *)v10);
  }
  return v3;
}

//----- (0052C5D0) --------------------------------------------------------  // acclient.c:348109
void __thiscall CEnvCell::check_building_transit(CEnvCell *this, int portal_id, Position *p, const unsigned int num_sphere, CSphere *sphere, CELLARRAY *cell_array, SPHEREPATH *path)
{
  CEnvCell *v7; // ebx@1
  const unsigned int v8; // edi@2
  CSphere *v9; // esi@3
  AC1Legacy::Vector3 *v10; // eax@4
  float v11; // ecx@4
  float v12; // eax@4
  CCellStruct *v13; // ecx@4
  AC1Legacy::Vector3 result; // [sp+4h] [bp-1Ch]@4
  CSphere v15; // [sp+10h] [bp-10h]@4

  v7 = this;
  if ( portal_id >= 0 )
  {
    v8 = 0;
    if ( num_sphere )
    {
      v9 = sphere;
      while ( 1 )
      {
        v10 = Frame::globaltolocal(&v7->pos.frame, &result, &v9->center);
        v15.center.x = v10->x;
        v11 = v9->radius;
        v15.center.y = v10->y;
        v12 = v10->z;
        v15.radius = v11;
        v13 = v7->structure;
        v15.center.z = v12;
        if ( CCellStruct::sphere_intersects_cell(v13, &v15) )
          break;
        ++v8;
        ++v9;
        if ( v8 >= num_sphere )
          return;
      }
      if ( path )
        path->hits_interior_cell = 1;
      CELLARRAY::add_cell(cell_array, v7->m_DID.id, (CObjCell *)&v7->vfptr);
    }
  }
}

//----- (0052C680) --------------------------------------------------------  // acclient.c:348153
void __thiscall CEnvCell::check_building_transit(CEnvCell *this, int portal_id, const unsigned int num_parts, CPhysicsPart **parts, CELLARRAY *cell_array)
{
  int v5; // ebp@1
  CEnvCell *v6; // ebx@1
  int v7; // eax@2
  CPhysicsPart *v8; // eax@5
  CGfxObj **v9; // edx@6
  CSphere *v10; // esi@6
  Position *v11; // edi@8
  double v12; // st7@8
  CCellPortal *v13; // edx@8
  CPolygon *v14; // esi@8
  int v15; // ebp@8
  int v16; // esi@8
  double v17; // st7@8
  BBox *v18; // ebx@13
  signed int v19; // eax@13
  unsigned int iq; // [sp+8h] [bp-4Ch]@2
  float radius; // [sp+Ch] [bp-48h]@8
  CObjCell *cell; // [sp+10h] [bp-44h]@1
  float neg_radius; // [sp+14h] [bp-40h]@8
  AC1Legacy::Vector3 center; // [sp+18h] [bp-3Ch]@8
  BBox box; // [sp+24h] [bp-30h]@13
  BBox cell_box; // [sp+3Ch] [bp-18h]@15

  v5 = portal_id;
  v6 = this;
  cell = (CObjCell *)this;
  if ( portal_id >= 0 )
  {
    v7 = 0;
    iq = 0;
    if ( num_parts )
    {
      while ( 1 )
      {
        v8 = parts[v7];
        if ( v8 )
        {
          v9 = v8->gfxobj;
          v10 = (*v9)->physics_sphere;
          if ( v10 || (v10 = (*v9)->drawing_sphere) != 0 )
          {
            v11 = &v6->pos;
            Position::localtolocal(&v6->pos, &center, &v8->pos, &v10->center);
            v12 = v10->radius + 0.00019999999;
            v13 = v6->portals;
            v14 = v13[v5].portal;
            v15 = v13[v5].portal_side;
            radius = v12;
            neg_radius = -v12;
            v16 = (int)&v14->plane;
            v17 = center.y * *(float *)(v16 + 4)
                + center.z * *(float *)(v16 + 8)
                + center.x * *(float *)v16
                + *(float *)(v16 + 12);
            if ( v15 == 1 )
            {
              if ( v17 > radius )
                goto LABEL_17;
            }
            else if ( !v15 && v17 < neg_radius )
            {
              goto LABEL_17;
            }
            v18 = CPhysicsPart::GetBoundingBox(parts[iq]);
            BBox::LocalToLocal(&box, v18, &parts[iq]->pos, v11);
            v19 = Plane::intersect_box((Plane *)v16, &box);
            if ( v19 == 3 || v19 == v15 )
            {
              BBox::LocalToLocal(&cell_box, v18, &parts[iq]->pos, v11);
              if ( CCellStruct::box_intersects_cell(*(CCellStruct **)&cell[1].m_bLoaded, &cell_box) )
              {
                CELLARRAY::add_cell(cell_array, cell->m_DID.id, cell);
                ((void (__thiscall *)(CObjCell *, const unsigned int, CPhysicsPart **, CELLARRAY *))cell->vfptr[5].IUnknown_AddRef)(
                  cell,
                  num_parts,
                  parts,
                  cell_array);
                return;
              }
            }
            v6 = (CEnvCell *)cell;
          }
        }
LABEL_17:
        v7 = iq++ + 1;
        if ( iq >= num_parts )
          return;
        v5 = portal_id;
      }
    }
  }
}

//----- (0052C820) --------------------------------------------------------  // acclient.c:348249
void __thiscall CEnvCell::find_transit_cells(CEnvCell *this, Position *p, const unsigned int num_sphere, CSphere *sphere, CELLARRAY *cell_array, SPHEREPATH *path)
{
  CEnvCell *v6; // esi@1
  unsigned int v7; // ebp@1
  int v8; // ecx@3
  const unsigned int v9; // edi@4
  int v10; // edx@5
  char *v11; // ecx@5
  double v12; // st7@6
  double v13; // st6@6
  double v14; // st5@6
  float v15; // ST30_4@6
  float v16; // ST34_4@6
  double v17; // st7@6
  RenderVertexStreamD3D *v18; // ebx@11
  const unsigned int v19; // ebp@12
  CSphere *v20; // edi@13
  AC1Legacy::Vector3 *v21; // eax@14
  float v22; // ecx@14
  float v23; // eax@14
  CCellStruct *v24; // ecx@14
  bool v25; // cf@17
  CSphere *v26; // edi@23
  AC1Legacy::Vector3 *v27; // eax@24
  double v28; // st7@24
  float v29; // ecx@24
  float localcenter; // ST24_4@24
  float v31; // edx@24
  CCellPortal *v32; // eax@24
  double v33; // st6@24
  int v34; // ecx@24
  double v35; // st6@24
  unsigned int i; // [sp+8h] [bp-4Ch]@2
  float ia; // [sp+8h] [bp-4Ch]@6
  unsigned int ib; // [sp+8h] [bp-4Ch]@22
  unsigned int iq; // [sp+Ch] [bp-48h]@1
  int check_outside; // [sp+10h] [bp-44h]@1
  AC1Legacy::Vector3 result; // [sp+2Ch] [bp-28h]@14
  AC1Legacy::Vector3 v42; // [sp+38h] [bp-1Ch]@24
  CSphere v43; // [sp+44h] [bp-10h]@14

  v6 = this;
  v7 = 0;
  check_outside = 0;
  iq = 0;
  if ( this->num_portals )
  {
    i = 0;
    do
    {
      v8 = (int)((char *)v6->portals + v7);
      if ( *(_DWORD *)v8 == -1 )
      {
        v9 = 0;
        if ( num_sphere )
        {
          v10 = *(_DWORD *)(v8 + 8) + 32;
          v11 = (char *)&sphere->center.z;
          while ( 1 )
          {
            v12 = *((float *)v11 - 2) - v6->pos.frame.m_fOrigin.x;
            v13 = *((float *)v11 - 1) - v6->pos.frame.m_fOrigin.y;
            v14 = *(float *)v11 - v6->pos.frame.m_fOrigin.z;
            v15 = v12 * v6->pos.frame.m_fl2gv[0] + v14 * v6->pos.frame.m_fl2gv[2] + v13 * v6->pos.frame.m_fl2gv[1];
            v16 = v12 * v6->pos.frame.m_fl2gv[3] + v14 * v6->pos.frame.m_fl2gv[5] + v13 * v6->pos.frame.m_fl2gv[4];
            ia = *((float *)v11 + 1) + 0.00019999999;
            v17 = (v14 * v6->pos.frame.m_fl2gv[8] + v13 * v6->pos.frame.m_fl2gv[7] + v12 * v6->pos.frame.m_fl2gv[6])
                * *(float *)(v10 + 8)
                + v16 * *(float *)(v10 + 4)
                + v15 * *(float *)v10
                + *(float *)(v10 + 12);
            if ( v17 > -ia && v17 < ia )
              break;
            ++v9;
            v11 += 16;
            if ( v9 >= num_sphere )
              goto LABEL_17;
          }
          check_outside = 1;
        }
      }
      else
      {
        v18 = CCellPortal::GetOtherCell((CCellPortal *)v8, cell_array->do_not_load_cells);
        if ( v18 )
        {
          v19 = 0;
          if ( num_sphere )
          {
            v20 = sphere;
            while ( 1 )
            {
              v21 = Frame::globaltolocal((Frame *)&v18->m_VertexFormatInfo.offsetWeight3, &result, &v20->center);
              v43.center.x = v21->x;
              v22 = v20->radius;
              v43.center.y = v21->y;
              v23 = v21->z;
              v43.radius = v22;
              v24 = (CCellStruct *)v18[1].m_VertexFormatInfo.numMatrices;
              v43.center.z = v23;
              if ( CCellStruct::sphere_intersects_cell(v24, &v43) )
                break;
              ++v19;
              ++v20;
              if ( v19 >= num_sphere )
                goto LABEL_16;
            }
            CELLARRAY::add_cell(cell_array, (const unsigned int)v18->m_pD3DVertexBuffer, (CObjCell *)v18);
          }
LABEL_16:
          v7 = i;
        }
        else
        {
          ib = 0;
          if ( num_sphere )
          {
            v26 = sphere;
            while ( 1 )
            {
              v27 = Frame::globaltolocal(&v6->pos.frame, &v42, &v26->center);
              v28 = v26->radius + 0.00019999999;
              v29 = v27->y;
              localcenter = v27->x;
              v31 = v27->z;
              v32 = v6->portals;
              v33 = v29;
              v34 = *(int *)((char *)&v32->portal_side + v7);
              v35 = v33 * (*(CPolygon **)((char *)&v32->portal + v7))->plane.N.y
                  + v31 * (*(CPolygon **)((char *)&v32->portal + v7))->plane.N.z
                  + localcenter * (*(CPolygon **)((char *)&v32->portal + v7))->plane.N.x
                  + (*(CPolygon **)((char *)&v32->portal + v7))->plane.d;
              if ( v35 > -v28 && v34 == 1 )
                break;
              if ( v35 < v28 && !v34 )
                break;
              ++v26;
              ++ib;
              if ( ib >= num_sphere )
                goto LABEL_17;
            }
            CELLARRAY::add_cell(cell_array, *(unsigned int *)((char *)&v6->portals->other_cell_id + v7), 0);
          }
        }
      }
LABEL_17:
      v7 += 24;
      v25 = iq++ + 1 < v6->num_portals;
      i = v7;
    }
    while ( v25 );
    if ( check_outside )
      CLandCell::add_all_outside_cells(p, num_sphere, sphere, cell_array);
  }
}

//----- (0052CAE0) --------------------------------------------------------  // acclient.c:348406
void __thiscall CEnvCell::find_transit_cells(CEnvCell *this, const unsigned int num_parts, CPhysicsPart **parts, CELLARRAY *cell_array)
{
  CEnvCell *v4; // ebp@1
  int v5; // eax@3
  CPhysicsPart *v6; // eax@4
  CGfxObj **v7; // edx@5
  CSphere *v8; // esi@5
  double v9; // st7@7
  CCellPortal *v10; // ecx@7
  int v11; // edi@7
  int v12; // esi@7
  double v13; // st7@7
  Position *v14; // ST08_4@12
  BBox *v15; // ebp@12
  CCellPortal *v16; // ecx@13
  RenderVertexStreamD3D *v17; // esi@14
  bool v18; // cf@23
  CEnvCell *v19; // [sp+4h] [bp-58h]@1
  int v20; // [sp+8h] [bp-54h]@2
  unsigned int jq; // [sp+Ch] [bp-50h]@3
  float radius; // [sp+10h] [bp-4Ch]@7
  unsigned int iq; // [sp+14h] [bp-48h]@1
  int check_outside; // [sp+18h] [bp-44h]@1
  float neg_radius; // [sp+1Ch] [bp-40h]@7
  AC1Legacy::Vector3 center; // [sp+20h] [bp-3Ch]@7
  BBox box; // [sp+2Ch] [bp-30h]@12
  BBox cell_box; // [sp+44h] [bp-18h]@15

  v4 = this;
  v19 = this;
  check_outside = 0;
  iq = 0;
  if ( this->num_portals )
  {
    v20 = 0;
    while ( 1 )
    {
      v5 = 0;
      jq = 0;
      if ( !num_parts )
        goto LABEL_23;
      while ( 1 )
      {
        v6 = parts[v5];
        if ( !v6 )
          goto LABEL_17;
        v7 = v6->gfxobj;
        v8 = (*v7)->physics_sphere;
        if ( !v8 )
        {
          v8 = (*v7)->drawing_sphere;
          if ( !v8 )
            goto LABEL_17;
        }
        Position::localtolocal(&v4->pos, &center, &v6->pos, &v8->center);
        v9 = v8->radius + 0.00019999999;
        v10 = v4->portals;
        v11 = v10[v20].portal_side;
        radius = v9;
        neg_radius = -v9;
        v12 = (int)&v10[v20].portal->plane;
        v13 = center.y * *(float *)(v12 + 4)
            + center.z * *(float *)(v12 + 8)
            + center.x * *(float *)v12
            + *(float *)(v12 + 12);
        if ( v11 )
          break;
        if ( v13 <= radius )
          goto LABEL_12;
LABEL_17:
        v5 = jq++ + 1;
        if ( jq >= num_parts )
          goto LABEL_23;
      }
      if ( v11 == 1 && v13 < neg_radius )
        goto LABEL_17;
LABEL_12:
      v14 = &v4->pos;
      v15 = CPhysicsPart::GetBoundingBox(parts[jq]);
      BBox::LocalToLocal(&box, v15, &parts[jq]->pos, v14);
      if ( Plane::intersect_box((Plane *)v12, &box) == v11 )
        goto LABEL_16;
      v16 = &v19->portals[v20];
      if ( v16->other_cell_id == -1 )
      {
        check_outside = 1;
        goto LABEL_22;
      }
      v17 = CCellPortal::GetOtherCell(v16, cell_array->do_not_load_cells);
      if ( v17 )
        break;
      CELLARRAY::add_cell(cell_array, v19->portals[v20].other_cell_id, 0);
LABEL_22:
      v4 = v19;
LABEL_23:
      v18 = iq++ + 1 < v4->num_portals;
      ++v20;
      if ( !v18 )
      {
        if ( check_outside )
          CLandCell::add_all_outside_cells(num_parts, parts, cell_array);
        return;
      }
    }
    BBox::LocalToLocal(&cell_box, v15, &parts[jq]->pos, (Position *)&v17->m_VertexFormatInfo.offsetWeight1);
    if ( CCellStruct::box_intersects_cell((CCellStruct *)v17[1].m_VertexFormatInfo.numMatrices, &cell_box) )
    {
      CELLARRAY::add_cell(cell_array, (const unsigned int)v17->m_pD3DVertexBuffer, (CObjCell *)v17);
      goto LABEL_22;
    }
LABEL_16:
    v4 = v19;
    goto LABEL_17;
  }
}

//----- (0052CD00) --------------------------------------------------------  // acclient.c:348523
int __thiscall CEnvCell::Pack(CEnvCell *this, void **addr, unsigned int size)
{
  CEnvCell *v3; // edi@1
  int v4; // ebp@1
  signed int v5; // eax@2
  char *v6; // eax@8
  char *v7; // edx@8
  char *v8; // ecx@8
  char *v9; // eax@8
  char *v10; // edx@8
  char *v11; // eax@8
  CShadowObj **v12; // edx@8
  int v13; // ecx@9
  char *v14; // ecx@13
  unsigned int v15; // ebx@13
  int v16; // ebp@14
  unsigned int v17; // eax@17
  unsigned int v18; // eax@19
  unsigned int v19; // ebx@20
  int v20; // ebp@21
  unsigned int v21; // edi@24
  unsigned int retval; // [sp+Ch] [bp-4h]@1

  v3 = this;
  v4 = CEnvCell::pack_size((CEnvCell *)((char *)this - 48));
  retval = v4;
  if ( size >= v4 )
  {
    v5 = 0;
    if ( v3->light_list.blocksize )
      v5 = 1;
    if ( v3->num_stabs )
      v5 |= 2u;
    if ( v3->object_list.next_available )
      v5 |= 8u;
    *(_DWORD *)*addr = v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3[-1].portal_view.next_available;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *v7 = LOBYTE(v3->shadow_object_list.data);
    v8 = (char *)*addr + 1;
    *addr = v8;
    *v8 = LOBYTE(v3->restriction_obj);
    v9 = (char *)*addr + 1;
    *addr = v9;
    *(_WORD *)v9 = LOWORD(v3->num_lights);
    v10 = (char *)*addr + 2;
    *addr = v10;
    v11 = v10;
    v12 = 0;
    if ( v3->shadow_object_list.data )
    {
      do
      {
        v13 = *(_DWORD *)(v3->shadow_object_list.blocksize + 4 * (_DWORD)v12);
        if ( v13 )
          *(_WORD *)v11 = *(_DWORD *)(v13 + 40);
        else
          *(_WORD *)v11 = 0;
        v11 = (char *)*addr + 2;
        *addr = v11;
        v12 = (CShadowObj **)((char *)v12 + 1);
      }
      while ( v12 < v3->shadow_object_list.data );
    }
    *(_WORD *)v11 = *(_DWORD *)(v3->shadow_object_list.sizeOf + 40);
    v14 = (char *)*addr + 2;
    *addr = v14;
    *(_WORD *)v14 = *(_WORD *)v3->shadow_object_list.next_available;
    *addr = (char *)*addr + 2;
    Frame::Pack((Frame *)&v3->m_AllowedInFreeList, addr, size);
    v15 = 0;
    if ( v3->restriction_obj )
    {
      v16 = 0;
      do
      {
        CCellPortal::Pack((CCellPortal *)&v3->clip_planes[v16], addr, size);
        ++v15;
        v16 += 6;
      }
      while ( v15 < v3->restriction_obj );
      v4 = retval;
    }
    v17 = 0;
    if ( v3->num_lights )
    {
      do
      {
        *(_WORD *)*addr = LOWORD(v3->light_list.data[v17]);
        *addr = (char *)*addr + 2;
        ++v17;
      }
      while ( v17 < v3->num_lights );
    }
    v18 = v3->num_stabs;
    if ( v18 )
    {
      *(_DWORD *)*addr = v18;
      *addr = (char *)*addr + 4;
      v19 = 0;
      if ( v3->num_stabs )
      {
        v20 = 0;
        do
        {
          *(_DWORD *)*addr = v3->stab_list[v19];
          *addr = (char *)*addr + 4;
          Frame::Pack((Frame *)(v20 + v3->seen_outside), addr, size);
          ++v19;
          v20 += 64;
        }
        while ( v19 < v3->num_stabs );
        v4 = retval;
      }
    }
    v21 = v3->object_list.next_available;
    if ( v21 )
    {
      *(_DWORD *)*addr = v21;
      *addr = (char *)*addr + 4;
    }
  }
  return v4;
}

//----- (0052CED0) --------------------------------------------------------  // acclient.c:348652
void __thiscall DArray<ClipPlane>::grow(DArray<ClipPlane> *this, unsigned int size)
{
  unsigned int v2; // ebp@1
  DArray<ClipPlane> *v3; // esi@1
  void *v4; // eax@3
  int v5; // edi@4
  unsigned int v6; // edx@6
  int v7; // ecx@7
  int v8; // eax@7
  ClipPlane *v9; // ecx@8
  Sidedness v10; // eax@9
  void *v11; // edx@9
  DiskSpace *v12; // ebx@9
  int v13; // eax@9
  int v14; // ebp@10
  int v15; // [sp+8h] [bp-4h]@9

  v2 = size;
  v3 = this;
  if ( size > this->sizeOf )
  {
    v4 = operator new[](8 * size + 4);
    if ( v4 )
    {
      v5 = (int)((char *)v4 + 4);
      *(_DWORD *)v4 = size;
      vector_constructor_iterator((char *)v4 + 4, 8u, size, (void *(__thiscall *)(void *))ClipPlane::ClipPlane);
    }
    else
    {
      v5 = 0;
    }
    v6 = 0;
    if ( v3->sizeOf )
    {
      do
      {
        v7 = 8 * v6;
        v8 = (int)&v3->data[v6];
        *(_DWORD *)(v7 + v5) = *(_DWORD *)v8;
        *(_DWORD *)(v7 + v5 + 4) = *(_DWORD *)(v8 + 4);
        ++v6;
      }
      while ( v6 < v3->sizeOf );
    }
    v9 = v3->data;
    if ( v3->data )
    {
      v10 = v9[-1].side;
      v11 = &v9[-1].side;
      v12 = (DiskSpace *)&v9[v10];
      v13 = v10 - 1;
      v15 = (int)&v9[-1].side;
      if ( v13 >= 0 )
      {
        v14 = v13 + 1;
        do
        {
          v12 -= 8;
          gmNoticeHandler::RecvNotice_PrevSpellSelection(v12);
          --v14;
        }
        while ( v14 );
        v2 = size;
        v11 = (void *)v15;
      }
      operator delete[](v11);
    }
    v3->data = (ClipPlane *)v5;
    v3->sizeOf = v2;
  }
  else
  {
    DArray<ClipPlane>::shrink(this, size);
  }
}

//----- (0052CF90) --------------------------------------------------------  // acclient.c:348730
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0> *v2; // esi@1
  HashTableData<unsigned long,CEnvCell *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C8D38: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::vftable[2])(void *, char);

//----- (0052CFD0) --------------------------------------------------------  // acclient.c:348751
void __thiscall DArray<ClipPlane>::shrink(DArray<ClipPlane> *this, unsigned int size)
{
  unsigned int v2; // ebp@1
  DArray<ClipPlane> *v3; // esi@1
  ClipPlane *v4; // ecx@4
  bool v5; // zf@4
  Sidedness v6; // eax@5
  void *v7; // edx@5
  DiskSpace *v8; // edi@5
  int v9; // eax@5
  int v10; // ebx@6
  void *v11; // eax@11
  int v12; // edi@12
  unsigned int v13; // edx@14
  int v14; // ecx@15
  int v15; // eax@15
  ClipPlane *v16; // ecx@16
  Sidedness v17; // eax@17
  void *v18; // edx@17
  DiskSpace *v19; // ebx@17
  int v20; // eax@17
  int v21; // ebp@18
  int v22; // [sp+8h] [bp-4h]@17
  unsigned int sizea; // [sp+10h] [bp+4h]@5

  v2 = size;
  v3 = this;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v11 = operator new[](8 * size + 4);
      if ( v11 )
      {
        v12 = (int)((char *)v11 + 4);
        *(_DWORD *)v11 = size;
        vector_constructor_iterator((char *)v11 + 4, 8u, size, (void *(__thiscall *)(void *))ClipPlane::ClipPlane);
      }
      else
      {
        v12 = 0;
      }
      v13 = 0;
      v3->sizeOf = size;
      if ( size )
      {
        do
        {
          v14 = 8 * v13;
          v15 = (int)&v3->data[v13];
          *(_DWORD *)(v14 + v12) = *(_DWORD *)v15;
          *(_DWORD *)(v14 + v12 + 4) = *(_DWORD *)(v15 + 4);
          ++v13;
        }
        while ( v13 < v3->sizeOf );
      }
      v16 = v3->data;
      if ( v3->data )
      {
        v17 = v16[-1].side;
        v18 = &v16[-1].side;
        v19 = (DiskSpace *)&v16[v17];
        v20 = v17 - 1;
        v22 = (int)&v16[-1].side;
        if ( v20 >= 0 )
        {
          v21 = v20 + 1;
          do
          {
            v19 -= 8;
            gmNoticeHandler::RecvNotice_PrevSpellSelection(v19);
            --v21;
          }
          while ( v21 );
          v18 = (void *)v22;
          v2 = size;
        }
        operator delete[](v18);
      }
      v3->data = (ClipPlane *)v12;
    }
    else
    {
      v4 = this->data;
      v5 = v3->data == 0;
      v3->sizeOf = 0;
      if ( !v5 )
      {
        v6 = v4[-1].side;
        v7 = &v4[-1].side;
        v8 = (DiskSpace *)&v4[v6];
        v9 = v6 - 1;
        sizea = (unsigned int)&v4[-1].side;
        if ( v9 >= 0 )
        {
          v10 = v9 + 1;
          do
          {
            v8 -= 8;
            gmNoticeHandler::RecvNotice_PrevSpellSelection(v8);
            --v10;
          }
          while ( v10 );
          v7 = (void *)sizea;
        }
        operator delete[](v7);
      }
      v3->data = 0;
    }
    if ( v3->next_available > v2 )
      v3->next_available = v2;
  }
  else
  {
    DArray<ClipPlane>::grow(this, size);
  }
}

//----- (0052D0F0) --------------------------------------------------------  // acclient.c:348870
void __thiscall CEnvCell::calc_clip_planes(CEnvCell *this)
{
  CEnvCell *v1; // edi@1
  void *v2; // eax@2
  ClipPlaneList *v3; // eax@4
  ClipPlaneList *v4; // eax@5
  unsigned int v5; // ebp@8
  int v6; // ebx@9
  ClipPlaneList *v7; // esi@10
  unsigned int v8; // eax@10
  unsigned int v9; // eax@12
  ClipPlane *v10; // edx@12
  ClipPlane cplane; // [sp+10h] [bp-8h]@10

  v1 = this;
  if ( !this->clip_planes )
  {
    v2 = operator new[](4u);
    v1->clip_planes = (ClipPlaneList **)v2;
    *(_DWORD *)v2 = 0;
  }
  if ( !*v1->clip_planes )
  {
    v3 = (ClipPlaneList *)operator new(0x18u);
    if ( v3 )
      ClipPlaneList::ClipPlaneList(v3);
    else
      v4 = 0;
    *v1->clip_planes = v4;
  }
  v5 = 0;
  if ( v1->num_portals )
  {
    v6 = 0;
    do
    {
      ClipPlane::ClipPlane(&cplane, &v1->portals[v6].portal->plane, (Sidedness)v1->portals[v6].portal_side);
      v7 = *v1->clip_planes;
      v8 = v7->cplane_list.sizeOf;
      if ( v7->cplane_num >= v8 )
        DArray<ClipPlane>::grow(&v7->cplane_list, v8 + 5);
      v9 = v7->cplane_num;
      v10 = v7->cplane_list.data;
      ++v7->cplane_num;
      v10[v9] = cplane;
      gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&cplane);
      ++v5;
      ++v6;
    }
    while ( v5 < v1->num_portals );
  }
}

//----- (0052D1E0) --------------------------------------------------------  // acclient.c:348924
int __cdecl CEnvCell::PreFetchCells(CEnvCell *this, IDClass<_tagDataID,32,0> cell_id)
{
  signed int v2; // edi@1
  QualifiedDataID *v3; // eax@1
  CACHE_OBJECT_CODES v4; // eax@1
  int result; // eax@3
  QualifiedDataID *v6; // eax@4
  int v7; // eax@4
  int v8; // esi@4
  QualifiedDataID v9; // [sp+Ch] [bp-8h]@1

  v2 = 1;
  *(_DWORD *)cell_id.id = 0;
  QualifiedDataID::QualifiedDataID(&v9, (IDClass<_tagDataID,32,0>)this, 3u);
  v4 = DBObj::PreFetch(v3);
  if ( v4 == 2 || v4 == 1 )
  {
    QualifiedDataID::QualifiedDataID(&v9, (IDClass<_tagDataID,32,0>)this, 3u);
    v7 = DBObj::Get(v6);
    v8 = v7;
    if ( v7 )
    {
      if ( !CEnvCell::PreFetchCells((CEnvCell *)v7, (unsigned int *)cell_id.id) )
        v2 = 0;
      (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 20))(v8);
    }
    result = v2;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0052D260) --------------------------------------------------------  // acclient.c:348960
void __thiscall CEnvCell::GetSubDataIDs(CEnvCell *this, QualifiedDataIDArray *id_array)
{
  CEnvCell *v2; // esi@1
  unsigned int v3; // edi@1
  CSurface *v4; // eax@2
  QualifiedDataID *v5; // eax@3
  CEnvironment *v6; // eax@5
  QualifiedDataID *v7; // eax@6
  unsigned int v8; // edi@7
  QualifiedDataID *v9; // eax@8
  QualifiedDataID v10; // [sp+10h] [bp-8h]@3

  v2 = this;
  v3 = 0;
  if ( this->num_surfaces )
  {
    do
    {
      v4 = v2->surfaces[v3];
      if ( v4 )
      {
        QualifiedDataID::QualifiedDataID(&v10, v4->m_DID, 0);
        QualifiedDataIDArray::AddQDID(id_array, v5, 0);
      }
      ++v3;
    }
    while ( v3 < v2->num_surfaces );
  }
  v6 = v2->env;
  if ( v6 )
  {
    QualifiedDataID::QualifiedDataID(&v10, v6->m_DID, 0);
    QualifiedDataIDArray::AddQDID(id_array, v7, 0);
  }
  v8 = 0;
  if ( v2->num_static_objects )
  {
    do
    {
      QualifiedDataID::QualifiedDataID(&v10, v2->static_object_ids[v8], 0);
      QualifiedDataIDArray::AddQDID(id_array, v9, 0);
      ++v8;
    }
    while ( v8 < v2->num_static_objects );
  }
}

//----- (0052D320) --------------------------------------------------------  // acclient.c:349008
void __thiscall DArray<view_vertex>::~DArray<view_vertex>(DArray<view_vertex> *this)
{
  DArray<view_vertex> *v1; // ebp@1
  view_vertex *v2; // ecx@1
  float v3; // eax@2
  void *v4; // ebx@2
  int v5; // edx@2
  int v6; // eax@2
  DiskSpace *v7; // esi@2
  int v8; // edi@3

  v1 = this;
  v2 = this->data;
  if ( v2 )
  {
    v3 = v2[-1].plane.d;
    v4 = &v2[-1].plane.d;
    v5 = 3 * LODWORD(v3);
    v6 = LODWORD(v3) - 1;
    v7 = (DiskSpace *)&v2[8 * v5 / 0x18u];
    if ( v6 >= 0 )
    {
      v8 = v6 + 1;
      do
      {
        v7 -= 24;
        gmNoticeHandler::RecvNotice_PrevSpellSelection(v7);
        --v8;
      }
      while ( v8 );
    }
    operator delete[](v4);
  }
  v1->data = 0;
}

//----- (0052D410) --------------------------------------------------------  // acclient.c:349093
void __cdecl CEnvCell::add_dynamic_lights()
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v0; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v1; // edi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v3; // esi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@1

  v0 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&CEnvCell::visible_cell_table.m_intrusiveTable,
         &result);
  v1 = v0->m_currElement;
  v2 = v0->m_currHashTable;
  v3 = v0->m_currBucket;
  if ( v1 )
  {
    do
    {
LABEL_2:
      CObjCell::add_dynamic_to_global_lights((CObjCell *)v1->m_data.vfptr);
      v1 = v1->m_hashNext;
    }
    while ( v1 );
    while ( 1 )
    {
      ++v3;
      if ( v3 == &v2->m_buckets[v2->m_numBuckets] )
        break;
      if ( *v3 )
      {
        v1 = *v3;
        if ( *v3 )
          goto LABEL_2;
        return;
      }
    }
  }
}

//----- (0052D470) --------------------------------------------------------  // acclient.c:349133
int __thiscall CEnvCell::UnPack(CEnvCell *this, void **addr, unsigned int size)
{
  CEnvCell *v3; // esi@1
  Frame *v4; // eax@1
  char *v5; // ebx@1
  void **v6; // edi@1
  char v7; // cl@1
  int v8; // ebp@1
  unsigned __int8 v9; // cl@1
  unsigned __int8 v10; // cl@1
  unsigned __int16 v11; // cx@1
  unsigned int v12; // ST1C_4@1
  CShadowObj **v13; // ebp@1
  unsigned __int16 v14; // cx@2
  QualifiedDataID *v15; // eax@2
  unsigned __int16 v16; // cx@3
  char *v17; // eax@3
  unsigned __int16 v18; // bp@3
  QualifiedDataID *v19; // eax@3
  int v20; // eax@3
  unsigned int v21; // ebp@5
  void *v22; // eax@6
  int v23; // eax@7
  int v24; // ebp@7
  int v25; // ebp@8
  int v26; // ebp@13
  unsigned int v27; // eax@15
  void *v28; // eax@16
  unsigned int v29; // ecx@16
  unsigned int v30; // eax@16
  unsigned __int16 v31; // dx@17
  unsigned int v32; // ebp@19
  void *v33; // eax@20
  int v34; // eax@21
  unsigned int v35; // ebp@23
  void *v36; // eax@23
  int v37; // ebx@24
  void **v38; // ecx@25
  int v39; // ebp@25
  int v40; // eax@28
  unsigned int v41; // ebp@30
  int v42; // edx@32
  int v43; // ecx@32
  int v44; // eax@37
  unsigned int block_mask; // [sp+10h] [bp-14h]@1
  unsigned int pack_bitfield; // [sp+14h] [bp-10h]@1
  QualifiedDataID poly_id; // [sp+18h] [bp-Ch]@2
  Frame **v49; // [sp+20h] [bp-4h]@1
  void **addra; // [sp+28h] [bp+4h]@7
  void **addrb; // [sp+28h] [bp+4h]@12
  void **addrc; // [sp+28h] [bp+4h]@25
  void **addrd; // [sp+28h] [bp+4h]@31

  v3 = this;
  v4 = this[-1].static_object_frames;
  v5 = (char *)&this[-1].static_object_frames;
  v49 = &this[-1].static_object_frames;
  LODWORD(v4->m_fOrigin.z)(&this[-1].static_object_frames);
  v6 = addr;
  pack_bitfield = *(_DWORD *)*addr;
  v7 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  v3->light_list.blocksize = v7 & 1;
  v8 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  (*(void (__thiscall **)(char *, int))(*(_DWORD *)v5 + 68))(v5, v8);
  v9 = *(_BYTE *)*addr;
  *v6 = (char *)*v6 + 1;
  v3->shadow_object_list.data = (CShadowObj **)v9;
  v10 = *(_BYTE *)*addr;
  *v6 = (char *)*v6 + 1;
  v3->restriction_obj = v10;
  v11 = *(_WORD *)*addr;
  *v6 = (char *)*v6 + 2;
  v12 = 4 * (unsigned int)v3->shadow_object_list.data;
  block_mask = v8 & 0xFFFF0000;
  v3->num_lights = v11;
  v3->shadow_object_list.blocksize = (unsigned int)operator new[](v12);
  v13 = 0;
  if ( v3->shadow_object_list.data )
  {
    do
    {
      v14 = *(_WORD *)*addr;
      *addr = (char *)*addr + 2;
      QualifiedDataID::QualifiedDataID(&poly_id, (IDClass<_tagDataID,32,0>)(v14 | 0x8000000), 0xDu);
      *(_DWORD *)(v3->shadow_object_list.blocksize + 4 * (_DWORD)v13) = DBObj::Get(v15);
      v13 = (CShadowObj **)((char *)v13 + 1);
    }
    while ( v13 < v3->shadow_object_list.data );
  }
  v16 = *(_WORD *)*addr;
  v17 = (char *)*addr + 2;
  *addr = v17;
  v18 = *(_WORD *)v17;
  *addr = v17 + 2;
  QualifiedDataID::QualifiedDataID(&poly_id, (IDClass<_tagDataID,32,0>)(v16 | 0xD000000), 0x10u);
  v20 = DBObj::Get(v19);
  v3->shadow_object_list.sizeOf = v20;
  if ( v20 )
    v3->shadow_object_list.next_available = (unsigned int)CEnvironment::get_cellstruct((CEnvironment *)v20, v18);
  v3->m_DID.id = v3[-1].portal_view.next_available;
  Frame::UnPack((Frame *)&v3->m_AllowedInFreeList, addr, size);
  v21 = v3->restriction_obj;
  if ( v21 )
  {
    v22 = operator new[](24 * v21 + 4);
    if ( v22 )
    {
      v23 = (int)((char *)v22 + 4);
      *(_DWORD *)(v23 - 4) = v21;
      v24 = v21 - 1;
      poly_id.Type = v23;
      addra = (void **)v23;
      if ( v24 >= 0 )
      {
        v25 = v24 + 1;
        do
        {
          CCellPortal::CCellPortal((CCellPortal *)addra);
          --v25;
          addra += 6;
        }
        while ( v25 );
        v23 = poly_id.Type;
      }
    }
    else
    {
      v23 = 0;
    }
    v3->clip_planes = (ClipPlaneList **)v23;
    addrb = 0;
    if ( v3->restriction_obj )
    {
      v26 = 0;
      do
      {
        CCellPortal::UnPack((CCellPortal *)&v3->clip_planes[v26], block_mask, (unsigned __int16 *)&poly_id, v6, size);
        v3->clip_planes[v26 + 2] = (ClipPlaneList *)CCellStruct::get_portal(
                                                      (CCellStruct *)v3->shadow_object_list.next_available,
                                                      poly_id.Type);
        v26 += 6;
        addrb = (void **)((char *)addrb + 1);
      }
      while ( (unsigned int)addrb < v3->restriction_obj );
    }
  }
  v27 = v3->num_lights;
  if ( v27 )
  {
    v28 = operator new[](4 * v27);
    v29 = v3->num_lights;
    v3->light_list.data = (LIGHTOBJ **)v28;
    v30 = 0;
    if ( v29 )
    {
      do
      {
        v31 = *(_WORD *)*v6;
        *v6 = (char *)*v6 + 2;
        v3->light_list.data[v30++] = (LIGHTOBJ *)(block_mask | v31);
      }
      while ( v30 < v3->num_lights );
    }
  }
  if ( pack_bitfield & 2 )
  {
    v3->num_stabs = *(_DWORD *)*v6;
    *v6 = (char *)*v6 + 4;
    v32 = v3->num_stabs;
    if ( v32 )
    {
      v33 = operator new[](4 * v32 + 4);
      if ( v33 )
      {
        *(_DWORD *)v33 = v32;
        v34 = (int)((char *)v33 + 4);
      }
      else
      {
        v34 = 0;
      }
      v35 = v3->num_stabs;
      v3->stab_list = (unsigned int *)v34;
      v36 = operator new[]((v35 << 6) + 4);
      if ( v36 )
      {
        v37 = (int)((char *)v36 + 4);
        *(_DWORD *)v36 = v35;
        poly_id.Type = (unsigned int)((char *)v36 + 4);
        if ( ((v35 - 1) & 0x80000000) == 0 )
        {
          v38 = (void **)v35;
          v39 = (int)((char *)v36 + 64);
          addrc = v38;
          do
          {
            *(_DWORD *)v37 = 1065353216;
            *(_DWORD *)(v39 - 56) = 0;
            *(_DWORD *)(v39 - 52) = 0;
            *(_DWORD *)(v39 - 48) = 0;
            *(_DWORD *)(v39 - 8) = 0;
            *(_DWORD *)(v39 - 4) = 0;
            *(_DWORD *)v39 = 0;
            Frame::cache((Frame *)v37);
            v37 += 64;
            v39 += 64;
            addrc = (void **)((char *)addrc - 1);
          }
          while ( addrc );
          v37 = poly_id.Type;
        }
        v40 = v37;
        v5 = (char *)v49;
      }
      else
      {
        v40 = 0;
      }
      v3->seen_outside = v40;
      v41 = 0;
      if ( v3->num_stabs )
      {
        addrd = 0;
        do
        {
          v42 = *(_DWORD *)*v6;
          v43 = (int)&v3->stab_list[v41];
          *v6 = (char *)*v6 + 4;
          *(_DWORD *)v43 = v42;
          Frame::UnPack((Frame *)((char *)addrd + v3->seen_outside), v6, size);
          ++v41;
          addrd += 16;
        }
        while ( v41 < v3->num_stabs );
      }
    }
  }
  if ( pack_bitfield & 8 )
  {
    v3->object_list.next_available = *(_DWORD *)*v6;
    *v6 = (char *)*v6 + 4;
  }
  else
  {
    v3->object_list.next_available = 0;
  }
  *((_DWORD *)v5 + 72) = operator new[](12 * *(_DWORD *)(*((_DWORD *)v5 + 64) + 36));
  CEnvCell::calc_clip_planes((CEnvCell *)v5);
  if ( DBCache::IsRunTime() )
  {
    v44 = *((_DWORD *)v5 + 74);
    *((_DWORD *)v5 + 75) = 1;
    if ( v44
      || !D3DPolyRender::ConstructMesh(
            *((_DWORD *)v5 + 62),
            *((CSurface ***)v5 + 63),
            (CVertexArray *)(*((_DWORD *)v5 + 64) + 4),
            *(_DWORD *)(*((_DWORD *)v5 + 64) + 60),
            *(CPolygon **)(*((_DWORD *)v5 + 64) + 64),
            3.0,
            1,
            (MeshBuffer **)v5 + 74) )
      *((_DWORD *)v5 + 75) = 0;
  }
  return 1;
}

//----- (0052D8A0) --------------------------------------------------------  // acclient.c:349403
CPhysicsObj *__thiscall CEnvCell::recursively_get_object(CEnvCell *this, const unsigned int obj_iid, PackableHashTable<unsigned long,int> *visited_cells)
{
  CEnvCell *v3; // ebx@1
  CPhysicsObj *result; // eax@1
  PackableHashTable<unsigned long,int> *v5; // ebp@3
  CCellPortal *v6; // edx@4
  unsigned int v7; // esi@4
  unsigned int v8; // edi@4
  CCellPortal *v9; // ecx@4
  PackableHashData<unsigned long,int> **v10; // ebx@5
  PackableHashData<unsigned long,int> *v11; // edx@6
  CEnvCell *v12; // esi@13
  bool v13; // cf@17
  CEnvCell *v14; // [sp+4h] [bp-Ch]@1
  unsigned int iq; // [sp+8h] [bp-8h]@2
  unsigned int cellid; // [sp+Ch] [bp-4h]@4
  PackableHashTable<unsigned long,int> *visited_cellsa; // [sp+18h] [bp+8h]@3

  v3 = this;
  v14 = this;
  result = (CPhysicsObj *)((int (__stdcall *)(const unsigned int))this->vfptr[5].IUnknown_QueryInterface)(obj_iid);
  if ( !result )
  {
    iq = 0;
    if ( v3->num_portals )
    {
      v5 = visited_cells;
      visited_cellsa = 0;
      do
      {
        v6 = v3->portals;
        v7 = v5->_table_size;
        v8 = *(unsigned int *)((char *)&visited_cellsa->vfptr + (_DWORD)v6);
        v9 = (CCellPortal *)((char *)visited_cellsa + (_DWORD)v6);
        cellid = *(unsigned int *)((char *)&visited_cellsa->vfptr + (_DWORD)v6);
        if ( v7 )
        {
          v10 = v5->_buckets;
          if ( v10 )
          {
            v11 = v10[v8 % v7];
            if ( v11 )
            {
              while ( v8 != v11->_key )
              {
                v11 = v11->_next;
                if ( !v11 )
                  goto LABEL_11;
              }
              if ( v11 != (PackableHashData<unsigned long,int> *)-4 )
              {
                v3 = v14;
                goto LABEL_17;
              }
            }
          }
LABEL_11:
          v3 = v14;
        }
        if ( v8 != -1 )
        {
          v12 = (CEnvCell *)CCellPortal::GetOtherCell(v9, 0);
          if ( v12 )
          {
            PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
              (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v5,
              (IDClass<_tagDataID,32,0> *)&cellid,
              &ptrue);
            result = CEnvCell::recursively_get_object(v12, obj_iid, v5);
            if ( result )
              return result;
          }
        }
LABEL_17:
        v13 = iq++ + 1 < v3->num_portals;
        visited_cellsa = (PackableHashTable<unsigned long,int> *)((char *)visited_cellsa + 24);
      }
      while ( v13 );
    }
    result = 0;
  }
  return result;
}

//----- (0052D990) --------------------------------------------------------  // acclient.c:349488
void __thiscall CEnvCell::Destroy(CEnvCell *this)
{
  CEnvCell *v1; // esi@1
  unsigned int v2; // edi@2
  CSurface *v3; // ecx@3
  void *v4; // eax@7
  ClipPlaneList **v5; // eax@9
  ClipPlaneList *v6; // eax@10
  CEnvironment *v7; // ecx@14
  unsigned int v8; // ebp@16
  portal_view_type *v9; // edi@17
  view_vertex *v10; // ecx@18
  float v11; // eax@19
  void *v12; // edx@19
  int v13; // ebx@19
  int v14; // eax@19
  DiskSpace *v15; // ebx@19
  int v16; // ebp@20
  CCellPortal *v17; // ecx@26
  int v18; // eax@27
  void *v19; // edx@27
  int v20; // edi@27
  int v21; // eax@27
  DiskSpace *v22; // edi@27
  int v23; // ebp@28
  void *v24; // eax@32
  IDClass<_tagDataID,32,0> *v25; // eax@34
  Frame *v26; // eax@36
  unsigned int j; // edi@39
  CPhysicsObj *v28; // ecx@40
  CPhysicsObj *v29; // ecx@41
  unsigned int i; // [sp+Ch] [bp-8h]@16
  int v31; // [sp+10h] [bp-4h]@19
  int v32; // [sp+10h] [bp-4h]@27

  v1 = this;
  if ( this->surfaces )
  {
    v2 = 0;
    if ( this->num_surfaces > 0 )
    {
      do
      {
        v3 = v1->surfaces[v2];
        if ( v3 )
          ((void (*)(void))v3->vfptr->Release)();
        ++v2;
      }
      while ( v2 < v1->num_surfaces );
    }
    operator delete[](v1->surfaces);
    v1->surfaces = 0;
  }
  v4 = v1->light_array;
  v1->num_surfaces = 0;
  if ( v4 )
  {
    operator delete[](v4);
    v1->light_array = 0;
  }
  v5 = v1->clip_planes;
  if ( v5 )
  {
    v6 = *v5;
    if ( v6 )
      v6->cplane_num = 0;
  }
  if ( v1->constructed_mesh )
  {
    D3DPolyRender::DestroyMesh(&v1->constructed_mesh);
    v1->constructed_mesh = 0;
  }
  v7 = v1->env;
  if ( v7 )
  {
    ((void (*)(void))v7->vfptr->Release)();
    v1->env = 0;
  }
  v8 = 0;
  for ( i = 0; v8 < v1->portal_view.sizeOf; i = v8 )
  {
    v9 = v1->portal_view.data[v8];
    if ( v9 )
    {
      v10 = v9->view.vertex.data;
      if ( v10 )
      {
        v11 = v10[-1].plane.d;
        v12 = &v10[-1].plane.d;
        v13 = 3 * LODWORD(v11);
        v14 = LODWORD(v11) - 1;
        v31 = (int)&v10[-1].plane.d;
        v15 = (DiskSpace *)&v10[8 * v13 / 0x18u];
        if ( v14 >= 0 )
        {
          v16 = v14 + 1;
          do
          {
            v15 -= 24;
            gmNoticeHandler::RecvNotice_PrevSpellSelection(v15);
            --v16;
          }
          while ( v16 );
          v12 = (void *)v31;
          v8 = i;
        }
        operator delete[](v12);
      }
      v9->view.vertex.data = 0;
      operator delete[](v9->view.poly.data);
      v9->view.poly.data = 0;
      operator delete[](v9->portal.data);
      v9->portal.data = 0;
      operator delete(v9);
      v1->portal_view.data[v8] = 0;
    }
    ++v8;
  }
  v17 = v1->portals;
  if ( v17 )
  {
    v18 = v17[-1].exact_match;
    v19 = &v17[-1].exact_match;
    v20 = 3 * v18;
    v21 = v18 - 1;
    v32 = (int)&v17[-1].exact_match;
    v22 = (DiskSpace *)&v17[8 * v20 / 0x18u];
    if ( v21 >= 0 )
    {
      v23 = v21 + 1;
      do
      {
        v22 -= 24;
        gmNoticeHandler::RecvNotice_PrevSpellSelection(v22);
        --v23;
      }
      while ( v23 );
      v19 = (void *)v32;
    }
    operator delete[](v19);
    v1->portals = 0;
  }
  v24 = v1->stab_list;
  v1->num_portals = 0;
  if ( v24 )
  {
    operator delete[](v24);
    v1->stab_list = 0;
  }
  v25 = v1->static_object_ids;
  v1->num_stabs = 0;
  if ( v25 )
  {
    operator delete[](&v25[-1]);
    v1->static_object_ids = 0;
  }
  v26 = v1->static_object_frames;
  if ( v26 )
  {
    operator delete[](&v26[-1].m_fOrigin.z);
    v1->static_object_frames = 0;
  }
  if ( v1->static_objects )
  {
    for ( j = 0; j < v1->num_static_objects; ++j )
    {
      v28 = v1->static_objects[j];
      if ( v28 )
      {
        CPhysicsObj::leave_world(v28);
        v29 = v1->static_objects[j];
        if ( v29 )
          ((void (__stdcall *)(_DWORD))v29->vfptr->__vecDelDtor)(1);
      }
    }
    operator delete[](v1->static_objects);
    v1->static_objects = 0;
  }
  v1->num_static_objects = 0;
  v1->structure = 0;
  v1->seen_outside = 0;
  CObjCell::release_objects((CObjCell *)&v1->vfptr);
}

//----- (0052DC10) --------------------------------------------------------  // acclient.c:349673
RenderVertexStreamD3D *__cdecl CEnvCell::GetVisible(unsigned int cell_id)
{
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v1; // eax@1
  RenderVertexStreamD3D *result; // eax@4

  v1 = CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets[cell_id
                                                             % CEnvCell::visible_cell_table.m_intrusiveTable.m_numBuckets];
  if ( !v1 )
    goto LABEL_4;
  while ( v1->m_hashKey != cell_id )
  {
    v1 = v1->m_hashNext;
    if ( !v1 )
      goto LABEL_4;
  }
  if ( v1 )
    result = v1->m_data;
  else
LABEL_4:
    result = 0;
  return result;
}

//----- (0052DC50) --------------------------------------------------------  // acclient.c:349697
RenderVertexStreamD3D *__thiscall CEnvCell::find_visible_child_cell(CEnvCell *this, AC1Legacy::Vector3 *origin, const int bSearchCells)
{
  CEnvCell *v3; // edi@1
  unsigned int v5; // ebx@4
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v6; // eax@5
  RenderVertexStreamD3D *v7; // esi@10
  unsigned int v8; // ebp@15
  int v9; // ebx@16

  v3 = this;
  if ( ((int (__stdcall *)(AC1Legacy::Vector3 *))this->vfptr[5].QueryInterface)(origin) )
    return (RenderVertexStreamD3D *)v3;
  if ( bSearchCells )
  {
    v5 = 0;
    if ( v3->num_stabs )
    {
      while ( 1 )
      {
        v6 = CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets[v3->stab_list[v5]
                                                                   % CEnvCell::visible_cell_table.m_intrusiveTable.m_numBuckets];
        if ( v6 )
        {
          while ( v6->m_hashKey != v3->stab_list[v5] )
          {
            v6 = v6->m_hashNext;
            if ( !v6 )
              goto LABEL_12;
          }
          if ( v6 )
          {
            v7 = v6->m_data;
            if ( v7 )
            {
              if ( v7->vfptr[8].CopyInto((GraphicsResource *)v7, (GraphicsResource *)origin) )
                return v7;
            }
          }
        }
LABEL_12:
        ++v5;
        if ( v5 >= v3->num_stabs )
          return 0;
      }
    }
  }
  else
  {
    v8 = 0;
    if ( v3->num_portals )
    {
      v9 = 0;
      while ( 1 )
      {
        v7 = CCellPortal::GetOtherCell(&v3->portals[v9], 1);
        if ( v7 )
        {
          if ( v7->vfptr[8].CopyInto((GraphicsResource *)v7, (GraphicsResource *)origin) )
            break;
        }
        ++v8;
        ++v9;
        if ( v8 >= v3->num_portals )
          return 0;
      }
      return v7;
    }
  }
  return 0;
}

//----- (0052DD50) --------------------------------------------------------  // acclient.c:349769
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,CEnvCell *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,CEnvCell *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7C8D38: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::vftable[2])(void *, char);

//----- (0052DDE0) --------------------------------------------------------  // acclient.c:349802
CEnvCell *__thiscall CEnvCell::scalar_deleting_destructor(CEnvCell *this, unsigned int a2)
{
  CEnvCell *v2; // esi@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&CEnvCell::vftable;
  this->vfptr = (PackObjVtbl *)&CEnvCell::vftable;
  this->vfptr = (CPartCellVtbl *)&CEnvCell::vftable;
  CEnvCell::Destroy(this);
  operator delete[](v2->portal_view.data);
  v2->portal_view.data = 0;
  CObjCell::~CObjCell((CObjCell *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C8C74: using guessed type void (__thiscall *CEnvCell::vftable)(CPartCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32);
// 7C8C80: using guessed type void *CEnvCell::vftable;
// 7C8C98: using guessed type __int32 (__stdcall *CEnvCell::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0052DE40) --------------------------------------------------------  // acclient.c:349823
int __cdecl CEnvCell::add_visible_cell(unsigned int cell_id)
{
  unsigned int v1; // esi@1
  RenderVertexStreamD3D *v2; // ecx@1
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v3; // edx@1
  HashSetData<IDClass<_tagDataID,32,0> > *v4; // eax@8
  int v5; // esi@9
  QualifiedDataID *v6; // eax@10
  QualifiedDataID v8; // [sp+4h] [bp-8h]@10

  v1 = cell_id;
  v2 = 0;
  v3 = CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets[cell_id
                                                             % CEnvCell::visible_cell_table.m_intrusiveTable.m_numBuckets];
  if ( v3 )
  {
    while ( v3->m_hashKey != cell_id )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        goto LABEL_7;
    }
    if ( v3 )
      v2 = v3->m_data;
  }
LABEL_7:
  if ( !v2 )
  {
    v4 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
           &stru_81DDA4,
           (IDClass<_tagDataID,32,0> *)&cell_id);
    if ( v4 )
    {
      v5 = v4[1].m_hashKey.id;
      cell_id = v4[1].m_hashKey.id;
      operator delete(v4);
    }
    else
    {
      QualifiedDataID::QualifiedDataID(&v8, (IDClass<_tagDataID,32,0>)v1, 3u);
      v5 = DBObj::Get(v6);
      cell_id = v5;
      if ( !v5 )
        return v5;
    }
    v8.Type = *(_DWORD *)(v5 + 40);
    HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
      &CEnvCell::visible_cell_table,
      &v8.Type,
      (RenderVertexStreamD3D *const *)&cell_id);
    return v5;
  }
  return (int)v2;
}

//----- (0052DEF0) --------------------------------------------------------  // acclient.c:349879
void __cdecl CEnvCell::flush_cells()
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v0; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v1; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // ebp@1
  HashTableData<unsigned long,HeritageGroup_CG> **v3; // edi@1
  HeritageGroup_CGVtbl *v4; // ebx@2
  HashTableData<unsigned long,RenderVertexStreamD3D *> **v5; // ecx@6
  HashTableData<unsigned long,RenderVertexStreamD3D *> **v6; // eax@6
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v7; // esi@9
  HashTableData<unsigned long,RenderVertexStreamD3D *> **v8; // edi@11
  CObjCell *v9; // ebx@12
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@1

  v0 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&stru_81DDA4,
         &result);
  v1 = v0->m_currElement;
  v2 = v0->m_currHashTable;
  v3 = v0->m_currBucket;
  if ( v1 )
  {
    do
    {
LABEL_2:
      v4 = v1->m_data.vfptr;
      CObjCell::release_objects((CObjCell *)v1->m_data.vfptr);
      (*((void (__thiscall **)(HeritageGroup_CGVtbl *))v4->Serialize + 5))(v4);
      v1 = v1->m_hashNext;
    }
    while ( v1 );
    while ( 1 )
    {
      ++v3;
      if ( v3 == &v2->m_buckets[v2->m_numBuckets] )
        break;
      if ( *v3 )
      {
        v1 = *v3;
        if ( *v3 )
          goto LABEL_2;
        break;
      }
    }
  }
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81DDA4);
  v5 = &CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets[CEnvCell::visible_cell_table.m_intrusiveTable.m_numBuckets];
  v6 = CEnvCell::visible_cell_table.m_intrusiveTable.m_firstInterestingBucket;
  if ( CEnvCell::visible_cell_table.m_intrusiveTable.m_firstInterestingBucket == v5 )
  {
LABEL_9:
    v6 = 0;
    v7 = 0;
  }
  else
  {
    while ( !*v6 )
    {
      ++v6;
      CEnvCell::visible_cell_table.m_intrusiveTable.m_firstInterestingBucket = v6;
      if ( v6 == v5 )
        goto LABEL_9;
    }
    v7 = *v6;
  }
  v8 = v6;
  if ( v7 )
  {
    do
    {
LABEL_12:
      v9 = (CObjCell *)v7->m_data;
      ((void (__thiscall *)(_DWORD))v9->vfptr[6].QueryInterface)(v7->m_data);
      CObjCell::init_objects(v9);
      CObjCell::add_static_to_global_lights(v9);
      v7 = v7->m_hashNext;
    }
    while ( v7 );
    while ( 1 )
    {
      ++v8;
      if ( v8 == &CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets[CEnvCell::visible_cell_table.m_intrusiveTable.m_numBuckets] )
        break;
      if ( *v8 )
      {
        v7 = *v8;
        if ( *v8 )
          goto LABEL_12;
        return;
      }
    }
  }
}

//----- (0052DFE0) --------------------------------------------------------  // acclient.c:349974
HashTable<unsigned long,CEnvCell *,0> *__thiscall HashTable<unsigned long,CEnvCell *,0>::vector_deleting_destructor(HashTable<unsigned long,CEnvCell *,0> *this, unsigned int a2)
{
  HashTable<unsigned long,CEnvCell *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,CEnvCell *,0>Vtbl *)&HashTable<unsigned long,CEnvCell *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C8D38: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::vftable[2])(void *, char);
// 7C8D3C: using guessed type int (__thiscall *HashTable<unsigned long,CEnvCell *,0>::vftable)(void *, char);

//----- (0052E040) --------------------------------------------------------  // acclient.c:350000
void __cdecl CEnvCell::grab_visible(unsigned int num_stabs, unsigned int *stab_list, CLandBlock *block)
{
  unsigned int v3; // esi@1
  int v4; // eax@2

  v3 = 0;
  if ( num_stabs )
  {
    do
    {
      v4 = CEnvCell::add_visible_cell(stab_list[v3]);
      if ( v4 )
        *(_DWORD *)(v4 + 240) = block;
      ++v3;
    }
    while ( v3 < num_stabs );
  }
}

//----- (0052E080) --------------------------------------------------------  // acclient.c:350020
void __cdecl CEnvCell::release_visible(unsigned int num_stabs, unsigned int *stab_list)
{
  unsigned int v2; // ebx@1
  unsigned int v3; // esi@1
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v4; // edx@2
  RenderVertexStreamD3D *v5; // edx@7
  unsigned int v6; // eax@8
  int v7; // ecx@9
  unsigned int v8; // edx@14
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v9; // ecx@14
  HashTableData<unsigned long,RenderVertexStreamD3D *> **v10; // edi@14
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v11; // eax@14
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v12; // edx@20
  RenderVertexStreamD3D *v13; // esi@24
  IDirect3DVertexBuffer9 *v14; // edi@24
  void *v15; // eax@24
  void *v16; // ecx@25
  unsigned int v17; // esi@27
  unsigned int v18; // edi@27
  HashSetData<IDClass<_tagDataID,32,0> > **v19; // ebx@27
  HashSetData<IDClass<_tagDataID,32,0> > *v20; // edx@27
  HashSetData<IDClass<_tagDataID,32,0> > **v21; // eax@32
  unsigned int i; // [sp+10h] [bp-4h]@13

  v2 = num_stabs;
  v3 = 0;
  if ( num_stabs )
  {
    do
    {
      v4 = CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets[stab_list[v3]
                                                                 % CEnvCell::visible_cell_table.m_intrusiveTable.m_numBuckets];
      if ( v4 )
      {
        while ( v4->m_hashKey != stab_list[v3] )
        {
          v4 = v4->m_hashNext;
          if ( !v4 )
            goto LABEL_12;
        }
        if ( v4 )
        {
          v5 = v4->m_data;
          if ( v5 )
          {
            v6 = 0;
            if ( v5[1].m_VertexFormatInfo.offsetWeight0 > 0 )
            {
              v7 = 0;
              do
              {
                *(_DWORD *)(v7 + v5[1].m_VertexFormatInfo.offsetWeight1 + 4) = 0;
                ++v6;
                v7 += 24;
              }
              while ( v6 < v5[1].m_VertexFormatInfo.offsetWeight0 );
            }
            *(_DWORD *)&v5[1].m_VertexFormatInfo.bFVFCompatible = 0;
          }
        }
      }
LABEL_12:
      ++v3;
    }
    while ( v3 < num_stabs );
  }
  i = 0;
  if ( num_stabs > 0 )
  {
    do
    {
      v8 = stab_list[i] % CEnvCell::visible_cell_table.m_intrusiveTable.m_numBuckets;
      v9 = CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets[v8];
      v10 = &CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets[v8];
      v11 = CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets[v8];
      if ( v11 )
      {
        while ( v11->m_hashKey != stab_list[i] )
        {
          v11 = v11->m_hashNext;
          if ( !v11 )
            goto LABEL_37;
        }
        if ( v11 )
        {
          if ( v9 == v11 )
            goto LABEL_40;
          do
          {
            v12 = v9;
            v9 = v9->m_hashNext;
          }
          while ( v9 != v11 );
          if ( v12 )
            v12->m_hashNext = v9->m_hashNext;
          else
LABEL_40:
            *v10 = v9->m_hashNext;
          --CEnvCell::visible_cell_table.m_intrusiveTable.m_numElements;
          v13 = v11->m_data;
          operator delete(v11);
          v14 = v13->m_pD3DVertexBuffer;
          v15 = operator new(0xCu);
          if ( v15 )
          {
            *(_DWORD *)v15 = v14;
            *((_DWORD *)v15 + 1) = 0;
            *((_DWORD *)v15 + 2) = v13;
            v16 = v15;
          }
          else
          {
            v16 = 0;
          }
          v17 = *(_DWORD *)v16;
          v18 = stru_81DDA4.m_numBuckets;
          v19 = stru_81DDA4.m_buckets;
          v20 = stru_81DDA4.m_buckets[*(_DWORD *)v16 % stru_81DDA4.m_numBuckets];
          if ( !v20 )
            goto LABEL_32;
          while ( v20->m_hashKey.id != v17 )
          {
            v20 = v20->m_hashNext;
            if ( !v20 )
              goto LABEL_32;
          }
          if ( v20 )
          {
            operator delete(v16);
          }
          else
          {
LABEL_32:
            v21 = &stru_81DDA4.m_buckets[v17 % stru_81DDA4.m_numBuckets];
            *((_DWORD *)v16 + 1) = *v21;
            *v21 = (HashSetData<IDClass<_tagDataID,32,0> > *)v16;
            if ( v21 < stru_81DDA4.m_firstInterestingBucket )
              stru_81DDA4.m_firstInterestingBucket = &v19[v17 % v18];
            ++stru_81DDA4.m_numElements;
          }
          v2 = num_stabs;
        }
      }
LABEL_37:
      ++i;
    }
    while ( i < v2 );
  }
}

//----- (0052E220) --------------------------------------------------------  // acclient.c:350171
void __thiscall CEnvCell::grab_visible_cells(CEnvCell *this)
{
  CEnvCell *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  CEnvCell::add_visible_cell(this->m_DID.id);
  v2 = 0;
  if ( v1->num_stabs )
  {
    do
      CEnvCell::add_visible_cell(v1->stab_list[v2++]);
    while ( v2 < v1->num_stabs );
  }
  if ( v1->seen_outside )
    LScape::grab_visible_cells(CObjCell::landscape);
}

//----- (0052E280) --------------------------------------------------------  // acclient.c:350190
void __thiscall CEnvCell::release_cells(CEnvCell *this)
{
  CEnvCell *v1; // ebx@1
  unsigned int v2; // eax@1
  int v3; // ecx@2
  unsigned int j; // esi@4
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v5; // edx@5
  RenderVertexStreamD3D *v6; // edx@10
  unsigned int v7; // eax@11
  int v8; // ecx@12
  HashTableData<unsigned long,RenderVertexStreamD3D *> **v9; // edi@15
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v10; // ecx@15
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v11; // eax@15
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v12; // edx@21
  RenderVertexStreamD3D *v13; // esi@25
  IDirect3DVertexBuffer9 *v14; // edi@25
  void *v15; // eax@25
  void *v16; // esi@26
  HashTableData<unsigned long,RenderVertexStreamD3D *> **v17; // edi@32
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v18; // ecx@32
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v19; // eax@32
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v20; // edx@38
  RenderVertexStreamD3D *v21; // esi@42
  IDirect3DVertexBuffer9 *v22; // edi@42
  void *v23; // eax@42
  void *v24; // ecx@43
  unsigned int v25; // esi@45
  unsigned int v26; // edi@45
  HashSetData<IDClass<_tagDataID,32,0> > **v27; // ebx@45
  HashSetData<IDClass<_tagDataID,32,0> > *v28; // edx@45
  HashSetData<IDClass<_tagDataID,32,0> > **v29; // eax@50
  unsigned int i; // [sp+10h] [bp-8h]@31
  CEnvCell *v31; // [sp+14h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  v31 = this;
  if ( this->num_portals )
  {
    v3 = 0;
    do
    {
      v1->portals[v3].other_cell_ptr = 0;
      ++v2;
      ++v3;
    }
    while ( v2 < v1->num_portals );
  }
  for ( j = 0; j < v1->num_stabs; ++j )
  {
    v5 = CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets[v1->stab_list[j]
                                                               % CEnvCell::visible_cell_table.m_intrusiveTable.m_numBuckets];
    if ( v5 )
    {
      while ( v5->m_hashKey != v1->stab_list[j] )
      {
        v5 = v5->m_hashNext;
        if ( !v5 )
          goto LABEL_14;
      }
      if ( v5 )
      {
        v6 = v5->m_data;
        if ( v6 )
        {
          v7 = 0;
          if ( v6[1].m_VertexFormatInfo.offsetWeight0 > 0 )
          {
            v8 = 0;
            do
            {
              *(_DWORD *)(v6[1].m_VertexFormatInfo.offsetWeight1 + v8 + 4) = 0;
              ++v7;
              v8 += 24;
            }
            while ( v7 < v6[1].m_VertexFormatInfo.offsetWeight0 );
          }
        }
      }
    }
LABEL_14:
    ;
  }
  v9 = &CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets[v1->m_DID.id
                                                              % CEnvCell::visible_cell_table.m_intrusiveTable.m_numBuckets];
  v10 = *v9;
  v11 = *v9;
  *v9;
  *v9;
  if ( *v9 )
  {
    while ( v11->m_hashKey != v1->m_DID.id )
    {
      v11 = v11->m_hashNext;
      if ( !v11 )
        goto LABEL_31;
    }
    if ( v11 )
    {
      if ( v10 == v11 )
        goto LABEL_60;
      do
      {
        v12 = v10;
        v10 = v10->m_hashNext;
      }
      while ( v10 != v11 );
      if ( v12 )
        v12->m_hashNext = v10->m_hashNext;
      else
LABEL_60:
        *v9 = v10->m_hashNext;
      --CEnvCell::visible_cell_table.m_intrusiveTable.m_numElements;
      v13 = v11->m_data;
      operator delete(v11);
      v14 = v13->m_pD3DVertexBuffer;
      v15 = operator new(0xCu);
      if ( v15 )
      {
        *((_DWORD *)v15 + 2) = v13;
        *(_DWORD *)v15 = v14;
        *((_DWORD *)v15 + 1) = 0;
        v16 = v15;
      }
      else
      {
        v16 = 0;
      }
      if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
              (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81DDA4,
              (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v16)
        && v16 )
        operator delete(v16);
    }
  }
LABEL_31:
  i = 0;
  if ( v1->num_stabs )
  {
    do
    {
      v17 = &CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets[v1->stab_list[i]
                                                                   % CEnvCell::visible_cell_table.m_intrusiveTable.m_numBuckets];
      v18 = *v17;
      v19 = *v17;
      *v17;
      *v17;
      if ( *v17 )
      {
        while ( v19->m_hashKey != v1->stab_list[i] )
        {
          v19 = v19->m_hashNext;
          if ( !v19 )
            goto LABEL_55;
        }
        if ( v19 )
        {
          if ( v18 == v19 )
            goto LABEL_61;
          do
          {
            v20 = v18;
            v18 = v18->m_hashNext;
          }
          while ( v18 != v19 );
          if ( v20 )
            v20->m_hashNext = v18->m_hashNext;
          else
LABEL_61:
            *v17 = v18->m_hashNext;
          --CEnvCell::visible_cell_table.m_intrusiveTable.m_numElements;
          v21 = v19->m_data;
          operator delete(v19);
          v22 = v21->m_pD3DVertexBuffer;
          v23 = operator new(0xCu);
          if ( v23 )
          {
            *(_DWORD *)v23 = v22;
            *((_DWORD *)v23 + 1) = 0;
            *((_DWORD *)v23 + 2) = v21;
            v24 = v23;
          }
          else
          {
            v24 = 0;
          }
          v25 = *(_DWORD *)v24;
          v26 = stru_81DDA4.m_numBuckets;
          v27 = stru_81DDA4.m_buckets;
          v28 = stru_81DDA4.m_buckets[*(_DWORD *)v24 % stru_81DDA4.m_numBuckets];
          if ( !v28 )
            goto LABEL_50;
          while ( v28->m_hashKey.id != v25 )
          {
            v28 = v28->m_hashNext;
            if ( !v28 )
              goto LABEL_50;
          }
          if ( v28 )
          {
            operator delete(v24);
          }
          else
          {
LABEL_50:
            v29 = &stru_81DDA4.m_buckets[v25 % stru_81DDA4.m_numBuckets];
            *((_DWORD *)v24 + 1) = *v29;
            *v29 = (HashSetData<IDClass<_tagDataID,32,0> > *)v24;
            if ( v29 < stru_81DDA4.m_firstInterestingBucket )
              stru_81DDA4.m_firstInterestingBucket = &v27[v25 % v26];
            ++stru_81DDA4.m_numElements;
          }
          v1 = v31;
        }
      }
LABEL_55:
      ++i;
    }
    while ( i < v1->num_stabs );
  }
  if ( v1->seen_outside )
    LScape::release_visible_cells(CObjCell::landscape);
}

//----- (006FE390) --------------------------------------------------------  // acclient.c:786407
int sub_6FE390()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_16;
  INITIAL_MAX_DATA_RATE_86 = LOWEST_DATA_RATE_16;
  return result;
}

//----- (006FE3A0) --------------------------------------------------------  // acclient.c:786417
void sub_6FE3A0()
{
  flt_844900 = 1000.0 + 1.0;
}

//----- (006FE3C0) --------------------------------------------------------  // acclient.c:786423
void _E99_27()
{
  flt_844904 = 24.0 * 8.0;
}

//----- (006FE3E0) --------------------------------------------------------  // acclient.c:786429
void _E101_25()
{
  flt_844908 = 24.0 * 0.5;
}

//----- (006FE400) --------------------------------------------------------  // acclient.c:786435
void sub_6FE400()
{
  flt_844910 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FE420) --------------------------------------------------------  // acclient.c:786441
void _E105_32()
{
  dbl_844918 = 1.0 / 30.0;
}

//----- (006FE440) --------------------------------------------------------  // acclient.c:786447
void _E107_25()
{
  dbl_844920 = 1.0 / 5.0;
}

//----- (006FE460) --------------------------------------------------------  // acclient.c:786453
int _E109_65()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_23, "Display.Resolution");
  return atexit(sub_768CC0);
}

//----- (006FE480) --------------------------------------------------------  // acclient.c:786460
int _E112_88()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_23, "Display.FullScreen");
  return atexit(_E113_65);
}

//----- (006FE4A0) --------------------------------------------------------  // acclient.c:786467
int _E115_66()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_23, "Display.RefreshRate");
  return atexit(_E116_57);
}

//----- (006FE4C0) --------------------------------------------------------  // acclient.c:786474
int _E118_66()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_23, "Display.SyncToRefresh");
  return atexit(_E119_85);
}

//----- (006FE4E0) --------------------------------------------------------  // acclient.c:786481
void _E121_59()
{
  PixelFormatDesc::PixelFormatDesc(&stru_844938, PFID_A8R8G8B8);
}

//----- (006FE4F0) --------------------------------------------------------  // acclient.c:786487
int _E123_31()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_26, "Render.TextureFiltering");
  return atexit(sub_768D80);
}

//----- (006FE510) --------------------------------------------------------  // acclient.c:786494
int _E126_37()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_26, "Render.LandscapeDetailTextures");
  return atexit(sub_768DB0);
}

//----- (006FE530) --------------------------------------------------------  // acclient.c:786501
int _E129_29()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_26, "Render.BuildingDetailTextures");
  return atexit(_E130_97);
}

//----- (006FE550) --------------------------------------------------------  // acclient.c:786508
int _E132_32()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_26, "Render.FieldOfView");
  return atexit(_E133_91);
}

//----- (006FE570) --------------------------------------------------------  // acclient.c:786515
int _E135_35()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_26, "Render.LandscapeTextureDetail");
  return atexit(_E136_74);
}

//----- (006FE590) --------------------------------------------------------  // acclient.c:786522
int _E138_27()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_26, "Render.EnvironmentTextureDetail");
  return atexit(_E139_74);
}

//----- (006FE5B0) --------------------------------------------------------  // acclient.c:786529
int _E141_27()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_26, "Render.SceneryDrawDistance");
  return atexit(_E142_69);
}

//----- (006FE5D0) --------------------------------------------------------  // acclient.c:786536
int _E144_26()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_26, "Render.LandscapeDrawDistance");
  return atexit(_E145_71);
}

//----- (006FE5F0) --------------------------------------------------------  // acclient.c:786543
int _E147_24()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_26, "Render.ScreenBrightness");
  return atexit(_E148_68);
}

//----- (006FE610) --------------------------------------------------------  // acclient.c:786550
int _E150_25()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_26, "Render.AspectRatio");
  return atexit(_E151_66);
}

//----- (006FE630) --------------------------------------------------------  // acclient.c:786557
int _E153_23()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_26, "Render.DisplayAdapter");
  return atexit(_E154_67);
}

//----- (006FE650) --------------------------------------------------------  // acclient.c:786564
int _E156_25()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_26, "Render.MaxHardwareClass");
  return atexit(_E157_63);
}

//----- (006FE670) --------------------------------------------------------  // acclient.c:786571
int _E159_23()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_26, "Render.AutomaticDegrades");
  return atexit(_E160_66);
}

//----- (006FE690) --------------------------------------------------------  // acclient.c:786578
int _E162_25()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_26, "Render.GraphicsPerformance");
  return atexit(_E163_59);
}

//----- (006FE6B0) --------------------------------------------------------  // acclient.c:786585
int _E165_21()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_26, "Render.DegradeDistance");
  return atexit(_E166_61);
}

//----- (006FE6D0) --------------------------------------------------------  // acclient.c:786592
int _E168_22()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_26, "Render.MultiPassAlpha");
  return atexit(_E169_60);
}

//----- (006FE6F0) --------------------------------------------------------  // acclient.c:786599
int _E171_21()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_26, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8449B4, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8449B8, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8449BC, "Anisotropic");
  return atexit(_E172_58);
}

//----- (006FE740) --------------------------------------------------------  // acclient.c:786609
int _E174_22()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_26, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8449C4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8449C8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8449CC, "High");
  PStringBase<char>::PStringBase<char>(&stru_8449D0, "VeryHigh");
  return atexit(_E175_55);
}

//----- (006FE7A0) --------------------------------------------------------  // acclient.c:786620
int _E177_20()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_26, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8449D8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8449DC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8449E0, "High");
  PStringBase<char>::PStringBase<char>(&stru_8449E4, "VeryHigh");
  return atexit(_E178_55);
}

//----- (006FE800) --------------------------------------------------------  // acclient.c:786631
int _E180_20()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_26, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8449EC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8449F0, "High");
  return atexit(_E181_55);
}

//----- (006FE840) --------------------------------------------------------  // acclient.c:786640
int _E183_19()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_26, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8449F8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8449FC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_844A00, "High");
  PStringBase<char>::PStringBase<char>(&stru_844A04, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_844A08, "Extreme");
  return atexit(_E184_52);
}

//----- (006FE8B0) --------------------------------------------------------  // acclient.c:786652
int _E186_19()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_26, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_844A10, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_844A14, "Wide");
  return atexit(_E187_51);
}

//----- (006FE8F0) --------------------------------------------------------  // acclient.c:786661
int _E189_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_50, "None");
  return atexit(_E190_52);
}

//----- (006FE910) --------------------------------------------------------  // acclient.c:786668
int _E192_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_50, "Speed");
  return atexit(_E193_44);
}

//----- (006FE930) --------------------------------------------------------  // acclient.c:786675
int _E195_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_50, "Noise");
  return atexit(_E196_51);
}

//----- (006FE950) --------------------------------------------------------  // acclient.c:786682
int _E198_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_50, "Sine");
  return atexit(_E199_43);
}

//----- (006FE970) --------------------------------------------------------  // acclient.c:786689
int _E201_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_50, "Square");
  return atexit(_E202_44);
}

//----- (006FE990) --------------------------------------------------------  // acclient.c:786696
int _E204_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_50, "Bounce");
  return atexit(_E205_40);
}

//----- (006FE9B0) --------------------------------------------------------  // acclient.c:786703
int _E207_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_50, "Perlin");
  return atexit(_E208_44);
}

//----- (006FE9D0) --------------------------------------------------------  // acclient.c:786710
int _E210_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_50, "Fractal");
  return atexit(_E211_40);
}

//----- (006FE9F0) --------------------------------------------------------  // acclient.c:786717
int _E213_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_50, "FrameLoop");
  return atexit(_E214_43);
}

//----- (006FEA10) --------------------------------------------------------  // acclient.c:786724
int _E216_9()
{
  return atexit(_E217_39);
}

//----- (006FEA20) --------------------------------------------------------  // acclient.c:786730
int _E219_6()
{
  return atexit(_E220_38);
}

//----- (006FEA30) --------------------------------------------------------  // acclient.c:786736
int _E222_5()
{
  return atexit(_E223_38);
}

//----- (006FEA40) --------------------------------------------------------  // acclient.c:786742
int _E225_5()
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0> *)&CEnvCell::visible_cell_table.m_intrusiveTable,
    0x80u);
  return atexit(_E226_24);
}

//----- (006FEA60) --------------------------------------------------------  // acclient.c:786751
int _E228_5()
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0> *)&stru_81DDA4,
    0x80u);
  return atexit(_E229_24);
}

//----- (006FEA80) --------------------------------------------------------  // acclient.c:786760
unsigned int _E231_5()
{
  unsigned int result; // eax@1

  result = Logger::CreateLoggingCategory("BlockAndCellLoading");
  lcat_BlockAndCellLoading = result;
  return result;
}
// 844A3C: using guessed type unsigned __int32 lcat_BlockAndCellLoading;

//----- (006FEAA0) --------------------------------------------------------  // acclient.c:786771
int sub_6FEAA0()
{
  return atexit(nullsub_1159);
}

//----- (00768B10) --------------------------------------------------------  // acclient.c:895576
void __cdecl _E190_52()
{
  char *v0; // esi@1

  v0 = &waveform_None_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768B40) --------------------------------------------------------  // acclient.c:895589
void __cdecl _E193_44()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768B70) --------------------------------------------------------  // acclient.c:895602
void __cdecl _E196_51()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768BA0) --------------------------------------------------------  // acclient.c:895615
void __cdecl _E199_43()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768BD0) --------------------------------------------------------  // acclient.c:895628
void __cdecl _E202_44()
{
  char *v0; // esi@1

  v0 = &waveform_Square_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768C00) --------------------------------------------------------  // acclient.c:895641
void __cdecl _E205_40()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768C30) --------------------------------------------------------  // acclient.c:895654
void __cdecl _E208_44()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768C60) --------------------------------------------------------  // acclient.c:895667
void __cdecl _E211_40()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768C90) --------------------------------------------------------  // acclient.c:895680
void __cdecl _E214_43()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768CC0) --------------------------------------------------------  // acclient.c:895693
void __cdecl sub_768CC0()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768CF0) --------------------------------------------------------  // acclient.c:895706
void __cdecl _E113_65()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768D20) --------------------------------------------------------  // acclient.c:895719
void __cdecl _E116_57()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768D50) --------------------------------------------------------  // acclient.c:895732
void __cdecl _E119_85()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768D80) --------------------------------------------------------  // acclient.c:895745
void __cdecl sub_768D80()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768DB0) --------------------------------------------------------  // acclient.c:895758
void __cdecl sub_768DB0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768DE0) --------------------------------------------------------  // acclient.c:895771
void __cdecl _E130_97()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768E10) --------------------------------------------------------  // acclient.c:895784
void __cdecl _E133_91()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768E40) --------------------------------------------------------  // acclient.c:895797
void __cdecl _E136_74()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768E70) --------------------------------------------------------  // acclient.c:895810
void __cdecl _E139_74()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768EA0) --------------------------------------------------------  // acclient.c:895823
void __cdecl _E142_69()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768ED0) --------------------------------------------------------  // acclient.c:895836
void __cdecl _E145_71()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768F00) --------------------------------------------------------  // acclient.c:895849
void __cdecl _E148_68()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768F30) --------------------------------------------------------  // acclient.c:895862
void __cdecl _E151_66()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768F60) --------------------------------------------------------  // acclient.c:895875
void __cdecl _E154_67()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768F90) --------------------------------------------------------  // acclient.c:895888
void __cdecl _E157_63()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768FC0) --------------------------------------------------------  // acclient.c:895901
void __cdecl _E160_66()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768FF0) --------------------------------------------------------  // acclient.c:895914
void __cdecl _E163_59()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769020) --------------------------------------------------------  // acclient.c:895927
void __cdecl _E166_61()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769050) --------------------------------------------------------  // acclient.c:895940
void __cdecl _E169_60()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769080) --------------------------------------------------------  // acclient.c:895953
void __cdecl _E172_58()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_26;
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

//----- (007690C0) --------------------------------------------------------  // acclient.c:895978
void __cdecl _E175_55()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_26;
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

//----- (00769100) --------------------------------------------------------  // acclient.c:896003
void __cdecl _E178_55()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_26;
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

//----- (00769140) --------------------------------------------------------  // acclient.c:896028
void __cdecl _E181_55()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_26;
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

//----- (00769180) --------------------------------------------------------  // acclient.c:896053
void __cdecl _E184_52()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_26;
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

//----- (007691C0) --------------------------------------------------------  // acclient.c:896078
void __cdecl _E187_51()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_50;
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

//----- (00769200) --------------------------------------------------------  // acclient.c:896103
void __cdecl _E226_24()
{
  CEnvCell::visible_cell_table.vfptr = (HashTable<unsigned long,RenderVertexStreamD3D *,0>Vtbl *)&HashTable<unsigned long,CEnvCell *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents(&CEnvCell::visible_cell_table.m_intrusiveTable);
  CEnvCell::visible_cell_table.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::vftable;
  if ( (HashTableData<unsigned long,RenderVertexStreamD3D *> **)CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets != CEnvCell::visible_cell_table.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets);
  CEnvCell::visible_cell_table.m_intrusiveTable.m_buckets = 0;
  CEnvCell::visible_cell_table.m_intrusiveTable.m_firstInterestingBucket = 0;
  CEnvCell::visible_cell_table.m_intrusiveTable.m_numBuckets = 0;
  CEnvCell::visible_cell_table.m_intrusiveTable.m_numElements = 0;
}
// 7C8D38: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::vftable[2])(void *, char);
// 7C8D3C: using guessed type int (__thiscall *HashTable<unsigned long,CEnvCell *,0>::vftable)(void *, char);

//----- (00769250) --------------------------------------------------------  // acclient.c:896119
void __cdecl _E229_24()
{
  CEnvCell::cell_flush_table = &HashTable<unsigned long,CEnvCell *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_81DDA4);
  stru_81DDA4.vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::vftable;
  if ( (HashSetData<IDClass<_tagDataID,32,0> > **)stru_81DDA4.m_buckets != stru_81DDA4.m_aInplaceBuckets )
    operator delete[](stru_81DDA4.m_buckets);
  stru_81DDA4.m_buckets = 0;
  stru_81DDA4.m_firstInterestingBucket = 0;
  stru_81DDA4.m_numBuckets = 0;
  stru_81DDA4.m_numElements = 0;
}
// 7C8D38: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::vftable[2])(void *, char);
// 7C8D3C: using guessed type int (__thiscall *HashTable<unsigned long,CEnvCell *,0>::vftable)(void *, char);
// 81DDA0: using guessed type int (__thiscall **CEnvCell::cell_flush_table)(void *, char);

