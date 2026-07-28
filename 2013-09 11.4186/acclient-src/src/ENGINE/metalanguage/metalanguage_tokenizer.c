/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : metalanguage_tokenizer
   Object     : ENGINE\metalanguage\metalanguage_tokenizer.obj
   Functions  : 18
   Addresses  : 0067E5E0 - 0077F450 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0067E5E0) --------------------------------------------------------  // acclient.c:661427
signed int __usercall IsSpecialChar@<eax>(wchar_t c@<bp>, __int16 a2@<si>)
{
  char v2; // al@1

  v2 = StringTableMetaLanguage::IsInChoiceBlock();
  if ( a2 != 125 && a2 != 124 )
  {
    if ( a2 == 123 )
    {
      if ( v2 )
        return 0;
    }
    else if ( a2 != 94 || v2 )
    {
      return 0;
    }
  }
  else if ( !v2 )
  {
    return 0;
  }
  return 1;
}

//----- (0067E620) --------------------------------------------------------  // acclient.c:661452
unsigned int __cdecl StringTableMetaLanguage::GetCurrentStreamPosition()
{
  return g_inputidx;
}

//----- (0067E630) --------------------------------------------------------  // acclient.c:661458
char __usercall IsNumberLabel@<al>(unsigned int idx@<edi>, unsigned int *endpos@<esi>, unsigned int a3@<eax>, int *value)
{
  unsigned int v4; // esi@1
  unsigned int v6; // eax@3
  bool v7; // cf@3
  char *v8; // eax@3
  PSRefBufferCharData<unsigned short> *v9; // eax@7
  unsigned int v10; // ecx@7
  unsigned int v11; // edx@7
  char *v12; // ecx@7
  __int16 v13; // cx@9
  unsigned int v14; // edx@12
  unsigned int v15; // ecx@12
  char *v16; // esi@12
  char *v17; // eax@16
  unsigned int v18; // edx@20
  unsigned int v19; // ecx@20
  wchar_t *v20; // ebx@20
  int v21; // edx@20
  unsigned int v22; // edx@23
  char *v23; // ecx@24
  unsigned int v24; // ecx@27
  unsigned int v25; // edx@27
  int v26; // ecx@27
  __int16 v27; // cx@29
  unsigned int v28; // edx@32
  int v29; // eax@33
  int v30; // esi@36
  PSRefBufferCharData<unsigned short> *v31; // eax@36
  unsigned int v32; // edx@37
  wint_t *v33; // eax@38
  unsigned int v34; // ecx@42
  unsigned int v35; // edx@42
  unsigned int v36; // ecx@46
  unsigned int v37; // edx@46
  char *v38; // ecx@46
  __int16 v39; // cx@48
  unsigned int v40; // ecx@51
  unsigned int v41; // edx@51
  PSRefBufferCharData<unsigned short> *v42; // eax@52
  unsigned int i; // esi@55
  unsigned int v44; // ecx@56
  char *v45; // ecx@56
  __int16 v46; // cx@58
  unsigned int v47; // ecx@61
  PSRefBufferCharData<unsigned short> *v48; // eax@62
  wchar_t buffer[1024]; // [sp+4h] [bp-800h]@20

  v4 = a3;
  if ( (unsigned __int8)StringTableMetaLanguage::IsInChoiceBlock() )
    return 0;
  *(_DWORD *)idx = v4;
  v6 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
  v7 = v4 < v6;
  v8 = (char *)g_input.m_charbuffer + 2 * v6 - 2;
  if ( v7 )
    v8 = (char *)g_input.m_charbuffer + 2 * v4;
  if ( *(_WORD *)v8 != 35 )
    return 0;
  for ( *(_DWORD *)idx = v4 + 1; ; *(_DWORD *)idx = v11 + 1 )
  {
    v9 = g_input.m_charbuffer;
    v10 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
    v11 = *(_DWORD *)idx;
    v7 = *(_DWORD *)idx < v10;
    v12 = (char *)g_input.m_charbuffer + 2 * v10 - 2;
    if ( v7 )
      v12 = (char *)g_input.m_charbuffer + 2 * v11;
    v13 = *(_WORD *)v12;
    if ( v13 != 32 && v13 != 9 )
      break;
  }
  v14 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
  v15 = *(_DWORD *)idx;
  v16 = (char *)g_input.m_charbuffer + 2 * v14 - 2;
  if ( *(_DWORD *)idx < v14 )
    v16 = (char *)g_input.m_charbuffer + 2 * v15;
  if ( *(_WORD *)v16 != 45 )
  {
    if ( v15 < v14 )
      v17 = (char *)g_input.m_charbuffer + 2 * v15;
    else
      v17 = (char *)g_input.m_charbuffer + 2 * v14 - 2;
    if ( !_iswdigit(*(_WORD *)v17) )
      return 0;
    v9 = g_input.m_charbuffer;
  }
  v18 = *(_DWORD *)&v9[-1].m_data[14];
  v19 = *(_DWORD *)idx;
  v7 = *(_DWORD *)idx < v18;
  v20 = buffer;
  v21 = (int)((char *)v9 + 2 * v18 - 2);
  if ( v7 )
    v21 = (int)((char *)v9 + 2 * v19);
  if ( *(_WORD *)v21 == 45 )
  {
    *(_DWORD *)idx = v19 + 1;
    v9 = g_input.m_charbuffer;
    v22 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
    if ( v19 < v22 )
      v23 = (char *)g_input.m_charbuffer + 2 * v19;
    else
      v23 = (char *)g_input.m_charbuffer + 2 * v22 - 2;
    buffer[0] = *(_WORD *)v23;
    v20 = &buffer[1];
  }
  while ( 1 )
  {
    v24 = *(_DWORD *)&v9[-1].m_data[14];
    v25 = *(_DWORD *)idx;
    v7 = *(_DWORD *)idx < v24;
    v26 = (int)((char *)v9 + 2 * v24 - 2);
    if ( v7 )
      v26 = (int)((char *)v9 + 2 * v25);
    v27 = *(_WORD *)v26;
    if ( v27 != 32 && v27 != 9 )
      break;
    *(_DWORD *)idx = v25 + 1;
    v9 = g_input.m_charbuffer;
  }
  v28 = *(_DWORD *)&v9[-1].m_data[14];
  if ( *(_DWORD *)idx < v28 )
    v29 = (int)((char *)v9 + 2 * *(_DWORD *)idx);
  else
    v29 = (int)((char *)v9 + 2 * v28 - 2);
  if ( _iswdigit(*(_WORD *)v29) )
  {
    v30 = (char *)v20 - (char *)buffer;
    v31 = g_input.m_charbuffer;
    while ( 1 )
    {
      v32 = *(_DWORD *)&v31[-1].m_data[14];
      v33 = (wint_t *)(*(_DWORD *)idx < v32 ? (PSRefBufferCharData<unsigned short> *)((char *)v31 + 2 * *(_DWORD *)idx) : (PSRefBufferCharData<unsigned short> *)((char *)v31 + 2 * v32 - 2));
      if ( !_iswdigit(*v33) || (signed int)(v30 & 0xFFFFFFFE) >= 2048 )
        break;
      v34 = (*(_DWORD *)idx)++;
      v31 = g_input.m_charbuffer;
      v35 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
      if ( v34 < v35 )
      {
        *v20 = g_input.m_charbuffer->m_data[v34];
        ++v20;
        v30 += 2;
      }
      else
      {
        *v20 = g_input.m_charbuffer->m_data[v35 - 1];
        ++v20;
        v30 += 2;
      }
    }
    *v20 = 0;
    *value = _wcstol(buffer, 0, 10);
    while ( 1 )
    {
      v36 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
      v37 = *(_DWORD *)idx;
      v7 = *(_DWORD *)idx < v36;
      v38 = (char *)g_input.m_charbuffer + 2 * v36 - 2;
      if ( v7 )
        v38 = (char *)g_input.m_charbuffer + 2 * v37;
      v39 = *(_WORD *)v38;
      if ( v39 != 32 && v39 != 9 )
        break;
      *(_DWORD *)idx = v37 + 1;
    }
    v40 = *(_DWORD *)idx;
    v41 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
    v42 = *(_DWORD *)idx < v41 ? (PSRefBufferCharData<unsigned short> *)((char *)g_input.m_charbuffer + 2 * v40) : (PSRefBufferCharData<unsigned short> *)((char *)g_input.m_charbuffer + 2 * v41 - 2);
    if ( v42->m_data[0] == 58 )
    {
      for ( i = v40 + 1; ; ++i )
      {
        *(_DWORD *)idx = i;
        v44 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
        v7 = i < v44;
        v45 = (char *)g_input.m_charbuffer + 2 * v44 - 2;
        if ( v7 )
          v45 = (char *)g_input.m_charbuffer + 2 * i;
        v46 = *(_WORD *)v45;
        if ( v46 != 32 && v46 != 9 )
          break;
      }
      v47 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
      v48 = i < v47 ? (PSRefBufferCharData<unsigned short> *)((char *)g_input.m_charbuffer + 2 * i) : (PSRefBufferCharData<unsigned short> *)((char *)g_input.m_charbuffer + 2 * v47 - 2);
      if ( v48->m_data[0] == 1
        || *(_WORD *)PStringBase<unsigned short>::operator[](&g_input, i) == 94
        || *(_WORD *)PStringBase<unsigned short>::operator[](&g_input, i) == 123 )
        return 1;
    }
  }
  return 0;
}

//----- (0067E8C0) --------------------------------------------------------  // acclient.c:661653
void __cdecl stringmeta_error(const char *txt)
{
  char *v1; // esi@1
  StringTableMetaLanguage::RenderErr err; // [sp+4h] [bp-Ch]@1

  err.msg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  err.pos = g_inputidx;
  err.code = 1;
  PStringBase<char>::set(&err.msg, txt);
  StringTableMetaLanguage::SetError(&err);
  v1 = &err.msg.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&err.msg.m_charbuffer[-1]) )
  {
    if ( v1 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
  }
}

//----- (0067E930) --------------------------------------------------------  // acclient.c:661673
char __usercall IsFlagsBlock@<al>(unsigned int *endpos@<edx>, PStringBase<unsigned short> *value@<esi>, unsigned int *a3@<ebx>, PStringBase<unsigned short> *a4@<edi>, unsigned int idx)
{
  char result; // al@1
  int v6; // ebp@2
  PStringBase<unsigned short> v7; // eax@2
  int v8; // ebp@2
  bool v9; // zf@2
  int v10; // esi@3
  volatile LONG *v11; // ST08_4@6
  unsigned int v12; // ecx@7
  unsigned int v13; // eax@7
  bool v14; // cf@7
  char *v15; // ecx@7
  PSRefBufferCharData<unsigned short> *v16; // eax@11
  unsigned int v17; // edx@12
  unsigned int v18; // ecx@12
  int v19; // edx@12
  unsigned int v20; // edx@16
  char *v21; // ecx@17
  PSRefBufferCharData<unsigned short> *v22; // eax@20
  unsigned int v23; // ebp@20
  int v24; // ecx@20
  int v25; // esi@23
  unsigned int v26; // ecx@27
  unsigned int v27; // edx@27
  int v28; // eax@28
  wchar_t Source[2]; // [sp+8h] [bp-8h]@19
  unsigned int len; // [sp+Ch] [bp-4h]@2

  result = StringTableMetaLanguage::IsInChoiceBlock();
  if ( result )
  {
    v6 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
    *a3 = idx;
    v7.m_charbuffer = a4->m_charbuffer;
    v8 = v6 - 1;
    v9 = a4->m_charbuffer == (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    len = v8;
    if ( !v9 )
    {
      v10 = (int)&v7.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v7.m_charbuffer[-1].m_data[8]) && v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      v11 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
      a4->m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement(v11);
    }
    v12 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
    v13 = *a3;
    v14 = *a3 < v12;
    v15 = (char *)g_input.m_charbuffer + 2 * v12 - 2;
    if ( v14 )
      v15 = (char *)g_input.m_charbuffer + 2 * v13;
    if ( *(_WORD *)v15 != 91 )
      goto LABEL_35;
    *a3 = v13 + 1;
LABEL_11:
    v16 = g_input.m_charbuffer;
    while ( 1 )
    {
      v17 = *(_DWORD *)&v16[-1].m_data[14];
      v18 = *a3;
      v14 = *a3 < v17;
      v19 = (int)((char *)v16 + 2 * v17 - 2);
      if ( v14 )
        v19 = (int)((char *)v16 + 2 * v18);
      if ( *(_WORD *)v19 == 93 || v18 >= v8 )
        break;
      *a3 = v18 + 1;
      v16 = g_input.m_charbuffer;
      v20 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
      if ( v18 < v20 )
        v21 = (char *)g_input.m_charbuffer + 2 * v18;
      else
        v21 = (char *)g_input.m_charbuffer + 2 * v20 - 2;
      *(_DWORD *)Source = *(_WORD *)v21;
      if ( Source[0] )
      {
        v22 = a4->m_charbuffer;
        v23 = *(_DWORD *)&a4->m_charbuffer[-1].m_data[14];
        v24 = v23 + 1;
        if ( *(_DWORD *)&a4->m_charbuffer[-1].m_data[8] != 1 || (unsigned int)v24 > *(_DWORD *)&v22[-1].m_data[10] )
        {
          v25 = (int)&v22[-1].m_data[6];
          PStringBase<unsigned short>::allocate_ref_buffer(a4, v23);
          _wcscpy(a4->m_charbuffer->m_data, (const wchar_t *)(v25 + 20));
          if ( !InterlockedDecrement((volatile LONG *)(v25 + 4)) )
          {
            if ( v25 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))v25)(v25, 1);
          }
        }
        else
        {
          *(_DWORD *)&v22[-1].m_data[14] = v24;
          *(_DWORD *)&a4->m_charbuffer[-1].m_data[12] = -1;
        }
        _wcsncpy((wchar_t *)a4->m_charbuffer + v23 - 1, Source, 1u);
        v8 = len;
        a4->m_charbuffer->m_data[*(_DWORD *)&a4->m_charbuffer[-1].m_data[14] - 1] = 0;
        goto LABEL_11;
      }
    }
    v26 = *a3;
    v27 = *(_DWORD *)&v16[-1].m_data[14];
    v28 = (int)(*a3 < v27 ? (PSRefBufferCharData<unsigned short> *)((char *)v16 + 2 * v26) : (PSRefBufferCharData<unsigned short> *)((char *)v16 + 2 * v27 - 2));
    if ( *(_WORD *)v28 != 93 )
    {
LABEL_35:
      result = 0;
    }
    else
    {
      *a3 = v26 + 1;
      result = 1;
    }
  }
  return result;
}

//----- (0067EAC0) --------------------------------------------------------  // acclient.c:661794
int __cdecl _stringmeta_lex()
{
  PSRefBufferCharData<unsigned short> *v0; // ecx@1
  unsigned int v1; // edx@1
  unsigned int v2; // eax@1
  int v3; // ebp@1
  int result; // eax@5
  char *v5; // esi@6
  unsigned int v6; // eax@9
  unsigned int v7; // ebx@9
  char *v8; // edi@10
  char *v9; // esi@11
  unsigned int v10; // ecx@17
  char *v11; // eax@18
  char *v12; // esi@25
  bool v13; // cf@28
  char *v14; // edx@28
  bool v15; // zf@31
  unsigned int v16; // ecx@32
  unsigned int v17; // eax@32
  unsigned int v18; // ebp@32
  int v19; // ebx@32
  char *i; // edi@32
  char *v21; // edx@33
  int v22; // edx@36
  char *v23; // edx@39
  unsigned int v24; // esi@43
  unsigned int v25; // ST04_4@44
  unsigned int v26; // eax@44
  unsigned int v27; // edx@50
  int v28; // eax@51
  unsigned int v29; // eax@54
  unsigned int v30; // ecx@54
  char *v31; // eax@55
  int v32; // edi@57
  unsigned int *v33; // edx@61
  PSRefBufferCharData<unsigned short> *v34; // edx@64
  int v35; // edi@64
  int j; // esi@64
  unsigned int v37; // eax@65
  int v38; // ecx@65
  int v39; // eax@68
  unsigned int v40; // ecx@72
  unsigned int v41; // edi@72
  char *k; // esi@72
  char *v43; // eax@73
  __int16 v44; // ax@75
  int v45; // esi@78
  unsigned int v46; // eax@82
  unsigned int v47; // edx@83
  char *v48; // esi@83
  PSRefBufferCharData<unsigned short> *v49; // eax@87
  char v50; // al@89
  unsigned int *v51; // edx@98
  PSRefBufferCharData<unsigned short> *v52; // eax@100
  unsigned int v53; // edx@100
  unsigned int v54; // ecx@100
  char *v55; // esi@100
  char *v56; // eax@104
  unsigned int v57; // edx@109
  unsigned int v58; // ecx@109
  int *v59; // eax@110
  PStringBase<unsigned short> valuestr; // [sp+8h] [bp-10h]@1
  unsigned int newpos; // [sp+Ch] [bp-Ch]@61
  int value; // [sp+10h] [bp-8h]@61
  unsigned int len; // [sp+14h] [bp-4h]@1

  valuestr.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v0 = g_input.m_charbuffer;
  v1 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
  v2 = g_inputidx;
  v3 = v1 - 1;
  len = v1 - 1;
  if ( g_inputidx >= v1 - 1 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&valuestr.m_charbuffer[-1].m_data[8])
      && valuestr.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&valuestr.m_charbuffer[-1].m_data[6])(
        &valuestr.m_charbuffer[-1].m_data[6],
        1);
    return -1;
  }
  v5 = (char *)g_input.m_charbuffer + 2 * v1 - 2;
  if ( g_inputidx < v1 )
    v5 = (char *)g_input.m_charbuffer + 2 * g_inputidx;
  if ( *(_WORD *)v5 == 1 )
  {
    v6 = g_inputidx + 1;
    g_inputidx = v6;
    v7 = v6;
    if ( v6 < v3 )
    {
      v8 = (char *)g_input.m_charbuffer + 2 * v6;
      do
      {
        v9 = (char *)g_input.m_charbuffer + 2 * v1 - 2;
        if ( v6 < v1 )
          v9 = v8;
        if ( *(_WORD *)v9 == 1 )
          break;
        ++v6;
        v8 += 2;
      }
      while ( v6 < v3 );
      g_inputidx = v6;
    }
    PStringBase<unsigned short>::clear(&stringmeta_lval);
    if ( g_inputidx != v7 )
    {
      v10 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
      if ( v7 < v10 )
        v11 = (char *)g_input.m_charbuffer + 2 * v7;
      else
        v11 = (char *)g_input.m_charbuffer + 2 * v10 - 2;
      PStringBase<unsigned short>::append_n_chars(&stringmeta_lval, (const unsigned __int16 *)v11, g_inputidx - v7);
    }
    ++g_inputidx;
    if ( !InterlockedDecrement((volatile LONG *)&valuestr.m_charbuffer[-1].m_data[8])
      && valuestr.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&valuestr.m_charbuffer[-1].m_data[6])(
        &valuestr.m_charbuffer[-1].m_data[6],
        1);
    return 258;
  }
  v12 = (char *)g_input.m_charbuffer + 2 * v1 - 2;
  if ( g_inputidx < v1 )
    v12 = (char *)g_input.m_charbuffer + 2 * g_inputidx;
  if ( *(_WORD *)v12 == 123 )
  {
    v12 = (char *)(g_inputidx + 1);
    v13 = g_inputidx + 1 < v1;
    v14 = (char *)g_input.m_charbuffer + 2 * v1 - 2;
    if ( v13 )
      v14 = (char *)g_input.m_charbuffer + 2 * (_DWORD)v12;
    if ( *(_WORD *)v14 == 123 )
    {
      v15 = (unsigned __int8)StringTableMetaLanguage::IsInChoiceBlock() == 0;
      v2 = g_inputidx;
      if ( v15 )
      {
        v16 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
        v17 = g_inputidx + 2;
        g_inputidx = v17;
        v18 = v17;
        v19 = v17 + 1;
        for ( i = (char *)g_input.m_charbuffer + 2 * v17; ; i += 2 )
        {
          v21 = (char *)g_input.m_charbuffer + 2 * v16 - 2;
          if ( v17 < v16 )
            v21 = i;
          if ( *(_WORD *)v21 == 125 )
          {
            v22 = (int)((char *)g_input.m_charbuffer + 2 * v16 - 2);
            if ( v19 < v16 )
              v22 = (int)(i + 2);
            if ( *(_WORD *)v22 == 125 )
              break;
          }
          v23 = (char *)g_input.m_charbuffer + 2 * v16 - 2;
          if ( v17 < v16 )
            v23 = i;
          if ( !*(_WORD *)v23 )
            break;
          ++v17;
          ++v19;
        }
        g_inputidx = v17;
        PStringBase<unsigned short>::clear(&stringmeta_lval);
        v24 = g_inputidx;
        if ( g_inputidx != v18 )
        {
          v25 = g_inputidx - v18;
          v26 = PStringBase<unsigned short>::operator[](&g_input, v18);
          PStringBase<unsigned short>::append_n_chars(&stringmeta_lval, (const unsigned __int16 *)v26, v25);
          v24 = g_inputidx;
        }
        if ( *(_WORD *)PStringBase<unsigned short>::operator[](&g_input, v24) == 125
          && *(_WORD *)PStringBase<unsigned short>::operator[](&g_input, v24 + 1) == 125 )
          g_inputidx = v24 + 2;
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&valuestr);
        return 261;
      }
      v0 = g_input.m_charbuffer;
    }
  }
  v27 = *(_DWORD *)&v0[-1].m_data[14];
  if ( v2 < v27 )
    v28 = (int)((char *)v0 + 2 * v2);
  else
    v28 = (int)((char *)v0 + 2 * v27 - 2);
  LOWORD(v12) = *(_WORD *)v28;
  if ( (unsigned __int8)IsSpecialChar(v3, *(_WORD *)v28) )
  {
    v29 = g_inputidx++;
    v30 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
    if ( v29 < v30 )
      v31 = (char *)g_input.m_charbuffer + 2 * v29;
    else
      v31 = (char *)g_input.m_charbuffer + 2 * v30 - 2;
    v32 = *(_WORD *)v31;
    if ( !InterlockedDecrement((volatile LONG *)&valuestr.m_charbuffer[-1].m_data[8])
      && valuestr.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&valuestr.m_charbuffer[-1].m_data[6])(
        &valuestr.m_charbuffer[-1].m_data[6],
        1);
    result = v32;
  }
  else if ( IsNumberLabel((unsigned int)&newpos, (unsigned int *)v12, g_inputidx, &value) )
  {
    g_inputidx = newpos;
    PStringBase<unsigned short>::clear(&stringmeta_lval);
    PStringBase<unsigned short>::append_int32(&stringmeta_lval, value);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&valuestr);
    result = 259;
  }
  else if ( IsFlagsBlock(v33, (PStringBase<unsigned short> *)v12, &newpos, &valuestr, g_inputidx) )
  {
    g_inputidx = newpos;
    PStringBase<unsigned short>::clear(&stringmeta_lval);
    v34 = valuestr.m_charbuffer;
    v35 = *(_DWORD *)&valuestr.m_charbuffer[-1].m_data[14] - 1;
    for ( j = 0; j < v35; ++j )
    {
      v37 = *(_DWORD *)&v34[-1].m_data[14];
      v38 = (int)((char *)v34 + 2 * v37 - 2);
      if ( j < v37 )
        v38 = (int)((char *)v34 + 2 * j);
      if ( *(_WORD *)v38 != 32 )
      {
        v13 = j < v37;
        v39 = (int)((char *)v34 + 2 * v37 - 2);
        if ( v13 )
          v39 = (int)((char *)v34 + 2 * j);
        value = *(_WORD *)v39;
        PStringBase<unsigned short>::append_n_chars(&stringmeta_lval, (const unsigned __int16 *)&value, 1u);
        v34 = valuestr.m_charbuffer;
      }
    }
    v40 = g_inputidx;
    v41 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
    for ( k = (char *)g_input.m_charbuffer + 2 * g_inputidx; ; k += 2 )
    {
      v43 = (char *)g_input.m_charbuffer + 2 * v41 - 2;
      if ( v40 < v41 )
        v43 = k;
      v44 = *(_WORD *)v43;
      if ( v44 != 32 && v44 != 9 )
        break;
      ++v40;
    }
    v45 = (int)&v34[-1].m_data[6];
    g_inputidx = v40;
    if ( !InterlockedDecrement((volatile LONG *)&v34[-1].m_data[8]) && v45 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v45)(v45, 1);
    result = 260;
  }
  else
  {
    PStringBase<unsigned short>::clear(&stringmeta_lval);
    v46 = g_inputidx;
    if ( g_inputidx < v3 )
    {
      do
      {
        v47 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
        v48 = (char *)g_input.m_charbuffer + 2 * v47 - 2;
        if ( v46 < v47 )
          v48 = (char *)g_input.m_charbuffer + 2 * v46;
        if ( *(_WORD *)v48 == 1 )
          break;
        v49 = v46 < v47 ? (PSRefBufferCharData<unsigned short> *)((char *)g_input.m_charbuffer + 2 * v46) : (PSRefBufferCharData<unsigned short> *)((char *)g_input.m_charbuffer + 2 * v47 - 2);
        LOWORD(v48) = v49->m_data[0];
        v50 = StringTableMetaLanguage::IsInChoiceBlock();
        if ( (_WORD)v48 == 125 )
        {
          if ( v50 )
            break;
        }
        else if ( (_WORD)v48 == 124 )
        {
          if ( v50 )
            break;
        }
        else if ( ((_WORD)v48 == 123 || (_WORD)v48 == 94) && !v50 )
        {
          break;
        }
        if ( IsNumberLabel((unsigned int)&newpos, (unsigned int *)v48, g_inputidx, &value)
          || IsFlagsBlock(v51, (PStringBase<unsigned short> *)v48, &newpos, &valuestr, g_inputidx) )
          break;
        v52 = g_input.m_charbuffer;
        v53 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
        v54 = g_inputidx;
        v55 = (char *)g_input.m_charbuffer + 2 * v53 - 2;
        if ( g_inputidx < v53 )
          v55 = (char *)g_input.m_charbuffer + 2 * g_inputidx;
        if ( *(_WORD *)v55 == 92 )
        {
          if ( g_inputidx + 1 < v53 )
            v56 = (char *)g_input.m_charbuffer + 2 * (g_inputidx + 1);
          else
            v56 = (char *)g_input.m_charbuffer + 2 * v53 - 2;
          if ( (unsigned __int8)StringTableMetaLanguage::IsEscapeChar(*(_WORD *)v56) )
          {
            ++g_inputidx;
            value = 92;
            PStringBase<unsigned short>::append_n_chars(&stringmeta_lval, (const unsigned __int16 *)&value, 1u);
          }
          v52 = g_input.m_charbuffer;
          v54 = g_inputidx;
        }
        v57 = v54;
        g_inputidx = v54 + 1;
        v58 = *(_DWORD *)&v52[-1].m_data[14];
        v59 = (int *)(v57 < v58 ? (PSRefBufferCharData<unsigned short> *)((char *)v52 + 2 * v57) : (PSRefBufferCharData<unsigned short> *)((char *)v52 + 2 * v58 - 2));
        value = *(_WORD *)v59;
        PStringBase<unsigned short>::append_n_chars(&stringmeta_lval, (const unsigned __int16 *)&value, 1u);
        v46 = g_inputidx;
      }
      while ( g_inputidx < len );
    }
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&valuestr);
    result = 257;
  }
  return result;
}

//----- (0067F020) --------------------------------------------------------  // acclient.c:662123
void __cdecl StringTableMetaLanguage::LoadTokenizer(SmartArray<PStringBase<unsigned short>,1> *textparts, SmartArray<PStringBase<unsigned short>,1> *varparts)
{
  char *v2; // esi@2
  SmartArray<PStringBase<unsigned short>,1> *v3; // ebx@6
  unsigned int v4; // eax@6
  unsigned int v5; // edi@6
  PSRefBufferCharData<unsigned short> *v6; // esi@7
  unsigned int v7; // ebp@7
  int v8; // eax@7
  unsigned int v9; // edi@10
  int v10; // ecx@10
  char *v11; // esi@13
  int v12; // ecx@16
  PSRefBufferCharData<unsigned short> *v13; // eax@16
  int v14; // edx@17
  int v15; // esi@17
  int v16; // eax@20
  bool v17; // bl@22
  int v18; // esi@24
  PSRefBufferCharData<unsigned short> *v19; // eax@28
  int v20; // ecx@28
  unsigned int v21; // edi@30
  int v22; // ecx@30
  char *v23; // esi@33
  int v24; // esi@37
  unsigned int v25; // eax@40
  wchar_t Source[2]; // [sp+10h] [bp-Ch]@10
  unsigned int loop; // [sp+14h] [bp-8h]@6
  PStringBase<unsigned short> textparts_str; // [sp+18h] [bp-4h]@7

  if ( (wchar_t *)g_input.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
  {
    v2 = (char *)&g_input.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&g_input.m_charbuffer[-1].m_data[8]) && v2 )
      (**(void (__thiscall ***)(char *, signed int))v2)(v2, 1);
    g_input.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  }
  v3 = textparts;
  v4 = textparts->m_num;
  v5 = 0;
  loop = 0;
  if ( v4 )
  {
    do
    {
      v7 = v5;
      textparts_str.m_charbuffer = v3->m_data[v5].m_charbuffer;
      v6 = textparts_str.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&textparts_str.m_charbuffer[-1].m_data[8]);
      v8 = *(_DWORD *)&v6[-1].m_data[14];
      if ( v8 != 1 )
        PStringBase<unsigned short>::append_n_chars(&g_input, v6->m_data, v8 - 1);
      if ( v5 < varparts->m_num )
      {
        *(_DWORD *)Source = 1;
        v9 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
        v10 = v9 + 1;
        if ( *(_DWORD *)&g_input.m_charbuffer[-1].m_data[8] != 1
          || (unsigned int)v10 > *(_DWORD *)&g_input.m_charbuffer[-1].m_data[10] )
        {
          v11 = (char *)&g_input.m_charbuffer[-1].m_data[6];
          PStringBase<unsigned short>::allocate_ref_buffer(&g_input, v9);
          _wcscpy(g_input.m_charbuffer->m_data, (const wchar_t *)v11 + 10);
          if ( !InterlockedDecrement((volatile LONG *)v11 + 1) && v11 )
            (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
        }
        else
        {
          *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14] = v10;
          *(_DWORD *)&g_input.m_charbuffer[-1].m_data[12] = -1;
        }
        _wcsncpy((wchar_t *)g_input.m_charbuffer + v9 - 1, Source, 1u);
        g_input.m_charbuffer->m_data[*(_DWORD *)&g_input.m_charbuffer[-1].m_data[14] - 1] = 0;
        *(_DWORD *)Source = PStringBase<unsigned short>::s_NullBuffer;
        InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
        v12 = *(_DWORD *)Source;
        v13 = varparts->m_data[v7].m_charbuffer;
        v17 = (*(_DWORD *)&v13[-1].m_data[14] != *(_DWORD *)(*(_DWORD *)Source - 4)
            || (v14 = *(_DWORD *)&v13[-1].m_data[12], v15 = *(_DWORD *)(*(_DWORD *)Source - 8), v14 != v15)
            && v14 != -1
            && v15 != -1
            || (v16 = _wcscmp(v13->m_data, *(const wchar_t **)Source), v12 = *(_DWORD *)Source, v16 != 0))
           && *(_DWORD *)&varparts->m_data[v7].m_charbuffer[-1].m_data[14] != 1;
        v18 = v12 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v12 - 20 + 4)) && v18 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
        if ( v17 )
        {
          v19 = varparts->m_data[v7].m_charbuffer;
          v20 = *(_DWORD *)&v19[-1].m_data[14];
          if ( v20 != 1 )
            PStringBase<unsigned short>::append_n_chars(&g_input, v19->m_data, v20 - 1);
        }
        *(_DWORD *)Source = 1;
        v21 = *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14];
        v22 = v21 + 1;
        if ( *(_DWORD *)&g_input.m_charbuffer[-1].m_data[8] != 1
          || (unsigned int)v22 > *(_DWORD *)&g_input.m_charbuffer[-1].m_data[10] )
        {
          v23 = (char *)&g_input.m_charbuffer[-1].m_data[6];
          PStringBase<unsigned short>::allocate_ref_buffer(&g_input, v21);
          _wcscpy(g_input.m_charbuffer->m_data, (const wchar_t *)v23 + 10);
          if ( !InterlockedDecrement((volatile LONG *)v23 + 1) && v23 )
            (**(void (__thiscall ***)(char *, signed int))v23)(v23, 1);
        }
        else
        {
          *(_DWORD *)&g_input.m_charbuffer[-1].m_data[14] = v22;
          *(_DWORD *)&g_input.m_charbuffer[-1].m_data[12] = -1;
        }
        _wcsncpy((wchar_t *)g_input.m_charbuffer + v21 - 1, Source, 1u);
        v3 = textparts;
        v5 = loop;
        v6 = textparts_str.m_charbuffer;
        g_input.m_charbuffer->m_data[*(_DWORD *)&g_input.m_charbuffer[-1].m_data[14] - 1] = 0;
      }
      v24 = (int)&v6[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)(v24 + 4)) )
      {
        if ( v24 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v24)(v24, 1);
      }
      v25 = v3->m_num;
      ++v5;
      loop = v5;
    }
    while ( v5 < v25 );
    g_inputidx = 0;
  }
  else
  {
    g_inputidx = 0;
  }
}

//----- (00715350) --------------------------------------------------------  // acclient.c:808167
int sub_715350()
{
  return atexit(nullsub_151);
}

//----- (00715360) --------------------------------------------------------  // acclient.c:808173
int _E4_32()
{
  return atexit(_E5_32);
}

//----- (00715370) --------------------------------------------------------  // acclient.c:808179
int _E7_32()
{
  Outside_CellID_32.id = Invalid_CellID_32.id + 1;
  return atexit(_E8_32);
}

//----- (00715390) --------------------------------------------------------  // acclient.c:808186
int _E10_31()
{
  In_Limbo_CellID_31.id = Outside_CellID_32.id + 1;
  return atexit(_E11_31);
}

//----- (007153B0) --------------------------------------------------------  // acclient.c:808193
int _E13_31()
{
  First_Interior_CellID_31.id = In_Limbo_CellID_31.id + 1;
  return atexit(_E14_31);
}

//----- (007153D0) --------------------------------------------------------  // acclient.c:808200
int _E16_31()
{
  Last_Interior_CellID_31.id = Invalid_CellID_32.id - 1;
  return atexit(_E17_31);
}

//----- (007153F0) --------------------------------------------------------  // acclient.c:808207
int _E21_34()
{
  return atexit(_E22_34);
}

//----- (00715400) --------------------------------------------------------  // acclient.c:808213
int _E40_33()
{
  return atexit(_E41_33);
}

//----- (00715410) --------------------------------------------------------  // acclient.c:808219
int _E43_36()
{
  return atexit(_E44_36);
}

//----- (00715420) --------------------------------------------------------  // acclient.c:808225
int sub_715420()
{
  g_input.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  return atexit(sub_77F450);
}

//----- (0077F450) --------------------------------------------------------  // acclient.c:918038
void __cdecl sub_77F450()
{
  char *v0; // esi@1

  v0 = (char *)&g_input.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&g_input.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

