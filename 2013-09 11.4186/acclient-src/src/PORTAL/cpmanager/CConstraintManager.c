/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CConstraintManager
   Object     : PORTAL\cpmanager\CConstraintManager.obj
   Functions  : 15
   Addresses  : 00556090 - 007071F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00556090) --------------------------------------------------------  // acclient.c:389394
void __thiscall ConstraintManager::SetPhysicsObject(ConstraintManager *this, CPhysicsObj *new_physobj)
{
  if ( this->physics_obj )
  {
    this->physics_obj = 0;
    this->is_constrained = 0;
    LODWORD(this->constraint_pos_offset) = 0;
    this->physics_obj = new_physobj;
  }
  else
  {
    this->physics_obj = new_physobj;
  }
}

//----- (005560C0) --------------------------------------------------------  // acclient.c:389410
void __thiscall ConstraintManager::UnConstrain(ConstraintManager *this)
{
  this->is_constrained = 0;
}

//----- (005560D0) --------------------------------------------------------  // acclient.c:389416
BOOL __thiscall ConstraintManager::IsFullyConstrained(ConstraintManager *this)
{
  return this->constraint_distance_max * 0.9 < this->constraint_pos_offset;
}

//----- (005560F0) --------------------------------------------------------  // acclient.c:389422
void __thiscall ConstraintManager::~ConstraintManager(ConstraintManager *this)
{
  this->is_constrained = 0;
  LODWORD(this->constraint_pos_offset) = 0;
  this->physics_obj = 0;
  this->constraint_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00556110) --------------------------------------------------------  // acclient.c:389432
ConstraintManager *__cdecl ConstraintManager::Create(CPhysicsObj *physobj)
{
  void *v1; // eax@1
  void *v2; // esi@1
  int v3; // ecx@2
  ConstraintManager *result; // eax@4

  v1 = operator new(0x5Cu);
  v2 = v1;
  if ( v1 )
  {
    *(_DWORD *)v1 = 0;
    *((_DWORD *)v1 + 1) = 0;
    *((_DWORD *)v1 + 2) = 0;
    v3 = (int)((char *)v1 + 20);
    *((_DWORD *)v1 + 3) = &Position::vftable;
    *((_DWORD *)v1 + 4) = 0;
    *(_DWORD *)v3 = 1065353216;
    *(_DWORD *)(v3 + 4) = 0;
    *(_DWORD *)(v3 + 8) = 0;
    *(_DWORD *)(v3 + 12) = 0;
    *(_DWORD *)(v3 + 52) = 0;
    *(_DWORD *)(v3 + 56) = 0;
    *(_DWORD *)(v3 + 60) = 0;
    Frame::cache((Frame *)((char *)v1 + 20));
    *((_DWORD *)v2 + 21) = 0;
    *((_DWORD *)v2 + 22) = 0;
    if ( *(_DWORD *)v2 )
    {
      *((_DWORD *)v2 + 1) = 0;
      *((_DWORD *)v2 + 2) = 0;
      *(_DWORD *)v2 = 0;
    }
    *(_DWORD *)v2 = physobj;
    result = (ConstraintManager *)v2;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00556180) --------------------------------------------------------  // acclient.c:389477
void __thiscall ConstraintManager::adjust_offset(ConstraintManager *this, Frame *offset, long double quantum)
{
  ConstraintManager *v3; // esi@1
  char *v4; // eax@5
  float _rhs; // ST00_4@7

  v3 = this;
  if ( this->physics_obj && this->is_constrained )
  {
    if ( this->physics_obj->transient_state & 1 )
    {
      if ( this->constraint_pos_offset < (double)this->constraint_distance_max )
      {
        if ( this->constraint_pos_offset > (double)this->constraint_distance_start )
        {
          _rhs = (this->constraint_distance_max - this->constraint_pos_offset)
               / (this->constraint_distance_max - this->constraint_distance_start);
          Vector3::operator*=((Vector3 *)&offset->m_fOrigin.x, _rhs);
        }
      }
      else
      {
        v4 = (char *)&offset->m_fOrigin;
        *(_DWORD *)v4 = 0;
        *((_DWORD *)v4 + 1) = 0;
        *((_DWORD *)v4 + 2) = 0;
      }
    }
    v3->constraint_pos_offset = sqrt(offset->m_fOrigin.x * offset->m_fOrigin.x
                                   + offset->m_fOrigin.y * offset->m_fOrigin.y + offset->m_fOrigin.z
                                                                               * offset->m_fOrigin.z)
                              + v3->constraint_pos_offset;
  }
}

//----- (00556240) --------------------------------------------------------  // acclient.c:389513
void __thiscall ConstraintManager::ConstrainTo(ConstraintManager *this, Position *p, float start_distance, float max_distance)
{
  ConstraintManager *v4; // esi@1
  Position *v5; // ST00_4@1

  v4 = this;
  this->is_constrained = 1;
  this->constraint_pos.objcell_id = p->objcell_id;
  Frame::operator=((int)&this->constraint_pos.frame, (int)&p->frame);
  v5 = &v4->physics_obj->m_position;
  v4->constraint_distance_start = start_distance;
  v4->constraint_distance_max = max_distance;
  v4->constraint_pos_offset = Position::distance(p, v5);
}

//----- (00707120) --------------------------------------------------------  // acclient.c:794311
void sub_707120()
{
  flt_86FBA4 = 1000.0 + 1.0;
}

//----- (00707140) --------------------------------------------------------  // acclient.c:794317
void sub_707140()
{
  flt_86FBA8 = 24.0 * 8.0;
}

//----- (00707160) --------------------------------------------------------  // acclient.c:794323
void sub_707160()
{
  flt_86FBAC = 24.0 * 0.5;
}

//----- (00707180) --------------------------------------------------------  // acclient.c:794329
int _E101_36()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_39;
  dword_86FBB4 = LOWEST_DATA_RATE_39;
  return result;
}

//----- (00707190) --------------------------------------------------------  // acclient.c:794339
void sub_707190()
{
  flt_86FBB8 = 0.00019999999 * 3.0 + 0.1;
}

//----- (007071B0) --------------------------------------------------------  // acclient.c:794345
void _E105_46()
{
  dbl_86FBC0 = 1.0 / 30.0;
}

//----- (007071D0) --------------------------------------------------------  // acclient.c:794351
void _E107_35()
{
  dbl_86FBC8 = 1.0 / 5.0;
}

//----- (007071F0) --------------------------------------------------------  // acclient.c:794357
int sub_7071F0()
{
  return atexit(nullsub_1261);
}

