/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : metalanguage_rules
   Object     : ENGINE\metalanguage\metalanguage_rules.obj
   Functions  : 25
   Addresses  : 0067D690 - 00715250 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0067D690) --------------------------------------------------------  // acclient.c:660408
StringTableMetaLanguage::Node *__cdecl StringTableMetaLanguage::GetRoot()
{
  return StringTableMetaLanguage::g_Root;
}

//----- (0067D6A0) --------------------------------------------------------  // acclient.c:660414
BOOL __cdecl StringTableMetaLanguage::IsInChoiceBlock()
{
  return StringTableMetaLanguage::g_curNode && StringTableMetaLanguage::g_curNode->type == 4;
}

//----- (0067D6C0) --------------------------------------------------------  // acclient.c:660420
void __thiscall StringTableMetaLanguage::Node::AddChild(StringTableMetaLanguage::Node *this, StringTableMetaLanguage::Node *child)
{
  StringTableMetaLanguage::Node *v2; // esi@1
  void *v3; // eax@1
  ListNode<StringTableMetaLanguage::Node const *> *v4; // ecx@4

  v2 = this;
  v3 = operator new(0xCu);
  if ( v3 )
  {
    *(_DWORD *)v3 = child;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
    if ( v2->children._head )
    {
      v4 = v2->children._tail;
      v4->next = (ListNode<StringTableMetaLanguage::Node const *> *)v3;
      *((_DWORD *)v3 + 2) = v4;
      v2->children._tail = (ListNode<StringTableMetaLanguage::Node const *> *)v3;
      ++v2->children._num_elements;
    }
    else
    {
      v2->children._head = (ListNode<StringTableMetaLanguage::Node const *> *)v3;
      v2->children._tail = (ListNode<StringTableMetaLanguage::Node const *> *)v3;
      ++v2->children._num_elements;
    }
  }
}

//----- (0067D710) --------------------------------------------------------  // acclient.c:660451
void __cdecl StringTableMetaLanguage::AddNode(StringTableMetaLanguage::Node *node)
{
  char *v1; // esi@5
  void *v2; // eax@5
  int v3; // ecx@8

  node->pos = StringTableMetaLanguage::GetCurrentStreamPosition() - 1;
  StringTableMetaLanguage::g_lastAddedNode = (struct Node *)node;
  if ( StringTableMetaLanguage::g_curNode )
  {
    if ( node == StringTableMetaLanguage::g_curNode )
    {
      StringTableMetaLanguage::Node::AddChild(StringTableMetaLanguage::g_Root, node);
      StringTableMetaLanguage::g_curNode = 0;
    }
    else
    {
      StringTableMetaLanguage::Node::AddChild(StringTableMetaLanguage::g_curNode, node);
    }
  }
  else
  {
    v1 = (char *)&StringTableMetaLanguage::g_Root->children;
    v2 = operator new(0xCu);
    if ( v2 )
    {
      *(_DWORD *)v2 = node;
      *((_DWORD *)v2 + 1) = 0;
      *((_DWORD *)v2 + 2) = 0;
      if ( *((_DWORD *)v1 + 1) )
      {
        v3 = *((_DWORD *)v1 + 2);
        *(_DWORD *)(v3 + 4) = v2;
        *((_DWORD *)v2 + 2) = v3;
        *((_DWORD *)v1 + 2) = v2;
        ++*((_DWORD *)v1 + 3);
      }
      else
      {
        *((_DWORD *)v1 + 1) = v2;
        *((_DWORD *)v1 + 2) = v2;
        ++*((_DWORD *)v1 + 3);
      }
    }
  }
}
// 8F7820: using guessed type struct Node *StringTableMetaLanguage::g_lastAddedNode;

//----- (0067D7A0) --------------------------------------------------------  // acclient.c:660500
void __cdecl StringTableMetaLanguage::r_Flags(PStringBase<unsigned short> *flags)
{
  PSRefBufferCharData<unsigned short> *v1; // eax@1
  struct Node *v2; // esi@1
  int v3; // edi@2
  PSRefBufferCharData<unsigned short> *v4; // eax@5

  v1 = (PSRefBufferCharData<unsigned short> *)StringTableMetaLanguage::g_lastAddedNode[8].lpVtbl;
  v2 = StringTableMetaLanguage::g_lastAddedNode + 8;
  if ( v1 != flags->m_charbuffer )
  {
    v3 = (int)&v1[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v1[-1].m_data[8]) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    v4 = flags->m_charbuffer;
    v2->lpVtbl = (struct NodeVtbl *)flags->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v4[-1].m_data[8]);
  }
}
// 8F7820: using guessed type struct Node *StringTableMetaLanguage::g_lastAddedNode;

//----- (0067D7F0) --------------------------------------------------------  // acclient.c:660525
char __cdecl StringTableMetaLanguage::CheckForErrorsInChoiceBlock(StringTableMetaLanguage::Node *n)
{
  ListNode<StringTableMetaLanguage::Node const *> *v1; // esi@1
  char v2; // al@1
  char *v4; // esi@7

  v1 = n->children._head;
  v2 = 0;
  if ( !v1 )
    return 1;
  while ( *(_DWORD *)&v1->data->flags.m_charbuffer[-1].m_data[14] != 1 )
  {
LABEL_5:
    v1 = v1->next;
    if ( !v1 )
      return 1;
  }
  if ( !v2 )
  {
    v2 = 1;
    goto LABEL_5;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&n, "multiple default choices in this block");
  StringTableMetaLanguage::SetError(v1->data->pos, recDuplicateChoices, (PStringBase<char> *)&n);
  v4 = (char *)&n[-1].children._num_elements;
  if ( !InterlockedDecrement(&n[-1].ID) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
  return 0;
}

//----- (0067D870) --------------------------------------------------------  // acclient.c:660559
void __thiscall StringTableMetaLanguage::Node::Reset(StringTableMetaLanguage::Node *this)
{
  StringTableMetaLanguage::Node *v1; // edi@1
  ListNode<StringTableMetaLanguage::Node const *> *i; // esi@1
  StringTableMetaLanguage::Node *v3; // ebx@2
  ListNode<StringTableMetaLanguage::Node const *> *v4; // ecx@5
  ListNode<StringTableMetaLanguage::Node const *> *v5; // eax@6

  v1 = this;
  this->type = 0;
  for ( i = this->children._head; i; i = i->next )
  {
    v3 = i->data;
    if ( i->data )
    {
      StringTableMetaLanguage::Node::~Node(i->data);
      operator delete(v3);
    }
  }
  while ( 1 )
  {
    v4 = v1->children._head;
    if ( !v4 )
      break;
    v5 = v4->next;
    v1->children._head = v5;
    if ( v5 )
      v5->prev = 0;
    else
      v1->children._tail = 0;
    if ( v4 )
      operator delete(v4);
    --v1->children._num_elements;
  }
}

//----- (0067D8D0) --------------------------------------------------------  // acclient.c:660596
void __cdecl StringTableMetaLanguage::r_ChoiceBlockEnd()
{
  StringTableMetaLanguage::CheckForErrorsInChoiceBlock(StringTableMetaLanguage::g_curNode);
  StringTableMetaLanguage::AddNode(StringTableMetaLanguage::g_curNode);
}

//----- (0067D8F0) --------------------------------------------------------  // acclient.c:660603
void __thiscall StringTableMetaLanguage::Node::Node(StringTableMetaLanguage::Node *this, StringTableMetaLanguage::NodeType Type)
{
  StringTableMetaLanguage::Node *v2; // esi@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1

  v2 = this;
  v3 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  this->text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v3);
  v2->type = Type;
  v2->children.vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
  v2->children._head = 0;
  v2->children._tail = 0;
  v2->children._num_elements = 0;
  v2->ID = 0;
  v2->bForceCapital = 0;
  v4 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v2->flags.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v4);
  v2->pos = 0;
}
// 7FE1E0: using guessed type int (__thiscall *List<StringTableMetaLanguage::Node const *>::vftable)(void *, char);

//----- (0067D950) --------------------------------------------------------  // acclient.c:660628
void __thiscall StringTableMetaLanguage::Node::~Node(StringTableMetaLanguage::Node *this)
{
  StringTableMetaLanguage::Node *v1; // edi@1
  int v2; // esi@1
  int v3; // esi@4

  v1 = this;
  StringTableMetaLanguage::Node::Reset(this);
  v2 = (int)&v1->flags.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v2 + 4)) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v1->children.vfptr = (List<StringTableMetaLanguage::Node const *>Vtbl *)&List<StringTableMetaLanguage::Node const *>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v1->children);
  v3 = (int)&v1->text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}
// 7FE1E0: using guessed type int (__thiscall *List<StringTableMetaLanguage::Node const *>::vftable)(void *, char);

//----- (0067D9B0) --------------------------------------------------------  // acclient.c:660651
void __cdecl StringTableMetaLanguage::InitRules()
{
  StringTableMetaLanguage::Node *v0; // eax@1
  StringTableMetaLanguage::Node *v1; // eax@2

  StringTableMetaLanguage::g_lastAddedNode = 0;
  StringTableMetaLanguage::g_curNode = 0;
  StringTableMetaLanguage::g_Root = 0;
  v0 = (StringTableMetaLanguage::Node *)operator new(0x28u);
  if ( v0 )
  {
    StringTableMetaLanguage::Node::Node(v0, ntRootNode);
    StringTableMetaLanguage::g_Root = v1;
  }
  else
  {
    StringTableMetaLanguage::g_Root = 0;
  }
}
// 8F7820: using guessed type struct Node *StringTableMetaLanguage::g_lastAddedNode;

//----- (0067D9F0) --------------------------------------------------------  // acclient.c:660673
void __cdecl StringTableMetaLanguage::CleanRules()
{
  StringTableMetaLanguage::Node *v0; // esi@1
  StringTableMetaLanguage::Node *v1; // esi@3

  v0 = StringTableMetaLanguage::g_Root;
  if ( StringTableMetaLanguage::g_Root )
  {
    StringTableMetaLanguage::Node::~Node(StringTableMetaLanguage::g_Root);
    operator delete(v0);
  }
  StringTableMetaLanguage::g_Root = 0;
  v1 = StringTableMetaLanguage::g_curNode;
  if ( StringTableMetaLanguage::g_curNode )
  {
    StringTableMetaLanguage::Node::~Node(StringTableMetaLanguage::g_curNode);
    operator delete(v1);
  }
  StringTableMetaLanguage::g_curNode = 0;
  StringTableMetaLanguage::g_lastAddedNode = 0;
}
// 8F7820: using guessed type struct Node *StringTableMetaLanguage::g_lastAddedNode;

//----- (0067DA40) --------------------------------------------------------  // acclient.c:660697
void __cdecl StringTableMetaLanguage::r_Text(PStringBase<unsigned short> *text)
{
  StringTableMetaLanguage::Node *v1; // eax@1
  StringTableMetaLanguage::Node *v2; // eax@2
  StringTableMetaLanguage::Node *v3; // esi@2
  PSRefBufferCharData<unsigned short> *v4; // eax@4
  int v5; // edi@5
  PSRefBufferCharData<unsigned short> *v6; // eax@8

  v1 = (StringTableMetaLanguage::Node *)operator new(0x28u);
  if ( v1 )
  {
    StringTableMetaLanguage::Node::Node(v1, ntText);
    v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  v4 = v3->text.m_charbuffer;
  if ( v3->text.m_charbuffer != text->m_charbuffer )
  {
    v5 = (int)&v4[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1].m_data[8]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = text->m_charbuffer;
    v3->text.m_charbuffer = text->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v6[-1].m_data[8]);
  }
  StringTableMetaLanguage::AddNode(v3);
}

//----- (0067DAB0) --------------------------------------------------------  // acclient.c:660730
void __cdecl StringTableMetaLanguage::r_Var(PStringBase<unsigned short> *var, int labelID, bool bForceCapitalize)
{
  StringTableMetaLanguage::Node *v3; // eax@1
  int v4; // eax@2
  int v5; // ebp@2
  bool v6; // cl@4
  const wchar_t **v7; // edi@4
  wchar_t *v8; // eax@4
  const wchar_t *v9; // esi@4
  const wchar_t *v10; // ebx@5
  PSRefBufferCharData<unsigned short> *v11; // eax@7
  unsigned int v12; // edi@7
  int v13; // ecx@7
  int v14; // esi@10
  PStringBase<unsigned short> v15; // ST08_4@15
  int v16; // esi@15
  const wchar_t *v17; // ST00_4@15
  wchar_t *v18; // eax@15
  int v19; // eax@16
  int v20; // esi@16
  unsigned int v21; // eax@21
  PSRefBufferCharData<unsigned short> *v22; // eax@21
  int v23; // ecx@21
  LONG (__stdcall *v24)(volatile LONG *); // edi@23
  char *v25; // esi@23
  void *v26; // esi@26
  int v27; // esi@27
  int v28; // esi@30
  PSRefBufferCharData<unsigned short> *v29; // eax@34
  int v30; // ecx@34
  char *v31; // esi@36
  __int16 v32; // ax@43
  int v33; // eax@46
  PStringBase<unsigned short> *v34; // esi@46
  int v35; // eax@49
  PStringBase<unsigned short> v36; // eax@51
  int v37; // esi@52
  const wchar_t *v38; // eax@55
  const wchar_t *v39; // ST00_4@56
  __int32 v40; // eax@56
  PStringBase<unsigned short> rhs; // [sp+10h] [bp-10h]@34
  PStringBase<unsigned short> result; // [sp+14h] [bp-Ch]@21
  PStringBase<unsigned short> v43; // [sp+18h] [bp-8h]@34
  wchar_t *pend; // [sp+1Ch] [bp-4h]@15

  v3 = (StringTableMetaLanguage::Node *)operator new(0x28u);
  if ( v3 )
  {
    StringTableMetaLanguage::Node::Node(v3, ntVar);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v6 = bForceCapitalize;
  v7 = (const wchar_t **)var;
  *(_DWORD *)(v5 + 24) = labelID;
  *(_BYTE *)(v5 + 28) = v6;
  v8 = PSUtils::wcschr_skipescapes(*v7, 0x5Bu, 0x5Cu);
  v9 = v8;
  *(_DWORD *)&bForceCapitalize = v8;
  if ( !v8 )
  {
    v36.m_charbuffer = *(PSRefBufferCharData<unsigned short> **)v5;
    if ( *(const wchar_t **)v5 != *v7 )
    {
      v37 = (int)&v36.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v36.m_charbuffer[-1].m_data[8]) && v37 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v37)(v37, 1);
      v38 = *v7;
      *(_DWORD *)v5 = *v7;
      InterlockedIncrement((volatile LONG *)v38 - 4);
    }
    v39 = *v7;
    *(_DWORD *)&bForceCapitalize = 0;
    v40 = _wcstol(v39, (wchar_t **)&bForceCapitalize, 10);
    if ( bForceCapitalize && !*(_WORD *)bForceCapitalize && StringTableMetaLanguage::IsNumberSingular(v40) )
    {
      var = (PStringBase<unsigned short> *)49;
      PStringBase<unsigned short>::append_n_chars(
        (PStringBase<unsigned short> *)(v5 + 32),
        (const unsigned __int16 *)&var,
        1u);
    }
    if ( *((_DWORD *)*v7 - 1) == 1 )
    {
      var = (PStringBase<unsigned short> *)98;
      PStringBase<unsigned short>::append_n_chars(
        (PStringBase<unsigned short> *)(v5 + 32),
        (const unsigned __int16 *)&var,
        1u);
    }
    goto LABEL_62;
  }
  v10 = *v7;
  if ( *v7 != v8 )
  {
    do
    {
      labelID = *v10;
      if ( (_WORD)labelID )
      {
        v11 = *(PSRefBufferCharData<unsigned short> **)v5;
        v12 = *(_DWORD *)(*(_DWORD *)v5 - 4);
        v13 = v12 + 1;
        if ( *(_DWORD *)(*(_DWORD *)v5 - 16) != 1 || (unsigned int)v13 > *(_DWORD *)&v11[-1].m_data[10] )
        {
          v14 = (int)&v11[-1].m_data[6];
          PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)v5, v12);
          _wcscpy(*(wchar_t **)v5, (const wchar_t *)(v14 + 20));
          if ( !InterlockedDecrement((volatile LONG *)(v14 + 4)) && v14 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
        }
        else
        {
          *(_DWORD *)&v11[-1].m_data[14] = v13;
          *(_DWORD *)(*(_DWORD *)v5 - 8) = -1;
        }
        _wcsncpy((wchar_t *)(*(_DWORD *)v5 + 2 * v12 - 2), (const wchar_t *)&labelID, 1u);
        v7 = (const wchar_t **)var;
        v9 = (const wchar_t *)bForceCapitalize;
        *(_WORD *)(*(_DWORD *)v5 + 2 * *(_DWORD *)(*(_DWORD *)v5 - 4) - 2) = 0;
      }
      ++v10;
    }
    while ( v10 != v9 );
  }
  v15.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::whitespace_string;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::whitespace_string - 4);
  PStringBase<unsigned short>::trim((PStringBase<unsigned short> *)v5, 0, 1, v15);
  v16 = (int)(v9 + 1);
  v17 = *v7;
  *(_DWORD *)&bForceCapitalize = v16;
  v18 = PSUtils::wcschr_skipescapes(v17, 0x5Du, 0x5Cu);
  pend = v18;
  if ( !v18 )
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&bForceCapitalize,
      "variable-substitution string is missing ']'");
    v19 = StringTableMetaLanguage::GetCurrentStreamPosition();
    StringTableMetaLanguage::SetError(v19, recSyntaxError, (PStringBase<char> *)&bForceCapitalize);
    v20 = bForceCapitalize - 20;
    if ( !InterlockedDecrement((volatile LONG *)(bForceCapitalize - 20 + 4)) )
    {
      if ( v20 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
    }
    return;
  }
  if ( (wchar_t *)v16 != v18 )
  {
    do
    {
      LOWORD(v18) = *(_WORD *)v16;
      if ( *(_WORD *)v16 == 77 )
      {
        labelID = (int)PStringBase<unsigned short>::s_NullBuffer;
        InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
        StringTableMetaLanguage::GetMaleMetaLetters((PStringBase<unsigned short> *)&labelID);
        v21 = _wcslen(L"M");
        PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)&var, v21);
        _wcscpy((wchar_t *)var, L"M");
        v22 = PStringBase<unsigned short>::operator+(
                (PStringBase<unsigned short> *)&labelID,
                &result,
                (PStringBase<unsigned short> *)&var)->m_charbuffer;
        v23 = *(_DWORD *)&v22[-1].m_data[14];
        if ( v23 != 1 )
          PStringBase<unsigned short>::append_n_chars((PStringBase<unsigned short> *)(v5 + 32), v22->m_data, v23 - 1);
        v24 = InterlockedDecrement;
        v25 = (char *)&result.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v25 )
          (**(void (__thiscall ***)(char *, signed int))v25)(v25, 1);
        v26 = var;
      }
      else
      {
        if ( (_WORD)v18 != 70 )
        {
          if ( (_WORD)v18 != 32 )
          {
            labelID = (int)v18;
            PStringBase<unsigned short>::append_n_chars(
              (PStringBase<unsigned short> *)(v5 + 32),
              (const unsigned __int16 *)&labelID,
              1u);
          }
          goto LABEL_42;
        }
        labelID = (int)PStringBase<unsigned short>::s_NullBuffer;
        InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
        StringTableMetaLanguage::GetFemaleMetaLetters((PStringBase<unsigned short> *)&labelID);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&rhs, L"F");
        v29 = PStringBase<unsigned short>::operator+((PStringBase<unsigned short> *)&labelID, &v43, &rhs)->m_charbuffer;
        v30 = *(_DWORD *)&v29[-1].m_data[14];
        if ( v30 != 1 )
          PStringBase<unsigned short>::append_n_chars((PStringBase<unsigned short> *)(v5 + 32), v29->m_data, v30 - 1);
        v24 = InterlockedDecrement;
        v31 = (char *)&v43.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&v43.m_charbuffer[-1].m_data[8]) && v31 )
          (**(void (__thiscall ***)(char *, signed int))v31)(v31, 1);
        v26 = rhs.m_charbuffer;
      }
      v27 = (int)((char *)v26 - 20);
      if ( !v24((volatile LONG *)(v27 + 4)) && v27 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
      v28 = labelID - 20;
      if ( !v24((volatile LONG *)(labelID - 20 + 4)) && v28 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v28)(v28, 1);
LABEL_42:
      HIWORD(v18) = HIWORD(pend);
      v16 = bForceCapitalize + 2;
      *(_DWORD *)&bForceCapitalize = bForceCapitalize + 2;
    }
    while ( (wchar_t *)bForceCapitalize != pend );
  }
  v32 = *(_WORD *)(v16 + 2);
  *(_DWORD *)&bForceCapitalize = v16 + 2;
  if ( !v32 )
  {
LABEL_62:
    StringTableMetaLanguage::AddNode((StringTableMetaLanguage::Node *)v5);
    return;
  }
  do
  {
    if ( v32 != 32 && v32 != 9 )
    {
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&var,
        "there is text after the ']' in a variable-substitution string");
      v33 = StringTableMetaLanguage::GetCurrentStreamPosition();
      StringTableMetaLanguage::SetError(v33, recSyntaxError, (PStringBase<char> *)&var);
      v34 = var - 5;
      if ( !InterlockedDecrement((volatile LONG *)&var[-4]) )
      {
        if ( v34 )
          (*(void (__thiscall **)(PStringBase<unsigned short> *, signed int))&v34->m_charbuffer->m_data[0])(v34, 1);
      }
    }
    v35 = bForceCapitalize + 2;
    *(_DWORD *)&bForceCapitalize = v35;
    v32 = *(_WORD *)v35;
  }
  while ( v32 );
  StringTableMetaLanguage::AddNode((StringTableMetaLanguage::Node *)v5);
}

//----- (0067DF30) --------------------------------------------------------  // acclient.c:660981
void __cdecl StringTableMetaLanguage::r_ChoiceBlockBegin(int labelID)
{
  StringTableMetaLanguage::Node *v1; // eax@1
  int v2; // eax@2

  v1 = (StringTableMetaLanguage::Node *)operator new(0x28u);
  if ( v1 )
  {
    StringTableMetaLanguage::Node::Node(v1, ntChoiceBlock);
    StringTableMetaLanguage::g_curNode = (StringTableMetaLanguage::Node *)v2;
    *(_DWORD *)(v2 + 24) = labelID;
  }
  else
  {
    StringTableMetaLanguage::g_curNode = 0;
    v18 = labelID;
  }
}

//----- (0067DF70) --------------------------------------------------------  // acclient.c:661001
void __cdecl StringTableMetaLanguage::r_OutsideInfoBlock(PStringBase<unsigned short> *text)
{
  StringTableMetaLanguage::Node *v1; // eax@1
  StringTableMetaLanguage::Node *v2; // eax@2
  StringTableMetaLanguage::Node *v3; // esi@2
  PSRefBufferCharData<unsigned short> *v4; // eax@4
  int v5; // edi@5
  PSRefBufferCharData<unsigned short> *v6; // eax@8

  v1 = (StringTableMetaLanguage::Node *)operator new(0x28u);
  if ( v1 )
  {
    StringTableMetaLanguage::Node::Node(v1, ntOutsideVar);
    v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  v4 = v3->text.m_charbuffer;
  if ( v3->text.m_charbuffer != text->m_charbuffer )
  {
    v5 = (int)&v4[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1].m_data[8]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = text->m_charbuffer;
    v3->text.m_charbuffer = text->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v6[-1].m_data[8]);
  }
  StringTableMetaLanguage::AddNode(v3);
}

//----- (00715190) --------------------------------------------------------  // acclient.c:808043
int sub_715190()
{
  return atexit(nullsub_160);
}

//----- (007151A0) --------------------------------------------------------  // acclient.c:808049
int _E4_30()
{
  return atexit(_E5_30);
}

//----- (007151B0) --------------------------------------------------------  // acclient.c:808055
int _E7_30()
{
  Outside_CellID_30.id = Invalid_CellID_30.id + 1;
  return atexit(_E8_30);
}

//----- (007151D0) --------------------------------------------------------  // acclient.c:808062
int _E10_29()
{
  In_Limbo_CellID_29.id = Outside_CellID_30.id + 1;
  return atexit(_E11_29);
}

//----- (007151F0) --------------------------------------------------------  // acclient.c:808069
int _E13_29()
{
  First_Interior_CellID_29.id = In_Limbo_CellID_29.id + 1;
  return atexit(_E14_29);
}

//----- (00715210) --------------------------------------------------------  // acclient.c:808076
int _E16_29()
{
  Last_Interior_CellID_29.id = Invalid_CellID_30.id - 1;
  return atexit(_E17_29);
}

//----- (00715230) --------------------------------------------------------  // acclient.c:808083
int _E21_32()
{
  return atexit(_E22_32);
}

//----- (00715240) --------------------------------------------------------  // acclient.c:808089
int _E40_31()
{
  return atexit(_E41_31);
}

//----- (00715250) --------------------------------------------------------  // acclient.c:808095
int _E43_34()
{
  return atexit(_E44_34);
}

