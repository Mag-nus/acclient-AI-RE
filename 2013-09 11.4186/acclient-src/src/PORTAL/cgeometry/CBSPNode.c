/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CBSPNode
   Object     : PORTAL\cgeometry\CBSPNode.obj
   Functions  : 93
   Addresses  : 00487830 - 0076B070 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00487830) --------------------------------------------------------  // acclient.c:195246
char __thiscall SmartArray<UIElement_Button *,1>::AddToEnd(SmartArray<BSPNODE *,1> *this, BSPNODE *const *i_rData)
{
  SmartArray<BSPNODE *,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v2, v4)) != 0) )
  {
    v2->m_data[v2->m_num++] = *i_rData;
    result = 1;
  }
  return result;
}

//----- (0053C0B0) --------------------------------------------------------  // acclient.c:362835
void __thiscall BSPNODE::Destroy(BSPNODE *this)
{
  BSPNODE *v1; // esi@1
  BSPNODE *v2; // ecx@1
  BSPNODE *v3; // ecx@5

  v1 = this;
  v2 = this->pos_node;
  if ( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->pos_node = 0;
  }
  if ( v1->in_polys )
  {
    operator delete[](v1->in_polys);
    v1->in_polys = 0;
  }
  v3 = v1->neg_node;
  v1->num_polys = 0;
  if ( v3 )
  {
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v1->neg_node = 0;
  }
  v1->type = 589505315;
}

//----- (0053C100) --------------------------------------------------------  // acclient.c:362864
void __thiscall BSPNODE::build_draw_portals_only(BSPNODE *this, int portalPolyOrPortalContents)
{
  BSPNODE *i; // esi@1
  double v3; // st7@2
  signed int v4; // eax@3
  int v5; // eax@7
  BSPNODE *v6; // ecx@9
  int v7; // eax@10
  BSPNODE *v8; // ecx@14
  int v9; // eax@16
  BSPNODE *v10; // ecx@19
  int v11; // eax@20

  for ( i = this; ; i = v8 )
  {
    v3 = Render::FrameCurrent->z * i->splitting_plane.N.z
       + Render::FrameCurrent->y * i->splitting_plane.N.y
       + i->splitting_plane.N.x * Render::FrameCurrent->x
       + i->splitting_plane.d;
    if ( v3 <= 0.00019999999 )
    {
      v4 = 1;
      if ( v3 >= -0.00019999999 )
        v4 = 2;
    }
    else
    {
      v4 = 0;
    }
    if ( v4 )
    {
      v5 = v4 - 1;
      if ( v5 && v5 != 1 )
        return;
      v6 = i->pos_node;
      if ( v6 )
      {
        v7 = v6->type;
        if ( v7 != 1279607110 )
        {
          if ( v7 == 1347375700 )
            BSPPORTAL::portal_draw_portals_only((BSPPORTAL *)v6, portalPolyOrPortalContents);
          else
            BSPNODE::build_draw_portals_only(v6, portalPolyOrPortalContents);
        }
      }
      v8 = i->neg_node;
    }
    else
    {
      v10 = i->neg_node;
      if ( !v10 )
        goto LABEL_24;
      v11 = v10->type;
      if ( v11 == 1279607110 )
        goto LABEL_24;
      if ( v11 == 1347375700 )
      {
        BSPPORTAL::portal_draw_portals_only((BSPPORTAL *)v10, portalPolyOrPortalContents);
LABEL_24:
        v8 = i->pos_node;
        goto LABEL_15;
      }
      BSPNODE::build_draw_portals_only(v10, portalPolyOrPortalContents);
      v8 = i->pos_node;
    }
LABEL_15:
    if ( !v8 )
      return;
    v9 = v8->type;
    if ( v9 == 1279607110 )
      return;
    if ( v9 == 1347375700 )
      break;
  }
  BSPPORTAL::portal_draw_portals_only((BSPPORTAL *)v8, portalPolyOrPortalContents);
}

//----- (0053C1F0) --------------------------------------------------------  // acclient.c:362943
int __thiscall BSPNODE::point_inside_cell_bsp(BSPNODE *this, AC1Legacy::Vector3 *origin)
{
  double v2; // st7@1
  signed int v3; // eax@2
  int v4; // eax@6

  while ( 1 )
  {
    v2 = this->splitting_plane.N.y * origin->y
       + this->splitting_plane.N.z * origin->z
       + this->splitting_plane.N.x * origin->x
       + this->splitting_plane.d;
    if ( v2 <= 0.00019999999 )
    {
      v3 = 1;
      if ( v2 >= -0.00019999999 )
        v3 = 2;
    }
    else
    {
      v3 = 0;
    }
    if ( v3 )
    {
      v4 = v3 - 1;
      if ( !v4 || v4 != 1 )
        return 0;
    }
    if ( !this->pos_node )
      break;
    this = this->pos_node;
  }
  return 1;
}

//----- (0053C260) --------------------------------------------------------  // acclient.c:362979
signed int __thiscall BSPNODE::sphere_intersects_cell_bsp(BSPNODE *this, CSphere *curr_sphere)
{
  CSphere *v2; // edx@1
  double v3; // st7@1
  double v4; // st6@1
  signed int result; // eax@5
  float curr_spherea; // [sp+4h] [bp+4h]@1

  v2 = curr_sphere;
  v3 = this->splitting_plane.N.y * curr_sphere->center.y
     + this->splitting_plane.N.z * curr_sphere->center.z
     + this->splitting_plane.N.x * curr_sphere->center.x
     + this->splitting_plane.d;
  v4 = curr_sphere->radius + 0.0099999998;
  curr_spherea = v4;
  if ( v3 <= -v4 )
  {
LABEL_5:
    result = 0;
  }
  else
  {
    while ( 1 )
    {
      this = this->pos_node;
      if ( v3 < v4 )
        break;
      if ( !this )
        return 2;
      v3 = this->splitting_plane.N.y * v2->center.y
         + this->splitting_plane.N.z * v2->center.z
         + this->splitting_plane.N.x * v2->center.x
         + this->splitting_plane.d;
      v4 = curr_spherea;
      if ( v3 <= -curr_spherea )
        goto LABEL_5;
    }
    if ( this )
      result = BSPNODE::sphere_intersects_cell_bsp(this, v2) != 0;
    else
      result = 1;
  }
  return result;
}

//----- (0053C310) --------------------------------------------------------  // acclient.c:363025
int __thiscall BSPNODE::point_intersects_solid(BSPNODE *this, AC1Legacy::Vector3 *point)
{
  int result; // eax@2

  if ( this->splitting_plane.N.z * point->z
     + this->splitting_plane.N.y * point->y
     + this->splitting_plane.N.x * point->x
     + this->splitting_plane.d < 0.0 )
    result = ((int (__stdcall *)(AC1Legacy::Vector3 *))this->neg_node->vfptr->point_intersects_solid)(point);
  else
    result = ((int (__stdcall *)(AC1Legacy::Vector3 *))this->pos_node->vfptr->point_intersects_solid)(point);
  return result;
}

//----- (0053C360) --------------------------------------------------------  // acclient.c:363040
signed int __thiscall Plane::Pack(Plane *this, void **addr, unsigned int size)
{
  char *v3; // edx@3
  char *v4; // esi@3

  if ( size >= 0x10 )
  {
    if ( size >= 0xC )
    {
      *(_DWORD *)*addr = LODWORD(this->N.x);
      v3 = (char *)*addr + 4;
      *addr = v3;
      *(float *)v3 = this->N.y;
      v4 = (char *)*addr + 4;
      *addr = v4;
      *(float *)v4 = this->N.z;
      *addr = (char *)*addr + 4;
    }
    *(float *)*addr = this->d;
    *addr = (char *)*addr + 4;
  }
  return 16;
}

//----- (0053C3B0) --------------------------------------------------------  // acclient.c:363065
void __thiscall BSPNODE::BSPNODE(BSPNODE *this)
{
  this->vfptr = (BSPNODEVtbl *)&BSPNODE::vftable;
  this->type = 589505315;
  this->num_polys = 0;
  this->in_polys = 0;
  this->pos_node = 0;
  this->neg_node = 0;
}
// 7C9AF0: using guessed type int (__thiscall *BSPNODE::vftable)(void *, char);

//----- (0053C3D0) --------------------------------------------------------  // acclient.c:363077
void __thiscall BSPNODE::~BSPNODE(BSPNODE *this)
{
  BSPNODE *v1; // esi@1
  BSPNODE *v2; // ecx@1
  BSPNODE *v3; // ecx@5

  v1 = this;
  v2 = this->pos_node;
  v1->vfptr = (BSPNODEVtbl *)&BSPNODE::vftable;
  if ( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->pos_node = 0;
  }
  if ( v1->in_polys )
  {
    operator delete[](v1->in_polys);
    v1->in_polys = 0;
  }
  v3 = v1->neg_node;
  v1->num_polys = 0;
  if ( v3 )
  {
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v1->neg_node = 0;
  }
  v1->type = 589505315;
}
// 7C9AF0: using guessed type int (__thiscall *BSPNODE::vftable)(void *, char);

//----- (0053C420) --------------------------------------------------------  // acclient.c:363108
int __thiscall BSPNODE::pack_size(BSPNODE *this)
{
  BSPNODE *v1; // edi@1
  BSPNODE *v2; // eax@1
  int v3; // esi@1
  BSPNODE *v4; // eax@3
  int result; // eax@6
  void *dummy; // [sp+0h] [bp-4h]@1

  dummy = this;
  v1 = this;
  v2 = this->pos_node;
  dummy = 0;
  v3 = 16;
  if ( v2 )
    v3 = BSPNODE::PackChild(v2, &dummy, 0) + 16;
  v4 = v1->neg_node;
  if ( v4 )
    v3 += BSPNODE::PackChild(v4, &dummy, 0);
  if ( BSPNODE::pack_tree_type )
  {
    if ( BSPNODE::pack_tree_type == 1 )
      v3 += 16;
    result = v3;
  }
  else
  {
    result = v3 + 2 * v1->num_polys + 20;
  }
  return result;
}
// 84537C: using guessed type enum BSPTreeType BSPNODE::pack_tree_type;

//----- (0053C490) --------------------------------------------------------  // acclient.c:363142
int __thiscall BSPNODE::Pack(BSPNODE *this, void **addr, unsigned int size)
{
  BSPNODE *v3; // edi@1
  int v4; // ebp@1
  BSPNODE *v5; // eax@2
  BSPNODE *v6; // eax@4
  unsigned int v7; // eax@7

  v3 = this;
  v4 = BSPNODE::pack_size(this);
  if ( size < v4 )
    return v4;
  Plane::Pack(&v3->splitting_plane, addr, size);
  v5 = v3->pos_node;
  if ( v5 )
    BSPNODE::PackChild(v5, addr, size);
  v6 = v3->neg_node;
  if ( v6 )
    BSPNODE::PackChild(v6, addr, size);
  if ( BSPNODE::pack_tree_type )
  {
    if ( BSPNODE::pack_tree_type == 1 )
      Plane::Pack((Plane *)&v3->sphere, addr, size);
    return v4;
  }
  Plane::Pack((Plane *)&v3->sphere, addr, size);
  *(_DWORD *)*addr = v3->num_polys;
  *addr = (char *)*addr + 4;
  v7 = 0;
  if ( !v3->num_polys )
    return v4;
  do
  {
    *(_WORD *)*addr = v3->in_polys[v7]->poly_id;
    *addr = (char *)*addr + 2;
    ++v7;
  }
  while ( v7 < v3->num_polys );
  return v4;
}
// 84537C: using guessed type enum BSPTreeType BSPNODE::pack_tree_type;

//----- (0053C540) --------------------------------------------------------  // acclient.c:363185
int __thiscall BSPNODE::UnPack(BSPNODE *this, void **addr, unsigned int size)
{
  float *v3; // ebp@1
  BSPNODE *v4; // edi@1
  char *v5; // edx@3
  char *v6; // ecx@3
  signed int v7; // eax@5
  int v8; // eax@7
  int v9; // eax@8
  int result; // eax@11
  unsigned int v11; // eax@20
  void *v12; // eax@21
  unsigned int v13; // ecx@21
  unsigned int v14; // eax@21
  __int16 v15; // dx@22

  v3 = (float *)*addr;
  v4 = this;
  if ( size >= 0x10 )
  {
    if ( size >= 0xC )
    {
      LODWORD(this->splitting_plane.N.x) = *(_DWORD *)v3;
      v5 = (char *)*addr + 4;
      *addr = v5;
      LODWORD(this->splitting_plane.N.y) = *(_DWORD *)v5;
      v6 = (char *)*addr + 4;
      *addr = v6;
      LODWORD(v4->splitting_plane.N.z) = *(_DWORD *)v6;
      *addr = (char *)*addr + 4;
    }
    LODWORD(v4->splitting_plane.d) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  v7 = v4->type;
  if ( v7 > 1112567406 )
  {
    if ( v7 != 1114655054 && v7 != 1114664526 || BSPNODE::UnPackChild(&v4->neg_node, addr, size) )
      goto LABEL_19;
    goto LABEL_18;
  }
  if ( v7 != 1112567406 )
  {
    v8 = v7 - 1112557902;
    if ( !v8 )
      goto LABEL_10;
    v9 = v8 - 32;
    if ( v9 )
    {
      if ( v9 != 9440 )
        goto LABEL_19;
LABEL_10:
      if ( BSPNODE::UnPackChild(&v4->pos_node, addr, size) )
      {
        result = BSPNODE::UnPackChild(&v4->neg_node, addr, size);
        if ( !result )
        {
          *addr = v3;
          return result;
        }
        goto LABEL_19;
      }
LABEL_18:
      *addr = v3;
      return 0;
    }
  }
  result = BSPNODE::UnPackChild(&v4->pos_node, addr, size);
  if ( !result )
  {
    *addr = v3;
    return result;
  }
LABEL_19:
  if ( BSPNODE::pack_tree_type )
  {
    if ( BSPNODE::pack_tree_type == 1 )
      CSphere::UnPack(&v4->sphere, addr, size);
    return 1;
  }
  CSphere::UnPack(&v4->sphere, addr, size);
  v4->num_polys = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  v11 = v4->num_polys;
  if ( !v11 )
    return 1;
  v12 = operator new[](4 * v11);
  v13 = v4->num_polys;
  v4->in_polys = (CPolygon **)v12;
  v14 = 0;
  if ( !v13 )
    return 1;
  do
  {
    v15 = *(_WORD *)*addr;
    *addr = (char *)*addr + 2;
    v4->in_polys[v14++] = &BSPNODE::pack_poly[v15];
  }
  while ( v14 < v4->num_polys );
  return 1;
}
// 845378: using guessed type struct CPolygon *BSPNODE::pack_poly;
// 84537C: using guessed type enum BSPTreeType BSPNODE::pack_tree_type;

//----- (0053C6B0) --------------------------------------------------------  // acclient.c:363290
int __cdecl BSPNODE::pack_child_size(BSPNODE *node)
{
  void *v1; // ecx@0
  int v2; // eax@1
  int result; // eax@2
  void *dummy; // [sp+0h] [bp-4h]@1

  dummy = v1;
  v2 = node->type;
  dummy = 0;
  if ( v2 == 1347375700 )
  {
    result = BSPPORTAL::PackPortal((BSPPORTAL *)node, &dummy, 0) + 4;
  }
  else if ( v2 == 1279607110 )
  {
    result = BSPLEAF::PackLeaf((BSPLEAF *)node, &dummy, 0) + 4;
  }
  else
  {
    result = BSPNODE::Pack(node, &dummy, 0) + 4;
  }
  return result;
}

//----- (0053C700) --------------------------------------------------------  // acclient.c:363316
int __cdecl BSPNODE::PackChild(BSPNODE *node, void **addr, unsigned int size)
{
  int v3; // edi@1
  int v4; // edx@2

  v3 = BSPNODE::pack_child_size(node);
  if ( size >= v3 )
  {
    *(_DWORD *)*addr = node->type;
    *addr = (char *)*addr + 4;
    v4 = node->type;
    if ( v4 == 1347375700 )
    {
      BSPPORTAL::PackPortal((BSPPORTAL *)node, addr, size);
      return v3;
    }
    if ( v4 == 1279607110 )
    {
      BSPLEAF::PackLeaf((BSPLEAF *)node, addr, size);
      return v3;
    }
    BSPNODE::Pack(node, addr, size);
  }
  return v3;
}

//----- (0053C770) --------------------------------------------------------  // acclient.c:363343
int __cdecl BSPNODE::UnPackChild(BSPNODE **node, void **addr, unsigned int size)
{
  int v3; // edi@1
  BSPPORTAL *v4; // eax@2
  int v5; // esi@2
  int v6; // eax@3
  int result; // eax@4
  BSPLEAF *v8; // eax@6
  int v9; // esi@6
  int v10; // eax@7
  void *v11; // eax@9

  v3 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  if ( v3 == 1347375700 )
  {
    v4 = (BSPPORTAL *)operator new(0x40u);
    v5 = 0;
    if ( v4 )
    {
      BSPPORTAL::BSPPORTAL(v4);
      v5 = v6;
    }
    *(_DWORD *)(v5 + 36) = 1347375700;
    result = BSPPORTAL::UnPackPortal((BSPPORTAL *)v5, addr, size);
    *node = (BSPNODE *)v5;
  }
  else if ( v3 == 1279607110 )
  {
    v8 = (BSPLEAF *)operator new(0x40u);
    v9 = 0;
    if ( v8 )
    {
      BSPLEAF::BSPLEAF(v8);
      v9 = v10;
    }
    *(_DWORD *)(v9 + 36) = 1279607110;
    result = BSPLEAF::UnPackLeaf((BSPLEAF *)v9, addr, size);
    *node = (BSPNODE *)v9;
  }
  else
  {
    v11 = operator new(0x38u);
    if ( v11 )
    {
      *(_DWORD *)v11 = &BSPNODE::vftable;
      *((_DWORD *)v11 + 9) = 589505315;
      *((_DWORD *)v11 + 10) = 0;
      *((_DWORD *)v11 + 11) = 0;
      *((_DWORD *)v11 + 12) = 0;
      *((_DWORD *)v11 + 13) = 0;
    }
    else
    {
      v11 = 0;
    }
    *node = (BSPNODE *)v11;
    *((_DWORD *)v11 + 9) = v3;
    result = BSPNODE::UnPack(*node, addr, size);
  }
  return result;
}
// 7C9AF0: using guessed type int (__thiscall *BSPNODE::vftable)(void *, char);

//----- (0053C850) --------------------------------------------------------  // acclient.c:363408
void __thiscall BSPNODE::LinkPortalNodeChain(BSPNODE *this, SmartArray<BSPNODE *,1> *_Portals)
{
  unsigned int i; // eax@1
  BSPNODE *v3; // edx@2

  for ( i = _Portals->m_num - 1; (i & 0x80000000) == 0; this = v3 )
  {
    v3 = _Portals->m_data[i];
    this->pos_node = v3;
    if ( (signed int)i > 0 )
      v3->pos_node = _Portals->m_data[i - 1];
    --i;
  }
}

//----- (0053C880) --------------------------------------------------------  // acclient.c:363424
int __thiscall BSPNODE::box_intersects_cell_bsp(BSPNODE *this, BBox *box)
{
  BSPNODE *i; // ebp@1
  double v3; // st7@2
  float v4; // ecx@4
  float v5; // edx@4
  float v6; // edx@5
  float v7; // eax@5
  float v8; // ecx@6
  float v9; // eax@6
  float v10; // ecx@7
  float v11; // edx@7
  float v12; // edx@8
  float v13; // eax@8
  float v14; // ecx@9
  float v15; // eax@9
  float v16; // ecx@10
  float v17; // edx@10
  AC1Legacy::Vector3 v; // [sp+10h] [bp-54h]@4
  AC1Legacy::Vector3 v20; // [sp+1Ch] [bp-48h]@5
  AC1Legacy::Vector3 v21; // [sp+28h] [bp-3Ch]@6
  AC1Legacy::Vector3 v22; // [sp+34h] [bp-30h]@7
  AC1Legacy::Vector3 v23; // [sp+40h] [bp-24h]@8
  AC1Legacy::Vector3 v24; // [sp+4Ch] [bp-18h]@9
  AC1Legacy::Vector3 v25; // [sp+58h] [bp-Ch]@10

  for ( i = this; ; i = i->pos_node )
  {
    v3 = box->m_vMin.z * i->splitting_plane.N.z
       + box->m_vMin.y * i->splitting_plane.N.y
       + box->m_vMin.x * i->splitting_plane.N.x
       + i->splitting_plane.d;
    if ( v3 <= 0.00019999999 && v3 < -0.00019999999 )
    {
      v4 = box->m_vMax.y;
      v5 = box->m_vMax.z;
      v.x = box->m_vMax.x;
      v.y = v4;
      v.z = v5;
      if ( Plane::which_side(&i->splitting_plane, &v, 0.00019999999) == 1 )
      {
        v6 = box->m_vMin.y;
        v7 = box->m_vMax.z;
        v20.x = box->m_vMin.x;
        v20.y = v6;
        v20.z = v7;
        if ( Plane::which_side(&i->splitting_plane, &v20, 0.00019999999) == 1 )
        {
          v8 = box->m_vMin.z;
          v9 = box->m_vMax.y;
          v21.x = box->m_vMin.x;
          v21.z = v8;
          v21.y = v9;
          if ( Plane::which_side(&i->splitting_plane, &v21, 0.00019999999) == 1 )
          {
            v10 = box->m_vMin.y;
            v11 = box->m_vMin.z;
            v22.x = box->m_vMax.x;
            v22.y = v10;
            v22.z = v11;
            if ( Plane::which_side(&i->splitting_plane, &v22, 0.00019999999) == 1 )
            {
              v12 = box->m_vMin.y;
              v13 = box->m_vMax.z;
              v23.x = box->m_vMax.x;
              v23.y = v12;
              v23.z = v13;
              if ( Plane::which_side(&i->splitting_plane, &v23, 0.00019999999) == 1 )
              {
                v14 = box->m_vMax.z;
                v15 = box->m_vMax.y;
                v24.x = box->m_vMin.x;
                v24.z = v14;
                v24.y = v15;
                if ( Plane::which_side(&i->splitting_plane, &v24, 0.00019999999) == 1 )
                {
                  v16 = box->m_vMax.y;
                  v17 = box->m_vMin.z;
                  v25.x = box->m_vMax.x;
                  v25.y = v16;
                  v25.z = v17;
                  if ( Plane::which_side(&i->splitting_plane, &v25, 0.00019999999) == 1 )
                    return 0;
                }
              }
            }
          }
        }
      }
    }
    if ( !i->pos_node )
      break;
  }
  return 1;
}

//----- (0053CA30) --------------------------------------------------------  // acclient.c:363521
int __thiscall BSPNODE::sphere_intersects_poly(BSPNODE *this, CSphere *check_pos, AC1Legacy::Vector3 *movement, CPolygon **polygon, AC1Legacy::Vector3 *contact_pt)
{
  BSPNODE *v5; // esi@1
  int result; // eax@1
  double v7; // st7@2
  double v8; // st6@2
  BSPNODE *v9; // ecx@3

  v5 = this;
  result = CSphere::intersects(&this->sphere, check_pos);
  if ( result )
  {
    v7 = v5->splitting_plane.N.z * check_pos->center.z
       + v5->splitting_plane.N.y * check_pos->center.y
       + check_pos->center.x * v5->splitting_plane.N.x
       + v5->splitting_plane.d;
    v8 = check_pos->radius - 0.00019999999;
    if ( v7 >= v8 )
    {
      v9 = v5->pos_node;
      return ((int (__stdcall *)(CSphere *, AC1Legacy::Vector3 *, CPolygon **, AC1Legacy::Vector3 *))v9->vfptr->sphere_intersects_poly)(
               check_pos,
               movement,
               polygon,
               contact_pt);
    }
    if ( v7 <= -v8 )
    {
      v9 = v5->neg_node;
      return ((int (__stdcall *)(CSphere *, AC1Legacy::Vector3 *, CPolygon **, AC1Legacy::Vector3 *))v9->vfptr->sphere_intersects_poly)(
               check_pos,
               movement,
               polygon,
               contact_pt);
    }
    if ( ((int (__stdcall *)(CSphere *, AC1Legacy::Vector3 *, CPolygon **, AC1Legacy::Vector3 *))v5->pos_node->vfptr->sphere_intersects_poly)(
           check_pos,
           movement,
           polygon,
           contact_pt) )
      result = 1;
    else
      result = ((int (__stdcall *)(CSphere *, AC1Legacy::Vector3 *, CPolygon **, AC1Legacy::Vector3 *))v5->neg_node->vfptr->sphere_intersects_poly)(
                 check_pos,
                 movement,
                 polygon,
                 contact_pt);
  }
  return result;
}

//----- (0053CAF0) --------------------------------------------------------  // acclient.c:363573
int __thiscall BSPNODE::sphere_intersects_solid(BSPNODE *this, CSphere *check_pos, int center_check)
{
  BSPNODE *v3; // esi@1
  int result; // eax@1
  double v5; // st7@2
  double v6; // st6@2
  BSPNODE *v7; // ecx@6

  v3 = this;
  result = CSphere::intersects(&this->sphere, check_pos);
  if ( result )
  {
    v5 = v3->splitting_plane.N.z * check_pos->center.z
       + v3->splitting_plane.N.y * check_pos->center.y
       + v3->splitting_plane.N.x * check_pos->center.x
       + v3->splitting_plane.d;
    v6 = check_pos->radius - 0.00019999999;
    if ( v5 >= v6 )
      return ((int (__stdcall *)(CSphere *, int))v3->pos_node->vfptr->sphere_intersects_solid)(check_pos, center_check);
    if ( v5 <= -v6 )
      return ((int (__stdcall *)(CSphere *, int))v3->neg_node->vfptr->sphere_intersects_solid)(check_pos, center_check);
    v7 = v3->pos_node;
    if ( v5 < 0.0 )
    {
      if ( ((int (__stdcall *)(CSphere *, _DWORD))v7->vfptr->sphere_intersects_solid)(check_pos, 0) )
        return 1;
      result = ((int (__stdcall *)(CSphere *, int))v3->neg_node->vfptr->sphere_intersects_solid)(
                 check_pos,
                 center_check);
    }
    else
    {
      if ( ((int (__stdcall *)(CSphere *, int))v7->vfptr->sphere_intersects_solid)(check_pos, center_check) )
        return 1;
      result = ((int (__stdcall *)(CSphere *, _DWORD))v3->neg_node->vfptr->sphere_intersects_solid)(check_pos, 0);
    }
  }
  return result;
}

//----- (0053CBD0) --------------------------------------------------------  // acclient.c:363614
int __thiscall BSPNODE::hits_walkable(BSPNODE *this, SPHEREPATH *path, CSphere *valid_pos, AC1Legacy::Vector3 *up)
{
  BSPNODE *v4; // esi@1
  int result; // eax@1
  double v6; // st7@2
  double v7; // st6@2
  BSPNODE *v8; // ecx@3

  v4 = this;
  result = CSphere::intersects(&this->sphere, valid_pos);
  if ( result )
  {
    v6 = v4->splitting_plane.N.z * valid_pos->center.z
       + v4->splitting_plane.N.y * valid_pos->center.y
       + valid_pos->center.x * v4->splitting_plane.N.x
       + v4->splitting_plane.d;
    v7 = valid_pos->radius - 0.00019999999;
    if ( v6 >= v7 )
    {
      v8 = v4->pos_node;
      return ((int (__stdcall *)(SPHEREPATH *, CSphere *, AC1Legacy::Vector3 *))v8->vfptr->hits_walkable)(
               path,
               valid_pos,
               up);
    }
    if ( v6 <= -v7 )
    {
      v8 = v4->neg_node;
      return ((int (__stdcall *)(SPHEREPATH *, CSphere *, AC1Legacy::Vector3 *))v8->vfptr->hits_walkable)(
               path,
               valid_pos,
               up);
    }
    if ( ((int (__stdcall *)(SPHEREPATH *, CSphere *, AC1Legacy::Vector3 *))v4->pos_node->vfptr->hits_walkable)(
           path,
           valid_pos,
           up) )
      result = 1;
    else
      result = ((int (__stdcall *)(SPHEREPATH *, CSphere *, AC1Legacy::Vector3 *))v4->neg_node->vfptr->hits_walkable)(
                 path,
                 valid_pos,
                 up);
  }
  return result;
}

//----- (0053CC80) --------------------------------------------------------  // acclient.c:363662
void __thiscall BSPNODE::find_walkable(BSPNODE *this, SPHEREPATH *path, CSphere *valid_pos, CPolygon **polygon, AC1Legacy::Vector3 *movement, AC1Legacy::Vector3 *up, int *changed)
{
  BSPNODE *v7; // esi@1
  double v8; // st7@2
  double v9; // st6@2
  BSPNODE *v10; // ecx@3

  v7 = this;
  if ( CSphere::intersects(&this->sphere, valid_pos) )
  {
    v8 = v7->splitting_plane.N.z * valid_pos->center.z
       + v7->splitting_plane.N.y * valid_pos->center.y
       + valid_pos->center.x * v7->splitting_plane.N.x
       + v7->splitting_plane.d;
    v9 = valid_pos->radius - 0.00019999999;
    if ( v8 >= v9 )
    {
      v10 = v7->pos_node;
LABEL_4:
      ((void (__stdcall *)(SPHEREPATH *, CSphere *, CPolygon **, AC1Legacy::Vector3 *, AC1Legacy::Vector3 *, int *))v10->vfptr->find_walkable)(
        path,
        valid_pos,
        polygon,
        movement,
        up,
        changed);
      return;
    }
    if ( v8 <= -v9 )
    {
      v10 = v7->neg_node;
      goto LABEL_4;
    }
    ((void (__stdcall *)(SPHEREPATH *, CSphere *, CPolygon **, AC1Legacy::Vector3 *, AC1Legacy::Vector3 *, int *))v7->pos_node->vfptr->find_walkable)(
      path,
      valid_pos,
      polygon,
      movement,
      up,
      changed);
    ((void (__stdcall *)(SPHEREPATH *, CSphere *, CPolygon **, AC1Legacy::Vector3 *, AC1Legacy::Vector3 *, int *))v7->neg_node->vfptr->find_walkable)(
      path,
      valid_pos,
      polygon,
      movement,
      up,
      changed);
  }
}

//----- (0053CD50) --------------------------------------------------------  // acclient.c:363713
int __thiscall BSPNODE::sphere_intersects_solid_poly(BSPNODE *this, CSphere *check_pos, float radius, int *center_solid, CPolygon **hit_poly, int center_check)
{
  BSPNODE *v6; // esi@1
  int result; // eax@1
  double v8; // st7@2
  double v9; // st6@2
  BSPNODE *v10; // ecx@3

  v6 = this;
  result = CSphere::intersects(&this->sphere, check_pos);
  if ( result )
  {
    v8 = v6->splitting_plane.N.z * check_pos->center.z
       + v6->splitting_plane.N.y * check_pos->center.y
       + check_pos->center.x * v6->splitting_plane.N.x
       + v6->splitting_plane.d;
    v9 = radius - 0.00019999999;
    if ( v8 >= v9 )
    {
      v10 = v6->pos_node;
      return ((int (__stdcall *)(CSphere *, _DWORD, int *, CPolygon **, int))v10->vfptr->sphere_intersects_solid_poly)(
               check_pos,
               LODWORD(radius),
               center_solid,
               hit_poly,
               center_check);
    }
    if ( v8 <= -v9 )
    {
      v10 = v6->neg_node;
      return ((int (__stdcall *)(CSphere *, _DWORD, int *, CPolygon **, int))v10->vfptr->sphere_intersects_solid_poly)(
               check_pos,
               LODWORD(radius),
               center_solid,
               hit_poly,
               center_check);
    }
    if ( v8 < 0.0 )
    {
      ((void (__stdcall *)(CSphere *, _DWORD, int *, CPolygon **, int))v6->neg_node->vfptr->sphere_intersects_solid_poly)(
        check_pos,
        LODWORD(radius),
        center_solid,
        hit_poly,
        center_check);
      if ( !*hit_poly )
        return ((int (__stdcall *)(CSphere *, _DWORD, int *, CPolygon **, _DWORD))v6->pos_node->vfptr->sphere_intersects_solid_poly)(
                 check_pos,
                 LODWORD(radius),
                 center_solid,
                 hit_poly,
                 0);
    }
    else
    {
      ((void (__stdcall *)(CSphere *, _DWORD, int *, CPolygon **, int))v6->pos_node->vfptr->sphere_intersects_solid_poly)(
        check_pos,
        LODWORD(radius),
        center_solid,
        hit_poly,
        center_check);
      if ( !*hit_poly )
        return ((int (__stdcall *)(CSphere *, _DWORD, int *, CPolygon **, _DWORD))v6->neg_node->vfptr->sphere_intersects_solid_poly)(
                 check_pos,
                 LODWORD(radius),
                 center_solid,
                 hit_poly,
                 0);
    }
    result = *center_solid;
  }
  return result;
}

//----- (0053CE50) --------------------------------------------------------  // acclient.c:363788
int __thiscall BSPNODE::TraceRay(BSPNODE *this, Ray *_Ray, float *_fDelta, Vector3 *_vImpactNormal)
{
  double v4; // st7@1
  double v5; // st6@1
  double v6; // st6@1
  double v7; // st5@1
  float v8; // eax@1
  double v9; // rt0@1
  char *v10; // esi@1
  double v11; // st6@1
  signed int v12; // edi@1
  double v13; // st7@1
  Sidedness v14; // ebx@2
  double v15; // st7@6
  BSPNODE *v16; // ebp@10
  int result; // eax@13
  BSPNODE *v18; // eax@14
  BSPNODE *v19; // ebx@19
  double v20; // st7@21
  double v21; // st6@21
  double v22; // st7@21
  double v23; // st6@21
  double v24; // st7@21
  long double v25; // st6@21
  float v26; // edx@28
  double v27; // st7@28
  float v28; // eax@28
  float v29; // ecx@35
  double v30; // st7@35
  float v31; // edx@35
  float fSubDelta; // [sp+Ch] [bp-6Ch]@21
  Sidedness sideStart; // [sp+10h] [bp-68h]@2
  Vector3 vStart; // [sp+14h] [bp-64h]@1
  float v35; // [sp+20h] [bp-58h]@1
  float v36; // [sp+24h] [bp-54h]@1
  float v37; // [sp+28h] [bp-50h]@1
  float v38; // [sp+2Ch] [bp-4Ch]@23
  float v39; // [sp+30h] [bp-48h]@1
  float v40; // [sp+34h] [bp-44h]@1
  Vector3 _offset; // [sp+38h] [bp-40h]@23
  Vector3 vMid; // [sp+44h] [bp-34h]@23
  float v43; // [sp+58h] [bp-20h]@23
  Ray newRay; // [sp+5Ch] [bp-1Ch]@21
  float _Raya; // [sp+7Ch] [bp+4h]@21

  v4 = _Ray->length;
  v5 = _Ray->length;
  vStart.x = _Ray->pt.x;
  v6 = v5 * _Ray->dir.x;
  v7 = v4 * _Ray->dir.y;
  vStart.y = _Ray->pt.y;
  v8 = _Ray->pt.z;
  v39 = v7;
  v9 = v6;
  v10 = (char *)&this->splitting_plane;
  v11 = v4 * _Ray->dir.z;
  vStart.z = v8;
  v12 = 2;
  v40 = v11;
  v35 = v9 + _Ray->pt.x;
  v36 = v39 + _Ray->pt.y;
  v37 = v40 + _Ray->pt.z;
  v13 = v8 * this->splitting_plane.N.z
      + vStart.y * this->splitting_plane.N.y
      + vStart.x * this->splitting_plane.N.x
      + this->splitting_plane.d;
  if ( v13 <= 0.1 )
  {
    sideStart = 1;
    if ( v13 >= -0.1 )
      sideStart = 2;
    v14 = sideStart;
  }
  else
  {
    v14 = 0;
    sideStart = 0;
  }
  v15 = v37 * this->splitting_plane.N.z
      + v36 * this->splitting_plane.N.y
      + v35 * *(float *)v10
      + this->splitting_plane.d;
  if ( v15 <= 0.1 )
  {
    if ( v15 < -0.1 )
      v12 = 1;
  }
  else
  {
    v12 = 0;
  }
  v16 = this->pos_node;
  if ( v16 && v14 != 1 && v12 != 1 )
    return v16->vfptr->TraceRay(v16, _Ray, _fDelta, _vImpactNormal);
  v18 = this->neg_node;
  if ( v18 && v14 && v12 )
    return v18->vfptr->TraceRay(v18, _Ray, _fDelta, _vImpactNormal);
  if ( v14 == 1 )
  {
    v19 = this->neg_node;
  }
  else
  {
    v19 = this->pos_node;
    v16 = this->neg_node;
  }
  v20 = vStart.z * this->splitting_plane.N.z;
  v21 = vStart.y * this->splitting_plane.N.y;
  newRay.pt.y = stru_84538C.y;
  newRay.dir.y = stru_84538C.y;
  LODWORD(newRay.pt.x) = (_DWORD)stru_84538C.x;
  v22 = v20 + v21;
  LODWORD(newRay.dir.x) = (_DWORD)stru_84538C.x;
  v23 = vStart.x * *(float *)v10;
  newRay.pt.z = stru_84538C.z;
  newRay.dir.z = stru_84538C.z;
  LODWORD(newRay.length) = 1176256512;
  fSubDelta = 0.0;
  _Raya = 0.0;
  v24 = v22 + v23 + this->splitting_plane.d;
  v25 = v24
      - (v37 * this->splitting_plane.N.z
       + v36 * this->splitting_plane.N.y
       + v35 * this->splitting_plane.N.x
       + this->splitting_plane.d);
  if ( fabs(v25) > 0.00019999999 )
    _Raya = v24 / v25;
  _offset.x = (v35 - vStart.x) * _Raya;
  v38 = _offset.x + vStart.x;
  vMid = *(Vector3 *)&v38;
  v39 = (v36 - vStart.y) * _Raya + vStart.y;
  v40 = vMid.z * _Raya + vStart.z;
  v43 = v40 - vStart.z;
  _offset.z = v43;
  _offset.x = v38 - vStart.x;
  _offset.y = v39 - vStart.y;
  Ray::InitFromOffset(&newRay, &vStart, &_offset);
  if ( v19 && v19->vfptr->TraceRay(v19, &newRay, &fSubDelta, _vImpactNormal) == 1 )
  {
    *_fDelta = _Raya * fSubDelta;
    if ( fabs(fSubDelta) <= 0.00019999999 )
    {
      if ( sideStart != 1 )
      {
        LODWORD(_vImpactNormal->x) = *(_DWORD *)v10;
        LODWORD(_vImpactNormal->y) = *((_DWORD *)v10 + 1);
        LODWORD(_vImpactNormal->z) = *((_DWORD *)v10 + 2);
        return 1;
      }
      v38 = -*(float *)v10;
      v39 = -*((float *)v10 + 1);
      v26 = v39;
      v27 = -*((float *)v10 + 2);
      _vImpactNormal->x = v38;
      v40 = v27;
      v28 = v40;
      _vImpactNormal->y = v26;
      _vImpactNormal->z = v28;
    }
    result = 1;
  }
  else
  {
    v43 = v37 - v40;
    _offset.z = v43;
    _offset.x = v35 - v38;
    _offset.y = v36 - v39;
    Ray::InitFromOffset(&newRay, &vMid, &_offset);
    if ( v16 && v16->vfptr->TraceRay(v16, &newRay, &fSubDelta, _vImpactNormal) == 1 )
    {
      *_fDelta = (1.0 - _Raya) * fSubDelta + _Raya;
      if ( fabs(fSubDelta) <= 0.00019999999 )
      {
        if ( sideStart != 1 )
        {
          LODWORD(_vImpactNormal->x) = *(_DWORD *)v10;
          LODWORD(_vImpactNormal->y) = *((_DWORD *)v10 + 1);
          LODWORD(_vImpactNormal->z) = *((_DWORD *)v10 + 2);
          return 1;
        }
        v38 = -*(float *)v10;
        v39 = -*((float *)v10 + 1);
        v29 = v39;
        v30 = -*((float *)v10 + 2);
        _vImpactNormal->x = v38;
        v40 = v30;
        v31 = v40;
        _vImpactNormal->y = v29;
        _vImpactNormal->z = v31;
      }
      result = 1;
    }
    else
    {
      *(_DWORD *)_fDelta = 1065353216;
      result = 0;
    }
  }
  return result;
}

//----- (0053D2E0) --------------------------------------------------------  // acclient.c:363990
BSPNODE *__thiscall BSPNODE::vector_deleting_destructor(BSPNODE *this, unsigned int a2)
{
  BSPNODE *v2; // esi@1
  BSPNODE *v3; // ecx@1
  BSPNODE *v4; // ecx@5

  v2 = this;
  v3 = this->pos_node;
  v2->vfptr = (BSPNODEVtbl *)&BSPNODE::vftable;
  if ( v3 )
  {
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v2->pos_node = 0;
  }
  if ( v2->in_polys )
  {
    operator delete[](v2->in_polys);
    v2->in_polys = 0;
  }
  v4 = v2->neg_node;
  v2->num_polys = 0;
  if ( v4 )
  {
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v2->neg_node = 0;
  }
  v2->type = 589505315;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9AF0: using guessed type int (__thiscall *BSPNODE::vftable)(void *, char);

//----- (0053D340) --------------------------------------------------------  // acclient.c:364024
void __thiscall BSPNODE::DetachPortalsAndPurgeNodes(BSPNODE *this, SmartArray<BSPNODE *,1> *io_PortalsToKeep)
{
  BSPNODE *v2; // edi@1
  BSPNODE *v3; // ecx@1
  int v4; // esi@1
  int v5; // ecx@2
  BSPNODE *v6; // ecx@7
  int v7; // esi@7
  int v8; // ecx@8

  v2 = this;
  v3 = this->pos_node;
  v4 = (int)&v2->pos_node;
  if ( v3 )
  {
    BSPNODE::DetachPortalsAndPurgeNodes(v3, io_PortalsToKeep);
    v5 = *(_DWORD *)v4;
    if ( *(_DWORD *)(*(_DWORD *)v4 + 36) == 1347375700 )
    {
      SmartArray<UIElement_Button *,1>::AddToEnd(io_PortalsToKeep, &v2->pos_node);
    }
    else if ( v5 )
    {
      (**(void (__stdcall ***)(_DWORD))v5)(1);
    }
    *(_DWORD *)v4 = 0;
  }
  v6 = v2->neg_node;
  v7 = (int)&v2->neg_node;
  if ( v6 )
  {
    BSPNODE::DetachPortalsAndPurgeNodes(v6, io_PortalsToKeep);
    v8 = *(_DWORD *)v7;
    if ( *(_DWORD *)(*(_DWORD *)v7 + 36) == 1347375700 )
    {
      SmartArray<UIElement_Button *,1>::AddToEnd(io_PortalsToKeep, &v2->neg_node);
    }
    else if ( v8 )
    {
      (**(void (__stdcall ***)(_DWORD))v8)(1);
      *(_DWORD *)v7 = 0;
      return;
    }
    *(_DWORD *)v7 = 0;
  }
}

//----- (00700AB0) --------------------------------------------------------  // acclient.c:788534
void _E89_4()
{
  PixelFormatDesc::PixelFormatDesc(&stru_845398, PFID_A8R8G8B8);
}

//----- (00700AC0) --------------------------------------------------------  // acclient.c:788540
void sub_700AC0()
{
  LODWORD(dword_8453D0) = 1053364187;
}

//----- (00700AD0) --------------------------------------------------------  // acclient.c:788546
void sub_700AD0()
{
  flt_8453D4 = 1000.0 + 1.0;
}

//----- (00700AF0) --------------------------------------------------------  // acclient.c:788552
void sub_700AF0()
{
  flt_8453D8 = 24.0 * 8.0;
}

//----- (00700B10) --------------------------------------------------------  // acclient.c:788558
void sub_700B10()
{
  flt_8453DC = 24.0 * 0.5;
}

//----- (00700B30) --------------------------------------------------------  // acclient.c:788564
int _E99_34()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_30, "Render.TextureFiltering");
  return atexit(sub_76AA70);
}

//----- (00700B50) --------------------------------------------------------  // acclient.c:788571
int _E102_23()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_30, "Render.LandscapeDetailTextures");
  return atexit(sub_76AAA0);
}

//----- (00700B70) --------------------------------------------------------  // acclient.c:788578
int _E105_39()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_30, "Render.BuildingDetailTextures");
  return atexit(sub_76AAD0);
}

//----- (00700B90) --------------------------------------------------------  // acclient.c:788585
int _E108_78()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_30, "Render.FieldOfView");
  return atexit(sub_76AB00);
}

//----- (00700BB0) --------------------------------------------------------  // acclient.c:788592
int _E111_42()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_30, "Render.LandscapeTextureDetail");
  return atexit(sub_76AB30);
}

//----- (00700BD0) --------------------------------------------------------  // acclient.c:788599
int _E114_52()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_30, "Render.EnvironmentTextureDetail");
  return atexit(sub_76AB60);
}

//----- (00700BF0) --------------------------------------------------------  // acclient.c:788606
int _E117_60()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_30, "Render.SceneryDrawDistance");
  return atexit(sub_76AB90);
}

//----- (00700C10) --------------------------------------------------------  // acclient.c:788613
int _E120_58()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_30, "Render.LandscapeDrawDistance");
  return atexit(sub_76ABC0);
}

//----- (00700C30) --------------------------------------------------------  // acclient.c:788620
int _E123_36()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_30, "Render.ScreenBrightness");
  return atexit(sub_76ABF0);
}

//----- (00700C50) --------------------------------------------------------  // acclient.c:788627
int _E126_42()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_30, "Render.AspectRatio");
  return atexit(sub_76AC20);
}

//----- (00700C70) --------------------------------------------------------  // acclient.c:788634
int _E129_34()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_30, "Render.DisplayAdapter");
  return atexit(sub_76AC50);
}

//----- (00700C90) --------------------------------------------------------  // acclient.c:788641
int _E132_37()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_30, "Render.MaxHardwareClass");
  return atexit(_E133_96);
}

//----- (00700CB0) --------------------------------------------------------  // acclient.c:788648
int _E135_40()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_30, "Render.AutomaticDegrades");
  return atexit(_E136_79);
}

//----- (00700CD0) --------------------------------------------------------  // acclient.c:788655
int _E138_32()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_30, "Render.GraphicsPerformance");
  return atexit(_E139_79);
}

//----- (00700CF0) --------------------------------------------------------  // acclient.c:788662
int _E141_32()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_30, "Render.DegradeDistance");
  return atexit(_E142_74);
}

//----- (00700D10) --------------------------------------------------------  // acclient.c:788669
int _E144_31()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_30, "Render.MultiPassAlpha");
  return atexit(_E145_76);
}

//----- (00700D30) --------------------------------------------------------  // acclient.c:788676
int _E147_29()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_30, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_845428, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_84542C, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_845430, "Anisotropic");
  return atexit(_E148_72);
}

//----- (00700D80) --------------------------------------------------------  // acclient.c:788686
int _E150_29()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_30, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_845438, "Low");
  PStringBase<char>::PStringBase<char>(&stru_84543C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_845440, "High");
  PStringBase<char>::PStringBase<char>(&stru_845444, "VeryHigh");
  return atexit(_E151_70);
}

//----- (00700DE0) --------------------------------------------------------  // acclient.c:788697
int _E153_27()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_30, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_84544C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_845450, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_845454, "High");
  PStringBase<char>::PStringBase<char>(&stru_845458, "VeryHigh");
  return atexit(_E154_71);
}

//----- (00700E40) --------------------------------------------------------  // acclient.c:788708
int _E156_29()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_30, "Low");
  PStringBase<char>::PStringBase<char>(&stru_845460, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_845464, "High");
  return atexit(_E157_67);
}

//----- (00700E80) --------------------------------------------------------  // acclient.c:788717
int _E159_27()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_30, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_84546C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_845470, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_845474, "High");
  PStringBase<char>::PStringBase<char>(&stru_845478, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_84547C, "Extreme");
  return atexit(_E160_70);
}

//----- (00700EF0) --------------------------------------------------------  // acclient.c:788729
int _E162_29()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_30, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_845484, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_845488, "Wide");
  return atexit(_E163_63);
}

//----- (00700F30) --------------------------------------------------------  // acclient.c:788738
int _E165_25()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_54, "None");
  return atexit(_E166_65);
}

//----- (00700F50) --------------------------------------------------------  // acclient.c:788745
int _E168_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_54, "Speed");
  return atexit(_E169_64);
}

//----- (00700F70) --------------------------------------------------------  // acclient.c:788752
int _E171_25()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_54, "Noise");
  return atexit(_E172_62);
}

//----- (00700F90) --------------------------------------------------------  // acclient.c:788759
int _E174_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_54, "Sine");
  return atexit(_E175_59);
}

//----- (00700FB0) --------------------------------------------------------  // acclient.c:788766
int _E177_24()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_54, "Square");
  return atexit(_E178_59);
}

//----- (00700FD0) --------------------------------------------------------  // acclient.c:788773
int _E180_24()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_54, "Bounce");
  return atexit(_E181_59);
}

//----- (00700FF0) --------------------------------------------------------  // acclient.c:788780
int _E183_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_54, "Perlin");
  return atexit(_E184_56);
}

//----- (00701010) --------------------------------------------------------  // acclient.c:788787
int _E186_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_54, "Fractal");
  return atexit(_E187_55);
}

//----- (00701030) --------------------------------------------------------  // acclient.c:788794
int _E189_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_54, "FrameLoop");
  return atexit(_E190_56);
}

//----- (00701050) --------------------------------------------------------  // acclient.c:788801
int sub_701050()
{
  return atexit(nullsub_1177);
}

//----- (0076AA70) --------------------------------------------------------  // acclient.c:897749
void __cdecl sub_76AA70()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AAA0) --------------------------------------------------------  // acclient.c:897762
void __cdecl sub_76AAA0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AAD0) --------------------------------------------------------  // acclient.c:897775
void __cdecl sub_76AAD0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AB00) --------------------------------------------------------  // acclient.c:897788
void __cdecl sub_76AB00()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AB30) --------------------------------------------------------  // acclient.c:897801
void __cdecl sub_76AB30()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AB60) --------------------------------------------------------  // acclient.c:897814
void __cdecl sub_76AB60()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AB90) --------------------------------------------------------  // acclient.c:897827
void __cdecl sub_76AB90()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076ABC0) --------------------------------------------------------  // acclient.c:897840
void __cdecl sub_76ABC0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076ABF0) --------------------------------------------------------  // acclient.c:897853
void __cdecl sub_76ABF0()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AC20) --------------------------------------------------------  // acclient.c:897866
void __cdecl sub_76AC20()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AC50) --------------------------------------------------------  // acclient.c:897879
void __cdecl sub_76AC50()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AC80) --------------------------------------------------------  // acclient.c:897892
void __cdecl _E133_96()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076ACB0) --------------------------------------------------------  // acclient.c:897905
void __cdecl _E136_79()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076ACE0) --------------------------------------------------------  // acclient.c:897918
void __cdecl _E139_79()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AD10) --------------------------------------------------------  // acclient.c:897931
void __cdecl _E142_74()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AD40) --------------------------------------------------------  // acclient.c:897944
void __cdecl _E145_76()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AD70) --------------------------------------------------------  // acclient.c:897957
void __cdecl _E148_72()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_30;
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

//----- (0076ADB0) --------------------------------------------------------  // acclient.c:897982
void __cdecl _E151_70()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_30;
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

//----- (0076ADF0) --------------------------------------------------------  // acclient.c:898007
void __cdecl _E154_71()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_30;
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

//----- (0076AE30) --------------------------------------------------------  // acclient.c:898032
void __cdecl _E157_67()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_30;
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

//----- (0076AE70) --------------------------------------------------------  // acclient.c:898057
void __cdecl _E160_70()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_30;
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

//----- (0076AEB0) --------------------------------------------------------  // acclient.c:898082
void __cdecl _E163_63()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_54;
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

//----- (0076AEF0) --------------------------------------------------------  // acclient.c:898107
void __cdecl _E166_65()
{
  char *v0; // esi@1

  v0 = &waveform_None_54.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_54.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AF20) --------------------------------------------------------  // acclient.c:898120
void __cdecl _E169_64()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_54.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_54.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AF50) --------------------------------------------------------  // acclient.c:898133
void __cdecl _E172_62()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_54.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_54.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AF80) --------------------------------------------------------  // acclient.c:898146
void __cdecl _E175_59()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_54.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_54.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AFB0) --------------------------------------------------------  // acclient.c:898159
void __cdecl _E178_59()
{
  char *v0; // esi@1

  v0 = &waveform_Square_54.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_54.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076AFE0) --------------------------------------------------------  // acclient.c:898172
void __cdecl _E181_59()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_54.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_54.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B010) --------------------------------------------------------  // acclient.c:898185
void __cdecl _E184_56()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_54.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_54.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B040) --------------------------------------------------------  // acclient.c:898198
void __cdecl _E187_55()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_54.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_54.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B070) --------------------------------------------------------  // acclient.c:898211
void __cdecl _E190_56()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_54.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_54.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

