/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : failure
   Object     : _runtime\msvcrt\failure.obj
   Functions  : 21
   Addresses  : 004058B3 - 00405ACE */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004058B3) --------------------------------------------------------  // acclient.c:64472
signed int __stdcall GodotFailCreateFileW(const unsigned __int16 *lpFileName, unsigned int dwDesiredAccess, unsigned int dwShareMode, _SECURITY_ATTRIBUTES *lpSecurityAttributes, unsigned int dwCreationDisposition, unsigned int dwFlagsAndAttributes, void *hTemplateFile)
{
  SetLastError(0x78u);
  return -1;
}

//----- (004058C1) --------------------------------------------------------  // acclient.c:64479
HFONT__ *__stdcall GodotFailCreateFontIndirectW(tagLOGFONTW *_noname0)
{
  SetLastError(0x78u);
  return 0;
}

//----- (004058CE) --------------------------------------------------------  // acclient.c:64486
int __stdcall GodotFailFindResourceW(HINSTANCE__ *_p1, const unsigned __int16 *_p2, const unsigned __int16 *_p3)
{
  HMODULE v3; // eax@1
  int v4; // eax@1
  int result; // eax@2

  v3 = GetModuleHandleA("kernel32.dll");
  v4 = GetProcAddressInternal(v3, "FindResourceW");
  if ( v4 )
  {
    result = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))v4)(_p1, _p2, _p3);
  }
  else
  {
    SetLastError(0x7Fu);
    result = 0;
  }
  return result;
}

//----- (004058F7) --------------------------------------------------------  // acclient.c:64507
int __stdcall GodotFailGetEnvironmentVariableW(void *_noname0, int _noname1, void *_noname2)
{
  SetLastError(0x78u);
  return 0;
}

//----- (00405909) --------------------------------------------------------  // acclient.c:64514
int __stdcall GodotFailVerQueryValueW(void *const pBlock, unsigned __int16 *lpSubBlock, void **lplpBuffer, unsigned int *puLen)
{
  SetLastError(0x78u);
  return 0;
}

//----- (00405916) --------------------------------------------------------  // acclient.c:64521
int __stdcall GodotFaillstrcatW(unsigned __int16 *_p1, const unsigned __int16 *_p2)
{
  HMODULE v2; // eax@1
  int v3; // eax@1
  int result; // eax@2

  v2 = GetModuleHandleA("kernel32.dll");
  v3 = GetProcAddressInternal(v2, "lstrcatW");
  if ( v3 )
  {
    result = ((int (__stdcall *)(_DWORD, _DWORD))v3)(_p1, _p2);
  }
  else
  {
    SetLastError(0x7Fu);
    result = 0;
  }
  return result;
}

//----- (0040593F) --------------------------------------------------------  // acclient.c:64542
int __stdcall GodotFaillstrlenW(const unsigned __int16 *_p1)
{
  HMODULE v1; // eax@1
  int v2; // eax@1
  int result; // eax@2

  v1 = GetModuleHandleA("kernel32.dll");
  v2 = GetProcAddressInternal(v1, "lstrlenW");
  if ( v2 )
  {
    result = ((int (__stdcall *)(const unsigned __int16 *))v2)(_p1);
  }
  else
  {
    SetLastError(0x7Fu);
    result = 0;
  }
  return result;
}

//----- (00405968) --------------------------------------------------------  // acclient.c:64563
int __stdcall GodotFailGetCurrentDirectoryW(HDC__ *_noname0, tagTEXTMETRICW *_noname1)
{
  SetLastError(0x78u);
  return 0;
}

//----- (00405975) --------------------------------------------------------  // acclient.c:64570
int __stdcall GodotFailMultiByteToWideChar(unsigned int _p1, unsigned int _p2, const char *_p3, int _p4, unsigned __int16 *_p5, int _p6)
{
  HMODULE v6; // eax@1
  int v7; // eax@1
  int result; // eax@2

  v6 = GetModuleHandleA("kernel32.dll");
  v7 = GetProcAddressInternal(v6, "MultiByteToWideChar");
  if ( v7 )
  {
    result = ((int (__stdcall *)(unsigned int, unsigned int, const char *, int, unsigned __int16 *, int))v7)(
               _p1,
               _p2,
               _p3,
               _p4,
               _p5,
               _p6);
  }
  else
  {
    SetLastError(0x7Fu);
    result = 0;
  }
  return result;
}

//----- (004059A3) --------------------------------------------------------  // acclient.c:64597
int __stdcall GodotFailWideCharToMultiByte(unsigned int _p1, unsigned int _p2, const unsigned __int16 *_p3, int _p4, char *_p5, int _p6, const char *_p7, int *_p8)
{
  HMODULE v8; // eax@1
  int v9; // eax@1
  int result; // eax@2

  v8 = GetModuleHandleA("kernel32.dll");
  v9 = GetProcAddressInternal(v8, "WideCharToMultiByte");
  if ( v9 )
  {
    result = ((int (__stdcall *)(unsigned int, unsigned int, const unsigned __int16 *, int, char *, int, const char *, int *))v9)(
               _p1,
               _p2,
               _p3,
               _p4,
               _p5,
               _p6,
               _p7,
               _p8);
  }
  else
  {
    SetLastError(0x7Fu);
    result = 0;
  }
  return result;
}

//----- (004059D1) --------------------------------------------------------  // acclient.c:64626
int __stdcall GodotFailGetClipboardData(unsigned int _p1)
{
  HMODULE v1; // eax@1
  int v2; // eax@1
  int result; // eax@2

  v1 = GetModuleHandleA("user32.dll");
  v2 = GetProcAddressInternal(v1, "GetClipboardData");
  if ( v2 )
  {
    result = ((int (__stdcall *)(_DWORD))v2)(_p1);
  }
  else
  {
    SetLastError(0x7Fu);
    result = 0;
  }
  return result;
}

//----- (004059FA) --------------------------------------------------------  // acclient.c:64647
int __stdcall GodotFailIsClipboardFormatAvailable(unsigned int _p1)
{
  HMODULE v1; // eax@1
  int v2; // eax@1
  int result; // eax@2

  v1 = GetModuleHandleA("user32.dll");
  v2 = GetProcAddressInternal(v1, "IsClipboardFormatAvailable");
  if ( v2 )
  {
    result = ((int (__stdcall *)(unsigned int))v2)(_p1);
  }
  else
  {
    SetLastError(0x7Fu);
    result = 0;
  }
  return result;
}

//----- (00405A23) --------------------------------------------------------  // acclient.c:64668
int __stdcall GodotFailMessageBoxW(HWND__ *_p1, const unsigned __int16 *_p2, const unsigned __int16 *_p3, unsigned int _p4)
{
  HMODULE v4; // eax@1
  int v5; // eax@1
  int result; // eax@2

  v4 = GetModuleHandleA("user32.dll");
  v5 = GetProcAddressInternal(v4, "MessageBoxW");
  if ( v5 )
  {
    result = ((int (__stdcall *)(HWND__ *, const unsigned __int16 *, const unsigned __int16 *, unsigned int))v5)(
               _p1,
               _p2,
               _p3,
               _p4);
  }
  else
  {
    SetLastError(0x7Fu);
    result = 0;
  }
  return result;
}

//----- (00405A4C) --------------------------------------------------------  // acclient.c:64693
int __stdcall GodotFailSetWindowLongA(HWND__ *_p1, int _p2, int _p3)
{
  HMODULE v3; // eax@1
  int v4; // eax@1
  int result; // eax@2

  v3 = GetModuleHandleA("user32.dll");
  v4 = GetProcAddressInternal(v3, "SetWindowLongA");
  if ( v4 )
  {
    result = ((int (__stdcall *)(HWND__ *, int, int))v4)(_p1, _p2, _p3);
  }
  else
  {
    SetLastError(0x7Fu);
    result = 0;
  }
  return result;
}

//----- (00405A75) --------------------------------------------------------  // acclient.c:64714
int GodotFailwsprintfW()
{
  SetLastError(0x78u);
  return -1;
}

//----- (00405A81) --------------------------------------------------------  // acclient.c:64721
int __stdcall GodotFailExtTextOutW(HDC__ *_p1, int _p2, int _p3, unsigned int _p4, tagRECT *const _p5, const unsigned __int16 *_p6, unsigned int _p7, int *const _p8)
{
  HMODULE v8; // eax@1
  int v9; // eax@1
  int result; // eax@2

  v8 = GetModuleHandleA("gdi32.dll");
  v9 = GetProcAddressInternal(v8, "ExtTextOutW");
  if ( v9 )
  {
    result = ((int (__stdcall *)(HDC__ *, int, int, unsigned int, tagRECT *const , const unsigned __int16 *, unsigned int, int *const ))v9)(
               _p1,
               _p2,
               _p3,
               _p4,
               _p5,
               _p6,
               _p7,
               _p8);
  }
  else
  {
    SetLastError(0x7Fu);
    result = 0;
  }
  return result;
}

//----- (00405AAF) --------------------------------------------------------  // acclient.c:64750
unsigned int __stdcall GodotFailGetCharacterPlacementW(HDC__ *_noname0, const unsigned __int16 *_noname1, int _noname2, int _noname3, tagGCP_RESULTSW *_noname4, unsigned int _noname5)
{
  SetLastError(0x78u);
  return 0;
}

//----- (00405ABC) --------------------------------------------------------  // acclient.c:64757
int __stdcall GodotFailRegCreateKeyExW(HKEY__ *_p1, const unsigned __int16 *_p2, unsigned int _p3, unsigned __int16 *_p4, unsigned int _p5, unsigned int _p6, _SECURITY_ATTRIBUTES *_p7, HKEY__ **_p8, unsigned int *_p9)
{
  return 120;
}

//----- (00405AC2) --------------------------------------------------------  // acclient.c:64763
int __stdcall GodotFailRegEnumValueW(HKEY__ *_p1, unsigned int _p2, unsigned __int16 *_p3, unsigned int *_p4, unsigned int *_p5, unsigned int *_p6, char *_p7, unsigned int *_p8)
{
  return 120;
}

//----- (00405AC8) --------------------------------------------------------  // acclient.c:64769
int __stdcall GodotFailRegOpenKeyExW(HKEY__ *_p1, const unsigned __int16 *_p2, unsigned int _p3, unsigned int _p4, HKEY__ **_p5)
{
  return 120;
}

//----- (00405ACE) --------------------------------------------------------  // acclient.c:64775
int __stdcall GodotFailRegQueryValueExW(HKEY__ *_p1, const unsigned __int16 *_p2, unsigned int _p3, unsigned int _p4, const char *_p5, unsigned int _p6)
{
  return 120;
}

