/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SmartBox
   Object     : PORTAL\smartbox\SmartBox.obj
   Functions  : 223
   Addresses  : 00451A20 - 0075C050 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00451A20) --------------------------------------------------------  // acclient.c:142983
void __thiscall RGBColor::SetColor32(RGBColor *this, const unsigned int color)
{
  this->r = (double)((color >> 16) & 0xFF) * 0.0039215689;
  this->g = (double)((unsigned __int16)color >> 8) * 0.0039215689;
  this->b = (double)(unsigned __int8)color * 0.0039215689;
}

//----- (00451AA0) --------------------------------------------------------  // acclient.c:142991
void __thiscall Vector3::operator=/(Vector3 *this, const float _rhs)
{
  double v2; // st7@1

  v2 = 1.0 / _rhs;
  this->x = v2 * this->x;
  this->y = v2 * this->y;
  this->z = v2 * this->z;
}

//----- (00451AD0) --------------------------------------------------------  // acclient.c:143002
int __cdecl CPhysicsObj::is_newer(unsigned __int16 timestamp, unsigned __int16 new_time)
{
  int result; // eax@2

  if ( abs(new_time - timestamp) > 0x7FFF )
    result = new_time < timestamp;
  else
    result = timestamp < new_time;
  return result;
}

//----- (00451B10) --------------------------------------------------------  // acclient.c:143014
int __thiscall CPhysicsObj::newer_event(CPhysicsObj *this, PhysicsTimeStamp stamp, unsigned __int16 new_time)
{
  unsigned __int16 v3; // si@1
  __int64 v4; // rax@1
  bool v5; // cf@2
  int result; // eax@5

  v3 = this->update_times[stamp];
  v4 = new_time - this->update_times[stamp];
  if ( (signed int)((HIDWORD(v4) ^ v4) - HIDWORD(v4)) > 0x7FFF )
    v5 = new_time < v3;
  else
    v5 = v3 < new_time;
  if ( v5 )
  {
    this->update_times[stamp] = new_time;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00451B70) --------------------------------------------------------  // acclient.c:143040
signed int __stdcall SmartBox::DispatchSmartBoxEvent(NetBlob *blob)
{
  return 3;
}

//----- (00451B80) --------------------------------------------------------  // acclient.c:143046
int __thiscall SmartBox::get_player_visualdesc(SmartBox *this)
{
  return ((int (*)(void))this->m_pObjMaint->vfptr[2].IUnknown_AddRef)();
}

//----- (00451B90) --------------------------------------------------------  // acclient.c:143052
void __thiscall SmartBox::QueueBlobForObject(SmartBox *this, unsigned int object_id, NetBlob *blob)
{
  CObjectMaint::QueueBlobForObject(this->m_pObjMaint, object_id, blob);
}

//----- (00451BA0) --------------------------------------------------------  // acclient.c:143058
void __cdecl SmartBox::set_selected_object_id(unsigned int _id)
{
  CPhysicsPart::viewcone_check_object_id = _id;
}
// 843BEC: using guessed type unsigned __int32 CPhysicsPart::viewcone_check_object_id;

//----- (00451BB0) --------------------------------------------------------  // acclient.c:143065
bool __cdecl SmartBox::is_selected_object_in_view()
{
  return CPhysicsPart::selected_object_in_view != 0;
}
// 843BF0: using guessed type int CPhysicsPart::selected_object_in_view;

//----- (00451BC0) --------------------------------------------------------  // acclient.c:143072
void __thiscall SmartBox::SetOverrideFovDistance(SmartBox *this, bool fEnable, float i_vdst)
{
  this->m_bUseViewDistance = fEnable;
  this->m_fViewDistFOV = i_vdst;
}

//----- (00451BE0) --------------------------------------------------------  // acclient.c:143079
double __thiscall SmartBox::GetOverrideFovDistance(SmartBox *this)
{
  double result; // st7@2

  if ( this->m_bUseViewDistance )
    result = this->m_fViewDistFOV;
  else
    result = 1.0 / tan(this->m_fGameFOV / (RenderDevice::render_device->m_ViewportAspectRatio - 0.1) * 0.5);
  return result;
}

//----- (00451C20) --------------------------------------------------------  // acclient.c:143091
BOOL __thiscall SmartBox::teleport_in_progress(SmartBox *this)
{
  return this->player && !this->position_update_complete;
}

//----- (00451C40) --------------------------------------------------------  // acclient.c:143097
int __thiscall SmartBox::teleport_occured(SmartBox *this)
{
  int result; // eax@1

  result = this->has_been_teleported;
  this->has_been_teleported = 0;
  return result;
}

//----- (00451C60) --------------------------------------------------------  // acclient.c:143107
char __cdecl SmartBox::find_object(unsigned int _mouseX, unsigned int _mouseY)
{
  int v2; // eax@1
  int v3; // ecx@1
  char result; // al@3

  SmartBox::m_cxWindowFindPos = _mouseX;
  SmartBox::m_cyWindowFindPos = _mouseY;
  SmartBox::click_object_id = 0;
  SmartBox::click_object_index = -1;
  v2 = _mouseX - RenderDevice::render_device->m_viewportX;
  v3 = _mouseY - RenderDevice::render_device->m_viewportY;
  if ( v2 >= RenderDevice::render_device->m_viewportWidth || v3 >= RenderDevice::render_device->m_viewportHeight )
  {
    Render::clear_selection_cursor();
    result = 0;
  }
  else
  {
    Render::set_selection_cursor(v2, v3, 1);
    CPhysicsPart::selected_object_in_view = 0;
    SmartBox::lookingForObject = 1;
    result = 1;
  }
  return result;
}
// 818618: using guessed type int SmartBox::click_object_index;
// 83CA44: using guessed type unsigned __int32 SmartBox::click_object_id;
// 83CA48: using guessed type bool SmartBox::lookingForObject;
// 83CA50: using guessed type unsigned __int32 SmartBox::m_cyWindowFindPos;
// 843BF0: using guessed type int CPhysicsPart::selected_object_in_view;

//----- (00451CE0) --------------------------------------------------------  // acclient.c:143140
unsigned __int32 __cdecl SmartBox::get_found_object_id()
{
  return SmartBox::click_object_id;
}
// 83CA44: using guessed type unsigned __int32 SmartBox::click_object_id;

//----- (00451CF0) --------------------------------------------------------  // acclient.c:143147
void __cdecl SmartBox::set_found_object(unsigned int iid, unsigned int index)
{
  SmartBox::click_object_id = iid;
  SmartBox::click_object_index = index;
  ECM_UI::SendNotice_SmartBoxObjectFound(iid);
}
// 818618: using guessed type int SmartBox::click_object_index;
// 83CA44: using guessed type unsigned __int32 SmartBox::click_object_id;

//----- (00451D10) --------------------------------------------------------  // acclient.c:143157
void __thiscall SmartBox::SetTargettingCallback(SmartBox *this, void (__cdecl *targetting_callback_func)(unsigned int, ObjectSelectStatus, tagRECT *, const float))
{
  this->target_callback = targetting_callback_func;
}

//----- (00451D20) --------------------------------------------------------  // acclient.c:143163
void __thiscall SmartBox::SetTargetObjectID(SmartBox *this, unsigned int new_target_object_id)
{
  this->target_object_id = new_target_object_id;
}

//----- (00451D30) --------------------------------------------------------  // acclient.c:143169
void __thiscall SmartBox::Show(SmartBox *this)
{
  this->hidden = 0;
}

//----- (00451D40) --------------------------------------------------------  // acclient.c:143175
void __thiscall SmartBox::Hide(SmartBox *this)
{
  this->hidden = 1;
}

//----- (00451D50) --------------------------------------------------------  // acclient.c:143181
int __stdcall SmartBox::SetMode(int _x, int _y, int _width, int _height)
{
  int result; // eax@4

  if ( Render::Set3DView(_x, _y, _width, _height) )
  {
    if ( SmartBox::lookingForObject )
      SmartBox::find_object(SmartBox::m_cxWindowFindPos, SmartBox::m_cxWindowFindPos);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 83CA48: using guessed type bool SmartBox::lookingForObject;

//----- (00451DA0) --------------------------------------------------------  // acclient.c:143200
void __cdecl SmartBox::DisableDegrades(int disable)
{
  degrades_disabled = disable;
}
// 8442E4: using guessed type int degrades_disabled;

//----- (00451DB0) --------------------------------------------------------  // acclient.c:143207
void __cdecl SmartBox::DisableFogging(int disable)
{
  RenderDeviceD3D::SetFFFogSystemDisabled((RenderDeviceD3D *)RenderDevice::render_device, disable != 0);
}

//----- (00451DD0) --------------------------------------------------------  // acclient.c:143213
void __stdcall SmartBox::EnableWeather(int enable)
{
  LScape::weather_enabled = enable != 0;
}
// 81CBE9: using guessed type bool LScape::weather_enabled;

//----- (00451DF0) --------------------------------------------------------  // acclient.c:143220
char __thiscall SmartBox::SetDetailTexturing(SmartBox *this, bool landscape, bool environment)
{
  LScape *v3; // ecx@1
  char result; // al@1

  v3 = this->lscape;
  result = 0;
  if ( v3 )
    result = LScape::SetDetailTexturing(v3, landscape, environment, environment, 0);
  return result;
}

//----- (00451E20) --------------------------------------------------------  // acclient.c:143233
BOOL __stdcall SmartBox::HandleRenderOption(int argc, char **argv, const char **status_string, const char **textbox_string)
{
  *status_string = 0;
  *textbox_string = 0;
  return GraphicsOptions::HandleRenderOption(argc, argv, status_string, textbox_string) != 0;
}

//----- (00451E60) --------------------------------------------------------  // acclient.c:143241
void __thiscall SmartBox::SetDefaultFov(SmartBox *this, float degrees)
{
  this->m_fGameFOV = degrees * 0.0174532925199433;
}

//----- (00451E80) --------------------------------------------------------  // acclient.c:143247
int __thiscall SmartBox::is_player_outside(SmartBox *this)
{
  CPhysicsObj *v1; // eax@1
  int result; // eax@2

  v1 = this->player;
  if ( v1 )
    result = (v1->m_position.objcell_id & 0xFFFF) < 0x100;
  else
    result = 0;
  return result;
}

//----- (00451EA0) --------------------------------------------------------  // acclient.c:143261
signed int __thiscall SmartBox::HandleDeleteObject(SmartBox *this, NetBlob *blob, unsigned int object_id, unsigned __int16 instance_timestamp)
{
  SmartBox *v4; // edi@1
  signed int result; // eax@2
  HashBaseData<unsigned long> *v6; // eax@3
  unsigned __int16 v7; // cx@4
  __int64 v8; // rax@4
  bool v9; // cf@5

  v4 = this;
  if ( object_id == this->player_id )
  {
    result = 3;
  }
  else
  {
    v6 = CObjectMaint::GetObjectA(this->m_pObjMaint, object_id);
    if ( !v6
      || ((v7 = LOWORD(v6[31].vfptr),
           v8 = instance_timestamp - LOWORD(v6[31].vfptr),
           (signed int)((HIDWORD(v8) ^ v8) - HIDWORD(v8)) > 0x7FFF) ? (v9 = instance_timestamp < v7) : (v9 = v7 < instance_timestamp),
          v9) )
    {
      CObjectMaint::QueueBlobForObject(v4->m_pObjMaint, object_id, blob);
      result = 4;
    }
    else if ( v7 == instance_timestamp )
    {
      v4->m_pObjMaint->vfptr[1].IUnknown_AddRef((Interface *)object_id);
      result = 1;
    }
    else
    {
      result = 2;
    }
  }
  return result;
}

//----- (00451F40) --------------------------------------------------------  // acclient.c:143301
int __thiscall SmartBox::UpdateVisualDesc(SmartBox *this, CPhysicsObj *object, VisualDesc *vdesc, unsigned __int16 vdesc_ts)
{
  unsigned __int16 v4; // di@1
  SmartBox *v5; // ebx@1
  __int64 v6; // rax@1
  bool v7; // cf@2
  int result; // eax@7

  v4 = object->update_times[7];
  v5 = this;
  v6 = vdesc_ts - object->update_times[7];
  if ( (signed int)((HIDWORD(v6) ^ v6) - HIDWORD(v6)) > 0x7FFF )
    v7 = vdesc_ts < v4;
  else
    v7 = v4 < vdesc_ts;
  if ( v7 )
  {
    object->update_times[7] = vdesc_ts;
    ((void (__stdcall *)(CPhysicsObj *, VisualDesc *))this->m_pObjMaint->vfptr[1].QueryInterface)(object, vdesc);
    if ( object == v5->player )
      ((void (__stdcall *)(VisualDesc *))v5->m_pObjMaint->vfptr[2].IUnknown_QueryInterface)(vdesc);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00451FC0) --------------------------------------------------------  // acclient.c:143332
signed int __thiscall SmartBox::HandleSoundEvent(SmartBox *this, NetBlob *blob, unsigned int object_id, int sound, float volume)
{
  SmartBox *v5; // esi@1
  HashBaseData<unsigned long> *v6; // eax@1
  signed int result; // eax@2

  v5 = this;
  v6 = CObjectMaint::GetObjectA(this->m_pObjMaint, object_id);
  if ( v6 )
  {
    result = CPhysicsObj::play_sound((CPhysicsObj *)v6, (SoundType)sound, volume) != 0 ? 1 : 3;
  }
  else
  {
    CObjectMaint::QueueBlobForObject(v5->m_pObjMaint, object_id, blob);
    result = 4;
  }
  return result;
}

//----- (00452020) --------------------------------------------------------  // acclient.c:143353
signed int __thiscall SmartBox::HandlePlayScriptID(SmartBox *this, NetBlob *blob, unsigned int object_id, IDClass<_tagDataID,32,0> script_id)
{
  SmartBox *v4; // esi@1
  HashBaseData<unsigned long> *v5; // eax@1
  signed int result; // eax@2

  v4 = this;
  v5 = CObjectMaint::GetObjectA(this->m_pObjMaint, object_id);
  if ( v5 )
  {
    result = CPhysicsObj::play_script((CPhysicsObj *)v5, script_id) != 0 ? 1 : 3;
  }
  else
  {
    CObjectMaint::QueueBlobForObject(v4->m_pObjMaint, object_id, blob);
    result = 4;
  }
  return result;
}

//----- (00452070) --------------------------------------------------------  // acclient.c:143374
signed int __thiscall SmartBox::HandlePlayScriptType(SmartBox *this, NetBlob *blob, unsigned int object_id, int script_type, float mod)
{
  SmartBox *v5; // esi@1
  HashBaseData<unsigned long> *v6; // eax@1
  signed int result; // eax@2

  v5 = this;
  v6 = CObjectMaint::GetObjectA(this->m_pObjMaint, object_id);
  if ( v6 )
  {
    result = CPhysicsObj::play_script((CPhysicsObj *)v6, (PScriptType)script_type, mod) != 0 ? 1 : 3;
  }
  else
  {
    CObjectMaint::QueueBlobForObject(v5->m_pObjMaint, object_id, blob);
    result = 4;
  }
  return result;
}

//----- (004520D0) --------------------------------------------------------  // acclient.c:143395
void __thiscall SmartBox::DoSetState(SmartBox *this, CPhysicsObj *object, unsigned int state, unsigned __int16 state_timestamp)
{
  SmartBox *v4; // ebx@1
  unsigned __int16 v5; // cx@1
  __int64 v6; // rax@1
  bool v7; // cf@2
  unsigned int v8; // eax@7

  v4 = this;
  v5 = object->update_times[2];
  v6 = state_timestamp - object->update_times[2];
  if ( (signed int)((HIDWORD(v6) ^ v6) - HIDWORD(v6)) > 0x7FFF )
    v7 = state_timestamp < v5;
  else
    v7 = v5 < state_timestamp;
  if ( v7 )
  {
    object->update_times[2] = state_timestamp;
    CPhysicsObj::set_state(object, state, 1);
    if ( object == v4->player )
    {
      if ( v4->waiting_for_teleport )
      {
        v8 = object->state;
        if ( !(BYTE1(v8) & 0x40) )
          v4->waiting_for_teleport = 0;
      }
    }
  }
}

//----- (00452150) --------------------------------------------------------  // acclient.c:143427
signed int __thiscall SmartBox::HandlePlayerTeleport(SmartBox *this, NetBlob *blob, unsigned __int16 physics_timestamp)
{
  CPhysicsObj *v3; // eax@1
  unsigned __int16 v4; // si@2
  bool v5; // cf@3
  signed int result; // eax@5

  v3 = this->player;
  if ( v3 )
  {
    v4 = v3->update_times[4];
    if ( abs(v4 - physics_timestamp) > 0x7FFF )
      v5 = v4 < physics_timestamp;
    else
      v5 = physics_timestamp < v4;
    result = 1;
    if ( !v5 )
    {
      this->position_update_complete = 0;
      this->has_been_teleported = 0;
      this->waiting_for_teleport = 1;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (004521C0) --------------------------------------------------------  // acclient.c:143458
void __thiscall SmartBox::DoVectorUpdate(SmartBox *this, CPhysicsObj *object, AC1Legacy::Vector3 *velocity, AC1Legacy::Vector3 *omega, unsigned __int16 vector_timestamp)
{
  unsigned __int16 v5; // si@1
  __int64 v6; // rax@1
  bool v7; // cf@2

  v5 = object->update_times[3];
  v6 = vector_timestamp - object->update_times[3];
  if ( (signed int)((HIDWORD(v6) ^ v6) - HIDWORD(v6)) > 0x7FFF )
    v7 = vector_timestamp < v5;
  else
    v7 = v5 < vector_timestamp;
  if ( v7 )
  {
    object->update_times[3] = vector_timestamp;
    if ( object != this->player || ((int (*)(void))this->cmdinterp->vfptr[8].__vecDelDtor)() )
    {
      CPhysicsObj::set_velocity(object, velocity, 1);
      CPhysicsObj::set_omega(object, omega, 1);
    }
  }
}

//----- (00452240) --------------------------------------------------------  // acclient.c:143482
void __stdcall SmartBox::DoPickupEvent(CPhysicsObj *object, unsigned __int16 position_timestamp)
{
  unsigned __int16 v3; // cx@1
  __int64 v4; // rax@1
  bool v5; // cf@2

  v3 = object->update_times[0];
  v4 = position_timestamp - object->update_times[0];
  if ( (signed int)((HIDWORD(v4) ^ v4) - HIDWORD(v4)) > 0x7FFF )
    v5 = position_timestamp < v3;
  else
    v5 = v3 < position_timestamp;
  if ( v5 )
  {
    object->update_times[0] = position_timestamp;
    CPhysicsObj::unset_parent(object);
    CPhysicsObj::leave_world(object);
  }
}

//----- (00452290) --------------------------------------------------------  // acclient.c:143503
void __thiscall SmartBox::DoParentEvent(SmartBox *this, CPhysicsObj *child, CPhysicsObj *parent, unsigned int child_location, unsigned int placement_id, unsigned __int16 position_stamp)
{
  unsigned __int16 v6; // si@1
  __int64 v7; // rax@1
  bool v8; // cf@2
  CPhysicsObj *v9; // eax@5
  HashBaseData<unsigned long> *v10; // eax@7

  v6 = child->update_times[0];
  v7 = position_stamp - child->update_times[0];
  if ( (signed int)((HIDWORD(v7) ^ v7) - HIDWORD(v7)) > 0x7FFF )
    v8 = position_stamp < v6;
  else
    v8 = v6 < position_stamp;
  if ( v8 )
  {
    v9 = child->parent;
    child->update_times[0] = position_stamp;
    if ( !v9 && parent->id != this->player_id )
    {
      v10 = CObjectMaint::GetWeenieObject(this->m_pObjMaint, parent->id);
      if ( v10 )
        v10->vfptr[3].__vecDelDtor(v10, 1u);
    }
    CPhysicsObj::set_parent(child, parent, child_location);
    CPhysicsObj::SetPlacementFrame(child, placement_id, 1);
  }
}

//----- (00452320) --------------------------------------------------------  // acclient.c:143533
bool __thiscall CreatureMode::InitializeScene(CreatureMode *this)
{
  CreatureMode *v1; // esi@1
  CEnvCell *v2; // eax@1
  CEnvCell *v3; // eax@2
  bool result; // al@2

  v1 = this;
  v2 = (CEnvCell *)operator new(0x148u);
  if ( v2 )
  {
    CEnvCell::CEnvCell(v2);
    v1->creature_cell = v3;
    result = v3 != 0;
  }
  else
  {
    result = 0;
    v1->creature_cell = 0;
  }
  return result;
}

//----- (00452360) --------------------------------------------------------  // acclient.c:143557
void __thiscall CreatureMode::SetCameraPosition(CreatureMode *this, AC1Legacy::Vector3 *i_position)
{
  this->creature_view_frame.m_fOrigin = *i_position;
}

//----- (00452380) --------------------------------------------------------  // acclient.c:143563
void __thiscall CreatureMode::UseSmartboxFOV(CreatureMode *this)
{
  this->m_bUseSmartboxFOV = 1;
}

//----- (00452390) --------------------------------------------------------  // acclient.c:143569
void __thiscall CreatureMode::UseSharpMode(CreatureMode *this)
{
  this->m_bUseSharpMode = 1;
}

//----- (004523A0) --------------------------------------------------------  // acclient.c:143575
double __cdecl MathLib::Clamp(const float _Number, const float _MinValue, const float _MaxValue)
{
  double result; // st7@2

  if ( _Number <= (double)_MaxValue )
  {
    if ( _Number >= (double)_MinValue )
      result = _Number;
    else
      result = _MinValue;
  }
  else
  {
    result = _MaxValue;
  }
  return result;
}

//----- (004523D0) --------------------------------------------------------  // acclient.c:143594
double __thiscall AC1Legacy::Vector3::magnitude(AC1Legacy::Vector3 *this)
{
  return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

//----- (00452400) --------------------------------------------------------  // acclient.c:143600
AC1Legacy::Vector3 *__thiscall AC1Legacy::Vector3::normalize(AC1Legacy::Vector3 *this, AC1Legacy::Vector3 *result)
{
  AC1Legacy::Vector3 *v2; // eax@1
  long double v3; // st4@1
  long double v4; // st6@1
  long double v5; // st7@1

  v2 = result;
  v3 = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
  v4 = 1.0 / v3 * this->x;
  this->x = v4;
  this->y = 1.0 / v3 * this->y;
  v5 = v4;
  this->z = 1.0 / v3 * this->z;
  result->x = v5;
  result->y = this->y;
  result->z = this->z;
  return v2;
}

//----- (00452460) --------------------------------------------------------  // acclient.c:143621
int __thiscall AC1Legacy::Vector3::normalize_check_small(AC1Legacy::Vector3 *this)
{
  long double v1; // st4@1
  int result; // eax@2

  v1 = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
  if ( v1 >= 0.00019999999 )
  {
    result = 0;
    this->x = 1.0 / v1 * this->x;
    this->y = 1.0 / v1 * this->y;
    this->z = 1.0 / v1 * this->z;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (004524C0) --------------------------------------------------------  // acclient.c:143642
AC1Legacy::Vector3 *__thiscall AC1Legacy::Vector3::operator-(AC1Legacy::Vector3 *this, AC1Legacy::Vector3 *result, AC1Legacy::Vector3 *b)
{
  double v3; // st7@1
  double v4; // st6@1
  AC1Legacy::Vector3 *v5; // eax@1

  v3 = this->z - b->z;
  v4 = this->y - b->y;
  v5 = result;
  result->x = this->x - b->x;
  result->y = v4;
  result->z = v3;
  return v5;
}

//----- (004524F0) --------------------------------------------------------  // acclient.c:143658
AC1Legacy::Vector3 *__thiscall Frame::localtoglobalvec(Frame *this, AC1Legacy::Vector3 *result, AC1Legacy::Vector3 *in)
{
  double v3; // st7@1
  double v4; // st6@1
  AC1Legacy::Vector3 *v5; // eax@1

  v3 = this->m_fl2gv[8] * in->z + this->m_fl2gv[2] * in->x + this->m_fl2gv[5] * in->y;
  v4 = this->m_fl2gv[7] * in->z + this->m_fl2gv[1] * in->x + this->m_fl2gv[4] * in->y;
  v5 = result;
  result->x = this->m_fl2gv[6] * in->z + this->m_fl2gv[0] * in->x + this->m_fl2gv[3] * in->y;
  result->y = v4;
  result->z = v3;
  return v5;
}

//----- (00452550) --------------------------------------------------------  // acclient.c:143674
AC1Legacy::Vector3 *__thiscall Frame::globaltolocalvec(Frame *this, AC1Legacy::Vector3 *result, AC1Legacy::Vector3 *in)
{
  double v3; // st7@1
  double v4; // st6@1
  AC1Legacy::Vector3 *v5; // eax@1

  v3 = this->m_fl2gv[8] * in->z + this->m_fl2gv[6] * in->x + this->m_fl2gv[7] * in->y;
  v4 = this->m_fl2gv[5] * in->z + this->m_fl2gv[3] * in->x + this->m_fl2gv[4] * in->y;
  v5 = result;
  result->x = this->m_fl2gv[2] * in->z + this->m_fl2gv[0] * in->x + this->m_fl2gv[1] * in->y;
  result->y = v4;
  result->z = v3;
  return v5;
}

//----- (004525B0) --------------------------------------------------------  // acclient.c:143690
void __thiscall Frame::rotate(Frame *this, AC1Legacy::Vector3 *w)
{
  AC1Legacy::Vector3 v2; // [sp+0h] [bp-Ch]@1

  v2.x = this->m_fl2gv[6] * w->z + this->m_fl2gv[0] * w->x + this->m_fl2gv[3] * w->y;
  v2.y = this->m_fl2gv[7] * w->z + this->m_fl2gv[1] * w->x + this->m_fl2gv[4] * w->y;
  v2.z = this->m_fl2gv[8] * w->z + this->m_fl2gv[2] * w->x + this->m_fl2gv[5] * w->y;
  Frame::grotate(this, &v2);
}

//----- (00452620) --------------------------------------------------------  // acclient.c:143701
AC1Legacy::Vector3 *__thiscall Frame::localtoglobal(Frame *this, AC1Legacy::Vector3 *result, AC1Legacy::Vector3 *in)
{
  double v3; // st7@1
  double v4; // st6@1
  AC1Legacy::Vector3 *v5; // eax@1

  v3 = this->m_fl2gv[8] * in->z + this->m_fl2gv[2] * in->x + this->m_fl2gv[5] * in->y + this->m_fOrigin.z;
  v4 = this->m_fl2gv[7] * in->z + this->m_fl2gv[1] * in->x + this->m_fl2gv[4] * in->y + this->m_fOrigin.y;
  v5 = result;
  result->x = this->m_fl2gv[6] * in->z + this->m_fl2gv[0] * in->x + this->m_fl2gv[3] * in->y + this->m_fOrigin.x;
  result->y = v4;
  result->z = v3;
  return v5;
}

//----- (00452680) --------------------------------------------------------  // acclient.c:143717
AC1Legacy::Vector3 *__thiscall Frame::globaltolocal(Frame *this, AC1Legacy::Vector3 *result, AC1Legacy::Vector3 *in)
{
  float v3; // ST00_4@1
  float v4; // ST04_4@1
  AC1Legacy::Vector3 *v5; // eax@1
  double v6; // st7@1
  float v7; // ST08_4@1
  double v8; // st7@1
  double v9; // st6@1

  v3 = in->x - this->m_fOrigin.x;
  v4 = in->y - this->m_fOrigin.y;
  v5 = result;
  v6 = in->z - this->m_fOrigin.z;
  v7 = v6;
  v8 = v6 * this->m_fl2gv[8] + v3 * this->m_fl2gv[6] + v4 * this->m_fl2gv[7];
  v9 = v7 * this->m_fl2gv[5] + v3 * this->m_fl2gv[3] + v4 * this->m_fl2gv[4];
  result->x = v7 * this->m_fl2gv[2] + v3 * this->m_fl2gv[0] + v4 * this->m_fl2gv[1];
  result->y = v9;
  result->z = v8;
  return v5;
}

//----- (00452700) --------------------------------------------------------  // acclient.c:143741
void __thiscall LIGHTINFO::SetDirection(LIGHTINFO *this, AC1Legacy::Vector3 *_direction)
{
  double v2; // st7@3
  double v3; // st6@3
  long double v4; // st5@3
  AC1Legacy::Vector3 normal; // [sp+0h] [bp-Ch]@3
  AC1Legacy::Vector3 *_directiona; // [sp+10h] [bp+4h]@3

  if ( this->type == 1 || this->type == 2 )
  {
    v2 = _direction->x;
    v3 = _direction->y;
    normal.z = _direction->z;
    v4 = 1.0 / sqrt(v2 * v2 + normal.z * normal.z + v3 * v3);
    *(float *)&_directiona = v4;
    normal.x = v4 * v2;
    normal.y = *(float *)&_directiona * v3;
    normal.z = *(float *)&_directiona * normal.z;
    Frame::set_vector_heading(&this->offset, &normal);
  }
}

//----- (00452780) --------------------------------------------------------  // acclient.c:143764
void __thiscall Position::Position(Position *this, unsigned int cellID, Frame *newFrame)
{
  this->vfptr = (PackObjVtbl *)&Position::vftable;
  this->objcell_id = cellID;
  Frame::operator=((int)&this->frame, (int)newFrame);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (004527B0) --------------------------------------------------------  // acclient.c:143773
unsigned int __thiscall Position::get_outside_cell_id(Position *this)
{
  float v1; // edx@1
  float v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@1
  unsigned int cell_id; // [sp+0h] [bp-10h]@1
  AC1Legacy::Vector3 loc; // [sp+4h] [bp-Ch]@1

  v1 = this->frame.m_fOrigin.y;
  loc.x = this->frame.m_fOrigin.x;
  v2 = this->frame.m_fOrigin.z;
  v3 = this->objcell_id;
  loc.y = v1;
  loc.z = v2;
  cell_id = v3;
  v4 = LandDefs::adjust_to_outside(&cell_id, &loc);
  return v4 != 0 ? cell_id : 0;
}

//----- (004527F0) --------------------------------------------------------  // acclient.c:143794
AC1Legacy::Vector3 *__thiscall Position::localtolocal(Position *this, AC1Legacy::Vector3 *result, Position *p, AC1Legacy::Vector3 *v)
{
  Position *v4; // esi@1
  float v5; // ST14_4@1
  float v6; // ST18_4@1
  float v7; // ST1C_4@1
  float v8; // ST1C_4@1
  AC1Legacy::Vector3 in; // [sp+14h] [bp-Ch]@1

  v4 = this;
  v5 = p->frame.m_fl2gv[3] * v->y + p->frame.m_fl2gv[0] * v->x + p->frame.m_fl2gv[6] * v->z + p->frame.m_fOrigin.x;
  v6 = p->frame.m_fl2gv[4] * v->y + p->frame.m_fl2gv[1] * v->x + p->frame.m_fl2gv[7] * v->z + p->frame.m_fOrigin.y;
  v7 = p->frame.m_fl2gv[5] * v->y + p->frame.m_fl2gv[2] * v->x + p->frame.m_fl2gv[8] * v->z + p->frame.m_fOrigin.z;
  LandDefs::get_block_offset(&in, this->objcell_id, p->objcell_id);
  v8 = in.z + v7;
  in.z = v8;
  in.x = in.x + v5;
  in.y = in.y + v6;
  Frame::globaltolocal(&v4->frame, result, &in);
  return result;
}

//----- (004528C0) --------------------------------------------------------  // acclient.c:143817
AC1Legacy::Vector3 *__thiscall Position::localtoglobal(Position *this, AC1Legacy::Vector3 *result, Position *p)
{
  AC1Legacy::Vector3 *v3; // eax@1
  double v4; // st6@1
  double v5; // st7@1
  AC1Legacy::Vector3 v6; // [sp+4h] [bp-Ch]@1

  LandDefs::get_block_offset(&v6, this->objcell_id, p->objcell_id);
  v3 = result;
  v4 = v6.y + p->frame.m_fOrigin.y;
  v5 = v6.z + p->frame.m_fOrigin.z;
  result->x = v6.x + p->frame.m_fOrigin.x;
  result->y = v4;
  result->z = v5;
  return v3;
}

//----- (00452910) --------------------------------------------------------  // acclient.c:143835
Frame *__thiscall CPhysicsObj::get_frame(CPhysicsObj *this)
{
  return &this->m_position.frame;
}

//----- (00452920) --------------------------------------------------------  // acclient.c:143841
void __thiscall Ambient::FlushSoundTables(Ambient *this)
{
  Ambient *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  AmbientSTBDesc *v4; // esi@2
  CSoundTable *v5; // ecx@2

  v1 = this;
  v2 = this->num_sounds;
  v3 = 0;
  LODWORD(this->total_sound_count) = 0;
  if ( v2 )
  {
    do
    {
      ((void (*)(void))v1->sounds.data[v3]->vfptr->ResetCount)();
      v4 = v1->sounds.data[v3]->desc;
      v5 = v4->sound_table;
      if ( v5 )
      {
        if ( !v4->play_count )
        {
          ((void (*)(void))v5->vfptr->Release)();
          v4->sound_table = 0;
        }
      }
      ++v3;
    }
    while ( v3 < v1->num_sounds );
  }
}

//----- (00452970) --------------------------------------------------------  // acclient.c:143875
AC1Legacy::Vector3 *__thiscall PhysicsDesc::get_omega(PhysicsDesc *this, AC1Legacy::Vector3 *result)
{
  AC1Legacy::Vector3 *v2; // eax@1

  v2 = result;
  result->x = this->omega.x;
  result->y = this->omega.y;
  result->z = this->omega.z;
  return v2;
}

//----- (004529A0) --------------------------------------------------------  // acclient.c:143887
void __thiscall Position::Position(Position *this, Position *__that)
{
  this->vfptr = (PackObjVtbl *)&Position::vftable;
  this->objcell_id = __that->objcell_id;
  Frame::operator=((int)&this->frame, (int)&__that->frame);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (004529D0) --------------------------------------------------------  // acclient.c:143896
void __thiscall CreatureMode::Render(CreatureMode *this)
{
  CreatureMode *v1; // esi@1
  char *v2; // eax@1
  unsigned int i; // edi@7
  float v4; // ST0C_4@12
  unsigned int j; // edi@14
  bool bRestoreDefaultSharpness; // [sp+17h] [bp-D1h]@4
  Frame frame; // [sp+18h] [bp-D0h]@14
  Position sound_pos; // [sp+58h] [bp-90h]@7
  Position posOriginal; // [sp+A0h] [bp-48h]@7

  v1 = this;
  v2 = (char *)&SmartBox::smartbox->creature_mode;
  if ( !SmartBox::smartbox->creature_mode )
  {
    SmartBox::smartbox->game_degrades_disabled = degrades_disabled;
    degrades_disabled = 1;
    *(_DWORD *)v2 = 1;
  }
  if ( this->creature_cell )
  {
    bRestoreDefaultSharpness = 0;
    if ( this->m_bUseSharpMode && Render::m_RenderPrefs.TextureFiltering < 2 )
    {
      RenderDeviceD3D::SetMipmapLODBiasForAllSamplers((RenderDeviceD3D *)RenderDevice::render_device, -1.4);
      bRestoreDefaultSharpness = 1;
    }
    posOriginal.vfptr = (PackObjVtbl *)&Position::vftable;
    posOriginal.objcell_id = SoundManager::player_position_.objcell_id;
    Frame::operator=((int)&posOriginal.frame, (int)&SoundManager::player_position_.frame);
    sound_pos.vfptr = (PackObjVtbl *)&Position::vftable;
    sound_pos.objcell_id = 0;
    Frame::operator=((int)&sound_pos.frame, (int)&v1->creature_view_frame);
    SoundManager::SetPlayerPosition(&sound_pos);
    for ( i = 0; i < v1->creature_mode_objects.m_num; ++i )
      CPhysicsObj::update_position(v1->creature_mode_objects.m_data[i]);
    SoundManager::SetPlayerPosition(&posOriginal);
    Render::world_lights.ambient_color.r = v1->m_clrAmbientLight.r;
    Render::world_lights.ambient_color.g = v1->m_clrAmbientLight.g;
    Render::world_lights.ambient_color.b = v1->m_clrAmbientLight.b;
    Render::useSunlightSet(1);
    Render::world_lights.num_static_lights = 0;
    Render::world_lights.num_dynamic_lights = 0;
    Render::useSunlightSet(0);
    if ( v1->m_bUseSmartboxFOV )
    {
      if ( SmartBox::smartbox->m_bUseViewDistance )
      {
        Render::set_vdst(SmartBox::smartbox->m_fViewDistFOV);
      }
      else
      {
        v4 = SmartBox::smartbox->m_fGameFOV / (RenderDevice::render_device->m_ViewportAspectRatio - 0.1);
        Render::SetFOVRad(v4);
      }
    }
    else
    {
      Render::SetFOVRad(v1->m_fFOVRadians);
    }
    LODWORD(frame.qw) = 1065353216;
    LODWORD(frame.qx) = 0;
    LODWORD(frame.qy) = 0;
    LODWORD(frame.qz) = 0;
    LODWORD(frame.m_fOrigin.x) = 0;
    LODWORD(frame.m_fOrigin.y) = 0;
    LODWORD(frame.m_fOrigin.z) = 0;
    Frame::cache(&frame);
    for ( j = 0; j < v1->creature_mode_lights.m_num; ++j )
      Render::add_static_light(v1->creature_mode_lights.m_data[j], 0, &frame);
    CObjCell::add_lights((CObjCell *)&v1->creature_cell->vfptr);
    if ( RenderDevice::render_device->m_bOpenScene )
    {
      Render::update_viewpoint(&v1->creature_view_frame);
      Render::set_default_view();
      Render::framePush(3, &frame);
      ((void (__stdcall *)(CEnvCell *))RenderDevice::render_device->vfptr->DrawObjCellForDummies)(v1->creature_cell);
      Render::framePop();
      D3DPolyRender::FlushAlphaList(0.0);
    }
    if ( bRestoreDefaultSharpness )
      RenderDeviceD3D::SetMipmapLODBiasForAllSamplers(
        (RenderDeviceD3D *)RenderDevice::render_device,
        Render::m_pRenderer->m_GlobalMipmapLODBias);
    Render::useSunlightSet(1);
    Render::world_lights.num_static_lights = 0;
    Render::world_lights.num_dynamic_lights = 0;
    Render::useSunlightSet(0);
  }
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 81EF90: using guessed type struct RenderPrefs Render::m_RenderPrefs;
// 8442E4: using guessed type int degrades_disabled;
// 866328: using guessed type int Render::FramePushCount;
// 86632C: using guessed type int Render::pushLevelOffset;

//----- (00452C40) --------------------------------------------------------  // acclient.c:143994
void __thiscall SmartBox::set_viewer(SmartBox *this, Position *new_viewer, int set_sought_position)
{
  SmartBox *v3; // esi@1
  Position *v4; // edi@1

  v3 = this;
  v4 = &this->viewer;
  this->viewer.objcell_id = new_viewer->objcell_id;
  Frame::operator=((int)&this->viewer.frame, (int)&new_viewer->frame);
  if ( set_sought_position )
  {
    v3->viewer_sought_position.objcell_id = new_viewer->objcell_id;
    Frame::operator=((int)&v3->viewer_sought_position.frame, (int)&new_viewer->frame);
  }
  v3->viewer_cell = 0;
  unk_8186E0 = LODWORD(SmartBox::s_fViewerLightFalloff);
  Render::world_lights.num_dynamic_lights = 0;
  unk_8186DC = LODWORD(SmartBox::s_fViewerLightIntensity);
  if ( v3->player )
  {
    if ( !viewer_light.type || viewer_light.type == 2 )
    {
      LODWORD(stru_818684.m_fOrigin.x) = 0;
      LODWORD(stru_818684.m_fOrigin.y) = 0;
      LODWORD(stru_818684.m_fOrigin.z) = 0x40000000;
    }
    Render::add_dynamic_light(&viewer_light, v3->player->m_position.objcell_id, &v3->player->m_position.frame);
  }
  else
  {
    if ( !viewer_light.type || viewer_light.type == 2 )
    {
      LODWORD(stru_818684.m_fOrigin.x) = 0;
      LODWORD(stru_818684.m_fOrigin.y) = 0;
      LODWORD(stru_818684.m_fOrigin.z) = 0;
    }
    Render::add_dynamic_light(&viewer_light, v3->viewer.objcell_id, &v3->viewer.frame);
  }
  CObjCell::add_dynamic_lights();
  SoundManager::SetPlayerPosition(v4);
  LScape::set_sky_position(v3->lscape, v4);
  SceneTool::SetupCamera(v4);
}
// 818610: using guessed type float SmartBox::s_fViewerLightFalloff;
// 83CC10: using guessed type float SmartBox::s_fViewerLightIntensity;

//----- (00452D60) --------------------------------------------------------  // acclient.c:144041
void __thiscall SmartBox::PlayerPhysicsUpdatedCallback(SmartBox *this)
{
  SmartBox *v1; // esi@1
  Position *v2; // eax@1
  Position result; // [sp+4h] [bp-48h]@1

  v1 = this;
  v2 = CameraManager::UpdateCamera(this->camera_manager, &result, &this->viewer);
  v1->viewer_sought_position.objcell_id = v2->objcell_id;
  Frame::operator=((int)&v1->viewer_sought_position.frame, (int)&v2->frame);
}

//----- (00452DA0) --------------------------------------------------------  // acclient.c:144054
int __thiscall SmartBox::convert_to_player_space(SmartBox *this, CPhysicsObj *object, AC1Legacy::Vector3 *_return_vector)
{
  CPhysicsObj *v3; // ecx@1
  int v4; // eax@4
  AC1Legacy::Vector3 *v5; // eax@5
  AC1Legacy::Vector3 v; // [sp+0h] [bp-18h]@5
  AC1Legacy::Vector3 result; // [sp+Ch] [bp-Ch]@5

  v3 = this->player;
  if ( v3 && object && object->cell )
  {
    LODWORD(v.x) = 0;
    LODWORD(v.y) = 0;
    LODWORD(v.z) = 0;
    v5 = Position::localtolocal(&v3->m_position, &result, &object->m_position, &v);
    _return_vector->x = v5->x;
    _return_vector->y = v5->y;
    _return_vector->z = v5->z;
    v4 = 1;
  }
  else
  {
    v4 = 0;
  }
  return v4;
}

//----- (00452E20) --------------------------------------------------------  // acclient.c:144082
signed int __userpurge SmartBox::GetObjectBoundingBox@<eax>(SmartBox *this@<ecx>, int a2@<ebx>, int a3@<edi>, unsigned int object_iid, tagRECT *bbox, float *heading)
{
  HashBaseData<unsigned long> *v6; // esi@1
  signed int v7; // eax@2
  signed int v8; // ebx@3
  Position *v9; // edi@3
  int v10; // esi@5
  double v11; // st7@12
  unsigned __int64 v12; // rax@12
  double v13; // st7@12
  unsigned __int64 v14; // rax@12
  double v15; // st7@12
  AC1Legacy::Vector3 *v16; // eax@13
  float v17; // ecx@13
  float v18; // edx@13
  int v19; // [sp+4h] [bp-5Ch]@3
  int v20; // [sp+8h] [bp-58h]@3
  Vec2D br_pt; // [sp+10h] [bp-50h]@12
  Vec2D tl_pt; // [sp+18h] [bp-48h]@6
  AC1Legacy::Vector3 viewer_center; // [sp+20h] [bp-40h]@3
  AC1Legacy::Vector3 top_left; // [sp+2Ch] [bp-34h]@6
  AC1Legacy::Vector3 bottom_right; // [sp+38h] [bp-28h]@6
  AC1Legacy::Vector3 result; // [sp+44h] [bp-1Ch]@13
  CSphere selection_sphere; // [sp+50h] [bp-10h]@3

  v6 = CObjectMaint::GetObjectA(this->m_pObjMaint, object_iid);
  if ( v6 )
  {
    v20 = a2;
    v19 = a3;
    v8 = 0;
    Render::set_default_view();
    v9 = (Position *)&v6[6];
    LODWORD(viewer_center.x) = 1065353216;
    LODWORD(viewer_center.y) = 1065353216;
    LODWORD(viewer_center.z) = 1065353216;
    LODWORD(Render::object_scale_vec.x) = 1065353216;
    dword_81EEB4 = 1065353216;
    dword_81EEB8 = 1065353216;
    LODWORD(Render::object_scale) = 1065353216;
    Render::positionPush(3, (Position *)&v6[6]);
    if ( !CPhysicsObj::GetSelectionSphere((CPhysicsObj *)v6, &selection_sphere) )
    {
      LODWORD(viewer_center.z) = 1036831949;
      LODWORD(viewer_center.x) = 0;
      LODWORD(viewer_center.y) = 0;
      LODWORD(selection_sphere.center.x) = 0;
      LODWORD(selection_sphere.center.y) = 0;
      LODWORD(selection_sphere.center.z) = 1036831949;
      LODWORD(selection_sphere.radius) = 1036831949;
    }
    v10 = Render::viewconeCheck(&selection_sphere);
    DeleteLeafTransactInfo::DynamicCast_DeleteLeaf();
    DeleteLeafTransactInfo::DynamicCast_DeleteLeaf();
    if ( !v10 )
      goto LABEL_22;
    Render::GetViewerBBox(&selection_sphere, &top_left, &bottom_right);
    if ( !((int (__stdcall *)(AC1Legacy::Vector3 *, Vec2D *, int, int))Render::m_pRenderer->vfptr->xformPointInternal)(
            &top_left,
            &tl_pt,
            v19,
            v20) )
      v10 = 0;
    if ( ((int (__cdecl *)(float *, Vec2D *))Render::m_pRenderer->vfptr->xformPointInternal)(&bottom_right.z, &tl_pt)
      && v10 )
    {
      if ( v10 > 0 && v10 <= 2 )
      {
        v11 = br_pt.x;
        bbox->left = (unsigned __int64)tl_pt.x;
        v12 = (unsigned __int64)v11;
        v13 = tl_pt.y;
        bbox->right = v12;
        v14 = (unsigned __int64)v13;
        v15 = br_pt.y;
        bbox->top = v14;
        bbox->bottom = (unsigned __int64)v15;
        v8 = 1;
      }
    }
    else
    {
LABEL_22:
      v16 = Position::localtolocal(&Render::viewer_pos, &result, v9, &selection_sphere.center);
      v17 = v16->y;
      viewer_center.x = v16->x;
      v18 = v16->z;
      viewer_center.y = v17;
      viewer_center.z = v18;
      if ( AC1Legacy::Vector3::normalize_check_small(&viewer_center) )
      {
        *(_DWORD *)heading = 0;
      }
      else if ( viewer_center.y <= 0.0 )
      {
        *heading = fmod(450.0 - atan2(viewer_center.x, 0.0) * 57.29577951308232, 360.0);
      }
      else
      {
        *heading = fmod(450.0 - atan2(viewer_center.x, viewer_center.z) * 57.29577951308232, 360.0);
      }
      v8 = 2;
    }
    Render::framePop();
    gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&br_pt);
    gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&tl_pt);
    v7 = v8;
  }
  else
  {
    v7 = 3;
  }
  return v7;
}
// 452E20: could not find valid save-restore pair for ebx
// 452E20: could not find valid save-restore pair for edi
// 81EC74: using guessed type float Render::object_scale;
// 81EEB0: using guessed type struct Vector3 Render::object_scale_vec;
// 81EEB4: using guessed type int dword_81EEB4;
// 81EEB8: using guessed type int dword_81EEB8;

//----- (00453070) --------------------------------------------------------  // acclient.c:144204
char __cdecl SmartBox::ResetDetailTexturing()
{
  char result; // al@1
  LScape *v1; // ecx@2

  result = 0;
  if ( SmartBox::smartbox )
  {
    v1 = SmartBox::smartbox->lscape;
    if ( v1 )
      result = LScape::SetDetailTexturing(v1, 0, (unsigned __int8)byte_81EF95, (unsigned __int8)byte_81EF95, 0);
  }
  return result;
}
// 81EF95: using guessed type char byte_81EF95;

//----- (004530A0) --------------------------------------------------------  // acclient.c:144221
void __thiscall SmartBox::SetWorldAmbientLight(SmartBox *this, float intensity, unsigned int color)
{
  int v3; // edx@1
  RGBColor rgb_color; // [sp+0h] [bp-Ch]@2

  v3 = this->creature_mode;
  this->game_ambient_level = intensity;
  this->game_ambient_color = color;
  if ( !v3 )
  {
    RGBColor::SetColor32(&rgb_color, color);
    rgb_color.r = rgb_color.r * intensity;
    Render::world_lights.ambient_color = rgb_color;
  }
}

//----- (00453120) --------------------------------------------------------  // acclient.c:144238
int __thiscall SmartBox::SetNormalMode(SmartBox *this)
{
  int v1; // eax@2

  if ( this->creature_mode )
  {
    v1 = this->game_degrades_disabled;
    this->creature_mode = 0;
    degrades_disabled = v1;
    SmartBox::SetWorldAmbientLight(this, this->game_ambient_level, this->game_ambient_color);
    Render::world_lights.num_static_lights = 0;
    Render::world_lights.num_dynamic_lights = 0;
    CEnvCell::flush_cells();
  }
  return 1;
}
// 8442E4: using guessed type int degrades_disabled;

//----- (00453180) --------------------------------------------------------  // acclient.c:144257
BOOL __userpurge SmartBox::set_mid_radius@<eax>(SmartBox *this@<ecx>, double a2@<st0>, int mid_radius)
{
  SmartBox *v3; // esi@1
  CellManager *v4; // ecx@1
  bool v5; // bl@1
  int v6; // eax@1
  bool v7; // cl@1
  CPhysicsObj *v8; // eax@3
  bool mid_radiusa; // [sp+Ch] [bp+4h]@1

  v3 = this;
  v4 = this->cell_manager;
  v5 = v4->blocking_for_cells;
  CellManager::Reset(v4);
  v6 = LScape::SetMidRadius(v3->lscape, mid_radius);
  v7 = v6 != 0;
  mid_radiusa = v6 != 0;
  if ( v6 )
  {
    if ( v5 )
    {
      v8 = v3->player;
      if ( v8 )
      {
        if ( v8->m_position.objcell_id )
        {
          CellManager::ChangePosition(v3->cell_manager, a2, &v8->m_position, 1);
          v7 = mid_radiusa;
        }
      }
    }
  }
  return v7;
}

//----- (004531F0) --------------------------------------------------------  // acclient.c:144293
int __userpurge SmartBox::SetRegion@<eax>(SmartBox *this@<ecx>, double a2@<st0>, unsigned int region_num)
{
  SmartBox *v3; // esi@1
  char v4; // al@1
  int v5; // edi@1

  v3 = this;
  CellManager::Reset(this->cell_manager);
  v4 = CRegionDesc::SetRegion(region_num);
  v5 = (unsigned __int8)v4;
  if ( v4 )
  {
    LScape::ChangeRegion(v3->lscape);
    SmartBox::set_mid_radius(v3, a2, mid_radius);
  }
  return v5;
}

//----- (00453240) --------------------------------------------------------  // acclient.c:144312
void __thiscall SmartBox::set_viewer_home(SmartBox *this)
{
  SmartBox *v1; // esi@1
  CPhysicsObj *v2; // eax@1
  int v3; // ecx@2
  CameraManager *v4; // ecx@2
  CameraManager *v5; // esi@2
  double v6; // st7@2
  AC1Legacy::Vector3 dir; // [sp+4h] [bp-Ch]@2

  v1 = this;
  v2 = this->player;
  if ( v2 )
  {
    CameraManager::SetPivotObject(this->camera_manager, v2->id, -1);
    v3 = (int)&v1->camera_manager->pivot_offset;
    LODWORD(dir.x) = 0;
    *(_DWORD *)v3 = 0;
    LODWORD(dir.y) = 0;
    *(_DWORD *)(v3 + 4) = 0;
    LODWORD(dir.z) = 1069547520;
    *(_DWORD *)(v3 + 8) = 1069547520;
    CameraManager::ClearTarget(v1->camera_manager);
    CameraManager::SetTarget(v1->camera_manager, LOOK_AT_PIVOT);
    v4 = v1->camera_manager;
    LODWORD(dir.x) = 0;
    LODWORD(dir.y) = 1065353216;
    LODWORD(dir.z) = 0;
    CameraManager::SetTargetDirection(v4, &dir);
    CameraManager::SetTarget(v1->camera_manager, LOOK_IN_DIRECTION);
    CameraManager::SetTarget(v1->camera_manager, ALIGN_WITH_PLANE);
    v5 = v1->camera_manager;
    v6 = v5->scale;
    v5 = (CameraManager *)((char *)v5 + 72);
    v5->vfptr = 0;
    dir.y = -2.5 * v6;
    v5->vfptr = (IInputActionCallbackVtbl *)LODWORD(dir.y);
    dir.z = v6 * 0.75;
    v5->t_stiffness = dir.z;
  }
}

//----- (00453340) --------------------------------------------------------  // acclient.c:144355
signed int __thiscall SmartBox::HandleObjDescEvent(SmartBox *this, NetBlob *blob, unsigned int object_id, VisualDesc *vdesc, PhysicsTimestampPack *timestamps)
{
  unsigned __int16 v5; // bp@1
  unsigned __int16 v6; // si@1
  SmartBox *v7; // edi@1
  HashBaseData<unsigned long> *v8; // eax@1
  CPhysicsObj *v9; // ecx@1
  unsigned __int16 v10; // bx@2
  __int64 v11; // rax@2
  bool v12; // cf@3
  signed int result; // eax@7

  v5 = timestamps->ts2;
  v6 = timestamps->ts1;
  v7 = this;
  v8 = CObjectMaint::GetObjectA(this->m_pObjMaint, object_id);
  v9 = (CPhysicsObj *)v8;
  if ( !v8
    || ((v10 = LOWORD(v8[31].vfptr),
         v11 = v6 - LOWORD(v8[31].vfptr),
         (signed int)((HIDWORD(v11) ^ v11) - HIDWORD(v11)) > 0x7FFF) ? (v12 = v6 < v10) : (v12 = v10 < v6),
        v12) )
  {
    CObjectMaint::QueueBlobForObject(v7->m_pObjMaint, object_id, blob);
    result = 4;
  }
  else if ( v10 == v6 )
  {
    SmartBox::UpdateVisualDesc(v7, v9, vdesc, v5);
    result = 1;
  }
  else
  {
    result = 2;
  }
  return result;
}

//----- (004533E0) --------------------------------------------------------  // acclient.c:144394
signed int __thiscall SmartBox::HandleSetState(SmartBox *this, NetBlob *blob, unsigned int object_id, unsigned int new_state, PhysicsTimestampPack *timestamps)
{
  unsigned __int16 v5; // bp@1
  unsigned __int16 v6; // si@1
  SmartBox *v7; // edi@1
  HashBaseData<unsigned long> *v8; // eax@1
  CPhysicsObj *v9; // ecx@1
  unsigned __int16 v10; // bx@2
  __int64 v11; // rax@2
  bool v12; // cf@3
  signed int result; // eax@7

  v5 = timestamps->ts2;
  v6 = timestamps->ts1;
  v7 = this;
  v8 = CObjectMaint::GetObjectA(this->m_pObjMaint, object_id);
  v9 = (CPhysicsObj *)v8;
  if ( !v8
    || ((v10 = LOWORD(v8[31].vfptr),
         v11 = v6 - LOWORD(v8[31].vfptr),
         (signed int)((HIDWORD(v11) ^ v11) - HIDWORD(v11)) > 0x7FFF) ? (v12 = v6 < v10) : (v12 = v10 < v6),
        v12) )
  {
    CObjectMaint::QueueBlobForObject(v7->m_pObjMaint, object_id, blob);
    result = 4;
  }
  else if ( v10 == v6 )
  {
    SmartBox::DoSetState(v7, v9, new_state, v5);
    result = 1;
  }
  else
  {
    result = 2;
  }
  return result;
}

//----- (00453480) --------------------------------------------------------  // acclient.c:144433
signed int __thiscall SmartBox::HandleVectorUpdate(SmartBox *this, NetBlob *blob, unsigned int object_id, AC1Legacy::Vector3 *velocity, AC1Legacy::Vector3 *omega, PhysicsTimestampPack *timestamps)
{
  unsigned __int16 v6; // bp@1
  unsigned __int16 v7; // si@1
  SmartBox *v8; // edi@1
  HashBaseData<unsigned long> *v9; // eax@1
  CPhysicsObj *v10; // ecx@1
  unsigned __int16 v11; // bx@2
  __int64 v12; // rax@2
  bool v13; // cf@3
  signed int result; // eax@7

  v6 = timestamps->ts2;
  v7 = timestamps->ts1;
  v8 = this;
  v9 = CObjectMaint::GetObjectA(this->m_pObjMaint, object_id);
  v10 = (CPhysicsObj *)v9;
  if ( !v9
    || ((v11 = LOWORD(v9[31].vfptr),
         v12 = v7 - LOWORD(v9[31].vfptr),
         (signed int)((HIDWORD(v12) ^ v12) - HIDWORD(v12)) > 0x7FFF) ? (v13 = v7 < v11) : (v13 = v11 < v7),
        v13) )
  {
    CObjectMaint::QueueBlobForObject(v8->m_pObjMaint, object_id, blob);
    result = 4;
  }
  else if ( v11 == v7 )
  {
    SmartBox::DoVectorUpdate(v8, v10, velocity, omega, v6);
    result = 1;
  }
  else
  {
    result = 2;
  }
  return result;
}

//----- (00453530) --------------------------------------------------------  // acclient.c:144472
signed int __thiscall SmartBox::HandlePickupEvent(SmartBox *this, NetBlob *blob, unsigned int object_id, PhysicsTimestampPack *timestamps)
{
  unsigned __int16 v4; // bp@1
  unsigned __int16 v5; // si@1
  SmartBox *v6; // edi@1
  HashBaseData<unsigned long> *v7; // eax@1
  CPhysicsObj *v8; // ecx@1
  unsigned __int16 v9; // bx@2
  __int64 v10; // rax@2
  bool v11; // cf@3
  signed int result; // eax@7

  v4 = timestamps->ts2;
  v5 = timestamps->ts1;
  v6 = this;
  v7 = CObjectMaint::GetObjectA(this->m_pObjMaint, object_id);
  v8 = (CPhysicsObj *)v7;
  if ( !v7
    || ((v9 = LOWORD(v7[31].vfptr),
         v10 = v5 - LOWORD(v7[31].vfptr),
         (signed int)((HIDWORD(v10) ^ v10) - HIDWORD(v10)) > 0x7FFF) ? (v11 = v5 < v9) : (v11 = v9 < v5),
        v11) )
  {
    CObjectMaint::QueueBlobForObject(v6->m_pObjMaint, object_id, blob);
    result = 4;
  }
  else if ( v9 == v5 )
  {
    SmartBox::DoPickupEvent(v8, v4);
    result = 1;
  }
  else
  {
    result = 2;
  }
  return result;
}

//----- (004535D0) --------------------------------------------------------  // acclient.c:144511
signed int __thiscall SmartBox::HandleParentEvent(SmartBox *this, NetBlob *blob, unsigned int object_id, unsigned int child_id, unsigned int child_location, unsigned int placement_id, PhysicsTimestampPack *timestamps)
{
  unsigned __int16 v7; // bx@1
  SmartBox *v8; // esi@1
  HashBaseData<unsigned long> *v9; // eax@1
  HashBaseData<unsigned long> *v10; // edi@1
  unsigned __int16 v11; // cx@2
  __int64 v12; // rax@2
  bool v13; // cf@3
  HashBaseData<unsigned long> *v14; // eax@6
  signed int result; // eax@9
  unsigned __int16 timestampsa; // [sp+28h] [bp+18h]@1

  v7 = timestamps->ts1;
  v8 = this;
  timestampsa = timestamps->ts2;
  v9 = CObjectMaint::GetObjectA(this->m_pObjMaint, object_id);
  v10 = v9;
  if ( !v9
    || ((v11 = LOWORD(v9[31].vfptr),
         v12 = v7 - LOWORD(v9[31].vfptr),
         (signed int)((HIDWORD(v12) ^ v12) - HIDWORD(v12)) > 0x7FFF) ? (v13 = v7 < v11) : (v13 = v11 < v7),
        v13) )
  {
    CObjectMaint::QueueBlobForObject(v8->m_pObjMaint, object_id, blob);
    return 4;
  }
  v14 = CObjectMaint::GetObjectA(v8->m_pObjMaint, child_id);
  if ( !v14 )
  {
    CObjectMaint::QueueBlobForObject(v8->m_pObjMaint, child_id, blob);
    return 4;
  }
  if ( LOWORD(v10[31].vfptr) == v7 )
  {
    SmartBox::DoParentEvent(v8, (CPhysicsObj *)v14, (CPhysicsObj *)v10, child_location, placement_id, timestampsa);
    result = 1;
  }
  else
  {
    result = 2;
  }
  return result;
}

//----- (004536A0) --------------------------------------------------------  // acclient.c:144557
char __thiscall CreatureMode::RemoveObject(CreatureMode *this, CPhysicsObj *i_pObject)
{
  CreatureMode *v2; // esi@1
  unsigned int v3; // edi@2
  CPhysicsObj **v4; // eax@3
  char result; // al@6
  unsigned int v6; // eax@7
  int v7; // eax@8

  v2 = this;
  if ( i_pObject && (v3 = 0, this->creature_mode_objects.m_num) )
  {
    v4 = this->creature_mode_objects.m_data;
    while ( *v4 != i_pObject )
    {
      ++v3;
      ++v4;
      if ( v3 >= this->creature_mode_objects.m_num )
        goto LABEL_6;
    }
    CPhysicsObj::RemoveObjectFromSingleCell(
      this->creature_mode_objects.m_data[v3],
      (CObjCell *)&this->creature_cell->vfptr);
    v6 = v2->creature_mode_objects.m_num;
    if ( v3 < v6 )
    {
      v7 = v6 - 1;
      v2->creature_mode_objects.m_num = v7;
      if ( v3 != v7 )
      {
        v2->creature_mode_objects.m_data[v3] = v2->creature_mode_objects.m_data[v7];
        v2->creature_mode_objects.m_data[v2->creature_mode_objects.m_num] = 0;
      }
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

//----- (00453710) --------------------------------------------------------  // acclient.c:144602
CPhysicsObj *__thiscall CreatureMode::GetObjectByIndex(CreatureMode *this, unsigned int i_index)
{
  CPhysicsObj *result; // eax@2

  if ( i_index < this->creature_mode_objects.m_num )
    result = this->creature_mode_objects.m_data[i_index];
  else
    result = 0;
  return result;
}

//----- (00453730) --------------------------------------------------------  // acclient.c:144614
void __thiscall CreatureMode::SetCameraDirection(CreatureMode *this, AC1Legacy::Vector3 *i_direction)
{
  Frame *v2; // esi@1

  v2 = &this->creature_view_frame;
  Frame::euler_set_rotate(&this->creature_view_frame, 0.0, 0.0, 0.0, 0);
  Frame::rotate(v2, i_direction);
}

//----- (00453760) --------------------------------------------------------  // acclient.c:144624
void __thiscall CreatureMode::SetCameraDirection_Degrees(CreatureMode *this, AC1Legacy::Vector3 *i_direction_degrees)
{
  Frame *v2; // esi@1
  double v3; // st7@1
  double v4; // st6@1
  AC1Legacy::Vector3 w; // [sp+4h] [bp-18h]@1
  float v6; // [sp+18h] [bp-4h]@1

  v2 = &this->creature_view_frame;
  Frame::euler_set_rotate(&this->creature_view_frame, 0.0, 0.0, 0.0, 0);
  v3 = i_direction_degrees->x * 0.017453292;
  v4 = i_direction_degrees->y * 0.017453292;
  v6 = i_direction_degrees->z * 0.017453292;
  w.z = v6;
  w.x = v3;
  w.y = v4;
  Frame::rotate(v2, &w);
}

//----- (00453810) --------------------------------------------------------  // acclient.c:144675
Position *__thiscall PhysicsDesc::get_position(PhysicsDesc *this, Position *result)
{
  result->vfptr = (PackObjVtbl *)&Position::vftable;
  result->objcell_id = this->pos.objcell_id;
  Frame::operator=((int)&result->frame, (int)&this->pos.frame);
  return result;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00453840) --------------------------------------------------------  // acclient.c:144685
void __cdecl SmartBox::Cleanup()
{
  Render::UnlinkRGRCallback((bool (__cdecl *)())SmartBox::ResetDetailTexturing);
  if ( SmartBox::smartbox )
    ((void (__stdcall *)(_DWORD))SmartBox::smartbox->vfptr->__vecDelDtor)(1);
  SmartBox::smartbox = 0;
}

//----- (00453870) --------------------------------------------------------  // acclient.c:144694
void __userpurge SmartBox::PlayerPositionUpdated(SmartBox *this@<ecx>, double a2@<st0>, int teleporting, float distance_moved)
{
  SmartBox *v4; // esi@1
  CPhysicsObj *v5; // ecx@1
  Position *v6; // ebx@2
  CPhysicsObj *v7; // eax@6

  v4 = this;
  v5 = this->player;
  if ( !v5 )
    return;
  v6 = &v5->m_position;
  if ( teleporting )
  {
    v4->position_update_complete = 0;
    v4->waiting_for_teleport = 0;
    v4->has_been_teleported = 0;
    CPhysicsObj::teleport_hook(v5, 1);
    ((void (*)(void))v4->cmdinterp->vfptr[9].OnLoseFocus)();
  }
  else
  {
    a2 = CPhysicsObj::GetAutonomyBlipDistance(v5);
    if ( a2 >= distance_moved )
      goto LABEL_6;
  }
  SmartBox::set_viewer(v4, v6, 1);
  LScape::update_viewpoint(v4->lscape, 0);
LABEL_6:
  v7 = v4->player;
  if ( v7 )
  {
    if ( v7->m_position.objcell_id )
      CellManager::ChangePosition(v4->cell_manager, a2, &v7->m_position, teleporting);
  }
}

//----- (00453910) --------------------------------------------------------  // acclient.c:144732
void __userpurge SmartBox::TeleportPlayer(SmartBox *this@<ecx>, double a2@<st0>, Position *new_pos)
{
  SmartBox *v3; // esi@1
  CPhysicsObj *v4; // ecx@1

  v3 = this;
  v4 = this->player;
  if ( v4 )
  {
    CPhysicsObj::SetPositionSimple(v4, new_pos, 1);
    SmartBox::PlayerPositionUpdated(v3, a2, 1, 3.4028235e38);
  }
}

//----- (00453940) --------------------------------------------------------  // acclient.c:144747
void __thiscall SmartBox::BlipPlayer(SmartBox *this, Position *new_pos)
{
  SmartBox *v2; // esi@1
  CPhysicsObj *v3; // eax@1
  Position *v4; // edi@2
  double v5; // st7@2
  float new_posa; // [sp+8h] [bp+4h]@2

  v2 = this;
  v3 = this->player;
  if ( v3 )
  {
    v4 = new_pos;
    v5 = Position::distance(&v3->m_position, new_pos);
    new_posa = v5;
    CPhysicsObj::SetPositionSimple(v2->player, v4, 1);
    SmartBox::PlayerPositionUpdated(v2, v5, 0, new_posa);
  }
}

//----- (00453980) --------------------------------------------------------  // acclient.c:144768
void __thiscall SmartBox::QueueNetBlob(SmartBox *this, NetBlob *blob)
{
  SmartBox *v2; // esi@1
  void *v3; // eax@2
  NIList<NetBlob *> *v4; // esi@6
  void *v5; // eax@6
  NIListElement<NetBlob *> *v6; // ecx@9

  v2 = this;
  if ( !this->netblob_list )
  {
    v3 = operator new(8u);
    if ( v3 )
    {
      *(_DWORD *)v3 = 0;
      *((_DWORD *)v3 + 1) = 0;
    }
    else
    {
      v3 = 0;
    }
    v2->netblob_list = (NIList<NetBlob *> *)v3;
  }
  InterlockedIncrement((volatile LONG *)&blob->m_cRef);
  v4 = v2->netblob_list;
  v5 = operator new(8u);
  if ( v5 )
  {
    *(_DWORD *)v5 = blob;
    *((_DWORD *)v5 + 1) = 0;
  }
  else
  {
    v5 = 0;
  }
  v6 = v4->tail_;
  if ( v6 )
  {
    v6->next_ = (NIListElement<NetBlob *> *)v5;
    v4->tail_ = v4->tail_->next_;
  }
  else
  {
    v4->head_ = (NIListElement<NetBlob *> *)v5;
    v4->tail_ = (NIListElement<NetBlob *> *)v5;
  }
}

//----- (00453A10) --------------------------------------------------------  // acclient.c:144817
void __thiscall SmartBox::DestroyQueuedNetBlobs(SmartBox *this)
{
  SmartBox *v1; // edi@1
  NIList<NetBlob *> *v2; // eax@1
  NIList<NetBlob *> *v3; // ecx@3
  NIListElement<NetBlob *> *v4; // eax@3
  NetBlob *v5; // esi@4
  NIListElement<NetBlob *> *v6; // edx@5
  void *v7; // esi@12

  v1 = this;
  v2 = this->netblob_list;
  if ( v2 )
  {
    if ( v2->head_ )
    {
      do
      {
        v3 = v1->netblob_list;
        v4 = v3->head_;
        if ( v3->head_ )
        {
          v6 = v4->next_;
          v3->head_ = v6;
          if ( !v6 )
            v3->tail_ = 0;
          v5 = v4->data_;
          operator delete(v4);
        }
        else
        {
          v5 = 0;
        }
        if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
          v5->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 1u);
      }
      while ( v1->netblob_list->head_ );
    }
    v7 = v1->netblob_list;
    if ( v7 )
    {
      NIList<unsigned long>::DeleteContents((NIList<NetPacket *> *)v1->netblob_list);
      operator delete(v7);
    }
    v1->netblob_list = 0;
  }
}

//----- (00453AA0) --------------------------------------------------------  // acclient.c:144866
void __usercall SmartBox::RenderNormalMode(SmartBox *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  SmartBox *v3; // esi@1
  unsigned int v4; // ecx@2
  int v5; // edi@2
  int v6; // ebx@4
  float _radians; // ST04_4@8
  unsigned int v8; // eax@12
  unsigned int v9; // eax@15
  signed int v10; // eax@17
  void (*v11)(void); // esi@18
  int v12; // [sp+4h] [bp-20h]@2
  int v13; // [sp+8h] [bp-1Ch]@2
  float heading; // [sp+10h] [bp-14h]@17
  tagRECT bbox; // [sp+14h] [bp-10h]@17

  v3 = this;
  if ( RenderDevice::render_device->m_bOpenScene )
  {
    v4 = this->viewer.objcell_id & 0xFFFF;
    v13 = a2;
    v12 = a3;
    v5 = v4 < 0x100;
    v6 = v4 < 0x100 || v3->viewer_cell->seen_outside;
    if ( v3->m_bUseViewDistance )
    {
      Render::set_vdst(v3->m_fViewDistFOV);
    }
    else
    {
      _radians = v3->m_fGameFOV / (RenderDevice::render_device->m_ViewportAspectRatio - 0.1);
      Render::SetFOVRad(_radians);
    }
    if ( v5 )
    {
      LScape::update_viewpoint(v3->lscape, v3->viewer.objcell_id);
      Render::update_viewpoint(&v3->viewer);
      Render::set_default_view();
      Render::useSunlightSet(1);
      LScape::draw(v3->lscape);
    }
    else
    {
      if ( v6 )
      {
        v8 = Position::get_outside_cell_id(&v3->viewer);
        LScape::update_viewpoint(v3->lscape, v8);
      }
      Render::update_viewpoint(&v3->viewer);
      ((void (__stdcall *)(CObjCell *))RenderDevice::render_device->vfptr->DrawInside)(v3->viewer_cell);
    }
    a3 = v12;
    a2 = v13;
  }
  D3DPolyRender::FlushAlphaList(0.0);
  v9 = v3->target_object_id;
  if ( v9 && v3->target_callback )
  {
    v10 = SmartBox::GetObjectBoundingBox(v3, a2, a3, v9, &bbox, &heading);
    ((void (__cdecl *)(unsigned int, signed int, tagRECT *, _DWORD))v3->target_callback)(
      v3->target_object_id,
      v10,
      &bbox,
      LODWORD(heading));
  }
  v11 = (void (*)(void))v3->m_renderingCallback;
  if ( v11 )
    v11();
}

//----- (00453BF0) --------------------------------------------------------  // acclient.c:144937
void __thiscall SmartBox::Reset(SmartBox *this, int clear_objects)
{
  SmartBox *v2; // esi@1
  InterpolationManager *v3; // ecx@1
  CommandInterpreter *v4; // ecx@3
  CellManager *v5; // ecx@5
  CObjectMaint *v6; // ecx@8

  v2 = this;
  degrades_disabled = 0;
  v3 = (InterpolationManager *)this->physics;
  v2->player = 0;
  if ( v3 )
    QuickWindow::SetWindowID(v3, 0);
  v4 = v2->cmdinterp;
  if ( v4 )
    ((void (__stdcall *)(SmartBox *))v4->vfptr[7].OnLoseFocus)(v2);
  v5 = v2->cell_manager;
  if ( v5 )
    CellManager::Reset(v5);
  v2->viewer_cell = 0;
  v2->position_update_complete = 0;
  v2->has_been_teleported = 0;
  if ( clear_objects )
  {
    v6 = v2->m_pObjMaint;
    v2->player_id = 0;
    if ( v6 )
    {
      ((void (__stdcall *)(_DWORD))v6->vfptr[2].IUnknown_QueryInterface)(0);
      CObjectMaint::DestroyObjects(v2->m_pObjMaint);
    }
    SmartBox::DestroyQueuedNetBlobs(v2);
  }
}
// 8442E4: using guessed type int degrades_disabled;

//----- (00453C80) --------------------------------------------------------  // acclient.c:144975
void __thiscall SmartBox::init_player(SmartBox *this, CPhysicsObj *player_object, int autonomous)
{
  SmartBox *v3; // esi@1

  v3 = this;
  this->player = player_object;
  SmartBox::set_viewer_home(this);
  QuickWindow::SetWindowID((InterpolationManager *)v3->physics, v3->player);
  CPhysicsObj::SetPlayer(v3->player);
  CPhysicsPart::player_iid = v3->player->id;
  ((void (__stdcall *)(int))v3->cmdinterp->vfptr[9].__vecDelDtor)(autonomous);
}
// 843BF8: using guessed type unsigned __int32 CPhysicsPart::player_iid;

//----- (00453CE0) --------------------------------------------------------  // acclient.c:144990
void __thiscall SmartBox::update_viewer(SmartBox *this)
{
  SmartBox *v1; // esi@1
  CPhysicsObj *v2; // ecx@1
  CameraManager *v3; // ebx@6
  int v4; // eax@6
  CPhysicsObj *v5; // edi@7
  CPartArray *v6; // ecx@7
  AC1Legacy::Vector3 *v7; // eax@10
  int v8; // edx@10
  CObjCell *v9; // edi@11
  unsigned int v10; // edi@12
  CPhysicsObj *v11; // eax@13
  unsigned int v12; // eax@15
  AC1Legacy::Vector3 *v13; // eax@15
  unsigned int v14; // edi@15
  CTransition *v15; // eax@15
  CTransition *v16; // edi@15
  CObjCell *start_cell; // [sp+8h] [bp-174h]@6
  CObjCell *new_cell; // [sp+Ch] [bp-170h]@18
  Frame start_frame; // [sp+10h] [bp-16Ch]@8
  AC1Legacy::Vector3 result; // [sp+50h] [bp-12Ch]@10
  Position new_viewer; // [sp+5Ch] [bp-120h]@6
  Position begin_pos; // [sp+A4h] [bp-D8h]@15
  Position start_pos; // [sp+ECh] [bp-90h]@12
  Position end_pos; // [sp+134h] [bp-48h]@15

  v1 = this;
  v2 = this->player;
  if ( v2 )
  {
    if ( v2->cell || (CPhysicsObj::reenter_visibility(v2), v2 = v1->player, v2->cell) )
    {
      cell_from = v2->m_position.objcell_id;
      Frame::operator=((int)&stru_81EF50, (int)&v2->m_position.frame);
      if ( !static_camera )
      {
        new_viewer.objcell_id = v1->viewer_sought_position.objcell_id;
        new_viewer.vfptr = (PackObjVtbl *)&Position::vftable;
        Frame::operator=((int)&new_viewer.frame, (int)&v1->viewer_sought_position.frame);
        v3 = v1->camera_manager;
        start_cell = 0;
        v4 = v3->pivot_part_index;
        if ( v4 == -1 || (v5 = v1->player, v6 = v5->part_array, v4 >= (signed int)v6->num_parts) )
        {
          v5 = v1->player;
          Frame::operator=((int)&start_frame, (int)&v5->m_position.frame);
        }
        else
        {
          Frame::operator=((int)&start_frame, (int)&v6->parts[v4]->pos.frame);
        }
        v7 = Frame::localtoglobalvec(&start_frame, &result, &v3->pivot_offset);
        v8 = v5->m_position.objcell_id & 0xFFFF;
        start_frame.m_fOrigin.x = start_frame.m_fOrigin.x + v7->x;
        start_frame.m_fOrigin.y = start_frame.m_fOrigin.y + v7->y;
        start_frame.m_fOrigin.z = start_frame.m_fOrigin.z + v7->z;
        if ( (unsigned int)v8 >= 0x100 )
        {
          v10 = v5->m_position.objcell_id;
          start_pos.vfptr = (PackObjVtbl *)&Position::vftable;
          start_pos.objcell_id = v10;
          Frame::operator=((int)&start_pos.frame, (int)&start_frame);
          if ( CPhysicsObj::AdjustPosition(&start_pos, &viewer_sphere, &start_cell, 0, 1) )
          {
            v9 = start_cell;
          }
          else
          {
            v11 = v1->player;
            v9 = v11->cell;
            start_cell = v11->cell;
          }
        }
        else
        {
          v9 = v5->cell;
          start_cell = v9;
        }
        v12 = v9->m_DID.id;
        begin_pos.vfptr = (PackObjVtbl *)&Position::vftable;
        begin_pos.objcell_id = v12;
        Frame::operator=((int)&begin_pos.frame, (int)&start_frame);
        v13 = Position::localtoglobal(&begin_pos, &result, &new_viewer);
        new_viewer.frame.m_fOrigin.x = v13->x;
        new_viewer.frame.m_fOrigin.y = v13->y;
        new_viewer.frame.m_fOrigin.z = v13->z;
        v14 = v9->m_DID.id;
        end_pos.vfptr = (PackObjVtbl *)&Position::vftable;
        end_pos.objcell_id = v14;
        Frame::operator=((int)&end_pos.frame, (int)&new_viewer.frame);
        v15 = CTransition::makeTransition();
        v16 = v15;
        if ( v15 )
        {
          CTransition::init_object(v15, v1->player, 92);
          CTransition::init_sphere(v16, 1u, (CSphere *)&viewer_sphere, 1.0);
          CTransition::init_path(v16, start_cell, &begin_pos, &end_pos);
          if ( CTransition::find_valid_position(v16) )
          {
            SmartBox::set_viewer(v1, &v16->sphere_path.curr_pos, 0);
            v1->viewer_cell = v16->sphere_path.curr_cell;
            CTransition::cleanupTransition();
          }
          else
          {
            new_cell = 0;
            if ( CPhysicsObj::AdjustPosition(&new_viewer, &viewer_sphere, &new_cell, 0, 1) )
            {
              SmartBox::set_viewer(v1, &new_viewer, 0);
              v1->viewer_cell = new_cell;
              CTransition::cleanupTransition();
            }
            else
            {
              SmartBox::set_viewer(v1, &v1->player->m_position, 1);
              v1->viewer_cell = 0;
              CTransition::cleanupTransition();
            }
          }
        }
      }
    }
    else
    {
      SmartBox::set_viewer(v1, &v2->m_position, 1);
      v1->viewer_cell = 0;
    }
  }
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 83CA40: using guessed type int static_camera;

//----- (00453FD0) --------------------------------------------------------  // acclient.c:145124
void __userpurge SmartBox::HandleReceivedPosition(SmartBox *this@<ecx>, double a2@<st0>, CPhysicsObj *object, Position *position, unsigned int placement_id, int has_contact, AC1Legacy::Vector3 *velocity, unsigned __int16 position_timestamp, unsigned __int16 teleport_timestamp, unsigned __int16 force_position_timestamp)
{
  SmartBox *v10; // edi@1
  CPhysicsObj *v11; // ecx@1
  CPhysicsObj *v12; // ecx@3
  unsigned __int16 v13; // bp@3
  __int64 v14; // rax@3
  bool v15; // cf@4
  unsigned __int16 v16; // bp@8
  unsigned __int16 v17; // cx@9
  __int64 v18; // rax@9
  bool v19; // cf@10
  CPhysicsObj *v20; // eax@14
  HashBaseData<unsigned long> *v21; // eax@16
  float max_distance; // ST0C_4@22
  float start_distance; // ST08_4@22
  CPhysicsObj *v24; // ecx@22
  float v25; // ST0C_4@23
  float v26; // ST08_4@23
  int v27; // eax@25
  float v28; // ST0C_4@27
  float v29; // ST08_4@27
  unsigned __int16 v30; // si@28
  bool v31; // cf@29
  AC1Legacy::Vector3 new_velocity; // [sp+1Ch] [bp-54h]@22
  Position pos; // [sp+28h] [bp-48h]@1
  int has_contacta; // [sp+80h] [bp+10h]@7

  v10 = this;
  pos.objcell_id = position->objcell_id;
  pos.vfptr = (PackObjVtbl *)&Position::vftable;
  Frame::operator=((int)&pos.frame, (int)&position->frame);
  v11 = v10->player;
  if ( object != v11
    || !CPhysicsObj::newer_event(v11, FORCE_POSITION_TS, force_position_timestamp)
    || ((v12 = v10->player,
         v13 = v12->update_times[4],
         v14 = v12->update_times[4] - teleport_timestamp,
         (signed int)((HIDWORD(v14) ^ v14) - HIDWORD(v14)) > 0x7FFF) ? (v15 = v13 < teleport_timestamp) : (v15 = teleport_timestamp < v13),
        v15) )
  {
    v16 = object->update_times[0];
    if ( CPhysicsObj::newer_event(object, 0, position_timestamp) )
    {
      v17 = object->update_times[4];
      v18 = object->update_times[4] - teleport_timestamp;
      if ( (signed int)((HIDWORD(v18) ^ v18) - HIDWORD(v18)) > 0x7FFF )
        v19 = v17 < teleport_timestamp;
      else
        v19 = teleport_timestamp < v17;
      if ( v19 )
      {
        object->update_times[0] = v16;
      }
      else
      {
        v20 = object->parent;
        if ( v20 )
        {
          if ( v20->id != v10->player_id )
          {
            v21 = CObjectMaint::GetWeenieObject(v10->m_pObjMaint, object->id);
            if ( v21 )
              v21->vfptr[3].__vecDelDtor(v21, 0);
          }
        }
        CPhysicsObj::unset_parent(object);
        if ( !CPhysicsObj::HasAnims(object) )
          CPhysicsObj::SetPlacementFrame(object, placement_id, 1);
        if ( object == v10->player )
        {
          if ( CPhysicsObj::newer_event(object, TELEPORT_TS, teleport_timestamp) )
          {
            SmartBox::TeleportPlayer(v10, a2, &pos);
            max_distance = CPhysicsObj::GetMaxConstraintDistance(object);
            start_distance = CPhysicsObj::GetStartConstraintDistance(object);
            CPhysicsObj::ConstrainTo(object, &pos, start_distance, max_distance);
            v24 = v10->player;
            LODWORD(new_velocity.x) = 0;
            LODWORD(new_velocity.y) = 0;
            LODWORD(new_velocity.z) = 0;
            CPhysicsObj::set_velocity(v24, &new_velocity, 1);
          }
          else
          {
            v25 = CPhysicsObj::GetMaxConstraintDistance(v10->player);
            v26 = CPhysicsObj::GetStartConstraintDistance(v10->player);
            CPhysicsObj::ConstrainTo(v10->player, &pos, v26, v25);
            if ( ((int (*)(void))v10->cmdinterp->vfptr[8].__vecDelDtor)() )
            {
              if ( has_contact )
              {
                v27 = ((int (*)(void))v10->cmdinterp->vfptr[15].__vecDelDtor)();
                CPhysicsObj::InterpolateTo(object, &pos, v27 != 0);
              }
            }
          }
        }
        else if ( CPhysicsObj::MoveOrTeleport(object, &pos, teleport_timestamp, has_contact, velocity) )
        {
          v28 = CPhysicsObj::GetMaxConstraintDistance(object);
          v29 = CPhysicsObj::GetStartConstraintDistance(object);
          CPhysicsObj::ConstrainTo(object, &object->m_position, v29, v28);
        }
      }
    }
    else
    {
      v30 = object->update_times[4];
      if ( abs(teleport_timestamp - v30) > 0x7FFF )
        v31 = teleport_timestamp < v30;
      else
        v31 = v30 < teleport_timestamp;
      if ( v31 )
        ++error_count;
    }
  }
  else
  {
    *(float *)&has_contacta = CPhysicsObj::get_heading(v12);
    Frame::set_heading(&pos.frame, *(float *)&has_contacta);
    SmartBox::BlipPlayer(v10, &pos);
    v10->player->update_times[0] = position_timestamp;
    ((void (*)(void))v10->cmdinterp->vfptr[7].OnAction)();
  }
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (004542C0) --------------------------------------------------------  // acclient.c:145253
signed int __userpurge SmartBox::UnpackPositionEvent@<eax>(SmartBox *this@<ecx>, double a2@<st0>, unsigned int object_id, void **buff, unsigned int size)
{
  SmartBox *v5; // ebx@1
  HashBaseData<unsigned long> *v6; // eax@1
  CPhysicsObj *v7; // edi@1
  unsigned __int16 v8; // cx@2
  __int64 v9; // rax@2
  bool v10; // cf@3
  signed int result; // eax@7
  PositionPack pp; // [sp+Ch] [bp-68h]@1

  v5 = this;
  PositionPack::PositionPack(&pp);
  PositionPack::UnPack(&pp, buff, size);
  v6 = CObjectMaint::GetObjectA(v5->m_pObjMaint, object_id);
  v7 = (CPhysicsObj *)v6;
  if ( !v6
    || ((v8 = LOWORD(v6[31].vfptr),
         v9 = pp.instance_timestamp - LOWORD(v6[31].vfptr),
         (signed int)((HIDWORD(v9) ^ v9) - HIDWORD(v9)) > 0x7FFF) ? (v10 = pp.instance_timestamp < v8) : (v10 = v8 < pp.instance_timestamp),
        v10) )
  {
    result = 4;
  }
  else if ( v8 == pp.instance_timestamp )
  {
    SmartBox::HandleReceivedPosition(
      v5,
      a2,
      v7,
      &pp.position,
      pp.placement_id,
      pp.has_contact,
      &pp.velocity,
      pp.position_timestamp,
      pp.teleport_timestamp,
      pp.force_position_timestamp);
    result = 1;
  }
  else
  {
    result = 2;
  }
  return result;
}

//----- (00454390) --------------------------------------------------------  // acclient.c:145300
void __thiscall CreatureMode::CreatureMode(CreatureMode *this)
{
  CreatureMode *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  this->creature_mode_objects.m_data = 0;
  this->creature_mode_objects.m_sizeAndDeallocate = 0;
  this->creature_mode_objects.m_num = 0;
  this->creature_mode_lights.m_data = 0;
  this->creature_mode_lights.m_sizeAndDeallocate = 0;
  this->creature_mode_lights.m_num = 0;
  v2 = (char *)&this->creature_view_frame;
  v1->creature_cell = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  LODWORD(v1->m_clrAmbientLight.r) = 1050253722;
  LODWORD(v1->m_clrAmbientLight.g) = 1050253722;
  LODWORD(v1->m_clrAmbientLight.b) = 1050253722;
  v1->m_bUseSmartboxFOV = 0;
  v1->m_bUseSharpMode = 0;
  LODWORD(v1->m_fFOVRadians) = 1061752795;
}

//----- (004543F0) --------------------------------------------------------  // acclient.c:145331
void __thiscall CreatureMode::RemoveAllObjects(CreatureMode *this)
{
  CreatureMode *v1; // esi@1
  unsigned int v2; // edi@2

  v1 = this;
  if ( this->creature_cell )
  {
    v2 = 0;
    if ( this->creature_mode_objects.m_num )
    {
      do
        CPhysicsObj::RemoveObjectFromSingleCell(
          v1->creature_mode_objects.m_data[v2++],
          (CObjCell *)&v1->creature_cell->vfptr);
      while ( v2 < v1->creature_mode_objects.m_num );
    }
    CPartCell::remove_shadows((CPartCell *)&v1->creature_cell->vfptr, 1);
  }
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)v1);
}

//----- (00454430) --------------------------------------------------------  // acclient.c:145354
void __thiscall CreatureMode::RemoveAllLights(CreatureMode *this)
{
  CreatureMode *v1; // esi@1
  unsigned int v2; // edi@1
  unsigned int v3; // eax@5
  unsigned int v4; // ecx@5
  int i; // eax@8

  v1 = this;
  v2 = 0;
  if ( this->creature_mode_lights.m_num )
  {
    do
    {
      if ( v1->creature_mode_lights.m_data[v2] )
        operator delete(v1->creature_mode_lights.m_data[v2]);
      ++v2;
    }
    while ( v2 < v1->creature_mode_lights.m_num );
  }
  v3 = v1->creature_mode_lights.m_sizeAndDeallocate;
  v4 = v1->creature_mode_lights.m_sizeAndDeallocate & 0x80000000;
  v1->creature_mode_lights.m_num = 0;
  if ( v4 == 0x80000000 )
  {
    operator delete[](v1->creature_mode_lights.m_data);
    v1->creature_mode_lights.m_data = 0;
    v1->creature_mode_lights.m_sizeAndDeallocate = 0;
  }
  else if ( v1->creature_mode_lights.m_data )
  {
    for ( i = (v3 & 0x7FFFFFFF) - 1; i >= 0; v1->creature_mode_lights.m_data[i + 1] = 0 )
      --i;
  }
}

//----- (004544C0) --------------------------------------------------------  // acclient.c:145391
char __thiscall CreatureMode::SetLightDirection(CreatureMode *this, unsigned int i_index, AC1Legacy::Vector3 *i_direction)
{
  char result; // al@2

  if ( i_index >= this->creature_mode_lights.m_num )
  {
    result = 0;
  }
  else
  {
    LIGHTINFO::SetDirection(this->creature_mode_lights.m_data[i_index], i_direction);
    result = 1;
  }
  return result;
}

//----- (004544F0) --------------------------------------------------------  // acclient.c:145408
int __thiscall InterfacePtr<CObjectMaint>::_QueryInterface(void *this, int a2, int a3, int a4)
{
  int v4; // edi@1
  void *v5; // esi@1
  int v6; // eax@2
  signed int v7; // ebx@2
  int v8; // ecx@2
  int v10; // ebp@6
  int v11; // ecx@9
  char v12; // [sp+10h] [bp-4h]@2

  v4 = a3;
  v5 = this;
  if ( a3 )
  {
    v6 = *(_DWORD *)a3;
    a3 = 0;
    v7 = *(_DWORD *)(*(int (__thiscall **)(int, char *, Turbine_GUID *, int *))(v6 + 12))(
                      v4,
                      &v12,
                      &CObjectMaint_InterfaceType_4,
                      &a3);
    v8 = *(_DWORD *)v5;
    if ( v7 < 0 )
    {
      if ( v8 )
        (*(void (**)(void))(*(_DWORD *)v8 + 20))();
      *(_DWORD *)v5 = 0;
      *((_DWORD *)v5 + 1) = 0;
      *(_DWORD *)a2 = v7;
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
      return a2;
    }
    v10 = a3;
    if ( v8 )
      (*(void (**)(void))(*(_DWORD *)v8 + 20))();
    *(_DWORD *)v5 = v10;
    *((_DWORD *)v5 + 1) = 0;
  }
  else
  {
    v11 = *(_DWORD *)this;
    if ( *(_DWORD *)v5 )
    {
      *(_DWORD *)v5 = 0;
      (*(void (**)(void))(*(_DWORD *)v11 + 20))();
      *((_DWORD *)v5 + 1) = 0;
    }
    v7 = -2147467262;
  }
  *(_DWORD *)a2 = v7;
  if ( v4 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
  return a2;
}

//----- (004545A0) --------------------------------------------------------  // acclient.c:145465
void __thiscall SmartBox::SmartBox(SmartBox *this, NIList<NetBlob *> *_in_queue)
{
  SmartBox *v2; // esi@1
  char *v3; // ecx@1
  int v4; // ecx@1
  char *v5; // edi@1
  char *v6; // edi@4
  char *v7; // edi@7
  char *v8; // edi@10
  PStringBase<char> _Description; // [sp+10h] [bp-50h]@1
  int v10; // [sp+14h] [bp-4Ch]@1
  int v11; // [sp+18h] [bp-48h]@1
  int v12; // [sp+1Ch] [bp-44h]@1
  Frame v13; // [sp+20h] [bp-40h]@13

  v2 = this;
  this->vfptr = (SmartBoxVtbl *)&SmartBox::vftable;
  this->testMode = 0;
  v3 = (char *)&this->viewer.frame;
  v2->viewer.objcell_id = 0;
  v2->viewer.vfptr = (PackObjVtbl *)&Position::vftable;
  *(_DWORD *)v3 = 1065353216;
  *((_DWORD *)v3 + 1) = 0;
  *((_DWORD *)v3 + 2) = 0;
  *((_DWORD *)v3 + 3) = 0;
  *((_DWORD *)v3 + 13) = 0;
  *((_DWORD *)v3 + 14) = 0;
  *((_DWORD *)v3 + 15) = 0;
  Frame::cache((Frame *)v3);
  v2->viewer_cell = 0;
  v2->head_index = 16;
  v4 = (int)&v2->viewer_sought_position.frame;
  v2->viewer_sought_position.vfptr = (PackObjVtbl *)&Position::vftable;
  v2->viewer_sought_position.objcell_id = 0;
  *(_DWORD *)v4 = 1065353216;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = 0;
  *(_DWORD *)(v4 + 52) = 0;
  *(_DWORD *)(v4 + 56) = 0;
  *(_DWORD *)(v4 + 60) = 0;
  Frame::cache(&v2->viewer_sought_position.frame);
  v2->in_queue = _in_queue;
  v2->camera_manager = 0;
  v2->cell_manager = 0;
  v2->physics = 0;
  v2->m_pObjMaint = 0;
  v2->lscape = 0;
  v2->ambient_sounds = 0;
  v2->cmdinterp = 0;
  v2->creature_mode = 0;
  LODWORD(v2->m_fGameFOV) = 1070141403;
  LODWORD(v2->m_fViewDistFOV) = 0;
  v2->m_bUseViewDistance = 0;
  LODWORD(v2->game_ambient_level) = 0;
  v2->game_degrades_disabled = 0;
  v2->hidden = 0;
  v2->position_update_complete = 0;
  v2->waiting_for_teleport = 0;
  v2->has_been_teleported = 0;
  v2->netblob_list = 0;
  v2->position_and_movement_file = 0;
  v2->player_id = 0;
  v2->player = 0;
  v2->target_object_id = 0;
  v2->target_callback = 0;
  v2->num_cells = 0;
  v2->cells = 0;
  v2->num_objects = 0;
  v2->objects = 0;
  v2->m_renderingCallback = 0;
  LODWORD(viewer_sphere.x) = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  LODWORD(viewer_sphere.y) = 0;
  LODWORD(viewer_sphere.z) = 0;
  dword_83CC20 = 1050253722;
  PStringBase<char>::PStringBase<char>(&_Description, "The intensity of the player light");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_in_queue, "SmartBox.ViewerLightIntensity");
  GlobalRegistry::RegisterVariableInternal(
    &SmartBox::s_fViewerLightIntensity,
    GRVDataType_Float32,
    (PStringBase<char> *)&_in_queue,
    &_Description,
    0,
    0,
    0,
    0);
  v5 = (char *)&_in_queue[-3].tail_;
  if ( !InterlockedDecrement((volatile LONG *)&_in_queue[-2]) && v5 )
    (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
  v6 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "The falloff distance of the player light");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_in_queue, "SmartBox.ViewerLightFalloff");
  GlobalRegistry::RegisterVariableInternal(
    &SmartBox::s_fViewerLightFalloff,
    GRVDataType_Float32,
    (PStringBase<char> *)&_in_queue,
    &_Description,
    0,
    0,
    0,
    0);
  v7 = (char *)&_in_queue[-3].tail_;
  if ( !InterlockedDecrement((volatile LONG *)&_in_queue[-2]) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  v8 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
  viewer_light.type = 0;
  LODWORD(v13.qw) = 1065353216;
  LODWORD(v13.qx) = 0;
  LODWORD(v13.qy) = 0;
  LODWORD(v13.qz) = 0;
  LODWORD(v13.m_fOrigin.x) = 0;
  LODWORD(v13.m_fOrigin.y) = 0;
  LODWORD(v13.m_fOrigin.z) = 0;
  Frame::cache(&v13);
  Frame::operator=((int)&stru_818684, (int)&v13);
  RGBColor::SetColor32(&stru_8186D0, 0xFFFFFFFF);
  unk_8186DC = LODWORD(SmartBox::s_fViewerLightIntensity);
  unk_8186E0 = LODWORD(SmartBox::s_fViewerLightFalloff);
  unk_8186E4 = 1135869952;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 79B76C: using guessed type int (__thiscall *SmartBox::vftable)(void *, char);
// 818610: using guessed type float SmartBox::s_fViewerLightFalloff;
// 83CC10: using guessed type float SmartBox::s_fViewerLightIntensity;
// 83CC20: using guessed type int dword_83CC20;

//----- (00454880) --------------------------------------------------------  // acclient.c:145599
void __thiscall SmartBox::~SmartBox(SmartBox *this)
{
  SmartBox *v1; // esi@1
  char *v2; // edi@1
  char *v3; // edi@4
  CameraManager *v4; // eax@7
  CameraManager *v5; // eax@10
  CellManager *v6; // eax@13
  void *v7; // edi@14
  CommandInterpreter *v8; // ecx@17
  CommandInterpreter *v9; // ecx@18
  Ambient *v10; // ecx@21
  void *v11; // edi@22
  void *v12; // edi@25
  void *v13; // edi@27
  CObjectMaint *v14; // ecx@29
  GameTime *v15; // edi@32
  PStringBase<char> _Name; // [sp+10h] [bp-4h]@1

  v1 = this;
  this->vfptr = (SmartBoxVtbl *)&SmartBox::vftable;
  SmartBox::Reset(this, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "SmartBox.ViewerLightIntensity");
  GlobalRegistry::UnregisterVariable(&_Name);
  v2 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "SmartBox.ViewerLightFalloff");
  GlobalRegistry::UnregisterVariable(&_Name);
  v3 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = v1->camera_manager;
  if ( v4 )
  {
    if ( ICIDM::s_cidm )
      ((void (__stdcall *)(_DWORD, _DWORD))ICIDM::s_cidm->vfptr->UnregisterInputHandler)(v4, 4);
    v5 = v1->camera_manager;
    if ( v5 )
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    v1->camera_manager = 0;
  }
  v6 = v1->cell_manager;
  if ( v6 )
  {
    v6->ambient_sounds = 0;
    v7 = v1->cell_manager;
    if ( v7 )
    {
      CellManager::~CellManager(v1->cell_manager);
      operator delete(v7);
    }
    v1->cell_manager = 0;
  }
  v8 = v1->cmdinterp;
  if ( v8 )
  {
    ((void (__stdcall *)(_DWORD))v8->vfptr[7].OnLoseFocus)(0);
    v9 = v1->cmdinterp;
    if ( v9 )
      ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
    v1->cmdinterp = 0;
  }
  CObjCell::SetObjectMaintainer(0);
  CPhysicsObj::SetObjectMaintainer(0);
  CWeenieObject::objMaint = 0;
  CObjCell::landscape = 0;
  v10 = v1->ambient_sounds;
  if ( v10 )
  {
    Ambient::FlushSoundTables(v10);
    v11 = v1->ambient_sounds;
    if ( v11 )
    {
      Ambient::~Ambient(v1->ambient_sounds);
      operator delete(v11);
    }
    v1->ambient_sounds = 0;
  }
  v12 = v1->lscape;
  if ( v12 )
  {
    LScape::~LScape(v1->lscape);
    operator delete(v12);
    v1->lscape = 0;
  }
  v13 = v1->physics;
  if ( v13 )
  {
    CPhysics::~CPhysics(v1->physics);
    operator delete(v13);
    v1->physics = 0;
  }
  v14 = v1->m_pObjMaint;
  if ( v14 )
  {
    ((void (*)(void))v14->vfptr->Release)();
    v1->m_pObjMaint = 0;
  }
  CRegionDesc::RemoveCurrentRegion();
  if ( GameTime::current_game_time )
  {
    v15 = GameTime::current_game_time;
    GameTime::~GameTime(GameTime::current_game_time);
    operator delete(v15);
    GameTime::current_game_time = 0;
  }
  v1->viewer_sought_position.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->viewer.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 79B76C: using guessed type int (__thiscall *SmartBox::vftable)(void *, char);

//----- (00454A70) --------------------------------------------------------  // acclient.c:145713
void __thiscall SmartBox::ProcessNetBlobs(SmartBox *this)
{
  SmartBox *v1; // edi@1
  NIList<NetBlob *> *v2; // eax@1
  NIList<NetBlob *> *v3; // ecx@3
  NIListElement<NetBlob *> *v4; // eax@3
  NetBlob *v5; // esi@4
  NIListElement<NetBlob *> *v6; // edx@5
  void *v7; // esi@15

  v1 = this;
  v2 = this->netblob_list;
  if ( v2 )
  {
    if ( v2->head_ )
    {
      do
      {
        v3 = v1->netblob_list;
        v4 = v3->head_;
        if ( v3->head_ )
        {
          v6 = v4->next_;
          v3->head_ = v6;
          if ( !v6 )
            v3->tail_ = 0;
          v5 = v4->data_;
          operator delete(v4);
        }
        else
        {
          v5 = 0;
        }
        if ( v1->vfptr->IsReadyToDispatchEvent(v1, v5) )
          v1->vfptr->DispatchSmartBoxEvent(v1, v5);
        else
          SmartBox::QueueNetBlob(v1, v5);
        if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
          v5->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 1u);
      }
      while ( v1->netblob_list->head_ );
    }
    v7 = v1->netblob_list;
    if ( v7 )
    {
      NIList<unsigned long>::DeleteContents((NIList<NetPacket *> *)v1->netblob_list);
      operator delete(v7);
    }
    v1->netblob_list = 0;
  }
}

//----- (00454B20) --------------------------------------------------------  // acclient.c:145766
void __thiscall SmartBox::ProcessObjectNetBlobs(SmartBox *this, CPhysicsObj *object)
{
  CWeenieObject *v2; // ecx@1
  NIList<NetBlob *> *v3; // eax@3
  void *v4; // edi@4
  void *v5; // ebx@4
  NIListElement<NetBlob *> *v6; // ecx@5
  NetBlob *v7; // esi@6
  NIListElement<NetBlob *> *v8; // edx@7
  void *v9; // eax@10
  void *v10; // eax@18
  int v11; // esi@18
  void *v12; // esi@25
  void *v13; // eax@26
  SmartBox *v14; // [sp+8h] [bp-4h]@1

  v14 = this;
  v2 = object->weenie_obj;
  if ( v2 )
    ((void (*)(void))v2->vfptr[2].__vecDelDtor)();
  v3 = object->netblob_list;
  if ( v3 )
  {
    v4 = 0;
    v5 = 0;
    if ( v3->head_ )
    {
      do
      {
        v6 = v3->head_;
        if ( v3->head_ )
        {
          v8 = v6->next_;
          v3->head_ = v8;
          if ( !v8 )
            v3->tail_ = 0;
          v7 = v6->data_;
          operator delete(v6);
        }
        else
        {
          v7 = 0;
        }
        v9 = operator new(8u);
        if ( v9 )
        {
          *(_DWORD *)v9 = v7;
          *((_DWORD *)v9 + 1) = 0;
        }
        else
        {
          v9 = 0;
        }
        if ( v5 )
          *((_DWORD *)v5 + 1) = v9;
        else
          v4 = v9;
        v5 = v9;
        v3 = object->netblob_list;
      }
      while ( v3->head_ );
      while ( v4 )
      {
        v10 = v4;
        v4 = (void *)*((_DWORD *)v4 + 1);
        v11 = *(_DWORD *)v10;
        operator delete(v10);
        if ( ((int (__stdcall *)(int))v14->vfptr->IsReadyToDispatchEvent)(v11) )
          ((void (__stdcall *)(int))v14->vfptr->DispatchSmartBoxEvent)(v11);
        else
          SmartBox::QueueNetBlob(v14, (NetBlob *)v11);
        if ( !InterlockedDecrement((volatile LONG *)(v11 + 4)) && v11 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      }
    }
    v12 = v4;
    while ( v12 )
    {
      v13 = v12;
      v12 = (void *)*((_DWORD *)v12 + 1);
      operator delete(v13);
    }
  }
}

//----- (00454C20) --------------------------------------------------------  // acclient.c:145852
void __usercall SmartBox::DrawNoBlit(SmartBox *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  SmartBox *v3; // esi@1
  int v4; // esi@5

  v3 = this;
  SmartBox::SetNormalMode(this);
  if ( v3->player )
  {
    SmartBox::update_viewer(v3);
    if ( v3->viewer_cell )
      SmartBox::RenderNormalMode(v3, a2, a3);
  }
  if ( SmartBox::lookingForObject )
  {
    v4 = Render::GetMouseSelectionPartIndex();
    SmartBox::click_object_id = Render::GetMouseSelectionObjectID();
    SmartBox::click_object_index = v4;
    ECM_UI::SendNotice_SmartBoxObjectFound(SmartBox::click_object_id);
    SmartBox::lookingForObject = 0;
  }
  Render::clear_selection_cursor();
}
// 818618: using guessed type int SmartBox::click_object_index;
// 83CA44: using guessed type unsigned __int32 SmartBox::click_object_id;
// 83CA48: using guessed type bool SmartBox::lookingForObject;

//----- (00454C80) --------------------------------------------------------  // acclient.c:145880
signed int __userpurge SmartBox::HandleCreateObject@<eax>(SmartBox *this@<ecx>, double a2@<st0>, NetBlob *blob, unsigned int object_id, VisualDesc *vdesc, PhysicsDesc *physicsdesc, WeenieDesc *wdesc, int force_recreate)
{
  SmartBox *v8; // edi@1
  unsigned int v9; // eax@1
  unsigned int v10; // ebx@1
  signed int v11; // eax@3
  CPhysicsObj *v12; // eax@5
  unsigned __int16 v13; // ax@7
  unsigned __int16 v14; // bp@8
  unsigned __int16 v15; // ax@9
  unsigned __int16 v16; // ax@9
  unsigned __int16 v17; // bx@10
  unsigned __int16 v18; // bp@10
  int v19; // eax@10
  float v20; // eax@11
  float v21; // ecx@11
  unsigned __int16 v22; // ST1C_2@11
  unsigned int v23; // eax@11
  unsigned __int16 v24; // ST1C_2@13
  unsigned int v25; // ST18_4@13
  unsigned int v26; // eax@13
  int v27; // ST1C_4@15
  unsigned __int16 v28; // ST18_2@15
  unsigned __int16 v29; // ST14_2@15
  unsigned int v30; // ST10_4@15
  void *v31; // eax@15
  CPhysics *v32; // ecx@15
  unsigned __int16 v33; // ax@16
  unsigned __int16 v34; // ax@16
  float v35; // edx@16
  float v36; // ecx@16
  unsigned __int16 v37; // ST1C_2@16
  AC1Legacy::Vector3 *v38; // eax@16
  CWeenieObject *v39; // eax@16
  int v40; // eax@32
  unsigned int v41; // edx@32
  CPhysicsObj *v42; // eax@32
  unsigned int v43; // edx@35
  CPhysicsObj *v44; // ecx@35
  Position *v45; // eax@40
  CPhysicsObj *object; // [sp+14h] [bp-BCh]@1
  CWeenieObject *wobject; // [sp+18h] [bp-B8h]@1
  int force_position_timestamp; // [sp+1Ch] [bp-B4h]@7
  CPhysicsObj *parent; // [sp+20h] [bp-B0h]@1
  AC1Legacy::Vector3 velocity; // [sp+24h] [bp-ACh]@11
  IDClass<_tagDataID,32,0> result; // [sp+30h] [bp-A0h]@8
  Position p; // [sp+34h] [bp-9Ch]@10
  AC1Legacy::Vector3 v53; // [sp+7Ch] [bp-54h]@16
  Position v54; // [sp+88h] [bp-48h]@32

  v8 = this;
  parent = 0;
  object = 0;
  wobject = 0;
  v9 = PhysicsDesc::get_parent_id(physicsdesc);
  v10 = v9;
  if ( v9 )
  {
    parent = (CPhysicsObj *)CObjectMaint::GetObjectA(v8->m_pObjMaint, v9);
    if ( !parent )
    {
      CObjectMaint::QueueBlobForObject(v8->m_pObjMaint, v10, blob);
      return 4;
    }
  }
  if ( !CObjectMaint::GetObjectA(v8->m_pObjMaint, object_id, &object, &wobject) )
    goto LABEL_45;
  v12 = object;
  if ( !object )
  {
LABEL_27:
    if ( !wobject )
    {
LABEL_29:
      object = (CPhysicsObj *)((int (__stdcall *)(unsigned int, VisualDesc *, PhysicsDesc *, WeenieDesc *))v8->m_pObjMaint->vfptr[1].Release)(
                                object_id,
                                vdesc,
                                physicsdesc,
                                wdesc);
      if ( !object )
        return 3;
      if ( object_id == v8->player_id )
      {
        v40 = PhysicsDesc::get_autonomous_movement((ChatRoomTracker *)physicsdesc);
        SmartBox::init_player(v8, object, v40);
        v41 = physicsdesc->pos.objcell_id;
        v54.vfptr = (PackObjVtbl *)&Position::vftable;
        v54.objcell_id = v41;
        Frame::operator=((int)&v54.frame, (int)&physicsdesc->pos.frame);
        CPhysicsObj::store_position(object, &v54);
        v42 = v8->player;
        if ( v42 && v42->m_position.objcell_id )
          CellManager::ChangePosition(v8->cell_manager, a2, &v42->m_position, 1);
        v43 = physicsdesc->pos.objcell_id;
        p.vfptr = (PackObjVtbl *)&Position::vftable;
        p.objcell_id = v43;
        Frame::operator=((int)&p.frame, (int)&physicsdesc->pos.frame);
        v44 = v8->player;
        if ( v44 )
        {
          CPhysicsObj::enter_world(v44, &p);
          SmartBox::PlayerPositionUpdated(v8, a2, 1, 3.4028235e38);
        }
        ((void (__stdcall *)(VisualDesc *))v8->m_pObjMaint->vfptr[2].IUnknown_QueryInterface)(vdesc);
      }
      else if ( !PhysicsDesc::get_parent_id(physicsdesc) )
      {
        p.objcell_id = physicsdesc->pos.objcell_id;
        Frame::operator=((int)&p.frame, (int)&physicsdesc->pos.frame);
        if ( p.objcell_id )
        {
          v45 = PhysicsDesc::get_position(physicsdesc, &p);
          CPhysicsObj::enter_world(object, v45);
        }
      }
      SmartBox::ProcessObjectNetBlobs(v8, object);
      return 1;
    }
LABEL_28:
    v8->m_pObjMaint->vfptr[1].IUnknown_AddRef((Interface *)object_id);
    goto LABEL_29;
  }
  if ( force_recreate )
  {
LABEL_26:
    if ( v12 )
      goto LABEL_28;
    goto LABEL_27;
  }
  LOWORD(force_position_timestamp) = object->update_times[8];
  v13 = PhysicsDesc::get_timestamp(physicsdesc, INSTANCE_TS);
  if ( CPhysicsObj::is_newer(force_position_timestamp, v13) )
  {
LABEL_45:
    v12 = object;
    goto LABEL_26;
  }
  CPhysicsObj::GetSetupID(object, (IDClass<_tagDataID,32,0> *)&force_position_timestamp);
  PhysicsDesc::get_setup_id(physicsdesc, &result);
  v14 = object->update_times[8];
  if ( v14 != PhysicsDesc::get_timestamp(physicsdesc, INSTANCE_TS) )
    return 2;
  v15 = PhysicsDesc::get_timestamp(physicsdesc, OBJDESC_TS);
  SmartBox::UpdateVisualDesc(v8, object, vdesc, v15);
  v16 = PhysicsDesc::get_timestamp(physicsdesc, 0);
  if ( v10 )
  {
    v24 = v16;
    v25 = PhysicsDesc::get_animframe_id((ChatRoomTracker *)physicsdesc);
    v26 = PhysicsDesc::get_parent_location_id((ACCharGenResult *)physicsdesc);
    SmartBox::DoParentEvent(v8, object, parent, v26, v25, v24);
  }
  else
  {
    v17 = v16;
    v18 = PhysicsDesc::get_timestamp(physicsdesc, TELEPORT_TS);
    LOWORD(v19) = PhysicsDesc::get_timestamp(physicsdesc, FORCE_POSITION_TS);
    force_position_timestamp = v19;
    PhysicsDesc::get_position(physicsdesc, &p);
    if ( p.objcell_id )
    {
      v20 = physicsdesc->velocity.y;
      v21 = physicsdesc->velocity.z;
      velocity.x = physicsdesc->velocity.x;
      v22 = force_position_timestamp;
      velocity.y = v20;
      velocity.z = v21;
      v23 = PhysicsDesc::get_animframe_id((ChatRoomTracker *)physicsdesc);
      SmartBox::HandleReceivedPosition(v8, a2, object, &p, v23, 1, &velocity, v17, v18, v22);
    }
    else
    {
      SmartBox::DoPickupEvent(object, v17);
    }
  }
  if ( ChatRoomTracker::GetGlobalTradeRoomID((ChatRoomTracker *)physicsdesc) )
  {
    v27 = PhysicsDesc::get_autonomous_movement((ChatRoomTracker *)physicsdesc);
    v28 = PhysicsDesc::get_timestamp(physicsdesc, SERVER_CONTROLLED_MOVE_TS);
    v29 = PhysicsDesc::get_timestamp(physicsdesc, MOVEMENT_TS);
    v30 = ChatRoomTracker::GetGlobalTradeRoomID((ChatRoomTracker *)physicsdesc);
    v31 = (void *)HookAppraisalProfile::GetValidLocations((ChatDisplayInfo *)physicsdesc);
    v32 = v8->physics;
    CPhysics::SetObjectMovement(object, v31, v30, v29, v28, v27);
  }
  v33 = PhysicsDesc::get_timestamp(physicsdesc, STATE_TS);
  SmartBox::DoSetState(v8, object, physicsdesc->state, v33);
  v34 = PhysicsDesc::get_timestamp(physicsdesc, VECTOR_TS);
  v35 = physicsdesc->velocity.y;
  velocity.x = physicsdesc->velocity.x;
  v36 = physicsdesc->velocity.z;
  velocity.y = v35;
  v37 = v34;
  velocity.z = v36;
  v38 = PhysicsDesc::get_omega(physicsdesc, &v53);
  SmartBox::DoVectorUpdate(v8, object, &velocity, v38, v37);
  v39 = wobject;
  if ( wobject )
  {
    ((void (__stdcall *)(CWeenieObject *, WeenieDesc *, signed int))v8->m_pObjMaint->vfptr[1].AddRef)(wobject, wdesc, 1);
    v39 = wobject;
  }
  if ( !object->m_position.objcell_id )
  {
    if ( !v39 )
    {
      CObjectMaint::AddObjectToBeDestroyed(v8->m_pObjMaint, object->id);
      return 1;
    }
    return 1;
  }
  if ( object->cell )
  {
    CObjectMaint::RemoveObjectToBeDestroyed(v8->m_pObjMaint, object->id);
    v11 = 1;
  }
  else
  {
    CObjectMaint::AddObjectToBeDestroyed(v8->m_pObjMaint, object->id);
    v11 = 1;
  }
  return v11;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00455110) --------------------------------------------------------  // acclient.c:146106
signed int __thiscall SmartBox::HandleCreatePlayer(SmartBox *this, NetBlob *blob, unsigned int object_id)
{
  SmartBox *v3; // esi@1
  signed int result; // eax@2

  v3 = this;
  if ( this->player_id )
  {
    result = 3;
  }
  else
  {
    this->player_id = object_id;
    SmartBox::ProcessNetBlobs(this);
    ((void (*)(void))v3->cmdinterp->vfptr[11].OnAction)();
    result = 1;
  }
  return result;
}

//----- (00455150) --------------------------------------------------------  // acclient.c:146127
void __thiscall CreatureMode::~CreatureMode(CreatureMode *this)
{
  CreatureMode *v1; // esi@1
  CEnvCell *v2; // ecx@1

  v1 = this;
  CreatureMode::RemoveAllObjects(this);
  v2 = v1->creature_cell;
  if ( v2 )
    ((void (__stdcall *)(signed int))v2->vfptr[1].IUnknown_QueryInterface)(1);
  v1->creature_cell = 0;
  if ( (v1->creature_mode_lights.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->creature_mode_lights.m_data);
  if ( (v1->creature_mode_objects.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->creature_mode_objects.m_data);
}

//----- (004551B0) --------------------------------------------------------  // acclient.c:146145
void __thiscall InterfacePtr<CObjectMaint>::InterfacePtr<CObjectMaint>(InterfacePtr<CObjectMaint> *this, InterfacePtr<Interface> *_ptr)
{
  InterfacePtr<Interface> *v2; // edx@1
  InterfacePtr<CObjectMaint> *v3; // esi@1
  int v4; // [sp-8h] [bp-Ch]@1

  v2 = _ptr;
  v3 = this;
  this->m_pInterface = 0;
  this->m_trStatus.m_val = 0;
  v4 = (int)v2->m_pInterface;
  if ( v2->m_pInterface )
    v2->m_pInterface->vfptr->AddRef(v2->m_pInterface);
  v3->m_trStatus.m_val = *(_DWORD *)InterfacePtr<CObjectMaint>::_QueryInterface(v3, (int)&_ptr, v4, 0);
}

//----- (004551F0) --------------------------------------------------------  // acclient.c:146162
char __thiscall SmartBox::InitInternal(SmartBox *this, NIList<NetBlob *> *_in_queue)
{
  SmartBox *v2; // esi@1
  InterfaceSystem *v3; // eax@1
  void *v4; // edi@1
  CObjectMaint *v5; // eax@5
  bool v6; // zf@6
  CPhysics *v7; // eax@8
  CPhysics *v8; // eax@9
  LScape *v9; // eax@12
  LScape *v10; // eax@13
  Ambient *v11; // eax@16
  Ambient *v12; // eax@17
  int v13; // eax@20
  CellManager *v14; // eax@21
  CellManager *v15; // eax@22
  CameraManager *v16; // eax@25
  CameraManager *v17; // eax@26
  char v18; // al@30
  int v19; // [sp-8h] [bp-28h]@1
  void *_ppNewInstance; // [sp+Ch] [bp-14h]@1
  TResult result; // [sp+10h] [bp-10h]@1
  char v22; // [sp+14h] [bp-Ch]@3
  InterfacePtr<CObjectMaint> spObjMaint; // [sp+18h] [bp-8h]@1

  v2 = this;
  _ppNewInstance = 0;
  v3 = InterfaceSystem::GetInstance();
  InterfaceSystem::CreateInstance(
    v3,
    &result,
    &CObjectMaint_Factory_ClassType,
    &Interface_InterfaceType_21,
    0,
    &_ppNewInstance);
  v19 = (int)_ppNewInstance;
  v4 = _ppNewInstance;
  spObjMaint.m_pInterface = 0;
  spObjMaint.m_trStatus.m_val = 0;
  if ( _ppNewInstance )
    (*(void (__thiscall **)(void *))(*(_DWORD *)_ppNewInstance + 16))(_ppNewInstance);
  InterfacePtr<CObjectMaint>::_QueryInterface(&spObjMaint, (int)&v22, v19, 0);
  if ( v4 )
    (*(void (__thiscall **)(void *))(*(_DWORD *)v4 + 20))(v4);
  v5 = spObjMaint.m_pInterface;
  if ( !(_DWORD)spObjMaint.m_pInterface )
    goto LABEL_34;
  v6 = v2->testMode == 0;
  v2->m_pObjMaint = spObjMaint.m_pInterface;
  if ( !v6 )
    v5->is_active = 0;
  v7 = (CPhysics *)operator new(0x10u);
  if ( v7 )
    CPhysics::CPhysics(v7, v2->m_pObjMaint, v2);
  else
    v8 = 0;
  v2->physics = v8;
  if ( v8
    && ((v9 = (LScape *)operator new(0x34u)) == 0 ? (v10 = 0) : LScape::LScape(v9),
        (v2->lscape = v10) != 0
     && ((v11 = (Ambient *)operator new(0x74u)) == 0 ? (v12 = 0) : Ambient::Ambient(v11),
         (v2->ambient_sounds = v12) != 0
      && (((void (__stdcall *)(LScape *))RenderDevice::render_device->vfptr->SetLandscape)(v2->lscape),
          CObjCell::SetObjectMaintainer(v2->m_pObjMaint),
          CPhysicsObj::SetObjectMaintainer(v2->m_pObjMaint),
          CWeenieObject::objMaint = v2->m_pObjMaint,
          CObjCell::landscape = v2->lscape,
          v13 = CFactory::MakeCommandInterpreter(),
          (v2->cmdinterp = (CommandInterpreter *)v13) != 0)
      && (((*(void (__thiscall **)(int, SmartBox *))(*(_DWORD *)v13 + 92))(v13, SmartBox::smartbox),
           ((void (__stdcall *)(unsigned int))v2->cmdinterp->vfptr[14].OnLoseFocus)(command_line_autonomy_level),
           (v14 = (CellManager *)operator new(0x78u)) == 0) ? (v15 = 0) : CellManager::CellManager(v14),
          (v2->cell_manager = v15) != 0
       && ((v15->lscape = v2->lscape,
            v2->cell_manager->ambient_sounds = v2->ambient_sounds,
            (v16 = (CameraManager *)operator new(0xC0u)) == 0) ? (v17 = 0) : CameraManager::CameraManager(v16),
           (v2->camera_manager = v17) != 0 && ICIDM::s_cidm)))) )
  {
    ((void (__stdcall *)(CameraManager *, signed int))ICIDM::s_cidm->vfptr->RegisterInputHandler)(v17, 4);
    SmartBox::set_viewer_home(v2);
    v18 = 1;
    v2->hidden = 1;
  }
  else
  {
LABEL_34:
    v18 = 0;
  }
  return v18;
}
// 818614: using guessed type unsigned int command_line_autonomy_level;

//----- (00455410) --------------------------------------------------------  // acclient.c:146255
void __usercall SmartBox::UseTime(SmartBox *this@<ecx>, double a2@<st0>)
{
  SmartBox *v2; // esi@1
  CellManager *v3; // ecx@1
  CPhysicsObj *v4; // eax@6
  NIList<NetBlob *> *v5; // ecx@17
  NIListElement<NetBlob *> *v6; // eax@17
  NetBlob *v7; // edi@18
  NIListElement<NetBlob *> *v8; // edx@19

  v2 = this;
  v3 = this->cell_manager;
  if ( v3->blocking_for_cells )
  {
    CellManager::CheckPrefetchStatus(v3);
  }
  else
  {
    if ( !v3->all_cells_available && CellManager::CheckPrefetchStatus(v3) )
      CellManager::UpdateLoadPoint(v2->cell_manager);
    v4 = v2->player;
    if ( v4 && v4->m_position.objcell_id )
      CellManager::ChangePosition(v2->cell_manager, a2, &v4->m_position, 0);
    if ( v2->player && !v2->waiting_for_teleport && !v2->position_update_complete )
    {
      v2->position_update_complete = 1;
      v2->has_been_teleported = 1;
    }
    CObjectMaint::UseTime(v2->m_pObjMaint);
    CPhysics::UseTime(v2->physics);
    if ( GameTime::current_game_time )
    {
      GameTime::UseTime(GameTime::current_game_time);
      LScape::UseTime(v2->lscape);
    }
    Ambient::UseTime(v2->ambient_sounds);
  }
  SceneTool::Think();
  if ( v2->in_queue )
  {
    while ( 1 )
    {
      v5 = v2->in_queue;
      v6 = v5->head_;
      if ( v5->head_ )
      {
        v8 = v6->next_;
        v5->head_ = v8;
        if ( !v8 )
          v5->tail_ = 0;
        v7 = v6->data_;
        operator delete(v6);
      }
      else
      {
        v7 = 0;
      }
      if ( !v7 )
        break;
      if ( v2->vfptr->IsReadyToDispatchEvent(v2, v7) )
        v2->vfptr->DispatchSmartBoxEvent(v2, v7);
      else
        SmartBox::QueueNetBlob(v2, v7);
      if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) )
        v7->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v7, 1u);
    }
  }
  if ( !v2->testMode )
    ((void (*)(void))v2->cmdinterp->vfptr[14].__vecDelDtor)();
  Render::CalcDegLevel();
}

//----- (00455570) --------------------------------------------------------  // acclient.c:146328
void __usercall SmartBox::Draw(SmartBox *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  if ( !this->hidden )
    SmartBox::DrawNoBlit(this, a2, a3);
}

//----- (00455580) --------------------------------------------------------  // acclient.c:146335
signed int __userpurge SmartBox::HandleUpdateObject@<eax>(SmartBox *this@<ecx>, double a2@<st0>, NetBlob *blob, unsigned int object_id, VisualDesc *objdesc, PhysicsDesc *physicsdesc, WeenieDesc *wdesc)
{
  return SmartBox::HandleCreateObject(this, a2, blob, object_id, objdesc, physicsdesc, wdesc, 1);
}

//----- (004555B0) --------------------------------------------------------  // acclient.c:146341
void __thiscall CreatureMode::AddLight(CreatureMode *this, LIGHTINFO::LightType _lightType, float _intensity)
{
  CreatureMode *v3; // edi@1
  void *v4; // esi@1
  int v5; // ecx@2
  int v6; // edi@4
  int v7; // eax@4
  unsigned int v8; // eax@5
  AC1Legacy::Vector3 _direction; // [sp+8h] [bp-Ch]@4

  v3 = this;
  v4 = operator new(0x68u);
  if ( v4 )
  {
    v5 = (int)((char *)v4 + 4);
    *(_DWORD *)v5 = 1065353216;
    *(_DWORD *)(v5 + 4) = 0;
    *(_DWORD *)(v5 + 8) = 0;
    *(_DWORD *)(v5 + 12) = 0;
    *(_DWORD *)(v5 + 52) = 0;
    *(_DWORD *)(v5 + 56) = 0;
    *(_DWORD *)(v5 + 60) = 0;
    Frame::cache((Frame *)((char *)v4 + 4));
  }
  else
  {
    v4 = 0;
  }
  *(_DWORD *)v4 = _lightType;
  LODWORD(_direction.x) = 1065353216;
  LODWORD(_direction.y) = 1065353216;
  LODWORD(_direction.z) = 1065353216;
  LIGHTINFO::SetDirection((LIGHTINFO *)v4, &_direction);
  *((float *)v4 + 23) = _intensity;
  RGBColor::SetColor32((RGBColor *)((char *)v4 + 80), 0xFFFFFFFF);
  v6 = (int)&v3->creature_mode_lights;
  *((_DWORD *)v4 + 24) = 2139095039;
  *((_DWORD *)v4 + 25) = 1135869952;
  v7 = *(_DWORD *)(v6 + 4) & 0x7FFFFFFF;
  if ( *(_DWORD *)(v6 + 8) < (unsigned int)v7
    || (v8 = SmartArray<UIChildFramework *,1>::get_new_size(v7 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v6, v8)) )
    *(_DWORD *)(*(_DWORD *)v6 + 4 * (*(_DWORD *)(v6 + 8))++) = v4;
}

//----- (00455670) --------------------------------------------------------  // acclient.c:146387
SmartBox *__cdecl SmartBox::Init(NIList<NetBlob *> *_in_queue, int test_mode)
{
  SmartBox *result; // eax@1

  result = (SmartBox *)CFactory::MakeSmartBox(_in_queue);
  SmartBox::smartbox = result;
  if ( result )
  {
    result->testMode = test_mode;
    if ( SmartBox::InitInternal(SmartBox::smartbox, _in_queue) )
    {
      Render::LinkRGRCallback((bool (__cdecl *)())SmartBox::ResetDetailTexturing);
      result = SmartBox::smartbox;
    }
    else
    {
      if ( SmartBox::smartbox )
        ((void (__stdcall *)(signed int))SmartBox::smartbox->vfptr->__vecDelDtor)(1);
      result = 0;
      SmartBox::smartbox = 0;
    }
  }
  return result;
}

//----- (004556D0) --------------------------------------------------------  // acclient.c:146413
char __thiscall CreatureMode::AddObject(CreatureMode *this, CPhysicsObj *i_pObject)
{
  CPhysicsObj *v2; // esi@1
  CreatureMode *v3; // edi@1
  char result; // al@3

  v2 = i_pObject;
  v3 = this;
  if ( i_pObject
    && SmartArray<QualityChangeHandler *,1>::add_unique(
         (SmartArray<UIElement *,1> *)this,
         (UIElement *const *)&i_pObject) )
  {
    CPhysicsObj::AddObjectToSingleCell(v2, (CObjCell *)&v3->creature_cell->vfptr);
    CPhysicsObj::SetPlacementFrame(v2, 0, 1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006E9220) --------------------------------------------------------  // acclient.c:765342
int _E73_58()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_4, "Display.Resolution");
  return atexit(_E74_42);
}

//----- (006E9240) --------------------------------------------------------  // acclient.c:765349
int _E76_28()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_4, "Display.FullScreen");
  return atexit(_E77_56);
}

//----- (006E9260) --------------------------------------------------------  // acclient.c:765356
int _E79_28()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_4, "Display.RefreshRate");
  return atexit(_E80_30);
}

//----- (006E9280) --------------------------------------------------------  // acclient.c:765363
int _E82_19()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_4, "Display.SyncToRefresh");
  return atexit(_E83_19);
}

//----- (006E92A0) --------------------------------------------------------  // acclient.c:765370
void _E85_15()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_32, PFID_A8R8G8B8);
}

//----- (006E92B0) --------------------------------------------------------  // acclient.c:765376
void _E103_11()
{
  LODWORD(dword_83CAD4) = 1053364187;
}

//----- (006E92C0) --------------------------------------------------------  // acclient.c:765382
void _E105_4()
{
  outside_val_18 = 1000.0 + 1.0;
}

//----- (006E92E0) --------------------------------------------------------  // acclient.c:765388
void _E107_0()
{
  block_length_18 = 24.0 * 8.0;
}

//----- (006E9300) --------------------------------------------------------  // acclient.c:765394
void _E109_10()
{
  half_square_length_18 = 24.0 * 0.5;
}

//----- (006E9320) --------------------------------------------------------  // acclient.c:765400
int _E111_6()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_13, "Render.TextureFiltering");
  return atexit(sub_75BA50);
}

//----- (006E9340) --------------------------------------------------------  // acclient.c:765407
int _E114_8()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_13, "Render.LandscapeDetailTextures");
  return atexit(sub_75BA80);
}

//----- (006E9360) --------------------------------------------------------  // acclient.c:765414
int _E117_6()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_13, "Render.BuildingDetailTextures");
  return atexit(sub_75BAB0);
}

//----- (006E9380) --------------------------------------------------------  // acclient.c:765421
int _E120_9()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_13, "Render.FieldOfView");
  return atexit(sub_75BAE0);
}

//----- (006E93A0) --------------------------------------------------------  // acclient.c:765428
int _E123_6()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_13, "Render.LandscapeTextureDetail");
  return atexit(sub_75BB10);
}

//----- (006E93C0) --------------------------------------------------------  // acclient.c:765435
int _E126_10()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_13, "Render.EnvironmentTextureDetail");
  return atexit(_E127_91);
}

//----- (006E93E0) --------------------------------------------------------  // acclient.c:765442
int _E129_9()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_13, "Render.SceneryDrawDistance");
  return atexit(_E130_83);
}

//----- (006E9400) --------------------------------------------------------  // acclient.c:765449
int _E132_10()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_13, "Render.LandscapeDrawDistance");
  return atexit(_E133_76);
}

//----- (006E9420) --------------------------------------------------------  // acclient.c:765456
int _E135_9()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_13, "Render.ScreenBrightness");
  return atexit(_E136_60);
}

//----- (006E9440) --------------------------------------------------------  // acclient.c:765463
int _E138_10()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_13, "Render.AspectRatio");
  return atexit(_E139_61);
}

//----- (006E9460) --------------------------------------------------------  // acclient.c:765470
int _E141_10()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_13, "Render.DisplayAdapter");
  return atexit(_E142_58);
}

//----- (006E9480) --------------------------------------------------------  // acclient.c:765477
int _E144_10()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_13, "Render.MaxHardwareClass");
  return atexit(_E145_60);
}

//----- (006E94A0) --------------------------------------------------------  // acclient.c:765484
int _E147_10()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_13, "Render.AutomaticDegrades");
  return atexit(_E148_59);
}

//----- (006E94C0) --------------------------------------------------------  // acclient.c:765491
int _E150_10()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_13, "Render.GraphicsPerformance");
  return atexit(_E151_57);
}

//----- (006E94E0) --------------------------------------------------------  // acclient.c:765498
int _E153_10()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_13, "Render.DegradeDistance");
  return atexit(_E154_58);
}

//----- (006E9500) --------------------------------------------------------  // acclient.c:765505
int _E156_11()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_13, "Render.MultiPassAlpha");
  return atexit(_E157_55);
}

//----- (006E9520) --------------------------------------------------------  // acclient.c:765512
int _E159_10()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_13, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_83CB2C, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_83CB30, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_83CB34, "Anisotropic");
  return atexit(_E160_58);
}

//----- (006E9570) --------------------------------------------------------  // acclient.c:765522
int _E162_11()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_13, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83CB3C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83CB40, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83CB44, "High");
  PStringBase<char>::PStringBase<char>(&stru_83CB48, "VeryHigh");
  return atexit(_E163_51);
}

//----- (006E95D0) --------------------------------------------------------  // acclient.c:765533
int _E165_10()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_13, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83CB50, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83CB54, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83CB58, "High");
  PStringBase<char>::PStringBase<char>(&stru_83CB5C, "VeryHigh");
  return atexit(_E166_53);
}

//----- (006E9630) --------------------------------------------------------  // acclient.c:765544
int _E168_11()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_13, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83CB64, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83CB68, "High");
  return atexit(_E169_52);
}

//----- (006E9670) --------------------------------------------------------  // acclient.c:765553
int _E171_11()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_13, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83CB70, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83CB74, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83CB78, "High");
  PStringBase<char>::PStringBase<char>(&stru_83CB7C, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_83CB80, "Extreme");
  return atexit(_E172_50);
}

//----- (006E96E0) --------------------------------------------------------  // acclient.c:765565
int _E174_11()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_13, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_83CB88, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_83CB8C, "Wide");
  return atexit(_E175_47);
}

//----- (006E9720) --------------------------------------------------------  // acclient.c:765574
int _E177_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_25, "None");
  return atexit(_E178_47);
}

//----- (006E9740) --------------------------------------------------------  // acclient.c:765581
int _E180_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_25, "Speed");
  return atexit(_E181_47);
}

//----- (006E9760) --------------------------------------------------------  // acclient.c:765588
int _E183_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_25, "Noise");
  return atexit(_E184_45);
}

//----- (006E9780) --------------------------------------------------------  // acclient.c:765595
int _E186_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_25, "Sine");
  return atexit(_E187_44);
}

//----- (006E97A0) --------------------------------------------------------  // acclient.c:765602
int _E189_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_25, "Square");
  return atexit(_E190_45);
}

//----- (006E97C0) --------------------------------------------------------  // acclient.c:765609
int _E192_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_25, "Bounce");
  return atexit(_E193_40);
}

//----- (006E97E0) --------------------------------------------------------  // acclient.c:765616
int _E195_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_25, "Perlin");
  return atexit(_E196_47);
}

//----- (006E9800) --------------------------------------------------------  // acclient.c:765623
int _E198_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_25, "Fractal");
  return atexit(_E199_39);
}

//----- (006E9820) --------------------------------------------------------  // acclient.c:765630
int _E201_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_25, "FrameLoop");
  return atexit(_E202_40);
}

//----- (006E9840) --------------------------------------------------------  // acclient.c:765637
void _E204_4()
{
  LOWEST_DATA_RATE_54 = 1024;
}

//----- (006E9850) --------------------------------------------------------  // acclient.c:765643
void _E206_0()
{
  HIGHEST_DATA_RATE_54 = 0x7FFF;
}

//----- (006E9860) --------------------------------------------------------  // acclient.c:765649
int _E208_9()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_54;
  INITIAL_MAX_DATA_RATE_2 = LOWEST_DATA_RATE_54;
  return result;
}

//----- (006E9870) --------------------------------------------------------  // acclient.c:765659
void _E210_4()
{
  DEFAULT_VIEW_RADIUS_5 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006E9890) --------------------------------------------------------  // acclient.c:765665
void _E212()
{
  MIN_QUANTUM_5 = 1.0 / 30.0;
}

//----- (006E98B0) --------------------------------------------------------  // acclient.c:765671
void _E214_8()
{
  MAX_QUANTUM_5 = 1.0 / 5.0;
}

//----- (006E98D0) --------------------------------------------------------  // acclient.c:765677
int _E216_5()
{
  return atexit(_E217_36);
}

//----- (006E98E0) --------------------------------------------------------  // acclient.c:765683
int _E219_3()
{
  return atexit(_E220_36);
}

//----- (006E98F0) --------------------------------------------------------  // acclient.c:765689
int _E222_3()
{
  return atexit(_E223_36);
}

//----- (006E9900) --------------------------------------------------------  // acclient.c:765695
int _E225_3()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_1, "Sound.SoundDisabled");
  return atexit(_E226_22);
}

//----- (006E9920) --------------------------------------------------------  // acclient.c:765702
int _E228_3()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_1, "Sound.SoundVolume");
  return atexit(_E229_22);
}

//----- (006E9940) --------------------------------------------------------  // acclient.c:765709
int _E231_3()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_1, "Sound.AmbientSoundDisabled");
  return atexit(_E232_22);
}

//----- (006E9960) --------------------------------------------------------  // acclient.c:765716
int _E234_3()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_1, "Sound.AmbientSoundVolume");
  return atexit(_E235_22);
}

//----- (006E9980) --------------------------------------------------------  // acclient.c:765723
int _E237_3()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_1, "Sound.InterfaceSoundDisabled");
  return atexit(_E238_20);
}

//----- (006E99A0) --------------------------------------------------------  // acclient.c:765730
int _E240_3()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_1, "Sound.InterfaceSoundVolume");
  return atexit(_E241_20);
}

//----- (006E99C0) --------------------------------------------------------  // acclient.c:765737
int _E243_3()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_1, "Sound.SoundFeatures");
  return atexit(_E244_20);
}

//----- (006E99E0) --------------------------------------------------------  // acclient.c:765744
int _E246_3()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_1, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E247_19);
}

//----- (006E9A00) --------------------------------------------------------  // acclient.c:765751
int _E249_3()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_1, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_83CBFC, "Mono");
  return atexit(_E250_19);
}

//----- (006E9A30) --------------------------------------------------------  // acclient.c:765759
void _E252_3()
{
  VOL_MIN_DIST_SQ_0 = 5.0 * 5.0;
}

//----- (006E9A50) --------------------------------------------------------  // acclient.c:765765
void _E254()
{
  INV_LOG_OF_2_0 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (006E9A70) --------------------------------------------------------  // acclient.c:765771
void _E260()
{
  SmartBox::s_fViewerLightIntensity = 0.5 * 4.5;
}
// 83CC10: using guessed type float SmartBox::s_fViewerLightIntensity;

//----- (006E9A90) --------------------------------------------------------  // acclient.c:765778
int _E262_8()
{
  return atexit(_E263_8);
}

//----- (006E9AA0) --------------------------------------------------------  // acclient.c:765784
int _E265_8()
{
  Frame::cache(&stru_818684);
  return atexit(_E266_8);
}

//----- (006E9AC0) --------------------------------------------------------  // acclient.c:765791
int _E1_47()
{
  return atexit(_E2_47);
}

//----- (0075B7C0) --------------------------------------------------------  // acclient.c:883330
void __cdecl _E226_22()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B7F0) --------------------------------------------------------  // acclient.c:883343
void __cdecl _E229_22()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B820) --------------------------------------------------------  // acclient.c:883356
void __cdecl _E232_22()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B850) --------------------------------------------------------  // acclient.c:883369
void __cdecl _E235_22()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B880) --------------------------------------------------------  // acclient.c:883382
void __cdecl _E238_20()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B8B0) --------------------------------------------------------  // acclient.c:883395
void __cdecl _E241_20()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B8E0) --------------------------------------------------------  // acclient.c:883408
void __cdecl _E244_20()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B910) --------------------------------------------------------  // acclient.c:883421
void __cdecl _E247_19()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B940) --------------------------------------------------------  // acclient.c:883434
void __cdecl _E250_19()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_0;
  v1 = 2;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
    --v0;
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

//----- (0075B990) --------------------------------------------------------  // acclient.c:883459
void __cdecl _E74_42()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B9C0) --------------------------------------------------------  // acclient.c:883472
void __cdecl _E77_56()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075B9F0) --------------------------------------------------------  // acclient.c:883485
void __cdecl _E80_30()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BA20) --------------------------------------------------------  // acclient.c:883498
void __cdecl _E83_19()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BA50) --------------------------------------------------------  // acclient.c:883511
void __cdecl sub_75BA50()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BA80) --------------------------------------------------------  // acclient.c:883524
void __cdecl sub_75BA80()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BAB0) --------------------------------------------------------  // acclient.c:883537
void __cdecl sub_75BAB0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BAE0) --------------------------------------------------------  // acclient.c:883550
void __cdecl sub_75BAE0()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BB10) --------------------------------------------------------  // acclient.c:883563
void __cdecl sub_75BB10()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BB40) --------------------------------------------------------  // acclient.c:883576
void __cdecl _E127_91()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BB70) --------------------------------------------------------  // acclient.c:883589
void __cdecl _E130_83()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BBA0) --------------------------------------------------------  // acclient.c:883602
void __cdecl _E133_76()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BBD0) --------------------------------------------------------  // acclient.c:883615
void __cdecl _E136_60()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BC00) --------------------------------------------------------  // acclient.c:883628
void __cdecl _E139_61()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BC30) --------------------------------------------------------  // acclient.c:883641
void __cdecl _E142_58()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BC60) --------------------------------------------------------  // acclient.c:883654
void __cdecl _E145_60()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BC90) --------------------------------------------------------  // acclient.c:883667
void __cdecl _E148_59()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BCC0) --------------------------------------------------------  // acclient.c:883680
void __cdecl _E151_57()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BCF0) --------------------------------------------------------  // acclient.c:883693
void __cdecl _E154_58()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BD20) --------------------------------------------------------  // acclient.c:883706
void __cdecl _E157_55()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BD50) --------------------------------------------------------  // acclient.c:883719
void __cdecl _E160_58()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_13;
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

//----- (0075BD90) --------------------------------------------------------  // acclient.c:883744
void __cdecl _E163_51()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_13;
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

//----- (0075BDD0) --------------------------------------------------------  // acclient.c:883769
void __cdecl _E166_53()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_13;
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

//----- (0075BE10) --------------------------------------------------------  // acclient.c:883794
void __cdecl _E169_52()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_13;
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

//----- (0075BE50) --------------------------------------------------------  // acclient.c:883819
void __cdecl _E172_50()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_13;
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

//----- (0075BE90) --------------------------------------------------------  // acclient.c:883844
void __cdecl _E175_47()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_25;
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

//----- (0075BED0) --------------------------------------------------------  // acclient.c:883869
void __cdecl _E178_47()
{
  char *v0; // esi@1

  v0 = &waveform_None_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BF00) --------------------------------------------------------  // acclient.c:883882
void __cdecl _E181_47()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BF30) --------------------------------------------------------  // acclient.c:883895
void __cdecl _E184_45()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BF60) --------------------------------------------------------  // acclient.c:883908
void __cdecl _E187_44()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BF90) --------------------------------------------------------  // acclient.c:883921
void __cdecl _E190_45()
{
  char *v0; // esi@1

  v0 = &waveform_Square_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BFC0) --------------------------------------------------------  // acclient.c:883934
void __cdecl _E193_40()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075BFF0) --------------------------------------------------------  // acclient.c:883947
void __cdecl _E196_47()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C020) --------------------------------------------------------  // acclient.c:883960
void __cdecl _E199_39()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C050) --------------------------------------------------------  // acclient.c:883973
void __cdecl _E202_40()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

