/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : NewParser
   Object     : ENGINE\pparser\NewParser.obj
   Functions  : 24
   Addresses  : 006BAB80 - 00791BD0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006BAB80) --------------------------------------------------------  // acclient.c:722687
char __thiscall InputStream::Next(InputStream *this)
{
  InputStream *v1; // esi@1
  char v2; // bl@1
  bool v3; // zf@4
  char *v4; // edi@5
  char v5; // al@5
  int v6; // esi@6
  char result; // al@7
  char v8; // al@9

  v1 = this;
  v2 = this->curr_char;
  if ( v2 == 10 )
  {
    ++this->line;
    this->col = 1;
  }
  else
  {
    ++this->col;
  }
  v3 = this->parsing_from_string == 0;
  ++this->num_chars;
  if ( v3 )
  {
    v8 = _getc(this->in_file);
    v1->curr_char = v8;
    if ( v8 != -1 && v8 != 0xFFFF )
      return v2;
    goto LABEL_11;
  }
  v4 = (char *)&this->in_string_iter;
  v5 = this->in_string_iter.vfptr->IndexToChar(
         (PStringBaseIter_Common<char> *)&this->in_string_iter,
         this->in_string_iter.curr);
  v1->curr_char = v5;
  if ( !v5 )
  {
LABEL_11:
    v1->done = 1;
    return v2;
  }
  v6 = v1->in_string_iter.curr + 1;
  if ( v6 <= (unsigned int)(**(int (__thiscall ***)(char *))v4)(v4) )
  {
    *((_DWORD *)v4 + 1) = v6;
    result = v2;
  }
  else
  {
    *((_DWORD *)v4 + 1) = (**(int (__thiscall ***)(char *))v4)(v4);
    result = v2;
  }
  return result;
}

//----- (006BAC10) --------------------------------------------------------  // acclient.c:722745
char __thiscall InputStream::SetFile(InputStream *this, PStringBase<char> *filename, _iobuf **ret_file, unsigned int num_tries, long double retry_delay)
{
  InputStream *v5; // esi@1
  _iobuf *v6; // eax@1
  PStringBase<char> *v7; // eax@5
  const char *v8; // eax@9
  FILE *v9; // eax@17
  unsigned int i; // [sp+Ch] [bp-Ch]@6
  double retry_time; // [sp+10h] [bp-8h]@14

  v5 = this;
  v6 = this->in_file;
  if ( v6 )
  {
    if ( !this->keep_locked )
      _fclose(v6);
    v5->in_file = 0;
  }
  v7 = filename;
  v5->keep_locked = 0;
  v5->line = 1;
  v5->col = 1;
  v5->num_chars = 0;
  v5->done = 1;
  if ( *(_DWORD *)&filename->m_charbuffer[-1].m_data[12] != 1 )
  {
    i = 0;
    if ( num_tries > 0 )
    {
      while ( 1 )
      {
        v8 = v7->m_charbuffer->m_data;
        if ( ret_file )
        {
          v5->in_file = __fsopen(v8, "r+", 16);
          __errno();
          *ret_file = v5->in_file;
          v5->keep_locked = 1;
        }
        else
        {
          v5->in_file = __fsopen(v8, "r", 32);
          __errno();
          v5->keep_locked = 0;
        }
        if ( v5->in_file )
          break;
        if ( i < num_tries - 1 )
        {
          retry_time = Timer::compute_time() + retry_delay;
          while ( Timer::compute_time() < retry_time )
            ;
        }
        ++i;
        if ( i >= num_tries )
          break;
        v7 = filename;
      }
    }
    v9 = v5->in_file;
    v5->parsing_from_string = 0;
    if ( v9 )
    {
      v5->curr_char = _getc(v9);
      v5->done = 0;
      return 1;
    }
    v5->done = 1;
  }
  return 0;
}

//----- (006BAD90) --------------------------------------------------------  // acclient.c:722857
void __thiscall InputStream::InputStream(InputStream *this)
{
  this->parsing_from_string = 0;
  this->keep_locked = 0;
  this->in_string_iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
  this->in_string_iter.pstring_ptr = 0;
  this->in_file = 0;
  this->line = 1;
  this->col = 1;
  this->num_chars = 0;
  this->curr_char = 0;
  this->done = 1;
}
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (006BADC0) --------------------------------------------------------  // acclient.c:722873
void __thiscall InputStream::~InputStream(InputStream *this)
{
  InputStream *v1; // esi@1
  _iobuf *v2; // eax@1

  v1 = this;
  v2 = this->in_file;
  if ( v2 )
  {
    if ( !this->keep_locked )
      _fclose(v2);
    v1->in_file = 0;
  }
  v1->keep_locked = 0;
  v1->line = 1;
  v1->col = 1;
  v1->num_chars = 0;
  v1->done = 1;
  v1->in_string_iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
}
// 794478: using guessed type void *PStringBaseIter_Common<unsigned short>::vftable;

//----- (006BAE10) --------------------------------------------------------  // acclient.c:722896
void __thiscall NewParser::Init(NewParser *this, PStringBase<char> *filename, PStringBase<char> *i_strDebug)
{
  NewParser *v3; // esi@1
  PSRefBufferCharData<char> *v4; // eax@1
  int v5; // edi@2
  PSRefBufferCharData<char> *v6; // eax@5
  PSRefBufferCharData<char> *v7; // edi@6
  int v8; // edi@7
  volatile LONG *v9; // ST00_4@10
  PSRefBufferCharData<char> *v10; // eax@11
  int v11; // edi@12
  PSRefBufferCharData<char> *v12; // eax@15

  v3 = this;
  v4 = this->curr_filename.m_charbuffer;
  if ( v4 != filename->m_charbuffer )
  {
    v5 = (int)&v4[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = filename->m_charbuffer;
    v3->curr_filename.m_charbuffer = filename->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v6[-1]);
  }
  v7 = v3->curr_comment.m_charbuffer;
  if ( v7 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v8 = (int)&v7[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    v9 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v3->curr_comment.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v9);
  }
  v3->error = 0;
  v10 = v3->m_strDebug.m_charbuffer;
  if ( v10 != i_strDebug->m_charbuffer )
  {
    v11 = (int)&v10[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v10[-1]) )
    {
      if ( v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    }
    v12 = i_strDebug->m_charbuffer;
    v3->m_strDebug.m_charbuffer = i_strDebug->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v12[-1]);
  }
}

//----- (006BAED0) --------------------------------------------------------  // acclient.c:722947
void __thiscall NewParser::Cleanup(NewParser *this)
{
  NewParser *v1; // esi@1
  _iobuf *v2; // eax@1
  PSRefBufferCharData<char> *v3; // eax@5
  int v4; // edi@6
  volatile LONG *v5; // ST00_4@9
  PSRefBufferCharData<char> *v6; // eax@10
  int v7; // edi@11
  volatile LONG *v8; // ST00_4@14
  PSRefBufferCharData<char> *v9; // eax@15
  int v10; // edi@16
  volatile LONG *v11; // ST00_4@19

  v1 = this;
  v2 = this->in.in_file;
  if ( v2 )
  {
    if ( !this->in.keep_locked )
      _fclose(v2);
    v1->in.in_file = 0;
  }
  v1->in.keep_locked = 0;
  v1->in.line = 1;
  v1->in.col = 1;
  v1->in.num_chars = 0;
  v1->in.done = 1;
  v3 = v1->curr_filename.m_charbuffer;
  if ( v3 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v4 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->curr_filename.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v5);
  }
  v6 = v1->curr_comment.m_charbuffer;
  if ( v6 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v7 = (int)&v6[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    v8 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->curr_comment.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v8);
  }
  v9 = v1->m_strDebug.m_charbuffer;
  if ( v9 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v10 = (int)&v9[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) )
    {
      if ( v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    }
    v11 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_strDebug.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v11);
  }
}

//----- (006BAFC0) --------------------------------------------------------  // acclient.c:723010
void __thiscall PFileNode::SetFileName(PFileNode *this, PStringBase<char> *filename)
{
  PFileNode *v2; // edi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // esi@2
  PSRefBufferCharData<char> *v5; // eax@5

  v2 = this;
  v3 = this->m_filename.m_charbuffer;
  if ( v3 != filename->m_charbuffer )
  {
    v4 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    v5 = filename->m_charbuffer;
    v2->m_filename.m_charbuffer = filename->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
  }
}

//----- (006BB010) --------------------------------------------------------  // acclient.c:723034
char __thiscall NewParser::ParseComment(NewParser *this, bool eat_newlines)
{
  NewParser *v2; // ebp@1
  PSRefBufferCharData<char> *v3; // eax@1
  PStringBase<char> *v4; // esi@1
  int v5; // edi@2
  volatile LONG *v6; // ST08_4@5
  int v7; // ebx@6
  char v8; // al@7
  char i; // al@15
  PSRefBufferCharData<char> *v10; // eax@19
  unsigned int v11; // ebp@19
  int v12; // ecx@19
  int v13; // edi@22
  PStringBase<char> v14; // eax@27
  unsigned int v15; // ebp@27
  int v16; // ecx@27
  int v17; // edi@30
  char v18; // al@34
  char result; // al@42
  char Source[4]; // [sp+10h] [bp-8h]@19
  NewParser *v21; // [sp+14h] [bp-4h]@1

  v2 = this;
  v3 = this->curr_comment.m_charbuffer;
  v4 = &this->curr_comment;
  v21 = this;
  if ( v3 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v5 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v4->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v6);
  }
  v7 = (int)&v2->in.parsing_from_string;
  while ( 1 )
  {
    v8 = v2->in.curr_char;
    if ( v8 != 44 && v8 != 32 && v8 != 9 && v8 != 13 && v8 != 10 )
      break;
    InputStream::Next(&v2->in);
  }
  if ( v2->in.curr_char == 35 )
  {
    do
    {
      InputStream::Next((InputStream *)v7);
      if ( v21->in.done )
        break;
      for ( i = InputStream::Next((InputStream *)v7); i != 10; i = InputStream::Next((InputStream *)v7) )
      {
        if ( i == -1 || i == 0xFFFF || !i )
          break;
        Source[0] = i;
        v10 = v4->m_charbuffer;
        v11 = *(_DWORD *)&v4->m_charbuffer[-1].m_data[12];
        v12 = v11 + 1;
        if ( *(_DWORD *)&v4->m_charbuffer[-1].m_data[0] != 1 || (unsigned int)v12 > *(_DWORD *)&v10[-1].m_data[4] )
        {
          v13 = (int)&v10[-2].m_data[12];
          PStringBase<char>::allocate_ref_buffer(v4, v11);
          ps_strcpy(v4->m_charbuffer->m_data, (const char *)(v13 + 20));
          if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) && v13 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
        }
        else
        {
          *(_DWORD *)&v10[-1].m_data[12] = v12;
          *(_DWORD *)&v4->m_charbuffer[-1].m_data[8] = -1;
        }
        _strncpy((char *)v4->m_charbuffer + v11 - 1, Source, 1u);
        v4->m_charbuffer->m_data[*(_DWORD *)&v4->m_charbuffer[-1].m_data[12] - 1] = 0;
      }
      if ( v21->in.done )
        break;
      v14.m_charbuffer = v4->m_charbuffer;
      Source[0] = 10;
      v15 = *(_DWORD *)&v14.m_charbuffer[-1].m_data[12];
      v16 = v15 + 1;
      if ( *(_DWORD *)&v14.m_charbuffer[-1].m_data[0] != 1
        || (unsigned int)v16 > *(_DWORD *)&v14.m_charbuffer[-1].m_data[4] )
      {
        v17 = (int)&v14.m_charbuffer[-2].m_data[12];
        PStringBase<char>::allocate_ref_buffer(v4, v15);
        strcpy(v4->m_charbuffer->m_data, (const char *)(v17 + 20));
        if ( !InterlockedDecrement((volatile LONG *)(v17 + 4)) && v17 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
      }
      else
      {
        *(_DWORD *)&v14.m_charbuffer[-1].m_data[12] = v16;
        *(_DWORD *)&v4->m_charbuffer[-1].m_data[8] = -1;
      }
      _strncpy((char *)v4->m_charbuffer + v15 - 1, Source, 1u);
      v4->m_charbuffer->m_data[*(_DWORD *)&v4->m_charbuffer[-1].m_data[12] - 1] = 0;
      while ( 1 )
      {
        v18 = *(_BYTE *)(v7 + 32);
        if ( v18 != 44 && v18 != 32 && v18 != 9 && v18 != 13 && (v18 != 10 || !eat_newlines) )
          break;
        InputStream::Next((InputStream *)v7);
      }
    }
    while ( v21->in.curr_char == 35 );
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006BB240) --------------------------------------------------------  // acclient.c:723150
char __thiscall NewParser::ParseNodeName(NewParser *this, PFileNode *node)
{
  NewParser *v2; // esi@1
  char *i; // edi@1
  char v4; // al@2
  PFileNode *v6; // ebx@10
  signed int v7; // eax@12
  bool v8; // zf@16
  char *v9; // esi@24
  char *v10; // esi@27
  signed int v11; // eax@30
  int v12; // eax@35
  int v13; // eax@36
  bool v14; // zf@37
  char v15; // al@38
  PStringBase<char> v16; // ST04_4@47
  char *v17; // esi@47
  PStringBase<char> name; // [sp+10h] [bp-Ch]@10
  PStringBase<char> v19; // [sp+14h] [bp-8h]@24
  PStringBase<char> v20; // [sp+18h] [bp-4h]@27

  v2 = this;
  for ( i = (char *)&this->in.parsing_from_string; ; InputStream::Next((InputStream *)i) )
  {
    v4 = i[32];
    if ( v4 != 44 && v4 != 32 && v4 != 9 && v4 != 13 && v4 != 10 )
      break;
  }
  if ( v2->in.done )
    return 0;
  v6 = node;
  PFileNode::SetFileName(node, &v2->curr_filename);
  PFileNode::SetLineNumber(v6, v2->in.line);
  PFileNode::SetColumnNumber(v6, v2->in.col);
  name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( v2->in.curr_char == 34 )
  {
LABEL_11:
    InputStream::Next((InputStream *)i);
    while ( 1 )
    {
      v7 = v2->in.curr_char;
      if ( v7 <= 34 )
        break;
      if ( v7 != 92 )
      {
        v8 = v7 == 0xFFFF;
LABEL_19:
        if ( !v8 )
        {
LABEL_20:
          LOBYTE(node) = v2->in.curr_char;
          PStringBase<char>::append_n_chars(&name, (const char *)&node, 1u);
          goto LABEL_11;
        }
LABEL_24:
        PStringBase<char>::PStringBase<char>(&v19, "unterminated string");
        v9 = &v19.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v19.m_charbuffer[-1]) && v9 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
        goto $L86561;
      }
      InputStream::Next((InputStream *)i);
      if ( v2->in.done )
      {
        PStringBase<char>::PStringBase<char>(&v20, "unexpected EOF after '\\'");
        v10 = &v20.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v20.m_charbuffer[-1]) && v10 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
        goto $L86561;
      }
      LOBYTE(node) = InputStream::Next((InputStream *)i);
      PStringBase<char>::append_n_chars(&name, (const char *)&node, 1u);
    }
    if ( v7 == 34 )
    {
      InputStream::Next((InputStream *)i);
      goto $L86561;
    }
    if ( v7 < -1 )
      goto LABEL_20;
    if ( v7 > 0 )
    {
      v8 = v7 == 10;
      goto LABEL_19;
    }
    goto LABEL_24;
  }
  while ( 1 )
  {
    v11 = v2->in.curr_char;
    if ( v11 <= 44 )
      break;
    if ( v11 > 123 )
    {
      if ( v11 == 125 )
        goto $L86561;
      v14 = v11 == 0xFFFF;
LABEL_44:
      if ( v14 )
        goto $L86561;
LABEL_45:
      LOBYTE(node) = v2->in.curr_char;
      PStringBase<char>::append_n_chars(&name, (const char *)&node, 1u);
      InputStream::Next((InputStream *)i);
    }
    else
    {
      if ( v11 == 123 )
        goto $L86561;
      v12 = v11 - 91;
      if ( !v12 )
        goto $L86561;
      v13 = v12 - 1;
      if ( v13 )
      {
        v14 = v13 == 1;
        goto LABEL_44;
      }
      InputStream::Next((InputStream *)i);
      v15 = InputStream::Next((InputStream *)i);
      if ( !v15 || v15 == -1 || v15 == 0xFFFF )
      {
        PStringBase<char>::PStringBase<char>(&v20, "unexpected EOF after '\\'");
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v20);
        goto $L86561;
      }
      LOBYTE(node) = v15;
      PStringBase<char>::append_n_chars(&name, (const char *)&node, 1u);
    }
  }
  if ( v11 != 44 )
  {
    switch ( v11 + 1 )
    {
      default:
        goto LABEL_45;
      case 0:
      case 1:
      case 10:
      case 11:
      case 14:
      case 33:
      case 35:
      case 36:
      case 41:
      case 42:
        break;
    }
  }
$L86561:
  v16.m_charbuffer = name.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&name.m_charbuffer[-1]);
  PFileNode::SetNameAsPString(v6, v16);
  v17 = &name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&name.m_charbuffer[-1]) )
  {
    if ( v17 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  }
  return 1;
}

//----- (006BB500) --------------------------------------------------------  // acclient.c:723315
char __thiscall NewParser::ParseNode(NewParser *this, PFileNode *node)
{
  NewParser *v2; // esi@1
  char *i; // edi@1
  char v4; // al@2
  char v5; // al@8
  PFileNode *v6; // ebx@14
  char v7; // al@17
  signed int v8; // eax@23
  char v9; // bl@26
  int v10; // eax@28
  int v11; // eax@29
  char v13; // al@34
  char v14; // al@43

  v2 = this;
  for ( i = (char *)&this->in.parsing_from_string; ; InputStream::Next((InputStream *)i) )
  {
    v4 = i[32];
    if ( v4 != 44 && v4 != 32 && v4 != 9 && v4 != 13 && v4 != 10 )
      break;
  }
  v5 = v2->in.curr_char;
  if ( !v5 )
    return 0;
  if ( v5 == -1 )
    return 0;
  if ( v5 == 0xFFFF )
    return 0;
  if ( v5 == 93 )
    return 0;
  if ( v5 == 125 )
    return 0;
  if ( v5 == 41 )
    return 0;
  v6 = node;
  PFileNode::AddComment(node, &v2->curr_comment);
  if ( !NewParser::ParseNodeName(v2, v6) )
    return 0;
  if ( v2->in.done )
    return 1;
  NewParser::ParseComment(v2, 1);
  while ( 1 )
  {
    v7 = i[32];
    if ( v7 != 44 && v7 != 32 && v7 != 9 && v7 != 13 && v7 != 10 )
      break;
    InputStream::Next((InputStream *)i);
  }
  v8 = v2->in.curr_char;
  if ( v8 <= 93 )
  {
    if ( v8 != 93 )
    {
      switch ( v8 + 1 )
      {
        case 41:
          v9 = 41;
          goto LABEL_33;
        case 92:
          v9 = 93;
          goto LABEL_33;
        case 0:
        case 1:
        case 42:
          goto $L82481;
        default:
          return 1;
      }
      return 1;
    }
$L82481:
    PFileNode::AddComment(v6, &v2->curr_comment);
    PStringBase<char>::clear(&v2->curr_comment);
    return 1;
  }
  v10 = v8 - 123;
  if ( !v10 )
  {
    v9 = 125;
LABEL_33:
    PFileNode::AddComment(node, &v2->curr_comment);
    PStringBase<char>::clear(&v2->curr_comment);
    InputStream::Next((InputStream *)i);
    if ( (unsigned __int8)NewParser::ParseNodes(v2, node) )
    {
      while ( 1 )
      {
        v13 = i[32];
        if ( v13 != 44 && v13 != 32 && v13 != 9 && v13 != 13 && v13 != 10 )
          break;
        InputStream::Next((InputStream *)i);
      }
      if ( v2->in.curr_char == v9 )
      {
        InputStream::Next((InputStream *)i);
        NewParser::ParseComment(v2, 1);
        v14 = v2->in.curr_char;
        if ( !v14 || v14 == -1 || v14 == 0xFFFF || v14 == 41 || v14 == 93 || v14 == 125 )
        {
          PFileNode::AddComment(node, &v2->curr_comment);
          PStringBase<char>::clear(&v2->curr_comment);
        }
        return 1;
      }
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&node, "mismatched paren");
      v2->error = 1;
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&node);
    }
    return 0;
  }
  v11 = v10 - 2;
  if ( !v11 || v11 == 65410 )
    goto $L82481;
  return 1;
}

//----- (006BB750) --------------------------------------------------------  // acclient.c:723433
List<PFileNode *> *__thiscall List<PFileNode *>::scalar_deleting_destructor(List<PFileNode *> *this, unsigned int a2)
{
  List<PFileNode *> *v2; // esi@1

  v2 = this;
  this->vfptr = (List<PFileNode *>Vtbl *)&List<PFileNode *>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 806990: using guessed type int (__thiscall *List<PFileNode *>::vftable)(void *, char);

//----- (006BB780) --------------------------------------------------------  // acclient.c:723447
BOOL __thiscall NewParser::ParseNodes(NewParser *this, PFileNode *parent_node)
{
  int v2; // edi@1
  char *v3; // ecx@4
  PFileNode *v4; // eax@4
  int v5; // esi@4
  PSRefBufferCharData<char> *v6; // ebp@5
  int v7; // eax@6
  bool v8; // zf@6
  PSRefBufferCharData<char> *v9; // eax@6
  ListNode<PFileNode *> *v10; // eax@9
  ListNode<PFileNode *> *v11; // esi@9
  void *v12; // ecx@14
  PStringBase<char> strName; // [sp+10h] [bp-14h]@5
  List<PFileNode *> node_list; // [sp+14h] [bp-10h]@9

  v2 = (int)this;
  NewParser::ParseComment(this, 1);
  while ( 1 )
  {
    if ( !PFileNode::s_fallocPool.m_firstFreeChunk )
      FallocPool::AllocateNewPool(&PFileNode::s_fallocPool);
    v3 = PFileNode::s_fallocPool.m_firstFreeChunk;
    PFileNode::s_fallocPool.m_firstFreeChunk = *(char **)PFileNode::s_fallocPool.m_firstFreeChunk;
    PFileNode::PFileNode((PFileNode *)v3);
    v5 = (int)v4;
    if ( !NewParser::ParseNode((NewParser *)v2, v4) )
    {
      if ( v5 && !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
        goto LABEL_29;
      return *(_BYTE *)(v2 + 16) == 0;
    }
    strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PFileNode::GetNameAsPString((PFileNode *)v5, v2, &strName);
    v6 = strName.m_charbuffer;
    if ( !*(_BYTE *)(v2 + 16) )
    {
      v7 = *(_DWORD *)&strName.m_charbuffer[-1].m_data[12];
      v8 = v7 == 0;
      v9 = (PSRefBufferCharData<char> *)((char *)strName.m_charbuffer + v7 - 1);
      if ( !v8 )
        v9 = strName.m_charbuffer;
      if ( v9->m_data[0] == 33 )
      {
        node_list.vfptr = (List<PFileNode *>Vtbl *)&List<PFileNode *>::vftable;
        node_list._head = 0;
        node_list._tail = 0;
        node_list._num_elements = 0;
        NewParser::PostProcessNode((NewParser *)v2, (PFileNode *)v5, &node_list);
        v10 = node_list._head;
        v11 = node_list._head;
        while ( v11 )
        {
          PFileNode::AdoptSubNode(parent_node, v11->data);
          v11 = v11->next;
          v10 = node_list._head;
        }
        node_list.vfptr = (List<PFileNode *>Vtbl *)&List<PFileNode *>::vftable;
        while ( v10 )
        {
          v12 = v10;
          v10 = v10->next;
          node_list._head = v10;
          if ( v10 )
          {
            v10->prev = 0;
            v10 = node_list._head;
          }
          else
          {
            node_list._tail = 0;
          }
          if ( v12 )
          {
            operator delete(v12);
            v10 = node_list._head;
          }
          --node_list._num_elements;
        }
        goto LABEL_21;
      }
    }
    PFileNode::AdoptSubNode(parent_node, (PFileNode *)v5);
    if ( *(_BYTE *)(v2 + 16) )
      break;
LABEL_21:
    if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v6 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&v6[-2].m_data[12])(&v6[-2].m_data[12], 1);
  }
  v5 = (int)&v6[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v6 != (PSRefBufferCharData<char> *)20 )
LABEL_29:
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return *(_BYTE *)(v2 + 16) == 0;
}
// 806990: using guessed type int (__thiscall *List<PFileNode *>::vftable)(void *, char);

//----- (006BB910) --------------------------------------------------------  // acclient.c:723546
void __thiscall NewParser::FindIncludeFiles(NewParser *this, PStringBase<char> *name, List<PStringBase<char> > *matching_filenames)
{
  List<PStringBase<char> > *v3; // esi@1
  NewParser *v4; // edi@1
  const char **v5; // ebp@1
  char *v6; // esi@4
  int v7; // ecx@8
  int v8; // ecx@12
  LONG (__stdcall *v9)(volatile LONG *); // edi@14
  PStringBase<char> *v10; // esi@14
  char *v11; // esi@21
  char *v12; // esi@24
  PStringBase<char> search_string; // [sp+10h] [bp-8h]@1
  NewParser *v14; // [sp+14h] [bp-4h]@1

  v3 = matching_filenames;
  v4 = this;
  v14 = this;
  List<PStringBase<char>>::flush(matching_filenames);
  search_string.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v5 = (const char **)name;
  while ( 1 )
  {
    v4 = (NewParser *)v4->include_path._head;
    if ( !v4 )
      break;
    if ( search_string.m_charbuffer != (PSRefBufferCharData<char> *)v4->include_path.vfptr )
    {
      v6 = &search_string.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&search_string.m_charbuffer[-1]) && v6 )
        (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
      search_string.m_charbuffer = (PSRefBufferCharData<char> *)v4->include_path.vfptr;
      InterlockedIncrement((volatile LONG *)&search_string.m_charbuffer[-1]);
      v3 = matching_filenames;
    }
    PSUtils::cleanup_directory_name(&search_string, 0);
    v7 = *((_DWORD *)*v5 - 1);
    if ( v7 != 1 )
      PStringBase<char>::append_n_chars(&search_string, *v5, v7 - 1);
    PSUtils::find_files(&search_string, v3, 0, 0);
  }
  if ( v3->_num_elements )
  {
    v9 = InterlockedDecrement;
  }
  else
  {
    name = (PStringBase<char> *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PSUtils::get_directory((PStringBase<char> *)&name, &v14->curr_filename);
    PSUtils::cleanup_directory_name((PStringBase<char> *)&name, 0);
    v8 = *((_DWORD *)*v5 - 1);
    if ( v8 != 1 )
      PStringBase<char>::append_n_chars((PStringBase<char> *)&name, *v5, v8 - 1);
    PSUtils::find_files((PStringBase<char> *)&name, v3, 0, 0);
    v9 = InterlockedDecrement;
    v10 = name - 5;
    if ( !InterlockedDecrement((volatile LONG *)&name[-4]) && v10 )
      (*(void (__thiscall **)(PStringBase<char> *, signed int))&v10->m_charbuffer->m_data[0])(v10, 1);
    v3 = matching_filenames;
  }
  if ( !v3->_num_elements )
  {
    FileArray::GetAbsoluteFilePathForDummies((PStringBase<char> *)&matching_filenames, (PStringBase<char> *)v5);
    if ( matching_filenames[-1]._num_elements != 1 )
      List<PStringBase<char>>::push_back(v3, (PStringBase<char> *)&matching_filenames);
    v11 = (char *)&matching_filenames[-2]._num_elements;
    if ( !v9((volatile LONG *)&matching_filenames[-1]) && v11 )
      (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
  }
  v12 = &search_string.m_charbuffer[-2].m_data[12];
  if ( !v9((volatile LONG *)&search_string.m_charbuffer[-1]) && v12 )
    (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
}

//----- (006BBAC0) --------------------------------------------------------  // acclient.c:723623
char __thiscall NewParser::Parse(NewParser *this, PFileNode *node)
{
  PFileNode *v2; // esi@1
  NewParser *v3; // ebp@1
  char *v4; // edi@1
  PSRefBufferCharData<char> *v5; // eax@1
  int v6; // ebx@2
  PSRefBufferCharData<char> *v7; // eax@5
  PStringBase<char> v8; // edi@6
  int v9; // edi@6
  char *v10; // esi@11
  volatile LONG *v11; // ST04_4@11

  v2 = node;
  v3 = this;
  v4 = (char *)&this->curr_filename;
  PFileNode::InitFileInfo(node, &this->curr_filename);
  v5 = v2->m_filename.m_charbuffer;
  if ( v5 != *(PSRefBufferCharData<char> **)v4 )
  {
    v6 = (int)&v5[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = *(PSRefBufferCharData<char> **)v4;
    v2->m_filename.m_charbuffer = *(PSRefBufferCharData<char> **)v4;
    InterlockedIncrement((volatile LONG *)&v7[-1]);
  }
  v8.m_charbuffer = *(PSRefBufferCharData<char> **)v4;
  InterlockedIncrement((volatile LONG *)&v8.m_charbuffer[-1]);
  InterlockedIncrement((volatile LONG *)&v8.m_charbuffer[-1]);
  PFileNode::SetNameAsPString(v2, v8);
  v9 = (int)&v8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  NewParser::ParseComment(v3, 0);
  PFileNode::AddComment(v2, &v3->curr_comment);
  NewParser::ParseNodes(v3, v2);
  PFileNode::AddComment(v2, &v3->curr_comment);
  if ( v3->error )
    return 0;
  if ( !v3->in.done )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&node, "unexpected close brace");
    v10 = (char *)&node[-1].sub_nodes.m_num;
    v11 = (volatile LONG *)&node[-1].m_bProcessed;
    v3->error = 1;
    if ( !InterlockedDecrement(v11) )
    {
      if ( v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    }
    return 0;
  }
  return 1;
}

//----- (006BBBC0) --------------------------------------------------------  // acclient.c:723680
char __thiscall NewParser::ParseFile(NewParser *this, PFileNode *node, PStringBase<char> *filename, _iobuf **ret_file, unsigned int num_tries, long double retry_delay)
{
  NewParser *v6; // esi@1
  char result; // al@1
  char v8; // bl@2

  v6 = this;
  NewParser::Init(this, filename, &PStringBase<char>::null_string);
  result = InputStream::SetFile(&v6->in, filename, ret_file, num_tries, retry_delay);
  if ( result )
  {
    v8 = NewParser::Parse(v6, node);
    NewParser::Cleanup(v6);
    result = v8;
  }
  return result;
}

//----- (006BBC20) --------------------------------------------------------  // acclient.c:723699
void __thiscall NewParser::PostProcessNode(NewParser *this, PFileNode *node, List<PFileNode *> *retval)
{
  int v3; // edi@1
  NewParser *v4; // esi@1
  PFileNode *v5; // esi@3
  LONG (__stdcall *v6)(volatile LONG *); // ebx@5
  char *v7; // esi@5
  char *v8; // ecx@12
  int v9; // eax@12
  int v10; // edi@12
  char v11; // bl@13
  unsigned int v12; // ebp@14
  int v13; // esi@15
  List<PFileNode *> *v14; // ebx@15
  int v15; // esi@16
  char *v16; // esi@18
  char *v17; // esi@27
  volatile LONG *v18; // ST10_4@27
  char *v19; // esi@30
  volatile LONG *v20; // ST10_4@30
  char *v21; // esi@33
  char *v22; // esi@36
  PSRefBufferCharData<char> *v23; // esi@46
  PFileNode *v24; // eax@46
  int v25; // eax@48
  int v26; // esi@50
  char *v27; // esi@56
  PSRefBufferCharData<char> *v28; // esi@61
  PFileNode *v29; // eax@61
  int v30; // esi@63
  char *v31; // esi@68
  PStringBase<char> sFileName; // [sp+10h] [bp-78h]@9
  PStringBase<char> strName; // [sp+14h] [bp-74h]@4
  NewParser *v34; // [sp+18h] [bp-70h]@1
  PStringBase<char> msg; // [sp+1Ch] [bp-6Ch]@5
  PStringBase<char> node_comment; // [sp+20h] [bp-68h]@15
  PFileNodeIter iter; // [sp+24h] [bp-64h]@3
  List<PStringBase<char> > matching_filenames; // [sp+30h] [bp-58h]@3
  NewParser new_parser; // [sp+40h] [bp-48h]@10

  v3 = (int)node;
  v4 = this;
  v34 = this;
  if ( PFileNode::IsKeyword(node, (int)node, &include_command_string) && v4->file_parser->m_expandIncludes )
  {
    matching_filenames.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
    matching_filenames._head = 0;
    matching_filenames._tail = 0;
    matching_filenames._num_elements = 0;
    PFileNodeIter::PFileNodeIter(&iter, (PFileNode *)v3);
    v5 = PFileNodeIter::Curr(&iter);
    if ( v5 )
    {
      while ( 1 )
      {
        strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        PFileNode::GetNameAsPString(v5, v3, &strName);
        NewParser::FindIncludeFiles(v34, &strName, &matching_filenames);
        if ( matching_filenames._num_elements <= 1 )
        {
          v6 = InterlockedDecrement;
        }
        else
        {
          msg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
          PStringBase<char>::sprintf(&msg, "Multiple files named '%s' found", strName.m_charbuffer);
          v6 = InterlockedDecrement;
          v7 = &msg.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1]) && v7 )
            (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
        }
        sFileName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        if ( !List<PStringBase<char>>::pop_front(&matching_filenames, &sFileName) )
        {
          msg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
          PStringBase<char>::sprintf(&msg, "Couldn't find !include file '%s'", strName.m_charbuffer);
          v19 = &msg.m_charbuffer[-2].m_data[12];
          v20 = (volatile LONG *)&msg.m_charbuffer[-1];
          v34->error = 1;
          if ( !v6(v20) && v19 )
            (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
          goto LABEL_33;
        }
        NewParser::NewParser(&new_parser, v34->file_parser);
        if ( !PFileNode::s_fallocPool.m_firstFreeChunk )
          FallocPool::AllocateNewPool(&PFileNode::s_fallocPool);
        v8 = PFileNode::s_fallocPool.m_firstFreeChunk;
        PFileNode::s_fallocPool.m_firstFreeChunk = *(char **)PFileNode::s_fallocPool.m_firstFreeChunk;
        PFileNode::PFileNode((PFileNode *)v8);
        v10 = v9;
        NewParser::Init(&new_parser, &sFileName, &PStringBase<char>::null_string);
        if ( !InputStream::SetFile(&new_parser.in, &sFileName, 0, 1u, 0.0) )
          goto LABEL_27;
        v11 = NewParser::Parse(&new_parser, (PFileNode *)v10);
        NewParser::Cleanup(&new_parser);
        if ( !v11 )
          break;
        v12 = PFileNode::GetNumSubNodes((PFileNode *)v10);
        if ( v12 )
        {
          v13 = PFileNode::RemoveSubNode((PFileNode *)v10, 0);
          node_comment.m_charbuffer = *(PSRefBufferCharData<char> **)(v13 + 16);
          msg.m_charbuffer = (PSRefBufferCharData<char> *)v13;
          InterlockedIncrement((volatile LONG *)&node_comment.m_charbuffer[-1]);
          PFileNode::ClearComments((PFileNode *)v13, 0);
          PFileNode::AddComment((PFileNode *)v13, &node->comment_string);
          PFileNode::AddComment((PFileNode *)v13, (PStringBase<char> *)(v10 + 16));
          PFileNode::AddComment((PFileNode *)v13, &node_comment);
          v14 = retval;
          List<PFileNode *>::push_back((List<UIElement_UIItem *> *)retval, (UIElement_UIItem *const *)&msg);
          if ( v12 > 1 )
          {
            v15 = v12 - 1;
            do
            {
              msg.m_charbuffer = (PSRefBufferCharData<char> *)PFileNode::RemoveSubNode((PFileNode *)v10, 0);
              List<PFileNode *>::push_back((List<UIElement_UIItem *> *)v14, (UIElement_UIItem *const *)&msg);
              --v15;
            }
            while ( v15 );
          }
          v16 = &node_comment.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&node_comment.m_charbuffer[-1]) && v16 )
            (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
        }
        v6 = InterlockedDecrement;
LABEL_22:
        if ( v10 && !v6((volatile LONG *)(v10 + 4)) )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
        NewParser::~NewParser(&new_parser);
        v3 = (int)node;
LABEL_33:
        v21 = &sFileName.m_charbuffer[-2].m_data[12];
        if ( !v6((volatile LONG *)&sFileName.m_charbuffer[-1]) && v21 )
          (**(void (__thiscall ***)(char *, signed int))v21)(v21, 1);
        v22 = &strName.m_charbuffer[-2].m_data[12];
        if ( !v6((volatile LONG *)&strName.m_charbuffer[-1]) && v22 )
          (**(void (__thiscall ***)(char *, signed int))v22)(v22, 1);
        v5 = (PFileNode *)PFileNodeIter::Next(&iter);
        if ( !v5 )
          goto LABEL_40;
      }
      v6 = InterlockedDecrement;
LABEL_27:
      msg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PStringBase<char>::sprintf(&msg, "Failed to parse include: %s", sFileName.m_charbuffer);
      v17 = &msg.m_charbuffer[-2].m_data[12];
      v18 = (volatile LONG *)&msg.m_charbuffer[-1];
      v34->error = 1;
      if ( !v6(v18) && v17 )
        (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
      goto LABEL_22;
    }
LABEL_40:
    if ( v3 )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    PFileNodeIter::~PFileNodeIter(&iter);
    matching_filenames.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
    List<PStringBase<char>>::flush(&matching_filenames);
  }
  else if ( PFileNode::IsKeyword((PFileNode *)v3, v3, &error_command_string) )
  {
    msg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    if ( PFileNode::GetNumSubNodes((PFileNode *)v3) )
    {
      v23 = PStringBase<char>::s_NullBuffer.m_charbuffer;
      node_comment.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      v24 = (PFileNode *)(*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 12))(v3, 0);
      if ( v24 )
      {
        PFileNode::GetNameAsPString(v24, v3, &node_comment);
        v23 = node_comment.m_charbuffer;
      }
      v25 = *(_DWORD *)&v23[-1].m_data[12];
      if ( v25 != 1 )
        PStringBase<char>::append_n_chars(&msg, v23->m_data, v25 - 1);
      v26 = (int)&v23[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)(v26 + 4)) && v26 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
    }
    v34->error = 1;
    if ( v3 && !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v27 = &msg.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1]) && v27 )
      (**(void (__thiscall ***)(char *, signed int))v27)(v27, 1);
  }
  else if ( PFileNode::IsKeyword((PFileNode *)v3, v3, &warning_command_string) )
  {
    node_comment.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    if ( PFileNode::GetNumSubNodes((PFileNode *)v3) )
    {
      v28 = PStringBase<char>::s_NullBuffer.m_charbuffer;
      msg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      v29 = (PFileNode *)(*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 12))(v3, 0);
      if ( v29 )
      {
        PFileNode::GetNameAsPString(v29, v3, &msg);
        v28 = msg.m_charbuffer;
      }
      PStringBase<unsigned short>::operator=(
        (PStringBase<unsigned short> *)&node_comment,
        (const unsigned __int16 *)&msg);
      v30 = (int)&v28[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)(v30 + 4)) && v30 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v30)(v30, 1);
    }
    if ( v3 )
      ReferenceCountTemplate<1048576,0>::Release((ReferenceCountTemplate<1048576,0> *)v3);
    v31 = &node_comment.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&node_comment.m_charbuffer[-1]) && v31 )
      (**(void (__thiscall ***)(char *, signed int))v31)(v31, 1);
  }
  else
  {
    List<PFileNode *>::push_back((List<UIElement_UIItem *> *)retval, (UIElement_UIItem *const *)&node);
  }
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);

//----- (00724B10) --------------------------------------------------------  // acclient.c:822424
int sub_724B10()
{
  PStringBase<char>::PStringBase<char>(&dummy_string_filename, "-string-");
  return atexit(sub_791B40);
}

//----- (00724B30) --------------------------------------------------------  // acclient.c:822431
int sub_724B30()
{
  PStringBase<char>::PStringBase<char>(&include_command_string, "!include");
  return atexit(sub_791B70);
}

//----- (00724B50) --------------------------------------------------------  // acclient.c:822438
int sub_724B50()
{
  PStringBase<char>::PStringBase<char>(&error_command_string, "!error");
  return atexit(sub_791BA0);
}

//----- (00724B70) --------------------------------------------------------  // acclient.c:822445
int _E82_75()
{
  PStringBase<char>::PStringBase<char>(&warning_command_string, "!warning");
  return atexit(_E83_71);
}

//----- (00791B40) --------------------------------------------------------  // acclient.c:937841
void __cdecl sub_791B40()
{
  char *v0; // esi@1

  v0 = &dummy_string_filename.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&dummy_string_filename.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791B70) --------------------------------------------------------  // acclient.c:937854
void __cdecl sub_791B70()
{
  char *v0; // esi@1

  v0 = &include_command_string.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&include_command_string.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791BA0) --------------------------------------------------------  // acclient.c:937867
void __cdecl sub_791BA0()
{
  char *v0; // esi@1

  v0 = &error_command_string.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&error_command_string.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00791BD0) --------------------------------------------------------  // acclient.c:937880
void __cdecl _E83_71()
{
  char *v0; // esi@1

  v0 = &warning_command_string.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&warning_command_string.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

