/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CliRegKey
   Object     : ENGINE\cregistry\CliRegKey.obj
   Functions  : 3
   Addresses  : 006AFE90 - 00790810 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006AFE90) --------------------------------------------------------  // acclient.c:713254
bool __cdecl ClientRegKey::GetClientOptions(PStringBase<char> *_opt, PStringBase<char> *_val)
{
  int v2; // ecx@0
  int v4; // [sp+0h] [bp-4h]@1

  v4 = v2;
  return RegEdit::QueryStrValue((RegEdit *)&v4, &g_strClientRegKeyBasePath, _opt, _val, (HKEY__ *)0x80000002);
}

//----- (007232B0) --------------------------------------------------------  // acclient.c:821081
int sub_7232B0()
{
  PStringBase<char>::PStringBase<char>(
    &g_strClientRegKeyBasePath,
    "SOFTWARE\\Microsoft\\Microsoft Games\\Asheron's Call\\1.00");
  return atexit(sub_790810);
}

//----- (00790810) --------------------------------------------------------  // acclient.c:936620
void __cdecl sub_790810()
{
  char *v0; // esi@1

  v0 = &g_strClientRegKeyBasePath.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&g_strClientRegKeyBasePath.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

