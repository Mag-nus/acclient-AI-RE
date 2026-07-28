/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : sounddev
   Object     : PORTAL\sound\sounddev.obj
   Functions  : 12
   Addresses  : 00552E10 - 007727A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00552E10) --------------------------------------------------------  // acclient.c:386174
BOOL __cdecl SoundOK()
{
  return pDirSound && CDirSound::DirectSoundOK(pDirSound);
}

//----- (00552E30) --------------------------------------------------------  // acclient.c:386180
CDirSound *__cdecl GetDirectSound()
{
  return pDirSound;
}

//----- (00552E40) --------------------------------------------------------  // acclient.c:386186
void __cdecl SoundCleanup()
{
  CDirSound *v0; // esi@2

  if ( pDirSound )
  {
    v0 = pDirSound;
    CDirSound::~CDirSound(pDirSound);
    operator delete(v0);
    pDirSound = 0;
  }
}

//----- (00552E70) --------------------------------------------------------  // acclient.c:386200
int __cdecl SoundSetup(HWND__ *hwnd)
{
  PSRefBufferCharData<char> *v1; // ecx@0
  HWND__ *v2; // edi@1
  HWND__ *v3; // esi@2
  char *v4; // esi@5
  int result; // eax@8
  CDirSound *v6; // esi@10
  CDirSound *v7; // eax@11
  CDirSound *v8; // eax@12
  PStringBase<char> errtitle; // [sp+4h] [bp-4h]@1

  errtitle.m_charbuffer = v1;
  v2 = hwnd;
  if ( !hwnd )
  {
    PStringBase<char>::PStringBase<char>(&errtitle, "SoundSetup Error");
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&hwnd,
      "SoundSetup requires a valid HWND!  Sound will be disabled.");
    Device::Error((PStringBase<char> *)&hwnd, &errtitle, (bool)v2);
    v3 = hwnd - 5;
    if ( !InterlockedDecrement((volatile LONG *)hwnd - 4) && v3 )
      (**(void (__thiscall ***)(HWND__ *, signed int))v3)(v3, 1);
    v4 = &errtitle.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&errtitle.m_charbuffer[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    }
    return 0;
  }
  if ( pDirSound )
  {
    v6 = pDirSound;
    CDirSound::~CDirSound(pDirSound);
    operator delete(v6);
    pDirSound = 0;
  }
  v7 = (CDirSound *)operator new(0x24u);
  if ( v7 )
  {
    CDirSound::CDirSound(v7, v2);
    pDirSound = v8;
    if ( !v8 || !CDirSound::DirectSoundOK(v8) )
      return 0;
    result = 1;
  }
  else
  {
    pDirSound = 0;
    result = 0;
  }
  return result;
}

//----- (00706E50) --------------------------------------------------------  // acclient.c:794147
int sub_706E50()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_29, "Display.Resolution");
  return atexit(_E74_77);
}

//----- (00706E70) --------------------------------------------------------  // acclient.c:794154
int _E76_63()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_29, "Display.FullScreen");
  return atexit(_E77_91);
}

//----- (00706E90) --------------------------------------------------------  // acclient.c:794161
int _E79_57()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_29, "Display.RefreshRate");
  return atexit(_E80_56);
}

//----- (00706EB0) --------------------------------------------------------  // acclient.c:794168
int _E82_38()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_29, "Display.SyncToRefresh");
  return atexit(_E83_36);
}

//----- (00772710) --------------------------------------------------------  // acclient.c:906367
void __cdecl _E74_77()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772740) --------------------------------------------------------  // acclient.c:906380
void __cdecl _E77_91()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772770) --------------------------------------------------------  // acclient.c:906393
void __cdecl _E80_56()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007727A0) --------------------------------------------------------  // acclient.c:906406
void __cdecl _E83_36()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

