/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CameraSet
   Object     : PORTAL\smartbox\CameraSet.obj
   Functions  : 49
   Addresses  : 004573C0 - 0075D0F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004573C0) --------------------------------------------------------  // acclient.c:148047
bool __thiscall CameraManager::SetStiffness(CameraManager *this, float stiffness)
{
  CameraManager *v2; // esi@1

  v2 = this;
  return CameraManager::SetTranslationalStiffness(this, stiffness)
      && CameraManager::SetRotationalStiffness(v2, stiffness);
}

//----- (004573F0) --------------------------------------------------------  // acclient.c:148057
void __thiscall CameraSet::StopRotating(CameraSet *this, int __formal)
{
  this->rot_left = 0;
  this->rot_right = 0;
  *(_QWORD *)&this->m_ttLastRotate = 0i64;
}

//----- (00457410) --------------------------------------------------------  // acclient.c:148065
void __thiscall CameraSet::StopRaising(CameraSet *this)
{
  this->raise = 0;
  *(_QWORD *)&this->m_ttLastRaiseOrLower = 0i64;
}

//----- (00457420) --------------------------------------------------------  // acclient.c:148072
void __thiscall CameraSet::StopLowering(CameraSet *this)
{
  this->lower = 0;
  *(_QWORD *)&this->m_ttLastRaiseOrLower = 0i64;
}

//----- (00457430) --------------------------------------------------------  // acclient.c:148079
void __thiscall CameraSet::StopCloser(CameraSet *this)
{
  this->closer = 0;
  *(_QWORD *)&this->m_ttLastZoom = 0i64;
}

//----- (00457440) --------------------------------------------------------  // acclient.c:148086
void __thiscall CameraSet::StopFarther(CameraSet *this)
{
  this->farther = 0;
  *(_QWORD *)&this->m_ttLastZoom = 0i64;
}

//----- (00457450) --------------------------------------------------------  // acclient.c:148093
BOOL __stdcall CameraSet::InHead(AC1Legacy::Vector3 camera_off)
{
  return camera_off.x == 0.0 && camera_off.y == 0.18000001 && camera_off.z == 0.0;
}

//----- (00457490) --------------------------------------------------------  // acclient.c:148099
void __userpurge CameraSet::ToggleMouseLook(CameraSet *this@<ecx>, int a2@<ebp>, int mouse_on)
{
  CameraSet *v3; // esi@1
  SmartBox *v4; // eax@2
  int v5; // ST10_4@2
  CInputManager *v6; // ebp@2

  v3 = this;
  if ( this->mouselook_active != mouse_on )
  {
    v4 = this->sbox;
    v5 = a2;
    v6 = ICIDM::s_cidm;
    this->mouselook_active = mouse_on;
    ((void (__stdcall *)(int, int))v4->cmdinterp->vfptr[17].OnAction)(mouse_on, v5);
    if ( v3->mouselook_active )
    {
      v3->mouselook_x_extent = 0;
      v3->mouselook_y_extent = 0;
    }
    ((void (__thiscall *)(CInputManager *))v6->vfptr->SetMouseLookMode)(v6);
    if ( v6->m_UseMouseTurning )
    {
      ((void (__stdcall *)(signed int, int, signed int, signed int, signed int))v3->sbox->cmdinterp->vfptr[13].OnAction)(
        201326785,
        mouse_on,
        1065353216,
        1,
        1);
      if ( !mouse_on )
        ((void (*)(void))v3->sbox->cmdinterp->vfptr[2].OnAction)();
      ((void (*)(void))v3->sbox->cmdinterp->vfptr[6].OnAction)();
    }
  }
}
// 457490: could not find valid save-restore pair for ebp

//----- (00457530) --------------------------------------------------------  // acclient.c:148137
void __stdcall CameraSet::FilterMouseInput(const float _DeltaX, const float _DeltaY, const float _MouseSmoothingAmount, float *o_FilteredX, float *o_FilteredY)
{
  long double v6; // st7@1
  double v7; // st6@2
  double v8; // st5@2
  double v9; // st4@4
  double v10; // st5@4

  v6 = Timer::compute_local_time();
  if ( v6 - s_LastFilterRealLocalTime <= 0.25 )
  {
    v7 = (s_LastDeltaX + _DeltaX) * 0.5;
    v8 = (s_LastDeltaY + _DeltaY) * 0.5;
  }
  else
  {
    v7 = _DeltaX;
    v8 = _DeltaY;
  }
  v9 = 1.0 - _MouseSmoothingAmount;
  *o_FilteredX = _DeltaX * v9 + v7 * _MouseSmoothingAmount;
  v10 = v9 * _DeltaY + v8 * _MouseSmoothingAmount;
  *o_FilteredY = v10;
  LODWORD(s_LastDeltaX) = *(_DWORD *)o_FilteredX;
  s_LastDeltaY = v10;
  s_LastFilterRealLocalTime = v6;
}

//----- (004575D0) --------------------------------------------------------  // acclient.c:148166
double __thiscall AC1Legacy::Vector3::get_heading(AC1Legacy::Vector3 *this)
{
  float v1; // eax@1
  double result; // st7@2
  AC1Legacy::Vector3 normal; // [sp+4h] [bp-Ch]@1

  v1 = this->x;
  normal.y = this->y;
  normal.x = v1;
  LODWORD(normal.z) = 0;
  if ( AC1Legacy::Vector3::normalize_check_small(&normal) )
    result = 0.0;
  else
    result = fmod(450.0 - atan2(normal.x, normal.y) * 57.29577951308232, 360.0);
  return result;
}

//----- (00457630) --------------------------------------------------------  // acclient.c:148184
double __thiscall AC1Legacy::Vector3::get_pitch(AC1Legacy::Vector3 *this)
{
  float v1; // edx@1
  float v2; // eax@1
  double result; // st7@2
  AC1Legacy::Vector3 normal; // [sp+0h] [bp-Ch]@1

  v1 = this->y;
  normal.x = this->x;
  v2 = this->z;
  normal.y = v1;
  normal.z = v2;
  if ( AC1Legacy::Vector3::normalize_check_small(&normal) )
    result = 0.0;
  else
    result = asin(normal.z) * 57.29577951308232;
  return result;
}

//----- (00457680) --------------------------------------------------------  // acclient.c:148204
BOOL __thiscall CameraSet::InHead(CameraSet *this)
{
  CameraManager *v1; // eax@1

  v1 = this->cm;
  return v1->viewer_offset.x == 0.0 && v1->viewer_offset.y == 0.18000001 && v1->viewer_offset.z == 0.0;
}

//----- (004576E0) --------------------------------------------------------  // acclient.c:148213
void __thiscall CameraSet::SetTargetForOffset(CameraSet *this, AC1Legacy::Vector3 camera_off)
{
  CameraSet *v2; // esi@1

  v2 = this;
  CameraManager::ClearTarget(this->cm);
  if ( v2->looking_down )
    goto LABEL_6;
  if ( camera_off.x == 0.0 && camera_off.y == 0.18000001 && camera_off.z == 0.0 )
  {
    CameraManager::SetTarget(v2->cm, ALIGN_WITH_PLANE);
LABEL_6:
    CameraManager::SetTarget(v2->cm, LOOK_IN_DIRECTION);
    return;
  }
  if ( v2->targeting )
  {
    CameraManager::SetTarget(v2->cm, LOOK_AT_PIVOT|LOOK_AT_OBJECT);
  }
  else
  {
    if ( camera_off.x > 1.0 || camera_off.x < -1.0 || camera_off.y > 0.0 )
      goto LABEL_20;
    CameraManager::SetTarget(v2->cm, ALIGN_WITH_PLANE);
    if ( camera_off.y <= -0.5 && camera_off.z >= -0.5 )
      CameraManager::SetTarget(v2->cm, LOOK_IN_DIRECTION);
    if ( camera_off.z > 0.75 || camera_off.z < -0.5 )
LABEL_20:
      CameraManager::SetTarget(v2->cm, LOOK_AT_PIVOT);
  }
}

//----- (004577F0) --------------------------------------------------------  // acclient.c:148246
void __thiscall CameraSet::SetStiffness(CameraSet *this, float _stiffness)
{
  CameraSet *v2; // esi@1
  CameraManager *v3; // esi@2

  v2 = this;
  this->current_stiffness = _stiffness;
  if ( CameraSet::InHead(this) )
  {
    CameraManager::SetRotationalStiffness(v2->cm, _stiffness);
  }
  else
  {
    v3 = v2->cm;
    if ( CameraManager::SetTranslationalStiffness(v3, _stiffness) )
      CameraManager::SetRotationalStiffness(v3, _stiffness);
  }
}

//----- (00457840) --------------------------------------------------------  // acclient.c:148266
void __thiscall CameraSet::SetScale(CameraSet *this, float _scale)
{
  CameraSet *v2; // esi@1
  CameraManager *v3; // edi@2
  double v4; // st7@3
  double v5; // st7@4
  int v6; // edx@9
  _BYTE v7[12]; // ST00_12@9
  float v8; // edx@9
  CameraManager *v9; // esi@9
  float v10; // edi@9
  float scale; // [sp+8h] [bp-10h]@2
  __int64 camera_off; // [sp+Ch] [bp-Ch]@3
  float camera_off_8; // [sp+14h] [bp-4h]@3

  v2 = this;
  if ( CameraSet::InHead(this) )
    return;
  v3 = v2->cm;
  scale = v3->scale;
  if ( scale == _scale )
    return;
  v4 = v3->viewer_offset.x;
  HIDWORD(camera_off) = LODWORD(v3->viewer_offset.y);
  camera_off_8 = v3->viewer_offset.z;
  if ( scale == 1.0 )
    goto LABEL_6;
  v5 = 1.0 / scale;
  *(float *)&camera_off = v3->viewer_offset.x * v5;
  *((float *)&camera_off + 1) = *((float *)&camera_off + 1) * v5;
  camera_off_8 = camera_off_8 * v5;
  if ( _scale != 1.0 )
  {
    v4 = *(float *)&camera_off;
LABEL_6:
    *(float *)&camera_off = v4 * _scale;
    *((float *)&camera_off + 1) = *((float *)&camera_off + 1) * _scale;
    camera_off_8 = camera_off_8 * _scale;
  }
  if ( CameraManager::SetTranslationalStiffness(v3, 1.0) )
    CameraManager::SetRotationalStiffness(v3, 1.0);
  v2->cm->scale = _scale;
  v6 = (int)&v2->cm->viewer_offset;
  *(_QWORD *)v6 = camera_off;
  *(float *)(v6 + 8) = camera_off_8;
  *(_QWORD *)v7 = camera_off;
  *(_DWORD *)&v7[8] = LODWORD(camera_off_8);
  CameraSet::SetTargetForOffset(v2, *(AC1Legacy::Vector3 *)v7);
  v8 = v2->current_stiffness;
  v9 = v2->cm;
  v10 = v8;
  if ( CameraManager::SetTranslationalStiffness(v9, v8) )
    CameraManager::SetRotationalStiffness(v9, v10);
}

//----- (00457980) --------------------------------------------------------  // acclient.c:148322
void __thiscall CameraSet::Raise(CameraSet *this, int keep_going, float i_fChangeModOverride)
{
  CameraSet *v3; // esi@1
  double v4; // st7@1
  CameraManager *v5; // eax@4
  float v6; // edx@4
  int v7; // ecx@4
  bool v8; // zf@4
  double v9; // st7@6
  float v10; // eax@6
  _BYTE v11[12]; // ST00_12@7
  CameraManager *v12; // ecx@8
  double v13; // st7@8
  long double v14; // st7@13
  CameraManager *v15; // edi@13
  float radius; // ST1C_4@17
  float theta; // ST20_4@17
  double v18; // st7@17
  long double v19; // st6@17
  long double v20; // st7@17
  long double v21; // st6@17
  CameraManager *v22; // ecx@29
  float v23; // edx@29
  int v24; // eax@29
  float v25; // ecx@29
  int v26; // edx@29
  _BYTE v27[12]; // ST00_12@29
  float saveY; // [sp+14h] [bp-28h]@13
  float saveX; // [sp+18h] [bp-24h]@13
  long double mod; // [sp+1Ch] [bp-20h]@1
  int v31; // [sp+24h] [bp-18h]@29
  AC1Legacy::Vector3 camera_dir; // [sp+30h] [bp-Ch]@4

  v3 = this;
  this->raise = keep_going;
  this->lower = 0;
  v4 = *(double *)&Timer::cur_time;
  mod = *(double *)&Timer::cur_time;
  if ( this->m_ttLastRaiseOrLower == 0.0 )
    this->m_ttLastRaiseOrLower = COERCE_DOUBLE(Timer::cur_time.Cmd) - 1.0 / SceneTool::m_FramesPerSecond;
  if ( v4 - this->m_ttLastRaiseOrLower >= 0.00019999999 )
  {
    v5 = this->cm;
    v6 = v5->viewer_offset.x;
    v7 = (int)&v5->viewer_offset;
    camera_dir.y = v5->viewer_offset.y;
    v8 = v3->looking_down == 0;
    camera_dir.x = v6;
    camera_dir.z = v5->viewer_offset.z;
    if ( !v8 )
    {
      if ( -(10.0 - 0.2) <= camera_dir.y )
      {
        v9 = camera_dir.y - 0.2;
        *(_DWORD *)v7 = (_DWORD)camera_dir.x;
        v10 = camera_dir.z;
        camera_dir.y = v9;
        *(_DWORD *)(v7 + 4) = LODWORD(camera_dir.y);
        *(float *)(v7 + 8) = v10;
      }
      goto LABEL_30;
    }
    *(_QWORD *)v11 = *(_QWORD *)&camera_dir;
    *(_DWORD *)&v11[8] = LODWORD(camera_dir.z);
    if ( CameraSet::InHead(*(AC1Legacy::Vector3 *)v11) )
    {
      v12 = v3->cm;
      camera_dir.x = v12->direction.x;
      camera_dir.y = v12->direction.y;
      v13 = v12->direction.z - 0.2;
      camera_dir.z = v13;
      if ( v13 <= 0.80000001 )
      {
        if ( camera_dir.z >= -0.80000001 )
        {
          CameraManager::SetTargetDirection(v12, &camera_dir);
        }
        else
        {
          camera_dir.z = -0.80000001;
          CameraManager::SetTargetDirection(v12, &camera_dir);
        }
      }
      else
      {
        camera_dir.z = CAMERA_MOUSELOOK_LIMIT;
        CameraManager::SetTargetDirection(v12, &camera_dir);
      }
LABEL_30:
      if ( !keep_going )
      {
        v3->raise = 0;
        LODWORD(v3->m_ttLastRaiseOrLower) = 0;
        HIDWORD(v3->m_ttLastRaiseOrLower) = 0;
      }
      return;
    }
    v14 = mod;
    v15 = v3->cm;
    saveY = camera_dir.y;
    saveX = camera_dir.x;
    mod = v15->m_rCameraAdjustmentSpeed * (mod - v3->m_ttLastRaiseOrLower);
    if ( i_fChangeModOverride != 1.0 )
      mod = i_fChangeModOverride;
    if ( ICIDM::s_cidm->m_UseMouseTurning )
      mod = mod * 0.25;
    v3->m_ttLastRaiseOrLower = v14;
    radius = sqrt(camera_dir.z * camera_dir.z + camera_dir.x * camera_dir.x + camera_dir.y * camera_dir.y);
    theta = AC1Legacy::Vector3::get_heading(&camera_dir) * 0.017453292;
    v18 = AC1Legacy::Vector3::get_pitch(&camera_dir);
    v19 = angle * mod;
    *(float *)&mod = v19;
    v20 = v18 * 0.017453292 + v19;
    v21 = cos(v20);
    camera_dir.x = sin(theta) * radius * v21;
    camera_dir.y = cos(theta) * radius * v21;
    camera_dir.z = sin(v20) * radius;
    if ( saveY >= 0.0 )
    {
      if ( saveY > 0.0 && camera_dir.y <= 0.0 )
        return;
    }
    else if ( camera_dir.y >= 0.0 )
    {
      return;
    }
    if ( saveX < 0.0 )
    {
      if ( camera_dir.x >= 0.0 )
        return;
      goto LABEL_27;
    }
    if ( saveX <= 0.0 || camera_dir.x > 0.0 )
    {
LABEL_27:
      if ( camera_dir.z > -1.8 )
        CameraManager::SetStiffness(v15, v3->current_stiffness);
      v22 = v3->cm;
      mod = 0.0078125;
      v31 = 0;
      CameraManager::SetTargetDirection(v22, (AC1Legacy::Vector3 *)&mod);
      v23 = camera_dir.y;
      v24 = (int)&v3->cm->viewer_offset;
      *(_DWORD *)v24 = (_DWORD)camera_dir.x;
      v25 = camera_dir.z;
      *(float *)(v24 + 4) = v23;
      v26 = (signed int)camera_dir.x;
      *(float *)(v24 + 8) = v25;
      *(_DWORD *)v27 = v26;
      *(_QWORD *)&v27[4] = *(_QWORD *)&camera_dir.y;
      CameraSet::SetTargetForOffset(v3, *(AC1Legacy::Vector3 *)v27);
      goto LABEL_30;
    }
  }
}
// 837418: using guessed type float SceneTool::m_FramesPerSecond;

//----- (00457CF0) --------------------------------------------------------  // acclient.c:148480
void __thiscall CameraSet::Lower(CameraSet *this, int keep_going, float i_fChangeModOverride)
{
  CameraSet *v3; // esi@1
  double v4; // st7@1
  CameraManager *v5; // eax@4
  float v6; // edx@4
  int v7; // ecx@4
  bool v8; // zf@4
  double v9; // st7@6
  float v10; // eax@6
  _BYTE v11[12]; // ST00_12@7
  CameraManager *v12; // ecx@8
  double v13; // st7@8
  long double v14; // st7@13
  CameraManager *v15; // edi@13
  float radius; // ST1C_4@17
  float theta; // ST20_4@17
  double v18; // st7@17
  long double v19; // st6@17
  long double v20; // st7@17
  long double v21; // st6@17
  CameraManager *v22; // ecx@21
  float v23; // edx@21
  int v24; // eax@21
  float v25; // ecx@21
  int v26; // edx@21
  _BYTE v27[12]; // ST00_12@21
  long double mod; // [sp+14h] [bp-20h]@1
  int v29; // [sp+1Ch] [bp-18h]@21
  AC1Legacy::Vector3 camera_dir; // [sp+28h] [bp-Ch]@4

  v3 = this;
  this->lower = keep_going;
  this->raise = 0;
  v4 = *(double *)&Timer::cur_time;
  mod = *(double *)&Timer::cur_time;
  if ( this->m_ttLastRaiseOrLower == 0.0 )
    this->m_ttLastRaiseOrLower = COERCE_DOUBLE(Timer::cur_time.Cmd) - 1.0 / SceneTool::m_FramesPerSecond;
  if ( v4 - this->m_ttLastRaiseOrLower >= 0.00019999999 )
  {
    v5 = this->cm;
    v6 = v5->viewer_offset.x;
    v7 = (int)&v5->viewer_offset;
    camera_dir.y = v5->viewer_offset.y;
    v8 = v3->looking_down == 0;
    camera_dir.x = v6;
    camera_dir.z = v5->viewer_offset.z;
    if ( !v8 )
    {
      if ( camera_dir.y <= 0.8 )
      {
        v9 = camera_dir.y + 0.2;
        *(_DWORD *)v7 = (_DWORD)camera_dir.x;
        v10 = camera_dir.z;
        camera_dir.y = v9;
        *(_DWORD *)(v7 + 4) = LODWORD(camera_dir.y);
        *(float *)(v7 + 8) = v10;
      }
      goto LABEL_22;
    }
    *(_QWORD *)v11 = *(_QWORD *)&camera_dir;
    *(_DWORD *)&v11[8] = LODWORD(camera_dir.z);
    if ( CameraSet::InHead(*(AC1Legacy::Vector3 *)v11) )
    {
      v12 = v3->cm;
      camera_dir.x = v12->direction.x;
      camera_dir.y = v12->direction.y;
      v13 = v12->direction.z + 0.2;
      camera_dir.z = v13;
      if ( v13 <= 0.80000001 )
      {
        if ( camera_dir.z >= -0.80000001 )
        {
          CameraManager::SetTargetDirection(v12, &camera_dir);
        }
        else
        {
          camera_dir.z = -0.80000001;
          CameraManager::SetTargetDirection(v12, &camera_dir);
        }
      }
      else
      {
        camera_dir.z = CAMERA_MOUSELOOK_LIMIT;
        CameraManager::SetTargetDirection(v12, &camera_dir);
      }
LABEL_22:
      if ( !keep_going )
      {
        v3->lower = 0;
        LODWORD(v3->m_ttLastRaiseOrLower) = 0;
        HIDWORD(v3->m_ttLastRaiseOrLower) = 0;
      }
      return;
    }
    v14 = mod;
    v15 = v3->cm;
    mod = v15->m_rCameraAdjustmentSpeed * (mod - v3->m_ttLastRaiseOrLower);
    if ( i_fChangeModOverride != 1.0 )
      mod = i_fChangeModOverride;
    if ( ICIDM::s_cidm->m_UseMouseTurning )
      mod = mod * 0.25;
    v3->m_ttLastRaiseOrLower = v14;
    radius = sqrt(camera_dir.z * camera_dir.z + camera_dir.x * camera_dir.x + camera_dir.y * camera_dir.y);
    theta = AC1Legacy::Vector3::get_heading(&camera_dir) * 0.017453292;
    v18 = AC1Legacy::Vector3::get_pitch(&camera_dir);
    v19 = angle * mod;
    *(float *)&mod = v19;
    v20 = v18 * 0.017453292 - v19;
    v21 = cos(v20);
    camera_dir.x = sin(theta) * radius * v21;
    camera_dir.y = cos(theta) * radius * v21;
    camera_dir.z = sin(v20) * radius;
    if ( 1.2 * 1.2 <= camera_dir.x * camera_dir.x + camera_dir.y * camera_dir.y || camera_dir.z >= 0.0 )
    {
      if ( camera_dir.z <= -1.8 )
        CameraManager::SetStiffness(v15, 1.0);
      v22 = v3->cm;
      mod = 0.0078125;
      v29 = 0;
      CameraManager::SetTargetDirection(v22, (AC1Legacy::Vector3 *)&mod);
      v23 = camera_dir.y;
      v24 = (int)&v3->cm->viewer_offset;
      *(_DWORD *)v24 = (_DWORD)camera_dir.x;
      v25 = camera_dir.z;
      *(float *)(v24 + 4) = v23;
      v26 = (signed int)camera_dir.x;
      *(float *)(v24 + 8) = v25;
      *(_DWORD *)v27 = v26;
      *(_QWORD *)&v27[4] = *(_QWORD *)&camera_dir.y;
      CameraSet::SetTargetForOffset(v3, *(AC1Legacy::Vector3 *)v27);
      goto LABEL_22;
    }
  }
}
// 837418: using guessed type float SceneTool::m_FramesPerSecond;

//----- (00457FF0) --------------------------------------------------------  // acclient.c:148618
void __thiscall CameraSet::LookDown(CameraSet *this, int look_down)
{
  CameraSet *v2; // esi@1
  CameraManager *v3; // ecx@3
  int v4; // edx@3
  int v5; // eax@3
  int v6; // eax@3
  CameraManager *v7; // edi@4
  _BYTE v8[12]; // ST00_12@7
  _BYTE v9[12]; // ST00_12@11
  _BYTE v10[12]; // ST00_12@14
  float v11; // ecx@16
  float v12; // edx@16
  float v13; // edx@17
  int v14; // eax@17
  float v15; // ecx@17
  int v16; // edx@17
  _BYTE v17[12]; // ST00_12@17
  AC1Legacy::Vector3 camera_off; // [sp+Ch] [bp-Ch]@3

  v2 = this;
  if ( look_down != this->looking_down )
  {
    this->looking_down = look_down;
    if ( look_down )
    {
      v3 = this->cm;
      v4 = (int)&v2->lookdown_saved_offset;
      *(_DWORD *)v4 = LODWORD(v3->viewer_offset.x);
      *(_DWORD *)(v4 + 4) = LODWORD(v3->viewer_offset.y);
      *(_DWORD *)(v4 + 8) = LODWORD(v3->viewer_offset.z);
      v5 = (int)&v2->lookdown_saved_target_dir;
      *(_DWORD *)v5 = LODWORD(v3->direction.x);
      *(_DWORD *)(v5 + 4) = LODWORD(v3->direction.y);
      *(_DWORD *)(v5 + 8) = LODWORD(v3->direction.z);
      LODWORD(camera_off.x) = 0;
      LODWORD(camera_off.y) = 1056964608;
      LODWORD(camera_off.z) = -1075419546;
      CameraManager::SetTargetDirection(v3, &camera_off);
      v6 = v2->in_map_mode;
      LODWORD(camera_off.z) = 1061158912;
      LODWORD(camera_off.x) = 0;
      if ( v6 )
      {
        v7 = v2->cm;
        camera_off.y = -450.0;
        if ( CameraManager::SetTranslationalStiffness(v7, 1.0) )
          CameraManager::SetRotationalStiffness(v7, 1.0);
        SmartBox::DisableDegrades(1);
        SmartBox::DisableFogging(1);
      }
      else
      {
        *(_DWORD *)v8 = LODWORD(v2->lookdown_saved_offset.x);
        *(_QWORD *)&v8[4] = *(_QWORD *)&v2->lookdown_saved_offset.y;
        if ( CameraSet::InHead(*(AC1Legacy::Vector3 *)v8) )
          CameraManager::SetStiffness(v2->cm, v2->current_stiffness);
        LODWORD(camera_off.y) = -1073741824;
      }
    }
    else
    {
      if ( this->in_map_mode )
      {
        this->in_map_mode = 0;
        *(_DWORD *)v9 = LODWORD(this->lookdown_saved_offset.x);
        *(_QWORD *)&v9[4] = *(_QWORD *)&this->lookdown_saved_offset.y;
        if ( !CameraSet::InHead(*(AC1Legacy::Vector3 *)v9) )
          CameraManager::SetStiffness(v2->cm, v2->current_stiffness);
        SmartBox::DisableDegrades(0);
        SmartBox::DisableFogging(0);
      }
      else
      {
        *(_DWORD *)v10 = LODWORD(this->lookdown_saved_offset.x);
        *(_QWORD *)&v10[4] = *(_QWORD *)&this->lookdown_saved_offset.y;
        if ( CameraSet::InHead(*(AC1Legacy::Vector3 *)v10) )
          CameraManager::SetStiffness(v2->cm, 1.0);
      }
      CameraManager::SetTargetDirection(v2->cm, &v2->lookdown_saved_target_dir);
      v11 = v2->lookdown_saved_offset.y;
      v12 = v2->lookdown_saved_offset.z;
      camera_off.x = v2->lookdown_saved_offset.x;
      camera_off.y = v11;
      camera_off.z = v12;
    }
    v13 = camera_off.y;
    v14 = (int)&v2->cm->viewer_offset;
    *(_DWORD *)v14 = (_DWORD)camera_off.x;
    v15 = camera_off.z;
    *(float *)(v14 + 4) = v13;
    v16 = (signed int)camera_off.x;
    *(float *)(v14 + 8) = v15;
    *(_DWORD *)v17 = v16;
    *(_QWORD *)&v17[4] = *(_QWORD *)&camera_off.y;
    CameraSet::SetTargetForOffset(v2, *(AC1Legacy::Vector3 *)v17);
  }
}

//----- (004581D0) --------------------------------------------------------  // acclient.c:148718
void __thiscall CameraSet::SetMapMode(CameraSet *this, int map_mode)
{
  CameraSet *v2; // esi@1
  CameraManager *v3; // edi@5
  CameraManager *v4; // eax@8
  float camera_off_4; // ST14_4@8
  float camera_off; // ST10_4@8
  float camera_off_8; // ST18_4@8
  int v8; // eax@8

  v2 = this;
  if ( map_mode != this->in_map_mode )
  {
    if ( map_mode )
      this->in_map_mode = map_mode;
    if ( this->in_map_mode )
    {
      v3 = this->cm;
      if ( CameraManager::SetTranslationalStiffness(this->cm, 1.0) )
        CameraManager::SetRotationalStiffness(v3, 1.0);
    }
    CameraSet::LookDown(v2, map_mode);
    if ( v2->in_map_mode )
    {
      v4 = v2->cm;
      camera_off_4 = -450.0;
      camera_off = v4->viewer_offset.x;
      camera_off_8 = v4->viewer_offset.z;
      SmartBox::DisableDegrades(1);
      SmartBox::DisableFogging(1);
      v8 = (int)&v2->cm->viewer_offset;
      *(float *)v8 = camera_off;
      *(float *)(v8 + 4) = camera_off_4;
      *(float *)(v8 + 8) = camera_off_8;
    }
  }
}

//----- (00458280) --------------------------------------------------------  // acclient.c:148757
void __thiscall CameraSet::TrackTarget(CameraSet *this, unsigned int _gid)
{
  CameraSet *v2; // esi@1
  CameraManager *v3; // ecx@3
  int v4; // eax@3
  CameraManager *v5; // eax@4
  _BYTE v6[12]; // ST00_12@4

  v2 = this;
  if ( _gid )
  {
    v3 = this->cm;
    v2->targeting = 1;
    CameraManager::SetTargetObject(v3, _gid, -1);
    v4 = (int)&v2->cm->target_offset;
    *(_DWORD *)v4 = 0;
    *(_DWORD *)(v4 + 4) = 0;
    *(_DWORD *)(v4 + 8) = 1056964608;
  }
  else
  {
    this->targeting = 0;
  }
  v5 = v2->cm;
  *(_DWORD *)v6 = LODWORD(v5->viewer_offset.x);
  *(_QWORD *)&v6[4] = *(_QWORD *)&v5->viewer_offset.y;
  CameraSet::SetTargetForOffset(v2, *(AC1Legacy::Vector3 *)v6);
}

//----- (00458310) --------------------------------------------------------  // acclient.c:148787
void __thiscall CameraSet::Rotate(CameraSet *this, int clockwise_dir, int keep_going, float i_fChangeModOverride, int camera_keys)
{
  CameraSet *v5; // esi@1
  CPhysicsObj *v6; // ecx@1
  CInputManager *v7; // edi@1
  int v8; // eax@1
  CameraManager *v9; // ecx@6
  float v10; // edx@6
  bool v11; // zf@6
  SmartBox *v12; // edx@8
  long double v13; // st7@9
  long double v14; // st7@14
  IInputActionCallbackVtbl *v15; // eax@16
  long double v16; // st7@19
  SmartBox *v17; // eax@20
  CPhysicsObj *v18; // ecx@24
  double v19; // st7@26
  float v20; // ST20_4@30
  double v21; // st7@31
  long double v22; // st6@31
  long double v23; // st6@34
  long double v24; // rt0@34
  long double v25; // st5@34
  long double v26; // st6@34
  long double v27; // st6@37
  long double v28; // rt2@37
  long double v29; // st5@37
  int v30; // eax@38
  float v31; // edx@38
  int v32; // eax@38
  float v33; // ecx@38
  int v34; // edx@38
  _BYTE v35[12]; // ST08_12@38
  float heading; // [sp+10h] [bp-4Ch]@14
  float headinga; // [sp+10h] [bp-4Ch]@25
  long double curTime; // [sp+14h] [bp-48h]@1
  int v39; // [sp+1Ch] [bp-40h]@38
  AC1Legacy::Vector3 camera_off; // [sp+28h] [bp-34h]@6
  InterpretedMotionState old_motion_state; // [sp+34h] [bp-28h]@1

  v5 = this;
  v6 = this->sbox->player;
  v7 = ICIDM::s_cidm;
  curTime = *(double *)&Timer::cur_time;
  v8 = CPhysicsObj::InqInterpretedMotionState(v6);
  InterpretedMotionState::InterpretedMotionState(&old_motion_state, (InterpretedMotionState *)v8);
  if ( v5->m_ttLastRotate == 0.0 )
    v5->m_ttLastRotate = curTime - 1.0 / SceneTool::m_FramesPerSecond;
  if ( curTime - v5->m_ttLastRotate >= 0.00019999999 )
  {
    if ( v5->looking_down )
      CameraSet::LookDown(v5, 0);
    v9 = v5->cm;
    v10 = v9->viewer_offset.y;
    camera_off.x = v9->viewer_offset.x;
    camera_off.z = v9->viewer_offset.z;
    v11 = v7->m_UseMouseTurning == 0;
    camera_off.y = v10;
    if ( v11 || camera_keys )
    {
      if ( camera_off.x != 0.0 || camera_off.y != 0.18000001 || camera_off.z != 0.0 )
      {
        v21 = camera_off.x;
        v22 = v9->m_rCameraAdjustmentSpeed * (curTime - v5->m_ttLastRotate);
        if ( clockwise_dir )
        {
          if ( i_fChangeModOverride != 1.0 )
            v22 = i_fChangeModOverride;
          v23 = v22 * angle;
          v5->rot_left = keep_going;
          v5->rot_right = 0;
          v24 = sin(v23);
          v25 = cos(v23);
          camera_off.x = camera_off.x * v25 - -(v24 * camera_off.y);
          v26 = v25 * camera_off.y - v24 * v21;
        }
        else
        {
          if ( i_fChangeModOverride != 1.0 )
            v22 = i_fChangeModOverride;
          v27 = v22 * angle;
          v5->rot_right = keep_going;
          v5->rot_left = 0;
          v28 = sin(v27);
          v29 = cos(v27);
          camera_off.x = camera_off.x * v29 - v28 * camera_off.y;
          v26 = v29 * camera_off.y + v28 * v21;
        }
        camera_off.y = v26;
        v30 = HIDWORD(curTime);
        LODWORD(v5->m_ttLastRotate) = LODWORD(curTime);
        HIDWORD(v5->m_ttLastRotate) = v30;
        curTime = 0.0078125;
        v39 = 0;
        CameraManager::SetTargetDirection(v9, (AC1Legacy::Vector3 *)&curTime);
        v31 = camera_off.y;
        v32 = (int)&v5->cm->viewer_offset;
        *(_DWORD *)v32 = (_DWORD)camera_off.x;
        v33 = camera_off.z;
        *(float *)(v32 + 4) = v31;
        v34 = (signed int)camera_off.x;
        *(float *)(v32 + 8) = v33;
        *(_DWORD *)v35 = v34;
        *(_QWORD *)&v35[4] = *(_QWORD *)&camera_off.y;
        CameraSet::SetTargetForOffset(v5, *(AC1Legacy::Vector3 *)v35);
      }
      else
      {
        v18 = v5->sbox->player;
        if ( v18 )
        {
          headinga = CPhysicsObj::get_heading(v18);
          if ( clockwise_dir )
          {
            v5->rot_left = keep_going;
            v19 = headinga + 8.0;
            v5->rot_right = 0;
            if ( v19 >= 360.0 )
              v19 = headinga - (360.0 - 8.0);
          }
          else
          {
            v5->rot_right = keep_going;
            v19 = headinga - 8.0;
            v5->rot_left = 0;
            if ( v19 < 0.0 )
              v19 = 360.0 - 8.0 + headinga;
          }
          v20 = v19;
          ((void (__stdcall *)(_DWORD, _DWORD))v5->sbox->cmdinterp->vfptr[16].OnAction)(LODWORD(v20), 0);
        }
      }
    }
    else
    {
      v12 = v5->sbox;
      if ( v12->player )
      {
        v13 = (curTime - v5->m_ttLastRotate) * v9->m_rCameraAdjustmentSpeed;
        if ( i_fChangeModOverride != 1.0 )
          v13 = i_fChangeModOverride;
        if ( v13 < 0.02 && v13 > -0.02 )
        {
          ((void (*)(void))v12->cmdinterp->vfptr[13].OnLoseFocus)();
          InterpretedMotionState::~InterpretedMotionState(&old_motion_state);
          return;
        }
        v14 = v13 + v13;
        heading = v14;
        if ( v14 > 1.5 )
          heading = 1.5;
        v15 = v12->cmdinterp->vfptr;
        if ( clockwise_dir )
          ((void (__stdcall *)(signed int, signed int, float, signed int, signed int))v15[13].OnAction)(
            1694498829,
            1,
            LODWORD(heading),
            1,
            1);
        else
          ((void (__stdcall *)(signed int, signed int, float, signed int, signed int))v15[13].OnAction)(
            1694498830,
            1,
            LODWORD(heading),
            1,
            1);
        v16 = curTime;
        v5->m_ttLastRotate = curTime;
        if ( v16 > v5->m_LastServerMessage + 0.5 )
        {
          v17 = v5->sbox;
          v5->m_LastServerMessage = v16;
          ((void (*)(void))v17->cmdinterp->vfptr[6].OnAction)();
        }
      }
    }
    if ( !keep_going )
    {
      v5->rot_left = 0;
      v5->rot_right = 0;
      LODWORD(v5->m_ttLastRotate) = 0;
      HIDWORD(v5->m_ttLastRotate) = 0;
    }
  }
  InterpretedMotionState::~InterpretedMotionState(&old_motion_state);
}
// 837418: using guessed type float SceneTool::m_FramesPerSecond;

//----- (004586D0) --------------------------------------------------------  // acclient.c:148976
void __thiscall CameraSet::Closer(CameraSet *this, int keep_going, float i_fChangeModOverride)
{
  CameraSet *v3; // esi@1
  int v4; // eax@2
  CameraManager *v5; // ecx@4
  long double v6; // st7@7
  long double v7; // st6@9
  long double v8; // st6@10
  long double v9; // st6@12
  int v10; // eax@16
  _BYTE v11[12]; // ST00_12@16
  float camera_off; // [sp+0h] [bp-Ch]@4
  float camera_offa; // [sp+0h] [bp-Ch]@12
  float camera_off_4; // [sp+4h] [bp-8h]@4
  __int64 camera_off_4a; // [sp+4h] [bp-8h]@12
  float camera_off_8; // [sp+8h] [bp-4h]@4

  v3 = this;
  if ( i_fChangeModOverride != 0.0 )
  {
    v4 = this->looking_down;
    this->closer = keep_going;
    this->farther = 0;
    if ( v4 )
      CameraSet::LookDown(this, 0);
    v5 = v3->cm;
    camera_off = v5->viewer_offset.x;
    camera_off_8 = v5->viewer_offset.z;
    camera_off_4 = v5->viewer_offset.y;
    if ( camera_off != 0.0 || camera_off_4 != 0.18000001 || camera_off_8 != 0.0 )
    {
      v6 = *(double *)&Timer::cur_time;
      if ( v3->m_ttLastZoom == 0.0 )
        v3->m_ttLastZoom = COERCE_DOUBLE(Timer::cur_time.Cmd) - 1.0 / SceneTool::m_FramesPerSecond;
      v7 = v6 - v3->m_ttLastZoom;
      if ( v7 >= 0.00019999999 )
      {
        v8 = v7 * v5->m_rCameraAdjustmentSpeed;
        if ( i_fChangeModOverride != 1.0 )
          v8 = 1.0 / i_fChangeModOverride;
        v9 = 1.0 - v8 * 0.2;
        camera_offa = camera_off * v9;
        *(float *)&camera_off_4a = camera_off_4 * v9;
        *((float *)&camera_off_4a + 1) = v9 * camera_off_8;
        v3->m_ttLastZoom = v6;
        if ( sqrt(*(float *)&camera_off_4a * *(float *)&camera_off_4a + camera_offa * camera_offa + *((float *)&camera_off_4a + 1) * *((float *)&camera_off_4a + 1)) >= 0.5 )
        {
          if ( *((float *)&camera_off_4a + 1) <= -1.8 )
            CameraManager::SetStiffness(v5, 1.0);
          else
            CameraManager::SetStiffness(v5, v3->current_stiffness);
          v10 = (int)&v3->cm->viewer_offset;
          *(float *)v10 = camera_offa;
          *(_QWORD *)(v10 + 4) = camera_off_4a;
          *(_DWORD *)v11 = LODWORD(camera_offa);
          *(_QWORD *)&v11[4] = camera_off_4a;
          CameraSet::SetTargetForOffset(v3, *(AC1Legacy::Vector3 *)v11);
          if ( !keep_going )
          {
            v3->closer = 0;
            LODWORD(v3->m_ttLastZoom) = 0;
            HIDWORD(v3->m_ttLastZoom) = 0;
          }
        }
      }
    }
  }
}
// 837418: using guessed type float SceneTool::m_FramesPerSecond;

//----- (00458890) --------------------------------------------------------  // acclient.c:149047
void __thiscall CameraSet::Farther(CameraSet *this, int keep_going, float i_fChangeModOverride)
{
  CameraSet *v3; // esi@1
  int v4; // eax@1
  long double v5; // st7@3
  long double v6; // st6@5
  CameraManager *v7; // ecx@6
  SmartBox *v8; // edx@9
  unsigned int v9; // eax@9
  int v10; // ecx@10
  CameraManager *v11; // edi@11
  float v12; // ebx@11
  int v13; // eax@13
  _BYTE v14[12]; // ST00_12@13
  long double v15; // st6@15
  long double v16; // st6@17
  float camera_off; // [sp+10h] [bp-18h]@6
  float camera_off_4; // [sp+14h] [bp-14h]@6
  signed __int64 camera_off_4a; // [sp+14h] [bp-14h]@9
  float camera_off_8; // [sp+18h] [bp-10h]@6

  v3 = this;
  v4 = this->looking_down;
  this->farther = keep_going;
  this->closer = 0;
  if ( v4 )
    CameraSet::LookDown(this, 0);
  v5 = *(double *)&Timer::cur_time;
  if ( v3->m_ttLastZoom == 0.0 )
    v3->m_ttLastZoom = COERCE_DOUBLE(Timer::cur_time.Cmd) - 1.0 / SceneTool::m_FramesPerSecond;
  v6 = v5 - v3->m_ttLastZoom;
  if ( v6 >= 0.00019999999 )
  {
    v7 = v3->cm;
    camera_off = v7->viewer_offset.x;
    camera_off_8 = v7->viewer_offset.z;
    camera_off_4 = v7->viewer_offset.y;
    if ( camera_off == 0.0 && camera_off_4 == 0.18000001 && camera_off_8 == 0.0 )
    {
      v8 = v3->sbox;
      v3->m_ttLastZoom = v5;
      v9 = v8->player_id;
      camera_off_4a = 4539628427595585946i64;
      if ( v9 )
      {
        CameraManager::SetPivotObject(v7, v9, -1);
        v10 = (int)&v3->cm->pivot_offset;
        *(_DWORD *)v10 = 0;
        *(_DWORD *)(v10 + 4) = 0;
        *(_DWORD *)(v10 + 8) = LODWORD(CAMERA_DEFAULT_PIVOT_Z);
      }
      v11 = v3->cm;
      v12 = v3->current_stiffness;
      if ( CameraManager::SetTranslationalStiffness(v11, v3->current_stiffness) )
        CameraManager::SetRotationalStiffness(v11, v12);
      goto LABEL_13;
    }
    v15 = v6 * v7->m_rCameraAdjustmentSpeed;
    if ( i_fChangeModOverride != 1.0 )
      v15 = i_fChangeModOverride;
    v16 = v15 * 0.2 + 1.0;
    camera_off = camera_off * v16;
    *(float *)&camera_off_4a = camera_off_4 * v16;
    *((float *)&camera_off_4a + 1) = v16 * camera_off_8;
    v3->m_ttLastZoom = v5;
    if ( fabs(camera_off) <= 10.0 && fabs(*(float *)&camera_off_4a) <= 10.0 && *((float *)&camera_off_4a + 1) <= 450.0 )
    {
      if ( *((float *)&camera_off_4a + 1) <= -1.8 )
        CameraManager::SetStiffness(v7, 1.0);
      else
        CameraManager::SetStiffness(v7, v3->current_stiffness);
LABEL_13:
      v13 = (int)&v3->cm->viewer_offset;
      *(float *)v13 = camera_off;
      *(_QWORD *)(v13 + 4) = camera_off_4a;
      *(_DWORD *)v14 = LODWORD(camera_off);
      *(_QWORD *)&v14[4] = camera_off_4a;
      CameraSet::SetTargetForOffset(v3, *(AC1Legacy::Vector3 *)v14);
      if ( !keep_going )
      {
        v3->farther = 0;
        LODWORD(v3->m_ttLastZoom) = 0;
        HIDWORD(v3->m_ttLastZoom) = 0;
      }
      return;
    }
  }
}
// 837418: using guessed type float SceneTool::m_FramesPerSecond;

//----- (00458AE0) --------------------------------------------------------  // acclient.c:149138
void __thiscall CameraSet::UpdateCamera(CameraSet *this)
{
  CameraSet *v1; // esi@1
  CPhysicsObj *v2; // ecx@17
  double v3; // st7@19
  CPhysicsObj *v4; // ecx@26
  CPhysicsObj *v5; // ecx@28
  int v6; // [sp-10h] [bp-5Ch]@3
  Position pos; // [sp+4h] [bp-48h]@18

  v1 = this;
  if ( ((int (*)(void))this->sbox->cmdinterp->vfptr[17].OnLoseFocus)() )
    return;
  if ( v1->rot_left )
  {
    v6 = 1;
LABEL_6:
    CameraSet::Rotate(v1, v6, 1, 1.0, 1);
    goto LABEL_7;
  }
  if ( v1->rot_right )
  {
    v6 = 0;
    goto LABEL_6;
  }
LABEL_7:
  if ( v1->closer )
  {
    CameraSet::Closer(v1, 1, 1.0);
  }
  else if ( v1->farther )
  {
    CameraSet::Farther(v1, 1, 1.0);
  }
  if ( v1->raise )
  {
    CameraSet::Raise(v1, 1, 1.0);
  }
  else if ( v1->lower )
  {
    CameraSet::Lower(v1, 1, 1.0);
  }
  if ( v1->sbox->player )
  {
    if ( CameraSet::InHead(v1) )
    {
      v2 = v1->sbox->player;
      LODWORD(t) = 1065353216;
      CPhysicsObj::SetTranslucencyHierarchical(v2, 1.0);
    }
    else
    {
      Position::Position(&pos);
      if ( CameraManager::QueryPivotPosition(v1->cm, &pos) )
      {
        v3 = Position::distance(&pos, &v1->sbox->viewer);
        if ( v3 >= 0.44999999 )
        {
          if ( t > 0.0 )
          {
            v4 = v1->sbox->player;
            LODWORD(t) = 0;
            CPhysicsObj::SetTranslucencyHierarchical(v4, 0.0);
          }
        }
        else
        {
          t = 1.0 - (0.2 - v3) / (0.2 - 0.44999999);
          if ( t >= 0.0 )
          {
            if ( t > 1.0 )
              LODWORD(t) = 1065353216;
          }
          else
          {
            LODWORD(t) = 0;
          }
          CPhysicsObj::SetTranslucencyHierarchical(v1->sbox->player, t);
        }
      }
      else if ( t > 0.0 )
      {
        v5 = v1->sbox->player;
        LODWORD(t) = 0;
        CPhysicsObj::SetTranslucencyHierarchical(v5, 0.0);
      }
    }
  }
}

//----- (00458CE0) --------------------------------------------------------  // acclient.c:149229
void __thiscall CameraSet::SetInHead(CameraSet *this)
{
  CameraSet *v1; // esi@1
  CameraManager *v2; // ecx@3
  CameraManager *v3; // ecx@3
  float v4; // edx@3
  _BYTE v5[12]; // ST00_12@3
  AC1Legacy::Vector3 camera_off; // [sp+4h] [bp-Ch]@3

  v1 = this;
  if ( this->looking_down )
    CameraSet::LookDown(this, 0);
  CameraManager::SetTranslationalStiffness(v1->cm, 1.0);
  v2 = v1->cm;
  LODWORD(camera_off.x) = 0;
  LODWORD(camera_off.y) = 1065353216;
  LODWORD(camera_off.z) = 0;
  CameraManager::SetTargetDirection(v2, &camera_off);
  v3 = v1->cm;
  camera_off.y = 0.18000001;
  v3 = (CameraManager *)((char *)v3 + 72);
  camera_off.z = 0.0;
  LODWORD(camera_off.x) = 0;
  v3->vfptr = 0;
  v4 = camera_off.z;
  *(float *)&v3->vfptr = 0.18000001;
  v3->t_stiffness = v4;
  *(float *)&v5[4] = 0.18000001;
  *(_DWORD *)v5 = 0;
  *(float *)&v5[8] = 0.0;
  CameraSet::SetTargetForOffset(v1, *(AC1Legacy::Vector3 *)v5);
}

//----- (00458D80) --------------------------------------------------------  // acclient.c:149263
void __thiscall CameraSet::MouseLookHandler(CameraSet *this, int i_nXMove, int i_nYMove)
{
  CInputManager *v3; // edi@1
  CameraSet *v4; // esi@1
  SmartBox *v5; // edx@5
  float v6; // ST04_4@6
  float _DeltaX; // ST00_4@6
  double v8; // st7@6
  bool v9; // al@6
  int v10; // eax@12
  CameraSet *v11; // ecx@12
  int v12; // eax@15
  float v13; // ST10_4@25
  int _DeltaY; // [sp+4h] [bp-24h]@13
  float i_fChangeModOverride; // [sp+Ch] [bp-1Ch]@12
  float MouseSmoothingAmount; // [sp+1Ch] [bp-Ch]@1
  double curTime; // [sp+20h] [bp-8h]@4

  v3 = ICIDM::s_cidm;
  MouseSmoothingAmount = ICIDM::s_cidm->m_MouseLookSmoothingAmount;
  v4 = this;
  if ( *(float *)&i_nXMove == 0.0 && *(float *)&i_nYMove == 0.0 )
  {
    if ( !ICIDM::s_cidm->m_UseMouseTurning )
      return;
    curTime = *(double *)&Timer::cur_time;
    ((void (*)(void))this->sbox->cmdinterp->vfptr[13].OnLoseFocus)();
    if ( v4->m_LastServerMessage + 0.5 < curTime )
    {
      v5 = v4->sbox;
      v4->m_LastServerMessage = curTime;
      ((void (*)(void))v5->cmdinterp->vfptr[6].OnAction)();
    }
  }
  v6 = (double)i_nYMove;
  _DeltaX = (double)i_nXMove;
  CameraSet::FilterMouseInput(_DeltaX, v6, MouseSmoothingAmount, (float *)&i_nYMove, (float *)&i_nXMove);
  v8 = v3->m_MouseLookSensitivity;
  v9 = v3->m_InvertMouseLookYAxis;
  *(float *)&i_nYMove = *(float *)&i_nYMove * v8 * 0.06666667;
  *(float *)&i_nXMove = v8 * *(float *)&i_nXMove * 0.06666667;
  if ( v9 )
  {
    *(float *)&i_nXMove = -*(float *)&i_nXMove;
    *(float *)&i_nYMove = -*(float *)&i_nYMove;
  }
  if ( *(float *)&i_nYMove == 0.0 )
  {
    v4->mouselook_x_extent = 0;
    goto LABEL_19;
  }
  ++v4->mouselook_x_extent;
  if ( v4->mouselook_x_extent > 5 )
  {
    if ( *(float *)&i_nYMove <= 0.0 )
    {
      if ( *(float *)&i_nYMove >= 0.0 )
        goto LABEL_19;
      v12 = CameraSet::InHead(v4);
      i_fChangeModOverride = fabs(*(float *)&i_nYMove);
      v11 = v4;
      if ( v12 )
      {
        _DeltaY = 0;
        goto LABEL_18;
      }
    }
    else
    {
      v10 = CameraSet::InHead(v4);
      i_fChangeModOverride = fabs(*(float *)&i_nYMove);
      v11 = v4;
      if ( !v10 )
      {
        _DeltaY = 0;
LABEL_18:
        CameraSet::Rotate(v11, _DeltaY, 0, i_fChangeModOverride, 0);
        goto LABEL_19;
      }
    }
    _DeltaY = 1;
    goto LABEL_18;
  }
LABEL_19:
  if ( *(float *)&i_nXMove == 0.0 )
  {
    v4->mouselook_y_extent = 0;
  }
  else
  {
    ++v4->mouselook_y_extent;
    if ( v4->mouselook_y_extent > 5 )
    {
      if ( *(float *)&i_nXMove <= 0.0 )
      {
        if ( *(float *)&i_nXMove < 0.0 )
        {
          v13 = fabs(*(float *)&i_nXMove);
          CameraSet::Raise(v4, 0, v13);
        }
      }
      else
      {
        CameraSet::Lower(v4, 0, *(float *)&i_nXMove);
      }
    }
  }
}

//----- (00458F80) --------------------------------------------------------  // acclient.c:149373
void __thiscall CameraSet::SetDefaultOffsets(CameraSet *this, int move_camera)
{
  CameraSet *v2; // esi@1
  CameraManager *v3; // ecx@6
  unsigned int v4; // eax@6
  CameraManager *v5; // ecx@7
  float v6; // edx@7
  CameraManager *v7; // ecx@8
  CameraManager *v8; // edi@8
  float v9; // ebx@8
  double v10; // st7@10
  int v11; // edx@10
  float v12; // ecx@10
  double v13; // st6@10
  float v14; // eax@10
  _BYTE v15[12]; // ST00_12@10
  AC1Legacy::Vector3 camera_off; // [sp+10h] [bp-Ch]@7
  int move_cameraa; // [sp+20h] [bp+4h]@6

  v2 = this;
  if ( move_camera )
  {
    if ( this->looking_down )
      CameraSet::LookDown(this, 0);
    if ( CameraSet::InHead(v2) )
      CameraSet::Farther(v2, 0, 1.0);
    v3 = v2->cm;
    *(float *)&move_cameraa = v3->scale;
    v4 = v2->sbox->player_id;
    if ( v4 )
    {
      CameraManager::SetPivotObject(v3, v4, -1);
      v5 = v2->cm;
      LODWORD(camera_off.x) = 0;
      v5 = (CameraManager *)((char *)v5 + 24);
      camera_off.z = CAMERA_DEFAULT_PIVOT_Z;
      v5->vfptr = 0;
      v6 = camera_off.z;
      LODWORD(camera_off.y) = 0;
      v5->vfptr = 0;
      v5->t_stiffness = v6;
    }
    v7 = v2->cm;
    LODWORD(camera_off.x) = 0;
    LODWORD(camera_off.y) = 1065353216;
    LODWORD(camera_off.z) = 0;
    CameraManager::SetTargetDirection(v7, &camera_off);
    v8 = v2->cm;
    v9 = v2->current_stiffness;
    if ( CameraManager::SetTranslationalStiffness(v8, v9) )
      CameraManager::SetRotationalStiffness(v8, v9);
    v10 = -2.5 * *(float *)&move_cameraa;
    v11 = (int)&v2->cm->viewer_offset;
    camera_off.y = v10;
    v12 = camera_off.y;
    LODWORD(camera_off.x) = 0;
    v13 = 0.75 * *(float *)&move_cameraa;
    *(_DWORD *)v11 = 0;
    camera_off.z = v13;
    v14 = camera_off.z;
    *(float *)(v11 + 4) = v12;
    *(float *)(v11 + 8) = v14;
    *(float *)&v15[4] = v10;
    *(float *)&v15[8] = v13;
    *(_DWORD *)v15 = 0;
    CameraSet::SetTargetForOffset(v2, *(AC1Legacy::Vector3 *)v15);
  }
}

//----- (004590C0) --------------------------------------------------------  // acclient.c:149443
void __thiscall CameraSet::CameraSet(CameraSet *this, SmartBox *_sbox)
{
  CameraSet *v2; // esi@1
  CameraManager *v3; // ecx@1

  v2 = this;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CameraSet::vftable;
  this->sbox = _sbox;
  this->looking_down = 0;
  this->in_map_mode = 0;
  this->mouselook_active = 0;
  this->camera_movement_active = 0;
  this->targeting = 0;
  this->rot_left = 0;
  this->rot_right = 0;
  this->lower = 0;
  this->raise = 0;
  this->farther = 0;
  this->closer = 0;
  this->mouselook_x_extent = 0;
  this->mouselook_y_extent = 0;
  *(_QWORD *)&this->m_ttLastRotate = 0i64;
  *(_QWORD *)&this->m_ttLastRaiseOrLower = 0i64;
  *(_QWORD *)&this->m_ttLastZoom = 0i64;
  *(_QWORD *)&this->m_LastServerMessage = 0i64;
  *(_QWORD *)&this->m_LastMouseMovement = 0i64;
  v3 = _sbox->camera_manager;
  v2->cm = v3;
  CameraManager::SetCameraSet(v3, v2);
  v2->current_stiffness = v2->cm->t_stiffness;
  CameraSet::SetDefaultOffsets(v2, 1);
}
// 79BC84: using guessed type int (__thiscall *CameraSet::vftable)(void *, char);

//----- (00459150) --------------------------------------------------------  // acclient.c:149479
CameraSet *__thiscall CameraSet::vector_deleting_destructor(CameraSet *this, unsigned int a2)
{
  CameraSet *v2; // esi@1

  v2 = this;
  this->rot_left = 0;
  this->rot_right = 0;
  this->closer = 0;
  this->farther = 0;
  this->raise = 0;
  this->lower = 0;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);

//----- (006EAA70) --------------------------------------------------------  // acclient.c:766586
void _E91_30()
{
  outside_val_22 = 1000.0 + 1.0;
}

//----- (006EAA90) --------------------------------------------------------  // acclient.c:766592
void _E93_10()
{
  block_length_22 = 24.0 * 8.0;
}

//----- (006EAAB0) --------------------------------------------------------  // acclient.c:766598
void _E95_10()
{
  half_square_length_22 = 24.0 * 0.5;
}

//----- (006EAAD0) --------------------------------------------------------  // acclient.c:766604
void _E97_29()
{
  DEFAULT_VIEW_RADIUS_9 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EAAF0) --------------------------------------------------------  // acclient.c:766610
void _E99_6()
{
  MIN_QUANTUM_9 = 1.0 / 30.0;
}

//----- (006EAB10) --------------------------------------------------------  // acclient.c:766616
void _E101_2()
{
  MAX_QUANTUM_9 = 1.0 / 5.0;
}

//----- (006EAB30) --------------------------------------------------------  // acclient.c:766622
void _E103_15()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_36, PFID_A8R8G8B8);
}

//----- (006EAB40) --------------------------------------------------------  // acclient.c:766628
int _E105_8()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_6, "Display.Resolution");
  return atexit(sub_75D060);
}

//----- (006EAB60) --------------------------------------------------------  // acclient.c:766635
int _E108_9()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_6, "Display.FullScreen");
  return atexit(sub_75D090);
}

//----- (006EAB80) --------------------------------------------------------  // acclient.c:766642
int _E111_10()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_6, "Display.RefreshRate");
  return atexit(sub_75D0C0);
}

//----- (006EABA0) --------------------------------------------------------  // acclient.c:766649
int _E114_11()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_6, "Display.SyncToRefresh");
  return atexit(sub_75D0F0);
}

//----- (006EABC0) --------------------------------------------------------  // acclient.c:766656
void _E117_10()
{
  LOWEST_DATA_RATE_56 = 1024;
}

//----- (006EABD0) --------------------------------------------------------  // acclient.c:766662
void _E119_0()
{
  HIGHEST_DATA_RATE_56 = 0x7FFF;
}

//----- (006EABE0) --------------------------------------------------------  // acclient.c:766668
int _E121_15()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_56;
  INITIAL_MAX_DATA_RATE_4 = LOWEST_DATA_RATE_56;
  return result;
}

//----- (006EABF0) --------------------------------------------------------  // acclient.c:766678
void _E123_10()
{
  angle = 3.1415927 / (180.0 / 8.0);
}

//----- (006EAC10) --------------------------------------------------------  // acclient.c:766684
int _E1_51()
{
  return atexit(_E2_51);
}

//----- (0075D060) --------------------------------------------------------  // acclient.c:885156
void __cdecl sub_75D060()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D090) --------------------------------------------------------  // acclient.c:885169
void __cdecl sub_75D090()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D0C0) --------------------------------------------------------  // acclient.c:885182
void __cdecl sub_75D0C0()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D0F0) --------------------------------------------------------  // acclient.c:885195
void __cdecl sub_75D0F0()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

