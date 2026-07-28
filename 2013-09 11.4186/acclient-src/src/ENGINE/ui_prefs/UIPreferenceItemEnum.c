/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIPreferenceItemEnum
   Object     : ENGINE\ui_prefs\UIPreferenceItemEnum.obj
   Functions  : 19
   Addresses  : 005DDF60 - 0077ED20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DDF60) --------------------------------------------------------  // acclient.c:521017
char __thiscall UIPreferenceItemEnum::InqEnumValues(UIPreferenceItemEnum *this, SmartArray<unsigned long,1> *o_arrayValues)
{
  char v2; // bl@1
  SmartArray<unsigned long,1> arrayValues; // [sp+4h] [bp-Ch]@1

  arrayValues.m_data = 0;
  arrayValues.m_sizeAndDeallocate = 0;
  arrayValues.m_num = 0;
  v2 = UserPreferences::InqChoiceValues(&this->m_strPreference, &arrayValues);
  if ( v2 )
    SmartArray<unsigned long,1>::AddToEnd(o_arrayValues, &arrayValues);
  if ( (arrayValues.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](arrayValues.m_data);
  return v2;
}

//----- (00714A10) --------------------------------------------------------  // acclient.c:807477
int sub_714A10()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_74, "None");
  return atexit(_E74_98);
}

//----- (00714A30) --------------------------------------------------------  // acclient.c:807484
int _E76_81()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_74, "Speed");
  return atexit(sub_77EBD0);
}

//----- (00714A50) --------------------------------------------------------  // acclient.c:807491
int _E79_76()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_74, "Noise");
  return atexit(_E80_74);
}

//----- (00714A70) --------------------------------------------------------  // acclient.c:807498
int _E82_52()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_74, "Sine");
  return atexit(_E83_50);
}

//----- (00714A90) --------------------------------------------------------  // acclient.c:807505
int _E85_38()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_74, "Square");
  return atexit(_E86_31);
}

//----- (00714AB0) --------------------------------------------------------  // acclient.c:807512
int _E88_28()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_74, "Bounce");
  return atexit(_E89_41);
}

//----- (00714AD0) --------------------------------------------------------  // acclient.c:807519
int sub_714AD0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_74, "Perlin");
  return atexit(_E92_46);
}

//----- (00714AF0) --------------------------------------------------------  // acclient.c:807526
int _E94_37()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_74, "Fractal");
  return atexit(sub_77ECF0);
}

//----- (00714B10) --------------------------------------------------------  // acclient.c:807533
int sub_714B10()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_74, "FrameLoop");
  return atexit(sub_77ED20);
}

//----- (0077EBA0) --------------------------------------------------------  // acclient.c:917830
void __cdecl _E74_98()
{
  char *v0; // esi@1

  v0 = &waveform_None_74.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_74.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077EBD0) --------------------------------------------------------  // acclient.c:917843
void __cdecl sub_77EBD0()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_74.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_74.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077EC00) --------------------------------------------------------  // acclient.c:917856
void __cdecl _E80_74()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_74.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_74.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077EC30) --------------------------------------------------------  // acclient.c:917869
void __cdecl _E83_50()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_74.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_74.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077EC60) --------------------------------------------------------  // acclient.c:917882
void __cdecl _E86_31()
{
  char *v0; // esi@1

  v0 = &waveform_Square_74.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_74.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077EC90) --------------------------------------------------------  // acclient.c:917895
void __cdecl _E89_41()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_74.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_74.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077ECC0) --------------------------------------------------------  // acclient.c:917908
void __cdecl _E92_46()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_74.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_74.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077ECF0) --------------------------------------------------------  // acclient.c:917921
void __cdecl sub_77ECF0()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_74.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_74.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077ED20) --------------------------------------------------------  // acclient.c:917934
void __cdecl sub_77ED20()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_74.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_74.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

