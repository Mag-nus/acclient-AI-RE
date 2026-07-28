/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPartArray
   Object     : PORTAL\cphysobj\CPartArray.obj
   Functions  : 90
   Addresses  : 00517C60 - 006FC630 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00517C60) --------------------------------------------------------  // acclient.c:325028
void __thiscall LIGHTLIST::set_frame(LIGHTLIST *this, Frame *offset)
{
  int v2; // esi@1
  char *v3; // eax@2
  char *v4; // ebx@2
  unsigned int i; // [sp+0h] [bp-4h]@1

  v2 = 0;
  i = 0;
  if ( this->num_lights )
  {
    do
    {
      v3 = (char *)&this->lightobj[v2].global_offset;
      v4 = (char *)&this->lightobj[v2].global_offset.m_fOrigin;
      *(_DWORD *)v4 = LODWORD(offset->m_fOrigin.x);
      *((_DWORD *)v4 + 1) = LODWORD(offset->m_fOrigin.y);
      *((_DWORD *)v4 + 2) = LODWORD(offset->m_fOrigin.z);
      *(_DWORD *)v3 = LODWORD(offset->qw);
      *((_DWORD *)v3 + 1) = LODWORD(offset->qx);
      *((_DWORD *)v3 + 2) = LODWORD(offset->qy);
      *((_DWORD *)v3 + 3) = LODWORD(offset->qz);
      *((_DWORD *)v3 + 4) = LODWORD(offset->m_fl2gv[0]);
      *((_DWORD *)v3 + 5) = LODWORD(offset->m_fl2gv[1]);
      *((_DWORD *)v3 + 6) = LODWORD(offset->m_fl2gv[2]);
      *((_DWORD *)v3 + 7) = LODWORD(offset->m_fl2gv[3]);
      *((_DWORD *)v3 + 8) = LODWORD(offset->m_fl2gv[4]);
      *((_DWORD *)v3 + 9) = LODWORD(offset->m_fl2gv[5]);
      *((_DWORD *)v3 + 10) = LODWORD(offset->m_fl2gv[6]);
      *((_DWORD *)v3 + 11) = LODWORD(offset->m_fl2gv[7]);
      *((_DWORD *)v3 + 12) = LODWORD(offset->m_fl2gv[8]);
      ++v2;
      ++i;
    }
    while ( i < this->num_lights );
  }
}

//----- (00517D10) --------------------------------------------------------  // acclient.c:325067
void __thiscall CPartArray::InitializeMotionTables(CPartArray *this)
{
  CPartArray *v1; // eax@1
  MotionTableManager *v2; // ecx@1

  v1 = this;
  v2 = this->motion_table_manager;
  if ( v2 )
    MotionTableManager::initialize_state(v2, &v1->sequence);
}

//----- (00517D30) --------------------------------------------------------  // acclient.c:325079
void __thiscall CPartArray::AnimationDone(CPartArray *this, int success)
{
  MotionTableManager *v2; // ecx@1

  v2 = this->motion_table_manager;
  if ( v2 )
    MotionTableManager::AnimationDone(v2, success);
}

//----- (00517D40) --------------------------------------------------------  // acclient.c:325089
int __thiscall CPartArray::HasAnims(CPartArray *this)
{
  return CSequence::has_anims(&this->sequence);
}

//----- (00517D50) --------------------------------------------------------  // acclient.c:325095
void __thiscall CPartArray::CheckForCompletedMotions(CPartArray *this)
{
  MotionTableManager *v1; // ecx@1

  v1 = this->motion_table_manager;
  if ( v1 )
    MotionTableManager::CheckForCompletedMotions(v1);
}

//----- (00517D60) --------------------------------------------------------  // acclient.c:325105
void __thiscall CPartArray::HandleMovement(CPartArray *this)
{
  MotionTableManager *v1; // ecx@1

  v1 = this->motion_table_manager;
  if ( v1 )
    MotionTableManager::UseTime(v1);
}

//----- (00517D70) --------------------------------------------------------  // acclient.c:325115
void __thiscall CPartArray::HandleEnterWorld(CPartArray *this)
{
  CPartArray *v1; // eax@1
  MotionTableManager *v2; // ecx@1

  v1 = this;
  v2 = this->motion_table_manager;
  if ( v2 )
    MotionTableManager::HandleEnterWorld(v2, &v1->sequence);
}

//----- (00517D90) --------------------------------------------------------  // acclient.c:325127
void __thiscall CPartArray::HandleExitWorld(CPartArray *this)
{
  CPartArray *v1; // eax@1
  MotionTableManager *v2; // ecx@1

  v1 = this;
  v2 = this->motion_table_manager;
  if ( v2 )
    MotionTableManager::HandleExitWorld(v2, &v1->sequence);
}

//----- (00517DB0) --------------------------------------------------------  // acclient.c:325139
void __thiscall CPartArray::Update(CPartArray *this, float quantum, Frame *offset_frame)
{
  CSequence::update(&this->sequence, quantum, offset_frame);
}

//----- (00517DD0) --------------------------------------------------------  // acclient.c:325145
void __thiscall CPartArray::SetCellID(CPartArray *this, const unsigned int cell_id)
{
  unsigned int v2; // edx@1
  CPhysicsPart *v3; // eax@2

  v2 = 0;
  if ( this->num_parts )
  {
    do
    {
      v3 = this->parts[v2];
      if ( v3 )
        v3->pos.objcell_id = cell_id;
      ++v2;
    }
    while ( v2 < this->num_parts );
  }
}

//----- (00517E00) --------------------------------------------------------  // acclient.c:325165
void __thiscall CPartArray::RemoveParts(CPartArray *this, CObjCell *obj_cell)
{
  CPartArray *v2; // edi@1
  unsigned int v3; // esi@1

  v2 = this;
  v3 = 0;
  if ( this->num_parts )
  {
    do
    {
      if ( v2->parts[v3] )
        obj_cell->vfptr->remove_part((CPartCell *)&obj_cell->vfptr, v2->parts[v3]);
      ++v3;
    }
    while ( v3 < v2->num_parts );
  }
}

//----- (00517E40) --------------------------------------------------------  // acclient.c:325185
void __thiscall CPartArray::AddPartsShadow(CPartArray *this, CObjCell *obj_cell, unsigned int num_shadow_parts)
{
  ClipPlaneList **v3; // ebx@1
  CPartArray *v4; // esi@1
  unsigned int v5; // edi@3
  CPhysicsPart *v6; // eax@4

  v3 = 0;
  v4 = this;
  if ( num_shadow_parts > 1 )
    v3 = obj_cell->clip_planes;
  v5 = 0;
  if ( this->num_parts )
  {
    do
    {
      v6 = v4->parts[v5];
      if ( v6 )
        obj_cell->vfptr->add_part(&obj_cell->vfptr, v6, v3, &obj_cell->pos.frame, num_shadow_parts);
      ++v5;
    }
    while ( v5 < v4->num_parts );
  }
}

//----- (00517EA0) --------------------------------------------------------  // acclient.c:325211
void __thiscall CPartArray::AddLightsToCell(CPartArray *this, CObjCell *cell)
{
  CPartArray *v2; // ebx@1
  LIGHTLIST *v3; // eax@2
  unsigned int v4; // esi@3
  int v5; // edi@4

  v2 = this;
  if ( cell )
  {
    v3 = this->lights;
    if ( v3 )
    {
      v4 = 0;
      if ( v3->num_lights )
      {
        v5 = 0;
        do
        {
          CObjCell::add_light(cell, &v3->lightobj[v5]);
          v3 = v2->lights;
          ++v4;
          ++v5;
        }
        while ( v4 < v3->num_lights );
      }
    }
  }
}

//----- (00517EF0) --------------------------------------------------------  // acclient.c:325242
void __thiscall CPartArray::RemoveLightsFromCell(CPartArray *this, CObjCell *cell)
{
  CPartArray *v2; // ebx@1
  LIGHTLIST *v3; // eax@2
  unsigned int v4; // esi@3
  int v5; // edi@4

  v2 = this;
  if ( cell )
  {
    v3 = this->lights;
    if ( v3 )
    {
      v4 = 0;
      if ( v3->num_lights )
      {
        v5 = 0;
        do
        {
          CObjCell::remove_light(cell, &v3->lightobj[v5]);
          v3 = v2->lights;
          ++v4;
          ++v5;
        }
        while ( v4 < v3->num_lights );
      }
    }
  }
}

//----- (00517F40) --------------------------------------------------------  // acclient.c:325273
unsigned int __thiscall CPartArray::InitParts(CPartArray *this)
{
  CPartArray *v1; // esi@1
  unsigned int v2; // eax@1
  void *v3; // eax@2
  unsigned int v4; // eax@3
  unsigned int v5; // edi@6
  unsigned int v6; // ecx@9
  unsigned int result; // eax@9
  unsigned int v8; // eax@13
  int v9; // ecx@14
  int v10; // edx@15
  int v11; // edi@15

  v1 = this;
  v2 = this->setup->num_parts;
  this->num_parts = v2;
  if ( v2 && (v3 = operator new[](4 * v2), (v1->parts = (CPhysicsPart **)v3) != 0) )
  {
    v4 = 0;
    if ( v1->num_parts )
    {
      do
        v1->parts[v4++] = 0;
      while ( v4 < v1->num_parts );
    }
    if ( !v1->setup->parts )
      return 1;
    v5 = 0;
    if ( v1->num_parts )
    {
      do
      {
        v1->parts[v5] = CPhysicsPart::makePhysicsPart(v1->setup->parts[v5]);
        if ( !v1->parts[v5] )
          break;
        ++v5;
      }
      while ( v5 < v1->num_parts );
    }
    v6 = v1->num_parts;
    result = 0;
    if ( v5 == v6 )
    {
      if ( v6 )
      {
        do
        {
          v1->parts[result]->physobj = v1->owner;
          v1->parts[result]->physobj_index = result;
          ++result;
        }
        while ( result < v1->num_parts );
      }
      if ( v1->setup->default_scale )
      {
        v8 = 0;
        if ( v1->num_parts )
        {
          v9 = 0;
          do
          {
            v10 = (int)&v1->setup->default_scale[v9];
            v11 = (int)&v1->parts[v8]->gfxobj_scale;
            *(_DWORD *)v11 = *(_DWORD *)v10;
            *(_DWORD *)(v11 + 4) = *(_DWORD *)(v10 + 4);
            *(_DWORD *)(v11 + 8) = *(_DWORD *)(v10 + 8);
            ++v8;
            ++v9;
          }
          while ( v8 < v1->num_parts );
        }
      }
      return 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00518060) --------------------------------------------------------  // acclient.c:325357
unsigned int __thiscall CPartArray::GetNumSphere(CPartArray *this)
{
  return this->setup->num_sphere;
}

//----- (00518070) --------------------------------------------------------  // acclient.c:325363
CSphere *__thiscall CPartArray::GetSphere(CPartArray *this)
{
  return this->setup->sphere;
}

//----- (00518080) --------------------------------------------------------  // acclient.c:325369
unsigned int __thiscall CPartArray::GetNumCylsphere(CPartArray *this)
{
  return this->setup->num_cylsphere;
}

//----- (00518090) --------------------------------------------------------  // acclient.c:325375
CCylSphere *__thiscall CPartArray::GetCylsphere(CPartArray *this)
{
  return this->setup->cylsphere;
}

//----- (005180A0) --------------------------------------------------------  // acclient.c:325381
double __thiscall CPartArray::GetRadius(CPartArray *this)
{
  return this->setup->radius * this->scale.z;
}

//----- (005180B0) --------------------------------------------------------  // acclient.c:325387
double __thiscall CPartArray::GetHeight(CPartArray *this)
{
  return this->setup->height * this->scale.z;
}

//----- (005180C0) --------------------------------------------------------  // acclient.c:325393
int __thiscall CPartArray::AllowsFreeHeading(CPartArray *this)
{
  return this->setup->allow_free_heading;
}

//----- (005180D0) --------------------------------------------------------  // acclient.c:325399
double __thiscall CPartArray::GetStepUpHeight(CPartArray *this)
{
  CSetup *v1; // eax@1
  double result; // st7@2

  v1 = this->setup;
  if ( v1 )
    result = v1->step_up_height * this->scale.z;
  else
    result = 0.0099999998;
  return result;
}

//----- (005180F0) --------------------------------------------------------  // acclient.c:325413
double __thiscall CPartArray::GetStepDownHeight(CPartArray *this)
{
  CSetup *v1; // eax@1
  double result; // st7@2

  v1 = this->setup;
  if ( v1 )
    result = v1->step_down_height * this->scale.z;
  else
    result = 0.0099999998;
  return result;
}

//----- (00518110) --------------------------------------------------------  // acclient.c:325427
int __thiscall CPartArray::CacheHasPhysicsBSP(CPartArray *this)
{
  unsigned int v1; // eax@1
  CPhysicsPart **v2; // edx@2
  int result; // eax@5

  v1 = 0;
  if ( this->num_parts )
  {
    v2 = this->parts;
    while ( !(*(*v2)->gfxobj)->physics_bsp )
    {
      ++v1;
      ++v2;
      if ( v1 >= this->num_parts )
        goto LABEL_5;
    }
    this->pa_state |= 0x10000u;
    result = 1;
  }
  else
  {
LABEL_5:
    this->pa_state &= 0xFFFEFFFF;
    result = 0;
  }
  return result;
}

//----- (00518160) --------------------------------------------------------  // acclient.c:325457
void __thiscall CPartArray::calc_cross_cells_static(CPartArray *this, CObjCell *cell, CELLARRAY *cell_array)
{
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))cell->vfptr[5].IUnknown_AddRef)(this->num_parts, this->parts, cell_array);
}

//----- (00518180) --------------------------------------------------------  // acclient.c:325463
signed int __thiscall CPartArray::FindObjCollisions(CPartArray *this, CTransition *transition)
{
  CPartArray *v2; // esi@1
  unsigned int v3; // edi@1
  signed int result; // eax@1
  CPhysicsPart *v5; // ecx@2

  v2 = this;
  v3 = 0;
  result = 1;
  if ( this->num_parts )
  {
    do
    {
      v5 = v2->parts[v3];
      if ( v5 )
      {
        result = CPhysicsPart::find_obj_collisions(v5, transition);
        if ( result != 1 )
          break;
      }
      ++v3;
    }
    while ( v3 < v2->num_parts );
  }
  return result;
}

//----- (005181C0) --------------------------------------------------------  // acclient.c:325492
int __thiscall CPartArray::InitPals(CPartArray *this)
{
  CPartArray *v1; // esi@1
  void *v2; // eax@2
  unsigned int v3; // eax@3

  v1 = this;
  if ( this->pals )
    return 1;
  v2 = operator new[](4 * this->num_parts);
  v1->pals = (Palette **)v2;
  if ( v2 )
  {
    v3 = 0;
    if ( v1->num_parts )
    {
      do
        v1->pals[v3++] = 0;
      while ( v3 < v1->num_parts );
    }
    return 1;
  }
  return 0;
}

//----- (00518210) --------------------------------------------------------  // acclient.c:325518
void __thiscall CPartArray::DestroyPals(CPartArray *this)
{
  CPartArray *v1; // esi@1
  unsigned int v2; // edi@2

  v1 = this;
  if ( this->pals )
  {
    v2 = 0;
    if ( this->num_parts )
    {
      do
      {
        if ( v1->pals[v2] )
        {
          Palette::releasePalette(v1->pals[v2]);
          v1->pals[v2] = 0;
        }
        ++v2;
      }
      while ( v2 < v1->num_parts );
    }
    operator delete[](v1->pals);
    v1->pals = 0;
  }
}

//----- (00518260) --------------------------------------------------------  // acclient.c:325546
void __thiscall CPartArray::UpdateViewerDistance(CPartArray *this)
{
  CPartArray *v1; // edi@1
  unsigned int v2; // esi@1
  CPhysicsPart *v3; // ecx@2

  v1 = this;
  v2 = 0;
  if ( this->num_parts )
  {
    do
    {
      v3 = v1->parts[v2];
      if ( v3 )
        CPhysicsPart::UpdateViewerDistance(v3);
      ++v2;
    }
    while ( v2 < v1->num_parts );
  }
}

//----- (00518290) --------------------------------------------------------  // acclient.c:325568
void __thiscall CPartArray::UpdateViewerDistance(CPartArray *this, float _CYpt, AC1Legacy::Vector3 *_viewer_heading)
{
  CPartArray *v3; // edi@1
  unsigned int v4; // esi@1
  CPhysicsPart *v5; // ecx@2

  v3 = this;
  v4 = 0;
  if ( this->num_parts )
  {
    do
    {
      v5 = v3->parts[v4];
      if ( v5 )
        CPhysicsPart::UpdateViewerDistance(v5, _CYpt, _viewer_heading);
      ++v4;
    }
    while ( v4 < v3->num_parts );
  }
}

//----- (005182D0) --------------------------------------------------------  // acclient.c:325590
void __thiscall CPartArray::Draw(CPartArray *this, Position *p)
{
  CPartArray *v2; // edi@1
  unsigned int v3; // esi@1
  CPhysicsPart *v4; // ecx@2

  v2 = this;
  v3 = 0;
  if ( this->num_parts )
  {
    do
    {
      v4 = v2->parts[v3];
      if ( v4 )
        CPhysicsPart::Draw(v4, 0);
      ++v3;
    }
    while ( v3 < v2->num_parts );
  }
}

//----- (00518300) --------------------------------------------------------  // acclient.c:325612
void __thiscall CPartArray::SetNoDrawInternal(CPartArray *this, int no_draw)
{
  CPartArray *v2; // edi@1
  unsigned int v3; // esi@2
  CPhysicsPart *v4; // ecx@3

  v2 = this;
  if ( this->setup )
  {
    v3 = 0;
    if ( this->num_parts )
    {
      do
      {
        v4 = v2->parts[v3];
        if ( v4 )
          CPhysicsPart::SetNoDraw(v4, no_draw);
        ++v3;
      }
      while ( v3 < v2->num_parts );
    }
  }
}

//----- (00518340) --------------------------------------------------------  // acclient.c:325637
void __thiscall CPartArray::SetTranslucencyInternal(CPartArray *this, float _translucency)
{
  CPartArray *v2; // edi@1
  unsigned int v3; // esi@2
  CPhysicsPart *v4; // ecx@3

  v2 = this;
  if ( this->setup )
  {
    v3 = 0;
    if ( this->num_parts )
    {
      do
      {
        v4 = v2->parts[v3];
        if ( v4 )
          CPhysicsPart::SetTranslucency(v4, _translucency);
        ++v3;
      }
      while ( v3 < v2->num_parts );
    }
  }
}

//----- (00518380) --------------------------------------------------------  // acclient.c:325662
void __thiscall CPartArray::SetPartTranslucencyInternal(CPartArray *this, unsigned int part_index, float _translucency)
{
  CPhysicsPart *v3; // ecx@3

  if ( this->setup && part_index < this->num_parts )
  {
    v3 = this->parts[part_index];
    if ( v3 )
      CPhysicsPart::SetTranslucency(v3, _translucency);
  }
}

//----- (005183B0) --------------------------------------------------------  // acclient.c:325675
void __thiscall CPartArray::SetLuminosityInternal(CPartArray *this, float lumi)
{
  CPartArray *v2; // edi@1
  unsigned int v3; // esi@2
  CPhysicsPart *v4; // ecx@3

  v2 = this;
  if ( this->setup )
  {
    v3 = 0;
    if ( this->num_parts )
    {
      do
      {
        v4 = v2->parts[v3];
        if ( v4 )
          CPhysicsPart::SetLuminosity(v4, lumi);
        ++v3;
      }
      while ( v3 < v2->num_parts );
    }
  }
}

//----- (005183F0) --------------------------------------------------------  // acclient.c:325700
void __thiscall CPartArray::SetPartLuminosityInternal(CPartArray *this, unsigned int part_index, float lumi)
{
  CPhysicsPart *v3; // ecx@3

  if ( this->setup && part_index < this->num_parts )
  {
    v3 = this->parts[part_index];
    if ( v3 )
      CPhysicsPart::SetLuminosity(v3, lumi);
  }
}

//----- (00518420) --------------------------------------------------------  // acclient.c:325713
void __thiscall CPartArray::SetDiffusionInternal(CPartArray *this, float diff)
{
  CPartArray *v2; // edi@1
  unsigned int v3; // esi@2
  CPhysicsPart *v4; // ecx@3

  v2 = this;
  if ( this->setup )
  {
    v3 = 0;
    if ( this->num_parts )
    {
      do
      {
        v4 = v2->parts[v3];
        if ( v4 )
          CPhysicsPart::SetDiffusion(v4, diff);
        ++v3;
      }
      while ( v3 < v2->num_parts );
    }
  }
}

//----- (00518460) --------------------------------------------------------  // acclient.c:325738
void __thiscall CPartArray::SetPartDiffusionInternal(CPartArray *this, unsigned int part_index, float diff)
{
  CPhysicsPart *v3; // ecx@3

  if ( this->setup && part_index < this->num_parts )
  {
    v3 = this->parts[part_index];
    if ( v3 )
      CPhysicsPart::SetDiffusion(v3, diff);
  }
}

//----- (00518490) --------------------------------------------------------  // acclient.c:325751
void __thiscall CPartArray::SetLightingInternal(CPartArray *this, float luminosity, float diffuse)
{
  CPartArray *v3; // edi@1
  unsigned int v4; // esi@2
  CPhysicsPart *v5; // ecx@3

  v3 = this;
  if ( this->setup )
  {
    v4 = 0;
    if ( this->num_parts )
    {
      do
      {
        v5 = v3->parts[v4];
        if ( v5 )
          CPhysicsPart::SetLighting(v5, luminosity, diffuse);
        ++v4;
      }
      while ( v4 < v3->num_parts );
    }
  }
}

//----- (005184D0) --------------------------------------------------------  // acclient.c:325776
int __thiscall CPartArray::SetPartLightingInternal(CPartArray *this, unsigned int part_index, float luminosity, float diffuse)
{
  int result; // eax@3
  CPhysicsPart *v5; // ecx@4

  if ( this->setup && part_index < this->num_parts )
  {
    v5 = this->parts[part_index];
    if ( v5 )
      CPhysicsPart::SetLighting(v5, luminosity, diffuse);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00518510) --------------------------------------------------------  // acclient.c:325796
void __thiscall CPartArray::RestoreLightingInternal(CPartArray *this)
{
  CPartArray *v1; // edi@1
  unsigned int v2; // esi@2
  CPhysicsPart *v3; // ecx@3

  v1 = this;
  if ( this->setup )
  {
    v2 = 0;
    if ( this->num_parts )
    {
      do
      {
        v3 = v1->parts[v2];
        if ( v3 )
          CPhysicsPart::RestoreLighting(v3);
        ++v2;
      }
      while ( v2 < v1->num_parts );
    }
  }
}

//----- (00518540) --------------------------------------------------------  // acclient.c:325821
int __thiscall CPartArray::InitObjDescChanges(CPartArray *this)
{
  CPartArray *v1; // esi@1
  signed int v2; // ebx@1
  unsigned int v3; // edi@2
  CPhysicsPart *v4; // ecx@3

  v1 = this;
  v2 = 0;
  if ( this->setup )
  {
    v3 = 0;
    if ( this->num_parts )
    {
      do
      {
        v4 = v1->parts[v3];
        if ( v4 && CPhysicsPart::InitObjDescChanges(v4) )
          v2 = 1;
        ++v3;
      }
      while ( v3 < v1->num_parts );
    }
  }
  return v2;
}

//----- (00518580) --------------------------------------------------------  // acclient.c:325849
int __thiscall CPartArray::SetPart(CPartArray *this, AnimPartChange *_changes)
{
  CPartArray *v2; // edi@1
  signed int v3; // ebx@1
  AnimPartChange *i; // esi@2
  unsigned int v5; // eax@3
  CPhysicsPart *v6; // eax@4
  int result; // eax@8

  v2 = this;
  v3 = 1;
  if ( this->setup )
  {
    for ( i = _changes; i; i = i->next )
    {
      v5 = i->part_index;
      if ( v5 < v2->num_parts )
      {
        v6 = v2->parts[v5];
        if ( v6 )
        {
          if ( CPhysicsPart::SetPart(v6, i->part_id) )
            continue;
        }
      }
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

//----- (005185E0) --------------------------------------------------------  // acclient.c:325886
int __thiscall CPartArray::SetTextureMap(CPartArray *this, TextureMapChange *_changes)
{
  CPartArray *v2; // edi@1
  signed int v3; // ebx@1
  TextureMapChange *i; // esi@2
  unsigned int v5; // eax@3
  CPhysicsPart *v6; // ecx@4
  int result; // eax@8

  v2 = this;
  v3 = 1;
  if ( this->setup )
  {
    for ( i = _changes; i; i = i->next )
    {
      v5 = i->part_index;
      if ( v5 < v2->num_parts )
      {
        v6 = v2->parts[v5];
        if ( v6 )
        {
          if ( CPhysicsPart::SetTextureMap(v6, i->old_tex_id, i->new_tex_id) )
            continue;
        }
      }
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

//----- (00518640) --------------------------------------------------------  // acclient.c:325923
void __thiscall LIGHTLIST::LIGHTLIST(LIGHTLIST *this, unsigned int _num_lights)
{
  unsigned int v2; // esi@1
  LIGHTLIST *v3; // ebp@1
  void *v4; // eax@1
  int v5; // eax@2
  unsigned int v6; // ecx@2
  int v7; // ebx@2
  int v8; // esi@3
  int v9; // ebp@3
  LIGHTLIST *v10; // [sp+Ch] [bp-4h]@1
  unsigned int _num_lightsa; // [sp+14h] [bp+4h]@2

  v2 = _num_lights;
  v3 = this;
  v10 = this;
  this->num_lights = _num_lights;
  v4 = operator new[](72 * _num_lights + 4);
  if ( v4 )
  {
    v5 = (int)((char *)v4 + 4);
    *(_DWORD *)(v5 - 4) = _num_lights;
    v6 = _num_lights - 1;
    _num_lightsa = v5;
    v7 = v5;
    if ( ((v2 - 1) & 0x80000000) == 0 )
    {
      v8 = v5 + 64;
      v9 = v6 + 1;
      do
      {
        *(_DWORD *)v7 = 0;
        *(_DWORD *)(v8 - 60) = 1065353216;
        *(_DWORD *)(v8 - 56) = 0;
        *(_DWORD *)(v8 - 52) = 0;
        *(_DWORD *)(v8 - 48) = 0;
        *(_DWORD *)(v8 - 8) = 0;
        *(_DWORD *)(v8 - 4) = 0;
        *(_DWORD *)v8 = 0;
        Frame::cache((Frame *)(v8 - 60));
        *(_DWORD *)(v8 + 4) = 0;
        v7 += 72;
        v8 += 72;
        --v9;
      }
      while ( v9 );
      v3 = v10;
      v5 = _num_lightsa;
    }
    v3->lightobj = (LIGHTOBJ *)v5;
  }
  else
  {
    v3->lightobj = 0;
  }
}

//----- (005186E0) --------------------------------------------------------  // acclient.c:325981
int __thiscall CPartArray::SetMotionTableID(CPartArray *this, IDClass<_tagDataID,32,0> mtable_id)
{
  unsigned int v2; // ebx@1
  CPartArray *v3; // esi@1
  MotionTableManager *v4; // ecx@1
  void *v5; // edi@3
  TurbineChatBlob *v6; // eax@7

  v2 = mtable_id.id;
  v3 = this;
  v4 = this->motion_table_manager;
  if ( v4 )
  {
    if ( MotionTableManager::GetMotionTableID(v4, &mtable_id)->id == v2 )
      return 1;
    v5 = v3->motion_table_manager;
    if ( v5 )
    {
      MotionTableManager::~MotionTableManager(v3->motion_table_manager);
      operator delete(v5);
    }
    v3->motion_table_manager = 0;
  }
  if ( !v2 )
    return 1;
  v6 = (TurbineChatBlob *)MotionTableManager::Create((IDClass<_tagDataID,32,0>)v2);
  v3->motion_table_manager = (MotionTableManager *)v6;
  if ( v6 )
  {
    TurbineChatBlob::SetTargetID(v6, (unsigned int)v3->owner);
    return 1;
  }
  return 0;
}

//----- (00518750) --------------------------------------------------------  // acclient.c:326017
signed int __thiscall CPartArray::DoInterpretedMotion(CPartArray *this, unsigned int motion, MovementParameters *params)
{
  CPartArray *v3; // esi@1
  signed int result; // eax@2
  MotionTableManager *v5; // ecx@3
  MovementStruct mvs; // [sp+4h] [bp-64h]@3

  v3 = this;
  if ( this->motion_table_manager )
  {
    mvs.type = 0;
    mvs.pos.vfptr = (PackObjVtbl *)&Position::vftable;
    mvs.pos.objcell_id = 0;
    LODWORD(mvs.pos.frame.qw) = 1065353216;
    LODWORD(mvs.pos.frame.qx) = 0;
    LODWORD(mvs.pos.frame.qy) = 0;
    LODWORD(mvs.pos.frame.qz) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.x) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.y) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.z) = 0;
    Frame::cache(&mvs.pos.frame);
    mvs.motion = motion;
    mvs.params = params;
    v5 = v3->motion_table_manager;
    mvs.type = 2;
    result = MotionTableManager::PerformMovement(v5, &mvs, &v3->sequence);
  }
  else
  {
    result = 7;
  }
  return result;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (005187F0) --------------------------------------------------------  // acclient.c:326053
signed int __thiscall CPartArray::StopInterpretedMotion(CPartArray *this, unsigned int motion, MovementParameters *params)
{
  CPartArray *v3; // esi@1
  signed int result; // eax@2
  MotionTableManager *v5; // ecx@3
  MovementStruct mvs; // [sp+4h] [bp-64h]@3

  v3 = this;
  if ( this->motion_table_manager )
  {
    mvs.type = 0;
    mvs.pos.vfptr = (PackObjVtbl *)&Position::vftable;
    mvs.pos.objcell_id = 0;
    LODWORD(mvs.pos.frame.qw) = 1065353216;
    LODWORD(mvs.pos.frame.qx) = 0;
    LODWORD(mvs.pos.frame.qy) = 0;
    LODWORD(mvs.pos.frame.qz) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.x) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.y) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.z) = 0;
    Frame::cache(&mvs.pos.frame);
    mvs.motion = motion;
    mvs.params = params;
    v5 = v3->motion_table_manager;
    mvs.type = 4;
    result = MotionTableManager::PerformMovement(v5, &mvs, &v3->sequence);
  }
  else
  {
    result = 7;
  }
  return result;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00518890) --------------------------------------------------------  // acclient.c:326089
signed int __thiscall CPartArray::StopCompletelyInternal(CPartArray *this)
{
  CPartArray *v1; // esi@1
  signed int result; // eax@2
  MotionTableManager *v3; // ecx@3
  MovementStruct mvs; // [sp+4h] [bp-64h]@3

  v1 = this;
  if ( this->motion_table_manager )
  {
    mvs.type = 0;
    mvs.pos.vfptr = (PackObjVtbl *)&Position::vftable;
    mvs.pos.objcell_id = 0;
    LODWORD(mvs.pos.frame.qw) = 1065353216;
    LODWORD(mvs.pos.frame.qx) = 0;
    LODWORD(mvs.pos.frame.qy) = 0;
    LODWORD(mvs.pos.frame.qz) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.x) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.y) = 0;
    LODWORD(mvs.pos.frame.m_fOrigin.z) = 0;
    Frame::cache(&mvs.pos.frame);
    v3 = v1->motion_table_manager;
    mvs.type = 5;
    result = MotionTableManager::PerformMovement(v3, &mvs, &v1->sequence);
  }
  else
  {
    result = 7;
  }
  return result;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00518920) --------------------------------------------------------  // acclient.c:326123
void __thiscall CPartArray::DestroyParts(CPartArray *this)
{
  CPartArray *v1; // esi@1
  unsigned int v2; // ebx@2
  CPhysicsPart **v3; // eax@3
  void *v4; // edi@3

  v1 = this;
  if ( this->parts )
  {
    v2 = 0;
    if ( this->num_parts )
    {
      do
      {
        v3 = v1->parts;
        v4 = v3[v2];
        if ( v4 )
        {
          CPhysicsPart::~CPhysicsPart(v3[v2]);
          operator delete(v4);
          v1->parts[v2] = 0;
        }
        ++v2;
      }
      while ( v2 < v1->num_parts );
    }
    operator delete[](v1->parts);
    v1->parts = 0;
  }
  v1->num_parts = 0;
}

//----- (00518980) --------------------------------------------------------  // acclient.c:326157
void __thiscall CPartArray::InitDefaults(CPartArray *this)
{
  CPartArray *v1; // esi@1
  CPhysicsObj *v2; // ecx@3
  AnimData anim_data; // [sp+4h] [bp-14h]@2

  v1 = this;
  if ( this->setup->default_anim_id.id )
  {
    CSequence::clear_animations(&this->sequence);
    AnimData::AnimData(&anim_data);
    anim_data.anim_id.id = v1->setup->default_anim_id.id;
    anim_data.low_frame = 0;
    anim_data.high_frame = -1;
    LODWORD(anim_data.framerate) = 1106247680;
    CSequence::append_animation(&v1->sequence, &anim_data);
    WeenieDesc::~WeenieDesc((WeenieDesc *)&anim_data);
  }
  v2 = v1->owner;
  if ( v2 )
    CPhysicsObj::InitDefaults(v2, v1->setup);
}

//----- (00518A00) --------------------------------------------------------  // acclient.c:326181
int __thiscall CPartArray::SetScaleInternal(CPartArray *this, AC1Legacy::Vector3 *new_scale)
{
  char *v2; // edi@1
  unsigned int v3; // ebx@1
  int v4; // esi@2
  CPhysicsPart *v5; // edx@3
  AC1Legacy::Vector3 *v6; // eax@4
  int v7; // edx@4
  float v8; // ST24_4@5
  double v9; // st7@5
  float v10; // ST10_4@5
  float v11; // ST14_4@5
  float v12; // eax@5

  v2 = (char *)&this->scale;
  this->scale = *new_scale;
  v3 = 0;
  if ( this->num_parts )
  {
    v4 = 0;
    do
    {
      v5 = this->parts[v3];
      if ( v5 )
      {
        v6 = this->setup->default_scale;
        v7 = (int)&v5->gfxobj_scale;
        if ( v6 )
        {
          v8 = v6[v4].z * this->scale.z;
          v9 = v6[v4].y * this->scale.y;
          v10 = v6[v4].x * *(float *)v2;
          *(float *)v7 = v10;
          v11 = v9;
          *(float *)(v7 + 4) = v11;
          v12 = v8;
        }
        else
        {
          *(_DWORD *)v7 = *(_DWORD *)v2;
          *(_DWORD *)(v7 + 4) = LODWORD(this->scale.y);
          v12 = this->scale.z;
        }
        *(float *)(v7 + 8) = v12;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->num_parts );
  }
  return 1;
}

//----- (00518AB0) --------------------------------------------------------  // acclient.c:326235
IDClass<_tagDataID,32,0> *__thiscall CPartArray::GetSetupID(CPartArray *this, IDClass<_tagDataID,32,0> *result)
{
  IDClass<_tagDataID,32,0> *v2; // eax@1

  v2 = result;
  result->id = this->setup->m_DID.id;
  return v2;
}

//----- (00518AC0) --------------------------------------------------------  // acclient.c:326245
IDClass<_tagDataID,32,0> *__thiscall CPartArray::GetDataID(CPartArray *this, IDClass<_tagDataID,32,0> *result)
{
  unsigned int v2; // edx@1
  IDClass<_tagDataID,32,0> *v3; // eax@4

  v2 = this->setup->m_DID.id;
  if ( v2 != stru_843FD0.id )
    goto LABEL_4;
  if ( this->num_parts == 1 )
  {
    v2 = (*(*this->parts)->gfxobj)->m_DID.id;
LABEL_4:
    v3 = result;
    result->id = v2;
    return v3;
  }
  v3 = result;
  result->id = stru_843FD0.id;
  return v3;
}

//----- (00518B00) --------------------------------------------------------  // acclient.c:326267
CSphere *__thiscall CPartArray::GetSortingSphere(CPartArray *this)
{
  CPartArray *v1; // esi@1
  CSetup *v2; // eax@3
  CSphere *result; // eax@4

  v1 = this;
  if ( !(_S118_54 & 1) )
  {
    _S118_54 |= 1u;
    LODWORD(default_sorting_sphere.center.x) = 0;
    LODWORD(default_sorting_sphere.center.y) = 0;
    LODWORD(default_sorting_sphere.center.z) = 0;
    LODWORD(default_sorting_sphere.radius) = 0;
    atexit(_E119_83);
  }
  v2 = v1->setup;
  if ( v2 )
    result = &v2->sorting_sphere;
  else
    result = &default_sorting_sphere;
  return result;
}

//----- (00518B80) --------------------------------------------------------  // acclient.c:326292
int __thiscall CPartArray::GetSelectionSphere(CPartArray *this, CSphere *selection_sphere)
{
  CSetup *v2; // eax@1
  float v3; // ST18_4@2
  float v4; // ST04_4@2
  float v5; // ST08_4@2
  int result; // eax@2

  v2 = this->setup;
  if ( v2 )
  {
    v3 = this->scale.z * v2->selection_sphere.center.z;
    v4 = this->scale.x * v2->selection_sphere.center.x;
    v5 = this->scale.y * v2->selection_sphere.center.y;
    selection_sphere->center.x = v4;
    selection_sphere->center.y = v5;
    selection_sphere->center.z = v3;
    selection_sphere->radius = this->setup->selection_sphere.radius * this->scale.z;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00518C00) --------------------------------------------------------  // acclient.c:326320
int __thiscall CPartArray::InitLights(CPartArray *this)
{
  CPartArray *v1; // esi@1
  LIGHTLIST *v2; // eax@3
  LIGHTLIST *v3; // eax@4
  unsigned int v4; // ebx@6
  int v5; // edi@7
  int v6; // edx@7
  int v7; // ecx@8
  int v8; // eax@8

  v1 = this;
  if ( this->owner && this->setup->num_lights )
  {
    v2 = (LIGHTLIST *)operator new(8u);
    if ( v2 )
      LIGHTLIST::LIGHTLIST(v2, v1->setup->num_lights);
    else
      v3 = 0;
    v1->lights = v3;
    v4 = 0;
    if ( v3->num_lights )
    {
      v5 = 0;
      v6 = 0;
      do
      {
        v7 = v1->owner->state & 1;
        v8 = (int)&v1->lights->lightobj[v6];
        *(_DWORD *)v8 = &v1->setup->lights[v5];
        if ( v7 )
          *(_DWORD *)(v8 + 68) |= 1u;
        ++v4;
        ++v6;
        ++v5;
      }
      while ( v4 < v1->lights->num_lights );
    }
    CPartArray::AddLightsToCell(v1, v1->owner->cell);
  }
  return 1;
}

//----- (00518CB0) --------------------------------------------------------  // acclient.c:326364
void __thiscall CPartArray::SetTextureVelocityInternal(CPartArray *this, float du, float dv)
{
  CPartArray *v3; // edi@1
  unsigned int v4; // esi@1
  CPhysicsPart *v5; // eax@2

  v3 = this;
  v4 = 0;
  if ( this->num_parts )
  {
    do
    {
      v5 = v3->parts[v4];
      if ( v5 )
        CPhysics::AddGfxVelocity((*v5->gfxobj)->m_DID, du, dv);
      ++v4;
    }
    while ( v4 < v3->num_parts );
  }
}

//----- (00518D00) --------------------------------------------------------  // acclient.c:326386
void __thiscall CPartArray::SetPartTextureVelocityInternal(CPartArray *this, unsigned int part_index, float du, float dv)
{
  CPhysicsPart *v4; // eax@2

  if ( part_index < this->num_parts )
  {
    v4 = this->parts[part_index];
    if ( v4 )
      CPhysics::AddGfxVelocity((*v4->gfxobj)->m_DID, du, dv);
  }
}

//----- (00518D40) --------------------------------------------------------  // acclient.c:326399
int __thiscall CPartArray::MorphToExistingObject(CPartArray *this, CPartArray *pObj)
{
  CPartArray *v2; // esi@1
  CSetup *v3; // ecx@1
  int v4; // edx@3
  unsigned int v5; // eax@3
  int v6; // edi@3
  Palette **v7; // eax@4
  Palette *v8; // ecx@5

  v2 = this;
  CPartArray::DestroyParts(this);
  v3 = pObj->setup;
  v2->setup = v3;
  if ( v3 )
    ((void (*)(void))v3->vfptr->AddRef)();
  v4 = (int)&v2->scale;
  *(_DWORD *)v4 = LODWORD(pObj->scale.x);
  *(_DWORD *)(v4 + 4) = LODWORD(pObj->scale.y);
  *(_DWORD *)(v4 + 8) = LODWORD(pObj->scale.z);
  v5 = pObj->num_parts;
  v2->num_parts = v5;
  v2->parts = (CPhysicsPart **)operator new[](4 * v5);
  CPartArray::InitPals(v2);
  v6 = 0;
  if ( v2->num_parts )
  {
    do
    {
      v2->parts[v6] = CPhysicsPart::makePhysicsPart(pObj->parts[v6]);
      v2->parts[v6]->physobj = v2->owner;
      v2->parts[v6]->physobj_index = v6;
      v7 = pObj->pals;
      if ( v7 )
      {
        v2->pals[v6] = v7[v6];
        v8 = v2->pals[v6];
        if ( v8 )
          ((void (*)(void))v8->vfptr->AddRef)();
      }
      ++v6;
    }
    while ( v6 < v2->num_parts );
  }
  return 1;
}

//----- (00518E10) --------------------------------------------------------  // acclient.c:326447
int __thiscall CPartArray::SetPalette(CPartArray *this, IDClass<_tagDataID,32,0> palID, Subpalette *subs)
{
  CPartArray *v3; // esi@1
  unsigned int v5; // ebp@3
  unsigned int v6; // edi@5
  Subpalette *v7; // ebx@6
  Palette *v8; // ecx@7
  int v9; // eax@8
  unsigned int v10; // eax@13
  unsigned int v11; // ebx@14
  CPhysicsPart **v12; // eax@15
  CPhysicsPart *v13; // ecx@15
  CPhysicsPart **v14; // eax@15

  v3 = this;
  if ( !this->setup )
    return 0;
  CPartArray::InitPals(this);
  v5 = palID.id;
  if ( palID.id == stru_843FD0.id )
    return 0;
  v6 = 0;
  if ( v3->num_parts )
  {
    v7 = subs;
    while ( 1 )
    {
      v8 = v3->pals[v6];
      if ( !v8 )
        break;
      if ( v8->m_DID.id == v5 )
      {
        v9 = Palette::Modify(v8, v7);
LABEL_11:
        if ( v9 )
          goto LABEL_13;
      }
      ++v6;
      if ( v6 >= v3->num_parts )
        goto LABEL_13;
    }
    v3->pals[v6] = (Palette *)Palette::makeModifiedPalette((IDClass<_tagDataID,32,0>)v5, v7);
    v9 = (int)v3->pals[v6];
    goto LABEL_11;
  }
LABEL_13:
  v10 = v3->num_parts;
  if ( v6 == v10 )
    return 0;
  v11 = 0;
  if ( v10 )
  {
    do
    {
      v12 = v3->parts;
      v13 = v12[v11];
      v14 = &v12[v11];
      if ( v13 && v3->pals[v6] && CPhysicsPart::GetOriginalPaletteID(*v14, &palID)->id == v5 )
        CPhysicsPart::UsePalette(v3->parts[v11], v3->pals[v6]);
      ++v11;
    }
    while ( v11 < v3->num_parts );
  }
  return 1;
}

//----- (00518EF0) --------------------------------------------------------  // acclient.c:326514
void __thiscall CPartArray::GetBoundingBox(CPartArray *this, BBox *o_bbox)
{
  CPartArray *v2; // edi@1
  unsigned int v3; // esi@1
  CPhysicsPart *v4; // ecx@2
  BBox *v5; // eax@3
  float v6; // edx@3
  CPhysicsPart **v7; // eax@3
  int v8; // ecx@3
  int v9; // eax@3
  BBox part; // [sp+8h] [bp-18h]@3

  v2 = this;
  v3 = 0;
  if ( this->num_parts )
  {
    do
    {
      v4 = v2->parts[v3];
      if ( v4 )
      {
        v5 = CPhysicsPart::GetBoundingBox(v4);
        part.m_vMin.x = v5->m_vMin.x;
        part.m_vMin.y = v5->m_vMin.y;
        part.m_vMin.z = v5->m_vMin.z;
        part.m_vMax.x = v5->m_vMax.x;
        part.m_vMax.y = v5->m_vMax.y;
        v6 = v5->m_vMax.z;
        v7 = v2->parts;
        part.m_vMax.z = v6;
        v8 = (int)&v7[v3];
        v9 = *(_DWORD *)v8 + 36;
        part.m_vMin.x = part.m_vMin.x * *(float *)v9;
        part.m_vMin.y = part.m_vMin.y * *(float *)(v9 + 4);
        part.m_vMin.z = part.m_vMin.z * *(float *)(v9 + 8);
        part.m_vMax.x = part.m_vMax.x * *(float *)v9;
        part.m_vMax.y = part.m_vMax.y * *(float *)(v9 + 4);
        part.m_vMax.z = v6 * *(float *)(v9 + 8);
        BBox::ConvertToGlobal(&part, (Position *)(*(_DWORD *)v8 + 48));
        BBox::BuildBoundingBox(&part, o_bbox);
      }
      ++v3;
    }
    while ( v3 < v2->num_parts );
  }
}

//----- (00518FD0) --------------------------------------------------------  // acclient.c:326562
void __thiscall Frame::combine(Frame *this, Frame *_f1, AFrame *_f2, AC1Legacy::Vector3 *scale)
{
  AFrame *v4; // edx@1
  double v5; // st7@1
  double v6; // st6@1
  char *v7; // esi@1
  double v8; // st5@1
  Frame *v9; // eax@1
  float v10; // ST18_4@1
  float v11; // ST1C_4@1
  double v12; // st7@1
  float v13; // ST20_4@1
  float new_qz; // ST0C_4@1
  float new_qy; // ST08_4@1
  float new_qx; // ST04_4@1
  float new_qw; // ST00_4@1

  v4 = _f2;
  v5 = _f2->m_fOrigin.x * scale->x;
  v6 = _f2->m_fOrigin.y * scale->y;
  v7 = (char *)&this->m_fOrigin;
  v8 = _f2->m_fOrigin.z * scale->z;
  v9 = _f1;
  v10 = v5 * _f1->m_fl2gv[0] + v8 * _f1->m_fl2gv[6] + v6 * _f1->m_fl2gv[3] + _f1->m_fOrigin.x;
  v11 = v5 * _f1->m_fl2gv[1] + v8 * _f1->m_fl2gv[7] + v6 * _f1->m_fl2gv[4] + _f1->m_fOrigin.y;
  v12 = v5 * _f1->m_fl2gv[2] + v8 * _f1->m_fl2gv[8] + v6 * _f1->m_fl2gv[5] + _f1->m_fOrigin.z;
  *(float *)v7 = v10;
  *((float *)v7 + 1) = v11;
  v13 = v12;
  *((float *)v7 + 2) = v13;
  new_qz = v9->qw * v4->qz + v9->qx * v4->qy - v4->qx * v9->qy + v4->qw * v9->qz;
  new_qy = v9->qw * v4->qy - v9->qx * v4->qz + v4->qx * v9->qz + v4->qw * v9->qy;
  new_qx = v4->qx * v9->qw + v4->qw * v9->qx + v4->qz * v9->qy - v4->qy * v9->qz;
  new_qw = v4->qw * v9->qw - v4->qx * v9->qx - v4->qy * v9->qy - _f2->qz * _f1->qz;
  Frame::set_rotate(this, new_qw, new_qx, new_qy, new_qz);
}

//----- (005190F0) --------------------------------------------------------  // acclient.c:326600
void __thiscall CPartArray::UpdateParts(CPartArray *this, Frame *frame)
{
  CPartArray *v2; // ebx@1
  AnimFrame *v3; // eax@1
  unsigned int v4; // ebp@2
  unsigned int v5; // esi@4
  int v6; // edi@5
  AnimFrame *curr_animframe; // [sp+0h] [bp-4h]@1

  v2 = this;
  v3 = CSequence::get_curr_animframe(&this->sequence);
  curr_animframe = v3;
  if ( v3 )
  {
    v4 = v2->num_parts;
    if ( v4 > v3->num_parts )
      v4 = v3->num_parts;
    v5 = 0;
    if ( v4 )
    {
      v6 = 0;
      while ( 1 )
      {
        Frame::combine(&v2->parts[v5++]->pos.frame, frame, &v3->frame[v6], &v2->scale);
        ++v6;
        if ( v5 >= v4 )
          break;
        v3 = curr_animframe;
      }
    }
  }
}

//----- (00519150) --------------------------------------------------------  // acclient.c:326634
int __thiscall CPartArray::SetMeshID(CPartArray *this, IDClass<_tagDataID,32,0> mesh_did)
{
  CPartArray *v2; // esi@1
  int result; // eax@2
  CSetup *v4; // edi@3
  CSetup *v5; // ecx@4

  v2 = this;
  if ( mesh_did.id == stru_843FD0.id )
  {
    result = 0;
  }
  else
  {
    v4 = CSetup::makeSimpleSetup(mesh_did);
    if ( !v4 )
      goto LABEL_11;
    CPartArray::DestroyParts(v2);
    v5 = v2->setup;
    if ( v5 )
    {
      ((void (*)(void))v5->vfptr->Release)();
      v2->setup = 0;
    }
    v2->setup = v4;
    if ( CPartArray::InitParts(v2) )
      result = 1;
    else
LABEL_11:
      result = 0;
  }
  return result;
}

//----- (005191B0) --------------------------------------------------------  // acclient.c:326669
void __thiscall CPartArray::DestroyLights(CPartArray *this)
{
  CPartArray *v1; // edi@1
  CPhysicsObj *v2; // eax@1
  LIGHTLIST *v3; // esi@3
  LIGHTOBJ *v4; // eax@4

  v1 = this;
  v2 = this->owner;
  if ( v2 && this->lights )
  {
    CPartArray::RemoveLightsFromCell(this, v2->cell);
    v3 = v1->lights;
    if ( v3 )
    {
      v4 = v3->lightobj;
      if ( v4 )
      {
        operator delete[](&v4[-1].state);
        v3->lightobj = 0;
      }
      v3->num_lights = 0;
      operator delete(v3);
    }
    v1->lights = 0;
  }
}

//----- (00519210) --------------------------------------------------------  // acclient.c:326698
int __thiscall CPartArray::DoObjDescChanges(CPartArray *this, ObjDesc *objdesc)
{
  CPartArray *v2; // edi@1
  signed int v3; // eax@1
  signed int v4; // ebx@1
  int result; // eax@13

  v2 = this;
  v3 = 0;
  v4 = 1;
  if ( objdesc->num_anim_part_changes > 0 )
  {
    if ( !CPartArray::SetPart(this, objdesc->firstAPChange) )
      v4 = 0;
    v3 = 1;
  }
  if ( objdesc->num_texture_map_changes > 0 )
  {
    if ( !CPartArray::SetTextureMap(v2, objdesc->firstTMChange) )
      v4 = 0;
    v3 = 1;
  }
  if ( objdesc->num_subpalettes > 0 )
  {
    if ( !CPartArray::SetPalette(v2, objdesc->paletteID, objdesc->firstSubpal) )
      v4 = 0;
LABEL_13:
    result = CPartArray::InitObjDescChanges(v2);
    if ( !result )
      return result;
    return v4;
  }
  if ( v3 )
    goto LABEL_13;
  return v4;
}

//----- (005192A0) --------------------------------------------------------  // acclient.c:326736
void __thiscall CPartArray::Destroy(CPartArray *this)
{
  CPartArray *v1; // esi@1
  MotionTableManager *v2; // edi@1
  CSetup *v3; // ecx@3

  v1 = this;
  v2 = this->motion_table_manager;
  if ( v2 )
  {
    MotionTableManager::~MotionTableManager(this->motion_table_manager);
    operator delete(v2);
  }
  v1->motion_table_manager = 0;
  CPartArray::DestroyPals(v1);
  CPartArray::DestroyLights(v1);
  CPartArray::DestroyParts(v1);
  v3 = v1->setup;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v1->setup = 0;
  }
  v1->pa_state = 0;
  v1->owner = 0;
  CSequence::set_object(&v1->sequence, 0);
}

//----- (00519310) --------------------------------------------------------  // acclient.c:326765
void __thiscall CPartArray::SetFrame(CPartArray *this, Frame *frame)
{
  CPartArray *v2; // esi@1
  LIGHTLIST *v3; // ecx@1

  v2 = this;
  CPartArray::UpdateParts(this, frame);
  v3 = v2->lights;
  if ( v3 )
    LIGHTLIST::set_frame(v3, frame);
}

//----- (00519330) --------------------------------------------------------  // acclient.c:326778
int __thiscall CPartArray::SetSetupID(CPartArray *this, IDClass<_tagDataID,32,0> setup_id, int bCreateParts)
{
  CPartArray *v3; // esi@1
  CSetup *v4; // eax@1
  QualifiedDataID *v5; // eax@3
  int v6; // edi@3
  CSetup *v7; // ecx@4
  QualifiedDataID v9; // [sp+8h] [bp-8h]@3

  v3 = this;
  v4 = this->setup;
  if ( !v4 || v4->m_DID.id != setup_id.id )
  {
    QualifiedDataID::QualifiedDataID(&v9, setup_id, 7u);
    v6 = DBObj::Get(v5);
    if ( !v6 )
      return 0;
    CPartArray::DestroyPals(v3);
    CPartArray::DestroyLights(v3);
    CPartArray::DestroyParts(v3);
    v7 = v3->setup;
    if ( v7 )
    {
      ((void (*)(void))v7->vfptr->Release)();
      v3->setup = 0;
    }
    v3->setup = (CSetup *)v6;
    if ( bCreateParts )
    {
      if ( !CPartArray::InitParts(v3) )
        return 0;
    }
    CPartArray::InitLights(v3);
    CPartArray::InitDefaults(v3);
  }
  return 1;
}

//----- (005193D0) --------------------------------------------------------  // acclient.c:326817
int __thiscall CPartArray::SetPlacementFrame(CPartArray *this, unsigned int placement_id)
{
  CPartArray *v2; // edi@1
  CSetup *v3; // edx@1
  HashBaseData<unsigned long> *v4; // eax@1
  unsigned int v5; // ecx@4
  unsigned int v6; // esi@4
  HashBaseData<unsigned long> *v7; // eax@4

  v2 = this;
  v3 = this->setup;
  v4 = v3->placement_frames.buckets[v3->placement_frames.table_mask & (placement_id ^ (placement_id >> v3->placement_frames.key_shift))];
  if ( !v4 )
    goto LABEL_4;
  while ( placement_id != v4->id )
  {
    v4 = v4->hash_next;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    CSequence::set_placement_frame(&this->sequence, (AnimFrame *)&v4[1], placement_id);
  }
  else
  {
LABEL_4:
    v5 = v3->placement_frames.key_shift;
    v6 = v3->placement_frames.table_mask;
    v7 = *v3->placement_frames.buckets;
    if ( !v7 )
      goto LABEL_7;
    while ( v7->id )
    {
      v7 = v7->hash_next;
      if ( !v7 )
        goto LABEL_7;
    }
    if ( !v7 )
    {
LABEL_7:
      CSequence::set_placement_frame(&v2->sequence, 0, 0);
      return 0;
    }
    CSequence::set_placement_frame(&v2->sequence, (AnimFrame *)&v7[1], 0);
  }
  return 1;
}

//----- (00519480) --------------------------------------------------------  // acclient.c:326867
int __thiscall CPartArray::DoObjDescChangesFromDefault(CPartArray *this, ObjDesc *objdesc)
{
  CPartArray *v2; // esi@1
  unsigned int v3; // edi@2
  CPhysicsPart *v4; // ecx@3
  int result; // eax@7

  v2 = this;
  if ( this->setup )
  {
    v3 = 0;
    if ( this->num_parts )
    {
      do
      {
        v4 = v2->parts[v3];
        if ( v4 )
          CPhysicsPart::RestorePalette(v4);
        ++v3;
      }
      while ( v3 < v2->num_parts );
    }
  }
  CPartArray::DestroyPals(v2);
  if ( objdesc )
    result = CPartArray::DoObjDescChanges(v2, objdesc);
  else
    result = 1;
  return result;
}

//----- (005194D0) --------------------------------------------------------  // acclient.c:326899
void __thiscall CPartArray::~CPartArray(CPartArray *this)
{
  CPartArray *v1; // esi@1

  v1 = this;
  CPartArray::Destroy(this);
  CSequence::~CSequence(&v1->sequence);
}

//----- (005194F0) --------------------------------------------------------  // acclient.c:326909
CPartArray *__cdecl CPartArray::CreateParticle(CPhysicsObj *_owner, unsigned int _num_parts)
{
  void *v2; // eax@1
  void *v3; // esi@1
  int v4; // eax@2

  v2 = operator new(0x78u);
  v3 = v2;
  if ( v2 )
  {
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = 0;
    CSequence::CSequence((CSequence *)((char *)v2 + 8));
    *((_DWORD *)v3 + 20) = 0;
    *((_DWORD *)v3 + 21) = 0;
    *((_DWORD *)v3 + 22) = 0;
    *((_DWORD *)v3 + 23) = 0;
    *((_DWORD *)v3 + 24) = 1065353216;
    *((_DWORD *)v3 + 25) = 1065353216;
    *((_DWORD *)v3 + 26) = 1065353216;
    *((_DWORD *)v3 + 27) = 0;
    *((_DWORD *)v3 + 28) = 0;
    *((_DWORD *)v3 + 29) = 0;
    *((_DWORD *)v3 + 1) = _owner;
    CSequence::set_object((CSequence *)((char *)v3 + 8), _owner);
    CSetup::makeParticleSetup(_num_parts);
    *((_DWORD *)v3 + 21) = v4;
    if ( v4 && CPartArray::InitParts((CPartArray *)v3) )
      return (CPartArray *)v3;
    CPartArray::Destroy((CPartArray *)v3);
    CSequence::~CSequence((CSequence *)((char *)v3 + 8));
    operator delete(v3);
  }
  return 0;
}

//----- (005195A0) --------------------------------------------------------  // acclient.c:326946
CPartArray *__cdecl CPartArray::CreateSetup(CPhysicsObj *_owner, IDClass<_tagDataID,32,0> setup_did, int bCreateParts)
{
  void *v3; // eax@1
  void *v4; // esi@1

  v3 = operator new(0x78u);
  v4 = v3;
  if ( v3 )
  {
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 1) = 0;
    CSequence::CSequence((CSequence *)((char *)v3 + 8));
    *((_DWORD *)v4 + 20) = 0;
    *((_DWORD *)v4 + 21) = 0;
    *((_DWORD *)v4 + 22) = 0;
    *((_DWORD *)v4 + 23) = 0;
    *((_DWORD *)v4 + 24) = 1065353216;
    *((_DWORD *)v4 + 25) = 1065353216;
    *((_DWORD *)v4 + 26) = 1065353216;
    *((_DWORD *)v4 + 27) = 0;
    *((_DWORD *)v4 + 28) = 0;
    *((_DWORD *)v4 + 29) = 0;
    *((_DWORD *)v4 + 1) = _owner;
    CSequence::set_object((CSequence *)((char *)v4 + 8), _owner);
    if ( CPartArray::SetSetupID((CPartArray *)v4, setup_did, bCreateParts) )
    {
      CPartArray::SetPlacementFrame((CPartArray *)v4, 0x65u);
      return (CPartArray *)v4;
    }
    CPartArray::Destroy((CPartArray *)v4);
    CSequence::~CSequence((CSequence *)((char *)v4 + 8));
    operator delete(v4);
  }
  return 0;
}

//----- (00519640) --------------------------------------------------------  // acclient.c:326983
CPartArray *__cdecl CPartArray::CreateMesh(CPhysicsObj *_owner, IDClass<_tagDataID,32,0> setup_did)
{
  void *v2; // eax@1
  void *v3; // esi@1

  v2 = operator new(0x78u);
  v3 = v2;
  if ( v2 )
  {
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = 0;
    CSequence::CSequence((CSequence *)((char *)v2 + 8));
    *((_DWORD *)v3 + 20) = 0;
    *((_DWORD *)v3 + 21) = 0;
    *((_DWORD *)v3 + 22) = 0;
    *((_DWORD *)v3 + 23) = 0;
    *((_DWORD *)v3 + 24) = 1065353216;
    *((_DWORD *)v3 + 25) = 1065353216;
    *((_DWORD *)v3 + 26) = 1065353216;
    *((_DWORD *)v3 + 27) = 0;
    *((_DWORD *)v3 + 28) = 0;
    *((_DWORD *)v3 + 29) = 0;
    *((_DWORD *)v3 + 1) = _owner;
    CSequence::set_object((CSequence *)((char *)v3 + 8), _owner);
    if ( CPartArray::SetMeshID((CPartArray *)v3, setup_did) )
    {
      CPartArray::SetPlacementFrame((CPartArray *)v3, 0x65u);
      return (CPartArray *)v3;
    }
    CPartArray::Destroy((CPartArray *)v3);
    CSequence::~CSequence((CSequence *)((char *)v3 + 8));
    operator delete(v3);
  }
  return 0;
}

//----- (006FC510) --------------------------------------------------------  // acclient.c:784657
void sub_6FC510()
{
  flt_843FC4 = 1000.0 + 1.0;
}

//----- (006FC530) --------------------------------------------------------  // acclient.c:784663
void sub_6FC530()
{
  flt_843FC8 = 24.0 * 8.0;
}

//----- (006FC550) --------------------------------------------------------  // acclient.c:784669
void sub_6FC550()
{
  flt_843FCC = 24.0 * 0.5;
}

//----- (006FC570) --------------------------------------------------------  // acclient.c:784675
int sub_6FC570()
{
  return atexit(nullsub_1093);
}

//----- (006FC580) --------------------------------------------------------  // acclient.c:784681
int sub_6FC580()
{
  return atexit(nullsub_1094);
}

//----- (006FC590) --------------------------------------------------------  // acclient.c:784687
int sub_6FC590()
{
  return atexit(nullsub_1095);
}

//----- (006FC5A0) --------------------------------------------------------  // acclient.c:784693
void _E106_92()
{
  dword_843FD4 = 1024;
}

//----- (006FC5B0) --------------------------------------------------------  // acclient.c:784699
void _E108_68()
{
  dword_843FD8 = 0x7FFF;
}

//----- (006FC5C0) --------------------------------------------------------  // acclient.c:784705
int _E110_57()
{
  const int result; // eax@1

  result = dword_843FD4;
  INITIAL_MAX_DATA_RATE_71 = dword_843FD4;
  return result;
}

//----- (006FC5D0) --------------------------------------------------------  // acclient.c:784715
void _E112_85()
{
  flt_843FE0 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FC5F0) --------------------------------------------------------  // acclient.c:784721
void _E114_43()
{
  dbl_843FE8 = 1.0 / 30.0;
}

//----- (006FC610) --------------------------------------------------------  // acclient.c:784727
void _E116_17()
{
  dbl_843FF0 = 1.0 / 5.0;
}

//----- (006FC630) --------------------------------------------------------  // acclient.c:784733
int sub_6FC630()
{
  return atexit(nullsub_1092);
}

