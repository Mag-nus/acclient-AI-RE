/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CCellStruct
   Object     : PORTAL\ccell\CCellStruct.obj
   Functions  : 24
   Addresses  : 00533870 - 006FF7B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00533870) --------------------------------------------------------  // acclient.c:355442
void __thiscall CCellStruct::CCellStruct(CCellStruct *this)
{
  CCellStruct *v1; // esi@1

  v1 = this;
  this->cellstruct_id = 0;
  CVertexArray::CVertexArray(&this->vertex_array);
  v1->num_portals = 0;
  v1->portals = 0;
  v1->num_surface_strips = 0;
  v1->surface_strips = 0;
  v1->num_polygons = 0;
  v1->polygons = 0;
  v1->drawing_bsp = 0;
  v1->num_physics_polygons = 0;
  v1->physics_polygons = 0;
  v1->physics_bsp = 0;
  v1->cell_bsp = 0;
}

//----- (005338B0) --------------------------------------------------------  // acclient.c:355463
CPolygon *__thiscall CCellStruct::get_portal(CCellStruct *this, unsigned __int16 poly_id)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  CPolygon **v4; // esi@2
  CPolygon **v5; // ecx@2
  CPolygon *result; // eax@5

  v2 = this->num_portals;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->portals;
    v5 = this->portals;
    while ( (*v5)->poly_id != poly_id )
    {
      ++v3;
      ++v5;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
    result = v4[v3];
  }
  else
  {
LABEL_5:
    result = 0;
  }
  return result;
}

//----- (005338F0) --------------------------------------------------------  // acclient.c:355495
int __thiscall CCellStruct::point_in_cell(CCellStruct *this, AC1Legacy::Vector3 *origin)
{
  return BSPTREE::point_inside_cell_bsp(this->cell_bsp, origin);
}

//----- (00533900) --------------------------------------------------------  // acclient.c:355501
signed int __thiscall CCellStruct::sphere_intersects_cell(CCellStruct *this, CSphere *sphere)
{
  return BSPTREE::sphere_intersects_cell_bsp(this->cell_bsp, sphere);
}

//----- (00533910) --------------------------------------------------------  // acclient.c:355507
int __thiscall CCellStruct::box_intersects_cell(CCellStruct *this, BBox *box)
{
  return BSPTREE::box_intersects_cell_bsp(this->cell_bsp, box);
}

//----- (00533920) --------------------------------------------------------  // acclient.c:355513
int __thiscall CCellStruct::pack_size(CCellStruct *this)
{
  CCellStruct *v1; // esi@1
  int v2; // ebp@1
  int v3; // edi@1
  unsigned int i; // ebx@1
  int v5; // edi@3
  int v6; // ebx@4
  int v7; // edi@6
  unsigned int v8; // ebx@6
  int v9; // ebp@7
  int v10; // edi@9
  int result; // eax@12
  void *dummy; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  dummy = 0;
  v3 = CVertexArray::pack_size(&this->vertex_array) + 16;
  for ( i = 0; i < v1->num_polygons; ++v2 )
  {
    v3 += CPolygon::Pack(&v1->polygons[v2], &dummy, 0);
    ++i;
  }
  v5 = v3 + 2 * v1->num_portals;
  if ( v5 & 3 )
    v6 = 4 - (v5 & 3);
  else
    v6 = 0;
  BSPNODE::pack_tree_type = 2;
  v7 = v6 + BSPTREE::Pack(v1->cell_bsp, &dummy, 0) + v5;
  v8 = 0;
  if ( v1->num_physics_polygons )
  {
    v9 = 0;
    do
    {
      v7 += CPolygon::Pack(&v1->physics_polygons[v9], &dummy, 0);
      ++v8;
      ++v9;
    }
    while ( v8 < v1->num_physics_polygons );
  }
  BSPNODE::pack_tree_type = 1;
  v10 = v7 + BSPTREE::Pack(v1->physics_bsp, &dummy, 0) + 4;
  if ( v1->drawing_bsp )
  {
    BSPNODE::pack_tree_type = 0;
    v10 += BSPTREE::Pack(v1->drawing_bsp, &dummy, 0);
  }
  if ( v10 & 3 )
    result = v10 + 4 - (v10 & 3);
  else
    result = v10;
  return result;
}
// 84537C: using guessed type enum BSPTreeType BSPNODE::pack_tree_type;

//----- (00533A20) --------------------------------------------------------  // acclient.c:355572
int __thiscall CCellStruct::Pack(CCellStruct *this, void **addr, unsigned int size)
{
  CCellStruct *v3; // edi@1
  int result; // eax@1
  unsigned int v5; // ebx@1
  char *v6; // edx@2
  char *v7; // ecx@2
  char *v8; // eax@2
  unsigned int v9; // ebp@2
  unsigned int v10; // eax@5
  int v11; // ecx@7
  int v12; // eax@8
  unsigned int v13; // ebp@10
  int v14; // ecx@16
  int v15; // eax@17
  unsigned int retval; // [sp+0h] [bp-4h]@1
  unsigned int sizea; // [sp+Ch] [bp+8h]@3
  unsigned int sizeb; // [sp+Ch] [bp+8h]@11

  v3 = this;
  result = CCellStruct::pack_size(this);
  v5 = size;
  retval = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->cellstruct_id;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->num_polygons;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->num_physics_polygons;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = v3->num_portals;
    *addr = (char *)*addr + 4;
    CVertexArray::Pack(&v3->vertex_array, addr, size);
    v9 = 0;
    if ( v3->num_polygons )
    {
      sizea = 0;
      do
      {
        CPolygon::Pack(&v3->polygons[sizea], addr, v5);
        ++v9;
        ++sizea;
      }
      while ( v9 < v3->num_polygons );
    }
    v10 = 0;
    if ( v3->num_portals )
    {
      do
      {
        *(_WORD *)*addr = v3->portals[v10]->poly_id;
        *addr = (char *)*addr + 2;
        ++v10;
      }
      while ( v10 < v3->num_portals );
    }
    v11 = (signed int)*addr % 4;
    if ( v11 )
    {
      v12 = 4 - v11;
      if ( 4 != v11 )
      {
        do
        {
          *(_BYTE *)*addr = 0;
          --v12;
          *addr = (char *)*addr + 1;
        }
        while ( v12 );
      }
    }
    BSPNODE::pack_tree_type = 2;
    BSPTREE::Pack(v3->cell_bsp, addr, v5);
    v13 = 0;
    if ( v3->num_physics_polygons )
    {
      sizeb = 0;
      do
      {
        CPolygon::Pack(&v3->physics_polygons[sizeb], addr, v5);
        ++v13;
        ++sizeb;
      }
      while ( v13 < v3->num_physics_polygons );
    }
    BSPNODE::pack_tree_type = 1;
    BSPTREE::Pack(v3->physics_bsp, addr, v5);
    if ( v3->drawing_bsp )
    {
      BSPNODE::pack_tree_type = 0;
      *(_DWORD *)*addr = 1;
      *addr = (char *)*addr + 4;
      BSPTREE::Pack(v3->drawing_bsp, addr, v5);
    }
    else
    {
      *(_DWORD *)*addr = 0;
      *addr = (char *)*addr + 4;
    }
    v14 = (signed int)*addr % 4;
    if ( v14 )
    {
      v15 = 4 - v14;
      if ( 4 != v14 )
      {
        do
        {
          *(_BYTE *)*addr = 0;
          --v15;
          *addr = (char *)*addr + 1;
        }
        while ( v15 );
      }
    }
    result = retval;
  }
  return result;
}
// 84537C: using guessed type enum BSPTreeType BSPNODE::pack_tree_type;

//----- (00533BD0) --------------------------------------------------------  // acclient.c:355697
void __thiscall CCellStruct::Destroy(CCellStruct *this)
{
  CCellStruct *v1; // esi@1
  BSPTREE *v2; // edi@1
  BSPTREE *v3; // edi@5
  CPolygon *v4; // ecx@7
  float v5; // eax@8
  void *v6; // ebp@8
  CPolygon *v7; // edi@8
  int v8; // eax@8
  int v9; // ebx@9
  BSPTREE *v10; // edi@12
  CPolygon *v11; // ecx@14
  float v12; // eax@15
  void *v13; // ebp@15
  CPolygon *v14; // edi@15
  int v15; // eax@15
  int v16; // ebx@16
  CSurfaceTriStrips *v17; // ecx@19
  CTriangleStrip *v18; // eax@20
  void *v19; // ebp@20
  int v20; // edx@20
  int v21; // eax@20
  CSurfaceTriStrips *v22; // edi@20
  int v23; // ebx@21

  v1 = this;
  v2 = this->cell_bsp;
  if ( v2 )
  {
    BSPTREE::~BSPTREE(this->cell_bsp);
    operator delete(v2);
    v1->cell_bsp = 0;
  }
  if ( v1->portals )
  {
    operator delete[](v1->portals);
    v1->portals = 0;
  }
  v3 = v1->physics_bsp;
  v1->num_portals = 0;
  if ( v3 )
  {
    BSPTREE::~BSPTREE(v3);
    operator delete(v3);
    v1->physics_bsp = 0;
  }
  v4 = v1->physics_polygons;
  if ( v4 )
  {
    v5 = v4[-1].plane.d;
    v6 = &v4[-1].plane.d;
    v7 = &v4[LODWORD(v5)];
    v8 = LODWORD(v5) - 1;
    if ( v8 >= 0 )
    {
      v9 = v8 + 1;
      do
      {
        --v7;
        CPolygon::Destroy(v7);
        --v9;
      }
      while ( v9 );
    }
    operator delete[](v6);
    v1->physics_polygons = 0;
  }
  v10 = v1->drawing_bsp;
  v1->num_physics_polygons = 0;
  if ( v10 )
  {
    BSPTREE::~BSPTREE(v10);
    operator delete(v10);
    v1->drawing_bsp = 0;
  }
  v11 = v1->polygons;
  if ( v11 )
  {
    v12 = v11[-1].plane.d;
    v13 = &v11[-1].plane.d;
    v14 = &v11[LODWORD(v12)];
    v15 = LODWORD(v12) - 1;
    if ( v15 >= 0 )
    {
      v16 = v15 + 1;
      do
      {
        --v14;
        CPolygon::Destroy(v14);
        --v16;
      }
      while ( v16 );
    }
    operator delete[](v13);
    v1->polygons = 0;
  }
  v17 = v1->surface_strips;
  v1->num_polygons = 0;
  if ( v17 )
  {
    v18 = v17[-1].strips;
    v19 = &v17[-1].strips;
    v20 = 3 * (_DWORD)v18;
    v21 = (int)((char *)&v18[-1].indices + 3);
    v22 = &v17[4 * v20 / 0xCu];
    if ( v21 >= 0 )
    {
      v23 = v21 + 1;
      do
      {
        --v22;
        CSurfaceTriStrips::~CSurfaceTriStrips(v22);
        --v23;
      }
      while ( v23 );
    }
    operator delete[](v19);
    v1->surface_strips = 0;
  }
  v1->num_surface_strips = 0;
  CVertexArray::DestroyVertex(&v1->vertex_array);
}

//----- (00533D00) --------------------------------------------------------  // acclient.c:355822
int __thiscall CCellStruct::UnPack(CCellStruct *this, void **addr, unsigned int size)
{
  CCellStruct *v3; // esi@1
  void **v4; // edi@1
  char *v5; // ebx@1
  char *v6; // edx@1
  char *v7; // ecx@1
  int result; // eax@1
  int v9; // ebx@2
  void *v10; // eax@2
  int v11; // ebp@3
  unsigned int v12; // eax@5
  unsigned int v13; // ebx@5
  int v14; // ebp@6
  void *v15; // eax@8
  unsigned int v16; // ecx@8
  unsigned int v17; // eax@8
  unsigned __int16 v18; // dx@9
  int v19; // ecx@10
  int v20; // eax@11
  ClipPlane *v21; // eax@13
  BSPTREE *v22; // eax@14
  unsigned int v23; // ebx@16
  void *v24; // eax@16
  int v25; // eax@17
  int v26; // ebx@17
  CPolygon *v27; // ebp@17
  int v28; // ebx@18
  unsigned int v29; // ebx@22
  int v30; // ebp@23
  ClipPlane *v31; // eax@25
  BSPTREE *v32; // eax@26
  int v33; // ecx@28
  ClipPlane *v34; // eax@29
  BSPTREE *v35; // eax@30
  int v36; // ecx@33
  int v37; // eax@34
  void **addra; // [sp+10h] [bp+4h]@17

  v3 = this;
  CCellStruct::Destroy(this);
  v4 = addr;
  v3->cellstruct_id = *(_DWORD *)*addr;
  v5 = (char *)*addr + 4;
  *addr = v5;
  v3->num_polygons = *(_DWORD *)v5;
  v6 = (char *)*addr + 4;
  *addr = v6;
  v3->num_physics_polygons = *(_DWORD *)v6;
  v7 = (char *)*addr + 4;
  *addr = v7;
  v3->num_portals = *(_DWORD *)v7;
  *addr = (char *)*addr + 4;
  result = CVertexArray::UnPack(&v3->vertex_array, addr, size);
  if ( result )
  {
    CPolygon::pack_verts = &v3->vertex_array;
    v9 = v3->num_polygons;
    v10 = operator new[](48 * v9 + 4);
    if ( v10 )
    {
      v11 = (int)((char *)v10 + 4);
      *(_DWORD *)v10 = v9;
      vector_constructor_iterator((char *)v10 + 4, 0x30u, v9, (void *(__thiscall *)(void *))CPolygon::CPolygon);
    }
    else
    {
      v11 = 0;
    }
    v12 = v3->num_polygons;
    v13 = 0;
    v3->polygons = (CPolygon *)v11;
    if ( v12 )
    {
      v14 = 0;
      do
      {
        CPolygon::UnPack(&v3->polygons[v14], addr, size);
        ++v13;
        ++v14;
      }
      while ( v13 < v3->num_polygons );
    }
    v15 = operator new[](4 * v3->num_portals);
    v16 = v3->num_portals;
    v3->portals = (CPolygon **)v15;
    v17 = 0;
    if ( v16 )
    {
      do
      {
        v18 = *(_WORD *)*addr;
        *addr = (char *)*addr + 2;
        v3->portals[v17++] = &v3->polygons[v18];
      }
      while ( v17 < v3->num_portals );
    }
    v19 = (signed int)*addr % 4;
    if ( v19 )
    {
      v20 = 4 - v19;
      if ( 4 != v19 )
      {
        do
        {
          *(_BYTE *)*addr = 0;
          --v20;
          *addr = (char *)*addr + 1;
        }
        while ( v20 );
      }
    }
    BSPNODE::pack_poly = v3->polygons;
    BSPNODE::pack_tree_type = 2;
    v21 = (ClipPlane *)operator new(4u);
    if ( v21 )
      ClipPlane::ClipPlane(v21);
    else
      v22 = 0;
    v3->cell_bsp = v22;
    BSPTREE::UnPack(v22, addr, size);
    v23 = v3->num_physics_polygons;
    v24 = operator new[](48 * v23 + 4);
    if ( v24 )
    {
      v25 = (int)((char *)v24 + 4);
      *(_DWORD *)(v25 - 4) = v23;
      v26 = v23 - 1;
      addra = (void **)v25;
      v27 = (CPolygon *)v25;
      if ( v26 >= 0 )
      {
        v28 = v26 + 1;
        do
        {
          CPolygon::CPolygon(v27);
          ++v27;
          --v28;
        }
        while ( v28 );
        v25 = (int)addra;
      }
    }
    else
    {
      v25 = 0;
    }
    v3->physics_polygons = (CPolygon *)v25;
    v29 = 0;
    if ( v3->num_physics_polygons )
    {
      v30 = 0;
      do
      {
        CPolygon::UnPack(&v3->physics_polygons[v30], v4, size);
        ++v29;
        ++v30;
      }
      while ( v29 < v3->num_physics_polygons );
    }
    BSPNODE::pack_poly = v3->physics_polygons;
    BSPNODE::pack_tree_type = 1;
    v31 = (ClipPlane *)operator new(4u);
    if ( v31 )
      ClipPlane::ClipPlane(v31);
    else
      v32 = 0;
    v3->physics_bsp = v32;
    BSPTREE::UnPack(v32, v4, size);
    BSPNODE::pack_poly = v3->polygons;
    v33 = *(_DWORD *)*v4;
    *v4 = (char *)*v4 + 4;
    if ( v33 )
    {
      BSPNODE::pack_tree_type = 0;
      v34 = (ClipPlane *)operator new(4u);
      if ( v34 )
        ClipPlane::ClipPlane(v34);
      else
        v35 = 0;
      v3->drawing_bsp = v35;
      BSPTREE::UnPack(v35, v4, size);
    }
    v36 = (signed int)*v4 % 4;
    if ( v36 )
    {
      v37 = 4 - v36;
      if ( 4 != v36 )
      {
        do
        {
          *(_BYTE *)*v4 = 0;
          --v37;
          *v4 = (char *)*v4 + 1;
        }
        while ( v37 );
      }
    }
    result = 1;
  }
  return result;
}
// 8450FC: using guessed type struct CVertexArray *CPolygon::pack_verts;
// 845378: using guessed type struct CPolygon *BSPNODE::pack_poly;
// 84537C: using guessed type enum BSPTreeType BSPNODE::pack_tree_type;

//----- (00533F90) --------------------------------------------------------  // acclient.c:356029
void __thiscall CCellStruct::~CCellStruct(CCellStruct *this)
{
  CCellStruct *v1; // esi@1

  v1 = this;
  CCellStruct::Destroy(this);
  gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&v1->vertex_array);
}

//----- (006FF680) --------------------------------------------------------  // acclient.c:787426
int _E73_93()
{
  return atexit(_E74_69);
}

//----- (006FF690) --------------------------------------------------------  // acclient.c:787432
int _E76_55()
{
  return atexit(_E77_83);
}

//----- (006FF6A0) --------------------------------------------------------  // acclient.c:787438
int _E79_48()
{
  return atexit(_E80_47);
}

//----- (006FF6B0) --------------------------------------------------------  // acclient.c:787444
void _E98_7()
{
  dword_844E38 = 1024;
}

//----- (006FF6C0) --------------------------------------------------------  // acclient.c:787450
void sub_6FF6C0()
{
  dword_844E3C = 0x7FFF;
}

//----- (006FF6D0) --------------------------------------------------------  // acclient.c:787456
int _E102_19()
{
  const int result; // eax@1

  result = dword_844E38;
  INITIAL_MAX_DATA_RATE_90 = dword_844E38;
  return result;
}

//----- (006FF6E0) --------------------------------------------------------  // acclient.c:787466
void _E104_9()
{
  LODWORD(dword_844E44) = 1053364187;
}

//----- (006FF6F0) --------------------------------------------------------  // acclient.c:787472
void _E106_96()
{
  flt_844E48 = 1000.0 + 1.0;
}

//----- (006FF710) --------------------------------------------------------  // acclient.c:787478
void _E108_74()
{
  flt_844E4C = 24.0 * 8.0;
}

//----- (006FF730) --------------------------------------------------------  // acclient.c:787484
void _E110_60()
{
  flt_844E50 = 24.0 * 0.5;
}

//----- (006FF750) --------------------------------------------------------  // acclient.c:787490
void _E112_90()
{
  flt_844E54 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FF770) --------------------------------------------------------  // acclient.c:787496
void _E114_48()
{
  dbl_844E58 = 1.0 / 30.0;
}

//----- (006FF790) --------------------------------------------------------  // acclient.c:787502
void _E116_19()
{
  dbl_844E60 = 1.0 / 5.0;
}

//----- (006FF7B0) --------------------------------------------------------  // acclient.c:787508
int sub_6FF7B0()
{
  return atexit(nullsub_1164);
}

