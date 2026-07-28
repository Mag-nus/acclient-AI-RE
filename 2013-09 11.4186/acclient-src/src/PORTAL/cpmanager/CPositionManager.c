/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPositionManager
   Object     : PORTAL\cpmanager\CPositionManager.obj
   Functions  : 18
   Addresses  : 00555160 - 00706F50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00555160) --------------------------------------------------------  // acclient.c:388266
void __thiscall PositionManager::UseTime(PositionManager *this)
{
  PositionManager *v1; // esi@1
  InterpolationManager *v2; // ecx@1
  DiskSpace *v3; // ecx@3
  StickyManager *v4; // ecx@5

  v1 = this;
  v2 = this->interpolation_manager;
  if ( v2 )
    InterpolationManager::UseTime(v2);
  v3 = (DiskSpace *)v1->constraint_manager;
  if ( v3 )
    gmNoticeHandler::RecvNotice_PrevSpellSelection(v3);
  v4 = v1->sticky_manager;
  if ( v4 )
    StickyManager::UseTime(v4);
}

//----- (00555190) --------------------------------------------------------  // acclient.c:388286
void __thiscall PositionManager::adjust_offset(PositionManager *this, Frame *offset, long double quantum)
{
  PositionManager *v3; // esi@1
  InterpolationManager *v4; // ecx@1
  StickyManager *v5; // ecx@3
  ConstraintManager *v6; // ecx@5

  v3 = this;
  v4 = this->interpolation_manager;
  if ( v4 )
    InterpolationManager::adjust_offset(v4, offset, quantum);
  v5 = v3->sticky_manager;
  if ( v5 )
    StickyManager::adjust_offset(v5, offset, quantum);
  v6 = v3->constraint_manager;
  if ( v6 )
    ConstraintManager::adjust_offset(v6, offset, quantum);
}

//----- (005551E0) --------------------------------------------------------  // acclient.c:388306
void __thiscall PositionManager::UnStick(PositionManager *this)
{
  StickyManager *v1; // ecx@1

  v1 = this->sticky_manager;
  if ( v1 )
    StickyManager::HandleExitWorld(v1);
}

//----- (005551F0) --------------------------------------------------------  // acclient.c:388316
void __thiscall PositionManager::InterpolateTo(PositionManager *this, Position *p, int keep_heading)
{
  InterpolationManager **v3; // esi@1
  InterpolationManager *v4; // eax@2

  v3 = (InterpolationManager **)this;
  if ( !this->interpolation_manager )
  {
    InterpolationManager::Create(this->physics_obj);
    *v3 = v4;
  }
  InterpolationManager::InterpolateTo(*v3, p, keep_heading);
}

//----- (00555220) --------------------------------------------------------  // acclient.c:388331
void __thiscall PositionManager::StopInterpolating(PositionManager *this)
{
  InterpolationManager *v1; // ecx@1

  v1 = this->interpolation_manager;
  if ( v1 )
    InterpolationManager::StopInterpolating(v1);
}

//----- (00555230) --------------------------------------------------------  // acclient.c:388341
void __thiscall PositionManager::StickTo(PositionManager *this, unsigned int object_id, float radius, float height)
{
  PositionManager *v4; // esi@1

  v4 = this;
  if ( !this->sticky_manager )
    this->sticky_manager = StickyManager::Create(this->physics_obj);
  StickyManager::StickTo(v4->sticky_manager, object_id, radius, height);
}

//----- (00555270) --------------------------------------------------------  // acclient.c:388352
unsigned int __thiscall PositionManager::GetStickyObjectID(PositionManager *this)
{
  StickyManager *v1; // ecx@1
  unsigned int result; // eax@2

  v1 = this->sticky_manager;
  if ( v1 )
    result = CommandList::GetHead((ChatDisplayInfo *)v1);
  else
    result = 0;
  return result;
}

//----- (00555280) --------------------------------------------------------  // acclient.c:388366
void __thiscall PositionManager::ConstrainTo(PositionManager *this, Position *p, float start_distance, float max_distance)
{
  PositionManager *v4; // esi@1
  ConstraintManager *v5; // ecx@3

  v4 = this;
  if ( !this->constraint_manager )
    this->constraint_manager = ConstraintManager::Create(this->physics_obj);
  v5 = v4->constraint_manager;
  if ( v5 )
    ConstraintManager::ConstrainTo(v5, p, start_distance, max_distance);
}

//----- (005552B0) --------------------------------------------------------  // acclient.c:388380
void __thiscall PositionManager::UnConstrain(PositionManager *this)
{
  ConstraintManager *v1; // ecx@1

  v1 = this->constraint_manager;
  if ( v1 )
    ConstraintManager::UnConstrain(v1);
}

//----- (005552C0) --------------------------------------------------------  // acclient.c:388390
int __thiscall PositionManager::IsFullyConstrained(PositionManager *this)
{
  ConstraintManager *v1; // ecx@1
  int result; // eax@2

  v1 = this->constraint_manager;
  if ( v1 )
    result = ConstraintManager::IsFullyConstrained(v1);
  else
    result = 0;
  return result;
}

//----- (005552D0) --------------------------------------------------------  // acclient.c:388404
PositionManager *__cdecl PositionManager::Create(CPhysicsObj *_physics_obj)
{
  void *v1; // eax@1
  void *v2; // esi@1
  InterpolationManager *v3; // ecx@2
  bool v4; // zf@2
  StickyManager *v5; // ecx@4
  ConstraintManager *v6; // ecx@6
  PositionManager *result; // eax@8

  v1 = operator new(0x10u);
  v2 = v1;
  if ( v1 )
  {
    *(_DWORD *)v1 = 0;
    *((_DWORD *)v1 + 1) = 0;
    *((_DWORD *)v1 + 2) = 0;
    *((_DWORD *)v1 + 3) = 0;
    v3 = *(InterpolationManager **)v1;
    v4 = *(_DWORD *)v1 == 0;
    *((_DWORD *)v1 + 3) = _physics_obj;
    if ( !v4 )
      QuickWindow::SetWindowID(v3, _physics_obj);
    v5 = (StickyManager *)*((_DWORD *)v2 + 1);
    if ( v5 )
      StickyManager::SetPhysicsObject(v5, _physics_obj);
    v6 = (ConstraintManager *)*((_DWORD *)v2 + 2);
    if ( v6 )
      ConstraintManager::SetPhysicsObject(v6, _physics_obj);
    result = (PositionManager *)v2;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00555340) --------------------------------------------------------  // acclient.c:388443
void __thiscall PositionManager::Destroy(PositionManager *this)
{
  PositionManager *v1; // esi@1
  InterpolationManager *v2; // edi@1
  StickyManager *v3; // edi@3
  ConstraintManager *v4; // edi@5

  v1 = this;
  v2 = this->interpolation_manager;
  if ( this->interpolation_manager )
  {
    InterpolationManager::~InterpolationManager(this->interpolation_manager);
    operator delete(v2);
  }
  v3 = v1->sticky_manager;
  v1->interpolation_manager = 0;
  if ( v3 )
  {
    StickyManager::~StickyManager(v3);
    operator delete(v3);
  }
  v4 = v1->constraint_manager;
  v1->sticky_manager = 0;
  if ( v4 )
  {
    ConstraintManager::~ConstraintManager(v4);
    operator delete(v4);
  }
  v1->constraint_manager = 0;
}

//----- (005553B0) --------------------------------------------------------  // acclient.c:388475
int __thiscall PositionManager::IsInterpolating(PositionManager *this)
{
  int result; // eax@2

  if ( this->interpolation_manager )
    result = this->interpolation_manager->position_queue.head_ != 0;
  else
    result = 0;
  return result;
}

//----- (005553D0) --------------------------------------------------------  // acclient.c:388487
void __thiscall PositionManager::HandleUpdateTarget(PositionManager *this, TargetInfo target_info)
{
  PositionManager *v2; // esi@1
  TargetInfo v3; // [sp-D0h] [bp-D4h]@2

  v2 = this;
  if ( this->sticky_manager )
  {
    TargetInfo::TargetInfo(&v3, &target_info);
    StickyManager::HandleUpdateTarget(v2->sticky_manager, v3);
  }
}

//----- (00706EF0) --------------------------------------------------------  // acclient.c:794183
void sub_706EF0()
{
  flt_86FAE8 = 1000.0 + 1.0;
}

//----- (00706F10) --------------------------------------------------------  // acclient.c:794189
void sub_706F10()
{
  flt_86FAEC = 24.0 * 8.0;
}

//----- (00706F30) --------------------------------------------------------  // acclient.c:794195
void sub_706F30()
{
  flt_86FAF0 = 24.0 * 0.5;
}

//----- (00706F50) --------------------------------------------------------  // acclient.c:794201
int sub_706F50()
{
  return atexit(nullsub_1258);
}

