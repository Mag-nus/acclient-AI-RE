/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSkyDesc
   Object     : PORTAL\cregion\CSkyDesc.obj
   Functions  : 26
   Addresses  : 00500950 - 006F9730 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00500950) --------------------------------------------------------  // acclient.c:301401
void __thiscall SkyObject::Destroy(SkyObject *this)
{
  SkyObject *v1; // esi@1
  int v2; // ecx@1

  v1 = this;
  operator delete[](this->object_name);
  v2 = (int)&v1->tex_velocity;
  *(_DWORD *)v2 = 0;
  *(_DWORD *)(v2 + 4) = 0;
  v1->object_name = 0;
  LODWORD(v1->begin_time) = 0;
  LODWORD(v1->end_time) = 0;
  LODWORD(v1->begin_angle) = 0;
  LODWORD(v1->end_angle) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  v1->default_gfx_object.id = stru_84152C.id;
  v1->default_pes_object.id = stru_84152C.id;
  v1->properties = 0;
}

//----- (005009B0) --------------------------------------------------------  // acclient.c:301423
unsigned int __thiscall DayGroup::GetTimeOfDay(DayGroup *this, float time_of_day, SkyTimeOfDay **before_time, SkyTimeOfDay **after_time, float *ratio)
{
  unsigned int result; // eax@1
  unsigned int v6; // edx@2
  SkyTimeOfDay **v7; // esi@3
  double v8; // st7@6
  unsigned int v9; // esi@6
  SkyTimeOfDay **v10; // ecx@6
  SkyTimeOfDay *v11; // edx@8

  result = this->sky_time.m_num;
  if ( result )
  {
    v6 = 0;
    if ( result != 1 )
    {
      v7 = this->sky_time.m_data + 1;
      do
      {
        if ( (*v7)->begin > (double)time_of_day )
          break;
        ++v6;
        ++v7;
      }
      while ( v6 < result - 1 );
    }
    v8 = time_of_day;
    *before_time = this->sky_time.m_data[v6];
    v9 = this->sky_time.m_num;
    v10 = this->sky_time.m_data;
    if ( v6 == v9 - 1 )
    {
      *after_time = *v10;
      result = 1;
      *ratio = (v8 - (*before_time)->begin) / (1.0 - (*before_time)->begin);
    }
    else
    {
      v11 = v10[v6 + 1];
      *after_time = v11;
      result = 1;
      *ratio = (v8 - (*before_time)->begin) / (v11->begin - (*before_time)->begin);
    }
  }
  return result;
}

//----- (00500A50) --------------------------------------------------------  // acclient.c:301471
void __thiscall SkyDesc::SkyDesc(SkyDesc *this)
{
  this->present_day_group = 0;
  LODWORD(this->tick_size) = 0;
  HIDWORD(this->tick_size) = 1074266112;
  LODWORD(this->light_tick_size) = 0;
  HIDWORD(this->light_tick_size) = 1077149696;
  this->day_groups.m_data = 0;
  this->day_groups.m_size = 0;
  this->day_groups.m_num = 0;
}

//----- (00500A80) --------------------------------------------------------  // acclient.c:301484
void __thiscall SkyDesc::GetLighting(SkyDesc *this, float time_of_day, float *ambient, RGBAUnion *amb_color, AC1Legacy::Vector3 *directional, RGBAUnion *dir_color)
{
  SkyTimeOfDay *v6; // esi@2
  SkyTimeOfDay *v7; // edi@2
  signed int v8; // ecx@2
  float *v9; // edx@2
  double v10; // st7@2
  unsigned __int64 v11; // rax@2
  float *v12; // ecx@2
  char v13; // bl@2
  double v14; // st6@2
  RGBAUnion *v15; // ecx@2
  double v16; // st7@2
  double v17; // st6@2
  long double v18; // st6@2
  AC1Legacy::Vector3 *v19; // ecx@2
  long double v20; // st5@2
  long double v21; // st6@2
  signed int v22; // ecx@2
  double v23; // st7@2
  unsigned __int64 v24; // rax@2
  float *v25; // ecx@2
  char v26; // bl@2
  double v27; // st6@2
  RGBAUnion *v28; // ecx@2
  RGBAUnion *v29; // eax@3
  AC1Legacy::Vector3 *v30; // edx@3
  RGBAUnion *v31; // eax@3
  SkyTimeOfDay *before_time; // [sp+0h] [bp-14h]@1
  SkyTimeOfDay *after_time; // [sp+4h] [bp-10h]@1
  float v34; // [sp+8h] [bp-Ch]@2
  float v35; // [sp+Ch] [bp-8h]@2
  float v36; // [sp+10h] [bp-4h]@2

  if ( DayGroup::GetTimeOfDay(
         this->day_groups.m_data[this->present_day_group],
         time_of_day,
         &before_time,
         &after_time,
         &time_of_day) )
  {
    v6 = before_time;
    v7 = after_time;
    *ambient = (after_time->amb_bright - before_time->amb_bright) * time_of_day + before_time->amb_bright;
    v8 = BYTE1(v6->amb_color.color);
    v9 = (float *)BYTE1(v7->amb_color.color);
    ambient = (float *)v6->amb_color.r;
    v10 = (double)(signed int)ambient;
    ambient = v9;
    v11 = (unsigned __int64)(((double)(signed int)v9 - (double)v8) * time_of_day + (double)v8);
    v12 = (float *)LOBYTE(v7->amb_color.color);
    v13 = v11;
    ambient = (float *)LOBYTE(v6->amb_color.color);
    v14 = (double)(signed int)ambient;
    ambient = v12;
    after_time = (SkyTimeOfDay *)v7->amb_color.r;
    LOBYTE(ambient) = (unsigned __int64)(((double)(signed int)v12 - v14) * time_of_day + v14);
    v15 = amb_color;
    amb_color->r = (unsigned __int64)(((double)(signed int)after_time - v10) * time_of_day + v10);
    LOBYTE(v11) = (_BYTE)ambient;
    v15->g = v13;
    v15->b = v11;
    v15->a = -1;
    v16 = v6->dir_bright + (v7->dir_bright - v6->dir_bright) * time_of_day;
    v17 = v6->dir_heading;
    *(float *)&ambient = ((v7->dir_pitch - v6->dir_pitch) * time_of_day + v6->dir_pitch) * 0.0174532925199433;
    v18 = (v17 + (v7->dir_heading - v17) * time_of_day) * 0.0174532925199433;
    v19 = directional;
    v20 = cos(*(float *)&ambient);
    v34 = sin(v18) * v16 * v20;
    directional->x = v34;
    v35 = cos(v18) * v16 * v20;
    v21 = sin(*(float *)&ambient);
    v19->y = v35;
    v36 = v16 * v21;
    v19->z = v36;
    v22 = BYTE1(v6->dir_color.color);
    HIDWORD(v11) = BYTE1(v7->dir_color.color);
    ambient = (float *)v6->dir_color.r;
    v23 = (double)(signed int)ambient;
    *(float *)&ambient = *((float *)&v11 + 1);
    v24 = (unsigned __int64)(((double)SHIDWORD(v11) - (double)v22) * time_of_day + (double)v22);
    v25 = (float *)LOBYTE(v7->dir_color.color);
    v26 = v24;
    ambient = (float *)LOBYTE(v6->dir_color.color);
    v27 = (double)(signed int)ambient;
    ambient = v25;
    amb_color = (RGBAUnion *)v7->dir_color.r;
    LOBYTE(ambient) = (unsigned __int64)(((double)(signed int)v25 - v27) * time_of_day + v27);
    v28 = dir_color;
    dir_color->r = (unsigned __int64)(((double)(signed int)amb_color - v23) * time_of_day + v23);
    LOBYTE(v24) = (_BYTE)ambient;
    v28->g = v26;
    v28->b = v24;
    v28->a = -1;
  }
  else
  {
    v29 = amb_color;
    v30 = directional;
    *(_DWORD *)ambient = 1050253722;
    v29->r = -1;
    v29->g = -1;
    v29->b = -1;
    v29->a = -1;
    v31 = dir_color;
    dir_color->r = -1;
    v31->g = -1;
    v31->b = -1;
    v31->a = -1;
    LODWORD(v30->x) = 1056964608;
    LODWORD(v30->y) = 0;
    LODWORD(v30->z) = 1061997773;
  }
}

//----- (00500CE0) --------------------------------------------------------  // acclient.c:301601
int __thiscall SkyDesc::GetWorldFog(SkyDesc *this, float time_of_day, float *min, float *max, RGBAUnion *color)
{
  float v5; // edi@2
  SkyTimeOfDay *v6; // esi@4
  float *v7; // eax@6
  signed int v8; // edx@6
  float v9; // eax@6
  double v10; // st7@6
  unsigned __int64 v11; // rax@6
  char v12; // bl@6
  double v13; // st6@6
  unsigned __int64 v14; // rax@6
  RGBAUnion *v15; // ecx@6
  int result; // eax@6
  float ratio; // [sp+8h] [bp-8h]@1
  SkyTimeOfDay *after_time; // [sp+Ch] [bp-4h]@1

  if ( DayGroup::GetTimeOfDay(
         this->day_groups.m_data[this->present_day_group],
         time_of_day,
         (SkyTimeOfDay **)&time_of_day,
         &after_time,
         &ratio)
    && (v5 = time_of_day, time_of_day != 0.0)
    && *(_DWORD *)(LODWORD(time_of_day) + 28)
    && (v6 = after_time) != 0
    && after_time->world_fog )
  {
    v7 = max;
    *min = (after_time->min_world_fog - *(float *)(LODWORD(time_of_day) + 32)) * ratio
         + *(float *)(LODWORD(time_of_day) + 32);
    *v7 = (v6->max_world_fog - *(float *)(LODWORD(v5) + 36)) * ratio + *(float *)(LODWORD(v5) + 36);
    v8 = *(_BYTE *)(LODWORD(v5) + 41);
    LODWORD(v9) = BYTE1(v6->world_fog_color.color);
    LODWORD(time_of_day) = *(_BYTE *)(LODWORD(v5) + 42);
    v10 = (double)SLODWORD(time_of_day);
    time_of_day = v9;
    v11 = (unsigned __int64)(((double)SLODWORD(v9) - (double)v8) * ratio + (double)v8);
    HIDWORD(v11) = LOBYTE(v6->world_fog_color.color);
    LODWORD(time_of_day) = *(_BYTE *)(LODWORD(v5) + 40);
    v12 = v11;
    v13 = (double)SLODWORD(time_of_day);
    time_of_day = *((float *)&v11 + 1);
    LOBYTE(time_of_day) = (unsigned __int64)(((double)SHIDWORD(v11) - v13) * ratio + v13);
    min = (float *)v6->world_fog_color.r;
    v14 = (unsigned __int64)(((double)(signed int)min - v10) * ratio + v10);
    v15 = color;
    BYTE4(v14) = LOBYTE(time_of_day);
    color->g = v12;
    v15->r = v14;
    v15->b = BYTE4(v14);
    v15->a = -1;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00500E10) --------------------------------------------------------  // acclient.c:301663
void __thiscall SkyDesc::CalcPresentDayGroup(SkyDesc *this)
{
  SkyDesc *v1; // esi@1
  int v2; // edi@2
  int v3; // edx@2
  int v4; // eax@2
  unsigned __int64 v5; // rax@4
  bool v6; // cf@4

  v1 = this;
  if ( GameTime::current_game_time )
  {
    v2 = GameTime::current_game_time->current_day;
    v3 = GameTime::current_game_time->days_per_year;
    v4 = GameTime::current_game_time->current_year;
  }
  else
  {
    v2 = 0;
    v3 = 0;
    v4 = 0;
  }
  v5 = (unsigned __int64)_floor((double)(unsigned int)(1782775218 * (v2 + v3 * v4) - 1967253934) * 2.3283064e-10 * (double)this->day_groups.m_num);
  v6 = (unsigned int)v5 < v1->day_groups.m_num;
  v1->present_day_group = v5;
  if ( !v6 )
    v1->present_day_group = 0;
}

//----- (00500ED0) --------------------------------------------------------  // acclient.c:301710
unsigned int __thiscall SkyObject::Pack(SkyObject *this, void **addr, unsigned int *size)
{
  unsigned int v3; // edx@2
  unsigned int v4; // edx@3
  unsigned int v5; // edx@4
  unsigned int v6; // edx@5
  unsigned int v7; // edx@6
  unsigned int v8; // edx@7
  unsigned int v9; // edx@8
  unsigned int v10; // edx@9

  if ( *size >= 4 )
  {
    *(float *)*addr = this->begin_time;
    *addr = (char *)*addr + 4;
    v3 = *size - 4;
    *size = v3;
    if ( v3 >= 4 )
    {
      *(float *)*addr = this->end_time;
      *addr = (char *)*addr + 4;
      v4 = *size - 4;
      *size = v4;
      if ( v4 >= 4 )
      {
        *(float *)*addr = this->begin_angle;
        *addr = (char *)*addr + 4;
        v5 = *size - 4;
        *size = v5;
        if ( v5 >= 4 )
        {
          *(float *)*addr = this->end_angle;
          *addr = (char *)*addr + 4;
          v6 = *size - 4;
          *size = v6;
          if ( v6 >= 4 )
          {
            *(float *)*addr = this->tex_velocity.x;
            *addr = (char *)*addr + 4;
            v7 = *size - 4;
            *size = v7;
            if ( v7 >= 4 )
            {
              *(float *)*addr = this->tex_velocity.y;
              *addr = (char *)*addr + 4;
              v8 = *size - 4;
              *size = v8;
              if ( v8 >= 4 )
              {
                *(_DWORD *)*addr = this->default_gfx_object.id;
                *addr = (char *)*addr + 4;
                v9 = *size - 4;
                *size = v9;
                if ( v9 >= 4 )
                {
                  *(_DWORD *)*addr = this->default_pes_object.id;
                  *addr = (char *)*addr + 4;
                  v10 = *size - 4;
                  *size = v10;
                  if ( v10 >= 4 )
                  {
                    *(_DWORD *)*addr = this->properties;
                    *addr = (char *)*addr + 4;
                    *size -= 4;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  PackObj::ALIGN_PTR(addr, size);
  return *size;
}

//----- (00500FD0) --------------------------------------------------------  // acclient.c:301788
int __thiscall SkyObject::UnPack(SkyObject *this, void **addr, unsigned int *size)
{
  SkyObject *v3; // esi@1
  unsigned int v4; // edx@2
  unsigned int v5; // edx@3
  unsigned int v6; // edx@4
  unsigned int v7; // edx@5
  unsigned int v8; // edx@6
  unsigned int v9; // edi@9
  unsigned int v10; // edi@10

  v3 = this;
  SkyObject::Destroy(this);
  if ( *size >= 4 )
  {
    LODWORD(v3->begin_time) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    v4 = *size - 4;
    *size = v4;
    if ( v4 >= 4 )
    {
      LODWORD(v3->end_time) = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      v5 = *size - 4;
      *size = v5;
      if ( v5 >= 4 )
      {
        LODWORD(v3->begin_angle) = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
        v6 = *size - 4;
        *size = v6;
        if ( v6 >= 4 )
        {
          LODWORD(v3->end_angle) = *(_DWORD *)*addr;
          *addr = (char *)*addr + 4;
          v7 = *size - 4;
          *size = v7;
          if ( v7 >= 4 )
          {
            LODWORD(v3->tex_velocity.x) = *(_DWORD *)*addr;
            *addr = (char *)*addr + 4;
            v8 = *size - 4;
            *size = v8;
            if ( v8 >= 4 )
            {
              LODWORD(v3->tex_velocity.y) = *(_DWORD *)*addr;
              *addr = (char *)*addr + 4;
              *size -= 4;
            }
          }
        }
      }
    }
  }
  LODWORD(v3->tex_velocity.z) = 0;
  if ( *size >= 4 )
  {
    v9 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    *size -= 4;
    v3->default_gfx_object.id = v9;
    if ( *size >= 4 )
    {
      v10 = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      *size -= 4;
      v3->default_pes_object.id = v10;
      if ( *size >= 4 )
      {
        v3->properties = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
        *size -= 4;
      }
    }
  }
  PackObj::ALIGN_PTR(addr, size);
  return 1;
}

//----- (005010D0) --------------------------------------------------------  // acclient.c:301868
unsigned int __thiscall SkyObjectReplace::Pack(SkyObjectReplace *this, void **addr, unsigned int *size)
{
  unsigned int v3; // edx@2
  unsigned int v4; // edx@3
  unsigned int v5; // edx@4
  unsigned int v6; // edx@5
  unsigned int v7; // edx@6

  if ( *size >= 4 )
  {
    *(_DWORD *)*addr = this->object_index;
    *addr = (char *)*addr + 4;
    v3 = *size - 4;
    *size = v3;
    if ( v3 >= 4 )
    {
      *(_DWORD *)*addr = this->gfx_obj_id.id;
      *addr = (char *)*addr + 4;
      v4 = *size - 4;
      *size = v4;
      if ( v4 >= 4 )
      {
        *(float *)*addr = this->rotate;
        *addr = (char *)*addr + 4;
        v5 = *size - 4;
        *size = v5;
        if ( v5 >= 4 )
        {
          *(float *)*addr = this->transparent;
          *addr = (char *)*addr + 4;
          v6 = *size - 4;
          *size = v6;
          if ( v6 >= 4 )
          {
            *(float *)*addr = this->luminosity;
            *addr = (char *)*addr + 4;
            v7 = *size - 4;
            *size = v7;
            if ( v7 >= 4 )
            {
              *(float *)*addr = this->max_bright;
              *addr = (char *)*addr + 4;
              *size -= 4;
            }
          }
        }
      }
    }
  }
  PackObj::ALIGN_PTR(addr, size);
  return *size;
}

//----- (00501180) --------------------------------------------------------  // acclient.c:301922
int __thiscall SkyObjectReplace::UnPack(SkyObjectReplace *this, void **addr, unsigned int *size)
{
  unsigned int v3; // esi@2
  unsigned int v4; // edi@3
  unsigned int v5; // esi@4
  unsigned int v6; // esi@5
  unsigned int v7; // esi@6

  if ( *size >= 4 )
  {
    this->object_index = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    v3 = *size - 4;
    *size = v3;
    if ( v3 >= 4 )
    {
      v4 = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      *size -= 4;
      this->gfx_obj_id.id = v4;
      if ( *size >= 4 )
      {
        LODWORD(this->rotate) = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
        v5 = *size - 4;
        *size = v5;
        if ( v5 >= 4 )
        {
          LODWORD(this->transparent) = *(_DWORD *)*addr;
          *addr = (char *)*addr + 4;
          v6 = *size - 4;
          *size = v6;
          if ( v6 >= 4 )
          {
            LODWORD(this->luminosity) = *(_DWORD *)*addr;
            *addr = (char *)*addr + 4;
            v7 = *size - 4;
            *size = v7;
            if ( v7 >= 4 )
            {
              LODWORD(this->max_bright) = *(_DWORD *)*addr;
              *addr = (char *)*addr + 4;
              *size -= 4;
            }
          }
        }
      }
    }
  }
  PackObj::ALIGN_PTR(addr, size);
  return 1;
}

//----- (00501230) --------------------------------------------------------  // acclient.c:301976
void __thiscall SkyTimeOfDay::~SkyTimeOfDay(SkyTimeOfDay *this)
{
  SkyTimeOfDay *v1; // esi@1
  unsigned int v2; // edi@1
  void *v3; // ST04_4@5

  v1 = this;
  v2 = 0;
  if ( this->sky_obj_replace.m_num )
  {
    do
    {
      if ( v1->sky_obj_replace.m_data[v2] )
        operator delete(v1->sky_obj_replace.m_data[v2]);
      ++v2;
    }
    while ( v2 < v1->sky_obj_replace.m_num );
  }
  v3 = v1->sky_obj_replace.m_data;
  v1->sky_obj_replace.m_num = 0;
  v1->sky_obj_replace.m_size = 0;
  operator delete[](v3);
  v1->sky_obj_replace.m_data = 0;
  operator delete[](v1->sky_obj_replace.m_data);
}

//----- (00501290) --------------------------------------------------------  // acclient.c:302003
unsigned int __thiscall SkyTimeOfDay::Pack(SkyTimeOfDay *this, void **addr, unsigned int *size)
{
  unsigned int *v3; // esi@1
  SkyTimeOfDay *v4; // ebx@1
  unsigned int v5; // eax@2
  unsigned int v6; // eax@3
  unsigned int v7; // eax@4
  unsigned int v8; // eax@5
  unsigned int v9; // eax@6
  unsigned int v10; // eax@7
  unsigned int v11; // eax@8
  unsigned int v12; // eax@9
  unsigned int v13; // eax@10
  unsigned int v14; // eax@11
  unsigned int v15; // eax@13
  unsigned int v16; // ebp@15
  unsigned int *sizea; // [sp+18h] [bp+8h]@13

  v3 = size;
  v4 = this;
  if ( *size >= 4 )
  {
    *(_DWORD *)*addr = LODWORD(this->begin);
    *addr = (char *)*addr + 4;
    v5 = *size - 4;
    *size = v5;
    if ( v5 >= 4 )
    {
      *(float *)*addr = this->dir_bright;
      *addr = (char *)*addr + 4;
      v6 = *size - 4;
      *size = v6;
      if ( v6 >= 4 )
      {
        *(float *)*addr = this->dir_heading;
        *addr = (char *)*addr + 4;
        v7 = *size - 4;
        *size = v7;
        if ( v7 >= 4 )
        {
          *(float *)*addr = this->dir_pitch;
          *addr = (char *)*addr + 4;
          v8 = *size - 4;
          *size = v8;
          if ( v8 >= 4 )
          {
            *(_DWORD *)*addr = this->dir_color.color;
            *addr = (char *)*addr + 4;
            v9 = *size - 4;
            *size = v9;
            if ( v9 >= 4 )
            {
              *(float *)*addr = this->amb_bright;
              *addr = (char *)*addr + 4;
              v10 = *size - 4;
              *size = v10;
              if ( v10 >= 4 )
              {
                *(_DWORD *)*addr = this->amb_color.color;
                *addr = (char *)*addr + 4;
                v11 = *size - 4;
                *size = v11;
                if ( v11 >= 4 )
                {
                  *(float *)*addr = this->min_world_fog;
                  *addr = (char *)*addr + 4;
                  v12 = *size - 4;
                  *size = v12;
                  if ( v12 >= 4 )
                  {
                    *(float *)*addr = this->max_world_fog;
                    *addr = (char *)*addr + 4;
                    v13 = *size - 4;
                    *size = v13;
                    if ( v13 >= 4 )
                    {
                      *(_DWORD *)*addr = this->world_fog_color.color;
                      *addr = (char *)*addr + 4;
                      v14 = *size - 4;
                      *size = v14;
                      if ( v14 >= 4 )
                      {
                        *(_DWORD *)*addr = this->world_fog;
                        *addr = (char *)*addr + 4;
                        *size -= 4;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  PackObj::ALIGN_PTR(addr, size);
  v15 = v4->sky_obj_replace.m_num;
  sizea = (unsigned int *)v4->sky_obj_replace.m_num;
  if ( *v3 >= 4 )
  {
    *(_DWORD *)*addr = v15;
    *addr = (char *)*addr + 4;
    *v3 -= 4;
  }
  v16 = 0;
  if ( v15 )
  {
    do
      SkyObjectReplace::Pack(v4->sky_obj_replace.m_data[v16++], addr, v3);
    while ( v16 < (unsigned int)sizea );
  }
  return *v3;
}

//----- (00501400) --------------------------------------------------------  // acclient.c:302119
void __thiscall SkyDesc::GetSubDataIDs(SkyDesc *this, QualifiedDataIDArray *id_array)
{
  int v2; // eax@1
  DayGroup *v3; // ebx@2
  unsigned int v4; // esi@2
  IDClass<_tagDataID,32,0> v5; // eax@3
  QualifiedDataID *v6; // eax@4
  unsigned int v7; // eax@6
  SkyTimeOfDay *v8; // esi@7
  unsigned int v9; // edi@7
  IDClass<_tagDataID,32,0> v10; // eax@8
  QualifiedDataID *v11; // eax@9
  unsigned int jq; // [sp+Ch] [bp-1Ch]@6
  unsigned int iq; // [sp+10h] [bp-18h]@1
  SkyDesc *v14; // [sp+14h] [bp-14h]@1
  QualifiedDataID v15; // [sp+18h] [bp-10h]@4
  QualifiedDataID v16; // [sp+20h] [bp-8h]@9

  v2 = 0;
  v14 = this;
  iq = 0;
  if ( this->day_groups.m_num )
  {
    do
    {
      v3 = this->day_groups.m_data[v2];
      v4 = 0;
      if ( v3->sky_objects.m_num )
      {
        do
        {
          v5.id = v3->sky_objects.m_data[v4]->default_gfx_object.id;
          if ( v5.id != stru_84152C.id )
          {
            QualifiedDataID::QualifiedDataID(&v15, v5, 0);
            QualifiedDataIDArray::AddQDID(id_array, v6, 8u);
          }
          ++v4;
        }
        while ( v4 < v3->sky_objects.m_num );
      }
      v7 = 0;
      jq = 0;
      if ( v3->sky_time.m_num )
      {
        do
        {
          v8 = v3->sky_time.m_data[v7];
          v9 = 0;
          if ( v8->sky_obj_replace.m_num )
          {
            do
            {
              v10.id = v8->sky_obj_replace.m_data[v9]->gfx_obj_id.id;
              if ( v10.id != stru_84152C.id )
              {
                QualifiedDataID::QualifiedDataID(&v16, v10, 0);
                QualifiedDataIDArray::AddQDID(id_array, v11, 8u);
              }
              ++v9;
            }
            while ( v9 < v8->sky_obj_replace.m_num );
            v7 = jq;
          }
          ++v7;
          jq = v7;
        }
        while ( v7 < v3->sky_time.m_num );
      }
      this = v14;
      v2 = iq++ + 1;
    }
    while ( iq < v14->day_groups.m_num );
  }
}

//----- (005014F0) --------------------------------------------------------  // acclient.c:302196
int __thiscall AC1Legacy::SmartArray<CelestialPosition>::grow(AC1Legacy::SmartArray<CelestialPosition> *this, unsigned int _size)
{
  AC1Legacy::SmartArray<CelestialPosition> *v2; // ebx@1
  unsigned int v3; // esi@1
  void *v5; // eax@5
  int v6; // ebp@6
  unsigned int v7; // edx@8
  int v8; // eax@9

  v2 = this;
  v3 = _size;
  if ( _size >= this->m_num )
  {
    if ( _size <= this->m_size )
      return 1;
    if ( !_size )
    {
      AC1Legacy::SmartArray<ScriptAndModData>::Reset((AC1Legacy::SmartArray<ScriptAndModData> *)this);
      return 1;
    }
    v5 = operator new[](44 * _size + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = _size;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x2Cu,
        _size,
        (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
      if ( v6 )
      {
        if ( v2->m_data )
        {
          v7 = 0;
          if ( v2->m_num )
          {
            v8 = 0;
            do
            {
              qmemcpy((void *)(v8 * 44 + v6), &v2->m_data[v8], 0x2Cu);
              ++v7;
              ++v8;
            }
            while ( v7 < v2->m_num );
            v3 = _size;
          }
          if ( v2->m_data )
            operator delete[](&v2->m_data[-1].properties);
        }
        v2->m_data = (CelestialPosition *)v6;
        v2->m_size = v3;
        return 1;
      }
    }
  }
  return 0;
}

//----- (005015B0) --------------------------------------------------------  // acclient.c:302256
unsigned int __thiscall SkyTimeOfDay::UnPack(SkyTimeOfDay *this, void **addr, unsigned int *size)
{
  unsigned int *v3; // esi@1
  SkyTimeOfDay *v4; // ebx@1
  unsigned int v5; // eax@2
  unsigned int v6; // eax@3
  unsigned int v7; // eax@4
  unsigned int v8; // eax@5
  unsigned int v9; // eax@6
  unsigned int v10; // eax@7
  unsigned int v11; // eax@8
  unsigned int v12; // eax@9
  unsigned int v13; // eax@10
  unsigned int v14; // eax@11
  unsigned int v15; // ebp@14
  int v16; // ebx@16
  void *v17; // eax@18
  SkyObjectReplace *v18; // ebp@18
  unsigned int v19; // eax@20
  unsigned int v20; // eax@22
  unsigned int *sizea; // [sp+18h] [bp+8h]@17

  v3 = size;
  v4 = this;
  if ( *size >= 4 )
  {
    LODWORD(this->begin) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    v5 = *size - 4;
    *size = v5;
    if ( v5 >= 4 )
    {
      LODWORD(this->dir_bright) = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      v6 = *size - 4;
      *size = v6;
      if ( v6 >= 4 )
      {
        LODWORD(this->dir_heading) = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
        v7 = *size - 4;
        *size = v7;
        if ( v7 >= 4 )
        {
          LODWORD(this->dir_pitch) = *(_DWORD *)*addr;
          *addr = (char *)*addr + 4;
          v8 = *size - 4;
          *size = v8;
          if ( v8 >= 4 )
          {
            this->dir_color.color = *(_DWORD *)*addr;
            *addr = (char *)*addr + 4;
            v9 = *size - 4;
            *size = v9;
            if ( v9 >= 4 )
            {
              LODWORD(this->amb_bright) = *(_DWORD *)*addr;
              *addr = (char *)*addr + 4;
              v10 = *size - 4;
              *size = v10;
              if ( v10 >= 4 )
              {
                this->amb_color.color = *(_DWORD *)*addr;
                *addr = (char *)*addr + 4;
                v11 = *size - 4;
                *size = v11;
                if ( v11 >= 4 )
                {
                  LODWORD(this->min_world_fog) = *(_DWORD *)*addr;
                  *addr = (char *)*addr + 4;
                  v12 = *size - 4;
                  *size = v12;
                  if ( v12 >= 4 )
                  {
                    LODWORD(this->max_world_fog) = *(_DWORD *)*addr;
                    *addr = (char *)*addr + 4;
                    v13 = *size - 4;
                    *size = v13;
                    if ( v13 >= 4 )
                    {
                      this->world_fog_color.color = *(_DWORD *)*addr;
                      *addr = (char *)*addr + 4;
                      v14 = *size - 4;
                      *size = v14;
                      if ( v14 >= 4 )
                      {
                        this->world_fog = *(_DWORD *)*addr;
                        *addr = (char *)*addr + 4;
                        *size -= 4;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  PackObj::ALIGN_PTR(addr, size);
  if ( *size < 4 )
  {
    v15 = (unsigned int)size;
  }
  else
  {
    v15 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  v16 = (int)&v4->sky_obj_replace;
  AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v16, v15);
  if ( v15 )
  {
    sizea = (unsigned int *)v15;
    do
    {
      v17 = operator new(0x1Cu);
      v18 = 0;
      if ( v17 )
      {
        *(_DWORD *)v17 = 0;
        *((_DWORD *)v17 + 1) = 0;
        *((_DWORD *)v17 + 2) = 0;
        *((_DWORD *)v17 + 3) = 0;
        *((_DWORD *)v17 + 5) = 0;
        *((_DWORD *)v17 + 6) = 0;
        *((_DWORD *)v17 + 4) = -1082130432;
        v18 = (SkyObjectReplace *)v17;
      }
      SkyObjectReplace::UnPack(v18, addr, v3);
      v19 = *(_DWORD *)(v16 + 4);
      if ( *(_DWORD *)(v16 + 8) < v19
        || (!v19 ? (v20 = 8) : (v20 = 2 * v19),
            AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v16, v20)) )
        *(_DWORD *)(*(_DWORD *)v16 + 4 * (*(_DWORD *)(v16 + 8))++) = v18;
      sizea = (unsigned int *)((char *)sizea - 1);
    }
    while ( sizea );
  }
  return *v3;
}

//----- (00501780) --------------------------------------------------------  // acclient.c:302401
void __thiscall DayGroup::Destroy(DayGroup *this)
{
  DayGroup *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  SkyTimeOfDay **v4; // eax@2
  void *v5; // esi@2
  void *v6; // ST04_4@5
  unsigned int i; // ebx@5
  SkyObject *v8; // esi@6
  int v9; // ecx@7
  void *v10; // ST04_4@9

  v1 = this;
  v2 = this->sky_time.m_num;
  v3 = 0;
  LODWORD(this->chance_of_occur) = 0;
  if ( v2 )
  {
    do
    {
      v4 = v1->sky_time.m_data;
      v5 = v4[v3];
      if ( v5 )
      {
        SkyTimeOfDay::~SkyTimeOfDay(v4[v3]);
        operator delete(v5);
      }
      ++v3;
    }
    while ( v3 < v1->sky_time.m_num );
  }
  v6 = v1->sky_time.m_data;
  v1->sky_time.m_num = 0;
  v1->sky_time.m_size = 0;
  operator delete[](v6);
  v1->sky_time.m_data = 0;
  for ( i = 0; i < v1->sky_objects.m_num; ++i )
  {
    v8 = v1->sky_objects.m_data[i];
    if ( v8 )
    {
      operator delete[](v8->object_name);
      v9 = (int)&v8->tex_velocity;
      *(_DWORD *)v9 = 0;
      *(_DWORD *)(v9 + 4) = 0;
      v8->object_name = 0;
      LODWORD(v8->begin_time) = 0;
      LODWORD(v8->end_time) = 0;
      LODWORD(v8->begin_angle) = 0;
      LODWORD(v8->end_angle) = 0;
      *(_DWORD *)(v9 + 8) = 0;
      v8->default_gfx_object.id = stru_84152C.id;
      v8->default_pes_object.id = stru_84152C.id;
      v8->properties = 0;
      operator delete(v8);
    }
  }
  v10 = v1->sky_objects.m_data;
  v1->sky_objects.m_num = 0;
  v1->sky_objects.m_size = 0;
  operator delete[](v10);
  v1->sky_objects.m_data = 0;
}

//----- (00501870) --------------------------------------------------------  // acclient.c:302467
int __thiscall DayGroup::pack_size(DayGroup *this)
{
  unsigned int v1; // eax@1
  signed int v2; // edx@1
  int v3; // esi@3
  int v4; // eax@3
  int v5; // edx@4
  int v6; // esi@6
  int v7; // edx@7
  int v8; // eax@9
  SkyTimeOfDay **v9; // edi@10
  unsigned int v10; // ebx@10
  unsigned int v11; // esi@11
  int v12; // edx@11
  unsigned int v13; // ecx@14
  int result; // eax@14

  v1 = this->day_name.m_buffer->m_len - 1;
  v2 = 0;
  if ( v1 >= 0xFFFF )
    v2 = 4;
  v3 = v2 + v1 + 2;
  v4 = ((_BYTE)v2 + (_BYTE)v1 + 2) & 3;
  if ( v4 )
    v5 = 4 - v4;
  else
    v5 = 0;
  v6 = v5 + v3 + 4;
  if ( v6 & 3 )
    v7 = 4 - (v6 & 3);
  else
    v7 = 0;
  v8 = v6 + v7 + 4;
  if ( this->sky_time.m_num )
  {
    v9 = this->sky_time.m_data;
    v10 = this->sky_time.m_num;
    do
    {
      v11 = (*v9)->sky_obj_replace.m_num;
      v12 = 48;
      if ( v11 )
        v12 = 8 * (3 * v11 + 6);
      v8 += v12;
      ++v9;
      --v10;
    }
    while ( v10 );
  }
  v13 = this->sky_objects.m_num;
  result = v8 + 4;
  if ( v13 )
    result += 36 * v13;
  return result;
}

//----- (00501900) --------------------------------------------------------  // acclient.c:302524
unsigned int __thiscall DayGroup::Pack(DayGroup *this, void **addr, unsigned int *size)
{
  DayGroup *v3; // ebx@1
  unsigned int v4; // ebp@5
  unsigned int v5; // ebp@9

  v3 = this;
  if ( *size >= 4 )
  {
    *(float *)*addr = this->chance_of_occur;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  *size -= AC1Legacy::PStringBase<char>::Pack(&this->day_name, addr, *size);
  PackObj::ALIGN_PTR(addr, size);
  if ( *size >= 4 )
  {
    *(_DWORD *)*addr = v3->sky_objects.m_num;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  v4 = 0;
  if ( v3->sky_objects.m_num )
  {
    do
      SkyObject::Pack(v3->sky_objects.m_data[v4++], addr, size);
    while ( v4 < v3->sky_objects.m_num );
  }
  if ( *size >= 4 )
  {
    *(_DWORD *)*addr = v3->sky_time.m_num;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  v5 = 0;
  if ( v3->sky_time.m_num )
  {
    do
      SkyTimeOfDay::Pack(v3->sky_time.m_data[v5++], addr, size);
    while ( v5 < v3->sky_time.m_num );
  }
  return *size;
}

//----- (005019B0) --------------------------------------------------------  // acclient.c:302569
int __thiscall SkyDesc::pack_size(SkyDesc *this)
{
  signed int v1; // esi@1
  DayGroup **v2; // edi@2
  unsigned int v3; // ebx@2
  int result; // eax@5

  v1 = 20;
  if ( this->day_groups.m_num )
  {
    v2 = this->day_groups.m_data;
    v3 = this->day_groups.m_num;
    do
    {
      v1 += DayGroup::pack_size(*v2);
      ++v2;
      --v3;
    }
    while ( v3 );
  }
  if ( v1 & 3 )
    result = v1 + 4 - (v1 & 3);
  else
    result = v1;
  return result;
}

//----- (005019F0) --------------------------------------------------------  // acclient.c:302597
unsigned int __thiscall SkyDesc::Pack(SkyDesc *this, void **addr, unsigned int *size)
{
  unsigned int *v3; // esi@1
  SkyDesc *v4; // ebp@1
  unsigned int v5; // eax@2
  unsigned int v6; // eax@4
  unsigned int v7; // ebx@6
  unsigned int *sizea; // [sp+18h] [bp+8h]@4

  v3 = size;
  v4 = this;
  if ( *size >= 8 )
  {
    *(double *)*addr = this->tick_size;
    *addr = (char *)*addr + 8;
    v5 = *size - 8;
    *size = v5;
    if ( v5 >= 8 )
    {
      *(double *)*addr = this->light_tick_size;
      *addr = (char *)*addr + 8;
      *size -= 8;
    }
  }
  PackObj::ALIGN_PTR(addr, size);
  v6 = v4->day_groups.m_num;
  sizea = (unsigned int *)v4->day_groups.m_num;
  if ( *v3 >= 4 )
  {
    *(_DWORD *)*addr = v6;
    *addr = (char *)*addr + 4;
    *v3 -= 4;
  }
  v7 = 0;
  if ( v6 )
  {
    do
      DayGroup::Pack(v4->day_groups.m_data[v7++], addr, v3);
    while ( v7 < (unsigned int)sizea );
  }
  return *v3;
}

//----- (00501A70) --------------------------------------------------------  // acclient.c:302641
int __thiscall DayGroup::UnPack(DayGroup *this, void **addr, unsigned int *size)
{
  unsigned int *v3; // ebp@1
  DayGroup *v4; // esi@1
  int result; // eax@3
  int v6; // eax@4
  signed int v7; // ecx@4
  int v8; // eax@6
  int v9; // ecx@7
  unsigned int v10; // ecx@10
  int v11; // esi@11
  void *v12; // eax@13
  unsigned int v13; // eax@16
  unsigned int v14; // eax@18
  unsigned int v15; // ecx@24
  void *v16; // eax@27
  void *v17; // esi@28
  unsigned int v18; // eax@30
  int v19; // ecx@31
  int v20; // ecx@33
  unsigned int v21; // eax@33
  unsigned int v22; // eax@35
  unsigned int num; // [sp+Ch] [bp-14h]@0
  SkyObject *obj; // [sp+10h] [bp-10h]@14
  SkyObject *obja; // [sp+10h] [bp-10h]@26
  AC1Legacy::SmartArray<Season *> *v26; // [sp+14h] [bp-Ch]@12
  DayGroup *v27; // [sp+18h] [bp-8h]@1
  int v28; // [sp+1Ch] [bp-4h]@11

  v3 = size;
  v4 = this;
  v27 = this;
  if ( *size >= 4 )
  {
    LODWORD(this->chance_of_occur) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  result = AC1Legacy::PStringBase<char>::UnPack(&this->day_name, addr, *size);
  if ( result )
  {
    v6 = v4->day_name.m_buffer->m_len - 1;
    v7 = 0;
    if ( (unsigned int)v6 >= 0xFFFF )
      v7 = 4;
    v8 = v7 + v6 + 2;
    if ( v8 & 3 )
      v9 = 4 - (v8 & 3);
    else
      v9 = 0;
    *size -= v8 + v9;
    PackObj::ALIGN_PTR(addr, size);
    if ( *size >= 4 )
    {
      v10 = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      num = v10;
      *size -= 4;
    }
    v11 = (int)&v4->sky_objects;
    v28 = v11;
    AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v11, num);
    if ( num > 0 )
    {
      v26 = (AC1Legacy::SmartArray<Season *> *)num;
      do
      {
        v12 = operator new(0x2Cu);
        if ( v12 )
        {
          *(_DWORD *)v12 = 0;
          *((_DWORD *)v12 + 1) = 0;
          *((_DWORD *)v12 + 2) = 0;
          *((_DWORD *)v12 + 3) = 0;
          *((_DWORD *)v12 + 4) = 0;
          *((_DWORD *)v12 + 5) = 0;
          *((_DWORD *)v12 + 6) = 0;
          *((_DWORD *)v12 + 7) = 0;
          *((_DWORD *)v12 + 8) = 0;
          *((_DWORD *)v12 + 9) = 0;
          *((_DWORD *)v12 + 10) = 0;
          obj = (SkyObject *)v12;
          SkyObject::UnPack((SkyObject *)v12, addr, size);
        }
        else
        {
          obj = 0;
          SkyObject::UnPack(0, addr, size);
        }
        v13 = *(_DWORD *)(v11 + 4);
        if ( *(_DWORD *)(v11 + 8) < v13
          || (v13 <= 0 ? (v14 = 8) : (v14 = 2 * v13),
              AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v11, v14)) )
          *(_DWORD *)(*(_DWORD *)v11 + 4 * (*(_DWORD *)(v11 + 8))++) = obj;
        v26 = (AC1Legacy::SmartArray<Season *> *)((char *)v26 - 1);
      }
      while ( v26 );
    }
    if ( *size >= 4 )
    {
      v15 = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      num = v15;
      *size -= 4;
    }
    AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v27->sky_time, num);
    if ( num > 0 )
    {
      obja = (SkyObject *)num;
      do
      {
        v16 = operator new(0x38u);
        if ( v16 )
        {
          *(_DWORD *)v16 = 0;
          *((_DWORD *)v16 + 1) = 0;
          *((_DWORD *)v16 + 2) = 0;
          *((_DWORD *)v16 + 3) = 0;
          *((_DWORD *)v16 + 5) = 0;
          *((_DWORD *)v16 + 7) = 0;
          *((_DWORD *)v16 + 8) = 0;
          *((_DWORD *)v16 + 9) = 0;
          *((_DWORD *)v16 + 11) = 0;
          *((_DWORD *)v16 + 12) = 0;
          *((_DWORD *)v16 + 13) = 0;
          *((_BYTE *)v16 + 18) = -1;
          *((_BYTE *)v16 + 17) = -1;
          *((_BYTE *)v16 + 16) = -1;
          *((_BYTE *)v16 + 19) = -1;
          *((_BYTE *)v16 + 26) = -1;
          *((_BYTE *)v16 + 25) = -1;
          *((_BYTE *)v16 + 24) = -1;
          *((_BYTE *)v16 + 27) = -1;
          *((_BYTE *)v16 + 42) = -1;
          *((_BYTE *)v16 + 41) = -1;
          *((_BYTE *)v16 + 40) = -1;
          *((_BYTE *)v16 + 43) = -1;
          v17 = v16;
        }
        else
        {
          v17 = 0;
        }
        SkyTimeOfDay::UnPack((SkyTimeOfDay *)v17, addr, v3);
        v18 = 0;
        if ( *((_DWORD *)v17 + 13) > 0u )
        {
          do
          {
            v19 = *(_DWORD *)(*((_DWORD *)v17 + 11) + 4 * v18);
            *(_DWORD *)(v19 + 4) = *(_DWORD *)(*(_DWORD *)v28 + 4 * *(_DWORD *)v19);
            ++v18;
          }
          while ( v18 < *((_DWORD *)v17 + 13) );
          v3 = size;
        }
        v20 = (int)&v27->sky_time;
        v21 = v27->sky_time.m_size;
        if ( v27->sky_time.m_num >= v21 )
        {
          if ( v21 <= 0 )
            v22 = 8;
          else
            v22 = 2 * v21;
          if ( !AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v27->sky_time, v22) )
            goto LABEL_40;
          v20 = (int)&v27->sky_time;
        }
        *(_DWORD *)(*(_DWORD *)v20 + 4 * (*(_DWORD *)(v20 + 8))++) = v17;
LABEL_40:
        obja = (SkyObject *)((char *)obja - 1);
      }
      while ( obja );
    }
    result = 1;
  }
  return result;
}

//----- (00501CD0) --------------------------------------------------------  // acclient.c:302821
int __thiscall SkyDesc::UnPack(SkyDesc *this, void **addr, unsigned int *size)
{
  void **v3; // ebx@1
  unsigned int *v4; // edi@1
  SkyDesc *v5; // esi@1
  void *v6; // eax@2
  unsigned int v7; // eax@2
  void *v8; // eax@3
  void **v9; // ecx@5
  void *v10; // esi@7
  volatile LONG *v11; // ST04_4@8
  unsigned int v12; // eax@11
  unsigned int v13; // eax@13
  int result; // eax@18
  unsigned int iq; // [sp+10h] [bp-8h]@6
  AC1Legacy::SmartArray<Season *> *v16; // [sp+14h] [bp-4h]@6
  unsigned int num_dg; // [sp+20h] [bp+8h]@8

  v3 = addr;
  v4 = size;
  v5 = this;
  if ( *size >= 8 )
  {
    v6 = *addr;
    LODWORD(this->tick_size) = *(_DWORD *)*addr;
    HIDWORD(this->tick_size) = *((_DWORD *)v6 + 1);
    *addr = (char *)*addr + 8;
    v7 = *size - 8;
    *size = v7;
    if ( v7 >= 8 )
    {
      v8 = *addr;
      LODWORD(this->light_tick_size) = *(_DWORD *)*addr;
      HIDWORD(this->light_tick_size) = *((_DWORD *)v8 + 1);
      *addr = (char *)*addr + 8;
      *size -= 8;
    }
  }
  PackObj::ALIGN_PTR(addr, size);
  if ( *size >= 4 )
  {
    v9 = *(void ***)*addr;
    *addr = (char *)*addr + 4;
    addr = v9;
    *size -= 4;
  }
  v16 = (AC1Legacy::SmartArray<Season *> *)&v5->day_groups;
  AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v5->day_groups, (unsigned int)addr);
  iq = 0;
  if ( addr )
  {
    while ( 1 )
    {
      v10 = operator new(0x20u);
      if ( v10 )
      {
        v11 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
        *(_DWORD *)v10 = AC1Legacy::PStringBase<char>::s_NullBuffer;
        InterlockedIncrement(v11);
        *((_DWORD *)v10 + 1) = 0;
        *((_DWORD *)v10 + 2) = 0;
        *((_DWORD *)v10 + 3) = 0;
        *((_DWORD *)v10 + 4) = 0;
        *((_DWORD *)v10 + 5) = 0;
        *((_DWORD *)v10 + 6) = 0;
        *((_DWORD *)v10 + 7) = 0;
        num_dg = (unsigned int)v10;
      }
      else
      {
        num_dg = 0;
      }
      if ( !DayGroup::UnPack((DayGroup *)num_dg, v3, v4) )
        break;
      v12 = v16->m_size;
      if ( v16->m_num < v12
        || (v12 <= 0 ? (v13 = 8) : (v13 = 2 * v12), AC1Legacy::SmartArray<SkyTimeOfDay *>::grow(v16, v13)) )
        v16->m_data[v16->m_num++] = (Season *)num_dg;
      ++iq;
      if ( iq >= (unsigned int)addr )
        goto LABEL_18;
    }
    result = 0;
  }
  else
  {
LABEL_18:
    result = 1;
  }
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00501E20) --------------------------------------------------------  // acclient.c:302915
void __thiscall SkyDesc::Destroy(SkyDesc *this)
{
  SkyDesc *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebp@1
  DayGroup **v4; // eax@2
  void *v5; // esi@2
  int v6; // ebx@3
  void *v7; // ST08_4@8

  v1 = this;
  v2 = this->day_groups.m_num;
  v3 = 0;
  this->present_day_group = 0;
  LODWORD(this->tick_size) = 0;
  HIDWORD(this->tick_size) = 1074266112;
  LODWORD(this->light_tick_size) = 0;
  HIDWORD(this->light_tick_size) = 1077149696;
  if ( v2 )
  {
    do
    {
      v4 = v1->day_groups.m_data;
      v5 = v4[v3];
      if ( v5 )
      {
        DayGroup::Destroy(v4[v3]);
        operator delete[](*((void **)v5 + 5));
        operator delete[](*((void **)v5 + 2));
        v6 = *(_DWORD *)v5;
        if ( !InterlockedDecrement((volatile LONG *)(*(_DWORD *)v5 + 4)) && v6 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
        operator delete(v5);
      }
      ++v3;
    }
    while ( v3 < v1->day_groups.m_num );
  }
  v7 = v1->day_groups.m_data;
  v1->day_groups.m_num = 0;
  v1->day_groups.m_size = 0;
  operator delete[](v7);
  v1->day_groups.m_data = 0;
}

//----- (00501EC0) --------------------------------------------------------  // acclient.c:302961
int __thiscall SkyDesc::GetSky(SkyDesc *this, float time_of_day, AC1Legacy::SmartArray<CelestialPosition> *sky_pos)
{
  unsigned int v3; // eax@1
  DayGroup **v4; // ecx@1
  AC1Legacy::SmartArray<CelestialPosition> *v5; // ebx@1
  unsigned int v6; // edx@1
  DayGroup *v7; // esi@1
  unsigned int v8; // ebp@1
  unsigned int v9; // eax@3
  unsigned int v10; // eax@5
  unsigned int v11; // eax@11
  int v12; // eax@12
  unsigned int v13; // edi@15
  int v14; // ecx@16
  SkyObject *v15; // edx@17
  unsigned int v16; // esi@20
  double v17; // st7@23
  int v18; // edx@25
  int v19; // eax@25
  SkyTimeOfDay *v20; // ecx@27
  int v21; // eax@27
  SkyObjectReplace *v22; // esi@28
  unsigned int v23; // eax@28
  SkyObject *v24; // edi@28
  unsigned int v25; // ecx@28
  SkyObject **v26; // edx@29
  unsigned int v27; // eax@32
  unsigned int v28; // edx@39
  unsigned int v29; // eax@39
  SkyObjectReplace *v30; // edx@44
  DayGroup *day; // [sp+10h] [bp-3Ch]@1
  unsigned int iq; // [sp+14h] [bp-38h]@27
  SkyTimeOfDay *prev_time_desc; // [sp+18h] [bp-34h]@26
  SkyTimeOfDay *next_time_desc; // [sp+1Ch] [bp-30h]@26
  CelestialPosition temp_cp; // [sp+20h] [bp-2Ch]@2
  float time_of_daya; // [sp+50h] [bp+4h]@40

  v3 = this->present_day_group;
  v4 = this->day_groups.m_data;
  v5 = sky_pos;
  v6 = sky_pos->m_num;
  v7 = v4[v3];
  v8 = v7->sky_objects.m_num;
  day = v4[v3];
  if ( v6 < v8 )
  {
    memset(&temp_cp, 0, sizeof(temp_cp));
    sky_pos = (AC1Legacy::SmartArray<CelestialPosition> *)(v8 - v6);
    do
    {
      v9 = v5->m_size;
      if ( v5->m_num < v9 || (!v9 ? (v10 = 8) : (v10 = 2 * v9), AC1Legacy::SmartArray<CelestialPosition>::grow(v5, v10)) )
      {
        qmemcpy(&v5->m_data[v5->m_num], &temp_cp, sizeof(v5->m_data[v5->m_num]));
        v7 = day;
        ++v5->m_num;
      }
      sky_pos = (AC1Legacy::SmartArray<CelestialPosition> *)((char *)sky_pos - 1);
    }
    while ( *(float *)&sky_pos != 0.0 );
  }
  while ( v5->m_num > v8 )
  {
    v11 = v5->m_num;
    if ( v8 < v11 )
    {
      v12 = v11 - 1;
      v5->m_num = v12;
      if ( v8 != v12 )
      {
        qmemcpy(&v5->m_data[v8], &v5->m_data[v12], sizeof(v5->m_data[v8]));
        v7 = day;
      }
    }
  }
  v13 = 0;
  if ( v7->sky_objects.m_num )
  {
    v14 = 0;
    do
    {
      v15 = v7->sky_objects.m_data[v13];
      if ( v15->begin_time == v15->end_time
        || time_of_day > (double)v15->begin_time && time_of_day < (double)v15->end_time )
        v16 = v15->default_gfx_object.id;
      else
        v16 = stru_84152C.id;
      v5->m_data[v14].gfx_id.id = v16;
      v5->m_data[v14].pes_id.id = v15->default_pes_object.id;
      v5->m_data[v14].properties = v15->properties;
      LODWORD(v5->m_data[v14].heading) = 0;
      if ( v15->begin_time == v15->end_time )
        v17 = v15->begin_angle;
      else
        v17 = (v15->end_angle - v15->begin_angle) * (time_of_day - v15->begin_time) / (v15->end_time - v15->begin_time)
            + v15->begin_angle;
      v5->m_data[v14].rotation = v17;
      v18 = (int)&v15->tex_velocity;
      v19 = (int)&v5->m_data[v14].tex_velocity;
      *(_DWORD *)v19 = *(_DWORD *)v18;
      *(_DWORD *)(v19 + 4) = *(_DWORD *)(v18 + 4);
      v7 = day;
      *(_DWORD *)(v19 + 8) = *(_DWORD *)(v18 + 8);
      LODWORD(v5->m_data[v14].luminosity) = -1082130432;
      LODWORD(v5->m_data[v14].max_bright) = -1082130432;
      LODWORD(v5->m_data[v14].transparent) = -1082130432;
      ++v13;
      ++v14;
    }
    while ( v13 < day->sky_objects.m_num );
  }
  if ( DayGroup::GetTimeOfDay(v7, time_of_day, &prev_time_desc, &next_time_desc, (float *)&sky_pos) )
  {
    v20 = prev_time_desc;
    v21 = 0;
    iq = 0;
    if ( prev_time_desc->sky_obj_replace.m_num )
    {
      do
      {
        v22 = v20->sky_obj_replace.m_data[v21];
        v23 = day->sky_objects.m_num;
        v24 = v22->object;
        v25 = 0;
        if ( v23 )
        {
          v26 = day->sky_objects.m_data;
          do
          {
            if ( v24 == *v26 )
              break;
            ++v25;
            ++v26;
          }
          while ( v25 < v23 );
        }
        v27 = v22->gfx_obj_id.id;
        if ( v27 )
          v5->m_data[v25].gfx_id.id = v27;
        if ( prev_time_desc->sky_obj_replace.m_data[iq]->rotate != 0.0 )
          v5->m_data[v25].heading = prev_time_desc->sky_obj_replace.m_data[iq]->rotate;
        if ( v22->luminosity > 0.0 || v22->max_bright > 0.0 || v22->transparent >= 0.0 )
        {
          v28 = next_time_desc->sky_obj_replace.m_num;
          v29 = 0;
          if ( v28 )
          {
            time_of_daya = *(float *)&next_time_desc->sky_obj_replace.m_data;
            do
            {
              if ( v24 == *(SkyObject **)(*LODWORD(time_of_daya) + 4) )
                break;
              ++v29;
              LODWORD(time_of_daya) += 4;
            }
            while ( v29 < v28 );
          }
          if ( v29 < v28 )
          {
            v30 = next_time_desc->sky_obj_replace.m_data[v29];
            if ( v22->luminosity > 0.0 && v30->luminosity > 0.0 )
              v5->m_data[v25].luminosity = (v30->luminosity - v22->luminosity) * *(float *)&sky_pos + v22->luminosity;
            if ( v22->max_bright > 0.0 && v30->max_bright > 0.0 )
              v5->m_data[v25].max_bright = (v30->max_bright - v22->max_bright) * *(float *)&sky_pos + v22->max_bright;
            if ( v22->transparent >= 0.0 && v30->transparent >= 0.0 )
              v5->m_data[v25].transparent = (v30->transparent - v22->transparent) * *(float *)&sky_pos
                                          + v22->transparent;
          }
        }
        v20 = prev_time_desc;
        v21 = iq++ + 1;
      }
      while ( iq < prev_time_desc->sky_obj_replace.m_num );
    }
  }
  return 1;
}

//----- (00502250) --------------------------------------------------------  // acclient.c:303140
void __thiscall SkyDesc::~SkyDesc(SkyDesc *this)
{
  SkyDesc *v1; // esi@1

  v1 = this;
  SkyDesc::Destroy(this);
  operator delete[](v1->day_groups.m_data);
}

//----- (006F9730) --------------------------------------------------------  // acclient.c:782175
int sub_6F9730()
{
  return atexit(nullsub_1055);
}

