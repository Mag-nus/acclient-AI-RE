/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PSUtils
   Object     : CORE\pstring\PSUtils.obj
   Functions  : 77
   Addresses  : 0040AD50 - 00725D60 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0040AD50) --------------------------------------------------------  // acclient.c:70570
void __cdecl Serializer::SerializePrimitive<unsigned char>(char *io_object, Archive *io_archive)
{
  char *v2; // eax@1

  Archive::CheckAlignment(io_archive, 1u);
  v2 = (char *)Archive::GetBytes(io_archive, 1u);
  if ( v2 )
  {
    if ( io_archive->m_flags & 1 )
      *v2 = *io_object;
    else
      *io_object = *v2;
  }
}

//----- (0040AD90) --------------------------------------------------------  // acclient.c:70586
char __thiscall PStringBaseIter_Common<char>::Next(PStringBaseIter_Common<char> *this, int n)
{
  PStringBaseIter_Common<char> *v2; // esi@1
  unsigned int v3; // eax@2
  int v4; // edi@5
  char result; // al@6

  v2 = this;
  if ( n < 0 )
  {
    PStringBaseIter_Common<char>::Next(this, n);
    v3 = v2->curr;
    if ( n <= v3 )
      v2->curr = v3 - n;
    else
      v2->curr = 0;
  }
  v4 = n + v2->curr;
  if ( v4 <= v2->vfptr->GetStrLen(v2) )
  {
    v2->curr = v4;
    result = 1;
  }
  else
  {
    v2->curr = v2->vfptr->GetStrLen(v2);
    result = 0;
  }
  return result;
}

//----- (0040ADF0) --------------------------------------------------------  // acclient.c:70618
char __thiscall PStringBaseIter_Common<unsigned short>::Next(PStringBaseIter_Common<unsigned short> *this, int n)
{
  PStringBaseIter_Common<unsigned short> *v2; // esi@1
  unsigned int v3; // eax@2
  int v4; // edi@5
  char result; // al@6

  v2 = this;
  if ( n < 0 )
  {
    PStringBaseIter_Common<unsigned short>::Next(this, n);
    v3 = v2->curr;
    if ( n <= v3 )
      v2->curr = v3 - n;
    else
      v2->curr = 0;
  }
  v4 = n + v2->curr;
  if ( v4 <= v2->vfptr->GetStrLen(v2) )
  {
    v2->curr = v4;
    result = 1;
  }
  else
  {
    v2->curr = v2->vfptr->GetStrLen(v2);
    result = 0;
  }
  return result;
}

//----- (0040AE50) --------------------------------------------------------  // acclient.c:70650
char __thiscall PStringBaseIter_Common<unsigned short>::SetMark(PStringBaseIter_Common<unsigned short> *this, unsigned int new_mark)
{
  PStringBaseIter_Common<unsigned short> *v2; // esi@1
  char result; // al@2

  v2 = this;
  if ( new_mark <= ((int (*)(void))this->vfptr->GetStrLen)() )
  {
    v2->mark = new_mark;
    result = 1;
  }
  else
  {
    v2->mark = v2->vfptr->GetStrLen(v2);
    result = 0;
  }
  return result;
}

//----- (0040AE80) --------------------------------------------------------  // acclient.c:70670
const unsigned __int16 *__cdecl search_skipescapes<unsigned short>(const unsigned __int16 *str, int c, int escapechar)
{
  const unsigned __int16 *result; // eax@1
  int v4; // ecx@1
  bool v5; // dl@1
  bool v6; // zf@4

  result = str;
  LOWORD(v4) = *str;
  v5 = 0;
  if ( *str )
  {
    while ( 1 )
    {
      v4 = (unsigned __int16)v4;
      if ( (unsigned __int16)v4 == c && !v5 )
        break;
      v6 = v4 == escapechar;
      LOWORD(v4) = result[1];
      v5 = v6;
      ++result;
      if ( !(_WORD)v4 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    result = 0;
  }
  return result;
}

//----- (0040AEC0) --------------------------------------------------------  // acclient.c:70704
void __thiscall PStringBase<unsigned short>::clear(PStringBase<unsigned short> *this)
{
  PStringBase<unsigned short> *v1; // edi@1
  PSRefBufferCharData<unsigned short> *v2; // eax@1
  int v3; // esi@2
  volatile LONG *v4; // ST00_4@5

  v1 = this;
  v2 = this->m_charbuffer;
  if ( (wchar_t *)this->m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
  {
    v3 = (int)&v2[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1].m_data[8]) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    v4 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    v1->m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v4);
  }
}

//----- (0040AF10) --------------------------------------------------------  // acclient.c:70728
int __cdecl template_strcspn<char>(PStringBase<char> *str, const char *pattern, bool bReverse)
{
  PSRefBufferCharData<char> *v3; // edi@2
  int v4; // ebp@2
  int result; // eax@2
  const char *v6; // esi@3
  const char v7; // dl@4
  unsigned int v8; // ecx@5
  PSRefBufferCharData<char> *v9; // edi@11
  int v10; // ebp@11
  const char *v11; // esi@12
  const char v12; // dl@13
  unsigned int v13; // ecx@14

  if ( bReverse )
  {
    v3 = str->m_charbuffer;
    v4 = *(_DWORD *)&str->m_charbuffer[-1].m_data[12];
    result = v4 - 1;
    if ( v4 - 1 > 0 )
    {
      while ( 1 )
      {
        v6 = pattern;
        --result;
        if ( *pattern )
          break;
LABEL_9:
        if ( result <= 0 )
          return -1;
      }
      v7 = *pattern;
      while ( 1 )
      {
        v8 = (unsigned int)((char *)v3 + v4 - 1);
        if ( result < (unsigned int)v4 )
          v8 = (unsigned int)((char *)v3 + result);
        if ( *(_BYTE *)v8 == v7 )
          return result;
        v7 = (v6++)[1];
        if ( !v7 )
          goto LABEL_9;
      }
    }
    return -1;
  }
  v9 = str->m_charbuffer;
  v10 = *(_DWORD *)&str->m_charbuffer[-1].m_data[12];
  result = 0;
  if ( v10 - 1 <= 0 )
    return -1;
  while ( 1 )
  {
    v11 = pattern;
    if ( *pattern )
      break;
LABEL_18:
    ++result;
    if ( result >= v10 - 1 )
      return -1;
  }
  v12 = *pattern;
  while ( 1 )
  {
    v13 = (unsigned int)((char *)v9 + v10 - 1);
    if ( result < (unsigned int)v10 )
      v13 = (unsigned int)((char *)v9 + result);
    if ( *(_BYTE *)v13 == v12 )
      return result;
    v12 = (v11++)[1];
    if ( !v12 )
      goto LABEL_18;
  }
}

//----- (0040AFC0) --------------------------------------------------------  // acclient.c:70804
BOOL __cdecl PSUtils::check_access(PStringBase<char> *filename, int mode)
{
  return __access(filename->m_charbuffer->m_data, mode) == 0;
}

//----- (0040AFE0) --------------------------------------------------------  // acclient.c:70810
wchar_t *__cdecl PSUtils::wcschr_skipescapes(const wchar_t *string, wchar_t c, wchar_t escapechar)
{
  return (wchar_t *)search_skipescapes<unsigned short>(string, c, escapechar);
}

//----- (0040B000) --------------------------------------------------------  // acclient.c:70816
unsigned int __thiscall PStringBaseIter_Const<char>::IndexToConstPointer(PStringBaseIter<char> *this, unsigned int n)
{
  PSRefBufferCharData<char> *v2; // eax@1
  unsigned int v3; // ecx@1
  unsigned int result; // eax@2

  v2 = this->pstring_ptr->m_charbuffer;
  v3 = *(_DWORD *)&v2[-1].m_data[12];
  if ( n < v3 )
    result = (unsigned int)((char *)v2 + n);
  else
    result = (unsigned int)((char *)v2 + v3 - 1);
  return result;
}

//----- (0040B020) --------------------------------------------------------  // acclient.c:70832
PStringBase<unsigned short> *__thiscall PStringBaseIter<unsigned short>::GetPStringPtr(PStringBaseIter<unsigned short> *this)
{
  return this->pstring_ptr;
}

//----- (0040B030) --------------------------------------------------------  // acclient.c:70838
char __thiscall PStringBaseIter_Const<char>::IndexToChar(PStringBaseIter<char> *this, unsigned int n)
{
  PSRefBufferCharData<char> *v2; // eax@1
  unsigned int v3; // ecx@1
  char result; // al@2

  v2 = this->pstring_ptr->m_charbuffer;
  v3 = *(_DWORD *)&v2[-1].m_data[12];
  if ( n < v3 )
    result = v2->m_data[n];
  else
    result = v2->m_data[v3 - 1];
  return result;
}

//----- (0040B050) --------------------------------------------------------  // acclient.c:70854
unsigned int __thiscall PStringBaseIter_Const<unsigned short>::IndexToConstPointer(PStringBaseIter<unsigned short> *this, unsigned int n)
{
  PSRefBufferCharData<unsigned short> *v2; // eax@1
  unsigned int v3; // ecx@1
  unsigned int result; // eax@2

  v2 = this->pstring_ptr->m_charbuffer;
  v3 = *(_DWORD *)&v2[-1].m_data[14];
  if ( n < v3 )
    result = (unsigned int)((char *)v2 + 2 * n);
  else
    result = (unsigned int)((char *)v2 + 2 * v3 - 2);
  return result;
}

//----- (0040B070) --------------------------------------------------------  // acclient.c:70870
unsigned __int16 __thiscall PStringBaseIter_Const<unsigned short>::IndexToChar(PStringBaseIter<unsigned short> *this, unsigned int n)
{
  PSRefBufferCharData<unsigned short> *v2; // eax@1
  unsigned int v3; // ecx@1
  unsigned __int16 result; // ax@2

  v2 = this->pstring_ptr->m_charbuffer;
  v3 = *(_DWORD *)&v2[-1].m_data[14];
  if ( n < v3 )
    result = v2->m_data[n];
  else
    result = v2->m_data[v3 - 1];
  return result;
}

//----- (0040B090) --------------------------------------------------------  // acclient.c:70886
int __thiscall PStringBaseIter<char>::GetStrLen(PStringBaseIter<unsigned short> *this)
{
  return *(_DWORD *)&this->pstring_ptr->m_charbuffer[-1].m_data[14] - 1;
}

//----- (0040B0A0) --------------------------------------------------------  // acclient.c:70892
bool __cdecl wildcard_match_iter<char>(PStringBaseIter_Const<char> *s_iter, PStringBaseIter_Const<char> *w_iter)
{
  PStringBaseIter_Const<char> *v2; // esi@1
  unsigned int v3; // ebp@3
  unsigned int v4; // ebx@13
  char v5; // bl@16
  char v6; // al@16
  unsigned int v7; // ebx@17
  int v8; // ebx@20
  int v9; // eax@24
  unsigned int w_itera; // [sp+18h] [bp+8h]@3
  int w_iterb; // [sp+18h] [bp+8h]@16

  v2 = w_iter;
  while ( v2->vfptr->IndexToChar((PStringBaseIter_Common<char> *)v2, v2->curr) )
  {
    if ( v2->vfptr->IndexToChar((PStringBaseIter_Common<char> *)v2, v2->curr) == 42 )
    {
      v3 = v2->curr;
      w_itera = s_iter->curr;
      if ( v3 + 1 <= v2->vfptr->GetStrLen((PStringBaseIter_Common<char> *)v2) )
        v2->curr = v3 + 1;
      else
        v2->curr = v2->vfptr->GetStrLen((PStringBaseIter_Common<char> *)v2);
      if ( wildcard_match_iter<char>(s_iter, v2) )
      {
        LOBYTE(v9) = 1;
        return v9;
      }
      if ( w_itera <= s_iter->vfptr->GetStrLen((PStringBaseIter_Common<char> *)s_iter) )
        s_iter->curr = w_itera;
      else
        s_iter->curr = s_iter->vfptr->GetStrLen((PStringBaseIter_Common<char> *)s_iter);
      if ( v3 <= v2->vfptr->GetStrLen((PStringBaseIter_Common<char> *)v2) )
        v2->curr = v3;
      else
        v2->curr = v2->vfptr->GetStrLen((PStringBaseIter_Common<char> *)v2);
      v4 = s_iter->curr + 1;
      if ( v4 > s_iter->vfptr->GetStrLen((PStringBaseIter_Common<char> *)s_iter) )
      {
        s_iter->curr = s_iter->vfptr->GetStrLen((PStringBaseIter_Common<char> *)s_iter);
LABEL_26:
        LOBYTE(v9) = 0;
        return v9;
      }
      s_iter->curr = v4;
    }
    else
    {
      if ( v2->vfptr->IndexToChar((PStringBaseIter_Common<char> *)v2, v2->curr) != 63 )
      {
        v5 = s_iter->vfptr->IndexToChar((PStringBaseIter_Common<char> *)s_iter, s_iter->curr);
        v6 = v2->vfptr->IndexToChar((PStringBaseIter_Common<char> *)v2, v2->curr);
        w_iterb = _tolower(v6);
        if ( w_iterb != _tolower(v5) )
          goto LABEL_26;
      }
      v7 = s_iter->curr + 1;
      if ( v7 <= s_iter->vfptr->GetStrLen((PStringBaseIter_Common<char> *)s_iter) )
        s_iter->curr = v7;
      else
        s_iter->curr = s_iter->vfptr->GetStrLen((PStringBaseIter_Common<char> *)s_iter);
      v8 = v2->curr + 1;
      if ( v8 <= v2->vfptr->GetStrLen((PStringBaseIter_Common<char> *)v2) )
        v2->curr = v8;
      else
        v2->curr = v2->vfptr->GetStrLen((PStringBaseIter_Common<char> *)v2);
    }
  }
  return s_iter->vfptr->IndexToChar((PStringBaseIter_Common<char> *)s_iter, s_iter->curr) == 0;
}

//----- (0040B220) --------------------------------------------------------  // acclient.c:70965
char __thiscall PStringBaseIter_Common<char>::FindChar(PStringBaseIter_Common<char> *this, char c, bool reverse)
{
  PStringBaseIter_Common<char> *v3; // esi@1
  unsigned int v4; // eax@2
  PStringBaseIter_Common<char>Vtbl *v5; // edx@3
  int v6; // eax@3
  int v8; // edi@8

  v3 = this;
  if ( reverse )
  {
    while ( 1 )
    {
      v4 = v3->curr;
      if ( v4 < 1 )
        break;
      v5 = v3->vfptr;
      v6 = v4 - 1;
      v3->curr = v6;
      if ( (unsigned __int8)v5->IndexToChar(v3, v6) == c )
        return 1;
    }
    v3->curr = 0;
    return 0;
  }
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))this->vfptr->IndexToChar)(this->curr) != c )
  {
    while ( 1 )
    {
      v8 = v3->curr + 1;
      v3->curr = v8 <= v3->vfptr->GetStrLen(v3) ? v8 : v3->vfptr->GetStrLen(v3);
      if ( !v3->vfptr->IndexToChar(v3, v3->curr) )
        break;
      if ( (unsigned __int8)v3->vfptr->IndexToChar(v3, v3->curr) == c )
        return 1;
    }
    return 0;
  }
  return 1;
}

//----- (0040B2C0) --------------------------------------------------------  // acclient.c:71007
char __thiscall PStringBaseIter_Common<unsigned short>::FindChar(PStringBaseIter_Common<unsigned short> *this, unsigned __int16 c, bool reverse)
{
  PStringBaseIter_Common<unsigned short> *v3; // esi@1
  unsigned int v4; // eax@2
  PStringBaseIter_Common<unsigned short>Vtbl *v5; // edx@3
  int v6; // eax@3
  int v8; // edi@8

  v3 = this;
  if ( reverse )
  {
    while ( 1 )
    {
      v4 = v3->curr;
      if ( v4 < 1 )
        break;
      v5 = v3->vfptr;
      v6 = v4 - 1;
      v3->curr = v6;
      if ( v5->IndexToChar(v3, v6) == c )
        return 1;
    }
    v3->curr = 0;
    return 0;
  }
  if ( (unsigned __int16)((int (__stdcall *)(_DWORD))this->vfptr->IndexToChar)(this->curr) != c )
  {
    while ( 1 )
    {
      v8 = v3->curr + 1;
      v3->curr = v8 <= v3->vfptr->GetStrLen(v3) ? v8 : v3->vfptr->GetStrLen(v3);
      if ( !v3->vfptr->IndexToChar(v3, v3->curr) )
        break;
      if ( v3->vfptr->IndexToChar(v3, v3->curr) == c )
        return 1;
    }
    return 0;
  }
  return 1;
}

//----- (0040B360) --------------------------------------------------------  // acclient.c:71049
char __cdecl template_find_extension<char>(PStringBaseIter<char> *io_extension)
{
  unsigned int v1; // eax@1
  unsigned int v2; // eax@2
  PStringBaseIter_Common<char>Vtbl *v3; // edx@3
  unsigned int v4; // eax@3
  char v5; // al@3
  char v6[4]; // edx@4
  char v7; // cl@4

  v1 = io_extension->vfptr->GetStrLen((PStringBaseIter_Common<char> *)io_extension);
  io_extension->curr = v1;
  io_extension->mark = v1;
LABEL_2:
  v2 = io_extension->curr;
  if ( v2 < 1 )
  {
    io_extension->curr = 0;
    return 0;
  }
  v3 = io_extension->vfptr;
  v4 = v2 - 1;
  io_extension->curr = v4;
  v5 = v3->IndexToChar((PStringBaseIter_Common<char> *)io_extension, v4);
  if ( v5 != 46 )
  {
    *(_DWORD *)v6 = "\\/:";
    v7 = 92;
    while ( v7 != v5 )
    {
      v7 = *(_BYTE *)((*(_DWORD *)v6)++ + 1);
      if ( !v7 )
        goto LABEL_2;
    }
    return 0;
  }
  return 1;
}

//----- (0040B3C0) --------------------------------------------------------  // acclient.c:71089
char __thiscall List<PStringBase<char>>::push_back(List<PStringBase<char> > *this, PStringBase<char> *val)
{
  List<PStringBase<char> > *v2; // edi@1
  void *v3; // esi@1
  PSRefBufferCharData<char> *v4; // eax@2
  char result; // al@3
  ListNode<PStringBase<char> > *v6; // eax@5

  v2 = this;
  v3 = operator new(0xCu);
  if ( v3 )
  {
    v4 = val->m_charbuffer;
    *(_DWORD *)v3 = val->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v4[-1]);
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
    if ( v2->_head )
    {
      v6 = v2->_tail;
      v6->next = (ListNode<PStringBase<char> > *)v3;
      *((_DWORD *)v3 + 2) = v6;
      result = 1;
      ++v2->_num_elements;
      v2->_tail = (ListNode<PStringBase<char> > *)v3;
    }
    else
    {
      result = 1;
      ++v2->_num_elements;
      v2->_head = (ListNode<PStringBase<char> > *)v3;
      v2->_tail = (ListNode<PStringBase<char> > *)v3;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0040B430) --------------------------------------------------------  // acclient.c:71131
char __thiscall PStringBaseIter_Common<char>::FindChar(PStringBaseIter_Common<char> *this, PStringBase<char> *s, bool reverse)
{
  PStringBaseIter_Common<char> *v3; // esi@1
  unsigned int v4; // eax@2
  PStringBaseIter_Common<char>Vtbl *v5; // edx@3
  int v6; // eax@3
  char v7; // al@3
  char v9; // al@7
  int v10; // edi@8
  PStringBaseIter_Common<char>Vtbl *v11; // edx@12
  unsigned int v12; // ST00_4@12
  char v13; // al@12
  PStringBaseIter_Const<char> iter; // [sp+Ch] [bp-10h]@1

  v3 = this;
  iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
  iter.pstring_ptr = s;
  iter.curr = 0;
  iter.mark = 0;
  if ( reverse )
  {
    while ( 1 )
    {
      v4 = v3->curr;
      if ( v4 < 1 )
        break;
      v5 = v3->vfptr;
      v6 = v4 - 1;
      v3->curr = v6;
      iter.curr = 0;
      v7 = v5->IndexToChar(v3, v6);
      if ( PStringBaseIter_Common<char>::FindChar((PStringBaseIter_Common<char> *)&iter.vfptr, v7, 0) )
        return 1;
    }
    v3->curr = 0;
    return 0;
  }
  v9 = this->vfptr->IndexToChar(this, this->curr);
  if ( !PStringBaseIter_Common<char>::FindChar((PStringBaseIter_Common<char> *)&iter.vfptr, v9, 0) )
  {
    while ( 1 )
    {
      v10 = v3->curr + 1;
      v3->curr = v10 <= v3->vfptr->GetStrLen(v3) ? v10 : v3->vfptr->GetStrLen(v3);
      if ( !v3->vfptr->IndexToChar(v3, v3->curr) )
        break;
      v11 = v3->vfptr;
      v12 = v3->curr;
      iter.curr = 0;
      v13 = v11->IndexToChar(v3, v12);
      if ( PStringBaseIter_Common<char>::FindChar((PStringBaseIter_Common<char> *)&iter.vfptr, v13, 0) )
        return 1;
    }
    return 0;
  }
  return 1;
}
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (0040B510) --------------------------------------------------------  // acclient.c:71191
void __thiscall PStringBase<char>::PStringBase<char>(PStringBase<char> *this, char c)
{
  PStringBase<char> *v2; // esi@1
  volatile LONG *v3; // ST00_4@2
  void *v4; // eax@3
  int v5; // eax@4

  v2 = this;
  if ( c )
  {
    v4 = operator new[](0x24u);
    if ( v4 )
    {
      *((_DWORD *)v4 + 1) = 1;
      *(_DWORD *)v4 = AC1Legacy::PSRefBuffer<char>::vftable;
      *((_DWORD *)v4 + 4) = 1;
      *((_DWORD *)v4 + 2) = 1;
      *((_DWORD *)v4 + 3) = -1;
      v5 = (int)((char *)v4 + 20);
      *(_BYTE *)v5 = 0;
      v2->m_charbuffer = (PSRefBufferCharData<char> *)v5;
      *(_DWORD *)(v5 - 4) = 2;
      *(_DWORD *)&v2->m_charbuffer[-1].m_data[4] = 16;
    }
    v2->m_charbuffer->m_data[0] = c;
    v2->m_charbuffer->m_data[1] = 0;
  }
  else
  {
    v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    this->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v3);
  }
}
// 7CA074: using guessed type int (__thiscall *AC1Legacy::PSRefBuffer<char>::vftable[2])(void *, char);

//----- (0040B590) --------------------------------------------------------  // acclient.c:71228
void __thiscall PStringBase<unsigned short>::append_string(PStringBase<unsigned short> *this, const unsigned __int16 *str)
{
  PStringBase<unsigned short> *v2; // edi@1
  unsigned int v3; // eax@3

  v2 = this;
  if ( str )
  {
    if ( *str )
    {
      v3 = _wcslen(str);
      PStringBase<unsigned short>::append_n_chars(v2, str, v3);
    }
  }
}

//----- (0040B5C0) --------------------------------------------------------  // acclient.c:71245
char __thiscall PStringBaseIter_Common<unsigned short>::GetSubString(PStringBaseIter_Common<unsigned short> *this, PStringBase<unsigned short> *retval)
{
  unsigned int v2; // eax@1
  unsigned int v3; // edx@1
  unsigned int v4; // esi@2
  int v5; // eax@2
  const unsigned __int16 *v6; // ebx@4
  PSRefBufferCharData<unsigned short> *v7; // eax@4
  int v8; // edi@5
  volatile LONG *v9; // ST00_4@8

  v2 = this->mark;
  v3 = this->curr;
  if ( v2 >= v3 )
  {
    v4 = v2 - this->curr;
    v5 = ((int (__stdcall *)(_DWORD))this->vfptr->IndexToConstPointer)(this->curr);
  }
  else
  {
    v4 = v3 - v2;
    v5 = ((int (__stdcall *)(_DWORD))this->vfptr->IndexToConstPointer)(this->mark);
  }
  v6 = (const unsigned __int16 *)v5;
  v7 = retval->m_charbuffer;
  if ( (wchar_t *)retval->m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
  {
    v8 = (int)&v7[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v7[-1].m_data[8]) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    v9 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    retval->m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v9);
  }
  if ( v4 )
    PStringBase<unsigned short>::append_n_chars(retval, v6, v4);
  return 1;
}

//----- (0040B640) --------------------------------------------------------  // acclient.c:71285
PStringBase<unsigned short> *__thiscall PStringBaseIter_Common<unsigned short>::GetSubString(PStringBaseIter_Common<unsigned short> *this, PStringBase<unsigned short> *result)
{
  PStringBaseIter_Common<unsigned short> *v2; // esi@1
  PSRefBufferCharData<unsigned short> *v3; // esi@1
  volatile LONG *v4; // ST00_4@1
  int v5; // esi@1
  PStringBase<unsigned short> retval; // [sp+0h] [bp-4h]@1

  retval.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  PStringBaseIter_Common<unsigned short>::GetSubString(v2, &retval);
  v3 = retval.m_charbuffer;
  v4 = (volatile LONG *)&retval.m_charbuffer[-1].m_data[8];
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (int)&v3[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return result;
}

//----- (0040B6A0) --------------------------------------------------------  // acclient.c:71308
char __thiscall PStringBaseIter<unsigned short>::Truncate(PStringBaseIter<unsigned short> *this)
{
  PStringBaseIter<unsigned short> *v1; // esi@1
  PSRefBufferCharData<unsigned short> *v2; // ebx@1
  wchar_t **v3; // edi@1
  wchar_t *v4; // eax@1
  int v5; // ebp@2
  volatile LONG *v6; // ST00_4@5
  unsigned int v7; // eax@8
  int v8; // ebx@10

  v1 = this;
  v2 = this->pstring_ptr->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v2[-1].m_data[8]);
  v3 = (wchar_t **)v1->pstring_ptr;
  v4 = *v3;
  if ( *v3 != PStringBase<unsigned short>::s_NullBuffer )
  {
    v5 = (int)(v4 - 10);
    if ( !InterlockedDecrement((volatile LONG *)v4 - 4) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    *v3 = PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v6);
  }
  if ( v1->curr )
    PStringBase<unsigned short>::append_n_chars(v1->pstring_ptr, v2->m_data, v1->curr);
  v7 = v1->curr;
  if ( v1->mark > v7 )
    v1->mark = v7;
  v8 = (int)&v2[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  return 1;
}

//----- (0040B740) --------------------------------------------------------  // acclient.c:71345
SmartBuffer *__cdecl PSUtils::get_binary_buffer_from_string(SmartBuffer *result, PStringBase<char> *str)
{
  SmartBuffer *v2; // eax@3
  PSRefBufferCharData<char> *v3; // esi@3
  PSRefBufferCharData<char> *v4; // ebp@3
  bool v5; // cf@3
  char v6; // bl@6
  unsigned int v7; // eax@6
  char s[3]; // [sp+8h] [bp-10h]@3
  SmartBuffer v10; // [sp+Ch] [bp-Ch]@3

  if ( !(_S83_6 & 1) )
  {
    _S83_6 |= 1u;
    archive.vfptr = (ArchiveVtbl *)&Archive::vftable;
    dword_8367B0 = 0;
    unk_8367B4 = 0;
    SmartBuffer::SmartBuffer(&stru_8367B8);
    unk_8367C4 = 0;
    unk_8367C8 = 0;
    unk_8367CC = 0;
    archive.vfptr = (ArchiveVtbl *)&TransientArchive::vftable;
    atexit(_E84_1);
  }
  SmartBuffer::SmartBuffer(&v10);
  Archive::InitForPacking((Archive *)&archive.vfptr, &Archive::SetCurrentCoreVersion, v2);
  SmartBuffer::ReleaseMasterBuffer(&v10);
  v3 = str->m_charbuffer;
  v4 = (PSRefBufferCharData<char> *)((char *)str->m_charbuffer + *(_DWORD *)&str->m_charbuffer[-1].m_data[12] - 1);
  v5 = str->m_charbuffer < v4;
  s[2] = 0;
  if ( v5 )
  {
    do
    {
      if ( _isspace(v3->m_data[0]) )
      {
        v3 = (PSRefBufferCharData<char> *)((char *)v3 + 1);
      }
      else
      {
        s[0] = v3->m_data[0];
        s[1] = v3->m_data[1];
        v3 = (PSRefBufferCharData<char> *)((char *)v3 + 2);
        v6 = _strtoul(s, (char **)&str, 16);
        Archive::CheckAlignment((Archive *)&archive.vfptr, 1u);
        v7 = Archive::GetBytes((Archive *)&archive.vfptr, 1u);
        if ( v7 && dword_8367B0 & 1 )
          *(_BYTE *)v7 = v6;
      }
    }
    while ( v3 < v4 );
  }
  Archive::GetSerializedBuffer((Archive *)&archive.vfptr, result);
  return result;
}
// 792B3C: using guessed type void (__thiscall *Archive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);
// 792B50: using guessed type void (__thiscall *TransientArchive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);

//----- (0040B860) --------------------------------------------------------  // acclient.c:71405
PStringBase<char> *__thiscall PStringBase<char>::operator+(PStringBase<char> *this, PStringBase<char> *result, PStringBase<char> *rhs)
{
  PSRefBufferCharData<char> *v3; // esi@1
  PStringBase<char> *v4; // edi@1
  int v5; // esi@1
  PSRefBufferCharData<char> *v6; // esi@4
  PSRefBufferCharData<char> *v7; // ecx@4
  PSRefBufferCharData<char> *v8; // edx@4
  char v9; // al@5
  PSRefBufferCharData<char> *v10; // ecx@6
  int v11; // edx@6
  char v12; // al@7
  int v13; // esi@8
  PStringBase<char> retstr; // [sp+Ch] [bp-4h]@1

  v3 = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v4 = this;
  retstr.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  PStringBase<char>::allocate_ref_buffer(
    &retstr,
    *(_DWORD *)&rhs->m_charbuffer[-1].m_data[12] + *(_DWORD *)&v4->m_charbuffer[-1].m_data[12] - 2);
  v6 = retstr.m_charbuffer;
  v7 = v4->m_charbuffer;
  v8 = retstr.m_charbuffer;
  do
  {
    v9 = v7->m_data[0];
    v8->m_data[0] = v7->m_data[0];
    v7 = (PSRefBufferCharData<char> *)((char *)v7 + 1);
    v8 = (PSRefBufferCharData<char> *)((char *)v8 + 1);
  }
  while ( v9 );
  v10 = rhs->m_charbuffer;
  v11 = (int)((char *)v6 + *(_DWORD *)&v4->m_charbuffer[-1].m_data[12] - 1);
  do
  {
    v12 = v10->m_data[0];
    *(_BYTE *)v11 = v10->m_data[0];
    v10 = (PSRefBufferCharData<char> *)((char *)v10 + 1);
    ++v11;
  }
  while ( v12 );
  result->m_charbuffer = v6;
  InterlockedIncrement((volatile LONG *)&v6[-1]);
  v13 = (int)&v6[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  return result;
}

//----- (0040B920) --------------------------------------------------------  // acclient.c:71460
char __usercall template_explode<unsigned short>@<al>(unsigned int a1@<esi>, PStringBase<unsigned short> *source, unsigned __int16 sep, List<PStringBase<unsigned short> > *list)
{
  List<PStringBase<unsigned short> > *v4; // edi@2
  void *v5; // eax@4
  PStringBase<unsigned short> *v6; // ebp@4
  void *v7; // esi@4
  volatile LONG *v8; // ST04_4@5
  ListNode<PStringBase<unsigned short> > *v9; // eax@7
  unsigned int v10; // esi@9
  unsigned int v11; // esi@12
  PStringBase<unsigned short> *v13; // esi@20
  unsigned int v14; // [sp-Ch] [bp-20h]@2
  PStringBaseIter_Const<unsigned short> iter; // [sp+4h] [bp-10h]@1

  iter.pstring_ptr = source;
  iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Const<unsigned short>::vftable;
  iter.curr = 0;
  iter.mark = 0;
  if ( PStringBaseIter_Const<unsigned short>::IndexToChar((PStringBaseIter<unsigned short> *)&iter, 0) )
  {
    v4 = list;
    v14 = a1;
    while ( 1 )
    {
      source = (PStringBase<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      PStringBaseIter_Common<unsigned short>::FindChar((PStringBaseIter_Common<unsigned short> *)&iter.vfptr, sep, 0);
      if ( !PStringBaseIter_Common<unsigned short>::GetSubString(
              (PStringBaseIter_Common<unsigned short> *)&iter.vfptr,
              (PStringBase<unsigned short> *)&source) )
        break;
      v5 = operator new(0xCu);
      v6 = source;
      v7 = v5;
      if ( v5 )
      {
        v8 = (volatile LONG *)&source[-4];
        *(_DWORD *)v5 = source;
        InterlockedIncrement(v8);
        *((_DWORD *)v7 + 1) = 0;
        *((_DWORD *)v7 + 2) = 0;
        if ( v4->_head )
        {
          v9 = v4->_tail;
          v9->next = (ListNode<PStringBase<unsigned short> > *)v7;
          *((_DWORD *)v7 + 2) = v9;
        }
        else
        {
          v4->_head = (ListNode<PStringBase<unsigned short> > *)v7;
        }
        ++v4->_num_elements;
        v4->_tail = (ListNode<PStringBase<unsigned short> > *)v7;
      }
      v10 = iter.curr + 1;
      if ( v10 <= ((int (__thiscall *)(_DWORD, _DWORD))iter.vfptr->GetStrLen)(&iter, v14) )
        iter.pstring_ptr = (PStringBase<unsigned short> *)v10;
      else
        iter.pstring_ptr = (PStringBase<unsigned short> *)(*(int (__thiscall **)(_DWORD))iter.curr)(&iter.curr);
      v11 = iter.mark + 1;
      if ( v11 <= (*(int (__thiscall **)(_DWORD))iter.curr)(&iter.curr) )
        iter.mark = v11;
      else
        iter.mark = (*(int (__thiscall **)(_DWORD))iter.curr)(&iter.curr);
      if ( !InterlockedDecrement((volatile LONG *)&v6[-4]) && v6 != (PStringBase<unsigned short> *)20 )
        (*(void (__thiscall **)(_DWORD, _DWORD))v6[-5].m_charbuffer)(&v6[-5], 1);
      v14 = iter.mark;
      if ( !(unsigned __int16)(*(int (__thiscall **)(unsigned int *))(iter.curr + 8))(&iter.curr) )
        return 1;
    }
    v13 = source - 5;
    if ( !InterlockedDecrement((volatile LONG *)&source[-4]) && v13 )
      (*(void (__thiscall **)(_DWORD, _DWORD))&v13->m_charbuffer->m_data[0])(v13, 1);
  }
  return 1;
}
// 40B920: could not find valid save-restore pair for esi
// 79449C: using guessed type int (*PStringBaseIter_Const<unsigned short>::vftable)();

//----- (0040BA90) --------------------------------------------------------  // acclient.c:71540
char __thiscall PStringBaseIter<unsigned short>::Replace(PStringBaseIter<unsigned short> *this, PStringBase<unsigned short> *s)
{
  PStringBaseIter<unsigned short> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // ecx@1
  unsigned int v5; // ebp@2
  const unsigned __int16 *v6; // ebx@4
  wchar_t **v7; // edi@4
  wchar_t *v8; // eax@4
  int v9; // ebp@5
  volatile LONG *v10; // ST04_4@8
  int v11; // ecx@11
  unsigned int v12; // eax@13
  int v13; // ecx@13
  int v14; // edi@16
  unsigned int v15; // eax@20
  unsigned int v16; // ecx@21
  int v17; // edx@21
  int v18; // eax@21
  int v19; // ebx@24
  unsigned int end; // [sp+10h] [bp-8h]@2
  unsigned int enda; // [sp+10h] [bp-8h]@18
  unsigned int start; // [sp+14h] [bp-4h]@2

  v2 = this;
  v3 = this->curr;
  v4 = this->mark;
  if ( v3 >= v4 )
  {
    start = v4;
    end = v3;
    v5 = v3;
  }
  else
  {
    v5 = v4;
    start = v3;
    end = v4;
  }
  v6 = (const unsigned __int16 *)v2->pstring_ptr->m_charbuffer;
  InterlockedIncrement((volatile LONG *)v6 - 4);
  v7 = (wchar_t **)v2->pstring_ptr;
  v8 = *v7;
  if ( *v7 != PStringBase<unsigned short>::s_NullBuffer )
  {
    v9 = (int)(v8 - 10);
    if ( !InterlockedDecrement((volatile LONG *)v8 - 4) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v10 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    *v7 = PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v10);
    v5 = end;
  }
  if ( start )
    PStringBase<unsigned short>::append_n_chars(v2->pstring_ptr, v6, start);
  v11 = *(_DWORD *)&s->m_charbuffer[-1].m_data[14];
  if ( v11 != 1 )
    PStringBase<unsigned short>::append_n_chars(v2->pstring_ptr, s->m_charbuffer->m_data, v11 - 1);
  v12 = *((_DWORD *)v6 - 1);
  v13 = (int)&v6[v12 - 1];
  if ( v5 < v12 )
    v13 = (int)&v6[v5];
  if ( *(_WORD *)v13 )
  {
    v14 = (int)&v6[v12 - 1];
    if ( v5 < v12 )
      v14 = (int)&v6[v5];
    enda = (unsigned int)v2->pstring_ptr;
    if ( v14 && *(_WORD *)v14 )
    {
      v15 = _wcslen((const wchar_t *)v14);
      PStringBase<unsigned short>::append_n_chars(
        (PStringBase<unsigned short> *)enda,
        (const unsigned __int16 *)v14,
        v15);
    }
  }
  v16 = v2->curr;
  v17 = v5 - start;
  v18 = *(_DWORD *)&s->m_charbuffer[-1].m_data[14] - 1;
  if ( v16 == v5 )
    v2->curr = v18 + v16 - v17;
  else
    v2->mark += v18 - v17;
  v19 = (int)(v6 - 10);
  if ( !InterlockedDecrement((volatile LONG *)(v19 + 4)) && v19 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
  return 1;
}

//----- (0040BBD0) --------------------------------------------------------  // acclient.c:71631
char __thiscall PStringBaseIter_Common<char>::GetSubString(PStringBaseIter_Common<char> *this, PStringBase<char> *retval)
{
  unsigned int v2; // eax@1
  unsigned int v3; // edx@1
  unsigned int v4; // esi@2
  int v5; // eax@2
  const char *v6; // ebx@4
  PSRefBufferCharData<char> *v7; // eax@4
  int v8; // edi@5
  volatile LONG *v9; // ST00_4@8

  v2 = this->mark;
  v3 = this->curr;
  if ( v2 >= v3 )
  {
    v4 = v2 - this->curr;
    v5 = ((int (__stdcall *)(_DWORD))this->vfptr->IndexToConstPointer)(this->curr);
  }
  else
  {
    v4 = v3 - v2;
    v5 = ((int (__stdcall *)(_DWORD))this->vfptr->IndexToConstPointer)(this->mark);
  }
  v6 = (const char *)v5;
  v7 = retval->m_charbuffer;
  if ( retval->m_charbuffer != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v8 = (int)&v7[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v7[-1]) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    v9 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    retval->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v9);
  }
  if ( v4 )
    PStringBase<char>::append_n_chars(retval, v6, v4);
  return 1;
}

//----- (0040BC50) --------------------------------------------------------  // acclient.c:71671
PStringBase<char> *__thiscall PStringBaseIter_Common<char>::GetSubString(PStringBaseIter_Common<char> *this, PStringBase<char> *result)
{
  PStringBaseIter_Common<char> *v2; // esi@1
  PSRefBufferCharData<char> *v3; // esi@1
  volatile LONG *v4; // ST00_4@1
  int v5; // esi@1
  PStringBase<char> retval; // [sp+0h] [bp-4h]@1

  retval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBaseIter_Common<char>::GetSubString(v2, &retval);
  v3 = retval.m_charbuffer;
  v4 = (volatile LONG *)&retval.m_charbuffer[-1];
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return result;
}

//----- (0040BCB0) --------------------------------------------------------  // acclient.c:71694
char __thiscall PStringBaseIter<char>::Truncate(PStringBaseIter<char> *this)
{
  PStringBaseIter<char> *v1; // esi@1
  PSRefBufferCharData<char> *v2; // ebx@1
  PSRefBufferCharData<char> **v3; // edi@1
  PSRefBufferCharData<char> *v4; // eax@1
  int v5; // ebp@2
  volatile LONG *v6; // ST00_4@5
  unsigned int v7; // eax@8
  int v8; // ebx@10

  v1 = this;
  v2 = this->pstring_ptr->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v2[-1]);
  v3 = &v1->pstring_ptr->m_charbuffer;
  v4 = *v3;
  if ( *v3 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v5 = (int)&v4[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    *v3 = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v6);
  }
  if ( v1->curr )
    PStringBase<char>::append_n_chars(v1->pstring_ptr, v2->m_data, v1->curr);
  v7 = v1->curr;
  if ( v1->mark > v7 )
    v1->mark = v7;
  v8 = (int)&v2[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  return 1;
}

//----- (0040BD50) --------------------------------------------------------  // acclient.c:71731
char __thiscall PStringBaseIter<char>::Behead(PStringBaseIter<char> *this)
{
  PStringBaseIter<char> *v1; // esi@1
  PSRefBufferCharData<char> *v2; // ebx@2
  PSRefBufferCharData<char> **v3; // edi@2
  PSRefBufferCharData<char> *v4; // eax@2
  int v5; // ebp@3
  volatile LONG *v6; // ST04_4@6
  unsigned int v7; // ecx@7
  unsigned int v8; // eax@7
  bool v9; // cf@7
  int v10; // ecx@7
  unsigned int v11; // eax@12
  unsigned int v12; // ecx@12

  v1 = this;
  if ( this->curr )
  {
    v2 = this->pstring_ptr->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v2[-1]);
    v3 = &v1->pstring_ptr->m_charbuffer;
    v4 = *v3;
    if ( *v3 != PStringBase<char>::s_NullBuffer.m_charbuffer )
    {
      v5 = (int)&v4[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      v6 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
      *v3 = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement(v6);
    }
    v7 = *(_DWORD *)&v2[-1].m_data[12];
    v8 = v1->curr;
    v9 = v8 < v7;
    v10 = (int)((char *)v2 + v7 - 1);
    if ( v9 )
      v10 = (int)((char *)v2 + v8);
    if ( v10 && *(_BYTE *)v10 )
      PStringBase<char>::append_n_chars(v1->pstring_ptr, (const char *)v10, strlen((const char *)v10));
    v11 = v1->mark;
    v12 = v1->curr;
    if ( v11 < v12 )
      v1->mark = 0;
    else
      v1->mark = v11 - v12;
    v1->curr = 0;
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) && v2 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&v2[-2].m_data[12])(&v2[-2].m_data[12], 1);
  }
  return 1;
}

//----- (0040BE20) --------------------------------------------------------  // acclient.c:71784
char __thiscall List<PStringBase<unsigned short>>::pop_front(List<PStringBase<unsigned short> > *this, PStringBase<unsigned short> *retval)
{
  List<PStringBase<unsigned short> > *v2; // ebx@1
  ListNode<PStringBase<unsigned short> > *v3; // edi@1
  char result; // al@2
  ListNode<PStringBase<unsigned short> > *v5; // eax@3
  PSRefBufferCharData<unsigned short> *v6; // eax@6
  int v7; // esi@7
  PSRefBufferCharData<unsigned short> *v8; // eax@10
  int v9; // esi@11

  v2 = this;
  v3 = this->_head;
  if ( v3 )
  {
    v5 = v3->next;
    this->_head = v5;
    if ( v5 )
      v5->prev = 0;
    else
      this->_tail = 0;
    v6 = retval->m_charbuffer;
    if ( retval->m_charbuffer != v3->data.m_charbuffer )
    {
      v7 = (int)&v6[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v6[-1].m_data[8]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      v8 = v3->data.m_charbuffer;
      retval->m_charbuffer = v3->data.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v8[-1].m_data[8]);
    }
    v9 = (int)&v3->data.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) )
    {
      if ( v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    }
    operator delete(v3);
    --v2->_num_elements;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0040BED0) --------------------------------------------------------  // acclient.c:71833
PStringBase<char> *__cdecl PSUtils::get_process_name(PStringBase<char> *result)
{
  char buff[260]; // [sp+4h] [bp-104h]@1

  buff[0] = 0;
  GetModuleFileNameA(0, buff, 0x104u);
  PStringBase<char>::PStringBase<char>(result, buff);
  return result;
}

//----- (0040BF10) --------------------------------------------------------  // acclient.c:71844
char __cdecl PSUtils::GetEnvironmentVariableA(PStringBase<unsigned short> *env, PStringBase<unsigned short> *retval)
{
  DWORD v2; // eax@1
  DWORD v3; // esi@1
  int v4; // eax@2
  void *v5; // esp@2
  char result; // al@3
  int v7; // [sp-Ch] [bp-18h]@2

  v2 = GetEnvironmentVariableW(env->m_charbuffer->m_data, 0, 0);
  v3 = v2;
  if ( v2
    && (v4 = 2 * v2 + 5,
        LOBYTE(v4) = v4 & 0xFC,
        v5 = alloca(v4),
        GetEnvironmentVariableW(env->m_charbuffer->m_data, (LPWSTR)&v7, v3) < v3) )
  {
    PStringBase<unsigned short>::set(retval, (const unsigned __int16 *)&v7);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0040BF70) --------------------------------------------------------  // acclient.c:71872
char __usercall template_explode<char>@<al>(unsigned int a1@<esi>, PStringBase<char> *source, char sep, List<PStringBase<char> > *list)
{
  List<PStringBase<char> > *v4; // edi@2
  void *v5; // eax@4
  PStringBase<char> *v6; // ebp@4
  void *v7; // esi@4
  volatile LONG *v8; // ST04_4@5
  ListNode<PStringBase<char> > *v9; // eax@7
  unsigned int v10; // esi@9
  unsigned int v11; // esi@12
  PStringBase<char> *v13; // esi@20
  unsigned int v14; // [sp-Ch] [bp-20h]@2
  PStringBaseIter_Const<char> iter; // [sp+4h] [bp-10h]@1

  iter.pstring_ptr = source;
  iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
  iter.curr = 0;
  iter.mark = 0;
  if ( PStringBaseIter_Const<char>::IndexToChar((PStringBaseIter<char> *)&iter, 0) )
  {
    v4 = list;
    v14 = a1;
    while ( 1 )
    {
      source = (PStringBase<char> *)PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PStringBaseIter_Common<char>::FindChar((PStringBaseIter_Common<char> *)&iter.vfptr, sep, 0);
      if ( !PStringBaseIter_Common<char>::GetSubString(
              (PStringBaseIter_Common<char> *)&iter.vfptr,
              (PStringBase<char> *)&source) )
        break;
      v5 = operator new(0xCu);
      v6 = source;
      v7 = v5;
      if ( v5 )
      {
        v8 = (volatile LONG *)&source[-4];
        *(_DWORD *)v5 = source;
        InterlockedIncrement(v8);
        *((_DWORD *)v7 + 1) = 0;
        *((_DWORD *)v7 + 2) = 0;
        if ( v4->_head )
        {
          v9 = v4->_tail;
          v9->next = (ListNode<PStringBase<char> > *)v7;
          *((_DWORD *)v7 + 2) = v9;
        }
        else
        {
          v4->_head = (ListNode<PStringBase<char> > *)v7;
        }
        ++v4->_num_elements;
        v4->_tail = (ListNode<PStringBase<char> > *)v7;
      }
      v10 = iter.curr + 1;
      if ( v10 <= ((int (__thiscall *)(PStringBaseIter_Const<char> *, unsigned int))iter.vfptr->GetStrLen)(&iter, v14) )
        iter.pstring_ptr = (PStringBase<char> *)v10;
      else
        iter.pstring_ptr = (PStringBase<char> *)(*(int (__thiscall **)(unsigned int *))iter.curr)(&iter.curr);
      v11 = iter.mark + 1;
      if ( v11 <= (*(int (__thiscall **)(_DWORD))iter.curr)(&iter.curr) )
        iter.mark = v11;
      else
        iter.mark = (*(int (__thiscall **)(unsigned int *))iter.curr)(&iter.curr);
      if ( !InterlockedDecrement((volatile LONG *)&v6[-4]) && v6 != (PStringBase<char> *)20 )
        (*(void (__thiscall **)(PStringBase<char> *, signed int))v6[-5].m_charbuffer)(&v6[-5], 1);
      v14 = iter.mark;
      if ( !(unsigned __int8)(*(int (__thiscall **)(unsigned int *))(iter.curr + 8))(&iter.curr) )
        return 1;
    }
    v13 = source - 5;
    if ( !InterlockedDecrement((volatile LONG *)&source[-4]) && v13 )
      (*(void (__thiscall **)(PStringBase<char> *, signed int))&v13->m_charbuffer->m_data[0])(v13, 1);
  }
  return 1;
}
// 40BF70: could not find valid save-restore pair for esi
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (0040C0E0) --------------------------------------------------------  // acclient.c:71952
bool __thiscall SmartArray<PStringBase<char>,1>::AddToEnd(SmartArray<PStringBase<char>,1> *this, PStringBase<char> *i_rData)
{
  SmartArray<PStringBase<char>,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  bool result; // al@2
  int v6; // edi@3
  PSRefBufferCharData<char> *v7; // eax@3
  int v8; // ebx@4
  PSRefBufferCharData<char> *v9; // eax@7

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<char *,1>::get_new_size(v3 + 1), (result = SmartArray<PStringBase<char>,1>::grow(v2, v4)) != 0) )
  {
    v6 = (int)&v2->m_data[v2->m_num];
    v7 = *(PSRefBufferCharData<char> **)v6;
    if ( *(PSRefBufferCharData<char> **)v6 != i_rData->m_charbuffer )
    {
      v8 = (int)&v7[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v7[-1]) )
      {
        if ( v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      }
      v9 = i_rData->m_charbuffer;
      *(_DWORD *)v6 = i_rData->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v9[-1]);
    }
    ++v2->m_num;
    result = 1;
  }
  return result;
}

//----- (0040C160) --------------------------------------------------------  // acclient.c:71989
char __thiscall PStringBaseIter_Common<char>::Split(PStringBaseIter_Common<char> *this, PStringBase<char> *start, PStringBase<char> *middle, PStringBase<char> *end)
{
  PStringBaseIter_Common<char> *v4; // edi@1
  PStringBase<char> *v5; // esi@1
  unsigned int v6; // eax@2
  unsigned int v7; // ecx@2
  unsigned int v8; // ebp@3
  const unsigned __int16 *v9; // eax@6
  char *v10; // ebx@6
  const unsigned __int16 *v11; // eax@9
  PStringBase<char> *v12; // ebp@9
  unsigned int v13; // eax@12
  const unsigned __int16 *v14; // eax@12
  PStringBase<char> *v15; // esi@12
  LONG v16; // eax@12
  const unsigned __int16 *v18; // eax@17
  char *v19; // ebx@17
  unsigned int v20; // eax@20
  const unsigned __int16 *v21; // eax@20
  unsigned int second; // [sp+8h] [bp-8h]@3
  PStringBase<char> result; // [sp+Ch] [bp-4h]@6

  v4 = this;
  v5 = (PStringBase<char> *)((int (*)(void))this->vfptr->GetPStringPtr)();
  if ( !v5 )
    return 0;
  v6 = v4->curr;
  v7 = v4->mark;
  if ( v7 <= v6 )
  {
    if ( v7 >= v6 )
    {
      v18 = (const unsigned __int16 *)PStringBase<char>::substring(v5, &result, 0, v6 - 1);
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)start, v18);
      v19 = &result.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v19 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
      PStringBase<char>::clear(middle);
      v20 = v4->vfptr->GetStrLen(v4);
      v21 = (const unsigned __int16 *)PStringBase<char>::substring(v5, (PStringBase<char> *)&start, v4->curr, v20);
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)end, v21);
      v15 = start - 5;
      v16 = InterlockedDecrement((volatile LONG *)&start[-4]);
      goto LABEL_13;
    }
    v8 = v4->mark;
    second = v4->curr;
  }
  else
  {
    v8 = v4->curr;
    second = v4->mark;
  }
  v9 = (const unsigned __int16 *)PStringBase<char>::substring(v5, &result, 0, v8 - 1);
  PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)start, v9);
  v10 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  v11 = (const unsigned __int16 *)PStringBase<char>::substring(v5, (PStringBase<char> *)&start, v8, second - 1);
  PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)middle, v11);
  v12 = start - 5;
  if ( !InterlockedDecrement((volatile LONG *)&start[-4]) && v12 )
    (*(void (__thiscall **)(_DWORD, _DWORD))&v12->m_charbuffer->m_data[0])(v12, 1);
  v13 = v4->vfptr->GetStrLen(v4);
  v14 = (const unsigned __int16 *)PStringBase<char>::substring(v5, (PStringBase<char> *)&start, second, v13);
  PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)end, v14);
  v15 = start - 5;
  v16 = InterlockedDecrement((volatile LONG *)&start[-4]);
LABEL_13:
  if ( !v16 )
  {
    if ( v15 )
      (*(void (__thiscall **)(_DWORD, _DWORD))&v15->m_charbuffer->m_data[0])(v15, 1);
  }
  return 1;
}

//----- (0040C2F0) --------------------------------------------------------  // acclient.c:72067
char __cdecl template_change_extension<char>(PStringBase<char> *filename, PStringBase<char> *new_extension)
{
  PStringBase<char> *v2; // edi@1
  PStringBase<char> v3; // eax@3
  unsigned int v4; // ecx@3
  int v5; // esi@4
  char v6[4]; // ecx@6
  char v7; // al@6
  const char **v8; // esi@9
  PSRefBufferCharData<char> *v9; // ecx@9
  int v10; // eax@9
  int v11; // ecx@14
  PStringBaseIter<char> iter; // [sp+8h] [bp-10h]@1

  v2 = filename;
  iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
  iter.pstring_ptr = filename;
  iter.curr = 0;
  iter.mark = 0;
  if ( template_find_extension<char>(&iter) )
    PStringBaseIter<char>::Truncate(&iter);
  v3.m_charbuffer = v2->m_charbuffer;
  v4 = *(_DWORD *)&v2->m_charbuffer[-1].m_data[12];
  if ( v4 - 2 < v4 )
    v5 = (int)((char *)v3.m_charbuffer + v4 - 2);
  else
    v5 = (int)((char *)v3.m_charbuffer + v4 - 1);
  *(_DWORD *)v6 = "\\/:";
  v7 = 92;
  do
  {
    if ( v7 == *(_BYTE *)v5 )
      return 0;
    v7 = *(_BYTE *)((*(_DWORD *)v6)++ + 1);
  }
  while ( v7 );
  v8 = (const char **)new_extension;
  v9 = new_extension->m_charbuffer;
  v10 = *(_DWORD *)&new_extension->m_charbuffer[-1].m_data[12];
  if ( v10 != 1 )
  {
    if ( !v10 )
      v9 = (PSRefBufferCharData<char> *)((char *)v9 - 1);
    if ( v9->m_data[0] != 46 )
    {
      LOBYTE(filename) = 46;
      PStringBase<char>::append_n_chars(v2, (const char *)&filename, 1u);
    }
  }
  v11 = *((_DWORD *)*v8 - 1);
  if ( v11 != 1 )
    PStringBase<char>::append_n_chars(v2, *v8, v11 - 1);
  return 1;
}
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (0040C3C0) --------------------------------------------------------  // acclient.c:72124
char __cdecl template_strip_directory<char>(PStringBase<char> *filename)
{
  int v1; // eax@1
  PStringBaseIter<char> iter; // [sp+0h] [bp-10h]@1

  iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
  iter.pstring_ptr = filename;
  iter.curr = 0;
  iter.mark = 0;
  v1 = template_strcspn<char>(filename, "\\/:", 1);
  if ( v1 >= 0 )
  {
    PStringBaseIter_Common<char>::Next((PStringBaseIter_Common<char> *)&iter.vfptr, v1 + 1);
    PStringBaseIter<char>::Behead(&iter);
  }
  return 1;
}
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (0040C420) --------------------------------------------------------  // acclient.c:72144
char __cdecl template_get_directory<char>(PStringBase<char> *out_dir, PStringBase<char> *filename)
{
  int v2; // eax@1
  char result; // al@2
  PSRefBufferCharData<char> *v4; // eax@3
  int v5; // esi@4
  volatile LONG *v6; // ST00_4@7
  PStringBaseIter_Const<char> iter; // [sp+0h] [bp-10h]@1

  iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
  iter.pstring_ptr = filename;
  iter.curr = 0;
  iter.mark = 0;
  v2 = template_strcspn<char>(filename, "\\/:", 1);
  if ( v2 < 0 )
  {
    v4 = out_dir->m_charbuffer;
    if ( out_dir->m_charbuffer != PStringBase<char>::s_NullBuffer.m_charbuffer )
    {
      v5 = (int)&v4[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) )
      {
        if ( v5 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      }
      v6 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
      out_dir->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement(v6);
    }
    result = 1;
  }
  else
  {
    PStringBaseIter_Common<char>::Next((PStringBaseIter_Common<char> *)&iter.vfptr, v2 + 1);
    iter.mark = iter.curr;
    iter.curr = 0;
    PStringBaseIter_Common<char>::GetSubString((PStringBaseIter_Common<char> *)&iter.vfptr, out_dir);
    result = 1;
  }
  return result;
}
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (0040C4E0) --------------------------------------------------------  // acclient.c:72188
PStringBase<char> *__cdecl template_get_extension<char>(PStringBase<char> *result, PStringBase<char> *filename)
{
  PStringBase<char> *v2; // eax@2
  volatile LONG *v3; // ST00_4@3
  PStringBaseIter<char> iter; // [sp+4h] [bp-10h]@1

  iter.pstring_ptr = filename;
  iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
  iter.curr = 0;
  iter.mark = 0;
  if ( template_find_extension<char>(&iter) )
  {
    PStringBaseIter_Common<char>::GetSubString((PStringBaseIter_Common<char> *)&iter.vfptr, result);
    v2 = result;
  }
  else
  {
    v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    result->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v3);
    v2 = result;
  }
  return v2;
}
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (0040C540) --------------------------------------------------------  // acclient.c:72215
char __thiscall PStringBaseIter<char>::Insert(PStringBaseIter<char> *this, PStringBase<char> *s)
{
  const char **v2; // ebx@1
  PStringBaseIter<char> *v3; // esi@1
  PSRefBufferCharData<char> *v4; // ebp@2
  PSRefBufferCharData<char> **v5; // edi@2
  PSRefBufferCharData<char> *v6; // eax@2
  int v7; // ebx@3
  volatile LONG *v8; // ST04_4@6
  int v9; // ecx@9
  const char *v10; // ecx@11
  unsigned int v11; // ecx@14
  unsigned int v12; // eax@14

  v2 = (const char **)s;
  v3 = this;
  if ( *(_DWORD *)&s->m_charbuffer[-1].m_data[12] != 1 )
  {
    v4 = this->pstring_ptr->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v4[-1]);
    v5 = &v3->pstring_ptr->m_charbuffer;
    v6 = *v5;
    if ( *v5 != PStringBase<char>::s_NullBuffer.m_charbuffer )
    {
      v7 = (int)&v6[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      v8 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
      *v5 = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement(v8);
      v2 = (const char **)s;
    }
    if ( v3->curr )
      PStringBase<char>::append_n_chars(v3->pstring_ptr, v4->m_data, v3->curr);
    v9 = *((_DWORD *)*v2 - 1);
    if ( v9 != 1 )
      PStringBase<char>::append_n_chars(v3->pstring_ptr, *v2, v9 - 1);
    v10 = &v4->m_data[v3->curr];
    if ( v10 && *v10 )
      PStringBase<char>::append_n_chars(v3->pstring_ptr, v10, strlen(v10));
    v11 = v3->mark;
    v12 = v3->curr;
    if ( v11 >= v12 )
      v3->mark = *((_DWORD *)*v2 - 1) + v11 - 1;
    v3->curr = *((_DWORD *)*v2 - 1) + v12 - 1;
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v4 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&v4[-2].m_data[12])(&v4[-2].m_data[12], 1);
  }
  return 1;
}

//----- (0040C640) --------------------------------------------------------  // acclient.c:72267
char __thiscall PStringBaseIter<char>::Replace(PStringBaseIter<char> *this, PStringBase<char> *s)
{
  PStringBaseIter<char> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // ecx@1
  unsigned int v5; // ebx@2
  const char *v6; // ebp@4
  PSRefBufferCharData<char> **v7; // edi@4
  PSRefBufferCharData<char> *v8; // eax@4
  int v9; // ebx@5
  volatile LONG *v10; // ST04_4@8
  unsigned int v11; // edi@9
  int v12; // ecx@11
  unsigned int v13; // ecx@13
  int v14; // eax@13
  bool v15; // cf@16
  int v16; // ecx@16
  unsigned int v17; // ecx@21
  int v18; // eax@21
  int v19; // edx@21
  unsigned int end; // [sp+10h] [bp-8h]@2
  unsigned int start; // [sp+14h] [bp-4h]@2

  v2 = this;
  v3 = this->curr;
  v4 = this->mark;
  if ( v3 >= v4 )
  {
    start = v4;
    end = v3;
    v5 = v3;
  }
  else
  {
    v5 = v4;
    start = v3;
    end = v4;
  }
  v6 = (const char *)v2->pstring_ptr->m_charbuffer;
  InterlockedIncrement((volatile LONG *)v6 - 4);
  v7 = &v2->pstring_ptr->m_charbuffer;
  v8 = *v7;
  if ( *v7 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v9 = (int)&v8[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v8[-1]) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v10 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    *v7 = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v10);
    v5 = end;
  }
  v11 = start;
  if ( start )
    PStringBase<char>::append_n_chars(v2->pstring_ptr, v6, start);
  v12 = *(_DWORD *)&s->m_charbuffer[-1].m_data[12];
  if ( v12 != 1 )
    PStringBase<char>::append_n_chars(v2->pstring_ptr, s->m_charbuffer->m_data, v12 - 1);
  v13 = *((_DWORD *)v6 - 1);
  v14 = (int)&v6[v13 - 1];
  if ( v5 < v13 )
    v14 = (int)&v6[v5];
  if ( *(_BYTE *)v14 )
  {
    v15 = v5 < v13;
    v16 = (int)&v6[v13 - 1];
    if ( v15 )
      v16 = (int)&v6[v5];
    if ( v16 && *(_BYTE *)v16 )
    {
      PStringBase<char>::append_n_chars(v2->pstring_ptr, (const char *)v16, strlen((const char *)v16));
      v11 = start;
    }
  }
  v17 = v2->curr;
  v18 = *(_DWORD *)&s->m_charbuffer[-1].m_data[12] - 1;
  v19 = v5 - v11;
  if ( v17 == v5 )
    v2->curr = v18 + v17 - v19;
  else
    v2->mark += v18 - v19;
  if ( !InterlockedDecrement((volatile LONG *)v6 - 4) && v6 != (const char *)20 )
    (*(void (__thiscall **)(const char *, signed int))*((void (__thiscall ***)(_DWORD, _DWORD))v6 - 5))(v6 - 20, 1);
  return 1;
}

//----- (0040C790) --------------------------------------------------------  // acclient.c:72354
char __cdecl PSUtils::explode(const char *i_string, unsigned int i_len, PStringBaseArray<char> *o_array)
{
  unsigned int v3; // ebx@1
  const char *v4; // esi@1
  void *v5; // edi@1
  const char *v6; // ebp@1
  int v7; // edi@2

  v3 = i_len;
  v4 = i_string;
  v5 = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v6 = &i_string[i_len];
  i_string = (const char *)PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( v4 < v6 )
  {
    do
    {
      v7 = PStringBase<char>::sprintf((PStringBase<char> *)&i_string, "%.*s", v3, v4);
      v3 -= v7;
      SmartArray<PStringBase<char>,1>::AddToEnd(
        (SmartArray<PStringBase<char>,1> *)&o_array->m_data,
        (PStringBase<char> *)&i_string);
      v4 += v7 + 1;
    }
    while ( v4 < v6 );
    v5 = (void *)i_string;
  }
  if ( !InterlockedDecrement((volatile LONG *)v5 - 4) && v5 != (void *)20 )
    (**((void (__thiscall ***)(_DWORD, _DWORD))v5 - 5))((char *)v5 - 20, 1);
  return 1;
}

//----- (0040C810) --------------------------------------------------------  // acclient.c:72388
void __cdecl PSUtils::path_append(PStringBase<char> *o_path, PStringBase<char> *i_suffix)
{
  const char **v2; // ebx@1
  PSRefBufferCharData<char> **v3; // eax@3
  PStringBase<char> *v4; // esi@3
  PSRefBufferCharData<char> *v5; // eax@7
  int v6; // ecx@7
  unsigned int v7; // edx@9
  int v8; // eax@10
  const char *v9; // eax@13
  int v10; // ecx@17

  v2 = (const char **)i_suffix;
  if ( *(_DWORD *)&i_suffix->m_charbuffer[-1].m_data[12] != 1 )
  {
    if ( !(_S73 & 1) )
    {
      _S73 |= 1u;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&i_suffix, "\\/");
      DirSeps.m_charbuffer = *v3;
      InterlockedIncrement((volatile LONG *)&DirSeps.m_charbuffer[-1]);
      v4 = i_suffix - 5;
      if ( !InterlockedDecrement((volatile LONG *)&i_suffix[-4]) && v4 )
        (*(void (__thiscall **)(PStringBase<char> *, signed int))&v4->m_charbuffer->m_data[0])(v4, 1);
      atexit(_E74_6);
    }
    v5 = o_path->m_charbuffer;
    v6 = *(_DWORD *)&o_path->m_charbuffer[-1].m_data[12];
    if ( v6 == 1 )
    {
      PStringBase<char>::set(o_path, "./");
    }
    else
    {
      v7 = *(_DWORD *)&v5[-1].m_data[12];
      if ( v7 - 2 < v7 )
        v8 = (int)((char *)v5 + v7 - 2);
      else
        v8 = (int)((char *)v5 + v6 - 1);
      if ( !_strchr(DirSeps.m_charbuffer->m_data, *(_BYTE *)v8) )
      {
        v9 = *v2;
        if ( !*((_DWORD *)*v2 - 1) )
          --v9;
        if ( !_strchr(DirSeps.m_charbuffer->m_data, *v9) )
        {
          LOBYTE(i_suffix) = 47;
          PStringBase<char>::append_n_chars(o_path, (const char *)&i_suffix, 1u);
        }
      }
    }
    v10 = *((_DWORD *)*v2 - 1);
    if ( v10 != 1 )
      PStringBase<char>::append_n_chars(o_path, *v2, v10 - 1);
  }
}

//----- (0040C920) --------------------------------------------------------  // acclient.c:72446
void __cdecl PSUtils::path_append(PStringBase<unsigned short> *o_path, PStringBase<unsigned short> *i_suffix)
{
  const unsigned __int16 **v2; // ebx@1
  PStringBase<char> *v3; // eax@3
  PStringBase<unsigned short> *v4; // esi@3
  PSRefBufferCharData<unsigned short> *v5; // eax@7
  int v6; // ecx@7
  unsigned int v7; // edx@9
  int v8; // eax@10
  wchar_t *v9; // eax@13
  int v10; // ecx@17

  v2 = (const unsigned __int16 **)i_suffix;
  if ( *(_DWORD *)&i_suffix->m_charbuffer[-1].m_data[14] != 1 )
  {
    if ( !(dword_8367E0 & 1) )
    {
      dword_8367E0 |= 1u;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&i_suffix, "\\/");
      PStringBase<char>::to_wpstring(v3, &DirSeps_0, 0);
      v4 = i_suffix - 5;
      if ( !InterlockedDecrement((volatile LONG *)&i_suffix[-4]) && v4 )
        (*(void (__thiscall **)(PStringBase<unsigned short> *, signed int))&v4->m_charbuffer->m_data[0])(v4, 1);
      atexit(func);
    }
    v5 = o_path->m_charbuffer;
    v6 = *(_DWORD *)&o_path->m_charbuffer[-1].m_data[14];
    if ( v6 == 1 )
    {
      PStringBase<unsigned short>::set(o_path, L"./");
    }
    else
    {
      v7 = *(_DWORD *)&v5[-1].m_data[14];
      if ( v7 - 2 < v7 )
        v8 = (int)((char *)v5 + 2 * (v7 - 2));
      else
        v8 = (int)((char *)v5 + 2 * v6 - 2);
      if ( !_wcschr(DirSeps_0.m_charbuffer->m_data, *(_WORD *)v8) )
      {
        v9 = (wchar_t *)*v2;
        if ( !*((_DWORD *)*v2 - 1) )
          --v9;
        if ( !_wcschr(DirSeps_0.m_charbuffer->m_data, *v9) )
        {
          i_suffix = (PStringBase<unsigned short> *)47;
          PStringBase<unsigned short>::append_n_chars(o_path, (const unsigned __int16 *)&i_suffix, 1u);
        }
      }
    }
    v10 = *((_DWORD *)*v2 - 1);
    if ( v10 != 1 )
      PStringBase<unsigned short>::append_n_chars(o_path, *v2, v10 - 1);
  }
}

//----- (0040CA40) --------------------------------------------------------  // acclient.c:72503
char __cdecl PSUtils::remove_extension(PStringBase<char> *filename)
{
  int v2; // [sp+0h] [bp-10h]@1
  int v3; // [sp+4h] [bp-Ch]@1
  int v4; // [sp+8h] [bp-8h]@1
  PStringBase<char> *v5; // [sp+Ch] [bp-4h]@1

  v5 = filename;
  v2 = (int)&PStringBaseIter_Const<char>::vftable;
  v3 = 0;
  v4 = 0;
  if ( template_find_extension<char>((PStringBaseIter<char> *)&v2) )
    PStringBaseIter<char>::Truncate((PStringBaseIter<char> *)&v2);
  return 1;
}
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (0040CAA0) --------------------------------------------------------  // acclient.c:72521
PStringBase<char> *__cdecl PSUtils::get_extension(PStringBase<char> *result, PStringBase<char> *filename)
{
  template_get_extension<char>(result, filename);
  return result;
}

//----- (0040CAC0) --------------------------------------------------------  // acclient.c:72528
PStringBase<char> *__cdecl PSUtils::stringify_buffer(PStringBase<char> *result, SmartBuffer *i_buffer)
{
  unsigned int v2; // esi@1
  unsigned int v3; // eax@1
  int v4; // ebx@1
  unsigned int v5; // eax@1
  const char *v6; // eax@1
  bool v7; // cf@1
  PSRefBufferCharData<char> *v8; // esi@1
  unsigned int v9; // eax@2
  int v10; // ebp@2
  unsigned int v11; // ebx@3
  int v12; // eax@3
  int v13; // edi@6
  int v14; // eax@6
  char *v15; // edx@6
  char v16; // cl@7
  unsigned int v17; // ebp@13
  int v18; // eax@13
  int v19; // edi@16
  int v20; // eax@16
  char *v21; // edx@16
  char v22; // cl@17
  int v23; // esi@23
  char Source[4]; // [sp+Ch] [bp-24h]@2
  PStringBase<char> out; // [sp+10h] [bp-20h]@1
  const char *i; // [sp+14h] [bp-1Ch]@1
  const char *end; // [sp+18h] [bp-18h]@1
  const char aIntToHexMapping[17]; // [sp+1Ch] [bp-14h]@1

  *(_DWORD *)&aIntToHexMapping[4] = 926299444;
  *(_DWORD *)aIntToHexMapping = *(_DWORD *)"0123456789ABCDEF";
  aIntToHexMapping[16] = 0;
  *(_DWORD *)&aIntToHexMapping[8] = 1111570744;
  *(_DWORD *)&aIntToHexMapping[12] = 1178944579;
  v2 = SmartBuffer::GetBuffer(i_buffer);
  v3 = SmartBuffer::GetSize(i_buffer);
  out.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v4 = v2 + v3;
  end = (const char *)(v2 + v3);
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v5 = SmartBuffer::GetSize(i_buffer);
  PStringBase<char>::allocate(&out, 2 * v5);
  v6 = (const char *)v2;
  v7 = v2 < v4;
  v8 = out.m_charbuffer;
  i = v6;
  if ( v7 )
  {
    do
    {
      v9 = *v6;
      v10 = v9 & 0xF;
      Source[0] = aIntToHexMapping[v9 >> 4];
      if ( Source[0] )
      {
        v11 = *(_DWORD *)&v8[-1].m_data[12];
        v12 = v11 + 1;
        if ( *(_DWORD *)&v8[-1].m_data[0] != 1 || (unsigned int)v12 > *(_DWORD *)&v8[-1].m_data[4] )
        {
          v13 = (int)&v8[-2].m_data[12];
          PStringBase<char>::allocate_ref_buffer(&out, v11);
          v8 = out.m_charbuffer;
          v14 = v13 + 20;
          v15 = (char *)&out.m_charbuffer[-1] + -v13 - 4;
          do
          {
            v16 = *(_BYTE *)v14;
            v15[v14] = *(_BYTE *)v14;
            ++v14;
          }
          while ( v16 );
          if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) && v13 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
        }
        else
        {
          *(_DWORD *)&v8[-1].m_data[12] = v12;
          *(_DWORD *)&v8[-1].m_data[8] = -1;
        }
        _strncpy((char *)v8 + v11 - 1, Source, 1u);
        v4 = (int)end;
        v8->m_data[*(_DWORD *)&v8[-1].m_data[12] - 1] = 0;
      }
      Source[0] = aIntToHexMapping[v10];
      if ( Source[0] )
      {
        v17 = *(_DWORD *)&v8[-1].m_data[12];
        v18 = v17 + 1;
        if ( *(_DWORD *)&v8[-1].m_data[0] != 1 || (unsigned int)v18 > *(_DWORD *)&v8[-1].m_data[4] )
        {
          v19 = (int)&v8[-2].m_data[12];
          PStringBase<char>::allocate_ref_buffer(&out, v17);
          v8 = out.m_charbuffer;
          v20 = v19 + 20;
          v21 = (char *)&out.m_charbuffer[-1] + -v19 - 4;
          do
          {
            v22 = *(_BYTE *)v20;
            v21[v20] = *(_BYTE *)v20;
            ++v20;
          }
          while ( v22 );
          if ( !InterlockedDecrement((volatile LONG *)(v19 + 4)) && v19 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
        }
        else
        {
          *(_DWORD *)&v8[-1].m_data[12] = v18;
          *(_DWORD *)&v8[-1].m_data[8] = -1;
        }
        _strncpy((char *)v8 + v17 - 1, Source, 1u);
        v8->m_data[*(_DWORD *)&v8[-1].m_data[12] - 1] = 0;
      }
      v6 = i++ + 1;
    }
    while ( (unsigned int)i < v4 );
  }
  result->m_charbuffer = v8;
  InterlockedIncrement((volatile LONG *)&v8[-1]);
  v23 = (int)&v8[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v23 + 4)) && v23 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
  return result;
}

//----- (0040CCC0) --------------------------------------------------------  // acclient.c:72655
char __cdecl PSUtils::linewrap_string(PStringBase<char> *s, unsigned int width)
{
  PStringBase<char> *v2; // esi@1
  PStringBase<char> v3; // ecx@1
  int v4; // ebp@1
  unsigned int v5; // edi@1
  int v6; // ebx@2
  volatile LONG *v7; // ST08_4@5
  unsigned int v8; // ebx@6
  PStringBase<char> v9; // eax@7
  int v10; // ecx@7
  int v11; // edi@10
  PStringBase<char> v12; // edx@10
  int v13; // ecx@10
  char v14; // al@11
  PStringBase<char> copy; // [sp+10h] [bp-8h]@1
  unsigned int v17; // [sp+14h] [bp-4h]@7

  v2 = s;
  copy.m_charbuffer = s->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&s->m_charbuffer[-1]);
  v3.m_charbuffer = v2->m_charbuffer;
  v4 = *(_DWORD *)&v2->m_charbuffer[-1].m_data[12] - 1;
  v5 = v4 + v4 / width;
  if ( v2->m_charbuffer != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v6 = (int)&v3.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3.m_charbuffer[-1]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v2->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v7);
  }
  PStringBase<char>::allocate(v2, v5);
  v8 = 0;
  if ( v4 )
  {
    do
    {
      PStringBase<char>::append_n_chars(v2, (const char *)copy.m_charbuffer + v8, width);
      v9.m_charbuffer = v2->m_charbuffer;
      LOBYTE(s) = 10;
      v17 = *(_DWORD *)&v9.m_charbuffer[-1].m_data[12];
      v10 = v17 + 1;
      if ( *(_DWORD *)&v9.m_charbuffer[-1].m_data[0] != 1
        || (unsigned int)v10 > *(_DWORD *)&v9.m_charbuffer[-1].m_data[4] )
      {
        v11 = (int)&v9.m_charbuffer[-2].m_data[12];
        PStringBase<char>::allocate_ref_buffer(v2, v17);
        v12.m_charbuffer = v2->m_charbuffer;
        v13 = v11 + 20;
        do
        {
          v14 = *(_BYTE *)v13;
          (v12.m_charbuffer++)->m_data[0] = *(_BYTE *)v13++;
        }
        while ( v14 );
        if ( !InterlockedDecrement((volatile LONG *)(v11 + 4)) && v11 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      }
      else
      {
        *(_DWORD *)&v9.m_charbuffer[-1].m_data[12] = v10;
        *(_DWORD *)&v2->m_charbuffer[-1].m_data[8] = -1;
      }
      _strncpy((char *)v2->m_charbuffer + v17 - 1, (const char *)&s, 1u);
      v8 += width;
      v2->m_charbuffer->m_data[*(_DWORD *)&v2->m_charbuffer[-1].m_data[12] - 1] = 0;
    }
    while ( v8 < v4 );
  }
  if ( !InterlockedDecrement((volatile LONG *)&copy.m_charbuffer[-1])
    && copy.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&copy.m_charbuffer[-2].m_data[12])(
      &copy.m_charbuffer[-2].m_data[12],
      1);
  return 1;
}

//----- (0040CE20) --------------------------------------------------------  // acclient.c:72735
char __cdecl PSUtils::widify(PStringBase<unsigned short> *dest, PStringBase<char> *org)
{
  PStringBase<unsigned short> *v2; // edi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@1
  int v4; // esi@2
  PSRefBufferCharData<unsigned short> *v5; // edi@5
  char *v6; // esi@6
  PStringBase<unsigned short> result; // [sp+10h] [bp-4h]@1

  v2 = PStringBase<char>::to_wpstring(org, &result, 0);
  v3 = dest->m_charbuffer;
  if ( dest->m_charbuffer != v2->m_charbuffer )
  {
    v4 = (int)&v3[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1].m_data[8]) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = v2->m_charbuffer;
    dest->m_charbuffer = v5;
    InterlockedIncrement((volatile LONG *)&v5[-1].m_data[8]);
  }
  v6 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0040CEA0) --------------------------------------------------------  // acclient.c:72762
PStringBase<unsigned short> *__cdecl PSUtils::widify(PStringBase<unsigned short> *result, PStringBase<char> *org)
{
  PSRefBufferCharData<unsigned short> *v2; // esi@1
  volatile LONG *v3; // ST04_4@1
  int v4; // esi@1
  PStringBase<unsigned short> temp; // [sp+0h] [bp-4h]@1

  temp.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  PSUtils::widify(&temp, org);
  v2 = temp.m_charbuffer;
  v3 = (volatile LONG *)&temp.m_charbuffer[-1].m_data[8];
  result->m_charbuffer = temp.m_charbuffer;
  InterlockedIncrement(v3);
  v4 = (int)&v2[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  return result;
}

//----- (0040CF00) --------------------------------------------------------  // acclient.c:72783
char __cdecl template_change_directory<char>(PStringBase<char> *filename, PStringBase<char> *directory)
{
  PStringBase<char> *v2; // edi@1
  int v3; // eax@2
  unsigned int v4; // eax@3
  char v5; // al@5
  char v6[4]; // edx@5
  char v7; // cl@5
  int v8; // eax@10
  unsigned int v9; // esi@11
  PStringBase<char> *v10; // eax@15
  PStringBase<char> *v11; // esi@15
  void *v12; // eax@17
  int v13; // esi@21
  char v15; // [sp+13h] [bp-21h]@1
  PStringBaseIter<char> iter; // [sp+14h] [bp-20h]@10
  PStringBaseIter_Const<char> dir_iter; // [sp+24h] [bp-10h]@2

  v2 = directory;
  v15 = 1;
  if ( *(_DWORD *)&directory->m_charbuffer[-1].m_data[12] != 1 )
  {
    dir_iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
    dir_iter.pstring_ptr = directory;
    dir_iter.curr = 0;
    dir_iter.mark = 0;
    v3 = PStringBaseIter_Const<char>::vftable(&dir_iter);
    if ( (unsigned int)v3 >= 1 )
      v4 = v3 - 1;
    else
      v4 = 0;
    dir_iter.curr = v4;
    v5 = dir_iter.vfptr->IndexToChar((PStringBaseIter_Common<char> *)&dir_iter, v4);
    *(_DWORD *)v6 = "\\/:";
    v7 = 92;
    while ( v7 != v5 )
    {
      v7 = *(_BYTE *)((*(_DWORD *)v6)++ + 1);
      if ( !v7 )
        goto LABEL_10;
    }
  }
  v15 = 0;
LABEL_10:
  iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
  iter.pstring_ptr = filename;
  iter.curr = 0;
  iter.mark = 0;
  v8 = template_strcspn<char>(filename, "\\/:", 1);
  if ( v8 < 0 )
  {
    iter.curr = 0;
    PStringBaseIter<char>::Insert(&iter, v2);
    if ( !v15 )
      return 1;
    v12 = operator new[](0x24u);
    if ( v12 )
    {
      v11 = (PStringBase<char> *)((char *)v12 + 20);
      *((_DWORD *)v12 + 1) = 1;
      *(_DWORD *)v12 = AC1Legacy::PSRefBuffer<char>::vftable;
      *((_DWORD *)v12 + 4) = 1;
      *((_DWORD *)v12 + 2) = 1;
      *((_DWORD *)v12 + 3) = -1;
      LOBYTE(v11->m_charbuffer) = 0;
      v11[-1].m_charbuffer = (PSRefBufferCharData<char> *)2;
      directory = (PStringBase<char> *)((char *)v12 + 20);
      v11[-3].m_charbuffer = (PSRefBufferCharData<char> *)16;
    }
    else
    {
      v11 = directory;
    }
    LOBYTE(v11->m_charbuffer) = 47;
    BYTE1(v11->m_charbuffer) = 0;
    PStringBaseIter<char>::Insert(&iter, (PStringBase<char> *)&directory);
    goto LABEL_21;
  }
  PStringBaseIter_Common<char>::Next((PStringBaseIter_Common<char> *)&iter.vfptr, v8);
  LOBYTE(directory) = iter.vfptr->IndexToChar((PStringBaseIter_Common<char> *)&iter, iter.curr);
  v9 = iter.curr + 1;
  if ( v9 <= iter.vfptr->GetStrLen(&iter) )
    iter.curr = v9;
  else
    iter.curr = iter.vfptr->GetStrLen(&iter);
  PStringBaseIter<char>::Behead(&iter);
  PStringBaseIter<char>::Insert(&iter, v2);
  if ( v15 )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&directory, (char)directory);
    PStringBaseIter<char>::Insert(&iter, v10);
    v11 = directory;
LABEL_21:
    v13 = (int)&v11[-5];
    if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) && v13 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  }
  return 1;
}
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);
// 7CA074: using guessed type int (__thiscall *AC1Legacy::PSRefBuffer<char>::vftable[2])(void *, char);

//----- (0040D0B0) --------------------------------------------------------  // acclient.c:72886
void __thiscall List<PStringBase<unsigned short>>::flush(List<PStringBase<unsigned short> > *this)
{
  List<PStringBase<unsigned short> > *v1; // edi@1
  char *v2; // esi@3
  PStringBase<unsigned short> retval; // [sp+10h] [bp-4h]@3

  v1 = this;
  while ( v1->_head )
  {
    retval.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    List<PStringBase<unsigned short>>::pop_front(v1, &retval);
    v2 = (char *)&retval.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&retval.m_charbuffer[-1].m_data[8]) )
    {
      if ( v2 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
    }
  }
}

//----- (0040D110) --------------------------------------------------------  // acclient.c:72908
List<PStringBase<unsigned short> > *__thiscall List<PStringBase<unsigned short>>::vector_deleting_destructor(List<PStringBase<unsigned short> > *this, unsigned int a2)
{
  List<PStringBase<unsigned short> > *v2; // esi@1

  v2 = this;
  this->vfptr = (List<PStringBase<unsigned short> >Vtbl *)&List<PStringBase<unsigned short>>::vftable;
  List<PStringBase<unsigned short>>::flush(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 794488: using guessed type int (__thiscall *List<PStringBase<unsigned short>>::vftable)(void *, char);

//----- (0040D140) --------------------------------------------------------  // acclient.c:72922
char __cdecl PSUtils::find_files(PStringBase<char> *_filename, List<PStringBase<char> > *_file_list, List<PStringBase<char> > *_dir_list, bool _recursive)
{
  __int32 v4; // eax@1
  bool v5; // al@4
  char *v6; // esi@5
  char *v7; // esi@14
  char *v8; // esi@17
  char *v9; // esi@20
  char *v10; // esi@25
  char *v11; // esi@28
  char *v12; // esi@31
  PStringBase<char> new_dir; // [sp+10h] [bp-154h]@5
  PStringBase<char> filename; // [sp+14h] [bp-150h]@2
  PStringBase<char> dir; // [sp+18h] [bp-14Ch]@1
  PStringBase<char> filename_wildcard; // [sp+1Ch] [bp-148h]@1
  PStringBase<char> new_filename_wildcard; // [sp+20h] [bp-144h]@14
  PStringBase<char> dir_wildcard; // [sp+24h] [bp-140h]@1
  int handle; // [sp+28h] [bp-13Ch]@1
  PStringBaseIter_Const<char> w_iter; // [sp+2Ch] [bp-138h]@4
  PStringBaseIter_Const<char> s_iter; // [sp+3Ch] [bp-128h]@4
  _finddata_t find_data; // [sp+4Ch] [bp-118h]@1

  dir.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  template_get_directory<char>(&dir, _filename);
  PStringBase<char>::PStringBase<char>(&dir_wildcard, "*.*");
  template_change_directory<char>(&dir_wildcard, &dir);
  filename_wildcard.m_charbuffer = _filename->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&filename_wildcard.m_charbuffer[-1]);
  template_strip_directory<char>(&filename_wildcard);
  v4 = __findfirst(dir_wildcard.m_charbuffer->m_data, &find_data);
  handle = v4;
  if ( v4 != -1 )
  {
    do
    {
      PStringBase<char>::PStringBase<char>(&filename, find_data.name);
      if ( __stricmp(filename.m_charbuffer->m_data, ignore1.m_charbuffer->m_data)
        && __stricmp(filename.m_charbuffer->m_data, ignore2.m_charbuffer->m_data) )
      {
        s_iter.pstring_ptr = &filename;
        s_iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
        w_iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
        s_iter.curr = 0;
        s_iter.mark = 0;
        w_iter.pstring_ptr = &filename_wildcard;
        w_iter.curr = 0;
        w_iter.mark = 0;
        v5 = wildcard_match_iter<char>(&s_iter, &w_iter);
        w_iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
        s_iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
        if ( v5 )
        {
          new_dir.m_charbuffer = filename.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&filename.m_charbuffer[-1]);
          template_change_directory<char>(&new_dir, &dir);
          List<PStringBase<char>>::push_back(_file_list, &new_dir);
          v6 = &new_dir.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&new_dir.m_charbuffer[-1]) )
          {
            if ( v6 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
          }
        }
        if ( (find_data.attrib >> 4) & 1 && (_dir_list || _recursive) )
        {
          new_dir.m_charbuffer = filename.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&filename.m_charbuffer[-1]);
          template_change_directory<char>(&new_dir, &dir);
          if ( _dir_list )
            List<PStringBase<char>>::push_back(_dir_list, &new_dir);
          if ( _recursive )
          {
            new_filename_wildcard.m_charbuffer = filename_wildcard.m_charbuffer;
            InterlockedIncrement((volatile LONG *)&filename_wildcard.m_charbuffer[-1]);
            template_change_directory<char>(&new_filename_wildcard, &new_dir);
            PSUtils::find_files(&new_filename_wildcard, _file_list, _dir_list, _recursive);
            v7 = &new_filename_wildcard.m_charbuffer[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&new_filename_wildcard.m_charbuffer[-1]) )
            {
              if ( v7 )
                (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
            }
          }
          v8 = &new_dir.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&new_dir.m_charbuffer[-1]) && v8 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
        }
      }
      v9 = &filename.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&filename.m_charbuffer[-1]) && v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    }
    while ( __findnext(handle, &find_data) != -1 );
    v4 = handle;
  }
  __findclose(v4);
  v10 = &filename_wildcard.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&filename_wildcard.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  v11 = &dir_wildcard.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&dir_wildcard.m_charbuffer[-1]) && v11 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
  v12 = &dir.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&dir.m_charbuffer[-1]) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  return 1;
}
// 794478: using guessed type void *PStringBaseIter_Common<unsigned short>::vftable;
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (0040D440) --------------------------------------------------------  // acclient.c:73034
char __cdecl PSUtils::narrowify(PStringBase<char> *dest, PStringBase<unsigned short> *org)
{
  PSRefBufferCharData<char> *v2; // eax@1
  PSRefBufferCharData<char> *v3; // edi@1
  int v4; // esi@2
  PStringBase<char> result; // [sp+10h] [bp-4h]@1

  PStringBase<unsigned short>::to_spstring(org, &result, 0);
  v2 = dest->m_charbuffer;
  v3 = result.m_charbuffer;
  if ( dest->m_charbuffer != result.m_charbuffer )
  {
    v4 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    dest->m_charbuffer = v3;
    InterlockedIncrement((volatile LONG *)&v3[-1]);
  }
  if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v3 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&v3[-2].m_data[12])(&v3[-2].m_data[12], 1);
  return 1;
}

//----- (0040D4B0) --------------------------------------------------------  // acclient.c:73058
PStringBase<char> *__cdecl PSUtils::narrowify(PStringBase<char> *result, PStringBase<unsigned short> *org)
{
  PSRefBufferCharData<char> *v2; // esi@1
  volatile LONG *v3; // ST04_4@1
  int v4; // esi@1
  PStringBase<char> ret; // [sp+0h] [bp-4h]@1

  ret.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PSUtils::narrowify(&ret, org);
  v2 = ret.m_charbuffer;
  v3 = (volatile LONG *)&ret.m_charbuffer[-1];
  result->m_charbuffer = ret.m_charbuffer;
  InterlockedIncrement(v3);
  v4 = (int)&v2[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  return result;
}

//----- (0040D510) --------------------------------------------------------  // acclient.c:73079
const unsigned __int16 *__thiscall PStringBase<unsigned short>::replace(PStringBase<unsigned short> *this, PStringBase<unsigned short> *search, PStringBase<unsigned short> *str)
{
  PStringBase<unsigned short> *v3; // ebp@1
  char **v4; // ebx@1
  PSRefBufferCharData<unsigned short> *v5; // ST10_4@1
  PSRefBufferCharData<unsigned short> *v6; // ST0C_4@1
  wchar_t *v7; // edi@1
  int v8; // ebx@8
  const unsigned __int16 *result; // eax@11
  PSRefBuffer<unsigned short> *v10; // esi@12
  unsigned int v11; // ST10_4@12
  int v12; // ebx@12
  unsigned int v13; // ebp@12
  int v14; // edi@12
  signed int v15; // esi@13
  wchar_t *v16; // ebx@13
  const unsigned __int16 *p; // [sp+10h] [bp-14h]@1
  PSRefBuffer<unsigned short> *old_buffer; // [sp+14h] [bp-10h]@12
  _STL::vector<unsigned short const *,_STL::allocator<unsigned short const *> > matches; // [sp+18h] [bp-Ch]@1

  v3 = this;
  v4 = 0;
  v5 = search->m_charbuffer;
  v6 = this->m_charbuffer;
  matches._M_start = 0;
  matches._M_finish = 0;
  matches._M_end_of_storage._M_data = 0;
  v7 = _wcsstr(v6->m_data, v5->m_data);
  for ( p = v7; v7; p = v7 )
  {
    if ( v4 == (char **)matches._M_end_of_storage._M_data )
    {
      _STL::vector<unsigned char *,_STL::allocator<unsigned char *>>::_M_insert_overflow(
        (_STL::vector<unsigned char *,_STL::allocator<unsigned char *> > *)&matches,
        v4,
        (char *const *)&p,
        (_STL::__true_type *)&str,
        1u,
        1);
      v4 = (char **)matches._M_finish;
    }
    else
    {
      if ( v4 )
        *v4 = (char *)v7;
      ++v4;
      matches._M_finish = (const unsigned __int16 **)v4;
    }
    v7 = _wcsstr(&v7[*(_DWORD *)&search->m_charbuffer[-1].m_data[14] - 1], search->m_charbuffer->m_data);
  }
  v8 = (signed int)((char *)v4 - (char *)matches._M_start) >> 2;
  p = (const unsigned __int16 *)v8;
  if ( v8 )
  {
    v11 = v8 * (*(_DWORD *)&str->m_charbuffer[-1].m_data[14] - *(_DWORD *)&search->m_charbuffer[-1].m_data[14])
        + *(_DWORD *)&v3->m_charbuffer[-1].m_data[14]
        - 1;
    old_buffer = (PSRefBuffer<unsigned short> *)&v3->m_charbuffer[-1].m_data[6];
    v10 = old_buffer;
    PStringBase<unsigned short>::allocate_ref_buffer(v3, v11);
    v12 = (int)v3->m_charbuffer;
    v13 = 0;
    v14 = (int)v10->m_data;
    if ( p )
    {
      do
      {
        v15 = (signed int)((char *)matches._M_start[v13] - v14) >> 1;
        _wcsncpy((wchar_t *)v12, (const wchar_t *)v14, v15);
        v16 = (wchar_t *)(v12 + 2 * v15);
        _wcscpy(v16, str->m_charbuffer->m_data);
        v12 = (int)&v16[*(_DWORD *)&str->m_charbuffer[-1].m_data[14] - 1];
        ++v13;
        v14 = v14 + 2 * (v15 + *(_DWORD *)&search->m_charbuffer[-1].m_data[14]) - 2;
      }
      while ( v13 < (unsigned int)p );
      v10 = old_buffer;
    }
    _wcscpy((wchar_t *)v12, (const wchar_t *)v14);
    if ( !InterlockedDecrement((volatile LONG *)&v10->m_cRef) && v10 )
      v10->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v10, 1u);
    if ( (_DWORD)matches._M_start )
      _STL::__node_alloc<1,0>::deallocate(matches._M_start, 4 * (matches._M_end_of_storage._M_data - matches._M_start));
    result = p;
  }
  else
  {
    if ( (_DWORD)matches._M_start )
      _STL::__node_alloc<1,0>::deallocate(matches._M_start, 4 * (matches._M_end_of_storage._M_data - matches._M_start));
    result = 0;
  }
  return result;
}

//----- (0040D6B0) --------------------------------------------------------  // acclient.c:73174
char __cdecl template_cleanup_filename<char>(PStringBase<char> *filename, bool backslash)
{
  void *v2; // eax@2
  PSRefBufferCharData<char> *v3; // eax@3
  void *v4; // eax@6
  PSRefBufferCharData<char> *v5; // eax@7
  char result; // al@10

  if ( !(template_cleanup_filename<char>::_2::local_static_guard & 1) )
  {
    template_cleanup_filename<char>::_2::local_static_guard |= 1u;
    v2 = operator new[](0x24u);
    if ( v2 )
    {
      *((_DWORD *)v2 + 1) = 1;
      *(_DWORD *)v2 = AC1Legacy::PSRefBuffer<char>::vftable;
      *((_DWORD *)v2 + 4) = 1;
      *((_DWORD *)v2 + 2) = 1;
      *((_DWORD *)v2 + 3) = -1;
      v3 = (PSRefBufferCharData<char> *)((char *)v2 + 20);
      v3->m_data[0] = 0;
      template_cleanup_filename<char>::_2::back_slash.m_charbuffer = v3;
      *(_DWORD *)&v3[-1].m_data[12] = 2;
      *(_DWORD *)&template_cleanup_filename<char>::_2::back_slash.m_charbuffer[-1].m_data[4] = 16;
    }
    template_cleanup_filename<char>::_2::back_slash.m_charbuffer->m_data[0] = 92;
    template_cleanup_filename<char>::_2::back_slash.m_charbuffer->m_data[1] = 0;
    atexit(template_cleanup_filename<char>::_2::back_slash);
  }
  if ( !(template_cleanup_filename<char>::_2::local_static_guard & 2) )
  {
    template_cleanup_filename<char>::_2::local_static_guard |= 2u;
    v4 = operator new[](0x24u);
    if ( v4 )
    {
      *((_DWORD *)v4 + 1) = 1;
      *(_DWORD *)v4 = AC1Legacy::PSRefBuffer<char>::vftable;
      *((_DWORD *)v4 + 4) = 1;
      *((_DWORD *)v4 + 2) = 1;
      *((_DWORD *)v4 + 3) = -1;
      v5 = (PSRefBufferCharData<char> *)((char *)v4 + 20);
      v5->m_data[0] = 0;
      template_cleanup_filename<char>::_2::forward_slash.m_charbuffer = v5;
      *(_DWORD *)&v5[-1].m_data[12] = 2;
      *(_DWORD *)&template_cleanup_filename<char>::_2::forward_slash.m_charbuffer[-1].m_data[4] = 16;
    }
    template_cleanup_filename<char>::_2::forward_slash.m_charbuffer->m_data[0] = 47;
    template_cleanup_filename<char>::_2::forward_slash.m_charbuffer->m_data[1] = 0;
    atexit(template_cleanup_filename<char>::_2::forward_slash);
  }
  if ( backslash )
  {
    PStringBase<char>::replace(
      filename,
      &template_cleanup_filename<char>::_2::forward_slash,
      &template_cleanup_filename<char>::_2::back_slash);
    result = 1;
  }
  else
  {
    PStringBase<char>::replace(
      filename,
      &template_cleanup_filename<char>::_2::back_slash,
      &template_cleanup_filename<char>::_2::forward_slash);
    result = 1;
  }
  return result;
}
// 7CA074: using guessed type int (__thiscall *AC1Legacy::PSRefBuffer<char>::vftable[2])(void *, char);
// 8367EC: using guessed type int template_cleanup_filename<char>::_2::local_static_guard;

//----- (0040D7D0) --------------------------------------------------------  // acclient.c:73246
char __cdecl PSUtils::get_cwd(PStringBase<char> *dir)
{
  char *v1; // esi@2
  char *v2; // esi@5
  char result; // al@8
  PStringBase<char> str; // [sp+4h] [bp-408h]@2
  PStringBase<char> search; // [sp+8h] [bp-404h]@2
  char buff[1024]; // [sp+Ch] [bp-400h]@1

  if ( GetCurrentDirectoryA(0x400u, buff) )
  {
    PStringBase<char>::set(dir, buff);
    PStringBase<char>::PStringBase<char>(&str, "/");
    PStringBase<char>::PStringBase<char>(&search, "\\");
    PStringBase<char>::replace(dir, &search, &str);
    v1 = &search.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&search.m_charbuffer[-1]) && v1 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
    v2 = &str.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1]) )
    {
      if ( v2 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0040D8A0) --------------------------------------------------------  // acclient.c:73280
bool __usercall PSUtils::GetLongPathNameA@<al>(unsigned int a1@<esi>, PStringBase<char> *_strIn, PStringBase<char> *_strOut)
{
  PSRefBufferCharData<char> *v3; // edi@3
  ListNode<PStringBase<char> > *v4; // esi@5
  ListNode<PStringBase<char> > *v5; // ebp@6
  PStringBase<char> *v6; // eax@7
  char *v7; // esi@7
  char *v8; // esi@10
  PSRefBufferCharData<char> *v9; // edi@13
  HANDLE v10; // esi@13
  char *v11; // esi@21
  bool v12; // al@27
  bool bRetval; // [sp+15h] [bp-371h]@1
  PStringBase<char> final; // [sp+16h] [bp-370h]@3
  PStringBase<char> clean_name; // [sp+1Ah] [bp-36Ch]@3
  PStringBase<char> rhs; // [sp+1Eh] [bp-368h]@7
  PStringBase<char> tmp; // [sp+22h] [bp-364h]@7
  List<PStringBase<char> > list; // [sp+26h] [bp-360h]@4
  PStringBase<char> v19; // [sp+36h] [bp-350h]@7
  char *name; // [sp+3Ah] [bp-34Ch]@1
  char fullname[260]; // [sp+3Eh] [bp-348h]@1
  char result[260]; // [sp+142h] [bp-244h]@2
  _WIN32_FIND_DATAA FileData; // [sp+246h] [bp-140h]@13

  bRetval = 0;
  if ( GetFullPathNameA(_strIn->m_charbuffer->m_data, 0x104u, fullname, &name)
    && GetLongPathNameA(fullname, result, 0x104u) )
  {
    v3 = PStringBase<char>::s_NullBuffer.m_charbuffer;
    final.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::PStringBase<char>(&clean_name, result);
    if ( template_cleanup_filename<char>(&clean_name, 0) )
    {
      list.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
      list._head = 0;
      list._tail = 0;
      list._num_elements = 0;
      if ( template_explode<char>(a1, &clean_name, 47, &list) )
      {
        v4 = list._head;
        PStringBase<unsigned short>::operator=(
          (PStringBase<unsigned short> *)&final,
          (const unsigned __int16 *)list._head);
        if ( v4 && (v5 = v4->next) != 0 )
        {
          while ( 1 )
          {
            PStringBase<char>::PStringBase<char>(&rhs, "/");
            v6 = PStringBase<char>::operator+(&final, &v19, &rhs);
            PStringBase<char>::operator+(v6, &tmp, &v5->data);
            v7 = &v19.m_charbuffer[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&v19.m_charbuffer[-1]) && v7 )
              (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
            v8 = &rhs.m_charbuffer[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v8 )
              (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
            v9 = tmp.m_charbuffer;
            v10 = FindFirstFileA(tmp.m_charbuffer->m_data, &FileData);
            if ( v10 == (HANDLE)-1 )
              break;
            PStringBase<char>::sprintf_append(&final, "/%s", FileData.cFileName);
            FindClose(v10);
            if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) && v9 != (PSRefBufferCharData<char> *)20 )
              (**(void (__thiscall ***)(char *, signed int))&v9[-2].m_data[12])(&v9[-2].m_data[12], 1);
            if ( v5 )
            {
              v5 = v5->next;
              if ( v5 )
                continue;
            }
            goto LABEL_19;
          }
          if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) && v9 != (PSRefBufferCharData<char> *)20 )
            (**(void (__thiscall ***)(char *, signed int))&v9[-2].m_data[12])(&v9[-2].m_data[12], 1);
        }
        else
        {
LABEL_19:
          PStringBase<char>::set(_strOut, &final);
          bRetval = 1;
        }
      }
      list.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
      List<PStringBase<char>>::flush(&list);
      v3 = final.m_charbuffer;
    }
    v11 = &clean_name.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&clean_name.m_charbuffer[-1]) && v11 )
      (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v3 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&v3[-2].m_data[12])(&v3[-2].m_data[12], 1);
    v12 = bRetval;
  }
  else
  {
    v12 = 0;
  }
  return v12;
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);

//----- (0040DB00) --------------------------------------------------------  // acclient.c:73383
char __cdecl PSUtils::unwrap_string(PStringBase<char> *s)
{
  PSRefBufferCharData<char> *v1; // ecx@0
  char *v2; // esi@1
  PStringBase<char> search; // [sp+0h] [bp-4h]@1

  search.m_charbuffer = v1;
  PStringBase<char>::PStringBase<char>(&search, "\n");
  PStringBase<char>::replace(s, &search, &PStringBase<char>::s_NullBuffer);
  v2 = &search.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&search.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  return 1;
}

//----- (0040DB50) --------------------------------------------------------  // acclient.c:73399
char __cdecl PSUtils::template_cleanup_directory_name<char>(PStringBase<char> *filename, bool backslash)
{
  bool v2; // bl@1
  PSRefBufferCharData<char> *v3; // eax@1
  unsigned int v4; // ecx@1
  char v5; // bl@1
  int v6; // eax@3

  v2 = backslash;
  template_cleanup_filename<char>(filename, backslash);
  v3 = filename->m_charbuffer;
  v4 = *(_DWORD *)&filename->m_charbuffer[-1].m_data[12];
  v5 = v2 != 0 ? 92 : 47;
  if ( v4 >= 2 )
  {
    if ( v4 - 2 < v4 )
      v6 = (int)((char *)v3 + v4 - 2);
    else
      v6 = (int)((char *)v3 + v4 - 1);
    if ( *(_BYTE *)v6 != v5 )
    {
      backslash = v5;
      PStringBase<char>::append_n_chars(filename, (const char *)&backslash, 1u);
    }
  }
  return 1;
}

//----- (0040DBC0) --------------------------------------------------------  // acclient.c:73428
char __usercall PSUtils::template_create_directory<char>@<al>(unsigned int a1@<esi>, PStringBase<char> *directory)
{
  unsigned int v2; // ecx@1
  PSRefBufferCharData<char> *v3; // eax@3
  List<PStringBase<char> >Vtbl *v4; // ebx@7
  char *v5; // esi@8
  char result; // al@11
  PSRefBufferCharData<char> *v7; // esi@12
  ListNode<PStringBase<char> > *v8; // edi@12
  int v9; // ecx@13
  int v10; // esi@19
  char *v11; // esi@22
  int v12; // esi@26
  char *v13; // esi@29
  PStringBase<char> clean_directory; // [sp+10h] [bp-18h]@1
  PStringBase<char> path; // [sp+14h] [bp-14h]@12
  List<PStringBase<char> > dir_list; // [sp+18h] [bp-10h]@7

  clean_directory.m_charbuffer = directory->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&clean_directory.m_charbuffer[-1]);
  template_cleanup_filename<char>(&clean_directory, 0);
  v2 = *(_DWORD *)&clean_directory.m_charbuffer[-1].m_data[12];
  if ( v2 >= 2 )
  {
    a1 = v2 - 2;
    v3 = v2 - 2 < v2 ? (PSRefBufferCharData<char> *)((char *)clean_directory.m_charbuffer + a1) : (PSRefBufferCharData<char> *)((char *)clean_directory.m_charbuffer + v2 - 1);
    if ( v3->m_data[0] != 47 )
    {
      LOBYTE(directory) = 47;
      PStringBase<char>::append_n_chars(&clean_directory, (const char *)&directory, 1u);
    }
  }
  v4 = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
  dir_list.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
  dir_list._head = 0;
  dir_list._tail = 0;
  dir_list._num_elements = 0;
  if ( template_explode<char>(a1, &clean_directory, 47, &dir_list) )
  {
    v7 = PStringBase<char>::s_NullBuffer.m_charbuffer;
    v8 = dir_list._head;
    path.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    if ( v8 )
    {
      while ( 1 )
      {
        v9 = *(_DWORD *)&v8->data.m_charbuffer[-1].m_data[12];
        if ( v9 != 1 )
          PStringBase<char>::append_n_chars(&path, v8->data.m_charbuffer->m_data, v9 - 1);
        LOBYTE(directory) = 47;
        PStringBase<char>::append_n_chars(&path, (const char *)&directory, 1u);
        v7 = path.m_charbuffer;
        if ( __access(path.m_charbuffer->m_data, 0) )
        {
          if ( !CreateDirectoryA(v7->m_data, 0) )
            break;
        }
        v8 = v8->next;
        if ( !v8 )
        {
          v4 = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
          goto LABEL_19;
        }
      }
      v12 = (int)&v7[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)(v12 + 4)) && v12 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
      dir_list.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
      List<PStringBase<char>>::flush(&dir_list);
      v13 = &clean_directory.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&clean_directory.m_charbuffer[-1]) && v13 )
        (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
      result = 0;
    }
    else
    {
LABEL_19:
      v10 = (int)&v7[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)(v10 + 4)) && v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      dir_list.vfptr = v4;
      List<PStringBase<char>>::flush(&dir_list);
      v11 = &clean_directory.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&clean_directory.m_charbuffer[-1]) && v11 )
        (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
      result = 1;
    }
  }
  else
  {
    dir_list.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
    List<PStringBase<char>>::flush(&dir_list);
    v5 = &clean_directory.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&clean_directory.m_charbuffer[-1]) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
    }
    result = 0;
  }
  return result;
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);

//----- (006C39F0) --------------------------------------------------------  // acclient.c:732035
int _E77()
{
  PStringBase<char>::PStringBase<char>(&ignore1, ".");
  return atexit(_E78_1);
}

//----- (006C3A10) --------------------------------------------------------  // acclient.c:732042
int _E80()
{
  PStringBase<char>::PStringBase<char>(&ignore2, "..");
  return atexit(_E81_1);
}

//----- (00725C60) --------------------------------------------------------  // acclient.c:823585
void __cdecl _E84_1()
{
  Archive::~Archive((Archive *)&archive.vfptr);
}

//----- (00725C70) --------------------------------------------------------  // acclient.c:823591
void __cdecl template_cleanup_filename<char>::_2::forward_slash()
{
  char *v0; // esi@1

  v0 = &template_cleanup_filename<char>::_2::forward_slash.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&template_cleanup_filename<char>::_2::forward_slash.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725CA0) --------------------------------------------------------  // acclient.c:823604
void __cdecl template_cleanup_filename<char>::_2::back_slash()
{
  char *v0; // esi@1

  v0 = &template_cleanup_filename<char>::_2::back_slash.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&template_cleanup_filename<char>::_2::back_slash.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725CD0) --------------------------------------------------------  // acclient.c:823617
void __cdecl _E74_6()
{
  char *v0; // esi@1

  v0 = &DirSeps.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DirSeps.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725D00) --------------------------------------------------------  // acclient.c:823630
void __cdecl func()
{
  char *v0; // esi@1

  v0 = (char *)&DirSeps_0.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&DirSeps_0.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725D30) --------------------------------------------------------  // acclient.c:823643
void __cdecl _E78_1()
{
  char *v0; // esi@1

  v0 = &ignore1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ignore1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00725D60) --------------------------------------------------------  // acclient.c:823656
void __cdecl _E81_1()
{
  char *v0; // esi@1

  v0 = &ignore2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ignore2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

