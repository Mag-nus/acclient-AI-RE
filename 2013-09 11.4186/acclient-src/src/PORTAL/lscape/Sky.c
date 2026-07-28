/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Sky
   Object     : PORTAL\lscape\Sky.obj
   Functions  : 96
   Addresses  : 00506DC0 - 00766870 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00506DC0) --------------------------------------------------------  // acclient.c:308360
AC1Legacy::Vector3 *__thiscall Position::get_origin(Position *this)
{
  return &this->frame.m_fOrigin;
}

//----- (00506DD0) --------------------------------------------------------  // acclient.c:308366
void __thiscall GameSky::UpdatePosition(GameSky *this, Position *p)
{
  GameSky *v2; // esi@1
  int v3; // eax@1
  int v4; // eax@1
  unsigned int v5; // edi@1
  CPhysicsObj **v6; // edx@2
  CPhysicsObj *v7; // eax@2
  int v8; // ebp@2
  AC1Legacy::Vector3 *v9; // eax@4
  unsigned int v10; // eax@6
  Frame dummy_frame; // [sp+Ch] [bp-40h]@3

  v2 = this;
  ((void (__stdcall *)(_DWORD))this->after_sky_cell->vfptr[2].Release)(p->objcell_id);
  v3 = (int)&v2->after_sky_cell->pos;
  *(_DWORD *)(v3 + 4) = p->objcell_id;
  Frame::operator=(v3 + 8, (int)&p->frame);
  ((void (__stdcall *)(unsigned int))v2->before_sky_cell->vfptr[2].Release)(p->objcell_id);
  v4 = (int)&v2->before_sky_cell->pos;
  *(_DWORD *)(v4 + 4) = p->objcell_id;
  Frame::operator=(v4 + 8, (int)&p->frame);
  v5 = 0;
  if ( v2->sky_obj.m_num )
  {
    do
    {
      v6 = v2->sky_obj.m_data;
      v7 = v6[v5];
      v8 = (int)&v6[v5];
      if ( v7 )
      {
        Frame::operator=((int)&dummy_frame, (int)&v7->m_position.frame);
        if ( v2->property_array.m_data[v5] & 4 )
        {
          v9 = Position::get_origin(p);
          dummy_frame.m_fOrigin.x = v9->x;
          dummy_frame.m_fOrigin.y = v9->y;
          dummy_frame.m_fOrigin.z = v9->z;
        }
        else
        {
          Frame::interpolate_origin(&dummy_frame, (Frame *)(*(_DWORD *)v8 + 80), &p->frame, 0.0);
        }
        v10 = v2->property_array.m_data[v5];
        if ( v10 & 4 )
        {
          if ( !(v10 & 8) )
            LODWORD(dummy_frame.m_fOrigin.z) = -1024458752;
        }
        CPhysicsObj::set_frame(v2->sky_obj.m_data[v5], &dummy_frame);
        CPhysicsObj::set_cell_id_recursive(v2->sky_obj.m_data[v5], p->objcell_id);
      }
      ++v5;
    }
    while ( v5 < v2->sky_obj.m_num );
  }
}

//----- (00506EE0) --------------------------------------------------------  // acclient.c:308426
CPhysicsObj *__thiscall GameSky::MakeObject(GameSky *this, IDClass<_tagDataID,32,0> id, AC1Legacy::Vector3 *tex_velocity, int after, int weather)
{
  GameSky *v5; // edi@1
  CPhysicsObj *v6; // esi@4
  CPhysicsObj *result; // eax@9

  v5 = this;
  if ( id.id && (!weather || LScape::weather_enabled) )
  {
    v6 = CPhysicsObj::makeObject(id, 0, 0);
    if ( v6 )
    {
      if ( tex_velocity->x != 0.0 || tex_velocity->y != 0.0 )
        CPhysicsObj::SetTextureVelocity(v6, tex_velocity->x, tex_velocity->y);
      if ( after )
      {
        CPhysicsObj::AddObjectToSingleCell(v6, (CObjCell *)&v5->after_sky_cell->vfptr);
        return v6;
      }
      CPhysicsObj::AddObjectToSingleCell(v6, (CObjCell *)&v5->before_sky_cell->vfptr);
    }
    result = v6;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 81CBE9: using guessed type bool LScape::weather_enabled;

//----- (00506F80) --------------------------------------------------------  // acclient.c:308458
void __stdcall GameSky::CalcFrame(Frame *dummy_frame, float heading, float rotation)
{
  AC1Legacy::Vector3 vc; // [sp+0h] [bp-Ch]@4

  if ( heading != 0.0 )
    Frame::set_heading(dummy_frame, heading);
  if ( rotation != 0.0 )
  {
    vc.y = -rotation * 0.0174532925199433;
    LODWORD(vc.x) = 0;
    LODWORD(vc.z) = 0;
    Frame::grotate(dummy_frame, &vc);
  }
}

//----- (00506FF0) --------------------------------------------------------  // acclient.c:308474
void __thiscall GameSky::Draw(GameSky *this, int after)
{
  GameSky *v2; // edi@1
  int v3; // esi@1
  RenderDevice *v4; // ebx@3
  RenderDeviceD3D *v5; // ecx@3
  int v6; // ebp@3
  float _zfar; // ST04_4@3
  unsigned int v8; // eax@6
  float aftera; // [sp+18h] [bp+4h]@3

  v2 = this;
  v3 = after;
  if ( SmartBox::is_player_outside(SmartBox::smartbox) || !after )
  {
    v4 = RenderDevice::render_device;
    v5 = (RenderDeviceD3D *)RenderDevice::render_device;
    LOBYTE(RenderDevice::render_device[2].m_GState.FrameBufferBloomRGBAmount.r) = 1;
    v6 = RenderDeviceD3D::GetFFFogEnable(v5);
    RenderDeviceD3D::SetFFFogEnable((RenderDeviceD3D *)v4, LScape::m_override_enabled != 0);
    aftera = Render::zfar;
    _zfar = Render::zfar * 4.0;
    Render::set_zfar(_zfar);
    RenderDeviceD3D::SetDepthBufferMode((RenderDeviceD3D *)v4, DEPTHTEST_ALWAYS, 0);
    if ( v3 )
    {
      if ( LScape::weather_enabled )
        ((void (__stdcall *)(CEnvCell *))RenderDevice::render_device->vfptr->DrawObjCellForDummies)(v2->after_sky_cell);
    }
    else if ( v2->sky_obj.m_num )
    {
      do
      {
        if ( v2->sky_obj.m_data[v3] )
        {
          v8 = v2->property_array.m_data[v3];
          if ( !(v8 & 1)
            && (LScape::weather_enabled || !(v8 & 4))
            && (!LScape::m_override_enabled
             || !RenderDeviceD3D::GetFFFogEnable((RenderDeviceD3D *)v4)
             || !(v2->property_array.m_data[v3] & 2)) )
          {
            CPhysicsObj::UpdateViewerDistanceRecursive(v2->sky_obj.m_data[v3]);
            CPhysicsObj::DrawRecursive(v2->sky_obj.m_data[v3]);
          }
        }
        ++v3;
      }
      while ( v3 < v2->sky_obj.m_num );
    }
    Render::set_zfar(aftera);
    RenderDeviceD3D::SetDepthBufferMode((RenderDeviceD3D *)v4, DEPTHTEST_LESSEQUAL, 1);
    RenderDeviceD3D::SetFFFogEnable((RenderDeviceD3D *)v4, v6 != 0);
    LOBYTE(v4[2].m_GState.FrameBufferBloomRGBAmount.r) = 0;
  }
}
// 81CBE9: using guessed type bool LScape::weather_enabled;
// 841799: using guessed type bool LScape::m_override_enabled;

//----- (00507120) --------------------------------------------------------  // acclient.c:308534
void __cdecl GameSky::OnTimeAdjustment()
{
  GameTime *v0; // eax@1
  int v1; // edx@2
  char *v2; // esi@5
  PStringBase<char> str; // [sp+0h] [bp-104h]@5
  char szTime[128]; // [sp+4h] [bp-100h]@3
  char szDate[128]; // [sp+84h] [bp-80h]@3

  v0 = GameTime::current_game_time;
  if ( GameTime::current_game_time
    && (v1 = dword_841964,
        LODWORD(GameTime::current_game_time->time_zero_start_delta) = LODWORD(GameSky::s_timeAdjustment),
        HIDWORD(v0->time_zero_start_delta) = v1,
        LODWORD(GameTime::current_game_time->time_of_next_event) = 0,
        HIDWORD(GameTime::current_game_time->time_of_next_event) = 0,
        GameTime::UseTime(GameTime::current_game_time),
        GameTime::current_game_time) )
  {
    GameTime::GetDateTimeString(GameTime::current_game_time, szDate, szTime);
  }
  else
  {
    strcpy(szDate, " ");
    *(_WORD *)szTime = *(_WORD *)szDate;
  }
  PStringBase<char>::PStringBase<char>(&str, 0, "  Date: %s\n  Time: %s\n", szDate, szTime);
  GlobalRegistry::OutputText(&str);
  v2 = &str.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1]) )
  {
    if ( v2 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  }
}
// 841960: using guessed type double GameSky::s_timeAdjustment;
// 841964: using guessed type int dword_841964;

//----- (005071F0) --------------------------------------------------------  // acclient.c:308573
void __thiscall GameSky::GameSky(GameSky *this)
{
  GameSky *v1; // esi@1
  CEnvCell *v2; // eax@1
  CEnvCell *v3; // eax@2
  CEnvCell *v4; // eax@4
  CEnvCell *v5; // eax@5
  char *v6; // edi@7
  char *v7; // edi@10
  PStringBase<char> _Name; // [sp+Ch] [bp-8h]@7
  PStringBase<char> _Description; // [sp+10h] [bp-4h]@7

  v1 = this;
  this->sky_obj_pos.m_data = 0;
  this->sky_obj_pos.m_size = 0;
  this->sky_obj_pos.m_num = 0;
  this->sky_obj.m_data = 0;
  this->sky_obj.m_size = 0;
  this->sky_obj.m_num = 0;
  this->property_array.m_data = 0;
  this->property_array.m_size = 0;
  this->property_array.m_num = 0;
  v2 = (CEnvCell *)operator new(0x148u);
  if ( v2 )
    CEnvCell::CEnvCell(v2);
  else
    v3 = 0;
  v1->before_sky_cell = v3;
  v4 = (CEnvCell *)operator new(0x148u);
  if ( v4 )
    CEnvCell::CEnvCell(v4);
  else
    v5 = 0;
  v1->after_sky_cell = v5;
  PStringBase<char>::PStringBase<char>(
    &_Description,
    "Number of seconds to adjust Timer time to compute GameTime time.  GameTime effects the state of the sky");
  PStringBase<char>::PStringBase<char>(&_Name, "GameTime.TimeZeroDelta");
  GlobalRegistry::RegisterVariableInternal(
    &GameSky::s_timeAdjustment,
    GRVDataType_Float64,
    &_Name,
    &_Description,
    (void (__cdecl *)(PStringBase<char> *))GameSky::OnTimeAdjustment,
    0,
    0,
    0);
  v6 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v7 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) )
  {
    if ( v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  }
}
// 841960: using guessed type double GameSky::s_timeAdjustment;

//----- (005072E0) --------------------------------------------------------  // acclient.c:308633
void __thiscall GameSky::~GameSky(GameSky *this)
{
  GameSky *v1; // esi@1
  char *v2; // edi@1
  unsigned int v3; // edi@4
  CPhysicsObj *v4; // ecx@5
  CPhysicsObj *v5; // ecx@9
  CEnvCell *v6; // ecx@12
  CEnvCell *v7; // ecx@14
  CelestialPosition *v8; // esi@16
  PStringBase<char> _Name; // [sp+0h] [bp-4h]@1

  _Name.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v1 = this;
  PStringBase<char>::PStringBase<char>(&_Name, "GameTime.TimeZeroDelta");
  GlobalRegistry::UnregisterVariable(&_Name);
  v2 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = 0;
  if ( v1->sky_obj.m_num )
  {
    do
    {
      v4 = v1->sky_obj.m_data[v3];
      if ( v4 )
      {
        if ( v1->property_array.m_data[v3] & 1 )
          CPhysicsObj::RemoveObjectFromSingleCell(v4, (CObjCell *)&v1->after_sky_cell->vfptr);
        else
          CPhysicsObj::RemoveObjectFromSingleCell(v4, (CObjCell *)&v1->before_sky_cell->vfptr);
        v5 = v1->sky_obj.m_data[v3];
        if ( v5 )
          ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
      }
      ++v3;
    }
    while ( v3 < v1->sky_obj.m_num );
  }
  v6 = v1->before_sky_cell;
  if ( v6 )
    ((void (__stdcall *)(signed int))v6->vfptr[1].IUnknown_QueryInterface)(1);
  v7 = v1->after_sky_cell;
  if ( v7 )
    ((void (__stdcall *)(signed int))v7->vfptr[1].IUnknown_QueryInterface)(1);
  operator delete[](v1->property_array.m_data);
  operator delete[](v1->sky_obj.m_data);
  v8 = v1->sky_obj_pos.m_data;
  if ( v8 )
    operator delete[](&v8[-1].properties);
}

//----- (005073C0) --------------------------------------------------------  // acclient.c:308686
void __thiscall GameSky::CreateDeletePhysicsObjects(GameSky *this)
{
  GameSky *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebp@1
  bool v4; // cf@1
  bool v5; // zf@1
  unsigned int v6; // edi@2
  CPhysicsObj *v7; // ecx@3
  CPhysicsObj *v8; // ecx@7
  unsigned int v9; // eax@15
  unsigned int v10; // eax@17
  unsigned int v11; // eax@21
  unsigned int v12; // eax@23
  int v13; // ecx@29
  int v14; // ebx@30
  CPhysicsObj **v15; // eax@31
  int v16; // edi@31
  CPhysicsObj *v17; // ecx@31
  CPhysicsObj **v18; // eax@31
  unsigned int v19; // ecx@32
  int v20; // eax@32
  unsigned int v21; // ecx@33
  CPhysicsObj *v22; // ecx@39
  int v23; // ebp@41
  bool weather_option_changed; // [sp+13h] [bp-Dh]@1
  unsigned int num_desc; // [sp+14h] [bp-Ch]@1
  unsigned int iq; // [sp+18h] [bp-8h]@14
  unsigned int iqa; // [sp+18h] [bp-8h]@29
  IDClass<_tagDataID,32,0> result; // [sp+1Ch] [bp-4h]@32

  v1 = this;
  v5 = GameSky::s_weatherEnabled == LScape::weather_enabled;
  GameSky::s_weatherEnabled = LScape::weather_enabled;
  v2 = this->sky_obj_pos.m_num;
  v3 = this->sky_obj.m_num;
  weather_option_changed = !v5;
  v4 = v2 < v3;
  v5 = v2 == v3;
  num_desc = this->sky_obj_pos.m_num;
  if ( v2 < v3 )
  {
    v6 = this->sky_obj_pos.m_num;
    do
    {
      v7 = v1->sky_obj.m_data[v6];
      if ( v7 )
      {
        if ( v1->property_array.m_data[v6] & 1 )
          CPhysicsObj::RemoveObjectFromSingleCell(v7, (CObjCell *)&v1->after_sky_cell->vfptr);
        else
          CPhysicsObj::RemoveObjectFromSingleCell(v7, (CObjCell *)&v1->before_sky_cell->vfptr);
        v8 = v1->sky_obj.m_data[v6];
        if ( v8 )
          ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
        v1->sky_obj.m_data[v6] = 0;
        v2 = num_desc;
      }
      ++v6;
    }
    while ( v6 < v3 );
    v4 = v2 < v3;
    v5 = v2 == v3;
  }
  if ( !v4 && !v5 )
  {
    AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v1->sky_obj, v2);
    AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v1->property_array, num_desc);
    v2 = num_desc;
    if ( v3 < num_desc )
    {
      iq = num_desc - v3;
      do
      {
        v9 = v1->sky_obj.m_size;
        if ( v1->sky_obj.m_num < v9
          || (!v9 ? (v10 = 8) : (v10 = 2 * v9),
              AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v1->sky_obj, v10)) )
          v1->sky_obj.m_data[v1->sky_obj.m_num++] = 0;
        v11 = v1->property_array.m_size;
        if ( v1->property_array.m_num < v11
          || (!v11 ? (v12 = 8) : (v12 = 2 * v11),
              AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v1->property_array, v12)) )
          v1->property_array.m_data[v1->property_array.m_num++] = 0;
        --iq;
      }
      while ( iq );
      v2 = num_desc;
    }
  }
  v13 = 0;
  iqa = 0;
  if ( v2 )
  {
    v14 = 0;
    do
    {
      v15 = v1->sky_obj.m_data;
      v16 = v13;
      v17 = v15[v13];
      v18 = &v15[v16];
      if ( v17 )
      {
        v19 = CPhysicsObj::GetDataID(*v18, &result)->id;
        v20 = (int)&v1->sky_obj_pos.m_data[v14];
        if ( *(_DWORD *)v20 == v19 )
        {
          v21 = v1->property_array.m_data[v16];
          if ( v21 == *(_DWORD *)(v20 + 40) && (!weather_option_changed || !(v21 & 4)) )
            goto LABEL_42;
        }
        if ( v1->property_array.m_data[v16] & 1 )
          CPhysicsObj::RemoveObjectFromSingleCell(v1->sky_obj.m_data[v16], (CObjCell *)&v1->after_sky_cell->vfptr);
        else
          CPhysicsObj::RemoveObjectFromSingleCell(v1->sky_obj.m_data[v16], (CObjCell *)&v1->before_sky_cell->vfptr);
        v22 = v1->sky_obj.m_data[v16];
        if ( v22 )
          ((void (__stdcall *)(signed int))v22->vfptr->__vecDelDtor)(1);
      }
      v1->property_array.m_data[v16] = v1->sky_obj_pos.m_data[v14].properties;
      v23 = (int)&v1->sky_obj.m_data[v16];
      *(_DWORD *)v23 = GameSky::MakeObject(
                         v1,
                         v1->sky_obj_pos.m_data[v14].gfx_id,
                         &v1->sky_obj_pos.m_data[v14].tex_velocity,
                         v1->property_array.m_data[v16] & 1,
                         v1->property_array.m_data[v16] & 4);
LABEL_42:
      v13 = iqa + 1;
      ++v14;
      ++iqa;
    }
    while ( iqa < num_desc );
  }
}
// 81CBE9: using guessed type bool LScape::weather_enabled;
// 81CD2C: using guessed type bool GameSky::s_weatherEnabled;

//----- (005075B0) --------------------------------------------------------  // acclient.c:308825
void __thiscall GameSky::UseTime(GameSky *this)
{
  GameSky *v1; // esi@1
  double v2; // st7@2
  float time_of_day; // ST08_4@4
  unsigned int v4; // ebp@5
  unsigned int v5; // edi@5
  int v6; // ebx@6
  int v7; // eax@9
  float end; // ST04_4@11
  float v9; // ST04_4@13
  float v10; // ST04_4@15
  float rotation; // [sp+1Ch] [bp-48h]@8
  float heading; // [sp+20h] [bp-44h]@8
  Frame dummy_frame; // [sp+24h] [bp-40h]@8

  v1 = this;
  CRegionDesc::CalcDayGroup();
  if ( GameTime::current_game_time )
    v2 = GameTime::current_game_time->present_time_of_day;
  else
    v2 = 0.0;
  time_of_day = v2;
  if ( CRegionDesc::GetSky(time_of_day, &v1->sky_obj_pos) )
  {
    GameSky::CreateDeletePhysicsObjects(v1);
    v4 = v1->sky_obj_pos.m_num;
    v5 = 0;
    if ( v4 )
    {
      v6 = 0;
      do
      {
        if ( v1->sky_obj.m_data[v5] )
        {
          heading = v1->sky_obj_pos.m_data[v6].heading;
          rotation = v1->sky_obj_pos.m_data[v6].rotation;
          LODWORD(dummy_frame.qw) = 1065353216;
          LODWORD(dummy_frame.qx) = 0;
          LODWORD(dummy_frame.qy) = 0;
          LODWORD(dummy_frame.qz) = 0;
          LODWORD(dummy_frame.m_fOrigin.x) = 0;
          LODWORD(dummy_frame.m_fOrigin.y) = 0;
          LODWORD(dummy_frame.m_fOrigin.z) = 0;
          Frame::cache(&dummy_frame);
          if ( v1->property_array.m_data[v5] & 4 )
          {
            v7 = (int)&(*v1->sky_obj.m_data)->m_position.frame.m_fOrigin;
            LODWORD(dummy_frame.m_fOrigin.x) = *(_DWORD *)v7;
            LODWORD(dummy_frame.m_fOrigin.y) = *(_DWORD *)(v7 + 4);
            LODWORD(dummy_frame.m_fOrigin.z) = *(_DWORD *)(v7 + 8);
          }
          GameSky::CalcFrame(&dummy_frame, heading, rotation);
          CPhysicsObj::set_frame(v1->sky_obj.m_data[v5], &dummy_frame);
          if ( v1->sky_obj_pos.m_data[v6].luminosity > 0.0 )
          {
            end = v1->sky_obj_pos.m_data[v6].luminosity * 0.0099999998;
            CPhysicsObj::SetLuminosity(v1->sky_obj.m_data[v5], 0.0, end, 0.0);
          }
          if ( v1->sky_obj_pos.m_data[v6].max_bright > 0.0 )
          {
            v9 = v1->sky_obj_pos.m_data[v6].max_bright * 0.0099999998;
            CPhysicsObj::SetDiffusion(v1->sky_obj.m_data[v5], 0.0, v9, 0.0);
          }
          if ( v1->sky_obj_pos.m_data[v6].transparent >= 0.0 )
          {
            v10 = v1->sky_obj_pos.m_data[v6].transparent * 0.0099999998;
            CPhysicsObj::SetTranslucency(v1->sky_obj.m_data[v5], v10, 0.0);
          }
        }
        ++v5;
        ++v6;
      }
      while ( v5 < v4 );
    }
  }
}

//----- (00507760) --------------------------------------------------------  // acclient.c:308904
void __thiscall GameSky::SetInactive(GameSky *this)
{
  GameSky *v1; // esi@1
  CelestialPosition *v2; // eax@1
  bool v3; // zf@1

  v1 = this;
  v2 = this->sky_obj_pos.m_data;
  v3 = this->sky_obj_pos.m_data == 0;
  this->sky_obj_pos.m_num = 0;
  this->sky_obj_pos.m_size = 0;
  if ( !v3 )
    operator delete[](&v2[-1].properties);
  v1->sky_obj_pos.m_data = 0;
  GameSky::CreateDeletePhysicsObjects(v1);
}

//----- (006FA980) --------------------------------------------------------  // acclient.c:783195
int _E73_87()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_21, "Display.Resolution");
  return atexit(_E74_66);
}

//----- (006FA9A0) --------------------------------------------------------  // acclient.c:783202
int _E76_52()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_21, "Display.FullScreen");
  return atexit(_E77_80);
}

//----- (006FA9C0) --------------------------------------------------------  // acclient.c:783209
int _E79_45()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_21, "Display.RefreshRate");
  return atexit(_E80_44);
}

//----- (006FA9E0) --------------------------------------------------------  // acclient.c:783216
int _E82_28()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_21, "Display.SyncToRefresh");
  return atexit(_E83_28);
}

//----- (006FAA00) --------------------------------------------------------  // acclient.c:783223
void _E85_20()
{
  PixelFormatDesc::PixelFormatDesc(&stru_841990, PFID_A8R8G8B8);
}

//----- (006FAA10) --------------------------------------------------------  // acclient.c:783229
void sub_6FAA10()
{
  LODWORD(dword_8419CC) = 1053364187;
}

//----- (006FAA20) --------------------------------------------------------  // acclient.c:783235
void _E105_14()
{
  flt_8419D0 = 1000.0 + 1.0;
}

//----- (006FAA40) --------------------------------------------------------  // acclient.c:783241
void _E107_8()
{
  flt_8419D4 = 24.0 * 8.0;
}

//----- (006FAA60) --------------------------------------------------------  // acclient.c:783247
void _E109_57()
{
  flt_8419D8 = 24.0 * 0.5;
}

//----- (006FAA80) --------------------------------------------------------  // acclient.c:783253
void _E111_36()
{
  DEFAULT_VIEW_RADIUS_91 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FAAA0) --------------------------------------------------------  // acclient.c:783259
void _E113_22()
{
  MIN_QUANTUM_91 = 1.0 / 30.0;
}

//----- (006FAAC0) --------------------------------------------------------  // acclient.c:783265
void _E115_62()
{
  MAX_QUANTUM_91 = 1.0 / 5.0;
}

//----- (006FAAE0) --------------------------------------------------------  // acclient.c:783271
void _E117_54()
{
  dword_8419F0 = 1024;
}

//----- (006FAAF0) --------------------------------------------------------  // acclient.c:783277
void _E119_19()
{
  dword_8419F4 = 0x7FFF;
}

//----- (006FAB00) --------------------------------------------------------  // acclient.c:783283
int _E121_57()
{
  const int result; // eax@1

  result = dword_8419F0;
  INITIAL_MAX_DATA_RATE_63 = dword_8419F0;
  return result;
}

//----- (006FAB10) --------------------------------------------------------  // acclient.c:783293
int _E123_26()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_21, "Render.TextureFiltering");
  return atexit(sub_766430);
}

//----- (006FAB30) --------------------------------------------------------  // acclient.c:783300
int _E126_31()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_21, "Render.LandscapeDetailTextures");
  return atexit(sub_766460);
}

//----- (006FAB50) --------------------------------------------------------  // acclient.c:783307
int _E129_24()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_21, "Render.BuildingDetailTextures");
  return atexit(_E130_92);
}

//----- (006FAB70) --------------------------------------------------------  // acclient.c:783314
int _E132_26()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_21, "Render.FieldOfView");
  return atexit(_E133_85);
}

//----- (006FAB90) --------------------------------------------------------  // acclient.c:783321
int _E135_29()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_21, "Render.LandscapeTextureDetail");
  return atexit(_E136_68);
}

//----- (006FABB0) --------------------------------------------------------  // acclient.c:783328
int _E138_22()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_21, "Render.EnvironmentTextureDetail");
  return atexit(_E139_69);
}

//----- (006FABD0) --------------------------------------------------------  // acclient.c:783335
int _E141_22()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_21, "Render.SceneryDrawDistance");
  return atexit(_E142_64);
}

//----- (006FABF0) --------------------------------------------------------  // acclient.c:783342
int _E144_21()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_21, "Render.LandscapeDrawDistance");
  return atexit(_E145_66);
}

//----- (006FAC10) --------------------------------------------------------  // acclient.c:783349
int _E147_18()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_21, "Render.ScreenBrightness");
  return atexit(_E148_64);
}

//----- (006FAC30) --------------------------------------------------------  // acclient.c:783356
int _E150_21()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_21, "Render.AspectRatio");
  return atexit(_E151_62);
}

//----- (006FAC50) --------------------------------------------------------  // acclient.c:783363
int _E153_19()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_21, "Render.DisplayAdapter");
  return atexit(_E154_63);
}

//----- (006FAC70) --------------------------------------------------------  // acclient.c:783370
int _E156_21()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_21, "Render.MaxHardwareClass");
  return atexit(_E157_59);
}

//----- (006FAC90) --------------------------------------------------------  // acclient.c:783377
int _E159_19()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_21, "Render.AutomaticDegrades");
  return atexit(_E160_62);
}

//----- (006FACB0) --------------------------------------------------------  // acclient.c:783384
int _E162_21()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_21, "Render.GraphicsPerformance");
  return atexit(_E163_55);
}

//----- (006FACD0) --------------------------------------------------------  // acclient.c:783391
int _E165_17()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_21, "Render.DegradeDistance");
  return atexit(_E166_57);
}

//----- (006FACF0) --------------------------------------------------------  // acclient.c:783398
int _E168_18()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_21, "Render.MultiPassAlpha");
  return atexit(_E169_56);
}

//----- (006FAD10) --------------------------------------------------------  // acclient.c:783405
int _E171_17()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_21, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_841A40, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_841A44, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_841A48, "Anisotropic");
  return atexit(_E172_54);
}

//----- (006FAD60) --------------------------------------------------------  // acclient.c:783415
int _E174_18()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_21, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_841A50, "Low");
  PStringBase<char>::PStringBase<char>(&stru_841A54, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_841A58, "High");
  PStringBase<char>::PStringBase<char>(&stru_841A5C, "VeryHigh");
  return atexit(_E175_51);
}

//----- (006FADC0) --------------------------------------------------------  // acclient.c:783426
int _E177_16()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_21, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_841A64, "Low");
  PStringBase<char>::PStringBase<char>(&stru_841A68, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_841A6C, "High");
  PStringBase<char>::PStringBase<char>(&stru_841A70, "VeryHigh");
  return atexit(_E178_51);
}

//----- (006FAE20) --------------------------------------------------------  // acclient.c:783437
int _E180_16()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_21, "Low");
  PStringBase<char>::PStringBase<char>(&stru_841A78, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_841A7C, "High");
  return atexit(_E181_51);
}

//----- (006FAE60) --------------------------------------------------------  // acclient.c:783446
int _E183_15()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_21, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_841A84, "Low");
  PStringBase<char>::PStringBase<char>(&stru_841A88, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_841A8C, "High");
  PStringBase<char>::PStringBase<char>(&stru_841A90, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_841A94, "Extreme");
  return atexit(_E184_48);
}

//----- (006FAED0) --------------------------------------------------------  // acclient.c:783458
int _E186_15()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_21, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_841A9C, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_841AA0, "Wide");
  return atexit(_E187_47);
}

//----- (006FAF10) --------------------------------------------------------  // acclient.c:783467
int _E189_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_45, "None");
  return atexit(_E190_48);
}

//----- (006FAF30) --------------------------------------------------------  // acclient.c:783474
int _E192_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_45, "Speed");
  return atexit(_E193_43);
}

//----- (006FAF50) --------------------------------------------------------  // acclient.c:783481
int _E195_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_45, "Noise");
  return atexit(_E196_50);
}

//----- (006FAF70) --------------------------------------------------------  // acclient.c:783488
int _E198_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_45, "Sine");
  return atexit(_E199_42);
}

//----- (006FAF90) --------------------------------------------------------  // acclient.c:783495
int _E201_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_45, "Square");
  return atexit(_E202_43);
}

//----- (006FAFB0) --------------------------------------------------------  // acclient.c:783502
int _E204_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_45, "Bounce");
  return atexit(_E205_38);
}

//----- (006FAFD0) --------------------------------------------------------  // acclient.c:783509
int _E207_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_45, "Perlin");
  return atexit(_E208_42);
}

//----- (006FAFF0) --------------------------------------------------------  // acclient.c:783516
int _E210_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_45, "Fractal");
  return atexit(_E211_38);
}

//----- (006FB010) --------------------------------------------------------  // acclient.c:783523
int _E213_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_45, "FrameLoop");
  return atexit(_E214_41);
}

//----- (006FB030) --------------------------------------------------------  // acclient.c:783530
int _E216_8()
{
  return atexit(_E217_38);
}

//----- (006FB040) --------------------------------------------------------  // acclient.c:783536
int _E219_5()
{
  return atexit(_E220_37);
}

//----- (006FB050) --------------------------------------------------------  // acclient.c:783542
int _E222_4()
{
  return atexit(_E223_37);
}

//----- (006FB060) --------------------------------------------------------  // acclient.c:783548
int sub_6FB060()
{
  return atexit(nullsub_1072);
}

//----- (007661C0) --------------------------------------------------------  // acclient.c:892764
void __cdecl _E190_48()
{
  char *v0; // esi@1

  v0 = &waveform_None_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007661F0) --------------------------------------------------------  // acclient.c:892777
void __cdecl _E193_43()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766220) --------------------------------------------------------  // acclient.c:892790
void __cdecl _E196_50()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766250) --------------------------------------------------------  // acclient.c:892803
void __cdecl _E199_42()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766280) --------------------------------------------------------  // acclient.c:892816
void __cdecl _E202_43()
{
  char *v0; // esi@1

  v0 = &waveform_Square_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007662B0) --------------------------------------------------------  // acclient.c:892829
void __cdecl _E205_38()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007662E0) --------------------------------------------------------  // acclient.c:892842
void __cdecl _E208_42()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766310) --------------------------------------------------------  // acclient.c:892855
void __cdecl _E211_38()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766340) --------------------------------------------------------  // acclient.c:892868
void __cdecl _E214_41()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766370) --------------------------------------------------------  // acclient.c:892881
void __cdecl _E74_66()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007663A0) --------------------------------------------------------  // acclient.c:892894
void __cdecl _E77_80()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007663D0) --------------------------------------------------------  // acclient.c:892907
void __cdecl _E80_44()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766400) --------------------------------------------------------  // acclient.c:892920
void __cdecl _E83_28()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766430) --------------------------------------------------------  // acclient.c:892933
void __cdecl sub_766430()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766460) --------------------------------------------------------  // acclient.c:892946
void __cdecl sub_766460()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766490) --------------------------------------------------------  // acclient.c:892959
void __cdecl _E130_92()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007664C0) --------------------------------------------------------  // acclient.c:892972
void __cdecl _E133_85()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007664F0) --------------------------------------------------------  // acclient.c:892985
void __cdecl _E136_68()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766520) --------------------------------------------------------  // acclient.c:892998
void __cdecl _E139_69()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766550) --------------------------------------------------------  // acclient.c:893011
void __cdecl _E142_64()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766580) --------------------------------------------------------  // acclient.c:893024
void __cdecl _E145_66()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007665B0) --------------------------------------------------------  // acclient.c:893037
void __cdecl _E148_64()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007665E0) --------------------------------------------------------  // acclient.c:893050
void __cdecl _E151_62()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766610) --------------------------------------------------------  // acclient.c:893063
void __cdecl _E154_63()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766640) --------------------------------------------------------  // acclient.c:893076
void __cdecl _E157_59()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766670) --------------------------------------------------------  // acclient.c:893089
void __cdecl _E160_62()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007666A0) --------------------------------------------------------  // acclient.c:893102
void __cdecl _E163_55()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007666D0) --------------------------------------------------------  // acclient.c:893115
void __cdecl _E166_57()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766700) --------------------------------------------------------  // acclient.c:893128
void __cdecl _E169_56()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766730) --------------------------------------------------------  // acclient.c:893141
void __cdecl _E172_54()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_21;
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

//----- (00766770) --------------------------------------------------------  // acclient.c:893166
void __cdecl _E175_51()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_21;
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

//----- (007667B0) --------------------------------------------------------  // acclient.c:893191
void __cdecl _E178_51()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_21;
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

//----- (007667F0) --------------------------------------------------------  // acclient.c:893216
void __cdecl _E181_51()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_21;
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

//----- (00766830) --------------------------------------------------------  // acclient.c:893241
void __cdecl _E184_48()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_21;
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

//----- (00766870) --------------------------------------------------------  // acclient.c:893266
void __cdecl _E187_47()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_45;
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

