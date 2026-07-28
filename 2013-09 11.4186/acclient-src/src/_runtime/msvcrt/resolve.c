/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : resolve
   Object     : _runtime\msvcrt\resolve.obj
   Functions  : 8
   Addresses  : 00405285 - 00405760 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00405285) --------------------------------------------------------  // acclient.c:64089
unsigned __int16 __stdcall GetOrdinal(char *Name, unsigned int cNames, void *DllBase, unsigned int *NameTable, unsigned __int16 *NameOrdinalTable)
{
  int v5; // ecx@1
  int v6; // esi@2
  int v7; // eax@2
  unsigned __int16 result; // ax@8
  int Low; // [sp+4h] [bp-4h]@1

  Low = 0;
  v5 = cNames - 1;
  if ( ((cNames - 1) & 0x80000000) != 0 )
    goto LABEL_12;
  do
  {
    v6 = (v5 + Low) >> 1;
    v7 = strcmp(Name, (const char *)DllBase + NameTable[v6]);
    if ( v7 >= 0 )
    {
      if ( v7 <= 0 )
        break;
      Low = v6 + 1;
    }
    else
    {
      v5 = v6 - 1;
    }
  }
  while ( v5 >= Low );
  if ( v5 >= Low )
    result = NameOrdinalTable[v6];
  else
LABEL_12:
    result = -1;
  return result;
}

//----- (00405302) --------------------------------------------------------  // acclient.c:64126
char *__stdcall ImageEntryToDataC(void *Base, unsigned __int16 Entry, unsigned int *Size)
{
  char *v3; // eax@1
  int v4; // edx@3
  char *result; // eax@4

  v3 = (char *)Base + *((_DWORD *)Base + 15);
  if ( v3 && (unsigned int)Entry < *((_DWORD *)v3 + 29) && (v4 = *(_DWORD *)&v3[8 * Entry + 120]) != 0 )
  {
    *Size = *(_DWORD *)&v3[8 * Entry + 124];
    result = (char *)Base + v4;
  }
  else
  {
    *Size = 0;
    result = 0;
  }
  return result;
}

//----- (0040533C) --------------------------------------------------------  // acclient.c:64147
BOOL __stdcall strcmpiC(char *sz1, char *sz2)
{
  return CompareStringA(0x409u, 1u, sz1, -1, sz2, -1) == 2;
}

//----- (0040535F) --------------------------------------------------------  // acclient.c:64153
char *__stdcall strncpyC(char *dest, const char *source, unsigned int count)
{
  unsigned int v3; // ecx@1
  char *v4; // edi@1
  const char *v5; // edx@2
  const char v6; // al@3
  unsigned int v7; // ecx@6

  v3 = count;
  v4 = dest;
  if ( count )
  {
    v5 = source;
    do
    {
      v6 = *v5;
      *v4++ = *v5++;
      if ( !v6 )
        break;
      --v3;
    }
    while ( v3 );
    if ( v3 )
    {
      v7 = v3 - 1;
      if ( v7 )
        memset(v4, 0, v7);
    }
  }
  return dest;
}

//----- (0040539E) --------------------------------------------------------  // acclient.c:64186
int __stdcall GetProcAddressInternal(HINSTANCE__ *hDll, char *szName)
{
  HINSTANCE__ *v2; // edi@1
  char *v3; // eax@3
  unsigned int v4; // esi@3
  int v5; // eax@4
  int result; // eax@5

  v2 = hDll;
  if ( !hDll
    || !szName
    || (v3 = ImageEntryToDataC(hDll, 0, (unsigned int *)&hDll), (v4 = (unsigned int)v3) == 0)
    || (v5 = GetOrdinal(
               szName,
               *((_DWORD *)v3 + 6),
               v2,
               (unsigned int *)((char *)v2 + *((_DWORD *)v3 + 8)),
               (unsigned __int16 *)((char *)v2 + *((_DWORD *)v3 + 9))),
        (unsigned int)(unsigned __int16)v5 >= *(_DWORD *)(v4 + 20))
    || (result = (int)((char *)v2 + *(_DWORD *)((char *)v2 + 4 * v5 + *(_DWORD *)(v4 + 28))), result > v4)
    && result < (unsigned int)((char *)hDll + v4) )
    result = 0;
  return result;
}

//----- (00405402) --------------------------------------------------------  // acclient.c:64212
void __stdcall driveandpathC(const char *path, char *drive, char *dir)
{
  const char *v3; // ebx@1
  const char v4; // cl@8
  int v5; // eax@8
  const char *v6; // edx@8
  unsigned int v7; // esi@15

  v3 = path;
  if ( strlen(path) < 1 || path[1] != 58 )
  {
    if ( drive )
      *drive = 0;
  }
  else
  {
    if ( drive )
    {
      strncpyC(drive, path, 2u);
      drive[2] = 0;
    }
    v3 = path + 2;
  }
  v4 = *v3;
  v5 = 0;
  v6 = v3;
  if ( !*v3 )
    goto LABEL_22;
  do
  {
    if ( v4 == 47 || v4 == 92 )
      v5 = (int)(v6 + 1);
    ++v6;
    v4 = *v6;
  }
  while ( *v6 );
  if ( v5 )
  {
    if ( dir )
    {
      v7 = v5 - (_DWORD)v3;
      if ( (unsigned int)(v5 - (_DWORD)v3) > 0xFF )
        v7 = 255;
      strncpyC(dir, v3, v7);
      dir[v7] = 0;
    }
  }
  else
  {
LABEL_22:
    if ( dir )
      *dir = 0;
  }
}

//----- (0040549D) --------------------------------------------------------  // acclient.c:64268
HINSTANCE__ *__stdcall LoadGodot()
{
  HMODULE v0; // eax@10
  HMODULE v1; // esi@18
  int v2; // esi@21
  int v3; // eax@21
  int v4; // edi@21
  unsigned int v5; // eax@25
  void *v6; // edi@25
  char v7; // cl@26
  void *v8; // edi@27
  char *v9; // esi@27
  char v10; // cl@27
  LPCSTR v11; // eax@27
  LPCSTR v12; // ecx@27
  char v13; // dl@28
  unsigned int v14; // eax@29
  const void *v15; // esi@29
  void *v16; // edi@29
  char v17; // cl@30
  char szSystemPath[261]; // [sp+4h] [bp-52Ch]@4
  char szWindowsPath[261]; // [sp+10Ch] [bp-424h]@6
  char dir[256]; // [sp+214h] [bp-31Ch]@12
  char szGodotPath[261]; // [sp+314h] [bp-21Ch]@8
  char v23; // [sp+41Bh] [bp-115h]@25
  char szName[261]; // [sp+41Ch] [bp-114h]@10
  unsigned int cb; // [sp+524h] [bp-Ch]@24
  HINSTANCE__ *hMod; // [sp+528h] [bp-8h]@2
  HKEY__ *hkey; // [sp+52Ch] [bp-4h]@12

  if ( !_PfnLoadUnicows || (hMod = (HINSTANCE__ *)_PfnLoadUnicows()) == 0 )
  {
    hMod = LoadLibraryA(m_rgDLLMap);
    if ( !hMod )
      goto LABEL_36;
    if ( !GetSystemDirectoryA(szSystemPath, 0x104u) )
      szSystemPath[0] = 0;
    if ( !GetWindowsDirectoryA(szWindowsPath, 0x104u) )
      szWindowsPath[0] = 0;
    if ( !GetModuleFileNameA(hMod, szGodotPath, 0x104u) )
      szGodotPath[0] = 0;
    v0 = GetModuleHandleA(0);
    if ( !GetModuleFileNameA(v0, szName, 0x104u) )
      szName[0] = 0;
    driveandpathC(szName, (char *)&hkey, dir);
    *(&szName[strlen((const char *)&hkey) + 1] + strlen(dir)) = 0;
    driveandpathC(szGodotPath, (char *)&hkey, dir);
    *(&szGodotPath[strlen((const char *)&hkey) + 1] + strlen(dir)) = 0;
    if ( !strcmpiC(szWindowsPath, szGodotPath) && strcmpiC(szWindowsPath, szName)
      || !strcmpiC(szSystemPath, szGodotPath) && strcmpiC(szSystemPath, szName) )
    {
      FreeLibrary(hMod);
      hMod = 0;
    }
    if ( !hMod )
    {
LABEL_36:
      hkey = 0;
      v1 = LoadLibraryA("advapi32.dll");
      if ( InterlockedExchange(&hDll, (LONG)v1) )
        FreeLibrary(v1);
      if ( hDll )
      {
        v2 = GetProcAddressInternal((HINSTANCE__ *)hDll, "RegOpenKeyExA");
        v3 = GetProcAddressInternal((HINSTANCE__ *)hDll, "RegQueryValueExA");
        v4 = v3;
        if ( v2 )
        {
          if ( v3
            && !((int (__stdcall *)(signed int, _DWORD, _DWORD, signed int, HKEY__ **))v2)(
                  -2147483646,
                  "SOFTWARE\\Microsoft\\Windows\\CurrentVersion",
                  0,
                  1,
                  &hkey) )
          {
            cb = 260;
            szName[0] = 0;
            if ( !((int (__stdcall *)(HKEY__ *, _DWORD, _DWORD, _DWORD, char *, unsigned int *))v4)(
                    hkey,
                    "CommonFilesDir",
                    0,
                    0,
                    szName,
                    &cb) )
            {
              v5 = strlen("\\Microsoft Shared\\MSLU\\") + 1;
              v6 = &v23;
              do
              {
                v7 = *((_BYTE *)v6 + 1);
                v6 = (char *)v6 + 1;
              }
              while ( v7 );
              qmemcpy(v6, "\\Microsoft Shared\\MSLU\\", 4 * (v5 >> 2));
              v9 = &c_szPath[4 * (v5 >> 2)];
              v8 = (char *)v6 + 4 * (v5 >> 2);
              v10 = v5;
              v11 = m_rgDLLMap;
              qmemcpy(v8, v9, v10 & 3);
              v12 = v11;
              do
                v13 = *v11++;
              while ( v13 );
              v14 = v11 - v12;
              v15 = v12;
              v16 = &v23;
              do
              {
                v17 = *((_BYTE *)v16 + 1);
                v16 = (char *)v16 + 1;
              }
              while ( v17 );
              qmemcpy(v16, v15, v14);
              hMod = LoadLibraryA(szName);
            }
            RegCloseKey(hkey);
          }
        }
      }
    }
  }
  return hMod;
}
// 9057C0: using guessed type int (*_PfnLoadUnicows)(void);

//----- (00405760) --------------------------------------------------------  // acclient.c:64395
void __stdcall ResolveThunk(char *Name, char *Function, int (__stdcall **Ptr)(), int (__stdcall *Override)(), int (__stdcall *FailPtr)())
{
  signed int v5; // edi@3
  const char *v6; // eax@8
  volatile LONG *v7; // esi@13
  HMODULE v8; // edi@14
  LONG v9; // eax@19
  HMODULE v10; // esi@19
  int (__stdcall *v11)(); // eax@16
  _MEMORY_BASIC_INFORMATION mbi; // [sp+Ch] [bp-1Ch]@7

  if ( UniPlatform == PlatformUntested )
  {
    if ( GetVersion() < 0x80000000 )
    {
      v5 = 1;
      UniPlatform = 1;
      goto LABEL_6;
    }
    UniPlatform = 2;
  }
  v5 = 1;
  if ( UniPlatform != 1 )
  {
    v11 = Override;
    if ( !Override )
    {
      if ( !dword_8172A4 )
      {
        v9 = (LONG)LoadGodot();
        v10 = (HMODULE)v9;
        if ( v9 && InterlockedExchange(&dword_8172A4, v9) )
          FreeLibrary(v10);
        if ( !dword_8172A4 )
          goto LABEL_11;
      }
      v11 = (int (__stdcall *)())GetProcAddressInternal((HINSTANCE__ *)dword_8172A4, Function);
    }
    goto LABEL_24;
  }
LABEL_6:
  if ( !m_hinst )
  {
    VirtualQuery(ResolveThunk, &mbi, 0x1Cu);
    m_hinst = mbi.AllocationBase;
  }
  v6 = off_8172A8;
  if ( !off_8172A8 )
    goto LABEL_11;
  while ( strcmp(Name, v6) )
  {
    v6 = (&off_8172A8)[8 * v5++];
    if ( !v6 )
      goto LABEL_11;
  }
  v7 = &dword_8172A4 + 2 * v5;
  if ( !*v7 )
  {
    v8 = LoadLibraryA(Name);
    if ( InterlockedExchange(v7, (LONG)v8) )
      FreeLibrary(v8);
  }
  v11 = (int (__stdcall *)())GetProcAddressInternal(*(HINSTANCE__ **)v7, Function);
LABEL_24:
  if ( v11 )
  {
    InterlockedExchange((volatile LONG *)Ptr, (LONG)v11);
    goto LABEL_12;
  }
LABEL_11:
  InterlockedExchange((volatile LONG *)Ptr, (LONG)FailPtr);
LABEL_12:
  FlushInstructionCache(m_hinst, Ptr, 4u);
}
// 8172A8: using guessed type char *off_8172A8;

