/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MaterialTypeEnumMap
   Object     : AC\actreasure\MaterialTypeEnumMap.obj
   Functions  : 1
   Addresses  : 005CD500 - 005CD500 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005CD500) --------------------------------------------------------  // acclient.c:505453
char __cdecl MaterialTypeEnumMapper::MaterialTypeToString(unsigned int ct, PStringBase<char> *str)
{
  int v2; // edi@1
  char *v3; // esi@3
  char *v4; // esi@6
  PStringBase<char> search; // [sp+8h] [bp-8h]@3
  PStringBase<char> v7; // [sp+Ch] [bp-4h]@3

  v2 = DBObj::GetByEnum(1, 268435457, 0x28u);
  if ( !v2 )
    return 0;
  if ( !(unsigned __int8)EnumIDMap::GetName((EnumIDMap *)v2, ct, str) )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 20))(v2);
    return 0;
  }
  PStringBase<char>::PStringBase<char>(&v7, " ");
  PStringBase<char>::PStringBase<char>(&search, "_");
  PStringBase<char>::replace(str, &search, &v7);
  v3 = &search.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&search.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = &v7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v7.m_charbuffer[-1]) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
  (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v2 + 20))(v2);
  return 1;
}

