/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Resource
   Object     : PORTAL\pversion\Resource.obj
   Functions  : 5
   Addresses  : 00554E40 - 005550F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00554E40) --------------------------------------------------------  // acclient.c:388087
DWORD __cdecl AC1Legacy::Resource::LoadData(char *fpFileName)
{
  unsigned int v1; // ecx@0
  unsigned int v2; // eax@1
  DWORD v3; // esi@1
  unsigned int dwHandle; // [sp+0h] [bp-4h]@1

  dwHandle = v1;
  v2 = GetFileVersionInfoSizeA(fpFileName, &dwHandle);
  v3 = v2;
  if ( v2 )
  {
    AC1Legacy::Resource::abData = operator new[](v2);
    GetFileVersionInfoA(fpFileName, dwHandle, v3, AC1Legacy::Resource::abData);
  }
  return v3;
}

//----- (00554E80) --------------------------------------------------------  // acclient.c:388106
DWORD __cdecl AC1Legacy::Resource::Init(const char *fname)
{
  char *v1; // edi@4
  char v2; // al@5
  int v3; // edx@8
  char *v4; // eax@8
  char v5; // cl@11
  unsigned int v6; // eax@12
  DWORD v7; // esi@12
  DWORD result; // eax@14
  char *v9; // edi@16
  char v10; // al@17
  unsigned int v11; // eax@18
  char *v12; // edi@18
  char v13; // cl@19
  unsigned int v14; // eax@20
  DWORD v15; // esi@20
  unsigned int dwHandle; // [sp+0h] [bp-508h]@12
  char fullFileName[260]; // [sp+4h] [bp-504h]@4
  char buff[1024]; // [sp+108h] [bp-400h]@3

  if ( AC1Legacy::Resource::abData )
    operator delete(AC1Legacy::Resource::abData);
  strcpy(buff, fname);
  if ( !_strchr(buff, 46) )
  {
    v1 = &fullFileName[259];
    do
      v2 = (v1++)[1];
    while ( v2 );
    *(_DWORD *)v1 = *(_DWORD *)".exe";
    v1[4] = 0;
  }
  if ( _strchr(buff, 34) )
  {
    v3 = 0;
    v4 = buff;
    if ( buff[0] )
    {
      do
      {
        if ( *v4 != 34 )
          fullFileName[v3++] = *v4;
        v5 = (v4++)[1];
      }
      while ( v5 );
    }
    fullFileName[v3] = 0;
    v6 = GetFileVersionInfoSizeA(fullFileName, &dwHandle);
    v7 = v6;
    if ( v6 )
    {
      AC1Legacy::Resource::abData = operator new[](v6);
      GetFileVersionInfoA(fullFileName, dwHandle, v7, AC1Legacy::Resource::abData);
    }
    result = v7;
  }
  else
  {
    if ( !__getcwd(fullFileName, 260) )
      goto LABEL_27;
    v9 = (char *)&dwHandle + 3;
    do
      v10 = (v9++)[1];
    while ( v10 );
    *(_WORD *)v9 = *(_WORD *)"\\";
    v11 = strlen(buff) + 1;
    v12 = (char *)&dwHandle + 3;
    do
      v13 = (v12++)[1];
    while ( v13 );
    qmemcpy(v12, buff, v11);
    v14 = GetFileVersionInfoSizeA(fullFileName, &dwHandle);
    v15 = v14;
    if ( v14 )
    {
      AC1Legacy::Resource::abData = operator new[](v14);
      GetFileVersionInfoA(fullFileName, dwHandle, v15, AC1Legacy::Resource::abData);
      result = 1;
    }
    else
    {
LABEL_27:
      fullFileName[0] = 0;
      __searchenv(buff, "PATH", fullFileName);
      if ( fullFileName[0] )
        result = AC1Legacy::Resource::LoadData(fullFileName);
      else
        result = 0;
    }
  }
  return result;
}

//----- (00555070) --------------------------------------------------------  // acclient.c:388201
void AC1Legacy::Resource::Cleanup()
{
  if ( AC1Legacy::Resource::abData )
    operator delete(AC1Legacy::Resource::abData);
}

//----- (00555090) --------------------------------------------------------  // acclient.c:388208
char *__cdecl AC1Legacy::Resource::GetComments()
{
  char *result; // eax@2
  char *v1; // esi@3
  unsigned int dwSize; // [sp+0h] [bp-8h]@3
  char *lpBuffer; // [sp+4h] [bp-4h]@3

  if ( AC1Legacy::Resource::abData )
  {
    v1 = (char *)operator new[](0x2Du);
    VerQueryValueA(AC1Legacy::Resource::abData, "\\StringFileInfo\\040904b0\\Comments", (LPVOID *)&lpBuffer, &dwSize);
    if ( dwSize )
      strcpy(v1, lpBuffer);
    result = v1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005550F0) --------------------------------------------------------  // acclient.c:388231
int __cdecl AC1Legacy::Resource::GetVersion(AC1Legacy::VERSION_NO_t *version)
{
  int result; // eax@2
  unsigned int dwSize; // [sp+0h] [bp-8h]@3
  char *lpBuffer; // [sp+4h] [bp-4h]@3

  if ( AC1Legacy::Resource::abData
    && (VerQueryValueA(
          AC1Legacy::Resource::abData,
          "\\StringFileInfo\\040904b0\\TurbineBuildVersion",
          (LPVOID *)&lpBuffer,
          &dwSize),
        dwSize) )
  {
    _sscanf(
      lpBuffer,
      "%d.%d.%d.%c%c%c%c.%c",
      version,
      &version->sc,
      &version->bb,
      version->mm,
      &version->mm[1],
      version->dd,
      &version->dd[1],
      &version->debug);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

