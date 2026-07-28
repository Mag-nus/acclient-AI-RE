/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : metalanguage_grammar
   Object     : ENGINE\metalanguage\metalanguage_grammar.obj
   Functions  : 12
   Addresses  : 0067DFE0 - 0077F390 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0067DFE0) --------------------------------------------------------  // acclient.c:661034
int __cdecl stringmeta_parse()
{
  PStringBase<unsigned short> *v0; // esi@1
  signed int v1; // edi@1
  volatile LONG *v2; // ST0C_4@2
  __int16 *v3; // edi@3
  __int16 *v4; // esi@3
  PStringBase<unsigned short> *v5; // ebx@3
  int v6; // ecx@4
  int v7; // eax@5
  int v8; // edx@5
  int v9; // esi@6
  void *v10; // esp@9
  int v11; // ebx@9
  int *v12; // eax@9
  signed int v13; // ecx@10
  void *v14; // esp@12
  int v15; // eax@12
  int *v16; // ecx@12
  signed int v17; // esi@13
  PStringBase<unsigned short> *v18; // edx@17
  int v19; // eax@18
  signed int v20; // eax@21
  bool v21; // sf@25
  int v22; // edx@25
  int v23; // eax@28
  int v24; // eax@30
  int v25; // eax@31
  PSRefBufferCharData<unsigned short> *v26; // ecx@32
  int v27; // edi@32
  PSRefBufferCharData<unsigned short> *v28; // eax@32
  PSRefBufferCharData<unsigned short> **v29; // edi@32
  int v30; // eax@52
  int v31; // eax@53
  int v32; // edi@56
  __int32 v33; // eax@66
  __int32 v34; // eax@70
  PStringBase<unsigned short> v35; // eax@75
  int v36; // edi@76
  PSRefBufferCharData<unsigned short> *v37; // eax@79
  int v38; // edx@80
  int v39; // eax@80
  char *v40; // esi@85
  __int16 **v41; // edi@88
  int v42; // esi@89
  int v43; // esi@89
  char *v45; // esi@95
  __int16 **v46; // edi@98
  int v47; // esi@99
  int v48; // esi@99
  const wchar_t *v49; // [sp-10h] [bp-4E8h]@64
  bool v50; // [sp-4h] [bp-4DCh]@64
  int v51; // [sp+0h] [bp-4D8h]@9
  __int16 v52; // [sp+Ah] [bp-4CEh]@3
  __int16 yyssa[200]; // [sp+Ch] [bp-4CCh]@3
  PStringBase<unsigned short> yyvsa[200]; // [sp+19Ch] [bp-33Ch]@1
  __int16 *yyss; // [sp+4BCh] [bp-1Ch]@3
  int yyerrstatus; // [sp+4C0h] [bp-18h]@3
  int yystacksize; // [sp+4C4h] [bp-14h]@3
  PStringBase<unsigned short> yyval; // [sp+4C8h] [bp-10h]@3
  int yylen; // [sp+4CCh] [bp-Ch]@3
  __int16 *yyss1; // [sp+4D0h] [bp-8h]@3
  PStringBase<unsigned short> *yyvs1; // [sp+4D4h] [bp-4h]@6

  v0 = yyvsa;
  v1 = 200;
  do
  {
    v2 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    v0->m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v2);
    ++v0;
    --v1;
  }
  while ( v1 );
  yyval.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v3 = yyssa;
  yyss = yyssa;
  yyss1 = (__int16 *)yyvsa;
  yystacksize = 200;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  yylen = 0;
  yyerrstatus = 0;
  stringmeta_nerrs = 0;
  stringmeta_char = -2;
  v4 = &v52;
  v5 = yyvsa;
  while ( 2 )
  {
    while ( 2 )
    {
      v6 = yylen;
      while ( 1 )
      {
        v7 = yystacksize;
        ++v4;
        v8 = (int)&v3[yystacksize - 1];
        *v4 = v6;
        if ( (unsigned int)v4 >= v8 )
        {
          v9 = v4 - v3 + 1;
          yyvs1 = (PStringBase<unsigned short> *)yyss1;
          yyss1 = v3;
          if ( v7 >= 10000 )
          {
            stringmeta_error("parser stack overflow");
            v40 = (char *)&yyval.m_charbuffer[-1].m_data[6];
            if ( !InterlockedDecrement((volatile LONG *)&yyval.m_charbuffer[-1].m_data[8]) && v40 )
              (**(void (__thiscall ***)(char *, signed int))v40)(v40, 1);
            v41 = &yyss;
            yyss1 = (__int16 *)200;
            do
            {
              v42 = (int)*(v41 - 1);
              --v41;
              v43 = v42 - 20;
              if ( !InterlockedDecrement((volatile LONG *)(v43 + 4)) && v43 )
                (**(void (__thiscall ***)(_DWORD, _DWORD))v43)(v43, 1);
              yyss1 = (__int16 *)((char *)yyss1 - 1);
            }
            while ( yyss1 );
            return 2;
          }
          yystacksize = 2 * v7;
          if ( 2 * v7 > 10000 )
            yystacksize = 10000;
          v10 = alloca(2 * yystacksize);
          v3 = (__int16 *)&v51;
          v11 = 2 * v9;
          yyss = (__int16 *)&v51;
          v12 = &v51;
          if ( 2 * v9 > 0 )
          {
            v13 = (char *)yyss1 - (char *)&v51;
            yyss1 = (__int16 *)(2 * v9);
            do
            {
              *(_BYTE *)v12 = *((_BYTE *)v12 + v13);
              v12 = (int *)((char *)v12 + 1);
              yyss1 = (__int16 *)((char *)yyss1 - 1);
            }
            while ( yyss1 );
          }
          v14 = alloca(4 * yystacksize);
          v15 = 2 * v9;
          v16 = &v51;
          yyss1 = (__int16 *)&v51;
          if ( 4 * v9 > 0 )
          {
            v17 = (char *)yyvs1 - (char *)&v51;
            yyvs1 = (PStringBase<unsigned short> *)(v15 * 2);
            do
            {
              *(_BYTE *)v16 = *((_BYTE *)v16 + v17);
              v16 = (int *)((char *)v16 + 1);
              yyvs1 = (PStringBase<unsigned short> *)((char *)yyvs1 - 1);
            }
            while ( yyvs1 );
          }
          v4 = (__int16 *)((char *)&v51 + v11 - 2);
          v5 = (PStringBase<unsigned short> *)&yyss1[v15 - 2];
          if ( (unsigned int)v4 >= (unsigned int)((char *)&v51 + 2 * yystacksize - 2) )
            goto LABEL_95;
          v6 = yylen;
        }
        v18 = (PStringBase<unsigned short> *)yypact[v6];
        yyvs1 = (PStringBase<unsigned short> *)yypact[v6];
        if ( v18 != (PStringBase<unsigned short> *)-32768 )
        {
          v19 = stringmeta_char;
          if ( stringmeta_char == -2 )
          {
            v19 = stringmeta_lex();
            v6 = yylen;
            v18 = yyvs1;
            stringmeta_char = v19;
          }
          if ( v19 > 0 )
          {
            v20 = (unsigned int)v19 > 0x105 ? 24 : yytranslate[v19];
          }
          else
          {
            v20 = 0;
            stringmeta_char = 0;
          }
          v21 = (signed int)((char *)v18 + v20) < 0;
          v22 = (int)((char *)v18 + v20);
          yyvs1 = (PStringBase<unsigned short> *)v22;
          if ( !v21 && v22 <= 22 && yycheck[v22] == v20 )
            break;
        }
        v24 = yydefact[v6];
        yyvs1 = (PStringBase<unsigned short> *)yydefact[v6];
        if ( !v24 )
          goto yyerrlab;
yyreduce:
        v25 = yyr2[v24];
        yylen = v25;
        if ( v25 > 0 )
        {
          v26 = yyval.m_charbuffer;
          v27 = (int)&v5[-v25];
          v28 = *(PSRefBufferCharData<unsigned short> **)(v27 + 4);
          v29 = (PSRefBufferCharData<unsigned short> **)(v27 + 4);
          if ( yyval.m_charbuffer != v28 )
          {
            yyval.m_charbuffer = (PSRefBufferCharData<unsigned short> *)((char *)yyval.m_charbuffer - 20);
            if ( !InterlockedDecrement((volatile LONG *)&v26[-1].m_data[8]) && yyval.m_charbuffer )
              (**(void (__stdcall ***)(_DWORD))&yyval.m_charbuffer->m_data[0])(1);
            yyval.m_charbuffer = *v29;
            InterlockedIncrement((volatile LONG *)&yyval.m_charbuffer[-1].m_data[8]);
          }
        }
        switch ( yyvs1 )
        {
          case 9u:
            v50 = 0;
            v49 = v5[-1].m_charbuffer->m_data;
            goto LABEL_66;
          case 0xAu:
            v50 = 1;
            v49 = v5[-2].m_charbuffer->m_data;
LABEL_66:
            v33 = _wcstol(v49, 0, 10);
            StringTableMetaLanguage::r_Var(v5, v33, v50);
            break;
          case 0xBu:
            StringTableMetaLanguage::r_Var(v5, 0, 0);
            break;
          case 0xCu:
            StringTableMetaLanguage::r_Var(v5, 0, 1);
            break;
          case 0xDu:
            StringTableMetaLanguage::r_ChoiceBlockBegin(0);
            break;
          case 0xFu:
            v34 = _wcstol(v5[-1].m_charbuffer->m_data, 0, 10);
            StringTableMetaLanguage::r_ChoiceBlockBegin(v34);
            break;
          case 0xEu:
          case 0x10u:
            StringTableMetaLanguage::r_ChoiceBlockEnd();
            break;
          case 0x11u:
            StringTableMetaLanguage::r_OutsideInfoBlock(v5);
            break;
          case 0x16u:
            StringTableMetaLanguage::r_Text(v5);
            break;
          case 0x17u:
            StringTableMetaLanguage::r_Flags(v5);
            break;
          default:
            break;
        }
        v5 = (PStringBase<unsigned short> *)((char *)v5 + 4 - 4 * yylen);
        v35.m_charbuffer = v5->m_charbuffer;
        v4 -= yylen;
        if ( v5->m_charbuffer != yyval.m_charbuffer )
        {
          v36 = (int)&v35.m_charbuffer[-1].m_data[6];
          if ( !InterlockedDecrement((volatile LONG *)&v35.m_charbuffer[-1].m_data[8]) && v36 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v36)(v36, 1);
          v37 = yyval.m_charbuffer;
          v5->m_charbuffer = yyval.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&v37[-1].m_data[8]);
        }
        v38 = yyr1[(_DWORD)yyvs1];
        v39 = *v4 + yypact[v38 + 22];
        if ( v39 < 0 || v39 > 22 || yycheck[v39] != *v4 )
        {
          v6 = yydefact[v38 + 22];
          v3 = yyss;
          yylen = yydefact[v38 + 22];
        }
        else
        {
          v6 = yytable[v39];
          v3 = yyss;
          yylen = yytable[v39];
        }
      }
      v23 = yytable[(_DWORD)yyvs1];
      yyvs1 = (PStringBase<unsigned short> *)yytable[(_DWORD)yyvs1];
      if ( v23 < 0 )
      {
        if ( v23 == -32768 )
          break;
        v24 = -v23;
        yyvs1 = (PStringBase<unsigned short> *)v24;
        goto yyreduce;
      }
      if ( v23 )
      {
        if ( v23 == 33 )
          goto LABEL_94;
        if ( stringmeta_char )
          stringmeta_char = -2;
        ++v5;
        PStringBase<unsigned short>::operator=(v5, (const unsigned __int16 *)&stringmeta_lval);
        if ( yyerrstatus )
          --yyerrstatus;
        yylen = (int)yyvs1;
        continue;
      }
      break;
    }
yyerrlab:
    if ( yyerrstatus )
    {
      if ( yyerrstatus == 3 )
      {
        if ( !stringmeta_char )
        {
LABEL_95:
          v45 = (char *)&yyval.m_charbuffer[-1].m_data[6];
          if ( !InterlockedDecrement((volatile LONG *)&yyval.m_charbuffer[-1].m_data[8]) && v45 )
            (**(void (__thiscall ***)(char *, signed int))v45)(v45, 1);
          v46 = &yyss;
          yyss1 = (__int16 *)200;
          do
          {
            v47 = (int)*(v46 - 1);
            --v46;
            v48 = v47 - 20;
            if ( !InterlockedDecrement((volatile LONG *)(v48 + 4)) && v48 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))v48)(v48, 1);
            yyss1 = (__int16 *)((char *)yyss1 - 1);
          }
          while ( yyss1 );
          return 1;
        }
        stringmeta_char = -2;
      }
    }
    else
    {
      ++stringmeta_nerrs;
      stringmeta_error("parse error");
      v6 = yylen;
    }
    yyerrstatus = 3;
    while ( 2 )
    {
      v30 = yypact[v6];
      if ( v30 == -32768 )
        goto yyerrdefault;
      v31 = v30 + 1;
      if ( v31 < 0 || v31 > 22 || yycheck[v31] != 1 )
        goto yyerrdefault;
      v32 = yytable[v31];
      if ( v32 < 0 )
      {
        if ( v32 != -32768 )
        {
          yyvs1 = (PStringBase<unsigned short> *)-v32;
          v24 = -v32;
          goto yyreduce;
        }
        goto yyerrdefault;
      }
      if ( !yytable[v31] )
      {
yyerrdefault:
        if ( v4 == yyss )
          goto LABEL_95;
        v6 = *(v4 - 1);
        --v5;
        --v4;
        continue;
      }
      break;
    }
    if ( v32 != 33 )
    {
      ++v5;
      PStringBase<unsigned short>::operator=(v5, (const unsigned __int16 *)&stringmeta_lval);
      yylen = v32;
      v3 = yyss;
      continue;
    }
    break;
  }
LABEL_94:
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&yyval);
  vector_destructor_iterator(yyvsa, 4u, 200, (void (__thiscall *)(void *))PStringBase<char>::~PStringBase<char>);
  return 0;
}
// 8F78A0: using guessed type int stringmeta_nerrs;
// 8F78A4: using guessed type int stringmeta_char;

//----- (00715260) --------------------------------------------------------  // acclient.c:808101
int sub_715260()
{
  return atexit(nullsub_133);
}

//----- (00715270) --------------------------------------------------------  // acclient.c:808107
int _E4_31()
{
  return atexit(_E5_31);
}

//----- (00715280) --------------------------------------------------------  // acclient.c:808113
int _E7_31()
{
  Outside_CellID_31.id = Invalid_CellID_31.id + 1;
  return atexit(_E8_31);
}

//----- (007152A0) --------------------------------------------------------  // acclient.c:808120
int _E10_30()
{
  In_Limbo_CellID_30.id = Outside_CellID_31.id + 1;
  return atexit(_E11_30);
}

//----- (007152C0) --------------------------------------------------------  // acclient.c:808127
int _E13_30()
{
  First_Interior_CellID_30.id = In_Limbo_CellID_30.id + 1;
  return atexit(_E14_30);
}

//----- (007152E0) --------------------------------------------------------  // acclient.c:808134
int _E16_30()
{
  Last_Interior_CellID_30.id = Invalid_CellID_31.id - 1;
  return atexit(_E17_30);
}

//----- (00715300) --------------------------------------------------------  // acclient.c:808141
int _E21_33()
{
  return atexit(_E22_33);
}

//----- (00715310) --------------------------------------------------------  // acclient.c:808147
int _E40_32()
{
  return atexit(_E41_32);
}

//----- (00715320) --------------------------------------------------------  // acclient.c:808153
int _E43_35()
{
  return atexit(_E44_35);
}

//----- (00715330) --------------------------------------------------------  // acclient.c:808159
int sub_715330()
{
  stringmeta_lval.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  return atexit(sub_77F390);
}

//----- (0077F390) --------------------------------------------------------  // acclient.c:918025
void __cdecl sub_77F390()
{
  char *v0; // esi@1

  v0 = (char *)&stringmeta_lval.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&stringmeta_lval.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

