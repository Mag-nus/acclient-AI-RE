/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderIndexBufferD3D
   Object     : ENGINE\render_base\RenderIndexBufferD3D.obj
   Functions  : 74
   Addresses  : 00697F40 - 00786000 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00697F40) --------------------------------------------------------  // acclient.c:687807
void __thiscall RenderIndexBufferD3D::Begin(RenderIndexBufferD3D *this)
{
  this->m_pIndexStream = 0;
}

//----- (00697F50) --------------------------------------------------------  // acclient.c:687813
void __thiscall RenderIndexBufferD3D::End(RenderIndexBufferD3D *this)
{
  RenderIndexBufferD3D *v1; // esi@1
  RenderIndexStreamD3D *v2; // ecx@2

  v1 = this;
  if ( this->staticData )
  {
    v2 = this->m_pIndexStream;
    if ( v2 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  }
  v1->m_pIndexStream = 0;
}

//----- (00697F70) --------------------------------------------------------  // acclient.c:687829
char __thiscall RenderIndexBufferD3D::Startup(RenderIndexBufferD3D *this, const unsigned int _nNumIndices, const char _indexSize, const bool _staticData, const bool _OnlyWriteOnce, const bool _bUseIndexCaching)
{
  RenderIndexBufferD3D *v6; // esi@1
  RenderIndexStreamD3D *v7; // eax@3
  RenderIndexStreamD3D *v8; // eax@4
  RenderIndexStreamD3D *v9; // ecx@8
  RenderIndexStreamD3D *v11; // eax@12

  v6 = this;
  if ( !(unsigned __int8)RenderIndexBuffer::Startup(
                           (RenderIndexBuffer *)&this->vfptr,
                           _nNumIndices,
                           _indexSize,
                           _staticData,
                           _OnlyWriteOnce,
                           _bUseIndexCaching) )
    return 0;
  if ( !v6->staticData )
  {
    v11 = D3DPolyRender::ReferenceDynamicIndexStream(Render::m_pRenderer);
    v6->m_pIndexStream = v11;
    if ( v11 )
      return 1;
    return 0;
  }
  v7 = (RenderIndexStreamD3D *)operator new(0x48u);
  if ( v7 )
    RenderIndexStreamD3D::RenderIndexStreamD3D(v7);
  else
    v8 = 0;
  v6->m_pIndexStream = v8;
  if ( !v8 )
    return 0;
  if ( !RenderIndexStreamD3D::Init(v8, _nNumIndices, v6->m_OnlyWriteOnce != 0 ? 4 : 0) )
  {
    v9 = v6->m_pIndexStream;
    if ( v9 )
      ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
    v6->m_pIndexStream = 0;
    return 0;
  }
  return 1;
}

//----- (00698010) --------------------------------------------------------  // acclient.c:687874
void __thiscall RenderIndexBufferD3D::Shutdown(RenderIndexBufferD3D *this)
{
  RenderIndexBufferD3D *v1; // esi@1
  RenderIndexStreamD3D *v2; // ecx@2

  v1 = this;
  if ( this->staticData )
  {
    v2 = this->m_pIndexStream;
    if ( v2 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  }
  v1->m_pIndexStream = 0;
  RenderIndexBuffer::Shutdown((RenderIndexBuffer *)&v1->vfptr);
  v1->m_pIndexStream = 0;
}

//----- (00698040) --------------------------------------------------------  // acclient.c:687892
char __thiscall RenderIndexBufferD3D::UpdateIndexBuffer(RenderIndexBufferD3D *this)
{
  RenderIndexBufferD3D *v1; // esi@1
  char result; // al@1
  unsigned int v3; // edi@5
  const void *v4; // eax@7
  void *v5; // ebp@7
  unsigned int v6; // ebx@9
  char *v7; // ecx@9
  unsigned int v8; // edx@9
  void *v9; // eax@9
  RenderIndexStreamD3D *v10; // ecx@16
  const unsigned int v11; // ST00_4@16
  unsigned int FirstRemoteIndex; // [sp+0h] [bp-4h]@1

  FirstRemoteIndex = (unsigned int)this;
  v1 = this;
  result = 1;
  if ( this->m_pIndexStream->m_bIsLost )
    this->needRefresh = 1;
  if ( this->needRefresh )
  {
    if ( this->m_bUseIndexCaching )
    {
      RenderIndexBuffer::RecalculateMinMaxIndices((RenderIndexBuffer *)&this->vfptr);
      v3 = v1->m_nMinVertexIndex;
    }
    else
    {
      v3 = 0;
    }
    v4 = v1->indices;
    v5 = 0;
    if ( v3 )
    {
      v5 = operator new[](v1->m_nNumIndices * v1->indexSize);
      if ( !v5 )
        return 0;
      v6 = v1->m_nNumIndices;
      v7 = v1->indices;
      v8 = 0;
      v9 = v5;
      if ( v1->indexSize == 2 )
      {
        if ( v6 )
        {
          do
          {
            *(_WORD *)v9 = *(_WORD *)v7 - v3;
            v9 = (char *)v9 + 2;
            v7 += 2;
            ++v8;
          }
          while ( v8 < v1->m_nNumIndices );
        }
      }
      else if ( v6 )
      {
        do
        {
          *(_DWORD *)v9 = *(_DWORD *)v7 - v3;
          v9 = (char *)v9 + 4;
          v7 += 4;
          ++v8;
        }
        while ( v8 < v1->m_nNumIndices );
      }
      v4 = v5;
    }
    v10 = v1->m_pIndexStream;
    v11 = v1->m_nNumIndices;
    FirstRemoteIndex = 0;
    RenderIndexStreamD3D::FillData(v10, v11, v4, &FirstRemoteIndex);
    operator delete[](v5);
    v1->needRefresh = 0;
    result = 1;
  }
  return result;
}

//----- (00698120) --------------------------------------------------------  // acclient.c:687973
RenderIndexBuffer *__thiscall RenderIndexBufferD3D::Duplicate(RenderIndexBufferD3D *this)
{
  RenderIndexBuffer *v1; // edi@1
  RenderIndexBuffer *v2; // eax@1
  RenderIndexBuffer *v3; // esi@1
  RenderIndexBuffer *result; // eax@7

  v1 = (RenderIndexBuffer *)this;
  v2 = (RenderIndexBuffer *)operator new(0x2Cu);
  v3 = v2;
  if ( v2 )
  {
    v2->vfptr = (RenderIndexBufferVtbl *)&RenderIndexBuffer::vftable;
    RenderIndexBuffer::Begin(v2);
    v3->vfptr = (RenderIndexBufferVtbl *)&RenderIndexBufferD3D::vftable;
    v3[1].vfptr = 0;
  }
  else
  {
    v3 = 0;
  }
  if ( RenderIndexBuffer::SetRenderIndexBuffer(v3, v1) )
  {
    result = v3;
  }
  else
  {
    if ( v3 )
      v3->vfptr->__vecDelDtor(v3, 1u);
    result = 0;
  }
  return result;
}
// 79B26C: using guessed type int (__thiscall *RenderIndexBuffer::vftable)(void *, char);
// 7E57A0: using guessed type int (__thiscall *RenderIndexBufferD3D::vftable)(void *, char);

//----- (0071A320) --------------------------------------------------------  // acclient.c:812757
void sub_71A320()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F8B78, PFID_A8R8G8B8);
}

//----- (0071A330) --------------------------------------------------------  // acclient.c:812763
void sub_71A330()
{
  LODWORD(dword_8F8BB0) = 1053364187;
}

//----- (0071A340) --------------------------------------------------------  // acclient.c:812769
void sub_71A340()
{
  flt_8F8BB4 = 1000.0 + 1.0;
}

//----- (0071A360) --------------------------------------------------------  // acclient.c:812775
void sub_71A360()
{
  flt_8F8BB8 = 24.0 * 8.0;
}

//----- (0071A380) --------------------------------------------------------  // acclient.c:812781
void sub_71A380()
{
  flt_8F8BBC = 24.0 * 0.5;
}

//----- (0071A3A0) --------------------------------------------------------  // acclient.c:812787
int _E99_46()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_46, "Render.TextureFiltering");
  return atexit(sub_785A00);
}

//----- (0071A3C0) --------------------------------------------------------  // acclient.c:812794
int _E102_39()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_46, "Render.LandscapeDetailTextures");
  return atexit(sub_785A30);
}

//----- (0071A3E0) --------------------------------------------------------  // acclient.c:812801
int _E105_60()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_46, "Render.BuildingDetailTextures");
  return atexit(sub_785A60);
}

//----- (0071A400) --------------------------------------------------------  // acclient.c:812808
int sub_71A400()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_46, "Render.FieldOfView");
  return atexit(sub_785A90);
}

//----- (0071A420) --------------------------------------------------------  // acclient.c:812815
int _E111_64()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_46, "Render.LandscapeTextureDetail");
  return atexit(sub_785AC0);
}

//----- (0071A440) --------------------------------------------------------  // acclient.c:812822
int _E114_70()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_46, "Render.EnvironmentTextureDetail");
  return atexit(sub_785AF0);
}

//----- (0071A460) --------------------------------------------------------  // acclient.c:812829
int _E117_88()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_46, "Render.SceneryDrawDistance");
  return atexit(sub_785B20);
}

//----- (0071A480) --------------------------------------------------------  // acclient.c:812836
int _E120_81()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_46, "Render.LandscapeDrawDistance");
  return atexit(sub_785B50);
}

//----- (0071A4A0) --------------------------------------------------------  // acclient.c:812843
int _E123_52()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_46, "Render.ScreenBrightness");
  return atexit(sub_785B80);
}

//----- (0071A4C0) --------------------------------------------------------  // acclient.c:812850
int _E126_59()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_46, "Render.AspectRatio");
  return atexit(sub_785BB0);
}

//----- (0071A4E0) --------------------------------------------------------  // acclient.c:812857
int _E129_53()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_46, "Render.DisplayAdapter");
  return atexit(sub_785BE0);
}

//----- (0071A500) --------------------------------------------------------  // acclient.c:812864
int _E132_53()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_46, "Render.MaxHardwareClass");
  return atexit(sub_785C10);
}

//----- (0071A520) --------------------------------------------------------  // acclient.c:812871
int _E135_61()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_46, "Render.AutomaticDegrades");
  return atexit(_E136_95);
}

//----- (0071A540) --------------------------------------------------------  // acclient.c:812878
int _E138_47()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_46, "Render.GraphicsPerformance");
  return atexit(_E139_95);
}

//----- (0071A560) --------------------------------------------------------  // acclient.c:812885
int _E141_49()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_46, "Render.DegradeDistance");
  return atexit(_E142_89);
}

//----- (0071A580) --------------------------------------------------------  // acclient.c:812892
int _E144_46()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_46, "Render.MultiPassAlpha");
  return atexit(_E145_91);
}

//----- (0071A5A0) --------------------------------------------------------  // acclient.c:812899
int _E147_45()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_46, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8F8C08, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8F8C0C, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8F8C10, "Anisotropic");
  return atexit(_E148_87);
}

//----- (0071A5F0) --------------------------------------------------------  // acclient.c:812909
int _E150_44()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_46, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F8C18, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8C1C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8C20, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F8C24, "VeryHigh");
  return atexit(_E151_85);
}

//----- (0071A650) --------------------------------------------------------  // acclient.c:812920
int _E153_42()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_46, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F8C2C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8C30, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8C34, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F8C38, "VeryHigh");
  return atexit(_E154_86);
}

//----- (0071A6B0) --------------------------------------------------------  // acclient.c:812931
int _E156_44()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_46, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8C40, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8C44, "High");
  return atexit(_E157_82);
}

//----- (0071A6F0) --------------------------------------------------------  // acclient.c:812940
int _E159_42()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_46, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F8C4C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8C50, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8C54, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F8C58, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8F8C5C, "Extreme");
  return atexit(_E160_85);
}

//----- (0071A760) --------------------------------------------------------  // acclient.c:812952
int _E162_45()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_46, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8F8C64, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8F8C68, "Wide");
  return atexit(_E163_78);
}

//----- (0071A7A0) --------------------------------------------------------  // acclient.c:812961
int _E165_40()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_81, "None");
  return atexit(_E166_80);
}

//----- (0071A7C0) --------------------------------------------------------  // acclient.c:812968
int _E168_41()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_81, "Speed");
  return atexit(_E169_79);
}

//----- (0071A7E0) --------------------------------------------------------  // acclient.c:812975
int _E171_40()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_81, "Noise");
  return atexit(_E172_77);
}

//----- (0071A800) --------------------------------------------------------  // acclient.c:812982
int _E174_42()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_81, "Sine");
  return atexit(_E175_74);
}

//----- (0071A820) --------------------------------------------------------  // acclient.c:812989
int _E177_39()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_81, "Square");
  return atexit(_E178_74);
}

//----- (0071A840) --------------------------------------------------------  // acclient.c:812996
int _E180_39()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_81, "Bounce");
  return atexit(_E181_74);
}

//----- (0071A860) --------------------------------------------------------  // acclient.c:813003
int _E183_38()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_81, "Perlin");
  return atexit(_E184_71);
}

//----- (0071A880) --------------------------------------------------------  // acclient.c:813010
int _E186_38()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_81, "Fractal");
  return atexit(_E187_70);
}

//----- (0071A8A0) --------------------------------------------------------  // acclient.c:813017
int _E189_37()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_81, "FrameLoop");
  return atexit(_E190_71);
}

//----- (0071A8C0) --------------------------------------------------------  // acclient.c:813024
int sub_71A8C0()
{
  return atexit(nullsub_251);
}

//----- (00785A00) --------------------------------------------------------  // acclient.c:924922
void __cdecl sub_785A00()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785A30) --------------------------------------------------------  // acclient.c:924935
void __cdecl sub_785A30()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785A60) --------------------------------------------------------  // acclient.c:924948
void __cdecl sub_785A60()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785A90) --------------------------------------------------------  // acclient.c:924961
void __cdecl sub_785A90()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785AC0) --------------------------------------------------------  // acclient.c:924974
void __cdecl sub_785AC0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785AF0) --------------------------------------------------------  // acclient.c:924987
void __cdecl sub_785AF0()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785B20) --------------------------------------------------------  // acclient.c:925000
void __cdecl sub_785B20()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785B50) --------------------------------------------------------  // acclient.c:925013
void __cdecl sub_785B50()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785B80) --------------------------------------------------------  // acclient.c:925026
void __cdecl sub_785B80()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785BB0) --------------------------------------------------------  // acclient.c:925039
void __cdecl sub_785BB0()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785BE0) --------------------------------------------------------  // acclient.c:925052
void __cdecl sub_785BE0()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785C10) --------------------------------------------------------  // acclient.c:925065
void __cdecl sub_785C10()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785C40) --------------------------------------------------------  // acclient.c:925078
void __cdecl _E136_95()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785C70) --------------------------------------------------------  // acclient.c:925091
void __cdecl _E139_95()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785CA0) --------------------------------------------------------  // acclient.c:925104
void __cdecl _E142_89()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785CD0) --------------------------------------------------------  // acclient.c:925117
void __cdecl _E145_91()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785D00) --------------------------------------------------------  // acclient.c:925130
void __cdecl _E148_87()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_46;
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

//----- (00785D40) --------------------------------------------------------  // acclient.c:925155
void __cdecl _E151_85()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_46;
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

//----- (00785D80) --------------------------------------------------------  // acclient.c:925180
void __cdecl _E154_86()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_46;
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

//----- (00785DC0) --------------------------------------------------------  // acclient.c:925205
void __cdecl _E157_82()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_46;
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

//----- (00785E00) --------------------------------------------------------  // acclient.c:925230
void __cdecl _E160_85()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_46;
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

//----- (00785E40) --------------------------------------------------------  // acclient.c:925255
void __cdecl _E163_78()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_81;
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

//----- (00785E80) --------------------------------------------------------  // acclient.c:925280
void __cdecl _E166_80()
{
  char *v0; // esi@1

  v0 = &waveform_None_81.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_81.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785EB0) --------------------------------------------------------  // acclient.c:925293
void __cdecl _E169_79()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_81.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_81.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785EE0) --------------------------------------------------------  // acclient.c:925306
void __cdecl _E172_77()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_81.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_81.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785F10) --------------------------------------------------------  // acclient.c:925319
void __cdecl _E175_74()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_81.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_81.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785F40) --------------------------------------------------------  // acclient.c:925332
void __cdecl _E178_74()
{
  char *v0; // esi@1

  v0 = &waveform_Square_81.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_81.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785F70) --------------------------------------------------------  // acclient.c:925345
void __cdecl _E181_74()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_81.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_81.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785FA0) --------------------------------------------------------  // acclient.c:925358
void __cdecl _E184_71()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_81.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_81.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785FD0) --------------------------------------------------------  // acclient.c:925371
void __cdecl _E187_70()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_81.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_81.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786000) --------------------------------------------------------  // acclient.c:925384
void __cdecl _E190_71()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_81.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_81.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

