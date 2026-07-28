/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPolygon
   Object     : PORTAL\cgeometry\CPolygon.obj
   Functions  : 24
   Addresses  : 00538060 - 00700190 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00538060) --------------------------------------------------------  // acclient.c:359419
int __thiscall CPolygon::point_in_poly2D(CPolygon *this, AC1Legacy::Vector3 *point, Sidedness side)
{
  int v3; // edx@1
  CVertex *v4; // eax@1
  CVertex **v5; // esi@2
  CVertex *v6; // ecx@3
  double v7; // st7@3
  double v8; // st6@3
  double v9; // st7@3

  v3 = this->num_pts - 1;
  v4 = *this->vertices;
  if ( v3 >= 0 )
  {
    v5 = &this->vertices[v3];
    do
    {
      v6 = *v5;
      v7 = v4->y - (*v5)->y;
      v8 = (*v5)->x - v4->x;
      v9 = -(v7 * (*v5)->x) - v8 * (*v5)->y + v8 * point->y + v7 * point->x;
      if ( side )
      {
        if ( v9 < 0.0 )
          return 0;
      }
      else if ( v9 > 0.0 )
      {
        return 0;
      }
      --v3;
      --v5;
      v4 = v6;
    }
    while ( v3 >= 0 );
  }
  return 1;
}

//----- (005380E0) --------------------------------------------------------  // acclient.c:359459
void __thiscall CPolygon::Destroy(CPolygon *this)
{
  CPolygon *v1; // esi@1

  v1 = this;
  if ( this->pos_uv_indices )
  {
    operator delete[](this->pos_uv_indices);
    v1->pos_uv_indices = 0;
  }
  if ( v1->sides_type == 2 && v1->neg_uv_indices )
  {
    operator delete[](v1->neg_uv_indices);
    v1->neg_uv_indices = 0;
  }
  if ( v1->vertices )
  {
    operator delete[](v1->vertices);
    v1->vertices = 0;
  }
  if ( v1->vertex_ids )
  {
    operator delete[](v1->vertex_ids);
    v1->vertex_ids = 0;
  }
  if ( v1->screen )
  {
    operator delete[](v1->screen);
    v1->screen = 0;
  }
  v1->num_pts = 0;
  v1->stippling = 0;
  v1->pos_surface = -1;
  v1->neg_surface = -1;
  v1->poly_id = -1;
}

//----- (00538170) --------------------------------------------------------  // acclient.c:359497
double __thiscall CPolygon::adjust_sphere_to_poly(CPolygon *this, CSphere *check_pos, AC1Legacy::Vector3 *curr_pos, AC1Legacy::Vector3 *movement)
{
  double result; // st7@2
  long double v5; // st7@3
  double v7; // st6@5
  unsigned __int8 v8; // c0@5
  unsigned __int8 v9; // c3@5
  float curr_posa; // [sp+8h] [bp+8h]@1

  curr_posa = this->plane.N.z * curr_pos->z
            + this->plane.N.y * curr_pos->y
            + curr_pos->x * this->plane.N.x
            + this->plane.d;
  if ( check_pos->radius <= fabs(curr_posa) )
  {
    v5 = this->plane.N.z * movement->z + this->plane.N.y * movement->y + movement->x * this->plane.N.x;
    if ( fabs(v5) >= 0.00019999999 )
    {
      v7 = check_pos->radius;
      if ( v8 | v9 )
        v7 = -v7;
      result = (v7 - curr_posa) / v5;
    }
    else
    {
      result = 0.0;
    }
  }
  else
  {
    result = 1.0;
  }
  return result;
}

//----- (00538210) --------------------------------------------------------  // acclient.c:359533
int __thiscall CPolygon::adjust_sphere_to_plane(CPolygon *this, SPHEREPATH *path, CSphere *valid_pos, AC1Legacy::Vector3 *movement)
{
  CSphere *v4; // edx@1
  double v5; // st7@1
  double v6; // st6@1
  double v7; // rt0@2
  double v8; // st6@2
  double v9; // st7@2
  double v10; // rt1@4
  double v11; // st6@4
  double v12; // st7@5
  double v13; // st6@5
  float v14; // ST08_4@7
  float v15; // ST0C_4@7
  int result; // eax@7
  float valid_posa; // [sp+18h] [bp+8h]@5

  v4 = valid_pos;
  v5 = this->plane.N.y * valid_pos->center.y
     + this->plane.N.z * valid_pos->center.z
     + valid_pos->center.x * this->plane.N.x
     + this->plane.d;
  v6 = this->plane.N.z * movement->z + this->plane.N.y * movement->y + this->plane.N.x * movement->x;
  if ( v6 <= 0.00019999999 )
  {
    if ( v6 >= -0.00019999999 )
      return 0;
    v10 = v6;
    v11 = v5;
    v9 = v10;
    v8 = v11 - valid_pos->radius;
  }
  else
  {
    v7 = v6;
    v8 = -valid_pos->radius - v5;
    v9 = v7;
  }
  v12 = v8 / v9;
  v13 = (1.0 - v12) * path->walk_interp;
  valid_posa = v13;
  if ( v13 >= path->walk_interp || valid_posa < -0.5 )
  {
    result = 0;
  }
  else
  {
    v14 = v12 * movement->y;
    v15 = v12 * movement->z;
    v4->center.x = v4->center.x - v12 * movement->x;
    v4->center.y = v4->center.y - v14;
    v4->center.z = v4->center.z - v15;
    path->walk_interp = valid_posa;
    result = 1;
  }
  return result;
}

//----- (00538320) --------------------------------------------------------  // acclient.c:359592
int __thiscall Plane::compute_time_of_intersection(Plane *this, Ray *line, long double *time)
{
  long double v3; // st7@1
  int result; // eax@2
  long double v5; // st7@3

  v3 = line->dir.z * this->N.z + line->dir.y * this->N.y + line->dir.x * this->N.x;
  result = 0;
  if ( fabs(v3) >= 0.00019999999 )
  {
    v5 = (line->pt.z * this->N.z + line->pt.y * this->N.y + line->pt.x * this->N.x + this->d) * (-1.0 / v3);
    *time = v5;
    if ( v5 >= 0.0 )
      result = 1;
  }
  return result;
}

//----- (005383A0) --------------------------------------------------------  // acclient.c:359611
void __thiscall CPolygon::CPolygon(CPolygon *this)
{
  this->vertices = 0;
  this->vertex_ids = 0;
  this->poly_id = -1;
  this->num_pts = 0;
  this->stippling = 0;
  this->sides_type = 0;
  this->pos_uv_indices = 0;
  this->neg_uv_indices = 0;
  this->pos_surface = -1;
  this->neg_surface = -1;
  this->screen = 0;
}

//----- (005383D0) --------------------------------------------------------  // acclient.c:359627
void __thiscall CPolygon::make_plane(CPolygon *this)
{
  double v1; // st7@1
  int v2; // ebx@1
  double v3; // st6@1
  CVertex *v4; // eax@2
  CVertex **v5; // edx@2
  int v6; // edi@2
  CVertex *v7; // esi@3
  double v8; // st5@3
  double v9; // st4@3
  double v10; // st3@3
  int v11; // esi@3
  double v12; // st3@3
  float v13; // ST20_4@3
  float v14; // ST24_4@3
  double v15; // st2@3
  float v16; // ST2C_4@3
  float v17; // ST30_4@3
  long double v18; // st5@4
  float v19; // ST0C_4@4
  double v20; // st7@4
  CVertex **v21; // edx@5
  int v22; // esi@5
  CVertex *v23; // eax@6
  double v24; // st6@6
  char *v25; // ecx@7
  signed int v26; // [sp+Ch] [bp-28h]@1
  float normal; // [sp+10h] [bp-24h]@4
  float normal_4; // [sp+14h] [bp-20h]@4
  float normal_8; // [sp+18h] [bp-1Ch]@1
  float normal_8a; // [sp+18h] [bp-1Ch]@4

  v1 = 0.0;
  v2 = this->num_pts;
  v3 = 0.0;
  normal_8 = 0.0;
  v26 = this->num_pts;
  if ( v2 - 1 > 1 )
  {
    v4 = *this->vertices;
    v5 = this->vertices + 1;
    v6 = this->num_pts - 2;
    do
    {
      v7 = v5[1];
      ++v5;
      --v6;
      v8 = v7->x - v4->x;
      v9 = v7->y - v4->y;
      v10 = v7->vertex.z;
      v11 = (int)*(v5 - 1);
      v12 = v10 - v4->z;
      v13 = *(float *)v11 - v4->x;
      v14 = *(float *)(v11 + 4) - v4->y;
      v15 = *(float *)(v11 + 8) - v4->z;
      v16 = v14 * v12 - v15 * v9;
      v17 = v15 * v8 - v12 * v13;
      v1 = v1 + v16;
      v3 = v3 + v17;
      normal_8 = v9 * v13 - v14 * v8 + normal_8;
    }
    while ( v6 );
  }
  v18 = 1.0 / sqrt(normal_8 * normal_8 + v3 * v3 + v1 * v1);
  v19 = v18;
  normal = v18 * v1;
  normal_4 = v19 * v3;
  normal_8a = v19 * normal_8;
  v20 = 0.0;
  if ( v2 > 0 )
  {
    v21 = this->vertices;
    v22 = this->num_pts;
    do
    {
      v23 = *v21;
      v24 = normal_8a * (*v21)->z;
      ++v21;
      --v22;
      v20 = v20 + v24 + normal_4 * v23->y + normal * v23->x;
    }
    while ( v22 );
  }
  v25 = (char *)&this->plane;
  *((float *)v25 + 3) = -(v20 / (double)v26);
  *(float *)v25 = normal;
  *((float *)v25 + 1) = normal_4;
  *((float *)v25 + 2) = normal_8a;
}

//----- (00538530) --------------------------------------------------------  // acclient.c:359719
unsigned int __thiscall CPolygon::Pack(CPolygon *this, void **addr, unsigned int size)
{
  int v3; // edx@1
  char v4; // bl@1
  unsigned int result; // eax@1
  char *v6; // ebx@7
  char *v7; // edi@7
  char *v8; // esi@7
  char *v9; // ebx@7
  char *v10; // edi@7
  char *v11; // esi@7
  char *v12; // edi@7
  signed int v13; // esi@7
  signed int v14; // esi@10
  signed int v15; // esi@14

  v3 = this->num_pts;
  v4 = this->stippling;
  result = 2 * v3 + 12;
  if ( !(v4 & 4) )
    result += v3;
  if ( this->sides_type == 2 && !(v4 & 8) )
    result += v3;
  if ( size >= result )
  {
    *(_WORD *)*addr = this->poly_id;
    v6 = (char *)*addr + 2;
    *addr = v6;
    *v6 = this->num_pts;
    v7 = (char *)*addr + 1;
    *addr = v7;
    *v7 = this->stippling;
    v8 = (char *)*addr + 1;
    *addr = v8;
    *(_DWORD *)v8 = this->sides_type;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_WORD *)v9 = this->pos_surface;
    v10 = (char *)*addr + 2;
    *addr = v10;
    *(_WORD *)v10 = this->neg_surface;
    v11 = (char *)*addr + 2;
    *addr = v11;
    v12 = v11;
    v13 = 0;
    if ( this->num_pts )
    {
      do
      {
        *(_WORD *)v12 = this->vertex_ids[v13];
        v12 = (char *)*addr + 2;
        *addr = v12;
        ++v13;
      }
      while ( v13 < this->num_pts );
    }
    if ( !(this->stippling & 4) )
    {
      v14 = 0;
      if ( this->num_pts )
      {
        do
        {
          *(_BYTE *)*addr = this->pos_uv_indices[v14];
          *addr = (char *)*addr + 1;
          ++v14;
        }
        while ( v14 < this->num_pts );
      }
    }
    if ( this->sides_type == 2 && !(this->stippling & 8) )
    {
      v15 = 0;
      if ( this->num_pts )
      {
        do
        {
          *(_BYTE *)*addr = this->neg_uv_indices[v15];
          *addr = (char *)*addr + 1;
          ++v15;
        }
        while ( v15 < this->num_pts );
      }
    }
  }
  return result;
}

//----- (00538650) --------------------------------------------------------  // acclient.c:359808
int __thiscall CPolygon::UnPack(CPolygon *this, void **addr, unsigned int size)
{
  CPolygon *v3; // edi@1
  char *v4; // edx@1
  char *v5; // ecx@1
  char *v6; // eax@1
  char *v7; // edx@1
  char *v8; // ecx@1
  void *v9; // eax@1
  unsigned int v10; // ST04_4@1
  void *v11; // eax@1
  char v12; // cl@1
  signed int v13; // eax@1
  void *v14; // eax@4
  char v15; // cl@4
  signed int v16; // eax@4
  void *v17; // eax@8
  char v18; // cl@8
  signed int v19; // eax@8
  char *v20; // ecx@11

  v3 = this;
  CPolygon::Destroy(this);
  v3->poly_id = *(_WORD *)*addr;
  v4 = (char *)*addr + 2;
  *addr = v4;
  v3->num_pts = *v4;
  v5 = (char *)*addr + 1;
  *addr = v5;
  v3->stippling = *v5;
  v6 = (char *)*addr + 1;
  *addr = v6;
  v3->sides_type = *(_DWORD *)v6;
  v7 = (char *)*addr + 4;
  *addr = v7;
  v3->pos_surface = *(_WORD *)v7;
  v8 = (char *)*addr + 2;
  *addr = v8;
  v3->neg_surface = *(_WORD *)v8;
  *addr = (char *)*addr + 2;
  v9 = operator new[](4 * v3->num_pts);
  v10 = 2 * v3->num_pts;
  v3->vertices = (CVertex **)v9;
  v3->vertex_ids = (unsigned __int16 *)operator new[](v10);
  v11 = operator new[](4 * v3->num_pts);
  v12 = v3->num_pts;
  v3->screen = (Vec2Dscreen **)v11;
  v13 = 0;
  if ( v12 )
  {
    do
    {
      v3->vertex_ids[v13] = *(_WORD *)*addr;
      *addr = (char *)*addr + 2;
      v3->vertices[v13] = (CVertex *)((char *)CPolygon::pack_verts->vertices
                                    + CVertexArray::vertex_size * v3->vertex_ids[v13]);
      ++v13;
    }
    while ( v13 < v3->num_pts );
  }
  if ( !(v3->stippling & 4) )
  {
    v14 = operator new[](v3->num_pts);
    v15 = v3->num_pts;
    v3->pos_uv_indices = (char *)v14;
    v16 = 0;
    if ( v15 )
    {
      do
      {
        v3->pos_uv_indices[v16] = *(_BYTE *)*addr;
        *addr = (char *)*addr + 1;
        ++v16;
      }
      while ( v16 < v3->num_pts );
    }
  }
  if ( v3->sides_type == 2 && !(v3->stippling & 8) )
  {
    v17 = operator new[](v3->num_pts);
    v18 = v3->num_pts;
    v3->neg_uv_indices = (char *)v17;
    v19 = 0;
    if ( v18 )
    {
      do
      {
        v3->neg_uv_indices[v19] = *(_BYTE *)*addr;
        *addr = (char *)*addr + 1;
        ++v19;
      }
      while ( v19 < v3->num_pts );
    }
  }
  if ( v3->sides_type == 1 )
  {
    v20 = v3->pos_uv_indices;
    v3->neg_surface = v3->pos_surface;
    v3->neg_uv_indices = v20;
  }
  CPolygon::make_plane(v3);
  return 1;
}
// 81E700: using guessed type unsigned __int32 CVertexArray::vertex_size;
// 8450FC: using guessed type struct CVertexArray *CPolygon::pack_verts;

//----- (005387C0) --------------------------------------------------------  // acclient.c:359915
int __thiscall CPolygon::polygon_hits_sphere(CPolygon *this, CSphere *object, AC1Legacy::Vector3 *contact_pt)
{
  CSphere *v3; // edx@1
  long double v4; // st7@1
  double v5; // st6@1
  AC1Legacy::Vector3 *v7; // esi@3
  AC1Legacy::Vector3 *v8; // eax@3
  signed int v9; // ebx@3
  float v10; // ST18_4@3
  float v11; // ST1C_4@3
  float v12; // ST20_4@3
  double v13; // st7@3
  float v14; // ST24_4@3
  int v15; // eax@3
  CVertex **v16; // ebp@4
  int v17; // edi@4
  int v18; // eax@5
  CVertex *v19; // edx@5
  double v20; // st7@5
  double v21; // st4@5
  unsigned __int8 v23; // c0@6
  unsigned __int8 v24; // c2@6
  double v25; // st7@7
  float edge; // [sp+0h] [bp-18h]@5
  float edge_4; // [sp+4h] [bp-14h]@5
  float edge_8; // [sp+8h] [bp-10h]@5
  float disp; // [sp+Ch] [bp-Ch]@5
  float disp_4; // [sp+10h] [bp-8h]@5
  float disp_8; // [sp+14h] [bp-4h]@5
  float objecta; // [sp+1Ch] [bp+4h]@3
  float radsq; // [sp+20h] [bp+8h]@3

  v3 = object;
  v4 = this->plane.N.y * object->center.y
     + this->plane.N.z * object->center.z
     + this->plane.N.x * object->center.x
     + this->plane.d;
  v5 = object->radius - 0.00019999999;
  if ( v5 < fabs(v4) )
    return 0;
  v7 = contact_pt;
  v8 = contact_pt;
  v9 = 0;
  LODWORD(radsq) = 1;
  objecta = v5 * v5 - v4 * v4;
  v10 = v4 * this->plane.N.z;
  v11 = v3->center.x - v4 * this->plane.N.x;
  v12 = v3->center.y - v4 * this->plane.N.y;
  v13 = v3->center.z - v10;
  v8->x = v11;
  v8->y = v12;
  v14 = v13;
  v8->z = v14;
  v15 = this->num_pts;
  if ( v15 <= 0 )
    return LODWORD(radsq);
  v16 = this->vertices;
  v17 = 4 * v15 - 4;
  while ( 1 )
  {
    v18 = *(int *)((char *)v16 + v17);
    v17 = 4 * v9;
    v19 = v16[v9];
    edge = v19->x - *(float *)v18;
    edge_4 = v19->y - *(float *)(v18 + 4);
    v20 = v19->z - *(float *)(v18 + 8);
    edge_8 = v20;
    disp = v7->x - *(float *)v18;
    disp_4 = v7->y - *(float *)(v18 + 4);
    v21 = v7->z - *(float *)(v18 + 8);
    disp_8 = v21;
    if ( v21 * (edge_4 * this->plane.N.x - edge * this->plane.N.y)
       + disp_4 * (edge * this->plane.N.z - edge_8 * this->plane.N.x)
       + disp * (v20 * this->plane.N.y - edge_4 * this->plane.N.z) >= 0.0 )
      goto LABEL_11;
    if ( v23 | v24 )
      return 0;
    v25 = disp_8 * edge_8 + disp_4 * edge_4 + disp * edge;
    if ( v25 >= 0.0 && v25 <= edge_8 * edge_8 + edge_4 * edge_4 + edge * edge )
      return 1;
    radsq = 0.0;
LABEL_11:
    if ( disp_8 * disp_8 + disp_4 * disp_4 + disp * disp <= objecta )
      return 1;
    ++v9;
    if ( v9 >= this->num_pts )
      return LODWORD(radsq);
  }
}

//----- (00538A10) --------------------------------------------------------  // acclient.c:360006
int __thiscall CPolygon::polygon_hits_sphere_slow_but_sure(CPolygon *this, CSphere *object, AC1Legacy::Vector3 *contact_pt)
{
  CSphere *v3; // edx@1
  long double v4; // st7@1
  double v5; // st6@1
  int result; // eax@2
  int v7; // ebp@3
  float v8; // ST18_4@3
  float v9; // ST1C_4@3
  float v10; // ST20_4@3
  double v11; // st7@3
  float v12; // ST24_4@3
  int v13; // eax@3
  CVertex **v14; // edi@4
  int v15; // ebx@4
  int v16; // eax@5
  CVertex *v17; // esi@5
  double v18; // st7@5
  double v19; // st6@5
  double v20; // st5@5
  float v21; // ST1C_4@5
  float v22; // ST20_4@5
  double v23; // st6@5
  int v24; // eax@5
  signed int v25; // ebp@8
  int v26; // ebx@8
  int v27; // eax@9
  CVertex *v28; // esi@9
  double v29; // st7@9
  double v30; // st4@9
  unsigned __int8 v32; // c0@10
  unsigned __int8 v33; // c2@10
  double v34; // st7@11
  float edge; // [sp+0h] [bp-18h]@9
  float edge_4; // [sp+4h] [bp-14h]@9
  float edge_8; // [sp+8h] [bp-10h]@9
  float disp; // [sp+Ch] [bp-Ch]@9
  float disp_4; // [sp+10h] [bp-8h]@9
  float disp_8; // [sp+14h] [bp-4h]@9
  float objecta; // [sp+1Ch] [bp+4h]@3

  v3 = object;
  v4 = this->plane.N.y * object->center.y
     + this->plane.N.z * object->center.z
     + object->center.x * this->plane.N.x
     + this->plane.d;
  v5 = object->radius - 0.00019999999;
  if ( v5 >= fabs(v4) )
  {
    v7 = 0;
    objecta = v5 * v5 - v4 * v4;
    v8 = v4 * this->plane.N.z;
    v9 = v3->center.x - v4 * this->plane.N.x;
    v10 = v3->center.y - v4 * this->plane.N.y;
    v11 = v3->center.z;
    contact_pt->x = v9;
    contact_pt->y = v10;
    v12 = v11 - v8;
    contact_pt->z = v12;
    v13 = this->num_pts;
    if ( v13 <= 0 )
    {
LABEL_7:
      result = 1;
    }
    else
    {
      v14 = this->vertices;
      v15 = 4 * v13 - 4;
      while ( 1 )
      {
        v16 = *(int *)((char *)v14 + v15);
        v15 = 4 * v7;
        v17 = v14[v7];
        v18 = v17->x - *(float *)v16;
        v19 = v17->y - *(float *)(v16 + 4);
        v20 = v17->z - *(float *)(v16 + 8);
        v21 = v20 * this->plane.N.y - v19 * this->plane.N.z;
        v22 = v18 * this->plane.N.z - v20 * this->plane.N.x;
        v23 = (contact_pt->z - *(float *)(v16 + 8)) * (v19 * this->plane.N.x - v18 * this->plane.N.y)
            + (contact_pt->y - *(float *)(v16 + 4)) * v22
            + (contact_pt->x - *(float *)v16) * v21;
        v24 = this->num_pts;
        if ( v23 < 0.0 )
          break;
        ++v7;
        if ( v7 >= v24 )
          goto LABEL_7;
      }
      v25 = 0;
      v26 = 4 * v24 - 4;
      do
      {
        v27 = *(int *)((char *)v14 + v26);
        v26 = 4 * v25;
        v28 = v14[v25];
        edge = v28->x - *(float *)v27;
        edge_4 = v28->y - *(float *)(v27 + 4);
        v29 = v28->z - *(float *)(v27 + 8);
        edge_8 = v29;
        disp = contact_pt->x - *(float *)v27;
        disp_4 = contact_pt->y - *(float *)(v27 + 4);
        v30 = contact_pt->z - *(float *)(v27 + 8);
        disp_8 = v30;
        if ( v30 * (edge_4 * this->plane.N.x - edge * this->plane.N.y)
           + disp_4 * (edge * this->plane.N.z - edge_8 * this->plane.N.x)
           + disp * (v29 * this->plane.N.y - edge_4 * this->plane.N.z) < 0.0 )
        {
          if ( v32 | v33 )
            break;
          v34 = disp_8 * edge_8 + disp_4 * edge_4 + disp * edge;
          if ( v34 >= 0.0 && v34 <= edge_8 * edge_8 + edge_4 * edge_4 + edge * edge )
            goto LABEL_7;
        }
        if ( disp_8 * disp_8 + disp_4 * disp_4 + disp * disp <= objecta )
          goto LABEL_7;
        ++v25;
      }
      while ( v25 < this->num_pts );
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00538CE0) --------------------------------------------------------  // acclient.c:360136
void __thiscall CPolygon::adjust_to_placement_poly(CPolygon *this, CSphere *struck_sphere, CSphere *other_sphere, float radius, int center_solid, int solid_check)
{
  double v6; // st7@1
  double v7; // st7@2
  double v8; // st6@3
  CSphere *v9; // eax@8
  float v10; // ST04_4@8
  double v11; // rt0@8
  float v12; // ST08_4@8

  v6 = this->plane.N.y * struck_sphere->center.y
     + this->plane.N.z * struck_sphere->center.z
     + struck_sphere->center.x * this->plane.N.x
     + this->plane.d;
  if ( solid_check )
  {
    v8 = radius;
    if ( center_solid )
      v8 = v8 * -1.0;
    if ( v6 <= 0.0 )
      v8 = -v8;
    v7 = v8 - v6;
  }
  else
  {
    v7 = radius - v6;
  }
  v9 = other_sphere;
  v10 = v7 * this->plane.N.y;
  v11 = v7 * this->plane.N.x;
  v12 = v7 * this->plane.N.z;
  struck_sphere->center.x = v11 + struck_sphere->center.x;
  struck_sphere->center.y = v10 + struck_sphere->center.y;
  struck_sphere->center.z = v12 + struck_sphere->center.z;
  v9->center.x = v11 + v9->center.x;
  v9->center.y = v10 + v9->center.y;
  other_sphere->center.z = v12 + other_sphere->center.z;
}

//----- (00538D90) --------------------------------------------------------  // acclient.c:360176
int __thiscall CPolygon::point_in_polygon(CPolygon *this, AC1Legacy::Vector3 *point)
{
  int v2; // eax@1
  signed int v3; // ebx@1
  CVertex **v4; // ebp@2
  int v5; // edi@2
  int v6; // eax@3
  CVertex *v7; // edx@3
  double v8; // st7@3
  double v9; // st6@3
  double v10; // st5@3
  float norm; // ST10_4@3
  float norm_4; // ST14_4@3
  int result; // eax@5

  v2 = this->num_pts;
  v3 = 0;
  if ( v2 <= 0 )
  {
LABEL_5:
    result = 1;
  }
  else
  {
    v4 = this->vertices;
    v5 = 4 * v2 - 4;
    while ( 1 )
    {
      v6 = *(int *)((char *)v4 + v5);
      v5 = 4 * v3;
      v7 = v4[v3];
      v8 = v7->x - *(float *)v6;
      v9 = v7->y - *(float *)(v6 + 4);
      v10 = v7->z - *(float *)(v6 + 8);
      norm = v10 * this->plane.N.y - v9 * this->plane.N.z;
      norm_4 = v8 * this->plane.N.z - v10 * this->plane.N.x;
      if ( (point->z - *(float *)(v6 + 8)) * (v9 * this->plane.N.x - v8 * this->plane.N.y)
         + (point->y - *(float *)(v6 + 4)) * norm_4
         + (point->x - *(float *)v6) * norm < 0.0 )
        break;
      ++v3;
      if ( v3 >= this->num_pts )
        goto LABEL_5;
    }
    result = 0;
  }
  return result;
}

//----- (00538E60) --------------------------------------------------------  // acclient.c:360226
CSphere *__thiscall CPolygon::check_walkable(CPolygon *this, CSphere *sphere, AC1Legacy::Vector3 *up)
{
  long double v3; // st7@1
  CSphere *v5; // eax@3
  int v6; // ebp@3
  int v7; // esi@3
  double v8; // st6@3
  double v9; // st5@3
  long double v10; // st7@3
  float v11; // ST20_4@3
  float v12; // ST24_4@3
  CVertex **v13; // ebx@4
  int v14; // edi@4
  int v15; // eax@5
  CVertex *v16; // edx@5
  double v17; // st7@5
  double v18; // st4@5
  unsigned __int8 v20; // c0@6
  unsigned __int8 v21; // c2@6
  double v22; // st7@7
  float edge; // [sp+0h] [bp-24h]@5
  float edge_4; // [sp+4h] [bp-20h]@5
  float edge_8; // [sp+8h] [bp-1Ch]@5
  float disp; // [sp+Ch] [bp-18h]@5
  float disp_4; // [sp+10h] [bp-14h]@5
  float disp_8; // [sp+14h] [bp-10h]@5
  float center; // [sp+18h] [bp-Ch]@3
  float center_4; // [sp+1Ch] [bp-8h]@3
  float center_8; // [sp+20h] [bp-4h]@3
  CSphere *spherea; // [sp+28h] [bp+4h]@3
  int inside; // [sp+2Ch] [bp+8h]@3

  v3 = this->plane.N.y * up->y + this->plane.N.z * up->z + up->x * this->plane.N.x;
  if ( fabs(v3) < 0.00019999999 )
    return 0;
  v5 = sphere;
  v6 = this->num_pts;
  v7 = 0;
  v8 = this->plane.N.z * sphere->center.z + this->plane.N.y * sphere->center.y;
  v9 = sphere->center.x * this->plane.N.x;
  spherea = (CSphere *)1;
  v10 = (v8 + v9 + this->plane.d) / v3;
  v11 = v10 * up->y;
  v12 = v10 * up->z;
  center = v5->center.x - v10 * up->x;
  center_4 = v5->center.y - v11;
  center_8 = v5->center.z - v12;
  *(float *)&inside = v5->radius * v5->radius;
  if ( v6 <= 0 )
    return spherea;
  v13 = this->vertices;
  v14 = 4 * v6 - 4;
  while ( 1 )
  {
    v15 = *(int *)((char *)v13 + v14);
    v14 = 4 * v7;
    v16 = v13[v7];
    edge = v16->x - *(float *)v15;
    edge_4 = v16->y - *(float *)(v15 + 4);
    v17 = v16->z - *(float *)(v15 + 8);
    edge_8 = v17;
    disp = center - *(float *)v15;
    disp_4 = center_4 - *(float *)(v15 + 4);
    v18 = center_8 - *(float *)(v15 + 8);
    disp_8 = v18;
    if ( v18 * (edge_4 * this->plane.N.x - edge * this->plane.N.y)
       + disp_4 * (edge * this->plane.N.z - edge_8 * this->plane.N.x)
       + disp * (v17 * this->plane.N.y - edge_4 * this->plane.N.z) >= 0.0 )
      goto LABEL_11;
    if ( v20 | v21 )
      return 0;
    v22 = disp_8 * edge_8 + disp_4 * edge_4 + disp * edge;
    if ( v22 >= 0.0 && v22 <= edge_8 * edge_8 + edge_4 * edge_4 + edge * edge )
      return (CSphere *)1;
    spherea = 0;
LABEL_11:
    if ( disp_8 * disp_8 + disp_4 * disp_4 + disp * disp <= *(float *)&inside )
      return (CSphere *)1;
    ++v7;
    if ( v7 >= v6 )
      return spherea;
  }
}

//----- (005390B0) --------------------------------------------------------  // acclient.c:360311
CSphere *__thiscall CPolygon::check_small_walkable(CPolygon *this, CSphere *sphere, AC1Legacy::Vector3 *up)
{
  long double v3; // st7@1
  CSphere *v5; // eax@3
  int v6; // ebp@3
  int v7; // esi@3
  double v8; // st6@3
  double v9; // st5@3
  long double v10; // st7@3
  float v11; // ST20_4@3
  float v12; // ST24_4@3
  CVertex **v13; // ebx@4
  int v14; // edi@4
  int v15; // eax@5
  CVertex *v16; // edx@5
  double v17; // st7@5
  double v18; // st4@5
  unsigned __int8 v20; // c0@6
  unsigned __int8 v21; // c2@6
  double v22; // st7@7
  float edge; // [sp+0h] [bp-24h]@5
  float edge_4; // [sp+4h] [bp-20h]@5
  float edge_8; // [sp+8h] [bp-1Ch]@5
  float disp; // [sp+Ch] [bp-18h]@5
  float disp_4; // [sp+10h] [bp-14h]@5
  float disp_8; // [sp+14h] [bp-10h]@5
  float center; // [sp+18h] [bp-Ch]@3
  float center_4; // [sp+1Ch] [bp-8h]@3
  float center_8; // [sp+20h] [bp-4h]@3
  CSphere *spherea; // [sp+28h] [bp+4h]@3
  int inside; // [sp+2Ch] [bp+8h]@3

  v3 = this->plane.N.y * up->y + this->plane.N.z * up->z + up->x * this->plane.N.x;
  if ( fabs(v3) < 0.00019999999 )
    return 0;
  v5 = sphere;
  v6 = this->num_pts;
  v7 = 0;
  v8 = this->plane.N.z * sphere->center.z + this->plane.N.y * sphere->center.y;
  v9 = sphere->center.x * this->plane.N.x;
  spherea = (CSphere *)1;
  v10 = (v8 + v9 + this->plane.d) / v3;
  v11 = v10 * up->y;
  v12 = v10 * up->z;
  center = v5->center.x - v10 * up->x;
  center_4 = v5->center.y - v11;
  center_8 = v5->center.z - v12;
  *(float *)&inside = v5->radius * v5->radius * 0.25;
  if ( v6 <= 0 )
    return spherea;
  v13 = this->vertices;
  v14 = 4 * v6 - 4;
  while ( 1 )
  {
    v15 = *(int *)((char *)v13 + v14);
    v14 = 4 * v7;
    v16 = v13[v7];
    edge = v16->x - *(float *)v15;
    edge_4 = v16->y - *(float *)(v15 + 4);
    v17 = v16->z - *(float *)(v15 + 8);
    edge_8 = v17;
    disp = center - *(float *)v15;
    disp_4 = center_4 - *(float *)(v15 + 4);
    v18 = center_8 - *(float *)(v15 + 8);
    disp_8 = v18;
    if ( v18 * (edge_4 * this->plane.N.x - edge * this->plane.N.y)
       + disp_4 * (edge * this->plane.N.z - edge_8 * this->plane.N.x)
       + disp * (v17 * this->plane.N.y - edge_4 * this->plane.N.z) >= 0.0 )
      goto LABEL_11;
    if ( v20 | v21 )
      return 0;
    v22 = disp_8 * edge_8 + disp_4 * edge_4 + disp * edge;
    if ( v22 >= 0.0 && v22 <= edge_8 * edge_8 + edge_4 * edge_4 + edge * edge )
      return (CSphere *)1;
    spherea = 0;
LABEL_11:
    if ( disp_8 * disp_8 + disp_4 * disp_4 + disp * disp <= *(float *)&inside )
      return (CSphere *)1;
    ++v7;
    if ( v7 >= v6 )
      return spherea;
  }
}

//----- (00539300) --------------------------------------------------------  // acclient.c:360396
int __thiscall CPolygon::find_crossed_edge(CPolygon *this, CSphere *sphere, AC1Legacy::Vector3 *up, AC1Legacy::Vector3 *normal)
{
  long double v4; // st7@1
  int result; // eax@2
  int v6; // ebp@3
  int v7; // edi@3
  long double v8; // st7@3
  float v9; // ST14_4@3
  float v10; // ST18_4@3
  CVertex **v11; // ebx@4
  int v12; // esi@4
  int v13; // eax@5
  CVertex *v14; // edx@5
  double v15; // st7@5
  double v16; // st4@5
  unsigned __int8 v18; // c0@5
  unsigned __int8 v19; // c2@5
  float v20; // ST1C_4@8
  float v21; // ST20_4@8
  double v22; // st7@8
  double v23; // st6@8
  AC1Legacy::Vector3 *v24; // ecx@8
  float v25; // ST24_4@8
  long double v26; // st4@8
  float edge; // [sp+0h] [bp-18h]@5
  float edge_4; // [sp+4h] [bp-14h]@5
  float edge_8; // [sp+8h] [bp-10h]@5
  float center; // [sp+Ch] [bp-Ch]@3
  float center_4; // [sp+10h] [bp-8h]@3
  float center_8; // [sp+14h] [bp-4h]@3

  v4 = this->plane.N.y * up->y + this->plane.N.z * up->z + this->plane.N.x * up->x;
  if ( fabs(v4) >= 0.00019999999 )
  {
    v6 = this->num_pts;
    v7 = 0;
    v8 = (this->plane.N.z * sphere->center.z
        + this->plane.N.y * sphere->center.y
        + this->plane.N.x * sphere->center.x
        + this->plane.d)
       / v4;
    v9 = v8 * up->y;
    v10 = v8 * up->z;
    center = sphere->center.x - v8 * up->x;
    center_4 = sphere->center.y - v9;
    center_8 = sphere->center.z - v10;
    if ( v6 <= 0 )
    {
LABEL_7:
      result = 0;
    }
    else
    {
      v11 = this->vertices;
      v12 = 4 * v6 - 4;
      while ( 1 )
      {
        v13 = *(int *)((char *)v11 + v12);
        v12 = 4 * v7;
        v14 = v11[v7];
        edge = v14->x - *(float *)v13;
        edge_4 = v14->y - *(float *)(v13 + 4);
        v15 = v14->z - *(float *)(v13 + 8);
        edge_8 = v15;
        v16 = (center_8 - *(float *)(v13 + 8)) * (edge_4 * this->plane.N.x - edge * this->plane.N.y)
            + (center_4 - *(float *)(v13 + 4)) * (edge * this->plane.N.z - edge_8 * this->plane.N.x)
            + (center - *(float *)v13) * (v15 * this->plane.N.y - edge_4 * this->plane.N.z);
        if ( v18 | v19 )
          break;
        ++v7;
        if ( v7 >= v6 )
          goto LABEL_7;
      }
      v20 = edge_8 * this->plane.N.y - edge_4 * this->plane.N.z;
      v21 = edge * this->plane.N.z - edge_8 * this->plane.N.x;
      v22 = edge_4 * this->plane.N.x;
      v23 = edge * this->plane.N.y;
      v24 = normal;
      normal->x = v20;
      normal->y = v21;
      v25 = v22 - v23;
      normal->z = v25;
      v26 = sqrt(v24->x * v24->x + v24->y * v24->y + v24->z * v24->z);
      v24->x = 1.0 / v26 * v24->x;
      v24->y = 1.0 / v26 * v24->y;
      normal->z = 1.0 / v26 * normal->z;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005394F0) --------------------------------------------------------  // acclient.c:360493
int __thiscall CPolygon::pos_hits_sphere(CPolygon *this, CSphere *object, AC1Legacy::Vector3 *movement, AC1Legacy::Vector3 *contact_pt, CPolygon **struck_poly)
{
  int v5; // edx@1
  int v6; // ecx@1
  int result; // eax@4

  v5 = CPolygon::polygon_hits_sphere_slow_but_sure(this, object, contact_pt);
  if ( v5 )
    *struck_poly = (CPolygon *)v6;
  if ( *(float *)(v6 + 40) * movement->z + *(float *)(v6 + 36) * movement->y + *(float *)(v6 + 32) * movement->x >= 0.0 )
    result = 0;
  else
    result = v5;
  return result;
}

//----- (00539540) --------------------------------------------------------  // acclient.c:360510
int __thiscall CPolygon::hits_sphere(CPolygon *this, CSphere *object)
{
  AC1Legacy::Vector3 contact_pt; // [sp+0h] [bp-Ch]@1

  return CPolygon::polygon_hits_sphere_slow_but_sure(this, object, &contact_pt);
}

//----- (00539560) --------------------------------------------------------  // acclient.c:360518
int __thiscall CPolygon::walkable_hits_sphere(CPolygon *this, SPHEREPATH *path, CSphere *object, AC1Legacy::Vector3 *up)
{
  int result; // eax@2
  int v5; // edi@3
  CPolygon *v6; // ecx@3
  CPolygon *v7; // ecx@3
  CPolygon *v8; // ecx@4
  AC1Legacy::Vector3 contact_pt; // [sp+0h] [bp-Ch]@3

  if ( this->plane.N.z * up->z + this->plane.N.y * up->y + up->x * this->plane.N.x > path->walkable_allowance )
  {
    v5 = CPolygon::polygon_hits_sphere_slow_but_sure(this, object, &contact_pt);
    if ( v5 != CPolygon::polygon_hits_sphere(v6, object, &contact_pt) )
    {
      CPolygon::polygon_hits_sphere_slow_but_sure(v7, object, &contact_pt);
      CPolygon::polygon_hits_sphere(v8, object, &contact_pt);
    }
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005395E0) --------------------------------------------------------  // acclient.c:360545
int __thiscall CPolygon::polygon_hits_ray(CPolygon *this, Ray *line, long double *time)
{
  CPolygon *v3; // edi@1
  int result; // eax@3
  long double v5; // st7@5
  double v6; // st6@5
  long double v7; // st5@5
  double v8; // st7@5
  AC1Legacy::Vector3 inplane_point; // [sp+8h] [bp-18h]@5
  float v10; // [sp+1Ch] [bp-4h]@5

  v3 = this;
  if ( this->sides_type
    || line->dir.z * this->plane.N.z + line->dir.y * this->plane.N.y + line->dir.x * this->plane.N.x <= 0.0 )
  {
    result = Plane::compute_time_of_intersection(&this->plane, line, time);
    if ( result )
    {
      v5 = *time;
      inplane_point.x = v5 * line->dir.x;
      inplane_point.y = v5 * line->dir.y;
      v6 = inplane_point.x + line->pt.x;
      v7 = v5 * line->dir.z;
      v8 = inplane_point.y + line->pt.y;
      v10 = v7 + line->pt.z;
      inplane_point.z = v10;
      inplane_point.x = v6;
      inplane_point.y = v8;
      result = CPolygon::point_in_polygon(v3, &inplane_point);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00700130) --------------------------------------------------------  // acclient.c:788031
void sub_700130()
{
  flt_845118 = 1000.0 + 1.0;
}

//----- (00700150) --------------------------------------------------------  // acclient.c:788037
void sub_700150()
{
  flt_84511C = 24.0 * 8.0;
}

//----- (00700170) --------------------------------------------------------  // acclient.c:788043
void sub_700170()
{
  flt_845120 = 24.0 * 0.5;
}

//----- (00700190) --------------------------------------------------------  // acclient.c:788049
int sub_700190()
{
  return atexit(nullsub_1180);
}

