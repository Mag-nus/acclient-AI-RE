/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CLandBlockStruct
   Object     : PORTAL\ccell\CLandBlockStruct.obj
   Functions  : 29
   Addresses  : 00530E30 - 006FF040 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00530E30) --------------------------------------------------------  // acclient.c:353108
void __thiscall CLandBlockStruct::CLandBlockStruct(CLandBlockStruct *this)
{
  CLandBlockStruct *v1; // esi@1

  v1 = this;
  this->vertex_lighting = 0;
  this->trans_dir = 9;
  this->side_vertex_count = 0;
  this->side_polygon_count = 0;
  this->side_cell_count = 0;
  this->water_type = 0;
  CVertexArray::CVertexArray(&this->vertex_array);
  v1->polygons = 0;
  v1->num_surface_strips = 0;
  v1->surface_strips = 0;
  v1->lcell = 0;
  v1->SWtoNEcut = 0;
  v1->height = (char *)operator new[](0x51u);
  v1->terrain = (unsigned __int16 *)operator new[](0xA2u);
  v1->block_surface_index = -1;
}

//----- (00530E90) --------------------------------------------------------  // acclient.c:353131
void __thiscall CLandBlockStruct::InitPVArrays(CLandBlockStruct *this)
{
  CLandBlockStruct *v1; // esi@1
  int v2; // ebx@1
  int v3; // edi@1
  int i; // edx@2
  int v5; // ecx@3
  unsigned __int32 v6; // eax@3
  int v7; // ebx@6
  void *v8; // eax@6
  int v9; // ebp@7
  CPolygon *v10; // edi@7
  int v11; // ebp@11
  int v12; // edi@12
  int v13; // ebx@16
  void *v14; // eax@16
  int v15; // ebp@17
  CLandCell *v16; // edi@17
  int v17; // [sp+10h] [bp-Ch]@1
  int num_lcell; // [sp+14h] [bp-8h]@1
  int num_vert; // [sp+18h] [bp-4h]@1

  v1 = this;
  v2 = this->side_polygon_count * this->side_polygon_count;
  num_vert = this->side_vertex_count * this->side_vertex_count;
  v17 = this->side_polygon_count * this->side_polygon_count;
  num_lcell = this->side_cell_count * this->side_cell_count;
  CVertexArray::AllocateVertex(&this->vertex_array, num_vert, CSWVertexType);
  v3 = 0;
  if ( v1->side_vertex_count > 0 )
  {
    do
    {
      for ( i = 0; i < v1->side_vertex_count; ++i )
      {
        v5 = i + v3 * v1->side_vertex_count;
        v6 = (unsigned __int32)((char *)v1->vertex_array.vertices + v5 * CVertexArray::vertex_size);
        *(_WORD *)(v6 + 12) = v5;
        *(_WORD *)(v6 + 14) = 4;
        *(_DWORD *)(v6 + 16) = &CLandBlockStruct::land_uvs;
      }
      ++v3;
    }
    while ( v3 < v1->side_vertex_count );
    v2 = v17;
  }
  v7 = 2 * v2;
  v8 = operator new[](48 * v7 + 4);
  if ( v8 )
  {
    *(_DWORD *)v8 = v7;
    v9 = (int)((char *)v8 + 4);
    v10 = (CPolygon *)((char *)v8 + 4);
    if ( v7 - 1 >= 0 )
    {
      do
      {
        CPolygon::CPolygon(v10);
        ++v10;
        --v7;
      }
      while ( v7 );
    }
  }
  else
  {
    v9 = 0;
  }
  v1->polygons = (CPolygon *)v9;
  v11 = 0;
  if ( 2 * v17 > 0 )
  {
    v12 = 0;
    do
    {
      v1->polygons[v12].num_pts = 3;
      v1->polygons[v12].poly_id = v11;
      v1->polygons[v12].vertices = (CVertex **)operator new[](0xCu);
      v1->polygons[v12].vertex_ids = (unsigned __int16 *)operator new[](6u);
      v1->polygons[v12].sides_type = 0;
      if ( v1->vertex_array.vertex_type == 1 )
      {
        v1->polygons[v12].pos_uv_indices = (char *)operator new[](3u);
        v1->polygons[v12].neg_uv_indices = 0;
        v1->polygons[v12].screen = (Vec2Dscreen **)operator new[](0xCu);
      }
      ++v11;
      ++v12;
    }
    while ( v11 < 2 * v17 );
  }
  v13 = num_lcell;
  v1->SWtoNEcut = (int *)operator new[](4 * v17);
  v14 = operator new[](264 * num_lcell + 4);
  if ( v14 )
  {
    v15 = (int)((char *)v14 + 4);
    *(_DWORD *)v14 = num_lcell;
    v16 = (CLandCell *)((char *)v14 + 4);
    if ( num_lcell - 1 >= 0 )
    {
      do
      {
        CLandCell::CLandCell(v16);
        ++v16;
        --v13;
      }
      while ( v13 );
    }
  }
  else
  {
    v15 = 0;
  }
  v1->lcell = (CLandCell *)v15;
  v1->vertex_lighting = (RGBColor *)operator new[](12 * num_vert);
}
// 81E700: using guessed type unsigned __int32 CVertexArray::vertex_size;
// 844CA8: using guessed type struct CVec2Duv *CLandBlockStruct::land_uvs;

//----- (00531050) --------------------------------------------------------  // acclient.c:353252
void *__thiscall CLandCell::vector_deleting_destructor(CLandCell *this, unsigned int a2)
{
  CLandCell *v2; // edi@1
  BoundingType v3; // eax@2
  char *v4; // ebp@2
  CLandCell *v5; // esi@2
  int v6; // eax@2
  int v7; // edi@3
  void *result; // eax@7

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].in_view;
    v4 = (char *)&this[-1].in_view;
    v5 = &this[v3];
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        --v5;
        CLandCell::~CLandCell(v5);
        --v7;
      }
      while ( v7 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    CLandCell::~CLandCell(this);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (005310D0) --------------------------------------------------------  // acclient.c:353295
int __thiscall CLandBlockStruct::AddPolygon(CLandBlockStruct *this, unsigned int pindex, unsigned int vindex0, unsigned int vindex1, unsigned int vindex2)
{
  CLandBlockStruct *v5; // esi@1
  unsigned int v6; // edi@1
  CPolygon *v7; // ecx@1
  CVertex **v8; // edx@1
  unsigned int v9; // ecx@1
  int result; // eax@4

  v5 = this;
  v6 = pindex;
  *this->polygons[pindex].vertices = (CVertex *)((char *)this->vertex_array.vertices
                                               + vindex0 * CVertexArray::vertex_size);
  *this->polygons[v6].vertex_ids = vindex0;
  *((_DWORD *)this->polygons[v6].vertices + 1) = (char *)this->vertex_array.vertices
                                               + vindex1 * CVertexArray::vertex_size;
  this->polygons[v6].vertex_ids[1] = vindex1;
  *((_DWORD *)this->polygons[v6].vertices + 2) = (char *)this->vertex_array.vertices
                                               + vindex2 * CVertexArray::vertex_size;
  this->polygons[pindex].vertex_ids[2] = vindex2;
  CPolygon::make_plane(&this->polygons[pindex]);
  v5->polygons[v6].pos_surface = 0;
  v7 = v5->polygons;
  v8 = v7[pindex].vertices;
  v9 = (unsigned int)&v7[pindex];
  if ( (*v8)->z != 0.0 || v8[1]->z != 0.0 || v8[2]->z != 0.0 )
  {
    *(_WORD *)(v9 + 28) = 1;
    result = (int)&v5->polygons[v6];
  }
  else
  {
    *(_WORD *)(v9 + 28) = 0;
    result = (int)&v5->polygons[v6];
  }
  return result;
}
// 81E700: using guessed type unsigned __int32 CVertexArray::vertex_size;

//----- (005311D0) --------------------------------------------------------  // acclient.c:353335
signed int CLandBlockStruct::pack_size()
{
  return 244;
}

//----- (005311E0) --------------------------------------------------------  // acclient.c:353341
unsigned int __thiscall CLandBlockStruct::Pack(CLandBlockStruct *this, void **addr, unsigned int size)
{
  signed int v3; // edx@1
  char *v4; // esi@2
  char *v5; // edi@2
  char *v6; // esi@2
  char *v7; // edi@2
  char *v8; // esi@2
  char *v9; // edi@2
  char *v10; // esi@2
  char *v11; // edi@2
  signed int v12; // esi@3
  char *v13; // edx@4
  char *v14; // edi@4
  char *v15; // edx@4
  char *v16; // edi@4
  char *v17; // edx@4
  char *v18; // edi@4
  char *v19; // edx@4
  char *v20; // edi@4
  char *v21; // edx@4
  int v22; // esi@5
  int v23; // ecx@6
  char *v24; // edi@7

  v3 = 3;
  do
  {
    *(_WORD *)*addr = this->terrain[v3 - 3];
    v4 = (char *)*addr + 2;
    *addr = v4;
    *(_WORD *)v4 = this->terrain[v3 - 2];
    v5 = (char *)*addr + 2;
    *addr = v5;
    *(_WORD *)v5 = this->terrain[v3 - 1];
    v6 = (char *)*addr + 2;
    *addr = v6;
    *(_WORD *)v6 = this->terrain[v3];
    v7 = (char *)*addr + 2;
    *addr = v7;
    *(_WORD *)v7 = this->terrain[v3 + 1];
    v8 = (char *)*addr + 2;
    *addr = v8;
    *(_WORD *)v8 = this->terrain[v3 + 2];
    v9 = (char *)*addr + 2;
    *addr = v9;
    *(_WORD *)v9 = this->terrain[v3 + 3];
    v10 = (char *)*addr + 2;
    *addr = v10;
    *(_WORD *)v10 = this->terrain[v3 + 4];
    v11 = (char *)*addr + 2;
    *addr = v11;
    *(_WORD *)v11 = this->terrain[v3 + 5];
    v3 += 9;
    *addr = (char *)*addr + 2;
  }
  while ( v3 < 84 );
  v12 = 0;
  do
  {
    *(_BYTE *)*addr = this->height[v12];
    v13 = (char *)*addr + 1;
    *addr = v13;
    *v13 = this->height[v12 + 1];
    v14 = (char *)*addr + 1;
    *addr = v14;
    *v14 = this->height[v12 + 2];
    v15 = (char *)*addr + 1;
    *addr = v15;
    *v15 = this->height[v12 + 3];
    v16 = (char *)*addr + 1;
    *addr = v16;
    *v16 = this->height[v12 + 4];
    v17 = (char *)*addr + 1;
    *addr = v17;
    *v17 = this->height[v12 + 5];
    v18 = (char *)*addr + 1;
    *addr = v18;
    *v18 = this->height[v12 + 6];
    v19 = (char *)*addr + 1;
    *addr = v19;
    *v19 = this->height[v12 + 7];
    v20 = (char *)*addr + 1;
    *addr = v20;
    *v20 = this->height[v12 + 8];
    v21 = (char *)*addr + 1;
    v12 += 9;
    *addr = v21;
  }
  while ( v12 < 81 );
  v22 = (signed int)v21 % 4;
  if ( (signed int)v21 % 4 )
  {
    v23 = 4 - v22;
    if ( 4 != v22 )
    {
      do
      {
        *v21 = 0;
        v24 = (char *)*addr + 1;
        --v23;
        *addr = v24;
        v21 = v24;
      }
      while ( v23 );
    }
  }
  return 0;
}

//----- (00531380) --------------------------------------------------------  // acclient.c:353452
void __thiscall CLandBlockStruct::AdjPlanes(CLandBlockStruct *this)
{
  CLandBlockStruct *v1; // edi@1
  int v2; // eax@1
  unsigned int v3; // ebp@1
  unsigned int v4; // ebx@2
  unsigned int v5; // esi@3

  v1 = this;
  v2 = this->side_polygon_count;
  v3 = 0;
  if ( v2 )
  {
    do
    {
      v4 = 0;
      if ( v2 )
      {
        do
        {
          v5 = 0;
          do
            CPolygon::make_plane(&v1->polygons[v5++ + 2 * (v4 + v3 * v1->side_polygon_count)]);
          while ( v5 < 2 );
          ++v4;
        }
        while ( v4 < v1->side_polygon_count );
      }
      v2 = v1->side_polygon_count;
      ++v3;
    }
    while ( v3 < v2 );
  }
}

//----- (005313E0) --------------------------------------------------------  // acclient.c:353488
void __thiscall CLandBlockStruct::RemoveSurfaces(CLandBlockStruct *this)
{
  CLandBlockStruct *v1; // edi@1
  int v2; // eax@2
  unsigned int v3; // ebx@2
  unsigned int v4; // esi@3
  unsigned int v5; // ST00_4@4
  LandSurf *v6; // eax@4

  v1 = this;
  if ( CRegionDesc::current_region )
  {
    v2 = this->side_cell_count;
    v3 = 0;
    if ( v2 )
    {
      do
      {
        v4 = 0;
        if ( v2 )
        {
          do
          {
            v5 = *(_WORD *)(**((_DWORD **)&v1->lcell[v4].polygons + 66 * v3 * v2) + 28);
            v6 = (LandSurf *)CommandList::GetHead((ChatDisplayInfo *)CRegionDesc::current_region->terrain_info);
            LandSurf::RemoveSurface(v6, v5);
            v2 = v1->side_cell_count;
            ++v4;
          }
          while ( v4 < v2 );
        }
        v2 = v1->side_cell_count;
        ++v3;
      }
      while ( v3 < v2 );
    }
  }
}

//----- (00531450) --------------------------------------------------------  // acclient.c:353528
void __thiscall CLandBlockStruct::Destroy(CLandBlockStruct *this)
{
  CLandBlockStruct *v1; // esi@1
  signed int i; // eax@2
  CLandCell *v3; // ecx@5
  CPolygon *v4; // ecx@10
  float v5; // eax@11
  void *v6; // ebp@11
  CPolygon *v7; // edi@11
  int v8; // eax@11
  int v9; // ebx@12
  void *v10; // eax@19
  bool v11; // zf@19

  v1 = this;
  if ( this->vertex_array.vertex_type == 1 )
  {
    for ( i = 0; i < (signed int)this->vertex_array.num_vertices; ++i )
      *(unsigned int *)((char *)&this->vertex_array.vertices->reserve5 + i * CVertexArray::vertex_size) = 0;
  }
  if ( this->lcell )
  {
    CLandBlockStruct::RemoveSurfaces(this);
    v3 = v1->lcell;
    if ( v3 )
    {
      if ( v3[-1].in_view )
        ((void (__stdcall *)(signed int))v3->vfptr[1].IUnknown_QueryInterface)(3);
      else
        operator delete[](&v3[-1].in_view);
    }
    v1->lcell = 0;
  }
  v4 = v1->polygons;
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
    v1->polygons = 0;
  }
  CVertexArray::DestroyVertex(&v1->vertex_array);
  if ( v1->SWtoNEcut )
  {
    operator delete[](v1->SWtoNEcut);
    v1->SWtoNEcut = 0;
  }
  if ( v1->surface_strips )
  {
    CSurfaceTriStrips::Free(v1->surface_strips);
    v1->surface_strips = 0;
  }
  v10 = v1->vertex_lighting;
  v11 = v1->vertex_lighting == 0;
  v1->num_surface_strips = 0;
  v1->side_cell_count = 0;
  v1->trans_dir = 9;
  if ( !v11 )
  {
    operator delete[](v10);
    v1->vertex_lighting = 0;
  }
}
// 81E700: using guessed type unsigned __int32 CVertexArray::vertex_size;

//----- (00531550) --------------------------------------------------------  // acclient.c:353607
void __thiscall CLandBlockStruct::CalcCellWater(CLandBlockStruct *this, int cell_x, int cell_y, int *cell_has_water, int *cell_all_water)
{
  int v5; // edi@2
  int v6; // esi@4
  signed int v7; // edx@4
  int cell_xa; // [sp+8h] [bp+4h]@2

  *cell_has_water = 0;
  *cell_all_water = 1;
  if ( (unsigned __int8)(__OFSUB__(cell_x, cell_x + 1) ^ 1) | (cell_x == cell_x + 1) )
  {
    v5 = 2 * (cell_y + 8 * cell_x + cell_x);
    cell_xa = 2;
    do
    {
      if ( cell_y <= cell_y + 1 )
      {
        v6 = v5;
        v7 = 2;
        do
        {
          if ( TERRAIN_SURF_CHAR[((unsigned int)*((_BYTE *)this->terrain + v6) >> 2) & 0x1F] == 1 )
            *cell_has_water = 1;
          else
            *cell_all_water = 0;
          v6 += 2;
          --v7;
        }
        while ( v7 );
      }
      v5 += 18;
      --cell_xa;
    }
    while ( cell_xa );
  }
}

//----- (005315F0) --------------------------------------------------------  // acclient.c:353645
double __thiscall CLandBlockStruct::calc_water_depth(CLandBlockStruct *this, unsigned int cell_id, AC1Legacy::Vector3 *point)
{
  CLandBlockStruct *v3; // esi@1
  unsigned int v4; // ecx@3
  unsigned int v5; // edx@3
  float v6; // et1@5
  double v8; // st6@5
  unsigned __int8 v9; // c0@5
  unsigned __int8 v10; // c2@5
  bool v11; // pf@5
  unsigned __int8 v13; // c0@5
  unsigned __int8 v14; // c3@5
  SURFCHAR v15; // eax@7
  int v16; // ecx@9
  unsigned __int16 *v17; // eax@9
  unsigned int v18; // ecx@10
  double result; // st7@15
  CLandBlockStruct *v20; // [sp+0h] [bp-4h]@1

  v20 = this;
  v3 = this;
  if ( LandDefs::inbound_valid_cellid(cell_id) && (unsigned __int16)cell_id < 0x100u )
  {
    v4 = ((unsigned int)(unsigned __int16)cell_id - 1) >> 3;
    v5 = ((_BYTE)cell_id - 1) & 7;
  }
  else
  {
    v5 = cell_id;
    v4 = (unsigned int)v20;
  }
  v6 = point->x;
  v8 = point->y;
  v11 = (v9 | v10) == 0;
  if ( v11 )
  {
    v16 = v5 + 8 * v4 + v4;
    v17 = v3->terrain;
    if ( v13 | v14 )
      v18 = LOBYTE(v17[v16]);
    else
      v18 = LOBYTE(v17[v16 + 1]);
    v15 = TERRAIN_SURF_CHAR[(v18 >> 2) & 0x1F];
  }
  else if ( v13 | v14 )
  {
    v15 = TERRAIN_SURF_CHAR[((unsigned int)LOBYTE(v3->terrain[v5 + 8 * (v4 + 1) + v4 + 1]) >> 2) & 0x1F];
  }
  else
  {
    v15 = TERRAIN_SURF_CHAR[((unsigned int)*((_BYTE *)&v3->terrain[8 * v4 + 10] + 2 * v5 + 2 * v4) >> 2) & 0x1F];
  }
  if ( v15 )
  {
    if ( v15 == 1 )
      result = 0.44999999;
    else
      result = 0.0;
  }
  else
  {
    result = 0.1;
  }
  return result;
}

//----- (00531700) --------------------------------------------------------  // acclient.c:353712
void __thiscall CLandBlockStruct::calc_lighting(CLandBlockStruct *this)
{
  CLandBlockStruct *v1; // esi@1
  unsigned int v2; // ebx@1
  void *v3; // esp@1
  int *v4; // eax@2
  int v5; // ebx@4
  unsigned int v6; // edx@5
  int v7; // ecx@6
  float *v8; // eax@6
  CPolygon *v9; // ecx@6
  double v10; // st7@6
  int v11; // eax@6
  int v12; // ecx@6
  float *v13; // eax@6
  CPolygon *v14; // ecx@6
  int v15; // eax@6
  int v16; // ecx@6
  float *v17; // eax@6
  unsigned int v18; // edx@7
  float *v19; // ecx@8
  unsigned int v20; // ebx@8
  long double v21; // st4@9
  double v22; // st7@13
  int v23; // eax@13
  double v24; // st6@14
  int v25; // ebx@14
  double v26; // st5@14
  double v27; // st4@14
  int v28; // edx@14
  char *v29; // ecx@14
  double v30; // st3@16
  double v31; // st3@18
  int v32; // edx@24
  double v33; // st3@24
  double v34; // st3@26
  double v35; // st3@32
  double v36; // st3@34
  double v37; // st3@40
  double v38; // st3@42
  unsigned int v39; // ebx@48
  bool v40; // sf@48
  unsigned __int8 v41; // of@48
  double v42; // st7@51
  int v43; // ecx@51
  double v44; // st6@51
  float *v45; // edi@51
  int v46; // edx@51
  double v47; // st5@51
  double v48; // st4@52
  double v49; // st4@54
  int v50; // [sp+0h] [bp-50h]@2
  int v51; // [sp+8h] [bp-48h]@8
  AC1Legacy::Vector3 sunlight_vec; // [sp+Ch] [bp-44h]@2
  int v53; // [sp+18h] [bp-38h]@14
  int v54; // [sp+1Ch] [bp-34h]@14
  int v55; // [sp+20h] [bp-30h]@14
  RGBAUnion ambient_color; // [sp+24h] [bp-2Ch]@13
  float ag; // [sp+28h] [bp-28h]@13
  RGBAUnion sunlight_color; // [sp+2Ch] [bp-24h]@13
  int iq; // [sp+30h] [bp-20h]@13
  unsigned int num_vertices; // [sp+34h] [bp-1Ch]@1
  float sb; // [sp+38h] [bp-18h]@13
  float sg; // [sp+3Ch] [bp-14h]@13
  float sr; // [sp+40h] [bp-10h]@13
  float ambient_level; // [sp+44h] [bp-Ch]@13
  float g; // [sp+48h] [bp-8h]@18
  float r; // [sp+4Ch] [bp-4h]@18

  v1 = this;
  num_vertices = this->side_vertex_count * this->side_vertex_count;
  v2 = num_vertices;
  v3 = alloca(12 * num_vertices);
  if ( (signed int)num_vertices > 0 )
  {
    LODWORD(sunlight_vec.x) = 0;
    LODWORD(sunlight_vec.y) = 0;
    LODWORD(sunlight_vec.z) = 0;
    v4 = &v50;
    do
    {
      *(AC1Legacy::Vector3 *)v4 = sunlight_vec;
      v4 += 3;
      --v2;
    }
    while ( v2 );
  }
  v5 = 0;
  if ( 2 * this->side_polygon_count * this->side_polygon_count > 0 )
  {
    v6 = 0;
    do
    {
      v7 = (int)&v1->polygons[v6];
      v8 = (float *)(&v50 + 3 * **(_WORD **)(v7 + 4));
      *v8 = *v8 + *(float *)(v7 + 32);
      v8[1] = *(float *)(v7 + 36) + v8[1];
      v8[2] = *(float *)(v7 + 40) + v8[2];
      v9 = v1->polygons;
      v10 = v9[v6].plane.N.x;
      v11 = v9[v6].vertex_ids[1];
      v12 = (int)&v9[v6];
      v13 = (float *)(&v50 + 3 * v11);
      *v13 = v10 + *v13;
      v13[1] = *(float *)(v12 + 36) + v13[1];
      v13[2] = *(float *)(v12 + 40) + v13[2];
      v14 = v1->polygons;
      v15 = v14[v6].vertex_ids[2];
      v16 = (int)&v14[v6];
      v17 = (float *)(&v50 + 3 * v15);
      ++v5;
      ++v6;
      *v17 = *v17 + *(float *)(v16 + 32);
      v17[1] = *(float *)(v16 + 36) + v17[1];
      v17[2] = *(float *)(v16 + 40) + v17[2];
    }
    while ( v5 < 2 * v1->side_polygon_count * v1->side_polygon_count );
  }
  v18 = num_vertices;
  if ( (signed int)num_vertices > 0 )
  {
    v19 = (float *)&v51;
    v20 = num_vertices;
    do
    {
      v21 = sqrt(*(v19 - 2) * *(v19 - 2) + *(v19 - 1) * *(v19 - 1) + *v19 * *v19);
      if ( v21 < 0.00019999999 )
      {
        LODWORD(sunlight_vec.x) = 0;
        *((_DWORD *)v19 - 2) = 0;
        LODWORD(sunlight_vec.y) = 0;
        *((_DWORD *)v19 - 1) = 0;
        LODWORD(sunlight_vec.z) = 1065353216;
        *(_DWORD *)v19 = 1065353216;
      }
      else
      {
        *(v19 - 2) = 1.0 / v21 * *(v19 - 2);
        *(v19 - 1) = 1.0 / v21 * *(v19 - 1);
        *v19 = 1.0 / v21 * *v19;
      }
      v19 += 3;
      --v20;
    }
    while ( v20 );
  }
  ambient_color.color = (unsigned __int8)(LScape::ambient_color.color >> 16);
  ambient_level = LScape::ambient_level;
  v22 = (double)(signed int)ambient_color.color * 0.0039215689;
  sunlight_vec = LScape::sunlight;
  ag = (double)BYTE1(LScape::ambient_color.color) * 0.0039215689;
  *(float *)&ambient_color.color = (double)(unsigned __int8)LScape::ambient_color.color * 0.0039215689;
  sunlight_color.color = (unsigned __int8)(LScape::sunlight_color.color >> 16);
  sr = (double)(signed int)sunlight_color.color * 0.0039215689;
  v23 = 0;
  sunlight_color.color = (unsigned __int8)LScape::sunlight_color.b;
  iq = 0;
  sg = (double)BYTE1(LScape::sunlight_color.color) * 0.0039215689;
  sb = (double)(unsigned __int8)LScape::sunlight_color.color * 0.0039215689;
  if ( (signed int)v18 >= 4 )
  {
    v24 = ambient_level * v22;
    v25 = 8 - (_DWORD)&v50;
    v26 = ag * ambient_level;
    v27 = *(float *)&ambient_color.color * ambient_level;
    v28 = -16 - (_DWORD)&v50;
    sunlight_color.color = 3;
    v29 = (char *)&sunlight_vec.y;
    v54 = 8 - (_DWORD)&v50;
    v53 = 20 - (_DWORD)&v50;
    v55 = -16 - (_DWORD)&v50;
    while ( 1 )
    {
      v30 = sunlight_vec.z * *((float *)v29 - 2)
          + sunlight_vec.y * *((float *)v29 - 3)
          + sunlight_vec.x * *((float *)v29 - 4);
      if ( v30 < 0.0 )
        v30 = 0.0;
      r = sr * v30 + v24;
      g = sg * v30 + v26;
      v31 = v30 * sb + v27;
      if ( r > 1.0 )
        r = 1.0;
      if ( g > 1.0 )
        g = 1.0;
      if ( v31 > 1.0 )
        v31 = 1.0;
      v32 = (int)&v29[v28];
      *(float *)((char *)&v1->vertex_lighting->r + v32) = r;
      *(float *)((char *)&v1->vertex_lighting->g + v32) = g;
      *(float *)((char *)&v1->vertex_lighting->b + v32) = v31;
      v33 = sunlight_vec.z * *((float *)v29 + 1) + sunlight_vec.x * *((float *)v29 - 1) + sunlight_vec.y * *(float *)v29;
      if ( v33 < 0.0 )
        v33 = 0.0;
      r = sr * v33 + v24;
      g = sg * v33 + v26;
      v34 = v33 * sb + v27;
      if ( r > 1.0 )
        r = 1.0;
      if ( g > 1.0 )
        g = 1.0;
      if ( v34 > 1.0 )
        v34 = 1.0;
      *(float *)((char *)&v1->vertex_lighting[1].r + v32) = r;
      *(float *)((char *)&v1->vertex_lighting[1].g + v32) = g;
      *(float *)((char *)&v1->vertex_lighting[1].b + v32) = v34;
      v35 = sunlight_vec.z * *((float *)v29 + 4)
          + sunlight_vec.y * *((float *)v29 + 3)
          + sunlight_vec.x * *((float *)v29 + 2);
      if ( v35 < 0.0 )
        v35 = 0.0;
      r = sr * v35 + v24;
      g = sg * v35 + v26;
      v36 = v35 * sb + v27;
      if ( r > 1.0 )
        r = 1.0;
      if ( g > 1.0 )
        g = 1.0;
      if ( v36 > 1.0 )
        v36 = 1.0;
      *(float *)(&v29[v25] + (unsigned int)v1->vertex_lighting) = r;
      *(float *)((char *)&v1->vertex_lighting[2].g + v32) = g;
      *(float *)((char *)&v1->vertex_lighting[2].b + v32) = v36;
      v37 = sunlight_vec.z * *((float *)v29 + 7)
          + sunlight_vec.y * *((float *)v29 + 6)
          + sunlight_vec.x * *((float *)v29 + 5);
      if ( v37 < 0.0 )
        v37 = 0.0;
      r = sr * v37 + v24;
      g = sg * v37 + v26;
      v38 = v37 * sb + v27;
      if ( r > 1.0 )
        r = 1.0;
      if ( g > 1.0 )
        g = 1.0;
      if ( v38 > 1.0 )
        v38 = 1.0;
      *(float *)(&v29[v53] + (unsigned int)v1->vertex_lighting) = r;
      v39 = num_vertices;
      *(float *)((char *)&v1->vertex_lighting[3].g + v32) = g;
      v29 += 48;
      *(float *)((char *)&v1->vertex_lighting[3].b + v32) = v38;
      v23 = iq + 4;
      v41 = __OFSUB__(sunlight_color.color + 4, v39);
      v40 = ((sunlight_color.color + 4 - v39) & 0x80000000) != 0;
      iq += 4;
      sunlight_color.color += 4;
      if ( !(v40 ^ v41) )
        break;
      v28 = v55;
      v25 = v54;
    }
    v18 = v39;
  }
  if ( v23 < (signed int)v18 )
  {
    v42 = v22 * ambient_level;
    v43 = v23;
    v44 = ag * ambient_level;
    v45 = (float *)(&v50 + 3 * v23 + 1);
    v46 = v18 - v23;
    v47 = *(float *)&ambient_color.color * ambient_level;
    do
    {
      v48 = sunlight_vec.z * v45[1] + sunlight_vec.x * *(v45 - 1) + sunlight_vec.y * *v45;
      if ( v48 < 0.0 )
        v48 = 0.0;
      r = sr * v48 + v42;
      g = sg * v48 + v44;
      v49 = v48 * sb + v47;
      if ( r > 1.0 )
        r = 1.0;
      if ( g > 1.0 )
        g = 1.0;
      if ( v49 > 1.0 )
        v49 = 1.0;
      v1->vertex_lighting[v43].r = r;
      ++v43;
      *((float *)&v1->vertex_lighting[v43] - 2) = g;
      v45 += 3;
      --v46;
      *((float *)&v1->vertex_lighting[v43] - 1) = v49;
    }
    while ( v46 );
  }
}

//----- (00531D10) --------------------------------------------------------  // acclient.c:354000
void __thiscall CLandBlockStruct::ConstructPolygons(CLandBlockStruct *this, unsigned int block_id)
{
  CLandBlockStruct *v2; // esi@1
  int v3; // eax@3
  int i; // ebx@3
  int v5; // edi@4
  int v6; // eax@5
  float v7; // ST30_4@16
  int v8; // edx@7
  int *v9; // ecx@7
  int v10; // eax@7
  int v11; // ebp@8
  int v12; // eax@8
  int v13; // ebp@8
  int v14; // ebp@9
  int v15; // ecx@10
  unsigned int v16; // edx@14
  int v17; // ebp@16
  double v18; // st7@16
  unsigned int v19; // [sp-18h] [bp-34h]@8
  unsigned int v20; // [sp-14h] [bp-30h]@8
  unsigned int v21; // [sp-10h] [bp-2Ch]@8
  unsigned int v22; // [sp-Ch] [bp-28h]@8
  signed int v23; // [sp+8h] [bp-14h]@5
  int block_x; // [sp+Ch] [bp-10h]@0
  int block_y; // [sp+10h] [bp-Ch]@0
  signed int v26; // [sp+14h] [bp-8h]@7
  unsigned int block_ida; // [sp+20h] [bp+4h]@10

  v2 = this;
  if ( block_id )
  {
    block_x = (block_id >> 21) & 0x7F8;
    block_y = 8 * (unsigned __int8)(block_id >> 16);
  }
  v3 = this->side_cell_count;
  for ( i = 0; i < v3; ++i )
  {
    v5 = 0;
    if ( v3 > 0 )
    {
      v6 = i + block_x;
      v23 = 1;
      while ( 1 )
      {
        v8 = (v5 + block_y) * (214614067 * v6 + 1813693831) - 1109124029 * v6 - 1369149221;
        v26 = v5 + block_y;
        v9 = v2->SWtoNEcut;
        v10 = v2->side_polygon_count;
        if ( (double)(unsigned int)v8 * 2.3283064e-10 >= 0.5 )
        {
          v9[v5 + i * v10] = 1;
          v14 = v5 + i * v2->side_cell_count;
          *v2->lcell[v14].polygons = (CPolygon *)CLandBlockStruct::AddPolygon(
                                                   v2,
                                                   2 * (v5 + i * v2->side_polygon_count),
                                                   v5 + i * v2->side_vertex_count,
                                                   v5 + v2->side_vertex_count * (i + 1),
                                                   v5 + v2->side_vertex_count * (i + 1) + 1);
          v22 = i * v2->side_vertex_count + v5 + 1;
          v21 = v2->side_vertex_count * (i + 1) + v5 + 1;
          v20 = i * v2->side_vertex_count + v5;
          v13 = v5 + i * v2->side_cell_count;
          v19 = 2 * (v5 + i * v2->side_polygon_count) + 1;
        }
        else
        {
          v9[v5 + i * v10] = 0;
          v11 = v5 + i * v2->side_cell_count;
          *v2->lcell[v11].polygons = (CPolygon *)CLandBlockStruct::AddPolygon(
                                                   v2,
                                                   2 * (v5 + i * v2->side_polygon_count),
                                                   i * v2->side_vertex_count + v5,
                                                   v5 + v2->side_vertex_count * (i + 1),
                                                   i * v2->side_vertex_count + v5 + 1);
          v12 = v2->side_vertex_count;
          v22 = v5 + v12 * (i + 1);
          v13 = v5 + i * v2->side_cell_count;
          v21 = i * v12 + v5 + 1;
          v20 = v22 + 1;
          v19 = 2 * (v5 + i * v2->side_polygon_count) + 1;
        }
        *((_DWORD *)v2->lcell[v13].polygons + 1) = CLandBlockStruct::AddPolygon(v2, v19, v20, v21, v22);
        v15 = i + block_x;
        block_ida = i + block_x;
        if ( i + block_x < 0 || v26 < 0 || v15 >= 2040 || v26 >= 2040 )
          v16 = 0;
        else
          v16 = ((32 * (v15 & 0xFFFFFFF8) | (v26 >> 3)) << 16) | ((v26 & 7) + 8 * (block_ida & 7) + 1);
        v17 = v5 + i * v2->side_cell_count;
        v2->lcell[v17].pos.objcell_id = v16;
        ((void (__thiscall *)(int, unsigned int))v2->lcell[v17].vfptr[2].Release)(&v2->lcell[v17], v16);
        ++v5;
        v7 = (double)(2 * i + 1);
        v2->lcell[v17].pos.frame.m_fOrigin.x = v7 * flt_844C8C;
        v18 = (double)v23;
        v23 += 2;
        v2->lcell[v17].pos.frame.m_fOrigin.y = v18 * flt_844C8C;
        if ( v5 >= v2->side_cell_count )
          break;
        v6 = block_ida;
      }
    }
    v3 = v2->side_cell_count;
  }
}

//----- (00531FD0) --------------------------------------------------------  // acclient.c:354108
int __thiscall CLandBlockStruct::UnPack(CLandBlockStruct *this, void **addr, unsigned int size)
{
  CLandBlockStruct *v3; // esi@1
  signed int v4; // ecx@1
  char *v5; // edi@2
  char *v6; // edx@2
  char *v7; // ebx@2
  char *v8; // edi@2
  char *v9; // edx@2
  char *v10; // ebx@2
  char *v11; // edi@2
  char *v12; // edx@2
  signed int v13; // ecx@3
  char *v14; // ebx@4
  char *v15; // edi@4
  char *v16; // edx@4
  char *v17; // ebx@4
  char *v18; // edi@4
  char *v19; // edx@4
  char *v20; // ebx@4
  char *v21; // edi@4
  char *v22; // edx@4
  int v23; // esi@5
  int v24; // ecx@6
  char *v25; // edi@7

  v3 = this;
  CLandBlockStruct::Destroy(this);
  v4 = 3;
  do
  {
    v3->terrain[v4 - 3] = *(_WORD *)*addr;
    v5 = (char *)*addr + 2;
    *addr = v5;
    v3->terrain[v4 - 2] = *(_WORD *)v5;
    v6 = (char *)*addr + 2;
    *addr = v6;
    v3->terrain[v4 - 1] = *(_WORD *)v6;
    v7 = (char *)*addr + 2;
    *addr = v7;
    v3->terrain[v4] = *(_WORD *)v7;
    v8 = (char *)*addr + 2;
    *addr = v8;
    v3->terrain[v4 + 1] = *(_WORD *)v8;
    v9 = (char *)*addr + 2;
    *addr = v9;
    v3->terrain[v4 + 2] = *(_WORD *)v9;
    v10 = (char *)*addr + 2;
    *addr = v10;
    v3->terrain[v4 + 3] = *(_WORD *)v10;
    v11 = (char *)*addr + 2;
    *addr = v11;
    v3->terrain[v4 + 4] = *(_WORD *)v11;
    v12 = (char *)*addr + 2;
    *addr = v12;
    v3->terrain[v4 + 5] = *(_WORD *)v12;
    v4 += 9;
    *addr = (char *)*addr + 2;
  }
  while ( v4 < 84 );
  v13 = 0;
  do
  {
    v3->height[v13] = *(_BYTE *)*addr;
    v14 = (char *)*addr + 1;
    *addr = v14;
    v3->height[v13 + 1] = *v14;
    v15 = (char *)*addr + 1;
    *addr = v15;
    v3->height[v13 + 2] = *v15;
    v16 = (char *)*addr + 1;
    *addr = v16;
    v3->height[v13 + 3] = *v16;
    v17 = (char *)*addr + 1;
    *addr = v17;
    v3->height[v13 + 4] = *v17;
    v18 = (char *)*addr + 1;
    *addr = v18;
    v3->height[v13 + 5] = *v18;
    v19 = (char *)*addr + 1;
    *addr = v19;
    v3->height[v13 + 6] = *v19;
    v20 = (char *)*addr + 1;
    *addr = v20;
    v3->height[v13 + 7] = *v20;
    v21 = (char *)*addr + 1;
    *addr = v21;
    v3->height[v13 + 8] = *v21;
    v22 = (char *)*addr + 1;
    v13 += 9;
    *addr = v22;
  }
  while ( v13 < 81 );
  v23 = (signed int)v22 % 4;
  if ( (signed int)v22 % 4 )
  {
    v24 = 4 - v23;
    if ( 4 != v23 )
    {
      do
      {
        *v22 = 0;
        v25 = (char *)*addr + 1;
        --v24;
        *addr = v25;
        v22 = v25;
      }
      while ( v24 );
    }
  }
  return 1;
}

//----- (00532170) --------------------------------------------------------  // acclient.c:354222
void __userpurge CLandBlockStruct::GetCellRotation(CLandBlockStruct *this@<ecx>, int a2@<ebx>, unsigned int block_id, int ix, int iy, bool *o_bSingleTextureCell, unsigned int *o_surf_num, LandDefs::Rotation *o_rot)
{
  CLandBlockStruct *v8; // edi@1
  int v9; // eax@2
  int v10; // ebp@4
  unsigned __int16 *v11; // edi@7
  int v12; // edx@7
  unsigned int v13; // ecx@7
  unsigned __int16 v14; // si@7
  int v15; // eax@7
  unsigned int v16; // ecx@7
  unsigned int v17; // ebx@7
  int v18; // esi@7
  unsigned int v19; // ebx@7
  int v20; // edi@7
  bool v21; // dl@10
  bool v22; // al@15
  int v23; // ebx@17
  bool v24; // al@18
  int v25; // ST18_4@23
  LandSurf *v26; // eax@23
  int v27; // [sp-4h] [bp-24h]@1
  int r3; // [sp+0h] [bp-20h]@7
  signed int tex_size; // [sp+4h] [bp-1Ch]@5
  int x; // [sp+8h] [bp-18h]@0
  int xa; // [sp+8h] [bp-18h]@4
  int y; // [sp+Ch] [bp-14h]@0
  int ya; // [sp+Ch] [bp-14h]@4
  unsigned int pal_code[4]; // [sp+10h] [bp-10h]@7
  int block_ida; // [sp+24h] [bp+4h]@7
  int r1; // [sp+28h] [bp+8h]@7

  v27 = a2;
  v8 = this;
  if ( block_id )
  {
    x = (block_id >> 21) & 0x7F8;
    v9 = 8 * (unsigned __int8)(block_id >> 16);
  }
  else
  {
    v9 = y;
  }
  xa = ix + x;
  ya = iy + v9;
  v10 = 8 / this->side_cell_count;
  if ( CRegionDesc::IsPalShifted(CRegionDesc::current_region) )
    tex_size = 1;
  else
    tex_size = v10 != 1 ? 4 : 1;
  v11 = v8->terrain;
  v12 = ix + iy + 8 * ix;
  v13 = v11[v10 * (ix + iy + 8 * ix)];
  block_ida = v13 & 3;
  v14 = v11[v10 * (ix + iy + 8 * ix + 8 + 1)];
  v15 = (v13 >> 2) & 0x1F;
  v16 = ((unsigned int)v14 >> 2) & 0x1F;
  v17 = v11[v10 * (ix + iy + 8 * ix + 8 + 2)];
  r1 = v14 & 3;
  r3 = v17 & 3;
  v18 = (v17 >> 2) & 0x1F;
  v19 = v11[v10 * (v12 + 1)];
  v20 = (v19 >> 2) & 0x1F;
  pal_code[0] = v20
              + (tex_size << 28)
              + 32 * (v18 + 32 * (v16 + 32 * (v15 + 32 * ((v19 & 3) + 4 * (r3 + 4 * (r1 + 4 * block_ida))))));
  pal_code[1] = v15
              + (tex_size << 28)
              + 32 * (v20 + 32 * (v18 + 32 * (v16 + 32 * (block_ida + 4 * ((v19 & 3) + 4 * (r3 + 4 * r1))))));
  pal_code[2] = v16
              + (tex_size << 28)
              + 32 * (v15 + 32 * (v20 + 32 * (v18 + 32 * (r1 + 4 * (block_ida + 4 * ((v19 & 3) + 4 * r3))))));
  pal_code[3] = v18
              + (tex_size << 28)
              + 32 * (v16 + 32 * (v15 + 32 * (v20 + 32 * (r3 + 4 * (r1 + 4 * (block_ida + 4 * (v19 & 3)))))));
  v21 = block_ida == r1 && block_ida == r3 && block_ida == (v19 & 3);
  v22 = v15 == v16 && v15 == v18 && v15 == v20;
  v23 = v27;
  if ( block_ida )
    v24 = v21;
  else
    v24 = v21 && v22;
  *o_bSingleTextureCell = v24;
  v25 = CRegionDesc::current_region->minimize_pal;
  v26 = (LandSurf *)CommandList::GetHead((ChatDisplayInfo *)CRegionDesc::current_region->terrain_info);
  LandSurf::SelectTerrain(v26, v23, xa, ya, o_surf_num, o_rot, pal_code, tex_size, v25);
}
// 532170: could not find valid save-restore pair for ebx

//----- (005323D0) --------------------------------------------------------  // acclient.c:354312
void __thiscall CLandBlockStruct::TransAdjust(CLandBlockStruct *this)
{
  LandDefs::Direction v1; // eax@1
  signed int v2; // edi@1
  int v3; // esi@4
  int v4; // eax@5
  unsigned __int32 v5; // ebp@5
  unsigned __int32 v6; // edx@5
  unsigned __int32 v7; // eax@5
  LandDefs::Direction v8; // eax@6
  int i; // esi@9
  CVertex *v10; // ebx@10
  unsigned __int32 v11; // edx@10
  double v12; // st7@10
  LandDefs::Direction v13; // eax@11
  int j; // esi@14
  int v15; // eax@15
  unsigned __int32 v16; // edx@15
  unsigned __int32 v17; // ebp@15
  unsigned __int32 v18; // eax@15
  LandDefs::Direction v19; // eax@16
  int v20; // eax@19
  signed int k; // esi@19
  int v22; // eax@20
  int v23; // esi@23
  signed int v24; // ebx@24
  char *v25; // edx@25
  char *v26; // eax@25
  int v27; // ebp@25
  int v28; // eax@25
  double v29; // st7@25
  double v30; // st6@25
  double v31; // st5@25
  double v32; // st7@27
  int v33; // eax@31
  signed int v34; // esi@31
  signed int v35; // ebx@32
  char *v36; // edx@33
  char *v37; // eax@33
  int v38; // ebp@33
  int v39; // eax@33
  double v40; // st7@33
  double v41; // st6@33
  double v42; // st5@33
  double v43; // st7@35
  int l; // edx@39
  char *v45; // esi@40
  char *v46; // eax@40
  int v47; // ebx@40
  int v48; // eax@40
  double v49; // st7@40
  double v50; // st6@40
  double v51; // st5@40
  double v52; // st7@42
  int v53; // eax@46
  signed int m; // edx@46
  char *v55; // esi@47
  char *v56; // eax@47
  double v57; // st7@47
  double v58; // st6@47
  int v59; // edi@47
  double v60; // st5@47
  double v61; // st7@49

  v1 = this->trans_dir;
  v2 = 1;
  if ( v1 == 5 || v1 == 1 || v1 == 7 )
  {
    v3 = this->side_polygon_count;
    if ( v3 > 1 )
    {
      do
      {
        v4 = this->side_vertex_count;
        v5 = CVertexArray::vertex_size * (v3 + v4 * (v2 - 1));
        v6 = CVertexArray::vertex_size * (v3 + v4 * (v2 + 1));
        v7 = CVertexArray::vertex_size * (v3 + v2 * v4);
        v2 += 2;
        *(float *)((char *)&this->vertex_array.vertices->z + v7) = (*(float *)((char *)&this->vertex_array.vertices->z
                                                                             + v5)
                                                                  + *(float *)((char *)&this->vertex_array.vertices->z
                                                                             + v6))
                                                                 * 0.5;
        v3 = this->side_polygon_count;
      }
      while ( v2 < v3 );
    }
  }
  v8 = this->trans_dir;
  if ( v8 == 5 || v8 == 4 || v8 == 6 )
  {
    for ( i = 1; i < this->side_polygon_count; *(float *)((char *)&v10->z + v11) = v12 * 0.5 )
    {
      v10 = this->vertex_array.vertices;
      v11 = i * CVertexArray::vertex_size;
      v12 = *(float *)((char *)&v10->z + CVertexArray::vertex_size * (i - 1))
          + *(float *)((char *)&v10->z + CVertexArray::vertex_size * (i + 1));
      i += 2;
    }
  }
  v13 = this->trans_dir;
  if ( v13 == 6 || v13 == 2 || v13 == 8 )
  {
    for ( j = 1;
          j < this->side_polygon_count;
          *(float *)((char *)&this->vertex_array.vertices->z + v18) = (*(float *)((char *)&this->vertex_array.vertices->z
                                                                                + v17)
                                                                     + *(float *)((char *)&this->vertex_array.vertices->z
                                                                                + v16))
                                                                    * 0.5 )
    {
      v15 = this->side_vertex_count;
      v16 = CVertexArray::vertex_size * v15 * (j + 1);
      v17 = CVertexArray::vertex_size * v15 * (j - 1);
      v18 = j * CVertexArray::vertex_size * v15;
      j += 2;
    }
  }
  v19 = this->trans_dir;
  if ( v19 == 8 || v19 == 3 || v19 == 7 )
  {
    v20 = this->side_polygon_count;
    for ( k = 1; k < v20; v20 = this->side_polygon_count )
    {
      v22 = v20 * this->side_vertex_count + k;
      k += 2;
      *(float *)((char *)&this->vertex_array.vertices->z + CVertexArray::vertex_size * v22) = (*(float *)((char *)&this->vertex_array.vertices->z + CVertexArray::vertex_size * (v22 - 1))
                                                                                             + *(float *)((char *)&this->vertex_array.vertices->z + CVertexArray::vertex_size * (v22 + 1)))
                                                                                            * 0.5;
    }
  }
  if ( this->side_cell_count == 4 )
  {
    if ( this->trans_dir == 1 )
    {
      v23 = 1;
      if ( this->side_polygon_count > 1 )
      {
        v24 = 18;
        do
        {
          v25 = (char *)&this->vertex_array.vertices->vertex.z
              + v23 * CVertexArray::vertex_size * this->side_vertex_count;
          v26 = this->height;
          v27 = (unsigned __int8)v26[v24 + 9];
          v28 = (int)&v26[v24];
          v29 = *(float *)&(&LandDefs::Land_Height_Table)[v27];
          v30 = *(float *)&(&LandDefs::Land_Height_Table)[*(_BYTE *)(v28 + 18)];
          v31 = *(float *)&(&LandDefs::Land_Height_Table)[*(_BYTE *)(v28 - 9)]
              + *(float *)&(&LandDefs::Land_Height_Table)[*(_BYTE *)(v28 - 9)]
              - *(float *)&(&LandDefs::Land_Height_Table)[*(_BYTE *)(v28 - 18)];
          if ( v31 < *(float *)v25 )
            *(float *)v25 = v31;
          v32 = v29 + v29 - v30;
          if ( v32 < *(float *)v25 )
            *(float *)v25 = v32;
          v23 += 2;
          v24 += 36;
        }
        while ( v23 < this->side_polygon_count );
      }
    }
    if ( this->trans_dir == 2 )
    {
      v33 = this->side_polygon_count;
      v34 = 1;
      if ( v33 > 1 )
      {
        v35 = 18;
        do
        {
          v36 = (char *)&this->vertex_array.vertices->vertex.z
              + CVertexArray::vertex_size * (v33 + v34 * this->side_vertex_count);
          v37 = this->height;
          v38 = (unsigned __int8)v37[v35 + 17];
          v39 = (int)&v37[v35 + 9];
          v40 = *(float *)&(&LandDefs::Land_Height_Table)[v38];
          v41 = *(float *)&(&LandDefs::Land_Height_Table)[*(_BYTE *)(v39 + 17)];
          v42 = *(float *)&(&LandDefs::Land_Height_Table)[*(_BYTE *)(v39 - 10)]
              + *(float *)&(&LandDefs::Land_Height_Table)[*(_BYTE *)(v39 - 10)]
              - *(float *)&(&LandDefs::Land_Height_Table)[*(_BYTE *)(v39 - 19)];
          if ( v42 < *(float *)v36 )
            *(float *)v36 = v42;
          v43 = v40 + v40 - v41;
          if ( v43 < *(float *)v36 )
            *(float *)v36 = v43;
          v33 = this->side_polygon_count;
          v34 += 2;
          v35 += 36;
        }
        while ( v34 < v33 );
      }
    }
    if ( this->trans_dir == 3 )
    {
      for ( l = 1; l < this->side_polygon_count; l += 2 )
      {
        v45 = (char *)&this->vertex_array.vertices->vertex.z + l * CVertexArray::vertex_size;
        v46 = this->height;
        v47 = (unsigned __int8)v46[2 * l + 1];
        v48 = (int)&v46[2 * l];
        v49 = *(float *)&(&LandDefs::Land_Height_Table)[v47];
        v50 = *(float *)&(&LandDefs::Land_Height_Table)[*(_BYTE *)(v48 + 2)];
        v51 = *(float *)&(&LandDefs::Land_Height_Table)[*(_BYTE *)(v48 - 1)]
            + *(float *)&(&LandDefs::Land_Height_Table)[*(_BYTE *)(v48 - 1)]
            - *(float *)&(&LandDefs::Land_Height_Table)[*(_BYTE *)(v48 - 2)];
        if ( v51 < *(float *)v45 )
          *(float *)v45 = v51;
        v52 = v49 + v49 - v50;
        if ( v52 < *(float *)v45 )
          *(float *)v45 = v52;
      }
    }
    if ( this->trans_dir == 4 )
    {
      v53 = this->side_polygon_count;
      for ( m = 1; m < v53; m += 2 )
      {
        v55 = (char *)&this->vertex_array.vertices->vertex.z
            + CVertexArray::vertex_size * (m + v53 * this->side_vertex_count);
        v56 = this->height;
        v57 = *(float *)&(&LandDefs::Land_Height_Table)[(unsigned __int8)v56[2 * m + 73]];
        v58 = *(float *)&(&LandDefs::Land_Height_Table)[(unsigned __int8)v56[2 * m + 74]];
        v59 = (unsigned __int8)v56[2 * m + 71];
        v60 = *(float *)&(&LandDefs::Land_Height_Table)[v59]
            + *(float *)&(&LandDefs::Land_Height_Table)[v59]
            - *(float *)&(&LandDefs::Land_Height_Table)[(unsigned __int8)v56[2 * m + 70]];
        if ( v60 < *(float *)v55 )
          *(float *)v55 = v60;
        v61 = v57 + v57 - v58;
        if ( v61 < *(float *)v55 )
          *(float *)v55 = v61;
        v53 = this->side_polygon_count;
      }
    }
  }
}
// 81E700: using guessed type unsigned __int32 CVertexArray::vertex_size;
// 8EDA28: using guessed type float *LandDefs::Land_Height_Table;

//----- (005327B0) --------------------------------------------------------  // acclient.c:354553
void __thiscall CLandBlockStruct::~CLandBlockStruct(CLandBlockStruct *this)
{
  CLandBlockStruct *v1; // esi@1

  v1 = this;
  CLandBlockStruct::Destroy(this);
  operator delete[](v1->height);
  operator delete[](v1->terrain);
  gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&v1->vertex_array);
}

//----- (005327E0) --------------------------------------------------------  // acclient.c:354565
void __thiscall CLandBlockStruct::CalcWater(CLandBlockStruct *this)
{
  CLandBlockStruct *v1; // esi@1
  int v2; // ebx@1
  signed int v3; // ebp@1
  int i; // edi@3
  int block_has_water; // [sp+Ch] [bp-Ch]@1
  int cell_has_water; // [sp+10h] [bp-8h]@4
  int cell_all_water; // [sp+14h] [bp-4h]@4

  v1 = this;
  v2 = 0;
  block_has_water = 0;
  v3 = 1;
  if ( this->side_cell_count == 8 )
  {
    do
    {
      for ( i = 0; i < v1->side_cell_count; ++i )
      {
        CLandBlockStruct::CalcCellWater(v1, v2, i, &cell_has_water, &cell_all_water);
        if ( cell_has_water )
        {
          block_has_water = 1;
          if ( cell_all_water )
          {
            *((_DWORD *)&v1->lcell[i].water_type + 66 * v2 * v1->side_cell_count) = 2;
          }
          else
          {
            v3 = 0;
            *((_DWORD *)&v1->lcell[i].water_type + 66 * v2 * v1->side_cell_count) = 1;
          }
        }
        else
        {
          v3 = 0;
          *((_DWORD *)&v1->lcell[i].water_type + 66 * v2 * v1->side_cell_count) = 0;
        }
      }
      ++v2;
    }
    while ( v2 < v1->side_cell_count );
    if ( block_has_water )
      v1->water_type = (v3 != 0) + 1;
    else
      v1->water_type = 0;
  }
  else
  {
    this->water_type = 0;
  }
}

//----- (005328D0) --------------------------------------------------------  // acclient.c:354620
void __thiscall CLandBlockStruct::ConstructVertices(CLandBlockStruct *this)
{
  int v1; // eax@1
  int v2; // edx@1
  int v3; // ebx@1
  int v4; // edi@2
  int v5; // esi@3
  float v6; // ST20_4@4
  float v7; // ST24_4@4
  double v8; // st7@4
  char *v9; // edx@4
  float v10; // ST28_4@4
  float poly_size; // [sp+4h] [bp-1Ch]@1
  int iy; // [sp+8h] [bp-18h]@3
  int ix; // [sp+Ch] [bp-14h]@1
  int v14; // [sp+10h] [bp-10h]@2

  v1 = 8 / this->side_cell_count;
  v2 = this->side_vertex_count;
  v3 = 0;
  ix = 0;
  poly_size = flt_844C88 / (double)this->side_polygon_count;
  if ( v2 > 0 )
  {
    v4 = 0;
    v14 = 0;
    do
    {
      v5 = 0;
      for ( iy = 0; v5 < v2; iy = v5 )
      {
        v7 = (double)iy * poly_size;
        v8 = *(float *)&(&LandDefs::Land_Height_Table)[this->height[v4]];
        v9 = (char *)this->vertex_array.vertices + CVertexArray::vertex_size * (v5 + v3 * v2);
        v6 = (double)ix * poly_size;
        *(float *)v9 = v6;
        *((float *)v9 + 1) = v7;
        v10 = v8;
        *((float *)v9 + 2) = v10;
        v2 = this->side_vertex_count;
        ++v5;
        v4 += v1;
      }
      v4 = 9 * v1 + v14;
      v2 = this->side_vertex_count;
      ++v3;
      ix = v3;
      v14 += 9 * v1;
    }
    while ( v3 < v2 );
  }
}
// 81E700: using guessed type unsigned __int32 CVertexArray::vertex_size;
// 8EDA28: using guessed type float *LandDefs::Land_Height_Table;

//----- (005329A0) --------------------------------------------------------  // acclient.c:354676
void __userpurge CLandBlockStruct::ConstructUVs(CLandBlockStruct *this@<ecx>, __int16 a2@<bx>, unsigned int block_id)
{
  CLandBlockStruct *v3; // esi@1
  int v4; // eax@1
  int v5; // ebp@1
  int v6; // edi@3
  int v7; // eax@4
  VertexType v8; // ecx@6
  int v9; // ecx@8
  int v10; // ecx@8
  char v11; // dl@8
  int v12; // ecx@10
  bool bSingleTextureCell; // [sp+Bh] [bp-9h]@4
  LandDefs::Rotation rotation; // [sp+Ch] [bp-8h]@4
  unsigned int surf_num; // [sp+10h] [bp-4h]@4

  v3 = this;
  v4 = this->side_polygon_count;
  v5 = 0;
  if ( v4 > 0 )
  {
    LOBYTE(a2) = 3;
    while ( 1 )
    {
      v6 = 0;
      if ( v4 > 0 )
        break;
LABEL_13:
      v4 = v3->side_polygon_count;
      ++v5;
      if ( v5 >= v4 )
        return;
    }
    while ( 1 )
    {
      CLandBlockStruct::GetCellRotation(v3, a2, block_id, v5, v6, &bSingleTextureCell, &surf_num, &rotation);
      v7 = 2 * (v6 + v5 * v3->side_polygon_count);
      if ( bSingleTextureCell )
      {
        v3->polygons[2 * (v6 + v5 * v3->side_polygon_count)].stippling = 3;
        *(&v3->polygons->stippling + 16 * (3 * v7 + 3)) = 3;
      }
      v8 = v3->vertex_array.vertex_type;
      if ( v3->SWtoNEcut[v6 + v5 * v3->side_polygon_count] )
      {
        if ( v8 == 1 )
        {
          *v3->polygons[v7].pos_uv_indices = LOBYTE(SW_Corner[rotation]);
          v3->polygons[v7].pos_uv_indices[1] = LOBYTE(SE_Corner[rotation]);
          v3->polygons[v7].pos_uv_indices[2] = LOBYTE(NE_Corner[rotation]);
          v9 = 16 * (3 * v7 + 3);
          **(char **)((char *)&v3->polygons->pos_uv_indices + v9) = LOBYTE(SW_Corner[rotation]);
          (*(char **)((char *)&v3->polygons->pos_uv_indices + v9))[1] = LOBYTE(NE_Corner[rotation]);
          v10 = *(int *)((char *)&v3->polygons->pos_uv_indices + v9);
          v11 = LOBYTE(NW_Corner[rotation]);
LABEL_11:
          *(_BYTE *)(v10 + 2) = v11;
          goto LABEL_12;
        }
      }
      else if ( v8 == 1 )
      {
        *v3->polygons[v7].pos_uv_indices = LOBYTE(SW_Corner[rotation]);
        v3->polygons[v7].pos_uv_indices[1] = LOBYTE(SE_Corner[rotation]);
        v3->polygons[v7].pos_uv_indices[2] = LOBYTE(NW_Corner[rotation]);
        v12 = 16 * (3 * v7 + 3);
        **(char **)((char *)&v3->polygons->pos_uv_indices + v12) = LOBYTE(NE_Corner[rotation]);
        (*(char **)((char *)&v3->polygons->pos_uv_indices + v12))[1] = LOBYTE(NW_Corner[rotation]);
        v10 = *(int *)((char *)&v3->polygons->pos_uv_indices + v12);
        v11 = LOBYTE(SE_Corner[rotation]);
        goto LABEL_11;
      }
LABEL_12:
      HIBYTE(a2) = BYTE1(surf_num);
      v3->polygons[v7].pos_surface = surf_num;
      *(&v3->polygons->pos_surface + 8 * (3 * v7 + 3)) = surf_num;
      ++v6;
      LOBYTE(a2) = 3;
      if ( v6 >= v3->side_polygon_count )
        goto LABEL_13;
    }
  }
}

//----- (00532BB0) --------------------------------------------------------  // acclient.c:354761
int __thiscall CLandBlockStruct::generate(CLandBlockStruct *this, unsigned int block_id, unsigned int poly_size, LandDefs::Direction tdir)
{
  CLandBlockStruct *v4; // esi@1
  unsigned int v5; // edi@1
  int v6; // eax@1
  int result; // eax@3
  signed int v8; // ebx@4
  CLandBlockStruct *v9; // ecx@8
  signed int v10; // eax@9

  v4 = this;
  v5 = 8 / poly_size;
  v6 = this->side_cell_count;
  if ( v6 != 8 / poly_size || this->trans_dir != tdir )
  {
    v8 = 0;
    if ( v6 != v5 )
    {
      v8 = 1;
      if ( v6 > 0 )
        CLandBlockStruct::Destroy(this);
      v4->side_cell_count = v5;
      v4->side_polygon_count = v5;
      v4->side_vertex_count = v5 + 1;
      CLandBlockStruct::InitPVArrays(v4);
    }
    v4->trans_dir = tdir;
    CLandBlockStruct::ConstructVertices(v4);
    if ( v4->trans_dir )
    {
      v10 = v4->side_cell_count;
      if ( v10 > 1 && v10 < 8 )
        CLandBlockStruct::TransAdjust(v9);
    }
    if ( v8 )
    {
      CLandBlockStruct::ConstructPolygons(v4, block_id);
      CLandBlockStruct::ConstructUVs(v4, v8, block_id);
      CLandBlockStruct::CalcWater(v4);
      result = v8;
    }
    else
    {
      CLandBlockStruct::AdjPlanes(v4);
      CLandBlockStruct::CalcWater(v4);
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006FEF70) --------------------------------------------------------  // acclient.c:787071
void sub_6FEF70()
{
  flt_844C84 = 1000.0 + 1.0;
}

//----- (006FEF90) --------------------------------------------------------  // acclient.c:787077
void sub_6FEF90()
{
  flt_844C88 = 24.0 * 8.0;
}

//----- (006FEFB0) --------------------------------------------------------  // acclient.c:787083
void sub_6FEFB0()
{
  flt_844C8C = 24.0 * 0.5;
}

//----- (006FEFD0) --------------------------------------------------------  // acclient.c:787089
void sub_6FEFD0()
{
  flt_844C94 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FEFF0) --------------------------------------------------------  // acclient.c:787095
void _E99_30()
{
  dbl_844C98 = 1.0 / 30.0;
}

//----- (006FF010) --------------------------------------------------------  // acclient.c:787101
void _E101_28()
{
  dbl_844CA0 = 1.0 / 5.0;
}

//----- (006FF030) --------------------------------------------------------  // acclient.c:787107
int sub_6FF030()
{
  return atexit(nullsub_1162);
}

//----- (006FF040) --------------------------------------------------------  // acclient.c:787113
int sub_6FF040()
{
  return atexit(nullsub_1163);
}

