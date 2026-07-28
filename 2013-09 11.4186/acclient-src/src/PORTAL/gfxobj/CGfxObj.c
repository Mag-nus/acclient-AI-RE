/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CGfxObj
   Object     : PORTAL\gfxobj\CGfxObj.obj
   Functions  : 94
   Addresses  : 00526840 - 0076A230 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00526840) --------------------------------------------------------  // acclient.c:342035
signed int UIElement_Menu::GetUIElementType()
{
  return 6;
}

//----- (00534150) --------------------------------------------------------  // acclient.c:356168
void __thiscall BBox::AdjustBBox(BBox *this, Vector3 *vc)
{
  if ( vc->x < (double)this->m_vMin.x )
    this->m_vMin.x = vc->x;
  if ( vc->y < (double)this->m_vMin.y )
    this->m_vMin.y = vc->y;
  if ( vc->z < (double)this->m_vMin.z )
    this->m_vMin.z = vc->z;
  if ( vc->x > (double)this->m_vMax.x )
    this->m_vMax.x = vc->x;
  if ( vc->y > (double)this->m_vMax.y )
    this->m_vMax.y = vc->y;
  if ( vc->z > (double)this->m_vMax.z )
    this->m_vMax.z = vc->z;
}

//----- (005341D0) --------------------------------------------------------  // acclient.c:356185
char __thiscall CGfxObj::TexVelocity(CGfxObj *this, CVec2Duv delta)
{
  MeshBuffer *v2; // eax@1

  v2 = this->constructed_mesh;
  if ( v2 )
  {
    v2->m_bUseUVAnimation = 1;
    this->constructed_mesh->m_vUVDelta = delta;
  }
  return 1;
}

//----- (00534200) --------------------------------------------------------  // acclient.c:356199
void __thiscall CGfxObj::init_end(CGfxObj *this)
{
  CGfxObj *v1; // esi@1
  CVertex *v2; // eax@3
  char *v3; // ebx@3
  char *v4; // ecx@3
  signed int v5; // edi@3

  v1 = this;
  if ( this->vertex_array.num_vertices )
  {
    v2 = this->vertex_array.vertices;
    v3 = (char *)&this->gfx_bound_box;
    *(_DWORD *)v3 = LODWORD(v2->x);
    *((_DWORD *)v3 + 1) = LODWORD(v2->y);
    *((_DWORD *)v3 + 2) = LODWORD(v2->z);
    v4 = (char *)&this->gfx_bound_box.m_vMax;
    *(_DWORD *)v4 = LODWORD(v2->x);
    *((_DWORD *)v4 + 1) = LODWORD(v2->y);
    *((_DWORD *)v4 + 2) = LODWORD(v2->z);
    v5 = 1;
    if ( v1->vertex_array.num_vertices > 1 )
    {
      do
        BBox::AdjustBBox(
          &v1->gfx_bound_box,
          (Vector3 *)((char *)v1->vertex_array.vertices + v5++ * CVertexArray::vertex_size));
      while ( v5 < v1->vertex_array.num_vertices );
    }
  }
  else
  {
    this->gfx_bound_box.m_vMin = stru_844EB4.0;
    this->gfx_bound_box.m_vMax = stru_844EB4.0;
  }
}
// 81E700: using guessed type unsigned __int32 CVertexArray::vertex_size;

//----- (005342C0) --------------------------------------------------------  // acclient.c:356238
void __cdecl SB_AsPackObj<0>::Serialize(CGfxObj *const *__formal, CVertexArray *i_obj, Archive *io_archive)
{
  void *v3; // ecx@0
  Archive *v4; // esi@1
  signed int v5; // edi@2
  unsigned int v6; // edi@4
  unsigned int v7; // eax@4
  unsigned int v8; // ebx@4
  void *pCurrent; // [sp+0h] [bp-4h]@1

  pCurrent = v3;
  v4 = io_archive;
  if ( io_archive->m_flags & 1 )
  {
    io_archive = 0;
    v5 = CVertexArray::Pack(i_obj, (void **)&io_archive, 0);
    pCurrent = (void *)Archive::GetBytes(v4, v5);
    if ( pCurrent )
      CVertexArray::Pack(i_obj, &pCurrent, v5);
  }
  else
  {
    v6 = Archive::GetSizeLeft(io_archive);
    v7 = Archive::GetSizeUsed(v4);
    v8 = Archive::PeekBytes(v4, v7, v6);
    io_archive = (Archive *)v8;
    if ( CVertexArray::UnPack(i_obj, (void **)&io_archive, v6) )
      Archive::GetBytes(v4, (unsigned int)((char *)io_archive - v8));
    else
      Archive::RaiseError(v4);
  }
}

//----- (00534360) --------------------------------------------------------  // acclient.c:356272
void __cdecl SB_AsPackObj<0>::Serialize(CGfxObj *const *__formal, CPolygon *i_obj, Archive *io_archive)
{
  void *v3; // ecx@0
  Archive *v4; // esi@1
  unsigned int v5; // edi@2
  unsigned int v6; // edi@4
  unsigned int v7; // eax@4
  unsigned int v8; // ebx@4
  void *pCurrent; // [sp+0h] [bp-4h]@1

  pCurrent = v3;
  v4 = io_archive;
  if ( io_archive->m_flags & 1 )
  {
    io_archive = 0;
    v5 = CPolygon::Pack(i_obj, (void **)&io_archive, 0);
    pCurrent = (void *)Archive::GetBytes(v4, v5);
    if ( pCurrent )
      CPolygon::Pack(i_obj, &pCurrent, v5);
  }
  else
  {
    v6 = Archive::GetSizeLeft(io_archive);
    v7 = Archive::GetSizeUsed(v4);
    v8 = Archive::PeekBytes(v4, v7, v6);
    io_archive = (Archive *)v8;
    if ( CPolygon::UnPack(i_obj, (void **)&io_archive, v6) )
      Archive::GetBytes(v4, (unsigned int)((char *)io_archive - v8));
    else
      Archive::RaiseError(v4);
  }
}

//----- (00534400) --------------------------------------------------------  // acclient.c:356306
void __cdecl SB_AsPackObj<0>::Serialize(CGfxObj *const *__formal, BSPTREE *i_obj, Archive *io_archive)
{
  void *v3; // ecx@0
  Archive *v4; // esi@1
  int v5; // edi@2
  unsigned int v6; // edi@4
  unsigned int v7; // eax@4
  unsigned int v8; // ebx@4
  void *pCurrent; // [sp+0h] [bp-4h]@1

  pCurrent = v3;
  v4 = io_archive;
  if ( io_archive->m_flags & 1 )
  {
    io_archive = 0;
    v5 = BSPTREE::Pack(i_obj, (void **)&io_archive, 0);
    pCurrent = (void *)Archive::GetBytes(v4, v5);
    if ( pCurrent )
      BSPTREE::Pack(i_obj, &pCurrent, v5);
  }
  else
  {
    v6 = Archive::GetSizeLeft(io_archive);
    v7 = Archive::GetSizeUsed(v4);
    v8 = Archive::PeekBytes(v4, v7, v6);
    io_archive = (Archive *)v8;
    if ( BSPTREE::UnPack(i_obj, (void **)&io_archive, v6) )
      Archive::GetBytes(v4, (unsigned int)((char *)io_archive - v8));
    else
      Archive::RaiseError(v4);
  }
}

//----- (005344A0) --------------------------------------------------------  // acclient.c:356340
BOOL __thiscall CSphere::intersects(CSphere *this, CSphere *s)
{
  double v2; // st7@1
  double v3; // st6@1
  double v4; // st5@1
  double v5; // st4@1
  unsigned __int8 v7; // c0@1
  unsigned __int8 v8; // c2@1

  v2 = this->center.x - s->center.x;
  v3 = this->center.y - s->center.y;
  v4 = this->center.z - s->center.z;
  v5 = s->radius + this->radius;
  return (v7 | v8) != 0;
}

//----- (00534500) --------------------------------------------------------  // acclient.c:356357
void __thiscall CGfxObj::CGfxObj(CGfxObj *this)
{
  CGfxObj *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, AnID);
  v1->vfptr = (InterfaceVtbl *)&CGfxObj::vftable;
  v1->material = 0;
  v1->num_surfaces = 0;
  v1->m_rgSurfaces = 0;
  CVertexArray::CVertexArray(&v1->vertex_array);
  v1->num_physics_polygons = 0;
  v1->physics_polygons = 0;
  v1->constructed_mesh = 0;
  v1->use_built_mesh = 0;
  v1->physics_sphere = 0;
  v1->physics_bsp = 0;
  LODWORD(v1->sort_center.x) = 0;
  LODWORD(v1->sort_center.y) = 0;
  LODWORD(v1->sort_center.z) = 0;
  v1->num_polygons = 0;
  v1->polygons = 0;
  v1->drawing_sphere = 0;
  v1->drawing_bsp = 0;
  v1->m_didDegrade.id = AnID.id;
}
// 7C9650: using guessed type __int32 (__stdcall *CGfxObj::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00534580) --------------------------------------------------------  // acclient.c:356386
void __thiscall CGfxObj::Destroy(CGfxObj *this)
{
  CGfxObj *v1; // esi@1
  BSPTREE *v2; // edi@1
  CPolygon *v3; // ecx@3
  float v4; // eax@4
  void *v5; // ebp@4
  CPolygon *v6; // edi@4
  int v7; // eax@4
  int v8; // ebx@5
  CPolygon *v9; // ecx@8
  float v10; // eax@9
  void *v11; // ebp@9
  CPolygon *v12; // edi@9
  int v13; // eax@9
  int v14; // ebx@10
  BSPTREE *v15; // edi@13
  signed int i; // edi@18
  CSurface *v17; // ecx@19
  MeshBuffer *v18; // eax@23
  MeshBuffer **v19; // esi@23

  v1 = this;
  v2 = this->drawing_bsp;
  if ( v2 )
  {
    BSPTREE::~BSPTREE(this->drawing_bsp);
    operator delete(v2);
    v1->drawing_bsp = 0;
  }
  v3 = v1->polygons;
  v1->drawing_sphere = 0;
  if ( v3 )
  {
    v4 = v3[-1].plane.d;
    v5 = &v3[-1].plane.d;
    v6 = &v3[LODWORD(v4)];
    v7 = LODWORD(v4) - 1;
    if ( v7 >= 0 )
    {
      v8 = v7 + 1;
      do
      {
        --v6;
        CPolygon::Destroy(v6);
        --v8;
      }
      while ( v8 );
    }
    operator delete[](v5);
    v1->polygons = 0;
  }
  v9 = v1->physics_polygons;
  v1->num_polygons = 0;
  if ( v9 )
  {
    v10 = v9[-1].plane.d;
    v11 = &v9[-1].plane.d;
    v12 = &v9[LODWORD(v10)];
    v13 = LODWORD(v10) - 1;
    if ( v13 >= 0 )
    {
      v14 = v13 + 1;
      do
      {
        --v12;
        CPolygon::Destroy(v12);
        --v14;
      }
      while ( v14 );
    }
    operator delete[](v11);
    v1->physics_polygons = 0;
  }
  v15 = v1->physics_bsp;
  v1->num_physics_polygons = 0;
  if ( v15 )
  {
    BSPTREE::~BSPTREE(v15);
    operator delete(v15);
    v1->physics_bsp = 0;
  }
  if ( v1->physics_sphere )
    v1->physics_sphere = 0;
  CVertexArray::DestroyVertex(&v1->vertex_array);
  if ( v1->m_rgSurfaces )
  {
    for ( i = 0; i < (signed int)v1->num_surfaces; ++i )
    {
      v17 = v1->m_rgSurfaces[i];
      if ( v17 )
        ((void (*)(void))v17->vfptr->Release)();
    }
    operator delete[](v1->m_rgSurfaces);
    v1->m_rgSurfaces = 0;
  }
  v18 = v1->constructed_mesh;
  v1->num_surfaces = 0;
  v19 = &v1->constructed_mesh;
  if ( v18 )
  {
    D3DPolyRender::DestroyMesh(v19);
    *v19 = 0;
  }
}

//----- (005346B0) --------------------------------------------------------  // acclient.c:356493
char __thiscall CGfxObj::InitLoad(CGfxObj *this)
{
  CGfxObj *v1; // esi@1
  BSPTREE *v2; // ecx@2
  MeshBuffer *v3; // ecx@4

  v1 = this;
  if ( DBCache::IsRunTime() )
  {
    v2 = v1->drawing_bsp;
    if ( v2 )
      BSPTREE::RemoveNonPortalNodes(v2);
    v3 = v1->constructed_mesh;
    v1->use_built_mesh = 1;
    if ( v3 || !D3DPolyRender::ConstructMesh(v1, &v1->constructed_mesh) )
      v1->use_built_mesh = 0;
  }
  return 1;
}

//----- (00534700) --------------------------------------------------------  // acclient.c:356514
signed int __thiscall CGfxObj::find_obj_collisions(CGfxObj *this, CTransition *transition, float scale)
{
  unsigned int v3; // ebx@1
  unsigned int v4; // esi@1
  signed int result; // eax@1
  CSphere *v6; // edx@2
  CSphere *v7; // edi@2
  double v8; // st7@3
  double v9; // st6@3
  double v10; // st5@3
  double v11; // st4@3
  unsigned __int8 v13; // c0@3
  unsigned __int8 v14; // c2@3
  BSPTREE *v15; // ecx@7

  v3 = transition->sphere_path.num_sphere;
  v4 = 0;
  result = 1;
  if ( v3 )
  {
    v6 = transition->sphere_path.localspace_sphere;
    v7 = this->physics_sphere;
    while ( 1 )
    {
      v8 = v7->center.x - v6->center.x;
      v9 = v7->center.y - v6->center.y;
      v10 = v7->center.z - v6->center.z;
      v11 = v6->radius + v7->radius;
      if ( v13 | v14 )
        break;
      ++v4;
      ++v6;
      if ( v4 >= v3 )
        return 1;
    }
    v15 = this->physics_bsp;
    if ( transition->sphere_path.insert_type == 2 )
      result = BSPTREE::placement_insert(v15, transition);
    else
      result = BSPTREE::find_collisions(v15, transition, scale);
  }
  return result;
}

//----- (005347A0) --------------------------------------------------------  // acclient.c:356559
void __cdecl SB_AsPackObj<0>::Serialize(CGfxObj *const *__formal, AC1Legacy::Vector3 *i_obj, Archive *io_archive)
{
  unsigned int v3; // eax@2
  int v4; // eax@3
  unsigned int v5; // eax@4
  unsigned int v6; // edi@4
  unsigned int v7; // ST04_4@4
  unsigned int v8; // eax@4
  unsigned int v9; // eax@4

  if ( io_archive->m_flags & 1 )
  {
    v3 = Archive::GetBytes(io_archive, 0xCu);
    if ( v3 )
    {
      *(_DWORD *)v3 = LODWORD(i_obj->x);
      v4 = v3 + 4;
      *(_DWORD *)v4 = LODWORD(i_obj->y);
      *(_DWORD *)(v4 + 4) = LODWORD(i_obj->z);
    }
  }
  else
  {
    v5 = Archive::GetSizeLeft(io_archive);
    v6 = v5;
    v7 = v5;
    v8 = Archive::GetSizeUsed(io_archive);
    v9 = Archive::PeekBytes(io_archive, v8, v7);
    if ( v6 < 0xC )
    {
      Archive::RaiseError(io_archive);
    }
    else
    {
      LODWORD(i_obj->x) = *(_DWORD *)v9;
      LODWORD(i_obj->y) = *(_DWORD *)(v9 + 4);
      LODWORD(i_obj->z) = *(_DWORD *)(v9 + 8);
      Archive::GetBytes(io_archive, 0xCu);
    }
  }
}

//----- (00534830) --------------------------------------------------------  // acclient.c:356602
CGfxObj *__thiscall CGfxObj::scalar_deleting_destructor(CGfxObj *this, unsigned int a2)
{
  CGfxObj *v2; // esi@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&CGfxObj::vftable;
  CGfxObj::Destroy(this);
  gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&v2->vertex_array);
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9650: using guessed type __int32 (__stdcall *CGfxObj::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00534870) --------------------------------------------------------  // acclient.c:356618
void __thiscall CGfxObj::GetSubDataIDs(CGfxObj *this, QualifiedDataIDArray *id_array)
{
  CGfxObj *v2; // esi@1
  unsigned int v3; // edi@1
  CSurface *v4; // eax@2
  QualifiedDataID *v5; // eax@3
  QualifiedDataID *v6; // eax@5
  QualifiedDataID v7; // [sp+Ch] [bp-8h]@3

  v2 = this;
  v3 = 0;
  if ( this->num_surfaces )
  {
    do
    {
      v4 = v2->m_rgSurfaces[v3];
      if ( v4 )
      {
        QualifiedDataID::QualifiedDataID(&v7, v4->m_DID, 0);
        QualifiedDataIDArray::AddQDID(id_array, v5, 0);
      }
      ++v3;
    }
    while ( v3 < v2->num_surfaces );
  }
  QualifiedDataID::QualifiedDataID(&v7, v2->m_didDegrade, 0);
  QualifiedDataIDArray::AddQDID(id_array, v6, 0);
}

//----- (005348E0) --------------------------------------------------------  // acclient.c:356648
void __cdecl SB_AsDataID<0>::Serialize(CGfxObj *const *__formal, CSurface **_obj, Archive *_arc)
{
  unsigned int v3; // edi@1
  unsigned int v4; // eax@4
  QualifiedDataID *v5; // eax@11
  QualifiedDataID v6; // [sp+Ch] [bp-8h]@11

  v3 = AnID.id;
  if ( _arc->m_flags & 1 && *_obj )
    v3 = (*_obj)->m_DID.id;
  Archive::CheckAlignment(_arc, 4u);
  v4 = Archive::GetBytes(_arc, 4u);
  if ( v4 )
  {
    if ( _arc->m_flags & 1 )
      *(_DWORD *)v4 = v3;
    else
      v3 = *(_DWORD *)v4;
  }
  if ( ~LOBYTE(_arc->m_flags) & 1 )
  {
    if ( v3 == AnID.id )
    {
      *_obj = 0;
    }
    else
    {
      QualifiedDataID::QualifiedDataID(&v6, (IDClass<_tagDataID,32,0>)v3, 0xDu);
      *_obj = (CSurface *)DBObj::Get(v5);
    }
  }
}

//----- (00534970) --------------------------------------------------------  // acclient.c:356682
void __thiscall CGfxObj::Serialize(CGfxObj *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  CGfxObj *v3; // edi@1
  char v4; // al@1
  int v5; // ebp@1
  Archive **v6; // eax@8
  int v7; // ebx@12
  int v8; // ebx@19
  float v9; // ebp@20
  void *v10; // eax@20
  struct CPolygon *v11; // eax@21
  int v12; // ebp@21
  CPolygon *v13; // ebx@21
  int v14; // ebp@22
  signed int v15; // ebp@27
  int v16; // ebx@28
  ClipPlane *v17; // eax@32
  BSPTREE *v18; // eax@33
  BSPTREE *v19; // eax@36
  int v20; // ebx@42
  float v21; // ebp@43
  void *v22; // eax@43
  struct CPolygon *v23; // eax@44
  int v24; // ebp@44
  CPolygon *v25; // ebx@44
  int v26; // ebp@45
  signed int v27; // ebp@50
  int v28; // ebx@51
  ClipPlane *v29; // eax@55
  BSPTREE *v30; // eax@56
  BSPTREE *v31; // eax@59
  unsigned int v32; // eax@65
  struct CPolygon *v33; // [sp+10h] [bp-4h]@21
  struct CPolygon *v34; // [sp+10h] [bp-4h]@44

  v2 = io_archive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  v4 = LOBYTE(v2->m_flags);
  v5 = 0;
  io_archive = 0;
  if ( v4 & 1 )
  {
    if ( v3->physics_bsp )
      io_archive = (Archive *)1;
    if ( v3->drawing_bsp )
      io_archive = (Archive *)((unsigned int)io_archive | 2);
    if ( AnID.id != v3->m_didDegrade.id )
      io_archive = (Archive *)((unsigned int)io_archive | 8);
  }
  Archive::CheckAlignment(v2, 4u);
  v6 = (Archive **)Archive::GetBytes(v2, 4u);
  if ( v6 )
  {
    if ( v2->m_flags & 1 )
      *v6 = io_archive;
    else
      io_archive = *v6;
  }
  v7 = (int)&v3->num_surfaces;
  SB_As32Bit_Compressed::Serialize((const int *)&io_archive, &v3->num_surfaces, v2);
  if ( ~LOBYTE(v2->m_flags) & 1 )
    v3->m_rgSurfaces = (CSurface **)operator new[](4 * *(_DWORD *)v7);
  if ( *(_DWORD *)v7 > 0 )
  {
    do
      SB_AsDataID<0>::Serialize((CGfxObj *const *)&io_archive, &v3->m_rgSurfaces[v5++], v2);
    while ( v5 < *(_DWORD *)v7 );
  }
  SB_AsPackObj<0>::Serialize((CGfxObj *const *)&io_archive, &v3->vertex_array, v2);
  if ( ~LOBYTE(v2->m_flags) & 1 )
    CPolygon::pack_verts = &v3->vertex_array;
  if ( (unsigned __int8)io_archive & 1 )
  {
    v8 = (int)&v3->num_physics_polygons;
    SB_As32Bit_Compressed::Serialize((const int *)&io_archive, &v3->num_physics_polygons, v2);
    if ( ~LOBYTE(v2->m_flags) & 1 )
    {
      v9 = *(float *)v8;
      v10 = operator new[](48 * *(_DWORD *)v8 + 4);
      if ( v10 )
      {
        v11 = (struct CPolygon *)((char *)v10 + 4);
        v11[-1].plane.d = v9;
        v12 = LODWORD(v9) - 1;
        v33 = v11;
        v13 = v11;
        if ( v12 >= 0 )
        {
          v14 = v12 + 1;
          do
          {
            CPolygon::CPolygon(v13);
            ++v13;
            --v14;
          }
          while ( v14 );
          v11 = v33;
        }
      }
      else
      {
        v11 = 0;
      }
      v3->physics_polygons = v11;
      BSPNODE::pack_poly = v11;
    }
    v15 = 0;
    if ( (signed int)v3->num_physics_polygons > 0 )
    {
      v16 = 0;
      do
      {
        SB_AsPackObj<0>::Serialize((CGfxObj *const *)&io_archive, &v3->physics_polygons[v16], v2);
        ++v15;
        ++v16;
      }
      while ( v15 < (signed int)v3->num_physics_polygons );
    }
    BSPNODE::pack_tree_type = 1;
    if ( !((v2->m_flags >> 2) & 1) )
    {
      if ( ~LOBYTE(v2->m_flags) & 1 )
      {
        v17 = (ClipPlane *)operator new(4u);
        if ( v17 )
          ClipPlane::ClipPlane(v17);
        else
          v18 = 0;
        v3->physics_bsp = v18;
      }
      v19 = v3->physics_bsp;
      if ( v19 )
        SB_AsPackObj<0>::Serialize((CGfxObj *const *)&io_archive, v19, v2);
      else
        Archive::RaiseError(v2);
    }
    if ( ~LOBYTE(v2->m_flags) & 1 )
      v3->physics_sphere = BSPTREE::GetSphere(v3->physics_bsp);
  }
  SB_AsPackObj<0>::Serialize((CGfxObj *const *)&io_archive, &v3->sort_center, v2);
  if ( (unsigned __int8)io_archive & 2 )
  {
    v20 = (int)&v3->num_polygons;
    SB_As32Bit_Compressed::Serialize((const int *)&io_archive, &v3->num_polygons, v2);
    if ( ~LOBYTE(v2->m_flags) & 1 )
    {
      v21 = *(float *)v20;
      v22 = operator new[](48 * *(_DWORD *)v20 + 4);
      if ( v22 )
      {
        v23 = (struct CPolygon *)((char *)v22 + 4);
        v23[-1].plane.d = v21;
        v24 = LODWORD(v21) - 1;
        v34 = v23;
        v25 = v23;
        if ( v24 >= 0 )
        {
          v26 = v24 + 1;
          do
          {
            CPolygon::CPolygon(v25);
            ++v25;
            --v26;
          }
          while ( v26 );
          v23 = v34;
        }
      }
      else
      {
        v23 = 0;
      }
      v3->polygons = v23;
      BSPNODE::pack_poly = v23;
    }
    v27 = 0;
    if ( (signed int)v3->num_polygons > 0 )
    {
      v28 = 0;
      do
      {
        SB_AsPackObj<0>::Serialize((CGfxObj *const *)&io_archive, &v3->polygons[v28], v2);
        ++v27;
        ++v28;
      }
      while ( v27 < (signed int)v3->num_polygons );
    }
    BSPNODE::pack_tree_type = 0;
    if ( !((v2->m_flags >> 2) & 1) )
    {
      if ( ~LOBYTE(v2->m_flags) & 1 )
      {
        v29 = (ClipPlane *)operator new(4u);
        if ( v29 )
          ClipPlane::ClipPlane(v29);
        else
          v30 = 0;
        v3->drawing_bsp = v30;
      }
      v31 = v3->drawing_bsp;
      if ( v31 )
        SB_AsPackObj<0>::Serialize((CGfxObj *const *)&io_archive, v31, v2);
      else
        Archive::RaiseError(v2);
    }
    if ( ~LOBYTE(v2->m_flags) & 1 )
      v3->drawing_sphere = BSPTREE::GetSphere(v3->drawing_bsp);
  }
  if ( (unsigned __int8)io_archive & 8 )
  {
    Archive::CheckAlignment(v2, 4u);
    v32 = Archive::GetBytes(v2, 4u);
    if ( v32 )
    {
      if ( v2->m_flags & 1 )
        *(_DWORD *)v32 = v3->m_didDegrade.id;
      else
        v3->m_didDegrade.id = *(_DWORD *)v32;
    }
  }
  if ( ~LOBYTE(v2->m_flags) & 1 )
    CGfxObj::init_end(v3);
}
// 8450FC: using guessed type struct CVertexArray *CPolygon::pack_verts;
// 845378: using guessed type struct CPolygon *BSPNODE::pack_poly;
// 84537C: using guessed type enum BSPTreeType BSPNODE::pack_tree_type;

//----- (006FF8A0) --------------------------------------------------------  // acclient.c:787566
int _E73_94()
{
  return atexit(_E74_70);
}

//----- (006FF8B0) --------------------------------------------------------  // acclient.c:787572
int _E76_56()
{
  return atexit(_E77_84);
}

//----- (006FF8C0) --------------------------------------------------------  // acclient.c:787578
int _E79_49()
{
  return atexit(_E80_48);
}

//----- (006FF8D0) --------------------------------------------------------  // acclient.c:787584
void _E82_30()
{
  PixelFormatDesc::PixelFormatDesc(&stru_844ED0, PFID_A8R8G8B8);
}

//----- (006FF8E0) --------------------------------------------------------  // acclient.c:787590
void sub_6FF8E0()
{
  dword_844F08 = 1024;
}

//----- (006FF8F0) --------------------------------------------------------  // acclient.c:787596
void _E102_20()
{
  dword_844F0C = 0x7FFF;
}

//----- (006FF900) --------------------------------------------------------  // acclient.c:787602
int _E104_10()
{
  const int result; // eax@1

  result = dword_844F08;
  INITIAL_MAX_DATA_RATE_92 = dword_844F08;
  return result;
}

//----- (006FF910) --------------------------------------------------------  // acclient.c:787612
void _E106_97()
{
  LODWORD(dword_844F14) = 1053364187;
}

//----- (006FF920) --------------------------------------------------------  // acclient.c:787618
void _E108_75()
{
  flt_844F18 = 1000.0 + 1.0;
}

//----- (006FF940) --------------------------------------------------------  // acclient.c:787624
void _E110_61()
{
  flt_844F1C = 24.0 * 8.0;
}

//----- (006FF960) --------------------------------------------------------  // acclient.c:787630
void _E112_91()
{
  flt_844F20 = 24.0 * 0.5;
}

//----- (006FF980) --------------------------------------------------------  // acclient.c:787636
void _E114_49()
{
  flt_844F24 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FF9A0) --------------------------------------------------------  // acclient.c:787642
void _E116_20()
{
  dbl_844F28 = 1.0 / 30.0;
}

//----- (006FF9C0) --------------------------------------------------------  // acclient.c:787648
void _E118_68()
{
  dbl_844F30 = 1.0 / 5.0;
}

//----- (006FF9E0) --------------------------------------------------------  // acclient.c:787654
int _E120_56()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_28, "Render.TextureFiltering");
  return atexit(sub_769E70);
}

//----- (006FFA00) --------------------------------------------------------  // acclient.c:787661
int _E123_34()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_28, "Render.LandscapeDetailTextures");
  return atexit(sub_769EA0);
}

//----- (006FFA20) --------------------------------------------------------  // acclient.c:787668
int _E126_40()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_28, "Render.BuildingDetailTextures");
  return atexit(sub_769ED0);
}

//----- (006FFA40) --------------------------------------------------------  // acclient.c:787675
int _E129_32()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_28, "Render.FieldOfView");
  return atexit(sub_769F00);
}

//----- (006FFA60) --------------------------------------------------------  // acclient.c:787682
int _E132_35()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_28, "Render.LandscapeTextureDetail");
  return atexit(_E133_94);
}

//----- (006FFA80) --------------------------------------------------------  // acclient.c:787689
int _E135_38()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_28, "Render.EnvironmentTextureDetail");
  return atexit(_E136_77);
}

//----- (006FFAA0) --------------------------------------------------------  // acclient.c:787696
int _E138_30()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_28, "Render.SceneryDrawDistance");
  return atexit(_E139_77);
}

//----- (006FFAC0) --------------------------------------------------------  // acclient.c:787703
int _E141_30()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_28, "Render.LandscapeDrawDistance");
  return atexit(_E142_72);
}

//----- (006FFAE0) --------------------------------------------------------  // acclient.c:787710
int _E144_29()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_28, "Render.ScreenBrightness");
  return atexit(_E145_74);
}

//----- (006FFB00) --------------------------------------------------------  // acclient.c:787717
int _E147_27()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_28, "Render.AspectRatio");
  return atexit(_E148_70);
}

//----- (006FFB20) --------------------------------------------------------  // acclient.c:787724
int _E150_27()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_28, "Render.DisplayAdapter");
  return atexit(_E151_68);
}

//----- (006FFB40) --------------------------------------------------------  // acclient.c:787731
int _E153_25()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_28, "Render.MaxHardwareClass");
  return atexit(_E154_69);
}

//----- (006FFB60) --------------------------------------------------------  // acclient.c:787738
int _E156_27()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_28, "Render.AutomaticDegrades");
  return atexit(_E157_65);
}

//----- (006FFB80) --------------------------------------------------------  // acclient.c:787745
int _E159_25()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_28, "Render.GraphicsPerformance");
  return atexit(_E160_68);
}

//----- (006FFBA0) --------------------------------------------------------  // acclient.c:787752
int _E162_27()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_28, "Render.DegradeDistance");
  return atexit(_E163_61);
}

//----- (006FFBC0) --------------------------------------------------------  // acclient.c:787759
int _E165_23()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_28, "Render.MultiPassAlpha");
  return atexit(_E166_63);
}

//----- (006FFBE0) --------------------------------------------------------  // acclient.c:787766
int _E168_24()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_28, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_844F7C, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_844F80, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_844F84, "Anisotropic");
  return atexit(_E169_62);
}

//----- (006FFC30) --------------------------------------------------------  // acclient.c:787776
int _E171_23()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_28, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_844F8C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_844F90, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_844F94, "High");
  PStringBase<char>::PStringBase<char>(&stru_844F98, "VeryHigh");
  return atexit(_E172_60);
}

//----- (006FFC90) --------------------------------------------------------  // acclient.c:787787
int _E174_24()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_28, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_844FA0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_844FA4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_844FA8, "High");
  PStringBase<char>::PStringBase<char>(&stru_844FAC, "VeryHigh");
  return atexit(_E175_57);
}

//----- (006FFCF0) --------------------------------------------------------  // acclient.c:787798
int _E177_22()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_28, "Low");
  PStringBase<char>::PStringBase<char>(&stru_844FB4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_844FB8, "High");
  return atexit(_E178_57);
}

//----- (006FFD30) --------------------------------------------------------  // acclient.c:787807
int _E180_22()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_28, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_844FC0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_844FC4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_844FC8, "High");
  PStringBase<char>::PStringBase<char>(&stru_844FCC, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_844FD0, "Extreme");
  return atexit(_E181_57);
}

//----- (006FFDA0) --------------------------------------------------------  // acclient.c:787819
int _E183_21()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_28, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_844FD8, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_844FDC, "Wide");
  return atexit(_E184_54);
}

//----- (006FFDE0) --------------------------------------------------------  // acclient.c:787828
int _E186_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_52, "None");
  return atexit(_E187_53);
}

//----- (006FFE00) --------------------------------------------------------  // acclient.c:787835
int _E189_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_52, "Speed");
  return atexit(_E190_54);
}

//----- (006FFE20) --------------------------------------------------------  // acclient.c:787842
int _E192_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_52, "Noise");
  return atexit(_E193_45);
}

//----- (006FFE40) --------------------------------------------------------  // acclient.c:787849
int _E195_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_52, "Sine");
  return atexit(_E196_52);
}

//----- (006FFE60) --------------------------------------------------------  // acclient.c:787856
int _E198_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_52, "Square");
  return atexit(_E199_44);
}

//----- (006FFE80) --------------------------------------------------------  // acclient.c:787863
int _E201_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_52, "Bounce");
  return atexit(_E202_45);
}

//----- (006FFEA0) --------------------------------------------------------  // acclient.c:787870
int _E204_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_52, "Perlin");
  return atexit(_E205_41);
}

//----- (006FFEC0) --------------------------------------------------------  // acclient.c:787877
int _E207_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_52, "Fractal");
  return atexit(_E208_45);
}

//----- (006FFEE0) --------------------------------------------------------  // acclient.c:787884
int _E210_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_52, "FrameLoop");
  return atexit(_E211_41);
}

//----- (006FFF00) --------------------------------------------------------  // acclient.c:787891
int sub_6FFF00()
{
  return atexit(nullsub_1172);
}

//----- (00769C40) --------------------------------------------------------  // acclient.c:896747
void __cdecl _E181_57()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_28;
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

//----- (00769C80) --------------------------------------------------------  // acclient.c:896772
void __cdecl _E184_54()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_52;
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

//----- (00769CC0) --------------------------------------------------------  // acclient.c:896797
void __cdecl _E187_53()
{
  char *v0; // esi@1

  v0 = &waveform_None_52.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_52.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769CF0) --------------------------------------------------------  // acclient.c:896810
void __cdecl _E190_54()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_52.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_52.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769D20) --------------------------------------------------------  // acclient.c:896823
void __cdecl _E193_45()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_52.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_52.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769D50) --------------------------------------------------------  // acclient.c:896836
void __cdecl _E196_52()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_52.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_52.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769D80) --------------------------------------------------------  // acclient.c:896849
void __cdecl _E199_44()
{
  char *v0; // esi@1

  v0 = &waveform_Square_52.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_52.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769DB0) --------------------------------------------------------  // acclient.c:896862
void __cdecl _E202_45()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_52.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_52.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769DE0) --------------------------------------------------------  // acclient.c:896875
void __cdecl _E205_41()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_52.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_52.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769E10) --------------------------------------------------------  // acclient.c:896888
void __cdecl _E208_45()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_52.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_52.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769E40) --------------------------------------------------------  // acclient.c:896901
void __cdecl _E211_41()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_52.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_52.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769E70) --------------------------------------------------------  // acclient.c:896914
void __cdecl sub_769E70()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769EA0) --------------------------------------------------------  // acclient.c:896927
void __cdecl sub_769EA0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769ED0) --------------------------------------------------------  // acclient.c:896940
void __cdecl sub_769ED0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769F00) --------------------------------------------------------  // acclient.c:896953
void __cdecl sub_769F00()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769F30) --------------------------------------------------------  // acclient.c:896966
void __cdecl _E133_94()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769F60) --------------------------------------------------------  // acclient.c:896979
void __cdecl _E136_77()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769F90) --------------------------------------------------------  // acclient.c:896992
void __cdecl _E139_77()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769FC0) --------------------------------------------------------  // acclient.c:897005
void __cdecl _E142_72()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769FF0) --------------------------------------------------------  // acclient.c:897018
void __cdecl _E145_74()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A020) --------------------------------------------------------  // acclient.c:897031
void __cdecl _E148_70()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A050) --------------------------------------------------------  // acclient.c:897044
void __cdecl _E151_68()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A080) --------------------------------------------------------  // acclient.c:897057
void __cdecl _E154_69()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A0B0) --------------------------------------------------------  // acclient.c:897070
void __cdecl _E157_65()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A0E0) --------------------------------------------------------  // acclient.c:897083
void __cdecl _E160_68()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A110) --------------------------------------------------------  // acclient.c:897096
void __cdecl _E163_61()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A140) --------------------------------------------------------  // acclient.c:897109
void __cdecl _E166_63()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A170) --------------------------------------------------------  // acclient.c:897122
void __cdecl _E169_62()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_28;
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

//----- (0076A1B0) --------------------------------------------------------  // acclient.c:897147
void __cdecl _E172_60()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_28;
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

//----- (0076A1F0) --------------------------------------------------------  // acclient.c:897172
void __cdecl _E175_57()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_28;
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

//----- (0076A230) --------------------------------------------------------  // acclient.c:897197
void __cdecl _E178_57()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_28;
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

