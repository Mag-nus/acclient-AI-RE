/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Plane
   Object     : PORTAL\geometry\Plane.obj
   Functions  : 6
   Addresses  : 005AA0A0 - 0070D9B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005AA0A0) --------------------------------------------------------  // acclient.c:467671
Plane *__cdecl Plane::localtoglobal(Plane *result, Position *to, Position *from, Plane *local_plane)
{
  double v4; // st7@1
  double v5; // st6@1
  double v6; // st5@1
  double v7; // st7@1
  float v8; // ST14_4@1
  float v9; // ST0C_4@1
  float v10; // ST10_4@1
  float v11; // ST14_4@1
  AC1Legacy::Vector3 *v12; // eax@1
  double v13; // st7@1
  double v14; // st6@1
  Plane *v15; // eax@1
  AC1Legacy::Vector3 point; // [sp+Ch] [bp-18h]@1
  AC1Legacy::Vector3 v17; // [sp+18h] [bp-Ch]@1

  v4 = -local_plane->d;
  v5 = v4 * local_plane->N.x;
  v6 = v4;
  v7 = v4 * local_plane->N.y;
  v8 = v6 * local_plane->N.z;
  point.z = v8;
  point.x = v5;
  point.y = v7;
  v9 = from->frame.m_fl2gv[6] * local_plane->N.z
     + from->frame.m_fl2gv[3] * local_plane->N.y
     + from->frame.m_fl2gv[0] * local_plane->N.x;
  v10 = from->frame.m_fl2gv[7] * local_plane->N.z
      + from->frame.m_fl2gv[4] * local_plane->N.y
      + from->frame.m_fl2gv[1] * local_plane->N.x;
  v11 = from->frame.m_fl2gv[8] * local_plane->N.z
      + from->frame.m_fl2gv[5] * local_plane->N.y
      + from->frame.m_fl2gv[2] * local_plane->N.x;
  v12 = Position::localtoglobal(to, &v17, from, &point);
  v13 = v11 * v12->z + v10 * v12->y;
  v14 = v9 * v12->x;
  v15 = result;
  result->N.x = v9;
  result->N.y = v10;
  result->N.z = v11;
  result->d = -(v13 + v14);
  return v15;
}

//----- (005AA170) --------------------------------------------------------  // acclient.c:467717
signed int __thiscall Plane::intersect_box(Plane *this, BBox *box)
{
  Plane *v2; // edi@1
  double v3; // st7@1
  signed int v4; // ebx@2
  float v5; // ecx@5
  float v6; // edx@5
  float v7; // edx@6
  float v8; // eax@6
  float v9; // ecx@7
  float v10; // eax@7
  float v11; // ecx@8
  float v12; // edx@8
  float v13; // edx@9
  float v14; // eax@9
  float v15; // ecx@10
  float v16; // eax@10
  float v17; // ecx@11
  float v18; // edx@11
  bool v19; // zf@11
  signed int result; // eax@11
  AC1Legacy::Vector3 v; // [sp+10h] [bp-Ch]@5

  v2 = this;
  v3 = box->m_vMin.z * this->N.z + box->m_vMin.y * this->N.y + box->m_vMin.x * this->N.x + this->d;
  if ( v3 <= 0.00019999999 )
  {
    if ( v3 >= -0.00019999999 )
      return 3;
    v4 = 1;
  }
  else
  {
    v4 = 0;
  }
  v5 = box->m_vMax.y;
  v6 = box->m_vMax.z;
  v.x = box->m_vMax.x;
  v.y = v5;
  v.z = v6;
  if ( v4 != Plane::which_side(v2, &v, 0.00019999999) )
    return 3;
  v7 = box->m_vMin.y;
  v8 = box->m_vMin.z;
  v.x = box->m_vMax.x;
  v.y = v7;
  v.z = v8;
  if ( v4 != Plane::which_side(v2, &v, 0.00019999999) )
    return 3;
  v9 = box->m_vMin.z;
  v10 = box->m_vMax.y;
  v.x = box->m_vMin.x;
  v.z = v9;
  v.y = v10;
  if ( v4 != Plane::which_side(v2, &v, 0.00019999999) )
    return 3;
  v11 = box->m_vMin.y;
  v12 = box->m_vMax.z;
  v.x = box->m_vMin.x;
  v.y = v11;
  v.z = v12;
  if ( v4 != Plane::which_side(v2, &v, 0.00019999999) )
    return 3;
  v13 = box->m_vMax.y;
  v14 = box->m_vMin.z;
  v.x = box->m_vMax.x;
  v.y = v13;
  v.z = v14;
  if ( v4 != Plane::which_side(v2, &v, 0.00019999999) )
    return 3;
  v15 = box->m_vMax.z;
  v16 = box->m_vMin.y;
  v.x = box->m_vMax.x;
  v.z = v15;
  v.y = v16;
  if ( v4 != Plane::which_side(v2, &v, 0.00019999999) )
    return 3;
  v17 = box->m_vMax.y;
  v18 = box->m_vMax.z;
  v.x = box->m_vMin.x;
  v.y = v17;
  v.z = v18;
  v19 = v4 == Plane::which_side(v2, &v, 0.00019999999);
  result = v4;
  if ( !v19 )
    return 3;
  return result;
}

//----- (0070D950) --------------------------------------------------------  // acclient.c:800544
void sub_70D950()
{
  flt_8EDE90 = 1000.0 + 1.0;
}

//----- (0070D970) --------------------------------------------------------  // acclient.c:800550
void sub_70D970()
{
  flt_8EDE94 = 24.0 * 8.0;
}

//----- (0070D990) --------------------------------------------------------  // acclient.c:800556
void sub_70D990()
{
  flt_8EDE98 = 24.0 * 0.5;
}

//----- (0070D9B0) --------------------------------------------------------  // acclient.c:800562
int sub_70D9B0()
{
  return atexit(nullsub_1532);
}

