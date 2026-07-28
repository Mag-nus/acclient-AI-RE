/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PFileParser
   Object     : ENGINE\pparser\PFileParser.obj
   Functions  : 19
   Addresses  : 006B9C30 - 00791B10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B9C30) --------------------------------------------------------  // acclient.c:721843
char __thiscall PFileParser::FormatSubNodes(PFileParser *this, PFileNode *in, OutputStream *out)
{
  PFileParser *v3; // esi@1
  PFileNode *i; // eax@2
  PFileNodeIter iter; // [sp+4h] [bp-Ch]@2

  v3 = this;
  if ( in )
  {
    this->first_subnode = 1;
    PFileNodeIter::PFileNodeIter(&iter, in);
    for ( i = PFileNodeIter::Curr(&iter); i; i = (PFileNode *)PFileNodeIter::Next(&iter) )
    {
      if ( !v3->indentation )
        v3->want_blank = 1;
      PFileParser::FormatNode(v3, (char)out, i, out);
      if ( v3->first_subnode )
        v3->first_subnode = 0;
    }
    PFileNodeIter::~PFileNodeIter(&iter);
  }
  return 1;
}

//----- (006B9CA0) --------------------------------------------------------  // acclient.c:721868
OutputStream *__thiscall OutputStream::vector_deleting_destructor(OutputStream *this, unsigned int a2)
{
  OutputStream *v2; // esi@1

  v2 = this;
  this->vfptr = (OutputStreamVtbl *)OutputStream::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 80698C: using guessed type int (__thiscall *OutputStream::vftable[2])(void *, char);

//----- (006B9CC0) --------------------------------------------------------  // acclient.c:721881
char __stdcall PFileParser::IsFileBinary(PStringBase<char> *i_filename)
{
  char v2; // bl@2
  FILE *v3; // eax@2
  FILE *v4; // esi@2
  int v5; // edi@3
  char result; // al@7

  if ( *(_DWORD *)&i_filename->m_charbuffer[-1].m_data[12] == 1 )
  {
    result = 0;
  }
  else
  {
    v2 = 0;
    v3 = _fopen(i_filename->m_charbuffer->m_data, "rb");
    v4 = v3;
    if ( v3 )
    {
      v5 = __getw(v3);
      if ( !_ferror(v4) && v5 == -1431655766 )
        v2 = 1;
      _fclose(v4);
    }
    result = v2;
  }
  return result;
}

//----- (006B9D20) --------------------------------------------------------  // acclient.c:721911
unsigned int __userpurge PFileParser::CheckWrapTree@<eax>(PFileParser *this@<ecx>, int a2@<edi>, PFileNode *node, unsigned int max_chars, unsigned int max_depth)
{
  PFileParser *v5; // ebp@1
  unsigned int v7; // esi@3
  int v8; // eax@5
  char *v9; // edi@10
  char *v10; // esi@14
  PStringBase<char> strName; // [sp+4h] [bp-10h]@3
  PFileNodeIter iter; // [sp+8h] [bp-Ch]@5

  v5 = this;
  if ( !max_depth )
    return max_chars + 1;
  strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PFileNode::GetNameAsPString(node, a2, &strName);
  v7 = *(_DWORD *)&strName.m_charbuffer[-1].m_data[12] - 1;
  if ( !PFileNode::GetNumSubNodes(node) )
    goto LABEL_10;
  v7 += 6;
  if ( v7 > max_chars )
    goto LABEL_10;
  PFileNodeIter::PFileNodeIter(&iter, node);
  v8 = (int)PFileNodeIter::Curr(&iter);
  if ( !v8 )
  {
LABEL_9:
    PFileNodeIter::~PFileNodeIter(&iter);
LABEL_10:
    v9 = &strName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strName.m_charbuffer[-1]) )
    {
      if ( v9 )
        (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
    }
    return v7;
  }
  while ( *(_DWORD *)(*(_DWORD *)(v8 + 16) - 4) == 1 )
  {
    v7 += PFileParser::CheckWrapTree(v5, (PFileNode *)v8, max_chars - v7, max_depth - 1);
    if ( v7 <= max_chars )
    {
      v8 = PFileNodeIter::Next(&iter);
      if ( v8 )
        continue;
    }
    goto LABEL_9;
  }
  PFileNodeIter::~PFileNodeIter(&iter);
  v10 = &strName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strName.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  return max_chars + 1;
}

//----- (006B9E40) --------------------------------------------------------  // acclient.c:721967
char __stdcall PFileParser::LoadBinary(PFileNode *i_node, PStringBase<char> *i_filename)
{
  char *v3; // eax@1
  PStringBase<char> v4; // edi@1
  int v5; // edi@1
  char v6; // bl@4
  TransientArchive archive; // [sp+10h] [bp-4Ch]@1
  MMapUtil mmap; // [sp+34h] [bp-28h]@1

  MMapUtil::MMapUtil(&mmap);
  v3 = MMapUtil::MMap(&mmap, i_filename->m_charbuffer->m_data, 1, 1, 0, 0, 0, 0);
  TransientArchive::TransientArchive(&archive, 0, v3, mmap.dataSize);
  Serializer::SerializeMagicNumber(-1431655766, (Archive *)&archive.vfptr);
  i_node->vfptr[5].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)i_node, (unsigned int)&archive);
  PFileNode::InitFileInfo(i_node, i_filename);
  v4.m_charbuffer = i_filename->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&i_filename->m_charbuffer[-1]);
  InterlockedIncrement((volatile LONG *)&v4.m_charbuffer[-1]);
  PFileNode::SetNameAsPString(i_node, v4);
  v5 = (int)&v4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v6 = ~(unsigned __int8)(archive.m_flags >> 2) & 1;
  Archive::~Archive((Archive *)&archive.vfptr);
  MMapUtil::~MMapUtil(&mmap);
  return v6;
}

//----- (006B9F10) --------------------------------------------------------  // acclient.c:721996
void __thiscall PFileParser::MaybeIndent(PFileParser *this, OutputStream *out)
{
  PFileParser *v2; // ebx@1
  unsigned int v3; // edi@2
  PSRefBufferCharData<char> *v4; // ecx@3
  int v5; // eax@5

  v2 = this;
  if ( this->separate_subnodes )
  {
    v3 = 0;
    if ( this->indentation )
    {
      v4 = indent_string.m_charbuffer;
      while ( out->saving_to_string )
      {
        v5 = *(_DWORD *)&v4[-1].m_data[12];
        if ( v5 != 1 )
        {
          PStringBase<char>::append_n_chars(out->m_pstring_stream, v4->m_data, v5 - 1);
LABEL_8:
          v4 = indent_string.m_charbuffer;
        }
        ++v3;
        if ( v3 >= v2->indentation )
          return;
      }
      _fputs(v4->m_data, out->file_ptr);
      goto LABEL_8;
    }
  }
}

//----- (006B9F80) --------------------------------------------------------  // acclient.c:722030
char __stdcall PFileParser::PutQuotedString(PStringBase<char> *in, OutputStream *out)
{
  PStringBase<char> *v3; // eax@1
  char v4; // al@1
  OutputStream *v5; // ebx@1
  unsigned int v6; // esi@3
  unsigned int v7; // eax@4
  PStringBase<char> *v8; // esi@9
  PStringBase<char> v9; // eax@9
  unsigned int v10; // ebp@9
  int v11; // ecx@9
  int v12; // edi@13
  PStringBase<char> *v13; // esi@21
  PStringBase<char> v14; // eax@21
  unsigned int v15; // ebp@21
  int v16; // ecx@21
  int v17; // edi@24
  char v18; // al@29
  PStringBase<char> *v19; // esi@30
  PStringBase<char> v20; // eax@31
  unsigned int v21; // ebp@31
  int v22; // ecx@31
  int v23; // edi@34
  unsigned int v24; // esi@39
  unsigned int v25; // eax@40
  PStringBase<char> *v26; // esi@45
  PStringBase<char> v27; // eax@45
  unsigned int v28; // ebp@45
  int v29; // ecx@45
  int v30; // edi@48
  PStringBaseIter_Const<char> in_iter; // [sp+14h] [bp-10h]@1

  v3 = in;
  LOBYTE(in) = *(_DWORD *)&in->m_charbuffer[-1].m_data[12] == 1;
  in_iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
  in_iter.pstring_ptr = v3;
  in_iter.curr = 0;
  in_iter.mark = 0;
  v4 = PStringBaseIter_Const<char>::IndexToChar((PStringBaseIter<char> *)&in_iter, 0);
  v5 = out;
  if ( v4 )
  {
    while ( 2 )
    {
      switch ( in_iter.vfptr->IndexToChar((PStringBaseIter_Common<char> *)&in_iter, in_iter.curr) )
      {
        default:
          v6 = in_iter.curr + 1;
          if ( v6 <= in_iter.vfptr->GetStrLen(&in_iter) )
            v7 = v6;
          else
            v7 = in_iter.vfptr->GetStrLen(&in_iter);
          in_iter.curr = v7;
          if ( !in_iter.vfptr->IndexToChar((PStringBaseIter_Common<char> *)&in_iter, v7) )
            goto quotes_done;
          continue;
        case 9:
        case 32:
        case 35:
        case 40:
        case 41:
        case 44:
        case 91:
        case 93:
        case 123:
        case 125:
          LOBYTE(in) = 1;
          break;
      }
      break;
    }
  }
  else
  {
quotes_done:
    if ( !(_BYTE)in )
      goto LABEL_18;
  }
  if ( v5->saving_to_string )
  {
    v8 = v5->m_pstring_stream;
    v9.m_charbuffer = v8->m_charbuffer;
    LOBYTE(out) = 34;
    v10 = *(_DWORD *)&v9.m_charbuffer[-1].m_data[12];
    v11 = v10 + 1;
    if ( *(_DWORD *)&v9.m_charbuffer[-1].m_data[0] != 1 || (unsigned int)v11 > *(_DWORD *)&v9.m_charbuffer[-1].m_data[4] )
    {
      v12 = (int)&v9.m_charbuffer[-2].m_data[12];
      PStringBase<char>::allocate_ref_buffer(v8, v10);
      strcpy(v8->m_charbuffer->m_data, (const char *)(v12 + 20));
      if ( !InterlockedDecrement((volatile LONG *)(v12 + 4)) && v12 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
    }
    else
    {
      *(_DWORD *)&v9.m_charbuffer[-1].m_data[12] = v11;
      *(_DWORD *)&v8->m_charbuffer[-1].m_data[8] = -1;
    }
    _strncpy((char *)v8->m_charbuffer + v10 - 1, (const char *)&out, 1u);
    v8->m_charbuffer->m_data[*(_DWORD *)&v8->m_charbuffer[-1].m_data[12] - 1] = 0;
  }
  else
  {
    _putc(34, v5->file_ptr);
  }
LABEL_18:
  in_iter.curr = 0;
  if ( in_iter.vfptr->IndexToChar((PStringBaseIter_Common<char> *)&in_iter, 0) )
  {
    do
    {
      switch ( in_iter.vfptr->IndexToChar((PStringBaseIter_Common<char> *)&in_iter, in_iter.curr) )
      {
        case 10:
        case 13:
        case 34:
        case 92:
          if ( v5->saving_to_string )
          {
            v13 = v5->m_pstring_stream;
            v14.m_charbuffer = v13->m_charbuffer;
            LOBYTE(out) = 92;
            v15 = *(_DWORD *)&v14.m_charbuffer[-1].m_data[12];
            v16 = v15 + 1;
            if ( *(_DWORD *)&v14.m_charbuffer[-1].m_data[0] != 1
              || (unsigned int)v16 > *(_DWORD *)&v14.m_charbuffer[-1].m_data[4] )
            {
              v17 = (int)&v14.m_charbuffer[-2].m_data[12];
              PStringBase<char>::allocate_ref_buffer(v13, v15);
              strcpy(v13->m_charbuffer->m_data, (const char *)(v17 + 20));
              if ( !InterlockedDecrement((volatile LONG *)(v17 + 4)) && v17 )
                (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
            }
            else
            {
              *(_DWORD *)&v14.m_charbuffer[-1].m_data[12] = v16;
              *(_DWORD *)&v13->m_charbuffer[-1].m_data[8] = -1;
            }
            _strncpy((char *)v13->m_charbuffer + v15 - 1, (const char *)&out, 1u);
            v13->m_charbuffer->m_data[*(_DWORD *)&v13->m_charbuffer[-1].m_data[12] - 1] = 0;
          }
          else
          {
            _putc(92, v5->file_ptr);
          }
          break;
        default:
          break;
      }
      v18 = in_iter.vfptr->IndexToChar((PStringBaseIter_Common<char> *)&in_iter, in_iter.curr);
      if ( v5->saving_to_string )
      {
        v19 = v5->m_pstring_stream;
        LOBYTE(out) = v18;
        if ( v18 )
        {
          v20.m_charbuffer = v19->m_charbuffer;
          v21 = *(_DWORD *)&v19->m_charbuffer[-1].m_data[12];
          v22 = v21 + 1;
          if ( *(_DWORD *)&v19->m_charbuffer[-1].m_data[0] != 1
            || (unsigned int)v22 > *(_DWORD *)&v20.m_charbuffer[-1].m_data[4] )
          {
            v23 = (int)&v20.m_charbuffer[-2].m_data[12];
            PStringBase<char>::allocate_ref_buffer(v19, v21);
            strcpy(v19->m_charbuffer->m_data, (const char *)(v23 + 20));
            if ( !InterlockedDecrement((volatile LONG *)(v23 + 4)) && v23 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
          }
          else
          {
            *(_DWORD *)&v20.m_charbuffer[-1].m_data[12] = v22;
            *(_DWORD *)&v19->m_charbuffer[-1].m_data[8] = -1;
          }
          _strncpy((char *)v19->m_charbuffer + v21 - 1, (const char *)&out, 1u);
          v19->m_charbuffer->m_data[*(_DWORD *)&v19->m_charbuffer[-1].m_data[12] - 1] = 0;
        }
      }
      else
      {
        _putc(v18, v5->file_ptr);
      }
      v24 = in_iter.curr + 1;
      if ( v24 <= in_iter.vfptr->GetStrLen(&in_iter) )
        v25 = v24;
      else
        v25 = in_iter.vfptr->GetStrLen(&in_iter);
      in_iter.curr = v25;
    }
    while ( in_iter.vfptr->IndexToChar((PStringBaseIter_Common<char> *)&in_iter, v25) );
  }
  if ( !(_BYTE)in )
    return 1;
  if ( !v5->saving_to_string )
  {
    _putc(34, v5->file_ptr);
    return 1;
  }
  v26 = v5->m_pstring_stream;
  v27.m_charbuffer = v26->m_charbuffer;
  LOBYTE(in) = 34;
  v28 = *(_DWORD *)&v27.m_charbuffer[-1].m_data[12];
  v29 = v28 + 1;
  if ( *(_DWORD *)&v27.m_charbuffer[-1].m_data[0] != 1 || (unsigned int)v29 > *(_DWORD *)&v27.m_charbuffer[-1].m_data[4] )
  {
    v30 = (int)&v27.m_charbuffer[-2].m_data[12];
    PStringBase<char>::allocate_ref_buffer(v26, v28);
    strcpy(v26->m_charbuffer->m_data, (const char *)(v30 + 20));
    if ( !InterlockedDecrement((volatile LONG *)(v30 + 4)) )
    {
      if ( v30 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v30)(v30, 1);
    }
  }
  else
  {
    *(_DWORD *)&v27.m_charbuffer[-1].m_data[12] = v29;
    *(_DWORD *)&v26->m_charbuffer[-1].m_data[8] = -1;
  }
  _strncpy((char *)v26->m_charbuffer + v28 - 1, (const char *)&in, 1u);
  v26->m_charbuffer->m_data[*(_DWORD *)&v26->m_charbuffer[-1].m_data[12] - 1] = 0;
  return 1;
}
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (006BA450) --------------------------------------------------------  // acclient.c:722255
void __stdcall PFileParser::NewLine(OutputStream *out)
{
  PStringBase<char> *v2; // ecx@2

  if ( out->saving_to_string )
  {
    v2 = out->m_pstring_stream;
    LOBYTE(out) = 10;
    PStringBase<char>::append_n_chars(v2, (const char *)&out, 1u);
  }
  else
  {
    _putc(10, out->file_ptr);
  }
}

//----- (006BA490) --------------------------------------------------------  // acclient.c:722272
void __thiscall PFileParser::InsertSeparator(PFileParser *this, OutputStream *out)
{
  bool v2; // zf@1
  bool v3; // cl@1
  PStringBase<char> *v4; // ecx@3
  PStringBase<char> *v5; // ecx@6

  v2 = this->separate_subnodes == 0;
  v3 = out->saving_to_string;
  if ( v2 )
  {
    if ( v3 )
    {
      v5 = out->m_pstring_stream;
      LOBYTE(out) = 32;
      PStringBase<char>::append_n_chars(v5, (const char *)&out, 1u);
    }
    else
    {
      _putc(32, out->file_ptr);
    }
  }
  else if ( v3 )
  {
    v4 = out->m_pstring_stream;
    LOBYTE(out) = 10;
    PStringBase<char>::append_n_chars(v4, (const char *)&out, 1u);
  }
  else
  {
    _putc(10, out->file_ptr);
  }
}

//----- (006BA500) --------------------------------------------------------  // acclient.c:722307
char __thiscall PFileParser::LoadFromFile(PFileParser *this, PFileNode *node, PStringBase<char> *filename, bool lock)
{
  PFileParser *v4; // esi@1
  char result; // al@2
  _iobuf **v6; // eax@3

  v4 = this;
  if ( PFileParser::IsFileBinary(filename) )
  {
    result = PFileParser::LoadBinary(node, filename);
  }
  else
  {
    v6 = 0;
    if ( lock )
      v6 = &v4->locked_file;
    result = NewParser::ParseFile(v4->new_parser, node, filename, v6, v4->num_retries, v4->retry_delay);
  }
  return result;
}

//----- (006BA550) --------------------------------------------------------  // acclient.c:722329
void __userpurge PFileParser::InsertComments(PFileParser *this@<ecx>, unsigned int a2@<edi>, PFileNode *node, OutputStream *out, char str)
{
  PFileParser *v5; // ebp@1
  PStringBase<char> *v6; // edi@2
  OutputStream *v7; // esi@3
  PStringBase<char> *v8; // ecx@6
  PStringBase<char> *v9; // ecx@11
  char v10; // bl@14
  PStringBase<char> *v11; // ecx@15
  unsigned int v12; // edi@19
  unsigned int v13; // eax@20
  PStringBase<char> *v14; // ecx@25
  unsigned int v15; // [sp-8h] [bp-24h]@2
  PFileParser *v16; // [sp+8h] [bp-14h]@1
  PStringBaseIter_Const<char> iter; // [sp+Ch] [bp-10h]@8

  v5 = this;
  v16 = this;
  if ( node )
  {
    v15 = a2;
    v6 = &node->comment_string;
    if ( *(_DWORD *)&node->comment_string.m_charbuffer[-1].m_data[12] != 1 )
    {
      v7 = out;
      if ( !this->first_subnode )
        PFileParser::NewLine(out);
      PFileParser::MaybeIndent(v5, v7);
      if ( v7->saving_to_string )
      {
        v8 = v7->m_pstring_stream;
        LOBYTE(node) = 35;
        PStringBase<char>::append_n_chars(v8, (const char *)&node, 1u);
      }
      else
      {
        _putc(35, v7->file_ptr);
      }
      iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
      iter.pstring_ptr = v6;
      iter.curr = 0;
      iter.mark = 0;
      LOBYTE(node) = 0;
      if ( !PStringBaseIter_Const<char>::IndexToChar((PStringBaseIter<char> *)&iter, 0) )
        goto LABEL_29;
      do
      {
        if ( (_BYTE)node )
        {
          PFileParser::MaybeIndent(v16, v7);
          if ( v7->saving_to_string )
          {
            v9 = v7->m_pstring_stream;
            LOBYTE(node) = 35;
            PStringBase<char>::append_n_chars(v9, (const char *)&node, 1u);
          }
          else
          {
            _putc(35, v7->file_ptr);
          }
          LOBYTE(node) = 0;
        }
        v10 = ((int (__thiscall *)(PStringBaseIter_Const<char> *, unsigned int, unsigned int))iter.vfptr->IndexToChar)(
                &iter,
                iter.curr,
                v15);
        if ( v7->saving_to_string )
        {
          v11 = v7->m_pstring_stream;
          str = v10;
          PStringBase<char>::append_n_chars(v11, &str, 1u);
        }
        else
        {
          _putc(v10, v7->file_ptr);
        }
        if ( v10 == 10 )
          LOBYTE(out) = 1;
        v12 = iter.mark + 1;
        if ( v12 <= (*(int (__thiscall **)(unsigned int *))iter.curr)(&iter.curr) )
          v13 = v12;
        else
          v13 = (*(int (__thiscall **)(unsigned int *))iter.curr)(&iter.curr);
        v15 = v13;
        iter.mark = v13;
      }
      while ( (unsigned __int8)(*(int (__thiscall **)(unsigned int *))(iter.curr + 8))(&iter.curr) );
      if ( !(_BYTE)node )
      {
LABEL_29:
        if ( v7->saving_to_string )
        {
          v14 = v7->m_pstring_stream;
          LOBYTE(node) = 10;
          PStringBase<char>::append_n_chars(v14, (const char *)&node, 1u);
        }
        else
        {
          _putc(10, v7->file_ptr);
        }
      }
    }
  }
}
// 6BA550: could not find valid save-restore pair for edi
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (006BA6F0) --------------------------------------------------------  // acclient.c:722437
char __userpurge PFileParser::FormatNode@<al>(PFileParser *this@<ecx>, char a2@<dil>, PFileNode *node, OutputStream *out)
{
  PFileNode *v4; // ebp@1
  PFileParser *v5; // esi@1
  bool v6; // bl@4
  unsigned int v7; // edi@6
  PStringBase<char> *v8; // ecx@13
  PStringBase<char> *v9; // ecx@16
  bool v10; // al@18
  char *v11; // esi@19
  char v13; // [sp-8h] [bp-14h]@2
  PStringBase<char> strName; // [sp+8h] [bp-4h]@11

  v4 = node;
  v5 = this;
  if ( node )
  {
    v13 = a2;
    v6 = this->separate_subnodes && PFileParser::CheckWrapTree(this, a2, node, 0x50u, 3u) > 0x50;
    v7 = (unsigned int)out;
    if ( v5->want_blank || !v5->first_subnode && v6 )
    {
      v5->want_blank = 0;
      if ( *(_DWORD *)&v4->comment_string.m_charbuffer[-1].m_data[12] == 1 )
        PFileParser::NewLine((OutputStream *)v7);
    }
    PFileParser::InsertComments(v5, v7, v4, (OutputStream *)v7, v13);
    PFileParser::MaybeIndent(v5, (OutputStream *)v7);
    strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PFileNode::GetNameAsPString(v4, v7, &strName);
    PFileParser::PutQuotedString(&strName, (OutputStream *)v7);
    if ( PFileNode::GetNumSubNodes(v4) )
    {
      LOBYTE(out) = v5->separate_subnodes;
      v5->separate_subnodes = v6;
      PFileParser::InsertSeparator(v5, (OutputStream *)v7);
      PFileParser::MaybeIndent(v5, (OutputStream *)v7);
      if ( *(_BYTE *)(v7 + 4) )
      {
        v8 = *(PStringBase<char> **)(v7 + 12);
        LOBYTE(node) = 91;
        PStringBase<char>::append_n_chars(v8, (const char *)&node, 1u);
      }
      else
      {
        _putc(91, *(FILE **)(v7 + 8));
      }
      PFileParser::InsertSeparator(v5, (OutputStream *)v7);
      ++v5->indentation;
      PFileParser::FormatSubNodes(v5, v4, (OutputStream *)v7);
      --v5->indentation;
      PFileParser::MaybeIndent(v5, (OutputStream *)v7);
      if ( *(_BYTE *)(v7 + 4) )
      {
        v9 = *(PStringBase<char> **)(v7 + 12);
        LOBYTE(node) = 93;
        PStringBase<char>::append_n_chars(v9, (const char *)&node, 1u);
      }
      else
      {
        _putc(93, *(FILE **)(v7 + 8));
      }
      v10 = (char)out;
      v5->want_blank = v5->separate_subnodes;
      v5->separate_subnodes = v10;
    }
    PFileParser::InsertSeparator(v5, (OutputStream *)v7);
    v11 = &strName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strName.m_charbuffer[-1]) && v11 )
      (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
  }
  return 1;
}

//----- (006BA870) --------------------------------------------------------  // acclient.c:722513
char __thiscall PFileParser::SaveToFile(PFileParser *this, PFileNode *file_node, PStringBase<char> *filename)
{
  unsigned int v3; // edi@1
  int v4; // eax@2
  _iobuf *v5; // esi@3
  unsigned int v6; // ecx@7
  char *v7; // esi@10
  char v9; // bl@14
  char *v10; // esi@14
  char v11; // [sp+0h] [bp-30h]@0
  PStringBase<char> dir; // [sp+10h] [bp-20h]@2
  unsigned int i; // [sp+14h] [bp-1Ch]@2
  long double retry_time; // [sp+18h] [bp-18h]@5
  OutputStream out; // [sp+20h] [bp-10h]@14

  v3 = (unsigned int)this;
  if ( !file_node )
    return 0;
  dir.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PSUtils::get_directory(&dir, filename);
  PSUtils::create_directory(&dir);
  v4 = *(_DWORD *)(v3 + 8);
  i = 0;
  if ( v4 )
  {
    while ( 1 )
    {
      v5 = __fsopen(filename->m_charbuffer->m_data, "w", 16);
      if ( v5 )
        goto LABEL_14;
      if ( (unsigned __int8)PSUtils::check_access(filename, 0) )
      {
        Timer::update_time();
        retry_time = COERCE_DOUBLE(Timer::cur_time.Cmd) + *(double *)(v3 + 16);
        while ( COERCE_DOUBLE(Timer::cur_time.Cmd) < retry_time )
          Timer::update_time();
        v6 = *(_DWORD *)(v3 + 8);
        ++i;
        if ( i < v6 )
          continue;
      }
      goto LABEL_10;
    }
  }
  v5 = (_iobuf *)i;
  if ( !i )
  {
LABEL_10:
    v7 = &dir.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&dir.m_charbuffer[-1]) )
    {
      if ( v7 )
        (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    }
    return 0;
  }
LABEL_14:
  out.m_pstring_stream = 0;
  out.saving_to_string = 0;
  *(_DWORD *)(v3 + 24) = 0;
  out.vfptr = (OutputStreamVtbl *)OutputStream::vftable;
  out.file_ptr = v5;
  *(_BYTE *)(v3 + 28) = 1;
  PFileParser::InsertComments((PFileParser *)v3, v3, file_node, &out, v11);
  v9 = PFileParser::FormatSubNodes((PFileParser *)v3, file_node, &out);
  _fclose(v5);
  v10 = &dir.m_charbuffer[-2].m_data[12];
  out.vfptr = (OutputStreamVtbl *)OutputStream::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&dir.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  return v9;
}
// 80698C: using guessed type int (__thiscall *OutputStream::vftable[2])(void *, char);

//----- (006BA9F0) --------------------------------------------------------  // acclient.c:722589
void __thiscall NewParser::NewParser(NewParser *this, PFileParser *parser)
{
  NewParser *v2; // esi@1
  volatile LONG *v3; // ST04_4@1
  volatile LONG *v4; // ST04_4@1
  volatile LONG *v5; // ST04_4@1

  v2 = this;
  this->include_path.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
  this->include_path._head = 0;
  this->include_path._tail = 0;
  this->include_path._num_elements = 0;
  InputStream::InputStream(&this->in);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v2->curr_comment.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v2->curr_filename.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
  v2->file_parser = parser;
  v5 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v2->m_strDebug.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v5);
  NewParser::Init(v2, &PStringBase<char>::null_string, &PStringBase<char>::null_string);
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);

//----- (006BAA70) --------------------------------------------------------  // acclient.c:722617
void __thiscall NewParser::~NewParser(NewParser *this)
{
  NewParser *v1; // edi@1
  int v2; // esi@1
  int v3; // esi@4
  int v4; // esi@7

  v1 = this;
  NewParser::Cleanup(this);
  v2 = (int)&v1->m_strDebug.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v2 + 4)) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->curr_filename.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = (int)&v1->curr_comment.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  InputStream::~InputStream(&v1->in);
  v1->include_path.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
  List<PStringBase<char>>::flush(&v1->include_path);
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);

//----- (006BAAF0) --------------------------------------------------------  // acclient.c:722642
void __thiscall PFileParser::PFileParser(PFileParser *this)
{
  PFileParser *v1; // esi@1
  NewParser *v2; // eax@1
  NewParser *v3; // eax@2

  v1 = this;
  this->new_parser = 0;
  this->locked_file = 0;
  this->num_retries = 1;
  *(_QWORD *)&this->retry_delay = 0i64;
  this->indentation = 0;
  this->separate_subnodes = 1;
  this->m_expandIncludes = 1;
  v2 = (NewParser *)operator new(0x48u);
  if ( v2 )
  {
    NewParser::NewParser(v2, v1);
    v1->new_parser = v3;
  }
  else
  {
    v1->new_parser = 0;
  }
}

//----- (006BAB40) --------------------------------------------------------  // acclient.c:722669
void __thiscall PFileParser::~PFileParser(PFileParser *this)
{
  NewParser **v1; // esi@1
  NewParser *v2; // edi@3

  v1 = (NewParser **)this;
  if ( this->locked_file )
    _fclose(this->locked_file);
  v2 = *v1;
  if ( *v1 )
  {
    NewParser::~NewParser(*v1);
    operator delete(v2);
  }
  *v1 = 0;
}

//----- (00724AF0) --------------------------------------------------------  // acclient.c:822417
int sub_724AF0()
{
  PStringBase<char>::PStringBase<char>(&indent_string, "  ");
  return atexit(sub_791B10);
}

//----- (00791B10) --------------------------------------------------------  // acclient.c:937828
void __cdecl sub_791B10()
{
  char *v0; // esi@1

  v0 = &indent_string.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&indent_string.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

