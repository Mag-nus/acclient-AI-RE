/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GraphicsOptions
   Object     : PORTAL\smartbox\GraphicsOptions.obj
   Functions  : 62
   Addresses  : 00455C30 - 0075CDC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00455C30) --------------------------------------------------------  // acclient.c:146791
bool __cdecl GraphicsOptions::HandleRenderOption(int argc, char **argv, const char **status_string, const char **usage_string)
{
  bool result; // al@2
  int v5; // eax@8
  int v6; // eax@15
  float i_nValue; // ST04_4@17

  if ( argc < 2 )
  {
    *usage_string = "Usage:\n@render <option> <value>\n  radius #        : set landscape radius (between 5 and 25)\n  fov #           : set field of view (between 10 and 160)\n";
    return 0;
  }
  if ( !__stricmp(argv[1], "usage") )
  {
    *usage_string = "Usage:\n@render <option> <value>\n  radius #        : set landscape radius (between 5 and 25)\n  fov #           : set field of view (between 10 and 160)\n";
    return 0;
  }
  if ( !__stricmp(argv[1], "radius") )
  {
    if ( argc >= 3 )
    {
      v5 = _atoi(argv[2]);
      if ( (unsigned int)v5 < 5 || (unsigned int)v5 > 0x19 )
      {
        *status_string = "Radius must be between 5 and 25";
        result = 1;
      }
      else
      {
        UIPreferences::ModifyPreference(&Render_LandscapeDrawDistance_15, v5);
        *status_string = "Landscape radius set";
        result = 1;
      }
    }
    else
    {
      *status_string = "Must specify a radius";
      result = 1;
    }
  }
  else
  {
    if ( !__stricmp(argv[1], "fov") )
    {
      if ( argc < 3 )
      {
        *status_string = "Must specify a field of view";
        return 1;
      }
      v6 = _atoi(argv[2]);
      if ( (unsigned int)v6 >= 0xA && (unsigned int)v6 <= 0xA0 )
      {
        i_nValue = (double)(unsigned int)v6;
        UIPreferences::ModifyPreference(&Render_FieldOfView_15, i_nValue);
        *status_string = "Field of view set";
        return 1;
      }
      *status_string = "Field of view must be between 10 and 160";
    }
    result = 1;
  }
  return result;
}

//----- (006EA270) --------------------------------------------------------  // acclient.c:766176
int _E73_59()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_5, "Display.Resolution");
  return atexit(_E74_43);
}

//----- (006EA290) --------------------------------------------------------  // acclient.c:766183
int _E76_29()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_5, "Display.FullScreen");
  return atexit(_E77_57);
}

//----- (006EA2B0) --------------------------------------------------------  // acclient.c:766190
int _E79_29()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_5, "Display.RefreshRate");
  return atexit(_E80_31);
}

//----- (006EA2D0) --------------------------------------------------------  // acclient.c:766197
int _E82_20()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_5, "Display.SyncToRefresh");
  return atexit(_E83_20);
}

//----- (006EA2F0) --------------------------------------------------------  // acclient.c:766204
void _E101_0()
{
  LODWORD(dword_83CDC8) = 1053364187;
}

//----- (006EA300) --------------------------------------------------------  // acclient.c:766210
void _E103_13()
{
  outside_val_20 = 1000.0 + 1.0;
}

//----- (006EA320) --------------------------------------------------------  // acclient.c:766216
void _E105_6()
{
  block_length_20 = 24.0 * 8.0;
}

//----- (006EA340) --------------------------------------------------------  // acclient.c:766222
void _E107_1()
{
  half_square_length_20 = 24.0 * 0.5;
}

//----- (006EA360) --------------------------------------------------------  // acclient.c:766228
void _E109_11()
{
  DEFAULT_VIEW_RADIUS_7 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EA380) --------------------------------------------------------  // acclient.c:766234
void _E111_8()
{
  MIN_QUANTUM_7 = 1.0 / 30.0;
}

//----- (006EA3A0) --------------------------------------------------------  // acclient.c:766240
void _E113_0()
{
  MAX_QUANTUM_7 = 1.0 / 5.0;
}

//----- (006EA3C0) --------------------------------------------------------  // acclient.c:766246
void _E115_9()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_34, PFID_A8R8G8B8);
}

//----- (006EA3D0) --------------------------------------------------------  // acclient.c:766252
int _E117_8()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_15, "Render.TextureFiltering");
  return atexit(sub_75C980);
}

//----- (006EA3F0) --------------------------------------------------------  // acclient.c:766259
int _E120_11()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_15, "Render.LandscapeDetailTextures");
  return atexit(sub_75C9B0);
}

//----- (006EA410) --------------------------------------------------------  // acclient.c:766266
int _E123_8()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_15, "Render.BuildingDetailTextures");
  return atexit(sub_75C9E0);
}

//----- (006EA430) --------------------------------------------------------  // acclient.c:766273
int _E126_12()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_15, "Render.FieldOfView");
  return atexit(_E127_93);
}

//----- (006EA450) --------------------------------------------------------  // acclient.c:766280
int _E129_11()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_15, "Render.LandscapeTextureDetail");
  return atexit(_E130_85);
}

//----- (006EA470) --------------------------------------------------------  // acclient.c:766287
int _E132_12()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_15, "Render.EnvironmentTextureDetail");
  return atexit(_E133_78);
}

//----- (006EA490) --------------------------------------------------------  // acclient.c:766294
int _E135_11()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_15, "Render.SceneryDrawDistance");
  return atexit(_E136_62);
}

//----- (006EA4B0) --------------------------------------------------------  // acclient.c:766301
int _E138_12()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_15, "Render.LandscapeDrawDistance");
  return atexit(_E139_63);
}

//----- (006EA4D0) --------------------------------------------------------  // acclient.c:766308
int _E141_12()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_15, "Render.ScreenBrightness");
  return atexit(_E142_59);
}

//----- (006EA4F0) --------------------------------------------------------  // acclient.c:766315
int _E144_11()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_15, "Render.AspectRatio");
  return atexit(_E145_61);
}

//----- (006EA510) --------------------------------------------------------  // acclient.c:766322
int _E147_11()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_15, "Render.DisplayAdapter");
  return atexit(_E148_60);
}

//----- (006EA530) --------------------------------------------------------  // acclient.c:766329
int _E150_11()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_15, "Render.MaxHardwareClass");
  return atexit(_E151_58);
}

//----- (006EA550) --------------------------------------------------------  // acclient.c:766336
int _E153_11()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_15, "Render.AutomaticDegrades");
  return atexit(_E154_59);
}

//----- (006EA570) --------------------------------------------------------  // acclient.c:766343
int _E156_12()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_15, "Render.GraphicsPerformance");
  return atexit(_E157_56);
}

//----- (006EA590) --------------------------------------------------------  // acclient.c:766350
int _E159_11()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_15, "Render.DegradeDistance");
  return atexit(_E160_59);
}

//----- (006EA5B0) --------------------------------------------------------  // acclient.c:766357
int _E162_12()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_15, "Render.MultiPassAlpha");
  return atexit(_E163_52);
}

//----- (006EA5D0) --------------------------------------------------------  // acclient.c:766364
int _E165_11()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_15, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_83CE6C, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_83CE70, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_83CE74, "Anisotropic");
  return atexit(_E166_54);
}

//----- (006EA620) --------------------------------------------------------  // acclient.c:766374
int _E168_12()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_15, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83CE7C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83CE80, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83CE84, "High");
  PStringBase<char>::PStringBase<char>(&stru_83CE88, "VeryHigh");
  return atexit(_E169_53);
}

//----- (006EA680) --------------------------------------------------------  // acclient.c:766385
int _E171_12()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_15, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83CE90, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83CE94, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83CE98, "High");
  PStringBase<char>::PStringBase<char>(&stru_83CE9C, "VeryHigh");
  return atexit(_E172_51);
}

//----- (006EA6E0) --------------------------------------------------------  // acclient.c:766396
int _E174_12()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_15, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83CEA4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83CEA8, "High");
  return atexit(_E175_48);
}

//----- (006EA720) --------------------------------------------------------  // acclient.c:766405
int _E177_12()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_15, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83CEB0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83CEB4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83CEB8, "High");
  PStringBase<char>::PStringBase<char>(&stru_83CEBC, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_83CEC0, "Extreme");
  return atexit(_E178_48);
}

//----- (006EA790) --------------------------------------------------------  // acclient.c:766417
int _E180_12()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_15, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_83CEC8, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_83CECC, "Wide");
  return atexit(_E181_48);
}

//----- (006EA7D0) --------------------------------------------------------  // acclient.c:766426
int _E1_49()
{
  return atexit(_E2_49);
}

//----- (0075C8C0) --------------------------------------------------------  // acclient.c:884590
void __cdecl _E74_43()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C8F0) --------------------------------------------------------  // acclient.c:884603
void __cdecl _E77_57()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C920) --------------------------------------------------------  // acclient.c:884616
void __cdecl _E80_31()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C950) --------------------------------------------------------  // acclient.c:884629
void __cdecl _E83_20()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C980) --------------------------------------------------------  // acclient.c:884642
void __cdecl sub_75C980()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C9B0) --------------------------------------------------------  // acclient.c:884655
void __cdecl sub_75C9B0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C9E0) --------------------------------------------------------  // acclient.c:884668
void __cdecl sub_75C9E0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CA10) --------------------------------------------------------  // acclient.c:884681
void __cdecl _E127_93()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CA40) --------------------------------------------------------  // acclient.c:884694
void __cdecl _E130_85()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CA70) --------------------------------------------------------  // acclient.c:884707
void __cdecl _E133_78()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CAA0) --------------------------------------------------------  // acclient.c:884720
void __cdecl _E136_62()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CAD0) --------------------------------------------------------  // acclient.c:884733
void __cdecl _E139_63()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CB00) --------------------------------------------------------  // acclient.c:884746
void __cdecl _E142_59()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CB30) --------------------------------------------------------  // acclient.c:884759
void __cdecl _E145_61()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CB60) --------------------------------------------------------  // acclient.c:884772
void __cdecl _E148_60()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CB90) --------------------------------------------------------  // acclient.c:884785
void __cdecl _E151_58()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CBC0) --------------------------------------------------------  // acclient.c:884798
void __cdecl _E154_59()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CBF0) --------------------------------------------------------  // acclient.c:884811
void __cdecl _E157_56()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CC20) --------------------------------------------------------  // acclient.c:884824
void __cdecl _E160_59()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CC50) --------------------------------------------------------  // acclient.c:884837
void __cdecl _E163_52()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075CC80) --------------------------------------------------------  // acclient.c:884850
void __cdecl _E166_54()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_15;
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

//----- (0075CCC0) --------------------------------------------------------  // acclient.c:884875
void __cdecl _E169_53()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_15;
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

//----- (0075CD00) --------------------------------------------------------  // acclient.c:884900
void __cdecl _E172_51()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_15;
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

//----- (0075CD40) --------------------------------------------------------  // acclient.c:884925
void __cdecl _E175_48()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_15;
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

//----- (0075CD80) --------------------------------------------------------  // acclient.c:884950
void __cdecl _E178_48()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_15;
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

//----- (0075CDC0) --------------------------------------------------------  // acclient.c:884975
void __cdecl _E181_48()
{
  char *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (char *)&unk_83CED0;
  v1 = 3;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
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

