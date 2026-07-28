/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CameraManager
   Object     : PORTAL\smartbox\CameraManager.obj
   Functions  : 60
   Addresses  : 00455D70 - 0075D020 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00455D70) --------------------------------------------------------  // acclient.c:146856
BOOL __cdecl Frame::close_rotation(Frame *f1, Frame *f2, const float epsilon)
{
  return epsilon > fabs(f1->qw - f2->qw)
      && epsilon > fabs(f1->qx - f2->qx)
      && epsilon > fabs(f1->qy - f2->qy)
      && epsilon > fabs(f1->qz - f2->qz);
}

//----- (00455DE0) --------------------------------------------------------  // acclient.c:146865
Vector3 *__thiscall Vector3::operator/(Vector3 *this, Vector3 *result, const float _rhs)
{
  Vector3 *v3; // eax@1
  double v4; // st7@1
  double v5; // st6@1
  double v6; // st5@1
  double v7; // st7@1
  const float _rhsa; // [sp+8h] [bp+8h]@1

  v3 = result;
  v4 = 1.0 / _rhs;
  _rhsa = v4;
  v5 = _rhsa * this->y;
  v6 = v4 * this->x;
  v7 = _rhsa * this->z;
  result->x = v6;
  result->y = v5;
  result->z = v7;
  return v3;
}

//----- (00455E10) --------------------------------------------------------  // acclient.c:146887
Vector3 *__cdecl operator*(Vector3 *result, const float _f, Vector3 *_V)
{
  double v3; // st6@1
  Vector3 *v4; // eax@1
  double v5; // st7@1

  v3 = _f * _V->y;
  v4 = result;
  v5 = _f * _V->z;
  result->x = _f * _V->x;
  result->y = v3;
  result->z = v5;
  return v4;
}

//----- (00455E40) --------------------------------------------------------  // acclient.c:146903
void __thiscall CameraSet::ToggleLookDown(CameraSet *this)
{
  CameraSet::LookDown(this, this->looking_down == 0);
}

//----- (00455E60) --------------------------------------------------------  // acclient.c:146909
void __thiscall CameraSet::ToggleMapMode(CameraSet *this)
{
  CameraSet::SetMapMode(this, this->in_map_mode == 0);
}

//----- (00455E80) --------------------------------------------------------  // acclient.c:146915
void __thiscall CameraManager::ClearTarget(CameraManager *this)
{
  this->target_status = 0;
}

//----- (00455E90) --------------------------------------------------------  // acclient.c:146921
void __thiscall CameraManager::SetTarget(CameraManager *this, CameraTarget target)
{
  this->target_status |= target;
}

//----- (00455EA0) --------------------------------------------------------  // acclient.c:146927
void __thiscall CameraManager::SetPivotObject(CameraManager *this, unsigned int object_id, int part_index)
{
  this->pivot_object_id = object_id;
  this->pivot_part_index = part_index;
}

//----- (00455EC0) --------------------------------------------------------  // acclient.c:146934
int __thiscall CameraManager::SetTranslationalStiffness(CameraManager *this, float stiffness)
{
  int result; // eax@3

  if ( stiffness < 0.0 || stiffness > 1.0 )
  {
    result = 0;
  }
  else
  {
    this->t_stiffness = stiffness;
    result = 1;
  }
  return result;
}

//----- (00455F00) --------------------------------------------------------  // acclient.c:146951
int __thiscall CameraManager::SetRotationalStiffness(CameraManager *this, float stiffness)
{
  int result; // eax@3

  if ( stiffness < 0.0 || stiffness > 1.0 )
  {
    result = 0;
  }
  else
  {
    this->r_stiffness = stiffness;
    result = 1;
  }
  return result;
}

//----- (00455F40) --------------------------------------------------------  // acclient.c:146968
bool __userpurge CameraManager::OnAction@<al>(CameraManager *this@<ecx>, int a2@<ebp>, InputEvent *i_evt)
{
  CameraManager *v3; // esi@1
  CameraSet *v4; // ecx@2
  bool result; // al@4
  CameraSet *v6; // ecx@5
  CameraSet *v7; // ecx@8
  CameraSet *v8; // ecx@11
  CameraSet *v9; // ecx@14
  CameraSet *v10; // ecx@19
  CameraSet *v11; // ecx@24
  bool v12; // al@25
  CameraSet *v13; // ecx@29
  CameraSet *v14; // ecx@34
  ICIDMVtbl *v15; // edx@40
  CameraSet *v16; // ecx@43

  v3 = this;
  switch ( i_evt->m_InputAction )
  {
    case 0x39u:
      v4 = *(CameraSet **)&this->m_bEnabled;
      if ( v4 )
        CameraSet::SetDefaultOffsets(v4, 1);
      return 1;
    case 0x3Au:
      v6 = *(CameraSet **)&this->m_bEnabled;
      if ( v6 )
        CameraSet::SetInHead(v6);
      return 1;
    case 0x3Bu:
      v7 = *(CameraSet **)&this->m_bEnabled;
      if ( v7 )
        CameraSet::ToggleLookDown(v7);
      return 1;
    case 0x3Cu:
      v8 = *(CameraSet **)&this->m_bEnabled;
      if ( v8 )
        CameraSet::ToggleMapMode(v8);
      return 1;
    case 0x33u:
      v9 = *(CameraSet **)&this->m_bEnabled;
      if ( !v9 )
        goto LABEL_18;
      if ( i_evt->m_fStart )
      {
        CameraSet::Closer(v9, 1, 1.0);
        result = 1;
      }
      else
      {
        CameraSet::StopCloser(v9);
LABEL_18:
        result = 1;
      }
      return result;
    case 0x34u:
      v10 = *(CameraSet **)&this->m_bEnabled;
      if ( !v10 )
        goto LABEL_23;
      if ( i_evt->m_fStart )
      {
        CameraSet::Farther(v10, 1, 1.0);
        result = 1;
      }
      else
      {
        CameraSet::StopFarther(v10);
LABEL_23:
        result = 1;
      }
      return result;
    case 0x35u:
    case 0x36u:
      v11 = *(CameraSet **)&this->m_bEnabled;
      if ( !v11 )
        goto LABEL_28;
      v12 = i_evt->m_InputAction == 53;
      if ( i_evt->m_fStart )
      {
        CameraSet::Rotate(v11, v12, 1, 1.0, 1);
        result = 1;
      }
      else
      {
        CameraSet::StopRotating(v11, v12);
LABEL_28:
        result = 1;
      }
      return result;
    case 0x38u:
      v13 = *(CameraSet **)&this->m_bEnabled;
      if ( !v13 )
        goto LABEL_33;
      if ( i_evt->m_fStart )
      {
        CameraSet::Lower(v13, 1, 1.0);
        result = 1;
      }
      else
      {
        CameraSet::StopLowering(v13);
LABEL_33:
        result = 1;
      }
      return result;
    case 0x37u:
      v14 = *(CameraSet **)&this->m_bEnabled;
      if ( !v14 )
        goto LABEL_38;
      if ( i_evt->m_fStart )
      {
        CameraSet::Raise(v14, 1, 1.0);
        result = 1;
      }
      else
      {
        CameraSet::StopRaising(v14);
LABEL_38:
        result = 1;
      }
      break;
    case 0x3Eu:
      if ( ICIDM::s_cidm )
      {
        v15 = ICIDM::s_cidm->vfptr;
        if ( i_evt->m_fStart )
          ((void (__stdcall *)(signed int, unsigned int, signed int))v15->RegisterInputMap)(
            6,
            this != (CameraManager *)4 ? (unsigned int)this : 0,
            2000);
        else
          ((void (__stdcall *)(signed int, unsigned int))v15->UnregisterInputMap)(
            6,
            this != (CameraManager *)4 ? (unsigned int)this : 0);
      }
      goto $L118621;
    case 0x3Du:
$L118621:
      v16 = *(CameraSet **)&v3->m_bEnabled;
      if ( v16 )
        CameraSet::ToggleMouseLook(v16, a2, i_evt->m_fStart);
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (00456140) --------------------------------------------------------  // acclient.c:147120
void __thiscall CameraManager::MouseLookHandler(CameraManager *this, int i_nXMove, int i_nYMove)
{
  CameraSet *v3; // ecx@1

  v3 = this->m_pCurrentCameraSet;
  if ( v3 )
    CameraSet::MouseLookHandler(v3, i_nXMove, i_nYMove);
}

//----- (00456160) --------------------------------------------------------  // acclient.c:147130
void __userpurge CameraManager::ToggleMouseLook(CameraManager *this@<ecx>, int a2@<ebp>, int camera_on)
{
  CameraSet *v3; // ecx@1

  v3 = this->m_pCurrentCameraSet;
  if ( v3 )
    CameraSet::ToggleMouseLook(v3, a2, camera_on);
}

//----- (00456180) --------------------------------------------------------  // acclient.c:147140
AC1Legacy::Vector3 *__thiscall Position::localtoglobal(Position *this, AC1Legacy::Vector3 *result, Position *p, AC1Legacy::Vector3 *v)
{
  float v4; // ST0C_4@1
  float v5; // ST10_4@1
  float v6; // ST14_4@1
  AC1Legacy::Vector3 *v7; // eax@1
  double v8; // st6@1
  double v9; // st7@1
  AC1Legacy::Vector3 v10; // [sp+Ch] [bp-Ch]@1

  v4 = p->frame.m_fl2gv[3] * v->y + p->frame.m_fl2gv[0] * v->x + p->frame.m_fl2gv[6] * v->z + p->frame.m_fOrigin.x;
  v5 = p->frame.m_fl2gv[4] * v->y + p->frame.m_fl2gv[1] * v->x + p->frame.m_fl2gv[7] * v->z + p->frame.m_fOrigin.y;
  v6 = p->frame.m_fl2gv[5] * v->y + p->frame.m_fl2gv[2] * v->x + p->frame.m_fl2gv[8] * v->z + p->frame.m_fOrigin.z;
  LandDefs::get_block_offset(&v10, this->objcell_id, p->objcell_id);
  v7 = result;
  v8 = v10.y + v5;
  v9 = v10.z + v6;
  result->x = v10.x + v4;
  result->y = v8;
  result->z = v9;
  return v7;
}

//----- (00456220) --------------------------------------------------------  // acclient.c:147164
AC1Legacy::Vector3 *__thiscall Position::localtoglobalvec(Position *this, AC1Legacy::Vector3 *result, AC1Legacy::Vector3 *v)
{
  double v3; // st7@1
  double v4; // st6@1
  AC1Legacy::Vector3 *v5; // eax@1

  v3 = this->frame.m_fl2gv[5] * v->y + this->frame.m_fl2gv[2] * v->x + this->frame.m_fl2gv[8] * v->z;
  v4 = this->frame.m_fl2gv[4] * v->y + this->frame.m_fl2gv[1] * v->x + this->frame.m_fl2gv[7] * v->z;
  v5 = result;
  result->x = this->frame.m_fl2gv[3] * v->y + this->frame.m_fl2gv[0] * v->x + this->frame.m_fl2gv[6] * v->z;
  result->y = v4;
  result->z = v3;
  return v5;
}

//----- (00456280) --------------------------------------------------------  // acclient.c:147180
void __thiscall CameraManager::~CameraManager(CameraManager *this)
{
  CameraManager *v1; // esi@1
  int v2; // edi@1

  v1 = this;
  v2 = *(_DWORD *)&this->m_bEnabled;
  this[-1].m_pCurrentCameraSet = (CameraSet *)&CameraManager::vftable;
  this->vfptr = (CInputHandlerVtbl *)&CameraManager::vftable;
  if ( v2 )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v2 + 4)) && v2 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
    *(_DWORD *)&v1->m_bEnabled = 0;
  }
  UserPreferences::UnregisterPreference(&Camera_AlignToSlope_0);
  UserPreferences::UnregisterPreference(&Camera_Stiffness_0);
  UserPreferences::UnregisterPreference(&Camera_AdjustmentSpeed_0);
  *(_DWORD *)(v1 != (CameraManager *)4 ? (unsigned int)v1 : 0) = &IInputActionCallback::vftable;
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(unsigned int))ICIDM::s_cidm->vfptr->UnregisterCallback)(v1 != (CameraManager *)4 ? (unsigned int)v1 : 0);
}
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 79BAA0: using guessed type int (__stdcall *CameraManager::vftable)(char);
// 79BAAC: using guessed type void (__thiscall *CameraManager::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00456310) --------------------------------------------------------  // acclient.c:147207
void __thiscall CameraManager::SetCameraSet(CameraManager *this, CameraSet *pCameraSet)
{
  CameraManager *v2; // esi@1
  CameraSet *v3; // edi@1
  CameraSet *v4; // ecx@7

  v2 = this;
  v3 = this->m_pCurrentCameraSet;
  if ( v3 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
      v3->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 1u);
    v2->m_pCurrentCameraSet = 0;
  }
  v2->m_pCurrentCameraSet = pCameraSet;
  if ( pCameraSet )
  {
    InterlockedIncrement((volatile LONG *)&pCameraSet->m_cRef);
    v4 = v2->m_pCurrentCameraSet;
    if ( v4 )
      CameraSet::SetStiffness(v4, v2->m_rCameraStiffness);
  }
}

//----- (00456380) --------------------------------------------------------  // acclient.c:147232
void __thiscall CameraManager::SetTargetObject(CameraManager *this, unsigned int object_id, int part_index)
{
  this->target_object_id = object_id;
  this->target_part_index = part_index;
  this->target_status = 2;
}

//----- (004563A0) --------------------------------------------------------  // acclient.c:147240
void __thiscall CameraManager::SetTargetDirection(CameraManager *this, AC1Legacy::Vector3 *dir)
{
  float v2; // edx@1
  CameraManager *v3; // esi@1
  float v4; // eax@1
  float v5; // edx@2
  float v6; // eax@2
  int v7; // esi@2
  AC1Legacy::Vector3 new_dir; // [sp+4h] [bp-Ch]@1

  v2 = dir->y;
  v3 = this;
  v4 = dir->z;
  new_dir.x = dir->x;
  new_dir.y = v2;
  new_dir.z = v4;
  if ( !AC1Legacy::Vector3::normalize_check_small(&new_dir) )
  {
    v5 = new_dir.y;
    v6 = new_dir.z;
    v7 = (int)&v3->direction;
    *(_DWORD *)v7 = (_DWORD)new_dir.x;
    *(float *)(v7 + 4) = v5;
    *(float *)(v7 + 8) = v6;
  }
}

//----- (004563F0) --------------------------------------------------------  // acclient.c:147268
AC1Legacy::Vector3 *__thiscall CameraManager::FlagsToVector(CameraManager *this, AC1Legacy::Vector3 *result, unsigned int flags)
{
  double v3; // st7@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@5
  unsigned int v6; // eax@9
  AC1Legacy::Vector3 *v7; // eax@13
  float viewDelta; // [sp+0h] [bp-Ch]@1
  float viewDelta_4; // [sp+4h] [bp-8h]@1

  v3 = 0.0;
  v4 = flags & 3;
  viewDelta = 0.0;
  viewDelta_4 = 0.0;
  if ( v4 == 2 )
  {
    viewDelta = this->m_rMovementSpeed;
  }
  else if ( v4 == 1 )
  {
    viewDelta = -this->m_rMovementSpeed;
  }
  v5 = flags & 0xC;
  if ( v5 == 4 )
  {
    viewDelta_4 = this->m_rMovementSpeed;
  }
  else if ( v5 == 8 )
  {
    viewDelta_4 = -this->m_rMovementSpeed;
  }
  v6 = flags & 0x30;
  if ( v6 == 16 )
  {
    v3 = this->m_rMovementSpeed;
  }
  else if ( v6 == 32 )
  {
    v3 = -this->m_rMovementSpeed;
  }
  v7 = result;
  result->x = viewDelta;
  result->y = viewDelta_4;
  result->z = v3;
  return v7;
}

//----- (00456490) --------------------------------------------------------  // acclient.c:147316
void __cdecl CameraManager::OnStiffnessChanged()
{
  CameraManager *v0; // eax@2
  CameraSet *v1; // ecx@3

  if ( SmartBox::smartbox )
  {
    v0 = SmartBox::smartbox->camera_manager;
    if ( v0 )
    {
      v1 = v0->m_pCurrentCameraSet;
      if ( v1 )
        CameraSet::SetStiffness(v1, v0->m_rCameraStiffness);
    }
  }
}

//----- (004564C0) --------------------------------------------------------  // acclient.c:147334
int __thiscall CameraManager::scalar_deleting_destructor(CameraManager *this, char a2)
{
  CameraManager *v2; // esi@1
  int result; // eax@1

  v2 = this;
  CameraManager::~CameraManager(this);
  result = (int)&v2[-1].m_pCurrentCameraSet;
  if ( a2 & 1 )
  {
    operator delete(&v2[-1].m_pCurrentCameraSet);
    result = (int)&v2[-1].m_pCurrentCameraSet;
  }
  return result;
}

//----- (004564F0) --------------------------------------------------------  // acclient.c:147351
int __thiscall CameraManager::QueryPivotPosition(CameraManager *this, Position *pivot_position)
{
  CameraManager *v2; // esi@1
  HashBaseData<unsigned long> *v3; // eax@1
  int v4; // ecx@2
  HashBaseData<unsigned long> *v5; // edx@3
  int v6; // ecx@4
  AC1Legacy::Vector3 *v7; // eax@5
  char *v8; // edi@5
  char *v10; // edi@6
  float v11; // edx@6
  double v12; // st7@6
  AC1Legacy::Vector3 result; // [sp+Ch] [bp-54h]@5
  int (__thiscall **v14)(void *, char); // [sp+18h] [bp-48h]@1
  int v15; // [sp+1Ch] [bp-44h]@1
  Frame v16; // [sp+20h] [bp-40h]@1

  v2 = this;
  v14 = &Position::vftable;
  v15 = 0;
  LODWORD(v16.qw) = 1065353216;
  LODWORD(v16.qx) = 0;
  LODWORD(v16.qy) = 0;
  LODWORD(v16.qz) = 0;
  LODWORD(v16.m_fOrigin.x) = 0;
  LODWORD(v16.m_fOrigin.y) = 0;
  LODWORD(v16.m_fOrigin.z) = 0;
  Frame::cache(&v16);
  pivot_position->objcell_id = 0;
  Frame::operator=((int)&pivot_position->frame, (int)&v16);
  v3 = CPhysicsObj::GetObjectA(v2->pivot_object_id);
  if ( v3 )
  {
    pivot_position->objcell_id = (unsigned int)v3[6].hash_next;
    v4 = v2->pivot_part_index;
    if ( v4 == -1 || (v5 = v3[1].hash_next, v4 >= (signed int)v5[7].hash_next) )
    {
      v10 = (char *)&pivot_position->frame.m_fOrigin;
      result.x = *(float *)&v3[9].vfptr * v2->pivot_offset.y
               + *(float *)&v3[8].vfptr * v2->pivot_offset.x
               + *(float *)&v3[10].vfptr * v2->pivot_offset.z
               + *(float *)&v3[11].vfptr;
      result.y = *(float *)&v3[9].hash_next * v2->pivot_offset.y
               + *(float *)&v3[8].hash_next * v2->pivot_offset.x
               + *(float *)&v3[10].hash_next * v2->pivot_offset.z
               + *(float *)&v3[11].hash_next;
      v11 = result.y;
      v12 = *(float *)&v3[9].id * v2->pivot_offset.y
          + *(float *)&v3[8].id * v2->pivot_offset.x
          + *(float *)&v3[10].id * v2->pivot_offset.z
          + *(float *)&v3[11].id;
      *(_DWORD *)v10 = (_DWORD)result.x;
      *((float *)v10 + 1) = v11;
      result.z = v12;
      *((_DWORD *)v10 + 2) = LODWORD(result.z);
      return 1;
    }
    v6 = *(_DWORD *)(v5[7].id + 4 * v4);
    if ( v6 )
    {
      v7 = Frame::localtoglobal((Frame *)(v6 + 56), &result, &v2->pivot_offset);
      v8 = (char *)&pivot_position->frame.m_fOrigin;
      *(_DWORD *)v8 = LODWORD(v7->x);
      *((_DWORD *)v8 + 1) = LODWORD(v7->y);
      *((_DWORD *)v8 + 2) = LODWORD(v7->z);
      return 1;
    }
  }
  return 0;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00456660) --------------------------------------------------------  // acclient.c:147424
Position *__thiscall CameraManager::UpdateCamera(CameraManager *this, Position *result, Position *viewer_pos)
{
  CameraManager *v3; // esi@1
  long double v5; // st7@3
  ICMDCommandEnum v6; // edx@3
  unsigned int v7; // eax@3
  HashBaseData<unsigned long> *v8; // ebp@7
  Position *v9; // ebx@9
  AC1Legacy::Vector3 *v10; // eax@9
  float v11; // ecx@9
  float v12; // edx@9
  bool v13; // zf@9
  HashBaseData<unsigned long> *v14; // eax@10
  int v15; // ecx@11
  HashBaseData<unsigned long> *v16; // edx@12
  AC1Legacy::Vector3 *v17; // eax@13
  float v18; // ecx@15
  float v19; // edx@15
  float v20; // eax@15
  double v21; // st7@19
  int v22; // eax@19
  int v23; // ecx@19
  float v24; // edx@19
  double v25; // st7@19
  double v26; // st6@19
  double v27; // st5@19
  int v28; // ecx@19
  float v29; // edx@19
  double v30; // st7@19
  double v31; // st6@19
  int v32; // eax@19
  double v33; // st5@19
  float v34; // edx@19
  double v35; // st7@19
  double v36; // st6@19
  float v37; // edx@19
  double v38; // st7@19
  signed int v39; // eax@19
  double v40; // st6@21
  float v41; // edx@21
  double v42; // st6@21
  float v43; // eax@21
  float v44; // ecx@25
  float v45; // edx@25
  float _f; // ST04_4@29
  Vector3 *v47; // eax@29
  double v48; // st7@29
  double v49; // st6@29
  char v50; // al@29
  double v51; // st7@34
  AC1Legacy::Vector3 *v52; // eax@38
  AC1Legacy::Vector3 *v53; // eax@39
  float v54; // ecx@41
  float v55; // edx@41
  float v56; // eax@41
  AC1Legacy::Vector3 *v57; // eax@31
  AC1Legacy::Vector3 *v58; // eax@46
  AC1Legacy::Vector3 *v59; // eax@50
  signed int v60; // edi@52
  long double v61; // st6@53
  signed int v62; // ebp@56
  long double v63; // st7@57
  double v64; // st7@60
  Position *v65; // esi@64
  unsigned int v66; // ecx@64
  char *v67; // [sp+8h] [bp-1D0h]@64
  AC1Legacy::Vector3 target_direction; // [sp+18h] [bp-1C0h]@9
  AC1Legacy::Vector3 local_dir; // [sp+24h] [bp-1B4h]@21
  AC1Legacy::Vector3 normal; // [sp+30h] [bp-1A8h]@19
  AC1Legacy::Vector3 velocity_direction; // [sp+3Ch] [bp-19Ch]@15
  AC1Legacy::Vector3 delta; // [sp+48h] [bp-190h]@4
  AC1Legacy::Vector3 look_direction; // [sp+54h] [bp-184h]@9
  long double quantum; // [sp+60h] [bp-178h]@3
  AC1Legacy::Vector3 plane_direction; // [sp+68h] [bp-170h]@15
  AC1Legacy::Vector3 pivot_direction; // [sp+74h] [bp-164h]@37
  Position actual_pos; // [sp+80h] [bp-158h]@59
  Position pivot_position; // [sp+C8h] [bp-110h]@8
  Frame camera_frame; // [sp+110h] [bp-C8h]@39
  Frame plane_frame; // [sp+150h] [bp-88h]@13
  Frame pivot_frame; // [sp+198h] [bp-40h]@39

  v3 = this;
  if ( !this->m_bEnabled )
  {
    result->vfptr = (PackObjVtbl *)&Position::vftable;
    result->objcell_id = viewer_pos->objcell_id;
    Frame::operator=((int)&result->frame, (int)&viewer_pos->frame);
    return result;
  }
  v5 = COERCE_DOUBLE(Timer::cur_time.Cmd) - this->last_update_time;
  v6 = (signed int)Timer::cur_time.Cmd;
  HIDWORD(this->last_update_time) = Timer::cur_time.Param;
  v7 = this->m_dwCameraOffsetMovement;
  quantum = v5;
  LODWORD(this->last_update_time) = v6;
  if ( v7 )
  {
    CameraManager::FlagsToVector(this, &delta, v7);
    delta.y = delta.y * quantum;
    delta.z = delta.z * quantum;
    v3->viewer_offset.x = delta.x * quantum + v3->viewer_offset.x;
    v3->viewer_offset.y = delta.y + v3->viewer_offset.y;
    v3->viewer_offset.z = delta.z + v3->viewer_offset.z;
  }
  if ( v3->m_dwPivotOffsetMovement )
  {
    CameraManager::FlagsToVector(v3, &delta, v3->m_dwPivotOffsetMovement);
    delta.y = delta.y * quantum;
    delta.z = delta.z * quantum;
    v3->pivot_offset.x = delta.x * quantum + v3->pivot_offset.x;
    v3->pivot_offset.y = delta.y + v3->pivot_offset.y;
    v3->pivot_offset.z = delta.z + v3->pivot_offset.z;
  }
  v8 = CPhysicsObj::GetObjectA(v3->pivot_object_id);
  if ( !v8
    || (pivot_position.vfptr = (PackObjVtbl *)&Position::vftable,
        pivot_position.objcell_id = 0,
        LODWORD(pivot_position.frame.qw) = 1065353216,
        LODWORD(pivot_position.frame.qx) = 0,
        LODWORD(pivot_position.frame.qy) = 0,
        LODWORD(pivot_position.frame.qz) = 0,
        LODWORD(pivot_position.frame.m_fOrigin.x) = 0,
        LODWORD(pivot_position.frame.m_fOrigin.y) = 0,
        LODWORD(pivot_position.frame.m_fOrigin.z) = 0,
        Frame::cache(&pivot_position.frame),
        !CameraManager::QueryPivotPosition(v3, &pivot_position)) )
  {
    v65 = result;
    result->vfptr = (PackObjVtbl *)&Position::vftable;
    v66 = viewer_pos->objcell_id;
    v67 = (char *)&viewer_pos->frame;
    goto LABEL_66;
  }
  v9 = viewer_pos;
  v10 = Position::localtoglobal(viewer_pos, &look_direction, &pivot_position);
  v11 = v10->y;
  delta.x = v10->x;
  v12 = v10->z;
  v13 = (v3->target_status & 2) == 0;
  delta.y = v11;
  delta.z = v12;
  LODWORD(target_direction.x) = 0;
  LODWORD(target_direction.y) = 0;
  LODWORD(target_direction.z) = 0;
  if ( !v13 )
  {
    v14 = CPhysicsObj::GetObjectA(v3->target_object_id);
    if ( v14 )
    {
      v15 = v3->target_part_index;
      if ( v15 == -1 || (v16 = v14[1].hash_next, v15 >= (signed int)v16[7].hash_next) )
      {
        v17 = Position::localtoglobal(viewer_pos, &look_direction, (Position *)&v14[6], &v3->target_offset);
      }
      else
      {
        Position::Position(
          (Position *)&plane_frame,
          (unsigned int)v14[6].hash_next,
          (Frame *)(*(_DWORD *)(v16[7].id + 4 * v15) + 56));
        v17 = Position::localtoglobal(viewer_pos, &look_direction, (Position *)&plane_frame, &v3->target_offset);
      }
      v18 = v17->x;
      v19 = v17->y;
      v20 = v17->z;
      velocity_direction.x = v18;
      velocity_direction.y = v19;
      velocity_direction.z = v20;
      plane_direction.x = v18 - delta.x;
      plane_direction.y = v19 - delta.y;
      plane_direction.z = v20 - delta.z;
      if ( !AC1Legacy::Vector3::normalize_check_small(&plane_direction) )
      {
        target_direction.x = plane_direction.x + target_direction.x;
        target_direction.y = plane_direction.y + target_direction.y;
        target_direction.z = plane_direction.z + target_direction.z;
      }
    }
  }
  if ( v3->m_bAlignCameraToSlope && v3->target_status & 0x10 )
  {
    CPhysicsObj::get_velocity((CPhysicsObj *)v8, &velocity_direction);
    v21 = velocity_direction.x;
    v22 = (int)&v3->old_velocities[1];
    v23 = (int)v3->old_velocities;
    *(_DWORD *)v23 = LODWORD(v3->old_velocities[1].x);
    v24 = v3->old_velocities[1].z;
    *(_DWORD *)(v23 + 4) = LODWORD(v3->old_velocities[1].y);
    *(float *)(v23 + 8) = v24;
    v25 = v21 + v3->old_velocities[0].x;
    v26 = velocity_direction.y + v3->old_velocities[0].y;
    v27 = velocity_direction.z + v3->old_velocities[0].z;
    v28 = (int)&v3->old_velocities[2];
    *(_DWORD *)v22 = LODWORD(v3->old_velocities[2].x);
    normal.z = v27;
    v29 = v3->old_velocities[2].z;
    *(_DWORD *)(v22 + 4) = LODWORD(v3->old_velocities[2].y);
    *(float *)(v22 + 8) = v29;
    normal.x = v25 + v3->old_velocities[1].x;
    v30 = v26 + v3->old_velocities[1].y;
    v31 = normal.z + v3->old_velocities[1].z;
    v32 = (int)&v3->old_velocities[3];
    v33 = normal.x;
    *(_DWORD *)v28 = LODWORD(v3->old_velocities[3].x);
    v34 = v3->old_velocities[3].z;
    *(_DWORD *)(v28 + 4) = LODWORD(v3->old_velocities[3].y);
    *(float *)(v28 + 8) = v34;
    normal.x = v33 + v3->old_velocities[2].x;
    normal.y = v30 + v3->old_velocities[2].y;
    v35 = v31 + v3->old_velocities[2].z;
    v36 = normal.x;
    *(_DWORD *)v32 = LODWORD(v3->old_velocities[4].x);
    v37 = v3->old_velocities[4].z;
    *(_DWORD *)(v32 + 4) = LODWORD(v3->old_velocities[4].y);
    *(float *)(v32 + 8) = v37;
    normal.x = v36 + v3->old_velocities[3].x;
    normal.y = normal.y + v3->old_velocities[3].y;
    v38 = v35 + v3->old_velocities[3].z;
    v39 = v3->old_velocity_num;
    if ( v39 < 5 )
      v3->old_velocity_num = v39 + 1;
    v40 = (double)v3->old_velocity_num;
    v41 = velocity_direction.y;
    LODWORD(v3->old_velocities[4].x) = (_DWORD)velocity_direction.x;
    v42 = 1.0 / v40;
    v43 = velocity_direction.z;
    v3->old_velocities[4].y = v41;
    v3->old_velocities[4].z = v43;
    look_direction.z = v38 * v42;
    local_dir.z = look_direction.z;
    local_dir.x = normal.x * v42;
    velocity_direction.z = look_direction.z;
    local_dir.y = normal.y * v42;
    LODWORD(velocity_direction.x) = (_DWORD)local_dir.x;
    velocity_direction.y = local_dir.y;
    if ( AC1Legacy::Vector3::normalize_check_small(&velocity_direction)
      || fabs(velocity_direction.x) < 0.00019999999
      || fabs(velocity_direction.y) < 0.00019999999 )
    {
      if ( !(v3->target_status & 1) )
        goto LABEL_36;
      v57 = Position::localtoglobalvec((Position *)&v8[6], &look_direction, &v3->direction);
    }
    else
    {
      if ( (unsigned int)v8[14].hash_next & 1 )
      {
        v44 = *(float *)&v8[25].id;
        v45 = *(float *)&v8[26].vfptr;
        LODWORD(normal.x) = v8[25].hash_next;
        normal.y = v44;
        normal.z = v45;
      }
      else
      {
        velocity_direction.z = velocity_direction.z * 0.1;
        if ( AC1Legacy::Vector3::normalize_check_small(&velocity_direction) )
        {
          LODWORD(local_dir.x) = 0;
          LODWORD(local_dir.y) = 0;
          LODWORD(local_dir.z) = 1065353216;
          LODWORD(normal.x) = 0;
          LODWORD(normal.y) = 0;
          LODWORD(normal.z) = 1065353216;
        }
        else
        {
          Frame::Frame(&plane_frame);
          Frame::set_vector_heading(&plane_frame, &velocity_direction);
          local_dir = *(AC1Legacy::Vector3 *)&plane_frame.m_fl2gv[6];
          normal = *(AC1Legacy::Vector3 *)&plane_frame.m_fl2gv[6];
        }
      }
      LODWORD(look_direction.x) = 0;
      LODWORD(look_direction.y) = 1065353216;
      LODWORD(look_direction.z) = 0;
      Position::localtoglobalvec((Position *)&v8[6], &local_dir, &look_direction);
      _f = local_dir.x * normal.x + normal.z * local_dir.z + normal.y * local_dir.y;
      v47 = operator*((Vector3 *)&look_direction.x, _f, (Vector3 *)&normal.x);
      v48 = v47->x;
      v49 = v47->y;
      look_direction.z = v47->z;
      plane_direction.x = local_dir.x - v48;
      plane_direction.y = local_dir.y - v49;
      plane_direction.z = local_dir.z - look_direction.z;
      v13 = AC1Legacy::Vector3::normalize_check_small(&plane_direction) == 0;
      v50 = LOBYTE(v3->target_status);
      if ( v13 )
      {
        if ( !(v50 & 1) )
        {
          target_direction.x = plane_direction.x + target_direction.x;
          target_direction.y = plane_direction.y + target_direction.y;
          v51 = plane_direction.z + target_direction.z;
LABEL_35:
          target_direction.z = v51;
          goto LABEL_36;
        }
        Frame::Frame(&plane_frame);
        Frame::set_vector_heading(&plane_frame, &plane_direction);
        v57 = Frame::localtoglobalvec(&plane_frame, &look_direction, &v3->direction);
      }
      else
      {
        if ( !(v50 & 1) )
        {
LABEL_36:
          v9 = viewer_pos;
          goto LABEL_37;
        }
        v57 = Position::localtoglobalvec((Position *)&v8[6], &look_direction, &v3->direction);
      }
    }
    target_direction.x = target_direction.x + v57->x;
    target_direction.y = target_direction.y + v57->y;
    v51 = target_direction.z + v57->z;
    goto LABEL_35;
  }
  if ( v3->target_status & 1 )
  {
    v58 = Position::localtoglobalvec((Position *)&v8[6], &look_direction, &v3->direction);
    target_direction.x = target_direction.x + v58->x;
    target_direction.y = target_direction.y + v58->y;
    target_direction.z = target_direction.z + v58->z;
  }
LABEL_37:
  pivot_direction.y = target_direction.y;
  LODWORD(pivot_direction.x) = (_DWORD)target_direction.x;
  pivot_direction.z = target_direction.z;
  if ( AC1Legacy::Vector3::normalize_check_small(&pivot_direction) )
  {
    v52 = Position::localtoglobalvec((Position *)&v8[6], &look_direction, &v3->direction);
    pivot_direction.x = v52->x;
    pivot_direction.y = v52->y;
    pivot_direction.z = v52->z;
  }
  pivot_frame.m_fOrigin = delta;
  Frame::set_vector_heading(&pivot_frame, &pivot_direction);
  v53 = Frame::localtoglobal(&pivot_frame, &look_direction, &v3->viewer_offset);
  camera_frame.m_fOrigin.x = v53->x;
  camera_frame.m_fOrigin.y = v53->y;
  camera_frame.m_fOrigin.z = v53->z;
  if ( v3->target_status & 4 )
  {
    local_dir.x = delta.x - camera_frame.m_fOrigin.x;
    pivot_direction = local_dir;
    local_dir.y = delta.y - camera_frame.m_fOrigin.y;
    local_dir.z = delta.z - camera_frame.m_fOrigin.z;
    if ( AC1Legacy::Vector3::normalize_check_small(&pivot_direction) )
    {
      LODWORD(local_dir.x) = 0;
      v54 = 0.0;
      LODWORD(local_dir.y) = 0;
      v55 = 0.0;
      LODWORD(local_dir.z) = 0;
      v56 = 0.0;
    }
    else
    {
      v54 = pivot_direction.x;
      v55 = pivot_direction.y;
      v56 = pivot_direction.z;
    }
    target_direction.x = v54;
    target_direction.y = v55;
    target_direction.z = v56;
  }
  if ( AC1Legacy::Vector3::normalize_check_small(&target_direction) )
  {
    v59 = Position::localtoglobalvec((Position *)&v8[6], &look_direction, &v3->direction);
    target_direction.x = v59->x;
    target_direction.y = v59->y;
    target_direction.z = v59->z;
  }
  Frame::set_vector_heading(&camera_frame, &target_direction);
  *(double *)&normal.x = v3->t_stiffness;
  if ( *(double *)&normal.x <= 1.0 - 0.00019999999 )
  {
    v60 = 0;
    v61 = *(double *)&normal.x * quantum * 10.0;
    normal.x = v61;
    if ( v61 <= 1.0 )
      goto LABEL_55;
  }
  else
  {
    v60 = 1;
  }
  LODWORD(normal.x) = 1065353216;
LABEL_55:
  *(double *)&velocity_direction.x = v3->r_stiffness;
  if ( *(double *)&velocity_direction.x <= 1.0 - 0.00019999999 )
  {
    v62 = 0;
    v63 = *(double *)&velocity_direction.x * quantum * 10.0;
    *(float *)&quantum = v63;
    if ( v63 <= 1.0 )
      goto LABEL_59;
  }
  else
  {
    v62 = 1;
  }
  LODWORD(quantum) = 1065353216;
LABEL_59:
  actual_pos.vfptr = (PackObjVtbl *)&Position::vftable;
  actual_pos.objcell_id = 0;
  LODWORD(actual_pos.frame.qw) = 1065353216;
  LODWORD(actual_pos.frame.qx) = 0;
  LODWORD(actual_pos.frame.qy) = 0;
  LODWORD(actual_pos.frame.qz) = 0;
  LODWORD(actual_pos.frame.m_fOrigin.x) = 0;
  LODWORD(actual_pos.frame.m_fOrigin.y) = 0;
  LODWORD(actual_pos.frame.m_fOrigin.z) = 0;
  Frame::cache(&actual_pos.frame);
  actual_pos.objcell_id = v9->objcell_id;
  Frame::interpolate_origin(&actual_pos.frame, &v9->frame, &camera_frame, normal.x);
  Frame::interpolate_rotation(&actual_pos.frame, &v9->frame, &camera_frame, quantum);
  normal.x = F_EPSILON_37;
  *(float *)&quantum = 0.00019999999 + 0.00019999999;
  if ( !v60 )
  {
    v64 = Position::distance(&actual_pos, v9);
    if ( v64 < (float)quantum && !v62 && Frame::close_rotation(&actual_pos.frame, &v9->frame, normal.x) )
    {
      Position::Position(result, v9);
      return result;
    }
  }
  v65 = result;
  v66 = actual_pos.objcell_id;
  result->vfptr = (PackObjVtbl *)&Position::vftable;
  v67 = (char *)&actual_pos.frame;
LABEL_66:
  v65->objcell_id = v66;
  Frame::operator=((int)&v65->frame, (int)v67);
  return v65;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00457090) --------------------------------------------------------  // acclient.c:147865
void __thiscall CameraManager::CameraManager(CameraManager *this)
{
  CameraManager *v1; // esi@1
  char *v2; // ebx@1
  char *v3; // ebp@1
  char *v4; // eax@1
  char *v5; // edx@1
  char *v6; // ecx@1
  int v7; // eax@1
  int v8; // edx@1
  GlobalRegistryInstance *v9; // eax@3
  GlobalRegistryInstance *v10; // eax@4
  int v11; // eax@9
  char *v12; // ebp@11
  GlobalRegistryInstance *v13; // eax@16
  GlobalRegistryInstance *v14; // eax@17
  int v15; // eax@22
  char *v16; // ebx@24
  GlobalRegistryInstance *v17; // eax@29
  GlobalRegistryInstance *v18; // eax@30
  int v19; // eax@35
  char *v20; // ebx@37
  PStringBase<char> _Description; // [sp+10h] [bp-14h]@1
  GRPObject *_pFoundObject; // [sp+14h] [bp-10h]@8
  int v23; // [sp+18h] [bp-Ch]@1
  int v24; // [sp+1Ch] [bp-8h]@1
  int v25; // [sp+20h] [bp-4h]@1

  v1 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&IInputActionCallback::vftable;
  this->vfptr = (CInputHandlerVtbl *)&CameraManager::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&CameraManager::vftable;
  LODWORD(this->t_stiffness) = 1055286886;
  LODWORD(this->r_stiffness) = 1055286886;
  this->pivot_object_id = 0;
  this->pivot_part_index = -1;
  LODWORD(this->pivot_offset.x) = 0;
  LODWORD(this->pivot_offset.y) = 0;
  LODWORD(this->pivot_offset.z) = 0;
  this->target_part_index = -1;
  this->target_object_id = 0;
  LODWORD(this->target_offset.x) = 0;
  LODWORD(this->target_offset.y) = 0;
  LODWORD(this->target_offset.z) = 0;
  LODWORD(this->direction.x) = 0;
  LODWORD(this->direction.z) = 0;
  LODWORD(this->direction.y) = 1065353216;
  this->target_status = 1;
  LODWORD(this->viewer_offset.x) = 0;
  LODWORD(this->viewer_offset.y) = -1069547520;
  LODWORD(this->viewer_offset.z) = 0;
  LODWORD(this->m_rCameraStiffness) = 1055286886;
  LODWORD(this->m_rMovementSpeed) = 1065353216;
  LODWORD(this->scale) = 1065353216;
  this->m_bAlignCameraToSlope = 1;
  LODWORD(this->m_rCameraAdjustmentSpeed) = 1109393408;
  this->m_dwPivotOffsetMovement = 0;
  this->m_dwCameraOffsetMovement = 0;
  *(_QWORD *)&this->last_update_time = 0i64;
  this->old_velocity_num = 0;
  this->m_bEnabled = 1;
  this->m_pCurrentCameraSet = 0;
  v2 = (char *)&this->m_rCameraStiffness;
  v3 = (char *)&this->m_bAlignCameraToSlope;
  v4 = (char *)this->old_velocities;
  *(_DWORD *)v4 = 0;
  *((_DWORD *)v4 + 1) = 0;
  *((_DWORD *)v4 + 2) = 0;
  v5 = (char *)&this->old_velocities[1];
  *(_DWORD *)v5 = 0;
  *((_DWORD *)v5 + 1) = 0;
  *((_DWORD *)v5 + 2) = 0;
  v6 = (char *)&this->old_velocities[2];
  *(_DWORD *)v6 = 0;
  *((_DWORD *)v6 + 1) = 0;
  *((_DWORD *)v6 + 2) = 0;
  v7 = (int)&v1->old_velocities[3];
  *(_DWORD *)v7 = 0;
  *(_DWORD *)(v7 + 4) = 0;
  *(_DWORD *)(v7 + 8) = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v8 = (int)&v1->old_velocities[4];
  *(_DWORD *)v8 = 0;
  *(_DWORD *)(v8 + 4) = 0;
  *(_DWORD *)(v8 + 8) = 0;
  PStringBase<char>::PStringBase<char>(&_Description, "Whether the camera should align to slope");
  if ( v3 )
    GlobalRegistry::RegisterVariableInternal(v3, GRVDataType_Bool, &Camera_AlignToSlope_0, &_Description, 0, 0, 0, 0);
  v9 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v10 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v10 )
      GlobalRegistryInstance::GlobalRegistryInstance(v10);
    else
      v9 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v9;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v9, &Camera_AlignToSlope_0, &_pFoundObject) )
  {
    v11 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)();
    if ( v11 )
      *(_BYTE *)(v11 + 40) = 1;
  }
  v12 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v12 )
    (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "How quickly the camera responds to player movement");
  if ( v2 )
    GlobalRegistry::RegisterVariableInternal(
      v2,
      GRVDataType_Float32,
      &Camera_Stiffness_0,
      &_Description,
      (void (__cdecl *)(PStringBase<char> *))CameraManager::OnStiffnessChanged,
      0,
      0,
      0);
  v13 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v14 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v14 )
      GlobalRegistryInstance::GlobalRegistryInstance(v14);
    else
      v13 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v13;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v13, &Camera_Stiffness_0, &_pFoundObject) )
  {
    v15 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)();
    if ( v15 )
      *(_BYTE *)(v15 + 40) = 1;
  }
  v16 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v16 )
    (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
  PStringBase<char>::PStringBase<char>(
    &_Description,
    "How quickly the camera moves in response to keyboard movement commands");
  if ( v1 != (CameraManager *)-92 )
    GlobalRegistry::RegisterVariableInternal(
      &v1->m_rCameraAdjustmentSpeed,
      GRVDataType_Float32,
      &Camera_AdjustmentSpeed_0,
      &_Description,
      0,
      0,
      0,
      0);
  v17 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v18 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v18 )
      GlobalRegistryInstance::GlobalRegistryInstance(v18);
    else
      v17 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v17;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v17, &Camera_AdjustmentSpeed_0, &_pFoundObject) )
  {
    v19 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)();
    if ( v19 )
      *(_BYTE *)(v19 + 40) = 1;
  }
  v20 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v20 )
    (**(void (__thiscall ***)(char *, signed int))v20)(v20, 1);
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(signed int, IInputActionCallbackVtbl **, signed int))ICIDM::s_cidm->vfptr->RegisterInputMap)(
      5,
      &v1->vfptr,
      1000);
}
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 79BAA0: using guessed type int (__stdcall *CameraManager::vftable)(char);
// 79BAAC: using guessed type void (__thiscall *CameraManager::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (006EA7E0) --------------------------------------------------------  // acclient.c:766432
void _E91_29()
{
  outside_val_21 = 1000.0 + 1.0;
}

//----- (006EA800) --------------------------------------------------------  // acclient.c:766438
void _E93_9()
{
  block_length_21 = 24.0 * 8.0;
}

//----- (006EA820) --------------------------------------------------------  // acclient.c:766444
void _E95_9()
{
  half_square_length_21 = 24.0 * 0.5;
}

//----- (006EA840) --------------------------------------------------------  // acclient.c:766450
void _E97_28()
{
  DEFAULT_VIEW_RADIUS_8 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EA860) --------------------------------------------------------  // acclient.c:766456
void _E99_5()
{
  MIN_QUANTUM_8 = 1.0 / 30.0;
}

//----- (006EA880) --------------------------------------------------------  // acclient.c:766462
void _E101_1()
{
  MAX_QUANTUM_8 = 1.0 / 5.0;
}

//----- (006EA8A0) --------------------------------------------------------  // acclient.c:766468
void _E103_14()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_35, PFID_A8R8G8B8);
}

//----- (006EA8B0) --------------------------------------------------------  // acclient.c:766474
void _E105_7()
{
  LOWEST_DATA_RATE_55 = 1024;
}

//----- (006EA8C0) --------------------------------------------------------  // acclient.c:766480
void _E107_2()
{
  HIGHEST_DATA_RATE_55 = 0x7FFF;
}

//----- (006EA8D0) --------------------------------------------------------  // acclient.c:766486
int _E109_12()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_55;
  INITIAL_MAX_DATA_RATE_3 = LOWEST_DATA_RATE_55;
  return result;
}

//----- (006EA8E0) --------------------------------------------------------  // acclient.c:766496
int _E111_9()
{
  PStringBase<char>::PStringBase<char>(&Camera_AlignToSlope_0, "Camera.AlignToSlope");
  return atexit(sub_75CE10);
}

//----- (006EA900) --------------------------------------------------------  // acclient.c:766503
int _E114_10()
{
  PStringBase<char>::PStringBase<char>(&Camera_Stiffness_0, "Camera.Stiffness");
  return atexit(sub_75CE40);
}

//----- (006EA920) --------------------------------------------------------  // acclient.c:766510
int _E117_9()
{
  PStringBase<char>::PStringBase<char>(&Camera_AdjustmentSpeed_0, "Camera.AdjustmentSpeed");
  return atexit(sub_75CE70);
}

//----- (006EA940) --------------------------------------------------------  // acclient.c:766517
int _E120_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_27, "None");
  return atexit(sub_75CEA0);
}

//----- (006EA960) --------------------------------------------------------  // acclient.c:766524
int _E123_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_27, "Speed");
  return atexit(sub_75CED0);
}

//----- (006EA980) --------------------------------------------------------  // acclient.c:766531
int _E126_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_27, "Noise");
  return atexit(_E127_94);
}

//----- (006EA9A0) --------------------------------------------------------  // acclient.c:766538
int _E129_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_27, "Sine");
  return atexit(_E130_86);
}

//----- (006EA9C0) --------------------------------------------------------  // acclient.c:766545
int _E132_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_27, "Square");
  return atexit(_E133_79);
}

//----- (006EA9E0) --------------------------------------------------------  // acclient.c:766552
int _E135_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_27, "Bounce");
  return atexit(_E136_63);
}

//----- (006EAA00) --------------------------------------------------------  // acclient.c:766559
int _E138_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_27, "Perlin");
  return atexit(_E139_64);
}

//----- (006EAA20) --------------------------------------------------------  // acclient.c:766566
int _E141_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_27, "Fractal");
  return atexit(_E142_60);
}

//----- (006EAA40) --------------------------------------------------------  // acclient.c:766573
int _E144_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_27, "FrameLoop");
  return atexit(_E145_62);
}

//----- (006EAA60) --------------------------------------------------------  // acclient.c:766580
int _E1_50()
{
  return atexit(_E2_50);
}

//----- (0075CE10) --------------------------------------------------------  // acclient.c:885000
void __cdecl sub_75CE10()
{
  char *v0; // esi@1

  v0 = &Camera_AlignToSlope_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_AlignToSlope_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CE40) --------------------------------------------------------  // acclient.c:885013
void __cdecl sub_75CE40()
{
  char *v0; // esi@1

  v0 = &Camera_Stiffness_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_Stiffness_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CE70) --------------------------------------------------------  // acclient.c:885026
void __cdecl sub_75CE70()
{
  char *v0; // esi@1

  v0 = &Camera_AdjustmentSpeed_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_AdjustmentSpeed_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CEA0) --------------------------------------------------------  // acclient.c:885039
void __cdecl sub_75CEA0()
{
  char *v0; // esi@1

  v0 = &waveform_None_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CED0) --------------------------------------------------------  // acclient.c:885052
void __cdecl sub_75CED0()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CF00) --------------------------------------------------------  // acclient.c:885065
void __cdecl _E127_94()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CF30) --------------------------------------------------------  // acclient.c:885078
void __cdecl _E130_86()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CF60) --------------------------------------------------------  // acclient.c:885091
void __cdecl _E133_79()
{
  char *v0; // esi@1

  v0 = &waveform_Square_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CF90) --------------------------------------------------------  // acclient.c:885104
void __cdecl _E136_63()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CFC0) --------------------------------------------------------  // acclient.c:885117
void __cdecl _E139_64()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CFF0) --------------------------------------------------------  // acclient.c:885130
void __cdecl _E142_60()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D020) --------------------------------------------------------  // acclient.c:885143
void __cdecl _E145_62()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

