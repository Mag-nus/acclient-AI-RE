/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CParticleEmitter
   Object     : PORTAL\cphysobj\CParticleEmitter.obj
   Functions  : 27
   Addresses  : 0051C190 - 006FCD80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051C190) --------------------------------------------------------  // acclient.c:330251
int __thiscall ParticleEmitter::SetParenting(ParticleEmitter *this, unsigned int _part_index, Frame *_frame)
{
  ParticleEmitter *v3; // esi@1
  CPhysicsObj *v4; // ecx@1
  int result; // eax@3

  v3 = this;
  v4 = this->physobj;
  if ( v4 && CPhysicsObj::set_parent(v4, v3->parent, _part_index, _frame) )
  {
    v3->part_index = _part_index;
    Frame::operator=((int)&v3->parent_offset, (int)_frame);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0051C1E0) --------------------------------------------------------  // acclient.c:330273
int __thiscall ParticleEmitter::KillParticle(ParticleEmitter *this, unsigned int i)
{
  ParticleEmitter *v2; // esi@1
  int result; // eax@2

  v2 = this;
  if ( this->particles[i].lifetime < this->particles[i].lifespan )
  {
    result = 0;
  }
  else
  {
    CPhysicsObj::RemovePartFromShadowCells(this->physobj, this->parts[i]);
    v2->parts[i] = 0;
    --v2->num_particles;
    result = 1;
  }
  return result;
}

//----- (0051C230) --------------------------------------------------------  // acclient.c:330294
int __thiscall ParticleEmitter::StopEmitter(ParticleEmitter *this)
{
  ParticleEmitterInfo *v1; // edx@2
  int v2; // edx@5

  if ( !this->stopped )
  {
    v1 = this->info;
    if ( v1->total_seconds > 0.0 && this->creation_time + v1->total_seconds < PhysicsTimer::curr_time )
      this->stopped = 1;
    v2 = v1->total_particles;
    if ( v2 && this->total_emitted >= v2 )
      this->stopped = 1;
  }
  return this->stopped;
}

//----- (0051C290) --------------------------------------------------------  // acclient.c:330312
void __thiscall Particle::Update(Particle *this, ParticleType _particle_type, int _is_persistent, CPhysicsPart *part, Frame *parent_frame)
{
  Particle *v5; // esi@1
  long double v6; // st7@1
  int v7; // ecx@2
  Vector3 *v8; // eax@5
  float origin_4; // ST1C_4@5
  char *v10; // ecx@5
  float origin_8; // ST20_4@5
  long double v12; // st7@6
  char *v13; // ecx@6
  float origin; // ST18_4@6
  float v15; // ST1C_4@6
  double v16; // st6@6
  float v17; // ST28_4@6
  float v18; // ST2C_4@6
  float v19; // ST20_4@6
  float v20; // ST18_4@6
  float v21; // ST1C_4@6
  char *v22; // ecx@7
  float v23; // ST18_4@7
  float v24; // ST1C_4@7
  float v25; // ST20_4@7
  long double v26; // st7@7
  float v27; // ST28_4@7
  float v28; // ST2C_4@7
  float v29; // ST14_4@7
  float v30; // ST18_4@7
  float v31; // ST1C_4@7
  float v32; // ST20_4@7
  long double v33; // st6@7
  long double v34; // rt1@7
  double v35; // st6@7
  float v36; // ST28_4@7
  float v37; // ST2C_4@7
  double v38; // st7@7
  float v39; // ST20_4@7
  float v40; // ST18_4@7
  float v41; // ST1C_4@7
  float v42; // ST18_4@8
  float v43; // ST1C_4@8
  float v44; // ST20_4@8
  long double v45; // st7@8
  float v46; // ST14_4@8
  double v47; // st5@8
  float v48; // ST2C_4@8
  long double v49; // st3@8
  long double v50; // st4@8
  long double v51; // st6@8
  long double v52; // st5@8
  long double v53; // st7@8
  long double v54; // st7@9
  char *v55; // ecx@9
  float v56; // ST18_4@9
  float v57; // ST1C_4@9
  long double v58; // st7@9
  float v59; // ST20_4@9
  long double v60; // st6@10
  long double v61; // st7@10
  float v62; // ST18_4@10
  float v63; // ST1C_4@10
  long double v64; // st7@10
  char *v65; // eax@10
  float v66; // ST20_4@10
  long double v67; // st7@11
  char *v68; // edx@11
  float v69; // ST18_4@11
  float v70; // ST1C_4@11
  long double v71; // st6@11
  float v72; // ST20_4@11
  long double v73; // st7@13
  char *v74; // ecx@15
  long double v75; // st6@15
  float v76; // ST18_4@15
  float v77; // ST1C_4@15
  float v78; // ST20_4@15
  float _translucency; // ST04_4@15
  Vector3 result; // [sp+2Ch] [bp-58h]@5
  AC1Legacy::Vector3 w; // [sp+38h] [bp-4Ch]@6
  Frame new_frame; // [sp+44h] [bp-40h]@8

  v5 = this;
  v6 = PhysicsTimer::curr_time - this->birthtime;
  if ( _is_persistent )
  {
    this->lifetime = v6 + this->lifetime;
    v7 = HIDWORD(PhysicsTimer::curr_time);
    LODWORD(v5->birthtime) = LODWORD(PhysicsTimer::curr_time);
    HIDWORD(v5->last_update_time) = v7;
  }
  else
  {
    this->lifetime = v6;
  }
  switch ( _particle_type )
  {
    case 1:
      v8 = Vector3::operator+((Vector3 *)&parent_frame->m_fOrigin.x, &result, (Vector3 *)&v5->offset.x);
      origin_4 = v8->y;
      v10 = (char *)&part->pos.frame.m_fOrigin;
      origin_8 = v8->z;
      *(_DWORD *)v10 = LODWORD(v8->x);
      *((float *)v10 + 1) = origin_4;
      *((float *)v10 + 2) = origin_8;
      break;
    case 2:
    case 12:
      v12 = v5->lifetime;
      v13 = (char *)&part->pos.frame.m_fOrigin;
      origin = v12 * v5->a.x;
      v15 = v12 * v5->a.y;
      v16 = parent_frame->m_fOrigin.x + v5->offset.x;
      v17 = v5->offset.y + parent_frame->m_fOrigin.y;
      v18 = v5->offset.z + parent_frame->m_fOrigin.z;
      w.z = v18 + v12 * v5->a.z;
      v19 = w.z;
      v20 = v16 + origin;
      *(float *)v13 = v20;
      v21 = v17 + v15;
      *((float *)v13 + 1) = v21;
      *((float *)v13 + 2) = v19;
      break;
    case 3:
    case 8:
    case 10:
      v22 = (char *)&part->pos.frame.m_fOrigin;
      v23 = v5->b.x * 0.5;
      v24 = v5->b.y * 0.5;
      v25 = v5->b.z * 0.5;
      v26 = v5->lifetime;
      v27 = v24 * v26;
      v28 = v25 * v26;
      v29 = v26;
      v30 = v23 * v26 * v29;
      v31 = v27 * v29;
      v32 = v28 * v29;
      v33 = v26 * v5->a.x;
      result.y = v26 * v5->a.y;
      v34 = v33;
      result.z = v26 * v5->a.z;
      v35 = v5->offset.x + parent_frame->m_fOrigin.x;
      v36 = v5->offset.y + parent_frame->m_fOrigin.y;
      v37 = v5->offset.z + parent_frame->m_fOrigin.z;
      w.y = v36 + result.y;
      w.z = v37 + result.z;
      w.z = w.z + v32;
      v38 = w.y + v31;
      v39 = w.z;
      v40 = v34 + v35 + v30;
      *(float *)v22 = v40;
      v41 = v38;
      *((float *)v22 + 1) = v41;
      *((float *)v22 + 2) = v39;
      break;
    case 4:
    case 9:
    case 11:
      Frame::operator=((int)&new_frame, (int)parent_frame);
      v42 = v5->b.x * 0.5;
      v43 = v5->b.y * 0.5;
      v44 = v5->b.z * 0.5;
      v45 = v5->lifetime;
      w.y = v43 * v45;
      w.z = v44 * v45;
      v46 = v45;
      v47 = w.y * v46;
      v48 = w.z * v46;
      v49 = v45 * v5->a.x;
      w.y = v45 * v5->a.y;
      w.z = v45 * v5->a.z;
      v50 = v49 + v5->offset.x;
      result.y = w.y + v5->offset.y;
      result.z = w.z + v5->offset.z;
      w.x = v50 + v42 * v45 * v46;
      new_frame.m_fOrigin.x = new_frame.m_fOrigin.x + w.x;
      new_frame.m_fOrigin.y = new_frame.m_fOrigin.y + result.y + v47;
      new_frame.m_fOrigin.z = new_frame.m_fOrigin.z + result.z + v48;
      v51 = v45 * v5->c.x;
      v52 = v45;
      v53 = v45 * v5->c.y;
      result.z = v52 * v5->c.z;
      w.z = result.z;
      w.x = v51;
      w.y = v53;
      Frame::rotate(&new_frame, &w);
      Frame::operator=((int)&part->pos.frame, (int)&new_frame);
      break;
    case 5:
      v54 = v5->lifetime;
      v55 = (char *)&part->pos.frame.m_fOrigin;
      v56 = cos(v5->b.x * v54) * v5->c.x + v54 * v5->a.x + v5->offset.x + parent_frame->m_fOrigin.x;
      v57 = sin(v5->b.y * v54) * v5->c.y + v54 * v5->a.y + v5->offset.y + parent_frame->m_fOrigin.y;
      v58 = cos(v5->b.z * v54) * v5->c.z + v54 * v5->a.z + v5->offset.z + parent_frame->m_fOrigin.z;
      *(float *)v55 = v56;
      *((float *)v55 + 1) = v57;
      v59 = v58;
      *((float *)v55 + 2) = v59;
      break;
    case 7:
      v60 = cos(v5->a.x * v5->lifetime);
      v61 = v5->lifetime * v5->lifetime;
      v62 = v60 * v5->c.x + v61 * v5->b.x + v5->offset.x + parent_frame->m_fOrigin.x;
      v63 = v60 * v5->c.y + v61 * v5->b.y + v5->offset.y + parent_frame->m_fOrigin.y;
      v64 = v60 * v5->c.z + v61 * v5->b.z + v5->offset.z + parent_frame->m_fOrigin.z;
      v65 = (char *)&part->pos.frame.m_fOrigin;
      *(float *)v65 = v62;
      *((float *)v65 + 1) = v63;
      v66 = v64;
      *((float *)v65 + 2) = v66;
      break;
    case 6:
      v67 = v5->lifetime;
      v68 = (char *)&part->pos.frame.m_fOrigin;
      v69 = (v67 * v5->b.x + v5->c.x * v5->a.x) * v67 + v5->offset.x + parent_frame->m_fOrigin.x;
      v70 = (v67 * v5->b.y + v5->c.y * v5->a.x) * v67 + v5->offset.y + parent_frame->m_fOrigin.y;
      v71 = (v67 * v5->b.z + v5->c.z * v5->a.x + v5->a.z) * v67 + v5->offset.z + parent_frame->m_fOrigin.z;
      *(float *)v68 = v69;
      *((float *)v68 + 1) = v70;
      v72 = v71;
      *((float *)v68 + 2) = v72;
      break;
    default:
      break;
  }
  if ( v5->lifetime < v5->lifespan )
    v73 = v5->lifetime / v5->lifespan;
  else
    v73 = 1.0;
  v74 = (char *)&part->gfxobj_scale;
  v75 = (v5->final_scale - v5->start_scale) * v73 + v5->start_scale;
  v76 = v75;
  v77 = v75;
  v78 = v75;
  *(float *)v74 = v76;
  *((float *)v74 + 1) = v77;
  *((float *)v74 + 2) = v78;
  _translucency = (v5->final_trans - v5->start_trans) * v73 + v5->start_trans;
  CPhysicsPart::SetTranslucency(part, _translucency);
}

//----- (0051C7E0) --------------------------------------------------------  // acclient.c:330553
void __thiscall ParticleEmitter::ParticleEmitter(ParticleEmitter *this, CPhysicsObj *_parent)
{
  ParticleEmitter *v2; // esi@1
  char *v3; // ecx@1
  unsigned int v4; // edx@1
  unsigned int v5; // ecx@1

  v2 = this;
  v3 = (char *)&this->parent_offset;
  v2->parent = _parent;
  v2->part_index = -1;
  v2->id = 0;
  *(_DWORD *)v3 = 1065353216;
  *((_DWORD *)v3 + 1) = 0;
  *((_DWORD *)v3 + 2) = 0;
  *((_DWORD *)v3 + 3) = 0;
  *((_DWORD *)v3 + 13) = 0;
  *((_DWORD *)v3 + 14) = 0;
  *((_DWORD *)v3 + 15) = 0;
  Frame::cache((Frame *)v3);
  v2->physobj = 0;
  v2->info = 0;
  v2->particles = 0;
  v2->part_storage = 0;
  v2->parts = 0;
  v2->degraded_out = 0;
  LODWORD(v2->degrade_distance) = 0;
  v2->num_particles = 0;
  v2->total_emitted = 0;
  v2->stopped = 0;
  v4 = Timer::cur_time.Param;
  LODWORD(v2->last_update_time) = Timer::cur_time.Cmd;
  HIDWORD(v2->last_update_time) = v4;
  v5 = Timer::cur_time.Param;
  LODWORD(v2->last_emit_time) = Timer::cur_time.Cmd;
  HIDWORD(v2->last_emit_time) = v5;
}

//----- (0051C870) --------------------------------------------------------  // acclient.c:330592
void __thiscall ParticleEmitter::RecordParticleEmission(ParticleEmitter *this)
{
  CPhysicsObj *v1; // eax@1
  char *v2; // edx@1
  int v3; // eax@1

  ++this->num_particles;
  v1 = this->physobj;
  ++this->total_emitted;
  v1 = (CPhysicsObj *)((char *)v1 + 132);
  v2 = (char *)&this->last_emit_offset;
  *(_DWORD *)v2 = v1->vfptr;
  *((_DWORD *)v2 + 1) = v1->hash_next;
  *((_DWORD *)v2 + 2) = v1->id;
  v3 = HIDWORD(PhysicsTimer::curr_time);
  LODWORD(this->last_emit_time) = LODWORD(PhysicsTimer::curr_time);
  HIDWORD(this->last_emit_time) = v3;
}

//----- (0051C8B0) --------------------------------------------------------  // acclient.c:330612
int __thiscall ParticleEmitter::ShouldEmitParticle(ParticleEmitter *this)
{
  ParticleEmitter *v1; // eax@1
  ParticleEmitterInfo *v2; // ecx@1
  CPhysicsObj *v3; // edx@2
  double v4; // st7@2
  float v5; // ST14_4@2
  float v6; // ST18_4@2
  double v7; // st7@2
  float v8; // ST1C_4@2
  AC1Legacy::Vector3 delta_offset; // [sp+Ch] [bp-Ch]@2

  v1 = this;
  v2 = this->info;
  if ( v2->emitter_type & 2 )
  {
    v3 = v1->physobj;
    v4 = v3->m_position.frame.m_fOrigin.x;
    v3 = (CPhysicsObj *)((char *)v3 + 132);
    v5 = v4 - v1->last_emit_offset.x;
    v6 = *(float *)&v3->hash_next - v1->last_emit_offset.y;
    v7 = *(float *)&v3->id - v1->last_emit_offset.z;
    delta_offset.x = v5;
    delta_offset.y = v6;
    v8 = v7;
    delta_offset.z = v8;
  }
  return ParticleEmitterInfo::ShouldEmitParticle(
           v2,
           v1->num_particles,
           v1->total_emitted,
           &delta_offset,
           v1->last_emit_time);
}

//----- (0051C930) --------------------------------------------------------  // acclient.c:330648
void __thiscall Particle::Init(Particle *this, CPhysicsObj *parent, const unsigned int part_index, Frame *parent_offset, CPhysicsPart *part, AC1Legacy::Vector3 *_offset, ParticleType _particle_type, const int _is_persistent, AC1Legacy::Vector3 *_a, AC1Legacy::Vector3 *_b, AC1Legacy::Vector3 *_c, const float _start_scale, const float _final_scale, const float _start_trans, const float _final_trans, const long double _lifespan)
{
  int v16; // edx@1
  Particle *v17; // esi@1
  int v18; // ecx@1
  double v19; // st7@4
  double v20; // st6@4
  AC1Legacy::Vector3 *v21; // eax@4
  double v22; // st5@4
  double v23; // rt0@4
  double v24; // st5@4
  double v25; // st6@4
  AC1Legacy::Vector3 *v26; // edx@7
  AC1Legacy::Vector3 *v27; // eax@8
  int v28; // ecx@8
  AC1Legacy::Vector3 *v29; // eax@9
  int v30; // ecx@9
  AC1Legacy::Vector3 *v31; // eax@10
  int v32; // ecx@10
  int v33; // edx@13
  AC1Legacy::Vector3 *v34; // eax@14
  int v35; // ecx@14
  float v36; // ecx@15
  double v37; // st7@16
  long double v38; // st6@16
  int v39; // ebx@16
  float v40; // ecx@16
  long double v41; // st7@16
  float v42; // eax@16
  char *v43; // edx@21
  float v44; // ST0C_4@21
  AC1Legacy::Vector3 v45; // [sp+10h] [bp-3Ch]@4
  AC1Legacy::Vector3 result; // [sp+1Ch] [bp-30h]@8
  AC1Legacy::Vector3 v47; // [sp+28h] [bp-24h]@9
  char v48; // [sp+34h] [bp-18h]@9
  AC1Legacy::Vector3 v49; // [sp+40h] [bp-Ch]@14
  AC1Legacy::Vector3 *_aa; // [sp+6Ch] [bp+20h]@16

  v16 = HIDWORD(PhysicsTimer::curr_time);
  v17 = this;
  v18 = LODWORD(PhysicsTimer::curr_time);
  LODWORD(v17->lifetime) = 0;
  HIDWORD(v17->lifetime) = 0;
  HIDWORD(v17->last_update_time) = v16;
  LODWORD(v17->birthtime) = v18;
  v17->lifespan = _lifespan;
  if ( part_index == -1 )
    Frame::operator=((int)&v17->start_frame, (int)&parent->m_position.frame);
  else
    Frame::operator=((int)&v17->start_frame, (int)&parent->part_array->parts[part_index]->pos.frame);
  v19 = _offset->x + parent_offset->m_fOrigin.x;
  v20 = parent_offset->m_fOrigin.y + _offset->y;
  v21 = &v17->offset;
  v22 = parent_offset->m_fOrigin.z + _offset->z;
  v45.x = v22 * v17->start_frame.m_fl2gv[6] + v20 * v17->start_frame.m_fl2gv[3] + v19 * v17->start_frame.m_fl2gv[0];
  v45.y = v22 * v17->start_frame.m_fl2gv[7] + v20 * v17->start_frame.m_fl2gv[4] + v19 * v17->start_frame.m_fl2gv[1];
  v23 = v22 * v17->start_frame.m_fl2gv[8];
  v24 = v20 * v17->start_frame.m_fl2gv[5];
  v25 = v19 * v17->start_frame.m_fl2gv[2];
  v17->offset = v45;
  v45.z = v23 + v24 + v25;
  switch ( _particle_type )
  {
    case 4:
      v17->c = *_c;
      goto $L112711;
    case 3:
$L112711:
      v17->b = *_b;
      goto $L112712;
    case 2:
$L112712:
      v26 = &v45;
      goto LABEL_10;
    case 9:
      v27 = Frame::localtoglobalvec(&v17->start_frame, &result, _c);
      v28 = (int)&v17->c;
      *(_DWORD *)v28 = LODWORD(v27->x);
      *(_DWORD *)(v28 + 4) = LODWORD(v27->y);
      *(_DWORD *)(v28 + 8) = LODWORD(v27->z);
      goto $L112717;
    case 8:
$L112717:
      v29 = Frame::localtoglobalvec(&v17->start_frame, &v47, _b);
      v30 = (int)&v17->b;
      *(_DWORD *)v30 = LODWORD(v29->x);
      *(_DWORD *)(v30 + 4) = LODWORD(v29->y);
      *(_DWORD *)(v30 + 8) = LODWORD(v29->z);
      v26 = (AC1Legacy::Vector3 *)&v48;
LABEL_10:
      v31 = Frame::localtoglobalvec(&v17->start_frame, v26, _a);
      v32 = (int)&v17->a;
      *(_DWORD *)v32 = LODWORD(v31->x);
      *(_DWORD *)(v32 + 4) = LODWORD(v31->y);
      *(_DWORD *)(v32 + 8) = LODWORD(v31->z);
      break;
    case 11:
      v17->c = *_c;
      goto $L112721;
    case 10:
$L112721:
      v17->b = *_b;
      goto $L112722;
    case 12:
$L112722:
      v21 = _a;
      v33 = (int)&v17->a;
      goto LABEL_19;
    case 5:
      v34 = Frame::localtoglobalvec(&v17->start_frame, &v49, _a);
      v35 = (int)&v17->a;
      *(_DWORD *)v35 = LODWORD(v34->x);
      *(_DWORD *)(v35 + 4) = LODWORD(v34->y);
      *(_DWORD *)(v35 + 8) = LODWORD(v34->z);
      v17->b = *_b;
      v17->c = *_c;
      break;
    case 7:
      v17->a = *_a;
      v17->b = *_b;
      v33 = (int)&v17->c;
      v21->x = _c->x * v21->x;
      v17->offset.y = _c->y * v17->offset.y;
      v17->offset.z = _c->z * v17->offset.z;
      v17->c.x = v21->x;
      v36 = v17->offset.y;
      goto LABEL_20;
    case 6:
      v17->a = *_a;
      v17->b = *_b;
      *(float *)&_aa = Random::RollDice(-3.1415927, 3.1415927);
      v37 = Random::RollDice(-3.1415927, 3.1415927);
      v38 = cos(v37);
      v39 = (int)&v17->c;
      v45.x = cos(*(float *)&_aa) * _c->x * v38;
      v45.y = sin(*(float *)&_aa) * _c->y * v38;
      v40 = v45.y;
      v41 = sin(v37) * _c->z;
      *(_DWORD *)v39 = (_DWORD)v45.x;
      v45.z = v41;
      v42 = v45.z;
      *(float *)(v39 + 4) = v40;
      *(float *)(v39 + 8) = v42;
      if ( AC1Legacy::Vector3::normalize_check_small(&v17->c) )
      {
        LODWORD(v45.x) = 0;
        LODWORD(v45.y) = 0;
        LODWORD(v45.z) = 0;
        *(_DWORD *)v39 = 0;
        LODWORD(v17->c.y) = 0;
        LODWORD(v17->c.z) = 0;
      }
      break;
    case 1:
      break;
    default:
      v17->a = *_a;
      v17->b = *_b;
      v21 = _c;
      v33 = (int)&v17->c;
LABEL_19:
      *(_DWORD *)v33 = LODWORD(v21->x);
      v36 = v21->y;
LABEL_20:
      *(float *)(v33 + 4) = v36;
      *(_DWORD *)(v33 + 8) = LODWORD(v21->z);
      break;
  }
  v17->start_scale = _start_scale;
  v17->final_scale = _final_scale;
  v17->final_trans = _final_trans;
  v17->start_trans = _start_trans;
  v45.x = _start_scale;
  v43 = (char *)&part->gfxobj_scale;
  *(const float *)v43 = _start_scale;
  *((const float *)v43 + 1) = _start_scale;
  v45.z = _start_scale;
  *((const float *)v43 + 2) = _start_scale;
  v44 = v17->start_trans;
  v45.y = _start_scale;
  CPhysicsPart::SetTranslucency(part, v44);
  Particle::Update(v17, _particle_type, _is_persistent, part, &v17->start_frame);
}

//----- (0051CD80) --------------------------------------------------------  // acclient.c:330833
void __cdecl ParticleEmitter::makeParticleEmitter(CPhysicsObj *_parent)
{
  ParticleEmitter *v1; // eax@2

  if ( _parent )
  {
    v1 = (ParticleEmitter *)operator new(0x98u);
    if ( v1 )
      ParticleEmitter::ParticleEmitter(v1, _parent);
  }
}

//----- (0051CDB0) --------------------------------------------------------  // acclient.c:330846
void __thiscall ParticleEmitter::Destroy(ParticleEmitter *this)
{
  ParticleEmitter *v1; // esi@1
  CPhysicsObj *v2; // ecx@1
  unsigned int i; // edi@4
  CPhysicsPart **v4; // ecx@5
  void *v5; // ebx@5
  Particle *v6; // eax@9
  ParticleEmitterInfo *v7; // ecx@11
  CPhysicsObj *v8; // ecx@15
  long double v9; // kr00_8@17

  v1 = this;
  v2 = this->physobj;
  if ( v2 )
  {
    CPhysicsObj::unset_parent(v2);
    CPhysicsObj::leave_world(v1->physobj);
  }
  if ( v1->part_storage )
  {
    for ( i = 0; i < v1->info->max_particles; ++i )
    {
      v4 = v1->part_storage;
      v5 = v4[i];
      if ( v5 )
      {
        CPhysicsPart::~CPhysicsPart(v4[i]);
        operator delete(v5);
      }
      v1->part_storage[i] = 0;
      v1->parts[i] = 0;
    }
    operator delete[](v1->part_storage);
    v1->part_storage = 0;
  }
  v6 = v1->particles;
  if ( v6 )
  {
    operator delete[](&v6[-1].final_trans);
    v1->particles = 0;
  }
  v7 = v1->info;
  if ( v7 )
  {
    if ( v7->m_DID.id != stru_84426C.id )
      ((void (*)(void))v7->vfptr->Release)();
    v1->info = 0;
  }
  v8 = v1->physobj;
  if ( v8 )
  {
    ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
    v1->physobj = 0;
  }
  v1->parts = 0;
  v9 = PhysicsTimer::curr_time;
  v1->num_particles = 0;
  v1->last_update_time = v9;
}

//----- (0051CE90) --------------------------------------------------------  // acclient.c:330908
int __thiscall ParticleEmitter::SetInfo(ParticleEmitter *this, ParticleEmitterInfo *_info)
{
  ParticleEmitter *v2; // edi@1
  unsigned int v3; // ebp@1
  int v5; // eax@3
  int v6; // edx@5
  ParticleEmitterInfo *v7; // ecx@5
  void *v8; // eax@5
  int i; // eax@6
  int j; // esi@8
  int v11; // esi@11
  void *v12; // eax@11
  int v13; // eax@12
  int v14; // ebp@12
  int v15; // esi@13
  int v16; // ebp@13
  ParticleEmitterInfo *_infoa; // [sp+Ch] [bp+4h]@12

  v2 = this;
  ParticleEmitter::Destroy(this);
  v2->info = _info;
  v3 = _info->hw_gfxobj_id.id;
  if ( v3 == stru_84426C.id )
  {
    ParticleEmitter::Destroy(v2);
    return 0;
  }
  v5 = CPhysicsObj::makeParticleObject(_info->max_particles);
  v2->physobj = (CPhysicsObj *)v5;
  if ( !v5 )
    goto LABEL_4;
  v6 = (int)&v2->last_emit_offset;
  *(_DWORD *)v6 = *(_DWORD *)(v5 + 132);
  *(_DWORD *)(v6 + 4) = *(_DWORD *)(v5 + 136);
  *(_DWORD *)(v6 + 8) = *(_DWORD *)(v5 + 140);
  v7 = v2->info;
  v2->parts = *(CPhysicsPart ***)(*(_DWORD *)(v5 + 16) + 92);
  v8 = operator new[](4 * v7->max_particles);
  v2->part_storage = (CPhysicsPart **)v8;
  if ( !v8 )
    goto LABEL_4;
  for ( i = 0; i < v2->info->max_particles; ++i )
    v2->part_storage[i] = 0;
  for ( j = 0; j < v2->info->max_particles; ++j )
  {
    v2->part_storage[j] = CPhysicsPart::makePhysicsPart((IDClass<_tagDataID,32,0>)v3);
    if ( !v2->part_storage[j] )
      goto LABEL_4;
  }
  v2->degrade_distance = CPhysicsPart::GetMaxDegradeDistance(*v2->part_storage);
  v11 = v2->info->max_particles;
  v12 = operator new[](152 * v11 + 4);
  if ( v12 )
  {
    *(_DWORD *)v12 = v11;
    v13 = (int)((char *)v12 + 4);
    v14 = v11 - 1;
    _infoa = (ParticleEmitterInfo *)v13;
    if ( v11 - 1 >= 0 )
    {
      v15 = v13 + 84;
      v16 = v14 + 1;
      do
      {
        *(_DWORD *)(v15 - 60) = 1065353216;
        *(_DWORD *)(v15 - 56) = 0;
        *(_DWORD *)(v15 - 52) = 0;
        *(_DWORD *)(v15 - 48) = 0;
        *(_DWORD *)(v15 - 8) = 0;
        *(_DWORD *)(v15 - 4) = 0;
        *(_DWORD *)v15 = 0;
        Frame::cache((Frame *)(v15 - 60));
        v15 += 152;
        --v16;
      }
      while ( v16 );
      v13 = (int)_infoa;
    }
  }
  else
  {
    v13 = 0;
  }
  v2->particles = (Particle *)v13;
  if ( !v13 )
  {
LABEL_4:
    ParticleEmitter::Destroy(v2);
    return 0;
  }
  return 1;
}

//----- (0051D010) --------------------------------------------------------  // acclient.c:331002
void __thiscall ParticleEmitter::EmitParticle(ParticleEmitter *this)
{
  ParticleEmitter *v1; // esi@1
  int v2; // ecx@1
  int v3; // edi@1
  CPhysicsPart **v4; // eax@2
  ParticleEmitterInfo *v5; // ecx@7
  const int v6; // ebp@9
  ParticleType v7; // ebx@11
  double _lifespan; // ST38_8@11
  float _final_trans; // ST34_4@11
  float _start_trans; // ST30_4@11
  float _final_scale; // ST2C_4@11
  float _start_scale; // ST28_4@11
  AC1Legacy::Vector3 *v13; // ST24_4@11
  AC1Legacy::Vector3 *v14; // ST20_4@11
  AC1Legacy::Vector3 *v15; // ST1C_4@11
  AC1Legacy::Vector3 *v16; // eax@11
  CPhysicsObj *v17; // eax@11
  int v18; // edx@11
  int v19; // ecx@11
  int v20; // edx@11
  AC1Legacy::Vector3 result; // [sp+28h] [bp-30h]@11
  AC1Legacy::Vector3 v22; // [sp+34h] [bp-24h]@11
  AC1Legacy::Vector3 v23; // [sp+40h] [bp-18h]@11
  AC1Legacy::Vector3 v24; // [sp+4Ch] [bp-Ch]@11

  v1 = this;
  v2 = this->info->max_particles;
  v3 = 0;
  if ( v2 > 0 )
  {
    v4 = v1->parts;
    do
    {
      if ( !*v4 )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < v1->info->max_particles );
  }
  if ( v3 != v2 )
  {
    v1->parts[v3] = v1->part_storage[v3];
    if ( v1->parts[v3] )
    {
      v5 = v1->info;
      v6 = !v5->total_particles && v5->total_seconds == 0.0;
      v7 = v5->particle_type;
      _lifespan = ParticleEmitterInfo::GetRandomLifespan(v5);
      _final_trans = ParticleEmitterInfo::GetRandomFinalTrans(v1->info);
      _start_trans = ParticleEmitterInfo::GetRandomStartTrans(v1->info);
      _final_scale = ParticleEmitterInfo::GetRandomFinalScale(v1->info);
      _start_scale = ParticleEmitterInfo::GetRandomStartScale(v1->info);
      v13 = ParticleEmitterInfo::GetRandomC(v1->info, &result);
      v14 = ParticleEmitterInfo::GetRandomB(v1->info, &v22);
      v15 = ParticleEmitterInfo::GetRandomA(v1->info, &v23);
      v16 = ParticleEmitterInfo::GetRandomOffset(v1->info, &v24);
      Particle::Init(
        &v1->particles[v3],
        v1->parent,
        v1->part_index,
        &v1->parent_offset,
        v1->parts[v3],
        v16,
        v7,
        v6,
        v15,
        v14,
        v13,
        _start_scale,
        _final_scale,
        _start_trans,
        _final_trans,
        _lifespan);
      CPhysicsObj::AddPartToShadowCells(v1->physobj, v1->parts[v3]);
      v17 = v1->physobj;
      v18 = v1->total_emitted + 1;
      ++v1->num_particles;
      v1->total_emitted = v18;
      v17 = (CPhysicsObj *)((char *)v17 + 132);
      v19 = (int)&v1->last_emit_offset;
      *(_DWORD *)v19 = v17->vfptr;
      *(_DWORD *)(v19 + 4) = v17->hash_next;
      *(_DWORD *)(v19 + 8) = v17->id;
      v20 = HIDWORD(PhysicsTimer::curr_time);
      LODWORD(v1->last_emit_time) = LODWORD(PhysicsTimer::curr_time);
      HIDWORD(v1->last_emit_time) = v20;
    }
  }
}

//----- (0051D180) --------------------------------------------------------  // acclient.c:331096
int __thiscall ParticleEmitter::UpdateParticles(ParticleEmitter *this)
{
  ParticleEmitter *v1; // esi@1
  unsigned int v2; // edi@1
  CPhysicsObj *v3; // ecx@2
  bool v4; // zf@3
  int v5; // eax@3
  int v6; // edx@6
  ParticleEmitterInfo *v7; // ecx@6
  unsigned int v8; // eax@8
  int v9; // ecx@9
  int result; // eax@11
  int v11; // ebx@13
  CPhysicsObj *v12; // ecx@23
  int v13; // ebp@25
  CPhysicsPart *v14; // ebx@26
  ParticleEmitterInfo *v15; // edx@27
  unsigned int v16; // eax@28
  CPhysicsObj *v17; // ecx@28
  int v18; // ecx@29
  int v19; // eax@34
  signed int v20; // edi@38
  int v21; // edx@43

  v1 = this;
  v2 = 0;
  if ( this->info && (v3 = this->physobj) != 0 )
  {
    v4 = CPhysicsObj::ShouldDrawParticles(v3, v1->degrade_distance) == 0;
    v5 = v1->degraded_out;
    if ( v4 )
    {
      if ( !v5 )
      {
        CPhysicsObj::SetNoDraw(v1->physobj, 1);
        v1->degraded_out = 1;
      }
      v6 = HIDWORD(PhysicsTimer::curr_time);
      LODWORD(v1->last_update_time) = LODWORD(PhysicsTimer::curr_time);
      v7 = v1->info;
      HIDWORD(v1->last_update_time) = v6;
      if ( v7->total_particles || v7->total_seconds != 0.0 )
      {
        if ( v7->max_particles > 0u )
        {
          v11 = 0;
          do
          {
            if ( v1->parts[v2] )
            {
              v1->particles[v11].lifetime = PhysicsTimer::curr_time - v1->particles[v11].birthtime;
              ParticleEmitter::KillParticle(v1, v2);
            }
            ++v2;
            ++v11;
          }
          while ( v2 < v1->info->max_particles );
        }
        if ( v1->stopped )
        {
          result = v1->num_particles != 0;
        }
        else
        {
          if ( ParticleEmitter::ShouldEmitParticle(v1) )
            ParticleEmitter::RecordParticleEmission(v1);
          ParticleEmitter::StopEmitter(v1);
          result = 1;
        }
      }
      else
      {
        v8 = 0;
        if ( v7->max_particles > 0u )
        {
          v9 = 0;
          do
          {
            v1->particles[v9].birthtime = PhysicsTimer::curr_time;
            ++v8;
            ++v9;
          }
          while ( v8 < v1->info->max_particles );
        }
        result = 1;
      }
    }
    else
    {
      if ( v5 )
      {
        v12 = v1->physobj;
        v1->degraded_out = 0;
        CPhysicsObj::SetNoDraw(v12, 0);
      }
      if ( v1->info->max_particles > 0u )
      {
        v13 = 0;
        do
        {
          v14 = v1->parts[v2];
          if ( v14 )
          {
            v15 = v1->info;
            if ( v15->is_parent_local )
            {
              v16 = v1->part_index;
              v17 = v1->parent;
              if ( v16 == -1 )
                v18 = (int)&v17->m_position.frame;
              else
                v18 = (int)&v17->part_array->parts[v16]->pos.frame;
            }
            else
            {
              v18 = (int)&v1->particles[v13].start_frame;
            }
            v19 = !v15->total_particles && v15->total_seconds == 0.0;
            Particle::Update(&v1->particles[v13], (ParticleType)v15->particle_type, v19, v14, (Frame *)v18);
            ParticleEmitter::KillParticle(v1, v2);
          }
          ++v2;
          ++v13;
        }
        while ( v2 < v1->info->max_particles );
      }
      v20 = 1;
      if ( v1->stopped )
      {
        v20 = v1->num_particles != 0;
      }
      else
      {
        if ( ParticleEmitter::ShouldEmitParticle(v1) )
          ParticleEmitter::EmitParticle(v1);
        ParticleEmitter::StopEmitter(v1);
      }
      v21 = HIDWORD(PhysicsTimer::curr_time);
      result = v20;
      LODWORD(v1->last_update_time) = LODWORD(PhysicsTimer::curr_time);
      HIDWORD(v1->last_update_time) = v21;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0051D3C0) --------------------------------------------------------  // acclient.c:331247
int __thiscall ParticleEmitter::SetInfo(ParticleEmitter *this, IDClass<_tagDataID,32,0> emitter_info_id)
{
  ParticleEmitter *v2; // esi@1
  QualifiedDataID *v3; // eax@2
  int v4; // eax@2
  int result; // eax@3
  QualifiedDataID v6; // [sp+4h] [bp-8h]@2

  v2 = this;
  if ( emitter_info_id.id && (QualifiedDataID::QualifiedDataID(&v6, emitter_info_id, 0x2Au), (v4 = DBObj::Get(v3)) != 0) )
    result = ParticleEmitter::SetInfo(v2, (ParticleEmitterInfo *)v4);
  else
    result = 0;
  return result;
}

//----- (0051D400) --------------------------------------------------------  // acclient.c:331264
int __thiscall ParticleEmitter::InitEnd(ParticleEmitter *this)
{
  ParticleEmitter *v1; // esi@1
  unsigned int v2; // ecx@1
  ParticleEmitterInfo *v3; // edx@1
  int v4; // edi@1

  v1 = this;
  v2 = Timer::cur_time.Param;
  v3 = v1->info;
  LODWORD(v1->creation_time) = Timer::cur_time.Cmd;
  HIDWORD(v1->creation_time) = v2;
  v4 = 0;
  if ( v3->initial_particles > 0 )
  {
    do
    {
      ParticleEmitter::EmitParticle(v1);
      ++v4;
    }
    while ( v4 < v1->info->initial_particles );
  }
  return 1;
}

//----- (006FCC70) --------------------------------------------------------  // acclient.c:785123
void _E89_0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_844234, PFID_A8R8G8B8);
}

//----- (006FCC80) --------------------------------------------------------  // acclient.c:785129
void sub_6FCC80()
{
  LODWORD(dword_844270) = 1053364187;
}

//----- (006FCC90) --------------------------------------------------------  // acclient.c:785135
void sub_6FCC90()
{
  flt_844274 = 1000.0 + 1.0;
}

//----- (006FCCB0) --------------------------------------------------------  // acclient.c:785141
void sub_6FCCB0()
{
  flt_844278 = 24.0 * 8.0;
}

//----- (006FCCD0) --------------------------------------------------------  // acclient.c:785147
void sub_6FCCD0()
{
  flt_84427C = 24.0 * 0.5;
}

//----- (006FCCF0) --------------------------------------------------------  // acclient.c:785153
void _E99_19()
{
  flt_844280 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FCD10) --------------------------------------------------------  // acclient.c:785159
void _E101_16()
{
  dbl_844288 = 1.0 / 30.0;
}

//----- (006FCD30) --------------------------------------------------------  // acclient.c:785165
void sub_6FCD30()
{
  dbl_844290 = 1.0 / 5.0;
}

//----- (006FCD50) --------------------------------------------------------  // acclient.c:785171
void _E105_23()
{
  dword_844298 = 1024;
}

//----- (006FCD60) --------------------------------------------------------  // acclient.c:785177
void _E107_18()
{
  dword_84429C = 0x7FFF;
}

//----- (006FCD70) --------------------------------------------------------  // acclient.c:785183
int _E109_61()
{
  const int result; // eax@1

  result = dword_844298;
  INITIAL_MAX_DATA_RATE_78 = dword_844298;
  return result;
}

//----- (006FCD80) --------------------------------------------------------  // acclient.c:785193
int sub_6FCD80()
{
  return atexit(nullsub_1103);
}

