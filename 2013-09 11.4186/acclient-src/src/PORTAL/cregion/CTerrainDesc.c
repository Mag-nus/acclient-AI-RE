/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CTerrainDesc
   Object     : PORTAL\cregion\CTerrainDesc.obj
   Functions  : 38
   Addresses  : 005023E0 - 00765420 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005023E0) --------------------------------------------------------  // acclient.c:303274
void __thiscall CTerrainDesc::GetSubDataIDs(CTerrainDesc *this, QualifiedDataIDArray *id_array)
{
  LandSurf::GetSubDataIDs(this->land_surfaces, id_array);
}

//----- (005023F0) --------------------------------------------------------  // acclient.c:303280
void __thiscall Box2D::Box2D(CTerrainDesc *this)
{
  this->land_surfaces = 0;
  this->terrain_types.m_data = 0;
  this->terrain_types.m_size = 0;
  this->terrain_types.m_num = 0;
}

//----- (00502400) --------------------------------------------------------  // acclient.c:303289
AmbientSTBDesc *__thiscall CTerrainDesc::GetSTBDesc(CTerrainDesc *this, unsigned int terrain_id, unsigned int scene_type_id)
{
  CTerrainType *v3; // eax@2
  CSceneType *v4; // eax@3
  AmbientSTBDesc *result; // eax@4

  if ( terrain_id < this->terrain_types.m_num
    && (v3 = this->terrain_types.m_data[terrain_id], scene_type_id < v3->scene_types.m_num)
    && (v4 = v3->scene_types.m_data[scene_type_id]) != 0 )
    result = v4->sound_table_desc;
  else
    result = 0;
  return result;
}

//----- (00502430) --------------------------------------------------------  // acclient.c:303305
unsigned int __thiscall CTerrainDesc::NumSceneType(CTerrainDesc *this, unsigned int terrain_id)
{
  unsigned int result; // eax@2

  if ( terrain_id >= this->terrain_types.m_num )
    result = 0;
  else
    result = this->terrain_types.m_data[terrain_id]->scene_types.m_num;
  return result;
}

//----- (00502450) --------------------------------------------------------  // acclient.c:303317
unsigned int __thiscall CTerrainDesc::SceneCount(CTerrainDesc *this, unsigned int terrain_id, unsigned int scene_type_id)
{
  CTerrainType *v3; // eax@2
  CSceneType *v4; // eax@3
  unsigned int result; // eax@4

  if ( terrain_id < this->terrain_types.m_num
    && (v3 = this->terrain_types.m_data[terrain_id], scene_type_id < v3->scene_types.m_num)
    && (v4 = v3->scene_types.m_data[scene_type_id]) != 0 )
    result = v4->scenes.m_num;
  else
    result = 0;
  return result;
}

//----- (00502480) --------------------------------------------------------  // acclient.c:303333
IDClass<_tagDataID,32,0> *__thiscall CTerrainDesc::GetScene(CTerrainDesc *this, IDClass<_tagDataID,32,0> *result, unsigned int terrain_id, unsigned int scene_type_id, unsigned int scene_index)
{
  CSceneType *v5; // eax@1
  IDClass<_tagDataID,32,0> *v6; // edx@2
  IDClass<_tagDataID,32,0> *v7; // eax@2

  v5 = this->terrain_types.m_data[terrain_id]->scene_types.m_data[scene_type_id];
  if ( scene_index >= v5->scenes.m_num )
  {
    v7 = result;
    result->id = stru_8415A4.id;
  }
  else
  {
    v6 = v5->scenes.m_data;
    v7 = result;
    result->id = v6[scene_index].id;
  }
  return v7;
}

//----- (005024C0) --------------------------------------------------------  // acclient.c:303355
void __thiscall CTerrainType::CTerrainType(CTerrainType *this)
{
  CTerrainType *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->terrain_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v1->scene_types.m_data = 0;
  v1->scene_types.m_size = 0;
  v1->scene_types.m_num = 0;
  v1->terrain_color.r = -1;
  v1->terrain_color.g = -1;
  v1->terrain_color.b = -1;
  v1->terrain_color.a = -1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00502500) --------------------------------------------------------  // acclient.c:303375
void __thiscall CTerrainDesc::Destroy(CTerrainDesc *this)
{
  CTerrainDesc *v1; // ebx@1
  unsigned int v2; // eax@1
  void *v3; // esi@2
  void *v4; // ST04_4@3
  int v5; // edi@3
  void *v6; // ST08_4@8
  LandSurf *v7; // esi@8
  unsigned int iq; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = 0;
  iq = 0;
  if ( this->terrain_types.m_num )
  {
    do
    {
      v3 = v1->terrain_types.m_data[v2];
      if ( v3 )
      {
        v4 = (void *)*((_DWORD *)v3 + 2);
        *((_DWORD *)v3 + 4) = 0;
        *((_DWORD *)v3 + 3) = 0;
        operator delete[](v4);
        *((_DWORD *)v3 + 2) = 0;
        operator delete[](0);
        v5 = *(_DWORD *)v3;
        if ( !InterlockedDecrement((volatile LONG *)(*(_DWORD *)v3 + 4)) && v5 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
        operator delete(v3);
        v2 = iq;
      }
      ++v2;
      iq = v2;
    }
    while ( v2 < v1->terrain_types.m_num );
  }
  v6 = v1->terrain_types.m_data;
  v1->terrain_types.m_num = 0;
  v1->terrain_types.m_size = 0;
  operator delete[](v6);
  v1->terrain_types.m_data = 0;
  v7 = v1->land_surfaces;
  if ( v1->land_surfaces )
  {
    LandSurf::~LandSurf(v1->land_surfaces);
    operator delete(v7);
  }
  v1->land_surfaces = 0;
}

//----- (005025B0) --------------------------------------------------------  // acclient.c:303428
int __thiscall CTerrainDesc::Add(CTerrainDesc *this, CTerrainType *terrain)
{
  unsigned int v2; // eax@1
  char *v3; // esi@1
  unsigned int v4; // eax@3
  int result; // eax@5

  v2 = this->terrain_types.m_size;
  v3 = (char *)&this->terrain_types;
  if ( this->terrain_types.m_num < v2
    || (!v2 ? (v4 = 8) : (v4 = 2 * v2),
        (result = AC1Legacy::SmartArray<SkyTimeOfDay *>::grow(
                    (AC1Legacy::SmartArray<Season *> *)&this->terrain_types,
                    v4)) != 0) )
  {
    *(_DWORD *)(*(_DWORD *)v3 + 4 * (*((_DWORD *)v3 + 2))++) = terrain;
    result = 1;
  }
  return result;
}

//----- (00502600) --------------------------------------------------------  // acclient.c:303450
int __thiscall CTerrainDesc::pack_size(CTerrainDesc *this)
{
  signed int v1; // ebp@1
  CTerrainType **v2; // ebx@2
  unsigned int v3; // ecx@2
  int v4; // eax@3
  signed int v5; // edx@3
  int v6; // esi@5
  int v7; // edx@5
  int v8; // eax@6
  CTerrainDesc *v10; // [sp+4h] [bp-4h]@1

  v10 = this;
  v1 = 4;
  if ( this->terrain_types.m_num )
  {
    v2 = this->terrain_types.m_data;
    v3 = this->terrain_types.m_num;
    do
    {
      v4 = (*v2)->terrain_name.m_buffer->m_len - 1;
      v5 = 0;
      if ( (unsigned int)v4 >= 0xFFFF )
        v5 = 4;
      v6 = v5 + v4 + 2;
      v7 = ((_BYTE)v5 + (_BYTE)v4 + 2) & 3;
      if ( v7 )
        v8 = 4 - v7;
      else
        v8 = 0;
      v1 += v6 + v8 + 4 * (*v2)->scene_types.m_num + 8;
      ++v2;
      --v3;
    }
    while ( v3 );
    this = v10;
  }
  return v1 + LandSurf::pack_size(this->land_surfaces);
}

//----- (00502670) --------------------------------------------------------  // acclient.c:303491
void __thiscall CTerrainDesc::~CTerrainDesc(CTerrainDesc *this)
{
  CTerrainDesc *v1; // esi@1

  v1 = this;
  CTerrainDesc::Destroy(this);
  operator delete[](v1->terrain_types.m_data);
}

//----- (006F9960) --------------------------------------------------------  // acclient.c:782305
void sub_6F9960()
{
  flt_841598 = 1000.0 + 1.0;
}

//----- (006F9980) --------------------------------------------------------  // acclient.c:782311
void sub_6F9980()
{
  flt_84159C = 24.0 * 8.0;
}

//----- (006F99A0) --------------------------------------------------------  // acclient.c:782317
void sub_6F99A0()
{
  flt_8415A0 = 24.0 * 0.5;
}

//----- (006F99C0) --------------------------------------------------------  // acclient.c:782323
int sub_6F99C0()
{
  return atexit(nullsub_1052);
}

//----- (006F99D0) --------------------------------------------------------  // acclient.c:782329
int sub_6F99D0()
{
  return atexit(nullsub_1053);
}

//----- (006F99E0) --------------------------------------------------------  // acclient.c:782335
int sub_6F99E0()
{
  return atexit(nullsub_1054);
}

//----- (006F99F0) --------------------------------------------------------  // acclient.c:782341
int _E106_88()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_9, "Sound.SoundDisabled");
  return atexit(_E107_83);
}

//----- (006F9A10) --------------------------------------------------------  // acclient.c:782348
int _E109_53()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_9, "Sound.SoundVolume");
  return atexit(sub_7652D0);
}

//----- (006F9A30) --------------------------------------------------------  // acclient.c:782355
int _E112_80()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_9, "Sound.AmbientSoundDisabled");
  return atexit(_E113_58);
}

//----- (006F9A50) --------------------------------------------------------  // acclient.c:782362
int _E115_59()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_9, "Sound.AmbientSoundVolume");
  return atexit(_E116_51);
}

//----- (006F9A70) --------------------------------------------------------  // acclient.c:782369
int _E118_60()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_9, "Sound.InterfaceSoundDisabled");
  return atexit(_E119_80);
}

//----- (006F9A90) --------------------------------------------------------  // acclient.c:782376
int _E121_54()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_9, "Sound.InterfaceSoundVolume");
  return atexit(_E122_83);
}

//----- (006F9AB0) --------------------------------------------------------  // acclient.c:782383
int _E124_56()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_9, "Sound.SoundFeatures");
  return atexit(_E125_55);
}

//----- (006F9AD0) --------------------------------------------------------  // acclient.c:782390
int _E127_45()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_9, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E128_54);
}

//----- (006F9AF0) --------------------------------------------------------  // acclient.c:782397
int _E130_43()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_9, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_8415CC, "Mono");
  return atexit(_E131_46);
}

//----- (006F9B20) --------------------------------------------------------  // acclient.c:782405
void _E133_33()
{
  VOL_MIN_DIST_SQ_6 = 5.0 * 5.0;
}

//----- (006F9B40) --------------------------------------------------------  // acclient.c:782411
void _E135_25()
{
  INV_LOG_OF_2_6 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (006F9B60) --------------------------------------------------------  // acclient.c:782417
int sub_6F9B60()
{
  return atexit(nullsub_1051);
}

//----- (007652A0) --------------------------------------------------------  // acclient.c:891721
void __cdecl _E107_83()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007652D0) --------------------------------------------------------  // acclient.c:891734
void __cdecl sub_7652D0()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765300) --------------------------------------------------------  // acclient.c:891747
void __cdecl _E113_58()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765330) --------------------------------------------------------  // acclient.c:891760
void __cdecl _E116_51()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765360) --------------------------------------------------------  // acclient.c:891773
void __cdecl _E119_80()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765390) --------------------------------------------------------  // acclient.c:891786
void __cdecl _E122_83()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007653C0) --------------------------------------------------------  // acclient.c:891799
void __cdecl _E125_55()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007653F0) --------------------------------------------------------  // acclient.c:891812
void __cdecl _E128_54()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765420) --------------------------------------------------------  // acclient.c:891825
void __cdecl _E131_46()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_6;
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

