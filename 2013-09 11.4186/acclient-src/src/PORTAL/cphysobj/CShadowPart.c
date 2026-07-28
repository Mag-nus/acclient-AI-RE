/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CShadowPart
   Object     : PORTAL\cphysobj\CShadowPart.obj
   Functions  : 76
   Addresses  : 006B5050 - 00791090 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B5050) --------------------------------------------------------  // acclient.c:718927
void __thiscall CShadowPart::CShadowPart(CShadowPart *this, unsigned int nump, Frame *_frame, CPhysicsPart *_part)
{
  CShadowPart *v4; // esi@1
  unsigned int v5; // eax@3

  v4 = this;
  this->part = _part;
  this->frame = _frame;
  this->num_planes = nump;
  if ( nump )
  {
    this->planes = (ClipPlaneList **)operator new[](4 * nump);
    v5 = 0;
    if ( nump )
    {
      do
        v4->planes[v5++] = 0;
      while ( v5 < nump );
    }
  }
  else
  {
    this->planes = 0;
  }
}

//----- (006B50B0) --------------------------------------------------------  // acclient.c:718954
void __thiscall CShadowPart::CShadowPart(CShadowPart *this, unsigned int nump, ClipPlaneList **_planes, Frame *_frame, CPhysicsPart *_part)
{
  this->num_planes = nump;
  this->planes = _planes;
  this->frame = _frame;
  this->part = _part;
}

//----- (006B50D0) --------------------------------------------------------  // acclient.c:718963
void __thiscall CShadowPart::draw(CShadowPart *this, unsigned int leaf_index)
{
  CPhysicsPart::Draw(this->part, 0);
}

//----- (006B50E0) --------------------------------------------------------  // acclient.c:718969
void __thiscall CShadowPart::~CShadowPart(CShadowPart *this)
{
  CShadowPart *v1; // edi@1
  unsigned int v2; // ebx@2
  ClipPlaneList **v3; // eax@3
  void *v4; // esi@3

  v1 = this;
  if ( this->planes )
  {
    v2 = 0;
    if ( this->num_planes )
    {
      do
      {
        v3 = v1->planes;
        v4 = v3[v2];
        if ( v4 )
        {
          ClipPlaneList::~ClipPlaneList(v3[v2]);
          operator delete(v4);
        }
        ++v2;
      }
      while ( v2 < v1->num_planes );
    }
    operator delete[](v1->planes);
  }
}

//----- (006B5130) --------------------------------------------------------  // acclient.c:719000
void __cdecl CShadowPart::insertion_sort(DArray<CShadowPart *> *A, unsigned int len)
{
  CShadowPart **v2; // eax@1
  CShadowPart **v3; // esi@1
  int v4; // ebx@2
  CShadowPart *v5; // edi@3
  unsigned int v6; // ecx@3
  unsigned int lena; // [sp+Ch] [bp+8h]@2

  v2 = A->data;
  v3 = &A->data[len - 2];
  if ( v3 >= A->data )
  {
    lena = 4 * len - 4;
    v4 = (int)(v3 + 1);
    do
    {
      v5 = *v3;
      v6 = v4;
      if ( v4 <= (unsigned int)((char *)v2 + lena) )
      {
        do
        {
          if ( **(float **)(*(_DWORD *)v6 + 12) <= (double)v5->part->CYpt )
            break;
          *(_DWORD *)(v6 - 4) = *(_DWORD *)v6;
          v6 += 4;
        }
        while ( (CShadowPart **)v6 <= (CShadowPart **)((char *)A->data + lena) );
      }
      *(_DWORD *)(v6 - 4) = v5;
      v2 = A->data;
      --v3;
      v4 -= 4;
    }
    while ( v3 >= A->data );
  }
}

//----- (007237D0) --------------------------------------------------------  // acclient.c:821345
void sub_7237D0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FA884, PFID_A8R8G8B8);
}

//----- (007237E0) --------------------------------------------------------  // acclient.c:821351
void sub_7237E0()
{
  LODWORD(dword_8FA8BC) = 1053364187;
}

//----- (007237F0) --------------------------------------------------------  // acclient.c:821357
void sub_7237F0()
{
  flt_8FA8C0 = 1000.0 + 1.0;
}

//----- (00723810) --------------------------------------------------------  // acclient.c:821363
void sub_723810()
{
  flt_8FA8C4 = 24.0 * 8.0;
}

//----- (00723830) --------------------------------------------------------  // acclient.c:821369
void sub_723830()
{
  flt_8FA8C8 = 24.0 * 0.5;
}

//----- (00723850) --------------------------------------------------------  // acclient.c:821375
int _E99_51()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_49, "Render.TextureFiltering");
  return atexit(sub_790A90);
}

//----- (00723870) --------------------------------------------------------  // acclient.c:821382
int _E102_42()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_49, "Render.LandscapeDetailTextures");
  return atexit(sub_790AC0);
}

//----- (00723890) --------------------------------------------------------  // acclient.c:821389
int _E105_64()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_49, "Render.BuildingDetailTextures");
  return atexit(sub_790AF0);
}

//----- (007238B0) --------------------------------------------------------  // acclient.c:821396
int sub_7238B0()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_49, "Render.FieldOfView");
  return atexit(sub_790B20);
}

//----- (007238D0) --------------------------------------------------------  // acclient.c:821403
int _E111_67()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_49, "Render.LandscapeTextureDetail");
  return atexit(sub_790B50);
}

//----- (007238F0) --------------------------------------------------------  // acclient.c:821410
int _E114_73()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_49, "Render.EnvironmentTextureDetail");
  return atexit(sub_790B80);
}

//----- (00723910) --------------------------------------------------------  // acclient.c:821417
int sub_723910()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_49, "Render.SceneryDrawDistance");
  return atexit(sub_790BB0);
}

//----- (00723930) --------------------------------------------------------  // acclient.c:821424
int _E120_85()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_49, "Render.LandscapeDrawDistance");
  return atexit(sub_790BE0);
}

//----- (00723950) --------------------------------------------------------  // acclient.c:821431
int _E123_55()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_49, "Render.ScreenBrightness");
  return atexit(sub_790C10);
}

//----- (00723970) --------------------------------------------------------  // acclient.c:821438
int _E126_63()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_49, "Render.AspectRatio");
  return atexit(sub_790C40);
}

//----- (00723990) --------------------------------------------------------  // acclient.c:821445
int _E129_57()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_49, "Render.DisplayAdapter");
  return atexit(sub_790C70);
}

//----- (007239B0) --------------------------------------------------------  // acclient.c:821452
int _E132_57()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_49, "Render.MaxHardwareClass");
  return atexit(sub_790CA0);
}

//----- (007239D0) --------------------------------------------------------  // acclient.c:821459
int _E135_65()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_49, "Render.AutomaticDegrades");
  return atexit(sub_790CD0);
}

//----- (007239F0) --------------------------------------------------------  // acclient.c:821466
int _E138_51()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_49, "Render.GraphicsPerformance");
  return atexit(sub_790D00);
}

//----- (00723A10) --------------------------------------------------------  // acclient.c:821473
int _E141_53()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_49, "Render.DegradeDistance");
  return atexit(_E142_93);
}

//----- (00723A30) --------------------------------------------------------  // acclient.c:821480
int _E144_49()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_49, "Render.MultiPassAlpha");
  return atexit(_E145_94);
}

//----- (00723A50) --------------------------------------------------------  // acclient.c:821487
int _E147_48()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_49, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8FA914, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8FA918, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8FA91C, "Anisotropic");
  return atexit(_E148_90);
}

//----- (00723AA0) --------------------------------------------------------  // acclient.c:821497
int _E150_47()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_49, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8FA924, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8FA928, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8FA92C, "High");
  PStringBase<char>::PStringBase<char>(&stru_8FA930, "VeryHigh");
  return atexit(_E151_88);
}

//----- (00723B00) --------------------------------------------------------  // acclient.c:821508
int _E153_45()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_49, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8FA938, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8FA93C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8FA940, "High");
  PStringBase<char>::PStringBase<char>(&stru_8FA944, "VeryHigh");
  return atexit(_E154_89);
}

//----- (00723B60) --------------------------------------------------------  // acclient.c:821519
int _E156_47()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_49, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8FA94C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8FA950, "High");
  return atexit(_E157_85);
}

//----- (00723BA0) --------------------------------------------------------  // acclient.c:821528
int _E159_45()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_49, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8FA958, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8FA95C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8FA960, "High");
  PStringBase<char>::PStringBase<char>(&stru_8FA964, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8FA968, "Extreme");
  return atexit(_E160_88);
}

//----- (00723C10) --------------------------------------------------------  // acclient.c:821540
int _E162_48()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_49, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8FA970, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8FA974, "Wide");
  return atexit(_E163_81);
}

//----- (00723C50) --------------------------------------------------------  // acclient.c:821549
int _E165_43()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_86, "None");
  return atexit(_E166_83);
}

//----- (00723C70) --------------------------------------------------------  // acclient.c:821556
int _E168_44()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_86, "Speed");
  return atexit(_E169_82);
}

//----- (00723C90) --------------------------------------------------------  // acclient.c:821563
int _E171_43()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_86, "Noise");
  return atexit(_E172_80);
}

//----- (00723CB0) --------------------------------------------------------  // acclient.c:821570
int _E174_45()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_86, "Sine");
  return atexit(_E175_77);
}

//----- (00723CD0) --------------------------------------------------------  // acclient.c:821577
int _E177_42()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_86, "Square");
  return atexit(_E178_77);
}

//----- (00723CF0) --------------------------------------------------------  // acclient.c:821584
int _E180_42()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_86, "Bounce");
  return atexit(_E181_77);
}

//----- (00723D10) --------------------------------------------------------  // acclient.c:821591
int _E183_41()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_86, "Perlin");
  return atexit(_E184_74);
}

//----- (00723D30) --------------------------------------------------------  // acclient.c:821598
int _E186_41()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_86, "Fractal");
  return atexit(_E187_73);
}

//----- (00723D50) --------------------------------------------------------  // acclient.c:821605
int _E189_40()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_86, "FrameLoop");
  return atexit(_E190_74);
}

//----- (00723D70) --------------------------------------------------------  // acclient.c:821612
void _E192_31()
{
  flt_8FA99C = 0.00019999999 * 3.0 + 0.1;
}

//----- (00723D90) --------------------------------------------------------  // acclient.c:821618
void _E194_9()
{
  dbl_8FA9A0 = 1.0 / 30.0;
}

//----- (00723DB0) --------------------------------------------------------  // acclient.c:821624
void _E196_39()
{
  dbl_8FA9A8 = 1.0 / 5.0;
}

//----- (00723DD0) --------------------------------------------------------  // acclient.c:821630
int sub_723DD0()
{
  return atexit(nullsub_1098);
}

//----- (00790A90) --------------------------------------------------------  // acclient.c:936776
void __cdecl sub_790A90()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790AC0) --------------------------------------------------------  // acclient.c:936789
void __cdecl sub_790AC0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790AF0) --------------------------------------------------------  // acclient.c:936802
void __cdecl sub_790AF0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790B20) --------------------------------------------------------  // acclient.c:936815
void __cdecl sub_790B20()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790B50) --------------------------------------------------------  // acclient.c:936828
void __cdecl sub_790B50()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790B80) --------------------------------------------------------  // acclient.c:936841
void __cdecl sub_790B80()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790BB0) --------------------------------------------------------  // acclient.c:936854
void __cdecl sub_790BB0()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790BE0) --------------------------------------------------------  // acclient.c:936867
void __cdecl sub_790BE0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790C10) --------------------------------------------------------  // acclient.c:936880
void __cdecl sub_790C10()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790C40) --------------------------------------------------------  // acclient.c:936893
void __cdecl sub_790C40()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790C70) --------------------------------------------------------  // acclient.c:936906
void __cdecl sub_790C70()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790CA0) --------------------------------------------------------  // acclient.c:936919
void __cdecl sub_790CA0()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790CD0) --------------------------------------------------------  // acclient.c:936932
void __cdecl sub_790CD0()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790D00) --------------------------------------------------------  // acclient.c:936945
void __cdecl sub_790D00()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790D30) --------------------------------------------------------  // acclient.c:936958
void __cdecl _E142_93()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790D60) --------------------------------------------------------  // acclient.c:936971
void __cdecl _E145_94()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790D90) --------------------------------------------------------  // acclient.c:936984
void __cdecl _E148_90()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_49;
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

//----- (00790DD0) --------------------------------------------------------  // acclient.c:937009
void __cdecl _E151_88()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_49;
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

//----- (00790E10) --------------------------------------------------------  // acclient.c:937034
void __cdecl _E154_89()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_49;
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

//----- (00790E50) --------------------------------------------------------  // acclient.c:937059
void __cdecl _E157_85()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_49;
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

//----- (00790E90) --------------------------------------------------------  // acclient.c:937084
void __cdecl _E160_88()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_49;
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

//----- (00790ED0) --------------------------------------------------------  // acclient.c:937109
void __cdecl _E163_81()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_86;
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

//----- (00790F10) --------------------------------------------------------  // acclient.c:937134
void __cdecl _E166_83()
{
  char *v0; // esi@1

  v0 = &waveform_None_86.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_86.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790F40) --------------------------------------------------------  // acclient.c:937147
void __cdecl _E169_82()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_86.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_86.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790F70) --------------------------------------------------------  // acclient.c:937160
void __cdecl _E172_80()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_86.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_86.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790FA0) --------------------------------------------------------  // acclient.c:937173
void __cdecl _E175_77()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_86.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_86.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790FD0) --------------------------------------------------------  // acclient.c:937186
void __cdecl _E178_77()
{
  char *v0; // esi@1

  v0 = &waveform_Square_86.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_86.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791000) --------------------------------------------------------  // acclient.c:937199
void __cdecl _E181_77()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_86.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_86.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791030) --------------------------------------------------------  // acclient.c:937212
void __cdecl _E184_74()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_86.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_86.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791060) --------------------------------------------------------  // acclient.c:937225
void __cdecl _E187_73()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_86.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_86.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791090) --------------------------------------------------------  // acclient.c:937238
void __cdecl _E190_74()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_86.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_86.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

