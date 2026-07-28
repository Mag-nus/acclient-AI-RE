/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : reg_edit
   Object     : CORE\core_utils\reg_edit.obj
   Functions  : 5
   Addresses  : 0040DDC0 - 0040DF80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0040DDC0) --------------------------------------------------------  // acclient.c:73534
bool __thiscall RegEdit::QueryStrValue(RegEdit *this, PStringBase<char> *szKeyPath, PStringBase<char> *szName, char *szValue, unsigned int cNumCharacters, HKEY__ *hKey)
{
  PSRefBufferCharData<char> *v6; // ST08_4@1
  LSTATUS v7; // eax@1
  bool v8; // bl@1
  HKEY__ *hk; // [sp+0h] [bp-4h]@1

  hk = (HKEY__ *)this;
  v6 = szKeyPath->m_charbuffer;
  hk = 0;
  v7 = RegOpenKeyExA(hKey, v6->m_data, 0, 0x20019u, &hk);
  v8 = v7 == 0;
  if ( !v7 )
    v8 = RegQueryValueExA(hk, szName->m_charbuffer->m_data, 0, (LPDWORD)&szKeyPath, szValue, &cNumCharacters) == 0;
  if ( hk )
    RegCloseKey(hk);
  return v8;
}

//----- (0040DE40) --------------------------------------------------------  // acclient.c:73554
bool __userpurge RegEdit::QueryWStrValue@<al>(RegEdit *this@<ecx>, int a2@<ebx>, PStringBase<unsigned short> *lszKeyPath, PStringBase<unsigned short> *lszName, wchar_t *lszValue, unsigned int cNumCharacters, HKEY__ *hKey)
{
  PSRefBufferCharData<unsigned short> *v7; // ST20_4@1
  LONG v8; // eax@1
  bool v9; // bl@1
  HKEY v11; // [sp+0h] [bp-30h]@0
  signed int v12; // [sp+20h] [bp-10h]@1
  HKEY__ **v13; // [sp+24h] [bp-Ch]@1
  int v14; // [sp+28h] [bp-8h]@1
  HKEY__ *hk; // [sp+2Ch] [bp-4h]@1

  hk = (HKEY__ *)this;
  v14 = a2;
  v13 = &hk;
  v12 = 131097;
  v7 = lszKeyPath->m_charbuffer;
  hk = 0;
  v8 = RegOpenKeyExW(hKey, v7->m_data, 0, 0x20019u, &hk);
  v9 = v8 == 0;
  if ( !v8 )
  {
    v11 = *v13;
    v9 = advapi32_RegQueryValueExW_Ptr() == 0;
  }
  if ( v11 )
    RegCloseKey(v11);
  return v9;
}
// 40DE40: could not find valid save-restore pair for ebx

//----- (0040DEC0) --------------------------------------------------------  // acclient.c:73585
bool __thiscall RegEdit::DeleteValue(RegEdit *this, PStringBase<char> *szKeyPath, PStringBase<char> *szName, HKEY__ *hKey)
{
  PSRefBufferCharData<char> *v4; // ST04_4@1
  LSTATUS v5; // eax@1
  bool v6; // bl@1
  HKEY__ *hk; // [sp+0h] [bp-4h]@1

  hk = (HKEY__ *)this;
  v4 = szKeyPath->m_charbuffer;
  hk = 0;
  v5 = RegOpenKeyExA(hKey, v4->m_data, 0, 0x20006u, &hk);
  v6 = v5 == 0;
  if ( !v5 )
    v6 = RegDeleteValueA(hk, szName->m_charbuffer->m_data) == 0;
  if ( hk )
    RegCloseKey(hk);
  return v6;
}

//----- (0040DF20) --------------------------------------------------------  // acclient.c:73605
bool __thiscall RegEdit::QueryStrValue(RegEdit *this, PStringBase<char> *szKeyPath, PStringBase<char> *szName, PStringBase<char> *szValue, HKEY__ *hKey)
{
  bool result; // al@1
  char buff[2048]; // [sp+0h] [bp-800h]@1

  result = RegEdit::QueryStrValue(this, szKeyPath, szName, buff, 0x800u, hKey);
  if ( result )
  {
    PStringBase<char>::set(szValue, buff);
    result = 1;
  }
  return result;
}

//----- (0040DF80) --------------------------------------------------------  // acclient.c:73620
bool __userpurge RegEdit::QueryWStrValue@<al>(RegEdit *this@<ecx>, int a2@<ebx>, PStringBase<unsigned short> *lszKeyPath, PStringBase<unsigned short> *lszName, PStringBase<unsigned short> *lszValue, HKEY__ *hKey)
{
  bool result; // al@1
  wchar_t lszValuea; // [sp+0h] [bp-1000h]@1

  result = RegEdit::QueryWStrValue(this, a2, lszKeyPath, lszName, &lszValuea, 0x800u, hKey);
  if ( result )
  {
    PStringBase<unsigned short>::set(lszValue, &lszValuea);
    result = 1;
  }
  return result;
}

