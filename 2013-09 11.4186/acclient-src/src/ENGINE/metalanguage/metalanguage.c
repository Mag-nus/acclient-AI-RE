/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : metalanguage
   Object     : ENGINE\metalanguage\metalanguage.obj
   Functions  : 20
   Addresses  : 0067C010 - 0077F240 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0067C010) --------------------------------------------------------  // acclient.c:658998
signed int __thiscall SmartArray<PStringBase<unsigned short>,1>::WhatNum(SmartArray<PStringBase<unsigned short>,1> *this, PStringBase<unsigned short> *i_rData)
{
  SmartArray<PStringBase<unsigned short>,1> *v2; // ebx@1
  signed int v3; // edi@1
  const wchar_t *v4; // eax@2
  int v5; // edx@3
  int v6; // esi@3
  signed int result; // eax@8

  v2 = this;
  v3 = 0;
  if ( this->m_num )
  {
    while ( 1 )
    {
      v4 = v2->m_data[v3].m_charbuffer->m_data;
      if ( *((_DWORD *)v4 - 1) == *(_DWORD *)&i_rData->m_charbuffer[-1].m_data[14] )
      {
        v5 = *((_DWORD *)v4 - 2);
        v6 = *(_DWORD *)&i_rData->m_charbuffer[-1].m_data[12];
        if ( (v5 == v6 || v5 == -1 || v6 == -1) && _wcscmp(v4, i_rData->m_charbuffer->m_data) == 0 )
          break;
      }
      ++v3;
      if ( v3 >= v2->m_num )
        goto LABEL_8;
    }
    result = v3;
  }
  else
  {
LABEL_8:
    result = -1;
  }
  return result;
}

//----- (0067C080) --------------------------------------------------------  // acclient.c:659036
int __cdecl StringTableMetaLanguage::GetMatchScore(PStringBase<unsigned short> *org, PStringBase<unsigned short> *match)
{
  int v2; // esi@1
  int v3; // edi@1
  PSRefBufferCharData<unsigned short> *v5; // eax@4
  unsigned int v6; // ecx@4
  int v7; // edx@4
  int v8; // eax@8
  int v9; // eax@13
  int score; // [sp+0h] [bp-4h]@1

  v2 = 0;
  v3 = *(_DWORD *)&match->m_charbuffer[-1].m_data[14] - 1;
  score = 0;
  if ( *(_DWORD *)&match->m_charbuffer[-1].m_data[14] == 1 )
    return 1;
  if ( v3 > 0 )
  {
    do
    {
      v5 = match->m_charbuffer;
      v6 = *(_DWORD *)&match->m_charbuffer[-1].m_data[14];
      v7 = (int)((char *)match->m_charbuffer + 2 * v6 - 2);
      if ( v2 < v6 )
        v7 = (int)((char *)v5 + 2 * v2);
      if ( *(_WORD *)v7 == 33 )
      {
        ++v2;
        if ( v2 < v6 )
          v8 = (int)((char *)v5 + 2 * v2);
        else
          v8 = (int)((char *)v5 + 2 * v6 - 2);
        if ( _wcschr(org->m_charbuffer->m_data, *(_WORD *)v8) )
          goto LABEL_17;
      }
      else
      {
        if ( v2 < v6 )
          v9 = (int)((char *)v5 + 2 * v2);
        else
          v9 = (int)((char *)v5 + 2 * v6 - 2);
        if ( !_wcschr(org->m_charbuffer->m_data, *(_WORD *)v9) )
          goto LABEL_17;
      }
      score += 2;
LABEL_17:
      ++v2;
    }
    while ( v2 < v3 );
  }
  return score;
}

//----- (0067C120) --------------------------------------------------------  // acclient.c:659090
void __cdecl StringTableMetaLanguage::SetError(StringTableMetaLanguage::RenderErr *err)
{
  char *v1; // esi@2

  StringTableMetaLanguage::curError.pos = err->pos;
  dword_8F77FC = err->code;
  if ( stru_8F7800.m_charbuffer != err->msg.m_charbuffer )
  {
    v1 = &stru_8F7800.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&stru_8F7800.m_charbuffer[-1]) )
    {
      if ( v1 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
    }
    stru_8F7800.m_charbuffer = err->msg.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&stru_8F7800.m_charbuffer[-1]);
  }
}
// 8F77F8: using guessed type struct StringTableMetaLanguage::RenderErr StringTableMetaLanguage::curError;
// 8F77FC: using guessed type int dword_8F77FC;

//----- (0067C180) --------------------------------------------------------  // acclient.c:659112
void __cdecl StringTableMetaLanguage::SetError(int pos, StringTableMetaLanguage::RenderErrorCode code, PStringBase<char> *msg)
{
  char *v3; // esi@2

  StringTableMetaLanguage::curError.pos = pos;
  dword_8F77FC = code;
  if ( stru_8F7800.m_charbuffer != msg->m_charbuffer )
  {
    v3 = &stru_8F7800.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&stru_8F7800.m_charbuffer[-1]) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    stru_8F7800.m_charbuffer = msg->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&stru_8F7800.m_charbuffer[-1]);
  }
}
// 8F77F8: using guessed type struct StringTableMetaLanguage::RenderErr StringTableMetaLanguage::curError;
// 8F77FC: using guessed type int dword_8F77FC;

//----- (0067C1E0) --------------------------------------------------------  // acclient.c:659134
StringTableMetaLanguage::Node *__cdecl StringTableMetaLanguage::ChooseChoice(StringTableMetaLanguage::Node *var, StringTableMetaLanguage::Node *choiceblock)
{
  ListNode<StringTableMetaLanguage::Node const *> *v2; // esi@1
  StringTableMetaLanguage::Node *v3; // ebx@1
  signed int i; // edi@1
  int v5; // eax@2

  v2 = choiceblock->children._head;
  v3 = 0;
  for ( i = -1; v2; v2 = v2->next )
  {
    v5 = StringTableMetaLanguage::GetMatchScore(&var->flags, &v2->data->flags);
    if ( v5 >= i && v5 > 0 )
    {
      v3 = v2->data;
      i = v5;
    }
  }
  return v3;
}

//----- (0067C230) --------------------------------------------------------  // acclient.c:659156
PStringBase<unsigned short> *__cdecl StringTableMetaLanguage::TakeValidLetters(PStringBase<unsigned short> *result, PStringBase<unsigned short> *validletters, PStringBase<unsigned short> *letters)
{
  PStringBase<unsigned short> *v3; // ebp@1
  PSRefBufferCharData<unsigned short> *v4; // eax@1
  unsigned int v5; // ecx@1
  unsigned int v6; // ebx@1
  int v7; // eax@3
  PSRefBufferCharData<unsigned short> *v8; // eax@6
  unsigned int v9; // ecx@6
  PStringBase<unsigned short> **v10; // eax@7
  unsigned int v11; // edi@10
  int v12; // ecx@10
  char *v13; // esi@13
  PSRefBufferCharData<unsigned short> *v14; // eax@18
  char *v15; // esi@18
  PStringBase<unsigned short> temp; // [sp+10h] [bp-4h]@1

  temp.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v3 = letters;
  v4 = letters->m_charbuffer;
  v5 = *(_DWORD *)&letters->m_charbuffer[-1].m_data[14];
  v6 = 0;
  if ( v5 != 1 )
  {
    do
    {
      if ( v6 < v5 )
        v7 = (int)((char *)v4 + 2 * v6);
      else
        v7 = (int)((char *)v4 + 2 * v5 - 2);
      if ( _wcschr(validletters->m_charbuffer->m_data, *(_WORD *)v7) )
      {
        v8 = v3->m_charbuffer;
        v9 = *(_DWORD *)&v3->m_charbuffer[-1].m_data[14];
        v10 = (PStringBase<unsigned short> **)(v6 < v9 ? (PSRefBufferCharData<unsigned short> *)((char *)v8 + 2 * v6) : (PSRefBufferCharData<unsigned short> *)((char *)v8 + 2 * v9 - 2));
        letters = (PStringBase<unsigned short> *)*(_WORD *)v10;
        if ( (_WORD)letters )
        {
          v11 = *(_DWORD *)&temp.m_charbuffer[-1].m_data[14];
          v12 = v11 + 1;
          if ( *(_DWORD *)&temp.m_charbuffer[-1].m_data[8] != 1
            || (unsigned int)v12 > *(_DWORD *)&temp.m_charbuffer[-1].m_data[10] )
          {
            v13 = (char *)&temp.m_charbuffer[-1].m_data[6];
            PStringBase<unsigned short>::allocate_ref_buffer(&temp, v11);
            _wcscpy(temp.m_charbuffer->m_data, (const wchar_t *)v13 + 10);
            if ( !InterlockedDecrement((volatile LONG *)v13 + 1) && v13 )
              (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
          }
          else
          {
            *(_DWORD *)&temp.m_charbuffer[-1].m_data[14] = v12;
            *(_DWORD *)&temp.m_charbuffer[-1].m_data[12] = -1;
          }
          _wcsncpy((wchar_t *)temp.m_charbuffer + v11 - 1, (const wchar_t *)&letters, 1u);
          temp.m_charbuffer->m_data[*(_DWORD *)&temp.m_charbuffer[-1].m_data[14] - 1] = 0;
        }
      }
      v4 = v3->m_charbuffer;
      v5 = *(_DWORD *)&v3->m_charbuffer[-1].m_data[14];
      ++v6;
    }
    while ( v6 < v5 - 1 );
  }
  v14 = temp.m_charbuffer;
  result->m_charbuffer = temp.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v14[-1].m_data[8]);
  v15 = (char *)&temp.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&temp.m_charbuffer[-1].m_data[8]) && v15 )
    (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
  return result;
}

//----- (0067C390) --------------------------------------------------------  // acclient.c:659231
List<StringTableMetaLanguage::Node const *> *__thiscall List<StringTableMetaLanguage::Node const *>::vector_deleting_destructor(List<StringTableMetaLanguage::Node const *> *this, unsigned int a2)
{
  List<StringTableMetaLanguage::Node const *> *v2; // esi@1

  v2 = this;
  this->vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7FE1E0: using guessed type int (__thiscall *List<StringTableMetaLanguage::Node const *>::vftable)(void *, char);

//----- (0067C3C0) --------------------------------------------------------  // acclient.c:659245
char __cdecl StringTableMetaLanguage::RenderNodes(StringTableMetaLanguage::Node *root, PStringBase<unsigned short> *result, SmartArray<PStringBase<unsigned short>,1> *outsideVars, int idxPre, int idxMid, int idxPost)
{
  ListNode<StringTableMetaLanguage::Node const *> *v6; // edi@1
  ListNode<StringTableMetaLanguage::Node const *> *v7; // ebx@1
  ListNode<StringTableMetaLanguage::Node const *> *v8; // ebp@1
  SmartArray<PStringBase<unsigned short>,1> *v9; // ebp@2
  StringTableMetaLanguage::NodeType v10; // eax@3
  void *v11; // eax@4
  ListNode<StringTableMetaLanguage::Node const *> *v12; // ecx@7
  void *v13; // eax@9
  ListNode<StringTableMetaLanguage::Node const *> *v14; // ecx@12
  const wchar_t *v15; // eax@14
  PSRefBufferCharData<unsigned short> *v16; // ecx@14
  bool v17; // bl@15
  int v18; // edx@16
  int v19; // esi@16
  int v20; // eax@20
  int v21; // esi@21
  ListNode<StringTableMetaLanguage::Node const *> *v22; // esi@29
  ListNode<StringTableMetaLanguage::Node const *> *v23; // ecx@30
  int v24; // edx@31
  ListNode<StringTableMetaLanguage::Node const *> *v25; // eax@34
  PStringBase<unsigned short> *v26; // ebx@41
  PSRefBufferCharData<unsigned short> *v27; // eax@41
  bool v28; // zf@41
  LONG (__stdcall *v29)(volatile LONG *); // edi@41
  int v30; // esi@42
  volatile LONG *v31; // ST08_4@45
  ListNode<StringTableMetaLanguage::Node const *> *v32; // eax@46
  StringTableMetaLanguage::Node *v33; // esi@47
  char *v34; // esi@49
  char *v35; // esi@53
  ListNode<StringTableMetaLanguage::Node const *> *v36; // eax@56
  void *v37; // ecx@58
  ListNode<StringTableMetaLanguage::Node const *> *v38; // eax@64
  void *v39; // ecx@66
  char *v40; // esi@73
  char *v41; // esi@77
  ListNode<StringTableMetaLanguage::Node const *> *v42; // eax@80
  void *v43; // ecx@82
  ListNode<StringTableMetaLanguage::Node const *> *v44; // eax@88
  void *v45; // ecx@90
  const unsigned __int16 *v46; // esi@96
  int v47; // eax@96
  PSRefBufferCharData<unsigned short> *v48; // esi@105
  const wchar_t **v49; // eax@120
  PSRefBufferCharData<unsigned short> *v50; // eax@121
  int v51; // ecx@121
  int v52; // esi@123
  const wchar_t *v53; // esi@127
  unsigned int v54; // eax@129
  StringTableMetaLanguage::Node *v55; // eax@131
  int v56; // ecx@131
  StringTableMetaLanguage::Node **v57; // eax@134
  ListNode<StringTableMetaLanguage::Node const *> *v58; // ecx@134
  char *v59; // esi@144
  void *v60; // esi@148
  StringTableMetaLanguage::Node *v61; // eax@149
  const unsigned __int16 *v62; // eax@150
  int v63; // ecx@150
  StringTableMetaLanguage::Node *v64; // eax@155
  const unsigned __int16 *v65; // eax@156
  int v66; // ecx@156
  char *v67; // esi@159
  int v68; // esi@164
  ListNode<StringTableMetaLanguage::Node const *> *v69; // eax@176
  void *v70; // ecx@178
  ListNode<StringTableMetaLanguage::Node const *> *v71; // eax@184
  void *v72; // ecx@186
  char *v73; // esi@193
  char *v74; // esi@197
  ListNode<StringTableMetaLanguage::Node const *> *v75; // eax@209
  void *v76; // ecx@211
  ListNode<StringTableMetaLanguage::Node const *> *v77; // eax@217
  void *v78; // ecx@219
  char v79; // al@225
  PSRefBufferCharData<unsigned short> *v80; // eax@227
  int v81; // ecx@227
  char *v82; // esi@229
  PSRefBufferCharData<unsigned short> *v83; // eax@232
  int v84; // ecx@232
  char *v85; // esi@234
  PSRefBufferCharData<unsigned short> *v86; // eax@237
  int v87; // ecx@237
  char *v88; // esi@239
  char *v89; // esi@242
  char *v90; // esi@245
  char *v91; // esi@248
  char *v92; // esi@251
  char *v93; // esi@254
  char *v94; // esi@257
  char *v95; // esi@260
  ListNode<StringTableMetaLanguage::Node const *> *v96; // eax@263
  void *v97; // ecx@265
  ListNode<StringTableMetaLanguage::Node const *> *v98; // eax@271
  void *v99; // ecx@273
  bool bUseHackyItemRule; // [sp+13h] [bp-4Dh]@1
  PStringBase<unsigned short> item_suffix; // [sp+14h] [bp-4Ch]@41
  PStringBase<unsigned short> item_mid; // [sp+18h] [bp-48h]@41
  PStringBase<unsigned short> item_prefix; // [sp+1Ch] [bp-44h]@41
  PStringBase<char> v104; // [sp+20h] [bp-40h]@143
  PStringBase<unsigned short> valid_pre; // [sp+24h] [bp-3Ch]@158
  PStringBase<unsigned short> valid_mid; // [sp+28h] [bp-38h]@192
  PStringBase<unsigned short> valid_post; // [sp+2Ch] [bp-34h]@14
  PStringBase<unsigned short> resulta; // [sp+30h] [bp-30h]@121
  ListIterator<StringTableMetaLanguage::Node const *> i; // [sp+34h] [bp-2Ch]@46
  List<StringTableMetaLanguage::Node const *> v110; // [sp+40h] [bp-20h]@1
  List<StringTableMetaLanguage::Node const *> choice_nodes; // [sp+50h] [bp-10h]@1

  v110.vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
  choice_nodes.vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
  v6 = root->children._head;
  v7 = 0;
  v8 = 0;
  v110._head = 0;
  v110._tail = 0;
  v110._num_elements = 0;
  choice_nodes._head = 0;
  choice_nodes._tail = 0;
  choice_nodes._num_elements = 0;
  bUseHackyItemRule = 0;
  if ( v6 )
  {
    v9 = outsideVars;
    do
    {
      v10 = v6->data->type;
      switch ( v10 )
      {
        case 3:
          v11 = operator new(0xCu);
          if ( v11 )
          {
            *(_DWORD *)v11 = v6->data;
            *((_DWORD *)v11 + 1) = 0;
            *((_DWORD *)v11 + 2) = 0;
            if ( v110._head )
            {
              v12 = v110._tail;
              v110._tail->next = (ListNode<StringTableMetaLanguage::Node const *> *)v11;
              *((_DWORD *)v11 + 2) = v12;
              v110._tail = (ListNode<StringTableMetaLanguage::Node const *> *)v11;
              ++v110._num_elements;
            }
            else
            {
              v110._head = (ListNode<StringTableMetaLanguage::Node const *> *)v11;
              v110._tail = (ListNode<StringTableMetaLanguage::Node const *> *)v11;
              ++v110._num_elements;
            }
          }
          break;
        case 4:
          v13 = operator new(0xCu);
          if ( v13 )
          {
            *(_DWORD *)v13 = v6->data;
            *((_DWORD *)v13 + 1) = 0;
            *((_DWORD *)v13 + 2) = 0;
            if ( choice_nodes._head )
            {
              v14 = choice_nodes._tail;
              choice_nodes._tail->next = (ListNode<StringTableMetaLanguage::Node const *> *)v13;
              *((_DWORD *)v13 + 2) = v14;
              choice_nodes._tail = (ListNode<StringTableMetaLanguage::Node const *> *)v13;
              ++choice_nodes._num_elements;
            }
            else
            {
              choice_nodes._head = (ListNode<StringTableMetaLanguage::Node const *> *)v13;
              choice_nodes._tail = (ListNode<StringTableMetaLanguage::Node const *> *)v13;
              ++choice_nodes._num_elements;
            }
          }
          break;
        case 5:
          PStringBase<unsigned short>::PStringBase<unsigned short>(&valid_post, L"item");
          v15 = v6->data->text.m_charbuffer->m_data;
          v16 = valid_post.m_charbuffer;
          if ( *((_DWORD *)v15 - 1) == *(_DWORD *)&valid_post.m_charbuffer[-1].m_data[14] )
          {
            v18 = *((_DWORD *)v15 - 2);
            v19 = *(_DWORD *)&valid_post.m_charbuffer[-1].m_data[12];
            if ( v18 == v19 || v18 == -1 || v19 == -1 )
            {
              v20 = _wcscmp(v15, valid_post.m_charbuffer->m_data);
              v16 = valid_post.m_charbuffer;
              v17 = v20 == 0;
            }
            else
            {
              v17 = 0;
            }
          }
          else
          {
            v17 = 0;
          }
          v21 = (int)&v16[-1].m_data[6];
          if ( !InterlockedDecrement((volatile LONG *)&v16[-1].m_data[8]) && v21 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
          if ( v17 )
            bUseHackyItemRule = 1;
          SmartArray<PStringBase<unsigned short>,1>::AddToEnd(v9, &v6->data->text);
          break;
      }
      v6 = v6->next;
    }
    while ( v6 );
    v7 = choice_nodes._head;
    v8 = v110._head;
  }
  v22 = v8;
  if ( v8 )
  {
    while ( 1 )
    {
      v23 = v8;
      if ( v22 != v8 )
        break;
LABEL_39:
      if ( v22 )
      {
        v22 = v22->next;
        if ( v22 )
          continue;
      }
      goto LABEL_41;
    }
    v24 = v22->data->ID;
    while ( 1 )
    {
      if ( v23->data->ID == v24 )
      {
        if ( v24 )
        {
          PStringBase<char>::allocate_ref_buffer(
            (PStringBase<char> *)&root,
            strlen("multiple variables with the same ID; ambiguity"));
          strcpy((char *)root, "multiple variables with the same ID; ambiguity");
          StringTableMetaLanguage::curError.pos = v22->data->pos;
          dword_8F77FC = 2;
          if ( (StringTableMetaLanguage::Node *)stru_8F7800.m_charbuffer != root )
          {
            v40 = &stru_8F7800.m_charbuffer[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&stru_8F7800.m_charbuffer[-1]) && v40 )
              (**(void (__thiscall ***)(char *, signed int))v40)(v40, 1);
            stru_8F7800.m_charbuffer = (PSRefBufferCharData<char> *)root;
            InterlockedIncrement(&root[-1].ID);
          }
          v41 = (char *)&root[-1].children._num_elements;
          if ( !InterlockedDecrement(&root[-1].ID) && v41 )
            (**(void (__thiscall ***)(char *, signed int))v41)(v41, 1);
          v42 = choice_nodes._head;
          choice_nodes.vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
          while ( v42 )
          {
            v43 = v42;
            v42 = v42->next;
            choice_nodes._head = v42;
            if ( v42 )
            {
              v42->prev = 0;
              v42 = choice_nodes._head;
            }
            else
            {
              choice_nodes._tail = 0;
            }
            if ( v43 )
            {
              operator delete(v43);
              v42 = choice_nodes._head;
            }
            --choice_nodes._num_elements;
          }
          v44 = v110._head;
          v110.vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
          while ( v44 )
          {
            v45 = v44;
            v44 = v44->next;
            v110._head = v44;
            if ( v44 )
            {
              v44->prev = 0;
              v44 = v110._head;
            }
            else
            {
              v110._tail = 0;
            }
            if ( v45 )
            {
              operator delete(v45);
              v44 = v110._head;
            }
            --v110._num_elements;
          }
          goto LABEL_225;
        }
        v25 = v7;
        if ( v7 )
          break;
      }
LABEL_38:
      v23 = v23->next;
      if ( v22 == v23 )
        goto LABEL_39;
    }
    while ( v25->data->ID )
    {
      v25 = v25->next;
      if ( !v25 )
      {
        v8 = v110._head;
        goto LABEL_38;
      }
    }
    PStringBase<char>::allocate_ref_buffer(
      (PStringBase<char> *)&root,
      strlen("multiple un-numbered variables; ambiguity"));
    strcpy((char *)root, "multiple un-numbered variables; ambiguity");
    StringTableMetaLanguage::curError.pos = v22->data->pos;
    dword_8F77FC = 2;
    if ( (StringTableMetaLanguage::Node *)stru_8F7800.m_charbuffer != root )
    {
      v34 = &stru_8F7800.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&stru_8F7800.m_charbuffer[-1]) && v34 )
        (**(void (__thiscall ***)(char *, signed int))v34)(v34, 1);
      stru_8F7800.m_charbuffer = (PSRefBufferCharData<char> *)root;
      InterlockedIncrement(&root[-1].ID);
    }
    v35 = (char *)&root[-1].children._num_elements;
    if ( !InterlockedDecrement(&root[-1].ID) && v35 )
      (**(void (__thiscall ***)(char *, signed int))v35)(v35, 1);
    v36 = choice_nodes._head;
    choice_nodes.vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
    while ( v36 )
    {
      v37 = v36;
      v36 = v36->next;
      choice_nodes._head = v36;
      if ( v36 )
      {
        v36->prev = 0;
        v36 = choice_nodes._head;
      }
      else
      {
        choice_nodes._tail = 0;
      }
      if ( v37 )
      {
        operator delete(v37);
        v36 = choice_nodes._head;
      }
      --choice_nodes._num_elements;
    }
    v38 = v110._head;
    v110.vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
    while ( v38 )
    {
      v39 = v38;
      v38 = v38->next;
      v110._head = v38;
      if ( v38 )
      {
        v38->prev = 0;
        v38 = v110._head;
      }
      else
      {
        v110._tail = 0;
      }
      if ( v39 )
      {
        operator delete(v39);
        v38 = v110._head;
      }
      --v110._num_elements;
    }
LABEL_225:
    v79 = 0;
  }
  else
  {
LABEL_41:
    item_prefix.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    item_mid.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    item_suffix.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    v26 = result;
    v27 = result->m_charbuffer;
    v28 = result->m_charbuffer == (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    valid_post.m_charbuffer = 0;
    v29 = InterlockedDecrement;
    if ( !v28 )
    {
      v30 = (int)&v27[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v27[-1].m_data[8]) && v30 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v30)(v30, 1);
      v31 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
      v26->m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement(v31);
    }
    i._current = root->children._head;
    v32 = i._current;
    if ( i._current )
    {
      while ( 1 )
      {
        v33 = v32->data;
        switch ( v32->data->type )
        {
          case 2:
            v46 = v33->text.m_charbuffer->m_data;
            v47 = *((_DWORD *)v46 - 1);
            if ( v47 != 1 )
              PStringBase<unsigned short>::append_n_chars(v26, v46, v47 - 1);
            goto $L78062;
          case 3:
            if ( v33->ID < 0 )
              goto $L78062;
            if ( !bUseHackyItemRule )
              goto LABEL_120;
            if ( valid_post.m_charbuffer == (PSRefBufferCharData<unsigned short> *)idxPre )
            {
              if ( item_prefix.m_charbuffer == v33->flags.m_charbuffer )
                goto LABEL_119;
              if ( !InterlockedDecrement((volatile LONG *)&item_prefix.m_charbuffer[-1].m_data[8])
                && item_prefix.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
                (**(void (__thiscall ***)(unsigned __int16 *, signed int))&item_prefix.m_charbuffer[-1].m_data[6])(
                  &item_prefix.m_charbuffer[-1].m_data[6],
                  1);
              v48 = v33->flags.m_charbuffer;
              item_prefix.m_charbuffer = v48;
              goto LABEL_118;
            }
            if ( valid_post.m_charbuffer == (PSRefBufferCharData<unsigned short> *)idxMid )
            {
              if ( item_mid.m_charbuffer == v33->flags.m_charbuffer )
                goto LABEL_119;
              if ( !InterlockedDecrement((volatile LONG *)&item_mid.m_charbuffer[-1].m_data[8])
                && item_mid.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
                (**(void (__thiscall ***)(unsigned __int16 *, signed int))&item_mid.m_charbuffer[-1].m_data[6])(
                  &item_mid.m_charbuffer[-1].m_data[6],
                  1);
              v48 = v33->flags.m_charbuffer;
              item_mid.m_charbuffer = v48;
              goto LABEL_118;
            }
            if ( valid_post.m_charbuffer == (PSRefBufferCharData<unsigned short> *)idxPost
              && item_suffix.m_charbuffer != v33->flags.m_charbuffer )
            {
              if ( !InterlockedDecrement((volatile LONG *)&item_suffix.m_charbuffer[-1].m_data[8])
                && item_suffix.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
                (**(void (__thiscall ***)(unsigned __int16 *, signed int))&item_suffix.m_charbuffer[-1].m_data[6])(
                  &item_suffix.m_charbuffer[-1].m_data[6],
                  1);
              v48 = v33->flags.m_charbuffer;
              item_suffix.m_charbuffer = v48;
LABEL_118:
              InterlockedIncrement((volatile LONG *)&v48[-1].m_data[8]);
              v29 = InterlockedDecrement;
            }
LABEL_119:
            ++valid_post.m_charbuffer;
LABEL_120:
            v49 = (const wchar_t **)i._current->data;
            if ( i._current->data->bForceCapital )
            {
              v50 = StringTableMetaLanguage::CapitalizeFirstLetter(&resulta, &i._current->data->text)->m_charbuffer;
              v51 = *(_DWORD *)&v50[-1].m_data[14];
              if ( v51 != 1 )
                PStringBase<unsigned short>::append_n_chars(v26, v50->m_data, v51 - 1);
              v52 = (int)&resulta.m_charbuffer[-1].m_data[6];
            }
            else
            {
              v53 = *v49;
              if ( *v49 && *v53 )
              {
                v54 = _wcslen(*v49);
                PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)&root, v54);
                _wcscpy((wchar_t *)root, v53);
              }
              else
              {
                root = (StringTableMetaLanguage::Node *)PStringBase<unsigned short>::s_NullBuffer;
                InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
              }
              v55 = root;
              v56 = root[-1].pos;
              if ( v56 != 1 )
              {
                PStringBase<unsigned short>::append_n_chars(v26, (const unsigned __int16 *)root, v56 - 1);
                v55 = root;
              }
              v52 = (int)&v55[-1].children._num_elements;
            }
            if ( !v29((volatile LONG *)(v52 + 4)) && v52 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))v52)(v52, 1);
$L78062:
            i._current = i._current->next;
            v32 = i._current;
            if ( !i._current )
              goto LABEL_226;
            break;
          case 4:
            v57 = &v110._head->data;
            v58 = v110._head;
            if ( !v110._head )
              goto LABEL_138;
            do
            {
              if ( v58->data->ID == v33->ID )
              {
                v61 = StringTableMetaLanguage::ChooseChoice(v58->data, v33);
                if ( v61 )
                {
                  v62 = v61->text.m_charbuffer->m_data;
                  v63 = *((_DWORD *)v62 - 1);
                  if ( v63 != 1 )
                    PStringBase<unsigned short>::append_n_chars(v26, v62, v63 - 1);
                }
                v29 = InterlockedDecrement;
                goto $L78062;
              }
              v58 = v58->next;
            }
            while ( v58 );
            v29 = InterlockedDecrement;
LABEL_138:
            if ( v33->ID || !v110._head )
            {
LABEL_142:
              if ( i._current->data->ID )
              {
                PStringBase<char>::allocate_ref_buffer(
                  (PStringBase<char> *)&valid_pre,
                  strlen("no variable has the same ID as this choice block"));
                strcpy((char *)valid_pre.m_charbuffer, "no variable has the same ID as this choice block");
                StringTableMetaLanguage::curError.pos = i._current->data->pos;
                dword_8F77FC = 1;
                if ( stru_8F7800.m_charbuffer != (PSRefBufferCharData<char> *)valid_pre.m_charbuffer )
                {
                  v67 = &stru_8F7800.m_charbuffer[-2].m_data[12];
                  if ( !v29((volatile LONG *)&stru_8F7800.m_charbuffer[-1]) && v67 )
                    (**(void (__thiscall ***)(char *, signed int))v67)(v67, 1);
                  stru_8F7800.m_charbuffer = (PSRefBufferCharData<char> *)valid_pre.m_charbuffer;
                  InterlockedIncrement((volatile LONG *)&valid_pre.m_charbuffer[-1].m_data[8]);
                }
                v60 = valid_pre.m_charbuffer;
              }
              else
              {
                PStringBase<char>::allocate_ref_buffer(
                  &v104,
                  strlen("no default variable exists to match with this default choice block"));
                strcpy(v104.m_charbuffer->m_data, "no default variable exists to match with this default choice block");
                StringTableMetaLanguage::curError.pos = i._current->data->pos;
                dword_8F77FC = 1;
                if ( stru_8F7800.m_charbuffer != v104.m_charbuffer )
                {
                  v59 = &stru_8F7800.m_charbuffer[-2].m_data[12];
                  if ( !v29((volatile LONG *)&stru_8F7800.m_charbuffer[-1]) && v59 )
                    (**(void (__thiscall ***)(char *, signed int))v59)(v59, 1);
                  stru_8F7800.m_charbuffer = v104.m_charbuffer;
                  InterlockedIncrement((volatile LONG *)&v104.m_charbuffer[-1]);
                }
                v60 = v104.m_charbuffer;
              }
              v68 = (int)((char *)v60 - 20);
              if ( !v29((volatile LONG *)(v68 + 4)) && v68 )
                (**(void (__thiscall ***)(_DWORD, _DWORD))v68)(v68, 1);
              if ( !v29((volatile LONG *)&item_suffix.m_charbuffer[-1].m_data[8])
                && item_suffix.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
                (**(void (__thiscall ***)(unsigned __int16 *, signed int))&item_suffix.m_charbuffer[-1].m_data[6])(
                  &item_suffix.m_charbuffer[-1].m_data[6],
                  1);
              if ( !v29((volatile LONG *)&item_mid.m_charbuffer[-1].m_data[8])
                && item_mid.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
                (**(void (__thiscall ***)(unsigned __int16 *, signed int))&item_mid.m_charbuffer[-1].m_data[6])(
                  &item_mid.m_charbuffer[-1].m_data[6],
                  1);
              if ( !v29((volatile LONG *)&item_prefix.m_charbuffer[-1].m_data[8])
                && item_prefix.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
                (**(void (__thiscall ***)(unsigned __int16 *, signed int))&item_prefix.m_charbuffer[-1].m_data[6])(
                  &item_prefix.m_charbuffer[-1].m_data[6],
                  1);
              v69 = choice_nodes._head;
              choice_nodes.vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
              while ( v69 )
              {
                v70 = v69;
                v69 = v69->next;
                choice_nodes._head = v69;
                if ( v69 )
                {
                  v69->prev = 0;
                  v69 = choice_nodes._head;
                }
                else
                {
                  choice_nodes._tail = 0;
                }
                if ( v70 )
                {
                  operator delete(v70);
                  v69 = choice_nodes._head;
                }
                --choice_nodes._num_elements;
              }
              v71 = v110._head;
              v110.vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
              while ( v71 )
              {
                v72 = v71;
                v71 = v71->next;
                v110._head = v71;
                if ( v71 )
                {
                  v71->prev = 0;
                  v71 = v110._head;
                }
                else
                {
                  v110._tail = 0;
                }
                if ( v72 )
                {
                  operator delete(v72);
                  v71 = v110._head;
                }
                --v110._num_elements;
              }
              goto LABEL_225;
            }
            while ( (*v57)->ID != -1 )
            {
              v57 = (StringTableMetaLanguage::Node **)v57[1];
              if ( !v57 )
                goto LABEL_142;
            }
            v64 = StringTableMetaLanguage::ChooseChoice(*v57, v33);
            if ( v64 )
            {
              v65 = v64->text.m_charbuffer->m_data;
              v66 = *((_DWORD *)v65 - 1);
              if ( v66 != 1 )
                PStringBase<unsigned short>::append_n_chars(v26, v65, v66 - 1);
            }
            goto $L78062;
          case 5:
            goto $L78062;
          default:
            PStringBase<char>::allocate_ref_buffer((PStringBase<char> *)&valid_mid, strlen("unknown node type"));
            strcpy((char *)valid_mid.m_charbuffer, "unknown node type");
            StringTableMetaLanguage::curError.pos = i._current->data->pos;
            dword_8F77FC = 4;
            if ( stru_8F7800.m_charbuffer != (PSRefBufferCharData<char> *)valid_mid.m_charbuffer )
            {
              v73 = &stru_8F7800.m_charbuffer[-2].m_data[12];
              if ( !v29((volatile LONG *)&stru_8F7800.m_charbuffer[-1]) && v73 )
                (**(void (__thiscall ***)(char *, signed int))v73)(v73, 1);
              stru_8F7800.m_charbuffer = (PSRefBufferCharData<char> *)valid_mid.m_charbuffer;
              InterlockedIncrement((volatile LONG *)&valid_mid.m_charbuffer[-1].m_data[8]);
            }
            v74 = (char *)&valid_mid.m_charbuffer[-1].m_data[6];
            if ( !v29((volatile LONG *)&valid_mid.m_charbuffer[-1].m_data[8]) && v74 )
              (**(void (__thiscall ***)(char *, signed int))v74)(v74, 1);
            if ( !v29((volatile LONG *)&item_suffix.m_charbuffer[-1].m_data[8])
              && item_suffix.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))&item_suffix.m_charbuffer[-1].m_data[6])(
                &item_suffix.m_charbuffer[-1].m_data[6],
                1);
            if ( !v29((volatile LONG *)&item_mid.m_charbuffer[-1].m_data[8])
              && item_mid.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))&item_mid.m_charbuffer[-1].m_data[6])(
                &item_mid.m_charbuffer[-1].m_data[6],
                1);
            if ( !v29((volatile LONG *)&item_prefix.m_charbuffer[-1].m_data[8])
              && item_prefix.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))&item_prefix.m_charbuffer[-1].m_data[6])(
                &item_prefix.m_charbuffer[-1].m_data[6],
                1);
            v75 = choice_nodes._head;
            choice_nodes.vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
            while ( v75 )
            {
              v76 = v75;
              v75 = v75->next;
              choice_nodes._head = v75;
              if ( v75 )
              {
                v75->prev = 0;
                v75 = choice_nodes._head;
              }
              else
              {
                choice_nodes._tail = 0;
              }
              if ( v76 )
              {
                operator delete(v76);
                v75 = choice_nodes._head;
              }
              --choice_nodes._num_elements;
            }
            v77 = v110._head;
            v110.vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
            while ( v77 )
            {
              v78 = v77;
              v77 = v77->next;
              v110._head = v77;
              if ( v77 )
              {
                v77->prev = 0;
                v77 = v110._head;
              }
              else
              {
                v110._tail = 0;
              }
              if ( v78 )
              {
                operator delete(v78);
                v77 = v110._head;
              }
              --v110._num_elements;
            }
            goto LABEL_225;
        }
      }
    }
LABEL_226:
    if ( bUseHackyItemRule )
    {
      valid_pre.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      valid_mid.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      valid_post.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      StringTableMetaLanguage::GetTreasureMetaLetters(&valid_pre, &valid_mid, &valid_post);
      root = (StringTableMetaLanguage::Node *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      v80 = StringTableMetaLanguage::TakeValidLetters(&resulta, &valid_pre, &item_prefix)->m_charbuffer;
      v81 = *(_DWORD *)&v80[-1].m_data[14];
      if ( v81 != 1 )
        PStringBase<unsigned short>::append_n_chars((PStringBase<unsigned short> *)&root, v80->m_data, v81 - 1);
      v82 = (char *)&resulta.m_charbuffer[-1].m_data[6];
      if ( !v29((volatile LONG *)&resulta.m_charbuffer[-1].m_data[8]) && v82 )
        (**(void (__thiscall ***)(char *, signed int))v82)(v82, 1);
      v83 = StringTableMetaLanguage::TakeValidLetters(&resulta, &valid_mid, &item_mid)->m_charbuffer;
      v84 = *(_DWORD *)&v83[-1].m_data[14];
      if ( v84 != 1 )
        PStringBase<unsigned short>::append_n_chars((PStringBase<unsigned short> *)&root, v83->m_data, v84 - 1);
      v85 = (char *)&resulta.m_charbuffer[-1].m_data[6];
      if ( !v29((volatile LONG *)&resulta.m_charbuffer[-1].m_data[8]) && v85 )
        (**(void (__thiscall ***)(char *, signed int))v85)(v85, 1);
      v86 = StringTableMetaLanguage::TakeValidLetters(&resulta, &valid_post, &item_suffix)->m_charbuffer;
      v87 = *(_DWORD *)&v86[-1].m_data[14];
      if ( v87 != 1 )
        PStringBase<unsigned short>::append_n_chars((PStringBase<unsigned short> *)&root, v86->m_data, v87 - 1);
      v88 = (char *)&resulta.m_charbuffer[-1].m_data[6];
      if ( !v29((volatile LONG *)&resulta.m_charbuffer[-1].m_data[8]) && v88 )
        (**(void (__thiscall ***)(char *, signed int))v88)(v88, 1);
      PStringBase<unsigned short>::sprintf_append(v26, L"[%ls]", root);
      v89 = (char *)&root[-1].children._num_elements;
      if ( !v29(&root[-1].ID) && v89 )
        (**(void (__thiscall ***)(char *, signed int))v89)(v89, 1);
      v90 = (char *)&valid_post.m_charbuffer[-1].m_data[6];
      if ( !v29((volatile LONG *)&valid_post.m_charbuffer[-1].m_data[8]) && v90 )
        (**(void (__thiscall ***)(char *, signed int))v90)(v90, 1);
      v91 = (char *)&valid_mid.m_charbuffer[-1].m_data[6];
      if ( !v29((volatile LONG *)&valid_mid.m_charbuffer[-1].m_data[8]) && v91 )
        (**(void (__thiscall ***)(char *, signed int))v91)(v91, 1);
      v92 = (char *)&valid_pre.m_charbuffer[-1].m_data[6];
      if ( !v29((volatile LONG *)&valid_pre.m_charbuffer[-1].m_data[8]) && v92 )
        (**(void (__thiscall ***)(char *, signed int))v92)(v92, 1);
    }
    v93 = (char *)&item_suffix.m_charbuffer[-1].m_data[6];
    if ( !v29((volatile LONG *)&item_suffix.m_charbuffer[-1].m_data[8]) && v93 )
      (**(void (__thiscall ***)(char *, signed int))v93)(v93, 1);
    v94 = (char *)&item_mid.m_charbuffer[-1].m_data[6];
    if ( !v29((volatile LONG *)&item_mid.m_charbuffer[-1].m_data[8]) && v94 )
      (**(void (__thiscall ***)(char *, signed int))v94)(v94, 1);
    v95 = (char *)&item_prefix.m_charbuffer[-1].m_data[6];
    if ( !v29((volatile LONG *)&item_prefix.m_charbuffer[-1].m_data[8]) && v95 )
      (**(void (__thiscall ***)(char *, signed int))v95)(v95, 1);
    v96 = choice_nodes._head;
    choice_nodes.vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
    while ( v96 )
    {
      v97 = v96;
      v96 = v96->next;
      choice_nodes._head = v96;
      if ( v96 )
      {
        v96->prev = 0;
        v96 = choice_nodes._head;
      }
      else
      {
        choice_nodes._tail = 0;
      }
      if ( v97 )
      {
        operator delete(v97);
        v96 = choice_nodes._head;
      }
      --choice_nodes._num_elements;
    }
    v98 = v110._head;
    v110.vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
    while ( v98 )
    {
      v99 = v98;
      v98 = v98->next;
      v110._head = v98;
      if ( v98 )
      {
        v98->prev = 0;
        v98 = v110._head;
      }
      else
      {
        v110._tail = 0;
      }
      if ( v99 )
      {
        operator delete(v99);
        v98 = v110._head;
      }
      --v110._num_elements;
    }
    v79 = 1;
  }
  return v79;
}
// 7FE1E0: using guessed type int (__thiscall *List<StringTableMetaLanguage::Node const *>::vftable)(void *, char);
// 8F77F8: using guessed type struct StringTableMetaLanguage::RenderErr StringTableMetaLanguage::curError;
// 8F77FC: using guessed type int dword_8F77FC;

//----- (0067D150) --------------------------------------------------------  // acclient.c:660095
BOOL __cdecl StringTableMetaLanguage::RenderString(SmartArray<PStringBase<unsigned short>,1> *textparts, SmartArray<PStringBase<unsigned short>,1> *varparts, SmartArray<PStringBase<unsigned short>,1> *varnames, PStringBase<unsigned short> *result, SmartArray<PStringBase<unsigned short>,1> *outsideVars, unsigned int OptionFlags, StringTableMetaLanguage::RenderErr *pErrReport)
{
  SmartArray<PStringBase<unsigned short>,1> *v7; // ebp@1
  bool v8; // zf@1
  unsigned int v9; // eax@2
  PSRefBufferCharData<unsigned short> *v10; // ecx@2
  int v11; // edi@2
  const wchar_t *v12; // eax@2
  bool v13; // bl@3
  int v14; // edx@4
  int v15; // esi@4
  int v16; // eax@8
  int v17; // esi@9
  unsigned int v18; // eax@14
  const wchar_t *v19; // eax@14
  int v20; // edx@15
  int v21; // esi@15
  unsigned int v22; // eax@19
  PSRefBufferCharData<unsigned short> *v23; // ecx@19
  const wchar_t *v24; // eax@19
  bool v25; // bl@20
  int v26; // edx@21
  int v27; // esi@21
  int v28; // eax@25
  int v29; // esi@26
  char *v30; // esi@31
  unsigned int v31; // eax@36
  PSRefBufferCharData<unsigned short> *v32; // ecx@36
  const wchar_t *v33; // eax@36
  bool v34; // bl@37
  int v35; // edx@38
  int v36; // esi@38
  int v37; // eax@42
  int v38; // esi@43
  PStringBase<unsigned short> *v39; // esi@53
  LONG (__stdcall *v40)(volatile LONG *); // ebp@53
  PStringBase<unsigned short> *v41; // ebx@53
  PStringBase<unsigned short> v42; // eax@53
  int v43; // edi@54
  PSRefBufferCharData<unsigned short> *v44; // eax@57
  char *v45; // esi@58
  PStringBase<unsigned short> *v46; // esi@63
  PStringBase<unsigned short> *v47; // ebx@63
  PSRefBufferCharData<unsigned short> *v48; // eax@63
  int v49; // edi@64
  PSRefBufferCharData<unsigned short> *v50; // eax@67
  char *v51; // esi@68
  SmartArray<PStringBase<unsigned short>,1> *v52; // esi@76
  PStringBase<unsigned short> *v53; // edi@76
  int v54; // ST10_4@76
  SmartArray<PStringBase<unsigned short>,1> *v55; // ST08_4@76
  PStringBase<unsigned short> *v56; // ST04_4@76
  StringTableMetaLanguage::Node *v57; // eax@76
  bool v58; // bl@78
  char *v59; // esi@78
  StringTableMetaLanguage::RenderErr *v60; // edi@83
  PSRefBufferCharData<char> *v61; // eax@84
  int v62; // esi@85
  PSRefBufferCharData<char> *v63; // eax@88
  int loop; // [sp+10h] [bp-2Ch]@1
  signed int idxPost; // [sp+14h] [bp-28h]@1
  signed int idxPre; // [sp+18h] [bp-24h]@1
  PStringBase<unsigned short> v68; // [sp+1Ch] [bp-20h]@2
  PStringBase<unsigned short> v69; // [sp+20h] [bp-1Ch]@19
  PStringBase<unsigned short> v70; // [sp+24h] [bp-18h]@14
  PStringBase<unsigned short> v71; // [sp+28h] [bp-14h]@36
  int idxMid; // [sp+2Ch] [bp-10h]@1
  SmartArray<PStringBase<unsigned short>,1> newvarparts; // [sp+30h] [bp-Ch]@52

  StringTableMetaLanguage::curError.pos = -1;
  dword_8F77FC = 0;
  PStringBase<char>::set(&stru_8F7800, &name);
  v7 = varnames;
  v8 = varnames->m_num == 0;
  idxPre = -1;
  idxMid = -1;
  idxPost = -1;
  loop = 0;
  if ( v8 )
    goto LABEL_92;
  do
  {
    v9 = _wcslen(L"PRE");
    PStringBase<unsigned short>::allocate_ref_buffer(&v68, v9);
    _wcscpy(v68.m_charbuffer->m_data, L"PRE");
    v10 = v68.m_charbuffer;
    v11 = loop;
    v12 = v7->m_data[loop].m_charbuffer->m_data;
    if ( *((_DWORD *)v12 - 1) == *(_DWORD *)&v68.m_charbuffer[-1].m_data[14] )
    {
      v14 = *((_DWORD *)v12 - 2);
      v15 = *(_DWORD *)&v68.m_charbuffer[-1].m_data[12];
      if ( v14 == v15 || v14 == -1 || v15 == -1 )
      {
        v16 = _wcscmp(v12, v68.m_charbuffer->m_data);
        v10 = v68.m_charbuffer;
        v13 = v16 == 0;
      }
      else
      {
        v13 = 0;
      }
    }
    else
    {
      v13 = 0;
    }
    v17 = (int)&v10[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v10[-1].m_data[8]) && v17 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
    if ( v13 )
    {
      idxPre = loop;
    }
    else
    {
      v18 = _wcslen(L"MID");
      PStringBase<unsigned short>::allocate_ref_buffer(&v70, v18);
      _wcscpy(v70.m_charbuffer->m_data, L"MID");
      v19 = v7->m_data[v11].m_charbuffer->m_data;
      if ( *((_DWORD *)v19 - 1) == *(_DWORD *)&v70.m_charbuffer[-1].m_data[14] )
      {
        v20 = *((_DWORD *)v19 - 2);
        v21 = *(_DWORD *)&v70.m_charbuffer[-1].m_data[12];
        if ( v20 == v21 || v20 == -1 || v21 == -1 )
        {
          LOBYTE(varnames) = _wcscmp(v19, v70.m_charbuffer->m_data) == 0;
          if ( (_BYTE)varnames )
            goto LABEL_93;
        }
      }
      v22 = _wcslen(L"NAME");
      PStringBase<unsigned short>::allocate_ref_buffer(&v69, v22);
      _wcscpy(v69.m_charbuffer->m_data, L"NAME");
      v23 = v69.m_charbuffer;
      v24 = v7->m_data[v11].m_charbuffer->m_data;
      if ( *((_DWORD *)v24 - 1) == *(_DWORD *)&v69.m_charbuffer[-1].m_data[14] )
      {
        v26 = *((_DWORD *)v24 - 2);
        v27 = *(_DWORD *)&v69.m_charbuffer[-1].m_data[12];
        if ( v26 == v27 || v26 == -1 || v27 == -1 )
        {
          v28 = _wcscmp(v24, v69.m_charbuffer->m_data);
          v23 = v69.m_charbuffer;
          v25 = v28 == 0;
        }
        else
        {
          v25 = 0;
        }
      }
      else
      {
        v25 = 0;
      }
      v29 = (int)&v23[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v23[-1].m_data[8]) && v29 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v29)(v29, 1);
      if ( v25 )
LABEL_93:
        v25 = 1;
      v30 = (char *)&v70.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v70.m_charbuffer[-1].m_data[8]) && v30 )
        (**(void (__thiscall ***)(char *, signed int))v30)(v30, 1);
      if ( v25 )
      {
        idxMid = loop;
      }
      else
      {
        v31 = _wcslen(L"POST");
        PStringBase<unsigned short>::allocate_ref_buffer(&v71, v31);
        _wcscpy(v71.m_charbuffer->m_data, L"POST");
        v32 = v71.m_charbuffer;
        v33 = v7->m_data[v11].m_charbuffer->m_data;
        if ( *((_DWORD *)v33 - 1) == *(_DWORD *)&v71.m_charbuffer[-1].m_data[14] )
        {
          v35 = *((_DWORD *)v33 - 2);
          v36 = *(_DWORD *)&v71.m_charbuffer[-1].m_data[12];
          if ( v35 == v36 || v35 == -1 || v36 == -1 )
          {
            v37 = _wcscmp(v33, v71.m_charbuffer->m_data);
            v32 = v71.m_charbuffer;
            v34 = v37 == 0;
          }
          else
          {
            v34 = 0;
          }
        }
        else
        {
          v34 = 0;
        }
        v38 = (int)&v32[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&v32[-1].m_data[8]) && v38 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v38)(v38, 1);
        if ( v34 )
          idxPost = loop;
      }
    }
    ++loop;
  }
  while ( loop < v7->m_num );
  if ( idxMid == -1 || idxPre == -1 && idxPost == -1 )
  {
LABEL_92:
    StringTableMetaLanguage::LoadTokenizer(textparts, varparts);
    v40 = InterlockedDecrement;
  }
  else
  {
    newvarparts.m_data = 0;
    newvarparts.m_sizeAndDeallocate = 0;
    newvarparts.m_num = 0;
    SmartArray<PStringBase<unsigned short>,1>::operator=(&newvarparts, (int)varparts);
    if ( idxPre == -1 )
    {
      v40 = InterlockedDecrement;
    }
    else
    {
      v39 = &newvarparts.m_data[idxPre];
      v40 = InterlockedDecrement;
      v41 = StringTableMetaLanguage::UnescapeString((PStringBase<unsigned short> *)&varnames, v39);
      v42.m_charbuffer = v39->m_charbuffer;
      if ( v39->m_charbuffer != v41->m_charbuffer )
      {
        v43 = (int)&v42.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&v42.m_charbuffer[-1].m_data[8]) && v43 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v43)(v43, 1);
        v44 = v41->m_charbuffer;
        v39->m_charbuffer = v41->m_charbuffer;
        InterlockedIncrement((volatile LONG *)&v44[-1].m_data[8]);
      }
      v45 = (char *)&varnames[-2].m_sizeAndDeallocate;
      if ( !InterlockedDecrement((volatile LONG *)&varnames[-2].m_num) && v45 )
        (**(void (__thiscall ***)(char *, signed int))v45)(v45, 1);
    }
    if ( idxPost != -1 )
    {
      v46 = &newvarparts.m_data[idxPost];
      v47 = StringTableMetaLanguage::UnescapeString(
              (PStringBase<unsigned short> *)&varnames,
              &newvarparts.m_data[idxPost]);
      v48 = v46->m_charbuffer;
      if ( v46->m_charbuffer != v47->m_charbuffer )
      {
        v49 = (int)&v48[-1].m_data[6];
        if ( !v40((volatile LONG *)&v48[-1].m_data[8]) && v49 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v49)(v49, 1);
        v50 = v47->m_charbuffer;
        v46->m_charbuffer = v47->m_charbuffer;
        InterlockedIncrement((volatile LONG *)&v50[-1].m_data[8]);
      }
      v51 = (char *)&varnames[-2].m_sizeAndDeallocate;
      if ( !v40((volatile LONG *)&varnames[-2].m_num) && v51 )
        (**(void (__thiscall ***)(char *, signed int))v51)(v51, 1);
    }
    StringTableMetaLanguage::LoadTokenizer(textparts, &newvarparts);
    if ( (newvarparts.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)newvarparts.m_data )
      PStringBase<unsigned short>::vector_deleting_destructor((PStringBase<char> *)newvarparts.m_data, 3u);
  }
  StringTableMetaLanguage::InitRules();
  stringmeta_parse();
  if ( !dword_8F77FC )
  {
    v52 = outsideVars;
    v53 = result;
    v54 = idxMid;
    v55 = outsideVars;
    v56 = result;
    v57 = StringTableMetaLanguage::GetRoot();
    StringTableMetaLanguage::RenderNodes(v57, v56, v55, idxPre, v54, idxPost);
    if ( !dword_8F77FC )
    {
      if ( OptionFlags & 1 )
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&varnames,
          L"keepspaces");
        v58 = SmartArray<PStringBase<unsigned short>,1>::WhatNum(v52, (PStringBase<unsigned short> *)&varnames) == -1;
        v59 = (char *)&varnames[-2].m_sizeAndDeallocate;
        if ( !v40((volatile LONG *)&varnames[-2].m_num) && v59 )
          (**(void (__thiscall ***)(char *, signed int))v59)(v59, 1);
        if ( v58 )
          StringTableMetaLanguage::TrimExcessSpaces(v53);
      }
    }
  }
  v60 = pErrReport;
  if ( pErrReport )
  {
    pErrReport->pos = StringTableMetaLanguage::curError.pos;
    v60->code = dword_8F77FC;
    v61 = v60->msg.m_charbuffer;
    if ( v61 != stru_8F7800.m_charbuffer )
    {
      v62 = (int)&v61[-2].m_data[12];
      if ( !v40((volatile LONG *)&v61[-1]) && v62 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v62)(v62, 1);
      v63 = stru_8F7800.m_charbuffer;
      v60->msg.m_charbuffer = stru_8F7800.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v63[-1]);
    }
  }
  StringTableMetaLanguage::CleanRules();
  return dword_8F77FC == 0;
}
// 8F77F8: using guessed type struct StringTableMetaLanguage::RenderErr StringTableMetaLanguage::curError;
// 8F77FC: using guessed type int dword_8F77FC;

//----- (007150A0) --------------------------------------------------------  // acclient.c:807977
int sub_7150A0()
{
  return atexit(nullsub_142);
}

//----- (007150B0) --------------------------------------------------------  // acclient.c:807983
int _E4_29()
{
  return atexit(_E5_29);
}

//----- (007150C0) --------------------------------------------------------  // acclient.c:807989
int _E7_29()
{
  Outside_CellID_29.id = Invalid_CellID_29.id + 1;
  return atexit(_E8_29);
}

//----- (007150E0) --------------------------------------------------------  // acclient.c:807996
int _E10_28()
{
  In_Limbo_CellID_28.id = Outside_CellID_29.id + 1;
  return atexit(_E11_28);
}

//----- (00715100) --------------------------------------------------------  // acclient.c:808003
int _E13_28()
{
  First_Interior_CellID_28.id = In_Limbo_CellID_28.id + 1;
  return atexit(_E14_28);
}

//----- (00715120) --------------------------------------------------------  // acclient.c:808010
int _E16_28()
{
  Last_Interior_CellID_28.id = Invalid_CellID_29.id - 1;
  return atexit(_E17_28);
}

//----- (00715140) --------------------------------------------------------  // acclient.c:808017
int _E21_31()
{
  return atexit(_E22_31);
}

//----- (00715150) --------------------------------------------------------  // acclient.c:808023
int _E40_30()
{
  return atexit(_E41_30);
}

//----- (00715160) --------------------------------------------------------  // acclient.c:808029
int _E43_33()
{
  return atexit(_E44_33);
}

//----- (00715170) --------------------------------------------------------  // acclient.c:808035
int sub_715170()
{
  stru_8F7800.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_77F240);
}

//----- (0077F240) --------------------------------------------------------  // acclient.c:918012
void __cdecl sub_77F240()
{
  char *v0; // esi@1

  v0 = &stru_8F7800.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&stru_8F7800.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

