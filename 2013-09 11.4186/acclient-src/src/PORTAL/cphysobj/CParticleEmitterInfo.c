/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CParticleEmitterInfo
   Object     : PORTAL\cphysobj\CParticleEmitterInfo.obj
   Functions  : 24
   Addresses  : 005170D0 - 006FC500 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005170D0) --------------------------------------------------------  // acclient.c:324323
double __thiscall ParticleEmitterInfo::GetRandomStartScale(ParticleEmitterInfo *this)
{
  double result; // st7@1

  result = Random::RollDice(-1.0, 1.0) * this->scale_rand + this->start_scale;
  if ( result >= 0.1 )
  {
    if ( result > 10.0 )
      result = 10.0;
  }
  else
  {
    result = 0.1;
  }
  return result;
}

//----- (00517120) --------------------------------------------------------  // acclient.c:324341
double __thiscall ParticleEmitterInfo::GetRandomFinalScale(ParticleEmitterInfo *this)
{
  double result; // st7@1

  result = Random::RollDice(-1.0, 1.0) * this->scale_rand + this->final_scale;
  if ( result >= 0.1 )
  {
    if ( result > 10.0 )
      result = 10.0;
  }
  else
  {
    result = 0.1;
  }
  return result;
}

//----- (00517170) --------------------------------------------------------  // acclient.c:324359
double __thiscall ParticleEmitterInfo::GetRandomStartTrans(ParticleEmitterInfo *this)
{
  double result; // st7@1

  result = Random::RollDice(-1.0, 1.0) * this->trans_rand + this->start_trans;
  if ( result >= 0.0 )
  {
    if ( result > 1.0 )
      result = 1.0;
  }
  else
  {
    result = 0.0;
  }
  return result;
}

//----- (005171C0) --------------------------------------------------------  // acclient.c:324377
double __thiscall ParticleEmitterInfo::GetRandomFinalTrans(ParticleEmitterInfo *this)
{
  double result; // st7@1

  result = Random::RollDice(-1.0, 1.0) * this->trans_rand + this->final_trans;
  if ( result >= 0.0 )
  {
    if ( result > 1.0 )
      result = 1.0;
  }
  else
  {
    result = 0.0;
  }
  return result;
}

//----- (00517210) --------------------------------------------------------  // acclient.c:324395
double __thiscall ParticleEmitterInfo::GetRandomLifespan(ParticleEmitterInfo *this)
{
  double result; // st7@1

  result = Random::RollDice(-1.0, 1.0) * this->lifespan_rand + this->lifespan;
  if ( result < 0.0 )
    result = 0.0;
  return result;
}

//----- (00517250) --------------------------------------------------------  // acclient.c:324406
void __thiscall ParticleEmitterInfo::ParticleEmitterInfo(ParticleEmitterInfo *this)
{
  ParticleEmitterInfo *v1; // esi@1
  int v2; // edx@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_843F78);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->emitter_type = 0;
  v1->particle_type = 0;
  v1->is_parent_local = 0;
  v1->vfptr = (InterfaceVtbl *)&ParticleEmitterInfo::vftable;
  v1->vfptr = (PackObjVtbl *)&ParticleEmitterInfo::vftable;
  v1->gfxobj_id.id = stru_843F78.id;
  v1->hw_gfxobj_id.id = stru_843F78.id;
  LODWORD(v1->birthrate) = 0;
  HIDWORD(v1->birthrate) = 0;
  v1->max_particles = 0;
  v1->initial_particles = 0;
  v1->total_particles = 0;
  LODWORD(v1->total_seconds) = 0;
  HIDWORD(v1->total_seconds) = 0;
  LODWORD(v1->lifespan_rand) = 0;
  HIDWORD(v1->lifespan_rand) = 0;
  LODWORD(v1->lifespan) = 0;
  HIDWORD(v1->lifespan) = 0;
  LODWORD(v1->sorting_sphere.radius) = 0;
  v2 = (int)&v1->sorting_sphere;
  *(_DWORD *)v2 = 0;
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  LODWORD(v1->offset_dir.x) = 0;
  LODWORD(v1->offset_dir.y) = 0;
  LODWORD(v1->offset_dir.z) = 0;
  LODWORD(v1->min_offset) = 0;
  LODWORD(v1->max_offset) = 0;
  LODWORD(v1->a.x) = 0;
  LODWORD(v1->a.y) = 0;
  LODWORD(v1->a.z) = 0;
  LODWORD(v1->b.x) = 0;
  LODWORD(v1->b.y) = 0;
  LODWORD(v1->b.z) = 0;
  LODWORD(v1->c.x) = 0;
  LODWORD(v1->c.y) = 0;
  LODWORD(v1->c.z) = 0;
  LODWORD(v1->scale_rand) = 0;
  LODWORD(v1->trans_rand) = 0;
  LODWORD(v1->start_trans) = 0;
  LODWORD(v1->final_trans) = 0;
  LODWORD(v1->min_a) = 1065353216;
  LODWORD(v1->max_a) = 1065353216;
  LODWORD(v1->min_b) = 1065353216;
  LODWORD(v1->max_b) = 1065353216;
  LODWORD(v1->min_c) = 1065353216;
  LODWORD(v1->max_c) = 1065353216;
  LODWORD(v1->start_scale) = 1065353216;
  LODWORD(v1->final_scale) = 1065353216;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C6C78: using guessed type void *ParticleEmitterInfo::vftable;
// 7C6C90: using guessed type __int32 (__stdcall *ParticleEmitterInfo::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00517390) --------------------------------------------------------  // acclient.c:324469
signed int ParticleEmitterInfo::GetDBOType()
{
  return 42;
}

//----- (005173A0) --------------------------------------------------------  // acclient.c:324475
ParticleEmitterInfo *__thiscall ParticleEmitterInfo::vector_deleting_destructor(ParticleEmitterInfo *this, unsigned int a2)
{
  return ParticleEmitterInfo::scalar_deleting_destructor((ParticleEmitterInfo *)((char *)this - 48), a2);
}

//----- (005173B0) --------------------------------------------------------  // acclient.c:324481
void __thiscall ParticleEmitterInfo::InitEnd(ParticleEmitterInfo *this)
{
  double v1; // st7@1
  char *v2; // eax@3
  float velocity_radius; // [sp+0h] [bp-10h]@1

  v1 = this->max_offset;
  velocity_radius = this->max_a * this->lifespan;
  if ( v1 <= velocity_radius )
    v1 = velocity_radius;
  this->sorting_sphere.radius = v1;
  v2 = (char *)&this->sorting_sphere;
  *(_DWORD *)v2 = 0;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
}

//----- (00517420) --------------------------------------------------------  // acclient.c:324499
int __thiscall ParticleEmitterInfo::ShouldEmitParticle(ParticleEmitterInfo *this, int num_particles, int total_emitted, AC1Legacy::Vector3 *emitter_offset, long double last_emit_time)
{
  int v5; // eax@1
  int v6; // eax@4
  double v8; // st7@8
  unsigned __int8 v10; // c0@8
  unsigned __int8 v11; // c2@8

  v5 = this->total_particles;
  if ( (v5 <= 0 || total_emitted < v5) && num_particles < this->max_particles )
  {
    v6 = this->emitter_type;
    if ( v6 & 1 )
    {
      if ( COERCE_DOUBLE(Timer::cur_time.Cmd) - last_emit_time > this->birthrate )
        return 1;
    }
    else if ( v6 & 2 )
    {
      v8 = emitter_offset->z;
      if ( v10 | v11 )
        return 1;
    }
  }
  return 0;
}

//----- (005174A0) --------------------------------------------------------  // acclient.c:324527
AC1Legacy::Vector3 *__thiscall ParticleEmitterInfo::GetRandomOffset(ParticleEmitterInfo *this, AC1Legacy::Vector3 *result)
{
  ParticleEmitterInfo *v2; // esi@1
  float v3; // ST20_4@1
  float v4; // ST1C_4@1
  double v5; // st7@1
  double v6; // st6@1
  double v7; // st7@1
  double v8; // st6@1
  double v9; // st7@1
  double v10; // st6@1
  double v11; // st7@2
  double v12; // st7@3
  AC1Legacy::Vector3 *v13; // eax@4
  float v14; // edx@4
  AC1Legacy::Vector3 offset; // [sp+Ch] [bp-24h]@1
  float v16; // [sp+18h] [bp-18h]@1
  float v17; // [sp+1Ch] [bp-14h]@1
  float v18; // [sp+20h] [bp-10h]@1
  float v19; // [sp+28h] [bp-8h]@1
  float v20; // [sp+2Ch] [bp-4h]@1

  v2 = this;
  v3 = Random::RollDice(-1.0, 1.0);
  v4 = Random::RollDice(-1.0, 1.0);
  v16 = Random::RollDice(-1.0, 1.0);
  v5 = v4 * v2->offset_dir.y;
  v6 = v3 * v2->offset_dir.z;
  offset.x = v16;
  offset.y = v4;
  offset.z = v3;
  v7 = v5 + v6;
  v18 = v3;
  v8 = v16 * v2->offset_dir.x;
  v17 = v4;
  v9 = v7 + v8;
  v10 = v9 * v2->offset_dir.x;
  v19 = v9 * v2->offset_dir.y;
  v20 = v9 * v2->offset_dir.z;
  offset.x = v16 - v10;
  offset.y = v4 - v19;
  offset.z = v3 - v20;
  if ( AC1Legacy::Vector3::normalize_check_small(&offset) )
  {
    v18 = 0.0;
    v16 = 0.0;
    v17 = 0.0;
    LODWORD(offset.z) = 0;
    v11 = 0.0;
    LODWORD(offset.x) = 0;
    LODWORD(offset.y) = 0;
  }
  else
  {
    v12 = Random::RollDice(0.0, 1.0) * (v2->max_offset - v2->min_offset) + v2->min_offset;
    offset.x = offset.x * v12;
    offset.y = offset.y * v12;
    v11 = v12 * offset.z;
  }
  v13 = result;
  v14 = offset.y;
  result->x = offset.x;
  result->y = v14;
  result->z = v11;
  return v13;
}

//----- (00517610) --------------------------------------------------------  // acclient.c:324595
AC1Legacy::Vector3 *__thiscall ParticleEmitterInfo::GetRandomA(ParticleEmitterInfo *this, AC1Legacy::Vector3 *result)
{
  ParticleEmitterInfo *v2; // esi@1
  double v3; // st7@1
  AC1Legacy::Vector3 *v4; // eax@1
  float a_mag; // ST0C_4@1
  double v6; // st6@1
  double v7; // st7@1

  v2 = this;
  v3 = Random::RollDice(0.0, 1.0);
  v4 = result;
  a_mag = (v2->max_a - v2->min_a) * v3 + v2->min_a;
  v6 = a_mag * v2->a.y;
  v7 = a_mag * v2->a.z;
  result->x = a_mag * v2->a.x;
  result->y = v6;
  result->z = v7;
  return v4;
}

//----- (00517670) --------------------------------------------------------  // acclient.c:324617
AC1Legacy::Vector3 *__thiscall ParticleEmitterInfo::GetRandomB(ParticleEmitterInfo *this, AC1Legacy::Vector3 *result)
{
  ParticleEmitterInfo *v2; // esi@1
  double v3; // st7@1
  AC1Legacy::Vector3 *v4; // eax@1
  float b_mag; // ST0C_4@1
  double v6; // st6@1
  double v7; // st7@1

  v2 = this;
  v3 = Random::RollDice(0.0, 1.0);
  v4 = result;
  b_mag = (v2->max_b - v2->min_b) * v3 + v2->min_b;
  v6 = b_mag * v2->b.y;
  v7 = b_mag * v2->b.z;
  result->x = b_mag * v2->b.x;
  result->y = v6;
  result->z = v7;
  return v4;
}

//----- (005176D0) --------------------------------------------------------  // acclient.c:324639
AC1Legacy::Vector3 *__thiscall ParticleEmitterInfo::GetRandomC(ParticleEmitterInfo *this, AC1Legacy::Vector3 *result)
{
  ParticleEmitterInfo *v2; // esi@1
  double v3; // st7@1
  AC1Legacy::Vector3 *v4; // eax@1
  float c_mag; // ST0C_4@1
  double v6; // st6@1
  double v7; // st7@1

  v2 = this;
  v3 = Random::RollDice(0.0, 1.0);
  v4 = result;
  c_mag = (v2->max_c - v2->min_c) * v3 + v2->min_c;
  v6 = c_mag * v2->c.y;
  v7 = c_mag * v2->c.z;
  result->x = c_mag * v2->c.x;
  result->y = v6;
  result->z = v7;
  return v4;
}

//----- (00517740) --------------------------------------------------------  // acclient.c:324661
ParticleEmitterInfo *__thiscall ParticleEmitterInfo::scalar_deleting_destructor(ParticleEmitterInfo *this, unsigned int a2)
{
  ParticleEmitterInfo *v2; // esi@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&ParticleEmitterInfo::vftable;
  this->vfptr = (PackObjVtbl *)&ParticleEmitterInfo::vftable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C6C78: using guessed type void *ParticleEmitterInfo::vftable;
// 7C6C90: using guessed type __int32 (__stdcall *ParticleEmitterInfo::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00517780) --------------------------------------------------------  // acclient.c:324679
signed int __thiscall ParticleEmitterInfo::Pack(ParticleEmitterInfo *this, void **addr, unsigned int size)
{
  char *v3; // edi@2
  char *v4; // edx@2
  char *v5; // edi@2
  char *v6; // edx@2
  char *v7; // edi@2
  char *v8; // edx@2
  char *v9; // edi@2
  char *v10; // edx@2
  char *v11; // edi@2
  char *v12; // edx@2
  char *v13; // edi@2
  char *v14; // edx@2
  char *v15; // edx@3
  char *v16; // edi@3
  char *v17; // edi@4
  char *v18; // edx@4
  char *v19; // edx@5
  char *v20; // edi@5
  char *v21; // edi@6
  char *v22; // edx@6
  char *v23; // edx@7
  char *v24; // edi@7
  char *v25; // edi@8
  char *v26; // edx@8
  char *v27; // edi@9
  char *v28; // esi@9
  char *v29; // esi@10
  char *v30; // edx@10
  char *v31; // edi@10
  char *v32; // esi@10
  char *v33; // edx@10
  char *v34; // edi@10
  char *v35; // esi@10
  char *v36; // edx@10

  if ( size >= 0xAC )
  {
    *(_DWORD *)*addr = 0;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = *(_DWORD *)&this->m_bLoaded;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_DWORD *)v4 = *((_DWORD *)&this->m_bLoaded + 1);
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = HIDWORD(this->m_timeStamp);
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = this->m_pNext;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(double *)v7 = *(double *)&this->m_pMaintainer;
    v8 = (char *)*addr + 8;
    *addr = v8;
    *(_DWORD *)v8 = this->m_DID.id;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = *(_DWORD *)&this->m_AllowedInFreeList;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(_DWORD *)v10 = this->vfptr;
    v11 = (char *)*addr + 4;
    *addr = v11;
    *(double *)v11 = *(double *)&this->emitter_type;
    v12 = (char *)*addr + 8;
    *addr = v12;
    *(double *)v12 = *(double *)&this->hw_gfxobj_id.id;
    v13 = (char *)*addr + 8;
    *addr = v13;
    *(double *)v13 = *(double *)&this->is_parent_local;
    v14 = (char *)*addr + 8;
    *addr = v14;
    if ( size >= 0xC )
    {
      *(_DWORD *)v14 = this->total_particles;
      v15 = (char *)*addr + 4;
      *addr = v15;
      *(float *)v15 = *((float *)&this->total_particles + 1);
      v16 = (char *)*addr + 4;
      *addr = v16;
      *(float *)v16 = *(float *)&this->total_seconds;
      *addr = (char *)*addr + 4;
    }
    *(float *)*addr = *((float *)&this->total_seconds + 1);
    v17 = (char *)*addr + 4;
    *addr = v17;
    *(float *)v17 = *(float *)&this->lifespan_rand;
    v18 = (char *)*addr + 4;
    *addr = v18;
    if ( size >= 0xC )
    {
      *(_DWORD *)v18 = HIDWORD(this->lifespan_rand);
      v19 = (char *)*addr + 4;
      *addr = v19;
      *(float *)v19 = *(float *)&this->lifespan;
      v20 = (char *)*addr + 4;
      *addr = v20;
      *(float *)v20 = *((float *)&this->lifespan + 1);
      v18 = (char *)*addr + 4;
      *addr = v18;
    }
    *(float *)v18 = this->offset_dir.z;
    v21 = (char *)*addr + 4;
    *addr = v21;
    *(float *)v21 = this->min_offset;
    v22 = (char *)*addr + 4;
    *addr = v22;
    if ( size >= 0xC )
    {
      *(_DWORD *)v22 = LODWORD(this->sorting_sphere.center.x);
      v23 = (char *)*addr + 4;
      *addr = v23;
      *(float *)v23 = this->sorting_sphere.center.y;
      v24 = (char *)*addr + 4;
      *addr = v24;
      *(float *)v24 = this->sorting_sphere.center.z;
      v22 = (char *)*addr + 4;
      *addr = v22;
    }
    *(float *)v22 = this->max_offset;
    v25 = (char *)*addr + 4;
    *addr = v25;
    *(float *)v25 = this->a.x;
    v26 = (char *)*addr + 4;
    *addr = v26;
    if ( size >= 0xC )
    {
      *(_DWORD *)v26 = LODWORD(this->sorting_sphere.radius);
      v27 = (char *)*addr + 4;
      *addr = v27;
      *(float *)v27 = this->offset_dir.x;
      v28 = (char *)*addr + 4;
      *addr = v28;
      *(float *)v28 = this->offset_dir.y;
      v26 = (char *)*addr + 4;
      *addr = v26;
    }
    *(float *)v26 = this->a.y;
    v29 = (char *)*addr + 4;
    *addr = v29;
    *(float *)v29 = this->a.z;
    v30 = (char *)*addr + 4;
    *addr = v30;
    *(float *)v30 = this->b.y;
    v31 = (char *)*addr + 4;
    *addr = v31;
    *(float *)v31 = this->b.z;
    v32 = (char *)*addr + 4;
    *addr = v32;
    *(float *)v32 = this->b.x;
    v33 = (char *)*addr + 4;
    *addr = v33;
    *(float *)v33 = this->c.y;
    v34 = (char *)*addr + 4;
    *addr = v34;
    *(float *)v34 = this->c.z;
    v35 = (char *)*addr + 4;
    *addr = v35;
    *(float *)v35 = this->c.x;
    v36 = (char *)*addr + 4;
    *addr = v36;
    *(_DWORD *)v36 = LODWORD(this->m_timeStamp);
    *addr = (char *)*addr + 4;
  }
  return 172;
}

//----- (005179F0) --------------------------------------------------------  // acclient.c:324850
int __thiscall ParticleEmitterInfo::UnPack(ParticleEmitterInfo *this, void **addr, unsigned int size)
{
  char *v3; // esi@1
  char *v4; // edx@1
  char *v5; // esi@1
  char *v6; // edx@1
  int v7; // esi@1
  DBObj *v8; // esi@1
  void *v9; // edx@1
  char *v10; // edx@1
  char *v11; // esi@1
  char *v12; // edx@1
  char *v13; // esi@1
  char *v14; // edx@1
  char *v15; // esi@1
  char *v16; // edx@1
  char *v17; // esi@2
  char *v18; // esi@2
  char *v19; // esi@3
  char *v20; // esi@3
  char *v21; // esi@4
  char *v22; // esi@4
  char *v23; // esi@5
  char *v24; // esi@5
  char *v25; // esi@6
  char *v26; // esi@6
  char *v27; // esi@7
  char *v28; // esi@7
  char *v29; // edx@8
  char *v30; // esi@8
  char *v31; // edx@8
  char *v32; // edx@9
  char *v33; // esi@9
  char *v34; // edx@9
  char *v35; // esi@9
  char *v36; // edx@9
  char *v37; // esi@9
  char *v38; // edx@9
  char *v39; // esi@9

  v3 = (char *)*addr + 4;
  *addr = v3;
  *(_DWORD *)&this->m_bLoaded = *(_DWORD *)v3;
  v4 = (char *)*addr + 4;
  *addr = v4;
  *((_DWORD *)&this->m_bLoaded + 1) = *(_DWORD *)v4;
  v5 = (char *)*addr + 4;
  *addr = v5;
  v6 = v5;
  v7 = *(_DWORD *)v5;
  *addr = v6 + 4;
  HIDWORD(this->m_timeStamp) = v7;
  v8 = *(DBObj **)*addr;
  *addr = (char *)*addr + 4;
  this->m_pNext = v8;
  v9 = *addr;
  this->m_pMaintainer = *(DBOCache **)*addr;
  this->m_numLinks = *((_DWORD *)v9 + 1);
  v10 = (char *)*addr + 8;
  *addr = v10;
  this->m_DID.id = *(_DWORD *)v10;
  v11 = (char *)*addr + 4;
  *addr = v11;
  *(_DWORD *)&this->m_AllowedInFreeList = *(_DWORD *)v11;
  v12 = (char *)*addr + 4;
  *addr = v12;
  this->vfptr = *(PackObjVtbl **)v12;
  v13 = (char *)*addr + 4;
  *addr = v13;
  this->emitter_type = *(_DWORD *)v13;
  this->particle_type = *((_DWORD *)v13 + 1);
  v14 = (char *)*addr + 8;
  *addr = v14;
  this->hw_gfxobj_id.id = *(_DWORD *)v14;
  *((_DWORD *)&this->hw_gfxobj_id + 1) = *((_DWORD *)v14 + 1);
  v15 = (char *)*addr + 8;
  *addr = v15;
  this->is_parent_local = *(_DWORD *)v15;
  this->gfxobj_id.id = *((_DWORD *)v15 + 1);
  v16 = (char *)*addr + 8;
  *addr = v16;
  if ( size >= 0xC )
  {
    this->total_particles = *(_DWORD *)v16;
    v17 = (char *)*addr + 4;
    *addr = v17;
    *(&this->total_particles + 1) = *(_DWORD *)v17;
    v18 = (char *)*addr + 4;
    *addr = v18;
    LODWORD(this->total_seconds) = *(_DWORD *)v18;
    *addr = (char *)*addr + 4;
  }
  HIDWORD(this->total_seconds) = *(_DWORD *)*addr;
  v19 = (char *)*addr + 4;
  *addr = v19;
  LODWORD(this->lifespan_rand) = *(_DWORD *)v19;
  v20 = (char *)*addr + 4;
  *addr = v20;
  if ( size >= 0xC )
  {
    HIDWORD(this->lifespan_rand) = *(_DWORD *)v20;
    v21 = (char *)*addr + 4;
    *addr = v21;
    LODWORD(this->lifespan) = *(_DWORD *)v21;
    v22 = (char *)*addr + 4;
    *addr = v22;
    HIDWORD(this->lifespan) = *(_DWORD *)v22;
    v20 = (char *)*addr + 4;
    *addr = v20;
  }
  LODWORD(this->offset_dir.z) = *(_DWORD *)v20;
  v23 = (char *)*addr + 4;
  *addr = v23;
  LODWORD(this->min_offset) = *(_DWORD *)v23;
  v24 = (char *)*addr + 4;
  *addr = v24;
  if ( size >= 0xC )
  {
    LODWORD(this->sorting_sphere.center.x) = *(_DWORD *)v24;
    v25 = (char *)*addr + 4;
    *addr = v25;
    LODWORD(this->sorting_sphere.center.y) = *(_DWORD *)v25;
    v26 = (char *)*addr + 4;
    *addr = v26;
    LODWORD(this->sorting_sphere.center.z) = *(_DWORD *)v26;
    v24 = (char *)*addr + 4;
    *addr = v24;
  }
  LODWORD(this->max_offset) = *(_DWORD *)v24;
  v27 = (char *)*addr + 4;
  *addr = v27;
  LODWORD(this->a.x) = *(_DWORD *)v27;
  v28 = (char *)*addr + 4;
  *addr = v28;
  if ( size >= 0xC )
  {
    LODWORD(this->sorting_sphere.radius) = *(_DWORD *)v28;
    v29 = (char *)*addr + 4;
    *addr = v29;
    LODWORD(this->offset_dir.x) = *(_DWORD *)v29;
    v30 = (char *)*addr + 4;
    *addr = v30;
    LODWORD(this->offset_dir.y) = *(_DWORD *)v30;
    v31 = (char *)*addr + 4;
    *addr = v31;
    v28 = v31;
  }
  LODWORD(this->a.y) = *(_DWORD *)v28;
  v32 = (char *)*addr + 4;
  *addr = v32;
  LODWORD(this->a.z) = *(_DWORD *)v32;
  v33 = (char *)*addr + 4;
  *addr = v33;
  LODWORD(this->b.y) = *(_DWORD *)v33;
  v34 = (char *)*addr + 4;
  *addr = v34;
  LODWORD(this->b.z) = *(_DWORD *)v34;
  v35 = (char *)*addr + 4;
  *addr = v35;
  LODWORD(this->b.x) = *(_DWORD *)v35;
  v36 = (char *)*addr + 4;
  *addr = v36;
  LODWORD(this->c.y) = *(_DWORD *)v36;
  v37 = (char *)*addr + 4;
  *addr = v37;
  LODWORD(this->c.z) = *(_DWORD *)v37;
  v38 = (char *)*addr + 4;
  *addr = v38;
  LODWORD(this->c.x) = *(_DWORD *)v38;
  v39 = (char *)*addr + 4;
  *addr = v39;
  LODWORD(this->m_timeStamp) = *(_DWORD *)v39;
  *addr = (char *)*addr + 4;
  ParticleEmitterInfo::InitEnd((ParticleEmitterInfo *)((char *)this - 48));
  return 1;
}

//----- (006FC440) --------------------------------------------------------  // acclient.c:784615
void sub_6FC440()
{
  flt_843F6C = 1000.0 + 1.0;
}

//----- (006FC460) --------------------------------------------------------  // acclient.c:784621
void sub_6FC460()
{
  flt_843F70 = 24.0 * 8.0;
}

//----- (006FC480) --------------------------------------------------------  // acclient.c:784627
void sub_6FC480()
{
  flt_843F74 = 24.0 * 0.5;
}

//----- (006FC4A0) --------------------------------------------------------  // acclient.c:784633
void sub_6FC4A0()
{
  DEFAULT_VIEW_RADIUS_98 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FC4C0) --------------------------------------------------------  // acclient.c:784639
void _E99_15()
{
  MIN_QUANTUM_98 = 1.0 / 30.0;
}

//----- (006FC4E0) --------------------------------------------------------  // acclient.c:784645
void _E101_10()
{
  MAX_QUANTUM_98 = 1.0 / 5.0;
}

//----- (006FC500) --------------------------------------------------------  // acclient.c:784651
int sub_6FC500()
{
  return atexit(nullsub_1104);
}

