/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CObjCell
   Object     : PORTAL\ccell\CObjCell.obj
   Functions  : 125
   Addresses  : 005138C0 - 00768AA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005138C0) --------------------------------------------------------  // acclient.c:320772
void __thiscall LongNIValHashIter<SurfInfo *>::LongNIValHashIter<SurfInfo *>(LongNIValHashIter<GlobalVoyeurInfo> *this, LongNIValHash<GlobalVoyeurInfo> *hash)
{
  HashBaseData<unsigned long> *v2; // eax@2

  this->myHash_ = (HashBase<unsigned long> *)hash;
  this->lastThisChain_ = 0;
  this->curBucket_ = 0;
  if ( hash )
  {
    this->fEnd_ = 0;
    v2 = *hash->buckets;
    this->curPtr_ = v2;
    if ( !v2 )
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&this->myHash_);
  }
  else
  {
    this->fEnd_ = 1;
    this->curPtr_ = 0;
  }
}

//----- (0051FE80) --------------------------------------------------------  // acclient.c:334338
LongNIValHashData<GlobalVoyeurInfo> *__thiscall HashBaseData<unsigned long>::scalar_deleting_destructor(LongNIValHashData<GlobalVoyeurInfo> *this, unsigned int a2)
{
  LongNIValHashData<GlobalVoyeurInfo> *v2; // esi@1

  v2 = this;
  this->hash_next = 0;
  this->id = 0;
  this->vfptr = (HashBaseData<unsigned long>Vtbl *)LongHashData::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);

//----- (0052AD40) --------------------------------------------------------  // acclient.c:346416
unsigned int __cdecl CObjCell::GetVisible(unsigned int cell_id)
{
  unsigned int result; // eax@1

  result = cell_id;
  if ( cell_id )
  {
    if ( (unsigned __int16)cell_id >= 0x100u )
      result = (unsigned int)CEnvCell::GetVisible(cell_id);
    else
      result = CLandCell::Get(cell_id);
  }
  return result;
}

//----- (0052AD70) --------------------------------------------------------  // acclient.c:346432
void __cdecl CObjCell::SetObjectMaintainer(CObjectMaint *_obj_maint)
{
  CObjCell::obj_maint = _obj_maint;
}

//----- (0052AD90) --------------------------------------------------------  // acclient.c:346438
LandDefs::WaterType __thiscall CObjCell::get_block_water_type(CObjCell *this)
{
  CLandBlock *v1; // eax@1
  LandDefs::WaterType result; // eax@2

  v1 = this->myLandBlock_;
  if ( v1 )
    result = v1->water_type;
  else
    result = 0;
  return result;
}

//----- (0052ADB0) --------------------------------------------------------  // acclient.c:346452
void __thiscall DArray<LIGHTOBJ const *>::shrink(DArray<LIGHTOBJ const *> *this, unsigned int size)
{
  DArray<LIGHTOBJ const *> *v2; // esi@1
  LIGHTOBJ **v3; // ST04_4@4
  void *v4; // ebx@5
  unsigned int v5; // eax@5

  v2 = this;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v4 = operator new[](4 * size);
      v5 = 0;
      v2->sizeOf = size;
      if ( size )
      {
        do
        {
          *((_DWORD *)v4 + v5) = v2->data[v5];
          ++v5;
        }
        while ( v5 < v2->sizeOf );
      }
      operator delete[](v2->data);
      v2->data = (LIGHTOBJ **)v4;
    }
    else
    {
      v3 = this->data;
      this->sizeOf = 0;
      operator delete[](v3);
      v2->data = 0;
    }
    if ( v2->next_available > size )
      v2->next_available = size;
  }
  else
  {
    DArray<LIGHTOBJ const *>::grow(this, size);
  }
}

//----- (0052AE30) --------------------------------------------------------  // acclient.c:346496
void __thiscall DArray<LIGHTOBJ const *>::grow(DArray<LIGHTOBJ const *> *this, unsigned int size)
{
  DArray<LIGHTOBJ const *> *v2; // esi@1
  void *v3; // edi@3
  unsigned int v4; // eax@3

  v2 = this;
  if ( size > this->sizeOf )
  {
    v3 = operator new[](4 * size);
    v4 = 0;
    if ( v2->sizeOf )
    {
      do
      {
        *((_DWORD *)v3 + v4) = v2->data[v4];
        ++v4;
      }
      while ( v4 < v2->sizeOf );
    }
    operator delete[](v2->data);
    v2->data = (LIGHTOBJ **)v3;
    v2->sizeOf = size;
  }
  else
  {
    DArray<LIGHTOBJ const *>::shrink(this, size);
  }
}

//----- (0052AE90) --------------------------------------------------------  // acclient.c:346527
void __thiscall DArray<CShadowObj *>::shrink(DArray<CShadowObj *> *this, unsigned int size)
{
  DArray<CShadowObj *> *v2; // esi@1
  CShadowObj **v3; // ST04_4@4
  void *v4; // ebx@5
  unsigned int v5; // eax@5

  v2 = this;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v4 = operator new[](4 * size);
      v5 = 0;
      v2->sizeOf = size;
      if ( size )
      {
        do
        {
          *((_DWORD *)v4 + v5) = v2->data[v5];
          ++v5;
        }
        while ( v5 < v2->sizeOf );
      }
      operator delete[](v2->data);
      v2->data = (CShadowObj **)v4;
    }
    else
    {
      v3 = this->data;
      this->sizeOf = 0;
      operator delete[](v3);
      v2->data = 0;
    }
    if ( v2->next_available > size )
      v2->next_available = size;
  }
  else
  {
    DArray<CShadowObj *>::grow(this, size);
  }
}

//----- (0052AF10) --------------------------------------------------------  // acclient.c:346571
void __thiscall DArray<CShadowObj *>::grow(DArray<CShadowObj *> *this, unsigned int size)
{
  DArray<CShadowObj *> *v2; // esi@1
  void *v3; // edi@3
  unsigned int v4; // eax@3

  v2 = this;
  if ( size > this->sizeOf )
  {
    v3 = operator new[](4 * size);
    v4 = 0;
    if ( v2->sizeOf )
    {
      do
      {
        *((_DWORD *)v3 + v4) = v2->data[v4];
        ++v4;
      }
      while ( v4 < v2->sizeOf );
    }
    operator delete[](v2->data);
    v2->data = (CShadowObj **)v3;
    v2->sizeOf = size;
  }
  else
  {
    DArray<CShadowObj *>::shrink(this, size);
  }
}

//----- (0052AF70) --------------------------------------------------------  // acclient.c:346602
void __thiscall CObjCell::CObjCell(CObjCell *this)
{
  CObjCell *v1; // esi@1
  int v2; // ecx@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_844744);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (InterfaceVtbl *)&SerializeUsingPackDBObj::vftable;
  v1->vfptr = (PackObjVtbl *)&SerializeUsingPackDBObj::vftable;
  CPartCell::CPartCell((CPartCell *)&v1->vfptr);
  v1->vfptr = (CPartCellVtbl *)&CObjCell::vftable;
  v1->vfptr = (InterfaceVtbl *)&CObjCell::vftable;
  v1->vfptr = (PackObjVtbl *)&CObjCell::vftable;
  v1->water_type = 0;
  v2 = (int)&v1->pos.frame;
  v1->pos.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->pos.objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 52) = 0;
  *(_DWORD *)(v2 + 56) = 0;
  *(_DWORD *)(v2 + 60) = 0;
  Frame::cache(&v1->pos.frame);
  v1->num_objects = 0;
  v1->object_list.data = 0;
  v1->object_list.sizeOf = 0;
  v1->object_list.next_available = 0;
  v1->object_list.blocksize = 128;
  v1->num_lights = 0;
  v1->light_list.data = 0;
  v1->light_list.sizeOf = 0;
  v1->light_list.next_available = 0;
  v1->light_list.blocksize = 128;
  v1->num_shadow_objects = 0;
  v1->shadow_object_list.data = 0;
  v1->shadow_object_list.sizeOf = 0;
  v1->shadow_object_list.next_available = 0;
  v1->shadow_object_list.blocksize = 128;
  v1->restriction_obj = 0;
  v1->clip_planes = 0;
  v1->num_stabs = 0;
  v1->stab_list = 0;
  v1->seen_outside = 0;
  v1->voyeur_table = 0;
  v1->myLandBlock_ = 0;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7C58CC: using guessed type void *SerializeUsingPackDBObj::vftable;
// 7C58E0: using guessed type __int32 (__stdcall *SerializeUsingPackDBObj::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7C8B0C: using guessed type void *CObjCell::vftable;
// 7C8B20: using guessed type __int32 (__stdcall *CObjCell::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7C8BC0: using guessed type void (__thiscall *CObjCell::vftable)(CPartCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32);

//----- (0052B070) --------------------------------------------------------  // acclient.c:346660
void __stdcall CObjCell::find_transit_cells(Position *p, const unsigned int num_sphere, CSphere *sphere, CELLARRAY *cell_array, SPHEREPATH *path)
{
  Turbine::Debug::Abort();
}

//----- (0052B080) --------------------------------------------------------  // acclient.c:346666
void __stdcall CObjCell::find_transit_cells(const unsigned int num_parts, CPhysicsPart **parts, CELLARRAY *cell_array)
{
  Turbine::Debug::Abort();
}

//----- (0052B0A0) --------------------------------------------------------  // acclient.c:346672
CObjCell *__thiscall CObjCell::vector_deleting_destructor(CObjCell *this, unsigned int a2)
{
  return CObjCell::vector_deleting_destructor((CObjCell *)((char *)this - 48), a2);
}

//----- (0052B0B0) --------------------------------------------------------  // acclient.c:346678
CObjCell *__thiscall CObjCell::vector_deleting_destructor(CObjCell *this, unsigned int a2)
{
  return CObjCell::vector_deleting_destructor((CObjCell *)((char *)this - 56), a2);
}

//----- (0052B0C0) --------------------------------------------------------  // acclient.c:346684
void __thiscall CObjCell::~CObjCell(CObjCell *this)
{
  CObjCell *v1; // esi@1
  LongNIValHash<GlobalVoyeurInfo> *v2; // ecx@1
  ClipPlaneList **v3; // eax@3
  ClipPlaneList *v4; // edi@4

  v1 = this;
  v2 = this->voyeur_table;
  v1->vfptr = (InterfaceVtbl *)&CObjCell::vftable;
  v1->vfptr = (PackObjVtbl *)&CObjCell::vftable;
  v1->vfptr = (CPartCellVtbl *)&CObjCell::vftable;
  if ( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->voyeur_table = 0;
  }
  v3 = v1->clip_planes;
  if ( v3 )
  {
    v4 = *v3;
    if ( *v3 )
    {
      ClipPlaneList::~ClipPlaneList(*v3);
      operator delete(v4);
    }
    operator delete[](v1->clip_planes);
  }
  operator delete[](v1->shadow_object_list.data);
  v1->shadow_object_list.data = 0;
  operator delete[](v1->light_list.data);
  v1->light_list.data = 0;
  operator delete[](v1->object_list.data);
  v1->object_list.data = 0;
  v1->pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
  CPartCell::~CPartCell((CPartCell *)&v1->vfptr);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C8B0C: using guessed type void *CObjCell::vftable;
// 7C8B20: using guessed type __int32 (__stdcall *CObjCell::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7C8BC0: using guessed type void (__thiscall *CObjCell::vftable)(CPartCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32);

//----- (0052B180) --------------------------------------------------------  // acclient.c:346729
unsigned int __cdecl CObjCell::Get(unsigned int cell_id)
{
  unsigned int result; // eax@1
  QualifiedDataID *v2; // eax@4
  QualifiedDataID v3; // [sp+0h] [bp-8h]@4

  result = cell_id;
  if ( cell_id )
  {
    if ( (unsigned __int16)cell_id >= 0x100u )
    {
      QualifiedDataID::QualifiedDataID(&v3, (IDClass<_tagDataID,32,0>)cell_id, 3u);
      result = DBObj::Get(v2);
    }
    else
    {
      result = CLandCell::Get(cell_id);
    }
  }
  return result;
}

//----- (0052B1D0) --------------------------------------------------------  // acclient.c:346752
void __thiscall CObjCell::add_light(CObjCell *this, LIGHTOBJ *_light)
{
  CObjCell *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@3
  LIGHTOBJ **v5; // edx@3

  v2 = this;
  v3 = this->light_list.sizeOf;
  if ( this->num_lights >= v3 )
    DArray<LIGHTOBJ const *>::grow(&this->light_list, v3 + 5);
  v4 = v2->num_lights;
  v5 = v2->light_list.data;
  v2->num_lights = v4 + 1;
  v5[v4] = _light;
}

//----- (0052B210) --------------------------------------------------------  // acclient.c:346770
void __thiscall CObjCell::remove_light(CObjCell *this, LIGHTOBJ *_light)
{
  CObjCell *v2; // eax@1
  unsigned int v3; // ebx@1
  unsigned int v4; // edx@1
  DArray<LIGHTOBJ const *> *v5; // ecx@2
  LIGHTOBJ **v6; // edi@2
  LIGHTOBJ **v7; // esi@2
  unsigned int v8; // edx@6

  v2 = this;
  v3 = this->num_lights;
  v4 = 0;
  if ( v3 )
  {
    v5 = &this->light_list;
    v6 = v2->light_list.data;
    v7 = v2->light_list.data;
    while ( *v7 != _light )
    {
      ++v4;
      ++v7;
      if ( v4 >= v2->num_lights )
        return;
    }
    v2->num_lights = v3 - 1;
    v6[v4] = v6[v3 - 1];
    v8 = v2->num_lights;
    if ( v8 + 10 < v2->light_list.sizeOf )
      DArray<LIGHTOBJ const *>::shrink(v5, v8 + 5);
  }
}

//----- (0052B280) --------------------------------------------------------  // acclient.c:346804
void __thiscall CObjCell::add_shadow_object(CObjCell *this, CShadowObj *_object, unsigned int num_shadow_cells)
{
  CObjCell *v3; // esi@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@3
  CShadowObj **v6; // edx@3

  v3 = this;
  v4 = this->shadow_object_list.sizeOf;
  if ( this->num_shadow_objects >= v4 )
    DArray<CShadowObj *>::grow(&this->shadow_object_list, v4 + 5);
  v5 = v3->num_shadow_objects;
  v6 = v3->shadow_object_list.data;
  v3->num_shadow_objects = v5 + 1;
  v6[v5] = _object;
  _object->cell = v3;
}

//----- (0052B2D0) --------------------------------------------------------  // acclient.c:346823
void __thiscall CObjCell::remove_shadow_object(CObjCell *this, CShadowObj *_object)
{
  CObjCell *v2; // eax@1
  unsigned int v3; // esi@1
  CShadowObj **v4; // edx@2
  DArray<CShadowObj *> *v5; // ecx@2
  CShadowObj **v6; // edx@6
  int v7; // ebx@6
  unsigned int v8; // edx@6

  v2 = this;
  v3 = 0;
  if ( this->num_shadow_objects )
  {
    v4 = this->shadow_object_list.data;
    v5 = &this->shadow_object_list;
    while ( *v4 != _object )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2->num_shadow_objects )
        return;
    }
    _object->cell = 0;
    v6 = v5->data;
    v7 = v2->num_shadow_objects - 1;
    v2->num_shadow_objects = v7;
    v6[v3] = v6[v7];
    v8 = v2->num_shadow_objects;
    if ( v8 + 10 < v2->shadow_object_list.sizeOf )
      DArray<CShadowObj *>::shrink(v5, v8 + 5);
  }
}

//----- (0052B350) --------------------------------------------------------  // acclient.c:346858
void __thiscall CObjCell::add_static_to_global_lights(CObjCell *this)
{
  CObjCell *v1; // esi@1
  unsigned int v2; // edi@1
  LIGHTOBJ *v3; // eax@2

  v1 = this;
  v2 = 0;
  if ( this->num_lights )
  {
    do
    {
      v3 = v1->light_list.data[v2];
      if ( v3->state & 1 )
        Render::add_static_light(v3->lightinfo, v1->m_DID.id, &v3->global_offset);
      ++v2;
    }
    while ( v2 < v1->num_lights );
  }
}

//----- (0052B390) --------------------------------------------------------  // acclient.c:346880
void __thiscall CObjCell::add_dynamic_to_global_lights(CObjCell *this)
{
  CObjCell *v1; // esi@1
  unsigned int v2; // edi@1
  LIGHTOBJ *v3; // eax@2

  v1 = this;
  v2 = 0;
  if ( this->num_lights )
  {
    do
    {
      v3 = v1->light_list.data[v2];
      if ( ~LOBYTE(v3->state) & 1 )
        Render::add_dynamic_light(v3->lightinfo, v1->m_DID.id, &v3->global_offset);
      ++v2;
    }
    while ( v2 < v1->num_lights );
  }
}

//----- (0052B3E0) --------------------------------------------------------  // acclient.c:346902
double __stdcall CObjCell::GetViewerDistance(AC1Legacy::Vector3 *diff_vec)
{
  double result; // st7@1

  result = 0.0;
  LODWORD(diff_vec->x) = 0;
  LODWORD(diff_vec->y) = 0;
  LODWORD(diff_vec->z) = 0;
  return result;
}

//----- (0052B420) --------------------------------------------------------  // acclient.c:346914
void __thiscall CObjCell::init_objects(CObjCell *this)
{
  CObjCell *v1; // esi@1
  unsigned int v2; // ebp@2
  CPhysicsObj **v3; // eax@3
  CPhysicsObj *v4; // edi@3

  v1 = this;
  if ( CObjCell::obj_maint )
  {
    CObjectMaint::InitObjCell(CObjCell::obj_maint, this);
    v2 = 0;
    if ( v1->num_objects )
    {
      do
      {
        v3 = v1->object_list.data;
        v4 = v3[v2];
        if ( !(v4->state & 1) && !CPhysicsObj::is_completely_visible(v3[v2]) )
          CPhysicsObj::recalc_cross_cells(v4);
        ++v2;
      }
      while ( v2 < v1->num_objects );
    }
  }
}

//----- (0052B490) --------------------------------------------------------  // acclient.c:346942
void __thiscall CObjCell::release_objects(CObjCell *this)
{
  CObjCell *i; // esi@1
  CShadowObj *v2; // edi@2

  for ( i = this; i->num_shadow_objects; CPhysicsObj::remove_parts(v2->physobj, i) )
  {
    v2 = *i->shadow_object_list.data;
    CObjCell::remove_shadow_object(i, v2);
  }
  if ( i->num_objects )
  {
    if ( CObjCell::obj_maint )
      CObjectMaint::ReleaseObjCell(i);
  }
}

//----- (0052B4E0) --------------------------------------------------------  // acclient.c:346960
void __cdecl CObjCell::find_cell_list(Position *p, const unsigned int num_sphere, CSphere *sphere, CELLARRAY *cell_array, CObjCell **curr_cell, SPHEREPATH *path)
{
  RenderVertexStreamD3D *v6; // eax@1
  CELLARRAY *v7; // edi@1
  unsigned int v8; // esi@1
  unsigned int v9; // esi@12
  CObjCell *v10; // ecx@13
  unsigned int v11; // ebp@17
  CObjCell *v12; // esi@18
  AC1Legacy::Vector3 *v13; // eax@19
  double v14; // st7@19
  double v15; // st6@19
  double v16; // st5@19
  InterfaceVtbl *v17; // eax@19
  const unsigned int v18; // ebx@27
  unsigned int v19; // esi@28
  int v20; // edx@29
  unsigned int v21; // eax@29
  int v22; // ecx@30
  unsigned int v23; // [sp+0h] [bp-2Ch]@2
  AC1Legacy::Vector3 localpoint; // [sp+14h] [bp-18h]@19
  AC1Legacy::Vector3 result; // [sp+20h] [bp-Ch]@19
  CELLARRAY *cell_arraya; // [sp+3Ch] [bp+10h]@5

  v6 = 0;
  v7 = cell_array;
  cell_array->num_cells = 0;
  cell_array->added_outside = 0;
  v8 = p->objcell_id;
  if ( v8 )
  {
    v23 = p->objcell_id;
    if ( (unsigned __int16)v8 >= 0x100u )
      v6 = CEnvCell::GetVisible(v23);
    else
      v6 = (RenderVertexStreamD3D *)CLandCell::Get(v23);
  }
  cell_arraya = (CELLARRAY *)v6;
  if ( (unsigned __int16)v8 >= 0x100u )
  {
    if ( path )
      path->hits_interior_cell = 1;
    CELLARRAY::add_cell(v7, v8, (CObjCell *)v6);
  }
  else
  {
    CLandCell::add_all_outside_cells(p, num_sphere, sphere, v7);
  }
  if ( cell_arraya && num_sphere )
  {
    v9 = 0;
    if ( v7->num_cells )
    {
      do
      {
        v10 = v7->cells.data[v9].cell;
        if ( v10 )
          ((void (__stdcall *)(Position *, const unsigned int, CSphere *, CELLARRAY *, SPHEREPATH *))v10->vfptr[5].IUnknown_Release)(
            p,
            num_sphere,
            sphere,
            v7,
            path);
        ++v9;
      }
      while ( v9 < v7->num_cells );
    }
    if ( curr_cell )
    {
      *curr_cell = 0;
      v11 = 0;
      if ( v7->num_cells )
      {
        while ( 1 )
        {
          v12 = v7->cells.data[v11].cell;
          if ( v12 )
          {
            v13 = LandDefs::get_block_offset(&result, p->objcell_id, v12->m_DID.id);
            v14 = sphere->center.z - v13->z;
            v15 = sphere->center.y - v13->y;
            v16 = sphere->center.x - v13->x;
            v17 = v12->vfptr;
            localpoint.x = v16;
            localpoint.y = v15;
            localpoint.z = v14;
            if ( ((int (__thiscall *)(CObjCell *, AC1Legacy::Vector3 *))v17[5].QueryInterface)(v12, &localpoint) )
            {
              *curr_cell = v12;
              if ( (v12->m_DID.id & 0xFFFF) >= 0x100 )
                break;
            }
          }
          ++v11;
          if ( v11 >= v7->num_cells )
            goto LABEL_25;
        }
        if ( path )
          path->hits_interior_cell = 1;
      }
    }
LABEL_25:
    if ( v7->do_not_load_cells )
    {
      if ( (p->objcell_id & 0xFFFF) >= 0x100 )
      {
        v18 = 0;
        if ( v7->num_cells )
        {
          while ( 1 )
          {
            v19 = v7->cells.data[v18].cell_id;
            if ( (CELLINFO *)v19 == cell_arraya[1].cells.data )
              goto LABEL_34;
            v20 = cell_arraya[8].added_outside;
            v21 = 0;
            if ( v20 )
              break;
LABEL_33:
            CELLARRAY::remove_cell(v7, v18);
LABEL_35:
            if ( v18 >= v7->num_cells )
              return;
          }
          v22 = cell_arraya[8].do_not_load_cells;
          while ( v19 != *(_DWORD *)v22 )
          {
            ++v21;
            v22 += 4;
            if ( v21 >= v20 )
              goto LABEL_33;
          }
LABEL_34:
          ++v18;
          goto LABEL_35;
        }
      }
    }
  }
}

//----- (0052B6D0) --------------------------------------------------------  // acclient.c:347102
signed int __thiscall CObjCell::check_entry_restrictions(CObjCell *this, CTransition *transition)
{
  CObjCell *v2; // edi@1
  CWeenieObject *v3; // esi@2
  int v4; // eax@3
  int v5; // ecx@3
  HashBaseData<unsigned long> *v6; // eax@6
  HashBaseData<unsigned long>Vtbl *v7; // ecx@7

  v2 = this;
  if ( !transition->object_info.object )
    return 2;
  v3 = transition->object_info.object->weenie_obj;
  if ( v3 )
  {
    v4 = ((int (__thiscall *)(CWeenieObject *))v3->vfptr[18].__vecDelDtor)(transition->object_info.object->weenie_obj);
    v5 = transition->object_info.state;
    if ( BYTE1(v5) & 1 )
    {
      if ( v2->restriction_obj && !v4 )
      {
        v6 = CPhysicsObj::GetObjectA(v2->restriction_obj);
        if ( !v6 )
          return 2;
        v7 = v6[25].vfptr;
        if ( !v7 )
          return 2;
        if ( !(*((int (__stdcall **)(CWeenieObject *))v7->__vecDelDtor + 17))(v3) )
        {
          ((void (__thiscall *)(CObjCell *, CTransition *))v2->vfptr[6].IUnknown_QueryInterface)(v2, transition);
          return 2;
        }
      }
    }
  }
  return 1;
}

//----- (0052B750) --------------------------------------------------------  // acclient.c:347141
signed int __thiscall CObjCell::find_obj_collisions(CObjCell *this, CTransition *transition)
{
  CObjCell *v2; // edi@1
  signed int result; // eax@1
  unsigned int v4; // esi@2
  CPhysicsObj *v5; // ecx@3

  v2 = this;
  result = 1;
  if ( transition->sphere_path.insert_type != 2 )
  {
    v4 = 0;
    if ( this->num_shadow_objects )
    {
      do
      {
        v5 = v2->shadow_object_list.data[v4]->physobj;
        if ( !v5->parent && v5 != transition->object_info.object )
        {
          result = CPhysicsObj::FindObjCollisions(v5, transition);
          if ( result != 1 )
            break;
        }
        ++v4;
      }
      while ( v4 < v2->num_shadow_objects );
    }
  }
  return result;
}

//----- (0052B7B0) --------------------------------------------------------  // acclient.c:347173
int __thiscall CObjCell::check_collisions(CObjCell *this, CPhysicsObj *object)
{
  CObjCell *v2; // edi@1
  unsigned int v3; // esi@1
  CPhysicsObj *v4; // ecx@2
  int result; // eax@6

  v2 = this;
  v3 = 0;
  if ( this->num_shadow_objects )
  {
    while ( 1 )
    {
      v4 = v2->shadow_object_list.data[v3]->physobj;
      if ( !v4->parent && v4 != object && CPhysicsObj::check_collision(v4, object) )
        break;
      ++v3;
      if ( v3 >= v2->num_shadow_objects )
        goto LABEL_6;
    }
    result = 1;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (0052B810) --------------------------------------------------------  // acclient.c:347204
void __thiscall CObjCell::check_attack(CObjCell *this, const unsigned int attacker_id, Position *attacker_pos, const float attacker_scale, AttackCone *attack_cone, AttackInfo *attack_info)
{
  unsigned int v6; // ebp@1
  CPhysicsObj *v7; // esi@2
  int v8; // eax@4
  CObjCell *v9; // [sp+4h] [bp-4h]@1

  v6 = 0;
  v9 = this;
  if ( this->num_shadow_objects )
  {
    do
    {
      v7 = this->shadow_object_list.data[v6]->physobj;
      if ( v7->id != attacker_id && !(v7->state & 1) )
      {
        v8 = CPhysicsObj::check_attack(v7, attacker_pos, attacker_scale, attack_cone, attack_info->attack_radius);
        if ( v8 )
          AttackInfo::AddObject(attack_info, v7->id, v8);
        this = v9;
      }
      ++v6;
    }
    while ( v6 < this->num_shadow_objects );
  }
}

//----- (0052B8A0) --------------------------------------------------------  // acclient.c:347232
double __thiscall CObjCell::get_water_depth(CObjCell *this, AC1Legacy::Vector3 *point)
{
  LandDefs::WaterType v2; // eax@1
  int v3; // eax@2
  double result; // st7@4
  CLandBlock *v5; // eax@5

  v2 = this->water_type;
  if ( v2 == NOT_WATER )
    return 0.0;
  v3 = v2 - 1;
  if ( v3 )
  {
    if ( v3 == 1 )
      return 0.89999998;
    return 0.0;
  }
  v5 = this->myLandBlock_;
  if ( v5 )
    result = CLandBlockStruct::calc_water_depth((CLandBlockStruct *)&v5->vertex_lighting, this->m_DID.id, point);
  else
    result = 0.1;
  return result;
}

//----- (0052B8F0) --------------------------------------------------------  // acclient.c:347258
CPhysicsObj *__thiscall CObjCell::get_object(CObjCell *this, const unsigned int obj_iid)
{
  unsigned int v2; // esi@1
  unsigned int v3; // edx@1
  CPhysicsObj **v4; // ecx@2
  CPhysicsObj *result; // eax@3

  v2 = this->num_objects;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->object_list.data;
    while ( 1 )
    {
      result = *v4;
      if ( *v4 )
      {
        if ( result->id == obj_iid )
          break;
      }
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (0052B930) --------------------------------------------------------  // acclient.c:347293
CObjCell *__thiscall CObjCell::vector_deleting_destructor(CObjCell *this, unsigned int a2)
{
  CObjCell *v2; // esi@1

  v2 = this;
  CObjCell::~CObjCell(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0052B950) --------------------------------------------------------  // acclient.c:347305
void __thiscall CObjCell::add_lights(CObjCell *this)
{
  CObjCell *v1; // esi@1

  v1 = this;
  CObjCell::add_static_to_global_lights(this);
  CObjCell::add_dynamic_to_global_lights(v1);
}

//----- (0052B960) --------------------------------------------------------  // acclient.c:347315
void __cdecl CObjCell::find_cell_list(CELLARRAY *cell_array, CObjCell **check_cell, SPHEREPATH *path)
{
  CObjCell::find_cell_list(&path->check_pos, path->num_sphere, path->global_sphere, cell_array, check_cell, path);
}

//----- (0052B990) --------------------------------------------------------  // acclient.c:347321
void __cdecl CObjCell::find_cell_list(Position *p, CSphere *sphere, CELLARRAY *cell_array, SPHEREPATH *path)
{
  AC1Legacy::Vector3 *v4; // eax@1
  AC1Legacy::Vector3 result; // [sp+4h] [bp-1Ch]@1
  CSphere global_sphere; // [sp+10h] [bp-10h]@1

  global_sphere.radius = sphere->radius;
  v4 = Position::localtoglobal(p, &result, p, &sphere->center);
  global_sphere.center.x = v4->x;
  global_sphere.center.y = v4->y;
  global_sphere.center.z = v4->z;
  CObjCell::find_cell_list(p, 1u, &global_sphere, cell_array, 0, path);
}

//----- (0052B9F0) --------------------------------------------------------  // acclient.c:347336
void __cdecl CObjCell::find_cell_list(Position *p, const unsigned int num_cylsphere, CCylSphere *cylsphere, CELLARRAY *cell_array, SPHEREPATH *path)
{
  signed int v5; // ebp@4
  CCylSphere *v6; // esi@7
  char *v7; // edi@7
  AC1Legacy::Vector3 *v8; // eax@8
  int v9; // ecx@8
  AC1Legacy::Vector3 result; // [sp+0h] [bp-Ch]@8

  if ( !(_S213_35 & 1) )
  {
    _S213_35 |= 1u;
    atexit(_E214_42);
  }
  if ( num_cylsphere <= 0xA )
  {
    v5 = num_cylsphere;
  }
  else
  {
    v5 = 10;
    num_cylsphere = 10;
  }
  if ( v5 )
  {
    v6 = cylsphere;
    v7 = (char *)&sphere[0].radius;
    do
    {
      v8 = Position::localtoglobal(p, &result, p, &v6->low_pt);
      v9 = (int)(v7 - 12);
      *(_DWORD *)v9 = LODWORD(v8->x);
      *(_DWORD *)(v9 + 4) = LODWORD(v8->y);
      *(_DWORD *)(v9 + 8) = LODWORD(v8->z);
      *(_DWORD *)v7 = LODWORD(v6->radius);
      ++v6;
      v7 += 16;
      --v5;
    }
    while ( v5 );
    v5 = num_cylsphere;
  }
  CObjCell::find_cell_list(p, v5, sphere, cell_array, 0, path);
}

//----- (0052BAB0) --------------------------------------------------------  // acclient.c:347382
void __thiscall LongNIValHash<GlobalVoyeurInfo>::LongNIValHash<GlobalVoyeurInfo>(LongNIValHash<GlobalVoyeurInfo> *this, unsigned int _table_size)
{
  HashBase<unsigned long> *v2; // esi@1

  v2 = (HashBase<unsigned long> *)this;
  this->vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  this->fPlacementNew_ = 0;
  this->buckets = (HashBaseData<unsigned long> **)operator new[](4 * _table_size);
  HashBase<unsigned long>::InternalInit(v2, _table_size);
  v2->vfptr = (HashBase<unsigned long>Vtbl *)&LongNIValHash<GlobalVoyeurInfo>::vftable;
}
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);
// 7C8BCC: using guessed type int (__thiscall *LongNIValHash<GlobalVoyeurInfo>::vftable)(void *, char);

//----- (0052BAF0) --------------------------------------------------------  // acclient.c:347397
void __thiscall LongNIValHash<GlobalVoyeurInfo>::add(LongNIValHash<GlobalVoyeurInfo> *this, GlobalVoyeurInfo data, unsigned int key)
{
  LongNIValHash<GlobalVoyeurInfo> *v3; // esi@1
  void *v4; // eax@1
  void *v5; // edx@1
  int v6; // eax@3

  v3 = this;
  v4 = operator new(0x18u);
  v5 = 0;
  if ( v4 )
  {
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = key;
    *((GlobalVoyeurInfo *)v4 + 1) = data;
    *(_DWORD *)v4 = LongHashData::vftable;
    v5 = v4;
  }
  v6 = v3->table_mask & (*((_DWORD *)v5 + 2) ^ (*((_DWORD *)v5 + 2) >> v3->key_shift));
  *((_DWORD *)v5 + 1) = v3->buckets[v6];
  v3->buckets[v6] = (HashBaseData<unsigned long> *)v5;
}
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);

//----- (0052BB60) --------------------------------------------------------  // acclient.c:347422
int __thiscall CObjCell::add_voyeur(CObjCell *this, unsigned int voyeur_id, DetectionCylsphere *detcyl)
{
  CObjCell *v3; // esi@1
  int result; // eax@3
  LongNIValHash<GlobalVoyeurInfo> *v5; // eax@5
  LongNIValHash<GlobalVoyeurInfo> *v6; // eax@6
  HashBaseData<unsigned long> *v7; // eax@9
  HashBaseData<unsigned long>Vtbl *v8; // ebp@10
  unsigned int v9; // ebx@10
  _BYTE v10[12]; // ST00_12@10
  _BYTE v11[12]; // ST00_12@11
  unsigned int v12; // ebp@11
  CPhysicsObj *v13; // ebx@12
  unsigned int v14; // eax@12
  HashBaseData<unsigned long> *v15; // eax@15
  GlobalVoyeurInfo info; // [sp+10h] [bp-Ch]@10

  v3 = this;
  if ( voyeur_id && detcyl )
  {
    if ( !this->voyeur_table )
    {
      v5 = (LongNIValHash<GlobalVoyeurInfo> *)operator new(0x18u);
      if ( v5 )
        LongNIValHash<GlobalVoyeurInfo>::LongNIValHash<GlobalVoyeurInfo>(v5, 0x20u);
      else
        v6 = 0;
      v3->voyeur_table = v6;
    }
    v7 = HashBase<unsigned long>::remove((HashBase<unsigned long> *)&v3->voyeur_table->vfptr, voyeur_id);
    if ( v7 )
    {
      v8 = v7[1].vfptr;
      v9 = v7[1].id;
      info.type = (unsigned int)v7[1].hash_next;
      v7->vfptr->__vecDelDtor(v7, 1u);
      *(_QWORD *)v10 = __PAIR__(info.type, (unsigned int)v8);
      *(_DWORD *)&v10[8] = v9 + 1;
      LongNIValHash<GlobalVoyeurInfo>::add(v3->voyeur_table, *(GlobalVoyeurInfo *)v10, voyeur_id);
      result = 1;
    }
    else
    {
      *(_DWORD *)v11 = voyeur_id;
      *(_DWORD *)&v11[4] = detcyl->detection_type;
      *(_DWORD *)&v11[8] = 1;
      LongNIValHash<GlobalVoyeurInfo>::add(v3->voyeur_table, *(GlobalVoyeurInfo *)v11, voyeur_id);
      v12 = 0;
      if ( v3->num_objects )
      {
        do
        {
          v13 = v3->object_list.data[v12];
          v14 = v13->id;
          if ( v14 != voyeur_id && v14 && !v13->parent )
          {
            v15 = CPhysicsObj::GetObjectA(voyeur_id);
            if ( v15 )
            {
              info.object_iid = v13->id;
              info.type = 1;
              CPhysicsObj::receive_detection_update((CPhysicsObj *)v15, (DetectionInfo *)&info);
            }
          }
          ++v12;
        }
        while ( v12 < v3->num_objects );
      }
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0052BC90) --------------------------------------------------------  // acclient.c:347501
int __thiscall CObjCell::remove_voyeur(CObjCell *this, unsigned int voyeur_id, DetectionCylsphere *detcyl)
{
  CObjCell *v3; // edi@1
  HashBase<unsigned long> *v4; // ecx@1
  HashBaseData<unsigned long> *v5; // eax@2
  HashBaseData<unsigned long>Vtbl *v6; // ebx@3
  HashBaseData<unsigned long> *v7; // ebp@3
  unsigned int v8; // esi@3
  int v9; // esi@3
  _BYTE v10[12]; // ST00_12@4
  int result; // eax@4
  unsigned int v12; // ebx@5
  CPhysicsObj *v13; // esi@6
  unsigned int v14; // eax@6
  HashBaseData<unsigned long> *v15; // eax@9
  DetectionInfo info; // [sp+10h] [bp-8h]@10

  v3 = this;
  v4 = (HashBase<unsigned long> *)&this->voyeur_table->vfptr;
  if ( v4 && (v5 = HashBase<unsigned long>::remove(v4, voyeur_id)) != 0 )
  {
    v6 = v5[1].vfptr;
    v7 = v5[1].hash_next;
    v8 = v5[1].id;
    v5->vfptr->__vecDelDtor(v5, 1u);
    v9 = v8 - 1;
    if ( v9 <= 0 )
    {
      v12 = 0;
      if ( v3->num_objects )
      {
        do
        {
          v13 = v3->object_list.data[v12];
          v14 = v13->id;
          if ( v14 != voyeur_id && v14 && !v13->parent )
          {
            v15 = CPhysicsObj::GetObjectA(voyeur_id);
            if ( v15 )
            {
              info.object_id = v13->id;
              info.object_status = 2;
              CPhysicsObj::receive_detection_update((CPhysicsObj *)v15, &info);
            }
          }
          ++v12;
        }
        while ( v12 < v3->num_objects );
      }
      result = 1;
    }
    else
    {
      *(_DWORD *)v10 = v6;
      *(_QWORD *)&v10[4] = __PAIR__(v9, (unsigned int)v7);
      LongNIValHash<GlobalVoyeurInfo>::add(v3->voyeur_table, *(GlobalVoyeurInfo *)v10, voyeur_id);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0052BD80) --------------------------------------------------------  // acclient.c:347568
void __thiscall CObjCell::update_all_voyeur(CObjCell *this, CPhysicsObj *object, DetectionType type)
{
  unsigned int v3; // eax@3
  CPhysicsObj *v4; // edi@7
  unsigned int v5; // eax@10
  HashBaseData<unsigned long> *v6; // eax@13
  DetectionInfo info; // [sp+4h] [bp-1Ch]@14
  LongNIValHashIter<GlobalVoyeurInfo> iter; // [sp+Ch] [bp-14h]@6

  if ( object->id )
  {
    if ( !object->parent )
    {
      v3 = object->state;
      if ( !(BYTE1(v3) & 0x40) || type != 1 )
      {
        if ( this->voyeur_table )
        {
          LongNIValHashIter<SurfInfo *>::LongNIValHashIter<SurfInfo *>(&iter, this->voyeur_table);
          if ( !iter.fEnd_ )
          {
            v4 = object;
            do
            {
              if ( iter.curPtr_ )
                v4 = (CPhysicsObj *)iter.curPtr_->id;
              v5 = object->id;
              if ( (CPhysicsObj *)v5 != v4 && v5 && !object->parent )
              {
                v6 = CPhysicsObj::GetObjectA((unsigned int)v4);
                if ( v6 )
                {
                  info.object_id = object->id;
                  info.object_status = type;
                  CPhysicsObj::receive_detection_update((CPhysicsObj *)v6, &info);
                }
              }
              HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&iter.myHash_);
            }
            while ( !iter.fEnd_ );
          }
        }
      }
    }
  }
}

//----- (0052BE30) --------------------------------------------------------  // acclient.c:347616
void __thiscall CObjCell::hide_object(CObjCell *this, CPhysicsObj *obj)
{
  CObjCell::update_all_voyeur(this, obj, LeftDetection);
}

//----- (0052BE40) --------------------------------------------------------  // acclient.c:347622
void __thiscall CObjCell::unhide_object(CObjCell *this, CPhysicsObj *obj)
{
  unsigned int v2; // eax@3
  CPhysicsObj *v3; // edi@6
  unsigned int v4; // eax@9
  HashBaseData<unsigned long> *v5; // eax@12
  DetectionInfo info; // [sp+4h] [bp-1Ch]@13
  LongNIValHashIter<GlobalVoyeurInfo> v7; // [sp+Ch] [bp-14h]@5

  if ( obj->id )
  {
    if ( !obj->parent )
    {
      v2 = obj->state;
      if ( !(BYTE1(v2) & 0x40) )
      {
        if ( this->voyeur_table )
        {
          LongNIValHashIter<SurfInfo *>::LongNIValHashIter<SurfInfo *>(&v7, this->voyeur_table);
          if ( !v7.fEnd_ )
          {
            v3 = obj;
            do
            {
              if ( v7.curPtr_ )
                v3 = (CPhysicsObj *)v7.curPtr_->id;
              v4 = obj->id;
              if ( (CPhysicsObj *)v4 != v3 && v4 && !obj->parent )
              {
                v5 = CPhysicsObj::GetObjectA((unsigned int)v3);
                if ( v5 )
                {
                  info.object_id = obj->id;
                  info.object_status = 1;
                  CPhysicsObj::receive_detection_update((CPhysicsObj *)v5, &info);
                }
              }
              HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&v7.myHash_);
            }
            while ( !v7.fEnd_ );
          }
        }
      }
    }
  }
}

//----- (0052BEF0) --------------------------------------------------------  // acclient.c:347670
LongNIValHash<GlobalVoyeurInfo> *__thiscall LongNIValHash<GlobalVoyeurInfo>::vector_deleting_destructor(LongNIValHash<GlobalVoyeurInfo> *this, unsigned int a2)
{
  LongNIValHash<GlobalVoyeurInfo> *v2; // esi@1

  v2 = this;
  LongNIValHash<GlobalVoyeurInfo>::~LongNIValHash<GlobalVoyeurInfo>(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0052BF10) --------------------------------------------------------  // acclient.c:347682
void __thiscall LongNIValHash<GlobalVoyeurInfo>::~LongNIValHash<GlobalVoyeurInfo>(LongNIValHash<GlobalVoyeurInfo> *this)
{
  LongNIValHash<GlobalVoyeurInfo> *v1; // esi@1
  int v2; // eax@3
  LongNIValHashIter<GlobalVoyeurInfo> v3; // [sp+4h] [bp-14h]@1

  v1 = this;
  this->vfptr = (HashBase<unsigned long>Vtbl *)&LongNIValHash<GlobalVoyeurInfo>::vftable;
  LongNIValHashIter<SurfInfo *>::LongNIValHashIter<SurfInfo *>(&v3, this);
  while ( !v3.fEnd_ )
    HashBaseIter<unsigned long>::DeleteCurrent((HashBaseIter<unsigned long> *)&v3.myHash_);
  v2 = v1->fPlacementNew_;
  v1->vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( !v2 )
    operator delete[](v1->buckets);
}
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);
// 7C8BCC: using guessed type int (__thiscall *LongNIValHash<GlobalVoyeurInfo>::vftable)(void *, char);

//----- (0052BF60) --------------------------------------------------------  // acclient.c:347702
void __thiscall CObjCell::add_object(CObjCell *this, CPhysicsObj *_object)
{
  CObjCell *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@3
  CPhysicsObj **v5; // edx@3
  unsigned int v6; // eax@5
  LongNIValHash<GlobalVoyeurInfo> *v7; // esi@6
  CPhysicsObj *v8; // esi@8
  unsigned int v9; // eax@11
  HashBaseData<unsigned long> *v10; // eax@14
  DetectionInfo info; // [sp+8h] [bp-1Ch]@15
  LongNIValHashIter<GlobalVoyeurInfo> v12; // [sp+10h] [bp-14h]@7

  v2 = this;
  v3 = this->object_list.sizeOf;
  if ( this->num_objects >= v3 )
    DArray<CPhysicsObj *>::grow(&this->object_list, v3 + 5);
  v4 = v2->num_objects;
  v5 = v2->object_list.data;
  v2->num_objects = v4 + 1;
  v5[v4] = _object;
  if ( _object->id )
  {
    if ( !_object->parent )
    {
      v6 = _object->state;
      if ( !(BYTE1(v6) & 0x40) )
      {
        v7 = v2->voyeur_table;
        if ( v7 )
        {
          LongNIValHashIter<SurfInfo *>::LongNIValHashIter<SurfInfo *>(&v12, v7);
          if ( !v12.fEnd_ )
          {
            v8 = _object;
            do
            {
              if ( v12.curPtr_ )
                v8 = (CPhysicsObj *)v12.curPtr_->id;
              v9 = _object->id;
              if ( (CPhysicsObj *)v9 != v8 && v9 && !_object->parent )
              {
                v10 = CPhysicsObj::GetObjectA((unsigned int)v8);
                if ( v10 )
                {
                  info.object_id = _object->id;
                  info.object_status = 1;
                  CPhysicsObj::receive_detection_update((CPhysicsObj *)v10, &info);
                }
              }
              HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&v12.myHash_);
            }
            while ( !v12.fEnd_ );
          }
        }
      }
    }
  }
}

//----- (0052C040) --------------------------------------------------------  // acclient.c:347764
void __thiscall CObjCell::remove_object(CObjCell *this, CPhysicsObj *_object)
{
  CObjCell *v2; // esi@1
  unsigned int v3; // ebx@1
  unsigned int v4; // eax@1
  CPhysicsObj **v5; // edx@2
  CPhysicsObj **v6; // ecx@2
  unsigned int v7; // eax@6

  v2 = this;
  v3 = this->num_objects;
  v4 = 0;
  if ( v3 )
  {
    v5 = this->object_list.data;
    v6 = this->object_list.data;
    while ( *v6 != _object )
    {
      ++v4;
      ++v6;
      if ( v4 >= v2->num_objects )
        return;
    }
    v2->num_objects = v3 - 1;
    v5[v4] = v5[v3 - 1];
    CObjCell::update_all_voyeur(v2, _object, LeftDetection);
    v7 = v2->num_objects;
    if ( v7 + 10 < v2->object_list.sizeOf )
      DArray<CPhysicsObj *>::shrink(&v2->object_list, v7 + 5);
  }
}

//----- (006FDD20) --------------------------------------------------------  // acclient.c:786076
void _E73_91()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8446FC, PFID_A8R8G8B8);
}

//----- (006FDD30) --------------------------------------------------------  // acclient.c:786082
void sub_6FDD30()
{
  LODWORD(dword_844734) = 1053364187;
}

//----- (006FDD40) --------------------------------------------------------  // acclient.c:786088
void sub_6FDD40()
{
  flt_844738 = 1000.0 + 1.0;
}

//----- (006FDD60) --------------------------------------------------------  // acclient.c:786094
void sub_6FDD60()
{
  flt_84473C = 24.0 * 8.0;
}

//----- (006FDD80) --------------------------------------------------------  // acclient.c:786100
void sub_6FDD80()
{
  flt_844740 = 24.0 * 0.5;
}

//----- (006FDDA0) --------------------------------------------------------  // acclient.c:786106
int _E99_26()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_25, "Render.TextureFiltering");
  return atexit(sub_7684A0);
}

//----- (006FDDC0) --------------------------------------------------------  // acclient.c:786113
int _E102_17()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_25, "Render.LandscapeDetailTextures");
  return atexit(sub_7684D0);
}

//----- (006FDDE0) --------------------------------------------------------  // acclient.c:786120
int _E105_31()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_25, "Render.BuildingDetailTextures");
  return atexit(sub_768500);
}

//----- (006FDE00) --------------------------------------------------------  // acclient.c:786127
int _E108_71()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_25, "Render.FieldOfView");
  return atexit(sub_768530);
}

//----- (006FDE20) --------------------------------------------------------  // acclient.c:786134
int _E111_39()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_25, "Render.LandscapeTextureDetail");
  return atexit(sub_768560);
}

//----- (006FDE40) --------------------------------------------------------  // acclient.c:786141
int _E114_46()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_25, "Render.EnvironmentTextureDetail");
  return atexit(sub_768590);
}

//----- (006FDE60) --------------------------------------------------------  // acclient.c:786148
int _E117_57()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_25, "Render.SceneryDrawDistance");
  return atexit(sub_7685C0);
}

//----- (006FDE80) --------------------------------------------------------  // acclient.c:786155
int _E120_53()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_25, "Render.LandscapeDrawDistance");
  return atexit(sub_7685F0);
}

//----- (006FDEA0) --------------------------------------------------------  // acclient.c:786162
int _E123_30()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_25, "Render.ScreenBrightness");
  return atexit(sub_768620);
}

//----- (006FDEC0) --------------------------------------------------------  // acclient.c:786169
int _E126_36()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_25, "Render.AspectRatio");
  return atexit(sub_768650);
}

//----- (006FDEE0) --------------------------------------------------------  // acclient.c:786176
int _E129_28()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_25, "Render.DisplayAdapter");
  return atexit(_E130_96);
}

//----- (006FDF00) --------------------------------------------------------  // acclient.c:786183
int _E132_31()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_25, "Render.MaxHardwareClass");
  return atexit(_E133_90);
}

//----- (006FDF20) --------------------------------------------------------  // acclient.c:786190
int _E135_34()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_25, "Render.AutomaticDegrades");
  return atexit(_E136_73);
}

//----- (006FDF40) --------------------------------------------------------  // acclient.c:786197
int _E138_26()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_25, "Render.GraphicsPerformance");
  return atexit(_E139_73);
}

//----- (006FDF60) --------------------------------------------------------  // acclient.c:786204
int _E141_26()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_25, "Render.DegradeDistance");
  return atexit(_E142_68);
}

//----- (006FDF80) --------------------------------------------------------  // acclient.c:786211
int _E144_25()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_25, "Render.MultiPassAlpha");
  return atexit(_E145_70);
}

//----- (006FDFA0) --------------------------------------------------------  // acclient.c:786218
int _E147_23()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_25, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_84478C, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_844790, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_844794, "Anisotropic");
  return atexit(_E148_67);
}

//----- (006FDFF0) --------------------------------------------------------  // acclient.c:786228
int _E150_24()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_25, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_84479C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8447A0, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8447A4, "High");
  PStringBase<char>::PStringBase<char>(&stru_8447A8, "VeryHigh");
  return atexit(_E151_65);
}

//----- (006FE050) --------------------------------------------------------  // acclient.c:786239
int _E153_22()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_25, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8447B0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8447B4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8447B8, "High");
  PStringBase<char>::PStringBase<char>(&stru_8447BC, "VeryHigh");
  return atexit(_E154_66);
}

//----- (006FE0B0) --------------------------------------------------------  // acclient.c:786250
int _E156_24()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_25, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8447C4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8447C8, "High");
  return atexit(_E157_62);
}

//----- (006FE0F0) --------------------------------------------------------  // acclient.c:786259
int _E159_22()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_25, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8447D0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8447D4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8447D8, "High");
  PStringBase<char>::PStringBase<char>(&stru_8447DC, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8447E0, "Extreme");
  return atexit(_E160_65);
}

//----- (006FE160) --------------------------------------------------------  // acclient.c:786271
int _E162_24()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_25, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8447E8, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8447EC, "Wide");
  return atexit(_E163_58);
}

//----- (006FE1A0) --------------------------------------------------------  // acclient.c:786280
int _E165_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_49, "None");
  return atexit(_E166_60);
}

//----- (006FE1C0) --------------------------------------------------------  // acclient.c:786287
int _E168_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_49, "Speed");
  return atexit(_E169_59);
}

//----- (006FE1E0) --------------------------------------------------------  // acclient.c:786294
int _E171_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_49, "Noise");
  return atexit(_E172_57);
}

//----- (006FE200) --------------------------------------------------------  // acclient.c:786301
int _E174_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_49, "Sine");
  return atexit(_E175_54);
}

//----- (006FE220) --------------------------------------------------------  // acclient.c:786308
int _E177_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_49, "Square");
  return atexit(_E178_54);
}

//----- (006FE240) --------------------------------------------------------  // acclient.c:786315
int _E180_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_49, "Bounce");
  return atexit(_E181_54);
}

//----- (006FE260) --------------------------------------------------------  // acclient.c:786322
int _E183_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_49, "Perlin");
  return atexit(_E184_51);
}

//----- (006FE280) --------------------------------------------------------  // acclient.c:786329
int _E186_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_49, "Fractal");
  return atexit(_E187_50);
}

//----- (006FE2A0) --------------------------------------------------------  // acclient.c:786336
int _E189_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_49, "FrameLoop");
  return atexit(_E190_51);
}

//----- (006FE2C0) --------------------------------------------------------  // acclient.c:786343
void _E192_15()
{
  dword_844814 = 1024;
}

//----- (006FE2D0) --------------------------------------------------------  // acclient.c:786349
void _E194_4()
{
  dword_844818 = 0x7FFF;
}

//----- (006FE2E0) --------------------------------------------------------  // acclient.c:786355
int _E196_17()
{
  const int result; // eax@1

  result = dword_844814;
  INITIAL_MAX_DATA_RATE_85 = dword_844814;
  return result;
}

//----- (006FE2F0) --------------------------------------------------------  // acclient.c:786365
void _E198_13()
{
  flt_844820 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FE310) --------------------------------------------------------  // acclient.c:786371
void _E200_2()
{
  dbl_844828 = 1.0 / 30.0;
}

//----- (006FE330) --------------------------------------------------------  // acclient.c:786377
void _E202_14()
{
  dbl_844830 = 1.0 / 5.0;
}

//----- (006FE350) --------------------------------------------------------  // acclient.c:786383
int _E204_9()
{
  return atexit(_E205_39);
}

//----- (006FE360) --------------------------------------------------------  // acclient.c:786389
int _E207_6()
{
  return atexit(_E208_43);
}

//----- (006FE370) --------------------------------------------------------  // acclient.c:786395
int _E210_9()
{
  return atexit(_E211_39);
}

//----- (006FE380) --------------------------------------------------------  // acclient.c:786401
int sub_6FE380()
{
  return atexit(nullsub_1155);
}

//----- (007684A0) --------------------------------------------------------  // acclient.c:895101
void __cdecl sub_7684A0()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007684D0) --------------------------------------------------------  // acclient.c:895114
void __cdecl sub_7684D0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768500) --------------------------------------------------------  // acclient.c:895127
void __cdecl sub_768500()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768530) --------------------------------------------------------  // acclient.c:895140
void __cdecl sub_768530()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768560) --------------------------------------------------------  // acclient.c:895153
void __cdecl sub_768560()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768590) --------------------------------------------------------  // acclient.c:895166
void __cdecl sub_768590()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007685C0) --------------------------------------------------------  // acclient.c:895179
void __cdecl sub_7685C0()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007685F0) --------------------------------------------------------  // acclient.c:895192
void __cdecl sub_7685F0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768620) --------------------------------------------------------  // acclient.c:895205
void __cdecl sub_768620()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768650) --------------------------------------------------------  // acclient.c:895218
void __cdecl sub_768650()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768680) --------------------------------------------------------  // acclient.c:895231
void __cdecl _E130_96()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007686B0) --------------------------------------------------------  // acclient.c:895244
void __cdecl _E133_90()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007686E0) --------------------------------------------------------  // acclient.c:895257
void __cdecl _E136_73()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768710) --------------------------------------------------------  // acclient.c:895270
void __cdecl _E139_73()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768740) --------------------------------------------------------  // acclient.c:895283
void __cdecl _E142_68()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768770) --------------------------------------------------------  // acclient.c:895296
void __cdecl _E145_70()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007687A0) --------------------------------------------------------  // acclient.c:895309
void __cdecl _E148_67()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_25;
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

//----- (007687E0) --------------------------------------------------------  // acclient.c:895334
void __cdecl _E151_65()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_25;
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

//----- (00768820) --------------------------------------------------------  // acclient.c:895359
void __cdecl _E154_66()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_25;
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

//----- (00768860) --------------------------------------------------------  // acclient.c:895384
void __cdecl _E157_62()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_25;
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

//----- (007688A0) --------------------------------------------------------  // acclient.c:895409
void __cdecl _E160_65()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_25;
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

//----- (007688E0) --------------------------------------------------------  // acclient.c:895434
void __cdecl _E163_58()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_49;
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

//----- (00768920) --------------------------------------------------------  // acclient.c:895459
void __cdecl _E166_60()
{
  char *v0; // esi@1

  v0 = &waveform_None_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768950) --------------------------------------------------------  // acclient.c:895472
void __cdecl _E169_59()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768980) --------------------------------------------------------  // acclient.c:895485
void __cdecl _E172_57()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007689B0) --------------------------------------------------------  // acclient.c:895498
void __cdecl _E175_54()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007689E0) --------------------------------------------------------  // acclient.c:895511
void __cdecl _E178_54()
{
  char *v0; // esi@1

  v0 = &waveform_Square_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768A10) --------------------------------------------------------  // acclient.c:895524
void __cdecl _E181_54()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768A40) --------------------------------------------------------  // acclient.c:895537
void __cdecl _E184_51()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768A70) --------------------------------------------------------  // acclient.c:895550
void __cdecl _E187_50()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768AA0) --------------------------------------------------------  // acclient.c:895563
void __cdecl _E190_51()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

