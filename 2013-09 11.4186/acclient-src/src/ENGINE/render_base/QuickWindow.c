/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : QuickWindow
   Object     : ENGINE\render_base\QuickWindow.obj
   Functions  : 79
   Addresses  : 006989C0 - 00786C80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006989C0) --------------------------------------------------------  // acclient.c:688589
void __thiscall QuickWindow::~QuickWindow(QuickWindow *this)
{
  QuickWindow *v1; // esi@1

  v1 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&QuickWindow::vftable;
  Render::SafelyStopUsingAndReleaseTexture(&this->m_pBackgroundTexture);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 800A98: using guessed type int (__thiscall *QuickWindow::vftable)(void *, char);

//----- (006989E0) --------------------------------------------------------  // acclient.c:688602
void __thiscall QuickWindow::SetColorAndOpacity(QuickWindow *this, RGBAColor *_ColorAndOpacity)
{
  this->m_ColorAndOpacity = *_ColorAndOpacity;
}

//----- (00698A00) --------------------------------------------------------  // acclient.c:688608
void __thiscall QuickWindow::SetBackgroundTexture(QuickWindow *this, RenderTexture *_pBackgroundTexture)
{
  QuickWindow *v2; // esi@1
  RenderTexture **v3; // esi@3

  v2 = this;
  if ( _pBackgroundTexture )
  {
    gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)this);
    _pBackgroundTexture->vfptr->AddRef((Interface *)_pBackgroundTexture);
  }
  v3 = &v2->m_pBackgroundTexture;
  Render::SafelyStopUsingAndReleaseTexture(v3);
  *v3 = _pBackgroundTexture;
}

//----- (00698A30) --------------------------------------------------------  // acclient.c:688625
void __thiscall QuickWindow::RenderWindowBackground(QuickWindow *this, RenderTexture *_pTexture, RGBAColor *_ColorAndOpacity)
{
  QuickWindow *v3; // esi@1
  float ClipLeft; // [sp+4h] [bp-60h]@1
  float ClipBottom; // [sp+8h] [bp-5Ch]@1
  float ClipRight; // [sp+Ch] [bp-58h]@1
  float ClipTop; // [sp+10h] [bp-54h]@1
  TexCoordPair TCQuad[4]; // [sp+14h] [bp-50h]@1
  Vector3 ClipPoints[4]; // [sp+34h] [bp-30h]@1

  v3 = this;
  SceneTool::IdentityMatrices();
  SceneTool::ViewportToClip(v3->m_X, v3->m_Y, &ClipLeft, &ClipTop);
  SceneTool::ViewportToClip(v3->m_Width + v3->m_X - 1, v3->m_Height + v3->m_Y - 1, &ClipRight, &ClipBottom);
  ClipPoints[0].x = ClipLeft;
  ClipPoints[0].z = ClipTop;
  ClipPoints[1].x = ClipLeft;
  ClipPoints[1].z = ClipBottom;
  ClipPoints[3].x = ClipRight;
  ClipPoints[2].x = ClipRight;
  ClipPoints[2].z = ClipBottom;
  LODWORD(ClipPoints[0].y) = 0;
  LODWORD(ClipPoints[1].y) = 0;
  LODWORD(ClipPoints[2].y) = 0;
  LODWORD(ClipPoints[3].y) = 0;
  ClipPoints[3].z = ClipTop;
  LODWORD(TCQuad[0].u) = 0;
  LODWORD(TCQuad[0].v) = 0;
  LODWORD(TCQuad[1].u) = 0;
  LODWORD(TCQuad[1].v) = 1065353216;
  LODWORD(TCQuad[2].u) = 1065353216;
  LODWORD(TCQuad[2].v) = 1065353216;
  LODWORD(TCQuad[3].u) = 1065353216;
  LODWORD(TCQuad[3].v) = 0;
  if ( _pTexture )
    SceneTool::DrawTexturedPolygon(
      ClipPoints,
      4u,
      TCQuad,
      _pTexture,
      _ColorAndOpacity,
      0,
      0,
      CULLMODE_CW,
      BLEND_SRCALPHA,
      BLEND_INVSRCALPHA,
      1);
  else
    SceneTool::DrawPolygon(ClipPoints, 4u, _ColorAndOpacity, 0, 0, CULLMODE_CW, BLEND_SRCALPHA, BLEND_INVSRCALPHA);
}

//----- (00698B70) --------------------------------------------------------  // acclient.c:688677
void __thiscall QuickWindow::RenderText(QuickWindow *this, const int _X, const int _Y, const char *_pText, const unsigned int _Color32)
{
  if ( _X < (signed int)this->m_ClientAreaWidth && _Y < (signed int)this->m_ClientAreaHeight )
    RenderDeviceD3D::RenderDebugText(
      (RenderDeviceD3D *)RenderDevice::render_device,
      _X + this->m_ClientAreaX,
      _Y + this->m_ClientAreaY,
      _pText,
      _Color32);
}

//----- (00698BB0) --------------------------------------------------------  // acclient.c:688689
void __thiscall QuickWindow::QuickWindow(QuickWindow *this)
{
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&QuickWindow::vftable;
  this->m_WindowID = 0;
  this->m_X = 0;
  this->m_Y = 0;
  this->m_Width = 0;
  this->m_Height = 0;
  this->m_BorderWidth = 0;
  this->m_BorderHeight = 0;
  this->m_ColorAndOpacity = stru_8349DC;
  this->m_pBackgroundTexture = 0;
  this->m_ClientAreaX = 0;
  this->m_ClientAreaY = 0;
  this->m_ClientAreaWidth = 0;
  this->m_ClientAreaHeight = 0;
}
// 800A98: using guessed type int (__thiscall *QuickWindow::vftable)(void *, char);

//----- (00698C10) --------------------------------------------------------  // acclient.c:688710
QuickWindow *__thiscall QuickWindow::vector_deleting_destructor(QuickWindow *this, unsigned int a2)
{
  QuickWindow *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&QuickWindow::vftable;
  Render::SafelyStopUsingAndReleaseTexture(&this->m_pBackgroundTexture);
  v2->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 800A98: using guessed type int (__thiscall *QuickWindow::vftable)(void *, char);

//----- (00698C50) --------------------------------------------------------  // acclient.c:688726
char __thiscall QuickWindow::Init(QuickWindow *this, const int _X, const int _Y, const unsigned int _Width, const unsigned int _Height, const unsigned int _BorderWidth, const unsigned int _BorderHeight)
{
  this->m_X = _X;
  this->m_BorderWidth = _BorderWidth;
  this->m_Width = _Width;
  this->m_Y = _Y;
  this->m_ClientAreaWidth = _Width - 2 * _BorderWidth;
  this->m_BorderHeight = _BorderHeight;
  this->m_Height = _Height;
  this->m_ClientAreaY = _BorderHeight + _Y;
  this->m_ClientAreaX = _BorderWidth + _X;
  this->m_ClientAreaHeight = _Height - 2 * _BorderHeight;
  return 1;
}

//----- (00698CA0) --------------------------------------------------------  // acclient.c:688742
void __thiscall QuickWindow::SetPosition(QuickWindow *this, const int _X, const int _Y)
{
  unsigned int v3; // eax@1
  unsigned int v4; // edx@1
  unsigned int v5; // esi@1
  unsigned int v6; // eax@1

  v3 = this->m_BorderWidth;
  this->m_X = _X;
  this->m_Y = _Y;
  this->m_ClientAreaX = v3 + _X;
  v4 = this->m_BorderHeight;
  this->m_ClientAreaY = v4 + _Y;
  v5 = this->m_Width - 2 * v3;
  v6 = this->m_Height - 2 * v4;
  this->m_ClientAreaWidth = v5;
  this->m_ClientAreaHeight = v6;
}

//----- (00698CE0) --------------------------------------------------------  // acclient.c:688762
void __thiscall QuickWindow::Render(QuickWindow *this)
{
  QuickWindow::RenderWindowBackground(this, this->m_pBackgroundTexture, &this->m_ColorAndOpacity);
}

//----- (00698CF0) --------------------------------------------------------  // acclient.c:688768
TResult *__cdecl QuickWindow::Create(TResult *result, QuickWindow **_pOutObject, const int _X, const int _Y, const unsigned int _Width, const unsigned int _Height, const unsigned int _BorderWidth, const unsigned int _BorderHeight)
{
  QuickWindow *v8; // eax@1
  int v9; // eax@2
  TResult *v10; // eax@5

  v8 = (QuickWindow *)operator new(0x48u);
  if ( v8 )
    QuickWindow::QuickWindow(v8);
  else
    v9 = 0;
  *_pOutObject = (QuickWindow *)v9;
  if ( v9 )
  {
    *(_DWORD *)(v9 + 12) = _X;
    *(_DWORD *)(v9 + 28) = _BorderWidth;
    *(_DWORD *)(v9 + 20) = _Width;
    *(_DWORD *)(v9 + 16) = _Y;
    *(_DWORD *)(v9 + 64) = _Width - 2 * _BorderWidth;
    *(_DWORD *)(v9 + 32) = _BorderHeight;
    *(_DWORD *)(v9 + 24) = _Height;
    *(_DWORD *)(v9 + 56) = _BorderWidth + _X;
    *(_DWORD *)(v9 + 60) = _BorderHeight + _Y;
    *(_DWORD *)(v9 + 68) = _Height - 2 * _BorderHeight;
    v10 = result;
    result->m_val = 0;
  }
  else
  {
    v10 = result;
    result->m_val = -2147467259;
  }
  return v10;
}

//----- (0071AE80) --------------------------------------------------------  // acclient.c:813303
void sub_71AE80()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F8DE0, PFID_A8R8G8B8);
}

//----- (0071AE90) --------------------------------------------------------  // acclient.c:813309
void sub_71AE90()
{
  LODWORD(dword_8F8E18) = 1053364187;
}

//----- (0071AEA0) --------------------------------------------------------  // acclient.c:813315
void sub_71AEA0()
{
  flt_8F8E1C = 1000.0 + 1.0;
}

//----- (0071AEC0) --------------------------------------------------------  // acclient.c:813321
void sub_71AEC0()
{
  flt_8F8E20 = 24.0 * 8.0;
}

//----- (0071AEE0) --------------------------------------------------------  // acclient.c:813327
void sub_71AEE0()
{
  flt_8F8E24 = 24.0 * 0.5;
}

//----- (0071AF00) --------------------------------------------------------  // acclient.c:813333
int _E99_47()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_48, "Render.TextureFiltering");
  return atexit(sub_786680);
}

//----- (0071AF20) --------------------------------------------------------  // acclient.c:813340
int _E102_40()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_48, "Render.LandscapeDetailTextures");
  return atexit(sub_7866B0);
}

//----- (0071AF40) --------------------------------------------------------  // acclient.c:813347
int _E105_61()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_48, "Render.BuildingDetailTextures");
  return atexit(sub_7866E0);
}

//----- (0071AF60) --------------------------------------------------------  // acclient.c:813354
int sub_71AF60()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_48, "Render.FieldOfView");
  return atexit(sub_786710);
}

//----- (0071AF80) --------------------------------------------------------  // acclient.c:813361
int _E111_65()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_48, "Render.LandscapeTextureDetail");
  return atexit(sub_786740);
}

//----- (0071AFA0) --------------------------------------------------------  // acclient.c:813368
int _E114_71()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_48, "Render.EnvironmentTextureDetail");
  return atexit(sub_786770);
}

//----- (0071AFC0) --------------------------------------------------------  // acclient.c:813375
int _E117_89()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_48, "Render.SceneryDrawDistance");
  return atexit(sub_7867A0);
}

//----- (0071AFE0) --------------------------------------------------------  // acclient.c:813382
int _E120_83()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_48, "Render.LandscapeDrawDistance");
  return atexit(sub_7867D0);
}

//----- (0071B000) --------------------------------------------------------  // acclient.c:813389
int _E123_53()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_48, "Render.ScreenBrightness");
  return atexit(sub_786800);
}

//----- (0071B020) --------------------------------------------------------  // acclient.c:813396
int _E126_61()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_48, "Render.AspectRatio");
  return atexit(sub_786830);
}

//----- (0071B040) --------------------------------------------------------  // acclient.c:813403
int _E129_55()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_48, "Render.DisplayAdapter");
  return atexit(sub_786860);
}

//----- (0071B060) --------------------------------------------------------  // acclient.c:813410
int _E132_55()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_48, "Render.MaxHardwareClass");
  return atexit(sub_786890);
}

//----- (0071B080) --------------------------------------------------------  // acclient.c:813417
int _E135_63()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_48, "Render.AutomaticDegrades");
  return atexit(_E136_97);
}

//----- (0071B0A0) --------------------------------------------------------  // acclient.c:813424
int _E138_49()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_48, "Render.GraphicsPerformance");
  return atexit(_E139_97);
}

//----- (0071B0C0) --------------------------------------------------------  // acclient.c:813431
int _E141_51()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_48, "Render.DegradeDistance");
  return atexit(_E142_91);
}

//----- (0071B0E0) --------------------------------------------------------  // acclient.c:813438
int _E144_48()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_48, "Render.MultiPassAlpha");
  return atexit(_E145_93);
}

//----- (0071B100) --------------------------------------------------------  // acclient.c:813445
int _E147_47()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_48, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8F8E70, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8F8E74, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8F8E78, "Anisotropic");
  return atexit(_E148_89);
}

//----- (0071B150) --------------------------------------------------------  // acclient.c:813455
int _E150_46()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_48, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F8E80, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8E84, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8E88, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F8E8C, "VeryHigh");
  return atexit(_E151_87);
}

//----- (0071B1B0) --------------------------------------------------------  // acclient.c:813466
int _E153_44()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_48, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F8E94, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8E98, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8E9C, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F8EA0, "VeryHigh");
  return atexit(_E154_88);
}

//----- (0071B210) --------------------------------------------------------  // acclient.c:813477
int _E156_46()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_48, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8EA8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8EAC, "High");
  return atexit(_E157_84);
}

//----- (0071B250) --------------------------------------------------------  // acclient.c:813486
int _E159_44()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_48, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F8EB4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F8EB8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F8EBC, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F8EC0, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8F8EC4, "Extreme");
  return atexit(_E160_87);
}

//----- (0071B2C0) --------------------------------------------------------  // acclient.c:813498
int _E162_47()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_48, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8F8ECC, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8F8ED0, "Wide");
  return atexit(_E163_80);
}

//----- (0071B300) --------------------------------------------------------  // acclient.c:813507
int _E165_42()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_83, "None");
  return atexit(_E166_82);
}

//----- (0071B320) --------------------------------------------------------  // acclient.c:813514
int _E168_43()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_83, "Speed");
  return atexit(_E169_81);
}

//----- (0071B340) --------------------------------------------------------  // acclient.c:813521
int _E171_42()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_83, "Noise");
  return atexit(_E172_79);
}

//----- (0071B360) --------------------------------------------------------  // acclient.c:813528
int _E174_44()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_83, "Sine");
  return atexit(_E175_76);
}

//----- (0071B380) --------------------------------------------------------  // acclient.c:813535
int _E177_41()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_83, "Square");
  return atexit(_E178_76);
}

//----- (0071B3A0) --------------------------------------------------------  // acclient.c:813542
int _E180_41()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_83, "Bounce");
  return atexit(_E181_76);
}

//----- (0071B3C0) --------------------------------------------------------  // acclient.c:813549
int _E183_40()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_83, "Perlin");
  return atexit(_E184_73);
}

//----- (0071B3E0) --------------------------------------------------------  // acclient.c:813556
int _E186_40()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_83, "Fractal");
  return atexit(_E187_72);
}

//----- (0071B400) --------------------------------------------------------  // acclient.c:813563
int _E189_39()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_83, "FrameLoop");
  return atexit(_E190_73);
}

//----- (0071B420) --------------------------------------------------------  // acclient.c:813570
int sub_71B420()
{
  return atexit(nullsub_296);
}

//----- (00786680) --------------------------------------------------------  // acclient.c:925872
void __cdecl sub_786680()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007866B0) --------------------------------------------------------  // acclient.c:925885
void __cdecl sub_7866B0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007866E0) --------------------------------------------------------  // acclient.c:925898
void __cdecl sub_7866E0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786710) --------------------------------------------------------  // acclient.c:925911
void __cdecl sub_786710()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786740) --------------------------------------------------------  // acclient.c:925924
void __cdecl sub_786740()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786770) --------------------------------------------------------  // acclient.c:925937
void __cdecl sub_786770()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007867A0) --------------------------------------------------------  // acclient.c:925950
void __cdecl sub_7867A0()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007867D0) --------------------------------------------------------  // acclient.c:925963
void __cdecl sub_7867D0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786800) --------------------------------------------------------  // acclient.c:925976
void __cdecl sub_786800()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786830) --------------------------------------------------------  // acclient.c:925989
void __cdecl sub_786830()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786860) --------------------------------------------------------  // acclient.c:926002
void __cdecl sub_786860()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786890) --------------------------------------------------------  // acclient.c:926015
void __cdecl sub_786890()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007868C0) --------------------------------------------------------  // acclient.c:926028
void __cdecl _E136_97()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007868F0) --------------------------------------------------------  // acclient.c:926041
void __cdecl _E139_97()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786920) --------------------------------------------------------  // acclient.c:926054
void __cdecl _E142_91()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786950) --------------------------------------------------------  // acclient.c:926067
void __cdecl _E145_93()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786980) --------------------------------------------------------  // acclient.c:926080
void __cdecl _E148_89()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_48;
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

//----- (007869C0) --------------------------------------------------------  // acclient.c:926105
void __cdecl _E151_87()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_48;
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

//----- (00786A00) --------------------------------------------------------  // acclient.c:926130
void __cdecl _E154_88()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_48;
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

//----- (00786A40) --------------------------------------------------------  // acclient.c:926155
void __cdecl _E157_84()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_48;
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

//----- (00786A80) --------------------------------------------------------  // acclient.c:926180
void __cdecl _E160_87()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_48;
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

//----- (00786AC0) --------------------------------------------------------  // acclient.c:926205
void __cdecl _E163_80()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_83;
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

//----- (00786B00) --------------------------------------------------------  // acclient.c:926230
void __cdecl _E166_82()
{
  char *v0; // esi@1

  v0 = &waveform_None_83.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_83.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786B30) --------------------------------------------------------  // acclient.c:926243
void __cdecl _E169_81()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_83.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_83.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786B60) --------------------------------------------------------  // acclient.c:926256
void __cdecl _E172_79()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_83.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_83.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786B90) --------------------------------------------------------  // acclient.c:926269
void __cdecl _E175_76()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_83.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_83.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786BC0) --------------------------------------------------------  // acclient.c:926282
void __cdecl _E178_76()
{
  char *v0; // esi@1

  v0 = &waveform_Square_83.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_83.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786BF0) --------------------------------------------------------  // acclient.c:926295
void __cdecl _E181_76()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_83.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_83.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786C20) --------------------------------------------------------  // acclient.c:926308
void __cdecl _E184_73()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_83.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_83.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786C50) --------------------------------------------------------  // acclient.c:926321
void __cdecl _E187_72()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_83.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_83.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00786C80) --------------------------------------------------------  // acclient.c:926334
void __cdecl _E190_73()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_83.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_83.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

