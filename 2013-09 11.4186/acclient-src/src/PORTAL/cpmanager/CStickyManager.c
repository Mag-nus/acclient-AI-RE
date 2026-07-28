/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CStickyManager
   Object     : PORTAL\cpmanager\CStickyManager.obj
   Functions  : 17
   Addresses  : 00555400 - 00707030 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00555400) --------------------------------------------------------  // acclient.c:388501
void __thiscall StickyManager::HandleExitWorld(StickyManager *this)
{
  StickyManager *v1; // esi@1
  CPhysicsObj *v2; // ecx@2

  v1 = this;
  if ( this->target_id )
  {
    v2 = this->physics_obj;
    v1->target_id = 0;
    v1->initialized = 0;
    CPhysicsObj::clear_target(v2);
    CPhysicsObj::cancel_moveto(v1->physics_obj);
  }
}

//----- (00555430) --------------------------------------------------------  // acclient.c:388518
void __thiscall StickyManager::adjust_offset(StickyManager *this, Frame *offset, long double quantum)
{
  StickyManager *v3; // ebx@1
  AC1Legacy::Vector3 *v4; // esi@3
  char *v5; // edi@3
  HashBaseData<unsigned long> *v6; // eax@3
  int v7; // ebp@3
  AC1Legacy::Vector3 *v8; // eax@5
  AC1Legacy::Vector3 *v9; // eax@5
  float v10; // ST08_4@5
  float r1; // ST00_4@5
  CMotionInterp *v12; // eax@8
  double v13; // st7@8
  long double v14; // st7@12
  long double v15; // st7@15
  float mag; // [sp+20h] [bp-14h]@5
  AC1Legacy::Vector3 result; // [sp+28h] [bp-Ch]@5
  float sought_headinga; // [sp+3Ch] [bp+8h]@15
  float sought_heading; // [sp+3Ch] [bp+8h]@15

  v3 = this;
  if ( this->target_id && this->initialized )
  {
    v4 = &offset->m_fOrigin;
    v5 = (char *)&this->physics_obj->m_position;
    v6 = CPhysicsObj::GetObjectA(this->target_id);
    v7 = (int)&v6[6];
    if ( !v6 )
      v7 = (int)&v3->target_position;
    v8 = Position::get_offset((Position *)v5, &result, (Position *)v7);
    v4->x = v8->x;
    offset->m_fOrigin.y = v8->y;
    offset->m_fOrigin.z = v8->z;
    v9 = Position::globaltolocalvec((Position *)v5, &result, v4);
    v4->x = v9->x;
    offset->m_fOrigin.y = v9->y;
    offset->m_fOrigin.z = v9->z;
    LODWORD(offset->m_fOrigin.z) = 0;
    v10 = v3->target_radius;
    r1 = CPhysicsObj::GetRadius(v3->physics_obj);
    mag = Position::cylinder_distance_no_z(r1, (Position *)v5, v10, (Position *)v7) - 0.30000001;
    if ( AC1Legacy::Vector3::normalize_check_small(v4) )
    {
      LODWORD(result.x) = 0;
      LODWORD(v4->x) = 0;
      LODWORD(result.y) = 0;
      LODWORD(result.z) = 0;
      LODWORD(offset->m_fOrigin.y) = 0;
      LODWORD(offset->m_fOrigin.z) = 0;
    }
    if ( CPhysicsObj::get_minterp(v3->physics_obj) )
    {
      v12 = CPhysicsObj::get_minterp(v3->physics_obj);
      v13 = CMotionInterp::get_max_speed(v12) * 5.0;
    }
    else
    {
      v13 = 0.0;
    }
    if ( v13 < 0.00019999999 )
      v13 = 15.0;
    v14 = v13 * quantum;
    if ( v14 >= fabs(mag) )
    {
      v4->x = mag * v4->x;
      offset->m_fOrigin.y = mag * offset->m_fOrigin.y;
      v14 = mag;
    }
    else
    {
      v4->x = v14 * v4->x;
      offset->m_fOrigin.y = v14 * offset->m_fOrigin.y;
    }
    offset->m_fOrigin.z = v14 * offset->m_fOrigin.z;
    sought_headinga = Position::heading((Position *)v5, (Position *)v7);
    v15 = sought_headinga - Frame::get_heading((Frame *)(v5 + 8));
    sought_heading = v15;
    if ( fabs(v15) < 0.00019999999 )
      sought_heading = 0.0;
    if ( -0.00019999999 > sought_heading )
      sought_heading = sought_heading + 360.0;
    Frame::set_heading(offset, sought_heading);
  }
}

//----- (00555610) --------------------------------------------------------  // acclient.c:388604
void __thiscall StickyManager::UseTime(StickyManager *this)
{
  StickyManager *v1; // esi@1
  CPhysicsObj *v2; // ecx@3

  v1 = this;
  if ( this->target_id )
  {
    if ( COERCE_DOUBLE(Timer::cur_time.Cmd) > this->sticky_timeout_time )
    {
      v2 = this->physics_obj;
      v1->target_id = 0;
      v1->initialized = 0;
      CPhysicsObj::clear_target(v2);
      CPhysicsObj::cancel_moveto(v1->physics_obj);
    }
  }
}

//----- (00555650) --------------------------------------------------------  // acclient.c:388624
void __thiscall StickyManager::Destroy(StickyManager *this)
{
  StickyManager *v1; // esi@1
  Frame v2; // [sp+Ch] [bp-40h]@3

  v1 = this;
  if ( this->target_id )
    CPhysicsObj::clear_target(this->physics_obj);
  v1->target_id = 0;
  LODWORD(v2.qw) = 1065353216;
  LODWORD(v2.qx) = 0;
  LODWORD(v2.qy) = 0;
  LODWORD(v2.qz) = 0;
  LODWORD(v2.m_fOrigin.x) = 0;
  LODWORD(v2.m_fOrigin.y) = 0;
  LODWORD(v2.m_fOrigin.z) = 0;
  Frame::cache(&v2);
  v1->target_position.objcell_id = 0;
  Frame::operator=((int)&v1->target_position.frame, (int)&v2);
  v1->initialized = 0;
}

//----- (005556E0) --------------------------------------------------------  // acclient.c:388647
void __thiscall StickyManager::SetPhysicsObject(StickyManager *this, CPhysicsObj *new_physobj)
{
  StickyManager *v2; // esi@1

  v2 = this;
  if ( this->physics_obj )
  {
    StickyManager::Destroy(this);
    v2->physics_obj = new_physobj;
  }
  else
  {
    this->physics_obj = new_physobj;
  }
}

//----- (00555710) --------------------------------------------------------  // acclient.c:388664
void __thiscall StickyManager::StickTo(StickyManager *this, unsigned int _target_id, float _target_radius, float _target_height)
{
  StickyManager *v4; // esi@1
  CPhysicsObj *v5; // ecx@2
  CPhysicsObj *v6; // ecx@3
  long double v7; // st7@3

  v4 = this;
  if ( this->target_id )
  {
    v5 = this->physics_obj;
    v4->target_id = 0;
    v4->initialized = 0;
    CPhysicsObj::clear_target(v5);
    CPhysicsObj::cancel_moveto(v4->physics_obj);
  }
  v4->target_radius = _target_radius;
  v6 = v4->physics_obj;
  v4->target_id = _target_id;
  v7 = COERCE_DOUBLE(Timer::cur_time.Cmd) + 1.0;
  v4->initialized = 0;
  v4->sticky_timeout_time = v7;
  CPhysicsObj::set_target(v6, 0, _target_id, 0.5, 0.5);
}

//----- (00555780) --------------------------------------------------------  // acclient.c:388690
void __thiscall StickyManager::HandleUpdateTarget(StickyManager *this, TargetInfo target_info)
{
  StickyManager *v2; // esi@1
  CPhysicsObj *v3; // ecx@5

  v2 = this;
  if ( target_info.object_id == this->target_id )
  {
    if ( target_info.status == 1 )
    {
      this->initialized = 1;
      this->target_position.objcell_id = target_info.target_position.objcell_id;
      Frame::operator=((int)&this->target_position.frame, (int)&target_info.target_position.frame);
    }
    else if ( this->target_id )
    {
      v3 = this->physics_obj;
      v2->target_id = 0;
      v2->initialized = 0;
      CPhysicsObj::clear_target(v3);
      CPhysicsObj::cancel_moveto(v2->physics_obj);
    }
  }
}

//----- (005557E0) --------------------------------------------------------  // acclient.c:388716
void __thiscall StickyManager::~StickyManager(StickyManager *this)
{
  StickyManager *v1; // esi@1

  v1 = this;
  StickyManager::Destroy(this);
  v1->target_position.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00555800) --------------------------------------------------------  // acclient.c:388727
StickyManager *__cdecl StickyManager::Create(CPhysicsObj *physics_obj)
{
  void *v1; // eax@1
  void *v2; // esi@1
  int v3; // ecx@2
  StickyManager *result; // eax@2

  v1 = operator new(0x60u);
  v2 = v1;
  if ( v1 )
  {
    *(_DWORD *)v1 = 0;
    *((_DWORD *)v1 + 1) = 0;
    v3 = (int)((char *)v1 + 16);
    *((_DWORD *)v1 + 2) = &Position::vftable;
    *((_DWORD *)v1 + 3) = 0;
    *(_DWORD *)v3 = 1065353216;
    *(_DWORD *)(v3 + 4) = 0;
    *(_DWORD *)(v3 + 8) = 0;
    *(_DWORD *)(v3 + 12) = 0;
    *(_DWORD *)(v3 + 52) = 0;
    *(_DWORD *)(v3 + 56) = 0;
    *(_DWORD *)(v3 + 60) = 0;
    Frame::cache((Frame *)((char *)v1 + 16));
    *((_DWORD *)v2 + 20) = 0;
    *((_DWORD *)v2 + 21) = 0;
    *((_DWORD *)v2 + 20) = physics_obj;
    result = (StickyManager *)v2;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00706F60) --------------------------------------------------------  // acclient.c:794207
void sub_706F60()
{
  flt_86FB14 = 1000.0 + 1.0;
}

//----- (00706F80) --------------------------------------------------------  // acclient.c:794213
void sub_706F80()
{
  flt_86FB18 = 24.0 * 8.0;
}

//----- (00706FA0) --------------------------------------------------------  // acclient.c:794219
void sub_706FA0()
{
  flt_86FB1C = 24.0 * 0.5;
}

//----- (00706FC0) --------------------------------------------------------  // acclient.c:794225
int _E101_34()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_37;
  dword_86FB24 = LOWEST_DATA_RATE_37;
  return result;
}

//----- (00706FD0) --------------------------------------------------------  // acclient.c:794235
void sub_706FD0()
{
  flt_86FB28 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00706FF0) --------------------------------------------------------  // acclient.c:794241
void _E105_44()
{
  dbl_86FB30 = 1.0 / 30.0;
}

//----- (00707010) --------------------------------------------------------  // acclient.c:794247
void _E107_33()
{
  dbl_86FB38 = 1.0 / 5.0;
}

//----- (00707030) --------------------------------------------------------  // acclient.c:794253
int sub_707030()
{
  return atexit(nullsub_1259);
}

