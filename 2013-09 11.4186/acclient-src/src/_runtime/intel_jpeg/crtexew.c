/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : crtexew
   Object     : _runtime\intel_jpeg\crtexew.obj
   Functions  : 1
   Addresses  : 005DE03A - 005DE03A */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DE03A) --------------------------------------------------------  // acclient.c:521073
int __cdecl WinMainCRTStartup()
{
  HMODULE v0; // eax@1
  int v1; // ecx@2
  int v2; // eax@3
  int v3; // eax@7
  bool v4; // zf@7
  char *v5; // esi@15
  signed int v6; // eax@23
  int v7; // ST1C_4@27
  HMODULE v8; // eax@27
  int v9; // eax@27
  int v10; // esi@27
  _STARTUPINFOA StartupInfo; // [sp+14h] [bp-78h]@22
  char *lpszCommandLine; // [sp+58h] [bp-34h]@15
  int argret; // [sp+5Ch] [bp-30h]@13
  int argc; // [sp+60h] [bp-2Ch]@13
  char **argv; // [sp+64h] [bp-28h]@13
  char **envp; // [sp+68h] [bp-24h]@13
  _startupinfo startinfo; // [sp+6Ch] [bp-20h]@13
  int managedapp; // [sp+70h] [bp-1Ch]@5
  CPPEH_RECORD ms_exc; // [sp+74h] [bp-18h]@11

  v0 = GetModuleHandleA(0);
  if ( *(_WORD *)v0 != 23117 )
    goto LABEL_5;
  v1 = (int)((char *)v0 + *((_DWORD *)v0 + 15));
  if ( *(_DWORD *)v1 != 17744 )
    goto LABEL_5;
  v2 = *(_WORD *)(v1 + 24);
  if ( v2 == 267 )
  {
    if ( *(_DWORD *)(v1 + 116) > 0xEu )
    {
      v3 = 0;
      v4 = *(_DWORD *)(v1 + 232) == 0;
      goto LABEL_10;
    }
LABEL_5:
    managedapp = 0;
    goto LABEL_11;
  }
  if ( v2 != 523 || *(_DWORD *)(v1 + 132) <= 0xEu )
    goto LABEL_5;
  v3 = 0;
  v4 = *(_DWORD *)(v1 + 248) == 0;
LABEL_10:
  LOBYTE(v3) = !v4;
  managedapp = v3;
LABEL_11:
  ms_exc.registration.TryLevel = 0;
  ___set_app_type(2);
  __onexitend = -1;
  __onexitbegin = -1;
  *(_DWORD *)___p__fmode() = _fmode;
  *(_DWORD *)___p__commode() = _commode;
  _adjust_fdiv = __adjust_fdiv;
  _RTC_Initialize();
  _setargv();
  if ( !__defaultmatherr )
    ___setusermatherr(_setargv);
  _setdefaultprecision();
  _initterm(&__xi_a, &__xi_z);
  atexit(_RTC_Terminate);
  startinfo.newmode = _newmode;
  argret = ___getmainargs(&argc, &argv, &envp, _dowildcard, &startinfo);
  if ( argret < 0 )
    _amsg_exit(8);
  _initterm(&__xc_a, &__xc_z);
  v5 = (char *)__acmdln;
  lpszCommandLine = (char *)__acmdln;
  if ( *(_BYTE *)__acmdln != 34 )
  {
    while ( (unsigned __int8)*v5 > 0x20u )
    {
      ++v5;
      lpszCommandLine = v5;
    }
    goto LABEL_20;
  }
  do
  {
    ++v5;
    lpszCommandLine = v5;
  }
  while ( *v5 && *v5 != 34 );
  if ( *v5 != 34 )
    goto LABEL_20;
  do
  {
    ++v5;
    lpszCommandLine = v5;
LABEL_20:
    ;
  }
  while ( *v5 && (unsigned __int8)*v5 <= 0x20u );
  StartupInfo.dwFlags = 0;
  GetStartupInfoA(&StartupInfo);
  if ( StartupInfo.dwFlags & 1 )
    v6 = StartupInfo.wShowWindow;
  else
    v6 = 10;
  v7 = v6;
  v8 = GetModuleHandleA(0);
  v9 = WinMain(v8, 0, v5, v7);
  v10 = v9;
  if ( !managedapp )
    _exit(v9);
  __cexit();
  return v10;
}
// 5DE5FA: using guessed type int __cdecl _amsg_exit(_DWORD);
// 5DE688: using guessed type int __cdecl _initterm(_DWORD, _DWORD);
// 7922F0: using guessed type int __cdecl ___set_app_type(_DWORD);
// 7922F4: using guessed type int ___p__fmode(void);
// 7922FC: using guessed type int ___p__commode(void);
// 79233C: using guessed type int __adjust_fdiv;
// 792340: using guessed type int __cdecl ___setusermatherr(_DWORD);
// 792348: using guessed type int __cdecl ___getmainargs(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 792350: using guessed type int __acmdln;
// 8241B0: using guessed type int __defaultmatherr;
// 8F195C: using guessed type int _dowildcard;
// 8F1960: using guessed type int _newmode;
// 8F1964: using guessed type int _commode;
// 9057C8: using guessed type int _adjust_fdiv;
// 9057CC: using guessed type int __onexitend;
// 9057D0: using guessed type int __onexitbegin;

