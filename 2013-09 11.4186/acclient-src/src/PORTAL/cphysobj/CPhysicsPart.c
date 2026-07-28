/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPhysicsPart
   Object     : PORTAL\cphysobj\CPhysicsPart.obj
   Functions  : 115
   Addresses  : 0050D330 - 007670B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0050D330) --------------------------------------------------------  // acclient.c:314285
void __thiscall Ray::InitFromOffset(Ray *this, Vector3 *_start_pt, Vector3 *_offset)
{
  char *v3; // ecx@4
  char *v4; // eax@5
  double v5; // st7@5

  this->pt = *_start_pt;
  if ( fabs(_offset->x - stru_843C08.x) > 0.00019999999
    || fabs(_offset->y - stru_843C08.y) > 0.00019999999
    || fabs(_offset->z - stru_843C08.z) > 0.00019999999 )
  {
    v4 = (char *)&this->dir;
    this->length = sqrt(_offset->z * _offset->z + _offset->y * _offset->y + _offset->x * _offset->x);
    v5 = 1.0 / this->length;
    this->dir = *_offset;
    *(float *)v4 = v5 * this->dir.x;
    *((float *)v4 + 1) = v5 * this->dir.y;
    *((float *)v4 + 2) = v5 * this->dir.z;
  }
  else
  {
    LODWORD(this->length) = 0;
    v3 = (char *)&this->dir;
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 1) = 1065353216;
    *((_DWORD *)v3 + 2) = 0;
  }
}

//----- (0050D430) --------------------------------------------------------  // acclient.c:314315
void __cdecl Render::SetObjectScale(Vector3 *scale)
{
  float v1; // edx@1

  Render::object_scale_vec.x = scale->x;
  v1 = scale->y;
  dword_81EEB4 = LODWORD(scale->y);
  dword_81EEB8 = LODWORD(scale->z);
  LODWORD(Render::object_scale) = (_DWORD)Render::object_scale_vec.x;
  if ( *(float *)&dword_81EEB4 > (double)Render::object_scale_vec.x )
    Render::object_scale = v1;
  if ( *(float *)&dword_81EEB8 > (double)Render::object_scale )
    LODWORD(Render::object_scale) = dword_81EEB8;
}
// 81EC74: using guessed type float Render::object_scale;
// 81EEB0: using guessed type struct Vector3 Render::object_scale_vec;
// 81EEB4: using guessed type int dword_81EEB4;
// 81EEB8: using guessed type int dword_81EEB8;

//----- (0050D490) --------------------------------------------------------  // acclient.c:314335
unsigned int __thiscall CPhysicsPart::get_physobj_id(CPhysicsPart *this)
{
  CPhysicsObj *v1; // eax@1
  unsigned int result; // eax@2

  v1 = this->physobj;
  if ( v1 )
    result = v1->id;
  else
    result = 0;
  return result;
}

//----- (0050D4B0) --------------------------------------------------------  // acclient.c:314349
BOOL __thiscall CPhysicsPart::IsPartOfPlayerObj(CPhysicsPart *this)
{
  struct CPhysicsObj *v1; // eax@1

  v1 = this->physobj;
  return v1 && v1 == CPhysicsObj::player_object;
}
// 843D58: using guessed type struct CPhysicsObj *CPhysicsObj::player_object;

//----- (0050D4D0) --------------------------------------------------------  // acclient.c:314359
bool __thiscall CPhysicsPart::GetDrawnThisFrame(CPhysicsPart *this)
{
  return this->m_current_render_frame_num == RenderDevice::render_device->m_nFrameStamp;
}

//----- (0050D4F0) --------------------------------------------------------  // acclient.c:314365
void __thiscall CPhysicsPart::SetDrawnThisFrame(CPhysicsPart *this)
{
  this->m_current_render_frame_num = RenderDevice::render_device->m_nFrameStamp;
}

//----- (0050D510) --------------------------------------------------------  // acclient.c:314371
double __thiscall CPhysicsPart::GetMaxDegradeDistance(CPhysicsPart *this)
{
  GfxObjDegradeInfo *v1; // ecx@1
  double result; // st7@1

  v1 = this->degrades;
  result = 100.0;
  if ( v1 )
    result = GfxObjDegradeInfo::get_max_degrade_distance(v1);
  return result;
}

//----- (0050D530) --------------------------------------------------------  // acclient.c:314384
void __cdecl CPhysicsPart::ReleaseGfxObjArray(GfxObjDegradeInfo **old_degrades, CGfxObj ***old_gfxobj)
{
  GfxObjDegradeInfo *v2; // ecx@1
  signed int v3; // ebx@1
  unsigned int v4; // esi@4
  CGfxObj *v5; // ecx@5

  v2 = *old_degrades;
  v3 = 1;
  if ( *old_degrades )
  {
    v3 = v2->num_degrades;
    ((void (*)(void))v2->vfptr->Release)();
    *old_degrades = 0;
  }
  if ( *old_gfxobj )
  {
    v4 = 0;
    if ( v3 )
    {
      do
      {
        v5 = (*old_gfxobj)[v4];
        if ( v5 )
        {
          ((void (*)(void))v5->vfptr->Release)();
          (*old_gfxobj)[v4] = 0;
        }
        ++v4;
      }
      while ( v4 < v3 );
    }
    operator delete[](*old_gfxobj);
    *old_gfxobj = 0;
  }
}

//----- (0050D5A0) --------------------------------------------------------  // acclient.c:314422
IDClass<_tagDataID,32,0> *__thiscall CPhysicsPart::GetOriginalPaletteID(CPhysicsPart *this, IDClass<_tagDataID,32,0> *result)
{
  IDClass<_tagDataID,32,0> *v2; // eax@1

  v2 = result;
  result->id = this->original_palette_id.id;
  return v2;
}

//----- (0050D5B0) --------------------------------------------------------  // acclient.c:314432
void __thiscall CPhysicsPart::RestorePalette(CPhysicsPart *this)
{
  CPhysicsPart *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = 0;
  if ( (*this->gfxobj)->num_surfaces )
  {
    do
      CSurface::RestorePalette(v1->surfaces[v2++]);
    while ( v2 < (*v1->gfxobj)->num_surfaces );
  }
  if ( v1->shiftPal )
  {
    Palette::releasePalette(v1->shiftPal);
    v1->shiftPal = 0;
  }
}

//----- (0050D600) --------------------------------------------------------  // acclient.c:314453
BBox *__thiscall CPhysicsPart::GetBoundingBox(CPhysicsPart *this)
{
  return &(*this->gfxobj)->gfx_bound_box;
}

//----- (0050D610) --------------------------------------------------------  // acclient.c:314459
void __thiscall CPhysicsPart::SetNoDraw(CPhysicsPart *this, int no_draw)
{
  int v2; // eax@1

  v2 = this->draw_state;
  if ( no_draw )
    this->draw_state = v2 | 1;
  else
    this->draw_state = v2 & 0xFFFFFFFE;
}

//----- (0050D630) --------------------------------------------------------  // acclient.c:314471
int __thiscall CPhysicsPart::CopyMaterial(CPhysicsPart *this)
{
  CPhysicsPart *v1; // esi@1
  CMaterial *v2; // eax@1
  CMaterial *v4; // eax@4
  CMaterial *v5; // eax@5
  CMaterial *v6; // eax@6

  v1 = this;
  v2 = (*this->gfxobj)->material;
  if ( this->material != v2 )
    return 1;
  if ( !v2 )
  {
    v6 = (CMaterial *)operator new(0x50u);
    if ( v6 )
    {
      CMaterial::CMaterial(v6);
      goto LABEL_9;
    }
LABEL_8:
    v5 = 0;
    goto LABEL_9;
  }
  v4 = (CMaterial *)operator new(0x50u);
  if ( !v4 )
    goto LABEL_8;
  CMaterial::CMaterial(v4, (*v1->gfxobj)->material);
LABEL_9:
  v1->material = v5;
  return v1->material != 0;
}

//----- (0050D6A0) --------------------------------------------------------  // acclient.c:314505
CSurface **__thiscall CPhysicsPart::CopySurfaces(CPhysicsPart *this)
{
  CPhysicsPart *v1; // edi@1
  CGfxObj *v2; // eax@1
  CSurface **result; // eax@2
  CGfxObj *v4; // eax@4
  CSurface **v5; // ebx@4
  unsigned int v6; // esi@4
  CSurface *v7; // eax@5

  v1 = this;
  v2 = *this->gfxobj;
  if ( this->surfaces == v2->m_rgSurfaces )
  {
    result = (CSurface **)operator new[](4 * v2->num_surfaces);
    v1->surfaces = result;
    if ( result )
    {
      v4 = *v1->gfxobj;
      v5 = v4->m_rgSurfaces;
      v6 = 0;
      if ( v4->num_surfaces )
      {
        while ( 1 )
        {
          CSurface::makeCustomSurface(v5[v6]);
          v1->surfaces[v6] = v7;
          if ( !v1->surfaces[v6] )
            break;
          ++v6;
          if ( v6 >= (*v1->gfxobj)->num_surfaces )
            goto LABEL_7;
        }
        result = 0;
      }
      else
      {
LABEL_7:
        result = (CSurface **)1;
      }
    }
  }
  else
  {
    result = (CSurface **)1;
  }
  return result;
}

//----- (0050D730) --------------------------------------------------------  // acclient.c:314555
void __thiscall CPhysicsPart::RestoreSurfaces(CPhysicsPart *this)
{
  CPhysicsPart *v1; // esi@1
  CGfxObj **v2; // eax@1
  CGfxObj *v3; // eax@2
  unsigned int v4; // edi@4

  v1 = this;
  v2 = this->gfxobj;
  if ( v2 )
  {
    v3 = *v2;
    if ( v3 )
    {
      if ( this->surfaces != v3->m_rgSurfaces )
      {
        v4 = 0;
        if ( v3->num_surfaces )
        {
          do
            CSurface::releaseCustomSurface(v1->surfaces[v4++]);
          while ( v4 < (*v1->gfxobj)->num_surfaces );
        }
        operator delete[](v1->surfaces);
        v1->surfaces = (*v1->gfxobj)->m_rgSurfaces;
      }
    }
  }
}

//----- (0050D7A0) --------------------------------------------------------  // acclient.c:314586
void __thiscall CPhysicsPart::Draw(CPhysicsPart *this, int building_flag)
{
  CPhysicsPart *v2; // esi@1
  GfxObjDegradeInfo *v3; // edx@4
  unsigned int v4; // eax@4
  CGfxObj *v5; // edi@7
  int v6; // edx@8
  CPhysicsObj *v7; // eax@8
  int v8; // eax@12
  CPhysicsObj *v9; // esi@14
  unsigned int v10; // esi@15

  v2 = this;
  if ( !(this->draw_state & 1)
    && (building_flag || this->m_current_render_frame_num != RenderDevice::render_device->m_nFrameStamp) )
  {
    v3 = this->degrades;
    v4 = this->deg_level;
    if ( !v3 || v4 >= v3->num_degrades )
      v4 = 0;
    v5 = this->gfxobj[v4];
    if ( v5 )
    {
      RenderDeviceD3D::SetCurrentMaterial((RenderDeviceD3D *)RenderDevice::render_device, this->material, 0);
      Render::SetSurfaceArray(v2->surfaces);
      Render::SetObjectScale((Vector3 *)&v2->gfxobj_scale.x);
      v7 = v2->physobj;
      if ( v7 && v7->id || (Render::check_curr_object = 0, CPhysicsPart::creature_mode) )
        Render::check_curr_object = 1;
      LOBYTE(v6) = building_flag != 0;
      RenderDeviceD3D::s_current_physics_part = v2;
      v8 = ((int (__stdcall *)(CGfxObj *, Position *, int))RenderDevice::render_device->vfptr->DrawMesh)(
             v5,
             &v2->draw_pos,
             v6);
      RenderDeviceD3D::s_current_physics_part = 0;
      if ( v8 == 2 && CPhysicsPart::viewcone_check_object_id )
      {
        v9 = v2->physobj;
        if ( v9 )
          v10 = v9->id;
        else
          v10 = 0;
        if ( CPhysicsPart::viewcone_check_object_id == v10 )
          CPhysicsPart::selected_object_in_view = 1;
      }
    }
  }
}
// 843BEC: using guessed type unsigned __int32 CPhysicsPart::viewcone_check_object_id;
// 843BF0: using guessed type int CPhysicsPart::selected_object_in_view;
// 843BF4: using guessed type int CPhysicsPart::creature_mode;
// 866338: using guessed type bool Render::check_curr_object;

//----- (0050D8A0) --------------------------------------------------------  // acclient.c:314641
int __thiscall CPhysicsPart::Always2D(CPhysicsPart *this)
{
  GfxObjDegradeInfo *v1; // eax@1
  int result; // eax@3

  v1 = this->degrades;
  if ( v1 && v1->num_degrades )
    result = v1->degrades->degrade_mode != 1;
  else
    result = 0;
  return result;
}

//----- (0050D8D0) --------------------------------------------------------  // acclient.c:314655
signed int __thiscall CPhysicsPart::find_obj_collisions(CPhysicsPart *this, CTransition *transition)
{
  CPhysicsPart *v2; // esi@1
  CGfxObj *v3; // ecx@1
  signed int result; // eax@1

  v2 = this;
  v3 = *this->gfxobj;
  result = 1;
  if ( v3 )
  {
    if ( v3->physics_bsp )
    {
      SPHEREPATH::cache_localspace_sphere(&transition->sphere_path, &v2->pos, v2->gfxobj_scale.z);
      result = CGfxObj::find_obj_collisions(*v2->gfxobj, transition, v2->gfxobj_scale.z);
    }
  }
  return result;
}

//----- (0050D920) --------------------------------------------------------  // acclient.c:314676
AC1Legacy::Vector3 *__thiscall Position::get_offset(Position *this, AC1Legacy::Vector3 *result, Position *p, AC1Legacy::Vector3 *v)
{
  Position *v4; // esi@1
  Position *v5; // edi@1
  double v6; // st7@1
  double v7; // st6@1
  AC1Legacy::Vector3 *v8; // eax@1
  double v9; // st7@1
  double v10; // st6@1
  AC1Legacy::Vector3 v11; // [sp+8h] [bp-24h]@1
  float v12; // [sp+14h] [bp-18h]@1
  float v13; // [sp+1Ch] [bp-10h]@1
  float v14; // [sp+20h] [bp-Ch]@1
  float v15; // [sp+28h] [bp-4h]@1

  v4 = p;
  v5 = this;
  LandDefs::get_block_offset(&v11, this->objcell_id, p->objcell_id);
  v6 = v4->frame.m_fl2gv[3] * v->y + v4->frame.m_fl2gv[0] * v->x + v4->frame.m_fl2gv[6] * v->z + v4->frame.m_fOrigin.x;
  v7 = v4->frame.m_fl2gv[4] * v->y + v4->frame.m_fl2gv[1] * v->x + v4->frame.m_fl2gv[7] * v->z + v4->frame.m_fOrigin.y;
  v8 = result;
  v15 = v4->frame.m_fl2gv[5] * v->y + v4->frame.m_fl2gv[2] * v->x + v4->frame.m_fl2gv[8] * v->z + v4->frame.m_fOrigin.z;
  v12 = v11.x + v6;
  v13 = v11.z + v15;
  v14 = v12 - v5->frame.m_fOrigin.x;
  v9 = v11.y + v7 - v5->frame.m_fOrigin.y;
  v10 = v13 - v5->frame.m_fOrigin.z;
  result->x = v14;
  result->y = v9;
  result->z = v10;
  return v8;
}

//----- (0050D9E0) --------------------------------------------------------  // acclient.c:314710
int __thiscall CPhysicsPart::CurSettingsAreDefault(CPhysicsPart *this)
{
  CPhysicsPart *v1; // esi@1
  CGfxObj **v2; // eax@1
  CGfxObj *v3; // eax@2
  CMaterial *v4; // eax@3
  double v5; // st7@4
  CGfxObj **v6; // eax@7
  CGfxObj *v7; // eax@8
  CMaterial *v8; // eax@9
  double v9; // st7@10
  CGfxObj **v10; // eax@13
  CGfxObj *v11; // eax@14
  CMaterial *v12; // eax@15
  double v13; // st7@16
  int result; // eax@19

  v1 = this;
  v2 = this->gfxobj;
  if ( v2 && (v3 = *v2) != 0 && (v4 = v3->material) != 0 )
    v5 = CMaterial::GetTranslucencySimple(v4);
  else
    v5 = 0.0;
  result = 0;
  if ( v5 == v1->curTranslucency )
  {
    v6 = v1->gfxobj;
    if ( v6 && (v7 = *v6) != 0 && (v8 = v7->material) != 0 )
      v9 = CMaterial::GetColorDiffuseSimple(v8);
    else
      v9 = 1.0;
    if ( v9 == v1->curDiffuse )
    {
      v10 = v1->gfxobj;
      if ( v10 && (v11 = *v10) != 0 && (v12 = v11->material) != 0 )
        v13 = CMaterial::GetLuminositySimple(v12);
      else
        v13 = 0.0;
      if ( v13 == v1->curLuminosity )
        result = 1;
    }
  }
  return result;
}

//----- (0050DA80) --------------------------------------------------------  // acclient.c:314756
void __thiscall CPhysicsPart::CPhysicsPart(CPhysicsPart *this)
{
  CPhysicsPart *v1; // esi@1
  char *v2; // ecx@1
  int v3; // ecx@1
  int v4; // eax@1
  unsigned int v5; // edx@1

  v1 = this;
  v2 = (char *)&this->pos.frame;
  v1->gfxobj = 0;
  LODWORD(v1->gfxobj_scale.x) = 1065353216;
  LODWORD(v1->gfxobj_scale.y) = 1065353216;
  LODWORD(v1->gfxobj_scale.z) = 1065353216;
  v1->pos.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->pos.objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  v3 = (int)&v1->draw_pos.frame;
  v1->draw_pos.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->draw_pos.objcell_id = 0;
  *(_DWORD *)v3 = 1065353216;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 0;
  *(_DWORD *)(v3 + 52) = 0;
  *(_DWORD *)(v3 + 56) = 0;
  *(_DWORD *)(v3 + 60) = 0;
  Frame::cache(&v1->draw_pos.frame);
  v4 = (int)&v1->viewer_heading;
  *(_DWORD *)v4 = 0;
  *(_DWORD *)(v4 + 4) = 0;
  v1->physobj = 0;
  v1->deg_level = 0;
  v1->degrades = 0;
  v1->draw_state = 0;
  v1->material = 0;
  v1->surfaces = 0;
  v1->shiftPal = 0;
  v1->physobj_index = -1;
  v1->deg_mode = 1;
  *(_DWORD *)(v4 + 8) = 1065353216;
  LODWORD(v1->CYpt) = 2139095039;
  v5 = stru_843C5C.id;
  v1->m_current_render_frame_num = 0;
  v1->original_palette_id.id = v5;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (0050DB70) --------------------------------------------------------  // acclient.c:314812
char __thiscall CPhysicsPart::MorphToExistingObject(CPhysicsPart *this, CPhysicsPart *pTemplate)
{
  CPhysicsPart *v2; // esi@1
  void *v3; // eax@1
  int v4; // ecx@1
  CGfxObj **v5; // edx@1
  unsigned int v6; // ebp@1
  char result; // al@2
  unsigned int v8; // ebx@3

  v2 = this;
  v3 = operator new[](4u);
  v2->gfxobj = (CGfxObj **)v3;
  *(_DWORD *)v3 = *pTemplate->gfxobj;
  (*(void (**)(void))(**(_DWORD **)v2->gfxobj + 16))();
  v4 = (int)&v2->gfxobj_scale;
  *(_DWORD *)v4 = LODWORD(pTemplate->gfxobj_scale.x);
  *(_DWORD *)(v4 + 4) = LODWORD(pTemplate->gfxobj_scale.y);
  *(_DWORD *)(v4 + 8) = LODWORD(pTemplate->gfxobj_scale.z);
  v2->pos.objcell_id = pTemplate->pos.objcell_id;
  Frame::operator=((int)&v2->pos.frame, (int)&pTemplate->pos.frame);
  v2->draw_pos.objcell_id = pTemplate->draw_pos.objcell_id;
  Frame::operator=((int)&v2->draw_pos.frame, (int)&pTemplate->draw_pos.frame);
  v2->original_palette_id.id = pTemplate->original_palette_id.id;
  v5 = v2->gfxobj;
  v2->curDiffuse = pTemplate->curDiffuse;
  v2->curLuminosity = pTemplate->curLuminosity;
  v6 = (*v5)->num_surfaces;
  if ( pTemplate->surfaces == (*pTemplate->gfxobj)->m_rgSurfaces )
  {
    v2->surfaces = (*v5)->m_rgSurfaces;
    result = 1;
  }
  else
  {
    v8 = 0;
    v2->surfaces = (CSurface **)operator new[](4 * v6);
    if ( v6 )
    {
      do
      {
        v2->surfaces[v8] = pTemplate->surfaces[v8];
        ((void (*)(void))v2->surfaces[v8++]->vfptr->AddRef)();
      }
      while ( v8 < v6 );
    }
    result = 1;
  }
  return result;
}

//----- (0050DC80) --------------------------------------------------------  // acclient.c:314864
void __thiscall CPhysicsPart::DetermineBasePal(CPhysicsPart *this)
{
  CPhysicsPart *v1; // esi@1
  signed int v2; // edi@1
  IDClass<_tagDataID,32,0> result; // [sp+0h] [bp-4h]@1

  result.id = (unsigned int)this;
  v1 = this;
  v2 = 0;
  if ( (signed int)(*this->gfxobj)->num_surfaces <= 0 )
  {
LABEL_4:
    v1->original_palette_id.id = stru_843C5C.id;
  }
  else
  {
    while ( !CSurface::GetOriginalPaletteID(v1->surfaces[v2], &result)->id )
    {
      ++v2;
      if ( v2 >= (signed int)(*v1->gfxobj)->num_surfaces )
        goto LABEL_4;
    }
    v1->original_palette_id.id = CSurface::GetOriginalPaletteID(v1->surfaces[v2], &result)->id;
  }
}

//----- (0050DCF0) --------------------------------------------------------  // acclient.c:314891
int __cdecl CPhysicsPart::LoadGfxObjArray(IDClass<_tagDataID,32,0> i_idRootObject, GfxObjDegradeInfo **new_degrades, CGfxObj ***new_gfxobj)
{
  QualifiedDataID *v3; // eax@1
  int v4; // eax@1
  IDClass<_tagDataID,32,0> v5; // esi@2
  QualifiedDataID *v6; // eax@2
  int v7; // eax@2
  CGfxObj ***v8; // esi@3
  unsigned int v9; // eax@3
  unsigned int v10; // edi@5
  int v11; // ebp@6
  unsigned int v12; // eax@7
  QualifiedDataID *v13; // eax@9
  CGfxObj **v14; // eax@12
  QualifiedDataID *v15; // eax@12
  int result; // eax@15
  int retval; // [sp+4h] [bp-Ch]@1
  QualifiedDataID v18; // [sp+8h] [bp-8h]@1

  retval = 1;
  QualifiedDataID::QualifiedDataID(&v18, i_idRootObject, 6u);
  v4 = DBObj::Get(v3);
  if ( v4 )
  {
    v5.id = *(_DWORD *)(v4 + 176);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
    QualifiedDataID::QualifiedDataID(&v18, v5, 0x1Au);
    v7 = DBObj::Get(v6);
    *new_degrades = (GfxObjDegradeInfo *)v7;
    if ( v7 )
    {
      v8 = new_gfxobj;
      *new_gfxobj = (CGfxObj **)operator new[](4 * *(_DWORD *)(v7 + 56));
      v9 = 0;
      if ( (*new_degrades)->num_degrades )
      {
        do
          (*new_gfxobj)[v9++] = 0;
        while ( v9 < (*new_degrades)->num_degrades );
      }
      v10 = 0;
      if ( (*new_degrades)->num_degrades )
      {
        v11 = 0;
        do
        {
          v12 = (*new_degrades)->degrades[v11].gfxobj_id.id;
          if ( v12 == stru_843C5C.id )
          {
            (*new_gfxobj)[v10] = 0;
          }
          else
          {
            QualifiedDataID::QualifiedDataID(&v18, (IDClass<_tagDataID,32,0>)v12, 6u);
            (*new_gfxobj)[v10] = (CGfxObj *)DBObj::Get(v13);
          }
          ++v10;
          ++v11;
        }
        while ( v10 < (*new_degrades)->num_degrades );
      }
    }
    else
    {
      v14 = (CGfxObj **)operator new[](4u);
      v8 = new_gfxobj;
      *new_gfxobj = v14;
      *v14 = 0;
      QualifiedDataID::QualifiedDataID(&v18, i_idRootObject, 6u);
      **new_gfxobj = (CGfxObj *)DBObj::Get(v15);
    }
    if ( !**v8 )
    {
      retval = 0;
      CPhysicsPart::ReleaseGfxObjArray(new_degrades, v8);
    }
    result = retval;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0050DE30) --------------------------------------------------------  // acclient.c:314977
int __thiscall CPhysicsPart::SetTextureMap(CPhysicsPart *this, IDClass<_tagDataID,32,0> old_tex_id, IDClass<_tagDataID,32,0> new_tex_id)
{
  unsigned int v3; // ebp@1
  CPhysicsPart *v4; // esi@1
  int result; // eax@4
  unsigned int v6; // edi@5

  v3 = new_tex_id.id;
  v4 = this;
  if ( new_tex_id.id != stru_843C5C.id
    && (this->surfaces != (*this->gfxobj)->m_rgSurfaces || CPhysicsPart::CopySurfaces(this)) )
  {
    v6 = 0;
    if ( (*v4->gfxobj)->num_surfaces )
    {
      while ( CSurface::GetOriginalTextureMapID(v4->surfaces[v6], &new_tex_id)->id != old_tex_id.id
           || CSurface::UseTextureMap(v4->surfaces[v6], (IDClass<_tagDataID,32,0>)v3, 0) )
      {
        ++v6;
        if ( v6 >= (*v4->gfxobj)->num_surfaces )
          goto LABEL_9;
      }
      result = 0;
    }
    else
    {
LABEL_9:
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0050DED0) --------------------------------------------------------  // acclient.c:315015
int __thiscall CPhysicsPart::UsePalette(CPhysicsPart *this, Palette *pal)
{
  CPhysicsPart *v2; // esi@1
  int result; // eax@4
  signed int i; // edi@5

  v2 = this;
  if ( pal && (this->surfaces != (*this->gfxobj)->m_rgSurfaces || CPhysicsPart::CopySurfaces(this)) )
  {
    for ( i = 0; i < (signed int)(*v2->gfxobj)->num_surfaces; ++i )
      CSurface::UsePalette(v2->surfaces[i], pal);
    if ( v2->shiftPal )
    {
      Palette::releasePalette(v2->shiftPal);
      v2->shiftPal = 0;
    }
    v2->shiftPal = Palette::copyRef(pal);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0050DF70) --------------------------------------------------------  // acclient.c:315042
void __thiscall CPhysicsPart::RestoreMaterial(CPhysicsPart *this)
{
  CPhysicsPart *v1; // esi@1
  CGfxObj **v2; // eax@1
  CGfxObj *v3; // eax@2
  ReferenceCountTemplate<1048576,0> *v4; // ecx@3

  v1 = this;
  v2 = this->gfxobj;
  if ( v2 )
  {
    v3 = *v2;
    if ( v3 )
    {
      v4 = (ReferenceCountTemplate<1048576,0> *)&this->material->vfptr;
      if ( (CMaterial *)v4 != v3->material )
        ReferenceCountTemplate<1048576,0>::Release(v4);
      v1->material = 0;
    }
  }
}

//----- (0050DFA0) --------------------------------------------------------  // acclient.c:315065
void __thiscall CPhysicsPart::calc_draw_frame(CPhysicsPart *this)
{
  CPhysicsPart *v1; // esi@1
  int v2; // eax@1

  v1 = this;
  this->draw_pos.objcell_id = this->pos.objcell_id;
  Frame::operator=((int)&this->draw_pos.frame, (int)&this->pos.frame);
  v2 = v1->deg_mode;
  if ( v2 != 1 )
  {
    switch ( v2 )
    {
      case 2:
        Frame::set_vector_heading(&v1->draw_pos.frame, &v1->viewer_heading);
        break;
      case 3:
        Frame::rotate_around_axis_to_vector(&v1->draw_pos.frame, 0, &v1->viewer_heading);
        break;
      case 4:
        Frame::rotate_around_axis_to_vector(&v1->draw_pos.frame, 1, &v1->viewer_heading);
        break;
      case 5:
        Frame::rotate_around_axis_to_vector(&v1->draw_pos.frame, 2, &v1->viewer_heading);
        break;
      default:
        return;
    }
  }
}

//----- (0050E030) --------------------------------------------------------  // acclient.c:315097
void __thiscall CPhysicsPart::UpdateViewerDistance(CPhysicsPart *this)
{
  CPhysicsPart *v1; // esi@1
  CGfxObj *v2; // eax@1
  double v3; // st7@1
  double v4; // st6@1
  int v5; // ecx@2
  double v6; // st7@2
  double v7; // st6@2
  float v8; // edx@2
  int v9; // eax@3
  GfxObjDegradeInfo *v10; // ecx@4
  CPhysicsObj *v11; // eax@5
  unsigned int v12; // eax@6
  int v13; // edi@9
  float distance; // ST00_4@9
  float v15; // [sp+14h] [bp-1Ch]@1
  AC1Legacy::Vector3 diff_vec; // [sp+18h] [bp-18h]@1
  AC1Legacy::Vector3 v; // [sp+24h] [bp-Ch]@1

  v1 = this;
  v2 = *this->gfxobj;
  v3 = this->gfxobj_scale.x * v2->sort_center.x;
  v2 = (CGfxObj *)((char *)v2 + 124);
  v4 = this->gfxobj_scale.y * *(float *)&v2->m_dataCategory;
  diff_vec.z = this->gfxobj_scale.z * *(float *)&v2->m_bLoaded;
  v.z = diff_vec.z;
  v.x = v3;
  v.y = v4;
  Position::get_offset(&Render::viewer_pos, &diff_vec, &this->pos, &v);
  v15 = sqrt(diff_vec.z * diff_vec.z + diff_vec.y * diff_vec.y + diff_vec.x * diff_vec.x);
  v1->CYpt = v15;
  if ( v15 <= 0.00019999999 )
  {
    LODWORD(diff_vec.x) = 0;
    v9 = (int)&v1->viewer_heading;
    *(_DWORD *)v9 = 0;
    LODWORD(diff_vec.y) = 0;
    LODWORD(diff_vec.z) = 1065353216;
    *(_DWORD *)(v9 + 4) = 0;
    *(_DWORD *)(v9 + 8) = 1065353216;
  }
  else
  {
    v5 = (int)&v1->viewer_heading;
    v6 = 1.0 / v15;
    v.z = diff_vec.z * v6;
    v7 = diff_vec.y * v6;
    diff_vec.z = v.z;
    diff_vec.x = diff_vec.x * v6;
    *(_DWORD *)v5 = (_DWORD)diff_vec.x;
    v8 = diff_vec.z;
    diff_vec.y = v7;
    *(_DWORD *)(v5 + 4) = LODWORD(diff_vec.y);
    *(float *)(v5 + 8) = v8;
  }
  v10 = v1->degrades;
  if ( v10 && ((v11 = v1->physobj) == 0 ? (v12 = 0) : (v12 = v11->id), v12 != CPhysicsPart::player_iid) )
  {
    v13 = (int)&v1->deg_level;
    distance = v15 / v1->gfxobj_scale.z;
    GfxObjDegradeInfo::get_degrade(v10, distance, &v1->deg_level, &v1->deg_mode);
  }
  else
  {
    v13 = (int)&v1->deg_level;
    v1->deg_level = 0;
    v1->deg_mode = 1;
  }
  if ( v1->gfxobj[*(_DWORD *)v13] )
    CPhysicsPart::calc_draw_frame(v1);
}
// 843BF8: using guessed type unsigned __int32 CPhysicsPart::player_iid;

//----- (0050E1A0) --------------------------------------------------------  // acclient.c:315172
void __thiscall CPhysicsPart::UpdateViewerDistance(CPhysicsPart *this, float _CYpt, AC1Legacy::Vector3 *_viewer_heading)
{
  CPhysicsPart *v3; // esi@1
  GfxObjDegradeInfo *v4; // ecx@1
  CPhysicsObj *v5; // eax@2
  unsigned int v6; // eax@3
  int v7; // edi@6
  float distance; // ST00_4@6

  v3 = this;
  this->CYpt = _CYpt;
  this->viewer_heading = *_viewer_heading;
  v4 = this->degrades;
  if ( v4 && ((v5 = v3->physobj) == 0 ? (v6 = 0) : (v6 = v5->id), v6 != CPhysicsPart::player_iid) )
  {
    v7 = (int)&v3->deg_level;
    distance = _CYpt / v3->gfxobj_scale.z;
    GfxObjDegradeInfo::get_degrade(v4, distance, &v3->deg_level, &v3->deg_mode);
  }
  else
  {
    v7 = (int)&v3->deg_level;
    v3->deg_level = 0;
    v3->deg_mode = 1;
  }
  if ( v3->gfxobj[*(_DWORD *)v7] )
    CPhysicsPart::calc_draw_frame(v3);
}
// 843BF8: using guessed type unsigned __int32 CPhysicsPart::player_iid;

//----- (0050E230) --------------------------------------------------------  // acclient.c:315203
CPhysicsPart *__cdecl CPhysicsPart::makePhysicsPart(CPhysicsPart *pTemplate)
{
  CPhysicsPart *v1; // eax@1
  CPhysicsPart *v2; // eax@2
  CPhysicsPart *v3; // esi@2
  CPhysicsPart *result; // eax@4

  v1 = (CPhysicsPart *)operator new(0xE8u);
  if ( v1 )
  {
    CPhysicsPart::CPhysicsPart(v1);
    v3 = v2;
    if ( v2 )
      CPhysicsPart::MorphToExistingObject(v2, pTemplate);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0050E270) --------------------------------------------------------  // acclient.c:315227
void __thiscall CPhysicsPart::~CPhysicsPart(CPhysicsPart *this)
{
  CPhysicsPart *v1; // esi@1
  Palette *v2; // ecx@1
  CGfxObj **v3; // eax@3
  CGfxObj *v4; // eax@4
  ReferenceCountTemplate<1048576,0> *v5; // ecx@5

  v1 = this;
  v2 = this->shiftPal;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->shiftPal = 0;
  }
  v3 = v1->gfxobj;
  if ( v3 )
  {
    v4 = *v3;
    if ( v4 )
    {
      v5 = (ReferenceCountTemplate<1048576,0> *)&v1->material->vfptr;
      if ( (CMaterial *)v5 != v4->material )
        ReferenceCountTemplate<1048576,0>::Release(v5);
      v1->material = 0;
    }
  }
  CPhysicsPart::RestoreSurfaces(v1);
  CPhysicsPart::ReleaseGfxObjArray(&v1->degrades, &v1->gfxobj);
  v1->draw_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0050E2E0) --------------------------------------------------------  // acclient.c:315262
void __thiscall CPhysicsPart::SetGfxObjArray(CPhysicsPart *this, GfxObjDegradeInfo *new_degrades, CGfxObj **new_gfxobj)
{
  CPhysicsPart *v3; // esi@1
  int v4; // edi@1
  int v5; // eax@2
  CMaterial *v6; // eax@3
  double v7; // st7@4
  int v8; // eax@6
  int v9; // eax@7
  CMaterial *v10; // eax@8
  double v11; // st7@9
  int v12; // edi@11
  int v13; // edi@12
  CMaterial *v14; // ecx@13
  double v15; // st7@14
  Palette *v16; // eax@16

  v3 = this;
  CPhysicsPart::RestoreSurfaces(this);
  v4 = (int)&v3->gfxobj;
  CPhysicsPart::ReleaseGfxObjArray(&v3->degrades, &v3->gfxobj);
  v3->degrades = new_degrades;
  v3->gfxobj = new_gfxobj;
  v3->surfaces = (*new_gfxobj)->m_rgSurfaces;
  CPhysicsPart::DetermineBasePal(v3);
  if ( v3->gfxobj && (v5 = **(_DWORD **)v4) != 0 && (v6 = *(CMaterial **)(v5 + 48)) != 0 )
    v7 = CMaterial::GetTranslucencySimple(v6);
  else
    v7 = 0.0;
  v8 = *(_DWORD *)v4;
  v3->curTranslucency = v7;
  if ( v8 && (v9 = *(_DWORD *)v8) != 0 && (v10 = *(CMaterial **)(v9 + 48)) != 0 )
    v11 = CMaterial::GetColorDiffuseSimple(v10);
  else
    v11 = 1.0;
  v12 = *(_DWORD *)v4;
  v3->curDiffuse = v11;
  if ( v12 && (v13 = *(_DWORD *)v12) != 0 && (v14 = *(CMaterial **)(v13 + 48)) != 0 )
    v15 = CMaterial::GetLuminositySimple(v14);
  else
    v15 = 0.0;
  v16 = v3->shiftPal;
  v3->curLuminosity = v15;
  if ( v16 )
    CPhysicsPart::UsePalette(v3, v16);
}

//----- (0050E3B0) --------------------------------------------------------  // acclient.c:315310
int __thiscall CPhysicsPart::InitObjDescChanges(CPhysicsPart *this)
{
  CPhysicsPart *v1; // esi@1
  signed int i; // edi@3

  v1 = this;
  if ( this->shiftPal )
    CPhysicsPart::UsePalette(this, this->shiftPal);
  for ( i = 0; i < (signed int)(*v1->gfxobj)->num_surfaces; ++i )
    CSurface::InitEnd(v1->surfaces[i], 0);
  return 1;
}

//----- (0050E400) --------------------------------------------------------  // acclient.c:315324
void __thiscall CPhysicsPart::SetLighting(CPhysicsPart *this, float _luminosity, float _diffuse)
{
  CPhysicsPart *v3; // esi@1
  CGfxObj **v4; // eax@4
  CGfxObj *v5; // eax@5
  ReferenceCountTemplate<1048576,0> *v6; // ecx@6

  v3 = this;
  if ( _luminosity != this->curLuminosity || _diffuse != this->curDiffuse )
  {
    this->curDiffuse = _diffuse;
    this->curLuminosity = _luminosity;
    if ( (unsigned __int8)CPhysicsPart::CurSettingsAreDefault(this) )
    {
      v4 = v3->gfxobj;
      if ( v4 )
      {
        v5 = *v4;
        if ( v5 )
        {
          v6 = (ReferenceCountTemplate<1048576,0> *)&v3->material->vfptr;
          if ( (CMaterial *)v6 != v5->material )
            ReferenceCountTemplate<1048576,0>::Release(v6);
          v3->material = 0;
        }
      }
    }
    else if ( CPhysicsPart::CopyMaterial(v3) )
    {
      CMaterial::SetLuminositySimple(v3->material, _luminosity);
      CMaterial::SetDiffuseSimple(v3->material, _diffuse);
    }
  }
}

//----- (0050E4A0) --------------------------------------------------------  // acclient.c:315360
void __thiscall CPhysicsPart::RestoreLighting(CPhysicsPart *this)
{
  CPhysicsPart *v1; // esi@1
  CGfxObj **v2; // eax@1
  CGfxObj *v3; // eax@2
  CMaterial *v4; // eax@3
  double v5; // st7@4
  CGfxObj **v6; // eax@6
  CGfxObj *v7; // eax@8
  CMaterial *v8; // eax@9
  CGfxObj **v9; // eax@12
  CGfxObj *v10; // eax@13
  CMaterial *v11; // eax@14
  float _diffuse; // ST0C_4@15
  CGfxObj *v13; // eax@19
  ReferenceCountTemplate<1048576,0> *v14; // ecx@20
  float _luminosity; // [sp+8h] [bp-4h]@10

  v1 = this;
  v2 = this->gfxobj;
  if ( v2 && (v3 = *v2) != 0 && (v4 = v3->material) != 0 )
    v5 = CMaterial::GetTranslucencySimple(v4);
  else
    v5 = 0.0;
  v6 = v1->gfxobj;
  if ( v5 == v1->curTranslucency )
  {
    if ( v6 )
    {
      v13 = *v6;
      if ( v13 )
      {
        v14 = (ReferenceCountTemplate<1048576,0> *)&v1->material->vfptr;
        if ( (CMaterial *)v14 != v13->material )
          ReferenceCountTemplate<1048576,0>::Release(v14);
        v1->material = 0;
      }
    }
  }
  else
  {
    if ( v6 && (v7 = *v6) != 0 && (v8 = v7->material) != 0 )
      _luminosity = CMaterial::GetLuminositySimple(v8);
    else
      _luminosity = 0.0;
    v9 = v1->gfxobj;
    if ( v9 && (v10 = *v9) != 0 && (v11 = v10->material) != 0 )
    {
      _diffuse = CMaterial::GetColorDiffuseSimple(v11);
      CPhysicsPart::SetLighting(v1, _luminosity, _diffuse);
    }
    else
    {
      CPhysicsPart::SetLighting(v1, _luminosity, 1.0);
    }
  }
}

//----- (0050E570) --------------------------------------------------------  // acclient.c:315419
void __thiscall CPhysicsPart::SetDiffusion(CPhysicsPart *this, float _diffuse)
{
  CPhysicsPart *v2; // esi@1
  CGfxObj **v3; // eax@3
  CGfxObj *v4; // eax@4
  ReferenceCountTemplate<1048576,0> *v5; // ecx@5

  v2 = this;
  if ( _diffuse != this->curDiffuse )
  {
    this->curDiffuse = _diffuse;
    if ( (unsigned __int8)CPhysicsPart::CurSettingsAreDefault(this) )
    {
      v3 = v2->gfxobj;
      if ( v3 )
      {
        v4 = *v3;
        if ( v4 )
        {
          v5 = (ReferenceCountTemplate<1048576,0> *)&v2->material->vfptr;
          if ( (CMaterial *)v5 != v4->material )
            ReferenceCountTemplate<1048576,0>::Release(v5);
          v2->material = 0;
        }
      }
    }
    else if ( CPhysicsPart::CopyMaterial(v2) )
    {
      CMaterial::SetDiffuseSimple(v2->material, _diffuse);
    }
  }
}

//----- (0050E5F0) --------------------------------------------------------  // acclient.c:315453
void __thiscall CPhysicsPart::SetLuminosity(CPhysicsPart *this, float _luminosity)
{
  CPhysicsPart *v2; // esi@1
  CGfxObj **v3; // eax@3
  CGfxObj *v4; // eax@4
  ReferenceCountTemplate<1048576,0> *v5; // ecx@5

  v2 = this;
  if ( _luminosity != this->curLuminosity )
  {
    this->curLuminosity = _luminosity;
    if ( (unsigned __int8)CPhysicsPart::CurSettingsAreDefault(this) )
    {
      v3 = v2->gfxobj;
      if ( v3 )
      {
        v4 = *v3;
        if ( v4 )
        {
          v5 = (ReferenceCountTemplate<1048576,0> *)&v2->material->vfptr;
          if ( (CMaterial *)v5 != v4->material )
            ReferenceCountTemplate<1048576,0>::Release(v5);
          v2->material = 0;
        }
      }
    }
    else if ( CPhysicsPart::CopyMaterial(v2) )
    {
      CMaterial::SetLuminositySimple(v2->material, _luminosity);
    }
  }
}

//----- (0050E670) --------------------------------------------------------  // acclient.c:315487
void __thiscall CPhysicsPart::SetTranslucency(CPhysicsPart *this, float _translucency)
{
  CPhysicsPart *v2; // esi@1
  CPhysicsObj *v3; // eax@1
  int v4; // eax@3
  double v5; // st7@5

  v2 = this;
  v3 = this->physobj;
  if ( !v3 || !(v3->state & 0x100000) )
  {
    v4 = this->draw_state;
    if ( _translucency == 1.0 )
    {
      this->draw_state = v4 | 1;
    }
    else
    {
      v5 = this->curTranslucency;
      this->draw_state = v4 & 0xFFFFFFFE;
      if ( v5 != _translucency )
      {
        this->curTranslucency = _translucency;
        if ( (unsigned __int8)CPhysicsPart::CurSettingsAreDefault(this) )
        {
          CPhysicsPart::RestoreMaterial(v2);
        }
        else if ( CPhysicsPart::CopyMaterial(v2) )
        {
          CMaterial::SetTranslucencySimple(v2->material, _translucency);
        }
      }
    }
  }
}

//----- (0050E700) --------------------------------------------------------  // acclient.c:315524
int __thiscall CPhysicsPart::SetPart(CPhysicsPart *this, IDClass<_tagDataID,32,0> gfxobj_id)
{
  unsigned int v2; // eax@1
  CPhysicsPart *v3; // esi@1
  int result; // eax@3
  GfxObjDegradeInfo *new_degrades; // [sp+0h] [bp-4h]@1

  new_degrades = (GfxObjDegradeInfo *)this;
  v2 = gfxobj_id.id;
  v3 = this;
  if ( gfxobj_id.id != stru_843C5C.id
    && (gfxobj_id.id = 0,
        new_degrades = 0,
        CPhysicsPart::LoadGfxObjArray((IDClass<_tagDataID,32,0>)v2, &new_degrades, (CGfxObj ***)&gfxobj_id)) )
  {
    CPhysicsPart::SetGfxObjArray(v3, new_degrades, (CGfxObj **)gfxobj_id.id);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0050E760) --------------------------------------------------------  // acclient.c:315550
CPhysicsPart *__cdecl CPhysicsPart::makePhysicsPart(IDClass<_tagDataID,32,0> gfxobj_id)
{
  CPhysicsPart *v1; // eax@1
  CPhysicsPart *v2; // eax@2
  CPhysicsPart *v3; // esi@2
  CPhysicsPart *result; // eax@3

  v1 = (CPhysicsPart *)operator new(0xE8u);
  if ( v1 && (CPhysicsPart::CPhysicsPart(v1), (v3 = v2) != 0) )
  {
    if ( !CPhysicsPart::SetPart(v2, gfxobj_id) )
    {
      CPhysicsPart::~CPhysicsPart(v3);
      operator delete(v3);
      v3 = 0;
    }
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006FB590) --------------------------------------------------------  // acclient.c:783879
void _E73_88()
{
  PixelFormatDesc::PixelFormatDesc(&stru_843C14, PFID_A8R8G8B8);
}

//----- (006FB5A0) --------------------------------------------------------  // acclient.c:783885
void sub_6FB5A0()
{
  LODWORD(dword_843C4C) = 1053364187;
}

//----- (006FB5B0) --------------------------------------------------------  // acclient.c:783891
void sub_6FB5B0()
{
  flt_843C50 = 1000.0 + 1.0;
}

//----- (006FB5D0) --------------------------------------------------------  // acclient.c:783897
void sub_6FB5D0()
{
  flt_843C54 = 24.0 * 8.0;
}

//----- (006FB5F0) --------------------------------------------------------  // acclient.c:783903
void sub_6FB5F0()
{
  flt_843C58 = 24.0 * 0.5;
}

//----- (006FB610) --------------------------------------------------------  // acclient.c:783909
int _E99_13()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_22, "Render.TextureFiltering");
  return atexit(sub_766AB0);
}

//----- (006FB630) --------------------------------------------------------  // acclient.c:783916
int _E102_14()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_22, "Render.LandscapeDetailTextures");
  return atexit(sub_766AE0);
}

//----- (006FB650) --------------------------------------------------------  // acclient.c:783923
int _E105_16()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_22, "Render.BuildingDetailTextures");
  return atexit(sub_766B10);
}

//----- (006FB670) --------------------------------------------------------  // acclient.c:783930
int _E108_67()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_22, "Render.FieldOfView");
  return atexit(sub_766B40);
}

//----- (006FB690) --------------------------------------------------------  // acclient.c:783937
int _E111_37()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_22, "Render.LandscapeTextureDetail");
  return atexit(sub_766B70);
}

//----- (006FB6B0) --------------------------------------------------------  // acclient.c:783944
int _E114_42()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_22, "Render.EnvironmentTextureDetail");
  return atexit(sub_766BA0);
}

//----- (006FB6D0) --------------------------------------------------------  // acclient.c:783951
int _E117_55()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_22, "Render.SceneryDrawDistance");
  return atexit(sub_766BD0);
}

//----- (006FB6F0) --------------------------------------------------------  // acclient.c:783958
int _E120_50()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_22, "Render.LandscapeDrawDistance");
  return atexit(sub_766C00);
}

//----- (006FB710) --------------------------------------------------------  // acclient.c:783965
int _E123_27()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_22, "Render.ScreenBrightness");
  return atexit(sub_766C30);
}

//----- (006FB730) --------------------------------------------------------  // acclient.c:783972
int _E126_33()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_22, "Render.AspectRatio");
  return atexit(sub_766C60);
}

//----- (006FB750) --------------------------------------------------------  // acclient.c:783979
int _E129_25()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_22, "Render.DisplayAdapter");
  return atexit(_E130_93);
}

//----- (006FB770) --------------------------------------------------------  // acclient.c:783986
int _E132_28()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_22, "Render.MaxHardwareClass");
  return atexit(_E133_87);
}

//----- (006FB790) --------------------------------------------------------  // acclient.c:783993
int _E135_31()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_22, "Render.AutomaticDegrades");
  return atexit(_E136_70);
}

//----- (006FB7B0) --------------------------------------------------------  // acclient.c:784000
int _E138_23()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_22, "Render.GraphicsPerformance");
  return atexit(_E139_70);
}

//----- (006FB7D0) --------------------------------------------------------  // acclient.c:784007
int _E141_23()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_22, "Render.DegradeDistance");
  return atexit(_E142_65);
}

//----- (006FB7F0) --------------------------------------------------------  // acclient.c:784014
int _E144_22()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_22, "Render.MultiPassAlpha");
  return atexit(_E145_67);
}

//----- (006FB810) --------------------------------------------------------  // acclient.c:784021
int _E147_19()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_22, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_843CA4, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_843CA8, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_843CAC, "Anisotropic");
  return atexit(_E148_65);
}

//----- (006FB860) --------------------------------------------------------  // acclient.c:784031
int _E150_22()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_22, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_843CB4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_843CB8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_843CBC, "High");
  PStringBase<char>::PStringBase<char>(&stru_843CC0, "VeryHigh");
  return atexit(_E151_63);
}

//----- (006FB8C0) --------------------------------------------------------  // acclient.c:784042
int _E153_20()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_22, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_843CC8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_843CCC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_843CD0, "High");
  PStringBase<char>::PStringBase<char>(&stru_843CD4, "VeryHigh");
  return atexit(_E154_64);
}

//----- (006FB920) --------------------------------------------------------  // acclient.c:784053
int _E156_22()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_22, "Low");
  PStringBase<char>::PStringBase<char>(&stru_843CDC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_843CE0, "High");
  return atexit(_E157_60);
}

//----- (006FB960) --------------------------------------------------------  // acclient.c:784062
int _E159_20()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_22, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_843CE8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_843CEC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_843CF0, "High");
  PStringBase<char>::PStringBase<char>(&stru_843CF4, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_843CF8, "Extreme");
  return atexit(_E160_63);
}

//----- (006FB9D0) --------------------------------------------------------  // acclient.c:784074
int _E162_22()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_22, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_843D00, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_843D04, "Wide");
  return atexit(_E163_56);
}

//----- (006FBA10) --------------------------------------------------------  // acclient.c:784083
int _E165_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_46, "None");
  return atexit(_E166_58);
}

//----- (006FBA30) --------------------------------------------------------  // acclient.c:784090
int _E168_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_46, "Speed");
  return atexit(_E169_57);
}

//----- (006FBA50) --------------------------------------------------------  // acclient.c:784097
int _E171_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_46, "Noise");
  return atexit(_E172_55);
}

//----- (006FBA70) --------------------------------------------------------  // acclient.c:784104
int _E174_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_46, "Sine");
  return atexit(_E175_52);
}

//----- (006FBA90) --------------------------------------------------------  // acclient.c:784111
int _E177_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_46, "Square");
  return atexit(_E178_52);
}

//----- (006FBAB0) --------------------------------------------------------  // acclient.c:784118
int _E180_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_46, "Bounce");
  return atexit(_E181_52);
}

//----- (006FBAD0) --------------------------------------------------------  // acclient.c:784125
int _E183_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_46, "Perlin");
  return atexit(_E184_49);
}

//----- (006FBAF0) --------------------------------------------------------  // acclient.c:784132
int _E186_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_46, "Fractal");
  return atexit(_E187_48);
}

//----- (006FBB10) --------------------------------------------------------  // acclient.c:784139
int _E189_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_46, "FrameLoop");
  return atexit(_E190_49);
}

//----- (006FBB30) --------------------------------------------------------  // acclient.c:784146
void _E192_14()
{
  dword_843D2C = 1024;
}

//----- (006FBB40) --------------------------------------------------------  // acclient.c:784152
void _E194_3()
{
  dword_843D30 = 0x7FFF;
}

//----- (006FBB50) --------------------------------------------------------  // acclient.c:784158
int _E196_15()
{
  const int result; // eax@1

  result = dword_843D2C;
  INITIAL_MAX_DATA_RATE_69 = dword_843D2C;
  return result;
}

//----- (006FBB60) --------------------------------------------------------  // acclient.c:784168
void _E198_12()
{
  DEFAULT_VIEW_RADIUS_96 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FBB80) --------------------------------------------------------  // acclient.c:784174
void _E200_1()
{
  MIN_QUANTUM_96 = 1.0 / 30.0;
}

//----- (006FBBA0) --------------------------------------------------------  // acclient.c:784180
void _E202_12()
{
  MAX_QUANTUM_96 = 1.0 / 5.0;
}

//----- (006FBBC0) --------------------------------------------------------  // acclient.c:784186
int sub_6FBBC0()
{
  return atexit(nullsub_1096);
}

//----- (00766AB0) --------------------------------------------------------  // acclient.c:893395
void __cdecl sub_766AB0()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766AE0) --------------------------------------------------------  // acclient.c:893408
void __cdecl sub_766AE0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766B10) --------------------------------------------------------  // acclient.c:893421
void __cdecl sub_766B10()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766B40) --------------------------------------------------------  // acclient.c:893434
void __cdecl sub_766B40()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766B70) --------------------------------------------------------  // acclient.c:893447
void __cdecl sub_766B70()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766BA0) --------------------------------------------------------  // acclient.c:893460
void __cdecl sub_766BA0()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766BD0) --------------------------------------------------------  // acclient.c:893473
void __cdecl sub_766BD0()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766C00) --------------------------------------------------------  // acclient.c:893486
void __cdecl sub_766C00()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766C30) --------------------------------------------------------  // acclient.c:893499
void __cdecl sub_766C30()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766C60) --------------------------------------------------------  // acclient.c:893512
void __cdecl sub_766C60()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766C90) --------------------------------------------------------  // acclient.c:893525
void __cdecl _E130_93()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766CC0) --------------------------------------------------------  // acclient.c:893538
void __cdecl _E133_87()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766CF0) --------------------------------------------------------  // acclient.c:893551
void __cdecl _E136_70()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766D20) --------------------------------------------------------  // acclient.c:893564
void __cdecl _E139_70()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766D50) --------------------------------------------------------  // acclient.c:893577
void __cdecl _E142_65()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766D80) --------------------------------------------------------  // acclient.c:893590
void __cdecl _E145_67()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766DB0) --------------------------------------------------------  // acclient.c:893603
void __cdecl _E148_65()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_22;
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

//----- (00766DF0) --------------------------------------------------------  // acclient.c:893628
void __cdecl _E151_63()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_22;
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

//----- (00766E30) --------------------------------------------------------  // acclient.c:893653
void __cdecl _E154_64()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_22;
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

//----- (00766E70) --------------------------------------------------------  // acclient.c:893678
void __cdecl _E157_60()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_22;
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

//----- (00766EB0) --------------------------------------------------------  // acclient.c:893703
void __cdecl _E160_63()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_22;
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

//----- (00766EF0) --------------------------------------------------------  // acclient.c:893728
void __cdecl _E163_56()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_46;
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

//----- (00766F30) --------------------------------------------------------  // acclient.c:893753
void __cdecl _E166_58()
{
  char *v0; // esi@1

  v0 = &waveform_None_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766F60) --------------------------------------------------------  // acclient.c:893766
void __cdecl _E169_57()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766F90) --------------------------------------------------------  // acclient.c:893779
void __cdecl _E172_55()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766FC0) --------------------------------------------------------  // acclient.c:893792
void __cdecl _E175_52()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766FF0) --------------------------------------------------------  // acclient.c:893805
void __cdecl _E178_52()
{
  char *v0; // esi@1

  v0 = &waveform_Square_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767020) --------------------------------------------------------  // acclient.c:893818
void __cdecl _E181_52()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767050) --------------------------------------------------------  // acclient.c:893831
void __cdecl _E184_49()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767080) --------------------------------------------------------  // acclient.c:893844
void __cdecl _E187_48()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007670B0) --------------------------------------------------------  // acclient.c:893857
void __cdecl _E190_49()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

