/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIViewportObject
   Object     : ENGINE\render_base\UIViewportObject.obj
   Functions  : 77
   Addresses  : 00694760 - 00784FA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00694760) --------------------------------------------------------  // acclient.c:684331
UIViewportObject *__thiscall UIObject::scalar_deleting_destructor(UIViewportObject *this, unsigned int a2)
{
  UIViewportObject *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&UIObject::vftable;
  if ( (this->m_dirtyRects.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](this->m_dirtyRects.m_data);
  v2->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 800678: using guessed type int (__thiscall *UIObject::vftable)(void *, char);

//----- (00695030) --------------------------------------------------------  // acclient.c:684767
void __thiscall UIViewportObject::Render(UIViewportObject *this)
{
  UIViewportObject *v1; // esi@1
  UIRegion *v2; // eax@1
  unsigned int v3; // edi@3
  unsigned int v4; // ebx@3
  unsigned int v5; // ebp@3
  float OldViewportAspect; // ST34_4@3
  unsigned int nOldHeight; // ST30_4@3
  CreatureMode *v8; // [sp+2Ch] [bp-Ch]@2

  v1 = this;
  v2 = this->m_pOwner;
  if ( v2 )
  {
    v8 = (CreatureMode *)&v2[3].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[22];
    if ( CreatureMode::GetObjectByIndex(
           (CreatureMode *)&v2[3].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[22],
           0) )
    {
      SceneTool::StoreMatrices();
      v3 = RenderDevice::render_device->m_viewportX;
      v4 = RenderDevice::render_device->m_viewportY;
      v5 = RenderDevice::render_device->m_viewportWidth;
      OldViewportAspect = RenderDevice::render_device->m_ViewportAspectRatio;
      nOldHeight = RenderDevice::render_device->m_viewportHeight;
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))RenderDevice::render_device->vfptr->SetViewport)(
        v1->m_nVirtualX,
        v1->m_nVirtualY,
        v1->m_nVirtualWidth,
        v1->m_nVirtualHeight,
        1);
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))RenderDevice::render_device->vfptr->Clear)(
        4,
        &stru_834630,
        1065353216);
      CreatureMode::Render(v8);
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))RenderDevice::render_device->vfptr->SetViewport)(
        v3,
        v4,
        v5,
        nOldHeight,
        0);
      RenderDevice::render_device->m_ViewportAspectRatio = OldViewportAspect;
      SceneTool::RestoreMatrices();
    }
  }
}

//----- (00695100) --------------------------------------------------------  // acclient.c:684817
void __thiscall UIViewportObject::UIViewportObject(UIViewportObject *this)
{
  UIViewportObject *v1; // esi@1

  v1 = this;
  UIObject::UIObject((UIObject *)&this->vfptr);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&UIViewportObject::vftable;
}
// 800808: using guessed type int (__thiscall *UIViewportObject::vftable)(void *, char);

//----- (007193E0) --------------------------------------------------------  // acclient.c:811961
void sub_7193E0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F874C, PFID_A8R8G8B8);
}

//----- (007193F0) --------------------------------------------------------  // acclient.c:811967
void sub_7193F0()
{
  LODWORD(dword_8F8788) = 1053364187;
}

//----- (00719400) --------------------------------------------------------  // acclient.c:811973
void sub_719400()
{
  flt_8F878C = 1000.0 + 1.0;
}

//----- (00719420) --------------------------------------------------------  // acclient.c:811979
void sub_719420()
{
  flt_8F8790 = 24.0 * 8.0;
}

//----- (00719440) --------------------------------------------------------  // acclient.c:811985
void sub_719440()
{
  flt_8F8794 = 24.0 * 0.5;
}

//----- (00719460) --------------------------------------------------------  // acclient.c:811991
void _E99_45()
{
  flt_8F8798 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00719480) --------------------------------------------------------  // acclient.c:811997
void _E101_44()
{
  dbl_8F87A0 = 1.0 / 30.0;
}

//----- (007194A0) --------------------------------------------------------  // acclient.c:812003
void sub_7194A0()
{
  dbl_8F87A8 = 1.0 / 5.0;
}

//----- (007194C0) --------------------------------------------------------  // acclient.c:812009
void _E105_59()
{
  dword_8F87B0 = 1024;
}

//----- (007194D0) --------------------------------------------------------  // acclient.c:812015
void _E107_47()
{
  dword_8F87B4 = 0x7FFF;
}

//----- (007194E0) --------------------------------------------------------  // acclient.c:812021
int _E109_90()
{
  const int result; // eax@1

  result = dword_8F87B0;
  dword_8F87B8 = dword_8F87B0;
  return result;
}

//----- (007194F0) --------------------------------------------------------  // acclient.c:812031
int _E111_62()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_44, "Render.TextureFiltering");
  return atexit(sub_784B60);
}

//----- (00719510) --------------------------------------------------------  // acclient.c:812038
int _E114_68()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_44, "Render.LandscapeDetailTextures");
  return atexit(sub_784B90);
}

//----- (00719530) --------------------------------------------------------  // acclient.c:812045
int _E117_86()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_44, "Render.BuildingDetailTextures");
  return atexit(sub_784BC0);
}

//----- (00719550) --------------------------------------------------------  // acclient.c:812052
int _E120_78()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_44, "Render.FieldOfView");
  return atexit(sub_784BF0);
}

//----- (00719570) --------------------------------------------------------  // acclient.c:812059
int _E123_50()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_44, "Render.LandscapeTextureDetail");
  return atexit(sub_784C20);
}

//----- (00719590) --------------------------------------------------------  // acclient.c:812066
int _E126_56()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_44, "Render.EnvironmentTextureDetail");
  return atexit(sub_784C50);
}

//----- (007195B0) --------------------------------------------------------  // acclient.c:812073
int _E129_51()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_44, "Render.SceneryDrawDistance");
  return atexit(sub_784C80);
}

//----- (007195D0) --------------------------------------------------------  // acclient.c:812080
int _E132_51()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_44, "Render.LandscapeDrawDistance");
  return atexit(sub_784CB0);
}

//----- (007195F0) --------------------------------------------------------  // acclient.c:812087
int _E135_59()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_44, "Render.ScreenBrightness");
  return atexit(_E136_93);
}

//----- (00719610) --------------------------------------------------------  // acclient.c:812094
int _E138_45()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_44, "Render.AspectRatio");
  return atexit(_E139_93);
}

//----- (00719630) --------------------------------------------------------  // acclient.c:812101
int _E141_47()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_44, "Render.DisplayAdapter");
  return atexit(_E142_87);
}

//----- (00719650) --------------------------------------------------------  // acclient.c:812108
int _E144_44()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_44, "Render.MaxHardwareClass");
  return atexit(_E145_89);
}

//----- (00719670) --------------------------------------------------------  // acclient.c:812115
int _E147_43()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_44, "Render.AutomaticDegrades");
  return atexit(_E148_85);
}

//----- (00719690) --------------------------------------------------------  // acclient.c:812122
int _E150_42()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_44, "Render.GraphicsPerformance");
  return atexit(_E151_83);
}

//----- (007196B0) --------------------------------------------------------  // acclient.c:812129
int _E153_40()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_44, "Render.DegradeDistance");
  return atexit(_E154_84);
}

//----- (007196D0) --------------------------------------------------------  // acclient.c:812136
int _E156_42()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_44, "Render.MultiPassAlpha");
  return atexit(_E157_80);
}

//----- (007196F0) --------------------------------------------------------  // acclient.c:812143
int _E159_40()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_44, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8F8800, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8F8804, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8F8808, "Anisotropic");
  return atexit(_E160_83);
}

//----- (00719740) --------------------------------------------------------  // acclient.c:812153
int _E162_43()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_44, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F8810, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8814, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8818, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F881C, "VeryHigh");
  return atexit(_E163_76);
}

//----- (007197A0) --------------------------------------------------------  // acclient.c:812164
int _E165_38()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_44, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F8824, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8828, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F882C, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F8830, "VeryHigh");
  return atexit(_E166_78);
}

//----- (00719800) --------------------------------------------------------  // acclient.c:812175
int _E168_39()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_44, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8838, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F883C, "High");
  return atexit(_E169_77);
}

//----- (00719840) --------------------------------------------------------  // acclient.c:812184
int _E171_38()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_44, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F8844, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8848, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F884C, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F8850, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8F8854, "Extreme");
  return atexit(_E172_75);
}

//----- (007198B0) --------------------------------------------------------  // acclient.c:812196
int _E174_40()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_44, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8F885C, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8F8860, "Wide");
  return atexit(_E175_72);
}

//----- (007198F0) --------------------------------------------------------  // acclient.c:812205
int _E177_37()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_77, "None");
  return atexit(_E178_72);
}

//----- (00719910) --------------------------------------------------------  // acclient.c:812212
int _E180_37()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_77, "Speed");
  return atexit(_E181_72);
}

//----- (00719930) --------------------------------------------------------  // acclient.c:812219
int _E183_36()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_77, "Noise");
  return atexit(_E184_69);
}

//----- (00719950) --------------------------------------------------------  // acclient.c:812226
int _E186_36()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_77, "Sine");
  return atexit(_E187_68);
}

//----- (00719970) --------------------------------------------------------  // acclient.c:812233
int _E189_35()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_77, "Square");
  return atexit(_E190_69);
}

//----- (00719990) --------------------------------------------------------  // acclient.c:812240
int _E192_29()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_77, "Bounce");
  return atexit(_E193_55);
}

//----- (007199B0) --------------------------------------------------------  // acclient.c:812247
int _E195_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_77, "Perlin");
  return atexit(_E196_62);
}

//----- (007199D0) --------------------------------------------------------  // acclient.c:812254
int _E198_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_77, "Fractal");
  return atexit(_E199_54);
}

//----- (007199F0) --------------------------------------------------------  // acclient.c:812261
int _E201_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_77, "FrameLoop");
  return atexit(_E202_54);
}

//----- (00719A10) --------------------------------------------------------  // acclient.c:812268
int sub_719A10()
{
  return atexit(nullsub_292);
}

//----- (007849B0) --------------------------------------------------------  // acclient.c:923731
void __cdecl _E178_72()
{
  char *v0; // esi@1

  v0 = &waveform_None_77.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_77.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007849E0) --------------------------------------------------------  // acclient.c:923744
void __cdecl _E181_72()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_77.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_77.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784A10) --------------------------------------------------------  // acclient.c:923757
void __cdecl _E184_69()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_77.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_77.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784A40) --------------------------------------------------------  // acclient.c:923770
void __cdecl _E187_68()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_77.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_77.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784A70) --------------------------------------------------------  // acclient.c:923783
void __cdecl _E190_69()
{
  char *v0; // esi@1

  v0 = &waveform_Square_77.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_77.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784AA0) --------------------------------------------------------  // acclient.c:923796
void __cdecl _E193_55()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_77.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_77.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784AD0) --------------------------------------------------------  // acclient.c:923809
void __cdecl _E196_62()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_77.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_77.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784B00) --------------------------------------------------------  // acclient.c:923822
void __cdecl _E199_54()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_77.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_77.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784B30) --------------------------------------------------------  // acclient.c:923835
void __cdecl _E202_54()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_77.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_77.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784B60) --------------------------------------------------------  // acclient.c:923848
void __cdecl sub_784B60()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784B90) --------------------------------------------------------  // acclient.c:923861
void __cdecl sub_784B90()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784BC0) --------------------------------------------------------  // acclient.c:923874
void __cdecl sub_784BC0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784BF0) --------------------------------------------------------  // acclient.c:923887
void __cdecl sub_784BF0()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784C20) --------------------------------------------------------  // acclient.c:923900
void __cdecl sub_784C20()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784C50) --------------------------------------------------------  // acclient.c:923913
void __cdecl sub_784C50()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784C80) --------------------------------------------------------  // acclient.c:923926
void __cdecl sub_784C80()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784CB0) --------------------------------------------------------  // acclient.c:923939
void __cdecl sub_784CB0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784CE0) --------------------------------------------------------  // acclient.c:923952
void __cdecl _E136_93()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784D10) --------------------------------------------------------  // acclient.c:923965
void __cdecl _E139_93()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784D40) --------------------------------------------------------  // acclient.c:923978
void __cdecl _E142_87()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784D70) --------------------------------------------------------  // acclient.c:923991
void __cdecl _E145_89()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784DA0) --------------------------------------------------------  // acclient.c:924004
void __cdecl _E148_85()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784DD0) --------------------------------------------------------  // acclient.c:924017
void __cdecl _E151_83()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784E00) --------------------------------------------------------  // acclient.c:924030
void __cdecl _E154_84()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784E30) --------------------------------------------------------  // acclient.c:924043
void __cdecl _E157_80()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784E60) --------------------------------------------------------  // acclient.c:924056
void __cdecl _E160_83()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_44;
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

//----- (00784EA0) --------------------------------------------------------  // acclient.c:924081
void __cdecl _E163_76()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_44;
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

//----- (00784EE0) --------------------------------------------------------  // acclient.c:924106
void __cdecl _E166_78()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_44;
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

//----- (00784F20) --------------------------------------------------------  // acclient.c:924131
void __cdecl _E169_77()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_44;
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

//----- (00784F60) --------------------------------------------------------  // acclient.c:924156
void __cdecl _E172_75()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_44;
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

//----- (00784FA0) --------------------------------------------------------  // acclient.c:924181
void __cdecl _E175_72()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_77;
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

