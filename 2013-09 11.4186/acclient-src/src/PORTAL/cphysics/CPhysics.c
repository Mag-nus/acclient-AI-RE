/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPhysics
   Object     : PORTAL\cphysics\CPhysics.obj
   Functions  : 35
   Addresses  : 00509690 - 007669D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00509690) --------------------------------------------------------  // acclient.c:311148
int __stdcall CPhysics::SetObjectMovement(CPhysicsObj *object, void *buff, unsigned int size, unsigned __int16 movement_timestamp, unsigned __int16 server_control_timestamp, int autonomous)
{
  CWeenieObject *v7; // ecx@1
  signed int v8; // ebp@1
  int v9; // ebx@1
  unsigned __int16 v10; // cx@3
  __int64 v11; // rax@3
  bool v12; // cf@4
  unsigned __int16 v13; // cx@7
  __int64 v14; // rax@7
  bool v15; // cf@8
  int v17; // eax@12
  bool v18; // zf@12

  v7 = object->weenie_obj;
  v8 = 0;
  v9 = 0;
  if ( v7 )
    v9 = ((int (*)(void))v7->vfptr[5].__vecDelDtor)();
  v10 = object->update_times[1];
  v11 = movement_timestamp - object->update_times[1];
  if ( (signed int)((HIDWORD(v11) ^ v11) - HIDWORD(v11)) > 0x7FFF )
    v12 = movement_timestamp < v10;
  else
    v12 = v10 < movement_timestamp;
  if ( v12 )
  {
    object->update_times[1] = movement_timestamp;
    v13 = object->update_times[5];
    v14 = object->update_times[5] - server_control_timestamp;
    if ( (signed int)((HIDWORD(v14) ^ v14) - HIDWORD(v14)) > 0x7FFF )
      v15 = v13 < server_control_timestamp;
    else
      v15 = server_control_timestamp < v13;
    if ( v15 )
      return 0;
    v17 = autonomous;
    v18 = autonomous == 0;
    object->update_times[5] = server_control_timestamp;
    if ( v18 || !v9 )
    {
      object->last_move_was_autonomous = v17;
      CPhysicsObj::unpack_movement(object, &buff, size);
      if ( v9 )
        v8 = 1;
    }
  }
  return v8;
}

//----- (00509760) --------------------------------------------------------  // acclient.c:311199
void __cdecl CPhysics::RemoveStaticAnimatingObject(CPhysicsObj *object)
{
  Season **v1; // eax@1
  unsigned int v2; // ecx@1

  v1 = CPhysics::static_animating_objects.m_data;
  v2 = (unsigned int)&CPhysics::static_animating_objects.m_data[CPhysics::static_animating_objects.m_num];
  if ( (unsigned int)CPhysics::static_animating_objects.m_data < v2 )
  {
    while ( (CPhysicsObj *)*v1 != object )
    {
      ++v1;
      if ( (unsigned int)v1 >= v2 )
        return;
    }
    *v1 = *(Season **)(v2 - 4);
    --CPhysics::static_animating_objects.m_num;
  }
}

//----- (00509790) --------------------------------------------------------  // acclient.c:311220
int __stdcall CPhysics::SetObjectMovement(CPhysicsObj *object, void *buff, unsigned int size)
{
  unsigned __int16 v4; // cx@1
  char *v5; // edx@1
  int v6; // eax@1
  unsigned int v7; // esi@2
  unsigned __int16 movement_timestamp; // [sp+8h] [bp-4h]@1
  unsigned __int8 buffa; // [sp+14h] [bp+8h]@1

  v4 = *((_WORD *)buff + 1);
  movement_timestamp = *(_WORD *)buff;
  v5 = (char *)buff + 5;
  buffa = *((_BYTE *)buff + 4);
  v6 = (signed int)v5 % 4;
  if ( (signed int)v5 % 4 )
  {
    v7 = 4 - v6;
    if ( 4 != v6 )
    {
      memset(v5, 0, v7);
      v5 += v7;
    }
  }
  return CPhysics::SetObjectMovement(object, v5, size, movement_timestamp, v4, buffa);
}

//----- (00509820) --------------------------------------------------------  // acclient.c:311247
void __cdecl CPhysics::UpdateTexVelocity(float time_delta)
{
  unsigned int v1; // eax@1
  unsigned int v2; // ebx@1
  Season *v3; // esi@2
  IDClass<_tagDataID,32,0> v4; // ST04_4@3
  DBOCache *v5; // eax@3
  CGfxObj *v6; // edi@3
  double v7; // st7@8
  double v8; // st6@8
  int v9; // edx@12
  CVec2Duv v10; // ST00_8@12

  v1 = CPhysics::texture_velocity_gids.m_num;
  v2 = 0;
  if ( CPhysics::texture_velocity_gids.m_num )
  {
    do
    {
      v3 = CPhysics::texture_velocity_gids.m_data[v2];
      if ( v3 )
      {
        v4.id = (unsigned int)v3->season_name.m_buffer;
        v5 = (DBOCache *)DBCache::GetDBOCache(6u);
        v6 = (CGfxObj *)DBOCache::GetIfUsing(v5, v4);
        if ( v6 )
        {
          v7 = time_delta * *(float *)&v3->begin;
          v8 = time_delta * *(float *)&v3[1].season_name.m_buffer;
          if ( *(float *)&v3[1].begin >= 1.0 )
            v7 = v7 - 1.0;
          if ( *(float *)&v3[2].season_name.m_buffer >= 1.0 )
            v8 = v8 - 1.0;
          *(float *)&v3[1].begin = v7 + *(float *)&v3[1].begin;
          v9 = v3[1].begin;
          *(float *)&v3[2].season_name.m_buffer = v8 + *(float *)&v3[2].season_name.m_buffer;
          LODWORD(v10.v) = v3[2].season_name.m_buffer;
          LODWORD(v10.u) = v9;
          CGfxObj::TexVelocity(v6, v10);
          v6->vfptr->Release((Interface *)v6);
          v1 = CPhysics::texture_velocity_gids.m_num;
        }
        else
        {
          operator delete(v3);
          v1 = CPhysics::texture_velocity_gids.m_num;
          if ( v2 < CPhysics::texture_velocity_gids.m_num )
          {
            v1 = CPhysics::texture_velocity_gids.m_num - 1;
            CPhysics::texture_velocity_gids.m_num = v1;
            if ( v2 != v1 )
            {
              CPhysics::texture_velocity_gids.m_data[v2] = CPhysics::texture_velocity_gids.m_data[v1];
              v1 = CPhysics::texture_velocity_gids.m_num;
            }
          }
          --v2;
        }
      }
      ++v2;
    }
    while ( v2 < v1 );
  }
}

//----- (00509910) --------------------------------------------------------  // acclient.c:311313
void __thiscall CPhysics::~CPhysics(CPhysics *this)
{
  unsigned int v1; // esi@1
  CPhysics *v2; // edi@1

  v1 = 0;
  v2 = this;
  if ( CPhysics::texture_velocity_gids.m_num )
  {
    do
    {
      if ( CPhysics::texture_velocity_gids.m_data[v1] )
        operator delete(CPhysics::texture_velocity_gids.m_data[v1]);
      ++v1;
    }
    while ( v1 < CPhysics::texture_velocity_gids.m_num );
  }
  operator delete(v2->iter);
}

//----- (00509950) --------------------------------------------------------  // acclient.c:311334
void __thiscall CPhysics::UseTime(CPhysics *this)
{
  CPhysics *v1; // esi@1
  LongHashIter<CPhysicsObj> *v2; // ecx@4
  HashBase<unsigned long> *v3; // eax@4
  HashBaseData<unsigned long> **v4; // edx@5
  bool v5; // zf@5
  LongHashIter<CPhysicsObj> *i; // eax@8
  CPhysicsObj *v7; // edi@9
  unsigned int v8; // esi@12
  float time_delta; // ST04_4@14
  double quantum; // [sp+8h] [bp-8h]@1

  v1 = this;
  quantum = COERCE_DOUBLE(Timer::cur_time.Cmd) - last_update;
  if ( quantum >= 0.0 )
  {
    if ( quantum >= MIN_QUANTUM_93 )
    {
      v2 = this->iter;
      v3 = v2->myHash_;
      v2->lastThisChain_ = 0;
      v2->curBucket_ = 0;
      if ( v3 )
      {
        v2->fEnd_ = 0;
        v4 = v3->buckets;
        v5 = *v4 == 0;
        v2->curPtr_ = *v4;
        if ( v5 )
          HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&v2->myHash_);
      }
      else
      {
        v2->fEnd_ = 1;
        v2->curPtr_ = 0;
      }
      for ( i = v1->iter; !i->fEnd_; i = v1->iter )
      {
        v7 = (CPhysicsObj *)i->curPtr_;
        CPhysicsObj::update_object((CPhysicsObj *)i->curPtr_);
        if ( v7 == v1->player )
          SmartBox::PlayerPhysicsUpdatedCallback(v1->smartbox);
        HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&v1->iter->myHash_);
      }
      *(_QWORD *)&last_update = Timer::cur_time;
      v8 = 0;
      if ( CPhysics::static_animating_objects.m_num )
      {
        do
          CPhysicsObj::animate_static_object((CPhysicsObj *)CPhysics::static_animating_objects.m_data[v8++]);
        while ( v8 < CPhysics::static_animating_objects.m_num );
      }
      time_delta = quantum;
      CPhysics::UpdateTexVelocity(time_delta);
    }
  }
  else
  {
    *(_QWORD *)&last_update = Timer::cur_time;
  }
}

//----- (00509A60) --------------------------------------------------------  // acclient.c:311398
void __thiscall CPhysics::CPhysics(CPhysics *this, CObjectMaint *_obj_maint, SmartBox *_smartbox)
{
  CPhysics *v3; // edi@1
  void *v4; // esi@1
  int v5; // edx@2
  int v6; // eax@3

  v3 = this;
  this->player = 0;
  this->obj_maint = _obj_maint;
  this->smartbox = _smartbox;
  v4 = operator new(0x14u);
  if ( v4 )
  {
    v5 = (int)&v3->obj_maint->object_table;
    *(_DWORD *)v4 = v5;
    *((_DWORD *)v4 + 3) = 0;
    *((_DWORD *)v4 + 1) = 0;
    if ( v5 )
    {
      *((_DWORD *)v4 + 4) = 0;
      v6 = **(_DWORD **)(v5 + 12);
      *((_DWORD *)v4 + 2) = v6;
      if ( !v6 )
        HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)v4);
    }
    else
    {
      *((_DWORD *)v4 + 4) = 1;
      *((_DWORD *)v4 + 2) = 0;
    }
  }
  else
  {
    v4 = 0;
  }
  v3->iter = (LongHashIter<CPhysicsObj> *)v4;
  *(_QWORD *)&PhysicsTimer::curr_time = Timer::cur_time;
}

//----- (00509AF0) --------------------------------------------------------  // acclient.c:311439
void __cdecl CPhysics::AddStaticAnimatingObject(CPhysicsObj *object)
{
  Season **v1; // eax@1
  unsigned int v2; // ecx@1
  unsigned int v3; // eax@8

  v1 = CPhysics::static_animating_objects.m_data;
  v2 = (unsigned int)&CPhysics::static_animating_objects.m_data[CPhysics::static_animating_objects.m_num];
  if ( (unsigned int)CPhysics::static_animating_objects.m_data < v2 )
  {
    while ( (CPhysicsObj *)*v1 != object )
    {
      ++v1;
      if ( (unsigned int)v1 >= v2 )
        goto LABEL_6;
    }
    *v1 = *(Season **)(v2 - 4);
    --CPhysics::static_animating_objects.m_num;
  }
LABEL_6:
  if ( CPhysics::static_animating_objects.m_num < CPhysics::static_animating_objects.m_size
    || (!CPhysics::static_animating_objects.m_size ? (v3 = 8) : (v3 = 2 * CPhysics::static_animating_objects.m_size),
        AC1Legacy::SmartArray<SkyTimeOfDay *>::grow(&CPhysics::static_animating_objects, v3)) )
    CPhysics::static_animating_objects.m_data[CPhysics::static_animating_objects.m_num++] = (Season *)object;
}

//----- (00509B60) --------------------------------------------------------  // acclient.c:311466
void __cdecl CPhysics::AddGfxVelocity(IDClass<_tagDataID,32,0> gfx_id, float du, float dv)
{
  unsigned int v3; // ecx@1
  Season *v4; // eax@2
  void *v5; // esi@5
  unsigned int v6; // eax@7
  Season *v7; // edi@8
  unsigned int v8; // esi@11

  v3 = 0;
  if ( CPhysics::texture_velocity_gids.m_num )
  {
    while ( 1 )
    {
      v4 = CPhysics::texture_velocity_gids.m_data[v3];
      if ( v4 )
      {
        if ( (AC1Legacy::PSRefBuffer<char> *)gfx_id.id == v4->season_name.m_buffer )
          break;
      }
      ++v3;
      if ( v3 >= CPhysics::texture_velocity_gids.m_num )
        goto LABEL_5;
    }
    v7 = CPhysics::texture_velocity_gids.m_data[v3];
    if ( du != 0.0 || dv != 0.0 )
    {
      *(float *)&v7->begin = du;
      *(float *)&v7[1].season_name.m_buffer = dv;
    }
    else
    {
      if ( v3 < CPhysics::texture_velocity_gids.m_num )
      {
        v8 = CPhysics::texture_velocity_gids.m_num - 1;
        CPhysics::texture_velocity_gids.m_num = v8;
        if ( v3 != v8 )
          CPhysics::texture_velocity_gids.m_data[v3] = CPhysics::texture_velocity_gids.m_data[v8];
      }
      if ( v7 )
        operator delete(v7);
    }
  }
  else
  {
LABEL_5:
    v5 = operator new(0x14u);
    *(_DWORD *)v5 = gfx_id.id;
    *((float *)v5 + 1) = du;
    *((float *)v5 + 2) = dv;
    *((_DWORD *)v5 + 3) = 0;
    *((_DWORD *)v5 + 4) = 0;
    if ( CPhysics::texture_velocity_gids.m_num < CPhysics::texture_velocity_gids.m_size
      || (!CPhysics::texture_velocity_gids.m_size ? (v6 = 8) : (v6 = 2 * CPhysics::texture_velocity_gids.m_size),
          AC1Legacy::SmartArray<SkyTimeOfDay *>::grow(&CPhysics::texture_velocity_gids, v6)) )
      CPhysics::texture_velocity_gids.m_data[CPhysics::texture_velocity_gids.m_num++] = (Season *)v5;
  }
}

//----- (006FB170) --------------------------------------------------------  // acclient.c:783622
void sub_6FB170()
{
  flt_841BC4 = 1000.0 + 1.0;
}

//----- (006FB190) --------------------------------------------------------  // acclient.c:783628
void sub_6FB190()
{
  flt_841BC8 = 24.0 * 8.0;
}

//----- (006FB1B0) --------------------------------------------------------  // acclient.c:783634
void sub_6FB1B0()
{
  flt_841BCC = 24.0 * 0.5;
}

//----- (006FB1D0) --------------------------------------------------------  // acclient.c:783640
int sub_6FB1D0()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_22, "Display.Resolution");
  return atexit(sub_766940);
}

//----- (006FB1F0) --------------------------------------------------------  // acclient.c:783647
int sub_6FB1F0()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_22, "Display.FullScreen");
  return atexit(sub_766970);
}

//----- (006FB210) --------------------------------------------------------  // acclient.c:783654
int sub_6FB210()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_22, "Display.RefreshRate");
  return atexit(sub_7669A0);
}

//----- (006FB230) --------------------------------------------------------  // acclient.c:783661
int _E106_91()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_22, "Display.SyncToRefresh");
  return atexit(_E107_86);
}

//----- (006FB250) --------------------------------------------------------  // acclient.c:783668
int _E109_59()
{
  return atexit(nullsub_1075);
}

//----- (006FB260) --------------------------------------------------------  // acclient.c:783674
int _E112_83()
{
  return atexit(_E113_62);
}

//----- (006FB270) --------------------------------------------------------  // acclient.c:783680
int _E115_63()
{
  return atexit(_E116_54);
}

//----- (006FB280) --------------------------------------------------------  // acclient.c:783686
void _E118_63()
{
  dword_841BE4 = 1024;
}

//----- (006FB290) --------------------------------------------------------  // acclient.c:783692
void _E120_49()
{
  dword_841BE8 = 0x7FFF;
}

//----- (006FB2A0) --------------------------------------------------------  // acclient.c:783698
int _E122_26()
{
  const int result; // eax@1

  result = dword_841BE4;
  INITIAL_MAX_DATA_RATE_66 = dword_841BE4;
  return result;
}

//----- (006FB2B0) --------------------------------------------------------  // acclient.c:783708
void _E124_59()
{
  DEFAULT_VIEW_RADIUS_93 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FB2D0) --------------------------------------------------------  // acclient.c:783714
void _E126_32()
{
  MIN_QUANTUM_93 = 1.0 / 30.0;
}

//----- (006FB2F0) --------------------------------------------------------  // acclient.c:783720
void _E128_11()
{
  MAX_QUANTUM_93 = 1.0 / 5.0;
}

//----- (006FB310) --------------------------------------------------------  // acclient.c:783726
void _E130_46()
{
  PixelFormatDesc::PixelFormatDesc(&stru_841C08, PFID_A8R8G8B8);
}

//----- (006FB320) --------------------------------------------------------  // acclient.c:783732
int _E132_27()
{
  AC1Legacy::SmartArray<SkyTimeOfDay *>::grow(&CPhysics::static_animating_objects, 0x20u);
  return atexit(_E133_86);
}

//----- (006FB340) --------------------------------------------------------  // acclient.c:783739
int _E135_30()
{
  return atexit(_E136_69);
}

//----- (006FB350) --------------------------------------------------------  // acclient.c:783745
int sub_6FB350()
{
  return atexit(nullsub_1074);
}

//----- (00766920) --------------------------------------------------------  // acclient.c:893298
void __cdecl _E133_86()
{
  operator delete[](CPhysics::static_animating_objects.m_data);
}

//----- (00766930) --------------------------------------------------------  // acclient.c:893304
void __cdecl _E136_69()
{
  operator delete[](CPhysics::texture_velocity_gids.m_data);
}

//----- (00766940) --------------------------------------------------------  // acclient.c:893310
void __cdecl sub_766940()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00766970) --------------------------------------------------------  // acclient.c:893323
void __cdecl sub_766970()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007669A0) --------------------------------------------------------  // acclient.c:893336
void __cdecl sub_7669A0()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007669D0) --------------------------------------------------------  // acclient.c:893349
void __cdecl _E107_86()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

