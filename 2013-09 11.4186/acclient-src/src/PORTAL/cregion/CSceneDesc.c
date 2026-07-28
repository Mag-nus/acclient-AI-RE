/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSceneDesc
   Object     : PORTAL\cregion\CSceneDesc.obj
   Functions  : 33
   Addresses  : 00502270 - 00765220 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00502270) --------------------------------------------------------  // acclient.c:303150
void __thiscall CSceneDesc::Destroy(CSceneDesc *this)
{
  CSceneDesc *v1; // esi@1
  unsigned int v2; // ebx@1
  void *v3; // edi@2
  void *v4; // ST04_4@5

  v1 = this;
  v2 = 0;
  if ( this->scene_types.m_num )
  {
    do
    {
      v3 = v1->scene_types.m_data[v2];
      if ( v3 )
      {
        CSceneType::~CSceneType(v1->scene_types.m_data[v2]);
        operator delete(v3);
      }
      ++v2;
    }
    while ( v2 < v1->scene_types.m_num );
  }
  v4 = v1->scene_types.m_data;
  v1->scene_types.m_num = 0;
  v1->scene_types.m_size = 0;
  operator delete[](v4);
  v1->scene_types.m_data = 0;
}

//----- (005022D0) --------------------------------------------------------  // acclient.c:303181
signed int __thiscall CSceneDesc::pack_size(CSceneDesc *this)
{
  CSceneDesc *v1; // edi@1
  unsigned int v2; // esi@1
  signed int v3; // ebx@1

  v1 = this;
  v2 = 0;
  v3 = 4;
  if ( this->scene_types.m_num )
  {
    do
      v3 += CSceneType::pack_size(v1->scene_types.m_data[v2++]);
    while ( v2 < v1->scene_types.m_num );
  }
  return v3;
}

//----- (00502300) --------------------------------------------------------  // acclient.c:303200
void __thiscall CSceneDesc::~CSceneDesc(CSceneDesc *this)
{
  void **v1; // esi@1

  v1 = (void **)this;
  CSceneDesc::Destroy(this);
  operator delete[](*v1);
}

//----- (00502320) --------------------------------------------------------  // acclient.c:303210
void __thiscall CSceneDesc::GetSubDataIDs(CSceneDesc *this, QualifiedDataIDArray *id_array)
{
  unsigned int v2; // eax@1
  CSceneType *v3; // esi@2
  unsigned int v4; // edi@2
  IDClass<_tagDataID,32,0> v5; // eax@3
  QualifiedDataID *v6; // eax@4
  unsigned int iq; // [sp+10h] [bp-10h]@1
  CSceneDesc *v8; // [sp+14h] [bp-Ch]@1
  QualifiedDataID v9; // [sp+18h] [bp-8h]@4

  v2 = 0;
  v8 = this;
  iq = 0;
  if ( this->scene_types.m_num )
  {
    do
    {
      v3 = this->scene_types.m_data[v2];
      v4 = 0;
      if ( v3->scenes.m_num )
      {
        do
        {
          v5.id = v3->scenes.m_data[v4].id;
          if ( v5.id != stru_841540.id )
          {
            QualifiedDataID::QualifiedDataID(&v9, v5, 0);
            QualifiedDataIDArray::AddQDID(id_array, v6, 8u);
            this = v8;
          }
          ++v4;
        }
        while ( v4 < v3->scenes.m_num );
        v2 = iq;
      }
      ++v2;
      iq = v2;
    }
    while ( v2 < this->scene_types.m_num );
  }
}

//----- (005023A0) --------------------------------------------------------  // acclient.c:303254
int __thiscall CSceneDesc::Add(CSceneDesc *this, CSceneType *scene)
{
  CSceneDesc *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@3
  int result; // eax@5

  v2 = this;
  v3 = this->scene_types.m_size;
  if ( this->scene_types.m_num < v3
    || (!v3 ? (v4 = 8) : (v4 = 2 * v3),
        (result = AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)this, v4)) != 0) )
  {
    v2->scene_types.m_data[v2->scene_types.m_num++] = scene;
    result = 1;
  }
  return result;
}

//----- (006F9740) --------------------------------------------------------  // acclient.c:782181
int _E73_84()
{
  return atexit(_E74_63);
}

//----- (006F9750) --------------------------------------------------------  // acclient.c:782187
int _E76_49()
{
  return atexit(_E77_77);
}

//----- (006F9760) --------------------------------------------------------  // acclient.c:782193
int _E79_42()
{
  return atexit(_E80_41);
}

//----- (006F9770) --------------------------------------------------------  // acclient.c:782199
void _E98_4()
{
  LODWORD(dword_841544) = 1053364187;
}

//----- (006F9780) --------------------------------------------------------  // acclient.c:782205
void sub_6F9780()
{
  flt_841548 = 1000.0 + 1.0;
}

//----- (006F97A0) --------------------------------------------------------  // acclient.c:782211
void _E102_12()
{
  flt_84154C = 24.0 * 8.0;
}

//----- (006F97C0) --------------------------------------------------------  // acclient.c:782217
void _E104_6()
{
  flt_841550 = 24.0 * 0.5;
}

//----- (006F97E0) --------------------------------------------------------  // acclient.c:782223
int _E106_87()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_8, "Sound.SoundDisabled");
  return atexit(_E107_82);
}

//----- (006F9800) --------------------------------------------------------  // acclient.c:782230
int _E109_52()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_8, "Sound.SoundVolume");
  return atexit(sub_7650D0);
}

//----- (006F9820) --------------------------------------------------------  // acclient.c:782237
int _E112_79()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_8, "Sound.AmbientSoundDisabled");
  return atexit(_E113_57);
}

//----- (006F9840) --------------------------------------------------------  // acclient.c:782244
int _E115_58()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_8, "Sound.AmbientSoundVolume");
  return atexit(_E116_50);
}

//----- (006F9860) --------------------------------------------------------  // acclient.c:782251
int _E118_59()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_8, "Sound.InterfaceSoundDisabled");
  return atexit(_E119_79);
}

//----- (006F9880) --------------------------------------------------------  // acclient.c:782258
int _E121_53()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_8, "Sound.InterfaceSoundVolume");
  return atexit(_E122_82);
}

//----- (006F98A0) --------------------------------------------------------  // acclient.c:782265
int _E124_55()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_8, "Sound.SoundFeatures");
  return atexit(_E125_54);
}

//----- (006F98C0) --------------------------------------------------------  // acclient.c:782272
int _E127_44()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_8, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E128_53);
}

//----- (006F98E0) --------------------------------------------------------  // acclient.c:782279
int _E130_42()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_8, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_841578, "Mono");
  return atexit(_E131_45);
}

//----- (006F9910) --------------------------------------------------------  // acclient.c:782287
void _E133_32()
{
  VOL_MIN_DIST_SQ_5 = 5.0 * 5.0;
}

//----- (006F9930) --------------------------------------------------------  // acclient.c:782293
void _E135_24()
{
  INV_LOG_OF_2_5 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (006F9950) --------------------------------------------------------  // acclient.c:782299
int sub_6F9950()
{
  return atexit(nullsub_1047);
}

//----- (007650A0) --------------------------------------------------------  // acclient.c:891592
void __cdecl _E107_82()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007650D0) --------------------------------------------------------  // acclient.c:891605
void __cdecl sub_7650D0()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765100) --------------------------------------------------------  // acclient.c:891618
void __cdecl _E113_57()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765130) --------------------------------------------------------  // acclient.c:891631
void __cdecl _E116_50()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765160) --------------------------------------------------------  // acclient.c:891644
void __cdecl _E119_79()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765190) --------------------------------------------------------  // acclient.c:891657
void __cdecl _E122_82()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007651C0) --------------------------------------------------------  // acclient.c:891670
void __cdecl _E125_54()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007651F0) --------------------------------------------------------  // acclient.c:891683
void __cdecl _E128_53()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765220) --------------------------------------------------------  // acclient.c:891696
void __cdecl _E131_45()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_5;
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

