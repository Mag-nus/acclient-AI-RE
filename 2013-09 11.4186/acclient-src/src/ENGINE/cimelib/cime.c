/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : cime
   Object     : ENGINE\cimelib\cime.obj
   Functions  : 29
   Addresses  : 00430B30 - 00728560 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00430B30) --------------------------------------------------------  // acclient.c:109881
void __thiscall RGBAColor::SetColor32(RGBAColor *this, const unsigned int color)
{
  this->a = (double)(color >> 24) * 0.0039215689;
  this->r = (double)((color >> 16) & 0xFF) * 0.0039215689;
  this->g = (double)((unsigned __int16)color >> 8) * 0.0039215689;
  this->b = (double)(unsigned __int8)color * 0.0039215689;
}

//----- (00430BD0) --------------------------------------------------------  // acclient.c:109890
char __cdecl CIme::CleanupPreferences()
{
  UserPreferences::UnregisterPreference(&International_UseIME);
  return 1;
}

//----- (00430BE0) --------------------------------------------------------  // acclient.c:109897
char __thiscall CIme::InitPreferences(PSRefBufferCharData<char> *this)
{
  char *v1; // esi@1
  PStringBase<char> _Description; // [sp+0h] [bp-4h]@1

  _Description.m_charbuffer = this;
  PStringBase<char>::PStringBase<char>(&_Description, "A flag to use IME");
  UserPreferences::RegisterPreference(
    (bool *)&_Description,
    &CIme::g_UseIme,
    &International_UseIME,
    &_Description,
    0,
    0,
    0,
    0);
  v1 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v1 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
  CIme::g_bOSImeEnabled = 1;
  return 1;
}
// 836F61: using guessed type bool CIme::g_bOSImeEnabled;

//----- (006C5840) --------------------------------------------------------  // acclient.c:733839
void _E73_24()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_2, PFID_A8R8G8B8);
}

//----- (006C5850) --------------------------------------------------------  // acclient.c:733845
int _E91_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_2, "None");
  return atexit(_E92_13);
}

//----- (006C5870) --------------------------------------------------------  // acclient.c:733852
int _E94_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_2, "Speed");
  return atexit(sub_7283E0);
}

//----- (006C5890) --------------------------------------------------------  // acclient.c:733859
int _E97_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_2, "Noise");
  return atexit(_E98_28);
}

//----- (006C58B0) --------------------------------------------------------  // acclient.c:733866
int _E100_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_2, "Sine");
  return atexit(_E101_57);
}

//----- (006C58D0) --------------------------------------------------------  // acclient.c:733873
int _E103_4()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_2, "Square");
  return atexit(_E104_27);
}

//----- (006C58F0) --------------------------------------------------------  // acclient.c:733880
int _E106_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_2, "Bounce");
  return atexit(_E107_59);
}

//----- (006C5910) --------------------------------------------------------  // acclient.c:733887
int _E109_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_2, "Perlin");
  return atexit(sub_7284D0);
}

//----- (006C5930) --------------------------------------------------------  // acclient.c:733894
int _E112_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_2, "Fractal");
  return atexit(_E113_39);
}

//----- (006C5950) --------------------------------------------------------  // acclient.c:733901
int _E115_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_2, "FrameLoop");
  return atexit(_E116_31);
}

//----- (006C5970) --------------------------------------------------------  // acclient.c:733908
void _E118_5()
{
  LODWORD(dword_836FDC) = 1053364187;
}

//----- (006C5980) --------------------------------------------------------  // acclient.c:733914
void _E120()
{
  outside_val_4 = 1000.0 + 1.0;
}

//----- (006C59A0) --------------------------------------------------------  // acclient.c:733920
void _E122_0()
{
  block_length_4 = 24.0 * 8.0;
}

//----- (006C59C0) --------------------------------------------------------  // acclient.c:733926
void _E124_5()
{
  half_square_length_4 = 24.0 * 0.5;
}

//----- (006C59E0) --------------------------------------------------------  // acclient.c:733932
int _E126()
{
  PStringBase<char>::PStringBase<char>(&International_UseIME, "International.UseIME");
  return atexit(_E127_80);
}

//----- (006C5A00) --------------------------------------------------------  // acclient.c:733939
int _E1_26()
{
  return atexit(_E2_26);
}

//----- (007283B0) --------------------------------------------------------  // acclient.c:826060
void __cdecl _E92_13()
{
  char *v0; // esi@1

  v0 = &waveform_None_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007283E0) --------------------------------------------------------  // acclient.c:826073
void __cdecl sub_7283E0()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728410) --------------------------------------------------------  // acclient.c:826086
void __cdecl _E98_28()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728440) --------------------------------------------------------  // acclient.c:826099
void __cdecl _E101_57()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728470) --------------------------------------------------------  // acclient.c:826112
void __cdecl _E104_27()
{
  char *v0; // esi@1

  v0 = &waveform_Square_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007284A0) --------------------------------------------------------  // acclient.c:826125
void __cdecl _E107_59()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007284D0) --------------------------------------------------------  // acclient.c:826138
void __cdecl sub_7284D0()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728500) --------------------------------------------------------  // acclient.c:826151
void __cdecl _E113_39()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728530) --------------------------------------------------------  // acclient.c:826164
void __cdecl _E116_31()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728560) --------------------------------------------------------  // acclient.c:826177
void __cdecl _E127_80()
{
  char *v0; // esi@1

  v0 = &International_UseIME.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&International_UseIME.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

