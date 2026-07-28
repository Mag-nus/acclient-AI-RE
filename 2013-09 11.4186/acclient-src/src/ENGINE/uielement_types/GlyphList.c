/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GlyphList
   Object     : ENGINE\uielement_types\GlyphList.obj
   Functions  : 44
   Addresses  : 00472520 - 006EC130 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00472520) --------------------------------------------------------  // acclient.c:175000
BOOL __cdecl LinebreakUtils::IsWhiteSpace(unsigned __int16 c)
{
  return c == 9 || c == 13 || c == 32;
}

//----- (00472540) --------------------------------------------------------  // acclient.c:175006
BOOL __cdecl LinebreakUtils::IsNonBeginningChar(unsigned __int16 c)
{
  return c == 33
      || c == 41
      || c == 44
      || c == 46
      || c == 63
      || c == 12289
      || c == 12290
      || c == 12540
      || c == -255
      || c == -247
      || c == -225
      || c == -144
      || c == -98
      || c == -97;
}

//----- (004725B0) --------------------------------------------------------  // acclient.c:175025
BOOL __cdecl LinebreakUtils::IsNonEndingChar(unsigned __int16 c)
{
  return c == 40 || c == -248;
}

//----- (004725D0) --------------------------------------------------------  // acclient.c:175031
BOOL __cdecl LinebreakUtils::IsEastAsianChar(unsigned __int16 c)
{
  return c >= 0x1100u && c <= 0x11FFu
      || c >= 0x3000u && c <= 0xD7AFu
      || c >= 0xF900u && c <= 0xFAFFu
      || c >= 0xFF00u && c <= 0xFFDCu;
}

//----- (00472610) --------------------------------------------------------  // acclient.c:175040
bool __cdecl LinebreakUtils::CanBreakLineAt(Glyph *prev, Glyph *cur)
{
  unsigned __int16 v2; // si@4
  unsigned __int16 v3; // di@4
  bool result; // al@5

  if ( cur && prev && prev != cur )
  {
    v2 = prev->m_data;
    v3 = cur->m_data;
    if ( prev->m_data == 10 )
      result = 1;
    else
      result = ((unsigned __int8)LinebreakUtils::IsWhiteSpace(v2)
             || (unsigned __int8)LinebreakUtils::IsEastAsianChar(v3)
             || (unsigned __int8)LinebreakUtils::IsEastAsianChar(v2))
            && !(unsigned __int8)LinebreakUtils::IsNonBeginningChar(v3)
            && !(unsigned __int8)LinebreakUtils::IsNonEndingChar(v2);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00472690) --------------------------------------------------------  // acclient.c:175067
int __thiscall GlyphLine::vector_deleting_destructor(GlyphLine *this, unsigned int a2)
{
  GlyphLine *v2; // esi@1
  int v3; // ecx@2
  int v4; // eax@2
  int v5; // ecx@2
  int v6; // ecx@3
  int result; // eax@7

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].m_nLineHeight;
    v4 = (int)&v2[v3];
    v5 = v3 - 1;
    if ( v5 >= 0 )
    {
      v6 = v5 + 1;
      do
      {
        v4 -= 16;
        --v6;
        *(_DWORD *)v4 = GlyphLine::vftable;
      }
      while ( v6 );
    }
    if ( a2 & 1 )
      operator delete[](&v2[-1].m_nLineHeight);
    result = (int)&v2[-1].m_nLineHeight;
  }
  else
  {
    this->vfptr = (GlyphLineVtbl *)GlyphLine::vftable;
    if ( a2 & 1 )
      operator delete(this);
    result = (int)v2;
  }
  return result;
}
// 79D4A4: using guessed type int (__thiscall *GlyphLine::vftable[3])(void *, char);

//----- (004726F0) --------------------------------------------------------  // acclient.c:175109
bool __thiscall GlyphList::FindCurrentLine(GlyphList *this, unsigned int i_nStart, unsigned int *o_nLine, unsigned int *o_nPos)
{
  unsigned int v4; // edx@2
  unsigned int v5; // eax@2
  int v6; // edi@3
  int v7; // esi@5
  bool result; // al@8

  if ( i_nStart > this->m_glyphList._num_elements )
  {
    result = 0;
  }
  else
  {
    *o_nLine = 0;
    *o_nPos = 0;
    v4 = this->m_glyphLines.m_num;
    v5 = 0;
    if ( v4 )
    {
      v6 = 0;
      while ( v5 != v4 - 1 )
      {
        v7 = v5 + 1;
        if ( v5 + 1 < v4 && i_nStart < this->m_glyphLines.m_data[v6 + 1].m_nIndex )
          break;
        ++v5;
        ++v6;
        if ( v7 >= v4 )
          return 1;
      }
      *o_nLine = v5;
      *o_nPos = this->m_glyphLines.m_data[v5].m_nIndex;
    }
    result = 1;
  }
  return result;
}

//----- (00472770) --------------------------------------------------------  // acclient.c:175149
char __thiscall GlyphList::FindLineFromY(GlyphList *this, int i_y, unsigned int *o_nLine)
{
  char result; // al@2
  unsigned int v4; // edi@3
  int v5; // esi@3
  unsigned int v6; // edx@3
  char *v7; // eax@4
  int *v8; // eax@7
  GlyphList *v9; // [sp+0h] [bp-4h]@1

  v9 = this;
  if ( i_y > 0 )
  {
    v4 = this->m_glyphLines.m_num;
    v5 = 0;
    v6 = 0;
    if ( v4 )
    {
      v7 = (char *)&this->m_glyphLines.m_data->m_nLineHeight;
      while ( 1 )
      {
        v5 += *(_DWORD *)v7;
        if ( v5 >= i_y )
          break;
        ++v6;
        v7 += 16;
        if ( v6 >= v4 )
          goto LABEL_7;
      }
      *o_nLine = v6;
      result = 1;
    }
    else
    {
LABEL_7:
      i_y = v4 - 1;
      v9 = 0;
      v8 = &i_y;
      if ( (signed int)(v4 - 1) <= 0 )
        v8 = (int *)&v9;
      *o_nLine = *v8;
      result = 1;
    }
  }
  else
  {
    *o_nLine = 0;
    result = 1;
  }
  return result;
}

//----- (004727F0) --------------------------------------------------------  // acclient.c:175202
char __thiscall GlyphList::FindCompleteLineFromY(GlyphList *this, int i_y, unsigned int *o_nLine)
{
  GlyphLine *v3; // esi@1
  unsigned int v4; // ecx@1
  int v5; // edx@1
  signed int v6; // eax@1
  int v7; // esi@2
  char result; // al@5

  v3 = this->m_glyphLines.m_data;
  v4 = this->m_glyphLines.m_num;
  v5 = v3->m_nLineHeight;
  v6 = 1;
  if ( v4 <= 1 )
  {
LABEL_5:
    *o_nLine = v4;
    result = 1;
  }
  else
  {
    v7 = (int)&v3[1].m_nLineHeight;
    while ( 1 )
    {
      v5 += *(_DWORD *)v7;
      if ( v5 > i_y )
        break;
      ++v6;
      v7 += 16;
      if ( v6 >= v4 )
        goto LABEL_5;
    }
    *o_nLine = v6 - 1;
    result = 1;
  }
  return result;
}

//----- (00472840) --------------------------------------------------------  // acclient.c:175241
char __thiscall GlyphList::FindNextLine(GlyphList *this, unsigned int i_nStart, unsigned int *o_nLine, unsigned int *o_nPos)
{
  unsigned int *v4; // ebx@1
  unsigned int *v5; // edi@1
  GlyphList *v6; // esi@1
  unsigned int v7; // eax@2
  unsigned int *v8; // ecx@3
  unsigned int *v9; // eax@3
  bool v10; // cf@3
  unsigned int **v11; // eax@3
  unsigned int v12; // eax@5

  v4 = o_nPos;
  v5 = o_nLine;
  v6 = this;
  if ( GlyphList::FindCurrentLine(this, i_nStart, o_nLine, o_nPos) )
  {
    v7 = v6->m_glyphLines.m_num;
    if ( v7 )
    {
      v8 = (unsigned int *)(v7 - 1);
      v9 = (unsigned int *)(*v5 + 1);
      o_nLine = v9;
      v10 = v8 < v9;
      o_nPos = v8;
      v11 = &o_nPos;
      if ( !v10 )
        v11 = &o_nLine;
      v12 = (unsigned int)*v11;
      *v5 = v12;
      *v4 = v6->m_glyphLines.m_data[v12].m_nIndex;
    }
  }
  return 1;
}

//----- (004728A0) --------------------------------------------------------  // acclient.c:175278
char __thiscall GlyphList::FindPrevLine(GlyphList *this, unsigned int i_nStart, unsigned int *o_nLine, unsigned int *o_nPos)
{
  unsigned int *v4; // ebx@1
  unsigned int *v5; // edi@1
  GlyphList *v6; // esi@1
  bool v7; // sf@3
  unsigned int *v8; // ecx@3
  unsigned int **v9; // eax@3
  unsigned int v10; // eax@5

  v4 = o_nPos;
  v5 = o_nLine;
  v6 = this;
  if ( GlyphList::FindCurrentLine(this, i_nStart, o_nLine, o_nPos) && v6->m_glyphLines.m_num )
  {
    v8 = (unsigned int *)(*v5 - 1);
    v7 = (signed int)v8 < 0;
    o_nPos = 0;
    o_nLine = v8;
    v9 = &o_nPos;
    if ( !v7 )
      v9 = &o_nLine;
    v10 = (unsigned int)*v9;
    *v5 = v10;
    *v4 = v6->m_glyphLines.m_data[v10].m_nIndex;
  }
  return 1;
}

//----- (00472900) --------------------------------------------------------  // acclient.c:175308
char __thiscall GlyphList::GetGlyphLineHeight(GlyphList *this, unsigned int i_nLine, int *o_nHeight)
{
  char result; // al@2

  *o_nHeight = 0;
  if ( i_nLine >= this->m_glyphLines.m_num )
  {
    result = 0;
  }
  else
  {
    *o_nHeight = this->m_glyphLines.m_data[i_nLine].m_nLineHeight;
    result = 1;
  }
  return result;
}

//----- (00472930) --------------------------------------------------------  // acclient.c:175326
char __thiscall GlyphList::GetGlyphLineWidth(GlyphList *this, unsigned int i_nLine, int *o_nWidth)
{
  char result; // al@2

  *o_nWidth = 0;
  if ( i_nLine >= this->m_glyphLines.m_num )
  {
    result = 0;
  }
  else
  {
    *o_nWidth = this->m_glyphLines.m_data[i_nLine].m_nLineWidth;
    result = 1;
  }
  return result;
}

//----- (00472960) --------------------------------------------------------  // acclient.c:175344
char __thiscall List<Glyph>::push_back(List<Glyph> *this, Glyph *val)
{
  List<Glyph> *v2; // edi@1
  void *v3; // esi@1
  int v4; // eax@3
  char result; // al@3
  ListNode<Glyph> *v6; // eax@5
  int v7; // eax@5

  v2 = this;
  v3 = operator new(0x2Cu);
  if ( v3 )
  {
    Glyph::Glyph((Glyph *)v3, val);
    *((_DWORD *)v3 + 9) = 0;
    *((_DWORD *)v3 + 10) = 0;
    if ( v2->_head )
    {
      v6 = v2->_tail;
      v6->next = (ListNode<Glyph> *)v3;
      *((_DWORD *)v3 + 10) = v6;
      v7 = v2->_num_elements + 1;
      v2->_tail = (ListNode<Glyph> *)v3;
      v2->_num_elements = v7;
      result = 1;
    }
    else
    {
      v4 = v2->_num_elements + 1;
      v2->_head = (ListNode<Glyph> *)v3;
      v2->_tail = (ListNode<Glyph> *)v3;
      v2->_num_elements = v4;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004729D0) --------------------------------------------------------  // acclient.c:175387
char __thiscall List<Glyph>::insert(List<Glyph> *this, ListNode<Glyph> *node, Glyph *val)
{
  List<Glyph> *v3; // edi@1
  void *v4; // esi@1
  int v5; // eax@3
  char result; // al@3
  ListNode<Glyph> *v7; // ecx@5

  v3 = this;
  v4 = operator new(0x2Cu);
  if ( v4 )
  {
    Glyph::Glyph((Glyph *)v4, val);
    *((_DWORD *)v4 + 9) = 0;
    *((_DWORD *)v4 + 10) = 0;
    if ( v3->_head )
    {
      *((_DWORD *)v4 + 9) = node;
      *((_DWORD *)v4 + 10) = node->prev;
      v7 = node->prev;
      if ( v7 )
      {
        v7->next = (ListNode<Glyph> *)v4;
        node->prev = (ListNode<Glyph> *)v4;
        ++v3->_num_elements;
        result = 1;
      }
      else
      {
        v3->_head = (ListNode<Glyph> *)v4;
        node->prev = (ListNode<Glyph> *)v4;
        ++v3->_num_elements;
        result = 1;
      }
    }
    else
    {
      v5 = v3->_num_elements + 1;
      v3->_head = (ListNode<Glyph> *)v4;
      v3->_tail = (ListNode<Glyph> *)v4;
      v3->_num_elements = v5;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00472A60) --------------------------------------------------------  // acclient.c:175439
void __thiscall GlyphLine::GlyphLine(GlyphLine *this)
{
  this->vfptr = (GlyphLineVtbl *)GlyphLine::vftable;
  this->m_nIndex = 0;
  this->m_nLineWidth = 0;
  this->m_nLineHeight = 0;
}
// 79D4A4: using guessed type int (__thiscall *GlyphLine::vftable[3])(void *, char);

//----- (00472A80) --------------------------------------------------------  // acclient.c:175449
char __thiscall GlyphList::FindNextWord(GlyphList *this, unsigned int i_nStart, unsigned int *o_nPos)
{
  ListNode<Glyph> *v3; // esi@2
  char v4; // bl@2
  unsigned int i; // edi@2
  char result; // al@10

  if ( i_nStart > this->m_glyphList._num_elements )
  {
    result = 0;
  }
  else
  {
    *o_nPos = i_nStart;
    v3 = this->m_glyphList._head;
    v4 = 0;
    for ( i = 0; v3; v3 = v3->next )
    {
      if ( i >= i_nStart )
      {
        if ( (unsigned __int8)Glyph::IsWhiteSpace(&v3->data) )
        {
          v4 = 1;
        }
        else if ( v4 )
        {
          break;
        }
        ++*o_nPos;
      }
      ++i;
      if ( !v3 )
        break;
    }
    result = 1;
  }
  return result;
}

//----- (00472AE0) --------------------------------------------------------  // acclient.c:175489
char __thiscall GlyphList::FindPrevWord(GlyphList *this, unsigned int i_nStart, unsigned int *o_nPos)
{
  ListNode<Glyph> *v3; // esi@2
  unsigned int v4; // ebp@2
  unsigned int v5; // edi@2
  char i; // bl@2
  char result; // al@10

  if ( i_nStart > this->m_glyphList._num_elements )
  {
    result = 0;
  }
  else
  {
    v3 = this->m_glyphList._head;
    v4 = 0;
    v5 = 0;
    for ( i = 1; v3; v3 = v3->next )
    {
      if ( v5 >= i_nStart )
        break;
      if ( (unsigned __int8)Glyph::IsWhiteSpace(&v3->data) )
      {
        i = 1;
      }
      else if ( i )
      {
        v4 = v5;
        i = 0;
      }
      ++v5;
      if ( !v3 )
        break;
    }
    *o_nPos = v4;
    result = 1;
  }
  return result;
}

//----- (00472B40) --------------------------------------------------------  // acclient.c:175530
bool __thiscall GlyphList::FindPixelsFromPos(GlyphList *this, unsigned int i_nStart, int *o_nPixels)
{
  unsigned int v3; // ebx@1
  GlyphList *v4; // esi@1
  int *v5; // edi@2
  unsigned int v6; // ST00_4@2
  bool result; // al@2
  ListNode<Glyph> *v8; // ecx@3
  unsigned int v9; // edx@3
  unsigned int v10; // esi@4

  v3 = i_nStart;
  v4 = this;
  if ( i_nStart > this->m_glyphList._num_elements )
  {
    result = 0;
  }
  else
  {
    v5 = o_nPixels;
    v6 = i_nStart;
    *o_nPixels = 0;
    i_nStart = 0;
    result = GlyphList::FindCurrentLine(this, v6, (unsigned int *)&o_nPixels, &i_nStart);
    if ( result )
    {
      v8 = v4->m_glyphList._head;
      v9 = 0;
      if ( v8 )
      {
        v10 = i_nStart;
        do
        {
          if ( v9 >= v3 )
            break;
          if ( v9 >= v10 )
            *v5 += v8->data.m_width;
          ++v9;
          if ( !v8 )
            break;
          v8 = v8->next;
        }
        while ( v8 );
      }
    }
  }
  return result;
}

//----- (00472BB0) --------------------------------------------------------  // acclient.c:175580
void __thiscall GlyphList::RemoveTextTag(GlyphList *this, TextTag *_pTag)
{
  ListNode<Glyph> *i; // esi@2

  if ( _pTag )
  {
    for ( i = this->m_glyphList._head; i; i = i->next )
    {
      if ( i->data.m_tag == _pTag )
        Glyph::SetTag(&i->data, 0);
    }
  }
}

//----- (00472BE0) --------------------------------------------------------  // acclient.c:175595
ListIterator<Glyph> *__thiscall GlyphList::GetGlyphIterForIndex(GlyphList *this, ListIterator<Glyph> *result, unsigned int i_nIndex)
{
  List<Glyph> *v3; // edx@1
  ListNode<Glyph> *v4; // ecx@1
  int v5; // eax@1
  ListIterator<Glyph> *v6; // eax@6

  v3 = &this->m_glyphList;
  v4 = this->m_glyphList._head;
  v5 = 0;
  if ( v4 )
  {
    while ( v5 != i_nIndex )
    {
      if ( v4 )
        v4 = v4->next;
      ++v5;
      if ( !v4 )
        goto LABEL_6;
    }
    v6 = result;
    result->_current = v4;
    result->vfptr = (ListIterator<Glyph>Vtbl *)ListIterator<Glyph>::vftable;
    result->_list = v3;
  }
  else
  {
LABEL_6:
    v6 = result;
    result->_current = 0;
    result->vfptr = (ListIterator<Glyph>Vtbl *)ListIterator<Glyph>::vftable;
    result->_list = v3;
  }
  return v6;
}
// 79C13C: using guessed type int (__thiscall *ListIterator<Glyph>::vftable[2])(void *, char);

//----- (00472C30) --------------------------------------------------------  // acclient.c:175633
void __thiscall GlyphList::ChangeExistingGlyphsToNewFont(GlyphList *this, Font *i_pNewFont)
{
  ListNode<Glyph> *i; // esi@1

  this->m_nFirstInvalidPosition = 0;
  for ( i = this->m_glyphList._head; i; i = i->next )
  {
    Glyph::SetFont(&i->data, i_pNewFont);
    if ( !i )
      break;
  }
}

//----- (00472C60) --------------------------------------------------------  // acclient.c:175647
char __thiscall List<Glyph>::remove(List<Glyph> *this, ListNode<Glyph> *node)
{
  List<Glyph> *v2; // edi@1
  ListNode<Glyph> *v3; // ecx@1
  ListNode<Glyph> *v4; // eax@2
  ListNode<Glyph> *v6; // eax@5

  v2 = this;
  v3 = 0;
  if ( !node )
    return 0;
  v4 = v2->_head;
  if ( !v4 )
    return 0;
  if ( node != v4 )
  {
    node->prev->next = node->next;
    v6 = node->next;
    if ( !v6 )
    {
      v2->_tail = node->prev;
      goto LABEL_11;
    }
    v3 = node->prev;
    goto LABEL_9;
  }
  v6 = node->next;
  v2->_head = v6;
  if ( v6 )
  {
LABEL_9:
    v6->prev = v3;
    goto LABEL_11;
  }
  v2->_tail = 0;
LABEL_11:
  Glyph::~Glyph(&node->data);
  operator delete(node);
  --v2->_num_elements;
  return 1;
}

//----- (00472CD0) --------------------------------------------------------  // acclient.c:175690
void __thiscall SmartArray<GlyphLine,1>::Reset(SmartArray<GlyphLine,1> *this)
{
  SmartArray<GlyphLine,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  GlyphLine *v4; // ecx@2
  int v5; // eax@8
  int v6; // ecx@9
  int v7; // edx@9
  int v8; // eax@10

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    v4 = v1->m_data;
    if ( v1->m_data )
    {
      if ( v4[-1].m_nLineHeight )
      {
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(3);
        v1->m_data = 0;
        v1->m_sizeAndDeallocate = 0;
        return;
      }
      operator delete[](&v4[-1].m_nLineHeight);
    }
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v5 = (v2 & 0x7FFFFFFF) - 1;
    if ( v5 >= 0 )
    {
      v6 = v5;
      v7 = v5 + 1;
      do
      {
        v8 = (int)&v1->m_data[v6];
        --v6;
        --v7;
        *(_DWORD *)(v8 + 4) = 0;
        *(_DWORD *)(v8 + 8) = 0;
        *(_DWORD *)(v8 + 12) = 0;
      }
      while ( v7 );
    }
  }
}

//----- (00472D50) --------------------------------------------------------  // acclient.c:175744
char __thiscall SmartArray<GlyphLine,1>::grow(SmartArray<GlyphLine,1> *this, unsigned int i_nSize)
{
  SmartArray<GlyphLine,1> *v2; // esi@1
  unsigned int v3; // edi@1
  void *v5; // eax@5
  int v6; // ebx@6
  int v7; // eax@8
  int v8; // ecx@9
  unsigned int v9; // edi@9
  int v10; // eax@10
  GlyphLine *v11; // ecx@13

  v2 = this;
  v3 = i_nSize;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<GlyphLine,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](16 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator((char *)v5 + 4, 0x10u, i_nSize, (void *(__thiscall *)(void *))GlyphLine::GlyphLine);
      if ( v6 )
      {
        if ( v2->m_data )
        {
          v7 = v2->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = 16 * v7 + v6 + 8;
            v9 = v2->m_num;
            do
            {
              v10 = (int)((char *)v2->m_data + -8 - v6 + v8);
              *(_DWORD *)(v8 - 4) = *(_DWORD *)(v10 + 4);
              *(_DWORD *)v8 = *(_DWORD *)(v10 + 8);
              *(_DWORD *)(v8 + 4) = *(_DWORD *)(v10 + 12);
              v8 -= 16;
              --v9;
            }
            while ( v9 );
            v3 = i_nSize;
          }
          if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            v11 = v2->m_data;
            if ( v2->m_data )
            {
              if ( v11[-1].m_nLineHeight )
              {
                ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(3);
                v2->m_sizeAndDeallocate = v3 | 0x80000000;
                v2->m_data = (GlyphLine *)v6;
                return 1;
              }
              operator delete[](&v11[-1].m_nLineHeight);
            }
          }
        }
        v2->m_data = (GlyphLine *)v6;
        v2->m_sizeAndDeallocate = v3 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (00472E70) --------------------------------------------------------  // acclient.c:175820
unsigned int __thiscall GlyphList::Insert(GlyphList *this, ListIterator<Glyph> *i_iter, Glyph *i_glyph)
{
  ListNode<Glyph> *v3; // eax@1
  ListNode<Glyph> *v4; // edx@2
  TextTag *v5; // edx@3
  List<Glyph> *v6; // ecx@5
  ListNode<Glyph> *v7; // eax@6
  unsigned int result; // eax@7

  v3 = i_iter->_current;
  if ( v3 )
  {
    v4 = v3->prev;
    if ( v4 )
    {
      v5 = v4->data.m_tag;
      if ( v5 == v3->data.m_tag )
        GlyphList::RemoveTextTag(this, v5);
    }
  }
  v6 = i_iter->_list;
  if ( v6 )
  {
    v7 = i_iter->_current;
    if ( v7 )
      result = List<Glyph>::insert(v6, v7, i_glyph) != 0;
    else
      result = List<Glyph>::push_back(v6, i_glyph) != 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00472EE0) --------------------------------------------------------  // acclient.c:175857
bool __thiscall GlyphList::FindXYFromPosition(GlyphList *this, unsigned int i_nStart, int *o_x, int *o_y)
{
  int *v4; // ebx@1
  int *v5; // edi@1
  GlyphList *v6; // esi@1
  bool result; // al@1
  int *v8; // ecx@2
  int v9; // eax@3

  v4 = o_x;
  v5 = o_y;
  v6 = this;
  *o_x = 0;
  *v5 = 0;
  o_x = 0;
  result = GlyphList::FindCurrentLine(this, i_nStart, (unsigned int *)&o_x, (unsigned int *)&o_y);
  if ( result )
  {
    v8 = o_x;
    if ( o_x )
    {
      v9 = 0;
      do
      {
        *v5 += v6->m_glyphLines.m_data[v9].m_nLineHeight;
        ++v9;
        v8 = (int *)((char *)v8 - 1);
      }
      while ( v8 );
    }
    result = GlyphList::FindPixelsFromPos(v6, i_nStart, v4);
  }
  return result;
}

//----- (00472F50) --------------------------------------------------------  // acclient.c:175893
ListIterator<Glyph> *__thiscall GlyphList::GetGlyphIterForLine(GlyphList *this, ListIterator<Glyph> *result, unsigned int i_nLine)
{
  unsigned int v3; // edx@1
  ListIterator<Glyph> *v4; // eax@2
  char *v5; // ecx@3

  v3 = this->m_glyphLines.m_num;
  if ( i_nLine >= v3 )
  {
    v4 = result;
    v5 = (char *)&this->m_glyphList;
    if ( v3 )
    {
      result->_current = 0;
      result->vfptr = (ListIterator<Glyph>Vtbl *)ListIterator<Glyph>::vftable;
      result->_list = (List<Glyph> *)v5;
    }
    else
    {
      result->_current = (ListNode<Glyph> *)*((_DWORD *)v5 + 1);
      result->vfptr = (ListIterator<Glyph>Vtbl *)ListIterator<Glyph>::vftable;
      result->_list = (List<Glyph> *)v5;
    }
  }
  else
  {
    GlyphList::GetGlyphIterForIndex(this, result, this->m_glyphLines.m_data[i_nLine].m_nIndex);
    v4 = result;
  }
  return v4;
}
// 79C13C: using guessed type int (__thiscall *ListIterator<Glyph>::vftable[2])(void *, char);

//----- (00472FB0) --------------------------------------------------------  // acclient.c:175927
void __thiscall List<Glyph>::flush(List<Glyph> *this)
{
  List<Glyph> *v1; // edi@1
  int v2; // esi@3
  int v3; // eax@4
  Glyph v4; // [sp+Ch] [bp-24h]@3

  v1 = this;
  while ( v1->_head )
  {
    Glyph::Glyph(&v4);
    v2 = (int)v1->_head;
    if ( v2 )
    {
      v3 = *(_DWORD *)(v2 + 36);
      v1->_head = (ListNode<Glyph> *)v3;
      if ( v3 )
        *(_DWORD *)(v3 + 40) = 0;
      else
        v1->_tail = 0;
      Glyph::operator=((int)&v4, v2);
      if ( v2 )
      {
        Glyph::~Glyph((Glyph *)v2);
        operator delete((void *)v2);
      }
      --v1->_num_elements;
    }
    Glyph::~Glyph(&v4);
  }
}

//----- (00473020) --------------------------------------------------------  // acclient.c:175960
void __thiscall GlyphList::Flush(GlyphList *this)
{
  GlyphList *v1; // esi@1

  v1 = this;
  List<Glyph>::flush(&this->m_glyphList);
  SmartArray<GlyphLine,1>::Reset(&v1->m_glyphLines);
  v1->m_cxLastRecalcWidth = -1;
  v1->m_nFirstInvalidPosition = 0;
  v1->m_bOneLine = 0;
}

//----- (00473050) --------------------------------------------------------  // acclient.c:175973
unsigned int __thiscall GlyphList::Insert(GlyphList *this, unsigned int i_nPos, Glyph *i_glyph)
{
  GlyphList *v3; // esi@1
  unsigned int result; // eax@4
  ListIterator<Glyph> iter; // [sp+4h] [bp-Ch]@4

  v3 = this;
  if ( i_nPos > this->m_glyphList._num_elements )
  {
    result = 0;
  }
  else
  {
    if ( i_nPos < this->m_nFirstInvalidPosition )
      this->m_nFirstInvalidPosition = i_nPos;
    GlyphList::GetGlyphIterForIndex(this, &iter, i_nPos);
    result = GlyphList::Insert(v3, &iter, i_glyph);
  }
  return result;
}

//----- (004730A0) --------------------------------------------------------  // acclient.c:175995
unsigned int __thiscall GlyphList::Delete(GlyphList *this, unsigned int i_nStart, unsigned int i_nEnd)
{
  GlyphList *v3; // esi@1
  unsigned int v4; // eax@1
  unsigned int *v5; // ecx@1
  unsigned int v6; // edx@3
  bool v7; // sf@3
  unsigned __int8 v8; // of@3
  unsigned int *v9; // eax@3
  bool v10; // cf@5
  unsigned int v11; // eax@5
  unsigned int v12; // ecx@7
  unsigned int result; // eax@8
  List<Glyph> *v14; // ebp@9
  ListNode<Glyph> *v15; // edi@9
  TextTag *v16; // ebx@13
  ListNode<Glyph> *i; // esi@14
  ListNode<Glyph> *v18; // eax@19
  unsigned int nDeleted; // [sp+4h] [bp-Ch]@7
  GlyphList *v20; // [sp+8h] [bp-8h]@1
  unsigned int nCurrent; // [sp+Ch] [bp-4h]@1

  v3 = this;
  v4 = this->m_glyphList._num_elements;
  nCurrent = v4 - 1;
  v20 = this;
  v5 = &nCurrent;
  if ( (signed int)(v4 - 1) >= (signed int)i_nStart )
    v5 = &i_nStart;
  v6 = *v5;
  nCurrent = v4;
  v8 = __OFSUB__(v4, i_nEnd);
  v7 = ((v4 - i_nEnd) & 0x80000000) != 0;
  i_nStart = v6;
  v9 = &nCurrent;
  if ( !(v7 ^ v8) )
    v9 = &i_nEnd;
  v10 = v6 < v3->m_nFirstInvalidPosition;
  v11 = *v9;
  i_nEnd = v11;
  if ( v10 )
    v3->m_nFirstInvalidPosition = v6;
  v12 = 0;
  nDeleted = 0;
  if ( v6 < v11 )
  {
    v14 = &v3->m_glyphList;
    v15 = v3->m_glyphList._head;
    while ( 1 )
    {
      nCurrent = v12;
      if ( !v15 || v12 >= v11 )
        break;
      if ( v12 < v6 )
      {
        v15 = v15->next;
        ++v12;
      }
      else
      {
        v16 = v15->data.m_tag;
        if ( v16 )
        {
          for ( i = v3->m_glyphList._head; i; i = i->next )
          {
            if ( i->data.m_tag == v16 )
              Glyph::SetTag(&i->data, 0);
          }
          v3 = v20;
        }
        v18 = v15;
        v15 = v15->next;
        List<Glyph>::remove(v14, v18);
        v6 = i_nStart;
        ++nDeleted;
        v11 = i_nEnd;
        v12 = nCurrent + 1;
      }
    }
    result = nDeleted;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00473190) --------------------------------------------------------  // acclient.c:176084
unsigned int __thiscall GlyphList::AddText(GlyphList *this, unsigned int i_nPos, SmartArray<Glyph,1> *i_glyphs)
{
  GlyphList *v3; // ebx@1
  unsigned int v4; // edi@1
  SmartArray<Glyph,1> *v5; // esi@3
  ListNode<Glyph> *v6; // ebp@4
  Glyph *v7; // edi@5
  ListNode<Glyph> *v8; // eax@6
  TextTag *v9; // ebx@7
  ListNode<Glyph> *i; // esi@9
  char v11; // al@17
  int v12; // eax@20
  bool v13; // cf@20
  unsigned int v14; // ecx@22
  unsigned int v15; // eax@22
  unsigned int v16; // eax@23
  unsigned int v17; // eax@26
  GlyphList *v19; // [sp+10h] [bp-20h]@1
  unsigned int nCursor; // [sp+14h] [bp-1Ch]@1
  unsigned int nTotalAdded; // [sp+18h] [bp-18h]@1
  unsigned int nTotalDeleted; // [sp+1Ch] [bp-14h]@1
  unsigned int nIndex; // [sp+20h] [bp-10h]@3
  ListIterator<Glyph> iter; // [sp+24h] [bp-Ch]@3
  unsigned int i_nPosa; // [sp+34h] [bp+4h]@4

  v3 = this;
  v4 = i_nPos;
  v19 = this;
  nCursor = i_nPos;
  nTotalDeleted = 0;
  nTotalAdded = 0;
  if ( i_nPos < this->m_nFirstInvalidPosition )
    this->m_nFirstInvalidPosition = i_nPos;
  GlyphList::GetGlyphIterForIndex(this, &iter, i_nPos);
  v5 = i_glyphs;
  nIndex = 0;
  if ( i_glyphs->m_num )
  {
    i_nPosa = 0;
    v6 = iter._current;
    do
    {
      v7 = &v5->m_data[i_nPosa];
      if ( v6 )
      {
        v8 = v6->prev;
        if ( v8 )
        {
          v9 = v8->data.m_tag;
          if ( v9 == v6->data.m_tag && v9 )
          {
            for ( i = v19->m_glyphList._head; i; i = i->next )
            {
              if ( i->data.m_tag == v9 )
                Glyph::SetTag(&i->data, 0);
            }
            v5 = i_glyphs;
          }
          v3 = v19;
        }
      }
      if ( iter._list )
      {
        if ( v6 )
          v11 = List<Glyph>::insert(iter._list, v6, v7);
        else
          v11 = List<Glyph>::push_back(iter._list, v7);
      }
      else
      {
        v11 = 0;
      }
      v12 = v11 != 0;
      nTotalAdded += v12;
      nCursor += v12;
      v13 = nIndex++ + 1 < v5->m_num;
      ++i_nPosa;
    }
    while ( v13 );
    v4 = nCursor;
  }
  v14 = v3->m_nMaxCharacters;
  v15 = v3->m_glyphList._num_elements;
  if ( v15 > v14 )
  {
    v16 = v15 - v14;
    if ( v16 > v5->m_num )
      v16 = v5->m_num;
    if ( v3->m_bTrimFromTop )
      v17 = GlyphList::Delete(v3, 0, v16);
    else
      v17 = GlyphList::Delete(v3, v4 - v16, v4);
    nTotalDeleted = v17;
  }
  return nTotalAdded - nTotalDeleted;
}

//----- (004732D0) --------------------------------------------------------  // acclient.c:176182
char __thiscall GlyphList::FindPosFromLineAndPixels(GlyphList *this, unsigned int i_nLine, unsigned int i_nPixels, bool i_bFindNearestPos, unsigned int *o_nPos)
{
  GlyphList *v5; // esi@1
  unsigned int v6; // edi@1
  int v7; // ebp@2
  unsigned int v8; // ebx@2
  unsigned int v9; // ecx@2
  bool v10; // sf@2
  unsigned __int8 v11; // of@2
  unsigned int *v12; // ecx@2
  unsigned int v13; // ecx@4
  unsigned int v14; // ecx@5
  int v15; // eax@7
  unsigned int v16; // edx@7
  unsigned int v17; // ST00_4@8
  char result; // al@9
  ListNode<Glyph> *v19; // esi@11
  char v20; // cl@14
  unsigned int v21; // ecx@17
  unsigned int nNextLine; // [sp+10h] [bp-10h]@2
  ListIterator<Glyph> iterBegin; // [sp+14h] [bp-Ch]@11

  v5 = this;
  v6 = i_nLine;
  if ( i_nLine >= this->m_glyphLines.m_num )
  {
    result = 0;
  }
  else
  {
    v7 = i_nPixels;
    v8 = this->m_glyphLines.m_data[i_nLine].m_nIndex;
    *o_nPos = v8;
    v9 = this->m_glyphLines.m_num - 1;
    i_nLine = v9;
    v11 = __OFSUB__(v9, v6 + 1);
    v10 = ((v9 - (v6 + 1)) & 0x80000000) != 0;
    nNextLine = v6 + 1;
    v12 = &i_nLine;
    if ( !(v10 ^ v11) )
      v12 = &nNextLine;
    v13 = *v12;
    nNextLine = v13;
    if ( v13 == v6 )
      v14 = v5->m_glyphList._num_elements;
    else
      v14 = v5->m_glyphLines.m_data[v13].m_nIndex;
    v15 = (int)&v5->m_glyphLines.m_data[v6];
    v16 = *(_DWORD *)(v15 + 8);
    i_nLine = v14;
    if ( i_nPixels <= v16 )
    {
      nNextLine = v8;
      GlyphList::GetGlyphIterForLine(v5, &iterBegin, v6);
      v19 = iterBegin._current;
      if ( iterBegin._current )
      {
        i_nPixels = v8 + 1;
        do
        {
          if ( v8 >= i_nLine )
            break;
          v20 = Glyph::IsNewLine(&v19->data);
          if ( v7 <= v19->data.m_width / ((i_bFindNearestPos != 0) + 1) || v20 && i_nPixels == i_nLine )
            break;
          v21 = i_nPixels;
          v7 -= v19->data.m_width;
          v8 = nNextLine + 1;
          ++*o_nPos;
          v19 = v19->next;
          nNextLine = v8;
          i_nPixels = v21 + 1;
        }
        while ( v19 );
      }
      result = 1;
    }
    else
    {
      v17 = *(_DWORD *)(v15 + 4);
      *(_DWORD *)&i_bFindNearestPos = 0;
      GlyphList::FindNextLine(v5, v17, &nNextLine, (unsigned int *)&i_bFindNearestPos);
      if ( v6 == v5->m_glyphLines.m_num - 1 )
      {
        *o_nPos = v5->m_glyphList._num_elements;
        result = 1;
      }
      else
      {
        *o_nPos = i_bFindNearestPos - 1;
        result = 1;
      }
    }
  }
  return result;
}

//----- (00473430) --------------------------------------------------------  // acclient.c:176280
char __thiscall GlyphList::InqGlyph(GlyphList *this, unsigned int i_pos, Glyph *o_glyph)
{
  GlyphList *v3; // edx@1
  int v4; // ecx@1
  char result; // al@1
  int v6; // edx@3

  v3 = this;
  v4 = (int)this->m_glyphList._head;
  result = 0;
  if ( v4 && i_pos < v3->m_glyphList._num_elements )
  {
    v6 = 0;
    while ( v6 != i_pos )
    {
      if ( v4 )
        v4 = *(_DWORD *)(v4 + 36);
      ++v6;
      if ( !v4 )
        return result;
    }
    if ( v4 )
    {
      Glyph::operator=((int)o_glyph, v4);
      result = 1;
    }
  }
  return result;
}

//----- (00473470) --------------------------------------------------------  // acclient.c:176311
List<Glyph> *__thiscall List<Glyph>::scalar_deleting_destructor(List<Glyph> *this, unsigned int a2)
{
  List<Glyph> *v2; // esi@1

  v2 = this;
  this->vfptr = (List<Glyph>Vtbl *)List<Glyph>::vftable;
  List<Glyph>::flush(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79D4A8: using guessed type int (__thiscall *List<Glyph>::vftable[2])(void *, char);

//----- (004734A0) --------------------------------------------------------  // acclient.c:176325
void __thiscall GlyphList::GlyphList(GlyphList *this)
{
  this->vfptr = (GlyphListVtbl *)&GlyphList::vftable;
  this->m_glyphList.vfptr = (List<Glyph>Vtbl *)List<Glyph>::vftable;
  this->m_glyphList._head = 0;
  this->m_glyphList._tail = 0;
  this->m_glyphList._num_elements = 0;
  this->m_glyphLines.m_data = 0;
  this->m_glyphLines.m_sizeAndDeallocate = 0;
  this->m_glyphLines.m_num = 0;
  this->m_nMaxCharacters = 0xFFFF;
  this->m_bTrimFromTop = 0;
  this->m_cxLastRecalcWidth = -1;
  this->m_nFirstInvalidPosition = 0;
  this->m_bOneLine = 0;
}
// 79D4A8: using guessed type int (__thiscall *List<Glyph>::vftable[2])(void *, char);
// 79D4AC: using guessed type int (__thiscall *GlyphList::vftable)(void *, char);

//----- (004734E0) --------------------------------------------------------  // acclient.c:176345
void __thiscall GlyphList::~GlyphList(GlyphList *this)
{
  GlyphList *v1; // esi@1
  List<Glyph> *v2; // ebx@1
  int v3; // edi@1
  int v4; // ecx@2

  v1 = this;
  v2 = &this->m_glyphList;
  this->vfptr = (GlyphListVtbl *)&GlyphList::vftable;
  List<Glyph>::flush(&this->m_glyphList);
  v3 = (int)&v1->m_glyphLines;
  SmartArray<GlyphLine,1>::Reset(&v1->m_glyphLines);
  v1->m_cxLastRecalcWidth = -1;
  v1->m_nFirstInvalidPosition = 0;
  v1->m_bOneLine = 0;
  if ( (v1->m_glyphLines.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v4 = *(_DWORD *)v3;
    if ( *(_DWORD *)v3 )
    {
      if ( *(_DWORD *)(v4 - 4) )
      {
        (**(void (__stdcall ***)(_DWORD))v4)(3);
        v2->vfptr = (List<Glyph>Vtbl *)List<Glyph>::vftable;
        List<Glyph>::flush(v2);
        return;
      }
      operator delete[]((void *)(v4 - 4));
    }
  }
  v2->vfptr = (List<Glyph>Vtbl *)List<Glyph>::vftable;
  List<Glyph>::flush(v2);
}
// 79D4A8: using guessed type int (__thiscall *List<Glyph>::vftable[2])(void *, char);
// 79D4AC: using guessed type int (__thiscall *GlyphList::vftable)(void *, char);

//----- (00473560) --------------------------------------------------------  // acclient.c:176383
char __thiscall GlyphList::InqText(GlyphList *this, unsigned int i_nStart, unsigned int i_nEnd, bool i_bIncludeHidden, PStringBase<unsigned short> *o_str)
{
  PStringBase<unsigned short> *v5; // esi@1
  PSRefBufferCharData<unsigned short> *v6; // eax@1
  GlyphList *v7; // ebp@1
  int v8; // edi@2
  volatile LONG *v9; // ST0C_4@5
  PStringBase<unsigned short> *v10; // eax@6
  void *v11; // ecx@6
  unsigned int v12; // edx@8
  bool v13; // sf@8
  unsigned __int8 v14; // of@8
  unsigned int *v15; // eax@8
  void *v16; // ebp@10
  unsigned int v17; // eax@10
  int v18; // edi@10
  int v19; // ebx@13
  PStringBase<unsigned short> *v20; // edi@16
  PStringBase<unsigned short> *v21; // edi@20
  PStringBase<unsigned short> v22; // eax@24
  unsigned int v23; // ebp@24
  int v24; // ecx@24
  int v25; // edi@27
  int v26; // esi@37
  unsigned int nCurrent; // [sp+18h] [bp-10h]@10
  PStringBase<unsigned short> **iterBegin_4; // [sp+20h] [bp-8h]@10

  v5 = o_str;
  v6 = o_str->m_charbuffer;
  v7 = this;
  if ( (wchar_t *)o_str->m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
  {
    v8 = (int)&v6[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v6[-1].m_data[8]) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    v9 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    v5->m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v9);
  }
  v10 = (PStringBase<unsigned short> *)v7->m_glyphList._num_elements;
  o_str = (PStringBase<unsigned short> *)((char *)v10 - 1);
  v11 = &o_str;
  if ( (signed int)((char *)&v10[-1].m_charbuffer + 3) >= (signed int)i_nStart )
    v11 = &i_nStart;
  v12 = *(_DWORD *)v11;
  o_str = v10;
  v14 = __OFSUB__(v10, i_nEnd);
  v13 = (signed int)((char *)v10 - i_nEnd) < 0;
  i_nStart = v12;
  v15 = (unsigned int *)&o_str;
  if ( !(v13 ^ v14) )
    v15 = &i_nEnd;
  v16 = v7->m_glyphList._head;
  i_nEnd = *v15;
  v17 = 0;
  v18 = 0;
  nCurrent = 0;
  iterBegin_4 = (PStringBase<unsigned short> **)v16;
  if ( v16 )
  {
    do
    {
      if ( v17 >= i_nEnd )
        break;
      if ( v17 >= i_nStart )
      {
        v19 = *((_DWORD *)v16 + 8);
        if ( i_bIncludeHidden && v19 != v18 )
        {
          if ( v18 )
          {
            o_str = (PStringBase<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
            InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
            (*(void (__thiscall **)(int, PStringBase<unsigned short> **))(*(_DWORD *)v18 + 12))(v18, &o_str);
            PStringBase<unsigned short>::sprintf_append(v5, L"%ls", o_str);
            v20 = o_str - 5;
            if ( !InterlockedDecrement((volatile LONG *)&o_str[-4]) )
            {
              if ( v20 )
                (*(void (__thiscall **)(PStringBase<unsigned short> *, signed int))&v20->m_charbuffer->m_data[0])(
                  v20,
                  1);
            }
          }
          if ( v19 )
          {
            o_str = (PStringBase<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
            InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
            (*(void (__thiscall **)(int, PStringBase<unsigned short> **))(*(_DWORD *)v19 + 16))(v19, &o_str);
            PStringBase<unsigned short>::sprintf_append(v5, L"%ls", o_str);
            v21 = o_str - 5;
            if ( !InterlockedDecrement((volatile LONG *)&o_str[-4]) )
            {
              if ( v21 )
                (*(void (__thiscall **)(PStringBase<unsigned short> *, signed int))&v21->m_charbuffer->m_data[0])(
                  v21,
                  1);
            }
          }
        }
        o_str = (PStringBase<unsigned short> *)*(_WORD *)iterBegin_4;
        if ( (_WORD)o_str )
        {
          v22.m_charbuffer = v5->m_charbuffer;
          v23 = *(_DWORD *)&v5->m_charbuffer[-1].m_data[14];
          v24 = v23 + 1;
          if ( *(_DWORD *)&v5->m_charbuffer[-1].m_data[8] != 1
            || (unsigned int)v24 > *(_DWORD *)&v22.m_charbuffer[-1].m_data[10] )
          {
            v25 = (int)&v22.m_charbuffer[-1].m_data[6];
            PStringBase<unsigned short>::allocate_ref_buffer(v5, v23);
            _wcscpy(v5->m_charbuffer->m_data, (const wchar_t *)(v25 + 20));
            if ( !InterlockedDecrement((volatile LONG *)(v25 + 4)) && v25 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))v25)(v25, 1);
          }
          else
          {
            *(_DWORD *)&v22.m_charbuffer[-1].m_data[14] = v24;
            *(_DWORD *)&v5->m_charbuffer[-1].m_data[12] = -1;
          }
          _wcsncpy((wchar_t *)v5->m_charbuffer + v23 - 1, (const wchar_t *)&o_str, 1u);
          v5->m_charbuffer->m_data[*(_DWORD *)&v5->m_charbuffer[-1].m_data[14] - 1] = 0;
        }
        v16 = iterBegin_4;
        v17 = nCurrent;
        v18 = v19;
      }
      if ( v16 )
        iterBegin_4 = (PStringBase<unsigned short> **)*((_DWORD *)v16 + 9);
      v16 = iterBegin_4;
      ++v17;
      nCurrent = v17;
    }
    while ( iterBegin_4 );
  }
  if ( i_bIncludeHidden )
  {
    if ( v18 )
    {
      *(_DWORD *)&i_bIncludeHidden = PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      (*(void (__thiscall **)(int, bool *))(*(_DWORD *)v18 + 12))(v18, &i_bIncludeHidden);
      PStringBase<unsigned short>::sprintf_append(v5, L"%ls", i_bIncludeHidden);
      v26 = i_bIncludeHidden - 20;
      if ( !InterlockedDecrement((volatile LONG *)(i_bIncludeHidden - 20 + 4)) )
      {
        if ( v26 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
      }
    }
  }
  return 1;
}

//----- (00473800) --------------------------------------------------------  // acclient.c:176538
char __thiscall GlyphList::Recalculate(GlyphList *this, int i_nMarginWidth, bool i_bOneLine, int *o_nWidth, int *o_nHeight)
{
  unsigned int v5; // edx@4
  int v6; // edx@7
  unsigned int v7; // edi@7
  GlyphLine *v8; // ecx@8
  unsigned int v9; // esi@8
  int v10; // ebx@8
  int v11; // ecx@8
  int *v14; // esi@8
  unsigned int v15; // edi@11
  int v16; // ebx@11
  ListNode<Glyph> *v17; // ebp@11
  ListNode<Glyph> *v18; // eax@12
  int v19; // edi@18
  int v20; // esi@19
  unsigned int v21; // eax@20
  char *v22; // edx@20
  unsigned int v23; // eax@21
  int v24; // ecx@22
  int v25; // eax@22
  int v26; // ebx@22
  int v27; // eax@22
  int v28; // eax@22
  int v29; // esi@26
  ListNode<Glyph> *v30; // edi@26
  int v31; // ebp@39
  int v32; // esi@39
  Glyph *v33; // esi@45
  int v34; // ebp@45
  int v35; // eax@49
  unsigned int v36; // edx@50
  int v40; // eax@58
  int v41; // ecx@58
  int *v42; // ecx@59
  int v43; // edx@61
  int v44; // ecx@61
  int v45; // eax@62
  int *v46; // eax@62
  char *v47; // esi@66
  unsigned int v48; // edx@66
  int v49; // edx@67
  int v51; // eax@75
  int v52; // ecx@75
  int *v53; // ecx@76
  unsigned int v54; // ebx@80
  unsigned int v55; // ecx@80
  int v56; // eax@80
  unsigned int v57; // edx@81
  int v59; // edx@89
  int v60; // eax@89
  bool bWrappable; // [sp+12h] [bp-4Ah]@11
  bool bMustWrap; // [sp+13h] [bp-49h]@11
  GlyphList *v64; // [sp+14h] [bp-48h]@1
  int nAccumulatedWidth; // [sp+18h] [bp-44h]@11
  unsigned int nLineToStart; // [sp+1Ch] [bp-40h]@4
  int nCurrentWidth; // [sp+20h] [bp-3Ch]@11
  int nWrappableHeight; // [sp+24h] [bp-38h]@11
  int nCurrentHeight; // [sp+28h] [bp-34h]@11
  int nWidthOfThisLine; // [sp+2Ch] [bp-30h]@12
  Glyph *pLastEndOfLineGlyph; // [sp+30h] [bp-2Ch]@11
  int nLastWrappable; // [sp+34h] [bp-28h]@11
  unsigned int nCurrentGlyph; // [sp+38h] [bp-24h]@8
  int nHeight; // [sp+3Ch] [bp-20h]@12
  ListIterator<Glyph> iterBegin; // [sp+40h] [bp-1Ch]@17
  GlyphLine curLine; // [sp+4Ch] [bp-10h]@11

  v64 = this;
  *o_nWidth = 0;
  *o_nHeight = 0;
  if ( i_nMarginWidth != this->m_cxLastRecalcWidth || i_bOneLine != this->m_bOneLine )
  {
    this->m_nFirstInvalidPosition = 0;
    this->m_cxLastRecalcWidth = i_nMarginWidth;
    this->m_bOneLine = i_bOneLine;
  }
  v5 = this->m_nFirstInvalidPosition;
  nLineToStart = 0;
  if ( v5 )
  {
    GlyphList::FindPrevLine(this, v5, &nLineToStart, &this->m_nFirstInvalidPosition);
    this = v64;
  }
  if ( nLineToStart > 0 )
  {
    v6 = 0;
    v7 = nLineToStart;
    do
    {
      v8 = this->m_glyphLines.m_data;
      v9 = v8[v6].m_nLineWidth;
      v10 = *o_nWidth;
      v11 = (int)&v8[v6];
      nCurrentGlyph = v9;
      _OF = __OFSUB__(v10, v9);
      _SF = ((v10 - v9) & 0x80000000) != 0;
      v14 = (int *)&nCurrentGlyph;
      if ( !(_SF ^ _OF) )
        v14 = o_nWidth;
      *o_nWidth = *v14;
      ++v6;
      --v7;
      *o_nHeight += *(_DWORD *)(v11 + 12);
      this = v64;
    }
    while ( v7 );
  }
  v15 = this->m_glyphLines.m_num;
  v16 = 0;
  nCurrentGlyph = this->m_nFirstInvalidPosition;
  curLine.m_nIndex = nCurrentGlyph;
  v17 = 0;
  nCurrentWidth = 0;
  nCurrentHeight = 0;
  nAccumulatedWidth = 0;
  nLastWrappable = 0;
  nWrappableHeight = 0;
  bWrappable = 0;
  bMustWrap = 0;
  pLastEndOfLineGlyph = 0;
  if ( nLineToStart < v15 )
  {
    nHeight = this->m_glyphLines.m_data[nLineToStart].m_nIndex;
    v18 = this->m_glyphList._head;
    nWidthOfThisLine = 0;
    if ( v18 )
    {
      while ( nWidthOfThisLine != nHeight )
      {
        if ( v18 )
          v18 = v18->next;
        ++nWidthOfThisLine;
        if ( !v18 )
          goto LABEL_17;
      }
      goto LABEL_34;
    }
LABEL_17:
    iterBegin._current = 0;
    goto LABEL_18;
  }
  if ( v15 )
    goto LABEL_17;
  v18 = this->m_glyphList._head;
LABEL_34:
  iterBegin._current = v18;
LABEL_18:
  v19 = v15 - 1;
  if ( v19 >= (signed int)nLineToStart )
  {
    v20 = 16 * v19;
    do
    {
      v21 = this->m_glyphLines.m_num;
      v22 = (char *)&this->m_glyphLines;
      if ( v19 < v21 )
      {
        v23 = v21 - 1;
        this->m_glyphLines.m_num = v23;
        if ( v19 != v23 )
        {
          v24 = *(_DWORD *)v22;
          v25 = 16 * v23;
          v26 = *(_DWORD *)(v25 + *(_DWORD *)v22 + 4);
          v27 = *(_DWORD *)v22 + v25;
          *(_DWORD *)(v24 + v20 + 4) = v26;
          *(_DWORD *)(v24 + v20 + 8) = *(_DWORD *)(v27 + 8);
          v16 = nCurrentHeight;
          *(_DWORD *)(v24 + v20 + 12) = *(_DWORD *)(v27 + 12);
          v28 = *(_DWORD *)v22 + 16 * *((_DWORD *)v22 + 2);
          *(_DWORD *)(v28 + 4) = 0;
          *(_DWORD *)(v28 + 8) = 0;
          *(_DWORD *)(v28 + 12) = 0;
        }
        this = v64;
      }
      --v19;
      v20 -= 16;
    }
    while ( v19 >= (signed int)nLineToStart );
  }
  if ( iterBegin._current )
  {
    v29 = nCurrentGlyph;
    v30 = iterBegin._current;
    do
    {
      nWidthOfThisLine = v30->data.m_width;
      if ( !i_bOneLine )
      {
        if ( LinebreakUtils::CanBreakLineAt(&v17->data, &v30->data) )
        {
          nLastWrappable = v29;
          pLastEndOfLineGlyph = (Glyph *)v17;
          nWrappableHeight = v16;
          nAccumulatedWidth = 0;
          bWrappable = 1;
          if ( v17 && (unsigned __int8)Glyph::IsNewLine(&v17->data) )
            bMustWrap = 1;
        }
        else if ( !(unsigned __int8)Glyph::IsWhiteSpace(&v30->data)
               && !(unsigned __int8)Glyph::IsNewLine(&v30->data)
               && nAccumulatedWidth + nWidthOfThisLine > i_nMarginWidth )
        {
          nLastWrappable = v29;
          pLastEndOfLineGlyph = (Glyph *)v17;
          nWrappableHeight = v16;
          nAccumulatedWidth = 0;
          bWrappable = 1;
        }
      }
      v31 = nWidthOfThisLine + nCurrentWidth;
      nCurrentWidth = v31;
      nAccumulatedWidth += nWidthOfThisLine;
      v32 = v31;
      if ( (unsigned __int8)Glyph::IsWhiteSpace(&v30->data) || (unsigned __int8)Glyph::IsNewLine(&v30->data) )
        v32 = v31 - nWidthOfThisLine;
      if ( bMustWrap || bWrappable && v32 > i_nMarginWidth )
      {
        v33 = pLastEndOfLineGlyph;
        v34 = v31 - nAccumulatedWidth;
        nWidthOfThisLine = v34;
        if ( pLastEndOfLineGlyph
          && ((unsigned __int8)Glyph::IsWhiteSpace(pLastEndOfLineGlyph) || (unsigned __int8)Glyph::IsNewLine(v33)) )
        {
          v34 -= v33->m_width;
          nWidthOfThisLine = v34;
        }
        v35 = v64->m_glyphLines.m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( v64->m_glyphLines.m_num < v35 )
          goto LABEL_94;
        v36 = v35 + 1;
        if ( (unsigned int)(v35 + 1) > 8 )
        {
          if ( v36 <= 0x4000 )
          {
            nHeight = v35 + 1;
            __asm { bsr     this, [esp+5Ch+nHeight] }
            if ( v36 > 1 << _EAX )
              v36 = 2 * (1 << _EAX);
          }
          else if ( v36 & 0x3FFF )
          {
            v36 += 0x4000 - (v36 & 0x3FFF);
          }
        }
        else
        {
          v36 = 8;
        }
        if ( SmartArray<GlyphLine,1>::grow(&v64->m_glyphLines, v36) )
        {
LABEL_94:
          v40 = (int)&v64->m_glyphLines.m_data[v64->m_glyphLines.m_num];
          v41 = nWrappableHeight;
          *(_DWORD *)(v40 + 4) = curLine.m_nIndex;
          *(_DWORD *)(v40 + 8) = v34;
          *(_DWORD *)(v40 + 12) = v41;
          ++v64->m_glyphLines.m_num;
        }
        v42 = &nWidthOfThisLine;
        if ( *o_nWidth >= v34 )
          v42 = o_nWidth;
        v43 = *v42;
        v44 = nWrappableHeight;
        v30 = iterBegin._current;
        *o_nWidth = v43;
        *o_nHeight += v44;
        v16 = 0;
        curLine.m_nIndex = nLastWrappable;
        nCurrentWidth = nAccumulatedWidth;
        nCurrentHeight = 0;
        bWrappable = 0;
        bMustWrap = 0;
      }
      v45 = v30->data.m_height;
      nHeight = v45;
      _OF = __OFSUB__(v45, v16);
      _SF = v45 - v16 < 0;
      v46 = &nCurrentHeight;
      if ( !(_SF ^ _OF) )
        v46 = &nHeight;
      v16 = *v46;
      v17 = v30;
      v30 = v30->next;
      v29 = nCurrentGlyph + 1;
      nCurrentHeight = *v46;
      ++nCurrentGlyph;
      iterBegin._current = v30;
    }
    while ( v30 );
    this = v64;
  }
  v47 = (char *)&this->m_glyphLines;
  v48 = this->m_glyphLines.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_glyphLines.m_num < v48 )
    goto LABEL_95;
  v49 = v48 + 1;
  if ( (unsigned int)v49 > 8 )
  {
    if ( (unsigned int)v49 <= 0x4000 )
    {
      nHeight = v49;
      __asm { bsr     this, [esp+5Ch+nHeight] }
      if ( v49 > (unsigned int)(1 << _EAX) )
        v49 = 2 * (1 << _EAX);
    }
    else if ( v49 & 0x3FFF )
    {
      v49 += 0x4000 - (v49 & 0x3FFF);
    }
  }
  else
  {
    v49 = 8;
  }
  if ( SmartArray<GlyphLine,1>::grow((SmartArray<GlyphLine,1> *)v47, v49) )
  {
LABEL_95:
    v51 = *(_DWORD *)v47 + 16 * *((_DWORD *)v47 + 2);
    v52 = nCurrentWidth;
    *(_DWORD *)(v51 + 4) = curLine.m_nIndex;
    *(_DWORD *)(v51 + 8) = v52;
    *(_DWORD *)(v51 + 12) = v16;
    ++*((_DWORD *)v47 + 2);
  }
  v53 = &nCurrentWidth;
  if ( *o_nWidth >= nCurrentWidth )
    v53 = o_nWidth;
  *o_nWidth = *v53;
  *o_nHeight += v16;
  if ( v17 && (unsigned __int8)Glyph::IsNewLine(&v17->data) )
  {
    v54 = v64->m_glyphList._num_elements;
    v55 = v64->m_glyphLines.m_num;
    v56 = v64->m_glyphLines.m_sizeAndDeallocate & 0x7FFFFFFF;
    curLine.m_nLineHeight = v17->data.m_height;
    if ( v55 < v56 )
      goto LABEL_96;
    v57 = v56 + 1;
    if ( (unsigned int)(v56 + 1) > 8 )
    {
      if ( v57 <= 0x4000 )
      {
        nHeight = v56 + 1;
        __asm { bsr     this, [esp+5Ch+nHeight] }
        if ( v57 > 1 << _EAX )
          v57 = 2 * (1 << _EAX);
      }
      else if ( v57 & 0x3FFF )
      {
        v57 += 0x4000 - (v57 & 0x3FFF);
      }
    }
    else
    {
      v57 = 8;
    }
    if ( SmartArray<GlyphLine,1>::grow(&v64->m_glyphLines, v57) )
    {
LABEL_96:
      v59 = curLine.m_nLineHeight;
      v60 = (int)&v64->m_glyphLines.m_data[v64->m_glyphLines.m_num];
      *(_DWORD *)(v60 + 4) = v54;
      *(_DWORD *)(v60 + 8) = 0;
      *(_DWORD *)(v60 + 12) = v59;
      ++v64->m_glyphLines.m_num;
    }
    *o_nHeight += v17->data.m_height;
  }
  v64->m_nFirstInvalidPosition = v64->m_glyphList._num_elements;
  return 1;
}

//----- (00473D50) --------------------------------------------------------  // acclient.c:176913
GlyphList *__thiscall GlyphList::scalar_deleting_destructor(GlyphList *this, unsigned int a2)
{
  GlyphList *v2; // esi@1

  v2 = this;
  GlyphList::~GlyphList(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00473D70) --------------------------------------------------------  // acclient.c:176925
char __thiscall GlyphList::InqText(GlyphList *this, bool i_bIncludeHidden, PStringBase<unsigned short> *o_str)
{
  return GlyphList::InqText(this, 0, this->m_glyphList._num_elements, i_bIncludeHidden, o_str);
}

//----- (006EC120) --------------------------------------------------------  // acclient.c:767885
void _E73_75()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_45, PFID_A8R8G8B8);
}

//----- (006EC130) --------------------------------------------------------  // acclient.c:767891
int _E1_70()
{
  return atexit(_E2_70);
}

