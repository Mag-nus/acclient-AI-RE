/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ContextMenu
   Object     : ENGINE\uielement_util_context\ContextMenu.obj
   Functions  : 26
   Addresses  : 00474B70 - 0075EBC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00474B70) --------------------------------------------------------  // acclient.c:177787
char __thiscall ContextMenu::Close(ContextMenu *this)
{
  ContextMenu *v1; // esi@1
  char result; // al@2
  unsigned int v3; // ebp@3
  char v4; // bl@3
  int v5; // edi@4
  ContextMenu *v6; // ecx@5
  UIElement *v7; // ecx@9

  v1 = this;
  if ( this->m_open )
  {
    v3 = 0;
    v4 = 1;
    if ( this->m_data.m_num )
    {
      v5 = 0;
      do
      {
        v6 = v1->m_data.m_data[v5].m_subMenu;
        if ( v6 && v6->m_open )
        {
          v1->m_pOpenSubMenu = 0;
          ContextMenu::Close(v6);
          v4 = 0;
        }
        ++v3;
        ++v5;
      }
      while ( v3 < v1->m_data.m_num );
    }
    v7 = v1->m_display;
    if ( v7 )
    {
      ((void (__stdcall *)(_DWORD))v7->vfptr[2].__vecDelDtor)(0);
      if ( v1->m_bTopLevel )
        ((void (__stdcall *)(_DWORD))v1->m_pRoot->vfptr[2].__vecDelDtor)(0);
      result = v4;
      v1->m_open = 0;
    }
    else
    {
      v1->m_open = 0;
      result = 0;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (00474C30) --------------------------------------------------------  // acclient.c:177842
void __thiscall ContextMenu::SetVisible(ContextMenu *this, int _visible)
{
  ContextMenu *v2; // esi@1
  UIElement *v3; // ecx@4

  v2 = this;
  if ( this->m_open && !(_BYTE)_visible )
    ContextMenu::Close(this);
  v3 = v2->m_pRoot;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr[2].__vecDelDtor)(_visible);
}

//----- (006EC1A0) --------------------------------------------------------  // acclient.c:767933
int _E73_77()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_14, "Misc.TooltipEnable");
  return atexit(_E74_58);
}

//----- (006EC1C0) --------------------------------------------------------  // acclient.c:767940
int _E76_44()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_14, "Misc.TooltipDelay");
  return atexit(_E77_72);
}

//----- (006EC1E0) --------------------------------------------------------  // acclient.c:767947
void _E79_37()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_46, PFID_A8R8G8B8);
}

//----- (006EC1F0) --------------------------------------------------------  // acclient.c:767953
int _E97_36()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_33, "None");
  return atexit(_E98_48);
}

//----- (006EC210) --------------------------------------------------------  // acclient.c:767960
int _E100_28()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_33, "Speed");
  return atexit(_E101_66);
}

//----- (006EC230) --------------------------------------------------------  // acclient.c:767967
int _E103_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_33, "Noise");
  return atexit(_E104_36);
}

//----- (006EC250) --------------------------------------------------------  // acclient.c:767974
int _E106_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_33, "Sine");
  return atexit(_E107_68);
}

//----- (006EC270) --------------------------------------------------------  // acclient.c:767981
int _E109_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_33, "Square");
  return atexit(sub_75EB00);
}

//----- (006EC290) --------------------------------------------------------  // acclient.c:767988
int _E112_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_33, "Bounce");
  return atexit(_E113_47);
}

//----- (006EC2B0) --------------------------------------------------------  // acclient.c:767995
int _E115_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_33, "Perlin");
  return atexit(_E116_39);
}

//----- (006EC2D0) --------------------------------------------------------  // acclient.c:768002
int _E118_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_33, "Fractal");
  return atexit(_E119_71);
}

//----- (006EC2F0) --------------------------------------------------------  // acclient.c:768009
int _E121_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_33, "FrameLoop");
  return atexit(_E122_58);
}

//----- (006EC310) --------------------------------------------------------  // acclient.c:768016
int _E1_74()
{
  return atexit(_E2_74);
}

//----- (0075E9E0) --------------------------------------------------------  // acclient.c:886852
void __cdecl _E74_58()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EA10) --------------------------------------------------------  // acclient.c:886865
void __cdecl _E77_72()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EA40) --------------------------------------------------------  // acclient.c:886878
void __cdecl _E98_48()
{
  char *v0; // esi@1

  v0 = &waveform_None_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EA70) --------------------------------------------------------  // acclient.c:886891
void __cdecl _E101_66()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EAA0) --------------------------------------------------------  // acclient.c:886904
void __cdecl _E104_36()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EAD0) --------------------------------------------------------  // acclient.c:886917
void __cdecl _E107_68()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EB00) --------------------------------------------------------  // acclient.c:886930
void __cdecl sub_75EB00()
{
  char *v0; // esi@1

  v0 = &waveform_Square_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EB30) --------------------------------------------------------  // acclient.c:886943
void __cdecl _E113_47()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EB60) --------------------------------------------------------  // acclient.c:886956
void __cdecl _E116_39()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EB90) --------------------------------------------------------  // acclient.c:886969
void __cdecl _E119_71()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075EBC0) --------------------------------------------------------  // acclient.c:886982
void __cdecl _E122_58()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

