/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TimeUtils
   Object     : ENGINE\engine_utils\TimeUtils.obj
   Functions  : 2
   Addresses  : 00684170 - 007157F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00684170) --------------------------------------------------------  // acclient.c:667509
char __cdecl TimeUtils::QueryDuration(int _time, StringInfo *_duration)
{
  unsigned int v2; // edi@1
  unsigned int v3; // ebx@1
  unsigned int v4; // ett@1
  unsigned int v5; // ebp@1
  unsigned int v6; // eax@2
  unsigned int v7; // edi@3
  unsigned int v8; // eax@5
  unsigned int v9; // edi@6
  unsigned int v10; // eax@8
  unsigned int v11; // edi@9
  unsigned int v12; // eax@11
  unsigned int v13; // edi@12
  unsigned int v14; // eax@14
  unsigned int v15; // edi@15
  unsigned int v16; // eax@17
  unsigned int v17; // edi@18
  unsigned int v18; // eax@20
  char result; // al@20
  unsigned int v20; // edi@21
  unsigned int v21; // [sp-8h] [bp-24h]@2
  unsigned __int64 v22; // [sp-8h] [bp-24h]@5
  unsigned __int64 v23; // [sp-8h] [bp-24h]@8
  unsigned __int64 v24; // [sp-8h] [bp-24h]@11
  unsigned __int64 v25; // [sp-8h] [bp-24h]@14
  unsigned __int64 v26; // [sp-8h] [bp-24h]@17
  unsigned __int64 v27; // [sp-8h] [bp-24h]@20
  unsigned __int64 _varValue; // [sp+10h] [bp-Ch]@1
  unsigned int v29; // [sp+18h] [bp-4h]@1
  int _timea; // [sp+20h] [bp+4h]@1

  v2 = _time / 0x1E13380u;
  v3 = _time % 0x1E13380u / 0x278D00;
  v4 = _time % 0x1E13380u % 0x278D00;
  v5 = v4 / 0x93A80;
  v4 %= 0x93A80u;
  _timea = v4 / 0x15180;
  v4 %= 0x15180u;
  LODWORD(_varValue) = v4 / 0xE10;
  v4 %= 0xE10u;
  v29 = v4 % 0x3C;
  HIDWORD(_varValue) = v4 / 0x3C;
  StringInfo::SetTableEnum(_duration, 2);
  _duration->m_stringID = compute_str_hash("ID_DurationFormat");
  if ( v2 )
  {
    v6 = compute_str_hash("YEARS");
    StringInfo::AddVariable_UInt(_duration, v6, v21);
  }
  else
  {
    v7 = compute_str_hash("YEARS");
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v22 + 1, &name);
    StringInfo::AddVariable_String(_duration, v7, HIDWORD(v22));
  }
  if ( v3 )
  {
    HIDWORD(v22) = 0;
    v8 = compute_str_hash("MONTHS");
    StringInfo::AddVariable_UInt(_duration, v8, v22);
  }
  else
  {
    v9 = compute_str_hash("MONTHS");
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v22 + 1, &name);
    StringInfo::AddVariable_String(_duration, v9, HIDWORD(v22));
  }
  if ( v5 )
  {
    HIDWORD(v22) = 0;
    v10 = compute_str_hash("WEEKS");
    StringInfo::AddVariable_UInt(_duration, v10, v23);
  }
  else
  {
    v11 = compute_str_hash("WEEKS");
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v22 + 1, &name);
    StringInfo::AddVariable_String(_duration, v11, HIDWORD(v22));
  }
  if ( _timea )
  {
    HIDWORD(v22) = 0;
    v12 = compute_str_hash("DAYS");
    StringInfo::AddVariable_UInt(_duration, v12, v24);
  }
  else
  {
    v13 = compute_str_hash("DAYS");
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v22 + 1, &name);
    StringInfo::AddVariable_String(_duration, v13, HIDWORD(v22));
  }
  if ( (_DWORD)_varValue )
  {
    HIDWORD(v22) = 0;
    v14 = compute_str_hash("HOURS");
    StringInfo::AddVariable_UInt(_duration, v14, v25);
  }
  else
  {
    v15 = compute_str_hash("HOURS");
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v22 + 1, &name);
    StringInfo::AddVariable_String(_duration, v15, HIDWORD(v22));
  }
  if ( HIDWORD(_varValue) )
  {
    HIDWORD(v22) = 0;
    v16 = compute_str_hash("MINUTES");
    StringInfo::AddVariable_UInt(_duration, v16, v26);
  }
  else
  {
    v17 = compute_str_hash("MINUTES");
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v22 + 1, &name);
    StringInfo::AddVariable_String(_duration, v17, HIDWORD(v22));
  }
  if ( v29 )
  {
    HIDWORD(v22) = 0;
    v18 = compute_str_hash("SECONDS");
    StringInfo::AddVariable_UInt(_duration, v18, v27);
    result = 1;
  }
  else
  {
    v20 = compute_str_hash("SECONDS");
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v22 + 1, &name);
    StringInfo::AddVariable_String(_duration, v20, HIDWORD(v22));
    result = 1;
  }
  return result;
}

//----- (007157F0) --------------------------------------------------------  // acclient.c:808496
int sub_7157F0()
{
  return atexit(nullsub_229);
}

