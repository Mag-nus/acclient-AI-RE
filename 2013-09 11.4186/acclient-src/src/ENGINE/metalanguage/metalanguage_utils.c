/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : metalanguage_utils
   Object     : ENGINE\metalanguage\metalanguage_utils.obj
   Functions  : 22
   Addresses  : 0067B690 - 00715090 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0067B690) --------------------------------------------------------  // acclient.c:658440
BOOL __cdecl StringTableMetaLanguage::IsEscapeChar(wchar_t c)
{
  return c && _wcschr(L"[]!{}#\\|^$", c);
}

//----- (0067B6C0) --------------------------------------------------------  // acclient.c:658446
wchar_t __cdecl StringTableMetaLanguage::GetEscapedChar(wchar_t c)
{
  wchar_t result; // ax@2

  switch ( c )
  {
    case 0x22u:
      result = 113;
      break;
    case 0xAu:
      result = 110;
      break;
    case 0xDu:
      result = 114;
      break;
    case 9u:
      result = 116;
      break;
    default:
      if ( c && _wcschr(L"[]!{}#\\|^$", c) )
        result = c;
      else
        result = 0;
      break;
  }
  return result;
}

//----- (0067B750) --------------------------------------------------------  // acclient.c:658475
wchar_t __cdecl StringTableMetaLanguage::GetUnEscapedChar(wchar_t c)
{
  wchar_t result; // ax@2

  switch ( c )
  {
    case 0x71u:
      result = 34;
      break;
    case 0x6Eu:
      result = 10;
      break;
    case 0x72u:
      result = 13;
      break;
    case 0x74u:
      result = 9;
      break;
    default:
      if ( c && _wcschr(L"[]!{}#\\|^$", c) )
        result = c;
      else
        result = 0;
      break;
  }
  return result;
}

//----- (0067B7C0) --------------------------------------------------------  // acclient.c:658504
bool __cdecl StringTableMetaLanguage::IsNumberSingular(int num)
{
  bool result; // al@3

  if ( CLanguageInfoInterface::m_instance && CLanguageInfoInterface::m_instance->m_pLanguageInfo )
    result = CLanguageInfoInterface::IsNumberSingular(CLanguageInfoInterface::m_instance, num);
  else
    result = num == 1;
  return result;
}

//----- (0067B7F0) --------------------------------------------------------  // acclient.c:658516
bool __cdecl PSUtils::TrimExcessSpaces(PStringBase<unsigned short> *str)
{
  PStringBase<unsigned short> *v1; // edi@1
  int v2; // esi@1
  char v3; // bl@1
  unsigned int v4; // ebp@1
  PSRefBufferCharData<unsigned short> *v5; // eax@2
  unsigned int v6; // ecx@2
  int v7; // edx@2
  int v8; // edx@5
  int v9; // eax@9
  int v10; // eax@14
  unsigned int v11; // edi@17
  int v12; // ecx@17
  char *v13; // esi@20
  PSRefBufferCharData<unsigned short> *v14; // eax@27
  int v15; // esi@28
  PSRefBufferCharData<unsigned short> *v16; // eax@31
  char *v17; // esi@32
  bool bChanged; // [sp+13h] [bp-Dh]@1
  PStringBase<unsigned short> ret; // [sp+14h] [bp-Ch]@1
  wchar_t Source[2]; // [sp+18h] [bp-8h]@11
  unsigned int len; // [sp+1Ch] [bp-4h]@1

  ret.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v1 = str;
  v2 = *(_DWORD *)&str->m_charbuffer[-1].m_data[14] - 1;
  bChanged = 0;
  len = v2;
  v3 = 0;
  v4 = 0;
  if ( v2 )
  {
    do
    {
      v5 = v1->m_charbuffer;
      v6 = *(_DWORD *)&v1->m_charbuffer[-1].m_data[14];
      v7 = (int)((char *)v1->m_charbuffer + 2 * v6 - 2);
      if ( v4 < v6 )
        v7 = (int)((char *)v5 + 2 * v4);
      if ( *(_WORD *)v7 == 32 )
        goto LABEL_38;
      v8 = (int)((char *)v5 + 2 * v6 - 2);
      if ( v4 < v6 )
        v8 = (int)((char *)v5 + 2 * v4);
      if ( *(_WORD *)v8 == 9 )
      {
LABEL_38:
        if ( v3 )
        {
          bChanged = 1;
        }
        else
        {
          if ( v4 < v6 )
            v10 = (int)((char *)v5 + 2 * v4);
          else
            v10 = (int)((char *)v5 + 2 * v6 - 2);
          *(_DWORD *)Source = *(_WORD *)v10;
          if ( Source[0] )
          {
            v11 = *(_DWORD *)&ret.m_charbuffer[-1].m_data[14];
            v12 = v11 + 1;
            if ( *(_DWORD *)&ret.m_charbuffer[-1].m_data[8] != 1
              || (unsigned int)v12 > *(_DWORD *)&ret.m_charbuffer[-1].m_data[10] )
            {
              v13 = (char *)&ret.m_charbuffer[-1].m_data[6];
              PStringBase<unsigned short>::allocate_ref_buffer(&ret, v11);
              _wcscpy(ret.m_charbuffer->m_data, (const wchar_t *)v13 + 10);
              if ( !InterlockedDecrement((volatile LONG *)v13 + 1) && v13 )
                (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
            }
            else
            {
              *(_DWORD *)&ret.m_charbuffer[-1].m_data[14] = v12;
              *(_DWORD *)&ret.m_charbuffer[-1].m_data[12] = -1;
            }
            _wcsncpy((wchar_t *)ret.m_charbuffer + v11 - 1, Source, 1u);
            v1 = str;
            v2 = len;
            ret.m_charbuffer->m_data[*(_DWORD *)&ret.m_charbuffer[-1].m_data[14] - 1] = 0;
          }
        }
        v3 = 1;
      }
      else
      {
        if ( v4 < v6 )
          v9 = (int)((char *)v5 + 2 * v4);
        else
          v9 = (int)((char *)v5 + 2 * v6 - 2);
        *(_DWORD *)Source = *(_WORD *)v9;
        PStringBase<unsigned short>::append_n_chars(&ret, Source, 1u);
        v3 = 0;
      }
      ++v4;
    }
    while ( v4 < v2 );
  }
  v14 = v1->m_charbuffer;
  if ( v1->m_charbuffer != ret.m_charbuffer )
  {
    v15 = (int)&v14[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v14[-1].m_data[8]) && v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    v16 = ret.m_charbuffer;
    v1->m_charbuffer = ret.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v16[-1].m_data[8]);
  }
  v17 = (char *)&ret.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&ret.m_charbuffer[-1].m_data[8]) && v17 )
    (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
  return bChanged;
}

//----- (0067B9B0) --------------------------------------------------------  // acclient.c:658633
void __cdecl StringTableMetaLanguage::TrimExcessSpaces(PStringBase<unsigned short> *str)
{
  PStringBase<unsigned short> v1; // ST08_4@1

  v1.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::whitespace_string;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::whitespace_string - 4);
  PStringBase<unsigned short>::trim(str, 1, 0, v1);
  PSUtils::TrimExcessSpaces(str);
}

//----- (0067B9F0) --------------------------------------------------------  // acclient.c:658644
PStringBase<unsigned short> *__cdecl StringTableMetaLanguage::CapitalizeFirstLetter(PStringBase<unsigned short> *result, PStringBase<unsigned short> *orgstr)
{
  PSRefBufferCharData<unsigned short> *v2; // eax@1
  char *v3; // ebx@1
  unsigned int v4; // edi@1
  unsigned int v5; // ecx@2
  wint_t *v6; // eax@3
  wint_t v7; // si@5
  PSRefBufferCharData<unsigned short> *v8; // ecx@15
  char *v9; // eax@16
  wint_t v10; // ax@18
  PStringBase<unsigned short> *v11; // esi@20

  orgstr = (PStringBase<unsigned short> *)orgstr->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&orgstr[-4]);
  v2 = (PSRefBufferCharData<unsigned short> *)orgstr;
  v3 = (char *)&orgstr[-1].m_charbuffer[-1].m_data[15] + 1;
  v4 = 0;
  if ( orgstr[-1].m_charbuffer != (PSRefBufferCharData<unsigned short> *)1 )
  {
    while ( 1 )
    {
      v5 = *(_DWORD *)&v2[-1].m_data[14];
      v6 = (wint_t *)(v4 < v5 ? (PSRefBufferCharData<unsigned short> *)((char *)v2 + 2 * v4) : (PSRefBufferCharData<unsigned short> *)((char *)v2 + 2 * v5 - 2));
      v7 = *v6;
      if ( !_iswspace(*v6) && !_iswpunct(v7) && v7 != 191 && v7 != 161 )
        break;
      if ( v7 == 92 || v7 == 47 || v7 == 64 )
        break;
      ++v4;
      if ( v4 >= (unsigned int)v3 )
        goto LABEL_19;
      v2 = (PSRefBufferCharData<unsigned short> *)orgstr;
    }
    if ( v4 < (unsigned int)v3 )
    {
      v8 = orgstr[-1].m_charbuffer;
      if ( v4 < (unsigned int)v8 )
        v9 = (char *)orgstr + 2 * v4;
      else
        v9 = (char *)orgstr + 2 * (_DWORD)v8 - 2;
      v10 = _towupper(*(_WORD *)v9);
      PStringBase<unsigned short>::SetAtIndex((PStringBase<unsigned short> *)&orgstr, v4, v10);
    }
LABEL_19:
    v2 = (PSRefBufferCharData<unsigned short> *)orgstr;
  }
  result->m_charbuffer = v2;
  InterlockedIncrement((volatile LONG *)&v2[-1].m_data[8]);
  v11 = orgstr - 5;
  if ( !InterlockedDecrement((volatile LONG *)&orgstr[-4]) && v11 )
    (*(void (__thiscall **)(PStringBase<unsigned short> *, signed int))&v11->m_charbuffer->m_data[0])(v11, 1);
  return result;
}

//----- (0067BAF0) --------------------------------------------------------  // acclient.c:658700
PStringBase<unsigned short> *__cdecl StringTableMetaLanguage::StripMetaLetters(PStringBase<unsigned short> *result, PStringBase<unsigned short> *string)
{
  wchar_t *v2; // eax@1
  int v3; // eax@2
  PStringBase<unsigned short> v4; // ST08_4@4
  PStringBase<unsigned short> *v5; // eax@5
  PStringBase<unsigned short> *v6; // esi@5
  PStringBaseIter<unsigned short> i; // [sp+8h] [bp-10h]@2

  string = (PStringBase<unsigned short> *)string->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&string[-4]);
  v2 = PSUtils::wcschr_skipescapes((const wchar_t *)string, 0x5Bu, 0x5Cu);
  if ( v2 )
  {
    v3 = ((char *)v2 - (char *)string) >> 1;
    i.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Const<unsigned short>::vftable;
    i.pstring_ptr = (PStringBase<unsigned short> *)&string;
    i.mark = 0;
    i.curr = 0;
    if ( v3 )
      PStringBaseIter_Common<unsigned short>::Next((PStringBaseIter_Common<unsigned short> *)&i.vfptr, v3);
    PStringBaseIter<unsigned short>::Truncate(&i);
    v4.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::whitespace_string;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::whitespace_string - 4);
    PStringBase<unsigned short>::trim((PStringBase<unsigned short> *)&string, 0, 1, v4);
  }
  v5 = string;
  result->m_charbuffer = (PSRefBufferCharData<unsigned short> *)string;
  InterlockedIncrement((volatile LONG *)&v5[-4]);
  v6 = string - 5;
  if ( !InterlockedDecrement((volatile LONG *)&string[-4]) && v6 )
    (*(void (__thiscall **)(PStringBase<unsigned short> *, signed int))&v6->m_charbuffer->m_data[0])(v6, 1);
  return result;
}
// 79449C: using guessed type int (*PStringBaseIter_Const<unsigned short>::vftable)();

//----- (0067BBC0) --------------------------------------------------------  // acclient.c:658737
PStringBase<unsigned short> *__cdecl StringTableMetaLanguage::EscapeString(PStringBase<unsigned short> *result, PStringBase<unsigned short> *string)
{
  PStringBase<unsigned short> *v2; // edi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@1
  unsigned int v4; // ecx@1
  unsigned int v5; // esi@1
  wchar_t *v6; // eax@3
  int v7; // eax@5
  int v8; // ebx@5
  unsigned int v9; // edi@6
  int v10; // ecx@6
  char *v11; // esi@9
  PSRefBufferCharData<unsigned short> *v12; // eax@13
  unsigned int v13; // ecx@13
  int v14; // eax@14
  unsigned int v15; // edi@17
  int v16; // ecx@17
  char *v17; // esi@20
  PSRefBufferCharData<unsigned short> *v18; // eax@25
  char *v19; // esi@25
  PStringBase<unsigned short> temp; // [sp+8h] [bp-Ch]@1
  unsigned int loop; // [sp+Ch] [bp-8h]@1
  wchar_t Source[2]; // [sp+10h] [bp-4h]@6

  temp.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v2 = string;
  v3 = string->m_charbuffer;
  v4 = *(_DWORD *)&string->m_charbuffer[-1].m_data[14];
  v5 = 0;
  loop = 0;
  if ( v4 != 1 )
  {
    while ( 1 )
    {
      v6 = (wchar_t *)(v5 < v4 ? (PSRefBufferCharData<unsigned short> *)((char *)v3 + 2 * v5) : (PSRefBufferCharData<unsigned short> *)((char *)v3 + 2 * v4 - 2));
      LOWORD(v7) = StringTableMetaLanguage::GetEscapedChar(*v6);
      v8 = v7;
      if ( (_WORD)v7 )
        break;
      v12 = v2->m_charbuffer;
      v13 = *(_DWORD *)&v2->m_charbuffer[-1].m_data[14];
      if ( v5 < v13 )
        v14 = (int)((char *)v12 + 2 * v5);
      else
        v14 = (int)((char *)v12 + 2 * v13 - 2);
      *(_DWORD *)Source = *(_WORD *)v14;
      if ( Source[0] )
        goto LABEL_17;
LABEL_24:
      v2 = string;
      v3 = string->m_charbuffer;
      v4 = *(_DWORD *)&string->m_charbuffer[-1].m_data[14];
      ++v5;
      loop = v5;
      if ( v5 >= v4 - 1 )
        goto LABEL_25;
    }
    *(_DWORD *)Source = 92;
    v9 = *(_DWORD *)&temp.m_charbuffer[-1].m_data[14];
    v10 = v9 + 1;
    if ( *(_DWORD *)&temp.m_charbuffer[-1].m_data[8] != 1
      || (unsigned int)v10 > *(_DWORD *)&temp.m_charbuffer[-1].m_data[10] )
    {
      v11 = (char *)&temp.m_charbuffer[-1].m_data[6];
      PStringBase<unsigned short>::allocate_ref_buffer(&temp, v9);
      _wcscpy(temp.m_charbuffer->m_data, (const wchar_t *)v11 + 10);
      if ( !InterlockedDecrement((volatile LONG *)v11 + 1) && v11 )
        (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
    }
    else
    {
      *(_DWORD *)&temp.m_charbuffer[-1].m_data[14] = v10;
      *(_DWORD *)&temp.m_charbuffer[-1].m_data[12] = -1;
    }
    _wcsncpy((wchar_t *)temp.m_charbuffer + v9 - 1, Source, 1u);
    temp.m_charbuffer->m_data[*(_DWORD *)&temp.m_charbuffer[-1].m_data[14] - 1] = 0;
    *(_DWORD *)Source = v8;
LABEL_17:
    v15 = *(_DWORD *)&temp.m_charbuffer[-1].m_data[14];
    v16 = v15 + 1;
    if ( *(_DWORD *)&temp.m_charbuffer[-1].m_data[8] != 1
      || (unsigned int)v16 > *(_DWORD *)&temp.m_charbuffer[-1].m_data[10] )
    {
      v17 = (char *)&temp.m_charbuffer[-1].m_data[6];
      PStringBase<unsigned short>::allocate_ref_buffer(&temp, v15);
      _wcscpy(temp.m_charbuffer->m_data, (const wchar_t *)v17 + 10);
      if ( !InterlockedDecrement((volatile LONG *)v17 + 1) && v17 )
        (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
    }
    else
    {
      *(_DWORD *)&temp.m_charbuffer[-1].m_data[14] = v16;
      *(_DWORD *)&temp.m_charbuffer[-1].m_data[12] = -1;
    }
    _wcsncpy((wchar_t *)temp.m_charbuffer + v15 - 1, Source, 1u);
    v5 = loop;
    temp.m_charbuffer->m_data[*(_DWORD *)&temp.m_charbuffer[-1].m_data[14] - 1] = 0;
    goto LABEL_24;
  }
LABEL_25:
  v18 = temp.m_charbuffer;
  result->m_charbuffer = temp.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v18[-1].m_data[8]);
  v19 = (char *)&temp.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&temp.m_charbuffer[-1].m_data[8]) && v19 )
    (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
  return result;
}

//----- (0067BDC0) --------------------------------------------------------  // acclient.c:658848
PStringBase<unsigned short> *__cdecl StringTableMetaLanguage::UnescapeString(PStringBase<unsigned short> *result, PStringBase<unsigned short> *string)
{
  PStringBase<unsigned short> *v2; // ebp@1
  PSRefBufferCharData<unsigned short> *v3; // eax@1
  unsigned int v4; // ecx@1
  unsigned int v5; // edi@1
  PStringBase<unsigned short> *v6; // ebx@2
  int v7; // eax@4
  PStringBase<unsigned short> *v8; // eax@6
  PSRefBufferCharData<unsigned short> *v9; // ecx@6
  unsigned int v10; // edx@6
  int v11; // esi@6
  int v12; // eax@11
  unsigned int v13; // ebx@14
  int v14; // ecx@14
  char *v15; // esi@17
  PSRefBufferCharData<unsigned short> *v16; // eax@22
  char *v17; // esi@22
  PStringBase<unsigned short> ret; // [sp+Ch] [bp-8h]@1
  wchar_t Source[2]; // [sp+10h] [bp-4h]@13

  ret.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v2 = string;
  v3 = string->m_charbuffer;
  v4 = *(_DWORD *)&string->m_charbuffer[-1].m_data[14];
  v5 = 0;
  if ( v4 != 1 )
  {
    v6 = (PStringBase<unsigned short> *)1;
    string = (PStringBase<unsigned short> *)1;
    do
    {
      if ( (unsigned int)v6 < v4 )
        v7 = (int)&v3->m_data[v5 + 1];
      else
        v7 = (int)((char *)v3 + 2 * v4 - 2);
      LOWORD(v8) = StringTableMetaLanguage::GetUnEscapedChar(*(_WORD *)v7);
      v9 = v2->m_charbuffer;
      v10 = *(_DWORD *)&v2->m_charbuffer[-1].m_data[14];
      v11 = (int)((char *)v2->m_charbuffer + 2 * v10 - 2);
      if ( v5 < v10 )
        v11 = (int)((char *)v9 + 2 * v5);
      if ( *(_WORD *)v11 == 92 && (_WORD)v8 )
      {
        ++v5;
        v6 = (PStringBase<unsigned short> *)((char *)v6 + 1);
        string = v8;
        PStringBase<unsigned short>::append_n_chars(&ret, (const unsigned __int16 *)&string, 1u);
      }
      else
      {
        v12 = (int)((char *)v9 + 2 * v10 - 2);
        if ( v5 < v10 )
          v12 = (int)((char *)v9 + 2 * v5);
        *(_DWORD *)Source = *(_WORD *)v12;
        if ( Source[0] )
        {
          v13 = *(_DWORD *)&ret.m_charbuffer[-1].m_data[14];
          v14 = v13 + 1;
          if ( *(_DWORD *)&ret.m_charbuffer[-1].m_data[8] != 1
            || (unsigned int)v14 > *(_DWORD *)&ret.m_charbuffer[-1].m_data[10] )
          {
            v15 = (char *)&ret.m_charbuffer[-1].m_data[6];
            PStringBase<unsigned short>::allocate_ref_buffer(&ret, v13);
            _wcscpy(ret.m_charbuffer->m_data, (const wchar_t *)v15 + 10);
            if ( !InterlockedDecrement((volatile LONG *)v15 + 1) && v15 )
              (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
          }
          else
          {
            *(_DWORD *)&ret.m_charbuffer[-1].m_data[14] = v14;
            *(_DWORD *)&ret.m_charbuffer[-1].m_data[12] = -1;
          }
          _wcsncpy((wchar_t *)ret.m_charbuffer + v13 - 1, Source, 1u);
          v6 = string;
          ret.m_charbuffer->m_data[*(_DWORD *)&ret.m_charbuffer[-1].m_data[14] - 1] = 0;
        }
      }
      v3 = v2->m_charbuffer;
      v4 = *(_DWORD *)&v2->m_charbuffer[-1].m_data[14];
      ++v5;
      v6 = (PStringBase<unsigned short> *)((char *)v6 + 1);
      string = v6;
    }
    while ( v5 < v4 - 1 );
  }
  v16 = ret.m_charbuffer;
  result->m_charbuffer = ret.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v16[-1].m_data[8]);
  v17 = (char *)&ret.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&ret.m_charbuffer[-1].m_data[8]) && v17 )
    (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
  return result;
}

//----- (0067BF50) --------------------------------------------------------  // acclient.c:658945
char __cdecl StringTableMetaLanguage::GetMaleMetaLetters(PStringBase<unsigned short> *letters)
{
  char result; // al@3

  if ( CLanguageInfoInterface::m_instance && CLanguageInfoInterface::m_instance->m_pLanguageInfo )
  {
    result = CLanguageInfoInterface::GetMaleMetaLetters(CLanguageInfoInterface::m_instance, letters);
  }
  else
  {
    PStringBase<unsigned short>::set(letters, L"mn");
    result = 1;
  }
  return result;
}

//----- (0067BF80) --------------------------------------------------------  // acclient.c:658962
char __cdecl StringTableMetaLanguage::GetFemaleMetaLetters(PStringBase<unsigned short> *letters)
{
  char result; // al@3

  if ( CLanguageInfoInterface::m_instance && CLanguageInfoInterface::m_instance->m_pLanguageInfo )
  {
    result = CLanguageInfoInterface::GetFemaleMetaLetters(CLanguageInfoInterface::m_instance, letters);
  }
  else
  {
    PStringBase<unsigned short>::set(letters, L"fn");
    result = 1;
  }
  return result;
}

//----- (0067BFB0) --------------------------------------------------------  // acclient.c:658979
char __cdecl StringTableMetaLanguage::GetTreasureMetaLetters(PStringBase<unsigned short> *pre, PStringBase<unsigned short> *mid, PStringBase<unsigned short> *suffix)
{
  char result; // al@3

  if ( CLanguageInfoInterface::m_instance && CLanguageInfoInterface::m_instance->m_pLanguageInfo )
  {
    result = CLanguageInfoInterface::GetTreasureMetaLetters(CLanguageInfoInterface::m_instance, pre, mid, suffix);
  }
  else
  {
    PStringBase<unsigned short>::set(pre, L"v");
    PStringBase<unsigned short>::set(mid, L"mfnp");
    PStringBase<unsigned short>::set(suffix, L"s");
    result = 1;
  }
  return result;
}

//----- (00714FD0) --------------------------------------------------------  // acclient.c:807919
int sub_714FD0()
{
  return atexit(nullsub_169);
}

//----- (00714FE0) --------------------------------------------------------  // acclient.c:807925
int _E4_28()
{
  return atexit(_E5_28);
}

//----- (00714FF0) --------------------------------------------------------  // acclient.c:807931
int _E7_28()
{
  Outside_CellID_28.id = Invalid_CellID_28.id + 1;
  return atexit(_E8_28);
}

//----- (00715010) --------------------------------------------------------  // acclient.c:807938
int _E10_27()
{
  In_Limbo_CellID_27.id = Outside_CellID_28.id + 1;
  return atexit(_E11_27);
}

//----- (00715030) --------------------------------------------------------  // acclient.c:807945
int _E13_27()
{
  First_Interior_CellID_27.id = In_Limbo_CellID_27.id + 1;
  return atexit(_E14_27);
}

//----- (00715050) --------------------------------------------------------  // acclient.c:807952
int _E16_27()
{
  Last_Interior_CellID_27.id = Invalid_CellID_28.id - 1;
  return atexit(_E17_27);
}

//----- (00715070) --------------------------------------------------------  // acclient.c:807959
int _E21_30()
{
  return atexit(_E22_30);
}

//----- (00715080) --------------------------------------------------------  // acclient.c:807965
int _E40_29()
{
  return atexit(_E41_29);
}

//----- (00715090) --------------------------------------------------------  // acclient.c:807971
int _E43_32()
{
  return atexit(_E44_32);
}

