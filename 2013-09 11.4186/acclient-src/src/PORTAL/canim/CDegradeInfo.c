/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CDegradeInfo
   Object     : PORTAL\canim\CDegradeInfo.obj
   Functions  : 78
   Addresses  : 0051E290 - 007680C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051E290) --------------------------------------------------------  // acclient.c:332169
void __thiscall GfxObjDegradeInfo::GfxObjDegradeInfo(GfxObjDegradeInfo *this)
{
  GfxObjDegradeInfo *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_844348);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->num_degrades = 0;
  v1->degrades = 0;
  v1->vfptr = (InterfaceVtbl *)&GfxObjDegradeInfo::vftable;
  v1->vfptr = (PackObjVtbl *)&GfxObjDegradeInfo::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C72EC: using guessed type void *GfxObjDegradeInfo::vftable;
// 7C7300: using guessed type __int32 (__stdcall *GfxObjDegradeInfo::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0051E2C0) --------------------------------------------------------  // acclient.c:332186
signed int GfxObjDegradeInfo::GetDBOType()
{
  return 26;
}

//----- (0051E2D0) --------------------------------------------------------  // acclient.c:332192
double __thiscall GfxObjDegradeInfo::get_max_degrade_distance(GfxObjDegradeInfo *this)
{
  unsigned int v1; // eax@1
  double result; // st7@2

  v1 = this->num_degrades;
  if ( v1 <= 2 )
    result = this->degrades->max_dist;
  else
    result = *((float *)&this->degrades[v1 - 1] - 1);
  return result;
}

//----- (0051E2F0) --------------------------------------------------------  // acclient.c:332206
GfxObjDegradeInfo *__thiscall GfxObjDegradeInfo::vector_deleting_destructor(GfxObjDegradeInfo *this, unsigned int a2)
{
  return GfxObjDegradeInfo::scalar_deleting_destructor((GfxObjDegradeInfo *)((char *)this - 48), a2);
}

//----- (0051E310) --------------------------------------------------------  // acclient.c:332212
void __thiscall GfxObjDegradeInfo::Destroy(GfxObjDegradeInfo *this)
{
  GfxObjDegradeInfo *v1; // esi@1
  GfxObjInfo *v2; // eax@1

  v1 = this;
  v2 = this->degrades;
  if ( v2 )
  {
    operator delete[](&v2[-1].max_dist);
    v1->degrades = 0;
  }
  v1->num_degrades = 0;
}

//----- (0051E340) --------------------------------------------------------  // acclient.c:332228
int __thiscall GfxObjDegradeInfo::Pack(GfxObjDegradeInfo *this, void **addr, unsigned int size)
{
  int v3; // edx@1
  int result; // eax@1
  char *v5; // edi@4
  unsigned int v6; // ebp@4
  int v7; // ebx@5
  int v8; // esi@6
  char *v9; // eax@7
  char *v10; // edi@7
  char *v11; // eax@7
  char *v12; // edi@7
  char *v13; // eax@7
  int v14; // [sp+0h] [bp-4h]@1

  v3 = *(_DWORD *)&this->m_bLoaded;
  result = 4;
  v14 = 4;
  if ( v3 )
  {
    result = 20 * v3 + 4;
    v14 = 20 * v3 + 4;
  }
  if ( size >= result )
  {
    *(_DWORD *)*addr = *(_DWORD *)&this->m_bLoaded;
    v5 = (char *)*addr + 4;
    *addr = v5;
    v6 = 0;
    if ( *(_DWORD *)&this->m_bLoaded )
    {
      v7 = 0;
      do
      {
        v8 = v7 + *((_DWORD *)&this->m_bLoaded + 1);
        if ( size >= 0x14 )
        {
          *(_DWORD *)v5 = *(_DWORD *)v8;
          v9 = (char *)*addr + 4;
          *addr = v9;
          *(_DWORD *)v9 = *(_DWORD *)(v8 + 4);
          v10 = (char *)*addr + 4;
          *addr = v10;
          *(float *)v10 = *(float *)(v8 + 8);
          v11 = (char *)*addr + 4;
          *addr = v11;
          *(float *)v11 = *(float *)(v8 + 12);
          v12 = (char *)*addr + 4;
          *addr = v12;
          *(float *)v12 = *(float *)(v8 + 16);
          v13 = (char *)*addr + 4;
          *addr = v13;
          v5 = v13;
        }
        ++v6;
        v7 += 20;
      }
      while ( v6 < *(_DWORD *)&this->m_bLoaded );
      result = v14;
    }
  }
  return result;
}

//----- (0051E400) --------------------------------------------------------  // acclient.c:332293
int __thiscall GfxObjDegradeInfo::UnPack(GfxObjDegradeInfo *this, void **addr, unsigned int size)
{
  GfxObjDegradeInfo *v3; // edi@1
  int v4; // ebx@1
  void *v5; // eax@1
  int v6; // eax@2
  unsigned int v7; // edx@4
  int v8; // ebx@5
  int v9; // ebp@6
  int v10; // eax@6
  int v11; // eax@6
  char *v12; // ecx@6
  char *v13; // ebp@6
  char *v14; // ecx@6

  v3 = this;
  (*(void (__thiscall **)(long double *))(LODWORD(this[-1].m_timeStamp) + 60))(&this[-1].m_timeStamp);
  *(_DWORD *)&v3->m_bLoaded = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  v4 = *(_DWORD *)&v3->m_bLoaded;
  v5 = operator new[](20 * v4 + 4);
  if ( v5 )
  {
    *(_DWORD *)v5 = v4;
    v6 = (int)((char *)v5 + 4);
  }
  else
  {
    v6 = 0;
  }
  *((_DWORD *)&v3->m_bLoaded + 1) = v6;
  v7 = 0;
  if ( *(_DWORD *)&v3->m_bLoaded )
  {
    v8 = 0;
    do
    {
      v9 = *(_DWORD *)*addr;
      v10 = *((_DWORD *)&v3->m_bLoaded + 1);
      *addr = (char *)*addr + 4;
      *(_DWORD *)(v10 + v8) = v9;
      v11 = v8 + v10;
      *(_DWORD *)(v11 + 4) = *(_DWORD *)*addr;
      v12 = (char *)*addr + 4;
      *addr = v12;
      *(_DWORD *)(v11 + 8) = *(_DWORD *)v12;
      v13 = (char *)*addr + 4;
      *addr = v13;
      *(_DWORD *)(v11 + 12) = *(_DWORD *)v13;
      v14 = (char *)*addr + 4;
      *addr = v14;
      *(_DWORD *)(v11 + 16) = *(_DWORD *)v14;
      *addr = (char *)*addr + 4;
      ++v7;
      v8 += 20;
    }
    while ( v7 < *(_DWORD *)&v3->m_bLoaded );
  }
  return 1;
}

//----- (0051E4B0) --------------------------------------------------------  // acclient.c:332355
void __thiscall GfxObjDegradeInfo::get_degrade(GfxObjDegradeInfo *this, float distance, unsigned int *deg_index, int *deg_mode)
{
  unsigned int v4; // eax@4
  long double v5; // st7@7
  float *v6; // eax@7
  unsigned int v7; // edx@12
  unsigned int v8; // esi@12
  char *v9; // edi@14
  char *v10; // edi@20
  float scale; // [sp+0h] [bp-4h]@1

  scale = *(float *)&this;
  if ( degrades_disabled )
  {
    *deg_index = 0;
    *deg_mode = this->degrades->degrade_mode;
    return;
  }
  if ( Render::force_level == -1 )
  {
    scale = 0.0;
    v5 = fabs(distance) - Render::s_rDegradeDistance;
    distance = v5;
    v6 = &scale;
    if ( v5 >= 0.0 )
      v6 = &distance;
    distance = *v6;
    if ( Render::auto_update_deg_mul )
      scale = Render::deg_mul;
    else
      scale = Render::s_rUserSuppliedDegradeBias;
    v7 = this->num_degrades;
    v8 = 0;
    if ( scale >= 0.0 )
    {
      if ( v7 )
      {
        v10 = (char *)&this->degrades->max_dist;
        while ( distance >= *((float *)v10 - 1) - (*((float *)v10 - 1) - *(float *)v10) * scale )
        {
          ++v8;
          v10 += 20;
          if ( v8 >= v7 )
            goto LABEL_23;
        }
        goto LABEL_18;
      }
    }
    else if ( v7 )
    {
      v9 = (char *)&this->degrades->ideal_dist;
      while ( (*(float *)v9 - *((float *)v9 - 1)) * scale + *(float *)v9 <= distance )
      {
        ++v8;
        v9 += 20;
        if ( v8 >= v7 )
          goto LABEL_23;
      }
LABEL_18:
      *deg_index = v8;
      *deg_mode = this->degrades[v8].degrade_mode;
      return;
    }
LABEL_23:
    *deg_index = v7 - 1;
    *deg_mode = *((_DWORD *)&this->degrades[this->num_degrades] - 4);
    return;
  }
  v4 = this->num_degrades;
  if ( Render::force_level < (signed int)v4 )
  {
    *deg_index = Render::force_level;
    *deg_mode = this->degrades[Render::force_level].degrade_mode;
  }
  else
  {
    *deg_index = v4 - 1;
    *deg_mode = *((_DWORD *)&this->degrades[this->num_degrades] - 4);
  }
}
// 81EC58: using guessed type float Render::s_rDegradeDistance;
// 81EC68: using guessed type bool Render::auto_update_deg_mul;
// 81EC6C: using guessed type int Render::force_level;
// 8442E4: using guessed type int degrades_disabled;
// 866308: using guessed type float Render::s_rUserSuppliedDegradeBias;
// 86630C: using guessed type float Render::deg_mul;

//----- (0051E630) --------------------------------------------------------  // acclient.c:332443
void __thiscall GfxObjDegradeInfo::GetSubDataIDs(GfxObjDegradeInfo *this, QualifiedDataIDArray *id_array)
{
  GfxObjDegradeInfo *v2; // esi@1
  unsigned int v3; // edi@1
  int v4; // ebx@2
  QualifiedDataID *v5; // eax@3
  QualifiedDataID v6; // [sp+8h] [bp-8h]@3

  v2 = this;
  v3 = 0;
  if ( this->num_degrades )
  {
    v4 = 0;
    do
    {
      QualifiedDataID::QualifiedDataID(&v6, v2->degrades[v4].gfxobj_id, 0);
      QualifiedDataIDArray::AddQDID(id_array, v5, 0);
      ++v3;
      ++v4;
    }
    while ( v3 < v2->num_degrades );
  }
}

//----- (0051E680) --------------------------------------------------------  // acclient.c:332468
GfxObjDegradeInfo *__thiscall GfxObjDegradeInfo::scalar_deleting_destructor(GfxObjDegradeInfo *this, unsigned int a2)
{
  GfxObjDegradeInfo *v2; // esi@1
  GfxObjInfo *v3; // eax@1

  v2 = this;
  v3 = this->degrades;
  this->vfptr = (InterfaceVtbl *)&GfxObjDegradeInfo::vftable;
  this->vfptr = (PackObjVtbl *)&GfxObjDegradeInfo::vftable;
  if ( v3 )
  {
    operator delete[](&v3[-1].max_dist);
    v2->degrades = 0;
  }
  v2->num_degrades = 0;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C72EC: using guessed type void *GfxObjDegradeInfo::vftable;
// 7C7300: using guessed type __int32 (__stdcall *GfxObjDegradeInfo::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006FCE60) --------------------------------------------------------  // acclient.c:785241
void _E73_89()
{
  PixelFormatDesc::PixelFormatDesc(&stru_844300, PFID_A8R8G8B8);
}

//----- (006FCE70) --------------------------------------------------------  // acclient.c:785247
void sub_6FCE70()
{
  LODWORD(dword_844338) = 1053364187;
}

//----- (006FCE80) --------------------------------------------------------  // acclient.c:785253
void sub_6FCE80()
{
  flt_84433C = 1000.0 + 1.0;
}

//----- (006FCEA0) --------------------------------------------------------  // acclient.c:785259
void sub_6FCEA0()
{
  flt_844340 = 24.0 * 8.0;
}

//----- (006FCEC0) --------------------------------------------------------  // acclient.c:785265
void sub_6FCEC0()
{
  flt_844344 = 24.0 * 0.5;
}

//----- (006FCEE0) --------------------------------------------------------  // acclient.c:785271
int _E99_21()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_24, "Render.TextureFiltering");
  return atexit(sub_767AC0);
}

//----- (006FCF00) --------------------------------------------------------  // acclient.c:785278
int _E102_16()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_24, "Render.LandscapeDetailTextures");
  return atexit(sub_767AF0);
}

//----- (006FCF20) --------------------------------------------------------  // acclient.c:785285
int _E105_24()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_24, "Render.BuildingDetailTextures");
  return atexit(sub_767B20);
}

//----- (006FCF40) --------------------------------------------------------  // acclient.c:785292
int _E108_70()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_24, "Render.FieldOfView");
  return atexit(sub_767B50);
}

//----- (006FCF60) --------------------------------------------------------  // acclient.c:785299
int _E111_38()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_24, "Render.LandscapeTextureDetail");
  return atexit(sub_767B80);
}

//----- (006FCF80) --------------------------------------------------------  // acclient.c:785306
int _E114_45()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_24, "Render.EnvironmentTextureDetail");
  return atexit(sub_767BB0);
}

//----- (006FCFA0) --------------------------------------------------------  // acclient.c:785313
int _E117_56()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_24, "Render.SceneryDrawDistance");
  return atexit(sub_767BE0);
}

//----- (006FCFC0) --------------------------------------------------------  // acclient.c:785320
int _E120_52()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_24, "Render.LandscapeDrawDistance");
  return atexit(sub_767C10);
}

//----- (006FCFE0) --------------------------------------------------------  // acclient.c:785327
int _E123_29()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_24, "Render.ScreenBrightness");
  return atexit(sub_767C40);
}

//----- (006FD000) --------------------------------------------------------  // acclient.c:785334
int _E126_35()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_24, "Render.AspectRatio");
  return atexit(sub_767C70);
}

//----- (006FD020) --------------------------------------------------------  // acclient.c:785341
int _E129_27()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_24, "Render.DisplayAdapter");
  return atexit(_E130_95);
}

//----- (006FD040) --------------------------------------------------------  // acclient.c:785348
int _E132_30()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_24, "Render.MaxHardwareClass");
  return atexit(_E133_89);
}

//----- (006FD060) --------------------------------------------------------  // acclient.c:785355
int _E135_33()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_24, "Render.AutomaticDegrades");
  return atexit(_E136_72);
}

//----- (006FD080) --------------------------------------------------------  // acclient.c:785362
int _E138_25()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_24, "Render.GraphicsPerformance");
  return atexit(_E139_72);
}

//----- (006FD0A0) --------------------------------------------------------  // acclient.c:785369
int _E141_25()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_24, "Render.DegradeDistance");
  return atexit(_E142_67);
}

//----- (006FD0C0) --------------------------------------------------------  // acclient.c:785376
int _E144_24()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_24, "Render.MultiPassAlpha");
  return atexit(_E145_69);
}

//----- (006FD0E0) --------------------------------------------------------  // acclient.c:785383
int _E147_21()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_24, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_844390, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_844394, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_844398, "Anisotropic");
  return atexit(_E148_66);
}

//----- (006FD130) --------------------------------------------------------  // acclient.c:785393
int _E150_23()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_24, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8443A0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8443A4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8443A8, "High");
  PStringBase<char>::PStringBase<char>(&stru_8443AC, "VeryHigh");
  return atexit(_E151_64);
}

//----- (006FD190) --------------------------------------------------------  // acclient.c:785404
int _E153_21()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_24, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8443B4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8443B8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8443BC, "High");
  PStringBase<char>::PStringBase<char>(&stru_8443C0, "VeryHigh");
  return atexit(_E154_65);
}

//----- (006FD1F0) --------------------------------------------------------  // acclient.c:785415
int _E156_23()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_24, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8443C8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8443CC, "High");
  return atexit(_E157_61);
}

//----- (006FD230) --------------------------------------------------------  // acclient.c:785424
int _E159_21()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_24, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8443D4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8443D8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8443DC, "High");
  PStringBase<char>::PStringBase<char>(&stru_8443E0, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8443E4, "Extreme");
  return atexit(_E160_64);
}

//----- (006FD2A0) --------------------------------------------------------  // acclient.c:785436
int _E162_23()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_24, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8443EC, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8443F0, "Wide");
  return atexit(_E163_57);
}

//----- (006FD2E0) --------------------------------------------------------  // acclient.c:785445
int _E165_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_48, "None");
  return atexit(_E166_59);
}

//----- (006FD300) --------------------------------------------------------  // acclient.c:785452
int _E168_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_48, "Speed");
  return atexit(_E169_58);
}

//----- (006FD320) --------------------------------------------------------  // acclient.c:785459
int _E171_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_48, "Noise");
  return atexit(_E172_56);
}

//----- (006FD340) --------------------------------------------------------  // acclient.c:785466
int _E174_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_48, "Sine");
  return atexit(_E175_53);
}

//----- (006FD360) --------------------------------------------------------  // acclient.c:785473
int _E177_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_48, "Square");
  return atexit(_E178_53);
}

//----- (006FD380) --------------------------------------------------------  // acclient.c:785480
int _E180_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_48, "Bounce");
  return atexit(_E181_53);
}

//----- (006FD3A0) --------------------------------------------------------  // acclient.c:785487
int _E183_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_48, "Perlin");
  return atexit(_E184_50);
}

//----- (006FD3C0) --------------------------------------------------------  // acclient.c:785494
int _E186_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_48, "Fractal");
  return atexit(_E187_49);
}

//----- (006FD3E0) --------------------------------------------------------  // acclient.c:785501
int _E189_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_48, "FrameLoop");
  return atexit(_E190_50);
}

//----- (006FD400) --------------------------------------------------------  // acclient.c:785508
int sub_6FD400()
{
  return atexit(nullsub_1137);
}

//----- (00767AC0) --------------------------------------------------------  // acclient.c:894490
void __cdecl sub_767AC0()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767AF0) --------------------------------------------------------  // acclient.c:894503
void __cdecl sub_767AF0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767B20) --------------------------------------------------------  // acclient.c:894516
void __cdecl sub_767B20()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767B50) --------------------------------------------------------  // acclient.c:894529
void __cdecl sub_767B50()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767B80) --------------------------------------------------------  // acclient.c:894542
void __cdecl sub_767B80()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767BB0) --------------------------------------------------------  // acclient.c:894555
void __cdecl sub_767BB0()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767BE0) --------------------------------------------------------  // acclient.c:894568
void __cdecl sub_767BE0()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767C10) --------------------------------------------------------  // acclient.c:894581
void __cdecl sub_767C10()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767C40) --------------------------------------------------------  // acclient.c:894594
void __cdecl sub_767C40()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767C70) --------------------------------------------------------  // acclient.c:894607
void __cdecl sub_767C70()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767CA0) --------------------------------------------------------  // acclient.c:894620
void __cdecl _E130_95()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767CD0) --------------------------------------------------------  // acclient.c:894633
void __cdecl _E133_89()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767D00) --------------------------------------------------------  // acclient.c:894646
void __cdecl _E136_72()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767D30) --------------------------------------------------------  // acclient.c:894659
void __cdecl _E139_72()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767D60) --------------------------------------------------------  // acclient.c:894672
void __cdecl _E142_67()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767D90) --------------------------------------------------------  // acclient.c:894685
void __cdecl _E145_69()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767DC0) --------------------------------------------------------  // acclient.c:894698
void __cdecl _E148_66()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_24;
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

//----- (00767E00) --------------------------------------------------------  // acclient.c:894723
void __cdecl _E151_64()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_24;
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

//----- (00767E40) --------------------------------------------------------  // acclient.c:894748
void __cdecl _E154_65()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_24;
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

//----- (00767E80) --------------------------------------------------------  // acclient.c:894773
void __cdecl _E157_61()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_24;
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

//----- (00767EC0) --------------------------------------------------------  // acclient.c:894798
void __cdecl _E160_64()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_24;
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

//----- (00767F00) --------------------------------------------------------  // acclient.c:894823
void __cdecl _E163_57()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_48;
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

//----- (00767F40) --------------------------------------------------------  // acclient.c:894848
void __cdecl _E166_59()
{
  char *v0; // esi@1

  v0 = &waveform_None_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767F70) --------------------------------------------------------  // acclient.c:894861
void __cdecl _E169_58()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767FA0) --------------------------------------------------------  // acclient.c:894874
void __cdecl _E172_56()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00767FD0) --------------------------------------------------------  // acclient.c:894887
void __cdecl _E175_53()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768000) --------------------------------------------------------  // acclient.c:894900
void __cdecl _E178_53()
{
  char *v0; // esi@1

  v0 = &waveform_Square_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768030) --------------------------------------------------------  // acclient.c:894913
void __cdecl _E181_53()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768060) --------------------------------------------------------  // acclient.c:894926
void __cdecl _E184_50()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768090) --------------------------------------------------------  // acclient.c:894939
void __cdecl _E187_49()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007680C0) --------------------------------------------------------  // acclient.c:894952
void __cdecl _E190_50()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

