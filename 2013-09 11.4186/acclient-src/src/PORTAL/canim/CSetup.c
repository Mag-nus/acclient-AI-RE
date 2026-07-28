/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSetup
   Object     : PORTAL\canim\CSetup.obj
   Functions  : 25
   Addresses  : 0051FD20 - 006FD620 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051FD20) --------------------------------------------------------  // acclient.c:334267
int __thiscall CSphere::UnPack(CSphere *this, void **addr, unsigned int size)
{
  char *v3; // edx@2
  char *v4; // edx@2

  if ( size >= 0xC )
  {
    LODWORD(this->center.x) = *(_DWORD *)*addr;
    v3 = (char *)*addr + 4;
    *addr = v3;
    LODWORD(this->center.y) = *(_DWORD *)v3;
    v4 = (char *)*addr + 4;
    *addr = v4;
    LODWORD(this->center.z) = *(_DWORD *)v4;
    *addr = (char *)*addr + 4;
  }
  LODWORD(this->radius) = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  return 1;
}

//----- (0051FD60) --------------------------------------------------------  // acclient.c:334289
PlacementType *__thiscall PlacementType::vector_deleting_destructor(PlacementType *this, unsigned int a2)
{
  PlacementType *v2; // esi@1

  v2 = this;
  this->vfptr = (HashBaseData<unsigned long>Vtbl *)PlacementType::vftable;
  AnimFrame::Destroy(&this->anim_frame);
  v2->hash_next = 0;
  v2->id = 0;
  v2->vfptr = (HashBaseData<unsigned long>Vtbl *)LongHashData::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);
// 7C7B74: using guessed type int (__thiscall *PlacementType::vftable[2])(void *, char);

//----- (0051FDA0) --------------------------------------------------------  // acclient.c:334307
void __thiscall CSetup::GetSubDataIDs(CSetup *this, QualifiedDataIDArray *id_array)
{
  CSetup *v2; // esi@1
  signed int i; // ebx@1
  QualifiedDataID *v4; // eax@2
  QualifiedDataID *v5; // eax@3
  QualifiedDataID *v6; // eax@3
  QualifiedDataID *v7; // eax@3
  QualifiedDataID *v8; // eax@3
  QualifiedDataID *v9; // eax@3
  QualifiedDataID v10; // [sp+10h] [bp-8h]@2

  v2 = this;
  for ( i = 0; i < (signed int)v2->num_parts; ++i )
  {
    QualifiedDataID::QualifiedDataID(&v10, v2->parts[i], 0);
    QualifiedDataIDArray::AddQDID(id_array, v4, 0);
  }
  QualifiedDataID::QualifiedDataID(&v10, v2->default_anim_id, 0);
  QualifiedDataIDArray::AddQDID(id_array, v5, 0);
  QualifiedDataID::QualifiedDataID(&v10, v2->default_script_id, 0);
  QualifiedDataIDArray::AddQDID(id_array, v6, 0);
  QualifiedDataID::QualifiedDataID(&v10, v2->default_mtable_id, 0);
  QualifiedDataIDArray::AddQDID(id_array, v7, 0);
  QualifiedDataID::QualifiedDataID(&v10, v2->default_stable_id, 0);
  QualifiedDataIDArray::AddQDID(id_array, v8, 0);
  QualifiedDataID::QualifiedDataID(&v10, v2->default_phstable_id, 0);
  QualifiedDataIDArray::AddQDID(id_array, v9, 0);
}

//----- (0051FEB0) --------------------------------------------------------  // acclient.c:334353
LongHash<LocationType> *__thiscall LongHash<LocationType>::scalar_deleting_destructor(LongHash<LocationType> *this, unsigned int a2)
{
  LongHash<LocationType> *v2; // esi@1

  v2 = this;
  this->vfptr = (HashBase<unsigned long>Vtbl *)&LongHash<LocationType>::vftable;
  HashBase<unsigned long>::~HashBase<unsigned long>((HashBase<unsigned long> *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C7B78: using guessed type int (__thiscall *LongHash<LocationType>::vftable)(void *, char);

//----- (0051FEE0) --------------------------------------------------------  // acclient.c:334367
void __thiscall CSetup::CSetup(CSetup *this)
{
  CSetup *v1; // esi@1
  int v2; // ecx@1
  int v3; // ecx@1
  signed int v4; // eax@1
  int v5; // edx@2
  unsigned int v6; // eax@3

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_8444A0);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (InterfaceVtbl *)&CSetup::vftable;
  v1->vfptr = (PackObjVtbl *)&CSetup::vftable;
  v1->num_parts = 0;
  v1->parts = 0;
  v1->parent_index = 0;
  v1->default_scale = 0;
  v1->num_cylsphere = 0;
  v1->cylsphere = 0;
  v1->num_sphere = 0;
  v1->sphere = 0;
  v1->has_physics_bsp = 0;
  v1->allow_free_heading = 1;
  LODWORD(v1->height) = 0;
  LODWORD(v1->radius) = 0;
  LODWORD(v1->step_down_height) = 0;
  LODWORD(v1->step_up_height) = 0;
  LODWORD(v1->sorting_sphere.radius) = 0;
  v2 = (int)&v1->sorting_sphere;
  *(_DWORD *)v2 = 0;
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  LODWORD(v1->selection_sphere.radius) = 0;
  v3 = (int)&v1->selection_sphere;
  *(_DWORD *)v3 = 0;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  v1->num_lights = 0;
  v1->lights = 0;
  LODWORD(v1->anim_scale.x) = 1065353216;
  LODWORD(v1->anim_scale.y) = 1065353216;
  LODWORD(v1->anim_scale.z) = 1065353216;
  v1->holding_locations = 0;
  v1->connection_points = 0;
  v1->placement_frames.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  v1->placement_frames.fPlacementNew_ = 0;
  v1->placement_frames.buckets = (HashBaseData<unsigned long> **)operator new[](8u);
  v1->placement_frames.table_size = 2;
  v1->placement_frames.key_shift = 8;
  v1->placement_frames.table_mask = 0;
  v4 = 1;
  do
  {
    v5 = v4 | v1->placement_frames.table_mask;
    v4 *= 2;
    v1->placement_frames.table_mask = v5;
  }
  while ( (v4 | (unsigned int)v5) < v1->placement_frames.table_size );
  v6 = 0;
  do
    v1->placement_frames.buckets[v6++] = 0;
  while ( v6 < v1->placement_frames.table_size );
  v1->placement_frames.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  v1->default_anim_id.id = stru_8444A0.id;
  v1->default_script_id.id = stru_8444A0.id;
  v1->default_mtable_id.id = stru_8444A0.id;
  v1->default_stable_id.id = stru_8444A0.id;
  v1->default_phstable_id.id = stru_8444A0.id;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);
// 7C7B7C: using guessed type void *CSetup::vftable;
// 7C7B90: using guessed type __int32 (__stdcall *CSetup::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00520080) --------------------------------------------------------  // acclient.c:334449
CSetup *__thiscall CSetup::vector_deleting_destructor(CSetup *this, unsigned int a2)
{
  return CSetup::vector_deleting_destructor((CSetup *)((char *)this - 48), a2);
}

//----- (00520090) --------------------------------------------------------  // acclient.c:334455
CSetup *__cdecl CSetup::makeSimpleSetup(IDClass<_tagDataID,32,0> gfxobj_id)
{
  CSetup *v1; // eax@1
  int v2; // eax@2
  int v3; // edi@2
  CSetup *result; // eax@3
  void *v5; // eax@4
  int v6; // esi@5
  int v7; // eax@5
  QualifiedDataID *v8; // eax@9
  int v9; // eax@9
  int v10; // edx@10
  int v11; // ecx@12
  void *v12; // eax@14
  void *v13; // esi@14
  void *v14; // eax@15
  int v15; // ebx@16
  int v16; // ecx@18
  QualifiedDataID v17; // [sp+8h] [bp-8h]@9

  v1 = (CSetup *)operator new(0xD8u);
  if ( v1 && (CSetup::CSetup(v1), (v3 = v2) != 0) )
  {
    v5 = operator new[](8u);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = 1;
      vector_constructor_iterator(
        (char *)v5 + 4,
        4u,
        1,
        (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    *(_DWORD *)(v3 + 60) = v7;
    if ( !v7 )
      goto LABEL_21;
    *(_DWORD *)(v3 + 56) = 1;
    *(_DWORD *)v7 = gfxobj_id.id;
    QualifiedDataID::QualifiedDataID(&v17, gfxobj_id, 6u);
    v9 = DBObj::Get(v8);
    if ( v9 )
    {
      v10 = *(_DWORD *)(v9 + 116);
      if ( v10 || (v10 = *(_DWORD *)(v9 + 144)) != 0 )
      {
        v11 = v3 + 112;
        *(_DWORD *)v11 = *(_DWORD *)v10;
        *(_DWORD *)(v11 + 4) = *(_DWORD *)(v10 + 4);
        *(_DWORD *)(v11 + 8) = *(_DWORD *)(v10 + 8);
        *(_DWORD *)(v11 + 12) = *(_DWORD *)(v10 + 12);
      }
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 20))(v9);
    }
    v12 = operator new(0x1Cu);
    v13 = v12;
    if ( v12 )
    {
      *((_DWORD *)v12 + 1) = 0;
      *((_DWORD *)v12 + 2) = 0;
      *(_DWORD *)v12 = PlacementType::vftable;
      *((_DWORD *)v12 + 3) = 0;
      *((_DWORD *)v12 + 4) = 0;
      *((_DWORD *)v12 + 5) = 0;
      *((_DWORD *)v12 + 6) = 0;
      v14 = operator new[](0x20u);
      if ( v14 )
      {
        v15 = (int)((char *)v14 + 4);
        *(_DWORD *)v14 = 1;
        vector_constructor_iterator((char *)v14 + 4, 0x1Cu, 1, (void *(__thiscall *)(void *))AFrame::AFrame);
      }
      else
      {
        v15 = 0;
      }
      *((_DWORD *)v13 + 3) = v15;
      *((_DWORD *)v13 + 2) = 0;
      v16 = *(_DWORD *)(v3 + 180);
      *(_DWORD *)(v3 + 176);
      *((_DWORD *)v13 + 1) = **(_DWORD **)(v3 + 184);
      **(_DWORD **)(v3 + 184) = v13;
      *((_DWORD *)v13 + 6) = 1;
      result = (CSetup *)v3;
    }
    else
    {
LABEL_21:
      (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v3 + 24))(v3, 1);
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7C7B74: using guessed type int (__thiscall *PlacementType::vftable[2])(void *, char);

//----- (005201F0) --------------------------------------------------------  // acclient.c:334561
void __cdecl CSetup::makeParticleSetup(unsigned int num_particles)
{
  CSetup *v1; // eax@1
  int v2; // eax@2

  v1 = (CSetup *)operator new(0xD8u);
  if ( v1 )
  {
    CSetup::CSetup(v1);
    if ( v2 )
    {
      *(_DWORD *)(v2 + 56) = num_particles;
      *(_DWORD *)(v2 + 60) = 0;
    }
  }
}

//----- (00520220) --------------------------------------------------------  // acclient.c:334579
int __thiscall CSetup::pack_size(CSetup *this)
{
  CSetup *v1; // ebp@1
  unsigned int *v2; // ecx@1
  unsigned int v3; // eax@1
  unsigned int v4; // esi@1
  int v5; // edi@1
  LongHash<LocationType> *v6; // ebx@5
  HashBase<unsigned long> *v7; // eax@5
  int v8; // edi@5
  HashBaseData<unsigned long> *v9; // ecx@6
  HashBaseData<unsigned long> *v10; // eax@11
  LongHash<LocationType> *v11; // ebx@15
  HashBase<unsigned long> *v12; // ecx@15
  int v13; // edi@15
  HashBaseData<unsigned long> *v14; // eax@16
  HashBaseData<unsigned long> *v15; // eax@21
  unsigned int v16; // ebx@26
  HashBase<unsigned long> *v17; // ebx@32
  int v18; // edi@32
  HashBaseData<unsigned long> *v19; // eax@33
  HashBaseData<unsigned long> **v20; // eax@37
  HashBaseData<unsigned long> *v21; // esi@37
  unsigned int v22; // ecx@42
  unsigned int v23; // eax@43
  int v24; // edi@48
  int v25; // ebx@49
  unsigned int v26; // eax@51
  int v27; // edi@51
  unsigned int v28; // eax@53
  int v29; // edi@53
  unsigned int v30; // esi@55
  signed int v31; // eax@55
  int v32; // ebx@55
  bool v33; // cf@57
  int v34; // edi@58
  int result; // eax@59
  void *dummy; // [sp+10h] [bp-20h]@1
  unsigned int num_holding_locations; // [sp+14h] [bp-1Ch]@5
  unsigned int i; // [sp+18h] [bp-18h]@53
  LongHashIter<LocationType> cpiter; // [sp+1Ch] [bp-14h]@5

  v1 = this;
  v2 = this->parent_index;
  v3 = v1->num_parts;
  v4 = 0;
  dummy = 0;
  v5 = 4 * v3 + 8;
  if ( v2 )
    v5 += 4 * v3;
  if ( v1->default_scale )
    v5 += 12 * v3;
  v6 = v1->holding_locations;
  v7 = (HashBase<unsigned long> *)&v1->holding_locations->vfptr;
  v8 = v5 + 4;
  num_holding_locations = 0;
  cpiter.myHash_ = v7;
  cpiter.lastThisChain_ = 0;
  cpiter.curBucket_ = 0;
  if ( v7 )
  {
    v9 = *v7->buckets;
    cpiter.fEnd_ = 0;
    cpiter.curPtr_ = v9;
    if ( !v9 )
    {
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&cpiter.myHash_);
      v7 = cpiter.myHash_;
    }
  }
  else
  {
    cpiter.fEnd_ = 1;
    cpiter.curPtr_ = 0;
  }
  if ( v6 )
  {
    cpiter.lastThisChain_ = 0;
    cpiter.curBucket_ = 0;
    if ( v7 )
    {
      v10 = *v7->buckets;
      cpiter.fEnd_ = 0;
      cpiter.curPtr_ = v10;
      if ( v10 || (HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&cpiter.myHash_), cpiter.curPtr_) )
      {
        do
        {
          ++num_holding_locations;
          HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&cpiter.myHash_);
        }
        while ( cpiter.curPtr_ );
      }
    }
    v8 += 36 * num_holding_locations;
  }
  v11 = v1->connection_points;
  v12 = (HashBase<unsigned long> *)&v1->connection_points->vfptr;
  v13 = v8 + 4;
  num_holding_locations = 0;
  cpiter.myHash_ = v12;
  cpiter.lastThisChain_ = 0;
  cpiter.curBucket_ = 0;
  if ( v12 )
  {
    v14 = *v12->buckets;
    cpiter.fEnd_ = 0;
    cpiter.curPtr_ = v14;
    if ( !v14 )
    {
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&cpiter.myHash_);
      v12 = cpiter.myHash_;
    }
  }
  else
  {
    cpiter.fEnd_ = 1;
    cpiter.curPtr_ = 0;
  }
  if ( v11 )
  {
    cpiter.lastThisChain_ = 0;
    cpiter.curBucket_ = 0;
    if ( v12 )
    {
      v15 = *v12->buckets;
      cpiter.fEnd_ = 0;
      cpiter.curPtr_ = v15;
      if ( v15 )
        goto LABEL_24;
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&cpiter.myHash_);
      v15 = cpiter.curPtr_;
      if ( cpiter.curPtr_ )
      {
        v12 = cpiter.myHash_;
        do
        {
          do
          {
LABEL_24:
            ++num_holding_locations;
            if ( !v15 )
              break;
            v15 = v15->hash_next;
          }
          while ( v15 );
          v16 = v12->table_size;
          while ( 1 )
          {
            ++cpiter.curBucket_;
            if ( cpiter.curBucket_ >= v16 )
              break;
            v15 = v12->buckets[cpiter.curBucket_];
            if ( v15 )
              goto LABEL_24;
          }
        }
        while ( v15 );
        goto LABEL_31;
      }
    }
LABEL_31:
    v13 += 36 * num_holding_locations;
  }
  v17 = (HashBase<unsigned long> *)&v1->placement_frames.vfptr;
  v18 = v13 + 4;
  cpiter.myHash_ = (HashBase<unsigned long> *)&v1->placement_frames.vfptr;
  cpiter.lastThisChain_ = 0;
  cpiter.curBucket_ = 0;
  if ( v1 == (CSetup *)-172 )
  {
    cpiter.fEnd_ = 1;
  }
  else
  {
    v19 = *v1->placement_frames.buckets;
    cpiter.fEnd_ = 0;
    cpiter.curPtr_ = v19;
    if ( !v19 )
    {
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&cpiter.myHash_);
      v17 = cpiter.myHash_;
    }
  }
  cpiter.lastThisChain_ = 0;
  cpiter.curBucket_ = 0;
  if ( v17 )
  {
    v20 = v17->buckets;
    cpiter.fEnd_ = 0;
    v21 = *v20;
    cpiter.curPtr_ = *v20;
    if ( !cpiter.curPtr_ )
    {
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&cpiter.myHash_);
      v21 = cpiter.curPtr_;
      if ( !cpiter.curPtr_ )
      {
LABEL_47:
        v4 = 0;
        goto LABEL_48;
      }
      v17 = cpiter.myHash_;
    }
    do
    {
      do
      {
LABEL_40:
        v18 += AnimFrame::pack_size((AnimFrame *)&v21[1], v1->num_parts) + 4;
        if ( !v21 )
          break;
        v21 = v21->hash_next;
      }
      while ( v21 );
      v22 = v17->table_size;
      while ( 1 )
      {
        v23 = cpiter.curBucket_++ + 1;
        if ( cpiter.curBucket_ >= v22 )
          break;
        v21 = v17->buckets[v23];
        if ( v21 )
          goto LABEL_40;
      }
    }
    while ( v21 );
    goto LABEL_47;
  }
LABEL_48:
  v24 = v18 + 4;
  if ( v1->num_cylsphere )
  {
    v25 = 0;
    do
    {
      v24 += CCylSphere::Pack(&v1->cylsphere[v25], &dummy, 0);
      ++v4;
      ++v25;
    }
    while ( v4 < v1->num_cylsphere );
  }
  v26 = v1->num_sphere;
  v27 = v24 + 4;
  if ( v26 )
    v27 += 16 * v26;
  v28 = v1->num_lights;
  v29 = v27 + 52;
  i = 0;
  if ( v28 > 0 )
  {
    num_holding_locations = 0;
    do
    {
      v30 = (unsigned int)((char *)v1->lights + num_holding_locations);
      v31 = EtherealHook::pack_size();
      v32 = v31 + 44;
      if ( v31 == -44 )
      {
        *(_DWORD *)dummy = *(_DWORD *)v30;
        dummy = (char *)dummy + 4;
        Frame::Pack((Frame *)(v30 + 4), &dummy, 0);
        RGBColor::Pack((RGBColor *)(v30 + 80), &dummy, 0);
        *(_DWORD *)dummy = *(_DWORD *)(v30 + 92);
        dummy = (char *)dummy + 4;
        *(_DWORD *)dummy = *(_DWORD *)(v30 + 96);
        dummy = (char *)dummy + 4;
        *(_DWORD *)dummy = *(_DWORD *)(v30 + 100);
        dummy = (char *)dummy + 4;
      }
      v29 += v32;
      v33 = i++ + 1 < v1->num_lights;
      num_holding_locations += 104;
    }
    while ( v33 );
  }
  v34 = v29 + 20;
  if ( v34 & 3 )
    result = v34 + 4 - (v34 & 3);
  else
    result = v34;
  return result;
}

//----- (00520580) --------------------------------------------------------  // acclient.c:334864
int __thiscall CSetup::Pack(CSetup *this, void **addr, unsigned int size)
{
  CSetup *v3; // ebp@1
  int result; // eax@1
  signed int v5; // eax@2
  void **v6; // esi@10
  char *v7; // edi@10
  char *v8; // edx@10
  unsigned int v9; // eax@10
  char *v10; // edi@10
  unsigned int v11; // eax@13
  unsigned int v12; // ebx@16
  int v13; // edx@17
  int v14; // eax@18
  char *v15; // edi@19
  char *v16; // ecx@19
  char *v17; // eax@19
  HashBase<unsigned long> *v18; // edx@21
  unsigned int v19; // eax@21
  HashBaseData<unsigned long> **v20; // ecx@22
  bool v21; // zf@22
  unsigned int v22; // ebx@23
  HashBaseData<unsigned long> *v23; // eax@30
  unsigned int v24; // ecx@30
  unsigned int v25; // ebx@40
  HashBaseData<unsigned long> **v26; // eax@41
  HashBaseData<unsigned long> *v27; // edi@41
  int v28; // edx@46
  float v29; // ebx@51
  unsigned int v30; // eax@51
  int v31; // ecx@52
  int v32; // edx@56
  int v33; // eax@56
  unsigned int v34; // ecx@56
  unsigned int v35; // ebx@68
  int v36; // eax@69
  int v37; // edi@69
  int v38; // edx@74
  int v39; // ebx@79
  unsigned int v40; // eax@79
  float v41; // edx@80
  unsigned int v42; // ecx@83
  float v43; // edx@84
  int v44; // eax@84
  unsigned int v45; // ebx@95
  float v46; // eax@96
  int v47; // edi@96
  DBObj *v48; // edi@106
  int v49; // ebx@107
  unsigned int v50; // ebx@109
  int v51; // ecx@109
  int v52; // edx@109
  int v53; // eax@110
  int v54; // ecx@112
  int v55; // edi@112
  int v56; // eax@113
  int v57; // edi@115
  int v58; // ecx@115
  int v59; // eax@115
  int v60; // edi@115
  int v61; // eax@115
  int v62; // edi@117
  int v63; // ecx@117
  int v64; // edi@120
  int v65; // ecx@120
  int v66; // edi@124
  int v67; // edx@125
  int v68; // ecx@125
  bool v69; // cf@126
  int v70; // ebx@127
  int v71; // edi@127
  int v72; // edx@127
  int v73; // ecx@127
  signed int v74; // eax@127
  int v75; // eax@127
  int v76; // ecx@128
  float v77; // [sp+4h] [bp-1Ch]@51
  unsigned int ret; // [sp+8h] [bp-18h]@1
  LongHashIter<LocationType> iter; // [sp+Ch] [bp-14h]@21
  void **addra; // [sp+24h] [bp+4h]@21
  void **addrb; // [sp+24h] [bp+4h]@51
  void **addrc; // [sp+24h] [bp+4h]@109
  void **addrd; // [sp+24h] [bp+4h]@122
  unsigned int i; // [sp+28h] [bp+8h]@123

  v3 = this;
  result = CSetup::pack_size((CSetup *)((char *)this - 48));
  ret = result;
  if ( size < result )
    return result;
  v5 = 0;
  if ( LODWORD(v3->m_timeStamp) )
    v5 = 1;
  if ( HIDWORD(v3->m_timeStamp) )
    v5 |= 2u;
  if ( *(_DWORD *)&v3->m_AllowedInFreeList )
    v5 |= 4u;
  if ( v3->m_DID.id )
    v5 |= 8u;
  v6 = addr;
  *(_DWORD *)*addr = v5;
  v7 = (char *)*addr + 4;
  *addr = v7;
  *(_DWORD *)v7 = *(_DWORD *)&v3->m_bLoaded;
  v8 = (char *)*addr + 4;
  *addr = v8;
  v9 = 0;
  v10 = v8;
  if ( *(_DWORD *)&v3->m_bLoaded )
  {
    do
    {
      *(_DWORD *)v10 = *(_DWORD *)(*((_DWORD *)&v3->m_bLoaded + 1) + 4 * v9);
      v10 = (char *)*addr + 4;
      *addr = v10;
      ++v9;
    }
    while ( v9 < *(_DWORD *)&v3->m_bLoaded );
  }
  if ( LODWORD(v3->m_timeStamp) )
  {
    v11 = 0;
    if ( *(_DWORD *)&v3->m_bLoaded )
    {
      do
      {
        *(_DWORD *)v10 = *(_DWORD *)(LODWORD(v3->m_timeStamp) + 4 * v11);
        v10 = (char *)*addr + 4;
        *addr = v10;
        ++v11;
      }
      while ( v11 < *(_DWORD *)&v3->m_bLoaded );
    }
  }
  if ( HIDWORD(v3->m_timeStamp) )
  {
    v12 = 0;
    if ( *(_DWORD *)&v3->m_bLoaded )
    {
      v13 = 0;
      do
      {
        v14 = v13 + HIDWORD(v3->m_timeStamp);
        if ( size >= 0xC )
        {
          *(_DWORD *)v10 = *(_DWORD *)v14;
          v15 = (char *)*addr + 4;
          *addr = v15;
          *(float *)v15 = *(float *)(v14 + 4);
          v16 = (char *)*addr + 4;
          *addr = v16;
          *(float *)v16 = *(float *)(v14 + 8);
          v17 = (char *)*addr + 4;
          *addr = v17;
          v10 = v17;
        }
        ++v12;
        v13 += 12;
      }
      while ( v12 < *(_DWORD *)&v3->m_bLoaded );
    }
  }
  v19 = 0;
  addra = 0;
  iter.myHash_ = (HashBase<unsigned long> *)LODWORD(v3->sorting_sphere.center.y);
  v18 = iter.myHash_;
  iter.lastThisChain_ = 0;
  if ( (_DWORD)iter.myHash_ )
  {
    v20 = iter.myHash_->buckets;
    v21 = *v20 == 0;
    iter.fEnd_ = 0;
    if ( !v21 )
      goto LABEL_29;
    v22 = iter.myHash_->table_size;
    while ( 1 )
    {
      ++v19;
      iter.lastThisChain_ = 0;
      if ( v19 >= v22 )
        break;
      if ( v20[v19] )
        goto LABEL_29;
    }
  }
  else
  {
    iter.curPtr_ = 0;
  }
  iter.fEnd_ = 1;
LABEL_29:
  if ( LODWORD(v3->sorting_sphere.center.y) )
  {
    v23 = *iter.myHash_->buckets;
    v24 = 0;
    iter.lastThisChain_ = 0;
    iter.curBucket_ = 0;
    iter.fEnd_ = 0;
    iter.curPtr_ = v23;
    if ( v23 )
    {
      do
      {
        do
        {
LABEL_33:
          addra = (void **)((char *)addra + 1);
          if ( !v23 )
            break;
          v23 = v23->hash_next;
        }
        while ( v23 );
        while ( 1 )
        {
          ++v24;
          if ( v24 >= v18->table_size )
            break;
          v23 = v18->buckets[v24];
          if ( v23 )
            goto LABEL_33;
        }
      }
      while ( v23 );
      goto LABEL_39;
    }
    HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&iter.myHash_);
    v23 = iter.curPtr_;
    if ( iter.curPtr_ )
    {
      v24 = iter.curBucket_;
      v18 = iter.myHash_;
      goto LABEL_33;
    }
  }
LABEL_39:
  *(_DWORD *)v10 = addra;
  *v6 = (char *)*v6 + 4;
  if ( LODWORD(v3->sorting_sphere.center.y) )
  {
    v25 = 0;
    if ( (_DWORD)iter.myHash_ )
    {
      v26 = iter.myHash_->buckets;
      v27 = *v26;
      if ( *v26 )
        goto LABEL_133;
      while ( 1 )
      {
        ++v25;
        if ( v25 >= iter.myHash_->table_size )
          break;
        v27 = v26[v25];
        if ( v27 )
          goto LABEL_46;
      }
      if ( v27 )
      {
LABEL_133:
        do
        {
          do
          {
LABEL_46:
            *(_DWORD *)*v6 = v27->id;
            v28 = (int)((char *)*v6 + 4);
            *v6 = (void *)v28;
            *(_DWORD *)v28 = v27[1].vfptr;
            *v6 = (char *)*v6 + 4;
            Frame::Pack((Frame *)&v27[1].hash_next, v6, size);
            v27 = v27->hash_next;
          }
          while ( v27 );
          while ( 1 )
          {
            ++v25;
            if ( v25 >= iter.myHash_->table_size )
              break;
            v27 = iter.myHash_->buckets[v25];
            if ( v27 )
              goto LABEL_46;
          }
        }
        while ( v27 );
      }
    }
  }
  v29 = v3->sorting_sphere.center.z;
  v30 = 0;
  addrb = 0;
  v77 = v3->sorting_sphere.center.z;
  if ( v29 != 0.0 )
  {
    v31 = *(_DWORD *)(LODWORD(v29) + 12);
    if ( !*(_DWORD *)v31 )
    {
      do
        ++v30;
      while ( v30 < *(_DWORD *)(LODWORD(v29) + 16) && !*(_DWORD *)(v31 + 4 * v30) );
    }
    if ( v29 != 0.0 )
    {
      v32 = *(_DWORD *)(LODWORD(v29) + 12);
      v33 = *(_DWORD *)v32;
      v34 = 0;
      if ( *(_DWORD *)v32 )
        goto LABEL_134;
      while ( 1 )
      {
        ++v34;
        if ( v34 >= *(_DWORD *)(LODWORD(v29) + 16) )
          break;
        v33 = *(_DWORD *)(v32 + 4 * v34);
        if ( v33 )
          goto LABEL_61;
      }
      if ( v33 )
      {
LABEL_134:
        do
        {
          do
          {
LABEL_61:
            addrb = (void **)((char *)addrb + 1);
            if ( !v33 )
              break;
            v33 = *(_DWORD *)(v33 + 4);
          }
          while ( v33 );
          while ( 1 )
          {
            ++v34;
            if ( v34 >= *(_DWORD *)(LODWORD(v29) + 16) )
              break;
            v33 = *(_DWORD *)(v32 + 4 * v34);
            if ( v33 )
              goto LABEL_61;
          }
        }
        while ( v33 );
      }
    }
  }
  *(_DWORD *)*v6 = addrb;
  *v6 = (char *)*v6 + 4;
  if ( LODWORD(v3->sorting_sphere.center.z) )
  {
    v35 = 0;
    if ( v77 != 0.0 )
    {
      v36 = *(_DWORD *)(LODWORD(v77) + 12);
      v37 = *(_DWORD *)v36;
      if ( *(_DWORD *)v36 )
        goto LABEL_135;
      while ( 1 )
      {
        ++v35;
        if ( v35 >= *(_DWORD *)(LODWORD(v77) + 16) )
          break;
        v37 = *(_DWORD *)(v36 + 4 * v35);
        if ( v37 )
          goto LABEL_74;
      }
      if ( v37 )
      {
LABEL_135:
        do
        {
          do
          {
LABEL_74:
            *(_DWORD *)*v6 = *(_DWORD *)(v37 + 8);
            v38 = (int)((char *)*v6 + 4);
            *v6 = (void *)v38;
            *(_DWORD *)v38 = *(_DWORD *)(v37 + 12);
            *v6 = (char *)*v6 + 4;
            Frame::Pack((Frame *)(v37 + 16), v6, size);
            v37 = *(_DWORD *)(v37 + 4);
          }
          while ( v37 );
          while ( 1 )
          {
            ++v35;
            if ( v35 >= *(_DWORD *)(LODWORD(v77) + 16) )
              break;
            v37 = *(_DWORD *)(*(_DWORD *)(LODWORD(v77) + 12) + 4 * v35);
            if ( v37 )
              goto LABEL_74;
          }
        }
        while ( v37 );
      }
    }
  }
  v39 = 0;
  v40 = 0;
  if ( v3 != (CSetup *)-124 )
  {
    v41 = v3->selection_sphere.center.z;
    if ( !*LODWORD(v41) )
    {
      do
        ++v40;
      while ( v40 < LODWORD(v3->selection_sphere.radius) && !*(_DWORD *)(LODWORD(v41) + 4 * v40) );
    }
  }
  v42 = 0;
  if ( v3 != (CSetup *)-124 )
  {
    v43 = v3->selection_sphere.center.z;
    v44 = *LODWORD(v43);
    if ( *LODWORD(v43) )
      goto LABEL_136;
    while ( 1 )
    {
      ++v42;
      if ( v42 >= LODWORD(v3->selection_sphere.radius) )
        break;
      v44 = *(_DWORD *)(LODWORD(v43) + 4 * v42);
      if ( v44 )
        goto LABEL_89;
    }
    if ( v44 )
    {
LABEL_136:
      do
      {
        do
        {
LABEL_89:
          ++v39;
          if ( !v44 )
            break;
          v44 = *(_DWORD *)(v44 + 4);
        }
        while ( v44 );
        while ( 1 )
        {
          ++v42;
          if ( v42 >= LODWORD(v3->selection_sphere.radius) )
            break;
          v44 = *(_DWORD *)(LODWORD(v43) + 4 * v42);
          if ( v44 )
            goto LABEL_89;
        }
      }
      while ( v44 );
    }
  }
  *(_DWORD *)*v6 = v39;
  v45 = 0;
  *v6 = (char *)*v6 + 4;
  if ( v3 != (CSetup *)-124 )
  {
    v46 = v3->selection_sphere.center.z;
    v47 = *LODWORD(v46);
    if ( *LODWORD(v46) )
      goto LABEL_137;
    while ( 1 )
    {
      ++v45;
      if ( v45 >= LODWORD(v3->selection_sphere.radius) )
        break;
      v47 = *(_DWORD *)(LODWORD(v46) + 4 * v45);
      if ( v47 )
        goto LABEL_101;
    }
    if ( v47 )
    {
LABEL_137:
      do
      {
        do
        {
LABEL_101:
          *(_DWORD *)*v6 = *(_DWORD *)(v47 + 8);
          *v6 = (char *)*v6 + 4;
          AnimFrame::Pack((AnimFrame *)(v47 + 12), *(_DWORD *)&v3->m_bLoaded, v6, size);
          v47 = *(_DWORD *)(v47 + 4);
        }
        while ( v47 );
        while ( 1 )
        {
          ++v45;
          if ( v45 >= LODWORD(v3->selection_sphere.radius) )
            break;
          v47 = *(_DWORD *)(LODWORD(v3->selection_sphere.center.z) + 4 * v45);
          if ( v47 )
            goto LABEL_101;
        }
      }
      while ( v47 );
    }
  }
  *(_DWORD *)*v6 = v3->m_pNext;
  *v6 = (char *)*v6 + 4;
  v48 = 0;
  if ( v3->m_pNext )
  {
    v49 = 0;
    do
    {
      CCylSphere::Pack((CCylSphere *)((char *)v3->m_pLast + v49), v6, size);
      v48 = (DBObj *)((char *)v48 + 1);
      v49 += 20;
    }
    while ( v48 < v3->m_pNext );
  }
  v50 = size;
  *(_DWORD *)*v6 = v3->m_pMaintainer;
  v51 = (int)((char *)*v6 + 4);
  *v6 = (void *)v51;
  v52 = 0;
  addrc = 0;
  if ( v3->m_pMaintainer )
  {
    do
    {
      v53 = v52 + v3->m_numLinks;
      if ( size >= 0x10 )
      {
        if ( size >= 0xC )
        {
          *(_DWORD *)v51 = *(_DWORD *)v53;
          v54 = (int)((char *)*v6 + 4);
          *v6 = (void *)v54;
          *(float *)v54 = *(float *)(v53 + 4);
          v55 = (int)((char *)*v6 + 4);
          *v6 = (void *)v55;
          *(float *)v55 = *(float *)(v53 + 8);
          v51 = (int)((char *)*v6 + 4);
          *v6 = (void *)v51;
        }
        *(float *)v51 = *(float *)(v53 + 12);
        v56 = (int)((char *)*v6 + 4);
        *v6 = (void *)v56;
        v51 = v56;
      }
      v52 += 16;
      addrc = (void **)((char *)addrc + 1);
    }
    while ( (DBOCache *)addrc < v3->m_pMaintainer );
  }
  *(float *)v51 = *(float *)&v3->vfptr;
  v57 = (int)((char *)*v6 + 4);
  *v6 = (void *)v57;
  *(float *)v57 = *((float *)&v3->48 + 1);
  v58 = (int)((char *)*v6 + 4);
  *v6 = (void *)v58;
  *(float *)v58 = *(float *)&v3->parts;
  v59 = (int)((char *)*v6 + 4);
  *v6 = (void *)v59;
  *(float *)v59 = *(float *)&v3->num_parts;
  v60 = (int)((char *)*v6 + 4);
  *v6 = (void *)v60;
  v61 = v60;
  if ( size >= 0x10 )
  {
    if ( size >= 0xC )
    {
      *(_DWORD *)v60 = v3->parent_index;
      v62 = (int)((char *)*v6 + 4);
      *v6 = (void *)v62;
      *(float *)v62 = *(float *)&v3->default_scale;
      v63 = (int)((char *)*v6 + 4);
      *v6 = (void *)v63;
      *(float *)v63 = *(float *)&v3->num_cylsphere;
      v61 = (int)((char *)*v6 + 4);
      *v6 = (void *)v61;
    }
    *(float *)v61 = *(float *)&v3->cylsphere;
    v61 = (int)((char *)*v6 + 4);
    *v6 = (void *)v61;
    if ( size >= 0x10 )
    {
      if ( size >= 0xC )
      {
        *(_DWORD *)v61 = v3->num_sphere;
        v64 = (int)((char *)*v6 + 4);
        *v6 = (void *)v64;
        *(float *)v64 = *(float *)&v3->sphere;
        v65 = (int)((char *)*v6 + 4);
        *v6 = (void *)v65;
        *(float *)v65 = *(float *)&v3->has_physics_bsp;
        v61 = (int)((char *)*v6 + 4);
        *v6 = (void *)v61;
      }
      *(float *)v61 = *(float *)&v3->allow_free_heading;
      v61 = (int)((char *)*v6 + 4);
      *v6 = (void *)v61;
    }
  }
  *(_DWORD *)v61 = LODWORD(v3->height);
  *v6 = (char *)*v6 + 4;
  addrd = 0;
  if ( LODWORD(v3->height) > 0 )
  {
    i = 0;
    do
    {
      v66 = i + LODWORD(v3->radius);
      if ( v50 >= EtherealHook::pack_size() + 44 )
      {
        *(_DWORD *)*v6 = *(_DWORD *)v66;
        *v6 = (char *)*v6 + 4;
        Frame::Pack((Frame *)(v66 + 4), v6, v50);
        RGBColor::Pack((RGBColor *)(v66 + 80), v6, v50);
        *(float *)*v6 = *(float *)(v66 + 92);
        v67 = (int)((char *)*v6 + 4);
        *v6 = (void *)v67;
        *(float *)v67 = *(float *)(v66 + 96);
        v68 = (int)((char *)*v6 + 4);
        *v6 = (void *)v68;
        *(float *)v68 = *(float *)(v66 + 100);
        *v6 = (char *)*v6 + 4;
      }
      v69 = (unsigned int)((char *)addrd + 1) < LODWORD(v3->height);
      addrd = (void **)((char *)addrd + 1);
      i += 104;
    }
    while ( v69 );
  }
  *(_DWORD *)*v6 = v3->lights;
  v70 = (int)((char *)*v6 + 4);
  *v6 = (void *)v70;
  *(_DWORD *)v70 = LODWORD(v3->anim_scale.x);
  v71 = (int)((char *)*v6 + 4);
  *v6 = (void *)v71;
  *(_DWORD *)v71 = LODWORD(v3->anim_scale.y);
  v72 = (int)((char *)*v6 + 4);
  *v6 = (void *)v72;
  *(_DWORD *)v72 = LODWORD(v3->anim_scale.z);
  v73 = (int)((char *)*v6 + 4);
  *v6 = (void *)v73;
  *(_DWORD *)v73 = v3->holding_locations;
  v74 = (signed int)((char *)*v6 + 4);
  *v6 = (void *)v74;
  v75 = v74 % 4;
  if ( v75 )
  {
    v76 = 4 - v75;
    if ( 4 != v75 )
    {
      do
      {
        *(_BYTE *)*v6 = 0;
        --v76;
        *v6 = (char *)*v6 + 1;
      }
      while ( v76 );
    }
  }
  return ret;
}

//----- (00520C50) --------------------------------------------------------  // acclient.c:335520
int __thiscall CSetup::UnPack(CSetup *this, void **addr, unsigned int size)
{
  CSetup *v3; // edi@1
  void **v4; // esi@1
  int v5; // ebx@1
  unsigned int v6; // edx@1
  int v7; // ebp@1
  void *v8; // eax@2
  void **v9; // eax@3
  int v10; // ecx@5
  unsigned int v11; // eax@5
  int v12; // edx@6
  int v13; // ebp@6
  void *v14; // eax@8
  int v15; // ecx@8
  unsigned int v16; // eax@8
  unsigned int v17; // ebx@11
  int v18; // edx@12
  int v19; // eax@13
  int v20; // ecx@14
  int v21; // ecx@14
  void **v22; // ebx@16
  void *v23; // eax@17
  float v24; // ebp@17
  signed int v25; // eax@18
  int v26; // ecx@19
  unsigned int v27; // eax@20
  void *v28; // ebp@26
  int v29; // ecx@27
  int v30; // ecx@29
  float v31; // edx@29
  int v32; // eax@29
  int v33; // ecx@30
  void *v34; // eax@31
  float v35; // ebp@31
  signed int v36; // eax@32
  int v37; // edx@33
  unsigned int v38; // eax@34
  void *v39; // ebp@39
  int v40; // ecx@40
  int v41; // ecx@42
  float v42; // edx@42
  int v43; // eax@42
  void **v44; // ecx@43
  void *v45; // eax@45
  void *v46; // ebp@46
  int v47; // eax@48
  DBObj *v48; // ebp@49
  void *v49; // eax@50
  int v50; // eax@51
  int v51; // ebp@51
  CCylSphere *v52; // ebx@51
  int v53; // ebp@52
  DBObj *v54; // ebp@56
  int v55; // ebx@57
  DBOCache *v56; // ebp@59
  void *v57; // eax@60
  int v58; // eax@61
  DBOCache *v59; // ecx@63
  unsigned int v60; // ebx@64
  int v61; // edx@64
  int v62; // eax@65
  int v63; // ebp@66
  int v64; // ebp@66
  int v65; // ecx@70
  int v66; // eax@70
  int v67; // ebp@70
  int v68; // edx@70
  int v69; // eax@70
  int v70; // edx@71
  int v71; // ecx@71
  int v72; // edx@72
  int v73; // eax@72
  int v74; // edx@73
  int v75; // ecx@73
  int v76; // edx@74
  float v77; // ebp@74
  void *v78; // eax@75
  int v79; // eax@76
  int v80; // ebp@77
  float v81; // eax@79
  int v82; // ebp@83
  int v83; // edx@84
  int v84; // ecx@84
  bool v85; // cf@85
  LIGHTINFO *v86; // ecx@86
  float v87; // ecx@86
  float v88; // ecx@86
  float v89; // ecx@86
  LongHash<LocationType> *v90; // ecx@86
  int v91; // eax@86
  int v92; // ecx@87
  void **addrg; // [sp+14h] [bp+4h]@3
  void **addra; // [sp+14h] [bp+4h]@25
  void **addrb; // [sp+14h] [bp+4h]@30
  void **addrc; // [sp+14h] [bp+4h]@44
  void **addrd; // [sp+14h] [bp+4h]@51
  void **addre; // [sp+14h] [bp+4h]@76
  void **addrf; // [sp+14h] [bp+4h]@81
  unsigned int n; // [sp+18h] [bp+8h]@77
  unsigned int na; // [sp+18h] [bp+8h]@82

  v3 = this;
  ((void (__thiscall *)(LongHash<LocationType> **))this[-1].connection_points[2].buckets)(&this[-1].connection_points);
  v4 = addr;
  v5 = *(_DWORD *)*addr;
  v6 = (unsigned __int8)*(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  *(_DWORD *)&v3->m_AllowedInFreeList = (v6 >> 2) & 1;
  v3->m_DID.id = (v6 >> 3) & 1;
  *(_DWORD *)&v3->m_bLoaded = *(_DWORD *)*addr;
  *v4 = (char *)*v4 + 4;
  v7 = *(_DWORD *)&v3->m_bLoaded;
  if ( v7 )
  {
    v8 = operator new[](4 * v7 + 4);
    if ( v8 )
    {
      *(_DWORD *)v8 = v7;
      addrg = (void **)((char *)v8 + 4);
      vector_constructor_iterator(
        (char *)v8 + 4,
        4u,
        v7,
        (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
      v9 = addrg;
    }
    else
    {
      v9 = 0;
    }
    v10 = *(_DWORD *)&v3->m_bLoaded;
    *((_DWORD *)&v3->m_bLoaded + 1) = v9;
    v11 = 0;
    if ( v10 )
    {
      do
      {
        v12 = *((_DWORD *)&v3->m_bLoaded + 1) + 4 * v11;
        v13 = *(_DWORD *)*v4;
        *v4 = (char *)*v4 + 4;
        *(_DWORD *)v12 = v13;
        ++v11;
      }
      while ( v11 < *(_DWORD *)&v3->m_bLoaded );
    }
    if ( v5 & 1 )
    {
      v14 = operator new[](4 * *(_DWORD *)&v3->m_bLoaded);
      v15 = *(_DWORD *)&v3->m_bLoaded;
      LODWORD(v3->m_timeStamp) = v14;
      v16 = 0;
      if ( v15 )
      {
        do
        {
          *(_DWORD *)(LODWORD(v3->m_timeStamp) + 4 * v16) = *(_DWORD *)*v4;
          *v4 = (char *)*v4 + 4;
          ++v16;
        }
        while ( v16 < *(_DWORD *)&v3->m_bLoaded );
      }
    }
    if ( v5 & 2 )
    {
      HIDWORD(v3->m_timeStamp) = operator new[](12 * *(_DWORD *)&v3->m_bLoaded);
      v17 = 0;
      if ( *(_DWORD *)&v3->m_bLoaded )
      {
        v18 = 0;
        do
        {
          v19 = v18 + HIDWORD(v3->m_timeStamp);
          if ( size >= 0xC )
          {
            *(_DWORD *)v19 = *(_DWORD *)*v4;
            v20 = (int)((char *)*v4 + 4);
            *v4 = (void *)v20;
            *(_DWORD *)(v19 + 4) = *(_DWORD *)v20;
            v21 = (int)((char *)*v4 + 4);
            *v4 = (void *)v21;
            *(_DWORD *)(v19 + 8) = *(_DWORD *)v21;
            *v4 = (char *)*v4 + 4;
          }
          ++v17;
          v18 += 12;
        }
        while ( v17 < *(_DWORD *)&v3->m_bLoaded );
      }
    }
  }
  v22 = *(void ***)*v4;
  *v4 = (char *)*v4 + 4;
  if ( v22 )
  {
    v23 = operator new(0x18u);
    v24 = *(float *)&v23;
    if ( v23 )
    {
      *(_DWORD *)v23 = LongHash<CWeenieObject>::vftable;
      *((_DWORD *)v23 + 5) = 0;
      *((_DWORD *)v23 + 3) = operator new[](0x10u);
      *(_DWORD *)(LODWORD(v24) + 16) = 4;
      *(_DWORD *)(LODWORD(v24) + 8) = 8;
      *(_DWORD *)(LODWORD(v24) + 4) = 0;
      v25 = 1;
      do
      {
        v26 = v25 | *(_DWORD *)(LODWORD(v24) + 4);
        v25 *= 2;
        *(_DWORD *)(LODWORD(v24) + 4) = v26;
      }
      while ( (v25 | (unsigned int)v26) < *(_DWORD *)(LODWORD(v24) + 16) );
      v27 = 0;
      do
        *(_DWORD *)(*(_DWORD *)(LODWORD(v24) + 12) + 4 * v27++) = 0;
      while ( v27 < *(_DWORD *)(LODWORD(v24) + 16) );
      *LODWORD(v24) = &LongHash<LocationType>::vftable;
    }
    else
    {
      v24 = 0.0;
    }
    v3->sorting_sphere.center.y = v24;
    if ( v22 )
    {
      addra = v22;
      do
      {
        v28 = operator new(0x50u);
        if ( v28 )
        {
          v29 = (int)((char *)v28 + 16);
          *((_DWORD *)v28 + 1) = 0;
          *((_DWORD *)v28 + 2) = 0;
          *(_DWORD *)v28 = LongHashData::vftable;
          *(_DWORD *)v29 = 1065353216;
          *(_DWORD *)(v29 + 4) = 0;
          *(_DWORD *)(v29 + 8) = 0;
          *(_DWORD *)(v29 + 12) = 0;
          *(_DWORD *)(v29 + 52) = 0;
          *(_DWORD *)(v29 + 56) = 0;
          *(_DWORD *)(v29 + 60) = 0;
          Frame::cache((Frame *)((char *)v28 + 16));
        }
        else
        {
          v28 = 0;
        }
        *((_DWORD *)v28 + 2) = *(_DWORD *)*v4;
        v30 = (int)((char *)*v4 + 4);
        *v4 = (void *)v30;
        *((_DWORD *)v28 + 3) = *(_DWORD *)v30;
        *v4 = (char *)*v4 + 4;
        Frame::UnPack((Frame *)((char *)v28 + 16), v4, size);
        v31 = v3->sorting_sphere.center.y;
        v32 = *(_DWORD *)(LODWORD(v31) + 4) & (*((_DWORD *)v28 + 2) ^ (*((_DWORD *)v28 + 2) >> *(_DWORD *)(LODWORD(v31) + 8)));
        *((_DWORD *)v28 + 1) = *(_DWORD *)(*(_DWORD *)(LODWORD(v31) + 12) + 4 * v32);
        *(_DWORD *)(*(_DWORD *)(LODWORD(v31) + 12) + 4 * v32) = v28;
        addra = (void **)((char *)addra - 1);
      }
      while ( addra );
    }
  }
  v33 = *(_DWORD *)*v4;
  addrb = *(void ***)*v4;
  *v4 = (char *)*v4 + 4;
  if ( v33 )
  {
    v34 = operator new(0x18u);
    v35 = *(float *)&v34;
    if ( v34 )
    {
      *(_DWORD *)v34 = LongHash<CWeenieObject>::vftable;
      *((_DWORD *)v34 + 5) = 0;
      *((_DWORD *)v34 + 3) = operator new[](0x10u);
      *(_DWORD *)(LODWORD(v35) + 16) = 4;
      *(_DWORD *)(LODWORD(v35) + 8) = 8;
      *(_DWORD *)(LODWORD(v35) + 4) = 0;
      v36 = 1;
      do
      {
        v37 = v36 | *(_DWORD *)(LODWORD(v35) + 4);
        v36 *= 2;
        *(_DWORD *)(LODWORD(v35) + 4) = v37;
      }
      while ( (v36 | (unsigned int)v37) < *(_DWORD *)(LODWORD(v35) + 16) );
      v38 = 0;
      do
        *(_DWORD *)(*(_DWORD *)(LODWORD(v35) + 12) + 4 * v38++) = 0;
      while ( v38 < *(_DWORD *)(LODWORD(v35) + 16) );
      *LODWORD(v35) = &LongHash<LocationType>::vftable;
    }
    else
    {
      v35 = 0.0;
    }
    for ( v3->sorting_sphere.center.z = v35; addrb; addrb = (void **)((char *)addrb - 1) )
    {
      v39 = operator new(0x50u);
      if ( v39 )
      {
        v40 = (int)((char *)v39 + 16);
        *((_DWORD *)v39 + 1) = 0;
        *((_DWORD *)v39 + 2) = 0;
        *(_DWORD *)v39 = LongHashData::vftable;
        *(_DWORD *)v40 = 1065353216;
        *(_DWORD *)(v40 + 4) = 0;
        *(_DWORD *)(v40 + 8) = 0;
        *(_DWORD *)(v40 + 12) = 0;
        *(_DWORD *)(v40 + 52) = 0;
        *(_DWORD *)(v40 + 56) = 0;
        *(_DWORD *)(v40 + 60) = 0;
        Frame::cache((Frame *)((char *)v39 + 16));
      }
      else
      {
        v39 = 0;
      }
      *((_DWORD *)v39 + 2) = *(_DWORD *)*v4;
      v41 = (int)((char *)*v4 + 4);
      *v4 = (void *)v41;
      *((_DWORD *)v39 + 3) = *(_DWORD *)v41;
      *v4 = (char *)*v4 + 4;
      Frame::UnPack((Frame *)((char *)v39 + 16), v4, size);
      v42 = v3->sorting_sphere.center.z;
      v43 = *(_DWORD *)(LODWORD(v42) + 4) & (*((_DWORD *)v39 + 2) ^ (*((_DWORD *)v39 + 2) >> *(_DWORD *)(LODWORD(v42) + 8)));
      *((_DWORD *)v39 + 1) = *(_DWORD *)(*(_DWORD *)(LODWORD(v42) + 12) + 4 * v43);
      *(_DWORD *)(*(_DWORD *)(LODWORD(v42) + 12) + 4 * v43) = v39;
    }
  }
  v44 = *(void ***)*v4;
  *v4 = (char *)*v4 + 4;
  if ( v44 )
  {
    addrc = v44;
    do
    {
      v45 = operator new(0x1Cu);
      if ( v45 )
      {
        *((_DWORD *)v45 + 1) = 0;
        *((_DWORD *)v45 + 2) = 0;
        *(_DWORD *)v45 = PlacementType::vftable;
        *((_DWORD *)v45 + 3) = 0;
        *((_DWORD *)v45 + 4) = 0;
        *((_DWORD *)v45 + 5) = 0;
        *((_DWORD *)v45 + 6) = 0;
        v46 = v45;
      }
      else
      {
        v46 = 0;
      }
      *((_DWORD *)v46 + 2) = *(_DWORD *)*v4;
      *v4 = (char *)*v4 + 4;
      AnimFrame::UnPack((AnimFrame *)((char *)v46 + 12), *(_DWORD *)&v3->m_bLoaded, v4, size);
      v47 = LODWORD(v3->selection_sphere.center.x) & (*((_DWORD *)v46 + 2) ^ (*((_DWORD *)v46 + 2) >> LODWORD(v3->selection_sphere.center.y)));
      *((_DWORD *)v46 + 1) = *(_DWORD *)(LODWORD(v3->selection_sphere.center.z) + 4 * v47);
      *(_DWORD *)(LODWORD(v3->selection_sphere.center.z) + 4 * v47) = v46;
      addrc = (void **)((char *)addrc - 1);
    }
    while ( addrc );
  }
  v3->m_pNext = *(DBObj **)*v4;
  *v4 = (char *)*v4 + 4;
  v48 = v3->m_pNext;
  if ( v48 )
  {
    v49 = operator new[](20 * (_DWORD)v48 + 4);
    if ( v49 )
    {
      v50 = (int)((char *)v49 + 4);
      *(_DWORD *)(v50 - 4) = v48;
      v51 = (int)(&v48[-1].m_AllowedInFreeList + 3);
      addrd = (void **)v50;
      v52 = (CCylSphere *)v50;
      if ( v51 >= 0 )
      {
        v53 = v51 + 1;
        do
        {
          CCylSphere::CCylSphere(v52);
          ++v52;
          --v53;
        }
        while ( v53 );
        v50 = (int)addrd;
      }
    }
    else
    {
      v50 = 0;
    }
    v3->m_pLast = (DBObj *)v50;
    v54 = 0;
    if ( v3->m_pNext )
    {
      v55 = 0;
      do
      {
        CCylSphere::UnPack((CCylSphere *)((char *)v3->m_pLast + v55), v4, size);
        v54 = (DBObj *)((char *)v54 + 1);
        v55 += 20;
      }
      while ( v54 < v3->m_pNext );
    }
  }
  v3->m_pMaintainer = *(DBOCache **)*v4;
  *v4 = (char *)*v4 + 4;
  v56 = v3->m_pMaintainer;
  if ( v56
    && ((v57 = operator new[](16 * (_DWORD)v56 + 4)) == 0 ? (v58 = 0) : (*(_DWORD *)v57 = v56,
                                                                         v58 = (int)((char *)v57 + 4)),
        v3->m_numLinks = v58,
        v59 = 0,
        v3->m_pMaintainer) )
  {
    v60 = size;
    v61 = 0;
    do
    {
      v62 = v61 + v3->m_numLinks;
      if ( size >= 0xC )
      {
        *(_DWORD *)v62 = *(_DWORD *)*v4;
        v63 = (int)((char *)*v4 + 4);
        *v4 = (void *)v63;
        *(_DWORD *)(v62 + 4) = *(_DWORD *)v63;
        v64 = (int)((char *)*v4 + 4);
        *v4 = (void *)v64;
        *(_DWORD *)(v62 + 8) = *(_DWORD *)v64;
        *v4 = (char *)*v4 + 4;
      }
      *(_DWORD *)(v62 + 12) = *(_DWORD *)*v4;
      *v4 = (char *)*v4 + 4;
      v59 = (DBOCache *)((char *)v59 + 1);
      v61 += 16;
    }
    while ( v59 < v3->m_pMaintainer );
  }
  else
  {
    v60 = size;
  }
  v3->vfptr = *(PackObjVtbl **)*v4;
  v65 = (int)((char *)*v4 + 4);
  *v4 = (void *)v65;
  *((_DWORD *)&v3->48 + 1) = *(_DWORD *)v65;
  v66 = (int)((char *)*v4 + 4);
  *v4 = (void *)v66;
  v3->parts = *(IDClass<_tagDataID,32,0> **)v66;
  v67 = (int)((char *)*v4 + 4);
  *v4 = (void *)v67;
  v3->num_parts = *(_DWORD *)v67;
  v68 = (int)((char *)*v4 + 4);
  *v4 = (void *)v68;
  v69 = v68;
  if ( v60 >= 0xC )
  {
    v3->parent_index = *(unsigned int **)v68;
    v70 = (int)((char *)*v4 + 4);
    *v4 = (void *)v70;
    v3->default_scale = *(AC1Legacy::Vector3 **)v70;
    v71 = (int)((char *)*v4 + 4);
    *v4 = (void *)v71;
    v3->num_cylsphere = *(_DWORD *)v71;
    v69 = (int)((char *)*v4 + 4);
    *v4 = (void *)v69;
  }
  v3->cylsphere = *(CCylSphere **)v69;
  v72 = (int)((char *)*v4 + 4);
  *v4 = (void *)v72;
  v73 = v72;
  if ( v60 >= 0xC )
  {
    v3->num_sphere = *(_DWORD *)v72;
    v74 = (int)((char *)*v4 + 4);
    *v4 = (void *)v74;
    v3->sphere = *(CSphere **)v74;
    v75 = (int)((char *)*v4 + 4);
    *v4 = (void *)v75;
    v3->has_physics_bsp = *(_DWORD *)v75;
    v73 = (int)((char *)*v4 + 4);
    *v4 = (void *)v73;
  }
  v3->allow_free_heading = *(_DWORD *)v73;
  v76 = (int)((char *)*v4 + 4);
  *v4 = (void *)v76;
  LODWORD(v3->height) = *(_DWORD *)v76;
  *v4 = (char *)*v4 + 4;
  v77 = v3->height;
  if ( v77 != 0.0 )
  {
    v78 = operator new[](104 * LODWORD(v77) + 4);
    if ( v78 )
    {
      *(float *)v78 = v77;
      addre = (void **)((char *)v78 + 4);
      v79 = LODWORD(v77) - 1;
      if ( LODWORD(v77) - 1 >= 0 )
      {
        v80 = (int)(addre + 16);
        n = v79 + 1;
        do
        {
          *(_DWORD *)(v80 - 60) = 1065353216;
          *(_DWORD *)(v80 - 56) = 0;
          *(_DWORD *)(v80 - 52) = 0;
          *(_DWORD *)(v80 - 48) = 0;
          *(_DWORD *)(v80 - 8) = 0;
          *(_DWORD *)(v80 - 4) = 0;
          *(_DWORD *)v80 = 0;
          Frame::cache((Frame *)(v80 - 60));
          v80 += 104;
          --n;
        }
        while ( n );
      }
      v81 = *(float *)&addre;
    }
    else
    {
      v81 = 0.0;
    }
    v3->radius = v81;
    addrf = 0;
    if ( LODWORD(v3->height) )
    {
      na = 0;
      do
      {
        v82 = na + LODWORD(v3->radius);
        if ( v60 >= EtherealHook::pack_size() + 44 )
        {
          *(_DWORD *)v82 = *(_DWORD *)*v4;
          *v4 = (char *)*v4 + 4;
          Frame::UnPack((Frame *)(v82 + 4), v4, v60);
          RGBColor::UnPack((RGBColor *)(v82 + 80), v4, v60);
          *(_DWORD *)(v82 + 92) = *(_DWORD *)*v4;
          v83 = (int)((char *)*v4 + 4);
          *v4 = (void *)v83;
          *(_DWORD *)(v82 + 96) = *(_DWORD *)v83;
          v84 = (int)((char *)*v4 + 4);
          *v4 = (void *)v84;
          *(_DWORD *)(v82 + 100) = *(_DWORD *)v84;
          *v4 = (char *)*v4 + 4;
        }
        v85 = (unsigned int)((char *)addrf + 1) < LODWORD(v3->height);
        addrf = (void **)((char *)addrf + 1);
        na += 104;
      }
      while ( v85 );
    }
  }
  v86 = *(LIGHTINFO **)*v4;
  *v4 = (char *)*v4 + 4;
  v3->lights = v86;
  v87 = *(float *)*v4;
  *v4 = (char *)*v4 + 4;
  v3->anim_scale.x = v87;
  v88 = *(float *)*v4;
  *v4 = (char *)*v4 + 4;
  v3->anim_scale.y = v88;
  v89 = *(float *)*v4;
  *v4 = (char *)*v4 + 4;
  v3->anim_scale.z = v89;
  v90 = *(LongHash<LocationType> **)*v4;
  *v4 = (char *)*v4 + 4;
  v3->holding_locations = v90;
  v91 = (signed int)*v4 % 4;
  if ( v91 )
  {
    v92 = 4 - v91;
    if ( 4 != v91 )
    {
      do
      {
        *(_BYTE *)*v4 = 0;
        --v92;
        *v4 = (char *)*v4 + 1;
      }
      while ( v92 );
    }
  }
  return 1;
}
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);
// 7C7B74: using guessed type int (__thiscall *PlacementType::vftable[2])(void *, char);
// 7C7B78: using guessed type int (__thiscall *LongHash<LocationType>::vftable)(void *, char);

//----- (005213F0) --------------------------------------------------------  // acclient.c:336113
HashBaseData<unsigned long> *__thiscall CSetup::GetHoldingLocation(CSetup *this, unsigned int location_id)
{
  LongHash<LocationType> *v2; // eax@1
  HashBaseData<unsigned long> *result; // eax@2

  v2 = this->holding_locations;
  if ( v2 && (result = v2->buckets[v2->table_mask & (location_id ^ (location_id >> v2->key_shift))]) != 0 )
  {
    while ( location_id != result->id )
    {
      result = result->hash_next;
      if ( !result )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    result = 0;
  }
  return result;
}

//----- (00521440) --------------------------------------------------------  // acclient.c:336137
void __thiscall CSetup::Destroy(CSetup *this)
{
  CSetup *v1; // esi@1
  IDClass<_tagDataID,32,0> *v2; // eax@5
  CCylSphere *v3; // ecx@7
  float v4; // eax@8
  void *v5; // edx@8
  int v6; // edi@8
  int v7; // eax@8
  DiskSpace *v8; // edi@8
  int v9; // ebp@9
  CSphere *v10; // eax@13
  LIGHTINFO *v11; // eax@15
  LongHash<MotionData> *v12; // ecx@17
  LongHash<LocationType> *v13; // ecx@18
  LongHash<MotionData> *v14; // ecx@21
  LongHash<LocationType> *v15; // ecx@22
  int v16; // [sp+0h] [bp-4h]@8

  v1 = this;
  if ( this->default_scale )
  {
    operator delete[](this->default_scale);
    v1->default_scale = 0;
  }
  if ( v1->parent_index )
  {
    operator delete[](v1->parent_index);
    v1->parent_index = 0;
  }
  v2 = v1->parts;
  if ( v2 )
  {
    operator delete[](&v2[-1]);
    v1->parts = 0;
  }
  v3 = v1->cylsphere;
  v1->num_parts = 0;
  if ( v3 )
  {
    v4 = v3[-1].radius;
    v5 = &v3[-1].radius;
    v6 = 5 * LODWORD(v4);
    v7 = LODWORD(v4) - 1;
    v16 = (int)&v3[-1].radius;
    v8 = (DiskSpace *)&v3[4 * v6 / 0x14u];
    if ( v7 >= 0 )
    {
      v9 = v7 + 1;
      do
      {
        v8 -= 20;
        gmNoticeHandler::RecvNotice_PrevSpellSelection(v8);
        --v9;
      }
      while ( v9 );
      v5 = (void *)v16;
    }
    operator delete[](v5);
    v1->cylsphere = 0;
  }
  v10 = v1->sphere;
  v1->num_cylsphere = 0;
  if ( v10 )
  {
    operator delete[](&v10[-1].radius);
    v1->sphere = 0;
  }
  v11 = v1->lights;
  v1->num_sphere = 0;
  if ( v11 )
  {
    operator delete[](&v11[-1].cone_angle);
    v1->lights = 0;
  }
  v12 = (LongHash<MotionData> *)v1->holding_locations;
  v1->num_lights = 0;
  if ( v12 )
  {
    LongNIValHash<unsigned long>::destroy_contents(v12);
    v13 = v1->holding_locations;
    if ( v13 )
      ((void (__stdcall *)(_DWORD))v13->vfptr->__vecDelDtor)(1);
    v1->holding_locations = 0;
  }
  v14 = (LongHash<MotionData> *)v1->connection_points;
  if ( v14 )
  {
    LongNIValHash<unsigned long>::destroy_contents(v14);
    v15 = v1->connection_points;
    if ( v15 )
      ((void (__stdcall *)(_DWORD))v15->vfptr->__vecDelDtor)(1);
    v1->connection_points = 0;
  }
  LongNIValHash<unsigned long>::destroy_contents((LongHash<MotionData> *)&v1->placement_frames);
  v1->default_anim_id.id = stru_8444A0.id;
  v1->default_script_id.id = stru_8444A0.id;
  v1->default_mtable_id.id = stru_8444A0.id;
  v1->default_stable_id.id = stru_8444A0.id;
  v1->default_phstable_id.id = stru_8444A0.id;
}

//----- (005215A0) --------------------------------------------------------  // acclient.c:336240
CSetup *__thiscall CSetup::vector_deleting_destructor(CSetup *this, unsigned int a2)
{
  CSetup *v2; // esi@1
  int v3; // eax@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&CSetup::vftable;
  this->vfptr = (PackObjVtbl *)&CSetup::vftable;
  CSetup::Destroy(this);
  v3 = v2->placement_frames.fPlacementNew_;
  v2->placement_frames.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( !v3 )
    operator delete[](v2->placement_frames.buckets);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);
// 7C7B7C: using guessed type void *CSetup::vftable;
// 7C7B90: using guessed type __int32 (__stdcall *CSetup::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006B2040) --------------------------------------------------------  // acclient.c:715414
signed int __cdecl TChessPiece<CBasePiece>::GetPackSize()
{
  return 28;
}

//----- (006FD530) --------------------------------------------------------  // acclient.c:785590
void sub_6FD530()
{
  flt_844494 = 1000.0 + 1.0;
}

//----- (006FD550) --------------------------------------------------------  // acclient.c:785596
void sub_6FD550()
{
  flt_844498 = 24.0 * 8.0;
}

//----- (006FD570) --------------------------------------------------------  // acclient.c:785602
void sub_6FD570()
{
  flt_84449C = 24.0 * 0.5;
}

//----- (006FD590) --------------------------------------------------------  // acclient.c:785608
void sub_6FD590()
{
  flt_8444A4 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FD5B0) --------------------------------------------------------  // acclient.c:785614
void _E99_22()
{
  dbl_8444A8 = 1.0 / 30.0;
}

//----- (006FD5D0) --------------------------------------------------------  // acclient.c:785620
void _E101_19()
{
  dbl_8444B0 = 1.0 / 5.0;
}

//----- (006FD5F0) --------------------------------------------------------  // acclient.c:785626
int sub_6FD5F0()
{
  return atexit(nullsub_1120);
}

//----- (006FD600) --------------------------------------------------------  // acclient.c:785632
int _E106_94()
{
  return atexit(_E107_87);
}

//----- (006FD610) --------------------------------------------------------  // acclient.c:785638
int _E109_62()
{
  return atexit(nullsub_1122);
}

//----- (006FD620) --------------------------------------------------------  // acclient.c:785644
int sub_6FD620()
{
  return atexit(nullsub_1119);
}

