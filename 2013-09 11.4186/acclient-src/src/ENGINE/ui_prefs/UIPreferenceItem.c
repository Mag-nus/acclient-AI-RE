/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIPreferenceItem
   Object     : ENGINE\ui_prefs\UIPreferenceItem.obj
   Functions  : 19
   Addresses  : 005DDE90 - 0077EB70 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DDE90) --------------------------------------------------------  // acclient.c:520963
char __thiscall UIPreferenceItem::Initialize(UIPreferenceItem *this, PStringBase<char> *i_strPreference, const unsigned int i_dataType, const unsigned int i_eStringTable, const unsigned int i_tokenDisplay, const unsigned int i_tokenTooltip)
{
  PStringBase<char> *v6; // edi@1
  UIPreferenceItem *v7; // esi@1
  PStringBase<char> *v8; // esi@2
  char result; // al@5
  PSRefBufferCharData<char> *v10; // ebx@6
  int v11; // ebx@7
  PSRefBufferCharData<char> *v12; // edi@10
  const unsigned int v13; // ecx@11
  const unsigned int v14; // edx@11

  v6 = i_strPreference;
  v7 = this;
  if ( UserPreferences::IsPreferenceRegistered(i_strPreference, 0) )
  {
    v10 = v7->m_strPreference.m_charbuffer;
    if ( v10 != v6->m_charbuffer )
    {
      v11 = (int)&v10[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)(v11 + 4)) && v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      v12 = v6->m_charbuffer;
      v7->m_strPreference.m_charbuffer = v12;
      InterlockedIncrement((volatile LONG *)&v12[-1]);
    }
    v13 = i_eStringTable;
    v14 = i_tokenDisplay;
    v7->m_dataType = i_dataType;
    v7->m_tokenTooltip = i_tokenTooltip;
    v7->m_eStringTable = v13;
    v7->m_tokenPreference = v14;
    result = 1;
  }
  else
  {
    i_strPreference = (PStringBase<char> *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::sprintf(
      (PStringBase<char> *)&i_strPreference,
      "UIPreferenceItem::Initialize: Attempted to initialize [%s] but the preference has not been registered!\n",
      v6->m_charbuffer);
    v8 = i_strPreference - 5;
    if ( !InterlockedDecrement((volatile LONG *)&i_strPreference[-4]) )
    {
      if ( v8 )
        (*(void (__thiscall **)(_DWORD, _DWORD))&v8->m_charbuffer->m_data[0])(v8, 1);
    }
    result = 0;
  }
  return result;
}

//----- (007148F0) --------------------------------------------------------  // acclient.c:807414
int sub_7148F0()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_73, "None");
  return atexit(_E74_97);
}

//----- (00714910) --------------------------------------------------------  // acclient.c:807421
int _E76_80()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_73, "Speed");
  return atexit(sub_77EA20);
}

//----- (00714930) --------------------------------------------------------  // acclient.c:807428
int _E79_75()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_73, "Noise");
  return atexit(_E80_73);
}

//----- (00714950) --------------------------------------------------------  // acclient.c:807435
int _E82_51()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_73, "Sine");
  return atexit(_E83_49);
}

//----- (00714970) --------------------------------------------------------  // acclient.c:807442
int _E85_37()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_73, "Square");
  return atexit(_E86_30);
}

//----- (00714990) --------------------------------------------------------  // acclient.c:807449
int _E88_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_73, "Bounce");
  return atexit(_E89_40);
}

//----- (007149B0) --------------------------------------------------------  // acclient.c:807456
int sub_7149B0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_73, "Perlin");
  return atexit(_E92_45);
}

//----- (007149D0) --------------------------------------------------------  // acclient.c:807463
int _E94_36()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_73, "Fractal");
  return atexit(sub_77EB40);
}

//----- (007149F0) --------------------------------------------------------  // acclient.c:807470
int sub_7149F0()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_73, "FrameLoop");
  return atexit(sub_77EB70);
}

//----- (0077E9F0) --------------------------------------------------------  // acclient.c:917713
void __cdecl _E74_97()
{
  char *v0; // esi@1

  v0 = &waveform_None_73.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_73.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077EA20) --------------------------------------------------------  // acclient.c:917726
void __cdecl sub_77EA20()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_73.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_73.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077EA50) --------------------------------------------------------  // acclient.c:917739
void __cdecl _E80_73()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_73.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_73.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077EA80) --------------------------------------------------------  // acclient.c:917752
void __cdecl _E83_49()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_73.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_73.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077EAB0) --------------------------------------------------------  // acclient.c:917765
void __cdecl _E86_30()
{
  char *v0; // esi@1

  v0 = &waveform_Square_73.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_73.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077EAE0) --------------------------------------------------------  // acclient.c:917778
void __cdecl _E89_40()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_73.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_73.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077EB10) --------------------------------------------------------  // acclient.c:917791
void __cdecl _E92_45()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_73.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_73.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077EB40) --------------------------------------------------------  // acclient.c:917804
void __cdecl sub_77EB40()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_73.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_73.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077EB70) --------------------------------------------------------  // acclient.c:917817
void __cdecl sub_77EB70()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_73.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_73.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

